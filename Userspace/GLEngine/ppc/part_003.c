#include "decls.h"

/* _gleShrinkFuncCacheElem @ 0x1ecb8 (88 bytes) */
int _gleShrinkFuncCacheElem(param_1, param_2)
  int param_1;
  int param_2;
{
  int *piVar1;
  
  piVar1 = (int *)_gleDCBRealloc(param_1,param_2 * 4 + 0x20);
  if (*piVar1 == param_1) {
    piVar1[1] = (int)piVar1;
    *piVar1 = (int)piVar1;
  }
  else {
    *(int **)(*piVar1 + 4) = piVar1;
    *(int **)piVar1[1] = piVar1;
  }
  return (int)piVar1;
}

/* _glEndNoMat_Exec @ 0x1ed10 (64 bytes) */
void _glEndNoMat_Exec(glContext)
  int glContext;
{
  if (-1 < *(short *)(glContext + 0x4a10)) {
    *(undefined2 *)(glContext + 0x4a10) = 0xffff;
    *(undefined4 *)(glContext + 0x4884) = *(undefined4 *)(glContext + 0xd8);
                    
                    
    (**(int ( **)(int))(glContext + 0x4a08))(glContext);
    return;
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  *(undefined4 *)(glContext + 0x7574) = 0x502;
  return;
}

/* _glFlush_Exec @ 0x1ee38 (652 bytes) */
void _glFlush_Exec(int glContext,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  int remaining;
  int loopIndex;
  bool bVar1;
  char cVar2;
  undefined4 glErrorCode;
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
  
  if (-1 < *(short *)(glContext + 0x4a10)) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
    goto LAB_0001f064;
  }
  iVar6 = *(int *)(glContext + 0x50ac);
  if (iVar6 != 0 || (*(uint *)(glContext + 0x505c) & *(uint *)(glContext + 0x50b0)) != 0) {
    _gleUpdateMatrixFunc(glContext);
    fparam_1 = extraout_f1;
  }
  if (*(char *)(glContext + 0x4691) == '\0') goto LAB_0001f090;
  iVar5 = *(int *)(glContext + 0x744c);
  piVar8 = (int *)(glContext + 0x310);
  cVar2 = *(char *)(*(int *)(glContext + 0x468c) + 0x79);
  if ((iVar5 != 0) && (*(int *)(iVar5 + 0xec) != 0)) {
    ((void (*)())_gleUpdateFramebufferCompleteness)(glContext,iVar5 + 0x10,in_r5,in_r6,in_r7,in_r8,iVar6,fparam_1,fparam_2,fparam_3,
               fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
    *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x80000000;
  }
  if ((*(char *)(glContext + 0x4664) == '\0') && (*(int *)(glContext + 0x5430) == 0)) {
LAB_0001ef68:
    uVar7 = *(uint *)(glContext + 0x31c);
  }
  else {
    loopIndex = 0;
    piVar4 = (int *)(glContext + 0x324);
    do {
      iVar5 = *piVar4;
      piVar4 = piVar4 + 1;
      if (iVar5 != 0) {
        *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x800000;
        break;
      }
      loopIndex = loopIndex + 1;
    } while (loopIndex < 9);
    uVar7 = *(uint *)(glContext + 0x31c);
    if ((uVar7 & 0x15555) != 0) {
      if (*(char *)(glContext + 0x2e54) != '\0') {
        _gleUpdateLightRGBASums(glContext,glContext + 0x2c20,0);
      }
      if (*(char *)(glContext + 0x3094) != '\0') {
        _gleUpdateLightRGBASums(glContext,glContext + 0x2e60,1);
      }
      goto LAB_0001ef68;
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
    bVar1 = ((*piVar8 == 0 && *(int *)(glContext + 0x314) == 0) && uVar7 == 0) &&
            *(int *)(glContext + 800) == 0;
  }
  else {
    bVar1 = (((*piVar8 == 0 && *(int *)(glContext + 0x314) == 0) &&
             (*(uint *)(glContext + 0x318) & 0xfffffffd) == 0) && uVar7 == 0) &&
            *(int *)(glContext + 800) == 0;
  }
  if (!bVar1) {
    if (*(char *)(glContext + 0x85a8) == *(char *)(glContext + 0x85a6)) {
      uVar7 = (**(code **)(glContext + 0x4788))
                        (*(undefined4 *)(glContext + 0x4688),glContext + 0x4698,piVar8);
      if ((((uVar7 & 3) != (uint)*(byte *)(glContext + 0x7580)) ||
          ((uVar7 & 4) != (uint)*(byte *)(glContext + 0x7581))) ||
         ((uVar7 & 8) != (uint)(*(char *)(glContext + 0x759d) == '\0'))) {
        if ((uVar7 & 4) == 0) {
          uVar7 = uVar7 & 0xfffffffe;
          *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x10000000;
        }
        _gleUpdateDispatchCodeChange(glContext,uVar7);
        if (*(char *)(glContext + 0x759d) == '\0') {
          if (*(int *)(glContext + 0x7574) != 0) {
            return;
          }
          glErrorCode = 0x506;
LAB_0001f064:
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
      *piVar8 = 0;
      piVar8 = piVar8 + 1;
      remaining = remaining + -1;
    } while (remaining != 0);
  }
LAB_0001f090:
                    
                    
  (**(code **)(glContext + 0x46f4))(*(undefined4 *)(glContext + 0x4688));
  return;
}

/* _glTexSubImage2D_Exec @ 0x1f0c4 (1364 bytes) */
int _glTexSubImage2D_Exec(glContext, target, level, xoffset, yoffset, width, height, format, type, pixels)
  int glContext;
  int target;
  uint level;
  int xoffset;
  int yoffset;
  int width;
  int height;
  undefined4 format;
  undefined4 type;
  int pixels;
{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  byte bVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  double dVar12;
  
  iVar3 = glContext;
  if (-1 < *(short *)(glContext + 0x4a10)) goto LAB_0001f180;
  iVar9 = *(int *)(glContext + 0x4a6c);
  if (iVar9 != 0) {
    iVar2 = _gleOffsetLimitImage(glContext + 0x31cc,width,height,format,type,pixels);
    iVar11 = *(int *)(iVar9 + 0x38);
    dVar12 = (double)((double (*)())_gleBytesPerElement)(type);
    iVar3 = (int)dVar12;
    if (iVar11 < iVar2) {
LAB_0001f180:
      if (*(int *)(glContext + 0x7574) == 0) {
        *(undefined4 *)(glContext + 0x7574) = 0x502;
      }
      return iVar3;
    }
    if (iVar3 == 0) {
      iVar3 = _glePixelBytes(format,type);
    }
    if (pixels != (pixels / iVar3) * iVar3) goto LAB_0001f180;
    pixels = pixels + *(int *)(iVar9 + 0x30);
  }
  if (width == 0) {
    return iVar3;
  }
  if (height == 0) {
    return iVar3;
  }
  iVar3 = ((int (*)())_gleCheckTexSubImage2DArgs)(glContext,target,level,xoffset,yoffset,width,height,format,type);
  if (iVar3 == 0) {
    return 0;
  }
  uVar1 = target - 0x8515;
  if (5 < uVar1) {
    uVar1 = 0;
  }
  iVar2 = iVar3 + uVar1 * 0x168 + level * 0x18;
  iVar10 = iVar2 + 0xc4;
  iVar11 = ((int (*)())_checkFastPath)(glContext,iVar10,xoffset,yoffset,0,width,height,format,type,pixels)
  ;
  if ((((iVar11 != 0) && ((int)(uint)*(byte *)(iVar3 + 0x8d) <= (int)level)) &&
      ((int)level <= (int)(uint)*(byte *)(iVar3 + 0x8f))) &&
     (iVar11 = uVar1 * 2, (*(ushort *)(iVar11 + iVar3 + 0x94) >> (level & 0x3f) & 1) != 0)) {
    if (iVar9 == 0) {
      uVar5 = *(undefined4 *)(glContext + 0x4688);
      uVar6 = *(undefined4 *)(iVar3 + (uint)*(byte *)(glContext + 0x85a8) * 4);
    }
    else {
      iVar4 = (**(code **)(glContext + 0x4710))
                        (*(undefined4 *)(glContext + 0x4688),
                         *(undefined4 *)(iVar3 + (uint)*(byte *)(glContext + 0x85a8) * 4),uVar1,
                         level,xoffset,yoffset,0,width);
      if (iVar4 != 0) goto LAB_0001f388;
      if (*(int *)(iVar9 + 0x40) != 0) {
        _gleSynchronizePluginBuffer(glContext,iVar9 + 0x10);
      }
      uVar5 = *(undefined4 *)(glContext + 0x4688);
      uVar6 = *(undefined4 *)(iVar3 + (uint)*(byte *)(glContext + 0x85a8) * 4);
    }
    iVar4 = (**(code **)(glContext + 0x4710))(uVar5,uVar6,uVar1,level,xoffset,yoffset,0,width);
    if (iVar4 != 0) {
LAB_0001f388:
      *(undefined4 *)(iVar3 + 0x20) =
           *(undefined4 *)
            ((uint)*(byte *)(glContext + 0x85a8) * 4 + *(int *)(glContext + 0x5148) + 0x8054);
      if (*(int *)(iVar2 + 0xd8) != 0) {
        bVar7 = *(byte *)(iVar2 + 0xcf);
        if (((bVar7 & 1) == 0) && (*(short *)(iVar3 + 0x3e) == -0x7a43)) {
          iVar4 = _gleFreeTextureLevel(glContext,iVar3,iVar10);
          bVar7 = *(byte *)(iVar2 + 0xcf);
        }
        *(byte *)(iVar2 + 0xcf) = bVar7 & 0xef;
        *(ushort *)(iVar11 + iVar3 + 0xa0) =
             *(ushort *)(iVar11 + iVar3 + 0xa0) &
             ((ushort)(-2 << (level & 0x1f)) | (ushort)(0xfffffffe >> 0x20 - (level & 0x1f)));
      }
      *(byte *)(iVar2 + 0xcf) = *(byte *)(iVar2 + 0xcf) | 0x40;
      if ((*(uint *)(iVar3 + 0x6c) & 0x8000) == 0) {
        return iVar4;
      }
      if ((int)*(short *)(iVar3 + 0x60) != level) {
        return iVar4;
      }
      uVar8 = level + 1;
      if ((int)(uint)*(byte *)(iVar3 + 0x83) < (int)uVar8) {
        return iVar4;
      }
      iVar9 = uVar8 * 0x18 + uVar1 * 0x168 + iVar3 + 0xc4;
      do {
        if (*(int *)(iVar9 + 0x14) != 0) {
          if (((*(byte *)(iVar9 + 0xb) & 1) == 0) && (*(short *)(iVar3 + 0x3e) == -0x7a43)) {
            iVar4 = _gleFreeTextureLevel(glContext,iVar3,iVar9);
          }
          *(byte *)(iVar9 + 0xb) = *(byte *)(iVar9 + 0xb) & 0xef;
          *(ushort *)(iVar11 + iVar3 + 0xa0) =
               *(ushort *)(iVar11 + iVar3 + 0xa0) & ~(ushort)(1 << (uVar8 & 0x3f));
        }
        uVar8 = uVar8 + 1;
        *(byte *)(iVar9 + 0xb) = *(byte *)(iVar9 + 0xb) | 0x40;
        iVar9 = iVar9 + 0x18;
      } while ((int)uVar8 <= (int)(uint)*(byte *)(iVar3 + 0x83));
      return iVar4;
    }
  }
  bVar7 = *(byte *)(iVar2 + 0xcf);
  if ((bVar7 & 0x10) == 0) {
    if ((bVar7 & 0x40) == 0) {
      if (*(int *)(iVar2 + 0xd8) == 0) {
        _gleAllocateTextureLevel(glContext,iVar3,iVar10);
        bVar7 = *(byte *)(iVar2 + 0xcf);
      }
      *(byte *)(iVar2 + 0xcf) = bVar7 | 0x10;
    }
    else {
      _gleUploadPluginTextureLevel
                (glContext,iVar3,iVar10,uVar1,level,(uint)*(byte *)(glContext + 0x85a8));
    }
  }
  ((int (*)())_gleModifyPluginTextureLevel)(glContext,iVar3,iVar10,uVar1,level,xoffset,yoffset,0,width,height,1);
  uVar5 = _gleTextureImagePut(glContext,iVar10,xoffset + (uint)*(byte *)(iVar2 + 0xce),
                              yoffset + (uint)*(byte *)(iVar2 + 0xce),0,width,height,1,format,
                              type,1,glContext + 0x31cc,pixels);
  if ((((*(uint *)(iVar3 + 0x6c) & 0x8000) != 0) && ((int)*(short *)(iVar3 + 0x60) == level)) &&
     (iVar3 = _gleGenMipmapsToLevel(glContext,iVar3,uVar1,level,0xf,1), uVar5 = 0, iVar3 != 0)) {
    return iVar3;
  }
  *(uint *)(glContext + 0x314) =
       *(uint *)(glContext + 0x314) | 1 << (*(uint *)(glContext + 0x53d4) & 0x3f);
  return uVar5;
}

/* _gleCheckTexSubImage2DArgs @ 0x1f618 (484 bytes) */
int _gleCheckTexSubImage2DArgs(glContext, target, level, xoffset, yoffset, width, height, format, type)
  int glContext;
  int target;
  int level;
  uint xoffset;
  uint yoffset;
  uint width;
  uint height;
  int format;
  undefined4 type;
{
  undefined4 glErrorCode;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar3 = ((int (*)())_gleLookUpNonProxyTexture2D)(glContext,target);
  if (iVar3 == 0) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return 0;
    }
    glErrorCode = 0x500;
  }
  else {
    if ((format != 0x1902) || (*(short *)(iVar3 + 0x26) == 0x1902)) {
      iVar4 = _gleCheckTexSubImageArgs(glContext,level,format,type);
      if (iVar4 == 0) {
        return 0;
      }
      iVar4 = iVar3 + 0xc4 + level * 0x18;
      if (target - 0x8515U < 6) {
        iVar4 = iVar3 + 0xc4 + target * 0x168 + level * 0x18 + -0xbb2588;
      }
      if (((*(byte *)(iVar4 + 0xb) & 0x20) != 0) &&
         ((*(short *)(iVar4 + 0x12) != 0 ||
          (((((width & 3) == 0 || (width == *(ushort *)(iVar4 + 4))) &&
            (((height & 3) == 0 || (height == *(ushort *)(iVar4 + 6))))) &&
           (((xoffset & 3) == 0 && ((yoffset & 3) == 0)))))))) {
        if ((*(uint *)(glContext + 0x3410) & 2) == 0) {
          if (((*(uint *)(glContext + 0x3410) & 4) == 0) || (*(short *)(glContext + 0x3348) != -0x7fea))
          goto LAB_0001f79c;
          iVar5 = *(int *)(glContext + 0x3354);
          iVar2 = *(int *)(glContext + 0x3350);
        }
        else {
          if (*(short *)(glContext + 0x3308) != -0x7fea) goto LAB_0001f79c;
          iVar5 = *(int *)(glContext + 0x3314);
          iVar2 = *(int *)(glContext + 0x3310);
        }
        width = (width - iVar2) + 1;
        height = (height - iVar5) + 1;
LAB_0001f79c:
        iVar2 = ((int (*)())_gleCheckTexSubImageRange)(glContext,iVar4,xoffset,width,(uint)*(ushort *)(iVar4 + 4));
        if (iVar2 == 0) {
          return 0;
        }
        iVar4 = ((int (*)())_gleCheckTexSubImageRange)(glContext,iVar4,yoffset,height,(uint)*(ushort *)(iVar4 + 6));
        if (iVar4 != 0) {
          return iVar3;
        }
        return 0;
      }
    }
    if (*(int *)(glContext + 0x7574) != 0) {
      return 0;
    }
    glErrorCode = 0x502;
  }
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return 0;
}

/* _gleLookUpNonProxyTexture2D @ 0x1f7fc (144 bytes) */
int _gleLookUpNonProxyTexture2D(glContext, target)
  int glContext;
  uint target;
{
  uint uVar1;
  int iVar2;
  
  iVar2 = *(int *)(glContext + 0x53d4);
  if (target == 0x8513) {
LAB_0001f860:
    iVar2 = *(int *)(iVar2 * 0x14 + glContext + 0x5154);
  }
  else {
    if (target < 0x8514) {
      if (target == 0xde1) {
        iVar2 = *(int *)(iVar2 * 0x14 + glContext + 0x5160);
        goto LAB_0001f86c;
      }
      uVar1 = 0x84f5;
    }
    else {
      if (target < 0x8515) {
        return 0;
      }
      if (target < 0x851b) goto LAB_0001f860;
      uVar1 = 0x85b3;
    }
    if (target != uVar1) {
      return 0;
    }
    iVar2 = *(int *)(iVar2 * 0x14 + glContext + 0x515c);
  }
LAB_0001f86c:
  return iVar2 + 0x10;
}

/* _gleCheckTexSubImageRange @ 0x1f88c (76 bytes) */
int _gleCheckTexSubImageRange(glContext, param_2, param_3, param_4, param_5)
  int glContext;
  int param_2;
  int param_3;
  int param_4;
  int param_5;
{
  if (((-1 < param_4) && ((int)-(uint)*(byte *)(param_2 + 10) <= param_3)) &&
     (param_3 + param_4 <= (int)(param_5 + (uint)*(byte *)(param_2 + 10)))) {
    return 1;
  }
  if (*(int *)(glContext + 0x7574) == 0) {
    *(undefined4 *)(glContext + 0x7574) = 0x501;
  }
  return 0;
}

/* _checkFastPath @ 0x1f8d8 (260 bytes) */
int _checkFastPath(glContext, param_2, xoffset, yoffset, param_5, width, height, format, type, pixels)
  int glContext;
  int param_2;
  int xoffset;
  int yoffset;
  int param_5;
  undefined4 width;
  undefined4 height;
  undefined4 format;
  undefined4 type;
  int pixels;
{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int local_50;
  undefined1 auStack_4c [4];
  undefined1 auStack_48 [4];
  undefined1 auStack_44 [4];
  undefined1 auStack_40 [4];
  int local_3c [4];
  
  if ((*(byte *)(param_2 + 0xb) & 1) != 0) {
    iVar3 = _glePixelBytes((uint)*(ushort *)(param_2 + 0x10),(uint)*(ushort *)(param_2 + 0x12));
    iVar4 = _gleRowBytes((uint)*(ushort *)(param_2 + 0x10),(uint)*(ushort *)(param_2 + 0x12),
                         (uint)*(ushort *)(param_2 + 0xc));
    uVar1 = *(ushort *)(param_2 + 0xe);
    uVar2 = *(ushort *)(param_2 + 0xc);
    iVar5 = *(int *)(param_2 + 0x14);
    _glePixelPackSettings
              (glContext,format,type,width,height,glContext + 0x31cc,auStack_40,local_3c,
               &local_50,auStack_4c,auStack_48,auStack_44);
    if ((pixels + local_3c[0] ==
         iVar5 + iVar3 * ((uint)uVar2 * ((uint)uVar1 * param_5 + yoffset) + xoffset)) &&
       (local_50 == iVar4)) {
      return 0;
    }
  }
  return 1;
}

/* _gleModifyPluginTextureLevel @ 0x1f9dc (376 bytes) */
int _gleModifyPluginTextureLevel(glContext, param_2, param_3, param_4, level, param_6, yoffset, param_8, param_9, height, param_11)
  int glContext;
  undefined4 *param_2;
  int *param_3;
  int param_4;
  uint level;
  undefined4 param_6;
  undefined4 yoffset;
  undefined4 param_8;
  undefined4 param_9;
  undefined4 height;
  undefined4 param_11;
{
  int loopIndex2;
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  ushort uVar5;
  int loopIndex;
  
  if ((*(byte *)((int)param_3 + 0xb) & 0x10) == 0) {
    iVar3 = param_4 * 2 + (int)param_2;
    uVar5 = *(ushort *)(iVar3 + 0xa0) &
            ((ushort)(-2 << (level & 0x1f)) | (ushort)(0xfffffffe >> 0x20 - (level & 0x1f)));
  }
  else {
    iVar3 = param_4 * 2 + (int)param_2;
    uVar5 = *(ushort *)(iVar3 + 0xa0) | *(ushort *)(iVar3 + 0x94) & (ushort)(1 << (level & 0x3f));
  }
  *(ushort *)(iVar3 + 0xa0) = uVar5;
  iVar3 = glContext + 0x10000;
  loopIndex = 0;
  if (*(char *)(glContext + 0x85a4) != '\0') {
    do {
      piVar1 = (int *)(iVar3 + -0x777c);
      puVar2 = (undefined4 *)(iVar3 + -0x7a54);
      uVar4 = *param_2;
      iVar3 = iVar3 + 0x2e0;
      loopIndex = loopIndex + 1;
      param_2 = param_2 + 1;
      (**(code **)(*piVar1 + 0x158))(*puVar2,uVar4,param_4,level,param_6,yoffset,param_8,param_9);
    } while (loopIndex < (int)(uint)*(byte *)(glContext + 0x85a4));
  }
  if ((*(byte *)((int)param_3 + 0xb) & 0x80) != 0) {
    loopIndex2 = 0;
    iVar3 = *(int *)(glContext + 0x744c) + 0x10;
    *(undefined4 *)(*(int *)(glContext + 0x744c) + 0xec) = 1;
    if (*(char *)(glContext + 0x85a4) != '\0') {
      do {
        *(undefined4 *)(iVar3 + 0xf8) = 1;
        loopIndex2 = loopIndex2 + 1;
        *(undefined4 *)(iVar3 + 0xfc) = 0;
        iVar3 = iVar3 + 0x20;
      } while (loopIndex2 < (int)(uint)*(byte *)(glContext + 0x85a4));
    }
    *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x80000000;
  }
  *param_3 = *param_3 + 1;
  return;
}

/* _glTestObjectAPPLE_Exec @ 0x1fb54 (304 bytes) */
int _glTestObjectAPPLE_Exec(glContext, object, name)
  int glContext;
  uint object;
  undefined4 name;
{
  undefined4 uVar1;
  
  if (-1 < *(short *)(glContext + 0x4a10)) {
    if (*(int *)(glContext + 0x7574) == 0) {
      *(undefined4 *)(glContext + 0x7574) = 0x502;
    }
    return 1;
  }
  if (object == 0x8a0a) {
    return 1;
  }
  if (object < 0x8a0b) {
    if (object == 0x8074) {
      uVar1 = 2;
    }
    else if (object < 0x8075) {
      if (object != 0x1702) {
LAB_0001fc50:
        if (*(int *)(glContext + 0x7574) == 0) {
          *(undefined4 *)(glContext + 0x7574) = 0x500;
        }
        return 0;
      }
      uVar1 = 1;
    }
    else {
      if (object != 0x85b3) goto LAB_0001fc50;
      uVar1 = 3;
    }
  }
  else if (object == 0x8d40) {
    uVar1 = 5;
  }
  else if (object < 0x8d41) {
    if (object != 0x8a0b) goto LAB_0001fc50;
    uVar1 = 0;
  }
  else {
    if (object != 0x8d41) goto LAB_0001fc50;
    uVar1 = 4;
  }
  uVar1 = ((int (*)())_gleTestObject)(glContext,uVar1,name);
  return uVar1;
}

/* _gleTestObject @ 0x1fc84 (760 bytes) */
int _gleTestObject(glContext, param_2, name)
  int glContext;
  undefined4 param_2;
  undefined4 name;
{
  uint loopIndex5;
  uint loopIndex4;
  uint loopIndex3;
  uint loopIndex2;
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  uint loopIndex;
  
  iVar4 = 1;
  iVar2 = 1;
  switch(param_2) {
  case 0:
    iVar2 = _gleLookupHashObject(glContext + 0x543c,name);
    if (iVar2 == 0) {
LAB_0001ff68:
      if (*(int *)(glContext + 0x7574) == 0) {
        *(undefined4 *)(glContext + 0x7574) = 0x502;
      }
    }
    else {
      iVar3 = glContext + 0x10000;
      loopIndex = 0;
      if (*(char *)(glContext + 0x85a4) != '\0') {
        puVar5 = (undefined4 *)(iVar2 + 0x10);
        do {
          bVar1 = iVar4 != 0;
          iVar4 = 0;
          if ((bVar1) &&
             (iVar2 = (**(code **)(*(int *)(iVar3 + -0x777c) + 0x1c0))
                                (*(undefined4 *)(iVar3 + -0x7a54),param_2,*puVar5), iVar2 != 0)) {
            iVar4 = 1;
          }
          loopIndex = loopIndex + 1;
          iVar3 = iVar3 + 0x2e0;
          puVar5 = puVar5 + 1;
        } while (loopIndex < *(byte *)(glContext + 0x85a4));
      }
    }
    break;
  case 1:
    iVar2 = _gleLookupHashObject(*(int *)(glContext + 0x5148) + 0x2008,name);
    if (iVar2 == 0) goto LAB_0001ff68;
    iVar3 = glContext + 0x10000;
    loopIndex2 = 0;
    if (*(char *)(glContext + 0x85a4) != '\0') {
      puVar5 = (undefined4 *)(iVar2 + 0x10);
      do {
        bVar1 = iVar4 != 0;
        iVar4 = 0;
        if ((bVar1) &&
           (iVar2 = (**(code **)(*(int *)(iVar3 + -0x777c) + 0x1c0))
                              (*(undefined4 *)(iVar3 + -0x7a54),param_2,*puVar5), iVar2 != 0)) {
          iVar4 = 1;
        }
        loopIndex2 = loopIndex2 + 1;
        iVar3 = iVar3 + 0x2e0;
        puVar5 = puVar5 + 1;
      } while (loopIndex2 < *(byte *)(glContext + 0x85a4));
    }
    break;
  case 2:
    iVar2 = _gleLookupHashObject(*(int *)(glContext + 0x5148) + 0x5014,name);
    if (iVar2 == 0) goto LAB_0001ff68;
    iVar3 = glContext + 0x10000;
    loopIndex3 = 0;
    if (*(char *)(glContext + 0x85a4) != '\0') {
      puVar5 = (undefined4 *)(iVar2 + 0x10);
      do {
        bVar1 = iVar4 != 0;
        iVar4 = 0;
        if ((bVar1) &&
           (iVar2 = (**(code **)(*(int *)(iVar3 + -0x777c) + 0x1c0))
                              (*(undefined4 *)(iVar3 + -0x7a54),param_2,*puVar5), iVar2 != 0)) {
          iVar4 = 1;
        }
        loopIndex3 = loopIndex3 + 1;
        iVar3 = iVar3 + 0x2e0;
        puVar5 = puVar5 + 1;
      } while (loopIndex3 < *(byte *)(glContext + 0x85a4));
    }
    break;
  case 3:
    iVar2 = _gleLookupHashObject(*(int *)(glContext + 0x5148) + 0x701c,name);
    if (iVar2 == 0) goto LAB_0001ff68;
    iVar3 = glContext + 0x10000;
    loopIndex4 = 0;
    if (*(char *)(glContext + 0x85a4) != '\0') {
      puVar5 = (undefined4 *)(iVar2 + 0x10);
      do {
        bVar1 = iVar4 != 0;
        iVar4 = 0;
        if ((bVar1) &&
           (iVar2 = (**(code **)(*(int *)(iVar3 + -0x777c) + 0x1c0))
                              (*(undefined4 *)(iVar3 + -0x7a54),param_2,*puVar5), iVar2 != 0)) {
          iVar4 = 1;
        }
        loopIndex4 = loopIndex4 + 1;
        iVar3 = iVar3 + 0x2e0;
        puVar5 = puVar5 + 1;
      } while (loopIndex4 < *(byte *)(glContext + 0x85a4));
    }
    break;
  case 4:
    iVar2 = _gleLookupHashObject(((unsigned char *)0x00001004) + *(int *)(glContext + 0x5148),name);
    if (iVar2 == 0) goto LAB_0001ff68;
    iVar3 = glContext + 0x10000;
    loopIndex5 = 0;
    if (*(char *)(glContext + 0x85a4) != '\0') {
      puVar5 = (undefined4 *)(iVar2 + 0x10);
      do {
        bVar1 = iVar4 != 0;
        iVar4 = 0;
        if ((bVar1) &&
           (iVar2 = (**(code **)(*(int *)(iVar3 + -0x777c) + 0x1c0))
                              (*(undefined4 *)(iVar3 + -0x7a54),param_2,*puVar5), iVar2 != 0)) {
          iVar4 = 1;
        }
        loopIndex5 = loopIndex5 + 1;
        iVar3 = iVar3 + 0x2e0;
        puVar5 = puVar5 + 1;
      } while (loopIndex5 < *(byte *)(glContext + 0x85a4));
    }
    break;
  case 5:
    break;
  default:
    goto switchD_0001fcd0_default;
  }
  iVar2 = iVar4;
switchD_0001fcd0_default:
  return iVar2;
}

/* _glDeleteTextures_Exec_body @ 0x1ff98 (572 bytes) */
void _glDeleteTextures_Exec_body(glContext, n, textures)
  int glContext;
  int n;
  int *textures;
{
  uint loopIndex3;
  int *cursor;
  undefined4 glErrorCode;
  int iVar2;
  int iVar3;
  uint loopIndex4;
  int *piVar5;
  int *piVar6;
  int iVar7;
  int loopIndex;
  int iVar9;
  int iVar10;
  uint loopIndex2;
  int iVar12;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (-1 < n) {
      if (n == 0) {
        return;
      }
      iVar3 = *(int *)(glContext + 0x5148);
      piVar6 = (int *)0x0;
      iVar7 = iVar3 + 0x2008;
      if (*(char *)(iVar3 + 0x8024) != '\0') {
        _pthread_mutex_lock(iVar3 + 0x8028);
      }
      iVar3 = *(int *)(glContext + 0x744c);
      if (iVar3 != 0) {
        piVar6 = (int *)(iVar3 + 0xd4);
      }
      loopIndex = 0;
      iVar9 = *textures;
      iVar10 = iVar9;
      if (0 < n) {
        do {
          if (*textures == 0) {
            ((void (*)())_gleDeleteHashNamesAndObjects)(glContext,iVar7,iVar9,iVar10 - iVar9);
            iVar9 = textures[1];
            iVar10 = iVar9 + -1;
          }
          else {
            loopIndex2 = 0;
            iVar12 = glContext;
            do {
              piVar5 = (int *)(iVar12 + 0x5154);
              loopIndex4 = 0;
              do {
                if (*(int *)(*piVar5 + 4) == *textures) {
                  _gleBindTexture(glContext,loopIndex4,0,loopIndex2);
                  break;
                }
                loopIndex4 = loopIndex4 + 1;
                piVar5 = piVar5 + 1;
              } while (loopIndex4 < 5);
              loopIndex2 = loopIndex2 + 1;
              iVar12 = iVar12 + 0x14;
            } while (loopIndex2 < 0x10);
            if ((iVar3 != 0) && (iVar12 = _gleLookupHashObject(iVar7,*textures), iVar12 != 0)) {
              loopIndex3 = 0;
              cursor = piVar6;
              do {
                iVar2 = *cursor;
                cursor = cursor + 1;
                if (iVar12 == iVar2) {
                  _gleFramebufferTexture(glContext,loopIndex3,0,0,0,0,0);
                }
                loopIndex3 = loopIndex3 + 1;
              } while (loopIndex3 < 6);
            }
            if (*textures != iVar10) {
              ((void (*)())_gleDeleteHashNamesAndObjects)(glContext,iVar7,iVar9,iVar10 - iVar9);
              iVar9 = *textures;
              iVar10 = iVar9;
            }
          }
          loopIndex = loopIndex + 1;
          textures = textures + 1;
          iVar10 = iVar10 + 1;
        } while (loopIndex < n);
      }
      ((void (*)())_gleDeleteHashNamesAndObjects)(glContext,iVar7,iVar9,iVar10 - iVar9);
      if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) == '\0') {
        return;
      }
      _pthread_mutex_unlock(*(int *)(glContext + 0x5148) + 0x8028);
      return;
    }
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x501;
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

/* _gleDeleteHashNamesAndObjects @ 0x201d4 (340 bytes) */
void _gleDeleteHashNamesAndObjects(glContext, param_2, list, listRange)
  undefined4 glContext;
  int param_2;
  uint list;
  int listRange;
{
  uint uVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  int *piVar11;
  
  uVar6 = list + listRange;
  piVar2 = (int *)*(int *)(param_2 + 0x1000);
  piVar5 = (int *)(param_2 + 0x1000);
  do {
    while( true ) {
      piVar11 = piVar2;
      if (piVar11 == (int *)0x0) {
        return;
      }
      uVar9 = piVar11[1];
      uVar8 = uVar9 + piVar11[2];
      if (uVar6 <= uVar9) {
        return;
      }
      if (list < uVar8) break;
LAB_00020304:
      piVar2 = (int *)*piVar11;
      piVar5 = piVar11;
    }
    uVar7 = list;
    if (list < uVar9) {
      uVar7 = uVar9;
    }
    uVar1 = uVar7;
    uVar10 = uVar6;
    if (uVar8 < uVar6) {
      uVar10 = uVar8;
    }
    for (; uVar1 < uVar10; uVar1 = uVar1 + 1) {
      iVar4 = ((int (*)())_gleRemoveHashObject)(param_2,uVar1);
      if ((iVar4 != 0) &&
         (iVar3 = *(int *)(iVar4 + 8) + -1, *(int *)(iVar4 + 8) = iVar3, iVar3 == 0)) {
        (**(code **)(iVar4 + 0xc))(glContext);
      }
    }
    if (uVar9 < uVar7) {
      piVar11[2] = uVar7 - uVar9;
      if (uVar10 < uVar8) {
        piVar5 = (int *)_malloc(0xc);
        iVar4 = *piVar11;
        piVar5[1] = uVar10;
        *piVar5 = iVar4;
        piVar5[2] = uVar8 - uVar10;
        *piVar11 = (int)piVar5;
        piVar11 = piVar5;
      }
      goto LAB_00020304;
    }
    if (uVar10 < uVar8) {
      piVar11[1] = uVar10;
      piVar11[2] = uVar8 - uVar10;
      goto LAB_00020304;
    }
    *piVar5 = *piVar11;
    _free(piVar11);
    piVar2 = (int *)*piVar5;
  } while( true );
}

/* _gleRemoveHashObject @ 0x20328 (120 bytes) */
int _gleRemoveHashObject(param_1, param_2)
  int param_1;
  uint param_2;
{
  int *piVar1;
  int *piVar2;
  int iVar3;
  
  iVar3 = (param_2 & 0x3ff) * 4;
  piVar2 = *(int **)(iVar3 + param_1);
  if (piVar2 == (int *)0x0) {
    return (int *)0x0;
  }
  if (piVar2[1] != param_2) {
    piVar1 = (int *)*piVar2;
    while( true ) {
      if (piVar1 == (int *)0x0) {
        return (int *)0x0;
      }
      if (piVar1[1] == param_2) break;
      piVar2 = piVar1;
      piVar1 = (int *)*piVar1;
    }
    *piVar2 = *piVar1;
    return piVar1;
  }
  *(int *)(iVar3 + param_1) = *piVar2;
  return piVar2;
}

/* _gleFreeTextureObject @ 0x203a0 (256 bytes) */
void _gleFreeTextureObject(glContext, param_2)
  undefined4 glContext;
  int param_2;
{
  ushort uVar1;
  int iVar2;
  int iVar3;
  int loopIndex;
  int loopIndex2;
  int remaining;
  int iVar7;
  
  iVar3 = param_2 + 0x10;
  ((void (*)())_gleDeletePluginTexture)(glContext,iVar3);
  uVar1 = *(ushort *)(param_2 + 0x34);
  if ((uVar1 & 0x100) == 0) {
    if ((*(int *)(param_2 + 0xd0) != 0) && ((*(byte *)(param_2 + 199) & 7) == 0)) {
      _gleFreeTextureLevel(glContext,iVar3,param_2 + 0xbc);
      uVar1 = *(ushort *)(param_2 + 0x34);
    }
    iVar2 = 0;
    if ((uVar1 & 0x200) == 0) {
      iVar2 = 1;
      if ((uVar1 & 0x2000) == 0) {
        iVar2 = 6;
        if ((uVar1 & 0xf) != 0) {
          iVar2 = 1;
        }
      }
    }
    loopIndex = 0;
    if (iVar2 != 0) {
      loopIndex2 = 0;
      do {
        remaining = 0xe;
        iVar7 = param_2 + loopIndex2 + 0xd4;
        do {
          if ((*(int *)(iVar7 + 0x14) != 0) && ((*(byte *)(iVar7 + 0xb) & 7) == 0)) {
            _gleFreeTextureLevel(glContext,iVar3,iVar7);
          }
          remaining = remaining + -1;
          iVar7 = iVar7 + 0x18;
        } while (-1 < remaining);
        loopIndex = loopIndex + 1;
        loopIndex2 = loopIndex2 + 0x168;
      } while (loopIndex < iVar2);
    }
  }
  _free(param_2);
  return;
}

/* _gleDeletePluginTexture @ 0x204a0 (120 bytes) */
void _gleDeletePluginTexture(glContext, param_2)
  int glContext;
  int param_2;
{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int loopIndex;
  
  iVar4 = glContext + 0x10000;
  loopIndex = 0;
  if (*(char *)(glContext + 0x85a4) != '\0') {
    do {
      piVar1 = (int *)(iVar4 + -0x777c);
      iVar3 = loopIndex * 4;
      puVar2 = (undefined4 *)(iVar4 + -0x7a54);
      iVar4 = iVar4 + 0x2e0;
      loopIndex = loopIndex + 1;
      (**(code **)(*piVar1 + 0x168))(*puVar2,*(undefined4 *)(iVar3 + param_2));
      *(undefined4 *)(iVar3 + param_2) = 0;
    } while (loopIndex < (int)(uint)*(byte *)(glContext + 0x85a4));
  }
  return;
}

/* _gleSetEnable_SCISSOR_TEST @ 0x20518 (72 bytes) */
void _gleSetEnable_SCISSOR_TEST(int glContext,undefined4 param_2,uint param_3,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  if (*(byte *)(glContext + 0x34f0) != param_3) {
    *(char *)(glContext + 0x34f0) = (char)param_3;
    ((void (*)())_gleUpdateViewScissorData)(glContext,fparam_1,fparam_2,fparam_3,fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
    *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x4000000;
  }
  return;
}

/* _glScissor_Exec @ 0x20560 (144 bytes) */
void _glScissor_Exec(int glContext,undefined4 x,undefined4 y,int width,int height,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  undefined4 glErrorCode;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    if ((-1 < width) && (-1 < height)) {
      *(undefined4 *)(glContext + 0x34e0) = x;
      *(undefined4 *)(glContext + 0x34e4) = y;
      *(int *)(glContext + 0x34e8) = width;
      *(int *)(glContext + 0x34ec) = height;
      ((void (*)())_gleUpdateViewScissorData)(glContext,fparam_1,fparam_2,fparam_3,fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
      *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x4000000;
      return;
    }
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x501;
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

/* _gleMoveFuncCacheElem @ 0x205f0 (44 bytes) */
void _gleMoveFuncCacheElem(param_1, param_2)
  int param_1;
  int *param_2;
{
  undefined4 *puVar1;
  int *piVar2;
  
  piVar2 = (int *)param_2[1];
  *piVar2 = *param_2;
  *(int **)(*param_2 + 4) = piVar2;
  puVar1 = *(undefined4 **)(param_1 + 4);
  *puVar1 = param_2;
  param_2[1] = (int)puVar1;
  *param_2 = param_1;
  *(int **)(param_1 + 4) = param_2;
  return;
}

/* _gliSetInteger @ 0x2061c (2408 bytes) */
int _gliSetInteger(glContext, stateId, valuePtr)
  int glContext;
  uint stateId;
  int *valuePtr;
{
  int loopIndex2;
  int loopIndex;
  byte bVar1;
  ushort uVar2;
  undefined2 uVar3;
  undefined1 uVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  undefined1 uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  uint uVar14;
  int iVar15;
  int iVar16;
  
  iVar10 = 0;
  if ((glContext == 0) || (*(int *)(glContext + 0x467c) != 0x3463a223)) {
    return 0x2714;
  }
  if (valuePtr == (int *)0x0) {
    return 0x271e;
  }
  if (stateId == 0x176) {
    iVar10 = *valuePtr;
    if (iVar10 < 1) {
      return 0x2718;
    }
    *(short *)(glContext + 0x49c0) = (short)iVar10;
    if (*(short *)(glContext + 0x49c2) <= iVar10) {
      return 0;
    }
    uVar5 = *(undefined4 *)(glContext + 0x49b8);
    iVar13 = *(short *)(glContext + 0x49c2) - iVar10;
    *(short *)(glContext + 0x49c2) = (short)iVar10;
LAB_0002085c:
    _gleShrinkFuncCache(uVar5,iVar13);
  }
  else {
    if (stateId < 0x177) {
      if (stateId == 0x133) {
        *(char *)(glContext + 0x5410) = '\x01' - (*valuePtr == 0);
        return 0;
      }
      if (0x133 < stateId) {
        if (stateId == 0x162) {
          iVar10 = *valuePtr;
          if (iVar10 < 4) {
            return 0x2718;
          }
          *(short *)(glContext + 0x5098) = (short)iVar10;
          if (*(short *)(glContext + 0x509a) <= iVar10) {
            return 0;
          }
          uVar5 = *(undefined4 *)(glContext + 0x5094);
          iVar13 = *(short *)(glContext + 0x509a) - iVar10;
          *(short *)(glContext + 0x509a) = (short)iVar10;
        }
        else if (stateId < 0x163) {
          if (stateId == 0x134) {
            _gleReclaimContextResources(glContext);
            return 0;
          }
          if (stateId != 0x15e) goto LAB_00020f04;
          iVar10 = *valuePtr;
          if (iVar10 < 4) {
            return 0x2718;
          }
          *(short *)(glContext + 0x508c) = (short)iVar10;
          if (*(short *)(glContext + 0x508e) <= iVar10) {
            return 0;
          }
          uVar5 = *(undefined4 *)(glContext + 0x5088);
          iVar13 = *(short *)(glContext + 0x508e) - iVar10;
          *(short *)(glContext + 0x508e) = (short)iVar10;
        }
        else if (stateId == 0x16a) {
          iVar10 = *valuePtr;
          if (iVar10 < 1) {
            return 0x2718;
          }
          *(short *)(glContext + 0x48b4) = (short)iVar10;
          if (*(short *)(glContext + 0x48b6) <= iVar10) {
            return 0;
          }
          uVar5 = *(undefined4 *)(glContext + 0x48b0);
          iVar13 = *(short *)(glContext + 0x48b6) - iVar10;
          *(short *)(glContext + 0x48b6) = (short)iVar10;
        }
        else if (stateId < 0x16b) {
          if (stateId != 0x166) goto LAB_00020f04;
          iVar10 = *valuePtr;
          if (iVar10 < 1) {
            return 0x2718;
          }
          *(short *)(glContext + 0x50a4) = (short)iVar10;
          if (*(short *)(glContext + 0x50a6) <= iVar10) {
            return 0;
          }
          uVar5 = *(undefined4 *)(glContext + 0x50a0);
          iVar13 = *(short *)(glContext + 0x50a6) - iVar10;
          *(short *)(glContext + 0x50a6) = (short)iVar10;
        }
        else {
          if (stateId != 0x172) goto LAB_00020f04;
          iVar10 = *valuePtr;
          if (iVar10 < 1) {
            return 0x2718;
          }
          *(short *)(glContext + 0x49bc) = (short)iVar10;
          if (*(short *)(glContext + 0x49be) <= iVar10) {
            return 0;
          }
          uVar5 = *(undefined4 *)(glContext + 0x49b4);
          iVar13 = *(short *)(glContext + 0x49be) - iVar10;
          *(short *)(glContext + 0x49be) = (short)iVar10;
        }
        goto LAB_0002085c;
      }
      if (stateId == 0xe5) {
        *(char *)(glContext + 0x4693) = '\x01' - (*valuePtr == 0);
        return 0;
      }
      if (stateId < 0xe6) {
        if (stateId == 0xdd) {
          uVar8 = 0;
          *(char *)(glContext + 0x4690) = '\x01' - (*valuePtr == 0);
          if ((*(char *)(glContext + 0x4690) == '\0') || (*(int *)(glContext + 0x4848) == 0)) {
            uVar8 = 1;
          }
          uVar4 = 0;
          *(undefined1 *)(glContext + 0x4692) = uVar8;
          if ((*(int *)(glContext + 0x4e1c) == 0x1c00) && (*(char *)(glContext + 0x4692) == '\0')) {
            uVar4 = 1;
          }
          *(undefined1 *)(glContext + 0x4691) = uVar4;
          *(undefined4 *)(glContext + 0x757c) = 0xffffffff;
          _gliSetCurrentPluginDispatchTable(glContext);
          return 0;
        }
        if (stateId == 0xe4) {
          *(int *)(glContext + 0x7590) = *valuePtr;
          return 0;
        }
LAB_00020f04:
        iVar13 = glContext + 0x10000;
        loopIndex = 0;
        if (*(char *)(glContext + 0x85a4) != '\0') {
          do {
            iVar7 = (**(code **)(*(int *)(iVar13 + -0x777c) + 0x140))
                              (*(undefined4 *)(iVar13 + -0x7a54),stateId,valuePtr);
            if ((iVar7 != 0) && (iVar10 == 0)) {
              iVar10 = iVar7;
            }
            loopIndex = loopIndex + 1;
            iVar13 = iVar13 + 0x2e0;
          } while (loopIndex < (int)(uint)*(byte *)(glContext + 0x85a4));
          return iVar10;
        }
        return 0;
      }
      if (stateId != 0x128) {
        if (stateId == 0x132) {
          *(char *)(glContext + 0x4694) = '\x01' - (*valuePtr == 0);
        }
        goto LAB_00020f04;
      }
      if (-1 < *(short *)(glContext + 0x4a10)) goto LAB_00020c88;
      uVar14 = valuePtr[1];
      iVar9 = valuePtr[7];
      iVar10 = *valuePtr;
      iVar11 = valuePtr[2];
      iVar13 = valuePtr[3];
      iVar7 = valuePtr[4];
      iVar16 = valuePtr[5];
      iVar12 = valuePtr[6];
      if (uVar14 == 0xde1) {
LAB_00020a7c:
        iVar6 = _gleCheckTexImage2DArgs
                          (glContext,uVar14,iVar11,iVar13,iVar7,iVar16,iVar9,0x80e1,0x1401);
      }
      else if (uVar14 < 0xde2) {
        if (uVar14 != 0xde0) {
          return 0x2717;
        }
        iVar6 = _gleCheckTexImage1DArgs(glContext,0xde0,iVar11,iVar13,iVar7,iVar9,0x80e1,0x1401);
      }
      else {
        if (uVar14 != 0x806f) {
          if (uVar14 != 0x84f5) {
            return 0x2717;
          }
          goto LAB_00020a7c;
        }
        iVar6 = ((int (*)())_gleCheckTexImage3DArgs)(glContext,0x806f,iVar11,iVar13,iVar7,iVar16,iVar12,iVar9,0x80e1,0x1401);
      }
      if (iVar6 == 0) {
        return 0;
      }
      uVar2 = *(ushort *)(iVar6 + 0x24);
      if ((uVar2 & 0x3c00) != 0x800) {
        if ((uVar2 & 0x3c00) == 0) {
          *(ushort *)(iVar6 + 0x24) = uVar2 | 0x800;
        }
        else if ((uVar2 & 0x1400) != 0) {
LAB_00020c88:
          if (*(int *)(glContext + 0x7574) == 0) {
            *(undefined4 *)(glContext + 0x7574) = 0x502;
          }
          return 0x2717;
        }
      }
      *(int *)(iVar6 + 0x2c) = iVar10;
      uVar14 = uVar14 - 0x8515;
      if (5 < uVar14) {
        uVar14 = 0;
      }
      iVar10 = iVar6 + uVar14 * 0x168 + iVar11 * 0x18;
      iVar15 = iVar10 + 0xc4;
      if ((*(byte *)(iVar10 + 0xcf) & 0x20) != 0) {
        _gleDeletePluginTextureLevel(glContext,iVar6,iVar15,uVar14,iVar11);
        if (*(int *)(iVar10 + 0xd8) != 0) {
          bVar1 = *(byte *)(iVar10 + 0xcf);
          if ((bVar1 & 1) == 0) {
            _gleFreeTextureLevel(glContext,iVar6,iVar15);
            bVar1 = *(byte *)(iVar10 + 0xcf);
          }
          else {
            *(undefined4 *)(iVar10 + 0xd8) = 0;
          }
          *(byte *)(iVar10 + 0xcf) = bVar1 & 0xef;
        }
        *(byte *)(iVar10 + 0xcf) = *(byte *)(iVar10 + 0xcf) & 0xdf;
      }
      _gleCreateGlobalLevel(glContext,iVar15,iVar7,iVar16,iVar12,iVar9);
      _gleCreatePluginTextureLevel(glContext,iVar6,iVar15,uVar14,iVar11,iVar13);
    }
    else {
      if (stateId == 0x3e1) {
        iVar10 = *(int *)(glContext + 0x5408);
        *(char *)(glContext + 0x7586) = '\x01' - (*valuePtr == 0);
joined_r0x00020e50:
        if (iVar10 != 0) {
          return 0;
        }
        _gliExecDispatchTable(glContext);
        return 0;
      }
      if (stateId < 0x3e2) {
        if (stateId == 0x184) {
          iVar10 = *valuePtr;
          if (iVar10 < 1) {
            return 0x2718;
          }
          *(short *)(glContext + 0x48bc) = (short)iVar10;
          if (*(short *)(glContext + 0x48be) <= iVar10) {
            return 0;
          }
          uVar5 = *(undefined4 *)(glContext + 0x48b8);
          iVar13 = *(short *)(glContext + 0x48be) - iVar10;
          *(short *)(glContext + 0x48be) = (short)iVar10;
        }
        else if (stateId < 0x185) {
          if (stateId == 0x17c) {
            iVar10 = *valuePtr;
            if (iVar10 < 1) {
              return 0x2718;
            }
            *(short *)(glContext + 0x48a4) = (short)iVar10;
            if (*(short *)(glContext + 0x48a6) <= iVar10) {
              return 0;
            }
            uVar5 = *(undefined4 *)(glContext + 0x48a0);
            iVar13 = *(short *)(glContext + 0x48a6) - iVar10;
            *(short *)(glContext + 0x48a6) = (short)iVar10;
          }
          else {
            if (stateId != 0x180) goto LAB_00020f04;
            iVar10 = *valuePtr;
            if (iVar10 < 1) {
              return 0x2718;
            }
            *(short *)(glContext + 0x48ac) = (short)iVar10;
            if (*(short *)(glContext + 0x48ae) <= iVar10) {
              return 0;
            }
            uVar5 = *(undefined4 *)(glContext + 0x48a8);
            iVar13 = *(short *)(glContext + 0x48ae) - iVar10;
            *(short *)(glContext + 0x48ae) = (short)iVar10;
          }
        }
        else {
          if (stateId != 0x188) {
            if (stateId == 0x3e0) {
              iVar10 = *(int *)(glContext + 0x5408);
              *(char *)(glContext + 0x7587) = '\x01' - (*valuePtr == 0);
              goto joined_r0x00020e50;
            }
            goto LAB_00020f04;
          }
          iVar10 = *valuePtr;
          if (iVar10 < 1) {
            return 0x2718;
          }
          *(short *)(glContext + 0x48c4) = (short)iVar10;
          if (*(short *)(glContext + 0x48c6) <= iVar10) {
            return 0;
          }
          uVar5 = *(undefined4 *)(glContext + 0x48c0);
          iVar13 = *(short *)(glContext + 0x48c6) - iVar10;
          *(short *)(glContext + 0x48c6) = (short)iVar10;
        }
        goto LAB_0002085c;
      }
      if (999 < stateId) {
        if (stateId == 0x6a7) {
          *(int *)(glContext + 0x7594) = *valuePtr;
          return 0;
        }
        if (stateId == 0x6a8) {
          *(int *)(glContext + 0x7598) = *valuePtr;
          return 0;
        }
        goto LAB_00020f04;
      }
      if (stateId < 0x3e5) {
        if (stateId == 0x3e2) {
          *(char *)(glContext + 0x7584) = '\x01' - (*valuePtr == 0);
          return 0;
        }
        if (stateId == 0x3e4) {
          *(char *)(glContext + 0x53e7) = '\x01' - (*valuePtr == 0);
          *(char *)(glContext + 0x7585) = '\x01' - (*valuePtr == 0);
          return 0;
        }
        goto LAB_00020f04;
      }
      iVar9 = valuePtr[1];
      iVar13 = valuePtr[2];
      iVar7 = valuePtr[3];
      iVar16 = valuePtr[4];
      iVar11 = *valuePtr;
      iVar10 = _gleCheckTexImage2DArgs(glContext,iVar9,0,iVar13,iVar7,iVar16,0,0x80e1,0x8367);
      if (iVar10 == 0) {
        return 0;
      }
      uVar2 = *(ushort *)(iVar10 + 0x24);
      if ((uVar2 & 0x3c00) != 0x400) {
        if ((uVar2 & 0x3c00) == 0) {
          *(ushort *)(iVar10 + 0x24) = uVar2 | 0x400;
        }
        else if ((uVar2 & 0x1800) != 0) goto LAB_00020c88;
      }
      *(int *)(iVar10 + 0x2c) = iVar11;
      if (stateId != 0x3e5) {
        uVar3 = 0x404;
      }
      else {
        uVar3 = *(undefined2 *)((int)valuePtr + 0x1a);
      }
      *(undefined2 *)(iVar10 + 0x30) = uVar3;
      iVar11 = 6;
      if (iVar9 != 0x8513) {
        iVar11 = 1;
      }
      loopIndex2 = 0;
      if (iVar11 != 0) {
        iVar12 = iVar10 + 0xc4;
        do {
          if ((*(byte *)(iVar12 + 0xb) & 0x20) != 0) {
            _gleDeletePluginTextureLevel(glContext,iVar10,iVar12,0,0);
            if (*(int *)(iVar12 + 0x14) != 0) {
              bVar1 = *(byte *)(iVar12 + 0xb);
              if ((bVar1 & 1) == 0) {
                _gleFreeTextureLevel(glContext,iVar10,iVar12);
                bVar1 = *(byte *)(iVar12 + 0xb);
              }
              else {
                *(undefined4 *)(iVar12 + 0x14) = 0;
              }
              *(byte *)(iVar12 + 0xb) = bVar1 & 0xef;
            }
            *(byte *)(iVar12 + 0xb) = *(byte *)(iVar12 + 0xb) & 0xdf;
          }
          ((int (*)())_gleCreateSurfaceLevel)(glContext,iVar12,iVar7,iVar16,0,0);
          if (stateId != 0x3e5) {
            iVar6 = 0;
          }
          else {
            iVar6 = valuePtr[7];
          }
          uVar5 = _gleReqToBase(iVar13);
          _gleCreatePluginTextureLevel(glContext,iVar10,iVar12,loopIndex2,0,uVar5);
          if (iVar6 != 0) {
            _gleGenSurfaceMipmaps(glContext,iVar10,loopIndex2,iVar6,*(uint *)(iVar10 + 0x6c) >> 0xf & 1);
          }
          loopIndex2 = loopIndex2 + 1;
          iVar12 = iVar12 + 0x168;
        } while (loopIndex2 < iVar11);
      }
    }
    *(uint *)(glContext + 0x314) =
         *(uint *)(glContext + 0x314) | 1 << (*(uint *)(glContext + 0x53d4) & 0x3f);
  }
  return 0;
}

/* _gleCreateSurfaceLevel @ 0x20f84 (60 bytes) */
int _gleCreateSurfaceLevel(glContext, param_2, param_3, param_4, param_5, param_6)
  undefined4 glContext;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
{
  *(undefined2 *)(param_2 + 8) = 1;
  *(undefined2 *)(param_2 + 0xe) = 0;
  *(undefined2 *)(param_2 + 4) = (*(unsigned short *)((unsigned char *)&(param_3) + 2));
  *(undefined2 *)(param_2 + 6) = (*(unsigned short *)((unsigned char *)&(param_4) + 2));
  *(undefined2 *)(param_2 + 0x10) = (*(unsigned short *)((unsigned char *)&(param_5) + 2));
  *(undefined2 *)(param_2 + 0x12) = (*(unsigned short *)((unsigned char *)&(param_6) + 2));
  *(undefined1 *)(param_2 + 0xb) = 0x32;
  *(undefined4 *)(param_2 + 0x14) = 0;
  *(undefined1 *)(param_2 + 10) = 0;
  *(undefined2 *)(param_2 + 0xc) = 0;
  return 0;
}

/* _glFlushRender_Exec @ 0x20fc0 (52 bytes) */
void _glFlushRender_Exec(glContext)
  int glContext;
{
  if (*(short *)(glContext + 0x4a10) < 0) {
                    
                    
    (**(code **)(glContext + 0x47b4))(*(undefined4 *)(glContext + 0x4688));
    return;
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  *(undefined4 *)(glContext + 0x7574) = 0x502;
  return;
}

/* _glGetFloatv_Exec @ 0x20ff4 (280 bytes) */
void _glGetFloatv_Exec(glContext, pname, params)
  int glContext;
  undefined4 pname;
  float *params;
{
  double intToDoubleMagic;
  undefined4 glErrorCode;
  uint uVar2;
  double *cursor;
  int iVar4;
  double dVar5;
  undefined1 auStack_b0 [16];
  double local_a0 [16];
  undefined4 local_20;
  uint uStack_1c;
  int local_18 [2];
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    cursor = local_a0;
    iVar4 = _gleGetState(glContext,pname,cursor,local_18,auStack_b0);
    intToDoubleMagic = DOUBLE_00108d58;
    if (iVar4 == 0) {
      if (*(int *)(glContext + 0x7574) != 0) {
        return;
      }
      glErrorCode = 0x500;
      goto LAB_00021068;
    }
    if (iVar4 != -1) {
      if (local_18[0] != 0x1404) {
        if (iVar4 < 1) {
          return;
        }
        do {
          dVar5 = *cursor;
          cursor = cursor + 1;
          *params = (float)dVar5;
          params = params + 1;
          iVar4 = iVar4 + -1;
        } while (iVar4 != 0);
        return;
      }
      if (iVar4 < 1) {
        return;
      }
      do {
        uVar2 = *(uint *)cursor;
        cursor = cursor + 1;
        local_20 = 0x43300000;
        uStack_1c = uVar2 ^ 0x80000000;
        *params = (float)((double)CONCAT44(0x43300000,uVar2 ^ 0x80000000) - intToDoubleMagic);
        params = params + 1;
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
      return;
    }
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  glErrorCode = 0x502;
LAB_00021068:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glGetProgramivARB_Exec @ 0x2110c (2084 bytes) */
void _glGetProgramivARB_Exec(glContext, target, pname, params)
  int glContext;
  uint target;
  uint pname;
  uint *params;
{
  int iVar1;
  uint uVar2;
  undefined4 glErrorCode;
  uint uVar4;
  int iVar5;
  uint local_30 [5];
  
  if (-1 < *(short *)(glContext + 0x4a10)) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
    goto LAB_0002190c;
  }
  if (target == 0x8620) {
    uVar4 = 0;
LAB_00021188:
    iVar5 = *(int *)(uVar4 * 4 + glContext + 0x5420);
    if (pname == 0x88a6) goto LAB_000216f4;
    if (pname < 0x88a7) {
      if (pname == 0x880d) {
LAB_00021804:
        uVar2 = 0;
        if (uVar4 != 0) {
          uVar2 = (uint)*(ushort *)(*(int *)(glContext + 0x468c) + 0x110);
        }
        goto LAB_00021914;
      }
      if (pname < 0x880e) {
        if (pname == 0x8807) {
          uVar2 = (uint)*(ushort *)(iVar5 + 0x4f0);
          goto LAB_00021914;
        }
        if (0x8807 < pname) {
          if (pname == 0x880b) {
LAB_000217d4:
            uVar2 = 0;
            if (uVar4 != 0) {
              uVar2 = (uint)*(ushort *)(*(int *)(glContext + 0x468c) + 0x10c);
            }
            goto LAB_00021914;
          }
          if (0x880b < pname) goto LAB_000217ec;
          goto LAB_000216f4;
        }
        if (pname == 0x8677) {
          uVar2 = *(uint *)(iVar5 + 4);
          goto LAB_00021914;
        }
        if (pname < 0x8678) {
          if (pname == 0x8627) {
            uVar2 = *(uint *)(iVar5 + 0x18);
            goto LAB_00021914;
          }
        }
        else {
          if (pname == 0x8805) {
            uVar2 = (uint)*(ushort *)(iVar5 + 0x4ec);
            goto LAB_00021914;
          }
          if (pname == 0x8806) {
            uVar2 = (uint)*(ushort *)(iVar5 + 0x4ee);
            goto LAB_00021914;
          }
        }
      }
      else {
        if (pname == 0x88a0) {
          uVar2 = (uint)*(ushort *)(iVar5 + 0x50);
          goto LAB_00021914;
        }
        if (pname < 0x88a1) {
          if (pname == 0x880f) {
LAB_000217ec:
            uVar2 = 0;
            if (uVar4 != 0) {
              uVar2 = (uint)*(ushort *)(*(int *)(glContext + 0x468c) + 0x10e);
            }
            goto LAB_00021914;
          }
          if (pname < 0x880f) goto LAB_000217d4;
          if (pname == 0x8810) goto LAB_00021804;
          if (pname == 0x8876) {
            uVar2 = *(uint *)(iVar5 + 0x1c);
            goto LAB_00021914;
          }
        }
        else {
          if (pname == 0x88a3) {
            uVar2 = (uint)*(ushort *)(uVar4 * 0x10 + *(int *)(glContext + 0x468c) + 0xec);
            goto LAB_00021914;
          }
          if (pname < 0x88a4) {
            if (pname == 0x88a1) {
              uVar2 = 0x8000;
              if (uVar4 != 0) {
                uVar2 = (uint)*(ushort *)(*(int *)(glContext + 0x468c) + 0xfc);
              }
              goto LAB_00021914;
            }
            uVar4 = 0x88a2;
            goto LAB_00021354;
          }
          if (pname == 0x88a4) {
            uVar2 = (uint)*(ushort *)(iVar5 + 0x56);
            goto LAB_00021914;
          }
          if (pname == 0x88a5) {
            uVar2 = 0x100;
            if (uVar4 != 0) {
              uVar2 = (uint)*(ushort *)(*(int *)(glContext + 0x468c) + 0x102);
            }
            goto LAB_00021914;
          }
        }
      }
    }
    else {
      if (pname == 0x88b1) {
        uVar2 = (uVar4 ^ 1) << 1;
        goto LAB_00021914;
      }
      if (pname < 0x88b2) {
        if (pname == 0x88ab) {
          uVar2 = (uint)*(ushort *)(uVar4 * 0x10 + *(int *)(glContext + 0x468c) + 0xf0);
          goto LAB_00021914;
        }
        if (pname < 0x88ac) {
          if (pname == 0x88a8) {
            uVar2 = (uint)*(ushort *)(iVar5 + 0x54);
            goto LAB_00021914;
          }
          if (pname < 0x88a8) {
            uVar2 = (uint)*(ushort *)(uVar4 * 0x10 + *(int *)(glContext + 0x468c) + 0xf2);
            goto LAB_00021914;
          }
          if (pname == 0x88a9) {
            uVar2 = 0x100;
            if (uVar4 != 0) {
              uVar2 = (uint)*(ushort *)(*(int *)(glContext + 0x468c) + 0x100);
            }
            goto LAB_00021914;
          }
          uVar4 = 0x88aa;
LAB_00021354:
          if (pname == uVar4) {
LAB_000216f4:
            (**(code **)(glContext + 0x47dc))
                      (*(undefined4 *)(glContext + 0x4688),
                       *(undefined4 *)((uint)*(byte *)(glContext + 0x85a8) * 4 + iVar5 + 0x4a8),
                       pname,local_30);
            uVar2 = local_30[0];
LAB_00021914:
            local_30[0] = uVar2;
            *params = local_30[0];
            return;
          }
        }
        else {
          if (pname == 0x88ae) goto LAB_000216f4;
          if (pname < 0x88af) {
            if (pname == 0x88ac) {
              uVar2 = (uint)*(ushort *)(iVar5 + 0x52);
              goto LAB_00021914;
            }
            if (pname == 0x88ad) {
              uVar2 = 0x20;
              if (uVar4 != 0) {
                uVar2 = (uint)*(ushort *)(*(int *)(glContext + 0x468c) + 0xfe);
              }
              goto LAB_00021914;
            }
          }
          else {
            if (pname == 0x88af) {
              uVar2 = (uint)*(ushort *)(uVar4 * 0x10 + *(int *)(glContext + 0x468c) + 0xee);
              goto LAB_00021914;
            }
            if (pname == 0x88b0) {
              uVar2 = (uint)*(ushort *)(iVar5 + 0x4e);
              goto LAB_00021914;
            }
          }
        }
      }
      else {
        if (pname == 0x88b6) {
          iVar1 = uVar4 * 0x10;
          uVar2 = 0;
          if (*(short *)(iVar1 + *(int *)(glContext + 0x468c) + 0xec) == 0) goto LAB_00021914;
          (**(code **)(glContext + 0x47dc))
                    (*(undefined4 *)(glContext + 0x4688),
                     *(undefined4 *)((uint)*(byte *)(glContext + 0x85a8) * 4 + iVar5 + 0x4a8),0x88a2,
                     local_30);
          if (((((int)local_30[0] <=
                 (int)(uint)*(ushort *)(iVar1 + *(int *)(glContext + 0x468c) + 0xec)) &&
               ((**(code **)(glContext + 0x47dc))
                          (*(undefined4 *)(glContext + 0x4688),
                           *(undefined4 *)((uint)*(byte *)(glContext + 0x85a8) * 4 + iVar5 + 0x4a8),
                           0x88aa,local_30),
               (int)local_30[0] <= (int)(uint)*(ushort *)(iVar1 + *(int *)(glContext + 0x468c) + 0xf0)
               )) && ((**(code **)(glContext + 0x47dc))
                                (*(undefined4 *)(glContext + 0x4688),
                                 *(undefined4 *)
                                  ((uint)*(byte *)(glContext + 0x85a8) * 4 + iVar5 + 0x4a8),0x88a6,
                                 local_30),
                     (int)local_30[0] <=
                     (int)(uint)*(ushort *)(iVar1 + *(int *)(glContext + 0x468c) + 0xf2))) &&
             ((**(code **)(glContext + 0x47dc))
                        (*(undefined4 *)(glContext + 0x4688),
                         *(undefined4 *)((uint)*(byte *)(glContext + 0x85a8) * 4 + iVar5 + 0x4a8),
                         0x88ae,local_30),
             (int)local_30[0] <= (int)(uint)*(ushort *)(iVar1 + *(int *)(glContext + 0x468c) + 0xee)))
          {
            if ((uVar4 == 0) &&
               ((**(code **)(glContext + 0x47dc))
                          (*(undefined4 *)(glContext + 0x4688),
                           *(undefined4 *)((uint)*(byte *)(glContext + 0x85a8) * 4 + iVar5 + 0x4a8),
                           0x88b2,local_30),
               (int)(uint)*(ushort *)(*(int *)(glContext + 0x468c) + 0x118) < (int)local_30[0])) {
              uVar2 = 0;
              goto LAB_00021914;
            }
            if ((uVar4 != 1) ||
               ((((**(code **)(glContext + 0x47dc))
                            (*(undefined4 *)(glContext + 0x4688),
                             *(undefined4 *)((uint)*(byte *)(glContext + 0x85a8) * 4 + iVar5 + 0x4a8),
                             0x8808,local_30),
                 (int)local_30[0] <= (int)(uint)*(ushort *)(*(int *)(glContext + 0x468c) + 0x10c) &&
                 ((**(code **)(glContext + 0x47dc))
                            (*(undefined4 *)(glContext + 0x4688),
                             *(undefined4 *)((uint)*(byte *)(glContext + 0x85a8) * 4 + iVar5 + 0x4a8),
                             0x8809,local_30),
                 (int)local_30[0] <= (int)(uint)*(ushort *)(*(int *)(glContext + 0x468c) + 0x10e))) &&
                ((**(code **)(glContext + 0x47dc))
                           (*(undefined4 *)(glContext + 0x4688),
                            *(undefined4 *)((uint)*(byte *)(glContext + 0x85a8) * 4 + iVar5 + 0x4a8),
                            0x880a,local_30),
                (int)local_30[0] <= (int)(uint)*(ushort *)(*(int *)(glContext + 0x468c) + 0x110))))) {
              uVar2 = 1;
              goto LAB_00021914;
            }
          }
          uVar2 = 0;
          goto LAB_00021914;
        }
        if (pname < 34999) {
          if (pname == 0x88b3) {
            uVar2 = 0;
            if (uVar4 == 0) {
              uVar2 = (uint)*(ushort *)(*(int *)(glContext + 0x468c) + 0x118);
            }
            goto LAB_00021914;
          }
          if (pname < 0x88b3) goto LAB_000216f4;
          if ((pname == 0x88b4) || (pname == 0x88b5)) {
            uVar2 = 0x100;
            if (uVar4 != 0) {
              uVar2 = 0x80;
            }
            goto LAB_00021914;
          }
        }
        else {
          if (pname == 0x88f6) {
            uVar2 = 0;
            if (uVar4 != 0) {
              uVar2 = (uint)*(ushort *)(*(int *)(glContext + 0x468c) + 0x112);
            }
            goto LAB_00021914;
          }
          if (pname < 0x88f7) {
            if (pname == 0x88f4) {
              uVar2 = *(uint *)(uVar4 * 0x10 + *(int *)(glContext + 0x468c) + 0xf8);
              goto LAB_00021914;
            }
            if (pname == 0x88f5) {
              uVar2 = (uint)*(ushort *)(uVar4 * 0x10 + *(int *)(glContext + 0x468c) + 0xf4);
              goto LAB_00021914;
            }
          }
          else {
            if (pname == 0x88f7) {
              uVar2 = 0;
              if (uVar4 != 0) {
                uVar2 = (uint)*(ushort *)(*(int *)(glContext + 0x468c) + 0x114);
              }
              goto LAB_00021914;
            }
            if (pname == 0x88f8) {
              uVar2 = 0;
              if (uVar4 != 0) {
                uVar2 = (uint)*(ushort *)(*(int *)(glContext + 0x468c) + 0x116);
              }
              goto LAB_00021914;
            }
          }
        }
      }
    }
  }
  else {
    if (target < 0x8621) {
      uVar4 = 0x8200;
    }
    else {
      uVar4 = 0x8804;
    }
    if (target == uVar4) {
      uVar4 = 1;
      goto LAB_00021188;
    }
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  glErrorCode = 0x500;
LAB_0002190c:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glIsEnabled_Exec @ 0x21930 (72 bytes) */
int _glIsEnabled_Exec(glContext, cap)
  int glContext;
  undefined4 cap;
{
  undefined4 uVar1;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    uVar1 = ((int (*)())_gleGetEnabled)(glContext,cap);
  }
  else {
    if (*(int *)(glContext + 0x7574) == 0) {
      *(undefined4 *)(glContext + 0x7574) = 0x502;
    }
    uVar1 = 0;
  }
  return uVar1;
}

/* _gleGetEnabled @ 0x21978 (2652 bytes) */
int _gleGetEnabled(glContext, cap)
  int glContext;
  uint cap;
{
  uint uVar1;
  uint uVar2;
  int iVar3;
  longlong lVar4;
  
  if (cap < 0x4008) {
    if (cap < 0x4000) {
      if (cap == 0xd90) {
        return (uint)*(byte *)(glContext + 0x74e2);
      }
      if (cap < 0xd91) {
        if (cap == 0xba1) {
          return (uint)*(byte *)(glContext + 0x280d);
        }
        if (0xba1 < cap) {
          if (cap == 0xc11) {
            return (uint)*(byte *)(glContext + 0x34f0);
          }
          if (cap < 0xc12) {
            if (cap == 0xbe2) {
              return (uint)*(byte *)(glContext + 0x30e4);
            }
            if (cap < 0xbe3) {
              if (cap == 0xbc0) {
                return (uint)*(byte *)(glContext + 0x30c6);
              }
              if (cap == 0xbd0) {
                return (uint)*(byte *)(glContext + 0x313c);
              }
            }
            else {
              if (cap == 0xbf1) {
                return (uint)*(byte *)(glContext + 0x3192);
              }
              if (cap == 0xbf2) {
                return (uint)*(byte *)(glContext + 0x3193);
              }
            }
          }
          else {
            if (cap == 0xc62) {
              return (uint)*(byte *)(*(int *)(glContext + 0x53d4) * 0x94 + glContext + 0x3d7a);
            }
            if (cap < 0xc63) {
              if (cap == 0xc60) {
                return (uint)*(byte *)(*(int *)(glContext + 0x53d4) * 0x94 + glContext + 0x3d78);
              }
              if (cap == 0xc61) {
                return (uint)*(byte *)(*(int *)(glContext + 0x53d4) * 0x94 + glContext + 0x3d79);
              }
            }
            else {
              if (cap == 0xc63) {
                return (uint)*(byte *)(*(int *)(glContext + 0x53d4) * 0x94 + glContext + 0x3d7b);
              }
              if (cap == 0xd80) {
                return (uint)*(byte *)(glContext + 0x74f2);
              }
            }
          }
LAB_000223a8:
          if (*(int *)(glContext + 0x7574) == 0) {
            *(undefined4 *)(glContext + 0x7574) = 0x500;
          }
          return 0;
        }
        if (cap == 0xb44) {
          return (uint)*(byte *)(glContext + 0x34da);
        }
        if (cap < 0xb45) {
          if (cap == 0xb24) {
            return (uint)*(byte *)(glContext + 0x318c);
          }
          if (cap < 0xb25) {
            if (cap == 0xb10) {
              return (uint)*(byte *)(glContext + 0x343c);
            }
            if (cap == 0xb20) {
              return (uint)*(byte *)(glContext + 0x318d);
            }
          }
          else {
            if (cap == 0xb41) {
              return (uint)*(byte *)(glContext + 0x34d9);
            }
            if (cap == 0xb42) {
              return (uint)*(byte *)(glContext + 0x34d8);
            }
          }
          goto LAB_000223a8;
        }
        if (cap == 0xb60) {
          return (uint)*(byte *)(glContext + 0x316a);
        }
        if (cap < 0xb61) {
          if (cap == 0xb50) {
            return (uint)*(byte *)(glContext + 0x30aa);
          }
          if (cap == 0xb57) {
            return (uint)*(byte *)(glContext + 0x30ab);
          }
          goto LAB_000223a8;
        }
        if (cap == 0xb71) {
          return (uint)*(byte *)(glContext + 0x3128);
        }
        if (cap != 0xb90) goto LAB_000223a8;
        uVar1 = *(uint *)(glContext + 0x3520);
        uVar2 = (uint)*(byte *)(glContext + 0x7583);
      }
      else {
        if (cap == 0xdb3) {
          return (uint)*(byte *)(glContext + 0x74ee);
        }
        if (cap < 0xdb4) {
          if (cap == 0xd96) {
            return (uint)*(byte *)(glContext + 0x74e8);
          }
          if (cap < 0xd97) {
            if (cap == 0xd93) {
              return (uint)*(byte *)(glContext + 0x74e5);
            }
            if (cap < 0xd94) {
              if (cap == 0xd91) {
                return (uint)*(byte *)(glContext + 0x74e3);
              }
              if (cap == 0xd92) {
                return (uint)*(byte *)(glContext + 0x74e4);
              }
            }
            else {
              if (cap == 0xd94) {
                return (uint)*(byte *)(glContext + 0x74e6);
              }
              if (cap == 0xd95) {
                return (uint)*(byte *)(glContext + 0x74e7);
              }
            }
          }
          else {
            if (cap == 0xdb0) {
              return (uint)*(byte *)(glContext + 0x74eb);
            }
            if (cap < 0xdb1) {
              if (cap == 0xd97) {
                return (uint)*(byte *)(glContext + 0x74e0);
              }
              if (cap == 0xd98) {
                return (uint)*(byte *)(glContext + 0x74e1);
              }
            }
            else {
              if (cap == 0xdb1) {
                return (uint)*(byte *)(glContext + 0x74ec);
              }
              if (cap == 0xdb2) {
                return (uint)*(byte *)(glContext + 0x74ed);
              }
            }
          }
          goto LAB_000223a8;
        }
        if (cap == 0xde0) {
          uVar1 = *(uint *)(*(int *)(glContext + 0x53d4) * 0x7c + glContext + 0x3534);
LAB_00022360:
          return uVar1 >> 4 & 1;
        }
        if (cap < 0xde1) {
          if (cap == 0xdb6) {
            return (uint)*(byte *)(glContext + 0x74f1);
          }
          if (cap < 0xdb7) {
            if (cap == 0xdb4) {
              return (uint)*(byte *)(glContext + 0x74ef);
            }
            if (cap == 0xdb5) {
              return (uint)*(byte *)(glContext + 0x74f0);
            }
          }
          else {
            if (cap == 0xdb7) {
              return (uint)*(byte *)(glContext + 0x74e9);
            }
            if (cap == 0xdb8) {
              return (uint)*(byte *)(glContext + 0x74ea);
            }
          }
          goto LAB_000223a8;
        }
        if (cap == 0x2a02) {
          return (uint)*(byte *)(glContext + 0x34dc);
        }
        if (cap < 0x2a03) {
          if (cap == 0xde1) {
            uVar1 = *(uint *)(*(int *)(glContext + 0x53d4) * 0x7c + glContext + 0x3534);
            goto LAB_0002236c;
          }
          if (cap == 0x2a01) {
            return (uint)*(byte *)(glContext + 0x34db);
          }
          goto LAB_000223a8;
        }
        uVar2 = cap - 0x3000;
        if (5 < uVar2) goto LAB_000223a8;
        uVar1 = *(uint *)(glContext + 0x4188);
      }
    }
    else {
      uVar1 = *(uint *)(glContext + 0x30a0);
      uVar2 = cap - 0x4000;
    }
    uVar1 = uVar1 >> (uVar2 & 0x3f);
LAB_00022378:
    return uVar1 & 1;
  }
  if (cap == 0x8200) {
LAB_00022328:
    return (uint)*(byte *)(glContext + 0x466c);
  }
  if (cap < 0x8201) {
    if (cap == 0x8076) {
      uVar1 = *(uint *)(*(int *)(glContext + 0x4a60) + 0x334) >> 0x12;
      goto LAB_0002227c;
    }
    if (0x8076 < cap) {
      if (cap == 0x809f) {
        return (uint)*(byte *)(glContext + 0x41f2);
      }
      if (cap < 0x80a0) {
        if (cap == 0x8079) {
          uVar1 = *(uint *)(*(int *)(glContext + 0x4a60) + 0x334) >> 0x16;
          goto LAB_0002227c;
        }
        if (cap < 0x807a) {
          if (cap == 0x8077) {
            return (uint)*(byte *)(glContext + 0x48eb);
          }
          if (cap == 0x8078) {
            iVar3 = *(int *)(glContext + 0x4a60);
            lVar4 = ___ashldi3(0,0x1000000,*(undefined4 *)(glContext + 0x53d8));
            if ((*(uint *)(iVar3 + 0x330) & (uint)((ulonglong)lVar4 >> 0x20)) == 0 &&
                (*(uint *)(iVar3 + 0x334) & (uint)lVar4) == 0) {
              return 0;
            }
            return 1;
          }
        }
        else {
          if (cap == 0x809d) {
            return (uint)*(byte *)(glContext + 0x41f0);
          }
          if (cap == 0x809e) {
            return (uint)*(byte *)(glContext + 0x41f1);
          }
        }
      }
      else {
        if (cap == 0x80d1) {
          return *(uint *)(glContext + 0x3410) >> 6 & 1;
        }
        if (cap < 0x80d2) {
          if (cap == 0x80a0) {
            return (uint)*(byte *)(glContext + 0x41f3);
          }
          if (cap == 0x80d0) {
            return *(uint *)(glContext + 0x3410) >> 5 & 1;
          }
        }
        else {
          if (cap == 0x80d2) {
            return *(uint *)(glContext + 0x3410) >> 7 & 1;
          }
          if (cap == 0x81fb) {
            return *(uint *)(*(int *)(glContext + 0x53d4) * 0x7c + glContext + 0x3534) >> 8 & 1;
          }
        }
      }
      goto LAB_000223a8;
    }
    if (cap == 0x802e) {
      uVar1 = *(uint *)(glContext + 0x3410);
LAB_0002236c:
      return uVar1 >> 3 & 1;
    }
    if (cap < 0x802f) {
      if (cap != 0x8011) {
        if (cap < 0x8012) {
          if (cap == 0x6090) {
            return (uint)*(byte *)(glContext + 0x280c);
          }
          if (cap == 0x8010) {
            uVar1 = (uint)*(byte *)(glContext + 0x3413);
            goto LAB_00022378;
          }
        }
        else {
          if (cap == 0x8012) {
            uVar1 = *(uint *)(glContext + 0x3410);
            goto LAB_00022398;
          }
          if (cap == 0x8024) {
            uVar1 = *(uint *)(glContext + 0x3410);
            goto LAB_00022360;
          }
        }
        goto LAB_000223a8;
      }
      uVar1 = *(uint *)(glContext + 0x3410);
    }
    else {
      if (cap != 0x806f) {
        if (0x806f < cap) {
          if (cap == 0x8074) {
            uVar1 = *(uint *)(*(int *)(glContext + 0x4a60) + 0x334) >> 0x10;
          }
          else {
            if (cap != 0x8075) goto LAB_000223a8;
            uVar1 = *(uint *)(*(int *)(glContext + 0x4a60) + 0x334) >> 0x11;
          }
          goto LAB_0002227c;
        }
        if (cap == 0x8037) {
          return (uint)*(byte *)(glContext + 0x34dd);
        }
        if (cap == 0x803a) {
          return (uint)*(byte *)(glContext + 0x280e);
        }
        goto LAB_000223a8;
      }
      uVar1 = *(uint *)(*(int *)(glContext + 0x53d4) * 0x7c + glContext + 0x3534);
    }
    return uVar1 >> 1 & 1;
  }
  if (cap == 0x8643) {
    return (uint)*(byte *)(glContext + 0x4666);
  }
  if (cap < 0x8644) {
    if (cap == 0x851d) {
      return (uint)*(byte *)(glContext + 0x465c);
    }
    if (cap < 0x851e) {
      if (cap == 0x845e) {
        uVar1 = *(uint *)(*(int *)(glContext + 0x4a60) + 0x334) >> 0x14;
LAB_0002227c:
        return uVar1 & 1;
      }
      if (cap < 0x845f) {
        if (cap != 0x8457) {
          if (cap == 0x8458) {
            return (uint)*(byte *)(glContext + 0x4fea);
          }
          goto LAB_000223a8;
        }
        uVar1 = *(uint *)(*(int *)(glContext + 0x4a60) + 0x334) >> 0x13;
        goto LAB_0002227c;
      }
      if (cap != 0x84f5) {
        if (cap != 0x8513) goto LAB_000223a8;
        uVar1 = (uint)*(byte *)(*(int *)(glContext + 0x53d4) * 0x7c + glContext + 0x3537);
        goto LAB_00022378;
      }
    }
    else if (cap != 0x85b3) {
      if (cap < 0x85b4) {
        if (cap == 0x8522) {
          return (uint)*(byte *)(glContext + 0x41f8);
        }
        if (cap == 0x8535) {
          return (uint)*(byte *)(glContext + 0x41f9);
        }
      }
      else {
        if (cap == 0x8620) {
          return (uint)*(byte *)(glContext + 0x4664);
        }
        if (cap == 0x8642) {
          return (uint)*(byte *)(glContext + 0x4665);
        }
      }
      goto LAB_000223a8;
    }
    uVar1 = *(uint *)(*(int *)(glContext + 0x53d4) * 0x7c + glContext + 0x3534);
  }
  else {
    if (cap == 0x8804) goto LAB_00022328;
    if (cap < 0x8805) {
      if (cap == 0x86a7) {
        return (uint)*(byte *)(glContext + 0x4661);
      }
      if (cap < 0x86a8) {
        if (cap == 0x864f) {
          return (uint)*(byte *)(glContext + 0x3129);
        }
        if (cap == 0x86a6) {
          return (uint)*(byte *)(glContext + 0x4662);
        }
      }
      else {
        if (cap == 0x86ad) {
          uVar1 = *(uint *)(*(int *)(glContext + 0x4a60) + 0x334) >> 0x15;
          goto LAB_0002227c;
        }
        if (cap == 0x86de) {
          return (uint)*(byte *)(glContext + 0x3ce4);
        }
      }
      goto LAB_000223a8;
    }
    if (cap != 0x8910) {
      if (cap < 0x8911) {
        if (cap == 0x8861) {
          return (uint)*(byte *)(glContext + 0x343d);
        }
        if (cap == 0x8890) {
          return (uint)*(byte *)(glContext + 0x312a);
        }
      }
      else {
        if (cap == 0x8a0c) {
          uVar1 = *(uint *)(*(int *)(glContext + 0x4a60) + 0x334) >> 0x17;
          goto LAB_0002227c;
        }
        if (cap == 0x19262) {
          return (uint)*(byte *)(glContext + 0x50b5);
        }
      }
      goto LAB_000223a8;
    }
    uVar1 = *(uint *)(glContext + 0x3520);
  }
LAB_00022398:
  return uVar1 >> 2 & 1;
}

/* _gleShareSharedState @ 0x223d4 (88 bytes) */
int _gleShareSharedState(param_1)
  int param_1;
{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x5148);
  _pthread_mutex_lock(iVar1 + 0x8028);
  *(undefined1 *)(iVar1 + 0x8024) = 1;
  *(int *)(iVar1 + 0x8020) = *(int *)(iVar1 + 0x8020) + 1;
  _pthread_mutex_unlock(iVar1 + 0x8028);
  return iVar1;
}

/* _gleSetEnable_DITHER @ 0x2242c (32 bytes) */
void _gleSetEnable_DITHER(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  uint param_3;
{
  if (*(byte *)(param_1 + 0x313c) == param_3) {
    return;
  }
  *(char *)(param_1 + 0x313c) = (char)param_3;
  *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x400;
  return;
}

/* _glStencilMask_Exec @ 0x2244c (68 bytes) */
void _glStencilMask_Exec(glContext, mask)
  int glContext;
  undefined4 mask;
{
  uint uVar1;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    uVar1 = *(uint *)(glContext + 0x310);
    *(undefined4 *)((uint)*(byte *)(glContext + 0x7583) * 4 + glContext + 0x3198) = mask;
    *(uint *)(glContext + 0x310) = uVar1 | 0x100000;
    return;
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  *(undefined4 *)(glContext + 0x7574) = 0x502;
  return;
}

/* _glClearColor_Exec @ 0x22490 (228 bytes) */
void _glClearColor_Exec(int glContext,float red,float green,float blue,float alpha)
{
  float floatZero;
  float floatOne;
  float dVar3;
  float dVar4;
  
  floatOne = FLOAT_00108e54;
  floatZero = FLOAT_00108e50;
  if (-1 < *(short *)(glContext + 0x4a10)) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    *(undefined4 *)(glContext + 0x7574) = 0x502;
    return;
  }
  dVar3 = (double)FLOAT_00108e50;
  dVar4 = (double)FLOAT_00108e54;
  *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 8;
  if (red < (double)dVar3) {
    *(float *)(glContext + 0x3100) = floatZero;
  }
  else if ((double)dVar4 < red) {
    *(float *)(glContext + 0x3100) = floatOne;
  }
  else {
    *(float *)(glContext + 0x3100) = (float)red;
  }
  if (green < (double)dVar3) {
    *(float *)(glContext + 0x3104) = floatZero;
  }
  else if ((double)dVar4 < green) {
    *(float *)(glContext + 0x3104) = floatOne;
  }
  else {
    *(float *)(glContext + 0x3104) = (float)green;
  }
  if (blue < (double)dVar3) {
    *(float *)(glContext + 0x3108) = floatZero;
  }
  else if ((double)dVar4 < blue) {
    *(float *)(glContext + 0x3108) = floatOne;
  }
  else {
    *(float *)(glContext + 0x3108) = (float)blue;
  }
  if (alpha < (double)dVar3) {
    *(float *)(glContext + 0x310c) = floatZero;
    return;
  }
  if ((double)dVar4 < alpha) {
    *(float *)(glContext + 0x310c) = floatOne;
    return;
  }
  *(float *)(glContext + 0x310c) = (float)alpha;
  return;
}

/* _glMultiTexCoord4fv_Exec @ 0x225b4 (60 bytes) */
double _glMultiTexCoord4fv_Exec(glContext, target, v)
  int glContext;
  uint target;
  undefined4 *v;
{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  
  uVar1 = v[3];
  iVar4 = glContext + (target & 7) * 0x10;
  uVar2 = v[1];
  uVar3 = v[2];
  *(undefined4 *)(iVar4 + 0x120) = *v;
  *(undefined4 *)(iVar4 + 300) = uVar1;
  *(undefined4 *)(iVar4 + 0x124) = uVar2;
  *(undefined4 *)(iVar4 + 0x128) = uVar3;
  *(uint *)(glContext + 0x486c) = *(uint *)(glContext + 0x486c) | 3;
  return;
}

/* _glVertex4fv_Exec @ 0x225f0 (48 bytes) */
void _glVertex4fv_Exec(glContext, v)
  int glContext;
  float *v;
{
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = *(code **)(glContext + 0x4884);
  if (*(int *)(glContext + 0x4858) == *(int *)(glContext + 0x485c)) {
    UNRECOVERED_JUMPTABLE = *(code **)(glContext + 0x28);
  }
                    
                    
  (*((int (*)(int,int,double,double,double,double))UNRECOVERED_JUMPTABLE))
            (glContext, v, (double)*v, (double)v[1], (double)v[2], (double)v[3]);
  return;
}

/* _glGenProgramsARB_Exec @ 0x22620 (236 bytes) */
void _glGenProgramsARB_Exec(glContext, n, programs)
  int glContext;
  int n;
  int *programs;
{
  undefined4 glErrorCode;
  int iVar2;
  int loopIndex;
  int iVar4;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (-1 < n) {
      iVar4 = *(int *)(glContext + 0x5148);
      if (*(char *)(iVar4 + 0x8024) != '\0') {
        _pthread_mutex_lock(iVar4 + 0x8028);
        iVar4 = *(int *)(glContext + 0x5148);
      }
      iVar4 = _gleGenHashNames(iVar4 + 0x4010,n);
      if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) != '\0') {
        _pthread_mutex_unlock(*(int *)(glContext + 0x5148) + 0x8028);
      }
      if (iVar4 == 0) {
        return;
      }
      loopIndex = 0;
      if (n < 1) {
        return;
      }
      do {
        iVar2 = loopIndex + iVar4;
        loopIndex = loopIndex + 1;
        *programs = iVar2;
        programs = programs + 1;
        n = n + -1;
      } while (n != 0);
      return;
    }
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x501;
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

/* _glBindProgramARB_Exec @ 0x2270c (276 bytes) */
void _glBindProgramARB_Exec(glContext, target, program)
  int glContext;
  uint target;
  undefined4 program;
{
  undefined4 glErrorCode;
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  
  if (-1 < *(short *)(glContext + 0x4a10)) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
LAB_0002279c:
    *(undefined4 *)(glContext + 0x7574) = glErrorCode;
    return;
  }
  if (target == 0x8620) {
    uVar1 = 0;
  }
  else {
    if (target < 0x8621) {
      uVar2 = 0x8200;
    }
    else {
      uVar2 = 0x8804;
    }
    if (target != uVar2) {
      if (*(int *)(glContext + 0x7574) != 0) {
        return;
      }
      glErrorCode = 0x500;
      goto LAB_0002279c;
    }
    uVar1 = 1;
  }
  if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) != '\0') {
    iVar3 = *(int *)(glContext + 0x5148) + 0x8028;
    _pthread_mutex_lock(iVar3);
    ((int (*)())_gleBindPipelineProgram)(glContext,uVar1,program);
    _pthread_mutex_unlock(iVar3);
    return;
  }
  ((int (*)())_gleBindPipelineProgram)(glContext,uVar1,program);
  return;
}

/* _gleBindPipelineProgram @ 0x22820 (644 bytes) */
int _gleBindPipelineProgram(glContext, param_2, program)
  int glContext;
  uint param_2;
  int program;
{
  int loopIndex2;
  int remaining;
  char cVar1;
  int iVar2;
  undefined *puVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  undefined4 *puVar8;
  int iVar9;
  int loopIndex;
  undefined4 *puVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  
  iVar12 = *(int *)(glContext + 0x5148) + 0x4010;
  if (program == 0) {
    iVar12 = param_2 * 4;
    iVar7 = *(int *)(iVar12 + glContext + 0x5428);
    iVar14 = iVar7 + 0x10;
  }
  else {
    iVar7 = _gleLookupHashObject(iVar12,program);
    if (iVar7 == 0) {
      iVar7 = _gleCreatePipelineProgramObject(glContext,param_2,program);
      iVar14 = iVar7 + 0x10;
      _gleCreatePluginPipelineProgram(glContext,iVar14);
      _gleAddHashNameAndObject(glContext,iVar12,iVar7);
    }
    else {
      if (*(ushort *)(iVar7 + 0x4ca) != param_2) {
        if (*(int *)(glContext + 0x7574) != 0) {
          return;
        }
        *(undefined4 *)(glContext + 0x7574) = 0x502;
        return;
      }
      iVar14 = iVar7 + 0x10;
    }
    iVar12 = param_2 << 2;
  }
  **(undefined1 **)(glContext + 0x5418) = 0;
  loopIndex2 = 0;
  *(undefined4 *)(glContext + 0x541c) = 0xffffffff;
  *(int *)(iVar7 + 8) = *(int *)(iVar7 + 8) + 1;
  cVar1 = *(char *)(glContext + 0x85a4);
  iVar13 = *(int *)(iVar12 + glContext + 0x5420);
  *(int *)(iVar12 + glContext + 0x5420) = iVar7;
  if (cVar1 != '\0') {
    puVar8 = (undefined4 *)(iVar7 + 0x4a8);
    puVar11 = (undefined4 *)(param_2 * 4 + glContext + 0x886c);
    do {
      uVar4 = *puVar8;
      loopIndex2 = loopIndex2 + 1;
      puVar8 = puVar8 + 1;
      *puVar11 = uVar4;
      puVar11 = puVar11 + 0xb8;
    } while (loopIndex2 < (int)(uint)*(byte *)(glContext + 0x85a4));
  }
  if (param_2 == 0) {
    remaining = 9;
    iVar12 = 5;
    uVar6 = *(uint *)(glContext + 0x31c) | 0x400000;
  }
  else {
    if (param_2 != 1) {
      remaining = 0;
      iVar12 = 0;
      goto LAB_0002299c;
    }
    remaining = 5;
    iVar12 = 0xe;
    uVar6 = *(uint *)(glContext + 0x31c) | 0x1000000;
  }
  *(uint *)(glContext + 0x31c) = uVar6;
LAB_0002299c:
  iVar9 = param_2 * 0xa30;
  if (*(int *)(iVar9 + *(int *)(glContext + 0x5148) + 0x8a98) != *(int *)(iVar14 + 0x14)) {
    ((void (*)())_glePPUpdateProgram)(glContext,iVar14);
    *(undefined4 *)(iVar14 + 0x14) = *(undefined4 *)(iVar9 + *(int *)(glContext + 0x5148) + 0x8a98);
  }
  _gleUpdateInverseNeeds(glContext);
  loopIndex = 0;
  if (remaining != 0) {
    iVar5 = *(int *)(glContext + 0x5148);
    iVar12 = iVar12 * 4 + glContext;
    do {
      iVar2 = loopIndex * 4;
      loopIndex = loopIndex + 1;
      uVar6 = *(uint *)(iVar12 + 0x310) |
              *(uint *)(iVar2 + iVar14 + 0x18) &
              (*(uint *)(iVar2 + iVar5 + iVar9 + 0x8a74) | ~*(uint *)(iVar2 + iVar13 + 0x28));
      *(uint *)(iVar12 + 0x310) = uVar6;
      *(uint *)(iVar12 + 0x310) = uVar6 & *(uint *)(iVar2 + iVar14 + 0x18);
      iVar12 = iVar12 + 4;
      remaining = remaining + -1;
    } while (remaining != 0);
  }
  iVar12 = *(int *)(iVar13 + 8) + -1;
  *(int *)(iVar13 + 8) = iVar12;
  if (iVar12 == 0) {
    _gleFreePipelineProgramObject(glContext,iVar13);
  }
  _gleSelectVertexSubmitFunc(glContext);
  puVar3 = PTR__gleSetClipInterpFunc_00112038;
  *(undefined **)(glContext + 0x49c8) = PTR__gleSetEyeInterpFunc_0011203c;
  *(undefined **)(glContext + 0x49cc) = puVar3;
  return;
}

/* _glProgramStringARB_Exec @ 0x22aa4 (796 bytes) */
void _glProgramStringARB_Exec(glContext, target, format, len, string)
  int glContext;
  uint target;
  int format;
  int len;
  int string;
{
  int allocatedBlock;
  int remaining4;
  int loopIndex5;
  int loopIndex4;
  int remaining2;
  int loopIndex3;
  int loopIndex2;
  int loopIndex;
  undefined4 glErrorCode;
  uint *puVar1;
  bool bVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int remaining3;
  int remaining;
  uint local_60 [15];
  
  if (-1 < *(short *)(glContext + 0x4a10)) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
    goto LAB_00022bb8;
  }
  if (-1 < len) {
    if (format != 0x8875) {
LAB_00022b48:
      if (*(int *)(glContext + 0x7574) != 0) {
        return;
      }
      glErrorCode = 0x500;
      goto LAB_00022bb8;
    }
    if (target == 0x8620) {
      iVar7 = 0;
    }
    else {
      if (target < 0x8621) {
        uVar4 = 0x8200;
      }
      else {
        uVar4 = 0x8804;
      }
      if (target != uVar4) goto LAB_00022b48;
      iVar7 = 1;
    }
    loopIndex2 = 0;
    allocatedBlock = _malloc(len + 1);
    bVar2 = len == 0;
    if (0 < len) {
      do {
        if (*(char *)(string + loopIndex2) == '\0') break;
        *(char *)(allocatedBlock + loopIndex2) = *(char *)(string + loopIndex2);
        loopIndex2 = loopIndex2 + 1;
        bVar2 = loopIndex2 == len;
      } while (loopIndex2 < len);
    }
    *(undefined1 *)(allocatedBlock + loopIndex2) = 0;
    if (bVar2) {
      iVar7 = *(int *)(iVar7 * 4 + glContext + 0x5420);
      if (*(int *)(iVar7 + 0x14) != 0) {
        ((void (*)())_gleModifyPluginPipelineProgram)(glContext,iVar7 + 0x10,1);
        _free(*(undefined4 *)(iVar7 + 0x14));
      }
      *(undefined1 *)(iVar7 + 0x4c) = 1;
      *(undefined4 *)(iVar7 + 0x1c) = 0x8875;
      *(int *)(iVar7 + 0x18) = loopIndex2;
      *(int *)(iVar7 + 0x14) = allocatedBlock;
      *(short *)(iVar7 + 0x4c8) = (short)target;
      if (target == 0x8620) {
        iVar6 = iVar7 + 0x10;
        remaining3 = 9;
        puVar5 = (undefined4 *)(iVar7 + 0x28);
        loopIndex3 = 0;
        do {
          uVar3 = *puVar5;
          puVar5 = puVar5 + 1;
          *(undefined4 *)((int)local_60 + loopIndex3) = uVar3;
          loopIndex3 = loopIndex3 + 4;
          remaining3 = remaining3 + -1;
        } while (remaining3 != 0);
        ((void (*)())_glePPParse)(glContext,iVar6,0);
        ((void (*)())_glePPUpdateProgram)(glContext,iVar6);
        _gleUpdateInverseNeeds(glContext);
        remaining = 9;
        loopIndex5 = 0;
        iVar8 = glContext;
        do {
          puVar1 = (uint *)((int)local_60 + loopIndex5);
          loopIndex5 = loopIndex5 + 4;
          uVar4 = *(uint *)(iVar8 + 0x324) | *(uint *)(iVar6 + 0x18) & ~*puVar1;
          *(uint *)(iVar8 + 0x324) = uVar4;
          puVar1 = (uint *)(iVar6 + 0x18);
          iVar6 = iVar6 + 4;
          *(uint *)(iVar8 + 0x324) = uVar4 & *puVar1;
          iVar8 = iVar8 + 4;
          remaining = remaining + -1;
        } while (remaining != 0);
        _gleSelectVertexSubmitFunc(glContext);
        *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x400000;
      }
      if (target == 0x8804) {
        puVar5 = (undefined4 *)(iVar7 + 0x28);
        remaining2 = 5;
        iVar7 = iVar7 + 0x10;
        loopIndex = 0;
        do {
          uVar3 = *puVar5;
          puVar5 = puVar5 + 1;
          *(undefined4 *)((int)local_60 + loopIndex) = uVar3;
          loopIndex = loopIndex + 4;
          remaining2 = remaining2 + -1;
        } while (remaining2 != 0);
        ((void (*)())_glePPParse)(glContext,iVar7,1);
        ((void (*)())_glePPUpdateProgram)(glContext,iVar7);
        _gleUpdateInverseNeeds(glContext);
        remaining4 = 9;
        loopIndex4 = 0;
        iVar6 = glContext;
        do {
          puVar1 = (uint *)((int)local_60 + loopIndex4);
          loopIndex4 = loopIndex4 + 4;
          uVar4 = *(uint *)(iVar6 + 0x348) | *(uint *)(iVar7 + 0x18) & ~*puVar1;
          *(uint *)(iVar6 + 0x348) = uVar4;
          puVar1 = (uint *)(iVar7 + 0x18);
          iVar7 = iVar7 + 4;
          *(uint *)(iVar6 + 0x348) = uVar4 & *puVar1;
          iVar6 = iVar6 + 4;
          remaining4 = remaining4 + -1;
        } while (remaining4 != 0);
        _gleSelectVertexSubmitFunc(glContext);
        *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x1000000;
      }
      if (target != 0x8200) {
        return;
      }
      _gleLFSParse(glContext);
      _gleSelectVertexSubmitFunc(glContext);
      *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x1000000;
      return;
    }
    _free(allocatedBlock);
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  glErrorCode = 0x501;
LAB_00022bb8:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glePPParse @ 0x22dc0 (4884 bytes) */
void _glePPParse(glContext, param_2, param_3)
  int glContext;
  int *param_2;
  int param_3;
{
  int allocatedBlock;
  bool bVar1;
  bool bVar2;
  short sVar3;
  ushort uVar4;
  int iVar5;
  int allocatedBlock2;
  int *piVar7;
  int *piVar8;
  undefined1 *puVar9;
  undefined4 uVar10;
  undefined2 uVar11;
  short sVar12;
  undefined4 *puVar13;
  int iVar14;
  uint uVar15;
  int iVar16;
  int iVar17;
  int *piVar18;
  int *piVar19;
  int *piVar20;
  int iVar21;
  int iVar22;
  uint uVar23;
  undefined4 uVar24;
  uint local_110;
  uint local_10c;
  undefined4 local_108;
  undefined4 local_104;
  uint local_100;
  undefined4 local_fc;
  undefined4 local_f8;
  undefined4 local_f4;
  uint local_f0;
  undefined4 local_ec;
  undefined4 local_e8;
  undefined4 local_e4;
  undefined4 local_e0;
  undefined4 local_dc;
  undefined4 local_d8;
  uint local_d0;
  uint local_cc;
  undefined4 local_c8;
  uint local_c4;
  uint local_c0;
  uint local_bc;
  uint local_b8;
  uint local_b4;
  uint local_b0;
  uint local_ac;
  uint local_a8;
  uint local_a4;
  uint local_a0;
  uint local_9c;
  uint local_90;
  undefined4 local_8c;
  uint local_88;
  uint local_84;
  uint local_80;
  undefined4 local_7c;
  uint local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  uint local_60;
  undefined4 local_5c;
  int local_58 [5];
  
  iVar22 = param_2[1];
  iVar17 = *param_2;
  if (param_2[0x12f] != 0) {
    _gleVecFree(param_2[0x12f]);
    param_2[0x12f] = 0;
  }
  if (iVar17 != 0) {
    _PPStreamFree(iVar17);
    *param_2 = 0;
  }
  bVar1 = param_3 == 1;
  iVar17 = _PPParserCreate(bVar1 << 1);
  _PPParserInit();
  if (bVar1) {
    local_fc = 0x80;
    local_f8 = 0x40;
    local_f4 = 0;
    local_110 = 0x80;
    local_10c = 0x80;
    local_d8 = 0;
  }
  else {
    local_d8 = 0x10;
    local_fc = 0x100;
    local_f8 = 0x20;
    local_f4 = 2;
    local_110 = 0x100;
    local_10c = 0x100;
  }
  local_100 = 0x100;
  local_104 = 0x8000;
  local_ec = 0x10;
  local_e8 = 4;
  local_e4 = 1;
  local_e0 = 6;
  local_dc = 8;
  local_108 = 8;
  local_f0 = 8;
  _memcpy(iVar17 + 0x450,&local_110,0x3c);
  _PPParserAttachString(iVar17,iVar22,1);
  iVar22 = _PPStreamCreate();
  _PPParserAttachStream(iVar17,iVar22);
  iVar5 = _PPParserParse(iVar17);
  if (iVar5 == 0) {
    *(undefined8 *)(param_2 + 0x130) = *(undefined8 *)(iVar17 + 0x34);
    iVar5 = ((int (*)())_glePPPruneParamArrays)(iVar17);
    bVar2 = iVar5 == 0;
    if (bVar2) {
      iVar5 = ((int (*)())_glePPPruneAttribs)(iVar17);
      bVar2 = iVar5 == 0;
      if (!bVar2) goto LAB_00022f84;
      iVar5 = ((int (*)())_glePPPruneOutputs)(iVar17);
      bVar2 = iVar5 == 0;
      if (!bVar2) goto LAB_00022f84;
      iVar5 = ((int (*)())_glePPPruneLocals)(iVar17);
      bVar2 = iVar5 == 0;
      if (!bVar2) goto LAB_00022f84;
      iVar5 = ((int (*)())_glePPPruneParams)(iVar17);
      bVar2 = iVar5 == 0;
      if (!bVar2) goto LAB_00022f84;
      piVar20 = *(int **)(iVar22 + 0x10);
      uVar24 = *(undefined4 *)(iVar22 + 0x14);
      _PPStreamChunkListGetStream(piVar20,0,&local_60,iVar22);
      _PPStreamChunkListGetStream(uVar24,0,&local_5c,iVar22);
      allocatedBlock = _calloc(local_60,8);
      allocatedBlock2 = _calloc(local_5c,8);
      _PPStreamChunkListGetStream(piVar20,allocatedBlock,&local_60,iVar22);
      _PPStreamChunkListGetStream(uVar24,allocatedBlock2,&local_5c,iVar22);
      if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) != '\0') {
        _pthread_mutex_lock(*(int *)(glContext + 0x5148) + 0x8028);
      }
      ((void (*)())_glePPLogParameters)(glContext,param_2,local_60,allocatedBlock,local_5c,allocatedBlock2);
      if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) != '\0') {
        _pthread_mutex_unlock(*(int *)(glContext + 0x5148) + 0x8028);
      }
      piVar19 = *(int **)(iVar22 + 0x20);
      uVar23 = 0;
      piVar18 = *(int **)(iVar22 + 0x14);
      piVar7 = (int *)_PPStreamChunkListCreateFromChunkList(piVar19);
      piVar8 = (int *)_PPStreamChunkListCreateFromChunkList(piVar18);
      iVar21 = *piVar20;
      if (local_60 != 0) {
        puVar13 = (undefined4 *)(allocatedBlock + 4);
        do {
          uVar24 = *puVar13;
          puVar13 = puVar13 + 2;
          iVar14 = *piVar7;
          sVar12 = (short)uVar24;
          for (iVar16 = *piVar19; iVar16 != 0; iVar16 = *(int *)(iVar16 + 8)) {
            if ((((*(uint *)(iVar16 + 0xc) >> 0x1d != 0) &&
                 ((*(uint *)(iVar16 + 0xc) >> 0x12 & 0xff) != 0x4a)) &&
                ((*(uint *)(iVar16 + 0x1c) >> 0x17 & 7) == 2)) &&
               (*(short *)(iVar16 + 0x22) == *(short *)(iVar21 + 0x12))) {
              *(short *)(iVar14 + 0x22) = sVar12;
            }
            uVar15 = *(uint *)(iVar16 + 0xc);
            if (((1 < uVar15 >> 0x1d) && (3 < (uVar15 >> 0x12 & 0xff) - 0x41)) &&
               (((*(uint *)(iVar16 + 0x24) >> 0x17 & 7) == 2 &&
                (*(short *)(iVar16 + 0x2a) == *(short *)(iVar21 + 0x12))))) {
              *(short *)(iVar14 + 0x2a) = sVar12;
              uVar15 = *(uint *)(iVar16 + 0xc);
            }
            if (((2 < uVar15 >> 0x1d) && ((*(uint *)(iVar16 + 0x2c) >> 0x17 & 7) == 2)) &&
               (*(short *)(iVar16 + 0x32) == *(short *)(iVar21 + 0x12))) {
              *(short *)(iVar14 + 0x32) = sVar12;
            }
            iVar14 = *(int *)(iVar14 + 8);
          }
          iVar14 = *piVar8;
          for (iVar16 = *piVar18; iVar16 != 0; iVar16 = *(int *)(iVar16 + 8)) {
            if (*(short *)(iVar16 + 0xe) == *(short *)(iVar21 + 0x12)) {
              sVar3 = *(short *)(iVar14 + 0xe);
              *(short *)(iVar14 + 0xe) = sVar12;
              *(short *)(iVar14 + 0x12) = (*(short *)(iVar14 + 0x12) + sVar12) - sVar3;
            }
            iVar14 = *(int *)(iVar14 + 8);
          }
          *(short *)(iVar21 + 0x12) = sVar12;
          uVar23 = uVar23 + 1;
          iVar21 = *(int *)(iVar21 + 8);
        } while (uVar23 < local_60);
      }
      uVar23 = 0;
      _PPStreamChunkListSort(piVar20);
      iVar21 = *piVar20;
      uVar24 = _PPStreamChunkListCreate();
      for (; iVar21 != 0; iVar21 = *(int *)(iVar21 + 8)) {
        if ((*(ushort *)(iVar21 + 0x12) != 0) && (uVar23 < *(ushort *)(iVar21 + 0x12))) {
          do {
            puVar9 = (undefined1 *)_calloc(0x1c,1);
            *(uint *)(puVar9 + 0xc) = *(uint *)(puVar9 + 0xc) & 0xffe0ffff;
            *(short *)(puVar9 + 0x12) = (short)uVar23;
            uVar23 = uVar23 + 1;
            *puVar9 = 3;
            _PPStreamChunkListAddChunk(uVar24,puVar9);
          } while (uVar23 < *(ushort *)(iVar21 + 0x12));
        }
        uVar10 = _PPStreamChunkCreateFromChunk(iVar21);
        _PPStreamChunkListAddChunk(uVar24,uVar10);
        uVar23 = *(ushort *)(iVar21 + 0x12) + 1;
      }
      if (allocatedBlock != 0) {
        _free(allocatedBlock);
      }
      if (allocatedBlock2 != 0) {
        _free(allocatedBlock2);
      }
      _PPStreamAttachOperationsChunkList(iVar22,piVar7);
      _PPStreamAttachParamBindingsChunkList(iVar22,uVar24);
      _PPStreamAttachParamBindingArraysChunkList(iVar22,piVar8);
      _PPStreamGetStream(iVar22,0,local_58);
      iVar5 = _gleVecAlloc(local_58[0] << 3);
      _PPStreamGetStream(iVar22,iVar5,local_58);
      *(undefined2 *)((int)param_2 + 0x46) = *(undefined2 *)(iVar5 + 0x12);
      *(undefined2 *)((int)param_2 + 0x3e) = *(undefined2 *)(iVar5 + 0x1a);
      *(undefined2 *)((int)param_2 + 0x42) = *(undefined2 *)(iVar5 + 0x22);
      *(undefined2 *)(param_2 + 0x11) = *(undefined2 *)(iVar5 + 0x2a);
      *(undefined2 *)(param_2 + 0x10) = *(undefined2 *)(iVar5 + 0x52);
      if (bVar1) {
        uVar11 = _PPStreamGetTexOperationCount(iVar22);
        *(undefined2 *)((int)param_2 + 0x4de) = uVar11;
        *(undefined2 *)(param_2 + 0x138) = 1;
        *(short *)(param_2 + 0x137) = *(short *)(param_2 + 0x10) - *(short *)((int)param_2 + 0x4de);
      }
      param_2[0x12f] = iVar5;
      *param_2 = iVar22;
      if (((*(byte *)(iVar17 + 0x442) & 1) != 0) &&
         ((*(ushort *)(*(int *)(glContext + 0x468c) + 0x11a) & 2) == 0)) {
        for (iVar5 = **(int **)(iVar22 + 0x18); iVar5 != 0; iVar5 = *(int *)(iVar5 + 8)) {
          local_110 = *(uint *)(iVar5 + 0xc);
          local_10c = *(uint *)(iVar5 + 0x10);
          if ((local_110 >> 0x10 & 0xf) == 1) break;
        }
        uVar24 = *(undefined4 *)(iVar22 + 0x1c);
        local_100 = 0;
        uVar23 = 0;
        local_fc = 0;
        sVar12 = _PPStreamChunkListGetMaxIndex(uVar24);
        local_100 = local_100 & 0xfff0ffff | 0x10000;
        local_fc = CONCAT22((*(unsigned short *)((unsigned char *)&(local_fc) + 0)),sVar12 + 1);
        _PPStreamAddOutputBinding(iVar22,&local_100);
        local_7c = 0;
        local_80 = 0;
        sVar12 = _PPStreamChunkListGetMaxIndex(uVar24);
        local_80 = local_80 & 0xfff0ffff | 0x80000;
        local_7c = CONCAT22((*(unsigned short *)((unsigned char *)&(local_7c) + 0)),sVar12 + 1);
        _PPStreamAddOutputBinding(iVar22,&local_80);
        uVar24 = *(undefined4 *)(iVar22 + 0x10);
        do {
          local_f0 = 0;
          local_ec = 0;
          local_e8 = 0;
          local_e4 = 0;
          sVar12 = _PPStreamChunkListGetMaxIndex(uVar24);
          local_ec = CONCAT22((*(unsigned short *)((unsigned char *)&(local_ec) + 0)),sVar12 + 1);
          if ((*(ushort *)(*(int *)(glContext + 0x468c) + 0x11a) & 1) == 0) {
            uVar15 = local_f0 & 0xffe03fff | 0x104000;
          }
          else {
            uVar15 = local_f0 & 0xffe03fff | 0x100000;
          }
          local_f0 = (uVar23 & 3) << 0xc | uVar15 & 0xffffc8ff;
          uVar23 = uVar23 + 1;
          _PPStreamAddParamBinding(iVar22,&local_f0);
        } while (uVar23 < 4);
        uVar24 = *(undefined4 *)(iVar22 + 0x10);
        uVar23 = 0;
        do {
          local_70 = 0;
          local_6c = 0;
          local_68 = 0;
          local_64 = 0;
          sVar12 = _PPStreamChunkListGetMaxIndex(uVar24);
          local_6c = CONCAT22((*(unsigned short *)((unsigned char *)&(local_6c) + 0)),sVar12 + 1);
          if ((*(ushort *)(*(int *)(glContext + 0x468c) + 0x11a) & 1) == 0) {
            uVar15 = local_70 & 0xffe03fff | 0x104000;
          }
          else {
            uVar15 = local_70 & 0xffe03fff | 0x100000;
          }
          local_70 = (uVar23 & 3) << 0xc | uVar15 & 0xffffc8ff | 0x300;
          uVar23 = uVar23 + 1;
          _PPStreamAddParamBinding(iVar22,&local_70);
        } while (uVar23 < 4);
        uVar4 = *(ushort *)(*(int *)(glContext + 0x468c) + 0x11a);
        uVar23 = uVar4 & 1;
        if ((uVar4 & 1) == 0) {
          local_90 = uVar23;
          local_8c = uVar23;
          local_88 = uVar23;
          local_84 = uVar23;
          sVar12 = _PPStreamChunkListGetMaxIndex(uVar24);
          local_8c = CONCAT22((*(unsigned short *)((unsigned char *)&(local_8c) + 0)),sVar12 + 1);
          _PPStreamAddTempUsage(iVar22,&local_90);
          local_d0 = uVar23 << 0x1a | 0x40880000;
          local_c0 = uVar23 << 0x15 | 0x10d8000;
          local_b8 = uVar23 << 0xf |
                     uVar23 << 0x11 | uVar23 << 0x13 | uVar23 << 0x15 | uVar23 << 0x17;
          local_c8 = 0x3e000;
          local_c4 = local_8c & 0xffff;
          local_bc = (uint)(ushort)((short)local_ec - 3);
          local_b4 = local_10c & 0xffff;
          local_cc = uVar23;
          local_b0 = uVar23;
          local_ac = uVar23;
          local_a8 = uVar23;
          local_a4 = uVar23;
          local_a0 = uVar23;
          local_9c = uVar23;
          _PPStreamAddOperation(iVar22,&local_d0,0,0);
          local_c0 = uVar23 << 0x15 | 0x10d8000;
          local_b0 = uVar23 << 0x15 | 0x8d8000;
          local_b8 = uVar23 << 0x17 | 0x2a8000;
          local_c8 = 0x3e000;
          local_d0 = 0x68fc0000;
          local_bc = (uint)(ushort)((short)local_ec - 2);
          local_b4 = local_10c & 0xffff;
          local_c4 = local_8c & 0xffff;
          local_ac = local_8c & 0xffff;
          local_cc = uVar23;
          local_a8 = uVar23;
          local_a4 = uVar23;
          local_a0 = uVar23;
          local_9c = uVar23;
          _PPStreamAddOperation(iVar22,&local_d0,0,0);
          local_b8 = uVar23 << 0x17 | 0x550000;
          local_c0 = uVar23 << 0x15 | 0x10d8000;
          local_b0 = uVar23 << 0x15 | 0x8d8000;
          local_d0 = 0x6cfc0000;
          local_c8 = 0x3e000;
          local_bc = (uint)(ushort)((short)local_ec - 1);
          local_b4 = local_10c & 0xffff;
          local_c4 = local_8c & 0xffff;
          local_ac = local_8c & 0xffff;
          local_cc = uVar23;
          local_a8 = uVar23;
          local_a4 = uVar23;
          local_a0 = uVar23;
          local_9c = uVar23;
          _PPStreamAddOperation(iVar22,&local_d0,0,0);
          local_c0 = uVar23 << 0x15 | 0x10d8000;
          local_b0 = uVar23 << 0x15 | 0x8d8000;
          local_b8 = uVar23 << 0x17 | 0x7f8000;
          local_c8 = 0x7e000;
          local_d0 = 0x6cfc0000;
          local_c4 = local_fc & 0xffff;
          local_bc = local_ec & 0xffff;
          local_b4 = local_10c & 0xffff;
          local_ac = local_8c & 0xffff;
          local_cc = uVar23;
          local_a8 = uVar23;
          local_a4 = uVar23;
          local_a0 = uVar23;
          local_9c = uVar23;
          _PPStreamAddOperation(iVar22,&local_d0,0,0);
          local_c0 = uVar23 << 0x15 | 0x10d8000;
          local_b8 = uVar23 << 0xf |
                     uVar23 << 0x11 | uVar23 << 0x13 | uVar23 << 0x15 | uVar23 << 0x17;
          local_d0 = 0x4c880000;
          local_c8 = 0x3e000;
          local_c4 = local_8c & 0xffff;
          local_bc = (uint)(ushort)((*(unsigned short *)((unsigned char *)&(local_6c) + 2)) - 3);
          local_b4 = local_10c & 0xffff;
          local_cc = uVar23;
          local_b0 = uVar23;
          local_ac = uVar23;
          local_a8 = uVar23;
          local_a4 = uVar23;
          local_a0 = uVar23;
          local_9c = uVar23;
          _PPStreamAddOperation(iVar22,&local_d0,0,0);
          local_c0 = uVar23 << 0x15 | 0x10d8000;
          local_b0 = uVar23 << 0x15 | 0x8d8000;
          local_b8 = uVar23 << 0x17 | 0x2a8000;
          local_c8 = 0x3e000;
          local_d0 = 0x68fc0000;
          local_bc = (uint)(ushort)((short)local_6c - 2);
          local_b4 = local_10c & 0xffff;
          local_c4 = local_8c & 0xffff;
          local_ac = local_8c & 0xffff;
          local_cc = uVar23;
          local_a8 = uVar23;
          local_a4 = uVar23;
          local_a0 = uVar23;
          local_9c = uVar23;
          _PPStreamAddOperation(iVar22,&local_d0,0,0);
          local_b8 = uVar23 << 0x17 | 0x550000;
          local_c0 = uVar23 << 0x15 | 0x10d8000;
          local_b0 = uVar23 << 0x15 | 0x8d8000;
          local_d0 = 0x6cfc0000;
          local_c8 = 0x3e000;
          local_bc = (uint)(ushort)((short)local_6c - 1);
          local_c4 = local_8c & 0xffff;
          local_ac = local_8c & 0xffff;
          local_b4 = local_10c & 0xffff;
          local_cc = uVar23;
          local_a8 = uVar23;
          local_a4 = uVar23;
          local_a0 = uVar23;
          local_9c = uVar23;
          _PPStreamAddOperation(iVar22,&local_d0,0,0);
          local_c0 = uVar23 << 0x15 | 0x10d8000;
          local_b8 = uVar23 << 0x17 | 0x7f8000;
          local_b0 = uVar23 << 0x15 | 0x8d8000;
          local_d0 = 0x6cfc0000;
          local_c8 = 0x7e000;
          local_ac = local_8c & 0xffff;
          local_9c = uVar23;
        }
        else {
          local_d0 = 0x40a40000;
          local_c8 = 0x62000;
          local_c0 = 0x10d8000;
          local_b8 = 0xd8000;
          local_c4 = local_fc & 0xffff;
          local_bc = (uint)(ushort)((short)local_ec - 3);
          local_cc = 0;
          local_b4 = local_10c & 0xffff;
          local_b0 = 0;
          local_ac = 0;
          local_a8 = 0;
          local_a4 = 0;
          local_a0 = 0;
          local_9c = 0;
          _PPStreamAddOperation(iVar22,&local_d0,0,0);
          local_d0 = 0x48a40000;
          local_c8 = 0x64000;
          local_c0 = 0x10d8000;
          local_b8 = 0xd8000;
          local_c4 = local_fc & 0xffff;
          local_bc = (uint)(ushort)((short)local_ec - 2);
          local_cc = 0;
          local_b4 = local_10c & 0xffff;
          local_b0 = 0;
          local_ac = 0;
          local_a8 = 0;
          local_a4 = 0;
          local_a0 = 0;
          local_9c = 0;
          _PPStreamAddOperation(iVar22,&local_d0,0,0);
          local_d0 = 0x48a40000;
          local_c8 = 0x68000;
          local_c0 = 0x10d8000;
          local_b8 = 0xd8000;
          local_c4 = local_fc & 0xffff;
          local_bc = (uint)(ushort)((short)local_ec - 1);
          local_cc = 0;
          local_b4 = local_10c & 0xffff;
          local_b0 = 0;
          local_ac = 0;
          local_a8 = 0;
          local_a4 = 0;
          local_a0 = 0;
          local_9c = 0;
          _PPStreamAddOperation(iVar22,&local_d0,0,0);
          local_d0 = 0x48a40000;
          local_c8 = 0x70000;
          local_c0 = 0x10d8000;
          local_b8 = 0xd8000;
          local_c4 = local_fc & 0xffff;
          local_bc = local_ec & 0xffff;
          local_cc = 0;
          local_b4 = local_10c & 0xffff;
          local_b0 = 0;
          local_ac = 0;
          local_a8 = 0;
          local_a4 = 0;
          local_a0 = 0;
          local_9c = 0;
          _PPStreamAddOperation(iVar22,&local_d0,0,0);
          local_d0 = 0x48a40000;
          local_c8 = 0x62000;
          local_c0 = 0x10d8000;
          local_b8 = 0xd8000;
          local_c4 = local_7c & 0xffff;
          local_bc = (uint)(ushort)((short)local_6c - 3);
          local_cc = 0;
          local_b4 = local_10c & 0xffff;
          local_b0 = 0;
          local_ac = 0;
          local_a8 = 0;
          local_a4 = 0;
          local_a0 = 0;
          local_9c = 0;
          _PPStreamAddOperation(iVar22,&local_d0,0,0);
          local_d0 = 0x48a40000;
          local_c8 = 0x64000;
          local_c0 = 0x10d8000;
          local_b8 = 0xd8000;
          local_c4 = local_7c & 0xffff;
          local_bc = (uint)(ushort)((short)local_6c - 2);
          local_cc = 0;
          local_b4 = local_10c & 0xffff;
          local_b0 = 0;
          local_ac = 0;
          local_a8 = 0;
          local_a4 = 0;
          local_a0 = 0;
          local_9c = 0;
          _PPStreamAddOperation(iVar22,&local_d0,0,0);
          local_d0 = 0x48a40000;
          local_c8 = 0x68000;
          local_c0 = 0x10d8000;
          local_b8 = 0xd8000;
          local_bc = (uint)(ushort)((short)local_6c - 1);
          local_c4 = local_7c & 0xffff;
          local_b4 = local_10c & 0xffff;
          local_cc = 0;
          local_b0 = 0;
          local_ac = 0;
          local_a8 = 0;
          local_a4 = 0;
          local_a0 = 0;
          local_9c = 0;
          _PPStreamAddOperation(iVar22,&local_d0,0,0);
          local_9c = 0;
          local_d0 = 0x48a40000;
          local_c8 = 0x70000;
          local_c0 = 0x10d8000;
          local_b8 = 0xd8000;
          local_b0 = 0;
          local_ac = 0;
        }
        local_b4 = local_10c & 0xffff;
        local_bc = local_6c & 0xffff;
        local_c4 = local_7c & 0xffff;
        local_cc = local_9c;
        local_a8 = local_9c;
        local_a4 = local_9c;
        local_a0 = local_9c;
        _PPStreamAddOperation(iVar22,&local_d0,0,0);
      }
      if (param_3 == 0) {
        iVar5 = _PPEmulatorProgramCreate();
        ((void (*)())_PPEmulatorProgramSetupHandlesFromPPStream)(iVar5,glContext,iVar22);
        _PPEmulatorProgramConvertFromPPStream(iVar5,iVar22);
        if (param_2[0x135] != 0) {
          _PPEmulatorProgramFree(param_2[0x135]);
        }
        param_2[0x135] = iVar5;
      }
      **(undefined1 **)(glContext + 0x5418) = 0;
      *(undefined4 *)(glContext + 0x541c) = 0xffffffff;
    }
    else {
LAB_00022f84:
      _PPParserBuildErrorString(iVar17,iVar5,0);
    }
    if (bVar2) goto LAB_000240b0;
  }
  if (*(int *)(glContext + 0x7574) == 0) {
    *(undefined4 *)(glContext + 0x7574) = 0x502;
  }
  _strncpy(*(char **)(glContext + 0x5418),(char *)(iVar17 + 0x3c),0x600);
  *(undefined4 *)(glContext + 0x541c) = 0;
  _PPParserAttachStream(iVar17,0);
LAB_000240b0:
  _PPParserFree(iVar17);
  return;
}

/* _glePPPruneParamArrays @ 0x240d4 (300 bytes) */
int _glePPPruneParamArrays(param_1)
  int param_1;
{
  short sVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  int iVar7;
  
  piVar5 = *(int **)(*(int *)(param_1 + 0x1c) + 0x14);
  piVar6 = *(int **)(*(int *)(param_1 + 0x1c) + 0x20);
  iVar7 = *piVar5;
  do {
    iVar2 = iVar7;
    if (iVar2 == 0) {
      return 0;
    }
    sVar1 = *(short *)(iVar2 + 0xe);
    for (iVar4 = *piVar6; iVar4 != 0; iVar4 = *(int *)(iVar4 + 8)) {
      if (((((*(uint *)(iVar4 + 0xc) >> 0x1d != 0) &&
            ((*(uint *)(iVar4 + 0xc) >> 0x12 & 0xff) != 0x4a)) &&
           ((*(uint *)(iVar4 + 0x1c) >> 0x17 & 7) == 2)) &&
          ((*(short *)(iVar4 + 0x22) == sVar1 && ((int)*(uint *)(iVar4 + 0x1c) < 0)))) ||
         ((((uVar3 = *(uint *)(iVar4 + 0xc), 1 < uVar3 >> 0x1d &&
            ((3 < (uVar3 >> 0x12 & 0xff) - 0x41 && ((*(uint *)(iVar4 + 0x24) >> 0x17 & 7) == 2))))
           && ((*(short *)(iVar4 + 0x2a) == sVar1 && ((int)*(uint *)(iVar4 + 0x24) < 0)))) ||
          ((((2 < uVar3 >> 0x1d && ((*(uint *)(iVar4 + 0x2c) >> 0x17 & 7) == 2)) &&
            (*(short *)(iVar4 + 0x32) == sVar1)) && ((int)*(uint *)(iVar4 + 0x2c) < 0)))))) break;
    }
    iVar7 = *(int *)(iVar2 + 8);
    if (iVar4 == 0) {
      _PPStreamChunkListRemoveChunk(piVar5,iVar2);
    }
  } while( true );
}

/* _glePPPruneAttribs @ 0x24200 (496 bytes) */
int _glePPPruneAttribs(param_1)
  int param_1;
{
  uint loopIndex;
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  int iVar7;
  
  piVar6 = *(int **)(*(int *)(param_1 + 0x1c) + 0x18);
  piVar5 = *(int **)(*(int *)(param_1 + 0x1c) + 0x20);
  iVar4 = 0;
  iVar7 = *piVar6;
  if (*piVar6 != 0) {
    do {
      if (((*(byte *)(param_1 + 0x442) & 1) == 0) || (iVar7 != *piVar6)) {
        for (iVar4 = *piVar5; iVar4 != 0; iVar4 = *(int *)(iVar4 + 8)) {
          if ((((((*(uint *)(iVar4 + 0xc) >> 0x1d != 0) &&
                 ((*(uint *)(iVar4 + 0xc) >> 0x12 & 0xff) != 0x4a)) &&
                ((*(uint *)(iVar4 + 0x1c) & 0x3800000) == 0)) &&
               (*(short *)(iVar4 + 0x22) == *(short *)(iVar7 + 0x12))) ||
              (((uVar3 = *(uint *)(iVar4 + 0xc), 1 < uVar3 >> 0x1d &&
                (3 < (uVar3 >> 0x12 & 0xff) - 0x41)) &&
               (((*(uint *)(iVar4 + 0x24) & 0x3800000) == 0 &&
                (*(short *)(iVar4 + 0x2a) == *(short *)(iVar7 + 0x12))))))) ||
             (((2 < uVar3 >> 0x1d && ((*(uint *)(iVar4 + 0x2c) & 0x3800000) == 0)) &&
              (*(short *)(iVar4 + 0x32) == *(short *)(iVar7 + 0x12))))) {
            iVar4 = *piVar6;
            goto joined_r0x0002431c;
          }
        }
LAB_0002435c:
        iVar4 = *(int *)(iVar7 + 8);
        _PPStreamChunkListRemoveChunk(piVar6,iVar7);
      }
      else {
LAB_00024370:
        iVar4 = *(int *)(iVar7 + 8);
      }
      iVar7 = iVar4;
    } while (iVar4 != 0);
    iVar4 = *piVar6;
  }
  loopIndex = 0;
  for (; iVar4 != 0; iVar4 = *(int *)(iVar4 + 8)) {
    if (loopIndex != *(ushort *)(iVar4 + 0x12)) {
      _glePPRelocateAttrib((uint)*(ushort *)(iVar4 + 0x12),loopIndex,piVar5);
      *(short *)(iVar4 + 0x12) = (short)loopIndex;
    }
    loopIndex = loopIndex + 1;
  }
  uVar2 = 0x35;
  if ((uint)piVar6[2] <= *(uint *)(param_1 + 0x468)) {
    uVar2 = 0;
  }
  return uVar2;
joined_r0x0002431c:
  if (iVar4 == iVar7) goto LAB_00024370;
  iVar1 = _PPStreamAttribBindingIsEqual(iVar7 + 0xc,iVar4 + 0xc);
  if (iVar1 != 0) {
    _glePPRelocateAttrib((uint)*(ushort *)(iVar7 + 0x12),(uint)*(ushort *)(iVar4 + 0x12),piVar5);
    goto LAB_0002435c;
  }
  iVar4 = *(int *)(iVar4 + 8);
  goto joined_r0x0002431c;
}

/* _glePPPruneOutputs @ 0x243f0 (344 bytes) */
int _glePPPruneOutputs(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  uint loopIndex;
  int iVar6;
  
  piVar4 = *(int **)(*(int *)(param_1 + 0x1c) + 0x1c);
  piVar3 = *(int **)(*(int *)(param_1 + 0x1c) + 0x20);
  iVar2 = 0;
  iVar6 = *piVar4;
  if (*piVar4 != 0) {
LAB_00024424:
    for (iVar2 = *piVar3; iVar2 != 0; iVar2 = *(int *)(iVar2 + 8)) {
      if ((((*(uint *)(iVar2 + 0xc) >> 0x12 & 0xff) < 0x4b) &&
          ((*(uint *)(iVar2 + 0x14) >> 0x11 & 7) == 3)) &&
         (*(short *)(iVar2 + 0x1a) == *(short *)(iVar6 + 0x12))) {
        iVar2 = *piVar4;
        goto joined_r0x00024488;
      }
    }
LAB_000244c8:
    iVar2 = *(int *)(iVar6 + 8);
    _PPStreamChunkListRemoveChunk(piVar4,iVar6);
    goto LAB_000244e0;
  }
LAB_000244ec:
  loopIndex = 0;
  for (; iVar2 != 0; iVar2 = *(int *)(iVar2 + 8)) {
    if (loopIndex != *(ushort *)(iVar2 + 0x12)) {
      _glePPRelocateOutput((uint)*(ushort *)(iVar2 + 0x12),loopIndex,piVar3);
      *(short *)(iVar2 + 0x12) = (short)loopIndex;
    }
    loopIndex = loopIndex + 1;
  }
  return 0;
joined_r0x00024488:
  if (iVar2 == iVar6) goto LAB_000244dc;
  iVar1 = _PPStreamOutputBindingIsEqual(iVar6 + 0xc,iVar2 + 0xc);
  if (iVar1 != 0) {
    _glePPRelocateOutput((uint)*(ushort *)(iVar6 + 0x12),(uint)*(ushort *)(iVar2 + 0x12),piVar3);
    goto LAB_000244c8;
  }
  iVar2 = *(int *)(iVar2 + 8);
  goto joined_r0x00024488;
LAB_000244dc:
  iVar2 = *(int *)(iVar6 + 8);
LAB_000244e0:
  iVar6 = iVar2;
  if (iVar2 == 0) goto code_r0x000244e8;
  goto LAB_00024424;
code_r0x000244e8:
  iVar2 = *piVar4;
  goto LAB_000244ec;
}

/* _glePPPruneLocals @ 0x24548 (412 bytes) */
int _glePPPruneLocals(param_1)
  int param_1;
{
  uint loopIndex;
  uint uVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  
  piVar4 = *(int **)(*(int *)(param_1 + 0x1c) + 4);
  piVar3 = *(int **)(*(int *)(param_1 + 0x1c) + 0x20);
  iVar2 = 0;
  iVar5 = *piVar4;
  if (*piVar4 != 0) {
    do {
      for (iVar2 = *piVar3; iVar2 != 0; iVar2 = *(int *)(iVar2 + 8)) {
        if (((((((*(uint *)(iVar2 + 0xc) >> 0x12 & 0xff) < 0x4b) &&
               ((*(uint *)(iVar2 + 0x14) >> 0x11 & 7) == 1)) &&
              (*(short *)(iVar2 + 0x1a) == *(short *)(iVar5 + 0x12))) ||
             (((uVar1 = *(uint *)(iVar2 + 0xc), uVar1 >> 0x1d != 0 &&
               ((uVar1 >> 0x12 & 0xff) != 0x4a)) &&
              (((*(uint *)(iVar2 + 0x1c) >> 0x17 & 7) == 1 &&
               (*(short *)(iVar2 + 0x22) == *(short *)(iVar5 + 0x12))))))) ||
            (((1 < uVar1 >> 0x1d && (3 < (uVar1 >> 0x12 & 0xff) - 0x41)) &&
             (((*(uint *)(iVar2 + 0x24) >> 0x17 & 7) == 1 &&
              (*(short *)(iVar2 + 0x2a) == *(short *)(iVar5 + 0x12))))))) ||
           (((2 < uVar1 >> 0x1d && ((*(uint *)(iVar2 + 0x2c) >> 0x17 & 7) == 1)) &&
            (*(short *)(iVar2 + 0x32) == *(short *)(iVar5 + 0x12))))) {
          iVar2 = *(int *)(iVar5 + 8);
          goto LAB_00024684;
        }
      }
      iVar2 = *(int *)(iVar5 + 8);
      _PPStreamChunkListRemoveChunk(piVar4,iVar5);
LAB_00024684:
      iVar5 = iVar2;
    } while (iVar2 != 0);
    iVar2 = *piVar4;
  }
  loopIndex = 0;
  for (; iVar2 != 0; iVar2 = *(int *)(iVar2 + 8)) {
    if (loopIndex != *(ushort *)(iVar2 + 0x12)) {
      _glePPRelocateLocal((uint)*(ushort *)(iVar2 + 0x12),loopIndex,piVar3);
      *(short *)(iVar2 + 0x12) = (short)loopIndex;
    }
    loopIndex = loopIndex + 1;
  }
  return 0;
}

/* _glePPPruneParams @ 0x246e4 (648 bytes) */
int _glePPPruneParams(param_1)
  int param_1;
{
  uint loopIndex;
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  int iVar8;
  
  iVar1 = *(int *)(param_1 + 0x1c);
  piVar7 = *(int **)(iVar1 + 0x10);
  piVar5 = *(int **)(iVar1 + 0x14);
  iVar8 = *piVar7;
  piVar6 = *(int **)(iVar1 + 0x20);
  iVar1 = 0;
  if (iVar8 != 0) {
    do {
      iVar1 = *piVar5;
      if (iVar1 == 0) break;
      do {
        if ((*(ushort *)(iVar1 + 0xe) <= *(ushort *)(iVar8 + 0x12)) &&
           (*(ushort *)(iVar8 + 0x12) <= *(ushort *)(iVar1 + 0x12))) {
          *(undefined4 *)(iVar8 + 0x14) = 1;
          break;
        }
        iVar1 = *(int *)(iVar1 + 8);
      } while (iVar1 != 0);
      iVar8 = *(int *)(iVar8 + 8);
    } while (iVar8 != 0);
    iVar1 = *piVar7;
  }
  iVar8 = 0;
  if (iVar1 != 0) {
LAB_0002477c:
    if (*(int *)(iVar1 + 0x14) != 0) {
LAB_00024868:
      iVar8 = *piVar7;
joined_r0x00024874:
      do {
        if (iVar8 == 0) goto LAB_000248e8;
        if ((iVar1 + 0xc != iVar8 + 0xc) &&
           (iVar2 = _PPStreamParamBindingIsEqual(iVar1 + 0xc,iVar8 + 0xc), iVar2 != 0)) {
          if (*(int *)(iVar8 + 0x14) == 0) {
            _glePPRelocateParam((uint)*(ushort *)(iVar8 + 0x12),(uint)*(ushort *)(iVar1 + 0x12),
                                piVar6,0);
            iVar2 = *(int *)(iVar8 + 8);
            _PPStreamChunkListRemoveChunk(piVar7,iVar8);
            iVar8 = iVar2;
            goto joined_r0x00024874;
          }
          if (*(int *)(iVar1 + 0x14) != 0) {
            return 0x29;
          }
        }
        iVar8 = *(int *)(iVar8 + 8);
      } while( true );
    }
    for (iVar8 = *piVar6; iVar8 != 0; iVar8 = *(int *)(iVar8 + 8)) {
      if ((((((*(uint *)(iVar8 + 0xc) >> 0x1d != 0) &&
             ((*(uint *)(iVar8 + 0xc) >> 0x12 & 0xff) != 0x4a)) &&
            ((*(uint *)(iVar8 + 0x1c) >> 0x17 & 7) == 2)) &&
           (*(short *)(iVar8 + 0x22) == *(short *)(iVar1 + 0x12))) ||
          (((uVar4 = *(uint *)(iVar8 + 0xc), 1 < uVar4 >> 0x1d &&
            (3 < (uVar4 >> 0x12 & 0xff) - 0x41)) &&
           (((*(uint *)(iVar8 + 0x24) >> 0x17 & 7) == 2 &&
            (*(short *)(iVar8 + 0x2a) == *(short *)(iVar1 + 0x12))))))) ||
         (((2 < uVar4 >> 0x1d && ((*(uint *)(iVar8 + 0x2c) >> 0x17 & 7) == 2)) &&
          (*(short *)(iVar8 + 0x32) == *(short *)(iVar1 + 0x12))))) goto LAB_00024868;
    }
    iVar8 = *(int *)(iVar1 + 8);
    _PPStreamChunkListRemoveChunk(piVar7,iVar1);
    goto LAB_000248ec;
  }
LAB_000248f8:
  loopIndex = 0;
  for (; iVar8 != 0; iVar8 = *(int *)(iVar8 + 8)) {
    *(undefined4 *)(iVar8 + 0x14) = 0;
    if (loopIndex != *(ushort *)(iVar8 + 0x12)) {
      _glePPRelocateParam((uint)*(ushort *)(iVar8 + 0x12),loopIndex,piVar6,piVar5);
      *(short *)(iVar8 + 0x12) = (short)loopIndex;
    }
    loopIndex = loopIndex + 1;
  }
  uVar3 = 0x34;
  if ((uint)piVar7[2] <= *(uint *)(param_1 + 0x464)) {
    uVar3 = 0;
  }
  return uVar3;
LAB_000248e8:
  iVar8 = *(int *)(iVar1 + 8);
LAB_000248ec:
  iVar1 = iVar8;
  if (iVar8 == 0) goto code_r0x000248f4;
  goto LAB_0002477c;
code_r0x000248f4:
  iVar8 = *piVar7;
  goto LAB_000248f8;
}

/* _glePPLogParameters @ 0x2496c (728 bytes) */
void _glePPLogParameters(glContext, param_2, param_3, param_4, param_5, param_6)
  int glContext;
  int param_2;
  uint param_3;
  int param_4;
  uint param_5;
  int param_6;
{
  uint loopIndex5;
  uint loopIndex4;
  uint loopIndex3;
  int loopIndex;
  int remaining;
  uint uVar1;
  int iVar2;
  undefined4 *cursor;
  undefined2 uVar4;
  int iVar5;
  uint *puVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  uint loopIndex2;
  uint uVar12;
  uint uVar13;
  undefined4 local_a0 [12];
  uint local_70;
  uint local_6c;
  uint local_60;
  uint local_5c;
  
  loopIndex2 = 0;
  uVar7 = (uint)*(ushort *)(param_2 + 0x4ba);
  iVar8 = *(int *)(glContext + 0x5148);
  iVar5 = uVar7 * 0xa30 + iVar8;
  iVar2 = *(int *)(iVar5 + 0x8a98) + 1;
  *(int *)(iVar5 + 0x8a98) = iVar2;
  *(int *)(param_2 + 0x14) = iVar2;
  uVar1 = 0;
  if (*(uint *)(iVar5 + 0x8a9c) != 0) {
    puVar6 = *(uint **)(iVar5 + 0x8aa0);
    do {
      uVar1 = *puVar6;
      puVar6 = puVar6 + 1;
      if (param_3 <= uVar1) break;
      loopIndex2 = loopIndex2 + 1;
      uVar1 = 0;
    } while (loopIndex2 < *(uint *)(iVar5 + 0x8a9c));
  }
  loopIndex3 = 0;
  do {
    cursor = local_a0;
    remaining = 9;
    do {
      *cursor = 0;
      cursor = cursor + 1;
      remaining = remaining + -1;
    } while (remaining != 0);
    loopIndex = 0;
    for (uVar13 = param_3; uVar13 != 0; uVar13 = uVar13 - 1) {
      iVar5 = loopIndex * 8;
      loopIndex = loopIndex + 1;
      *(uint *)(iVar5 + param_4) = *(uint *)(iVar5 + param_4) & 0xff1fffff;
    }
    loopIndex5 = 0;
    iVar2 = -1;
    if (param_5 != 0) {
      do {
        local_60 = *(uint *)(param_6 + loopIndex5 * 8);
        local_5c = *(uint *)(loopIndex5 * 8 + param_6 + 4);
        uVar12 = local_60 & 0xffff;
        uVar9 = (local_5c & 0xffff) + 1;
        if (loopIndex3 <= loopIndex5) {
          iVar5 = uVar12 * 8;
          iVar10 = iVar5 + param_4;
          local_70 = *(undefined4 *)(iVar5 + param_4);
          local_6c = *(uint *)(iVar10 + 4) & 0xffff0000;
          iVar2 = ((int (*)())_glePPLogParam)(glContext,iVar8,uVar7,local_70,local_6c,uVar9 - uVar12,0xffffffff,
                                 local_a0,uVar1);
          if (iVar2 < 0) break;
          uVar12 = uVar12 + 1;
          *(uint *)(iVar5 + param_4) = local_70;
          *(uint *)(iVar10 + 4) = local_6c;
          *(short *)(iVar10 + 6) = (short)iVar2;
          *(uint *)(iVar5 + param_4) = *(uint *)(iVar5 + param_4) & 0xff1fffff | 0x200000;
        }
        for (; uVar12 < uVar9; uVar12 = uVar12 + 1) {
          iVar5 = uVar12 * 8;
          iVar10 = iVar5 + param_4;
          local_70 = *(undefined4 *)(iVar5 + param_4);
          local_6c = *(uint *)(iVar10 + 4) & 0xffff0000;
          iVar2 = ((int (*)())_glePPLogParam)(glContext,iVar8,uVar7,local_70,local_6c,1,iVar2 + 1,local_a0,uVar1);
          *(uint *)(iVar5 + param_4) = local_70;
          *(uint *)(iVar10 + 4) = local_6c;
          *(short *)(iVar10 + 6) = (short)iVar2;
          *(uint *)(iVar5 + param_4) = *(uint *)(iVar5 + param_4) & 0xff1fffff | 0x200000;
        }
        loopIndex5 = loopIndex5 + 1;
      } while (loopIndex5 < param_5);
    }
    if ((loopIndex5 == param_5) || (loopIndex3 = loopIndex3 + 1, param_5 < loopIndex3)) {
      loopIndex4 = 0;
      if (param_3 != 0) {
        do {
          iVar2 = loopIndex4 * 8;
          local_70 = *(uint *)(iVar2 + param_4);
          iVar5 = iVar2 + param_4;
          if ((local_70 >> 0x15 & 7) == 0) {
            local_6c = *(uint *)(iVar5 + 4) & 0xffff0000;
            uVar4 = ((int (*)())_glePPLogParam)(glContext,iVar8,uVar7,local_70,local_6c,1,0xffffffff,local_a0,uVar1
                                  );
            *(uint *)(iVar2 + param_4) = local_70;
            *(uint *)(iVar5 + 4) = local_6c;
            *(undefined2 *)(iVar5 + 6) = uVar4;
            *(uint *)(iVar2 + param_4) = *(uint *)(iVar2 + param_4) & 0xff1fffff | 0x200000;
          }
          loopIndex4 = loopIndex4 + 1;
        } while (loopIndex4 < param_3);
      }
      return;
    }
  } while( true );
}

/* _glePPLogParam @ 0x24c44 (1068 bytes) */
int _glePPLogParam(glContext, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9)
  int glContext;
  int param_2;
  int param_3;
  uint param_4;
  int param_5;
  int param_6;
  uint param_7;
  int param_8;
  int param_9;
{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  short sVar12;
  
  uVar7 = param_4 >> 0x10 & 0x1f;
  uVar11 = 0x7fffffff;
  uVar9 = 0xffffffff;
  uVar10 = 0xffffffff;
  uVar8 = 0xffffffff;
  if (uVar7 == 0) {
    return 0;
  }
  if ((uVar7 == 1) || (uVar7 == 0x11)) {
    if (-1 < (int)param_7) {
      if ((*(uint *)(param_8 + ((int)param_7 >> 5) * 4) >> (param_7 & 0x1f) & 1) != 0) {
        return 0xffffffff;
      }
      uVar3 = 1;
      iVar2 = (param_3 * 0x146 + param_7) * 8 + param_2;
      bVar1 = *(int *)(iVar2 + 0x8074) == 0 && *(int *)(iVar2 + 0x8078) == 0;
      goto LAB_00024ea0;
    }
    uVar10 = 0;
    if (param_9 - param_6 == -1) {
      return 0xffffffff;
    }
    iVar2 = param_3 * 0xa30 + param_2 + 0x8070;
    do {
      for (uVar7 = uVar10;
          ((int)uVar7 < (int)(uVar10 + param_6) &&
          ((*(uint *)(param_8 + ((int)uVar7 >> 5) * 4) >> (uVar7 & 0x1f) & 1) == 0));
          uVar7 = uVar7 + 1) {
      }
      if (uVar7 == uVar10 + param_6) {
        if ((*(int *)(iVar2 + 4) == -1) && (*(int *)(iVar2 + 8) == -1)) goto LAB_00024ff0;
        if (*(int *)(iVar2 + 4) == 0 && *(int *)(iVar2 + 8) == 0) {
          if (uVar9 == 0xffffffff) {
            uVar9 = uVar10;
          }
        }
        else {
          uVar7 = (uint)*(ushort *)((param_3 * 0x518 + uVar10) * 2 + param_2 + 0x8874);
          if (uVar7 < uVar11) {
            uVar8 = uVar10;
            uVar11 = uVar7;
          }
        }
      }
      uVar10 = uVar10 + 1;
      iVar2 = iVar2 + 8;
    } while (uVar10 < (param_9 - param_6) + 1U);
    param_7 = uVar8;
    if (uVar9 != 0xffffffff) {
      uVar3 = 1;
      param_7 = uVar9;
      goto LAB_00025008;
    }
LAB_00024fd4:
    if (param_7 == 0xffffffff) {
      return 0xffffffff;
    }
  }
  else {
    if ((int)param_7 < 0) {
      param_7 = 0;
      if (param_9 - param_6 == -1) {
        return 0xffffffff;
      }
      iVar2 = param_3 * 0xa30 + param_2 + 0x8070;
      do {
        for (uVar7 = param_7;
            ((int)uVar7 < (int)(param_7 + param_6) &&
            ((*(uint *)(param_8 + ((int)uVar7 >> 5) * 4) >> (uVar7 & 0x1f) & 1) == 0));
            uVar7 = uVar7 + 1) {
        }
        if (uVar7 == param_7 + param_6) {
          uVar7 = *(uint *)(iVar2 + 4);
          iVar4 = *(int *)(iVar2 + 8);
          if ((uVar7 == param_4) && (iVar4 == param_5)) {
            uVar3 = 5;
            goto LAB_00025008;
          }
          if ((uVar7 == 0xffffffff) && (iVar4 == -1)) {
            if (uVar10 == 0xffffffff) {
              uVar10 = param_7;
            }
          }
          else if (uVar7 == 0 && iVar4 == 0) {
            if (uVar9 == 0xffffffff) {
              uVar9 = param_7;
            }
          }
          else {
            uVar7 = (uint)*(ushort *)((param_3 * 0x518 + param_7) * 2 + param_2 + 0x8874);
            if (uVar7 < uVar11) {
              uVar8 = param_7;
              uVar11 = uVar7;
            }
          }
        }
        param_7 = param_7 + 1;
        iVar2 = iVar2 + 8;
      } while (param_7 < (param_9 - param_6) + 1U);
      if (uVar9 != 0xffffffff) {
        uVar3 = 2;
        param_7 = uVar9;
        goto LAB_00025008;
      }
      param_7 = uVar8;
      if (uVar10 != 0xffffffff) {
LAB_00024ff0:
        uVar3 = 3;
        param_7 = uVar10;
        goto LAB_00025008;
      }
      goto LAB_00024fd4;
    }
    if ((*(uint *)(param_8 + ((int)param_7 >> 5) * 4) >> (param_7 & 0x1f) & 1) != 0) {
      return 0xffffffff;
    }
    iVar2 = (param_3 * 0x146 + param_7) * 8 + param_2;
    uVar8 = *(uint *)(iVar2 + 0x8074);
    iVar2 = *(int *)(iVar2 + 0x8078);
    if (((uVar8 == param_4) && (uVar3 = 5, iVar2 == param_5)) ||
       ((uVar8 == 0xffffffff && (uVar3 = 3, iVar2 == -1)))) goto LAB_00025008;
    bVar1 = uVar8 == 0 && iVar2 == 0;
    uVar3 = 2;
LAB_00024ea0:
    if (bVar1) goto LAB_00025008;
  }
  uVar3 = 4;
LAB_00025008:
  iVar2 = (int)param_7 >> 5;
                    
  switch(uVar3) {
  case 0:
    iVar4 = param_3 * 0x518;
    sVar12 = 0;
    break;
  case 1:
    iVar4 = (param_3 * 0x146 + param_7) * 8 + param_2;
    iVar5 = (param_3 * 0x28c + iVar2) * 4 + param_2;
    *(undefined4 *)(iVar4 + 0x8074) = 0xffffffff;
    *(undefined4 *)(iVar4 + 0x8078) = 0xffffffff;
    iVar4 = param_3 * 0x518;
    sVar12 = 0;
    *(uint *)(iVar5 + 0x8a74) = *(uint *)(iVar5 + 0x8a74) | 1 << (param_7 & 0x1f);
    break;
  case 2:
    iVar5 = (param_3 * 0x28c + iVar2) * 4 + param_2;
    uVar9 = *(uint *)(iVar5 + 0x8a74);
    iVar4 = (param_3 * 0x146 + param_7) * 8 + param_2;
    uVar8 = 1 << (param_7 & 0x1f);
    *(uint *)(iVar4 + 0x8074) = param_4;
    *(int *)(iVar4 + 0x8078) = param_5;
    sVar12 = 0;
    *(uint *)(iVar5 + 0x8a74) = uVar9 & ~uVar8;
    if (param_3 == 0) {
      iVar4 = 0;
      iVar5 = iVar2 * 4 + glContext;
      *(uint *)(iVar5 + 0x324) = *(uint *)(iVar5 + 0x324) | uVar8;
    }
    else {
      iVar4 = param_3 * 0x518;
      iVar5 = iVar2 * 4 + glContext;
      *(uint *)(iVar5 + 0x348) = *(uint *)(iVar5 + 0x348) | uVar8;
    }
    break;
  case 5:
  case 3:
    iVar4 = param_3 * 0x518;
    sVar12 = *(short *)((iVar4 + param_7) * 2 + param_2 + 0x8874);
    break;
  case 4:
    iVar4 = param_3 * 0x518;
    iVar5 = (param_3 * 0x146 + param_7) * 8 + param_2;
    iVar6 = (param_3 * 0x28c + iVar2) * 4 + param_2;
    sVar12 = *(short *)((iVar4 + param_7) * 2 + param_2 + 0x8874);
    *(undefined4 *)(iVar5 + 0x8074) = 0xffffffff;
    *(undefined4 *)(iVar5 + 0x8078) = 0xffffffff;
    *(uint *)(iVar6 + 0x8a74) = *(uint *)(iVar6 + 0x8a74) | 1 << (param_7 & 0x1f);
  }
  *(uint *)(iVar2 * 4 + param_8) = *(uint *)(iVar2 * 4 + param_8) | 1 << (param_7 & 0x1f);
  *(short *)((iVar4 + param_7) * 2 + param_2 + 0x8874) = sVar12 + 1;
  return param_7;
}

/* _PPEmulatorProgramSetupHandlesFromPPStream @ 0x25218 (844 bytes) */
void _PPEmulatorProgramSetupHandlesFromPPStream(param_1, glContext, param_3)
  int param_1;
  undefined4 glContext;
  int param_3;
{
  int loopIndex;
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint local_40;
  undefined4 local_3c;
  undefined1 auStack_30 [4];
  int local_2c;
  undefined1 auStack_28 [4];
  int local_24 [2];
  
  iVar5 = 0;
  if (*(int *)(*(int *)(param_3 + 4) + 8) != 0) {
    iVar5 = _PPStreamChunkListGetMaxIndex(*(int *)(param_3 + 4));
    iVar5 = iVar5 + 1;
  }
  _PPEmulatorProgramInitialiseHandleBanks
            (param_1,iVar5,*(undefined4 *)(*(int *)(param_3 + 0x1c) + 8),
             *(undefined4 *)(*(int *)(param_3 + 0x18) + 8),
             *(undefined4 *)(*(int *)(param_3 + 0x10) + 8));
  loopIndex = 0;
  iVar4 = *(int *)(param_1 + 0x80);
  for (; iVar5 != 0; iVar5 = iVar5 + -1) {
    local_2c = loopIndex * 0x10;
    loopIndex = loopIndex + 1;
    *(int *)(local_2c + iVar4) = local_2c;
    iVar3 = local_2c + iVar4;
    *(int *)(iVar3 + 4) = local_2c + 4;
    *(int *)(iVar3 + 8) = local_2c + 8;
    *(int *)(iVar3 + 0xc) = local_2c + 0xc;
  }
  iVar2 = *(int *)(param_1 + 0x8c);
  for (iVar5 = **(int **)(param_3 + 0x1c); iVar5 != 0; iVar5 = *(int *)(iVar5 + 8)) {
    _PPStreamChunkGetStream(&local_40,iVar5,param_3,auStack_30,0);
    ((void (*)())_gleVPGetResultOffset)(glContext,local_40,local_3c,&local_2c,auStack_28);
    *(int *)(iVar2 + (uint)*(ushort *)(iVar5 + 0x12) * 0x10) = local_2c;
    *(int *)((uint)*(ushort *)(iVar5 + 0x12) * 0x10 + iVar2 + 4) = local_2c + 4;
    *(int *)((uint)*(ushort *)(iVar5 + 0x12) * 0x10 + iVar2 + 8) = local_2c + 8;
    *(int *)((uint)*(ushort *)(iVar5 + 0x12) * 0x10 + iVar2 + 0xc) = local_2c + 0xc;
  }
  iVar2 = *(int *)(param_1 + 0x98);
  for (iVar5 = **(int **)(param_3 + 0x18); iVar5 != 0; iVar5 = *(int *)(iVar5 + 8)) {
    local_2c = (uint)*(ushort *)(iVar5 + 0x12) * 0x10;
    *(int *)(iVar2 + (uint)*(ushort *)(iVar5 + 0x12) * 0x10) = local_2c;
    *(int *)((uint)*(ushort *)(iVar5 + 0x12) * 0x10 + iVar2 + 4) = local_2c + 4;
    *(int *)((uint)*(ushort *)(iVar5 + 0x12) * 0x10 + iVar2 + 8) = local_2c + 8;
    *(int *)((uint)*(ushort *)(iVar5 + 0x12) * 0x10 + iVar2 + 0xc) = local_2c + 0xc;
  }
  iVar2 = *(int *)(param_1 + 0xa4);
  for (iVar5 = **(int **)(param_3 + 0x10); iVar5 != 0; iVar5 = *(int *)(iVar5 + 8)) {
    uVar1 = *(uint *)(iVar5 + 0xc) >> 0x10 & 0x1f;
    if ((uVar1 == 1) || (uVar1 == 0x11)) {
      _PPStreamChunkGetStream(&local_40,iVar5,param_3,auStack_30,0);
      local_2c = (local_40 & 0xffff) * 0x10;
      *(int *)(iVar2 + (uint)*(ushort *)(iVar5 + 0x12) * 0x10) = local_2c;
      *(int *)((uint)*(ushort *)(iVar5 + 0x12) * 0x10 + iVar2 + 4) = local_2c + 4;
      *(int *)((uint)*(ushort *)(iVar5 + 0x12) * 0x10 + iVar2 + 8) = local_2c + 8;
      *(int *)((uint)*(ushort *)(iVar5 + 0x12) * 0x10 + iVar2 + 0xc) = local_2c + 0xc;
    }
    else {
      _PPStreamChunkGetStream(&local_40,iVar5,param_3,auStack_30,0);
      ((void (*)())_gleVPGetParameterPtr)(glContext,local_40,local_3c,&local_2c,local_24);
      *(int *)(iVar2 + (uint)*(ushort *)(iVar5 + 0x12) * 0x10) = local_2c;
      *(int *)((uint)*(ushort *)(iVar5 + 0x12) * 0x10 + iVar2 + 4) = local_2c + local_24[0];
      *(int *)((uint)*(ushort *)(iVar5 + 0x12) * 0x10 + iVar2 + 8) = local_2c + local_24[0] * 2;
      *(int *)((uint)*(ushort *)(iVar5 + 0x12) * 0x10 + iVar2 + 0xc) = local_2c + local_24[0] * 3;
    }
  }
  return;
}

/* _gleVPGetResultOffset @ 0x25564 (204 bytes) */
void _gleVPGetResultOffset(glContext, param_2, param_3, param_4, param_5)
  undefined4 glContext;
  uint param_2;
  undefined4 param_3;
  int *param_4;
  undefined4 *param_5;
{
  int iVar1;
  
  *param_5 = 4;
  switch(param_2 >> 0x10 & 0xf) {
  case 0:
  case 7:
    return;
  case 1:
    iVar1 = 0x10;
    break;
  case 2:
    iVar1 = 0x5c;
    *param_5 = 1;
    goto LAB_00025630;
  case 3:
    *param_5 = 1;
    *param_4 = 0x70;
    return;
  case 4:
    if ((param_2 & 1) == 0) {
      iVar1 = 0x30;
      break;
    }
  case 8:
    iVar1 = 0x20;
    break;
  case 5:
    *param_5 = 3;
    if ((param_2 & 1) == 0) {
      iVar1 = 0x50;
    }
    else {
      iVar1 = 0x40;
    }
    break;
  case 6:
    iVar1 = (param_2 & 0x1f) * 0x10 + 0x80;
LAB_00025630:
    *param_4 = iVar1;
    return;
  default:
    return;
  }
  *param_4 = iVar1;
  return;
}

/* _gleVPGetParameterPtr @ 0x25654 (972 bytes) */
void _gleVPGetParameterPtr(glContext, param_2, param_3, param_4, param_5)
  undefined4 glContext;
  uint param_2;
  undefined4 param_3;
  int *param_4;
  undefined4 *param_5;
{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  *param_5 = 4;
  switch(param_2 >> 0x10 & 0x1f) {
  case 0:
  case 1:
  case 9:
  case 0x11:
    return;
  case 2:
    iVar2 = (param_2 & 0xffff) * 0x10 + 0x10;
    break;
  case 3:
    uVar1 = param_2 & 0xff;
    switch(param_2 >> 8 & 0xf) {
    case 0:
      iVar2 = uVar1 * 0x80 + 0x24c0;
      break;
    case 1:
      iVar2 = uVar1 * 0x80 + 0x24d0;
      break;
    case 2:
      iVar2 = uVar1 * 0x80 + 0x24e0;
      break;
    case 3:
      iVar2 = uVar1 * 0x80 + 0x24f0;
      break;
    case 4:
      iVar2 = uVar1 * 0x80 + 0x2500;
      break;
    case 5:
      iVar2 = uVar1 * 0x80 + 0x2510;
      break;
    case 6:
      iVar2 = uVar1 * 0x80 + 0x2520;
      break;
    case 7:
      iVar2 = uVar1 * 0x80 + 0x2530;
      break;
    default:
      return;
    }
    break;
  case 4:
    uVar3 = param_2 >> 9 & 3;
    uVar1 = param_2 & 0xff;
    uVar4 = param_2 >> 8 & 1;
    if (uVar3 == 1) {
      iVar2 = uVar4 * 0x240 + uVar1 * 0x30 + 0x2920;
    }
    else if (uVar3 < 2) {
      if (uVar3 != 0) {
        return;
      }
      iVar2 = uVar4 * 0x240 + uVar1 * 0x30 + 0x2910;
    }
    else {
      if (uVar3 != 2) {
        return;
      }
      iVar2 = uVar4 * 0x240 + uVar1 * 0x30 + 0x2930;
    }
    break;
  case 5:
    uVar1 = param_2 & 1;
    switch(param_2 >> 1 & 7) {
    case 0:
      iVar2 = uVar1 * 0x240 + 0x28c0;
      break;
    case 1:
      iVar2 = uVar1 * 0x240 + 0x28d0;
      break;
    case 2:
      iVar2 = uVar1 * 0x240 + 0x28e0;
      break;
    case 3:
      iVar2 = uVar1 * 0x240 + 0x28f0;
      break;
    case 4:
      iVar2 = uVar1 * 0x240 + 0x2900;
      break;
    case 5:
      iVar2 = uVar1 * 0x240 + 0x2a90;
      break;
    default:
      return;
    }
    break;
  case 6:
    iVar2 = 0x24b0;
    goto LAB_00025998;
  case 7:
    uVar3 = param_2 >> 5 & 7;
    uVar1 = param_2 & 0x1f;
    if (uVar3 == 1) {
      iVar2 = uVar1 * 0x94 + 0x39b0;
    }
    else if (uVar3 < 2) {
      if (uVar3 != 0) {
        return;
      }
      iVar2 = uVar1 * 0x94 + 0x398c;
    }
    else if (uVar3 == 2) {
      iVar2 = uVar1 * 0x94 + 0x39d4;
    }
    else {
      if (uVar3 != 3) {
        return;
      }
      iVar2 = uVar1 * 0x94 + 0x39f8;
    }
    break;
  case 8:
    uVar3 = param_2 >> 5 & 7;
    uVar1 = param_2 & 0x1f;
    if (uVar3 == 1) {
      iVar2 = uVar1 * 0x94 + 0x39c0;
    }
    else if (uVar3 < 2) {
      if (uVar3 != 0) {
        return;
      }
      iVar2 = uVar1 * 0x94 + 0x399c;
    }
    else if (uVar3 == 2) {
      iVar2 = uVar1 * 0x94 + 0x39e4;
    }
    else {
      if (uVar3 != 3) {
        return;
      }
      iVar2 = uVar1 * 0x94 + 0x3a08;
    }
    break;
  case 10:
    iVar2 = (param_2 & 0xff) * 0x10 + 0x3e2c;
    break;
  case 0xb:
    iVar2 = 0x2de0;
    goto LAB_00025998;
  case 0xc:
    iVar2 = 0x2df0;
    goto LAB_00025998;
  case 0xd:
    iVar2 = 0x30bc;
    goto LAB_00025998;
  case 0xe:
    iVar2 = 0x30cc;
    goto LAB_00025998;
  case 0xf:
    iVar2 = 0x1850;
LAB_00025998:
    *param_4 = iVar2;
    return;
  case 0x10:
    uVar1 = param_2 & 0xff;
    switch(param_2 >> 8 & 7) {
    case 0:
      uVar1 = 0;
      break;
    case 1:
      uVar1 = 3;
      break;
    case 2:
      uVar1 = 2;
      break;
    case 3:
      uVar1 = uVar1 + 4;
      break;
    case 4:
      uVar1 = uVar1 + 0x10;
      break;
    case 5:
      uVar1 = uVar1 + 8;
    }
    if ((param_2 >> 0xe & 3) < 2) {
      iVar2 = uVar1 * 0x40 + 0x1860;
    }
    else {
      iVar2 = uVar1 * 0x40 + 0x1e60;
    }
    uVar1 = param_2 >> 0xe & 3;
    *param_4 = iVar2;
    uVar3 = param_2 >> 0xc & 3;
    if (uVar1 < 3) {
      if (uVar1 != 0) {
        iVar2 = *param_4 + uVar3 * 0x10;
        goto LAB_00025998;
      }
    }
    else if (uVar1 != 3) {
      return;
    }
    *param_4 = *param_4 + uVar3 * 4;
    *param_5 = 0x10;
    return;
  case 0x12:
    *param_4 = 0x24a4;
    return;
  default:
    return;
  }
  *param_4 = iVar2;
  return;
}

/* _glePPUpdateProgram @ 0x25abc (1144 bytes) */
void _glePPUpdateProgram(glContext, param_2)
  undefined4 glContext;
  int param_2;
{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint loopIndex;
  undefined1 uVar9;
  uint uVar10;
  
  uVar4 = 0x100;
  if (*(short *)(param_2 + 0x4ba) != 0) {
    uVar4 = 0x80;
  }
  _memset(param_2 + 0x48,uVar4,0x450);
  *(undefined4 *)(param_2 + 0x10) = 0;
  if ((*(short *)(param_2 + 0x4b8) == -0x7e00) || (iVar2 = *(int *)(param_2 + 0x4bc), iVar2 == 0)) {
    return;
  }
  iVar3 = *(int *)(iVar2 + 0x2c);
  iVar5 = *(int *)(iVar2 + 0x28);
  loopIndex = 0;
  if (iVar5 < 1) {
    return;
  }
  do {
    uVar6 = *(uint *)(loopIndex * 8 + iVar2 + iVar3 * 8);
    uVar9 = (undefined1)loopIndex;
    switch(uVar6 >> 0x10 & 0x1f) {
    default:
      goto switchD_00025bb0_caseD_0;
    case 1:
      *(undefined1 *)((uVar6 & 0xffff) + param_2 + 0x48) = uVar9;
      break;
    case 2:
      *(undefined1 *)((uVar6 & 0xffff) + param_2 + 0x148) = uVar9;
      break;
    case 3:
      uVar10 = uVar6 & 0xff;
      switch(uVar6 >> 8 & 0xf) {
      case 0:
        *(undefined1 *)(uVar10 * 7 + param_2 + 0x248) = uVar9;
        break;
      case 1:
        *(undefined1 *)(uVar10 * 7 + param_2 + 0x249) = uVar9;
        break;
      case 2:
        *(undefined1 *)(uVar10 * 7 + param_2 + 0x24a) = uVar9;
        break;
      case 3:
        *(undefined1 *)(uVar10 * 7 + param_2 + 0x24b) = uVar9;
        break;
      case 4:
        *(undefined1 *)(uVar10 * 7 + param_2 + 0x24c) = uVar9;
        break;
      case 5:
        *(undefined1 *)(uVar10 * 7 + param_2 + 0x24d) = uVar9;
        break;
      case 6:
        *(undefined1 *)(uVar10 * 7 + param_2 + 0x24e) = uVar9;
      }
      break;
    case 4:
      uVar1 = uVar6 >> 9 & 3;
      uVar10 = uVar6 & 0xff;
      uVar6 = uVar6 >> 8 & 1;
      if (uVar1 == 1) {
        *(undefined1 *)(uVar10 * 6 + uVar6 * 3 + param_2 + 0x281) = uVar9;
      }
      else if (uVar1 < 2) {
        if (uVar1 == 0) {
          *(undefined1 *)(uVar10 * 6 + uVar6 * 3 + param_2 + 0x280) = uVar9;
        }
      }
      else if (uVar1 == 2) {
        *(undefined1 *)(uVar10 * 6 + uVar6 * 3 + param_2 + 0x282) = uVar9;
      }
      break;
    case 5:
      uVar10 = uVar6 & 1;
      switch(uVar6 >> 1 & 7) {
      case 0:
        *(undefined1 *)(uVar10 * 6 + param_2 + 0x2b0) = uVar9;
        break;
      case 1:
        *(undefined1 *)(uVar10 * 6 + param_2 + 0x2b1) = uVar9;
        break;
      case 2:
        *(undefined1 *)(uVar10 * 6 + param_2 + 0x2b2) = uVar9;
        break;
      case 3:
        *(undefined1 *)(uVar10 * 6 + param_2 + 0x2b3) = uVar9;
        break;
      case 4:
        *(undefined1 *)(uVar10 * 6 + param_2 + 0x2b4) = uVar9;
        break;
      case 5:
        *(undefined1 *)(uVar10 * 6 + param_2 + 0x2b5) = uVar9;
      }
      break;
    case 6:
      *(undefined1 *)(param_2 + 0x314) = uVar9;
      break;
    case 7:
      *(undefined1 *)((uVar6 & 0x1f) * 4 + param_2 + (uVar6 >> 5 & 7) + 700) = uVar9;
      break;
    case 8:
      *(undefined1 *)((uVar6 & 0x1f) * 4 + param_2 + (uVar6 >> 5 & 7) + 0x2dc) = uVar9;
      break;
    case 10:
      *(undefined1 *)((uVar6 & 0xff) + param_2 + 0x30c) = uVar9;
      break;
    case 0xb:
      *(undefined1 *)(param_2 + 0x312) = uVar9;
      break;
    case 0xc:
      *(undefined1 *)(param_2 + 0x313) = uVar9;
      break;
    case 0xd:
      *(undefined1 *)(param_2 + 0x315) = uVar9;
      break;
    case 0xe:
      *(undefined1 *)(param_2 + 0x316) = uVar9;
      break;
    case 0x10:
      uVar10 = uVar6 & 0xff;
      switch(uVar6 >> 8 & 7) {
      case 0:
        uVar10 = 0;
        goto LAB_00025eec;
      case 1:
        uVar10 = 3;
        goto LAB_00025eec;
      case 2:
        uVar10 = 2;
        goto LAB_00025eec;
      case 3:
        uVar10 = uVar10 + 4;
        break;
      case 4:
        uVar10 = uVar10 + 0x10;
        break;
      case 5:
        uVar10 = uVar10 + 8;
        break;
      default:
        uVar10 = 0xffffffff;
      }
      if (uVar10 != 0xffffffff) {
LAB_00025eec:
        uVar1 = uVar6 >> 0xe & 3;
        uVar6 = uVar6 >> 0xc & 3;
        if (uVar1 == 1) {
          *(undefined1 *)(uVar10 * 4 + param_2 + uVar6 + 0x3d8) = uVar9;
        }
        else if (uVar1 < 2) {
          if (uVar1 == 0) {
            *(undefined1 *)(uVar10 * 4 + param_2 + uVar6 + 0x318) = uVar9;
          }
        }
        else {
          if (uVar1 == 2) {
            uVar1 = *(uint *)(param_2 + 0x10) | 1 << (uVar10 & 0x3f);
            *(undefined1 *)(uVar10 * 4 + param_2 + uVar6 + 0x378) = uVar9;
          }
          else {
            if (uVar1 != 3) break;
            uVar1 = *(uint *)(param_2 + 0x10) | 1 << (uVar10 & 0x3f);
            *(undefined1 *)(uVar10 * 4 + param_2 + uVar6 + 0x438) = uVar9;
          }
          *(uint *)(param_2 + 0x10) = uVar1;
        }
      }
    }
    iVar7 = ((int)loopIndex >> 5) * 4 + param_2;
    *(uint *)(iVar7 + 0x18) = *(uint *)(iVar7 + 0x18) | 1 << (loopIndex & 0x1f);
switchD_00025bb0_caseD_0:
    loopIndex = loopIndex + 1;
    if (iVar5 <= (int)loopIndex) {
      return;
    }
  } while( true );
}

/* _gleVPEnable @ 0x25fc4 (128 bytes) */
double _gleVPEnable(int glContext,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  ((void (*)())_gleVPChanged)(glContext,fparam_1,fparam_2,fparam_3,fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
  if (*(char *)(glContext + 0x30aa) != '\0') {
    *(undefined1 *)(glContext + 0x316b) = *(undefined1 *)(glContext + 0x4fea);
    *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x800;
  }
  _gleSetColorMaterialEnable(glContext);
  _gleUpdateInverseNeeds(glContext);
  _gleUpdatePrimitiveData(glContext);
  _gleUpdateTextureTransform(glContext);
  _gleUpdatePolyMode(glContext);
  *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x400000;
  return;
}

/* _gleVPChanged @ 0x26044 (184 bytes) */
void _gleVPChanged(int glContext,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  int remaining;
  int iVar1;
  uint uVar2;
  int iVar3;
  int loopIndex;
  int iVar5;
  uint *puVar6;
  int remaining2;
  
  if (*(int *)(glContext + 0x5434) == 0) {
    remaining = 9;
    puVar6 = (uint *)(*(int *)(glContext + 0x5420) + 0x28);
    iVar5 = glContext;
    do {
      uVar2 = *puVar6;
      puVar6 = puVar6 + 1;
      *(uint *)(iVar5 + 0x324) = *(uint *)(iVar5 + 0x324) | uVar2;
      iVar5 = iVar5 + 4;
      remaining = remaining + -1;
    } while (remaining != 0);
  }
  else {
    iVar3 = *(int *)(glContext + 0x5430);
    remaining2 = 9;
    loopIndex = 0;
    iVar5 = glContext;
    do {
      iVar1 = loopIndex + *(int *)(iVar3 + 0x20);
      loopIndex = loopIndex + 4;
      *(uint *)(iVar5 + 0x324) = *(uint *)(iVar5 + 0x324) | *(uint *)(iVar1 + 8);
      iVar5 = iVar5 + 4;
      remaining2 = remaining2 + -1;
    } while (remaining2 != 0);
  }
  ((void (*)())_gleUpdateViewScissorData)(glContext,fparam_1,fparam_2,fparam_3,fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
  *(uint *)(glContext + 0x50ac) = *(uint *)(glContext + 0x50ac) | 1;
  _gleSelectVertexSubmitFunc(glContext);
  return;
}

/* _glProgramLocalParameter4fvARB_Exec @ 0x260fc (344 bytes) */
void _glProgramLocalParameter4fvARB_Exec(glContext, target, index, params)
  int glContext;
  uint target;
  uint index;
  undefined4 *params;
{
  byte bVar1;
  uint uVar2;
  undefined4 glErrorCode;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  if (target == 0x8620) {
    iVar5 = 0;
    if (index < 0x100) {
      uVar2 = *(uint *)(glContext + 0x31c) | 0x400000;
LAB_00026190:
      *(uint *)(glContext + 0x31c) = uVar2;
      if (*(int *)(glContext + 0x5434) == 0) {
        bVar1 = *(byte *)(index + *(int *)(glContext + 0x5420) + 0x58);
      }
      else {
        bVar1 = *(byte *)(index + *(int *)(*(int *)(glContext + 0x5430) + 0x20) + 0x8c);
      }
      iVar7 = (bVar1 >> 3 & 0x1c) + glContext;
      iVar4 = *(int *)(glContext + 0x5424);
      iVar6 = iVar5 * 4 + glContext;
      *(uint *)(iVar7 + 0x324) = *(uint *)(iVar7 + 0x324) | 1 << (bVar1 & 0x1f);
      bVar1 = *(byte *)(index + iVar4 + 0x58);
      iVar4 = (bVar1 >> 3 & 0x1c) + glContext;
      iVar5 = *(int *)(iVar6 + 0x5420);
      *(uint *)(iVar4 + 0x348) = *(uint *)(iVar4 + 0x348) | 1 << (bVar1 & 0x1f);
      iVar5 = *(int *)(iVar5 + 0x4e0);
      *(undefined4 *)(iVar5 + index * 0x10) = *params;
      iVar5 = iVar5 + index * 0x10;
      *(undefined4 *)(iVar5 + 4) = params[1];
      *(undefined4 *)(iVar5 + 8) = params[2];
      *(undefined4 *)(iVar5 + 0xc) = params[3];
      ((void (*)())_gleModifyPluginPipelineProgram)(glContext,*(int *)(iVar6 + 0x5420) + 0x10,2);
      return;
    }
  }
  else {
    if (target < 0x8621) {
      uVar2 = 0x8200;
    }
    else {
      uVar2 = 0x8804;
    }
    if (target != uVar2) {
      if (*(int *)(glContext + 0x7574) != 0) {
        return;
      }
      glErrorCode = 0x500;
      goto LAB_00026188;
    }
    iVar5 = 1;
    if (index < 0x80) {
      uVar2 = *(uint *)(glContext + 0x31c) | 0x1000000;
      goto LAB_00026190;
    }
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  glErrorCode = 0x501;
LAB_00026188:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _gleModifyPluginPipelineProgram @ 0x26254 (120 bytes) */
void _gleModifyPluginPipelineProgram(glContext, param_2, param_3)
  int glContext;
  int param_2;
  undefined4 param_3;
{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  int loopIndex;
  undefined4 *puVar6;
  
  iVar4 = glContext + 0x10000;
  loopIndex = 0;
  if (*(char *)(glContext + 0x85a4) != '\0') {
    puVar6 = (undefined4 *)(param_2 + 0x498);
    do {
      piVar1 = (int *)(iVar4 + -0x777c);
      uVar3 = *puVar6;
      loopIndex = loopIndex + 1;
      puVar6 = puVar6 + 1;
      puVar2 = (undefined4 *)(iVar4 + -0x7a54);
      iVar4 = iVar4 + 0x2e0;
      (**(code **)(*piVar1 + 0x194))(*puVar2,uVar3,param_3);
    } while (loopIndex < (int)(uint)*(byte *)(glContext + 0x85a4));
  }
  return;
}

/* _gleVPDisable @ 0x262cc (140 bytes) */
void _gleVPDisable(glContext)
  int glContext;
{
  if (*(char *)(glContext + 0x30aa) != '\0') {
    *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x800;
    *(bool *)(glContext + 0x316b) = *(short *)(glContext + 0x30a8) == -0x7e06;
  }
  _gleSetColorMaterialEnable(glContext);
  _gleUpdateInverseNeeds(glContext);
  _gleUpdatePrimitiveData(glContext);
  _gleSelectVertexSubmitFunc(glContext);
  _gleUpdateTextureTransform(glContext);
  _gleUpdatePolyMode(glContext);
  *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x400000;
  return;
}

/* _glPixelTransferi_Exec @ 0x26358 (3128 bytes) */
void _glPixelTransferi_Exec(glContext, pname, param)
  int glContext;
  uint pname;
  uint param;
{
  float fVar1;
  float fVar2;
  undefined4 glErrorCode;
  uint uVar4;
  uint uVar5;
  
  fVar2 = FLOAT_00108e54;
  fVar1 = FLOAT_00108e50;
  if (-1 < *(short *)(glContext + 0x4a10)) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
    goto LAB_00026ef8;
  }
  if (pname == 0x8022) {
    uVar5 = 0x40000000;
    *(float *)(glContext + 0x33a4) =
         (float)((double)CONCAT44(0x43300000,param ^ 0x80000000) - DOUBLE_00108d58);
  }
  else {
    if (0x8022 < pname) {
      if (pname == 0x870f) {
        uVar5 = 4;
        *(float *)(glContext + 0x3224) =
             (float)((double)CONCAT44(0x43300000,param ^ 0x80000000) - DOUBLE_00108d58);
      }
      else {
        if (pname < 0x8710) {
          if (pname == 0x80b7) {
            uVar5 = 0x80000;
            *(float *)(glContext + 0x3374) =
                 (float)((double)CONCAT44(0x43300000,param ^ 0x80000000) - DOUBLE_00108d58);
            fVar1 = fVar2;
          }
          else if (pname < 0x80b8) {
            if (pname == 0x80b4) {
              uVar5 = 0x10000;
              *(float *)(glContext + 0x335c) =
                   (float)((double)CONCAT44(0x43300000,param ^ 0x80000000) - DOUBLE_00108d58);
              fVar1 = fVar2;
            }
            else if (pname < 0x80b5) {
              if (pname != 0x8023) goto LAB_00026ee8;
              uVar5 = 0x80000000;
              *(float *)(glContext + 0x33ac) =
                   (float)((double)CONCAT44(0x43300000,param ^ 0x80000000) - DOUBLE_00108d58);
            }
            else if (pname == 0x80b5) {
              uVar5 = 0x20000;
              *(float *)(glContext + 0x336c) =
                   (float)((double)CONCAT44(0x43300000,param ^ 0x80000000) - DOUBLE_00108d58);
              fVar1 = fVar2;
            }
            else {
              if (pname != 0x80b6) goto LAB_00026ee8;
              uVar5 = 0x40000;
              *(float *)(glContext + 0x3364) =
                   (float)((double)CONCAT44(0x43300000,param ^ 0x80000000) - DOUBLE_00108d58);
              fVar1 = fVar2;
            }
          }
          else if (pname == 0x80ba) {
            uVar5 = 0x400000;
            *(float *)(glContext + 0x3370) =
                 (float)((double)CONCAT44(0x43300000,param ^ 0x80000000) - DOUBLE_00108d58);
          }
          else if (pname < 0x80bb) {
            if (pname == 0x80b8) {
              uVar5 = 0x100000;
              *(float *)(glContext + 0x3360) =
                   (float)((double)CONCAT44(0x43300000,param ^ 0x80000000) - DOUBLE_00108d58);
            }
            else {
              if (pname != 0x80b9) goto LAB_00026ee8;
              uVar5 = 0x200000;
              *(float *)(glContext + 0x3368) =
                   (float)((double)CONCAT44(0x43300000,param ^ 0x80000000) - DOUBLE_00108d58);
            }
          }
          else {
            if (pname != 0x80bb) {
              if (pname == 0x870e) {
                uVar5 = 1;
                *(float *)(glContext + 0x321c) =
                     (float)((double)CONCAT44(0x43300000,param ^ 0x80000000) - DOUBLE_00108d58);
                goto LAB_00026f44;
              }
              goto LAB_00026ee8;
            }
            uVar5 = 0x800000;
            *(float *)(glContext + 0x3378) =
                 (float)((double)CONCAT44(0x43300000,param ^ 0x80000000) - DOUBLE_00108d58);
          }
          goto LAB_00026f00;
        }
        if (pname == 0x8714) {
          uVar5 = 2;
          *(float *)(glContext + 0x3218) =
               (float)((double)CONCAT44(0x43300000,param ^ 0x80000000) - DOUBLE_00108d58);
          fVar2 = fVar1;
        }
        else if (pname < 0x8715) {
          if (pname == 0x8711) {
            uVar5 = 0x40;
            *(float *)(glContext + 0x3234) =
                 (float)((double)CONCAT44(0x43300000,param ^ 0x80000000) - DOUBLE_00108d58);
          }
          else if (pname < 0x8711) {
            uVar5 = 0x10;
            *(float *)(glContext + 0x322c) =
                 (float)((double)CONCAT44(0x43300000,param ^ 0x80000000) - DOUBLE_00108d58);
          }
          else if (pname == 0x8712) {
            uVar5 = 0x100;
            *(float *)(glContext + 0x323c) =
                 (float)((double)CONCAT44(0x43300000,param ^ 0x80000000) - DOUBLE_00108d58);
          }
          else {
            if (pname != 0x8713) goto LAB_00026ee8;
            uVar5 = 0x400;
            *(float *)(glContext + 0x3244) =
                 (float)((double)CONCAT44(0x43300000,param ^ 0x80000000) - DOUBLE_00108d58);
          }
        }
        else if (pname == 0x8717) {
          uVar5 = 0x80;
          *(float *)(glContext + 0x3230) =
               (float)((double)CONCAT44(0x43300000,param ^ 0x80000000) - DOUBLE_00108d58);
          fVar2 = fVar1;
        }
        else if (pname < 0x8718) {
          if (pname == 0x8715) {
            uVar5 = 8;
            *(float *)(glContext + 0x3220) =
                 (float)((double)CONCAT44(0x43300000,param ^ 0x80000000) - DOUBLE_00108d58);
            fVar2 = fVar1;
          }
          else {
            if (pname != 0x8716) goto LAB_00026ee8;
            uVar5 = 0x20;
            *(float *)(glContext + 0x3228) =
                 (float)((double)CONCAT44(0x43300000,param ^ 0x80000000) - DOUBLE_00108d58);
            fVar2 = fVar1;
          }
        }
        else if (pname == 0x8718) {
          uVar5 = 0x200;
          *(float *)(glContext + 0x3238) =
               (float)((double)CONCAT44(0x43300000,param ^ 0x80000000) - DOUBLE_00108d58);
          fVar2 = fVar1;
        }
        else {
          if (pname != 0x8719) goto LAB_00026ee8;
          uVar5 = 0x800;
          *(float *)(glContext + 0x3240) =
               (float)((double)CONCAT44(0x43300000,param ^ 0x80000000) - DOUBLE_00108d58);
          fVar2 = fVar1;
        }
      }
LAB_00026f44:
      uVar4 = *(uint *)(glContext + 0x3418) & ~uVar5;
      if ((float)((double)CONCAT44(0x43300000,param ^ 0x80000000) - DOUBLE_00108d58) != fVar2) {
        uVar4 = uVar4 | uVar5;
      }
      *(uint *)(glContext + 0x3418) = uVar4;
      goto LAB_00026f80;
    }
    if (pname == 0xd1b) {
      uVar5 = 0x400;
      *(float *)(glContext + 0x31f8) =
           (float)((double)CONCAT44(0x43300000,param ^ 0x80000000) - DOUBLE_00108d58);
    }
    else if (pname < 0xd1c) {
      if (pname == 0xd14) {
        uVar5 = 0x10;
        *(float *)(glContext + 0x31ec) =
             (float)((double)CONCAT44(0x43300000,param ^ 0x80000000) - DOUBLE_00108d58);
        fVar1 = fVar2;
      }
      else if (pname < 0xd15) {
        if (pname == 0xd11) {
          uVar5 = 2;
        }
        else if (pname < 0xd12) {
          if (pname != 0xd10) {
LAB_00026ee8:
            if (*(int *)(glContext + 0x7574) != 0) {
              return;
            }
            glErrorCode = 0x500;
LAB_00026ef8:
            *(undefined4 *)(glContext + 0x7574) = glErrorCode;
            return;
          }
          uVar5 = 1;
        }
        else if (pname == 0xd12) {
          *(uint *)(glContext + 0x3214) = param;
          uVar5 = 4;
          fVar1 = FLOAT_00108e50;
        }
        else {
          if (pname != 0xd13) goto LAB_00026ee8;
          *(uint *)(glContext + 0x3210) = param;
          uVar5 = 8;
          fVar1 = FLOAT_00108e50;
        }
      }
      else if (pname == 0xd18) {
        uVar5 = 0x20;
        *(float *)(glContext + 0x31f4) =
             (float)((double)CONCAT44(0x43300000,param ^ 0x80000000) - DOUBLE_00108d58);
        fVar1 = fVar2;
      }
      else if (pname < 0xd19) {
        if (pname != 0xd15) goto LAB_00026ee8;
        uVar5 = 0x100;
        *(float *)(glContext + 0x31e8) =
             (float)((double)CONCAT44(0x43300000,param ^ 0x80000000) - DOUBLE_00108d58);
      }
      else if (pname == 0xd19) {
        uVar5 = 0x200;
        *(float *)(glContext + 0x31f0) =
             (float)((double)CONCAT44(0x43300000,param ^ 0x80000000) - DOUBLE_00108d58);
      }
      else {
        if (pname != 0xd1a) goto LAB_00026ee8;
        uVar5 = 0x40;
        *(float *)(glContext + 0x31fc) =
             (float)((double)CONCAT44(0x43300000,param ^ 0x80000000) - DOUBLE_00108d58);
        fVar1 = fVar2;
      }
    }
    else if (pname == 0x801c) {
      uVar5 = 0x1000000;
      *(float *)(glContext + 0x3390) =
           (float)((double)CONCAT44(0x43300000,param ^ 0x80000000) - DOUBLE_00108d58);
      fVar1 = fVar2;
    }
    else if (pname < 0x801d) {
      if (pname == 0xd1d) {
        uVar5 = 0x800;
        *(float *)(glContext + 0x3200) =
             (float)((double)CONCAT44(0x43300000,param ^ 0x80000000) - DOUBLE_00108d58);
      }
      else if (pname < 0xd1d) {
        uVar5 = 0x80;
        *(float *)(glContext + 0x3204) =
             (float)((double)CONCAT44(0x43300000,param ^ 0x80000000) - DOUBLE_00108d58);
        fVar1 = fVar2;
      }
      else if (pname == 0xd1e) {
        uVar5 = 0x1000;
        *(float *)(glContext + 0x320c) =
             (float)((double)CONCAT44(0x43300000,param ^ 0x80000000) - DOUBLE_00108d58);
        fVar1 = fVar2;
      }
      else {
        if (pname != 0xd1f) goto LAB_00026ee8;
        uVar5 = 0x2000;
        *(float *)(glContext + 0x3208) =
             (float)((double)CONCAT44(0x43300000,param ^ 0x80000000) - DOUBLE_00108d58);
      }
    }
    else if (pname == 0x801f) {
      uVar5 = 0x8000000;
      *(float *)(glContext + 0x33a8) =
           (float)((double)CONCAT44(0x43300000,param ^ 0x80000000) - DOUBLE_00108d58);
      fVar1 = fVar2;
    }
    else if (pname < 0x8020) {
      if (pname == 0x801d) {
        uVar5 = 0x2000000;
        *(float *)(glContext + 0x33a0) =
             (float)((double)CONCAT44(0x43300000,param ^ 0x80000000) - DOUBLE_00108d58);
        fVar1 = fVar2;
      }
      else {
        if (pname != 0x801e) goto LAB_00026ee8;
        uVar5 = 0x4000000;
        *(float *)(glContext + 0x3398) =
             (float)((double)CONCAT44(0x43300000,param ^ 0x80000000) - DOUBLE_00108d58);
        fVar1 = fVar2;
      }
    }
    else if (pname == 0x8020) {
      uVar5 = 0x10000000;
      *(float *)(glContext + 0x3394) =
           (float)((double)CONCAT44(0x43300000,param ^ 0x80000000) - DOUBLE_00108d58);
    }
    else {
      if (pname != 0x8021) goto LAB_00026ee8;
      uVar5 = 0x20000000;
      *(float *)(glContext + 0x339c) =
           (float)((double)CONCAT44(0x43300000,param ^ 0x80000000) - DOUBLE_00108d58);
    }
  }
LAB_00026f00:
  uVar4 = *(uint *)(glContext + 0x3414) & ~uVar5;
  if ((float)((double)CONCAT44(0x43300000,param ^ 0x80000000) - DOUBLE_00108d58) != fVar1) {
    uVar4 = uVar4 | uVar5;
  }
  *(uint *)(glContext + 0x3414) = uVar4;
LAB_00026f80:
  *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x200000;
  return;
}

/* _glTexImage3D_Exec @ 0x26f94 (800 bytes) */
int _glTexImage3D_Exec(glContext, target, level, internalformat, width, height, depth, border, format, type, pixels)
  int glContext;
  undefined4 target;
  int level;
  undefined4 internalformat;
  int width;
  int height;
  int depth;
  undefined4 border;
  undefined4 format;
  undefined4 type;
  int pixels;
{
  byte bVar1;
  ushort uVar2;
  undefined4 glErrorCode;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  double dVar8;
  
  if (-1 < *(short *)(glContext + 0x4a10)) goto LAB_000270fc;
  if ((pixels == 0) && (*(char *)(glContext + 0x31e6) != '\0')) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x501;
    goto LAB_0002710c;
  }
  iVar6 = *(int *)(glContext + 0x4a6c);
  if (iVar6 == 0) {
LAB_00027098:
    iVar6 = ((int (*)())_gleCheckTexImage3DArgs)(glContext,target,level,internalformat,width,height,depth,border,format,
                       type);
    if (iVar6 == 0) {
      return;
    }
    uVar2 = *(ushort *)(iVar6 + 0x24);
    if ((uVar2 & 0x3c00) == 0x1000) {
LAB_00027114:
      iVar5 = iVar6 + level * 0x18;
      iVar4 = iVar5 + 0xc4;
      if ((*(byte *)(iVar5 + 0xcf) & 0x20) != 0) {
        _gleDeletePluginTextureLevel(glContext,iVar6,iVar4,0,level);
        if (*(int *)(iVar5 + 0xd8) != 0) {
          bVar1 = *(byte *)(iVar5 + 0xcf);
          if ((bVar1 & 1) == 0) {
            _gleFreeTextureLevel(glContext,iVar6,iVar4);
            bVar1 = *(byte *)(iVar5 + 0xcf);
          }
          else {
            *(undefined4 *)(iVar5 + 0xd8) = 0;
          }
          *(byte *)(iVar5 + 0xcf) = bVar1 & 0xef;
        }
        *(byte *)(iVar5 + 0xcf) = *(byte *)(iVar5 + 0xcf) & 0xdf;
      }
      iVar5 = _gleCreateTextureLevel
                        (glContext,iVar6,iVar4,internalformat,width,height,depth,border,format,
                         type,1,pixels);
      if ((iVar5 != 0) && (pixels != 0)) {
        _gleTextureImagePut(glContext,iVar4,0,0,0,width,height,depth,format,type,0,
                            glContext + 0x31cc,pixels);
      }
      if ((((width != 0) && (height != 0)) && (depth != 0)) &&
         (((_gleCreatePluginTextureLevel(glContext,iVar6,iVar4,0,level,internalformat),
           (*(uint *)(iVar6 + 0x6c) & 0x8000) != 0 && (*(short *)(iVar6 + 0x60) == level)) &&
          (iVar6 = _gleGenMipmapsToLevel(glContext,iVar6,0,level,0xf,1), iVar6 != 0)))) {
        return;
      }
      *(uint *)(glContext + 0x314) =
           *(uint *)(glContext + 0x314) | 1 << (*(uint *)(glContext + 0x53d4) & 0x3f);
      return;
    }
    if ((uVar2 & 0x3c00) == 0) {
      *(ushort *)(iVar6 + 0x24) = uVar2 | 0x1000;
      goto LAB_00027114;
    }
    if ((uVar2 & 0xc00) == 0) goto LAB_00027114;
  }
  else {
    iVar4 = _gleOffsetLimitImage3D
                      (glContext + 0x31cc,width,height,depth,format,type,pixels);
    iVar7 = *(int *)(iVar6 + 0x38);
    dVar8 = (double)((double (*)())_gleBytesPerElement)(type);
    iVar5 = (int)dVar8;
    if (iVar4 <= iVar7) {
      if (iVar5 == 0) {
        iVar5 = _glePixelBytes(format,type);
      }
      if (pixels == (pixels / iVar5) * iVar5) {
        if (*(int *)(iVar6 + 0x40) != 0) {
          _gleSynchronizePluginBuffer(glContext,iVar6 + 0x10);
        }
        pixels = pixels + *(int *)(iVar6 + 0x30);
        goto LAB_00027098;
      }
    }
  }
LAB_000270fc:
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  glErrorCode = 0x502;
LAB_0002710c:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _gleCheckTexImage3DArgs @ 0x272b4 (324 bytes) */
int _gleCheckTexImage3DArgs(glContext, target, level, internalformat, width, height, depth, border, format, type)
  int glContext;
  undefined4 target;
  undefined4 level;
  undefined4 internalformat;
  int width;
  int height;
  int depth;
  int border;
  undefined4 format;
  undefined4 type;
{
  undefined4 glErrorCode;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  iVar3 = ((int (*)())_gleLookUpTexture3D)(glContext,target);
  if (iVar3 == 0) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return 0;
    }
    glErrorCode = 0x500;
    goto LAB_000273a4;
  }
  uVar7 = width + border * -2;
  uVar6 = height + border * -2;
  uVar5 = depth + border * -2;
  if (-1 < (int)uVar7) {
    if ((uVar7 & uVar7 - 1) == 0) {
      iVar2 = *(int *)(glContext + 0x468c);
    }
    else {
      iVar2 = *(int *)(glContext + 0x468c);
      if ((*(uint *)(iVar2 + 0x124) & 0x80000) == 0) goto LAB_00027394;
    }
    uVar4 = (uint)*(ushort *)(iVar2 + 0xbe);
    if (((((((int)uVar7 <= (int)uVar4) && (-1 < (int)uVar6)) &&
          (((uVar6 & uVar6 - 1) == 0 || ((*(uint *)(iVar2 + 0x124) & 0x80000) != 0)))) &&
         (((int)uVar6 <= (int)uVar4 && (-1 < (int)uVar5)))) &&
        (((uVar5 & uVar5 - 1) == 0 || ((*(uint *)(iVar2 + 0x124) & 0x80000) != 0)))) &&
       ((int)uVar5 <= (int)uVar4)) {
      iVar2 = _gleCheckTexImageArgs(glContext,level,format,type,internalformat,border,0,1);
      if (iVar2 != 0) {
        return iVar3;
      }
      return 0;
    }
  }
LAB_00027394:
  if (*(int *)(glContext + 0x7574) != 0) {
    return 0;
  }
  glErrorCode = 0x501;
LAB_000273a4:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return 0;
}

/* _gleLookUpTexture3D @ 0x273f8 (80 bytes) */
int _gleLookUpTexture3D(glContext, target)
  int glContext;
  int target;
{
  if (target == 0x806f) {
    return *(int *)(*(int *)(glContext + 0x53d4) * 0x14 + glContext + 0x5158) + 0x10;
  }
  if (target != 0x8070) {
    return 0;
  }
  return *(int *)(glContext + 0x52ac) + 0x10;
}

/* _gleTextureImagePut_Slow @ 0x27448 (28188 bytes) */
void _gleTextureImagePut_Slow(glContext, textureLevel, xoffset, yoffset, zoffset, width, height, depth, format, type, param_11, param_12, pixels)
  int glContext;
  int textureLevel;
  uint xoffset;
  uint yoffset;
  int zoffset;
  int width;
  uint height;
  uint depth;
  int format;
  int type;
  undefined4 param_11;
  int param_12;
  uint pixels;
{
  int srcPixel;
  uint componentUint;
  int columnsLeft2;
  uint rowsLeft;
  uint allocatedBlock;
  float floatOne3;
  float floatMinusOne2;
  float float255C;
  float float127B;
  float floatZero2;
  float floatOne2;
  float float32767;
  float float255B;
  float floatZero;
  float floatOne;
  int scaledInt;
  short sVar2;
  ushort uVar3;
  bool bVar4;
  double twoPow31;
  double uint32MaxAsDouble;
  float float65535;
  float floatMinusOne;
  float fVar9;
  float float127;
  float float255;
  ushort uVar14;
  undefined1 componentByte;
  uint uVar12;
  uint uVar13;
  undefined2 componentShort;
  int iVar17;
  uint uVar18;
  code *extractPixelFunc;
  code *modifyPixelFunc;
  int iVar21;
  uint uVar22;
  uint uVar23;
  int iVar24;
  int *piVar25;
  uint *dstSlice;
  int dstSliceBytes;
  uint *dstRow;
  int columnsLeft;
  undefined1 *puVar30;
  uint *dstPixel;
  double scaledComponent;
  undefined1 auStack_1b0 [4];
  float local_1ac;
  float local_1a8;
  float local_1a4;
  float local_1a0;
  float local_19c;
  float local_190;
  float local_18c;
  float local_188;
  float local_184;
  float local_180;
  int local_170;
  int local_16c;
  undefined1 auStack_168 [4];
  undefined1 auStack_164 [4];
  int local_160;
  int local_15c;
  undefined1 auStack_158 [4];
  undefined1 auStack_154 [4];
  undefined4 local_150;
  uint local_14c;
  undefined4 local_148;
  int local_144;
  uint local_140;
  undefined4 local_13c;
  undefined4 local_138;
  uint local_134;
  uint local_130;
  uint local_12c;
  undefined4 local_128;
  uint local_124;
  uint local_120;
  uint local_11c;
  undefined4 local_118;
  uint local_114;
  uint local_110;
  uint local_10c;
  undefined4 local_108;
  undefined1 local_104;
  undefined8 local_100;
  longlong local_f8;
  undefined8 local_f0;
  longlong local_e8;
  longlong local_e0;
  longlong local_d8;
  longlong local_d0;
  undefined8 local_c8;
  int srcRowBytes;
  int srcRowPad;
  int srcImageBytes;
  int srcImagePad;
  int srcPixelStride;
  int srcOffset;
  float local_a8;
  float local_a4;
  int local_a0;
  int local_9c;
  float local_90;
  
  if (type != 0x1a00) {
    bVar4 = false;
    iVar17 = zoffset;
    iVar21 = width;
    uVar22 = height;
    uVar23 = depth;
  }
  else {
    iVar17 = _gleImageSize(format,0x1a00,width,height);
    allocatedBlock = _malloc(iVar17 * depth);
    if (allocatedBlock == 0) {
      if (*(int *)(glContext + 0x7574) != 0) {
        return;
      }
      *(undefined4 *)(glContext + 0x7574) = 0x505;
      return;
    }
    iVar21 = 0x1a00;
    iVar17 = format;
    uVar23 = allocatedBlock;
    _gleFillImage(glContext,width,height,depth,format,0x1a00,pixels,allocatedBlock);
    bVar4 = true;
    uVar22 = pixels;
    pixels = allocatedBlock;
  }
  if (((((param_12 != 0) && (*(char *)(param_12 + 0x18) != '\0')) ||
       (((char)param_11 != '\0' &&
        ((((*(uint *)(glContext + 0x3410) & 0x1ff) != 0 ||
          (uVar22 = *(uint *)(glContext + 0x3414) & 0xff0000, uVar22 != 0)) && (format != 0x1900)))))
       ) || ((type == 0x140b || (type == 0x1406)))) ||
     ((sVar2 = *(short *)(textureLevel + 0x12), sVar2 == 0x140b ||
      (((sVar2 == 0x1406 || (sVar2 == 0)) || ((sVar2 == 0x1403 || (type == 0x1a00)))))))) {
    _glgConvertType(format,type,auStack_168,auStack_164,iVar17,iVar21,uVar22,uVar23);
    piVar25 = &srcOffset;
    rowsLeft = height;
    iVar17 = param_12;
    _glePixelPackSettings
              (glContext,format,type,width,height,param_12,&srcPixelStride,piVar25,&srcRowBytes,
               &srcRowPad,&srcImageBytes,&srcImagePad);
    uVar23 = 0;
    local_14c = 0;
    local_148 = 0x7efff;
    local_138 = 0;
    local_13c = 0;
    if ((char)param_11 != '\0') {
      uVar23 = *(uint *)(glContext + 0x3410);
      if ((uVar23 & 0x20) != 0) {
        iVar21 = _gleLookUpNonProxyColorTable(glContext,0x80d0);
        uVar23 = *(uint *)(glContext + 0x3410);
        local_128 = *(undefined4 *)(iVar21 + 0xc0);
        local_134 = (uint)*(ushort *)(iVar21 + 0xbc);
        local_130 = (uint)*(ushort *)(iVar21 + 0xbe);
        local_12c = (uint)*(ushort *)(iVar21 + 0xb0);
      }
      if ((uVar23 & 0x80) != 0) {
        iVar21 = _gleLookUpNonProxyColorTable(glContext,0x80d2);
        uVar23 = *(uint *)(glContext + 0x3410);
        local_118 = *(undefined4 *)(iVar21 + 0xc0);
        local_124 = (uint)*(ushort *)(iVar21 + 0xbc);
        local_120 = (uint)*(ushort *)(iVar21 + 0xbe);
        local_11c = (uint)*(ushort *)(iVar21 + 0xb0);
      }
      if ((uVar23 & 0x40) != 0) {
        iVar21 = _gleLookUpNonProxyColorTable(glContext,0x80d1);
        local_108 = *(undefined4 *)(iVar21 + 0xc0);
        local_114 = (uint)*(ushort *)(iVar21 + 0xbc);
        local_110 = (uint)*(ushort *)(iVar21 + 0xbe);
        local_10c = (uint)*(ushort *)(iVar21 + 0xb0);
      }
    }
    if (param_12 == 0) {
      if (1 < (int)depth) {
        srcImageBytes = srcRowBytes * height;
      }
    }
    else {
      if (*(char *)(param_12 + 0x19) != '\0') {
        local_14c = local_14c | 4;
      }
      if (*(char *)(param_12 + 0x18) != '\0') {
        local_14c = local_14c | 1;
      }
    }
    puVar30 = auStack_154;
    local_150 = 2;
    local_104 = 0;
    local_144 = width;
    local_140 = height;
    _glgConvertType((uint)*(ushort *)(textureLevel + 0x10),(uint)*(ushort *)(textureLevel + 0x12),auStack_158,
                    puVar30,rowsLeft,iVar17,uVar23,piVar25);
    iVar21 = _glePixelBytes((uint)*(ushort *)(textureLevel + 0x10),(uint)*(ushort *)(textureLevel + 0x12));
    uVar23 = (uint)*(ushort *)(textureLevel + 0xc);
    local_15c = _gleRowBytes((uint)*(ushort *)(textureLevel + 0x10),(uint)*(ushort *)(textureLevel + 0x12),
                             uVar23);
    dstSliceBytes = local_15c * (uint)*(ushort *)(textureLevel + 6);
    local_170 = pixels + srcOffset;
    local_16c = srcRowBytes;
    if ((*(short *)(textureLevel + 0x12) == 0) && (((xoffset != 0 || (yoffset != 0)) || (zoffset != 0))))
    {
      uVar3 = *(ushort *)(textureLevel + 0x10);
      if (((0x83f3 < uVar3) || (0x83f1 < uVar3)) || (uVar23 = 8, uVar3 < 0x83f0)) {
        uVar23 = 0x10;
      }
      iVar24 = ((int)xoffset >> 2) + (uint)((int)xoffset < 0 && (xoffset & 3) != 0);
      local_160 = *(int *)(textureLevel + 0x14) +
                  ((uint)(*(ushort *)(textureLevel + 4) >> 2) *
                   (((int)yoffset >> 2) + (uint)((int)yoffset < 0 && (yoffset & 3) != 0)) + iVar24)
                  * uVar23;
    }
    else {
      iVar24 = local_15c * yoffset;
      local_160 = dstSliceBytes * zoffset + iVar24 + *(int *)(textureLevel + 0x14) + iVar21 * xoffset;
    }
    uVar18 = 0;
    while( true ) {
      uVar18 = uVar18 + 1;
      _glgProcessPixels(glContext + 0x31a8,&local_170,uVar23,puVar30,rowsLeft,iVar17,iVar24,piVar25);
      if (uVar18 == depth) break;
      local_160 = local_160 + dstSliceBytes;
      local_170 = local_170 + srcImageBytes;
      iVar24 = srcImageBytes;
    }
    goto LAB_0002e240;
  }
  iVar17 = _gleComponents((uint)*(ushort *)(textureLevel + 0x10));
  iVar21 = _glePixelBytes((uint)*(ushort *)(textureLevel + 0x10),(uint)*(ushort *)(textureLevel + 0x12));
  dstSlice = (uint *)(*(int *)(textureLevel + 0x14) +
                    iVar21 * ((uint)*(ushort *)(textureLevel + 4) *
                              ((uint)*(ushort *)(textureLevel + 6) * zoffset + yoffset) + xoffset));
  iVar21 = _gleRowBytes((uint)*(ushort *)(textureLevel + 0x10),(uint)*(ushort *)(textureLevel + 0x12),
                        (uint)*(ushort *)(textureLevel + 4));
  dstSliceBytes = iVar21 * (uint)*(ushort *)(textureLevel + 6);
  _glePixelPackSettings
            (glContext,format,type,width,height,param_12,&srcPixelStride,&srcOffset,&srcRowBytes,
             &srcRowPad,&srcImageBytes,&srcImagePad);
  srcPixel = pixels + srcOffset;
  extractPixelFunc = (code *)((int (*)())_gleSelectPixelExtractFunc)(format,type);
  modifyPixelFunc = (code *)((int (*)())_gleSelectModifyPixelFunc)(glContext,format);
  float65535 = FLOAT_00108ea0;
  uint32MaxAsDouble = DOUBLE_00108da8;
  if (extractPixelFunc == (code *)0x0) {
    return;
  }
  local_1a4 = 0.0;
  local_1a0 = 1.0;
  local_1ac = 0.0;
  local_1a8 = 0.0;
  if (modifyPixelFunc != (code *)0x0) {
    uVar3 = *(ushort *)(textureLevel + 0x10);
    if (uVar3 == 0x190a) {
      if (*(short *)(textureLevel + 0x12) == 1) {
        if (0 < (int)depth) {
          do {
            rowsLeft = height;
            dstRow = dstSlice;
            if (0 < (int)height) {
              do {
                float127B = FLOAT_00108f6c;
                floatMinusOne = FLOAT_00108e58;
                floatOne = FLOAT_00108e54;
                columnsLeft = width;
                dstPixel = dstRow;
                if (0 < width) {
                  do {
                    (*extractPixelFunc)(auStack_1b0,srcPixel);
                    _gleModifyPixelSignedRGBA(glContext,auStack_1b0);
                    if (floatOne < local_1a0) {
                      componentByte = 0x7f;
                    }
                    else {
                      componentByte = 0x81;
                      if (!(local_1a0 < floatMinusOne)) {
                        scaledInt = (int)(local_1a0 * float127B);
                        (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)scaledInt;
                        componentByte = (undefined1)local_c8;
                        local_c8 = (longlong)scaledInt;
                      }
                    }
                    *(undefined1 *)dstPixel = componentByte;
                    if (floatOne < local_1ac) {
                      componentByte = 0x7f;
                    }
                    else {
                      componentByte = 0x81;
                      if (!(local_1ac < floatMinusOne)) {
                        scaledInt = (int)(local_1ac * float127B);
                        (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)scaledInt;
                        componentByte = (undefined1)local_c8;
                        local_c8 = (longlong)scaledInt;
                      }
                    }
                    columnsLeft = columnsLeft + -1;
                    *(undefined1 *)((int)dstPixel + 1) = componentByte;
                    srcPixel = srcPixel + srcPixelStride;
                    dstPixel = (uint *)((int)dstPixel + iVar17);
                  } while (columnsLeft != 0);
                }
                rowsLeft = rowsLeft - 1;
                srcPixel = srcPixel + srcRowPad;
                dstRow = (uint *)((int)dstRow + iVar21);
              } while (rowsLeft != 0);
            }
            depth = depth - 1;
            dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
            srcPixel = srcPixel + srcImagePad;
          } while (depth != 0);
        }
      }
      else if (0 < (int)depth) {
        do {
          rowsLeft = height;
          dstRow = dstSlice;
          if (0 < (int)height) {
            do {
              float255C = FLOAT_00108f70;
              floatOne2 = FLOAT_00108e54;
              floatZero = FLOAT_00108e50;
              columnsLeft = width;
              dstPixel = dstRow;
              if (0 < width) {
                do {
                  local_1ac = floatZero;
                  local_1a0 = floatOne2;
                  (*extractPixelFunc)(auStack_1b0,srcPixel);
                  (*modifyPixelFunc)(glContext,auStack_1b0);
                  if (floatOne2 < local_1ac) {
                    componentByte = 0xff;
                  }
                  else {
                    componentByte = 0;
                    if (!(local_1ac < floatZero)) {
                      scaledInt = (int)(local_1ac * float255C);
                      (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)scaledInt;
                      componentByte = (undefined1)local_c8;
                      local_c8 = (longlong)scaledInt;
                    }
                  }
                  *(undefined1 *)dstPixel = componentByte;
                  if (floatOne2 < local_1a0) {
                    componentByte = 0xff;
                  }
                  else {
                    componentByte = 0;
                    if (!(local_1a0 < floatZero)) {
                      scaledInt = (int)(local_1a0 * float255C);
                      (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)scaledInt;
                      componentByte = (undefined1)local_c8;
                      local_c8 = (longlong)scaledInt;
                    }
                  }
                  columnsLeft = columnsLeft + -1;
                  *(undefined1 *)((int)dstPixel + 1) = componentByte;
                  srcPixel = srcPixel + srcPixelStride;
                  dstPixel = (uint *)((int)dstPixel + iVar17);
                } while (columnsLeft != 0);
              }
              rowsLeft = rowsLeft - 1;
              srcPixel = srcPixel + srcRowPad;
              dstRow = (uint *)((int)dstRow + iVar21);
            } while (rowsLeft != 0);
          }
          depth = depth - 1;
          dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
          srcPixel = srcPixel + srcImagePad;
        } while (depth != 0);
      }
      goto LAB_0002e240;
    }
    if (uVar3 < 0x190b) {
      if (uVar3 == 0x1907) {
        uVar3 = *(ushort *)(textureLevel + 0x12);
        if (uVar3 == 0x8362) {
          if (0 < (int)depth) {
            do {
              rowsLeft = height;
              dstRow = dstSlice;
              if (0 < (int)height) {
                do {
                  float255B = FLOAT_00108f70;
                  columnsLeft2 = width;
                  dstPixel = dstRow;
                  if (0 < width) {
                    do {
                      (*extractPixelFunc)(auStack_1b0,srcPixel);
                      (*modifyPixelFunc)(glContext,auStack_1b0);
                      columnsLeft2 = columnsLeft2 + -1;
                      local_c8 = (longlong)(int)(local_1a4 * float255B);
                      local_d0 = (longlong)(int)(local_1a8 * float255B);
                      local_d8 = (longlong)(int)(local_1ac * float255B);
                      *(byte *)dstPixel =
                           (byte)(int)(local_1a4 * float255B) & 0xc0 |
                           (byte)((uint)(int)(local_1a8 * float255B) >> 2) & 0x38 |
                           (byte)((uint)(int)(local_1ac * float255B) >> 5) & 7;
                      srcPixel = srcPixel + srcPixelStride;
                      dstPixel = (uint *)((int)dstPixel + 1);
                    } while (columnsLeft2 != 0);
                  }
                  rowsLeft = rowsLeft - 1;
                  srcPixel = srcPixel + srcRowPad;
                  dstRow = (uint *)((int)dstRow + iVar21);
                } while (rowsLeft != 0);
              }
              depth = depth - 1;
              dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
              srcPixel = srcPixel + srcImagePad;
            } while (depth != 0);
          }
          goto LAB_0002e240;
        }
        if (uVar3 < 0x8363) {
          if (uVar3 == 8) {
            if (0 < (int)depth) {
              do {
                rowsLeft = height;
                dstRow = dstSlice;
                if (0 < (int)height) {
                  do {
                    float127B = FLOAT_00108f6c;
                    floatMinusOne = FLOAT_00108e58;
                    floatOne = FLOAT_00108e54;
                    columnsLeft = width;
                    dstPixel = dstRow;
                    if (0 < width) {
                      do {
                        (*extractPixelFunc)(auStack_1b0,srcPixel);
                        _gleModifyPixelSignedRGBA(glContext,auStack_1b0);
                        if (floatOne < local_1ac) {
                          componentByte = 0x7f;
                        }
                        else {
                          componentByte = 0x81;
                          if (!(local_1ac < floatMinusOne)) {
                            (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)(int)(local_1ac * float127B);
                            componentByte = (undefined1)local_c8;
                            local_c8 = (longlong)(int)(local_1ac * float127B);
                          }
                        }
                        *(undefined1 *)dstPixel = componentByte;
                        if (floatOne < local_1a8) {
                          componentByte = 0x7f;
                        }
                        else {
                          componentByte = 0x81;
                          if (!(local_1a8 < floatMinusOne)) {
                            (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)(int)(local_1a8 * float127B);
                            componentByte = (undefined1)local_c8;
                            local_c8 = (longlong)(int)(local_1a8 * float127B);
                          }
                        }
                        *(undefined1 *)((int)dstPixel + 1) = componentByte;
                        if (floatOne < local_1a4) {
                          componentByte = 0x7f;
                        }
                        else {
                          componentByte = 0x81;
                          if (!(local_1a4 < floatMinusOne)) {
                            (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)(int)(local_1a4 * float127B);
                            componentByte = (undefined1)local_c8;
                            local_c8 = (longlong)(int)(local_1a4 * float127B);
                          }
                        }
                        columnsLeft = columnsLeft + -1;
                        *(undefined1 *)((int)dstPixel + 2) = componentByte;
                        *(undefined1 *)((int)dstPixel + 3) = 0;
                        srcPixel = srcPixel + srcPixelStride;
                        dstPixel = (uint *)((int)dstPixel + iVar17);
                      } while (columnsLeft != 0);
                    }
                    rowsLeft = rowsLeft - 1;
                    srcPixel = srcPixel + srcRowPad;
                    dstRow = (uint *)((int)dstRow + iVar21);
                  } while (rowsLeft != 0);
                }
                depth = depth - 1;
                dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
                srcPixel = srcPixel + srcImagePad;
              } while (depth != 0);
            }
            goto LAB_0002e240;
          }
          if (uVar3 == 0x8032) {
            if (0 < (int)depth) {
              do {
                rowsLeft = height;
                dstRow = dstSlice;
                if (0 < (int)height) {
                  do {
                    float255B = FLOAT_00108f70;
                    columnsLeft2 = width;
                    dstPixel = dstRow;
                    if (0 < width) {
                      do {
                        (*extractPixelFunc)(auStack_1b0,srcPixel);
                        (*modifyPixelFunc)(glContext,auStack_1b0);
                        columnsLeft2 = columnsLeft2 + -1;
                        local_c8 = (longlong)(int)(local_1ac * float255B);
                        local_d0 = (longlong)(int)(local_1a8 * float255B);
                        local_d8 = (longlong)(int)(local_1a4 * float255B);
                        *(byte *)dstPixel =
                             (byte)(int)(local_1ac * float255B) & 0xe0 |
                             (byte)((uint)(int)(local_1a8 * float255B) >> 3) & 0x1c |
                             (byte)((uint)(int)(local_1a4 * float255B) >> 6) & 3;
                        srcPixel = srcPixel + srcPixelStride;
                        dstPixel = (uint *)((int)dstPixel + 1);
                      } while (columnsLeft2 != 0);
                    }
                    rowsLeft = rowsLeft - 1;
                    srcPixel = srcPixel + srcRowPad;
                    dstRow = (uint *)((int)dstRow + iVar21);
                  } while (rowsLeft != 0);
                }
                depth = depth - 1;
                dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
                srcPixel = srcPixel + srcImagePad;
              } while (depth != 0);
            }
            goto LAB_0002e240;
          }
        }
        else {
          if (uVar3 == 0x8363) {
            if (0 < (int)depth) {
              do {
                rowsLeft = height;
                dstRow = dstSlice;
                if (0 < (int)height) {
                  do {
                    if (0 < width) {
                      local_90 = float65535;
                      columnsLeft2 = width;
                      dstPixel = dstRow;
                      do {
                        (*extractPixelFunc)(auStack_1b0,srcPixel);
                        (*modifyPixelFunc)(glContext,auStack_1b0);
                        columnsLeft2 = columnsLeft2 + -1;
                        local_c8 = (longlong)(int)(local_1ac * float65535);
                        local_d0 = (longlong)(int)(local_1a8 * float65535);
                        local_d8 = (longlong)(int)(local_1a4 * float65535);
                        *(ushort *)dstPixel =
                             (ushort)(int)(local_1ac * float65535) & 0xf800 |
                             (ushort)((uint)(int)(local_1a8 * float65535) >> 5) & 0x7e0 |
                             (ushort)((uint)(int)(local_1a4 * float65535) >> 0xb) & 0x1f;
                        dstPixel = (uint *)((int)dstPixel + 2);
                        srcPixel = srcPixel + srcPixelStride;
                      } while (columnsLeft2 != 0);
                    }
                    rowsLeft = rowsLeft - 1;
                    srcPixel = srcPixel + srcRowPad;
                    dstRow = (uint *)((int)dstRow + iVar21);
                  } while (rowsLeft != 0);
                }
                depth = depth - 1;
                dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
                srcPixel = srcPixel + srcImagePad;
              } while (depth != 0);
            }
            goto LAB_0002e240;
          }
          if (uVar3 == 0x8364) {
            if (0 < (int)depth) {
              do {
                rowsLeft = height;
                dstRow = dstSlice;
                if (0 < (int)height) {
                  do {
                    if (0 < width) {
                      local_90 = float65535;
                      columnsLeft2 = width;
                      dstPixel = dstRow;
                      do {
                        (*extractPixelFunc)(auStack_1b0,srcPixel);
                        (*modifyPixelFunc)(glContext,auStack_1b0);
                        columnsLeft2 = columnsLeft2 + -1;
                        local_c8 = (longlong)(int)(local_1a4 * float65535);
                        local_d0 = (longlong)(int)(local_1a8 * float65535);
                        local_d8 = (longlong)(int)(local_1ac * float65535);
                        *(ushort *)dstPixel =
                             (ushort)(int)(local_1a4 * float65535) & 0xf800 |
                             (ushort)((uint)(int)(local_1a8 * float65535) >> 5) & 0x7e0 |
                             (ushort)((uint)(int)(local_1ac * float65535) >> 0xb) & 0x1f;
                        dstPixel = (uint *)((int)dstPixel + 2);
                        srcPixel = srcPixel + srcPixelStride;
                      } while (columnsLeft2 != 0);
                    }
                    rowsLeft = rowsLeft - 1;
                    srcPixel = srcPixel + srcRowPad;
                    dstRow = (uint *)((int)dstRow + iVar21);
                  } while (rowsLeft != 0);
                }
                depth = depth - 1;
                dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
                srcPixel = srcPixel + srcImagePad;
              } while (depth != 0);
            }
            goto LAB_0002e240;
          }
        }
        if (0 < (int)depth) {
          do {
            rowsLeft = height;
            dstRow = dstSlice;
            if (0 < (int)height) {
              do {
                float255C = FLOAT_00108f70;
                floatOne2 = FLOAT_00108e54;
                floatZero = FLOAT_00108e50;
                columnsLeft = width;
                dstPixel = dstRow;
                if (0 < width) {
                  do {
                    local_1ac = floatZero;
                    local_1a8 = floatZero;
                    local_1a4 = floatZero;
                    (*extractPixelFunc)(auStack_1b0,srcPixel);
                    (*modifyPixelFunc)(glContext,auStack_1b0);
                    if (floatOne2 < local_1ac) {
                      componentByte = 0xff;
                    }
                    else {
                      componentByte = 0;
                      if (!(local_1ac < floatZero)) {
                        (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)(int)(local_1ac * float255C);
                        componentByte = (undefined1)local_c8;
                        local_c8 = (longlong)(int)(local_1ac * float255C);
                      }
                    }
                    *(undefined1 *)dstPixel = componentByte;
                    if (floatOne2 < local_1a8) {
                      componentByte = 0xff;
                    }
                    else {
                      componentByte = 0;
                      if (!(local_1a8 < floatZero)) {
                        (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)(int)(local_1a8 * float255C);
                        componentByte = (undefined1)local_c8;
                        local_c8 = (longlong)(int)(local_1a8 * float255C);
                      }
                    }
                    *(undefined1 *)((int)dstPixel + 1) = componentByte;
                    if (floatOne2 < local_1a4) {
                      componentByte = 0xff;
                    }
                    else {
                      componentByte = 0;
                      if (!(local_1a4 < floatZero)) {
                        (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)(int)(local_1a4 * float255C);
                        componentByte = (undefined1)local_c8;
                        local_c8 = (longlong)(int)(local_1a4 * float255C);
                      }
                    }
                    columnsLeft = columnsLeft + -1;
                    *(undefined1 *)((int)dstPixel + 2) = componentByte;
                    srcPixel = srcPixel + srcPixelStride;
                    dstPixel = (uint *)((int)dstPixel + iVar17);
                  } while (columnsLeft != 0);
                }
                rowsLeft = rowsLeft - 1;
                srcPixel = srcPixel + srcRowPad;
                dstRow = (uint *)((int)dstRow + iVar21);
              } while (rowsLeft != 0);
            }
            depth = depth - 1;
            dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
            srcPixel = srcPixel + srcImagePad;
          } while (depth != 0);
        }
        goto LAB_0002e240;
      }
      if (uVar3 < 0x1908) {
        if (uVar3 == 0x1906) {
          if (*(short *)(textureLevel + 0x12) == 0x1400) {
            if (0 < (int)depth) {
              do {
                rowsLeft = height;
                dstRow = dstSlice;
                if (0 < (int)height) {
                  do {
                    float255C = FLOAT_00108f70;
                    floatOne2 = FLOAT_00108e54;
                    floatZero = FLOAT_00108e50;
                    columnsLeft = width;
                    dstPixel = dstRow;
                    if (0 < width) {
                      do {
                        (*extractPixelFunc)(auStack_1b0,srcPixel);
                        (*modifyPixelFunc)(glContext,auStack_1b0);
                        if (floatOne2 < local_1a0) {
                          componentByte = 0xff;
                        }
                        else {
                          componentByte = 0;
                          if (!(local_1a0 < floatZero)) {
                            (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)(int)(local_1a0 * float255C);
                            componentByte = (undefined1)local_c8;
                            local_c8 = (longlong)(int)(local_1a0 * float255C);
                          }
                        }
                        columnsLeft = columnsLeft + -1;
                        *(undefined1 *)dstPixel = componentByte;
                        srcPixel = srcPixel + srcPixelStride;
                        dstPixel = (uint *)((int)dstPixel + iVar17);
                      } while (columnsLeft != 0);
                    }
                    rowsLeft = rowsLeft - 1;
                    srcPixel = srcPixel + srcRowPad;
                    dstRow = (uint *)((int)dstRow + iVar21);
                  } while (rowsLeft != 0);
                }
                depth = depth - 1;
                dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
                srcPixel = srcPixel + srcImagePad;
              } while (depth != 0);
            }
          }
          else if (0 < (int)depth) {
            do {
              rowsLeft = height;
              dstRow = dstSlice;
              if (0 < (int)height) {
                do {
                  float255C = FLOAT_00108f70;
                  floatOne2 = FLOAT_00108e54;
                  floatZero = FLOAT_00108e50;
                  columnsLeft = width;
                  dstPixel = dstRow;
                  if (0 < width) {
                    do {
                      local_1a0 = floatOne2;
                      (*extractPixelFunc)(auStack_1b0,srcPixel);
                      (*modifyPixelFunc)(glContext,auStack_1b0);
                      if (floatOne2 < local_1a0) {
                        componentByte = 0xff;
                      }
                      else {
                        componentByte = 0;
                        if (!(local_1a0 < floatZero)) {
                          (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)(int)(local_1a0 * float255C);
                          componentByte = (undefined1)local_c8;
                          local_c8 = (longlong)(int)(local_1a0 * float255C);
                        }
                      }
                      columnsLeft = columnsLeft + -1;
                      *(undefined1 *)dstPixel = componentByte;
                      srcPixel = srcPixel + srcPixelStride;
                      dstPixel = (uint *)((int)dstPixel + iVar17);
                    } while (columnsLeft != 0);
                  }
                  rowsLeft = rowsLeft - 1;
                  srcPixel = srcPixel + srcRowPad;
                  dstRow = (uint *)((int)dstRow + iVar21);
                } while (rowsLeft != 0);
              }
              depth = depth - 1;
              dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
              srcPixel = srcPixel + srcImagePad;
            } while (depth != 0);
          }
          goto LAB_0002e240;
        }
      }
      else {
        if (uVar3 == 0x1908) {
          uVar3 = *(ushort *)(textureLevel + 0x12);
          if (uVar3 == 0x8036) {
            if (0 < (int)depth) {
              do {
                rowsLeft = height;
                dstRow = dstSlice;
                if (0 < (int)height) {
                  do {
                    twoPow31 = DOUBLE_00108d80;
                    dstPixel = dstRow;
                    columnsLeft2 = width;
                    if (0 < width) {
                      do {
                        (*extractPixelFunc)(auStack_1b0,srcPixel);
                        (*modifyPixelFunc)(glContext,auStack_1b0);
                        scaledComponent = (double)local_1ac * uint32MaxAsDouble;
                        if (twoPow31 <= scaledComponent) {
                          componentUint = (uint)(int)(scaledComponent - twoPow31);
                          local_d0 = (longlong)(int)componentUint;
                          componentUint = componentUint ^ 0x80000000;
                        }
                        else {
                          componentUint = (uint)(int)scaledComponent;
                          local_c8 = (longlong)(int)componentUint;
                        }
                        scaledComponent = (double)local_1a8 * uint32MaxAsDouble;
                        if (DOUBLE_00108d80 <= scaledComponent) {
                          local_e0 = (longlong)(int)(scaledComponent - DOUBLE_00108d80);
                          uVar18 = (int)(scaledComponent - DOUBLE_00108d80) ^ 0x80000000;
                        }
                        else {
                          uVar18 = (uint)(int)scaledComponent;
                          local_d8 = (longlong)(int)uVar18;
                        }
                        scaledComponent = (double)local_1a4 * uint32MaxAsDouble;
                        if (DOUBLE_00108d80 <= scaledComponent) {
                          local_f0 = (longlong)(int)(scaledComponent - DOUBLE_00108d80);
                          uVar12 = (int)(scaledComponent - DOUBLE_00108d80) ^ 0x80000000;
                        }
                        else {
                          uVar12 = (uint)(int)scaledComponent;
                          local_e8 = (longlong)(int)uVar12;
                        }
                        scaledComponent = (double)local_1a0 * uint32MaxAsDouble;
                        if (DOUBLE_00108d80 <= scaledComponent) {
                          local_100 = (longlong)(int)(scaledComponent - DOUBLE_00108d80);
                          uVar13 = (int)(scaledComponent - DOUBLE_00108d80) ^ 0x80000000;
                        }
                        else {
                          uVar13 = (uint)(int)scaledComponent;
                          local_f8 = (longlong)(int)uVar13;
                        }
                        columnsLeft2 = columnsLeft2 + -1;
                        *dstPixel = componentUint & 0xffc00000 | uVar18 >> 10 & 0x3ff000 |
                                   uVar12 >> 0x14 & 0xffc | uVar13 >> 0x1e;
                        srcPixel = srcPixel + srcPixelStride;
                        dstPixel = dstPixel + 1;
                      } while (columnsLeft2 != 0);
                    }
                    rowsLeft = rowsLeft - 1;
                    srcPixel = srcPixel + srcRowPad;
                    dstRow = (uint *)((int)dstRow + iVar21);
                  } while (rowsLeft != 0);
                }
                depth = depth - 1;
                dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
                srcPixel = srcPixel + srcImagePad;
              } while (depth != 0);
            }
            goto LAB_0002e240;
          }
          if (uVar3 < 0x8037) {
            if (uVar3 == 0x8033) {
              if (0 < (int)depth) {
                do {
                  rowsLeft = height;
                  dstRow = dstSlice;
                  if (0 < (int)height) {
                    do {
                      if (0 < width) {
                        local_90 = float65535;
                        dstPixel = dstRow;
                        columnsLeft2 = width;
                        do {
                          (*extractPixelFunc)(auStack_1b0,srcPixel);
                          (*modifyPixelFunc)(glContext,auStack_1b0);
                          columnsLeft2 = columnsLeft2 + -1;
                          local_c8 = (longlong)(int)(local_1ac * float65535);
                          local_d0 = (longlong)(int)(local_1a8 * float65535);
                          local_d8 = (longlong)(int)(local_1a4 * float65535);
                          local_e0 = (longlong)(int)(local_1a0 * float65535);
                          *(ushort *)dstPixel =
                               (ushort)(int)(local_1ac * float65535) & 0xf000 |
                               (ushort)((uint)(int)(local_1a8 * float65535) >> 4) & 0xf00 |
                               (ushort)((uint)(int)(local_1a4 * float65535) >> 8) & 0xf0 |
                               (ushort)((uint)(int)(local_1a0 * float65535) >> 0xc) & 0xf;
                          dstPixel = (uint *)((int)dstPixel + 2);
                          srcPixel = srcPixel + srcPixelStride;
                        } while (columnsLeft2 != 0);
                      }
                      rowsLeft = rowsLeft - 1;
                      srcPixel = srcPixel + srcRowPad;
                      dstRow = (uint *)((int)dstRow + iVar21);
                    } while (rowsLeft != 0);
                  }
                  depth = depth - 1;
                  dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
                  srcPixel = srcPixel + srcImagePad;
                } while (depth != 0);
              }
              goto LAB_0002e240;
            }
            if (uVar3 < 0x8034) {
              if (uVar3 == 8) {
                if (0 < (int)depth) {
                  do {
                    rowsLeft = height;
                    dstRow = dstSlice;
                    if (0 < (int)height) {
                      do {
                        float127B = FLOAT_00108f6c;
                        floatMinusOne = FLOAT_00108e58;
                        floatOne = FLOAT_00108e54;
                        columnsLeft = width;
                        dstPixel = dstRow;
                        if (0 < width) {
                          do {
                            (*extractPixelFunc)(auStack_1b0,srcPixel);
                            _gleModifyPixelSignedRGBA(glContext,auStack_1b0);
                            if (floatOne < local_1ac) {
                              componentByte = 0x7f;
                            }
                            else {
                              componentByte = 0x81;
                              if (!(local_1ac < floatMinusOne)) {
                                (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)(int)(local_1ac * float127B);
                                componentByte = (undefined1)local_c8;
                                local_c8 = (longlong)(int)(local_1ac * float127B);
                              }
                            }
                            *(undefined1 *)dstPixel = componentByte;
                            if (floatOne < local_1a8) {
                              componentByte = 0x7f;
                            }
                            else {
                              componentByte = 0x81;
                              if (!(local_1a8 < floatMinusOne)) {
                                (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)(int)(local_1a8 * float127B);
                                componentByte = (undefined1)local_c8;
                                local_c8 = (longlong)(int)(local_1a8 * float127B);
                              }
                            }
                            *(undefined1 *)((int)dstPixel + 1) = componentByte;
                            if (floatOne < local_1a4) {
                              componentByte = 0x7f;
                            }
                            else {
                              componentByte = 0x81;
                              if (!(local_1a4 < floatMinusOne)) {
                                (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)(int)(local_1a4 * float127B);
                                componentByte = (undefined1)local_c8;
                                local_c8 = (longlong)(int)(local_1a4 * float127B);
                              }
                            }
                            *(undefined1 *)((int)dstPixel + 2) = componentByte;
                            if (floatOne < local_1a0) {
                              componentByte = 0x7f;
                            }
                            else {
                              componentByte = 0x81;
                              if (!(local_1a0 < floatMinusOne)) {
                                (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)(int)(local_1a0 * float127B);
                                componentByte = (undefined1)local_c8;
                                local_c8 = (longlong)(int)(local_1a0 * float127B);
                              }
                            }
                            columnsLeft = columnsLeft + -1;
                            *(undefined1 *)((int)dstPixel + 3) = componentByte;
                            srcPixel = srcPixel + srcPixelStride;
                            dstPixel = (uint *)((int)dstPixel + iVar17);
                          } while (columnsLeft != 0);
                        }
                        rowsLeft = rowsLeft - 1;
                        srcPixel = srcPixel + srcRowPad;
                        dstRow = (uint *)((int)dstRow + iVar21);
                      } while (rowsLeft != 0);
                    }
                    depth = depth - 1;
                    dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
                    srcPixel = srcPixel + srcImagePad;
                  } while (depth != 0);
                }
                goto LAB_0002e240;
              }
            }
            else {
              if (uVar3 == 0x8034) {
                if (0 < (int)depth) {
                  do {
                    rowsLeft = height;
                    dstRow = dstSlice;
                    if (0 < (int)height) {
                      do {
                        if (0 < width) {
                          local_90 = float65535;
                          dstPixel = dstRow;
                          columnsLeft2 = width;
                          do {
                            (*extractPixelFunc)(auStack_1b0,srcPixel);
                            (*modifyPixelFunc)(glContext,auStack_1b0);
                            columnsLeft2 = columnsLeft2 + -1;
                            local_c8 = (longlong)(int)(local_1ac * float65535);
                            local_d0 = (longlong)(int)(local_1a8 * float65535);
                            local_d8 = (longlong)(int)(local_1a4 * float65535);
                            local_e0 = (longlong)(int)(local_1a0 * float65535);
                            *(ushort *)dstPixel =
                                 (ushort)(int)(local_1ac * float65535) & 0xf800 |
                                 (ushort)((uint)(int)(local_1a8 * float65535) >> 5) & 0x7c0 |
                                 (ushort)((uint)(int)(local_1a4 * float65535) >> 10) & 0x3e |
                                 (ushort)((uint)(int)(local_1a0 * float65535) >> 0xf) & 1;
                            dstPixel = (uint *)((int)dstPixel + 2);
                            srcPixel = srcPixel + srcPixelStride;
                          } while (columnsLeft2 != 0);
                        }
                        rowsLeft = rowsLeft - 1;
                        srcPixel = srcPixel + srcRowPad;
                        dstRow = (uint *)((int)dstRow + iVar21);
                      } while (rowsLeft != 0);
                    }
                    depth = depth - 1;
                    dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
                    srcPixel = srcPixel + srcImagePad;
                  } while (depth != 0);
                }
                goto LAB_0002e240;
              }
              if (uVar3 == 0x8035) {
                if (0 < (int)depth) {
                  do {
                    rowsLeft = height;
                    dstRow = dstSlice;
                    if (0 < (int)height) {
                      do {
                        twoPow31 = DOUBLE_00108d80;
                        dstPixel = dstRow;
                        columnsLeft2 = width;
                        if (0 < width) {
                          do {
                            (*extractPixelFunc)(auStack_1b0,srcPixel);
                            (*modifyPixelFunc)(glContext,auStack_1b0);
                            scaledComponent = (double)local_1ac * uint32MaxAsDouble;
                            if (twoPow31 <= scaledComponent) {
                              componentUint = (uint)(int)(scaledComponent - twoPow31);
                              local_d0 = (longlong)(int)componentUint;
                              componentUint = componentUint ^ 0x80000000;
                            }
                            else {
                              componentUint = (uint)(int)scaledComponent;
                              local_c8 = (longlong)(int)componentUint;
                            }
                            scaledComponent = (double)local_1a8 * uint32MaxAsDouble;
                            if (DOUBLE_00108d80 <= scaledComponent) {
                              local_e0 = (longlong)(int)(scaledComponent - DOUBLE_00108d80);
                              uVar18 = (int)(scaledComponent - DOUBLE_00108d80) ^ 0x80000000;
                            }
                            else {
                              uVar18 = (uint)(int)scaledComponent;
                              local_d8 = (longlong)(int)uVar18;
                            }
                            scaledComponent = (double)local_1a4 * uint32MaxAsDouble;
                            if (DOUBLE_00108d80 <= scaledComponent) {
                              local_f0 = (longlong)(int)(scaledComponent - DOUBLE_00108d80);
                              uVar12 = (int)(scaledComponent - DOUBLE_00108d80) ^ 0x80000000;
                            }
                            else {
                              uVar12 = (uint)(int)scaledComponent;
                              local_e8 = (longlong)(int)uVar12;
                            }
                            scaledComponent = (double)local_1a0 * uint32MaxAsDouble;
                            if (DOUBLE_00108d80 <= scaledComponent) {
                              local_100 = (longlong)(int)(scaledComponent - DOUBLE_00108d80);
                              uVar13 = (int)(scaledComponent - DOUBLE_00108d80) ^ 0x80000000;
                            }
                            else {
                              uVar13 = (uint)(int)scaledComponent;
                              local_f8 = (longlong)(int)uVar13;
                            }
                            columnsLeft2 = columnsLeft2 + -1;
                            *dstPixel = componentUint & 0xff000000 | uVar18 >> 8 & 0xff0000 |
                                       uVar12 >> 0x10 & 0xff00 | uVar13 >> 0x18;
                            srcPixel = srcPixel + srcPixelStride;
                            dstPixel = dstPixel + 1;
                          } while (columnsLeft2 != 0);
                        }
                        rowsLeft = rowsLeft - 1;
                        srcPixel = srcPixel + srcRowPad;
                        dstRow = (uint *)((int)dstRow + iVar21);
                      } while (rowsLeft != 0);
                    }
                    depth = depth - 1;
                    dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
                    srcPixel = srcPixel + srcImagePad;
                  } while (depth != 0);
                }
                goto LAB_0002e240;
              }
            }
          }
          else {
            if (uVar3 == 0x8366) {
              if (0 < (int)depth) {
                do {
                  rowsLeft = height;
                  dstRow = dstSlice;
                  if (0 < (int)height) {
                    do {
                      if (0 < width) {
                        local_90 = float65535;
                        dstPixel = dstRow;
                        columnsLeft2 = width;
                        do {
                          (*extractPixelFunc)(auStack_1b0,srcPixel);
                          (*modifyPixelFunc)(glContext,auStack_1b0);
                          columnsLeft2 = columnsLeft2 + -1;
                          local_c8 = (longlong)(int)(local_1a0 * float65535);
                          local_d0 = (longlong)(int)(local_1a4 * float65535);
                          local_d8 = (longlong)(int)(local_1a8 * float65535);
                          local_e0 = (longlong)(int)(local_1ac * float65535);
                          *(ushort *)dstPixel =
                               (ushort)(int)(local_1a0 * float65535) & 0x8000 |
                               (ushort)((uint)(int)(local_1a4 * float65535) >> 1) & 0x7c00 |
                               (ushort)((uint)(int)(local_1a8 * float65535) >> 6) & 0x3e0 |
                               (ushort)((uint)(int)(local_1ac * float65535) >> 0xb) & 0x1f;
                          dstPixel = (uint *)((int)dstPixel + 2);
                          srcPixel = srcPixel + srcPixelStride;
                        } while (columnsLeft2 != 0);
                      }
                      rowsLeft = rowsLeft - 1;
                      srcPixel = srcPixel + srcRowPad;
                      dstRow = (uint *)((int)dstRow + iVar21);
                    } while (rowsLeft != 0);
                  }
                  depth = depth - 1;
                  dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
                  srcPixel = srcPixel + srcImagePad;
                } while (depth != 0);
              }
              goto LAB_0002e240;
            }
            if (uVar3 < 0x8367) {
              if (uVar3 == 0x8365) {
                if (0 < (int)depth) {
                  do {
                    rowsLeft = height;
                    dstRow = dstSlice;
                    if (0 < (int)height) {
                      do {
                        if (0 < width) {
                          local_90 = float65535;
                          dstPixel = dstRow;
                          columnsLeft2 = width;
                          do {
                            (*extractPixelFunc)(auStack_1b0,srcPixel);
                            (*modifyPixelFunc)(glContext,auStack_1b0);
                            columnsLeft2 = columnsLeft2 + -1;
                            local_c8 = (longlong)(int)(local_1a0 * float65535);
                            local_d0 = (longlong)(int)(local_1a4 * float65535);
                            local_d8 = (longlong)(int)(local_1a8 * float65535);
                            local_e0 = (longlong)(int)(local_1ac * float65535);
                            *(ushort *)dstPixel =
                                 (ushort)(int)(local_1a0 * float65535) & 0xf000 |
                                 (ushort)((uint)(int)(local_1a4 * float65535) >> 4) & 0xf00 |
                                 (ushort)((uint)(int)(local_1a8 * float65535) >> 8) & 0xf0 |
                                 (ushort)((uint)(int)(local_1ac * float65535) >> 0xc) & 0xf;
                            dstPixel = (uint *)((int)dstPixel + 2);
                            srcPixel = srcPixel + srcPixelStride;
                          } while (columnsLeft2 != 0);
                        }
                        rowsLeft = rowsLeft - 1;
                        srcPixel = srcPixel + srcRowPad;
                        dstRow = (uint *)((int)dstRow + iVar21);
                      } while (rowsLeft != 0);
                    }
                    depth = depth - 1;
                    dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
                    srcPixel = srcPixel + srcImagePad;
                  } while (depth != 0);
                }
                goto LAB_0002e240;
              }
            }
            else {
              if (uVar3 == 0x8367) {
                if (0 < (int)depth) {
                  do {
                    rowsLeft = height;
                    dstRow = dstSlice;
                    if (0 < (int)height) {
                      do {
                        twoPow31 = DOUBLE_00108d80;
                        dstPixel = dstRow;
                        columnsLeft2 = width;
                        if (0 < width) {
                          do {
                            (*extractPixelFunc)(auStack_1b0,srcPixel);
                            (*modifyPixelFunc)(glContext,auStack_1b0);
                            scaledComponent = (double)local_1a0 * uint32MaxAsDouble;
                            if (twoPow31 <= scaledComponent) {
                              componentUint = (uint)(int)(scaledComponent - twoPow31);
                              local_d0 = (longlong)(int)componentUint;
                              componentUint = componentUint ^ 0x80000000;
                            }
                            else {
                              componentUint = (uint)(int)scaledComponent;
                              local_c8 = (longlong)(int)componentUint;
                            }
                            scaledComponent = (double)local_1a4 * uint32MaxAsDouble;
                            if (DOUBLE_00108d80 <= scaledComponent) {
                              local_e0 = (longlong)(int)(scaledComponent - DOUBLE_00108d80);
                              uVar18 = (int)(scaledComponent - DOUBLE_00108d80) ^ 0x80000000;
                            }
                            else {
                              uVar18 = (uint)(int)scaledComponent;
                              local_d8 = (longlong)(int)uVar18;
                            }
                            scaledComponent = (double)local_1a8 * uint32MaxAsDouble;
                            if (DOUBLE_00108d80 <= scaledComponent) {
                              local_f0 = (longlong)(int)(scaledComponent - DOUBLE_00108d80);
                              uVar12 = (int)(scaledComponent - DOUBLE_00108d80) ^ 0x80000000;
                            }
                            else {
                              uVar12 = (uint)(int)scaledComponent;
                              local_e8 = (longlong)(int)uVar12;
                            }
                            scaledComponent = (double)local_1ac * uint32MaxAsDouble;
                            if (DOUBLE_00108d80 <= scaledComponent) {
                              local_100 = (longlong)(int)(scaledComponent - DOUBLE_00108d80);
                              uVar13 = (int)(scaledComponent - DOUBLE_00108d80) ^ 0x80000000;
                            }
                            else {
                              uVar13 = (uint)(int)scaledComponent;
                              local_f8 = (longlong)(int)uVar13;
                            }
                            columnsLeft2 = columnsLeft2 + -1;
                            *dstPixel = componentUint & 0xff000000 | uVar18 >> 8 & 0xff0000 |
                                       uVar12 >> 0x10 & 0xff00 | uVar13 >> 0x18;
                            srcPixel = srcPixel + srcPixelStride;
                            dstPixel = dstPixel + 1;
                          } while (columnsLeft2 != 0);
                        }
                        rowsLeft = rowsLeft - 1;
                        srcPixel = srcPixel + srcRowPad;
                        dstRow = (uint *)((int)dstRow + iVar21);
                      } while (rowsLeft != 0);
                    }
                    depth = depth - 1;
                    dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
                    srcPixel = srcPixel + srcImagePad;
                  } while (depth != 0);
                }
                goto LAB_0002e240;
              }
              if (uVar3 == 0x8368) {
                if (0 < (int)depth) {
                  do {
                    rowsLeft = height;
                    dstRow = dstSlice;
                    if (0 < (int)height) {
                      do {
                        twoPow31 = DOUBLE_00108d80;
                        dstPixel = dstRow;
                        columnsLeft2 = width;
                        if (0 < width) {
                          do {
                            (*extractPixelFunc)(auStack_1b0,srcPixel);
                            (*modifyPixelFunc)(glContext,auStack_1b0);
                            scaledComponent = (double)local_1a0 * uint32MaxAsDouble;
                            if (twoPow31 <= scaledComponent) {
                              componentUint = (uint)(int)(scaledComponent - twoPow31);
                              local_d0 = (longlong)(int)componentUint;
                              componentUint = componentUint ^ 0x80000000;
                            }
                            else {
                              componentUint = (uint)(int)scaledComponent;
                              local_c8 = (longlong)(int)componentUint;
                            }
                            scaledComponent = (double)local_1a4 * uint32MaxAsDouble;
                            if (DOUBLE_00108d80 <= scaledComponent) {
                              local_e0 = (longlong)(int)(scaledComponent - DOUBLE_00108d80);
                              uVar18 = (int)(scaledComponent - DOUBLE_00108d80) ^ 0x80000000;
                            }
                            else {
                              uVar18 = (uint)(int)scaledComponent;
                              local_d8 = (longlong)(int)uVar18;
                            }
                            scaledComponent = (double)local_1a8 * uint32MaxAsDouble;
                            if (DOUBLE_00108d80 <= scaledComponent) {
                              local_f0 = (longlong)(int)(scaledComponent - DOUBLE_00108d80);
                              uVar12 = (int)(scaledComponent - DOUBLE_00108d80) ^ 0x80000000;
                            }
                            else {
                              uVar12 = (uint)(int)scaledComponent;
                              local_e8 = (longlong)(int)uVar12;
                            }
                            scaledComponent = (double)local_1ac * uint32MaxAsDouble;
                            if (DOUBLE_00108d80 <= scaledComponent) {
                              local_100 = (longlong)(int)(scaledComponent - DOUBLE_00108d80);
                              uVar13 = (int)(scaledComponent - DOUBLE_00108d80) ^ 0x80000000;
                            }
                            else {
                              uVar13 = (uint)(int)scaledComponent;
                              local_f8 = (longlong)(int)uVar13;
                            }
                            columnsLeft2 = columnsLeft2 + -1;
                            *dstPixel = componentUint & 0xc0000000 | uVar18 >> 2 & 0x3ff00000 |
                                       uVar12 >> 0xc & 0xffc00 | uVar13 >> 0x16;
                            srcPixel = srcPixel + srcPixelStride;
                            dstPixel = dstPixel + 1;
                          } while (columnsLeft2 != 0);
                        }
                        rowsLeft = rowsLeft - 1;
                        srcPixel = srcPixel + srcRowPad;
                        dstRow = (uint *)((int)dstRow + iVar21);
                      } while (rowsLeft != 0);
                    }
                    depth = depth - 1;
                    dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
                    srcPixel = srcPixel + srcImagePad;
                  } while (depth != 0);
                }
                goto LAB_0002e240;
              }
            }
          }
          if (0 < (int)depth) {
            do {
              rowsLeft = height;
              dstRow = dstSlice;
              if (0 < (int)height) {
                do {
                  float255C = FLOAT_00108f70;
                  floatOne2 = FLOAT_00108e54;
                  floatZero = FLOAT_00108e50;
                  columnsLeft = width;
                  dstPixel = dstRow;
                  if (0 < width) {
                    do {
                      local_1ac = floatZero;
                      local_1a8 = floatZero;
                      local_1a4 = floatZero;
                      local_1a0 = floatOne2;
                      (*extractPixelFunc)(auStack_1b0,srcPixel);
                      (*modifyPixelFunc)(glContext,auStack_1b0);
                      if (floatOne2 < local_1ac) {
                        componentByte = 0xff;
                      }
                      else {
                        componentByte = 0;
                        if (!(local_1ac < floatZero)) {
                          (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)(int)(local_1ac * float255C);
                          componentByte = (undefined1)local_c8;
                          local_c8 = (longlong)(int)(local_1ac * float255C);
                        }
                      }
                      *(undefined1 *)dstPixel = componentByte;
                      if (floatOne2 < local_1a8) {
                        componentByte = 0xff;
                      }
                      else {
                        componentByte = 0;
                        if (!(local_1a8 < floatZero)) {
                          (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)(int)(local_1a8 * float255C);
                          componentByte = (undefined1)local_c8;
                          local_c8 = (longlong)(int)(local_1a8 * float255C);
                        }
                      }
                      *(undefined1 *)((int)dstPixel + 1) = componentByte;
                      if (floatOne2 < local_1a4) {
                        componentByte = 0xff;
                      }
                      else {
                        componentByte = 0;
                        if (!(local_1a4 < floatZero)) {
                          (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)(int)(local_1a4 * float255C);
                          componentByte = (undefined1)local_c8;
                          local_c8 = (longlong)(int)(local_1a4 * float255C);
                        }
                      }
                      *(undefined1 *)((int)dstPixel + 2) = componentByte;
                      if (floatOne2 < local_1a0) {
                        componentByte = 0xff;
                      }
                      else {
                        componentByte = 0;
                        if (!(local_1a0 < floatZero)) {
                          (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)(int)(local_1a0 * float255C);
                          componentByte = (undefined1)local_c8;
                          local_c8 = (longlong)(int)(local_1a0 * float255C);
                        }
                      }
                      columnsLeft = columnsLeft + -1;
                      *(undefined1 *)((int)dstPixel + 3) = componentByte;
                      srcPixel = srcPixel + srcPixelStride;
                      dstPixel = (uint *)((int)dstPixel + iVar17);
                    } while (columnsLeft != 0);
                  }
                  rowsLeft = rowsLeft - 1;
                  srcPixel = srcPixel + srcRowPad;
                  dstRow = (uint *)((int)dstRow + iVar21);
                } while (rowsLeft != 0);
              }
              depth = depth - 1;
              dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
              srcPixel = srcPixel + srcImagePad;
            } while (depth != 0);
          }
          goto LAB_0002e240;
        }
        if (uVar3 == 0x1909) {
          if (*(short *)(textureLevel + 0x12) == 0x1400) {
            if (0 < (int)depth) {
              do {
                rowsLeft = height;
                dstRow = dstSlice;
                if (0 < (int)height) {
                  do {
                    float127B = FLOAT_00108f6c;
                    floatMinusOne = FLOAT_00108e58;
                    floatOne = FLOAT_00108e54;
                    columnsLeft = width;
                    dstPixel = dstRow;
                    if (0 < width) {
                      do {
                        (*extractPixelFunc)(auStack_1b0,srcPixel);
                        _gleModifyPixelSignedRGBA(glContext,auStack_1b0);
                        if (floatOne < local_1ac) {
                          componentByte = 0x7f;
                        }
                        else {
                          componentByte = 0x81;
                          if (!(local_1ac < floatMinusOne)) {
                            (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)(int)(local_1ac * float127B);
                            componentByte = (undefined1)local_c8;
                            local_c8 = (longlong)(int)(local_1ac * float127B);
                          }
                        }
                        columnsLeft = columnsLeft + -1;
                        *(undefined1 *)dstPixel = componentByte;
                        srcPixel = srcPixel + srcPixelStride;
                        dstPixel = (uint *)((int)dstPixel + iVar17);
                      } while (columnsLeft != 0);
                    }
                    rowsLeft = rowsLeft - 1;
                    srcPixel = srcPixel + srcRowPad;
                    dstRow = (uint *)((int)dstRow + iVar21);
                  } while (rowsLeft != 0);
                }
                depth = depth - 1;
                dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
                srcPixel = srcPixel + srcImagePad;
              } while (depth != 0);
            }
          }
          else if (0 < (int)depth) {
            do {
              rowsLeft = height;
              dstRow = dstSlice;
              if (0 < (int)height) {
                do {
                  float255C = FLOAT_00108f70;
                  floatOne2 = FLOAT_00108e54;
                  floatZero = FLOAT_00108e50;
                  columnsLeft = width;
                  dstPixel = dstRow;
                  if (0 < width) {
                    do {
                      local_1ac = floatZero;
                      (*extractPixelFunc)(auStack_1b0,srcPixel);
                      (*modifyPixelFunc)(glContext,auStack_1b0);
                      if (floatOne2 < local_1ac) {
                        componentByte = 0xff;
                      }
                      else {
                        componentByte = 0;
                        if (!(local_1ac < floatZero)) {
                          (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)(int)(local_1ac * float255C);
                          componentByte = (undefined1)local_c8;
                          local_c8 = (longlong)(int)(local_1ac * float255C);
                        }
                      }
                      columnsLeft = columnsLeft + -1;
                      *(undefined1 *)dstPixel = componentByte;
                      srcPixel = srcPixel + srcPixelStride;
                      dstPixel = (uint *)((int)dstPixel + iVar17);
                    } while (columnsLeft != 0);
                  }
                  rowsLeft = rowsLeft - 1;
                  srcPixel = srcPixel + srcRowPad;
                  dstRow = (uint *)((int)dstRow + iVar21);
                } while (rowsLeft != 0);
              }
              depth = depth - 1;
              dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
              srcPixel = srcPixel + srcImagePad;
            } while (depth != 0);
          }
          goto LAB_0002e240;
        }
      }
    }
    else {
      if (uVar3 == 0x86f4) {
        uVar3 = *(ushort *)(textureLevel + 0x12);
        if (uVar3 == 6) {
          if (0 < (int)depth) {
            local_9c = iVar17 << 1;
            do {
              iVar17 = local_9c;
              if (0 < (int)height) {
                local_a4 = FLOAT_00108f74;
                rowsLeft = height;
                dstRow = dstSlice;
                do {
                  fVar9 = local_a4;
                  floatMinusOne = FLOAT_00108e58;
                  floatOne = FLOAT_00108e54;
                  columnsLeft = width;
                  dstPixel = dstRow;
                  if (0 < width) {
                    do {
                      (*extractPixelFunc)(auStack_1b0,srcPixel);
                      (*modifyPixelFunc)(glContext,auStack_1b0);
                      if (floatOne < local_190) {
                        componentShort = 0x7fff;
                      }
                      else {
                        componentShort = 0x8001;
                        if (!(local_190 < floatMinusOne)) {
                          scaledInt = (int)(local_190 * fVar9);
                          (*(unsigned short *)((unsigned char *)&(local_c8) + 6)) = (undefined2)scaledInt;
                          componentShort = (*(unsigned short *)((unsigned char *)&(local_c8) + 6));
                          local_c8 = (longlong)scaledInt;
                        }
                      }
                      *(undefined2 *)dstPixel = componentShort;
                      if (floatOne < local_18c) {
                        componentShort = 0x7fff;
                      }
                      else {
                        componentShort = 0x8001;
                        if (!(local_18c < floatMinusOne)) {
                          scaledInt = (int)(local_18c * fVar9);
                          (*(unsigned short *)((unsigned char *)&(local_c8) + 6)) = (undefined2)scaledInt;
                          componentShort = (*(unsigned short *)((unsigned char *)&(local_c8) + 6));
                          local_c8 = (longlong)scaledInt;
                        }
                      }
                      columnsLeft = columnsLeft + -1;
                      *(undefined2 *)((int)dstPixel + 2) = componentShort;
                      srcPixel = srcPixel + srcPixelStride;
                      dstPixel = (uint *)((int)dstPixel + iVar17);
                    } while (columnsLeft != 0);
                  }
                  rowsLeft = rowsLeft - 1;
                  dstRow = (uint *)((int)dstRow + iVar21);
                  srcPixel = srcPixel + srcRowPad;
                } while (rowsLeft != 0);
              }
              depth = depth - 1;
              dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
              srcPixel = srcPixel + srcImagePad;
            } while (depth != 0);
          }
        }
        else if (uVar3 < 7) {
          if ((uVar3 == 5) && (0 < (int)depth)) {
            local_a0 = iVar17 << 1;
            do {
              iVar17 = local_a0;
              if (0 < (int)height) {
                local_a8 = FLOAT_00108ea0;
                rowsLeft = height;
                dstRow = dstSlice;
                do {
                  fVar9 = local_a8;
                  floatOne2 = FLOAT_00108e54;
                  floatZero = FLOAT_00108e50;
                  columnsLeft = width;
                  dstPixel = dstRow;
                  if (0 < width) {
                    do {
                      (*extractPixelFunc)(auStack_1b0,srcPixel);
                      (*modifyPixelFunc)(glContext,auStack_1b0);
                      if (floatOne2 < local_190) {
                        componentShort = 0xffff;
                      }
                      else {
                        componentShort = 0;
                        if (!(local_190 < floatZero)) {
                          scaledInt = (int)(local_190 * fVar9);
                          (*(unsigned short *)((unsigned char *)&(local_c8) + 6)) = (undefined2)scaledInt;
                          componentShort = (*(unsigned short *)((unsigned char *)&(local_c8) + 6));
                          local_c8 = (longlong)scaledInt;
                        }
                      }
                      *(undefined2 *)dstPixel = componentShort;
                      if (floatOne2 < local_18c) {
                        componentShort = 0xffff;
                      }
                      else {
                        componentShort = 0;
                        if (!(local_18c < floatZero)) {
                          scaledInt = (int)(local_18c * fVar9);
                          (*(unsigned short *)((unsigned char *)&(local_c8) + 6)) = (undefined2)scaledInt;
                          componentShort = (*(unsigned short *)((unsigned char *)&(local_c8) + 6));
                          local_c8 = (longlong)scaledInt;
                        }
                      }
                      columnsLeft = columnsLeft + -1;
                      *(undefined2 *)((int)dstPixel + 2) = componentShort;
                      srcPixel = srcPixel + srcPixelStride;
                      dstPixel = (uint *)((int)dstPixel + iVar17);
                    } while (columnsLeft != 0);
                  }
                  rowsLeft = rowsLeft - 1;
                  dstRow = (uint *)((int)dstRow + iVar21);
                  srcPixel = srcPixel + srcRowPad;
                } while (rowsLeft != 0);
              }
              depth = depth - 1;
              dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
              srcPixel = srcPixel + srcImagePad;
            } while (depth != 0);
          }
        }
        else if (uVar3 == 0x1400) {
          if (0 < (int)depth) {
            do {
              rowsLeft = height;
              dstRow = dstSlice;
              if (0 < (int)height) {
                do {
                  float127B = FLOAT_00108f6c;
                  floatMinusOne = FLOAT_00108e58;
                  floatOne = FLOAT_00108e54;
                  columnsLeft = width;
                  dstPixel = dstRow;
                  if (0 < width) {
                    do {
                      (*extractPixelFunc)(auStack_1b0,srcPixel);
                      (*modifyPixelFunc)(glContext,auStack_1b0);
                      if (floatOne < local_190) {
                        componentByte = 0x7f;
                      }
                      else {
                        componentByte = 0x81;
                        if (!(local_190 < floatMinusOne)) {
                          scaledInt = (int)(local_190 * float127B);
                          (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)scaledInt;
                          componentByte = (undefined1)local_c8;
                          local_c8 = (longlong)scaledInt;
                        }
                      }
                      *(undefined1 *)dstPixel = componentByte;
                      if (floatOne < local_18c) {
                        componentByte = 0x7f;
                      }
                      else {
                        componentByte = 0x81;
                        if (!(local_18c < floatMinusOne)) {
                          scaledInt = (int)(local_18c * float127B);
                          (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)scaledInt;
                          componentByte = (undefined1)local_c8;
                          local_c8 = (longlong)scaledInt;
                        }
                      }
                      columnsLeft = columnsLeft + -1;
                      *(undefined1 *)((int)dstPixel + 1) = componentByte;
                      srcPixel = srcPixel + srcPixelStride;
                      dstPixel = (uint *)((int)dstPixel + iVar17);
                    } while (columnsLeft != 0);
                  }
                  rowsLeft = rowsLeft - 1;
                  srcPixel = srcPixel + srcRowPad;
                  dstRow = (uint *)((int)dstRow + iVar21);
                } while (rowsLeft != 0);
              }
              depth = depth - 1;
              dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
              srcPixel = srcPixel + srcImagePad;
            } while (depth != 0);
          }
        }
        else if ((uVar3 == 0x1401) && (0 < (int)depth)) {
          do {
            rowsLeft = height;
            dstRow = dstSlice;
            if (0 < (int)height) {
              do {
                float255C = FLOAT_00108f70;
                floatOne2 = FLOAT_00108e54;
                floatZero = FLOAT_00108e50;
                columnsLeft = width;
                dstPixel = dstRow;
                if (0 < width) {
                  do {
                    (*extractPixelFunc)(auStack_1b0,srcPixel);
                    (*modifyPixelFunc)(glContext,auStack_1b0);
                    if (floatOne2 < local_190) {
                      componentByte = 0xff;
                    }
                    else {
                      componentByte = 0;
                      if (!(local_190 < floatZero)) {
                        scaledInt = (int)(local_190 * float255C);
                        (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)scaledInt;
                        componentByte = (undefined1)local_c8;
                        local_c8 = (longlong)scaledInt;
                      }
                    }
                    *(undefined1 *)dstPixel = componentByte;
                    if (floatOne2 < local_18c) {
                      componentByte = 0xff;
                    }
                    else {
                      componentByte = 0;
                      if (!(local_18c < floatZero)) {
                        scaledInt = (int)(local_18c * float255C);
                        (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)scaledInt;
                        componentByte = (undefined1)local_c8;
                        local_c8 = (longlong)scaledInt;
                      }
                    }
                    columnsLeft = columnsLeft + -1;
                    *(undefined1 *)((int)dstPixel + 1) = componentByte;
                    srcPixel = srcPixel + srcPixelStride;
                    dstPixel = (uint *)((int)dstPixel + iVar17);
                  } while (columnsLeft != 0);
                }
                rowsLeft = rowsLeft - 1;
                srcPixel = srcPixel + srcRowPad;
                dstRow = (uint *)((int)dstRow + iVar21);
              } while (rowsLeft != 0);
            }
            depth = depth - 1;
            dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
            srcPixel = srcPixel + srcImagePad;
          } while (depth != 0);
        }
        goto LAB_0002e240;
      }
      if (uVar3 < 0x86f5) {
        if (uVar3 == 0x80e1) {
          uVar3 = *(ushort *)(textureLevel + 0x12);
          if (uVar3 == 0x8036) {
            if (0 < (int)depth) {
              do {
                rowsLeft = height;
                dstRow = dstSlice;
                if (0 < (int)height) {
                  do {
                    twoPow31 = DOUBLE_00108d80;
                    dstPixel = dstRow;
                    columnsLeft2 = width;
                    if (0 < width) {
                      do {
                        (*extractPixelFunc)(auStack_1b0,srcPixel);
                        (*modifyPixelFunc)(glContext,auStack_1b0);
                        scaledComponent = (double)local_1a4 * uint32MaxAsDouble;
                        if (twoPow31 <= scaledComponent) {
                          componentUint = (uint)(int)(scaledComponent - twoPow31);
                          local_d0 = (longlong)(int)componentUint;
                          componentUint = componentUint ^ 0x80000000;
                        }
                        else {
                          componentUint = (uint)(int)scaledComponent;
                          local_c8 = (longlong)(int)componentUint;
                        }
                        scaledComponent = (double)local_1a8 * uint32MaxAsDouble;
                        if (DOUBLE_00108d80 <= scaledComponent) {
                          local_e0 = (longlong)(int)(scaledComponent - DOUBLE_00108d80);
                          uVar18 = (int)(scaledComponent - DOUBLE_00108d80) ^ 0x80000000;
                        }
                        else {
                          uVar18 = (uint)(int)scaledComponent;
                          local_d8 = (longlong)(int)uVar18;
                        }
                        scaledComponent = (double)local_1ac * uint32MaxAsDouble;
                        if (DOUBLE_00108d80 <= scaledComponent) {
                          local_f0 = (longlong)(int)(scaledComponent - DOUBLE_00108d80);
                          uVar12 = (int)(scaledComponent - DOUBLE_00108d80) ^ 0x80000000;
                        }
                        else {
                          uVar12 = (uint)(int)scaledComponent;
                          local_e8 = (longlong)(int)uVar12;
                        }
                        scaledComponent = (double)local_1a0 * uint32MaxAsDouble;
                        if (DOUBLE_00108d80 <= scaledComponent) {
                          local_100 = (longlong)(int)(scaledComponent - DOUBLE_00108d80);
                          uVar13 = (int)(scaledComponent - DOUBLE_00108d80) ^ 0x80000000;
                        }
                        else {
                          uVar13 = (uint)(int)scaledComponent;
                          local_f8 = (longlong)(int)uVar13;
                        }
                        columnsLeft2 = columnsLeft2 + -1;
                        *dstPixel = componentUint & 0xffc00000 | uVar18 >> 10 & 0x3ff000 |
                                   uVar12 >> 0x14 & 0xffc | uVar13 >> 0x1e;
                        srcPixel = srcPixel + srcPixelStride;
                        dstPixel = dstPixel + 1;
                      } while (columnsLeft2 != 0);
                    }
                    rowsLeft = rowsLeft - 1;
                    srcPixel = srcPixel + srcRowPad;
                    dstRow = (uint *)((int)dstRow + iVar21);
                  } while (rowsLeft != 0);
                }
                depth = depth - 1;
                dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
                srcPixel = srcPixel + srcImagePad;
              } while (depth != 0);
            }
            goto LAB_0002e240;
          }
          if (uVar3 < 0x8037) {
            if (uVar3 == 0x8033) {
              if (0 < (int)depth) {
                do {
                  rowsLeft = height;
                  dstRow = dstSlice;
                  if (0 < (int)height) {
                    do {
                      if (0 < width) {
                        local_90 = float65535;
                        dstPixel = dstRow;
                        columnsLeft2 = width;
                        do {
                          (*extractPixelFunc)(auStack_1b0,srcPixel);
                          (*modifyPixelFunc)(glContext,auStack_1b0);
                          columnsLeft2 = columnsLeft2 + -1;
                          local_c8 = (longlong)(int)(local_1a4 * float65535);
                          local_d0 = (longlong)(int)(local_1a8 * float65535);
                          local_d8 = (longlong)(int)(local_1ac * float65535);
                          local_e0 = (longlong)(int)(local_1a0 * float65535);
                          *(ushort *)dstPixel =
                               (ushort)(int)(local_1a4 * float65535) & 0xf000 |
                               (ushort)((uint)(int)(local_1a8 * float65535) >> 4) & 0xf00 |
                               (ushort)((uint)(int)(local_1ac * float65535) >> 8) & 0xf0 |
                               (ushort)((uint)(int)(local_1a0 * float65535) >> 0xc) & 0xf;
                          dstPixel = (uint *)((int)dstPixel + 2);
                          srcPixel = srcPixel + srcPixelStride;
                        } while (columnsLeft2 != 0);
                      }
                      rowsLeft = rowsLeft - 1;
                      srcPixel = srcPixel + srcRowPad;
                      dstRow = (uint *)((int)dstRow + iVar21);
                    } while (rowsLeft != 0);
                  }
                  depth = depth - 1;
                  dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
                  srcPixel = srcPixel + srcImagePad;
                } while (depth != 0);
              }
              goto LAB_0002e240;
            }
            if (uVar3 < 0x8034) {
              if (uVar3 == 7) {
                if (0 < (int)depth) {
                  do {
                    rowsLeft = height;
                    dstRow = dstSlice;
                    if (0 < (int)height) {
                      do {
                        float255 = FLOAT_00108f70;
                        float127 = FLOAT_00108f6c;
                        floatMinusOne2 = FLOAT_00108e58;
                        floatOne2 = FLOAT_00108e54;
                        floatZero = FLOAT_00108e50;
                        if (0 < width) {
                          puVar30 = (undefined1 *)((int)dstRow + 3);
                          dstPixel = dstRow;
                          columnsLeft = width;
                          do {
                            (*extractPixelFunc)(auStack_1b0,srcPixel);
                            _gleModifyPixelSignedRGB_UnsignedA(glContext,auStack_1b0);
                            if (floatOne2 < local_1a0) {
                              componentByte = 0xff;
                            }
                            else {
                              componentByte = 0;
                              if (!(local_1a0 < floatZero)) {
                                (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)(int)(local_1a0 * float255);
                                componentByte = (undefined1)local_c8;
                                local_c8 = (longlong)(int)(local_1a0 * float255);
                              }
                            }
                            *(undefined1 *)dstPixel = componentByte;
                            if (floatOne2 < local_1ac) {
                              componentByte = 0x7f;
                            }
                            else {
                              componentByte = 0x81;
                              if (!(local_1ac < floatMinusOne2)) {
                                (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)(int)(local_1ac * float127);
                                componentByte = (undefined1)local_c8;
                                local_c8 = (longlong)(int)(local_1ac * float127);
                              }
                            }
                            puVar30[-2] = componentByte;
                            if (floatOne2 < local_1a8) {
                              componentByte = 0x7f;
                            }
                            else {
                              componentByte = 0x81;
                              if (!(local_1a8 < floatMinusOne2)) {
                                (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)(int)(local_1a8 * float127);
                                componentByte = (undefined1)local_c8;
                                local_c8 = (longlong)(int)(local_1a8 * float127);
                              }
                            }
                            puVar30[-1] = componentByte;
                            if (floatOne2 < local_1a4) {
                              componentByte = 0x7f;
                            }
                            else {
                              componentByte = 0x81;
                              if (!(local_1a4 < floatMinusOne2)) {
                                (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)(int)(local_1a4 * float127);
                                componentByte = (undefined1)local_c8;
                                local_c8 = (longlong)(int)(local_1a4 * float127);
                              }
                            }
                            columnsLeft = columnsLeft + -1;
                            *puVar30 = componentByte;
                            puVar30 = puVar30 + iVar17;
                            dstPixel = (uint *)((int)dstPixel + iVar17);
                            srcPixel = srcPixel + srcPixelStride;
                          } while (columnsLeft != 0);
                        }
                        rowsLeft = rowsLeft - 1;
                        srcPixel = srcPixel + srcRowPad;
                        dstRow = (uint *)((int)dstRow + iVar21);
                      } while (rowsLeft != 0);
                    }
                    depth = depth - 1;
                    dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
                    srcPixel = srcPixel + srcImagePad;
                  } while (depth != 0);
                }
                goto LAB_0002e240;
              }
            }
            else {
              if (uVar3 == 0x8034) {
                if (0 < (int)depth) {
                  do {
                    rowsLeft = height;
                    dstRow = dstSlice;
                    if (0 < (int)height) {
                      do {
                        if (0 < width) {
                          local_90 = float65535;
                          dstPixel = dstRow;
                          columnsLeft2 = width;
                          do {
                            (*extractPixelFunc)(auStack_1b0,srcPixel);
                            (*modifyPixelFunc)(glContext,auStack_1b0);
                            columnsLeft2 = columnsLeft2 + -1;
                            local_c8 = (longlong)(int)(local_1a4 * float65535);
                            local_d0 = (longlong)(int)(local_1a8 * float65535);
                            local_d8 = (longlong)(int)(local_1ac * float65535);
                            local_e0 = (longlong)(int)(local_1a0 * float65535);
                            *(ushort *)dstPixel =
                                 (ushort)(int)(local_1a4 * float65535) & 0xf800 |
                                 (ushort)((uint)(int)(local_1a8 * float65535) >> 5) & 0x7c0 |
                                 (ushort)((uint)(int)(local_1ac * float65535) >> 10) & 0x3e |
                                 (ushort)((uint)(int)(local_1a0 * float65535) >> 0xf) & 1;
                            dstPixel = (uint *)((int)dstPixel + 2);
                            srcPixel = srcPixel + srcPixelStride;
                          } while (columnsLeft2 != 0);
                        }
                        rowsLeft = rowsLeft - 1;
                        srcPixel = srcPixel + srcRowPad;
                        dstRow = (uint *)((int)dstRow + iVar21);
                      } while (rowsLeft != 0);
                    }
                    depth = depth - 1;
                    dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
                    srcPixel = srcPixel + srcImagePad;
                  } while (depth != 0);
                }
                goto LAB_0002e240;
              }
              if (uVar3 == 0x8035) {
                if (0 < (int)depth) {
                  do {
                    rowsLeft = height;
                    dstRow = dstSlice;
                    if (0 < (int)height) {
                      do {
                        twoPow31 = DOUBLE_00108d80;
                        dstPixel = dstRow;
                        columnsLeft2 = width;
                        if (0 < width) {
                          do {
                            (*extractPixelFunc)(auStack_1b0,srcPixel);
                            (*modifyPixelFunc)(glContext,auStack_1b0);
                            scaledComponent = (double)local_1a4 * uint32MaxAsDouble;
                            if (twoPow31 <= scaledComponent) {
                              componentUint = (uint)(int)(scaledComponent - twoPow31);
                              local_d0 = (longlong)(int)componentUint;
                              componentUint = componentUint ^ 0x80000000;
                            }
                            else {
                              componentUint = (uint)(int)scaledComponent;
                              local_c8 = (longlong)(int)componentUint;
                            }
                            scaledComponent = (double)local_1a8 * uint32MaxAsDouble;
                            if (DOUBLE_00108d80 <= scaledComponent) {
                              local_e0 = (longlong)(int)(scaledComponent - DOUBLE_00108d80);
                              uVar18 = (int)(scaledComponent - DOUBLE_00108d80) ^ 0x80000000;
                            }
                            else {
                              uVar18 = (uint)(int)scaledComponent;
                              local_d8 = (longlong)(int)uVar18;
                            }
                            scaledComponent = (double)local_1ac * uint32MaxAsDouble;
                            if (DOUBLE_00108d80 <= scaledComponent) {
                              local_f0 = (longlong)(int)(scaledComponent - DOUBLE_00108d80);
                              uVar12 = (int)(scaledComponent - DOUBLE_00108d80) ^ 0x80000000;
                            }
                            else {
                              uVar12 = (uint)(int)scaledComponent;
                              local_e8 = (longlong)(int)uVar12;
                            }
                            scaledComponent = (double)local_1a0 * uint32MaxAsDouble;
                            if (DOUBLE_00108d80 <= scaledComponent) {
                              local_100 = (longlong)(int)(scaledComponent - DOUBLE_00108d80);
                              uVar13 = (int)(scaledComponent - DOUBLE_00108d80) ^ 0x80000000;
                            }
                            else {
                              uVar13 = (uint)(int)scaledComponent;
                              local_f8 = (longlong)(int)uVar13;
                            }
                            columnsLeft2 = columnsLeft2 + -1;
                            *dstPixel = componentUint & 0xff000000 | uVar18 >> 8 & 0xff0000 |
                                       uVar12 >> 0x10 & 0xff00 | uVar13 >> 0x18;
                            srcPixel = srcPixel + srcPixelStride;
                            dstPixel = dstPixel + 1;
                          } while (columnsLeft2 != 0);
                        }
                        rowsLeft = rowsLeft - 1;
                        srcPixel = srcPixel + srcRowPad;
                        dstRow = (uint *)((int)dstRow + iVar21);
                      } while (rowsLeft != 0);
                    }
                    depth = depth - 1;
                    dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
                    srcPixel = srcPixel + srcImagePad;
                  } while (depth != 0);
                }
                goto LAB_0002e240;
              }
            }
          }
          else {
            if (uVar3 == 0x8366) {
              if (0 < (int)depth) {
                do {
                  rowsLeft = height;
                  dstRow = dstSlice;
                  if (0 < (int)height) {
                    do {
                      if (0 < width) {
                        local_90 = float65535;
                        dstPixel = dstRow;
                        columnsLeft2 = width;
                        do {
                          (*extractPixelFunc)(auStack_1b0,srcPixel);
                          (*modifyPixelFunc)(glContext,auStack_1b0);
                          columnsLeft2 = columnsLeft2 + -1;
                          local_c8 = (longlong)(int)(local_1a0 * float65535);
                          local_d0 = (longlong)(int)(local_1ac * float65535);
                          local_d8 = (longlong)(int)(local_1a8 * float65535);
                          local_e0 = (longlong)(int)(local_1a4 * float65535);
                          *(ushort *)dstPixel =
                               (ushort)(int)(local_1a0 * float65535) & 0x8000 |
                               (ushort)((uint)(int)(local_1ac * float65535) >> 1) & 0x7c00 |
                               (ushort)((uint)(int)(local_1a8 * float65535) >> 6) & 0x3e0 |
                               (ushort)((uint)(int)(local_1a4 * float65535) >> 0xb) & 0x1f;
                          dstPixel = (uint *)((int)dstPixel + 2);
                          srcPixel = srcPixel + srcPixelStride;
                        } while (columnsLeft2 != 0);
                      }
                      rowsLeft = rowsLeft - 1;
                      srcPixel = srcPixel + srcRowPad;
                      dstRow = (uint *)((int)dstRow + iVar21);
                    } while (rowsLeft != 0);
                  }
                  depth = depth - 1;
                  dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
                  srcPixel = srcPixel + srcImagePad;
                } while (depth != 0);
              }
              goto LAB_0002e240;
            }
            if (uVar3 < 0x8367) {
              if (uVar3 == 0x8365) {
                if (0 < (int)depth) {
                  do {
                    rowsLeft = height;
                    dstRow = dstSlice;
                    if (0 < (int)height) {
                      do {
                        if (0 < width) {
                          local_90 = float65535;
                          dstPixel = dstRow;
                          columnsLeft2 = width;
                          do {
                            (*extractPixelFunc)(auStack_1b0,srcPixel);
                            (*modifyPixelFunc)(glContext,auStack_1b0);
                            columnsLeft2 = columnsLeft2 + -1;
                            local_c8 = (longlong)(int)(local_1a0 * float65535);
                            local_d0 = (longlong)(int)(local_1ac * float65535);
                            local_d8 = (longlong)(int)(local_1a8 * float65535);
                            local_e0 = (longlong)(int)(local_1a4 * float65535);
                            *(ushort *)dstPixel =
                                 (ushort)(int)(local_1a0 * float65535) & 0xf000 |
                                 (ushort)((uint)(int)(local_1ac * float65535) >> 4) & 0xf00 |
                                 (ushort)((uint)(int)(local_1a8 * float65535) >> 8) & 0xf0 |
                                 (ushort)((uint)(int)(local_1a4 * float65535) >> 0xc) & 0xf;
                            dstPixel = (uint *)((int)dstPixel + 2);
                            srcPixel = srcPixel + srcPixelStride;
                          } while (columnsLeft2 != 0);
                        }
                        rowsLeft = rowsLeft - 1;
                        srcPixel = srcPixel + srcRowPad;
                        dstRow = (uint *)((int)dstRow + iVar21);
                      } while (rowsLeft != 0);
                    }
                    depth = depth - 1;
                    dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
                    srcPixel = srcPixel + srcImagePad;
                  } while (depth != 0);
                }
                goto LAB_0002e240;
              }
            }
            else {
              if (uVar3 == 0x8367) {
                if (0 < (int)depth) {
                  do {
                    rowsLeft = height;
                    dstRow = dstSlice;
                    if (0 < (int)height) {
                      do {
                        twoPow31 = DOUBLE_00108d80;
                        dstPixel = dstRow;
                        columnsLeft2 = width;
                        if (0 < width) {
                          do {
                            (*extractPixelFunc)(auStack_1b0,srcPixel);
                            (*modifyPixelFunc)(glContext,auStack_1b0);
                            scaledComponent = (double)local_1a0 * uint32MaxAsDouble;
                            if (twoPow31 <= scaledComponent) {
                              componentUint = (uint)(int)(scaledComponent - twoPow31);
                              local_d0 = (longlong)(int)componentUint;
                              componentUint = componentUint ^ 0x80000000;
                            }
                            else {
                              componentUint = (uint)(int)scaledComponent;
                              local_c8 = (longlong)(int)componentUint;
                            }
                            scaledComponent = (double)local_1ac * uint32MaxAsDouble;
                            if (DOUBLE_00108d80 <= scaledComponent) {
                              local_e0 = (longlong)(int)(scaledComponent - DOUBLE_00108d80);
                              uVar18 = (int)(scaledComponent - DOUBLE_00108d80) ^ 0x80000000;
                            }
                            else {
                              uVar18 = (uint)(int)scaledComponent;
                              local_d8 = (longlong)(int)uVar18;
                            }
                            scaledComponent = (double)local_1a8 * uint32MaxAsDouble;
                            if (DOUBLE_00108d80 <= scaledComponent) {
                              local_f0 = (longlong)(int)(scaledComponent - DOUBLE_00108d80);
                              uVar12 = (int)(scaledComponent - DOUBLE_00108d80) ^ 0x80000000;
                            }
                            else {
                              uVar12 = (uint)(int)scaledComponent;
                              local_e8 = (longlong)(int)uVar12;
                            }
                            scaledComponent = (double)local_1a4 * uint32MaxAsDouble;
                            if (DOUBLE_00108d80 <= scaledComponent) {
                              local_100 = (longlong)(int)(scaledComponent - DOUBLE_00108d80);
                              uVar13 = (int)(scaledComponent - DOUBLE_00108d80) ^ 0x80000000;
                            }
                            else {
                              uVar13 = (uint)(int)scaledComponent;
                              local_f8 = (longlong)(int)uVar13;
                            }
                            columnsLeft2 = columnsLeft2 + -1;
                            *dstPixel = componentUint & 0xff000000 | uVar18 >> 8 & 0xff0000 |
                                       uVar12 >> 0x10 & 0xff00 | uVar13 >> 0x18;
                            srcPixel = srcPixel + srcPixelStride;
                            dstPixel = dstPixel + 1;
                          } while (columnsLeft2 != 0);
                        }
                        rowsLeft = rowsLeft - 1;
                        srcPixel = srcPixel + srcRowPad;
                        dstRow = (uint *)((int)dstRow + iVar21);
                      } while (rowsLeft != 0);
                    }
                    depth = depth - 1;
                    dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
                    srcPixel = srcPixel + srcImagePad;
                  } while (depth != 0);
                }
                goto LAB_0002e240;
              }
              if (uVar3 == 0x8368) {
                if (0 < (int)depth) {
                  do {
                    rowsLeft = height;
                    dstRow = dstSlice;
                    if (0 < (int)height) {
                      do {
                        twoPow31 = DOUBLE_00108d80;
                        dstPixel = dstRow;
                        columnsLeft2 = width;
                        if (0 < width) {
                          do {
                            (*extractPixelFunc)(auStack_1b0,srcPixel);
                            (*modifyPixelFunc)(glContext,auStack_1b0);
                            scaledComponent = (double)local_1a0 * uint32MaxAsDouble;
                            if (twoPow31 <= scaledComponent) {
                              componentUint = (uint)(int)(scaledComponent - twoPow31);
                              local_d0 = (longlong)(int)componentUint;
                              componentUint = componentUint ^ 0x80000000;
                            }
                            else {
                              componentUint = (uint)(int)scaledComponent;
                              local_c8 = (longlong)(int)componentUint;
                            }
                            scaledComponent = (double)local_1ac * uint32MaxAsDouble;
                            if (DOUBLE_00108d80 <= scaledComponent) {
                              local_e0 = (longlong)(int)(scaledComponent - DOUBLE_00108d80);
                              uVar18 = (int)(scaledComponent - DOUBLE_00108d80) ^ 0x80000000;
                            }
                            else {
                              uVar18 = (uint)(int)scaledComponent;
                              local_d8 = (longlong)(int)uVar18;
                            }
                            scaledComponent = (double)local_1a8 * uint32MaxAsDouble;
                            if (DOUBLE_00108d80 <= scaledComponent) {
                              local_f0 = (longlong)(int)(scaledComponent - DOUBLE_00108d80);
                              uVar12 = (int)(scaledComponent - DOUBLE_00108d80) ^ 0x80000000;
                            }
                            else {
                              uVar12 = (uint)(int)scaledComponent;
                              local_e8 = (longlong)(int)uVar12;
                            }
                            scaledComponent = (double)local_1a4 * uint32MaxAsDouble;
                            if (DOUBLE_00108d80 <= scaledComponent) {
                              local_100 = (longlong)(int)(scaledComponent - DOUBLE_00108d80);
                              uVar13 = (int)(scaledComponent - DOUBLE_00108d80) ^ 0x80000000;
                            }
                            else {
                              uVar13 = (uint)(int)scaledComponent;
                              local_f8 = (longlong)(int)uVar13;
                            }
                            columnsLeft2 = columnsLeft2 + -1;
                            *dstPixel = componentUint & 0xc0000000 | uVar18 >> 2 & 0x3ff00000 |
                                       uVar12 >> 0xc & 0xffc00 | uVar13 >> 0x16;
                            srcPixel = srcPixel + srcPixelStride;
                            dstPixel = dstPixel + 1;
                          } while (columnsLeft2 != 0);
                        }
                        rowsLeft = rowsLeft - 1;
                        srcPixel = srcPixel + srcRowPad;
                        dstRow = (uint *)((int)dstRow + iVar21);
                      } while (rowsLeft != 0);
                    }
                    depth = depth - 1;
                    dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
                    srcPixel = srcPixel + srcImagePad;
                  } while (depth != 0);
                }
                goto LAB_0002e240;
              }
            }
          }
          if (0 < (int)depth) {
            do {
              rowsLeft = height;
              dstRow = dstSlice;
              if (0 < (int)height) {
                do {
                  float255C = FLOAT_00108f70;
                  floatOne2 = FLOAT_00108e54;
                  floatZero = FLOAT_00108e50;
                  columnsLeft = width;
                  dstPixel = dstRow;
                  if (0 < width) {
                    do {
                      local_1ac = floatZero;
                      local_1a8 = floatZero;
                      local_1a4 = floatZero;
                      local_1a0 = floatOne2;
                      (*extractPixelFunc)(auStack_1b0,srcPixel);
                      (*modifyPixelFunc)(glContext,auStack_1b0);
                      if (floatOne2 < local_1a4) {
                        componentByte = 0xff;
                      }
                      else {
                        componentByte = 0;
                        if (!(local_1a4 < floatZero)) {
                          (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)(int)(local_1a4 * float255C);
                          componentByte = (undefined1)local_c8;
                          local_c8 = (longlong)(int)(local_1a4 * float255C);
                        }
                      }
                      *(undefined1 *)dstPixel = componentByte;
                      if (floatOne2 < local_1a8) {
                        componentByte = 0xff;
                      }
                      else {
                        componentByte = 0;
                        if (!(local_1a8 < floatZero)) {
                          (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)(int)(local_1a8 * float255C);
                          componentByte = (undefined1)local_c8;
                          local_c8 = (longlong)(int)(local_1a8 * float255C);
                        }
                      }
                      *(undefined1 *)((int)dstPixel + 1) = componentByte;
                      if (floatOne2 < local_1ac) {
                        componentByte = 0xff;
                      }
                      else {
                        componentByte = 0;
                        if (!(local_1ac < floatZero)) {
                          (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)(int)(local_1ac * float255C);
                          componentByte = (undefined1)local_c8;
                          local_c8 = (longlong)(int)(local_1ac * float255C);
                        }
                      }
                      *(undefined1 *)((int)dstPixel + 2) = componentByte;
                      if (floatOne2 < local_1a0) {
                        componentByte = 0xff;
                      }
                      else {
                        componentByte = 0;
                        if (!(local_1a0 < floatZero)) {
                          (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)(int)(local_1a0 * float255C);
                          componentByte = (undefined1)local_c8;
                          local_c8 = (longlong)(int)(local_1a0 * float255C);
                        }
                      }
                      columnsLeft = columnsLeft + -1;
                      *(undefined1 *)((int)dstPixel + 3) = componentByte;
                      srcPixel = srcPixel + srcPixelStride;
                      dstPixel = (uint *)((int)dstPixel + iVar17);
                    } while (columnsLeft != 0);
                  }
                  rowsLeft = rowsLeft - 1;
                  srcPixel = srcPixel + srcRowPad;
                  dstRow = (uint *)((int)dstRow + iVar21);
                } while (rowsLeft != 0);
              }
              depth = depth - 1;
              dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
              srcPixel = srcPixel + srcImagePad;
            } while (depth != 0);
          }
          goto LAB_0002e240;
        }
        uVar14 = 0x86dc;
      }
      else {
        if (uVar3 == 0x86f5) {
          if (0 < (int)depth) {
            do {
              rowsLeft = height;
              dstRow = dstSlice;
              if (0 < (int)height) {
                do {
                  float127B = FLOAT_00108f6c;
                  floatMinusOne = FLOAT_00108e58;
                  floatOne = FLOAT_00108e54;
                  columnsLeft = width;
                  dstPixel = dstRow;
                  if (0 < width) {
                    do {
                      (*extractPixelFunc)(auStack_1b0,srcPixel);
                      (*modifyPixelFunc)(glContext,auStack_1b0);
                      if (floatOne < local_188) {
                        componentByte = 0x7f;
                      }
                      else {
                        componentByte = 0x81;
                        if (!(local_188 < floatMinusOne)) {
                          scaledInt = (int)(local_188 * float127B);
                          (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)scaledInt;
                          componentByte = (undefined1)local_c8;
                          local_c8 = (longlong)scaledInt;
                        }
                      }
                      *(undefined1 *)dstPixel = componentByte;
                      if (floatOne < local_184) {
                        componentByte = 0x7f;
                      }
                      else {
                        componentByte = 0x81;
                        if (!(local_184 < floatMinusOne)) {
                          scaledInt = (int)(local_184 * float127B);
                          (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)scaledInt;
                          componentByte = (undefined1)local_c8;
                          local_c8 = (longlong)scaledInt;
                        }
                      }
                      columnsLeft = columnsLeft + -1;
                      *(undefined1 *)((int)dstPixel + 1) = componentByte;
                      srcPixel = srcPixel + srcPixelStride;
                      dstPixel = (uint *)((int)dstPixel + iVar17);
                    } while (columnsLeft != 0);
                  }
                  rowsLeft = rowsLeft - 1;
                  srcPixel = srcPixel + srcRowPad;
                  dstRow = (uint *)((int)dstRow + iVar21);
                } while (rowsLeft != 0);
              }
              depth = depth - 1;
              dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
              srcPixel = srcPixel + srcImagePad;
            } while (depth != 0);
          }
          goto LAB_0002e240;
        }
        uVar14 = 0x86f6;
      }
      if (uVar3 == uVar14) {
        if (0 < (int)depth) {
          do {
            dstRow = dstSlice;
            rowsLeft = height;
            if (0 < (int)height) {
              do {
                float255 = FLOAT_00108f70;
                float127 = FLOAT_00108f6c;
                floatMinusOne2 = FLOAT_00108e58;
                floatOne2 = FLOAT_00108e54;
                floatZero = FLOAT_00108e50;
                if (0 < width) {
                  puVar30 = (undefined1 *)((int)dstRow + 3);
                  columnsLeft = width;
                  dstPixel = dstRow;
                  do {
                    (*extractPixelFunc)(auStack_1b0,srcPixel);
                    (*modifyPixelFunc)(glContext,auStack_1b0);
                    if (floatOne2 < local_1ac) {
                      componentByte = 0xff;
                    }
                    else {
                      componentByte = 0;
                      if (!(local_1ac < floatZero)) {
                        scaledInt = (int)(local_1ac * float255);
                        (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)scaledInt;
                        componentByte = (undefined1)local_c8;
                        local_c8 = (longlong)scaledInt;
                      }
                    }
                    *(undefined1 *)dstPixel = componentByte;
                    if (floatOne2 < local_180) {
                      componentByte = 0xff;
                    }
                    else {
                      componentByte = 0;
                      if (!(local_180 < floatZero)) {
                        scaledInt = (int)(local_180 * float255);
                        (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)scaledInt;
                        componentByte = (undefined1)local_c8;
                        local_c8 = (longlong)scaledInt;
                      }
                    }
                    *(undefined1 *)((int)dstPixel + 1) = componentByte;
                    if (floatOne2 < local_184) {
                      componentByte = 0x7f;
                    }
                    else {
                      componentByte = 0x81;
                      if (!(local_184 < floatMinusOne2)) {
                        scaledInt = (int)(local_184 * float127);
                        (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)scaledInt;
                        componentByte = (undefined1)local_c8;
                        local_c8 = (longlong)scaledInt;
                      }
                    }
                    puVar30[-1] = componentByte;
                    if (floatOne2 < local_188) {
                      componentByte = 0x7f;
                    }
                    else {
                      componentByte = 0x81;
                      if (!(local_188 < floatMinusOne2)) {
                        scaledInt = (int)(local_188 * float127);
                        (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)scaledInt;
                        componentByte = (undefined1)local_c8;
                        local_c8 = (longlong)scaledInt;
                      }
                    }
                    columnsLeft = columnsLeft + -1;
                    *puVar30 = componentByte;
                    puVar30 = puVar30 + iVar17;
                    dstPixel = (uint *)((int)dstPixel + iVar17);
                    srcPixel = srcPixel + srcPixelStride;
                  } while (columnsLeft != 0);
                }
                rowsLeft = rowsLeft - 1;
                srcPixel = srcPixel + srcRowPad;
                dstRow = (uint *)((int)dstRow + iVar21);
              } while (rowsLeft != 0);
            }
            depth = depth - 1;
            dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
            srcPixel = srcPixel + srcImagePad;
          } while (depth != 0);
        }
        goto LAB_0002e240;
      }
    }
    if (*(short *)(textureLevel + 0x12) == 0x1400) {
      if (0 < (int)depth) {
        do {
          rowsLeft = height;
          dstRow = dstSlice;
          if (0 < (int)height) {
            do {
              float127B = FLOAT_00108f6c;
              floatMinusOne = FLOAT_00108e58;
              floatOne = FLOAT_00108e54;
              columnsLeft = width;
              dstPixel = dstRow;
              if (0 < width) {
                do {
                  (*extractPixelFunc)(auStack_1b0,srcPixel);
                  _gleModifyPixelSignedRGBA(glContext,auStack_1b0);
                  if (floatOne < local_1ac) {
                    componentByte = 0x7f;
                  }
                  else {
                    componentByte = 0x81;
                    if (!(local_1ac < floatMinusOne)) {
                      (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)(int)(local_1ac * float127B);
                      componentByte = (undefined1)local_c8;
                      local_c8 = (longlong)(int)(local_1ac * float127B);
                    }
                  }
                  columnsLeft = columnsLeft + -1;
                  *(undefined1 *)dstPixel = componentByte;
                  srcPixel = srcPixel + srcPixelStride;
                  dstPixel = (uint *)((int)dstPixel + iVar17);
                } while (columnsLeft != 0);
              }
              rowsLeft = rowsLeft - 1;
              srcPixel = srcPixel + srcRowPad;
              dstRow = (uint *)((int)dstRow + iVar21);
            } while (rowsLeft != 0);
          }
          depth = depth - 1;
          dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
          srcPixel = srcPixel + srcImagePad;
        } while (depth != 0);
      }
    }
    else if (0 < (int)depth) {
      do {
        rowsLeft = height;
        dstRow = dstSlice;
        if (0 < (int)height) {
          do {
            float255C = FLOAT_00108f70;
            floatOne2 = FLOAT_00108e54;
            floatZero = FLOAT_00108e50;
            columnsLeft = width;
            dstPixel = dstRow;
            if (0 < width) {
              do {
                local_1ac = floatOne2;
                (*extractPixelFunc)(auStack_1b0,srcPixel);
                (*modifyPixelFunc)(glContext,auStack_1b0);
                if (floatOne2 < local_1ac) {
                  componentByte = 0xff;
                }
                else {
                  componentByte = 0;
                  if (!(local_1ac < floatZero)) {
                    (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)(int)(local_1ac * float255C);
                    componentByte = (undefined1)local_c8;
                    local_c8 = (longlong)(int)(local_1ac * float255C);
                  }
                }
                columnsLeft = columnsLeft + -1;
                *(undefined1 *)dstPixel = componentByte;
                srcPixel = srcPixel + srcPixelStride;
                dstPixel = (uint *)((int)dstPixel + iVar17);
              } while (columnsLeft != 0);
            }
            rowsLeft = rowsLeft - 1;
            srcPixel = srcPixel + srcRowPad;
            dstRow = (uint *)((int)dstRow + iVar21);
          } while (rowsLeft != 0);
        }
        depth = depth - 1;
        dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
        srcPixel = srcPixel + srcImagePad;
      } while (depth != 0);
    }
    goto LAB_0002e240;
  }
  uVar3 = *(ushort *)(textureLevel + 0x10);
  if (uVar3 == 0x190a) {
    if (*(short *)(textureLevel + 0x12) == 1) {
      if (0 < (int)depth) {
        do {
          rowsLeft = height;
          dstRow = dstSlice;
          if (0 < (int)height) {
            do {
              float127B = FLOAT_00108f6c;
              floatMinusOne = FLOAT_00108e58;
              floatOne = FLOAT_00108e54;
              columnsLeft = width;
              dstPixel = dstRow;
              if (0 < width) {
                do {
                  (*extractPixelFunc)(auStack_1b0,srcPixel);
                  if (floatOne < local_1a0) {
                    componentByte = 0x7f;
                  }
                  else {
                    componentByte = 0x81;
                    if (!(local_1a0 < floatMinusOne)) {
                      scaledInt = (int)(local_1a0 * float127B);
                      (*(unsigned char *)((unsigned char *)&(local_100) + 7)) = (undefined1)scaledInt;
                      componentByte = (undefined1)local_100;
                      local_100 = (longlong)scaledInt;
                    }
                  }
                  *(undefined1 *)dstPixel = componentByte;
                  if (floatOne < local_1ac) {
                    componentByte = 0x7f;
                  }
                  else {
                    componentByte = 0x81;
                    if (!(local_1ac < floatMinusOne)) {
                      scaledInt = (int)(local_1ac * float127B);
                      (*(unsigned char *)((unsigned char *)&(local_100) + 7)) = (undefined1)scaledInt;
                      componentByte = (undefined1)local_100;
                      local_100 = (longlong)scaledInt;
                    }
                  }
                  columnsLeft = columnsLeft + -1;
                  *(undefined1 *)((int)dstPixel + 1) = componentByte;
                  srcPixel = srcPixel + srcPixelStride;
                  dstPixel = (uint *)((int)dstPixel + iVar17);
                } while (columnsLeft != 0);
              }
              rowsLeft = rowsLeft - 1;
              srcPixel = srcPixel + srcRowPad;
              dstRow = (uint *)((int)dstRow + iVar21);
            } while (rowsLeft != 0);
          }
          depth = depth - 1;
          dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
          srcPixel = srcPixel + srcImagePad;
        } while (depth != 0);
      }
    }
    else if (0 < (int)depth) {
      do {
        rowsLeft = height;
        dstRow = dstSlice;
        if (0 < (int)height) {
          do {
            float255C = FLOAT_00108f70;
            floatOne2 = FLOAT_00108e54;
            floatZero = FLOAT_00108e50;
            columnsLeft = width;
            dstPixel = dstRow;
            if (0 < width) {
              do {
                (*extractPixelFunc)(auStack_1b0,srcPixel);
                if (floatOne2 < local_1ac) {
                  componentByte = 0xff;
                }
                else {
                  componentByte = 0;
                  if (!(local_1ac < floatZero)) {
                    scaledInt = (int)(local_1ac * float255C);
                    (*(unsigned char *)((unsigned char *)&(local_100) + 7)) = (undefined1)scaledInt;
                    componentByte = (undefined1)local_100;
                    local_100 = (longlong)scaledInt;
                  }
                }
                *(undefined1 *)dstPixel = componentByte;
                if (floatOne2 < local_1a0) {
                  componentByte = 0xff;
                }
                else {
                  componentByte = 0;
                  if (!(local_1a0 < floatZero)) {
                    scaledInt = (int)(local_1a0 * float255C);
                    (*(unsigned char *)((unsigned char *)&(local_100) + 7)) = (undefined1)scaledInt;
                    componentByte = (undefined1)local_100;
                    local_100 = (longlong)scaledInt;
                  }
                }
                columnsLeft = columnsLeft + -1;
                *(undefined1 *)((int)dstPixel + 1) = componentByte;
                srcPixel = srcPixel + srcPixelStride;
                dstPixel = (uint *)((int)dstPixel + iVar17);
              } while (columnsLeft != 0);
            }
            rowsLeft = rowsLeft - 1;
            srcPixel = srcPixel + srcRowPad;
            dstRow = (uint *)((int)dstRow + iVar21);
          } while (rowsLeft != 0);
        }
        depth = depth - 1;
        dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
        srcPixel = srcPixel + srcImagePad;
      } while (depth != 0);
    }
    goto LAB_0002e240;
  }
  if (uVar3 < 0x190b) {
    if (uVar3 == 0x1907) {
      uVar3 = *(ushort *)(textureLevel + 0x12);
      if (uVar3 == 0x8362) {
        if (0 < (int)depth) {
          do {
            rowsLeft = height;
            dstRow = dstSlice;
            if (0 < (int)height) {
              do {
                float255B = FLOAT_00108f70;
                columnsLeft2 = width;
                dstPixel = dstRow;
                if (0 < width) {
                  do {
                    (*extractPixelFunc)(auStack_1b0,srcPixel);
                    columnsLeft2 = columnsLeft2 + -1;
                    local_f0 = (longlong)(int)(local_1a4 * float255B);
                    local_f8 = (longlong)(int)(local_1a8 * float255B);
                    local_100 = (longlong)(int)(local_1ac * float255B);
                    *(byte *)dstPixel =
                         (byte)(int)(local_1a4 * float255B) & 0xc0 |
                         (byte)((uint)(int)(local_1a8 * float255B) >> 2) & 0x38 |
                         (byte)((uint)(int)(local_1ac * float255B) >> 5) & 7;
                    srcPixel = srcPixel + srcPixelStride;
                    dstPixel = (uint *)((int)dstPixel + 1);
                  } while (columnsLeft2 != 0);
                }
                rowsLeft = rowsLeft - 1;
                srcPixel = srcPixel + srcRowPad;
                dstRow = (uint *)((int)dstRow + iVar21);
              } while (rowsLeft != 0);
            }
            depth = depth - 1;
            dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
            srcPixel = srcPixel + srcImagePad;
          } while (depth != 0);
        }
        goto LAB_0002e240;
      }
      if (uVar3 < 0x8363) {
        if (uVar3 == 8) {
          if (0 < (int)depth) {
            do {
              rowsLeft = height;
              dstRow = dstSlice;
              if (0 < (int)height) {
                do {
                  float127B = FLOAT_00108f6c;
                  floatMinusOne = FLOAT_00108e58;
                  floatOne = FLOAT_00108e54;
                  columnsLeft = width;
                  dstPixel = dstRow;
                  if (0 < width) {
                    do {
                      (*extractPixelFunc)(auStack_1b0,srcPixel);
                      *(undefined1 *)dstPixel = 0x7f;
                      if (floatOne < local_1ac) {
                        componentByte = 0x7f;
                      }
                      else {
                        componentByte = 0x81;
                        if (!(local_1ac < floatMinusOne)) {
                          (*(unsigned char *)((unsigned char *)&(local_f0) + 7)) = (undefined1)(int)(local_1ac * float127B);
                          componentByte = (undefined1)local_f0;
                          local_f0 = (longlong)(int)(local_1ac * float127B);
                        }
                      }
                      *(undefined1 *)((int)dstPixel + 1) = componentByte;
                      if (floatOne < local_1a8) {
                        componentByte = 0x7f;
                      }
                      else {
                        componentByte = 0x81;
                        if (!(local_1a8 < floatMinusOne)) {
                          (*(unsigned char *)((unsigned char *)&(local_f0) + 7)) = (undefined1)(int)(local_1a8 * float127B);
                          componentByte = (undefined1)local_f0;
                          local_f0 = (longlong)(int)(local_1a8 * float127B);
                        }
                      }
                      *(undefined1 *)((int)dstPixel + 2) = componentByte;
                      if (floatOne < local_1a4) {
                        componentByte = 0x7f;
                      }
                      else {
                        componentByte = 0x81;
                        if (!(local_1a4 < floatMinusOne)) {
                          (*(unsigned char *)((unsigned char *)&(local_f0) + 7)) = (undefined1)(int)(local_1a4 * float127B);
                          componentByte = (undefined1)local_f0;
                          local_f0 = (longlong)(int)(local_1a4 * float127B);
                        }
                      }
                      columnsLeft = columnsLeft + -1;
                      *(undefined1 *)((int)dstPixel + 3) = componentByte;
                      srcPixel = srcPixel + srcPixelStride;
                      dstPixel = (uint *)((int)dstPixel + iVar17);
                    } while (columnsLeft != 0);
                  }
                  rowsLeft = rowsLeft - 1;
                  srcPixel = srcPixel + srcRowPad;
                  dstRow = (uint *)((int)dstRow + iVar21);
                } while (rowsLeft != 0);
              }
              depth = depth - 1;
              dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
              srcPixel = srcPixel + srcImagePad;
            } while (depth != 0);
          }
          goto LAB_0002e240;
        }
        if (uVar3 == 0x8032) {
          if (0 < (int)depth) {
            do {
              rowsLeft = height;
              dstRow = dstSlice;
              if (0 < (int)height) {
                do {
                  float255B = FLOAT_00108f70;
                  columnsLeft2 = width;
                  dstPixel = dstRow;
                  if (0 < width) {
                    do {
                      (*extractPixelFunc)(auStack_1b0,srcPixel);
                      columnsLeft2 = columnsLeft2 + -1;
                      local_100 = (longlong)(int)(local_1ac * float255B);
                      local_f8 = (longlong)(int)(local_1a8 * float255B);
                      local_f0 = (longlong)(int)(local_1a4 * float255B);
                      *(byte *)dstPixel =
                           (byte)(int)(local_1ac * float255B) & 0xe0 |
                           (byte)((uint)(int)(local_1a8 * float255B) >> 3) & 0x1c |
                           (byte)((uint)(int)(local_1a4 * float255B) >> 6) & 3;
                      srcPixel = srcPixel + srcPixelStride;
                      dstPixel = (uint *)((int)dstPixel + 1);
                    } while (columnsLeft2 != 0);
                  }
                  rowsLeft = rowsLeft - 1;
                  srcPixel = srcPixel + srcRowPad;
                  dstRow = (uint *)((int)dstRow + iVar21);
                } while (rowsLeft != 0);
              }
              depth = depth - 1;
              dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
              srcPixel = srcPixel + srcImagePad;
            } while (depth != 0);
          }
          goto LAB_0002e240;
        }
      }
      else {
        if (uVar3 == 0x8363) {
          if (0 < (int)depth) {
            do {
              rowsLeft = height;
              dstRow = dstSlice;
              if (0 < (int)height) {
                do {
                  if (0 < width) {
                    local_90 = float65535;
                    dstPixel = dstRow;
                    columnsLeft2 = width;
                    do {
                      (*extractPixelFunc)(auStack_1b0,srcPixel);
                      columnsLeft2 = columnsLeft2 + -1;
                      local_f0 = (longlong)(int)(local_1ac * float65535);
                      local_f8 = (longlong)(int)(local_1a8 * float65535);
                      local_100 = (longlong)(int)(local_1a4 * float65535);
                      *(ushort *)dstPixel =
                           (ushort)(int)(local_1ac * float65535) & 0xf800 |
                           (ushort)((uint)(int)(local_1a8 * float65535) >> 5) & 0x7e0 |
                           (ushort)((uint)(int)(local_1a4 * float65535) >> 0xb) & 0x1f;
                      dstPixel = (uint *)((int)dstPixel + 2);
                      srcPixel = srcPixel + srcPixelStride;
                    } while (columnsLeft2 != 0);
                  }
                  rowsLeft = rowsLeft - 1;
                  srcPixel = srcPixel + srcRowPad;
                  dstRow = (uint *)((int)dstRow + iVar21);
                } while (rowsLeft != 0);
              }
              depth = depth - 1;
              dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
              srcPixel = srcPixel + srcImagePad;
            } while (depth != 0);
          }
          goto LAB_0002e240;
        }
        if (uVar3 == 0x8364) {
          if (0 < (int)depth) {
            do {
              rowsLeft = height;
              dstRow = dstSlice;
              if (0 < (int)height) {
                do {
                  if (0 < width) {
                    local_90 = float65535;
                    dstPixel = dstRow;
                    columnsLeft2 = width;
                    do {
                      (*extractPixelFunc)(auStack_1b0,srcPixel);
                      columnsLeft2 = columnsLeft2 + -1;
                      local_f0 = (longlong)(int)(local_1a4 * float65535);
                      local_f8 = (longlong)(int)(local_1a8 * float65535);
                      local_100 = (longlong)(int)(local_1ac * float65535);
                      *(ushort *)dstPixel =
                           (ushort)(int)(local_1a4 * float65535) & 0xf800 |
                           (ushort)((uint)(int)(local_1a8 * float65535) >> 5) & 0x7e0 |
                           (ushort)((uint)(int)(local_1ac * float65535) >> 0xb) & 0x1f;
                      dstPixel = (uint *)((int)dstPixel + 2);
                      srcPixel = srcPixel + srcPixelStride;
                    } while (columnsLeft2 != 0);
                  }
                  rowsLeft = rowsLeft - 1;
                  srcPixel = srcPixel + srcRowPad;
                  dstRow = (uint *)((int)dstRow + iVar21);
                } while (rowsLeft != 0);
              }
              depth = depth - 1;
              dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
              srcPixel = srcPixel + srcImagePad;
            } while (depth != 0);
          }
          goto LAB_0002e240;
        }
      }
      if (0 < (int)depth) {
        do {
          rowsLeft = height;
          dstRow = dstSlice;
          if (0 < (int)height) {
            do {
              float255C = FLOAT_00108f70;
              floatOne2 = FLOAT_00108e54;
              floatZero = FLOAT_00108e50;
              columnsLeft = width;
              dstPixel = dstRow;
              if (0 < width) {
                do {
                  (*extractPixelFunc)(auStack_1b0,srcPixel);
                  if (floatOne2 < local_1ac) {
                    componentByte = 0xff;
                  }
                  else {
                    componentByte = 0;
                    if (!(local_1ac < floatZero)) {
                      (*(unsigned char *)((unsigned char *)&(local_f0) + 7)) = (undefined1)(int)(local_1ac * float255C);
                      componentByte = (undefined1)local_f0;
                      local_f0 = (longlong)(int)(local_1ac * float255C);
                    }
                  }
                  *(undefined1 *)dstPixel = componentByte;
                  if (floatOne2 < local_1a8) {
                    componentByte = 0xff;
                  }
                  else {
                    componentByte = 0;
                    if (!(local_1a8 < floatZero)) {
                      (*(unsigned char *)((unsigned char *)&(local_f0) + 7)) = (undefined1)(int)(local_1a8 * float255C);
                      componentByte = (undefined1)local_f0;
                      local_f0 = (longlong)(int)(local_1a8 * float255C);
                    }
                  }
                  *(undefined1 *)((int)dstPixel + 1) = componentByte;
                  if (floatOne2 < local_1a4) {
                    componentByte = 0xff;
                  }
                  else {
                    componentByte = 0;
                    if (!(local_1a4 < floatZero)) {
                      (*(unsigned char *)((unsigned char *)&(local_f0) + 7)) = (undefined1)(int)(local_1a4 * float255C);
                      componentByte = (undefined1)local_f0;
                      local_f0 = (longlong)(int)(local_1a4 * float255C);
                    }
                  }
                  columnsLeft = columnsLeft + -1;
                  *(undefined1 *)((int)dstPixel + 2) = componentByte;
                  srcPixel = srcPixel + srcPixelStride;
                  dstPixel = (uint *)((int)dstPixel + iVar17);
                } while (columnsLeft != 0);
              }
              rowsLeft = rowsLeft - 1;
              srcPixel = srcPixel + srcRowPad;
              dstRow = (uint *)((int)dstRow + iVar21);
            } while (rowsLeft != 0);
          }
          depth = depth - 1;
          dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
          srcPixel = srcPixel + srcImagePad;
        } while (depth != 0);
      }
      goto LAB_0002e240;
    }
    if (uVar3 < 0x1908) {
      if (uVar3 == 0x1902) {
        if (*(short *)(textureLevel + 0x12) == 0x1405) {
          if (0 < (int)depth) {
            do {
              rowsLeft = height;
              dstRow = dstSlice;
              if (0 < (int)height) {
                do {
                  twoPow31 = DOUBLE_00108d80;
                  columnsLeft = width;
                  dstPixel = dstRow;
                  if (0 < width) {
                    do {
                      (*extractPixelFunc)(auStack_1b0,srcPixel);
                      scaledComponent = (double)local_19c * uint32MaxAsDouble;
                      if (twoPow31 <= scaledComponent) {
                        componentUint = (uint)(int)(scaledComponent - twoPow31);
                        local_d0 = (longlong)(int)componentUint;
                        componentUint = componentUint ^ 0x80000000;
                      }
                      else {
                        componentUint = (uint)(int)scaledComponent;
                        local_c8 = (longlong)(int)componentUint;
                      }
                      columnsLeft = columnsLeft + -1;
                      *dstPixel = componentUint;
                      srcPixel = srcPixel + srcPixelStride;
                      dstPixel = dstPixel + iVar17;
                    } while (columnsLeft != 0);
                  }
                  rowsLeft = rowsLeft - 1;
                  srcPixel = srcPixel + srcRowPad;
                  dstRow = (uint *)((int)dstRow + iVar21);
                } while (rowsLeft != 0);
              }
              depth = depth - 1;
              dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
              srcPixel = srcPixel + srcImagePad;
            } while (depth != 0);
          }
        }
        else if (0 < (int)depth) {
          do {
            float65535 = FLOAT_00108ea0;
            rowsLeft = height;
            dstRow = dstSlice;
            if (0 < (int)height) {
              do {
                if (0 < width) {
                  local_90 = float65535;
                  columnsLeft = width;
                  dstPixel = dstRow;
                  do {
                    (*extractPixelFunc)(auStack_1b0,srcPixel);
                    columnsLeft = columnsLeft + -1;
                    scaledInt = (int)(local_19c * float65535);
                    local_c8 = (longlong)scaledInt;
                    *(short *)dstPixel = (short)scaledInt;
                    dstPixel = (uint *)((int)dstPixel + iVar17 * 2);
                    srcPixel = srcPixel + srcPixelStride;
                  } while (columnsLeft != 0);
                }
                rowsLeft = rowsLeft - 1;
                srcPixel = srcPixel + srcRowPad;
                dstRow = (uint *)((int)dstRow + iVar21);
              } while (rowsLeft != 0);
            }
            depth = depth - 1;
            dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
            srcPixel = srcPixel + srcImagePad;
          } while (depth != 0);
        }
        goto LAB_0002e240;
      }
      if (uVar3 == 0x1906) {
        if (*(short *)(textureLevel + 0x12) == 0x1400) {
          if (0 < (int)depth) {
            do {
              rowsLeft = height;
              dstRow = dstSlice;
              if (0 < (int)height) {
                do {
                  float255C = FLOAT_00108f70;
                  floatOne2 = FLOAT_00108e54;
                  floatZero = FLOAT_00108e50;
                  columnsLeft = width;
                  dstPixel = dstRow;
                  if (0 < width) {
                    do {
                      (*extractPixelFunc)(auStack_1b0,srcPixel);
                      if (floatOne2 < local_1a0) {
                        componentByte = 0xff;
                      }
                      else {
                        componentByte = 0;
                        if (!(local_1a0 < floatZero)) {
                          (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)(int)(local_1a0 * float255C);
                          componentByte = (undefined1)local_c8;
                          local_c8 = (longlong)(int)(local_1a0 * float255C);
                        }
                      }
                      columnsLeft = columnsLeft + -1;
                      *(undefined1 *)dstPixel = componentByte;
                      srcPixel = srcPixel + srcPixelStride;
                      dstPixel = (uint *)((int)dstPixel + iVar17);
                    } while (columnsLeft != 0);
                  }
                  rowsLeft = rowsLeft - 1;
                  srcPixel = srcPixel + srcRowPad;
                  dstRow = (uint *)((int)dstRow + iVar21);
                } while (rowsLeft != 0);
              }
              depth = depth - 1;
              dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
              srcPixel = srcPixel + srcImagePad;
            } while (depth != 0);
          }
        }
        else if (0 < (int)depth) {
          do {
            rowsLeft = height;
            dstRow = dstSlice;
            if (0 < (int)height) {
              do {
                float255C = FLOAT_00108f70;
                floatOne2 = FLOAT_00108e54;
                floatZero = FLOAT_00108e50;
                columnsLeft = width;
                dstPixel = dstRow;
                if (0 < width) {
                  do {
                    (*extractPixelFunc)(auStack_1b0,srcPixel);
                    if (floatOne2 < local_1a0) {
                      componentByte = 0xff;
                    }
                    else {
                      componentByte = 0;
                      if (!(local_1a0 < floatZero)) {
                        (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)(int)(local_1a0 * float255C);
                        componentByte = (undefined1)local_c8;
                        local_c8 = (longlong)(int)(local_1a0 * float255C);
                      }
                    }
                    columnsLeft = columnsLeft + -1;
                    *(undefined1 *)dstPixel = componentByte;
                    srcPixel = srcPixel + srcPixelStride;
                    dstPixel = (uint *)((int)dstPixel + iVar17);
                  } while (columnsLeft != 0);
                }
                rowsLeft = rowsLeft - 1;
                srcPixel = srcPixel + srcRowPad;
                dstRow = (uint *)((int)dstRow + iVar21);
              } while (rowsLeft != 0);
            }
            depth = depth - 1;
            dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
            srcPixel = srcPixel + srcImagePad;
          } while (depth != 0);
        }
        goto LAB_0002e240;
      }
    }
    else {
      if (uVar3 == 0x1908) {
        uVar3 = *(ushort *)(textureLevel + 0x12);
        if (uVar3 == 0x8035) {
          if (0 < (int)depth) {
            do {
              rowsLeft = height;
              dstRow = dstSlice;
              if (0 < (int)height) {
                do {
                  twoPow31 = DOUBLE_00108d80;
                  dstPixel = dstRow;
                  columnsLeft2 = width;
                  if (0 < width) {
                    do {
                      (*extractPixelFunc)(auStack_1b0,srcPixel);
                      scaledComponent = (double)local_1ac * uint32MaxAsDouble;
                      if (twoPow31 <= scaledComponent) {
                        componentUint = (uint)(int)(scaledComponent - twoPow31);
                        local_f0 = (longlong)(int)componentUint;
                        componentUint = componentUint ^ 0x80000000;
                      }
                      else {
                        componentUint = (uint)(int)scaledComponent;
                        local_e8 = (longlong)(int)componentUint;
                      }
                      scaledComponent = (double)local_1a8 * uint32MaxAsDouble;
                      if (DOUBLE_00108d80 <= scaledComponent) {
                        local_100 = (longlong)(int)(scaledComponent - DOUBLE_00108d80);
                        uVar18 = (int)(scaledComponent - DOUBLE_00108d80) ^ 0x80000000;
                      }
                      else {
                        uVar18 = (uint)(int)scaledComponent;
                        local_f8 = (longlong)(int)uVar18;
                      }
                      scaledComponent = (double)local_1a4 * uint32MaxAsDouble;
                      if (DOUBLE_00108d80 <= scaledComponent) {
                        local_d8 = (longlong)(int)(scaledComponent - DOUBLE_00108d80);
                        uVar12 = (int)(scaledComponent - DOUBLE_00108d80) ^ 0x80000000;
                      }
                      else {
                        uVar12 = (uint)(int)scaledComponent;
                        local_e0 = (longlong)(int)uVar12;
                      }
                      scaledComponent = (double)local_1a0 * uint32MaxAsDouble;
                      if (DOUBLE_00108d80 <= scaledComponent) {
                        local_c8 = (longlong)(int)(scaledComponent - DOUBLE_00108d80);
                        uVar13 = (int)(scaledComponent - DOUBLE_00108d80) ^ 0x80000000;
                      }
                      else {
                        uVar13 = (uint)(int)scaledComponent;
                        local_d0 = (longlong)(int)uVar13;
                      }
                      columnsLeft2 = columnsLeft2 + -1;
                      *dstPixel = componentUint & 0xff000000 | uVar18 >> 8 & 0xff0000 |
                                 uVar12 >> 0x10 & 0xff00 | uVar13 >> 0x18;
                      srcPixel = srcPixel + srcPixelStride;
                      dstPixel = dstPixel + 1;
                    } while (columnsLeft2 != 0);
                  }
                  rowsLeft = rowsLeft - 1;
                  srcPixel = srcPixel + srcRowPad;
                  dstRow = (uint *)((int)dstRow + iVar21);
                } while (rowsLeft != 0);
              }
              depth = depth - 1;
              dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
              srcPixel = srcPixel + srcImagePad;
            } while (depth != 0);
          }
          goto LAB_0002e240;
        }
        if (uVar3 < 0x8036) {
          if (uVar3 == 8) {
            if (0 < (int)depth) {
              do {
                rowsLeft = height;
                dstRow = dstSlice;
                if (0 < (int)height) {
                  do {
                    float127B = FLOAT_00108f6c;
                    floatMinusOne = FLOAT_00108e58;
                    floatOne = FLOAT_00108e54;
                    columnsLeft = width;
                    dstPixel = dstRow;
                    if (0 < width) {
                      do {
                        (*extractPixelFunc)(auStack_1b0,srcPixel);
                        if (floatOne < local_1a0) {
                          componentByte = 0x7f;
                        }
                        else {
                          componentByte = 0x81;
                          if (!(local_1a0 < floatMinusOne)) {
                            (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)(int)(local_1a0 * float127B);
                            componentByte = (undefined1)local_c8;
                            local_c8 = (longlong)(int)(local_1a0 * float127B);
                          }
                        }
                        *(undefined1 *)dstPixel = componentByte;
                        if (floatOne < local_1ac) {
                          componentByte = 0x7f;
                        }
                        else {
                          componentByte = 0x81;
                          if (!(local_1ac < floatMinusOne)) {
                            (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)(int)(local_1ac * float127B);
                            componentByte = (undefined1)local_c8;
                            local_c8 = (longlong)(int)(local_1ac * float127B);
                          }
                        }
                        *(undefined1 *)((int)dstPixel + 1) = componentByte;
                        if (floatOne < local_1a8) {
                          componentByte = 0x7f;
                        }
                        else {
                          componentByte = 0x81;
                          if (!(local_1a8 < floatMinusOne)) {
                            (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)(int)(local_1a8 * float127B);
                            componentByte = (undefined1)local_c8;
                            local_c8 = (longlong)(int)(local_1a8 * float127B);
                          }
                        }
                        *(undefined1 *)((int)dstPixel + 2) = componentByte;
                        if (floatOne < local_1a4) {
                          componentByte = 0x7f;
                        }
                        else {
                          componentByte = 0x81;
                          if (!(local_1a4 < floatMinusOne)) {
                            (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)(int)(local_1a4 * float127B);
                            componentByte = (undefined1)local_c8;
                            local_c8 = (longlong)(int)(local_1a4 * float127B);
                          }
                        }
                        columnsLeft = columnsLeft + -1;
                        *(undefined1 *)((int)dstPixel + 3) = componentByte;
                        srcPixel = srcPixel + srcPixelStride;
                        dstPixel = (uint *)((int)dstPixel + iVar17);
                      } while (columnsLeft != 0);
                    }
                    rowsLeft = rowsLeft - 1;
                    srcPixel = srcPixel + srcRowPad;
                    dstRow = (uint *)((int)dstRow + iVar21);
                  } while (rowsLeft != 0);
                }
                depth = depth - 1;
                dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
                srcPixel = srcPixel + srcImagePad;
              } while (depth != 0);
            }
            goto LAB_0002e240;
          }
          if (uVar3 < 9) {
            if (uVar3 == 7) {
              if (0 < (int)depth) {
                do {
                  rowsLeft = height;
                  dstRow = dstSlice;
                  if (0 < (int)height) {
                    do {
                      float255 = FLOAT_00108f70;
                      float127 = FLOAT_00108f6c;
                      floatMinusOne2 = FLOAT_00108e58;
                      floatOne2 = FLOAT_00108e54;
                      floatZero = FLOAT_00108e50;
                      if (0 < width) {
                        puVar30 = (undefined1 *)((int)dstRow + 3);
                        dstPixel = dstRow;
                        columnsLeft = width;
                        do {
                          (*extractPixelFunc)(auStack_1b0,srcPixel);
                          if (floatOne2 < local_1a0) {
                            componentByte = 0xff;
                          }
                          else {
                            componentByte = 0;
                            if (!(local_1a0 < floatZero)) {
                              (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)(int)(local_1a0 * float255);
                              componentByte = (undefined1)local_c8;
                              local_c8 = (longlong)(int)(local_1a0 * float255);
                            }
                          }
                          *(undefined1 *)dstPixel = componentByte;
                          if (floatOne2 < local_1ac) {
                            componentByte = 0x7f;
                          }
                          else {
                            componentByte = 0x81;
                            if (!(local_1ac < floatMinusOne2)) {
                              (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)(int)(local_1ac * float127);
                              componentByte = (undefined1)local_c8;
                              local_c8 = (longlong)(int)(local_1ac * float127);
                            }
                          }
                          puVar30[-2] = componentByte;
                          if (floatOne2 < local_1a8) {
                            componentByte = 0x7f;
                          }
                          else {
                            componentByte = 0x81;
                            if (!(local_1a8 < floatMinusOne2)) {
                              (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)(int)(local_1a8 * float127);
                              componentByte = (undefined1)local_c8;
                              local_c8 = (longlong)(int)(local_1a8 * float127);
                            }
                          }
                          puVar30[-1] = componentByte;
                          if (floatOne2 < local_1a4) {
                            componentByte = 0x7f;
                          }
                          else {
                            componentByte = 0x81;
                            if (!(local_1a4 < floatMinusOne2)) {
                              (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)(int)(local_1a4 * float127);
                              componentByte = (undefined1)local_c8;
                              local_c8 = (longlong)(int)(local_1a4 * float127);
                            }
                          }
                          columnsLeft = columnsLeft + -1;
                          *puVar30 = componentByte;
                          puVar30 = puVar30 + iVar17;
                          dstPixel = (uint *)((int)dstPixel + iVar17);
                          srcPixel = srcPixel + srcPixelStride;
                        } while (columnsLeft != 0);
                      }
                      rowsLeft = rowsLeft - 1;
                      srcPixel = srcPixel + srcRowPad;
                      dstRow = (uint *)((int)dstRow + iVar21);
                    } while (rowsLeft != 0);
                  }
                  depth = depth - 1;
                  dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
                  srcPixel = srcPixel + srcImagePad;
                } while (depth != 0);
              }
              goto LAB_0002e240;
            }
          }
          else {
            if (uVar3 == 0x8033) {
              if (0 < (int)depth) {
                do {
                  rowsLeft = height;
                  dstRow = dstSlice;
                  if (0 < (int)height) {
                    do {
                      if (0 < width) {
                        local_90 = float65535;
                        columnsLeft2 = width;
                        dstPixel = dstRow;
                        do {
                          (*extractPixelFunc)(auStack_1b0,srcPixel);
                          columnsLeft2 = columnsLeft2 + -1;
                          local_f0 = (longlong)(int)(local_1ac * float65535);
                          local_f8 = (longlong)(int)(local_1a8 * float65535);
                          local_100 = (longlong)(int)(local_1a4 * float65535);
                          local_e8 = (longlong)(int)(local_1a0 * float65535);
                          *(ushort *)dstPixel =
                               (ushort)(int)(local_1ac * float65535) & 0xf000 |
                               (ushort)((uint)(int)(local_1a8 * float65535) >> 4) & 0xf00 |
                               (ushort)((uint)(int)(local_1a4 * float65535) >> 8) & 0xf0 |
                               (ushort)((uint)(int)(local_1a0 * float65535) >> 0xc) & 0xf;
                          dstPixel = (uint *)((int)dstPixel + 2);
                          srcPixel = srcPixel + srcPixelStride;
                        } while (columnsLeft2 != 0);
                      }
                      rowsLeft = rowsLeft - 1;
                      srcPixel = srcPixel + srcRowPad;
                      dstRow = (uint *)((int)dstRow + iVar21);
                    } while (rowsLeft != 0);
                  }
                  depth = depth - 1;
                  dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
                  srcPixel = srcPixel + srcImagePad;
                } while (depth != 0);
              }
              goto LAB_0002e240;
            }
            if (uVar3 == 0x8034) {
              if (0 < (int)depth) {
                do {
                  rowsLeft = height;
                  dstRow = dstSlice;
                  if (0 < (int)height) {
                    do {
                      if (0 < width) {
                        local_90 = float65535;
                        columnsLeft2 = width;
                        dstPixel = dstRow;
                        do {
                          (*extractPixelFunc)(auStack_1b0,srcPixel);
                          columnsLeft2 = columnsLeft2 + -1;
                          local_e8 = (longlong)(int)(local_1ac * float65535);
                          local_f0 = (longlong)(int)(local_1a8 * float65535);
                          local_f8 = (longlong)(int)(local_1a4 * float65535);
                          local_100 = (longlong)(int)(local_1a0 * float65535);
                          *(ushort *)dstPixel =
                               (ushort)(int)(local_1ac * float65535) & 0xf800 |
                               (ushort)((uint)(int)(local_1a8 * float65535) >> 5) & 0x7c0 |
                               (ushort)((uint)(int)(local_1a4 * float65535) >> 10) & 0x3e |
                               (ushort)((uint)(int)(local_1a0 * float65535) >> 0xf) & 1;
                          dstPixel = (uint *)((int)dstPixel + 2);
                          srcPixel = srcPixel + srcPixelStride;
                        } while (columnsLeft2 != 0);
                      }
                      rowsLeft = rowsLeft - 1;
                      srcPixel = srcPixel + srcRowPad;
                      dstRow = (uint *)((int)dstRow + iVar21);
                    } while (rowsLeft != 0);
                  }
                  depth = depth - 1;
                  dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
                  srcPixel = srcPixel + srcImagePad;
                } while (depth != 0);
              }
              goto LAB_0002e240;
            }
          }
        }
        else {
          if (uVar3 == 0x8366) {
            if (0 < (int)depth) {
              do {
                rowsLeft = height;
                dstRow = dstSlice;
                if (0 < (int)height) {
                  do {
                    if (0 < width) {
                      local_90 = float65535;
                      columnsLeft2 = width;
                      dstPixel = dstRow;
                      do {
                        (*extractPixelFunc)(auStack_1b0,srcPixel);
                        columnsLeft2 = columnsLeft2 + -1;
                        local_e8 = (longlong)(int)(local_1a0 * float65535);
                        local_f0 = (longlong)(int)(local_1a4 * float65535);
                        local_f8 = (longlong)(int)(local_1a8 * float65535);
                        local_100 = (longlong)(int)(local_1ac * float65535);
                        *(ushort *)dstPixel =
                             (ushort)(int)(local_1a0 * float65535) & 0x8000 |
                             (ushort)((uint)(int)(local_1a4 * float65535) >> 1) & 0x7c00 |
                             (ushort)((uint)(int)(local_1a8 * float65535) >> 6) & 0x3e0 |
                             (ushort)((uint)(int)(local_1ac * float65535) >> 0xb) & 0x1f;
                        dstPixel = (uint *)((int)dstPixel + 2);
                        srcPixel = srcPixel + srcPixelStride;
                      } while (columnsLeft2 != 0);
                    }
                    rowsLeft = rowsLeft - 1;
                    srcPixel = srcPixel + srcRowPad;
                    dstRow = (uint *)((int)dstRow + iVar21);
                  } while (rowsLeft != 0);
                }
                depth = depth - 1;
                dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
                srcPixel = srcPixel + srcImagePad;
              } while (depth != 0);
            }
            goto LAB_0002e240;
          }
          if (uVar3 < 0x8367) {
            if (uVar3 == 0x8036) {
              if (0 < (int)depth) {
                do {
                  rowsLeft = height;
                  dstRow = dstSlice;
                  if (0 < (int)height) {
                    do {
                      twoPow31 = DOUBLE_00108d80;
                      dstPixel = dstRow;
                      columnsLeft2 = width;
                      if (0 < width) {
                        do {
                          (*extractPixelFunc)(auStack_1b0,srcPixel);
                          scaledComponent = (double)local_1ac * uint32MaxAsDouble;
                          if (twoPow31 <= scaledComponent) {
                            componentUint = (uint)(int)(scaledComponent - twoPow31);
                            local_d0 = (longlong)(int)componentUint;
                            componentUint = componentUint ^ 0x80000000;
                          }
                          else {
                            componentUint = (uint)(int)scaledComponent;
                            local_c8 = (longlong)(int)componentUint;
                          }
                          scaledComponent = (double)local_1a8 * uint32MaxAsDouble;
                          if (DOUBLE_00108d80 <= scaledComponent) {
                            local_e0 = (longlong)(int)(scaledComponent - DOUBLE_00108d80);
                            uVar18 = (int)(scaledComponent - DOUBLE_00108d80) ^ 0x80000000;
                          }
                          else {
                            uVar18 = (uint)(int)scaledComponent;
                            local_d8 = (longlong)(int)uVar18;
                          }
                          scaledComponent = (double)local_1a4 * uint32MaxAsDouble;
                          if (DOUBLE_00108d80 <= scaledComponent) {
                            local_f0 = (longlong)(int)(scaledComponent - DOUBLE_00108d80);
                            uVar12 = (int)(scaledComponent - DOUBLE_00108d80) ^ 0x80000000;
                          }
                          else {
                            uVar12 = (uint)(int)scaledComponent;
                            local_e8 = (longlong)(int)uVar12;
                          }
                          scaledComponent = (double)local_1a0 * uint32MaxAsDouble;
                          if (DOUBLE_00108d80 <= scaledComponent) {
                            local_100 = (longlong)(int)(scaledComponent - DOUBLE_00108d80);
                            uVar13 = (int)(scaledComponent - DOUBLE_00108d80) ^ 0x80000000;
                          }
                          else {
                            uVar13 = (uint)(int)scaledComponent;
                            local_f8 = (longlong)(int)uVar13;
                          }
                          columnsLeft2 = columnsLeft2 + -1;
                          *dstPixel = componentUint & 0xffc00000 | uVar18 >> 10 & 0x3ff000 |
                                     uVar12 >> 0x14 & 0xffc | uVar13 >> 0x1e;
                          srcPixel = srcPixel + srcPixelStride;
                          dstPixel = dstPixel + 1;
                        } while (columnsLeft2 != 0);
                      }
                      rowsLeft = rowsLeft - 1;
                      srcPixel = srcPixel + srcRowPad;
                      dstRow = (uint *)((int)dstRow + iVar21);
                    } while (rowsLeft != 0);
                  }
                  depth = depth - 1;
                  dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
                  srcPixel = srcPixel + srcImagePad;
                } while (depth != 0);
              }
              goto LAB_0002e240;
            }
            if (uVar3 == 0x8365) {
              if (0 < (int)depth) {
                do {
                  rowsLeft = height;
                  dstRow = dstSlice;
                  if (0 < (int)height) {
                    do {
                      if (0 < width) {
                        local_90 = float65535;
                        columnsLeft2 = width;
                        dstPixel = dstRow;
                        do {
                          (*extractPixelFunc)(auStack_1b0,srcPixel);
                          columnsLeft2 = columnsLeft2 + -1;
                          local_e8 = (longlong)(int)(local_1a0 * float65535);
                          local_f0 = (longlong)(int)(local_1a4 * float65535);
                          local_f8 = (longlong)(int)(local_1a8 * float65535);
                          local_100 = (longlong)(int)(local_1ac * float65535);
                          *(ushort *)dstPixel =
                               (ushort)(int)(local_1a0 * float65535) & 0xf000 |
                               (ushort)((uint)(int)(local_1a4 * float65535) >> 4) & 0xf00 |
                               (ushort)((uint)(int)(local_1a8 * float65535) >> 8) & 0xf0 |
                               (ushort)((uint)(int)(local_1ac * float65535) >> 0xc) & 0xf;
                          dstPixel = (uint *)((int)dstPixel + 2);
                          srcPixel = srcPixel + srcPixelStride;
                        } while (columnsLeft2 != 0);
                      }
                      rowsLeft = rowsLeft - 1;
                      srcPixel = srcPixel + srcRowPad;
                      dstRow = (uint *)((int)dstRow + iVar21);
                    } while (rowsLeft != 0);
                  }
                  depth = depth - 1;
                  dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
                  srcPixel = srcPixel + srcImagePad;
                } while (depth != 0);
              }
              goto LAB_0002e240;
            }
          }
          else {
            if (uVar3 == 0x8367) {
              if (0 < (int)depth) {
                do {
                  rowsLeft = height;
                  dstRow = dstSlice;
                  if (0 < (int)height) {
                    do {
                      twoPow31 = DOUBLE_00108d80;
                      dstPixel = dstRow;
                      columnsLeft2 = width;
                      if (0 < width) {
                        do {
                          (*extractPixelFunc)(auStack_1b0,srcPixel);
                          scaledComponent = (double)local_1a0 * uint32MaxAsDouble;
                          if (twoPow31 <= scaledComponent) {
                            componentUint = (uint)(int)(scaledComponent - twoPow31);
                            local_d0 = (longlong)(int)componentUint;
                            componentUint = componentUint ^ 0x80000000;
                          }
                          else {
                            componentUint = (uint)(int)scaledComponent;
                            local_c8 = (longlong)(int)componentUint;
                          }
                          scaledComponent = (double)local_1a4 * uint32MaxAsDouble;
                          if (DOUBLE_00108d80 <= scaledComponent) {
                            local_e0 = (longlong)(int)(scaledComponent - DOUBLE_00108d80);
                            uVar18 = (int)(scaledComponent - DOUBLE_00108d80) ^ 0x80000000;
                          }
                          else {
                            uVar18 = (uint)(int)scaledComponent;
                            local_d8 = (longlong)(int)uVar18;
                          }
                          scaledComponent = (double)local_1a8 * uint32MaxAsDouble;
                          if (DOUBLE_00108d80 <= scaledComponent) {
                            local_f0 = (longlong)(int)(scaledComponent - DOUBLE_00108d80);
                            uVar12 = (int)(scaledComponent - DOUBLE_00108d80) ^ 0x80000000;
                          }
                          else {
                            uVar12 = (uint)(int)scaledComponent;
                            local_e8 = (longlong)(int)uVar12;
                          }
                          scaledComponent = (double)local_1ac * uint32MaxAsDouble;
                          if (DOUBLE_00108d80 <= scaledComponent) {
                            local_100 = (longlong)(int)(scaledComponent - DOUBLE_00108d80);
                            uVar13 = (int)(scaledComponent - DOUBLE_00108d80) ^ 0x80000000;
                          }
                          else {
                            uVar13 = (uint)(int)scaledComponent;
                            local_f8 = (longlong)(int)uVar13;
                          }
                          columnsLeft2 = columnsLeft2 + -1;
                          *dstPixel = componentUint & 0xff000000 | uVar18 >> 8 & 0xff0000 |
                                     uVar12 >> 0x10 & 0xff00 | uVar13 >> 0x18;
                          srcPixel = srcPixel + srcPixelStride;
                          dstPixel = dstPixel + 1;
                        } while (columnsLeft2 != 0);
                      }
                      rowsLeft = rowsLeft - 1;
                      srcPixel = srcPixel + srcRowPad;
                      dstRow = (uint *)((int)dstRow + iVar21);
                    } while (rowsLeft != 0);
                  }
                  depth = depth - 1;
                  dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
                  srcPixel = srcPixel + srcImagePad;
                } while (depth != 0);
              }
              goto LAB_0002e240;
            }
            if (uVar3 == 0x8368) {
              if (0 < (int)depth) {
                do {
                  rowsLeft = height;
                  dstRow = dstSlice;
                  if (0 < (int)height) {
                    do {
                      twoPow31 = DOUBLE_00108d80;
                      dstPixel = dstRow;
                      columnsLeft2 = width;
                      if (0 < width) {
                        do {
                          (*extractPixelFunc)(auStack_1b0,srcPixel);
                          scaledComponent = (double)local_1a0 * uint32MaxAsDouble;
                          if (twoPow31 <= scaledComponent) {
                            componentUint = (uint)(int)(scaledComponent - twoPow31);
                            local_d0 = (longlong)(int)componentUint;
                            componentUint = componentUint ^ 0x80000000;
                          }
                          else {
                            componentUint = (uint)(int)scaledComponent;
                            local_c8 = (longlong)(int)componentUint;
                          }
                          scaledComponent = (double)local_1a4 * uint32MaxAsDouble;
                          if (DOUBLE_00108d80 <= scaledComponent) {
                            local_e0 = (longlong)(int)(scaledComponent - DOUBLE_00108d80);
                            uVar18 = (int)(scaledComponent - DOUBLE_00108d80) ^ 0x80000000;
                          }
                          else {
                            uVar18 = (uint)(int)scaledComponent;
                            local_d8 = (longlong)(int)uVar18;
                          }
                          scaledComponent = (double)local_1a8 * uint32MaxAsDouble;
                          if (DOUBLE_00108d80 <= scaledComponent) {
                            local_f0 = (longlong)(int)(scaledComponent - DOUBLE_00108d80);
                            uVar12 = (int)(scaledComponent - DOUBLE_00108d80) ^ 0x80000000;
                          }
                          else {
                            uVar12 = (uint)(int)scaledComponent;
                            local_e8 = (longlong)(int)uVar12;
                          }
                          scaledComponent = (double)local_1ac * uint32MaxAsDouble;
                          if (DOUBLE_00108d80 <= scaledComponent) {
                            local_100 = (longlong)(int)(scaledComponent - DOUBLE_00108d80);
                            uVar13 = (int)(scaledComponent - DOUBLE_00108d80) ^ 0x80000000;
                          }
                          else {
                            uVar13 = (uint)(int)scaledComponent;
                            local_f8 = (longlong)(int)uVar13;
                          }
                          columnsLeft2 = columnsLeft2 + -1;
                          *dstPixel = componentUint & 0xc0000000 | uVar18 >> 2 & 0x3ff00000 |
                                     uVar12 >> 0xc & 0xffc00 | uVar13 >> 0x16;
                          srcPixel = srcPixel + srcPixelStride;
                          dstPixel = dstPixel + 1;
                        } while (columnsLeft2 != 0);
                      }
                      rowsLeft = rowsLeft - 1;
                      srcPixel = srcPixel + srcRowPad;
                      dstRow = (uint *)((int)dstRow + iVar21);
                    } while (rowsLeft != 0);
                  }
                  depth = depth - 1;
                  dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
                  srcPixel = srcPixel + srcImagePad;
                } while (depth != 0);
              }
              goto LAB_0002e240;
            }
          }
        }
        if (0 < (int)depth) {
          do {
            rowsLeft = height;
            dstRow = dstSlice;
            if (0 < (int)height) {
              do {
                float255C = FLOAT_00108f70;
                floatOne2 = FLOAT_00108e54;
                floatZero = FLOAT_00108e50;
                columnsLeft = width;
                dstPixel = dstRow;
                if (0 < width) {
                  do {
                    (*extractPixelFunc)(auStack_1b0,srcPixel);
                    if (floatOne2 < local_1ac) {
                      componentByte = 0xff;
                    }
                    else {
                      componentByte = 0;
                      if (!(local_1ac < floatZero)) {
                        (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)(int)(local_1ac * float255C);
                        componentByte = (undefined1)local_c8;
                        local_c8 = (longlong)(int)(local_1ac * float255C);
                      }
                    }
                    *(undefined1 *)dstPixel = componentByte;
                    if (floatOne2 < local_1a8) {
                      componentByte = 0xff;
                    }
                    else {
                      componentByte = 0;
                      if (!(local_1a8 < floatZero)) {
                        (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)(int)(local_1a8 * float255C);
                        componentByte = (undefined1)local_c8;
                        local_c8 = (longlong)(int)(local_1a8 * float255C);
                      }
                    }
                    *(undefined1 *)((int)dstPixel + 1) = componentByte;
                    if (floatOne2 < local_1a4) {
                      componentByte = 0xff;
                    }
                    else {
                      componentByte = 0;
                      if (!(local_1a4 < floatZero)) {
                        (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)(int)(local_1a4 * float255C);
                        componentByte = (undefined1)local_c8;
                        local_c8 = (longlong)(int)(local_1a4 * float255C);
                      }
                    }
                    *(undefined1 *)((int)dstPixel + 2) = componentByte;
                    if (floatOne2 < local_1a0) {
                      componentByte = 0xff;
                    }
                    else {
                      componentByte = 0;
                      if (!(local_1a0 < floatZero)) {
                        (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)(int)(local_1a0 * float255C);
                        componentByte = (undefined1)local_c8;
                        local_c8 = (longlong)(int)(local_1a0 * float255C);
                      }
                    }
                    columnsLeft = columnsLeft + -1;
                    *(undefined1 *)((int)dstPixel + 3) = componentByte;
                    srcPixel = srcPixel + srcPixelStride;
                    dstPixel = (uint *)((int)dstPixel + iVar17);
                  } while (columnsLeft != 0);
                }
                rowsLeft = rowsLeft - 1;
                srcPixel = srcPixel + srcRowPad;
                dstRow = (uint *)((int)dstRow + iVar21);
              } while (rowsLeft != 0);
            }
            depth = depth - 1;
            dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
            srcPixel = srcPixel + srcImagePad;
          } while (depth != 0);
        }
        goto LAB_0002e240;
      }
      if (uVar3 == 0x1909) {
        if (*(short *)(textureLevel + 0x12) == 0x1400) {
          if (0 < (int)depth) {
            do {
              rowsLeft = height;
              dstRow = dstSlice;
              if (0 < (int)height) {
                do {
                  float127B = FLOAT_00108f6c;
                  floatMinusOne = FLOAT_00108e58;
                  floatOne = FLOAT_00108e54;
                  columnsLeft = width;
                  dstPixel = dstRow;
                  if (0 < width) {
                    do {
                      (*extractPixelFunc)(auStack_1b0,srcPixel);
                      if (floatOne < local_1ac) {
                        componentByte = 0x7f;
                      }
                      else {
                        componentByte = 0x81;
                        if (!(local_1ac < floatMinusOne)) {
                          (*(unsigned char *)((unsigned char *)&(local_100) + 7)) = (undefined1)(int)(local_1ac * float127B);
                          componentByte = (undefined1)local_100;
                          local_100 = (longlong)(int)(local_1ac * float127B);
                        }
                      }
                      columnsLeft = columnsLeft + -1;
                      *(undefined1 *)dstPixel = componentByte;
                      srcPixel = srcPixel + srcPixelStride;
                      dstPixel = (uint *)((int)dstPixel + iVar17);
                    } while (columnsLeft != 0);
                  }
                  rowsLeft = rowsLeft - 1;
                  srcPixel = srcPixel + srcRowPad;
                  dstRow = (uint *)((int)dstRow + iVar21);
                } while (rowsLeft != 0);
              }
              depth = depth - 1;
              dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
              srcPixel = srcPixel + srcImagePad;
            } while (depth != 0);
          }
        }
        else if (0 < (int)depth) {
          do {
            rowsLeft = height;
            dstRow = dstSlice;
            if (0 < (int)height) {
              do {
                float255C = FLOAT_00108f70;
                floatOne2 = FLOAT_00108e54;
                floatZero = FLOAT_00108e50;
                columnsLeft = width;
                dstPixel = dstRow;
                if (0 < width) {
                  do {
                    (*extractPixelFunc)(auStack_1b0,srcPixel);
                    if (floatOne2 < local_1ac) {
                      componentByte = 0xff;
                    }
                    else {
                      componentByte = 0;
                      if (!(local_1ac < floatZero)) {
                        (*(unsigned char *)((unsigned char *)&(local_100) + 7)) = (undefined1)(int)(local_1ac * float255C);
                        componentByte = (undefined1)local_100;
                        local_100 = (longlong)(int)(local_1ac * float255C);
                      }
                    }
                    columnsLeft = columnsLeft + -1;
                    *(undefined1 *)dstPixel = componentByte;
                    srcPixel = srcPixel + srcPixelStride;
                    dstPixel = (uint *)((int)dstPixel + iVar17);
                  } while (columnsLeft != 0);
                }
                rowsLeft = rowsLeft - 1;
                srcPixel = srcPixel + srcRowPad;
                dstRow = (uint *)((int)dstRow + iVar21);
              } while (rowsLeft != 0);
            }
            depth = depth - 1;
            dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
            srcPixel = srcPixel + srcImagePad;
          } while (depth != 0);
        }
        goto LAB_0002e240;
      }
    }
  }
  else {
    if (uVar3 == 0x86f4) {
      uVar3 = *(ushort *)(textureLevel + 0x12);
      if (uVar3 == 6) {
        if (0 < (int)depth) {
          do {
            float32767 = FLOAT_00108f74;
            rowsLeft = height;
            dstRow = dstSlice;
            if (0 < (int)height) {
              do {
                floatMinusOne2 = FLOAT_00108e58;
                floatOne2 = FLOAT_00108e54;
                if (0 < width) {
                  local_90 = float32767;
                  columnsLeft = width;
                  dstPixel = dstRow;
                  do {
                    (*extractPixelFunc)(auStack_1b0,srcPixel);
                    if (floatOne2 < local_190) {
                      componentShort = 0x7fff;
                    }
                    else {
                      componentShort = 0x8001;
                      if (!(local_190 < floatMinusOne2)) {
                        (*(unsigned short *)((unsigned char *)&(local_c8) + 6)) = (undefined2)(int)(local_190 * float32767);
                        componentShort = (*(unsigned short *)((unsigned char *)&(local_c8) + 6));
                        local_c8 = (longlong)(int)(local_190 * float32767);
                      }
                    }
                    *(undefined2 *)dstPixel = componentShort;
                    if (floatOne2 < local_18c) {
                      componentShort = 0x7fff;
                    }
                    else {
                      componentShort = 0x8001;
                      if (!(local_18c < floatMinusOne2)) {
                        (*(unsigned short *)((unsigned char *)&(local_c8) + 6)) = (undefined2)(int)(local_18c * float32767);
                        componentShort = (*(unsigned short *)((unsigned char *)&(local_c8) + 6));
                        local_c8 = (longlong)(int)(local_18c * float32767);
                      }
                    }
                    columnsLeft = columnsLeft + -1;
                    *(undefined2 *)((int)dstPixel + 2) = componentShort;
                    dstPixel = (uint *)((int)dstPixel + iVar17 * 2);
                    srcPixel = srcPixel + srcPixelStride;
                  } while (columnsLeft != 0);
                }
                rowsLeft = rowsLeft - 1;
                srcPixel = srcPixel + srcRowPad;
                dstRow = (uint *)((int)dstRow + iVar21);
              } while (rowsLeft != 0);
            }
            depth = depth - 1;
            dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
            srcPixel = srcPixel + srcImagePad;
          } while (depth != 0);
        }
      }
      else if (uVar3 < 7) {
        if ((uVar3 == 5) && (0 < (int)depth)) {
          do {
            float65535 = FLOAT_00108ea0;
            rowsLeft = height;
            dstRow = dstSlice;
            if (0 < (int)height) {
              do {
                floatOne3 = FLOAT_00108e54;
                floatZero2 = FLOAT_00108e50;
                if (0 < width) {
                  local_90 = float65535;
                  columnsLeft = width;
                  dstPixel = dstRow;
                  do {
                    (*extractPixelFunc)(auStack_1b0,srcPixel);
                    if (floatOne3 < local_190) {
                      componentShort = 0xffff;
                    }
                    else {
                      componentShort = 0;
                      if (!(local_190 < floatZero2)) {
                        (*(unsigned short *)((unsigned char *)&(local_c8) + 6)) = (undefined2)(int)(local_190 * float65535);
                        componentShort = (*(unsigned short *)((unsigned char *)&(local_c8) + 6));
                        local_c8 = (longlong)(int)(local_190 * float65535);
                      }
                    }
                    *(undefined2 *)dstPixel = componentShort;
                    if (floatOne3 < local_18c) {
                      componentShort = 0xffff;
                    }
                    else {
                      componentShort = 0;
                      if (!(local_18c < floatZero2)) {
                        (*(unsigned short *)((unsigned char *)&(local_c8) + 6)) = (undefined2)(int)(local_18c * float65535);
                        componentShort = (*(unsigned short *)((unsigned char *)&(local_c8) + 6));
                        local_c8 = (longlong)(int)(local_18c * float65535);
                      }
                    }
                    columnsLeft = columnsLeft + -1;
                    *(undefined2 *)((int)dstPixel + 2) = componentShort;
                    dstPixel = (uint *)((int)dstPixel + iVar17 * 2);
                    srcPixel = srcPixel + srcPixelStride;
                  } while (columnsLeft != 0);
                }
                rowsLeft = rowsLeft - 1;
                srcPixel = srcPixel + srcRowPad;
                dstRow = (uint *)((int)dstRow + iVar21);
              } while (rowsLeft != 0);
            }
            depth = depth - 1;
            dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
            srcPixel = srcPixel + srcImagePad;
          } while (depth != 0);
        }
      }
      else if (uVar3 == 0x1400) {
        if (0 < (int)depth) {
          do {
            rowsLeft = height;
            dstRow = dstSlice;
            if (0 < (int)height) {
              do {
                float127B = FLOAT_00108f6c;
                floatMinusOne = FLOAT_00108e58;
                floatOne = FLOAT_00108e54;
                columnsLeft = width;
                dstPixel = dstRow;
                if (0 < width) {
                  do {
                    (*extractPixelFunc)(auStack_1b0,srcPixel);
                    if (floatOne < local_190) {
                      componentByte = 0x7f;
                    }
                    else {
                      componentByte = 0x81;
                      if (!(local_190 < floatMinusOne)) {
                        scaledInt = (int)(local_190 * float127B);
                        (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)scaledInt;
                        componentByte = (undefined1)local_c8;
                        local_c8 = (longlong)scaledInt;
                      }
                    }
                    *(undefined1 *)dstPixel = componentByte;
                    if (floatOne < local_18c) {
                      componentByte = 0x7f;
                    }
                    else {
                      componentByte = 0x81;
                      if (!(local_18c < floatMinusOne)) {
                        scaledInt = (int)(local_18c * float127B);
                        (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)scaledInt;
                        componentByte = (undefined1)local_c8;
                        local_c8 = (longlong)scaledInt;
                      }
                    }
                    columnsLeft = columnsLeft + -1;
                    *(undefined1 *)((int)dstPixel + 1) = componentByte;
                    srcPixel = srcPixel + srcPixelStride;
                    dstPixel = (uint *)((int)dstPixel + iVar17);
                  } while (columnsLeft != 0);
                }
                rowsLeft = rowsLeft - 1;
                srcPixel = srcPixel + srcRowPad;
                dstRow = (uint *)((int)dstRow + iVar21);
              } while (rowsLeft != 0);
            }
            depth = depth - 1;
            dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
            srcPixel = srcPixel + srcImagePad;
          } while (depth != 0);
        }
      }
      else if ((uVar3 == 0x1401) && (0 < (int)depth)) {
        do {
          rowsLeft = height;
          dstRow = dstSlice;
          if (0 < (int)height) {
            do {
              float255C = FLOAT_00108f70;
              floatOne2 = FLOAT_00108e54;
              floatZero = FLOAT_00108e50;
              columnsLeft = width;
              dstPixel = dstRow;
              if (0 < width) {
                do {
                  (*extractPixelFunc)(auStack_1b0,srcPixel);
                  if (floatOne2 < local_190) {
                    componentByte = 0xff;
                  }
                  else {
                    componentByte = 0;
                    if (!(local_190 < floatZero)) {
                      scaledInt = (int)(local_190 * float255C);
                      (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)scaledInt;
                      componentByte = (undefined1)local_c8;
                      local_c8 = (longlong)scaledInt;
                    }
                  }
                  *(undefined1 *)dstPixel = componentByte;
                  if (floatOne2 < local_18c) {
                    componentByte = 0xff;
                  }
                  else {
                    componentByte = 0;
                    if (!(local_18c < floatZero)) {
                      scaledInt = (int)(local_18c * float255C);
                      (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)scaledInt;
                      componentByte = (undefined1)local_c8;
                      local_c8 = (longlong)scaledInt;
                    }
                  }
                  columnsLeft = columnsLeft + -1;
                  *(undefined1 *)((int)dstPixel + 1) = componentByte;
                  srcPixel = srcPixel + srcPixelStride;
                  dstPixel = (uint *)((int)dstPixel + iVar17);
                } while (columnsLeft != 0);
              }
              rowsLeft = rowsLeft - 1;
              srcPixel = srcPixel + srcRowPad;
              dstRow = (uint *)((int)dstRow + iVar21);
            } while (rowsLeft != 0);
          }
          depth = depth - 1;
          dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
          srcPixel = srcPixel + srcImagePad;
        } while (depth != 0);
      }
      goto LAB_0002e240;
    }
    if (uVar3 < 0x86f5) {
      if (uVar3 == 0x80e1) {
        uVar3 = *(ushort *)(textureLevel + 0x12);
        if (uVar3 == 0x8036) {
          if (0 < (int)depth) {
            do {
              rowsLeft = height;
              dstRow = dstSlice;
              if (0 < (int)height) {
                do {
                  twoPow31 = DOUBLE_00108d80;
                  dstPixel = dstRow;
                  columnsLeft2 = width;
                  if (0 < width) {
                    do {
                      (*extractPixelFunc)(auStack_1b0,srcPixel);
                      scaledComponent = (double)local_1a4 * uint32MaxAsDouble;
                      if (twoPow31 <= scaledComponent) {
                        componentUint = (uint)(int)(scaledComponent - twoPow31);
                        local_d0 = (longlong)(int)componentUint;
                        componentUint = componentUint ^ 0x80000000;
                      }
                      else {
                        componentUint = (uint)(int)scaledComponent;
                        local_c8 = (longlong)(int)componentUint;
                      }
                      scaledComponent = (double)local_1a8 * uint32MaxAsDouble;
                      if (DOUBLE_00108d80 <= scaledComponent) {
                        local_e0 = (longlong)(int)(scaledComponent - DOUBLE_00108d80);
                        uVar18 = (int)(scaledComponent - DOUBLE_00108d80) ^ 0x80000000;
                      }
                      else {
                        uVar18 = (uint)(int)scaledComponent;
                        local_d8 = (longlong)(int)uVar18;
                      }
                      scaledComponent = (double)local_1ac * uint32MaxAsDouble;
                      if (DOUBLE_00108d80 <= scaledComponent) {
                        local_f0 = (longlong)(int)(scaledComponent - DOUBLE_00108d80);
                        uVar12 = (int)(scaledComponent - DOUBLE_00108d80) ^ 0x80000000;
                      }
                      else {
                        uVar12 = (uint)(int)scaledComponent;
                        local_e8 = (longlong)(int)uVar12;
                      }
                      scaledComponent = (double)local_1a0 * uint32MaxAsDouble;
                      if (DOUBLE_00108d80 <= scaledComponent) {
                        local_100 = (longlong)(int)(scaledComponent - DOUBLE_00108d80);
                        uVar13 = (int)(scaledComponent - DOUBLE_00108d80) ^ 0x80000000;
                      }
                      else {
                        uVar13 = (uint)(int)scaledComponent;
                        local_f8 = (longlong)(int)uVar13;
                      }
                      columnsLeft2 = columnsLeft2 + -1;
                      *dstPixel = componentUint & 0xffc00000 | uVar18 >> 10 & 0x3ff000 |
                                 uVar12 >> 0x14 & 0xffc | uVar13 >> 0x1e;
                      srcPixel = srcPixel + srcPixelStride;
                      dstPixel = dstPixel + 1;
                    } while (columnsLeft2 != 0);
                  }
                  rowsLeft = rowsLeft - 1;
                  srcPixel = srcPixel + srcRowPad;
                  dstRow = (uint *)((int)dstRow + iVar21);
                } while (rowsLeft != 0);
              }
              depth = depth - 1;
              dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
              srcPixel = srcPixel + srcImagePad;
            } while (depth != 0);
          }
          goto LAB_0002e240;
        }
        if (uVar3 < 0x8037) {
          if (uVar3 == 0x8034) {
            if (0 < (int)depth) {
              do {
                rowsLeft = height;
                dstRow = dstSlice;
                if (0 < (int)height) {
                  do {
                    if (0 < width) {
                      local_90 = float65535;
                      columnsLeft2 = width;
                      dstPixel = dstRow;
                      do {
                        (*extractPixelFunc)(auStack_1b0,srcPixel);
                        columnsLeft2 = columnsLeft2 + -1;
                        local_c8 = (longlong)(int)(local_1a4 * float65535);
                        local_d0 = (longlong)(int)(local_1a8 * float65535);
                        local_d8 = (longlong)(int)(local_1ac * float65535);
                        local_e0 = (longlong)(int)(local_1a0 * float65535);
                        *(ushort *)dstPixel =
                             (ushort)(int)(local_1a4 * float65535) & 0xf800 |
                             (ushort)((uint)(int)(local_1a8 * float65535) >> 5) & 0x7c0 |
                             (ushort)((uint)(int)(local_1ac * float65535) >> 10) & 0x3e |
                             (ushort)((uint)(int)(local_1a0 * float65535) >> 0xf) & 1;
                        dstPixel = (uint *)((int)dstPixel + 2);
                        srcPixel = srcPixel + srcPixelStride;
                      } while (columnsLeft2 != 0);
                    }
                    rowsLeft = rowsLeft - 1;
                    srcPixel = srcPixel + srcRowPad;
                    dstRow = (uint *)((int)dstRow + iVar21);
                  } while (rowsLeft != 0);
                }
                depth = depth - 1;
                dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
                srcPixel = srcPixel + srcImagePad;
              } while (depth != 0);
            }
            goto LAB_0002e240;
          }
          if (0x8034 < uVar3) {
            if (0 < (int)depth) {
              do {
                rowsLeft = height;
                dstRow = dstSlice;
                if (0 < (int)height) {
                  do {
                    twoPow31 = DOUBLE_00108d80;
                    dstPixel = dstRow;
                    columnsLeft2 = width;
                    if (0 < width) {
                      do {
                        (*extractPixelFunc)(auStack_1b0,srcPixel);
                        scaledComponent = (double)local_1a4 * uint32MaxAsDouble;
                        if (twoPow31 <= scaledComponent) {
                          componentUint = (uint)(int)(scaledComponent - twoPow31);
                          local_d0 = (longlong)(int)componentUint;
                          componentUint = componentUint ^ 0x80000000;
                        }
                        else {
                          componentUint = (uint)(int)scaledComponent;
                          local_c8 = (longlong)(int)componentUint;
                        }
                        scaledComponent = (double)local_1a8 * uint32MaxAsDouble;
                        if (DOUBLE_00108d80 <= scaledComponent) {
                          local_e0 = (longlong)(int)(scaledComponent - DOUBLE_00108d80);
                          uVar18 = (int)(scaledComponent - DOUBLE_00108d80) ^ 0x80000000;
                        }
                        else {
                          uVar18 = (uint)(int)scaledComponent;
                          local_d8 = (longlong)(int)uVar18;
                        }
                        scaledComponent = (double)local_1ac * uint32MaxAsDouble;
                        if (DOUBLE_00108d80 <= scaledComponent) {
                          local_f0 = (longlong)(int)(scaledComponent - DOUBLE_00108d80);
                          uVar12 = (int)(scaledComponent - DOUBLE_00108d80) ^ 0x80000000;
                        }
                        else {
                          uVar12 = (uint)(int)scaledComponent;
                          local_e8 = (longlong)(int)uVar12;
                        }
                        scaledComponent = (double)local_1a0 * uint32MaxAsDouble;
                        if (DOUBLE_00108d80 <= scaledComponent) {
                          local_100 = (longlong)(int)(scaledComponent - DOUBLE_00108d80);
                          uVar13 = (int)(scaledComponent - DOUBLE_00108d80) ^ 0x80000000;
                        }
                        else {
                          uVar13 = (uint)(int)scaledComponent;
                          local_f8 = (longlong)(int)uVar13;
                        }
                        columnsLeft2 = columnsLeft2 + -1;
                        *dstPixel = componentUint & 0xff000000 | uVar18 >> 8 & 0xff0000 |
                                   uVar12 >> 0x10 & 0xff00 | uVar13 >> 0x18;
                        srcPixel = srcPixel + srcPixelStride;
                        dstPixel = dstPixel + 1;
                      } while (columnsLeft2 != 0);
                    }
                    rowsLeft = rowsLeft - 1;
                    srcPixel = srcPixel + srcRowPad;
                    dstRow = (uint *)((int)dstRow + iVar21);
                  } while (rowsLeft != 0);
                }
                depth = depth - 1;
                dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
                srcPixel = srcPixel + srcImagePad;
              } while (depth != 0);
            }
            goto LAB_0002e240;
          }
          if (uVar3 == 0x8033) {
            if (0 < (int)depth) {
              do {
                rowsLeft = height;
                dstRow = dstSlice;
                if (0 < (int)height) {
                  do {
                    if (0 < width) {
                      local_90 = float65535;
                      columnsLeft2 = width;
                      dstPixel = dstRow;
                      do {
                        (*extractPixelFunc)(auStack_1b0,srcPixel);
                        columnsLeft2 = columnsLeft2 + -1;
                        local_c8 = (longlong)(int)(local_1a4 * float65535);
                        local_d0 = (longlong)(int)(local_1a8 * float65535);
                        local_d8 = (longlong)(int)(local_1ac * float65535);
                        local_e0 = (longlong)(int)(local_1a0 * float65535);
                        *(ushort *)dstPixel =
                             (ushort)(int)(local_1a4 * float65535) & 0xf000 |
                             (ushort)((uint)(int)(local_1a8 * float65535) >> 4) & 0xf00 |
                             (ushort)((uint)(int)(local_1ac * float65535) >> 8) & 0xf0 |
                             (ushort)((uint)(int)(local_1a0 * float65535) >> 0xc) & 0xf;
                        dstPixel = (uint *)((int)dstPixel + 2);
                        srcPixel = srcPixel + srcPixelStride;
                      } while (columnsLeft2 != 0);
                    }
                    rowsLeft = rowsLeft - 1;
                    srcPixel = srcPixel + srcRowPad;
                    dstRow = (uint *)((int)dstRow + iVar21);
                  } while (rowsLeft != 0);
                }
                depth = depth - 1;
                dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
                srcPixel = srcPixel + srcImagePad;
              } while (depth != 0);
            }
            goto LAB_0002e240;
          }
        }
        else {
          if (uVar3 == 0x8366) {
            if (0 < (int)depth) {
              do {
                rowsLeft = height;
                dstRow = dstSlice;
                if (0 < (int)height) {
                  do {
                    if (0 < width) {
                      local_90 = float65535;
                      columnsLeft2 = width;
                      dstPixel = dstRow;
                      do {
                        (*extractPixelFunc)(auStack_1b0,srcPixel);
                        columnsLeft2 = columnsLeft2 + -1;
                        local_c8 = (longlong)(int)(local_1a0 * float65535);
                        local_d0 = (longlong)(int)(local_1ac * float65535);
                        local_d8 = (longlong)(int)(local_1a8 * float65535);
                        local_e0 = (longlong)(int)(local_1a4 * float65535);
                        *(ushort *)dstPixel =
                             (ushort)(int)(local_1a0 * float65535) & 0x8000 |
                             (ushort)((uint)(int)(local_1ac * float65535) >> 1) & 0x7c00 |
                             (ushort)((uint)(int)(local_1a8 * float65535) >> 6) & 0x3e0 |
                             (ushort)((uint)(int)(local_1a4 * float65535) >> 0xb) & 0x1f;
                        dstPixel = (uint *)((int)dstPixel + 2);
                        srcPixel = srcPixel + srcPixelStride;
                      } while (columnsLeft2 != 0);
                    }
                    rowsLeft = rowsLeft - 1;
                    srcPixel = srcPixel + srcRowPad;
                    dstRow = (uint *)((int)dstRow + iVar21);
                  } while (rowsLeft != 0);
                }
                depth = depth - 1;
                dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
                srcPixel = srcPixel + srcImagePad;
              } while (depth != 0);
            }
            goto LAB_0002e240;
          }
          if (uVar3 < 0x8367) {
            if (uVar3 == 0x8365) {
              if (0 < (int)depth) {
                do {
                  rowsLeft = height;
                  dstRow = dstSlice;
                  if (0 < (int)height) {
                    do {
                      if (0 < width) {
                        local_90 = float65535;
                        columnsLeft2 = width;
                        dstPixel = dstRow;
                        do {
                          (*extractPixelFunc)(auStack_1b0,srcPixel);
                          columnsLeft2 = columnsLeft2 + -1;
                          local_c8 = (longlong)(int)(local_1a0 * float65535);
                          local_d0 = (longlong)(int)(local_1ac * float65535);
                          local_d8 = (longlong)(int)(local_1a8 * float65535);
                          local_e0 = (longlong)(int)(local_1a4 * float65535);
                          *(ushort *)dstPixel =
                               (ushort)(int)(local_1a0 * float65535) & 0xf000 |
                               (ushort)((uint)(int)(local_1ac * float65535) >> 4) & 0xf00 |
                               (ushort)((uint)(int)(local_1a8 * float65535) >> 8) & 0xf0 |
                               (ushort)((uint)(int)(local_1a4 * float65535) >> 0xc) & 0xf;
                          dstPixel = (uint *)((int)dstPixel + 2);
                          srcPixel = srcPixel + srcPixelStride;
                        } while (columnsLeft2 != 0);
                      }
                      rowsLeft = rowsLeft - 1;
                      srcPixel = srcPixel + srcRowPad;
                      dstRow = (uint *)((int)dstRow + iVar21);
                    } while (rowsLeft != 0);
                  }
                  depth = depth - 1;
                  dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
                  srcPixel = srcPixel + srcImagePad;
                } while (depth != 0);
              }
              goto LAB_0002e240;
            }
          }
          else {
            if (uVar3 == 0x8367) {
              if (0 < (int)depth) {
                do {
                  rowsLeft = height;
                  dstRow = dstSlice;
                  if (0 < (int)height) {
                    do {
                      twoPow31 = DOUBLE_00108d80;
                      dstPixel = dstRow;
                      columnsLeft2 = width;
                      if (0 < width) {
                        do {
                          (*extractPixelFunc)(auStack_1b0,srcPixel);
                          scaledComponent = (double)local_1a0 * uint32MaxAsDouble;
                          if (twoPow31 <= scaledComponent) {
                            componentUint = (uint)(int)(scaledComponent - twoPow31);
                            local_d0 = (longlong)(int)componentUint;
                            componentUint = componentUint ^ 0x80000000;
                          }
                          else {
                            componentUint = (uint)(int)scaledComponent;
                            local_c8 = (longlong)(int)componentUint;
                          }
                          scaledComponent = (double)local_1ac * uint32MaxAsDouble;
                          if (DOUBLE_00108d80 <= scaledComponent) {
                            local_e0 = (longlong)(int)(scaledComponent - DOUBLE_00108d80);
                            uVar18 = (int)(scaledComponent - DOUBLE_00108d80) ^ 0x80000000;
                          }
                          else {
                            uVar18 = (uint)(int)scaledComponent;
                            local_d8 = (longlong)(int)uVar18;
                          }
                          scaledComponent = (double)local_1a8 * uint32MaxAsDouble;
                          if (DOUBLE_00108d80 <= scaledComponent) {
                            local_f0 = (longlong)(int)(scaledComponent - DOUBLE_00108d80);
                            uVar12 = (int)(scaledComponent - DOUBLE_00108d80) ^ 0x80000000;
                          }
                          else {
                            uVar12 = (uint)(int)scaledComponent;
                            local_e8 = (longlong)(int)uVar12;
                          }
                          scaledComponent = (double)local_1a4 * uint32MaxAsDouble;
                          if (DOUBLE_00108d80 <= scaledComponent) {
                            local_100 = (longlong)(int)(scaledComponent - DOUBLE_00108d80);
                            uVar13 = (int)(scaledComponent - DOUBLE_00108d80) ^ 0x80000000;
                          }
                          else {
                            uVar13 = (uint)(int)scaledComponent;
                            local_f8 = (longlong)(int)uVar13;
                          }
                          columnsLeft2 = columnsLeft2 + -1;
                          *dstPixel = componentUint & 0xff000000 | uVar18 >> 8 & 0xff0000 |
                                     uVar12 >> 0x10 & 0xff00 | uVar13 >> 0x18;
                          srcPixel = srcPixel + srcPixelStride;
                          dstPixel = dstPixel + 1;
                        } while (columnsLeft2 != 0);
                      }
                      rowsLeft = rowsLeft - 1;
                      srcPixel = srcPixel + srcRowPad;
                      dstRow = (uint *)((int)dstRow + iVar21);
                    } while (rowsLeft != 0);
                  }
                  depth = depth - 1;
                  dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
                  srcPixel = srcPixel + srcImagePad;
                } while (depth != 0);
              }
              goto LAB_0002e240;
            }
            if (uVar3 == 0x8368) {
              if (0 < (int)depth) {
                do {
                  rowsLeft = height;
                  dstRow = dstSlice;
                  if (0 < (int)height) {
                    do {
                      twoPow31 = DOUBLE_00108d80;
                      dstPixel = dstRow;
                      columnsLeft2 = width;
                      if (0 < width) {
                        do {
                          (*extractPixelFunc)(auStack_1b0,srcPixel);
                          scaledComponent = (double)local_1a0 * uint32MaxAsDouble;
                          if (twoPow31 <= scaledComponent) {
                            componentUint = (uint)(int)(scaledComponent - twoPow31);
                            local_d0 = (longlong)(int)componentUint;
                            componentUint = componentUint ^ 0x80000000;
                          }
                          else {
                            componentUint = (uint)(int)scaledComponent;
                            local_c8 = (longlong)(int)componentUint;
                          }
                          scaledComponent = (double)local_1ac * uint32MaxAsDouble;
                          if (DOUBLE_00108d80 <= scaledComponent) {
                            local_e0 = (longlong)(int)(scaledComponent - DOUBLE_00108d80);
                            uVar18 = (int)(scaledComponent - DOUBLE_00108d80) ^ 0x80000000;
                          }
                          else {
                            uVar18 = (uint)(int)scaledComponent;
                            local_d8 = (longlong)(int)uVar18;
                          }
                          scaledComponent = (double)local_1a8 * uint32MaxAsDouble;
                          if (DOUBLE_00108d80 <= scaledComponent) {
                            local_f0 = (longlong)(int)(scaledComponent - DOUBLE_00108d80);
                            uVar12 = (int)(scaledComponent - DOUBLE_00108d80) ^ 0x80000000;
                          }
                          else {
                            uVar12 = (uint)(int)scaledComponent;
                            local_e8 = (longlong)(int)uVar12;
                          }
                          scaledComponent = (double)local_1a4 * uint32MaxAsDouble;
                          if (DOUBLE_00108d80 <= scaledComponent) {
                            local_100 = (longlong)(int)(scaledComponent - DOUBLE_00108d80);
                            uVar13 = (int)(scaledComponent - DOUBLE_00108d80) ^ 0x80000000;
                          }
                          else {
                            uVar13 = (uint)(int)scaledComponent;
                            local_f8 = (longlong)(int)uVar13;
                          }
                          columnsLeft2 = columnsLeft2 + -1;
                          *dstPixel = componentUint & 0xc0000000 | uVar18 >> 2 & 0x3ff00000 |
                                     uVar12 >> 0xc & 0xffc00 | uVar13 >> 0x16;
                          srcPixel = srcPixel + srcPixelStride;
                          dstPixel = dstPixel + 1;
                        } while (columnsLeft2 != 0);
                      }
                      rowsLeft = rowsLeft - 1;
                      srcPixel = srcPixel + srcRowPad;
                      dstRow = (uint *)((int)dstRow + iVar21);
                    } while (rowsLeft != 0);
                  }
                  depth = depth - 1;
                  dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
                  srcPixel = srcPixel + srcImagePad;
                } while (depth != 0);
              }
              goto LAB_0002e240;
            }
          }
        }
        if (0 < (int)depth) {
          do {
            rowsLeft = height;
            dstRow = dstSlice;
            if (0 < (int)height) {
              do {
                float255C = FLOAT_00108f70;
                floatOne2 = FLOAT_00108e54;
                floatZero = FLOAT_00108e50;
                columnsLeft = width;
                dstPixel = dstRow;
                if (0 < width) {
                  do {
                    (*extractPixelFunc)(auStack_1b0,srcPixel);
                    if (floatOne2 < local_1a4) {
                      componentByte = 0xff;
                    }
                    else {
                      componentByte = 0;
                      if (!(local_1a4 < floatZero)) {
                        (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)(int)(local_1a4 * float255C);
                        componentByte = (undefined1)local_c8;
                        local_c8 = (longlong)(int)(local_1a4 * float255C);
                      }
                    }
                    *(undefined1 *)dstPixel = componentByte;
                    if (floatOne2 < local_1a8) {
                      componentByte = 0xff;
                    }
                    else {
                      componentByte = 0;
                      if (!(local_1a8 < floatZero)) {
                        (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)(int)(local_1a8 * float255C);
                        componentByte = (undefined1)local_c8;
                        local_c8 = (longlong)(int)(local_1a8 * float255C);
                      }
                    }
                    *(undefined1 *)((int)dstPixel + 1) = componentByte;
                    if (floatOne2 < local_1ac) {
                      componentByte = 0xff;
                    }
                    else {
                      componentByte = 0;
                      if (!(local_1ac < floatZero)) {
                        (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)(int)(local_1ac * float255C);
                        componentByte = (undefined1)local_c8;
                        local_c8 = (longlong)(int)(local_1ac * float255C);
                      }
                    }
                    *(undefined1 *)((int)dstPixel + 2) = componentByte;
                    if (floatOne2 < local_1a0) {
                      componentByte = 0xff;
                    }
                    else {
                      componentByte = 0;
                      if (!(local_1a0 < floatZero)) {
                        (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)(int)(local_1a0 * float255C);
                        componentByte = (undefined1)local_c8;
                        local_c8 = (longlong)(int)(local_1a0 * float255C);
                      }
                    }
                    columnsLeft = columnsLeft + -1;
                    *(undefined1 *)((int)dstPixel + 3) = componentByte;
                    srcPixel = srcPixel + srcPixelStride;
                    dstPixel = (uint *)((int)dstPixel + iVar17);
                  } while (columnsLeft != 0);
                }
                rowsLeft = rowsLeft - 1;
                srcPixel = srcPixel + srcRowPad;
                dstRow = (uint *)((int)dstRow + iVar21);
              } while (rowsLeft != 0);
            }
            depth = depth - 1;
            dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
            srcPixel = srcPixel + srcImagePad;
          } while (depth != 0);
        }
        goto LAB_0002e240;
      }
      uVar14 = 0x86dc;
    }
    else {
      if (uVar3 == 0x86f5) {
        if (0 < (int)depth) {
          do {
            rowsLeft = height;
            dstRow = dstSlice;
            if (0 < (int)height) {
              do {
                float127B = FLOAT_00108f6c;
                floatMinusOne = FLOAT_00108e58;
                floatOne = FLOAT_00108e54;
                columnsLeft = width;
                dstPixel = dstRow;
                if (0 < width) {
                  do {
                    (*extractPixelFunc)(auStack_1b0,srcPixel);
                    if (floatOne < local_188) {
                      componentByte = 0x7f;
                    }
                    else {
                      componentByte = 0x81;
                      if (!(local_188 < floatMinusOne)) {
                        scaledInt = (int)(local_188 * float127B);
                        (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)scaledInt;
                        componentByte = (undefined1)local_c8;
                        local_c8 = (longlong)scaledInt;
                      }
                    }
                    *(undefined1 *)((int)dstPixel + 1) = componentByte;
                    if (floatOne < local_184) {
                      componentByte = 0x7f;
                    }
                    else {
                      componentByte = 0x81;
                      if (!(local_184 < floatMinusOne)) {
                        scaledInt = (int)(local_184 * float127B);
                        (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)scaledInt;
                        componentByte = (undefined1)local_c8;
                        local_c8 = (longlong)scaledInt;
                      }
                    }
                    columnsLeft = columnsLeft + -1;
                    *(undefined1 *)dstPixel = componentByte;
                    srcPixel = srcPixel + srcPixelStride;
                    dstPixel = (uint *)((int)dstPixel + iVar17);
                  } while (columnsLeft != 0);
                }
                rowsLeft = rowsLeft - 1;
                srcPixel = srcPixel + srcRowPad;
                dstRow = (uint *)((int)dstRow + iVar21);
              } while (rowsLeft != 0);
            }
            depth = depth - 1;
            dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
            srcPixel = srcPixel + srcImagePad;
          } while (depth != 0);
        }
        goto LAB_0002e240;
      }
      uVar14 = 0x86f6;
    }
    if (uVar3 == uVar14) {
      if (0 < (int)depth) {
        do {
          rowsLeft = height;
          dstRow = dstSlice;
          if (0 < (int)height) {
            do {
              float255 = FLOAT_00108f70;
              float127 = FLOAT_00108f6c;
              floatMinusOne2 = FLOAT_00108e58;
              floatOne2 = FLOAT_00108e54;
              floatZero = FLOAT_00108e50;
              if (0 < width) {
                puVar30 = (undefined1 *)((int)dstRow + 2);
                dstPixel = dstRow;
                columnsLeft = width;
                do {
                  (*extractPixelFunc)(auStack_1b0,srcPixel);
                  if (floatOne2 < local_188) {
                    componentByte = 0x7f;
                  }
                  else {
                    componentByte = 0x81;
                    if (!(local_188 < floatMinusOne2)) {
                      scaledInt = (int)(local_188 * float127);
                      (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)scaledInt;
                      componentByte = (undefined1)local_c8;
                      local_c8 = (longlong)scaledInt;
                    }
                  }
                  puVar30[1] = componentByte;
                  if (floatOne2 < local_184) {
                    componentByte = 0x7f;
                  }
                  else {
                    componentByte = 0x81;
                    if (!(local_184 < floatMinusOne2)) {
                      scaledInt = (int)(local_184 * float127);
                      (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)scaledInt;
                      componentByte = (undefined1)local_c8;
                      local_c8 = (longlong)scaledInt;
                    }
                  }
                  *puVar30 = componentByte;
                  if (floatOne2 < local_180) {
                    componentByte = 0xff;
                  }
                  else {
                    componentByte = 0;
                    if (!(local_180 < floatZero)) {
                      scaledInt = (int)(local_180 * float255);
                      (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)scaledInt;
                      componentByte = (undefined1)local_c8;
                      local_c8 = (longlong)scaledInt;
                    }
                  }
                  *(undefined1 *)((int)dstPixel + 1) = componentByte;
                  if (floatOne2 < local_1ac) {
                    componentByte = 0xff;
                  }
                  else {
                    componentByte = 0;
                    if (!(local_1ac < floatZero)) {
                      scaledInt = (int)(local_1ac * float255);
                      (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)scaledInt;
                      componentByte = (undefined1)local_c8;
                      local_c8 = (longlong)scaledInt;
                    }
                  }
                  columnsLeft = columnsLeft + -1;
                  *(undefined1 *)dstPixel = componentByte;
                  puVar30 = puVar30 + iVar17;
                  dstPixel = (uint *)((int)dstPixel + iVar17);
                  srcPixel = srcPixel + srcPixelStride;
                } while (columnsLeft != 0);
              }
              rowsLeft = rowsLeft - 1;
              srcPixel = srcPixel + srcRowPad;
              dstRow = (uint *)((int)dstRow + iVar21);
            } while (rowsLeft != 0);
          }
          depth = depth - 1;
          dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
          srcPixel = srcPixel + srcImagePad;
        } while (depth != 0);
      }
      goto LAB_0002e240;
    }
  }
  if (*(short *)(textureLevel + 0x12) == 0x1400) {
    if (0 < (int)depth) {
      do {
        rowsLeft = height;
        dstRow = dstSlice;
        if (0 < (int)height) {
          do {
            float127B = FLOAT_00108f6c;
            floatMinusOne = FLOAT_00108e58;
            floatOne = FLOAT_00108e54;
            columnsLeft = width;
            dstPixel = dstRow;
            if (0 < width) {
              do {
                (*extractPixelFunc)(auStack_1b0,srcPixel);
                if (floatOne < local_1ac) {
                  componentByte = 0x7f;
                }
                else {
                  componentByte = 0x81;
                  if (!(local_1ac < floatMinusOne)) {
                    (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)(int)(local_1ac * float127B);
                    componentByte = (undefined1)local_c8;
                    local_c8 = (longlong)(int)(local_1ac * float127B);
                  }
                }
                columnsLeft = columnsLeft + -1;
                *(undefined1 *)dstPixel = componentByte;
                srcPixel = srcPixel + srcPixelStride;
                dstPixel = (uint *)((int)dstPixel + iVar17);
              } while (columnsLeft != 0);
            }
            rowsLeft = rowsLeft - 1;
            srcPixel = srcPixel + srcRowPad;
            dstRow = (uint *)((int)dstRow + iVar21);
          } while (rowsLeft != 0);
        }
        depth = depth - 1;
        dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
        srcPixel = srcPixel + srcImagePad;
      } while (depth != 0);
    }
  }
  else if (0 < (int)depth) {
    do {
      rowsLeft = height;
      dstRow = dstSlice;
      if (0 < (int)height) {
        do {
          float255C = FLOAT_00108f70;
          floatOne2 = FLOAT_00108e54;
          floatZero = FLOAT_00108e50;
          columnsLeft = width;
          dstPixel = dstRow;
          if (0 < width) {
            do {
              (*extractPixelFunc)(auStack_1b0,srcPixel);
              if (floatOne2 < local_1ac) {
                componentByte = 0xff;
              }
              else {
                componentByte = 0;
                if (!(local_1ac < floatZero)) {
                  (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)(int)(local_1ac * float255C);
                  componentByte = (undefined1)local_c8;
                  local_c8 = (longlong)(int)(local_1ac * float255C);
                }
              }
              columnsLeft = columnsLeft + -1;
              *(undefined1 *)dstPixel = componentByte;
              srcPixel = srcPixel + srcPixelStride;
              dstPixel = (uint *)((int)dstPixel + iVar17);
            } while (columnsLeft != 0);
          }
          rowsLeft = rowsLeft - 1;
          srcPixel = srcPixel + srcRowPad;
          dstRow = (uint *)((int)dstRow + iVar21);
        } while (rowsLeft != 0);
      }
      depth = depth - 1;
      dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
      srcPixel = srcPixel + srcImagePad;
    } while (depth != 0);
  }
LAB_0002e240:
  if (bVar4) {
    _free(pixels);
  }
  return;
}

/* _gleSelectPixelExtractFunc @ 0x2e264 (3124 bytes) */
int _gleSelectPixelExtractFunc(param_1, param_2)
  uint param_1;
  uint param_2;
{
  if (param_1 == 0x1908) {
    if (param_2 == 0x1406) {
      return PTR__gleExtractPixel_RGBA_Float_00111074;
    }
    if (param_2 < 0x1407) {
      if (param_2 == 0x1402) {
        return PTR__gleExtractPixel_RGBA_Short_00111084;
      }
      if (0x1402 < param_2) {
        if (param_2 == 0x1404) {
          return PTR__gleExtractPixel_RGBA_Int_0011107c;
        }
        if (0x1404 < param_2) {
          return PTR__gleExtractPixel_RGBA_Uint_00111078;
        }
        return PTR__gleExtractPixel_RGBA_Ushort_00111080;
      }
      if (param_2 == 0x1400) {
        return PTR__gleExtractPixel_RGBA_Byte_0011108c;
      }
      if (param_2 == 0x1401) {
        return PTR__gleExtractPixel_RGBA_Ubyte_00111088;
      }
    }
    else {
      if (param_2 == 0x8036) {
        return PTR__gleExtractPixel_RGBA_1010102_00111058;
      }
      if (param_2 < 0x8037) {
        if (param_2 == 0x8034) {
          return PTR__gleExtractPixel_RGBA_5551_00111068;
        }
        if (0x8034 < param_2) {
          return PTR__gleExtractPixel_RGBA_8888_00111060;
        }
        if (param_2 == 0x8033) {
          return PTR__gleExtractPixel_RGBA_4444_00111070;
        }
      }
      else {
        if (param_2 == 0x8366) {
          return PTR__gleExtractPixel_RGBA_1555Rev_00111064;
        }
        if (param_2 < 0x8367) {
          if (param_2 == 0x8365) {
            return PTR__gleExtractPixel_RGBA_4444Rev_0011106c;
          }
        }
        else if (param_2 == 0x8367) {
          return PTR__gleExtractPixel_RGBA_8888Rev_0011105c;
        }
      }
    }
    return PTR__gleExtractPixel_RGBA_2101010Rev_00111054;
  }
  if (param_1 < 0x1909) {
    if (param_1 == 0x1903) {
      switch(param_2) {
      case 0x1400:
        return PTR__gleExtractPixel_R_Byte_00110f38;
      case 0x1401:
        return PTR__gleExtractPixel_R_Ubyte_00110f34;
      case 0x1402:
        return PTR__gleExtractPixel_R_Short_00110f30;
      case 0x1403:
        return PTR__gleExtractPixel_R_Ushort_00110f2c;
      case 0x1404:
        return PTR__gleExtractPixel_R_Int_00110f28;
      case 0x1405:
        return PTR__gleExtractPixel_R_Uint_00110f24;
      default:
        return PTR__gleExtractPixel_R_Float_00110f20;
      }
    }
    if (param_1 < 0x1904) {
      if (0x18ff < param_1) {
        if (0x1901 < param_1) {
          switch(param_2) {
          case 0x1400:
            return PTR__gleExtractPixel_Depth_Byte_001110a8;
          case 0x1401:
            return PTR__gleExtractPixel_Depth_Ubyte_001110a4;
          case 0x1402:
            return PTR__gleExtractPixel_Depth_Short_001110a0;
          case 0x1403:
            return PTR__gleExtractPixel_Depth_Ushort_0011109c;
          case 0x1404:
            return PTR__gleExtractPixel_Depth_Int_00111098;
          case 0x1405:
            return PTR__gleExtractPixel_Depth_Uint_00111094;
          default:
            return PTR__gleExtractPixel_Depth_Float_00111090;
          }
        }
        switch(param_2) {
        case 0x1400:
          return PTR__gleExtractPixel_Index_Byte_001110c4;
        case 0x1401:
          return PTR__gleExtractPixel_Index_Ubyte_001110c0;
        case 0x1402:
          return PTR__gleExtractPixel_Index_Short_001110bc;
        case 0x1403:
          return PTR__gleExtractPixel_Index_Ushort_001110b8;
        case 0x1404:
          return PTR__gleExtractPixel_Index_Int_001110b4;
        case 0x1405:
          return PTR__gleExtractPixel_Index_Uint_001110b0;
        default:
          return PTR__gleExtractPixel_Index_Float_001110ac;
        }
      }
    }
    else {
      if (param_1 == 0x1905) {
        switch(param_2) {
        case 0x1400:
          return PTR__gleExtractPixel_B_Byte_00110f00;
        case 0x1401:
          return PTR__gleExtractPixel_B_Ubyte_00110efc;
        case 0x1402:
          return PTR__gleExtractPixel_B_Short_00110ef8;
        case 0x1403:
          return PTR__gleExtractPixel_B_Ushort_00110ef4;
        case 0x1404:
          return PTR__gleExtractPixel_B_Int_00110ef0;
        case 0x1405:
          return PTR__gleExtractPixel_B_Uint_00110eec;
        default:
          return PTR__gleExtractPixel_B_Float_00110ee8;
        }
      }
      if (param_1 < 0x1905) {
        switch(param_2) {
        case 0x1400:
          return PTR__gleExtractPixel_G_Byte_00110f1c;
        case 0x1401:
          return PTR__gleExtractPixel_G_Ubyte_00110f18;
        case 0x1402:
          return PTR__gleExtractPixel_G_Short_00110f14;
        case 0x1403:
          return PTR__gleExtractPixel_G_Ushort_00110f10;
        case 0x1404:
          return PTR__gleExtractPixel_G_Int_00110f0c;
        case 0x1405:
          return PTR__gleExtractPixel_G_Uint_00110f08;
        default:
          return PTR__gleExtractPixel_G_Float_00110f04;
        }
      }
      if (param_1 == 0x1906) {
        switch(param_2) {
        case 0x1400:
          return PTR__gleExtractPixel_A_Byte_00110ee4;
        case 0x1401:
          return PTR__gleExtractPixel_A_Ubyte_00110ee0;
        case 0x1402:
          return PTR__gleExtractPixel_A_Short_00110edc;
        case 0x1403:
          return PTR__gleExtractPixel_A_Ushort_00110ed8;
        case 0x1404:
          return PTR__gleExtractPixel_A_Int_00110ed4;
        case 0x1405:
          return PTR__gleExtractPixel_A_Uint_00110ed0;
        default:
          return PTR__gleExtractPixel_A_Float_00110ecc;
        }
      }
      if (param_1 == 0x1907) {
        if (param_2 == 0x1404) {
          return PTR__gleExtractPixel_RGB_Int_00110f54;
        }
        if (param_2 < 0x1405) {
          if (param_2 == 0x1401) {
            return PTR__gleExtractPixel_RGB_Ubyte_00110f60;
          }
          if (param_2 < 0x1402) {
            if (param_2 == 0x1400) {
              return PTR__gleExtractPixel_RGB_Byte_00110f64;
            }
          }
          else {
            if (param_2 == 0x1402) {
              return PTR__gleExtractPixel_RGB_Short_00110f5c;
            }
            if (param_2 == 0x1403) {
              return PTR__gleExtractPixel_RGB_Ushort_00110f58;
            }
          }
        }
        else {
          if (param_2 == 0x8032) {
            return PTR__gleExtractPixel_RGB_332_00110f48;
          }
          if (param_2 < 0x8033) {
            if (param_2 == 0x1405) {
              return PTR__gleExtractPixel_RGB_Uint_00110f50;
            }
            if (param_2 == 0x1406) {
              return PTR__gleExtractPixel_RGB_Float_00110f4c;
            }
          }
          else {
            if (param_2 == 0x8362) {
              return PTR__gleExtractPixel_RGB_233Rev_00110f44;
            }
            if (param_2 == 0x8363) {
              return PTR__gleExtractPixel_RGB_565_00110f40;
            }
          }
        }
        return PTR__gleExtractPixel_RGB_565Rev_00110f3c;
      }
    }
  }
  else {
    if (param_1 == 0x80e1) {
      if (param_2 == 0x1406) {
        return PTR__gleExtractPixel_BGRA_EXT_Float_0011101c;
      }
      if (param_2 < 0x1407) {
        if (param_2 == 0x1402) {
          return PTR__gleExtractPixel_BGRA_EXT_Short_0011102c;
        }
        if (0x1402 < param_2) {
          if (param_2 == 0x1404) {
            return PTR__gleExtractPixel_BGRA_EXT_Int_00111024;
          }
          if (0x1404 < param_2) {
            return PTR__gleExtractPixel_BGRA_EXT_Uint_00111020;
          }
          return PTR__gleExtractPixel_BGRA_EXT_Ushort_00111028;
        }
        if (param_2 == 0x1400) {
          return PTR__gleExtractPixel_BGRA_EXT_Byte_00111034;
        }
        if (param_2 == 0x1401) {
          return PTR__gleExtractPixel_BGRA_EXT_Ubyte_00111030;
        }
      }
      else {
        if (param_2 == 0x8036) {
          return PTR__gleExtractPixel_BGRA_1010102_00111000;
        }
        if (param_2 < 0x8037) {
          if (param_2 == 0x8034) {
            return PTR__gleExtractPixel_BGRA_5551_00111010;
          }
          if (0x8034 < param_2) {
            return PTR__gleExtractPixel_BGRA_8888_00111008;
          }
          if (param_2 == 0x8033) {
            return PTR__gleExtractPixel_BGRA_4444_00111018;
          }
        }
        else {
          if (param_2 == 0x8366) {
            return PTR__gleExtractPixel_BGRA_1555Rev_0011100c;
          }
          if (param_2 < 0x8367) {
            if (param_2 == 0x8365) {
              return PTR__gleExtractPixel_BGRA_4444Rev_00111014;
            }
          }
          else if (param_2 == 0x8367) {
            return PTR__gleExtractPixel_BGRA_8888Rev_00111004;
          }
        }
      }
      return PTR__gleExtractPixel_BGRA_2101010Rev_00110ffc;
    }
    if (param_1 < 0x80e2) {
      if (param_1 == 0x8000) {
        switch(param_2) {
        case 0x1400:
          return PTR__gleExtractPixel_ABGR_EXT_Byte_00111050;
        case 0x1401:
          return PTR__gleExtractPixel_ABGR_EXT_Ubyte_0011104c;
        case 0x1402:
          return PTR__gleExtractPixel_ABGR_EXT_Short_00111048;
        case 0x1403:
          return PTR__gleExtractPixel_ABGR_EXT_Ushort_00111044;
        case 0x1404:
          return PTR__gleExtractPixel_ABGR_EXT_Int_00111040;
        case 0x1405:
          return PTR__gleExtractPixel_ABGR_EXT_Uint_0011103c;
        default:
          return PTR__gleExtractPixel_ABGR_EXT_Float_00111038;
        }
      }
      if (param_1 < 0x8001) {
        if (param_1 == 0x1909) {
          switch(param_2) {
          case 0x1400:
            return PTR__gleExtractPixel_L_Byte_00110ec8;
          case 0x1401:
            return PTR__gleExtractPixel_L_Ubyte_00110ec4;
          case 0x1402:
            return PTR__gleExtractPixel_L_Short_00110ec0;
          case 0x1403:
            return PTR__gleExtractPixel_L_Ushort_00110ebc;
          case 0x1404:
            return PTR__gleExtractPixel_L_Int_00110eb8;
          case 0x1405:
            return PTR__gleExtractPixel_L_Uint_00110eb4;
          default:
            return PTR__gleExtractPixel_L_Float_00110eb0;
          }
        }
      }
      else if (param_1 == 0x80e0) {
        switch(param_2) {
        case 0x1400:
          return PTR__gleExtractPixel_BGR_EXT_Byte_00110ff8;
        case 0x1401:
          return PTR__gleExtractPixel_BGR_EXT_Ubyte_00110ff4;
        case 0x1402:
          return PTR__gleExtractPixel_BGR_EXT_Short_00110ff0;
        case 0x1403:
          return PTR__gleExtractPixel_BGR_EXT_Ushort_00110fec;
        case 0x1404:
          return PTR__gleExtractPixel_BGR_EXT_Int_00110fe8;
        case 0x1405:
          return PTR__gleExtractPixel_BGR_EXT_Uint_00110fe4;
        default:
          return PTR__gleExtractPixel_BGR_EXT_Float_00110fe0;
        }
      }
    }
    else {
      if (param_1 == 0x86f5) {
        switch(param_2) {
        case 0x1400:
          return PTR__gleExtractPixel_DSDT_Byte_00110fc0;
        case 0x1401:
          return PTR__gleExtractPixel_DSDT_Ubyte_00110fbc;
        case 0x1402:
          return PTR__gleExtractPixel_DSDT_Short_00110fb8;
        case 0x1403:
          return PTR__gleExtractPixel_DSDT_Ushort_00110fb4;
        case 0x1404:
          return PTR__gleExtractPixel_DSDT_Int_00110fb0;
        case 0x1405:
          return PTR__gleExtractPixel_DSDT_Uint_00110fac;
        default:
          return PTR__gleExtractPixel_DSDT_Float_00110fa8;
        }
      }
      if (param_1 < 0x86f6) {
        if (param_1 == 0x86f4) {
          switch(param_2) {
          case 0x1400:
            return PTR__gleExtractPixel_HILO_Byte_00110fdc;
          case 0x1401:
            return PTR__gleExtractPixel_HILO_Ubyte_00110fd8;
          case 0x1402:
            return PTR__gleExtractPixel_HILO_Short_00110fd4;
          case 0x1403:
            return PTR__gleExtractPixel_HILO_Ushort_00110fd0;
          case 0x1404:
            return PTR__gleExtractPixel_HILO_Int_00110fcc;
          case 0x1405:
            return PTR__gleExtractPixel_HILO_Uint_00110fc8;
          default:
            return PTR__gleExtractPixel_HILO_Float_00110fc4;
          }
        }
      }
      else {
        if (param_1 == 0x86f6) {
          switch(param_2) {
          case 0x1400:
            return PTR__gleExtractPixel_DSDT_MAG_Byte_00110fa4;
          case 0x1401:
            return PTR__gleExtractPixel_DSDT_MAG_Ubyte_00110fa0;
          case 0x1402:
            return PTR__gleExtractPixel_DSDT_MAG_Short_00110f9c;
          case 0x1403:
            return PTR__gleExtractPixel_DSDT_MAG_Ushort_00110f98;
          case 0x1404:
            return PTR__gleExtractPixel_DSDT_MAG_Int_00110f94;
          case 0x1405:
            return PTR__gleExtractPixel_DSDT_MAG_Uint_00110f90;
          default:
            return PTR__gleExtractPixel_DSDT_MAG_Float_00110f8c;
          }
        }
        if (param_1 == 0x86f7) {
          if (param_2 == 0x1403) {
            return PTR__gleExtractPixel_DSDT_MAG_VIB_Ushort_00110f74;
          }
          if (param_2 < 0x1404) {
            if (param_2 == 0x1401) {
              return PTR__gleExtractPixel_DSDT_MAG_VIB_Ubyte_00110f7c;
            }
            if (0x1401 < param_2) {
              return PTR__gleExtractPixel_DSDT_MAG_VIB_Short_00110f78;
            }
            if (param_2 == 0x1400) {
              return PTR__gleExtractPixel_DSDT_MAG_VIB_Byte_00110f80;
            }
          }
          else {
            if (param_2 == 0x1405) {
              return PTR__gleExtractPixel_DSDT_MAG_VIB_Uint_00110f6c;
            }
            if (param_2 < 0x1405) {
              return PTR__gleExtractPixel_DSDT_MAG_VIB_Int_00110f70;
            }
            if (param_2 == 0x86da) {
              return PTR__gleExtractPixel_DSDT_MAG_VIB_S8_S8_8_8_00110f88;
            }
            if (param_2 == 0x86db) {
              return PTR__gleExtractPixel_DSDT_MAG_VIB_8_8_S8_S8_Rev_00110f84;
            }
          }
          return PTR__gleExtractPixel_DSDT_MAG_VIB_Float_00110f68;
        }
      }
    }
  }
  switch(param_2) {
  case 0x1400:
    return PTR__gleExtractPixel_LA_Byte_00110eac;
  case 0x1401:
    return PTR__gleExtractPixel_LA_Ubyte_00110ea8;
  case 0x1402:
    return PTR__gleExtractPixel_LA_Short_00110ea4;
  case 0x1403:
    return PTR__gleExtractPixel_LA_Ushort_00110ea0;
  case 0x1404:
    return PTR__gleExtractPixel_LA_Int_00110e9c;
  case 0x1405:
    return PTR__gleExtractPixel_LA_Uint_00110e98;
  default:
    return PTR__gleExtractPixel_LA_Float_00110e94;
  }
}

/* _gleSelectModifyPixelFunc @ 0x2efd0 (476 bytes) */
int _gleSelectModifyPixelFunc(param_1, param_2)
  int param_1;
  uint param_2;
{
  bool bVar1;
  int iVar2;
  undefined *puVar3;
  
  iVar2 = _gleIsIndex(param_2);
  if (iVar2 == 0) {
    if (param_2 == 0x1902) {
      puVar3 = (undefined *)0x0;
      if ((*(uint *)(param_1 + 0x3414) & 0x3000) != 0) {
        puVar3 = PTR__gleModifyPixelDepth_00111200;
      }
    }
    else if (param_2 == 0x86f4) {
      puVar3 = (undefined *)0x0;
      if ((*(uint *)(param_1 + 0x3418) & 0xf) != 0) {
        puVar3 = PTR__gleModifyPixelHILO_001111fc;
      }
    }
    else if ((param_2 - 0x86f5 < 2) || (param_2 == 0x86dc)) {
      puVar3 = (undefined *)0x0;
      if ((*(uint *)(param_1 + 0x3418) & 0xff0) != 0) {
        puVar3 = PTR__gleModifyPixelDSDTMagVib_001111f8;
      }
    }
    else {
      puVar3 = (undefined *)0x0;
      if (((*(uint *)(param_1 + 0x3414) & 0xff1) != 0) &&
         (puVar3 = PTR__gleModifyPixelRGBA_001111f4, param_2 != 0x1908)) {
        puVar3 = PTR__gleModifyPixelA_001111e0;
        if (param_2 < 0x1909) {
          if (param_2 == 0x1904) {
            return PTR__gleModifyPixelG_001111e8;
          }
          if (param_2 < 0x1905) {
            if (param_2 == 0x1903) {
              return PTR__gleModifyPixelR_001111ec;
            }
          }
          else {
            if (param_2 == 0x1905) {
              return PTR__gleModifyPixelB_001111e4;
            }
            if (param_2 == 0x1907) {
              return PTR__gleModifyPixelRGB_001111f0;
            }
          }
        }
        else {
          if (param_2 == 0x8000) {
            return PTR__gleModifyPixelRGBA_001111f4;
          }
          if (param_2 < 0x8001) {
            if (param_2 == 0x1909) {
              return PTR__gleModifyPixelRGB_001111f0;
            }
            bVar1 = param_2 == 0x190a;
          }
          else {
            if (param_2 == 0x80e0) {
              return PTR__gleModifyPixelRGB_001111f0;
            }
            bVar1 = param_2 == 0x80e1;
          }
          if (bVar1) {
            return PTR__gleModifyPixelRGBA_001111f4;
          }
        }
      }
    }
  }
  else {
    puVar3 = PTR__gleModifyPixelRGBAIndex_00111208;
    if ((param_2 != 0x1900) && (puVar3 = (undefined *)0x0, (*(uint *)(param_1 + 0x3414) & 0xe) != 0)
       ) {
      puVar3 = PTR__gleModifyPixelStencil_00111204;
    }
  }
  return puVar3;
}

