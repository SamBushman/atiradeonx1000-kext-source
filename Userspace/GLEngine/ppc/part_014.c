#include "decls.h"

/* _glCopyPixels_NoopExec @ 0x6227c (672 bytes) */
void _glCopyPixels_NoopExec(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  bool bVar1;
  char cVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  int iVar9;
  uint uVar10;
  int *piVar11;
  double extraout_f1;
  double extraout_f1_00;
  double extraout_f1_01;
  
  iVar9 = *(int *)(param_1 + 0x50ac);
  uVar5 = param_3;
  uVar6 = param_4;
  uVar7 = param_5;
  uVar8 = param_6;
  if (iVar9 != 0 || (*(uint *)(param_1 + 0x505c) & *(uint *)(param_1 + 0x50b0)) != 0) {
    _gleUpdateMatrixFunc(param_1);
    fparam_1 = extraout_f1;
  }
  if (*(char *)(param_1 + 0x4691) != '\0') {
    iVar4 = *(int *)(param_1 + 0x744c);
    piVar11 = (int *)(param_1 + 0x310);
    cVar2 = *(char *)(*(int *)(param_1 + 0x468c) + 0x79);
    if ((iVar4 != 0) && (*(int *)(iVar4 + 0xec) != 0)) {
      ((int (*)())_gleUpdateFramebufferCompleteness)(param_1,iVar4 + 0x10,uVar5,uVar6,uVar7,uVar8,iVar9,fparam_1,fparam_2,fparam_3,
                 fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
      *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x80000000;
      fparam_1 = extraout_f1_00;
    }
    if ((*(char *)(param_1 + 0x4664) == '\0') && (*(int *)(param_1 + 0x5430) == 0)) {
LAB_000623a4:
      uVar10 = *(uint *)(param_1 + 0x31c);
    }
    else {
      iVar9 = 0;
      piVar3 = (int *)(param_1 + 0x324);
      do {
        iVar4 = *piVar3;
        piVar3 = piVar3 + 1;
        if (iVar4 != 0) {
          *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x800000;
          break;
        }
        iVar9 = iVar9 + 1;
      } while (iVar9 < 9);
      uVar10 = *(uint *)(param_1 + 0x31c);
      if ((uVar10 & 0x15555) != 0) {
        if (*(char *)(param_1 + 0x2e54) != '\0') {
          fparam_1 = (double)_gleUpdateLightRGBASums(param_1,param_1 + 0x2c20,0);
        }
        if (*(char *)(param_1 + 0x3094) != '\0') {
          fparam_1 = (double)_gleUpdateLightRGBASums(param_1,param_1 + 0x2e60,1);
        }
        goto LAB_000623a4;
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
           (fparam_1 = extraout_f1_01, (uVar10 & 8) != (uint)(*(char *)(param_1 + 0x759d) == '\0')))
        {
          if ((uVar10 & 4) == 0) {
            uVar10 = uVar10 & 0xfffffffe;
            *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x10000000;
          }
          fparam_1 = (double)_gleUpdateDispatchCodeChange(param_1,uVar10);
          if (*(char *)(param_1 + 0x759d) == '\0') goto LAB_000624c4;
        }
      }
      else {
        fparam_1 = (double)_gleSwitchToNonRevertRenderer(param_1);
      }
      iVar9 = 0x13;
      do {
        *piVar11 = 0;
        piVar11 = piVar11 + 1;
        iVar9 = iVar9 + -1;
      } while (iVar9 != 0);
    }
  }
  if (*(char *)(param_1 + 0x759d) != '\0') {
    ((void (*)())_glCopyPixels_Exec)(param_1,param_2,param_3,param_4,param_5,param_6,fparam_1,fparam_2,fparam_3,
                       fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
    return;
  }
LAB_000624c4:
  if (*(int *)(param_1 + 0x7574) == 0) {
    *(undefined4 *)(param_1 + 0x7574) = 0x506;
  }
  return;
}

/* _glDepthFunc_ListExec @ 0x6251c (40 bytes) */
int _glDepthFunc_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  _glDepthFunc_Exec(param_1,*param_2);
  return 4;
}

/* _glDepthFunc_Comp @ 0x62544 (76 bytes) */
int _glDepthFunc_Comp(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glDepthFunc_ListExec_00110090,4);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_2;
  }
  return puVar1;
}

/* _glDepthFunc_CompExec @ 0x62590 (56 bytes) */
int _glDepthFunc_CompExec(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  ((int (*)())_glDepthFunc_Comp)(param_1,param_2);
  _glDepthFunc_Exec(param_1,param_2);
  return;
}

/* _glDepthRange_ListExec @ 0x625c8 (44 bytes) */
undefined4 _glDepthRange_ListExec(undefined4 param_1,double *param_2,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  double in_stack_ffffffb8;
  double in_stack_ffffffc0;
  double in_stack_ffffffc8;
  double in_stack_ffffffd0;
  double in_stack_ffffffd8;
  
  ((void (*)())_glDepthRange_Exec)(param_1,*param_2,param_2[1],fparam_3,fparam_4,fparam_5,fparam_6,fparam_7,
                     fparam_8,in_stack_ffffffb8,in_stack_ffffffc0,in_stack_ffffffc8,
                     in_stack_ffffffd0,in_stack_ffffffd8);
  return 0x10;
}

/* _glDepthRange_Comp @ 0x625f4 (100 bytes) */
double * _glDepthRange_Comp(undefined4 param_1,double fparam_1,double fparam_2)
{
  double *pdVar1;
  
  pdVar1 = (double *)_gleAddListItem(param_1,PTR__glDepthRange_ListExec_0011008c,0x10);
  if (pdVar1 != (double *)0x0) {
    pdVar1[1] = fparam_2;
    *pdVar1 = fparam_1;
  }
  return pdVar1;
}

/* _glDepthRange_Exec @ 0x62658 (320 bytes) */
void _glDepthRange_Exec(int param_1,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  byte bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  double dVar5;
  
  if (-1 < *(short *)(param_1 + 0x4a10)) {
    if (*(int *)(param_1 + 0x7574) == 0) {
      *(undefined4 *)(param_1 + 0x7574) = 0x502;
      return;
    }
    return;
  }
  if (DOUBLE_00108d60 <= fparam_1) {
    dVar5 = fparam_1;
    if (fparam_1 <= DOUBLE_00108d68) goto LAB_000626d0;
    uVar2 = 0x3ff00000;
  }
  else {
    uVar2 = 0;
  }
  dVar5 = (double)((ulonglong)uVar2 << 0x20);
LAB_000626d0:
  *(double *)(param_1 + 0x1b90) = dVar5;
  dVar5 = DOUBLE_00108d60;
  if ((fparam_2 < DOUBLE_00108d60) || (dVar5 = DOUBLE_00108d68, DOUBLE_00108d68 < fparam_2)) {
    fparam_2 = dVar5;
  }
  *(double *)(param_1 + 0x1b98) = fparam_2;
  *(float *)(param_1 + 0x1bb4) = (float)fparam_2;
  *(float *)(param_1 + 0x1bb0) = (float)*(double *)(param_1 + 0x1b90);
  *(float *)(param_1 + 0x1bb8) = (float)fparam_2 - (float)*(double *)(param_1 + 0x1b90);
  if (*(int *)(param_1 + 0x5434) == 0) {
    bVar1 = *(byte *)(*(int *)(param_1 + 0x5420) + 0x327);
  }
  else {
    bVar1 = *(byte *)(*(int *)(*(int *)(param_1 + 0x5430) + 0x20) + 0x35b);
  }
  iVar3 = (bVar1 >> 3 & 0x1c) + param_1;
  iVar4 = *(int *)(param_1 + 0x5424);
  *(uint *)(iVar3 + 0x324) = *(uint *)(iVar3 + 0x324) | 1 << (bVar1 & 0x1f);
  bVar1 = *(byte *)(iVar4 + 0x327);
  iVar3 = (bVar1 >> 3 & 0x1c) + param_1;
  *(uint *)(iVar3 + 0x348) = *(uint *)(iVar3 + 0x348) | 1 << (bVar1 & 0x1f);
  *(uint *)(param_1 + 0x318) = *(uint *)(param_1 + 0x318) | 1;
  ((void (*)())_gleUpdateDepthRangeData)(param_1,fparam_1,fparam_2,fparam_3,fparam_4,fparam_5,fparam_6,fparam_7,fparam_8,
             fparam_9,fparam_10,fparam_11,fparam_12,fparam_13);
  return;
}

