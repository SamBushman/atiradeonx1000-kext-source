#include "decls.h"

/* _glPixelTransferi_CompExec @ 0x7dfa8 (64 bytes) */
void _glPixelTransferi_CompExec(glContext, pname, param)
  undefined4 glContext;
  undefined4 pname;
  undefined4 param;
{
  _glPixelTransferi_Comp(glContext,pname,param);
  _glPixelTransferi_Exec(glContext,pname,param);
  return;
}

/* _glPixelZoom_ListExec @ 0x7dfe8 (44 bytes) */
int _glPixelZoom_ListExec(glContext, listRecord)
  undefined4 glContext;
  float *listRecord;
{
  ((void (*)())_glPixelZoom_Exec)(glContext,(double)*listRecord,(double)listRecord[1]);
  return 8;
}

/* _glPixelZoom_Comp @ 0x7e014 (100 bytes) */
float * _glPixelZoom_Comp(undefined4 glContext,float xfactor,float yfactor)
{
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glPixelZoom_ListExec_00110258,8);
  if (listRecord != (float *)0x0) {
    listRecord[1] = (float)yfactor;
    *listRecord = (float)xfactor;
  }
  return listRecord;
}

/* _glPixelZoom_Exec @ 0x7e078 (156 bytes) */
void _glPixelZoom_Exec(int glContext,float xfactor,float yfactor)
{
  uint uVar1;
  float doubleOne;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    *(float *)(glContext + 0x31a8) = (float)xfactor;
    doubleOne = (double)FLOAT_00108e54;
    *(float *)(glContext + 0x31ac) = (float)yfactor;
    if (xfactor == (double)doubleOne) {
      uVar1 = *(uint *)(glContext + 0x3414) & 0xffffbfff;
    }
    else {
      uVar1 = *(uint *)(glContext + 0x3414) | 0x4000;
    }
    *(uint *)(glContext + 0x3414) = uVar1;
    if (yfactor == (double)FLOAT_00108e54) {
      uVar1 = *(uint *)(glContext + 0x3414) & 0xffff7fff;
    }
    else {
      uVar1 = *(uint *)(glContext + 0x3414) | 0x8000;
    }
    *(uint *)(glContext + 0x3414) = uVar1;
    *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x200000;
    return;
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  *(undefined4 *)(glContext + 0x7574) = 0x502;
  return;
}

/* _glPixelZoom_CompExec @ 0x7e114 (80 bytes) */
void _glPixelZoom_CompExec(undefined4 glContext,float xfactor,float yfactor)
{
  ((float * (*)())_glPixelZoom_Comp)(glContext,xfactor,yfactor);
  ((void (*)())_glPixelZoom_Exec)(glContext,xfactor,yfactor);
  return;
}

/* _glPNTrianglesiATIX_ListExec @ 0x7e164 (44 bytes) */
int _glPNTrianglesiATIX_ListExec(glContext, listRecord)
  undefined4 glContext;
  undefined4 *listRecord;
{
  ((void (*)())_glPNTrianglesiATIX_Exec)(glContext,*listRecord,listRecord[1]);
  return 8;
}

/* _glPNTrianglesiATIX_Comp @ 0x7e190 (84 bytes) */
int _glPNTrianglesiATIX_Comp(glContext, pname, param)
  undefined4 glContext;
  undefined4 pname;
  undefined4 param;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glPNTrianglesiATIX_ListExec_0011025c,8);
  if (listRecord != (undefined4 *)0x0) {
    listRecord[1] = param;
    *listRecord = pname;
  }
  return listRecord;
}

/* _glPNTrianglesiATIX_Exec @ 0x7e1e4 (200 bytes) */
void _glPNTrianglesiATIX_Exec(glContext, pname, param)
  int glContext;
  uint pname;
  int param;
{
  undefined4 glErrorCode;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (pname == 0x6093) {
      if (param - 0x6097U < 2) {
        *(short *)(glContext + 0x280a) = (short)param;
        goto LAB_0007e29c;
      }
    }
    else if (pname < 0x6094) {
      if ((pname == 0x6092) && (param - 0x6095U < 2)) {
        *(short *)(glContext + 0x2808) = (short)param;
LAB_0007e29c:
        *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x80000;
        return;
      }
    }
    else if (pname == 0x6094) {
      if ((param < 0) || (*(int *)(*(int *)(glContext + 0x468c) + 0x9c) < param)) {
        if (*(int *)(glContext + 0x7574) != 0) {
          return;
        }
        glErrorCode = 0x501;
        goto LAB_0007e250;
      }
      *(int *)(glContext + 0x2800) = param;
      goto LAB_0007e29c;
    }
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x500;
  }
  else {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
  }
LAB_0007e250:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glPNTrianglesiATIX_CompExec @ 0x7e2ac (64 bytes) */
void _glPNTrianglesiATIX_CompExec(glContext, pname, param)
  undefined4 glContext;
  undefined4 pname;
  undefined4 param;
{
  ((int (*)())_glPNTrianglesiATIX_Comp)(glContext,pname,param);
  ((void (*)())_glPNTrianglesiATIX_Exec)(glContext,pname,param);
  return;
}

/* _glPNTrianglesfATIX_Comp @ 0x7e2ec (104 bytes) */
undefined4 * _glPNTrianglesfATIX_Comp(undefined4 glContext,undefined4 pname,double param)
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glPNTrianglesiATIX_ListExec_0011025c,8);
  if (listRecord != (undefined4 *)0x0) {
    *listRecord = pname;
    listRecord[1] = (int)param;
  }
  return listRecord;
}

/* _glPNTrianglesfATIX_CompExec @ 0x7e3e4 (216 bytes) */
void _glPNTrianglesfATIX_CompExec(int glContext,undefined4 pname,double param)
{
  int iVar1;
  undefined4 glErrorCode;
  
  ((undefined4 * (*)())_glPNTrianglesfATIX_Comp)(glContext,pname,param);
  if (*(short *)(glContext + 0x4a10) < 0) {
    iVar1 = (int)param;
    if (((iVar1 == 0x6093) || (iVar1 < 0x6094)) || (iVar1 != 0x6094)) {
      if (*(int *)(glContext + 0x7574) != 0) {
        return;
      }
      glErrorCode = 0x500;
    }
    else {
      if (0x6093 < *(int *)(*(int *)(glContext + 0x468c) + 0x9c)) {
        *(undefined4 *)(glContext + 0x2800) = 0x6094;
        *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x80000;
        return;
      }
      if (*(int *)(glContext + 0x7574) != 0) {
        return;
      }
      glErrorCode = 0x501;
    }
  }
  else {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
  }
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glPointParameterf_Exec @ 0x7e42c (484 bytes) */
void _glPointParameterf_Exec(int glContext,uint pname,double param)
{
  bool bVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  
  if (pname == 0x8127) {
    iVar3 = *(int *)(glContext + 0x5434);
    *(float *)(glContext + 0x3424) = (float)param;
  }
  else if (pname < 0x8128) {
    if (pname == 0x60b3) {
      if (DOUBLE_00108d80 <= param) {
        uVar4 = (int)(param - DOUBLE_00108d80) ^ 0x80000000;
      }
      else {
        uVar4 = (uint)(int)param;
      }
      if (uVar4 - 0x60b4 < 2) {
        *(short *)(glContext + 0x3442) = (short)uVar4;
        goto LAB_0007e600;
      }
LAB_0007e5d0:
      if (*(int *)(glContext + 0x7574) == 0) {
        *(undefined4 *)(glContext + 0x7574) = 0x500;
      }
      goto LAB_0007e600;
    }
    if (pname != 0x8126) {
LAB_0007e5e8:
      if (*(int *)(glContext + 0x7574) == 0) {
        *(undefined4 *)(glContext + 0x7574) = 0x500;
        return;
      }
      return;
    }
    iVar3 = *(int *)(glContext + 0x5434);
    *(float *)(glContext + 0x3420) = (float)param;
  }
  else {
    if (pname != 0x8128) {
      if (pname != 0x8863) goto LAB_0007e5e8;
      if (DOUBLE_00108d80 <= param) {
        uVar4 = (int)(param - DOUBLE_00108d80) ^ 0x80000000;
      }
      else {
        uVar4 = (uint)(int)param;
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
      *(short *)(glContext + 0x3440) = (short)uVar4;
      goto LAB_0007e600;
    }
    iVar3 = *(int *)(glContext + 0x5434);
    *(float *)(glContext + 0x3428) = (float)param;
  }
  if (iVar3 == 0) {
    bVar2 = *(byte *)(*(int *)(glContext + 0x5420) + 0x325);
  }
  else {
    bVar2 = *(byte *)(*(int *)(*(int *)(glContext + 0x5430) + 0x20) + 0x359);
  }
  iVar5 = (bVar2 >> 3 & 0x1c) + glContext;
  iVar3 = *(int *)(glContext + 0x5424);
  *(uint *)(iVar5 + 0x324) = *(uint *)(iVar5 + 0x324) | 1 << (bVar2 & 0x1f);
  bVar2 = *(byte *)(iVar3 + 0x325);
  iVar3 = (bVar2 >> 3 & 0x1c) + glContext;
  *(uint *)(iVar3 + 0x348) = *(uint *)(iVar3 + 0x348) | 1 << (bVar2 & 0x1f);
LAB_0007e600:
  *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x400000;
  return;
}

/* _glPointParameterf_Comp @ 0x7e610 (92 bytes) */
undefined4 * _glPointParameterf_Comp(undefined4 glContext,undefined4 pname,float param)
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glPointParameterf_ListExec_0011026c,8);
  if (listRecord != (undefined4 *)0x0) {
    listRecord[1] = (float)param;
    *listRecord = pname;
  }
  return listRecord;
}

