#include "decls.h"

/* _gleCreateGlobalLevel @ 0x103534 (64 bytes) */
int _gleCreateGlobalLevel(param_1, param_2, param_3, param_4, param_5, param_6)
  undefined4 param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
{
  *(undefined2 *)(param_2 + 0x10) = 0x1908;
  *(undefined2 *)(param_2 + 0xe) = 0;
  *(undefined2 *)(param_2 + 4) = (*(unsigned short *)((unsigned char *)&(param_3) + 2));
  *(undefined2 *)(param_2 + 6) = (*(unsigned short *)((unsigned char *)&(param_4) + 2));
  *(undefined2 *)(param_2 + 8) = (*(unsigned short *)((unsigned char *)&(param_5) + 2));
  *(undefined2 *)(param_2 + 0x12) = 0x1401;
  *(undefined1 *)(param_2 + 0xb) = 0x34;
  *(undefined1 *)(param_2 + 10) = (undefined1)param_6;
  *(undefined4 *)(param_2 + 0x14) = 0;
  *(undefined2 *)(param_2 + 0xc) = 0;
  return 0;
}

/* _gleSynchronizePluginTextureLevels @ 0x103574 (308 bytes) */
int _gleSynchronizePluginTextureLevels(param_1, param_2)
  int param_1;
  int param_2;
{
  byte bVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  if (*(int *)(param_2 + 0x20) != 0) {
    iVar4 = 0;
    bVar1 = *(byte *)(param_2 + 0x90);
    if (*(byte *)(param_1 + 0x85a4) != 0) {
      piVar3 = (int *)(*(int *)(param_1 + 0x5148) + 0x8054);
      do {
        iVar2 = *piVar3;
        piVar3 = piVar3 + 1;
        if (*(int *)(param_2 + 0x20) == iVar2) break;
        iVar4 = iVar4 + 1;
      } while (iVar4 < (int)(uint)*(byte *)(param_1 + 0x85a4));
    }
    iVar2 = 0;
    if (bVar1 != 0) {
      iVar5 = 0;
      do {
        iVar6 = -(uint)(iVar2 == 0);
        iVar7 = (uint)(iVar2 == 0) * -0x18 + param_2 + iVar5 + 0xc4;
        do {
          if ((*(byte *)(iVar7 + 0xb) & 0x50) == 0x40) {
            _gleUploadPluginTextureLevel(param_1,param_2,iVar7,iVar2,iVar6,iVar4);
            _gleModifyPluginTextureLevel(param_1,param_2,iVar7,iVar2,iVar6,0,0,0);
          }
          iVar6 = iVar6 + 1;
          iVar7 = iVar7 + 0x18;
        } while (iVar6 < 0xf);
        iVar2 = iVar2 + 1;
        iVar5 = iVar5 + 0x168;
      } while (iVar2 < (int)(uint)bVar1);
    }
    *(undefined4 *)(param_2 + 0x20) = 0;
  }
  return;
}

/* _gleSynchronizePluginTextures @ 0x1036a8 (108 bytes) */
int _gleSynchronizePluginTextures(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  
  iVar2 = 0;
  iVar3 = param_1;
  do {
    piVar5 = (int *)(iVar3 + 0x5154);
    iVar4 = 4;
    do {
      iVar1 = *piVar5;
      piVar5 = piVar5 + 1;
      if (iVar1 != 0) {
        ((int (*)())_gleSynchronizePluginTextureLevels)(param_1,iVar1 + 0x10);
      }
      iVar4 = iVar4 + -1;
    } while (-1 < iVar4);
    iVar2 = iVar2 + 1;
    iVar3 = iVar3 + 0x14;
  } while (iVar2 < 0x10);
  return;
}

/* _gleTextureTargetExtractor @ 0x103714 (116 bytes) */
int _gleTextureTargetExtractor(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  switch(*(ushort *)(param_2 + 0x34) & 0xf) {
  case 0:
    return 0x8513;
  case 1:
    return 0x806f;
  case 2:
    return 0x84f5;
  case 3:
    return 0xde1;
  case 4:
    return 0xde0;
  default:
    return 0;
  }
}

/* _gleTexEnableBits @ 0x10379c (192 bytes) */
int _gleTexEnableBits(param_1)
  int param_1;
{
  bool bVar1;
  int iVar2;
  uint *puVar3;
  uint uVar4;
  
  uVar4 = 0;
  bVar1 = *(char *)(param_1 + 0x466c) != '\0';
  if ((bVar1) || (*(int *)(param_1 + 0x5438) != 0)) {
    iVar2 = 0;
    if (bVar1) {
      iVar2 = *(int *)(param_1 + 0x5424);
      if (*(short *)(iVar2 + 0x4c8) == -0x7e00) {
        return (uint)*(byte *)(iVar2 + 0x4eb);
      }
      iVar2 = *(int *)(iVar2 + 0x4cc);
    }
    if (*(int *)(param_1 + 0x5438) != 0) {
      iVar2 = *(int *)(*(int *)(*(int *)(param_1 + 0x5430) + 0x24) + 0x508);
    }
    if (iVar2 != 0) {
      puVar3 = (uint *)(iVar2 + *(int *)(iVar2 + 0x24) * 8);
      for (iVar2 = *(int *)(iVar2 + 0x20); iVar2 != 0; iVar2 = iVar2 + -1) {
        if ((*puVar3 >> 0x10 & 0xf) == 7) {
          uVar4 = uVar4 | 1 << (*puVar3 & 0x1f);
        }
        puVar3 = puVar3 + 2;
      }
    }
  }
  else {
    uVar4 = *(uint *)(param_1 + 0x514c);
  }
  return uVar4;
}

/* FUN_00103860 @ 0x103860 (252 bytes) */
void FUN_00103860(int param_1,uint param_2,int param_3,int param_4,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11)
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
  int iVar22;
  uint uVar23;
  
  iVar22 = param_1 + param_4 * 0x40;
  fVar1 = *(float *)(iVar22 + 0x1fc0);
  fVar2 = *(float *)(iVar22 + 0x1ff8);
  fVar3 = *(float *)(iVar22 + 0x1fc4);
  fVar4 = *(float *)(_glePreInitVectorTOC + iVar22);
  fVar5 = *(float *)(iVar22 + 0x1fd0);
  fVar6 = *(float *)(iVar22 + 0x1fd4);
  fVar7 = *(float *)(iVar22 + 0x1fdc);
  fVar8 = *(float *)(iVar22 + 0x1fe0);
  fVar9 = *(float *)(iVar22 + 0x1fe4);
  fVar10 = *(float *)(iVar22 + 0x1fec);
  fVar11 = *(float *)(iVar22 + 0x1ff0);
  fVar12 = *(float *)(iVar22 + 0x1ff4);
  fVar13 = *(float *)(iVar22 + 0x1ffc);
  fVar14 = *(float *)(iVar22 + 0x1fc8);
  fVar15 = *(float *)(iVar22 + 0x1fd8);
  fVar16 = *(float *)(iVar22 + 0x1fe8);
  if (param_2 < param_2 + param_3) {
    uVar23 = ((param_2 + param_3) - param_2) + 0xff >> 8;
    do {
      iVar22 = param_2 + param_4 * 0x10;
      fVar17 = *(float *)(iVar22 + 0x80);
      fVar18 = *(float *)(iVar22 + 0x84);
      fVar19 = *(float *)(iVar22 + 0x88);
      fVar20 = *(float *)(iVar22 + 0x8c);
      fVar21 = *(float *)(param_2 + 0xc);
      param_2 = param_2 + 0x100;
      *(float *)(iVar22 + 0x8c) =
           (fVar20 * fVar13 + fVar19 * fVar10 + fVar17 * fVar4 + fVar18 * fVar7) * fVar21;
      *(float *)(iVar22 + 0x80) =
           (fVar20 * fVar11 + fVar19 * fVar8 + fVar17 * fVar1 + fVar18 * fVar5) * fVar21;
      *(float *)(iVar22 + 0x84) =
           (fVar20 * fVar12 + fVar19 * fVar9 + fVar17 * fVar3 + fVar18 * fVar6) * fVar21;
      *(float *)(iVar22 + 0x88) =
           (fVar20 * fVar2 + fVar19 * fVar16 + fVar17 * fVar14 + fVar18 * fVar15) * fVar21;
      uVar23 = uVar23 - 1;
    } while (uVar23 != 0);
  }
  return;
}

/* FUN_00103960 @ 0x103960 (264 bytes) */
void FUN_00103960(int param_1,uint param_2,int param_3,int param_4,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11)
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
  int iVar25;
  uint uVar26;
  
  iVar25 = param_1 + param_4 * 0x40;
  fVar1 = *(float *)(iVar25 + 0x1fc0);
  fVar2 = *(float *)(iVar25 + 0x1ff8);
  fVar3 = *(float *)(iVar25 + 0x1fc4);
  fVar4 = *(float *)(_glePreInitVectorTOC + iVar25);
  fVar5 = *(float *)(iVar25 + 0x1fd0);
  fVar6 = *(float *)(iVar25 + 0x1fd4);
  fVar7 = *(float *)(iVar25 + 0x1fdc);
  fVar8 = *(float *)(iVar25 + 0x1fe0);
  fVar9 = *(float *)(iVar25 + 0x1fe4);
  fVar10 = *(float *)(iVar25 + 0x1fec);
  fVar11 = *(float *)(iVar25 + 0x1ff0);
  fVar12 = *(float *)(iVar25 + 0x1ff4);
  fVar13 = *(float *)(iVar25 + 0x1ffc);
  fVar14 = *(float *)(iVar25 + 0x1fc8);
  fVar15 = *(float *)(iVar25 + 0x1fd8);
  fVar16 = *(float *)(iVar25 + 0x1fe8);
  if (param_2 < param_2 + param_3) {
    uVar26 = ((param_2 + param_3) - param_2) + 0xff >> 8;
    do {
      iVar25 = param_2 + param_4 * 0x10;
      fVar17 = *(float *)(iVar25 + 0x80);
      fVar18 = *(float *)(iVar25 + 0x84);
      fVar19 = *(float *)(iVar25 + 0x88);
      fVar20 = *(float *)(iVar25 + 0x8c);
      fVar21 = *(float *)(param_2 + 0xc);
      fVar24 = fVar20 * fVar13 + fVar19 * fVar10 + fVar17 * fVar4 + fVar18 * fVar7;
      fVar23 = fVar20 * fVar11 + fVar19 * fVar8 + fVar17 * fVar1 + fVar18 * fVar5;
      fVar22 = fVar20 * fVar12 + fVar19 * fVar9 + fVar17 * fVar3 + fVar18 * fVar6;
      fVar17 = fVar20 * fVar2 + fVar19 * fVar16 + fVar17 * fVar14 + fVar18 * fVar15;
      if (*(char *)(param_2 + 0x7f) == '\0') {
        fVar24 = fVar24 * fVar21;
        fVar23 = fVar23 * fVar21;
        fVar22 = fVar22 * fVar21;
        fVar17 = fVar17 * fVar21;
      }
      *(float *)(iVar25 + 0x80) = fVar23;
      param_2 = param_2 + 0x100;
      *(float *)(iVar25 + 0x8c) = fVar24;
      *(float *)(iVar25 + 0x84) = fVar22;
      *(float *)(iVar25 + 0x88) = fVar17;
      uVar26 = uVar26 - 1;
    } while (uVar26 != 0);
  }
  return;
}

/* _gleMultiTextureMatTrans @ 0x103a68 (120 bytes) */
int _gleMultiTextureMatTrans(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = ((int (*)())_gleTexEnableBits)(param_1);
  uVar3 = 0;
  do {
    uVar1 = uVar2 >> (uVar3 & 0x3f);
    if ((uVar1 & 1) == 0) {
      if (uVar1 == 0) {
        return;
      }
    }
    else {
      (**(code **)(param_1 + 0x5070))(param_1,param_2,param_3,uVar3);
    }
    uVar3 = uVar3 + 1;
  } while( true );
}