/* _glDepthRange_CompExec @ 0x62798 (80 bytes) */
void _glDepthRange_CompExec(undefined4 param_1,double fparam_1,double fparam_2)
{
  undefined4 in_LR;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  
  ((double * (*)())_glDepthRange_Comp)(param_1,fparam_1,fparam_2);
  ((void (*)())_glDepthRange_Exec)(param_1,fparam_1,fparam_2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8,
                     (double)CONCAT44(in_LR,(*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0xc))),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),
                     (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
  return;
}

/* _glDepthBoundsEXT_ListExec @ 0x627e8 (44 bytes) */
int _glDepthBoundsEXT_ListExec(param_1, param_2)
  undefined4 param_1;
  double *param_2;
{
  ((void (*)())_glDepthBoundsEXT_Exec)(param_1,*param_2,param_2[1]);
  return 0x10;
}

/* _glDepthBoundsEXT_Comp @ 0x62814 (100 bytes) */
double * _glDepthBoundsEXT_Comp(undefined4 param_1,double fparam_1,double fparam_2)
{
  double *pdVar1;
  
  pdVar1 = (double *)_gleAddListItem(param_1,PTR__glDepthBoundsEXT_ListExec_00110088,0x10);
  if (pdVar1 != (double *)0x0) {
    pdVar1[1] = fparam_2;
    *pdVar1 = fparam_1;
  }
  return pdVar1;
}

/* _glDepthBoundsEXT_Exec @ 0x62878 (212 bytes) */
void _glDepthBoundsEXT_Exec(int param_1,double fparam_1,double fparam_2)
{
  uint uVar1;
  
  if (-1 < *(short *)(param_1 + 0x4a10)) {
    if (*(int *)(param_1 + 0x7574) == 0) {
      *(undefined4 *)(param_1 + 0x7574) = 0x502;
      return;
    }
    return;
  }
  if (DOUBLE_00108d60 <= fparam_1) {
    if (DOUBLE_00108d68 < fparam_1) {
      uVar1 = 0x3ff00000;
      goto LAB_000628d8;
    }
  }
  else {
    uVar1 = 0;
LAB_000628d8:
    fparam_1 = (double)((ulonglong)uVar1 << 0x20);
  }
  *(double *)(param_1 + 0x312c) = fparam_1;
  if (DOUBLE_00108d60 <= fparam_2) {
    if (fparam_2 <= DOUBLE_00108d68) goto LAB_00062934;
    uVar1 = 0x3ff00000;
  }
  else {
    uVar1 = 0;
  }
  fparam_2 = (double)((ulonglong)uVar1 << 0x20);
LAB_00062934:
  *(double *)(param_1 + 0x3134) = fparam_2;
  *(uint *)(param_1 + 0x318) = *(uint *)(param_1 + 0x318) | 1;
  return;
}

/* _glDepthBoundsEXT_CompExec @ 0x6294c (80 bytes) */
void _glDepthBoundsEXT_CompExec(undefined4 param_1,double fparam_1,double fparam_2)
{
  ((double * (*)())_glDepthBoundsEXT_Comp)(param_1,fparam_1,fparam_2);
  ((void (*)())_glDepthBoundsEXT_Exec)(param_1,fparam_1,fparam_2);
  return;
}

/* _glCallList_ListExec @ 0x6299c (40 bytes) */
int _glCallList_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  _glCallList_Exec(param_1,*param_2);
  return 4;
}

/* _glCallList_Comp @ 0x629c4 (76 bytes) */
int _glCallList_Comp(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glCallList_ListExec_0011009c,4);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_2;
  }
  return puVar1;
}

/* _glCallList_CompExec @ 0x62a10 (56 bytes) */
int _glCallList_CompExec(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  ((int (*)())_glCallList_Comp)(param_1,param_2);
  _glCallList_Exec(param_1,param_2);
  return;
}

/* _glCallLists_ListExec @ 0x62a48 (64 bytes) */
int _glCallLists_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  ((int (*)())_glCallLists_Exec)(param_1,*param_2,param_2[2],param_2 + 3);
  return param_2[1] + 0xc;
}

/* _glCallLists_Comp @ 0x62a88 (164 bytes) */
int _glCallLists_Comp(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  int param_2;
  int param_3;
  undefined4 param_4;
{
  uint uVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  
  iVar2 = _gleTypeSize(param_1,param_3);
  uVar1 = param_2 * iVar2 + 3U & 0xfffffffc;
  piVar3 = (int *)_gleAddListItem(param_1,PTR__glCallLists_ListExec_00110098,uVar1 + 0xc);
  if (piVar3 != (int *)0x0) {
    *piVar3 = param_2;
    piVar3[2] = param_3;
    piVar3[1] = uVar1;
    uVar4 = _gleCopy(param_4,piVar3 + 3,param_2 * iVar2,1,0,0);
    return uVar4;
  }
  return 0;
}

/* _glCallLists_Exec @ 0x62b2c (764 bytes) */
int _glCallLists_Exec(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  undefined4 param_3;
  float *param_4;
{
  byte *pbVar1;
  short sVar2;
  ushort uVar3;
  double dVar4;
  float fVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  double dVar9;
  
  dVar4 = DOUBLE_00108d80;
  switch(param_3) {
  case 0x1400:
    iVar7 = 0;
    if (0 < param_2) {
      do {
        pbVar1 = (byte *)((int)param_4 + iVar7);
        iVar7 = iVar7 + 1;
        _gleCallList(param_1,(int)(char)*pbVar1 + *(int *)(param_1 + 0x5404));
      } while (iVar7 < param_2);
    }
    break;
  case 0x1401:
    iVar7 = 0;
    if (0 < param_2) {
      do {
        pbVar1 = (byte *)((int)param_4 + iVar7);
        iVar7 = iVar7 + 1;
        _gleCallList(param_1,(uint)*pbVar1 + *(int *)(param_1 + 0x5404));
      } while (iVar7 < param_2);
    }
    break;
  case 0x1402:
    if (0 < param_2) {
      do {
        sVar2 = *(short *)param_4;
        param_4 = (float *)((int)param_4 + 2);
        _gleCallList(param_1,(int)sVar2 + *(int *)(param_1 + 0x5404));
        param_2 = param_2 + -1;
      } while (param_2 != 0);
    }
    break;
  case 0x1403:
    if (0 < param_2) {
      do {
        uVar3 = *(ushort *)param_4;
        param_4 = (float *)((int)param_4 + 2);
        _gleCallList(param_1,(uint)uVar3 + *(int *)(param_1 + 0x5404));
        param_2 = param_2 + -1;
      } while (param_2 != 0);
    }
    break;
  case 0x1404:
    if (0 < param_2) {
      do {
        fVar5 = *param_4;
        param_4 = param_4 + 1;
        _gleCallList(param_1,(int)fVar5 + *(int *)(param_1 + 0x5404));
        param_2 = param_2 + -1;
      } while (param_2 != 0);
    }
    break;
  case 0x1405:
    if (0 < param_2) {
      do {
        fVar5 = *param_4;
        param_4 = param_4 + 1;
        _gleCallList(param_1,(int)fVar5 + *(int *)(param_1 + 0x5404));
        param_2 = param_2 + -1;
      } while (param_2 != 0);
    }
    break;
  case 0x1406:
    if (0 < param_2) {
      do {
        fVar5 = *param_4;
        dVar9 = (double)fVar5;
        param_4 = param_4 + 1;
        if (dVar4 <= dVar9) {
          uVar6 = (int)(dVar9 - dVar4) ^ 0x80000000;
        }
        else {
          uVar6 = (uint)(int)fVar5;
        }
        _gleCallList(param_1,uVar6 + *(int *)(param_1 + 0x5404));
        param_2 = param_2 + -1;
      } while (param_2 != 0);
    }
    break;
  case 0x1407:
    iVar7 = 0;
    if (0 < param_2 << 1) {
      do {
        iVar7 = iVar7 + 2;
        _gleCallList(param_1,(uint)*(byte *)param_4 * 0x100 + (uint)*(byte *)((int)param_4 + 1) +
                             *(int *)(param_1 + 0x5404));
        param_4 = (float *)((int)param_4 + 2);
      } while (iVar7 < param_2 << 1);
    }
    break;
  case 0x1408:
    iVar7 = 0;
    if (0 < param_2 * 3) {
      do {
        iVar8 = iVar7 + 3;
        _gleCallList(param_1,(uint)*(byte *)((int)param_4 + iVar7) * 0x10000 +
                             (uint)*(byte *)((int)param_4 + iVar7 + 1) * 0x100 +
                             (uint)*(byte *)((int)param_4 + iVar7 + 2) + *(int *)(param_1 + 0x5404))
        ;
        iVar7 = iVar8;
      } while (iVar8 < param_2 * 3);
    }
    break;
  case 0x1409:
    iVar7 = 0;
    if (0 < param_2 << 2) {
      do {
        iVar8 = iVar7 + 4;
        _gleCallList(param_1,(uint)*(byte *)((int)param_4 + iVar7) * 0x1000000 +
                             (uint)*(byte *)((int)param_4 + iVar7 + 1) * 0x10000 +
                             (uint)*(byte *)((int)param_4 + iVar7 + 2) * 0x100 +
                             (uint)*(byte *)((int)param_4 + iVar7 + 3) + *(int *)(param_1 + 0x5404))
        ;
        iVar7 = iVar8;
      } while (iVar8 < param_2 << 2);
    }
    break;
  default:
    if (*(int *)(param_1 + 0x7574) == 0) {
      *(undefined4 *)(param_1 + 0x7574) = 0x500;
    }
  }
  return;
}

/* _glCallLists_CompExec @ 0x62e50 (72 bytes) */
int _glCallLists_CompExec(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  ((int (*)())_glCallLists_Comp)(param_1,param_2,param_3,param_4);
  ((int (*)())_glCallLists_Exec)(param_1,param_2,param_3,param_4);
  return;
}

/* _glIsList_Exec @ 0x62e98 (80 bytes) */
int _glIsList_Exec(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  undefined4 uVar1;
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    uVar1 = _gleIsHashName(*(int *)(param_1 + 0x5148) + 0x300c,param_2);
  }
  else {
    if (*(int *)(param_1 + 0x7574) == 0) {
      *(undefined4 *)(param_1 + 0x7574) = 0x502;
    }
    uVar1 = 0;
  }
  return uVar1;
}

/* _glListBase_ListExec @ 0x62ee8 (40 bytes) */
int _glListBase_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  ((int (*)())_glListBase_Exec)(param_1,*param_2);
  return 4;
}