/* _glPointParameterf_CompExec @ 0x7e66c (72 bytes) */
void _glPointParameterf_CompExec(undefined4 glContext,undefined4 pname,float param)
{
  ((undefined4 * (*)())_glPointParameterf_Comp)(glContext,pname,param);
  ((void (*)())_glPointParameterf_Exec)(glContext,pname,param);
  return;
}

/* _glPointParameterf_ListExec @ 0x7e6b4 (44 bytes) */
int _glPointParameterf_ListExec(glContext, listRecord)
  undefined4 glContext;
  undefined4 *listRecord;
{
  ((void (*)())_glPointParameterf_Exec)(glContext,*listRecord,(double)GH_U2F((unsigned int)(listRecord[1])));
  return 8;
}

/* _glPointParameterfv_Exec @ 0x7e6e0 (616 bytes) */
void _glPointParameterfv_Exec(glContext, pname, params)
  int glContext;
  uint pname;
  float *params;
{
  bool bVar1;
  bool glContextWord5434IsZero;
  byte dirtyBitNumber;
  uint enumValue;
  int glContextWord5424;
  int dirtyWordAddress348;
  int dirtyWordAddress324;
  float paramAsDouble;
  
  if (pname == 0x8127) {
    glContextWord5434IsZero = *(int *)(glContext + 0x5434) == 0;
    *(float *)(glContext + 0x3424) = *params;
LAB_0007e788:
    if (glContextWord5434IsZero) {
      dirtyBitNumber = *(byte *)(*(int *)(glContext + 0x5420) + 0x325);
    }
    else {
      dirtyBitNumber = *(byte *)(*(int *)(*(int *)(glContext + 0x5430) + 0x20) + 0x359);
    }
    dirtyWordAddress324 = (dirtyBitNumber >> 3 & 0x1c) + glContext;
    glContextWord5424 = *(int *)(glContext + 0x5424);
    *(uint *)(dirtyWordAddress324 + 0x324) = *(uint *)(dirtyWordAddress324 + 0x324) | 1 << (dirtyBitNumber & 0x1f);
    dirtyBitNumber = *(byte *)(glContextWord5424 + 0x325);
  }
  else {
    if (pname < 0x8128) {
      if (pname == 0x60b3) {
        paramAsDouble = (double)*params;
        if (DOUBLE_00108d80 <= (double)paramAsDouble) {
          enumValue = (int)((double)paramAsDouble - DOUBLE_00108d80) ^ 0x80000000;
        }
        else {
          enumValue = (uint)(int)*params;
        }
        if (enumValue - 0x60b4 < 2) {
          *(short *)(glContext + 0x3442) = (short)enumValue;
          goto LAB_0007e938;
        }
LAB_0007e908:
        if (*(int *)(glContext + 0x7574) == 0) {
          *(undefined4 *)(glContext + 0x7574) = 0x500;
        }
        goto LAB_0007e938;
      }
      if (pname != 0x8126) {
LAB_0007e920:
        if (*(int *)(glContext + 0x7574) == 0) {
          *(undefined4 *)(glContext + 0x7574) = 0x500;
          return;
        }
        return;
      }
      glContextWord5434IsZero = *(int *)(glContext + 0x5434) == 0;
      *(float *)(glContext + 0x3420) = *params;
      goto LAB_0007e788;
    }
    if (pname != 0x8129) {
      if (0x8128 < pname) {
        if (pname != 0x8863) goto LAB_0007e920;
        paramAsDouble = (double)*params;
        if (DOUBLE_00108d80 <= (double)paramAsDouble) {
          enumValue = (int)((double)paramAsDouble - DOUBLE_00108d80) ^ 0x80000000;
        }
        else {
          enumValue = (uint)(int)*params;
        }
        if (enumValue != 0x2000) {
          if (enumValue < 0x2001) {
            bVar1 = enumValue == 0;
          }
          else {
            bVar1 = enumValue == 0x2002;
          }
          if (!bVar1) goto LAB_0007e908;
        }
        *(short *)(glContext + 0x3440) = (short)enumValue;
        goto LAB_0007e938;
      }
      glContextWord5434IsZero = *(int *)(glContext + 0x5434) == 0;
      *(float *)(glContext + 0x3428) = *params;
      goto LAB_0007e788;
    }
    *(float *)(glContext + 0x342c) = *params;
    *(float *)(glContext + 0x3430) = params[1];
    *(float *)(glContext + 0x3434) = params[2];
    if (*(int *)(glContext + 0x5434) == 0) {
      dirtyBitNumber = *(byte *)(*(int *)(glContext + 0x5420) + 0x326);
    }
    else {
      dirtyBitNumber = *(byte *)(*(int *)(*(int *)(glContext + 0x5430) + 0x20) + 0x35a);
    }
    dirtyWordAddress324 = (dirtyBitNumber >> 3 & 0x1c) + glContext;
    glContextWord5424 = *(int *)(glContext + 0x5424);
    *(uint *)(dirtyWordAddress324 + 0x324) = *(uint *)(dirtyWordAddress324 + 0x324) | 1 << (dirtyBitNumber & 0x1f);
    dirtyBitNumber = *(byte *)(glContextWord5424 + 0x326);
  }
  dirtyWordAddress348 = (dirtyBitNumber >> 3 & 0x1c) + glContext;
  *(uint *)(dirtyWordAddress348 + 0x348) = *(uint *)(dirtyWordAddress348 + 0x348) | 1 << (dirtyBitNumber & 0x1f);
LAB_0007e938:
  *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x400000;
  return;
}

/* _glPointParameterfv_Comp @ 0x7e948 (148 bytes) */
int _glPointParameterfv_Comp(glContext, pname, params)
  undefined4 glContext;
  int pname;
  int *params;
{
  int iVar1;
  int *dstCursor;
  int remaining;
  
  remaining = 3;
  if (pname != 0x8129) {
    remaining = 1;
  }
  dstCursor = (int *)_gleAddListItem(glContext,PTR__glPointParameterfv_ListExec_00110268,remaining * 4 + 4);
  if ((dstCursor != (int *)0x0) && (*dstCursor = pname, remaining != 0)) {
    dstCursor = dstCursor + 1;
    do {
      iVar1 = *params;
      params = params + 1;
      *dstCursor = iVar1;
      dstCursor = dstCursor + 1;
      remaining = remaining + -1;
    } while (remaining != 0);
  }
  return dstCursor;
}

/* _glPointParameterfv_CompExec @ 0x7e9dc (64 bytes) */
void _glPointParameterfv_CompExec(glContext, pname, params)
  undefined4 glContext;
  undefined4 pname;
  undefined4 params;
{
  ((int (*)())_glPointParameterfv_Comp)(glContext,pname,params);
  ((void (*)())_glPointParameterfv_Exec)(glContext,pname,params);
  return;
}

/* _glPointParameterfv_ListExec @ 0x7ea1c (88 bytes) */
int _glPointParameterfv_ListExec(glContext, listRecord)
  undefined4 glContext;
  int *listRecord;
{
  int iVar1;
  
  iVar1 = 3;
  if (*listRecord != 0x8129) {
    iVar1 = 1;
  }
  ((void (*)())_glPointParameterfv_Exec)(glContext,*listRecord,listRecord + 1);
  return iVar1 * 4 + 4;
}

