#include "decls.h"

/* _glCopyTexSubImage1D_Exec @ 0x97d38 (1428 bytes) */
void _glCopyTexSubImage1D_Exec(int param_1,undefined4 param_2,uint param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,int param_7,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  bool bVar1;
  char cVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  int iVar9;
  uint uVar10;
  byte bVar11;
  int iVar12;
  int *piVar13;
  double extraout_f1;
  
  if ((*(int *)(param_1 + 0x744c) != 0) || (*(int *)(param_1 + 0x310) < 0)) {
    iVar9 = *(int *)(param_1 + 0x50ac);
    uVar10 = param_3;
    uVar3 = param_4;
    uVar7 = param_5;
    uVar8 = param_6;
    if (iVar9 != 0 || (*(uint *)(param_1 + 0x505c) & *(uint *)(param_1 + 0x50b0)) != 0) {
      _gleUpdateMatrixFunc(param_1);
      fparam_1 = extraout_f1;
    }
    if (*(char *)(param_1 + 0x4691) != '\0') {
      iVar6 = *(int *)(param_1 + 0x744c);
      piVar13 = (int *)(param_1 + 0x310);
      cVar2 = *(char *)(*(int *)(param_1 + 0x468c) + 0x79);
      if ((iVar6 != 0) && (*(int *)(iVar6 + 0xec) != 0)) {
        ((int (*)())_gleUpdateFramebufferCompleteness)(param_1,iVar6 + 0x10,uVar10,uVar3,uVar7,uVar8,iVar9,fparam_1,fparam_2,fparam_3,
                   fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
        *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x80000000;
      }
      if ((*(char *)(param_1 + 0x4664) == '\0') && (*(int *)(param_1 + 0x5430) == 0)) {
LAB_00097e7c:
        uVar10 = *(uint *)(param_1 + 0x31c);
      }
      else {
        iVar9 = 0;
        piVar4 = (int *)(param_1 + 0x324);
        do {
          iVar6 = *piVar4;
          piVar4 = piVar4 + 1;
          if (iVar6 != 0) {
            *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x800000;
            break;
          }
          iVar9 = iVar9 + 1;
        } while (iVar9 < 9);
        uVar10 = *(uint *)(param_1 + 0x31c);
        if ((uVar10 & 0x15555) != 0) {
          if (*(char *)(param_1 + 0x2e54) != '\0') {
            _gleUpdateLightRGBASums(param_1,param_1 + 0x2c20,0);
          }
          if (*(char *)(param_1 + 0x3094) != '\0') {
            _gleUpdateLightRGBASums(param_1,param_1 + 0x2e60,1);
          }
          goto LAB_00097e7c;
        }
      }
      bVar1 = cVar2 == '\0';
      if (bVar1) {
        uVar10 = uVar10 & 0x17000000;
      }
      else {
        uVar10 = uVar10 & 0x17ffffff;
      }
      if (bVar1) {
        bVar1 = ((*piVar13 == 0 && *(int *)(param_1 + 0x314) == 0) && uVar10 == 0) &&
                *(int *)(param_1 + 800) == 0;
      }
      else {
        bVar1 = (((*piVar13 == 0 && *(int *)(param_1 + 0x314) == 0) &&
                 (*(uint *)(param_1 + 0x318) & 0xfffffffd) == 0) && uVar10 == 0) &&
                *(int *)(param_1 + 800) == 0;
      }
      if (!bVar1) {
        if (*(char *)(param_1 + 0x85a8) == *(char *)(param_1 + 0x85a6)) {
          uVar10 = (**(code **)(param_1 + 0x4788))
                             (*(undefined4 *)(param_1 + 0x4688),param_1 + 0x4698,piVar13);
          if ((((uVar10 & 3) != (uint)*(byte *)(param_1 + 0x7580)) ||
              ((uVar10 & 4) != (uint)*(byte *)(param_1 + 0x7581))) ||
             ((uVar10 & 8) != (uint)(*(char *)(param_1 + 0x759d) == '\0'))) {
            if ((uVar10 & 4) == 0) {
              uVar10 = uVar10 & 0xfffffffe;
              *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x10000000;
            }
            _gleUpdateDispatchCodeChange(param_1,uVar10);
            if (*(char *)(param_1 + 0x759d) == '\0') {
              if (*(int *)(param_1 + 0x7574) != 0) {
                return;
              }
              uVar3 = 0x506;
              goto LAB_00097fbc;
            }
          }
        }
        else {
          _gleSwitchToNonRevertRenderer(param_1);
        }
        iVar9 = 0x13;
        do {
          *piVar13 = 0;
          piVar13 = piVar13 + 1;
          iVar9 = iVar9 + -1;
        } while (iVar9 != 0);
      }
    }
  }
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if (param_7 == 0) {
      return;
    }
    iVar9 = _gleCheckCopyTexSubImage1DArgs(param_1,param_2,param_3,param_4,param_7);
    if (iVar9 == 0) {
      return;
    }
    iVar6 = iVar9 + param_3 * 0x18;
    iVar12 = iVar6 + 0xc4;
    if ((((int)param_3 < (int)(uint)*(byte *)(iVar9 + 0x8d)) ||
        ((int)(uint)*(byte *)(iVar9 + 0x8f) < (int)param_3)) ||
       (((*(ushort *)(iVar9 + 0x94) >> (param_3 & 0x3f) & 1) == 0 ||
        (iVar5 = (**(code **)(param_1 + 0x470c))
                           (*(undefined4 *)(param_1 + 0x4688),
                            *(undefined4 *)(iVar9 + (uint)*(byte *)(param_1 + 0x85a8) * 4),0,param_3
                            ,param_4,0,0,param_5), iVar5 == 0)))) {
      bVar11 = *(byte *)(iVar6 + 0xcf);
      if ((bVar11 & 0x10) == 0) {
        if ((bVar11 & 0x40) == 0) {
          if (*(int *)(iVar6 + 0xd8) == 0) {
            _gleAllocateTextureLevel(param_1,iVar9,iVar12);
            bVar11 = *(byte *)(iVar6 + 0xcf);
          }
          *(byte *)(iVar6 + 0xcf) = bVar11 | 0x10;
        }
        else {
          _gleUploadPluginTextureLevel
                    (param_1,iVar9,iVar12,0,param_3,(uint)*(byte *)(param_1 + 0x85a8));
        }
      }
      _gleModifyPluginTextureLevel(param_1,iVar9,iVar12,0,param_3,param_4,0,0,param_7);
      _gleTextureSubImageCopy(param_1,iVar12,param_4,0,0,param_5,param_6,param_7,1);
      if ((((*(uint *)(iVar9 + 0x6c) & 0x8000) != 0) && ((int)*(short *)(iVar9 + 0x60) == param_3))
         && (iVar9 = _gleGenMipmapsToLevel(param_1,iVar9,0,param_3,0xf,1), iVar9 != 0)) {
        return;
      }
      *(uint *)(param_1 + 0x314) =
           *(uint *)(param_1 + 0x314) | 1 << (*(uint *)(param_1 + 0x53d4) & 0x3f);
      return;
    }
    *(undefined4 *)(iVar9 + 0x20) =
         *(undefined4 *)
          ((uint)*(byte *)(param_1 + 0x85a8) * 4 + *(int *)(param_1 + 0x5148) + 0x8054);
    if (*(int *)(iVar6 + 0xd8) != 0) {
      bVar11 = *(byte *)(iVar6 + 0xcf);
      if (((bVar11 & 1) == 0) && (*(short *)(iVar9 + 0x3e) == -0x7a43)) {
        _gleFreeTextureLevel(param_1,iVar9,iVar12);
        bVar11 = *(byte *)(iVar6 + 0xcf);
      }
      *(byte *)(iVar6 + 0xcf) = bVar11 & 0xef;
      *(ushort *)(iVar9 + 0xa0) =
           *(ushort *)(iVar9 + 0xa0) &
           ((ushort)(-2 << (param_3 & 0x1f)) | (ushort)(0xfffffffe >> 0x20 - (param_3 & 0x1f)));
    }
    *(byte *)(iVar6 + 0xcf) = *(byte *)(iVar6 + 0xcf) | 0x40;
    if ((*(uint *)(iVar9 + 0x6c) & 0x8000) == 0) {
      return;
    }
    if ((int)*(short *)(iVar9 + 0x60) != param_3) {
      return;
    }
    uVar10 = param_3 + 1;
    if ((int)(uint)*(byte *)(iVar9 + 0x83) < (int)uVar10) {
      return;
    }
    iVar6 = uVar10 * 0x18 + iVar9 + 0xc4;
    do {
      if (*(int *)(iVar6 + 0x14) != 0) {
        if (((*(byte *)(iVar6 + 0xb) & 1) == 0) && (*(short *)(iVar9 + 0x3e) == -0x7a43)) {
          _gleFreeTextureLevel(param_1,iVar9,iVar6);
        }
        *(byte *)(iVar6 + 0xb) = *(byte *)(iVar6 + 0xb) & 0xef;
        *(ushort *)(iVar9 + 0xa0) = *(ushort *)(iVar9 + 0xa0) & ~(ushort)(1 << (uVar10 & 0x3f));
      }
      uVar10 = uVar10 + 1;
      *(byte *)(iVar6 + 0xb) = *(byte *)(iVar6 + 0xb) | 0x40;
      iVar6 = iVar6 + 0x18;
    } while ((int)uVar10 <= (int)(uint)*(byte *)(iVar9 + 0x83));
    return;
  }
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  uVar3 = 0x502;
LAB_00097fbc:
  *(undefined4 *)(param_1 + 0x7574) = uVar3;
  return;
}

