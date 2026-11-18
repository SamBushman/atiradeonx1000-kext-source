#include "decls.h"

/* _gleCreateGlobalLevel @ 0x103534 (64 bytes) */
int _gleCreateGlobalLevel(unusedArg1, param_2, param_3, param_4, param_5, param_6)
  undefined4 unusedArg1;
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
void _gleSynchronizePluginTextureLevels(glContext, param_2)
  int glContext;
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
    if (*(byte *)(glContext + 0x85a4) != 0) {
      piVar3 = (int *)(*(int *)(glContext + 0x5148) + 0x8054);
      do {
        iVar2 = *piVar3;
        piVar3 = piVar3 + 1;
        if (*(int *)(param_2 + 0x20) == iVar2) break;
        iVar4 = iVar4 + 1;
      } while (iVar4 < (int)(uint)*(byte *)(glContext + 0x85a4));
    }
    iVar2 = 0;
    if (bVar1 != 0) {
      iVar5 = 0;
      do {
        iVar6 = -(uint)(iVar2 == 0);
        iVar7 = (uint)(iVar2 == 0) * -0x18 + param_2 + iVar5 + 0xc4;
        do {
          if ((*(byte *)(iVar7 + 0xb) & 0x50) == 0x40) {
            _gleUploadPluginTextureLevel(glContext,param_2,iVar7,iVar2,iVar6,iVar4);
            _gleModifyPluginTextureLevel
                      (glContext,param_2,iVar7,iVar2,iVar6,0,0,0,(uint)*(ushort *)(iVar7 + 4),
                       (uint)*(ushort *)(iVar7 + 6),(uint)*(ushort *)(iVar7 + 8));
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
void _gleSynchronizePluginTextures(param_1)
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
        ((void (*)())_gleSynchronizePluginTextureLevels)(param_1,iVar1 + 0x10);
      }
      iVar4 = iVar4 + -1;
    } while (-1 < iVar4);
    iVar2 = iVar2 + 1;
    iVar3 = iVar3 + 0x14;
  } while (iVar2 < 0x10);
  return;
}

/* _gleTextureTargetExtractor @ 0x103714 (116 bytes) */
int _gleTextureTargetExtractor(unusedArg1, param_2)
  undefined4 unusedArg1;
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
int _gleTexEnableBits(glContext)
  int glContext;
{
  bool bVar1;
  int iVar2;
  uint *puVar3;
  uint uVar4;
  
  uVar4 = 0;
  bVar1 = *(char *)(glContext + 0x466c) != '\0';
  if ((bVar1) || (*(int *)(glContext + 0x5438) != 0)) {
    iVar2 = 0;
    if (bVar1) {
      iVar2 = *(int *)(glContext + 0x5424);
      if (*(short *)(iVar2 + 0x4c8) == -0x7e00) {
        return (uint)*(byte *)(iVar2 + 0x4eb);
      }
      iVar2 = *(int *)(iVar2 + 0x4cc);
    }
    if (*(int *)(glContext + 0x5438) != 0) {
      iVar2 = *(int *)(*(int *)(*(int *)(glContext + 0x5430) + 0x24) + 0x508);
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
    uVar4 = *(uint *)(glContext + 0x514c);
  }
  return uVar4;
}

/* _gleTextureMatTransDivW_body @ 0x103860 (252 bytes) */
void _gleTextureMatTransDivW_body(int param_1,uint param_2,int param_3,int param_4,double unusedFloatArg1,double unusedFloatArg2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11)
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
  fVar4 = *(float *)(0x1fcc + iVar22);
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
           (fVar20 * fVar13 + (fVar19 * fVar10 + (fVar17 * fVar4 + fVar18 * fVar7))) * fVar21;
      *(float *)(iVar22 + 0x80) =
           (fVar20 * fVar11 + (fVar19 * fVar8 + (fVar17 * fVar1 + fVar18 * fVar5))) * fVar21;
      *(float *)(iVar22 + 0x84) =
           (fVar20 * fVar12 + (fVar19 * fVar9 + (fVar17 * fVar3 + fVar18 * fVar6))) * fVar21;
      *(float *)(iVar22 + 0x88) =
           (fVar20 * fVar2 + (fVar19 * fVar16 + (fVar17 * fVar14 + fVar18 * fVar15))) * fVar21;
      uVar23 = uVar23 - 1;
    } while (uVar23 != 0);
  }
  return;
}

