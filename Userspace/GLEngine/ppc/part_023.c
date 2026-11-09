#include "decls.h"

/* _glRasterPos2sv_Exec @ 0x809b0 (744 bytes) */
void _glRasterPos2sv_Exec(int param_1,short *param_2,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  bool bVar1;
  char cVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  undefined4 in_r5;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  int iVar6;
  uint uVar7;
  int *piVar8;
  double extraout_f1;
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if ((*(int *)(param_1 + 0x744c) != 0) || (*(int *)(param_1 + 0x310) < 0)) {
      iVar6 = *(int *)(param_1 + 0x50ac);
      if (iVar6 != 0 || (*(uint *)(param_1 + 0x505c) & *(uint *)(param_1 + 0x50b0)) != 0) {
        _gleUpdateMatrixFunc(param_1);
        fparam_1 = extraout_f1;
      }
      if (*(char *)(param_1 + 0x4691) != '\0') {
        iVar5 = *(int *)(param_1 + 0x744c);
        piVar8 = (int *)(param_1 + 0x310);
        cVar2 = *(char *)(*(int *)(param_1 + 0x468c) + 0x79);
        if ((iVar5 != 0) && (*(int *)(iVar5 + 0xec) != 0)) {
          ((int (*)())_gleUpdateFramebufferCompleteness)(param_1,iVar5 + 0x10,in_r5,in_r6,in_r7,in_r8,iVar6,fparam_1,fparam_2,fparam_3,
                     fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
          *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x80000000;
        }
        if ((*(char *)(param_1 + 0x4664) == '\0') && (*(int *)(param_1 + 0x5430) == 0)) {
LAB_00080b04:
          uVar7 = *(uint *)(param_1 + 0x31c);
        }
        else {
          iVar6 = 0;
          piVar4 = (int *)(param_1 + 0x324);
          do {
            iVar5 = *piVar4;
            piVar4 = piVar4 + 1;
            if (iVar5 != 0) {
              *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x800000;
              break;
            }
            iVar6 = iVar6 + 1;
          } while (iVar6 < 9);
          uVar7 = *(uint *)(param_1 + 0x31c);
          if ((uVar7 & 0x15555) != 0) {
            if (*(char *)(param_1 + 0x2e54) != '\0') {
              _gleUpdateLightRGBASums(param_1,param_1 + 0x2c20,0);
            }
            if (*(char *)(param_1 + 0x3094) != '\0') {
              _gleUpdateLightRGBASums(param_1,param_1 + 0x2e60,1);
            }
            goto LAB_00080b04;
          }
        }
        bVar1 = cVar2 == '\0';
        if (bVar1) {
          uVar7 = uVar7 & 0x17000000;
        }
        else {
          uVar7 = uVar7 & 0x17ffffff;
        }
        if (bVar1) {
          bVar1 = ((*piVar8 == 0 && *(int *)(param_1 + 0x314) == 0) && uVar7 == 0) &&
                  *(int *)(param_1 + 800) == 0;
        }
        else {
          bVar1 = (((*piVar8 == 0 && *(int *)(param_1 + 0x314) == 0) &&
                   (*(uint *)(param_1 + 0x318) & 0xfffffffd) == 0) && uVar7 == 0) &&
                  *(int *)(param_1 + 800) == 0;
        }
        if (!bVar1) {
          if (*(char *)(param_1 + 0x85a8) == *(char *)(param_1 + 0x85a6)) {
            uVar7 = (**(code **)(param_1 + 0x4788))
                              (*(undefined4 *)(param_1 + 0x4688),param_1 + 0x4698,piVar8);
            if ((((uVar7 & 3) != (uint)*(byte *)(param_1 + 0x7580)) ||
                ((uVar7 & 4) != (uint)*(byte *)(param_1 + 0x7581))) ||
               ((uVar7 & 8) != (uint)(*(char *)(param_1 + 0x759d) == '\0'))) {
              if ((uVar7 & 4) == 0) {
                uVar7 = uVar7 & 0xfffffffe;
                *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x10000000;
              }
              _gleUpdateDispatchCodeChange(param_1,uVar7);
              if (*(char *)(param_1 + 0x759d) == '\0') {
                if (*(int *)(param_1 + 0x7574) != 0) {
                  return;
                }
                uVar3 = 0x506;
                goto LAB_00080c00;
              }
            }
          }
          else {
            _gleSwitchToNonRevertRenderer(param_1);
          }
          iVar6 = 0x13;
          do {
            *piVar8 = 0;
            piVar8 = piVar8 + 1;
            iVar6 = iVar6 + -1;
          } while (iVar6 != 0);
        }
      }
    }
    ((void (*)())_gleSetRasterPos)(param_1,(double)(float)((double)CONCAT44(0x43300000,(int)*param_2 ^ 0x80000000)
                                            - DOUBLE_00108d58),
                     (double)(float)((double)CONCAT44(0x43300000,(int)param_2[1] ^ 0x80000000) -
                                    DOUBLE_00108d58),(double)FLOAT_00108e50,(double)FLOAT_00108e54);
  }
  else {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar3 = 0x502;
LAB_00080c00:
    *(undefined4 *)(param_1 + 0x7574) = uVar3;
  }
  return;
}

/* _glRasterPos2sv_CompExec @ 0x80c98 (56 bytes) */
int _glRasterPos2sv_CompExec(param_1, param_2)
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
  
  fparam_1 = ((double (*)())_glRasterPos2sv_Comp)(param_1,param_2);
  ((void (*)())_glRasterPos2sv_Exec)(param_1,param_2,fparam_1,in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8);
  return;
}

/* _glRasterPos3d_Comp @ 0x80cd0 (40 bytes) */
void _glRasterPos3d_Comp(undefined4 param_1,double fparam_1,double fparam_2,double fparam_3)
{
  ((void (*)())_glSetRasterPos_Comp)(param_1,(double)(float)fparam_1,(double)(float)fparam_2,(double)(float)fparam_3,
             (double)FLOAT_00108e54);
  return;
}

