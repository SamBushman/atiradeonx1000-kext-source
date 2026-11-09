#include "decls.h"

/* _gleBeginRSLNoop @ 0xf34d4 (44 bytes) */
int _gleBeginRSLNoop(param_1)
  int param_1;
{
  undefined *puVar1;
  
  puVar1 = PTR__gleFlushNoop_001113e4;
  *(undefined **)(param_1 + 0x4a08) = PTR__gleRenderNoop_001113e0;
  *(undefined **)(param_1 + 0x4a0c) = puVar1;
  return;
}

/* _gleFlushPrimitiveTCLRDirtyFunc @ 0xf3500 (856 bytes) */
void _gleFlushPrimitiveTCLRDirtyFunc(int param_1,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  undefined8 local_220 [64];
  int local_20 [5];
  
  if ((((*(char *)(param_1 + 0x7580) != '\0') && ((*(uint *)(param_1 + 0x486c) & 1) != 0)) &&
      (*(char *)(*(int *)(param_1 + 0x468c) + 0x7a) == '\0')) &&
     ((*(char *)(param_1 + 0x4664) == '\0' && (*(int *)(param_1 + 0x5434) == 0)))) {
    ((undefined4 (*)())_gleForceToSoftwareTCL)(param_1,fparam_1,fparam_2,fparam_3,fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
    (**(code **)(param_1 + 0x4a0c))(param_1);
    return;
  }
  iVar5 = (int)*(short *)(param_1 + 0x487c);
  switch(*(undefined2 *)(param_1 + 0x4a10)) {
  case 2:
    if (*(char *)(param_1 + 0x4a18) == '\0') {
      iVar4 = 0;
      iVar2 = *(int *)(param_1 + 0x4854);
      iVar1 = *(int *)(param_1 + 0x4868);
      if (0 < iVar5) {
        uVar6 = iVar5 + 7U >> 3;
        do {
          *(undefined8 *)(iVar2 + -0x100 + iVar4) = *(undefined8 *)(iVar1 + iVar4);
          iVar4 = iVar4 + 8;
          uVar6 = uVar6 - 1;
        } while (uVar6 != 0);
      }
    }
  case 3:
    iVar2 = 0;
    iVar1 = *(int *)(param_1 + 0x4858);
    *(undefined1 *)(param_1 + 0x4a18) = 1;
    if (0 < iVar5) {
      uVar6 = iVar5 + 7U >> 3;
      do {
        *(undefined8 *)((int)local_220 + iVar2) = *(undefined8 *)((iVar1 - iVar5) + iVar2);
        iVar2 = iVar2 + 8;
        uVar6 = uVar6 - 1;
      } while (uVar6 != 0);
    }
    break;
  case 5:
  case 8:
    iVar2 = iVar5 * 2;
    iVar4 = 0;
    iVar3 = *(int *)(param_1 + 0x4858);
    iVar1 = iVar5 * -2;
    iVar5 = iVar2;
    if (0 < iVar2) {
      uVar6 = iVar2 + 7U >> 3;
      do {
        *(undefined8 *)((int)local_220 + iVar4) = *(undefined8 *)(iVar3 + iVar1 + iVar4);
        iVar4 = iVar4 + 8;
        uVar6 = uVar6 - 1;
      } while (uVar6 != 0);
    }
    break;
  case 6:
    iVar2 = 0;
    iVar4 = *(int *)(param_1 + 0x4858);
    iVar1 = *(int *)(param_1 + 0x4868);
    if (0 < iVar5) {
      do {
        *(undefined8 *)((int)local_220 + iVar2) = *(undefined8 *)(iVar1 + iVar2);
        iVar2 = iVar2 + 8;
      } while (iVar2 < iVar5);
    }
    iVar2 = 0;
    if (0 < iVar5) {
      uVar6 = iVar5 + 7U >> 3;
      do {
        *(undefined8 *)((int)local_220 + iVar2 + iVar5) = *(undefined8 *)((iVar4 - iVar5) + iVar2);
        iVar2 = iVar2 + 8;
        uVar6 = uVar6 - 1;
      } while (uVar6 != 0);
    }
    break;
  case 9:
    iVar2 = 0;
    iVar4 = *(int *)(param_1 + 0x4858);
    iVar1 = *(int *)(param_1 + 0x4868);
    if (0 < iVar5) {
      do {
        *(undefined8 *)((int)local_220 + iVar2) = *(undefined8 *)(iVar1 + iVar2);
        iVar2 = iVar2 + 8;
      } while (iVar2 < iVar5);
    }
    iVar2 = 0;
    iVar4 = iVar4 - iVar5;
    if (0 < iVar5) {
      uVar6 = iVar5 + 7U >> 3;
      do {
        *(undefined8 *)((int)local_220 + iVar2 + iVar5) = *(undefined8 *)(iVar4 + iVar2);
        iVar2 = iVar2 + 8;
        uVar6 = uVar6 - 1;
      } while (uVar6 != 0);
    }
    if ((*(short *)(param_1 + 0x34d2) == 0x1b01) || (*(short *)(param_1 + 0x34d0) == 0x1b01)) {
      *(undefined1 *)(iVar4 + *(short *)(param_1 + 0x487e)) = 0;
    }
  }
  (**(code **)(param_1 + 0x4a08))(param_1);
  local_20[0] = *(int *)(param_1 + 0x4a14);
  iVar2 = (**(code **)(param_1 + 0x46e8))
                    (*(undefined4 *)(param_1 + 0x4688),(int)*(short *)(param_1 + 0x4a10),local_20);
  *(int *)(param_1 + 0x4868) = iVar2;
  *(int *)(param_1 + 0x485c) = iVar2 + *(short *)(param_1 + 0x487c) * local_20[0];
  switch(*(undefined2 *)(param_1 + 0x4a10)) {
  default:
    goto switchD_000f37d0_caseD_0;
  case 2:
  case 3:
    iVar1 = 0;
    if (0 < iVar5) {
      uVar6 = iVar5 + 7U >> 3;
      do {
        *(undefined8 *)(iVar2 + iVar1) = *(undefined8 *)((int)local_220 + iVar1);
        iVar1 = iVar1 + 8;
        uVar6 = uVar6 - 1;
      } while (uVar6 != 0);
    }
    break;
  case 9:
    if ((*(short *)(param_1 + 0x34d2) == 0x1b01) || (*(short *)(param_1 + 0x34d0) == 0x1b01)) {
      *(undefined1 *)((int)local_220 + (int)*(short *)(param_1 + 0x487e)) = 0;
    }
  case 6:
    iVar5 = iVar5 << 1;
  case 5:
  case 8:
    iVar1 = 0;
    if (0 < iVar5) {
      uVar6 = iVar5 + 7U >> 3;
      do {
        *(undefined8 *)(iVar2 + iVar1) = *(undefined8 *)((int)local_220 + iVar1);
        iVar1 = iVar1 + 8;
        uVar6 = uVar6 - 1;
      } while (uVar6 != 0);
    }
  }
  iVar2 = iVar2 + iVar5;
switchD_000f37d0_caseD_0:
  *(int *)(param_1 + 0x4858) = iVar2;
  *(undefined4 *)(param_1 + 0x486c) = 0;
  return;
}

/* _gleBeginPrimitiveTCLRDirtyFunc @ 0xf38a8 (176 bytes) */
int _gleBeginPrimitiveTCLRDirtyFunc(param_1)
  int param_1;
{
  short sVar1;
  undefined *puVar2;
  int iVar3;
  int local_20 [5];
  
  local_20[0] = *(int *)(param_1 + 0x4a14);
  *(undefined1 *)(param_1 + 0x4a18) = 0;
  if (local_20[0] == 0) {
    sVar1 = *(short *)(param_1 + 0x4880);
  }
  else {
    sVar1 = *(short *)(param_1 + 0x4882);
  }
  iVar3 = (**(code **)(param_1 + 0x46e8))
                    (*(undefined4 *)(param_1 + 0x4688),(int)*(short *)(param_1 + 0x4a10),local_20);
  *(undefined4 *)(param_1 + 0x486c) = 0;
  puVar2 = PTR__gleRenderPrimitiveTCLFunc_001113cc;
  *(undefined **)(param_1 + 0x4a0c) = PTR__gleFlushPrimitiveTCLRDirtyFunc_001113c8;
  *(int *)(param_1 + 0x485c) = iVar3 + sVar1 * local_20[0];
  *(undefined **)(param_1 + 0x4a08) = puVar2;
  *(undefined2 *)(param_1 + 0x4a12) = *(undefined2 *)(param_1 + 0x4a10);
  *(short *)(param_1 + 0x487c) = sVar1;
  *(int *)(param_1 + 0x4868) = iVar3;
  *(int *)(param_1 + 0x4858) = iVar3;
  return;
}

/* _gleUpdateScissorData @ 0xf3958 (44 bytes) */
int _gleUpdateScissorData(param_1)
  int param_1;
{
  if (*(int *)(param_1 + 0x3188) < 0) {
    *(undefined4 *)(param_1 + 0x3188) = 0;
  }
  if (-1 < *(int *)(param_1 + 0x318c)) {
    return;
  }
  *(undefined4 *)(param_1 + 0x318c) = 0;
  return;
}

/* _gleSelectHit @ 0xf3984 (8 bytes) */
int _gleSelectHit(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  ((void (*)())_gleSelectHitRecord)(param_1,(double)*(float *)(param_2 + 8));
  return;
}

/* _gleSelectHitRecord @ 0xf398c (340 bytes) */
void _gleSelectHitRecord(int param_1,double fparam_1)
{
  uint uVar1;
  uint *puVar2;
  uint *puVar3;
  uint *puVar4;
  double dVar5;
  
  if (*(char *)(param_1 + 0x4fc9) != '\0') {
    return;
  }
  dVar5 = fparam_1 * DOUBLE_00108da8;
  puVar2 = *(uint **)(param_1 + 0x4e24);
  puVar3 = (uint *)(*(int *)(param_1 + 20000) + *(int *)(param_1 + 0x4e28) * 4);
  if (DOUBLE_00108d80 <= dVar5) {
    uVar1 = (int)(dVar5 - DOUBLE_00108d80) ^ 0x80000000;
  }
  else {
    uVar1 = (uint)(int)dVar5;
  }
  if (*(char *)(param_1 + 0x4fc8) != '\0') {
    puVar2 = *(uint **)(param_1 + 0x4fc0);
    if (uVar1 < *puVar2) {
      *puVar2 = uVar1;
      puVar2 = *(uint **)(param_1 + 0x4fc0);
    }
    if (uVar1 <= puVar2[1]) {
      return;
    }
    puVar2[1] = uVar1;
    return;
  }
  *(undefined1 *)(param_1 + 0x4fc8) = 1;
  if (puVar2 != puVar3) {
    *puVar2 = (*(int *)(param_1 + 0x4fbc) - param_1) + -0x4e2c >> 2;
    puVar4 = puVar2 + 1;
    *(int *)(param_1 + 0x4fc4) = *(int *)(param_1 + 0x4fc4) + 1;
    if (puVar4 != puVar3) {
      *(uint **)(param_1 + 0x4fc0) = puVar4;
      *puVar4 = uVar1;
      if (puVar2 + 2 != puVar3) {
        puVar2[2] = uVar1;
        puVar4 = (uint *)(param_1 + 0x4e2c);
        puVar2 = puVar2 + 3;
        if (puVar4 < *(uint **)(param_1 + 0x4fbc)) {
          do {
            if (puVar2 == puVar3) goto LAB_000f3a4c;
            uVar1 = *puVar4;
            puVar4 = puVar4 + 1;
            *puVar2 = uVar1;
            puVar2 = puVar2 + 1;
          } while (puVar4 < *(uint **)(param_1 + 0x4fbc));
        }
        *(uint **)(param_1 + 0x4e24) = puVar2;
        return;
      }
    }
  }
LAB_000f3a4c:
  *(uint **)(param_1 + 0x4e24) = puVar3;
  *(undefined1 *)(param_1 + 0x4fc9) = 1;
  return;
}

/* _gleSelectPoints @ 0xf3ae0 (84 bytes) */
int _gleSelectPoints(param_1, param_2, param_3)
  undefined4 param_1;
  uint param_2;
  int param_3;
{
  uint uVar1;
  
  uVar1 = param_2 + param_3 * 0x100;
  for (; param_2 < uVar1; param_2 = param_2 + 0x100) {
    ((void (*)())_gleSelectHitRecord)(param_1,(double)*(float *)(param_2 + 8));
  }
  return;
}

/* _gleSelectPointsPtr @ 0xf3b34 (88 bytes) */
int _gleSelectPointsPtr(param_1, param_2, param_3)
  undefined4 param_1;
  int *param_2;
  int param_3;
{
  int *piVar1;
  
  piVar1 = param_2 + param_3;
  for (; param_2 < piVar1; param_2 = param_2 + 1) {
    ((void (*)())_gleSelectHitRecord)(param_1,(double)*(float *)(*param_2 + 8));
  }
  return;
}

/* _gleSelectLines @ 0xf3b8c (100 bytes) */
int _gleSelectLines(param_1, param_2, param_3)
  undefined4 param_1;
  uint param_2;
  int param_3;
{
  int iVar1;
  
  iVar1 = param_2 + param_3 * 0x100;
  for (; param_2 < iVar1 - 0x100U; param_2 = param_2 + 0x200) {
    ((void (*)())_gleSelectHitRecord)(param_1,(double)*(float *)(param_2 + 8));
    ((void (*)())_gleSelectHitRecord)(param_1,(double)*(float *)(param_2 + 0x108));
  }
  return;
}

/* _gleSelectLineStrip @ 0xf3bf0 (100 bytes) */
int _gleSelectLineStrip(param_1, param_2, param_3)
  undefined4 param_1;
  uint param_2;
  int param_3;
{
  int iVar1;
  
  iVar1 = param_2 + param_3 * 0x100;
  for (; param_2 < iVar1 - 0x100U; param_2 = param_2 + 0x100) {
    ((void (*)())_gleSelectHitRecord)(param_1,(double)*(float *)(param_2 + 8));
    ((void (*)())_gleSelectHitRecord)(param_1,(double)*(float *)(param_2 + 0x108));
  }
  return;
}

/* FUN_000f3c60 @ 0xf3c60 (112 bytes) */
int FUN_000f3c60(param_1, param_2, param_3)
  undefined4 param_1;
  uint param_2;
  int param_3;
{
  uint uVar1;
  
  for (uVar1 = param_2; uVar1 < param_3 - 0x100U; uVar1 = uVar1 + 0x100) {
    ((void (*)())_gleSelectHitRecord)(param_1,(double)*(float *)(uVar1 + 8));
    ((void (*)())_gleSelectHitRecord)(param_1,(double)*(float *)(uVar1 + 0x108));
  }
  ((void (*)())_gleSelectHitRecord)(param_1,(double)*(float *)(uVar1 + 8));
  ((void (*)())_gleSelectHitRecord)(param_1,(double)*(float *)(param_2 + 8));
  return;
}

/* _gleSelectLinesPtr @ 0xf3cd0 (108 bytes) */
int _gleSelectLinesPtr(param_1, param_2, param_3)
  undefined4 param_1;
  int *param_2;
  int param_3;
{
  int *piVar1;
  
  piVar1 = param_2 + param_3 + -1;
  for (; param_2 < piVar1; param_2 = param_2 + 2) {
    ((void (*)())_gleSelectHitRecord)(param_1,(double)*(float *)(*param_2 + 8));
    ((void (*)())_gleSelectHitRecord)(param_1,(double)*(float *)(param_2[1] + 8));
  }
  return;
}

/* _gleSelectPolygon @ 0xf3d3c (84 bytes) */
int _gleSelectPolygon(param_1, param_2, param_3)
  undefined4 param_1;
  uint param_2;
  int param_3;
{
  uint uVar1;
  
  uVar1 = param_2 + param_3 * 0x100;
  for (; param_2 < uVar1; param_2 = param_2 + 0x100) {
    ((void (*)())_gleSelectHitRecord)(param_1,(double)*(float *)(param_2 + 8));
  }
  return;
}

/* _gleSelectPolygonPtr @ 0xf3d90 (88 bytes) */
int _gleSelectPolygonPtr(param_1, param_2, param_3)
  undefined4 param_1;
  int *param_2;
  int param_3;
{
  int *piVar1;
  
  piVar1 = param_2 + param_3;
  for (; param_2 < piVar1; param_2 = param_2 + 1) {
    ((void (*)())_gleSelectHitRecord)(param_1,(double)*(float *)(*param_2 + 8));
  }
  return;
}

/* _gleSelectTriangles @ 0xf3de8 (116 bytes) */
int _gleSelectTriangles(param_1, param_2, param_3)
  undefined4 param_1;
  uint param_2;
  int param_3;
{
  int iVar1;
  uint uVar2;
  
  iVar1 = 0;
  if (-1 < param_3 + -3) {
    do {
      for (uVar2 = param_2; uVar2 < param_2 + 0x300; uVar2 = uVar2 + 0x100) {
        ((void (*)())_gleSelectHitRecord)(param_1,(double)*(float *)(uVar2 + 8));
      }
      iVar1 = iVar1 + 3;
      param_2 = param_2 + 0x300;
    } while (iVar1 <= param_3 + -3);
  }
  return;
}

/* _gleSelectTriangleFan @ 0xf3e5c (124 bytes) */
int _gleSelectTriangleFan(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  int param_2;
  uint param_3;
  int param_4;
{
  int iVar1;
  uint uVar2;
  
  if (-1 < param_4 + -2) {
    iVar1 = param_4 + -1;
    do {
      ((void (*)())_gleSelectHitRecord)(param_1,(double)*(float *)(param_2 + 8));
      for (uVar2 = param_3; uVar2 < param_3 + 0x200; uVar2 = uVar2 + 0x100) {
        ((void (*)())_gleSelectHitRecord)(param_1,(double)*(float *)(uVar2 + 8));
      }
      iVar1 = iVar1 + -1;
      param_3 = param_3 + 0x100;
    } while (iVar1 != 0);
  }
  return;
}

/* _gleSelectTriangleStrip @ 0xf3ed8 (108 bytes) */
int _gleSelectTriangleStrip(param_1, param_2, param_3)
  undefined4 param_1;
  uint param_2;
  int param_3;
{
  int iVar1;
  uint uVar2;
  
  if (-1 < param_3 + -3) {
    iVar1 = param_3 + -2;
    do {
      for (uVar2 = param_2; uVar2 < param_2 + 0x300; uVar2 = uVar2 + 0x100) {
        ((void (*)())_gleSelectHitRecord)(param_1,(double)*(float *)(uVar2 + 8));
      }
      iVar1 = iVar1 + -1;
      param_2 = param_2 + 0x100;
    } while (iVar1 != 0);
  }
  return;
}

/* _gleSelectQuads @ 0xf3f44 (116 bytes) */
int _gleSelectQuads(param_1, param_2, param_3)
  undefined4 param_1;
  uint param_2;
  int param_3;
{
  int iVar1;
  uint uVar2;
  
  iVar1 = 0;
  if (-1 < param_3 + -4) {
    do {
      for (uVar2 = param_2; uVar2 < param_2 + 0x400; uVar2 = uVar2 + 0x100) {
        ((void (*)())_gleSelectHitRecord)(param_1,(double)*(float *)(uVar2 + 8));
      }
      iVar1 = iVar1 + 4;
      param_2 = param_2 + 0x400;
    } while (iVar1 <= param_3 + -4);
  }
  return;
}

/* _gleSelectQuadStrip @ 0xf3fb8 (116 bytes) */
int _gleSelectQuadStrip(param_1, param_2, param_3)
  undefined4 param_1;
  uint param_2;
  int param_3;
{
  int iVar1;
  uint uVar2;
  
  iVar1 = 0;
  if (-1 < param_3 + -4) {
    do {
      for (uVar2 = param_2; uVar2 < param_2 + 0x400; uVar2 = uVar2 + 0x100) {
        ((void (*)())_gleSelectHitRecord)(param_1,(double)*(float *)(uVar2 + 8));
      }
      iVar1 = iVar1 + 2;
      param_2 = param_2 + 0x200;
    } while (iVar1 <= param_3 + -4);
  }
  return;
}

/* _gleDetachShaderObjectIterFunc @ 0xf402c (180 bytes) */
int _gleDetachShaderObjectIterFunc(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  
  if (*(int *)(param_2 + 0x10) == 0x8b40) {
    iVar1 = *(int *)(param_2 + 0x48);
    iVar4 = 0;
    if (iVar1 < 1) {
      piVar2 = *(int **)(param_2 + 0x44);
    }
    else {
      piVar2 = *(int **)(param_2 + 0x44);
      piVar5 = piVar2;
      do {
        iVar3 = *piVar5;
        if (iVar3 != 0) {
          *(int *)(iVar3 + 8) = *(int *)(iVar3 + 8) + -1;
        }
        iVar4 = iVar4 + 1;
        piVar5 = piVar5 + 1;
      } while (iVar4 < iVar1);
    }
    if (piVar2 != (int *)0x0) {
      _free(piVar2);
    }
    *(undefined4 *)(param_2 + 0x48) = 0;
    *(undefined4 *)(param_2 + 0x44) = 0;
  }
  if (*(char *)(param_2 + 0x14) == '\0') {
    *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + -1;
  }
  return;
}

/* _gleFreeShaderObject @ 0xf40e0 (868 bytes) */
int _gleFreeShaderObject(param_1, param_2)
  int param_1;
  int param_2;
{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  if (*(int *)(param_2 + 0x10) == 0x8b40) {
    if (*(int *)(param_2 + 0x18) != 0) {
      _free(*(int *)(param_2 + 0x18));
    }
    iVar5 = *(int *)(param_2 + 0x20);
    if (*(int *)(iVar5 + 0x518) != 0) {
      iVar3 = *(int *)(*(int *)(iVar5 + 0x518) + 0x20);
      if (iVar3 != 0) {
        _gleVecFree(iVar3);
        iVar5 = *(int *)(param_2 + 0x20);
      }
      iVar3 = *(int *)(*(int *)(iVar5 + 0x518) + 8);
      if (iVar3 != 0) {
        _gleVecFree(iVar3);
        iVar5 = *(int *)(param_2 + 0x20);
      }
      iVar3 = *(int *)(*(int *)(iVar5 + 0x518) + 0xc);
      if (iVar3 != 0) {
        _gleVecFree(iVar3);
        iVar5 = *(int *)(param_2 + 0x20);
      }
      iVar3 = *(int *)(*(int *)(iVar5 + 0x518) + 0x18);
      if (iVar3 != 0) {
        _gleVecFree(iVar3);
        iVar5 = *(int *)(param_2 + 0x20);
      }
      iVar3 = *(int *)(*(int *)(iVar5 + 0x518) + 0x1c);
      if (iVar3 != 0) {
        _gleVecFree(iVar3);
        iVar5 = *(int *)(param_2 + 0x20);
      }
      _gleVecFree(*(undefined4 *)(iVar5 + 0x518));
    }
    iVar5 = *(int *)(param_2 + 0x24);
    if (*(int *)(iVar5 + 0x518) != 0) {
      iVar3 = *(int *)(*(int *)(iVar5 + 0x518) + 0x20);
      if (iVar3 != 0) {
        _gleVecFree(iVar3);
        iVar5 = *(int *)(param_2 + 0x24);
      }
      iVar3 = *(int *)(*(int *)(iVar5 + 0x518) + 8);
      if (iVar3 != 0) {
        _gleVecFree(iVar3);
        iVar5 = *(int *)(param_2 + 0x24);
      }
      iVar3 = *(int *)(*(int *)(iVar5 + 0x518) + 0xc);
      if (iVar3 != 0) {
        _gleVecFree(iVar3);
        iVar5 = *(int *)(param_2 + 0x24);
      }
      iVar3 = *(int *)(*(int *)(iVar5 + 0x518) + 0x18);
      if (iVar3 != 0) {
        _gleVecFree(iVar3);
        iVar5 = *(int *)(param_2 + 0x24);
      }
      iVar3 = *(int *)(*(int *)(iVar5 + 0x518) + 0x1c);
      if (iVar3 != 0) {
        _gleVecFree(iVar3);
        iVar5 = *(int *)(param_2 + 0x24);
      }
      _gleVecFree(*(undefined4 *)(iVar5 + 0x518));
    }
    iVar5 = *(int *)(param_2 + 0x20);
    if (*(int *)(iVar5 + 0x4dc) != 0) {
      _PPEmulatorProgramFree(*(int *)(iVar5 + 0x4dc));
      iVar5 = *(int *)(param_2 + 0x20);
    }
    if (*(int *)(iVar5 + 0x508) != 0) {
      _gleVecFree(*(int *)(iVar5 + 0x508));
    }
    iVar5 = *(int *)(*(int *)(param_2 + 0x24) + 0x508);
    if (iVar5 != 0) {
      _gleVecFree(iVar5);
    }
    iVar5 = *(int *)(*(int *)(param_2 + 0x20) + 0x51c);
    if (iVar5 != 0) {
      _gleVecFree(iVar5);
    }
    iVar5 = *(int *)(*(int *)(param_2 + 0x24) + 0x51c);
    if (iVar5 != 0) {
      _gleVecFree(iVar5);
    }
    iVar5 = *(int *)(param_2 + 0x48);
    iVar3 = 0;
    if (iVar5 < 1) {
      iVar6 = *(int *)(param_2 + 0x44);
    }
    else {
      iVar6 = *(int *)(param_2 + 0x44);
      do {
        iVar7 = *(int *)(iVar3 * 4 + iVar6);
        if ((iVar7 != 0) &&
           (iVar4 = *(int *)(iVar7 + 8) + -1, *(int *)(iVar7 + 8) = iVar4, iVar4 == 1)) {
          _gleDeleteHashNameAndObject
                    (param_1,*(int *)(param_1 + 0x5148) + 0x6018,*(undefined4 *)(iVar7 + 4));
          iVar5 = *(int *)(param_2 + 0x48);
          iVar6 = *(int *)(param_2 + 0x44);
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < iVar5);
    }
    if (iVar6 != 0) {
      _free(iVar6);
    }
    if (*(int *)(param_2 + 0x40) != 0) {
      _ShDestruct();
    }
    iVar5 = 0;
    if (*(char *)(param_1 + 0x85a4) != '\0') {
      iVar3 = param_1 + 0x85a0;
      do {
        iVar6 = iVar5 * 4;
        iVar5 = iVar5 + 1;
        (**(code **)(*(int *)(iVar3 + 0x2e4) + 0x1a0))
                  (*(undefined4 *)(iVar3 + 0xc),
                   *(undefined4 *)(iVar6 + *(int *)(param_2 + 0x20) + 0x4e4));
        piVar1 = (int *)(iVar3 + 0x2e4);
        puVar2 = (undefined4 *)(iVar3 + 0xc);
        iVar3 = iVar3 + 0x2e0;
        (**(code **)(*piVar1 + 0x1a0))
                  (*puVar2,*(undefined4 *)(iVar6 + *(int *)(param_2 + 0x24) + 0x4e4));
      } while (iVar5 < (int)(uint)*(byte *)(param_1 + 0x85a4));
    }
    if (*(int *)(param_2 + 0x20) != 0) {
      _gleVecFree(*(int *)(param_2 + 0x20));
    }
    if (*(int *)(param_2 + 0x24) != 0) {
      _gleVecFree(*(int *)(param_2 + 0x24));
    }
    if (*(int *)(param_2 + 0x4c) != 0) {
      _gleVecFree(*(int *)(param_2 + 0x4c));
    }
  }
  else if ((*(int *)(param_2 + 0x10) == 0x8b48) && (*(int *)(param_2 + 0x20) - 0x8b30U < 2)) {
    if (*(int *)(param_2 + 0x2c) != 0) {
      _free(*(int *)(param_2 + 0x2c));
    }
    if (*(int *)(param_2 + 0x18) != 0) {
      _free(*(int *)(param_2 + 0x18));
    }
    if (*(int *)(param_2 + 0x30) != 0) {
      _ShDestruct();
    }
  }
  _gleVecFree(param_2);
  return;
}

/* _gleShaderDataUpdateParams @ 0xf4444 (1020 bytes) */
int _gleShaderDataUpdateParams(param_1)
  int param_1;
{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  undefined1 uVar9;
  uint uVar10;
  
  iVar5 = *(int *)(param_1 + 0x508);
  uVar8 = 0;
  iVar3 = *(int *)(iVar5 + 0x28);
  iVar1 = *(int *)(iVar5 + 0x2c);
  if (iVar3 < 1) {
    return;
  }
  do {
    uVar6 = *(uint *)(uVar8 * 8 + iVar5 + iVar1 * 8);
    uVar9 = (undefined1)uVar8;
    switch(uVar6 >> 0x10 & 0x1f) {
    default:
      goto switchD_000f44b0_caseD_0;
    case 1:
      *(undefined1 *)((uVar6 & 0xffff) + param_1 + 0x8c) = uVar9;
      break;
    case 2:
      *(undefined1 *)((uVar6 & 0xffff) + param_1 + 0x18c) = uVar9;
      break;
    case 3:
      uVar10 = uVar6 & 0xff;
      switch(uVar6 >> 8 & 0xf) {
      case 0:
        *(undefined1 *)(uVar10 * 7 + param_1 + 0x28c) = uVar9;
        break;
      case 1:
        *(undefined1 *)(uVar10 * 7 + param_1 + 0x28d) = uVar9;
        break;
      case 2:
        *(undefined1 *)(uVar10 * 7 + param_1 + 0x28e) = uVar9;
        break;
      case 3:
        *(undefined1 *)(uVar10 * 7 + param_1 + 0x28f) = uVar9;
        break;
      case 4:
        *(undefined1 *)(uVar10 * 7 + param_1 + 0x290) = uVar9;
        break;
      case 5:
        *(undefined1 *)(uVar10 * 7 + param_1 + 0x291) = uVar9;
        break;
      case 6:
        *(undefined1 *)(uVar10 * 7 + param_1 + 0x292) = uVar9;
      }
      break;
    case 4:
      uVar2 = uVar6 >> 9 & 3;
      uVar10 = uVar6 & 0xff;
      uVar6 = uVar6 >> 8 & 1;
      if (uVar2 == 1) {
        *(undefined1 *)(uVar10 * 6 + uVar6 * 3 + param_1 + 0x2c5) = uVar9;
      }
      else if (uVar2 < 2) {
        if (uVar2 == 0) {
          *(undefined1 *)(uVar10 * 6 + uVar6 * 3 + param_1 + 0x2c4) = uVar9;
        }
      }
      else if (uVar2 == 2) {
        *(undefined1 *)(uVar10 * 6 + uVar6 * 3 + param_1 + 0x2c6) = uVar9;
      }
      break;
    case 5:
      uVar10 = uVar6 & 1;
      switch(uVar6 >> 1 & 7) {
      case 0:
        *(undefined1 *)(uVar10 * 6 + param_1 + 0x2f4) = uVar9;
        break;
      case 1:
        *(undefined1 *)(uVar10 * 6 + param_1 + 0x2f5) = uVar9;
        break;
      case 2:
        *(undefined1 *)(uVar10 * 6 + param_1 + 0x2f6) = uVar9;
        break;
      case 3:
        *(undefined1 *)(uVar10 * 6 + param_1 + 0x2f7) = uVar9;
        break;
      case 4:
        *(undefined1 *)(uVar10 * 6 + param_1 + 0x2f8) = uVar9;
        break;
      case 5:
        *(undefined1 *)(uVar10 * 6 + param_1 + 0x2f9) = uVar9;
      }
      break;
    case 6:
      *(undefined1 *)(param_1 + 0x358) = uVar9;
      break;
    case 7:
      *(undefined1 *)((uVar6 & 0x1f) * 4 + param_1 + (uVar6 >> 5 & 7) + 0x300) = uVar9;
      break;
    case 8:
      *(undefined1 *)((uVar6 & 0x1f) * 4 + param_1 + (uVar6 >> 5 & 7) + 800) = uVar9;
      break;
    case 10:
      *(undefined1 *)((uVar6 & 0xff) + param_1 + 0x350) = uVar9;
      break;
    case 0xb:
      *(undefined1 *)(param_1 + 0x356) = uVar9;
      break;
    case 0xc:
      *(undefined1 *)(param_1 + 0x357) = uVar9;
      break;
    case 0xd:
      *(undefined1 *)(param_1 + 0x359) = uVar9;
      break;
    case 0xe:
      *(undefined1 *)(param_1 + 0x35a) = uVar9;
      break;
    case 0x10:
      uVar10 = uVar6 & 0xff;
      switch(uVar6 >> 8 & 7) {
      case 0:
        uVar10 = 0;
        goto LAB_000f4800;
      case 1:
        uVar10 = 3;
        goto LAB_000f4800;
      case 2:
        uVar10 = 2;
        goto LAB_000f4800;
      case 3:
        uVar10 = uVar10 + 4;
        break;
      case 4:
        uVar10 = uVar10 + 0x10;
        break;
      case 5:
        uVar10 = uVar10 + 8;
        break;
      default:
        uVar10 = 0xffffffff;
      }
      if (uVar10 != 0xffffffff) {
LAB_000f4800:
        uVar2 = uVar6 >> 0xe & 3;
        uVar4 = uVar6 >> 0xc & 3;
        if (uVar2 == 1) {
          *(undefined1 *)(uVar10 * 4 + param_1 + uVar4 + 0x41c) = uVar9;
        }
        else if (uVar2 < 2) {
          if (uVar2 == 0) {
            *(undefined1 *)(uVar10 * 4 + param_1 + uVar4 + 0x35c) = uVar9;
          }
        }
        else {
          if (uVar2 == 2) {
            uVar6 = *(uint *)(param_1 + 4) | 1 << (uVar10 & 0x3f);
            *(undefined1 *)(uVar10 * 4 + param_1 + uVar4 + 0x3bc) = uVar9;
          }
          else {
            if (uVar2 != 3) break;
            uVar6 = *(uint *)(param_1 + 4) | 1 << (uVar10 & 0x3f);
            *(undefined1 *)(uVar10 * 4 + param_1 + uVar4 + 0x47c) = uVar9;
          }
LAB_000f48a0:
          *(uint *)(param_1 + 4) = uVar6;
        }
      }
      break;
    case 0x12:
      uVar6 = *(uint *)(param_1 + 4) | 0x10;
      goto LAB_000f48a0;
    }
    iVar7 = ((int)uVar8 >> 5) * 4 + param_1;
    *(uint *)(iVar7 + 8) = *(uint *)(iVar7 + 8) | 1 << (uVar8 & 0x1f);
switchD_000f44b0_caseD_0:
    uVar8 = uVar8 + 1;
    if (iVar3 <= (int)uVar8) {
      return;
    }
  } while( true );
}

/* _gleShaderParse @ 0xf48d8 (244 bytes) */
int _gleShaderParse(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  undefined1 uVar4;
  undefined4 uVar2;
  char *pcVar3;
  undefined4 local_20 [4];
  
  if (*(char *)(param_2 + 0x24) != '\0') {
    iVar1 = *(int *)(param_2 + 0x30);
    local_20[0] = *(undefined4 *)(param_2 + 0x2c);
    *(undefined1 *)(param_2 + 0x25) = 0;
    if (iVar1 == 0) {
      iVar1 = _ShConstructCompiler(*(int *)(param_2 + 0x20) != 0x8b31,0);
      *(int *)(param_2 + 0x30) = iVar1;
    }
    uVar4 = _ShCompile(iVar1,local_20,1,*(undefined4 *)(param_1 + 0x7594),
                       *(undefined4 *)(param_1 + 0x7598));
    *(undefined1 *)(param_2 + 0x24) = 0;
    *(undefined1 *)(param_2 + 0x25) = uVar4;
    uVar2 = _ShGetInfoLog(*(undefined4 *)(param_2 + 0x30));
    uVar2 = _strlen(uVar2);
    *(undefined4 *)(param_2 + 0x1c) = uVar2;
    if (*(int *)(param_2 + 0x18) != 0) {
      _free(*(int *)(param_2 + 0x18));
    }
    *(undefined4 *)(param_2 + 0x18) = 0;
    if (*(int *)(param_2 + 0x1c) != 0) {
      iVar1 = _malloc(*(int *)(param_2 + 0x1c) + 1);
      *(int *)(param_2 + 0x18) = iVar1;
      if (iVar1 != 0) {
        pcVar3 = (char *)_ShGetInfoLog(*(undefined4 *)(param_2 + 0x30));
        _strncpy(*(char **)(param_2 + 0x18),pcVar3,*(size_t *)(param_2 + 0x1c));
      }
    }
  }
  return;
}

/* _gleCheckCompressedTexImageArgs @ 0xf49cc (212 bytes) */
int _gleCheckCompressedTexImageArgs(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  undefined4 param_2;
  int param_3;
  int param_4;
  int param_5;
  int param_6;
  int param_7;
  int param_8;
{
  undefined4 uVar1;
  int iVar2;
  
  if (param_3 < 0x83f4) {
    if (0x83f1 < param_3) goto LAB_000f4a24;
    if (param_3 < 0x83f0) goto LAB_000f4a2c;
    iVar2 = 3;
  }
  else {
    if (param_3 != 0x8837) {
LAB_000f4a2c:
      if (*(int *)(param_1 + 0x7574) != 0) {
        return 0;
      }
      uVar1 = 0x500;
      goto LAB_000f4a94;
    }
LAB_000f4a24:
    iVar2 = 4;
  }
  if (param_4 == 0) {
    if (param_8 == (param_5 + 3 >> 2) * (param_6 + 3 >> 2) * param_7 << iVar2) {
      return 1;
    }
    if (*(int *)(param_1 + 0x7574) != 0) {
      return 0;
    }
    uVar1 = 0x501;
  }
  else {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return 0;
    }
    uVar1 = 0x502;
  }
LAB_000f4a94:
  *(undefined4 *)(param_1 + 0x7574) = uVar1;
  return 0;
}

/* _gleCheckTexImage1DArgs @ 0xf4aa0 (284 bytes) */
int _gleCheckTexImage1DArgs(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  int param_5;
  int param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  iVar3 = _gleLookUpTexture1D(param_1,param_2);
  if (iVar3 == 0) {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return 0;
    }
    uVar1 = 0x500;
    goto LAB_000f4b68;
  }
  if (((*(uint *)(param_1 + 0x3410) & 1) != 0) && (*(short *)(param_1 + 13000) == -0x7fea)) {
    param_5 = (param_5 - *(int *)(param_1 + 0x32d0)) + 1;
  }
  uVar4 = param_5 + param_6 * -2;
  if (-1 < (int)uVar4) {
    if ((uVar4 & uVar4 - 1) == 0) {
      iVar2 = *(int *)(param_1 + 0x468c);
    }
    else {
      iVar2 = *(int *)(param_1 + 0x468c);
      if ((*(uint *)(iVar2 + 0x124) & 0x80000) == 0) goto LAB_000f4b58;
    }
    if ((int)uVar4 <= (int)(uint)*(ushort *)(iVar2 + 0xbc)) {
      iVar2 = _gleCheckTexImageArgs(param_1,param_3,param_7,param_8,param_4,param_6,1,1);
      if (iVar2 != 0) {
        return iVar3;
      }
      return 0;
    }
  }
LAB_000f4b58:
  if (*(int *)(param_1 + 0x7574) != 0) {
    return 0;
  }
  uVar1 = 0x501;
LAB_000f4b68:
  *(undefined4 *)(param_1 + 0x7574) = uVar1;
  return 0;
}

/* _gleCheckCopyTexImage1DArgs @ 0xf4bbc (268 bytes) */
int _gleCheckCopyTexImage1DArgs(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  int param_5;
  int param_6;
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  iVar3 = _gleLookUpNonProxyTexture1D(param_1,param_2);
  if (iVar3 == 0) {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return 0;
    }
    uVar1 = 0x500;
    goto LAB_000f4c7c;
  }
  if (((*(uint *)(param_1 + 0x3410) & 1) != 0) && (*(short *)(param_1 + 13000) == -0x7fea)) {
    param_5 = (param_5 - *(int *)(param_1 + 0x32d0)) + 1;
  }
  uVar4 = param_5 + param_6 * -2;
  if (-1 < (int)uVar4) {
    if ((uVar4 & uVar4 - 1) == 0) {
      iVar2 = *(int *)(param_1 + 0x468c);
    }
    else {
      iVar2 = *(int *)(param_1 + 0x468c);
      if ((*(uint *)(iVar2 + 0x124) & 0x80000) == 0) goto LAB_000f4c6c;
    }
    if ((int)uVar4 <= (int)(uint)*(ushort *)(iVar2 + 0xbc)) {
      iVar2 = _gleCheckCopyTexImageArgs(param_1,param_3,param_4,param_6,1,1);
      if (iVar2 != 0) {
        return iVar3;
      }
      return 0;
    }
  }
LAB_000f4c6c:
  if (*(int *)(param_1 + 0x7574) != 0) {
    return 0;
  }
  uVar1 = 0x501;
LAB_000f4c7c:
  *(undefined4 *)(param_1 + 0x7574) = uVar1;
  return 0;
}

/* _gleCheckColorTableArgs @ 0xf4cc8 (228 bytes) */
int _gleCheckColorTableArgs(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  uint param_4;
  undefined4 param_5;
  undefined4 param_6;
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = _gleLookUpColorTable(param_1,param_2);
  if (iVar2 == 0) {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return 0;
    }
    uVar1 = 0x500;
  }
  else {
    iVar3 = _gleCheckTexImageArgs(param_1,0,param_5,param_6,param_3,0,0,0);
    if (iVar3 == 0) {
      return 0;
    }
    if (((int)param_4 < 0) || ((param_4 & param_4 - 1) != 0)) {
      if (*(int *)(param_1 + 0x7574) != 0) {
        return 0;
      }
      uVar1 = 0x501;
    }
    else {
      if ((int)param_4 < 0x4001) {
        return iVar2;
      }
      if ((*(ushort *)(iVar2 + 0x24) & 0x100) != 0) {
        return 0;
      }
      if (*(int *)(param_1 + 0x7574) != 0) {
        return 0;
      }
      uVar1 = 0x8031;
    }
  }
  *(undefined4 *)(param_1 + 0x7574) = uVar1;
  return 0;
}