/* _gleTextureMatTransPtrDivW_body @ 0x103960 (264 bytes) */
void _gleTextureMatTransPtrDivW_body(int param_1,uint param_2,int param_3,int param_4,double unusedFloatArg1,double unusedFloatArg2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11)
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
  fVar4 = *(float *)(0x1fcc + iVar25);
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
      fVar24 = fVar20 * fVar13 + (fVar19 * fVar10 + (fVar17 * fVar4 + fVar18 * fVar7));
      fVar23 = fVar20 * fVar11 + (fVar19 * fVar8 + (fVar17 * fVar1 + fVar18 * fVar5));
      fVar22 = fVar20 * fVar12 + (fVar19 * fVar9 + (fVar17 * fVar3 + fVar18 * fVar6));
      fVar17 = fVar20 * fVar2 + (fVar19 * fVar16 + (fVar17 * fVar14 + fVar18 * fVar15));
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
void _gleMultiTextureMatTrans(param_1, param_2, param_3)
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
int _gleSubmitVertexCopy(glContext, param_2)
  int glContext;
  int param_2;
{
  short sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  sVar1 = *(short *)(glContext + 0x487c);
  iVar4 = 0;
  iVar5 = *(int *)(glContext + 0x4858);
  iVar3 = (int)sVar1 >> 3;
  if (0 < iVar3) {
    do {
      iVar2 = iVar4 * 8;
      iVar4 = iVar4 + 1;
      *(undefined8 *)(iVar5 + iVar2) = *(undefined8 *)(param_2 + iVar2);
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    sVar1 = *(short *)(glContext + 0x487c);
  }
  *(int *)(glContext + 0x4858) = iVar5 + sVar1;
                    
                    
  (**(code **)(glContext + 0x4de4))(glContext);
  return;
}

/* _gleForceToSoftwareTCL @ 0x103b38 (1520 bytes) */
undefined4 _gleForceToSoftwareTCL(int glContext,double fparam_1,double floatArg2,double floatArg3,double floatArg4,double floatArg5,double floatArg6,double floatArg7,double floatArg8)
{
  bool bVar1;
  char cVar2;
  undefined1 uVar3;
  int *piVar4;
  undefined4 uVar5;
  int iVar6;
  int incomingR5;
  undefined4 incomingR6;
  int incomingR7;
  undefined1 *puVar7;
  char *incomingR8;
  int iVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  undefined4 uVar13;
  int *piVar14;
  int iVar15;
  undefined4 uVar16;
  double f1AfterCall;
  double f1AfterCall1;
  char local_30 [16];
  
  local_30[0] = '\0';
  iVar10 = *(int *)(glContext + 0x4854);
  if (*(int *)(glContext + 0x48d0) == 0) {
    iVar11 = *(int *)(glContext + 0x4858) - iVar10 >> 8;
  }
  else {
    incomingR8 = local_30;
    iVar11 = (*(int *)(glContext + 0x4858) - *(int *)(glContext + 0x4868)) /
             (int)*(short *)(glContext + 0x487c);
    *(int *)(glContext + 0x4858) = iVar10 + iVar11 * 0x100;
    incomingR7 = iVar10;
    _gleDecomposePrimitiveVertices
              (glContext,*(int *)(glContext + 0x48d0),iVar11,*(int *)(glContext + 0x4868),iVar10,incomingR8);
    if (local_30[0] != '\0') {
      iVar10 = *(int *)(glContext + 0x758c);
    }
    incomingR6 = 0;
    incomingR5 = (int)*(short *)(glContext + 0x4a12);
    (**(code **)(glContext + 0x46ec))(*(undefined4 *)(glContext + 0x4688),2,incomingR5,0);
    fparam_1 = f1AfterCall;
  }
  iVar12 = iVar11 + -1;
  iVar8 = *(int *)(glContext + 0x50ac);
  *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x10000000;
  if (iVar8 != 0 || (*(uint *)(glContext + 0x505c) & *(uint *)(glContext + 0x50b0)) != 0) {
    _gleUpdateMatrixFunc(glContext);
    fparam_1 = f1AfterCall1;
  }
  if (*(char *)(glContext + 0x4691) == '\0') goto LAB_00103dec;
  iVar6 = *(int *)(glContext + 0x744c);
  piVar14 = (int *)(glContext + 0x310);
  cVar2 = *(char *)(*(int *)(glContext + 0x468c) + 0x79);
  if ((iVar6 != 0) && (*(int *)(iVar6 + 0xec) != 0)) {
    ((void (*)())_gleUpdateFramebufferCompleteness)(glContext,iVar6 + 0x10,incomingR5,incomingR6,incomingR7,incomingR8,iVar8,fparam_1,floatArg2,floatArg3,
               floatArg4,floatArg5,floatArg6,floatArg7,floatArg8);
    *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x80000000;
  }
  if ((*(char *)(glContext + 0x4664) == '\0') && (*(int *)(glContext + 0x5430) == 0)) {
LAB_00103ce4:
    uVar9 = *(uint *)(glContext + 0x31c);
  }
  else {
    iVar8 = 0;
    piVar4 = (int *)(glContext + 0x324);
    do {
      iVar6 = *piVar4;
      piVar4 = piVar4 + 1;
      if (iVar6 != 0) {
        *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x800000;
        break;
      }
      iVar8 = iVar8 + 1;
    } while (iVar8 < 9);
    uVar9 = *(uint *)(glContext + 0x31c);
    if ((uVar9 & 0x15555) != 0) {
      if (*(char *)(glContext + 0x2e54) != '\0') {
        _gleUpdateLightRGBASums(glContext,glContext + 0x2c20,0);
      }
      if (*(char *)(glContext + 0x3094) != '\0') {
        _gleUpdateLightRGBASums(glContext,glContext + 0x2e60,1);
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
    bVar1 = ((*piVar14 == 0 && *(int *)(glContext + 0x314) == 0) && uVar9 == 0) &&
            *(int *)(glContext + 800) == 0;
  }
  else {
    bVar1 = (((*piVar14 == 0 && *(int *)(glContext + 0x314) == 0) &&
             (*(uint *)(glContext + 0x318) & 0xfffffffd) == 0) && uVar9 == 0) &&
            *(int *)(glContext + 800) == 0;
  }
  if (!bVar1) {
    if (*(char *)(glContext + 0x85a8) == *(char *)(glContext + 0x85a6)) {
      uVar9 = (**(code **)(glContext + 0x4788))
                        (*(undefined4 *)(glContext + 0x4688),glContext + 0x4698,piVar14);
      if ((((uVar9 & 3) != (uint)*(byte *)(glContext + 0x7580)) ||
          ((uVar9 & 4) != (uint)*(byte *)(glContext + 0x7581))) ||
         ((uVar9 & 8) != (uint)(*(char *)(glContext + 0x759d) == '\0'))) {
        if ((uVar9 & 4) == 0) {
          uVar9 = uVar9 & 0xfffffffe;
          *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x10000000;
        }
        _gleUpdateDispatchCodeChange(glContext,uVar9);
      }
    }
    else {
      _gleSwitchToNonRevertRenderer(glContext);
    }
  }
  iVar8 = 0x13;
  do {
    *piVar14 = 0;
    piVar14 = piVar14 + 1;
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
LAB_00103dec:
  *(undefined4 *)(glContext + 0x4884) = *(undefined4 *)(glContext + 0x4888);
  if (*(char *)(glContext + 0x30aa) == '\0') {
    if (-1 < iVar12) {
      puVar7 = (undefined1 *)(iVar10 + 0x7e);
      do {
        puVar7[-1] = *(undefined1 *)(glContext + 0x2ed);
        *puVar7 = *(undefined1 *)(glContext + 0x2ee);
        puVar7 = puVar7 + 0x100;
        iVar11 = iVar11 + -1;
      } while (iVar11 != 0);
    }
  }
  else if (*(char *)(glContext + 0x4df8) == '\0') {
    if (*(char *)(glContext + 0x30ac) == '\0') {
      iVar8 = *(int *)(glContext + 0x4dd0);
      *(undefined4 *)(iVar8 + 0x1e0) = 1;
      if (-1 < iVar12) {
        do {
          *(undefined1 *)(iVar10 + 0x7d) = *(undefined1 *)(glContext + 0x2ed);
          uVar3 = *(undefined1 *)(glContext + 0x2ee);
          *(int *)(iVar10 + 0x74) = iVar8;
          *(undefined1 *)(iVar10 + 0x7e) = uVar3;
          iVar10 = iVar10 + 0x100;
          iVar11 = iVar11 + -1;
        } while (iVar11 != 0);
      }
    }
    else {
      iVar8 = *(int *)(glContext + 0x4dd0);
      iVar6 = *(int *)(glContext + 0x4dd4);
      *(undefined4 *)(iVar8 + 0x1e0) = 1;
      *(undefined4 *)(iVar6 + 0x1e0) = 1;
      if (-1 < iVar12) {
        do {
          *(undefined1 *)(iVar10 + 0x7d) = *(undefined1 *)(glContext + 0x2ed);
          uVar3 = *(undefined1 *)(glContext + 0x2ee);
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
    (**(code **)(glContext + 0x4de0))(glContext,iVar11);
    if (*(char *)(glContext + 0x30ac) == '\0') {
      iVar8 = 0;
      iVar6 = iVar12;
      iVar15 = iVar10;
      if (0 < iVar12) {
        do {
          *(undefined1 *)(iVar15 + 0x7d) = *(undefined1 *)(glContext + 0x2ed);
          *(undefined1 *)(iVar15 + 0x7e) = *(undefined1 *)(glContext + 0x2ee);
          iVar8 = *(int *)(glContext + 0x4dd0);
          *(undefined4 *)(iVar8 + 0x1e0) = 1;
          *(int *)(iVar15 + 0x74) = iVar8;
          if (((*(float *)(iVar15 + 0x30) != *(float *)(iVar15 + 0x130)) ||
              (*(float *)(iVar15 + 0x34) != *(float *)(iVar15 + 0x134))) ||
             ((*(float *)(iVar15 + 0x38) != *(float *)(iVar15 + 0x138) ||
              (*(float *)(iVar15 + 0x3c) != *(float *)(iVar15 + 0x13c))))) {
            (**(code **)(glContext + 0x4de0))(glContext,iVar11);
          }
          iVar6 = iVar6 + -1;
          iVar11 = iVar11 + 0x100;
          iVar8 = iVar12;
          iVar15 = iVar15 + 0x100;
        } while (iVar6 != 0);
      }
      iVar11 = *(int *)(glContext + 0x4dd0);
      *(undefined4 *)(iVar11 + 0x1e0) = 1;
      *(int *)(iVar8 * 0x100 + iVar10 + 0x74) = iVar11;
    }
    else {
      iVar8 = 0;
      iVar6 = iVar12;
      iVar15 = iVar10;
      if (0 < iVar12) {
        do {
          *(undefined1 *)(iVar15 + 0x7d) = *(undefined1 *)(glContext + 0x2ed);
          *(undefined1 *)(iVar15 + 0x7e) = *(undefined1 *)(glContext + 0x2ee);
          iVar8 = *(int *)(glContext + 0x4dd0);
          *(undefined4 *)(iVar8 + 0x1e0) = 1;
          *(int *)(iVar15 + 0x74) = iVar8;
          iVar8 = *(int *)(glContext + 0x4dd4);
          *(undefined4 *)(iVar8 + 0x1e0) = 1;
          *(int *)(iVar15 + 0x78) = iVar8;
          if (((*(float *)(iVar15 + 0x30) != *(float *)(iVar15 + 0x130)) ||
              (*(float *)(iVar15 + 0x34) != *(float *)(iVar15 + 0x134))) ||
             ((*(float *)(iVar15 + 0x38) != *(float *)(iVar15 + 0x138) ||
              (*(float *)(iVar15 + 0x3c) != *(float *)(iVar15 + 0x13c))))) {
            (**(code **)(glContext + 0x4de0))(glContext,iVar11);
          }
          iVar6 = iVar6 + -1;
          iVar11 = iVar11 + 0x100;
          iVar8 = iVar12;
          iVar15 = iVar15 + 0x100;
        } while (iVar6 != 0);
      }
      iVar11 = *(int *)(glContext + 0x4dd0);
      iVar10 = iVar8 * 0x100 + iVar10;
      *(undefined4 *)(iVar11 + 0x1e0) = 1;
      *(int *)(iVar10 + 0x74) = iVar11;
      iVar11 = *(int *)(glContext + 0x4dd4);
      *(undefined4 *)(iVar11 + 0x1e0) = 1;
      *(int *)(iVar10 + 0x78) = iVar11;
    }
  }
  if (local_30[0] == '\0') {
    uVar13 = *(undefined4 *)(glContext + 0x486c);
    uVar16 = *(undefined4 *)(glContext + 0x4858);
    uVar5 = (**(code **)(*(short *)(glContext + 0x4a10) * 4 + glContext + 0x49e0))(glContext);
    *(undefined4 *)(glContext + 0x4858) = uVar16;
    *(undefined4 *)(glContext + 0x486c) = uVar13;
  }
  else {
    uVar13 = *(undefined4 *)(glContext + 0x486c);
    uVar5 = (**(code **)(*(short *)(glContext + 0x4a10) * 4 + glContext + 0x49e0))(glContext);
    iVar10 = *(int *)(glContext + 0x7588);
    *(undefined4 *)(glContext + 0x486c) = uVar13;
    iVar11 = *(int *)(glContext + 0x758c);
    for (; iVar10 != 0; iVar10 = iVar10 + -1) {
      uVar5 = ((int (*)())_gleSubmitVertexCopy)(glContext,iVar11);
      iVar11 = iVar11 + 0x100;
    }
  }
  return uVar5;
}

/* _gleTypeSize @ 0x104128 (84 bytes) */
int _gleTypeSize(unusedArg1, param_2)
  undefined4 unusedArg1;
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
int _gleBindVertexArray(glContext, param_2)
  int glContext;
  int param_2;
{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = *(int *)(glContext + 0x5148) + 0x5014;
  if (param_2 == 0) {
    iVar1 = *(int *)(glContext + 0x4a64);
  }
  else {
    iVar1 = _gleLookupHashObject(iVar3,param_2);
    if (iVar1 == 0) {
      iVar1 = _gleCreateVertexArrayObject(glContext,param_2);
      _gleCreatePluginVertexArray(glContext,iVar1 + 0x10);
      _gleAddHashNameAndObject(glContext,iVar3,iVar1);
    }
  }
  *(int *)(iVar1 + 8) = *(int *)(iVar1 + 8) + 1;
  iVar4 = *(int *)(glContext + 0x4a60);
  uVar2 = _gleSetCurrentVertexObject(glContext,iVar1);
  iVar3 = *(int *)(iVar4 + 8) + -1;
  *(int *)(iVar4 + 8) = iVar3;
  if (iVar3 == 0) {
    uVar2 = _gleFreeVertexArrayObject(glContext,iVar4);
    return uVar2;
  }
  return uVar2;
}

/* _gleReclaimVertexArrayResources @ 0x104260 (352 bytes) */
void _gleReclaimVertexArrayResources(glContext)
  int glContext;
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
  
  iVar3 = *(int *)(glContext + 0x5148);
  piVar8 = (int *)(iVar3 + 0x5014);
  do {
    piVar5 = piVar8 + 1;
    for (piVar8 = (int *)*piVar8; piVar8 != (int *)0x0; piVar8 = (int *)*piVar8) {
      if (piVar8[2] == 1) {
        iVar6 = 0;
        if (*(char *)(glContext + 0x85a4) != '\0') {
          iVar7 = (int)(piVar8 + 0x118);
          puVar9 = piVar8 + 4;
          iVar10 = glContext + 0x10000;
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
          } while (iVar6 < (int)(uint)*(byte *)(glContext + 0x85a4));
        }
        piVar8[0xd4] = piVar8[0xd4];
        piVar8[0xd5] = piVar8[0xd5] | 1;
      }
    }
    piVar8 = piVar5;
  } while ((int)piVar5 <= iVar3 + 0x6010);
  iVar3 = *(int *)(glContext + 0x4a64);
  if (*(int *)(iVar3 + 8) == 1) {
    iVar6 = glContext + 0x10000;
    iVar7 = 0;
    if (*(char *)(glContext + 0x85a4) != '\0') {
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
      } while (iVar7 < (int)(uint)*(byte *)(glContext + 0x85a4));
    }
  }
  return;
}

/* _gleVPFlipColors @ 0x1043c0 (404 bytes) */
double _gleVPFlipColors(param_1, param_2, param_3, param_4)
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
void _gleVPRenderPoints(glContext)
  int glContext;
{
  int iVar1;
  uint uVar2;
  code *UNRECOVERED_JUMPTABLE;
  undefined4 uVar3;
  uint uVar4;
  undefined4 uVar5;
  
  iVar1 = ((int (*)())_gleTexEnableBits)(glContext);
  if ((((int)*(short *)(glContext + 0x487c) == 0) ||
      (uVar4 = (uint)(*(int *)(glContext + 0x4858) - *(int *)(glContext + 0x4854)) /
               (uint)(int)*(short *)(glContext + 0x487c), (int)uVar4 < 1)) ||
     (uVar2 = _gleVPEmulate(glContext,uVar4), (uVar2 & 0xff00) != 0)) {
    return;
  }
  uVar5 = *(undefined4 *)(glContext + 0x4864);
  if (((uVar2 & 0xff) == 0) && (*(char *)(glContext + 0x4e18) == '\0')) {
    if (iVar1 != 0) {
      (**(code **)(glContext + 0x506c))(glContext,uVar5,uVar4,0);
    }
    UNRECOVERED_JUMPTABLE = *(code **)(glContext + 0x46b0);
    uVar3 = uVar5;
  }
  else {
    if (iVar1 != 0) {
      (**(code **)(glContext + 0x5074))(glContext,uVar5,uVar4,0);
    }
    uVar3 = *(undefined4 *)(glContext + 0x4870);
    uVar4 = _gleClipPoints(glContext,uVar5,uVar4,uVar3);
    if (uVar4 == 0) {
      return;
    }
    if ((*(char *)(glContext + 0x4e18) != '\0') &&
       (uVar4 = _gleClipPointsPlane(glContext,uVar3,uVar4), uVar4 == 0)) {
      return;
    }
    UNRECOVERED_JUMPTABLE = *(code **)(glContext + 0x46d8);
  }
                    
                    
  (*UNRECOVERED_JUMPTABLE)(*(undefined4 *)(glContext + 0x4688),uVar3,uVar4);
  return;
}

/* _gleVPRenderLines @ 0x104698 (420 bytes) */
void _gleVPRenderLines(glContext)
  int glContext;
{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint *puVar4;
  uint uVar5;
  uint uVar6;
  uint *puVar7;
  double f1AfterCall;
  double fparam_1;
  
  iVar2 = ((int (*)())_gleTexEnableBits)(glContext);
  if ((((int)*(short *)(glContext + 0x487c) != 0) &&
      (uVar5 = (uint)(*(int *)(glContext + 0x4858) - *(int *)(glContext + 0x4854)) /
               (uint)(int)*(short *)(glContext + 0x487c), 1 < (int)uVar5)) &&
     (uVar3 = _gleVPEmulate(glContext,uVar5), (uVar3 & 0xff00) == 0)) {
    uVar6 = *(uint *)(glContext + 0x4864);
    if (((uVar3 & 0xff) == 0) && (*(char *)(glContext + 0x4e18) == '\0')) {
      if (iVar2 != 0) {
        (**(code **)(glContext + 0x506c))(glContext,uVar6,uVar5,0);
      }
                    
                    
      (**(code **)(glContext + 0x46b4))(*(undefined4 *)(glContext + 0x4688),uVar6,uVar5);
      return;
    }
    fparam_1 = f1AfterCall;
    if (iVar2 != 0) {
      fparam_1 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x5074))(glContext, uVar6, uVar5, 0);
    }
    uVar1 = uVar6 + uVar5 * 0x100;
    puVar7 = *(uint **)(glContext + 0x4870);
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
    if ((*(char *)(glContext + 0x4e18) != '\0') &&
       (uVar5 = ((int (*)())_gleClipLinesPlane)(glContext,puVar7,uVar5,fparam_1), uVar5 == 0)) {
      return;
    }
    if (((uVar3 & 0xff) == 0) ||
       (uVar5 = _gleClipLines(glContext,puVar7,uVar5,uVar3 & 0xff), uVar5 != 0)) {
                    
                    
      (**(code **)(glContext + 0x46dc))(*(undefined4 *)(glContext + 0x4688),puVar7,uVar5,2);
      return;
    }
  }
  return;
}

/* _gleVPRenderLineStrip @ 0x10483c (436 bytes) */
void _gleVPRenderLineStrip(glContext)
  int glContext;
{
  char cVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  code *UNRECOVERED_JUMPTABLE;
  uint *puVar5;
  uint *puVar6;
  uint uVar7;
  uint uVar8;
  uint *puVar9;
  double f1AfterCall;
  double fparam_1;
  double f1AfterCall1;
  
  iVar3 = ((int (*)())_gleTexEnableBits)(glContext);
  if ((((int)*(short *)(glContext + 0x487c) == 0) ||
      (uVar7 = (uint)(*(int *)(glContext + 0x4858) - *(int *)(glContext + 0x4854)) /
               (uint)(int)*(short *)(glContext + 0x487c), (int)uVar7 < 2)) ||
     (uVar4 = _gleVPEmulate(glContext,uVar7), (uVar4 & 0xff00) != 0)) {
    return;
  }
  puVar9 = *(uint **)(glContext + 0x4864);
  if (((uVar4 & 0xff) == 0) && (*(char *)(glContext + 0x4e18) == '\0')) {
    if (iVar3 != 0) {
      (**(code **)(glContext + 0x506c))(glContext,puVar9,uVar7,0);
    }
    cVar1 = *(char *)(glContext + 0x4a18);
    UNRECOVERED_JUMPTABLE = *(code **)(glContext + 0x46b8);
    puVar5 = puVar9;
  }
  else {
    fparam_1 = f1AfterCall;
    if (iVar3 != 0) {
      fparam_1 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x5074))(glContext, puVar9, uVar7, 0);
    }
    puVar5 = *(uint **)(glContext + 0x4870);
    uVar8 = *(uint *)(glContext + 0x4854);
    puVar2 = puVar9;
    puVar6 = puVar5;
    while (puVar2 < puVar9 + uVar7 * 0x40 + -0x40) {
      *puVar6 = (uint)puVar2;
      _memcpy(uVar8,puVar2 + 0x40,0x100);
      puVar6[1] = uVar8;
      uVar8 = uVar8 + 0x100;
      puVar6 = puVar6 + 2;
      puVar2 = puVar2 + 0x40;
      fparam_1 = f1AfterCall1;
    }
    uVar7 = (int)puVar6 - (int)puVar5 >> 2;
    if ((*(char *)(glContext + 0x4e18) != '\0') &&
       (uVar7 = ((int (*)())_gleClipLinesPlane)(glContext,puVar5,uVar7,fparam_1), uVar7 == 0)) {
      return;
    }
    if (((uVar4 & 0xff) != 0) &&
       (uVar7 = _gleClipLines(glContext,puVar5,uVar7,uVar4 & 0xff), uVar7 == 0)) {
      return;
    }
    cVar1 = *(char *)(glContext + 0x4a18);
    UNRECOVERED_JUMPTABLE = *(code **)(glContext + 0x46dc);
  }
                    
                    
  (*UNRECOVERED_JUMPTABLE)(*(undefined4 *)(glContext + 0x4688),puVar5,uVar7,cVar1 == '\0');
  return;
}

