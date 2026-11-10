#include "decls.h"

/* _gleLightMaterialRGBAChange_FB_A @ 0x32efc (224 bytes) */
void _gleLightMaterialRGBAChange_FB_A(param_1, param_2)
  int param_1;
  undefined8 *param_2;
{
  byte bVar1;
  undefined8 *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined8 uVar7;
  
  iVar6 = 0;
  do {
    puVar2 = (undefined8 *)((int (*)())_glePushMaterial)(param_1,iVar6);
    *puVar2 = *param_2;
    uVar7 = param_2[1];
    *(ushort *)((int)puVar2 + 0x234) = *(ushort *)((int)puVar2 + 0x234) | 0x404;
    puVar2[1] = uVar7;
    if (*(int *)(param_1 + 0x5434) == 0) {
      bVar1 = *(byte *)(iVar6 * 6 + *(int *)(param_1 + 0x5420) + 0x2c0);
    }
    else {
      bVar1 = *(byte *)(iVar6 * 6 + *(int *)(*(int *)(param_1 + 0x5430) + 0x20) + 0x2f4);
    }
    iVar4 = iVar6 * 6;
    iVar5 = (bVar1 >> 3 & 0x1c) + param_1;
    iVar6 = iVar6 + 1;
    iVar3 = *(int *)(param_1 + 0x5424);
    *(uint *)(iVar5 + 0x324) = *(uint *)(iVar5 + 0x324) | 1 << (bVar1 & 0x1f);
    bVar1 = *(byte *)(iVar4 + iVar3 + 0x2c0);
    iVar3 = (bVar1 >> 3 & 0x1c) + param_1;
    *(uint *)(iVar3 + 0x348) = *(uint *)(iVar3 + 0x348) | 1 << (bVar1 & 0x1f);
  } while (iVar6 < 2);
  return;
}

/* _glePushMaterial @ 0x32fdc (260 bytes) */
int _glePushMaterial(param_1, param_2)
  int param_1;
  int param_2;
{
  undefined4 uVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  
  puVar3 = *(undefined8 **)(param_2 * 4 + param_1 + 0x4dd0);
  if (((*(ushort *)(param_1 + 0x4a10) & 0x8000) == 0) && (*(int *)(puVar3 + 0x3c) != 0)) {
    puVar2 = *(undefined8 **)(param_1 + 0x4dd8);
    if (puVar2 == (undefined8 *)0x0) {
      puVar2 = (undefined8 *)_gleVecAlloc(0x240);
      *(undefined4 *)((int)puVar2 + 500) = 0xbf800000;
    }
    else {
      *(undefined4 *)(param_1 + 0x4dd8) = *(undefined4 *)((int)puVar2 + 0x23c);
    }
    *puVar2 = *puVar3;
    puVar2[1] = puVar3[1];
    puVar2[2] = puVar3[2];
    puVar2[3] = puVar3[3];
    puVar2[4] = puVar3[4];
    puVar2[5] = puVar3[5];
    puVar2[6] = puVar3[6];
    uVar4 = puVar3[7];
    *(undefined4 *)(puVar2 + 0x47) = 0;
    puVar2[7] = uVar4;
    uVar1 = *(undefined4 *)(puVar3 + 8);
    *(undefined4 *)(puVar2 + 0x3c) = 0;
    *(undefined8 **)(puVar3 + 0x47) = puVar2;
    *(undefined4 *)(puVar2 + 8) = uVar1;
    *(undefined8 **)((int)puVar2 + 0x23c) = puVar3;
    *(undefined8 **)(param_2 * 4 + param_1 + 0x4dd0) = puVar2;
    *(undefined4 *)((int)puVar2 + 0x234) = 0x1f000000;
    puVar3 = puVar2;
  }
  else if ((*(ushort *)(param_1 + 0x4a10) & 0x8000) != 0) {
    *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 1;
  }
  return puVar3;
}

/* _gleLightMaterialRGBAChange_FB_D @ 0x330e0 (224 bytes) */
void _gleLightMaterialRGBAChange_FB_D(param_1, param_2)
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
    iVar2 = ((int (*)())_glePushMaterial)(param_1,iVar5);
    *(undefined8 *)(iVar2 + 0x10) = *param_2;
    uVar6 = param_2[1];
    *(ushort *)(iVar2 + 0x234) = *(ushort *)(iVar2 + 0x234) | 0x808;
    *(undefined8 *)(iVar2 + 0x18) = uVar6;
    if (*(int *)(param_1 + 0x5434) == 0) {
      bVar1 = *(byte *)(iVar5 * 6 + *(int *)(param_1 + 0x5420) + 0x2c1);
    }
    else {
      bVar1 = *(byte *)(iVar5 * 6 + *(int *)(*(int *)(param_1 + 0x5430) + 0x20) + 0x2f5);
    }
    iVar3 = iVar5 * 6;
    iVar4 = (bVar1 >> 3 & 0x1c) + param_1;
    iVar5 = iVar5 + 1;
    iVar2 = *(int *)(param_1 + 0x5424);
    *(uint *)(iVar4 + 0x324) = *(uint *)(iVar4 + 0x324) | 1 << (bVar1 & 0x1f);
    bVar1 = *(byte *)(iVar3 + iVar2 + 0x2c1);
    iVar2 = (bVar1 >> 3 & 0x1c) + param_1;
    *(uint *)(iVar2 + 0x348) = *(uint *)(iVar2 + 0x348) | 1 << (bVar1 & 0x1f);
  } while (iVar5 < 2);
  return;
}

/* _gleLightMaterialShineChange_FB @ 0x331c0 (220 bytes) */
void _gleLightMaterialShineChange_FB(int param_1,double fparam_1)
{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  
  uVar5 = 0;
  do {
    iVar2 = ((int (*)())_glePushMaterial)(param_1,uVar5);
    *(float *)(iVar2 + 0x40) = (float)fparam_1;
    *(ushort *)(iVar2 + 0x234) = *(ushort *)(iVar2 + 0x234) | 0x101;
    if (*(int *)(param_1 + 0x5434) == 0) {
      bVar1 = *(byte *)(uVar5 * 6 + *(int *)(param_1 + 0x5420) + 0x2c4);
    }
    else {
      bVar1 = *(byte *)(uVar5 * 6 + *(int *)(*(int *)(param_1 + 0x5430) + 0x20) + 0x2f8);
    }
    iVar3 = uVar5 * 6;
    iVar4 = (bVar1 >> 3 & 0x1c) + param_1;
    uVar5 = uVar5 + 1;
    iVar2 = *(int *)(param_1 + 0x5424);
    *(uint *)(iVar4 + 0x324) = *(uint *)(iVar4 + 0x324) | 1 << (bVar1 & 0x1f);
    bVar1 = *(byte *)(iVar3 + iVar2 + 0x2c4);
    iVar2 = (bVar1 >> 3 & 0x1c) + param_1;
    *(uint *)(iVar2 + 0x348) = *(uint *)(iVar2 + 0x348) | 1 << (bVar1 & 0x1f);
  } while (uVar5 < 2);
  return;
}

/* _gleLightMaterialRGBAChange_FB_S @ 0x3329c (224 bytes) */
void _gleLightMaterialRGBAChange_FB_S(param_1, param_2)
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
    iVar2 = ((int (*)())_glePushMaterial)(param_1,iVar5);
    *(undefined8 *)(iVar2 + 0x20) = *param_2;
    uVar6 = param_2[1];
    *(ushort *)(iVar2 + 0x234) = *(ushort *)(iVar2 + 0x234) | 0x1010;
    *(undefined8 *)(iVar2 + 0x28) = uVar6;
    if (*(int *)(param_1 + 0x5434) == 0) {
      bVar1 = *(byte *)(iVar5 * 6 + *(int *)(param_1 + 0x5420) + 0x2c2);
    }
    else {
      bVar1 = *(byte *)(iVar5 * 6 + *(int *)(*(int *)(param_1 + 0x5430) + 0x20) + 0x2f6);
    }
    iVar3 = iVar5 * 6;
    iVar4 = (bVar1 >> 3 & 0x1c) + param_1;
    iVar5 = iVar5 + 1;
    iVar2 = *(int *)(param_1 + 0x5424);
    *(uint *)(iVar4 + 0x324) = *(uint *)(iVar4 + 0x324) | 1 << (bVar1 & 0x1f);
    bVar1 = *(byte *)(iVar3 + iVar2 + 0x2c2);
    iVar2 = (bVar1 >> 3 & 0x1c) + param_1;
    *(uint *)(iVar2 + 0x348) = *(uint *)(iVar2 + 0x348) | 1 << (bVar1 & 0x1f);
  } while (iVar5 < 2);
  return;
}

/* _glPushMatrix_Exec @ 0x3337c (244 bytes) */
int _glPushMatrix_Exec(param_1)
  int param_1;
{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = *(int *)(param_1 + 0x4ff4);
  if ((*(short *)(param_1 + 0x4a10) < 0) && (iVar5 < 0x18)) {
    iVar1 = iVar5 * 4;
    iVar3 = *(int *)(iVar1 + *(int *)(param_1 + 0x4ff8));
    iVar4 = *(int *)(iVar1 + param_1 + 0x4ffc);
    if (iVar4 < *(int *)(iVar1 + *(int *)(param_1 + 0x4ff8) + 4) - iVar3) {
      uVar2 = ((int (*)())_gleCopyMatrix)(param_1 + iVar5 * 0x40 + 0x1bc0,
                             *(int *)(param_1 + 0x4678) + (iVar3 + iVar4) * 0x40);
      if (iVar5 == 4) {
        if ((*(uint *)(param_1 + 0x50b0) & 0x10) != 0) {
          ((double (*)())_gleModelMatInvert)(param_1);
        }
        uVar2 = ((int (*)())_gleCopyMatrix)(param_1 + 0x22c0,*(int *)(param_1 + 0x4678) + iVar4 * 0x40 + 0x2b00);
      }
      *(int *)(iVar1 + param_1 + 0x4ffc) = iVar4 + 1;
      return uVar2;
    }
    if (*(int *)(param_1 + 0x7574) != 0) {
      return param_1;
    }
    uVar2 = 0x503;
  }
  else {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return param_1;
    }
    uVar2 = 0x502;
  }
  *(undefined4 *)(param_1 + 0x7574) = uVar2;
  return param_1;
}

/* _gleCopyMatrix @ 0x33470 (68 bytes) */
int _gleCopyMatrix(param_1, param_2)
  undefined8 *param_1;
  undefined8 *param_2;
{
  *param_2 = *param_1;
  param_2[1] = param_1[1];
  param_2[2] = param_1[2];
  param_2[3] = param_1[3];
  param_2[4] = param_1[4];
  param_2[5] = param_1[5];
  param_2[6] = param_1[6];
  param_2[7] = param_1[7];
  return;
}