/* _gleCheckCopyColorTableArgs @ 0xf4dac (212 bytes) */
int _gleCheckCopyColorTableArgs(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  uint param_4;
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = _gleLookUpNonProxyColorTable(param_1,param_2);
  if (iVar2 == 0) {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return 0;
    }
    uVar1 = 0x500;
  }
  else {
    iVar3 = _gleCheckCopyTexImageArgs(param_1,0,param_3,0,0,0);
    if (iVar3 == 0) {
      return 0;
    }
    if (((int)param_4 < 0) || ((param_4 & param_4 - 1) != 0)) {
      if (*(int *)(param_1 + 0x7574) != 0) {
        return 0;
      }
      uVar1 = 0x501;
    }
    else {
      if ((int)param_4 < 0x4001) {
        return iVar2;
      }
      if ((*(ushort *)(iVar2 + 0x24) & 0x100) != 0) {
        return 0;
      }
      if (*(int *)(param_1 + 0x7574) != 0) {
        return 0;
      }
      uVar1 = 0x8031;
    }
  }
  *(undefined4 *)(param_1 + 0x7574) = uVar1;
  return 0;
}

/* _gleCheckCompressedTexImage2DArgs @ 0xf4e80 (360 bytes) */
int _gleCheckCompressedTexImage2DArgs(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  int param_5;
  int param_6;
  int param_7;
  undefined4 param_8;
{
  undefined4 uVar1;
  ushort uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  
  iVar4 = _gleLookUpTexture2D(param_1,param_2);
  if (iVar4 == 0) {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return 0;
    }
    uVar1 = 0x500;
    goto LAB_000f4f94;
  }
  uVar6 = param_6 + param_7 * -2;
  uVar7 = param_5 + param_7 * -2;
  uVar2 = *(ushort *)(iVar4 + 0x24) & 0xf;
  if (uVar2 == 2) {
    if (((-1 < (int)uVar7) &&
        (uVar3 = (uint)*(ushort *)(*(int *)(param_1 + 0x468c) + 0xc0), (int)uVar7 <= (int)uVar3)) &&
       (-1 < (int)uVar6)) {
LAB_000f4f80:
      if ((int)uVar6 <= (int)uVar3) {
LAB_000f4fa0:
        iVar5 = ((int (*)())_gleCheckCompressedTexImageArgs)(param_1,param_3,param_4,param_7,uVar7,uVar6,1,param_8);
        if (iVar5 != 0) {
          return iVar4;
        }
        return 0;
      }
    }
  }
  else {
    if (uVar2 < 3) {
      if ((*(ushort *)(iVar4 + 0x24) & 0xf) != 0) goto LAB_000f4fa0;
      if ((uVar7 != uVar6) ||
         ((int)(uint)*(ushort *)(*(int *)(param_1 + 0x468c) + 0xc2) < (int)uVar6))
      goto LAB_000f4f84;
    }
    else if (uVar2 != 3) goto LAB_000f4fa0;
    if (((-1 < (int)uVar7) &&
        ((((uVar7 & uVar7 - 1) == 0 &&
          (uVar3 = (uint)*(ushort *)(*(int *)(param_1 + 0x468c) + 0xbc), (int)uVar7 <= (int)uVar3))
         && (-1 < (int)uVar6)))) && ((uVar6 & uVar6 - 1) == 0)) goto LAB_000f4f80;
  }
LAB_000f4f84:
  if (*(int *)(param_1 + 0x7574) != 0) {
    return 0;
  }
  uVar1 = 0x501;
LAB_000f4f94:
  *(undefined4 *)(param_1 + 0x7574) = uVar1;
  return 0;
}