/* _gleVPRenderLineLoop @ 0x1049f0 (540 bytes) */
void _gleVPRenderLineLoop(glContext)
  int glContext;
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
  uint uVar15;
  double f1AfterCall;
  double fparam_1;
  double f1AfterCall1;
  
  iVar4 = ((int (*)())_gleTexEnableBits)(glContext);
  sVar8 = *(short *)(glContext + 0x487c);
  iVar13 = *(int *)(glContext + 0x4854);
  if ((int)sVar8 != 0) {
    iVar6 = *(int *)(glContext + 0x4858);
    uVar12 = (uint)(iVar6 - iVar13) / (uint)(int)sVar8;
    if (*(short *)(glContext + 0x4a10) < 0) {
      if ((int)uVar12 < 1) {
        return;
      }
      iVar7 = iVar13 + -0x100;
      if (*(char *)(glContext + 0x4a18) == '\0') {
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
        sVar8 = *(short *)(glContext + 0x487c);
      }
      uVar12 = uVar12 + 1;
      *(int *)(glContext + 0x4858) = iVar6 + sVar8;
    }
    uVar5 = _gleVPEmulate(glContext,uVar12);
    if ((uVar5 & 0xff00) == 0) {
      puVar14 = *(uint **)(glContext + 0x4864);
      if (((uVar5 & 0xff) == 0) && (*(char *)(glContext + 0x4e18) == '\0')) {
        if (iVar4 != 0) {
          (**(code **)(glContext + 0x506c))(glContext,puVar14,uVar12,0);
        }
        cVar1 = *(char *)(glContext + 0x4a18);
        UNRECOVERED_JUMPTABLE = *(code **)(glContext + 0x46b8);
        puVar10 = puVar14;
      }
      else {
        fparam_1 = f1AfterCall;
        if (iVar4 != 0) {
          fparam_1 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x5074))(glContext, puVar14, uVar12, 0);
        }
        puVar10 = *(uint **)(glContext + 0x4870);
        uVar15 = *(uint *)(glContext + 0x4854);
        puVar3 = puVar14;
        puVar11 = puVar10;
        while (puVar3 < puVar14 + uVar12 * 0x40 + -0x40) {
          *puVar11 = (uint)puVar3;
          _memcpy(uVar15,puVar3 + 0x40,0x100);
          puVar11[1] = uVar15;
          uVar15 = uVar15 + 0x100;
          puVar11 = puVar11 + 2;
          puVar3 = puVar3 + 0x40;
          fparam_1 = f1AfterCall1;
        }
        uVar12 = (int)puVar11 - (int)puVar10 >> 2;
        if ((*(char *)(glContext + 0x4e18) != '\0') &&
           (uVar12 = ((int (*)())_gleClipLinesPlane)(glContext,puVar10,uVar12,fparam_1), uVar12 == 0)) {
          return;
        }
        if (((uVar5 & 0xff) != 0) &&
           (uVar12 = _gleClipLines(glContext,puVar10,uVar12,uVar5 & 0xff), uVar12 == 0)) {
          return;
        }
        cVar1 = *(char *)(glContext + 0x4a18);
        UNRECOVERED_JUMPTABLE = *(code **)(glContext + 0x46dc);
      }
                    
                    
      (*UNRECOVERED_JUMPTABLE)(*(undefined4 *)(glContext + 0x4688),puVar10,uVar12,cVar1 == '\0');
      return;
    }
  }
  return;
}

/* _gleVPRenderTriangles_body @ 0x104c10 (876 bytes) */
void _gleVPRenderTriangles_body(glContext)
  int glContext;
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
  double f1AfterCall;
  double dVar17;
  double extraout_f1_00;
  double f1AfterCall2;
  double incomingFpr2;
  double incomingFpr3;
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  double incomingStack_ffffff78;
  double incomingStack_ffffff80;
  int local_50;
  int local_4c [5];
  
  iVar11 = -1;
  iVar6 = ((int (*)())_gleTexEnableBits)(glContext);
  bVar1 = *(byte *)(glContext + 0x4666);
  cVar2 = *(char *)(glContext + 0x34de);
  if ((((int)*(short *)(glContext + 0x487c) != 0) &&
      (uVar13 = (uint)(*(int *)(glContext + 0x4858) - *(int *)(glContext + 0x4854)) /
                (uint)(int)*(short *)(glContext + 0x487c), 2 < (int)uVar13)) &&
     (uVar7 = _gleVPEmulate(glContext,uVar13), (uVar7 & 0xff00) == 0)) {
    uVar16 = *(uint *)(glContext + 0x4864);
    if (((uVar7 & 0xff) == 0) && (*(char *)(glContext + 0x4e18) == '\0')) {
      dVar17 = f1AfterCall;
      if (iVar6 != 0) {
        dVar17 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x506c))(glContext, uVar16, uVar13, 0);
      }
      if (cVar2 == '\0') {
        (**(code **)(glContext + 0x46c4))
                  (*(undefined4 *)(glContext + 0x4688),uVar16,uVar13,
                   *(ushort *)(glContext + 0x34d0) - 0x1b00);
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
              iVar8 = ((undefined4 (*)())_gleCullTriangle)(glContext,uVar16,uVar16 + 0x100,uVar16 + 0x200,0,&local_50,
                                       dVar17,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,
                                       incomingStack_ffffff78,incomingStack_ffffff80);
              dVar17 = dVar17;
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
                ((double (*)())_gleVPFlipColors)(glContext,uVar15,iVar6,iVar11);
              }
              if (iVar11 == 0) {
                uVar3 = *(ushort *)(glContext + 0x34d0);
              }
              else {
                uVar3 = *(ushort *)(glContext + 0x34d2);
              }
              dVar17 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x46c4))
                                         (*(undefined4 *)(glContext + 0x4688), uVar15, iVar6, uVar3 - 0x1b00);
            }
          }
          uVar16 = uVar7;
        } while (uVar7 <= uVar13);
      }
    }
    else {
      dVar17 = f1AfterCall;
      if (iVar6 != 0) {
        dVar17 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x5074))(glContext, uVar16, uVar13, 0);
      }
      puVar12 = *(uint **)(glContext + 0x4870);
      uVar13 = (uVar16 + uVar13 * 0x100) - 0x300;
      puVar9 = *(uint **)(glContext + 0x4874);
      if (uVar16 <= uVar13) {
        do {
          puVar12[1] = uVar16 + 0x100;
          puVar12[2] = uVar16 + 0x200;
          *puVar12 = uVar16;
          *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
          puVar10 = puVar9;
          puVar5 = puVar12;
          iVar11 = 3;
          if ((*(char *)(glContext + 0x4e18) == '\0') ||
             (dVar17 = (double)((double (*)())_gleClipPolyPlane)(glContext,puVar12,3,puVar9,local_4c,dVar17,incomingFpr2,
                                                 incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,
                                                 incomingStack_ffffff78,incomingStack_ffffff80),
             puVar10 = puVar12, puVar5 = puVar9, iVar11 = local_4c[0], local_4c[0] != 0)) {
            puVar12 = puVar5;
            puVar9 = puVar10;
            if ((uVar7 & 0xff) != 0) {
              dVar17 = (double)_gleClipPoly(glContext,puVar12,iVar11,uVar7 & 0xff,puVar10,local_4c,1);
              if (local_4c[0] == 0) goto LAB_00104f54;
              if (0 < local_4c[0]) {
                puVar9 = puVar12;
                puVar12 = puVar10;
                iVar11 = local_4c[0];
              }
            }
            if ((cVar2 == '\0') ||
               (iVar6 = _gleCullPolygonPtrStack(glContext,puVar12,iVar11,&local_50),
               dVar17 = f1AfterCall2, iVar6 == 0)) {
              iVar6 = local_50;
              if (((int)-(uint)bVar1 < 0) && (puVar10 = puVar12, iVar8 = iVar11, 0 < iVar11)) {
                do {
                  ((double (*)())_gleVPFlipColors)(glContext,*puVar10,1,iVar6);
                  iVar8 = iVar8 + -1;
                  puVar10 = puVar10 + 1;
                } while (iVar8 != 0);
              }
              if (iVar6 == 0) {
                uVar3 = *(ushort *)(glContext + 0x34d0);
              }
              else {
                uVar3 = *(ushort *)(glContext + 0x34d2);
              }
              dVar17 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x46e0))
                                         (*(undefined4 *)(glContext + 0x4688), puVar12, iVar11, uVar3 - 0x1b00);
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

/* _gleVPRenderTriangleStrip_body @ 0x104f80 (1040 bytes) */
void _gleVPRenderTriangleStrip_body(glContext)
  int glContext;
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
  double f1AfterCall;
  double dVar21;
  double f1AfterCall1;
  double f1AfterCall2;
  double incomingFpr2;
  double incomingFpr3;
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  double incomingStack_ffffff78;
  double incomingStack_ffffff80;
  int local_50;
  int local_4c [4];
  
  iVar11 = -1;
  iVar7 = ((int (*)())_gleTexEnableBits)(glContext);
  bVar1 = *(byte *)(glContext + 0x4666);
  cVar2 = *(char *)(glContext + 0x34de);
  uVar12 = 0;
  if ((((int)*(short *)(glContext + 0x487c) != 0) &&
      (uVar18 = (uint)(*(int *)(glContext + 0x4858) - *(int *)(glContext + 0x4854)) /
                (uint)(int)*(short *)(glContext + 0x487c), 2 < (int)uVar18)) &&
     (uVar8 = _gleVPEmulate(glContext,uVar18), (uVar8 & 0xff00) == 0)) {
    uVar20 = *(uint *)(glContext + 0x4864);
    if (((uVar8 & 0xff) == 0) && (*(char *)(glContext + 0x4e18) == '\0')) {
      dVar21 = f1AfterCall;
      if (iVar7 != 0) {
        dVar21 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x506c))(glContext, uVar20, uVar18, 0);
      }
      if (cVar2 == '\0') {
        (**(code **)(glContext + 0x46cc))
                  (*(undefined4 *)(glContext + 0x4688),uVar20,uVar18,
                   *(ushort *)(glContext + 0x34d0) - 0x1b00);
      }
      else {
        piVar15 = *(int **)(glContext + 0x4870);
        uVar8 = 0;
        uVar18 = (uVar20 + uVar18 * 0x100) - 0x300;
        do {
          bVar4 = false;
          iVar7 = 0;
          uVar10 = uVar8;
          uVar5 = uVar20;
          while (uVar8 = uVar10, uVar20 <= uVar18) {
            uVar19 = uVar20 + 0x100;
            iVar9 = ((undefined4 (*)())_gleCullTriangle)(glContext,uVar20,uVar19,uVar20 + 0x200,uVar10,&local_50,dVar21,
                                     incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,incomingStack_ffffff78,
                                     incomingStack_ffffff80);
            dVar21 = f1AfterCall1;
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
              ((double (*)())_gleVPFlipColors)(glContext,uVar5,iVar9,iVar11);
            }
            uVar10 = uVar5;
            if (uVar12 != 0) {
              uVar10 = uVar5 + 0x100;
              *piVar15 = uVar5 + 0x200;
              piVar15[2] = uVar5;
              piVar15[1] = uVar10;
              if (iVar11 != 0) {
                uVar3 = *(ushort *)(glContext + 0x34d2);
              }
              else {
                uVar3 = *(ushort *)(glContext + 0x34d0);
              }
              iVar9 = iVar7 + 1;
              dVar21 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x46e0))
                                         (*(undefined4 *)(glContext + 0x4688), piVar15, 3, uVar3 - 0x1b00);
              if (iVar9 < 3) goto LAB_001051b4;
            }
            if (iVar11 != 0) {
              uVar3 = *(ushort *)(glContext + 0x34d2);
            }
            else {
              uVar3 = *(ushort *)(glContext + 0x34d0);
            }
            dVar21 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x46cc))
                                       (*(undefined4 *)(glContext + 0x4688), uVar10, iVar9, uVar3 - 0x1b00);
          }