/* _glListBase_Comp @ 0x62f10 (76 bytes) */
int _glListBase_Comp(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glListBase_ListExec_00110094,4);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_2;
  }
  return puVar1;
}

/* _glListBase_Exec @ 0x62f5c (44 bytes) */
int _glListBase_Exec(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  if (*(short *)(param_1 + 0x4a10) < 0) {
    *(undefined4 *)(param_1 + 0x5404) = param_2;
    return;
  }
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  *(undefined4 *)(param_1 + 0x7574) = 0x502;
  return;
}

/* _glListBase_CompExec @ 0x62f88 (56 bytes) */
int _glListBase_CompExec(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  ((int (*)())_glListBase_Comp)(param_1,param_2);
  ((int (*)())_glListBase_Exec)(param_1,param_2);
  return;
}

/* _glDrawBuffer_ListExec @ 0x62fc0 (40 bytes) */
int _glDrawBuffer_ListExec(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  undefined4 param_1;
  undefined4 *param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  ((int (*)())_glDrawBuffer_Exec)(param_1,*param_2,param_3,param_4,param_5,param_6,param_7);
  return 4;
}

/* _glDrawBuffer_Comp @ 0x62fe8 (76 bytes) */
int _glDrawBuffer_Comp(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glDrawBuffer_ListExec_001100a4,4);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_2;
  }
  return puVar1;
}

/* _glDrawBuffer_Exec @ 0x63034 (472 bytes) */
int _glDrawBuffer_Exec(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int param_1;
  uint param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  bool bVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  undefined2 *puVar5;
  int iVar6;
  int iVar7;
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if (param_2 == 0x404) {
LAB_000630bc:
      if (*(int *)(param_1 + 0x744c) == 0) {
        iVar6 = 0;
        goto LAB_00063184;
      }
    }
    else {
      if (param_2 < 0x405) {
        if (param_2 == 0x401) goto LAB_000630e0;
        if (param_2 < 0x402) {
          if (param_2 == 0) {
            iVar6 = *(int *)(param_1 + 0x744c);
            goto LAB_00063184;
          }
          bVar1 = param_2 == 0x400;
LAB_000630a0:
          if (!bVar1) goto LAB_0006313c;
          goto LAB_000630bc;
        }
        if (param_2 == 0x402) goto LAB_000630cc;
        if (param_2 != 0x403) goto LAB_0006313c;
        if ((*(int *)(param_1 + 0x744c) != 0) || (*(char *)(param_1 + 0x7582) == '\0'))
        goto LAB_000631f8;
LAB_000630ec:
        cVar2 = *(char *)(*(int *)(param_1 + 0x468c) + 0x26);
LAB_000630f4:
        iVar6 = 0;
        bVar1 = cVar2 == '\0';
      }
      else {
        if (param_2 == 0x407) {
LAB_000630e0:
          if (*(int *)(param_1 + 0x744c) != 0) goto LAB_000631f8;
          goto LAB_000630ec;
        }
        if (param_2 < 0x408) {
          if (param_2 != 0x405) {
            bVar1 = param_2 == 0x406;
            goto LAB_000630a0;
          }
LAB_000630cc:
          if (*(int *)(param_1 + 0x744c) != 0) goto LAB_000631f8;
          cVar2 = *(char *)(param_1 + 0x7582);
          goto LAB_000630f4;
        }
        if (param_2 == 0x408) goto LAB_000630bc;
        if (param_2 < 0x40d) {
          if ((*(int *)(param_1 + 0x744c) == 0) &&
             (param_2 < *(int *)(*(int *)(param_1 + 0x468c) + 0x54) + 0x409U)) {
            iVar6 = 0;
            goto LAB_00063184;
          }
          goto LAB_000631f8;
        }
LAB_0006313c:
        if (((int)(param_2 - 0x8ce0) < 0) ||
           (*(uint *)(*(int *)(param_1 + 0x468c) + 0x18) <= param_2 - 0x8ce0)) {
          if (*(int *)(param_1 + 0x7574) != 0) {
            return;
          }
          uVar4 = 0x500;
          goto LAB_00063168;
        }
        iVar6 = *(int *)(param_1 + 0x744c);
        bVar1 = iVar6 == 0;
      }
      if (!bVar1) {
LAB_00063184:
        if (iVar6 == 0) {
          *(short *)(param_1 + 0x311a) = (short)param_2;
          iVar6 = 3;
          puVar5 = (undefined2 *)(param_1 + 0x311c);
          do {
            *puVar5 = 0;
            puVar5 = puVar5 + 1;
            iVar6 = iVar6 + -1;
          } while (iVar6 != 0);
        }
        else {
          *(short *)(iVar6 + 0xc0) = (short)param_2;
          iVar7 = 3;
          iVar6 = 1;
          do {
            iVar3 = iVar6 * 2;
            iVar6 = iVar6 + 1;
            *(undefined2 *)(iVar3 + *(int *)(param_1 + 0x744c) + 0xc0) = 0;
            iVar7 = iVar7 + -1;
          } while (iVar7 != 0);
          *(undefined4 *)(*(int *)(param_1 + 0x744c) + 0xec) = 1;
        }
        *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x80;
        return;
      }
    }
  }
LAB_000631f8:
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  uVar4 = 0x502;
LAB_00063168:
  *(undefined4 *)(param_1 + 0x7574) = uVar4;
  return;
}

/* _glDrawBuffer_CompExec @ 0x6320c (56 bytes) */
int _glDrawBuffer_CompExec(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  undefined4 in_r5;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  undefined4 in_r9;
  
  ((int (*)())_glDrawBuffer_Comp)(param_1,param_2);
  ((int (*)())_glDrawBuffer_Exec)(param_1,param_2,in_r5,in_r6,in_r7,in_r8,in_r9);
  return;
}

/* _glDrawBuffersARB_ListExec @ 0x63244 (48 bytes) */
int _glDrawBuffersARB_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  ((int (*)())_glDrawBuffersARB_Exec)(param_1,*param_2,param_2 + 1);
  return 0x14;
}