/* _glCopyTexSubImage1D_CompExec @ 0x982cc (96 bytes) */
int _glCopyTexSubImage1D_CompExec(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  double fparam_1;
  double in_f2;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  
  _glCopyTexSubImage1D_Comp(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  ((void (*)())_glCopyTexSubImage1D_Exec)(param_1,param_2,param_3,param_4,param_5,param_6,param_7,fparam_1,in_f2,in_f3,in_f4,
             in_f5,in_f6,in_f7,in_f8);
  return;
}

/* _glCopyTexSubImage1D_NoopExec @ 0x9832c (680 bytes) */
void _glCopyTexSubImage1D_NoopExec(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,undefined4 param_7,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  bool bVar1;
  char cVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  uint uVar11;
  int *piVar12;
  double extraout_f1;
  double extraout_f1_00;
  double extraout_f1_01;
  
  uVar6 = param_3;
  uVar7 = param_4;
  uVar8 = param_5;
  uVar9 = param_6;
  uVar10 = param_7;
  if (*(int *)(param_1 + 0x50ac) != 0 ||
      (*(uint *)(param_1 + 0x505c) & *(uint *)(param_1 + 0x50b0)) != 0) {
    _gleUpdateMatrixFunc(param_1);
    fparam_1 = extraout_f1;
  }
  if (*(char *)(param_1 + 0x4691) != '\0') {
    iVar5 = *(int *)(param_1 + 0x744c);
    piVar12 = (int *)(param_1 + 0x310);
    cVar2 = *(char *)(*(int *)(param_1 + 0x468c) + 0x79);
    if ((iVar5 != 0) && (*(int *)(iVar5 + 0xec) != 0)) {
      ((int (*)())_gleUpdateFramebufferCompleteness)(param_1,iVar5 + 0x10,uVar6,uVar7,uVar8,uVar9,uVar10,fparam_1,fparam_2,fparam_3,
                 fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
      *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x80000000;
      fparam_1 = fparam_1;
    }
    if ((*(char *)(param_1 + 0x4664) == '\0') && (*(int *)(param_1 + 0x5430) == 0)) {
LAB_00098458:
      uVar11 = *(uint *)(param_1 + 0x31c);
    }
    else {
      iVar5 = 0;
      piVar4 = (int *)(param_1 + 0x324);
      do {
        iVar3 = *piVar4;
        piVar4 = piVar4 + 1;
        if (iVar3 != 0) {
          *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x800000;
          break;
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < 9);
      uVar11 = *(uint *)(param_1 + 0x31c);
      if ((uVar11 & 0x15555) != 0) {
        if (*(char *)(param_1 + 0x2e54) != '\0') {
          fparam_1 = (double)_gleUpdateLightRGBASums(param_1,param_1 + 0x2c20,0);
        }
        if (*(char *)(param_1 + 0x3094) != '\0') {
          fparam_1 = (double)_gleUpdateLightRGBASums(param_1,param_1 + 0x2e60,1);
        }
        goto LAB_00098458;
      }
    }
    bVar1 = cVar2 == '\0';
    if (bVar1) {
      uVar11 = uVar11 & 0x17000000;
    }
    else {
      uVar11 = uVar11 & 0x17ffffff;
    }
    if (bVar1) {
      bVar1 = ((*piVar12 == 0 && *(int *)(param_1 + 0x314) == 0) && uVar11 == 0) &&
              *(int *)(param_1 + 800) == 0;
    }
    else {
      bVar1 = (((*piVar12 == 0 && *(int *)(param_1 + 0x314) == 0) &&
               (*(uint *)(param_1 + 0x318) & 0xfffffffd) == 0) && uVar11 == 0) &&
              *(int *)(param_1 + 800) == 0;
    }
    if (!bVar1) {
      if (*(char *)(param_1 + 0x85a8) == *(char *)(param_1 + 0x85a6)) {
        uVar11 = (**(code **)(param_1 + 0x4788))
                           (*(undefined4 *)(param_1 + 0x4688),param_1 + 0x4698,piVar12);
        if ((((uVar11 & 3) != (uint)*(byte *)(param_1 + 0x7580)) ||
            ((uVar11 & 4) != (uint)*(byte *)(param_1 + 0x7581))) ||
           (fparam_1 = extraout_f1_01, (uVar11 & 8) != (uint)(*(char *)(param_1 + 0x759d) == '\0')))
        {
          if ((uVar11 & 4) == 0) {
            uVar11 = uVar11 & 0xfffffffe;
            *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x10000000;
          }
          fparam_1 = (double)_gleUpdateDispatchCodeChange(param_1,uVar11);
          if (*(char *)(param_1 + 0x759d) == '\0') goto LAB_00098578;
        }
      }
      else {
        fparam_1 = (double)_gleSwitchToNonRevertRenderer(param_1);
      }
      iVar5 = 0x13;
      do {
        *piVar12 = 0;
        piVar12 = piVar12 + 1;
        iVar5 = iVar5 + -1;
      } while (iVar5 != 0);
    }
  }
  if (*(char *)(param_1 + 0x759d) != '\0') {
    ((void (*)())_glCopyTexSubImage1D_Exec)(param_1,param_2,param_3,param_4,param_5,param_6,param_7,fparam_1,fparam_2,fparam_3,
               fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
    return;
  }
LAB_00098578:
  if (*(int *)(param_1 + 0x7574) == 0) {
    *(undefined4 *)(param_1 + 0x7574) = 0x506;
  }
  return;
}

/* _glCopyTexSubImage2D_ListExec @ 0x985d4 (76 bytes) */
undefined4 _glCopyTexSubImage2D_ListExec(undefined4 param_1,undefined4 *param_2,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  ((void (*)())_glCopyTexSubImage2D_Exec)(param_1,*param_2,param_2[1],param_2[2],param_2[3],param_2[4],param_2[5],param_2[6],
             param_2[7],fparam_1,fparam_2,fparam_3,fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
  return 0x20;
}

/* _glCopyTexSubImage2D_Comp @ 0x98620 (132 bytes) */
int _glCopyTexSubImage2D_Comp(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
  undefined4 param_9;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glCopyTexSubImage2D_ListExec_001103c8,0x20);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_2;
    puVar1[7] = param_9;
    puVar1[1] = param_3;
    puVar1[2] = param_4;
    puVar1[3] = param_5;
    puVar1[4] = param_6;
    puVar1[5] = param_7;
    puVar1[6] = param_8;
  }
  return puVar1;
}

/* _glCopyTexSubImage2D_Exec @ 0x986a4 (1508 bytes) */
void _glCopyTexSubImage2D_Exec(int param_1,int param_2,uint param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,undefined4 param_7,int param_8,int param_9,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  bool bVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  int iVar10;
  uint uVar11;
  byte bVar12;
  uint uVar13;
  int *piVar14;
  int iVar15;
  double extraout_f1;
  
  if ((*(int *)(param_1 + 0x744c) != 0) || (*(int *)(param_1 + 0x310) < 0)) {
    iVar10 = *(int *)(param_1 + 0x50ac);
    uVar11 = param_3;
    uVar4 = param_4;
    uVar8 = param_5;
    uVar9 = param_6;
    if (iVar10 != 0 || (*(uint *)(param_1 + 0x505c) & *(uint *)(param_1 + 0x50b0)) != 0) {
      _gleUpdateMatrixFunc(param_1);
      fparam_1 = extraout_f1;
    }
    if (*(char *)(param_1 + 0x4691) != '\0') {
      iVar7 = *(int *)(param_1 + 0x744c);
      piVar14 = (int *)(param_1 + 0x310);
      cVar2 = *(char *)(*(int *)(param_1 + 0x468c) + 0x79);
      if ((iVar7 != 0) && (*(int *)(iVar7 + 0xec) != 0)) {
        ((int (*)())_gleUpdateFramebufferCompleteness)(param_1,iVar7 + 0x10,uVar11,uVar4,uVar8,uVar9,iVar10,fparam_1,fparam_2,fparam_3,
                   fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
        *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x80000000;
      }
      if ((*(char *)(param_1 + 0x4664) == '\0') && (*(int *)(param_1 + 0x5430) == 0)) {
LAB_000987f0:
        uVar11 = *(uint *)(param_1 + 0x31c);
      }
      else {
        iVar10 = 0;
        piVar5 = (int *)(param_1 + 0x324);
        do {
          iVar7 = *piVar5;
          piVar5 = piVar5 + 1;
          if (iVar7 != 0) {
            *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x800000;
            break;
          }
          iVar10 = iVar10 + 1;
        } while (iVar10 < 9);
        uVar11 = *(uint *)(param_1 + 0x31c);
        if ((uVar11 & 0x15555) != 0) {
          if (*(char *)(param_1 + 0x2e54) != '\0') {
            _gleUpdateLightRGBASums(param_1,param_1 + 0x2c20,0);
          }
          if (*(char *)(param_1 + 0x3094) != '\0') {
            _gleUpdateLightRGBASums(param_1,param_1 + 0x2e60,1);
          }
          goto LAB_000987f0;
        }
      }
      bVar1 = cVar2 == '\0';
      if (bVar1) {
        uVar11 = uVar11 & 0x17000000;
      }
      else {
        uVar11 = uVar11 & 0x17ffffff;
      }
      if (bVar1) {
        bVar1 = ((*piVar14 == 0 && *(int *)(param_1 + 0x314) == 0) && uVar11 == 0) &&
                *(int *)(param_1 + 800) == 0;
      }
      else {
        bVar1 = (((*piVar14 == 0 && *(int *)(param_1 + 0x314) == 0) &&
                 (*(uint *)(param_1 + 0x318) & 0xfffffffd) == 0) && uVar11 == 0) &&
                *(int *)(param_1 + 800) == 0;
      }
      if (!bVar1) {
        if (*(char *)(param_1 + 0x85a8) == *(char *)(param_1 + 0x85a6)) {
          uVar11 = (**(code **)(param_1 + 0x4788))
                             (*(undefined4 *)(param_1 + 0x4688),param_1 + 0x4698,piVar14);
          if ((((uVar11 & 3) != (uint)*(byte *)(param_1 + 0x7580)) ||
              ((uVar11 & 4) != (uint)*(byte *)(param_1 + 0x7581))) ||
             ((uVar11 & 8) != (uint)(*(char *)(param_1 + 0x759d) == '\0'))) {
            if ((uVar11 & 4) == 0) {
              uVar11 = uVar11 & 0xfffffffe;
              *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x10000000;
            }
            _gleUpdateDispatchCodeChange(param_1,uVar11);
            if (*(char *)(param_1 + 0x759d) == '\0') {
              if (*(int *)(param_1 + 0x7574) != 0) {
                return;
              }
              uVar4 = 0x506;
              goto LAB_00098930;
            }
          }
        }
        else {
          _gleSwitchToNonRevertRenderer(param_1);
        }
        iVar10 = 0x13;
        do {
          *piVar14 = 0;
          piVar14 = piVar14 + 1;
          iVar10 = iVar10 + -1;
        } while (iVar10 != 0);
      }
    }
  }
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if (param_8 == 0) {
      return;
    }
    if (param_9 == 0) {
      return;
    }
    iVar10 = _gleCheckCopyTexSubImage2DArgs(param_1,param_2,param_3,param_4,param_5,param_8,param_9)
    ;
    if (iVar10 == 0) {
      return;
    }
    uVar11 = param_2 - 0x8515;
    if (5 < uVar11) {
      uVar11 = 0;
    }
    iVar7 = iVar10 + uVar11 * 0x168 + param_3 * 0x18;
    iVar15 = iVar7 + 0xc4;
    if ((((int)(uint)*(byte *)(iVar10 + 0x8d) <= (int)param_3) &&
        ((int)param_3 <= (int)(uint)*(byte *)(iVar10 + 0x8f))) &&
       ((iVar3 = uVar11 * 2, (*(ushort *)(iVar3 + iVar10 + 0x94) >> (param_3 & 0x3f) & 1) != 0 &&
        (iVar6 = (**(code **)(param_1 + 0x470c))
                           (*(undefined4 *)(param_1 + 0x4688),
                            *(undefined4 *)(iVar10 + (uint)*(byte *)(param_1 + 0x85a8) * 4),uVar11,
                            param_3,param_4,param_5,0,param_6), iVar6 != 0)))) {
      *(undefined4 *)(iVar10 + 0x20) =
           *(undefined4 *)
            ((uint)*(byte *)(param_1 + 0x85a8) * 4 + *(int *)(param_1 + 0x5148) + 0x8054);
      if (*(int *)(iVar7 + 0xd8) != 0) {
        bVar12 = *(byte *)(iVar7 + 0xcf);
        if (((bVar12 & 1) == 0) && (*(short *)(iVar10 + 0x3e) == -0x7a43)) {
          _gleFreeTextureLevel(param_1,iVar10,iVar15);
          bVar12 = *(byte *)(iVar7 + 0xcf);
        }
        *(byte *)(iVar7 + 0xcf) = bVar12 & 0xef;
        *(ushort *)(iVar3 + iVar10 + 0xa0) =
             *(ushort *)(iVar3 + iVar10 + 0xa0) &
             ((ushort)(-2 << (param_3 & 0x1f)) | (ushort)(0xfffffffe >> 0x20 - (param_3 & 0x1f)));
      }
      *(byte *)(iVar7 + 0xcf) = *(byte *)(iVar7 + 0xcf) | 0x40;
      if ((*(uint *)(iVar10 + 0x6c) & 0x8000) == 0) {
        return;
      }
      if ((int)*(short *)(iVar10 + 0x60) != param_3) {
        return;
      }
      uVar13 = param_3 + 1;
      if ((int)(uint)*(byte *)(iVar10 + 0x83) < (int)uVar13) {
        return;
      }
      iVar7 = uVar13 * 0x18 + uVar11 * 0x168 + iVar10 + 0xc4;
      do {
        if (*(int *)(iVar7 + 0x14) != 0) {
          if (((*(byte *)(iVar7 + 0xb) & 1) == 0) && (*(short *)(iVar10 + 0x3e) == -0x7a43)) {
            _gleFreeTextureLevel(param_1,iVar10,iVar7);
          }
          *(byte *)(iVar7 + 0xb) = *(byte *)(iVar7 + 0xb) & 0xef;
          *(ushort *)(iVar3 + iVar10 + 0xa0) =
               *(ushort *)(iVar3 + iVar10 + 0xa0) & ~(ushort)(1 << (uVar13 & 0x3f));
        }
        uVar13 = uVar13 + 1;
        *(byte *)(iVar7 + 0xb) = *(byte *)(iVar7 + 0xb) | 0x40;
        iVar7 = iVar7 + 0x18;
      } while ((int)uVar13 <= (int)(uint)*(byte *)(iVar10 + 0x83));
      return;
    }
    bVar12 = *(byte *)(iVar7 + 0xcf);
    if ((bVar12 & 0x10) == 0) {
      if ((bVar12 & 0x40) == 0) {
        if (*(int *)(iVar7 + 0xd8) == 0) {
          _gleAllocateTextureLevel(param_1,iVar10,iVar15);
          bVar12 = *(byte *)(iVar7 + 0xcf);
        }
        *(byte *)(iVar7 + 0xcf) = bVar12 | 0x10;
      }
      else {
        _gleUploadPluginTextureLevel
                  (param_1,iVar10,iVar15,uVar11,param_3,(uint)*(byte *)(param_1 + 0x85a8));
      }
    }
    _gleModifyPluginTextureLevel(param_1,iVar10,iVar15,uVar11,param_3,param_4,param_5,0,param_8);
    _gleTextureSubImageCopy(param_1,iVar15,param_4,param_5,0,param_6,param_7,param_8,param_9);
    if ((((*(uint *)(iVar10 + 0x6c) & 0x8000) != 0) && ((int)*(short *)(iVar10 + 0x60) == param_3))
       && (iVar10 = _gleGenMipmapsToLevel(param_1,iVar10,uVar11,param_3,0xf,1), iVar10 != 0)) {
      return;
    }
    *(uint *)(param_1 + 0x314) =
         *(uint *)(param_1 + 0x314) | 1 << (*(uint *)(param_1 + 0x53d4) & 0x3f);
    return;
  }
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  uVar4 = 0x502;
LAB_00098930:
  *(undefined4 *)(param_1 + 0x7574) = uVar4;
  return;
}

/* _glCopyTexSubImage2D_CompExec @ 0x98c88 (116 bytes) */
int _glCopyTexSubImage2D_CompExec(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
  undefined4 param_9;
{
  double fparam_1;
  double in_f2;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  
  ((int (*)())_glCopyTexSubImage2D_Comp)(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9)
  ;
  ((void (*)())_glCopyTexSubImage2D_Exec)(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,fparam_1,in_f2,
             in_f3,in_f4,in_f5,in_f6,in_f7,in_f8);
  return;
}

/* _glCopyTexSubImage2D_NoopExec @ 0x98cfc (696 bytes) */
void _glCopyTexSubImage2D_NoopExec(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  bool bVar1;
  char cVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  uint uVar11;
  int *piVar12;
  double extraout_f1;
  double extraout_f1_00;
  double extraout_f1_01;
  
  uVar6 = param_3;
  uVar7 = param_4;
  uVar8 = param_5;
  uVar9 = param_6;
  uVar10 = param_7;
  if (*(int *)(param_1 + 0x50ac) != 0 ||
      (*(uint *)(param_1 + 0x505c) & *(uint *)(param_1 + 0x50b0)) != 0) {
    _gleUpdateMatrixFunc(param_1);
    fparam_1 = extraout_f1;
  }
  if (*(char *)(param_1 + 0x4691) != '\0') {
    iVar5 = *(int *)(param_1 + 0x744c);
    piVar12 = (int *)(param_1 + 0x310);
    cVar2 = *(char *)(*(int *)(param_1 + 0x468c) + 0x79);
    if ((iVar5 != 0) && (*(int *)(iVar5 + 0xec) != 0)) {
      ((int (*)())_gleUpdateFramebufferCompleteness)(param_1,iVar5 + 0x10,uVar6,uVar7,uVar8,uVar9,uVar10,fparam_1,fparam_2,fparam_3,
                 fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
      *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x80000000;
      fparam_1 = fparam_1;
    }
    if ((*(char *)(param_1 + 0x4664) == '\0') && (*(int *)(param_1 + 0x5430) == 0)) {
LAB_00098e30:
      uVar11 = *(uint *)(param_1 + 0x31c);
    }
    else {
      iVar5 = 0;
      piVar4 = (int *)(param_1 + 0x324);
      do {
        iVar3 = *piVar4;
        piVar4 = piVar4 + 1;
        if (iVar3 != 0) {
          *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x800000;
          break;
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < 9);
      uVar11 = *(uint *)(param_1 + 0x31c);
      if ((uVar11 & 0x15555) != 0) {
        if (*(char *)(param_1 + 0x2e54) != '\0') {
          fparam_1 = (double)_gleUpdateLightRGBASums(param_1,param_1 + 0x2c20,0);
        }
        if (*(char *)(param_1 + 0x3094) != '\0') {
          fparam_1 = (double)_gleUpdateLightRGBASums(param_1,param_1 + 0x2e60,1);
        }
        goto LAB_00098e30;
      }
    }
    bVar1 = cVar2 == '\0';
    if (bVar1) {
      uVar11 = uVar11 & 0x17000000;
    }
    else {
      uVar11 = uVar11 & 0x17ffffff;
    }
    if (bVar1) {
      bVar1 = ((*piVar12 == 0 && *(int *)(param_1 + 0x314) == 0) && uVar11 == 0) &&
              *(int *)(param_1 + 800) == 0;
    }
    else {
      bVar1 = (((*piVar12 == 0 && *(int *)(param_1 + 0x314) == 0) &&
               (*(uint *)(param_1 + 0x318) & 0xfffffffd) == 0) && uVar11 == 0) &&
              *(int *)(param_1 + 800) == 0;
    }
    if (!bVar1) {
      if (*(char *)(param_1 + 0x85a8) == *(char *)(param_1 + 0x85a6)) {
        uVar11 = (**(code **)(param_1 + 0x4788))
                           (*(undefined4 *)(param_1 + 0x4688),param_1 + 0x4698,piVar12);
        if ((((uVar11 & 3) != (uint)*(byte *)(param_1 + 0x7580)) ||
            ((uVar11 & 4) != (uint)*(byte *)(param_1 + 0x7581))) ||
           (fparam_1 = extraout_f1_01, (uVar11 & 8) != (uint)(*(char *)(param_1 + 0x759d) == '\0')))
        {
          if ((uVar11 & 4) == 0) {
            uVar11 = uVar11 & 0xfffffffe;
            *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x10000000;
          }
          fparam_1 = (double)_gleUpdateDispatchCodeChange(param_1,uVar11);
          if (*(char *)(param_1 + 0x759d) == '\0') goto LAB_00098f50;
        }
      }
      else {
        fparam_1 = (double)_gleSwitchToNonRevertRenderer(param_1);
      }
      iVar5 = 0x13;
      do {
        *piVar12 = 0;
        piVar12 = piVar12 + 1;
        iVar5 = iVar5 + -1;
      } while (iVar5 != 0);
    }
  }
  if (*(char *)(param_1 + 0x759d) != '\0') {
    ((void (*)())_glCopyTexSubImage2D_Exec)(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,fparam_1,
               fparam_2,fparam_3,fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
    return;
  }
LAB_00098f50:
  if (*(int *)(param_1 + 0x7574) == 0) {
    *(undefined4 *)(param_1 + 0x7574) = 0x506;
  }
  return;
}

/* _glCopyTexSubImage3D_ListExec @ 0x98fb4 (84 bytes) */
undefined4 _glCopyTexSubImage3D_ListExec(undefined4 param_1,undefined4 *param_2,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  ((void (*)())_glCopyTexSubImage3D_Exec)(param_1,*param_2,param_2[1],param_2[2],param_2[3],param_2[4],param_2[5],param_2[6],
             param_2[7],param_2[8],fparam_1,fparam_2,fparam_3,fparam_4,fparam_5,fparam_6,fparam_7,
             fparam_8);
  return 0x24;
}

/* _glCopyTexSubImage3D_Comp @ 0x99008 (132 bytes) */
int _glCopyTexSubImage3D_Comp(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
  undefined4 param_9;
  undefined4 param_10;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glCopyTexSubImage3D_ListExec_001103c4,0x24);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_2;
    puVar1[8] = param_10;
    puVar1[1] = param_3;
    puVar1[2] = param_4;
    puVar1[3] = param_6;
    puVar1[5] = param_7;
    puVar1[6] = param_8;
    puVar1[7] = param_9;
  }
  return puVar1;
}

/* _glCopyTexSubImage3D_Exec @ 0x9908c (1464 bytes) */
void _glCopyTexSubImage3D_Exec(int param_1,undefined4 param_2,uint param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,int param_9,int param_10,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  bool bVar1;
  char cVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  int iVar9;
  uint uVar10;
  byte bVar11;
  int *piVar12;
  int iVar13;
  double extraout_f1;
  
  if ((*(int *)(param_1 + 0x744c) != 0) || (*(int *)(param_1 + 0x310) < 0)) {
    iVar9 = *(int *)(param_1 + 0x50ac);
    uVar10 = param_3;
    uVar3 = param_4;
    uVar7 = param_5;
    uVar8 = param_6;
    if (iVar9 != 0 || (*(uint *)(param_1 + 0x505c) & *(uint *)(param_1 + 0x50b0)) != 0) {
      _gleUpdateMatrixFunc(param_1);
      fparam_1 = extraout_f1;
    }
    if (*(char *)(param_1 + 0x4691) != '\0') {
      iVar6 = *(int *)(param_1 + 0x744c);
      piVar12 = (int *)(param_1 + 0x310);
      cVar2 = *(char *)(*(int *)(param_1 + 0x468c) + 0x79);
      if ((iVar6 != 0) && (*(int *)(iVar6 + 0xec) != 0)) {
        ((int (*)())_gleUpdateFramebufferCompleteness)(param_1,iVar6 + 0x10,uVar10,uVar3,uVar7,uVar8,iVar9,fparam_1,fparam_2,fparam_3,
                   fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
        *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x80000000;
      }
      if ((*(char *)(param_1 + 0x4664) == '\0') && (*(int *)(param_1 + 0x5430) == 0)) {
LAB_000991dc:
        uVar10 = *(uint *)(param_1 + 0x31c);
      }
      else {
        iVar9 = 0;
        piVar4 = (int *)(param_1 + 0x324);
        do {
          iVar6 = *piVar4;
          piVar4 = piVar4 + 1;
          if (iVar6 != 0) {
            *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x800000;
            break;
          }
          iVar9 = iVar9 + 1;
        } while (iVar9 < 9);
        uVar10 = *(uint *)(param_1 + 0x31c);
        if ((uVar10 & 0x15555) != 0) {
          if (*(char *)(param_1 + 0x2e54) != '\0') {
            _gleUpdateLightRGBASums(param_1,param_1 + 0x2c20,0);
          }
          if (*(char *)(param_1 + 0x3094) != '\0') {
            _gleUpdateLightRGBASums(param_1,param_1 + 0x2e60,1);
          }
          goto LAB_000991dc;
        }
      }
      bVar1 = cVar2 == '\0';
      if (bVar1) {
        uVar10 = uVar10 & 0x17000000;
      }
      else {
        uVar10 = uVar10 & 0x17ffffff;
      }
      if (bVar1) {
        bVar1 = ((*piVar12 == 0 && *(int *)(param_1 + 0x314) == 0) && uVar10 == 0) &&
                *(int *)(param_1 + 800) == 0;
      }
      else {
        bVar1 = (((*piVar12 == 0 && *(int *)(param_1 + 0x314) == 0) &&
                 (*(uint *)(param_1 + 0x318) & 0xfffffffd) == 0) && uVar10 == 0) &&
                *(int *)(param_1 + 800) == 0;
      }
      if (!bVar1) {
        if (*(char *)(param_1 + 0x85a8) == *(char *)(param_1 + 0x85a6)) {
          uVar10 = (**(code **)(param_1 + 0x4788))
                             (*(undefined4 *)(param_1 + 0x4688),param_1 + 0x4698,piVar12);
          if ((((uVar10 & 3) != (uint)*(byte *)(param_1 + 0x7580)) ||
              ((uVar10 & 4) != (uint)*(byte *)(param_1 + 0x7581))) ||
             ((uVar10 & 8) != (uint)(*(char *)(param_1 + 0x759d) == '\0'))) {
            if ((uVar10 & 4) == 0) {
              uVar10 = uVar10 & 0xfffffffe;
              *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x10000000;
            }
            _gleUpdateDispatchCodeChange(param_1,uVar10);
            if (*(char *)(param_1 + 0x759d) == '\0') {
              if (*(int *)(param_1 + 0x7574) != 0) {
                return;
              }
              uVar3 = 0x506;
              goto LAB_0009931c;
            }
          }
        }
        else {
          _gleSwitchToNonRevertRenderer(param_1);
        }
        iVar9 = 0x13;
        do {
          *piVar12 = 0;
          piVar12 = piVar12 + 1;
          iVar9 = iVar9 + -1;
        } while (iVar9 != 0);
      }
    }
  }
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if (param_9 == 0) {
      return;
    }
    if (param_10 == 0) {
      return;
    }
    iVar9 = _gleCheckCopyTexSubImage3DArgs
                      (param_1,param_2,param_3,param_4,param_5,param_6,param_9,param_10,1);
    if (iVar9 == 0) {
      return;
    }
    iVar6 = iVar9 + param_3 * 0x18;
    iVar13 = iVar6 + 0xc4;
    if ((((int)(uint)*(byte *)(iVar9 + 0x8d) <= (int)param_3) &&
        ((int)param_3 <= (int)(uint)*(byte *)(iVar9 + 0x8f))) &&
       (((*(ushort *)(iVar9 + 0x94) >> (param_3 & 0x3f) & 1) != 0 &&
        (iVar5 = (**(code **)(param_1 + 0x470c))
                           (*(undefined4 *)(param_1 + 0x4688),
                            *(undefined4 *)(iVar9 + (uint)*(byte *)(param_1 + 0x85a8) * 4),0,param_3
                            ,param_4,param_5,param_6,param_7), iVar5 != 0)))) {
      *(undefined4 *)(iVar9 + 0x20) =
           *(undefined4 *)
            ((uint)*(byte *)(param_1 + 0x85a8) * 4 + *(int *)(param_1 + 0x5148) + 0x8054);
      if (*(int *)(iVar6 + 0xd8) != 0) {
        bVar11 = *(byte *)(iVar6 + 0xcf);
        if (((bVar11 & 1) == 0) && (*(short *)(iVar9 + 0x3e) == -0x7a43)) {
          _gleFreeTextureLevel(param_1,iVar9,iVar13);
          bVar11 = *(byte *)(iVar6 + 0xcf);
        }
        *(byte *)(iVar6 + 0xcf) = bVar11 & 0xef;
        *(ushort *)(iVar9 + 0xa0) =
             *(ushort *)(iVar9 + 0xa0) &
             ((ushort)(-2 << (param_3 & 0x1f)) | (ushort)(0xfffffffe >> 0x20 - (param_3 & 0x1f)));
      }
      *(byte *)(iVar6 + 0xcf) = *(byte *)(iVar6 + 0xcf) | 0x40;
      if ((*(uint *)(iVar9 + 0x6c) & 0x8000) == 0) {
        return;
      }
      if ((int)*(short *)(iVar9 + 0x60) != param_3) {
        return;
      }
      uVar10 = param_3 + 1;
      if ((int)(uint)*(byte *)(iVar9 + 0x83) < (int)uVar10) {
        return;
      }
      iVar6 = uVar10 * 0x18 + iVar9 + 0xc4;
      do {
        if (*(int *)(iVar6 + 0x14) != 0) {
          if (((*(byte *)(iVar6 + 0xb) & 1) == 0) && (*(short *)(iVar9 + 0x3e) == -0x7a43)) {
            _gleFreeTextureLevel(param_1,iVar9,iVar6);
          }
          *(byte *)(iVar6 + 0xb) = *(byte *)(iVar6 + 0xb) & 0xef;
          *(ushort *)(iVar9 + 0xa0) = *(ushort *)(iVar9 + 0xa0) & ~(ushort)(1 << (uVar10 & 0x3f));
        }
        uVar10 = uVar10 + 1;
        *(byte *)(iVar6 + 0xb) = *(byte *)(iVar6 + 0xb) | 0x40;
        iVar6 = iVar6 + 0x18;
      } while ((int)uVar10 <= (int)(uint)*(byte *)(iVar9 + 0x83));
      return;
    }
    bVar11 = *(byte *)(iVar6 + 0xcf);
    if ((bVar11 & 0x10) == 0) {
      if ((bVar11 & 0x40) == 0) {
        if (*(int *)(iVar6 + 0xd8) == 0) {
          _gleAllocateTextureLevel(param_1,iVar9,iVar13);
          bVar11 = *(byte *)(iVar6 + 0xcf);
        }
        *(byte *)(iVar6 + 0xcf) = bVar11 | 0x10;
      }
      else {
        _gleUploadPluginTextureLevel
                  (param_1,iVar9,iVar13,0,param_3,(uint)*(byte *)(param_1 + 0x85a8));
      }
    }
    _gleModifyPluginTextureLevel(param_1,iVar9,iVar13,0,param_3,param_4,param_5,param_6,param_9);
    _gleTextureSubImageCopy(param_1,iVar13,param_4,param_5,param_6,param_7,param_8,param_9,param_10)
    ;
    if ((((*(uint *)(iVar9 + 0x6c) & 0x8000) != 0) && ((int)*(short *)(iVar9 + 0x60) == param_3)) &&
       (iVar9 = _gleGenMipmapsToLevel(param_1,iVar9,0,param_3,0xf,1), iVar9 != 0)) {
      return;
    }
    *(uint *)(param_1 + 0x314) =
         *(uint *)(param_1 + 0x314) | 1 << (*(uint *)(param_1 + 0x53d4) & 0x3f);
    return;
  }
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  uVar3 = 0x502;
LAB_0009931c:
  *(undefined4 *)(param_1 + 0x7574) = uVar3;
  return;
}

/* _glCopyTexSubImage3D_CompExec @ 0x99644 (128 bytes) */
int _glCopyTexSubImage3D_CompExec(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
  undefined4 param_9;
  undefined4 param_10;
{
  double fparam_1;
  double in_f2;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  
  ((int (*)())_glCopyTexSubImage3D_Comp)(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,param_10);
  ((void (*)())_glCopyTexSubImage3D_Exec)(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,param_10,
             fparam_1,in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8);
  return;
}

/* _glCopyTexSubImage3D_NoopExec @ 0x996c4 (704 bytes) */
void _glCopyTexSubImage3D_NoopExec(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9,undefined4 param_10,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  bool bVar1;
  char cVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  uint uVar11;
  int *piVar12;
  double extraout_f1;
  double extraout_f1_00;
  double extraout_f1_01;
  
  uVar6 = param_3;
  uVar7 = param_4;
  uVar8 = param_5;
  uVar9 = param_6;
  uVar10 = param_7;
  if (*(int *)(param_1 + 0x50ac) != 0 ||
      (*(uint *)(param_1 + 0x505c) & *(uint *)(param_1 + 0x50b0)) != 0) {
    _gleUpdateMatrixFunc(param_1);
    fparam_1 = extraout_f1;
  }
  if (*(char *)(param_1 + 0x4691) != '\0') {
    iVar5 = *(int *)(param_1 + 0x744c);
    piVar12 = (int *)(param_1 + 0x310);
    cVar2 = *(char *)(*(int *)(param_1 + 0x468c) + 0x79);
    if ((iVar5 != 0) && (*(int *)(iVar5 + 0xec) != 0)) {
      ((int (*)())_gleUpdateFramebufferCompleteness)(param_1,iVar5 + 0x10,uVar6,uVar7,uVar8,uVar9,uVar10,fparam_1,fparam_2,fparam_3,
                 fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
      *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x80000000;
      fparam_1 = fparam_1;
    }
    if ((*(char *)(param_1 + 0x4664) == '\0') && (*(int *)(param_1 + 0x5430) == 0)) {
LAB_000997fc:
      uVar11 = *(uint *)(param_1 + 0x31c);
    }
    else {
      iVar5 = 0;
      piVar4 = (int *)(param_1 + 0x324);
      do {
        iVar3 = *piVar4;
        piVar4 = piVar4 + 1;
        if (iVar3 != 0) {
          *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x800000;
          break;
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < 9);
      uVar11 = *(uint *)(param_1 + 0x31c);
      if ((uVar11 & 0x15555) != 0) {
        if (*(char *)(param_1 + 0x2e54) != '\0') {
          fparam_1 = (double)_gleUpdateLightRGBASums(param_1,param_1 + 0x2c20,0);
        }
        if (*(char *)(param_1 + 0x3094) != '\0') {
          fparam_1 = (double)_gleUpdateLightRGBASums(param_1,param_1 + 0x2e60,1);
        }
        goto LAB_000997fc;
      }
    }
    bVar1 = cVar2 == '\0';
    if (bVar1) {
      uVar11 = uVar11 & 0x17000000;
    }
    else {
      uVar11 = uVar11 & 0x17ffffff;
    }
    if (bVar1) {
      bVar1 = ((*piVar12 == 0 && *(int *)(param_1 + 0x314) == 0) && uVar11 == 0) &&
              *(int *)(param_1 + 800) == 0;
    }
    else {
      bVar1 = (((*piVar12 == 0 && *(int *)(param_1 + 0x314) == 0) &&
               (*(uint *)(param_1 + 0x318) & 0xfffffffd) == 0) && uVar11 == 0) &&
              *(int *)(param_1 + 800) == 0;
    }
    if (!bVar1) {
      if (*(char *)(param_1 + 0x85a8) == *(char *)(param_1 + 0x85a6)) {
        uVar11 = (**(code **)(param_1 + 0x4788))
                           (*(undefined4 *)(param_1 + 0x4688),param_1 + 0x4698,piVar12);
        if ((((uVar11 & 3) != (uint)*(byte *)(param_1 + 0x7580)) ||
            ((uVar11 & 4) != (uint)*(byte *)(param_1 + 0x7581))) ||
           (fparam_1 = extraout_f1_01, (uVar11 & 8) != (uint)(*(char *)(param_1 + 0x759d) == '\0')))
        {
          if ((uVar11 & 4) == 0) {
            uVar11 = uVar11 & 0xfffffffe;
            *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x10000000;
          }
          fparam_1 = (double)_gleUpdateDispatchCodeChange(param_1,uVar11);
          if (*(char *)(param_1 + 0x759d) == '\0') goto LAB_0009991c;
        }
      }
      else {
        fparam_1 = (double)_gleSwitchToNonRevertRenderer(param_1);
      }
      iVar5 = 0x13;
      do {
        *piVar12 = 0;
        piVar12 = piVar12 + 1;
        iVar5 = iVar5 + -1;
      } while (iVar5 != 0);
    }
  }
  if (*(char *)(param_1 + 0x759d) != '\0') {
    ((void (*)())_glCopyTexSubImage3D_Exec)(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,param_10,
               fparam_1,fparam_2,fparam_3,fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
    return;
  }
LAB_0009991c:
  if (*(int *)(param_1 + 0x7574) == 0) {
    *(undefined4 *)(param_1 + 0x7574) = 0x506;
  }
  return;
}

/* _glTexEnvf_ListExec @ 0x99984 (52 bytes) */
int _glTexEnvf_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  ((void (*)())_glTexEnvf_Exec)(param_1,*param_2,param_2[1],(double)GH_U2F((unsigned int)(param_2[2])));
  return 0xc;
}

/* _glTexEnvf_Comp @ 0x999b8 (100 bytes) */
undefined4 * _glTexEnvf_Comp(undefined4 param_1,undefined4 param_2,undefined4 param_3,double fparam_1)
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glTexEnvf_ListExec_001103dc,0xc);
  if (puVar1 != (undefined4 *)0x0) {
    puVar1[2] = (float)fparam_1;
    *puVar1 = param_2;
    puVar1[1] = param_3;
  }
  return puVar1;
}

/* _CheckNVShaderOperation @ 0x99a1c (388 bytes) */
int _CheckNVShaderOperation(param_1, param_2)
  int param_1;
  uint param_2;
{
  bool bVar1;
  uint uVar2;
  
  if (0x86e7 < param_2) {
    if (param_2 < 0x86f1) {
      if (0x86ee < param_2) {
LAB_00099b80:
        if (*(uint *)(param_1 + 0x53d4) < 3) {
          return 0x502;
        }
        return 0;
      }
      if (param_2 == 0x86ec) {
        uVar2 = *(uint *)(param_1 + 0x53d4);
        if (uVar2 == 0) {
          return 0x502;
        }
LAB_00099b64:
        if (*(ushort *)(*(int *)(param_1 + 0x468c) + 0xb4) - 1 <= uVar2) {
          return 0x502;
        }
        return 0;
      }
      if (0x86ec < param_2) goto LAB_00099b44;
      bVar1 = 0x86ea < param_2;
    }
    else {
      if (param_2 < 0x86f4) {
        if (param_2 < 0x86f2) {
          uVar2 = *(uint *)(param_1 + 0x53d4);
          if (uVar2 < 2) {
            return 0x502;
          }
          goto LAB_00099b64;
        }
        goto LAB_00099b80;
      }
      bVar1 = 0xd < param_2 - 0x8850;
    }
    if (bVar1) {
      return 0x500;
    }
    goto LAB_00099b30;
  }
  if (0x86e5 < param_2) {
    return 0;
  }
  if (param_2 == 0x8513) {
    return 0;
  }
  if (param_2 < 0x8514) {
    if (param_2 < 0xde2) {
      if (0xddf < param_2) {
        return 0;
      }
      bVar1 = param_2 == 0;
      goto LAB_00099a94;
    }
    if (param_2 == 0x806f) {
      return 0;
    }
    uVar2 = 0x84f5;
  }
  else {
    if (0x864d < param_2) {
      if (param_2 == 0x864e) {
LAB_00099b44:
        if (*(uint *)(param_1 + 0x53d4) < 2) {
          return 0x502;
        }
        return 0;
      }
      if (param_2 != 0x86e2) {
        return 0x500;
      }
LAB_00099b30:
      if (*(int *)(param_1 + 0x53d4) == 0) {
        return 0x502;
      }
      return 0;
    }
    if (0x864b < param_2) goto LAB_00099b30;
    uVar2 = 0x85b3;
  }
  bVar1 = param_2 == uVar2;
LAB_00099a94:
  if (!bVar1) {
    return 0x500;
  }
  return 0;
}

/* _glTexEnvf_CompExec @ 0x99ba0 (80 bytes) */
void _glTexEnvf_CompExec(undefined4 param_1,undefined4 param_2,undefined4 param_3,double fparam_1)
{
  ((undefined4 * (*)())_glTexEnvf_Comp)(param_1,param_2,param_3,fparam_1);
  ((void (*)())_glTexEnvf_Exec)(param_1,param_2,param_3,fparam_1);
  return;
}

/* _glTexEnvfv_ListExec @ 0x99bf0 (52 bytes) */
int _glTexEnvfv_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  _glTexEnvfv_Exec(param_1,*param_2,param_2[1],param_2 + 2);
  return 0x18;
}

/* _glTexEnvfv_Comp @ 0x99c24 (292 bytes) */
int _glTexEnvfv_Comp(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  int param_2;
  int param_3;
  int *param_4;
{
  int *piVar1;
  
  if (((param_2 != 0x2300) || (param_3 != 0x2201)) &&
     ((param_2 != 0x86de || (1 < param_3 - 0x86e0U)))) {
    if ((param_2 != 0x2300) || (param_3 != 0x86e5)) {
      piVar1 = (int *)_gleAddListItem(param_1,PTR__glTexEnvfv_ListExec_001103d8,0x18);
      if (piVar1 != (int *)0x0) {
        *piVar1 = param_2;
        piVar1[1] = param_3;
        piVar1[2] = *param_4;
      }
    }
    else {
      piVar1 = (int *)_gleAddListItem(param_1,PTR__glTexEnviv_ListExec_001103d4,0x18);
      if (piVar1 != (int *)0x0) {
        *piVar1 = 0x2300;
        piVar1[1] = 0x86e5;
        piVar1[2] = *param_4;
        piVar1[3] = param_4[1];
        piVar1[4] = param_4[2];
      }
    }
  }
  else {
    piVar1 = (int *)_gleAddListItem(param_1,PTR__glTexEnvfv_ListExec_001103d8,0x18);
    if (piVar1 != (int *)0x0) {
      *piVar1 = param_2;
      piVar1[1] = param_3;
      piVar1[2] = *param_4;
      piVar1[3] = param_4[1];
      piVar1[4] = param_4[2];
      piVar1[5] = param_4[3];
    }
  }
  return piVar1;
}

/* _glTexEnvfv_CompExec @ 0x99d48 (72 bytes) */
int _glTexEnvfv_CompExec(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  ((int (*)())_glTexEnvfv_Comp)(param_1,param_2,param_3,param_4);
  _glTexEnvfv_Exec(param_1,param_2,param_3,param_4);
  return;
}

/* _glTexEnvi_ListExec @ 0x99d90 (52 bytes) */
int _glTexEnvi_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  _glTexEnvi_Exec(param_1,*param_2,param_2[1],param_2[2]);
  return 0xc;
}

/* _glTexEnvi_Comp @ 0x99dc4 (92 bytes) */
int _glTexEnvi_Comp(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glTexEnvi_ListExec_001103d0,0xc);
  if (puVar1 != (undefined4 *)0x0) {
    puVar1[2] = param_4;
    *puVar1 = param_2;
    puVar1[1] = param_3;
  }
  return puVar1;
}

/* _glTexEnvi_CompExec @ 0x99e20 (72 bytes) */
int _glTexEnvi_CompExec(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  ((int (*)())_glTexEnvi_Comp)(param_1,param_2,param_3,param_4);
  _glTexEnvi_Exec(param_1,param_2,param_3,param_4);
  return;
}

/* _glTexEnviv_ListExec @ 0x99e68 (52 bytes) */
int _glTexEnviv_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  ((int (*)())_glTexEnviv_Exec)(param_1,*param_2,param_2[1],param_2 + 2);
  return 0x18;
}

/* _glTexEnviv_Comp @ 0x99e9c (292 bytes) */
int _glTexEnviv_Comp(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  int param_2;
  int param_3;
  int *param_4;
{
  int *piVar1;
  
  if (((param_2 != 0x2300) || (param_3 != 0x2201)) &&
     ((param_2 != 0x86de || (1 < param_3 - 0x86e0U)))) {
    if ((param_2 != 0x2300) || (param_3 != 0x86e5)) {
      piVar1 = (int *)_gleAddListItem(param_1,PTR__glTexEnviv_ListExec_001103d4,0x18);
      if (piVar1 != (int *)0x0) {
        *piVar1 = param_2;
        piVar1[1] = param_3;
        piVar1[2] = *param_4;
      }
    }
    else {
      piVar1 = (int *)_gleAddListItem(param_1,PTR__glTexEnviv_ListExec_001103d4,0x18);
      if (piVar1 != (int *)0x0) {
        *piVar1 = 0x2300;
        piVar1[1] = 0x86e5;
        piVar1[2] = *param_4;
        piVar1[3] = param_4[1];
        piVar1[4] = param_4[2];
      }
    }
  }
  else {
    piVar1 = (int *)_gleAddListItem(param_1,PTR__glTexEnviv_ListExec_001103d4,0x18);
    if (piVar1 != (int *)0x0) {
      *piVar1 = param_2;
      piVar1[1] = param_3;
      piVar1[2] = *param_4;
      piVar1[3] = param_4[1];
      piVar1[4] = param_4[2];
      piVar1[5] = param_4[3];
    }
  }
  return piVar1;
}

/* _glTexEnviv_Exec @ 0x99fc0 (3296 bytes) */
int _glTexEnviv_Exec(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  uint param_3;
  uint *param_4;
{
  bool bVar1;
  byte bVar2;
  float fVar3;
  double dVar4;
  float fVar5;
  undefined4 uVar6;
  int iVar7;
  uint uVar8;
  code *pcVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  
  fVar5 = FLOAT_00108e50;
  dVar4 = DOUBLE_00108d58;
  uVar12 = *(uint *)(param_1 + 0x53d4);
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if (param_2 == 0x86de) {
      iVar7 = param_1 + uVar12 * 0x7c;
      switch(param_3) {
      case 0x86d9:
        if ((*param_4 != 0x8536) && (*param_4 != 0x8538)) goto switchD_0009a048_caseD_86da;
        *(short *)(iVar7 + 0x356c) = (short)*param_4;
        break;
      default:
switchD_0009a048_caseD_86da:
        if (*(int *)(param_1 + 0x7574) != 0) {
          return;
        }
        uVar6 = 0x500;
        goto LAB_0009acbc;
      case 0x86df:
        iVar11 = ((int (*)())_CheckNVShaderOperation)(param_1,*param_4);
        if (iVar11 != 0) {
          if (*(int *)(param_1 + 0x7574) != 0) {
            return;
          }
          *(int *)(param_1 + 0x7574) = iVar11;
          return;
        }
        *(short *)(iVar7 + 0x3564) = (short)*param_4;
        _gleUpdateTextureParams(param_1,uVar12);
        break;
      case 0x86e0:
        uVar8 = *param_4;
        iVar11 = 4;
        do {
          if (((uVar8 != 0x201) && (uVar8 != 0x206)) && (*(int *)(param_1 + 0x7574) == 0)) {
            *(undefined4 *)(param_1 + 0x7574) = 0x500;
            uVar8 = *param_4;
          }
          iVar10 = 0;
          iVar11 = iVar11 + -1;
        } while (iVar11 != 0);
        while( true ) {
          if ((uVar8 == 0x201) || (uVar8 == 0x206)) {
            *(short *)(iVar10 * 2 + iVar7 + 0x3570) = (short)*param_4;
          }
          iVar10 = iVar10 + 1;
          if (3 < iVar10) break;
          uVar8 = *param_4;
        }
        break;
      case 0x86e1:
        *(float *)(iVar7 + 0x3588) =
             (float)((double)CONCAT44(0x43300000,*param_4 ^ 0x80000000) - DOUBLE_00108d58);
        *(float *)(iVar7 + 0x358c) =
             (float)((double)CONCAT44(0x43300000,param_4[1] ^ 0x80000000) - dVar4);
        *(float *)(iVar7 + 0x3590) =
             (float)((double)CONCAT44(0x43300000,param_4[2] ^ 0x80000000) - dVar4);
        *(float *)(iVar7 + 0x3594) =
             (float)((double)CONCAT44(0x43300000,param_4[3] ^ 0x80000000) - dVar4);
        break;
      case 0x86e2:
        *(float *)(iVar7 + 0x3598) =
             (float)((double)CONCAT44(0x43300000,*param_4 ^ 0x80000000) - DOUBLE_00108d58);
        break;
      case 0x86e3:
        *(float *)(iVar7 + 0x359c) =
             (float)((double)CONCAT44(0x43300000,*param_4 ^ 0x80000000) - DOUBLE_00108d58);
        break;
      case 0x86e4:
        if (((int)*param_4 < 0x84c0) ||
           ((int)(*(ushort *)(*(int *)(param_1 + 0x468c) + 0xb4) + 0x84c0) <= (int)*param_4))
        goto switchD_0009a048_caseD_86da;
        *(short *)(iVar7 + 0x356a) = (short)*param_4;
        break;
      case 0x86e5:
        *(float *)(iVar7 + 0x357c) =
             (float)((double)CONCAT44(0x43300000,*param_4 ^ 0x80000000) - DOUBLE_00108d58);
        *(float *)(iVar7 + 0x3580) =
             (float)((double)CONCAT44(0x43300000,param_4[1] ^ 0x80000000) - dVar4);
        *(float *)(iVar7 + 0x3584) =
             (float)((double)CONCAT44(0x43300000,param_4[2] ^ 0x80000000) - dVar4);
      }
      uVar8 = *(uint *)(param_1 + 800);
      iVar7 = 1;
    }
    else {
      if (param_2 == 0x8861) {
        if (param_3 == 0x8862) {
          if (*param_4 == 0) {
            uVar12 = *(uint *)(param_1 + 0x3444) &
                     (-2 << (uVar12 & 0x1f) | 0xfffffffeU >> 0x20 - (uVar12 & 0x1f));
          }
          else {
            uVar12 = *(uint *)(param_1 + 0x3444) | 1 << (uVar12 & 0x3f);
          }
          *(uint *)(param_1 + 0x3444) = uVar12;
          *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x400000;
          return;
        }
        goto switchD_0009a048_caseD_86da;
      }
      if (param_2 != 0x2300) {
        if ((param_2 == 0x8500) && (param_3 == 0x8501)) {
          *(float *)(uVar12 * 0x7c + param_1 + 0x3560) =
               (float)((double)CONCAT44(0x43300000,*param_4 ^ 0x80000000) - DOUBLE_00108d58);
          *(uint *)(param_1 + 800) = *(uint *)(param_1 + 800) | 0x10000 << (uVar12 & 0x3f);
          return;
        }
        goto switchD_0009a048_caseD_86da;
      }
      if (param_3 == 0x2200) {
        uVar8 = *param_4;
        if (uVar8 == 0x1e01) goto LAB_0009a3c0;
        if ((int)uVar8 < 0x1e02) {
          if (uVar8 == 0x104) goto LAB_0009a3c0;
          if ((int)uVar8 < 0x105) {
            bVar1 = uVar8 == 0;
          }
          else {
            bVar1 = uVar8 == 0xbe2;
          }
        }
        else {
          if ((int)uVar8 < 0x2100) goto switchD_0009a048_caseD_86da;
          if ((int)uVar8 < 0x2102) goto LAB_0009a3c0;
          bVar1 = uVar8 == 0x8570;
        }
        if (bVar1) {
LAB_0009a3c0:
          *(short *)(uVar12 * 0x7c + param_1 + 0x3538) = (short)*param_4;
          *(uint *)(param_1 + 800) = *(uint *)(param_1 + 800) | 1 << (uVar12 & 0x3f);
          return;
        }
        goto switchD_0009a048_caseD_86da;
      }
      if (param_3 == 0x2201) {
        iVar7 = param_1 + uVar12 * 0x7c;
        fVar3 = (float)((double)CONCAT44(0x43300000,*param_4 ^ 0x80000000) - DOUBLE_00108d58) *
                FLOAT_00108e68 + FLOAT_00108e6c;
        if (FLOAT_00108e50 <= fVar3) {
          *(float *)(iVar7 + 0x3524) = fVar3;
        }
        else {
          *(float *)(iVar7 + 0x3524) = FLOAT_00108e50;
        }
        fVar3 = (float)((double)CONCAT44(0x43300000,param_4[1] ^ 0x80000000) - DOUBLE_00108d58) *
                FLOAT_00108e68 + FLOAT_00108e6c;
        if (fVar5 <= fVar3) {
          *(float *)(iVar7 + 0x3528) = fVar3;
        }
        else {
          *(float *)(iVar7 + 0x3528) = fVar5;
        }
        fVar3 = (float)((double)CONCAT44(0x43300000,param_4[2] ^ 0x80000000) - DOUBLE_00108d58) *
                FLOAT_00108e68 + FLOAT_00108e6c;
        if (fVar5 <= fVar3) {
          *(float *)(iVar7 + 0x352c) = fVar3;
        }
        else {
          *(float *)(iVar7 + 0x352c) = fVar5;
        }
        fVar3 = (float)((double)CONCAT44(0x43300000,param_4[3] ^ 0x80000000) - DOUBLE_00108d58) *
                FLOAT_00108e68 + FLOAT_00108e6c;
        if (fVar5 <= fVar3) {
          *(float *)(iVar7 + 0x3530) = fVar3;
        }
        else {
          *(float *)(iVar7 + 0x3530) = fVar5;
        }
        if (*(int *)(param_1 + 0x5434) == 0) {
          bVar2 = *(byte *)(uVar12 + *(int *)(param_1 + 0x5420) + 0x30c);
        }
        else {
          bVar2 = *(byte *)(uVar12 + *(int *)(*(int *)(param_1 + 0x5430) + 0x20) + 0x340);
        }
        iVar11 = (bVar2 >> 3 & 0x1c) + param_1;
        iVar7 = *(int *)(param_1 + 0x5424);
        *(uint *)(iVar11 + 0x324) = *(uint *)(iVar11 + 0x324) | 1 << (bVar2 & 0x1f);
        bVar2 = *(byte *)(uVar12 + iVar7 + 0x30c);
        iVar7 = (bVar2 >> 3 & 0x1c) + param_1;
        *(uint *)(iVar7 + 0x348) = *(uint *)(iVar7 + 0x348) | 1 << (bVar2 & 0x1f);
        iVar7 = 0x100;
        uVar8 = *(uint *)(param_1 + 800);
      }
      else {
        if (param_3 == 0x8588) {
          uVar8 = *param_4;
          if ((((uVar8 == 0x1702) || (uVar8 - 0x84c0 < 0x10)) || (uVar8 == 0x8576)) ||
             (((uVar8 == 0x8577 || (uVar8 == 0x8578)) || ((uVar8 == 0 || (uVar8 == 1)))))) {
            *(short *)(uVar12 * 0x7c + param_1 + 0x3546) = (short)*param_4;
            goto LAB_0009ac28;
          }
          goto switchD_0009a048_caseD_86da;
        }
        if (param_3 < 0x8589) {
          if (param_3 == 0x8573) {
            uVar8 = *param_4;
            if ((uVar8 - 1 < 2) || (uVar8 == 4)) {
              *(float *)(uVar12 * 0x7c + param_1 + 0x3558) =
                   (float)((double)CONCAT44(0x43300000,uVar8 ^ 0x80000000) - DOUBLE_00108d58);
            }
            else {
LAB_0009abe0:
              if (*(int *)(param_1 + 0x7574) == 0) {
                *(undefined4 *)(param_1 + 0x7574) = 0x500;
              }
            }
          }
          else {
            if (0x8573 < param_3) {
              if (param_3 == 0x8581) {
                uVar8 = *param_4;
                if ((((uVar8 == 0x1702) || (uVar8 - 0x84c0 < 0x10)) || (uVar8 == 0x8576)) ||
                   (((uVar8 == 0x8577 || (uVar8 == 0x8578)) || ((uVar8 == 0 || (uVar8 == 1)))))) {
                  *(short *)(uVar12 * 0x7c + param_1 + 0x3542) = (short)*param_4;
                  goto LAB_0009ac28;
                }
              }
              else if (param_3 < 0x8582) {
                if ((param_3 == 0x8580) &&
                   ((((uVar8 = *param_4, uVar8 == 0x1702 || (uVar8 - 0x84c0 < 0x10)) ||
                     ((uVar8 == 0x8576 || ((uVar8 == 0x8577 || (uVar8 == 0x8578)))))) ||
                    ((uVar8 == 0 || (uVar8 == 1)))))) {
                  *(short *)(uVar12 * 0x7c + param_1 + 0x3540) = (short)*param_4;
                  goto LAB_0009ac28;
                }
              }
              else if ((param_3 == 0x8582) &&
                      (((uVar8 = *param_4, uVar8 == 0x1702 || (uVar8 - 0x84c0 < 0x10)) ||
                       ((uVar8 == 0x8576 ||
                        ((((uVar8 == 0x8577 || (uVar8 == 0x8578)) || (uVar8 == 0)) || (uVar8 == 1)))
                        ))))) {
                *(short *)(uVar12 * 0x7c + param_1 + 0x3544) = (short)*param_4;
                goto LAB_0009ac28;
              }
              goto switchD_0009a048_caseD_86da;
            }
            if (param_3 == 0x8571) {
              pcVar9 = (code *)*param_4;
              if ((int)pcVar9 < 0x8576) {
                if (((int)pcVar9 < 0x8574) && (pcVar9 != (code *)0x1e01)) {
                  if ((int)pcVar9 < 0x1e02) {
                    bVar1 = pcVar9 == (code *)0x104;
                  }
                  else {
                    if (pcVar9 == _glePreInitVertexSubmitFunc) goto LAB_0009a770;
                    bVar1 = pcVar9 == (code *)0x84e7;
                  }
                  if (!bVar1) goto switchD_0009a048_caseD_86da;
                }
              }
              else if (((int)pcVar9 < 0x86ae) ||
                      ((0x86af < (int)pcVar9 && ((code *)0x2 < pcVar9 + -0x8744))))
              goto switchD_0009a048_caseD_86da;
LAB_0009a770:
              *(short *)(uVar12 * 0x7c + param_1 + 0x353c) = (short)*param_4;
            }
            else {
              if (param_3 < 0x8572) {
                if (param_3 == 0xd1c) {
                  uVar8 = *param_4;
                  if ((1 < uVar8 - 1) && (uVar8 != 4)) goto LAB_0009abe0;
                  *(float *)(uVar12 * 0x7c + param_1 + 0x355c) =
                       (float)((double)CONCAT44(0x43300000,uVar8 ^ 0x80000000) - DOUBLE_00108d58);
                  goto LAB_0009ac28;
                }
                goto switchD_0009a048_caseD_86da;
              }
              pcVar9 = (code *)*param_4;
              if (pcVar9 != (code *)0x84e7) {
                if ((int)pcVar9 < 0x84e8) {
                  if (pcVar9 != (code *)0x1e01) {
                    if ((int)pcVar9 < 0x1e02) {
                      bVar1 = pcVar9 == (code *)0x104;
                    }
                    else {
                      bVar1 = pcVar9 == _glePreInitVertexSubmitFunc;
                    }
                    if (!bVar1) goto switchD_0009a048_caseD_86da;
                  }
                }
                else if (((int)pcVar9 < 0x8574) ||
                        ((0x8575 < (int)pcVar9 && ((code *)0x2 < pcVar9 + -0x8744))))
                goto switchD_0009a048_caseD_86da;
              }
              *(short *)(uVar12 * 0x7c + param_1 + 0x353e) = (short)*param_4;
            }
          }
        }
        else {
          if (param_3 != 0x8591) {
            if (param_3 < 0x8592) {
              if (param_3 == 0x858a) {
                uVar8 = *param_4;
                if ((((((uVar8 == 0x1702) || (uVar8 - 0x84c0 < 0x10)) || (uVar8 == 0x8576)) ||
                     ((uVar8 == 0x8577 || (uVar8 == 0x8578)))) || (uVar8 == 0)) || (uVar8 == 1)) {
                  *(short *)(uVar12 * 0x7c + param_1 + 0x354a) = (short)*param_4;
                  goto LAB_0009ac28;
                }
              }
              else if (param_3 < 0x858a) {
                uVar8 = *param_4;
                if ((((uVar8 == 0x1702) || (uVar8 - 0x84c0 < 0x10)) ||
                    ((uVar8 == 0x8576 || (((uVar8 == 0x8577 || (uVar8 == 0x8578)) || (uVar8 == 0))))
                    )) || (uVar8 == 1)) {
                  *(short *)(uVar12 * 0x7c + param_1 + 0x3548) = (short)*param_4;
                  goto LAB_0009ac28;
                }
              }
              else if ((param_3 == 0x8590) && (*param_4 - 0x300 < 4)) {
                *(short *)(uVar12 * 0x7c + param_1 + 0x354c) = (short)*param_4;
                goto LAB_0009ac28;
              }
            }
            else if (param_3 == 0x8598) {
              if (*param_4 - 0x302 < 2) {
                *(short *)(uVar12 * 0x7c + param_1 + 0x3552) = (short)*param_4;
                goto LAB_0009ac28;
              }
            }
            else if (param_3 < 0x8599) {
              if ((param_3 == 0x8592) && (*param_4 - 0x300 < 4)) {
                *(short *)(uVar12 * 0x7c + param_1 + 0x3550) = (short)*param_4;
                goto LAB_0009ac28;
              }
            }
            else if (param_3 == 0x8599) {
              if (*param_4 - 0x302 < 2) {
                *(short *)(uVar12 * 0x7c + param_1 + 0x3554) = (short)*param_4;
                goto LAB_0009ac28;
              }
            }
            else if ((param_3 == 0x859a) && (*param_4 - 0x302 < 2)) {
              *(short *)(uVar12 * 0x7c + param_1 + 0x3556) = (short)*param_4;
              goto LAB_0009ac28;
            }
            goto switchD_0009a048_caseD_86da;
          }
          if (3 < *param_4 - 0x300) goto switchD_0009a048_caseD_86da;
          *(short *)(uVar12 * 0x7c + param_1 + 0x354e) = (short)*param_4;
        }
LAB_0009ac28:
        uVar8 = *(uint *)(param_1 + 800);
        iVar7 = 0x1000000;
      }
    }
    *(uint *)(param_1 + 800) = uVar8 | iVar7 << (uVar12 & 0x3f);
  }
  else {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar6 = 0x502;
LAB_0009acbc:
    *(undefined4 *)(param_1 + 0x7574) = uVar6;
  }
  return;
}

/* _glTexEnviv_CompExec @ 0x9acd4 (72 bytes) */
int _glTexEnviv_CompExec(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  ((int (*)())_glTexEnviv_Comp)(param_1,param_2,param_3,param_4);
  ((int (*)())_glTexEnviv_Exec)(param_1,param_2,param_3,param_4);
  return;
}

/* _glGetTexEnvfv_Exec @ 0x9ad1c (1248 bytes) */
void _glGetTexEnvfv_Exec(int param_1,int param_2,uint param_3,float *param_4,undefined4 param_5,undefined4 param_6,undefined4 param_7,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  ushort uVar1;
  undefined4 uVar2;
  float fVar3;
  int iVar4;
  uint uVar5;
  
  uVar5 = *(uint *)(param_1 + 0x53d4);
  if (-1 < *(short *)(param_1 + 0x4a10)) {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar2 = 0x502;
    goto LAB_0009af0c;
  }
  if (param_2 != 0x86de) {
    if (param_2 == 0x8861) {
      if (param_3 == 0x8862) {
        if ((*(uint *)(param_1 + 0x3444) & 1 << (uVar5 & 0x3f)) == 0) {
          fVar3 = 0.0;
          goto LAB_0009af54;
        }
        goto switchD_0009ad94_caseD_86dd;
      }
    }
    else if (param_2 == 0x2300) {
      if (param_3 == 0x8582) {
        uVar5 = (uint)*(ushort *)(uVar5 * 0x7c + param_1 + 0x3544);
        goto LAB_0009aec4;
      }
      if (param_3 < 0x8583) {
        if (param_3 == 0x8571) {
          uVar5 = (uint)*(ushort *)(uVar5 * 0x7c + param_1 + 0x353c);
          goto LAB_0009aec4;
        }
        if (param_3 < 0x8572) {
          if (param_3 == 0x2200) {
            uVar5 = (uint)*(ushort *)(uVar5 * 0x7c + param_1 + 0x3538);
            goto LAB_0009aec4;
          }
          if (param_3 < 0x2201) {
            if (param_3 == 0xd1c) {
              fVar3 = *(float *)(uVar5 * 0x7c + param_1 + 0x355c);
              goto LAB_0009aee8;
            }
          }
          else if (param_3 == 0x2201) {
            iVar4 = param_1 + uVar5 * 0x7c;
            *param_4 = *(float *)(iVar4 + 0x3524);
            param_4[1] = *(float *)(iVar4 + 0x3528);
            param_4[2] = *(float *)(iVar4 + 0x352c);
            param_4[3] = *(float *)(iVar4 + 0x3530);
            return;
          }
        }
        else {
          if (param_3 == 0x8573) {
            fVar3 = *(float *)(uVar5 * 0x7c + param_1 + 0x3558);
            goto LAB_0009aee8;
          }
          if (param_3 < 0x8573) {
            uVar5 = (uint)*(ushort *)(uVar5 * 0x7c + param_1 + 0x353e);
            goto LAB_0009aec4;
          }
          if (param_3 == 0x8580) {
            uVar5 = (uint)*(ushort *)(uVar5 * 0x7c + param_1 + 0x3540);
            goto LAB_0009aec4;
          }
          if (param_3 == 0x8581) {
            uVar5 = (uint)*(ushort *)(uVar5 * 0x7c + param_1 + 0x3542);
            goto LAB_0009aec4;
          }
        }
      }
      else {
        if (param_3 == 0x8591) {
          uVar5 = (uint)*(ushort *)(uVar5 * 0x7c + param_1 + 0x354e);
          goto LAB_0009aec4;
        }
        if (param_3 < 0x8592) {
          if (param_3 == 0x8589) {
            uVar5 = (uint)*(ushort *)(uVar5 * 0x7c + param_1 + 0x3548);
            goto LAB_0009aec4;
          }
          if (param_3 < 0x858a) {
            if (param_3 == 0x8588) {
              uVar5 = (uint)*(ushort *)(uVar5 * 0x7c + param_1 + 0x3546);
              goto LAB_0009aec4;
            }
          }
          else {
            if (param_3 == 0x858a) {
              uVar5 = (uint)*(ushort *)(uVar5 * 0x7c + param_1 + 0x354a);
              goto LAB_0009aec4;
            }
            if (param_3 == 0x8590) {
              uVar5 = (uint)*(ushort *)(uVar5 * 0x7c + param_1 + 0x354c);
              goto LAB_0009aec4;
            }
          }
        }
        else {
          if (param_3 == 0x8598) {
            uVar5 = (uint)*(ushort *)(uVar5 * 0x7c + param_1 + 0x3552);
            goto LAB_0009aec4;
          }
          if (param_3 < 0x8599) {
            if (param_3 == 0x8592) {
              uVar5 = (uint)*(ushort *)(uVar5 * 0x7c + param_1 + 0x3550);
              goto LAB_0009aec4;
            }
          }
          else {
            if (param_3 == 0x8599) {
              uVar5 = (uint)*(ushort *)(uVar5 * 0x7c + param_1 + 0x3554);
              goto LAB_0009aec4;
            }
            if (param_3 == 0x859a) {
              uVar5 = (uint)*(ushort *)(uVar5 * 0x7c + param_1 + 0x3556);
              goto LAB_0009aec4;
            }
          }
        }
      }
    }
    else if ((param_2 == 0x8500) && (param_3 == 0x8501)) {
      fVar3 = *(float *)(uVar5 * 0x7c + param_1 + 0x3560);
      goto LAB_0009aee8;
    }
switchD_0009ad94_caseD_86da:
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar2 = 0x500;
LAB_0009af0c:
    *(undefined4 *)(param_1 + 0x7574) = uVar2;
    return;
  }
  iVar4 = param_1 + uVar5 * 0x7c;
  switch(param_3) {
  case 0x86d9:
    fVar3 = *param_4;
    *(short *)(iVar4 + 0x356c) = (short)(int)fVar3;
    uVar5 = (int)fVar3 & 0xffff;
    goto LAB_0009aec4;
  default:
    goto switchD_0009ad94_caseD_86da;
  case 0x86dd:
switchD_0009ad94_caseD_86dd:
    fVar3 = 1.0;
LAB_0009af54:
    *param_4 = fVar3;
    return;
  case 0x86df:
    uVar1 = *(ushort *)(iVar4 + 0x3564);
    break;
  case 0x86e0:
    *param_4 = GH_U2F((unsigned int)((*(ushort *)(iVar4 + 0x3570) | 0x4b000000))) - 8388608.0;
    param_4[1] = GH_U2F((unsigned int)((*(ushort *)(iVar4 + 0x3572) | 0x4b000000))) - 8388608.0;
    param_4[2] = GH_U2F((unsigned int)((*(ushort *)(iVar4 + 0x3574) | 0x4b000000))) - 8388608.0;
    fVar3 = GH_U2F((unsigned int)((*(ushort *)(iVar4 + 0x3576) | 0x4b000000))) - 8388608.0;
    goto LAB_0009ae78;
  case 0x86e1:
    *param_4 = *(float *)(iVar4 + 0x3588);
    param_4[1] = *(float *)(iVar4 + 0x358c);
    param_4[2] = *(float *)(iVar4 + 0x3590);
    fVar3 = *(float *)(iVar4 + 0x3594);
LAB_0009ae78:
    param_4[3] = fVar3;
    return;
  case 0x86e2:
    fVar3 = *(float *)(iVar4 + 0x3598);
    goto LAB_0009aee8;
  case 0x86e3:
    fVar3 = *(float *)(iVar4 + 0x359c);
LAB_0009aee8:
    *param_4 = fVar3;
    return;
  case 0x86e4:
    uVar1 = *(ushort *)(iVar4 + 0x356a);
    break;
  case 0x86e5:
    *param_4 = *(float *)(iVar4 + 0x357c);
    param_4[1] = *(float *)(iVar4 + 0x3580);
    param_4[2] = *(float *)(iVar4 + 0x3584);
    return;
  }
  uVar5 = (uint)uVar1;
LAB_0009aec4:
  *param_4 = GH_U2F((unsigned int)((uVar5 | 0x4b000000))) - 8388608.0;
  return;
}

/* _glGetTexEnviv_Exec @ 0x9b230 (1232 bytes) */
int _glGetTexEnviv_Exec(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  uint param_3;
  uint *param_4;
{
  float fVar1;
  float fVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  
  fVar2 = FLOAT_00108e94;
  fVar1 = FLOAT_00108e90;
  uVar6 = *(uint *)(param_1 + 0x53d4);
  if (-1 < *(short *)(param_1 + 0x4a10)) {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar3 = 0x502;
    goto LAB_0009b3d0;
  }
  if (param_2 != 0x86de) {
    if (param_2 == 0x8861) {
      if (param_3 == 0x8862) {
        uVar4 = 0;
        if ((*(uint *)(param_1 + 0x3444) & 1 << (uVar6 & 0x3f)) != 0) {
          *param_4 = 1;
          return;
        }
        goto LAB_0009b398;
      }
    }
    else if (param_2 == 0x2300) {
      if (param_3 == 0x8582) {
        uVar4 = (uint)*(ushort *)(uVar6 * 0x7c + param_1 + 0x3544);
        goto LAB_0009b398;
      }
      if (param_3 < 0x8583) {
        if (param_3 == 0x8571) {
          uVar4 = (uint)*(ushort *)(uVar6 * 0x7c + param_1 + 0x353c);
          goto LAB_0009b398;
        }
        if (param_3 < 0x8572) {
          if (param_3 == 0x2200) {
            uVar4 = (uint)*(ushort *)(uVar6 * 0x7c + param_1 + 0x3538);
            goto LAB_0009b398;
          }
          if (param_3 < 0x2201) {
            if (param_3 == 0xd1c) {
              fVar1 = *(float *)(uVar6 * 0x7c + param_1 + 0x355c);
              goto LAB_0009b724;
            }
          }
          else if (param_3 == 0x2201) {
            iVar5 = param_1 + uVar6 * 0x7c;
            *param_4 = (int)(*(float *)(iVar5 + 0x3524) * FLOAT_00108e94 - FLOAT_00108e90);
            param_4[1] = (int)(*(float *)(iVar5 + 0x3528) * fVar2 - fVar1);
            param_4[2] = (int)(*(float *)(iVar5 + 0x352c) * fVar2 - fVar1);
            fVar1 = *(float *)(iVar5 + 0x3530) * fVar2 - fVar1;
            goto LAB_0009b5e4;
          }
        }
        else {
          if (param_3 == 0x8573) {
            fVar1 = *(float *)(uVar6 * 0x7c + param_1 + 0x3558);
            goto LAB_0009b724;
          }
          if (param_3 < 0x8573) {
            uVar4 = (uint)*(ushort *)(uVar6 * 0x7c + param_1 + 0x353e);
            goto LAB_0009b398;
          }
          if (param_3 == 0x8580) {
            uVar4 = (uint)*(ushort *)(uVar6 * 0x7c + param_1 + 0x3540);
            goto LAB_0009b398;
          }
          if (param_3 == 0x8581) {
            uVar4 = (uint)*(ushort *)(uVar6 * 0x7c + param_1 + 0x3542);
            goto LAB_0009b398;
          }
        }
      }
      else {
        if (param_3 == 0x8591) {
          uVar4 = (uint)*(ushort *)(uVar6 * 0x7c + param_1 + 0x354e);
          goto LAB_0009b398;
        }
        if (param_3 < 0x8592) {
          if (param_3 == 0x8589) {
            uVar4 = (uint)*(ushort *)(uVar6 * 0x7c + param_1 + 0x3548);
            goto LAB_0009b398;
          }
          if (param_3 < 0x858a) {
            if (param_3 == 0x8588) {
              uVar4 = (uint)*(ushort *)(uVar6 * 0x7c + param_1 + 0x3546);
              goto LAB_0009b398;
            }
          }
          else {
            if (param_3 == 0x858a) {
              uVar4 = (uint)*(ushort *)(uVar6 * 0x7c + param_1 + 0x354a);
              goto LAB_0009b398;
            }
            if (param_3 == 0x8590) {
              uVar4 = (uint)*(ushort *)(uVar6 * 0x7c + param_1 + 0x354c);
              goto LAB_0009b398;
            }
          }
        }
        else {
          if (param_3 == 0x8598) {
            uVar4 = (uint)*(ushort *)(uVar6 * 0x7c + param_1 + 0x3552);
            goto LAB_0009b398;
          }
          if (param_3 < 0x8599) {
            if (param_3 == 0x8592) {
              uVar4 = (uint)*(ushort *)(uVar6 * 0x7c + param_1 + 0x3550);
              goto LAB_0009b398;
            }
          }
          else {
            if (param_3 == 0x8599) {
              uVar4 = (uint)*(ushort *)(uVar6 * 0x7c + param_1 + 0x3554);
              goto LAB_0009b398;
            }
            if (param_3 == 0x859a) {
              uVar4 = (uint)*(ushort *)(uVar6 * 0x7c + param_1 + 0x3556);
              goto LAB_0009b398;
            }
          }
        }
      }
    }
    else if ((param_2 == 0x8500) && (param_3 == 0x8501)) {
      fVar1 = *(float *)(uVar6 * 0x7c + param_1 + 0x3560);
      goto LAB_0009b724;
    }
switchD_0009b2a8_caseD_86da:
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar3 = 0x500;
LAB_0009b3d0:
    *(undefined4 *)(param_1 + 0x7574) = uVar3;
    return;
  }
  iVar5 = param_1 + uVar6 * 0x7c;
  switch(param_3) {
  case 0x86d9:
    uVar4 = (uint)(ushort)*param_4;
    *(ushort *)(iVar5 + 0x356c) = (ushort)*param_4;
    break;
  default:
    goto switchD_0009b2a8_caseD_86da;
  case 0x86dd:
    uVar4 = 1;
    break;
  case 0x86df:
    uVar4 = (uint)*(ushort *)(iVar5 + 0x3564);
    break;
  case 0x86e0:
    *param_4 = (uint)*(ushort *)(iVar5 + 0x3570);
    param_4[1] = (uint)*(ushort *)(iVar5 + 0x3572);
    param_4[2] = (uint)*(ushort *)(iVar5 + 0x3574);
    param_4[3] = (uint)*(ushort *)(iVar5 + 0x3576);
    return;
  case 0x86e1:
    *param_4 = (int)*(float *)(iVar5 + 0x3588);
    param_4[1] = (int)*(float *)(iVar5 + 0x358c);
    param_4[2] = (int)*(float *)(iVar5 + 0x3590);
    fVar1 = *(float *)(iVar5 + 0x3594);
LAB_0009b5e4:
    param_4[3] = (int)fVar1;
    return;
  case 0x86e2:
    fVar1 = *(float *)(iVar5 + 0x3598);
    goto LAB_0009b724;
  case 0x86e3:
    fVar1 = *(float *)(iVar5 + 0x359c);
LAB_0009b724:
    uVar4 = (uint)(int)fVar1;
    break;
  case 0x86e4:
    uVar4 = (uint)*(ushort *)(iVar5 + 0x356a);
    break;
  case 0x86e5:
    *param_4 = (int)*(float *)(iVar5 + 0x357c);
    param_4[1] = (int)*(float *)(iVar5 + 0x3580);
    param_4[2] = (int)*(float *)(iVar5 + 0x3584);
    return;
  }
LAB_0009b398:
  *param_4 = uVar4;
  return;
}

/* _glTexGen_ListExec @ 0x9b734 (64 bytes) */
int _glTexGen_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  ((void (*)())_glTexGen_Exec)(param_1,*param_2,param_2[1],(double)GH_U2F((unsigned int)(param_2[2])),(double)GH_U2F((unsigned int)(param_2[3])),
                 (double)GH_U2F((unsigned int)(param_2[4])),(double)GH_U2F((unsigned int)(param_2[5])));
  return 0x18;
}

/* _glTexGen_Comp @ 0x9b774 (144 bytes) */
double _glTexGen_Comp(undefined4 param_1,undefined4 param_2,uint param_3,double fparam_1,double fparam_2,double fparam_3,double fparam_4)
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glTexGen_ListExec_001103e0,0x18);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_2;
    puVar1[1] = param_3;
    if (param_3 == 0x2500) {
      puVar1[2] = (float)fparam_1;
    }
    else if ((0x24ff < param_3) && (param_3 < 0x2503)) {
      puVar1[5] = (float)fparam_4;
      puVar1[2] = (float)fparam_1;
      puVar1[3] = (float)fparam_2;
      puVar1[4] = (float)fparam_3;
    }
  }
  FUN_00008b68();
  return;
}

/* _glTexGen_Exec @ 0x9b804 (2380 bytes) */
void _glTexGen_Exec(int param_1,uint param_2,uint param_3,double fparam_1,double fparam_2,double fparam_3,double fparam_4)
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
  
  uVar10 = *(uint *)(param_1 + 0x53d4);
  if ((-1 < *(short *)(param_1 + 0x4a10)) || (7 < uVar10)) {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar6 = 0x502;
    goto LAB_0009c0ec;
  }
  if (param_2 == 0x2001) {
    if (param_3 != 0x2501) {
      if (param_3 < 0x2502) {
        if (((param_3 == 0x2500) && (iVar7 = (int)fparam_1, 0x23ff < iVar7)) &&
           ((iVar7 < 0x2403 || (iVar7 - 0x8511U < 2)))) {
          *(short *)(uVar10 * 0x94 + param_1 + 0x3d0c) = (short)iVar7;
          goto LAB_0009c10c;
        }
      }
      else if (param_3 == 0x2502) {
        iVar7 = uVar10 * 0x94 + param_1;
        *(float *)(iVar7 + 0x3d10) = (float)fparam_1;
        *(float *)(iVar7 + 0x3d14) = (float)fparam_2;
        *(float *)(iVar7 + 0x3d18) = (float)fparam_3;
        *(float *)(iVar7 + 0x3d1c) = (float)fparam_4;
        if ((*(uint *)(param_1 + 0x50b0) & 0x10) != 0) {
          ((double (*)())_gleModelMatInvert)(param_1);
        }
        fVar2 = *(float *)(iVar7 + 0x3d14);
        fVar3 = *(float *)(iVar7 + 0x3d10);
        fVar4 = *(float *)(iVar7 + 0x3d18);
        fVar5 = *(float *)(iVar7 + 0x3d1c);
        *(float *)(iVar7 + 0x3d10) =
             fVar5 * *(float *)(param_1 + 0x22f0) +
             (fVar4 * *(float *)(param_1 + 0x22e0) +
             (fVar3 * *(float *)(param_1 + 0x22c0) + fVar2 * *(float *)(param_1 + 0x22d0)));
        *(float *)(iVar7 + 0x3d14) =
             fVar5 * *(float *)(param_1 + 0x22f4) +
             (fVar4 * *(float *)(param_1 + 0x22e4) +
             (fVar3 * *(float *)(param_1 + 0x22c4) + fVar2 * *(float *)(param_1 + 0x22d4)));
        *(float *)(iVar7 + 0x3d18) =
             fVar5 * *(float *)(param_1 + 0x22f8) +
             (fVar4 * *(float *)(param_1 + 0x22e8) +
             (fVar3 * *(float *)(param_1 + 0x22c8) + fVar2 * *(float *)(param_1 + 0x22d8)));
        *(float *)(iVar7 + 0x3d1c) =
             fVar5 * *(float *)(param_1 + 0x22fc) +
             (fVar4 * *(float *)(param_1 + 0x22ec) +
             (fVar3 * *(float *)(param_1 + 0x22cc) + fVar2 * *(float *)(param_1 + 0x22dc)));
        if (*(int *)(param_1 + 0x5434) == 0) {
          bVar1 = *(byte *)(uVar10 * 4 + *(int *)(param_1 + 0x5420) + 0x2cd);
        }
        else {
          bVar1 = *(byte *)(uVar10 * 4 + *(int *)(*(int *)(param_1 + 0x5430) + 0x20) + 0x301);
        }
        iVar9 = (bVar1 >> 3 & 0x1c) + param_1;
        iVar7 = *(int *)(param_1 + 0x5424);
        *(uint *)(iVar9 + 0x324) = *(uint *)(iVar9 + 0x324) | 1 << (bVar1 & 0x1f);
        uVar8 = (uint)*(byte *)(uVar10 * 4 + iVar7 + 0x2cd);
        goto LAB_0009c0b8;
      }
LAB_0009c0dc:
      if (*(int *)(param_1 + 0x7574) != 0) {
        return;
      }
      uVar6 = 0x500;
LAB_0009c0ec:
      *(undefined4 *)(param_1 + 0x7574) = uVar6;
      return;
    }
    iVar7 = uVar10 * 0x94 + param_1;
    *(float *)(iVar7 + 0x3d2c) = (float)fparam_4;
    *(float *)(iVar7 + 0x3d20) = (float)fparam_1;
    *(float *)(iVar7 + 0x3d24) = (float)fparam_2;
    *(float *)(iVar7 + 0x3d28) = (float)fparam_3;
    if (*(int *)(param_1 + 0x5434) == 0) {
      bVar1 = *(byte *)(uVar10 * 4 + *(int *)(param_1 + 0x5420) + 0x2ed);
    }
    else {
      bVar1 = *(byte *)(uVar10 * 4 + *(int *)(*(int *)(param_1 + 0x5430) + 0x20) + 0x321);
    }
    iVar9 = (bVar1 >> 3 & 0x1c) + param_1;
    iVar7 = *(int *)(param_1 + 0x5424);
    *(uint *)(iVar9 + 0x324) = *(uint *)(iVar9 + 0x324) | 1 << (bVar1 & 0x1f);
    uVar8 = (uint)*(byte *)(uVar10 * 4 + iVar7 + 0x2ed);
  }
  else if (param_2 < 0x2002) {
    if (param_2 != 0x2000) {
LAB_0009c0f4:
      if (*(int *)(param_1 + 0x7574) == 0) {
        *(undefined4 *)(param_1 + 0x7574) = 0x500;
      }
      goto LAB_0009c10c;
    }
    if (param_3 != 0x2501) {
      if (param_3 < 0x2502) {
        if (((param_3 == 0x2500) && (iVar7 = (int)fparam_1, 0x23ff < iVar7)) &&
           ((iVar7 < 0x2403 || (iVar7 - 0x8511U < 2)))) {
          *(short *)(uVar10 * 0x94 + param_1 + 0x3ce8) = (short)iVar7;
          goto LAB_0009c10c;
        }
      }
      else if (param_3 == 0x2502) {
        iVar7 = uVar10 * 0x94 + param_1;
        *(float *)(iVar7 + 0x3cec) = (float)fparam_1;
        *(float *)(iVar7 + 0x3cf0) = (float)fparam_2;
        *(float *)(iVar7 + 0x3cf4) = (float)fparam_3;
        *(float *)(iVar7 + 0x3cf8) = (float)fparam_4;
        if ((*(uint *)(param_1 + 0x50b0) & 0x10) != 0) {
          ((double (*)())_gleModelMatInvert)(param_1);
        }
        fVar2 = *(float *)(iVar7 + 0x3cf0);
        fVar3 = *(float *)(iVar7 + 0x3cec);
        fVar4 = *(float *)(iVar7 + 0x3cf4);
        fVar5 = *(float *)(iVar7 + 0x3cf8);
        *(float *)(iVar7 + 0x3cec) =
             fVar5 * *(float *)(param_1 + 0x22f0) +
             (fVar4 * *(float *)(param_1 + 0x22e0) +
             (fVar3 * *(float *)(param_1 + 0x22c0) + fVar2 * *(float *)(param_1 + 0x22d0)));
        *(float *)(iVar7 + 0x3cf0) =
             fVar5 * *(float *)(param_1 + 0x22f4) +
             (fVar4 * *(float *)(param_1 + 0x22e4) +
             (fVar3 * *(float *)(param_1 + 0x22c4) + fVar2 * *(float *)(param_1 + 0x22d4)));
        *(float *)(iVar7 + 0x3cf4) =
             fVar5 * *(float *)(param_1 + 0x22f8) +
             (fVar4 * *(float *)(param_1 + 0x22e8) +
             (fVar3 * *(float *)(param_1 + 0x22c8) + fVar2 * *(float *)(param_1 + 0x22d8)));
        *(float *)(iVar7 + 0x3cf8) =
             fVar5 * *(float *)(param_1 + 0x22fc) +
             (fVar4 * *(float *)(param_1 + 0x22ec) +
             (fVar3 * *(float *)(param_1 + 0x22cc) + fVar2 * *(float *)(param_1 + 0x22dc)));
        if (*(int *)(param_1 + 0x5434) == 0) {
          bVar1 = *(byte *)(uVar10 * 4 + *(int *)(param_1 + 0x5420) + 0x2cc);
        }
        else {
          bVar1 = *(byte *)(uVar10 * 4 + *(int *)(*(int *)(param_1 + 0x5430) + 0x20) + 0x300);
        }
        iVar9 = (bVar1 >> 3 & 0x1c) + param_1;
        iVar7 = *(int *)(param_1 + 0x5424);
        *(uint *)(iVar9 + 0x324) = *(uint *)(iVar9 + 0x324) | 1 << (bVar1 & 0x1f);
        uVar8 = (uint)*(byte *)(uVar10 * 4 + iVar7 + 0x2cc);
        goto LAB_0009c0b8;
      }
      goto LAB_0009c0dc;
    }
    iVar7 = uVar10 * 0x94 + param_1;
    *(float *)(iVar7 + 0x3d08) = (float)fparam_4;
    *(float *)(iVar7 + 0x3cfc) = (float)fparam_1;
    *(float *)(iVar7 + 0x3d00) = (float)fparam_2;
    *(float *)(iVar7 + 0x3d04) = (float)fparam_3;
    if (*(int *)(param_1 + 0x5434) == 0) {
      bVar1 = *(byte *)(uVar10 * 4 + *(int *)(param_1 + 0x5420) + 0x2ec);
    }
    else {
      bVar1 = *(byte *)(uVar10 * 4 + *(int *)(*(int *)(param_1 + 0x5430) + 0x20) + 800);
    }
    iVar9 = (bVar1 >> 3 & 0x1c) + param_1;
    iVar7 = *(int *)(param_1 + 0x5424);
    *(uint *)(iVar9 + 0x324) = *(uint *)(iVar9 + 0x324) | 1 << (bVar1 & 0x1f);
    uVar8 = (uint)*(byte *)(uVar10 * 4 + iVar7 + 0x2ec);
  }
  else if (param_2 == 0x2002) {
    if (param_3 != 0x2501) {
      if (param_3 < 0x2502) {
        if (((param_3 == 0x2500) && (iVar7 = (int)fparam_1, 0x23ff < iVar7)) &&
           ((iVar7 < 0x2402 || (iVar7 - 0x8511U < 2)))) {
          *(short *)(uVar10 * 0x94 + param_1 + 0x3d30) = (short)iVar7;
          goto LAB_0009c10c;
        }
      }
      else if (param_3 == 0x2502) {
        iVar7 = uVar10 * 0x94 + param_1;
        *(float *)(iVar7 + 0x3d34) = (float)fparam_1;
        *(float *)(iVar7 + 0x3d38) = (float)fparam_2;
        *(float *)(iVar7 + 0x3d3c) = (float)fparam_3;
        *(float *)(iVar7 + 0x3d40) = (float)fparam_4;
        if ((*(uint *)(param_1 + 0x50b0) & 0x10) != 0) {
          ((double (*)())_gleModelMatInvert)(param_1);
        }
        fVar2 = *(float *)(iVar7 + 0x3d38);
        fVar3 = *(float *)(iVar7 + 0x3d34);
        fVar4 = *(float *)(iVar7 + 0x3d3c);
        fVar5 = *(float *)(iVar7 + 0x3d40);
        *(float *)(iVar7 + 0x3d34) =
             fVar5 * *(float *)(param_1 + 0x22f0) +
             (fVar4 * *(float *)(param_1 + 0x22e0) +
             (fVar3 * *(float *)(param_1 + 0x22c0) + fVar2 * *(float *)(param_1 + 0x22d0)));
        *(float *)(iVar7 + 0x3d38) =
             fVar5 * *(float *)(param_1 + 0x22f4) +
             (fVar4 * *(float *)(param_1 + 0x22e4) +
             (fVar3 * *(float *)(param_1 + 0x22c4) + fVar2 * *(float *)(param_1 + 0x22d4)));
        *(float *)(iVar7 + 0x3d3c) =
             fVar5 * *(float *)(param_1 + 0x22f8) +
             (fVar4 * *(float *)(param_1 + 0x22e8) +
             (fVar3 * *(float *)(param_1 + 0x22c8) + fVar2 * *(float *)(param_1 + 0x22d8)));
        *(float *)(iVar7 + 0x3d40) =
             fVar5 * *(float *)(param_1 + 0x22fc) +
             (fVar4 * *(float *)(param_1 + 0x22ec) +
             (fVar3 * *(float *)(param_1 + 0x22cc) + fVar2 * *(float *)(param_1 + 0x22dc)));
        if (*(int *)(param_1 + 0x5434) == 0) {
          bVar1 = *(byte *)(uVar10 * 4 + *(int *)(param_1 + 0x5420) + 0x2ce);
        }
        else {
          bVar1 = *(byte *)(uVar10 * 4 + *(int *)(*(int *)(param_1 + 0x5430) + 0x20) + 0x302);
        }
        iVar9 = (bVar1 >> 3 & 0x1c) + param_1;
        iVar7 = *(int *)(param_1 + 0x5424);
        *(uint *)(iVar9 + 0x324) = *(uint *)(iVar9 + 0x324) | 1 << (bVar1 & 0x1f);
        uVar8 = (uint)*(byte *)(uVar10 * 4 + iVar7 + 0x2ce);
        goto LAB_0009c0b8;
      }
      goto LAB_0009c0dc;
    }
    iVar7 = uVar10 * 0x94 + param_1;
    *(float *)(iVar7 + 0x3d50) = (float)fparam_4;
    *(float *)(iVar7 + 0x3d44) = (float)fparam_1;
    *(float *)(iVar7 + 0x3d48) = (float)fparam_2;
    *(float *)(iVar7 + 0x3d4c) = (float)fparam_3;
    if (*(int *)(param_1 + 0x5434) == 0) {
      bVar1 = *(byte *)(uVar10 * 4 + *(int *)(param_1 + 0x5420) + 0x2ee);
    }
    else {
      bVar1 = *(byte *)(uVar10 * 4 + *(int *)(*(int *)(param_1 + 0x5430) + 0x20) + 0x322);
    }
    iVar9 = (bVar1 >> 3 & 0x1c) + param_1;
    iVar7 = *(int *)(param_1 + 0x5424);
    *(uint *)(iVar9 + 0x324) = *(uint *)(iVar9 + 0x324) | 1 << (bVar1 & 0x1f);
    uVar8 = (uint)*(byte *)(uVar10 * 4 + iVar7 + 0x2ee);
  }
  else {
    if (param_2 != 0x2003) goto LAB_0009c0f4;
    if (param_3 != 0x2501) {
      if (param_3 < 0x2502) {
        if ((param_3 == 0x2500) && ((int)fparam_1 - 0x2400U < 2)) {
          *(short *)(uVar10 * 0x94 + param_1 + 0x3d54) = (short)(int)fparam_1;
          goto LAB_0009c10c;
        }
      }
      else if (param_3 == 0x2502) {
        iVar7 = uVar10 * 0x94 + param_1;
        *(float *)(iVar7 + 0x3d58) = (float)fparam_1;
        *(float *)(iVar7 + 0x3d5c) = (float)fparam_2;
        *(float *)(iVar7 + 0x3d60) = (float)fparam_3;
        *(float *)(iVar7 + 0x3d64) = (float)fparam_4;
        if ((*(uint *)(param_1 + 0x50b0) & 0x10) != 0) {
          ((double (*)())_gleModelMatInvert)(param_1);
        }
        fVar2 = *(float *)(iVar7 + 0x3d5c);
        fVar3 = *(float *)(iVar7 + 0x3d58);
        fVar4 = *(float *)(iVar7 + 0x3d60);
        fVar5 = *(float *)(iVar7 + 0x3d64);
        *(float *)(iVar7 + 0x3d58) =
             fVar5 * *(float *)(param_1 + 0x22f0) +
             (fVar4 * *(float *)(param_1 + 0x22e0) +
             (fVar3 * *(float *)(param_1 + 0x22c0) + fVar2 * *(float *)(param_1 + 0x22d0)));
        *(float *)(iVar7 + 0x3d5c) =
             fVar5 * *(float *)(param_1 + 0x22f4) +
             (fVar4 * *(float *)(param_1 + 0x22e4) +
             (fVar3 * *(float *)(param_1 + 0x22c4) + fVar2 * *(float *)(param_1 + 0x22d4)));
        *(float *)(iVar7 + 0x3d60) =
             fVar5 * *(float *)(param_1 + 0x22f8) +
             (fVar4 * *(float *)(param_1 + 0x22e8) +
             (fVar3 * *(float *)(param_1 + 0x22c8) + fVar2 * *(float *)(param_1 + 0x22d8)));
        *(float *)(iVar7 + 0x3d64) =
             fVar5 * *(float *)(param_1 + 0x22fc) +
             (fVar4 * *(float *)(param_1 + 0x22ec) +
             (fVar3 * *(float *)(param_1 + 0x22cc) + fVar2 * *(float *)(param_1 + 0x22dc)));
        if (*(int *)(param_1 + 0x5434) == 0) {
          bVar1 = *(byte *)(uVar10 * 4 + *(int *)(param_1 + 0x5420) + 0x2cf);
        }
        else {
          bVar1 = *(byte *)(uVar10 * 4 + *(int *)(*(int *)(param_1 + 0x5430) + 0x20) + 0x303);
        }
        iVar9 = (bVar1 >> 3 & 0x1c) + param_1;
        iVar7 = *(int *)(param_1 + 0x5424);
        *(uint *)(iVar9 + 0x324) = *(uint *)(iVar9 + 0x324) | 1 << (bVar1 & 0x1f);
        uVar8 = (uint)*(byte *)(uVar10 * 4 + iVar7 + 0x2cf);
        goto LAB_0009c0b8;
      }
      goto LAB_0009c0dc;
    }
    iVar7 = uVar10 * 0x94 + param_1;
    *(float *)(iVar7 + 0x3d74) = (float)fparam_4;
    *(float *)(iVar7 + 0x3d68) = (float)fparam_1;
    *(float *)(iVar7 + 0x3d6c) = (float)fparam_2;
    *(float *)(iVar7 + 0x3d70) = (float)fparam_3;
    if (*(int *)(param_1 + 0x5434) == 0) {
      bVar1 = *(byte *)(uVar10 * 4 + *(int *)(param_1 + 0x5420) + 0x2ef);
    }
    else {
      bVar1 = *(byte *)(uVar10 * 4 + *(int *)(*(int *)(param_1 + 0x5430) + 0x20) + 0x323);
    }
    iVar9 = (bVar1 >> 3 & 0x1c) + param_1;
    iVar7 = *(int *)(param_1 + 0x5424);
    *(uint *)(iVar9 + 0x324) = *(uint *)(iVar9 + 0x324) | 1 << (bVar1 & 0x1f);
    uVar8 = (uint)*(byte *)(uVar10 * 4 + iVar7 + 0x2ef);
  }
LAB_0009c0b8:
  iVar7 = (uVar8 >> 3 & 0x1c) + param_1;
  *(uint *)(iVar7 + 0x348) = *(uint *)(iVar7 + 0x348) | 1 << (uVar8 & 0x1f);
LAB_0009c10c:
  _gleUpdateTextureCoordGen(param_1);
  if (param_3 == 0x2500) {
    _gleSelectVertexSubmitFunc(param_1);
  }
  *(uint *)(param_1 + 0x314) = *(uint *)(param_1 + 0x314) | 0x10000 << (uVar10 & 0x3f);
  return;
}

