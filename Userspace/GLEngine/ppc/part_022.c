#include "decls.h"

/* _glPixelTransferi_CompExec @ 0x7dfa8 (64 bytes) */
void _glPixelTransferi_CompExec(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  _glPixelTransferi_Comp(param_1,param_2,param_3);
  _glPixelTransferi_Exec(param_1,param_2,param_3);
  return;
}

/* _glPixelZoom_ListExec @ 0x7dfe8 (44 bytes) */
int _glPixelZoom_ListExec(param_1, param_2)
  undefined4 param_1;
  float *param_2;
{
  ((void (*)())_glPixelZoom_Exec)(param_1,(double)*param_2,(double)param_2[1]);
  return 8;
}

/* _glPixelZoom_Comp @ 0x7e014 (100 bytes) */
float * _glPixelZoom_Comp(undefined4 param_1,float fparam_1,float fparam_2)
{
  float *pfVar1;
  
  pfVar1 = (float *)_gleAddListItem(param_1,PTR__glPixelZoom_ListExec_00110258,8);
  if (pfVar1 != (float *)0x0) {
    pfVar1[1] = (float)fparam_2;
    *pfVar1 = (float)fparam_1;
  }
  return pfVar1;
}

/* _glPixelZoom_Exec @ 0x7e078 (156 bytes) */
void _glPixelZoom_Exec(int param_1,float fparam_1,float fparam_2)
{
  uint uVar1;
  float dVar2;
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    *(float *)(param_1 + 0x31a8) = (float)fparam_1;
    dVar2 = (double)FLOAT_00108e54;
    *(float *)(param_1 + 0x31ac) = (float)fparam_2;
    if (fparam_1 == (double)dVar2) {
      uVar1 = *(uint *)(param_1 + 0x3414) & 0xffffbfff;
    }
    else {
      uVar1 = *(uint *)(param_1 + 0x3414) | 0x4000;
    }
    *(uint *)(param_1 + 0x3414) = uVar1;
    if (fparam_2 == (double)FLOAT_00108e54) {
      uVar1 = *(uint *)(param_1 + 0x3414) & 0xffff7fff;
    }
    else {
      uVar1 = *(uint *)(param_1 + 0x3414) | 0x8000;
    }
    *(uint *)(param_1 + 0x3414) = uVar1;
    *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x200000;
    return;
  }
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  *(undefined4 *)(param_1 + 0x7574) = 0x502;
  return;
}

/* _glPixelZoom_CompExec @ 0x7e114 (80 bytes) */
void _glPixelZoom_CompExec(undefined4 param_1,float fparam_1,float fparam_2)
{
  ((float * (*)())_glPixelZoom_Comp)(param_1,fparam_1,fparam_2);
  ((void (*)())_glPixelZoom_Exec)(param_1,fparam_1,fparam_2);
  return;
}

/* _glPNTrianglesiATIX_ListExec @ 0x7e164 (44 bytes) */
int _glPNTrianglesiATIX_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  ((void (*)())_glPNTrianglesiATIX_Exec)(param_1,*param_2,param_2[1]);
  return 8;
}

/* _glPNTrianglesiATIX_Comp @ 0x7e190 (84 bytes) */
int _glPNTrianglesiATIX_Comp(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glPNTrianglesiATIX_ListExec_0011025c,8);
  if (puVar1 != (undefined4 *)0x0) {
    puVar1[1] = param_3;
    *puVar1 = param_2;
  }
  return puVar1;
}

/* _glPNTrianglesiATIX_Exec @ 0x7e1e4 (200 bytes) */
void _glPNTrianglesiATIX_Exec(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  int param_3;
{
  undefined4 uVar1;
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if (param_2 == 0x6093) {
      if (param_3 - 0x6097U < 2) {
        *(short *)(param_1 + 0x280a) = (short)param_3;
        goto LAB_0007e29c;
      }
    }
    else if (param_2 < 0x6094) {
      if ((param_2 == 0x6092) && (param_3 - 0x6095U < 2)) {
        *(short *)(param_1 + 0x2808) = (short)param_3;
LAB_0007e29c:
        *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x80000;
        return;
      }
    }
    else if (param_2 == 0x6094) {
      if ((param_3 < 0) || (*(int *)(*(int *)(param_1 + 0x468c) + 0x9c) < param_3)) {
        if (*(int *)(param_1 + 0x7574) != 0) {
          return;
        }
        uVar1 = 0x501;
        goto LAB_0007e250;
      }
      *(int *)(param_1 + 0x2800) = param_3;
      goto LAB_0007e29c;
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
LAB_0007e250:
  *(undefined4 *)(param_1 + 0x7574) = uVar1;
  return;
}

/* _glPNTrianglesiATIX_CompExec @ 0x7e2ac (64 bytes) */
void _glPNTrianglesiATIX_CompExec(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  ((int (*)())_glPNTrianglesiATIX_Comp)(param_1,param_2,param_3);
  ((void (*)())_glPNTrianglesiATIX_Exec)(param_1,param_2,param_3);
  return;
}

/* _glPNTrianglesfATIX_Comp @ 0x7e2ec (104 bytes) */
undefined4 * _glPNTrianglesfATIX_Comp(undefined4 param_1,undefined4 param_2,double fparam_1)
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glPNTrianglesiATIX_ListExec_0011025c,8);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_2;
    puVar1[1] = (int)fparam_1;
  }
  return puVar1;
}

