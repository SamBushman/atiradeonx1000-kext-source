#include "decls.h"

/* _glResetHistogram_Comp @ 0x690f0 (76 bytes) */
int _glResetHistogram_Comp(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glResetHistogram_ListExec_00110110,0x10);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_2;
  }
  return puVar1;
}

/* _glResetMinmax_Comp @ 0x6913c (76 bytes) */
int _glResetMinmax_Comp(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glResetMinmax_ListExec_0011010c,0xc);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_2;
  }
  return puVar1;
}

/* _glConvolutionFilter1D_Exec @ 0x69188 (376 bytes) */
int _glConvolutionFilter1D_Exec(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int param_1;
  int param_2;
  undefined4 param_3;
  uint param_4;
  undefined4 param_5;
  undefined4 param_6;
  int param_7;
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  double dVar7;
  
  iVar2 = _gleImagingTexFormatToInternal(param_3);
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if ((param_2 != 0x8010) || (iVar2 == 0)) {
      if (*(int *)(param_1 + 0x7574) != 0) {
        return;
      }
      uVar1 = 0x500;
      goto LAB_000692a4;
    }
    iVar3 = _CheckTypeFormat(param_6,param_5);
    if (iVar3 != 0) {
      if (0xb < param_4) {
        if (*(int *)(param_1 + 0x7574) != 0) {
          return;
        }
        uVar1 = 0x501;
        goto LAB_000692a4;
      }
      iVar3 = *(int *)(param_1 + 0x4a6c);
      if (iVar3 == 0) {
LAB_000692cc:
        _gleConvolutionFilter1D(param_1,0x8010,iVar2,param_4,param_5,param_6,param_7);
        return;
      }
      iVar4 = _gleOffsetLimitImage(param_1 + 0x31cc,param_4,1,param_5,param_6,param_7);
      iVar6 = *(int *)(iVar3 + 0x38);
      dVar7 = (double)((double (*)())_gleBytesPerElement)(param_6);
      iVar5 = (int)dVar7;
      if (iVar4 <= iVar6) {
        if (iVar5 == 0) {
          iVar5 = _glePixelBytes(param_5,param_6);
        }
        if (param_7 == (param_7 / iVar5) * iVar5) {
          if (*(int *)(iVar3 + 0x40) != 0) {
            _gleSynchronizePluginBuffer(param_1,iVar3 + 0x10);
          }
          param_7 = param_7 + *(int *)(iVar3 + 0x30);
          goto LAB_000692cc;
        }
      }
    }
  }
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  uVar1 = 0x502;
LAB_000692a4:
  *(undefined4 *)(param_1 + 0x7574) = uVar1;
  return;
}

/* _glConvolutionFilter2D_Exec @ 0x69300 (408 bytes) */
int _glConvolutionFilter2D_Exec(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  int param_2;
  undefined4 param_3;
  int param_4;
  int param_5;
  undefined4 param_6;
  undefined4 param_7;
  int param_8;
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  double dVar7;
  
  iVar2 = _gleImagingTexFormatToInternal(param_3);
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if ((param_2 != 0x8011) || (iVar2 == 0)) {
      if (*(int *)(param_1 + 0x7574) != 0) {
        return;
      }
      uVar1 = 0x500;
      goto LAB_00069438;
    }
    iVar3 = _CheckTypeFormat(param_7,param_6);
    if (iVar3 != 0) {
      if ((((0xb < param_4) || (0xb < param_5)) || (param_4 < 0)) || (param_5 < 0)) {
        if (*(int *)(param_1 + 0x7574) != 0) {
          return;
        }
        uVar1 = 0x501;
        goto LAB_00069438;
      }
      iVar3 = *(int *)(param_1 + 0x4a6c);
      if (iVar3 == 0) {
LAB_00069460:
        _gleConvolutionFilter2D(param_1,0x8011,iVar2,param_4,param_5,param_6,param_7,param_8);
        return;
      }
      iVar4 = _gleOffsetLimitImage(param_1 + 0x31cc,param_4,param_5,param_6,param_7,param_8);
      iVar6 = *(int *)(iVar3 + 0x38);
      dVar7 = (double)((double (*)())_gleBytesPerElement)(param_7);
      iVar5 = (int)dVar7;
      if (iVar4 <= iVar6) {
        if (iVar5 == 0) {
          iVar5 = _glePixelBytes(param_6,param_7);
        }
        if (param_8 == (param_8 / iVar5) * iVar5) {
          if (*(int *)(iVar3 + 0x40) != 0) {
            _gleSynchronizePluginBuffer(param_1,iVar3 + 0x10);
          }
          param_8 = param_8 + *(int *)(iVar3 + 0x30);
          goto LAB_00069460;
        }
      }
    }
  }
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  uVar1 = 0x502;
LAB_00069438:
  *(undefined4 *)(param_1 + 0x7574) = uVar1;
  return;
}