/* _gleCheckCompressedTexImage3DArgs @ 0xf4fe8 (296 bytes) */
int _gleCheckCompressedTexImage3DArgs(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  int param_5;
  int param_6;
  uint param_7;
  int param_8;
  undefined4 param_9;
{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  
  iVar3 = _gleLookUpTexture3D(param_1,param_2);
  if (iVar3 == 0) {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return 0;
    }
    uVar1 = 0x500;
  }
  else {
    uVar5 = param_6 + param_8 * -2;
    uVar6 = param_5 + param_8 * -2;
    if (((*(ushort *)(iVar3 + 0x24) & 0xf) != 1) ||
       ((((((-1 < (int)uVar6 && ((uVar6 & uVar6 - 1) == 0)) &&
           (uVar2 = (uint)*(ushort *)(*(int *)(param_1 + 0x468c) + 0xbe), (int)uVar6 <= (int)uVar2))
          && ((-1 < (int)uVar5 && ((uVar5 & uVar5 - 1) == 0)))) &&
         (((int)uVar5 <= (int)uVar2 && ((-1 < (int)param_7 && ((param_7 & param_7 - 1) == 0)))))) &&
        ((int)param_7 <= (int)uVar2)))) {
      iVar4 = ((int (*)())_gleCheckCompressedTexImageArgs)(param_1,param_3,param_4,param_8,uVar6,uVar5,param_7,param_9);
      if (iVar4 != 0) {
        return iVar3;
      }
      return 0;
    }
    if (*(int *)(param_1 + 0x7574) != 0) {
      return 0;
    }
    uVar1 = 0x501;
  }
  *(undefined4 *)(param_1 + 0x7574) = uVar1;
  return 0;
}