/* _gleModelMatInvert @ 0x334b4 (188 bytes) */
double _gleModelMatInvert(int param_1)
{
  int iVar1;
  int iVar2;
  double dVar3;
  double dVar4;
  
  *(uint *)(param_1 + 0x50b0) = *(uint *)(param_1 + 0x50b0) & 0xffffffef;
  dVar3 = (double)(*(double ( *)(int,int))_gleInvertMatrix)(param_1, 4);
  if (*(char *)(param_1 + 0x280e) == '\0') {
    *(undefined4 *)(param_1 + 0x2804) = 0x3f800000;
  }
  else {
    dVar4 = _sqrt((double)(*(float *)(param_1 + 0x22e8) * *(float *)(param_1 + 0x22e8) +
                          (*(float *)(param_1 + 0x22d8) * *(float *)(param_1 + 0x22d8) +
                          *(float *)(param_1 + 0x22c8) * *(float *)(param_1 + 0x22c8))));
    iVar2 = 0x10;
    iVar1 = 0;
    dVar4 = DOUBLE_00108d68 / dVar4;
    dVar3 = (double)(float)dVar4;
    do {
      *(float *)(iVar1 + param_1 + 0x22c0) =
           (float)((double)*(float *)(iVar1 + param_1 + 0x22c0) * dVar3);
      iVar1 = iVar1 + 4;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    *(float *)(param_1 + 0x2804) = (float)dVar4;
  }
  return dVar3;
}

/* _gleSetupInvertMatrix @ 0x33570 (80 bytes) */
void _gleSetupInvertMatrix()
{
  _gleInvertMatrix = PTR__gleInvertMatrix_601_00110e80;
  if ((*(uint *)PTR__gle_processor_0011204c & 0x10) != 0) {
    _gleInvertMatrix = PTR__gleInvertMatrix_AltiVec_00110e84;
  }
                    
                    
  (*(code *)_gleInvertMatrix)();
  return;
}

/* _glPopMatrix_Exec @ 0x33830 (276 bytes) */
int _glPopMatrix_Exec(param_1)
  int param_1;
{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  
  iVar7 = *(int *)(param_1 + 0x4ff4);
  if ((*(short *)(param_1 + 0x4a10) < 0) && (iVar7 < 0x18)) {
    iVar4 = iVar7 * 4 + param_1;
    iVar6 = *(int *)(iVar4 + 0x4ffc);
    if (0 < iVar6) {
      iVar6 = iVar6 + -1;
      iVar3 = *(int *)(param_1 + 0x4678);
      iVar5 = *(int *)(iVar7 * 4 + *(int *)(param_1 + 0x4ff8));
      *(int *)(iVar4 + 0x4ffc) = iVar6;
      uVar2 = ((int (*)())_gleCopyMatrix)(iVar3 + (iVar5 + iVar6) * 0x40,param_1 + iVar7 * 0x40 + 0x1bc0);
      uVar8 = *(uint *)(param_1 + 0x50a8);
      *(uint *)(param_1 + 0x50ac) = *(uint *)(param_1 + 0x50ac) | uVar8;
      if ((iVar7 == 4) && ((uVar8 & *(uint *)(param_1 + 0x505c) & 0xfffffc) != 0)) {
        uVar2 = ((int (*)())_gleCopyMatrix)(*(int *)(param_1 + 0x4678) + iVar6 * 0x40 + 0x2b00,param_1 + 0x22c0);
        uVar1 = uVar8 & 0xfffffc;
        uVar8 = uVar8 & 0xff000003;
        *(uint *)(param_1 + 0x50b0) = *(uint *)(param_1 + 0x50b0) & ~uVar1;
      }
      *(uint *)(param_1 + 0x50b0) = *(uint *)(param_1 + 0x50b0) | uVar8;
      return uVar2;
    }
    if (*(int *)(param_1 + 0x7574) != 0) {
      return param_1;
    }
    uVar2 = 0x504;
  }
  else {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return param_1;
    }
    uVar2 = 0x502;
  }
  *(undefined4 *)(param_1 + 0x7574) = uVar2;
  return param_1;
}

/* _glGenLists_Exec @ 0x33944 (188 bytes) */
int _glGenLists_Exec(param_1, param_2)
  int param_1;
  int param_2;
{
  undefined4 uVar1;
  int iVar2;
  
  if (param_2 < 0) {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return 0;
    }
    uVar1 = 0x501;
  }
  else {
    if (*(short *)(param_1 + 0x4a10) < 0) {
      iVar2 = *(int *)(param_1 + 0x5148);
      if (*(char *)(iVar2 + 0x8024) != '\0') {
        _pthread_mutex_lock(iVar2 + 0x8028);
        iVar2 = *(int *)(param_1 + 0x5148);
      }
      uVar1 = _gleGenHashNames(iVar2 + 0x300c,param_2);
      if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) != '\0') {
        _pthread_mutex_unlock(*(int *)(param_1 + 0x5148) + 0x8028);
        return uVar1;
      }
      return uVar1;
    }
    if (*(int *)(param_1 + 0x7574) != 0) {
      return 0;
    }
    uVar1 = 0x502;
  }
  *(undefined4 *)(param_1 + 0x7574) = uVar1;
  return 0;
}

/* _glNewList_Exec @ 0x33a00 (116 bytes) */
void _glNewList_Exec(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  undefined4 uVar1;
  
  if (param_2 == 0) {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar1 = 0x501;
  }
  else if (param_3 - 0x1300U < 2) {
    if ((*(int *)(param_1 + 0x5408) == 0) && (*(short *)(param_1 + 0x4a10) < 0)) {
      ((int (*)())_gleNewList)(param_1,param_2,param_3);
      return;
    }
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar1 = 0x502;
  }
  else {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar1 = 0x500;
  }
  *(undefined4 *)(param_1 + 0x7574) = uVar1;
  return;
}