/* _glPNTrianglesfATIX_CompExec @ 0x7e3e4 (216 bytes) */
void _glPNTrianglesfATIX_CompExec(int param_1,undefined4 param_2,double fparam_1)
{
  int iVar1;
  undefined4 uVar2;
  
  ((undefined4 * (*)())_glPNTrianglesfATIX_Comp)(param_1,param_2,fparam_1);
  if (*(short *)(param_1 + 0x4a10) < 0) {
    iVar1 = (int)fparam_1;
    if (((iVar1 == 0x6093) || (iVar1 < 0x6094)) || (iVar1 != 0x6094)) {
      if (*(int *)(param_1 + 0x7574) != 0) {
        return;
      }
      uVar2 = 0x500;
    }
    else {
      if (0x6093 < *(int *)(*(int *)(param_1 + 0x468c) + 0x9c)) {
        *(undefined4 *)(param_1 + 0x2800) = 0x6094;
        *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x80000;
        return;
      }
      if (*(int *)(param_1 + 0x7574) != 0) {
        return;
      }
      uVar2 = 0x501;
    }
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

/* _glPointParameterf_Exec @ 0x7e42c (484 bytes) */
void _glPointParameterf_Exec(int param_1,uint param_2,double fparam_1)
{
  bool bVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  
  if (param_2 == 0x8127) {
    iVar3 = *(int *)(param_1 + 0x5434);
    *(float *)(param_1 + 0x3424) = (float)fparam_1;
  }
  else if (param_2 < 0x8128) {
    if (param_2 == 0x60b3) {
      if (DOUBLE_00108d80 <= fparam_1) {
        uVar4 = (int)(fparam_1 - DOUBLE_00108d80) ^ 0x80000000;
      }
      else {
        uVar4 = (uint)(int)fparam_1;
      }
      if (uVar4 - 0x60b4 < 2) {
        *(short *)(param_1 + 0x3442) = (short)uVar4;
        goto LAB_0007e600;
      }
LAB_0007e5d0:
      if (*(int *)(param_1 + 0x7574) == 0) {
        *(undefined4 *)(param_1 + 0x7574) = 0x500;
      }
      goto LAB_0007e600;
    }
    if (param_2 != 0x8126) {
LAB_0007e5e8:
      if (*(int *)(param_1 + 0x7574) == 0) {
        *(undefined4 *)(param_1 + 0x7574) = 0x500;
        return;
      }
      return;
    }
    iVar3 = *(int *)(param_1 + 0x5434);
    *(float *)(param_1 + 0x3420) = (float)fparam_1;
  }
  else {
    if (param_2 != 0x8128) {
      if (param_2 != 0x8863) goto LAB_0007e5e8;
      if (DOUBLE_00108d80 <= fparam_1) {
        uVar4 = (int)(fparam_1 - DOUBLE_00108d80) ^ 0x80000000;
      }
      else {
        uVar4 = (uint)(int)fparam_1;
      }
      if (uVar4 != 0x2000) {
        if (uVar4 < 0x2001) {
          bVar1 = uVar4 == 0;
        }
        else {
          bVar1 = uVar4 == 0x2002;
        }
        if (!bVar1) goto LAB_0007e5d0;
      }
      *(short *)(param_1 + 0x3440) = (short)uVar4;
      goto LAB_0007e600;
    }
    iVar3 = *(int *)(param_1 + 0x5434);
    *(float *)(param_1 + 0x3428) = (float)fparam_1;
  }
  if (iVar3 == 0) {
    bVar2 = *(byte *)(*(int *)(param_1 + 0x5420) + 0x325);
  }
  else {
    bVar2 = *(byte *)(*(int *)(*(int *)(param_1 + 0x5430) + 0x20) + 0x359);
  }
  iVar5 = (bVar2 >> 3 & 0x1c) + param_1;
  iVar3 = *(int *)(param_1 + 0x5424);
  *(uint *)(iVar5 + 0x324) = *(uint *)(iVar5 + 0x324) | 1 << (bVar2 & 0x1f);
  bVar2 = *(byte *)(iVar3 + 0x325);
  iVar3 = (bVar2 >> 3 & 0x1c) + param_1;
  *(uint *)(iVar3 + 0x348) = *(uint *)(iVar3 + 0x348) | 1 << (bVar2 & 0x1f);
LAB_0007e600:
  *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x400000;
  return;
}

/* _glPointParameterf_Comp @ 0x7e610 (92 bytes) */
undefined4 * _glPointParameterf_Comp(undefined4 param_1,undefined4 param_2,float fparam_1)
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glPointParameterf_ListExec_0011026c,8);
  if (puVar1 != (undefined4 *)0x0) {
    puVar1[1] = (float)fparam_1;
    *puVar1 = param_2;
  }
  return puVar1;
}

/* _glPointParameterf_CompExec @ 0x7e66c (72 bytes) */
void _glPointParameterf_CompExec(undefined4 param_1,undefined4 param_2,float fparam_1)
{
  ((undefined4 * (*)())_glPointParameterf_Comp)(param_1,param_2,fparam_1);
  ((void (*)())_glPointParameterf_Exec)(param_1,param_2,fparam_1);
  return;
}

/* _glPointParameterf_ListExec @ 0x7e6b4 (44 bytes) */
int _glPointParameterf_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  ((void (*)())_glPointParameterf_Exec)(param_1,*param_2,(double)GH_U2F((unsigned int)(param_2[1])));
  return 8;
}