/* _glTexGend_Comp @ 0x9c150 (40 bytes) */
void _glTexGend_Comp(undefined4 param_1,undefined4 param_2,undefined4 param_3,double fparam_1)
{
  double fparam_2;
  
  fparam_2 = (double)FLOAT_00108e50;
  ((double (*)())_glTexGen_Comp)(param_1,param_2,param_3,(double)(float)fparam_1,fparam_2,fparam_2,fparam_2);
  return;
}

/* _glTexGend_Exec @ 0x9c178 (40 bytes) */
void _glTexGend_Exec(undefined4 param_1,undefined4 param_2,undefined4 param_3,double fparam_1)
{
  double fparam_2;
  
  fparam_2 = (double)FLOAT_00108e50;
  ((void (*)())_glTexGen_Exec)(param_1,param_2,param_3,(double)(float)fparam_1,fparam_2,fparam_2,fparam_2);
  return;
}

/* _glTexGend_CompExec @ 0x9c1a0 (80 bytes) */
void _glTexGend_CompExec(undefined4 param_1,undefined4 param_2,undefined4 param_3,double fparam_1)
{
  ((void (*)())_glTexGend_Comp)(param_1,param_2,param_3,fparam_1);
  ((void (*)())_glTexGend_Exec)(param_1,param_2,param_3,fparam_1);
  return;
}