/* _glPointParameteriARB_Exec @ 0x7ea74 (480 bytes) */
void _glPointParameteriARB_Exec(glContext, pname, param)
  int glContext;
  uint pname;
  uint param;
{
  bool word5434IsZero;
  bool rModeValid;
  byte dirtyBitIndex;
  int glContextWord5424;
  int dirtyWord348;
  int dirtyWord324;
  
  if (pname == 0x8127) {
    word5434IsZero = *(int *)(glContext + 0x5434) == 0;
    *(float *)(glContext + 0x3424) =
         (float)((double)CONCAT44(0x43300000,param ^ 0x80000000) - DOUBLE_00108d58);
  }
  else if (pname < 0x8128) {
    if (pname == 0x60b3) {
      if (param - 0x60b4 < 2) {
        *(short *)(glContext + 0x3442) = (short)param;
        goto LAB_0007ec44;
      }
LAB_0007ec14:
      if (*(int *)(glContext + 0x7574) == 0) {
        *(undefined4 *)(glContext + 0x7574) = 0x500;
      }
      goto LAB_0007ec44;
    }
    if (pname != 0x8126) {
LAB_0007ec2c:
      if (*(int *)(glContext + 0x7574) == 0) {
        *(undefined4 *)(glContext + 0x7574) = 0x500;
        return;
      }
      return;
    }
    word5434IsZero = *(int *)(glContext + 0x5434) == 0;
    *(float *)(glContext + 0x3420) =
         (float)((double)CONCAT44(0x43300000,param ^ 0x80000000) - DOUBLE_00108d58);
  }
  else {
    if (pname != 0x8128) {
      if (pname != 0x8863) goto LAB_0007ec2c;
      if (param != 0x2000) {
        if (param < 0x2001) {
          rModeValid = param == 0;
        }
        else {
          rModeValid = param == 0x2002;
        }
        if (!rModeValid) goto LAB_0007ec14;
      }
      *(short *)(glContext + 0x3440) = (short)param;
      goto LAB_0007ec44;
    }
    word5434IsZero = *(int *)(glContext + 0x5434) == 0;
    *(float *)(glContext + 0x3428) =
         (float)((double)CONCAT44(0x43300000,param ^ 0x80000000) - DOUBLE_00108d58);
  }
  if (word5434IsZero) {
    dirtyBitIndex = *(byte *)(*(int *)(glContext + 0x5420) + 0x325);
  }
  else {
    dirtyBitIndex = *(byte *)(*(int *)(*(int *)(glContext + 0x5430) + 0x20) + 0x359);
  }
  dirtyWord324 = (dirtyBitIndex >> 3 & 0x1c) + glContext;
  glContextWord5424 = *(int *)(glContext + 0x5424);
  *(uint *)(dirtyWord324 + 0x324) = *(uint *)(dirtyWord324 + 0x324) | 1 << (dirtyBitIndex & 0x1f);
  dirtyBitIndex = *(byte *)(glContextWord5424 + 0x325);
  dirtyWord348 = (dirtyBitIndex >> 3 & 0x1c) + glContext;
  *(uint *)(dirtyWord348 + 0x348) = *(uint *)(dirtyWord348 + 0x348) | 1 << (dirtyBitIndex & 0x1f);
LAB_0007ec44:
  *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x400000;
  return;
}

/* _glPointParameteriARB_Comp @ 0x7ec54 (84 bytes) */
int _glPointParameteriARB_Comp(glContext, pname, param)
  undefined4 glContext;
  undefined4 pname;
  undefined4 param;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glPointParameteriARB_ListExec_00110264,8);
  if (listRecord != (undefined4 *)0x0) {
    listRecord[1] = param;
    *listRecord = pname;
  }
  return listRecord;
}

/* _glPointParameteriARB_CompExec @ 0x7eca8 (64 bytes) */
void _glPointParameteriARB_CompExec(glContext, pname, param)
  undefined4 glContext;
  undefined4 pname;
  undefined4 param;
{
  ((int (*)())_glPointParameteriARB_Comp)(glContext,pname,param);
  ((void (*)())_glPointParameteriARB_Exec)(glContext,pname,param);
  return;
}

/* _glPointParameteriARB_ListExec @ 0x7ece8 (44 bytes) */
int _glPointParameteriARB_ListExec(glContext, listRecord)
  undefined4 glContext;
  undefined4 *listRecord;
{
  ((void (*)())_glPointParameteriARB_Exec)(glContext,*listRecord,listRecord[1]);
  return 8;
}

/* _glPointParameterivARB_Exec @ 0x7ed14 (688 bytes) */
void _glPointParameterivARB_Exec(glContext, pname, params)
  int glContext;
  uint pname;
  uint *params;
{
  bool bVar1;
  byte bVar2;
  double intToDoubleBias;
  uint uVar4;
  int iVar5;
  int iVar6;
  
  intToDoubleBias = DOUBLE_00108d58;
  if (pname == 0x8127) {
    bVar1 = *(int *)(glContext + 0x5434) == 0;
    *(float *)(glContext + 0x3424) =
         (float)((double)CONCAT44(0x43300000,*params ^ 0x80000000) - DOUBLE_00108d58);
LAB_0007ee28:
    if (bVar1) {
      bVar2 = *(byte *)(*(int *)(glContext + 0x5420) + 0x325);
    }
    else {
      bVar2 = *(byte *)(*(int *)(*(int *)(glContext + 0x5430) + 0x20) + 0x359);
    }
    iVar6 = (bVar2 >> 3 & 0x1c) + glContext;
    iVar5 = *(int *)(glContext + 0x5424);
    *(uint *)(iVar6 + 0x324) = *(uint *)(iVar6 + 0x324) | 1 << (bVar2 & 0x1f);
    bVar2 = *(byte *)(iVar5 + 0x325);
  }
  else {
    if (pname < 0x8128) {
      if (pname == 0x60b3) {
        if (*params - 0x60b4 < 2) {
          *(short *)(glContext + 0x3442) = (short)*params;
          goto LAB_0007efb4;
        }
LAB_0007ef84:
        if (*(int *)(glContext + 0x7574) == 0) {
          *(undefined4 *)(glContext + 0x7574) = 0x500;
        }
        goto LAB_0007efb4;
      }
      if (pname != 0x8126) {
LAB_0007ef9c:
        if (*(int *)(glContext + 0x7574) == 0) {
          *(undefined4 *)(glContext + 0x7574) = 0x500;
          return;
        }
        return;
      }
      bVar1 = *(int *)(glContext + 0x5434) == 0;
      *(float *)(glContext + 0x3420) =
           (float)((double)CONCAT44(0x43300000,*params ^ 0x80000000) - DOUBLE_00108d58);
      goto LAB_0007ee28;
    }
    if (pname != 0x8129) {
      if (0x8128 < pname) {
        if (pname != 0x8863) goto LAB_0007ef9c;
        uVar4 = *params;
        if (uVar4 != 0x2000) {
          if (uVar4 < 0x2001) {
            bVar1 = uVar4 == 0;
          }
          else {
            bVar1 = uVar4 == 0x2002;
          }
          if (!bVar1) goto LAB_0007ef84;
        }
        *(short *)(glContext + 0x3440) = (short)uVar4;
        goto LAB_0007efb4;
      }
      bVar1 = *(int *)(glContext + 0x5434) == 0;
      *(float *)(glContext + 0x3428) =
           (float)((double)CONCAT44(0x43300000,*params ^ 0x80000000) - DOUBLE_00108d58);
      goto LAB_0007ee28;
    }
    *(float *)(glContext + 0x342c) =
         (float)((double)CONCAT44(0x43300000,*params ^ 0x80000000) - DOUBLE_00108d58);
    *(float *)(glContext + 0x3430) =
         (float)((double)CONCAT44(0x43300000,params[1] ^ 0x80000000) - intToDoubleBias);
    *(float *)(glContext + 0x3434) =
         (float)((double)CONCAT44(0x43300000,params[2] ^ 0x80000000) - intToDoubleBias);
    if (*(int *)(glContext + 0x5434) == 0) {
      bVar2 = *(byte *)(*(int *)(glContext + 0x5420) + 0x326);
    }
    else {
      bVar2 = *(byte *)(*(int *)(*(int *)(glContext + 0x5430) + 0x20) + 0x35a);
    }
    iVar6 = (bVar2 >> 3 & 0x1c) + glContext;
    iVar5 = *(int *)(glContext + 0x5424);
    *(uint *)(iVar6 + 0x324) = *(uint *)(iVar6 + 0x324) | 1 << (bVar2 & 0x1f);
    bVar2 = *(byte *)(iVar5 + 0x326);
  }
  iVar5 = (bVar2 >> 3 & 0x1c) + glContext;
  *(uint *)(iVar5 + 0x348) = *(uint *)(iVar5 + 0x348) | 1 << (bVar2 & 0x1f);
LAB_0007efb4:
  *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x400000;
  return;
}

/* _glPointParameterivARB_Comp @ 0x7efc4 (148 bytes) */
int _glPointParameterivARB_Comp(glContext, pname, params)
  undefined4 glContext;
  int pname;
  int *params;
{
  int iVar1;
  int *dstCursor;
  int remaining;
  
  remaining = 3;
  if (pname != 0x8129) {
    remaining = 1;
  }
  dstCursor = (int *)_gleAddListItem(glContext,PTR__glPointParameterivARB_ListExec_00110260,remaining * 4 + 4
                                 );
  if ((dstCursor != (int *)0x0) && (*dstCursor = pname, remaining != 0)) {
    dstCursor = dstCursor + 1;
    do {
      iVar1 = *params;
      params = params + 1;
      *dstCursor = iVar1;
      dstCursor = dstCursor + 1;
      remaining = remaining + -1;
    } while (remaining != 0);
  }
  return dstCursor;
}

/* _glPointParameterivARB_CompExec @ 0x7f058 (64 bytes) */
void _glPointParameterivARB_CompExec(glContext, pname, params)
  undefined4 glContext;
  undefined4 pname;
  undefined4 params;
{
  ((int (*)())_glPointParameterivARB_Comp)(glContext,pname,params);
  ((void (*)())_glPointParameterivARB_Exec)(glContext,pname,params);
  return;
}