/* _glDrawBuffersARB_Comp @ 0x63274 (152 bytes) */
int _glDrawBuffersARB_Comp(param_1, param_2, param_3)
  int *param_1;
  int param_2;
  int *param_3;
{
  int iVar1;
  
  if (param_2 < 5) {
    param_1 = (int *)_gleAddListItem(param_1,PTR__glDrawBuffersARB_ListExec_001100a0,0x14);
    if ((param_1 != (int *)0x0) && (*param_1 = param_2, 0 < param_2)) {
      param_1 = param_1 + 1;
      do {
        iVar1 = *param_3;
        param_3 = param_3 + 1;
        *param_1 = iVar1;
        param_1 = param_1 + 1;
        param_2 = param_2 + -1;
      } while (param_2 != 0);
    }
  }
  else if (param_1[0x1d5d] == 0) {
    param_1[0x1d5d] = 0x502;
  }
  return param_1;
}

/* _glDrawBuffersARB_Exec @ 0x6330c (652 bytes) */
int _glDrawBuffersARB_Exec(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int *param_3;
{
  undefined2 uVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  undefined2 *puVar5;
  undefined2 *puVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  
  uVar7 = 0;
  if ((-1 < *(short *)(param_1 + 0x4a10)) || (4 < param_2)) {
LAB_000635b8:
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar3 = 0x502;
LAB_000634a0:
    *(undefined4 *)(param_1 + 0x7574) = uVar3;
    return;
  }
  iVar10 = 0;
  if (0 < param_2) {
    do {
      if (param_3[iVar10] == 0) goto LAB_000634c4;
      iVar8 = 0;
      piVar4 = param_3;
      if (0 < iVar10) {
        do {
          if (param_3[iVar10] == *piVar4) goto LAB_000635b8;
          iVar8 = iVar8 + 1;
          piVar4 = piVar4 + 1;
        } while (iVar8 < iVar10);
      }
      switch(param_3[iVar10]) {
      case 0x400:
      case 0x404:
      case 0x406:
      case 0x408:
        if (*(int *)(param_1 + 0x744c) == 0) goto LAB_00063408;
        goto LAB_000635b8;
      case 0x401:
      case 0x407:
        if (*(int *)(param_1 + 0x744c) == 0) goto LAB_00063438;
        goto LAB_000635b8;
      case 0x402:
      case 0x405:
        if ((*(int *)(param_1 + 0x744c) != 0) || (*(char *)(param_1 + 0x7582) == '\0'))
        goto LAB_000635b8;
LAB_00063408:
        iVar8 = *(int *)(param_1 + 0x468c);
        break;
      case 0x403:
        if ((*(int *)(param_1 + 0x744c) != 0) || (*(char *)(param_1 + 0x7582) == '\0'))
        goto LAB_000635b8;
LAB_00063438:
        iVar8 = *(int *)(param_1 + 0x468c);
        if (*(char *)(iVar8 + 0x26) == '\0') goto LAB_000635b8;
        break;
      case 0x409:
      case 0x40a:
      case 0x40b:
      case 0x40c:
        if ((*(int *)(param_1 + 0x744c) != 0) ||
           (iVar8 = *(int *)(param_1 + 0x468c),
           *(int *)(iVar8 + 0x54) + 0x409U <= (uint)param_3[iVar10])) goto LAB_000635b8;
        break;
      default:
        uVar9 = param_3[iVar10] - 0x8ce0;
        if (((int)uVar9 < 0) ||
           (iVar8 = *(int *)(param_1 + 0x468c), *(uint *)(iVar8 + 0x18) <= uVar9)) {
          if (*(int *)(param_1 + 0x7574) != 0) {
            return;
          }
          uVar3 = 0x500;
          goto LAB_000634a0;
        }
        if (*(int *)(param_1 + 0x744c) == 0) goto LAB_000635b8;
        uVar7 = uVar7 + 1;
      }
      if (*(uint *)(iVar8 + 0x14) <= uVar7) goto LAB_000635b8;
LAB_000634c4:
      iVar10 = iVar10 + 1;
    } while (iVar10 < param_2);
  }
  iVar10 = *(int *)(param_1 + 0x744c);
  if (iVar10 == 0) {
    iVar10 = 0;
    if (0 < param_2) {
      puVar6 = (undefined2 *)((int)param_3 + 2);
      puVar5 = (undefined2 *)(param_1 + 0x311a);
      iVar10 = param_2;
      do {
        uVar1 = *puVar6;
        puVar6 = puVar6 + 2;
        *puVar5 = uVar1;
        puVar5 = puVar5 + 1;
        iVar10 = iVar10 + -1;
      } while (iVar10 != 0);
      iVar10 = param_2;
      if (3 < param_2) goto LAB_000635a8;
    }
    do {
      iVar8 = iVar10 * 2;
      iVar10 = iVar10 + 1;
      *(undefined2 *)(iVar8 + param_1 + 0x311a) = 0;
    } while (iVar10 < 4);
    goto LAB_000635a8;
  }
  iVar8 = 0;
  if (param_2 < 1) {
LAB_00063528:
    while( true ) {
      iVar2 = iVar8 * 2;
      iVar8 = iVar8 + 1;
      *(undefined2 *)(iVar2 + iVar10 + 0xc0) = 0;
      if (3 < iVar8) break;
      iVar10 = *(int *)(param_1 + 0x744c);
    }
    iVar10 = *(int *)(param_1 + 0x744c);
  }
  else {
    puVar5 = (undefined2 *)((int)param_3 + 2);
    while( true ) {
      uVar1 = *puVar5;
      puVar5 = puVar5 + 2;
      *(undefined2 *)(iVar8 * 2 + iVar10 + 0xc0) = uVar1;
      iVar8 = iVar8 + 1;
      param_2 = param_2 + -1;
      if (param_2 == 0) break;
      iVar10 = *(int *)(param_1 + 0x744c);
    }
    iVar10 = *(int *)(param_1 + 0x744c);
    if (iVar8 < 4) goto LAB_00063528;
  }
  *(undefined4 *)(iVar10 + 0xec) = 1;
LAB_000635a8:
  *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x80;
  return;
}

/* _glDrawBuffersARB_CompExec @ 0x635cc (64 bytes) */
int _glDrawBuffersARB_CompExec(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  ((int (*)())_glDrawBuffersARB_Comp)(param_1,param_2,param_3);
  ((int (*)())_glDrawBuffersARB_Exec)(param_1,param_2,param_3);
  return;
}

/* _glDrawPixels_ListExec @ 0x6360c (1320 bytes) */
int _glDrawPixels_ListExec(int param_1,uint *param_2,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  bool bVar1;
  char cVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int *piVar7;
  int iVar8;
  undefined4 in_r5;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  uint uVar9;
  int iVar10;
  int *piVar11;
  int iVar12;
  float *pfVar13;
  double extraout_f1;
  
  iVar5 = *(int *)(param_1 + 0x4854);
  pfVar13 = (float *)(iVar5 + -0x200);
  iVar12 = param_2[4] + 0x14;
  if (-1 < *(short *)(param_1 + 0x4a10)) {
LAB_00063798:
    if (*(int *)(param_1 + 0x7574) != 0) {
      return iVar12;
    }
    uVar3 = 0x502;
    goto LAB_00063b18;
  }
  uVar9 = *param_2;
  if (((int)uVar9 < 0) || ((int)param_2[1] < 0)) {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return iVar12;
    }
    uVar3 = 0x501;
    goto LAB_00063b18;
  }
  uVar6 = param_2[3];
  if (uVar6 < 0x8037) {
    if (0x8032 < uVar6) {
LAB_00063748:
      uVar6 = param_2[2];
      if (uVar6 != 0x1908) {
        uVar4 = 0x80e1;
        goto LAB_0006375c;
      }
      goto LAB_000637ac;
    }
    if (uVar6 == 0x140b) {
LAB_000636f4:
      uVar6 = param_2[2];
      if (uVar6 != 0x8000) {
        if (uVar6 < 0x8001) {
          bVar1 = 10 < uVar6 - 0x1900;
        }
        else {
          bVar1 = 1 < uVar6 - 0x80e0;
        }
        if (bVar1) goto LAB_00063798;
      }
      goto LAB_000637ac;
    }
    if (uVar6 < 0x140c) {
      if (uVar6 - 0x1400 < 7) goto LAB_000636f4;
    }
    else if (uVar6 == 0x1a00) {
      if (param_2[2] - 0x1900 < 2) goto LAB_000637ac;
    }
    else if (uVar6 == 0x8032) goto LAB_00063730;
  }
  else {
    if (uVar6 < 0x8369) {
      if (0x8364 < uVar6) goto LAB_00063748;
      if (uVar6 < 0x8362) goto LAB_00063b08;
LAB_00063730:
      uVar6 = param_2[2];
      if (uVar6 == 0x1907) goto LAB_000637ac;
      uVar4 = 0x80e0;
LAB_0006375c:
      if (uVar6 != uVar4) goto LAB_00063798;
    }
    else {
      if (1 < uVar6 - 0x85ba) goto LAB_00063b08;
      if ((param_2[2] != 0x85b9) || ((uVar9 & 1) != 0)) goto LAB_00063798;
    }
LAB_000637ac:
    if (*(char *)(param_1 + 0x2ef) == '\0') {
      return iVar12;
    }
    uVar6 = *(uint *)(param_1 + 0x4e1c);
    if (uVar6 == 0x1c01) {
      *pfVar13 = *(float *)(param_1 + 0x2e0);
      *(undefined4 *)(iVar5 + -0x1fc) = *(undefined4 *)(param_1 + 0x2e4);
      *(undefined4 *)(iVar5 + -0x1f8) = *(undefined4 *)(param_1 + 0x2e8);
      _gleFeedbackDrawPixels(param_1,pfVar13);
      return iVar12;
    }
    if (uVar6 < 0x1c02) {
      if (uVar6 == 0x1c00) {
        if (*(float *)(param_1 + 0x31a8) == FLOAT_00108e50) {
          return iVar12;
        }
        if (*(float *)(param_1 + 0x31ac) == FLOAT_00108e50) {
          return iVar12;
        }
        if (uVar9 == 0) {
          return iVar12;
        }
        if (param_2[1] == 0) {
          return iVar12;
        }
        iVar10 = *(int *)(param_1 + 0x50ac);
        if (iVar10 != 0 || (*(uint *)(param_1 + 0x505c) & *(uint *)(param_1 + 0x50b0)) != 0) {
          _gleUpdateMatrixFunc(param_1);
          fparam_1 = extraout_f1;
        }
        if (*(char *)(param_1 + 0x4691) == '\0') goto LAB_00063a3c;
        iVar8 = *(int *)(param_1 + 0x744c);
        piVar11 = (int *)(param_1 + 0x310);
        cVar2 = *(char *)(*(int *)(param_1 + 0x468c) + 0x79);
        if ((iVar8 != 0) && (*(int *)(iVar8 + 0xec) != 0)) {
          ((int (*)())_gleUpdateFramebufferCompleteness)(param_1,iVar8 + 0x10,in_r5,in_r6,in_r7,in_r8,iVar10,fparam_1,fparam_2,fparam_3,
                     fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
          *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x80000000;
        }
        if ((*(char *)(param_1 + 0x4664) == '\0') && (*(int *)(param_1 + 0x5430) == 0)) {
LAB_00063918:
          uVar9 = *(uint *)(param_1 + 0x31c);
        }
        else {
          iVar10 = 0;
          piVar7 = (int *)(param_1 + 0x324);
          do {
            iVar8 = *piVar7;
            piVar7 = piVar7 + 1;
            if (iVar8 != 0) {
              *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x800000;
              break;
            }
            iVar10 = iVar10 + 1;
          } while (iVar10 < 9);
          uVar9 = *(uint *)(param_1 + 0x31c);
          if ((uVar9 & 0x15555) != 0) {
            if (*(char *)(param_1 + 0x2e54) != '\0') {
              _gleUpdateLightRGBASums(param_1,param_1 + 0x2c20,0);
            }
            if (*(char *)(param_1 + 0x3094) != '\0') {
              _gleUpdateLightRGBASums(param_1,param_1 + 0x2e60,1);
            }
            goto LAB_00063918;
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
          bVar1 = ((*piVar11 == 0 && *(int *)(param_1 + 0x314) == 0) && uVar9 == 0) &&
                  *(int *)(param_1 + 800) == 0;
        }
        else {
          bVar1 = (((*piVar11 == 0 && *(int *)(param_1 + 0x314) == 0) &&
                   (*(uint *)(param_1 + 0x318) & 0xfffffffd) == 0) && uVar9 == 0) &&
                  *(int *)(param_1 + 800) == 0;
        }
        if (!bVar1) {
          if (*(char *)(param_1 + 0x85a8) == *(char *)(param_1 + 0x85a6)) {
            uVar9 = (**(code **)(param_1 + 0x4788))
                              (*(undefined4 *)(param_1 + 0x4688),param_1 + 0x4698,piVar11);
            if ((((uVar9 & 3) != (uint)*(byte *)(param_1 + 0x7580)) ||
                ((uVar9 & 4) != (uint)*(byte *)(param_1 + 0x7581))) ||
               ((uVar9 & 8) != (uint)(*(char *)(param_1 + 0x759d) == '\0'))) {
              if ((uVar9 & 4) == 0) {
                uVar9 = uVar9 & 0xfffffffe;
                *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x10000000;
              }
              _gleUpdateDispatchCodeChange(param_1,uVar9);
              if (*(char *)(param_1 + 0x759d) == '\0') {
                if (*(int *)(param_1 + 0x7574) != 0) {
                  return iVar12;
                }
                uVar3 = 0x506;
                goto LAB_00063b18;
              }
            }
          }
          else {
            _gleSwitchToNonRevertRenderer(param_1);
          }
          iVar10 = 0x13;
          do {
            *piVar11 = 0;
            piVar11 = piVar11 + 1;
            iVar10 = iVar10 + -1;
          } while (iVar10 != 0);
        }
LAB_00063a3c:
        *pfVar13 = *(float *)(param_1 + 0x4a44) * *(float *)(param_1 + 0x2e0) +
                   *(float *)(param_1 + 0x4a48);
        *(float *)(iVar5 + -0x1fc) =
             *(float *)(param_1 + 0x4a4c) * *(float *)(param_1 + 0x2e4) +
             *(float *)(param_1 + 0x4a50);
        *(float *)(iVar5 + -0x1f8) = *(float *)(param_1 + 0x4a54) * *(float *)(param_1 + 0x2e8);
        if ((*(char *)(*(int *)(param_1 + 0x468c) + 0x7b) != '\0') &&
           (iVar5 = _gleDrawPixelsFast(param_1,*param_2,param_2[1],param_2[2],param_2[3],param_2 + 5
                                      ), iVar5 != 0)) {
          return iVar12;
        }
        (**(code **)(param_1 + 0x46a4))
                  (*(undefined4 *)(param_1 + 0x4688),pfVar13,*param_2,param_2[1],param_2[2],
                   param_2[3],param_2 + 5,1);
        return iVar12;
      }
    }
    else if (uVar6 == 0x1c02) {
      return iVar12;
    }
  }
LAB_00063b08:
  if (*(int *)(param_1 + 0x7574) != 0) {
    return iVar12;
  }
  uVar3 = 0x500;
LAB_00063b18:
  *(undefined4 *)(param_1 + 0x7574) = uVar3;
  return iVar12;
}

/* _glDrawPixels_Comp @ 0x63b34 (600 bytes) */
int _glDrawPixels_Comp(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  undefined4 param_2;
  int param_3;
  undefined4 param_4;
  undefined4 param_5;
  int param_6;
{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined1 *puVar7;
  int *piVar8;
  int iVar9;
  int iVar10;
  double dVar11;
  int local_c0;
  undefined4 local_bc;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined4 *local_b0;
  int local_ac;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  uint local_9c;
  undefined4 local_98;
  undefined4 local_94;
  int local_90;
  undefined1 local_54;
  undefined4 local_50;
  undefined1 auStack_4c [4];
  undefined1 auStack_48 [4];
  undefined1 auStack_44 [4];
  undefined1 auStack_40 [4];
  int local_3c;
  undefined4 local_38;
  undefined4 local_34 [2];
  
  iVar10 = *(int *)(param_1 + 0x4a6c);
  if (iVar10 == 0) {
LAB_00063c10:
    iVar9 = param_1 + 0x31cc;
    puVar7 = auStack_40;
    piVar8 = &local_3c;
    iVar10 = param_3;
    _glePixelPackSettings
              (param_1,param_4,param_5,param_2,param_3,iVar9,puVar7,piVar8,&local_50,auStack_4c,
               auStack_48,auStack_44);
    iVar2 = _gleRowBytes(param_4,param_5,param_2);
    uVar1 = iVar2 * param_3 + 3U & 0xfffffffc;
    puVar4 = (undefined4 *)_gleAddListItem(param_1,PTR__glDrawPixels_ListExec_001100a8,uVar1 + 0x14)
    ;
    iVar3 = 0;
    if (puVar4 != (undefined4 *)0x0) {
      puVar4[4] = uVar1;
      *puVar4 = param_2;
      puVar4[1] = param_3;
      puVar4[2] = param_4;
      puVar4[3] = param_5;
      if ((*(uint *)(param_1 + 0x31e4) & 0xffff0000) == 0) {
        iVar3 = _gleCopy(param_6 + local_3c,puVar4 + 5,iVar2,param_3,local_50,iVar2);
      }
      else {
        puVar5 = &local_38;
        puVar6 = local_34;
        _glgConvertType(param_4,param_5,puVar5,puVar6,iVar10,iVar9,puVar7,piVar8);
        local_bc = local_50;
        local_a8 = local_38;
        local_a4 = local_34[0];
        local_a0 = 2;
        local_98 = 5;
        local_54 = 0;
        local_b8 = local_38;
        local_b4 = local_34[0];
        local_9c = (uint)(*(char *)(param_1 + 0x31e4) != '\0');
        if (*(char *)(param_1 + 0x31e5) != '\0') {
          local_9c = local_9c | 4;
        }
        local_c0 = param_6 + local_3c;
        local_b0 = puVar4 + 5;
        local_ac = iVar2;
        local_94 = param_2;
        local_90 = param_3;
        iVar3 = _glgProcessPixels(0,&local_c0,puVar5,puVar6,iVar10,iVar9,local_34[0],local_38);
      }
    }
  }
  else {
    iVar2 = _gleOffsetLimitImage(param_1 + 0x31cc,param_2,param_3,param_4,param_5,param_6);
    iVar9 = *(int *)(iVar10 + 0x38);
    dVar11 = (double)((double (*)())_gleBytesPerElement)(param_5);
    iVar3 = (int)dVar11;
    if (iVar2 <= iVar9) {
      if (iVar3 == 0) {
        iVar3 = _glePixelBytes(param_4,param_5);
      }
      if (param_6 == (param_6 / iVar3) * iVar3) {
        iVar3 = *(int *)(param_1 + 0x4a6c);
        if ((iVar3 != 0) && (*(int *)(iVar3 + 0x40) != 0)) {
          _gleSynchronizePluginBuffer(param_1,iVar3 + 0x10);
        }
        param_6 = param_6 + *(int *)(iVar10 + 0x30);
        goto LAB_00063c10;
      }
    }
    if (*(int *)(param_1 + 0x7574) == 0) {
      *(undefined4 *)(param_1 + 0x7574) = 0x502;
    }
  }
  return iVar3;
}

/* _glDrawPixels_Exec @ 0x63d8c (1520 bytes) */
void _glDrawPixels_Exec(int param_1,uint param_2,int param_3,uint param_4,uint param_5,int param_6,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  bool bVar1;
  char cVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  int iVar13;
  float *pfVar14;
  int iVar15;
  int *piVar16;
  double extraout_f1;
  double extraout_f1_00;
  
  iVar6 = *(int *)(param_1 + 0x4854);
  pfVar14 = (float *)(iVar6 + -0x200);
  if (-1 < *(short *)(param_1 + 0x4a10)) goto LAB_00063f78;
  if (((int)param_2 < 0) || (param_3 < 0)) {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar3 = 0x501;
    goto LAB_0006435c;
  }
  if (param_5 < 0x8037) {
    if (0x8032 < param_5) {
LAB_00063ec4:
      if (param_4 != 0x1908) {
        uVar12 = 0x80e1;
        goto LAB_00063ed4;
      }
      goto LAB_00063f08;
    }
    if (param_5 == 0x140b) {
LAB_00063e78:
      if (param_4 != 0x8000) {
        if (param_4 < 0x8001) {
          bVar1 = 10 < param_4 - 0x1900;
        }
        else {
          bVar1 = 1 < param_4 - 0x80e0;
        }
        if (bVar1) goto LAB_00063f78;
      }
      goto LAB_00063f08;
    }
    if (param_5 < 0x140c) {
      if (param_5 - 0x1400 < 7) goto LAB_00063e78;
    }
    else if (param_5 == 0x1a00) {
      if (param_4 - 0x1900 < 2) goto LAB_00063f08;
    }
    else if (param_5 == 0x8032) goto LAB_00063eb0;
    goto LAB_0006434c;
  }
  if (param_5 < 0x8369) {
    if (0x8364 < param_5) goto LAB_00063ec4;
    if (param_5 < 0x8362) goto LAB_0006434c;
LAB_00063eb0:
    if (param_4 == 0x1907) goto LAB_00063f08;
    uVar12 = 0x80e0;
LAB_00063ed4:
    if (param_4 != uVar12) goto LAB_00063f78;
  }
  else {
    if (1 < param_5 - 0x85ba) goto LAB_0006434c;
    if ((param_4 != 0x85b9) || ((param_2 & 1) != 0)) goto LAB_00063f78;
  }
LAB_00063f08:
  iVar13 = *(int *)(param_1 + 0x4a6c);
  iVar11 = param_3;
  uVar12 = param_4;
  uVar10 = param_5;
  iVar5 = param_6;
  if (iVar13 != 0) {
    iVar8 = _gleOffsetLimitImage(param_1 + 0x31cc,param_2,param_3,param_4,param_5,param_6);
    iVar15 = *(int *)(iVar13 + 0x38);
    fparam_1 = (double)((double (*)())_gleBytesPerElement)(param_5);
    iVar9 = (int)fparam_1;
    if (iVar8 <= iVar15) {
      if (iVar9 == 0) {
        iVar9 = _glePixelBytes(param_4,param_5);
        fparam_1 = extraout_f1;
      }
      if (param_6 == (param_6 / iVar9) * iVar9) {
        param_6 = param_6 + *(int *)(iVar13 + 0x30);
        goto LAB_00063f94;
      }
    }
LAB_00063f78:
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar3 = 0x502;
    goto LAB_0006435c;
  }
LAB_00063f94:
  if (*(char *)(param_1 + 0x2ef) == '\0') {
    return;
  }
  uVar4 = *(uint *)(param_1 + 0x4e1c);
  if (uVar4 == 0x1c01) {
    *pfVar14 = *(float *)(param_1 + 0x2e0);
    *(undefined4 *)(iVar6 + -0x1fc) = *(undefined4 *)(param_1 + 0x2e4);
    *(undefined4 *)(iVar6 + -0x1f8) = *(undefined4 *)(param_1 + 0x2e8);
    _gleFeedbackDrawPixels(param_1,pfVar14);
    return;
  }
  if (uVar4 < 0x1c02) {
    if (uVar4 == 0x1c00) {
      if (*(float *)(param_1 + 0x31a8) == FLOAT_00108e50) {
        return;
      }
      if (*(float *)(param_1 + 0x31ac) == FLOAT_00108e50) {
        return;
      }
      if (param_2 == 0) {
        return;
      }
      if (param_3 == 0) {
        return;
      }
      iVar9 = *(int *)(param_1 + 0x50ac);
      if (iVar9 != 0 || (*(uint *)(param_1 + 0x505c) & *(uint *)(param_1 + 0x50b0)) != 0) {
        _gleUpdateMatrixFunc(param_1);
        fparam_1 = extraout_f1_00;
      }
      if (*(char *)(param_1 + 0x4691) == '\0') goto LAB_00064218;
      iVar8 = *(int *)(param_1 + 0x744c);
      piVar16 = (int *)(param_1 + 0x310);
      cVar2 = *(char *)(*(int *)(param_1 + 0x468c) + 0x79);
      if ((iVar8 != 0) && (*(int *)(iVar8 + 0xec) != 0)) {
        ((int (*)())_gleUpdateFramebufferCompleteness)(param_1,iVar8 + 0x10,iVar11,uVar12,uVar10,iVar5,iVar9,fparam_1,fparam_2,fparam_3,
                   fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
        *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x80000000;
      }
      if ((*(char *)(param_1 + 0x4664) == '\0') && (*(int *)(param_1 + 0x5430) == 0)) {
LAB_000640f4:
        uVar12 = *(uint *)(param_1 + 0x31c);
      }
      else {
        iVar11 = 0;
        piVar7 = (int *)(param_1 + 0x324);
        do {
          iVar5 = *piVar7;
          piVar7 = piVar7 + 1;
          if (iVar5 != 0) {
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
          goto LAB_000640f4;
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
        bVar1 = ((*piVar16 == 0 && *(int *)(param_1 + 0x314) == 0) && uVar12 == 0) &&
                *(int *)(param_1 + 800) == 0;
      }
      else {
        bVar1 = (((*piVar16 == 0 && *(int *)(param_1 + 0x314) == 0) &&
                 (*(uint *)(param_1 + 0x318) & 0xfffffffd) == 0) && uVar12 == 0) &&
                *(int *)(param_1 + 800) == 0;
      }
      if (!bVar1) {
        if (*(char *)(param_1 + 0x85a8) == *(char *)(param_1 + 0x85a6)) {
          uVar12 = (**(code **)(param_1 + 0x4788))
                             (*(undefined4 *)(param_1 + 0x4688),param_1 + 0x4698,piVar16);
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
              uVar3 = 0x506;
              goto LAB_0006435c;
            }
          }
        }
        else {
          _gleSwitchToNonRevertRenderer(param_1);
        }
        iVar11 = 0x13;
        do {
          *piVar16 = 0;
          piVar16 = piVar16 + 1;
          iVar11 = iVar11 + -1;
        } while (iVar11 != 0);
      }
LAB_00064218:
      *pfVar14 = *(float *)(param_1 + 0x4a44) * *(float *)(param_1 + 0x2e0) +
                 *(float *)(param_1 + 0x4a48);
      *(float *)(iVar6 + -0x1fc) =
           *(float *)(param_1 + 0x4a4c) * *(float *)(param_1 + 0x2e4) + *(float *)(param_1 + 0x4a50)
      ;
      *(float *)(iVar6 + -0x1f8) = *(float *)(param_1 + 0x4a54) * *(float *)(param_1 + 0x2e8);
      if (iVar13 != 0) {
        iVar6 = (**(code **)(param_1 + 0x46a4))
                          (*(undefined4 *)(param_1 + 0x4688),pfVar14,param_2,param_3,param_4,param_5
                           ,param_6,0);
        if (iVar6 != 0) {
          return;
        }
        if (*(int *)(iVar13 + 0x40) != 0) {
          _gleSynchronizePluginBuffer(param_1,iVar13 + 0x10);
        }
      }
      if ((*(char *)(*(int *)(param_1 + 0x468c) + 0x7b) != '\0') &&
         (iVar6 = _gleDrawPixelsFast(param_1,param_2,param_3,param_4,param_5,param_6), iVar6 != 0))
      {
        return;
      }
      (**(code **)(param_1 + 0x46a4))
                (*(undefined4 *)(param_1 + 0x4688),pfVar14,param_2,param_3,param_4,param_5,param_6,0
                );
      return;
    }
  }
  else if (uVar4 == 0x1c02) {
    return;
  }
LAB_0006434c:
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  uVar3 = 0x500;
LAB_0006435c:
  *(undefined4 *)(param_1 + 0x7574) = uVar3;
  return;
}

/* _glDrawPixels_CompExec @ 0x6437c (88 bytes) */
int _glDrawPixels_CompExec(param_1, param_2, param_3, param_4, param_5, param_6)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
{
  double fparam_1;
  double in_f2;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  
  ((int (*)())_glDrawPixels_Comp)(param_1,param_2,param_3,param_4,param_5,param_6);
  ((void (*)())_glDrawPixels_Exec)(param_1,param_2,param_3,param_4,param_5,param_6,fparam_1,in_f2,in_f3,in_f4,
                     in_f5,in_f6,in_f7,in_f8);
  return;
}

/* _glDrawPixels_NoopExec @ 0x643d4 (672 bytes) */
void _glDrawPixels_NoopExec(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  bool bVar1;
  char cVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  int iVar9;
  uint uVar10;
  int *piVar11;
  double extraout_f1;
  double extraout_f1_00;
  double extraout_f1_01;
  
  iVar9 = *(int *)(param_1 + 0x50ac);
  uVar5 = param_3;
  uVar6 = param_4;
  uVar7 = param_5;
  uVar8 = param_6;
  if (iVar9 != 0 || (*(uint *)(param_1 + 0x505c) & *(uint *)(param_1 + 0x50b0)) != 0) {
    _gleUpdateMatrixFunc(param_1);
    fparam_1 = extraout_f1;
  }
  if (*(char *)(param_1 + 0x4691) != '\0') {
    iVar4 = *(int *)(param_1 + 0x744c);
    piVar11 = (int *)(param_1 + 0x310);
    cVar2 = *(char *)(*(int *)(param_1 + 0x468c) + 0x79);
    if ((iVar4 != 0) && (*(int *)(iVar4 + 0xec) != 0)) {
      ((int (*)())_gleUpdateFramebufferCompleteness)(param_1,iVar4 + 0x10,uVar5,uVar6,uVar7,uVar8,iVar9,fparam_1,fparam_2,fparam_3,
                 fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
      *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x80000000;
      fparam_1 = extraout_f1_00;
    }
    if ((*(char *)(param_1 + 0x4664) == '\0') && (*(int *)(param_1 + 0x5430) == 0)) {
LAB_000644fc:
      uVar10 = *(uint *)(param_1 + 0x31c);
    }
    else {
      iVar9 = 0;
      piVar3 = (int *)(param_1 + 0x324);
      do {
        iVar4 = *piVar3;
        piVar3 = piVar3 + 1;
        if (iVar4 != 0) {
          *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x800000;
          break;
        }
        iVar9 = iVar9 + 1;
      } while (iVar9 < 9);
      uVar10 = *(uint *)(param_1 + 0x31c);
      if ((uVar10 & 0x15555) != 0) {
        if (*(char *)(param_1 + 0x2e54) != '\0') {
          fparam_1 = (double)_gleUpdateLightRGBASums(param_1,param_1 + 0x2c20,0);
        }
        if (*(char *)(param_1 + 0x3094) != '\0') {
          fparam_1 = (double)_gleUpdateLightRGBASums(param_1,param_1 + 0x2e60,1);
        }
        goto LAB_000644fc;
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
           (fparam_1 = extraout_f1_01, (uVar10 & 8) != (uint)(*(char *)(param_1 + 0x759d) == '\0')))
        {
          if ((uVar10 & 4) == 0) {
            uVar10 = uVar10 & 0xfffffffe;
            *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x10000000;
          }
          fparam_1 = (double)_gleUpdateDispatchCodeChange(param_1,uVar10);
          if (*(char *)(param_1 + 0x759d) == '\0') goto LAB_0006461c;
        }
      }
      else {
        fparam_1 = (double)_gleSwitchToNonRevertRenderer(param_1);
      }
      iVar9 = 0x13;
      do {
        *piVar11 = 0;
        piVar11 = piVar11 + 1;
        iVar9 = iVar9 + -1;
      } while (iVar9 != 0);
    }
  }
  if (*(char *)(param_1 + 0x759d) != '\0') {
    ((void (*)())_glDrawPixels_Exec)(param_1,param_2,param_3,param_4,param_5,param_6,fparam_1,fparam_2,fparam_3,
                       fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
    return;
  }
LAB_0006461c:
  if (*(int *)(param_1 + 0x7574) == 0) {
    *(undefined4 *)(param_1 + 0x7574) = 0x506;
  }
  return;
}

/* _glEdgeFlag_ListExec @ 0x64674 (40 bytes) */
int _glEdgeFlag_ListExec(param_1, param_2)
  undefined4 param_1;
  byte *param_2;
{
  ((int (*)())_glEdgeFlag_Exec)(param_1,(uint)*param_2);
  return 4;
}

/* _glEdgeFlag_Comp @ 0x6469c (76 bytes) */
int _glEdgeFlag_Comp(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)_gleAddListItem(param_1,PTR__glEdgeFlag_ListExec_001100ac,4);
  if (puVar1 != (undefined1 *)0x0) {
    *puVar1 = (undefined1)param_2;
  }
  return puVar1;
}

/* _glEdgeFlag_Exec @ 0x646e8 (16 bytes) */
int _glEdgeFlag_Exec(param_1, param_2)
  int param_1;
  int param_2;
{
  *(byte *)(param_1 + 0x2ec) = (byte)((uint)-param_2 >> 0x1f);
  return;
}

/* _glEdgeFlag_CompExec @ 0x646f8 (56 bytes) */
int _glEdgeFlag_CompExec(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  ((int (*)())_glEdgeFlag_Comp)(param_1,param_2);
  ((int (*)())_glEdgeFlag_Exec)(param_1,param_2);
  return;
}

/* _glEdgeFlagv_Comp @ 0x64730 (80 bytes) */
int _glEdgeFlagv_Comp(param_1, param_2)
  undefined4 param_1;
  undefined1 *param_2;
{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)_gleAddListItem(param_1,PTR__glEdgeFlag_ListExec_001100ac,4);
  if (puVar1 != (undefined1 *)0x0) {
    *puVar1 = *param_2;
  }
  return puVar1;
}

/* _glEdgeFlagv_Exec @ 0x64780 (20 bytes) */
int _glEdgeFlagv_Exec(param_1, param_2)
  int param_1;
  byte *param_2;
{
  *(byte *)(param_1 + 0x2ec) = (byte)(-(uint)*param_2 >> 0x1f);
  return;
}

/* _glEdgeFlagv_CompExec @ 0x64794 (56 bytes) */
int _glEdgeFlagv_CompExec(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  ((int (*)())_glEdgeFlagv_Comp)(param_1,param_2);
  ((int (*)())_glEdgeFlagv_Exec)(param_1,param_2);
  return;
}

/* FUN_000647d0 @ 0x647d0 (40 bytes) */
undefined4 FUN_000647d0(undefined4 param_1,double fparam_1)
{
  ((void (*)())_gleEvalMap1)(param_1,(double)(float)fparam_1);
  return 8;
}

/* _glEvalCoord1d_Comp @ 0x647f8 (84 bytes) */
double * _glEvalCoord1d_Comp(undefined4 param_1,double fparam_1)
{
  double *pdVar1;
  
  pdVar1 = (double *)_gleAddListItem(param_1,PTR__glEvalCoord1d_ListExec_001100c0,8);
  if (pdVar1 != (double *)0x0) {
    *pdVar1 = fparam_1;
  }
  return pdVar1;
}

/* _glEvalCoord1d_CompExec @ 0x64854 (72 bytes) */
void _glEvalCoord1d_CompExec(undefined4 param_1,double fparam_1)
{
  ((double * (*)())_glEvalCoord1d_Comp)(param_1,fparam_1);
  ((void (*)())_gleEvalMap1)(param_1,(double)(float)fparam_1);
  return;
}

/* _glEvalCoord1dv_Comp @ 0x64894 (80 bytes) */
int _glEvalCoord1dv_Comp(param_1, param_2)
  undefined4 param_1;
  undefined8 *param_2;
{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)_gleAddListItem(param_1,PTR__glEvalCoord1d_ListExec_001100c0,8);
  if (puVar1 != (undefined8 *)0x0) {
    *puVar1 = *param_2;
  }
  return puVar1;
}

/* _glEvalCoord1dv_Exec @ 0x648e4 (12 bytes) */
int _glEvalCoord1dv_Exec(param_1, param_2)
  undefined4 param_1;
  double *param_2;
{
  ((void (*)())_gleEvalMap1)(param_1,(double)GH_U2F((unsigned int)(*param_2)));
  return;
}

/* _glEvalCoord1dv_CompExec @ 0x648f0 (56 bytes) */
int _glEvalCoord1dv_CompExec(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  ((int (*)())_glEvalCoord1dv_Comp)(param_1,param_2);
  ((int (*)())_glEvalCoord1dv_Exec)(param_1,param_2);
  return;
}

/* _glEvalCoord1f_ListExec @ 0x64928 (40 bytes) */
int _glEvalCoord1f_ListExec(param_1, param_2)
  undefined4 param_1;
  float *param_2;
{
  ((void (*)())_gleEvalMap1)(param_1,(double)*param_2);
  return 4;
}

/* _glEvalCoord1f_Comp @ 0x64950 (84 bytes) */
float * _glEvalCoord1f_Comp(undefined4 param_1,double fparam_1)
{
  float *pfVar1;
  
  pfVar1 = (float *)_gleAddListItem(param_1,PTR__glEvalCoord1f_ListExec_001100bc,4);
  if (pfVar1 != (float *)0x0) {
    *pfVar1 = (float)fparam_1;
  }
  return pfVar1;
}

/* _glEvalCoord1f_CompExec @ 0x649a8 (68 bytes) */
void _glEvalCoord1f_CompExec(undefined4 param_1,double fparam_1)
{
  ((float * (*)())_glEvalCoord1f_Comp)(param_1,fparam_1);
  ((void (*)())_gleEvalMap1)(param_1,fparam_1);
  return;
}

/* _glEvalCoord1fv_Comp @ 0x649e8 (80 bytes) */
int _glEvalCoord1fv_Comp(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glEvalCoord1f_ListExec_001100bc,4);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = *param_2;
  }
  return puVar1;
}