LAB_001051b4: ;
        } while (uVar20 <= uVar18);
      }
    }
    else {
      dVar21 = f1AfterCall;
      if (iVar7 != 0) {
        dVar21 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x5074))(glContext, uVar20, uVar18, 0);
      }
      puVar17 = *(uint **)(glContext + 0x4870);
      uVar12 = (uVar20 + uVar18 * 0x100) - 0x300;
      puVar13 = *(uint **)(glContext + 0x4874);
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
          *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
          puVar14 = puVar13;
          puVar6 = puVar17;
          iVar11 = 3;
          if ((*(char *)(glContext + 0x4e18) == '\0') ||
             (dVar21 = (double)((double (*)())_gleClipPolyPlane)(glContext,puVar17,3,puVar13,local_4c,dVar21,incomingFpr2,
                                                 incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,
                                                 incomingStack_ffffff78,incomingStack_ffffff80),
             puVar14 = puVar17, puVar6 = puVar13, iVar11 = local_4c[0], local_4c[0] != 0)) {
            puVar17 = puVar6;
            puVar13 = puVar14;
            if ((uVar8 & 0xff) != 0) {
              dVar21 = (double)_gleClipPoly(glContext,puVar17,iVar11,uVar8 & 0xff,puVar14,local_4c,1);
              if (local_4c[0] == 0) goto LAB_00105368;
              if (0 < local_4c[0]) {
                puVar13 = puVar17;
                puVar17 = puVar14;
                iVar11 = local_4c[0];
              }
            }
            if ((cVar2 == '\0') ||
               (iVar7 = _gleCullPolygonPtrStack(glContext,puVar17,iVar11,&local_50),
               dVar21 = f1AfterCall2, iVar7 == 0)) {
              iVar7 = local_50;
              if (((int)-(uint)bVar1 < 0) && (puVar14 = puVar17, iVar9 = iVar11, 0 < iVar11)) {
                do {
                  ((double (*)())_gleVPFlipColors)(glContext,*puVar14,1,iVar7);
                  iVar9 = iVar9 + -1;
                  puVar14 = puVar14 + 1;
                } while (iVar9 != 0);
              }
              if (iVar7 == 0) {
                uVar3 = *(ushort *)(glContext + 0x34d0);
              }
              else {
                uVar3 = *(ushort *)(glContext + 0x34d2);
              }
              dVar21 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x46e0))
                                         (*(undefined4 *)(glContext + 0x4688), puVar17, iVar11, uVar3 - 0x1b00);
            }
          }
LAB_00105368: ;
        } while (uVar20 <= uVar12);
      }
    }
  }
  return;
}