/* _gleSubmitVertexCopy @ 0x103ae0 (88 bytes) */
int _gleSubmitVertexCopy(param_1, param_2)
  int param_1;
  int param_2;
{
  short sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  sVar1 = *(short *)(param_1 + 0x487c);
  iVar4 = 0;
  iVar5 = *(int *)(param_1 + 0x4858);
  iVar3 = (int)sVar1 >> 3;
  if (0 < iVar3) {
    do {
      iVar2 = iVar4 * 8;
      iVar4 = iVar4 + 1;
      *(undefined8 *)(iVar5 + iVar2) = *(undefined8 *)(param_2 + iVar2);
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    sVar1 = *(short *)(param_1 + 0x487c);
  }
  *(int *)(param_1 + 0x4858) = iVar5 + sVar1;
                    
                    
  (**(code **)(param_1 + 0x4de4))(param_1);
  return;
}

/* _gleForceToSoftwareTCL @ 0x103b38 (1520 bytes) */
undefined4 _gleForceToSoftwareTCL(int param_1,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  bool bVar1;
  char cVar2;
  undefined1 uVar3;
  int *piVar4;
  undefined4 uVar5;
  int iVar6;
  int in_r5;
  undefined4 in_r6;
  int in_r7;
  undefined1 *puVar7;
  char *in_r8;
  int iVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  undefined4 uVar13;
  int *piVar14;
  int iVar15;
  undefined4 uVar16;
  double extraout_f1;
  char local_30 [16];
  
  local_30[0] = '\0';
  iVar10 = *(int *)(param_1 + 0x4854);
  if (*(int *)(param_1 + 0x48d0) == 0) {
    iVar11 = *(int *)(param_1 + 0x4858) - iVar10 >> 8;
  }
  else {
    in_r8 = local_30;
    iVar11 = (*(int *)(param_1 + 0x4858) - *(int *)(param_1 + 0x4868)) /
             (int)*(short *)(param_1 + 0x487c);
    *(int *)(param_1 + 0x4858) = iVar10 + iVar11 * 0x100;
    in_r7 = iVar10;
    _gleDecomposePrimitiveVertices
              (param_1,*(int *)(param_1 + 0x48d0),iVar11,*(int *)(param_1 + 0x4868),iVar10,in_r8);
    if (local_30[0] != '\0') {
      iVar10 = *(int *)(param_1 + 0x758c);
    }
    in_r6 = 0;
    in_r5 = (int)*(short *)(param_1 + 0x4a12);
    fparam_1 = (double)(**(code **)(param_1 + 0x46ec))(*(undefined4 *)(param_1 + 0x4688),2);
  }
  iVar12 = iVar11 + -1;
  iVar8 = *(int *)(param_1 + 0x50ac);
  *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x10000000;
  if (iVar8 != 0 || (*(uint *)(param_1 + 0x505c) & *(uint *)(param_1 + 0x50b0)) != 0) {
    _gleUpdateMatrixFunc(param_1);
    fparam_1 = extraout_f1;
  }
  if (*(char *)(param_1 + 0x4691) == '\0') goto LAB_00103dec;
  iVar6 = *(int *)(param_1 + 0x744c);
  piVar14 = (int *)(param_1 + 0x310);
  cVar2 = *(char *)(*(int *)(param_1 + 0x468c) + 0x79);
  if ((iVar6 != 0) && (*(int *)(iVar6 + 0xec) != 0)) {
    ((int (*)())_gleUpdateFramebufferCompleteness)(param_1,iVar6 + 0x10,in_r5,in_r6,in_r7,in_r8,iVar8,fparam_1,fparam_2,fparam_3,
               fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
    *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x80000000;
  }
  if ((*(char *)(param_1 + 0x4664) == '\0') && (*(int *)(param_1 + 0x5430) == 0)) {
LAB_00103ce4:
    uVar9 = *(uint *)(param_1 + 0x31c);
  }
  else {
    iVar8 = 0;
    piVar4 = (int *)(param_1 + 0x324);
    do {
      iVar6 = *piVar4;
      piVar4 = piVar4 + 1;
      if (iVar6 != 0) {
        *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x800000;
        break;
      }
      iVar8 = iVar8 + 1;
    } while (iVar8 < 9);
    uVar9 = *(uint *)(param_1 + 0x31c);
    if ((uVar9 & 0x15555) != 0) {
      if (*(char *)(param_1 + 0x2e54) != '\0') {
        _gleUpdateLightRGBASums(param_1,param_1 + 0x2c20,0);
      }
      if (*(char *)(param_1 + 0x3094) != '\0') {
        _gleUpdateLightRGBASums(param_1,param_1 + 0x2e60,1);
      }
      goto LAB_00103ce4;
    }
  }
  bVar1 = cVar2 == '\0';
  if (bVar1) {
    uVar9 = uVar9 & 0x17000000;
  }
  else {
    uVar9 = uVar9 & 0x17ffffff;
  }
  if (bVar1) {
    bVar1 = ((*piVar14 == 0 && *(int *)(param_1 + 0x314) == 0) && uVar9 == 0) &&
            *(int *)(param_1 + 800) == 0;
  }
  else {
    bVar1 = (((*piVar14 == 0 && *(int *)(param_1 + 0x314) == 0) &&
             (*(uint *)(param_1 + 0x318) & 0xfffffffd) == 0) && uVar9 == 0) &&
            *(int *)(param_1 + 800) == 0;
  }
  if (!bVar1) {
    if (*(char *)(param_1 + 0x85a8) == *(char *)(param_1 + 0x85a6)) {
      uVar9 = (**(code **)(param_1 + 0x4788))
                        (*(undefined4 *)(param_1 + 0x4688),param_1 + 0x4698,piVar14);
      if ((((uVar9 & 3) != (uint)*(byte *)(param_1 + 0x7580)) ||
          ((uVar9 & 4) != (uint)*(byte *)(param_1 + 0x7581))) ||
         ((uVar9 & 8) != (uint)(*(char *)(param_1 + 0x759d) == '\0'))) {
        if ((uVar9 & 4) == 0) {
          uVar9 = uVar9 & 0xfffffffe;
          *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x10000000;
        }
        _gleUpdateDispatchCodeChange(param_1,uVar9);
      }
    }
    else {
      _gleSwitchToNonRevertRenderer(param_1);
    }
  }
  iVar8 = 0x13;
  do {
    *piVar14 = 0;
    piVar14 = piVar14 + 1;
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
LAB_00103dec:
  *(undefined4 *)(param_1 + 0x4884) = *(undefined4 *)(param_1 + 0x4888);
  if (*(char *)(param_1 + 0x30aa) == '\0') {
    if (-1 < iVar12) {
      puVar7 = (undefined1 *)(iVar10 + 0x7e);
      do {
        puVar7[-1] = *(undefined1 *)(param_1 + 0x2ed);
        *puVar7 = *(undefined1 *)(param_1 + 0x2ee);
        puVar7 = puVar7 + 0x100;
        iVar11 = iVar11 + -1;
      } while (iVar11 != 0);
    }
  }
  else if (*(char *)(param_1 + 0x4df8) == '\0') {
    if (*(char *)(param_1 + 0x30ac) == '\0') {
      iVar8 = *(int *)(param_1 + 0x4dd0);
      *(undefined4 *)(iVar8 + 0x1e0) = 1;
      if (-1 < iVar12) {
        do {
          *(undefined1 *)(iVar10 + 0x7d) = *(undefined1 *)(param_1 + 0x2ed);
          uVar3 = *(undefined1 *)(param_1 + 0x2ee);
          *(int *)(iVar10 + 0x74) = iVar8;
          *(undefined1 *)(iVar10 + 0x7e) = uVar3;
          iVar10 = iVar10 + 0x100;
          iVar11 = iVar11 + -1;
        } while (iVar11 != 0);
      }
    }
    else {
      iVar8 = *(int *)(param_1 + 0x4dd0);
      iVar6 = *(int *)(param_1 + 0x4dd4);
      *(undefined4 *)(iVar8 + 0x1e0) = 1;
      *(undefined4 *)(iVar6 + 0x1e0) = 1;
      if (-1 < iVar12) {
        do {
          *(undefined1 *)(iVar10 + 0x7d) = *(undefined1 *)(param_1 + 0x2ed);
          uVar3 = *(undefined1 *)(param_1 + 0x2ee);
          *(int *)(iVar10 + 0x74) = iVar8;
          *(undefined1 *)(iVar10 + 0x7e) = uVar3;
          *(int *)(iVar10 + 0x78) = iVar6;
          iVar10 = iVar10 + 0x100;
          iVar11 = iVar11 + -1;
        } while (iVar11 != 0);
      }
    }
  }
  else {
    iVar11 = iVar10 + 0x30;
    (**(code **)(param_1 + 0x4de0))(param_1,iVar11);
    if (*(char *)(param_1 + 0x30ac) == '\0') {
      iVar8 = 0;
      iVar6 = iVar12;
      iVar15 = iVar10;
      if (0 < iVar12) {
        do {
          *(undefined1 *)(iVar15 + 0x7d) = *(undefined1 *)(param_1 + 0x2ed);
          *(undefined1 *)(iVar15 + 0x7e) = *(undefined1 *)(param_1 + 0x2ee);
          iVar8 = *(int *)(param_1 + 0x4dd0);
          *(undefined4 *)(iVar8 + 0x1e0) = 1;
          *(int *)(iVar15 + 0x74) = iVar8;
          if (((*(float *)(iVar15 + 0x30) != *(float *)(iVar15 + 0x130)) ||
              (*(float *)(iVar15 + 0x34) != *(float *)(iVar15 + 0x134))) ||
             ((*(float *)(iVar15 + 0x38) != *(float *)(iVar15 + 0x138) ||
              (*(float *)(iVar15 + 0x3c) != *(float *)(iVar15 + 0x13c))))) {
            (**(code **)(param_1 + 0x4de0))(param_1,iVar11);
          }
          iVar6 = iVar6 + -1;
          iVar11 = iVar11 + 0x100;
          iVar8 = iVar12;
          iVar15 = iVar15 + 0x100;
        } while (iVar6 != 0);
      }
      iVar11 = *(int *)(param_1 + 0x4dd0);
      *(undefined4 *)(iVar11 + 0x1e0) = 1;
      *(int *)(iVar8 * 0x100 + iVar10 + 0x74) = iVar11;
    }
    else {
      iVar8 = 0;
      iVar6 = iVar12;
      iVar15 = iVar10;
      if (0 < iVar12) {
        do {
          *(undefined1 *)(iVar15 + 0x7d) = *(undefined1 *)(param_1 + 0x2ed);
          *(undefined1 *)(iVar15 + 0x7e) = *(undefined1 *)(param_1 + 0x2ee);
          iVar8 = *(int *)(param_1 + 0x4dd0);
          *(undefined4 *)(iVar8 + 0x1e0) = 1;
          *(int *)(iVar15 + 0x74) = iVar8;
          iVar8 = *(int *)(param_1 + 0x4dd4);
          *(undefined4 *)(iVar8 + 0x1e0) = 1;
          *(int *)(iVar15 + 0x78) = iVar8;
          if (((*(float *)(iVar15 + 0x30) != *(float *)(iVar15 + 0x130)) ||
              (*(float *)(iVar15 + 0x34) != *(float *)(iVar15 + 0x134))) ||
             ((*(float *)(iVar15 + 0x38) != *(float *)(iVar15 + 0x138) ||
              (*(float *)(iVar15 + 0x3c) != *(float *)(iVar15 + 0x13c))))) {
            (**(code **)(param_1 + 0x4de0))(param_1,iVar11);
          }
          iVar6 = iVar6 + -1;
          iVar11 = iVar11 + 0x100;
          iVar8 = iVar12;
          iVar15 = iVar15 + 0x100;
        } while (iVar6 != 0);
      }
      iVar11 = *(int *)(param_1 + 0x4dd0);
      iVar10 = iVar8 * 0x100 + iVar10;
      *(undefined4 *)(iVar11 + 0x1e0) = 1;
      *(int *)(iVar10 + 0x74) = iVar11;
      iVar11 = *(int *)(param_1 + 0x4dd4);
      *(undefined4 *)(iVar11 + 0x1e0) = 1;
      *(int *)(iVar10 + 0x78) = iVar11;
    }
  }
  if (local_30[0] == '\0') {
    uVar13 = *(undefined4 *)(param_1 + 0x486c);
    uVar16 = *(undefined4 *)(param_1 + 0x4858);
    uVar5 = (**(code **)(*(short *)(param_1 + 0x4a10) * 4 + param_1 + 0x49e0))(param_1);
    *(undefined4 *)(param_1 + 0x4858) = uVar16;
    *(undefined4 *)(param_1 + 0x486c) = uVar13;
  }
  else {
    uVar13 = *(undefined4 *)(param_1 + 0x486c);
    uVar5 = (**(code **)(*(short *)(param_1 + 0x4a10) * 4 + param_1 + 0x49e0))(param_1);
    iVar10 = *(int *)(param_1 + 0x7588);
    *(undefined4 *)(param_1 + 0x486c) = uVar13;
    iVar11 = *(int *)(param_1 + 0x758c);
    for (; iVar10 != 0; iVar10 = iVar10 + -1) {
      uVar5 = ((int (*)())_gleSubmitVertexCopy)(param_1,iVar11);
      iVar11 = iVar11 + 0x100;
    }
  }
  return uVar5;
}

/* _gleTypeSize @ 0x104128 (84 bytes) */
int _gleTypeSize(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  switch(param_2) {
  case 0x1400:
  case 0x1401:
    return 1;
  case 0x1402:
  case 0x1403:
    return 2;
  case 0x1404:
  case 0x1405:
  case 0x1406:
    return 4;
  default:
    return 8;
  }
}

/* _gleBindVertexArray @ 0x104198 (200 bytes) */
int _gleBindVertexArray(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = *(int *)(param_1 + 0x5148) + 0x5014;
  if (param_2 == 0) {
    iVar1 = *(int *)(param_1 + 0x4a64);
  }
  else {
    iVar1 = _gleLookupHashObject(iVar3,param_2);
    if (iVar1 == 0) {
      iVar1 = _gleCreateVertexArrayObject(param_1,param_2);
      _gleCreatePluginVertexArray(param_1,iVar1 + 0x10);
      _gleAddHashNameAndObject(param_1,iVar3,iVar1);
    }
  }
  *(int *)(iVar1 + 8) = *(int *)(iVar1 + 8) + 1;
  iVar4 = *(int *)(param_1 + 0x4a60);
  uVar2 = _gleSetCurrentVertexObject(param_1,iVar1);
  iVar3 = *(int *)(iVar4 + 8) + -1;
  *(int *)(iVar4 + 8) = iVar3;
  if (iVar3 == 0) {
    uVar2 = _gleFreeVertexArrayObject(param_1,iVar4);
    return uVar2;
  }
  return uVar2;
}

/* _gleReclaimVertexArrayResources @ 0x104260 (352 bytes) */
int _gleReclaimVertexArrayResources(param_1)
  int param_1;
{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  undefined4 *puVar9;
  int iVar10;
  
  iVar3 = *(int *)(param_1 + 0x5148);
  piVar8 = (int *)(iVar3 + 0x5014);
  do {
    piVar5 = piVar8 + 1;
    for (piVar8 = (int *)*piVar8; piVar8 != (int *)0x0; piVar8 = (int *)*piVar8) {
      if (piVar8[2] == 1) {
        iVar6 = 0;
        if (*(char *)(param_1 + 0x85a4) != '\0') {
          iVar7 = (int)(piVar8 + 0x118);
          puVar9 = piVar8 + 4;
          iVar10 = param_1 + 0x10000;
          do {
            piVar1 = (int *)(iVar10 + -0x777c);
            iVar6 = iVar6 + 1;
            puVar2 = (undefined4 *)(iVar10 + -0x7a54);
            iVar10 = iVar10 + 0x2e0;
            uVar4 = *puVar9;
            puVar9 = puVar9 + 1;
            (**(code **)(*piVar1 + 0x1b4))(*puVar2,uVar4);
            *(undefined4 *)(iVar7 + 4) = *(undefined4 *)(iVar7 + 4);
            *(uint *)(iVar7 + 8) = *(uint *)(iVar7 + 8) | 1;
            iVar7 = iVar7 + 0x8c;
          } while (iVar6 < (int)(uint)*(byte *)(param_1 + 0x85a4));
        }
        piVar8[0xd4] = piVar8[0xd4];
        piVar8[0xd5] = piVar8[0xd5] | 1;
      }
    }
    piVar8 = piVar5;
  } while ((int)piVar5 <= iVar3 + 0x6010);
  iVar3 = *(int *)(param_1 + 0x4a64);
  if (*(int *)(iVar3 + 8) == 1) {
    iVar6 = param_1 + 0x10000;
    iVar7 = 0;
    if (*(char *)(param_1 + 0x85a4) != '\0') {
      puVar9 = (undefined4 *)(iVar3 + 0x10);
      iVar3 = iVar3 + 0x460;
      do {
        piVar8 = (int *)(iVar6 + -0x777c);
        iVar7 = iVar7 + 1;
        puVar2 = (undefined4 *)(iVar6 + -0x7a54);
        iVar6 = iVar6 + 0x2e0;
        uVar4 = *puVar9;
        puVar9 = puVar9 + 1;
        (**(code **)(*piVar8 + 0x1b4))(*puVar2,uVar4);
        *(undefined4 *)(iVar3 + 4) = *(undefined4 *)(iVar3 + 4);
        *(uint *)(iVar3 + 8) = *(uint *)(iVar3 + 8) | 1;
        iVar3 = iVar3 + 0x8c;
      } while (iVar7 < (int)(uint)*(byte *)(param_1 + 0x85a4));
    }
  }
  return;
}

/* _gleVPFlipColors @ 0x1043c0 (404 bytes) */
int _gleVPFlipColors(param_1, param_2, param_3, param_4)
  int param_1;
  uint param_2;
  int param_3;
  uint param_4;
{
  uint uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  
  uVar1 = param_2 + param_3 * 0x100;
  if (*(char *)(param_1 + 0x316b) == '\0') {
    if (param_2 < uVar1) {
      uVar1 = (uVar1 - param_2) + 0xff >> 8;
      do {
        if (param_4 != *(byte *)(param_2 + 0x7e)) {
          uVar2 = *(undefined4 *)(param_2 + 0x30);
          uVar3 = *(undefined4 *)(param_2 + 0x34);
          uVar4 = *(undefined4 *)(param_2 + 0x38);
          uVar5 = *(undefined4 *)(param_2 + 0x3c);
          *(undefined4 *)(param_2 + 0x30) = *(undefined4 *)(param_2 + 0x20);
          *(undefined4 *)(param_2 + 0x34) = *(undefined4 *)(param_2 + 0x24);
          *(undefined4 *)(param_2 + 0x38) = *(undefined4 *)(param_2 + 0x28);
          *(undefined4 *)(param_2 + 0x3c) = *(undefined4 *)(param_2 + 0x2c);
          *(char *)(param_2 + 0x7e) = (char)param_4;
          *(undefined4 *)(param_2 + 0x20) = uVar2;
          *(undefined4 *)(param_2 + 0x24) = uVar3;
          *(undefined4 *)(param_2 + 0x28) = uVar4;
          *(undefined4 *)(param_2 + 0x2c) = uVar5;
        }
        param_2 = param_2 + 0x100;
        uVar1 = uVar1 - 1;
      } while (uVar1 != 0);
    }
  }
  else if (param_2 < uVar1) {
    uVar1 = (uVar1 - param_2) + 0xff >> 8;
    do {
      if (param_4 != *(byte *)(param_2 + 0x7e)) {
        uVar6 = *(undefined4 *)(param_2 + 0x30);
        uVar7 = *(undefined4 *)(param_2 + 0x34);
        uVar8 = *(undefined4 *)(param_2 + 0x38);
        uVar2 = *(undefined4 *)(param_2 + 0x3c);
        uVar4 = *(undefined4 *)(param_2 + 0x50);
        uVar5 = *(undefined4 *)(param_2 + 0x54);
        uVar3 = *(undefined4 *)(param_2 + 0x58);
        *(undefined4 *)(param_2 + 0x30) = *(undefined4 *)(param_2 + 0x20);
        *(undefined4 *)(param_2 + 0x34) = *(undefined4 *)(param_2 + 0x24);
        *(undefined4 *)(param_2 + 0x38) = *(undefined4 *)(param_2 + 0x28);
        *(undefined4 *)(param_2 + 0x3c) = *(undefined4 *)(param_2 + 0x2c);
        *(undefined4 *)(param_2 + 0x50) = *(undefined4 *)(param_2 + 0x40);
        *(undefined4 *)(param_2 + 0x54) = *(undefined4 *)(param_2 + 0x44);
        *(undefined4 *)(param_2 + 0x58) = *(undefined4 *)(param_2 + 0x48);
        *(char *)(param_2 + 0x7e) = (char)param_4;
        *(undefined4 *)(param_2 + 0x20) = uVar6;
        *(undefined4 *)(param_2 + 0x24) = uVar7;
        *(undefined4 *)(param_2 + 0x28) = uVar8;
        *(undefined4 *)(param_2 + 0x2c) = uVar2;
        *(undefined4 *)(param_2 + 0x40) = uVar4;
        *(undefined4 *)(param_2 + 0x44) = uVar5;
        *(undefined4 *)(param_2 + 0x48) = uVar3;
      }
      param_2 = param_2 + 0x100;
      uVar1 = uVar1 - 1;
    } while (uVar1 != 0);
  }
  return;
}

/* _gleVPRenderPoints @ 0x104554 (324 bytes) */
int _gleVPRenderPoints(param_1)
  int param_1;
{
  int iVar1;
  uint uVar2;
  code *UNRECOVERED_JUMPTABLE;
  undefined4 uVar3;
  uint uVar4;
  undefined4 uVar5;
  
  iVar1 = ((int (*)())_gleTexEnableBits)(param_1);
  if ((((int)*(short *)(param_1 + 0x487c) == 0) ||
      (uVar4 = (uint)(*(int *)(param_1 + 0x4858) - *(int *)(param_1 + 0x4854)) /
               (uint)(int)*(short *)(param_1 + 0x487c), (int)uVar4 < 1)) ||
     (uVar2 = _gleVPEmulate(param_1,uVar4), (uVar2 & 0xff00) != 0)) {
    return;
  }
  uVar5 = *(undefined4 *)(param_1 + 0x4864);
  if (((uVar2 & 0xff) == 0) && (*(char *)(param_1 + 0x4e18) == '\0')) {
    if (iVar1 != 0) {
      (**(code **)(param_1 + 0x506c))(param_1,uVar5,uVar4,0);
    }
    UNRECOVERED_JUMPTABLE = *(code **)(param_1 + 0x46b0);
    uVar3 = uVar5;
  }
  else {
    if (iVar1 != 0) {
      (**(code **)(param_1 + 0x5074))(param_1,uVar5,uVar4,0);
    }
    uVar3 = *(undefined4 *)(param_1 + 0x4870);
    uVar4 = _gleClipPoints(param_1,uVar5,uVar4,uVar3);
    if (uVar4 == 0) {
      return;
    }
    if ((*(char *)(param_1 + 0x4e18) != '\0') &&
       (uVar4 = _gleClipPointsPlane(param_1,uVar3,uVar4), uVar4 == 0)) {
      return;
    }
    UNRECOVERED_JUMPTABLE = *(code **)(param_1 + 0x46d8);
  }
                    
                    
  (*UNRECOVERED_JUMPTABLE)(*(undefined4 *)(param_1 + 0x4688),uVar3,uVar4);
  return;
}

/* _gleVPRenderLines @ 0x104698 (420 bytes) */
int _gleVPRenderLines(param_1)
  int param_1;
{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint *puVar4;
  uint uVar5;
  uint uVar6;
  uint *puVar7;
  double extraout_f1;
  double fparam_1;
  
  iVar2 = ((int (*)())_gleTexEnableBits)(param_1);
  if ((((int)*(short *)(param_1 + 0x487c) != 0) &&
      (uVar5 = (uint)(*(int *)(param_1 + 0x4858) - *(int *)(param_1 + 0x4854)) /
               (uint)(int)*(short *)(param_1 + 0x487c), 1 < (int)uVar5)) &&
     (uVar3 = _gleVPEmulate(param_1,uVar5), (uVar3 & 0xff00) == 0)) {
    uVar6 = *(uint *)(param_1 + 0x4864);
    if (((uVar3 & 0xff) == 0) && (*(char *)(param_1 + 0x4e18) == '\0')) {
      if (iVar2 != 0) {
        (**(code **)(param_1 + 0x506c))(param_1,uVar6,uVar5,0);
      }
                    
                    
      (**(code **)(param_1 + 0x46b4))(*(undefined4 *)(param_1 + 0x4688),uVar6,uVar5);
      return;
    }
    fparam_1 = extraout_f1;
    if (iVar2 != 0) {
      fparam_1 = (double)(**(code **)(param_1 + 0x5074))(param_1,uVar6,uVar5,0);
    }
    uVar1 = uVar6 + uVar5 * 0x100;
    puVar7 = *(uint **)(param_1 + 0x4870);
    if (uVar6 < uVar1) {
      uVar1 = (uVar1 - uVar6) + 0xff >> 8;
      puVar4 = puVar7;
      do {
        *puVar4 = uVar6;
        uVar6 = uVar6 + 0x100;
        puVar4 = puVar4 + 1;
        uVar1 = uVar1 - 1;
      } while (uVar1 != 0);
    }
    if ((*(char *)(param_1 + 0x4e18) != '\0') &&
       (uVar5 = ((int (*)())_gleClipLinesPlane)(param_1,puVar7,uVar5,fparam_1), uVar5 == 0)) {
      return;
    }
    if (((uVar3 & 0xff) == 0) ||
       (uVar5 = _gleClipLines(param_1,puVar7,uVar5,uVar3 & 0xff), uVar5 != 0)) {
                    
                    
      (**(code **)(param_1 + 0x46dc))(*(undefined4 *)(param_1 + 0x4688),puVar7,uVar5,2);
      return;
    }
  }
  return;
}

/* _gleVPRenderLineStrip @ 0x10483c (436 bytes) */
int _gleVPRenderLineStrip(param_1)
  int param_1;
{
  char cVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  code *UNRECOVERED_JUMPTABLE;
  uint *puVar5;
  uint *puVar6;
  uint uVar7;
  void *pvVar8;
  uint *puVar9;
  double extraout_f1;
  double fparam_1;
  double extraout_f1_00;
  
  iVar3 = ((int (*)())_gleTexEnableBits)(param_1);
  if ((((int)*(short *)(param_1 + 0x487c) == 0) ||
      (uVar7 = (uint)(*(int *)(param_1 + 0x4858) - *(int *)(param_1 + 0x4854)) /
               (uint)(int)*(short *)(param_1 + 0x487c), (int)uVar7 < 2)) ||
     (uVar4 = _gleVPEmulate(param_1,uVar7), (uVar4 & 0xff00) != 0)) {
    return;
  }
  puVar9 = *(uint **)(param_1 + 0x4864);
  if (((uVar4 & 0xff) == 0) && (*(char *)(param_1 + 0x4e18) == '\0')) {
    if (iVar3 != 0) {
      (**(code **)(param_1 + 0x506c))(param_1,puVar9,uVar7,0);
    }
    cVar1 = *(char *)(param_1 + 0x4a18);
    UNRECOVERED_JUMPTABLE = *(code **)(param_1 + 0x46b8);
    puVar5 = puVar9;
  }
  else {
    fparam_1 = extraout_f1;
    if (iVar3 != 0) {
      fparam_1 = (double)(**(code **)(param_1 + 0x5074))(param_1,puVar9,uVar7,0);
    }
    puVar5 = *(uint **)(param_1 + 0x4870);
    pvVar8 = *(void **)(param_1 + 0x4854);
    puVar2 = puVar9;
    puVar6 = puVar5;
    while (puVar2 < puVar9 + uVar7 * 0x40 + -0x40) {
      *puVar6 = (uint)puVar2;
      _memcpy(pvVar8,puVar2 + 0x40,0x100);
      puVar6[1] = (uint)pvVar8;
      pvVar8 = (void *)((int)pvVar8 + 0x100);
      puVar6 = puVar6 + 2;
      puVar2 = puVar2 + 0x40;
      fparam_1 = extraout_f1_00;
    }
    uVar7 = (int)puVar6 - (int)puVar5 >> 2;
    if ((*(char *)(param_1 + 0x4e18) != '\0') &&
       (uVar7 = ((int (*)())_gleClipLinesPlane)(param_1,puVar5,uVar7,fparam_1), uVar7 == 0)) {
      return;
    }
    if (((uVar4 & 0xff) != 0) &&
       (uVar7 = _gleClipLines(param_1,puVar5,uVar7,uVar4 & 0xff), uVar7 == 0)) {
      return;
    }
    cVar1 = *(char *)(param_1 + 0x4a18);
    UNRECOVERED_JUMPTABLE = *(code **)(param_1 + 0x46dc);
  }
                    
                    
  (*UNRECOVERED_JUMPTABLE)(*(undefined4 *)(param_1 + 0x4688),puVar5,uVar7,cVar1 == '\0');
  return;
}

/* _gleVPRenderLineLoop @ 0x1049f0 (540 bytes) */
int _gleVPRenderLineLoop(param_1)
  int param_1;
{
  char cVar1;
  int iVar2;
  uint *puVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  short sVar8;
  int iVar9;
  code *UNRECOVERED_JUMPTABLE;
  uint *puVar10;
  uint *puVar11;
  uint uVar12;
  int iVar13;
  uint *puVar14;
  void *pvVar15;
  double extraout_f1;
  double fparam_1;
  double extraout_f1_00;
  
  iVar4 = ((int (*)())_gleTexEnableBits)(param_1);
  sVar8 = *(short *)(param_1 + 0x487c);
  iVar13 = *(int *)(param_1 + 0x4854);
  if ((int)sVar8 != 0) {
    iVar6 = *(int *)(param_1 + 0x4858);
    uVar12 = (uint)(iVar6 - iVar13) / (uint)(int)sVar8;
    if (*(short *)(param_1 + 0x4a10) < 0) {
      if ((int)uVar12 < 1) {
        return;
      }
      iVar7 = iVar13 + -0x100;
      if (*(char *)(param_1 + 0x4a18) == '\0') {
        iVar7 = iVar13;
      }
      iVar9 = 0;
      iVar13 = (int)sVar8 >> 3;
      if (0 < iVar13) {
        do {
          iVar2 = iVar9 * 8;
          iVar9 = iVar9 + 1;
          *(undefined8 *)(iVar2 + iVar6) = *(undefined8 *)(iVar2 + iVar7);
          iVar13 = iVar13 + -1;
        } while (iVar13 != 0);
        sVar8 = *(short *)(param_1 + 0x487c);
      }
      uVar12 = uVar12 + 1;
      *(int *)(param_1 + 0x4858) = iVar6 + sVar8;
    }
    uVar5 = _gleVPEmulate(param_1,uVar12);
    if ((uVar5 & 0xff00) == 0) {
      puVar14 = *(uint **)(param_1 + 0x4864);
      if (((uVar5 & 0xff) == 0) && (*(char *)(param_1 + 0x4e18) == '\0')) {
        if (iVar4 != 0) {
          (**(code **)(param_1 + 0x506c))(param_1,puVar14,uVar12,0);
        }
        cVar1 = *(char *)(param_1 + 0x4a18);
        UNRECOVERED_JUMPTABLE = *(code **)(param_1 + 0x46b8);
        puVar10 = puVar14;
      }
      else {
        fparam_1 = extraout_f1;
        if (iVar4 != 0) {
          fparam_1 = (double)(**(code **)(param_1 + 0x5074))(param_1,puVar14,uVar12,0);
        }
        puVar10 = *(uint **)(param_1 + 0x4870);
        pvVar15 = *(void **)(param_1 + 0x4854);
        puVar3 = puVar14;
        puVar11 = puVar10;
        while (puVar3 < puVar14 + uVar12 * 0x40 + -0x40) {
          *puVar11 = (uint)puVar3;
          _memcpy(pvVar15,puVar3 + 0x40,0x100);
          puVar11[1] = (uint)pvVar15;
          pvVar15 = (void *)((int)pvVar15 + 0x100);
          puVar11 = puVar11 + 2;
          puVar3 = puVar3 + 0x40;
          fparam_1 = extraout_f1_00;
        }
        uVar12 = (int)puVar11 - (int)puVar10 >> 2;
        if ((*(char *)(param_1 + 0x4e18) != '\0') &&
           (uVar12 = ((int (*)())_gleClipLinesPlane)(param_1,puVar10,uVar12,fparam_1), uVar12 == 0)) {
          return;
        }
        if (((uVar5 & 0xff) != 0) &&
           (uVar12 = _gleClipLines(param_1,puVar10,uVar12,uVar5 & 0xff), uVar12 == 0)) {
          return;
        }
        cVar1 = *(char *)(param_1 + 0x4a18);
        UNRECOVERED_JUMPTABLE = *(code **)(param_1 + 0x46dc);
      }
                    
                    
      (*UNRECOVERED_JUMPTABLE)(*(undefined4 *)(param_1 + 0x4688),puVar10,uVar12,cVar1 == '\0');
      return;
    }
  }
  return;
}

/* FUN_00104c10 @ 0x104c10 (876 bytes) */
int FUN_00104c10(param_1)
  int param_1;
{
  byte bVar1;
  char cVar2;
  ushort uVar3;
  bool bVar4;
  uint *puVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  uint *puVar9;
  uint *puVar10;
  int iVar11;
  uint *puVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
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
  int local_50;
  int local_4c [5];
  
  iVar11 = -1;
  iVar6 = ((int (*)())_gleTexEnableBits)(param_1);
  bVar1 = *(byte *)(param_1 + 0x4666);
  cVar2 = *(char *)(param_1 + 0x34de);
  if ((((int)*(short *)(param_1 + 0x487c) != 0) &&
      (uVar13 = (uint)(*(int *)(param_1 + 0x4858) - *(int *)(param_1 + 0x4854)) /
                (uint)(int)*(short *)(param_1 + 0x487c), 2 < (int)uVar13)) &&
     (uVar7 = _gleVPEmulate(param_1,uVar13), (uVar7 & 0xff00) == 0)) {
    uVar16 = *(uint *)(param_1 + 0x4864);
    if (((uVar7 & 0xff) == 0) && (*(char *)(param_1 + 0x4e18) == '\0')) {
      dVar17 = extraout_f1;
      if (iVar6 != 0) {
        dVar17 = (double)(**(code **)(param_1 + 0x506c))(param_1,uVar16,uVar13,0);
      }
      if (cVar2 == '\0') {
        (**(code **)(param_1 + 0x46c4))
                  (*(undefined4 *)(param_1 + 0x4688),uVar16,uVar13,
                   *(ushort *)(param_1 + 0x34d0) - 0x1b00);
      }
      else {
        uVar13 = (uVar16 + uVar13 * 0x100) - 0x300;
        do {
          bVar4 = false;
          iVar6 = 0;
          uVar7 = uVar16;
          uVar15 = uVar16;
          if (uVar16 <= uVar13) {
            do {
              iVar8 = ((undefined4 (*)())_gleCullTriangle)(param_1,uVar16,uVar16 + 0x100,uVar16 + 0x200,0,&local_50,
                                       dVar17,in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8,
                                       in_stack_ffffff78,in_stack_ffffff80);
              dVar17 = extraout_f1_00;
              if (iVar8 == 0) {
                if (iVar11 != local_50) {
                  bVar4 = true;
                }
                if ((bVar4) && (uVar7 = uVar16, 0 < iVar6)) break;
                iVar6 = iVar6 + 3;
                iVar11 = local_50;
                uVar14 = uVar15;
              }
              else {
                uVar14 = uVar16 + 0x300;
                uVar7 = uVar14;
                if (0 < iVar6) break;
              }
              uVar16 = uVar16 + 0x300;
              uVar7 = uVar16;
              uVar15 = uVar14;
            } while (uVar16 <= uVar13);
            if (2 < iVar6) {
              if ((int)-(uint)bVar1 < 0) {
                ((int (*)())_gleVPFlipColors)(param_1,uVar15,iVar6,iVar11);
              }
              if (iVar11 == 0) {
                uVar3 = *(ushort *)(param_1 + 0x34d0);
              }
              else {
                uVar3 = *(ushort *)(param_1 + 0x34d2);
              }
              dVar17 = (double)(**(code **)(param_1 + 0x46c4))
                                         (*(undefined4 *)(param_1 + 0x4688),uVar15,iVar6,
                                          uVar3 - 0x1b00);
            }
          }
          uVar16 = uVar7;
        } while (uVar7 <= uVar13);
      }
    }
    else {
      dVar17 = extraout_f1;
      if (iVar6 != 0) {
        dVar17 = (double)(**(code **)(param_1 + 0x5074))(param_1,uVar16,uVar13,0);
      }
      puVar12 = *(uint **)(param_1 + 0x4870);
      uVar13 = (uVar16 + uVar13 * 0x100) - 0x300;
      puVar9 = *(uint **)(param_1 + 0x4874);
      if (uVar16 <= uVar13) {
        do {
          puVar12[1] = uVar16 + 0x100;
          puVar12[2] = uVar16 + 0x200;
          *puVar12 = uVar16;
          *(undefined4 *)(param_1 + 0x4858) = *(undefined4 *)(param_1 + 0x4854);
          puVar10 = puVar9;
          puVar5 = puVar12;
          iVar11 = 3;
          if ((*(char *)(param_1 + 0x4e18) == '\0') ||
             (dVar17 = (double)((double (*)())_gleClipPolyPlane)(param_1,puVar12,3,puVar9,local_4c,dVar17,in_f2,
                                                 in_f3,in_f4,in_f5,in_f6,in_f7,in_f8,
                                                 in_stack_ffffff78,in_stack_ffffff80),
             puVar10 = puVar12, puVar5 = puVar9, iVar11 = local_4c[0], local_4c[0] != 0)) {
            puVar12 = puVar5;
            puVar9 = puVar10;
            if ((uVar7 & 0xff) != 0) {
              dVar17 = (double)_gleClipPoly(param_1,puVar12,iVar11,uVar7 & 0xff,puVar10,local_4c,1);
              if (local_4c[0] == 0) goto LAB_00104f54;
              if (0 < local_4c[0]) {
                puVar9 = puVar12;
                puVar12 = puVar10;
                iVar11 = local_4c[0];
              }
            }
            if ((cVar2 == '\0') ||
               (iVar6 = _gleCullPolygonPtrStack(param_1,puVar12,iVar11,&local_50),
               dVar17 = extraout_f1_01, iVar6 == 0)) {
              iVar6 = local_50;
              if (((int)-(uint)bVar1 < 0) && (puVar10 = puVar12, iVar8 = iVar11, 0 < iVar11)) {
                do {
                  ((int (*)())_gleVPFlipColors)(param_1,*puVar10,1,iVar6);
                  iVar8 = iVar8 + -1;
                  puVar10 = puVar10 + 1;
                } while (iVar8 != 0);
              }
              if (iVar6 == 0) {
                uVar3 = *(ushort *)(param_1 + 0x34d0);
              }
              else {
                uVar3 = *(ushort *)(param_1 + 0x34d2);
              }
              dVar17 = (double)(**(code **)(param_1 + 0x46e0))
                                         (*(undefined4 *)(param_1 + 0x4688),puVar12,iVar11,
                                          uVar3 - 0x1b00);
            }
          }
LAB_00104f54:
          uVar16 = uVar16 + 0x300;
        } while (uVar16 <= uVar13);
      }
    }
  }
  return;
}

/* FUN_00104f80 @ 0x104f80 (1040 bytes) */
int FUN_00104f80(param_1)
  int param_1;
{
  byte bVar1;
  char cVar2;
  ushort uVar3;
  bool bVar4;
  uint uVar5;
  uint *puVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  uint *puVar13;
  uint *puVar14;
  int *piVar15;
  uint uVar16;
  uint *puVar17;
  uint uVar18;
  uint uVar19;
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
  
  iVar11 = -1;
  iVar7 = ((int (*)())_gleTexEnableBits)(param_1);
  bVar1 = *(byte *)(param_1 + 0x4666);
  cVar2 = *(char *)(param_1 + 0x34de);
  uVar12 = 0;
  if ((((int)*(short *)(param_1 + 0x487c) != 0) &&
      (uVar18 = (uint)(*(int *)(param_1 + 0x4858) - *(int *)(param_1 + 0x4854)) /
                (uint)(int)*(short *)(param_1 + 0x487c), 2 < (int)uVar18)) &&
     (uVar8 = _gleVPEmulate(param_1,uVar18), (uVar8 & 0xff00) == 0)) {
    uVar20 = *(uint *)(param_1 + 0x4864);
    if (((uVar8 & 0xff) == 0) && (*(char *)(param_1 + 0x4e18) == '\0')) {
      dVar21 = extraout_f1;
      if (iVar7 != 0) {
        dVar21 = (double)(**(code **)(param_1 + 0x506c))(param_1,uVar20,uVar18,0);
      }
      if (cVar2 == '\0') {
        (**(code **)(param_1 + 0x46cc))
                  (*(undefined4 *)(param_1 + 0x4688),uVar20,uVar18,
                   *(ushort *)(param_1 + 0x34d0) - 0x1b00);
      }
      else {
        piVar15 = *(int **)(param_1 + 0x4870);
        uVar8 = 0;
        uVar18 = (uVar20 + uVar18 * 0x100) - 0x300;
        do {
          bVar4 = false;
          iVar7 = 0;
          uVar10 = uVar8;
          uVar5 = uVar20;
          while (uVar8 = uVar10, uVar20 <= uVar18) {
            uVar19 = uVar20 + 0x100;
            iVar9 = ((undefined4 (*)())_gleCullTriangle)(param_1,uVar20,uVar19,uVar20 + 0x200,uVar10,&local_50,dVar21,
                                     in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8,in_stack_ffffff78,
                                     in_stack_ffffff80);
            dVar21 = extraout_f1_00;
            if (iVar9 == 0) {
              if (iVar11 != local_50) {
                bVar4 = true;
              }
              if ((bVar4) && (0 < iVar7)) break;
              if (iVar7 == 0) {
                uVar12 = uVar10;
              }
              iVar7 = iVar7 + 1;
              iVar11 = local_50;
              uVar16 = uVar5;
            }
            else {
              uVar16 = uVar19;
              uVar8 = uVar10 ^ 1;
              uVar20 = uVar19;
              if (0 < iVar7) break;
            }
            uVar10 = uVar10 ^ 1;
            uVar20 = uVar19;
            uVar5 = uVar16;
          }
          iVar9 = iVar7 + 2;
          if (2 < iVar9) {
            if ((int)-(uint)bVar1 < 0) {
              ((int (*)())_gleVPFlipColors)(param_1,uVar5,iVar9,iVar11);
            }
            uVar10 = uVar5;
            if (uVar12 != 0) {
              uVar10 = uVar5 + 0x100;
              *piVar15 = uVar5 + 0x200;
              piVar15[2] = uVar5;
              piVar15[1] = uVar10;
              if (iVar11 != 0) {
                uVar3 = *(ushort *)(param_1 + 0x34d2);
              }
              else {
                uVar3 = *(ushort *)(param_1 + 0x34d0);
              }
              iVar9 = iVar7 + 1;
              dVar21 = (double)(**(code **)(param_1 + 0x46e0))
                                         (*(undefined4 *)(param_1 + 0x4688),piVar15,3,uVar3 - 0x1b00
                                         );
              if (iVar9 < 3) goto LAB_001051b4;
            }
            if (iVar11 != 0) {
              uVar3 = *(ushort *)(param_1 + 0x34d2);
            }
            else {
              uVar3 = *(ushort *)(param_1 + 0x34d0);
            }
            dVar21 = (double)(**(code **)(param_1 + 0x46cc))
                                       (*(undefined4 *)(param_1 + 0x4688),uVar10,iVar9,
                                        uVar3 - 0x1b00);
          }
LAB_001051b4: ;
        } while (uVar20 <= uVar18);
      }
    }
    else {
      dVar21 = extraout_f1;
      if (iVar7 != 0) {
        dVar21 = (double)(**(code **)(param_1 + 0x5074))(param_1,uVar20,uVar18,0);
      }
      puVar17 = *(uint **)(param_1 + 0x4870);
      uVar12 = (uVar20 + uVar18 * 0x100) - 0x300;
      puVar13 = *(uint **)(param_1 + 0x4874);
      if (uVar20 <= uVar12) {
        bVar4 = false;
        do {
          bVar4 = !bVar4;
          if (bVar4) {
            puVar17[2] = uVar20 + 0x200;
            *puVar17 = uVar20;
          }
          else {
            *puVar17 = uVar20 + 0x200;
            puVar17[2] = uVar20;
          }
          uVar20 = uVar20 + 0x100;
          puVar17[1] = uVar20;
          *(undefined4 *)(param_1 + 0x4858) = *(undefined4 *)(param_1 + 0x4854);
          puVar14 = puVar13;
          puVar6 = puVar17;
          iVar11 = 3;
          if ((*(char *)(param_1 + 0x4e18) == '\0') ||
             (dVar21 = (double)((double (*)())_gleClipPolyPlane)(param_1,puVar17,3,puVar13,local_4c,dVar21,in_f2,
                                                 in_f3,in_f4,in_f5,in_f6,in_f7,in_f8,
                                                 in_stack_ffffff78,in_stack_ffffff80),
             puVar14 = puVar17, puVar6 = puVar13, iVar11 = local_4c[0], local_4c[0] != 0)) {
            puVar17 = puVar6;
            puVar13 = puVar14;
            if ((uVar8 & 0xff) != 0) {
              dVar21 = (double)_gleClipPoly(param_1,puVar17,iVar11,uVar8 & 0xff,puVar14,local_4c,1);
              if (local_4c[0] == 0) goto LAB_00105368;
              if (0 < local_4c[0]) {
                puVar13 = puVar17;
                puVar17 = puVar14;
                iVar11 = local_4c[0];
              }
            }
            if ((cVar2 == '\0') ||
               (iVar7 = _gleCullPolygonPtrStack(param_1,puVar17,iVar11,&local_50),
               dVar21 = extraout_f1_01, iVar7 == 0)) {
              iVar7 = local_50;
              if (((int)-(uint)bVar1 < 0) && (puVar14 = puVar17, iVar9 = iVar11, 0 < iVar11)) {
                do {
                  ((int (*)())_gleVPFlipColors)(param_1,*puVar14,1,iVar7);
                  iVar9 = iVar9 + -1;
                  puVar14 = puVar14 + 1;
                } while (iVar9 != 0);
              }
              if (iVar7 == 0) {
                uVar3 = *(ushort *)(param_1 + 0x34d0);
              }
              else {
                uVar3 = *(ushort *)(param_1 + 0x34d2);
              }
              dVar21 = (double)(**(code **)(param_1 + 0x46e0))
                                         (*(undefined4 *)(param_1 + 0x4688),puVar17,iVar11,
                                          uVar3 - 0x1b00);
            }
          }
LAB_00105368: ;
        } while (uVar20 <= uVar12);
      }
    }
  }
  return;
}

/* FUN_00105394 @ 0x105394 (888 bytes) */
int FUN_00105394(param_1)
  int param_1;
{
  byte bVar1;
  char cVar2;
  ushort uVar3;
  bool bVar4;
  int *piVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int *piVar9;
  int *piVar10;
  int iVar11;
  uint uVar12;
  int iVar13;
  int *piVar14;
  uint uVar15;
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
  int local_50;
  int local_4c [6];
  
  iVar11 = -1;
  iVar6 = ((int (*)())_gleTexEnableBits)(param_1);
  bVar1 = *(byte *)(param_1 + 0x4666);
  cVar2 = *(char *)(param_1 + 0x34de);
  if ((((int)*(short *)(param_1 + 0x487c) != 0) &&
      (uVar15 = (uint)(*(int *)(param_1 + 0x4858) - *(int *)(param_1 + 0x4854)) /
                (uint)(int)*(short *)(param_1 + 0x487c), 2 < (int)uVar15)) &&
     (uVar7 = _gleVPEmulate(param_1,uVar15), (uVar7 & 0xff00) == 0)) {
    iVar13 = *(int *)(param_1 + 0x4864);
    if (((uVar7 & 0xff) == 0) && (*(char *)(param_1 + 0x4e18) == '\0')) {
      dVar17 = extraout_f1;
      if (iVar6 != 0) {
        dVar17 = (double)(**(code **)(param_1 + 0x506c))(param_1,iVar13,uVar15,0);
      }
      if (cVar2 == '\0') {
        (**(code **)(param_1 + 0x46c8))
                  (*(undefined4 *)(param_1 + 0x4688),iVar13,iVar13 + 0x100,uVar15 - 1,
                   *(ushort *)(param_1 + 0x34d0) - 0x1b00);
      }
      else {
        uVar7 = iVar13 + 0x100;
        uVar15 = (iVar13 + uVar15 * 0x100) - 0x200;
        do {
          bVar4 = false;
          iVar6 = 0;
          uVar16 = uVar7;
          do {
            while( true ) {
              uVar12 = uVar16;
              if (uVar15 < uVar7) goto LAB_00105508;
              uVar16 = uVar7 + 0x100;
              iVar8 = ((undefined4 (*)())_gleCullTriangle)(param_1,iVar13,uVar7,uVar16,0,&local_50,dVar17,in_f2,in_f3,
                                       in_f4,in_f5,in_f6,in_f7,in_f8,in_stack_ffffff78,
                                       in_stack_ffffff80);
              dVar17 = extraout_f1_00;
              if (iVar8 != 0) break;
              if (iVar11 != local_50) {
                bVar4 = true;
              }
              if ((bVar4) && (0 < iVar6)) goto LAB_00105508;
              iVar6 = iVar6 + 1;
              iVar11 = local_50;
              uVar7 = uVar16;
              uVar16 = uVar12;
            }
            uVar7 = uVar16;
          } while (iVar6 < 1);
LAB_00105508:
          iVar6 = iVar6 + 1;
          if (1 < iVar6) {
            if ((int)-(uint)bVar1 < 0) {
              ((int (*)())_gleVPFlipColors)(param_1,uVar12,iVar6,iVar11);
            }
            if (iVar11 == 0) {
              uVar3 = *(ushort *)(param_1 + 0x34d0);
            }
            else {
              uVar3 = *(ushort *)(param_1 + 0x34d2);
            }
            dVar17 = (double)(**(code **)(param_1 + 0x46c8))
                                       (*(undefined4 *)(param_1 + 0x4688),iVar13,uVar12,iVar6,
                                        uVar3 - 0x1b00);
          }
        } while (uVar7 <= uVar15);
      }
    }
    else {
      dVar17 = extraout_f1;
      if (iVar6 != 0) {
        dVar17 = (double)(**(code **)(param_1 + 0x5074))(param_1,iVar13,uVar15,0);
      }
      piVar14 = *(int **)(param_1 + 0x4870);
      uVar15 = (iVar13 + uVar15 * 0x100) - 0x200;
      piVar9 = *(int **)(param_1 + 0x4874);
      if (iVar13 + 0x100U <= uVar15) {
        uVar16 = iVar13 + 0x100U;
        do {
          uVar12 = uVar16 + 0x100;
          *piVar14 = iVar13;
          piVar14[1] = uVar16;
          piVar14[2] = uVar12;
          *(undefined4 *)(param_1 + 0x4858) = *(undefined4 *)(param_1 + 0x4854);
          piVar10 = piVar9;
          piVar5 = piVar14;
          iVar11 = 3;
          if ((*(char *)(param_1 + 0x4e18) == '\0') ||
             (dVar17 = (double)((double (*)())_gleClipPolyPlane)(param_1,piVar14,3,piVar9,local_4c,dVar17,in_f2,
                                                 in_f3,in_f4,in_f5,in_f6,in_f7,in_f8,
                                                 in_stack_ffffff78,in_stack_ffffff80),
             piVar10 = piVar14, piVar5 = piVar9, iVar11 = local_4c[0], local_4c[0] != 0)) {
            piVar14 = piVar5;
            piVar9 = piVar10;
            if ((uVar7 & 0xff) != 0) {
              dVar17 = (double)_gleClipPoly(param_1,piVar14,iVar11,uVar7 & 0xff,piVar10,local_4c,1);
              if (local_4c[0] == 0) goto LAB_001056e4;
              if (0 < local_4c[0]) {
                piVar9 = piVar14;
                piVar14 = piVar10;
                iVar11 = local_4c[0];
              }
            }
            if ((cVar2 == '\0') ||
               (iVar6 = _gleCullPolygonPtrStack(param_1,piVar14,iVar11,&local_50),
               dVar17 = extraout_f1_01, iVar6 == 0)) {
              iVar6 = local_50;
              if (((int)-(uint)bVar1 < 0) && (piVar10 = piVar14, iVar8 = iVar11, 0 < iVar11)) {
                do {
                  ((int (*)())_gleVPFlipColors)(param_1,*piVar10,1,iVar6);
                  iVar8 = iVar8 + -1;
                  piVar10 = piVar10 + 1;
                } while (iVar8 != 0);
              }
              if (iVar6 == 0) {
                uVar3 = *(ushort *)(param_1 + 0x34d0);
              }
              else {
                uVar3 = *(ushort *)(param_1 + 0x34d2);
              }
              dVar17 = (double)(**(code **)(param_1 + 0x46e0))
                                         (*(undefined4 *)(param_1 + 0x4688),piVar14,iVar11,
                                          uVar3 - 0x1b00);
            }
          }
LAB_001056e4:
          uVar16 = uVar12;
        } while (uVar12 <= uVar15);
      }
    }
  }
  return;
}

/* FUN_00105710 @ 0x105710 (884 bytes) */
int FUN_00105710(param_1)
  int param_1;
{
  byte bVar1;
  char cVar2;
  ushort uVar3;
  bool bVar4;
  uint *puVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  uint *puVar9;
  uint *puVar10;
  int iVar11;
  uint *puVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
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
  int local_4c [5];
  
  iVar11 = -1;
  iVar6 = ((int (*)())_gleTexEnableBits)(param_1);
  bVar1 = *(byte *)(param_1 + 0x4666);
  cVar2 = *(char *)(param_1 + 0x34de);
  if ((((int)*(short *)(param_1 + 0x487c) != 0) &&
      (uVar13 = (uint)(*(int *)(param_1 + 0x4858) - *(int *)(param_1 + 0x4854)) /
                (uint)(int)*(short *)(param_1 + 0x487c), 3 < (int)uVar13)) &&
     (uVar7 = _gleVPEmulate(param_1,uVar13), (uVar7 & 0xff00) == 0)) {
    uVar16 = *(uint *)(param_1 + 0x4864);
    if (((uVar7 & 0xff) == 0) && (*(char *)(param_1 + 0x4e18) == '\0')) {
      dVar17 = extraout_f1;
      if (iVar6 != 0) {
        dVar17 = (double)(**(code **)(param_1 + 0x506c))(param_1,uVar16,uVar13,0);
      }
      if (cVar2 == '\0') {
        (**(code **)(param_1 + 0x46d0))
                  (*(undefined4 *)(param_1 + 0x4688),uVar16,uVar13,
                   *(ushort *)(param_1 + 0x34d0) - 0x1b00);
      }
      else {
        uVar13 = (uVar16 + uVar13 * 0x100) - 0x400;
        do {
          bVar4 = false;
          iVar6 = 0;
          uVar7 = uVar16;
          uVar15 = uVar16;
          if (uVar16 <= uVar13) {
            do {
              iVar8 = ((undefined4 (*)())_gleCullQuad)(param_1,uVar16,uVar16 + 0x100,uVar16 + 0x200,uVar16 + 0x300,
                                   &local_50,dVar17,in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8,
                                   in_stack_ffffff78,in_stack_ffffff80,in_stack_ffffff88);
              dVar17 = extraout_f1_00;
              if (iVar8 == 0) {
                if (iVar11 != local_50) {
                  bVar4 = true;
                }
                if ((bVar4) && (uVar7 = uVar16, 0 < iVar6)) break;
                iVar6 = iVar6 + 4;
                iVar11 = local_50;
                uVar14 = uVar15;
              }
              else {
                uVar14 = uVar16 + 0x400;
                uVar7 = uVar14;
                if (0 < iVar6) break;
              }
              uVar16 = uVar16 + 0x400;
              uVar7 = uVar16;
              uVar15 = uVar14;
            } while (uVar16 <= uVar13);
            if (3 < iVar6) {
              if ((int)-(uint)bVar1 < 0) {
                ((int (*)())_gleVPFlipColors)(param_1,uVar15,iVar6,iVar11);
              }
              if (iVar11 == 0) {
                uVar3 = *(ushort *)(param_1 + 0x34d0);
              }
              else {
                uVar3 = *(ushort *)(param_1 + 0x34d2);
              }
              dVar17 = (double)(**(code **)(param_1 + 0x46d0))
                                         (*(undefined4 *)(param_1 + 0x4688),uVar15,iVar6,
                                          uVar3 - 0x1b00);
            }
          }
          uVar16 = uVar7;
        } while (uVar7 <= uVar13);
      }
    }
    else {
      dVar17 = extraout_f1;
      if (iVar6 != 0) {
        dVar17 = (double)(**(code **)(param_1 + 0x5074))(param_1,uVar16,uVar13,0);
      }
      puVar12 = *(uint **)(param_1 + 0x4870);
      uVar13 = (uVar16 + uVar13 * 0x100) - 0x400;
      puVar9 = *(uint **)(param_1 + 0x4874);
      if (uVar16 <= uVar13) {
        do {
          puVar12[1] = uVar16 + 0x100;
          puVar12[2] = uVar16 + 0x200;
          puVar12[3] = uVar16 + 0x300;
          *puVar12 = uVar16;
          *(undefined4 *)(param_1 + 0x4858) = *(undefined4 *)(param_1 + 0x4854);
          puVar10 = puVar9;
          puVar5 = puVar12;
          iVar11 = 4;
          if ((*(char *)(param_1 + 0x4e18) == '\0') ||
             (dVar17 = (double)((double (*)())_gleClipPolyPlane)(param_1,puVar12,4,puVar9,local_4c,dVar17,in_f2,
                                                 in_f3,in_f4,in_f5,in_f6,in_f7,in_f8,
                                                 in_stack_ffffff78,in_stack_ffffff80),
             puVar10 = puVar12, puVar5 = puVar9, iVar11 = local_4c[0], local_4c[0] != 0)) {
            puVar12 = puVar5;
            puVar9 = puVar10;
            if ((uVar7 & 0xff) != 0) {
              dVar17 = (double)_gleClipPoly(param_1,puVar12,iVar11,uVar7 & 0xff,puVar10,local_4c,1);
              if (local_4c[0] == 0) goto LAB_00105a5c;
              if (0 < local_4c[0]) {
                puVar9 = puVar12;
                puVar12 = puVar10;
                iVar11 = local_4c[0];
              }
            }
            if ((cVar2 == '\0') ||
               (iVar6 = _gleCullPolygonPtrStack(param_1,puVar12,iVar11,&local_50),
               dVar17 = extraout_f1_01, iVar6 == 0)) {
              iVar6 = local_50;
              if (((int)-(uint)bVar1 < 0) && (puVar10 = puVar12, iVar8 = iVar11, 0 < iVar11)) {
                do {
                  ((int (*)())_gleVPFlipColors)(param_1,*puVar10,1,iVar6);
                  iVar8 = iVar8 + -1;
                  puVar10 = puVar10 + 1;
                } while (iVar8 != 0);
              }
              if (iVar6 == 0) {
                uVar3 = *(ushort *)(param_1 + 0x34d0);
              }
              else {
                uVar3 = *(ushort *)(param_1 + 0x34d2);
              }
              dVar17 = (double)(**(code **)(param_1 + 0x46e0))
                                         (*(undefined4 *)(param_1 + 0x4688),puVar12,iVar11,
                                          uVar3 - 0x1b00);
            }
          }
LAB_00105a5c:
          uVar16 = uVar16 + 0x400;
        } while (uVar16 <= uVar13);
      }
    }
  }
  return;
}

/* FUN_00105a88 @ 0x105a88 (884 bytes) */
int FUN_00105a88(param_1)
  int param_1;
{
  byte bVar1;
  char cVar2;
  ushort uVar3;
  bool bVar4;
  uint *puVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  uint *puVar9;
  uint *puVar10;
  int iVar11;
  uint uVar12;
  uint *puVar13;
  uint uVar14;
  uint uVar15;
  double extraout_f1;
  double dVar16;
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
  
  iVar11 = -1;
  iVar6 = ((int (*)())_gleTexEnableBits)(param_1);
  bVar1 = *(byte *)(param_1 + 0x4666);
  cVar2 = *(char *)(param_1 + 0x34de);
  if ((((int)*(short *)(param_1 + 0x487c) != 0) &&
      (uVar14 = (uint)(*(int *)(param_1 + 0x4858) - *(int *)(param_1 + 0x4854)) /
                (uint)(int)*(short *)(param_1 + 0x487c), 3 < (int)uVar14)) &&
     (uVar7 = _gleVPEmulate(param_1,uVar14), (uVar7 & 0xff00) == 0)) {
    uVar15 = *(uint *)(param_1 + 0x4864);
    if (((uVar7 & 0xff) == 0) && (*(char *)(param_1 + 0x4e18) == '\0')) {
      dVar16 = extraout_f1;
      if (iVar6 != 0) {
        dVar16 = (double)(**(code **)(param_1 + 0x506c))(param_1,uVar15,uVar14,0);
      }
      if (cVar2 == '\0') {
        (**(code **)(param_1 + 0x46d4))
                  (*(undefined4 *)(param_1 + 0x4688),uVar15,uVar14,
                   *(ushort *)(param_1 + 0x34d0) - 0x1b00);
      }
      else {
        uVar14 = (uVar15 + uVar14 * 0x100) - 0x400;
        do {
          bVar4 = false;
          iVar6 = 0;
          uVar7 = uVar15;
          do {
            while( true ) {
              uVar12 = uVar7;
              if (uVar14 < uVar15) goto LAB_00105bf4;
              uVar7 = uVar15 + 0x200;
              iVar8 = ((undefined4 (*)())_gleCullQuad)(param_1,uVar15,uVar15 + 0x100,uVar15 + 0x300,uVar7,&local_50,
                                   dVar16,in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8,
                                   in_stack_ffffff78,in_stack_ffffff80,in_stack_ffffff88);
              dVar16 = extraout_f1_00;
              if (iVar8 != 0) break;
              if (iVar11 != local_50) {
                bVar4 = true;
              }
              if ((bVar4) && (0 < iVar6)) goto LAB_00105bf4;
              iVar6 = iVar6 + 2;
              iVar11 = local_50;
              uVar15 = uVar7;
              uVar7 = uVar12;
            }
            uVar15 = uVar7;
          } while (iVar6 < 1);
LAB_00105bf4:
          iVar6 = iVar6 + 2;
          if (3 < iVar6) {
            if ((int)-(uint)bVar1 < 0) {
              ((int (*)())_gleVPFlipColors)(param_1,uVar12,iVar6,iVar11);
            }
            if (iVar11 == 0) {
              uVar3 = *(ushort *)(param_1 + 0x34d0);
            }
            else {
              uVar3 = *(ushort *)(param_1 + 0x34d2);
            }
            dVar16 = (double)(**(code **)(param_1 + 0x46d4))
                                       (*(undefined4 *)(param_1 + 0x4688),uVar12,iVar6,
                                        uVar3 - 0x1b00);
          }
        } while (uVar15 <= uVar14);
      }
    }
    else {
      dVar16 = extraout_f1;
      if (iVar6 != 0) {
        dVar16 = (double)(**(code **)(param_1 + 0x5074))(param_1,uVar15,uVar14,0);
      }
      puVar13 = *(uint **)(param_1 + 0x4870);
      puVar9 = *(uint **)(param_1 + 0x4874);
      uVar14 = (uVar15 + uVar14 * 0x100) - 0x400;
      if (uVar15 <= uVar14) {
        do {
          uVar12 = uVar15 + 0x200;
          puVar13[1] = uVar15 + 0x100;
          puVar13[2] = uVar15 + 0x300;
          *puVar13 = uVar15;
          puVar13[3] = uVar12;
          *(undefined4 *)(param_1 + 0x4858) = *(undefined4 *)(param_1 + 0x4854);
          puVar10 = puVar9;
          puVar5 = puVar13;
          iVar11 = 4;
          if ((*(char *)(param_1 + 0x4e18) == '\0') ||
             (dVar16 = (double)((double (*)())_gleClipPolyPlane)(param_1,puVar13,4,puVar9,local_4c,dVar16,in_f2,
                                                 in_f3,in_f4,in_f5,in_f6,in_f7,in_f8,
                                                 in_stack_ffffff78,in_stack_ffffff80),
             puVar10 = puVar13, puVar5 = puVar9, iVar11 = local_4c[0], local_4c[0] != 0)) {
            puVar13 = puVar5;
            puVar9 = puVar10;
            if ((uVar7 & 0xff) != 0) {
              dVar16 = (double)_gleClipPoly(param_1,puVar13,iVar11,uVar7 & 0xff,puVar10,local_4c,1);
              if (local_4c[0] == 0) goto LAB_00105dd4;
              if (0 < local_4c[0]) {
                puVar9 = puVar13;
                puVar13 = puVar10;
                iVar11 = local_4c[0];
              }
            }
            if ((cVar2 == '\0') ||
               (iVar6 = _gleCullPolygonPtrStack(param_1,puVar13,iVar11,&local_50),
               dVar16 = extraout_f1_01, iVar6 == 0)) {
              iVar6 = local_50;
              if (((int)-(uint)bVar1 < 0) && (puVar10 = puVar13, iVar8 = iVar11, 0 < iVar11)) {
                do {
                  ((int (*)())_gleVPFlipColors)(param_1,*puVar10,1,iVar6);
                  iVar8 = iVar8 + -1;
                  puVar10 = puVar10 + 1;
                } while (iVar8 != 0);
              }
              if (iVar6 == 0) {
                uVar3 = *(ushort *)(param_1 + 0x34d0);
              }
              else {
                uVar3 = *(ushort *)(param_1 + 0x34d2);
              }
              dVar16 = (double)(**(code **)(param_1 + 0x46e0))
                                         (*(undefined4 *)(param_1 + 0x4688),puVar13,iVar11,
                                          uVar3 - 0x1b00);
            }
          }
LAB_00105dd4:
          uVar15 = uVar12;
        } while (uVar12 <= uVar14);
      }
    }
  }
  return;
}

/* _gleVPRenderPolygon @ 0x105dfc (728 bytes) */
int _gleVPRenderPolygon(param_1)
  int param_1;
{
  byte bVar1;
  char cVar2;
  ushort uVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  undefined4 uVar8;
  code *pcVar9;
  int *piVar10;
  uint uVar11;
  int *piVar12;
  int *piVar13;
  uint uVar14;
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
  uint local_40;
  int local_3c [4];
  
  local_3c[0] = 0;
  iVar5 = ((int (*)())_gleTexEnableBits)(param_1);
  bVar1 = *(byte *)(param_1 + 0x4666);
  cVar2 = *(char *)(param_1 + 0x34de);
  if ((((int)*(short *)(param_1 + 0x487c) != 0) &&
      (uVar11 = (uint)(*(int *)(param_1 + 0x4858) - *(int *)(param_1 + 0x4854)) /
                (uint)(int)*(short *)(param_1 + 0x487c), 2 < (int)uVar11)) &&
     (uVar6 = _gleVPEmulate(param_1,uVar11), (uVar6 & 0xff00) == 0)) {
    piVar13 = *(int **)(param_1 + 0x4864);
    if (((uVar6 & 0xff) == 0) && (*(char *)(param_1 + 0x4e18) == '\0')) {
      if ((cVar2 != '\0') &&
         (iVar7 = _gleCullPolygonStack(param_1,piVar13,uVar11,0,local_3c), iVar7 != 0)) {
        return;
      }
      if (iVar5 != 0) {
        (**(code **)(param_1 + 0x506c))(param_1,piVar13,uVar11,0);
      }
      if (local_3c[0] == 0) {
        uVar3 = *(ushort *)(param_1 + 0x34d0);
      }
      else {
        uVar3 = *(ushort *)(param_1 + 0x34d2);
      }
      iVar5 = uVar3 - 0x1b00;
      if ((*(char *)(param_1 + 0x4a18) != '\0') && (iVar5 == 1)) {
        iVar5 = 3;
      }
      if ((int)-(uint)bVar1 < 0) {
        ((int (*)())_gleVPFlipColors)(param_1,piVar13,uVar11,local_3c[0]);
      }
      pcVar9 = *(code **)(param_1 + 0x46c0);
    }
    else {
      fparam_1 = extraout_f1;
      if (iVar5 != 0) {
        fparam_1 = (double)(**(code **)(param_1 + 0x5074))(param_1,piVar13,uVar11,0);
      }
      piVar10 = *(int **)(param_1 + 0x4870);
      piVar12 = *(int **)(param_1 + 0x4874);
      piVar4 = piVar10;
      uVar14 = uVar11;
      if (0 < (int)uVar11) {
        do {
          *piVar4 = (int)piVar13;
          piVar13 = piVar13 + 0x40;
          uVar14 = uVar14 - 1;
          piVar4 = piVar4 + 1;
        } while (uVar14 != 0);
      }
      uVar8 = 0;
      *(undefined4 *)(param_1 + 0x4858) = *(undefined4 *)(param_1 + 0x4854);
      piVar13 = piVar10;
      if (*(char *)(param_1 + 0x4e18) != '\0') {
        ((double (*)())_gleClipPolyPlane)(param_1,piVar10,uVar11,piVar12,&local_40,fparam_1,in_f2,in_f3,in_f4,in_f5,
                          in_f6,in_f7,in_f8,in_stack_ffffff88,in_stack_ffffff90);
        if (local_40 == 0) {
          return;
        }
        uVar8 = 1;
        piVar13 = piVar12;
        uVar11 = local_40;
        piVar12 = piVar10;
      }
      if ((uVar6 & 0xff) != 0) {
        _gleClipPoly(param_1,piVar13,uVar11,uVar6 & 0xff,piVar12,&local_40,uVar8);
        if (local_40 == 0) {
          return;
        }
        if (0 < (int)local_40) {
          piVar13 = piVar12;
          uVar11 = local_40;
        }
      }
      if ((cVar2 != '\0') &&
         (iVar5 = _gleCullPolygonPtrStack(param_1,piVar13,uVar11,local_3c), iVar5 != 0)) {
        return;
      }
      if (local_3c[0] == 0) {
        uVar3 = *(ushort *)(param_1 + 0x34d0);
      }
      else {
        uVar3 = *(ushort *)(param_1 + 0x34d2);
      }
      iVar5 = uVar3 - 0x1b00;
      if ((*(char *)(param_1 + 0x4a18) != '\0') && (iVar5 == 1)) {
        iVar5 = 3;
      }
      if (((int)-(uint)bVar1 < 0) && (piVar4 = piVar13, uVar6 = uVar11, 0 < (int)uVar11)) {
        do {
          ((int (*)())_gleVPFlipColors)(param_1,*piVar4,1,local_3c[0]);
          uVar6 = uVar6 - 1;
          piVar4 = piVar4 + 1;
        } while (uVar6 != 0);
      }
      pcVar9 = *(code **)(param_1 + 0x46e0);
    }
    (*pcVar9)(*(undefined4 *)(param_1 + 0x4688),piVar13,uVar11,iVar5);
  }
  return;
}

/* _gleVPFlushAtomic @ 0x1060d4 (60 bytes) */
int _gleVPFlushAtomic(param_1)
  int param_1;
{
  (**(code **)(param_1 + 0x4a08))();
  *(undefined4 *)(param_1 + 0x4858) = *(undefined4 *)(param_1 + 0x4854);
  return;
}

/* _gleVPFlushAtomicTCL @ 0x106110 (60 bytes) */
int _gleVPFlushAtomicTCL(param_1)
  int param_1;
{
  (**(code **)(param_1 + 0x4a08))();
  *(undefined4 *)(param_1 + 0x4858) = *(undefined4 *)(param_1 + 0x4854);
  return;
}

/* _gleVPFlushAtomicTCLRDirty @ 0x10614c (132 bytes) */
void _gleVPFlushAtomicTCLRDirty(int param_1,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  if ((((*(char *)(param_1 + 0x7580) != '\0') && ((*(uint *)(param_1 + 0x486c) & 1) != 0)) &&
      (*(char *)(*(int *)(param_1 + 0x468c) + 0x7a) == '\0')) &&
     ((*(char *)(param_1 + 0x4664) == '\0' && (*(int *)(param_1 + 0x5434) == 0)))) {
    ((undefined4 (*)())_gleForceToSoftwareTCL)(param_1,fparam_1,fparam_2,fparam_3,fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
  }
  (**(code **)(param_1 + 0x4a08))(param_1);
  *(undefined4 *)(param_1 + 0x4858) = *(undefined4 *)(param_1 + 0x4854);
  return;
}

/* _gleVPFlushLineLoop @ 0x1061d0 (228 bytes) */
int _gleVPFlushLineLoop(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined8 local_120 [33];
  
  iVar5 = *(int *)(param_1 + 0x4854);
  iVar4 = (int)*(short *)(param_1 + 0x487c) >> 3;
  if (*(char *)(param_1 + 0x4a18) == '\0') {
    iVar3 = 0;
    for (iVar6 = iVar4; iVar6 != 0; iVar6 = iVar6 + -1) {
      iVar1 = iVar3 * 8;
      iVar3 = iVar3 + 1;
      *(undefined8 *)(iVar5 + -0x100 + iVar1) = *(undefined8 *)(iVar5 + iVar1);
    }
  }
  iVar2 = *(int *)(param_1 + 0x4858);
  iVar6 = iVar4 * 8;
  iVar1 = 0;
  for (iVar3 = iVar4; iVar3 != 0; iVar3 = iVar3 + -1) {
    local_120[iVar1] = *(undefined8 *)(iVar2 + iVar4 * -8 + iVar1 * 8);
    iVar1 = iVar1 + 1;
  }
  (**(code **)(param_1 + 0x4a08))(param_1);
  *(undefined1 *)(param_1 + 0x4a18) = 1;
  iVar3 = 0;
  for (; iVar4 != 0; iVar4 = iVar4 + -1) {
    *(undefined8 *)(iVar5 + iVar3 * 8) = local_120[iVar3];
    iVar3 = iVar3 + 1;
  }
  *(int *)(param_1 + 0x4858) = iVar5 + iVar6;
  return;
}

/* _gleVPFlushLineLoopTCL @ 0x1062b4 (180 bytes) */
int _gleVPFlushLineLoopTCL(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  (**(code **)(param_1 + 0x4a08))();
  iVar6 = *(int *)(param_1 + 0x4854);
  iVar3 = (int)*(short *)(param_1 + 0x487c) >> 3;
  if (*(char *)(param_1 + 0x4a18) == '\0') {
    iVar4 = 0;
    for (iVar7 = iVar3; iVar7 != 0; iVar7 = iVar7 + -1) {
      iVar5 = iVar4 * 8;
      iVar4 = iVar4 + 1;
      *(undefined8 *)(iVar6 + -0x100 + iVar5) = *(undefined8 *)(iVar6 + iVar5);
    }
    *(undefined1 *)(param_1 + 0x4a18) = 1;
  }
  iVar5 = 0;
  iVar2 = *(int *)(param_1 + 0x4858);
  iVar7 = iVar3 * 8;
  iVar4 = iVar3 * -8;
  for (; iVar3 != 0; iVar3 = iVar3 + -1) {
    iVar1 = iVar5 * 8;
    iVar5 = iVar5 + 1;
    *(undefined8 *)(iVar6 + iVar1) = *(undefined8 *)(iVar2 + iVar4 + iVar1);
  }
  *(int *)(param_1 + 0x4858) = iVar6 + iVar7;
  return;
}

/* _gleVPFlushLineLoopTCLRDirty @ 0x106368 (252 bytes) */
void _gleVPFlushLineLoopTCLRDirty(int param_1,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  if ((((*(char *)(param_1 + 0x7580) != '\0') && ((*(uint *)(param_1 + 0x486c) & 1) != 0)) &&
      (*(char *)(*(int *)(param_1 + 0x468c) + 0x7a) == '\0')) &&
     ((*(char *)(param_1 + 0x4664) == '\0' && (*(int *)(param_1 + 0x5434) == 0)))) {
    ((undefined4 (*)())_gleForceToSoftwareTCL)(param_1,fparam_1,fparam_2,fparam_3,fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
  }
  (**(code **)(param_1 + 0x4a08))(param_1);
  iVar6 = *(int *)(param_1 + 0x4854);
  iVar3 = (int)*(short *)(param_1 + 0x487c) >> 3;
  if (*(char *)(param_1 + 0x4a18) == '\0') {
    iVar4 = 0;
    for (iVar7 = iVar3; iVar7 != 0; iVar7 = iVar7 + -1) {
      iVar5 = iVar4 * 8;
      iVar4 = iVar4 + 1;
      *(undefined8 *)(iVar6 + -0x100 + iVar5) = *(undefined8 *)(iVar6 + iVar5);
    }
    *(undefined1 *)(param_1 + 0x4a18) = 1;
  }
  iVar5 = 0;
  iVar2 = *(int *)(param_1 + 0x4858);
  iVar7 = iVar3 * 8;
  iVar4 = iVar3 * -8;
  for (; iVar3 != 0; iVar3 = iVar3 + -1) {
    iVar1 = iVar5 * 8;
    iVar5 = iVar5 + 1;
    *(undefined8 *)(iVar6 + iVar1) = *(undefined8 *)(iVar2 + iVar4 + iVar1);
  }
  *(int *)(param_1 + 0x4858) = iVar6 + iVar7;
  return;
}

/* _gleVPFlushLineStrip @ 0x106464 (176 bytes) */
int _gleVPFlushLineStrip(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined8 local_110 [32];
  
  iVar4 = (int)*(short *)(param_1 + 0x487c) >> 3;
  iVar3 = *(int *)(param_1 + 0x4858);
  iVar1 = iVar4 * 8;
  iVar2 = 0;
  for (iVar5 = iVar4; iVar5 != 0; iVar5 = iVar5 + -1) {
    local_110[iVar2] = *(undefined8 *)(iVar3 + iVar4 * -8 + iVar2 * 8);
    iVar2 = iVar2 + 1;
  }
  (**(code **)(param_1 + 0x4a08))(param_1);
  *(undefined1 *)(param_1 + 0x4a18) = 1;
  iVar5 = *(int *)(param_1 + 0x4854);
  iVar2 = 0;
  for (; iVar4 != 0; iVar4 = iVar4 + -1) {
    *(undefined8 *)(iVar5 + iVar2 * 8) = local_110[iVar2];
    iVar2 = iVar2 + 1;
  }
  *(int *)(param_1 + 0x4858) = iVar5 + iVar1;
  return;
}

/* _gleVPFlushLineStripTCL @ 0x106514 (128 bytes) */
int _gleVPFlushLineStripTCL(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  (**(code **)(param_1 + 0x4a08))();
  iVar5 = 0;
  iVar4 = *(int *)(param_1 + 0x4858);
  iVar6 = (int)*(short *)(param_1 + 0x487c) >> 3;
  iVar1 = iVar6 * 8;
  *(undefined1 *)(param_1 + 0x4a18) = 1;
  iVar3 = iVar6 * -8;
  iVar7 = *(int *)(param_1 + 0x4854);
  for (; iVar6 != 0; iVar6 = iVar6 + -1) {
    iVar2 = iVar5 * 8;
    iVar5 = iVar5 + 1;
    *(undefined8 *)(iVar7 + iVar2) = *(undefined8 *)(iVar4 + iVar3 + iVar2);
  }
  *(int *)(param_1 + 0x4858) = iVar7 + iVar1;
  return;
}

/* _gleVPFlushLineStripTCLRDirty @ 0x106594 (200 bytes) */
void _gleVPFlushLineStripTCLRDirty(int param_1,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  if ((((*(char *)(param_1 + 0x7580) != '\0') && ((*(uint *)(param_1 + 0x486c) & 1) != 0)) &&
      (*(char *)(*(int *)(param_1 + 0x468c) + 0x7a) == '\0')) &&
     ((*(char *)(param_1 + 0x4664) == '\0' && (*(int *)(param_1 + 0x5434) == 0)))) {
    ((undefined4 (*)())_gleForceToSoftwareTCL)(param_1,fparam_1,fparam_2,fparam_3,fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
  }
  (**(code **)(param_1 + 0x4a08))(param_1);
  iVar5 = 0;
  iVar4 = *(int *)(param_1 + 0x4858);
  iVar6 = (int)*(short *)(param_1 + 0x487c) >> 3;
  iVar1 = iVar6 * 8;
  *(undefined1 *)(param_1 + 0x4a18) = 1;
  iVar3 = iVar6 * -8;
  iVar7 = *(int *)(param_1 + 0x4854);
  for (; iVar6 != 0; iVar6 = iVar6 + -1) {
    iVar2 = iVar5 * 8;
    iVar5 = iVar5 + 1;
    *(undefined8 *)(iVar7 + iVar2) = *(undefined8 *)(iVar4 + iVar3 + iVar2);
  }
  *(int *)(param_1 + 0x4858) = iVar7 + iVar1;
  return;
}

/* _gleVPFlushTriQuadStrip @ 0x10665c (168 bytes) */
int _gleVPFlushTriQuadStrip(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined8 local_210 [64];
  
  iVar4 = (int)*(short *)(param_1 + 0x487c) >> 2;
  iVar3 = *(int *)(param_1 + 0x4858);
  iVar1 = iVar4 * 8;
  iVar2 = 0;
  for (iVar5 = iVar4; iVar5 != 0; iVar5 = iVar5 + -1) {
    local_210[iVar2] = *(undefined8 *)(iVar3 + iVar4 * -8 + iVar2 * 8);
    iVar2 = iVar2 + 1;
  }
  (**(code **)(param_1 + 0x4a08))(param_1);
  iVar5 = *(int *)(param_1 + 0x4854);
  iVar2 = 0;
  for (; iVar4 != 0; iVar4 = iVar4 + -1) {
    *(undefined8 *)(iVar5 + iVar2 * 8) = local_210[iVar2];
    iVar2 = iVar2 + 1;
  }
  *(int *)(param_1 + 0x4858) = iVar5 + iVar1;
  return;
}

/* _gleVPFlushTriQuadStripTCL @ 0x106704 (120 bytes) */
int _gleVPFlushTriQuadStripTCL(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  (**(code **)(param_1 + 0x4a08))();
  iVar5 = 0;
  iVar7 = *(int *)(param_1 + 0x4854);
  iVar6 = (int)*(short *)(param_1 + 0x487c) >> 2;
  iVar4 = *(int *)(param_1 + 0x4858);
  iVar1 = iVar6 * 8;
  iVar3 = iVar6 * -8;
  for (; iVar6 != 0; iVar6 = iVar6 + -1) {
    iVar2 = iVar5 * 8;
    iVar5 = iVar5 + 1;
    *(undefined8 *)(iVar7 + iVar2) = *(undefined8 *)(iVar4 + iVar3 + iVar2);
  }
  *(int *)(param_1 + 0x4858) = iVar7 + iVar1;
  return;
}

/* _gleVPFlushTriQuadStripTCLRDirty @ 0x10677c (192 bytes) */
void _gleVPFlushTriQuadStripTCLRDirty(int param_1,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  if ((((*(char *)(param_1 + 0x7580) != '\0') && ((*(uint *)(param_1 + 0x486c) & 1) != 0)) &&
      (*(char *)(*(int *)(param_1 + 0x468c) + 0x7a) == '\0')) &&
     ((*(char *)(param_1 + 0x4664) == '\0' && (*(int *)(param_1 + 0x5434) == 0)))) {
    ((undefined4 (*)())_gleForceToSoftwareTCL)(param_1,fparam_1,fparam_2,fparam_3,fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
  }
  (**(code **)(param_1 + 0x4a08))(param_1);
  iVar5 = 0;
  iVar7 = *(int *)(param_1 + 0x4854);
  iVar6 = (int)*(short *)(param_1 + 0x487c) >> 2;
  iVar4 = *(int *)(param_1 + 0x4858);
  iVar1 = iVar6 * 8;
  iVar3 = iVar6 * -8;
  for (; iVar6 != 0; iVar6 = iVar6 + -1) {
    iVar2 = iVar5 * 8;
    iVar5 = iVar5 + 1;
    *(undefined8 *)(iVar7 + iVar2) = *(undefined8 *)(iVar4 + iVar3 + iVar2);
  }
  *(int *)(param_1 + 0x4858) = iVar7 + iVar1;
  return;
}

/* _gleVPFlushTriangleFan @ 0x10683c (252 bytes) */
int _gleVPFlushTriangleFan(param_1)
  int param_1;
{
  undefined8 *puVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined8 uVar8;
  undefined8 local_220 [32];
  undefined8 local_120 [33];
  
  iVar5 = *(int *)(param_1 + 0x4854);
  iVar4 = (int)*(short *)(param_1 + 0x487c) >> 3;
  puVar3 = (undefined8 *)(*(int *)(param_1 + 0x4858) + iVar4 * -8);
  iVar7 = 0;
  for (iVar6 = iVar4; iVar6 != 0; iVar6 = iVar6 + -1) {
    local_220[iVar7] = *(undefined8 *)(iVar5 + iVar7 * 8);
    iVar7 = iVar7 + 1;
  }
  if (iVar4 != 0) {
    puVar1 = local_120;
    iVar7 = iVar4;
    do {
      uVar8 = *puVar3;
      puVar3 = puVar3 + 1;
      *puVar1 = uVar8;
      puVar1 = puVar1 + 1;
      iVar7 = iVar7 + -1;
    } while (iVar7 != 0);
  }
  (**(code **)(param_1 + 0x4a08))(param_1);
  iVar6 = 0;
  for (iVar7 = iVar4; iVar7 != 0; iVar7 = iVar7 + -1) {
    *(undefined8 *)(iVar5 + iVar6 * 8) = local_220[iVar6];
    iVar6 = iVar6 + 1;
  }
  puVar3 = (undefined8 *)(iVar5 + iVar4 * 8);
  if (iVar4 != 0) {
    puVar2 = local_120;
    puVar1 = puVar3;
    iVar7 = iVar4;
    do {
      uVar8 = *puVar2;
      puVar2 = puVar2 + 1;
      *puVar1 = uVar8;
      puVar1 = puVar1 + 1;
      iVar7 = iVar7 + -1;
    } while (iVar7 != 0);
  }
  *(undefined8 **)(param_1 + 0x4858) = puVar3 + iVar4;
  return;
}

/* _gleVPFlushTriangleFanTCL @ 0x106938 (124 bytes) */
int _gleVPFlushTriangleFanTCL(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  (**(code **)(param_1 + 0x4a08))();
  iVar6 = 0;
  iVar7 = (int)*(short *)(param_1 + 0x487c) >> 3;
  iVar4 = *(int *)(param_1 + 0x4858);
  iVar1 = iVar7 * 8;
  iVar3 = iVar7 * -8;
  iVar5 = *(int *)(param_1 + 0x4854) + iVar1;
  for (; iVar7 != 0; iVar7 = iVar7 + -1) {
    iVar2 = iVar6 * 8;
    iVar6 = iVar6 + 1;
    *(undefined8 *)(iVar5 + iVar2) = *(undefined8 *)(iVar4 + iVar3 + iVar2);
  }
  *(int *)(param_1 + 0x4858) = iVar5 + iVar1;
  return;
}

/* _gleVPFlushTriangleFanTCLRDirty @ 0x1069b4 (196 bytes) */
void _gleVPFlushTriangleFanTCLRDirty(int param_1,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  if ((((*(char *)(param_1 + 0x7580) != '\0') && ((*(uint *)(param_1 + 0x486c) & 1) != 0)) &&
      (*(char *)(*(int *)(param_1 + 0x468c) + 0x7a) == '\0')) &&
     ((*(char *)(param_1 + 0x4664) == '\0' && (*(int *)(param_1 + 0x5434) == 0)))) {
    ((undefined4 (*)())_gleForceToSoftwareTCL)(param_1,fparam_1,fparam_2,fparam_3,fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
  }
  (**(code **)(param_1 + 0x4a08))(param_1);
  iVar6 = 0;
  iVar7 = (int)*(short *)(param_1 + 0x487c) >> 3;
  iVar4 = *(int *)(param_1 + 0x4858);
  iVar1 = iVar7 * 8;
  iVar3 = iVar7 * -8;
  iVar5 = *(int *)(param_1 + 0x4854) + iVar1;
  for (; iVar7 != 0; iVar7 = iVar7 + -1) {
    iVar2 = iVar6 * 8;
    iVar6 = iVar6 + 1;
    *(undefined8 *)(iVar5 + iVar2) = *(undefined8 *)(iVar4 + iVar3 + iVar2);
  }
  *(int *)(param_1 + 0x4858) = iVar5 + iVar1;
  return;
}

/* _gleVPFlushPolygon @ 0x106a78 (324 bytes) */
int _gleVPFlushPolygon(param_1)
  int param_1;
{
  uint uVar1;
  undefined8 *puVar2;
  uint uVar3;
  undefined8 *puVar4;
  undefined8 *puVar5;
  int iVar6;
  uint *puVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  undefined8 uVar12;
  undefined8 local_220 [32];
  undefined8 local_120 [32];
  
  iVar9 = *(int *)(param_1 + 0x4854);
  iVar6 = (int)*(short *)(param_1 + 0x487c) >> 3;
  puVar5 = (undefined8 *)(*(int *)(param_1 + 0x4858) + iVar6 * -8);
  iVar11 = 0;
  for (iVar10 = iVar6; iVar10 != 0; iVar10 = iVar10 + -1) {
    local_220[iVar11] = *(undefined8 *)(iVar9 + iVar11 * 8);
    iVar11 = iVar11 + 1;
  }
  if (iVar6 != 0) {
    puVar4 = local_120;
    puVar2 = puVar5;
    iVar11 = iVar6;
    do {
      uVar12 = *puVar2;
      puVar2 = puVar2 + 1;
      *puVar4 = uVar12;
      puVar4 = puVar4 + 1;
      iVar11 = iVar11 + -1;
    } while (iVar11 != 0);
  }
  puVar7 = *(uint **)(param_1 + 0x30b0);
  uVar3 = (uint)((int)puVar5 - iVar9) / (uint)(iVar6 * 8);
  uVar1 = uVar3 >> 3 & 0x1ffffffc;
  uVar3 = uVar3 & 0x1f;
  uVar8 = *(uint *)(uVar1 + (int)puVar7);
  *(uint *)(uVar1 + (int)puVar7) = uVar8 & ~(1 << uVar3);
  (**(code **)(param_1 + 0x4a08))(param_1);
  *(undefined1 *)(param_1 + 0x4a18) = 1;
  *puVar7 = *puVar7 & 0xfffffffc | (uVar8 >> uVar3 & 1) << 1;
  iVar10 = 0;
  for (iVar11 = iVar6; iVar11 != 0; iVar11 = iVar11 + -1) {
    *(undefined8 *)(iVar9 + iVar10 * 8) = local_220[iVar10];
    iVar10 = iVar10 + 1;
  }
  puVar5 = (undefined8 *)(iVar9 + iVar6 * 8);
  if (iVar6 != 0) {
    puVar4 = local_120;
    puVar2 = puVar5;
    iVar11 = iVar6;
    do {
      uVar12 = *puVar4;
      puVar4 = puVar4 + 1;
      *puVar2 = uVar12;
      puVar2 = puVar2 + 1;
      iVar11 = iVar11 + -1;
    } while (iVar11 != 0);
  }
  *(undefined8 **)(param_1 + 0x4858) = puVar5 + iVar6;
  return;
}

/* _gleVPFlushPolygonTCL @ 0x106bbc (196 bytes) */
int _gleVPFlushPolygonTCL(param_1)
  int param_1;
{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint *puVar8;
  uint uVar9;
  int iVar10;
  
  iVar6 = (int)*(short *)(param_1 + 0x487c) >> 3;
  uVar1 = iVar6 * 8;
  puVar8 = *(uint **)(param_1 + 0x30b0);
  iVar7 = *(int *)(param_1 + 0x4858) + iVar6 * -8;
  iVar10 = *(int *)(param_1 + 0x4854) + uVar1;
  uVar4 = (uint)(iVar7 - *(int *)(param_1 + 0x4854)) / uVar1;
  uVar3 = uVar4 >> 3 & 0x1ffffffc;
  uVar4 = uVar4 & 0x1f;
  uVar9 = *(uint *)(uVar3 + (int)puVar8);
  *(uint *)(uVar3 + (int)puVar8) = uVar9 & ~(1 << uVar4);
  (**(code **)(param_1 + 0x4a08))();
  *(undefined1 *)(param_1 + 0x4a18) = 1;
  iVar5 = 0;
  *puVar8 = *puVar8 & 0xfffffffc | (uVar9 >> uVar4 & 1) << 1;
  for (; iVar6 != 0; iVar6 = iVar6 + -1) {
    iVar2 = iVar5 * 8;
    iVar5 = iVar5 + 1;
    *(undefined8 *)(iVar10 + iVar2) = *(undefined8 *)(iVar7 + iVar2);
  }
  *(uint *)(param_1 + 0x4858) = iVar10 + uVar1;
  return;
}

/* _gleVPFlushPolygonTCLRDirty @ 0x106c80 (268 bytes) */
void _gleVPFlushPolygonTCLRDirty(int param_1,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint *puVar8;
  uint uVar9;
  int iVar10;
  
  if ((((*(char *)(param_1 + 0x7580) != '\0') && ((*(uint *)(param_1 + 0x486c) & 1) != 0)) &&
      (*(char *)(*(int *)(param_1 + 0x468c) + 0x7a) == '\0')) &&
     ((*(char *)(param_1 + 0x4664) == '\0' && (*(int *)(param_1 + 0x5434) == 0)))) {
    ((undefined4 (*)())_gleForceToSoftwareTCL)(param_1,fparam_1,fparam_2,fparam_3,fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
  }
  iVar6 = (int)*(short *)(param_1 + 0x487c) >> 3;
  uVar1 = iVar6 * 8;
  puVar8 = *(uint **)(param_1 + 0x30b0);
  iVar7 = *(int *)(param_1 + 0x4858) + iVar6 * -8;
  iVar10 = *(int *)(param_1 + 0x4854) + uVar1;
  uVar4 = (uint)(iVar7 - *(int *)(param_1 + 0x4854)) / uVar1;
  uVar3 = uVar4 >> 3 & 0x1ffffffc;
  uVar4 = uVar4 & 0x1f;
  uVar9 = *(uint *)(uVar3 + (int)puVar8);
  *(uint *)(uVar3 + (int)puVar8) = uVar9 & ~(1 << uVar4);
  (**(code **)(param_1 + 0x4a08))(param_1);
  *(undefined1 *)(param_1 + 0x4a18) = 1;
  iVar5 = 0;
  *puVar8 = *puVar8 & 0xfffffffc | (uVar9 >> uVar4 & 1) << 1;
  for (; iVar6 != 0; iVar6 = iVar6 + -1) {
    iVar2 = iVar5 * 8;
    iVar5 = iVar5 + 1;
    *(undefined8 *)(iVar10 + iVar2) = *(undefined8 *)(iVar7 + iVar2);
  }
  *(uint *)(param_1 + 0x4858) = iVar10 + uVar1;
  return;
}

/* _gleVPBeginPoints @ 0x106d8c (60 bytes) */
int _gleVPBeginPoints(param_1)
  int param_1;
{
  undefined *puVar1;
  undefined *puVar2;
  
  *(undefined4 *)(param_1 + 0x486c) = 0;
  puVar2 = PTR__gleVPFlushAtomic_00111668;
  puVar1 = PTR__gleVPRenderPoints_00111664;
  *(undefined4 *)(param_1 + 0x4858) = *(undefined4 *)(param_1 + 0x4854);
  *(undefined **)(param_1 + 0x4a0c) = puVar2;
  *(undefined **)(param_1 + 0x4a08) = puVar1;
  return;
}

/* _gleVPBeginLines @ 0x106dc8 (60 bytes) */
int _gleVPBeginLines(param_1)
  int param_1;
{
  undefined *puVar1;
  undefined *puVar2;
  
  *(undefined4 *)(param_1 + 0x486c) = 0;
  puVar2 = PTR__gleVPFlushAtomic_00111668;
  puVar1 = PTR__gleVPRenderLines_00111660;
  *(undefined4 *)(param_1 + 0x4858) = *(undefined4 *)(param_1 + 0x4854);
  *(undefined **)(param_1 + 0x4a0c) = puVar2;
  *(undefined **)(param_1 + 0x4a08) = puVar1;
  return;
}

/* _gleVPBeginLineLoop @ 0x106e04 (68 bytes) */
int _gleVPBeginLineLoop(param_1)
  int param_1;
{
  undefined *puVar1;
  undefined *puVar2;
  
  *(undefined1 *)(param_1 + 0x4a18) = 0;
  puVar2 = PTR__gleVPFlushLineLoop_0011165c;
  puVar1 = PTR__gleVPRenderLineLoop_00111658;
  *(undefined4 *)(param_1 + 0x4858) = *(undefined4 *)(param_1 + 0x4854);
  *(undefined4 *)(param_1 + 0x486c) = 0;
  *(undefined **)(param_1 + 0x4a0c) = puVar2;
  *(undefined **)(param_1 + 0x4a08) = puVar1;
  return;
}

/* _gleVPBeginLineStrip @ 0x106e48 (68 bytes) */
int _gleVPBeginLineStrip(param_1)
  int param_1;
{
  undefined *puVar1;
  undefined *puVar2;
  
  *(undefined1 *)(param_1 + 0x4a18) = 0;
  puVar2 = PTR__gleVPFlushLineStrip_00111654;
  puVar1 = PTR__gleVPRenderLineStrip_00111650;
  *(undefined4 *)(param_1 + 0x4858) = *(undefined4 *)(param_1 + 0x4854);
  *(undefined4 *)(param_1 + 0x486c) = 0;
  *(undefined **)(param_1 + 0x4a0c) = puVar2;
  *(undefined **)(param_1 + 0x4a08) = puVar1;
  return;
}

/* _gleVPBeginTriangles @ 0x106e8c (60 bytes) */
int _gleVPBeginTriangles(param_1)
  int param_1;
{
  undefined *puVar1;
  undefined *puVar2;
  
  *(undefined4 *)(param_1 + 0x486c) = 0;
  puVar2 = PTR__gleVPFlushAtomic_00111668;
  puVar1 = PTR__gleVPRenderTriangles_0011164c;
  *(undefined4 *)(param_1 + 0x4858) = *(undefined4 *)(param_1 + 0x4854);
  *(undefined **)(param_1 + 0x4a0c) = puVar2;
  *(undefined **)(param_1 + 0x4a08) = puVar1;
  return;
}

/* _gleVPBeginTriangleStrip @ 0x106ec8 (60 bytes) */
int _gleVPBeginTriangleStrip(param_1)
  int param_1;
{
  undefined *puVar1;
  undefined *puVar2;
  
  *(undefined4 *)(param_1 + 0x486c) = 0;
  puVar2 = PTR__gleVPFlushTriQuadStrip_00111648;
  puVar1 = PTR__gleVPRenderTriangleStrip_00111644;
  *(undefined4 *)(param_1 + 0x4858) = *(undefined4 *)(param_1 + 0x4854);
  *(undefined **)(param_1 + 0x4a0c) = puVar2;
  *(undefined **)(param_1 + 0x4a08) = puVar1;
  return;
}

/* _gleVPBeginTriangleFan @ 0x106f04 (60 bytes) */
int _gleVPBeginTriangleFan(param_1)
  int param_1;
{
  undefined *puVar1;
  undefined *puVar2;
  
  *(undefined4 *)(param_1 + 0x486c) = 0;
  puVar2 = PTR__gleVPFlushTriangleFan_00111640;
  puVar1 = PTR__gleVPRenderTriangleFan_0011163c;
  *(undefined4 *)(param_1 + 0x4858) = *(undefined4 *)(param_1 + 0x4854);
  *(undefined **)(param_1 + 0x4a0c) = puVar2;
  *(undefined **)(param_1 + 0x4a08) = puVar1;
  return;
}

/* _gleVPBeginQuads @ 0x106f40 (60 bytes) */
int _gleVPBeginQuads(param_1)
  int param_1;
{
  undefined *puVar1;
  undefined *puVar2;
  
  *(undefined4 *)(param_1 + 0x486c) = 0;
  puVar2 = PTR__gleVPFlushAtomic_00111668;
  puVar1 = PTR__gleVPRenderQuads_00111638;
  *(undefined4 *)(param_1 + 0x4858) = *(undefined4 *)(param_1 + 0x4854);
  *(undefined **)(param_1 + 0x4a0c) = puVar2;
  *(undefined **)(param_1 + 0x4a08) = puVar1;
  return;
}

/* _gleVPBeginQuadStrip @ 0x106f7c (60 bytes) */
int _gleVPBeginQuadStrip(param_1)
  int param_1;
{
  undefined *puVar1;
  undefined *puVar2;
  
  *(undefined4 *)(param_1 + 0x486c) = 0;
  puVar2 = PTR__gleVPFlushTriQuadStrip_00111648;
  puVar1 = PTR__gleVPRenderQuadStrip_00111634;
  *(undefined4 *)(param_1 + 0x4858) = *(undefined4 *)(param_1 + 0x4854);
  *(undefined **)(param_1 + 0x4a0c) = puVar2;
  *(undefined **)(param_1 + 0x4a08) = puVar1;
  return;
}

/* _gleVPBeginPolygon @ 0x106fb8 (68 bytes) */
int _gleVPBeginPolygon(param_1)
  int param_1;
{
  undefined *puVar1;
  undefined *puVar2;
  
  *(undefined1 *)(param_1 + 0x4a18) = 0;
  puVar2 = PTR__gleVPFlushPolygon_00111630;
  puVar1 = PTR__gleVPRenderPolygon_0011162c;
  *(undefined4 *)(param_1 + 0x4858) = *(undefined4 *)(param_1 + 0x4854);
  *(undefined4 *)(param_1 + 0x486c) = 0;
  *(undefined **)(param_1 + 0x4a0c) = puVar2;
  *(undefined **)(param_1 + 0x4a08) = puVar1;
  return;
}

/* _gleVPBeginPointsTCL @ 0x106ffc (52 bytes) */
int _gleVPBeginPointsTCL(param_1)
  int param_1;
{
  undefined *puVar1;
  
  puVar1 = PTR__gleVPFlushAtomicTCL_00111628;
  *(undefined4 *)(param_1 + 0x4858) = *(undefined4 *)(param_1 + 0x4854);
  *(undefined **)(param_1 + 0x4a0c) = puVar1;
  *(undefined **)(param_1 + 0x4a08) = PTR__gleRenderPointsTCLFunc_0011223c;
  return;
}

/* _gleVPBeginLinesTCL @ 0x107030 (52 bytes) */
int _gleVPBeginLinesTCL(param_1)
  int param_1;
{
  undefined *puVar1;
  
  puVar1 = PTR__gleVPFlushAtomicTCL_00111628;
  *(undefined4 *)(param_1 + 0x4858) = *(undefined4 *)(param_1 + 0x4854);
  *(undefined **)(param_1 + 0x4a0c) = puVar1;
  *(undefined **)(param_1 + 0x4a08) = PTR__gleRenderLinesTCLFunc_00112214;
  return;
}

/* _gleVPBeginLineLoopTCL @ 0x107064 (60 bytes) */
int _gleVPBeginLineLoopTCL(param_1)
  int param_1;
{
  undefined *puVar1;
  undefined *puVar2;
  
  *(undefined1 *)(param_1 + 0x4a18) = 0;
  puVar2 = PTR__gleRenderLineLoopTCLFunc_001121d4;
  puVar1 = PTR__gleVPFlushLineLoopTCL_00111624;
  *(undefined4 *)(param_1 + 0x4858) = *(undefined4 *)(param_1 + 0x4854);
  *(undefined **)(param_1 + 0x4a0c) = puVar1;
  *(undefined **)(param_1 + 0x4a08) = puVar2;
  return;
}

/* _gleVPBeginLineStripTCL @ 0x1070a0 (60 bytes) */
int _gleVPBeginLineStripTCL(param_1)
  int param_1;
{
  undefined *puVar1;
  undefined *puVar2;
  
  *(undefined1 *)(param_1 + 0x4a18) = 0;
  puVar2 = PTR__gleRenderLineStripTCLFunc_001121f4;
  puVar1 = PTR__gleVPFlushLineStripTCL_00111620;
  *(undefined4 *)(param_1 + 0x4858) = *(undefined4 *)(param_1 + 0x4854);
  *(undefined **)(param_1 + 0x4a0c) = puVar1;
  *(undefined **)(param_1 + 0x4a08) = puVar2;
  return;
}

/* _gleVPBeginTrianglesTCL @ 0x1070dc (52 bytes) */
int _gleVPBeginTrianglesTCL(param_1)
  int param_1;
{
  undefined *puVar1;
  
  puVar1 = PTR__gleVPFlushAtomicTCL_00111628;
  *(undefined4 *)(param_1 + 0x4858) = *(undefined4 *)(param_1 + 0x4854);
  *(undefined **)(param_1 + 0x4a0c) = puVar1;
  *(undefined **)(param_1 + 0x4a08) = PTR__gleRenderTrianglesTCLFunc_001122d4;
  return;
}

/* _gleVPBeginTriangleStripTCL @ 0x107110 (52 bytes) */
int _gleVPBeginTriangleStripTCL(param_1)
  int param_1;
{
  undefined *puVar1;
  
  puVar1 = PTR__gleVPFlushTriQuadStripTCL_0011161c;
  *(undefined4 *)(param_1 + 0x4858) = *(undefined4 *)(param_1 + 0x4854);
  *(undefined **)(param_1 + 0x4a0c) = puVar1;
  *(undefined **)(param_1 + 0x4a08) = PTR__gleRenderTriangleStripTCLFunc_001122b8;
  return;
}

/* _gleVPBeginTriangleFanTCL @ 0x107144 (52 bytes) */
int _gleVPBeginTriangleFanTCL(param_1)
  int param_1;
{
  undefined *puVar1;
  
  puVar1 = PTR__gleVPFlushTriangleFanTCL_00111618;
  *(undefined4 *)(param_1 + 0x4858) = *(undefined4 *)(param_1 + 0x4854);
  *(undefined **)(param_1 + 0x4a0c) = puVar1;
  *(undefined **)(param_1 + 0x4a08) = PTR__gleRenderTriangleFanTCLFunc_00112298;
  return;
}

/* _gleVPBeginQuadsTCL @ 0x107178 (52 bytes) */
int _gleVPBeginQuadsTCL(param_1)
  int param_1;
{
  undefined *puVar1;
  
  puVar1 = PTR__gleVPFlushAtomicTCL_00111628;
  *(undefined4 *)(param_1 + 0x4858) = *(undefined4 *)(param_1 + 0x4854);
  *(undefined **)(param_1 + 0x4a0c) = puVar1;
  *(undefined **)(param_1 + 0x4a08) = PTR__gleRenderQuadsTCLFunc_00112280;
  return;
}