/* _glRasterPos3d_Exec @ 0x80cf8 (744 bytes) */
void _glRasterPos3d_Exec(int param_1,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  bool bVar1;
  char cVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  undefined4 in_r5;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  int iVar6;
  uint uVar7;
  int *piVar8;
  double extraout_f1;
  double fparam_1_00;
  double fparam_2_00;
  double fparam_3_00;
  
  if (-1 < *(short *)(param_1 + 0x4a10)) {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar3 = 0x502;
    goto LAB_00080f5c;
  }
  if ((*(int *)(param_1 + 0x744c) == 0) && (-1 < *(int *)(param_1 + 0x310))) goto LAB_00080f88;
  iVar6 = *(int *)(param_1 + 0x50ac);
  fparam_1_00 = fparam_1;
  fparam_2_00 = fparam_2;
  fparam_3_00 = fparam_3;
  if (iVar6 != 0 || (*(uint *)(param_1 + 0x505c) & *(uint *)(param_1 + 0x50b0)) != 0) {
    _gleUpdateMatrixFunc(param_1);
    fparam_1_00 = extraout_f1;
  }
  if (*(char *)(param_1 + 0x4691) == '\0') goto LAB_00080f88;
  iVar5 = *(int *)(param_1 + 0x744c);
  piVar8 = (int *)(param_1 + 0x310);
  cVar2 = *(char *)(*(int *)(param_1 + 0x468c) + 0x79);
  if ((iVar5 != 0) && (*(int *)(iVar5 + 0xec) != 0)) {
    ((int (*)())_gleUpdateFramebufferCompleteness)(param_1,iVar5 + 0x10,in_r5,in_r6,in_r7,in_r8,iVar6,fparam_1_00,fparam_2_00,
               fparam_3_00,fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
    *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x80000000;
  }
  if ((*(char *)(param_1 + 0x4664) == '\0') && (*(int *)(param_1 + 0x5430) == 0)) {
LAB_00080e60:
    uVar7 = *(uint *)(param_1 + 0x31c);
  }
  else {
    iVar6 = 0;
    piVar4 = (int *)(param_1 + 0x324);
    do {
      iVar5 = *piVar4;
      piVar4 = piVar4 + 1;
      if (iVar5 != 0) {
        *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x800000;
        break;
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < 9);
    uVar7 = *(uint *)(param_1 + 0x31c);
    if ((uVar7 & 0x15555) != 0) {
      if (*(char *)(param_1 + 0x2e54) != '\0') {
        _gleUpdateLightRGBASums(param_1,param_1 + 0x2c20,0);
      }
      if (*(char *)(param_1 + 0x3094) != '\0') {
        _gleUpdateLightRGBASums(param_1,param_1 + 0x2e60,1);
      }
      goto LAB_00080e60;
    }
  }
  bVar1 = cVar2 == '\0';
  if (bVar1) {
    uVar7 = uVar7 & 0x17000000;
  }
  else {
    uVar7 = uVar7 & 0x17ffffff;
  }
  if (bVar1) {
    bVar1 = ((*piVar8 == 0 && *(int *)(param_1 + 0x314) == 0) && uVar7 == 0) &&
            *(int *)(param_1 + 800) == 0;
  }
  else {
    bVar1 = (((*piVar8 == 0 && *(int *)(param_1 + 0x314) == 0) &&
             (*(uint *)(param_1 + 0x318) & 0xfffffffd) == 0) && uVar7 == 0) &&
            *(int *)(param_1 + 800) == 0;
  }
  if (!bVar1) {
    if (*(char *)(param_1 + 0x85a8) == *(char *)(param_1 + 0x85a6)) {
      uVar7 = (**(code **)(param_1 + 0x4788))
                        (*(undefined4 *)(param_1 + 0x4688),param_1 + 0x4698,piVar8);
      if ((((uVar7 & 3) != (uint)*(byte *)(param_1 + 0x7580)) ||
          ((uVar7 & 4) != (uint)*(byte *)(param_1 + 0x7581))) ||
         ((uVar7 & 8) != (uint)(*(char *)(param_1 + 0x759d) == '\0'))) {
        if ((uVar7 & 4) == 0) {
          uVar7 = uVar7 & 0xfffffffe;
          *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x10000000;
        }
        _gleUpdateDispatchCodeChange(param_1,uVar7);
        if (*(char *)(param_1 + 0x759d) == '\0') {
          if (*(int *)(param_1 + 0x7574) != 0) {
            return;
          }
          uVar3 = 0x506;
LAB_00080f5c:
          *(undefined4 *)(param_1 + 0x7574) = uVar3;
          return;
        }
      }
    }
    else {
      _gleSwitchToNonRevertRenderer(param_1);
    }
    iVar6 = 0x13;
    do {
      *piVar8 = 0;
      piVar8 = piVar8 + 1;
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
  }
LAB_00080f88:
  ((void (*)())_gleSetRasterPos)(param_1,(double)(float)fparam_1,(double)(float)fparam_2,(double)(float)fparam_3,
                   (double)FLOAT_00108e54);
  return;
}

/* _glRasterPos3d_CompExec @ 0x80fe0 (96 bytes) */
void _glRasterPos3d_CompExec(undefined4 param_1,double fparam_1,double fparam_2,double fparam_3)
{
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  
  ((void (*)())_glRasterPos3d_Comp)(param_1,fparam_1,fparam_2,fparam_3);
  ((void (*)())_glRasterPos3d_Exec)(param_1,fparam_1,fparam_2,fparam_3,in_f4,in_f5,in_f6,in_f7,in_f8);
  return;
}

/* _glRasterPos3dv_Comp @ 0x81040 (52 bytes) */
int _glRasterPos3dv_Comp(param_1, param_2)
  undefined4 param_1;
  double *param_2;
{
  ((void (*)())_glSetRasterPos_Comp)(param_1,(double)(float)*param_2,(double)(float)param_2[1],(double)(float)param_2[2],
             (double)FLOAT_00108e54);
  return;
}

/* _glRasterPos3dv_Exec @ 0x81074 (712 bytes) */
void _glRasterPos3dv_Exec(int param_1,double *param_2,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  bool bVar1;
  char cVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  undefined4 in_r5;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  int iVar6;
  uint uVar7;
  int *piVar8;
  double extraout_f1;
  
  if (-1 < *(short *)(param_1 + 0x4a10)) {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar3 = 0x502;
    goto LAB_000812c4;
  }
  if ((*(int *)(param_1 + 0x744c) == 0) && (-1 < *(int *)(param_1 + 0x310))) goto LAB_000812f0;
  iVar6 = *(int *)(param_1 + 0x50ac);
  if (iVar6 != 0 || (*(uint *)(param_1 + 0x505c) & *(uint *)(param_1 + 0x50b0)) != 0) {
    _gleUpdateMatrixFunc(param_1);
    fparam_1 = extraout_f1;
  }
  if (*(char *)(param_1 + 0x4691) == '\0') goto LAB_000812f0;
  iVar5 = *(int *)(param_1 + 0x744c);
  piVar8 = (int *)(param_1 + 0x310);
  cVar2 = *(char *)(*(int *)(param_1 + 0x468c) + 0x79);
  if ((iVar5 != 0) && (*(int *)(iVar5 + 0xec) != 0)) {
    ((int (*)())_gleUpdateFramebufferCompleteness)(param_1,iVar5 + 0x10,in_r5,in_r6,in_r7,in_r8,iVar6,fparam_1,fparam_2,fparam_3,
               fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
    *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x80000000;
  }
  if ((*(char *)(param_1 + 0x4664) == '\0') && (*(int *)(param_1 + 0x5430) == 0)) {
LAB_000811c8:
    uVar7 = *(uint *)(param_1 + 0x31c);
  }
  else {
    iVar6 = 0;
    piVar4 = (int *)(param_1 + 0x324);
    do {
      iVar5 = *piVar4;
      piVar4 = piVar4 + 1;
      if (iVar5 != 0) {
        *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x800000;
        break;
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < 9);
    uVar7 = *(uint *)(param_1 + 0x31c);
    if ((uVar7 & 0x15555) != 0) {
      if (*(char *)(param_1 + 0x2e54) != '\0') {
        _gleUpdateLightRGBASums(param_1,param_1 + 0x2c20,0);
      }
      if (*(char *)(param_1 + 0x3094) != '\0') {
        _gleUpdateLightRGBASums(param_1,param_1 + 0x2e60,1);
      }
      goto LAB_000811c8;
    }
  }
  bVar1 = cVar2 == '\0';
  if (bVar1) {
    uVar7 = uVar7 & 0x17000000;
  }
  else {
    uVar7 = uVar7 & 0x17ffffff;
  }
  if (bVar1) {
    bVar1 = ((*piVar8 == 0 && *(int *)(param_1 + 0x314) == 0) && uVar7 == 0) &&
            *(int *)(param_1 + 800) == 0;
  }
  else {
    bVar1 = (((*piVar8 == 0 && *(int *)(param_1 + 0x314) == 0) &&
             (*(uint *)(param_1 + 0x318) & 0xfffffffd) == 0) && uVar7 == 0) &&
            *(int *)(param_1 + 800) == 0;
  }
  if (!bVar1) {
    if (*(char *)(param_1 + 0x85a8) == *(char *)(param_1 + 0x85a6)) {
      uVar7 = (**(code **)(param_1 + 0x4788))
                        (*(undefined4 *)(param_1 + 0x4688),param_1 + 0x4698,piVar8);
      if ((((uVar7 & 3) != (uint)*(byte *)(param_1 + 0x7580)) ||
          ((uVar7 & 4) != (uint)*(byte *)(param_1 + 0x7581))) ||
         ((uVar7 & 8) != (uint)(*(char *)(param_1 + 0x759d) == '\0'))) {
        if ((uVar7 & 4) == 0) {
          uVar7 = uVar7 & 0xfffffffe;
          *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x10000000;
        }
        _gleUpdateDispatchCodeChange(param_1,uVar7);
        if (*(char *)(param_1 + 0x759d) == '\0') {
          if (*(int *)(param_1 + 0x7574) != 0) {
            return;
          }
          uVar3 = 0x506;
LAB_000812c4:
          *(undefined4 *)(param_1 + 0x7574) = uVar3;
          return;
        }
      }
    }
    else {
      _gleSwitchToNonRevertRenderer(param_1);
    }
    iVar6 = 0x13;
    do {
      *piVar8 = 0;
      piVar8 = piVar8 + 1;
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
  }
LAB_000812f0:
  ((void (*)())_gleSetRasterPos)(param_1,(double)GH_U2F((unsigned int)(*param_2)),(double)GH_U2F((unsigned int)(param_2[1])),
                   (double)GH_U2F((unsigned int)(param_2[2])),(double)FLOAT_00108e54);
  return;
}

/* _glRasterPos3dv_CompExec @ 0x8133c (56 bytes) */
int _glRasterPos3dv_CompExec(param_1, param_2)
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
  
  ((int (*)())_glRasterPos3dv_Comp)(param_1,param_2);
  ((void (*)())_glRasterPos3dv_Exec)(param_1,param_2,fparam_1,in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8);
  return;
}

/* _glRasterPos3f_Comp @ 0x81374 (28 bytes) */
void _glRasterPos3f_Comp(undefined4 param_1,double fparam_1,double fparam_2,double fparam_3)
{
  ((void (*)())_glSetRasterPos_Comp)(param_1,fparam_1,fparam_2,fparam_3,(double)FLOAT_00108e54);
  return;
}

/* _glRasterPos3f_Exec @ 0x81390 (744 bytes) */
void _glRasterPos3f_Exec(int param_1,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  bool bVar1;
  char cVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  undefined4 in_r5;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  int iVar6;
  uint uVar7;
  int *piVar8;
  double extraout_f1;
  double fparam_1_00;
  double fparam_2_00;
  double fparam_3_00;
  
  if (-1 < *(short *)(param_1 + 0x4a10)) {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar3 = 0x502;
    goto LAB_000815f4;
  }
  if ((*(int *)(param_1 + 0x744c) == 0) && (-1 < *(int *)(param_1 + 0x310))) goto LAB_00081620;
  iVar6 = *(int *)(param_1 + 0x50ac);
  fparam_1_00 = fparam_1;
  fparam_2_00 = fparam_2;
  fparam_3_00 = fparam_3;
  if (iVar6 != 0 || (*(uint *)(param_1 + 0x505c) & *(uint *)(param_1 + 0x50b0)) != 0) {
    _gleUpdateMatrixFunc(param_1);
    fparam_1_00 = extraout_f1;
  }
  if (*(char *)(param_1 + 0x4691) == '\0') goto LAB_00081620;
  iVar5 = *(int *)(param_1 + 0x744c);
  piVar8 = (int *)(param_1 + 0x310);
  cVar2 = *(char *)(*(int *)(param_1 + 0x468c) + 0x79);
  if ((iVar5 != 0) && (*(int *)(iVar5 + 0xec) != 0)) {
    ((int (*)())_gleUpdateFramebufferCompleteness)(param_1,iVar5 + 0x10,in_r5,in_r6,in_r7,in_r8,iVar6,fparam_1_00,fparam_2_00,
               fparam_3_00,fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
    *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x80000000;
  }
  if ((*(char *)(param_1 + 0x4664) == '\0') && (*(int *)(param_1 + 0x5430) == 0)) {
LAB_000814f8:
    uVar7 = *(uint *)(param_1 + 0x31c);
  }
  else {
    iVar6 = 0;
    piVar4 = (int *)(param_1 + 0x324);
    do {
      iVar5 = *piVar4;
      piVar4 = piVar4 + 1;
      if (iVar5 != 0) {
        *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x800000;
        break;
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < 9);
    uVar7 = *(uint *)(param_1 + 0x31c);
    if ((uVar7 & 0x15555) != 0) {
      if (*(char *)(param_1 + 0x2e54) != '\0') {
        _gleUpdateLightRGBASums(param_1,param_1 + 0x2c20,0);
      }
      if (*(char *)(param_1 + 0x3094) != '\0') {
        _gleUpdateLightRGBASums(param_1,param_1 + 0x2e60,1);
      }
      goto LAB_000814f8;
    }
  }
  bVar1 = cVar2 == '\0';
  if (bVar1) {
    uVar7 = uVar7 & 0x17000000;
  }
  else {
    uVar7 = uVar7 & 0x17ffffff;
  }
  if (bVar1) {
    bVar1 = ((*piVar8 == 0 && *(int *)(param_1 + 0x314) == 0) && uVar7 == 0) &&
            *(int *)(param_1 + 800) == 0;
  }
  else {
    bVar1 = (((*piVar8 == 0 && *(int *)(param_1 + 0x314) == 0) &&
             (*(uint *)(param_1 + 0x318) & 0xfffffffd) == 0) && uVar7 == 0) &&
            *(int *)(param_1 + 800) == 0;
  }
  if (!bVar1) {
    if (*(char *)(param_1 + 0x85a8) == *(char *)(param_1 + 0x85a6)) {
      uVar7 = (**(code **)(param_1 + 0x4788))
                        (*(undefined4 *)(param_1 + 0x4688),param_1 + 0x4698,piVar8);
      if ((((uVar7 & 3) != (uint)*(byte *)(param_1 + 0x7580)) ||
          ((uVar7 & 4) != (uint)*(byte *)(param_1 + 0x7581))) ||
         ((uVar7 & 8) != (uint)(*(char *)(param_1 + 0x759d) == '\0'))) {
        if ((uVar7 & 4) == 0) {
          uVar7 = uVar7 & 0xfffffffe;
          *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x10000000;
        }
        _gleUpdateDispatchCodeChange(param_1,uVar7);
        if (*(char *)(param_1 + 0x759d) == '\0') {
          if (*(int *)(param_1 + 0x7574) != 0) {
            return;
          }
          uVar3 = 0x506;
LAB_000815f4:
          *(undefined4 *)(param_1 + 0x7574) = uVar3;
          return;
        }
      }
    }
    else {
      _gleSwitchToNonRevertRenderer(param_1);
    }
    iVar6 = 0x13;
    do {
      *piVar8 = 0;
      piVar8 = piVar8 + 1;
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
  }
LAB_00081620:
  ((void (*)())_gleSetRasterPos)(param_1,fparam_1,fparam_2,fparam_3,(double)FLOAT_00108e54);
  return;
}

/* _glRasterPos3f_CompExec @ 0x81678 (96 bytes) */
void _glRasterPos3f_CompExec(undefined4 param_1,double fparam_1,double fparam_2,double fparam_3)
{
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  
  ((void (*)())_glRasterPos3f_Comp)(param_1,fparam_1,fparam_2,fparam_3);
  ((void (*)())_glRasterPos3f_Exec)(param_1,fparam_1,fparam_2,fparam_3,in_f4,in_f5,in_f6,in_f7,in_f8);
  return;
}

/* _glRasterPos3fv_Comp @ 0x816d8 (40 bytes) */
int _glRasterPos3fv_Comp(param_1, param_2)
  undefined4 param_1;
  float *param_2;
{
  ((void (*)())_glSetRasterPos_Comp)(param_1,(double)*param_2,(double)param_2[1],(double)param_2[2],(double)FLOAT_00108e54);
  return;
}

/* _glRasterPos3fv_Exec @ 0x81700 (700 bytes) */
void _glRasterPos3fv_Exec(int param_1,float *param_2,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  bool bVar1;
  char cVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  undefined4 in_r5;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  int iVar6;
  uint uVar7;
  int *piVar8;
  double extraout_f1;
  
  if (-1 < *(short *)(param_1 + 0x4a10)) {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar3 = 0x502;
    goto LAB_00081950;
  }
  if ((*(int *)(param_1 + 0x744c) == 0) && (-1 < *(int *)(param_1 + 0x310))) goto LAB_0008197c;
  iVar6 = *(int *)(param_1 + 0x50ac);
  if (iVar6 != 0 || (*(uint *)(param_1 + 0x505c) & *(uint *)(param_1 + 0x50b0)) != 0) {
    _gleUpdateMatrixFunc(param_1);
    fparam_1 = extraout_f1;
  }
  if (*(char *)(param_1 + 0x4691) == '\0') goto LAB_0008197c;
  iVar5 = *(int *)(param_1 + 0x744c);
  piVar8 = (int *)(param_1 + 0x310);
  cVar2 = *(char *)(*(int *)(param_1 + 0x468c) + 0x79);
  if ((iVar5 != 0) && (*(int *)(iVar5 + 0xec) != 0)) {
    ((int (*)())_gleUpdateFramebufferCompleteness)(param_1,iVar5 + 0x10,in_r5,in_r6,in_r7,in_r8,iVar6,fparam_1,fparam_2,fparam_3,
               fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
    *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x80000000;
  }
  if ((*(char *)(param_1 + 0x4664) == '\0') && (*(int *)(param_1 + 0x5430) == 0)) {
LAB_00081854:
    uVar7 = *(uint *)(param_1 + 0x31c);
  }
  else {
    iVar6 = 0;
    piVar4 = (int *)(param_1 + 0x324);
    do {
      iVar5 = *piVar4;
      piVar4 = piVar4 + 1;
      if (iVar5 != 0) {
        *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x800000;
        break;
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < 9);
    uVar7 = *(uint *)(param_1 + 0x31c);
    if ((uVar7 & 0x15555) != 0) {
      if (*(char *)(param_1 + 0x2e54) != '\0') {
        _gleUpdateLightRGBASums(param_1,param_1 + 0x2c20,0);
      }
      if (*(char *)(param_1 + 0x3094) != '\0') {
        _gleUpdateLightRGBASums(param_1,param_1 + 0x2e60,1);
      }
      goto LAB_00081854;
    }
  }
  bVar1 = cVar2 == '\0';
  if (bVar1) {
    uVar7 = uVar7 & 0x17000000;
  }
  else {
    uVar7 = uVar7 & 0x17ffffff;
  }
  if (bVar1) {
    bVar1 = ((*piVar8 == 0 && *(int *)(param_1 + 0x314) == 0) && uVar7 == 0) &&
            *(int *)(param_1 + 800) == 0;
  }
  else {
    bVar1 = (((*piVar8 == 0 && *(int *)(param_1 + 0x314) == 0) &&
             (*(uint *)(param_1 + 0x318) & 0xfffffffd) == 0) && uVar7 == 0) &&
            *(int *)(param_1 + 800) == 0;
  }
  if (!bVar1) {
    if (*(char *)(param_1 + 0x85a8) == *(char *)(param_1 + 0x85a6)) {
      uVar7 = (**(code **)(param_1 + 0x4788))
                        (*(undefined4 *)(param_1 + 0x4688),param_1 + 0x4698,piVar8);
      if ((((uVar7 & 3) != (uint)*(byte *)(param_1 + 0x7580)) ||
          ((uVar7 & 4) != (uint)*(byte *)(param_1 + 0x7581))) ||
         ((uVar7 & 8) != (uint)(*(char *)(param_1 + 0x759d) == '\0'))) {
        if ((uVar7 & 4) == 0) {
          uVar7 = uVar7 & 0xfffffffe;
          *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x10000000;
        }
        _gleUpdateDispatchCodeChange(param_1,uVar7);
        if (*(char *)(param_1 + 0x759d) == '\0') {
          if (*(int *)(param_1 + 0x7574) != 0) {
            return;
          }
          uVar3 = 0x506;
LAB_00081950:
          *(undefined4 *)(param_1 + 0x7574) = uVar3;
          return;
        }
      }
    }
    else {
      _gleSwitchToNonRevertRenderer(param_1);
    }
    iVar6 = 0x13;
    do {
      *piVar8 = 0;
      piVar8 = piVar8 + 1;
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
  }
LAB_0008197c:
  ((void (*)())_gleSetRasterPos)(param_1,(double)*param_2,(double)param_2[1],(double)param_2[2],
                   (double)FLOAT_00108e54);
  return;
}

/* _glRasterPos3fv_CompExec @ 0x819bc (56 bytes) */
int _glRasterPos3fv_CompExec(param_1, param_2)
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
  
  ((int (*)())_glRasterPos3fv_Comp)(param_1,param_2);
  ((void (*)())_glRasterPos3fv_Exec)(param_1,param_2,fparam_1,in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8);
  return;
}

/* _glRasterPos3i_Comp @ 0x819f4 (132 bytes) */
double _glRasterPos3i_Comp(undefined4 param_1,uint param_2,uint param_3,uint param_4)
{
  double extraout_f1;
  
  ((void (*)())_glSetRasterPos_Comp)(param_1,(double)(float)((double)CONCAT44(0x43300000,param_2 ^ 0x80000000) -
                                    DOUBLE_00108d58),
             (double)(float)((double)CONCAT44(0x43300000,param_3 ^ 0x80000000) - DOUBLE_00108d58),
             (double)(float)((double)CONCAT44(0x43300000,param_4 ^ 0x80000000) - DOUBLE_00108d58),
             (double)FLOAT_00108e54);
  return extraout_f1;
}

/* _glRasterPos3i_Exec @ 0x81a78 (756 bytes) */
void _glRasterPos3i_Exec(int param_1,uint param_2,uint param_3,uint param_4,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  bool bVar1;
  char cVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  undefined4 in_r7;
  undefined4 in_r8;
  int iVar7;
  uint uVar8;
  int *piVar9;
  double extraout_f1;
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if ((*(int *)(param_1 + 0x744c) != 0) || (*(int *)(param_1 + 0x310) < 0)) {
      iVar7 = *(int *)(param_1 + 0x50ac);
      uVar8 = param_3;
      uVar6 = param_4;
      if (iVar7 != 0 || (*(uint *)(param_1 + 0x505c) & *(uint *)(param_1 + 0x50b0)) != 0) {
        _gleUpdateMatrixFunc(param_1);
        fparam_1 = extraout_f1;
      }
      if (*(char *)(param_1 + 0x4691) != '\0') {
        iVar5 = *(int *)(param_1 + 0x744c);
        piVar9 = (int *)(param_1 + 0x310);
        cVar2 = *(char *)(*(int *)(param_1 + 0x468c) + 0x79);
        if ((iVar5 != 0) && (*(int *)(iVar5 + 0xec) != 0)) {
          ((int (*)())_gleUpdateFramebufferCompleteness)(param_1,iVar5 + 0x10,uVar8,uVar6,in_r7,in_r8,iVar7,fparam_1,fparam_2,fparam_3,
                     fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
          *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x80000000;
        }
        if ((*(char *)(param_1 + 0x4664) == '\0') && (*(int *)(param_1 + 0x5430) == 0)) {
LAB_00081bd4:
          uVar8 = *(uint *)(param_1 + 0x31c);
        }
        else {
          iVar7 = 0;
          piVar4 = (int *)(param_1 + 0x324);
          do {
            iVar5 = *piVar4;
            piVar4 = piVar4 + 1;
            if (iVar5 != 0) {
              *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x800000;
              break;
            }
            iVar7 = iVar7 + 1;
          } while (iVar7 < 9);
          uVar8 = *(uint *)(param_1 + 0x31c);
          if ((uVar8 & 0x15555) != 0) {
            if (*(char *)(param_1 + 0x2e54) != '\0') {
              _gleUpdateLightRGBASums(param_1,param_1 + 0x2c20,0);
            }
            if (*(char *)(param_1 + 0x3094) != '\0') {
              _gleUpdateLightRGBASums(param_1,param_1 + 0x2e60,1);
            }
            goto LAB_00081bd4;
          }
        }
        bVar1 = cVar2 == '\0';
        if (bVar1) {
          uVar8 = uVar8 & 0x17000000;
        }
        else {
          uVar8 = uVar8 & 0x17ffffff;
        }
        if (bVar1) {
          bVar1 = ((*piVar9 == 0 && *(int *)(param_1 + 0x314) == 0) && uVar8 == 0) &&
                  *(int *)(param_1 + 800) == 0;
        }
        else {
          bVar1 = (((*piVar9 == 0 && *(int *)(param_1 + 0x314) == 0) &&
                   (*(uint *)(param_1 + 0x318) & 0xfffffffd) == 0) && uVar8 == 0) &&
                  *(int *)(param_1 + 800) == 0;
        }
        if (!bVar1) {
          if (*(char *)(param_1 + 0x85a8) == *(char *)(param_1 + 0x85a6)) {
            uVar8 = (**(code **)(param_1 + 0x4788))
                              (*(undefined4 *)(param_1 + 0x4688),param_1 + 0x4698,piVar9);
            if ((((uVar8 & 3) != (uint)*(byte *)(param_1 + 0x7580)) ||
                ((uVar8 & 4) != (uint)*(byte *)(param_1 + 0x7581))) ||
               ((uVar8 & 8) != (uint)(*(char *)(param_1 + 0x759d) == '\0'))) {
              if ((uVar8 & 4) == 0) {
                uVar8 = uVar8 & 0xfffffffe;
                *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x10000000;
              }
              _gleUpdateDispatchCodeChange(param_1,uVar8);
              if (*(char *)(param_1 + 0x759d) == '\0') {
                if (*(int *)(param_1 + 0x7574) != 0) {
                  return;
                }
                uVar3 = 0x506;
                goto LAB_00081cd0;
              }
            }
          }
          else {
            _gleSwitchToNonRevertRenderer(param_1);
          }
          iVar7 = 0x13;
          do {
            *piVar9 = 0;
            piVar9 = piVar9 + 1;
            iVar7 = iVar7 + -1;
          } while (iVar7 != 0);
        }
      }
    }
    ((void (*)())_gleSetRasterPos)(param_1,(double)(float)((double)CONCAT44(0x43300000,param_2 ^ 0x80000000) -
                                            DOUBLE_00108d58),
                     (double)(float)((double)CONCAT44(0x43300000,param_3 ^ 0x80000000) -
                                    DOUBLE_00108d58),
                     (double)(float)((double)CONCAT44(0x43300000,param_4 ^ 0x80000000) -
                                    DOUBLE_00108d58),(double)FLOAT_00108e54);
  }
  else {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar3 = 0x502;
LAB_00081cd0:
    *(undefined4 *)(param_1 + 0x7574) = uVar3;
  }
  return;
}

/* _glRasterPos3i_CompExec @ 0x81d6c (72 bytes) */
int _glRasterPos3i_CompExec(param_1, param_2, param_3, param_4)
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
  
  fparam_1 = ((double (*)())_glRasterPos3i_Comp)(param_1,param_2,param_3,param_4);
  ((void (*)())_glRasterPos3i_Exec)(param_1,param_2,param_3,param_4,fparam_1,in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,
                      in_f8);
  return;
}

/* _glRasterPos3iv_Comp @ 0x81db4 (144 bytes) */
double _glRasterPos3iv_Comp(undefined4 param_1,uint *param_2)
{
  double extraout_f1;
  
  ((void (*)())_glSetRasterPos_Comp)(param_1,(double)(float)((double)CONCAT44(0x43300000,*param_2 ^ 0x80000000) -
                                    DOUBLE_00108d58),
             (double)(float)((double)CONCAT44(0x43300000,param_2[1] ^ 0x80000000) - DOUBLE_00108d58)
             ,(double)(float)((double)CONCAT44(0x43300000,param_2[2] ^ 0x80000000) - DOUBLE_00108d58
                             ),(double)FLOAT_00108e54);
  return extraout_f1;
}

/* _glRasterPos3iv_Exec @ 0x81e44 (760 bytes) */
void _glRasterPos3iv_Exec(int param_1,uint *param_2,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  bool bVar1;
  char cVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  undefined4 in_r5;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  int iVar6;
  uint uVar7;
  int *piVar8;
  double extraout_f1;
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if ((*(int *)(param_1 + 0x744c) != 0) || (*(int *)(param_1 + 0x310) < 0)) {
      iVar6 = *(int *)(param_1 + 0x50ac);
      if (iVar6 != 0 || (*(uint *)(param_1 + 0x505c) & *(uint *)(param_1 + 0x50b0)) != 0) {
        _gleUpdateMatrixFunc(param_1);
        fparam_1 = extraout_f1;
      }
      if (*(char *)(param_1 + 0x4691) != '\0') {
        iVar5 = *(int *)(param_1 + 0x744c);
        piVar8 = (int *)(param_1 + 0x310);
        cVar2 = *(char *)(*(int *)(param_1 + 0x468c) + 0x79);
        if ((iVar5 != 0) && (*(int *)(iVar5 + 0xec) != 0)) {
          ((int (*)())_gleUpdateFramebufferCompleteness)(param_1,iVar5 + 0x10,in_r5,in_r6,in_r7,in_r8,iVar6,fparam_1,fparam_2,fparam_3,
                     fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
          *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x80000000;
        }
        if ((*(char *)(param_1 + 0x4664) == '\0') && (*(int *)(param_1 + 0x5430) == 0)) {
LAB_00081f98:
          uVar7 = *(uint *)(param_1 + 0x31c);
        }
        else {
          iVar6 = 0;
          piVar4 = (int *)(param_1 + 0x324);
          do {
            iVar5 = *piVar4;
            piVar4 = piVar4 + 1;
            if (iVar5 != 0) {
              *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x800000;
              break;
            }
            iVar6 = iVar6 + 1;
          } while (iVar6 < 9);
          uVar7 = *(uint *)(param_1 + 0x31c);
          if ((uVar7 & 0x15555) != 0) {
            if (*(char *)(param_1 + 0x2e54) != '\0') {
              _gleUpdateLightRGBASums(param_1,param_1 + 0x2c20,0);
            }
            if (*(char *)(param_1 + 0x3094) != '\0') {
              _gleUpdateLightRGBASums(param_1,param_1 + 0x2e60,1);
            }
            goto LAB_00081f98;
          }
        }
        bVar1 = cVar2 == '\0';
        if (bVar1) {
          uVar7 = uVar7 & 0x17000000;
        }
        else {
          uVar7 = uVar7 & 0x17ffffff;
        }
        if (bVar1) {
          bVar1 = ((*piVar8 == 0 && *(int *)(param_1 + 0x314) == 0) && uVar7 == 0) &&
                  *(int *)(param_1 + 800) == 0;
        }
        else {
          bVar1 = (((*piVar8 == 0 && *(int *)(param_1 + 0x314) == 0) &&
                   (*(uint *)(param_1 + 0x318) & 0xfffffffd) == 0) && uVar7 == 0) &&
                  *(int *)(param_1 + 800) == 0;
        }
        if (!bVar1) {
          if (*(char *)(param_1 + 0x85a8) == *(char *)(param_1 + 0x85a6)) {
            uVar7 = (**(code **)(param_1 + 0x4788))
                              (*(undefined4 *)(param_1 + 0x4688),param_1 + 0x4698,piVar8);
            if ((((uVar7 & 3) != (uint)*(byte *)(param_1 + 0x7580)) ||
                ((uVar7 & 4) != (uint)*(byte *)(param_1 + 0x7581))) ||
               ((uVar7 & 8) != (uint)(*(char *)(param_1 + 0x759d) == '\0'))) {
              if ((uVar7 & 4) == 0) {
                uVar7 = uVar7 & 0xfffffffe;
                *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x10000000;
              }
              _gleUpdateDispatchCodeChange(param_1,uVar7);
              if (*(char *)(param_1 + 0x759d) == '\0') {
                if (*(int *)(param_1 + 0x7574) != 0) {
                  return;
                }
                uVar3 = 0x506;
                goto LAB_00082094;
              }
            }
          }
          else {
            _gleSwitchToNonRevertRenderer(param_1);
          }
          iVar6 = 0x13;
          do {
            *piVar8 = 0;
            piVar8 = piVar8 + 1;
            iVar6 = iVar6 + -1;
          } while (iVar6 != 0);
        }
      }
    }
    ((void (*)())_gleSetRasterPos)(param_1,(double)(float)((double)CONCAT44(0x43300000,*param_2 ^ 0x80000000) -
                                            DOUBLE_00108d58),
                     (double)(float)((double)CONCAT44(0x43300000,param_2[1] ^ 0x80000000) -
                                    DOUBLE_00108d58),
                     (double)(float)((double)CONCAT44(0x43300000,param_2[2] ^ 0x80000000) -
                                    DOUBLE_00108d58),(double)FLOAT_00108e54);
  }
  else {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar3 = 0x502;
LAB_00082094:
    *(undefined4 *)(param_1 + 0x7574) = uVar3;
  }
  return;
}

/* _glRasterPos3iv_CompExec @ 0x8213c (56 bytes) */
int _glRasterPos3iv_CompExec(param_1, param_2)
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
  
  fparam_1 = ((double (*)())_glRasterPos3iv_Comp)(param_1,param_2);
  ((void (*)())_glRasterPos3iv_Exec)(param_1,param_2,fparam_1,in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8);
  return;
}

/* _glRasterPos3s_Comp @ 0x82174 (132 bytes) */
double _glRasterPos3s_Comp(undefined4 param_1,uint param_2,uint param_3,uint param_4)
{
  double extraout_f1;
  
  ((void (*)())_glSetRasterPos_Comp)(param_1,(double)(float)((double)CONCAT44(0x43300000,param_2 ^ 0x80000000) -
                                    DOUBLE_00108d58),
             (double)(float)((double)CONCAT44(0x43300000,param_3 ^ 0x80000000) - DOUBLE_00108d58),
             (double)(float)((double)CONCAT44(0x43300000,param_4 ^ 0x80000000) - DOUBLE_00108d58),
             (double)FLOAT_00108e54);
  return extraout_f1;
}

/* _glRasterPos3s_Exec @ 0x821f8 (756 bytes) */
void _glRasterPos3s_Exec(int param_1,uint param_2,uint param_3,uint param_4,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  bool bVar1;
  char cVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  undefined4 in_r7;
  undefined4 in_r8;
  int iVar7;
  uint uVar8;
  int *piVar9;
  double extraout_f1;
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if ((*(int *)(param_1 + 0x744c) != 0) || (*(int *)(param_1 + 0x310) < 0)) {
      iVar7 = *(int *)(param_1 + 0x50ac);
      uVar8 = param_3;
      uVar6 = param_4;
      if (iVar7 != 0 || (*(uint *)(param_1 + 0x505c) & *(uint *)(param_1 + 0x50b0)) != 0) {
        _gleUpdateMatrixFunc(param_1);
        fparam_1 = extraout_f1;
      }
      if (*(char *)(param_1 + 0x4691) != '\0') {
        iVar5 = *(int *)(param_1 + 0x744c);
        piVar9 = (int *)(param_1 + 0x310);
        cVar2 = *(char *)(*(int *)(param_1 + 0x468c) + 0x79);
        if ((iVar5 != 0) && (*(int *)(iVar5 + 0xec) != 0)) {
          ((int (*)())_gleUpdateFramebufferCompleteness)(param_1,iVar5 + 0x10,uVar8,uVar6,in_r7,in_r8,iVar7,fparam_1,fparam_2,fparam_3,
                     fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
          *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x80000000;
        }
        if ((*(char *)(param_1 + 0x4664) == '\0') && (*(int *)(param_1 + 0x5430) == 0)) {
LAB_00082354:
          uVar8 = *(uint *)(param_1 + 0x31c);
        }
        else {
          iVar7 = 0;
          piVar4 = (int *)(param_1 + 0x324);
          do {
            iVar5 = *piVar4;
            piVar4 = piVar4 + 1;
            if (iVar5 != 0) {
              *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x800000;
              break;
            }
            iVar7 = iVar7 + 1;
          } while (iVar7 < 9);
          uVar8 = *(uint *)(param_1 + 0x31c);
          if ((uVar8 & 0x15555) != 0) {
            if (*(char *)(param_1 + 0x2e54) != '\0') {
              _gleUpdateLightRGBASums(param_1,param_1 + 0x2c20,0);
            }
            if (*(char *)(param_1 + 0x3094) != '\0') {
              _gleUpdateLightRGBASums(param_1,param_1 + 0x2e60,1);
            }
            goto LAB_00082354;
          }
        }
        bVar1 = cVar2 == '\0';
        if (bVar1) {
          uVar8 = uVar8 & 0x17000000;
        }
        else {
          uVar8 = uVar8 & 0x17ffffff;
        }
        if (bVar1) {
          bVar1 = ((*piVar9 == 0 && *(int *)(param_1 + 0x314) == 0) && uVar8 == 0) &&
                  *(int *)(param_1 + 800) == 0;
        }
        else {
          bVar1 = (((*piVar9 == 0 && *(int *)(param_1 + 0x314) == 0) &&
                   (*(uint *)(param_1 + 0x318) & 0xfffffffd) == 0) && uVar8 == 0) &&
                  *(int *)(param_1 + 800) == 0;
        }
        if (!bVar1) {
          if (*(char *)(param_1 + 0x85a8) == *(char *)(param_1 + 0x85a6)) {
            uVar8 = (**(code **)(param_1 + 0x4788))
                              (*(undefined4 *)(param_1 + 0x4688),param_1 + 0x4698,piVar9);
            if ((((uVar8 & 3) != (uint)*(byte *)(param_1 + 0x7580)) ||
                ((uVar8 & 4) != (uint)*(byte *)(param_1 + 0x7581))) ||
               ((uVar8 & 8) != (uint)(*(char *)(param_1 + 0x759d) == '\0'))) {
              if ((uVar8 & 4) == 0) {
                uVar8 = uVar8 & 0xfffffffe;
                *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x10000000;
              }
              _gleUpdateDispatchCodeChange(param_1,uVar8);
              if (*(char *)(param_1 + 0x759d) == '\0') {
                if (*(int *)(param_1 + 0x7574) != 0) {
                  return;
                }
                uVar3 = 0x506;
                goto LAB_00082450;
              }
            }
          }
          else {
            _gleSwitchToNonRevertRenderer(param_1);
          }
          iVar7 = 0x13;
          do {
            *piVar9 = 0;
            piVar9 = piVar9 + 1;
            iVar7 = iVar7 + -1;
          } while (iVar7 != 0);
        }
      }
    }
    ((void (*)())_gleSetRasterPos)(param_1,(double)(float)((double)CONCAT44(0x43300000,param_2 ^ 0x80000000) -
                                            DOUBLE_00108d58),
                     (double)(float)((double)CONCAT44(0x43300000,param_3 ^ 0x80000000) -
                                    DOUBLE_00108d58),
                     (double)(float)((double)CONCAT44(0x43300000,param_4 ^ 0x80000000) -
                                    DOUBLE_00108d58),(double)FLOAT_00108e54);
  }
  else {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar3 = 0x502;
LAB_00082450:
    *(undefined4 *)(param_1 + 0x7574) = uVar3;
  }
  return;
}

/* _glRasterPos3s_CompExec @ 0x824ec (72 bytes) */
int _glRasterPos3s_CompExec(param_1, param_2, param_3, param_4)
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
  
  fparam_1 = ((double (*)())_glRasterPos3s_Comp)(param_1,param_2,param_3,param_4);
  ((void (*)())_glRasterPos3s_Exec)(param_1,param_2,param_3,param_4,fparam_1,in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,
                      in_f8);
  return;
}

/* _glRasterPos3sv_Comp @ 0x82534 (144 bytes) */
double _glRasterPos3sv_Comp(undefined4 param_1,short *param_2)
{
  double extraout_f1;
  
  ((void (*)())_glSetRasterPos_Comp)(param_1,(double)(float)((double)CONCAT44(0x43300000,(int)*param_2 ^ 0x80000000) -
                                    DOUBLE_00108d58),
             (double)(float)((double)CONCAT44(0x43300000,(int)param_2[1] ^ 0x80000000) -
                            DOUBLE_00108d58),
             (double)(float)((double)CONCAT44(0x43300000,(int)param_2[2] ^ 0x80000000) -
                            DOUBLE_00108d58),(double)FLOAT_00108e54);
  return extraout_f1;
}

/* _glRasterPos3sv_Exec @ 0x825c4 (760 bytes) */
void _glRasterPos3sv_Exec(int param_1,short *param_2,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  bool bVar1;
  char cVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  undefined4 in_r5;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  int iVar6;
  uint uVar7;
  int *piVar8;
  double extraout_f1;
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if ((*(int *)(param_1 + 0x744c) != 0) || (*(int *)(param_1 + 0x310) < 0)) {
      iVar6 = *(int *)(param_1 + 0x50ac);
      if (iVar6 != 0 || (*(uint *)(param_1 + 0x505c) & *(uint *)(param_1 + 0x50b0)) != 0) {
        _gleUpdateMatrixFunc(param_1);
        fparam_1 = extraout_f1;
      }
      if (*(char *)(param_1 + 0x4691) != '\0') {
        iVar5 = *(int *)(param_1 + 0x744c);
        piVar8 = (int *)(param_1 + 0x310);
        cVar2 = *(char *)(*(int *)(param_1 + 0x468c) + 0x79);
        if ((iVar5 != 0) && (*(int *)(iVar5 + 0xec) != 0)) {
          ((int (*)())_gleUpdateFramebufferCompleteness)(param_1,iVar5 + 0x10,in_r5,in_r6,in_r7,in_r8,iVar6,fparam_1,fparam_2,fparam_3,
                     fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
          *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x80000000;
        }
        if ((*(char *)(param_1 + 0x4664) == '\0') && (*(int *)(param_1 + 0x5430) == 0)) {
LAB_00082718:
          uVar7 = *(uint *)(param_1 + 0x31c);
        }
        else {
          iVar6 = 0;
          piVar4 = (int *)(param_1 + 0x324);
          do {
            iVar5 = *piVar4;
            piVar4 = piVar4 + 1;
            if (iVar5 != 0) {
              *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x800000;
              break;
            }
            iVar6 = iVar6 + 1;
          } while (iVar6 < 9);
          uVar7 = *(uint *)(param_1 + 0x31c);
          if ((uVar7 & 0x15555) != 0) {
            if (*(char *)(param_1 + 0x2e54) != '\0') {
              _gleUpdateLightRGBASums(param_1,param_1 + 0x2c20,0);
            }
            if (*(char *)(param_1 + 0x3094) != '\0') {
              _gleUpdateLightRGBASums(param_1,param_1 + 0x2e60,1);
            }
            goto LAB_00082718;
          }
        }
        bVar1 = cVar2 == '\0';
        if (bVar1) {
          uVar7 = uVar7 & 0x17000000;
        }
        else {
          uVar7 = uVar7 & 0x17ffffff;
        }
        if (bVar1) {
          bVar1 = ((*piVar8 == 0 && *(int *)(param_1 + 0x314) == 0) && uVar7 == 0) &&
                  *(int *)(param_1 + 800) == 0;
        }
        else {
          bVar1 = (((*piVar8 == 0 && *(int *)(param_1 + 0x314) == 0) &&
                   (*(uint *)(param_1 + 0x318) & 0xfffffffd) == 0) && uVar7 == 0) &&
                  *(int *)(param_1 + 800) == 0;
        }
        if (!bVar1) {
          if (*(char *)(param_1 + 0x85a8) == *(char *)(param_1 + 0x85a6)) {
            uVar7 = (**(code **)(param_1 + 0x4788))
                              (*(undefined4 *)(param_1 + 0x4688),param_1 + 0x4698,piVar8);
            if ((((uVar7 & 3) != (uint)*(byte *)(param_1 + 0x7580)) ||
                ((uVar7 & 4) != (uint)*(byte *)(param_1 + 0x7581))) ||
               ((uVar7 & 8) != (uint)(*(char *)(param_1 + 0x759d) == '\0'))) {
              if ((uVar7 & 4) == 0) {
                uVar7 = uVar7 & 0xfffffffe;
                *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x10000000;
              }
              _gleUpdateDispatchCodeChange(param_1,uVar7);
              if (*(char *)(param_1 + 0x759d) == '\0') {
                if (*(int *)(param_1 + 0x7574) != 0) {
                  return;
                }
                uVar3 = 0x506;
                goto LAB_00082814;
              }
            }
          }
          else {
            _gleSwitchToNonRevertRenderer(param_1);
          }
          iVar6 = 0x13;
          do {
            *piVar8 = 0;
            piVar8 = piVar8 + 1;
            iVar6 = iVar6 + -1;
          } while (iVar6 != 0);
        }
      }
    }
    ((void (*)())_gleSetRasterPos)(param_1,(double)(float)((double)CONCAT44(0x43300000,(int)*param_2 ^ 0x80000000)
                                            - DOUBLE_00108d58),
                     (double)(float)((double)CONCAT44(0x43300000,(int)param_2[1] ^ 0x80000000) -
                                    DOUBLE_00108d58),
                     (double)(float)((double)CONCAT44(0x43300000,(int)param_2[2] ^ 0x80000000) -
                                    DOUBLE_00108d58),(double)FLOAT_00108e54);
  }
  else {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar3 = 0x502;
LAB_00082814:
    *(undefined4 *)(param_1 + 0x7574) = uVar3;
  }
  return;
}

/* _glRasterPos3sv_CompExec @ 0x828bc (56 bytes) */
int _glRasterPos3sv_CompExec(param_1, param_2)
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
  
  fparam_1 = ((double (*)())_glRasterPos3sv_Comp)(param_1,param_2);
  ((void (*)())_glRasterPos3sv_Exec)(param_1,param_2,fparam_1,in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8);
  return;
}

/* _glRasterPos4d_Comp @ 0x828f4 (20 bytes) */
void _glRasterPos4d_Comp(undefined4 param_1,double fparam_1,double fparam_2,double fparam_3,double fparam_4)
{
  ((void (*)())_glSetRasterPos_Comp)(param_1,(double)(float)fparam_1,(double)(float)fparam_2,(double)(float)fparam_3,
             (double)(float)fparam_4);
  return;
}

/* _glRasterPos4d_Exec @ 0x82908 (708 bytes) */
void _glRasterPos4d_Exec(int param_1,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  bool bVar1;
  char cVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  undefined4 in_r5;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  int iVar6;
  uint uVar7;
  int *piVar8;
  double extraout_f1;
  double fparam_1_00;
  double fparam_2_00;
  double fparam_3_00;
  double fparam_4_00;
  
  if (-1 < *(short *)(param_1 + 0x4a10)) {
    if (*(int *)(param_1 + 0x7574) != 0) goto LAB_00082bc0;
    uVar3 = 0x502;
LAB_00082b5c:
    *(undefined4 *)(param_1 + 0x7574) = uVar3;
LAB_00082bc0:
    FUN_00008b68();
    return;
  }
  if ((*(int *)(param_1 + 0x744c) == 0) && (-1 < *(int *)(param_1 + 0x310))) goto LAB_00082b88;
  iVar6 = *(int *)(param_1 + 0x50ac);
  fparam_1_00 = fparam_1;
  fparam_2_00 = fparam_2;
  fparam_3_00 = fparam_3;
  fparam_4_00 = fparam_4;
  if (iVar6 != 0 || (*(uint *)(param_1 + 0x505c) & *(uint *)(param_1 + 0x50b0)) != 0) {
    _gleUpdateMatrixFunc(param_1);
    fparam_1_00 = extraout_f1;
  }
  if (*(char *)(param_1 + 0x4691) == '\0') goto LAB_00082b88;
  iVar5 = *(int *)(param_1 + 0x744c);
  piVar8 = (int *)(param_1 + 0x310);
  cVar2 = *(char *)(*(int *)(param_1 + 0x468c) + 0x79);
  if ((iVar5 != 0) && (*(int *)(iVar5 + 0xec) != 0)) {
    ((int (*)())_gleUpdateFramebufferCompleteness)(param_1,iVar5 + 0x10,in_r5,in_r6,in_r7,in_r8,iVar6,fparam_1_00,fparam_2_00,
               fparam_3_00,fparam_4_00,fparam_5,fparam_6,fparam_7,fparam_8);
    *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x80000000;
  }
  if ((*(char *)(param_1 + 0x4664) == '\0') && (*(int *)(param_1 + 0x5430) == 0)) {
LAB_00082a60:
    uVar7 = *(uint *)(param_1 + 0x31c);
  }
  else {
    iVar6 = 0;
    piVar4 = (int *)(param_1 + 0x324);
    do {
      iVar5 = *piVar4;
      piVar4 = piVar4 + 1;
      if (iVar5 != 0) {
        *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x800000;
        break;
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < 9);
    uVar7 = *(uint *)(param_1 + 0x31c);
    if ((uVar7 & 0x15555) != 0) {
      if (*(char *)(param_1 + 0x2e54) != '\0') {
        _gleUpdateLightRGBASums(param_1,param_1 + 0x2c20,0);
      }
      if (*(char *)(param_1 + 0x3094) != '\0') {
        _gleUpdateLightRGBASums(param_1,param_1 + 0x2e60,1);
      }
      goto LAB_00082a60;
    }
  }
  bVar1 = cVar2 == '\0';
  if (bVar1) {
    uVar7 = uVar7 & 0x17000000;
  }
  else {
    uVar7 = uVar7 & 0x17ffffff;
  }
  if (bVar1) {
    bVar1 = ((*piVar8 == 0 && *(int *)(param_1 + 0x314) == 0) && uVar7 == 0) &&
            *(int *)(param_1 + 800) == 0;
  }
  else {
    bVar1 = (((*piVar8 == 0 && *(int *)(param_1 + 0x314) == 0) &&
             (*(uint *)(param_1 + 0x318) & 0xfffffffd) == 0) && uVar7 == 0) &&
            *(int *)(param_1 + 800) == 0;
  }
  if (bVar1) goto LAB_00082b88;
  if (*(char *)(param_1 + 0x85a8) == *(char *)(param_1 + 0x85a6)) {
    uVar7 = (**(code **)(param_1 + 0x4788))
                      (*(undefined4 *)(param_1 + 0x4688),param_1 + 0x4698,piVar8);
    if ((((uVar7 & 3) != (uint)*(byte *)(param_1 + 0x7580)) ||
        ((uVar7 & 4) != (uint)*(byte *)(param_1 + 0x7581))) ||
       ((uVar7 & 8) != (uint)(*(char *)(param_1 + 0x759d) == '\0'))) {
      if ((uVar7 & 4) == 0) {
        uVar7 = uVar7 & 0xfffffffe;
        *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x10000000;
      }
      _gleUpdateDispatchCodeChange(param_1,uVar7);
      if (*(char *)(param_1 + 0x759d) == '\0') {
        if (*(int *)(param_1 + 0x7574) != 0) goto LAB_00082bc0;
        uVar3 = 0x506;
        goto LAB_00082b5c;
      }
    }
  }
  else {
    _gleSwitchToNonRevertRenderer(param_1);
  }
  iVar6 = 0x13;
  do {
    *piVar8 = 0;
    piVar8 = piVar8 + 1;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
LAB_00082b88:
  ((void (*)())_gleSetRasterPos)(param_1,(double)(float)fparam_1,(double)(float)fparam_2,(double)(float)fparam_3,
                   (double)(float)fparam_4);
  return;
}

/* _glRasterPos4d_CompExec @ 0x82bcc (96 bytes) */
void _glRasterPos4d_CompExec(undefined4 param_1,double fparam_1,double fparam_2,double fparam_3,double fparam_4)
{
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  
  ((void (*)())_glRasterPos4d_Comp)(param_1,fparam_1,fparam_2,fparam_3,fparam_4);
  ((void (*)())_glRasterPos4d_Exec)(param_1,fparam_1,fparam_2,fparam_3,fparam_4,in_f5,in_f6,in_f7,in_f8);
  return;
}

/* _glRasterPos4dv_Comp @ 0x82c2c (36 bytes) */
int _glRasterPos4dv_Comp(param_1, param_2)
  undefined4 param_1;
  double *param_2;
{
  ((void (*)())_glSetRasterPos_Comp)(param_1,(double)(float)*param_2,(double)(float)param_2[1],(double)(float)param_2[2],
             (double)(float)param_2[3]);
  return;
}

/* _glRasterPos4dv_Exec @ 0x82c50 (704 bytes) */
void _glRasterPos4dv_Exec(int param_1,double *param_2,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  bool bVar1;
  char cVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  undefined4 in_r5;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  int iVar6;
  uint uVar7;
  int *piVar8;
  double extraout_f1;
  
  if (-1 < *(short *)(param_1 + 0x4a10)) {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar3 = 0x502;
    goto LAB_00082e98;
  }
  if ((*(int *)(param_1 + 0x744c) == 0) && (-1 < *(int *)(param_1 + 0x310))) goto LAB_00082ec4;
  iVar6 = *(int *)(param_1 + 0x50ac);
  if (iVar6 != 0 || (*(uint *)(param_1 + 0x505c) & *(uint *)(param_1 + 0x50b0)) != 0) {
    _gleUpdateMatrixFunc(param_1);
    fparam_1 = extraout_f1;
  }
  if (*(char *)(param_1 + 0x4691) == '\0') goto LAB_00082ec4;
  iVar5 = *(int *)(param_1 + 0x744c);
  piVar8 = (int *)(param_1 + 0x310);
  cVar2 = *(char *)(*(int *)(param_1 + 0x468c) + 0x79);
  if ((iVar5 != 0) && (*(int *)(iVar5 + 0xec) != 0)) {
    ((int (*)())_gleUpdateFramebufferCompleteness)(param_1,iVar5 + 0x10,in_r5,in_r6,in_r7,in_r8,iVar6,fparam_1,fparam_2,fparam_3,
               fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
    *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x80000000;
  }
  if ((*(char *)(param_1 + 0x4664) == '\0') && (*(int *)(param_1 + 0x5430) == 0)) {
LAB_00082d9c:
    uVar7 = *(uint *)(param_1 + 0x31c);
  }
  else {
    iVar6 = 0;
    piVar4 = (int *)(param_1 + 0x324);
    do {
      iVar5 = *piVar4;
      piVar4 = piVar4 + 1;
      if (iVar5 != 0) {
        *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x800000;
        break;
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < 9);
    uVar7 = *(uint *)(param_1 + 0x31c);
    if ((uVar7 & 0x15555) != 0) {
      if (*(char *)(param_1 + 0x2e54) != '\0') {
        _gleUpdateLightRGBASums(param_1,param_1 + 0x2c20,0);
      }
      if (*(char *)(param_1 + 0x3094) != '\0') {
        _gleUpdateLightRGBASums(param_1,param_1 + 0x2e60,1);
      }
      goto LAB_00082d9c;
    }
  }
  bVar1 = cVar2 == '\0';
  if (bVar1) {
    uVar7 = uVar7 & 0x17000000;
  }
  else {
    uVar7 = uVar7 & 0x17ffffff;
  }
  if (bVar1) {
    bVar1 = ((*piVar8 == 0 && *(int *)(param_1 + 0x314) == 0) && uVar7 == 0) &&
            *(int *)(param_1 + 800) == 0;
  }
  else {
    bVar1 = (((*piVar8 == 0 && *(int *)(param_1 + 0x314) == 0) &&
             (*(uint *)(param_1 + 0x318) & 0xfffffffd) == 0) && uVar7 == 0) &&
            *(int *)(param_1 + 800) == 0;
  }
  if (!bVar1) {
    if (*(char *)(param_1 + 0x85a8) == *(char *)(param_1 + 0x85a6)) {
      uVar7 = (**(code **)(param_1 + 0x4788))
                        (*(undefined4 *)(param_1 + 0x4688),param_1 + 0x4698,piVar8);
      if ((((uVar7 & 3) != (uint)*(byte *)(param_1 + 0x7580)) ||
          ((uVar7 & 4) != (uint)*(byte *)(param_1 + 0x7581))) ||
         ((uVar7 & 8) != (uint)(*(char *)(param_1 + 0x759d) == '\0'))) {
        if ((uVar7 & 4) == 0) {
          uVar7 = uVar7 & 0xfffffffe;
          *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x10000000;
        }
        _gleUpdateDispatchCodeChange(param_1,uVar7);
        if (*(char *)(param_1 + 0x759d) == '\0') {
          if (*(int *)(param_1 + 0x7574) != 0) {
            return;
          }
          uVar3 = 0x506;
LAB_00082e98:
          *(undefined4 *)(param_1 + 0x7574) = uVar3;
          return;
        }
      }
    }
    else {
      _gleSwitchToNonRevertRenderer(param_1);
    }
    iVar6 = 0x13;
    do {
      *piVar8 = 0;
      piVar8 = piVar8 + 1;
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
  }
LAB_00082ec4:
  ((void (*)())_gleSetRasterPos)(param_1,(double)GH_U2F((unsigned int)(*param_2)),(double)GH_U2F((unsigned int)(param_2[1])),
                   (double)GH_U2F((unsigned int)(param_2[2])),(double)GH_U2F((unsigned int)(param_2[3])));
  return;
}

/* _glRasterPos4dv_CompExec @ 0x82f10 (56 bytes) */
int _glRasterPos4dv_CompExec(param_1, param_2)
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
  
  ((int (*)())_glRasterPos4dv_Comp)(param_1,param_2);
  ((void (*)())_glRasterPos4dv_Exec)(param_1,param_2,fparam_1,in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8);
  return;
}

/* _glRasterPos4f_Exec @ 0x82f4c (708 bytes) */
void _glRasterPos4f_Exec(int param_1,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  bool bVar1;
  char cVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  undefined4 in_r5;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  int iVar6;
  uint uVar7;
  int *piVar8;
  double extraout_f1;
  double fparam_1_00;
  double fparam_2_00;
  double fparam_3_00;
  double fparam_4_00;
  
  if (-1 < *(short *)(param_1 + 0x4a10)) {
    if (*(int *)(param_1 + 0x7574) != 0) goto LAB_00083204;
    uVar3 = 0x502;
LAB_000831a0:
    *(undefined4 *)(param_1 + 0x7574) = uVar3;
LAB_00083204:
    FUN_00008b68();
    return;
  }
  if ((*(int *)(param_1 + 0x744c) == 0) && (-1 < *(int *)(param_1 + 0x310))) goto LAB_000831cc;
  iVar6 = *(int *)(param_1 + 0x50ac);
  fparam_1_00 = fparam_1;
  fparam_2_00 = fparam_2;
  fparam_3_00 = fparam_3;
  fparam_4_00 = fparam_4;
  if (iVar6 != 0 || (*(uint *)(param_1 + 0x505c) & *(uint *)(param_1 + 0x50b0)) != 0) {
    _gleUpdateMatrixFunc(param_1);
    fparam_1_00 = extraout_f1;
  }
  if (*(char *)(param_1 + 0x4691) == '\0') goto LAB_000831cc;
  iVar5 = *(int *)(param_1 + 0x744c);
  piVar8 = (int *)(param_1 + 0x310);
  cVar2 = *(char *)(*(int *)(param_1 + 0x468c) + 0x79);
  if ((iVar5 != 0) && (*(int *)(iVar5 + 0xec) != 0)) {
    ((int (*)())_gleUpdateFramebufferCompleteness)(param_1,iVar5 + 0x10,in_r5,in_r6,in_r7,in_r8,iVar6,fparam_1_00,fparam_2_00,
               fparam_3_00,fparam_4_00,fparam_5,fparam_6,fparam_7,fparam_8);
    *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x80000000;
  }
  if ((*(char *)(param_1 + 0x4664) == '\0') && (*(int *)(param_1 + 0x5430) == 0)) {
LAB_000830a4:
    uVar7 = *(uint *)(param_1 + 0x31c);
  }
  else {
    iVar6 = 0;
    piVar4 = (int *)(param_1 + 0x324);
    do {
      iVar5 = *piVar4;
      piVar4 = piVar4 + 1;
      if (iVar5 != 0) {
        *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x800000;
        break;
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < 9);
    uVar7 = *(uint *)(param_1 + 0x31c);
    if ((uVar7 & 0x15555) != 0) {
      if (*(char *)(param_1 + 0x2e54) != '\0') {
        _gleUpdateLightRGBASums(param_1,param_1 + 0x2c20,0);
      }
      if (*(char *)(param_1 + 0x3094) != '\0') {
        _gleUpdateLightRGBASums(param_1,param_1 + 0x2e60,1);
      }
      goto LAB_000830a4;
    }
  }
  bVar1 = cVar2 == '\0';
  if (bVar1) {
    uVar7 = uVar7 & 0x17000000;
  }
  else {
    uVar7 = uVar7 & 0x17ffffff;
  }
  if (bVar1) {
    bVar1 = ((*piVar8 == 0 && *(int *)(param_1 + 0x314) == 0) && uVar7 == 0) &&
            *(int *)(param_1 + 800) == 0;
  }
  else {
    bVar1 = (((*piVar8 == 0 && *(int *)(param_1 + 0x314) == 0) &&
             (*(uint *)(param_1 + 0x318) & 0xfffffffd) == 0) && uVar7 == 0) &&
            *(int *)(param_1 + 800) == 0;
  }
  if (bVar1) goto LAB_000831cc;
  if (*(char *)(param_1 + 0x85a8) == *(char *)(param_1 + 0x85a6)) {
    uVar7 = (**(code **)(param_1 + 0x4788))
                      (*(undefined4 *)(param_1 + 0x4688),param_1 + 0x4698,piVar8);
    if ((((uVar7 & 3) != (uint)*(byte *)(param_1 + 0x7580)) ||
        ((uVar7 & 4) != (uint)*(byte *)(param_1 + 0x7581))) ||
       ((uVar7 & 8) != (uint)(*(char *)(param_1 + 0x759d) == '\0'))) {
      if ((uVar7 & 4) == 0) {
        uVar7 = uVar7 & 0xfffffffe;
        *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x10000000;
      }
      _gleUpdateDispatchCodeChange(param_1,uVar7);
      if (*(char *)(param_1 + 0x759d) == '\0') {
        if (*(int *)(param_1 + 0x7574) != 0) goto LAB_00083204;
        uVar3 = 0x506;
        goto LAB_000831a0;
      }
    }
  }
  else {
    _gleSwitchToNonRevertRenderer(param_1);
  }
  iVar6 = 0x13;
  do {
    *piVar8 = 0;
    piVar8 = piVar8 + 1;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
LAB_000831cc:
  ((void (*)())_gleSetRasterPos)(param_1,fparam_1,fparam_2,fparam_3,fparam_4);
  return;
}

/* _glRasterPos4f_CompExec @ 0x83210 (96 bytes) */
void _glRasterPos4f_CompExec(undefined4 param_1,double fparam_1,double fparam_2,double fparam_3,double fparam_4)
{
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  
  _glRasterPos4f_Comp(param_1,fparam_1,fparam_2,fparam_3,fparam_4);
  ((void (*)())_glRasterPos4f_Exec)(param_1,fparam_1,fparam_2,fparam_3,fparam_4,in_f5,in_f6,in_f7,in_f8);
  return;
}

/* _glRasterPos4fv_Comp @ 0x83270 (20 bytes) */
int _glRasterPos4fv_Comp(param_1, param_2)
  undefined4 param_1;
  float *param_2;
{
  ((void (*)())_glSetRasterPos_Comp)(param_1,(double)*param_2,(double)param_2[1],(double)param_2[2],(double)param_2[3]);
  return;
}

/* _glRasterPos4fv_Exec @ 0x83284 (688 bytes) */
void _glRasterPos4fv_Exec(int param_1,float *param_2,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  bool bVar1;
  char cVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  undefined4 in_r5;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  int iVar6;
  uint uVar7;
  int *piVar8;
  double extraout_f1;
  
  if (-1 < *(short *)(param_1 + 0x4a10)) {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar3 = 0x502;
    goto LAB_000834cc;
  }
  if ((*(int *)(param_1 + 0x744c) == 0) && (-1 < *(int *)(param_1 + 0x310))) goto LAB_000834f8;
  iVar6 = *(int *)(param_1 + 0x50ac);
  if (iVar6 != 0 || (*(uint *)(param_1 + 0x505c) & *(uint *)(param_1 + 0x50b0)) != 0) {
    _gleUpdateMatrixFunc(param_1);
    fparam_1 = extraout_f1;
  }
  if (*(char *)(param_1 + 0x4691) == '\0') goto LAB_000834f8;
  iVar5 = *(int *)(param_1 + 0x744c);
  piVar8 = (int *)(param_1 + 0x310);
  cVar2 = *(char *)(*(int *)(param_1 + 0x468c) + 0x79);
  if ((iVar5 != 0) && (*(int *)(iVar5 + 0xec) != 0)) {
    ((int (*)())_gleUpdateFramebufferCompleteness)(param_1,iVar5 + 0x10,in_r5,in_r6,in_r7,in_r8,iVar6,fparam_1,fparam_2,fparam_3,
               fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
    *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x80000000;
  }
  if ((*(char *)(param_1 + 0x4664) == '\0') && (*(int *)(param_1 + 0x5430) == 0)) {
LAB_000833d0:
    uVar7 = *(uint *)(param_1 + 0x31c);
  }
  else {
    iVar6 = 0;
    piVar4 = (int *)(param_1 + 0x324);
    do {
      iVar5 = *piVar4;
      piVar4 = piVar4 + 1;
      if (iVar5 != 0) {
        *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x800000;
        break;
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < 9);
    uVar7 = *(uint *)(param_1 + 0x31c);
    if ((uVar7 & 0x15555) != 0) {
      if (*(char *)(param_1 + 0x2e54) != '\0') {
        _gleUpdateLightRGBASums(param_1,param_1 + 0x2c20,0);
      }
      if (*(char *)(param_1 + 0x3094) != '\0') {
        _gleUpdateLightRGBASums(param_1,param_1 + 0x2e60,1);
      }
      goto LAB_000833d0;
    }
  }
  bVar1 = cVar2 == '\0';
  if (bVar1) {
    uVar7 = uVar7 & 0x17000000;
  }
  else {
    uVar7 = uVar7 & 0x17ffffff;
  }
  if (bVar1) {
    bVar1 = ((*piVar8 == 0 && *(int *)(param_1 + 0x314) == 0) && uVar7 == 0) &&
            *(int *)(param_1 + 800) == 0;
  }
  else {
    bVar1 = (((*piVar8 == 0 && *(int *)(param_1 + 0x314) == 0) &&
             (*(uint *)(param_1 + 0x318) & 0xfffffffd) == 0) && uVar7 == 0) &&
            *(int *)(param_1 + 800) == 0;
  }
  if (!bVar1) {
    if (*(char *)(param_1 + 0x85a8) == *(char *)(param_1 + 0x85a6)) {
      uVar7 = (**(code **)(param_1 + 0x4788))
                        (*(undefined4 *)(param_1 + 0x4688),param_1 + 0x4698,piVar8);
      if ((((uVar7 & 3) != (uint)*(byte *)(param_1 + 0x7580)) ||
          ((uVar7 & 4) != (uint)*(byte *)(param_1 + 0x7581))) ||
         ((uVar7 & 8) != (uint)(*(char *)(param_1 + 0x759d) == '\0'))) {
        if ((uVar7 & 4) == 0) {
          uVar7 = uVar7 & 0xfffffffe;
          *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x10000000;
        }
        _gleUpdateDispatchCodeChange(param_1,uVar7);
        if (*(char *)(param_1 + 0x759d) == '\0') {
          if (*(int *)(param_1 + 0x7574) != 0) {
            return;
          }
          uVar3 = 0x506;
LAB_000834cc:
          *(undefined4 *)(param_1 + 0x7574) = uVar3;
          return;
        }
      }
    }
    else {
      _gleSwitchToNonRevertRenderer(param_1);
    }
    iVar6 = 0x13;
    do {
      *piVar8 = 0;
      piVar8 = piVar8 + 1;
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
  }
LAB_000834f8:
  ((void (*)())_gleSetRasterPos)(param_1,(double)*param_2,(double)param_2[1],(double)param_2[2],(double)param_2[3]
                  );
  return;
}

/* _glRasterPos4fv_CompExec @ 0x83534 (56 bytes) */
int _glRasterPos4fv_CompExec(param_1, param_2)
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
  
  ((int (*)())_glRasterPos4fv_Comp)(param_1,param_2);
  ((void (*)())_glRasterPos4fv_Exec)(param_1,param_2,fparam_1,in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8);
  return;
}

/* _glRasterPos4i_Comp @ 0x8356c (144 bytes) */
double _glRasterPos4i_Comp(undefined4 param_1,uint param_2,uint param_3,uint param_4,uint param_5)
{
  double extraout_f1;
  
  ((void (*)())_glSetRasterPos_Comp)(param_1,(double)(float)((double)CONCAT44(0x43300000,param_2 ^ 0x80000000) -
                                    DOUBLE_00108d58),
             (double)(float)((double)CONCAT44(0x43300000,param_3 ^ 0x80000000) - DOUBLE_00108d58),
             (double)(float)((double)CONCAT44(0x43300000,param_4 ^ 0x80000000) - DOUBLE_00108d58),
             (double)(float)((double)CONCAT44(0x43300000,param_5 ^ 0x80000000) - DOUBLE_00108d58));
  return extraout_f1;
}

/* _glRasterPos4i_Exec @ 0x835fc (772 bytes) */
void _glRasterPos4i_Exec(int param_1,uint param_2,uint param_3,uint param_4,uint param_5,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  bool bVar1;
  char cVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  undefined4 in_r8;
  int iVar8;
  uint uVar9;
  int *piVar10;
  double extraout_f1;
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if ((*(int *)(param_1 + 0x744c) != 0) || (*(int *)(param_1 + 0x310) < 0)) {
      iVar8 = *(int *)(param_1 + 0x50ac);
      uVar9 = param_3;
      uVar6 = param_4;
      uVar7 = param_5;
      if (iVar8 != 0 || (*(uint *)(param_1 + 0x505c) & *(uint *)(param_1 + 0x50b0)) != 0) {
        _gleUpdateMatrixFunc(param_1);
        fparam_1 = extraout_f1;
      }
      if (*(char *)(param_1 + 0x4691) != '\0') {
        iVar5 = *(int *)(param_1 + 0x744c);
        piVar10 = (int *)(param_1 + 0x310);
        cVar2 = *(char *)(*(int *)(param_1 + 0x468c) + 0x79);
        if ((iVar5 != 0) && (*(int *)(iVar5 + 0xec) != 0)) {
          ((int (*)())_gleUpdateFramebufferCompleteness)(param_1,iVar5 + 0x10,uVar9,uVar6,uVar7,in_r8,iVar8,fparam_1,fparam_2,fparam_3,
                     fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
          *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x80000000;
        }
        if ((*(char *)(param_1 + 0x4664) == '\0') && (*(int *)(param_1 + 0x5430) == 0)) {
LAB_0008375c:
          uVar9 = *(uint *)(param_1 + 0x31c);
        }
        else {
          iVar8 = 0;
          piVar4 = (int *)(param_1 + 0x324);
          do {
            iVar5 = *piVar4;
            piVar4 = piVar4 + 1;
            if (iVar5 != 0) {
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
            goto LAB_0008375c;
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
               ((uVar9 & 8) != (uint)(*(char *)(param_1 + 0x759d) == '\0'))) {
              if ((uVar9 & 4) == 0) {
                uVar9 = uVar9 & 0xfffffffe;
                *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x10000000;
              }
              _gleUpdateDispatchCodeChange(param_1,uVar9);
              if (*(char *)(param_1 + 0x759d) == '\0') {
                if (*(int *)(param_1 + 0x7574) != 0) {
                  return;
                }
                uVar3 = 0x506;
                goto LAB_00083858;
              }
            }
          }
          else {
            _gleSwitchToNonRevertRenderer(param_1);
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
    ((void (*)())_gleSetRasterPos)(param_1,(double)(float)((double)CONCAT44(0x43300000,param_2 ^ 0x80000000) -
                                            DOUBLE_00108d58),
                     (double)(float)((double)CONCAT44(0x43300000,param_3 ^ 0x80000000) -
                                    DOUBLE_00108d58),
                     (double)(float)((double)CONCAT44(0x43300000,param_4 ^ 0x80000000) -
                                    DOUBLE_00108d58),
                     (double)(float)((double)CONCAT44(0x43300000,param_5 ^ 0x80000000) -
                                    DOUBLE_00108d58));
  }
  else {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar3 = 0x502;
LAB_00083858:
    *(undefined4 *)(param_1 + 0x7574) = uVar3;
  }
  return;
}

/* _glRasterPos4i_CompExec @ 0x83900 (80 bytes) */
int _glRasterPos4i_CompExec(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  double fparam_1;
  double in_f2;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  
  fparam_1 = ((double (*)())_glRasterPos4i_Comp)(param_1,param_2,param_3,param_4,param_5);
  ((void (*)())_glRasterPos4i_Exec)(param_1,param_2,param_3,param_4,param_5,fparam_1,in_f2,in_f3,in_f4,in_f5,in_f6
                      ,in_f7,in_f8);
  return;
}

/* _glRasterPos4iv_Comp @ 0x83950 (160 bytes) */
double _glRasterPos4iv_Comp(undefined4 param_1,uint *param_2)
{
  double extraout_f1;
  
  ((void (*)())_glSetRasterPos_Comp)(param_1,(double)(float)((double)CONCAT44(0x43300000,*param_2 ^ 0x80000000) -
                                    DOUBLE_00108d58),
             (double)(float)((double)CONCAT44(0x43300000,param_2[1] ^ 0x80000000) - DOUBLE_00108d58)
             ,(double)(float)((double)CONCAT44(0x43300000,param_2[2] ^ 0x80000000) - DOUBLE_00108d58
                             ),
             (double)(float)((double)CONCAT44(0x43300000,param_2[3] ^ 0x80000000) - DOUBLE_00108d58)
            );
  return extraout_f1;
}

/* _glRasterPos4iv_Exec @ 0x839f0 (776 bytes) */
void _glRasterPos4iv_Exec(int param_1,uint *param_2,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  bool bVar1;
  char cVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  undefined4 in_r5;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  int iVar6;
  uint uVar7;
  int *piVar8;
  double extraout_f1;
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if ((*(int *)(param_1 + 0x744c) != 0) || (*(int *)(param_1 + 0x310) < 0)) {
      iVar6 = *(int *)(param_1 + 0x50ac);
      if (iVar6 != 0 || (*(uint *)(param_1 + 0x505c) & *(uint *)(param_1 + 0x50b0)) != 0) {
        _gleUpdateMatrixFunc(param_1);
        fparam_1 = extraout_f1;
      }
      if (*(char *)(param_1 + 0x4691) != '\0') {
        iVar5 = *(int *)(param_1 + 0x744c);
        piVar8 = (int *)(param_1 + 0x310);
        cVar2 = *(char *)(*(int *)(param_1 + 0x468c) + 0x79);
        if ((iVar5 != 0) && (*(int *)(iVar5 + 0xec) != 0)) {
          ((int (*)())_gleUpdateFramebufferCompleteness)(param_1,iVar5 + 0x10,in_r5,in_r6,in_r7,in_r8,iVar6,fparam_1,fparam_2,fparam_3,
                     fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
          *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x80000000;
        }
        if ((*(char *)(param_1 + 0x4664) == '\0') && (*(int *)(param_1 + 0x5430) == 0)) {
LAB_00083b44:
          uVar7 = *(uint *)(param_1 + 0x31c);
        }
        else {
          iVar6 = 0;
          piVar4 = (int *)(param_1 + 0x324);
          do {
            iVar5 = *piVar4;
            piVar4 = piVar4 + 1;
            if (iVar5 != 0) {
              *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x800000;
              break;
            }
            iVar6 = iVar6 + 1;
          } while (iVar6 < 9);
          uVar7 = *(uint *)(param_1 + 0x31c);
          if ((uVar7 & 0x15555) != 0) {
            if (*(char *)(param_1 + 0x2e54) != '\0') {
              _gleUpdateLightRGBASums(param_1,param_1 + 0x2c20,0);
            }
            if (*(char *)(param_1 + 0x3094) != '\0') {
              _gleUpdateLightRGBASums(param_1,param_1 + 0x2e60,1);
            }
            goto LAB_00083b44;
          }
        }
        bVar1 = cVar2 == '\0';
        if (bVar1) {
          uVar7 = uVar7 & 0x17000000;
        }
        else {
          uVar7 = uVar7 & 0x17ffffff;
        }
        if (bVar1) {
          bVar1 = ((*piVar8 == 0 && *(int *)(param_1 + 0x314) == 0) && uVar7 == 0) &&
                  *(int *)(param_1 + 800) == 0;
        }
        else {
          bVar1 = (((*piVar8 == 0 && *(int *)(param_1 + 0x314) == 0) &&
                   (*(uint *)(param_1 + 0x318) & 0xfffffffd) == 0) && uVar7 == 0) &&
                  *(int *)(param_1 + 800) == 0;
        }
        if (!bVar1) {
          if (*(char *)(param_1 + 0x85a8) == *(char *)(param_1 + 0x85a6)) {
            uVar7 = (**(code **)(param_1 + 0x4788))
                              (*(undefined4 *)(param_1 + 0x4688),param_1 + 0x4698,piVar8);
            if ((((uVar7 & 3) != (uint)*(byte *)(param_1 + 0x7580)) ||
                ((uVar7 & 4) != (uint)*(byte *)(param_1 + 0x7581))) ||
               ((uVar7 & 8) != (uint)(*(char *)(param_1 + 0x759d) == '\0'))) {
              if ((uVar7 & 4) == 0) {
                uVar7 = uVar7 & 0xfffffffe;
                *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x10000000;
              }
              _gleUpdateDispatchCodeChange(param_1,uVar7);
              if (*(char *)(param_1 + 0x759d) == '\0') {
                if (*(int *)(param_1 + 0x7574) != 0) {
                  return;
                }
                uVar3 = 0x506;
                goto LAB_00083c40;
              }
            }
          }
          else {
            _gleSwitchToNonRevertRenderer(param_1);
          }
          iVar6 = 0x13;
          do {
            *piVar8 = 0;
            piVar8 = piVar8 + 1;
            iVar6 = iVar6 + -1;
          } while (iVar6 != 0);
        }
      }
    }
    ((void (*)())_gleSetRasterPos)(param_1,(double)(float)((double)CONCAT44(0x43300000,*param_2 ^ 0x80000000) -
                                            DOUBLE_00108d58),
                     (double)(float)((double)CONCAT44(0x43300000,param_2[1] ^ 0x80000000) -
                                    DOUBLE_00108d58),
                     (double)(float)((double)CONCAT44(0x43300000,param_2[2] ^ 0x80000000) -
                                    DOUBLE_00108d58),
                     (double)(float)((double)CONCAT44(0x43300000,param_2[3] ^ 0x80000000) -
                                    DOUBLE_00108d58));
  }
  else {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar3 = 0x502;
LAB_00083c40:
    *(undefined4 *)(param_1 + 0x7574) = uVar3;
  }
  return;
}

/* _glRasterPos4iv_CompExec @ 0x83cf8 (56 bytes) */
int _glRasterPos4iv_CompExec(param_1, param_2)
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
  
  fparam_1 = ((double (*)())_glRasterPos4iv_Comp)(param_1,param_2);
  ((void (*)())_glRasterPos4iv_Exec)(param_1,param_2,fparam_1,in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8);
  return;
}

/* _glRasterPos4s_Comp @ 0x83d30 (144 bytes) */
double _glRasterPos4s_Comp(undefined4 param_1,uint param_2,uint param_3,uint param_4,uint param_5)
{
  double extraout_f1;
  
  ((void (*)())_glSetRasterPos_Comp)(param_1,(double)(float)((double)CONCAT44(0x43300000,param_2 ^ 0x80000000) -
                                    DOUBLE_00108d58),
             (double)(float)((double)CONCAT44(0x43300000,param_3 ^ 0x80000000) - DOUBLE_00108d58),
             (double)(float)((double)CONCAT44(0x43300000,param_4 ^ 0x80000000) - DOUBLE_00108d58),
             (double)(float)((double)CONCAT44(0x43300000,param_5 ^ 0x80000000) - DOUBLE_00108d58));
  return extraout_f1;
}

/* _glRasterPos4s_Exec @ 0x83dc0 (772 bytes) */
void _glRasterPos4s_Exec(int param_1,uint param_2,uint param_3,uint param_4,uint param_5,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  bool bVar1;
  char cVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  undefined4 in_r8;
  int iVar8;
  uint uVar9;
  int *piVar10;
  double extraout_f1;
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if ((*(int *)(param_1 + 0x744c) != 0) || (*(int *)(param_1 + 0x310) < 0)) {
      iVar8 = *(int *)(param_1 + 0x50ac);
      uVar9 = param_3;
      uVar6 = param_4;
      uVar7 = param_5;
      if (iVar8 != 0 || (*(uint *)(param_1 + 0x505c) & *(uint *)(param_1 + 0x50b0)) != 0) {
        _gleUpdateMatrixFunc(param_1);
        fparam_1 = extraout_f1;
      }
      if (*(char *)(param_1 + 0x4691) != '\0') {
        iVar5 = *(int *)(param_1 + 0x744c);
        piVar10 = (int *)(param_1 + 0x310);
        cVar2 = *(char *)(*(int *)(param_1 + 0x468c) + 0x79);
        if ((iVar5 != 0) && (*(int *)(iVar5 + 0xec) != 0)) {
          ((int (*)())_gleUpdateFramebufferCompleteness)(param_1,iVar5 + 0x10,uVar9,uVar6,uVar7,in_r8,iVar8,fparam_1,fparam_2,fparam_3,
                     fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
          *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x80000000;
        }
        if ((*(char *)(param_1 + 0x4664) == '\0') && (*(int *)(param_1 + 0x5430) == 0)) {
LAB_00083f20:
          uVar9 = *(uint *)(param_1 + 0x31c);
        }
        else {
          iVar8 = 0;
          piVar4 = (int *)(param_1 + 0x324);
          do {
            iVar5 = *piVar4;
            piVar4 = piVar4 + 1;
            if (iVar5 != 0) {
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
            goto LAB_00083f20;
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
               ((uVar9 & 8) != (uint)(*(char *)(param_1 + 0x759d) == '\0'))) {
              if ((uVar9 & 4) == 0) {
                uVar9 = uVar9 & 0xfffffffe;
                *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x10000000;
              }
              _gleUpdateDispatchCodeChange(param_1,uVar9);
              if (*(char *)(param_1 + 0x759d) == '\0') {
                if (*(int *)(param_1 + 0x7574) != 0) {
                  return;
                }
                uVar3 = 0x506;
                goto LAB_0008401c;
              }
            }
          }
          else {
            _gleSwitchToNonRevertRenderer(param_1);
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
    ((void (*)())_gleSetRasterPos)(param_1,(double)(float)((double)CONCAT44(0x43300000,param_2 ^ 0x80000000) -
                                            DOUBLE_00108d58),
                     (double)(float)((double)CONCAT44(0x43300000,param_3 ^ 0x80000000) -
                                    DOUBLE_00108d58),
                     (double)(float)((double)CONCAT44(0x43300000,param_4 ^ 0x80000000) -
                                    DOUBLE_00108d58),
                     (double)(float)((double)CONCAT44(0x43300000,param_5 ^ 0x80000000) -
                                    DOUBLE_00108d58));
  }
  else {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar3 = 0x502;
LAB_0008401c:
    *(undefined4 *)(param_1 + 0x7574) = uVar3;
  }
  return;
}

/* _glRasterPos4s_CompExec @ 0x840c4 (80 bytes) */
int _glRasterPos4s_CompExec(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  double fparam_1;
  double in_f2;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  
  fparam_1 = ((double (*)())_glRasterPos4s_Comp)(param_1,param_2,param_3,param_4,param_5);
  ((void (*)())_glRasterPos4s_Exec)(param_1,param_2,param_3,param_4,param_5,fparam_1,in_f2,in_f3,in_f4,in_f5,in_f6
                      ,in_f7,in_f8);
  return;
}

/* _glRasterPos4sv_Comp @ 0x84114 (160 bytes) */
double _glRasterPos4sv_Comp(undefined4 param_1,short *param_2)
{
  double extraout_f1;
  
  ((void (*)())_glSetRasterPos_Comp)(param_1,(double)(float)((double)CONCAT44(0x43300000,(int)*param_2 ^ 0x80000000) -
                                    DOUBLE_00108d58),
             (double)(float)((double)CONCAT44(0x43300000,(int)param_2[1] ^ 0x80000000) -
                            DOUBLE_00108d58),
             (double)(float)((double)CONCAT44(0x43300000,(int)param_2[2] ^ 0x80000000) -
                            DOUBLE_00108d58),
             (double)(float)((double)CONCAT44(0x43300000,(int)param_2[3] ^ 0x80000000) -
                            DOUBLE_00108d58));
  return extraout_f1;
}

/* _glRasterPos4sv_Exec @ 0x841b4 (776 bytes) */
void _glRasterPos4sv_Exec(int param_1,short *param_2,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  bool bVar1;
  char cVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  undefined4 in_r5;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  int iVar6;
  uint uVar7;
  int *piVar8;
  double extraout_f1;
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if ((*(int *)(param_1 + 0x744c) != 0) || (*(int *)(param_1 + 0x310) < 0)) {
      iVar6 = *(int *)(param_1 + 0x50ac);
      if (iVar6 != 0 || (*(uint *)(param_1 + 0x505c) & *(uint *)(param_1 + 0x50b0)) != 0) {
        _gleUpdateMatrixFunc(param_1);
        fparam_1 = extraout_f1;
      }
      if (*(char *)(param_1 + 0x4691) != '\0') {
        iVar5 = *(int *)(param_1 + 0x744c);
        piVar8 = (int *)(param_1 + 0x310);
        cVar2 = *(char *)(*(int *)(param_1 + 0x468c) + 0x79);
        if ((iVar5 != 0) && (*(int *)(iVar5 + 0xec) != 0)) {
          ((int (*)())_gleUpdateFramebufferCompleteness)(param_1,iVar5 + 0x10,in_r5,in_r6,in_r7,in_r8,iVar6,fparam_1,fparam_2,fparam_3,
                     fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
          *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x80000000;
        }
        if ((*(char *)(param_1 + 0x4664) == '\0') && (*(int *)(param_1 + 0x5430) == 0)) {
LAB_00084308:
          uVar7 = *(uint *)(param_1 + 0x31c);
        }
        else {
          iVar6 = 0;
          piVar4 = (int *)(param_1 + 0x324);
          do {
            iVar5 = *piVar4;
            piVar4 = piVar4 + 1;
            if (iVar5 != 0) {
              *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x800000;
              break;
            }
            iVar6 = iVar6 + 1;
          } while (iVar6 < 9);
          uVar7 = *(uint *)(param_1 + 0x31c);
          if ((uVar7 & 0x15555) != 0) {
            if (*(char *)(param_1 + 0x2e54) != '\0') {
              _gleUpdateLightRGBASums(param_1,param_1 + 0x2c20,0);
            }
            if (*(char *)(param_1 + 0x3094) != '\0') {
              _gleUpdateLightRGBASums(param_1,param_1 + 0x2e60,1);
            }
            goto LAB_00084308;
          }
        }
        bVar1 = cVar2 == '\0';
        if (bVar1) {
          uVar7 = uVar7 & 0x17000000;
        }
        else {
          uVar7 = uVar7 & 0x17ffffff;
        }
        if (bVar1) {
          bVar1 = ((*piVar8 == 0 && *(int *)(param_1 + 0x314) == 0) && uVar7 == 0) &&
                  *(int *)(param_1 + 800) == 0;
        }
        else {
          bVar1 = (((*piVar8 == 0 && *(int *)(param_1 + 0x314) == 0) &&
                   (*(uint *)(param_1 + 0x318) & 0xfffffffd) == 0) && uVar7 == 0) &&
                  *(int *)(param_1 + 800) == 0;
        }
        if (!bVar1) {
          if (*(char *)(param_1 + 0x85a8) == *(char *)(param_1 + 0x85a6)) {
            uVar7 = (**(code **)(param_1 + 0x4788))
                              (*(undefined4 *)(param_1 + 0x4688),param_1 + 0x4698,piVar8);
            if ((((uVar7 & 3) != (uint)*(byte *)(param_1 + 0x7580)) ||
                ((uVar7 & 4) != (uint)*(byte *)(param_1 + 0x7581))) ||
               ((uVar7 & 8) != (uint)(*(char *)(param_1 + 0x759d) == '\0'))) {
              if ((uVar7 & 4) == 0) {
                uVar7 = uVar7 & 0xfffffffe;
                *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x10000000;
              }
              _gleUpdateDispatchCodeChange(param_1,uVar7);
              if (*(char *)(param_1 + 0x759d) == '\0') {
                if (*(int *)(param_1 + 0x7574) != 0) {
                  return;
                }
                uVar3 = 0x506;
                goto LAB_00084404;
              }
            }
          }
          else {
            _gleSwitchToNonRevertRenderer(param_1);
          }
          iVar6 = 0x13;
          do {
            *piVar8 = 0;
            piVar8 = piVar8 + 1;
            iVar6 = iVar6 + -1;
          } while (iVar6 != 0);
        }
      }
    }
    ((void (*)())_gleSetRasterPos)(param_1,(double)(float)((double)CONCAT44(0x43300000,(int)*param_2 ^ 0x80000000)
                                            - DOUBLE_00108d58),
                     (double)(float)((double)CONCAT44(0x43300000,(int)param_2[1] ^ 0x80000000) -
                                    DOUBLE_00108d58),
                     (double)(float)((double)CONCAT44(0x43300000,(int)param_2[2] ^ 0x80000000) -
                                    DOUBLE_00108d58),
                     (double)(float)((double)CONCAT44(0x43300000,(int)param_2[3] ^ 0x80000000) -
                                    DOUBLE_00108d58));
  }
  else {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar3 = 0x502;
LAB_00084404:
    *(undefined4 *)(param_1 + 0x7574) = uVar3;
  }
  return;
}

/* _glRasterPos4sv_CompExec @ 0x844bc (56 bytes) */
int _glRasterPos4sv_CompExec(param_1, param_2)
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
  
  fparam_1 = ((double (*)())_glRasterPos4sv_Comp)(param_1,param_2);
  ((void (*)())_glRasterPos4sv_Exec)(param_1,param_2,fparam_1,in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8);
  return;
}

/* _glReadBuffer_ListExec @ 0x844f4 (40 bytes) */
int _glReadBuffer_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  _glReadBuffer_Exec(param_1,*param_2);
  return 4;
}

/* _glReadBuffer_Comp @ 0x8451c (76 bytes) */
int _glReadBuffer_Comp(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glReadBuffer_ListExec_00110280,4);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_2;
  }
  return puVar1;
}

/* _glReadBuffer_CompExec @ 0x84568 (56 bytes) */
int _glReadBuffer_CompExec(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  ((int (*)())_glReadBuffer_Comp)(param_1,param_2);
  _glReadBuffer_Exec(param_1,param_2);
  return;
}

/* _glRectd_Comp @ 0x845a0 (148 bytes) */
undefined4 _glRectd_Comp(undefined4 param_1,double fparam_1,double fparam_2,double fparam_3,double fparam_4)
{
  undefined4 uVar1;
  
  _glBegin_Comp(param_1,9);
  ((float * (*)())_glVertex2d_Comp)(param_1,fparam_1,fparam_2);
  ((float * (*)())_glVertex2d_Comp)(param_1,fparam_3,fparam_2);
  ((float * (*)())_glVertex2d_Comp)(param_1,fparam_3,fparam_4);
  ((float * (*)())_glVertex2d_Comp)(param_1,fparam_1,fparam_4);
  uVar1 = _glEnd_Comp(param_1);
  return uVar1;
}

/* _glRectd_CompExec @ 0x84634 (96 bytes) */
void _glRectd_CompExec(undefined4 param_1,double fparam_1,double fparam_2,double fparam_3,double fparam_4)
{
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  
  ((undefined4 (*)())_glRectd_Comp)(param_1,fparam_1,fparam_2,fparam_3,fparam_4);
  ((void (*)())_glRectd_Exec)(param_1,fparam_1,fparam_2,fparam_3,fparam_4,in_f5,in_f6,in_f7,in_f8);
  return;
}

/* _glRectf_Comp @ 0x84694 (148 bytes) */
undefined4 _glRectf_Comp(undefined4 param_1,double fparam_1,double fparam_2,double fparam_3,double fparam_4)
{
  undefined4 uVar1;
  
  _glBegin_Comp(param_1,9);
  ((float * (*)())_glVertex2f_Comp)(param_1,fparam_1,fparam_2);
  ((float * (*)())_glVertex2f_Comp)(param_1,fparam_3,fparam_2);
  ((float * (*)())_glVertex2f_Comp)(param_1,fparam_3,fparam_4);
  ((float * (*)())_glVertex2f_Comp)(param_1,fparam_1,fparam_4);
  uVar1 = _glEnd_Comp(param_1);
  return uVar1;
}

/* _glRectf_Exec @ 0x84728 (196 bytes) */
void _glRectf_Exec(int param_1,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  if (-1 < *(short *)(param_1 + 0x4a10)) {
    if (*(int *)(param_1 + 0x7574) == 0) {
      *(undefined4 *)(param_1 + 0x7574) = 0x502;
    }
    FUN_00008b68();
    return;
  }
  ((void (*)())_glBegin_Exec)(param_1,9,fparam_1,fparam_2,fparam_3,fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
  _glVertex2f_Exec(param_1);
  _glVertex2f_Exec(param_1);
  _glVertex2f_Exec(param_1);
  _glVertex2f_Exec(param_1);
  _glEnd_Exec(param_1);
  return;
}

/* _glRectf_CompExec @ 0x847ec (96 bytes) */
void _glRectf_CompExec(undefined4 param_1,double fparam_1,double fparam_2,double fparam_3,double fparam_4)
{
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  
  ((undefined4 (*)())_glRectf_Comp)(param_1,fparam_1,fparam_2,fparam_3,fparam_4);
  ((void (*)())_glRectf_Exec)(param_1,fparam_1,fparam_2,fparam_3,fparam_4,in_f5,in_f6,in_f7,in_f8);
  return;
}

/* _glRecti_Comp @ 0x8484c (132 bytes) */
int _glRecti_Comp(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  undefined4 uVar1;
  
  _glBegin_Comp(param_1,9);
  _glVertex2i_Comp(param_1,param_2,param_3);
  _glVertex2i_Comp(param_1,param_4,param_3);
  _glVertex2i_Comp(param_1,param_4,param_5);
  _glVertex2i_Comp(param_1,param_2,param_5);
  uVar1 = _glEnd_Comp(param_1);
  return uVar1;
}

/* _glRecti_Exec @ 0x848d0 (188 bytes) */
void _glRecti_Exec(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  if (-1 < *(short *)(param_1 + 0x4a10)) {
    if (*(int *)(param_1 + 0x7574) == 0) {
      *(undefined4 *)(param_1 + 0x7574) = 0x502;
    }
    return;
  }
  ((void (*)())_glBegin_Exec)(param_1,9,fparam_1,fparam_2,fparam_3,fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
  _glVertex2i_Exec(param_1,param_2,param_3);
  _glVertex2i_Exec(param_1,param_4,param_3);
  _glVertex2i_Exec(param_1,param_4,param_5);
  _glVertex2i_Exec(param_1,param_2,param_5);
  _glEnd_Exec(param_1);
  return;
}

/* _glRecti_CompExec @ 0x8498c (80 bytes) */
int _glRecti_CompExec(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  double fparam_1;
  double in_f2;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  
  ((int (*)())_glRecti_Comp)(param_1,param_2,param_3,param_4,param_5);
  ((void (*)())_glRecti_Exec)(param_1,param_2,param_3,param_4,param_5,fparam_1,in_f2,in_f3,in_f4,in_f5,in_f6,in_f7
                ,in_f8);
  return;
}