/* _gleVPRenderTriangleFan_body @ 0x105394 (888 bytes) */
void _gleVPRenderTriangleFan_body(glContext)
  int glContext;
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
  double f1AfterCall;
  double dVar17;
  double f1AfterCall1;
  double f1AfterCall2;
  double incomingFpr2;
  double incomingFpr3;
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  double incomingStack_ffffff78;
  double incomingStack_ffffff80;
  int local_50;
  int local_4c [6];
  
  iVar11 = -1;
  iVar6 = ((int (*)())_gleTexEnableBits)(glContext);
  bVar1 = *(byte *)(glContext + 0x4666);
  cVar2 = *(char *)(glContext + 0x34de);
  if ((((int)*(short *)(glContext + 0x487c) != 0) &&
      (uVar15 = (uint)(*(int *)(glContext + 0x4858) - *(int *)(glContext + 0x4854)) /
                (uint)(int)*(short *)(glContext + 0x487c), 2 < (int)uVar15)) &&
     (uVar7 = _gleVPEmulate(glContext,uVar15), (uVar7 & 0xff00) == 0)) {
    iVar13 = *(int *)(glContext + 0x4864);
    if (((uVar7 & 0xff) == 0) && (*(char *)(glContext + 0x4e18) == '\0')) {
      dVar17 = f1AfterCall;
      if (iVar6 != 0) {
        dVar17 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x506c))(glContext, iVar13, uVar15, 0);
      }
      if (cVar2 == '\0') {
        (**(code **)(glContext + 0x46c8))
                  (*(undefined4 *)(glContext + 0x4688),iVar13,iVar13 + 0x100,uVar15 - 1,
                   *(ushort *)(glContext + 0x34d0) - 0x1b00);
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
              iVar8 = ((undefined4 (*)())_gleCullTriangle)(glContext,iVar13,uVar7,uVar16,0,&local_50,dVar17,incomingFpr2,incomingFpr3,
                                       incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,incomingStack_ffffff78,
                                       incomingStack_ffffff80);
              dVar17 = f1AfterCall1;
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
              ((double (*)())_gleVPFlipColors)(glContext,uVar12,iVar6,iVar11);
            }
            if (iVar11 == 0) {
              uVar3 = *(ushort *)(glContext + 0x34d0);
            }
            else {
              uVar3 = *(ushort *)(glContext + 0x34d2);
            }
            dVar17 = (double)(**(double ( **)(int,int,int,int,int))(glContext + 0x46c8))
                                       (*(undefined4 *)(glContext + 0x4688), iVar13, uVar12, iVar6, uVar3 - 0x1b00);
          }
        } while (uVar7 <= uVar15);
      }
    }
    else {
      dVar17 = f1AfterCall;
      if (iVar6 != 0) {
        dVar17 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x5074))(glContext, iVar13, uVar15, 0);
      }
      piVar14 = *(int **)(glContext + 0x4870);
      uVar15 = (iVar13 + uVar15 * 0x100) - 0x200;
      piVar9 = *(int **)(glContext + 0x4874);
      if (iVar13 + 0x100U <= uVar15) {
        uVar16 = iVar13 + 0x100U;
        do {
          uVar12 = uVar16 + 0x100;
          *piVar14 = iVar13;
          piVar14[1] = uVar16;
          piVar14[2] = uVar12;
          *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
          piVar10 = piVar9;
          piVar5 = piVar14;
          iVar11 = 3;
          if ((*(char *)(glContext + 0x4e18) == '\0') ||
             (dVar17 = (double)((double (*)())_gleClipPolyPlane)(glContext,piVar14,3,piVar9,local_4c,dVar17,incomingFpr2,
                                                 incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,
                                                 incomingStack_ffffff78,incomingStack_ffffff80),
             piVar10 = piVar14, piVar5 = piVar9, iVar11 = local_4c[0], local_4c[0] != 0)) {
            piVar14 = piVar5;
            piVar9 = piVar10;
            if ((uVar7 & 0xff) != 0) {
              dVar17 = (double)_gleClipPoly(glContext,piVar14,iVar11,uVar7 & 0xff,piVar10,local_4c,1);
              if (local_4c[0] == 0) goto LAB_001056e4;
              if (0 < local_4c[0]) {
                piVar9 = piVar14;
                piVar14 = piVar10;
                iVar11 = local_4c[0];
              }
            }
            if ((cVar2 == '\0') ||
               (iVar6 = _gleCullPolygonPtrStack(glContext,piVar14,iVar11,&local_50),
               dVar17 = f1AfterCall2, iVar6 == 0)) {
              iVar6 = local_50;
              if (((int)-(uint)bVar1 < 0) && (piVar10 = piVar14, iVar8 = iVar11, 0 < iVar11)) {
                do {
                  ((double (*)())_gleVPFlipColors)(glContext,*piVar10,1,iVar6);
                  iVar8 = iVar8 + -1;
                  piVar10 = piVar10 + 1;
                } while (iVar8 != 0);
              }
              if (iVar6 == 0) {
                uVar3 = *(ushort *)(glContext + 0x34d0);
              }
              else {
                uVar3 = *(ushort *)(glContext + 0x34d2);
              }
              dVar17 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x46e0))
                                         (*(undefined4 *)(glContext + 0x4688), piVar14, iVar11, uVar3 - 0x1b00);
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

/* _gleVPRenderQuads_body @ 0x105710 (884 bytes) */
void _gleVPRenderQuads_body(glContext)
  int glContext;
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
  double f1AfterCall;
  double dVar17;
  double extraout_f1_00;
  double f1AfterCall2;
  double incomingFpr2;
  double incomingFpr3;
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  double incomingStack_ffffff78;
  double incomingStack_ffffff80;
  double incomingStack_ffffff88;
  int local_50;
  int local_4c [5];
  
  iVar11 = -1;
  iVar6 = ((int (*)())_gleTexEnableBits)(glContext);
  bVar1 = *(byte *)(glContext + 0x4666);
  cVar2 = *(char *)(glContext + 0x34de);
  if ((((int)*(short *)(glContext + 0x487c) != 0) &&
      (uVar13 = (uint)(*(int *)(glContext + 0x4858) - *(int *)(glContext + 0x4854)) /
                (uint)(int)*(short *)(glContext + 0x487c), 3 < (int)uVar13)) &&
     (uVar7 = _gleVPEmulate(glContext,uVar13), (uVar7 & 0xff00) == 0)) {
    uVar16 = *(uint *)(glContext + 0x4864);
    if (((uVar7 & 0xff) == 0) && (*(char *)(glContext + 0x4e18) == '\0')) {
      dVar17 = f1AfterCall;
      if (iVar6 != 0) {
        dVar17 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x506c))(glContext, uVar16, uVar13, 0);
      }
      if (cVar2 == '\0') {
        (**(code **)(glContext + 0x46d0))
                  (*(undefined4 *)(glContext + 0x4688),uVar16,uVar13,
                   *(ushort *)(glContext + 0x34d0) - 0x1b00);
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
              iVar8 = ((undefined4 (*)())_gleCullQuad)(glContext,uVar16,uVar16 + 0x100,uVar16 + 0x200,uVar16 + 0x300,
                                   &local_50,dVar17,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,
                                   incomingStack_ffffff78,incomingStack_ffffff80,incomingStack_ffffff88);
              dVar17 = dVar17;
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
                ((double (*)())_gleVPFlipColors)(glContext,uVar15,iVar6,iVar11);
              }
              if (iVar11 == 0) {
                uVar3 = *(ushort *)(glContext + 0x34d0);
              }
              else {
                uVar3 = *(ushort *)(glContext + 0x34d2);
              }
              dVar17 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x46d0))
                                         (*(undefined4 *)(glContext + 0x4688), uVar15, iVar6, uVar3 - 0x1b00);
            }
          }
          uVar16 = uVar7;
        } while (uVar7 <= uVar13);
      }
    }
    else {
      dVar17 = f1AfterCall;
      if (iVar6 != 0) {
        dVar17 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x5074))(glContext, uVar16, uVar13, 0);
      }
      puVar12 = *(uint **)(glContext + 0x4870);
      uVar13 = (uVar16 + uVar13 * 0x100) - 0x400;
      puVar9 = *(uint **)(glContext + 0x4874);
      if (uVar16 <= uVar13) {
        do {
          puVar12[1] = uVar16 + 0x100;
          puVar12[2] = uVar16 + 0x200;
          puVar12[3] = uVar16 + 0x300;
          *puVar12 = uVar16;
          *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
          puVar10 = puVar9;
          puVar5 = puVar12;
          iVar11 = 4;
          if ((*(char *)(glContext + 0x4e18) == '\0') ||
             (dVar17 = (double)((double (*)())_gleClipPolyPlane)(glContext,puVar12,4,puVar9,local_4c,dVar17,incomingFpr2,
                                                 incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,
                                                 incomingStack_ffffff78,incomingStack_ffffff80),
             puVar10 = puVar12, puVar5 = puVar9, iVar11 = local_4c[0], local_4c[0] != 0)) {
            puVar12 = puVar5;
            puVar9 = puVar10;
            if ((uVar7 & 0xff) != 0) {
              dVar17 = (double)_gleClipPoly(glContext,puVar12,iVar11,uVar7 & 0xff,puVar10,local_4c,1);
              if (local_4c[0] == 0) goto LAB_00105a5c;
              if (0 < local_4c[0]) {
                puVar9 = puVar12;
                puVar12 = puVar10;
                iVar11 = local_4c[0];
              }
            }
            if ((cVar2 == '\0') ||
               (iVar6 = _gleCullPolygonPtrStack(glContext,puVar12,iVar11,&local_50),
               dVar17 = f1AfterCall2, iVar6 == 0)) {
              iVar6 = local_50;
              if (((int)-(uint)bVar1 < 0) && (puVar10 = puVar12, iVar8 = iVar11, 0 < iVar11)) {
                do {
                  ((double (*)())_gleVPFlipColors)(glContext,*puVar10,1,iVar6);
                  iVar8 = iVar8 + -1;
                  puVar10 = puVar10 + 1;
                } while (iVar8 != 0);
              }
              if (iVar6 == 0) {
                uVar3 = *(ushort *)(glContext + 0x34d0);
              }
              else {
                uVar3 = *(ushort *)(glContext + 0x34d2);
              }
              dVar17 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x46e0))
                                         (*(undefined4 *)(glContext + 0x4688), puVar12, iVar11, uVar3 - 0x1b00);
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

/* _gleVPRenderQuadStrip_body @ 0x105a88 (884 bytes) */
void _gleVPRenderQuadStrip_body(glContext)
  int glContext;
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
  double f1AfterCall;
  double dVar16;
  double f1AfterCall1;
  double f1AfterCall2;
  double incomingFpr2;
  double incomingFpr3;
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  double incomingStack_ffffff78;
  double incomingStack_ffffff80;
  double incomingStack_ffffff88;
  int local_50;
  int local_4c [6];
  
  iVar11 = -1;
  iVar6 = ((int (*)())_gleTexEnableBits)(glContext);
  bVar1 = *(byte *)(glContext + 0x4666);
  cVar2 = *(char *)(glContext + 0x34de);
  if ((((int)*(short *)(glContext + 0x487c) != 0) &&
      (uVar14 = (uint)(*(int *)(glContext + 0x4858) - *(int *)(glContext + 0x4854)) /
                (uint)(int)*(short *)(glContext + 0x487c), 3 < (int)uVar14)) &&
     (uVar7 = _gleVPEmulate(glContext,uVar14), (uVar7 & 0xff00) == 0)) {
    uVar15 = *(uint *)(glContext + 0x4864);
    if (((uVar7 & 0xff) == 0) && (*(char *)(glContext + 0x4e18) == '\0')) {
      dVar16 = f1AfterCall;
      if (iVar6 != 0) {
        dVar16 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x506c))(glContext, uVar15, uVar14, 0);
      }
      if (cVar2 == '\0') {
        (**(code **)(glContext + 0x46d4))
                  (*(undefined4 *)(glContext + 0x4688),uVar15,uVar14,
                   *(ushort *)(glContext + 0x34d0) - 0x1b00);
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
              iVar8 = ((undefined4 (*)())_gleCullQuad)(glContext,uVar15,uVar15 + 0x100,uVar15 + 0x300,uVar7,&local_50,
                                   dVar16,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,
                                   incomingStack_ffffff78,incomingStack_ffffff80,incomingStack_ffffff88);
              dVar16 = f1AfterCall1;
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
              ((double (*)())_gleVPFlipColors)(glContext,uVar12,iVar6,iVar11);
            }
            if (iVar11 == 0) {
              uVar3 = *(ushort *)(glContext + 0x34d0);
            }
            else {
              uVar3 = *(ushort *)(glContext + 0x34d2);
            }
            dVar16 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x46d4))
                                       (*(undefined4 *)(glContext + 0x4688), uVar12, iVar6, uVar3 - 0x1b00);
          }
        } while (uVar15 <= uVar14);
      }
    }
    else {
      dVar16 = f1AfterCall;
      if (iVar6 != 0) {
        dVar16 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x5074))(glContext, uVar15, uVar14, 0);
      }
      puVar13 = *(uint **)(glContext + 0x4870);
      puVar9 = *(uint **)(glContext + 0x4874);
      uVar14 = (uVar15 + uVar14 * 0x100) - 0x400;
      if (uVar15 <= uVar14) {
        do {
          uVar12 = uVar15 + 0x200;
          puVar13[1] = uVar15 + 0x100;
          puVar13[2] = uVar15 + 0x300;
          *puVar13 = uVar15;
          puVar13[3] = uVar12;
          *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
          puVar10 = puVar9;
          puVar5 = puVar13;
          iVar11 = 4;
          if ((*(char *)(glContext + 0x4e18) == '\0') ||
             (dVar16 = (double)((double (*)())_gleClipPolyPlane)(glContext,puVar13,4,puVar9,local_4c,dVar16,incomingFpr2,
                                                 incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,
                                                 incomingStack_ffffff78,incomingStack_ffffff80),
             puVar10 = puVar13, puVar5 = puVar9, iVar11 = local_4c[0], local_4c[0] != 0)) {
            puVar13 = puVar5;
            puVar9 = puVar10;
            if ((uVar7 & 0xff) != 0) {
              dVar16 = (double)_gleClipPoly(glContext,puVar13,iVar11,uVar7 & 0xff,puVar10,local_4c,1);
              if (local_4c[0] == 0) goto LAB_00105dd4;
              if (0 < local_4c[0]) {
                puVar9 = puVar13;
                puVar13 = puVar10;
                iVar11 = local_4c[0];
              }
            }
            if ((cVar2 == '\0') ||
               (iVar6 = _gleCullPolygonPtrStack(glContext,puVar13,iVar11,&local_50),
               dVar16 = f1AfterCall2, iVar6 == 0)) {
              iVar6 = local_50;
              if (((int)-(uint)bVar1 < 0) && (puVar10 = puVar13, iVar8 = iVar11, 0 < iVar11)) {
                do {
                  ((double (*)())_gleVPFlipColors)(glContext,*puVar10,1,iVar6);
                  iVar8 = iVar8 + -1;
                  puVar10 = puVar10 + 1;
                } while (iVar8 != 0);
              }
              if (iVar6 == 0) {
                uVar3 = *(ushort *)(glContext + 0x34d0);
              }
              else {
                uVar3 = *(ushort *)(glContext + 0x34d2);
              }
              dVar16 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x46e0))
                                         (*(undefined4 *)(glContext + 0x4688), puVar13, iVar11, uVar3 - 0x1b00);
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
void _gleVPRenderPolygon(glContext)
  int glContext;
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
  double f1AfterCall;
  double fparam_1;
  double incomingFpr2;
  double incomingFpr3;
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  double incomingStack_ffffff88;
  double incomingStack_ffffff90;
  uint local_40;
  int local_3c [4];
  
  local_3c[0] = 0;
  iVar5 = ((int (*)())_gleTexEnableBits)(glContext);
  bVar1 = *(byte *)(glContext + 0x4666);
  cVar2 = *(char *)(glContext + 0x34de);
  if ((((int)*(short *)(glContext + 0x487c) != 0) &&
      (uVar11 = (uint)(*(int *)(glContext + 0x4858) - *(int *)(glContext + 0x4854)) /
                (uint)(int)*(short *)(glContext + 0x487c), 2 < (int)uVar11)) &&
     (uVar6 = _gleVPEmulate(glContext,uVar11), (uVar6 & 0xff00) == 0)) {
    piVar13 = *(int **)(glContext + 0x4864);
    if (((uVar6 & 0xff) == 0) && (*(char *)(glContext + 0x4e18) == '\0')) {
      if ((cVar2 != '\0') &&
         (iVar7 = _gleCullPolygonStack(glContext,piVar13,uVar11,0,local_3c), iVar7 != 0)) {
        return;
      }
      if (iVar5 != 0) {
        (**(code **)(glContext + 0x506c))(glContext,piVar13,uVar11,0);
      }
      if (local_3c[0] == 0) {
        uVar3 = *(ushort *)(glContext + 0x34d0);
      }
      else {
        uVar3 = *(ushort *)(glContext + 0x34d2);
      }
      iVar5 = uVar3 - 0x1b00;
      if ((*(char *)(glContext + 0x4a18) != '\0') && (iVar5 == 1)) {
        iVar5 = 3;
      }
      if ((int)-(uint)bVar1 < 0) {
        ((double (*)())_gleVPFlipColors)(glContext,piVar13,uVar11,local_3c[0]);
      }
      pcVar9 = *(code **)(glContext + 0x46c0);
    }
    else {
      fparam_1 = f1AfterCall;
      if (iVar5 != 0) {
        fparam_1 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x5074))(glContext, piVar13, uVar11, 0);
      }
      piVar10 = *(int **)(glContext + 0x4870);
      piVar12 = *(int **)(glContext + 0x4874);
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
      *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
      piVar13 = piVar10;
      if (*(char *)(glContext + 0x4e18) != '\0') {
        ((double (*)())_gleClipPolyPlane)(glContext,piVar10,uVar11,piVar12,&local_40,fparam_1,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,
                          incomingFpr6,incomingFpr7,incomingFpr8,incomingStack_ffffff88,incomingStack_ffffff90);
        if (local_40 == 0) {
          return;
        }
        uVar8 = 1;
        piVar13 = piVar12;
        uVar11 = local_40;
        piVar12 = piVar10;
      }
      if ((uVar6 & 0xff) != 0) {
        _gleClipPoly(glContext,piVar13,uVar11,uVar6 & 0xff,piVar12,&local_40,uVar8);
        if (local_40 == 0) {
          return;
        }
        if (0 < (int)local_40) {
          piVar13 = piVar12;
          uVar11 = local_40;
        }
      }
      if ((cVar2 != '\0') &&
         (iVar5 = _gleCullPolygonPtrStack(glContext,piVar13,uVar11,local_3c), iVar5 != 0)) {
        return;
      }
      if (local_3c[0] == 0) {
        uVar3 = *(ushort *)(glContext + 0x34d0);
      }
      else {
        uVar3 = *(ushort *)(glContext + 0x34d2);
      }
      iVar5 = uVar3 - 0x1b00;
      if ((*(char *)(glContext + 0x4a18) != '\0') && (iVar5 == 1)) {
        iVar5 = 3;
      }
      if (((int)-(uint)bVar1 < 0) && (piVar4 = piVar13, uVar6 = uVar11, 0 < (int)uVar11)) {
        do {
          ((double (*)())_gleVPFlipColors)(glContext,*piVar4,1,local_3c[0]);
          uVar6 = uVar6 - 1;
          piVar4 = piVar4 + 1;
        } while (uVar6 != 0);
      }
      pcVar9 = *(code **)(glContext + 0x46e0);
    }
    (*pcVar9)(*(undefined4 *)(glContext + 0x4688),piVar13,uVar11,iVar5);
  }
  return;
}