/* _gleNewList @ 0x33a74 (22516 bytes) */
int _gleNewList(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  undefined *param_3;
{
  uint uVar1;
  undefined *puVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  
  puVar3 = (undefined4 *)_malloc(0x1000);
  puVar3[10] = 0;
  *(undefined4 *)(param_1 + 0x5400) = 0x2c;
  puVar2 = PTR__gleFreeDisplayListObject_00110a24;
  *(undefined4 *)(param_1 + 0x53fc) = 0x1000;
  puVar3[1] = param_2;
  puVar3[2] = 1;
  puVar3[3] = puVar2;
  *(undefined **)(param_1 + 0x5408) = param_3;
  *(undefined4 **)(param_1 + 0x53e8) = puVar3;
  *(undefined4 *)(param_1 + 0x53ec) = 0;
  *(undefined4 *)(param_1 + 0x53f0) = 0;
  *puVar3 = 0;
  puVar3[4] = 0;
  puVar3[5] = 0;
  puVar3[6] = 0;
  puVar3[7] = 0;
  puVar3[9] = 0;
  if (param_3 == ((unsigned char *)0x00001300)) {
    uVar4 = _gliCompDispatchTable(param_1);
    return uVar4;
  }
  uVar1 = -(uint)(**(int **)(param_1 + 0x4684) == 0);
  *(undefined **)(*(uint *)(param_1 + 0x4680) & uVar1 | (uint)*(int **)(param_1 + 0x4684) & ~uVar1)
       = PTR__glAccum_CompExec_00112c00;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 4) == 0);
  *(undefined **)((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 4)
       = PTR__glAlphaFunc_CompExec_00112bfc;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0xc) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0xc) =
       PTR__glArrayElement_CompExec_00112bf8;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x10) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x10) =
       PTR__glBegin_CompExec_001122e0;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x14) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x14) =
       PTR__glBindTexture_CompExec_00112bf4;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x18) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x18) =
       PTR__glBitmap_CompExec_00112bf0;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x1c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x1c) =
       PTR__glBlendFunc_CompExec_00112bec;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x20) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x20) =
       PTR__glCallList_CompExec_00112be8;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x24) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x24) =
       PTR__glCallLists_CompExec_00112be4;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x28) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x28) =
       PTR__glClear_CompExec_00112be0;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x2c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x2c) =
       PTR__glClearAccum_CompExec_00112bdc;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x30) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x30) =
       PTR__glClearColor_CompExec_00112bd8;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x34) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x34) =
       PTR__glClearDepth_CompExec_00112bd4;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x38) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x38) =
       PTR__glClearIndex_CompExec_00112bd0;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x3c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x3c) =
       PTR__glClearStencil_CompExec_00112bcc;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x40) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x40) =
       PTR__glClipPlane_CompExec_00112bc8;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x44) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x44) =
       PTR__glColor3b_CompExec_00112bc4;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x48) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x48) =
       PTR__glColor3bv_CompExec_00112bc0;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x4c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x4c) =
       PTR__glColor3d_CompExec_00112bbc;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x50) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x50) =
       PTR__glColor3dv_CompExec_00112bb8;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x54) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x54) =
       PTR__glColor3f_CompExec_00112bb4;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x58) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x58) =
       PTR__glColor3fv_CompExec_00112bb0;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x5c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x5c) =
       PTR__glColor3i_CompExec_00112bac;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x60) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x60) =
       PTR__glColor3iv_CompExec_00112ba8;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 100) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 100) =
       PTR__glColor3s_CompExec_00112ba4;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x68) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x68) =
       PTR__glColor3sv_CompExec_00112ba0;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x6c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x6c) =
       PTR__glColor3ub_CompExec_00112b9c;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x70) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x70) =
       PTR__glColor3ubv_CompExec_00112b98;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x74) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x74) =
       PTR__glColor3ui_CompExec_00112b94;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x78) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x78) =
       PTR__glColor3uiv_CompExec_00112b90;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x7c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x7c) =
       PTR__glColor3us_CompExec_00112b8c;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x80) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x80) =
       PTR__glColor3usv_CompExec_00112b88;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x84) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x84) =
       PTR__glColor4b_CompExec_00112b84;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x88) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x88) =
       PTR__glColor4bv_CompExec_00112b80;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x8c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x8c) =
       PTR__glColor4d_CompExec_00112b7c;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x90) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x90) =
       PTR__glColor4dv_CompExec_00112b78;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x94) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x94) =
       PTR__glColor4f_CompExec_00112b74;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x98) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x98) =
       PTR__glColor4fv_CompExec_00112b70;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x9c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x9c) =
       PTR__glColor4i_CompExec_00112b6c;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0xa0) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0xa0) =
       PTR__glColor4iv_CompExec_00112b68;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0xa4) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0xa4) =
       PTR__glColor4s_CompExec_00112b64;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0xa8) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0xa8) =
       PTR__glColor4sv_CompExec_00112b60;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0xac) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0xac) =
       PTR__glColor4ub_CompExec_00112b5c;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0xb0) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0xb0) =
       PTR__glColor4ubv_CompExec_00112b58;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0xb4) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0xb4) =
       PTR__glColor4ui_CompExec_00112b54;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0xb8) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0xb8) =
       PTR__glColor4uiv_CompExec_00112b50;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0xbc) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0xbc) =
       PTR__glColor4us_CompExec_00112b4c;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0xc0) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0xc0) =
       PTR__glColor4usv_CompExec_00112b48;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0xc4) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0xc4) =
       PTR__glColorMask_CompExec_00112b44;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 200) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 200) =
       PTR__glColorMaterial_CompExec_00112b40;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0xd0) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0xd0) =
       PTR__glCopyPixels_CompExec_00112b3c;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0xd4) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0xd4) =
       PTR__glCopyTexImage1D_CompExec_00112b38;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0xd8) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0xd8) =
       PTR__glCopyTexImage2D_CompExec_00112b34;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0xdc) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0xdc) =
       PTR__glCopyTexSubImage1D_CompExec_00112b30;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0xe0) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0xe0) =
       PTR__glCopyTexSubImage2D_CompExec_00112b2c;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0xe4) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0xe4) =
       PTR__glCullFace_CompExec_00112b28;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0xf0) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0xf0) =
       PTR__glDepthFunc_CompExec_00112b24;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0xf4) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0xf4) =
       PTR__glDepthMask_CompExec_00112b20;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0xf8) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0xf8) =
       PTR__glDepthRange_CompExec_00112b1c;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0xfc) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0xfc) =
       PTR__glDisable_CompExec_00112b18;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x104) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x104) =
       PTR__glDrawArrays_CompExec_00112b14;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x108) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x108) =
       PTR__glDrawBuffer_CompExec_00112b10;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x10c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x10c) =
       PTR__glDrawElements_CompExec_00112b0c;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x110) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x110) =
       PTR__glDrawPixels_CompExec_00112b08;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x114) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x114) =
       PTR__glEdgeFlag_CompExec_00112b04;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x11c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x11c) =
       PTR__glEdgeFlagv_CompExec_00112b00;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x120) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x120) =
       PTR__glEnable_CompExec_00112afc;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x128) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x128) =
       PTR__glEnd_CompExec_00112384;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x130) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x130) =
       PTR__glEvalCoord1d_CompExec_00112af8;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x134) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x134) =
       PTR__glEvalCoord1dv_CompExec_00112af4;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x138) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x138) =
       PTR__glEvalCoord1f_CompExec_00112af0;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x13c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x13c) =
       PTR__glEvalCoord1fv_CompExec_00112aec;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x140) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x140) =
       PTR__glEvalCoord2d_CompExec_00112ae8;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x144) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x144) =
       PTR__glEvalCoord2dv_CompExec_00112ae4;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x148) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x148) =
       PTR__glEvalCoord2f_CompExec_00112ae0;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x14c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x14c) =
       PTR__glEvalCoord2fv_CompExec_00112adc;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x150) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x150) =
       PTR__glEvalMesh1_CompExec_00112ad8;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x154) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x154) =
       PTR__glEvalMesh2_CompExec_00112ad4;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x158) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x158) =
       PTR__glEvalPoint1_CompExec_00112ad0;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x15c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x15c) =
       PTR__glEvalPoint2_CompExec_00112acc;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x16c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x16c) =
       PTR__glFogf_CompExec_00112ac8;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x170) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x170) =
       PTR__glFogfv_CompExec_00112ac4;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x174) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x174) =
       PTR__glFogi_CompExec_00112ac0;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x178) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x178) =
       PTR__glFogiv_CompExec_00112abc;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x17c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x17c) =
       PTR__glFrontFace_CompExec_00112ab8;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x180) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x180) =
       PTR__glFrustum_CompExec_00112ab4;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x200) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x200) =
       PTR__glHint_CompExec_00112ab0;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x204) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x204) =
       PTR__glIndexMask_CompExec_00112aac;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x20c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x20c) =
       PTR__glIndexd_CompExec_00112aa8;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x210) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x210) =
       PTR__glIndexdv_CompExec_00112aa4;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x214) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x214) =
       PTR__glIndexf_CompExec_00112aa0;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x218) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x218) =
       PTR__glIndexfv_CompExec_00112a9c;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x21c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x21c) =
       PTR__glIndexi_CompExec_00112a98;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x220) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x220) =
       PTR__glIndexiv_CompExec_00112a94;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x224) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x224) =
       PTR__glIndexs_CompExec_00112a90;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x228) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x228) =
       PTR__glIndexsv_CompExec_00112a8c;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x22c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x22c) =
       PTR__glIndexub_CompExec_00112a88;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x230) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x230) =
       PTR__glIndexubv_CompExec_00112a84;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x234) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x234) =
       PTR__glInitNames_CompExec_00112a80;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x248) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x248) =
       PTR__glLightModelf_CompExec_00112a7c;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x24c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x24c) =
       PTR__glLightModelfv_CompExec_00112a78;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x250) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x250) =
       PTR__glLightModeli_CompExec_00112a74;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x254) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x254) =
       PTR__glLightModeliv_CompExec_00112a70;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 600) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 600) =
       PTR__glLightf_CompExec_00112a6c;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x25c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x25c) =
       PTR__glLightfv_CompExec_00112a68;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x260) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x260) =
       PTR__glLighti_CompExec_00112a64;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x264) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x264) =
       PTR__glLightiv_CompExec_00112a60;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x268) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x268) =
       PTR__glLineStipple_CompExec_00112a5c;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x26c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x26c) =
       PTR__glLineWidth_CompExec_00112a58;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x270) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x270) =
       PTR__glListBase_CompExec_00112a54;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x274) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x274) =
       PTR__glLoadIdentity_CompExec_00112a50;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x278) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x278) =
       PTR__glLoadMatrixd_CompExec_00112a4c;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x27c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x27c) =
       PTR__glLoadMatrixf_CompExec_00112a48;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x280) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x280) =
       PTR__glLoadName_CompExec_00112a44;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x284) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x284) =
       PTR__glLogicOp_CompExec_00112a40;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x288) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x288) =
       PTR__glMap1d_CompExec_00112a3c;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x28c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x28c) =
       PTR__glMap1f_CompExec_00112a38;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x290) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x290) =
       PTR__glMap2d_CompExec_00112a34;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x294) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x294) =
       PTR__glMap2f_CompExec_00112a30;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x298) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x298) =
       PTR__glMapGrid1d_CompExec_00112a2c;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x29c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x29c) =
       PTR__glMapGrid1f_CompExec_00112a28;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x2a0) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x2a0) =
       PTR__glMapGrid2d_CompExec_00112a24;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x2a4) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x2a4) =
       PTR__glMapGrid2f_CompExec_00112a20;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x2a8) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x2a8) =
       PTR__glMaterialf_CompExec_00112a1c;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x2ac) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x2ac) =
       PTR__glMaterialfv_CompExec_00112a18;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x2b0) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x2b0) =
       PTR__glMateriali_CompExec_00112a14;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x2b4) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x2b4) =
       PTR__glMaterialiv_CompExec_00112a10;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x2b8) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x2b8) =
       PTR__glMatrixMode_CompExec_00112a0c;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 700) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 700) =
       PTR__glMultMatrixd_CompExec_00112a08;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x2c0) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x2c0) =
       PTR__glMultMatrixf_CompExec_00112a04;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x2c8) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x2c8) =
       PTR__glNormal3b_CompExec_00112a00;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x2cc) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x2cc) =
       PTR__glNormal3bv_CompExec_001129fc;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x2d0) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x2d0) =
       PTR__glNormal3d_CompExec_001129f8;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x2d4) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x2d4) =
       PTR__glNormal3dv_CompExec_001129f4;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x2d8) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x2d8) =
       PTR__glNormal3f_CompExec_001129f0;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x2dc) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x2dc) =
       PTR__glNormal3fv_CompExec_001129ec;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x2e0) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x2e0) =
       PTR__glNormal3i_CompExec_001129e8;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x2e4) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x2e4) =
       PTR__glNormal3iv_CompExec_001129e4;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x2e8) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x2e8) =
       PTR__glNormal3s_CompExec_001129e0;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x2ec) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x2ec) =
       PTR__glNormal3sv_CompExec_001129dc;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x2f4) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x2f4) =
       PTR__glOrtho_CompExec_001129d8;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x2f8) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x2f8) =
       PTR__glPassThrough_CompExec_001129d4;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x2fc) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x2fc) =
       PTR__glPixelMapfv_CompExec_001129d0;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x300) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x300) =
       PTR__glPixelMapuiv_CompExec_001129cc;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x304) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x304) =
       PTR__glPixelMapusv_CompExec_001129c8;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x310) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x310) =
       PTR__glPixelTransferf_CompExec_001129c4;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x314) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x314) =
       PTR__glPixelTransferi_CompExec_001129c0;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x318) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x318) =
       PTR__glPixelZoom_CompExec_001129bc;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x31c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x31c) =
       PTR__glPointSize_CompExec_001129b8;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 800) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 800) =
       PTR__glPolygonMode_CompExec_001129b4;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x324) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x324) =
       PTR__glPolygonOffset_CompExec_001129b0;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x328) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x328) =
       PTR__glPolygonStipple_CompExec_001129ac;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x32c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x32c) =
       PTR__glPopAttrib_CompExec_001129a8;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x334) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x334) =
       PTR__glPopMatrix_CompExec_001129a4;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x338) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x338) =
       PTR__glPopName_CompExec_001129a0;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x33c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x33c) =
       PTR__glPrioritizeTextures_CompExec_0011299c;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x340) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x340) =
       PTR__glPushAttrib_CompExec_00112998;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x348) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x348) =
       PTR__glPushMatrix_CompExec_00112994;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x34c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x34c) =
       PTR__glPushName_CompExec_00112990;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x350) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x350) =
       PTR__glRasterPos2d_CompExec_0011298c;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x354) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x354) =
       PTR__glRasterPos2dv_CompExec_00112988;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x358) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x358) =
       PTR__glRasterPos2f_CompExec_00112984;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x35c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x35c) =
       PTR__glRasterPos2fv_CompExec_00112980;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x360) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x360) =
       PTR__glRasterPos2i_CompExec_0011297c;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x364) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x364) =
       PTR__glRasterPos2iv_CompExec_00112978;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x368) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x368) =
       PTR__glRasterPos2s_CompExec_00112974;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x36c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x36c) =
       PTR__glRasterPos2sv_CompExec_00112970;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x370) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x370) =
       PTR__glRasterPos3d_CompExec_0011296c;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x374) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x374) =
       PTR__glRasterPos3dv_CompExec_00112968;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x378) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x378) =
       PTR__glRasterPos3f_CompExec_00112964;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x37c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x37c) =
       PTR__glRasterPos3fv_CompExec_00112960;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x380) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x380) =
       PTR__glRasterPos3i_CompExec_0011295c;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 900) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 900) =
       PTR__glRasterPos3iv_CompExec_00112958;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x388) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x388) =
       PTR__glRasterPos3s_CompExec_00112954;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x38c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x38c) =
       PTR__glRasterPos3sv_CompExec_00112950;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x390) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x390) =
       PTR__glRasterPos4d_CompExec_0011294c;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x394) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x394) =
       PTR__glRasterPos4dv_CompExec_00112948;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x398) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x398) =
       PTR__glRasterPos4f_CompExec_00112944;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x39c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x39c) =
       PTR__glRasterPos4fv_CompExec_00112940;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x3a0) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x3a0) =
       PTR__glRasterPos4i_CompExec_0011293c;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x3a4) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x3a4) =
       PTR__glRasterPos4iv_CompExec_00112938;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x3a8) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x3a8) =
       PTR__glRasterPos4s_CompExec_00112934;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x3ac) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x3ac) =
       PTR__glRasterPos4sv_CompExec_00112930;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x3b0) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x3b0) =
       PTR__glReadBuffer_CompExec_0011292c;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x3b8) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x3b8) =
       PTR__glRectd_CompExec_00112928;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x3bc) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x3bc) =
       PTR__glRectdv_CompExec_00112924;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x3c0) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x3c0) =
       PTR__glRectf_CompExec_00112920;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x3c4) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x3c4) =
       PTR__glRectfv_CompExec_0011291c;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x3c8) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x3c8) =
       PTR__glRecti_CompExec_00112918;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x3cc) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x3cc) =
       PTR__glRectiv_CompExec_00112914;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x3d0) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x3d0) =
       PTR__glRects_CompExec_00112910;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x3d4) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x3d4) =
       PTR__glRectsv_CompExec_0011290c;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x3dc) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x3dc) =
       PTR__glRotated_CompExec_00112908;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x3e0) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x3e0) =
       PTR__glRotatef_CompExec_00112904;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x3e4) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x3e4) =
       PTR__glScaled_CompExec_00112900;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 1000) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 1000) =
       PTR__glScalef_CompExec_001128fc;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x3ec) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x3ec) =
       PTR__glScissor_CompExec_001128f8;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x3f4) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x3f4) =
       PTR__glShadeModel_CompExec_001128f4;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x3f8) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x3f8) =
       PTR__glStencilFunc_CompExec_001128f0;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x3fc) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x3fc) =
       PTR__glStencilMask_CompExec_001128ec;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x400) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x400) =
       PTR__glStencilOp_CompExec_001128e8;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x404) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x404) =
       PTR__glTexCoord1d_CompExec_001128e4;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x408) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x408) =
       PTR__glTexCoord1dv_CompExec_001128e0;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x40c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x40c) =
       PTR__glTexCoord1f_CompExec_001128dc;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x410) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x410) =
       PTR__glTexCoord1fv_CompExec_001128d8;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x414) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x414) =
       PTR__glTexCoord1i_CompExec_001128d4;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x418) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x418) =
       PTR__glTexCoord1iv_CompExec_001128d0;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x41c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x41c) =
       PTR__glTexCoord1s_CompExec_001128cc;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x420) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x420) =
       PTR__glTexCoord1sv_CompExec_001128c8;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x424) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x424) =
       PTR__glTexCoord2d_CompExec_001128c4;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x428) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x428) =
       PTR__glTexCoord2dv_CompExec_001128c0;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x42c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x42c) =
       PTR__glTexCoord2f_CompExec_001128bc;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x430) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x430) =
       PTR__glTexCoord2fv_CompExec_001128b8;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x434) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x434) =
       PTR__glTexCoord2i_CompExec_001128b4;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x438) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x438) =
       PTR__glTexCoord2iv_CompExec_001128b0;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x43c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x43c) =
       PTR__glTexCoord2s_CompExec_001128ac;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x440) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x440) =
       PTR__glTexCoord2sv_CompExec_001128a8;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x444) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x444) =
       PTR__glTexCoord3d_CompExec_001128a4;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x448) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x448) =
       PTR__glTexCoord3dv_CompExec_001128a0;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x44c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x44c) =
       PTR__glTexCoord3f_CompExec_0011289c;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x450) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x450) =
       PTR__glTexCoord3fv_CompExec_00112898;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x454) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x454) =
       PTR__glTexCoord3i_CompExec_00112894;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x458) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x458) =
       PTR__glTexCoord3iv_CompExec_00112890;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x45c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x45c) =
       PTR__glTexCoord3s_CompExec_0011288c;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x460) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x460) =
       PTR__glTexCoord3sv_CompExec_00112888;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x464) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x464) =
       PTR__glTexCoord4d_CompExec_00112884;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x468) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x468) =
       PTR__glTexCoord4dv_CompExec_00112880;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x46c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x46c) =
       PTR__glTexCoord4f_CompExec_0011287c;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x470) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x470) =
       PTR__glTexCoord4fv_CompExec_00112878;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x474) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x474) =
       PTR__glTexCoord4i_CompExec_00112874;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x478) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x478) =
       PTR__glTexCoord4iv_CompExec_00112870;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x47c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x47c) =
       PTR__glTexCoord4s_CompExec_0011286c;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x480) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x480) =
       PTR__glTexCoord4sv_CompExec_00112868;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x488) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x488) =
       PTR__glTexEnvf_CompExec_00112864;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x48c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x48c) =
       PTR__glTexEnvfv_CompExec_00112860;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x490) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x490) =
       PTR__glTexEnvi_CompExec_0011285c;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x494) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x494) =
       PTR__glTexEnviv_CompExec_00112858;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x498) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x498) =
       PTR__glTexGend_CompExec_00112854;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x49c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x49c) =
       PTR__glTexGendv_CompExec_00112850;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x4a0) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x4a0) =
       PTR__glTexGenf_CompExec_0011284c;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x4a4) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x4a4) =
       PTR__glTexGenfv_CompExec_00112848;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x4a8) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x4a8) =
       PTR__glTexGeni_CompExec_00112844;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x4ac) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x4ac) =
       PTR__glTexGeniv_CompExec_00112840;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x4b0) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x4b0) =
       PTR__glTexImage1D_CompExec_0011283c;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x4b4) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x4b4) =
       PTR__glTexImage2D_CompExec_00112838;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x4b8) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x4b8) =
       PTR__glTexParameterf_CompExec_00112834;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x4bc) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x4bc) =
       PTR__glTexParameterfv_CompExec_00112830;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x4c0) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x4c0) =
       PTR__glTexParameteri_CompExec_0011282c;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x4c4) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x4c4) =
       PTR__glTexParameteriv_CompExec_00112828;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x4c8) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x4c8) =
       PTR__glTexSubImage1D_CompExec_00112824;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x4cc) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x4cc) =
       PTR__glTexSubImage2D_CompExec_00112820;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x4d0) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x4d0) =
       PTR__glTranslated_CompExec_0011281c;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x4d4) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x4d4) =
       PTR__glTranslatef_CompExec_00112818;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x4d8) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x4d8) =
       PTR__glVertex2d_CompExec_00112814;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x4dc) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x4dc) =
       PTR__glVertex2dv_CompExec_00112810;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x4e0) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x4e0) =
       PTR__glVertex2f_CompExec_0011280c;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x4e4) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x4e4) =
       PTR__glVertex2fv_CompExec_00112808;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x4e8) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x4e8) =
       PTR__glVertex2i_CompExec_00112804;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x4ec) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x4ec) =
       PTR__glVertex2iv_CompExec_00112800;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x4f0) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x4f0) =
       PTR__glVertex2s_CompExec_001127fc;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x4f4) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x4f4) =
       PTR__glVertex2sv_CompExec_001127f8;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x4f8) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x4f8) =
       PTR__glVertex3d_CompExec_001127f4;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x4fc) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x4fc) =
       PTR__glVertex3dv_CompExec_001127f0;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x500) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x500) =
       PTR__glVertex3f_CompExec_001127ec;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x504) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x504) =
       PTR__glVertex3fv_CompExec_001127e8;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x508) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x508) =
       PTR__glVertex3i_CompExec_001127e4;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x50c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x50c) =
       PTR__glVertex3iv_CompExec_001127e0;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x510) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x510) =
       PTR__glVertex3s_CompExec_001127dc;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x514) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x514) =
       PTR__glVertex3sv_CompExec_001127d8;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x518) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x518) =
       PTR__glVertex4d_CompExec_001127d4;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x51c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x51c) =
       PTR__glVertex4dv_CompExec_001127d0;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x520) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x520) =
       PTR__glVertex4f_CompExec_001127cc;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x524) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x524) =
       PTR__glVertex4fv_CompExec_001127c8;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x528) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x528) =
       PTR__glVertex4i_CompExec_001127c4;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x52c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x52c) =
       PTR__glVertex4iv_CompExec_001127c0;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x530) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x530) =
       PTR__glVertex4s_CompExec_001127bc;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x534) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x534) =
       PTR__glVertex4sv_CompExec_001127b8;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x53c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x53c) =
       PTR__glViewport_CompExec_001127b4;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x544) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x544) =
       PTR__glBlendColor_CompExec_001127b0;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x548) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x548) =
       PTR__glBlendEquation_CompExec_001127ac;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x558) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x558) =
       PTR__glActiveTexture_CompExec_001127a8;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x55c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x55c) =
       PTR__glMultiTexCoord1d_CompExec_001127a4;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x560) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x560) =
       PTR__glMultiTexCoord1dv_CompExec_001127a0;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x564) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x564) =
       PTR__glMultiTexCoord1f_CompExec_0011279c;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x568) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x568) =
       PTR__glMultiTexCoord1fv_CompExec_00112798;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x56c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x56c) =
       PTR__glMultiTexCoord1i_CompExec_00112794;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x570) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x570) =
       PTR__glMultiTexCoord1iv_CompExec_00112790;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x574) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x574) =
       PTR__glMultiTexCoord1s_CompExec_0011278c;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x578) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x578) =
       PTR__glMultiTexCoord1sv_CompExec_00112788;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x57c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x57c) =
       PTR__glMultiTexCoord2d_CompExec_00112784;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x580) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x580) =
       PTR__glMultiTexCoord2dv_CompExec_00112780;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x584) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x584) =
       PTR__glMultiTexCoord2f_CompExec_0011277c;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x588) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x588) =
       PTR__glMultiTexCoord2fv_CompExec_00112778;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x58c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x58c) =
       PTR__glMultiTexCoord2i_CompExec_00112774;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x590) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x590) =
       PTR__glMultiTexCoord2iv_CompExec_00112770;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x594) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x594) =
       PTR__glMultiTexCoord2s_CompExec_0011276c;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x598) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x598) =
       PTR__glMultiTexCoord2sv_CompExec_00112768;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x59c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x59c) =
       PTR__glMultiTexCoord3d_CompExec_00112764;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x5a0) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x5a0) =
       PTR__glMultiTexCoord3dv_CompExec_00112760;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x5a4) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x5a4) =
       PTR__glMultiTexCoord3f_CompExec_0011275c;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x5a8) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x5a8) =
       PTR__glMultiTexCoord3fv_CompExec_00112758;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x5ac) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x5ac) =
       PTR__glMultiTexCoord3i_CompExec_00112754;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x5b0) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x5b0) =
       PTR__glMultiTexCoord3iv_CompExec_00112750;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x5b4) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x5b4) =
       PTR__glMultiTexCoord3s_CompExec_0011274c;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x5b8) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x5b8) =
       PTR__glMultiTexCoord3sv_CompExec_00112748;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x5bc) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x5bc) =
       PTR__glMultiTexCoord4d_CompExec_00112744;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x5c0) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x5c0) =
       PTR__glMultiTexCoord4dv_CompExec_00112740;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x5c4) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x5c4) =
       PTR__glMultiTexCoord4f_CompExec_0011273c;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x5c8) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x5c8) =
       PTR__glMultiTexCoord4fv_CompExec_00112738;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x5cc) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x5cc) =
       PTR__glMultiTexCoord4i_CompExec_00112734;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x5d0) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x5d0) =
       PTR__glMultiTexCoord4iv_CompExec_00112730;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x5d4) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x5d4) =
       PTR__glMultiTexCoord4s_CompExec_0011272c;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x5d8) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x5d8) =
       PTR__glMultiTexCoord4sv_CompExec_00112728;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x5dc) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x5dc) =
       PTR__glLoadTransposeMatrixd_CompExec_00112724;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x5e0) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x5e0) =
       PTR__glLoadTransposeMatrixf_CompExec_00112720;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x5e4) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x5e4) =
       PTR__glMultTransposeMatrixd_CompExec_0011271c;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x5e8) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x5e8) =
       PTR__glMultTransposeMatrixf_CompExec_00112718;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x654) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x654) =
       PTR__glDrawRangeElements_CompExec_00112714;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x6d8) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x6d8) =
       PTR__glTexImage3D_CompExec_00112710;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x6dc) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x6dc) =
       PTR__glTexSubImage3D_CompExec_0011270c;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x6e0) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x6e0) =
       PTR__glCopyTexSubImage3D_CompExec_00112708;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x658) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x658) =
       PTR__glColorTable_CompExec_00112704;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x65c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x65c) =
       PTR__glColorTableParameterfv_CompExec_00112700;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x660) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x660) =
       PTR__glColorTableParameteriv_CompExec_001126fc;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x664) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x664) =
       PTR__glCopyColorTable_CompExec_001126f8;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x674) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x674) =
       PTR__glColorSubTable_CompExec_001126f4;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x678) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x678) =
       PTR__glCopyColorSubTable_CompExec_001126f0;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x67c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x67c) =
       PTR__glConvolutionFilter1D_CompExec_001126ec;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x680) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x680) =
       PTR__glConvolutionFilter2D_CompExec_001126e8;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x684) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x684) =
       PTR__glConvolutionParameterf_CompExec_001126e4;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x688) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x688) =
       PTR__glConvolutionParameterfv_CompExec_001126e0;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x68c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x68c) =
       PTR__glConvolutionParameteri_CompExec_001126dc;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x690) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x690) =
       PTR__glConvolutionParameteriv_CompExec_001126d8;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x694) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x694) =
       PTR__glCopyConvolutionFilter1D_CompExec_001126d4;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x698) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x698) =
       PTR__glCopyConvolutionFilter2D_CompExec_001126d0;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x6ac) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x6ac) =
       PTR__glSeparableFilter2D_CompExec_001126cc;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x6c8) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x6c8) =
       PTR__glHistogram_CompExec_001126c8;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x6cc) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x6cc) =
       PTR__glMinmax_CompExec_001126c4;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x6d0) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x6d0) =
       PTR__glResetHistogram_CompExec_001126c0;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x6d4) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x6d4) =
       PTR__glResetMinmax_CompExec_001126bc;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x5ec) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x5ec) =
       PTR__glCompressedTexImage3D_CompExec_001126b8;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x5f0) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x5f0) =
       PTR__glCompressedTexImage2D_CompExec_001126b4;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x5f4) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x5f4) =
       PTR__glCompressedTexImage1D_CompExec_001126b0;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x5f8) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x5f8) =
       PTR__glCompressedTexSubImage3D_CompExec_001126ac;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x5fc) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x5fc) =
       PTR__glCompressedTexSubImage2D_CompExec_001126a8;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x600) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x600) =
       PTR__glCompressedTexSubImage1D_CompExec_001126a4;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x608) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x608) =
       PTR__glSecondaryColor3b_CompExec_001126a0;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x60c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x60c) =
       PTR__glSecondaryColor3bv_CompExec_0011269c;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x610) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x610) =
       PTR__glSecondaryColor3d_CompExec_00112698;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x614) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x614) =
       PTR__glSecondaryColor3dv_CompExec_00112694;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x618) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x618) =
       PTR__glSecondaryColor3f_CompExec_00112690;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x61c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x61c) =
       PTR__glSecondaryColor3fv_CompExec_0011268c;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x620) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x620) =
       PTR__glSecondaryColor3i_CompExec_00112688;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x624) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x624) =
       PTR__glSecondaryColor3iv_CompExec_00112684;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x628) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x628) =
       PTR__glSecondaryColor3s_CompExec_00112680;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x62c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x62c) =
       PTR__glSecondaryColor3sv_CompExec_0011267c;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x630) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x630) =
       PTR__glSecondaryColor3ub_CompExec_00112678;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x634) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x634) =
       PTR__glSecondaryColor3ubv_CompExec_00112674;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x638) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x638) =
       PTR__glSecondaryColor3ui_CompExec_00112670;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x63c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x63c) =
       PTR__glSecondaryColor3uiv_CompExec_0011266c;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x640) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x640) =
       PTR__glSecondaryColor3us_CompExec_00112668;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x644) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x644) =
       PTR__glSecondaryColor3usv_CompExec_00112664;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x72c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x72c) =
       PTR__glSampleCoverage_CompExec_00112660;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x730) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x730) =
       PTR__glSamplePass_CompExec_0011265c;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x8e4) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x8e4) =
       PTR__glWindowPos2d_CompExec_00112658;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x8e8) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x8e8) =
       PTR__glWindowPos2dv_CompExec_00112654;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x8ec) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x8ec) =
       PTR__glWindowPos2f_CompExec_00112650;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x8f0) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x8f0) =
       PTR__glWindowPos2fv_CompExec_0011264c;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x8f4) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x8f4) =
       PTR__glWindowPos2i_CompExec_00112648;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x8f8) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x8f8) =
       PTR__glWindowPos2iv_CompExec_00112644;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x8fc) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x8fc) =
       PTR__glWindowPos2s_CompExec_00112640;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x900) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x900) =
       PTR__glWindowPos2sv_CompExec_0011263c;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x904) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x904) =
       PTR__glWindowPos3d_CompExec_00112638;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x908) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x908) =
       PTR__glWindowPos3dv_CompExec_00112634;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x90c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x90c) =
       PTR__glWindowPos3f_CompExec_00112630;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x910) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x910) =
       PTR__glWindowPos3fv_CompExec_0011262c;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x914) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x914) =
       PTR__glWindowPos3i_CompExec_00112628;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x918) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x918) =
       PTR__glWindowPos3iv_CompExec_00112624;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x91c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x91c) =
       PTR__glWindowPos3s_CompExec_00112620;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x920) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x920) =
       PTR__glWindowPos3sv_CompExec_0011261c;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x894) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x894) =
       PTR__glVertexArrayParameteriEXT_CompExec_00112618;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x6e4) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x6e4) =
       PTR__glCombinerParameterfvNV_CompExec_00112614;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x6e8) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x6e8) =
       PTR__glCombinerParameterfNV_CompExec_00112610;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x6ec) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x6ec) =
       PTR__glCombinerParameterivNV_CompExec_0011260c;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x6f0) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x6f0) =
       PTR__glCombinerParameteriNV_CompExec_00112608;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x6f4) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x6f4) =
       PTR__glCombinerInputNV_CompExec_00112604;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x6f8) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x6f8) =
       PTR__glCombinerOutputNV_CompExec_00112600;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x6fc) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x6fc) =
       PTR__glFinalCombinerInputNV_CompExec_001125fc;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x718) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x718) =
       PTR__glCombinerStageParameterfvNV_CompExec_001125f8;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x738) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x738) =
       PTR__glPNTrianglesfATIX_CompExec_001125f4;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x734) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x734) =
       PTR__glPNTrianglesiATIX_CompExec_001125f0;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x75c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x75c) =
       PTR__glBindProgramARB_CompExec_001125ec;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x76c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x76c) =
       PTR__glVertexAttrib1sARB_CompExec_001125e8;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x770) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x770) =
       PTR__glVertexAttrib1fARB_CompExec_001125e4;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x774) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x774) =
       PTR__glVertexAttrib1dARB_CompExec_001125e0;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x778) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x778) =
       PTR__glVertexAttrib2sARB_CompExec_001125dc;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x77c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x77c) =
       PTR__glVertexAttrib2fARB_CompExec_001125d8;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x780) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x780) =
       PTR__glVertexAttrib2dARB_CompExec_001125d4;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x784) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x784) =
       PTR__glVertexAttrib3sARB_CompExec_001125d0;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x788) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x788) =
       PTR__glVertexAttrib3fARB_CompExec_001125cc;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x78c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x78c) =
       PTR__glVertexAttrib3dARB_CompExec_001125c8;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x790) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x790) =
       PTR__glVertexAttrib4sARB_CompExec_001125c4;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x794) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x794) =
       PTR__glVertexAttrib4fARB_CompExec_001125c0;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x798) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x798) =
       PTR__glVertexAttrib4dARB_CompExec_001125bc;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x79c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x79c) =
       PTR__glVertexAttrib4NubARB_CompExec_001125b8;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x7a0) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x7a0) =
       PTR__glVertexAttrib1svARB_CompExec_001125b4;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x7a4) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x7a4) =
       PTR__glVertexAttrib1fvARB_CompExec_001125b0;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x7a8) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x7a8) =
       PTR__glVertexAttrib1dvARB_CompExec_001125ac;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x7ac) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x7ac) =
       PTR__glVertexAttrib2svARB_CompExec_001125a8;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x7b0) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x7b0) =
       PTR__glVertexAttrib2fvARB_CompExec_001125a4;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x7b4) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x7b4) =
       PTR__glVertexAttrib2dvARB_CompExec_001125a0;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x7b8) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x7b8) =
       PTR__glVertexAttrib3svARB_CompExec_0011259c;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x7bc) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x7bc) =
       PTR__glVertexAttrib3fvARB_CompExec_00112598;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x7c0) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x7c0) =
       PTR__glVertexAttrib3dvARB_CompExec_00112594;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x7c4) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x7c4) =
       PTR__glVertexAttrib4bvARB_CompExec_00112590;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x7c8) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x7c8) =
       PTR__glVertexAttrib4svARB_CompExec_0011258c;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x7cc) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x7cc) =
       PTR__glVertexAttrib4ivARB_CompExec_00112588;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 2000) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 2000) =
       PTR__glVertexAttrib4ubvARB_CompExec_00112584;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x7d4) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x7d4) =
       PTR__glVertexAttrib4usvARB_CompExec_00112580;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x7d8) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x7d8) =
       PTR__glVertexAttrib4uivARB_CompExec_0011257c;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x7dc) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x7dc) =
       PTR__glVertexAttrib4fvARB_CompExec_00112578;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x7e0) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x7e0) =
       PTR__glVertexAttrib4dvARB_CompExec_00112574;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x7e4) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x7e4) =
       PTR__glVertexAttrib4NbvARB_CompExec_00112570;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x7e8) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x7e8) =
       PTR__glVertexAttrib4NsvARB_CompExec_0011256c;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x7ec) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x7ec) =
       PTR__glVertexAttrib4NivARB_CompExec_00112568;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x7f0) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x7f0) =
       PTR__glVertexAttrib4NubvARB_CompExec_00112564;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x7f4) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x7f4) =
       PTR__glVertexAttrib4NusvARB_CompExec_00112560;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x7f8) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x7f8) =
       PTR__glVertexAttrib4NuivARB_CompExec_0011255c;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x818) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x818) =
       PTR__glProgramEnvParameter4dARB_CompExec_00112558;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x81c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x81c) =
       PTR__glProgramEnvParameter4dvARB_CompExec_00112554;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x820) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x820) =
       PTR__glProgramEnvParameter4fARB_CompExec_00112550;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x824) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x824) =
       PTR__glProgramEnvParameter4fvARB_CompExec_0011254c;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x828) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x828) =
       PTR__glProgramLocalParameter4dARB_CompExec_00112548;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x82c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x82c) =
       PTR__glProgramLocalParameter4dvARB_CompExec_00112544;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x830) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x830) =
       PTR__glProgramLocalParameter4fARB_CompExec_00112540;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x834) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x834) =
       PTR__glProgramLocalParameter4fvARB_CompExec_0011253c;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x848) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x848) =
       PTR__glProgramStringARB_CompExec_00112538;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x854) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x854) =
       PTR__glEnableVertexAttribARB_CompExec_00112534;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x858) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x858) =
       PTR__glDisableVertexAttribARB_CompExec_00112530;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x860) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x860) =
       PTR__glMapVertexAttrib1dARB_CompExec_0011252c;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x864) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x864) =
       PTR__glMapVertexAttrib1fARB_CompExec_00112528;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x868) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x868) =
       PTR__glMapVertexAttrib2dARB_CompExec_00112524;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x86c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x86c) =
       PTR__glMapVertexAttrib2fARB_CompExec_00112520;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x744) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x744) =
       PTR__glSetFenceAPPLE_CompExec_0011251c;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x750) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x750) =
       PTR__glFinishFenceAPPLE_CompExec_00112518;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x758) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x758) =
       PTR__glFinishObjectAPPLE_CompExec_00112514;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x870) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x870) =
       PTR__glPointParameterf_CompExec_00112510;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x874) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x874) =
       PTR__glPointParameterfv_CompExec_0011250c;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x878) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x878) =
       PTR__glPointParameteriARB_CompExec_00112508;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x87c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x87c) =
       PTR__glPointParameterivARB_CompExec_00112504;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x880) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x880) =
       PTR__glFogCoordf_CompExec_00112500;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x884) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x884) =
       PTR__glFogCoordfv_CompExec_001124fc;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x888) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x888) =
       PTR__glFogCoordd_CompExec_001124f8;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x88c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x88c) =
       PTR__glFogCoorddv_CompExec_001124f4;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x898) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x898) =
       PTR__glBindVertexArrayEXT_CompExec_001124f0;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x8ac) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x8ac) =
       PTR__glDrawElementArrayAPPLE_CompExec_001124ec;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x8b0) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x8b0) =
       PTR__glDrawRangeElementArrayAPPLE_CompExec_001124e8;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0xa60) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0xa60) =
       PTR__glMultiDrawRangeElementArrayAPPLE_CompExec_001124e4;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0xa5c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0xa5c) =
       PTR__glMultiDrawElementArrayAPPLE_CompExec_001124e0;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x540) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x540) =
       PTR__glBlendFuncSeparate_CompExec_001124dc;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x728) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x728) =
       PTR__glBlendEquationSeparateEXT_CompExec_001124d8;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x8dc) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x8dc) =
       PTR__glMultiDrawArrays_CompExec_001124d4;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x8e0) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x8e0) =
       PTR__glMultiDrawElements_CompExec_001124d0;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x8b4) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x8b4) =
       PTR__glWeightbvARB_CompExec_001124cc;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x8b8) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x8b8) =
       PTR__glWeightsvARB_CompExec_001124c8;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x8bc) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x8bc) =
       PTR__glWeightivARB_CompExec_001124c4;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x8c0) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x8c0) =
       PTR__glWeightfvARB_CompExec_001124c0;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x8c4) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x8c4) =
       PTR__glWeightdvARB_CompExec_001124bc;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x8c8) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x8c8) =
       PTR__glWeightubvARB_CompExec_001124b8;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x8cc) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x8cc) =
       PTR__glWeightusvARB_CompExec_001124b4;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x8d0) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x8d0) =
       PTR__glWeightuivARB_CompExec_001124b0;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x8d8) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x8d8) =
       PTR__glVertexBlendARB_CompExec_001124ac;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x924) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x924) =
       PTR__glActiveStencilFace_CompExec_001124a8;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x928) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x928) =
       PTR__glStencilOpSeparateATI_CompExec_001124a4;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x92c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x92c) =
       PTR__glStencilFuncSeparateATI_CompExec_001124a0;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x960) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x960) =
       PTR__glUseProgramObjectARB_CompExec_0011249c;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x968) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x968) =
       PTR__glUniform1fARB_CompExec_00112498;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x96c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x96c) =
       PTR__glUniform2fARB_CompExec_00112494;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x970) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x970) =
       PTR__glUniform3fARB_CompExec_00112490;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x974) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x974) =
       PTR__glUniform4fARB_CompExec_0011248c;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x978) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x978) =
       PTR__glUniform1iARB_CompExec_00112488;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x97c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x97c) =
       PTR__glUniform2iARB_CompExec_00112484;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x980) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x980) =
       PTR__glUniform3iARB_CompExec_00112480;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x984) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x984) =
       PTR__glUniform4iARB_CompExec_0011247c;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x988) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x988) =
       PTR__glUniform1fvARB_CompExec_00112478;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x98c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x98c) =
       PTR__glUniform2fvARB_CompExec_00112474;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x990) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x990) =
       PTR__glUniform3fvARB_CompExec_00112470;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x994) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x994) =
       PTR__glUniform4fvARB_CompExec_0011246c;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x998) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x998) =
       PTR__glUniform1ivARB_CompExec_00112468;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x99c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x99c) =
       PTR__glUniform2ivARB_CompExec_00112464;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x9a0) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x9a0) =
       PTR__glUniform3ivARB_CompExec_00112460;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x9a4) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x9a4) =
       PTR__glUniform4ivARB_CompExec_0011245c;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x9a8) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x9a8) =
       PTR__glUniformMatrix2fvARB_CompExec_00112458;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x9ac) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x9ac) =
       PTR__glUniformMatrix3fvARB_CompExec_00112454;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x9b0) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x9b0) =
       PTR__glUniformMatrix4fvARB_CompExec_00112450;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x9f4) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x9f4) =
       PTR__glBeginQuery_CompExec_0011244c;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x9f8) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x9f8) =
       PTR__glEndQuery_CompExec_00112448;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0xa34) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0xa34) =
       PTR__glDepthBoundsEXT_CompExec_00112444;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0xa38) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0xa38) =
       PTR__glDrawBuffersARB_CompExec_00112440;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0xa3c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0xa3c) =
       PTR__glIsShader_Exec_00113b9c;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0xa40) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0xa40) =
       PTR__glIsProgram_Exec_00113b98;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0xa44) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0xa44) =
       PTR__glGetShaderiv_Exec_00113b94;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0xa48) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0xa48) =
       PTR__glGetProgramiv_Exec_00113b90;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0xa4c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0xa4c) =
       PTR__glGetShaderInfoLog_Exec_00113b8c;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0xa50) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0xa50) =
       PTR__glGetProgramInfoLog_Exec_00113b88;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0xa54) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0xa54) =
       PTR__glStencilFuncSeparate_CompExec_0011243c;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0xa58) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0xa58) =
       PTR__glStencilMaskSeparate_CompExec_00112438;
  return param_1;
}