/* _glPointParameterfv_Exec @ 0x7e6e0 (616 bytes) */
void _glPointParameterfv_Exec(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  float *param_3;
{
  bool bVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  float dVar6;
  
  if (param_2 == 0x8127) {
    bVar1 = *(int *)(param_1 + 0x5434) == 0;
    *(float *)(param_1 + 0x3424) = *param_3;
LAB_0007e788:
    if (bVar1) {
      bVar2 = *(byte *)(*(int *)(param_1 + 0x5420) + 0x325);
    }
    else {
      bVar2 = *(byte *)(*(int *)(*(int *)(param_1 + 0x5430) + 0x20) + 0x359);
    }
    iVar5 = (bVar2 >> 3 & 0x1c) + param_1;
    iVar4 = *(int *)(param_1 + 0x5424);
    *(uint *)(iVar5 + 0x324) = *(uint *)(iVar5 + 0x324) | 1 << (bVar2 & 0x1f);
    bVar2 = *(byte *)(iVar4 + 0x325);
  }
  else {
    if (param_2 < 0x8128) {
      if (param_2 == 0x60b3) {
        dVar6 = (double)*param_3;
        if (DOUBLE_00108d80 <= (double)dVar6) {
          uVar3 = (int)((double)dVar6 - DOUBLE_00108d80) ^ 0x80000000;
        }
        else {
          uVar3 = (uint)(int)*param_3;
        }
        if (uVar3 - 0x60b4 < 2) {
          *(short *)(param_1 + 0x3442) = (short)uVar3;
          goto LAB_0007e938;
        }
LAB_0007e908:
        if (*(int *)(param_1 + 0x7574) == 0) {
          *(undefined4 *)(param_1 + 0x7574) = 0x500;
        }
        goto LAB_0007e938;
      }
      if (param_2 != 0x8126) {
LAB_0007e920:
        if (*(int *)(param_1 + 0x7574) == 0) {
          *(undefined4 *)(param_1 + 0x7574) = 0x500;
          return;
        }
        return;
      }
      bVar1 = *(int *)(param_1 + 0x5434) == 0;
      *(float *)(param_1 + 0x3420) = *param_3;
      goto LAB_0007e788;
    }
    if (param_2 != 0x8129) {
      if (0x8128 < param_2) {
        if (param_2 != 0x8863) goto LAB_0007e920;
        dVar6 = (double)*param_3;
        if (DOUBLE_00108d80 <= (double)dVar6) {
          uVar3 = (int)((double)dVar6 - DOUBLE_00108d80) ^ 0x80000000;
        }
        else {
          uVar3 = (uint)(int)*param_3;
        }
        if (uVar3 != 0x2000) {
          if (uVar3 < 0x2001) {
            bVar1 = uVar3 == 0;
          }
          else {
            bVar1 = uVar3 == 0x2002;
          }
          if (!bVar1) goto LAB_0007e908;
        }
        *(short *)(param_1 + 0x3440) = (short)uVar3;
        goto LAB_0007e938;
      }
      bVar1 = *(int *)(param_1 + 0x5434) == 0;
      *(float *)(param_1 + 0x3428) = *param_3;
      goto LAB_0007e788;
    }
    *(float *)(param_1 + 0x342c) = *param_3;
    *(float *)(param_1 + 0x3430) = param_3[1];
    *(float *)(param_1 + 0x3434) = param_3[2];
    if (*(int *)(param_1 + 0x5434) == 0) {
      bVar2 = *(byte *)(*(int *)(param_1 + 0x5420) + 0x326);
    }
    else {
      bVar2 = *(byte *)(*(int *)(*(int *)(param_1 + 0x5430) + 0x20) + 0x35a);
    }
    iVar5 = (bVar2 >> 3 & 0x1c) + param_1;
    iVar4 = *(int *)(param_1 + 0x5424);
    *(uint *)(iVar5 + 0x324) = *(uint *)(iVar5 + 0x324) | 1 << (bVar2 & 0x1f);
    bVar2 = *(byte *)(iVar4 + 0x326);
  }
  iVar4 = (bVar2 >> 3 & 0x1c) + param_1;
  *(uint *)(iVar4 + 0x348) = *(uint *)(iVar4 + 0x348) | 1 << (bVar2 & 0x1f);
LAB_0007e938:
  *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x400000;
  return;
}

/* _glPointParameterfv_Comp @ 0x7e948 (148 bytes) */
int _glPointParameterfv_Comp(param_1, param_2, param_3)
  undefined4 param_1;
  int param_2;
  int *param_3;
{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  iVar3 = 3;
  if (param_2 != 0x8129) {
    iVar3 = 1;
  }
  piVar2 = (int *)_gleAddListItem(param_1,PTR__glPointParameterfv_ListExec_00110268,iVar3 * 4 + 4);
  if ((piVar2 != (int *)0x0) && (*piVar2 = param_2, iVar3 != 0)) {
    piVar2 = piVar2 + 1;
    do {
      iVar1 = *param_3;
      param_3 = param_3 + 1;
      *piVar2 = iVar1;
      piVar2 = piVar2 + 1;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  return piVar2;
}

/* _glPointParameterfv_CompExec @ 0x7e9dc (64 bytes) */
void _glPointParameterfv_CompExec(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  ((int (*)())_glPointParameterfv_Comp)(param_1,param_2,param_3);
  ((void (*)())_glPointParameterfv_Exec)(param_1,param_2,param_3);
  return;
}

/* _glPointParameterfv_ListExec @ 0x7ea1c (88 bytes) */
int _glPointParameterfv_ListExec(param_1, param_2)
  undefined4 param_1;
  int *param_2;
{
  int iVar1;
  
  iVar1 = 3;
  if (*param_2 != 0x8129) {
    iVar1 = 1;
  }
  ((void (*)())_glPointParameterfv_Exec)(param_1,*param_2,param_2 + 1);
  return iVar1 * 4 + 4;
}

/* _glPointParameteriARB_Exec @ 0x7ea74 (480 bytes) */
void _glPointParameteriARB_Exec(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  uint param_3;
{
  bool bVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  
  if (param_2 == 0x8127) {
    bVar1 = *(int *)(param_1 + 0x5434) == 0;
    *(float *)(param_1 + 0x3424) =
         (float)((double)CONCAT44(0x43300000,param_3 ^ 0x80000000) - DOUBLE_00108d58);
  }
  else if (param_2 < 0x8128) {
    if (param_2 == 0x60b3) {
      if (param_3 - 0x60b4 < 2) {
        *(short *)(param_1 + 0x3442) = (short)param_3;
        goto LAB_0007ec44;
      }
LAB_0007ec14:
      if (*(int *)(param_1 + 0x7574) == 0) {
        *(undefined4 *)(param_1 + 0x7574) = 0x500;
      }
      goto LAB_0007ec44;
    }
    if (param_2 != 0x8126) {
LAB_0007ec2c:
      if (*(int *)(param_1 + 0x7574) == 0) {
        *(undefined4 *)(param_1 + 0x7574) = 0x500;
        return;
      }
      return;
    }
    bVar1 = *(int *)(param_1 + 0x5434) == 0;
    *(float *)(param_1 + 0x3420) =
         (float)((double)CONCAT44(0x43300000,param_3 ^ 0x80000000) - DOUBLE_00108d58);
  }
  else {
    if (param_2 != 0x8128) {
      if (param_2 != 0x8863) goto LAB_0007ec2c;
      if (param_3 != 0x2000) {
        if (param_3 < 0x2001) {
          bVar1 = param_3 == 0;
        }
        else {
          bVar1 = param_3 == 0x2002;
        }
        if (!bVar1) goto LAB_0007ec14;
      }
      *(short *)(param_1 + 0x3440) = (short)param_3;
      goto LAB_0007ec44;
    }
    bVar1 = *(int *)(param_1 + 0x5434) == 0;
    *(float *)(param_1 + 0x3428) =
         (float)((double)CONCAT44(0x43300000,param_3 ^ 0x80000000) - DOUBLE_00108d58);
  }
  if (bVar1) {
    bVar2 = *(byte *)(*(int *)(param_1 + 0x5420) + 0x325);
  }
  else {
    bVar2 = *(byte *)(*(int *)(*(int *)(param_1 + 0x5430) + 0x20) + 0x359);
  }
  iVar4 = (bVar2 >> 3 & 0x1c) + param_1;
  iVar3 = *(int *)(param_1 + 0x5424);
  *(uint *)(iVar4 + 0x324) = *(uint *)(iVar4 + 0x324) | 1 << (bVar2 & 0x1f);
  bVar2 = *(byte *)(iVar3 + 0x325);
  iVar3 = (bVar2 >> 3 & 0x1c) + param_1;
  *(uint *)(iVar3 + 0x348) = *(uint *)(iVar3 + 0x348) | 1 << (bVar2 & 0x1f);
LAB_0007ec44:
  *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x400000;
  return;
}

/* _glPointParameteriARB_Comp @ 0x7ec54 (84 bytes) */
int _glPointParameteriARB_Comp(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glPointParameteriARB_ListExec_00110264,8);
  if (puVar1 != (undefined4 *)0x0) {
    puVar1[1] = param_3;
    *puVar1 = param_2;
  }
  return puVar1;
}

/* _glPointParameteriARB_CompExec @ 0x7eca8 (64 bytes) */
void _glPointParameteriARB_CompExec(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  ((int (*)())_glPointParameteriARB_Comp)(param_1,param_2,param_3);
  ((void (*)())_glPointParameteriARB_Exec)(param_1,param_2,param_3);
  return;
}

/* _glPointParameteriARB_ListExec @ 0x7ece8 (44 bytes) */
int _glPointParameteriARB_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  ((void (*)())_glPointParameteriARB_Exec)(param_1,*param_2,param_2[1]);
  return 8;
}

/* _glPointParameterivARB_Exec @ 0x7ed14 (688 bytes) */
void _glPointParameterivARB_Exec(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  uint *param_3;
{
  bool bVar1;
  byte bVar2;
  double dVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  
  dVar3 = DOUBLE_00108d58;
  if (param_2 == 0x8127) {
    bVar1 = *(int *)(param_1 + 0x5434) == 0;
    *(float *)(param_1 + 0x3424) =
         (float)((double)CONCAT44(0x43300000,*param_3 ^ 0x80000000) - DOUBLE_00108d58);
LAB_0007ee28:
    if (bVar1) {
      bVar2 = *(byte *)(*(int *)(param_1 + 0x5420) + 0x325);
    }
    else {
      bVar2 = *(byte *)(*(int *)(*(int *)(param_1 + 0x5430) + 0x20) + 0x359);
    }
    iVar6 = (bVar2 >> 3 & 0x1c) + param_1;
    iVar5 = *(int *)(param_1 + 0x5424);
    *(uint *)(iVar6 + 0x324) = *(uint *)(iVar6 + 0x324) | 1 << (bVar2 & 0x1f);
    bVar2 = *(byte *)(iVar5 + 0x325);
  }
  else {
    if (param_2 < 0x8128) {
      if (param_2 == 0x60b3) {
        if (*param_3 - 0x60b4 < 2) {
          *(short *)(param_1 + 0x3442) = (short)*param_3;
          goto LAB_0007efb4;
        }
LAB_0007ef84:
        if (*(int *)(param_1 + 0x7574) == 0) {
          *(undefined4 *)(param_1 + 0x7574) = 0x500;
        }
        goto LAB_0007efb4;
      }
      if (param_2 != 0x8126) {
LAB_0007ef9c:
        if (*(int *)(param_1 + 0x7574) == 0) {
          *(undefined4 *)(param_1 + 0x7574) = 0x500;
          return;
        }
        return;
      }
      bVar1 = *(int *)(param_1 + 0x5434) == 0;
      *(float *)(param_1 + 0x3420) =
           (float)((double)CONCAT44(0x43300000,*param_3 ^ 0x80000000) - DOUBLE_00108d58);
      goto LAB_0007ee28;
    }
    if (param_2 != 0x8129) {
      if (0x8128 < param_2) {
        if (param_2 != 0x8863) goto LAB_0007ef9c;
        uVar4 = *param_3;
        if (uVar4 != 0x2000) {
          if (uVar4 < 0x2001) {
            bVar1 = uVar4 == 0;
          }
          else {
            bVar1 = uVar4 == 0x2002;
          }
          if (!bVar1) goto LAB_0007ef84;
        }
        *(short *)(param_1 + 0x3440) = (short)uVar4;
        goto LAB_0007efb4;
      }
      bVar1 = *(int *)(param_1 + 0x5434) == 0;
      *(float *)(param_1 + 0x3428) =
           (float)((double)CONCAT44(0x43300000,*param_3 ^ 0x80000000) - DOUBLE_00108d58);
      goto LAB_0007ee28;
    }
    *(float *)(param_1 + 0x342c) =
         (float)((double)CONCAT44(0x43300000,*param_3 ^ 0x80000000) - DOUBLE_00108d58);
    *(float *)(param_1 + 0x3430) =
         (float)((double)CONCAT44(0x43300000,param_3[1] ^ 0x80000000) - dVar3);
    *(float *)(param_1 + 0x3434) =
         (float)((double)CONCAT44(0x43300000,param_3[2] ^ 0x80000000) - dVar3);
    if (*(int *)(param_1 + 0x5434) == 0) {
      bVar2 = *(byte *)(*(int *)(param_1 + 0x5420) + 0x326);
    }
    else {
      bVar2 = *(byte *)(*(int *)(*(int *)(param_1 + 0x5430) + 0x20) + 0x35a);
    }
    iVar6 = (bVar2 >> 3 & 0x1c) + param_1;
    iVar5 = *(int *)(param_1 + 0x5424);
    *(uint *)(iVar6 + 0x324) = *(uint *)(iVar6 + 0x324) | 1 << (bVar2 & 0x1f);
    bVar2 = *(byte *)(iVar5 + 0x326);
  }
  iVar5 = (bVar2 >> 3 & 0x1c) + param_1;
  *(uint *)(iVar5 + 0x348) = *(uint *)(iVar5 + 0x348) | 1 << (bVar2 & 0x1f);
LAB_0007efb4:
  *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x400000;
  return;
}

/* _glPointParameterivARB_Comp @ 0x7efc4 (148 bytes) */
int _glPointParameterivARB_Comp(param_1, param_2, param_3)
  undefined4 param_1;
  int param_2;
  int *param_3;
{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  iVar3 = 3;
  if (param_2 != 0x8129) {
    iVar3 = 1;
  }
  piVar2 = (int *)_gleAddListItem(param_1,PTR__glPointParameterivARB_ListExec_00110260,iVar3 * 4 + 4
                                 );
  if ((piVar2 != (int *)0x0) && (*piVar2 = param_2, iVar3 != 0)) {
    piVar2 = piVar2 + 1;
    do {
      iVar1 = *param_3;
      param_3 = param_3 + 1;
      *piVar2 = iVar1;
      piVar2 = piVar2 + 1;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  return piVar2;
}

/* _glPointParameterivARB_CompExec @ 0x7f058 (64 bytes) */
void _glPointParameterivARB_CompExec(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  ((int (*)())_glPointParameterivARB_Comp)(param_1,param_2,param_3);
  ((void (*)())_glPointParameterivARB_Exec)(param_1,param_2,param_3);
  return;
}

/* _glPointParameterivARB_ListExec @ 0x7f098 (88 bytes) */
int _glPointParameterivARB_ListExec(param_1, param_2)
  undefined4 param_1;
  int *param_2;
{
  int iVar1;
  
  iVar1 = 3;
  if (*param_2 != 0x8129) {
    iVar1 = 1;
  }
  ((void (*)())_glPointParameterivARB_Exec)(param_1,*param_2,param_2 + 1);
  return iVar1 * 4 + 4;
}

/* _glPointSize_ListExec @ 0x7f0f0 (40 bytes) */
int _glPointSize_ListExec(param_1, param_2)
  undefined4 param_1;
  float *param_2;
{
  ((void (*)())_glPointSize_Exec)(param_1,(double)*param_2);
  return 4;
}

/* _glPointSize_Comp @ 0x7f118 (84 bytes) */
float * _glPointSize_Comp(undefined4 param_1,float fparam_1)
{
  float *pfVar1;
  
  pfVar1 = (float *)_gleAddListItem(param_1,PTR__glPointSize_ListExec_00110270,4);
  if (pfVar1 != (float *)0x0) {
    *pfVar1 = (float)fparam_1;
  }
  return pfVar1;
}

/* _glPointSize_CompExec @ 0x7f16c (64 bytes) */
void _glPointSize_CompExec(undefined4 param_1,float fparam_1)
{
  ((float * (*)())_glPointSize_Comp)(param_1,fparam_1);
  ((void (*)())_glPointSize_Exec)(param_1,fparam_1);
  return;
}

/* _glPolygonMode_ListExec @ 0x7f1ac (44 bytes) */
int _glPolygonMode_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  _glPolygonMode_Exec(param_1,*param_2,param_2[1]);
  return 8;
}

/* _glPolygonMode_Comp @ 0x7f1d8 (84 bytes) */
int _glPolygonMode_Comp(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glPolygonMode_ListExec_00110274,8);
  if (puVar1 != (undefined4 *)0x0) {
    puVar1[1] = param_3;
    *puVar1 = param_2;
  }
  return puVar1;
}

/* _glPolygonMode_CompExec @ 0x7f22c (64 bytes) */
void _glPolygonMode_CompExec(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  ((int (*)())_glPolygonMode_Comp)(param_1,param_2,param_3);
  _glPolygonMode_Exec(param_1,param_2,param_3);
  return;
}

/* _glPolygonOffset_ListExec @ 0x7f26c (44 bytes) */
int _glPolygonOffset_ListExec(param_1, param_2)
  undefined4 param_1;
  float *param_2;
{
  ((void (*)())_glPolygonOffset_Exec)(param_1,(double)*param_2,(double)param_2[1]);
  return 8;
}

/* _glPolygonOffset_Comp @ 0x7f298 (100 bytes) */
float * _glPolygonOffset_Comp(undefined4 param_1,float fparam_1,float fparam_2)
{
  float *pfVar1;
  
  pfVar1 = (float *)_gleAddListItem(param_1,PTR__glPolygonOffset_ListExec_00110278,8);
  if (pfVar1 != (float *)0x0) {
    pfVar1[1] = (float)fparam_2;
    *pfVar1 = (float)fparam_1;
  }
  return pfVar1;
}

/* _glPolygonOffset_Exec @ 0x7f2fc (60 bytes) */
void _glPolygonOffset_Exec(int param_1,float fparam_1,float fparam_2)
{
  if (*(short *)(param_1 + 0x4a10) < 0) {
    *(float *)(param_1 + 0x34c8) = (float)fparam_1;
    *(float *)(param_1 + 0x34cc) = (float)fparam_2;
    *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x800000;
    return;
  }
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  *(undefined4 *)(param_1 + 0x7574) = 0x502;
  return;
}

/* _glPolygonOffset_CompExec @ 0x7f338 (80 bytes) */
void _glPolygonOffset_CompExec(undefined4 param_1,float fparam_1,float fparam_2)
{
  ((float * (*)())_glPolygonOffset_Comp)(param_1,fparam_1,fparam_2);
  ((void (*)())_glPolygonOffset_Exec)(param_1,fparam_1,fparam_2);
  return;
}

/* _glSetRasterPos_ListExec @ 0x7f388 (88 bytes) */
int _glSetRasterPos_ListExec(param_1, param_2)
  int param_1;
  float *param_2;
{
  if (*(short *)(param_1 + 0x4a10) < 0) {
    ((void (*)())_gleSetRasterPos)(param_1,(double)*param_2,(double)param_2[1],(double)param_2[2],
                     (double)param_2[3]);
  }
  else if (*(int *)(param_1 + 0x7574) == 0) {
    *(undefined4 *)(param_1 + 0x7574) = 0x502;
  }
  return 0x10;
}

/* _glSetRasterPos_Comp @ 0x7f3e0 (92 bytes) */
void _glSetRasterPos_Comp(undefined4 param_1,float fparam_1,float fparam_2,float fparam_3,float fparam_4)
{
  float *pfVar1;
  
  pfVar1 = (float *)_gleAddListItem(param_1,PTR__glSetRasterPos_ListExec_0011027c,0x10);
  if (pfVar1 != (float *)0x0) {
    pfVar1[3] = (float)fparam_4;
    *pfVar1 = (float)fparam_1;
    pfVar1[1] = (float)fparam_2;
    pfVar1[2] = (float)fparam_3;
  }
  return;
}

/* _glRasterPos2d_Comp @ 0x7f43c (44 bytes) */
void _glRasterPos2d_Comp(undefined4 param_1,double fparam_1,double fparam_2)
{
  ((void (*)())_glSetRasterPos_Comp)(param_1,(double)(float)fparam_1,(double)(float)fparam_2,(double)FLOAT_00108e50,
             (double)FLOAT_00108e54);
  return;
}

/* _glRasterPos2d_Exec @ 0x7f468 (732 bytes) */
void _glRasterPos2d_Exec(int param_1,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
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
  
  if (-1 < *(short *)(param_1 + 0x4a10)) {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar3 = 0x502;
    goto LAB_0007f6c4;
  }
  if ((*(int *)(param_1 + 0x744c) == 0) && (-1 < *(int *)(param_1 + 0x310))) goto LAB_0007f6f0;
  iVar6 = *(int *)(param_1 + 0x50ac);
  fparam_1_00 = fparam_1;
  fparam_2_00 = fparam_2;
  if (iVar6 != 0 || (*(uint *)(param_1 + 0x505c) & *(uint *)(param_1 + 0x50b0)) != 0) {
    _gleUpdateMatrixFunc(param_1);
    fparam_1_00 = extraout_f1;
  }
  if (*(char *)(param_1 + 0x4691) == '\0') goto LAB_0007f6f0;
  iVar5 = *(int *)(param_1 + 0x744c);
  piVar8 = (int *)(param_1 + 0x310);
  cVar2 = *(char *)(*(int *)(param_1 + 0x468c) + 0x79);
  if ((iVar5 != 0) && (*(int *)(iVar5 + 0xec) != 0)) {
    ((void (*)())_gleUpdateFramebufferCompleteness)(param_1,iVar5 + 0x10,in_r5,in_r6,in_r7,in_r8,iVar6,fparam_1_00,fparam_2_00,fparam_3,
               fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
    *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x80000000;
  }
  if ((*(char *)(param_1 + 0x4664) == '\0') && (*(int *)(param_1 + 0x5430) == 0)) {
LAB_0007f5c8:
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
      goto LAB_0007f5c8;
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
LAB_0007f6c4:
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
LAB_0007f6f0:
  ((void (*)())_gleSetRasterPos)(param_1,(double)(float)fparam_1,(double)(float)fparam_2,(double)FLOAT_00108e50,
                   (double)FLOAT_00108e54);
  return;
}

/* _glRasterPos2d_CompExec @ 0x7f744 (80 bytes) */
void _glRasterPos2d_CompExec(undefined4 param_1,double fparam_1,double fparam_2)
{
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  
  ((void (*)())_glRasterPos2d_Comp)(param_1,fparam_1,fparam_2);
  ((void (*)())_glRasterPos2d_Exec)(param_1,fparam_1,fparam_2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8);
  return;
}

/* _glRasterPos2dv_Comp @ 0x7f794 (52 bytes) */
void _glRasterPos2dv_Comp(param_1, param_2)
  undefined4 param_1;
  double *param_2;
{
  ((void (*)())_glSetRasterPos_Comp)(param_1,(double)(float)*param_2,(double)(float)param_2[1],(double)FLOAT_00108e50,
             (double)FLOAT_00108e54);
  return;
}

/* _glRasterPos2dv_Exec @ 0x7f7c8 (712 bytes) */
void _glRasterPos2dv_Exec(int param_1,double *param_2,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
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
    goto LAB_0007fa18;
  }
  if ((*(int *)(param_1 + 0x744c) == 0) && (-1 < *(int *)(param_1 + 0x310))) goto LAB_0007fa44;
  iVar6 = *(int *)(param_1 + 0x50ac);
  if (iVar6 != 0 || (*(uint *)(param_1 + 0x505c) & *(uint *)(param_1 + 0x50b0)) != 0) {
    _gleUpdateMatrixFunc(param_1);
    fparam_1 = extraout_f1;
  }
  if (*(char *)(param_1 + 0x4691) == '\0') goto LAB_0007fa44;
  iVar5 = *(int *)(param_1 + 0x744c);
  piVar8 = (int *)(param_1 + 0x310);
  cVar2 = *(char *)(*(int *)(param_1 + 0x468c) + 0x79);
  if ((iVar5 != 0) && (*(int *)(iVar5 + 0xec) != 0)) {
    ((void (*)())_gleUpdateFramebufferCompleteness)(param_1,iVar5 + 0x10,in_r5,in_r6,in_r7,in_r8,iVar6,fparam_1,fparam_2,fparam_3,
               fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
    *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x80000000;
  }
  if ((*(char *)(param_1 + 0x4664) == '\0') && (*(int *)(param_1 + 0x5430) == 0)) {
LAB_0007f91c:
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
      goto LAB_0007f91c;
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
LAB_0007fa18:
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
LAB_0007fa44:
  ((void (*)())_gleSetRasterPos)(param_1,(double)GH_U2F((unsigned int)(*param_2)),(double)GH_U2F((unsigned int)(param_2[1])),(double)FLOAT_00108e50,
                   (double)FLOAT_00108e54);
  return;
}

/* _glRasterPos2dv_CompExec @ 0x7fa90 (56 bytes) */
void _glRasterPos2dv_CompExec(param_1, param_2)
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
  
  ((void (*)())_glRasterPos2dv_Comp)(param_1,param_2);
  ((void (*)())_glRasterPos2dv_Exec)(param_1,param_2,fparam_1,in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8);
  return;
}

/* _glRasterPos2f_Comp @ 0x7fac8 (36 bytes) */
void _glRasterPos2f_Comp(undefined4 param_1,float fparam_1,float fparam_2)
{
  ((void (*)())_glSetRasterPos_Comp)(param_1,fparam_1,fparam_2,(double)FLOAT_00108e50,(double)FLOAT_00108e54);
  return;
}

/* _glRasterPos2f_Exec @ 0x7faec (732 bytes) */
void _glRasterPos2f_Exec(int param_1,float fparam_1,float fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
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
  
  if (-1 < *(short *)(param_1 + 0x4a10)) {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar3 = 0x502;
    goto LAB_0007fd48;
  }
  if ((*(int *)(param_1 + 0x744c) == 0) && (-1 < *(int *)(param_1 + 0x310))) goto LAB_0007fd74;
  iVar6 = *(int *)(param_1 + 0x50ac);
  fparam_1_00 = fparam_1;
  fparam_2_00 = fparam_2;
  if (iVar6 != 0 || (*(uint *)(param_1 + 0x505c) & *(uint *)(param_1 + 0x50b0)) != 0) {
    _gleUpdateMatrixFunc(param_1);
    fparam_1_00 = extraout_f1;
  }
  if (*(char *)(param_1 + 0x4691) == '\0') goto LAB_0007fd74;
  iVar5 = *(int *)(param_1 + 0x744c);
  piVar8 = (int *)(param_1 + 0x310);
  cVar2 = *(char *)(*(int *)(param_1 + 0x468c) + 0x79);
  if ((iVar5 != 0) && (*(int *)(iVar5 + 0xec) != 0)) {
    ((void (*)())_gleUpdateFramebufferCompleteness)(param_1,iVar5 + 0x10,in_r5,in_r6,in_r7,in_r8,iVar6,fparam_1_00,fparam_2_00,fparam_3,
               fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
    *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x80000000;
  }
  if ((*(char *)(param_1 + 0x4664) == '\0') && (*(int *)(param_1 + 0x5430) == 0)) {
LAB_0007fc4c:
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
      goto LAB_0007fc4c;
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
LAB_0007fd48:
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
LAB_0007fd74:
  ((void (*)())_gleSetRasterPos)(param_1,fparam_1,fparam_2,(double)FLOAT_00108e50,(double)FLOAT_00108e54);
  return;
}

/* _glRasterPos2f_CompExec @ 0x7fdc8 (80 bytes) */
void _glRasterPos2f_CompExec(undefined4 param_1,float fparam_1,float fparam_2)
{
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  
  ((void (*)())_glRasterPos2f_Comp)(param_1,fparam_1,fparam_2);
  ((void (*)())_glRasterPos2f_Exec)(param_1,fparam_1,fparam_2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8);
  return;
}

/* _glRasterPos2fv_Comp @ 0x7fe18 (44 bytes) */
void _glRasterPos2fv_Comp(param_1, param_2)
  undefined4 param_1;
  float *param_2;
{
  ((void (*)())_glSetRasterPos_Comp)(param_1,(double)*param_2,(double)param_2[1],(double)FLOAT_00108e50,
             (double)FLOAT_00108e54);
  return;
}

/* _glRasterPos2fv_Exec @ 0x7fe44 (704 bytes) */
void _glRasterPos2fv_Exec(int param_1,float *param_2,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
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
    goto LAB_00080094;
  }
  if ((*(int *)(param_1 + 0x744c) == 0) && (-1 < *(int *)(param_1 + 0x310))) goto LAB_000800c0;
  iVar6 = *(int *)(param_1 + 0x50ac);
  if (iVar6 != 0 || (*(uint *)(param_1 + 0x505c) & *(uint *)(param_1 + 0x50b0)) != 0) {
    _gleUpdateMatrixFunc(param_1);
    fparam_1 = extraout_f1;
  }
  if (*(char *)(param_1 + 0x4691) == '\0') goto LAB_000800c0;
  iVar5 = *(int *)(param_1 + 0x744c);
  piVar8 = (int *)(param_1 + 0x310);
  cVar2 = *(char *)(*(int *)(param_1 + 0x468c) + 0x79);
  if ((iVar5 != 0) && (*(int *)(iVar5 + 0xec) != 0)) {
    ((void (*)())_gleUpdateFramebufferCompleteness)(param_1,iVar5 + 0x10,in_r5,in_r6,in_r7,in_r8,iVar6,fparam_1,fparam_2,fparam_3,
               fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
    *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x80000000;
  }
  if ((*(char *)(param_1 + 0x4664) == '\0') && (*(int *)(param_1 + 0x5430) == 0)) {
LAB_0007ff98:
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
      goto LAB_0007ff98;
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
LAB_00080094:
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
LAB_000800c0:
  ((void (*)())_gleSetRasterPos)(param_1,(double)*param_2,(double)param_2[1],(double)FLOAT_00108e50,
                   (double)FLOAT_00108e54);
  return;
}

/* _glRasterPos2fv_CompExec @ 0x80104 (56 bytes) */
void _glRasterPos2fv_CompExec(param_1, param_2)
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
  
  ((void (*)())_glRasterPos2fv_Comp)(param_1,param_2);
  ((void (*)())_glRasterPos2fv_Exec)(param_1,param_2,fparam_1,in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8);
  return;
}

/* _glRasterPos2i_Comp @ 0x8013c (120 bytes) */
void _glRasterPos2i_Comp(param_1, param_2, param_3)
  undefined4 param_1;
  uint param_2;
  uint param_3;
{
  ((void (*)())_glSetRasterPos_Comp)(param_1,(double)(float)((double)CONCAT44(0x43300000,param_2 ^ 0x80000000) -
                                    DOUBLE_00108d58),
             (double)(float)((double)CONCAT44(0x43300000,param_3 ^ 0x80000000) - DOUBLE_00108d58),
             (double)FLOAT_00108e50,(double)FLOAT_00108e54);
  return;
}

/* _glRasterPos2i_CompExec @ 0x801b4 (64 bytes) */
void _glRasterPos2i_CompExec(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  double fparam_1;
  double in_f2;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  
  ((void (*)())_glRasterPos2i_Comp)(param_1,param_2,param_3);
  ((void (*)())_glRasterPos2i_Exec)(param_1,param_2,param_3,fparam_1,in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8);
  return;
}

/* _glRasterPos2iv_Comp @ 0x801f4 (128 bytes) */
void _glRasterPos2iv_Comp(param_1, param_2)
  undefined4 param_1;
  uint *param_2;
{
  ((void (*)())_glSetRasterPos_Comp)(param_1,(double)(float)((double)CONCAT44(0x43300000,*param_2 ^ 0x80000000) -
                                    DOUBLE_00108d58),
             (double)(float)((double)CONCAT44(0x43300000,param_2[1] ^ 0x80000000) - DOUBLE_00108d58)
             ,(double)FLOAT_00108e50,(double)FLOAT_00108e54);
  return;
}

/* _glRasterPos2iv_Exec @ 0x80274 (744 bytes) */
void _glRasterPos2iv_Exec(int param_1,uint *param_2,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
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
          ((void (*)())_gleUpdateFramebufferCompleteness)(param_1,iVar5 + 0x10,in_r5,in_r6,in_r7,in_r8,iVar6,fparam_1,fparam_2,fparam_3,
                     fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
          *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x80000000;
        }
        if ((*(char *)(param_1 + 0x4664) == '\0') && (*(int *)(param_1 + 0x5430) == 0)) {
LAB_000803c8:
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
            goto LAB_000803c8;
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
                goto LAB_000804c4;
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
                                    DOUBLE_00108d58),(double)FLOAT_00108e50,(double)FLOAT_00108e54);
  }
  else {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar3 = 0x502;
LAB_000804c4:
    *(undefined4 *)(param_1 + 0x7574) = uVar3;
  }
  return;
}

/* _glRasterPos2iv_CompExec @ 0x8055c (56 bytes) */
void _glRasterPos2iv_CompExec(param_1, param_2)
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
  
  ((void (*)())_glRasterPos2iv_Comp)(param_1,param_2);
  ((void (*)())_glRasterPos2iv_Exec)(param_1,param_2,fparam_1,in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8);
  return;
}

/* _glRasterPos2s_Comp @ 0x80594 (120 bytes) */
void _glRasterPos2s_Comp(param_1, param_2, param_3)
  undefined4 param_1;
  uint param_2;
  uint param_3;
{
  ((void (*)())_glSetRasterPos_Comp)(param_1,(double)(float)((double)CONCAT44(0x43300000,param_2 ^ 0x80000000) -
                                    DOUBLE_00108d58),
             (double)(float)((double)CONCAT44(0x43300000,param_3 ^ 0x80000000) - DOUBLE_00108d58),
             (double)FLOAT_00108e50,(double)FLOAT_00108e54);
  return;
}

/* _glRasterPos2s_Exec @ 0x8060c (740 bytes) */
void _glRasterPos2s_Exec(int param_1,uint param_2,uint param_3,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  bool bVar1;
  char cVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
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
      uVar7 = param_3;
      if (iVar6 != 0 || (*(uint *)(param_1 + 0x505c) & *(uint *)(param_1 + 0x50b0)) != 0) {
        _gleUpdateMatrixFunc(param_1);
        fparam_1 = extraout_f1;
      }
      if (*(char *)(param_1 + 0x4691) != '\0') {
        iVar5 = *(int *)(param_1 + 0x744c);
        piVar8 = (int *)(param_1 + 0x310);
        cVar2 = *(char *)(*(int *)(param_1 + 0x468c) + 0x79);
        if ((iVar5 != 0) && (*(int *)(iVar5 + 0xec) != 0)) {
          ((void (*)())_gleUpdateFramebufferCompleteness)(param_1,iVar5 + 0x10,uVar7,in_r6,in_r7,in_r8,iVar6,fparam_1,fparam_2,fparam_3,
                     fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
          *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x80000000;
        }
        if ((*(char *)(param_1 + 0x4664) == '\0') && (*(int *)(param_1 + 0x5430) == 0)) {
LAB_00080764:
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
            goto LAB_00080764;
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
                goto LAB_00080860;
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
    ((void (*)())_gleSetRasterPos)(param_1,(double)(float)((double)CONCAT44(0x43300000,param_2 ^ 0x80000000) -
                                            DOUBLE_00108d58),
                     (double)(float)((double)CONCAT44(0x43300000,param_3 ^ 0x80000000) -
                                    DOUBLE_00108d58),(double)FLOAT_00108e50,(double)FLOAT_00108e54);
  }
  else {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar3 = 0x502;
LAB_00080860:
    *(undefined4 *)(param_1 + 0x7574) = uVar3;
  }
  return;
}

/* _glRasterPos2s_CompExec @ 0x808f0 (64 bytes) */
void _glRasterPos2s_CompExec(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  double fparam_1;
  double in_f2;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  
  ((void (*)())_glRasterPos2s_Comp)(param_1,param_2,param_3);
  ((void (*)())_glRasterPos2s_Exec)(param_1,param_2,param_3,fparam_1,in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8);
  return;
}

/* _glRasterPos2sv_Comp @ 0x80930 (128 bytes) */
void _glRasterPos2sv_Comp(param_1, param_2)
  undefined4 param_1;
  short *param_2;
{
  ((void (*)())_glSetRasterPos_Comp)(param_1,(double)(float)((double)CONCAT44(0x43300000,(int)*param_2 ^ 0x80000000) -
                                    DOUBLE_00108d58),
             (double)(float)((double)CONCAT44(0x43300000,(int)param_2[1] ^ 0x80000000) -
                            DOUBLE_00108d58),(double)FLOAT_00108e50,(double)FLOAT_00108e54);
  return;
}