/* _glTexGendv_Comp @ 0x9c1f0 (36 bytes) */
int _glTexGendv_Comp(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  double *param_4;
{
  ((double (*)())_glTexGen_Comp)(param_1,param_2,param_3,(double)GH_U2F((unsigned int)(*param_4)),(double)GH_U2F((unsigned int)(param_4[1])),
                 (double)GH_U2F((unsigned int)(param_4[2])),(double)GH_U2F((unsigned int)(param_4[3])));
  return;
}

/* _glTexGendv_CompExec @ 0x9c238 (108 bytes) */
int _glTexGendv_CompExec(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  double *param_4;
{
  ((int (*)())_glTexGendv_Comp)(param_1,param_2,param_3,param_4);
  ((void (*)())_glTexGen_Exec)(param_1,param_2,param_3,(double)GH_U2F((unsigned int)(*param_4)),(double)GH_U2F((unsigned int)(param_4[1])),
                 (double)GH_U2F((unsigned int)(param_4[2])),(double)GH_U2F((unsigned int)(param_4[3])));
  return;
}

/* _glTexGenf_Comp @ 0x9c280 (36 bytes) */
void _glTexGenf_Comp(undefined4 param_1,undefined4 param_2,undefined4 param_3,double fparam_1)
{
  double fparam_2;
  
  fparam_2 = (double)FLOAT_00108e50;
  ((double (*)())_glTexGen_Comp)(param_1,param_2,param_3,fparam_1,fparam_2,fparam_2,fparam_2);
  return;
}

/* _glTexGenf_Exec @ 0x9c2a4 (36 bytes) */
void _glTexGenf_Exec(undefined4 param_1,undefined4 param_2,undefined4 param_3,double fparam_1)
{
  double fparam_2;
  
  fparam_2 = (double)FLOAT_00108e50;
  ((void (*)())_glTexGen_Exec)(param_1,param_2,param_3,fparam_1,fparam_2,fparam_2,fparam_2);
  return;
}

/* _glTexGenf_CompExec @ 0x9c2c8 (80 bytes) */
void _glTexGenf_CompExec(undefined4 param_1,undefined4 param_2,undefined4 param_3,double fparam_1)
{
  ((void (*)())_glTexGenf_Comp)(param_1,param_2,param_3,fparam_1);
  ((void (*)())_glTexGenf_Exec)(param_1,param_2,param_3,fparam_1);
  return;
}

/* _glTexGenfv_Comp @ 0x9c318 (20 bytes) */
int _glTexGenfv_Comp(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  float *param_4;
{
  ((double (*)())_glTexGen_Comp)(param_1,param_2,param_3,(double)*param_4,(double)param_4[1],(double)param_4[2],
                 (double)param_4[3]);
  return;
}

/* _glTexGenfv_CompExec @ 0x9c340 (92 bytes) */
int _glTexGenfv_CompExec(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  float *param_4;
{
  ((int (*)())_glTexGenfv_Comp)(param_1,param_2,param_3,param_4);
  ((void (*)())_glTexGen_Exec)(param_1,param_2,param_3,(double)*param_4,(double)param_4[1],(double)param_4[2],
                 (double)param_4[3]);
  return;
}

/* _glTexGeni_Comp @ 0x9c388 (100 bytes) */
double _glTexGeni_Comp(undefined4 param_1,undefined4 param_2,undefined4 param_3,uint param_4)
{
  double dVar1;
  
  dVar1 = (double)FLOAT_00108e50;
  dVar1 = (double)((double (*)())_glTexGen_Comp)(param_1,param_2,param_3,
                                 (double)(float)((double)CONCAT44(0x43300000,param_4 ^ 0x80000000) -
                                                DOUBLE_00108d58),dVar1,dVar1,dVar1);
  return dVar1;
}

/* _glTexGeni_Exec @ 0x9c3ec (100 bytes) */
int _glTexGeni_Exec(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  uint param_4;
{
  double fparam_2;
  
  fparam_2 = (double)FLOAT_00108e50;
  ((void (*)())_glTexGen_Exec)(param_1,param_2,param_3,
                 (double)(float)((double)CONCAT44(0x43300000,param_4 ^ 0x80000000) - DOUBLE_00108d58
                                ),fparam_2,fparam_2,fparam_2);
  return;
}

/* _glTexGeni_CompExec @ 0x9c450 (72 bytes) */
int _glTexGeni_CompExec(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  ((double (*)())_glTexGeni_Comp)(param_1,param_2,param_3,param_4);
  ((int (*)())_glTexGeni_Exec)(param_1,param_2,param_3,param_4);
  return;
}

/* _glTexGeniv_Comp @ 0x9c498 (160 bytes) */
double _glTexGeniv_Comp(undefined4 param_1,undefined4 param_2,undefined4 param_3,uint *param_4)
{
  double dVar1;
  
  dVar1 = (double)((double (*)())_glTexGen_Comp)(param_1,param_2,param_3,
                                 (double)(float)((double)CONCAT44(0x43300000,*param_4 ^ 0x80000000)
                                                - DOUBLE_00108d58),
                                 (double)(float)((double)CONCAT44(0x43300000,param_4[1] ^ 0x80000000
                                                                 ) - DOUBLE_00108d58),
                                 (double)(float)((double)CONCAT44(0x43300000,param_4[2] ^ 0x80000000
                                                                 ) - DOUBLE_00108d58),
                                 (double)(float)((double)CONCAT44(0x43300000,param_4[3] ^ 0x80000000
                                                                 ) - DOUBLE_00108d58));
  return dVar1;
}

/* _glTexGeniv_Exec @ 0x9c538 (160 bytes) */
int _glTexGeniv_Exec(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  uint *param_4;
{
  ((void (*)())_glTexGen_Exec)(param_1,param_2,param_3,
                 (double)(float)((double)CONCAT44(0x43300000,*param_4 ^ 0x80000000) -
                                DOUBLE_00108d58),
                 (double)(float)((double)CONCAT44(0x43300000,param_4[1] ^ 0x80000000) -
                                DOUBLE_00108d58),
                 (double)(float)((double)CONCAT44(0x43300000,param_4[2] ^ 0x80000000) -
                                DOUBLE_00108d58),
                 (double)(float)((double)CONCAT44(0x43300000,param_4[3] ^ 0x80000000) -
                                DOUBLE_00108d58));
  return;
}

/* _glTexGeniv_CompExec @ 0x9c5d8 (72 bytes) */
int _glTexGeniv_CompExec(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  ((double (*)())_glTexGeniv_Comp)(param_1,param_2,param_3,param_4);
  ((int (*)())_glTexGeniv_Exec)(param_1,param_2,param_3,param_4);
  return;
}

/* _glGetTexGendv_Exec @ 0x9c620 (632 bytes) */
int _glGetTexGendv_Exec(param_1, param_2, param_3, param_4)
  int param_1;
  uint param_2;
  uint param_3;
  double *param_4;
{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  double dVar4;
  
  uVar2 = *(uint *)(param_1 + 0x53d4);
  if ((-1 < *(short *)(param_1 + 0x4a10)) || (7 < uVar2)) {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar1 = 0x502;
    goto LAB_0009c714;
  }
  if (param_2 == 0x2001) {
    if (param_3 == 0x2501) {
      iVar3 = uVar2 * 0x94 + param_1 + 0x3d10;
LAB_0009c790:
      *param_4 = (double)*(float *)(iVar3 + 0x10);
      param_4[1] = (double)*(float *)(iVar3 + 0x14);
      param_4[2] = (double)*(float *)(iVar3 + 0x18);
      dVar4 = (double)*(float *)(iVar3 + 0x1c);
LAB_0009c6fc:
      param_4[3] = dVar4;
      return;
    }
    if (param_3 < 0x2502) {
      if (param_3 == 0x2500) {
        uVar2 = (uint)*(ushort *)(uVar2 * 0x94 + param_1 + 0x3d0c);
        goto LAB_0009c750;
      }
    }
    else if (param_3 == 0x2502) {
      iVar3 = uVar2 * 0x94 + param_1 + 0x3d00;
      goto LAB_0009c790;
    }
  }
  else if (param_2 < 0x2002) {
    if (param_2 == 0x2000) {
      if (param_3 == 0x2501) {
        iVar3 = uVar2 * 0x94 + param_1 + 0x3cf0;
LAB_0009c6e0:
        *param_4 = (double)*(float *)(iVar3 + 0xc);
        param_4[1] = (double)*(float *)(iVar3 + 0x10);
        param_4[2] = (double)*(float *)(iVar3 + 0x14);
        dVar4 = (double)*(float *)(iVar3 + 0x18);
        goto LAB_0009c6fc;
      }
      if (param_3 < 0x2502) {
        if (param_3 == 0x2500) {
          uVar2 = (uint)*(ushort *)(uVar2 * 0x94 + param_1 + 0x3ce8);
          goto LAB_0009c750;
        }
      }
      else if (param_3 == 0x2502) {
        iVar3 = uVar2 * 0x94 + param_1 + 0x3ce0;
        goto LAB_0009c6e0;
      }
    }
  }
  else if (param_2 == 0x2002) {
    if (param_3 == 0x2501) {
      iVar3 = uVar2 * 0x94 + param_1 + 0x3d30;
LAB_0009c804:
      *param_4 = (double)*(float *)(iVar3 + 0x14);
      param_4[1] = (double)*(float *)(iVar3 + 0x18);
      param_4[2] = (double)*(float *)(iVar3 + 0x1c);
      dVar4 = (double)*(float *)(iVar3 + 0x20);
      goto LAB_0009c6fc;
    }
    if (param_3 < 0x2502) {
      if (param_3 == 0x2500) {
        uVar2 = (uint)*(ushort *)(uVar2 * 0x94 + param_1 + 0x3d30);
LAB_0009c750:
        *param_4 = (double)CONCAT44(0x43300000,uVar2) - DOUBLE_00108d70;
        return;
      }
    }
    else if (param_3 == 0x2502) {
      iVar3 = uVar2 * 0x94 + param_1 + 0x3d20;
      goto LAB_0009c804;
    }
  }
  else if (param_2 == 0x2003) {
    if (param_3 == 0x2501) {
      iVar3 = uVar2 * 0x94 + param_1 + 0x3d50;
LAB_0009c878:
      *param_4 = (double)*(float *)(iVar3 + 0x18);
      param_4[1] = (double)*(float *)(iVar3 + 0x1c);
      param_4[2] = (double)*(float *)(iVar3 + 0x20);
      dVar4 = (double)*(float *)(iVar3 + 0x24);
      goto LAB_0009c6fc;
    }
    if (param_3 < 0x2502) {
      if (param_3 == 0x2500) {
        uVar2 = (uint)*(ushort *)(uVar2 * 0x94 + param_1 + 0x3d54);
        goto LAB_0009c750;
      }
    }
    else if (param_3 == 0x2502) {
      iVar3 = uVar2 * 0x94 + param_1 + 0x3d40;
      goto LAB_0009c878;
    }
  }
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  uVar1 = 0x500;
LAB_0009c714:
  *(undefined4 *)(param_1 + 0x7574) = uVar1;
  return;
}

/* _glGetTexGenfv_Exec @ 0x9c898 (620 bytes) */
void _glGetTexGenfv_Exec(int param_1,uint param_2,uint param_3,float *param_4,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  float fVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  
  uVar3 = *(uint *)(param_1 + 0x53d4);
  if ((-1 < *(short *)(param_1 + 0x4a10)) || (7 < uVar3)) {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar2 = 0x502;
    goto LAB_0009c97c;
  }
  if (param_2 == 0x2001) {
    if (param_3 == 0x2501) {
      iVar4 = uVar3 * 0x94 + param_1 + 0x3d10;
LAB_0009c9fc:
      *param_4 = *(float *)(iVar4 + 0x10);
      param_4[1] = *(float *)(iVar4 + 0x14);
      param_4[2] = *(float *)(iVar4 + 0x18);
      fVar1 = *(float *)(iVar4 + 0x1c);
LAB_0009c964:
      param_4[3] = fVar1;
      return;
    }
    if (param_3 < 0x2502) {
      if (param_3 == 0x2500) {
        uVar3 = (uint)*(ushort *)(uVar3 * 0x94 + param_1 + 0x3d0c);
        goto LAB_0009c9b8;
      }
    }
    else if (param_3 == 0x2502) {
      iVar4 = uVar3 * 0x94 + param_1 + 0x3d00;
      goto LAB_0009c9fc;
    }
  }
  else if (param_2 < 0x2002) {
    if (param_2 == 0x2000) {
      if (param_3 == 0x2501) {
        iVar4 = uVar3 * 0x94 + param_1 + 0x3cf0;
LAB_0009c948:
        *param_4 = *(float *)(iVar4 + 0xc);
        param_4[1] = *(float *)(iVar4 + 0x10);
        param_4[2] = *(float *)(iVar4 + 0x14);
        fVar1 = *(float *)(iVar4 + 0x18);
        goto LAB_0009c964;
      }
      if (param_3 < 0x2502) {
        if (param_3 == 0x2500) {
          uVar3 = (uint)*(ushort *)(uVar3 * 0x94 + param_1 + 0x3ce8);
          goto LAB_0009c9b8;
        }
      }
      else if (param_3 == 0x2502) {
        iVar4 = uVar3 * 0x94 + param_1 + 0x3ce0;
        goto LAB_0009c948;
      }
    }
  }
  else if (param_2 == 0x2002) {
    if (param_3 == 0x2501) {
      iVar4 = uVar3 * 0x94 + param_1 + 0x3d30;
LAB_0009ca70:
      *param_4 = *(float *)(iVar4 + 0x14);
      param_4[1] = *(float *)(iVar4 + 0x18);
      param_4[2] = *(float *)(iVar4 + 0x1c);
      fVar1 = *(float *)(iVar4 + 0x20);
      goto LAB_0009c964;
    }
    if (param_3 < 0x2502) {
      if (param_3 == 0x2500) {
        uVar3 = (uint)*(ushort *)(uVar3 * 0x94 + param_1 + 0x3d30);
LAB_0009c9b8:
        *param_4 = GH_U2F((unsigned int)((uVar3 | 0x4b000000))) - 8388608.0;
        return;
      }
    }
    else if (param_3 == 0x2502) {
      iVar4 = uVar3 * 0x94 + param_1 + 0x3d20;
      goto LAB_0009ca70;
    }
  }
  else if (param_2 == 0x2003) {
    if (param_3 == 0x2501) {
      iVar4 = uVar3 * 0x94 + param_1 + 0x3d50;
LAB_0009cae4:
      *param_4 = *(float *)(iVar4 + 0x18);
      param_4[1] = *(float *)(iVar4 + 0x1c);
      param_4[2] = *(float *)(iVar4 + 0x20);
      fVar1 = *(float *)(iVar4 + 0x24);
      goto LAB_0009c964;
    }
    if (param_3 < 0x2502) {
      if (param_3 == 0x2500) {
        uVar3 = (uint)*(ushort *)(uVar3 * 0x94 + param_1 + 0x3d54);
        goto LAB_0009c9b8;
      }
    }
    else if (param_3 == 0x2502) {
      iVar4 = uVar3 * 0x94 + param_1 + 0x3d40;
      goto LAB_0009cae4;
    }
  }
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  uVar2 = 0x500;
LAB_0009c97c:
  *(undefined4 *)(param_1 + 0x7574) = uVar2;
  return;
}

/* _glGetTexGeniv_Exec @ 0x9cb04 (744 bytes) */
int _glGetTexGeniv_Exec(param_1, param_2, param_3, param_4)
  int param_1;
  uint param_2;
  uint param_3;
  uint *param_4;
{
  float fVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  
  uVar3 = *(uint *)(param_1 + 0x53d4);
  if ((-1 < *(short *)(param_1 + 0x4a10)) || (7 < uVar3)) {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar2 = 0x502;
    goto LAB_0009cc18;
  }
  if (param_2 == 0x2001) {
    if (param_3 == 0x2501) {
      iVar4 = uVar3 * 0x94 + param_1 + 0x3d10;
LAB_0009cc78:
      *param_4 = (int)*(float *)(iVar4 + 0x10);
      param_4[1] = (int)*(float *)(iVar4 + 0x14);
      param_4[2] = (int)*(float *)(iVar4 + 0x18);
      fVar1 = *(float *)(iVar4 + 0x1c);
LAB_0009cbf4:
      param_4[3] = (int)fVar1;
      return;
    }
    if (param_3 < 0x2502) {
      if (param_3 == 0x2500) {
        uVar3 = (uint)*(ushort *)(uVar3 * 0x94 + param_1 + 0x3d0c);
        goto LAB_0009cc54;
      }
    }
    else if (param_3 == 0x2502) {
      iVar4 = uVar3 * 0x94 + param_1 + 0x3d00;
      goto LAB_0009cc78;
    }
  }
  else if (param_2 < 0x2002) {
    if (param_2 == 0x2000) {
      if (param_3 == 0x2501) {
        iVar4 = uVar3 * 0x94 + param_1 + 0x3cf0;
LAB_0009cbb4:
        *param_4 = (int)*(float *)(iVar4 + 0xc);
        param_4[1] = (int)*(float *)(iVar4 + 0x10);
        param_4[2] = (int)*(float *)(iVar4 + 0x14);
        fVar1 = *(float *)(iVar4 + 0x18);
        goto LAB_0009cbf4;
      }
      if (param_3 < 0x2502) {
        if (param_3 == 0x2500) {
          uVar3 = (uint)*(ushort *)(uVar3 * 0x94 + param_1 + 0x3ce8);
          goto LAB_0009cc54;
        }
      }
      else if (param_3 == 0x2502) {
        iVar4 = uVar3 * 0x94 + param_1 + 0x3ce0;
        goto LAB_0009cbb4;
      }
    }
  }
  else if (param_2 == 0x2002) {
    if (param_3 == 0x2501) {
      iVar4 = uVar3 * 0x94 + param_1 + 0x3d30;
LAB_0009cd10:
      *param_4 = (int)*(float *)(iVar4 + 0x14);
      param_4[1] = (int)*(float *)(iVar4 + 0x18);
      param_4[2] = (int)*(float *)(iVar4 + 0x1c);
      fVar1 = *(float *)(iVar4 + 0x20);
      goto LAB_0009cbf4;
    }
    if (param_3 < 0x2502) {
      if (param_3 == 0x2500) {
        uVar3 = (uint)*(ushort *)(uVar3 * 0x94 + param_1 + 0x3d30);
LAB_0009cc54:
        *param_4 = uVar3;
        return;
      }
    }
    else if (param_3 == 0x2502) {
      iVar4 = uVar3 * 0x94 + param_1 + 0x3d20;
      goto LAB_0009cd10;
    }
  }
  else if (param_2 == 0x2003) {
    if (param_3 == 0x2501) {
      iVar4 = uVar3 * 0x94 + param_1 + 0x3d50;
LAB_0009cda8:
      *param_4 = (int)*(float *)(iVar4 + 0x18);
      param_4[1] = (int)*(float *)(iVar4 + 0x1c);
      param_4[2] = (int)*(float *)(iVar4 + 0x20);
      fVar1 = *(float *)(iVar4 + 0x24);
      goto LAB_0009cbf4;
    }
    if (param_3 < 0x2502) {
      if (param_3 == 0x2500) {
        uVar3 = (uint)*(ushort *)(uVar3 * 0x94 + param_1 + 0x3d54);
        goto LAB_0009cc54;
      }
    }
    else if (param_3 == 0x2502) {
      iVar4 = uVar3 * 0x94 + param_1 + 0x3d40;
      goto LAB_0009cda8;
    }
  }
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  uVar2 = 0x500;
LAB_0009cc18:
  *(undefined4 *)(param_1 + 0x7574) = uVar2;
  return;
}

/* _glCopyTexImage1D_ListExec @ 0x9cdec (68 bytes) */
undefined4 _glCopyTexImage1D_ListExec(undefined4 param_1,undefined4 *param_2,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  ((void (*)())_glCopyTexImage1D_Exec)(param_1,*param_2,param_2[1],param_2[2],param_2[3],param_2[4],param_2[5],param_2[6],
             fparam_1,fparam_2,fparam_3,fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
  return 0x1c;
}

/* _glCopyTexImage1D_Comp @ 0x9ce30 (124 bytes) */
int _glCopyTexImage1D_Comp(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glCopyTexImage1D_ListExec_001103e8,0x1c);
  if (puVar1 != (undefined4 *)0x0) {
    puVar1[6] = param_8;
    *puVar1 = param_2;
    puVar1[1] = param_3;
    puVar1[2] = param_4;
    puVar1[3] = param_5;
    puVar1[4] = param_6;
    puVar1[5] = param_7;
  }
  return puVar1;
}

/* _glCopyTexImage1D_Exec @ 0x9ceac (1592 bytes) */
void _glCopyTexImage1D_Exec(int param_1,undefined4 param_2,uint param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  bool bVar1;
  char cVar2;
  ushort uVar3;
  undefined4 uVar4;
  int *piVar5;
  byte bVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  int iVar11;
  uint uVar12;
  int *piVar13;
  int iVar14;
  double extraout_f1;
  
  if ((*(int *)(param_1 + 0x744c) != 0) || (*(int *)(param_1 + 0x310) < 0)) {
    iVar11 = *(int *)(param_1 + 0x50ac);
    uVar12 = param_3;
    uVar4 = param_4;
    uVar9 = param_5;
    uVar10 = param_6;
    if (iVar11 != 0 || (*(uint *)(param_1 + 0x505c) & *(uint *)(param_1 + 0x50b0)) != 0) {
      _gleUpdateMatrixFunc(param_1);
      fparam_1 = extraout_f1;
    }
    if (*(char *)(param_1 + 0x4691) != '\0') {
      iVar8 = *(int *)(param_1 + 0x744c);
      piVar13 = (int *)(param_1 + 0x310);
      cVar2 = *(char *)(*(int *)(param_1 + 0x468c) + 0x79);
      if ((iVar8 != 0) && (*(int *)(iVar8 + 0xec) != 0)) {
        ((int (*)())_gleUpdateFramebufferCompleteness)(param_1,iVar8 + 0x10,uVar12,uVar4,uVar9,uVar10,iVar11,fparam_1,fparam_2,fparam_3,
                   fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
        *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x80000000;
      }
      if ((*(char *)(param_1 + 0x4664) == '\0') && (*(int *)(param_1 + 0x5430) == 0)) {
LAB_0009cff4:
        uVar12 = *(uint *)(param_1 + 0x31c);
      }
      else {
        iVar11 = 0;
        piVar5 = (int *)(param_1 + 0x324);
        do {
          iVar8 = *piVar5;
          piVar5 = piVar5 + 1;
          if (iVar8 != 0) {
            *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x800000;
            break;
          }
          iVar11 = iVar11 + 1;
        } while (iVar11 < 9);
        uVar12 = *(uint *)(param_1 + 0x31c);
        if ((uVar12 & 0x15555) != 0) {
          if (*(char *)(param_1 + 0x2e54) != '\0') {
            _gleUpdateLightRGBASums(param_1,param_1 + 0x2c20,0);
          }
          if (*(char *)(param_1 + 0x3094) != '\0') {
            _gleUpdateLightRGBASums(param_1,param_1 + 0x2e60,1);
          }
          goto LAB_0009cff4;
        }
      }
      bVar1 = cVar2 == '\0';
      if (bVar1) {
        uVar12 = uVar12 & 0x17000000;
      }
      else {
        uVar12 = uVar12 & 0x17ffffff;
      }
      if (bVar1) {
        bVar1 = ((*piVar13 == 0 && *(int *)(param_1 + 0x314) == 0) && uVar12 == 0) &&
                *(int *)(param_1 + 800) == 0;
      }
      else {
        bVar1 = (((*piVar13 == 0 && *(int *)(param_1 + 0x314) == 0) &&
                 (*(uint *)(param_1 + 0x318) & 0xfffffffd) == 0) && uVar12 == 0) &&
                *(int *)(param_1 + 800) == 0;
      }
      if (!bVar1) {
        if (*(char *)(param_1 + 0x85a8) == *(char *)(param_1 + 0x85a6)) {
          uVar12 = (**(code **)(param_1 + 0x4788))
                             (*(undefined4 *)(param_1 + 0x4688),param_1 + 0x4698,piVar13);
          if ((((uVar12 & 3) != (uint)*(byte *)(param_1 + 0x7580)) ||
              ((uVar12 & 4) != (uint)*(byte *)(param_1 + 0x7581))) ||
             ((uVar12 & 8) != (uint)(*(char *)(param_1 + 0x759d) == '\0'))) {
            if ((uVar12 & 4) == 0) {
              uVar12 = uVar12 & 0xfffffffe;
              *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x10000000;
            }
            _gleUpdateDispatchCodeChange(param_1,uVar12);
            if (*(char *)(param_1 + 0x759d) == '\0') {
              if (*(int *)(param_1 + 0x7574) != 0) {
                return;
              }
              uVar4 = 0x506;
              goto LAB_0009d188;
            }
          }
        }
        else {
          _gleSwitchToNonRevertRenderer(param_1);
        }
        iVar11 = 0x13;
        do {
          *piVar13 = 0;
          piVar13 = piVar13 + 1;
          iVar11 = iVar11 + -1;
        } while (iVar11 != 0);
      }
    }
  }
  if (*(short *)(param_1 + 0x4a10) < 0) {
    iVar11 = _gleCheckCopyTexImage1DArgs(param_1,param_2,param_3,param_4,param_7,param_8);
    if (iVar11 == 0) {
      return;
    }
    uVar3 = *(ushort *)(iVar11 + 0x24);
    if ((uVar3 & 0x3c00) == 0x1000) {
LAB_0009d190:
      iVar8 = iVar11 + param_3 * 0x18;
      iVar14 = iVar8 + 0xc4;
      if ((*(byte *)(iVar8 + 0xcf) & 0x20) != 0) {
        _gleDeletePluginTextureLevel(param_1,iVar11,iVar14,0,param_3);
        if (*(int *)(iVar8 + 0xd8) != 0) {
          bVar6 = *(byte *)(iVar8 + 0xcf);
          if ((bVar6 & 1) == 0) {
            _gleFreeTextureLevel(param_1,iVar11,iVar14);
            bVar6 = *(byte *)(iVar8 + 0xcf);
          }
          else {
            *(undefined4 *)(iVar8 + 0xd8) = 0;
          }
          *(byte *)(iVar8 + 0xcf) = bVar6 & 0xef;
        }
        *(byte *)(iVar8 + 0xcf) = *(byte *)(iVar8 + 0xcf) & 0xdf;
      }
      iVar7 = _gleCreateTextureLevel
                        (param_1,iVar11,iVar14,param_4,param_7,1,1,param_8,0x1908,0x1401,0,0);
      if (iVar7 != 0) {
        _gleCreatePluginTextureLevel(param_1,iVar11,iVar14,0,param_3,param_4);
        if ((((int)(uint)*(byte *)(iVar11 + 0x8d) <= (int)param_3) &&
            ((int)param_3 <= (int)(uint)*(byte *)(iVar11 + 0x8f))) &&
           (((*(ushort *)(iVar11 + 0x94) >> (param_3 & 0x3f) & 1) != 0 &&
            (iVar7 = (**(code **)(param_1 + 0x470c))
                               (*(undefined4 *)(param_1 + 0x4688),
                                *(undefined4 *)(iVar11 + (uint)*(byte *)(param_1 + 0x85a8) * 4),0,
                                param_3,0,0,0,param_5), iVar7 != 0)))) {
          *(undefined4 *)(iVar11 + 0x20) =
               *(undefined4 *)
                ((uint)*(byte *)(param_1 + 0x85a8) * 4 + *(int *)(param_1 + 0x5148) + 0x8054);
          *(byte *)(iVar8 + 0xcf) = *(byte *)(iVar8 + 0xcf) | 0x40;
          if ((*(uint *)(iVar11 + 0x6c) & 0x8000) == 0) {
            return;
          }
          if ((int)*(short *)(iVar11 + 0x60) != param_3) {
            return;
          }
          uVar12 = param_3 + 1;
          if ((int)(uint)*(byte *)(iVar11 + 0x83) < (int)uVar12) {
            return;
          }
          iVar8 = uVar12 * 0x18 + iVar11 + 0xc4;
          do {
            if (*(int *)(iVar8 + 0x14) != 0) {
              if (((*(byte *)(iVar8 + 0xb) & 1) == 0) && (*(short *)(iVar11 + 0x3e) == -0x7a43)) {
                _gleFreeTextureLevel(param_1,iVar11,iVar8);
              }
              *(byte *)(iVar8 + 0xb) = *(byte *)(iVar8 + 0xb) & 0xef;
              *(ushort *)(iVar11 + 0xa0) =
                   *(ushort *)(iVar11 + 0xa0) & ~(ushort)(1 << (uVar12 & 0x3f));
            }
            uVar12 = uVar12 + 1;
            *(byte *)(iVar8 + 0xb) = *(byte *)(iVar8 + 0xb) | 0x40;
            iVar8 = iVar8 + 0x18;
          } while ((int)uVar12 <= (int)(uint)*(byte *)(iVar11 + 0x83));
          return;
        }
        bVar6 = *(byte *)(iVar8 + 0xcf);
        if ((bVar6 & 0x10) == 0) {
          if ((bVar6 & 0x40) == 0) {
            if (*(int *)(iVar8 + 0xd8) == 0) {
              _gleAllocateTextureLevel(param_1,iVar11,iVar14);
              bVar6 = *(byte *)(iVar8 + 0xcf);
            }
            *(byte *)(iVar8 + 0xcf) = bVar6 | 0x10;
          }
          else {
            _gleUploadPluginTextureLevel
                      (param_1,iVar11,iVar14,0,param_3,(uint)*(byte *)(param_1 + 0x85a8));
          }
        }
        _gleModifyPluginTextureLevel(param_1,iVar11,iVar14,0,param_3,0,0,0,param_7);
        _gleTextureImageCopy(param_1,iVar14,param_4,param_5,param_6,param_7,1);
        if ((((*(uint *)(iVar11 + 0x6c) & 0x8000) != 0) &&
            ((int)*(short *)(iVar11 + 0x60) == param_3)) &&
           (iVar11 = _gleGenMipmapsToLevel(param_1,iVar11,0,param_3,0xf,1), iVar11 != 0)) {
          return;
        }
      }
      *(uint *)(param_1 + 0x314) =
           *(uint *)(param_1 + 0x314) | 1 << (*(uint *)(param_1 + 0x53d4) & 0x3f);
      return;
    }
    if ((uVar3 & 0x3c00) == 0) {
      *(ushort *)(iVar11 + 0x24) = uVar3 | 0x1000;
      goto LAB_0009d190;
    }
    if ((uVar3 & 0xc00) == 0) goto LAB_0009d190;
  }
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  uVar4 = 0x502;
LAB_0009d188:
  *(undefined4 *)(param_1 + 0x7574) = uVar4;
  return;
}

/* _glCopyTexImage1D_CompExec @ 0x9d4e4 (104 bytes) */
int _glCopyTexImage1D_CompExec(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  double fparam_1;
  double in_f2;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  
  ((int (*)())_glCopyTexImage1D_Comp)(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
  ((void (*)())_glCopyTexImage1D_Exec)(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,fparam_1,in_f2,in_f3,
             in_f4,in_f5,in_f6,in_f7,in_f8);
  return;
}

/* _glCopyTexImage1D_NoopExec @ 0x9d54c (688 bytes) */
void _glCopyTexImage1D_NoopExec(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  bool bVar1;
  char cVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  uint uVar11;
  int *piVar12;
  double extraout_f1;
  double extraout_f1_00;
  double extraout_f1_01;
  
  uVar6 = param_3;
  uVar7 = param_4;
  uVar8 = param_5;
  uVar9 = param_6;
  uVar10 = param_7;
  if (*(int *)(param_1 + 0x50ac) != 0 ||
      (*(uint *)(param_1 + 0x505c) & *(uint *)(param_1 + 0x50b0)) != 0) {
    _gleUpdateMatrixFunc(param_1);
    fparam_1 = extraout_f1;
  }
  if (*(char *)(param_1 + 0x4691) != '\0') {
    iVar5 = *(int *)(param_1 + 0x744c);
    piVar12 = (int *)(param_1 + 0x310);
    cVar2 = *(char *)(*(int *)(param_1 + 0x468c) + 0x79);
    if ((iVar5 != 0) && (*(int *)(iVar5 + 0xec) != 0)) {
      ((int (*)())_gleUpdateFramebufferCompleteness)(param_1,iVar5 + 0x10,uVar6,uVar7,uVar8,uVar9,uVar10,fparam_1,fparam_2,fparam_3,
                 fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
      *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x80000000;
      fparam_1 = fparam_1;
    }
    if ((*(char *)(param_1 + 0x4664) == '\0') && (*(int *)(param_1 + 0x5430) == 0)) {
LAB_0009d67c:
      uVar11 = *(uint *)(param_1 + 0x31c);
    }
    else {
      iVar5 = 0;
      piVar4 = (int *)(param_1 + 0x324);
      do {
        iVar3 = *piVar4;
        piVar4 = piVar4 + 1;
        if (iVar3 != 0) {
          *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x800000;
          break;
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < 9);
      uVar11 = *(uint *)(param_1 + 0x31c);
      if ((uVar11 & 0x15555) != 0) {
        if (*(char *)(param_1 + 0x2e54) != '\0') {
          fparam_1 = (double)_gleUpdateLightRGBASums(param_1,param_1 + 0x2c20,0);
        }
        if (*(char *)(param_1 + 0x3094) != '\0') {
          fparam_1 = (double)_gleUpdateLightRGBASums(param_1,param_1 + 0x2e60,1);
        }
        goto LAB_0009d67c;
      }
    }
    bVar1 = cVar2 == '\0';
    if (bVar1) {
      uVar11 = uVar11 & 0x17000000;
    }
    else {
      uVar11 = uVar11 & 0x17ffffff;
    }
    if (bVar1) {
      bVar1 = ((*piVar12 == 0 && *(int *)(param_1 + 0x314) == 0) && uVar11 == 0) &&
              *(int *)(param_1 + 800) == 0;
    }
    else {
      bVar1 = (((*piVar12 == 0 && *(int *)(param_1 + 0x314) == 0) &&
               (*(uint *)(param_1 + 0x318) & 0xfffffffd) == 0) && uVar11 == 0) &&
              *(int *)(param_1 + 800) == 0;
    }
    if (!bVar1) {
      if (*(char *)(param_1 + 0x85a8) == *(char *)(param_1 + 0x85a6)) {
        uVar11 = (**(code **)(param_1 + 0x4788))
                           (*(undefined4 *)(param_1 + 0x4688),param_1 + 0x4698,piVar12);
        if ((((uVar11 & 3) != (uint)*(byte *)(param_1 + 0x7580)) ||
            ((uVar11 & 4) != (uint)*(byte *)(param_1 + 0x7581))) ||
           (fparam_1 = extraout_f1_01, (uVar11 & 8) != (uint)(*(char *)(param_1 + 0x759d) == '\0')))
        {
          if ((uVar11 & 4) == 0) {
            uVar11 = uVar11 & 0xfffffffe;
            *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x10000000;
          }
          fparam_1 = (double)_gleUpdateDispatchCodeChange(param_1,uVar11);
          if (*(char *)(param_1 + 0x759d) == '\0') goto LAB_0009d79c;
        }
      }
      else {
        fparam_1 = (double)_gleSwitchToNonRevertRenderer(param_1);
      }
      iVar5 = 0x13;
      do {
        *piVar12 = 0;
        piVar12 = piVar12 + 1;
        iVar5 = iVar5 + -1;
      } while (iVar5 != 0);
    }
  }
  if (*(char *)(param_1 + 0x759d) != '\0') {
    ((void (*)())_glCopyTexImage1D_Exec)(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,fparam_1,fparam_2,
               fparam_3,fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
    return;
  }
LAB_0009d79c:
  if (*(int *)(param_1 + 0x7574) == 0) {
    *(undefined4 *)(param_1 + 0x7574) = 0x506;
  }
  return;
}

/* _glCopyTexImage2D_ListExec @ 0x9d7fc (76 bytes) */
undefined4 _glCopyTexImage2D_ListExec(undefined4 param_1,undefined4 *param_2,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  ((void (*)())_glCopyTexImage2D_Exec)(param_1,*param_2,param_2[1],param_2[2],param_2[3],param_2[4],param_2[5],param_2[6],
             param_2[7],fparam_1,fparam_2,fparam_3,fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
  return 0x20;
}

/* _glCopyTexImage2D_Comp @ 0x9d848 (132 bytes) */
int _glCopyTexImage2D_Comp(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
  undefined4 param_9;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glCopyTexImage2D_ListExec_001103e4,0x20);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_2;
    puVar1[7] = param_9;
    puVar1[1] = param_3;
    puVar1[2] = param_4;
    puVar1[3] = param_5;
    puVar1[4] = param_6;
    puVar1[5] = param_7;
    puVar1[6] = param_8;
  }
  return puVar1;
}

/* _glCopyTexImage2D_CompExec @ 0x9d8cc (116 bytes) */
int _glCopyTexImage2D_CompExec(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
  undefined4 param_9;
{
  double fparam_1;
  double in_f2;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  
  ((int (*)())_glCopyTexImage2D_Comp)(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9);
  ((void (*)())_glCopyTexImage2D_Exec)(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,fparam_1,in_f2,
             in_f3,in_f4,in_f5,in_f6,in_f7,in_f8);
  return;
}

/* _glCopyTexImage2D_NoopExec @ 0x9d940 (696 bytes) */
void _glCopyTexImage2D_NoopExec(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  bool bVar1;
  char cVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  uint uVar11;
  int *piVar12;
  double extraout_f1;
  double extraout_f1_00;
  double extraout_f1_01;
  
  uVar6 = param_3;
  uVar7 = param_4;
  uVar8 = param_5;
  uVar9 = param_6;
  uVar10 = param_7;
  if (*(int *)(param_1 + 0x50ac) != 0 ||
      (*(uint *)(param_1 + 0x505c) & *(uint *)(param_1 + 0x50b0)) != 0) {
    _gleUpdateMatrixFunc(param_1);
    fparam_1 = extraout_f1;
  }
  if (*(char *)(param_1 + 0x4691) != '\0') {
    iVar5 = *(int *)(param_1 + 0x744c);
    piVar12 = (int *)(param_1 + 0x310);
    cVar2 = *(char *)(*(int *)(param_1 + 0x468c) + 0x79);
    if ((iVar5 != 0) && (*(int *)(iVar5 + 0xec) != 0)) {
      ((int (*)())_gleUpdateFramebufferCompleteness)(param_1,iVar5 + 0x10,uVar6,uVar7,uVar8,uVar9,uVar10,fparam_1,fparam_2,fparam_3,
                 fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
      *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x80000000;
      fparam_1 = fparam_1;
    }
    if ((*(char *)(param_1 + 0x4664) == '\0') && (*(int *)(param_1 + 0x5430) == 0)) {
LAB_0009da74:
      uVar11 = *(uint *)(param_1 + 0x31c);
    }
    else {
      iVar5 = 0;
      piVar4 = (int *)(param_1 + 0x324);
      do {
        iVar3 = *piVar4;
        piVar4 = piVar4 + 1;
        if (iVar3 != 0) {
          *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x800000;
          break;
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < 9);
      uVar11 = *(uint *)(param_1 + 0x31c);
      if ((uVar11 & 0x15555) != 0) {
        if (*(char *)(param_1 + 0x2e54) != '\0') {
          fparam_1 = (double)_gleUpdateLightRGBASums(param_1,param_1 + 0x2c20,0);
        }
        if (*(char *)(param_1 + 0x3094) != '\0') {
          fparam_1 = (double)_gleUpdateLightRGBASums(param_1,param_1 + 0x2e60,1);
        }
        goto LAB_0009da74;
      }
    }
    bVar1 = cVar2 == '\0';
    if (bVar1) {
      uVar11 = uVar11 & 0x17000000;
    }
    else {
      uVar11 = uVar11 & 0x17ffffff;
    }
    if (bVar1) {
      bVar1 = ((*piVar12 == 0 && *(int *)(param_1 + 0x314) == 0) && uVar11 == 0) &&
              *(int *)(param_1 + 800) == 0;
    }
    else {
      bVar1 = (((*piVar12 == 0 && *(int *)(param_1 + 0x314) == 0) &&
               (*(uint *)(param_1 + 0x318) & 0xfffffffd) == 0) && uVar11 == 0) &&
              *(int *)(param_1 + 800) == 0;
    }
    if (!bVar1) {
      if (*(char *)(param_1 + 0x85a8) == *(char *)(param_1 + 0x85a6)) {
        uVar11 = (**(code **)(param_1 + 0x4788))
                           (*(undefined4 *)(param_1 + 0x4688),param_1 + 0x4698,piVar12);
        if ((((uVar11 & 3) != (uint)*(byte *)(param_1 + 0x7580)) ||
            ((uVar11 & 4) != (uint)*(byte *)(param_1 + 0x7581))) ||
           (fparam_1 = extraout_f1_01, (uVar11 & 8) != (uint)(*(char *)(param_1 + 0x759d) == '\0')))
        {
          if ((uVar11 & 4) == 0) {
            uVar11 = uVar11 & 0xfffffffe;
            *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x10000000;
          }
          fparam_1 = (double)_gleUpdateDispatchCodeChange(param_1,uVar11);
          if (*(char *)(param_1 + 0x759d) == '\0') goto LAB_0009db94;
        }
      }
      else {
        fparam_1 = (double)_gleSwitchToNonRevertRenderer(param_1);
      }
      iVar5 = 0x13;
      do {
        *piVar12 = 0;
        piVar12 = piVar12 + 1;
        iVar5 = iVar5 + -1;
      } while (iVar5 != 0);
    }
  }
  if (*(char *)(param_1 + 0x759d) != '\0') {
    ((void (*)())_glCopyTexImage2D_Exec)(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,fparam_1,
               fparam_2,fparam_3,fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
    return;
  }
LAB_0009db94:
  if (*(int *)(param_1 + 0x7574) == 0) {
    *(undefined4 *)(param_1 + 0x7574) = 0x506;
  }
  return;
}