/* _gleCheckCompressedTexSubImageRange @ 0xf5110 (92 bytes) */
int _gleCheckCompressedTexSubImageRange(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  int param_2;
  uint param_3;
  uint param_4;
  int param_5;
  uint param_6;
{
  if (((-1 < (int)param_4) && ((int)-(uint)*(byte *)(param_2 + 10) <= (int)param_3)) &&
     ((int)(param_3 + param_4) <= (int)(param_5 + (uint)*(byte *)(param_2 + 10)))) {
    if ((param_3 & param_6) == 0) {
      if ((param_4 & param_6) == 0) {
        return 1;
      }
    }
  }
  if (*(int *)(param_1 + 0x7574) == 0) {
    *(undefined4 *)(param_1 + 0x7574) = 0x501;
  }
  return 0;
}

/* _gleCheckTexSubImage1DArgs @ 0xf516c (280 bytes) */
int _gleCheckTexSubImage1DArgs(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int param_1;
  undefined4 param_2;
  int param_3;
  undefined4 param_4;
  int param_5;
  int param_6;
  undefined4 param_7;
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = _gleLookUpNonProxyTexture1D(param_1,param_2);
  if (iVar2 == 0) {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return 0;
    }
    uVar1 = 0x500;
  }
  else {
    if ((param_6 != 0x1902) || (*(short *)(iVar2 + 0x26) == 0x1902)) {
      iVar3 = _gleCheckTexSubImageArgs(param_1,param_3,param_6,param_7);
      if (iVar3 == 0) {
        return 0;
      }
      iVar3 = iVar2 + param_3 * 0x18;
      if ((*(byte *)(iVar3 + 0xcf) & 0x20) != 0) {
        if (((*(uint *)(param_1 + 0x3410) & 1) != 0) && (*(short *)(param_1 + 13000) == -0x7fea)) {
          param_5 = (param_5 - *(int *)(param_1 + 0x32d0)) + 1;
        }
        iVar3 = _gleCheckTexSubImageRange
                          (param_1,iVar3 + 0xc4,param_4,param_5,(uint)*(ushort *)(iVar3 + 200));
        if (iVar3 != 0) {
          return iVar2;
        }
        return 0;
      }
    }
    if (*(int *)(param_1 + 0x7574) != 0) {
      return 0;
    }
    uVar1 = 0x502;
  }
  *(undefined4 *)(param_1 + 0x7574) = uVar1;
  return 0;
}

/* _gleCheckCopyTexSubImage1DArgs @ 0xf5284 (268 bytes) */
int _gleCheckCopyTexSubImage1DArgs(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  undefined4 param_2;
  uint param_3;
  undefined4 param_4;
  int param_5;
{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = _gleLookUpNonProxyTexture1D(param_1,param_2);
  if (iVar4 == 0) {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return 0;
    }
    uVar2 = 0x500;
  }
  else {
    bVar1 = true;
    if (0xe < param_3) {
      if (*(int *)(param_1 + 0x7574) == 0) {
        *(undefined4 *)(param_1 + 0x7574) = 0x501;
      }
      bVar1 = false;
    }
    if (!bVar1) {
      return 0;
    }
    iVar3 = iVar4 + param_3 * 0x18;
    if ((*(byte *)(iVar3 + 0xcf) & 0x20) != 0) {
      if (((*(uint *)(param_1 + 0x3410) & 1) != 0) && (*(short *)(param_1 + 13000) == -0x7fea)) {
        param_5 = (param_5 - *(int *)(param_1 + 0x32d0)) + 1;
      }
      iVar3 = _gleCheckTexSubImageRange
                        (param_1,iVar3 + 0xc4,param_4,param_5,(uint)*(ushort *)(iVar3 + 200));
      if (iVar3 != 0) {
        return iVar4;
      }
      return 0;
    }
    if (*(int *)(param_1 + 0x7574) != 0) {
      return 0;
    }
    uVar2 = 0x502;
  }
  *(undefined4 *)(param_1 + 0x7574) = uVar2;
  return 0;
}

/* _gleCheckCopyTexSubImage2DArgs @ 0xf5390 (476 bytes) */
int _gleCheckCopyTexSubImage2DArgs(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int param_1;
  int param_2;
  uint param_3;
  uint param_4;
  uint param_5;
  uint param_6;
  uint param_7;
{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar4 = _gleLookUpNonProxyTexture2D(param_1,param_2);
  if (iVar4 == 0) {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return 0;
    }
    uVar2 = 0x500;
LAB_000f549c:
    *(undefined4 *)(param_1 + 0x7574) = uVar2;
    return 0;
  }
  bVar1 = true;
  if (0xe < param_3) {
    if (*(int *)(param_1 + 0x7574) == 0) {
      *(undefined4 *)(param_1 + 0x7574) = 0x501;
    }
    bVar1 = false;
  }
  if (!bVar1) {
    return 0;
  }
  iVar6 = iVar4 + 0xc4 + param_3 * 0x18;
  if (param_2 - 0x8515U < 6) {
    iVar6 = iVar4 + 0xc4 + param_2 * 0x168 + param_3 * 0x18 + -0xbb2588;
  }
  if (((*(byte *)(iVar6 + 0xb) & 0x20) == 0) ||
     ((*(short *)(iVar6 + 0x12) == 0 &&
      (((((param_6 & 3) != 0 && (param_6 != *(ushort *)(iVar6 + 4))) ||
        (((param_7 & 3) != 0 && (param_7 != *(ushort *)(iVar6 + 6))))) ||
       (((param_4 & 3) != 0 || ((param_5 & 3) != 0)))))))) {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return 0;
    }
    uVar2 = 0x502;
    goto LAB_000f549c;
  }
  if ((*(uint *)(param_1 + 0x3410) & 2) == 0) {
    if (((*(uint *)(param_1 + 0x3410) & 4) == 0) || (*(short *)(param_1 + 0x3348) != -0x7fea))
    goto LAB_000f550c;
    iVar5 = *(int *)(param_1 + 0x3354);
    iVar3 = *(int *)(param_1 + 0x3350);
  }
  else {
    if (*(short *)(param_1 + 0x3308) != -0x7fea) goto LAB_000f550c;
    iVar5 = *(int *)(param_1 + 0x3314);
    iVar3 = *(int *)(param_1 + 0x3310);
  }
  param_6 = (param_6 - iVar3) + 1;
  param_7 = (param_7 - iVar5) + 1;
LAB_000f550c:
  iVar3 = _gleCheckTexSubImageRange(param_1,iVar6,param_4,param_6,(uint)*(ushort *)(iVar6 + 4));
  if (iVar3 == 0) {
    return 0;
  }
  iVar6 = _gleCheckTexSubImageRange(param_1,iVar6,param_5,param_7,(uint)*(ushort *)(iVar6 + 6));
  if (iVar6 != 0) {
    return iVar4;
  }
  return 0;
}

/* _gleCheckTexSubImage3DArgs @ 0xf556c (316 bytes) */
int _gleCheckTexSubImage3DArgs(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11)
  int param_1;
  undefined4 param_2;
  int param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
  undefined4 param_9;
  int param_10;
  undefined4 param_11;
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar2 = _gleLookUpNonProxyTexture3D(param_1,param_2);
  if (iVar2 == 0) {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return 0;
    }
    uVar1 = 0x500;
  }
  else {
    if ((param_10 != 0x1902) || (*(short *)(iVar2 + 0x26) == 0x1902)) {
      iVar3 = _gleCheckTexSubImageArgs(param_1,param_3,param_10,param_11);
      if (iVar3 == 0) {
        return 0;
      }
      iVar3 = iVar2 + param_3 * 0x18;
      iVar5 = iVar3 + 0xc4;
      if ((*(byte *)(iVar3 + 0xcf) & 0x20) != 0) {
        iVar4 = _gleCheckTexSubImageRange
                          (param_1,iVar5,param_4,param_7,(uint)*(ushort *)(iVar3 + 200));
        if (iVar4 == 0) {
          return 0;
        }
        iVar4 = _gleCheckTexSubImageRange
                          (param_1,iVar5,param_5,param_8,(uint)*(ushort *)(iVar3 + 0xca));
        if (iVar4 != 0) {
          iVar3 = _gleCheckTexSubImageRange
                            (param_1,iVar5,param_6,param_9,(uint)*(ushort *)(iVar3 + 0xcc));
          if (iVar3 != 0) {
            return iVar2;
          }
          return 0;
        }
        return 0;
      }
    }
    if (*(int *)(param_1 + 0x7574) != 0) {
      return 0;
    }
    uVar1 = 0x502;
  }
  *(undefined4 *)(param_1 + 0x7574) = uVar1;
  return 0;
}