/* _gleVPFlushAtomic @ 0x1060d4 (60 bytes) */
void _gleVPFlushAtomic(glContext)
  int glContext;
{
  (**(code **)(glContext + 0x4a08))(glContext);
  *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
  return;
}

/* _gleVPFlushAtomicTCL @ 0x106110 (60 bytes) */
void _gleVPFlushAtomicTCL(glContext)
  int glContext;
{
  (**(code **)(glContext + 0x4a08))(glContext);
  *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
  return;
}

/* _gleVPFlushAtomicTCLRDirty @ 0x10614c (132 bytes) */
void _gleVPFlushAtomicTCLRDirty(int glContext,double floatArg1,double floatArg2,double floatArg3,double floatArg4,double floatArg5,double floatArg6,double floatArg7,double floatArg8)
{
  if ((((*(char *)(glContext + 0x7580) != '\0') && ((*(uint *)(glContext + 0x486c) & 1) != 0)) &&
      (*(char *)(*(int *)(glContext + 0x468c) + 0x7a) == '\0')) &&
     ((*(char *)(glContext + 0x4664) == '\0' && (*(int *)(glContext + 0x5434) == 0)))) {
    ((undefined4 (*)())_gleForceToSoftwareTCL)(glContext,floatArg1,floatArg2,floatArg3,floatArg4,floatArg5,floatArg6,floatArg7,floatArg8);
  }
  (**(code **)(glContext + 0x4a08))(glContext);
  *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
  return;
}

/* _gleVPFlushLineLoop @ 0x1061d0 (228 bytes) */
void _gleVPFlushLineLoop(glContext)
  int glContext;
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined8 local_120 [33];
  
  iVar5 = *(int *)(glContext + 0x4854);
  iVar4 = (int)*(short *)(glContext + 0x487c) >> 3;
  if (*(char *)(glContext + 0x4a18) == '\0') {
    iVar3 = 0;
    for (iVar6 = iVar4; iVar6 != 0; iVar6 = iVar6 + -1) {
      iVar1 = iVar3 * 8;
      iVar3 = iVar3 + 1;
      *(undefined8 *)(iVar5 + -0x100 + iVar1) = *(undefined8 *)(iVar5 + iVar1);
    }
  }
  iVar2 = *(int *)(glContext + 0x4858);
  iVar6 = iVar4 * 8;
  iVar1 = 0;
  for (iVar3 = iVar4; iVar3 != 0; iVar3 = iVar3 + -1) {
    local_120[iVar1] = *(undefined8 *)(iVar2 + iVar4 * -8 + iVar1 * 8);
    iVar1 = iVar1 + 1;
  }
  (**(code **)(glContext + 0x4a08))(glContext);
  *(undefined1 *)(glContext + 0x4a18) = 1;
  iVar3 = 0;
  for (; iVar4 != 0; iVar4 = iVar4 + -1) {
    *(undefined8 *)(iVar5 + iVar3 * 8) = local_120[iVar3];
    iVar3 = iVar3 + 1;
  }
  *(int *)(glContext + 0x4858) = iVar5 + iVar6;
  return;
}

/* _gleVPFlushLineLoopTCL @ 0x1062b4 (180 bytes) */
void _gleVPFlushLineLoopTCL(glContext)
  int glContext;
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  (**(code **)(glContext + 0x4a08))(glContext);
  iVar6 = *(int *)(glContext + 0x4854);
  iVar3 = (int)*(short *)(glContext + 0x487c) >> 3;
  if (*(char *)(glContext + 0x4a18) == '\0') {
    iVar4 = 0;
    for (iVar7 = iVar3; iVar7 != 0; iVar7 = iVar7 + -1) {
      iVar5 = iVar4 * 8;
      iVar4 = iVar4 + 1;
      *(undefined8 *)(iVar6 + -0x100 + iVar5) = *(undefined8 *)(iVar6 + iVar5);
    }
    *(undefined1 *)(glContext + 0x4a18) = 1;
  }
  iVar5 = 0;
  iVar2 = *(int *)(glContext + 0x4858);
  iVar7 = iVar3 * 8;
  iVar4 = iVar3 * -8;
  for (; iVar3 != 0; iVar3 = iVar3 + -1) {
    iVar1 = iVar5 * 8;
    iVar5 = iVar5 + 1;
    *(undefined8 *)(iVar6 + iVar1) = *(undefined8 *)(iVar2 + iVar4 + iVar1);
  }
  *(int *)(glContext + 0x4858) = iVar6 + iVar7;
  return;
}

/* _gleVPFlushLineLoopTCLRDirty @ 0x106368 (252 bytes) */
void _gleVPFlushLineLoopTCLRDirty(int glContext,double floatArg1,double floatArg2,double floatArg3,double floatArg4,double floatArg5,double floatArg6,double floatArg7,double floatArg8)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  if ((((*(char *)(glContext + 0x7580) != '\0') && ((*(uint *)(glContext + 0x486c) & 1) != 0)) &&
      (*(char *)(*(int *)(glContext + 0x468c) + 0x7a) == '\0')) &&
     ((*(char *)(glContext + 0x4664) == '\0' && (*(int *)(glContext + 0x5434) == 0)))) {
    ((undefined4 (*)())_gleForceToSoftwareTCL)(glContext,floatArg1,floatArg2,floatArg3,floatArg4,floatArg5,floatArg6,floatArg7,floatArg8);
  }
  (**(code **)(glContext + 0x4a08))(glContext);
  iVar6 = *(int *)(glContext + 0x4854);
  iVar3 = (int)*(short *)(glContext + 0x487c) >> 3;
  if (*(char *)(glContext + 0x4a18) == '\0') {
    iVar4 = 0;
    for (iVar7 = iVar3; iVar7 != 0; iVar7 = iVar7 + -1) {
      iVar5 = iVar4 * 8;
      iVar4 = iVar4 + 1;
      *(undefined8 *)(iVar6 + -0x100 + iVar5) = *(undefined8 *)(iVar6 + iVar5);
    }
    *(undefined1 *)(glContext + 0x4a18) = 1;
  }
  iVar5 = 0;
  iVar2 = *(int *)(glContext + 0x4858);
  iVar7 = iVar3 * 8;
  iVar4 = iVar3 * -8;
  for (; iVar3 != 0; iVar3 = iVar3 + -1) {
    iVar1 = iVar5 * 8;
    iVar5 = iVar5 + 1;
    *(undefined8 *)(iVar6 + iVar1) = *(undefined8 *)(iVar2 + iVar4 + iVar1);
  }
  *(int *)(glContext + 0x4858) = iVar6 + iVar7;
  return;
}

/* _gleVPFlushLineStrip @ 0x106464 (176 bytes) */
void _gleVPFlushLineStrip(glContext)
  int glContext;
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined8 local_110 [32];
  
  iVar4 = (int)*(short *)(glContext + 0x487c) >> 3;
  iVar3 = *(int *)(glContext + 0x4858);
  iVar1 = iVar4 * 8;
  iVar2 = 0;
  for (iVar5 = iVar4; iVar5 != 0; iVar5 = iVar5 + -1) {
    local_110[iVar2] = *(undefined8 *)(iVar3 + iVar4 * -8 + iVar2 * 8);
    iVar2 = iVar2 + 1;
  }
  (**(code **)(glContext + 0x4a08))(glContext);
  *(undefined1 *)(glContext + 0x4a18) = 1;
  iVar5 = *(int *)(glContext + 0x4854);
  iVar2 = 0;
  for (; iVar4 != 0; iVar4 = iVar4 + -1) {
    *(undefined8 *)(iVar5 + iVar2 * 8) = local_110[iVar2];
    iVar2 = iVar2 + 1;
  }
  *(int *)(glContext + 0x4858) = iVar5 + iVar1;
  return;
}

/* _gleVPFlushLineStripTCL @ 0x106514 (128 bytes) */
void _gleVPFlushLineStripTCL(glContext)
  int glContext;
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  (**(code **)(glContext + 0x4a08))(glContext);
  iVar5 = 0;
  iVar4 = *(int *)(glContext + 0x4858);
  iVar6 = (int)*(short *)(glContext + 0x487c) >> 3;
  iVar1 = iVar6 * 8;
  *(undefined1 *)(glContext + 0x4a18) = 1;
  iVar3 = iVar6 * -8;
  iVar7 = *(int *)(glContext + 0x4854);
  for (; iVar6 != 0; iVar6 = iVar6 + -1) {
    iVar2 = iVar5 * 8;
    iVar5 = iVar5 + 1;
    *(undefined8 *)(iVar7 + iVar2) = *(undefined8 *)(iVar4 + iVar3 + iVar2);
  }
  *(int *)(glContext + 0x4858) = iVar7 + iVar1;
  return;
}

/* _gleVPFlushLineStripTCLRDirty @ 0x106594 (200 bytes) */
void _gleVPFlushLineStripTCLRDirty(int glContext,double floatArg1,double floatArg2,double floatArg3,double floatArg4,double floatArg5,double floatArg6,double floatArg7,double floatArg8)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  if ((((*(char *)(glContext + 0x7580) != '\0') && ((*(uint *)(glContext + 0x486c) & 1) != 0)) &&
      (*(char *)(*(int *)(glContext + 0x468c) + 0x7a) == '\0')) &&
     ((*(char *)(glContext + 0x4664) == '\0' && (*(int *)(glContext + 0x5434) == 0)))) {
    ((undefined4 (*)())_gleForceToSoftwareTCL)(glContext,floatArg1,floatArg2,floatArg3,floatArg4,floatArg5,floatArg6,floatArg7,floatArg8);
  }
  (**(code **)(glContext + 0x4a08))(glContext);
  iVar5 = 0;
  iVar4 = *(int *)(glContext + 0x4858);
  iVar6 = (int)*(short *)(glContext + 0x487c) >> 3;
  iVar1 = iVar6 * 8;
  *(undefined1 *)(glContext + 0x4a18) = 1;
  iVar3 = iVar6 * -8;
  iVar7 = *(int *)(glContext + 0x4854);
  for (; iVar6 != 0; iVar6 = iVar6 + -1) {
    iVar2 = iVar5 * 8;
    iVar5 = iVar5 + 1;
    *(undefined8 *)(iVar7 + iVar2) = *(undefined8 *)(iVar4 + iVar3 + iVar2);
  }
  *(int *)(glContext + 0x4858) = iVar7 + iVar1;
  return;
}