/* _glCullFace_CompExec @ 0x39268 (56 bytes) */
void _glCullFace_CompExec(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  ((int (*)())_glCullFace_Comp)(param_1,param_2);
  ((void (*)())_glCullFace_Exec)(param_1,param_2);
  return;
}

/* _glCullFace_Comp @ 0x392a0 (76 bytes) */
int _glCullFace_Comp(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)((int (*)())_gleAddListItem)(param_1,PTR__glCullFace_ListExec_00110084,4);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_2;
  }
  return puVar1;
}

/* _gleAddListItem @ 0x392ec (292 bytes) */
int _gleAddListItem(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  int param_3;
{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  
  uVar5 = param_3 + 4;
  iVar1 = *(int *)(param_1 + 0x5400);
  if ((uint)(*(int *)(param_1 + 0x53fc) - iVar1) < uVar5) {
    uVar3 = iVar1 + uVar5;
    if ((0x2000000 < uVar3) && (uVar3 = 0x2000000, 0x1ffffff < uVar5)) {
      uVar3 = param_3 + 0x24;
    }
    iVar2 = _realloc(*(undefined4 *)(param_1 + 0x53e8),iVar1 + uVar3);
    *(int *)(param_1 + 0x53e8) = iVar2;
    if (iVar2 != 0) {
      *(uint *)(param_1 + 0x53fc) = iVar1 + uVar3;
      goto LAB_00039364;
    }
LAB_000393a0:
    if (*(int *)(param_1 + 0x7574) == 0) {
      *(undefined4 *)(param_1 + 0x7574) = 0x505;
    }
    iVar1 = 0;
  }
  else {
LAB_00039364:
    iVar2 = *(int *)(param_1 + 0x53e8);
    piVar6 = (int *)(iVar2 + 0x10);
    iVar1 = iVar2;
    if (*(uint *)(iVar2 + 0x18) <= *(int *)(iVar2 + 0x10) + 1U) {
      iVar4 = *(uint *)(iVar2 + 0x18) * 2 + 2;
      iVar1 = _realloc(*(undefined4 *)(iVar2 + 0x14),iVar4 * 4);
      *(int *)(iVar2 + 0x14) = iVar1;
      if (iVar1 == 0) goto LAB_000393a0;
      *(int *)(iVar2 + 0x18) = iVar4;
      iVar1 = *(int *)(param_1 + 0x53e8);
    }
    iVar4 = *(int *)(param_1 + 0x5400);
    *(undefined4 *)(iVar1 + iVar4) = param_2;
    iVar1 = iVar1 + iVar4 + 4;
    *(uint *)(*piVar6 * 4 + *(int *)(iVar2 + 0x14)) = uVar5;
    *piVar6 = *piVar6 + 1;
    *(uint *)(param_1 + 0x5400) = *(int *)(param_1 + 0x5400) + uVar5;
  }
  return iVar1;
}

/* _glCullFace_Exec @ 0x39410 (156 bytes) */
void _glCullFace_Exec(param_1, param_2)
  int param_1;
  uint param_2;
{
  if (-1 < *(short *)(param_1 + 0x4a10)) {
    if (*(int *)(param_1 + 0x7574) == 0) {
      *(undefined4 *)(param_1 + 0x7574) = 0x502;
    }
    return;
  }
  if (((param_2 < 0x404) || ((0x405 < param_2 && (param_2 != 0x408)))) &&
     (*(int *)(param_1 + 0x7574) == 0)) {
    *(undefined4 *)(param_1 + 0x7574) = 0x500;
  }
  *(short *)(param_1 + 0x34d6) = (short)param_2;
  _gleUpdatePolyMode(param_1);
  _gleUpdatePrimitiveData(param_1);
  return;
}

/* _glEnable_CompExec @ 0x394ac (56 bytes) */
void _glEnable_CompExec(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  ((int (*)())_glEnable_Comp)(param_1,param_2);
  _glEnable_Exec(param_1,param_2);
  return;
}

/* _glEnable_Comp @ 0x394e4 (76 bytes) */
int _glEnable_Comp(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)((int (*)())_gleAddListItem)(param_1,PTR__glEnable_ListExec_001100b4,4);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_2;
  }
  return puVar1;
}