/* _gleCheckCopyTexSubImage3DArgs @ 0xf56a8 (308 bytes) */
int _gleCheckCopyTexSubImage3DArgs(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9)
  int param_1;
  undefined4 param_2;
  uint param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
  undefined4 param_9;
{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar4 = _gleLookUpNonProxyTexture3D(param_1,param_2);
  if (iVar4 == 0) {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return 0;
    }
    uVar2 = 0x500;
  }
  else {
    bVar1 = true;
    if (0xe < param_3) {
      if (*(int *)(param_1 + 0x7574) == 0) {
        *(undefined4 *)(param_1 + 0x7574) = 0x501;
      }
      bVar1 = false;
    }
    if (!bVar1) {
      return 0;
    }
    iVar3 = iVar4 + param_3 * 0x18;
    iVar6 = iVar3 + 0xc4;
    if ((*(byte *)(iVar3 + 0xcf) & 0x20) != 0) {
      iVar5 = _gleCheckTexSubImageRange
                        (param_1,iVar6,param_4,param_7,(uint)*(ushort *)(iVar3 + 200));
      if (iVar5 == 0) {
        return 0;
      }
      iVar5 = _gleCheckTexSubImageRange
                        (param_1,iVar6,param_5,param_8,(uint)*(ushort *)(iVar3 + 0xca));
      if (iVar5 != 0) {
        iVar3 = _gleCheckTexSubImageRange
                          (param_1,iVar6,param_6,param_9,(uint)*(ushort *)(iVar3 + 0xcc));
        if (iVar3 != 0) {
          return iVar4;
        }
        return 0;
      }
      return 0;
    }
    if (*(int *)(param_1 + 0x7574) != 0) {
      return 0;
    }
    uVar2 = 0x502;
  }
  *(undefined4 *)(param_1 + 0x7574) = uVar2;
  return 0;
}

/* _gleCheckCompressedTexSubImage2DArgs @ 0xf57dc (320 bytes) */
int _gleCheckCompressedTexSubImage2DArgs(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9)
  int param_1;
  int param_2;
  int param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
  undefined4 param_9;
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = _gleLookUpNonProxyTexture2D(param_1,param_2);
  if (iVar2 == 0) {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return 0;
    }
    uVar1 = 0x500;
  }
  else {
    iVar3 = ((int (*)())_gleCheckCompressedTexImageArgs)(param_1,param_3,param_8,0,param_6,param_7,1,param_9);
    if (iVar3 == 0) {
      return 0;
    }
    iVar3 = iVar2 + 0xc4 + param_3 * 0x18;
    if (param_2 - 0x8515U < 6) {
      iVar3 = iVar2 + 0xc4 + param_2 * 0x168 + param_3 * 0x18 + -0xbb2588;
    }
    if (*(int *)(iVar3 + 0x14) != 0) {
      iVar4 = ((int (*)())_gleCheckCompressedTexSubImageRange)(param_1,iVar3,param_4,param_6,(uint)*(ushort *)(iVar3 + 4),3);
      if (iVar4 == 0) {
        return 0;
      }
      iVar3 = ((int (*)())_gleCheckCompressedTexSubImageRange)(param_1,iVar3,param_5,param_7,(uint)*(ushort *)(iVar3 + 6),3);
      if (iVar3 != 0) {
        return iVar2;
      }
      return 0;
    }
    if (*(int *)(param_1 + 0x7574) != 0) {
      return 0;
    }
    uVar1 = 0x502;
  }
  *(undefined4 *)(param_1 + 0x7574) = uVar1;
  return 0;
}

/* _gleCheckCompressedTexSubImage3DArgs @ 0xf591c (364 bytes) */
int _gleCheckCompressedTexSubImage3DArgs(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11)
  int param_1;
  int param_2;
  int param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
  undefined4 param_9;
  undefined4 param_10;
  undefined4 param_11;
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = _gleLookUpNonProxyTexture3D(param_1,param_2);
  if (iVar2 == 0) {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return 0;
    }
    uVar1 = 0x500;
  }
  else {
    iVar3 = ((int (*)())_gleCheckCompressedTexImageArgs)(param_1,param_3,param_10,0,param_7,param_8,param_9,param_11);
    if (iVar3 == 0) {
      return 0;
    }
    iVar3 = iVar2 + 0xc4 + param_3 * 0x18;
    if (param_2 - 0x8515U < 6) {
      iVar3 = iVar2 + 0xc4 + param_2 * 0x168 + param_3 * 0x18 + -0xbb2588;
    }
    if (*(int *)(iVar3 + 0x14) != 0) {
      iVar4 = ((int (*)())_gleCheckCompressedTexSubImageRange)(param_1,iVar3,param_4,param_7,(uint)*(ushort *)(iVar3 + 4),3);
      if (iVar4 == 0) {
        return 0;
      }
      iVar4 = ((int (*)())_gleCheckCompressedTexSubImageRange)(param_1,iVar3,param_5,param_8,(uint)*(ushort *)(iVar3 + 6),3);
      if (iVar4 != 0) {
        iVar3 = ((int (*)())_gleCheckCompressedTexSubImageRange)(param_1,iVar3,param_6,param_9,(uint)*(ushort *)(iVar3 + 8),0);
        if (iVar3 != 0) {
          return iVar2;
        }
        return 0;
      }
      return 0;
    }
    if (*(int *)(param_1 + 0x7574) != 0) {
      return 0;
    }
    uVar1 = 0x502;
  }
  *(undefined4 *)(param_1 + 0x7574) = uVar1;
  return 0;
}

/* _gleCheckColorSubTableArgs @ 0xf5a88 (200 bytes) */
int _gleCheckColorSubTableArgs(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = _gleLookUpNonProxyColorTable(param_1,param_2);
  if (iVar2 == 0) {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return 0;
    }
    uVar1 = 0x500;
  }
  else {
    iVar3 = _gleCheckTexSubImageArgs(param_1,0,param_5,param_6);
    if (iVar3 == 0) {
      return 0;
    }
    if (*(int *)(iVar2 + 0xc0) != 0) {
      iVar3 = _gleCheckTexSubImageRange
                        (param_1,iVar2 + 0xac,param_3,param_4,(uint)*(ushort *)(iVar2 + 0xb0));
      if (iVar3 != 0) {
        return iVar2;
      }
      return 0;
    }
    if (*(int *)(param_1 + 0x7574) != 0) {
      return 0;
    }
    uVar1 = 0x502;
  }
  *(undefined4 *)(param_1 + 0x7574) = uVar1;
  return 0;
}

/* _gleCheckCopyColorSubTableArgs @ 0xf5b50 (160 bytes) */
int _gleCheckCopyColorSubTableArgs(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = _gleLookUpNonProxyColorTable(param_1,param_2);
  if (iVar2 == 0) {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return 0;
    }
    uVar1 = 0x500;
  }
  else {
    if (*(int *)(iVar2 + 0xc0) != 0) {
      iVar3 = _gleCheckTexSubImageRange
                        (param_1,iVar2 + 0xac,param_3,param_4,(uint)*(ushort *)(iVar2 + 0xb0));
      if (iVar3 != 0) {
        return iVar2;
      }
      return 0;
    }
    if (*(int *)(param_1 + 0x7574) != 0) {
      return 0;
    }
    uVar1 = 0x502;
  }
  *(undefined4 *)(param_1 + 0x7574) = uVar1;
  return 0;
}

/* _gleSphereGenST @ 0xf5bf0 (356 bytes) */
double _gleSphereGenST(undefined4 param_1,undefined4 param_2,float *param_3,float *param_4,double fparam_1)
{
  float fVar1;
  undefined4 in_r7;
  undefined4 in_r8;
  double dVar2;
  double dVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  float local_30;
  float local_2c;
  float local_28;
  
  (**(code **)PTR__gleVectorNormalize_00112064)(param_1,param_2,&local_30,param_4,in_r7,in_r8);
  fVar1 = param_3[2] * local_28 + (*param_3 * local_30 + param_3[1] * local_2c);
  fVar1 = fVar1 + fVar1;
  dVar4 = -(double)(param_3[1] * fVar1 - local_2c);
  dVar3 = -(double)(*param_3 * fVar1 - local_30);
  fVar1 = (float)(-(double)(param_3[2] * fVar1 - local_28) + (double)FLOAT_00108e54);
  fVar1 = fVar1 * fVar1 + (float)(dVar3 * dVar3 + (double)(float)(dVar4 * dVar4));
  dVar5 = (double)fVar1;
  dVar2 = (double)FLOAT_00108e50;
  if (((double)FLOAT_00108e50 < dVar5) && (dVar2 = dVar5, dVar5 != (double)FLOAT_00108e54)) {
    dVar2 = (double)(float)(0x5f375a00 - ((uint)GH_F2U(fVar1) >> 1));
    dVar6 = (double)(float)((double)(float)(dVar5 * dVar2) * dVar2);
    dVar5 = (double)(float)(DOUBLE_00108e40 - dVar6);
    dVar2 = (double)(float)(dVar2 * DOUBLE_00108e38 * dVar5 *
                           (DOUBLE_00108e48 -
                           (double)(float)((double)(float)(dVar6 * dVar5) * dVar5)));
  }
  if (dVar2 <= (double)FLOAT_00108e80) {
    param_4[1] = 0.5;
    *param_4 = 0.5;
  }
  else {
    dVar5 = (double)FLOAT_00108e90;
    param_4[1] = (float)(dVar4 * dVar2 + dVar5);
    *param_4 = (float)(dVar3 * dVar2 + dVar5);
  }
  return;
}

/* _gleVtxTextureCoordGenObjectSlow @ 0xf5d54 (500 bytes) */
int _gleVtxTextureCoordGenObjectSlow(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  int param_3;
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  uVar6 = param_2 + param_3 * 0x100;
  if ((*(char *)(param_1 + 0x3d78) != '\0') && (*(short *)(param_1 + 0x3ce8) == 0x2401)) {
    fVar1 = *(float *)(param_1 + 0x3d08);
    fVar2 = *(float *)(param_1 + 0x3cfc);
    fVar3 = *(float *)(param_1 + 0x3d00);
    fVar4 = *(float *)(param_1 + 0x3d04);
    if (param_2 < uVar6) {
      uVar7 = (uVar6 - param_2) + 0xff >> 8;
      uVar5 = param_2;
      do {
        *(float *)(uVar5 + 0x80) =
             fVar1 * *(float *)(uVar5 + 0x2c) +
             (fVar4 * *(float *)(uVar5 + 0x28) +
             (fVar2 * *(float *)(uVar5 + 0x20) + fVar3 * *(float *)(uVar5 + 0x24)));
        uVar5 = uVar5 + 0x100;
        uVar7 = uVar7 - 1;
      } while (uVar7 != 0);
    }
  }
  if ((*(char *)(param_1 + 0x3d79) != '\0') && (*(short *)(param_1 + 0x3d0c) == 0x2401)) {
    fVar1 = *(float *)(param_1 + 0x3d2c);
    fVar2 = *(float *)(param_1 + 0x3d20);
    fVar3 = *(float *)(param_1 + 0x3d24);
    fVar4 = *(float *)(param_1 + 0x3d28);
    if (param_2 < uVar6) {
      uVar7 = (uVar6 - param_2) + 0xff >> 8;
      uVar5 = param_2;
      do {
        *(float *)(uVar5 + 0x84) =
             fVar1 * *(float *)(uVar5 + 0x2c) +
             (fVar4 * *(float *)(uVar5 + 0x28) +
             (fVar2 * *(float *)(uVar5 + 0x20) + fVar3 * *(float *)(uVar5 + 0x24)));
        uVar5 = uVar5 + 0x100;
        uVar7 = uVar7 - 1;
      } while (uVar7 != 0);
    }
  }
  if ((*(char *)(param_1 + 0x3d7a) != '\0') && (*(short *)(param_1 + 0x3d30) == 0x2401)) {
    fVar1 = *(float *)(param_1 + 0x3d50);
    fVar2 = *(float *)(param_1 + 0x3d44);
    fVar3 = *(float *)(param_1 + 0x3d48);
    fVar4 = *(float *)(param_1 + 0x3d4c);
    if (param_2 < uVar6) {
      uVar7 = (uVar6 - param_2) + 0xff >> 8;
      uVar5 = param_2;
      do {
        *(float *)(uVar5 + 0x88) =
             fVar1 * *(float *)(uVar5 + 0x2c) +
             (fVar4 * *(float *)(uVar5 + 0x28) +
             (fVar2 * *(float *)(uVar5 + 0x20) + fVar3 * *(float *)(uVar5 + 0x24)));
        uVar5 = uVar5 + 0x100;
        uVar7 = uVar7 - 1;
      } while (uVar7 != 0);
    }
    *(uint *)(param_1 + 0x486c) = *(uint *)(param_1 + 0x486c) | 1;
  }
  if (*(char *)(param_1 + 0x3d7b) == '\0') {
    return;
  }
  if (*(short *)(param_1 + 0x3d54) != 0x2401) {
    return;
  }
  fVar1 = *(float *)(param_1 + 0x3d74);
  fVar2 = *(float *)(param_1 + 0x3d68);
  fVar3 = *(float *)(param_1 + 0x3d6c);
  fVar4 = *(float *)(param_1 + 0x3d70);
  if (param_2 < uVar6) {
    uVar6 = (uVar6 - param_2) + 0xff >> 8;
    do {
      *(float *)(param_2 + 0x8c) =
           fVar1 * *(float *)(param_2 + 0x2c) +
           (fVar4 * *(float *)(param_2 + 0x28) +
           (fVar2 * *(float *)(param_2 + 0x20) + fVar3 * *(float *)(param_2 + 0x24)));
      param_2 = param_2 + 0x100;
      uVar6 = uVar6 - 1;
    } while (uVar6 != 0);
  }
  *(uint *)(param_1 + 0x486c) = *(uint *)(param_1 + 0x486c) | 3;
  return;
}