/* _glEvalCoord1fv_Exec @ 0x64a38 (8 bytes) */
int _glEvalCoord1fv_Exec(param_1, param_2)
  undefined4 param_1;
  float *param_2;
{
  ((void (*)())_gleEvalMap1)(param_1,(double)*param_2);
  return;
}

/* _glEvalCoord1fv_CompExec @ 0x64a40 (56 bytes) */
int _glEvalCoord1fv_CompExec(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  ((int (*)())_glEvalCoord1fv_Comp)(param_1,param_2);
  ((int (*)())_glEvalCoord1fv_Exec)(param_1,param_2);
  return;
}

/* _glEvalCoord2d_ListExec @ 0x64a78 (44 bytes) */
undefined4 _glEvalCoord2d_ListExec(undefined4 param_1,float *param_2,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12)
{
  double in_stack_ffffffb8;
  double in_stack_ffffffc0;
  double in_stack_ffffffc8;
  double in_stack_ffffffd0;
  
  ((void (*)())_gleEvalMap2)(param_1,(double)*param_2,(double)param_2[1],fparam_3,fparam_4,fparam_5,fparam_6,
               fparam_7,fparam_8,in_stack_ffffffb8,in_stack_ffffffc0,in_stack_ffffffc8,
               in_stack_ffffffd0);
  return 8;
}