/* _glPointParameterivARB_ListExec @ 0x7f098 (88 bytes) */
int _glPointParameterivARB_ListExec(glContext, listRecord)
  undefined4 glContext;
  int *listRecord;
{
  int iVar1;
  
  iVar1 = 3;
  if (*listRecord != 0x8129) {
    iVar1 = 1;
  }
  ((void (*)())_glPointParameterivARB_Exec)(glContext,*listRecord,listRecord + 1);
  return iVar1 * 4 + 4;
}

/* _glPointSize_ListExec @ 0x7f0f0 (40 bytes) */
int _glPointSize_ListExec(glContext, listRecord)
  undefined4 glContext;
  float *listRecord;
{
  ((void (*)())_glPointSize_Exec)(glContext,(double)*listRecord);
  return 4;
}

/* _glPointSize_Comp @ 0x7f118 (84 bytes) */
float * _glPointSize_Comp(undefined4 glContext,float size)
{
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glPointSize_ListExec_00110270,4);
  if (listRecord != (float *)0x0) {
    *listRecord = (float)size;
  }
  return listRecord;
}

/* _glPointSize_CompExec @ 0x7f16c (64 bytes) */
void _glPointSize_CompExec(undefined4 glContext,float size)
{
  ((float * (*)())_glPointSize_Comp)(glContext,size);
  ((void (*)())_glPointSize_Exec)(glContext,size);
  return;
}

/* _glPolygonMode_ListExec @ 0x7f1ac (44 bytes) */
int _glPolygonMode_ListExec(glContext, listRecord)
  undefined4 glContext;
  undefined4 *listRecord;
{
  _glPolygonMode_Exec(glContext,*listRecord,listRecord[1]);
  return 8;
}

/* _glPolygonMode_Comp @ 0x7f1d8 (84 bytes) */
int _glPolygonMode_Comp(glContext, face, mode)
  undefined4 glContext;
  undefined4 face;
  undefined4 mode;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glPolygonMode_ListExec_00110274,8);
  if (listRecord != (undefined4 *)0x0) {
    listRecord[1] = mode;
    *listRecord = face;
  }
  return listRecord;
}

/* _glPolygonMode_CompExec @ 0x7f22c (64 bytes) */
void _glPolygonMode_CompExec(glContext, face, mode)
  undefined4 glContext;
  undefined4 face;
  undefined4 mode;
{
  ((int (*)())_glPolygonMode_Comp)(glContext,face,mode);
  _glPolygonMode_Exec(glContext,face,mode);
  return;
}

/* _glPolygonOffset_ListExec @ 0x7f26c (44 bytes) */
int _glPolygonOffset_ListExec(glContext, listRecord)
  undefined4 glContext;
  float *listRecord;
{
  ((void (*)())_glPolygonOffset_Exec)(glContext,(double)*listRecord,(double)listRecord[1]);
  return 8;
}

/* _glPolygonOffset_Comp @ 0x7f298 (100 bytes) */
float * _glPolygonOffset_Comp(undefined4 glContext,float factor,float units)
{
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glPolygonOffset_ListExec_00110278,8);
  if (listRecord != (float *)0x0) {
    listRecord[1] = (float)units;
    *listRecord = (float)factor;
  }
  return listRecord;
}

/* _glPolygonOffset_Exec @ 0x7f2fc (60 bytes) */
void _glPolygonOffset_Exec(int glContext,float factor,float units)
{
  if (*(short *)(glContext + 0x4a10) < 0) {
    *(float *)(glContext + 0x34c8) = (float)factor;
    *(float *)(glContext + 0x34cc) = (float)units;
    *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x800000;
    return;
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  *(undefined4 *)(glContext + 0x7574) = 0x502;
  return;
}

/* _glPolygonOffset_CompExec @ 0x7f338 (80 bytes) */
void _glPolygonOffset_CompExec(undefined4 glContext,float factor,float units)
{
  ((float * (*)())_glPolygonOffset_Comp)(glContext,factor,units);
  ((void (*)())_glPolygonOffset_Exec)(glContext,factor,units);
  return;
}

/* _glSetRasterPos_ListExec @ 0x7f388 (88 bytes) */
int _glSetRasterPos_ListExec(glContext, listRecord)
  int glContext;
  float *listRecord;
{
  if (*(short *)(glContext + 0x4a10) < 0) {
    ((void (*)())_gleSetRasterPos)(glContext,(double)*listRecord,(double)listRecord[1],(double)listRecord[2],
                     (double)listRecord[3]);
  }
  else if (*(int *)(glContext + 0x7574) == 0) {
    *(undefined4 *)(glContext + 0x7574) = 0x502;
  }
  return 0x10;
}

/* _glSetRasterPos_Comp @ 0x7f3e0 (92 bytes) */
void _glSetRasterPos_Comp(undefined4 glContext,float fparam_1,float fparam_2,float fparam_3,float fparam_4)
{
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glSetRasterPos_ListExec_0011027c,0x10);
  if (listRecord != (float *)0x0) {
    listRecord[3] = (float)fparam_4;
    *listRecord = (float)fparam_1;
    listRecord[1] = (float)fparam_2;
    listRecord[2] = (float)fparam_3;
  }
  return;
}

/* _glRasterPos2d_Comp @ 0x7f43c (44 bytes) */
void _glRasterPos2d_Comp(undefined4 glContext,double x,double y)
{
  ((void (*)())_glSetRasterPos_Comp)(glContext,(double)(float)x,(double)(float)y,(double)FLOAT_00108e50,
             (double)FLOAT_00108e54);
  return;
}