/* _gleVtxTextureCoordGenEyeSlow @ 0xf5f48 (1288 bytes) */
void _gleVtxTextureCoordGenEyeSlow(int param_1,uint param_2,int param_3,double fparam_1)
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  ushort uVar5;
  undefined *puVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  undefined4 local_40;
  undefined4 local_3c;
  float local_30;
  float local_2c;
  float local_28;
  
  puVar6 = PTR__gleVectorNormalize_00112064;
  uVar7 = param_2 + param_3 * 0x100;
  if (*(char *)(param_1 + 0x3d78) != '\0') {
    uVar5 = *(ushort *)(param_1 + 0x3ce8);
    uVar9 = param_2;
    if (uVar5 == 0x2402) {
      for (; uVar9 < uVar7; uVar9 = uVar9 + 0x100) {
        fparam_1 = (double)((double (*)())_gleSphereGenST)(param_1,uVar9 + 0x20,uVar9 + 0x40,&local_40,fparam_1);
        *(undefined4 *)(uVar9 + 0x80) = local_40;
      }
    }
    else if (uVar5 < 0x2403) {
      if (uVar5 == 0x2400) {
        fVar1 = *(float *)(param_1 + 0x3cf8);
        fVar2 = *(float *)(param_1 + 0x3cec);
        fVar3 = *(float *)(param_1 + 0x3cf0);
        fVar4 = *(float *)(param_1 + 0x3cf4);
        if (param_2 < uVar7) {
          uVar9 = (uVar7 - param_2) + 0xff >> 8;
          uVar8 = param_2;
          do {
            *(float *)(uVar8 + 0x80) =
                 fVar1 * *(float *)(uVar8 + 0x2c) +
                 (fVar4 * *(float *)(uVar8 + 0x28) +
                 (fVar2 * *(float *)(uVar8 + 0x20) + fVar3 * *(float *)(uVar8 + 0x24)));
            uVar8 = uVar8 + 0x100;
            uVar9 = uVar9 - 1;
          } while (uVar9 != 0);
        }
      }
    }
    else if (uVar5 == 0x8511) {
      if (param_2 < uVar7) {
        uVar9 = (uVar7 - param_2) + 0xff >> 8;
        uVar8 = param_2;
        do {
          *(undefined4 *)(uVar8 + 0x80) = *(undefined4 *)(uVar8 + 0x40);
          uVar8 = uVar8 + 0x100;
          uVar9 = uVar9 - 1;
        } while (uVar9 != 0);
      }
    }
    else if ((uVar5 == 0x8512) && (param_2 < uVar7)) {
      do {
        fparam_1 = (double)(**(double ( **)(int,int,int))puVar6)(param_1, uVar9 + 0x20, &local_30);
        fVar1 = *(float *)(uVar9 + 0x48) * local_28 +
                (*(float *)(uVar9 + 0x40) * local_30 + *(float *)(uVar9 + 0x44) * local_2c);
        *(float *)(uVar9 + 0x80) = -(*(float *)(uVar9 + 0x40) * (fVar1 + fVar1) - local_30);
        uVar9 = uVar9 + 0x100;
      } while (uVar9 < uVar7);
    }
  }
  puVar6 = PTR__gleVectorNormalize_00112064;
  if (*(char *)(param_1 + 0x3d79) != '\0') {
    uVar5 = *(ushort *)(param_1 + 0x3d0c);
    uVar9 = param_2;
    if (uVar5 == 0x2402) {
      for (; uVar9 < uVar7; uVar9 = uVar9 + 0x100) {
        fparam_1 = (double)((double (*)())_gleSphereGenST)(param_1,uVar9 + 0x20,uVar9 + 0x40,&local_40,fparam_1);
        *(undefined4 *)(uVar9 + 0x84) = local_3c;
      }
    }
    else if (uVar5 < 0x2403) {
      if (uVar5 == 0x2400) {
        fVar1 = *(float *)(param_1 + 0x3d1c);
        fVar2 = *(float *)(param_1 + 0x3d10);
        fVar3 = *(float *)(param_1 + 0x3d14);
        fVar4 = *(float *)(param_1 + 0x3d18);
        if (param_2 < uVar7) {
          uVar9 = (uVar7 - param_2) + 0xff >> 8;
          uVar8 = param_2;
          do {
            *(float *)(uVar8 + 0x84) =
                 fVar1 * *(float *)(uVar8 + 0x2c) +
                 (fVar4 * *(float *)(uVar8 + 0x28) +
                 (fVar2 * *(float *)(uVar8 + 0x20) + fVar3 * *(float *)(uVar8 + 0x24)));
            uVar8 = uVar8 + 0x100;
            uVar9 = uVar9 - 1;
          } while (uVar9 != 0);
        }
      }
    }
    else if (uVar5 == 0x8511) {
      if (param_2 < uVar7) {
        uVar9 = (uVar7 - param_2) + 0xff >> 8;
        uVar8 = param_2;
        do {
          *(undefined4 *)(uVar8 + 0x84) = *(undefined4 *)(uVar8 + 0x44);
          uVar8 = uVar8 + 0x100;
          uVar9 = uVar9 - 1;
        } while (uVar9 != 0);
      }
    }
    else if ((uVar5 == 0x8512) && (param_2 < uVar7)) {
      do {
        (**(code **)puVar6)(param_1,uVar9 + 0x20,&local_30);
        fVar1 = *(float *)(uVar9 + 0x48) * local_28 +
                (*(float *)(uVar9 + 0x40) * local_30 + *(float *)(uVar9 + 0x44) * local_2c);
        *(float *)(uVar9 + 0x84) = -(*(float *)(uVar9 + 0x44) * (fVar1 + fVar1) - local_2c);
        uVar9 = uVar9 + 0x100;
      } while (uVar9 < uVar7);
    }
  }
  puVar6 = PTR__gleVectorNormalize_00112064;
  if (*(char *)(param_1 + 0x3d7a) != '\0') {
    uVar5 = *(ushort *)(param_1 + 0x3d30);
    if (uVar5 == 0x8511) {
      if (param_2 < uVar7) {
        uVar9 = (uVar7 - param_2) + 0xff >> 8;
        uVar8 = param_2;
        do {
          *(undefined4 *)(uVar8 + 0x88) = *(undefined4 *)(uVar8 + 0x48);
          uVar8 = uVar8 + 0x100;
          uVar9 = uVar9 - 1;
        } while (uVar9 != 0);
      }
    }
    else if (uVar5 < 0x8512) {
      if (uVar5 == 0x2400) {
        fVar1 = *(float *)(param_1 + 0x3d40);
        fVar2 = *(float *)(param_1 + 0x3d34);
        fVar3 = *(float *)(param_1 + 0x3d38);
        fVar4 = *(float *)(param_1 + 0x3d3c);
        if (param_2 < uVar7) {
          uVar9 = (uVar7 - param_2) + 0xff >> 8;
          uVar8 = param_2;
          do {
            *(float *)(uVar8 + 0x88) =
                 fVar1 * *(float *)(uVar8 + 0x2c) +
                 (fVar4 * *(float *)(uVar8 + 0x28) +
                 (fVar2 * *(float *)(uVar8 + 0x20) + fVar3 * *(float *)(uVar8 + 0x24)));
            uVar8 = uVar8 + 0x100;
            uVar9 = uVar9 - 1;
          } while (uVar9 != 0);
        }
      }
    }
    else if ((uVar5 == 0x8512) && (param_2 < uVar7)) {
      uVar9 = param_2;
      do {
        (**(code **)puVar6)(param_1,uVar9 + 0x20,&local_30);
        fVar1 = *(float *)(uVar9 + 0x48) * local_28 +
                (*(float *)(uVar9 + 0x40) * local_30 + *(float *)(uVar9 + 0x44) * local_2c);
        *(float *)(uVar9 + 0x88) = -(*(float *)(uVar9 + 0x48) * (fVar1 + fVar1) - local_28);
        uVar9 = uVar9 + 0x100;
      } while (uVar9 < uVar7);
    }
    *(uint *)(param_1 + 0x486c) = *(uint *)(param_1 + 0x486c) | 1;
  }
  if (*(char *)(param_1 + 0x3d7b) != '\0') {
    if (*(short *)(param_1 + 0x3d54) == 0x2400) {
      fVar1 = *(float *)(param_1 + 0x3d64);
      fVar2 = *(float *)(param_1 + 0x3d58);
      fVar3 = *(float *)(param_1 + 0x3d5c);
      fVar4 = *(float *)(param_1 + 0x3d60);
      if (param_2 < uVar7) {
        uVar7 = (uVar7 - param_2) + 0xff >> 8;
        do {
          *(float *)(param_2 + 0x8c) =
               fVar1 * *(float *)(param_2 + 0x2c) +
               (fVar4 * *(float *)(param_2 + 0x28) +
               (fVar2 * *(float *)(param_2 + 0x20) + fVar3 * *(float *)(param_2 + 0x24)));
          param_2 = param_2 + 0x100;
          uVar7 = uVar7 - 1;
        } while (uVar7 != 0);
      }
    }
    *(uint *)(param_1 + 0x486c) = *(uint *)(param_1 + 0x486c) | 2;
  }
  return;
}

/* _gleVtxTextureCoordGenEyeST @ 0xf6450 (140 bytes) */
int _gleVtxTextureCoordGenEyeST(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  int param_3;
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  uint uVar9;
  
  uVar9 = param_2 + param_3 * 0x100;
  fVar1 = *(float *)(param_1 + 0x3cf8);
  fVar2 = *(float *)(param_1 + 0x3cf0);
  fVar3 = *(float *)(param_1 + 0x3cf4);
  fVar4 = *(float *)(param_1 + 0x3d10);
  fVar5 = *(float *)(param_1 + 0x3d1c);
  fVar6 = *(float *)(param_1 + 0x3cec);
  fVar7 = *(float *)(param_1 + 0x3d14);
  fVar8 = *(float *)(param_1 + 0x3d18);
  if (uVar9 <= param_2) {
    return;
  }
  uVar9 = (uVar9 - param_2) + 0xff >> 8;
  do {
    *(float *)(param_2 + 0x84) =
         fVar5 * *(float *)(param_2 + 0x2c) +
         (fVar8 * *(float *)(param_2 + 0x28) +
         (fVar4 * *(float *)(param_2 + 0x20) + fVar7 * *(float *)(param_2 + 0x24)));
    *(float *)(param_2 + 0x80) =
         fVar1 * *(float *)(param_2 + 0x2c) +
         (fVar3 * *(float *)(param_2 + 0x28) +
         (fVar6 * *(float *)(param_2 + 0x20) + fVar2 * *(float *)(param_2 + 0x24)));
    param_2 = param_2 + 0x100;
    uVar9 = uVar9 - 1;
  } while (uVar9 != 0);
  return;
}

/* _gleVtxTextureCoordGenObjectST @ 0xf64dc (140 bytes) */
int _gleVtxTextureCoordGenObjectST(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  int param_3;
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  uint uVar9;
  
  uVar9 = param_2 + param_3 * 0x100;
  fVar1 = *(float *)(param_1 + 0x3d08);
  fVar2 = *(float *)(param_1 + 0x3d00);
  fVar3 = *(float *)(param_1 + 0x3d04);
  fVar4 = *(float *)(param_1 + 0x3d20);
  fVar5 = *(float *)(param_1 + 0x3d2c);
  fVar6 = *(float *)(param_1 + 0x3cfc);
  fVar7 = *(float *)(param_1 + 0x3d24);
  fVar8 = *(float *)(param_1 + 0x3d28);
  if (uVar9 <= param_2) {
    return;
  }
  uVar9 = (uVar9 - param_2) + 0xff >> 8;
  do {
    *(float *)(param_2 + 0x84) =
         fVar5 * *(float *)(param_2 + 0x2c) +
         (fVar8 * *(float *)(param_2 + 0x28) +
         (fVar4 * *(float *)(param_2 + 0x20) + fVar7 * *(float *)(param_2 + 0x24)));
    *(float *)(param_2 + 0x80) =
         fVar1 * *(float *)(param_2 + 0x2c) +
         (fVar3 * *(float *)(param_2 + 0x28) +
         (fVar6 * *(float *)(param_2 + 0x20) + fVar2 * *(float *)(param_2 + 0x24)));
    param_2 = param_2 + 0x100;
    uVar9 = uVar9 - 1;
  } while (uVar9 != 0);
  return;
}

/* _gleVtxTextureCoordGenSphereST @ 0xf6568 (92 bytes) */
void _gleVtxTextureCoordGenSphereST(undefined4 param_1,uint param_2,int param_3,double fparam_1)
{
  uint uVar1;
  
  uVar1 = param_2 + param_3 * 0x100;
  for (; param_2 < uVar1; param_2 = param_2 + 0x100) {
    fparam_1 = (double)((double (*)())_gleSphereGenST)(param_1,param_2 + 0x20,param_2 + 0x40,param_2 + 0x80,fparam_1
                                      );
  }
  return;
}

/* _gleVtxTextureCoordGenReflectST @ 0xf65c4 (168 bytes) */
int _gleVtxTextureCoordGenReflectST(param_1, param_2, param_3)
  undefined4 param_1;
  uint param_2;
  int param_3;
{
  float fVar1;
  undefined *puVar2;
  uint uVar3;
  float fStack_30;
  float fStack_2c;
  float fStack_28;
  
  puVar2 = PTR__gleVectorNormalize_00112064;
  uVar3 = param_2 + param_3 * 0x100;
  for (; param_2 < uVar3; param_2 = param_2 + 0x100) {
    (**(code **)puVar2)(param_1,param_2 + 0x20,&fStack_30);
    fVar1 = *(float *)(param_2 + 0x48) * fStack_28 +
            (*(float *)(param_2 + 0x40) * fStack_30 + *(float *)(param_2 + 0x44) * fStack_2c);
    fVar1 = fVar1 + fVar1;
    *(float *)(param_2 + 0x84) = -(*(float *)(param_2 + 0x44) * fVar1 - fStack_2c);
    *(float *)(param_2 + 0x80) = -(*(float *)(param_2 + 0x40) * fVar1 - fStack_30);
  }
  return;
}

/* _gleVtxTextureCoordGenReflectSTR @ 0xf666c (188 bytes) */
void _gleVtxTextureCoordGenReflectSTR(int param_1,uint param_2,int param_3,double fparam_1)
{
  float fVar1;
  undefined *puVar2;
  uint uVar3;
  float fStack_30;
  float fStack_2c;
  float fStack_28;
  
  puVar2 = PTR__gleVectorNormalize_00112064;
  uVar3 = param_2 + param_3 * 0x100;
  for (; param_2 < uVar3; param_2 = param_2 + 0x100) {
    fparam_1 = (double)(**(double ( **)(int,int,int,double))puVar2)(param_1, param_2 + 0x20, &fStack_30, fparam_1);
    fVar1 = *(float *)(param_2 + 0x48) * fStack_28 +
            (*(float *)(param_2 + 0x40) * fStack_30 + *(float *)(param_2 + 0x44) * fStack_2c);
    fVar1 = fVar1 + fVar1;
    *(float *)(param_2 + 0x88) = -(*(float *)(param_2 + 0x48) * fVar1 - fStack_28);
    *(float *)(param_2 + 0x80) = -(*(float *)(param_2 + 0x40) * fVar1 - fStack_30);
    *(float *)(param_2 + 0x84) = -(*(float *)(param_2 + 0x44) * fVar1 - fStack_2c);
  }
  *(uint *)(param_1 + 0x486c) = *(uint *)(param_1 + 0x486c) | 1;
  return;
}