/* _glConvolutionParameteri_Exec @ 0x69498 (176 bytes) */
int _glConvolutionParameteri_Exec(param_1, param_2, param_3, param_4)
  int param_1;
  uint param_2;
  int param_3;
  undefined4 param_4;
{
  undefined4 uVar1;
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if ((param_2 - 0x8010 < 3) && (param_3 == 0x8013)) {
      if (param_2 == 0x8011) {
        *(undefined2 *)(param_1 + 0x3308) = (*(unsigned short *)((unsigned char *)&(param_4) + 2));
        return;
      }
      if (param_2 < 0x8012) {
        if (param_2 == 0x8010) {
          *(undefined2 *)(param_1 + 13000) = (*(unsigned short *)((unsigned char *)&(param_4) + 2));
          return;
        }
      }
      else if (param_2 == 0x8012) {
        *(undefined2 *)(param_1 + 0x3348) = (*(unsigned short *)((unsigned char *)&(param_4) + 2));
        return;
      }
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

/* _glConvolutionParameteriv_Exec @ 0x69548 (692 bytes) */
int _glConvolutionParameteriv_Exec(param_1, param_2, param_3, param_4)
  int param_1;
  uint param_2;
  uint param_3;
  uint *param_4;
{
  double dVar1;
  undefined4 uVar2;
  float *pfVar3;
  
  dVar1 = DOUBLE_00108d58;
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if (param_2 == 0x8011) {
      pfVar3 = (float *)(param_1 + 0x32d8);
LAB_000695f0:
      if (param_3 == 0x8015) {
        pfVar3[5] = (float)((double)CONCAT44(0x43300000,*param_4 ^ 0x80000000) - DOUBLE_00108d58);
        pfVar3[7] = (float)((double)CONCAT44(0x43300000,param_4[1] ^ 0x80000000) - dVar1);
        pfVar3[9] = (float)((double)CONCAT44(0x43300000,param_4[2] ^ 0x80000000) - dVar1);
        pfVar3[0xb] = (float)((double)CONCAT44(0x43300000,param_4[3] ^ 0x80000000) - dVar1);
        return;
      }
      if (param_3 < 0x8016) {
        if (param_3 == 0x8014) {
          pfVar3[4] = (float)((double)CONCAT44(0x43300000,*param_4 ^ 0x80000000) - DOUBLE_00108d58);
          pfVar3[6] = (float)((double)CONCAT44(0x43300000,param_4[1] ^ 0x80000000) - dVar1);
          pfVar3[8] = (float)((double)CONCAT44(0x43300000,param_4[2] ^ 0x80000000) - dVar1);
          pfVar3[10] = (float)((double)CONCAT44(0x43300000,param_4[3] ^ 0x80000000) - dVar1);
          return;
        }
      }
      else if (param_3 == 0x8154) {
        *pfVar3 = (float)((double)CONCAT44(0x43300000,*param_4 ^ 0x80000000) - DOUBLE_00108d58);
        pfVar3[1] = (float)((double)CONCAT44(0x43300000,param_4[1] ^ 0x80000000) - dVar1);
        pfVar3[2] = (float)((double)CONCAT44(0x43300000,param_4[2] ^ 0x80000000) - dVar1);
        pfVar3[3] = (float)((double)CONCAT44(0x43300000,param_4[3] ^ 0x80000000) - dVar1);
        return;
      }
      ((int (*)())_glConvolutionParameteri_Exec)(param_1,param_2,param_3,*param_4);
      return;
    }
    if (param_2 < 0x8012) {
      if (param_2 == 0x8010) {
        pfVar3 = (float *)(param_1 + 0x3298);
        goto LAB_000695f0;
      }
    }
    else if (param_2 == 0x8012) {
      pfVar3 = (float *)(param_1 + 0x3318);
      goto LAB_000695f0;
    }
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar2 = 0x500;
  }
  else {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar2 = 0x502;
  }
  *(undefined4 *)(param_1 + 0x7574) = uVar2;
  return;
}

/* _glConvolutionParameterf_Exec @ 0x697fc (44 bytes) */
void _glConvolutionParameterf_Exec(undefined4 param_1,undefined4 param_2,undefined4 param_3,double fparam_1)
{
  ((int (*)())_glConvolutionParameteri_Exec)(param_1,param_2,param_3,(int)fparam_1);
  return;
}

/* _glConvolutionParameterfv_Exec @ 0x69828 (324 bytes) */
int _glConvolutionParameterfv_Exec(param_1, param_2, param_3, param_4)
  int param_1;
  uint param_2;
  uint param_3;
  float *param_4;
{
  undefined4 uVar1;
  float *pfVar2;
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if (param_2 == 0x8011) {
      pfVar2 = (float *)(param_1 + 0x32d8);
LAB_000698b8:
      if (param_3 == 0x8015) {
        pfVar2[5] = *param_4;
        pfVar2[7] = param_4[1];
        pfVar2[9] = param_4[2];
        pfVar2[0xb] = param_4[3];
        return;
      }
      if (param_3 < 0x8016) {
        if (param_3 == 0x8014) {
          pfVar2[4] = *param_4;
          pfVar2[6] = param_4[1];
          pfVar2[8] = param_4[2];
          pfVar2[10] = param_4[3];
          return;
        }
      }
      else if (param_3 == 0x8154) {
        *pfVar2 = *param_4;
        pfVar2[1] = param_4[1];
        pfVar2[2] = param_4[2];
        pfVar2[3] = param_4[3];
        return;
      }
      ((void (*)())_glConvolutionParameterf_Exec)(param_1,param_2,param_3,(double)*param_4);
      return;
    }
    if (param_2 < 0x8012) {
      if (param_2 == 0x8010) {
        pfVar2 = (float *)(param_1 + 0x3298);
        goto LAB_000698b8;
      }
    }
    else if (param_2 == 0x8012) {
      pfVar2 = (float *)(param_1 + 0x3318);
      goto LAB_000698b8;
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

/* _glCopyConvolutionFilter1D_Exec @ 0x6996c (824 bytes) */
int _glCopyConvolutionFilter1D_Exec(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  uint param_6;
{
  bool bVar1;
  char cVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  uint uVar9;
  int *piVar10;
  double extraout_f1;
  double extraout_f1_00;
  double extraout_f1_01;
  double dVar11;
  double extraout_f1_02;
  double in_f2;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  undefined1 auStack_e0 [188];
  
  uVar3 = param_4;
  uVar7 = param_5;
  uVar9 = param_6;
  iVar5 = _gleImagingTexFormatToInternal(param_3);
  dVar11 = extraout_f1;
  if ((*(int *)(param_1 + 0x744c) != 0) || (*(int *)(param_1 + 0x310) < 0)) {
    iVar8 = *(int *)(param_1 + 0x50ac);
    if (iVar8 != 0 || (*(uint *)(param_1 + 0x505c) & *(uint *)(param_1 + 0x50b0)) != 0) {
      _gleUpdateMatrixFunc(param_1);
      dVar11 = extraout_f1_00;
    }
    if (*(char *)(param_1 + 0x4691) != '\0') {
      iVar6 = *(int *)(param_1 + 0x744c);
      piVar10 = (int *)(param_1 + 0x310);
      cVar2 = *(char *)(*(int *)(param_1 + 0x468c) + 0x79);
      if ((iVar6 != 0) && (*(int *)(iVar6 + 0xec) != 0)) {
        ((int (*)())_gleUpdateFramebufferCompleteness)(param_1,iVar6 + 0x10,param_3,uVar3,uVar7,uVar9,iVar8,dVar11,in_f2,in_f3,in_f4,
                   in_f5,in_f6,in_f7,in_f8);
        *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x80000000;
        dVar11 = extraout_f1_01;
      }
      if ((*(char *)(param_1 + 0x4664) == '\0') && (*(int *)(param_1 + 0x5430) == 0)) {
LAB_00069ab8:
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
            dVar11 = (double)_gleUpdateLightRGBASums(param_1,param_1 + 0x2c20,0);
          }
          if (*(char *)(param_1 + 0x3094) != '\0') {
            dVar11 = (double)_gleUpdateLightRGBASums(param_1,param_1 + 0x2e60,1);
          }
          goto LAB_00069ab8;
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
        bVar1 = ((*piVar10 == 0 && *(int *)(param_1 + 0x314) == 0) && uVar9 == 0) &&
                *(int *)(param_1 + 800) == 0;
      }
      else {
        bVar1 = (((*piVar10 == 0 && *(int *)(param_1 + 0x314) == 0) &&
                 (*(uint *)(param_1 + 0x318) & 0xfffffffd) == 0) && uVar9 == 0) &&
                *(int *)(param_1 + 800) == 0;
      }
      if (!bVar1) {
        if (*(char *)(param_1 + 0x85a8) == *(char *)(param_1 + 0x85a6)) {
          uVar9 = (**(code **)(param_1 + 0x4788))
                            (*(undefined4 *)(param_1 + 0x4688),param_1 + 0x4698,piVar10);
          if ((((uVar9 & 3) != (uint)*(byte *)(param_1 + 0x7580)) ||
              ((uVar9 & 4) != (uint)*(byte *)(param_1 + 0x7581))) ||
             (dVar11 = extraout_f1_02, (uVar9 & 8) != (uint)(*(char *)(param_1 + 0x759d) == '\0')))
          {
            if ((uVar9 & 4) == 0) {
              uVar9 = uVar9 & 0xfffffffe;
              *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x10000000;
            }
            dVar11 = (double)_gleUpdateDispatchCodeChange(param_1,uVar9);
            if (*(char *)(param_1 + 0x759d) == '\0') {
              if (*(int *)(param_1 + 0x7574) != 0) {
                return;
              }
              uVar3 = 0x506;
              goto LAB_00069c40;
            }
          }
        }
        else {
          dVar11 = (double)_gleSwitchToNonRevertRenderer(param_1);
        }
        iVar8 = 0x13;
        do {
          *piVar10 = 0;
          piVar10 = piVar10 + 1;
          iVar8 = iVar8 + -1;
        } while (iVar8 != 0);
      }
    }
  }
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if ((param_2 == 0x8010) && (iVar5 != 0)) {
      if (param_6 < 0xc) {
        ((void (*)())_glReadPixels_Exec)(param_1,param_4,param_5,param_6,1,iVar5,0x1406,auStack_e0,dVar11,in_f2,
                           in_f3,in_f4,in_f5,in_f6,in_f7,in_f8);
        ((int (*)())_glConvolutionFilter1D_Exec)(param_1,0x8010,iVar5,param_6,iVar5,0x1406,auStack_e0);
        return;
      }
      if (*(int *)(param_1 + 0x7574) != 0) {
        return;
      }
      uVar3 = 0x501;
    }
    else {
      if (*(int *)(param_1 + 0x7574) != 0) {
        return;
      }
      uVar3 = 0x500;
    }
  }
  else {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar3 = 0x502;
  }
LAB_00069c40:
  *(undefined4 *)(param_1 + 0x7574) = uVar3;
  return;
}

/* _glCopyConvolutionFilter2D_Exec @ 0x69ca4 (856 bytes) */
int _glCopyConvolutionFilter2D_Exec(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  int param_6;
  int param_7;
{
  bool bVar1;
  char cVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  int *piVar11;
  double extraout_f1;
  double extraout_f1_00;
  double extraout_f1_01;
  double dVar12;
  double extraout_f1_02;
  double in_f2;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  undefined1 auStack_7c0 [1944];
  
  uVar3 = param_4;
  uVar7 = param_5;
  iVar9 = param_6;
  iVar5 = _gleImagingTexFormatToInternal(param_3);
  dVar12 = extraout_f1;
  if ((*(int *)(param_1 + 0x744c) != 0) || (*(int *)(param_1 + 0x310) < 0)) {
    iVar8 = *(int *)(param_1 + 0x50ac);
    if (iVar8 != 0 || (*(uint *)(param_1 + 0x505c) & *(uint *)(param_1 + 0x50b0)) != 0) {
      _gleUpdateMatrixFunc(param_1);
      dVar12 = extraout_f1_00;
    }
    if (*(char *)(param_1 + 0x4691) != '\0') {
      iVar6 = *(int *)(param_1 + 0x744c);
      piVar11 = (int *)(param_1 + 0x310);
      cVar2 = *(char *)(*(int *)(param_1 + 0x468c) + 0x79);
      if ((iVar6 != 0) && (*(int *)(iVar6 + 0xec) != 0)) {
        ((int (*)())_gleUpdateFramebufferCompleteness)(param_1,iVar6 + 0x10,param_3,uVar3,uVar7,iVar9,iVar8,dVar12,in_f2,in_f3,in_f4,
                   in_f5,in_f6,in_f7,in_f8);
        *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x80000000;
        dVar12 = extraout_f1_01;
      }
      if ((*(char *)(param_1 + 0x4664) == '\0') && (*(int *)(param_1 + 0x5430) == 0)) {
LAB_00069df4:
        uVar10 = *(uint *)(param_1 + 0x31c);
      }
      else {
        iVar9 = 0;
        piVar4 = (int *)(param_1 + 0x324);
        do {
          iVar8 = *piVar4;
          piVar4 = piVar4 + 1;
          if (iVar8 != 0) {
            *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x800000;
            break;
          }
          iVar9 = iVar9 + 1;
        } while (iVar9 < 9);
        uVar10 = *(uint *)(param_1 + 0x31c);
        if ((uVar10 & 0x15555) != 0) {
          if (*(char *)(param_1 + 0x2e54) != '\0') {
            dVar12 = (double)_gleUpdateLightRGBASums(param_1,param_1 + 0x2c20,0);
          }
          if (*(char *)(param_1 + 0x3094) != '\0') {
            dVar12 = (double)_gleUpdateLightRGBASums(param_1,param_1 + 0x2e60,1);
          }
          goto LAB_00069df4;
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
        bVar1 = ((*piVar11 == 0 && *(int *)(param_1 + 0x314) == 0) && uVar10 == 0) &&
                *(int *)(param_1 + 800) == 0;
      }
      else {
        bVar1 = (((*piVar11 == 0 && *(int *)(param_1 + 0x314) == 0) &&
                 (*(uint *)(param_1 + 0x318) & 0xfffffffd) == 0) && uVar10 == 0) &&
                *(int *)(param_1 + 800) == 0;
      }
      if (!bVar1) {
        if (*(char *)(param_1 + 0x85a8) == *(char *)(param_1 + 0x85a6)) {
          uVar10 = (**(code **)(param_1 + 0x4788))
                             (*(undefined4 *)(param_1 + 0x4688),param_1 + 0x4698,piVar11);
          if ((((uVar10 & 3) != (uint)*(byte *)(param_1 + 0x7580)) ||
              ((uVar10 & 4) != (uint)*(byte *)(param_1 + 0x7581))) ||
             (dVar12 = extraout_f1_02, (uVar10 & 8) != (uint)(*(char *)(param_1 + 0x759d) == '\0')))
          {
            if ((uVar10 & 4) == 0) {
              uVar10 = uVar10 & 0xfffffffe;
              *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x10000000;
            }
            dVar12 = (double)_gleUpdateDispatchCodeChange(param_1,uVar10);
            if (*(char *)(param_1 + 0x759d) == '\0') {
              if (*(int *)(param_1 + 0x7574) != 0) {
                return;
              }
              uVar3 = 0x506;
              goto LAB_00069f94;
            }
          }
        }
        else {
          dVar12 = (double)_gleSwitchToNonRevertRenderer(param_1);
        }
        iVar9 = 0x13;
        do {
          *piVar11 = 0;
          piVar11 = piVar11 + 1;
          iVar9 = iVar9 + -1;
        } while (iVar9 != 0);
      }
    }
  }
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if ((param_2 == 0x8011) && (iVar5 != 0)) {
      if (((param_6 < 0xc) && (param_7 < 0xc)) && ((-1 < param_6 && (-1 < param_7)))) {
        ((void (*)())_glReadPixels_Exec)(param_1,param_4,param_5,param_6,param_7,iVar5,0x1406,auStack_7c0,dVar12,
                           in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8);
        ((int (*)())_glConvolutionFilter2D_Exec)(param_1,0x8011,iVar5,param_6,param_7,iVar5,0x1406,auStack_7c0);
        return;
      }
      if (*(int *)(param_1 + 0x7574) != 0) {
        return;
      }
      uVar3 = 0x501;
    }
    else {
      if (*(int *)(param_1 + 0x7574) != 0) {
        return;
      }
      uVar3 = 0x500;
    }
  }
  else {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar3 = 0x502;
  }
LAB_00069f94:
  *(undefined4 *)(param_1 + 0x7574) = uVar3;
  return;
}

/* _glGetConvolutionFilter_Exec @ 0x69ffc (340 bytes) */
int _glGetConvolutionFilter_Exec(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
  int param_5;
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  double dVar5;
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if (1 < param_2 - 0x8010U) {
      if (*(int *)(param_1 + 0x7574) != 0) {
        return;
      }
      uVar1 = 0x500;
      goto LAB_0006a0fc;
    }
    iVar3 = _CheckTypeFormat(param_3,param_4);
    if (iVar3 != 0) {
      iVar3 = *(int *)(param_1 + 0x4a68);
      if (iVar3 == 0) {
LAB_0006a124:
        _gleGetConvolutionFilter(param_1,param_2,param_3,param_4,param_5);
        return;
      }
      dVar5 = (double)((double (*)())_gleBytesPerElement)(param_4);
      iVar2 = param_1 + 0x3298;
      iVar4 = (int)dVar5;
      if (param_2 != 0x8010) {
        iVar2 = param_1 + 0x32d8;
      }
      iVar2 = _gleOffsetLimitImage
                        (param_1 + 0x31b0,*(undefined4 *)(iVar2 + 0x38),
                         *(undefined4 *)(iVar2 + 0x3c),param_3,param_4,param_5);
      if (iVar2 <= *(int *)(iVar3 + 0x38)) {
        if (iVar4 == 0) {
          iVar4 = _glePixelBytes(param_3,param_4);
        }
        if (param_5 == (param_5 / iVar4) * iVar4) {
          if (*(int *)(iVar3 + 0x40) != 0) {
            _gleSynchronizePluginBuffer(param_1,iVar3 + 0x10);
          }
          param_5 = param_5 + *(int *)(iVar3 + 0x30);
          goto LAB_0006a124;
        }
      }
    }
  }
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  uVar1 = 0x502;
LAB_0006a0fc:
  *(undefined4 *)(param_1 + 0x7574) = uVar1;
  return;
}

/* _glGetConvolutionParameteriv_Exec @ 0x6a150 (568 bytes) */
int _glGetConvolutionParameteriv_Exec(param_1, param_2, param_3, param_4)
  int param_1;
  uint param_2;
  uint param_3;
  float *param_4;
{
  undefined4 uVar1;
  float fVar2;
  float *pfVar3;
  
  if (-1 < *(short *)(param_1 + 0x4a10)) {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar1 = 0x502;
    goto LAB_0006a1d8;
  }
  if (param_2 == 0x8011) {
    pfVar3 = (float *)(param_1 + 0x32d8);
LAB_0006a1e0:
    if (param_3 == 0x8018) {
      fVar2 = pfVar3[0xe];
      goto LAB_0006a368;
    }
    if (0x8018 < param_3) {
      if (param_3 != 0x801a) {
        if (param_3 < 0x801a) {
          fVar2 = pfVar3[0xf];
          goto LAB_0006a368;
        }
        if (param_3 != 0x801b) {
          if (param_3 == 0x8154) {
            *param_4 = GH_U2F((unsigned int)((int)*pfVar3));
            param_4[1] = GH_U2F((unsigned int)((int)pfVar3[1]));
            param_4[2] = GH_U2F((unsigned int)((int)pfVar3[2]));
            fVar2 = pfVar3[3];
            goto LAB_0006a30c;
          }
          goto LAB_0006a1c8;
        }
      }
      fVar2 = 1.54143e-44;
LAB_0006a368:
      *param_4 = fVar2;
      return;
    }
    if (param_3 == 0x8014) {
      *param_4 = GH_U2F((unsigned int)((int)pfVar3[4]));
      param_4[1] = GH_U2F((unsigned int)((int)pfVar3[6]));
      param_4[2] = GH_U2F((unsigned int)((int)pfVar3[8]));
      fVar2 = pfVar3[10];
LAB_0006a30c:
      param_4[3] = GH_U2F((unsigned int)((int)fVar2));
      return;
    }
    if (param_3 < 0x8015) {
      if (param_3 == 0x8013) {
        fVar2 = GH_U2F((unsigned int)((uint)*(ushort *)(pfVar3 + 0xc)));
        goto LAB_0006a368;
      }
    }
    else {
      if (param_3 == 0x8015) {
        *param_4 = GH_U2F((unsigned int)((int)pfVar3[5]));
        param_4[1] = GH_U2F((unsigned int)((int)pfVar3[7]));
        param_4[2] = GH_U2F((unsigned int)((int)pfVar3[9]));
        fVar2 = pfVar3[0xb];
        goto LAB_0006a30c;
      }
      if (param_3 == 0x8017) {
        fVar2 = GH_U2F((unsigned int)((uint)*(ushort *)((int)pfVar3 + 0x32)));
        goto LAB_0006a368;
      }
    }
  }
  else if (param_2 < 0x8012) {
    if (param_2 == 0x8010) {
      pfVar3 = (float *)(param_1 + 0x3298);
      goto LAB_0006a1e0;
    }
  }
  else if (param_2 == 0x8012) {
    pfVar3 = (float *)(param_1 + 0x3318);
    goto LAB_0006a1e0;
  }
LAB_0006a1c8:
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  uVar1 = 0x500;
LAB_0006a1d8:
  *(undefined4 *)(param_1 + 0x7574) = uVar1;
  return;
}

/* _glGetConvolutionParameterfv_Exec @ 0x6a388 (404 bytes) */
int _glGetConvolutionParameterfv_Exec(param_1, param_2, param_3, param_4)
  int param_1;
  uint param_2;
  uint param_3;
  float *param_4;
{
  float fVar1;
  undefined4 uVar2;
  float *pfVar3;
  uint local_18 [4];
  
  if (-1 < *(short *)(param_1 + 0x4a10)) {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar2 = 0x502;
    goto LAB_0006a42c;
  }
  if (param_2 != 0x8011) {
    if (param_2 < 0x8012) {
      if (param_2 == 0x8010) {
        pfVar3 = (float *)(param_1 + 0x3298);
        goto LAB_0006a434;
      }
    }
    else if (param_2 == 0x8012) {
      pfVar3 = (float *)(param_1 + 0x3318);
      goto LAB_0006a434;
    }
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar2 = 0x500;
LAB_0006a42c:
    *(undefined4 *)(param_1 + 0x7574) = uVar2;
    return;
  }
  pfVar3 = (float *)(param_1 + 0x32d8);
LAB_0006a434:
  if (param_3 != 0x8015) {
    if (param_3 < 0x8016) {
      if (param_3 == 0x8014) {
        *param_4 = pfVar3[4];
        param_4[1] = pfVar3[6];
        param_4[2] = pfVar3[8];
        fVar1 = pfVar3[10];
        goto LAB_0006a4cc;
      }
    }
    else if (param_3 == 0x8154) {
      *param_4 = *pfVar3;
      param_4[1] = pfVar3[1];
      param_4[2] = pfVar3[2];
      fVar1 = pfVar3[3];
      goto LAB_0006a4cc;
    }
    ((int (*)())_glGetConvolutionParameteriv_Exec)(param_1,param_2,param_3,local_18);
    *param_4 = (float)((double)CONCAT44(0x43300000,local_18[0] ^ 0x80000000) - DOUBLE_00108d58);
    return;
  }
  *param_4 = pfVar3[5];
  param_4[1] = pfVar3[7];
  param_4[2] = pfVar3[9];
  fVar1 = pfVar3[0xb];
LAB_0006a4cc:
  param_4[3] = fVar1;
  return;
}

/* _glGetSeparableFilter_Exec @ 0x6a51c (400 bytes) */
int _glGetSeparableFilter_Exec(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
  int param_5;
  int param_6;
  undefined4 param_7;
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  double dVar7;
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if (param_2 != 0x8012) {
      if (*(int *)(param_1 + 0x7574) != 0) {
        return;
      }
      uVar1 = 0x500;
      goto LAB_0006a64c;
    }
    iVar2 = _CheckTypeFormat(param_4,param_3);
    if (iVar2 != 0) {
      iVar2 = *(int *)(param_1 + 0x4a68);
      if (iVar2 == 0) {
LAB_0006a678:
        _gleGetSeparableFilter(param_1,0x8012,param_3,param_4,param_5,param_6);
        return;
      }
      iVar3 = _gleOffsetLimitImage
                        (param_1 + 0x31b0,*(undefined4 *)(param_1 + 0x3350),1,param_3,param_4,
                         param_5);
      iVar4 = _gleOffsetLimitImage
                        (param_1 + 0x31b0,*(undefined4 *)(param_1 + 0x3354),1,param_3,param_4,
                         param_6);
      iVar6 = *(int *)(iVar2 + 0x38);
      dVar7 = (double)((double (*)())_gleBytesPerElement)(param_4);
      iVar5 = (int)dVar7;
      if ((iVar3 <= iVar6) && (iVar4 <= iVar6)) {
        if (iVar5 == 0) {
          iVar5 = _glePixelBytes(param_3,param_4);
        }
        if ((param_5 == (param_5 / iVar5) * iVar5) && (param_6 == (param_6 / iVar5) * iVar5)) {
          if (*(int *)(iVar2 + 0x40) != 0) {
            _gleSynchronizePluginBuffer(param_1,iVar2 + 0x10);
          }
          param_6 = param_6 + *(int *)(iVar2 + 0x30);
          param_5 = param_5 + *(int *)(iVar2 + 0x30);
          goto LAB_0006a678;
        }
      }
    }
  }
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  uVar1 = 0x502;
LAB_0006a64c:
  *(undefined4 *)(param_1 + 0x7574) = uVar1;
  return;
}

/* _glSeparableFilter2D_Exec @ 0x6a6ac (480 bytes) */
int _glSeparableFilter2D_Exec(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9)
  int param_1;
  int param_2;
  undefined4 param_3;
  int param_4;
  int param_5;
  undefined4 param_6;
  undefined4 param_7;
  int param_8;
  int param_9;
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  double dVar8;
  
  iVar2 = _gleImagingTexFormatToInternal(param_3);
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if ((param_2 != 0x8012) || (iVar2 == 0)) {
      if (*(int *)(param_1 + 0x7574) != 0) {
        return;
      }
      uVar1 = 0x500;
      goto LAB_0006a824;
    }
    iVar3 = _CheckTypeFormat(param_7,param_6);
    if (iVar3 != 0) {
      if ((((0xb < param_4) || (0xb < param_5)) || (param_4 < 0)) || (param_5 < 0)) {
        if (*(int *)(param_1 + 0x7574) != 0) {
          return;
        }
        uVar1 = 0x501;
        goto LAB_0006a824;
      }
      iVar3 = *(int *)(param_1 + 0x4a6c);
      if (iVar3 == 0) {
LAB_0006a850:
        _gleSeparableFilter2D(param_1,0x8012,iVar2,param_4,param_5,param_6,param_7,param_8,param_9);
        return;
      }
      iVar4 = _gleOffsetLimitImage(param_1 + 0x31cc,param_4,1,param_6,param_7,param_8);
      iVar5 = _gleOffsetLimitImage(param_1 + 0x31cc,param_5,1,param_6,param_7,param_9);
      iVar7 = *(int *)(iVar3 + 0x38);
      dVar8 = (double)((double (*)())_gleBytesPerElement)(param_7);
      iVar6 = (int)dVar8;
      if ((iVar4 <= iVar7) && (iVar5 <= iVar7)) {
        if (iVar6 == 0) {
          iVar6 = _glePixelBytes(param_6,param_7);
        }
        if ((param_8 == (param_8 / iVar6) * iVar6) && (param_9 == (param_9 / iVar6) * iVar6)) {
          if (*(int *)(iVar3 + 0x40) != 0) {
            _gleSynchronizePluginBuffer(param_1,iVar3 + 0x10);
          }
          param_9 = param_9 + *(int *)(iVar3 + 0x30);
          param_8 = param_8 + *(int *)(iVar3 + 0x30);
          goto LAB_0006a850;
        }
      }
    }
  }
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  uVar1 = 0x502;
LAB_0006a824:
  *(undefined4 *)(param_1 + 0x7574) = uVar1;
  return;
}

