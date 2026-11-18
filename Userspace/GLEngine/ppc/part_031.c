#include "decls.h"

/* _glCopyTexSubImage1D_Exec @ 0x97d38 (1428 bytes) */
void _glCopyTexSubImage1D_Exec(int glContext,undefined4 target,uint level,undefined4 xoffset,undefined4 x,undefined4 y,int width,double fparam_1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
{
  bool bVar1;
  char cVar2;
  undefined4 uVar3;
  undefined4 glErrorCode;
  int *srcCursor;
  int iVar5;
  int iVar6;
  int framebufferObject;
  undefined4 uVar7;
  undefined4 uVar8;
  int iVar9;
  int remaining;
  int loopIndex;
  uint uVar10;
  byte bVar11;
  int iVar12;
  int *piVar13;
  double extraout_f1;
  
  if ((*(int *)(glContext + 0x744c) != 0) || (*(int *)(glContext + 0x310) < 0)) {
    iVar9 = *(int *)(glContext + 0x50ac);
    uVar10 = level;
    uVar3 = xoffset;
    uVar7 = x;
    uVar8 = y;
    if (iVar9 != 0 || (*(uint *)(glContext + 0x505c) & *(uint *)(glContext + 0x50b0)) != 0) {
      _gleUpdateMatrixFunc(glContext);
      fparam_1 = extraout_f1;
    }
    if (*(char *)(glContext + 0x4691) != '\0') {
      framebufferObject = *(int *)(glContext + 0x744c);
      piVar13 = (int *)(glContext + 0x310);
      cVar2 = *(char *)(*(int *)(glContext + 0x468c) + 0x79);
      if ((framebufferObject != 0) && (*(int *)(framebufferObject + 0xec) != 0)) {
        ((void (*)())_gleUpdateFramebufferCompleteness)(glContext,framebufferObject + 0x10,uVar10,uVar3,uVar7,uVar8,iVar9,fparam_1,forwardedFloatArg2,forwardedFloatArg3,
                   forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
        *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x80000000;
      }
      if ((*(char *)(glContext + 0x4664) == '\0') && (*(int *)(glContext + 0x5430) == 0)) {
LAB_00097e7c:
        uVar10 = *(uint *)(glContext + 0x31c);
      }
      else {
        loopIndex = 0;
        srcCursor = (int *)(glContext + 0x324);
        do {
          iVar6 = *srcCursor;
          srcCursor = srcCursor + 1;
          if (iVar6 != 0) {
            *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x800000;
            break;
          }
          loopIndex = loopIndex + 1;
        } while (loopIndex < 9);
        uVar10 = *(uint *)(glContext + 0x31c);
        if ((uVar10 & 0x15555) != 0) {
          if (*(char *)(glContext + 0x2e54) != '\0') {
            _gleUpdateLightRGBASums(glContext,glContext + 0x2c20,0);
          }
          if (*(char *)(glContext + 0x3094) != '\0') {
            _gleUpdateLightRGBASums(glContext,glContext + 0x2e60,1);
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
        bVar1 = ((*piVar13 == 0 && *(int *)(glContext + 0x314) == 0) && uVar10 == 0) &&
                *(int *)(glContext + 800) == 0;
      }
      else {
        bVar1 = (((*piVar13 == 0 && *(int *)(glContext + 0x314) == 0) &&
                 (*(uint *)(glContext + 0x318) & 0xfffffffd) == 0) && uVar10 == 0) &&
                *(int *)(glContext + 800) == 0;
      }
      if (!bVar1) {
        if (*(char *)(glContext + 0x85a8) == *(char *)(glContext + 0x85a6)) {
          uVar10 = (**(code **)(glContext + 0x4788))
                             (*(undefined4 *)(glContext + 0x4688),glContext + 0x4698,piVar13);
          if ((((uVar10 & 3) != (uint)*(byte *)(glContext + 0x7580)) ||
              ((uVar10 & 4) != (uint)*(byte *)(glContext + 0x7581))) ||
             ((uVar10 & 8) != (uint)(*(char *)(glContext + 0x759d) == '\0'))) {
            if ((uVar10 & 4) == 0) {
              uVar10 = uVar10 & 0xfffffffe;
              *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x10000000;
            }
            _gleUpdateDispatchCodeChange(glContext,uVar10);
            if (*(char *)(glContext + 0x759d) == '\0') {
              if (*(int *)(glContext + 0x7574) != 0) {
                return;
              }
              glErrorCode = 0x506;
              goto LAB_00097fbc;
            }
          }
        }
        else {
          _gleSwitchToNonRevertRenderer(glContext);
        }
        remaining = 0x13;
        do {
          *piVar13 = 0;
          piVar13 = piVar13 + 1;
          remaining = remaining + -1;
        } while (remaining != 0);
      }
    }
  }
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (width == 0) {
      return;
    }
    iVar9 = _gleCheckCopyTexSubImage1DArgs(glContext,target,level,xoffset,width);
    if (iVar9 == 0) {
      return;
    }
    iVar6 = iVar9 + level * 0x18;
    iVar12 = iVar6 + 0xc4;
    if ((((int)level < (int)(uint)*(byte *)(iVar9 + 0x8d)) ||
        ((int)(uint)*(byte *)(iVar9 + 0x8f) < (int)level)) ||
       (((*(ushort *)(iVar9 + 0x94) >> (level & 0x3f) & 1) == 0 ||
        (iVar5 = (**(code **)(glContext + 0x470c))
                           (*(undefined4 *)(glContext + 0x4688),
                            *(undefined4 *)(iVar9 + (uint)*(byte *)(glContext + 0x85a8) * 4),0,level
                            ,xoffset,0,0,x), iVar5 == 0)))) {
      bVar11 = *(byte *)(iVar6 + 0xcf);
      if ((bVar11 & 0x10) == 0) {
        if ((bVar11 & 0x40) == 0) {
          if (*(int *)(iVar6 + 0xd8) == 0) {
            _gleAllocateTextureLevel(glContext,iVar9,iVar12);
            bVar11 = *(byte *)(iVar6 + 0xcf);
          }
          *(byte *)(iVar6 + 0xcf) = bVar11 | 0x10;
        }
        else {
          _gleUploadPluginTextureLevel
                    (glContext,iVar9,iVar12,0,level,(uint)*(byte *)(glContext + 0x85a8));
        }
      }
      _gleModifyPluginTextureLevel(glContext,iVar9,iVar12,0,level,xoffset,0,0,width,1,1);
      _gleTextureSubImageCopy(glContext,iVar12,xoffset,0,0,x,y,width,1);
      if ((((*(uint *)(iVar9 + 0x6c) & 0x8000) != 0) && ((int)*(short *)(iVar9 + 0x60) == level))
         && (iVar9 = _gleGenMipmapsToLevel(glContext,iVar9,0,level,0xf,1), iVar9 != 0)) {
        return;
      }
      *(uint *)(glContext + 0x314) =
           *(uint *)(glContext + 0x314) | 1 << (*(uint *)(glContext + 0x53d4) & 0x3f);
      return;
    }
    *(undefined4 *)(iVar9 + 0x20) =
         *(undefined4 *)
          ((uint)*(byte *)(glContext + 0x85a8) * 4 + *(int *)(glContext + 0x5148) + 0x8054);
    if (*(int *)(iVar6 + 0xd8) != 0) {
      bVar11 = *(byte *)(iVar6 + 0xcf);
      if (((bVar11 & 1) == 0) && (*(short *)(iVar9 + 0x3e) == -0x7a43)) {
        _gleFreeTextureLevel(glContext,iVar9,iVar12);
        bVar11 = *(byte *)(iVar6 + 0xcf);
      }
      *(byte *)(iVar6 + 0xcf) = bVar11 & 0xef;
      *(ushort *)(iVar9 + 0xa0) =
           *(ushort *)(iVar9 + 0xa0) &
           ((ushort)(-2 << (level & 0x1f)) | (ushort)(0xfffffffe >> 0x20 - (level & 0x1f)));
    }
    *(byte *)(iVar6 + 0xcf) = *(byte *)(iVar6 + 0xcf) | 0x40;
    if ((*(uint *)(iVar9 + 0x6c) & 0x8000) == 0) {
      return;
    }
    if ((int)*(short *)(iVar9 + 0x60) != level) {
      return;
    }
    uVar10 = level + 1;
    if ((int)(uint)*(byte *)(iVar9 + 0x83) < (int)uVar10) {
      return;
    }
    iVar6 = uVar10 * 0x18 + iVar9 + 0xc4;
    do {
      if (*(int *)(iVar6 + 0x14) != 0) {
        if (((*(byte *)(iVar6 + 0xb) & 1) == 0) && (*(short *)(iVar9 + 0x3e) == -0x7a43)) {
          _gleFreeTextureLevel(glContext,iVar9,iVar6);
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
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  glErrorCode = 0x502;
LAB_00097fbc:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glCopyTexSubImage1D_CompExec @ 0x982cc (96 bytes) */
void _glCopyTexSubImage1D_CompExec(glContext, target, level, xoffset, x, y, width)
  undefined4 glContext;
  undefined4 target;
  undefined4 level;
  undefined4 xoffset;
  undefined4 x;
  undefined4 y;
  undefined4 width;
{
  double fparam_1;
  double in_f2;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  
  _glCopyTexSubImage1D_Comp(glContext,target,level,xoffset,x,y,width);
  ((void (*)())_glCopyTexSubImage1D_Exec)(glContext,target,level,xoffset,x,y,width,fparam_1,in_f2,in_f3,in_f4,
             in_f5,in_f6,in_f7,in_f8);
  return;
}

/* _glCopyTexSubImage1D_NoopExec @ 0x9832c (680 bytes) */
void _glCopyTexSubImage1D_NoopExec(int glContext,undefined4 forwardedArg2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,undefined4 param_7,double fparam_1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
{
  bool bVar1;
  char cVar2;
  int iVar3;
  int *srcCursor;
  int framebufferObject;
  int remaining;
  int loopIndex;
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
  if (*(int *)(glContext + 0x50ac) != 0 ||
      (*(uint *)(glContext + 0x505c) & *(uint *)(glContext + 0x50b0)) != 0) {
    _gleUpdateMatrixFunc(glContext);
    fparam_1 = extraout_f1;
  }
  if (*(char *)(glContext + 0x4691) != '\0') {
    framebufferObject = *(int *)(glContext + 0x744c);
    piVar12 = (int *)(glContext + 0x310);
    cVar2 = *(char *)(*(int *)(glContext + 0x468c) + 0x79);
    if ((framebufferObject != 0) && (*(int *)(framebufferObject + 0xec) != 0)) {
      ((void (*)())_gleUpdateFramebufferCompleteness)(glContext,framebufferObject + 0x10,uVar6,uVar7,uVar8,uVar9,uVar10,fparam_1,forwardedFloatArg2,forwardedFloatArg3,
                 forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
      *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x80000000;
      fparam_1 = fparam_1;
    }
    if ((*(char *)(glContext + 0x4664) == '\0') && (*(int *)(glContext + 0x5430) == 0)) {
LAB_00098458:
      uVar11 = *(uint *)(glContext + 0x31c);
    }
    else {
      loopIndex = 0;
      srcCursor = (int *)(glContext + 0x324);
      do {
        iVar3 = *srcCursor;
        srcCursor = srcCursor + 1;
        if (iVar3 != 0) {
          *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x800000;
          break;
        }
        loopIndex = loopIndex + 1;
      } while (loopIndex < 9);
      uVar11 = *(uint *)(glContext + 0x31c);
      if ((uVar11 & 0x15555) != 0) {
        if (*(char *)(glContext + 0x2e54) != '\0') {
          fparam_1 = (double)_gleUpdateLightRGBASums(glContext,glContext + 0x2c20,0);
        }
        if (*(char *)(glContext + 0x3094) != '\0') {
          fparam_1 = (double)_gleUpdateLightRGBASums(glContext,glContext + 0x2e60,1);
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
      bVar1 = ((*piVar12 == 0 && *(int *)(glContext + 0x314) == 0) && uVar11 == 0) &&
              *(int *)(glContext + 800) == 0;
    }
    else {
      bVar1 = (((*piVar12 == 0 && *(int *)(glContext + 0x314) == 0) &&
               (*(uint *)(glContext + 0x318) & 0xfffffffd) == 0) && uVar11 == 0) &&
              *(int *)(glContext + 800) == 0;
    }
    if (!bVar1) {
      if (*(char *)(glContext + 0x85a8) == *(char *)(glContext + 0x85a6)) {
        uVar11 = (**(code **)(glContext + 0x4788))
                           (*(undefined4 *)(glContext + 0x4688),glContext + 0x4698,piVar12);
        if ((((uVar11 & 3) != (uint)*(byte *)(glContext + 0x7580)) ||
            ((uVar11 & 4) != (uint)*(byte *)(glContext + 0x7581))) ||
           (fparam_1 = extraout_f1_01, (uVar11 & 8) != (uint)(*(char *)(glContext + 0x759d) == '\0')))
        {
          if ((uVar11 & 4) == 0) {
            uVar11 = uVar11 & 0xfffffffe;
            *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x10000000;
          }
          fparam_1 = (double)_gleUpdateDispatchCodeChange(glContext,uVar11);
          if (*(char *)(glContext + 0x759d) == '\0') goto LAB_00098578;
        }
      }
      else {
        fparam_1 = (double)_gleSwitchToNonRevertRenderer(glContext);
      }
      remaining = 0x13;
      do {
        *piVar12 = 0;
        piVar12 = piVar12 + 1;
        remaining = remaining + -1;
      } while (remaining != 0);
    }
  }
  if (*(char *)(glContext + 0x759d) != '\0') {
    ((void (*)())_glCopyTexSubImage1D_Exec)(glContext,forwardedArg2,param_3,param_4,param_5,param_6,param_7,fparam_1,forwardedFloatArg2,forwardedFloatArg3,
               forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
    return;
  }
LAB_00098578:
  if (*(int *)(glContext + 0x7574) == 0) {
    *(undefined4 *)(glContext + 0x7574) = 0x506;
  }
  return;
}

/* _glCopyTexSubImage2D_ListExec @ 0x985d4 (76 bytes) */
undefined4 _glCopyTexSubImage2D_ListExec(undefined4 glContext,undefined4 *listRecord,double forwardedFloatArg1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
{
  ((void (*)())_glCopyTexSubImage2D_Exec)(glContext,*listRecord,listRecord[1],listRecord[2],listRecord[3],listRecord[4],listRecord[5],listRecord[6],
             listRecord[7],forwardedFloatArg1,forwardedFloatArg2,forwardedFloatArg3,forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
  return 0x20;
}

/* _glCopyTexSubImage2D_Comp @ 0x98620 (132 bytes) */
int _glCopyTexSubImage2D_Comp(glContext, target, level, xoffset, yoffset, x, y, width, height)
  undefined4 glContext;
  undefined4 target;
  undefined4 level;
  undefined4 xoffset;
  undefined4 yoffset;
  undefined4 x;
  undefined4 y;
  undefined4 width;
  undefined4 height;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glCopyTexSubImage2D_ListExec_001103c8,0x20);
  if (listRecord != (undefined4 *)0x0) {
    *listRecord = target;
    listRecord[7] = height;
    listRecord[1] = level;
    listRecord[2] = xoffset;
    listRecord[3] = yoffset;
    listRecord[4] = x;
    listRecord[5] = y;
    listRecord[6] = width;
  }
  return listRecord;
}

/* _glCopyTexSubImage2D_Exec @ 0x986a4 (1508 bytes) */
void _glCopyTexSubImage2D_Exec(int glContext,int target,uint level,undefined4 xoffset,undefined4 yoffset,undefined4 x,undefined4 y,int width,int height,double fparam_1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
{
  bool bVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 glErrorCode;
  int *srcCursor;
  int iVar6;
  int iVar7;
  int framebufferObject;
  undefined4 uVar8;
  undefined4 uVar9;
  int iVar10;
  int remaining;
  int loopIndex;
  uint uVar11;
  byte bVar12;
  uint uVar13;
  int *piVar14;
  int iVar15;
  double extraout_f1;
  
  if ((*(int *)(glContext + 0x744c) != 0) || (*(int *)(glContext + 0x310) < 0)) {
    iVar10 = *(int *)(glContext + 0x50ac);
    uVar11 = level;
    uVar4 = xoffset;
    uVar8 = yoffset;
    uVar9 = x;
    if (iVar10 != 0 || (*(uint *)(glContext + 0x505c) & *(uint *)(glContext + 0x50b0)) != 0) {
      _gleUpdateMatrixFunc(glContext);
      fparam_1 = extraout_f1;
    }
    if (*(char *)(glContext + 0x4691) != '\0') {
      framebufferObject = *(int *)(glContext + 0x744c);
      piVar14 = (int *)(glContext + 0x310);
      cVar2 = *(char *)(*(int *)(glContext + 0x468c) + 0x79);
      if ((framebufferObject != 0) && (*(int *)(framebufferObject + 0xec) != 0)) {
        ((void (*)())_gleUpdateFramebufferCompleteness)(glContext,framebufferObject + 0x10,uVar11,uVar4,uVar8,uVar9,iVar10,fparam_1,forwardedFloatArg2,forwardedFloatArg3,
                   forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
        *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x80000000;
      }
      if ((*(char *)(glContext + 0x4664) == '\0') && (*(int *)(glContext + 0x5430) == 0)) {
LAB_000987f0:
        uVar11 = *(uint *)(glContext + 0x31c);
      }
      else {
        loopIndex = 0;
        srcCursor = (int *)(glContext + 0x324);
        do {
          iVar7 = *srcCursor;
          srcCursor = srcCursor + 1;
          if (iVar7 != 0) {
            *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x800000;
            break;
          }
          loopIndex = loopIndex + 1;
        } while (loopIndex < 9);
        uVar11 = *(uint *)(glContext + 0x31c);
        if ((uVar11 & 0x15555) != 0) {
          if (*(char *)(glContext + 0x2e54) != '\0') {
            _gleUpdateLightRGBASums(glContext,glContext + 0x2c20,0);
          }
          if (*(char *)(glContext + 0x3094) != '\0') {
            _gleUpdateLightRGBASums(glContext,glContext + 0x2e60,1);
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
        bVar1 = ((*piVar14 == 0 && *(int *)(glContext + 0x314) == 0) && uVar11 == 0) &&
                *(int *)(glContext + 800) == 0;
      }
      else {
        bVar1 = (((*piVar14 == 0 && *(int *)(glContext + 0x314) == 0) &&
                 (*(uint *)(glContext + 0x318) & 0xfffffffd) == 0) && uVar11 == 0) &&
                *(int *)(glContext + 800) == 0;
      }
      if (!bVar1) {
        if (*(char *)(glContext + 0x85a8) == *(char *)(glContext + 0x85a6)) {
          uVar11 = (**(code **)(glContext + 0x4788))
                             (*(undefined4 *)(glContext + 0x4688),glContext + 0x4698,piVar14);
          if ((((uVar11 & 3) != (uint)*(byte *)(glContext + 0x7580)) ||
              ((uVar11 & 4) != (uint)*(byte *)(glContext + 0x7581))) ||
             ((uVar11 & 8) != (uint)(*(char *)(glContext + 0x759d) == '\0'))) {
            if ((uVar11 & 4) == 0) {
              uVar11 = uVar11 & 0xfffffffe;
              *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x10000000;
            }
            _gleUpdateDispatchCodeChange(glContext,uVar11);
            if (*(char *)(glContext + 0x759d) == '\0') {
              if (*(int *)(glContext + 0x7574) != 0) {
                return;
              }
              glErrorCode = 0x506;
              goto LAB_00098930;
            }
          }
        }
        else {
          _gleSwitchToNonRevertRenderer(glContext);
        }
        remaining = 0x13;
        do {
          *piVar14 = 0;
          piVar14 = piVar14 + 1;
          remaining = remaining + -1;
        } while (remaining != 0);
      }
    }
  }
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (width == 0) {
      return;
    }
    if (height == 0) {
      return;
    }
    iVar10 = _gleCheckCopyTexSubImage2DArgs(glContext,target,level,xoffset,yoffset,width,height)
    ;
    if (iVar10 == 0) {
      return;
    }
    uVar11 = target - 0x8515;
    if (5 < uVar11) {
      uVar11 = 0;
    }
    iVar7 = iVar10 + uVar11 * 0x168 + level * 0x18;
    iVar15 = iVar7 + 0xc4;
    if ((((int)(uint)*(byte *)(iVar10 + 0x8d) <= (int)level) &&
        ((int)level <= (int)(uint)*(byte *)(iVar10 + 0x8f))) &&
       ((iVar3 = uVar11 * 2, (*(ushort *)(iVar3 + iVar10 + 0x94) >> (level & 0x3f) & 1) != 0 &&
        (iVar6 = (**(code **)(glContext + 0x470c))
                           (*(undefined4 *)(glContext + 0x4688),
                            *(undefined4 *)(iVar10 + (uint)*(byte *)(glContext + 0x85a8) * 4),uVar11,
                            level,xoffset,yoffset,0,x), iVar6 != 0)))) {
      *(undefined4 *)(iVar10 + 0x20) =
           *(undefined4 *)
            ((uint)*(byte *)(glContext + 0x85a8) * 4 + *(int *)(glContext + 0x5148) + 0x8054);
      if (*(int *)(iVar7 + 0xd8) != 0) {
        bVar12 = *(byte *)(iVar7 + 0xcf);
        if (((bVar12 & 1) == 0) && (*(short *)(iVar10 + 0x3e) == -0x7a43)) {
          _gleFreeTextureLevel(glContext,iVar10,iVar15);
          bVar12 = *(byte *)(iVar7 + 0xcf);
        }
        *(byte *)(iVar7 + 0xcf) = bVar12 & 0xef;
        *(ushort *)(iVar3 + iVar10 + 0xa0) =
             *(ushort *)(iVar3 + iVar10 + 0xa0) &
             ((ushort)(-2 << (level & 0x1f)) | (ushort)(0xfffffffe >> 0x20 - (level & 0x1f)));
      }
      *(byte *)(iVar7 + 0xcf) = *(byte *)(iVar7 + 0xcf) | 0x40;
      if ((*(uint *)(iVar10 + 0x6c) & 0x8000) == 0) {
        return;
      }
      if ((int)*(short *)(iVar10 + 0x60) != level) {
        return;
      }
      uVar13 = level + 1;
      if ((int)(uint)*(byte *)(iVar10 + 0x83) < (int)uVar13) {
        return;
      }
      iVar7 = uVar13 * 0x18 + uVar11 * 0x168 + iVar10 + 0xc4;
      do {
        if (*(int *)(iVar7 + 0x14) != 0) {
          if (((*(byte *)(iVar7 + 0xb) & 1) == 0) && (*(short *)(iVar10 + 0x3e) == -0x7a43)) {
            _gleFreeTextureLevel(glContext,iVar10,iVar7);
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
          _gleAllocateTextureLevel(glContext,iVar10,iVar15);
          bVar12 = *(byte *)(iVar7 + 0xcf);
        }
        *(byte *)(iVar7 + 0xcf) = bVar12 | 0x10;
      }
      else {
        _gleUploadPluginTextureLevel
                  (glContext,iVar10,iVar15,uVar11,level,(uint)*(byte *)(glContext + 0x85a8));
      }
    }
    _gleModifyPluginTextureLevel
              (glContext,iVar10,iVar15,uVar11,level,xoffset,yoffset,0,width,height,1);
    _gleTextureSubImageCopy(glContext,iVar15,xoffset,yoffset,0,x,y,width,height);
    if ((((*(uint *)(iVar10 + 0x6c) & 0x8000) != 0) && ((int)*(short *)(iVar10 + 0x60) == level))
       && (iVar10 = _gleGenMipmapsToLevel(glContext,iVar10,uVar11,level,0xf,1), iVar10 != 0)) {
      return;
    }
    *(uint *)(glContext + 0x314) =
         *(uint *)(glContext + 0x314) | 1 << (*(uint *)(glContext + 0x53d4) & 0x3f);
    return;
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  glErrorCode = 0x502;
LAB_00098930:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glCopyTexSubImage2D_CompExec @ 0x98c88 (116 bytes) */
void _glCopyTexSubImage2D_CompExec(glContext, target, level, xoffset, yoffset, x, y, width, height)
  undefined4 glContext;
  undefined4 target;
  undefined4 level;
  undefined4 xoffset;
  undefined4 yoffset;
  undefined4 x;
  undefined4 y;
  undefined4 width;
  undefined4 height;
{
  double fparam_1;
  double in_f2;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  
  ((int (*)())_glCopyTexSubImage2D_Comp)(glContext,target,level,xoffset,yoffset,x,y,width,height)
  ;
  ((void (*)())_glCopyTexSubImage2D_Exec)(glContext,target,level,xoffset,yoffset,x,y,width,height,fparam_1,in_f2,
             in_f3,in_f4,in_f5,in_f6,in_f7,in_f8);
  return;
}

/* _glCopyTexSubImage2D_NoopExec @ 0x98cfc (696 bytes) */
void _glCopyTexSubImage2D_NoopExec(int glContext,undefined4 forwardedArg2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 forwardedArg8,undefined4 forwardedArg9,double fparam_1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
{
  bool bVar1;
  char cVar2;
  int iVar3;
  int *srcCursor;
  int framebufferObject;
  int remaining;
  int loopIndex;
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
  if (*(int *)(glContext + 0x50ac) != 0 ||
      (*(uint *)(glContext + 0x505c) & *(uint *)(glContext + 0x50b0)) != 0) {
    _gleUpdateMatrixFunc(glContext);
    fparam_1 = extraout_f1;
  }
  if (*(char *)(glContext + 0x4691) != '\0') {
    framebufferObject = *(int *)(glContext + 0x744c);
    piVar12 = (int *)(glContext + 0x310);
    cVar2 = *(char *)(*(int *)(glContext + 0x468c) + 0x79);
    if ((framebufferObject != 0) && (*(int *)(framebufferObject + 0xec) != 0)) {
      ((void (*)())_gleUpdateFramebufferCompleteness)(glContext,framebufferObject + 0x10,uVar6,uVar7,uVar8,uVar9,uVar10,fparam_1,forwardedFloatArg2,forwardedFloatArg3,
                 forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
      *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x80000000;
      fparam_1 = fparam_1;
    }
    if ((*(char *)(glContext + 0x4664) == '\0') && (*(int *)(glContext + 0x5430) == 0)) {
LAB_00098e30:
      uVar11 = *(uint *)(glContext + 0x31c);
    }
    else {
      loopIndex = 0;
      srcCursor = (int *)(glContext + 0x324);
      do {
        iVar3 = *srcCursor;
        srcCursor = srcCursor + 1;
        if (iVar3 != 0) {
          *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x800000;
          break;
        }
        loopIndex = loopIndex + 1;
      } while (loopIndex < 9);
      uVar11 = *(uint *)(glContext + 0x31c);
      if ((uVar11 & 0x15555) != 0) {
        if (*(char *)(glContext + 0x2e54) != '\0') {
          fparam_1 = (double)_gleUpdateLightRGBASums(glContext,glContext + 0x2c20,0);
        }
        if (*(char *)(glContext + 0x3094) != '\0') {
          fparam_1 = (double)_gleUpdateLightRGBASums(glContext,glContext + 0x2e60,1);
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
      bVar1 = ((*piVar12 == 0 && *(int *)(glContext + 0x314) == 0) && uVar11 == 0) &&
              *(int *)(glContext + 800) == 0;
    }
    else {
      bVar1 = (((*piVar12 == 0 && *(int *)(glContext + 0x314) == 0) &&
               (*(uint *)(glContext + 0x318) & 0xfffffffd) == 0) && uVar11 == 0) &&
              *(int *)(glContext + 800) == 0;
    }
    if (!bVar1) {
      if (*(char *)(glContext + 0x85a8) == *(char *)(glContext + 0x85a6)) {
        uVar11 = (**(code **)(glContext + 0x4788))
                           (*(undefined4 *)(glContext + 0x4688),glContext + 0x4698,piVar12);
        if ((((uVar11 & 3) != (uint)*(byte *)(glContext + 0x7580)) ||
            ((uVar11 & 4) != (uint)*(byte *)(glContext + 0x7581))) ||
           (fparam_1 = extraout_f1_01, (uVar11 & 8) != (uint)(*(char *)(glContext + 0x759d) == '\0')))
        {
          if ((uVar11 & 4) == 0) {
            uVar11 = uVar11 & 0xfffffffe;
            *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x10000000;
          }
          fparam_1 = (double)_gleUpdateDispatchCodeChange(glContext,uVar11);
          if (*(char *)(glContext + 0x759d) == '\0') goto LAB_00098f50;
        }
      }
      else {
        fparam_1 = (double)_gleSwitchToNonRevertRenderer(glContext);
      }
      remaining = 0x13;
      do {
        *piVar12 = 0;
        piVar12 = piVar12 + 1;
        remaining = remaining + -1;
      } while (remaining != 0);
    }
  }
  if (*(char *)(glContext + 0x759d) != '\0') {
    ((void (*)())_glCopyTexSubImage2D_Exec)(glContext,forwardedArg2,param_3,param_4,param_5,param_6,param_7,forwardedArg8,forwardedArg9,fparam_1,
               forwardedFloatArg2,forwardedFloatArg3,forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
    return;
  }
LAB_00098f50:
  if (*(int *)(glContext + 0x7574) == 0) {
    *(undefined4 *)(glContext + 0x7574) = 0x506;
  }
  return;
}

/* _glCopyTexSubImage3D_ListExec @ 0x98fb4 (84 bytes) */
undefined4 _glCopyTexSubImage3D_ListExec(undefined4 glContext,undefined4 *listRecord,double forwardedFloatArg1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
{
  ((void (*)())_glCopyTexSubImage3D_Exec)(glContext,*listRecord,listRecord[1],listRecord[2],listRecord[3],listRecord[4],listRecord[5],listRecord[6],
             listRecord[7],listRecord[8],forwardedFloatArg1,forwardedFloatArg2,forwardedFloatArg3,forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,
             forwardedFloatArg8);
  return 0x24;
}

/* _glCopyTexSubImage3D_Comp @ 0x99008 (132 bytes) */
int _glCopyTexSubImage3D_Comp(glContext, target, level, xoffset, yoffset, zoffset, x, y, width, height)
  undefined4 glContext;
  undefined4 target;
  undefined4 level;
  undefined4 xoffset;
  undefined4 yoffset;
  undefined4 zoffset;
  undefined4 x;
  undefined4 y;
  undefined4 width;
  undefined4 height;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glCopyTexSubImage3D_ListExec_001103c4,0x24);
  if (listRecord != (undefined4 *)0x0) {
    *listRecord = target;
    listRecord[8] = height;
    listRecord[1] = level;
    listRecord[2] = xoffset;
    listRecord[3] = zoffset;
    listRecord[5] = x;
    listRecord[6] = y;
    listRecord[7] = width;
  }
  return listRecord;
}

/* _glCopyTexSubImage3D_Exec @ 0x9908c (1464 bytes) */
void _glCopyTexSubImage3D_Exec(int glContext,undefined4 target,uint level,undefined4 xoffset,undefined4 yoffset,undefined4 zoffset,undefined4 x,undefined4 y,int width,int height,double fparam_1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
{
  bool bVar1;
  char cVar2;
  undefined4 uVar3;
  undefined4 glErrorCode;
  int *srcCursor;
  int iVar5;
  int iVar6;
  int framebufferObject;
  undefined4 uVar7;
  undefined4 uVar8;
  int iVar9;
  int remaining;
  int loopIndex;
  uint uVar10;
  byte bVar11;
  int *piVar12;
  int iVar13;
  double extraout_f1;
  
  if ((*(int *)(glContext + 0x744c) != 0) || (*(int *)(glContext + 0x310) < 0)) {
    iVar9 = *(int *)(glContext + 0x50ac);
    uVar10 = level;
    uVar3 = xoffset;
    uVar7 = yoffset;
    uVar8 = zoffset;
    if (iVar9 != 0 || (*(uint *)(glContext + 0x505c) & *(uint *)(glContext + 0x50b0)) != 0) {
      _gleUpdateMatrixFunc(glContext);
      fparam_1 = extraout_f1;
    }
    if (*(char *)(glContext + 0x4691) != '\0') {
      framebufferObject = *(int *)(glContext + 0x744c);
      piVar12 = (int *)(glContext + 0x310);
      cVar2 = *(char *)(*(int *)(glContext + 0x468c) + 0x79);
      if ((framebufferObject != 0) && (*(int *)(framebufferObject + 0xec) != 0)) {
        ((void (*)())_gleUpdateFramebufferCompleteness)(glContext,framebufferObject + 0x10,uVar10,uVar3,uVar7,uVar8,iVar9,fparam_1,forwardedFloatArg2,forwardedFloatArg3,
                   forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
        *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x80000000;
      }
      if ((*(char *)(glContext + 0x4664) == '\0') && (*(int *)(glContext + 0x5430) == 0)) {
LAB_000991dc:
        uVar10 = *(uint *)(glContext + 0x31c);
      }
      else {
        loopIndex = 0;
        srcCursor = (int *)(glContext + 0x324);
        do {
          iVar6 = *srcCursor;
          srcCursor = srcCursor + 1;
          if (iVar6 != 0) {
            *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x800000;
            break;
          }
          loopIndex = loopIndex + 1;
        } while (loopIndex < 9);
        uVar10 = *(uint *)(glContext + 0x31c);
        if ((uVar10 & 0x15555) != 0) {
          if (*(char *)(glContext + 0x2e54) != '\0') {
            _gleUpdateLightRGBASums(glContext,glContext + 0x2c20,0);
          }
          if (*(char *)(glContext + 0x3094) != '\0') {
            _gleUpdateLightRGBASums(glContext,glContext + 0x2e60,1);
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
        bVar1 = ((*piVar12 == 0 && *(int *)(glContext + 0x314) == 0) && uVar10 == 0) &&
                *(int *)(glContext + 800) == 0;
      }
      else {
        bVar1 = (((*piVar12 == 0 && *(int *)(glContext + 0x314) == 0) &&
                 (*(uint *)(glContext + 0x318) & 0xfffffffd) == 0) && uVar10 == 0) &&
                *(int *)(glContext + 800) == 0;
      }
      if (!bVar1) {
        if (*(char *)(glContext + 0x85a8) == *(char *)(glContext + 0x85a6)) {
          uVar10 = (**(code **)(glContext + 0x4788))
                             (*(undefined4 *)(glContext + 0x4688),glContext + 0x4698,piVar12);
          if ((((uVar10 & 3) != (uint)*(byte *)(glContext + 0x7580)) ||
              ((uVar10 & 4) != (uint)*(byte *)(glContext + 0x7581))) ||
             ((uVar10 & 8) != (uint)(*(char *)(glContext + 0x759d) == '\0'))) {
            if ((uVar10 & 4) == 0) {
              uVar10 = uVar10 & 0xfffffffe;
              *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x10000000;
            }
            _gleUpdateDispatchCodeChange(glContext,uVar10);
            if (*(char *)(glContext + 0x759d) == '\0') {
              if (*(int *)(glContext + 0x7574) != 0) {
                return;
              }
              glErrorCode = 0x506;
              goto LAB_0009931c;
            }
          }
        }
        else {
          _gleSwitchToNonRevertRenderer(glContext);
        }
        remaining = 0x13;
        do {
          *piVar12 = 0;
          piVar12 = piVar12 + 1;
          remaining = remaining + -1;
        } while (remaining != 0);
      }
    }
  }
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (width == 0) {
      return;
    }
    if (height == 0) {
      return;
    }
    iVar9 = _gleCheckCopyTexSubImage3DArgs
                      (glContext,target,level,xoffset,yoffset,zoffset,width,height,1);
    if (iVar9 == 0) {
      return;
    }
    iVar6 = iVar9 + level * 0x18;
    iVar13 = iVar6 + 0xc4;
    if ((((int)(uint)*(byte *)(iVar9 + 0x8d) <= (int)level) &&
        ((int)level <= (int)(uint)*(byte *)(iVar9 + 0x8f))) &&
       (((*(ushort *)(iVar9 + 0x94) >> (level & 0x3f) & 1) != 0 &&
        (iVar5 = (**(code **)(glContext + 0x470c))
                           (*(undefined4 *)(glContext + 0x4688),
                            *(undefined4 *)(iVar9 + (uint)*(byte *)(glContext + 0x85a8) * 4),0,level
                            ,xoffset,yoffset,zoffset,x), iVar5 != 0)))) {
      *(undefined4 *)(iVar9 + 0x20) =
           *(undefined4 *)
            ((uint)*(byte *)(glContext + 0x85a8) * 4 + *(int *)(glContext + 0x5148) + 0x8054);
      if (*(int *)(iVar6 + 0xd8) != 0) {
        bVar11 = *(byte *)(iVar6 + 0xcf);
        if (((bVar11 & 1) == 0) && (*(short *)(iVar9 + 0x3e) == -0x7a43)) {
          _gleFreeTextureLevel(glContext,iVar9,iVar13);
          bVar11 = *(byte *)(iVar6 + 0xcf);
        }
        *(byte *)(iVar6 + 0xcf) = bVar11 & 0xef;
        *(ushort *)(iVar9 + 0xa0) =
             *(ushort *)(iVar9 + 0xa0) &
             ((ushort)(-2 << (level & 0x1f)) | (ushort)(0xfffffffe >> 0x20 - (level & 0x1f)));
      }
      *(byte *)(iVar6 + 0xcf) = *(byte *)(iVar6 + 0xcf) | 0x40;
      if ((*(uint *)(iVar9 + 0x6c) & 0x8000) == 0) {
        return;
      }
      if ((int)*(short *)(iVar9 + 0x60) != level) {
        return;
      }
      uVar10 = level + 1;
      if ((int)(uint)*(byte *)(iVar9 + 0x83) < (int)uVar10) {
        return;
      }
      iVar6 = uVar10 * 0x18 + iVar9 + 0xc4;
      do {
        if (*(int *)(iVar6 + 0x14) != 0) {
          if (((*(byte *)(iVar6 + 0xb) & 1) == 0) && (*(short *)(iVar9 + 0x3e) == -0x7a43)) {
            _gleFreeTextureLevel(glContext,iVar9,iVar6);
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
          _gleAllocateTextureLevel(glContext,iVar9,iVar13);
          bVar11 = *(byte *)(iVar6 + 0xcf);
        }
        *(byte *)(iVar6 + 0xcf) = bVar11 | 0x10;
      }
      else {
        _gleUploadPluginTextureLevel
                  (glContext,iVar9,iVar13,0,level,(uint)*(byte *)(glContext + 0x85a8));
      }
    }
    _gleModifyPluginTextureLevel
              (glContext,iVar9,iVar13,0,level,xoffset,yoffset,zoffset,width,height,1);
    _gleTextureSubImageCopy(glContext,iVar13,xoffset,yoffset,zoffset,x,y,width,height)
    ;
    if ((((*(uint *)(iVar9 + 0x6c) & 0x8000) != 0) && ((int)*(short *)(iVar9 + 0x60) == level)) &&
       (iVar9 = _gleGenMipmapsToLevel(glContext,iVar9,0,level,0xf,1), iVar9 != 0)) {
      return;
    }
    *(uint *)(glContext + 0x314) =
         *(uint *)(glContext + 0x314) | 1 << (*(uint *)(glContext + 0x53d4) & 0x3f);
    return;
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  glErrorCode = 0x502;
LAB_0009931c:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glCopyTexSubImage3D_CompExec @ 0x99644 (128 bytes) */
void _glCopyTexSubImage3D_CompExec(glContext, target, level, xoffset, yoffset, zoffset, x, y, width, height)
  undefined4 glContext;
  undefined4 target;
  undefined4 level;
  undefined4 xoffset;
  undefined4 yoffset;
  undefined4 zoffset;
  undefined4 x;
  undefined4 y;
  undefined4 width;
  undefined4 height;
{
  double fparam_1;
  double in_f2;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  
  ((int (*)())_glCopyTexSubImage3D_Comp)(glContext,target,level,xoffset,yoffset,zoffset,x,y,width,height);
  ((void (*)())_glCopyTexSubImage3D_Exec)(glContext,target,level,xoffset,yoffset,zoffset,x,y,width,height,
             fparam_1,in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8);
  return;
}

/* _glCopyTexSubImage3D_NoopExec @ 0x996c4 (704 bytes) */
void _glCopyTexSubImage3D_NoopExec(int glContext,undefined4 forwardedArg2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 forwardedArg8,undefined4 forwardedArg9,undefined4 forwardedArg10,double fparam_1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
{
  bool bVar1;
  char cVar2;
  int iVar3;
  int *srcCursor;
  int framebufferObject;
  int remaining;
  int loopIndex;
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
  if (*(int *)(glContext + 0x50ac) != 0 ||
      (*(uint *)(glContext + 0x505c) & *(uint *)(glContext + 0x50b0)) != 0) {
    _gleUpdateMatrixFunc(glContext);
    fparam_1 = extraout_f1;
  }
  if (*(char *)(glContext + 0x4691) != '\0') {
    framebufferObject = *(int *)(glContext + 0x744c);
    piVar12 = (int *)(glContext + 0x310);
    cVar2 = *(char *)(*(int *)(glContext + 0x468c) + 0x79);
    if ((framebufferObject != 0) && (*(int *)(framebufferObject + 0xec) != 0)) {
      ((void (*)())_gleUpdateFramebufferCompleteness)(glContext,framebufferObject + 0x10,uVar6,uVar7,uVar8,uVar9,uVar10,fparam_1,forwardedFloatArg2,forwardedFloatArg3,
                 forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
      *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x80000000;
      fparam_1 = fparam_1;
    }
    if ((*(char *)(glContext + 0x4664) == '\0') && (*(int *)(glContext + 0x5430) == 0)) {
LAB_000997fc:
      uVar11 = *(uint *)(glContext + 0x31c);
    }
    else {
      loopIndex = 0;
      srcCursor = (int *)(glContext + 0x324);
      do {
        iVar3 = *srcCursor;
        srcCursor = srcCursor + 1;
        if (iVar3 != 0) {
          *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x800000;
          break;
        }
        loopIndex = loopIndex + 1;
      } while (loopIndex < 9);
      uVar11 = *(uint *)(glContext + 0x31c);
      if ((uVar11 & 0x15555) != 0) {
        if (*(char *)(glContext + 0x2e54) != '\0') {
          fparam_1 = (double)_gleUpdateLightRGBASums(glContext,glContext + 0x2c20,0);
        }
        if (*(char *)(glContext + 0x3094) != '\0') {
          fparam_1 = (double)_gleUpdateLightRGBASums(glContext,glContext + 0x2e60,1);
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
      bVar1 = ((*piVar12 == 0 && *(int *)(glContext + 0x314) == 0) && uVar11 == 0) &&
              *(int *)(glContext + 800) == 0;
    }
    else {
      bVar1 = (((*piVar12 == 0 && *(int *)(glContext + 0x314) == 0) &&
               (*(uint *)(glContext + 0x318) & 0xfffffffd) == 0) && uVar11 == 0) &&
              *(int *)(glContext + 800) == 0;
    }
    if (!bVar1) {
      if (*(char *)(glContext + 0x85a8) == *(char *)(glContext + 0x85a6)) {
        uVar11 = (**(code **)(glContext + 0x4788))
                           (*(undefined4 *)(glContext + 0x4688),glContext + 0x4698,piVar12);
        if ((((uVar11 & 3) != (uint)*(byte *)(glContext + 0x7580)) ||
            ((uVar11 & 4) != (uint)*(byte *)(glContext + 0x7581))) ||
           (fparam_1 = extraout_f1_01, (uVar11 & 8) != (uint)(*(char *)(glContext + 0x759d) == '\0')))
        {
          if ((uVar11 & 4) == 0) {
            uVar11 = uVar11 & 0xfffffffe;
            *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x10000000;
          }
          fparam_1 = (double)_gleUpdateDispatchCodeChange(glContext,uVar11);
          if (*(char *)(glContext + 0x759d) == '\0') goto LAB_0009991c;
        }
      }
      else {
        fparam_1 = (double)_gleSwitchToNonRevertRenderer(glContext);
      }
      remaining = 0x13;
      do {
        *piVar12 = 0;
        piVar12 = piVar12 + 1;
        remaining = remaining + -1;
      } while (remaining != 0);
    }
  }
  if (*(char *)(glContext + 0x759d) != '\0') {
    ((void (*)())_glCopyTexSubImage3D_Exec)(glContext,forwardedArg2,param_3,param_4,param_5,param_6,param_7,forwardedArg8,forwardedArg9,forwardedArg10,
               fparam_1,forwardedFloatArg2,forwardedFloatArg3,forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
    return;
  }
LAB_0009991c:
  if (*(int *)(glContext + 0x7574) == 0) {
    *(undefined4 *)(glContext + 0x7574) = 0x506;
  }
  return;
}

/* _glTexEnvf_ListExec @ 0x99984 (52 bytes) */
int _glTexEnvf_ListExec(glContext, listRecord)
  undefined4 glContext;
  undefined4 *listRecord;
{
  ((void (*)())_glTexEnvf_Exec)(glContext,*listRecord,listRecord[1],(double)GH_U2F((unsigned int)(listRecord[2])));
  return 0xc;
}

/* _glTexEnvf_Comp @ 0x999b8 (100 bytes) */
undefined4 * _glTexEnvf_Comp(undefined4 glContext,undefined4 target,undefined4 pname,float param)
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glTexEnvf_ListExec_001103dc,0xc);
  if (listRecord != (undefined4 *)0x0) {
    listRecord[2] = (float)param;
    *listRecord = target;
    listRecord[1] = pname;
  }
  return listRecord;
}

/* _CheckNVShaderOperation @ 0x99a1c (388 bytes) */
int _CheckNVShaderOperation(glContext, param_2)
  int glContext;
  uint param_2;
{
  bool bVar1;
  uint uVar2;
  
  if (0x86e7 < param_2) {
    if (param_2 < 0x86f1) {
      if (0x86ee < param_2) {
LAB_00099b80:
        if (*(uint *)(glContext + 0x53d4) < 3) {
          return 0x502;
        }
        return 0;
      }
      if (param_2 == 0x86ec) {
        uVar2 = *(uint *)(glContext + 0x53d4);
        if (uVar2 == 0) {
          return 0x502;
        }
LAB_00099b64:
        if (*(ushort *)(*(int *)(glContext + 0x468c) + 0xb4) - 1 <= uVar2) {
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
          uVar2 = *(uint *)(glContext + 0x53d4);
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
        if (*(uint *)(glContext + 0x53d4) < 2) {
          return 0x502;
        }
        return 0;
      }
      if (param_2 != 0x86e2) {
        return 0x500;
      }
LAB_00099b30:
      if (*(int *)(glContext + 0x53d4) == 0) {
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
void _glTexEnvf_CompExec(undefined4 glContext,undefined4 target,undefined4 pname,float param)
{
  ((undefined4 * (*)())_glTexEnvf_Comp)(glContext,target,pname,param);
  ((void (*)())_glTexEnvf_Exec)(glContext,target,pname,param);
  return;
}

/* _glTexEnvfv_ListExec @ 0x99bf0 (52 bytes) */
int _glTexEnvfv_ListExec(glContext, listRecord)
  undefined4 glContext;
  undefined4 *listRecord;
{
  _glTexEnvfv_Exec(glContext,*listRecord,listRecord[1],listRecord + 2);
  return 0x18;
}

/* _glTexEnvfv_Comp @ 0x99c24 (292 bytes) */
int _glTexEnvfv_Comp(glContext, target, pname, params)
  undefined4 glContext;
  int target;
  int pname;
  int *params;
{
  int *listRecord;
  
  if (((target != 0x2300) || (pname != 0x2201)) &&
     ((target != 0x86de || (1 < pname - 0x86e0U)))) {
    if ((target != 0x2300) || (pname != 0x86e5)) {
      listRecord = (int *)_gleAddListItem(glContext,PTR__glTexEnvfv_ListExec_001103d8,0x18);
      if (listRecord != (int *)0x0) {
        *listRecord = target;
        listRecord[1] = pname;
        listRecord[2] = *params;
      }
    }
    else {
      listRecord = (int *)_gleAddListItem(glContext,PTR__glTexEnviv_ListExec_001103d4,0x18);
      if (listRecord != (int *)0x0) {
        *listRecord = 0x2300;
        listRecord[1] = 0x86e5;
        listRecord[2] = *params;
        listRecord[3] = params[1];
        listRecord[4] = params[2];
      }
    }
  }
  else {
    listRecord = (int *)_gleAddListItem(glContext,PTR__glTexEnvfv_ListExec_001103d8,0x18);
    if (listRecord != (int *)0x0) {
      *listRecord = target;
      listRecord[1] = pname;
      listRecord[2] = *params;
      listRecord[3] = params[1];
      listRecord[4] = params[2];
      listRecord[5] = params[3];
    }
  }
  return listRecord;
}

/* _glTexEnvfv_CompExec @ 0x99d48 (72 bytes) */
void _glTexEnvfv_CompExec(glContext, target, pname, params)
  undefined4 glContext;
  undefined4 target;
  undefined4 pname;
  undefined4 params;
{
  ((int (*)())_glTexEnvfv_Comp)(glContext,target,pname,params);
  _glTexEnvfv_Exec(glContext,target,pname,params);
  return;
}

/* _glTexEnvi_ListExec @ 0x99d90 (52 bytes) */
int _glTexEnvi_ListExec(glContext, listRecord)
  undefined4 glContext;
  undefined4 *listRecord;
{
  _glTexEnvi_Exec(glContext,*listRecord,listRecord[1],listRecord[2]);
  return 0xc;
}

/* _glTexEnvi_Comp @ 0x99dc4 (92 bytes) */
int _glTexEnvi_Comp(glContext, target, pname, param)
  undefined4 glContext;
  undefined4 target;
  undefined4 pname;
  undefined4 param;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glTexEnvi_ListExec_001103d0,0xc);
  if (listRecord != (undefined4 *)0x0) {
    listRecord[2] = param;
    *listRecord = target;
    listRecord[1] = pname;
  }
  return listRecord;
}

/* _glTexEnvi_CompExec @ 0x99e20 (72 bytes) */
void _glTexEnvi_CompExec(glContext, target, pname, param)
  undefined4 glContext;
  undefined4 target;
  undefined4 pname;
  undefined4 param;
{
  ((int (*)())_glTexEnvi_Comp)(glContext,target,pname,param);
  _glTexEnvi_Exec(glContext,target,pname,param);
  return;
}

/* _glTexEnviv_ListExec @ 0x99e68 (52 bytes) */
int _glTexEnviv_ListExec(glContext, listRecord)
  undefined4 glContext;
  undefined4 *listRecord;
{
  ((void (*)())_glTexEnviv_Exec)(glContext,*listRecord,listRecord[1],listRecord + 2);
  return 0x18;
}

/* _glTexEnviv_Comp @ 0x99e9c (292 bytes) */
int _glTexEnviv_Comp(glContext, target, pname, params)
  undefined4 glContext;
  int target;
  int pname;
  int *params;
{
  int *listRecord;
  
  if (((target != 0x2300) || (pname != 0x2201)) &&
     ((target != 0x86de || (1 < pname - 0x86e0U)))) {
    if ((target != 0x2300) || (pname != 0x86e5)) {
      listRecord = (int *)_gleAddListItem(glContext,PTR__glTexEnviv_ListExec_001103d4,0x18);
      if (listRecord != (int *)0x0) {
        *listRecord = target;
        listRecord[1] = pname;
        listRecord[2] = *params;
      }
    }
    else {
      listRecord = (int *)_gleAddListItem(glContext,PTR__glTexEnviv_ListExec_001103d4,0x18);
      if (listRecord != (int *)0x0) {
        *listRecord = 0x2300;
        listRecord[1] = 0x86e5;
        listRecord[2] = *params;
        listRecord[3] = params[1];
        listRecord[4] = params[2];
      }
    }
  }
  else {
    listRecord = (int *)_gleAddListItem(glContext,PTR__glTexEnviv_ListExec_001103d4,0x18);
    if (listRecord != (int *)0x0) {
      *listRecord = target;
      listRecord[1] = pname;
      listRecord[2] = *params;
      listRecord[3] = params[1];
      listRecord[4] = params[2];
      listRecord[5] = params[3];
    }
  }
  return listRecord;
}

/* _glTexEnviv_Exec @ 0x99fc0 (3296 bytes) */
void _glTexEnviv_Exec(glContext, target, pname, params)
  int glContext;
  int target;
  uint pname;
  uint *params;
{
  bool bVar1;
  byte bVar2;
  float fVar3;
  double dVar4;
  float fVar5;
  undefined4 glErrorCode;
  int iVar7;
  uint uVar8;
  code *pcVar9;
  int loopIndex;
  int iVar11;
  int remaining;
  uint uVar12;
  
  fVar5 = FLOAT_00108e50;
  dVar4 = DOUBLE_00108d58;
  uVar12 = *(uint *)(glContext + 0x53d4);
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (target == 0x86de) {
      iVar7 = glContext + uVar12 * 0x7c;
      switch(pname) {
      case 0x86d9:
        if ((*params != 0x8536) && (*params != 0x8538)) goto switchD_0009a048_caseD_86da;
        *(short *)(iVar7 + 0x356c) = (short)*params;
        break;
      default:
switchD_0009a048_caseD_86da:
        if (*(int *)(glContext + 0x7574) != 0) {
          return;
        }
        glErrorCode = 0x500;
        goto LAB_0009acbc;
      case 0x86df:
        iVar11 = ((int (*)())_CheckNVShaderOperation)(glContext,*params);
        if (iVar11 != 0) {
          if (*(int *)(glContext + 0x7574) != 0) {
            return;
          }
          *(int *)(glContext + 0x7574) = iVar11;
          return;
        }
        *(short *)(iVar7 + 0x3564) = (short)*params;
        _gleUpdateTextureParams(glContext,uVar12);
        break;
      case 0x86e0:
        uVar8 = *params;
        remaining = 4;
        do {
          if (((uVar8 != 0x201) && (uVar8 != 0x206)) && (*(int *)(glContext + 0x7574) == 0)) {
            *(undefined4 *)(glContext + 0x7574) = 0x500;
            uVar8 = *params;
          }
          loopIndex = 0;
          remaining = remaining + -1;
        } while (remaining != 0);
        while( true ) {
          if ((uVar8 == 0x201) || (uVar8 == 0x206)) {
            *(short *)(loopIndex * 2 + iVar7 + 0x3570) = (short)*params;
          }
          loopIndex = loopIndex + 1;
          if (3 < loopIndex) break;
          uVar8 = *params;
        }
        break;
      case 0x86e1:
        *(float *)(iVar7 + 0x3588) =
             (float)((double)CONCAT44(0x43300000,*params ^ 0x80000000) - DOUBLE_00108d58);
        *(float *)(iVar7 + 0x358c) =
             (float)((double)CONCAT44(0x43300000,params[1] ^ 0x80000000) - dVar4);
        *(float *)(iVar7 + 0x3590) =
             (float)((double)CONCAT44(0x43300000,params[2] ^ 0x80000000) - dVar4);
        *(float *)(iVar7 + 0x3594) =
             (float)((double)CONCAT44(0x43300000,params[3] ^ 0x80000000) - dVar4);
        break;
      case 0x86e2:
        *(float *)(iVar7 + 0x3598) =
             (float)((double)CONCAT44(0x43300000,*params ^ 0x80000000) - DOUBLE_00108d58);
        break;
      case 0x86e3:
        *(float *)(iVar7 + 0x359c) =
             (float)((double)CONCAT44(0x43300000,*params ^ 0x80000000) - DOUBLE_00108d58);
        break;
      case 0x86e4:
        if (((int)*params < 0x84c0) ||
           ((int)(*(ushort *)(*(int *)(glContext + 0x468c) + 0xb4) + 0x84c0) <= (int)*params))
        goto switchD_0009a048_caseD_86da;
        *(short *)(iVar7 + 0x356a) = (short)*params;
        break;
      case 0x86e5:
        *(float *)(iVar7 + 0x357c) =
             (float)((double)CONCAT44(0x43300000,*params ^ 0x80000000) - DOUBLE_00108d58);
        *(float *)(iVar7 + 0x3580) =
             (float)((double)CONCAT44(0x43300000,params[1] ^ 0x80000000) - dVar4);
        *(float *)(iVar7 + 0x3584) =
             (float)((double)CONCAT44(0x43300000,params[2] ^ 0x80000000) - dVar4);
      }
      uVar8 = *(uint *)(glContext + 800);
      iVar7 = 1;
    }
    else {
      if (target == 0x8861) {
        if (pname == 0x8862) {
          if (*params == 0) {
            uVar12 = *(uint *)(glContext + 0x3444) &
                     (-2 << (uVar12 & 0x1f) | 0xfffffffeU >> 0x20 - (uVar12 & 0x1f));
          }
          else {
            uVar12 = *(uint *)(glContext + 0x3444) | 1 << (uVar12 & 0x3f);
          }
          *(uint *)(glContext + 0x3444) = uVar12;
          *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x400000;
          return;
        }
        goto switchD_0009a048_caseD_86da;
      }
      if (target != 0x2300) {
        if ((target == 0x8500) && (pname == 0x8501)) {
          *(float *)(uVar12 * 0x7c + glContext + 0x3560) =
               (float)((double)CONCAT44(0x43300000,*params ^ 0x80000000) - DOUBLE_00108d58);
          *(uint *)(glContext + 800) = *(uint *)(glContext + 800) | 0x10000 << (uVar12 & 0x3f);
          return;
        }
        goto switchD_0009a048_caseD_86da;
      }
      if (pname == 0x2200) {
        uVar8 = *params;
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
          *(short *)(uVar12 * 0x7c + glContext + 0x3538) = (short)*params;
          *(uint *)(glContext + 800) = *(uint *)(glContext + 800) | 1 << (uVar12 & 0x3f);
          return;
        }
        goto switchD_0009a048_caseD_86da;
      }
      if (pname == 0x2201) {
        iVar7 = glContext + uVar12 * 0x7c;
        fVar3 = (float)((double)CONCAT44(0x43300000,*params ^ 0x80000000) - DOUBLE_00108d58) *
                FLOAT_00108e68 + FLOAT_00108e6c;
        if (fVar3 < FLOAT_00108e50) {
          *(float *)(iVar7 + 0x3524) = FLOAT_00108e50;
        }
        else {
          *(float *)(iVar7 + 0x3524) = fVar3;
        }
        fVar3 = (float)((double)CONCAT44(0x43300000,params[1] ^ 0x80000000) - DOUBLE_00108d58) *
                FLOAT_00108e68 + FLOAT_00108e6c;
        if (fVar3 < fVar5) {
          *(float *)(iVar7 + 0x3528) = fVar5;
        }
        else {
          *(float *)(iVar7 + 0x3528) = fVar3;
        }
        fVar3 = (float)((double)CONCAT44(0x43300000,params[2] ^ 0x80000000) - DOUBLE_00108d58) *
                FLOAT_00108e68 + FLOAT_00108e6c;
        if (fVar3 < fVar5) {
          *(float *)(iVar7 + 0x352c) = fVar5;
        }
        else {
          *(float *)(iVar7 + 0x352c) = fVar3;
        }
        fVar3 = (float)((double)CONCAT44(0x43300000,params[3] ^ 0x80000000) - DOUBLE_00108d58) *
                FLOAT_00108e68 + FLOAT_00108e6c;
        if (fVar3 < fVar5) {
          *(float *)(iVar7 + 0x3530) = fVar5;
        }
        else {
          *(float *)(iVar7 + 0x3530) = fVar3;
        }
        if (*(int *)(glContext + 0x5434) == 0) {
          bVar2 = *(byte *)(uVar12 + *(int *)(glContext + 0x5420) + 0x30c);
        }
        else {
          bVar2 = *(byte *)(uVar12 + *(int *)(*(int *)(glContext + 0x5430) + 0x20) + 0x340);
        }
        iVar11 = (bVar2 >> 3 & 0x1c) + glContext;
        iVar7 = *(int *)(glContext + 0x5424);
        *(uint *)(iVar11 + 0x324) = *(uint *)(iVar11 + 0x324) | 1 << (bVar2 & 0x1f);
        bVar2 = *(byte *)(uVar12 + iVar7 + 0x30c);
        iVar7 = (bVar2 >> 3 & 0x1c) + glContext;
        *(uint *)(iVar7 + 0x348) = *(uint *)(iVar7 + 0x348) | 1 << (bVar2 & 0x1f);
        iVar7 = 0x100;
        uVar8 = *(uint *)(glContext + 800);
      }
      else {
        if (pname == 0x8588) {
          uVar8 = *params;
          if ((((uVar8 == 0x1702) || (uVar8 - 0x84c0 < 0x10)) || (uVar8 == 0x8576)) ||
             (((uVar8 == 0x8577 || (uVar8 == 0x8578)) || ((uVar8 == 0 || (uVar8 == 1)))))) {
            *(short *)(uVar12 * 0x7c + glContext + 0x3546) = (short)*params;
            goto LAB_0009ac28;
          }
          goto switchD_0009a048_caseD_86da;
        }
        if (pname < 0x8589) {
          if (pname == 0x8573) {
            uVar8 = *params;
            if ((uVar8 - 1 < 2) || (uVar8 == 4)) {
              *(float *)(uVar12 * 0x7c + glContext + 0x3558) =
                   (float)((double)CONCAT44(0x43300000,uVar8 ^ 0x80000000) - DOUBLE_00108d58);
            }
            else {
LAB_0009abe0:
              if (*(int *)(glContext + 0x7574) == 0) {
                *(undefined4 *)(glContext + 0x7574) = 0x500;
              }
            }
          }
          else {
            if (0x8573 < pname) {
              if (pname == 0x8581) {
                uVar8 = *params;
                if ((((uVar8 == 0x1702) || (uVar8 - 0x84c0 < 0x10)) || (uVar8 == 0x8576)) ||
                   (((uVar8 == 0x8577 || (uVar8 == 0x8578)) || ((uVar8 == 0 || (uVar8 == 1)))))) {
                  *(short *)(uVar12 * 0x7c + glContext + 0x3542) = (short)*params;
                  goto LAB_0009ac28;
                }
              }
              else if (pname < 0x8582) {
                if ((pname == 0x8580) &&
                   ((((uVar8 = *params, uVar8 == 0x1702 || (uVar8 - 0x84c0 < 0x10)) ||
                     ((uVar8 == 0x8576 || ((uVar8 == 0x8577 || (uVar8 == 0x8578)))))) ||
                    ((uVar8 == 0 || (uVar8 == 1)))))) {
                  *(short *)(uVar12 * 0x7c + glContext + 0x3540) = (short)*params;
                  goto LAB_0009ac28;
                }
              }
              else if ((pname == 0x8582) &&
                      (((uVar8 = *params, uVar8 == 0x1702 || (uVar8 - 0x84c0 < 0x10)) ||
                       ((uVar8 == 0x8576 ||
                        ((((uVar8 == 0x8577 || (uVar8 == 0x8578)) || (uVar8 == 0)) || (uVar8 == 1)))
                        ))))) {
                *(short *)(uVar12 * 0x7c + glContext + 0x3544) = (short)*params;
                goto LAB_0009ac28;
              }
              goto switchD_0009a048_caseD_86da;
            }
            if (pname == 0x8571) {
              pcVar9 = (code *)*params;
              if ((int)pcVar9 < 0x8576) {
                if (((int)pcVar9 < 0x8574) && (pcVar9 != (code *)0x1e01)) {
                  if ((int)pcVar9 < 0x1e02) {
                    bVar1 = pcVar9 == (code *)0x104;
                  }
                  else {
                    if (pcVar9 == (code *)0x2100) goto LAB_0009a770;
                    bVar1 = pcVar9 == (code *)0x84e7;
                  }
                  if (!bVar1) goto switchD_0009a048_caseD_86da;
                }
              }
              else if (((int)pcVar9 < 0x86ae) ||
                      ((0x86af < (int)pcVar9 && ((code *)0x2 < pcVar9 + -0x8744))))
              goto switchD_0009a048_caseD_86da;
LAB_0009a770:
              *(short *)(uVar12 * 0x7c + glContext + 0x353c) = (short)*params;
            }
            else {
              if (pname < 0x8572) {
                if (pname == 0xd1c) {
                  uVar8 = *params;
                  if ((1 < uVar8 - 1) && (uVar8 != 4)) goto LAB_0009abe0;
                  *(float *)(uVar12 * 0x7c + glContext + 0x355c) =
                       (float)((double)CONCAT44(0x43300000,uVar8 ^ 0x80000000) - DOUBLE_00108d58);
                  goto LAB_0009ac28;
                }
                goto switchD_0009a048_caseD_86da;
              }
              pcVar9 = (code *)*params;
              if (pcVar9 != (code *)0x84e7) {
                if ((int)pcVar9 < 0x84e8) {
                  if (pcVar9 != (code *)0x1e01) {
                    if ((int)pcVar9 < 0x1e02) {
                      bVar1 = pcVar9 == (code *)0x104;
                    }
                    else {
                      bVar1 = pcVar9 == (code *)0x2100;
                    }
                    if (!bVar1) goto switchD_0009a048_caseD_86da;
                  }
                }
                else if (((int)pcVar9 < 0x8574) ||
                        ((0x8575 < (int)pcVar9 && ((code *)0x2 < pcVar9 + -0x8744))))
                goto switchD_0009a048_caseD_86da;
              }
              *(short *)(uVar12 * 0x7c + glContext + 0x353e) = (short)*params;
            }
          }
        }
        else {
          if (pname != 0x8591) {
            if (pname < 0x8592) {
              if (pname == 0x858a) {
                uVar8 = *params;
                if ((((((uVar8 == 0x1702) || (uVar8 - 0x84c0 < 0x10)) || (uVar8 == 0x8576)) ||
                     ((uVar8 == 0x8577 || (uVar8 == 0x8578)))) || (uVar8 == 0)) || (uVar8 == 1)) {
                  *(short *)(uVar12 * 0x7c + glContext + 0x354a) = (short)*params;
                  goto LAB_0009ac28;
                }
              }
              else if (pname < 0x858a) {
                uVar8 = *params;
                if ((((uVar8 == 0x1702) || (uVar8 - 0x84c0 < 0x10)) ||
                    ((uVar8 == 0x8576 || (((uVar8 == 0x8577 || (uVar8 == 0x8578)) || (uVar8 == 0))))
                    )) || (uVar8 == 1)) {
                  *(short *)(uVar12 * 0x7c + glContext + 0x3548) = (short)*params;
                  goto LAB_0009ac28;
                }
              }
              else if ((pname == 0x8590) && (*params - 0x300 < 4)) {
                *(short *)(uVar12 * 0x7c + glContext + 0x354c) = (short)*params;
                goto LAB_0009ac28;
              }
            }
            else if (pname == 0x8598) {
              if (*params - 0x302 < 2) {
                *(short *)(uVar12 * 0x7c + glContext + 0x3552) = (short)*params;
                goto LAB_0009ac28;
              }
            }
            else if (pname < 0x8599) {
              if ((pname == 0x8592) && (*params - 0x300 < 4)) {
                *(short *)(uVar12 * 0x7c + glContext + 0x3550) = (short)*params;
                goto LAB_0009ac28;
              }
            }
            else if (pname == 0x8599) {
              if (*params - 0x302 < 2) {
                *(short *)(uVar12 * 0x7c + glContext + 0x3554) = (short)*params;
                goto LAB_0009ac28;
              }
            }
            else if ((pname == 0x859a) && (*params - 0x302 < 2)) {
              *(short *)(uVar12 * 0x7c + glContext + 0x3556) = (short)*params;
              goto LAB_0009ac28;
            }
            goto switchD_0009a048_caseD_86da;
          }
          if (3 < *params - 0x300) goto switchD_0009a048_caseD_86da;
          *(short *)(uVar12 * 0x7c + glContext + 0x354e) = (short)*params;
        }
LAB_0009ac28:
        uVar8 = *(uint *)(glContext + 800);
        iVar7 = 0x1000000;
      }
    }
    *(uint *)(glContext + 800) = uVar8 | iVar7 << (uVar12 & 0x3f);
  }
  else {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
LAB_0009acbc:
    *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  }
  return;
}

/* _glTexEnviv_CompExec @ 0x9acd4 (72 bytes) */
void _glTexEnviv_CompExec(glContext, target, pname, params)
  undefined4 glContext;
  undefined4 target;
  undefined4 pname;
  undefined4 params;
{
  ((int (*)())_glTexEnviv_Comp)(glContext,target,pname,params);
  ((void (*)())_glTexEnviv_Exec)(glContext,target,pname,params);
  return;
}

/* _glGetTexEnvfv_Exec @ 0x9ad1c (1248 bytes) */
void _glGetTexEnvfv_Exec(int glContext,int target,uint pname,float *params,undefined4 unusedArg5,undefined4 unusedArg6,undefined4 unusedArg7,double unusedFloatArg1,double unusedFloatArg2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  ushort uVar1;
  undefined4 glErrorCode;
  float fVar3;
  int iVar4;
  uint uVar5;
  
  uVar5 = *(uint *)(glContext + 0x53d4);
  if (-1 < *(short *)(glContext + 0x4a10)) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
    goto LAB_0009af0c;
  }
  if (target != 0x86de) {
    if (target == 0x8861) {
      if (pname == 0x8862) {
        if ((*(uint *)(glContext + 0x3444) & 1 << (uVar5 & 0x3f)) == 0) {
          fVar3 = 0.0;
          goto LAB_0009af54;
        }
        goto switchD_0009ad94_caseD_86dd;
      }
    }
    else if (target == 0x2300) {
      if (pname == 0x8582) {
        uVar5 = (uint)*(ushort *)(uVar5 * 0x7c + glContext + 0x3544);
        goto LAB_0009aec4;
      }
      if (pname < 0x8583) {
        if (pname == 0x8571) {
          uVar5 = (uint)*(ushort *)(uVar5 * 0x7c + glContext + 0x353c);
          goto LAB_0009aec4;
        }
        if (pname < 0x8572) {
          if (pname == 0x2200) {
            uVar5 = (uint)*(ushort *)(uVar5 * 0x7c + glContext + 0x3538);
            goto LAB_0009aec4;
          }
          if (pname < 0x2201) {
            if (pname == 0xd1c) {
              fVar3 = *(float *)(uVar5 * 0x7c + glContext + 0x355c);
              goto LAB_0009aee8;
            }
          }
          else if (pname == 0x2201) {
            iVar4 = glContext + uVar5 * 0x7c;
            *params = *(float *)(iVar4 + 0x3524);
            params[1] = *(float *)(iVar4 + 0x3528);
            params[2] = *(float *)(iVar4 + 0x352c);
            params[3] = *(float *)(iVar4 + 0x3530);
            return;
          }
        }
        else {
          if (pname == 0x8573) {
            fVar3 = *(float *)(uVar5 * 0x7c + glContext + 0x3558);
            goto LAB_0009aee8;
          }
          if (pname < 0x8573) {
            uVar5 = (uint)*(ushort *)(uVar5 * 0x7c + glContext + 0x353e);
            goto LAB_0009aec4;
          }
          if (pname == 0x8580) {
            uVar5 = (uint)*(ushort *)(uVar5 * 0x7c + glContext + 0x3540);
            goto LAB_0009aec4;
          }
          if (pname == 0x8581) {
            uVar5 = (uint)*(ushort *)(uVar5 * 0x7c + glContext + 0x3542);
            goto LAB_0009aec4;
          }
        }
      }
      else {
        if (pname == 0x8591) {
          uVar5 = (uint)*(ushort *)(uVar5 * 0x7c + glContext + 0x354e);
          goto LAB_0009aec4;
        }
        if (pname < 0x8592) {
          if (pname == 0x8589) {
            uVar5 = (uint)*(ushort *)(uVar5 * 0x7c + glContext + 0x3548);
            goto LAB_0009aec4;
          }
          if (pname < 0x858a) {
            if (pname == 0x8588) {
              uVar5 = (uint)*(ushort *)(uVar5 * 0x7c + glContext + 0x3546);
              goto LAB_0009aec4;
            }
          }
          else {
            if (pname == 0x858a) {
              uVar5 = (uint)*(ushort *)(uVar5 * 0x7c + glContext + 0x354a);
              goto LAB_0009aec4;
            }
            if (pname == 0x8590) {
              uVar5 = (uint)*(ushort *)(uVar5 * 0x7c + glContext + 0x354c);
              goto LAB_0009aec4;
            }
          }
        }
        else {
          if (pname == 0x8598) {
            uVar5 = (uint)*(ushort *)(uVar5 * 0x7c + glContext + 0x3552);
            goto LAB_0009aec4;
          }
          if (pname < 0x8599) {
            if (pname == 0x8592) {
              uVar5 = (uint)*(ushort *)(uVar5 * 0x7c + glContext + 0x3550);
              goto LAB_0009aec4;
            }
          }
          else {
            if (pname == 0x8599) {
              uVar5 = (uint)*(ushort *)(uVar5 * 0x7c + glContext + 0x3554);
              goto LAB_0009aec4;
            }
            if (pname == 0x859a) {
              uVar5 = (uint)*(ushort *)(uVar5 * 0x7c + glContext + 0x3556);
              goto LAB_0009aec4;
            }
          }
        }
      }
    }
    else if ((target == 0x8500) && (pname == 0x8501)) {
      fVar3 = *(float *)(uVar5 * 0x7c + glContext + 0x3560);
      goto LAB_0009aee8;
    }
switchD_0009ad94_caseD_86da:
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x500;
LAB_0009af0c:
    *(undefined4 *)(glContext + 0x7574) = glErrorCode;
    return;
  }
  iVar4 = glContext + uVar5 * 0x7c;
  switch(pname) {
  case 0x86d9:
    fVar3 = *params;
    *(short *)(iVar4 + 0x356c) = (short)(int)fVar3;
    uVar5 = (int)fVar3 & 0xffff;
    goto LAB_0009aec4;
  default:
    goto switchD_0009ad94_caseD_86da;
  case 0x86dd:
switchD_0009ad94_caseD_86dd:
    fVar3 = 1.0;
LAB_0009af54:
    *params = fVar3;
    return;
  case 0x86df:
    uVar1 = *(ushort *)(iVar4 + 0x3564);
    break;
  case 0x86e0:
    *params = GH_U2F((unsigned int)((*(ushort *)(iVar4 + 0x3570) | 0x4b000000))) - 8388608.0;
    params[1] = GH_U2F((unsigned int)((*(ushort *)(iVar4 + 0x3572) | 0x4b000000))) - 8388608.0;
    params[2] = GH_U2F((unsigned int)((*(ushort *)(iVar4 + 0x3574) | 0x4b000000))) - 8388608.0;
    fVar3 = GH_U2F((unsigned int)((*(ushort *)(iVar4 + 0x3576) | 0x4b000000))) - 8388608.0;
    goto LAB_0009ae78;
  case 0x86e1:
    *params = *(float *)(iVar4 + 0x3588);
    params[1] = *(float *)(iVar4 + 0x358c);
    params[2] = *(float *)(iVar4 + 0x3590);
    fVar3 = *(float *)(iVar4 + 0x3594);
LAB_0009ae78:
    params[3] = fVar3;
    return;
  case 0x86e2:
    fVar3 = *(float *)(iVar4 + 0x3598);
    goto LAB_0009aee8;
  case 0x86e3:
    fVar3 = *(float *)(iVar4 + 0x359c);
LAB_0009aee8:
    *params = fVar3;
    return;
  case 0x86e4:
    uVar1 = *(ushort *)(iVar4 + 0x356a);
    break;
  case 0x86e5:
    *params = *(float *)(iVar4 + 0x357c);
    params[1] = *(float *)(iVar4 + 0x3580);
    params[2] = *(float *)(iVar4 + 0x3584);
    return;
  }
  uVar5 = (uint)uVar1;
LAB_0009aec4:
  *params = GH_U2F((unsigned int)((uVar5 | 0x4b000000))) - 8388608.0;
  return;
}

/* _glGetTexEnviv_Exec @ 0x9b230 (1232 bytes) */
void _glGetTexEnviv_Exec(glContext, target, pname, params)
  int glContext;
  int target;
  uint pname;
  uint *params;
{
  float fVar1;
  float fVar2;
  undefined4 glErrorCode;
  uint uVar4;
  int iVar5;
  uint uVar6;
  
  fVar2 = FLOAT_00108e94;
  fVar1 = FLOAT_00108e90;
  uVar6 = *(uint *)(glContext + 0x53d4);
  if (-1 < *(short *)(glContext + 0x4a10)) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
    goto LAB_0009b3d0;
  }
  if (target != 0x86de) {
    if (target == 0x8861) {
      if (pname == 0x8862) {
        uVar4 = 0;
        if ((*(uint *)(glContext + 0x3444) & 1 << (uVar6 & 0x3f)) != 0) {
          *params = 1;
          return;
        }
        goto LAB_0009b398;
      }
    }
    else if (target == 0x2300) {
      if (pname == 0x8582) {
        uVar4 = (uint)*(ushort *)(uVar6 * 0x7c + glContext + 0x3544);
        goto LAB_0009b398;
      }
      if (pname < 0x8583) {
        if (pname == 0x8571) {
          uVar4 = (uint)*(ushort *)(uVar6 * 0x7c + glContext + 0x353c);
          goto LAB_0009b398;
        }
        if (pname < 0x8572) {
          if (pname == 0x2200) {
            uVar4 = (uint)*(ushort *)(uVar6 * 0x7c + glContext + 0x3538);
            goto LAB_0009b398;
          }
          if (pname < 0x2201) {
            if (pname == 0xd1c) {
              fVar1 = *(float *)(uVar6 * 0x7c + glContext + 0x355c);
              goto LAB_0009b724;
            }
          }
          else if (pname == 0x2201) {
            iVar5 = glContext + uVar6 * 0x7c;
            *params = (int)(*(float *)(iVar5 + 0x3524) * FLOAT_00108e94 - FLOAT_00108e90);
            params[1] = (int)(*(float *)(iVar5 + 0x3528) * fVar2 - fVar1);
            params[2] = (int)(*(float *)(iVar5 + 0x352c) * fVar2 - fVar1);
            fVar1 = *(float *)(iVar5 + 0x3530) * fVar2 - fVar1;
            goto LAB_0009b5e4;
          }
        }
        else {
          if (pname == 0x8573) {
            fVar1 = *(float *)(uVar6 * 0x7c + glContext + 0x3558);
            goto LAB_0009b724;
          }
          if (pname < 0x8573) {
            uVar4 = (uint)*(ushort *)(uVar6 * 0x7c + glContext + 0x353e);
            goto LAB_0009b398;
          }
          if (pname == 0x8580) {
            uVar4 = (uint)*(ushort *)(uVar6 * 0x7c + glContext + 0x3540);
            goto LAB_0009b398;
          }
          if (pname == 0x8581) {
            uVar4 = (uint)*(ushort *)(uVar6 * 0x7c + glContext + 0x3542);
            goto LAB_0009b398;
          }
        }
      }
      else {
        if (pname == 0x8591) {
          uVar4 = (uint)*(ushort *)(uVar6 * 0x7c + glContext + 0x354e);
          goto LAB_0009b398;
        }
        if (pname < 0x8592) {
          if (pname == 0x8589) {
            uVar4 = (uint)*(ushort *)(uVar6 * 0x7c + glContext + 0x3548);
            goto LAB_0009b398;
          }
          if (pname < 0x858a) {
            if (pname == 0x8588) {
              uVar4 = (uint)*(ushort *)(uVar6 * 0x7c + glContext + 0x3546);
              goto LAB_0009b398;
            }
          }
          else {
            if (pname == 0x858a) {
              uVar4 = (uint)*(ushort *)(uVar6 * 0x7c + glContext + 0x354a);
              goto LAB_0009b398;
            }
            if (pname == 0x8590) {
              uVar4 = (uint)*(ushort *)(uVar6 * 0x7c + glContext + 0x354c);
              goto LAB_0009b398;
            }
          }
        }
        else {
          if (pname == 0x8598) {
            uVar4 = (uint)*(ushort *)(uVar6 * 0x7c + glContext + 0x3552);
            goto LAB_0009b398;
          }
          if (pname < 0x8599) {
            if (pname == 0x8592) {
              uVar4 = (uint)*(ushort *)(uVar6 * 0x7c + glContext + 0x3550);
              goto LAB_0009b398;
            }
          }
          else {
            if (pname == 0x8599) {
              uVar4 = (uint)*(ushort *)(uVar6 * 0x7c + glContext + 0x3554);
              goto LAB_0009b398;
            }
            if (pname == 0x859a) {
              uVar4 = (uint)*(ushort *)(uVar6 * 0x7c + glContext + 0x3556);
              goto LAB_0009b398;
            }
          }
        }
      }
    }
    else if ((target == 0x8500) && (pname == 0x8501)) {
      fVar1 = *(float *)(uVar6 * 0x7c + glContext + 0x3560);
      goto LAB_0009b724;
    }
switchD_0009b2a8_caseD_86da:
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x500;
LAB_0009b3d0:
    *(undefined4 *)(glContext + 0x7574) = glErrorCode;
    return;
  }
  iVar5 = glContext + uVar6 * 0x7c;
  switch(pname) {
  case 0x86d9:
    uVar4 = (uint)(ushort)*params;
    *(ushort *)(iVar5 + 0x356c) = (ushort)*params;
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
    *params = (uint)*(ushort *)(iVar5 + 0x3570);
    params[1] = (uint)*(ushort *)(iVar5 + 0x3572);
    params[2] = (uint)*(ushort *)(iVar5 + 0x3574);
    params[3] = (uint)*(ushort *)(iVar5 + 0x3576);
    return;
  case 0x86e1:
    *params = (int)*(float *)(iVar5 + 0x3588);
    params[1] = (int)*(float *)(iVar5 + 0x358c);
    params[2] = (int)*(float *)(iVar5 + 0x3590);
    fVar1 = *(float *)(iVar5 + 0x3594);
LAB_0009b5e4:
    params[3] = (int)fVar1;
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
    *params = (int)*(float *)(iVar5 + 0x357c);
    params[1] = (int)*(float *)(iVar5 + 0x3580);
    params[2] = (int)*(float *)(iVar5 + 0x3584);
    return;
  }
LAB_0009b398:
  *params = uVar4;
  return;
}

/* _glTexGen_ListExec @ 0x9b734 (64 bytes) */
int _glTexGen_ListExec(glContext, listRecord)
  undefined4 glContext;
  undefined4 *listRecord;
{
  ((void (*)())_glTexGen_Exec)(glContext,*listRecord,listRecord[1],(double)GH_U2F((unsigned int)(listRecord[2])),(double)GH_U2F((unsigned int)(listRecord[3])),
                 (double)GH_U2F((unsigned int)(listRecord[4])),(double)GH_U2F((unsigned int)(listRecord[5])));
  return 0x18;
}

/* _glTexGen_Comp @ 0x9b774 (144 bytes) */
double _glTexGen_Comp(undefined4 glContext,undefined4 param_2,uint param_3,float fparam_1,float fparam_2,float fparam_3,float fparam_4)
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glTexGen_ListExec_001103e0,0x18);
  if (listRecord != (undefined4 *)0x0) {
    *listRecord = param_2;
    listRecord[1] = param_3;
    if (param_3 == 0x2500) {
      listRecord[2] = (float)fparam_1;
    }
    else if ((0x24ff < param_3) && (param_3 < 0x2503)) {
      listRecord[5] = (float)fparam_4;
      listRecord[2] = (float)fparam_1;
      listRecord[3] = (float)fparam_2;
      listRecord[4] = (float)fparam_3;
    }
  }
  return;
}

/* _glTexGen_Exec @ 0x9b804 (2380 bytes) */
void _glTexGen_Exec(int glContext,uint param_2,uint param_3,float fparam_1,float fparam_2,float fparam_3,float fparam_4)
{
  byte bVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  undefined4 glErrorCode;
  int iVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  
  uVar10 = *(uint *)(glContext + 0x53d4);
  if ((-1 < *(short *)(glContext + 0x4a10)) || (7 < uVar10)) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
    goto LAB_0009c0ec;
  }
  if (param_2 == 0x2001) {
    if (param_3 != 0x2501) {
      if (param_3 < 0x2502) {
        if (((param_3 == 0x2500) && (iVar7 = (int)fparam_1, 0x23ff < iVar7)) &&
           ((iVar7 < 0x2403 || (iVar7 - 0x8511U < 2)))) {
          *(short *)(uVar10 * 0x94 + glContext + 0x3d0c) = (short)iVar7;
          goto LAB_0009c10c;
        }
      }
      else if (param_3 == 0x2502) {
        iVar7 = uVar10 * 0x94 + glContext;
        *(float *)(iVar7 + 0x3d10) = (float)fparam_1;
        *(float *)(iVar7 + 0x3d14) = (float)fparam_2;
        *(float *)(iVar7 + 0x3d18) = (float)fparam_3;
        *(float *)(iVar7 + 0x3d1c) = (float)fparam_4;
        if ((*(uint *)(glContext + 0x50b0) & 0x10) != 0) {
          ((double (*)())_gleModelMatInvert)(glContext);
        }
        fVar2 = *(float *)(iVar7 + 0x3d14);
        fVar3 = *(float *)(iVar7 + 0x3d10);
        fVar4 = *(float *)(iVar7 + 0x3d18);
        fVar5 = *(float *)(iVar7 + 0x3d1c);
        *(float *)(iVar7 + 0x3d10) =
             fVar5 * *(float *)(glContext + 0x22f0) +
             (fVar4 * *(float *)(glContext + 0x22e0) +
             (fVar3 * *(float *)(glContext + 0x22c0) + fVar2 * *(float *)(glContext + 0x22d0)));
        *(float *)(iVar7 + 0x3d14) =
             fVar5 * *(float *)(glContext + 0x22f4) +
             (fVar4 * *(float *)(glContext + 0x22e4) +
             (fVar3 * *(float *)(glContext + 0x22c4) + fVar2 * *(float *)(glContext + 0x22d4)));
        *(float *)(iVar7 + 0x3d18) =
             fVar5 * *(float *)(glContext + 0x22f8) +
             (fVar4 * *(float *)(glContext + 0x22e8) +
             (fVar3 * *(float *)(glContext + 0x22c8) + fVar2 * *(float *)(glContext + 0x22d8)));
        *(float *)(iVar7 + 0x3d1c) =
             fVar5 * *(float *)(glContext + 0x22fc) +
             (fVar4 * *(float *)(glContext + 0x22ec) +
             (fVar3 * *(float *)(glContext + 0x22cc) + fVar2 * *(float *)(glContext + 0x22dc)));
        if (*(int *)(glContext + 0x5434) == 0) {
          bVar1 = *(byte *)(uVar10 * 4 + *(int *)(glContext + 0x5420) + 0x2cd);
        }
        else {
          bVar1 = *(byte *)(uVar10 * 4 + *(int *)(*(int *)(glContext + 0x5430) + 0x20) + 0x301);
        }
        iVar9 = (bVar1 >> 3 & 0x1c) + glContext;
        iVar7 = *(int *)(glContext + 0x5424);
        *(uint *)(iVar9 + 0x324) = *(uint *)(iVar9 + 0x324) | 1 << (bVar1 & 0x1f);
        uVar8 = (uint)*(byte *)(uVar10 * 4 + iVar7 + 0x2cd);
        goto LAB_0009c0b8;
      }
LAB_0009c0dc:
      if (*(int *)(glContext + 0x7574) != 0) {
        return;
      }
      glErrorCode = 0x500;
LAB_0009c0ec:
      *(undefined4 *)(glContext + 0x7574) = glErrorCode;
      return;
    }
    iVar7 = uVar10 * 0x94 + glContext;
    *(float *)(iVar7 + 0x3d2c) = (float)fparam_4;
    *(float *)(iVar7 + 0x3d20) = (float)fparam_1;
    *(float *)(iVar7 + 0x3d24) = (float)fparam_2;
    *(float *)(iVar7 + 0x3d28) = (float)fparam_3;
    if (*(int *)(glContext + 0x5434) == 0) {
      bVar1 = *(byte *)(uVar10 * 4 + *(int *)(glContext + 0x5420) + 0x2ed);
    }
    else {
      bVar1 = *(byte *)(uVar10 * 4 + *(int *)(*(int *)(glContext + 0x5430) + 0x20) + 0x321);
    }
    iVar9 = (bVar1 >> 3 & 0x1c) + glContext;
    iVar7 = *(int *)(glContext + 0x5424);
    *(uint *)(iVar9 + 0x324) = *(uint *)(iVar9 + 0x324) | 1 << (bVar1 & 0x1f);
    uVar8 = (uint)*(byte *)(uVar10 * 4 + iVar7 + 0x2ed);
  }
  else if (param_2 < 0x2002) {
    if (param_2 != 0x2000) {
LAB_0009c0f4:
      if (*(int *)(glContext + 0x7574) == 0) {
        *(undefined4 *)(glContext + 0x7574) = 0x500;
      }
      goto LAB_0009c10c;
    }
    if (param_3 != 0x2501) {
      if (param_3 < 0x2502) {
        if (((param_3 == 0x2500) && (iVar7 = (int)fparam_1, 0x23ff < iVar7)) &&
           ((iVar7 < 0x2403 || (iVar7 - 0x8511U < 2)))) {
          *(short *)(uVar10 * 0x94 + glContext + 0x3ce8) = (short)iVar7;
          goto LAB_0009c10c;
        }
      }
      else if (param_3 == 0x2502) {
        iVar7 = uVar10 * 0x94 + glContext;
        *(float *)(iVar7 + 0x3cec) = (float)fparam_1;
        *(float *)(iVar7 + 0x3cf0) = (float)fparam_2;
        *(float *)(iVar7 + 0x3cf4) = (float)fparam_3;
        *(float *)(iVar7 + 0x3cf8) = (float)fparam_4;
        if ((*(uint *)(glContext + 0x50b0) & 0x10) != 0) {
          ((double (*)())_gleModelMatInvert)(glContext);
        }
        fVar2 = *(float *)(iVar7 + 0x3cf0);
        fVar3 = *(float *)(iVar7 + 0x3cec);
        fVar4 = *(float *)(iVar7 + 0x3cf4);
        fVar5 = *(float *)(iVar7 + 0x3cf8);
        *(float *)(iVar7 + 0x3cec) =
             fVar5 * *(float *)(glContext + 0x22f0) +
             (fVar4 * *(float *)(glContext + 0x22e0) +
             (fVar3 * *(float *)(glContext + 0x22c0) + fVar2 * *(float *)(glContext + 0x22d0)));
        *(float *)(iVar7 + 0x3cf0) =
             fVar5 * *(float *)(glContext + 0x22f4) +
             (fVar4 * *(float *)(glContext + 0x22e4) +
             (fVar3 * *(float *)(glContext + 0x22c4) + fVar2 * *(float *)(glContext + 0x22d4)));
        *(float *)(iVar7 + 0x3cf4) =
             fVar5 * *(float *)(glContext + 0x22f8) +
             (fVar4 * *(float *)(glContext + 0x22e8) +
             (fVar3 * *(float *)(glContext + 0x22c8) + fVar2 * *(float *)(glContext + 0x22d8)));
        *(float *)(iVar7 + 0x3cf8) =
             fVar5 * *(float *)(glContext + 0x22fc) +
             (fVar4 * *(float *)(glContext + 0x22ec) +
             (fVar3 * *(float *)(glContext + 0x22cc) + fVar2 * *(float *)(glContext + 0x22dc)));
        if (*(int *)(glContext + 0x5434) == 0) {
          bVar1 = *(byte *)(uVar10 * 4 + *(int *)(glContext + 0x5420) + 0x2cc);
        }
        else {
          bVar1 = *(byte *)(uVar10 * 4 + *(int *)(*(int *)(glContext + 0x5430) + 0x20) + 0x300);
        }
        iVar9 = (bVar1 >> 3 & 0x1c) + glContext;
        iVar7 = *(int *)(glContext + 0x5424);
        *(uint *)(iVar9 + 0x324) = *(uint *)(iVar9 + 0x324) | 1 << (bVar1 & 0x1f);
        uVar8 = (uint)*(byte *)(uVar10 * 4 + iVar7 + 0x2cc);
        goto LAB_0009c0b8;
      }
      goto LAB_0009c0dc;
    }
    iVar7 = uVar10 * 0x94 + glContext;
    *(float *)(iVar7 + 0x3d08) = (float)fparam_4;
    *(float *)(iVar7 + 0x3cfc) = (float)fparam_1;
    *(float *)(iVar7 + 0x3d00) = (float)fparam_2;
    *(float *)(iVar7 + 0x3d04) = (float)fparam_3;
    if (*(int *)(glContext + 0x5434) == 0) {
      bVar1 = *(byte *)(uVar10 * 4 + *(int *)(glContext + 0x5420) + 0x2ec);
    }
    else {
      bVar1 = *(byte *)(uVar10 * 4 + *(int *)(*(int *)(glContext + 0x5430) + 0x20) + 800);
    }
    iVar9 = (bVar1 >> 3 & 0x1c) + glContext;
    iVar7 = *(int *)(glContext + 0x5424);
    *(uint *)(iVar9 + 0x324) = *(uint *)(iVar9 + 0x324) | 1 << (bVar1 & 0x1f);
    uVar8 = (uint)*(byte *)(uVar10 * 4 + iVar7 + 0x2ec);
  }
  else if (param_2 == 0x2002) {
    if (param_3 != 0x2501) {
      if (param_3 < 0x2502) {
        if (((param_3 == 0x2500) && (iVar7 = (int)fparam_1, 0x23ff < iVar7)) &&
           ((iVar7 < 0x2402 || (iVar7 - 0x8511U < 2)))) {
          *(short *)(uVar10 * 0x94 + glContext + 0x3d30) = (short)iVar7;
          goto LAB_0009c10c;
        }
      }
      else if (param_3 == 0x2502) {
        iVar7 = uVar10 * 0x94 + glContext;
        *(float *)(iVar7 + 0x3d34) = (float)fparam_1;
        *(float *)(iVar7 + 0x3d38) = (float)fparam_2;
        *(float *)(iVar7 + 0x3d3c) = (float)fparam_3;
        *(float *)(iVar7 + 0x3d40) = (float)fparam_4;
        if ((*(uint *)(glContext + 0x50b0) & 0x10) != 0) {
          ((double (*)())_gleModelMatInvert)(glContext);
        }
        fVar2 = *(float *)(iVar7 + 0x3d38);
        fVar3 = *(float *)(iVar7 + 0x3d34);
        fVar4 = *(float *)(iVar7 + 0x3d3c);
        fVar5 = *(float *)(iVar7 + 0x3d40);
        *(float *)(iVar7 + 0x3d34) =
             fVar5 * *(float *)(glContext + 0x22f0) +
             (fVar4 * *(float *)(glContext + 0x22e0) +
             (fVar3 * *(float *)(glContext + 0x22c0) + fVar2 * *(float *)(glContext + 0x22d0)));
        *(float *)(iVar7 + 0x3d38) =
             fVar5 * *(float *)(glContext + 0x22f4) +
             (fVar4 * *(float *)(glContext + 0x22e4) +
             (fVar3 * *(float *)(glContext + 0x22c4) + fVar2 * *(float *)(glContext + 0x22d4)));
        *(float *)(iVar7 + 0x3d3c) =
             fVar5 * *(float *)(glContext + 0x22f8) +
             (fVar4 * *(float *)(glContext + 0x22e8) +
             (fVar3 * *(float *)(glContext + 0x22c8) + fVar2 * *(float *)(glContext + 0x22d8)));
        *(float *)(iVar7 + 0x3d40) =
             fVar5 * *(float *)(glContext + 0x22fc) +
             (fVar4 * *(float *)(glContext + 0x22ec) +
             (fVar3 * *(float *)(glContext + 0x22cc) + fVar2 * *(float *)(glContext + 0x22dc)));
        if (*(int *)(glContext + 0x5434) == 0) {
          bVar1 = *(byte *)(uVar10 * 4 + *(int *)(glContext + 0x5420) + 0x2ce);
        }
        else {
          bVar1 = *(byte *)(uVar10 * 4 + *(int *)(*(int *)(glContext + 0x5430) + 0x20) + 0x302);
        }
        iVar9 = (bVar1 >> 3 & 0x1c) + glContext;
        iVar7 = *(int *)(glContext + 0x5424);
        *(uint *)(iVar9 + 0x324) = *(uint *)(iVar9 + 0x324) | 1 << (bVar1 & 0x1f);
        uVar8 = (uint)*(byte *)(uVar10 * 4 + iVar7 + 0x2ce);
        goto LAB_0009c0b8;
      }
      goto LAB_0009c0dc;
    }
    iVar7 = uVar10 * 0x94 + glContext;
    *(float *)(iVar7 + 0x3d50) = (float)fparam_4;
    *(float *)(iVar7 + 0x3d44) = (float)fparam_1;
    *(float *)(iVar7 + 0x3d48) = (float)fparam_2;
    *(float *)(iVar7 + 0x3d4c) = (float)fparam_3;
    if (*(int *)(glContext + 0x5434) == 0) {
      bVar1 = *(byte *)(uVar10 * 4 + *(int *)(glContext + 0x5420) + 0x2ee);
    }
    else {
      bVar1 = *(byte *)(uVar10 * 4 + *(int *)(*(int *)(glContext + 0x5430) + 0x20) + 0x322);
    }
    iVar9 = (bVar1 >> 3 & 0x1c) + glContext;
    iVar7 = *(int *)(glContext + 0x5424);
    *(uint *)(iVar9 + 0x324) = *(uint *)(iVar9 + 0x324) | 1 << (bVar1 & 0x1f);
    uVar8 = (uint)*(byte *)(uVar10 * 4 + iVar7 + 0x2ee);
  }
  else {
    if (param_2 != 0x2003) goto LAB_0009c0f4;
    if (param_3 != 0x2501) {
      if (param_3 < 0x2502) {
        if ((param_3 == 0x2500) && ((int)fparam_1 - 0x2400U < 2)) {
          *(short *)(uVar10 * 0x94 + glContext + 0x3d54) = (short)(int)fparam_1;
          goto LAB_0009c10c;
        }
      }
      else if (param_3 == 0x2502) {
        iVar7 = uVar10 * 0x94 + glContext;
        *(float *)(iVar7 + 0x3d58) = (float)fparam_1;
        *(float *)(iVar7 + 0x3d5c) = (float)fparam_2;
        *(float *)(iVar7 + 0x3d60) = (float)fparam_3;
        *(float *)(iVar7 + 0x3d64) = (float)fparam_4;
        if ((*(uint *)(glContext + 0x50b0) & 0x10) != 0) {
          ((double (*)())_gleModelMatInvert)(glContext);
        }
        fVar2 = *(float *)(iVar7 + 0x3d5c);
        fVar3 = *(float *)(iVar7 + 0x3d58);
        fVar4 = *(float *)(iVar7 + 0x3d60);
        fVar5 = *(float *)(iVar7 + 0x3d64);
        *(float *)(iVar7 + 0x3d58) =
             fVar5 * *(float *)(glContext + 0x22f0) +
             (fVar4 * *(float *)(glContext + 0x22e0) +
             (fVar3 * *(float *)(glContext + 0x22c0) + fVar2 * *(float *)(glContext + 0x22d0)));
        *(float *)(iVar7 + 0x3d5c) =
             fVar5 * *(float *)(glContext + 0x22f4) +
             (fVar4 * *(float *)(glContext + 0x22e4) +
             (fVar3 * *(float *)(glContext + 0x22c4) + fVar2 * *(float *)(glContext + 0x22d4)));
        *(float *)(iVar7 + 0x3d60) =
             fVar5 * *(float *)(glContext + 0x22f8) +
             (fVar4 * *(float *)(glContext + 0x22e8) +
             (fVar3 * *(float *)(glContext + 0x22c8) + fVar2 * *(float *)(glContext + 0x22d8)));
        *(float *)(iVar7 + 0x3d64) =
             fVar5 * *(float *)(glContext + 0x22fc) +
             (fVar4 * *(float *)(glContext + 0x22ec) +
             (fVar3 * *(float *)(glContext + 0x22cc) + fVar2 * *(float *)(glContext + 0x22dc)));
        if (*(int *)(glContext + 0x5434) == 0) {
          bVar1 = *(byte *)(uVar10 * 4 + *(int *)(glContext + 0x5420) + 0x2cf);
        }
        else {
          bVar1 = *(byte *)(uVar10 * 4 + *(int *)(*(int *)(glContext + 0x5430) + 0x20) + 0x303);
        }
        iVar9 = (bVar1 >> 3 & 0x1c) + glContext;
        iVar7 = *(int *)(glContext + 0x5424);
        *(uint *)(iVar9 + 0x324) = *(uint *)(iVar9 + 0x324) | 1 << (bVar1 & 0x1f);
        uVar8 = (uint)*(byte *)(uVar10 * 4 + iVar7 + 0x2cf);
        goto LAB_0009c0b8;
      }
      goto LAB_0009c0dc;
    }
    iVar7 = uVar10 * 0x94 + glContext;
    *(float *)(iVar7 + 0x3d74) = (float)fparam_4;
    *(float *)(iVar7 + 0x3d68) = (float)fparam_1;
    *(float *)(iVar7 + 0x3d6c) = (float)fparam_2;
    *(float *)(iVar7 + 0x3d70) = (float)fparam_3;
    if (*(int *)(glContext + 0x5434) == 0) {
      bVar1 = *(byte *)(uVar10 * 4 + *(int *)(glContext + 0x5420) + 0x2ef);
    }
    else {
      bVar1 = *(byte *)(uVar10 * 4 + *(int *)(*(int *)(glContext + 0x5430) + 0x20) + 0x323);
    }
    iVar9 = (bVar1 >> 3 & 0x1c) + glContext;
    iVar7 = *(int *)(glContext + 0x5424);
    *(uint *)(iVar9 + 0x324) = *(uint *)(iVar9 + 0x324) | 1 << (bVar1 & 0x1f);
    uVar8 = (uint)*(byte *)(uVar10 * 4 + iVar7 + 0x2ef);
  }
LAB_0009c0b8:
  iVar7 = (uVar8 >> 3 & 0x1c) + glContext;
  *(uint *)(iVar7 + 0x348) = *(uint *)(iVar7 + 0x348) | 1 << (uVar8 & 0x1f);
LAB_0009c10c:
  _gleUpdateTextureCoordGen(glContext);
  if (param_3 == 0x2500) {
    _gleSelectVertexSubmitFunc(glContext);
  }
  *(uint *)(glContext + 0x314) = *(uint *)(glContext + 0x314) | 0x10000 << (uVar10 & 0x3f);
  return;
}

/* _glTexGend_Comp @ 0x9c150 (40 bytes) */
void _glTexGend_Comp(undefined4 glContext,undefined4 coord,undefined4 pname,double param)
{
  double fparam_2;
  
  fparam_2 = (double)FLOAT_00108e50;
  ((double (*)())_glTexGen_Comp)(glContext,coord,pname,(double)(float)param,fparam_2,fparam_2,fparam_2);
  return;
}

/* _glTexGend_Exec @ 0x9c178 (40 bytes) */
void _glTexGend_Exec(undefined4 glContext,undefined4 coord,undefined4 pname,double param)
{
  double fparam_2;
  
  fparam_2 = (double)FLOAT_00108e50;
  ((void (*)())_glTexGen_Exec)(glContext,coord,pname,(double)(float)param,fparam_2,fparam_2,fparam_2);
  return;
}

/* _glTexGend_CompExec @ 0x9c1a0 (80 bytes) */
void _glTexGend_CompExec(undefined4 glContext,undefined4 coord,undefined4 pname,double param)
{
  ((void (*)())_glTexGend_Comp)(glContext,coord,pname,param);
  ((void (*)())_glTexGend_Exec)(glContext,coord,pname,param);
  return;
}

/* _glTexGendv_Comp @ 0x9c1f0 (36 bytes) */
void _glTexGendv_Comp(glContext, coord, pname, params)
  undefined4 glContext;
  undefined4 coord;
  undefined4 pname;
  double *params;
{
  ((double (*)())_glTexGen_Comp)(glContext,coord,pname,(double)(float)*params,(double)(float)params[1],
                 (double)(float)params[2],(double)(float)params[3]);
  return;
}

/* _glTexGendv_CompExec @ 0x9c238 (108 bytes) */
void _glTexGendv_CompExec(glContext, coord, pname, params)
  undefined4 glContext;
  undefined4 coord;
  undefined4 pname;
  double *params;
{
  ((void (*)())_glTexGendv_Comp)(glContext,coord,pname,params);
  ((void (*)())_glTexGen_Exec)(glContext,coord,pname,(double)(float)*params,(double)(float)params[1],
                 (double)(float)params[2],(double)(float)params[3]);
  return;
}

/* _glTexGenf_Comp @ 0x9c280 (36 bytes) */
void _glTexGenf_Comp(undefined4 glContext,undefined4 coord,undefined4 pname,float param)
{
  double fparam_2;
  
  fparam_2 = (double)FLOAT_00108e50;
  ((double (*)())_glTexGen_Comp)(glContext,coord,pname,param,fparam_2,fparam_2,fparam_2);
  return;
}

/* _glTexGenf_Exec @ 0x9c2a4 (36 bytes) */
void _glTexGenf_Exec(undefined4 glContext,undefined4 coord,undefined4 pname,float param)
{
  double fparam_2;
  
  fparam_2 = (double)FLOAT_00108e50;
  ((void (*)())_glTexGen_Exec)(glContext,coord,pname,param,fparam_2,fparam_2,fparam_2);
  return;
}

/* _glTexGenf_CompExec @ 0x9c2c8 (80 bytes) */
void _glTexGenf_CompExec(undefined4 glContext,undefined4 coord,undefined4 pname,float param)
{
  ((void (*)())_glTexGenf_Comp)(glContext,coord,pname,param);
  ((void (*)())_glTexGenf_Exec)(glContext,coord,pname,param);
  return;
}

/* _glTexGenfv_Comp @ 0x9c318 (20 bytes) */
void _glTexGenfv_Comp(glContext, coord, pname, params)
  undefined4 glContext;
  undefined4 coord;
  undefined4 pname;
  float *params;
{
  ((double (*)())_glTexGen_Comp)(glContext,coord,pname,(double)*params,(double)params[1],(double)params[2],
                 (double)params[3]);
  return;
}

/* _glTexGenfv_CompExec @ 0x9c340 (92 bytes) */
void _glTexGenfv_CompExec(glContext, coord, pname, params)
  undefined4 glContext;
  undefined4 coord;
  undefined4 pname;
  float *params;
{
  ((void (*)())_glTexGenfv_Comp)(glContext,coord,pname,params);
  ((void (*)())_glTexGen_Exec)(glContext,coord,pname,(double)*params,(double)params[1],(double)params[2],
                 (double)params[3]);
  return;
}

/* _glTexGeni_Comp @ 0x9c388 (100 bytes) */
double _glTexGeni_Comp(undefined4 glContext,undefined4 coord,undefined4 pname,uint param)
{
  double dVar1;
  
  dVar1 = (double)FLOAT_00108e50;
  dVar1 = (double)((double (*)())_glTexGen_Comp)(glContext,coord,pname,
                                 (double)(float)((double)CONCAT44(0x43300000,param ^ 0x80000000) -
                                                DOUBLE_00108d58),dVar1,dVar1,dVar1);
  return dVar1;
}

/* _glTexGeni_Exec @ 0x9c3ec (100 bytes) */
void _glTexGeni_Exec(glContext, coord, pname, param)
  undefined4 glContext;
  undefined4 coord;
  undefined4 pname;
  uint param;
{
  double fparam_2;
  
  fparam_2 = (double)FLOAT_00108e50;
  ((void (*)())_glTexGen_Exec)(glContext,coord,pname,
                 (double)(float)((double)CONCAT44(0x43300000,param ^ 0x80000000) - DOUBLE_00108d58
                                ),fparam_2,fparam_2,fparam_2);
  return;
}

/* _glTexGeni_CompExec @ 0x9c450 (72 bytes) */
void _glTexGeni_CompExec(glContext, coord, pname, param)
  undefined4 glContext;
  undefined4 coord;
  undefined4 pname;
  undefined4 param;
{
  ((double (*)())_glTexGeni_Comp)(glContext,coord,pname,param);
  ((void (*)())_glTexGeni_Exec)(glContext,coord,pname,param);
  return;
}

/* _glTexGeniv_Comp @ 0x9c498 (160 bytes) */
double _glTexGeniv_Comp(undefined4 glContext,undefined4 coord,undefined4 pname,uint *params)
{
  double dVar1;
  
  dVar1 = (double)((double (*)())_glTexGen_Comp)(glContext,coord,pname,
                                 (double)(float)((double)CONCAT44(0x43300000,*params ^ 0x80000000)
                                                - DOUBLE_00108d58),
                                 (double)(float)((double)CONCAT44(0x43300000,params[1] ^ 0x80000000
                                                                 ) - DOUBLE_00108d58),
                                 (double)(float)((double)CONCAT44(0x43300000,params[2] ^ 0x80000000
                                                                 ) - DOUBLE_00108d58),
                                 (double)(float)((double)CONCAT44(0x43300000,params[3] ^ 0x80000000
                                                                 ) - DOUBLE_00108d58));
  return dVar1;
}

/* _glTexGeniv_Exec @ 0x9c538 (160 bytes) */
void _glTexGeniv_Exec(glContext, coord, pname, params)
  undefined4 glContext;
  undefined4 coord;
  undefined4 pname;
  uint *params;
{
  ((void (*)())_glTexGen_Exec)(glContext,coord,pname,
                 (double)(float)((double)CONCAT44(0x43300000,*params ^ 0x80000000) -
                                DOUBLE_00108d58),
                 (double)(float)((double)CONCAT44(0x43300000,params[1] ^ 0x80000000) -
                                DOUBLE_00108d58),
                 (double)(float)((double)CONCAT44(0x43300000,params[2] ^ 0x80000000) -
                                DOUBLE_00108d58),
                 (double)(float)((double)CONCAT44(0x43300000,params[3] ^ 0x80000000) -
                                DOUBLE_00108d58));
  return;
}

/* _glTexGeniv_CompExec @ 0x9c5d8 (72 bytes) */
void _glTexGeniv_CompExec(glContext, coord, pname, params)
  undefined4 glContext;
  undefined4 coord;
  undefined4 pname;
  undefined4 params;
{
  ((double (*)())_glTexGeniv_Comp)(glContext,coord,pname,params);
  ((void (*)())_glTexGeniv_Exec)(glContext,coord,pname,params);
  return;
}

/* _glGetTexGendv_Exec @ 0x9c620 (632 bytes) */
void _glGetTexGendv_Exec(glContext, coord, pname, params)
  int glContext;
  uint coord;
  uint pname;
  double *params;
{
  undefined4 glErrorCode;
  uint uVar2;
  int iVar3;
  float dVar4;
  
  uVar2 = *(uint *)(glContext + 0x53d4);
  if ((-1 < *(short *)(glContext + 0x4a10)) || (7 < uVar2)) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
    goto LAB_0009c714;
  }
  if (coord == 0x2001) {
    if (pname == 0x2501) {
      iVar3 = uVar2 * 0x94 + glContext + 0x3d10;
LAB_0009c790:
      *params = (double)*(float *)(iVar3 + 0x10);
      params[1] = (double)*(float *)(iVar3 + 0x14);
      params[2] = (double)*(float *)(iVar3 + 0x18);
      dVar4 = (double)*(float *)(iVar3 + 0x1c);
LAB_0009c6fc:
      params[3] = (double)dVar4;
      return;
    }
    if (pname < 0x2502) {
      if (pname == 0x2500) {
        uVar2 = (uint)*(ushort *)(uVar2 * 0x94 + glContext + 0x3d0c);
        goto LAB_0009c750;
      }
    }
    else if (pname == 0x2502) {
      iVar3 = uVar2 * 0x94 + glContext + 0x3d00;
      goto LAB_0009c790;
    }
  }
  else if (coord < 0x2002) {
    if (coord == 0x2000) {
      if (pname == 0x2501) {
        iVar3 = uVar2 * 0x94 + glContext + 0x3cf0;
LAB_0009c6e0:
        *params = (double)*(float *)(iVar3 + 0xc);
        params[1] = (double)*(float *)(iVar3 + 0x10);
        params[2] = (double)*(float *)(iVar3 + 0x14);
        dVar4 = (double)*(float *)(iVar3 + 0x18);
        goto LAB_0009c6fc;
      }
      if (pname < 0x2502) {
        if (pname == 0x2500) {
          uVar2 = (uint)*(ushort *)(uVar2 * 0x94 + glContext + 0x3ce8);
          goto LAB_0009c750;
        }
      }
      else if (pname == 0x2502) {
        iVar3 = uVar2 * 0x94 + glContext + 0x3ce0;
        goto LAB_0009c6e0;
      }
    }
  }
  else if (coord == 0x2002) {
    if (pname == 0x2501) {
      iVar3 = uVar2 * 0x94 + glContext + 0x3d30;
LAB_0009c804:
      *params = (double)*(float *)(iVar3 + 0x14);
      params[1] = (double)*(float *)(iVar3 + 0x18);
      params[2] = (double)*(float *)(iVar3 + 0x1c);
      dVar4 = (double)*(float *)(iVar3 + 0x20);
      goto LAB_0009c6fc;
    }
    if (pname < 0x2502) {
      if (pname == 0x2500) {
        uVar2 = (uint)*(ushort *)(uVar2 * 0x94 + glContext + 0x3d30);
LAB_0009c750:
        *params = (double)CONCAT44(0x43300000,uVar2) - DOUBLE_00108d70;
        return;
      }
    }
    else if (pname == 0x2502) {
      iVar3 = uVar2 * 0x94 + glContext + 0x3d20;
      goto LAB_0009c804;
    }
  }
  else if (coord == 0x2003) {
    if (pname == 0x2501) {
      iVar3 = uVar2 * 0x94 + glContext + 0x3d50;
LAB_0009c878:
      *params = (double)*(float *)(iVar3 + 0x18);
      params[1] = (double)*(float *)(iVar3 + 0x1c);
      params[2] = (double)*(float *)(iVar3 + 0x20);
      dVar4 = (double)*(float *)(iVar3 + 0x24);
      goto LAB_0009c6fc;
    }
    if (pname < 0x2502) {
      if (pname == 0x2500) {
        uVar2 = (uint)*(ushort *)(uVar2 * 0x94 + glContext + 0x3d54);
        goto LAB_0009c750;
      }
    }
    else if (pname == 0x2502) {
      iVar3 = uVar2 * 0x94 + glContext + 0x3d40;
      goto LAB_0009c878;
    }
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  glErrorCode = 0x500;
LAB_0009c714:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glGetTexGenfv_Exec @ 0x9c898 (620 bytes) */
void _glGetTexGenfv_Exec(int glContext,uint coord,uint pname,float *params,double unusedFloatArg1,double unusedFloatArg2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  float fVar1;
  undefined4 glErrorCode;
  uint uVar3;
  int iVar4;
  
  uVar3 = *(uint *)(glContext + 0x53d4);
  if ((-1 < *(short *)(glContext + 0x4a10)) || (7 < uVar3)) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
    goto LAB_0009c97c;
  }
  if (coord == 0x2001) {
    if (pname == 0x2501) {
      iVar4 = uVar3 * 0x94 + glContext + 0x3d10;
LAB_0009c9fc:
      *params = *(float *)(iVar4 + 0x10);
      params[1] = *(float *)(iVar4 + 0x14);
      params[2] = *(float *)(iVar4 + 0x18);
      fVar1 = *(float *)(iVar4 + 0x1c);
LAB_0009c964:
      params[3] = fVar1;
      return;
    }
    if (pname < 0x2502) {
      if (pname == 0x2500) {
        uVar3 = (uint)*(ushort *)(uVar3 * 0x94 + glContext + 0x3d0c);
        goto LAB_0009c9b8;
      }
    }
    else if (pname == 0x2502) {
      iVar4 = uVar3 * 0x94 + glContext + 0x3d00;
      goto LAB_0009c9fc;
    }
  }
  else if (coord < 0x2002) {
    if (coord == 0x2000) {
      if (pname == 0x2501) {
        iVar4 = uVar3 * 0x94 + glContext + 0x3cf0;
LAB_0009c948:
        *params = *(float *)(iVar4 + 0xc);
        params[1] = *(float *)(iVar4 + 0x10);
        params[2] = *(float *)(iVar4 + 0x14);
        fVar1 = *(float *)(iVar4 + 0x18);
        goto LAB_0009c964;
      }
      if (pname < 0x2502) {
        if (pname == 0x2500) {
          uVar3 = (uint)*(ushort *)(uVar3 * 0x94 + glContext + 0x3ce8);
          goto LAB_0009c9b8;
        }
      }
      else if (pname == 0x2502) {
        iVar4 = uVar3 * 0x94 + glContext + 0x3ce0;
        goto LAB_0009c948;
      }
    }
  }
  else if (coord == 0x2002) {
    if (pname == 0x2501) {
      iVar4 = uVar3 * 0x94 + glContext + 0x3d30;
LAB_0009ca70:
      *params = *(float *)(iVar4 + 0x14);
      params[1] = *(float *)(iVar4 + 0x18);
      params[2] = *(float *)(iVar4 + 0x1c);
      fVar1 = *(float *)(iVar4 + 0x20);
      goto LAB_0009c964;
    }
    if (pname < 0x2502) {
      if (pname == 0x2500) {
        uVar3 = (uint)*(ushort *)(uVar3 * 0x94 + glContext + 0x3d30);
LAB_0009c9b8:
        *params = GH_U2F((unsigned int)((uVar3 | 0x4b000000))) - 8388608.0;
        return;
      }
    }
    else if (pname == 0x2502) {
      iVar4 = uVar3 * 0x94 + glContext + 0x3d20;
      goto LAB_0009ca70;
    }
  }
  else if (coord == 0x2003) {
    if (pname == 0x2501) {
      iVar4 = uVar3 * 0x94 + glContext + 0x3d50;
LAB_0009cae4:
      *params = *(float *)(iVar4 + 0x18);
      params[1] = *(float *)(iVar4 + 0x1c);
      params[2] = *(float *)(iVar4 + 0x20);
      fVar1 = *(float *)(iVar4 + 0x24);
      goto LAB_0009c964;
    }
    if (pname < 0x2502) {
      if (pname == 0x2500) {
        uVar3 = (uint)*(ushort *)(uVar3 * 0x94 + glContext + 0x3d54);
        goto LAB_0009c9b8;
      }
    }
    else if (pname == 0x2502) {
      iVar4 = uVar3 * 0x94 + glContext + 0x3d40;
      goto LAB_0009cae4;
    }
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  glErrorCode = 0x500;
LAB_0009c97c:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glGetTexGeniv_Exec @ 0x9cb04 (744 bytes) */
void _glGetTexGeniv_Exec(glContext, coord, pname, params)
  int glContext;
  uint coord;
  uint pname;
  uint *params;
{
  float fVar1;
  undefined4 glErrorCode;
  uint uVar3;
  int iVar4;
  
  uVar3 = *(uint *)(glContext + 0x53d4);
  if ((-1 < *(short *)(glContext + 0x4a10)) || (7 < uVar3)) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
    goto LAB_0009cc18;
  }
  if (coord == 0x2001) {
    if (pname == 0x2501) {
      iVar4 = uVar3 * 0x94 + glContext + 0x3d10;
LAB_0009cc78:
      *params = (int)*(float *)(iVar4 + 0x10);
      params[1] = (int)*(float *)(iVar4 + 0x14);
      params[2] = (int)*(float *)(iVar4 + 0x18);
      fVar1 = *(float *)(iVar4 + 0x1c);
LAB_0009cbf4:
      params[3] = (int)fVar1;
      return;
    }
    if (pname < 0x2502) {
      if (pname == 0x2500) {
        uVar3 = (uint)*(ushort *)(uVar3 * 0x94 + glContext + 0x3d0c);
        goto LAB_0009cc54;
      }
    }
    else if (pname == 0x2502) {
      iVar4 = uVar3 * 0x94 + glContext + 0x3d00;
      goto LAB_0009cc78;
    }
  }
  else if (coord < 0x2002) {
    if (coord == 0x2000) {
      if (pname == 0x2501) {
        iVar4 = uVar3 * 0x94 + glContext + 0x3cf0;
LAB_0009cbb4:
        *params = (int)*(float *)(iVar4 + 0xc);
        params[1] = (int)*(float *)(iVar4 + 0x10);
        params[2] = (int)*(float *)(iVar4 + 0x14);
        fVar1 = *(float *)(iVar4 + 0x18);
        goto LAB_0009cbf4;
      }
      if (pname < 0x2502) {
        if (pname == 0x2500) {
          uVar3 = (uint)*(ushort *)(uVar3 * 0x94 + glContext + 0x3ce8);
          goto LAB_0009cc54;
        }
      }
      else if (pname == 0x2502) {
        iVar4 = uVar3 * 0x94 + glContext + 0x3ce0;
        goto LAB_0009cbb4;
      }
    }
  }
  else if (coord == 0x2002) {
    if (pname == 0x2501) {
      iVar4 = uVar3 * 0x94 + glContext + 0x3d30;
LAB_0009cd10:
      *params = (int)*(float *)(iVar4 + 0x14);
      params[1] = (int)*(float *)(iVar4 + 0x18);
      params[2] = (int)*(float *)(iVar4 + 0x1c);
      fVar1 = *(float *)(iVar4 + 0x20);
      goto LAB_0009cbf4;
    }
    if (pname < 0x2502) {
      if (pname == 0x2500) {
        uVar3 = (uint)*(ushort *)(uVar3 * 0x94 + glContext + 0x3d30);
LAB_0009cc54:
        *params = uVar3;
        return;
      }
    }
    else if (pname == 0x2502) {
      iVar4 = uVar3 * 0x94 + glContext + 0x3d20;
      goto LAB_0009cd10;
    }
  }
  else if (coord == 0x2003) {
    if (pname == 0x2501) {
      iVar4 = uVar3 * 0x94 + glContext + 0x3d50;
LAB_0009cda8:
      *params = (int)*(float *)(iVar4 + 0x18);
      params[1] = (int)*(float *)(iVar4 + 0x1c);
      params[2] = (int)*(float *)(iVar4 + 0x20);
      fVar1 = *(float *)(iVar4 + 0x24);
      goto LAB_0009cbf4;
    }
    if (pname < 0x2502) {
      if (pname == 0x2500) {
        uVar3 = (uint)*(ushort *)(uVar3 * 0x94 + glContext + 0x3d54);
        goto LAB_0009cc54;
      }
    }
    else if (pname == 0x2502) {
      iVar4 = uVar3 * 0x94 + glContext + 0x3d40;
      goto LAB_0009cda8;
    }
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  glErrorCode = 0x500;
LAB_0009cc18:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glCopyTexImage1D_ListExec @ 0x9cdec (68 bytes) */
undefined4 _glCopyTexImage1D_ListExec(undefined4 glContext,undefined4 *listRecord,double forwardedFloatArg1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
{
  ((void (*)())_glCopyTexImage1D_Exec)(glContext,*listRecord,listRecord[1],listRecord[2],listRecord[3],listRecord[4],listRecord[5],listRecord[6],
             forwardedFloatArg1,forwardedFloatArg2,forwardedFloatArg3,forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
  return 0x1c;
}

/* _glCopyTexImage1D_Comp @ 0x9ce30 (124 bytes) */
int _glCopyTexImage1D_Comp(glContext, target, level, internalformat, x, y, width, border)
  undefined4 glContext;
  undefined4 target;
  undefined4 level;
  undefined4 internalformat;
  undefined4 x;
  undefined4 y;
  undefined4 width;
  undefined4 border;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glCopyTexImage1D_ListExec_001103e8,0x1c);
  if (listRecord != (undefined4 *)0x0) {
    listRecord[6] = border;
    *listRecord = target;
    listRecord[1] = level;
    listRecord[2] = internalformat;
    listRecord[3] = x;
    listRecord[4] = y;
    listRecord[5] = width;
  }
  return listRecord;
}

/* _glCopyTexImage1D_Exec @ 0x9ceac (1592 bytes) */
void _glCopyTexImage1D_Exec(int glContext,undefined4 target,uint level,undefined4 internalformat,undefined4 x,undefined4 y,undefined4 width,undefined4 border,double fparam_1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
{
  bool bVar1;
  char cVar2;
  ushort uVar3;
  undefined4 uVar4;
  undefined4 glErrorCode;
  int *srcCursor;
  byte bVar6;
  int iVar7;
  int iVar8;
  int framebufferObject;
  undefined4 uVar9;
  undefined4 uVar10;
  int iVar11;
  int remaining;
  int loopIndex;
  uint uVar12;
  int *piVar13;
  int iVar14;
  double extraout_f1;
  
  if ((*(int *)(glContext + 0x744c) != 0) || (*(int *)(glContext + 0x310) < 0)) {
    iVar11 = *(int *)(glContext + 0x50ac);
    uVar12 = level;
    uVar4 = internalformat;
    uVar9 = x;
    uVar10 = y;
    if (iVar11 != 0 || (*(uint *)(glContext + 0x505c) & *(uint *)(glContext + 0x50b0)) != 0) {
      _gleUpdateMatrixFunc(glContext);
      fparam_1 = extraout_f1;
    }
    if (*(char *)(glContext + 0x4691) != '\0') {
      framebufferObject = *(int *)(glContext + 0x744c);
      piVar13 = (int *)(glContext + 0x310);
      cVar2 = *(char *)(*(int *)(glContext + 0x468c) + 0x79);
      if ((framebufferObject != 0) && (*(int *)(framebufferObject + 0xec) != 0)) {
        ((void (*)())_gleUpdateFramebufferCompleteness)(glContext,framebufferObject + 0x10,uVar12,uVar4,uVar9,uVar10,iVar11,fparam_1,forwardedFloatArg2,forwardedFloatArg3,
                   forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
        *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x80000000;
      }
      if ((*(char *)(glContext + 0x4664) == '\0') && (*(int *)(glContext + 0x5430) == 0)) {
LAB_0009cff4:
        uVar12 = *(uint *)(glContext + 0x31c);
      }
      else {
        loopIndex = 0;
        srcCursor = (int *)(glContext + 0x324);
        do {
          iVar8 = *srcCursor;
          srcCursor = srcCursor + 1;
          if (iVar8 != 0) {
            *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x800000;
            break;
          }
          loopIndex = loopIndex + 1;
        } while (loopIndex < 9);
        uVar12 = *(uint *)(glContext + 0x31c);
        if ((uVar12 & 0x15555) != 0) {
          if (*(char *)(glContext + 0x2e54) != '\0') {
            _gleUpdateLightRGBASums(glContext,glContext + 0x2c20,0);
          }
          if (*(char *)(glContext + 0x3094) != '\0') {
            _gleUpdateLightRGBASums(glContext,glContext + 0x2e60,1);
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
        bVar1 = ((*piVar13 == 0 && *(int *)(glContext + 0x314) == 0) && uVar12 == 0) &&
                *(int *)(glContext + 800) == 0;
      }
      else {
        bVar1 = (((*piVar13 == 0 && *(int *)(glContext + 0x314) == 0) &&
                 (*(uint *)(glContext + 0x318) & 0xfffffffd) == 0) && uVar12 == 0) &&
                *(int *)(glContext + 800) == 0;
      }
      if (!bVar1) {
        if (*(char *)(glContext + 0x85a8) == *(char *)(glContext + 0x85a6)) {
          uVar12 = (**(code **)(glContext + 0x4788))
                             (*(undefined4 *)(glContext + 0x4688),glContext + 0x4698,piVar13);
          if ((((uVar12 & 3) != (uint)*(byte *)(glContext + 0x7580)) ||
              ((uVar12 & 4) != (uint)*(byte *)(glContext + 0x7581))) ||
             ((uVar12 & 8) != (uint)(*(char *)(glContext + 0x759d) == '\0'))) {
            if ((uVar12 & 4) == 0) {
              uVar12 = uVar12 & 0xfffffffe;
              *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x10000000;
            }
            _gleUpdateDispatchCodeChange(glContext,uVar12);
            if (*(char *)(glContext + 0x759d) == '\0') {
              if (*(int *)(glContext + 0x7574) != 0) {
                return;
              }
              glErrorCode = 0x506;
              goto LAB_0009d188;
            }
          }
        }
        else {
          _gleSwitchToNonRevertRenderer(glContext);
        }
        remaining = 0x13;
        do {
          *piVar13 = 0;
          piVar13 = piVar13 + 1;
          remaining = remaining + -1;
        } while (remaining != 0);
      }
    }
  }
  if (*(short *)(glContext + 0x4a10) < 0) {
    iVar11 = _gleCheckCopyTexImage1DArgs(glContext,target,level,internalformat,width,border);
    if (iVar11 == 0) {
      return;
    }
    uVar3 = *(ushort *)(iVar11 + 0x24);
    if ((uVar3 & 0x3c00) == 0x1000) {
LAB_0009d190:
      iVar8 = iVar11 + level * 0x18;
      iVar14 = iVar8 + 0xc4;
      if ((*(byte *)(iVar8 + 0xcf) & 0x20) != 0) {
        _gleDeletePluginTextureLevel(glContext,iVar11,iVar14,0,level);
        if (*(int *)(iVar8 + 0xd8) != 0) {
          bVar6 = *(byte *)(iVar8 + 0xcf);
          if ((bVar6 & 1) == 0) {
            _gleFreeTextureLevel(glContext,iVar11,iVar14);
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
                        (glContext,iVar11,iVar14,internalformat,width,1,1,border,0x1908,0x1401,0,0);
      if (iVar7 != 0) {
        _gleCreatePluginTextureLevel(glContext,iVar11,iVar14,0,level,internalformat);
        if ((((int)(uint)*(byte *)(iVar11 + 0x8d) <= (int)level) &&
            ((int)level <= (int)(uint)*(byte *)(iVar11 + 0x8f))) &&
           (((*(ushort *)(iVar11 + 0x94) >> (level & 0x3f) & 1) != 0 &&
            (iVar7 = (**(code **)(glContext + 0x470c))
                               (*(undefined4 *)(glContext + 0x4688),
                                *(undefined4 *)(iVar11 + (uint)*(byte *)(glContext + 0x85a8) * 4),0,
                                level,0,0,0,x), iVar7 != 0)))) {
          *(undefined4 *)(iVar11 + 0x20) =
               *(undefined4 *)
                ((uint)*(byte *)(glContext + 0x85a8) * 4 + *(int *)(glContext + 0x5148) + 0x8054);
          *(byte *)(iVar8 + 0xcf) = *(byte *)(iVar8 + 0xcf) | 0x40;
          if ((*(uint *)(iVar11 + 0x6c) & 0x8000) == 0) {
            return;
          }
          if ((int)*(short *)(iVar11 + 0x60) != level) {
            return;
          }
          uVar12 = level + 1;
          if ((int)(uint)*(byte *)(iVar11 + 0x83) < (int)uVar12) {
            return;
          }
          iVar8 = uVar12 * 0x18 + iVar11 + 0xc4;
          do {
            if (*(int *)(iVar8 + 0x14) != 0) {
              if (((*(byte *)(iVar8 + 0xb) & 1) == 0) && (*(short *)(iVar11 + 0x3e) == -0x7a43)) {
                _gleFreeTextureLevel(glContext,iVar11,iVar8);
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
              _gleAllocateTextureLevel(glContext,iVar11,iVar14);
              bVar6 = *(byte *)(iVar8 + 0xcf);
            }
            *(byte *)(iVar8 + 0xcf) = bVar6 | 0x10;
          }
          else {
            _gleUploadPluginTextureLevel
                      (glContext,iVar11,iVar14,0,level,(uint)*(byte *)(glContext + 0x85a8));
          }
        }
        _gleModifyPluginTextureLevel(glContext,iVar11,iVar14,0,level,0,0,0,width,1,1);
        _gleTextureImageCopy(glContext,iVar14,internalformat,x,y,width,1);
        if ((((*(uint *)(iVar11 + 0x6c) & 0x8000) != 0) &&
            ((int)*(short *)(iVar11 + 0x60) == level)) &&
           (iVar11 = _gleGenMipmapsToLevel(glContext,iVar11,0,level,0xf,1), iVar11 != 0)) {
          return;
        }
      }
      *(uint *)(glContext + 0x314) =
           *(uint *)(glContext + 0x314) | 1 << (*(uint *)(glContext + 0x53d4) & 0x3f);
      return;
    }
    if ((uVar3 & 0x3c00) == 0) {
      *(ushort *)(iVar11 + 0x24) = uVar3 | 0x1000;
      goto LAB_0009d190;
    }
    if ((uVar3 & 0xc00) == 0) goto LAB_0009d190;
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  glErrorCode = 0x502;
LAB_0009d188:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glCopyTexImage1D_CompExec @ 0x9d4e4 (104 bytes) */
void _glCopyTexImage1D_CompExec(glContext, target, level, internalformat, x, y, width, border)
  undefined4 glContext;
  undefined4 target;
  undefined4 level;
  undefined4 internalformat;
  undefined4 x;
  undefined4 y;
  undefined4 width;
  undefined4 border;
{
  double fparam_1;
  double in_f2;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  
  ((int (*)())_glCopyTexImage1D_Comp)(glContext,target,level,internalformat,x,y,width,border);
  ((void (*)())_glCopyTexImage1D_Exec)(glContext,target,level,internalformat,x,y,width,border,fparam_1,in_f2,in_f3,
             in_f4,in_f5,in_f6,in_f7,in_f8);
  return;
}

/* _glCopyTexImage1D_NoopExec @ 0x9d54c (688 bytes) */
void _glCopyTexImage1D_NoopExec(int glContext,undefined4 forwardedArg2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 forwardedArg8,double fparam_1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
{
  bool bVar1;
  char cVar2;
  int iVar3;
  int *srcCursor;
  int framebufferObject;
  int remaining;
  int loopIndex;
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
  if (*(int *)(glContext + 0x50ac) != 0 ||
      (*(uint *)(glContext + 0x505c) & *(uint *)(glContext + 0x50b0)) != 0) {
    _gleUpdateMatrixFunc(glContext);
    fparam_1 = extraout_f1;
  }
  if (*(char *)(glContext + 0x4691) != '\0') {
    framebufferObject = *(int *)(glContext + 0x744c);
    piVar12 = (int *)(glContext + 0x310);
    cVar2 = *(char *)(*(int *)(glContext + 0x468c) + 0x79);
    if ((framebufferObject != 0) && (*(int *)(framebufferObject + 0xec) != 0)) {
      ((void (*)())_gleUpdateFramebufferCompleteness)(glContext,framebufferObject + 0x10,uVar6,uVar7,uVar8,uVar9,uVar10,fparam_1,forwardedFloatArg2,forwardedFloatArg3,
                 forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
      *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x80000000;
      fparam_1 = fparam_1;
    }
    if ((*(char *)(glContext + 0x4664) == '\0') && (*(int *)(glContext + 0x5430) == 0)) {
LAB_0009d67c:
      uVar11 = *(uint *)(glContext + 0x31c);
    }
    else {
      loopIndex = 0;
      srcCursor = (int *)(glContext + 0x324);
      do {
        iVar3 = *srcCursor;
        srcCursor = srcCursor + 1;
        if (iVar3 != 0) {
          *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x800000;
          break;
        }
        loopIndex = loopIndex + 1;
      } while (loopIndex < 9);
      uVar11 = *(uint *)(glContext + 0x31c);
      if ((uVar11 & 0x15555) != 0) {
        if (*(char *)(glContext + 0x2e54) != '\0') {
          fparam_1 = (double)_gleUpdateLightRGBASums(glContext,glContext + 0x2c20,0);
        }
        if (*(char *)(glContext + 0x3094) != '\0') {
          fparam_1 = (double)_gleUpdateLightRGBASums(glContext,glContext + 0x2e60,1);
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
      bVar1 = ((*piVar12 == 0 && *(int *)(glContext + 0x314) == 0) && uVar11 == 0) &&
              *(int *)(glContext + 800) == 0;
    }
    else {
      bVar1 = (((*piVar12 == 0 && *(int *)(glContext + 0x314) == 0) &&
               (*(uint *)(glContext + 0x318) & 0xfffffffd) == 0) && uVar11 == 0) &&
              *(int *)(glContext + 800) == 0;
    }
    if (!bVar1) {
      if (*(char *)(glContext + 0x85a8) == *(char *)(glContext + 0x85a6)) {
        uVar11 = (**(code **)(glContext + 0x4788))
                           (*(undefined4 *)(glContext + 0x4688),glContext + 0x4698,piVar12);
        if ((((uVar11 & 3) != (uint)*(byte *)(glContext + 0x7580)) ||
            ((uVar11 & 4) != (uint)*(byte *)(glContext + 0x7581))) ||
           (fparam_1 = extraout_f1_01, (uVar11 & 8) != (uint)(*(char *)(glContext + 0x759d) == '\0')))
        {
          if ((uVar11 & 4) == 0) {
            uVar11 = uVar11 & 0xfffffffe;
            *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x10000000;
          }
          fparam_1 = (double)_gleUpdateDispatchCodeChange(glContext,uVar11);
          if (*(char *)(glContext + 0x759d) == '\0') goto LAB_0009d79c;
        }
      }
      else {
        fparam_1 = (double)_gleSwitchToNonRevertRenderer(glContext);
      }
      remaining = 0x13;
      do {
        *piVar12 = 0;
        piVar12 = piVar12 + 1;
        remaining = remaining + -1;
      } while (remaining != 0);
    }
  }
  if (*(char *)(glContext + 0x759d) != '\0') {
    ((void (*)())_glCopyTexImage1D_Exec)(glContext,forwardedArg2,param_3,param_4,param_5,param_6,param_7,forwardedArg8,fparam_1,forwardedFloatArg2,
               forwardedFloatArg3,forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
    return;
  }
LAB_0009d79c:
  if (*(int *)(glContext + 0x7574) == 0) {
    *(undefined4 *)(glContext + 0x7574) = 0x506;
  }
  return;
}

/* _glCopyTexImage2D_ListExec @ 0x9d7fc (76 bytes) */
undefined4 _glCopyTexImage2D_ListExec(undefined4 glContext,undefined4 *listRecord,double forwardedFloatArg1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
{
  ((void (*)())_glCopyTexImage2D_Exec)(glContext,*listRecord,listRecord[1],listRecord[2],listRecord[3],listRecord[4],listRecord[5],listRecord[6],
             listRecord[7],forwardedFloatArg1,forwardedFloatArg2,forwardedFloatArg3,forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
  return 0x20;
}

/* _glCopyTexImage2D_Comp @ 0x9d848 (132 bytes) */
int _glCopyTexImage2D_Comp(glContext, target, level, internalformat, x, y, width, height, border)
  undefined4 glContext;
  undefined4 target;
  undefined4 level;
  undefined4 internalformat;
  undefined4 x;
  undefined4 y;
  undefined4 width;
  undefined4 height;
  undefined4 border;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glCopyTexImage2D_ListExec_001103e4,0x20);
  if (listRecord != (undefined4 *)0x0) {
    *listRecord = target;
    listRecord[7] = border;
    listRecord[1] = level;
    listRecord[2] = internalformat;
    listRecord[3] = x;
    listRecord[4] = y;
    listRecord[5] = width;
    listRecord[6] = height;
  }
  return listRecord;
}

/* _glCopyTexImage2D_CompExec @ 0x9d8cc (116 bytes) */
void _glCopyTexImage2D_CompExec(glContext, target, level, internalformat, x, y, width, height, border)
  undefined4 glContext;
  undefined4 target;
  undefined4 level;
  undefined4 internalformat;
  undefined4 x;
  undefined4 y;
  undefined4 width;
  undefined4 height;
  undefined4 border;
{
  double fparam_1;
  double in_f2;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  
  ((int (*)())_glCopyTexImage2D_Comp)(glContext,target,level,internalformat,x,y,width,height,border);
  ((void (*)())_glCopyTexImage2D_Exec)(glContext,target,level,internalformat,x,y,width,height,border,fparam_1,in_f2,
             in_f3,in_f4,in_f5,in_f6,in_f7,in_f8);
  return;
}

/* _glCopyTexImage2D_NoopExec @ 0x9d940 (696 bytes) */
void _glCopyTexImage2D_NoopExec(int glContext,undefined4 forwardedArg2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 forwardedArg8,undefined4 forwardedArg9,double fparam_1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
{
  bool bVar1;
  char cVar2;
  int iVar3;
  int *srcCursor;
  int framebufferObject;
  int remaining;
  int loopIndex;
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
  if (*(int *)(glContext + 0x50ac) != 0 ||
      (*(uint *)(glContext + 0x505c) & *(uint *)(glContext + 0x50b0)) != 0) {
    _gleUpdateMatrixFunc(glContext);
    fparam_1 = extraout_f1;
  }
  if (*(char *)(glContext + 0x4691) != '\0') {
    framebufferObject = *(int *)(glContext + 0x744c);
    piVar12 = (int *)(glContext + 0x310);
    cVar2 = *(char *)(*(int *)(glContext + 0x468c) + 0x79);
    if ((framebufferObject != 0) && (*(int *)(framebufferObject + 0xec) != 0)) {
      ((void (*)())_gleUpdateFramebufferCompleteness)(glContext,framebufferObject + 0x10,uVar6,uVar7,uVar8,uVar9,uVar10,fparam_1,forwardedFloatArg2,forwardedFloatArg3,
                 forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
      *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x80000000;
      fparam_1 = fparam_1;
    }
    if ((*(char *)(glContext + 0x4664) == '\0') && (*(int *)(glContext + 0x5430) == 0)) {
LAB_0009da74:
      uVar11 = *(uint *)(glContext + 0x31c);
    }
    else {
      loopIndex = 0;
      srcCursor = (int *)(glContext + 0x324);
      do {
        iVar3 = *srcCursor;
        srcCursor = srcCursor + 1;
        if (iVar3 != 0) {
          *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x800000;
          break;
        }
        loopIndex = loopIndex + 1;
      } while (loopIndex < 9);
      uVar11 = *(uint *)(glContext + 0x31c);
      if ((uVar11 & 0x15555) != 0) {
        if (*(char *)(glContext + 0x2e54) != '\0') {
          fparam_1 = (double)_gleUpdateLightRGBASums(glContext,glContext + 0x2c20,0);
        }
        if (*(char *)(glContext + 0x3094) != '\0') {
          fparam_1 = (double)_gleUpdateLightRGBASums(glContext,glContext + 0x2e60,1);
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
      bVar1 = ((*piVar12 == 0 && *(int *)(glContext + 0x314) == 0) && uVar11 == 0) &&
              *(int *)(glContext + 800) == 0;
    }
    else {
      bVar1 = (((*piVar12 == 0 && *(int *)(glContext + 0x314) == 0) &&
               (*(uint *)(glContext + 0x318) & 0xfffffffd) == 0) && uVar11 == 0) &&
              *(int *)(glContext + 800) == 0;
    }
    if (!bVar1) {
      if (*(char *)(glContext + 0x85a8) == *(char *)(glContext + 0x85a6)) {
        uVar11 = (**(code **)(glContext + 0x4788))
                           (*(undefined4 *)(glContext + 0x4688),glContext + 0x4698,piVar12);
        if ((((uVar11 & 3) != (uint)*(byte *)(glContext + 0x7580)) ||
            ((uVar11 & 4) != (uint)*(byte *)(glContext + 0x7581))) ||
           (fparam_1 = extraout_f1_01, (uVar11 & 8) != (uint)(*(char *)(glContext + 0x759d) == '\0')))
        {
          if ((uVar11 & 4) == 0) {
            uVar11 = uVar11 & 0xfffffffe;
            *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x10000000;
          }
          fparam_1 = (double)_gleUpdateDispatchCodeChange(glContext,uVar11);
          if (*(char *)(glContext + 0x759d) == '\0') goto LAB_0009db94;
        }
      }
      else {
        fparam_1 = (double)_gleSwitchToNonRevertRenderer(glContext);
      }
      remaining = 0x13;
      do {
        *piVar12 = 0;
        piVar12 = piVar12 + 1;
        remaining = remaining + -1;
      } while (remaining != 0);
    }
  }
  if (*(char *)(glContext + 0x759d) != '\0') {
    ((void (*)())_glCopyTexImage2D_Exec)(glContext,forwardedArg2,param_3,param_4,param_5,param_6,param_7,forwardedArg8,forwardedArg9,fparam_1,
               forwardedFloatArg2,forwardedFloatArg3,forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
    return;
  }
LAB_0009db94:
  if (*(int *)(glContext + 0x7574) == 0) {
    *(undefined4 *)(glContext + 0x7574) = 0x506;
  }
  return;
}