/* _glLoadName_CompExec @ 0x39530 (56 bytes) */
void _glLoadName_CompExec(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  ((int (*)())_glLoadName_Comp)(param_1,param_2);
  ((void (*)())_glLoadName_Exec)(param_1,param_2);
  return;
}

/* _glLoadName_Comp @ 0x39568 (76 bytes) */
int _glLoadName_Comp(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)((int (*)())_gleAddListItem)(param_1,PTR__glLoadName_ListExec_001102ac,4);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_2;
  }
  return puVar1;
}

/* _glLoadName_Exec @ 0x395b4 (80 bytes) */
void _glLoadName_Exec(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if (*(int *)(param_1 + 0x4e1c) != 0x1c02) {
      return;
    }
    if (*(int *)(param_1 + 0x4fbc) != param_1 + 0x4e2c) {
      *(undefined4 *)(*(int *)(param_1 + 0x4fbc) + -4) = param_2;
      *(undefined1 *)(param_1 + 0x4fc8) = 0;
      return;
    }
  }
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  *(undefined4 *)(param_1 + 0x7574) = 0x502;
  return;
}

/* _glMaterialfv_CompExec @ 0x39604 (72 bytes) */
void _glMaterialfv_CompExec(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  double fparam_1;
  double in_f2;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  
  ((int (*)())_glMaterialfv_Comp)(param_1,param_2,param_3,param_4);
  ((void (*)())_glMaterialfv_Exec)(param_1,param_2,param_3,param_4,fparam_1,in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,
                     in_f8);
  return;
}