/* _glGetHistogram_Exec @ 0x6a88c (332 bytes) */
int _glGetHistogram_Exec(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  int param_6;
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  double dVar6;
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if (param_2 != 0x8024) {
      if (*(int *)(param_1 + 0x7574) != 0) {
        return;
      }
      uVar1 = 0x500;
      goto LAB_0006a980;
    }
    iVar2 = _CheckTypeFormat(param_5,param_4);
    if (iVar2 != 0) {
      if (*(int *)(param_1 + 0x3388) < 1) {
        return;
      }
      iVar2 = *(int *)(param_1 + 0x4a68);
      if (iVar2 == 0) {
LAB_0006a9a8:
        _gleGetHistogram(param_1,0x8024,param_3,param_4,param_5,param_6);
        return;
      }
      iVar3 = _gleOffsetLimitImage
                        (param_1 + 0x31b0,*(int *)(param_1 + 0x3388),1,param_4,param_5,param_6);
      iVar5 = *(int *)(iVar2 + 0x38);
      dVar6 = (double)((double (*)())_gleBytesPerElement)(param_5);
      iVar4 = (int)dVar6;
      if (iVar3 <= iVar5) {
        if (iVar4 == 0) {
          iVar4 = _glePixelBytes(param_4,param_5);
        }
        if (param_6 == (param_6 / iVar4) * iVar4) {
          if (*(int *)(iVar2 + 0x40) != 0) {
            _gleSynchronizePluginBuffer(param_1,iVar2 + 0x10);
          }
          param_6 = param_6 + *(int *)(iVar2 + 0x30);
          goto LAB_0006a9a8;
        }
      }
    }
  }
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  uVar1 = 0x502;
LAB_0006a980:
  *(undefined4 *)(param_1 + 0x7574) = uVar1;
  return;
}