/* _gleVPFlushTriQuadStrip @ 0x10665c (168 bytes) */
void _gleVPFlushTriQuadStrip(glContext)
  int glContext;
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined8 local_210 [64];
  
  iVar4 = (int)*(short *)(glContext + 0x487c) >> 2;
  iVar3 = *(int *)(glContext + 0x4858);
  iVar1 = iVar4 * 8;
  iVar2 = 0;
  for (iVar5 = iVar4; iVar5 != 0; iVar5 = iVar5 + -1) {
    local_210[iVar2] = *(undefined8 *)(iVar3 + iVar4 * -8 + iVar2 * 8);
    iVar2 = iVar2 + 1;
  }
  (**(code **)(glContext + 0x4a08))(glContext);
  iVar5 = *(int *)(glContext + 0x4854);
  iVar2 = 0;
  for (; iVar4 != 0; iVar4 = iVar4 + -1) {
    *(undefined8 *)(iVar5 + iVar2 * 8) = local_210[iVar2];
    iVar2 = iVar2 + 1;
  }
  *(int *)(glContext + 0x4858) = iVar5 + iVar1;
  return;
}

/* _gleVPFlushTriQuadStripTCL @ 0x106704 (120 bytes) */
void _gleVPFlushTriQuadStripTCL(glContext)
  int glContext;
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  (**(code **)(glContext + 0x4a08))(glContext);
  iVar5 = 0;
  iVar7 = *(int *)(glContext + 0x4854);
  iVar6 = (int)*(short *)(glContext + 0x487c) >> 2;
  iVar4 = *(int *)(glContext + 0x4858);
  iVar1 = iVar6 * 8;
  iVar3 = iVar6 * -8;
  for (; iVar6 != 0; iVar6 = iVar6 + -1) {
    iVar2 = iVar5 * 8;
    iVar5 = iVar5 + 1;
    *(undefined8 *)(iVar7 + iVar2) = *(undefined8 *)(iVar4 + iVar3 + iVar2);
  }
  *(int *)(glContext + 0x4858) = iVar7 + iVar1;
  return;
}

/* _gleVPFlushTriQuadStripTCLRDirty @ 0x10677c (192 bytes) */
void _gleVPFlushTriQuadStripTCLRDirty(int glContext,double floatArg1,double floatArg2,double floatArg3,double floatArg4,double floatArg5,double floatArg6,double floatArg7,double floatArg8)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  if ((((*(char *)(glContext + 0x7580) != '\0') && ((*(uint *)(glContext + 0x486c) & 1) != 0)) &&
      (*(char *)(*(int *)(glContext + 0x468c) + 0x7a) == '\0')) &&
     ((*(char *)(glContext + 0x4664) == '\0' && (*(int *)(glContext + 0x5434) == 0)))) {
    ((undefined4 (*)())_gleForceToSoftwareTCL)(glContext,floatArg1,floatArg2,floatArg3,floatArg4,floatArg5,floatArg6,floatArg7,floatArg8);
  }
  (**(code **)(glContext + 0x4a08))(glContext);
  iVar5 = 0;
  iVar7 = *(int *)(glContext + 0x4854);
  iVar6 = (int)*(short *)(glContext + 0x487c) >> 2;
  iVar4 = *(int *)(glContext + 0x4858);
  iVar1 = iVar6 * 8;
  iVar3 = iVar6 * -8;
  for (; iVar6 != 0; iVar6 = iVar6 + -1) {
    iVar2 = iVar5 * 8;
    iVar5 = iVar5 + 1;
    *(undefined8 *)(iVar7 + iVar2) = *(undefined8 *)(iVar4 + iVar3 + iVar2);
  }
  *(int *)(glContext + 0x4858) = iVar7 + iVar1;
  return;
}

/* _gleVPFlushTriangleFan @ 0x10683c (252 bytes) */
void _gleVPFlushTriangleFan(glContext)
  int glContext;
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
  
  iVar5 = *(int *)(glContext + 0x4854);
  iVar4 = (int)*(short *)(glContext + 0x487c) >> 3;
  puVar3 = (undefined8 *)(*(int *)(glContext + 0x4858) + iVar4 * -8);
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
  (**(code **)(glContext + 0x4a08))(glContext);
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
  *(undefined8 **)(glContext + 0x4858) = puVar3 + iVar4;
  return;
}

/* _gleVPFlushTriangleFanTCL @ 0x106938 (124 bytes) */
void _gleVPFlushTriangleFanTCL(glContext)
  int glContext;
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  (**(code **)(glContext + 0x4a08))(glContext);
  iVar6 = 0;
  iVar7 = (int)*(short *)(glContext + 0x487c) >> 3;
  iVar4 = *(int *)(glContext + 0x4858);
  iVar1 = iVar7 * 8;
  iVar3 = iVar7 * -8;
  iVar5 = *(int *)(glContext + 0x4854) + iVar1;
  for (; iVar7 != 0; iVar7 = iVar7 + -1) {
    iVar2 = iVar6 * 8;
    iVar6 = iVar6 + 1;
    *(undefined8 *)(iVar5 + iVar2) = *(undefined8 *)(iVar4 + iVar3 + iVar2);
  }
  *(int *)(glContext + 0x4858) = iVar5 + iVar1;
  return;
}

/* _gleVPFlushTriangleFanTCLRDirty @ 0x1069b4 (196 bytes) */
void _gleVPFlushTriangleFanTCLRDirty(int glContext,double floatArg1,double floatArg2,double floatArg3,double floatArg4,double floatArg5,double floatArg6,double floatArg7,double floatArg8)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  if ((((*(char *)(glContext + 0x7580) != '\0') && ((*(uint *)(glContext + 0x486c) & 1) != 0)) &&
      (*(char *)(*(int *)(glContext + 0x468c) + 0x7a) == '\0')) &&
     ((*(char *)(glContext + 0x4664) == '\0' && (*(int *)(glContext + 0x5434) == 0)))) {
    ((undefined4 (*)())_gleForceToSoftwareTCL)(glContext,floatArg1,floatArg2,floatArg3,floatArg4,floatArg5,floatArg6,floatArg7,floatArg8);
  }
  (**(code **)(glContext + 0x4a08))(glContext);
  iVar6 = 0;
  iVar7 = (int)*(short *)(glContext + 0x487c) >> 3;
  iVar4 = *(int *)(glContext + 0x4858);
  iVar1 = iVar7 * 8;
  iVar3 = iVar7 * -8;
  iVar5 = *(int *)(glContext + 0x4854) + iVar1;
  for (; iVar7 != 0; iVar7 = iVar7 + -1) {
    iVar2 = iVar6 * 8;
    iVar6 = iVar6 + 1;
    *(undefined8 *)(iVar5 + iVar2) = *(undefined8 *)(iVar4 + iVar3 + iVar2);
  }
  *(int *)(glContext + 0x4858) = iVar5 + iVar1;
  return;
}

/* _gleVPFlushPolygon @ 0x106a78 (324 bytes) */
void _gleVPFlushPolygon(glContext)
  int glContext;
{
  uint uVar1;
  undefined8 *puVar2;
  undefined4 incomingR4;
  undefined4 incomingR5;
  undefined4 incomingR6;
  undefined4 incomingR7;
  undefined4 incomingR8;
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
  
  iVar9 = *(int *)(glContext + 0x4854);
  iVar6 = (int)*(short *)(glContext + 0x487c) >> 3;
  puVar5 = (undefined8 *)(*(int *)(glContext + 0x4858) + iVar6 * -8);
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
  puVar7 = *(uint **)(glContext + 0x30b0);
  uVar3 = (uint)((int)puVar5 - iVar9) / (uint)(iVar6 * 8);
  uVar1 = uVar3 >> 3 & 0x1ffffffc;
  uVar3 = uVar3 & 0x1f;
  uVar8 = *(uint *)(uVar1 + (int)puVar7);
  *(uint *)(uVar1 + (int)puVar7) = uVar8 & ~(1 << uVar3);
  (**(code **)(glContext + 0x4a08))(glContext,incomingR4,incomingR5,incomingR6,incomingR7,incomingR8,uVar3);
  *(undefined1 *)(glContext + 0x4a18) = 1;
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
  *(undefined8 **)(glContext + 0x4858) = puVar5 + iVar6;
  return;
}

/* _gleVPFlushPolygonTCL @ 0x106bbc (196 bytes) */
void _gleVPFlushPolygonTCL(glContext)
  int glContext;
{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined4 incomingR4;
  undefined4 incomingR5;
  undefined4 incomingR6;
  undefined4 incomingR7;
  undefined4 incomingR8;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint *puVar8;
  uint uVar9;
  int iVar10;
  
  iVar6 = (int)*(short *)(glContext + 0x487c) >> 3;
  uVar1 = iVar6 * 8;
  puVar8 = *(uint **)(glContext + 0x30b0);
  iVar7 = *(int *)(glContext + 0x4858) + iVar6 * -8;
  iVar10 = *(int *)(glContext + 0x4854) + uVar1;
  uVar4 = (uint)(iVar7 - *(int *)(glContext + 0x4854)) / uVar1;
  uVar3 = uVar4 >> 3 & 0x1ffffffc;
  uVar4 = uVar4 & 0x1f;
  uVar9 = *(uint *)(uVar3 + (int)puVar8);
  *(uint *)(uVar3 + (int)puVar8) = uVar9 & ~(1 << uVar4);
  (**(code **)(glContext + 0x4a08))(glContext,incomingR4,incomingR5,incomingR6,incomingR7,incomingR8,uVar4);
  *(undefined1 *)(glContext + 0x4a18) = 1;
  iVar5 = 0;
  *puVar8 = *puVar8 & 0xfffffffc | (uVar9 >> uVar4 & 1) << 1;
  for (; iVar6 != 0; iVar6 = iVar6 + -1) {
    iVar2 = iVar5 * 8;
    iVar5 = iVar5 + 1;
    *(undefined8 *)(iVar10 + iVar2) = *(undefined8 *)(iVar7 + iVar2);
  }
  *(uint *)(glContext + 0x4858) = iVar10 + uVar1;
  return;
}

/* _gleVPFlushPolygonTCLRDirty @ 0x106c80 (268 bytes) */
void _gleVPFlushPolygonTCLRDirty(int glContext,double floatArg1,double floatArg2,double floatArg3,double floatArg4,double floatArg5,double floatArg6,double floatArg7,double floatArg8)
{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined4 incomingR4;
  undefined4 r4AfterCall;
  undefined4 incomingR5;
  undefined4 incomingR6;
  undefined4 incomingR7;
  undefined4 incomingR8;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint *puVar8;
  uint uVar9;
  int iVar10;
  
  if ((((*(char *)(glContext + 0x7580) != '\0') && ((*(uint *)(glContext + 0x486c) & 1) != 0)) &&
      (*(char *)(*(int *)(glContext + 0x468c) + 0x7a) == '\0')) &&
     ((*(char *)(glContext + 0x4664) == '\0' && (*(int *)(glContext + 0x5434) == 0)))) {
    ((undefined4 (*)())_gleForceToSoftwareTCL)(glContext,floatArg1,floatArg2,floatArg3,floatArg4,floatArg5,floatArg6,floatArg7,floatArg8);
    incomingR4 = r4AfterCall;
  }
  iVar6 = (int)*(short *)(glContext + 0x487c) >> 3;
  uVar1 = iVar6 * 8;
  puVar8 = *(uint **)(glContext + 0x30b0);
  iVar7 = *(int *)(glContext + 0x4858) + iVar6 * -8;
  iVar10 = *(int *)(glContext + 0x4854) + uVar1;
  uVar4 = (uint)(iVar7 - *(int *)(glContext + 0x4854)) / uVar1;
  uVar3 = uVar4 >> 3 & 0x1ffffffc;
  uVar4 = uVar4 & 0x1f;
  uVar9 = *(uint *)(uVar3 + (int)puVar8);
  *(uint *)(uVar3 + (int)puVar8) = uVar9 & ~(1 << uVar4);
  (**(code **)(glContext + 0x4a08))(glContext,incomingR4,incomingR5,incomingR6,incomingR7,incomingR8,uVar4);
  *(undefined1 *)(glContext + 0x4a18) = 1;
  iVar5 = 0;
  *puVar8 = *puVar8 & 0xfffffffc | (uVar9 >> uVar4 & 1) << 1;
  for (; iVar6 != 0; iVar6 = iVar6 + -1) {
    iVar2 = iVar5 * 8;
    iVar5 = iVar5 + 1;
    *(undefined8 *)(iVar10 + iVar2) = *(undefined8 *)(iVar7 + iVar2);
  }
  *(uint *)(glContext + 0x4858) = iVar10 + uVar1;
  return;
}