/* _glMaterialfv_Comp @ 0x3964c (284 bytes) */
int _glMaterialfv_Comp(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 param_2;
  undefined *param_3;
  undefined4 *param_4;
{
  undefined *puVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)((int (*)())_gleAddListItem)(param_1,PTR__glMaterialfv_ListExec_001101ec,0x18);
  if (puVar2 == (undefined4 *)0x0) {
    return puVar2;
  }
  if (param_3 != (undefined *)0x1600) {
    if (param_3 < (undefined *)0x1601) {
      if (param_3 != ((unsigned char *)0x00001201)) {
        if (((unsigned char *)0x00001201) < param_3) {
          puVar1 = ((unsigned char *)0x00001202);
        }
        else {
          puVar1 = ((unsigned char *)0x00001200);
        }
        if (param_3 != puVar1) goto LAB_00039740;
      }
    }
    else if (param_3 != (undefined *)0x1602) {
      if (param_3 < (undefined *)0x1602) {
        *puVar2 = param_2;
        puVar2[1] = param_3;
        puVar2[2] = *param_4;
        return puVar2;
      }
      if (param_3 == (undefined *)0x1603) {
        *puVar2 = param_2;
        puVar2[1] = 0x1603;
        puVar2[2] = *param_4;
        puVar2[3] = param_4[1];
        puVar2[4] = param_4[2];
        return puVar2;
      }
LAB_00039740:
      if (*(int *)(param_1 + 0x7574) != 0) {
        return puVar2;
      }
      *(undefined4 *)(param_1 + 0x7574) = 0x500;
      return puVar2;
    }
  }
  *puVar2 = param_2;
  puVar2[1] = param_3;
  puVar2[2] = *param_4;
  puVar2[3] = param_4[1];
  puVar2[4] = param_4[2];
  puVar2[5] = param_4[3];
  return puVar2;
}

/* _glDisable_CompExec @ 0x39768 (56 bytes) */
void _glDisable_CompExec(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  ((int (*)())_glDisable_Comp)(param_1,param_2);
  _glDisable_Exec(param_1,param_2);
  return;
}

/* _glDisable_Comp @ 0x397a0 (76 bytes) */
int _glDisable_Comp(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)((int (*)())_gleAddListItem)(param_1,PTR__glDisable_ListExec_001100b0,4);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_2;
  }
  return puVar1;
}

/* _glColor4f_CompExec @ 0x397ec (164 bytes) */
void _glColor4f_CompExec(int param_1,double fparam_1,double fparam_2,double fparam_3,double fparam_4)
{
  ((void (*)())_glColor4f_Comp)(param_1,fparam_1,fparam_2,fparam_3,fparam_4);
  if (*(char *)(param_1 + 0x4df8) != '\0') {
    ((void (*)())_glColor4f_ColorMat_Exec)(param_1,fparam_1,fparam_2,fparam_3,fparam_4);
    return;
  }
  ((void (*)())_glColor4f_NoColorMat_Exec)(param_1,fparam_1,fparam_2,fparam_3,fparam_4);
  return;
}

/* _glColor4f_Comp @ 0x39890 (92 bytes) */
void _glColor4f_Comp(undefined4 param_1,double fparam_1,double fparam_2,double fparam_3,double fparam_4)
{
  float *pfVar1;
  
  pfVar1 = (float *)((int (*)())_gleAddListItem)(param_1,PTR__glColor4_ListExec_00110058,0x10);
  if (pfVar1 != (float *)0x0) {
    pfVar1[3] = (float)fparam_4;
    *pfVar1 = (float)fparam_1;
    pfVar1[1] = (float)fparam_2;
    pfVar1[2] = (float)fparam_3;
  }
  FUN_00008b68();
  return;
}

/* _glColor4f_NoColorMat_Exec @ 0x398ec (20 bytes) */
void _glColor4f_NoColorMat_Exec(int param_1,float fparam_1,float fparam_2,float fparam_3,float fparam_4)
{
  *(float *)(param_1 + 0x2ac) = (float)fparam_4;
  *(float *)(param_1 + 0x2a0) = (float)fparam_1;
  *(float *)(param_1 + 0x2a4) = (float)fparam_2;
  *(float *)(param_1 + 0x2a8) = (float)fparam_3;
  return;
}

/* _glBegin_CompExec @ 0x39900 (112 bytes) */
void _glBegin_CompExec(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  double fparam_1;
  double in_f2;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  
  if (*(char *)(param_1 + 0x759c) == '\0') {
    if (*(int *)(param_1 + 0x7574) == 0) {
      *(undefined4 *)(param_1 + 0x7574) = 0x502;
    }
    return;
  }
  ((int (*)())_glBegin_Comp)(param_1,param_2);
  ((void (*)())_glBegin_Exec)(param_1,param_2,fparam_1,in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8);
  return;
}