/* _gleVtxTextureCoordGenNormalST @ 0xf6728 (60 bytes) */
int _gleVtxTextureCoordGenNormalST(param_1, param_2, param_3)
  undefined4 param_1;
  uint param_2;
  int param_3;
{
  uint uVar1;
  
  uVar1 = param_2 + param_3 * 0x100;
  if (uVar1 <= param_2) {
    return;
  }
  uVar1 = (uVar1 - param_2) + 0xff >> 8;
  do {
    *(undefined4 *)(param_2 + 0x80) = *(undefined4 *)(param_2 + 0x40);
    *(undefined4 *)(param_2 + 0x84) = *(undefined4 *)(param_2 + 0x44);
    param_2 = param_2 + 0x100;
    uVar1 = uVar1 - 1;
  } while (uVar1 != 0);
  return;
}

/* _gleVtxTextureCoordGenNormalSTR @ 0xf6764 (80 bytes) */
int _gleVtxTextureCoordGenNormalSTR(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  int param_3;
{
  uint uVar1;
  
  uVar1 = param_2 + param_3 * 0x100;
  if (param_2 < uVar1) {
    uVar1 = (uVar1 - param_2) + 0xff >> 8;
    do {
      *(undefined4 *)(param_2 + 0x80) = *(undefined4 *)(param_2 + 0x40);
      *(undefined4 *)(param_2 + 0x84) = *(undefined4 *)(param_2 + 0x44);
      *(undefined4 *)(param_2 + 0x88) = *(undefined4 *)(param_2 + 0x48);
      param_2 = param_2 + 0x100;
      uVar1 = uVar1 - 1;
    } while (uVar1 != 0);
  }
  *(uint *)(param_1 + 0x486c) = *(uint *)(param_1 + 0x486c) | 1;
  return;
}

/* _gleMultiVtxTextureCoordGenWrapObject @ 0xf67b8 (112 bytes) */
int _gleMultiVtxTextureCoordGenWrapObject(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  uint uVar1;
  int iVar2;
  
  uVar1 = 0;
  iVar2 = param_1 + 0x5300;
  do {
    if (*(char *)(iVar2 + 0x1c) != '\0') {
      (**(code **)(iVar2 + 0x14))(param_1,param_2,param_3,uVar1);
    }
    uVar1 = uVar1 + 1;
    iVar2 = iVar2 + 0xc;
  } while (uVar1 < 8);
  return;
}

/* _gleMultiVtxTextureCoordGenWrapEye @ 0xf6828 (112 bytes) */
int _gleMultiVtxTextureCoordGenWrapEye(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  uint uVar1;
  int iVar2;
  
  uVar1 = 0;
  iVar2 = param_1 + 0x5300;
  do {
    if (*(char *)(iVar2 + 0x1c) != '\0') {
      (**(code **)(iVar2 + 0x18))(param_1,param_2,param_3,uVar1);
    }
    uVar1 = uVar1 + 1;
    iVar2 = iVar2 + 0xc;
  } while (uVar1 < 8);
  return;
}

/* _gleMultiVtxTextureCoordGenObjectSlow @ 0xf6898 (552 bytes) */
int _gleMultiVtxTextureCoordGenObjectSlow(param_1, param_2, param_3, param_4)
  int param_1;
  uint param_2;
  int param_3;
  int param_4;
{
  float *pfVar1;
  float *pfVar2;
  float *pfVar3;
  float *pfVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  uint uVar13;
  
  iVar12 = param_4 * 0x94;
  uVar10 = param_2 + param_3 * 0x100;
  iVar9 = iVar12 + param_1;
  if ((*(char *)(iVar9 + 0x3d78) != '\0') && (*(short *)(iVar9 + 0x3ce8) == 0x2401)) {
    fVar5 = *(float *)(iVar9 + 0x3cfc);
    fVar6 = *(float *)(iVar9 + 0x3d08);
    fVar7 = *(float *)(iVar9 + 0x3d00);
    fVar8 = *(float *)(iVar9 + 0x3d04);
    if (param_2 < uVar10) {
      uVar13 = (uVar10 - param_2) + 0xff >> 8;
      uVar11 = param_2;
      do {
        pfVar1 = (float *)(uVar11 + 0x24);
        iVar9 = param_4 * 0x10 + uVar11;
        pfVar2 = (float *)(uVar11 + 0x20);
        pfVar3 = (float *)(uVar11 + 0x28);
        pfVar4 = (float *)(uVar11 + 0x2c);
        uVar11 = uVar11 + 0x100;
        *(float *)(iVar9 + 0x80) =
             fVar6 * *pfVar4 + (fVar8 * *pfVar3 + (fVar5 * *pfVar2 + fVar7 * *pfVar1));
        uVar13 = uVar13 - 1;
      } while (uVar13 != 0);
    }
  }
  iVar9 = iVar12 + param_1;
  if ((*(char *)(iVar9 + 0x3d79) != '\0') && (*(short *)(iVar9 + 0x3d0c) == 0x2401)) {
    fVar5 = *(float *)(iVar9 + 0x3d20);
    fVar6 = *(float *)(iVar9 + 0x3d2c);
    fVar7 = *(float *)(iVar9 + 0x3d24);
    fVar8 = *(float *)(iVar9 + 0x3d28);
    if (param_2 < uVar10) {
      uVar13 = (uVar10 - param_2) + 0xff >> 8;
      uVar11 = param_2;
      do {
        pfVar1 = (float *)(uVar11 + 0x24);
        iVar9 = param_4 * 0x10 + uVar11;
        pfVar2 = (float *)(uVar11 + 0x20);
        pfVar3 = (float *)(uVar11 + 0x28);
        pfVar4 = (float *)(uVar11 + 0x2c);
        uVar11 = uVar11 + 0x100;
        *(float *)(iVar9 + 0x84) =
             fVar6 * *pfVar4 + (fVar8 * *pfVar3 + (fVar5 * *pfVar2 + fVar7 * *pfVar1));
        uVar13 = uVar13 - 1;
      } while (uVar13 != 0);
    }
  }
  iVar9 = iVar12 + param_1;
  if ((*(char *)(iVar9 + 0x3d7a) != '\0') && (*(short *)(iVar9 + 0x3d30) == 0x2401)) {
    fVar5 = *(float *)(iVar9 + 0x3d44);
    fVar6 = *(float *)(iVar9 + 0x3d50);
    fVar7 = *(float *)(iVar9 + 0x3d48);
    fVar8 = *(float *)(iVar9 + 0x3d4c);
    if (param_2 < uVar10) {
      uVar13 = (uVar10 - param_2) + 0xff >> 8;
      uVar11 = param_2;
      do {
        pfVar1 = (float *)(uVar11 + 0x24);
        iVar9 = param_4 * 0x10 + uVar11;
        pfVar2 = (float *)(uVar11 + 0x20);
        pfVar3 = (float *)(uVar11 + 0x28);
        pfVar4 = (float *)(uVar11 + 0x2c);
        uVar11 = uVar11 + 0x100;
        *(float *)(iVar9 + 0x88) =
             fVar6 * *pfVar4 + (fVar8 * *pfVar3 + (fVar5 * *pfVar2 + fVar7 * *pfVar1));
        uVar13 = uVar13 - 1;
      } while (uVar13 != 0);
    }
    *(uint *)(param_1 + 0x486c) = *(uint *)(param_1 + 0x486c) | 1;
  }
  iVar12 = iVar12 + param_1;
  if (*(char *)(iVar12 + 0x3d7b) == '\0') {
    return;
  }
  if (*(short *)(iVar12 + 0x3d54) != 0x2401) {
    return;
  }
  fVar5 = *(float *)(iVar12 + 0x3d68);
  fVar6 = *(float *)(iVar12 + 0x3d74);
  fVar7 = *(float *)(iVar12 + 0x3d6c);
  fVar8 = *(float *)(iVar12 + 0x3d70);
  if (param_2 < uVar10) {
    uVar10 = (uVar10 - param_2) + 0xff >> 8;
    do {
      pfVar1 = (float *)(param_2 + 0x24);
      iVar9 = param_4 * 0x10 + param_2;
      pfVar2 = (float *)(param_2 + 0x20);
      pfVar3 = (float *)(param_2 + 0x28);
      pfVar4 = (float *)(param_2 + 0x2c);
      param_2 = param_2 + 0x100;
      *(float *)(iVar9 + 0x8c) =
           fVar6 * *pfVar4 + (fVar8 * *pfVar3 + (fVar5 * *pfVar2 + fVar7 * *pfVar1));
      uVar10 = uVar10 - 1;
    } while (uVar10 != 0);
  }
  *(uint *)(param_1 + 0x486c) = *(uint *)(param_1 + 0x486c) | 2;
  return;
}

/* _gleMultiVtxTextureCoordGenEyeSlow @ 0xf6ac0 (1408 bytes) */
void _gleMultiVtxTextureCoordGenEyeSlow(int param_1,uint param_2,int param_3,int param_4,double fparam_1)
{
  undefined4 *puVar1;
  float *pfVar2;
  float *pfVar3;
  float *pfVar4;
  float *pfVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  ushort uVar10;
  undefined *puVar11;
  int iVar12;
  int iVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  float fStack_40;
  float fStack_3c;
  float fStack_38;
  
  puVar11 = PTR__gleVectorNormalize_00112064;
  iVar13 = param_4 * 0x94;
  iVar12 = iVar13 + param_1;
  uVar14 = param_2 + param_3 * 0x100;
  if (*(char *)(iVar12 + 0x3d78) != '\0') {
    uVar10 = *(ushort *)(iVar12 + 0x3ce8);
    if (uVar10 == 0x2402) {
      if (param_2 < uVar14) {
        uVar16 = param_2;
        do {
          fparam_1 = (double)((double (*)())_gleSphereGenST)(param_1,uVar16 + 0x20,uVar16 + 0x40,&uStack_50,fparam_1
                                            );
          iVar12 = param_4 * 0x10 + uVar16;
          uVar16 = uVar16 + 0x100;
          *(undefined4 *)(iVar12 + 0x80) = uStack_50;
        } while (uVar16 < uVar14);
      }
    }
    else if (uVar10 < 0x2403) {
      if (uVar10 == 0x2400) {
        fVar6 = *(float *)(iVar12 + 0x3cec);
        fVar7 = *(float *)(iVar12 + 0x3cf8);
        fVar8 = *(float *)(iVar12 + 0x3cf0);
        fVar9 = *(float *)(iVar12 + 0x3cf4);
        if (param_2 < uVar14) {
          uVar16 = (uVar14 - param_2) + 0xff >> 8;
          uVar15 = param_2;
          do {
            pfVar2 = (float *)(uVar15 + 0x24);
            iVar12 = param_4 * 0x10 + uVar15;
            pfVar3 = (float *)(uVar15 + 0x20);
            pfVar4 = (float *)(uVar15 + 0x28);
            pfVar5 = (float *)(uVar15 + 0x2c);
            uVar15 = uVar15 + 0x100;
            *(float *)(iVar12 + 0x80) =
                 fVar7 * *pfVar5 + (fVar9 * *pfVar4 + (fVar6 * *pfVar3 + fVar8 * *pfVar2));
            uVar16 = uVar16 - 1;
          } while (uVar16 != 0);
        }
      }
    }
    else if (uVar10 == 0x8511) {
      if (param_2 < uVar14) {
        uVar16 = (uVar14 - param_2) + 0xff >> 8;
        uVar15 = param_2;
        do {
          puVar1 = (undefined4 *)(uVar15 + 0x40);
          iVar12 = param_4 * 0x10 + uVar15;
          uVar15 = uVar15 + 0x100;
          *(undefined4 *)(iVar12 + 0x80) = *puVar1;
          uVar16 = uVar16 - 1;
        } while (uVar16 != 0);
      }
    }
    else if ((uVar10 == 0x8512) && (param_2 < uVar14)) {
      uVar16 = param_2;
      do {
        fparam_1 = (double)(**(double ( **)(int,int,int))puVar11)(param_1, uVar16 + 0x20, &fStack_40);
        pfVar2 = (float *)(uVar16 + 0x44);
        iVar12 = param_4 * 0x10 + uVar16;
        pfVar3 = (float *)(uVar16 + 0x40);
        pfVar4 = (float *)(uVar16 + 0x48);
        uVar16 = uVar16 + 0x100;
        fVar6 = *pfVar4 * fStack_38 + (*pfVar3 * fStack_40 + *pfVar2 * fStack_3c);
        *(float *)(iVar12 + 0x80) = -(*pfVar3 * (fVar6 + fVar6) - fStack_40);
      } while (uVar16 < uVar14);
    }
  }
  puVar11 = PTR__gleVectorNormalize_00112064;
  iVar12 = iVar13 + param_1;
  if (*(char *)(iVar12 + 0x3d79) != '\0') {
    uVar10 = *(ushort *)(iVar12 + 0x3d0c);
    if (uVar10 == 0x2402) {
      if (param_2 < uVar14) {
        uVar16 = param_2;
        do {
          fparam_1 = (double)((double (*)())_gleSphereGenST)(param_1,uVar16 + 0x20,uVar16 + 0x40,&uStack_50,fparam_1
                                            );
          iVar12 = param_4 * 0x10 + uVar16;
          uVar16 = uVar16 + 0x100;
          *(undefined4 *)(iVar12 + 0x84) = uStack_4c;
        } while (uVar16 < uVar14);
      }
    }
    else if (uVar10 < 0x2403) {
      if (uVar10 == 0x2400) {
        fVar6 = *(float *)(iVar12 + 0x3d10);
        fVar7 = *(float *)(iVar12 + 0x3d1c);
        fVar8 = *(float *)(iVar12 + 0x3d14);
        fVar9 = *(float *)(iVar12 + 0x3d18);
        if (param_2 < uVar14) {
          uVar16 = (uVar14 - param_2) + 0xff >> 8;
          uVar15 = param_2;
          do {
            pfVar2 = (float *)(uVar15 + 0x24);
            iVar12 = param_4 * 0x10 + uVar15;
            pfVar3 = (float *)(uVar15 + 0x20);
            pfVar4 = (float *)(uVar15 + 0x28);
            pfVar5 = (float *)(uVar15 + 0x2c);
            uVar15 = uVar15 + 0x100;
            *(float *)(iVar12 + 0x84) =
                 fVar7 * *pfVar5 + (fVar9 * *pfVar4 + (fVar6 * *pfVar3 + fVar8 * *pfVar2));
            uVar16 = uVar16 - 1;
          } while (uVar16 != 0);
        }
      }
    }
    else if (uVar10 == 0x8511) {
      if (param_2 < uVar14) {
        uVar16 = (uVar14 - param_2) + 0xff >> 8;
        uVar15 = param_2;
        do {
          puVar1 = (undefined4 *)(uVar15 + 0x44);
          iVar12 = param_4 * 0x10 + uVar15;
          uVar15 = uVar15 + 0x100;
          *(undefined4 *)(iVar12 + 0x84) = *puVar1;
          uVar16 = uVar16 - 1;
        } while (uVar16 != 0);
      }
    }
    else if ((uVar10 == 0x8512) && (param_2 < uVar14)) {
      uVar16 = param_2;
      do {
        (**(code **)puVar11)(param_1,uVar16 + 0x20,&fStack_40);
        pfVar2 = (float *)(uVar16 + 0x44);
        iVar12 = param_4 * 0x10 + uVar16;
        pfVar3 = (float *)(uVar16 + 0x40);
        pfVar4 = (float *)(uVar16 + 0x48);
        uVar16 = uVar16 + 0x100;
        fVar6 = *pfVar4 * fStack_38 + (*pfVar3 * fStack_40 + *pfVar2 * fStack_3c);
        *(float *)(iVar12 + 0x84) = -(*pfVar2 * (fVar6 + fVar6) - fStack_3c);
      } while (uVar16 < uVar14);
    }
  }
  puVar11 = PTR__gleVectorNormalize_00112064;
  iVar12 = iVar13 + param_1;
  if (*(char *)(iVar12 + 0x3d7a) != '\0') {
    uVar10 = *(ushort *)(iVar12 + 0x3d30);
    if (uVar10 == 0x8511) {
      if (param_2 < uVar14) {
        uVar16 = (uVar14 - param_2) + 0xff >> 8;
        uVar15 = param_2;
        do {
          puVar1 = (undefined4 *)(uVar15 + 0x48);
          iVar12 = param_4 * 0x10 + uVar15;
          uVar15 = uVar15 + 0x100;
          *(undefined4 *)(iVar12 + 0x88) = *puVar1;
          uVar16 = uVar16 - 1;
        } while (uVar16 != 0);
      }
    }
    else if (uVar10 < 0x8512) {
      if (uVar10 == 0x2400) {
        fVar6 = *(float *)(iVar12 + 0x3d34);
        fVar7 = *(float *)(iVar12 + 0x3d40);
        fVar8 = *(float *)(iVar12 + 0x3d38);
        fVar9 = *(float *)(iVar12 + 0x3d3c);
        if (param_2 < uVar14) {
          uVar16 = (uVar14 - param_2) + 0xff >> 8;
          uVar15 = param_2;
          do {
            pfVar2 = (float *)(uVar15 + 0x24);
            iVar12 = param_4 * 0x10 + uVar15;
            pfVar3 = (float *)(uVar15 + 0x20);
            pfVar4 = (float *)(uVar15 + 0x28);
            pfVar5 = (float *)(uVar15 + 0x2c);
            uVar15 = uVar15 + 0x100;
            *(float *)(iVar12 + 0x88) =
                 fVar7 * *pfVar5 + (fVar9 * *pfVar4 + (fVar6 * *pfVar3 + fVar8 * *pfVar2));
            uVar16 = uVar16 - 1;
          } while (uVar16 != 0);
        }
      }
    }
    else if ((uVar10 == 0x8512) && (param_2 < uVar14)) {
      uVar16 = param_2;
      do {
        (**(code **)puVar11)(param_1,uVar16 + 0x20,&fStack_40);
        pfVar2 = (float *)(uVar16 + 0x44);
        iVar12 = param_4 * 0x10 + uVar16;
        pfVar3 = (float *)(uVar16 + 0x40);
        pfVar4 = (float *)(uVar16 + 0x48);
        uVar16 = uVar16 + 0x100;
        fVar6 = *pfVar4 * fStack_38 + (*pfVar3 * fStack_40 + *pfVar2 * fStack_3c);
        *(float *)(iVar12 + 0x88) = -(*pfVar4 * (fVar6 + fVar6) - fStack_38);
      } while (uVar16 < uVar14);
    }
    *(uint *)(param_1 + 0x486c) = *(uint *)(param_1 + 0x486c) | 1;
  }
  iVar13 = iVar13 + param_1;
  if (*(char *)(iVar13 + 0x3d7b) != '\0') {
    if (*(short *)(iVar13 + 0x3d54) == 0x2400) {
      fVar6 = *(float *)(iVar13 + 0x3d58);
      fVar7 = *(float *)(iVar13 + 0x3d64);
      fVar8 = *(float *)(iVar13 + 0x3d5c);
      fVar9 = *(float *)(iVar13 + 0x3d60);
      if (param_2 < uVar14) {
        uVar14 = (uVar14 - param_2) + 0xff >> 8;
        do {
          pfVar2 = (float *)(param_2 + 0x24);
          iVar12 = param_4 * 0x10 + param_2;
          pfVar3 = (float *)(param_2 + 0x20);
          pfVar4 = (float *)(param_2 + 0x28);
          pfVar5 = (float *)(param_2 + 0x2c);
          param_2 = param_2 + 0x100;
          *(float *)(iVar12 + 0x8c) =
               fVar7 * *pfVar5 + (fVar9 * *pfVar4 + (fVar6 * *pfVar3 + fVar8 * *pfVar2));
          uVar14 = uVar14 - 1;
        } while (uVar14 != 0);
      }
    }
    *(uint *)(param_1 + 0x486c) = *(uint *)(param_1 + 0x486c) | 2;
  }
  return;
}

/* _gleMultiVtxTextureCoordGenEyeST @ 0xf7040 (156 bytes) */
int _gleMultiVtxTextureCoordGenEyeST(param_1, param_2, param_3, param_4)
  int param_1;
  uint param_2;
  int param_3;
  int param_4;
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
  uint uVar13;
  int iVar14;
  
  uVar13 = param_2 + param_3 * 0x100;
  iVar14 = param_1 + param_4 * 0x94;
  fVar1 = *(float *)(iVar14 + 0x3d10);
  fVar2 = *(float *)(iVar14 + 0x3cf8);
  fVar3 = *(float *)(iVar14 + 0x3cf0);
  fVar4 = *(float *)(iVar14 + 0x3cf4);
  fVar5 = *(float *)(iVar14 + 0x3d1c);
  fVar6 = *(float *)(iVar14 + 0x3cec);
  fVar7 = *(float *)(iVar14 + 0x3d14);
  fVar8 = *(float *)(iVar14 + 0x3d18);
  if (uVar13 <= param_2) {
    return;
  }
  uVar13 = (uVar13 - param_2) + 0xff >> 8;
  do {
    fVar9 = *(float *)(param_2 + 0x24);
    iVar14 = param_4 * 0x10 + param_2;
    fVar10 = *(float *)(param_2 + 0x20);
    fVar11 = *(float *)(param_2 + 0x28);
    fVar12 = *(float *)(param_2 + 0x2c);
    param_2 = param_2 + 0x100;
    *(float *)(iVar14 + 0x84) = fVar5 * fVar12 + (fVar8 * fVar11 + (fVar1 * fVar10 + fVar7 * fVar9));
    *(float *)(iVar14 + 0x80) = fVar2 * fVar12 + (fVar4 * fVar11 + (fVar6 * fVar10 + fVar3 * fVar9));
    uVar13 = uVar13 - 1;
  } while (uVar13 != 0);
  return;
}