/* _glGetHistogramParameterfv_Exec @ 0x6a9d8 (100 bytes) */
int _glGetHistogramParameterfv_Exec(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  float *param_4;
{
  uint local_18 [3];
  
  ((int (*)())_glGetHistogramParameteriv_Exec)(param_1,param_2,param_3,local_18);
  *param_4 = (float)((double)CONCAT44(0x43300000,local_18[0] ^ 0x80000000) - DOUBLE_00108d58);
  return;
}

/* _glGetHistogramParameteriv_Exec @ 0x6aa3c (168 bytes) */
int _glGetHistogramParameteriv_Exec(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  undefined4 param_3;
  uint *param_4;
{
  undefined4 uVar1;
  uint uVar2;
  
  if (-1 < *(short *)(param_1 + 0x4a10)) {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar1 = 0x502;
    goto LAB_0006aa8c;
  }
  if (1 < param_2 - 0x8024U) {
switchD_0006aabc_default:
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar1 = 0x500;
LAB_0006aa8c:
    *(undefined4 *)(param_1 + 0x7574) = uVar1;
    return;
  }
  switch(param_3) {
  case 0x8026:
    uVar2 = *(uint *)(param_1 + 0x3388);
    break;
  case 0x8027:
    uVar2 = (uint)*(ushort *)(param_1 + 0x338c);
    break;
  case 0x8028:
  case 0x8029:
  case 0x802a:
  case 0x802b:
  case 0x802c:
    uVar2 = 0x20;
    break;
  case 0x802d:
    uVar2 = (uint)*(byte *)(param_1 + 0x338e);
    break;
  default:
    goto switchD_0006aabc_default;
  }
  *param_4 = uVar2;
  return;
}

/* _glGetMinmax_Exec @ 0x6ab04 (292 bytes) */
int _glGetMinmax_Exec(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  int param_6;
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  double dVar6;
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if (param_2 != 0x802e) {
      if (*(int *)(param_1 + 0x7574) != 0) {
        return;
      }
      uVar1 = 0x500;
      goto LAB_0006abd0;
    }
    iVar4 = *(int *)(param_1 + 0x4a68);
    if (iVar4 == 0) {
LAB_0006abf8:
      _gleGetMinmax(param_1,0x802e,param_3,param_4,param_5,param_6);
      return;
    }
    iVar2 = _gleOffsetLimitImage(param_1 + 0x31b0,2,1,param_4,param_5,param_6);
    iVar5 = *(int *)(iVar4 + 0x38);
    dVar6 = (double)((double (*)())_gleBytesPerElement)(param_5);
    iVar3 = (int)dVar6;
    if (iVar2 <= iVar5) {
      if (iVar3 == 0) {
        iVar3 = _glePixelBytes(param_4,param_5);
      }
      if (param_6 == (param_6 / iVar3) * iVar3) {
        if (*(int *)(iVar4 + 0x40) != 0) {
          _gleSynchronizePluginBuffer(param_1,iVar4 + 0x10);
        }
        param_6 = param_6 + *(int *)(iVar4 + 0x30);
        goto LAB_0006abf8;
      }
    }
  }
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  uVar1 = 0x502;
LAB_0006abd0:
  *(undefined4 *)(param_1 + 0x7574) = uVar1;
  return;
}

/* _glGetMinmaxParameteriv_Exec @ 0x6ac28 (128 bytes) */
int _glGetMinmaxParameteriv_Exec(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  uint *param_4;
{
  undefined4 uVar1;
  uint uVar2;
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if (param_2 == 0x802e) {
      if (param_3 == 0x802f) {
        uVar2 = (uint)*(ushort *)(param_1 + 0x3380);
LAB_0006aca0:
        *param_4 = uVar2;
        return;
      }
      if (param_3 == 0x8030) {
        uVar2 = (uint)*(byte *)(param_1 + 0x3382);
        goto LAB_0006aca0;
      }
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

/* _glGetMinmaxParameterfv_Exec @ 0x6aca8 (100 bytes) */
int _glGetMinmaxParameterfv_Exec(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  float *param_4;
{
  uint local_18 [3];
  
  ((int (*)())_glGetMinmaxParameteriv_Exec)(param_1,param_2,param_3,local_18);
  *param_4 = (float)((double)CONCAT44(0x43300000,local_18[0] ^ 0x80000000) - DOUBLE_00108d58);
  return;
}

/* _glHistogram_Exec @ 0x6ad0c (280 bytes) */
int _glHistogram_Exec(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  undefined4 param_2;
  size_t param_3;
  undefined4 param_4;
  int param_5;
{
  undefined4 uVar1;
  int iVar2;
  void *pvVar3;
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if (((param_3 & param_3 - 1) == 0) && (-1 < (int)param_3)) {
      if ((int)param_3 < 0x20001) {
        iVar2 = _CheckInternalFormat(param_4);
        if (iVar2 != 0) {
          *(short *)(param_1 + 0x338c) = (short)param_4;
          *(byte *)(param_1 + 0x338e) = (byte)((uint)-param_5 >> 0x1f);
          *(size_t *)(param_1 + 0x3388) = param_3;
          if (*(void **)(param_1 + 0x3384) != (void *)0x0) {
            _free(*(void **)(param_1 + 0x3384));
          }
          if ((int)param_3 < 1) {
            param_3 = 1;
          }
          pvVar3 = _calloc(param_3,0x10);
          *(void **)(param_1 + 0x3384) = pvVar3;
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
        uVar1 = 0x8031;
      }
    }
    else {
      if (*(int *)(param_1 + 0x7574) != 0) {
        return;
      }
      uVar1 = 0x501;
    }
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

/* _glMinmax_Exec @ 0x6ae24 (120 bytes) */
int _glMinmax_Exec(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  undefined4 param_3;
  int param_4;
{
  int iVar1;
  
  if ((param_2 == 0x802e) && (iVar1 = _CheckInternalFormat(param_3), iVar1 != 0)) {
    *(short *)(param_1 + 0x3380) = (short)param_3;
    *(byte *)(param_1 + 0x3382) = (byte)((uint)-param_4 >> 0x1f);
  }
  else if (*(int *)(param_1 + 0x7574) == 0) {
    *(undefined4 *)(param_1 + 0x7574) = 0x500;
  }
  return;
}

/* _glResetHistogram_Exec @ 0x6ae9c (172 bytes) */
int _glResetHistogram_Exec(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if (param_2 == 0x8024) {
      iVar4 = 0;
      if (0 < *(int *)(param_1 + 0x3388)) {
        iVar1 = (int)*(float *)(param_1 + 0x20);
        do {
          iVar2 = iVar4 * 0x10;
          iVar4 = iVar4 + 1;
          *(int *)(iVar2 + *(int *)(param_1 + 0x3384)) = iVar1;
          *(int *)(iVar2 + *(int *)(param_1 + 0x3384) + 4) = iVar1;
          *(int *)(iVar2 + *(int *)(param_1 + 0x3384) + 8) = iVar1;
          *(int *)(iVar2 + *(int *)(param_1 + 0x3384) + 0xc) = iVar1;
        } while (iVar4 < *(int *)(param_1 + 0x3388));
        return;
      }
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

/* _glResetMinmax_Exec @ 0x6af48 (172 bytes) */
int _glResetMinmax_Exec(param_1, param_2)
  int param_1;
  int param_2;
{
  undefined4 uVar1;
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if (param_2 == 0x802e) {
      **(undefined4 **)(param_1 + 0x337c) = *(undefined4 *)(param_1 + 0x24);
      *(undefined4 *)(*(int *)(param_1 + 0x337c) + 4) = *(undefined4 *)(param_1 + 0x24);
      *(undefined4 *)(*(int *)(param_1 + 0x337c) + 8) = *(undefined4 *)(param_1 + 0x24);
      *(undefined4 *)(*(int *)(param_1 + 0x337c) + 0xc) = *(undefined4 *)(param_1 + 0x24);
      *(undefined4 *)(*(int *)(param_1 + 0x337c) + 0x10) = *(undefined4 *)(param_1 + 0x20);
      *(undefined4 *)(*(int *)(param_1 + 0x337c) + 0x14) = *(undefined4 *)(param_1 + 0x20);
      *(undefined4 *)(*(int *)(param_1 + 0x337c) + 0x18) = *(undefined4 *)(param_1 + 0x20);
      *(undefined4 *)(*(int *)(param_1 + 0x337c) + 0x1c) = *(undefined4 *)(param_1 + 0x20);
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

/* _glConvolutionFilter1D_CompExec @ 0x6aff4 (96 bytes) */
int _glConvolutionFilter1D_CompExec(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  _glConvolutionFilter1D_Comp(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  ((int (*)())_glConvolutionFilter1D_Exec)(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  return;
}

/* _glConvolutionFilter2D_CompExec @ 0x6b054 (104 bytes) */
int _glConvolutionFilter2D_CompExec(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  _glConvolutionFilter2D_Comp(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
  ((int (*)())_glConvolutionFilter2D_Exec)(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
  return;
}

/* _glConvolutionParameterf_CompExec @ 0x6b0bc (80 bytes) */
void _glConvolutionParameterf_CompExec(undefined4 param_1,undefined4 param_2,undefined4 param_3,double fparam_1)
{
  ((undefined4 (*)())_glConvolutionParameterf_Comp)(param_1,param_2,param_3,fparam_1);
  ((void (*)())_glConvolutionParameterf_Exec)(param_1,param_2,param_3,fparam_1);
  return;
}

/* _glConvolutionParameterfv_CompExec @ 0x6b10c (72 bytes) */
int _glConvolutionParameterfv_CompExec(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  _glConvolutionParameterfv_Comp(param_1,param_2,param_3,param_4);
  ((int (*)())_glConvolutionParameterfv_Exec)(param_1,param_2,param_3,param_4);
  return;
}

/* _glConvolutionParameteri_CompExec @ 0x6b154 (72 bytes) */
int _glConvolutionParameteri_CompExec(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  _glConvolutionParameteri_Comp(param_1,param_2,param_3,param_4);
  ((int (*)())_glConvolutionParameteri_Exec)(param_1,param_2,param_3,param_4);
  return;
}

/* _glConvolutionParameteriv_CompExec @ 0x6b19c (72 bytes) */
int _glConvolutionParameteriv_CompExec(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  _glConvolutionParameteriv_Comp(param_1,param_2,param_3,param_4);
  ((int (*)())_glConvolutionParameteriv_Exec)(param_1,param_2,param_3,param_4);
  return;
}

/* _glCopyConvolutionFilter1D_CompExec @ 0x6b1e4 (88 bytes) */
int _glCopyConvolutionFilter1D_CompExec(param_1, param_2, param_3, param_4, param_5, param_6)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
{
  _glCopyConvolutionFilter1D_Comp(param_1,param_2,param_3,param_4,param_5,param_6);
  ((int (*)())_glCopyConvolutionFilter1D_Exec)(param_1,param_2,param_3,param_4,param_5,param_6);
  return;
}

/* _glCopyConvolutionFilter2D_CompExec @ 0x6b23c (96 bytes) */
int _glCopyConvolutionFilter2D_CompExec(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  _glCopyConvolutionFilter2D_Comp(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  ((int (*)())_glCopyConvolutionFilter2D_Exec)(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  return;
}

/* _glSeparableFilter2D_CompExec @ 0x6b29c (116 bytes) */
int _glSeparableFilter2D_CompExec(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9)
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
  _glSeparableFilter2D_Comp(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9)
  ;
  ((int (*)())_glSeparableFilter2D_Exec)(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9)
  ;
  return;
}

/* _glHistogram_CompExec @ 0x6b310 (80 bytes) */
int _glHistogram_CompExec(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  _glHistogram_Comp(param_1,param_2,param_3,param_4,param_5);
  ((int (*)())_glHistogram_Exec)(param_1,param_2,param_3,param_4,param_5);
  return;
}

/* _glMinmax_CompExec @ 0x6b360 (72 bytes) */
int _glMinmax_CompExec(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  _glMinmax_Comp(param_1,param_2,param_3,param_4);
  ((int (*)())_glMinmax_Exec)(param_1,param_2,param_3,param_4);
  return;
}

/* _glResetHistogram_CompExec @ 0x6b3a8 (56 bytes) */
int _glResetHistogram_CompExec(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  ((int (*)())_glResetHistogram_Comp)(param_1,param_2);
  ((int (*)())_glResetHistogram_Exec)(param_1,param_2);
  return;
}

/* _glResetMinmax_CompExec @ 0x6b3e0 (56 bytes) */
int _glResetMinmax_CompExec(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  ((int (*)())_glResetMinmax_Comp)(param_1,param_2);
  ((int (*)())_glResetMinmax_Exec)(param_1,param_2);
  return;
}

/* _glLightf_ListExec @ 0x6b418 (52 bytes) */
int _glLightf_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  ((void (*)())_glLightf_Exec)(param_1,*param_2,param_2[1],(double)GH_U2F((unsigned int)(param_2[2])));
  return 0xc;
}

/* _glLightf_Comp @ 0x6b44c (100 bytes) */
undefined4 * _glLightf_Comp(undefined4 param_1,undefined4 param_2,undefined4 param_3,double fparam_1)
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glLightf_ListExec_00110144,0xc);
  if (puVar1 != (undefined4 *)0x0) {
    puVar1[2] = (float)fparam_1;
    *puVar1 = param_2;
    puVar1[1] = param_3;
  }
  return puVar1;
}

/* _glLightf_Exec @ 0x6b4b0 (724 bytes) */
void _glLightf_Exec(int param_1,int param_2,undefined4 param_3,double fparam_1)
{
  byte bVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  double dVar6;
  
  if (-1 < *(short *)(param_1 + 0x4a10)) {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar2 = 0x502;
    goto LAB_0006b764;
  }
  uVar5 = param_2 - 0x4000;
  if (uVar5 < 8) {
    iVar3 = param_1 + uVar5 * 0x80;
    switch(param_3) {
    case 0x1205:
      if (((double)FLOAT_00108e50 <= fparam_1) &&
         (fparam_1 <=
          (double)(float)((double)CONCAT44(0x43300000,
                                           *(uint *)(*(int *)(param_1 + 0x468c) + 0xa4) ^ 0x80000000
                                          ) - DOUBLE_00108d58))) {
        *(float *)(iVar3 + 0x287c) = (float)fparam_1;
        _gleUpdateLightExponents(param_1,uVar5);
        if (*(int *)(param_1 + 0x5434) == 0) {
          bVar1 = *(byte *)(uVar5 * 7 + *(int *)(param_1 + 0x5420) + 0x25d);
        }
        else {
          bVar1 = *(byte *)(uVar5 * 7 + *(int *)(*(int *)(param_1 + 0x5430) + 0x20) + 0x291);
        }
        iVar4 = (bVar1 >> 3 & 0x1c) + param_1;
        iVar3 = *(int *)(param_1 + 0x5424);
        *(uint *)(iVar4 + 0x324) = *(uint *)(iVar4 + 0x324) | 1 << (bVar1 & 0x1f);
        bVar1 = *(byte *)(uVar5 * 7 + iVar3 + 0x25d);
        goto LAB_0006b6cc;
      }
      break;
    case 0x1206:
      if ((fparam_1 < (double)FLOAT_00108e50) || ((double)FLOAT_00108e88 < fparam_1)) {
        if (fparam_1 != (double)FLOAT_00108e8c) break;
        *(undefined4 *)(iVar3 + 0x286c) = 0xbf800000;
        *(undefined4 *)(iVar3 + 0x2890) = 0;
      }
      else {
        *(float *)(iVar3 + 0x2890) = (float)fparam_1;
        dVar6 = (double)_cos((double)(float)(fparam_1 * (double)FLOAT_00108e84));
        *(float *)(iVar3 + 0x286c) = (float)dVar6;
      }
      _gleUpdateLightExponents(param_1,uVar5);
      if (*(int *)(param_1 + 0x5434) == 0) {
        bVar1 = *(byte *)(uVar5 * 7 + *(int *)(param_1 + 0x5420) + 0x25c);
      }
      else {
        bVar1 = *(byte *)(uVar5 * 7 + *(int *)(*(int *)(param_1 + 0x5430) + 0x20) + 0x290);
      }
      iVar4 = (bVar1 >> 3 & 0x1c) + param_1;
      iVar3 = *(int *)(param_1 + 0x5424);
      *(uint *)(iVar4 + 0x324) = *(uint *)(iVar4 + 0x324) | 1 << (bVar1 & 0x1f);
      bVar1 = *(byte *)(uVar5 * 7 + iVar3 + 0x25c);
LAB_0006b6cc:
      iVar3 = (bVar1 >> 3 & 0x1c) + param_1;
      *(uint *)(iVar3 + 0x348) = *(uint *)(iVar3 + 0x348) | 1 << (bVar1 & 0x1f);
LAB_0006b76c:
      *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 4 << (uVar5 * 2 & 0x3e);
      return;
    case 0x1207:
      if ((double)FLOAT_00108e50 <= fparam_1) {
        *(float *)(iVar3 + 0x2870) = (float)fparam_1;
LAB_0006b744:
        _gleUpdateLightAttenuation(param_1,uVar5);
        goto LAB_0006b76c;
      }
      break;
    case 0x1208:
      if ((double)FLOAT_00108e50 <= fparam_1) {
        *(float *)(iVar3 + 0x2874) = (float)fparam_1;
        goto LAB_0006b744;
      }
      break;
    case 0x1209:
      if ((double)FLOAT_00108e50 <= fparam_1) {
        *(float *)(iVar3 + 0x2878) = (float)fparam_1;
        goto LAB_0006b744;
      }
      break;
    default:
      goto switchD_0006b52c_default;
    }
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar2 = 0x501;
  }
  else {
switchD_0006b52c_default:
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar2 = 0x500;
  }
LAB_0006b764:
  *(undefined4 *)(param_1 + 0x7574) = uVar2;
  return;
}

/* _glLightf_CompExec @ 0x6b798 (80 bytes) */
void _glLightf_CompExec(undefined4 param_1,undefined4 param_2,undefined4 param_3,double fparam_1)
{
  ((undefined4 * (*)())_glLightf_Comp)(param_1,param_2,param_3,fparam_1);
  ((void (*)())_glLightf_Exec)(param_1,param_2,param_3,fparam_1);
  return;
}

/* _glLightfv_ListExec @ 0x6b7e8 (52 bytes) */
undefined4 _glLightfv_ListExec(undefined4 param_1,undefined4 *param_2,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10)
{
  double in_stack_ffffffb8;
  double in_stack_ffffffc0;
  
  ((void (*)())_glLightfv_Exec)(param_1,*param_2,param_2[1],param_2 + 2,fparam_1,fparam_2,fparam_3,fparam_4,
                  fparam_5,fparam_6,fparam_7,fparam_8,in_stack_ffffffb8,in_stack_ffffffc0);
  return 0x18;
}

/* _glLightfv_Comp @ 0x6b81c (200 bytes) */
int _glLightfv_Comp(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 *param_4;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glLightfv_ListExec_00110140,0x18);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_2;
    puVar1[1] = param_3;
    switch(param_3) {
    case 0x1200:
    case 0x1201:
    case 0x1202:
    case 0x1203:
      puVar1[2] = *param_4;
      puVar1[3] = param_4[1];
      puVar1[4] = param_4[2];
      puVar1[5] = param_4[3];
      break;
    case 0x1204:
      puVar1[2] = *param_4;
      puVar1[3] = param_4[1];
      puVar1[4] = param_4[2];
      break;
    case 0x1205:
    case 0x1206:
    case 0x1207:
    case 0x1208:
    case 0x1209:
      puVar1[2] = *param_4;
    }
  }
  return puVar1;
}

/* _glLightfv_CompExec @ 0x6b90c (72 bytes) */
int _glLightfv_CompExec(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  undefined4 in_LR;
  double fparam_1;
  double in_f2;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  
  ((int (*)())_glLightfv_Comp)(param_1,param_2,param_3,param_4);
  ((void (*)())_glLightfv_Exec)(param_1,param_2,param_3,param_4,fparam_1,in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8
                  ,(double)CONCAT44(in_LR,(*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0xc))),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)));
  return;
}

/* _glLighti_ListExec @ 0x6b954 (52 bytes) */
undefined4 _glLighti_ListExec(undefined4 param_1,undefined4 *param_2,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12)
{
  double in_stack_ffffffb8;
  double in_stack_ffffffc0;
  double in_stack_ffffffc8;
  double in_stack_ffffffd0;
  
  ((double (*)())_glLighti_Exec)(param_1,*param_2,param_2[1],param_2[2],fparam_1,fparam_2,fparam_3,fparam_4,fparam_5
                 ,fparam_6,fparam_7,fparam_8,in_stack_ffffffb8,in_stack_ffffffc0,in_stack_ffffffc8,
                 in_stack_ffffffd0);
  return 0xc;
}

/* _glLighti_Comp @ 0x6b988 (92 bytes) */
int _glLighti_Comp(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glLighti_ListExec_0011013c,0xc);
  if (puVar1 != (undefined4 *)0x0) {
    puVar1[2] = param_4;
    *puVar1 = param_2;
    puVar1[1] = param_3;
  }
  return puVar1;
}

/* _glLighti_Exec @ 0x6b9e4 (756 bytes) */
double _glLighti_Exec(int param_1,int param_2,undefined4 param_3,uint param_4,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12)
{
  float fVar1;
  byte bVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  double dVar7;
  
  if (-1 < *(short *)(param_1 + 0x4a10)) {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return fparam_1;
    }
    uVar3 = 0x502;
    goto LAB_0006bcb8;
  }
  uVar6 = param_2 - 0x4000;
  if (uVar6 < 8) {
    iVar4 = param_1 + uVar6 * 0x80;
    fVar1 = (float)((double)CONCAT44(0x43300000,param_4 ^ 0x80000000) - DOUBLE_00108d58);
    switch(param_3) {
    case 0x1205:
      if ((FLOAT_00108e50 <= fVar1) &&
         (fVar1 <= (float)((double)CONCAT44(0x43300000,
                                            *(uint *)(*(int *)(param_1 + 0x468c) + 0xa4) ^
                                            0x80000000) - DOUBLE_00108d58))) {
        *(float *)(iVar4 + 0x287c) = fVar1;
        dVar7 = (double)_gleUpdateLightExponents(param_1,uVar6);
        if (*(int *)(param_1 + 0x5434) == 0) {
          bVar2 = *(byte *)(uVar6 * 7 + *(int *)(param_1 + 0x5420) + 0x25d);
        }
        else {
          bVar2 = *(byte *)(uVar6 * 7 + *(int *)(*(int *)(param_1 + 0x5430) + 0x20) + 0x291);
        }
        iVar5 = (bVar2 >> 3 & 0x1c) + param_1;
        iVar4 = *(int *)(param_1 + 0x5424);
        *(uint *)(iVar5 + 0x324) = *(uint *)(iVar5 + 0x324) | 1 << (bVar2 & 0x1f);
        bVar2 = *(byte *)(uVar6 * 7 + iVar4 + 0x25d);
        goto LAB_0006bc20;
      }
      break;
    case 0x1206:
      if ((fVar1 < FLOAT_00108e50) || (FLOAT_00108e88 < fVar1)) {
        if (fVar1 != FLOAT_00108e8c) break;
        *(undefined4 *)(iVar4 + 0x286c) = 0xbf800000;
        *(undefined4 *)(iVar4 + 0x2890) = 0;
      }
      else {
        *(float *)(iVar4 + 0x2890) = fVar1;
        dVar7 = (double)_cos((double)(fVar1 * FLOAT_00108e84));
        *(float *)(iVar4 + 0x286c) = (float)dVar7;
      }
      dVar7 = (double)_gleUpdateLightExponents(param_1,uVar6);
      if (*(int *)(param_1 + 0x5434) == 0) {
        bVar2 = *(byte *)(uVar6 * 7 + *(int *)(param_1 + 0x5420) + 0x25c);
      }
      else {
        bVar2 = *(byte *)(uVar6 * 7 + *(int *)(*(int *)(param_1 + 0x5430) + 0x20) + 0x290);
      }
      iVar5 = (bVar2 >> 3 & 0x1c) + param_1;
      iVar4 = *(int *)(param_1 + 0x5424);
      *(uint *)(iVar5 + 0x324) = *(uint *)(iVar5 + 0x324) | 1 << (bVar2 & 0x1f);
      bVar2 = *(byte *)(uVar6 * 7 + iVar4 + 0x25c);
LAB_0006bc20:
      iVar4 = (bVar2 >> 3 & 0x1c) + param_1;
      *(uint *)(iVar4 + 0x348) = *(uint *)(iVar4 + 0x348) | 1 << (bVar2 & 0x1f);
LAB_0006bcc0:
      *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 4 << (uVar6 * 2 & 0x3e);
      return dVar7;
    case 0x1207:
      if (FLOAT_00108e50 <= fVar1) {
        *(float *)(iVar4 + 0x2870) = fVar1;
LAB_0006bc98:
        dVar7 = (double)_gleUpdateLightAttenuation(param_1,uVar6);
        goto LAB_0006bcc0;
      }
      break;
    case 0x1208:
      if (FLOAT_00108e50 <= fVar1) {
        *(float *)(iVar4 + 0x2874) = fVar1;
        goto LAB_0006bc98;
      }
      break;
    case 0x1209:
      if (FLOAT_00108e50 <= fVar1) {
        *(float *)(iVar4 + 0x2878) = fVar1;
        goto LAB_0006bc98;
      }
      break;
    default:
      goto switchD_0006ba80_default;
    }
    if (*(int *)(param_1 + 0x7574) != 0) {
      return fparam_1;
    }
    uVar3 = 0x501;
  }
  else {
switchD_0006ba80_default:
    if (*(int *)(param_1 + 0x7574) != 0) {
      return fparam_1;
    }
    uVar3 = 0x500;
  }
LAB_0006bcb8:
  *(undefined4 *)(param_1 + 0x7574) = uVar3;
  return fparam_1;
}

/* _glLighti_CompExec @ 0x6bcec (72 bytes) */
int _glLighti_CompExec(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  unsigned int ghidra_home[8] = { param_1, param_2, param_3, param_4, 0, 0, 0, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  undefined4 in_LR;
  double fparam_1;
  double in_f2;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  
  ((int (*)())_glLighti_Comp)(param_1,param_2,param_3,param_4);
  ((double (*)())_glLighti_Exec)(param_1,param_2,param_3,param_4,fparam_1,in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8,
                 (double)CONCAT44(in_LR,(*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0xc))),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),(*(double *)((unsigned char *)ghidra_home + 0)),
                 (*(double *)((unsigned char *)ghidra_home + 8)));
  return;
}

/* _glLightiv_ListExec @ 0x6bd34 (52 bytes) */
undefined4 _glLightiv_ListExec(undefined4 param_1,undefined4 *param_2,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12)
{
  double in_stack_ffffffb8;
  double in_stack_ffffffc0;
  double in_stack_ffffffc8;
  double in_stack_ffffffd0;
  
  ((void (*)())_glLightiv_Exec)(param_1,*param_2,param_2[1],param_2 + 2,fparam_1,fparam_2,fparam_3,fparam_4,
                  fparam_5,fparam_6,fparam_7,fparam_8,in_stack_ffffffb8,in_stack_ffffffc0,
                  in_stack_ffffffc8,in_stack_ffffffd0);
  return 0x18;
}

/* _glLightiv_Comp @ 0x6bd68 (200 bytes) */
int _glLightiv_Comp(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 *param_4;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glLightiv_ListExec_00110138,0x18);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_2;
    puVar1[1] = param_3;
    switch(param_3) {
    case 0x1200:
    case 0x1201:
    case 0x1202:
    case 0x1203:
      puVar1[2] = *param_4;
      puVar1[3] = param_4[1];
      puVar1[4] = param_4[2];
      puVar1[5] = param_4[3];
      break;
    case 0x1204:
      puVar1[2] = *param_4;
      puVar1[3] = param_4[1];
      puVar1[4] = param_4[2];
      break;
    case 0x1205:
    case 0x1206:
    case 0x1207:
    case 0x1208:
    case 0x1209:
      puVar1[2] = *param_4;
    }
  }
  return puVar1;
}

/* _glLightiv_Exec @ 0x6be58 (2268 bytes) */
void _glLightiv_Exec(int param_1,int param_2,undefined4 param_3,uint *param_4,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12)
{
  float fVar1;
  byte bVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  double dVar6;
  undefined4 uVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  double dVar12;
  double in_stack_ffffffa8;
  double in_stack_ffffffb0;
  
  dVar6 = DOUBLE_00108d88;
  dVar12 = DOUBLE_00108d58;
  if (-1 < *(short *)(param_1 + 0x4a10)) {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar7 = 0x502;
    goto LAB_0006c728;
  }
  uVar11 = param_2 - 0x4000;
  if (7 < uVar11) {
switchD_0006bed0_default:
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar7 = 0x500;
    goto LAB_0006c728;
  }
  iVar8 = param_1 + uVar11 * 0x80;
  switch(param_3) {
  case 0x1200:
    *(float *)(iVar8 + 0x2820) =
         (float)((double)(float)((double)CONCAT44(0x43300000,*param_4 ^ 0x80000000) -
                                DOUBLE_00108d58) * DOUBLE_00108d88);
    *(float *)(iVar8 + 0x2824) =
         (float)((double)(float)((double)CONCAT44(0x43300000,param_4[1] ^ 0x80000000) - dVar12) *
                dVar6);
    *(float *)(iVar8 + 0x2828) =
         (float)((double)(float)((double)CONCAT44(0x43300000,param_4[2] ^ 0x80000000) - dVar12) *
                dVar6);
    *(float *)(iVar8 + 0x282c) =
         (float)((double)(float)((double)CONCAT44(0x43300000,param_4[3] ^ 0x80000000) - dVar12) *
                dVar6);
    *(byte *)(*(int *)(param_1 + 0x4dd0) + 0x234) =
         *(byte *)(*(int *)(param_1 + 0x4dd0) + 0x234) | 0x1e;
    *(byte *)(*(int *)(param_1 + 0x4dd4) + 0x234) =
         *(byte *)(*(int *)(param_1 + 0x4dd4) + 0x234) | 0x1e;
    if (*(int *)(param_1 + 0x5434) == 0) {
      bVar2 = *(byte *)(uVar11 * 7 + *(int *)(param_1 + 0x5420) + 600);
    }
    else {
      bVar2 = *(byte *)(uVar11 * 7 + *(int *)(*(int *)(param_1 + 0x5430) + 0x20) + 0x28c);
    }
    iVar10 = (bVar2 >> 3 & 0x1c) + param_1;
    iVar8 = *(int *)(param_1 + 0x5424);
    *(uint *)(iVar10 + 0x324) = *(uint *)(iVar10 + 0x324) | 1 << (bVar2 & 0x1f);
    uVar9 = (uint)*(byte *)(uVar11 * 7 + iVar8 + 600);
    break;
  case 0x1201:
    *(float *)(iVar8 + 0x2830) =
         (float)((double)(float)((double)CONCAT44(0x43300000,*param_4 ^ 0x80000000) -
                                DOUBLE_00108d58) * DOUBLE_00108d88);
    *(float *)(iVar8 + 0x2834) =
         (float)((double)(float)((double)CONCAT44(0x43300000,param_4[1] ^ 0x80000000) - dVar12) *
                dVar6);
    *(float *)(iVar8 + 0x2838) =
         (float)((double)(float)((double)CONCAT44(0x43300000,param_4[2] ^ 0x80000000) - dVar12) *
                dVar6);
    *(float *)(iVar8 + 0x283c) =
         (float)((double)(float)((double)CONCAT44(0x43300000,param_4[3] ^ 0x80000000) - dVar12) *
                dVar6);
    *(byte *)(*(int *)(param_1 + 0x4dd0) + 0x234) =
         *(byte *)(*(int *)(param_1 + 0x4dd0) + 0x234) | 0x1e;
    *(byte *)(*(int *)(param_1 + 0x4dd4) + 0x234) =
         *(byte *)(*(int *)(param_1 + 0x4dd4) + 0x234) | 0x1e;
    if (*(int *)(param_1 + 0x5434) == 0) {
      bVar2 = *(byte *)(uVar11 * 7 + *(int *)(param_1 + 0x5420) + 0x259);
    }
    else {
      bVar2 = *(byte *)(uVar11 * 7 + *(int *)(*(int *)(param_1 + 0x5430) + 0x20) + 0x28d);
    }
    iVar10 = (bVar2 >> 3 & 0x1c) + param_1;
    iVar8 = *(int *)(param_1 + 0x5424);
    *(uint *)(iVar10 + 0x324) = *(uint *)(iVar10 + 0x324) | 1 << (bVar2 & 0x1f);
    uVar9 = (uint)*(byte *)(uVar11 * 7 + iVar8 + 0x259);
    break;
  case 0x1202:
    *(float *)(iVar8 + 0x2840) =
         (float)((double)(float)((double)CONCAT44(0x43300000,*param_4 ^ 0x80000000) -
                                DOUBLE_00108d58) * DOUBLE_00108d88);
    *(float *)(iVar8 + 0x2844) =
         (float)((double)(float)((double)CONCAT44(0x43300000,param_4[1] ^ 0x80000000) - dVar12) *
                dVar6);
    *(float *)(iVar8 + 0x2848) =
         (float)((double)(float)((double)CONCAT44(0x43300000,param_4[2] ^ 0x80000000) - dVar12) *
                dVar6);
    *(float *)(iVar8 + 0x284c) =
         (float)((double)(float)((double)CONCAT44(0x43300000,param_4[3] ^ 0x80000000) - dVar12) *
                dVar6);
    *(byte *)(*(int *)(param_1 + 0x4dd0) + 0x234) =
         *(byte *)(*(int *)(param_1 + 0x4dd0) + 0x234) | 0x1e;
    *(byte *)(*(int *)(param_1 + 0x4dd4) + 0x234) =
         *(byte *)(*(int *)(param_1 + 0x4dd4) + 0x234) | 0x1e;
    if (*(int *)(param_1 + 0x5434) == 0) {
      bVar2 = *(byte *)(uVar11 * 7 + *(int *)(param_1 + 0x5420) + 0x25a);
    }
    else {
      bVar2 = *(byte *)(uVar11 * 7 + *(int *)(*(int *)(param_1 + 0x5430) + 0x20) + 0x28e);
    }
    iVar10 = (bVar2 >> 3 & 0x1c) + param_1;
    iVar8 = *(int *)(param_1 + 0x5424);
    *(uint *)(iVar10 + 0x324) = *(uint *)(iVar10 + 0x324) | 1 << (bVar2 & 0x1f);
    uVar9 = (uint)*(byte *)(uVar11 * 7 + iVar8 + 0x25a);
    break;
  case 0x1203:
    *(float *)(iVar8 + 0x2850) =
         (float)((double)CONCAT44(0x43300000,*param_4 ^ 0x80000000) - DOUBLE_00108d58);
    *(float *)(iVar8 + 0x2854) =
         (float)((double)CONCAT44(0x43300000,param_4[1] ^ 0x80000000) - dVar12);
    *(float *)(iVar8 + 0x2858) =
         (float)((double)CONCAT44(0x43300000,param_4[2] ^ 0x80000000) - dVar12);
    fVar3 = *(float *)(iVar8 + 0x2854);
    fVar4 = *(float *)(iVar8 + 0x2850);
    fVar5 = *(float *)(iVar8 + 0x2858);
    fVar1 = (float)((double)CONCAT44(0x43300000,param_4[3] ^ 0x80000000) - dVar12);
    *(float *)(iVar8 + 0x285c) = fVar1;
    *(float *)(iVar8 + 0x2850) =
         fVar1 * *(float *)(param_1 + 0x1cf0) +
         (fVar5 * *(float *)(param_1 + 0x1ce0) +
         (fVar4 * *(float *)(param_1 + 0x1cc0) + fVar3 * *(float *)(param_1 + 0x1cd0)));
    *(float *)(iVar8 + 0x2854) =
         fVar1 * *(float *)(param_1 + 0x1cf4) +
         (fVar5 * *(float *)(param_1 + 0x1ce4) +
         (fVar4 * *(float *)(param_1 + 0x1cc4) + fVar3 * *(float *)(param_1 + 0x1cd4)));
    *(float *)(iVar8 + 0x2858) =
         fVar1 * *(float *)(param_1 + 0x1cf8) +
         (fVar5 * *(float *)(param_1 + 0x1ce8) +
         (fVar4 * *(float *)(0x1cc8 + param_1) + fVar3 * *(float *)(param_1 + 0x1cd8)));
    *(float *)(iVar8 + 0x285c) =
         fVar1 * *(float *)(param_1 + 0x1cfc) +
         (fVar5 * *(float *)(param_1 + 0x1cec) +
         (fVar4 * *(float *)(param_1 + 0x1ccc) + fVar3 * *(float *)(param_1 + 0x1cdc)));
    ((double (*)())_gleUpdateLightPosition)(param_1,uVar11,fparam_1);
    goto LAB_0006c730;
  case 0x1204:
    *(float *)(iVar8 + 0x2860) =
         (float)((double)CONCAT44(0x43300000,*param_4 ^ 0x80000000) - DOUBLE_00108d58);
    *(float *)(iVar8 + 0x2864) =
         (float)((double)CONCAT44(0x43300000,param_4[1] ^ 0x80000000) - dVar12);
    *(float *)(iVar8 + 0x2868) =
         (float)((double)CONCAT44(0x43300000,param_4[2] ^ 0x80000000) - dVar12);
    ((void (*)())_gleTransformLightDirection)(param_1,uVar11,fparam_1,fparam_2,fparam_3,fparam_4,fparam_5,fparam_6,fparam_7,
               fparam_8,in_stack_ffffffa8,in_stack_ffffffb0);
    goto LAB_0006c730;
  case 0x1205:
    fVar1 = (float)((double)CONCAT44(0x43300000,*param_4 ^ 0x80000000) - DOUBLE_00108d58);
    if ((fVar1 < FLOAT_00108e50) ||
       ((float)((double)CONCAT44(0x43300000,
                                 *(uint *)(*(int *)(param_1 + 0x468c) + 0xa4) ^ 0x80000000) -
               DOUBLE_00108d58) < fVar1)) goto LAB_0006c6f0;
    *(float *)(iVar8 + 0x287c) = fVar1;
    _gleUpdateLightExponents(param_1,uVar11);
    if (*(int *)(param_1 + 0x5434) == 0) {
      bVar2 = *(byte *)(uVar11 * 7 + *(int *)(param_1 + 0x5420) + 0x25d);
    }
    else {
      bVar2 = *(byte *)(uVar11 * 7 + *(int *)(*(int *)(param_1 + 0x5430) + 0x20) + 0x291);
    }
    iVar10 = (bVar2 >> 3 & 0x1c) + param_1;
    iVar8 = *(int *)(param_1 + 0x5424);
    *(uint *)(iVar10 + 0x324) = *(uint *)(iVar10 + 0x324) | 1 << (bVar2 & 0x1f);
    uVar9 = (uint)*(byte *)(uVar11 * 7 + iVar8 + 0x25d);
    break;
  case 0x1206:
    fVar1 = (float)((double)CONCAT44(0x43300000,*param_4 ^ 0x80000000) - DOUBLE_00108d58);
    if ((fVar1 < FLOAT_00108e50) || (FLOAT_00108e88 < fVar1)) {
      if (fVar1 != FLOAT_00108e8c) goto LAB_0006c6f0;
      *(undefined4 *)(iVar8 + 0x286c) = 0xbf800000;
      *(undefined4 *)(iVar8 + 0x2890) = 0;
    }
    else {
      *(float *)(iVar8 + 0x2890) = fVar1;
      dVar12 = (double)_cos((double)(fVar1 * FLOAT_00108e84));
      *(float *)(iVar8 + 0x286c) = (float)dVar12;
    }
    _gleUpdateLightExponents(param_1,uVar11);
    if (*(int *)(param_1 + 0x5434) == 0) {
      bVar2 = *(byte *)(uVar11 * 7 + *(int *)(param_1 + 0x5420) + 0x25c);
    }
    else {
      bVar2 = *(byte *)(uVar11 * 7 + *(int *)(*(int *)(param_1 + 0x5430) + 0x20) + 0x290);
    }
    iVar10 = (bVar2 >> 3 & 0x1c) + param_1;
    iVar8 = *(int *)(param_1 + 0x5424);
    *(uint *)(iVar10 + 0x324) = *(uint *)(iVar10 + 0x324) | 1 << (bVar2 & 0x1f);
    uVar9 = (uint)*(byte *)(uVar11 * 7 + iVar8 + 0x25c);
    break;
  case 0x1207:
    fVar1 = (float)((double)CONCAT44(0x43300000,*param_4 ^ 0x80000000) - DOUBLE_00108d58);
    if (FLOAT_00108e50 <= fVar1) {
      *(float *)(iVar8 + 0x2870) = fVar1;
LAB_0006c708:
      _gleUpdateLightAttenuation(param_1,uVar11);
      goto LAB_0006c730;
    }
    goto LAB_0006c6f0;
  case 0x1208:
    fVar1 = (float)((double)CONCAT44(0x43300000,*param_4 ^ 0x80000000) - DOUBLE_00108d58);
    if (FLOAT_00108e50 <= fVar1) {
      *(float *)(iVar8 + 0x2874) = fVar1;
      goto LAB_0006c708;
    }
    goto LAB_0006c6f0;
  case 0x1209:
    fVar1 = (float)((double)CONCAT44(0x43300000,*param_4 ^ 0x80000000) - DOUBLE_00108d58);
    if (FLOAT_00108e50 <= fVar1) {
      *(float *)(iVar8 + 0x2878) = fVar1;
      goto LAB_0006c708;
    }
LAB_0006c6f0:
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar7 = 0x501;
LAB_0006c728:
    *(undefined4 *)(param_1 + 0x7574) = uVar7;
    return;
  default:
    goto switchD_0006bed0_default;
  }
  iVar8 = (uVar9 >> 3 & 0x1c) + param_1;
  *(uint *)(iVar8 + 0x348) = *(uint *)(iVar8 + 0x348) | 1 << (uVar9 & 0x1f);
LAB_0006c730:
  *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 4 << (uVar11 * 2 & 0x3e);
  return;
}

/* _glLightiv_CompExec @ 0x6c75c (72 bytes) */
int _glLightiv_CompExec(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  unsigned int ghidra_home[8] = { param_1, param_2, param_3, param_4, 0, 0, 0, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  undefined4 in_LR;
  double fparam_1;
  double in_f2;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  
  ((int (*)())_glLightiv_Comp)(param_1,param_2,param_3,param_4);
  ((void (*)())_glLightiv_Exec)(param_1,param_2,param_3,param_4,fparam_1,in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8
                  ,(double)CONCAT44(in_LR,(*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0xc))),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),(*(double *)((unsigned char *)ghidra_home + 0)),
                  (*(double *)((unsigned char *)ghidra_home + 8)));
  return;
}

/* _glGetLightfv_Exec @ 0x6c7a4 (340 bytes) */
int _glGetLightfv_Exec(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  undefined4 param_3;
  undefined4 *param_4;
{
  undefined4 uVar1;
  int iVar2;
  
  if (-1 < *(short *)(param_1 + 0x4a10)) {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar1 = 0x502;
    goto LAB_0006c7f0;
  }
  if (7 < param_2 - 0x4000U) {
switchD_0006c828_default:
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar1 = 0x500;
LAB_0006c7f0:
    *(undefined4 *)(param_1 + 0x7574) = uVar1;
    return;
  }
  iVar2 = param_1 + (param_2 - 0x4000U) * 0x80;
  switch(param_3) {
  case 0x1200:
    *param_4 = *(undefined4 *)(iVar2 + 0x2820);
    param_4[1] = *(undefined4 *)(iVar2 + 0x2824);
    param_4[2] = *(undefined4 *)(iVar2 + 0x2828);
    uVar1 = *(undefined4 *)(iVar2 + 0x282c);
    goto LAB_0006c890;
  case 0x1201:
    *param_4 = *(undefined4 *)(iVar2 + 0x2830);
    param_4[1] = *(undefined4 *)(iVar2 + 0x2834);
    param_4[2] = *(undefined4 *)(iVar2 + 0x2838);
    uVar1 = *(undefined4 *)(iVar2 + 0x283c);
    goto LAB_0006c890;
  case 0x1202:
    *param_4 = *(undefined4 *)(iVar2 + 0x2840);
    param_4[1] = *(undefined4 *)(iVar2 + 0x2844);
    param_4[2] = *(undefined4 *)(iVar2 + 0x2848);
    uVar1 = *(undefined4 *)(iVar2 + 0x284c);
    goto LAB_0006c890;
  case 0x1203:
    *param_4 = *(undefined4 *)(iVar2 + 0x2850);
    param_4[1] = *(undefined4 *)(iVar2 + 0x2854);
    param_4[2] = *(undefined4 *)(iVar2 + 0x2858);
    uVar1 = *(undefined4 *)(iVar2 + 0x285c);
LAB_0006c890:
    param_4[3] = uVar1;
    return;
  case 0x1204:
    *param_4 = *(undefined4 *)(iVar2 + 0x2860);
    param_4[1] = *(undefined4 *)(iVar2 + 0x2864);
    param_4[2] = *(undefined4 *)(iVar2 + 0x2868);
    return;
  case 0x1205:
    uVar1 = *(undefined4 *)(iVar2 + 0x287c);
    break;
  case 0x1206:
    uVar1 = *(undefined4 *)(iVar2 + 0x2890);
    break;
  case 0x1207:
    uVar1 = *(undefined4 *)(iVar2 + 0x2870);
    break;
  case 0x1208:
    uVar1 = *(undefined4 *)(iVar2 + 0x2874);
    break;
  case 0x1209:
    uVar1 = *(undefined4 *)(iVar2 + 0x2878);
    break;
  default:
    goto switchD_0006c828_default;
  }
  *param_4 = uVar1;
  return;
}

/* _glGetLightiv_Exec @ 0x6c920 (676 bytes) */
int _glGetLightiv_Exec(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  undefined4 param_3;
  int *param_4;
{
  float fVar1;
  double dVar2;
  undefined4 uVar3;
  int iVar4;
  double dVar5;
  
  fVar1 = FLOAT_00108e90;
  dVar2 = DOUBLE_00108d90;
  if (-1 < *(short *)(param_1 + 0x4a10)) {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar3 = 0x502;
    goto LAB_0006c96c;
  }
  if (7 < param_2 - 0x4000U) {
switchD_0006c9a4_default:
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar3 = 0x500;
LAB_0006c96c:
    *(undefined4 *)(param_1 + 0x7574) = uVar3;
    return;
  }
  iVar4 = param_1 + (param_2 - 0x4000U) * 0x80;
  switch(param_3) {
  case 0x1200:
    *param_4 = (int)((double)*(float *)(iVar4 + 0x2820) * DOUBLE_00108d90);
    param_4[1] = (int)((double)*(float *)(iVar4 + 0x2824) * dVar2);
    param_4[2] = (int)((double)*(float *)(iVar4 + 0x2828) * dVar2);
    dVar5 = (double)*(float *)(iVar4 + 0x282c);
    goto LAB_0006ca7c;
  case 0x1201:
    *param_4 = (int)((double)*(float *)(iVar4 + 0x2830) * DOUBLE_00108d90);
    param_4[1] = (int)((double)*(float *)(iVar4 + 0x2834) * dVar2);
    param_4[2] = (int)((double)*(float *)(iVar4 + 0x2838) * dVar2);
    dVar5 = (double)*(float *)(iVar4 + 0x283c);
    goto LAB_0006ca7c;
  case 0x1202:
    *param_4 = (int)((double)*(float *)(iVar4 + 0x2840) * DOUBLE_00108d90);
    param_4[1] = (int)((double)*(float *)(iVar4 + 0x2844) * dVar2);
    param_4[2] = (int)((double)*(float *)(iVar4 + 0x2848) * dVar2);
    dVar5 = (double)*(float *)(iVar4 + 0x284c);
LAB_0006ca7c:
    dVar5 = dVar5 * dVar2;
LAB_0006ca80:
    param_4[3] = (int)dVar5;
    return;
  case 0x1203:
    *param_4 = (int)*(float *)(iVar4 + 0x2850);
    param_4[1] = (int)*(float *)(iVar4 + 0x2854);
    param_4[2] = (int)*(float *)(iVar4 + 0x2858);
    dVar5 = (double)*(float *)(iVar4 + 0x285c);
    goto LAB_0006ca80;
  case 0x1204:
    *param_4 = (int)(*(float *)(iVar4 + 0x2860) + FLOAT_00108e90);
    param_4[1] = (int)(*(float *)(iVar4 + 0x2864) + fVar1);
    param_4[2] = (int)(*(float *)(iVar4 + 0x2868) + fVar1);
    return;
  case 0x1205:
    fVar1 = *(float *)(iVar4 + 0x287c);
    break;
  case 0x1206:
    fVar1 = *(float *)(iVar4 + 0x2890);
    if (fVar1 < FLOAT_00108e50) {
      iVar4 = 0xb4;
      goto LAB_0006cbd4;
    }
    break;
  case 0x1207:
    fVar1 = *(float *)(iVar4 + 0x2870);
    break;
  case 0x1208:
    fVar1 = *(float *)(iVar4 + 0x2874);
    break;
  case 0x1209:
    fVar1 = *(float *)(iVar4 + 0x2878);
    break;
  default:
    goto switchD_0006c9a4_default;
  }
  iVar4 = (int)(fVar1 + FLOAT_00108e90);
LAB_0006cbd4:
  *param_4 = iVar4;
  return;
}

/* _glLightModelf_ListExec @ 0x6cbec (44 bytes) */
int _glLightModelf_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  ((void (*)())_glLightModelf_Exec)(param_1,*param_2,(double)GH_U2F((unsigned int)(param_2[1])));
  return 8;
}

/* _glLightModelf_Comp @ 0x6cc18 (92 bytes) */
undefined4 * _glLightModelf_Comp(undefined4 param_1,undefined4 param_2,double fparam_1)
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glLightModelf_ListExec_00110154,8);
  if (puVar1 != (undefined4 *)0x0) {
    puVar1[1] = (float)fparam_1;
    *puVar1 = param_2;
  }
  return puVar1;
}

/* _glLightModelf_Exec @ 0x6cc74 (500 bytes) */
void _glLightModelf_Exec(int param_1,uint param_2,double fparam_1)
{
  undefined4 uVar1;
  uint uVar2;
  undefined2 uVar3;
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if (param_2 == 0xb52) {
      *(bool *)(param_1 + 0x30ac) = fparam_1 != (double)FLOAT_00108e50;
      _gleUpdatePolyMode(param_1);
      _gleSelectVertexSubmitFunc(param_1);
      _gleSelectVertexAddMaterialFunc(param_1);
    }
    else if (param_2 < 0xb53) {
      if (param_2 != 0xb51) goto LAB_0006ce28;
      *(bool *)(param_1 + 0x30ad) = fparam_1 != (double)FLOAT_00108e50;
    }
    else if (param_2 == 0x81f8) {
      if (DOUBLE_00108d80 <= fparam_1) {
        uVar2 = (int)(fparam_1 - DOUBLE_00108d80) ^ 0x80000000;
      }
      else {
        uVar2 = (uint)(int)fparam_1;
      }
      if (1 < uVar2 - 0x81f9) goto LAB_0006ce28;
      if (DOUBLE_00108d80 <= fparam_1) {
        uVar3 = (undefined2)(int)(fparam_1 - DOUBLE_00108d80);
      }
      else {
        uVar3 = (undefined2)(int)fparam_1;
      }
      *(undefined2 *)(param_1 + 0x30a8) = uVar3;
      if ((*(char *)(param_1 + 0x30aa) != '\0') && (*(char *)(param_1 + 0x4664) == '\0')) {
        *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x800;
        *(bool *)(param_1 + 0x316b) = *(short *)(param_1 + 0x30a8) == -0x7e06;
      }
    }
    else {
      if (param_2 != 0x85b0) {
LAB_0006ce28:
        if (*(int *)(param_1 + 0x7574) != 0) {
          return;
        }
        uVar1 = 0x500;
        goto LAB_0006ce38;
      }
      *(bool *)(param_1 + 0x30ae) = fparam_1 != (double)FLOAT_00108e50;
    }
    _gleUpdateLightModel(param_1);
    *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 1;
  }
  else {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar1 = 0x502;
LAB_0006ce38:
    *(undefined4 *)(param_1 + 0x7574) = uVar1;
  }
  return;
}

/* _glLightModelf_CompExec @ 0x6ce68 (72 bytes) */
void _glLightModelf_CompExec(undefined4 param_1,undefined4 param_2,double fparam_1)
{
  ((undefined4 * (*)())_glLightModelf_Comp)(param_1,param_2,fparam_1);
  ((void (*)())_glLightModelf_Exec)(param_1,param_2,fparam_1);
  return;
}

/* _glLightModelfv_ListExec @ 0x6ceb0 (48 bytes) */
int _glLightModelfv_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  _glLightModelfv_Exec(param_1,*param_2,param_2 + 1);
  return 0x14;
}