/* _gleVPBeginPoints @ 0x106d8c (60 bytes) */
void _gleVPBeginPoints(glContext)
  int glContext;
{
  undefined *vpRenderPoints;
  undefined *vpFlushAtomic;
  
  *(undefined4 *)(glContext + 0x486c) = 0;
  vpFlushAtomic = PTR__gleVPFlushAtomic_00111668;
  vpRenderPoints = PTR__gleVPRenderPoints_00111664;
  *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
  *(undefined **)(glContext + 0x4a0c) = vpFlushAtomic;
  *(undefined **)(glContext + 0x4a08) = vpRenderPoints;
  return;
}

/* _gleVPBeginLines @ 0x106dc8 (60 bytes) */
void _gleVPBeginLines(glContext)
  int glContext;
{
  undefined *vpRenderLines;
  undefined *vpFlushAtomic;
  
  *(undefined4 *)(glContext + 0x486c) = 0;
  vpFlushAtomic = PTR__gleVPFlushAtomic_00111668;
  vpRenderLines = PTR__gleVPRenderLines_00111660;
  *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
  *(undefined **)(glContext + 0x4a0c) = vpFlushAtomic;
  *(undefined **)(glContext + 0x4a08) = vpRenderLines;
  return;
}

/* _gleVPBeginLineLoop @ 0x106e04 (68 bytes) */
void _gleVPBeginLineLoop(glContext)
  int glContext;
{
  undefined *vpRenderLineLoop;
  undefined *vpFlushLineLoop;
  
  *(undefined1 *)(glContext + 0x4a18) = 0;
  vpFlushLineLoop = PTR__gleVPFlushLineLoop_0011165c;
  vpRenderLineLoop = PTR__gleVPRenderLineLoop_00111658;
  *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
  *(undefined4 *)(glContext + 0x486c) = 0;
  *(undefined **)(glContext + 0x4a0c) = vpFlushLineLoop;
  *(undefined **)(glContext + 0x4a08) = vpRenderLineLoop;
  return;
}

/* _gleVPBeginLineStrip @ 0x106e48 (68 bytes) */
void _gleVPBeginLineStrip(glContext)
  int glContext;
{
  undefined *vpRenderLineStrip;
  undefined *vpFlushLineStrip;
  
  *(undefined1 *)(glContext + 0x4a18) = 0;
  vpFlushLineStrip = PTR__gleVPFlushLineStrip_00111654;
  vpRenderLineStrip = PTR__gleVPRenderLineStrip_00111650;
  *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
  *(undefined4 *)(glContext + 0x486c) = 0;
  *(undefined **)(glContext + 0x4a0c) = vpFlushLineStrip;
  *(undefined **)(glContext + 0x4a08) = vpRenderLineStrip;
  return;
}

/* _gleVPBeginTriangles @ 0x106e8c (60 bytes) */
void _gleVPBeginTriangles(glContext)
  int glContext;
{
  undefined *vpRenderTriangles;
  undefined *vpFlushAtomic;
  
  *(undefined4 *)(glContext + 0x486c) = 0;
  vpFlushAtomic = PTR__gleVPFlushAtomic_00111668;
  vpRenderTriangles = PTR__gleVPRenderTriangles_0011164c;
  *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
  *(undefined **)(glContext + 0x4a0c) = vpFlushAtomic;
  *(undefined **)(glContext + 0x4a08) = vpRenderTriangles;
  return;
}

/* _gleVPBeginTriangleStrip @ 0x106ec8 (60 bytes) */
void _gleVPBeginTriangleStrip(glContext)
  int glContext;
{
  undefined *vpRenderTriangleStrip;
  undefined *vpFlushTriQuadStrip;
  
  *(undefined4 *)(glContext + 0x486c) = 0;
  vpFlushTriQuadStrip = PTR__gleVPFlushTriQuadStrip_00111648;
  vpRenderTriangleStrip = PTR__gleVPRenderTriangleStrip_00111644;
  *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
  *(undefined **)(glContext + 0x4a0c) = vpFlushTriQuadStrip;
  *(undefined **)(glContext + 0x4a08) = vpRenderTriangleStrip;
  return;
}

/* _gleVPBeginTriangleFan @ 0x106f04 (60 bytes) */
void _gleVPBeginTriangleFan(glContext)
  int glContext;
{
  undefined *vpRenderTriangleFan;
  undefined *vpFlushTriangleFan;
  
  *(undefined4 *)(glContext + 0x486c) = 0;
  vpFlushTriangleFan = PTR__gleVPFlushTriangleFan_00111640;
  vpRenderTriangleFan = PTR__gleVPRenderTriangleFan_0011163c;
  *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
  *(undefined **)(glContext + 0x4a0c) = vpFlushTriangleFan;
  *(undefined **)(glContext + 0x4a08) = vpRenderTriangleFan;
  return;
}

/* _gleVPBeginQuads @ 0x106f40 (60 bytes) */
void _gleVPBeginQuads(glContext)
  int glContext;
{
  undefined *vpRenderQuads;
  undefined *vpFlushAtomic;
  
  *(undefined4 *)(glContext + 0x486c) = 0;
  vpFlushAtomic = PTR__gleVPFlushAtomic_00111668;
  vpRenderQuads = PTR__gleVPRenderQuads_00111638;
  *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
  *(undefined **)(glContext + 0x4a0c) = vpFlushAtomic;
  *(undefined **)(glContext + 0x4a08) = vpRenderQuads;
  return;
}

/* _gleVPBeginQuadStrip @ 0x106f7c (60 bytes) */
void _gleVPBeginQuadStrip(glContext)
  int glContext;
{
  undefined *vpRenderQuadStrip;
  undefined *vpFlushTriQuadStrip;
  
  *(undefined4 *)(glContext + 0x486c) = 0;
  vpFlushTriQuadStrip = PTR__gleVPFlushTriQuadStrip_00111648;
  vpRenderQuadStrip = PTR__gleVPRenderQuadStrip_00111634;
  *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
  *(undefined **)(glContext + 0x4a0c) = vpFlushTriQuadStrip;
  *(undefined **)(glContext + 0x4a08) = vpRenderQuadStrip;
  return;
}

/* _gleVPBeginPolygon @ 0x106fb8 (68 bytes) */
void _gleVPBeginPolygon(glContext)
  int glContext;
{
  undefined *vpRenderPolygon;
  undefined *vpFlushPolygon;
  
  *(undefined1 *)(glContext + 0x4a18) = 0;
  vpFlushPolygon = PTR__gleVPFlushPolygon_00111630;
  vpRenderPolygon = PTR__gleVPRenderPolygon_0011162c;
  *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
  *(undefined4 *)(glContext + 0x486c) = 0;
  *(undefined **)(glContext + 0x4a0c) = vpFlushPolygon;
  *(undefined **)(glContext + 0x4a08) = vpRenderPolygon;
  return;
}

/* _gleVPBeginPointsTCL @ 0x106ffc (52 bytes) */
void _gleVPBeginPointsTCL(glContext)
  int glContext;
{
  undefined *vpFlushAtomicTCL;
  
  vpFlushAtomicTCL = PTR__gleVPFlushAtomicTCL_00111628;
  *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
  *(undefined **)(glContext + 0x4a0c) = vpFlushAtomicTCL;
  *(undefined **)(glContext + 0x4a08) = PTR__gleRenderPointsTCLFunc_0011223c;
  return;
}

/* _gleVPBeginLinesTCL @ 0x107030 (52 bytes) */
void _gleVPBeginLinesTCL(glContext)
  int glContext;
{
  undefined *vpFlushAtomicTCL;
  
  vpFlushAtomicTCL = PTR__gleVPFlushAtomicTCL_00111628;
  *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
  *(undefined **)(glContext + 0x4a0c) = vpFlushAtomicTCL;
  *(undefined **)(glContext + 0x4a08) = PTR__gleRenderLinesTCLFunc_00112214;
  return;
}

/* _gleVPBeginLineLoopTCL @ 0x107064 (60 bytes) */
void _gleVPBeginLineLoopTCL(glContext)
  int glContext;
{
  undefined *vpFlushLineLoopTCL;
  undefined *renderLineLoopTCLFunc;
  
  *(undefined1 *)(glContext + 0x4a18) = 0;
  renderLineLoopTCLFunc = PTR__gleRenderLineLoopTCLFunc_001121d4;
  vpFlushLineLoopTCL = PTR__gleVPFlushLineLoopTCL_00111624;
  *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
  *(undefined **)(glContext + 0x4a0c) = vpFlushLineLoopTCL;
  *(undefined **)(glContext + 0x4a08) = renderLineLoopTCLFunc;
  return;
}

/* _gleVPBeginLineStripTCL @ 0x1070a0 (60 bytes) */
void _gleVPBeginLineStripTCL(glContext)
  int glContext;
{
  undefined *vpFlushLineStripTCL;
  undefined *renderLineStripTCLFunc;
  
  *(undefined1 *)(glContext + 0x4a18) = 0;
  renderLineStripTCLFunc = PTR__gleRenderLineStripTCLFunc_001121f4;
  vpFlushLineStripTCL = PTR__gleVPFlushLineStripTCL_00111620;
  *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
  *(undefined **)(glContext + 0x4a0c) = vpFlushLineStripTCL;
  *(undefined **)(glContext + 0x4a08) = renderLineStripTCLFunc;
  return;
}

/* _gleVPBeginTrianglesTCL @ 0x1070dc (52 bytes) */
void _gleVPBeginTrianglesTCL(glContext)
  int glContext;
{
  undefined *vpFlushAtomicTCL;
  
  vpFlushAtomicTCL = PTR__gleVPFlushAtomicTCL_00111628;
  *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
  *(undefined **)(glContext + 0x4a0c) = vpFlushAtomicTCL;
  *(undefined **)(glContext + 0x4a08) = PTR__gleRenderTrianglesTCLFunc_001122d4;
  return;
}

/* _gleVPBeginTriangleStripTCL @ 0x107110 (52 bytes) */
void _gleVPBeginTriangleStripTCL(glContext)
  int glContext;
{
  undefined *vpFlushTriQuadStripTCL;
  
  vpFlushTriQuadStripTCL = PTR__gleVPFlushTriQuadStripTCL_0011161c;
  *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
  *(undefined **)(glContext + 0x4a0c) = vpFlushTriQuadStripTCL;
  *(undefined **)(glContext + 0x4a08) = PTR__gleRenderTriangleStripTCLFunc_001122b8;
  return;
}

/* _gleVPBeginTriangleFanTCL @ 0x107144 (52 bytes) */
void _gleVPBeginTriangleFanTCL(glContext)
  int glContext;
{
  undefined *vpFlushTriangleFanTCL;
  
  vpFlushTriangleFanTCL = PTR__gleVPFlushTriangleFanTCL_00111618;
  *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
  *(undefined **)(glContext + 0x4a0c) = vpFlushTriangleFanTCL;
  *(undefined **)(glContext + 0x4a08) = PTR__gleRenderTriangleFanTCLFunc_00112298;
  return;
}

/* _gleVPBeginQuadsTCL @ 0x107178 (52 bytes) */
void _gleVPBeginQuadsTCL(glContext)
  int glContext;
{
  undefined *vpFlushAtomicTCL;
  
  vpFlushAtomicTCL = PTR__gleVPFlushAtomicTCL_00111628;
  *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
  *(undefined **)(glContext + 0x4a0c) = vpFlushAtomicTCL;
  *(undefined **)(glContext + 0x4a08) = PTR__gleRenderQuadsTCLFunc_00112280;
  return;
}