/* _gleMultiVtxTextureCoordGenObjectST @ 0xf70dc (156 bytes) */
int _gleMultiVtxTextureCoordGenObjectST(param_1, param_2, param_3, param_4)
  int param_1;
  uint param_2;
  int param_3;
  int param_4;
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
  uint uVar13;
  int iVar14;
  
  uVar13 = param_2 + param_3 * 0x100;
  iVar14 = param_1 + param_4 * 0x94;
  fVar1 = *(float *)(iVar14 + 0x3d20);
  fVar2 = *(float *)(iVar14 + 0x3d08);
  fVar3 = *(float *)(iVar14 + 0x3d00);
  fVar4 = *(float *)(iVar14 + 0x3d04);
  fVar5 = *(float *)(iVar14 + 0x3d2c);
  fVar6 = *(float *)(iVar14 + 0x3cfc);
  fVar7 = *(float *)(iVar14 + 0x3d24);
  fVar8 = *(float *)(iVar14 + 0x3d28);
  if (uVar13 <= param_2) {
    return;
  }
  uVar13 = (uVar13 - param_2) + 0xff >> 8;
  do {
    fVar9 = *(float *)(param_2 + 0x24);
    iVar14 = param_4 * 0x10 + param_2;
    fVar10 = *(float *)(param_2 + 0x20);
    fVar11 = *(float *)(param_2 + 0x28);
    fVar12 = *(float *)(param_2 + 0x2c);
    param_2 = param_2 + 0x100;
    *(float *)(iVar14 + 0x84) = fVar5 * fVar12 + (fVar8 * fVar11 + (fVar1 * fVar10 + fVar7 * fVar9));
    *(float *)(iVar14 + 0x80) = fVar2 * fVar12 + (fVar4 * fVar11 + (fVar6 * fVar10 + fVar3 * fVar9));
    uVar13 = uVar13 - 1;
  } while (uVar13 != 0);
  return;
}

/* _gleMultiVtxTextureCoordGenSphereST @ 0xf7178 (108 bytes) */
void _gleMultiVtxTextureCoordGenSphereST(undefined4 param_1,uint param_2,int param_3,int param_4,double fparam_1)
{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  uVar3 = param_2 + param_3 * 0x100;
  if (param_2 < uVar3) {
    iVar4 = param_2 + param_4 * 0x10 + 0x80;
    do {
      iVar1 = param_2 + 0x20;
      iVar2 = param_2 + 0x40;
      param_2 = param_2 + 0x100;
      fparam_1 = (double)((double (*)())_gleSphereGenST)(param_1,iVar1,iVar2,iVar4,fparam_1);
      iVar4 = iVar4 + 0x100;
    } while (param_2 < uVar3);
  }
  return;
}

/* _gleMultiVtxTextureCoordGenReflectST @ 0xf71e4 (184 bytes) */
int _gleMultiVtxTextureCoordGenReflectST(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  uint param_2;
  int param_3;
  int param_4;
{
  float *pfVar1;
  float fVar2;
  undefined *puVar3;
  int iVar4;
  uint uVar5;
  float fStack_30;
  float fStack_2c;
  float fStack_28;
  
  puVar3 = PTR__gleVectorNormalize_00112064;
  uVar5 = param_2 + param_3 * 0x100;
  if (param_2 < uVar5) {
    do {
      (**(code **)puVar3)(param_1,param_2 + 0x20,&fStack_30);
      iVar4 = param_4 * 0x10 + param_2;
      fVar2 = *(float *)(param_2 + 0x48) * fStack_28 +
              (*(float *)(param_2 + 0x40) * fStack_30 + *(float *)(param_2 + 0x44) * fStack_2c);
      fVar2 = fVar2 + fVar2;
      *(float *)(iVar4 + 0x80) = -(*(float *)(param_2 + 0x40) * fVar2 - fStack_30);
      pfVar1 = (float *)(param_2 + 0x44);
      param_2 = param_2 + 0x100;
      *(float *)(iVar4 + 0x84) = -(*pfVar1 * fVar2 - fStack_2c);
    } while (param_2 < uVar5);
  }
  return;
}

/* _gleMultiVtxTextureCoordGenReflectSTR @ 0xf729c (212 bytes) */
void _gleMultiVtxTextureCoordGenReflectSTR(int param_1,uint param_2,int param_3,int param_4,double fparam_1)
{
  float *pfVar1;
  float fVar2;
  undefined *puVar3;
  int iVar4;
  uint uVar5;
  float fStack_30;
  float fStack_2c;
  float fStack_28;
  
  puVar3 = PTR__gleVectorNormalize_00112064;
  uVar5 = param_2 + param_3 * 0x100;
  if (param_2 < uVar5) {
    do {
      fparam_1 = (double)(**(double ( **)(int,int,int,double))puVar3)(param_1, param_2 + 0x20, &fStack_30, fparam_1);
      iVar4 = param_4 * 0x10 + param_2;
      fVar2 = *(float *)(param_2 + 0x48) * fStack_28 +
              (*(float *)(param_2 + 0x40) * fStack_30 + *(float *)(param_2 + 0x44) * fStack_2c);
      fVar2 = fVar2 + fVar2;
      *(float *)(iVar4 + 0x80) = -(*(float *)(param_2 + 0x40) * fVar2 - fStack_30);
      *(float *)(iVar4 + 0x84) = -(*(float *)(param_2 + 0x44) * fVar2 - fStack_2c);
      pfVar1 = (float *)(param_2 + 0x48);
      param_2 = param_2 + 0x100;
      *(float *)(iVar4 + 0x88) = -(*pfVar1 * fVar2 - fStack_28);
    } while (param_2 < uVar5);
  }
  *(uint *)(param_1 + 0x486c) = *(uint *)(param_1 + 0x486c) | 1;
  return;
}

/* _gleMultiVtxTextureCoordGenNormalST @ 0xf7370 (68 bytes) */
int _gleMultiVtxTextureCoordGenNormalST(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  uint param_2;
  int param_3;
  int param_4;
{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = param_2 + param_3 * 0x100;
  if (uVar2 <= param_2) {
    return;
  }
  uVar2 = (uVar2 - param_2) + 0xff >> 8;
  do {
    iVar3 = param_4 * 0x10 + param_2;
    *(undefined4 *)(iVar3 + 0x80) = *(undefined4 *)(param_2 + 0x40);
    puVar1 = (undefined4 *)(param_2 + 0x44);
    param_2 = param_2 + 0x100;
    *(undefined4 *)(iVar3 + 0x84) = *puVar1;
    uVar2 = uVar2 - 1;
  } while (uVar2 != 0);
  return;
}