/* _glBegin_Comp @ 0x39970 (76 bytes) */
int _glBegin_Comp(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)((int (*)())_gleAddListItem)(param_1,PTR__glBegin_ListExec_0011001c,4);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_2;
  }
  return puVar1;
}

/* _gleBeginLineStripRenderTCL @ 0x399bc (60 bytes) */
void _gleBeginLineStripRenderTCL(param_1)
  int param_1;
{
  undefined *puVar1;
  undefined *puVar2;
  
  *(undefined1 *)(param_1 + 0x4a18) = 0;
  puVar2 = PTR__gleFlushLineStripTCLFunc_001121f8;
  puVar1 = PTR__gleRenderLineStripTCLFunc_001121f4;
  *(undefined4 *)(param_1 + 0x4858) = *(undefined4 *)(param_1 + 0x4854);
  *(undefined **)(param_1 + 0x4a0c) = puVar2;
  *(undefined **)(param_1 + 0x4a08) = puVar1;
  return;
}

/* _glVertex3d_CompExec @ 0x399f8 (96 bytes) */
void _glVertex3d_CompExec(undefined4 param_1,double fparam_1,double fparam_2,double fparam_3)
{
  ((float * (*)())_glVertex3d_Comp)(param_1,fparam_1,fparam_2,fparam_3);
  ((void (*)())_glVertex3d_Exec)(param_1,fparam_1,fparam_2,fparam_3);
  return;
}

/* _glVertex3d_Comp @ 0x39a58 (128 bytes) */
float * _glVertex3d_Comp(undefined4 param_1,double fparam_1,double fparam_2,double fparam_3)
{
  float *pfVar1;
  
  pfVar1 = (float *)((int (*)())_gleAddListItem)(param_1,PTR__glVertex3_ListExec_00110414,0xc);
  if (pfVar1 != (float *)0x0) {
    *pfVar1 = (float)fparam_1;
    pfVar1[1] = (float)fparam_2;
    pfVar1[2] = (float)fparam_3;
  }
  return pfVar1;
}

/* _glVertex3d_Exec @ 0x39ad8 (52 bytes) */
void _glVertex3d_Exec(int param_1,double fparam_1,double fparam_2,double fparam_3)
{
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = *(code **)(param_1 + 0x4884);
  if (*(int *)(param_1 + 0x4858) == *(int *)(param_1 + 0x485c)) {
    UNRECOVERED_JUMPTABLE = *(code **)(param_1 + 0x28);
  }
                    
                    
  (*((int (*)(int,double,double,double,double))UNRECOVERED_JUMPTABLE))
            (param_1, (double)(float)fparam_1, (double)(float)fparam_2, (double)(float)fparam_3, (double)*(float *)(param_1 + 0x24));
  return;
}

/* _gleSetFuncOutputDesc @ 0x39b0c (1348 bytes) */
void _gleSetFuncOutputDesc(param_1, param_2, param_3)
  int param_1;
  int param_2;
  uint *param_3;
{
  char cVar1;
  bool bVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  ushort uVar10;
  ushort *puVar11;
  uint uVar12;
  uint uVar13;
  int iVar14;
  longlong lVar15;
  
  *param_3 = 0x204000;
  *(undefined2 *)(param_1 + 0x487e) = 0x7c;
  if (*(int *)(param_1 + 0x4e1c) == 0x1c00) {
    uVar9 = 0x10000;
    iVar14 = 1;
    if (*(char *)(param_1 + 0x466c) == '\0') {
      if (*(char *)(param_1 + 0x41f8) == '\0') {
        uVar6 = *(uint *)(param_1 + 0x514c);
        uVar13 = uVar6;
      }
      else {
        iVar8 = 0;
        uVar6 = *(uint *)(param_1 + 0x514c);
        uVar13 = uVar6;
        if (0 < *(int *)(param_1 + 0x41fc)) {
          do {
            iVar7 = 0;
            do {
              iVar5 = 0;
              do {
                if (*(short *)((iVar8 * 0x10 + iVar7 * 6 + iVar5) * 8 + param_1 + 0x4220) == -0x7ad3
                   ) {
                  uVar13 = uVar13 | 0x200;
                  iVar8 = 8;
                  iVar7 = 2;
                  iVar5 = 4;
                }
                iVar5 = iVar5 + 1;
              } while (iVar5 < 4);
              iVar7 = iVar7 + 1;
            } while (iVar7 < 2);
            iVar8 = iVar8 + 1;
          } while (iVar8 < *(int *)(param_1 + 0x41fc));
        }
        iVar8 = 0;
        do {
          if (*(short *)(iVar8 * 8 + param_1 + 0x4624) == -0x7ad3) {
            uVar13 = uVar13 | 0x200;
            iVar8 = 7;
          }
          iVar8 = iVar8 + 1;
        } while (iVar8 < 7);
      }
    }
    else {
      iVar8 = *(int *)(param_1 + 0x5424);
      if (*(short *)(iVar8 + 0x4c8) == -0x7e00) {
        uVar13 = *(uint *)(iVar8 + 0x4e8);
      }
      else {
        iVar8 = *(int *)(iVar8 + 0x4cc);
        uVar4 = 0;
        if (iVar8 != 0) {
          uVar4 = *(undefined4 *)(iVar8 + 0x20);
          iVar8 = iVar8 + *(int *)(iVar8 + 0x24) * 8;
        }
        uVar13 = _glePPSetFuncNeeds(iVar8,uVar4);
      }
      uVar6 = uVar13 & 0xff;
    }
    uVar12 = 0;
    do {
      uVar3 = uVar6 >> (uVar12 & 0x3f);
      if ((uVar3 & 1) == 0) {
        if (uVar3 == 0) goto LAB_00039cc0;
      }
      else {
        iVar14 = iVar14 + 1;
        lVar15 = ((longlong (*)())___ashldi3)(0,0x1000000,uVar12);
        uVar9 = uVar9 | (uint)lVar15;
      }
      uVar12 = uVar12 + 1;
    } while( true );
  }
  if (*(int *)(param_1 + 0x4e1c) == 0x1c01) {
    uVar6 = 0x1070080;
    iVar8 = 5;
    if (*(char *)(param_1 + 0x30aa) != '\0') {
      iVar8 = 7;
      uVar6 = 0x10700e0;
    }
  }
  else {
    uVar6 = 0x10000;
    iVar8 = 1;
  }
LAB_00039e14:
  bVar2 = (uVar6 & 0x80) != 0;
  *param_3 = *param_3 | iVar8 << 0x18;
  if (bVar2) {
    *(undefined2 *)(param_3 + 1) = 0xb0df;
  }
  uVar9 = (uint)bVar2;
  if ((uVar6 & 0x10000) != 0) {
    iVar14 = uVar9 * 2;
    uVar9 = uVar9 + 1;
    *(undefined2 *)((int)param_3 + iVar14 + 4) = 0x308;
  }
  if ((uVar6 & 0x20000) != 0) {
    iVar14 = uVar9 * 2;
    uVar9 = uVar9 + 1;
    *(undefined2 *)((int)param_3 + iVar14 + 4) = 0x610;
  }
  if ((uVar6 & 0x40000) != 0) {
    iVar14 = uVar9 * 2;
    uVar9 = uVar9 + 1;
    *(undefined2 *)((int)param_3 + iVar14 + 4) = 0xb0c;
  }
  if ((uVar6 & 0x80000) != 0) {
    iVar14 = uVar9 * 2;
    uVar9 = uVar9 + 1;
    *(undefined2 *)((int)param_3 + iVar14 + 4) = 0xc17;
  }
  if ((uVar6 & 0x100000) != 0) {
    iVar14 = uVar9 * 2;
    uVar9 = uVar9 + 1;
    *(undefined2 *)((int)param_3 + iVar14 + 4) = 0x1214;
  }
  if ((uVar6 & 0x200000) != 0) {
    iVar14 = uVar9 * 2;
    uVar9 = uVar9 + 1;
    *(ushort *)((int)param_3 + iVar14 + 4) = (*(byte *)(param_1 + 0x4660) - 1) * 0x100 | 0x1418;
  }
  uVar13 = 0;
  puVar11 = (ushort *)((int)param_3 + uVar9 * 2 + 4);
  uVar10 = 0x2000;
  do {
    lVar15 = ((longlong (*)())___ashldi3)(0,0x1000000,uVar13);
    if ((uVar6 & (uint)lVar15) == 0) {
      if ((uVar6 & -0x1000000 << (uVar13 & 0x3f) & 0xff000000) == 0) break;
    }
    else {
      uVar9 = uVar9 + 1;
      *puVar11 = uVar10 | (ushort)((int)(uVar13 * 0x10 + 0x80) >> 2) | 0x300;
      puVar11 = puVar11 + 1;
    }
    uVar13 = uVar13 + 1;
    uVar10 = uVar10 + 0x400;
  } while ((int)uVar13 < 8);
  uVar10 = 0xa800;
  puVar11 = (ushort *)((int)param_3 + uVar9 * 2 + 4);
  iVar14 = 0;
  do {
    lVar15 = ((longlong (*)())___ashldi3)(0,0x20,iVar14);
    if ((uVar6 & (uint)lVar15) != 0) {
      uVar9 = uVar9 + 1;
      *puVar11 = uVar10 | (ushort)(iVar14 * 4 + 0x74 >> 2) | 0xc0;
      puVar11 = puVar11 + 1;
    }
    iVar14 = iVar14 + 1;
    uVar10 = uVar10 + 0x400;
  } while (iVar14 < 2);
  if ((uVar6 & 0x400000) != 0) {
    *(undefined2 *)((int)param_3 + uVar9 * 2 + 4) = 0x185f;
  }
  return;
LAB_00039cc0:
  if ((*(short *)(param_1 + 0x3166) == -0x7baf) || ((uVar13 & 0x400) != 0)) {
    uVar9 = uVar9 | 0x80000;
    iVar14 = iVar14 + 1;
  }
  if (*(char *)(param_1 + 0x4661) != '\0') {
    uVar9 = uVar9 | 0x200000;
    iVar14 = iVar14 + 1;
  }
  if (*(int *)(param_1 + 0x34d0) != 0x1b021b02) {
    uVar9 = uVar9 | 0x400000;
    iVar14 = iVar14 + 1;
  }
  cVar1 = *(char *)(param_1 + 0x7580);
  if (cVar1 == '\0') {
    uVar9 = uVar9 | 0x80;
    iVar14 = iVar14 + 1;
  }
  if (*(char *)(param_1 + 0x30aa) == '\0') {
    uVar6 = uVar9 | 0x40000;
    iVar8 = iVar14 + 1;
    if (((uVar13 & 0x200) != 0) || (*(char *)(param_1 + 0x4fea) != '\0')) {
      uVar6 = uVar9 | 0x140000;
      iVar8 = iVar14 + 2;
    }
    if (((*(int *)(param_1 + 0x514c) == 0) || (*(char *)(param_1 + 0x53e6) == '\0')) &&
       (*(char *)(param_1 + 0x280c) == '\0')) goto LAB_00039e14;
    uVar6 = uVar6 | 0x20000;
  }
  else {
    uVar12 = uVar9 | 0x20000;
    iVar7 = iVar14 + 1;
    if ((*(char *)(param_1 + 0x30ab) != '\0') && ((cVar1 != '\0' || (param_2 != 0)))) {
      uVar12 = uVar9 | 0x60000;
      iVar7 = iVar14 + 2;
    }
    uVar6 = uVar12;
    iVar8 = iVar7;
    if (cVar1 == '\0') {
      uVar6 = uVar12 | 0x20;
      iVar8 = iVar7 + 1;
      if (*(char *)(param_1 + 0x30ac) != '\0') {
        uVar6 = uVar12 | 0x60;
        iVar8 = iVar7 + 2;
      }
    }
    if ((uVar13 & 0x200) == 0) goto LAB_00039e14;
    uVar6 = uVar6 | 0x100000;
  }
  iVar8 = iVar8 + 1;
  goto LAB_00039e14;
}