/* _glRasterPos2d_Exec @ 0x7f468 (732 bytes) */
void _glRasterPos2d_Exec(int glContext,double x,double y,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
{
  bool bVar1;
  bool stateClean;
  char cVar2;
  undefined4 glErrorCode;
  int *srcCursor;
  int iVar5;
  int framebufferObject;
  undefined4 incomingR5;
  undefined4 incomingR6;
  undefined4 incomingR7;
  undefined4 incomingR8;
  int matrixFuncDirty;
  int remaining;
  int loopIndex;
  uint dirtyWord3ThenMasked;
  uint dispatchFlags;
  int *dirtyFlagWords;
  double extraout_f1;
  double fparam_1_00;
  double fparam_2_00;
  
  if (-1 < *(short *)(glContext + 0x4a10)) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
    goto LAB_0007f6c4;
  }
  if ((*(int *)(glContext + 0x744c) == 0) && (-1 < *(int *)(glContext + 0x310))) goto LAB_0007f6f0;
  matrixFuncDirty = *(int *)(glContext + 0x50ac);
  fparam_1_00 = x;
  fparam_2_00 = y;
  if (matrixFuncDirty != 0 || (*(uint *)(glContext + 0x505c) & *(uint *)(glContext + 0x50b0)) != 0) {
    _gleUpdateMatrixFunc(glContext);
    fparam_1_00 = extraout_f1;
  }
  if (*(char *)(glContext + 0x4691) == '\0') goto LAB_0007f6f0;
  framebufferObject = *(int *)(glContext + 0x744c);
  dirtyFlagWords = (int *)(glContext + 0x310);
  cVar2 = *(char *)(*(int *)(glContext + 0x468c) + 0x79);
  if ((framebufferObject != 0) && (*(int *)(framebufferObject + 0xec) != 0)) {
    ((void (*)())_gleUpdateFramebufferCompleteness)(glContext,framebufferObject + 0x10,incomingR5,incomingR6,incomingR7,incomingR8,matrixFuncDirty,fparam_1_00,fparam_2_00,forwardedFloatArg3,
               forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
    *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x80000000;
  }
  if ((*(char *)(glContext + 0x4664) == '\0') && (*(int *)(glContext + 0x5430) == 0)) {
LAB_0007f5c8:
    dirtyWord3ThenMasked = *(uint *)(glContext + 0x31c);
  }
  else {
    loopIndex = 0;
    srcCursor = (int *)(glContext + 0x324);
    do {
      iVar5 = *srcCursor;
      srcCursor = srcCursor + 1;
      if (iVar5 != 0) {
        *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x800000;
        break;
      }
      loopIndex = loopIndex + 1;
    } while (loopIndex < 9);
    dirtyWord3ThenMasked = *(uint *)(glContext + 0x31c);
    if ((dirtyWord3ThenMasked & 0x15555) != 0) {
      if (*(char *)(glContext + 0x2e54) != '\0') {
        _gleUpdateLightRGBASums(glContext,glContext + 0x2c20,0);
      }
      if (*(char *)(glContext + 0x3094) != '\0') {
        _gleUpdateLightRGBASums(glContext,glContext + 0x2e60,1);
      }
      goto LAB_0007f5c8;
    }
  }
  bVar1 = cVar2 == '\0';
  if (bVar1) {
    dirtyWord3ThenMasked = dirtyWord3ThenMasked & 0x17000000;
  }
  else {
    dirtyWord3ThenMasked = dirtyWord3ThenMasked & 0x17ffffff;
  }
  if (bVar1) {
    stateClean = ((*dirtyFlagWords == 0 && *(int *)(glContext + 0x314) == 0) && dirtyWord3ThenMasked == 0) &&
            *(int *)(glContext + 800) == 0;
  }
  else {
    stateClean = (((*dirtyFlagWords == 0 && *(int *)(glContext + 0x314) == 0) &&
             (*(uint *)(glContext + 0x318) & 0xfffffffd) == 0) && dirtyWord3ThenMasked == 0) &&
            *(int *)(glContext + 800) == 0;
  }
  if (!stateClean) {
    if (*(char *)(glContext + 0x85a8) == *(char *)(glContext + 0x85a6)) {
      dispatchFlags = (**(code **)(glContext + 0x4788))
                        (*(undefined4 *)(glContext + 0x4688),glContext + 0x4698,dirtyFlagWords);
      if ((((dispatchFlags & 3) != (uint)*(byte *)(glContext + 0x7580)) ||
          ((dispatchFlags & 4) != (uint)*(byte *)(glContext + 0x7581))) ||
         ((dispatchFlags & 8) != (uint)(*(char *)(glContext + 0x759d) == '\0'))) {
        if ((dispatchFlags & 4) == 0) {
          dispatchFlags = dispatchFlags & 0xfffffffe;
          *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x10000000;
        }
        _gleUpdateDispatchCodeChange(glContext,dispatchFlags);
        if (*(char *)(glContext + 0x759d) == '\0') {
          if (*(int *)(glContext + 0x7574) != 0) {
            return;
          }
          glErrorCode = 0x506;
LAB_0007f6c4:
          *(undefined4 *)(glContext + 0x7574) = glErrorCode;
          return;
        }
      }
    }
    else {
      _gleSwitchToNonRevertRenderer(glContext);
    }
    remaining = 0x13;
    do {
      *dirtyFlagWords = 0;
      dirtyFlagWords = dirtyFlagWords + 1;
      remaining = remaining + -1;
    } while (remaining != 0);
  }
LAB_0007f6f0:
  ((void (*)())_gleSetRasterPos)(glContext,(double)(float)x,(double)(float)y,(double)FLOAT_00108e50,
                   (double)FLOAT_00108e54);
  return;
}

/* _glRasterPos2d_CompExec @ 0x7f744 (80 bytes) */
void _glRasterPos2d_CompExec(undefined4 glContext,double x,double y)
{
  double incomingFpr3;
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  
  ((void (*)())_glRasterPos2d_Comp)(glContext,x,y);
  ((void (*)())_glRasterPos2d_Exec)(glContext,x,y,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8);
  return;
}

/* _glRasterPos2dv_Comp @ 0x7f794 (52 bytes) */
void _glRasterPos2dv_Comp(glContext, v)
  undefined4 glContext;
  double *v;
{
  ((void (*)())_glSetRasterPos_Comp)(glContext,(double)(float)*v,(double)(float)v[1],(double)FLOAT_00108e50,
             (double)FLOAT_00108e54);
  return;
}

/* _glRasterPos2dv_Exec @ 0x7f7c8 (712 bytes) */
void _glRasterPos2dv_Exec(int glContext,double *v,double fparam_1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
{
  bool bVar1;
  bool stateClean;
  char cVar2;
  undefined4 glErrorCode;
  int *srcCursor;
  int iVar5;
  int framebufferObject;
  undefined4 incomingR5;
  undefined4 incomingR6;
  undefined4 incomingR7;
  undefined4 incomingR8;
  int matrixFuncDirty;
  int remaining;
  int loopIndex;
  uint dirtyWord3ThenMasked;
  uint dispatchFlags;
  int *dirtyFlagWords;
  double extraout_f1;
  
  if (-1 < *(short *)(glContext + 0x4a10)) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
    goto LAB_0007fa18;
  }
  if ((*(int *)(glContext + 0x744c) == 0) && (-1 < *(int *)(glContext + 0x310))) goto LAB_0007fa44;
  matrixFuncDirty = *(int *)(glContext + 0x50ac);
  if (matrixFuncDirty != 0 || (*(uint *)(glContext + 0x505c) & *(uint *)(glContext + 0x50b0)) != 0) {
    _gleUpdateMatrixFunc(glContext);
    fparam_1 = extraout_f1;
  }
  if (*(char *)(glContext + 0x4691) == '\0') goto LAB_0007fa44;
  framebufferObject = *(int *)(glContext + 0x744c);
  dirtyFlagWords = (int *)(glContext + 0x310);
  cVar2 = *(char *)(*(int *)(glContext + 0x468c) + 0x79);
  if ((framebufferObject != 0) && (*(int *)(framebufferObject + 0xec) != 0)) {
    ((void (*)())_gleUpdateFramebufferCompleteness)(glContext,framebufferObject + 0x10,incomingR5,incomingR6,incomingR7,incomingR8,matrixFuncDirty,fparam_1,forwardedFloatArg2,forwardedFloatArg3,
               forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
    *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x80000000;
  }
  if ((*(char *)(glContext + 0x4664) == '\0') && (*(int *)(glContext + 0x5430) == 0)) {
LAB_0007f91c:
    dirtyWord3ThenMasked = *(uint *)(glContext + 0x31c);
  }
  else {
    loopIndex = 0;
    srcCursor = (int *)(glContext + 0x324);
    do {
      iVar5 = *srcCursor;
      srcCursor = srcCursor + 1;
      if (iVar5 != 0) {
        *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x800000;
        break;
      }
      loopIndex = loopIndex + 1;
    } while (loopIndex < 9);
    dirtyWord3ThenMasked = *(uint *)(glContext + 0x31c);
    if ((dirtyWord3ThenMasked & 0x15555) != 0) {
      if (*(char *)(glContext + 0x2e54) != '\0') {
        _gleUpdateLightRGBASums(glContext,glContext + 0x2c20,0);
      }
      if (*(char *)(glContext + 0x3094) != '\0') {
        _gleUpdateLightRGBASums(glContext,glContext + 0x2e60,1);
      }
      goto LAB_0007f91c;
    }
  }
  bVar1 = cVar2 == '\0';
  if (bVar1) {
    dirtyWord3ThenMasked = dirtyWord3ThenMasked & 0x17000000;
  }
  else {
    dirtyWord3ThenMasked = dirtyWord3ThenMasked & 0x17ffffff;
  }
  if (bVar1) {
    stateClean = ((*dirtyFlagWords == 0 && *(int *)(glContext + 0x314) == 0) && dirtyWord3ThenMasked == 0) &&
            *(int *)(glContext + 800) == 0;
  }
  else {
    stateClean = (((*dirtyFlagWords == 0 && *(int *)(glContext + 0x314) == 0) &&
             (*(uint *)(glContext + 0x318) & 0xfffffffd) == 0) && dirtyWord3ThenMasked == 0) &&
            *(int *)(glContext + 800) == 0;
  }
  if (!stateClean) {
    if (*(char *)(glContext + 0x85a8) == *(char *)(glContext + 0x85a6)) {
      dispatchFlags = (**(code **)(glContext + 0x4788))
                        (*(undefined4 *)(glContext + 0x4688),glContext + 0x4698,dirtyFlagWords);
      if ((((dispatchFlags & 3) != (uint)*(byte *)(glContext + 0x7580)) ||
          ((dispatchFlags & 4) != (uint)*(byte *)(glContext + 0x7581))) ||
         ((dispatchFlags & 8) != (uint)(*(char *)(glContext + 0x759d) == '\0'))) {
        if ((dispatchFlags & 4) == 0) {
          dispatchFlags = dispatchFlags & 0xfffffffe;
          *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x10000000;
        }
        _gleUpdateDispatchCodeChange(glContext,dispatchFlags);
        if (*(char *)(glContext + 0x759d) == '\0') {
          if (*(int *)(glContext + 0x7574) != 0) {
            return;
          }
          glErrorCode = 0x506;
LAB_0007fa18:
          *(undefined4 *)(glContext + 0x7574) = glErrorCode;
          return;
        }
      }
    }
    else {
      _gleSwitchToNonRevertRenderer(glContext);
    }
    remaining = 0x13;
    do {
      *dirtyFlagWords = 0;
      dirtyFlagWords = dirtyFlagWords + 1;
      remaining = remaining + -1;
    } while (remaining != 0);
  }
LAB_0007fa44:
  ((void (*)())_gleSetRasterPos)(glContext,(double)(float)(*v),(double)(float)(v[1]),(double)FLOAT_00108e50,
                   (double)FLOAT_00108e54);
  return;
}

/* _glRasterPos2dv_CompExec @ 0x7fa90 (56 bytes) */
void _glRasterPos2dv_CompExec(glContext, v)
  undefined4 glContext;
  undefined4 v;
{
  double fparam_1;
  double incomingFpr2;
  double incomingFpr3;
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  
  ((void (*)())_glRasterPos2dv_Comp)(glContext,v);
  ((void (*)())_glRasterPos2dv_Exec)(glContext,v,fparam_1,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8);
  return;
}

/* _glRasterPos2f_Comp @ 0x7fac8 (36 bytes) */
void _glRasterPos2f_Comp(undefined4 glContext,float x,float y)
{
  ((void (*)())_glSetRasterPos_Comp)(glContext,x,y,(double)FLOAT_00108e50,(double)FLOAT_00108e54);
  return;
}

/* _glRasterPos2f_Exec @ 0x7faec (732 bytes) */
void _glRasterPos2f_Exec(int glContext,float x,float y,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
{
  bool rendererInfoByte79Zero;
  bool stateClean;
  char rendererInfoByte79;
  undefined4 glErrorCode;
  int *srcCursor;
  int dirtyWord;
  int framebufferObject;
  undefined4 incomingR5;
  undefined4 incomingR6;
  undefined4 incomingR7;
  undefined4 incomingR8;
  int matrixFuncDirty;
  int remaining;
  int loopIndex;
  uint dirtyWord3ThenMasked;
  uint dispatchFlags;
  int *dirtyFlagWords;
  double f1AfterCall;
  double fparam_1_00;
  double fparam_2_00;
  
  if (-1 < *(short *)(glContext + 0x4a10)) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
    goto LAB_0007fd48;
  }
  if ((*(int *)(glContext + 0x744c) == 0) && (-1 < *(int *)(glContext + 0x310))) goto LAB_0007fd74;
  matrixFuncDirty = *(int *)(glContext + 0x50ac);
  fparam_1_00 = x;
  fparam_2_00 = y;
  if (matrixFuncDirty != 0 || (*(uint *)(glContext + 0x505c) & *(uint *)(glContext + 0x50b0)) != 0) {
    _gleUpdateMatrixFunc(glContext);
    fparam_1_00 = f1AfterCall;
  }
  if (*(char *)(glContext + 0x4691) == '\0') goto LAB_0007fd74;
  framebufferObject = *(int *)(glContext + 0x744c);
  dirtyFlagWords = (int *)(glContext + 0x310);
  rendererInfoByte79 = *(char *)(*(int *)(glContext + 0x468c) + 0x79);
  if ((framebufferObject != 0) && (*(int *)(framebufferObject + 0xec) != 0)) {
    ((void (*)())_gleUpdateFramebufferCompleteness)(glContext,framebufferObject + 0x10,incomingR5,incomingR6,incomingR7,incomingR8,matrixFuncDirty,fparam_1_00,fparam_2_00,forwardedFloatArg3,
               forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
    *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x80000000;
  }
  if ((*(char *)(glContext + 0x4664) == '\0') && (*(int *)(glContext + 0x5430) == 0)) {
LAB_0007fc4c:
    dirtyWord3ThenMasked = *(uint *)(glContext + 0x31c);
  }
  else {
    loopIndex = 0;
    srcCursor = (int *)(glContext + 0x324);
    do {
      dirtyWord = *srcCursor;
      srcCursor = srcCursor + 1;
      if (dirtyWord != 0) {
        *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x800000;
        break;
      }
      loopIndex = loopIndex + 1;
    } while (loopIndex < 9);
    dirtyWord3ThenMasked = *(uint *)(glContext + 0x31c);
    if ((dirtyWord3ThenMasked & 0x15555) != 0) {
      if (*(char *)(glContext + 0x2e54) != '\0') {
        _gleUpdateLightRGBASums(glContext,glContext + 0x2c20,0);
      }
      if (*(char *)(glContext + 0x3094) != '\0') {
        _gleUpdateLightRGBASums(glContext,glContext + 0x2e60,1);
      }
      goto LAB_0007fc4c;
    }
  }
  rendererInfoByte79Zero = rendererInfoByte79 == '\0';
  if (rendererInfoByte79Zero) {
    dirtyWord3ThenMasked = dirtyWord3ThenMasked & 0x17000000;
  }
  else {
    dirtyWord3ThenMasked = dirtyWord3ThenMasked & 0x17ffffff;
  }
  if (rendererInfoByte79Zero) {
    stateClean = ((*dirtyFlagWords == 0 && *(int *)(glContext + 0x314) == 0) && dirtyWord3ThenMasked == 0) &&
            *(int *)(glContext + 800) == 0;
  }
  else {
    stateClean = (((*dirtyFlagWords == 0 && *(int *)(glContext + 0x314) == 0) &&
             (*(uint *)(glContext + 0x318) & 0xfffffffd) == 0) && dirtyWord3ThenMasked == 0) &&
            *(int *)(glContext + 800) == 0;
  }
  if (!stateClean) {
    if (*(char *)(glContext + 0x85a8) == *(char *)(glContext + 0x85a6)) {
      dispatchFlags = (**(code **)(glContext + 0x4788))
                        (*(undefined4 *)(glContext + 0x4688),glContext + 0x4698,dirtyFlagWords);
      if ((((dispatchFlags & 3) != (uint)*(byte *)(glContext + 0x7580)) ||
          ((dispatchFlags & 4) != (uint)*(byte *)(glContext + 0x7581))) ||
         ((dispatchFlags & 8) != (uint)(*(char *)(glContext + 0x759d) == '\0'))) {
        if ((dispatchFlags & 4) == 0) {
          dispatchFlags = dispatchFlags & 0xfffffffe;
          *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x10000000;
        }
        _gleUpdateDispatchCodeChange(glContext,dispatchFlags);
        if (*(char *)(glContext + 0x759d) == '\0') {
          if (*(int *)(glContext + 0x7574) != 0) {
            return;
          }
          glErrorCode = 0x506;
LAB_0007fd48:
          *(undefined4 *)(glContext + 0x7574) = glErrorCode;
          return;
        }
      }
    }
    else {
      _gleSwitchToNonRevertRenderer(glContext);
    }
    remaining = 0x13;
    do {
      *dirtyFlagWords = 0;
      dirtyFlagWords = dirtyFlagWords + 1;
      remaining = remaining + -1;
    } while (remaining != 0);
  }
LAB_0007fd74:
  ((void (*)())_gleSetRasterPos)(glContext,x,y,(double)FLOAT_00108e50,(double)FLOAT_00108e54);
  return;
}

/* _glRasterPos2f_CompExec @ 0x7fdc8 (80 bytes) */
void _glRasterPos2f_CompExec(undefined4 glContext,float x,float y)
{
  double incomingFpr3;
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  
  ((void (*)())_glRasterPos2f_Comp)(glContext,x,y);
  ((void (*)())_glRasterPos2f_Exec)(glContext,x,y,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8);
  return;
}

/* _glRasterPos2fv_Comp @ 0x7fe18 (44 bytes) */
void _glRasterPos2fv_Comp(glContext, v)
  undefined4 glContext;
  float *v;
{
  ((void (*)())_glSetRasterPos_Comp)(glContext,(double)*v,(double)v[1],(double)FLOAT_00108e50,
             (double)FLOAT_00108e54);
  return;
}

/* _glRasterPos2fv_Exec @ 0x7fe44 (704 bytes) */
void _glRasterPos2fv_Exec(int glContext,float *v,double fparam_1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
{
  bool bVar1;
  bool stateClean;
  char cVar2;
  undefined4 glErrorCode;
  int *srcCursor;
  int iVar5;
  int framebufferObject;
  undefined4 incomingR5;
  undefined4 incomingR6;
  undefined4 incomingR7;
  undefined4 incomingR8;
  int matrixFuncDirty;
  int remaining;
  int loopIndex;
  uint dirtyWord3ThenMasked;
  uint dispatchFlags;
  int *dirtyFlagWords;
  double extraout_f1;
  
  if (-1 < *(short *)(glContext + 0x4a10)) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
    goto LAB_00080094;
  }
  if ((*(int *)(glContext + 0x744c) == 0) && (-1 < *(int *)(glContext + 0x310))) goto LAB_000800c0;
  matrixFuncDirty = *(int *)(glContext + 0x50ac);
  if (matrixFuncDirty != 0 || (*(uint *)(glContext + 0x505c) & *(uint *)(glContext + 0x50b0)) != 0) {
    _gleUpdateMatrixFunc(glContext);
    fparam_1 = extraout_f1;
  }
  if (*(char *)(glContext + 0x4691) == '\0') goto LAB_000800c0;
  framebufferObject = *(int *)(glContext + 0x744c);
  dirtyFlagWords = (int *)(glContext + 0x310);
  cVar2 = *(char *)(*(int *)(glContext + 0x468c) + 0x79);
  if ((framebufferObject != 0) && (*(int *)(framebufferObject + 0xec) != 0)) {
    ((void (*)())_gleUpdateFramebufferCompleteness)(glContext,framebufferObject + 0x10,incomingR5,incomingR6,incomingR7,incomingR8,matrixFuncDirty,fparam_1,forwardedFloatArg2,forwardedFloatArg3,
               forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
    *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x80000000;
  }
  if ((*(char *)(glContext + 0x4664) == '\0') && (*(int *)(glContext + 0x5430) == 0)) {
LAB_0007ff98:
    dirtyWord3ThenMasked = *(uint *)(glContext + 0x31c);
  }
  else {
    loopIndex = 0;
    srcCursor = (int *)(glContext + 0x324);
    do {
      iVar5 = *srcCursor;
      srcCursor = srcCursor + 1;
      if (iVar5 != 0) {
        *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x800000;
        break;
      }
      loopIndex = loopIndex + 1;
    } while (loopIndex < 9);
    dirtyWord3ThenMasked = *(uint *)(glContext + 0x31c);
    if ((dirtyWord3ThenMasked & 0x15555) != 0) {
      if (*(char *)(glContext + 0x2e54) != '\0') {
        _gleUpdateLightRGBASums(glContext,glContext + 0x2c20,0);
      }
      if (*(char *)(glContext + 0x3094) != '\0') {
        _gleUpdateLightRGBASums(glContext,glContext + 0x2e60,1);
      }
      goto LAB_0007ff98;
    }
  }
  bVar1 = cVar2 == '\0';
  if (bVar1) {
    dirtyWord3ThenMasked = dirtyWord3ThenMasked & 0x17000000;
  }
  else {
    dirtyWord3ThenMasked = dirtyWord3ThenMasked & 0x17ffffff;
  }
  if (bVar1) {
    stateClean = ((*dirtyFlagWords == 0 && *(int *)(glContext + 0x314) == 0) && dirtyWord3ThenMasked == 0) &&
            *(int *)(glContext + 800) == 0;
  }
  else {
    stateClean = (((*dirtyFlagWords == 0 && *(int *)(glContext + 0x314) == 0) &&
             (*(uint *)(glContext + 0x318) & 0xfffffffd) == 0) && dirtyWord3ThenMasked == 0) &&
            *(int *)(glContext + 800) == 0;
  }
  if (!stateClean) {
    if (*(char *)(glContext + 0x85a8) == *(char *)(glContext + 0x85a6)) {
      dispatchFlags = (**(code **)(glContext + 0x4788))
                        (*(undefined4 *)(glContext + 0x4688),glContext + 0x4698,dirtyFlagWords);
      if ((((dispatchFlags & 3) != (uint)*(byte *)(glContext + 0x7580)) ||
          ((dispatchFlags & 4) != (uint)*(byte *)(glContext + 0x7581))) ||
         ((dispatchFlags & 8) != (uint)(*(char *)(glContext + 0x759d) == '\0'))) {
        if ((dispatchFlags & 4) == 0) {
          dispatchFlags = dispatchFlags & 0xfffffffe;
          *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x10000000;
        }
        _gleUpdateDispatchCodeChange(glContext,dispatchFlags);
        if (*(char *)(glContext + 0x759d) == '\0') {
          if (*(int *)(glContext + 0x7574) != 0) {
            return;
          }
          glErrorCode = 0x506;
LAB_00080094:
          *(undefined4 *)(glContext + 0x7574) = glErrorCode;
          return;
        }
      }
    }
    else {
      _gleSwitchToNonRevertRenderer(glContext);
    }
    remaining = 0x13;
    do {
      *dirtyFlagWords = 0;
      dirtyFlagWords = dirtyFlagWords + 1;
      remaining = remaining + -1;
    } while (remaining != 0);
  }
LAB_000800c0:
  ((void (*)())_gleSetRasterPos)(glContext,(double)*v,(double)v[1],(double)FLOAT_00108e50,
                   (double)FLOAT_00108e54);
  return;
}

/* _glRasterPos2fv_CompExec @ 0x80104 (56 bytes) */
void _glRasterPos2fv_CompExec(glContext, v)
  undefined4 glContext;
  undefined4 v;
{
  double fparam_1;
  double incomingFpr2;
  double incomingFpr3;
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  
  ((void (*)())_glRasterPos2fv_Comp)(glContext,v);
  ((void (*)())_glRasterPos2fv_Exec)(glContext,v,fparam_1,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8);
  return;
}

/* _glRasterPos2i_Comp @ 0x8013c (120 bytes) */
void _glRasterPos2i_Comp(glContext, x, y)
  undefined4 glContext;
  uint x;
  uint y;
{
  ((void (*)())_glSetRasterPos_Comp)(glContext,(double)(float)((double)CONCAT44(0x43300000,x ^ 0x80000000) -
                                    DOUBLE_00108d58),
             (double)(float)((double)CONCAT44(0x43300000,y ^ 0x80000000) - DOUBLE_00108d58),
             (double)FLOAT_00108e50,(double)FLOAT_00108e54);
  return;
}

/* _glRasterPos2i_CompExec @ 0x801b4 (64 bytes) */
void _glRasterPos2i_CompExec(glContext, x, y)
  undefined4 glContext;
  undefined4 x;
  undefined4 y;
{
  double forwardedFloatArg1;
  double incomingFpr2;
  double incomingFpr3;
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  
  ((void (*)())_glRasterPos2i_Comp)(glContext,x,y);
  ((void (*)())_glRasterPos2i_Exec)(glContext,x,y,forwardedFloatArg1,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8);
  return;
}

/* _glRasterPos2iv_Comp @ 0x801f4 (128 bytes) */
void _glRasterPos2iv_Comp(glContext, v)
  undefined4 glContext;
  uint *v;
{
  ((void (*)())_glSetRasterPos_Comp)(glContext,(double)(float)((double)CONCAT44(0x43300000,*v ^ 0x80000000) -
                                    DOUBLE_00108d58),
             (double)(float)((double)CONCAT44(0x43300000,v[1] ^ 0x80000000) - DOUBLE_00108d58)
             ,(double)FLOAT_00108e50,(double)FLOAT_00108e54);
  return;
}

/* _glRasterPos2iv_Exec @ 0x80274 (744 bytes) */
void _glRasterPos2iv_Exec(int glContext,uint *v,double fparam_1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
{
  bool bVar1;
  bool stateClean;
  char cVar2;
  undefined4 glErrorCode;
  int *srcCursor;
  int iVar5;
  int framebufferObject;
  undefined4 incomingR5;
  undefined4 incomingR6;
  undefined4 incomingR7;
  undefined4 incomingR8;
  int matrixFuncDirty;
  int remaining;
  int loopIndex;
  uint dirtyWord3ThenMasked;
  uint dispatchFlags;
  int *dirtyFlagWords;
  double extraout_f1;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    if ((*(int *)(glContext + 0x744c) != 0) || (*(int *)(glContext + 0x310) < 0)) {
      matrixFuncDirty = *(int *)(glContext + 0x50ac);
      if (matrixFuncDirty != 0 || (*(uint *)(glContext + 0x505c) & *(uint *)(glContext + 0x50b0)) != 0) {
        _gleUpdateMatrixFunc(glContext);
        fparam_1 = extraout_f1;
      }
      if (*(char *)(glContext + 0x4691) != '\0') {
        framebufferObject = *(int *)(glContext + 0x744c);
        dirtyFlagWords = (int *)(glContext + 0x310);
        cVar2 = *(char *)(*(int *)(glContext + 0x468c) + 0x79);
        if ((framebufferObject != 0) && (*(int *)(framebufferObject + 0xec) != 0)) {
          ((void (*)())_gleUpdateFramebufferCompleteness)(glContext,framebufferObject + 0x10,incomingR5,incomingR6,incomingR7,incomingR8,matrixFuncDirty,fparam_1,forwardedFloatArg2,forwardedFloatArg3,
                     forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
          *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x80000000;
        }
        if ((*(char *)(glContext + 0x4664) == '\0') && (*(int *)(glContext + 0x5430) == 0)) {
LAB_000803c8:
          dirtyWord3ThenMasked = *(uint *)(glContext + 0x31c);
        }
        else {
          loopIndex = 0;
          srcCursor = (int *)(glContext + 0x324);
          do {
            iVar5 = *srcCursor;
            srcCursor = srcCursor + 1;
            if (iVar5 != 0) {
              *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x800000;
              break;
            }
            loopIndex = loopIndex + 1;
          } while (loopIndex < 9);
          dirtyWord3ThenMasked = *(uint *)(glContext + 0x31c);
          if ((dirtyWord3ThenMasked & 0x15555) != 0) {
            if (*(char *)(glContext + 0x2e54) != '\0') {
              _gleUpdateLightRGBASums(glContext,glContext + 0x2c20,0);
            }
            if (*(char *)(glContext + 0x3094) != '\0') {
              _gleUpdateLightRGBASums(glContext,glContext + 0x2e60,1);
            }
            goto LAB_000803c8;
          }
        }
        bVar1 = cVar2 == '\0';
        if (bVar1) {
          dirtyWord3ThenMasked = dirtyWord3ThenMasked & 0x17000000;
        }
        else {
          dirtyWord3ThenMasked = dirtyWord3ThenMasked & 0x17ffffff;
        }
        if (bVar1) {
          stateClean = ((*dirtyFlagWords == 0 && *(int *)(glContext + 0x314) == 0) && dirtyWord3ThenMasked == 0) &&
                  *(int *)(glContext + 800) == 0;
        }
        else {
          stateClean = (((*dirtyFlagWords == 0 && *(int *)(glContext + 0x314) == 0) &&
                   (*(uint *)(glContext + 0x318) & 0xfffffffd) == 0) && dirtyWord3ThenMasked == 0) &&
                  *(int *)(glContext + 800) == 0;
        }
        if (!stateClean) {
          if (*(char *)(glContext + 0x85a8) == *(char *)(glContext + 0x85a6)) {
            dispatchFlags = (**(code **)(glContext + 0x4788))
                              (*(undefined4 *)(glContext + 0x4688),glContext + 0x4698,dirtyFlagWords);
            if ((((dispatchFlags & 3) != (uint)*(byte *)(glContext + 0x7580)) ||
                ((dispatchFlags & 4) != (uint)*(byte *)(glContext + 0x7581))) ||
               ((dispatchFlags & 8) != (uint)(*(char *)(glContext + 0x759d) == '\0'))) {
              if ((dispatchFlags & 4) == 0) {
                dispatchFlags = dispatchFlags & 0xfffffffe;
                *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x10000000;
              }
              _gleUpdateDispatchCodeChange(glContext,dispatchFlags);
              if (*(char *)(glContext + 0x759d) == '\0') {
                if (*(int *)(glContext + 0x7574) != 0) {
                  return;
                }
                glErrorCode = 0x506;
                goto LAB_000804c4;
              }
            }
          }
          else {
            _gleSwitchToNonRevertRenderer(glContext);
          }
          remaining = 0x13;
          do {
            *dirtyFlagWords = 0;
            dirtyFlagWords = dirtyFlagWords + 1;
            remaining = remaining + -1;
          } while (remaining != 0);
        }
      }
    }
    ((void (*)())_gleSetRasterPos)(glContext,(double)(float)((double)CONCAT44(0x43300000,*v ^ 0x80000000) -
                                            DOUBLE_00108d58),
                     (double)(float)((double)CONCAT44(0x43300000,v[1] ^ 0x80000000) -
                                    DOUBLE_00108d58),(double)FLOAT_00108e50,(double)FLOAT_00108e54);
  }
  else {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
LAB_000804c4:
    *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  }
  return;
}

/* _glRasterPos2iv_CompExec @ 0x8055c (56 bytes) */
void _glRasterPos2iv_CompExec(glContext, v)
  undefined4 glContext;
  undefined4 v;
{
  double fparam_1;
  double incomingFpr2;
  double incomingFpr3;
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  
  ((void (*)())_glRasterPos2iv_Comp)(glContext,v);
  ((void (*)())_glRasterPos2iv_Exec)(glContext,v,fparam_1,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8);
  return;
}

/* _glRasterPos2s_Comp @ 0x80594 (120 bytes) */
void _glRasterPos2s_Comp(glContext, x, y)
  undefined4 glContext;
  uint x;
  uint y;
{
  ((void (*)())_glSetRasterPos_Comp)(glContext,(double)(float)((double)CONCAT44(0x43300000,x ^ 0x80000000) -
                                    DOUBLE_00108d58),
             (double)(float)((double)CONCAT44(0x43300000,y ^ 0x80000000) - DOUBLE_00108d58),
             (double)FLOAT_00108e50,(double)FLOAT_00108e54);
  return;
}

/* _glRasterPos2s_Exec @ 0x8060c (740 bytes) */
void _glRasterPos2s_Exec(int glContext,uint x,uint y,double fparam_1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
{
  bool bVar1;
  bool stateClean;
  char cVar2;
  undefined4 glErrorCode;
  int *srcCursor;
  int iVar5;
  int framebufferObject;
  undefined4 incomingR6;
  undefined4 incomingR7;
  undefined4 incomingR8;
  int matrixFuncDirty;
  int remaining;
  int loopIndex;
  uint uVar7;
  uint dispatchFlags;
  uint dirtyWord3ThenMasked;
  int *dirtyFlagWords;
  double extraout_f1;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    if ((*(int *)(glContext + 0x744c) != 0) || (*(int *)(glContext + 0x310) < 0)) {
      matrixFuncDirty = *(int *)(glContext + 0x50ac);
      uVar7 = y;
      if (matrixFuncDirty != 0 || (*(uint *)(glContext + 0x505c) & *(uint *)(glContext + 0x50b0)) != 0) {
        _gleUpdateMatrixFunc(glContext);
        fparam_1 = extraout_f1;
      }
      if (*(char *)(glContext + 0x4691) != '\0') {
        framebufferObject = *(int *)(glContext + 0x744c);
        dirtyFlagWords = (int *)(glContext + 0x310);
        cVar2 = *(char *)(*(int *)(glContext + 0x468c) + 0x79);
        if ((framebufferObject != 0) && (*(int *)(framebufferObject + 0xec) != 0)) {
          ((void (*)())_gleUpdateFramebufferCompleteness)(glContext,framebufferObject + 0x10,uVar7,incomingR6,incomingR7,incomingR8,matrixFuncDirty,fparam_1,forwardedFloatArg2,forwardedFloatArg3,
                     forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
          *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x80000000;
        }
        if ((*(char *)(glContext + 0x4664) == '\0') && (*(int *)(glContext + 0x5430) == 0)) {
LAB_00080764:
          dirtyWord3ThenMasked = *(uint *)(glContext + 0x31c);
        }
        else {
          loopIndex = 0;
          srcCursor = (int *)(glContext + 0x324);
          do {
            iVar5 = *srcCursor;
            srcCursor = srcCursor + 1;
            if (iVar5 != 0) {
              *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x800000;
              break;
            }
            loopIndex = loopIndex + 1;
          } while (loopIndex < 9);
          dirtyWord3ThenMasked = *(uint *)(glContext + 0x31c);
          if ((dirtyWord3ThenMasked & 0x15555) != 0) {
            if (*(char *)(glContext + 0x2e54) != '\0') {
              _gleUpdateLightRGBASums(glContext,glContext + 0x2c20,0);
            }
            if (*(char *)(glContext + 0x3094) != '\0') {
              _gleUpdateLightRGBASums(glContext,glContext + 0x2e60,1);
            }
            goto LAB_00080764;
          }
        }
        bVar1 = cVar2 == '\0';
        if (bVar1) {
          dirtyWord3ThenMasked = dirtyWord3ThenMasked & 0x17000000;
        }
        else {
          dirtyWord3ThenMasked = dirtyWord3ThenMasked & 0x17ffffff;
        }
        if (bVar1) {
          stateClean = ((*dirtyFlagWords == 0 && *(int *)(glContext + 0x314) == 0) && dirtyWord3ThenMasked == 0) &&
                  *(int *)(glContext + 800) == 0;
        }
        else {
          stateClean = (((*dirtyFlagWords == 0 && *(int *)(glContext + 0x314) == 0) &&
                   (*(uint *)(glContext + 0x318) & 0xfffffffd) == 0) && dirtyWord3ThenMasked == 0) &&
                  *(int *)(glContext + 800) == 0;
        }
        if (!stateClean) {
          if (*(char *)(glContext + 0x85a8) == *(char *)(glContext + 0x85a6)) {
            dispatchFlags = (**(code **)(glContext + 0x4788))
                              (*(undefined4 *)(glContext + 0x4688),glContext + 0x4698,dirtyFlagWords);
            if ((((dispatchFlags & 3) != (uint)*(byte *)(glContext + 0x7580)) ||
                ((dispatchFlags & 4) != (uint)*(byte *)(glContext + 0x7581))) ||
               ((dispatchFlags & 8) != (uint)(*(char *)(glContext + 0x759d) == '\0'))) {
              if ((dispatchFlags & 4) == 0) {
                dispatchFlags = dispatchFlags & 0xfffffffe;
                *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x10000000;
              }
              _gleUpdateDispatchCodeChange(glContext,dispatchFlags);
              if (*(char *)(glContext + 0x759d) == '\0') {
                if (*(int *)(glContext + 0x7574) != 0) {
                  return;
                }
                glErrorCode = 0x506;
                goto LAB_00080860;
              }
            }
          }
          else {
            _gleSwitchToNonRevertRenderer(glContext);
          }
          remaining = 0x13;
          do {
            *dirtyFlagWords = 0;
            dirtyFlagWords = dirtyFlagWords + 1;
            remaining = remaining + -1;
          } while (remaining != 0);
        }
      }
    }
    ((void (*)())_gleSetRasterPos)(glContext,(double)(float)((double)CONCAT44(0x43300000,x ^ 0x80000000) -
                                            DOUBLE_00108d58),
                     (double)(float)((double)CONCAT44(0x43300000,y ^ 0x80000000) -
                                    DOUBLE_00108d58),(double)FLOAT_00108e50,(double)FLOAT_00108e54);
  }
  else {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
LAB_00080860:
    *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  }
  return;
}

/* _glRasterPos2s_CompExec @ 0x808f0 (64 bytes) */
void _glRasterPos2s_CompExec(glContext, x, y)
  undefined4 glContext;
  undefined4 x;
  undefined4 y;
{
  double fparam_1;
  double incomingFpr2;
  double incomingFpr3;
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  
  ((void (*)())_glRasterPos2s_Comp)(glContext,x,y);
  ((void (*)())_glRasterPos2s_Exec)(glContext,x,y,fparam_1,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8);
  return;
}

/* _glRasterPos2sv_Comp @ 0x80930 (128 bytes) */
void _glRasterPos2sv_Comp(glContext, v)
  undefined4 glContext;
  short *v;
{
  ((void (*)())_glSetRasterPos_Comp)(glContext,(double)(float)((double)CONCAT44(0x43300000,(int)*v ^ 0x80000000) -
                                    DOUBLE_00108d58),
             (double)(float)((double)CONCAT44(0x43300000,(int)v[1] ^ 0x80000000) -
                            DOUBLE_00108d58),(double)FLOAT_00108e50,(double)FLOAT_00108e54);
  return;
}