/* _glEvalCoord2d_Comp @ 0x64aa4 (108 bytes) */
float * _glEvalCoord2d_Comp(undefined4 param_1,double fparam_1,double fparam_2)
{
  float *pfVar1;
  
  pfVar1 = (float *)_gleAddListItem(param_1,PTR__glEvalCoord2d_ListExec_001100c8,8);
  if (pfVar1 != (float *)0x0) {
    *pfVar1 = (float)fparam_1;
    pfVar1[1] = (float)fparam_2;
  }
  return pfVar1;
}

/* _glEvalCoord2d_CompExec @ 0x64b1c (92 bytes) */
void _glEvalCoord2d_CompExec(undefined4 param_1,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12)
{
  undefined4 in_LR;
  
  ((float * (*)())_glEvalCoord2d_Comp)(param_1,fparam_1,fparam_2);
  ((void (*)())_gleEvalMap2)(param_1,(double)(float)fparam_1,(double)(float)fparam_2,fparam_3,fparam_4,fparam_5,
               fparam_6,fparam_7,fparam_8,(double)CONCAT44(in_LR,(*(unsigned int *)((unsigned char *)&(fparam_9) + 4))),fparam_10,fparam_11
               ,fparam_12);
  return;
}

/* _glEvalCoord2dv_Comp @ 0x64b6c (96 bytes) */
int _glEvalCoord2dv_Comp(param_1, param_2)
  undefined4 param_1;
  double *param_2;
{
  float *pfVar1;
  
  pfVar1 = (float *)_gleAddListItem(param_1,PTR__glEvalCoord2d_ListExec_001100c8,8);
  if (pfVar1 != (float *)0x0) {
    *pfVar1 = GH_U2F((unsigned int)(*param_2));
    pfVar1[1] = GH_U2F((unsigned int)(param_2[1]));
  }
  return pfVar1;
}