/* ___ashldi3 @ 0x3a050 (96 bytes) */
longlong ___ashldi3(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  uint param_3;
{
  uint uVar1;
  undefined4 local_2c;
  
  if (param_3 == 0) {
    return CONCAT44(param_1,param_2);
  }
  uVar1 = 0x20 - param_3;
  if ((int)uVar1 < 1) {
    uVar1 = param_2 << (-uVar1 & 0x3f);
    local_2c = 0;
  }
  else {
    local_2c = param_2 << (param_3 & 0x3f);
    uVar1 = param_1 << (param_3 & 0x3f) | param_2 >> (uVar1 & 0x3f);
  }
  return CONCAT44(uVar1,local_2c);
}

/* _glEnd_CompExec @ 0x3a0b0 (48 bytes) */
void _glEnd_CompExec(param_1)
  undefined4 param_1;
{
  ((int (*)())_glEnd_Comp)(param_1);
  ((double (*)())_glEnd_Exec)(param_1);
  return;
}

/* _glEnd_Comp @ 0x3a0e0 (32 bytes) */
int _glEnd_Comp(param_1)
  undefined4 param_1;
{
  undefined4 uVar1;
  
  uVar1 = ((int (*)())_gleAddListItem)(param_1,PTR__glEnd_ListExec_001100b8,0);
  return uVar1;
}

/* _glEnd_Exec @ 0x3a100 (128 bytes) */
double _glEnd_Exec(param_1)
  int param_1;
{
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if (*(int *)(param_1 + 0x7574) == 0) {
      *(undefined4 *)(param_1 + 0x7574) = 0x502;
    }
    return;
  }
  *(undefined2 *)(param_1 + 0x4a10) = 0xffff;
  *(undefined4 *)(param_1 + 0x4884) = *(undefined4 *)(param_1 + 0xd8);
  (**(code **)(param_1 + 0x4a08))(param_1);
  ((int (*)())_glePopAndCopyMaterials)(param_1);
  return;
}

/* _glePopAndCopyMaterials @ 0x3a1b0 (152 bytes) */
int _glePopAndCopyMaterials(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = param_1 + 0x2c20;
  iVar4 = param_1;
  do {
    iVar2 = *(int *)(iVar4 + 0x4dd0);
    if (*(int *)(iVar2 + 0x23c) != 0) {
      iVar1 = *(int *)(param_1 + 0x4dd8);
      iVar3 = *(int *)(iVar5 + 0x238);
      *(int *)(iVar3 + 0x23c) = iVar1;
      if (iVar1 != 0) {
        *(int *)(iVar1 + 0x238) = iVar3;
      }
      *(int *)(param_1 + 0x4dd8) = iVar2;
      *(int *)(iVar4 + 0x4dd0) = iVar5;
      _memcpy(iVar5,iVar2,0x240);
      *(undefined4 *)(iVar5 + 0x23c) = 0;
      iVar2 = iVar5;
    }
    iVar4 = iVar4 + 4;
    *(undefined1 *)(iVar2 + 0x236) = 0;
    *(undefined4 *)(iVar2 + 0x1e0) = 0;
    *(undefined1 *)(iVar2 + 0x235) = 0;
    iVar5 = iVar5 + 0x240;
  } while (iVar4 <= param_1 + 4);
  return;
}

/* _glLineWidth_CompExec @ 0x3a248 (64 bytes) */
void _glLineWidth_CompExec(undefined4 param_1,double fparam_1)
{
  ((float * (*)())_glLineWidth_Comp)(param_1,fparam_1);
  ((void (*)())_glLineWidth_Exec)(param_1,fparam_1);
  return;
}

/* _glLineWidth_Comp @ 0x3a288 (84 bytes) */
float * _glLineWidth_Comp(undefined4 param_1,double fparam_1)
{
  float *pfVar1;
  
  pfVar1 = (float *)((int (*)())_gleAddListItem)(param_1,PTR__glLineWidth_ListExec_00110158,4);
  if (pfVar1 != (float *)0x0) {
    *pfVar1 = (float)fparam_1;
  }
  return pfVar1;
}

/* _glLineWidth_Exec @ 0x3a2dc (112 bytes) */
void _glLineWidth_Exec(int param_1,float fparam_1)
{
  undefined4 uVar1;
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if ((double)FLOAT_00108e50 < fparam_1) {
      *(float *)(param_1 + 0x3180) = (float)fparam_1;
      *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x4000;
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

/* _glClear_CompExec @ 0x3a34c (56 bytes) */
void _glClear_CompExec(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  double fparam_1;
  double in_f2;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  
  ((int (*)())_glClear_Comp)(param_1,param_2);
  ((void (*)())_glClear_Exec)(param_1,param_2,fparam_1,in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8);
  return;
}

/* _glClear_Comp @ 0x3a384 (76 bytes) */
int _glClear_Comp(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)((int (*)())_gleAddListItem)(param_1,PTR__glClear_ListExec_00110038,4);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_2;
  }
  return puVar1;
}

/* _gleSetEnable_STENCIL_TEST @ 0x3a3d0 (56 bytes) */
void _gleSetEnable_STENCIL_TEST(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  int param_3;
{
  uint uVar1;
  
  uVar1 = *(byte *)(param_1 + 0x7583) & 0x1f;
  uVar1 = *(uint *)(param_1 + 0x3520) & (-2 << uVar1 | 0xfffffffeU >> 0x20 - uVar1) |
          param_3 << (*(byte *)(param_1 + 0x7583) & 0x3f);
  if (*(uint *)(param_1 + 0x3520) == uVar1) {
    return;
  }
  *(uint *)(param_1 + 0x3520) = uVar1;
  *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x10000000;
  return;
}

/* _glStencilFunc_CompExec @ 0x3a408 (72 bytes) */
void _glStencilFunc_CompExec(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  ((int (*)())_glStencilFunc_Comp)(param_1,param_2,param_3,param_4);
  ((void (*)())_glStencilFunc_Exec)(param_1,param_2,param_3,param_4);
  return;
}

/* _glStencilFunc_Comp @ 0x3a450 (92 bytes) */
int _glStencilFunc_Comp(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)((int (*)())_gleAddListItem)(param_1,PTR__glStencilFunc_ListExec_0011031c,0xc);
  if (puVar1 != (undefined4 *)0x0) {
    puVar1[2] = param_4;
    *puVar1 = param_2;
    puVar1[1] = param_3;
  }
  return puVar1;
}

/* _glStencilFunc_Exec @ 0x3a4ac (164 bytes) */
void _glStencilFunc_Exec(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  uint param_3;
  undefined4 param_4;
{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if (param_2 - 0x200U < 8) {
      if ((int)param_3 < 0) {
        param_3 = 0;
      }
      else {
        uVar2 = 0xffffffff >> (0x20U - *(int *)(*(int *)(param_1 + 0x468c) + 0x40) & 0x3f);
        if (uVar2 < param_3) {
          param_3 = uVar2;
        }
      }
      iVar3 = (uint)*(byte *)(param_1 + 0x7583) * 0x10 + param_1;
      *(undefined4 *)(iVar3 + 0x34f8) = param_4;
      *(uint *)(iVar3 + 0x34fc) = param_3;
      *(short *)(iVar3 + 0x3500) = (short)param_2;
      *(short *)(param_1 + 0x3518) = (short)param_2;
      *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x10000000;
      return;
    }
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar1 = 0x500;
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

/* _glStencilOp_CompExec @ 0x3a550 (72 bytes) */
void _glStencilOp_CompExec(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  ((int (*)())_glStencilOp_Comp)(param_1,param_2,param_3,param_4);
  ((void (*)())_glStencilOp_Exec)(param_1,param_2,param_3,param_4);
  return;
}

/* _glStencilOp_Comp @ 0x3a598 (92 bytes) */
int _glStencilOp_Comp(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)((int (*)())_gleAddListItem)(param_1,PTR__glStencilOp_ListExec_00110318,0xc);
  if (puVar1 != (undefined4 *)0x0) {
    puVar1[2] = param_4;
    *puVar1 = param_2;
    puVar1[1] = param_3;
  }
  return puVar1;
}

/* _glStencilOp_Exec @ 0x3a5f4 (268 bytes) */
void _glStencilOp_Exec(param_1, param_2, param_3, param_4)
  int param_1;
  uint param_2;
  uint param_3;
  uint param_4;
{
  undefined4 uVar1;
  int iVar2;
  
  if (-1 < *(short *)(param_1 + 0x4a10)) {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar1 = 0x502;
    goto LAB_0003a658;
  }
  if (param_2 < 0x1e04) {
    if (((0x1dff < param_2) || (param_2 == 0)) || (param_2 == 0x150a)) {
LAB_0003a660:
      if (param_3 < 0x1e04) {
        if (((0x1dff < param_3) || (param_3 == 0)) || (param_3 == 0x150a)) {
LAB_0003a694:
          if (param_4 < 0x1e04) {
            if (((0x1dff < param_4) || (param_4 == 0)) || (param_4 == 0x150a)) {
LAB_0003a6c8:
              iVar2 = (uint)*(byte *)(param_1 + 0x7583) * 0x10 + param_1;
              *(short *)(iVar2 + 0x3506) = (short)param_4;
              *(short *)(iVar2 + 0x3502) = (short)param_2;
              *(short *)(iVar2 + 0x3504) = (short)param_3;
              *(short *)(param_1 + 0x351a) = (short)param_2;
              *(short *)(param_1 + 0x351c) = (short)param_3;
              *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x10000000;
              *(short *)(param_1 + 0x351e) = (short)param_4;
              return;
            }
          }
          else if (param_4 - 0x8507 < 2) goto LAB_0003a6c8;
        }
      }
      else if (param_3 - 0x8507 < 2) goto LAB_0003a694;
    }
  }
  else if (param_2 - 0x8507 < 2) goto LAB_0003a660;
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  uVar1 = 0x500;
LAB_0003a658:
  *(undefined4 *)(param_1 + 0x7574) = uVar1;
  return;
}

/* _glColorMask_CompExec @ 0x3a700 (80 bytes) */
void _glColorMask_CompExec(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  ((int (*)())_glColorMask_Comp)(param_1,param_2,param_3,param_4,param_5);
  _glColorMask_Exec(param_1,param_2,param_3,param_4,param_5);
  return;
}

/* _glColorMask_Comp @ 0x3a750 (100 bytes) */
int _glColorMask_Comp(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)((int (*)())_gleAddListItem)(param_1,PTR__glColorMask_ListExec_001101dc,4);
  if (puVar1 != (undefined1 *)0x0) {
    puVar1[3] = (undefined1)param_5;
    *puVar1 = (undefined1)param_2;
    puVar1[1] = (undefined1)param_3;
    puVar1[2] = (undefined1)param_4;
  }
  return puVar1;
}

/* _glDepthMask_CompExec @ 0x3a7b4 (56 bytes) */
void _glDepthMask_CompExec(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  ((int (*)())_glDepthMask_Comp)(param_1,param_2);
  _glDepthMask_Exec(param_1,param_2);
  return;
}

/* _glDepthMask_Comp @ 0x3a7ec (76 bytes) */
int _glDepthMask_Comp(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)((int (*)())_gleAddListItem)(param_1,PTR__glDepthMask_ListExec_001101d8,4);
  if (puVar1 != (undefined1 *)0x0) {
    *puVar1 = (undefined1)param_2;
  }
  return puVar1;
}

/* _gleBeginQuadsRenderTCL @ 0x3a838 (52 bytes) */
void _gleBeginQuadsRenderTCL(param_1)
  int param_1;
{
  undefined *puVar1;
  
  puVar1 = PTR__gleFlushAtomicTCLFunc_00112218;
  *(undefined4 *)(param_1 + 0x4858) = *(undefined4 *)(param_1 + 0x4854);
  *(undefined **)(param_1 + 0x4a0c) = puVar1;
  *(undefined **)(param_1 + 0x4a08) = PTR__gleRenderQuadsTCLFunc_00112280;
  return;
}

/* _glNormal3f_CompExec @ 0x3a86c (96 bytes) */
void _glNormal3f_CompExec(undefined4 param_1,double fparam_1,double fparam_2,double fparam_3)
{
  ((float * (*)())_glNormal3f_Comp)(param_1,fparam_1,fparam_2,fparam_3);
  ((void (*)())_glNormal3f_Exec)(param_1,fparam_1,fparam_2,fparam_3);
  return;
}

