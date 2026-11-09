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
  return;
}

/* _glEndNoMat_Exec @ 0x1ed10 (64 bytes) */
int _glEndNoMat_Exec(param_1)
  int param_1;
{
  if (-1 < *(short *)(param_1 + 0x4a10)) {
    *(undefined2 *)(param_1 + 0x4a10) = 0xffff;
    *(undefined4 *)(param_1 + 0x4884) = *(undefined4 *)(param_1 + 0xd8);
                    
                    
    (**(int ( **)(int))(param_1 + 0x4a08))(param_1);
    return;
  }
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  *(undefined4 *)(param_1 + 0x7574) = 0x502;
  return;
}

/* _glFlush_Exec @ 0x1ee38 (652 bytes) */
void _glFlush_Exec(int param_1,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
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
    goto LAB_0001f064;
  }
  iVar6 = *(int *)(param_1 + 0x50ac);
  if (iVar6 != 0 || (*(uint *)(param_1 + 0x505c) & *(uint *)(param_1 + 0x50b0)) != 0) {
    _gleUpdateMatrixFunc(param_1);
    fparam_1 = extraout_f1;
  }
  if (*(char *)(param_1 + 0x4691) == '\0') goto LAB_0001f090;
  iVar5 = *(int *)(param_1 + 0x744c);
  piVar8 = (int *)(param_1 + 0x310);
  cVar2 = *(char *)(*(int *)(param_1 + 0x468c) + 0x79);
  if ((iVar5 != 0) && (*(int *)(iVar5 + 0xec) != 0)) {
    ((int (*)())_gleUpdateFramebufferCompleteness)(param_1,iVar5 + 0x10,in_r5,in_r6,in_r7,in_r8,iVar6,fparam_1,fparam_2,fparam_3,
               fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
    *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x80000000;
  }
  if ((*(char *)(param_1 + 0x4664) == '\0') && (*(int *)(param_1 + 0x5430) == 0)) {
LAB_0001ef68:
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
LAB_0001f064:
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
LAB_0001f090:
                    
                    
  (**(code **)(param_1 + 0x46f4))(*(undefined4 *)(param_1 + 0x4688));
  return;
}

/* _glTexSubImage2D_Exec @ 0x1f0c4 (1364 bytes) */
int _glTexSubImage2D_Exec(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10)
  int param_1;
  int param_2;
  uint param_3;
  int param_4;
  int param_5;
  int param_6;
  int param_7;
  undefined4 param_8;
  undefined4 param_9;
  int param_10;
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
  
  iVar3 = param_1;
  if (-1 < *(short *)(param_1 + 0x4a10)) goto LAB_0001f180;
  iVar9 = *(int *)(param_1 + 0x4a6c);
  if (iVar9 != 0) {
    iVar2 = _gleOffsetLimitImage(param_1 + 0x31cc,param_6,param_7,param_8,param_9,param_10);
    iVar11 = *(int *)(iVar9 + 0x38);
    dVar12 = (double)((double (*)())_gleBytesPerElement)(param_9);
    iVar3 = (int)dVar12;
    if (iVar11 < iVar2) {
LAB_0001f180:
      if (*(int *)(param_1 + 0x7574) == 0) {
        *(undefined4 *)(param_1 + 0x7574) = 0x502;
      }
      return iVar3;
    }
    if (iVar3 == 0) {
      iVar3 = _glePixelBytes(param_8,param_9);
    }
    if (param_10 != (param_10 / iVar3) * iVar3) goto LAB_0001f180;
    param_10 = param_10 + *(int *)(iVar9 + 0x30);
  }
  if (param_6 == 0) {
    return iVar3;
  }
  if (param_7 == 0) {
    return iVar3;
  }
  iVar3 = ((int (*)())_gleCheckTexSubImage2DArgs)(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9);
  if (iVar3 == 0) {
    return 0;
  }
  uVar1 = param_2 - 0x8515;
  if (5 < uVar1) {
    uVar1 = 0;
  }
  iVar2 = iVar3 + uVar1 * 0x168 + param_3 * 0x18;
  iVar10 = iVar2 + 0xc4;
  iVar11 = ((int (*)())_checkFastPath)(param_1,iVar10,param_4,param_5,0,param_6,param_7,param_8,param_9,param_10)
  ;
  if ((((iVar11 != 0) && ((int)(uint)*(byte *)(iVar3 + 0x8d) <= (int)param_3)) &&
      ((int)param_3 <= (int)(uint)*(byte *)(iVar3 + 0x8f))) &&
     (iVar11 = uVar1 * 2, (*(ushort *)(iVar11 + iVar3 + 0x94) >> (param_3 & 0x3f) & 1) != 0)) {
    if (iVar9 == 0) {
      uVar5 = *(undefined4 *)(param_1 + 0x4688);
      uVar6 = *(undefined4 *)(iVar3 + (uint)*(byte *)(param_1 + 0x85a8) * 4);
    }
    else {
      iVar4 = (**(code **)(param_1 + 0x4710))
                        (*(undefined4 *)(param_1 + 0x4688),
                         *(undefined4 *)(iVar3 + (uint)*(byte *)(param_1 + 0x85a8) * 4),uVar1,
                         param_3,param_4,param_5,0,param_6);
      if (iVar4 != 0) goto LAB_0001f388;
      if (*(int *)(iVar9 + 0x40) != 0) {
        _gleSynchronizePluginBuffer(param_1,iVar9 + 0x10);
      }
      uVar5 = *(undefined4 *)(param_1 + 0x4688);
      uVar6 = *(undefined4 *)(iVar3 + (uint)*(byte *)(param_1 + 0x85a8) * 4);
    }
    iVar4 = (**(code **)(param_1 + 0x4710))(uVar5,uVar6,uVar1,param_3,param_4,param_5,0,param_6);
    if (iVar4 != 0) {
LAB_0001f388:
      *(undefined4 *)(iVar3 + 0x20) =
           *(undefined4 *)
            ((uint)*(byte *)(param_1 + 0x85a8) * 4 + *(int *)(param_1 + 0x5148) + 0x8054);
      if (*(int *)(iVar2 + 0xd8) != 0) {
        bVar7 = *(byte *)(iVar2 + 0xcf);
        if (((bVar7 & 1) == 0) && (*(short *)(iVar3 + 0x3e) == -0x7a43)) {
          iVar4 = _gleFreeTextureLevel(param_1,iVar3,iVar10);
          bVar7 = *(byte *)(iVar2 + 0xcf);
        }
        *(byte *)(iVar2 + 0xcf) = bVar7 & 0xef;
        *(ushort *)(iVar11 + iVar3 + 0xa0) =
             *(ushort *)(iVar11 + iVar3 + 0xa0) &
             ((ushort)(-2 << (param_3 & 0x1f)) | (ushort)(0xfffffffe >> 0x20 - (param_3 & 0x1f)));
      }
      *(byte *)(iVar2 + 0xcf) = *(byte *)(iVar2 + 0xcf) | 0x40;
      if ((*(uint *)(iVar3 + 0x6c) & 0x8000) == 0) {
        return iVar4;
      }
      if ((int)*(short *)(iVar3 + 0x60) != param_3) {
        return iVar4;
      }
      uVar8 = param_3 + 1;
      if ((int)(uint)*(byte *)(iVar3 + 0x83) < (int)uVar8) {
        return iVar4;
      }
      iVar9 = uVar8 * 0x18 + uVar1 * 0x168 + iVar3 + 0xc4;
      do {
        if (*(int *)(iVar9 + 0x14) != 0) {
          if (((*(byte *)(iVar9 + 0xb) & 1) == 0) && (*(short *)(iVar3 + 0x3e) == -0x7a43)) {
            iVar4 = _gleFreeTextureLevel(param_1,iVar3,iVar9);
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
        _gleAllocateTextureLevel(param_1,iVar3,iVar10);
        bVar7 = *(byte *)(iVar2 + 0xcf);
      }
      *(byte *)(iVar2 + 0xcf) = bVar7 | 0x10;
    }
    else {
      _gleUploadPluginTextureLevel
                (param_1,iVar3,iVar10,uVar1,param_3,(uint)*(byte *)(param_1 + 0x85a8));
    }
  }
  ((int (*)())_gleModifyPluginTextureLevel)(param_1,iVar3,iVar10,uVar1,param_3,param_4,param_5,0,param_6,param_7,1);
  uVar5 = _gleTextureImagePut(param_1,iVar10,param_4 + (uint)*(byte *)(iVar2 + 0xce),
                              param_5 + (uint)*(byte *)(iVar2 + 0xce),0,param_6,param_7,1,param_8,
                              param_9,1,param_1 + 0x31cc,param_10);
  if ((((*(uint *)(iVar3 + 0x6c) & 0x8000) != 0) && ((int)*(short *)(iVar3 + 0x60) == param_3)) &&
     (iVar3 = _gleGenMipmapsToLevel(param_1,iVar3,uVar1,param_3,0xf,1), uVar5 = 0, iVar3 != 0)) {
    return iVar3;
  }
  *(uint *)(param_1 + 0x314) =
       *(uint *)(param_1 + 0x314) | 1 << (*(uint *)(param_1 + 0x53d4) & 0x3f);
  return uVar5;
}

/* _gleCheckTexSubImage2DArgs @ 0x1f618 (484 bytes) */
int _gleCheckTexSubImage2DArgs(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9)
  int param_1;
  int param_2;
  int param_3;
  uint param_4;
  uint param_5;
  uint param_6;
  uint param_7;
  int param_8;
  undefined4 param_9;
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar3 = ((int (*)())_gleLookUpNonProxyTexture2D)(param_1,param_2);
  if (iVar3 == 0) {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return 0;
    }
    uVar1 = 0x500;
  }
  else {
    if ((param_8 != 0x1902) || (*(short *)(iVar3 + 0x26) == 0x1902)) {
      iVar4 = _gleCheckTexSubImageArgs(param_1,param_3,param_8,param_9);
      if (iVar4 == 0) {
        return 0;
      }
      iVar4 = iVar3 + 0xc4 + param_3 * 0x18;
      if (param_2 - 0x8515U < 6) {
        iVar4 = iVar3 + 0xc4 + param_2 * 0x168 + param_3 * 0x18 + -0xbb2588;
      }
      if (((*(byte *)(iVar4 + 0xb) & 0x20) != 0) &&
         ((*(short *)(iVar4 + 0x12) != 0 ||
          (((((param_6 & 3) == 0 || (param_6 == *(ushort *)(iVar4 + 4))) &&
            (((param_7 & 3) == 0 || (param_7 == *(ushort *)(iVar4 + 6))))) &&
           (((param_4 & 3) == 0 && ((param_5 & 3) == 0)))))))) {
        if ((*(uint *)(param_1 + 0x3410) & 2) == 0) {
          if (((*(uint *)(param_1 + 0x3410) & 4) == 0) || (*(short *)(param_1 + 0x3348) != -0x7fea))
          goto LAB_0001f79c;
          iVar5 = *(int *)(param_1 + 0x3354);
          iVar2 = *(int *)(param_1 + 0x3350);
        }
        else {
          if (*(short *)(param_1 + 0x3308) != -0x7fea) goto LAB_0001f79c;
          iVar5 = *(int *)(param_1 + 0x3314);
          iVar2 = *(int *)(param_1 + 0x3310);
        }
        param_6 = (param_6 - iVar2) + 1;
        param_7 = (param_7 - iVar5) + 1;
LAB_0001f79c:
        iVar2 = ((int (*)())_gleCheckTexSubImageRange)(param_1,iVar4,param_4,param_6,(uint)*(ushort *)(iVar4 + 4));
        if (iVar2 == 0) {
          return 0;
        }
        iVar4 = ((int (*)())_gleCheckTexSubImageRange)(param_1,iVar4,param_5,param_7,(uint)*(ushort *)(iVar4 + 6));
        if (iVar4 != 0) {
          return iVar3;
        }
        return 0;
      }
    }
    if (*(int *)(param_1 + 0x7574) != 0) {
      return 0;
    }
    uVar1 = 0x502;
  }
  *(undefined4 *)(param_1 + 0x7574) = uVar1;
  return 0;
}

/* _gleLookUpNonProxyTexture2D @ 0x1f7fc (144 bytes) */
int _gleLookUpNonProxyTexture2D(param_1, param_2)
  int param_1;
  uint param_2;
{
  uint uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x53d4);
  if (param_2 == 0x8513) {
LAB_0001f860:
    iVar2 = *(int *)(iVar2 * 0x14 + param_1 + 0x5154);
  }
  else {
    if (param_2 < 0x8514) {
      if (param_2 == 0xde1) {
        iVar2 = *(int *)(iVar2 * 0x14 + param_1 + 0x5160);
        goto LAB_0001f86c;
      }
      uVar1 = 0x84f5;
    }
    else {
      if (param_2 < 0x8515) {
        return 0;
      }
      if (param_2 < 0x851b) goto LAB_0001f860;
      uVar1 = 0x85b3;
    }
    if (param_2 != uVar1) {
      return 0;
    }
    iVar2 = *(int *)(iVar2 * 0x14 + param_1 + 0x515c);
  }
LAB_0001f86c:
  return iVar2 + 0x10;
}

/* _gleCheckTexSubImageRange @ 0x1f88c (76 bytes) */
int _gleCheckTexSubImageRange(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
  int param_5;
{
  if (((-1 < param_4) && ((int)-(uint)*(byte *)(param_2 + 10) <= param_3)) &&
     (param_3 + param_4 <= (int)(param_5 + (uint)*(byte *)(param_2 + 10)))) {
    return 1;
  }
  if (*(int *)(param_1 + 0x7574) == 0) {
    *(undefined4 *)(param_1 + 0x7574) = 0x501;
  }
  return 0;
}

/* _checkFastPath @ 0x1f8d8 (260 bytes) */
int _checkFastPath(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
  int param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
  undefined4 param_9;
  int param_10;
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
              (param_1,param_8,param_9,param_6,param_7,param_1 + 0x31cc,auStack_40,local_3c,
               &local_50,auStack_4c,auStack_48,auStack_44);
    if ((param_10 + local_3c[0] ==
         iVar5 + iVar3 * ((uint)uVar2 * ((uint)uVar1 * param_5 + param_4) + param_3)) &&
       (local_50 == iVar4)) {
      return 0;
    }
  }
  return 1;
}

/* _gleModifyPluginTextureLevel @ 0x1f9dc (376 bytes) */
int _gleModifyPluginTextureLevel(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11)
  int param_1;
  undefined4 *param_2;
  int *param_3;
  int param_4;
  uint param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
  undefined4 param_9;
  undefined4 param_10;
  undefined4 param_11;
{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  ushort uVar5;
  int iVar6;
  
  if ((*(byte *)((int)param_3 + 0xb) & 0x10) == 0) {
    iVar3 = param_4 * 2 + (int)param_2;
    uVar5 = *(ushort *)(iVar3 + 0xa0) &
            ((ushort)(-2 << (param_5 & 0x1f)) | (ushort)(0xfffffffe >> 0x20 - (param_5 & 0x1f)));
  }
  else {
    iVar3 = param_4 * 2 + (int)param_2;
    uVar5 = *(ushort *)(iVar3 + 0xa0) | *(ushort *)(iVar3 + 0x94) & (ushort)(1 << (param_5 & 0x3f));
  }
  *(ushort *)(iVar3 + 0xa0) = uVar5;
  iVar3 = param_1 + 0x10000;
  iVar6 = 0;
  if (*(char *)(param_1 + 0x85a4) != '\0') {
    do {
      piVar1 = (int *)(iVar3 + -0x777c);
      puVar2 = (undefined4 *)(iVar3 + -0x7a54);
      uVar4 = *param_2;
      iVar3 = iVar3 + 0x2e0;
      iVar6 = iVar6 + 1;
      param_2 = param_2 + 1;
      (**(code **)(*piVar1 + 0x158))(*puVar2,uVar4,param_4,param_5,param_6,param_7,param_8,param_9);
    } while (iVar6 < (int)(uint)*(byte *)(param_1 + 0x85a4));
  }
  if ((*(byte *)((int)param_3 + 0xb) & 0x80) != 0) {
    iVar6 = 0;
    iVar3 = *(int *)(param_1 + 0x744c) + 0x10;
    *(undefined4 *)(*(int *)(param_1 + 0x744c) + 0xec) = 1;
    if (*(char *)(param_1 + 0x85a4) != '\0') {
      do {
        *(undefined4 *)(iVar3 + 0xf8) = 1;
        iVar6 = iVar6 + 1;
        *(undefined4 *)(iVar3 + 0xfc) = 0;
        iVar3 = iVar3 + 0x20;
      } while (iVar6 < (int)(uint)*(byte *)(param_1 + 0x85a4));
    }
    *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x80000000;
  }
  *param_3 = *param_3 + 1;
  return;
}

/* _glTestObjectAPPLE_Exec @ 0x1fb54 (304 bytes) */
int _glTestObjectAPPLE_Exec(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  undefined4 param_3;
{
  undefined4 uVar1;
  
  if (-1 < *(short *)(param_1 + 0x4a10)) {
    if (*(int *)(param_1 + 0x7574) == 0) {
      *(undefined4 *)(param_1 + 0x7574) = 0x502;
    }
    return 1;
  }
  if (param_2 == 0x8a0a) {
    return 1;
  }
  if (param_2 < 0x8a0b) {
    if (param_2 == 0x8074) {
      uVar1 = 2;
    }
    else if (param_2 < 0x8075) {
      if (param_2 != 0x1702) {
LAB_0001fc50:
        if (*(int *)(param_1 + 0x7574) == 0) {
          *(undefined4 *)(param_1 + 0x7574) = 0x500;
        }
        return 0;
      }
      uVar1 = 1;
    }
    else {
      if (param_2 != 0x85b3) goto LAB_0001fc50;
      uVar1 = 3;
    }
  }
  else if (param_2 == 0x8d40) {
    uVar1 = 5;
  }
  else if (param_2 < 0x8d41) {
    if (param_2 != 0x8a0b) goto LAB_0001fc50;
    uVar1 = 0;
  }
  else {
    if (param_2 != 0x8d41) goto LAB_0001fc50;
    uVar1 = 4;
  }
  uVar1 = ((int (*)())_gleTestObject)(param_1,uVar1,param_3);
  return uVar1;
}

/* _gleTestObject @ 0x1fc84 (760 bytes) */
int _gleTestObject(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  uint uVar6;
  
  iVar4 = 1;
  iVar2 = 1;
  switch(param_2) {
  case 0:
    iVar2 = _gleLookupHashObject(param_1 + 0x543c,param_3);
    if (iVar2 == 0) {
LAB_0001ff68:
      if (*(int *)(param_1 + 0x7574) == 0) {
        *(undefined4 *)(param_1 + 0x7574) = 0x502;
      }
    }
    else {
      iVar3 = param_1 + 0x10000;
      uVar6 = 0;
      if (*(char *)(param_1 + 0x85a4) != '\0') {
        puVar5 = (undefined4 *)(iVar2 + 0x10);
        do {
          bVar1 = iVar4 != 0;
          iVar4 = 0;
          if ((bVar1) &&
             (iVar2 = (**(code **)(*(int *)(iVar3 + -0x777c) + 0x1c0))
                                (*(undefined4 *)(iVar3 + -0x7a54),param_2,*puVar5), iVar2 != 0)) {
            iVar4 = 1;
          }
          uVar6 = uVar6 + 1;
          iVar3 = iVar3 + 0x2e0;
          puVar5 = puVar5 + 1;
        } while (uVar6 < *(byte *)(param_1 + 0x85a4));
      }
    }
    break;
  case 1:
    iVar2 = _gleLookupHashObject(*(int *)(param_1 + 0x5148) + 0x2008,param_3);
    if (iVar2 == 0) goto LAB_0001ff68;
    iVar3 = param_1 + 0x10000;
    uVar6 = 0;
    if (*(char *)(param_1 + 0x85a4) != '\0') {
      puVar5 = (undefined4 *)(iVar2 + 0x10);
      do {
        bVar1 = iVar4 != 0;
        iVar4 = 0;
        if ((bVar1) &&
           (iVar2 = (**(code **)(*(int *)(iVar3 + -0x777c) + 0x1c0))
                              (*(undefined4 *)(iVar3 + -0x7a54),param_2,*puVar5), iVar2 != 0)) {
          iVar4 = 1;
        }
        uVar6 = uVar6 + 1;
        iVar3 = iVar3 + 0x2e0;
        puVar5 = puVar5 + 1;
      } while (uVar6 < *(byte *)(param_1 + 0x85a4));
    }
    break;
  case 2:
    iVar2 = _gleLookupHashObject(*(int *)(param_1 + 0x5148) + 0x5014,param_3);
    if (iVar2 == 0) goto LAB_0001ff68;
    iVar3 = param_1 + 0x10000;
    uVar6 = 0;
    if (*(char *)(param_1 + 0x85a4) != '\0') {
      puVar5 = (undefined4 *)(iVar2 + 0x10);
      do {
        bVar1 = iVar4 != 0;
        iVar4 = 0;
        if ((bVar1) &&
           (iVar2 = (**(code **)(*(int *)(iVar3 + -0x777c) + 0x1c0))
                              (*(undefined4 *)(iVar3 + -0x7a54),param_2,*puVar5), iVar2 != 0)) {
          iVar4 = 1;
        }
        uVar6 = uVar6 + 1;
        iVar3 = iVar3 + 0x2e0;
        puVar5 = puVar5 + 1;
      } while (uVar6 < *(byte *)(param_1 + 0x85a4));
    }
    break;
  case 3:
    iVar2 = _gleLookupHashObject(*(int *)(param_1 + 0x5148) + 0x701c,param_3);
    if (iVar2 == 0) goto LAB_0001ff68;
    iVar3 = param_1 + 0x10000;
    uVar6 = 0;
    if (*(char *)(param_1 + 0x85a4) != '\0') {
      puVar5 = (undefined4 *)(iVar2 + 0x10);
      do {
        bVar1 = iVar4 != 0;
        iVar4 = 0;
        if ((bVar1) &&
           (iVar2 = (**(code **)(*(int *)(iVar3 + -0x777c) + 0x1c0))
                              (*(undefined4 *)(iVar3 + -0x7a54),param_2,*puVar5), iVar2 != 0)) {
          iVar4 = 1;
        }
        uVar6 = uVar6 + 1;
        iVar3 = iVar3 + 0x2e0;
        puVar5 = puVar5 + 1;
      } while (uVar6 < *(byte *)(param_1 + 0x85a4));
    }
    break;
  case 4:
    iVar2 = _gleLookupHashObject(((unsigned char *)0x00001004) + *(int *)(param_1 + 0x5148),param_3);
    if (iVar2 == 0) goto LAB_0001ff68;
    iVar3 = param_1 + 0x10000;
    uVar6 = 0;
    if (*(char *)(param_1 + 0x85a4) != '\0') {
      puVar5 = (undefined4 *)(iVar2 + 0x10);
      do {
        bVar1 = iVar4 != 0;
        iVar4 = 0;
        if ((bVar1) &&
           (iVar2 = (**(code **)(*(int *)(iVar3 + -0x777c) + 0x1c0))
                              (*(undefined4 *)(iVar3 + -0x7a54),param_2,*puVar5), iVar2 != 0)) {
          iVar4 = 1;
        }
        uVar6 = uVar6 + 1;
        iVar3 = iVar3 + 0x2e0;
        puVar5 = puVar5 + 1;
      } while (uVar6 < *(byte *)(param_1 + 0x85a4));
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

/* FUN_0001ff98 @ 0x1ff98 (572 bytes) */
int FUN_0001ff98(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int *param_3;
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if (-1 < param_2) {
      if (param_2 == 0) {
        return;
      }
      iVar3 = *(int *)(param_1 + 0x5148);
      piVar6 = (int *)0x0;
      iVar7 = iVar3 + 0x2008;
      if (*(char *)(iVar3 + 0x8024) != '\0') {
        _pthread_mutex_lock(iVar3 + 0x8028);
      }
      iVar3 = *(int *)(param_1 + 0x744c);
      if (iVar3 != 0) {
        piVar6 = (int *)(iVar3 + 0xd4);
      }
      iVar8 = 0;
      iVar9 = *param_3;
      iVar10 = iVar9;
      if (0 < param_2) {
        do {
          if (*param_3 == 0) {
            ((int (*)())_gleDeleteHashNamesAndObjects)(param_1,iVar7,iVar9,iVar10 - iVar9);
            iVar9 = param_3[1];
            iVar10 = iVar9 + -1;
          }
          else {
            uVar11 = 0;
            iVar12 = param_1;
            do {
              piVar5 = (int *)(iVar12 + 0x5154);
              uVar4 = 0;
              do {
                if (*(int *)(*piVar5 + 4) == *param_3) {
                  _gleBindTexture(param_1,uVar4,0,uVar11);
                  break;
                }
                uVar4 = uVar4 + 1;
                piVar5 = piVar5 + 1;
              } while (uVar4 < 5);
              uVar11 = uVar11 + 1;
              iVar12 = iVar12 + 0x14;
            } while (uVar11 < 0x10);
            if ((iVar3 != 0) && (iVar12 = _gleLookupHashObject(iVar7,*param_3), iVar12 != 0)) {
              uVar11 = 0;
              piVar5 = piVar6;
              do {
                iVar2 = *piVar5;
                piVar5 = piVar5 + 1;
                if (iVar12 == iVar2) {
                  _gleFramebufferTexture(param_1,uVar11,0,0,0,0,0);
                }
                uVar11 = uVar11 + 1;
              } while (uVar11 < 6);
            }
            if (*param_3 != iVar10) {
              ((int (*)())_gleDeleteHashNamesAndObjects)(param_1,iVar7,iVar9,iVar10 - iVar9);
              iVar9 = *param_3;
              iVar10 = iVar9;
            }
          }
          iVar8 = iVar8 + 1;
          param_3 = param_3 + 1;
          iVar10 = iVar10 + 1;
        } while (iVar8 < param_2);
      }
      ((int (*)())_gleDeleteHashNamesAndObjects)(param_1,iVar7,iVar9,iVar10 - iVar9);
      if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) == '\0') {
        return;
      }
      _pthread_mutex_unlock(*(int *)(param_1 + 0x5148) + 0x8028);
      return;
    }
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar1 = 0x501;
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

/* _gleDeleteHashNamesAndObjects @ 0x201d4 (340 bytes) */
int _gleDeleteHashNamesAndObjects(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  int param_2;
  uint param_3;
  int param_4;
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
  
  uVar6 = param_3 + param_4;
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
      if (param_3 < uVar8) break;
LAB_00020304:
      piVar2 = (int *)*piVar11;
      piVar5 = piVar11;
    }
    uVar7 = param_3;
    if (param_3 < uVar9) {
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
        (**(code **)(iVar4 + 0xc))(param_1);
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
int _gleFreeTextureObject(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  ushort uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  iVar3 = param_2 + 0x10;
  ((int (*)())_gleDeletePluginTexture)(param_1,iVar3);
  uVar1 = *(ushort *)(param_2 + 0x34);
  if ((uVar1 & 0x100) == 0) {
    if ((*(int *)(param_2 + 0xd0) != 0) && ((*(byte *)(param_2 + 199) & 7) == 0)) {
      _gleFreeTextureLevel(param_1,iVar3,param_2 + 0xbc);
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
    iVar4 = 0;
    if (iVar2 != 0) {
      iVar5 = 0;
      do {
        iVar6 = 0xe;
        iVar7 = param_2 + iVar5 + 0xd4;
        do {
          if ((*(int *)(iVar7 + 0x14) != 0) && ((*(byte *)(iVar7 + 0xb) & 7) == 0)) {
            _gleFreeTextureLevel(param_1,iVar3,iVar7);
          }
          iVar6 = iVar6 + -1;
          iVar7 = iVar7 + 0x18;
        } while (-1 < iVar6);
        iVar4 = iVar4 + 1;
        iVar5 = iVar5 + 0x168;
      } while (iVar4 < iVar2);
    }
  }
  _free(param_2);
  return;
}

/* _gleDeletePluginTexture @ 0x204a0 (120 bytes) */
int _gleDeletePluginTexture(param_1, param_2)
  int param_1;
  int param_2;
{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = param_1 + 0x10000;
  iVar5 = 0;
  if (*(char *)(param_1 + 0x85a4) != '\0') {
    do {
      piVar1 = (int *)(iVar4 + -0x777c);
      iVar3 = iVar5 * 4;
      puVar2 = (undefined4 *)(iVar4 + -0x7a54);
      iVar4 = iVar4 + 0x2e0;
      iVar5 = iVar5 + 1;
      (**(code **)(*piVar1 + 0x168))(*puVar2,*(undefined4 *)(iVar3 + param_2));
      *(undefined4 *)(iVar3 + param_2) = 0;
    } while (iVar5 < (int)(uint)*(byte *)(param_1 + 0x85a4));
  }
  return;
}

/* _gleSetEnable_SCISSOR_TEST @ 0x20518 (72 bytes) */
void _gleSetEnable_SCISSOR_TEST(int param_1,undefined4 param_2,uint param_3,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  if (*(byte *)(param_1 + 0x34f0) != param_3) {
    *(char *)(param_1 + 0x34f0) = (char)param_3;
    ((void (*)())_gleUpdateViewScissorData)(param_1,fparam_1,fparam_2,fparam_3,fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
    *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x4000000;
  }
  return;
}

/* _glScissor_Exec @ 0x20560 (144 bytes) */
void _glScissor_Exec(int param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  undefined4 uVar1;
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if ((-1 < param_4) && (-1 < param_5)) {
      *(undefined4 *)(param_1 + 0x34e0) = param_2;
      *(undefined4 *)(param_1 + 0x34e4) = param_3;
      *(int *)(param_1 + 0x34e8) = param_4;
      *(int *)(param_1 + 0x34ec) = param_5;
      ((void (*)())_gleUpdateViewScissorData)(param_1,fparam_1,fparam_2,fparam_3,fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
      *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x4000000;
      return;
    }
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar1 = 0x501;
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

/* _gleMoveFuncCacheElem @ 0x205f0 (44 bytes) */
int _gleMoveFuncCacheElem(param_1, param_2)
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
int _gliSetInteger(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  int *param_3;
{
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
  if ((param_1 == 0) || (*(int *)(param_1 + 0x467c) != 0x3463a223)) {
    return 0x2714;
  }
  if (param_3 == (int *)0x0) {
    return 0x271e;
  }
  if (param_2 == 0x176) {
    iVar10 = *param_3;
    if (iVar10 < 1) {
      return 0x2718;
    }
    *(short *)(param_1 + 0x49c0) = (short)iVar10;
    if (*(short *)(param_1 + 0x49c2) <= iVar10) {
      return 0;
    }
    uVar5 = *(undefined4 *)(param_1 + 0x49b8);
    iVar13 = *(short *)(param_1 + 0x49c2) - iVar10;
    *(short *)(param_1 + 0x49c2) = (short)iVar10;
LAB_0002085c:
    _gleShrinkFuncCache(uVar5,iVar13);
  }
  else {
    if (param_2 < 0x177) {
      if (param_2 == 0x133) {
        *(char *)(param_1 + 0x5410) = '\x01' - (*param_3 == 0);
        return 0;
      }
      if (0x133 < param_2) {
        if (param_2 == 0x162) {
          iVar10 = *param_3;
          if (iVar10 < 4) {
            return 0x2718;
          }
          *(short *)(param_1 + 0x5098) = (short)iVar10;
          if (*(short *)(param_1 + 0x509a) <= iVar10) {
            return 0;
          }
          uVar5 = *(undefined4 *)(param_1 + 0x5094);
          iVar13 = *(short *)(param_1 + 0x509a) - iVar10;
          *(short *)(param_1 + 0x509a) = (short)iVar10;
        }
        else if (param_2 < 0x163) {
          if (param_2 == 0x134) {
            _gleReclaimContextResources(param_1);
            return 0;
          }
          if (param_2 != 0x15e) goto LAB_00020f04;
          iVar10 = *param_3;
          if (iVar10 < 4) {
            return 0x2718;
          }
          *(short *)(param_1 + 0x508c) = (short)iVar10;
          if (*(short *)(param_1 + 0x508e) <= iVar10) {
            return 0;
          }
          uVar5 = *(undefined4 *)(param_1 + 0x5088);
          iVar13 = *(short *)(param_1 + 0x508e) - iVar10;
          *(short *)(param_1 + 0x508e) = (short)iVar10;
        }
        else if (param_2 == 0x16a) {
          iVar10 = *param_3;
          if (iVar10 < 1) {
            return 0x2718;
          }
          *(short *)(param_1 + 0x48b4) = (short)iVar10;
          if (*(short *)(param_1 + 0x48b6) <= iVar10) {
            return 0;
          }
          uVar5 = *(undefined4 *)(param_1 + 0x48b0);
          iVar13 = *(short *)(param_1 + 0x48b6) - iVar10;
          *(short *)(param_1 + 0x48b6) = (short)iVar10;
        }
        else if (param_2 < 0x16b) {
          if (param_2 != 0x166) goto LAB_00020f04;
          iVar10 = *param_3;
          if (iVar10 < 1) {
            return 0x2718;
          }
          *(short *)(param_1 + 0x50a4) = (short)iVar10;
          if (*(short *)(param_1 + 0x50a6) <= iVar10) {
            return 0;
          }
          uVar5 = *(undefined4 *)(param_1 + 0x50a0);
          iVar13 = *(short *)(param_1 + 0x50a6) - iVar10;
          *(short *)(param_1 + 0x50a6) = (short)iVar10;
        }
        else {
          if (param_2 != 0x172) goto LAB_00020f04;
          iVar10 = *param_3;
          if (iVar10 < 1) {
            return 0x2718;
          }
          *(short *)(param_1 + 0x49bc) = (short)iVar10;
          if (*(short *)(param_1 + 0x49be) <= iVar10) {
            return 0;
          }
          uVar5 = *(undefined4 *)(param_1 + 0x49b4);
          iVar13 = *(short *)(param_1 + 0x49be) - iVar10;
          *(short *)(param_1 + 0x49be) = (short)iVar10;
        }
        goto LAB_0002085c;
      }
      if (param_2 == 0xe5) {
        *(char *)(param_1 + 0x4693) = '\x01' - (*param_3 == 0);
        return 0;
      }
      if (param_2 < 0xe6) {
        if (param_2 == 0xdd) {
          uVar8 = 0;
          *(char *)(param_1 + 0x4690) = '\x01' - (*param_3 == 0);
          if ((*(char *)(param_1 + 0x4690) == '\0') || (*(int *)(param_1 + 0x4848) == 0)) {
            uVar8 = 1;
          }
          uVar4 = 0;
          *(undefined1 *)(param_1 + 0x4692) = uVar8;
          if ((*(int *)(param_1 + 0x4e1c) == 0x1c00) && (*(char *)(param_1 + 0x4692) == '\0')) {
            uVar4 = 1;
          }
          *(undefined1 *)(param_1 + 0x4691) = uVar4;
          *(undefined4 *)(param_1 + 0x757c) = 0xffffffff;
          _gliSetCurrentPluginDispatchTable(param_1);
          return 0;
        }
        if (param_2 == 0xe4) {
          *(int *)(param_1 + 0x7590) = *param_3;
          return 0;
        }
LAB_00020f04:
        iVar13 = param_1 + 0x10000;
        iVar16 = 0;
        if (*(char *)(param_1 + 0x85a4) != '\0') {
          do {
            iVar7 = (**(code **)(*(int *)(iVar13 + -0x777c) + 0x140))
                              (*(undefined4 *)(iVar13 + -0x7a54),param_2,param_3);
            if ((iVar7 != 0) && (iVar10 == 0)) {
              iVar10 = iVar7;
            }
            iVar16 = iVar16 + 1;
            iVar13 = iVar13 + 0x2e0;
          } while (iVar16 < (int)(uint)*(byte *)(param_1 + 0x85a4));
          return iVar10;
        }
        return 0;
      }
      if (param_2 != 0x128) {
        if (param_2 == 0x132) {
          *(char *)(param_1 + 0x4694) = '\x01' - (*param_3 == 0);
        }
        goto LAB_00020f04;
      }
      if (-1 < *(short *)(param_1 + 0x4a10)) goto LAB_00020c88;
      uVar14 = param_3[1];
      iVar9 = param_3[7];
      iVar10 = *param_3;
      iVar11 = param_3[2];
      iVar13 = param_3[3];
      iVar7 = param_3[4];
      iVar16 = param_3[5];
      iVar12 = param_3[6];
      if (uVar14 == 0xde1) {
LAB_00020a7c:
        iVar6 = _gleCheckTexImage2DArgs
                          (param_1,uVar14,iVar11,iVar13,iVar7,iVar16,iVar9,0x80e1,0x1401);
      }
      else if (uVar14 < 0xde2) {
        if (uVar14 != 0xde0) {
          return 0x2717;
        }
        iVar6 = _gleCheckTexImage1DArgs(param_1,0xde0,iVar11,iVar13,iVar7,iVar9,0x80e1,0x1401);
      }
      else {
        if (uVar14 != 0x806f) {
          if (uVar14 != 0x84f5) {
            return 0x2717;
          }
          goto LAB_00020a7c;
        }
        iVar6 = ((int (*)())_gleCheckTexImage3DArgs)(param_1,0x806f,iVar11,iVar13,iVar7,iVar16,iVar12,iVar9,0x80e1,0x1401);
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
          if (*(int *)(param_1 + 0x7574) == 0) {
            *(undefined4 *)(param_1 + 0x7574) = 0x502;
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
        _gleDeletePluginTextureLevel(param_1,iVar6,iVar15,uVar14,iVar11);
        if (*(int *)(iVar10 + 0xd8) != 0) {
          bVar1 = *(byte *)(iVar10 + 0xcf);
          if ((bVar1 & 1) == 0) {
            _gleFreeTextureLevel(param_1,iVar6,iVar15);
            bVar1 = *(byte *)(iVar10 + 0xcf);
          }
          else {
            *(undefined4 *)(iVar10 + 0xd8) = 0;
          }
          *(byte *)(iVar10 + 0xcf) = bVar1 & 0xef;
        }
        *(byte *)(iVar10 + 0xcf) = *(byte *)(iVar10 + 0xcf) & 0xdf;
      }
      _gleCreateGlobalLevel(param_1,iVar15,iVar7,iVar16,iVar12,iVar9);
      _gleCreatePluginTextureLevel(param_1,iVar6,iVar15,uVar14,iVar11,iVar13);
    }
    else {
      if (param_2 == 0x3e1) {
        iVar10 = *(int *)(param_1 + 0x5408);
        *(char *)(param_1 + 0x7586) = '\x01' - (*param_3 == 0);
joined_r0x00020e50:
        if (iVar10 != 0) {
          return 0;
        }
        _gliExecDispatchTable(param_1);
        return 0;
      }
      if (param_2 < 0x3e2) {
        if (param_2 == 0x184) {
          iVar10 = *param_3;
          if (iVar10 < 1) {
            return 0x2718;
          }
          *(short *)(param_1 + 0x48bc) = (short)iVar10;
          if (*(short *)(param_1 + 0x48be) <= iVar10) {
            return 0;
          }
          uVar5 = *(undefined4 *)(param_1 + 0x48b8);
          iVar13 = *(short *)(param_1 + 0x48be) - iVar10;
          *(short *)(param_1 + 0x48be) = (short)iVar10;
        }
        else if (param_2 < 0x185) {
          if (param_2 == 0x17c) {
            iVar10 = *param_3;
            if (iVar10 < 1) {
              return 0x2718;
            }
            *(short *)(param_1 + 0x48a4) = (short)iVar10;
            if (*(short *)(param_1 + 0x48a6) <= iVar10) {
              return 0;
            }
            uVar5 = *(undefined4 *)(param_1 + 0x48a0);
            iVar13 = *(short *)(param_1 + 0x48a6) - iVar10;
            *(short *)(param_1 + 0x48a6) = (short)iVar10;
          }
          else {
            if (param_2 != 0x180) goto LAB_00020f04;
            iVar10 = *param_3;
            if (iVar10 < 1) {
              return 0x2718;
            }
            *(short *)(param_1 + 0x48ac) = (short)iVar10;
            if (*(short *)(param_1 + 0x48ae) <= iVar10) {
              return 0;
            }
            uVar5 = *(undefined4 *)(param_1 + 0x48a8);
            iVar13 = *(short *)(param_1 + 0x48ae) - iVar10;
            *(short *)(param_1 + 0x48ae) = (short)iVar10;
          }
        }
        else {
          if (param_2 != 0x188) {
            if (param_2 == 0x3e0) {
              iVar10 = *(int *)(param_1 + 0x5408);
              *(char *)(param_1 + 0x7587) = '\x01' - (*param_3 == 0);
              goto joined_r0x00020e50;
            }
            goto LAB_00020f04;
          }
          iVar10 = *param_3;
          if (iVar10 < 1) {
            return 0x2718;
          }
          *(short *)(param_1 + 0x48c4) = (short)iVar10;
          if (*(short *)(param_1 + 0x48c6) <= iVar10) {
            return 0;
          }
          uVar5 = *(undefined4 *)(param_1 + 0x48c0);
          iVar13 = *(short *)(param_1 + 0x48c6) - iVar10;
          *(short *)(param_1 + 0x48c6) = (short)iVar10;
        }
        goto LAB_0002085c;
      }
      if (999 < param_2) {
        if (param_2 == 0x6a7) {
          *(int *)(param_1 + 0x7594) = *param_3;
          return 0;
        }
        if (param_2 == 0x6a8) {
          *(int *)(param_1 + 0x7598) = *param_3;
          return 0;
        }
        goto LAB_00020f04;
      }
      if (param_2 < 0x3e5) {
        if (param_2 == 0x3e2) {
          *(char *)(param_1 + 0x7584) = '\x01' - (*param_3 == 0);
          return 0;
        }
        if (param_2 == 0x3e4) {
          *(char *)(param_1 + 0x53e7) = '\x01' - (*param_3 == 0);
          *(char *)(param_1 + 0x7585) = '\x01' - (*param_3 == 0);
          return 0;
        }
        goto LAB_00020f04;
      }
      iVar9 = param_3[1];
      iVar13 = param_3[2];
      iVar7 = param_3[3];
      iVar16 = param_3[4];
      iVar11 = *param_3;
      iVar10 = _gleCheckTexImage2DArgs(param_1,iVar9,0,iVar13,iVar7,iVar16,0,0x80e1,0x8367);
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
      if (param_2 != 0x3e5) {
        uVar3 = 0x404;
      }
      else {
        uVar3 = *(undefined2 *)((int)param_3 + 0x1a);
      }
      *(undefined2 *)(iVar10 + 0x30) = uVar3;
      iVar11 = 6;
      if (iVar9 != 0x8513) {
        iVar11 = 1;
      }
      iVar9 = 0;
      if (iVar11 != 0) {
        iVar12 = iVar10 + 0xc4;
        do {
          if ((*(byte *)(iVar12 + 0xb) & 0x20) != 0) {
            _gleDeletePluginTextureLevel(param_1,iVar10,iVar12,0,0);
            if (*(int *)(iVar12 + 0x14) != 0) {
              bVar1 = *(byte *)(iVar12 + 0xb);
              if ((bVar1 & 1) == 0) {
                _gleFreeTextureLevel(param_1,iVar10,iVar12);
                bVar1 = *(byte *)(iVar12 + 0xb);
              }
              else {
                *(undefined4 *)(iVar12 + 0x14) = 0;
              }
              *(byte *)(iVar12 + 0xb) = bVar1 & 0xef;
            }
            *(byte *)(iVar12 + 0xb) = *(byte *)(iVar12 + 0xb) & 0xdf;
          }
          ((int (*)())_gleCreateSurfaceLevel)(param_1,iVar12,iVar7,iVar16,0,0);
          if (param_2 != 0x3e5) {
            iVar6 = 0;
          }
          else {
            iVar6 = param_3[7];
          }
          uVar5 = _gleReqToBase(iVar13);
          _gleCreatePluginTextureLevel(param_1,iVar10,iVar12,iVar9,0,uVar5);
          if (iVar6 != 0) {
            _gleGenSurfaceMipmaps(param_1,iVar10,iVar9,iVar6,*(uint *)(iVar10 + 0x6c) >> 0xf & 1);
          }
          iVar9 = iVar9 + 1;
          iVar12 = iVar12 + 0x168;
        } while (iVar9 < iVar11);
      }
    }
    *(uint *)(param_1 + 0x314) =
         *(uint *)(param_1 + 0x314) | 1 << (*(uint *)(param_1 + 0x53d4) & 0x3f);
  }
  return 0;
}

/* _gleCreateSurfaceLevel @ 0x20f84 (60 bytes) */
int _gleCreateSurfaceLevel(param_1, param_2, param_3, param_4, param_5, param_6)
  undefined4 param_1;
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
int _glFlushRender_Exec(param_1)
  int param_1;
{
  if (*(short *)(param_1 + 0x4a10) < 0) {
                    
                    
    (**(code **)(param_1 + 0x47b4))(*(undefined4 *)(param_1 + 0x4688));
    return;
  }
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  *(undefined4 *)(param_1 + 0x7574) = 0x502;
  return;
}

/* _glGetFloatv_Exec @ 0x20ff4 (280 bytes) */
int _glGetFloatv_Exec(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  float *param_3;
{
  undefined4 uVar1;
  uint uVar2;
  double *pdVar3;
  int iVar4;
  double dVar5;
  undefined1 auStack_b0 [16];
  double local_a0 [16];
  undefined4 local_20;
  uint uStack_1c;
  int local_18 [2];
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    pdVar3 = local_a0;
    iVar4 = _gleGetState(param_1,param_2,pdVar3,local_18,auStack_b0);
    dVar5 = DOUBLE_00108d58;
    if (iVar4 == 0) {
      if (*(int *)(param_1 + 0x7574) != 0) {
        return;
      }
      uVar1 = 0x500;
      goto LAB_00021068;
    }
    if (iVar4 != -1) {
      if (local_18[0] != 0x1404) {
        if (iVar4 < 1) {
          return;
        }
        do {
          dVar5 = *pdVar3;
          pdVar3 = pdVar3 + 1;
          *param_3 = (float)dVar5;
          param_3 = param_3 + 1;
          iVar4 = iVar4 + -1;
        } while (iVar4 != 0);
        return;
      }
      if (iVar4 < 1) {
        return;
      }
      do {
        uVar2 = *(uint *)pdVar3;
        pdVar3 = pdVar3 + 1;
        local_20 = 0x43300000;
        uStack_1c = uVar2 ^ 0x80000000;
        *param_3 = (float)((double)CONCAT44(0x43300000,uVar2 ^ 0x80000000) - dVar5);
        param_3 = param_3 + 1;
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
      return;
    }
  }
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  uVar1 = 0x502;
LAB_00021068:
  *(undefined4 *)(param_1 + 0x7574) = uVar1;
  return;
}

/* _glGetProgramivARB_Exec @ 0x2110c (2084 bytes) */
int _glGetProgramivARB_Exec(param_1, param_2, param_3, param_4)
  int param_1;
  uint param_2;
  uint param_3;
  uint *param_4;
{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  uint local_30 [5];
  
  if (-1 < *(short *)(param_1 + 0x4a10)) {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar3 = 0x502;
    goto LAB_0002190c;
  }
  if (param_2 == 0x8620) {
    uVar4 = 0;
LAB_00021188:
    iVar5 = *(int *)(uVar4 * 4 + param_1 + 0x5420);
    if (param_3 == 0x88a6) goto LAB_000216f4;
    if (param_3 < 0x88a7) {
      if (param_3 == 0x880d) {
LAB_00021804:
        uVar2 = 0;
        if (uVar4 != 0) {
          uVar2 = (uint)*(ushort *)(*(int *)(param_1 + 0x468c) + 0x110);
        }
        goto LAB_00021914;
      }
      if (param_3 < 0x880e) {
        if (param_3 == 0x8807) {
          uVar2 = (uint)*(ushort *)(iVar5 + 0x4f0);
          goto LAB_00021914;
        }
        if (0x8807 < param_3) {
          if (param_3 == 0x880b) {
LAB_000217d4:
            uVar2 = 0;
            if (uVar4 != 0) {
              uVar2 = (uint)*(ushort *)(*(int *)(param_1 + 0x468c) + 0x10c);
            }
            goto LAB_00021914;
          }
          if (0x880b < param_3) goto LAB_000217ec;
          goto LAB_000216f4;
        }
        if (param_3 == 0x8677) {
          uVar2 = *(uint *)(iVar5 + 4);
          goto LAB_00021914;
        }
        if (param_3 < 0x8678) {
          if (param_3 == 0x8627) {
            uVar2 = *(uint *)(iVar5 + 0x18);
            goto LAB_00021914;
          }
        }
        else {
          if (param_3 == 0x8805) {
            uVar2 = (uint)*(ushort *)(iVar5 + 0x4ec);
            goto LAB_00021914;
          }
          if (param_3 == 0x8806) {
            uVar2 = (uint)*(ushort *)(iVar5 + 0x4ee);
            goto LAB_00021914;
          }
        }
      }
      else {
        if (param_3 == 0x88a0) {
          uVar2 = (uint)*(ushort *)(iVar5 + 0x50);
          goto LAB_00021914;
        }
        if (param_3 < 0x88a1) {
          if (param_3 == 0x880f) {
LAB_000217ec:
            uVar2 = 0;
            if (uVar4 != 0) {
              uVar2 = (uint)*(ushort *)(*(int *)(param_1 + 0x468c) + 0x10e);
            }
            goto LAB_00021914;
          }
          if (param_3 < 0x880f) goto LAB_000217d4;
          if (param_3 == 0x8810) goto LAB_00021804;
          if (param_3 == 0x8876) {
            uVar2 = *(uint *)(iVar5 + 0x1c);
            goto LAB_00021914;
          }
        }
        else {
          if (param_3 == 0x88a3) {
            uVar2 = (uint)*(ushort *)(uVar4 * 0x10 + *(int *)(param_1 + 0x468c) + 0xec);
            goto LAB_00021914;
          }
          if (param_3 < 0x88a4) {
            if (param_3 == 0x88a1) {
              uVar2 = 0x8000;
              if (uVar4 != 0) {
                uVar2 = (uint)*(ushort *)(*(int *)(param_1 + 0x468c) + 0xfc);
              }
              goto LAB_00021914;
            }
            uVar4 = 0x88a2;
            goto LAB_00021354;
          }
          if (param_3 == 0x88a4) {
            uVar2 = (uint)*(ushort *)(iVar5 + 0x56);
            goto LAB_00021914;
          }
          if (param_3 == 0x88a5) {
            uVar2 = 0x100;
            if (uVar4 != 0) {
              uVar2 = (uint)*(ushort *)(*(int *)(param_1 + 0x468c) + 0x102);
            }
            goto LAB_00021914;
          }
        }
      }
    }
    else {
      if (param_3 == 0x88b1) {
        uVar2 = (uVar4 ^ 1) << 1;
        goto LAB_00021914;
      }
      if (param_3 < 0x88b2) {
        if (param_3 == 0x88ab) {
          uVar2 = (uint)*(ushort *)(uVar4 * 0x10 + *(int *)(param_1 + 0x468c) + 0xf0);
          goto LAB_00021914;
        }
        if (param_3 < 0x88ac) {
          if (param_3 == 0x88a8) {
            uVar2 = (uint)*(ushort *)(iVar5 + 0x54);
            goto LAB_00021914;
          }
          if (param_3 < 0x88a8) {
            uVar2 = (uint)*(ushort *)(uVar4 * 0x10 + *(int *)(param_1 + 0x468c) + 0xf2);
            goto LAB_00021914;
          }
          if (param_3 == 0x88a9) {
            uVar2 = 0x100;
            if (uVar4 != 0) {
              uVar2 = (uint)*(ushort *)(*(int *)(param_1 + 0x468c) + 0x100);
            }
            goto LAB_00021914;
          }
          uVar4 = 0x88aa;
LAB_00021354:
          if (param_3 == uVar4) {
LAB_000216f4:
            (**(code **)(param_1 + 0x47dc))
                      (*(undefined4 *)(param_1 + 0x4688),
                       *(undefined4 *)((uint)*(byte *)(param_1 + 0x85a8) * 4 + iVar5 + 0x4a8),
                       param_3,local_30);
            uVar2 = local_30[0];
LAB_00021914:
            local_30[0] = uVar2;
            *param_4 = local_30[0];
            return;
          }
        }
        else {
          if (param_3 == 0x88ae) goto LAB_000216f4;
          if (param_3 < 0x88af) {
            if (param_3 == 0x88ac) {
              uVar2 = (uint)*(ushort *)(iVar5 + 0x52);
              goto LAB_00021914;
            }
            if (param_3 == 0x88ad) {
              uVar2 = 0x20;
              if (uVar4 != 0) {
                uVar2 = (uint)*(ushort *)(*(int *)(param_1 + 0x468c) + 0xfe);
              }
              goto LAB_00021914;
            }
          }
          else {
            if (param_3 == 0x88af) {
              uVar2 = (uint)*(ushort *)(uVar4 * 0x10 + *(int *)(param_1 + 0x468c) + 0xee);
              goto LAB_00021914;
            }
            if (param_3 == 0x88b0) {
              uVar2 = (uint)*(ushort *)(iVar5 + 0x4e);
              goto LAB_00021914;
            }
          }
        }
      }
      else {
        if (param_3 == 0x88b6) {
          iVar1 = uVar4 * 0x10;
          uVar2 = 0;
          if (*(short *)(iVar1 + *(int *)(param_1 + 0x468c) + 0xec) == 0) goto LAB_00021914;
          (**(code **)(param_1 + 0x47dc))
                    (*(undefined4 *)(param_1 + 0x4688),
                     *(undefined4 *)((uint)*(byte *)(param_1 + 0x85a8) * 4 + iVar5 + 0x4a8),0x88a2,
                     local_30);
          if (((((int)local_30[0] <=
                 (int)(uint)*(ushort *)(iVar1 + *(int *)(param_1 + 0x468c) + 0xec)) &&
               ((**(code **)(param_1 + 0x47dc))
                          (*(undefined4 *)(param_1 + 0x4688),
                           *(undefined4 *)((uint)*(byte *)(param_1 + 0x85a8) * 4 + iVar5 + 0x4a8),
                           0x88aa,local_30),
               (int)local_30[0] <= (int)(uint)*(ushort *)(iVar1 + *(int *)(param_1 + 0x468c) + 0xf0)
               )) && ((**(code **)(param_1 + 0x47dc))
                                (*(undefined4 *)(param_1 + 0x4688),
                                 *(undefined4 *)
                                  ((uint)*(byte *)(param_1 + 0x85a8) * 4 + iVar5 + 0x4a8),0x88a6,
                                 local_30),
                     (int)local_30[0] <=
                     (int)(uint)*(ushort *)(iVar1 + *(int *)(param_1 + 0x468c) + 0xf2))) &&
             ((**(code **)(param_1 + 0x47dc))
                        (*(undefined4 *)(param_1 + 0x4688),
                         *(undefined4 *)((uint)*(byte *)(param_1 + 0x85a8) * 4 + iVar5 + 0x4a8),
                         0x88ae,local_30),
             (int)local_30[0] <= (int)(uint)*(ushort *)(iVar1 + *(int *)(param_1 + 0x468c) + 0xee)))
          {
            if ((uVar4 == 0) &&
               ((**(code **)(param_1 + 0x47dc))
                          (*(undefined4 *)(param_1 + 0x4688),
                           *(undefined4 *)((uint)*(byte *)(param_1 + 0x85a8) * 4 + iVar5 + 0x4a8),
                           0x88b2,local_30),
               (int)(uint)*(ushort *)(*(int *)(param_1 + 0x468c) + 0x118) < (int)local_30[0])) {
              uVar2 = 0;
              goto LAB_00021914;
            }
            if ((uVar4 != 1) ||
               ((((**(code **)(param_1 + 0x47dc))
                            (*(undefined4 *)(param_1 + 0x4688),
                             *(undefined4 *)((uint)*(byte *)(param_1 + 0x85a8) * 4 + iVar5 + 0x4a8),
                             0x8808,local_30),
                 (int)local_30[0] <= (int)(uint)*(ushort *)(*(int *)(param_1 + 0x468c) + 0x10c) &&
                 ((**(code **)(param_1 + 0x47dc))
                            (*(undefined4 *)(param_1 + 0x4688),
                             *(undefined4 *)((uint)*(byte *)(param_1 + 0x85a8) * 4 + iVar5 + 0x4a8),
                             0x8809,local_30),
                 (int)local_30[0] <= (int)(uint)*(ushort *)(*(int *)(param_1 + 0x468c) + 0x10e))) &&
                ((**(code **)(param_1 + 0x47dc))
                           (*(undefined4 *)(param_1 + 0x4688),
                            *(undefined4 *)((uint)*(byte *)(param_1 + 0x85a8) * 4 + iVar5 + 0x4a8),
                            0x880a,local_30),
                (int)local_30[0] <= (int)(uint)*(ushort *)(*(int *)(param_1 + 0x468c) + 0x110))))) {
              uVar2 = 1;
              goto LAB_00021914;
            }
          }
          uVar2 = 0;
          goto LAB_00021914;
        }
        if (param_3 < 34999) {
          if (param_3 == 0x88b3) {
            uVar2 = 0;
            if (uVar4 == 0) {
              uVar2 = (uint)*(ushort *)(*(int *)(param_1 + 0x468c) + 0x118);
            }
            goto LAB_00021914;
          }
          if (param_3 < 0x88b3) goto LAB_000216f4;
          if ((param_3 == 0x88b4) || (param_3 == 0x88b5)) {
            uVar2 = 0x100;
            if (uVar4 != 0) {
              uVar2 = 0x80;
            }
            goto LAB_00021914;
          }
        }
        else {
          if (param_3 == 0x88f6) {
            uVar2 = 0;
            if (uVar4 != 0) {
              uVar2 = (uint)*(ushort *)(*(int *)(param_1 + 0x468c) + 0x112);
            }
            goto LAB_00021914;
          }
          if (param_3 < 0x88f7) {
            if (param_3 == 0x88f4) {
              uVar2 = *(uint *)(uVar4 * 0x10 + *(int *)(param_1 + 0x468c) + 0xf8);
              goto LAB_00021914;
            }
            if (param_3 == 0x88f5) {
              uVar2 = (uint)*(ushort *)(uVar4 * 0x10 + *(int *)(param_1 + 0x468c) + 0xf4);
              goto LAB_00021914;
            }
          }
          else {
            if (param_3 == 0x88f7) {
              uVar2 = 0;
              if (uVar4 != 0) {
                uVar2 = (uint)*(ushort *)(*(int *)(param_1 + 0x468c) + 0x114);
              }
              goto LAB_00021914;
            }
            if (param_3 == 0x88f8) {
              uVar2 = 0;
              if (uVar4 != 0) {
                uVar2 = (uint)*(ushort *)(*(int *)(param_1 + 0x468c) + 0x116);
              }
              goto LAB_00021914;
            }
          }
        }
      }
    }
  }
  else {
    if (param_2 < 0x8621) {
      uVar4 = 0x8200;
    }
    else {
      uVar4 = 0x8804;
    }
    if (param_2 == uVar4) {
      uVar4 = 1;
      goto LAB_00021188;
    }
  }
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  uVar3 = 0x500;
LAB_0002190c:
  *(undefined4 *)(param_1 + 0x7574) = uVar3;
  return;
}

/* _glIsEnabled_Exec @ 0x21930 (72 bytes) */
int _glIsEnabled_Exec(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  undefined4 uVar1;
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    uVar1 = ((int (*)())_gleGetEnabled)(param_1,param_2);
  }
  else {
    if (*(int *)(param_1 + 0x7574) == 0) {
      *(undefined4 *)(param_1 + 0x7574) = 0x502;
    }
    uVar1 = 0;
  }
  return uVar1;
}

/* _gleGetEnabled @ 0x21978 (2652 bytes) */
int _gleGetEnabled(param_1, param_2)
  int param_1;
  uint param_2;
{
  uint uVar1;
  uint uVar2;
  int iVar3;
  longlong lVar4;
  
  if (param_2 < 0x4008) {
    if (param_2 < 0x4000) {
      if (param_2 == 0xd90) {
        return (uint)*(byte *)(param_1 + 0x74e2);
      }
      if (param_2 < 0xd91) {
        if (param_2 == 0xba1) {
          return (uint)*(byte *)(param_1 + 0x280d);
        }
        if (0xba1 < param_2) {
          if (param_2 == 0xc11) {
            return (uint)*(byte *)(param_1 + 0x34f0);
          }
          if (param_2 < 0xc12) {
            if (param_2 == 0xbe2) {
              return (uint)*(byte *)(param_1 + 0x30e4);
            }
            if (param_2 < 0xbe3) {
              if (param_2 == 0xbc0) {
                return (uint)*(byte *)(param_1 + 0x30c6);
              }
              if (param_2 == 0xbd0) {
                return (uint)*(byte *)(param_1 + 0x313c);
              }
            }
            else {
              if (param_2 == 0xbf1) {
                return (uint)*(byte *)(param_1 + 0x3192);
              }
              if (param_2 == 0xbf2) {
                return (uint)*(byte *)(param_1 + 0x3193);
              }
            }
          }
          else {
            if (param_2 == 0xc62) {
              return (uint)*(byte *)(*(int *)(param_1 + 0x53d4) * 0x94 + param_1 + 0x3d7a);
            }
            if (param_2 < 0xc63) {
              if (param_2 == 0xc60) {
                return (uint)*(byte *)(*(int *)(param_1 + 0x53d4) * 0x94 + param_1 + 0x3d78);
              }
              if (param_2 == 0xc61) {
                return (uint)*(byte *)(*(int *)(param_1 + 0x53d4) * 0x94 + param_1 + 0x3d79);
              }
            }
            else {
              if (param_2 == 0xc63) {
                return (uint)*(byte *)(*(int *)(param_1 + 0x53d4) * 0x94 + param_1 + 0x3d7b);
              }
              if (param_2 == 0xd80) {
                return (uint)*(byte *)(param_1 + 0x74f2);
              }
            }
          }
LAB_000223a8:
          if (*(int *)(param_1 + 0x7574) == 0) {
            *(undefined4 *)(param_1 + 0x7574) = 0x500;
          }
          return 0;
        }
        if (param_2 == 0xb44) {
          return (uint)*(byte *)(param_1 + 0x34da);
        }
        if (param_2 < 0xb45) {
          if (param_2 == 0xb24) {
            return (uint)*(byte *)(param_1 + 0x318c);
          }
          if (param_2 < 0xb25) {
            if (param_2 == 0xb10) {
              return (uint)*(byte *)(param_1 + 0x343c);
            }
            if (param_2 == 0xb20) {
              return (uint)*(byte *)(param_1 + 0x318d);
            }
          }
          else {
            if (param_2 == 0xb41) {
              return (uint)*(byte *)(param_1 + 0x34d9);
            }
            if (param_2 == 0xb42) {
              return (uint)*(byte *)(param_1 + 0x34d8);
            }
          }
          goto LAB_000223a8;
        }
        if (param_2 == 0xb60) {
          return (uint)*(byte *)(param_1 + 0x316a);
        }
        if (param_2 < 0xb61) {
          if (param_2 == 0xb50) {
            return (uint)*(byte *)(param_1 + 0x30aa);
          }
          if (param_2 == 0xb57) {
            return (uint)*(byte *)(param_1 + 0x30ab);
          }
          goto LAB_000223a8;
        }
        if (param_2 == 0xb71) {
          return (uint)*(byte *)(param_1 + 0x3128);
        }
        if (param_2 != 0xb90) goto LAB_000223a8;
        uVar1 = *(uint *)(param_1 + 0x3520);
        uVar2 = (uint)*(byte *)(param_1 + 0x7583);
      }
      else {
        if (param_2 == 0xdb3) {
          return (uint)*(byte *)(param_1 + 0x74ee);
        }
        if (param_2 < 0xdb4) {
          if (param_2 == 0xd96) {
            return (uint)*(byte *)(param_1 + 0x74e8);
          }
          if (param_2 < 0xd97) {
            if (param_2 == 0xd93) {
              return (uint)*(byte *)(param_1 + 0x74e5);
            }
            if (param_2 < 0xd94) {
              if (param_2 == 0xd91) {
                return (uint)*(byte *)(param_1 + 0x74e3);
              }
              if (param_2 == 0xd92) {
                return (uint)*(byte *)(param_1 + 0x74e4);
              }
            }
            else {
              if (param_2 == 0xd94) {
                return (uint)*(byte *)(param_1 + 0x74e6);
              }
              if (param_2 == 0xd95) {
                return (uint)*(byte *)(param_1 + 0x74e7);
              }
            }
          }
          else {
            if (param_2 == 0xdb0) {
              return (uint)*(byte *)(param_1 + 0x74eb);
            }
            if (param_2 < 0xdb1) {
              if (param_2 == 0xd97) {
                return (uint)*(byte *)(param_1 + 0x74e0);
              }
              if (param_2 == 0xd98) {
                return (uint)*(byte *)(param_1 + 0x74e1);
              }
            }
            else {
              if (param_2 == 0xdb1) {
                return (uint)*(byte *)(param_1 + 0x74ec);
              }
              if (param_2 == 0xdb2) {
                return (uint)*(byte *)(param_1 + 0x74ed);
              }
            }
          }
          goto LAB_000223a8;
        }
        if (param_2 == 0xde0) {
          uVar1 = *(uint *)(*(int *)(param_1 + 0x53d4) * 0x7c + param_1 + 0x3534);
LAB_00022360:
          return uVar1 >> 4 & 1;
        }
        if (param_2 < 0xde1) {
          if (param_2 == 0xdb6) {
            return (uint)*(byte *)(param_1 + 0x74f1);
          }
          if (param_2 < 0xdb7) {
            if (param_2 == 0xdb4) {
              return (uint)*(byte *)(param_1 + 0x74ef);
            }
            if (param_2 == 0xdb5) {
              return (uint)*(byte *)(param_1 + 0x74f0);
            }
          }
          else {
            if (param_2 == 0xdb7) {
              return (uint)*(byte *)(param_1 + 0x74e9);
            }
            if (param_2 == 0xdb8) {
              return (uint)*(byte *)(param_1 + 0x74ea);
            }
          }
          goto LAB_000223a8;
        }
        if (param_2 == 0x2a02) {
          return (uint)*(byte *)(param_1 + 0x34dc);
        }
        if (param_2 < 0x2a03) {
          if (param_2 == 0xde1) {
            uVar1 = *(uint *)(*(int *)(param_1 + 0x53d4) * 0x7c + param_1 + 0x3534);
            goto LAB_0002236c;
          }
          if (param_2 == 0x2a01) {
            return (uint)*(byte *)(param_1 + 0x34db);
          }
          goto LAB_000223a8;
        }
        uVar2 = param_2 - 0x3000;
        if (5 < uVar2) goto LAB_000223a8;
        uVar1 = *(uint *)(param_1 + 0x4188);
      }
    }
    else {
      uVar1 = *(uint *)(param_1 + 0x30a0);
      uVar2 = param_2 - 0x4000;
    }
    uVar1 = uVar1 >> (uVar2 & 0x3f);
LAB_00022378:
    return uVar1 & 1;
  }
  if (param_2 == 0x8200) {
LAB_00022328:
    return (uint)*(byte *)(param_1 + 0x466c);
  }
  if (param_2 < 0x8201) {
    if (param_2 == 0x8076) {
      uVar1 = *(uint *)(*(int *)(param_1 + 0x4a60) + 0x334) >> 0x12;
      goto LAB_0002227c;
    }
    if (0x8076 < param_2) {
      if (param_2 == 0x809f) {
        return (uint)*(byte *)(param_1 + 0x41f2);
      }
      if (param_2 < 0x80a0) {
        if (param_2 == 0x8079) {
          uVar1 = *(uint *)(*(int *)(param_1 + 0x4a60) + 0x334) >> 0x16;
          goto LAB_0002227c;
        }
        if (param_2 < 0x807a) {
          if (param_2 == 0x8077) {
            return (uint)*(byte *)(param_1 + 0x48eb);
          }
          if (param_2 == 0x8078) {
            iVar3 = *(int *)(param_1 + 0x4a60);
            lVar4 = ___ashldi3(0,0x1000000,*(undefined4 *)(param_1 + 0x53d8));
            if ((*(uint *)(iVar3 + 0x330) & (uint)((ulonglong)lVar4 >> 0x20)) == 0 &&
                (*(uint *)(iVar3 + 0x334) & (uint)lVar4) == 0) {
              return 0;
            }
            return 1;
          }
        }
        else {
          if (param_2 == 0x809d) {
            return (uint)*(byte *)(param_1 + 0x41f0);
          }
          if (param_2 == 0x809e) {
            return (uint)*(byte *)(param_1 + 0x41f1);
          }
        }
      }
      else {
        if (param_2 == 0x80d1) {
          return *(uint *)(param_1 + 0x3410) >> 6 & 1;
        }
        if (param_2 < 0x80d2) {
          if (param_2 == 0x80a0) {
            return (uint)*(byte *)(param_1 + 0x41f3);
          }
          if (param_2 == 0x80d0) {
            return *(uint *)(param_1 + 0x3410) >> 5 & 1;
          }
        }
        else {
          if (param_2 == 0x80d2) {
            return *(uint *)(param_1 + 0x3410) >> 7 & 1;
          }
          if (param_2 == 0x81fb) {
            return *(uint *)(*(int *)(param_1 + 0x53d4) * 0x7c + param_1 + 0x3534) >> 8 & 1;
          }
        }
      }
      goto LAB_000223a8;
    }
    if (param_2 == 0x802e) {
      uVar1 = *(uint *)(param_1 + 0x3410);
LAB_0002236c:
      return uVar1 >> 3 & 1;
    }
    if (param_2 < 0x802f) {
      if (param_2 != 0x8011) {
        if (param_2 < 0x8012) {
          if (param_2 == 0x6090) {
            return (uint)*(byte *)(param_1 + 0x280c);
          }
          if (param_2 == 0x8010) {
            uVar1 = (uint)*(byte *)(param_1 + 0x3413);
            goto LAB_00022378;
          }
        }
        else {
          if (param_2 == 0x8012) {
            uVar1 = *(uint *)(param_1 + 0x3410);
            goto LAB_00022398;
          }
          if (param_2 == 0x8024) {
            uVar1 = *(uint *)(param_1 + 0x3410);
            goto LAB_00022360;
          }
        }
        goto LAB_000223a8;
      }
      uVar1 = *(uint *)(param_1 + 0x3410);
    }
    else {
      if (param_2 != 0x806f) {
        if (0x806f < param_2) {
          if (param_2 == 0x8074) {
            uVar1 = *(uint *)(*(int *)(param_1 + 0x4a60) + 0x334) >> 0x10;
          }
          else {
            if (param_2 != 0x8075) goto LAB_000223a8;
            uVar1 = *(uint *)(*(int *)(param_1 + 0x4a60) + 0x334) >> 0x11;
          }
          goto LAB_0002227c;
        }
        if (param_2 == 0x8037) {
          return (uint)*(byte *)(param_1 + 0x34dd);
        }
        if (param_2 == 0x803a) {
          return (uint)*(byte *)(param_1 + 0x280e);
        }
        goto LAB_000223a8;
      }
      uVar1 = *(uint *)(*(int *)(param_1 + 0x53d4) * 0x7c + param_1 + 0x3534);
    }
    return uVar1 >> 1 & 1;
  }
  if (param_2 == 0x8643) {
    return (uint)*(byte *)(param_1 + 0x4666);
  }
  if (param_2 < 0x8644) {
    if (param_2 == 0x851d) {
      return (uint)*(byte *)(param_1 + 0x465c);
    }
    if (param_2 < 0x851e) {
      if (param_2 == 0x845e) {
        uVar1 = *(uint *)(*(int *)(param_1 + 0x4a60) + 0x334) >> 0x14;
LAB_0002227c:
        return uVar1 & 1;
      }
      if (param_2 < 0x845f) {
        if (param_2 != 0x8457) {
          if (param_2 == 0x8458) {
            return (uint)*(byte *)(param_1 + 0x4fea);
          }
          goto LAB_000223a8;
        }
        uVar1 = *(uint *)(*(int *)(param_1 + 0x4a60) + 0x334) >> 0x13;
        goto LAB_0002227c;
      }
      if (param_2 != 0x84f5) {
        if (param_2 != 0x8513) goto LAB_000223a8;
        uVar1 = (uint)*(byte *)(*(int *)(param_1 + 0x53d4) * 0x7c + param_1 + 0x3537);
        goto LAB_00022378;
      }
    }
    else if (param_2 != 0x85b3) {
      if (param_2 < 0x85b4) {
        if (param_2 == 0x8522) {
          return (uint)*(byte *)(param_1 + 0x41f8);
        }
        if (param_2 == 0x8535) {
          return (uint)*(byte *)(param_1 + 0x41f9);
        }
      }
      else {
        if (param_2 == 0x8620) {
          return (uint)*(byte *)(param_1 + 0x4664);
        }
        if (param_2 == 0x8642) {
          return (uint)*(byte *)(param_1 + 0x4665);
        }
      }
      goto LAB_000223a8;
    }
    uVar1 = *(uint *)(*(int *)(param_1 + 0x53d4) * 0x7c + param_1 + 0x3534);
  }
  else {
    if (param_2 == 0x8804) goto LAB_00022328;
    if (param_2 < 0x8805) {
      if (param_2 == 0x86a7) {
        return (uint)*(byte *)(param_1 + 0x4661);
      }
      if (param_2 < 0x86a8) {
        if (param_2 == 0x864f) {
          return (uint)*(byte *)(param_1 + 0x3129);
        }
        if (param_2 == 0x86a6) {
          return (uint)*(byte *)(param_1 + 0x4662);
        }
      }
      else {
        if (param_2 == 0x86ad) {
          uVar1 = *(uint *)(*(int *)(param_1 + 0x4a60) + 0x334) >> 0x15;
          goto LAB_0002227c;
        }
        if (param_2 == 0x86de) {
          return (uint)*(byte *)(param_1 + 0x3ce4);
        }
      }
      goto LAB_000223a8;
    }
    if (param_2 != 0x8910) {
      if (param_2 < 0x8911) {
        if (param_2 == 0x8861) {
          return (uint)*(byte *)(param_1 + 0x343d);
        }
        if (param_2 == 0x8890) {
          return (uint)*(byte *)(param_1 + 0x312a);
        }
      }
      else {
        if (param_2 == 0x8a0c) {
          uVar1 = *(uint *)(*(int *)(param_1 + 0x4a60) + 0x334) >> 0x17;
          goto LAB_0002227c;
        }
        if (param_2 == 0x19262) {
          return (uint)*(byte *)(param_1 + 0x50b5);
        }
      }
      goto LAB_000223a8;
    }
    uVar1 = *(uint *)(param_1 + 0x3520);
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
int _gleSetEnable_DITHER(param_1, param_2, param_3)
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
int _glStencilMask_Exec(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  uint uVar1;
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    uVar1 = *(uint *)(param_1 + 0x310);
    *(undefined4 *)((uint)*(byte *)(param_1 + 0x7583) * 4 + param_1 + 0x3198) = param_2;
    *(uint *)(param_1 + 0x310) = uVar1 | 0x100000;
    return;
  }
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  *(undefined4 *)(param_1 + 0x7574) = 0x502;
  return;
}

/* _glClearColor_Exec @ 0x22490 (228 bytes) */
void _glClearColor_Exec(int param_1,float fparam_1,float fparam_2,float fparam_3,float fparam_4)
{
  float fVar1;
  float fVar2;
  double dVar3;
  double dVar4;
  
  fVar2 = FLOAT_00108e54;
  fVar1 = FLOAT_00108e50;
  if (-1 < *(short *)(param_1 + 0x4a10)) {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    *(undefined4 *)(param_1 + 0x7574) = 0x502;
    return;
  }
  dVar3 = (double)FLOAT_00108e50;
  dVar4 = (double)FLOAT_00108e54;
  *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 8;
  if (dVar3 <= fparam_1) {
    if (fparam_1 <= dVar4) {
      *(float *)(param_1 + 0x3100) = (float)fparam_1;
    }
    else {
      *(float *)(param_1 + 0x3100) = fVar2;
    }
  }
  else {
    *(float *)(param_1 + 0x3100) = fVar1;
  }
  if (dVar3 <= fparam_2) {
    if (fparam_2 <= dVar4) {
      *(float *)(param_1 + 0x3104) = (float)fparam_2;
    }
    else {
      *(float *)(param_1 + 0x3104) = fVar2;
    }
  }
  else {
    *(float *)(param_1 + 0x3104) = fVar1;
  }
  if (dVar3 <= fparam_3) {
    if (fparam_3 <= dVar4) {
      *(float *)(param_1 + 0x3108) = (float)fparam_3;
    }
    else {
      *(float *)(param_1 + 0x3108) = fVar2;
    }
  }
  else {
    *(float *)(param_1 + 0x3108) = fVar1;
  }
  if (fparam_4 < dVar3) {
    *(float *)(param_1 + 0x310c) = fVar1;
    return;
  }
  if (dVar4 < fparam_4) {
    *(float *)(param_1 + 0x310c) = fVar2;
    return;
  }
  *(float *)(param_1 + 0x310c) = (float)fparam_4;
  return;
}

/* _glMultiTexCoord4fv_Exec @ 0x225b4 (60 bytes) */
int _glMultiTexCoord4fv_Exec(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  undefined4 *param_3;
{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  
  uVar1 = param_3[3];
  iVar4 = param_1 + (param_2 & 7) * 0x10;
  uVar2 = param_3[1];
  uVar3 = param_3[2];
  *(undefined4 *)(iVar4 + 0x120) = *param_3;
  *(undefined4 *)(iVar4 + 300) = uVar1;
  *(undefined4 *)(iVar4 + 0x124) = uVar2;
  *(undefined4 *)(iVar4 + 0x128) = uVar3;
  *(uint *)(param_1 + 0x486c) = *(uint *)(param_1 + 0x486c) | 3;
  return;
}

/* _glVertex4fv_Exec @ 0x225f0 (48 bytes) */
int _glVertex4fv_Exec(param_1, param_2)
  int param_1;
  float *param_2;
{
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = *(code **)(param_1 + 0x4884);
  if (*(int *)(param_1 + 0x4858) == *(int *)(param_1 + 0x485c)) {
    UNRECOVERED_JUMPTABLE = *(code **)(param_1 + 0x28);
  }
                    
                    
  (*((int (*)(int,int,double,double,double,double))UNRECOVERED_JUMPTABLE))
            (param_1, param_2, (double)*param_2, (double)param_2[1], (double)param_2[2], (double)param_2[3]);
  return;
}

/* _glGenProgramsARB_Exec @ 0x22620 (236 bytes) */
int _glGenProgramsARB_Exec(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int *param_3;
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if (-1 < param_2) {
      iVar4 = *(int *)(param_1 + 0x5148);
      if (*(char *)(iVar4 + 0x8024) != '\0') {
        _pthread_mutex_lock(iVar4 + 0x8028);
        iVar4 = *(int *)(param_1 + 0x5148);
      }
      iVar4 = _gleGenHashNames(iVar4 + 0x4010,param_2);
      if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) != '\0') {
        _pthread_mutex_unlock(*(int *)(param_1 + 0x5148) + 0x8028);
      }
      if (iVar4 == 0) {
        return;
      }
      iVar3 = 0;
      if (param_2 < 1) {
        return;
      }
      do {
        iVar2 = iVar3 + iVar4;
        iVar3 = iVar3 + 1;
        *param_3 = iVar2;
        param_3 = param_3 + 1;
        param_2 = param_2 + -1;
      } while (param_2 != 0);
      return;
    }
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar1 = 0x501;
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

/* _glBindProgramARB_Exec @ 0x2270c (276 bytes) */
int _glBindProgramARB_Exec(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  undefined4 param_3;
{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  
  if (-1 < *(short *)(param_1 + 0x4a10)) {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar1 = 0x502;
LAB_0002279c:
    *(undefined4 *)(param_1 + 0x7574) = uVar1;
    return;
  }
  if (param_2 == 0x8620) {
    uVar1 = 0;
  }
  else {
    if (param_2 < 0x8621) {
      uVar2 = 0x8200;
    }
    else {
      uVar2 = 0x8804;
    }
    if (param_2 != uVar2) {
      if (*(int *)(param_1 + 0x7574) != 0) {
        return;
      }
      uVar1 = 0x500;
      goto LAB_0002279c;
    }
    uVar1 = 1;
  }
  if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) != '\0') {
    iVar3 = *(int *)(param_1 + 0x5148) + 0x8028;
    _pthread_mutex_lock(iVar3);
    ((int (*)())_gleBindPipelineProgram)(param_1,uVar1,param_3);
    _pthread_mutex_unlock(iVar3);
    return;
  }
  ((int (*)())_gleBindPipelineProgram)(param_1,uVar1,param_3);
  return;
}

/* _gleBindPipelineProgram @ 0x22820 (644 bytes) */
int _gleBindPipelineProgram(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  int param_3;
{
  char cVar1;
  int iVar2;
  undefined *puVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  undefined4 *puVar8;
  int iVar9;
  int iVar10;
  undefined4 *puVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  
  iVar12 = *(int *)(param_1 + 0x5148) + 0x4010;
  if (param_3 == 0) {
    iVar12 = param_2 * 4;
    iVar7 = *(int *)(iVar12 + param_1 + 0x5428);
    iVar14 = iVar7 + 0x10;
  }
  else {
    iVar7 = _gleLookupHashObject(iVar12,param_3);
    if (iVar7 == 0) {
      iVar7 = _gleCreatePipelineProgramObject(param_1,param_2,param_3);
      iVar14 = iVar7 + 0x10;
      _gleCreatePluginPipelineProgram(param_1,iVar14);
      _gleAddHashNameAndObject(param_1,iVar12,iVar7);
    }
    else {
      if (*(ushort *)(iVar7 + 0x4ca) != param_2) {
        if (*(int *)(param_1 + 0x7574) != 0) {
          return;
        }
        *(undefined4 *)(param_1 + 0x7574) = 0x502;
        return;
      }
      iVar14 = iVar7 + 0x10;
    }
    iVar12 = param_2 << 2;
  }
  **(undefined1 **)(param_1 + 0x5418) = 0;
  iVar9 = 0;
  *(undefined4 *)(param_1 + 0x541c) = 0xffffffff;
  *(int *)(iVar7 + 8) = *(int *)(iVar7 + 8) + 1;
  cVar1 = *(char *)(param_1 + 0x85a4);
  iVar13 = *(int *)(iVar12 + param_1 + 0x5420);
  *(int *)(iVar12 + param_1 + 0x5420) = iVar7;
  if (cVar1 != '\0') {
    puVar8 = (undefined4 *)(iVar7 + 0x4a8);
    puVar11 = (undefined4 *)(param_2 * 4 + param_1 + 0x886c);
    do {
      uVar4 = *puVar8;
      iVar9 = iVar9 + 1;
      puVar8 = puVar8 + 1;
      *puVar11 = uVar4;
      puVar11 = puVar11 + 0xb8;
    } while (iVar9 < (int)(uint)*(byte *)(param_1 + 0x85a4));
  }
  if (param_2 == 0) {
    iVar7 = 9;
    iVar12 = 5;
    uVar6 = *(uint *)(param_1 + 0x31c) | 0x400000;
  }
  else {
    if (param_2 != 1) {
      iVar7 = 0;
      iVar12 = 0;
      goto LAB_0002299c;
    }
    iVar7 = 5;
    iVar12 = 0xe;
    uVar6 = *(uint *)(param_1 + 0x31c) | 0x1000000;
  }
  *(uint *)(param_1 + 0x31c) = uVar6;
LAB_0002299c:
  iVar9 = param_2 * 0xa30;
  if (*(int *)(iVar9 + *(int *)(param_1 + 0x5148) + 0x8a98) != *(int *)(iVar14 + 0x14)) {
    ((int (*)())_glePPUpdateProgram)(param_1,iVar14);
    *(undefined4 *)(iVar14 + 0x14) = *(undefined4 *)(iVar9 + *(int *)(param_1 + 0x5148) + 0x8a98);
  }
  _gleUpdateInverseNeeds(param_1);
  iVar10 = 0;
  if (iVar7 != 0) {
    iVar5 = *(int *)(param_1 + 0x5148);
    iVar12 = iVar12 * 4 + param_1;
    do {
      iVar2 = iVar10 * 4;
      iVar10 = iVar10 + 1;
      uVar6 = *(uint *)(iVar12 + 0x310) |
              *(uint *)(iVar2 + iVar14 + 0x18) &
              (*(uint *)(iVar2 + iVar5 + iVar9 + 0x8a74) | ~*(uint *)(iVar2 + iVar13 + 0x28));
      *(uint *)(iVar12 + 0x310) = uVar6;
      *(uint *)(iVar12 + 0x310) = uVar6 & *(uint *)(iVar2 + iVar14 + 0x18);
      iVar12 = iVar12 + 4;
      iVar7 = iVar7 + -1;
    } while (iVar7 != 0);
  }
  iVar12 = *(int *)(iVar13 + 8) + -1;
  *(int *)(iVar13 + 8) = iVar12;
  if (iVar12 == 0) {
    _gleFreePipelineProgramObject(param_1,iVar13);
  }
  _gleSelectVertexSubmitFunc(param_1);
  puVar3 = PTR__gleSetClipInterpFunc_00112038;
  *(undefined **)(param_1 + 0x49c8) = PTR__gleSetEyeInterpFunc_0011203c;
  *(undefined **)(param_1 + 0x49cc) = puVar3;
  return;
}

/* _glProgramStringARB_Exec @ 0x22aa4 (796 bytes) */
int _glProgramStringARB_Exec(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  uint param_2;
  int param_3;
  int param_4;
  int param_5;
{
  uint *puVar1;
  bool bVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  uint local_60 [15];
  
  if (-1 < *(short *)(param_1 + 0x4a10)) {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar3 = 0x502;
    goto LAB_00022bb8;
  }
  if (-1 < param_4) {
    if (param_3 != 0x8875) {
LAB_00022b48:
      if (*(int *)(param_1 + 0x7574) != 0) {
        return;
      }
      uVar3 = 0x500;
      goto LAB_00022bb8;
    }
    if (param_2 == 0x8620) {
      iVar7 = 0;
    }
    else {
      if (param_2 < 0x8621) {
        uVar4 = 0x8200;
      }
      else {
        uVar4 = 0x8804;
      }
      if (param_2 != uVar4) goto LAB_00022b48;
      iVar7 = 1;
    }
    iVar8 = 0;
    iVar6 = _malloc(param_4 + 1);
    bVar2 = param_4 == 0;
    if (0 < param_4) {
      do {
        if (*(char *)(param_5 + iVar8) == '\0') break;
        *(char *)(iVar6 + iVar8) = *(char *)(param_5 + iVar8);
        iVar8 = iVar8 + 1;
        bVar2 = iVar8 == param_4;
      } while (iVar8 < param_4);
    }
    *(undefined1 *)(iVar6 + iVar8) = 0;
    if (bVar2) {
      iVar7 = *(int *)(iVar7 * 4 + param_1 + 0x5420);
      if (*(int *)(iVar7 + 0x14) != 0) {
        ((int (*)())_gleModifyPluginPipelineProgram)(param_1,iVar7 + 0x10,1);
        _free(*(undefined4 *)(iVar7 + 0x14));
      }
      *(undefined1 *)(iVar7 + 0x4c) = 1;
      *(undefined4 *)(iVar7 + 0x1c) = 0x8875;
      *(int *)(iVar7 + 0x18) = iVar8;
      *(int *)(iVar7 + 0x14) = iVar6;
      *(short *)(iVar7 + 0x4c8) = (short)param_2;
      if (param_2 == 0x8620) {
        iVar6 = iVar7 + 0x10;
        iVar9 = 9;
        puVar5 = (undefined4 *)(iVar7 + 0x28);
        iVar8 = 0;
        do {
          uVar3 = *puVar5;
          puVar5 = puVar5 + 1;
          *(undefined4 *)((int)local_60 + iVar8) = uVar3;
          iVar8 = iVar8 + 4;
          iVar9 = iVar9 + -1;
        } while (iVar9 != 0);
        ((int (*)())_glePPParse)(param_1,iVar6,0);
        ((int (*)())_glePPUpdateProgram)(param_1,iVar6);
        _gleUpdateInverseNeeds(param_1);
        iVar10 = 9;
        iVar9 = 0;
        iVar8 = param_1;
        do {
          puVar1 = (uint *)((int)local_60 + iVar9);
          iVar9 = iVar9 + 4;
          uVar4 = *(uint *)(iVar8 + 0x324) | *(uint *)(iVar6 + 0x18) & ~*puVar1;
          *(uint *)(iVar8 + 0x324) = uVar4;
          puVar1 = (uint *)(iVar6 + 0x18);
          iVar6 = iVar6 + 4;
          *(uint *)(iVar8 + 0x324) = uVar4 & *puVar1;
          iVar8 = iVar8 + 4;
          iVar10 = iVar10 + -1;
        } while (iVar10 != 0);
        _gleSelectVertexSubmitFunc(param_1);
        *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x400000;
      }
      if (param_2 == 0x8804) {
        puVar5 = (undefined4 *)(iVar7 + 0x28);
        iVar8 = 5;
        iVar7 = iVar7 + 0x10;
        iVar6 = 0;
        do {
          uVar3 = *puVar5;
          puVar5 = puVar5 + 1;
          *(undefined4 *)((int)local_60 + iVar6) = uVar3;
          iVar6 = iVar6 + 4;
          iVar8 = iVar8 + -1;
        } while (iVar8 != 0);
        ((int (*)())_glePPParse)(param_1,iVar7,1);
        ((int (*)())_glePPUpdateProgram)(param_1,iVar7);
        _gleUpdateInverseNeeds(param_1);
        iVar9 = 9;
        iVar8 = 0;
        iVar6 = param_1;
        do {
          puVar1 = (uint *)((int)local_60 + iVar8);
          iVar8 = iVar8 + 4;
          uVar4 = *(uint *)(iVar6 + 0x348) | *(uint *)(iVar7 + 0x18) & ~*puVar1;
          *(uint *)(iVar6 + 0x348) = uVar4;
          puVar1 = (uint *)(iVar7 + 0x18);
          iVar7 = iVar7 + 4;
          *(uint *)(iVar6 + 0x348) = uVar4 & *puVar1;
          iVar6 = iVar6 + 4;
          iVar9 = iVar9 + -1;
        } while (iVar9 != 0);
        _gleSelectVertexSubmitFunc(param_1);
        *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x1000000;
      }
      if (param_2 != 0x8200) {
        return;
      }
      _gleLFSParse(param_1);
      _gleSelectVertexSubmitFunc(param_1);
      *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x1000000;
      return;
    }
    _free(iVar6);
  }
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  uVar3 = 0x501;
LAB_00022bb8:
  *(undefined4 *)(param_1 + 0x7574) = uVar3;
  return;
}

/* _glePPParse @ 0x22dc0 (4884 bytes) */
int _glePPParse(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  int param_3;
{
  bool bVar1;
  bool bVar2;
  short sVar3;
  ushort uVar4;
  int iVar5;
  int iVar6;
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
      iVar5 = _calloc(local_60,8);
      iVar6 = _calloc(local_5c,8);
      _PPStreamChunkListGetStream(piVar20,iVar5,&local_60,iVar22);
      _PPStreamChunkListGetStream(uVar24,iVar6,&local_5c,iVar22);
      if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) != '\0') {
        _pthread_mutex_lock(*(int *)(param_1 + 0x5148) + 0x8028);
      }
      ((int (*)())_glePPLogParameters)(param_1,param_2,local_60,iVar5,local_5c,iVar6);
      if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) != '\0') {
        _pthread_mutex_unlock(*(int *)(param_1 + 0x5148) + 0x8028);
      }
      piVar19 = *(int **)(iVar22 + 0x20);
      uVar23 = 0;
      piVar18 = *(int **)(iVar22 + 0x14);
      piVar7 = (int *)_PPStreamChunkListCreateFromChunkList(piVar19);
      piVar8 = (int *)_PPStreamChunkListCreateFromChunkList(piVar18);
      iVar21 = *piVar20;
      if (local_60 != 0) {
        puVar13 = (undefined4 *)(iVar5 + 4);
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
      if (iVar5 != 0) {
        _free(iVar5);
      }
      if (iVar6 != 0) {
        _free(iVar6);
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
         ((*(ushort *)(*(int *)(param_1 + 0x468c) + 0x11a) & 2) == 0)) {
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
          if ((*(ushort *)(*(int *)(param_1 + 0x468c) + 0x11a) & 1) == 0) {
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
          if ((*(ushort *)(*(int *)(param_1 + 0x468c) + 0x11a) & 1) == 0) {
            uVar15 = local_70 & 0xffe03fff | 0x104000;
          }
          else {
            uVar15 = local_70 & 0xffe03fff | 0x100000;
          }
          local_70 = (uVar23 & 3) << 0xc | uVar15 & 0xffffc8ff | 0x300;
          uVar23 = uVar23 + 1;
          _PPStreamAddParamBinding(iVar22,&local_70);
        } while (uVar23 < 4);
        uVar4 = *(ushort *)(*(int *)(param_1 + 0x468c) + 0x11a);
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
        ((int (*)())_PPEmulatorProgramSetupHandlesFromPPStream)(iVar5,param_1,iVar22);
        _PPEmulatorProgramConvertFromPPStream(iVar5,iVar22);
        if (param_2[0x135] != 0) {
          _PPEmulatorProgramFree();
        }
        param_2[0x135] = iVar5;
      }
      **(undefined1 **)(param_1 + 0x5418) = 0;
      *(undefined4 *)(param_1 + 0x541c) = 0xffffffff;
    }
    else {
LAB_00022f84:
      _PPParserBuildErrorString(iVar17,iVar5,0);
    }
    if (bVar2) goto LAB_000240b0;
  }
  if (*(int *)(param_1 + 0x7574) == 0) {
    *(undefined4 *)(param_1 + 0x7574) = 0x502;
  }
  _strncpy(*(char **)(param_1 + 0x5418),(char *)(iVar17 + 0x3c),0x600);
  *(undefined4 *)(param_1 + 0x541c) = 0;
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
  uVar3 = 0;
  for (; iVar4 != 0; iVar4 = *(int *)(iVar4 + 8)) {
    if (uVar3 != *(ushort *)(iVar4 + 0x12)) {
      _glePPRelocateAttrib((uint)*(ushort *)(iVar4 + 0x12),uVar3,piVar5);
      *(short *)(iVar4 + 0x12) = (short)uVar3;
    }
    uVar3 = uVar3 + 1;
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
  uint uVar5;
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
  uVar5 = 0;
  for (; iVar2 != 0; iVar2 = *(int *)(iVar2 + 8)) {
    if (uVar5 != *(ushort *)(iVar2 + 0x12)) {
      _glePPRelocateOutput((uint)*(ushort *)(iVar2 + 0x12),uVar5,piVar3);
      *(short *)(iVar2 + 0x12) = (short)uVar5;
    }
    uVar5 = uVar5 + 1;
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
  uVar1 = 0;
  for (; iVar2 != 0; iVar2 = *(int *)(iVar2 + 8)) {
    if (uVar1 != *(ushort *)(iVar2 + 0x12)) {
      _glePPRelocateLocal((uint)*(ushort *)(iVar2 + 0x12),uVar1,piVar3);
      *(short *)(iVar2 + 0x12) = (short)uVar1;
    }
    uVar1 = uVar1 + 1;
  }
  return 0;
}

/* _glePPPruneParams @ 0x246e4 (648 bytes) */
int _glePPPruneParams(param_1)
  int param_1;
{
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
  uVar4 = 0;
  for (; iVar8 != 0; iVar8 = *(int *)(iVar8 + 8)) {
    *(undefined4 *)(iVar8 + 0x14) = 0;
    if (uVar4 != *(ushort *)(iVar8 + 0x12)) {
      _glePPRelocateParam((uint)*(ushort *)(iVar8 + 0x12),uVar4,piVar6,piVar5);
      *(short *)(iVar8 + 0x12) = (short)uVar4;
    }
    uVar4 = uVar4 + 1;
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
int _glePPLogParameters(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  int param_2;
  uint param_3;
  int param_4;
  uint param_5;
  int param_6;
{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined2 uVar4;
  int iVar5;
  uint *puVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  undefined4 local_a0 [12];
  uint local_70;
  uint local_6c;
  uint local_60;
  uint local_5c;
  
  uVar11 = 0;
  uVar7 = (uint)*(ushort *)(param_2 + 0x4ba);
  iVar8 = *(int *)(param_1 + 0x5148);
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
      uVar11 = uVar11 + 1;
      uVar1 = 0;
    } while (uVar11 < *(uint *)(iVar5 + 0x8a9c));
  }
  uVar11 = 0;
  do {
    puVar3 = local_a0;
    iVar2 = 9;
    do {
      *puVar3 = 0;
      puVar3 = puVar3 + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    iVar2 = 0;
    for (uVar13 = param_3; uVar13 != 0; uVar13 = uVar13 - 1) {
      iVar5 = iVar2 * 8;
      iVar2 = iVar2 + 1;
      *(uint *)(iVar5 + param_4) = *(uint *)(iVar5 + param_4) & 0xff1fffff;
    }
    uVar13 = 0;
    iVar2 = -1;
    if (param_5 != 0) {
      do {
        local_60 = *(uint *)(param_6 + uVar13 * 8);
        local_5c = *(uint *)(uVar13 * 8 + param_6 + 4);
        uVar12 = local_60 & 0xffff;
        uVar9 = (local_5c & 0xffff) + 1;
        if (uVar11 <= uVar13) {
          iVar5 = uVar12 * 8;
          iVar10 = iVar5 + param_4;
          local_70 = *(undefined4 *)(iVar5 + param_4);
          local_6c = *(uint *)(iVar10 + 4) & 0xffff0000;
          iVar2 = ((int (*)())_glePPLogParam)(param_1,iVar8,uVar7,local_70,local_6c,uVar9 - uVar12,0xffffffff,
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
          iVar2 = ((int (*)())_glePPLogParam)(param_1,iVar8,uVar7,local_70,local_6c,1,iVar2 + 1,local_a0,uVar1);
          *(uint *)(iVar5 + param_4) = local_70;
          *(uint *)(iVar10 + 4) = local_6c;
          *(short *)(iVar10 + 6) = (short)iVar2;
          *(uint *)(iVar5 + param_4) = *(uint *)(iVar5 + param_4) & 0xff1fffff | 0x200000;
        }
        uVar13 = uVar13 + 1;
      } while (uVar13 < param_5);
    }
    if ((uVar13 == param_5) || (uVar11 = uVar11 + 1, param_5 < uVar11)) {
      uVar11 = 0;
      if (param_3 != 0) {
        do {
          iVar2 = uVar11 * 8;
          local_70 = *(uint *)(iVar2 + param_4);
          iVar5 = iVar2 + param_4;
          if ((local_70 >> 0x15 & 7) == 0) {
            local_6c = *(uint *)(iVar5 + 4) & 0xffff0000;
            uVar4 = ((int (*)())_glePPLogParam)(param_1,iVar8,uVar7,local_70,local_6c,1,0xffffffff,local_a0,uVar1
                                  );
            *(uint *)(iVar2 + param_4) = local_70;
            *(uint *)(iVar5 + 4) = local_6c;
            *(undefined2 *)(iVar5 + 6) = uVar4;
            *(uint *)(iVar2 + param_4) = *(uint *)(iVar2 + param_4) & 0xff1fffff | 0x200000;
          }
          uVar11 = uVar11 + 1;
        } while (uVar11 < param_3);
      }
      return;
    }
  } while( true );
}

/* _glePPLogParam @ 0x24c44 (1068 bytes) */
int _glePPLogParam(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9)
  undefined4 param_1;
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
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uStack00000024;
  int iStack00000028;
  
  uVar5 = param_4 >> 0x10 & 0x1f;
  uVar11 = 0x7fffffff;
  uVar9 = 0xffffffff;
  uVar10 = 0xffffffff;
  uVar8 = 0xffffffff;
  if (uVar5 == 0) {
    return 0;
  }
  if ((uVar5 == 1) || (uVar5 == 0x11)) {
    if ((int)param_7 < 0) {
      uVar10 = 0;
      if (param_9 - param_6 == -1) {
        return 0xffffffff;
      }
      uVar5 = param_3 * 0x518;
      iVar2 = param_3 * 0xa30 + param_2 + 0x8070;
      do {
        for (uVar6 = uVar10;
            ((int)uVar6 < (int)(uVar10 + param_6) &&
            ((*(uint *)(param_8 + ((int)uVar6 >> 5) * 4) >> (uVar6 & 0x1f) & 1) == 0));
            uVar6 = uVar6 + 1) {
        }
        if (uVar6 == uVar10 + param_6) {
          if ((*(int *)(iVar2 + 4) == -1) && (*(int *)(iVar2 + 8) == -1)) goto LAB_00024ff0;
          if (*(int *)(iVar2 + 4) == 0 && *(int *)(iVar2 + 8) == 0) {
            if (uVar9 == 0xffffffff) {
              uVar9 = uVar10;
            }
          }
          else {
            uVar6 = (uint)*(ushort *)((uVar5 + uVar10) * 2 + param_2 + 0x8874);
            if (uVar6 < uVar11) {
              uVar8 = uVar10;
              uVar11 = uVar6;
            }
          }
        }
        uVar10 = uVar10 + 1;
        iVar2 = iVar2 + 8;
      } while (uVar10 < (param_9 - param_6) + 1U);
      if (uVar9 != 0xffffffff) {
        iVar4 = 1;
        goto LAB_00025008;
      }
      goto LAB_00024fd4;
    }
    if ((*(uint *)(param_8 + ((int)param_7 >> 5) * 4) >> (param_7 & 0x1f) & 1) != 0) {
      return 0xffffffff;
    }
    iVar4 = 1;
    iVar2 = (param_3 * 0x146 + param_7) * 8 + param_2;
    bVar1 = *(int *)(iVar2 + 0x8074) == 0 && *(int *)(iVar2 + 0x8078) == 0;
LAB_00024ea0:
    uVar5 = 0xffffffff;
    if (bVar1) goto LAB_00025008;
  }
  else {
    if (-1 < (int)param_7) {
      if ((*(uint *)(param_8 + ((int)param_7 >> 5) * 4) >> (param_7 & 0x1f) & 1) != 0) {
        return 0xffffffff;
      }
      iVar2 = (param_3 * 0x146 + param_7) * 8 + param_2;
      uVar8 = *(uint *)(iVar2 + 0x8074);
      iVar2 = *(int *)(iVar2 + 0x8078);
      uVar5 = 0xffffffff;
      if (((uVar8 == param_4) && (iVar4 = 5, iVar2 == param_5)) ||
         ((uVar8 == 0xffffffff && (iVar4 = 3, iVar2 == -1)))) goto LAB_00025008;
      bVar1 = uVar8 == 0 && iVar2 == 0;
      iVar4 = 2;
      goto LAB_00024ea0;
    }
    uVar6 = 0;
    if (param_9 - param_6 == -1) {
      return 0xffffffff;
    }
    iVar2 = param_3 * 0xa30 + param_2 + 0x8070;
    do {
      for (uVar7 = uVar6;
          ((int)uVar7 < (int)(uVar6 + param_6) &&
          ((*(uint *)(param_8 + ((int)uVar7 >> 5) * 4) >> (uVar7 & 0x1f) & 1) == 0));
          uVar7 = uVar7 + 1) {
      }
      uVar5 = param_4;
      if (uVar7 == uVar6 + param_6) {
        uVar7 = *(uint *)(iVar2 + 4);
        iVar4 = *(int *)(iVar2 + 8);
        if ((uVar7 == param_4) && (iVar4 == param_5)) {
          iVar4 = 5;
          goto LAB_00025008;
        }
        if ((uVar7 == 0xffffffff) && (iVar4 == -1)) {
          if (uVar10 == 0xffffffff) {
            uVar10 = uVar6;
          }
        }
        else if (uVar7 == 0 && iVar4 == 0) {
          if (uVar9 == 0xffffffff) {
            uVar9 = uVar6;
          }
        }
        else {
          uVar7 = (uint)*(ushort *)((param_3 * 0x518 + uVar6) * 2 + param_2 + 0x8874);
          if (uVar7 < uVar11) {
            uVar8 = uVar6;
            uVar11 = uVar7;
          }
        }
      }
      uVar6 = uVar6 + 1;
      iVar2 = iVar2 + 8;
    } while (uVar6 < (param_9 - param_6) + 1U);
    if (uVar9 != 0xffffffff) {
      iVar4 = 2;
      goto LAB_00025008;
    }
    if (uVar10 != 0xffffffff) {
LAB_00024ff0:
      iVar4 = 3;
      goto LAB_00025008;
    }
LAB_00024fd4:
    if (uVar8 == 0xffffffff) {
      return 0xffffffff;
    }
  }
  iVar4 = 4;
LAB_00025008:
  uStack00000024 = param_4;
  iStack00000028 = param_5;
                    
                    
  uVar3 = (*(code *)((int)(*(unsigned char *)0x00025024) + ((unsigned char *)0x00025024)[iVar4]))(uVar5);
  return uVar3;
}

/* _PPEmulatorProgramSetupHandlesFromPPStream @ 0x25218 (844 bytes) */
int _PPEmulatorProgramSetupHandlesFromPPStream(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  int param_3;
{
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
  iVar2 = 0;
  iVar4 = *(int *)(param_1 + 0x80);
  for (; iVar5 != 0; iVar5 = iVar5 + -1) {
    local_2c = iVar2 * 0x10;
    iVar2 = iVar2 + 1;
    *(int *)(local_2c + iVar4) = local_2c;
    iVar3 = local_2c + iVar4;
    *(int *)(iVar3 + 4) = local_2c + 4;
    *(int *)(iVar3 + 8) = local_2c + 8;
    *(int *)(iVar3 + 0xc) = local_2c + 0xc;
  }
  iVar2 = *(int *)(param_1 + 0x8c);
  for (iVar5 = **(int **)(param_3 + 0x1c); iVar5 != 0; iVar5 = *(int *)(iVar5 + 8)) {
    _PPStreamChunkGetStream(&local_40,iVar5,param_3,auStack_30,0);
    ((int (*)())_gleVPGetResultOffset)(param_2,local_40,local_3c,&local_2c,auStack_28);
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
      ((int (*)())_gleVPGetParameterPtr)(param_2,local_40,local_3c,&local_2c,local_24);
      *(int *)(iVar2 + (uint)*(ushort *)(iVar5 + 0x12) * 0x10) = local_2c;
      *(int *)((uint)*(ushort *)(iVar5 + 0x12) * 0x10 + iVar2 + 4) = local_2c + local_24[0];
      *(int *)((uint)*(ushort *)(iVar5 + 0x12) * 0x10 + iVar2 + 8) = local_2c + local_24[0] * 2;
      *(int *)((uint)*(ushort *)(iVar5 + 0x12) * 0x10 + iVar2 + 0xc) = local_2c + local_24[0] * 3;
    }
  }
  return;
}

/* _gleVPGetResultOffset @ 0x25564 (204 bytes) */
int _gleVPGetResultOffset(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
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
int _gleVPGetParameterPtr(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
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
int _glePPUpdateProgram(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
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
  uVar8 = 0;
  if (iVar5 < 1) {
    return;
  }
  do {
    uVar6 = *(uint *)(uVar8 * 8 + iVar2 + iVar3 * 8);
    uVar9 = (undefined1)uVar8;
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
    iVar7 = ((int)uVar8 >> 5) * 4 + param_2;
    *(uint *)(iVar7 + 0x18) = *(uint *)(iVar7 + 0x18) | 1 << (uVar8 & 0x1f);
switchD_00025bb0_caseD_0:
    uVar8 = uVar8 + 1;
    if (iVar5 <= (int)uVar8) {
      return;
    }
  } while( true );
}

/* _gleVPEnable @ 0x25fc4 (128 bytes) */
double _gleVPEnable(int param_1,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  ((void (*)())_gleVPChanged)(param_1,fparam_1,fparam_2,fparam_3,fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
  if (*(char *)(param_1 + 0x30aa) != '\0') {
    *(undefined1 *)(param_1 + 0x316b) = *(undefined1 *)(param_1 + 0x4fea);
    *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x800;
  }
  _gleSetColorMaterialEnable(param_1);
  _gleUpdateInverseNeeds(param_1);
  _gleUpdatePrimitiveData(param_1);
  _gleUpdateTextureTransform(param_1);
  _gleUpdatePolyMode(param_1);
  *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x400000;
  return;
}

/* _gleVPChanged @ 0x26044 (184 bytes) */
void _gleVPChanged(int param_1,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint *puVar6;
  int iVar7;
  
  if (*(int *)(param_1 + 0x5434) == 0) {
    iVar3 = 9;
    puVar6 = (uint *)(*(int *)(param_1 + 0x5420) + 0x28);
    iVar5 = param_1;
    do {
      uVar2 = *puVar6;
      puVar6 = puVar6 + 1;
      *(uint *)(iVar5 + 0x324) = *(uint *)(iVar5 + 0x324) | uVar2;
      iVar5 = iVar5 + 4;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  else {
    iVar3 = *(int *)(param_1 + 0x5430);
    iVar7 = 9;
    iVar4 = 0;
    iVar5 = param_1;
    do {
      iVar1 = iVar4 + *(int *)(iVar3 + 0x20);
      iVar4 = iVar4 + 4;
      *(uint *)(iVar5 + 0x324) = *(uint *)(iVar5 + 0x324) | *(uint *)(iVar1 + 8);
      iVar5 = iVar5 + 4;
      iVar7 = iVar7 + -1;
    } while (iVar7 != 0);
  }
  ((void (*)())_gleUpdateViewScissorData)(param_1,fparam_1,fparam_2,fparam_3,fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
  *(uint *)(param_1 + 0x50ac) = *(uint *)(param_1 + 0x50ac) | 1;
  _gleSelectVertexSubmitFunc(param_1);
  return;
}

/* _glProgramLocalParameter4fvARB_Exec @ 0x260fc (344 bytes) */
int _glProgramLocalParameter4fvARB_Exec(param_1, param_2, param_3, param_4)
  int param_1;
  uint param_2;
  uint param_3;
  undefined4 *param_4;
{
  byte bVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  if (param_2 == 0x8620) {
    iVar5 = 0;
    if (param_3 < 0x100) {
      uVar2 = *(uint *)(param_1 + 0x31c) | 0x400000;
LAB_00026190:
      *(uint *)(param_1 + 0x31c) = uVar2;
      if (*(int *)(param_1 + 0x5434) == 0) {
        bVar1 = *(byte *)(param_3 + *(int *)(param_1 + 0x5420) + 0x58);
      }
      else {
        bVar1 = *(byte *)(param_3 + *(int *)(*(int *)(param_1 + 0x5430) + 0x20) + 0x8c);
      }
      iVar7 = (bVar1 >> 3 & 0x1c) + param_1;
      iVar4 = *(int *)(param_1 + 0x5424);
      iVar6 = iVar5 * 4 + param_1;
      *(uint *)(iVar7 + 0x324) = *(uint *)(iVar7 + 0x324) | 1 << (bVar1 & 0x1f);
      bVar1 = *(byte *)(param_3 + iVar4 + 0x58);
      iVar4 = (bVar1 >> 3 & 0x1c) + param_1;
      iVar5 = *(int *)(iVar6 + 0x5420);
      *(uint *)(iVar4 + 0x348) = *(uint *)(iVar4 + 0x348) | 1 << (bVar1 & 0x1f);
      iVar5 = *(int *)(iVar5 + 0x4e0);
      *(undefined4 *)(iVar5 + param_3 * 0x10) = *param_4;
      iVar5 = iVar5 + param_3 * 0x10;
      *(undefined4 *)(iVar5 + 4) = param_4[1];
      *(undefined4 *)(iVar5 + 8) = param_4[2];
      *(undefined4 *)(iVar5 + 0xc) = param_4[3];
      ((int (*)())_gleModifyPluginPipelineProgram)(param_1,*(int *)(iVar6 + 0x5420) + 0x10,2);
      return;
    }
  }
  else {
    if (param_2 < 0x8621) {
      uVar2 = 0x8200;
    }
    else {
      uVar2 = 0x8804;
    }
    if (param_2 != uVar2) {
      if (*(int *)(param_1 + 0x7574) != 0) {
        return;
      }
      uVar3 = 0x500;
      goto LAB_00026188;
    }
    iVar5 = 1;
    if (param_3 < 0x80) {
      uVar2 = *(uint *)(param_1 + 0x31c) | 0x1000000;
      goto LAB_00026190;
    }
  }
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  uVar3 = 0x501;
LAB_00026188:
  *(undefined4 *)(param_1 + 0x7574) = uVar3;
  return;
}

/* _gleModifyPluginPipelineProgram @ 0x26254 (120 bytes) */
int _gleModifyPluginPipelineProgram(param_1, param_2, param_3)
  int param_1;
  int param_2;
  undefined4 param_3;
{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  
  iVar4 = param_1 + 0x10000;
  iVar5 = 0;
  if (*(char *)(param_1 + 0x85a4) != '\0') {
    puVar6 = (undefined4 *)(param_2 + 0x498);
    do {
      piVar1 = (int *)(iVar4 + -0x777c);
      uVar3 = *puVar6;
      iVar5 = iVar5 + 1;
      puVar6 = puVar6 + 1;
      puVar2 = (undefined4 *)(iVar4 + -0x7a54);
      iVar4 = iVar4 + 0x2e0;
      (**(code **)(*piVar1 + 0x194))(*puVar2,uVar3,param_3);
    } while (iVar5 < (int)(uint)*(byte *)(param_1 + 0x85a4));
  }
  return;
}

/* _gleVPDisable @ 0x262cc (140 bytes) */
int _gleVPDisable(param_1)
  int param_1;
{
  undefined4 extraout_r3;
  
  if (*(char *)(param_1 + 0x30aa) != '\0') {
    *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x800;
    *(bool *)(param_1 + 0x316b) = *(short *)(param_1 + 0x30a8) == -0x7e06;
  }
  _gleSetColorMaterialEnable(param_1);
  _gleUpdateInverseNeeds(param_1);
  _gleUpdatePrimitiveData(param_1);
  _gleSelectVertexSubmitFunc(param_1);
  _gleUpdateTextureTransform(param_1);
  _gleUpdatePolyMode(param_1);
  *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x400000;
  return extraout_r3;
}

/* _glPixelTransferi_Exec @ 0x26358 (3128 bytes) */
int _glPixelTransferi_Exec(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  uint param_3;
{
  float fVar1;
  float fVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  
  fVar2 = FLOAT_00108e54;
  fVar1 = FLOAT_00108e50;
  if (-1 < *(short *)(param_1 + 0x4a10)) {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar3 = 0x502;
    goto LAB_00026ef8;
  }
  if (param_2 == 0x8022) {
    uVar5 = 0x40000000;
    *(float *)(param_1 + 0x33a4) =
         (float)((double)CONCAT44(0x43300000,param_3 ^ 0x80000000) - DOUBLE_00108d58);
  }
  else {
    if (0x8022 < param_2) {
      if (param_2 == 0x870f) {
        uVar5 = 4;
        *(float *)(param_1 + 0x3224) =
             (float)((double)CONCAT44(0x43300000,param_3 ^ 0x80000000) - DOUBLE_00108d58);
      }
      else {
        if (param_2 < 0x8710) {
          if (param_2 == 0x80b7) {
            uVar5 = 0x80000;
            *(float *)(param_1 + 0x3374) =
                 (float)((double)CONCAT44(0x43300000,param_3 ^ 0x80000000) - DOUBLE_00108d58);
            fVar1 = fVar2;
          }
          else if (param_2 < 0x80b8) {
            if (param_2 == 0x80b4) {
              uVar5 = 0x10000;
              *(float *)(param_1 + 0x335c) =
                   (float)((double)CONCAT44(0x43300000,param_3 ^ 0x80000000) - DOUBLE_00108d58);
              fVar1 = fVar2;
            }
            else if (param_2 < 0x80b5) {
              if (param_2 != 0x8023) goto LAB_00026ee8;
              uVar5 = 0x80000000;
              *(float *)(param_1 + 0x33ac) =
                   (float)((double)CONCAT44(0x43300000,param_3 ^ 0x80000000) - DOUBLE_00108d58);
            }
            else if (param_2 == 0x80b5) {
              uVar5 = 0x20000;
              *(float *)(param_1 + 0x336c) =
                   (float)((double)CONCAT44(0x43300000,param_3 ^ 0x80000000) - DOUBLE_00108d58);
              fVar1 = fVar2;
            }
            else {
              if (param_2 != 0x80b6) goto LAB_00026ee8;
              uVar5 = 0x40000;
              *(float *)(param_1 + 0x3364) =
                   (float)((double)CONCAT44(0x43300000,param_3 ^ 0x80000000) - DOUBLE_00108d58);
              fVar1 = fVar2;
            }
          }
          else if (param_2 == 0x80ba) {
            uVar5 = 0x400000;
            *(float *)(param_1 + 0x3370) =
                 (float)((double)CONCAT44(0x43300000,param_3 ^ 0x80000000) - DOUBLE_00108d58);
          }
          else if (param_2 < 0x80bb) {
            if (param_2 == 0x80b8) {
              uVar5 = 0x100000;
              *(float *)(param_1 + 0x3360) =
                   (float)((double)CONCAT44(0x43300000,param_3 ^ 0x80000000) - DOUBLE_00108d58);
            }
            else {
              if (param_2 != 0x80b9) goto LAB_00026ee8;
              uVar5 = 0x200000;
              *(float *)(param_1 + 0x3368) =
                   (float)((double)CONCAT44(0x43300000,param_3 ^ 0x80000000) - DOUBLE_00108d58);
            }
          }
          else {
            if (param_2 != 0x80bb) {
              if (param_2 == 0x870e) {
                uVar5 = 1;
                *(float *)(param_1 + 0x321c) =
                     (float)((double)CONCAT44(0x43300000,param_3 ^ 0x80000000) - DOUBLE_00108d58);
                goto LAB_00026f44;
              }
              goto LAB_00026ee8;
            }
            uVar5 = 0x800000;
            *(float *)(param_1 + 0x3378) =
                 (float)((double)CONCAT44(0x43300000,param_3 ^ 0x80000000) - DOUBLE_00108d58);
          }
          goto LAB_00026f00;
        }
        if (param_2 == 0x8714) {
          uVar5 = 2;
          *(float *)(param_1 + 0x3218) =
               (float)((double)CONCAT44(0x43300000,param_3 ^ 0x80000000) - DOUBLE_00108d58);
          fVar2 = fVar1;
        }
        else if (param_2 < 0x8715) {
          if (param_2 == 0x8711) {
            uVar5 = 0x40;
            *(float *)(param_1 + 0x3234) =
                 (float)((double)CONCAT44(0x43300000,param_3 ^ 0x80000000) - DOUBLE_00108d58);
          }
          else if (param_2 < 0x8711) {
            uVar5 = 0x10;
            *(float *)(param_1 + 0x322c) =
                 (float)((double)CONCAT44(0x43300000,param_3 ^ 0x80000000) - DOUBLE_00108d58);
          }
          else if (param_2 == 0x8712) {
            uVar5 = 0x100;
            *(float *)(param_1 + 0x323c) =
                 (float)((double)CONCAT44(0x43300000,param_3 ^ 0x80000000) - DOUBLE_00108d58);
          }
          else {
            if (param_2 != 0x8713) goto LAB_00026ee8;
            uVar5 = 0x400;
            *(float *)(param_1 + 0x3244) =
                 (float)((double)CONCAT44(0x43300000,param_3 ^ 0x80000000) - DOUBLE_00108d58);
          }
        }
        else if (param_2 == 0x8717) {
          uVar5 = 0x80;
          *(float *)(param_1 + 0x3230) =
               (float)((double)CONCAT44(0x43300000,param_3 ^ 0x80000000) - DOUBLE_00108d58);
          fVar2 = fVar1;
        }
        else if (param_2 < 0x8718) {
          if (param_2 == 0x8715) {
            uVar5 = 8;
            *(float *)(param_1 + 0x3220) =
                 (float)((double)CONCAT44(0x43300000,param_3 ^ 0x80000000) - DOUBLE_00108d58);
            fVar2 = fVar1;
          }
          else {
            if (param_2 != 0x8716) goto LAB_00026ee8;
            uVar5 = 0x20;
            *(float *)(param_1 + 0x3228) =
                 (float)((double)CONCAT44(0x43300000,param_3 ^ 0x80000000) - DOUBLE_00108d58);
            fVar2 = fVar1;
          }
        }
        else if (param_2 == 0x8718) {
          uVar5 = 0x200;
          *(float *)(param_1 + 0x3238) =
               (float)((double)CONCAT44(0x43300000,param_3 ^ 0x80000000) - DOUBLE_00108d58);
          fVar2 = fVar1;
        }
        else {
          if (param_2 != 0x8719) goto LAB_00026ee8;
          uVar5 = 0x800;
          *(float *)(param_1 + 0x3240) =
               (float)((double)CONCAT44(0x43300000,param_3 ^ 0x80000000) - DOUBLE_00108d58);
          fVar2 = fVar1;
        }
      }
LAB_00026f44:
      uVar4 = *(uint *)(param_1 + 0x3418) & ~uVar5;
      if ((float)((double)CONCAT44(0x43300000,param_3 ^ 0x80000000) - DOUBLE_00108d58) != fVar2) {
        uVar4 = uVar4 | uVar5;
      }
      *(uint *)(param_1 + 0x3418) = uVar4;
      goto LAB_00026f80;
    }
    if (param_2 == 0xd1b) {
      uVar5 = 0x400;
      *(float *)(param_1 + 0x31f8) =
           (float)((double)CONCAT44(0x43300000,param_3 ^ 0x80000000) - DOUBLE_00108d58);
    }
    else if (param_2 < 0xd1c) {
      if (param_2 == 0xd14) {
        uVar5 = 0x10;
        *(float *)(param_1 + 0x31ec) =
             (float)((double)CONCAT44(0x43300000,param_3 ^ 0x80000000) - DOUBLE_00108d58);
        fVar1 = fVar2;
      }
      else if (param_2 < 0xd15) {
        if (param_2 == 0xd11) {
          uVar5 = 2;
        }
        else if (param_2 < 0xd12) {
          if (param_2 != 0xd10) {
LAB_00026ee8:
            if (*(int *)(param_1 + 0x7574) != 0) {
              return;
            }
            uVar3 = 0x500;
LAB_00026ef8:
            *(undefined4 *)(param_1 + 0x7574) = uVar3;
            return;
          }
          uVar5 = 1;
        }
        else if (param_2 == 0xd12) {
          *(uint *)(param_1 + 0x3214) = param_3;
          uVar5 = 4;
          fVar1 = FLOAT_00108e50;
        }
        else {
          if (param_2 != 0xd13) goto LAB_00026ee8;
          *(uint *)(param_1 + 0x3210) = param_3;
          uVar5 = 8;
          fVar1 = FLOAT_00108e50;
        }
      }
      else if (param_2 == 0xd18) {
        uVar5 = 0x20;
        *(float *)(param_1 + 0x31f4) =
             (float)((double)CONCAT44(0x43300000,param_3 ^ 0x80000000) - DOUBLE_00108d58);
        fVar1 = fVar2;
      }
      else if (param_2 < 0xd19) {
        if (param_2 != 0xd15) goto LAB_00026ee8;
        uVar5 = 0x100;
        *(float *)(param_1 + 0x31e8) =
             (float)((double)CONCAT44(0x43300000,param_3 ^ 0x80000000) - DOUBLE_00108d58);
      }
      else if (param_2 == 0xd19) {
        uVar5 = 0x200;
        *(float *)(param_1 + 0x31f0) =
             (float)((double)CONCAT44(0x43300000,param_3 ^ 0x80000000) - DOUBLE_00108d58);
      }
      else {
        if (param_2 != 0xd1a) goto LAB_00026ee8;
        uVar5 = 0x40;
        *(float *)(param_1 + 0x31fc) =
             (float)((double)CONCAT44(0x43300000,param_3 ^ 0x80000000) - DOUBLE_00108d58);
        fVar1 = fVar2;
      }
    }
    else if (param_2 == 0x801c) {
      uVar5 = 0x1000000;
      *(float *)(param_1 + 0x3390) =
           (float)((double)CONCAT44(0x43300000,param_3 ^ 0x80000000) - DOUBLE_00108d58);
      fVar1 = fVar2;
    }
    else if (param_2 < 0x801d) {
      if (param_2 == 0xd1d) {
        uVar5 = 0x800;
        *(float *)(param_1 + 0x3200) =
             (float)((double)CONCAT44(0x43300000,param_3 ^ 0x80000000) - DOUBLE_00108d58);
      }
      else if (param_2 < 0xd1d) {
        uVar5 = 0x80;
        *(float *)(param_1 + 0x3204) =
             (float)((double)CONCAT44(0x43300000,param_3 ^ 0x80000000) - DOUBLE_00108d58);
        fVar1 = fVar2;
      }
      else if (param_2 == 0xd1e) {
        uVar5 = 0x1000;
        *(float *)(param_1 + 0x320c) =
             (float)((double)CONCAT44(0x43300000,param_3 ^ 0x80000000) - DOUBLE_00108d58);
        fVar1 = fVar2;
      }
      else {
        if (param_2 != 0xd1f) goto LAB_00026ee8;
        uVar5 = 0x2000;
        *(float *)(param_1 + 0x3208) =
             (float)((double)CONCAT44(0x43300000,param_3 ^ 0x80000000) - DOUBLE_00108d58);
      }
    }
    else if (param_2 == 0x801f) {
      uVar5 = 0x8000000;
      *(float *)(param_1 + 0x33a8) =
           (float)((double)CONCAT44(0x43300000,param_3 ^ 0x80000000) - DOUBLE_00108d58);
      fVar1 = fVar2;
    }
    else if (param_2 < 0x8020) {
      if (param_2 == 0x801d) {
        uVar5 = 0x2000000;
        *(float *)(param_1 + 0x33a0) =
             (float)((double)CONCAT44(0x43300000,param_3 ^ 0x80000000) - DOUBLE_00108d58);
        fVar1 = fVar2;
      }
      else {
        if (param_2 != 0x801e) goto LAB_00026ee8;
        uVar5 = 0x4000000;
        *(float *)(param_1 + 0x3398) =
             (float)((double)CONCAT44(0x43300000,param_3 ^ 0x80000000) - DOUBLE_00108d58);
        fVar1 = fVar2;
      }
    }
    else if (param_2 == 0x8020) {
      uVar5 = 0x10000000;
      *(float *)(param_1 + 0x3394) =
           (float)((double)CONCAT44(0x43300000,param_3 ^ 0x80000000) - DOUBLE_00108d58);
    }
    else {
      if (param_2 != 0x8021) goto LAB_00026ee8;
      uVar5 = 0x20000000;
      *(float *)(param_1 + 0x339c) =
           (float)((double)CONCAT44(0x43300000,param_3 ^ 0x80000000) - DOUBLE_00108d58);
    }
  }
LAB_00026f00:
  uVar4 = *(uint *)(param_1 + 0x3414) & ~uVar5;
  if ((float)((double)CONCAT44(0x43300000,param_3 ^ 0x80000000) - DOUBLE_00108d58) != fVar1) {
    uVar4 = uVar4 | uVar5;
  }
  *(uint *)(param_1 + 0x3414) = uVar4;
LAB_00026f80:
  *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x200000;
  return;
}

/* _glTexImage3D_Exec @ 0x26f94 (800 bytes) */
int _glTexImage3D_Exec(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11)
  int param_1;
  undefined4 param_2;
  int param_3;
  undefined4 param_4;
  int param_5;
  int param_6;
  int param_7;
  undefined4 param_8;
  undefined4 param_9;
  undefined4 param_10;
  int param_11;
{
  byte bVar1;
  ushort uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  double dVar8;
  
  if (-1 < *(short *)(param_1 + 0x4a10)) goto LAB_000270fc;
  if ((param_11 == 0) && (*(char *)(param_1 + 0x31e6) != '\0')) {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar3 = 0x501;
    goto LAB_0002710c;
  }
  iVar6 = *(int *)(param_1 + 0x4a6c);
  if (iVar6 == 0) {
LAB_00027098:
    iVar6 = ((int (*)())_gleCheckTexImage3DArgs)(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,
                       param_10);
    if (iVar6 == 0) {
      return;
    }
    uVar2 = *(ushort *)(iVar6 + 0x24);
    if ((uVar2 & 0x3c00) == 0x1000) {
LAB_00027114:
      iVar5 = iVar6 + param_3 * 0x18;
      iVar4 = iVar5 + 0xc4;
      if ((*(byte *)(iVar5 + 0xcf) & 0x20) != 0) {
        _gleDeletePluginTextureLevel(param_1,iVar6,iVar4,0,param_3);
        if (*(int *)(iVar5 + 0xd8) != 0) {
          bVar1 = *(byte *)(iVar5 + 0xcf);
          if ((bVar1 & 1) == 0) {
            _gleFreeTextureLevel(param_1,iVar6,iVar4);
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
                        (param_1,iVar6,iVar4,param_4,param_5,param_6,param_7,param_8,param_9,
                         param_10,1,param_11);
      if ((iVar5 != 0) && (param_11 != 0)) {
        _gleTextureImagePut(param_1,iVar4,0,0,0,param_5,param_6,param_7,param_9,param_10,0,
                            param_1 + 0x31cc,param_11);
      }
      if ((((param_5 != 0) && (param_6 != 0)) && (param_7 != 0)) &&
         (((_gleCreatePluginTextureLevel(param_1,iVar6,iVar4,0,param_3,param_4),
           (*(uint *)(iVar6 + 0x6c) & 0x8000) != 0 && (*(short *)(iVar6 + 0x60) == param_3)) &&
          (iVar6 = _gleGenMipmapsToLevel(param_1,iVar6,0,param_3,0xf,1), iVar6 != 0)))) {
        return;
      }
      *(uint *)(param_1 + 0x314) =
           *(uint *)(param_1 + 0x314) | 1 << (*(uint *)(param_1 + 0x53d4) & 0x3f);
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
                      (param_1 + 0x31cc,param_5,param_6,param_7,param_9,param_10,param_11);
    iVar7 = *(int *)(iVar6 + 0x38);
    dVar8 = (double)((double (*)())_gleBytesPerElement)(param_10);
    iVar5 = (int)dVar8;
    if (iVar4 <= iVar7) {
      if (iVar5 == 0) {
        iVar5 = _glePixelBytes(param_9,param_10);
      }
      if (param_11 == (param_11 / iVar5) * iVar5) {
        if (*(int *)(iVar6 + 0x40) != 0) {
          _gleSynchronizePluginBuffer(param_1,iVar6 + 0x10);
        }
        param_11 = param_11 + *(int *)(iVar6 + 0x30);
        goto LAB_00027098;
      }
    }
  }
LAB_000270fc:
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  uVar3 = 0x502;
LAB_0002710c:
  *(undefined4 *)(param_1 + 0x7574) = uVar3;
  return;
}

/* _gleCheckTexImage3DArgs @ 0x272b4 (324 bytes) */
int _gleCheckTexImage3DArgs(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  int param_5;
  int param_6;
  int param_7;
  int param_8;
  undefined4 param_9;
  undefined4 param_10;
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  iVar3 = ((int (*)())_gleLookUpTexture3D)(param_1,param_2);
  if (iVar3 == 0) {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return 0;
    }
    uVar1 = 0x500;
    goto LAB_000273a4;
  }
  uVar7 = param_5 + param_8 * -2;
  uVar6 = param_6 + param_8 * -2;
  uVar5 = param_7 + param_8 * -2;
  if (-1 < (int)uVar7) {
    if ((uVar7 & uVar7 - 1) == 0) {
      iVar2 = *(int *)(param_1 + 0x468c);
    }
    else {
      iVar2 = *(int *)(param_1 + 0x468c);
      if ((*(uint *)(iVar2 + 0x124) & 0x80000) == 0) goto LAB_00027394;
    }
    uVar4 = (uint)*(ushort *)(iVar2 + 0xbe);
    if (((((((int)uVar7 <= (int)uVar4) && (-1 < (int)uVar6)) &&
          (((uVar6 & uVar6 - 1) == 0 || ((*(uint *)(iVar2 + 0x124) & 0x80000) != 0)))) &&
         (((int)uVar6 <= (int)uVar4 && (-1 < (int)uVar5)))) &&
        (((uVar5 & uVar5 - 1) == 0 || ((*(uint *)(iVar2 + 0x124) & 0x80000) != 0)))) &&
       ((int)uVar5 <= (int)uVar4)) {
      iVar2 = _gleCheckTexImageArgs(param_1,param_3,param_9,param_10,param_4,param_8,0,1);
      if (iVar2 != 0) {
        return iVar3;
      }
      return 0;
    }
  }
LAB_00027394:
  if (*(int *)(param_1 + 0x7574) != 0) {
    return 0;
  }
  uVar1 = 0x501;
LAB_000273a4:
  *(undefined4 *)(param_1 + 0x7574) = uVar1;
  return 0;
}

/* _gleLookUpTexture3D @ 0x273f8 (80 bytes) */
int _gleLookUpTexture3D(param_1, param_2)
  int param_1;
  int param_2;
{
  if (param_2 == 0x806f) {
    return *(int *)(*(int *)(param_1 + 0x53d4) * 0x14 + param_1 + 0x5158) + 0x10;
  }
  if (param_2 != 0x8070) {
    return 0;
  }
  return *(int *)(param_1 + 0x52ac) + 0x10;
}

/* _gleTextureImagePut_Slow @ 0x27448 (28188 bytes) */
int _gleTextureImagePut_Slow(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12, param_13)
  int param_1;
  int param_2;
  uint param_3;
  uint param_4;
  int param_5;
  int param_6;
  uint param_7;
  uint param_8;
  int param_9;
  int param_10;
  undefined4 param_11;
  int param_12;
  uint param_13;
{
  int iVar1;
  short sVar2;
  ushort uVar3;
  bool bVar4;
  double dVar5;
  double dVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  ushort uVar14;
  undefined1 uVar16;
  uint uVar12;
  uint uVar13;
  undefined2 uVar15;
  int iVar17;
  uint uVar18;
  code *pcVar19;
  code *pcVar20;
  int iVar21;
  uint uVar22;
  uint uVar23;
  int iVar24;
  int *piVar25;
  uint *puVar26;
  int iVar27;
  uint *puVar28;
  int iVar29;
  undefined1 *puVar30;
  uint *puVar31;
  double dVar32;
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
  int local_c0;
  int local_bc;
  int local_b8;
  int local_b4;
  int local_b0;
  int local_ac;
  float local_a8;
  float local_a4;
  int local_a0;
  int local_9c;
  float local_90;
  
  if (param_10 != 0x1a00) {
    bVar4 = false;
    iVar17 = param_5;
    iVar21 = param_6;
    uVar22 = param_7;
    uVar23 = param_8;
  }
  else {
    iVar17 = _gleImageSize(param_9,0x1a00,param_6,param_7);
    uVar18 = _malloc(iVar17 * param_8);
    if (uVar18 == 0) {
      if (*(int *)(param_1 + 0x7574) != 0) {
        return;
      }
      *(undefined4 *)(param_1 + 0x7574) = 0x505;
      return;
    }
    iVar21 = 0x1a00;
    iVar17 = param_9;
    uVar23 = uVar18;
    _gleFillImage(param_1,param_6,param_7,param_8,param_9,0x1a00,param_13,uVar18);
    bVar4 = true;
    uVar22 = param_13;
    param_13 = uVar18;
  }
  if (((((param_12 != 0) && (*(char *)(param_12 + 0x18) != '\0')) ||
       (((char)param_11 != '\0' &&
        ((((*(uint *)(param_1 + 0x3410) & 0x1ff) != 0 ||
          (uVar22 = *(uint *)(param_1 + 0x3414) & 0xff0000, uVar22 != 0)) && (param_9 != 0x1900)))))
       ) || ((param_10 == 0x140b || (param_10 == 0x1406)))) ||
     ((sVar2 = *(short *)(param_2 + 0x12), sVar2 == 0x140b ||
      (((sVar2 == 0x1406 || (sVar2 == 0)) || ((sVar2 == 0x1403 || (param_10 == 0x1a00)))))))) {
    _glgConvertType(param_9,param_10,auStack_168,auStack_164,iVar17,iVar21,uVar22,uVar23);
    piVar25 = &local_ac;
    uVar22 = param_7;
    iVar17 = param_12;
    _glePixelPackSettings
              (param_1,param_9,param_10,param_6,param_7,param_12,&local_b0,piVar25,&local_c0,
               &local_bc,&local_b8,&local_b4);
    uVar23 = 0;
    local_14c = 0;
    local_148 = 0x7efff;
    local_138 = 0;
    local_13c = 0;
    if ((char)param_11 != '\0') {
      uVar23 = *(uint *)(param_1 + 0x3410);
      if ((uVar23 & 0x20) != 0) {
        iVar21 = _gleLookUpNonProxyColorTable(param_1,0x80d0);
        uVar23 = *(uint *)(param_1 + 0x3410);
        local_128 = *(undefined4 *)(iVar21 + 0xc0);
        local_134 = (uint)*(ushort *)(iVar21 + 0xbc);
        local_130 = (uint)*(ushort *)(iVar21 + 0xbe);
        local_12c = (uint)*(ushort *)(iVar21 + 0xb0);
      }
      if ((uVar23 & 0x80) != 0) {
        iVar21 = _gleLookUpNonProxyColorTable(param_1,0x80d2);
        uVar23 = *(uint *)(param_1 + 0x3410);
        local_118 = *(undefined4 *)(iVar21 + 0xc0);
        local_124 = (uint)*(ushort *)(iVar21 + 0xbc);
        local_120 = (uint)*(ushort *)(iVar21 + 0xbe);
        local_11c = (uint)*(ushort *)(iVar21 + 0xb0);
      }
      if ((uVar23 & 0x40) != 0) {
        iVar21 = _gleLookUpNonProxyColorTable(param_1,0x80d1);
        local_108 = *(undefined4 *)(iVar21 + 0xc0);
        local_114 = (uint)*(ushort *)(iVar21 + 0xbc);
        local_110 = (uint)*(ushort *)(iVar21 + 0xbe);
        local_10c = (uint)*(ushort *)(iVar21 + 0xb0);
      }
    }
    if (param_12 == 0) {
      if (1 < (int)param_8) {
        local_b8 = local_c0 * param_7;
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
    local_144 = param_6;
    local_140 = param_7;
    _glgConvertType((uint)*(ushort *)(param_2 + 0x10),(uint)*(ushort *)(param_2 + 0x12),auStack_158,
                    puVar30,uVar22,iVar17,uVar23,piVar25);
    iVar21 = _glePixelBytes((uint)*(ushort *)(param_2 + 0x10),(uint)*(ushort *)(param_2 + 0x12));
    uVar23 = (uint)*(ushort *)(param_2 + 0xc);
    local_15c = _gleRowBytes((uint)*(ushort *)(param_2 + 0x10),(uint)*(ushort *)(param_2 + 0x12),
                             uVar23);
    iVar27 = local_15c * (uint)*(ushort *)(param_2 + 6);
    local_170 = param_13 + local_ac;
    local_16c = local_c0;
    if ((*(short *)(param_2 + 0x12) == 0) && (((param_3 != 0 || (param_4 != 0)) || (param_5 != 0))))
    {
      uVar3 = *(ushort *)(param_2 + 0x10);
      if (((0x83f3 < uVar3) || (0x83f1 < uVar3)) || (uVar23 = 8, uVar3 < 0x83f0)) {
        uVar23 = 0x10;
      }
      iVar24 = ((int)param_3 >> 2) + (uint)((int)param_3 < 0 && (param_3 & 3) != 0);
      local_160 = *(int *)(param_2 + 0x14) +
                  ((uint)(*(ushort *)(param_2 + 4) >> 2) *
                   (((int)param_4 >> 2) + (uint)((int)param_4 < 0 && (param_4 & 3) != 0)) + iVar24)
                  * uVar23;
    }
    else {
      iVar24 = local_15c * param_4;
      local_160 = iVar27 * param_5 + iVar24 + *(int *)(param_2 + 0x14) + iVar21 * param_3;
    }
    uVar18 = 0;
    while( true ) {
      uVar18 = uVar18 + 1;
      _glgProcessPixels(param_1 + 0x31a8,&local_170,uVar23,puVar30,uVar22,iVar17,iVar24,piVar25);
      if (uVar18 == param_8) break;
      local_160 = local_160 + iVar27;
      local_170 = local_170 + local_b8;
      iVar24 = local_b8;
    }
    goto LAB_0002e240;
  }
  iVar17 = _gleComponents((uint)*(ushort *)(param_2 + 0x10));
  iVar21 = _glePixelBytes((uint)*(ushort *)(param_2 + 0x10),(uint)*(ushort *)(param_2 + 0x12));
  puVar26 = (uint *)(*(int *)(param_2 + 0x14) +
                    iVar21 * ((uint)*(ushort *)(param_2 + 4) *
                              ((uint)*(ushort *)(param_2 + 6) * param_5 + param_4) + param_3));
  iVar21 = _gleRowBytes((uint)*(ushort *)(param_2 + 0x10),(uint)*(ushort *)(param_2 + 0x12),
                        (uint)*(ushort *)(param_2 + 4));
  iVar27 = iVar21 * (uint)*(ushort *)(param_2 + 6);
  _glePixelPackSettings
            (param_1,param_9,param_10,param_6,param_7,param_12,&local_b0,&local_ac,&local_c0,
             &local_bc,&local_b8,&local_b4);
  iVar24 = param_13 + local_ac;
  pcVar19 = (code *)((int (*)())_gleSelectPixelExtractFunc)(param_9,param_10);
  pcVar20 = (code *)((int (*)())_gleSelectModifyPixelFunc)(param_1,param_9);
  fVar7 = FLOAT_00108ea0;
  dVar6 = DOUBLE_00108da8;
  if (pcVar19 == (code *)0x0) {
    return;
  }
  local_1a4 = 0.0;
  local_1a0 = 1.0;
  local_1ac = 0.0;
  local_1a8 = 0.0;
  if (pcVar20 != (code *)0x0) {
    uVar3 = *(ushort *)(param_2 + 0x10);
    if (uVar3 == 0x190a) {
      if (*(short *)(param_2 + 0x12) == 1) {
        if (0 < (int)param_8) {
          do {
            uVar22 = param_7;
            puVar28 = puVar26;
            if (0 < (int)param_7) {
              do {
                fVar9 = FLOAT_00108f6c;
                fVar8 = FLOAT_00108e58;
                fVar7 = FLOAT_00108e54;
                iVar29 = param_6;
                puVar31 = puVar28;
                if (0 < param_6) {
                  do {
                    (*pcVar19)(auStack_1b0,iVar24);
                    _gleModifyPixelSignedRGBA(param_1,auStack_1b0);
                    if (fVar7 < local_1a0) {
                      uVar16 = 0x7f;
                    }
                    else {
                      uVar16 = 0x81;
                      if (fVar8 <= local_1a0) {
                        iVar1 = (int)(local_1a0 * fVar9);
                        (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)iVar1;
                        uVar16 = (undefined1)local_c8;
                        local_c8 = (longlong)iVar1;
                      }
                    }
                    *(undefined1 *)puVar31 = uVar16;
                    if (fVar7 < local_1ac) {
                      uVar16 = 0x7f;
                    }
                    else {
                      uVar16 = 0x81;
                      if (fVar8 <= local_1ac) {
                        iVar1 = (int)(local_1ac * fVar9);
                        (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)iVar1;
                        uVar16 = (undefined1)local_c8;
                        local_c8 = (longlong)iVar1;
                      }
                    }
                    iVar29 = iVar29 + -1;
                    *(undefined1 *)((int)puVar31 + 1) = uVar16;
                    iVar24 = iVar24 + local_b0;
                    puVar31 = (uint *)((int)puVar31 + iVar17);
                  } while (iVar29 != 0);
                }
                uVar22 = uVar22 - 1;
                iVar24 = iVar24 + local_bc;
                puVar28 = (uint *)((int)puVar28 + iVar21);
              } while (uVar22 != 0);
            }
            param_8 = param_8 - 1;
            puVar26 = (uint *)((int)puVar26 + iVar27);
            iVar24 = iVar24 + local_b4;
          } while (param_8 != 0);
        }
      }
      else if (0 < (int)param_8) {
        do {
          uVar22 = param_7;
          puVar28 = puVar26;
          if (0 < (int)param_7) {
            do {
              fVar9 = FLOAT_00108f70;
              fVar8 = FLOAT_00108e54;
              fVar7 = FLOAT_00108e50;
              iVar29 = param_6;
              puVar31 = puVar28;
              if (0 < param_6) {
                do {
                  local_1ac = fVar7;
                  local_1a0 = fVar8;
                  (*pcVar19)(auStack_1b0,iVar24);
                  (*pcVar20)(param_1,auStack_1b0);
                  if (fVar8 < local_1ac) {
                    uVar16 = 0xff;
                  }
                  else {
                    uVar16 = 0;
                    if (fVar7 <= local_1ac) {
                      iVar1 = (int)(local_1ac * fVar9);
                      (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)iVar1;
                      uVar16 = (undefined1)local_c8;
                      local_c8 = (longlong)iVar1;
                    }
                  }
                  *(undefined1 *)puVar31 = uVar16;
                  if (fVar8 < local_1a0) {
                    uVar16 = 0xff;
                  }
                  else {
                    uVar16 = 0;
                    if (fVar7 <= local_1a0) {
                      iVar1 = (int)(local_1a0 * fVar9);
                      (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)iVar1;
                      uVar16 = (undefined1)local_c8;
                      local_c8 = (longlong)iVar1;
                    }
                  }
                  iVar29 = iVar29 + -1;
                  *(undefined1 *)((int)puVar31 + 1) = uVar16;
                  iVar24 = iVar24 + local_b0;
                  puVar31 = (uint *)((int)puVar31 + iVar17);
                } while (iVar29 != 0);
              }
              uVar22 = uVar22 - 1;
              iVar24 = iVar24 + local_bc;
              puVar28 = (uint *)((int)puVar28 + iVar21);
            } while (uVar22 != 0);
          }
          param_8 = param_8 - 1;
          puVar26 = (uint *)((int)puVar26 + iVar27);
          iVar24 = iVar24 + local_b4;
        } while (param_8 != 0);
      }
      goto LAB_0002e240;
    }
    if (uVar3 < 0x190b) {
      if (uVar3 == 0x1907) {
        uVar3 = *(ushort *)(param_2 + 0x12);
        if (uVar3 == 0x8362) {
          if (0 < (int)param_8) {
            do {
              uVar22 = param_7;
              puVar28 = puVar26;
              if (0 < (int)param_7) {
                do {
                  fVar7 = FLOAT_00108f70;
                  iVar17 = param_6;
                  puVar31 = puVar28;
                  if (0 < param_6) {
                    do {
                      (*pcVar19)(auStack_1b0,iVar24);
                      (*pcVar20)(param_1,auStack_1b0);
                      iVar17 = iVar17 + -1;
                      local_c8 = (longlong)(int)(local_1a4 * fVar7);
                      local_d0 = (longlong)(int)(local_1a8 * fVar7);
                      local_d8 = (longlong)(int)(local_1ac * fVar7);
                      *(byte *)puVar31 =
                           (byte)(int)(local_1a4 * fVar7) & 0xc0 |
                           (byte)((uint)(int)(local_1a8 * fVar7) >> 2) & 0x38 |
                           (byte)((uint)(int)(local_1ac * fVar7) >> 5) & 7;
                      iVar24 = iVar24 + local_b0;
                      puVar31 = (uint *)((int)puVar31 + 1);
                    } while (iVar17 != 0);
                  }
                  uVar22 = uVar22 - 1;
                  iVar24 = iVar24 + local_bc;
                  puVar28 = (uint *)((int)puVar28 + iVar21);
                } while (uVar22 != 0);
              }
              param_8 = param_8 - 1;
              puVar26 = (uint *)((int)puVar26 + iVar27);
              iVar24 = iVar24 + local_b4;
            } while (param_8 != 0);
          }
          goto LAB_0002e240;
        }
        if (uVar3 < 0x8363) {
          if (uVar3 == 8) {
            if (0 < (int)param_8) {
              do {
                uVar22 = param_7;
                puVar28 = puVar26;
                if (0 < (int)param_7) {
                  do {
                    fVar9 = FLOAT_00108f6c;
                    fVar8 = FLOAT_00108e58;
                    fVar7 = FLOAT_00108e54;
                    iVar29 = param_6;
                    puVar31 = puVar28;
                    if (0 < param_6) {
                      do {
                        (*pcVar19)(auStack_1b0,iVar24);
                        _gleModifyPixelSignedRGBA(param_1,auStack_1b0);
                        if (fVar7 < local_1ac) {
                          uVar16 = 0x7f;
                        }
                        else {
                          uVar16 = 0x81;
                          if (fVar8 <= local_1ac) {
                            (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)(int)(local_1ac * fVar9);
                            uVar16 = (undefined1)local_c8;
                            local_c8 = (longlong)(int)(local_1ac * fVar9);
                          }
                        }
                        *(undefined1 *)puVar31 = uVar16;
                        if (fVar7 < local_1a8) {
                          uVar16 = 0x7f;
                        }
                        else {
                          uVar16 = 0x81;
                          if (fVar8 <= local_1a8) {
                            (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)(int)(local_1a8 * fVar9);
                            uVar16 = (undefined1)local_c8;
                            local_c8 = (longlong)(int)(local_1a8 * fVar9);
                          }
                        }
                        *(undefined1 *)((int)puVar31 + 1) = uVar16;
                        if (fVar7 < local_1a4) {
                          uVar16 = 0x7f;
                        }
                        else {
                          uVar16 = 0x81;
                          if (fVar8 <= local_1a4) {
                            (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)(int)(local_1a4 * fVar9);
                            uVar16 = (undefined1)local_c8;
                            local_c8 = (longlong)(int)(local_1a4 * fVar9);
                          }
                        }
                        iVar29 = iVar29 + -1;
                        *(undefined1 *)((int)puVar31 + 2) = uVar16;
                        *(undefined1 *)((int)puVar31 + 3) = 0;
                        iVar24 = iVar24 + local_b0;
                        puVar31 = (uint *)((int)puVar31 + iVar17);
                      } while (iVar29 != 0);
                    }
                    uVar22 = uVar22 - 1;
                    iVar24 = iVar24 + local_bc;
                    puVar28 = (uint *)((int)puVar28 + iVar21);
                  } while (uVar22 != 0);
                }
                param_8 = param_8 - 1;
                puVar26 = (uint *)((int)puVar26 + iVar27);
                iVar24 = iVar24 + local_b4;
              } while (param_8 != 0);
            }
            goto LAB_0002e240;
          }
          if (uVar3 == 0x8032) {
            if (0 < (int)param_8) {
              do {
                uVar22 = param_7;
                puVar28 = puVar26;
                if (0 < (int)param_7) {
                  do {
                    fVar7 = FLOAT_00108f70;
                    iVar17 = param_6;
                    puVar31 = puVar28;
                    if (0 < param_6) {
                      do {
                        (*pcVar19)(auStack_1b0,iVar24);
                        (*pcVar20)(param_1,auStack_1b0);
                        iVar17 = iVar17 + -1;
                        local_c8 = (longlong)(int)(local_1ac * fVar7);
                        local_d0 = (longlong)(int)(local_1a8 * fVar7);
                        local_d8 = (longlong)(int)(local_1a4 * fVar7);
                        *(byte *)puVar31 =
                             (byte)(int)(local_1ac * fVar7) & 0xe0 |
                             (byte)((uint)(int)(local_1a8 * fVar7) >> 3) & 0x1c |
                             (byte)((uint)(int)(local_1a4 * fVar7) >> 6) & 3;
                        iVar24 = iVar24 + local_b0;
                        puVar31 = (uint *)((int)puVar31 + 1);
                      } while (iVar17 != 0);
                    }
                    uVar22 = uVar22 - 1;
                    iVar24 = iVar24 + local_bc;
                    puVar28 = (uint *)((int)puVar28 + iVar21);
                  } while (uVar22 != 0);
                }
                param_8 = param_8 - 1;
                puVar26 = (uint *)((int)puVar26 + iVar27);
                iVar24 = iVar24 + local_b4;
              } while (param_8 != 0);
            }
            goto LAB_0002e240;
          }
        }
        else {
          if (uVar3 == 0x8363) {
            if (0 < (int)param_8) {
              do {
                uVar22 = param_7;
                puVar28 = puVar26;
                if (0 < (int)param_7) {
                  do {
                    if (0 < param_6) {
                      local_90 = fVar7;
                      iVar17 = param_6;
                      puVar31 = puVar28;
                      do {
                        (*pcVar19)(auStack_1b0,iVar24);
                        (*pcVar20)(param_1,auStack_1b0);
                        iVar17 = iVar17 + -1;
                        local_c8 = (longlong)(int)(local_1ac * fVar7);
                        local_d0 = (longlong)(int)(local_1a8 * fVar7);
                        local_d8 = (longlong)(int)(local_1a4 * fVar7);
                        *(ushort *)puVar31 =
                             (ushort)(int)(local_1ac * fVar7) & 0xf800 |
                             (ushort)((uint)(int)(local_1a8 * fVar7) >> 5) & 0x7e0 |
                             (ushort)((uint)(int)(local_1a4 * fVar7) >> 0xb) & 0x1f;
                        puVar31 = (uint *)((int)puVar31 + 2);
                        iVar24 = iVar24 + local_b0;
                      } while (iVar17 != 0);
                    }
                    uVar22 = uVar22 - 1;
                    iVar24 = iVar24 + local_bc;
                    puVar28 = (uint *)((int)puVar28 + iVar21);
                  } while (uVar22 != 0);
                }
                param_8 = param_8 - 1;
                puVar26 = (uint *)((int)puVar26 + iVar27);
                iVar24 = iVar24 + local_b4;
              } while (param_8 != 0);
            }
            goto LAB_0002e240;
          }
          if (uVar3 == 0x8364) {
            if (0 < (int)param_8) {
              do {
                uVar22 = param_7;
                puVar28 = puVar26;
                if (0 < (int)param_7) {
                  do {
                    if (0 < param_6) {
                      local_90 = fVar7;
                      iVar17 = param_6;
                      puVar31 = puVar28;
                      do {
                        (*pcVar19)(auStack_1b0,iVar24);
                        (*pcVar20)(param_1,auStack_1b0);
                        iVar17 = iVar17 + -1;
                        local_c8 = (longlong)(int)(local_1a4 * fVar7);
                        local_d0 = (longlong)(int)(local_1a8 * fVar7);
                        local_d8 = (longlong)(int)(local_1ac * fVar7);
                        *(ushort *)puVar31 =
                             (ushort)(int)(local_1a4 * fVar7) & 0xf800 |
                             (ushort)((uint)(int)(local_1a8 * fVar7) >> 5) & 0x7e0 |
                             (ushort)((uint)(int)(local_1ac * fVar7) >> 0xb) & 0x1f;
                        puVar31 = (uint *)((int)puVar31 + 2);
                        iVar24 = iVar24 + local_b0;
                      } while (iVar17 != 0);
                    }
                    uVar22 = uVar22 - 1;
                    iVar24 = iVar24 + local_bc;
                    puVar28 = (uint *)((int)puVar28 + iVar21);
                  } while (uVar22 != 0);
                }
                param_8 = param_8 - 1;
                puVar26 = (uint *)((int)puVar26 + iVar27);
                iVar24 = iVar24 + local_b4;
              } while (param_8 != 0);
            }
            goto LAB_0002e240;
          }
        }
        if (0 < (int)param_8) {
          do {
            uVar22 = param_7;
            puVar28 = puVar26;
            if (0 < (int)param_7) {
              do {
                fVar9 = FLOAT_00108f70;
                fVar8 = FLOAT_00108e54;
                fVar7 = FLOAT_00108e50;
                iVar29 = param_6;
                puVar31 = puVar28;
                if (0 < param_6) {
                  do {
                    local_1ac = fVar7;
                    local_1a8 = fVar7;
                    local_1a4 = fVar7;
                    (*pcVar19)(auStack_1b0,iVar24);
                    (*pcVar20)(param_1,auStack_1b0);
                    if (fVar8 < local_1ac) {
                      uVar16 = 0xff;
                    }
                    else {
                      uVar16 = 0;
                      if (fVar7 <= local_1ac) {
                        (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)(int)(local_1ac * fVar9);
                        uVar16 = (undefined1)local_c8;
                        local_c8 = (longlong)(int)(local_1ac * fVar9);
                      }
                    }
                    *(undefined1 *)puVar31 = uVar16;
                    if (fVar8 < local_1a8) {
                      uVar16 = 0xff;
                    }
                    else {
                      uVar16 = 0;
                      if (fVar7 <= local_1a8) {
                        (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)(int)(local_1a8 * fVar9);
                        uVar16 = (undefined1)local_c8;
                        local_c8 = (longlong)(int)(local_1a8 * fVar9);
                      }
                    }
                    *(undefined1 *)((int)puVar31 + 1) = uVar16;
                    if (fVar8 < local_1a4) {
                      uVar16 = 0xff;
                    }
                    else {
                      uVar16 = 0;
                      if (fVar7 <= local_1a4) {
                        (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)(int)(local_1a4 * fVar9);
                        uVar16 = (undefined1)local_c8;
                        local_c8 = (longlong)(int)(local_1a4 * fVar9);
                      }
                    }
                    iVar29 = iVar29 + -1;
                    *(undefined1 *)((int)puVar31 + 2) = uVar16;
                    iVar24 = iVar24 + local_b0;
                    puVar31 = (uint *)((int)puVar31 + iVar17);
                  } while (iVar29 != 0);
                }
                uVar22 = uVar22 - 1;
                iVar24 = iVar24 + local_bc;
                puVar28 = (uint *)((int)puVar28 + iVar21);
              } while (uVar22 != 0);
            }
            param_8 = param_8 - 1;
            puVar26 = (uint *)((int)puVar26 + iVar27);
            iVar24 = iVar24 + local_b4;
          } while (param_8 != 0);
        }
        goto LAB_0002e240;
      }
      if (uVar3 < 0x1908) {
        if (uVar3 == 0x1906) {
          if (*(short *)(param_2 + 0x12) == 0x1400) {
            if (0 < (int)param_8) {
              do {
                uVar22 = param_7;
                puVar28 = puVar26;
                if (0 < (int)param_7) {
                  do {
                    fVar9 = FLOAT_00108f70;
                    fVar8 = FLOAT_00108e54;
                    fVar7 = FLOAT_00108e50;
                    iVar29 = param_6;
                    puVar31 = puVar28;
                    if (0 < param_6) {
                      do {
                        (*pcVar19)(auStack_1b0,iVar24);
                        (*pcVar20)(param_1,auStack_1b0);
                        if (fVar8 < local_1a0) {
                          uVar16 = 0xff;
                        }
                        else {
                          uVar16 = 0;
                          if (fVar7 <= local_1a0) {
                            (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)(int)(local_1a0 * fVar9);
                            uVar16 = (undefined1)local_c8;
                            local_c8 = (longlong)(int)(local_1a0 * fVar9);
                          }
                        }
                        iVar29 = iVar29 + -1;
                        *(undefined1 *)puVar31 = uVar16;
                        iVar24 = iVar24 + local_b0;
                        puVar31 = (uint *)((int)puVar31 + iVar17);
                      } while (iVar29 != 0);
                    }
                    uVar22 = uVar22 - 1;
                    iVar24 = iVar24 + local_bc;
                    puVar28 = (uint *)((int)puVar28 + iVar21);
                  } while (uVar22 != 0);
                }
                param_8 = param_8 - 1;
                puVar26 = (uint *)((int)puVar26 + iVar27);
                iVar24 = iVar24 + local_b4;
              } while (param_8 != 0);
            }
          }
          else if (0 < (int)param_8) {
            do {
              uVar22 = param_7;
              puVar28 = puVar26;
              if (0 < (int)param_7) {
                do {
                  fVar9 = FLOAT_00108f70;
                  fVar8 = FLOAT_00108e54;
                  fVar7 = FLOAT_00108e50;
                  iVar29 = param_6;
                  puVar31 = puVar28;
                  if (0 < param_6) {
                    do {
                      local_1a0 = fVar8;
                      (*pcVar19)(auStack_1b0,iVar24);
                      (*pcVar20)(param_1,auStack_1b0);
                      if (fVar8 < local_1a0) {
                        uVar16 = 0xff;
                      }
                      else {
                        uVar16 = 0;
                        if (fVar7 <= local_1a0) {
                          (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)(int)(local_1a0 * fVar9);
                          uVar16 = (undefined1)local_c8;
                          local_c8 = (longlong)(int)(local_1a0 * fVar9);
                        }
                      }
                      iVar29 = iVar29 + -1;
                      *(undefined1 *)puVar31 = uVar16;
                      iVar24 = iVar24 + local_b0;
                      puVar31 = (uint *)((int)puVar31 + iVar17);
                    } while (iVar29 != 0);
                  }
                  uVar22 = uVar22 - 1;
                  iVar24 = iVar24 + local_bc;
                  puVar28 = (uint *)((int)puVar28 + iVar21);
                } while (uVar22 != 0);
              }
              param_8 = param_8 - 1;
              puVar26 = (uint *)((int)puVar26 + iVar27);
              iVar24 = iVar24 + local_b4;
            } while (param_8 != 0);
          }
          goto LAB_0002e240;
        }
      }
      else {
        if (uVar3 == 0x1908) {
          uVar3 = *(ushort *)(param_2 + 0x12);
          if (uVar3 == 0x8036) {
            if (0 < (int)param_8) {
              do {
                uVar22 = param_7;
                puVar28 = puVar26;
                if (0 < (int)param_7) {
                  do {
                    dVar5 = DOUBLE_00108d80;
                    puVar31 = puVar28;
                    iVar17 = param_6;
                    if (0 < param_6) {
                      do {
                        (*pcVar19)(auStack_1b0,iVar24);
                        (*pcVar20)(param_1,auStack_1b0);
                        dVar32 = (double)local_1ac * dVar6;
                        if (dVar5 <= dVar32) {
                          uVar23 = (uint)(int)(dVar32 - dVar5);
                          local_d0 = (longlong)(int)uVar23;
                          uVar23 = uVar23 ^ 0x80000000;
                        }
                        else {
                          uVar23 = (uint)(int)dVar32;
                          local_c8 = (longlong)(int)uVar23;
                        }
                        dVar32 = (double)local_1a8 * dVar6;
                        if (DOUBLE_00108d80 <= dVar32) {
                          local_e0 = (longlong)(int)(dVar32 - DOUBLE_00108d80);
                          uVar18 = (int)(dVar32 - DOUBLE_00108d80) ^ 0x80000000;
                        }
                        else {
                          uVar18 = (uint)(int)dVar32;
                          local_d8 = (longlong)(int)uVar18;
                        }
                        dVar32 = (double)local_1a4 * dVar6;
                        if (DOUBLE_00108d80 <= dVar32) {
                          local_f0 = (longlong)(int)(dVar32 - DOUBLE_00108d80);
                          uVar12 = (int)(dVar32 - DOUBLE_00108d80) ^ 0x80000000;
                        }
                        else {
                          uVar12 = (uint)(int)dVar32;
                          local_e8 = (longlong)(int)uVar12;
                        }
                        dVar32 = (double)local_1a0 * dVar6;
                        if (DOUBLE_00108d80 <= dVar32) {
                          local_100 = (longlong)(int)(dVar32 - DOUBLE_00108d80);
                          uVar13 = (int)(dVar32 - DOUBLE_00108d80) ^ 0x80000000;
                        }
                        else {
                          uVar13 = (uint)(int)dVar32;
                          local_f8 = (longlong)(int)uVar13;
                        }
                        iVar17 = iVar17 + -1;
                        *puVar31 = uVar23 & 0xffc00000 | uVar18 >> 10 & 0x3ff000 |
                                   uVar12 >> 0x14 & 0xffc | uVar13 >> 0x1e;
                        iVar24 = iVar24 + local_b0;
                        puVar31 = puVar31 + 1;
                      } while (iVar17 != 0);
                    }
                    uVar22 = uVar22 - 1;
                    iVar24 = iVar24 + local_bc;
                    puVar28 = (uint *)((int)puVar28 + iVar21);
                  } while (uVar22 != 0);
                }
                param_8 = param_8 - 1;
                puVar26 = (uint *)((int)puVar26 + iVar27);
                iVar24 = iVar24 + local_b4;
              } while (param_8 != 0);
            }
            goto LAB_0002e240;
          }
          if (uVar3 < 0x8037) {
            if (uVar3 == 0x8033) {
              if (0 < (int)param_8) {
                do {
                  uVar22 = param_7;
                  puVar28 = puVar26;
                  if (0 < (int)param_7) {
                    do {
                      if (0 < param_6) {
                        local_90 = fVar7;
                        puVar31 = puVar28;
                        iVar17 = param_6;
                        do {
                          (*pcVar19)(auStack_1b0,iVar24);
                          (*pcVar20)(param_1,auStack_1b0);
                          iVar17 = iVar17 + -1;
                          local_c8 = (longlong)(int)(local_1ac * fVar7);
                          local_d0 = (longlong)(int)(local_1a8 * fVar7);
                          local_d8 = (longlong)(int)(local_1a4 * fVar7);
                          local_e0 = (longlong)(int)(local_1a0 * fVar7);
                          *(ushort *)puVar31 =
                               (ushort)(int)(local_1ac * fVar7) & 0xf000 |
                               (ushort)((uint)(int)(local_1a8 * fVar7) >> 4) & 0xf00 |
                               (ushort)((uint)(int)(local_1a4 * fVar7) >> 8) & 0xf0 |
                               (ushort)((uint)(int)(local_1a0 * fVar7) >> 0xc) & 0xf;
                          puVar31 = (uint *)((int)puVar31 + 2);
                          iVar24 = iVar24 + local_b0;
                        } while (iVar17 != 0);
                      }
                      uVar22 = uVar22 - 1;
                      iVar24 = iVar24 + local_bc;
                      puVar28 = (uint *)((int)puVar28 + iVar21);
                    } while (uVar22 != 0);
                  }
                  param_8 = param_8 - 1;
                  puVar26 = (uint *)((int)puVar26 + iVar27);
                  iVar24 = iVar24 + local_b4;
                } while (param_8 != 0);
              }
              goto LAB_0002e240;
            }
            if (uVar3 < 0x8034) {
              if (uVar3 == 8) {
                if (0 < (int)param_8) {
                  do {
                    uVar22 = param_7;
                    puVar28 = puVar26;
                    if (0 < (int)param_7) {
                      do {
                        fVar9 = FLOAT_00108f6c;
                        fVar8 = FLOAT_00108e58;
                        fVar7 = FLOAT_00108e54;
                        iVar29 = param_6;
                        puVar31 = puVar28;
                        if (0 < param_6) {
                          do {
                            (*pcVar19)(auStack_1b0,iVar24);
                            _gleModifyPixelSignedRGBA(param_1,auStack_1b0);
                            if (fVar7 < local_1ac) {
                              uVar16 = 0x7f;
                            }
                            else {
                              uVar16 = 0x81;
                              if (fVar8 <= local_1ac) {
                                (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)(int)(local_1ac * fVar9);
                                uVar16 = (undefined1)local_c8;
                                local_c8 = (longlong)(int)(local_1ac * fVar9);
                              }
                            }
                            *(undefined1 *)puVar31 = uVar16;
                            if (fVar7 < local_1a8) {
                              uVar16 = 0x7f;
                            }
                            else {
                              uVar16 = 0x81;
                              if (fVar8 <= local_1a8) {
                                (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)(int)(local_1a8 * fVar9);
                                uVar16 = (undefined1)local_c8;
                                local_c8 = (longlong)(int)(local_1a8 * fVar9);
                              }
                            }
                            *(undefined1 *)((int)puVar31 + 1) = uVar16;
                            if (fVar7 < local_1a4) {
                              uVar16 = 0x7f;
                            }
                            else {
                              uVar16 = 0x81;
                              if (fVar8 <= local_1a4) {
                                (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)(int)(local_1a4 * fVar9);
                                uVar16 = (undefined1)local_c8;
                                local_c8 = (longlong)(int)(local_1a4 * fVar9);
                              }
                            }
                            *(undefined1 *)((int)puVar31 + 2) = uVar16;
                            if (fVar7 < local_1a0) {
                              uVar16 = 0x7f;
                            }
                            else {
                              uVar16 = 0x81;
                              if (fVar8 <= local_1a0) {
                                (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)(int)(local_1a0 * fVar9);
                                uVar16 = (undefined1)local_c8;
                                local_c8 = (longlong)(int)(local_1a0 * fVar9);
                              }
                            }
                            iVar29 = iVar29 + -1;
                            *(undefined1 *)((int)puVar31 + 3) = uVar16;
                            iVar24 = iVar24 + local_b0;
                            puVar31 = (uint *)((int)puVar31 + iVar17);
                          } while (iVar29 != 0);
                        }
                        uVar22 = uVar22 - 1;
                        iVar24 = iVar24 + local_bc;
                        puVar28 = (uint *)((int)puVar28 + iVar21);
                      } while (uVar22 != 0);
                    }
                    param_8 = param_8 - 1;
                    puVar26 = (uint *)((int)puVar26 + iVar27);
                    iVar24 = iVar24 + local_b4;
                  } while (param_8 != 0);
                }
                goto LAB_0002e240;
              }
            }
            else {
              if (uVar3 == 0x8034) {
                if (0 < (int)param_8) {
                  do {
                    uVar22 = param_7;
                    puVar28 = puVar26;
                    if (0 < (int)param_7) {
                      do {
                        if (0 < param_6) {
                          local_90 = fVar7;
                          puVar31 = puVar28;
                          iVar17 = param_6;
                          do {
                            (*pcVar19)(auStack_1b0,iVar24);
                            (*pcVar20)(param_1,auStack_1b0);
                            iVar17 = iVar17 + -1;
                            local_c8 = (longlong)(int)(local_1ac * fVar7);
                            local_d0 = (longlong)(int)(local_1a8 * fVar7);
                            local_d8 = (longlong)(int)(local_1a4 * fVar7);
                            local_e0 = (longlong)(int)(local_1a0 * fVar7);
                            *(ushort *)puVar31 =
                                 (ushort)(int)(local_1ac * fVar7) & 0xf800 |
                                 (ushort)((uint)(int)(local_1a8 * fVar7) >> 5) & 0x7c0 |
                                 (ushort)((uint)(int)(local_1a4 * fVar7) >> 10) & 0x3e |
                                 (ushort)((uint)(int)(local_1a0 * fVar7) >> 0xf) & 1;
                            puVar31 = (uint *)((int)puVar31 + 2);
                            iVar24 = iVar24 + local_b0;
                          } while (iVar17 != 0);
                        }
                        uVar22 = uVar22 - 1;
                        iVar24 = iVar24 + local_bc;
                        puVar28 = (uint *)((int)puVar28 + iVar21);
                      } while (uVar22 != 0);
                    }
                    param_8 = param_8 - 1;
                    puVar26 = (uint *)((int)puVar26 + iVar27);
                    iVar24 = iVar24 + local_b4;
                  } while (param_8 != 0);
                }
                goto LAB_0002e240;
              }
              if (uVar3 == 0x8035) {
                if (0 < (int)param_8) {
                  do {
                    uVar22 = param_7;
                    puVar28 = puVar26;
                    if (0 < (int)param_7) {
                      do {
                        dVar5 = DOUBLE_00108d80;
                        puVar31 = puVar28;
                        iVar17 = param_6;
                        if (0 < param_6) {
                          do {
                            (*pcVar19)(auStack_1b0,iVar24);
                            (*pcVar20)(param_1,auStack_1b0);
                            dVar32 = (double)local_1ac * dVar6;
                            if (dVar5 <= dVar32) {
                              uVar23 = (uint)(int)(dVar32 - dVar5);
                              local_d0 = (longlong)(int)uVar23;
                              uVar23 = uVar23 ^ 0x80000000;
                            }
                            else {
                              uVar23 = (uint)(int)dVar32;
                              local_c8 = (longlong)(int)uVar23;
                            }
                            dVar32 = (double)local_1a8 * dVar6;
                            if (DOUBLE_00108d80 <= dVar32) {
                              local_e0 = (longlong)(int)(dVar32 - DOUBLE_00108d80);
                              uVar18 = (int)(dVar32 - DOUBLE_00108d80) ^ 0x80000000;
                            }
                            else {
                              uVar18 = (uint)(int)dVar32;
                              local_d8 = (longlong)(int)uVar18;
                            }
                            dVar32 = (double)local_1a4 * dVar6;
                            if (DOUBLE_00108d80 <= dVar32) {
                              local_f0 = (longlong)(int)(dVar32 - DOUBLE_00108d80);
                              uVar12 = (int)(dVar32 - DOUBLE_00108d80) ^ 0x80000000;
                            }
                            else {
                              uVar12 = (uint)(int)dVar32;
                              local_e8 = (longlong)(int)uVar12;
                            }
                            dVar32 = (double)local_1a0 * dVar6;
                            if (DOUBLE_00108d80 <= dVar32) {
                              local_100 = (longlong)(int)(dVar32 - DOUBLE_00108d80);
                              uVar13 = (int)(dVar32 - DOUBLE_00108d80) ^ 0x80000000;
                            }
                            else {
                              uVar13 = (uint)(int)dVar32;
                              local_f8 = (longlong)(int)uVar13;
                            }
                            iVar17 = iVar17 + -1;
                            *puVar31 = uVar23 & 0xff000000 | uVar18 >> 8 & 0xff0000 |
                                       uVar12 >> 0x10 & 0xff00 | uVar13 >> 0x18;
                            iVar24 = iVar24 + local_b0;
                            puVar31 = puVar31 + 1;
                          } while (iVar17 != 0);
                        }
                        uVar22 = uVar22 - 1;
                        iVar24 = iVar24 + local_bc;
                        puVar28 = (uint *)((int)puVar28 + iVar21);
                      } while (uVar22 != 0);
                    }
                    param_8 = param_8 - 1;
                    puVar26 = (uint *)((int)puVar26 + iVar27);
                    iVar24 = iVar24 + local_b4;
                  } while (param_8 != 0);
                }
                goto LAB_0002e240;
              }
            }
          }
          else {
            if (uVar3 == 0x8366) {
              if (0 < (int)param_8) {
                do {
                  uVar22 = param_7;
                  puVar28 = puVar26;
                  if (0 < (int)param_7) {
                    do {
                      if (0 < param_6) {
                        local_90 = fVar7;
                        puVar31 = puVar28;
                        iVar17 = param_6;
                        do {
                          (*pcVar19)(auStack_1b0,iVar24);
                          (*pcVar20)(param_1,auStack_1b0);
                          iVar17 = iVar17 + -1;
                          local_c8 = (longlong)(int)(local_1a0 * fVar7);
                          local_d0 = (longlong)(int)(local_1a4 * fVar7);
                          local_d8 = (longlong)(int)(local_1a8 * fVar7);
                          local_e0 = (longlong)(int)(local_1ac * fVar7);
                          *(ushort *)puVar31 =
                               (ushort)(int)(local_1a0 * fVar7) & 0x8000 |
                               (ushort)((uint)(int)(local_1a4 * fVar7) >> 1) & 0x7c00 |
                               (ushort)((uint)(int)(local_1a8 * fVar7) >> 6) & 0x3e0 |
                               (ushort)((uint)(int)(local_1ac * fVar7) >> 0xb) & 0x1f;
                          puVar31 = (uint *)((int)puVar31 + 2);
                          iVar24 = iVar24 + local_b0;
                        } while (iVar17 != 0);
                      }
                      uVar22 = uVar22 - 1;
                      iVar24 = iVar24 + local_bc;
                      puVar28 = (uint *)((int)puVar28 + iVar21);
                    } while (uVar22 != 0);
                  }
                  param_8 = param_8 - 1;
                  puVar26 = (uint *)((int)puVar26 + iVar27);
                  iVar24 = iVar24 + local_b4;
                } while (param_8 != 0);
              }
              goto LAB_0002e240;
            }
            if (uVar3 < 0x8367) {
              if (uVar3 == 0x8365) {
                if (0 < (int)param_8) {
                  do {
                    uVar22 = param_7;
                    puVar28 = puVar26;
                    if (0 < (int)param_7) {
                      do {
                        if (0 < param_6) {
                          local_90 = fVar7;
                          puVar31 = puVar28;
                          iVar17 = param_6;
                          do {
                            (*pcVar19)(auStack_1b0,iVar24);
                            (*pcVar20)(param_1,auStack_1b0);
                            iVar17 = iVar17 + -1;
                            local_c8 = (longlong)(int)(local_1a0 * fVar7);
                            local_d0 = (longlong)(int)(local_1a4 * fVar7);
                            local_d8 = (longlong)(int)(local_1a8 * fVar7);
                            local_e0 = (longlong)(int)(local_1ac * fVar7);
                            *(ushort *)puVar31 =
                                 (ushort)(int)(local_1a0 * fVar7) & 0xf000 |
                                 (ushort)((uint)(int)(local_1a4 * fVar7) >> 4) & 0xf00 |
                                 (ushort)((uint)(int)(local_1a8 * fVar7) >> 8) & 0xf0 |
                                 (ushort)((uint)(int)(local_1ac * fVar7) >> 0xc) & 0xf;
                            puVar31 = (uint *)((int)puVar31 + 2);
                            iVar24 = iVar24 + local_b0;
                          } while (iVar17 != 0);
                        }
                        uVar22 = uVar22 - 1;
                        iVar24 = iVar24 + local_bc;
                        puVar28 = (uint *)((int)puVar28 + iVar21);
                      } while (uVar22 != 0);
                    }
                    param_8 = param_8 - 1;
                    puVar26 = (uint *)((int)puVar26 + iVar27);
                    iVar24 = iVar24 + local_b4;
                  } while (param_8 != 0);
                }
                goto LAB_0002e240;
              }
            }
            else {
              if (uVar3 == 0x8367) {
                if (0 < (int)param_8) {
                  do {
                    uVar22 = param_7;
                    puVar28 = puVar26;
                    if (0 < (int)param_7) {
                      do {
                        dVar5 = DOUBLE_00108d80;
                        puVar31 = puVar28;
                        iVar17 = param_6;
                        if (0 < param_6) {
                          do {
                            (*pcVar19)(auStack_1b0,iVar24);
                            (*pcVar20)(param_1,auStack_1b0);
                            dVar32 = (double)local_1a0 * dVar6;
                            if (dVar5 <= dVar32) {
                              uVar23 = (uint)(int)(dVar32 - dVar5);
                              local_d0 = (longlong)(int)uVar23;
                              uVar23 = uVar23 ^ 0x80000000;
                            }
                            else {
                              uVar23 = (uint)(int)dVar32;
                              local_c8 = (longlong)(int)uVar23;
                            }
                            dVar32 = (double)local_1a4 * dVar6;
                            if (DOUBLE_00108d80 <= dVar32) {
                              local_e0 = (longlong)(int)(dVar32 - DOUBLE_00108d80);
                              uVar18 = (int)(dVar32 - DOUBLE_00108d80) ^ 0x80000000;
                            }
                            else {
                              uVar18 = (uint)(int)dVar32;
                              local_d8 = (longlong)(int)uVar18;
                            }
                            dVar32 = (double)local_1a8 * dVar6;
                            if (DOUBLE_00108d80 <= dVar32) {
                              local_f0 = (longlong)(int)(dVar32 - DOUBLE_00108d80);
                              uVar12 = (int)(dVar32 - DOUBLE_00108d80) ^ 0x80000000;
                            }
                            else {
                              uVar12 = (uint)(int)dVar32;
                              local_e8 = (longlong)(int)uVar12;
                            }
                            dVar32 = (double)local_1ac * dVar6;
                            if (DOUBLE_00108d80 <= dVar32) {
                              local_100 = (longlong)(int)(dVar32 - DOUBLE_00108d80);
                              uVar13 = (int)(dVar32 - DOUBLE_00108d80) ^ 0x80000000;
                            }
                            else {
                              uVar13 = (uint)(int)dVar32;
                              local_f8 = (longlong)(int)uVar13;
                            }
                            iVar17 = iVar17 + -1;
                            *puVar31 = uVar23 & 0xff000000 | uVar18 >> 8 & 0xff0000 |
                                       uVar12 >> 0x10 & 0xff00 | uVar13 >> 0x18;
                            iVar24 = iVar24 + local_b0;
                            puVar31 = puVar31 + 1;
                          } while (iVar17 != 0);
                        }
                        uVar22 = uVar22 - 1;
                        iVar24 = iVar24 + local_bc;
                        puVar28 = (uint *)((int)puVar28 + iVar21);
                      } while (uVar22 != 0);
                    }
                    param_8 = param_8 - 1;
                    puVar26 = (uint *)((int)puVar26 + iVar27);
                    iVar24 = iVar24 + local_b4;
                  } while (param_8 != 0);
                }
                goto LAB_0002e240;
              }
              if (uVar3 == 0x8368) {
                if (0 < (int)param_8) {
                  do {
                    uVar22 = param_7;
                    puVar28 = puVar26;
                    if (0 < (int)param_7) {
                      do {
                        dVar5 = DOUBLE_00108d80;
                        puVar31 = puVar28;
                        iVar17 = param_6;
                        if (0 < param_6) {
                          do {
                            (*pcVar19)(auStack_1b0,iVar24);
                            (*pcVar20)(param_1,auStack_1b0);
                            dVar32 = (double)local_1a0 * dVar6;
                            if (dVar5 <= dVar32) {
                              uVar23 = (uint)(int)(dVar32 - dVar5);
                              local_d0 = (longlong)(int)uVar23;
                              uVar23 = uVar23 ^ 0x80000000;
                            }
                            else {
                              uVar23 = (uint)(int)dVar32;
                              local_c8 = (longlong)(int)uVar23;
                            }
                            dVar32 = (double)local_1a4 * dVar6;
                            if (DOUBLE_00108d80 <= dVar32) {
                              local_e0 = (longlong)(int)(dVar32 - DOUBLE_00108d80);
                              uVar18 = (int)(dVar32 - DOUBLE_00108d80) ^ 0x80000000;
                            }
                            else {
                              uVar18 = (uint)(int)dVar32;
                              local_d8 = (longlong)(int)uVar18;
                            }
                            dVar32 = (double)local_1a8 * dVar6;
                            if (DOUBLE_00108d80 <= dVar32) {
                              local_f0 = (longlong)(int)(dVar32 - DOUBLE_00108d80);
                              uVar12 = (int)(dVar32 - DOUBLE_00108d80) ^ 0x80000000;
                            }
                            else {
                              uVar12 = (uint)(int)dVar32;
                              local_e8 = (longlong)(int)uVar12;
                            }
                            dVar32 = (double)local_1ac * dVar6;
                            if (DOUBLE_00108d80 <= dVar32) {
                              local_100 = (longlong)(int)(dVar32 - DOUBLE_00108d80);
                              uVar13 = (int)(dVar32 - DOUBLE_00108d80) ^ 0x80000000;
                            }
                            else {
                              uVar13 = (uint)(int)dVar32;
                              local_f8 = (longlong)(int)uVar13;
                            }
                            iVar17 = iVar17 + -1;
                            *puVar31 = uVar23 & 0xc0000000 | uVar18 >> 2 & 0x3ff00000 |
                                       uVar12 >> 0xc & 0xffc00 | uVar13 >> 0x16;
                            iVar24 = iVar24 + local_b0;
                            puVar31 = puVar31 + 1;
                          } while (iVar17 != 0);
                        }
                        uVar22 = uVar22 - 1;
                        iVar24 = iVar24 + local_bc;
                        puVar28 = (uint *)((int)puVar28 + iVar21);
                      } while (uVar22 != 0);
                    }
                    param_8 = param_8 - 1;
                    puVar26 = (uint *)((int)puVar26 + iVar27);
                    iVar24 = iVar24 + local_b4;
                  } while (param_8 != 0);
                }
                goto LAB_0002e240;
              }
            }
          }
          if (0 < (int)param_8) {
            do {
              uVar22 = param_7;
              puVar28 = puVar26;
              if (0 < (int)param_7) {
                do {
                  fVar9 = FLOAT_00108f70;
                  fVar8 = FLOAT_00108e54;
                  fVar7 = FLOAT_00108e50;
                  iVar29 = param_6;
                  puVar31 = puVar28;
                  if (0 < param_6) {
                    do {
                      local_1ac = fVar7;
                      local_1a8 = fVar7;
                      local_1a4 = fVar7;
                      local_1a0 = fVar8;
                      (*pcVar19)(auStack_1b0,iVar24);
                      (*pcVar20)(param_1,auStack_1b0);
                      if (fVar8 < local_1ac) {
                        uVar16 = 0xff;
                      }
                      else {
                        uVar16 = 0;
                        if (fVar7 <= local_1ac) {
                          (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)(int)(local_1ac * fVar9);
                          uVar16 = (undefined1)local_c8;
                          local_c8 = (longlong)(int)(local_1ac * fVar9);
                        }
                      }
                      *(undefined1 *)puVar31 = uVar16;
                      if (fVar8 < local_1a8) {
                        uVar16 = 0xff;
                      }
                      else {
                        uVar16 = 0;
                        if (fVar7 <= local_1a8) {
                          (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)(int)(local_1a8 * fVar9);
                          uVar16 = (undefined1)local_c8;
                          local_c8 = (longlong)(int)(local_1a8 * fVar9);
                        }
                      }
                      *(undefined1 *)((int)puVar31 + 1) = uVar16;
                      if (fVar8 < local_1a4) {
                        uVar16 = 0xff;
                      }
                      else {
                        uVar16 = 0;
                        if (fVar7 <= local_1a4) {
                          (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)(int)(local_1a4 * fVar9);
                          uVar16 = (undefined1)local_c8;
                          local_c8 = (longlong)(int)(local_1a4 * fVar9);
                        }
                      }
                      *(undefined1 *)((int)puVar31 + 2) = uVar16;
                      if (fVar8 < local_1a0) {
                        uVar16 = 0xff;
                      }
                      else {
                        uVar16 = 0;
                        if (fVar7 <= local_1a0) {
                          (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)(int)(local_1a0 * fVar9);
                          uVar16 = (undefined1)local_c8;
                          local_c8 = (longlong)(int)(local_1a0 * fVar9);
                        }
                      }
                      iVar29 = iVar29 + -1;
                      *(undefined1 *)((int)puVar31 + 3) = uVar16;
                      iVar24 = iVar24 + local_b0;
                      puVar31 = (uint *)((int)puVar31 + iVar17);
                    } while (iVar29 != 0);
                  }
                  uVar22 = uVar22 - 1;
                  iVar24 = iVar24 + local_bc;
                  puVar28 = (uint *)((int)puVar28 + iVar21);
                } while (uVar22 != 0);
              }
              param_8 = param_8 - 1;
              puVar26 = (uint *)((int)puVar26 + iVar27);
              iVar24 = iVar24 + local_b4;
            } while (param_8 != 0);
          }
          goto LAB_0002e240;
        }
        if (uVar3 == 0x1909) {
          if (*(short *)(param_2 + 0x12) == 0x1400) {
            if (0 < (int)param_8) {
              do {
                uVar22 = param_7;
                puVar28 = puVar26;
                if (0 < (int)param_7) {
                  do {
                    fVar9 = FLOAT_00108f6c;
                    fVar8 = FLOAT_00108e58;
                    fVar7 = FLOAT_00108e54;
                    iVar29 = param_6;
                    puVar31 = puVar28;
                    if (0 < param_6) {
                      do {
                        (*pcVar19)(auStack_1b0,iVar24);
                        _gleModifyPixelSignedRGBA(param_1,auStack_1b0);
                        if (fVar7 < local_1ac) {
                          uVar16 = 0x7f;
                        }
                        else {
                          uVar16 = 0x81;
                          if (fVar8 <= local_1ac) {
                            (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)(int)(local_1ac * fVar9);
                            uVar16 = (undefined1)local_c8;
                            local_c8 = (longlong)(int)(local_1ac * fVar9);
                          }
                        }
                        iVar29 = iVar29 + -1;
                        *(undefined1 *)puVar31 = uVar16;
                        iVar24 = iVar24 + local_b0;
                        puVar31 = (uint *)((int)puVar31 + iVar17);
                      } while (iVar29 != 0);
                    }
                    uVar22 = uVar22 - 1;
                    iVar24 = iVar24 + local_bc;
                    puVar28 = (uint *)((int)puVar28 + iVar21);
                  } while (uVar22 != 0);
                }
                param_8 = param_8 - 1;
                puVar26 = (uint *)((int)puVar26 + iVar27);
                iVar24 = iVar24 + local_b4;
              } while (param_8 != 0);
            }
          }
          else if (0 < (int)param_8) {
            do {
              uVar22 = param_7;
              puVar28 = puVar26;
              if (0 < (int)param_7) {
                do {
                  fVar9 = FLOAT_00108f70;
                  fVar8 = FLOAT_00108e54;
                  fVar7 = FLOAT_00108e50;
                  iVar29 = param_6;
                  puVar31 = puVar28;
                  if (0 < param_6) {
                    do {
                      local_1ac = fVar7;
                      (*pcVar19)(auStack_1b0,iVar24);
                      (*pcVar20)(param_1,auStack_1b0);
                      if (fVar8 < local_1ac) {
                        uVar16 = 0xff;
                      }
                      else {
                        uVar16 = 0;
                        if (fVar7 <= local_1ac) {
                          (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)(int)(local_1ac * fVar9);
                          uVar16 = (undefined1)local_c8;
                          local_c8 = (longlong)(int)(local_1ac * fVar9);
                        }
                      }
                      iVar29 = iVar29 + -1;
                      *(undefined1 *)puVar31 = uVar16;
                      iVar24 = iVar24 + local_b0;
                      puVar31 = (uint *)((int)puVar31 + iVar17);
                    } while (iVar29 != 0);
                  }
                  uVar22 = uVar22 - 1;
                  iVar24 = iVar24 + local_bc;
                  puVar28 = (uint *)((int)puVar28 + iVar21);
                } while (uVar22 != 0);
              }
              param_8 = param_8 - 1;
              puVar26 = (uint *)((int)puVar26 + iVar27);
              iVar24 = iVar24 + local_b4;
            } while (param_8 != 0);
          }
          goto LAB_0002e240;
        }
      }
    }
    else {
      if (uVar3 == 0x86f4) {
        uVar3 = *(ushort *)(param_2 + 0x12);
        if (uVar3 == 6) {
          if (0 < (int)param_8) {
            local_9c = iVar17 << 1;
            do {
              iVar17 = local_9c;
              if (0 < (int)param_7) {
                local_a4 = FLOAT_00108f74;
                uVar22 = param_7;
                puVar28 = puVar26;
                do {
                  fVar9 = local_a4;
                  fVar8 = FLOAT_00108e58;
                  fVar7 = FLOAT_00108e54;
                  iVar29 = param_6;
                  puVar31 = puVar28;
                  if (0 < param_6) {
                    do {
                      (*pcVar19)(auStack_1b0,iVar24);
                      (*pcVar20)(param_1,auStack_1b0);
                      if (fVar7 < local_190) {
                        uVar15 = 0x7fff;
                      }
                      else {
                        uVar15 = 0x8001;
                        if (fVar8 <= local_190) {
                          iVar1 = (int)(local_190 * fVar9);
                          (*(unsigned short *)((unsigned char *)&(local_c8) + 6)) = (undefined2)iVar1;
                          uVar15 = (*(unsigned short *)((unsigned char *)&(local_c8) + 6));
                          local_c8 = (longlong)iVar1;
                        }
                      }
                      *(undefined2 *)puVar31 = uVar15;
                      if (fVar7 < local_18c) {
                        uVar15 = 0x7fff;
                      }
                      else {
                        uVar15 = 0x8001;
                        if (fVar8 <= local_18c) {
                          iVar1 = (int)(local_18c * fVar9);
                          (*(unsigned short *)((unsigned char *)&(local_c8) + 6)) = (undefined2)iVar1;
                          uVar15 = (*(unsigned short *)((unsigned char *)&(local_c8) + 6));
                          local_c8 = (longlong)iVar1;
                        }
                      }
                      iVar29 = iVar29 + -1;
                      *(undefined2 *)((int)puVar31 + 2) = uVar15;
                      iVar24 = iVar24 + local_b0;
                      puVar31 = (uint *)((int)puVar31 + iVar17);
                    } while (iVar29 != 0);
                  }
                  uVar22 = uVar22 - 1;
                  puVar28 = (uint *)((int)puVar28 + iVar21);
                  iVar24 = iVar24 + local_bc;
                } while (uVar22 != 0);
              }
              param_8 = param_8 - 1;
              puVar26 = (uint *)((int)puVar26 + iVar27);
              iVar24 = iVar24 + local_b4;
            } while (param_8 != 0);
          }
        }
        else if (uVar3 < 7) {
          if ((uVar3 == 5) && (0 < (int)param_8)) {
            local_a0 = iVar17 << 1;
            do {
              iVar17 = local_a0;
              if (0 < (int)param_7) {
                local_a8 = FLOAT_00108ea0;
                uVar22 = param_7;
                puVar28 = puVar26;
                do {
                  fVar9 = local_a8;
                  fVar8 = FLOAT_00108e54;
                  fVar7 = FLOAT_00108e50;
                  iVar29 = param_6;
                  puVar31 = puVar28;
                  if (0 < param_6) {
                    do {
                      (*pcVar19)(auStack_1b0,iVar24);
                      (*pcVar20)(param_1,auStack_1b0);
                      if (fVar8 < local_190) {
                        uVar15 = 0xffff;
                      }
                      else {
                        uVar15 = 0;
                        if (fVar7 <= local_190) {
                          iVar1 = (int)(local_190 * fVar9);
                          (*(unsigned short *)((unsigned char *)&(local_c8) + 6)) = (undefined2)iVar1;
                          uVar15 = (*(unsigned short *)((unsigned char *)&(local_c8) + 6));
                          local_c8 = (longlong)iVar1;
                        }
                      }
                      *(undefined2 *)puVar31 = uVar15;
                      if (fVar8 < local_18c) {
                        uVar15 = 0xffff;
                      }
                      else {
                        uVar15 = 0;
                        if (fVar7 <= local_18c) {
                          iVar1 = (int)(local_18c * fVar9);
                          (*(unsigned short *)((unsigned char *)&(local_c8) + 6)) = (undefined2)iVar1;
                          uVar15 = (*(unsigned short *)((unsigned char *)&(local_c8) + 6));
                          local_c8 = (longlong)iVar1;
                        }
                      }
                      iVar29 = iVar29 + -1;
                      *(undefined2 *)((int)puVar31 + 2) = uVar15;
                      iVar24 = iVar24 + local_b0;
                      puVar31 = (uint *)((int)puVar31 + iVar17);
                    } while (iVar29 != 0);
                  }
                  uVar22 = uVar22 - 1;
                  puVar28 = (uint *)((int)puVar28 + iVar21);
                  iVar24 = iVar24 + local_bc;
                } while (uVar22 != 0);
              }
              param_8 = param_8 - 1;
              puVar26 = (uint *)((int)puVar26 + iVar27);
              iVar24 = iVar24 + local_b4;
            } while (param_8 != 0);
          }
        }
        else if (uVar3 == 0x1400) {
          if (0 < (int)param_8) {
            do {
              uVar22 = param_7;
              puVar28 = puVar26;
              if (0 < (int)param_7) {
                do {
                  fVar9 = FLOAT_00108f6c;
                  fVar8 = FLOAT_00108e58;
                  fVar7 = FLOAT_00108e54;
                  iVar29 = param_6;
                  puVar31 = puVar28;
                  if (0 < param_6) {
                    do {
                      (*pcVar19)(auStack_1b0,iVar24);
                      (*pcVar20)(param_1,auStack_1b0);
                      if (fVar7 < local_190) {
                        uVar16 = 0x7f;
                      }
                      else {
                        uVar16 = 0x81;
                        if (fVar8 <= local_190) {
                          iVar1 = (int)(local_190 * fVar9);
                          (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)iVar1;
                          uVar16 = (undefined1)local_c8;
                          local_c8 = (longlong)iVar1;
                        }
                      }
                      *(undefined1 *)puVar31 = uVar16;
                      if (fVar7 < local_18c) {
                        uVar16 = 0x7f;
                      }
                      else {
                        uVar16 = 0x81;
                        if (fVar8 <= local_18c) {
                          iVar1 = (int)(local_18c * fVar9);
                          (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)iVar1;
                          uVar16 = (undefined1)local_c8;
                          local_c8 = (longlong)iVar1;
                        }
                      }
                      iVar29 = iVar29 + -1;
                      *(undefined1 *)((int)puVar31 + 1) = uVar16;
                      iVar24 = iVar24 + local_b0;
                      puVar31 = (uint *)((int)puVar31 + iVar17);
                    } while (iVar29 != 0);
                  }
                  uVar22 = uVar22 - 1;
                  iVar24 = iVar24 + local_bc;
                  puVar28 = (uint *)((int)puVar28 + iVar21);
                } while (uVar22 != 0);
              }
              param_8 = param_8 - 1;
              puVar26 = (uint *)((int)puVar26 + iVar27);
              iVar24 = iVar24 + local_b4;
            } while (param_8 != 0);
          }
        }
        else if ((uVar3 == 0x1401) && (0 < (int)param_8)) {
          do {
            uVar22 = param_7;
            puVar28 = puVar26;
            if (0 < (int)param_7) {
              do {
                fVar9 = FLOAT_00108f70;
                fVar8 = FLOAT_00108e54;
                fVar7 = FLOAT_00108e50;
                iVar29 = param_6;
                puVar31 = puVar28;
                if (0 < param_6) {
                  do {
                    (*pcVar19)(auStack_1b0,iVar24);
                    (*pcVar20)(param_1,auStack_1b0);
                    if (fVar8 < local_190) {
                      uVar16 = 0xff;
                    }
                    else {
                      uVar16 = 0;
                      if (fVar7 <= local_190) {
                        iVar1 = (int)(local_190 * fVar9);
                        (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)iVar1;
                        uVar16 = (undefined1)local_c8;
                        local_c8 = (longlong)iVar1;
                      }
                    }
                    *(undefined1 *)puVar31 = uVar16;
                    if (fVar8 < local_18c) {
                      uVar16 = 0xff;
                    }
                    else {
                      uVar16 = 0;
                      if (fVar7 <= local_18c) {
                        iVar1 = (int)(local_18c * fVar9);
                        (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)iVar1;
                        uVar16 = (undefined1)local_c8;
                        local_c8 = (longlong)iVar1;
                      }
                    }
                    iVar29 = iVar29 + -1;
                    *(undefined1 *)((int)puVar31 + 1) = uVar16;
                    iVar24 = iVar24 + local_b0;
                    puVar31 = (uint *)((int)puVar31 + iVar17);
                  } while (iVar29 != 0);
                }
                uVar22 = uVar22 - 1;
                iVar24 = iVar24 + local_bc;
                puVar28 = (uint *)((int)puVar28 + iVar21);
              } while (uVar22 != 0);
            }
            param_8 = param_8 - 1;
            puVar26 = (uint *)((int)puVar26 + iVar27);
            iVar24 = iVar24 + local_b4;
          } while (param_8 != 0);
        }
        goto LAB_0002e240;
      }
      if (uVar3 < 0x86f5) {
        if (uVar3 == 0x80e1) {
          uVar3 = *(ushort *)(param_2 + 0x12);
          if (uVar3 == 0x8036) {
            if (0 < (int)param_8) {
              do {
                uVar22 = param_7;
                puVar28 = puVar26;
                if (0 < (int)param_7) {
                  do {
                    dVar5 = DOUBLE_00108d80;
                    puVar31 = puVar28;
                    iVar17 = param_6;
                    if (0 < param_6) {
                      do {
                        (*pcVar19)(auStack_1b0,iVar24);
                        (*pcVar20)(param_1,auStack_1b0);
                        dVar32 = (double)local_1a4 * dVar6;
                        if (dVar5 <= dVar32) {
                          uVar23 = (uint)(int)(dVar32 - dVar5);
                          local_d0 = (longlong)(int)uVar23;
                          uVar23 = uVar23 ^ 0x80000000;
                        }
                        else {
                          uVar23 = (uint)(int)dVar32;
                          local_c8 = (longlong)(int)uVar23;
                        }
                        dVar32 = (double)local_1a8 * dVar6;
                        if (DOUBLE_00108d80 <= dVar32) {
                          local_e0 = (longlong)(int)(dVar32 - DOUBLE_00108d80);
                          uVar18 = (int)(dVar32 - DOUBLE_00108d80) ^ 0x80000000;
                        }
                        else {
                          uVar18 = (uint)(int)dVar32;
                          local_d8 = (longlong)(int)uVar18;
                        }
                        dVar32 = (double)local_1ac * dVar6;
                        if (DOUBLE_00108d80 <= dVar32) {
                          local_f0 = (longlong)(int)(dVar32 - DOUBLE_00108d80);
                          uVar12 = (int)(dVar32 - DOUBLE_00108d80) ^ 0x80000000;
                        }
                        else {
                          uVar12 = (uint)(int)dVar32;
                          local_e8 = (longlong)(int)uVar12;
                        }
                        dVar32 = (double)local_1a0 * dVar6;
                        if (DOUBLE_00108d80 <= dVar32) {
                          local_100 = (longlong)(int)(dVar32 - DOUBLE_00108d80);
                          uVar13 = (int)(dVar32 - DOUBLE_00108d80) ^ 0x80000000;
                        }
                        else {
                          uVar13 = (uint)(int)dVar32;
                          local_f8 = (longlong)(int)uVar13;
                        }
                        iVar17 = iVar17 + -1;
                        *puVar31 = uVar23 & 0xffc00000 | uVar18 >> 10 & 0x3ff000 |
                                   uVar12 >> 0x14 & 0xffc | uVar13 >> 0x1e;
                        iVar24 = iVar24 + local_b0;
                        puVar31 = puVar31 + 1;
                      } while (iVar17 != 0);
                    }
                    uVar22 = uVar22 - 1;
                    iVar24 = iVar24 + local_bc;
                    puVar28 = (uint *)((int)puVar28 + iVar21);
                  } while (uVar22 != 0);
                }
                param_8 = param_8 - 1;
                puVar26 = (uint *)((int)puVar26 + iVar27);
                iVar24 = iVar24 + local_b4;
              } while (param_8 != 0);
            }
            goto LAB_0002e240;
          }
          if (uVar3 < 0x8037) {
            if (uVar3 == 0x8033) {
              if (0 < (int)param_8) {
                do {
                  uVar22 = param_7;
                  puVar28 = puVar26;
                  if (0 < (int)param_7) {
                    do {
                      if (0 < param_6) {
                        local_90 = fVar7;
                        puVar31 = puVar28;
                        iVar17 = param_6;
                        do {
                          (*pcVar19)(auStack_1b0,iVar24);
                          (*pcVar20)(param_1,auStack_1b0);
                          iVar17 = iVar17 + -1;
                          local_c8 = (longlong)(int)(local_1a4 * fVar7);
                          local_d0 = (longlong)(int)(local_1a8 * fVar7);
                          local_d8 = (longlong)(int)(local_1ac * fVar7);
                          local_e0 = (longlong)(int)(local_1a0 * fVar7);
                          *(ushort *)puVar31 =
                               (ushort)(int)(local_1a4 * fVar7) & 0xf000 |
                               (ushort)((uint)(int)(local_1a8 * fVar7) >> 4) & 0xf00 |
                               (ushort)((uint)(int)(local_1ac * fVar7) >> 8) & 0xf0 |
                               (ushort)((uint)(int)(local_1a0 * fVar7) >> 0xc) & 0xf;
                          puVar31 = (uint *)((int)puVar31 + 2);
                          iVar24 = iVar24 + local_b0;
                        } while (iVar17 != 0);
                      }
                      uVar22 = uVar22 - 1;
                      iVar24 = iVar24 + local_bc;
                      puVar28 = (uint *)((int)puVar28 + iVar21);
                    } while (uVar22 != 0);
                  }
                  param_8 = param_8 - 1;
                  puVar26 = (uint *)((int)puVar26 + iVar27);
                  iVar24 = iVar24 + local_b4;
                } while (param_8 != 0);
              }
              goto LAB_0002e240;
            }
            if (uVar3 < 0x8034) {
              if (uVar3 == 7) {
                if (0 < (int)param_8) {
                  do {
                    uVar22 = param_7;
                    puVar28 = puVar26;
                    if (0 < (int)param_7) {
                      do {
                        fVar11 = FLOAT_00108f70;
                        fVar10 = FLOAT_00108f6c;
                        fVar9 = FLOAT_00108e58;
                        fVar8 = FLOAT_00108e54;
                        fVar7 = FLOAT_00108e50;
                        if (0 < param_6) {
                          puVar30 = (undefined1 *)((int)puVar28 + 3);
                          puVar31 = puVar28;
                          iVar29 = param_6;
                          do {
                            (*pcVar19)(auStack_1b0,iVar24);
                            _gleModifyPixelSignedRGB_UnsignedA(param_1,auStack_1b0);
                            if (fVar8 < local_1a0) {
                              uVar16 = 0xff;
                            }
                            else {
                              uVar16 = 0;
                              if (fVar7 <= local_1a0) {
                                (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)(int)(local_1a0 * fVar11);
                                uVar16 = (undefined1)local_c8;
                                local_c8 = (longlong)(int)(local_1a0 * fVar11);
                              }
                            }
                            *(undefined1 *)puVar31 = uVar16;
                            if (fVar8 < local_1ac) {
                              uVar16 = 0x7f;
                            }
                            else {
                              uVar16 = 0x81;
                              if (fVar9 <= local_1ac) {
                                (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)(int)(local_1ac * fVar10);
                                uVar16 = (undefined1)local_c8;
                                local_c8 = (longlong)(int)(local_1ac * fVar10);
                              }
                            }
                            puVar30[-2] = uVar16;
                            if (fVar8 < local_1a8) {
                              uVar16 = 0x7f;
                            }
                            else {
                              uVar16 = 0x81;
                              if (fVar9 <= local_1a8) {
                                (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)(int)(local_1a8 * fVar10);
                                uVar16 = (undefined1)local_c8;
                                local_c8 = (longlong)(int)(local_1a8 * fVar10);
                              }
                            }
                            puVar30[-1] = uVar16;
                            if (fVar8 < local_1a4) {
                              uVar16 = 0x7f;
                            }
                            else {
                              uVar16 = 0x81;
                              if (fVar9 <= local_1a4) {
                                (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)(int)(local_1a4 * fVar10);
                                uVar16 = (undefined1)local_c8;
                                local_c8 = (longlong)(int)(local_1a4 * fVar10);
                              }
                            }
                            iVar29 = iVar29 + -1;
                            *puVar30 = uVar16;
                            puVar30 = puVar30 + iVar17;
                            puVar31 = (uint *)((int)puVar31 + iVar17);
                            iVar24 = iVar24 + local_b0;
                          } while (iVar29 != 0);
                        }
                        uVar22 = uVar22 - 1;
                        iVar24 = iVar24 + local_bc;
                        puVar28 = (uint *)((int)puVar28 + iVar21);
                      } while (uVar22 != 0);
                    }
                    param_8 = param_8 - 1;
                    puVar26 = (uint *)((int)puVar26 + iVar27);
                    iVar24 = iVar24 + local_b4;
                  } while (param_8 != 0);
                }
                goto LAB_0002e240;
              }
            }
            else {
              if (uVar3 == 0x8034) {
                if (0 < (int)param_8) {
                  do {
                    uVar22 = param_7;
                    puVar28 = puVar26;
                    if (0 < (int)param_7) {
                      do {
                        if (0 < param_6) {
                          local_90 = fVar7;
                          puVar31 = puVar28;
                          iVar17 = param_6;
                          do {
                            (*pcVar19)(auStack_1b0,iVar24);
                            (*pcVar20)(param_1,auStack_1b0);
                            iVar17 = iVar17 + -1;
                            local_c8 = (longlong)(int)(local_1a4 * fVar7);
                            local_d0 = (longlong)(int)(local_1a8 * fVar7);
                            local_d8 = (longlong)(int)(local_1ac * fVar7);
                            local_e0 = (longlong)(int)(local_1a0 * fVar7);
                            *(ushort *)puVar31 =
                                 (ushort)(int)(local_1a4 * fVar7) & 0xf800 |
                                 (ushort)((uint)(int)(local_1a8 * fVar7) >> 5) & 0x7c0 |
                                 (ushort)((uint)(int)(local_1ac * fVar7) >> 10) & 0x3e |
                                 (ushort)((uint)(int)(local_1a0 * fVar7) >> 0xf) & 1;
                            puVar31 = (uint *)((int)puVar31 + 2);
                            iVar24 = iVar24 + local_b0;
                          } while (iVar17 != 0);
                        }
                        uVar22 = uVar22 - 1;
                        iVar24 = iVar24 + local_bc;
                        puVar28 = (uint *)((int)puVar28 + iVar21);
                      } while (uVar22 != 0);
                    }
                    param_8 = param_8 - 1;
                    puVar26 = (uint *)((int)puVar26 + iVar27);
                    iVar24 = iVar24 + local_b4;
                  } while (param_8 != 0);
                }
                goto LAB_0002e240;
              }
              if (uVar3 == 0x8035) {
                if (0 < (int)param_8) {
                  do {
                    uVar22 = param_7;
                    puVar28 = puVar26;
                    if (0 < (int)param_7) {
                      do {
                        dVar5 = DOUBLE_00108d80;
                        puVar31 = puVar28;
                        iVar17 = param_6;
                        if (0 < param_6) {
                          do {
                            (*pcVar19)(auStack_1b0,iVar24);
                            (*pcVar20)(param_1,auStack_1b0);
                            dVar32 = (double)local_1a4 * dVar6;
                            if (dVar5 <= dVar32) {
                              uVar23 = (uint)(int)(dVar32 - dVar5);
                              local_d0 = (longlong)(int)uVar23;
                              uVar23 = uVar23 ^ 0x80000000;
                            }
                            else {
                              uVar23 = (uint)(int)dVar32;
                              local_c8 = (longlong)(int)uVar23;
                            }
                            dVar32 = (double)local_1a8 * dVar6;
                            if (DOUBLE_00108d80 <= dVar32) {
                              local_e0 = (longlong)(int)(dVar32 - DOUBLE_00108d80);
                              uVar18 = (int)(dVar32 - DOUBLE_00108d80) ^ 0x80000000;
                            }
                            else {
                              uVar18 = (uint)(int)dVar32;
                              local_d8 = (longlong)(int)uVar18;
                            }
                            dVar32 = (double)local_1ac * dVar6;
                            if (DOUBLE_00108d80 <= dVar32) {
                              local_f0 = (longlong)(int)(dVar32 - DOUBLE_00108d80);
                              uVar12 = (int)(dVar32 - DOUBLE_00108d80) ^ 0x80000000;
                            }
                            else {
                              uVar12 = (uint)(int)dVar32;
                              local_e8 = (longlong)(int)uVar12;
                            }
                            dVar32 = (double)local_1a0 * dVar6;
                            if (DOUBLE_00108d80 <= dVar32) {
                              local_100 = (longlong)(int)(dVar32 - DOUBLE_00108d80);
                              uVar13 = (int)(dVar32 - DOUBLE_00108d80) ^ 0x80000000;
                            }
                            else {
                              uVar13 = (uint)(int)dVar32;
                              local_f8 = (longlong)(int)uVar13;
                            }
                            iVar17 = iVar17 + -1;
                            *puVar31 = uVar23 & 0xff000000 | uVar18 >> 8 & 0xff0000 |
                                       uVar12 >> 0x10 & 0xff00 | uVar13 >> 0x18;
                            iVar24 = iVar24 + local_b0;
                            puVar31 = puVar31 + 1;
                          } while (iVar17 != 0);
                        }
                        uVar22 = uVar22 - 1;
                        iVar24 = iVar24 + local_bc;
                        puVar28 = (uint *)((int)puVar28 + iVar21);
                      } while (uVar22 != 0);
                    }
                    param_8 = param_8 - 1;
                    puVar26 = (uint *)((int)puVar26 + iVar27);
                    iVar24 = iVar24 + local_b4;
                  } while (param_8 != 0);
                }
                goto LAB_0002e240;
              }
            }
          }
          else {
            if (uVar3 == 0x8366) {
              if (0 < (int)param_8) {
                do {
                  uVar22 = param_7;
                  puVar28 = puVar26;
                  if (0 < (int)param_7) {
                    do {
                      if (0 < param_6) {
                        local_90 = fVar7;
                        puVar31 = puVar28;
                        iVar17 = param_6;
                        do {
                          (*pcVar19)(auStack_1b0,iVar24);
                          (*pcVar20)(param_1,auStack_1b0);
                          iVar17 = iVar17 + -1;
                          local_c8 = (longlong)(int)(local_1a0 * fVar7);
                          local_d0 = (longlong)(int)(local_1ac * fVar7);
                          local_d8 = (longlong)(int)(local_1a8 * fVar7);
                          local_e0 = (longlong)(int)(local_1a4 * fVar7);
                          *(ushort *)puVar31 =
                               (ushort)(int)(local_1a0 * fVar7) & 0x8000 |
                               (ushort)((uint)(int)(local_1ac * fVar7) >> 1) & 0x7c00 |
                               (ushort)((uint)(int)(local_1a8 * fVar7) >> 6) & 0x3e0 |
                               (ushort)((uint)(int)(local_1a4 * fVar7) >> 0xb) & 0x1f;
                          puVar31 = (uint *)((int)puVar31 + 2);
                          iVar24 = iVar24 + local_b0;
                        } while (iVar17 != 0);
                      }
                      uVar22 = uVar22 - 1;
                      iVar24 = iVar24 + local_bc;
                      puVar28 = (uint *)((int)puVar28 + iVar21);
                    } while (uVar22 != 0);
                  }
                  param_8 = param_8 - 1;
                  puVar26 = (uint *)((int)puVar26 + iVar27);
                  iVar24 = iVar24 + local_b4;
                } while (param_8 != 0);
              }
              goto LAB_0002e240;
            }
            if (uVar3 < 0x8367) {
              if (uVar3 == 0x8365) {
                if (0 < (int)param_8) {
                  do {
                    uVar22 = param_7;
                    puVar28 = puVar26;
                    if (0 < (int)param_7) {
                      do {
                        if (0 < param_6) {
                          local_90 = fVar7;
                          puVar31 = puVar28;
                          iVar17 = param_6;
                          do {
                            (*pcVar19)(auStack_1b0,iVar24);
                            (*pcVar20)(param_1,auStack_1b0);
                            iVar17 = iVar17 + -1;
                            local_c8 = (longlong)(int)(local_1a0 * fVar7);
                            local_d0 = (longlong)(int)(local_1ac * fVar7);
                            local_d8 = (longlong)(int)(local_1a8 * fVar7);
                            local_e0 = (longlong)(int)(local_1a4 * fVar7);
                            *(ushort *)puVar31 =
                                 (ushort)(int)(local_1a0 * fVar7) & 0xf000 |
                                 (ushort)((uint)(int)(local_1ac * fVar7) >> 4) & 0xf00 |
                                 (ushort)((uint)(int)(local_1a8 * fVar7) >> 8) & 0xf0 |
                                 (ushort)((uint)(int)(local_1a4 * fVar7) >> 0xc) & 0xf;
                            puVar31 = (uint *)((int)puVar31 + 2);
                            iVar24 = iVar24 + local_b0;
                          } while (iVar17 != 0);
                        }
                        uVar22 = uVar22 - 1;
                        iVar24 = iVar24 + local_bc;
                        puVar28 = (uint *)((int)puVar28 + iVar21);
                      } while (uVar22 != 0);
                    }
                    param_8 = param_8 - 1;
                    puVar26 = (uint *)((int)puVar26 + iVar27);
                    iVar24 = iVar24 + local_b4;
                  } while (param_8 != 0);
                }
                goto LAB_0002e240;
              }
            }
            else {
              if (uVar3 == 0x8367) {
                if (0 < (int)param_8) {
                  do {
                    uVar22 = param_7;
                    puVar28 = puVar26;
                    if (0 < (int)param_7) {
                      do {
                        dVar5 = DOUBLE_00108d80;
                        puVar31 = puVar28;
                        iVar17 = param_6;
                        if (0 < param_6) {
                          do {
                            (*pcVar19)(auStack_1b0,iVar24);
                            (*pcVar20)(param_1,auStack_1b0);
                            dVar32 = (double)local_1a0 * dVar6;
                            if (dVar5 <= dVar32) {
                              uVar23 = (uint)(int)(dVar32 - dVar5);
                              local_d0 = (longlong)(int)uVar23;
                              uVar23 = uVar23 ^ 0x80000000;
                            }
                            else {
                              uVar23 = (uint)(int)dVar32;
                              local_c8 = (longlong)(int)uVar23;
                            }
                            dVar32 = (double)local_1ac * dVar6;
                            if (DOUBLE_00108d80 <= dVar32) {
                              local_e0 = (longlong)(int)(dVar32 - DOUBLE_00108d80);
                              uVar18 = (int)(dVar32 - DOUBLE_00108d80) ^ 0x80000000;
                            }
                            else {
                              uVar18 = (uint)(int)dVar32;
                              local_d8 = (longlong)(int)uVar18;
                            }
                            dVar32 = (double)local_1a8 * dVar6;
                            if (DOUBLE_00108d80 <= dVar32) {
                              local_f0 = (longlong)(int)(dVar32 - DOUBLE_00108d80);
                              uVar12 = (int)(dVar32 - DOUBLE_00108d80) ^ 0x80000000;
                            }
                            else {
                              uVar12 = (uint)(int)dVar32;
                              local_e8 = (longlong)(int)uVar12;
                            }
                            dVar32 = (double)local_1a4 * dVar6;
                            if (DOUBLE_00108d80 <= dVar32) {
                              local_100 = (longlong)(int)(dVar32 - DOUBLE_00108d80);
                              uVar13 = (int)(dVar32 - DOUBLE_00108d80) ^ 0x80000000;
                            }
                            else {
                              uVar13 = (uint)(int)dVar32;
                              local_f8 = (longlong)(int)uVar13;
                            }
                            iVar17 = iVar17 + -1;
                            *puVar31 = uVar23 & 0xff000000 | uVar18 >> 8 & 0xff0000 |
                                       uVar12 >> 0x10 & 0xff00 | uVar13 >> 0x18;
                            iVar24 = iVar24 + local_b0;
                            puVar31 = puVar31 + 1;
                          } while (iVar17 != 0);
                        }
                        uVar22 = uVar22 - 1;
                        iVar24 = iVar24 + local_bc;
                        puVar28 = (uint *)((int)puVar28 + iVar21);
                      } while (uVar22 != 0);
                    }
                    param_8 = param_8 - 1;
                    puVar26 = (uint *)((int)puVar26 + iVar27);
                    iVar24 = iVar24 + local_b4;
                  } while (param_8 != 0);
                }
                goto LAB_0002e240;
              }
              if (uVar3 == 0x8368) {
                if (0 < (int)param_8) {
                  do {
                    uVar22 = param_7;
                    puVar28 = puVar26;
                    if (0 < (int)param_7) {
                      do {
                        dVar5 = DOUBLE_00108d80;
                        puVar31 = puVar28;
                        iVar17 = param_6;
                        if (0 < param_6) {
                          do {
                            (*pcVar19)(auStack_1b0,iVar24);
                            (*pcVar20)(param_1,auStack_1b0);
                            dVar32 = (double)local_1a0 * dVar6;
                            if (dVar5 <= dVar32) {
                              uVar23 = (uint)(int)(dVar32 - dVar5);
                              local_d0 = (longlong)(int)uVar23;
                              uVar23 = uVar23 ^ 0x80000000;
                            }
                            else {
                              uVar23 = (uint)(int)dVar32;
                              local_c8 = (longlong)(int)uVar23;
                            }
                            dVar32 = (double)local_1ac * dVar6;
                            if (DOUBLE_00108d80 <= dVar32) {
                              local_e0 = (longlong)(int)(dVar32 - DOUBLE_00108d80);
                              uVar18 = (int)(dVar32 - DOUBLE_00108d80) ^ 0x80000000;
                            }
                            else {
                              uVar18 = (uint)(int)dVar32;
                              local_d8 = (longlong)(int)uVar18;
                            }
                            dVar32 = (double)local_1a8 * dVar6;
                            if (DOUBLE_00108d80 <= dVar32) {
                              local_f0 = (longlong)(int)(dVar32 - DOUBLE_00108d80);
                              uVar12 = (int)(dVar32 - DOUBLE_00108d80) ^ 0x80000000;
                            }
                            else {
                              uVar12 = (uint)(int)dVar32;
                              local_e8 = (longlong)(int)uVar12;
                            }
                            dVar32 = (double)local_1a4 * dVar6;
                            if (DOUBLE_00108d80 <= dVar32) {
                              local_100 = (longlong)(int)(dVar32 - DOUBLE_00108d80);
                              uVar13 = (int)(dVar32 - DOUBLE_00108d80) ^ 0x80000000;
                            }
                            else {
                              uVar13 = (uint)(int)dVar32;
                              local_f8 = (longlong)(int)uVar13;
                            }
                            iVar17 = iVar17 + -1;
                            *puVar31 = uVar23 & 0xc0000000 | uVar18 >> 2 & 0x3ff00000 |
                                       uVar12 >> 0xc & 0xffc00 | uVar13 >> 0x16;
                            iVar24 = iVar24 + local_b0;
                            puVar31 = puVar31 + 1;
                          } while (iVar17 != 0);
                        }
                        uVar22 = uVar22 - 1;
                        iVar24 = iVar24 + local_bc;
                        puVar28 = (uint *)((int)puVar28 + iVar21);
                      } while (uVar22 != 0);
                    }
                    param_8 = param_8 - 1;
                    puVar26 = (uint *)((int)puVar26 + iVar27);
                    iVar24 = iVar24 + local_b4;
                  } while (param_8 != 0);
                }
                goto LAB_0002e240;
              }
            }
          }
          if (0 < (int)param_8) {
            do {
              uVar22 = param_7;
              puVar28 = puVar26;
              if (0 < (int)param_7) {
                do {
                  fVar9 = FLOAT_00108f70;
                  fVar8 = FLOAT_00108e54;
                  fVar7 = FLOAT_00108e50;
                  iVar29 = param_6;
                  puVar31 = puVar28;
                  if (0 < param_6) {
                    do {
                      local_1ac = fVar7;
                      local_1a8 = fVar7;
                      local_1a4 = fVar7;
                      local_1a0 = fVar8;
                      (*pcVar19)(auStack_1b0,iVar24);
                      (*pcVar20)(param_1,auStack_1b0);
                      if (fVar8 < local_1a4) {
                        uVar16 = 0xff;
                      }
                      else {
                        uVar16 = 0;
                        if (fVar7 <= local_1a4) {
                          (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)(int)(local_1a4 * fVar9);
                          uVar16 = (undefined1)local_c8;
                          local_c8 = (longlong)(int)(local_1a4 * fVar9);
                        }
                      }
                      *(undefined1 *)puVar31 = uVar16;
                      if (fVar8 < local_1a8) {
                        uVar16 = 0xff;
                      }
                      else {
                        uVar16 = 0;
                        if (fVar7 <= local_1a8) {
                          (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)(int)(local_1a8 * fVar9);
                          uVar16 = (undefined1)local_c8;
                          local_c8 = (longlong)(int)(local_1a8 * fVar9);
                        }
                      }
                      *(undefined1 *)((int)puVar31 + 1) = uVar16;
                      if (fVar8 < local_1ac) {
                        uVar16 = 0xff;
                      }
                      else {
                        uVar16 = 0;
                        if (fVar7 <= local_1ac) {
                          (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)(int)(local_1ac * fVar9);
                          uVar16 = (undefined1)local_c8;
                          local_c8 = (longlong)(int)(local_1ac * fVar9);
                        }
                      }
                      *(undefined1 *)((int)puVar31 + 2) = uVar16;
                      if (fVar8 < local_1a0) {
                        uVar16 = 0xff;
                      }
                      else {
                        uVar16 = 0;
                        if (fVar7 <= local_1a0) {
                          (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)(int)(local_1a0 * fVar9);
                          uVar16 = (undefined1)local_c8;
                          local_c8 = (longlong)(int)(local_1a0 * fVar9);
                        }
                      }
                      iVar29 = iVar29 + -1;
                      *(undefined1 *)((int)puVar31 + 3) = uVar16;
                      iVar24 = iVar24 + local_b0;
                      puVar31 = (uint *)((int)puVar31 + iVar17);
                    } while (iVar29 != 0);
                  }
                  uVar22 = uVar22 - 1;
                  iVar24 = iVar24 + local_bc;
                  puVar28 = (uint *)((int)puVar28 + iVar21);
                } while (uVar22 != 0);
              }
              param_8 = param_8 - 1;
              puVar26 = (uint *)((int)puVar26 + iVar27);
              iVar24 = iVar24 + local_b4;
            } while (param_8 != 0);
          }
          goto LAB_0002e240;
        }
        uVar14 = 0x86dc;
      }
      else {
        if (uVar3 == 0x86f5) {
          if (0 < (int)param_8) {
            do {
              uVar22 = param_7;
              puVar28 = puVar26;
              if (0 < (int)param_7) {
                do {
                  fVar9 = FLOAT_00108f6c;
                  fVar8 = FLOAT_00108e58;
                  fVar7 = FLOAT_00108e54;
                  iVar29 = param_6;
                  puVar31 = puVar28;
                  if (0 < param_6) {
                    do {
                      (*pcVar19)(auStack_1b0,iVar24);
                      (*pcVar20)(param_1,auStack_1b0);
                      if (fVar7 < local_188) {
                        uVar16 = 0x7f;
                      }
                      else {
                        uVar16 = 0x81;
                        if (fVar8 <= local_188) {
                          iVar1 = (int)(local_188 * fVar9);
                          (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)iVar1;
                          uVar16 = (undefined1)local_c8;
                          local_c8 = (longlong)iVar1;
                        }
                      }
                      *(undefined1 *)puVar31 = uVar16;
                      if (fVar7 < local_184) {
                        uVar16 = 0x7f;
                      }
                      else {
                        uVar16 = 0x81;
                        if (fVar8 <= local_184) {
                          iVar1 = (int)(local_184 * fVar9);
                          (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)iVar1;
                          uVar16 = (undefined1)local_c8;
                          local_c8 = (longlong)iVar1;
                        }
                      }
                      iVar29 = iVar29 + -1;
                      *(undefined1 *)((int)puVar31 + 1) = uVar16;
                      iVar24 = iVar24 + local_b0;
                      puVar31 = (uint *)((int)puVar31 + iVar17);
                    } while (iVar29 != 0);
                  }
                  uVar22 = uVar22 - 1;
                  iVar24 = iVar24 + local_bc;
                  puVar28 = (uint *)((int)puVar28 + iVar21);
                } while (uVar22 != 0);
              }
              param_8 = param_8 - 1;
              puVar26 = (uint *)((int)puVar26 + iVar27);
              iVar24 = iVar24 + local_b4;
            } while (param_8 != 0);
          }
          goto LAB_0002e240;
        }
        uVar14 = 0x86f6;
      }
      if (uVar3 == uVar14) {
        if (0 < (int)param_8) {
          do {
            puVar28 = puVar26;
            uVar22 = param_7;
            if (0 < (int)param_7) {
              do {
                fVar11 = FLOAT_00108f70;
                fVar10 = FLOAT_00108f6c;
                fVar9 = FLOAT_00108e58;
                fVar8 = FLOAT_00108e54;
                fVar7 = FLOAT_00108e50;
                if (0 < param_6) {
                  puVar30 = (undefined1 *)((int)puVar28 + 3);
                  iVar29 = param_6;
                  puVar31 = puVar28;
                  do {
                    (*pcVar19)(auStack_1b0,iVar24);
                    (*pcVar20)(param_1,auStack_1b0);
                    if (fVar8 < local_1ac) {
                      uVar16 = 0xff;
                    }
                    else {
                      uVar16 = 0;
                      if (fVar7 <= local_1ac) {
                        iVar1 = (int)(local_1ac * fVar11);
                        (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)iVar1;
                        uVar16 = (undefined1)local_c8;
                        local_c8 = (longlong)iVar1;
                      }
                    }
                    *(undefined1 *)puVar31 = uVar16;
                    if (fVar8 < local_180) {
                      uVar16 = 0xff;
                    }
                    else {
                      uVar16 = 0;
                      if (fVar7 <= local_180) {
                        iVar1 = (int)(local_180 * fVar11);
                        (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)iVar1;
                        uVar16 = (undefined1)local_c8;
                        local_c8 = (longlong)iVar1;
                      }
                    }
                    *(undefined1 *)((int)puVar31 + 1) = uVar16;
                    if (fVar8 < local_184) {
                      uVar16 = 0x7f;
                    }
                    else {
                      uVar16 = 0x81;
                      if (fVar9 <= local_184) {
                        iVar1 = (int)(local_184 * fVar10);
                        (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)iVar1;
                        uVar16 = (undefined1)local_c8;
                        local_c8 = (longlong)iVar1;
                      }
                    }
                    puVar30[-1] = uVar16;
                    if (fVar8 < local_188) {
                      uVar16 = 0x7f;
                    }
                    else {
                      uVar16 = 0x81;
                      if (fVar9 <= local_188) {
                        iVar1 = (int)(local_188 * fVar10);
                        (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)iVar1;
                        uVar16 = (undefined1)local_c8;
                        local_c8 = (longlong)iVar1;
                      }
                    }
                    iVar29 = iVar29 + -1;
                    *puVar30 = uVar16;
                    puVar30 = puVar30 + iVar17;
                    puVar31 = (uint *)((int)puVar31 + iVar17);
                    iVar24 = iVar24 + local_b0;
                  } while (iVar29 != 0);
                }
                uVar22 = uVar22 - 1;
                iVar24 = iVar24 + local_bc;
                puVar28 = (uint *)((int)puVar28 + iVar21);
              } while (uVar22 != 0);
            }
            param_8 = param_8 - 1;
            puVar26 = (uint *)((int)puVar26 + iVar27);
            iVar24 = iVar24 + local_b4;
          } while (param_8 != 0);
        }
        goto LAB_0002e240;
      }
    }
    if (*(short *)(param_2 + 0x12) == 0x1400) {
      if (0 < (int)param_8) {
        do {
          uVar22 = param_7;
          puVar28 = puVar26;
          if (0 < (int)param_7) {
            do {
              fVar9 = FLOAT_00108f6c;
              fVar8 = FLOAT_00108e58;
              fVar7 = FLOAT_00108e54;
              iVar29 = param_6;
              puVar31 = puVar28;
              if (0 < param_6) {
                do {
                  (*pcVar19)(auStack_1b0,iVar24);
                  _gleModifyPixelSignedRGBA(param_1,auStack_1b0);
                  if (fVar7 < local_1ac) {
                    uVar16 = 0x7f;
                  }
                  else {
                    uVar16 = 0x81;
                    if (fVar8 <= local_1ac) {
                      (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)(int)(local_1ac * fVar9);
                      uVar16 = (undefined1)local_c8;
                      local_c8 = (longlong)(int)(local_1ac * fVar9);
                    }
                  }
                  iVar29 = iVar29 + -1;
                  *(undefined1 *)puVar31 = uVar16;
                  iVar24 = iVar24 + local_b0;
                  puVar31 = (uint *)((int)puVar31 + iVar17);
                } while (iVar29 != 0);
              }
              uVar22 = uVar22 - 1;
              iVar24 = iVar24 + local_bc;
              puVar28 = (uint *)((int)puVar28 + iVar21);
            } while (uVar22 != 0);
          }
          param_8 = param_8 - 1;
          puVar26 = (uint *)((int)puVar26 + iVar27);
          iVar24 = iVar24 + local_b4;
        } while (param_8 != 0);
      }
    }
    else if (0 < (int)param_8) {
      do {
        uVar22 = param_7;
        puVar28 = puVar26;
        if (0 < (int)param_7) {
          do {
            fVar9 = FLOAT_00108f70;
            fVar8 = FLOAT_00108e54;
            fVar7 = FLOAT_00108e50;
            iVar29 = param_6;
            puVar31 = puVar28;
            if (0 < param_6) {
              do {
                local_1ac = fVar8;
                (*pcVar19)(auStack_1b0,iVar24);
                (*pcVar20)(param_1,auStack_1b0);
                if (fVar8 < local_1ac) {
                  uVar16 = 0xff;
                }
                else {
                  uVar16 = 0;
                  if (fVar7 <= local_1ac) {
                    (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)(int)(local_1ac * fVar9);
                    uVar16 = (undefined1)local_c8;
                    local_c8 = (longlong)(int)(local_1ac * fVar9);
                  }
                }
                iVar29 = iVar29 + -1;
                *(undefined1 *)puVar31 = uVar16;
                iVar24 = iVar24 + local_b0;
                puVar31 = (uint *)((int)puVar31 + iVar17);
              } while (iVar29 != 0);
            }
            uVar22 = uVar22 - 1;
            iVar24 = iVar24 + local_bc;
            puVar28 = (uint *)((int)puVar28 + iVar21);
          } while (uVar22 != 0);
        }
        param_8 = param_8 - 1;
        puVar26 = (uint *)((int)puVar26 + iVar27);
        iVar24 = iVar24 + local_b4;
      } while (param_8 != 0);
    }
    goto LAB_0002e240;
  }
  uVar3 = *(ushort *)(param_2 + 0x10);
  if (uVar3 == 0x190a) {
    if (*(short *)(param_2 + 0x12) == 1) {
      if (0 < (int)param_8) {
        do {
          uVar22 = param_7;
          puVar28 = puVar26;
          if (0 < (int)param_7) {
            do {
              fVar9 = FLOAT_00108f6c;
              fVar8 = FLOAT_00108e58;
              fVar7 = FLOAT_00108e54;
              iVar29 = param_6;
              puVar31 = puVar28;
              if (0 < param_6) {
                do {
                  (*pcVar19)(auStack_1b0,iVar24);
                  if (fVar7 < local_1a0) {
                    uVar16 = 0x7f;
                  }
                  else {
                    uVar16 = 0x81;
                    if (fVar8 <= local_1a0) {
                      iVar1 = (int)(local_1a0 * fVar9);
                      (*(unsigned char *)((unsigned char *)&(local_100) + 7)) = (undefined1)iVar1;
                      uVar16 = (undefined1)local_100;
                      local_100 = (longlong)iVar1;
                    }
                  }
                  *(undefined1 *)puVar31 = uVar16;
                  if (fVar7 < local_1ac) {
                    uVar16 = 0x7f;
                  }
                  else {
                    uVar16 = 0x81;
                    if (fVar8 <= local_1ac) {
                      iVar1 = (int)(local_1ac * fVar9);
                      (*(unsigned char *)((unsigned char *)&(local_100) + 7)) = (undefined1)iVar1;
                      uVar16 = (undefined1)local_100;
                      local_100 = (longlong)iVar1;
                    }
                  }
                  iVar29 = iVar29 + -1;
                  *(undefined1 *)((int)puVar31 + 1) = uVar16;
                  iVar24 = iVar24 + local_b0;
                  puVar31 = (uint *)((int)puVar31 + iVar17);
                } while (iVar29 != 0);
              }
              uVar22 = uVar22 - 1;
              iVar24 = iVar24 + local_bc;
              puVar28 = (uint *)((int)puVar28 + iVar21);
            } while (uVar22 != 0);
          }
          param_8 = param_8 - 1;
          puVar26 = (uint *)((int)puVar26 + iVar27);
          iVar24 = iVar24 + local_b4;
        } while (param_8 != 0);
      }
    }
    else if (0 < (int)param_8) {
      do {
        uVar22 = param_7;
        puVar28 = puVar26;
        if (0 < (int)param_7) {
          do {
            fVar9 = FLOAT_00108f70;
            fVar8 = FLOAT_00108e54;
            fVar7 = FLOAT_00108e50;
            iVar29 = param_6;
            puVar31 = puVar28;
            if (0 < param_6) {
              do {
                (*pcVar19)(auStack_1b0,iVar24);
                if (fVar8 < local_1ac) {
                  uVar16 = 0xff;
                }
                else {
                  uVar16 = 0;
                  if (fVar7 <= local_1ac) {
                    iVar1 = (int)(local_1ac * fVar9);
                    (*(unsigned char *)((unsigned char *)&(local_100) + 7)) = (undefined1)iVar1;
                    uVar16 = (undefined1)local_100;
                    local_100 = (longlong)iVar1;
                  }
                }
                *(undefined1 *)puVar31 = uVar16;
                if (fVar8 < local_1a0) {
                  uVar16 = 0xff;
                }
                else {
                  uVar16 = 0;
                  if (fVar7 <= local_1a0) {
                    iVar1 = (int)(local_1a0 * fVar9);
                    (*(unsigned char *)((unsigned char *)&(local_100) + 7)) = (undefined1)iVar1;
                    uVar16 = (undefined1)local_100;
                    local_100 = (longlong)iVar1;
                  }
                }
                iVar29 = iVar29 + -1;
                *(undefined1 *)((int)puVar31 + 1) = uVar16;
                iVar24 = iVar24 + local_b0;
                puVar31 = (uint *)((int)puVar31 + iVar17);
              } while (iVar29 != 0);
            }
            uVar22 = uVar22 - 1;
            iVar24 = iVar24 + local_bc;
            puVar28 = (uint *)((int)puVar28 + iVar21);
          } while (uVar22 != 0);
        }
        param_8 = param_8 - 1;
        puVar26 = (uint *)((int)puVar26 + iVar27);
        iVar24 = iVar24 + local_b4;
      } while (param_8 != 0);
    }
    goto LAB_0002e240;
  }
  if (uVar3 < 0x190b) {
    if (uVar3 == 0x1907) {
      uVar3 = *(ushort *)(param_2 + 0x12);
      if (uVar3 == 0x8362) {
        if (0 < (int)param_8) {
          do {
            uVar22 = param_7;
            puVar28 = puVar26;
            if (0 < (int)param_7) {
              do {
                fVar7 = FLOAT_00108f70;
                iVar17 = param_6;
                puVar31 = puVar28;
                if (0 < param_6) {
                  do {
                    (*pcVar19)(auStack_1b0,iVar24);
                    iVar17 = iVar17 + -1;
                    local_f0 = (longlong)(int)(local_1a4 * fVar7);
                    local_f8 = (longlong)(int)(local_1a8 * fVar7);
                    local_100 = (longlong)(int)(local_1ac * fVar7);
                    *(byte *)puVar31 =
                         (byte)(int)(local_1a4 * fVar7) & 0xc0 |
                         (byte)((uint)(int)(local_1a8 * fVar7) >> 2) & 0x38 |
                         (byte)((uint)(int)(local_1ac * fVar7) >> 5) & 7;
                    iVar24 = iVar24 + local_b0;
                    puVar31 = (uint *)((int)puVar31 + 1);
                  } while (iVar17 != 0);
                }
                uVar22 = uVar22 - 1;
                iVar24 = iVar24 + local_bc;
                puVar28 = (uint *)((int)puVar28 + iVar21);
              } while (uVar22 != 0);
            }
            param_8 = param_8 - 1;
            puVar26 = (uint *)((int)puVar26 + iVar27);
            iVar24 = iVar24 + local_b4;
          } while (param_8 != 0);
        }
        goto LAB_0002e240;
      }
      if (uVar3 < 0x8363) {
        if (uVar3 == 8) {
          if (0 < (int)param_8) {
            do {
              uVar22 = param_7;
              puVar28 = puVar26;
              if (0 < (int)param_7) {
                do {
                  fVar9 = FLOAT_00108f6c;
                  fVar8 = FLOAT_00108e58;
                  fVar7 = FLOAT_00108e54;
                  iVar29 = param_6;
                  puVar31 = puVar28;
                  if (0 < param_6) {
                    do {
                      (*pcVar19)(auStack_1b0,iVar24);
                      *(undefined1 *)puVar31 = 0x7f;
                      if (fVar7 < local_1ac) {
                        uVar16 = 0x7f;
                      }
                      else {
                        uVar16 = 0x81;
                        if (fVar8 <= local_1ac) {
                          (*(unsigned char *)((unsigned char *)&(local_f0) + 7)) = (undefined1)(int)(local_1ac * fVar9);
                          uVar16 = (undefined1)local_f0;
                          local_f0 = (longlong)(int)(local_1ac * fVar9);
                        }
                      }
                      *(undefined1 *)((int)puVar31 + 1) = uVar16;
                      if (fVar7 < local_1a8) {
                        uVar16 = 0x7f;
                      }
                      else {
                        uVar16 = 0x81;
                        if (fVar8 <= local_1a8) {
                          (*(unsigned char *)((unsigned char *)&(local_f0) + 7)) = (undefined1)(int)(local_1a8 * fVar9);
                          uVar16 = (undefined1)local_f0;
                          local_f0 = (longlong)(int)(local_1a8 * fVar9);
                        }
                      }
                      *(undefined1 *)((int)puVar31 + 2) = uVar16;
                      if (fVar7 < local_1a4) {
                        uVar16 = 0x7f;
                      }
                      else {
                        uVar16 = 0x81;
                        if (fVar8 <= local_1a4) {
                          (*(unsigned char *)((unsigned char *)&(local_f0) + 7)) = (undefined1)(int)(local_1a4 * fVar9);
                          uVar16 = (undefined1)local_f0;
                          local_f0 = (longlong)(int)(local_1a4 * fVar9);
                        }
                      }
                      iVar29 = iVar29 + -1;
                      *(undefined1 *)((int)puVar31 + 3) = uVar16;
                      iVar24 = iVar24 + local_b0;
                      puVar31 = (uint *)((int)puVar31 + iVar17);
                    } while (iVar29 != 0);
                  }
                  uVar22 = uVar22 - 1;
                  iVar24 = iVar24 + local_bc;
                  puVar28 = (uint *)((int)puVar28 + iVar21);
                } while (uVar22 != 0);
              }
              param_8 = param_8 - 1;
              puVar26 = (uint *)((int)puVar26 + iVar27);
              iVar24 = iVar24 + local_b4;
            } while (param_8 != 0);
          }
          goto LAB_0002e240;
        }
        if (uVar3 == 0x8032) {
          if (0 < (int)param_8) {
            do {
              uVar22 = param_7;
              puVar28 = puVar26;
              if (0 < (int)param_7) {
                do {
                  fVar7 = FLOAT_00108f70;
                  iVar17 = param_6;
                  puVar31 = puVar28;
                  if (0 < param_6) {
                    do {
                      (*pcVar19)(auStack_1b0,iVar24);
                      iVar17 = iVar17 + -1;
                      local_100 = (longlong)(int)(local_1ac * fVar7);
                      local_f8 = (longlong)(int)(local_1a8 * fVar7);
                      local_f0 = (longlong)(int)(local_1a4 * fVar7);
                      *(byte *)puVar31 =
                           (byte)(int)(local_1ac * fVar7) & 0xe0 |
                           (byte)((uint)(int)(local_1a8 * fVar7) >> 3) & 0x1c |
                           (byte)((uint)(int)(local_1a4 * fVar7) >> 6) & 3;
                      iVar24 = iVar24 + local_b0;
                      puVar31 = (uint *)((int)puVar31 + 1);
                    } while (iVar17 != 0);
                  }
                  uVar22 = uVar22 - 1;
                  iVar24 = iVar24 + local_bc;
                  puVar28 = (uint *)((int)puVar28 + iVar21);
                } while (uVar22 != 0);
              }
              param_8 = param_8 - 1;
              puVar26 = (uint *)((int)puVar26 + iVar27);
              iVar24 = iVar24 + local_b4;
            } while (param_8 != 0);
          }
          goto LAB_0002e240;
        }
      }
      else {
        if (uVar3 == 0x8363) {
          if (0 < (int)param_8) {
            do {
              uVar22 = param_7;
              puVar28 = puVar26;
              if (0 < (int)param_7) {
                do {
                  if (0 < param_6) {
                    local_90 = fVar7;
                    puVar31 = puVar28;
                    iVar17 = param_6;
                    do {
                      (*pcVar19)(auStack_1b0,iVar24);
                      iVar17 = iVar17 + -1;
                      local_f0 = (longlong)(int)(local_1ac * fVar7);
                      local_f8 = (longlong)(int)(local_1a8 * fVar7);
                      local_100 = (longlong)(int)(local_1a4 * fVar7);
                      *(ushort *)puVar31 =
                           (ushort)(int)(local_1ac * fVar7) & 0xf800 |
                           (ushort)((uint)(int)(local_1a8 * fVar7) >> 5) & 0x7e0 |
                           (ushort)((uint)(int)(local_1a4 * fVar7) >> 0xb) & 0x1f;
                      puVar31 = (uint *)((int)puVar31 + 2);
                      iVar24 = iVar24 + local_b0;
                    } while (iVar17 != 0);
                  }
                  uVar22 = uVar22 - 1;
                  iVar24 = iVar24 + local_bc;
                  puVar28 = (uint *)((int)puVar28 + iVar21);
                } while (uVar22 != 0);
              }
              param_8 = param_8 - 1;
              puVar26 = (uint *)((int)puVar26 + iVar27);
              iVar24 = iVar24 + local_b4;
            } while (param_8 != 0);
          }
          goto LAB_0002e240;
        }
        if (uVar3 == 0x8364) {
          if (0 < (int)param_8) {
            do {
              uVar22 = param_7;
              puVar28 = puVar26;
              if (0 < (int)param_7) {
                do {
                  if (0 < param_6) {
                    local_90 = fVar7;
                    puVar31 = puVar28;
                    iVar17 = param_6;
                    do {
                      (*pcVar19)(auStack_1b0,iVar24);
                      iVar17 = iVar17 + -1;
                      local_f0 = (longlong)(int)(local_1a4 * fVar7);
                      local_f8 = (longlong)(int)(local_1a8 * fVar7);
                      local_100 = (longlong)(int)(local_1ac * fVar7);
                      *(ushort *)puVar31 =
                           (ushort)(int)(local_1a4 * fVar7) & 0xf800 |
                           (ushort)((uint)(int)(local_1a8 * fVar7) >> 5) & 0x7e0 |
                           (ushort)((uint)(int)(local_1ac * fVar7) >> 0xb) & 0x1f;
                      puVar31 = (uint *)((int)puVar31 + 2);
                      iVar24 = iVar24 + local_b0;
                    } while (iVar17 != 0);
                  }
                  uVar22 = uVar22 - 1;
                  iVar24 = iVar24 + local_bc;
                  puVar28 = (uint *)((int)puVar28 + iVar21);
                } while (uVar22 != 0);
              }
              param_8 = param_8 - 1;
              puVar26 = (uint *)((int)puVar26 + iVar27);
              iVar24 = iVar24 + local_b4;
            } while (param_8 != 0);
          }
          goto LAB_0002e240;
        }
      }
      if (0 < (int)param_8) {
        do {
          uVar22 = param_7;
          puVar28 = puVar26;
          if (0 < (int)param_7) {
            do {
              fVar9 = FLOAT_00108f70;
              fVar8 = FLOAT_00108e54;
              fVar7 = FLOAT_00108e50;
              iVar29 = param_6;
              puVar31 = puVar28;
              if (0 < param_6) {
                do {
                  (*pcVar19)(auStack_1b0,iVar24);
                  if (fVar8 < local_1ac) {
                    uVar16 = 0xff;
                  }
                  else {
                    uVar16 = 0;
                    if (fVar7 <= local_1ac) {
                      (*(unsigned char *)((unsigned char *)&(local_f0) + 7)) = (undefined1)(int)(local_1ac * fVar9);
                      uVar16 = (undefined1)local_f0;
                      local_f0 = (longlong)(int)(local_1ac * fVar9);
                    }
                  }
                  *(undefined1 *)puVar31 = uVar16;
                  if (fVar8 < local_1a8) {
                    uVar16 = 0xff;
                  }
                  else {
                    uVar16 = 0;
                    if (fVar7 <= local_1a8) {
                      (*(unsigned char *)((unsigned char *)&(local_f0) + 7)) = (undefined1)(int)(local_1a8 * fVar9);
                      uVar16 = (undefined1)local_f0;
                      local_f0 = (longlong)(int)(local_1a8 * fVar9);
                    }
                  }
                  *(undefined1 *)((int)puVar31 + 1) = uVar16;
                  if (fVar8 < local_1a4) {
                    uVar16 = 0xff;
                  }
                  else {
                    uVar16 = 0;
                    if (fVar7 <= local_1a4) {
                      (*(unsigned char *)((unsigned char *)&(local_f0) + 7)) = (undefined1)(int)(local_1a4 * fVar9);
                      uVar16 = (undefined1)local_f0;
                      local_f0 = (longlong)(int)(local_1a4 * fVar9);
                    }
                  }
                  iVar29 = iVar29 + -1;
                  *(undefined1 *)((int)puVar31 + 2) = uVar16;
                  iVar24 = iVar24 + local_b0;
                  puVar31 = (uint *)((int)puVar31 + iVar17);
                } while (iVar29 != 0);
              }
              uVar22 = uVar22 - 1;
              iVar24 = iVar24 + local_bc;
              puVar28 = (uint *)((int)puVar28 + iVar21);
            } while (uVar22 != 0);
          }
          param_8 = param_8 - 1;
          puVar26 = (uint *)((int)puVar26 + iVar27);
          iVar24 = iVar24 + local_b4;
        } while (param_8 != 0);
      }
      goto LAB_0002e240;
    }
    if (uVar3 < 0x1908) {
      if (uVar3 == 0x1902) {
        if (*(short *)(param_2 + 0x12) == 0x1405) {
          if (0 < (int)param_8) {
            do {
              uVar22 = param_7;
              puVar28 = puVar26;
              if (0 < (int)param_7) {
                do {
                  dVar5 = DOUBLE_00108d80;
                  iVar29 = param_6;
                  puVar31 = puVar28;
                  if (0 < param_6) {
                    do {
                      (*pcVar19)(auStack_1b0,iVar24);
                      dVar32 = (double)local_19c * dVar6;
                      if (dVar5 <= dVar32) {
                        uVar23 = (uint)(int)(dVar32 - dVar5);
                        local_d0 = (longlong)(int)uVar23;
                        uVar23 = uVar23 ^ 0x80000000;
                      }
                      else {
                        uVar23 = (uint)(int)dVar32;
                        local_c8 = (longlong)(int)uVar23;
                      }
                      iVar29 = iVar29 + -1;
                      *puVar31 = uVar23;
                      iVar24 = iVar24 + local_b0;
                      puVar31 = puVar31 + iVar17;
                    } while (iVar29 != 0);
                  }
                  uVar22 = uVar22 - 1;
                  iVar24 = iVar24 + local_bc;
                  puVar28 = (uint *)((int)puVar28 + iVar21);
                } while (uVar22 != 0);
              }
              param_8 = param_8 - 1;
              puVar26 = (uint *)((int)puVar26 + iVar27);
              iVar24 = iVar24 + local_b4;
            } while (param_8 != 0);
          }
        }
        else if (0 < (int)param_8) {
          do {
            fVar7 = FLOAT_00108ea0;
            uVar22 = param_7;
            puVar28 = puVar26;
            if (0 < (int)param_7) {
              do {
                if (0 < param_6) {
                  local_90 = fVar7;
                  iVar29 = param_6;
                  puVar31 = puVar28;
                  do {
                    (*pcVar19)(auStack_1b0,iVar24);
                    iVar29 = iVar29 + -1;
                    iVar1 = (int)(local_19c * fVar7);
                    local_c8 = (longlong)iVar1;
                    *(short *)puVar31 = (short)iVar1;
                    puVar31 = (uint *)((int)puVar31 + iVar17 * 2);
                    iVar24 = iVar24 + local_b0;
                  } while (iVar29 != 0);
                }
                uVar22 = uVar22 - 1;
                iVar24 = iVar24 + local_bc;
                puVar28 = (uint *)((int)puVar28 + iVar21);
              } while (uVar22 != 0);
            }
            param_8 = param_8 - 1;
            puVar26 = (uint *)((int)puVar26 + iVar27);
            iVar24 = iVar24 + local_b4;
          } while (param_8 != 0);
        }
        goto LAB_0002e240;
      }
      if (uVar3 == 0x1906) {
        if (*(short *)(param_2 + 0x12) == 0x1400) {
          if (0 < (int)param_8) {
            do {
              uVar22 = param_7;
              puVar28 = puVar26;
              if (0 < (int)param_7) {
                do {
                  fVar9 = FLOAT_00108f70;
                  fVar8 = FLOAT_00108e54;
                  fVar7 = FLOAT_00108e50;
                  iVar29 = param_6;
                  puVar31 = puVar28;
                  if (0 < param_6) {
                    do {
                      (*pcVar19)(auStack_1b0,iVar24);
                      if (fVar8 < local_1a0) {
                        uVar16 = 0xff;
                      }
                      else {
                        uVar16 = 0;
                        if (fVar7 <= local_1a0) {
                          (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)(int)(local_1a0 * fVar9);
                          uVar16 = (undefined1)local_c8;
                          local_c8 = (longlong)(int)(local_1a0 * fVar9);
                        }
                      }
                      iVar29 = iVar29 + -1;
                      *(undefined1 *)puVar31 = uVar16;
                      iVar24 = iVar24 + local_b0;
                      puVar31 = (uint *)((int)puVar31 + iVar17);
                    } while (iVar29 != 0);
                  }
                  uVar22 = uVar22 - 1;
                  iVar24 = iVar24 + local_bc;
                  puVar28 = (uint *)((int)puVar28 + iVar21);
                } while (uVar22 != 0);
              }
              param_8 = param_8 - 1;
              puVar26 = (uint *)((int)puVar26 + iVar27);
              iVar24 = iVar24 + local_b4;
            } while (param_8 != 0);
          }
        }
        else if (0 < (int)param_8) {
          do {
            uVar22 = param_7;
            puVar28 = puVar26;
            if (0 < (int)param_7) {
              do {
                fVar9 = FLOAT_00108f70;
                fVar8 = FLOAT_00108e54;
                fVar7 = FLOAT_00108e50;
                iVar29 = param_6;
                puVar31 = puVar28;
                if (0 < param_6) {
                  do {
                    (*pcVar19)(auStack_1b0,iVar24);
                    if (fVar8 < local_1a0) {
                      uVar16 = 0xff;
                    }
                    else {
                      uVar16 = 0;
                      if (fVar7 <= local_1a0) {
                        (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)(int)(local_1a0 * fVar9);
                        uVar16 = (undefined1)local_c8;
                        local_c8 = (longlong)(int)(local_1a0 * fVar9);
                      }
                    }
                    iVar29 = iVar29 + -1;
                    *(undefined1 *)puVar31 = uVar16;
                    iVar24 = iVar24 + local_b0;
                    puVar31 = (uint *)((int)puVar31 + iVar17);
                  } while (iVar29 != 0);
                }
                uVar22 = uVar22 - 1;
                iVar24 = iVar24 + local_bc;
                puVar28 = (uint *)((int)puVar28 + iVar21);
              } while (uVar22 != 0);
            }
            param_8 = param_8 - 1;
            puVar26 = (uint *)((int)puVar26 + iVar27);
            iVar24 = iVar24 + local_b4;
          } while (param_8 != 0);
        }
        goto LAB_0002e240;
      }
    }
    else {
      if (uVar3 == 0x1908) {
        uVar3 = *(ushort *)(param_2 + 0x12);
        if (uVar3 == 0x8035) {
          if (0 < (int)param_8) {
            do {
              uVar22 = param_7;
              puVar28 = puVar26;
              if (0 < (int)param_7) {
                do {
                  dVar5 = DOUBLE_00108d80;
                  puVar31 = puVar28;
                  iVar17 = param_6;
                  if (0 < param_6) {
                    do {
                      (*pcVar19)(auStack_1b0,iVar24);
                      dVar32 = (double)local_1ac * dVar6;
                      if (dVar5 <= dVar32) {
                        uVar23 = (uint)(int)(dVar32 - dVar5);
                        local_f0 = (longlong)(int)uVar23;
                        uVar23 = uVar23 ^ 0x80000000;
                      }
                      else {
                        uVar23 = (uint)(int)dVar32;
                        local_e8 = (longlong)(int)uVar23;
                      }
                      dVar32 = (double)local_1a8 * dVar6;
                      if (DOUBLE_00108d80 <= dVar32) {
                        local_100 = (longlong)(int)(dVar32 - DOUBLE_00108d80);
                        uVar18 = (int)(dVar32 - DOUBLE_00108d80) ^ 0x80000000;
                      }
                      else {
                        uVar18 = (uint)(int)dVar32;
                        local_f8 = (longlong)(int)uVar18;
                      }
                      dVar32 = (double)local_1a4 * dVar6;
                      if (DOUBLE_00108d80 <= dVar32) {
                        local_d8 = (longlong)(int)(dVar32 - DOUBLE_00108d80);
                        uVar12 = (int)(dVar32 - DOUBLE_00108d80) ^ 0x80000000;
                      }
                      else {
                        uVar12 = (uint)(int)dVar32;
                        local_e0 = (longlong)(int)uVar12;
                      }
                      dVar32 = (double)local_1a0 * dVar6;
                      if (DOUBLE_00108d80 <= dVar32) {
                        local_c8 = (longlong)(int)(dVar32 - DOUBLE_00108d80);
                        uVar13 = (int)(dVar32 - DOUBLE_00108d80) ^ 0x80000000;
                      }
                      else {
                        uVar13 = (uint)(int)dVar32;
                        local_d0 = (longlong)(int)uVar13;
                      }
                      iVar17 = iVar17 + -1;
                      *puVar31 = uVar23 & 0xff000000 | uVar18 >> 8 & 0xff0000 |
                                 uVar12 >> 0x10 & 0xff00 | uVar13 >> 0x18;
                      iVar24 = iVar24 + local_b0;
                      puVar31 = puVar31 + 1;
                    } while (iVar17 != 0);
                  }
                  uVar22 = uVar22 - 1;
                  iVar24 = iVar24 + local_bc;
                  puVar28 = (uint *)((int)puVar28 + iVar21);
                } while (uVar22 != 0);
              }
              param_8 = param_8 - 1;
              puVar26 = (uint *)((int)puVar26 + iVar27);
              iVar24 = iVar24 + local_b4;
            } while (param_8 != 0);
          }
          goto LAB_0002e240;
        }
        if (uVar3 < 0x8036) {
          if (uVar3 == 8) {
            if (0 < (int)param_8) {
              do {
                uVar22 = param_7;
                puVar28 = puVar26;
                if (0 < (int)param_7) {
                  do {
                    fVar9 = FLOAT_00108f6c;
                    fVar8 = FLOAT_00108e58;
                    fVar7 = FLOAT_00108e54;
                    iVar29 = param_6;
                    puVar31 = puVar28;
                    if (0 < param_6) {
                      do {
                        (*pcVar19)(auStack_1b0,iVar24);
                        if (fVar7 < local_1a0) {
                          uVar16 = 0x7f;
                        }
                        else {
                          uVar16 = 0x81;
                          if (fVar8 <= local_1a0) {
                            (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)(int)(local_1a0 * fVar9);
                            uVar16 = (undefined1)local_c8;
                            local_c8 = (longlong)(int)(local_1a0 * fVar9);
                          }
                        }
                        *(undefined1 *)puVar31 = uVar16;
                        if (fVar7 < local_1ac) {
                          uVar16 = 0x7f;
                        }
                        else {
                          uVar16 = 0x81;
                          if (fVar8 <= local_1ac) {
                            (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)(int)(local_1ac * fVar9);
                            uVar16 = (undefined1)local_c8;
                            local_c8 = (longlong)(int)(local_1ac * fVar9);
                          }
                        }
                        *(undefined1 *)((int)puVar31 + 1) = uVar16;
                        if (fVar7 < local_1a8) {
                          uVar16 = 0x7f;
                        }
                        else {
                          uVar16 = 0x81;
                          if (fVar8 <= local_1a8) {
                            (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)(int)(local_1a8 * fVar9);
                            uVar16 = (undefined1)local_c8;
                            local_c8 = (longlong)(int)(local_1a8 * fVar9);
                          }
                        }
                        *(undefined1 *)((int)puVar31 + 2) = uVar16;
                        if (fVar7 < local_1a4) {
                          uVar16 = 0x7f;
                        }
                        else {
                          uVar16 = 0x81;
                          if (fVar8 <= local_1a4) {
                            (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)(int)(local_1a4 * fVar9);
                            uVar16 = (undefined1)local_c8;
                            local_c8 = (longlong)(int)(local_1a4 * fVar9);
                          }
                        }
                        iVar29 = iVar29 + -1;
                        *(undefined1 *)((int)puVar31 + 3) = uVar16;
                        iVar24 = iVar24 + local_b0;
                        puVar31 = (uint *)((int)puVar31 + iVar17);
                      } while (iVar29 != 0);
                    }
                    uVar22 = uVar22 - 1;
                    iVar24 = iVar24 + local_bc;
                    puVar28 = (uint *)((int)puVar28 + iVar21);
                  } while (uVar22 != 0);
                }
                param_8 = param_8 - 1;
                puVar26 = (uint *)((int)puVar26 + iVar27);
                iVar24 = iVar24 + local_b4;
              } while (param_8 != 0);
            }
            goto LAB_0002e240;
          }
          if (uVar3 < 9) {
            if (uVar3 == 7) {
              if (0 < (int)param_8) {
                do {
                  uVar22 = param_7;
                  puVar28 = puVar26;
                  if (0 < (int)param_7) {
                    do {
                      fVar11 = FLOAT_00108f70;
                      fVar10 = FLOAT_00108f6c;
                      fVar9 = FLOAT_00108e58;
                      fVar8 = FLOAT_00108e54;
                      fVar7 = FLOAT_00108e50;
                      if (0 < param_6) {
                        puVar30 = (undefined1 *)((int)puVar28 + 3);
                        puVar31 = puVar28;
                        iVar29 = param_6;
                        do {
                          (*pcVar19)(auStack_1b0,iVar24);
                          if (fVar8 < local_1a0) {
                            uVar16 = 0xff;
                          }
                          else {
                            uVar16 = 0;
                            if (fVar7 <= local_1a0) {
                              (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)(int)(local_1a0 * fVar11);
                              uVar16 = (undefined1)local_c8;
                              local_c8 = (longlong)(int)(local_1a0 * fVar11);
                            }
                          }
                          *(undefined1 *)puVar31 = uVar16;
                          if (fVar8 < local_1ac) {
                            uVar16 = 0x7f;
                          }
                          else {
                            uVar16 = 0x81;
                            if (fVar9 <= local_1ac) {
                              (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)(int)(local_1ac * fVar10);
                              uVar16 = (undefined1)local_c8;
                              local_c8 = (longlong)(int)(local_1ac * fVar10);
                            }
                          }
                          puVar30[-2] = uVar16;
                          if (fVar8 < local_1a8) {
                            uVar16 = 0x7f;
                          }
                          else {
                            uVar16 = 0x81;
                            if (fVar9 <= local_1a8) {
                              (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)(int)(local_1a8 * fVar10);
                              uVar16 = (undefined1)local_c8;
                              local_c8 = (longlong)(int)(local_1a8 * fVar10);
                            }
                          }
                          puVar30[-1] = uVar16;
                          if (fVar8 < local_1a4) {
                            uVar16 = 0x7f;
                          }
                          else {
                            uVar16 = 0x81;
                            if (fVar9 <= local_1a4) {
                              (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)(int)(local_1a4 * fVar10);
                              uVar16 = (undefined1)local_c8;
                              local_c8 = (longlong)(int)(local_1a4 * fVar10);
                            }
                          }
                          iVar29 = iVar29 + -1;
                          *puVar30 = uVar16;
                          puVar30 = puVar30 + iVar17;
                          puVar31 = (uint *)((int)puVar31 + iVar17);
                          iVar24 = iVar24 + local_b0;
                        } while (iVar29 != 0);
                      }
                      uVar22 = uVar22 - 1;
                      iVar24 = iVar24 + local_bc;
                      puVar28 = (uint *)((int)puVar28 + iVar21);
                    } while (uVar22 != 0);
                  }
                  param_8 = param_8 - 1;
                  puVar26 = (uint *)((int)puVar26 + iVar27);
                  iVar24 = iVar24 + local_b4;
                } while (param_8 != 0);
              }
              goto LAB_0002e240;
            }
          }
          else {
            if (uVar3 == 0x8033) {
              if (0 < (int)param_8) {
                do {
                  uVar22 = param_7;
                  puVar28 = puVar26;
                  if (0 < (int)param_7) {
                    do {
                      if (0 < param_6) {
                        local_90 = fVar7;
                        iVar17 = param_6;
                        puVar31 = puVar28;
                        do {
                          (*pcVar19)(auStack_1b0,iVar24);
                          iVar17 = iVar17 + -1;
                          local_f0 = (longlong)(int)(local_1ac * fVar7);
                          local_f8 = (longlong)(int)(local_1a8 * fVar7);
                          local_100 = (longlong)(int)(local_1a4 * fVar7);
                          local_e8 = (longlong)(int)(local_1a0 * fVar7);
                          *(ushort *)puVar31 =
                               (ushort)(int)(local_1ac * fVar7) & 0xf000 |
                               (ushort)((uint)(int)(local_1a8 * fVar7) >> 4) & 0xf00 |
                               (ushort)((uint)(int)(local_1a4 * fVar7) >> 8) & 0xf0 |
                               (ushort)((uint)(int)(local_1a0 * fVar7) >> 0xc) & 0xf;
                          puVar31 = (uint *)((int)puVar31 + 2);
                          iVar24 = iVar24 + local_b0;
                        } while (iVar17 != 0);
                      }
                      uVar22 = uVar22 - 1;
                      iVar24 = iVar24 + local_bc;
                      puVar28 = (uint *)((int)puVar28 + iVar21);
                    } while (uVar22 != 0);
                  }
                  param_8 = param_8 - 1;
                  puVar26 = (uint *)((int)puVar26 + iVar27);
                  iVar24 = iVar24 + local_b4;
                } while (param_8 != 0);
              }
              goto LAB_0002e240;
            }
            if (uVar3 == 0x8034) {
              if (0 < (int)param_8) {
                do {
                  uVar22 = param_7;
                  puVar28 = puVar26;
                  if (0 < (int)param_7) {
                    do {
                      if (0 < param_6) {
                        local_90 = fVar7;
                        iVar17 = param_6;
                        puVar31 = puVar28;
                        do {
                          (*pcVar19)(auStack_1b0,iVar24);
                          iVar17 = iVar17 + -1;
                          local_e8 = (longlong)(int)(local_1ac * fVar7);
                          local_f0 = (longlong)(int)(local_1a8 * fVar7);
                          local_f8 = (longlong)(int)(local_1a4 * fVar7);
                          local_100 = (longlong)(int)(local_1a0 * fVar7);
                          *(ushort *)puVar31 =
                               (ushort)(int)(local_1ac * fVar7) & 0xf800 |
                               (ushort)((uint)(int)(local_1a8 * fVar7) >> 5) & 0x7c0 |
                               (ushort)((uint)(int)(local_1a4 * fVar7) >> 10) & 0x3e |
                               (ushort)((uint)(int)(local_1a0 * fVar7) >> 0xf) & 1;
                          puVar31 = (uint *)((int)puVar31 + 2);
                          iVar24 = iVar24 + local_b0;
                        } while (iVar17 != 0);
                      }
                      uVar22 = uVar22 - 1;
                      iVar24 = iVar24 + local_bc;
                      puVar28 = (uint *)((int)puVar28 + iVar21);
                    } while (uVar22 != 0);
                  }
                  param_8 = param_8 - 1;
                  puVar26 = (uint *)((int)puVar26 + iVar27);
                  iVar24 = iVar24 + local_b4;
                } while (param_8 != 0);
              }
              goto LAB_0002e240;
            }
          }
        }
        else {
          if (uVar3 == 0x8366) {
            if (0 < (int)param_8) {
              do {
                uVar22 = param_7;
                puVar28 = puVar26;
                if (0 < (int)param_7) {
                  do {
                    if (0 < param_6) {
                      local_90 = fVar7;
                      iVar17 = param_6;
                      puVar31 = puVar28;
                      do {
                        (*pcVar19)(auStack_1b0,iVar24);
                        iVar17 = iVar17 + -1;
                        local_e8 = (longlong)(int)(local_1a0 * fVar7);
                        local_f0 = (longlong)(int)(local_1a4 * fVar7);
                        local_f8 = (longlong)(int)(local_1a8 * fVar7);
                        local_100 = (longlong)(int)(local_1ac * fVar7);
                        *(ushort *)puVar31 =
                             (ushort)(int)(local_1a0 * fVar7) & 0x8000 |
                             (ushort)((uint)(int)(local_1a4 * fVar7) >> 1) & 0x7c00 |
                             (ushort)((uint)(int)(local_1a8 * fVar7) >> 6) & 0x3e0 |
                             (ushort)((uint)(int)(local_1ac * fVar7) >> 0xb) & 0x1f;
                        puVar31 = (uint *)((int)puVar31 + 2);
                        iVar24 = iVar24 + local_b0;
                      } while (iVar17 != 0);
                    }
                    uVar22 = uVar22 - 1;
                    iVar24 = iVar24 + local_bc;
                    puVar28 = (uint *)((int)puVar28 + iVar21);
                  } while (uVar22 != 0);
                }
                param_8 = param_8 - 1;
                puVar26 = (uint *)((int)puVar26 + iVar27);
                iVar24 = iVar24 + local_b4;
              } while (param_8 != 0);
            }
            goto LAB_0002e240;
          }
          if (uVar3 < 0x8367) {
            if (uVar3 == 0x8036) {
              if (0 < (int)param_8) {
                do {
                  uVar22 = param_7;
                  puVar28 = puVar26;
                  if (0 < (int)param_7) {
                    do {
                      dVar5 = DOUBLE_00108d80;
                      puVar31 = puVar28;
                      iVar17 = param_6;
                      if (0 < param_6) {
                        do {
                          (*pcVar19)(auStack_1b0,iVar24);
                          dVar32 = (double)local_1ac * dVar6;
                          if (dVar5 <= dVar32) {
                            uVar23 = (uint)(int)(dVar32 - dVar5);
                            local_d0 = (longlong)(int)uVar23;
                            uVar23 = uVar23 ^ 0x80000000;
                          }
                          else {
                            uVar23 = (uint)(int)dVar32;
                            local_c8 = (longlong)(int)uVar23;
                          }
                          dVar32 = (double)local_1a8 * dVar6;
                          if (DOUBLE_00108d80 <= dVar32) {
                            local_e0 = (longlong)(int)(dVar32 - DOUBLE_00108d80);
                            uVar18 = (int)(dVar32 - DOUBLE_00108d80) ^ 0x80000000;
                          }
                          else {
                            uVar18 = (uint)(int)dVar32;
                            local_d8 = (longlong)(int)uVar18;
                          }
                          dVar32 = (double)local_1a4 * dVar6;
                          if (DOUBLE_00108d80 <= dVar32) {
                            local_f0 = (longlong)(int)(dVar32 - DOUBLE_00108d80);
                            uVar12 = (int)(dVar32 - DOUBLE_00108d80) ^ 0x80000000;
                          }
                          else {
                            uVar12 = (uint)(int)dVar32;
                            local_e8 = (longlong)(int)uVar12;
                          }
                          dVar32 = (double)local_1a0 * dVar6;
                          if (DOUBLE_00108d80 <= dVar32) {
                            local_100 = (longlong)(int)(dVar32 - DOUBLE_00108d80);
                            uVar13 = (int)(dVar32 - DOUBLE_00108d80) ^ 0x80000000;
                          }
                          else {
                            uVar13 = (uint)(int)dVar32;
                            local_f8 = (longlong)(int)uVar13;
                          }
                          iVar17 = iVar17 + -1;
                          *puVar31 = uVar23 & 0xffc00000 | uVar18 >> 10 & 0x3ff000 |
                                     uVar12 >> 0x14 & 0xffc | uVar13 >> 0x1e;
                          iVar24 = iVar24 + local_b0;
                          puVar31 = puVar31 + 1;
                        } while (iVar17 != 0);
                      }
                      uVar22 = uVar22 - 1;
                      iVar24 = iVar24 + local_bc;
                      puVar28 = (uint *)((int)puVar28 + iVar21);
                    } while (uVar22 != 0);
                  }
                  param_8 = param_8 - 1;
                  puVar26 = (uint *)((int)puVar26 + iVar27);
                  iVar24 = iVar24 + local_b4;
                } while (param_8 != 0);
              }
              goto LAB_0002e240;
            }
            if (uVar3 == 0x8365) {
              if (0 < (int)param_8) {
                do {
                  uVar22 = param_7;
                  puVar28 = puVar26;
                  if (0 < (int)param_7) {
                    do {
                      if (0 < param_6) {
                        local_90 = fVar7;
                        iVar17 = param_6;
                        puVar31 = puVar28;
                        do {
                          (*pcVar19)(auStack_1b0,iVar24);
                          iVar17 = iVar17 + -1;
                          local_e8 = (longlong)(int)(local_1a0 * fVar7);
                          local_f0 = (longlong)(int)(local_1a4 * fVar7);
                          local_f8 = (longlong)(int)(local_1a8 * fVar7);
                          local_100 = (longlong)(int)(local_1ac * fVar7);
                          *(ushort *)puVar31 =
                               (ushort)(int)(local_1a0 * fVar7) & 0xf000 |
                               (ushort)((uint)(int)(local_1a4 * fVar7) >> 4) & 0xf00 |
                               (ushort)((uint)(int)(local_1a8 * fVar7) >> 8) & 0xf0 |
                               (ushort)((uint)(int)(local_1ac * fVar7) >> 0xc) & 0xf;
                          puVar31 = (uint *)((int)puVar31 + 2);
                          iVar24 = iVar24 + local_b0;
                        } while (iVar17 != 0);
                      }
                      uVar22 = uVar22 - 1;
                      iVar24 = iVar24 + local_bc;
                      puVar28 = (uint *)((int)puVar28 + iVar21);
                    } while (uVar22 != 0);
                  }
                  param_8 = param_8 - 1;
                  puVar26 = (uint *)((int)puVar26 + iVar27);
                  iVar24 = iVar24 + local_b4;
                } while (param_8 != 0);
              }
              goto LAB_0002e240;
            }
          }
          else {
            if (uVar3 == 0x8367) {
              if (0 < (int)param_8) {
                do {
                  uVar22 = param_7;
                  puVar28 = puVar26;
                  if (0 < (int)param_7) {
                    do {
                      dVar5 = DOUBLE_00108d80;
                      puVar31 = puVar28;
                      iVar17 = param_6;
                      if (0 < param_6) {
                        do {
                          (*pcVar19)(auStack_1b0,iVar24);
                          dVar32 = (double)local_1a0 * dVar6;
                          if (dVar5 <= dVar32) {
                            uVar23 = (uint)(int)(dVar32 - dVar5);
                            local_d0 = (longlong)(int)uVar23;
                            uVar23 = uVar23 ^ 0x80000000;
                          }
                          else {
                            uVar23 = (uint)(int)dVar32;
                            local_c8 = (longlong)(int)uVar23;
                          }
                          dVar32 = (double)local_1a4 * dVar6;
                          if (DOUBLE_00108d80 <= dVar32) {
                            local_e0 = (longlong)(int)(dVar32 - DOUBLE_00108d80);
                            uVar18 = (int)(dVar32 - DOUBLE_00108d80) ^ 0x80000000;
                          }
                          else {
                            uVar18 = (uint)(int)dVar32;
                            local_d8 = (longlong)(int)uVar18;
                          }
                          dVar32 = (double)local_1a8 * dVar6;
                          if (DOUBLE_00108d80 <= dVar32) {
                            local_f0 = (longlong)(int)(dVar32 - DOUBLE_00108d80);
                            uVar12 = (int)(dVar32 - DOUBLE_00108d80) ^ 0x80000000;
                          }
                          else {
                            uVar12 = (uint)(int)dVar32;
                            local_e8 = (longlong)(int)uVar12;
                          }
                          dVar32 = (double)local_1ac * dVar6;
                          if (DOUBLE_00108d80 <= dVar32) {
                            local_100 = (longlong)(int)(dVar32 - DOUBLE_00108d80);
                            uVar13 = (int)(dVar32 - DOUBLE_00108d80) ^ 0x80000000;
                          }
                          else {
                            uVar13 = (uint)(int)dVar32;
                            local_f8 = (longlong)(int)uVar13;
                          }
                          iVar17 = iVar17 + -1;
                          *puVar31 = uVar23 & 0xff000000 | uVar18 >> 8 & 0xff0000 |
                                     uVar12 >> 0x10 & 0xff00 | uVar13 >> 0x18;
                          iVar24 = iVar24 + local_b0;
                          puVar31 = puVar31 + 1;
                        } while (iVar17 != 0);
                      }
                      uVar22 = uVar22 - 1;
                      iVar24 = iVar24 + local_bc;
                      puVar28 = (uint *)((int)puVar28 + iVar21);
                    } while (uVar22 != 0);
                  }
                  param_8 = param_8 - 1;
                  puVar26 = (uint *)((int)puVar26 + iVar27);
                  iVar24 = iVar24 + local_b4;
                } while (param_8 != 0);
              }
              goto LAB_0002e240;
            }
            if (uVar3 == 0x8368) {
              if (0 < (int)param_8) {
                do {
                  uVar22 = param_7;
                  puVar28 = puVar26;
                  if (0 < (int)param_7) {
                    do {
                      dVar5 = DOUBLE_00108d80;
                      puVar31 = puVar28;
                      iVar17 = param_6;
                      if (0 < param_6) {
                        do {
                          (*pcVar19)(auStack_1b0,iVar24);
                          dVar32 = (double)local_1a0 * dVar6;
                          if (dVar5 <= dVar32) {
                            uVar23 = (uint)(int)(dVar32 - dVar5);
                            local_d0 = (longlong)(int)uVar23;
                            uVar23 = uVar23 ^ 0x80000000;
                          }
                          else {
                            uVar23 = (uint)(int)dVar32;
                            local_c8 = (longlong)(int)uVar23;
                          }
                          dVar32 = (double)local_1a4 * dVar6;
                          if (DOUBLE_00108d80 <= dVar32) {
                            local_e0 = (longlong)(int)(dVar32 - DOUBLE_00108d80);
                            uVar18 = (int)(dVar32 - DOUBLE_00108d80) ^ 0x80000000;
                          }
                          else {
                            uVar18 = (uint)(int)dVar32;
                            local_d8 = (longlong)(int)uVar18;
                          }
                          dVar32 = (double)local_1a8 * dVar6;
                          if (DOUBLE_00108d80 <= dVar32) {
                            local_f0 = (longlong)(int)(dVar32 - DOUBLE_00108d80);
                            uVar12 = (int)(dVar32 - DOUBLE_00108d80) ^ 0x80000000;
                          }
                          else {
                            uVar12 = (uint)(int)dVar32;
                            local_e8 = (longlong)(int)uVar12;
                          }
                          dVar32 = (double)local_1ac * dVar6;
                          if (DOUBLE_00108d80 <= dVar32) {
                            local_100 = (longlong)(int)(dVar32 - DOUBLE_00108d80);
                            uVar13 = (int)(dVar32 - DOUBLE_00108d80) ^ 0x80000000;
                          }
                          else {
                            uVar13 = (uint)(int)dVar32;
                            local_f8 = (longlong)(int)uVar13;
                          }
                          iVar17 = iVar17 + -1;
                          *puVar31 = uVar23 & 0xc0000000 | uVar18 >> 2 & 0x3ff00000 |
                                     uVar12 >> 0xc & 0xffc00 | uVar13 >> 0x16;
                          iVar24 = iVar24 + local_b0;
                          puVar31 = puVar31 + 1;
                        } while (iVar17 != 0);
                      }
                      uVar22 = uVar22 - 1;
                      iVar24 = iVar24 + local_bc;
                      puVar28 = (uint *)((int)puVar28 + iVar21);
                    } while (uVar22 != 0);
                  }
                  param_8 = param_8 - 1;
                  puVar26 = (uint *)((int)puVar26 + iVar27);
                  iVar24 = iVar24 + local_b4;
                } while (param_8 != 0);
              }
              goto LAB_0002e240;
            }
          }
        }
        if (0 < (int)param_8) {
          do {
            uVar22 = param_7;
            puVar28 = puVar26;
            if (0 < (int)param_7) {
              do {
                fVar9 = FLOAT_00108f70;
                fVar8 = FLOAT_00108e54;
                fVar7 = FLOAT_00108e50;
                iVar29 = param_6;
                puVar31 = puVar28;
                if (0 < param_6) {
                  do {
                    (*pcVar19)(auStack_1b0,iVar24);
                    if (fVar8 < local_1ac) {
                      uVar16 = 0xff;
                    }
                    else {
                      uVar16 = 0;
                      if (fVar7 <= local_1ac) {
                        (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)(int)(local_1ac * fVar9);
                        uVar16 = (undefined1)local_c8;
                        local_c8 = (longlong)(int)(local_1ac * fVar9);
                      }
                    }
                    *(undefined1 *)puVar31 = uVar16;
                    if (fVar8 < local_1a8) {
                      uVar16 = 0xff;
                    }
                    else {
                      uVar16 = 0;
                      if (fVar7 <= local_1a8) {
                        (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)(int)(local_1a8 * fVar9);
                        uVar16 = (undefined1)local_c8;
                        local_c8 = (longlong)(int)(local_1a8 * fVar9);
                      }
                    }
                    *(undefined1 *)((int)puVar31 + 1) = uVar16;
                    if (fVar8 < local_1a4) {
                      uVar16 = 0xff;
                    }
                    else {
                      uVar16 = 0;
                      if (fVar7 <= local_1a4) {
                        (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)(int)(local_1a4 * fVar9);
                        uVar16 = (undefined1)local_c8;
                        local_c8 = (longlong)(int)(local_1a4 * fVar9);
                      }
                    }
                    *(undefined1 *)((int)puVar31 + 2) = uVar16;
                    if (fVar8 < local_1a0) {
                      uVar16 = 0xff;
                    }
                    else {
                      uVar16 = 0;
                      if (fVar7 <= local_1a0) {
                        (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)(int)(local_1a0 * fVar9);
                        uVar16 = (undefined1)local_c8;
                        local_c8 = (longlong)(int)(local_1a0 * fVar9);
                      }
                    }
                    iVar29 = iVar29 + -1;
                    *(undefined1 *)((int)puVar31 + 3) = uVar16;
                    iVar24 = iVar24 + local_b0;
                    puVar31 = (uint *)((int)puVar31 + iVar17);
                  } while (iVar29 != 0);
                }
                uVar22 = uVar22 - 1;
                iVar24 = iVar24 + local_bc;
                puVar28 = (uint *)((int)puVar28 + iVar21);
              } while (uVar22 != 0);
            }
            param_8 = param_8 - 1;
            puVar26 = (uint *)((int)puVar26 + iVar27);
            iVar24 = iVar24 + local_b4;
          } while (param_8 != 0);
        }
        goto LAB_0002e240;
      }
      if (uVar3 == 0x1909) {
        if (*(short *)(param_2 + 0x12) == 0x1400) {
          if (0 < (int)param_8) {
            do {
              uVar22 = param_7;
              puVar28 = puVar26;
              if (0 < (int)param_7) {
                do {
                  fVar9 = FLOAT_00108f6c;
                  fVar8 = FLOAT_00108e58;
                  fVar7 = FLOAT_00108e54;
                  iVar29 = param_6;
                  puVar31 = puVar28;
                  if (0 < param_6) {
                    do {
                      (*pcVar19)(auStack_1b0,iVar24);
                      if (fVar7 < local_1ac) {
                        uVar16 = 0x7f;
                      }
                      else {
                        uVar16 = 0x81;
                        if (fVar8 <= local_1ac) {
                          (*(unsigned char *)((unsigned char *)&(local_100) + 7)) = (undefined1)(int)(local_1ac * fVar9);
                          uVar16 = (undefined1)local_100;
                          local_100 = (longlong)(int)(local_1ac * fVar9);
                        }
                      }
                      iVar29 = iVar29 + -1;
                      *(undefined1 *)puVar31 = uVar16;
                      iVar24 = iVar24 + local_b0;
                      puVar31 = (uint *)((int)puVar31 + iVar17);
                    } while (iVar29 != 0);
                  }
                  uVar22 = uVar22 - 1;
                  iVar24 = iVar24 + local_bc;
                  puVar28 = (uint *)((int)puVar28 + iVar21);
                } while (uVar22 != 0);
              }
              param_8 = param_8 - 1;
              puVar26 = (uint *)((int)puVar26 + iVar27);
              iVar24 = iVar24 + local_b4;
            } while (param_8 != 0);
          }
        }
        else if (0 < (int)param_8) {
          do {
            uVar22 = param_7;
            puVar28 = puVar26;
            if (0 < (int)param_7) {
              do {
                fVar9 = FLOAT_00108f70;
                fVar8 = FLOAT_00108e54;
                fVar7 = FLOAT_00108e50;
                iVar29 = param_6;
                puVar31 = puVar28;
                if (0 < param_6) {
                  do {
                    (*pcVar19)(auStack_1b0,iVar24);
                    if (fVar8 < local_1ac) {
                      uVar16 = 0xff;
                    }
                    else {
                      uVar16 = 0;
                      if (fVar7 <= local_1ac) {
                        (*(unsigned char *)((unsigned char *)&(local_100) + 7)) = (undefined1)(int)(local_1ac * fVar9);
                        uVar16 = (undefined1)local_100;
                        local_100 = (longlong)(int)(local_1ac * fVar9);
                      }
                    }
                    iVar29 = iVar29 + -1;
                    *(undefined1 *)puVar31 = uVar16;
                    iVar24 = iVar24 + local_b0;
                    puVar31 = (uint *)((int)puVar31 + iVar17);
                  } while (iVar29 != 0);
                }
                uVar22 = uVar22 - 1;
                iVar24 = iVar24 + local_bc;
                puVar28 = (uint *)((int)puVar28 + iVar21);
              } while (uVar22 != 0);
            }
            param_8 = param_8 - 1;
            puVar26 = (uint *)((int)puVar26 + iVar27);
            iVar24 = iVar24 + local_b4;
          } while (param_8 != 0);
        }
        goto LAB_0002e240;
      }
    }
  }
  else {
    if (uVar3 == 0x86f4) {
      uVar3 = *(ushort *)(param_2 + 0x12);
      if (uVar3 == 6) {
        if (0 < (int)param_8) {
          do {
            fVar7 = FLOAT_00108f74;
            uVar22 = param_7;
            puVar28 = puVar26;
            if (0 < (int)param_7) {
              do {
                fVar9 = FLOAT_00108e58;
                fVar8 = FLOAT_00108e54;
                if (0 < param_6) {
                  local_90 = fVar7;
                  iVar29 = param_6;
                  puVar31 = puVar28;
                  do {
                    (*pcVar19)(auStack_1b0,iVar24);
                    if (fVar8 < local_190) {
                      uVar15 = 0x7fff;
                    }
                    else {
                      uVar15 = 0x8001;
                      if (fVar9 <= local_190) {
                        (*(unsigned short *)((unsigned char *)&(local_c8) + 6)) = (undefined2)(int)(local_190 * fVar7);
                        uVar15 = (*(unsigned short *)((unsigned char *)&(local_c8) + 6));
                        local_c8 = (longlong)(int)(local_190 * fVar7);
                      }
                    }
                    *(undefined2 *)puVar31 = uVar15;
                    if (fVar8 < local_18c) {
                      uVar15 = 0x7fff;
                    }
                    else {
                      uVar15 = 0x8001;
                      if (fVar9 <= local_18c) {
                        (*(unsigned short *)((unsigned char *)&(local_c8) + 6)) = (undefined2)(int)(local_18c * fVar7);
                        uVar15 = (*(unsigned short *)((unsigned char *)&(local_c8) + 6));
                        local_c8 = (longlong)(int)(local_18c * fVar7);
                      }
                    }
                    iVar29 = iVar29 + -1;
                    *(undefined2 *)((int)puVar31 + 2) = uVar15;
                    puVar31 = (uint *)((int)puVar31 + iVar17 * 2);
                    iVar24 = iVar24 + local_b0;
                  } while (iVar29 != 0);
                }
                uVar22 = uVar22 - 1;
                iVar24 = iVar24 + local_bc;
                puVar28 = (uint *)((int)puVar28 + iVar21);
              } while (uVar22 != 0);
            }
            param_8 = param_8 - 1;
            puVar26 = (uint *)((int)puVar26 + iVar27);
            iVar24 = iVar24 + local_b4;
          } while (param_8 != 0);
        }
      }
      else if (uVar3 < 7) {
        if ((uVar3 == 5) && (0 < (int)param_8)) {
          do {
            fVar7 = FLOAT_00108ea0;
            uVar22 = param_7;
            puVar28 = puVar26;
            if (0 < (int)param_7) {
              do {
                fVar9 = FLOAT_00108e54;
                fVar8 = FLOAT_00108e50;
                if (0 < param_6) {
                  local_90 = fVar7;
                  iVar29 = param_6;
                  puVar31 = puVar28;
                  do {
                    (*pcVar19)(auStack_1b0,iVar24);
                    if (fVar9 < local_190) {
                      uVar15 = 0xffff;
                    }
                    else {
                      uVar15 = 0;
                      if (fVar8 <= local_190) {
                        (*(unsigned short *)((unsigned char *)&(local_c8) + 6)) = (undefined2)(int)(local_190 * fVar7);
                        uVar15 = (*(unsigned short *)((unsigned char *)&(local_c8) + 6));
                        local_c8 = (longlong)(int)(local_190 * fVar7);
                      }
                    }
                    *(undefined2 *)puVar31 = uVar15;
                    if (fVar9 < local_18c) {
                      uVar15 = 0xffff;
                    }
                    else {
                      uVar15 = 0;
                      if (fVar8 <= local_18c) {
                        (*(unsigned short *)((unsigned char *)&(local_c8) + 6)) = (undefined2)(int)(local_18c * fVar7);
                        uVar15 = (*(unsigned short *)((unsigned char *)&(local_c8) + 6));
                        local_c8 = (longlong)(int)(local_18c * fVar7);
                      }
                    }
                    iVar29 = iVar29 + -1;
                    *(undefined2 *)((int)puVar31 + 2) = uVar15;
                    puVar31 = (uint *)((int)puVar31 + iVar17 * 2);
                    iVar24 = iVar24 + local_b0;
                  } while (iVar29 != 0);
                }
                uVar22 = uVar22 - 1;
                iVar24 = iVar24 + local_bc;
                puVar28 = (uint *)((int)puVar28 + iVar21);
              } while (uVar22 != 0);
            }
            param_8 = param_8 - 1;
            puVar26 = (uint *)((int)puVar26 + iVar27);
            iVar24 = iVar24 + local_b4;
          } while (param_8 != 0);
        }
      }
      else if (uVar3 == 0x1400) {
        if (0 < (int)param_8) {
          do {
            uVar22 = param_7;
            puVar28 = puVar26;
            if (0 < (int)param_7) {
              do {
                fVar9 = FLOAT_00108f6c;
                fVar8 = FLOAT_00108e58;
                fVar7 = FLOAT_00108e54;
                iVar29 = param_6;
                puVar31 = puVar28;
                if (0 < param_6) {
                  do {
                    (*pcVar19)(auStack_1b0,iVar24);
                    if (fVar7 < local_190) {
                      uVar16 = 0x7f;
                    }
                    else {
                      uVar16 = 0x81;
                      if (fVar8 <= local_190) {
                        iVar1 = (int)(local_190 * fVar9);
                        (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)iVar1;
                        uVar16 = (undefined1)local_c8;
                        local_c8 = (longlong)iVar1;
                      }
                    }
                    *(undefined1 *)puVar31 = uVar16;
                    if (fVar7 < local_18c) {
                      uVar16 = 0x7f;
                    }
                    else {
                      uVar16 = 0x81;
                      if (fVar8 <= local_18c) {
                        iVar1 = (int)(local_18c * fVar9);
                        (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)iVar1;
                        uVar16 = (undefined1)local_c8;
                        local_c8 = (longlong)iVar1;
                      }
                    }
                    iVar29 = iVar29 + -1;
                    *(undefined1 *)((int)puVar31 + 1) = uVar16;
                    iVar24 = iVar24 + local_b0;
                    puVar31 = (uint *)((int)puVar31 + iVar17);
                  } while (iVar29 != 0);
                }
                uVar22 = uVar22 - 1;
                iVar24 = iVar24 + local_bc;
                puVar28 = (uint *)((int)puVar28 + iVar21);
              } while (uVar22 != 0);
            }
            param_8 = param_8 - 1;
            puVar26 = (uint *)((int)puVar26 + iVar27);
            iVar24 = iVar24 + local_b4;
          } while (param_8 != 0);
        }
      }
      else if ((uVar3 == 0x1401) && (0 < (int)param_8)) {
        do {
          uVar22 = param_7;
          puVar28 = puVar26;
          if (0 < (int)param_7) {
            do {
              fVar9 = FLOAT_00108f70;
              fVar8 = FLOAT_00108e54;
              fVar7 = FLOAT_00108e50;
              iVar29 = param_6;
              puVar31 = puVar28;
              if (0 < param_6) {
                do {
                  (*pcVar19)(auStack_1b0,iVar24);
                  if (fVar8 < local_190) {
                    uVar16 = 0xff;
                  }
                  else {
                    uVar16 = 0;
                    if (fVar7 <= local_190) {
                      iVar1 = (int)(local_190 * fVar9);
                      (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)iVar1;
                      uVar16 = (undefined1)local_c8;
                      local_c8 = (longlong)iVar1;
                    }
                  }
                  *(undefined1 *)puVar31 = uVar16;
                  if (fVar8 < local_18c) {
                    uVar16 = 0xff;
                  }
                  else {
                    uVar16 = 0;
                    if (fVar7 <= local_18c) {
                      iVar1 = (int)(local_18c * fVar9);
                      (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)iVar1;
                      uVar16 = (undefined1)local_c8;
                      local_c8 = (longlong)iVar1;
                    }
                  }
                  iVar29 = iVar29 + -1;
                  *(undefined1 *)((int)puVar31 + 1) = uVar16;
                  iVar24 = iVar24 + local_b0;
                  puVar31 = (uint *)((int)puVar31 + iVar17);
                } while (iVar29 != 0);
              }
              uVar22 = uVar22 - 1;
              iVar24 = iVar24 + local_bc;
              puVar28 = (uint *)((int)puVar28 + iVar21);
            } while (uVar22 != 0);
          }
          param_8 = param_8 - 1;
          puVar26 = (uint *)((int)puVar26 + iVar27);
          iVar24 = iVar24 + local_b4;
        } while (param_8 != 0);
      }
      goto LAB_0002e240;
    }
    if (uVar3 < 0x86f5) {
      if (uVar3 == 0x80e1) {
        uVar3 = *(ushort *)(param_2 + 0x12);
        if (uVar3 == 0x8036) {
          if (0 < (int)param_8) {
            do {
              uVar22 = param_7;
              puVar28 = puVar26;
              if (0 < (int)param_7) {
                do {
                  dVar5 = DOUBLE_00108d80;
                  puVar31 = puVar28;
                  iVar17 = param_6;
                  if (0 < param_6) {
                    do {
                      (*pcVar19)(auStack_1b0,iVar24);
                      dVar32 = (double)local_1a4 * dVar6;
                      if (dVar5 <= dVar32) {
                        uVar23 = (uint)(int)(dVar32 - dVar5);
                        local_d0 = (longlong)(int)uVar23;
                        uVar23 = uVar23 ^ 0x80000000;
                      }
                      else {
                        uVar23 = (uint)(int)dVar32;
                        local_c8 = (longlong)(int)uVar23;
                      }
                      dVar32 = (double)local_1a8 * dVar6;
                      if (DOUBLE_00108d80 <= dVar32) {
                        local_e0 = (longlong)(int)(dVar32 - DOUBLE_00108d80);
                        uVar18 = (int)(dVar32 - DOUBLE_00108d80) ^ 0x80000000;
                      }
                      else {
                        uVar18 = (uint)(int)dVar32;
                        local_d8 = (longlong)(int)uVar18;
                      }
                      dVar32 = (double)local_1ac * dVar6;
                      if (DOUBLE_00108d80 <= dVar32) {
                        local_f0 = (longlong)(int)(dVar32 - DOUBLE_00108d80);
                        uVar12 = (int)(dVar32 - DOUBLE_00108d80) ^ 0x80000000;
                      }
                      else {
                        uVar12 = (uint)(int)dVar32;
                        local_e8 = (longlong)(int)uVar12;
                      }
                      dVar32 = (double)local_1a0 * dVar6;
                      if (DOUBLE_00108d80 <= dVar32) {
                        local_100 = (longlong)(int)(dVar32 - DOUBLE_00108d80);
                        uVar13 = (int)(dVar32 - DOUBLE_00108d80) ^ 0x80000000;
                      }
                      else {
                        uVar13 = (uint)(int)dVar32;
                        local_f8 = (longlong)(int)uVar13;
                      }
                      iVar17 = iVar17 + -1;
                      *puVar31 = uVar23 & 0xffc00000 | uVar18 >> 10 & 0x3ff000 |
                                 uVar12 >> 0x14 & 0xffc | uVar13 >> 0x1e;
                      iVar24 = iVar24 + local_b0;
                      puVar31 = puVar31 + 1;
                    } while (iVar17 != 0);
                  }
                  uVar22 = uVar22 - 1;
                  iVar24 = iVar24 + local_bc;
                  puVar28 = (uint *)((int)puVar28 + iVar21);
                } while (uVar22 != 0);
              }
              param_8 = param_8 - 1;
              puVar26 = (uint *)((int)puVar26 + iVar27);
              iVar24 = iVar24 + local_b4;
            } while (param_8 != 0);
          }
          goto LAB_0002e240;
        }
        if (uVar3 < 0x8037) {
          if (uVar3 == 0x8034) {
            if (0 < (int)param_8) {
              do {
                uVar22 = param_7;
                puVar28 = puVar26;
                if (0 < (int)param_7) {
                  do {
                    if (0 < param_6) {
                      local_90 = fVar7;
                      iVar17 = param_6;
                      puVar31 = puVar28;
                      do {
                        (*pcVar19)(auStack_1b0,iVar24);
                        iVar17 = iVar17 + -1;
                        local_c8 = (longlong)(int)(local_1a4 * fVar7);
                        local_d0 = (longlong)(int)(local_1a8 * fVar7);
                        local_d8 = (longlong)(int)(local_1ac * fVar7);
                        local_e0 = (longlong)(int)(local_1a0 * fVar7);
                        *(ushort *)puVar31 =
                             (ushort)(int)(local_1a4 * fVar7) & 0xf800 |
                             (ushort)((uint)(int)(local_1a8 * fVar7) >> 5) & 0x7c0 |
                             (ushort)((uint)(int)(local_1ac * fVar7) >> 10) & 0x3e |
                             (ushort)((uint)(int)(local_1a0 * fVar7) >> 0xf) & 1;
                        puVar31 = (uint *)((int)puVar31 + 2);
                        iVar24 = iVar24 + local_b0;
                      } while (iVar17 != 0);
                    }
                    uVar22 = uVar22 - 1;
                    iVar24 = iVar24 + local_bc;
                    puVar28 = (uint *)((int)puVar28 + iVar21);
                  } while (uVar22 != 0);
                }
                param_8 = param_8 - 1;
                puVar26 = (uint *)((int)puVar26 + iVar27);
                iVar24 = iVar24 + local_b4;
              } while (param_8 != 0);
            }
            goto LAB_0002e240;
          }
          if (0x8034 < uVar3) {
            if (0 < (int)param_8) {
              do {
                uVar22 = param_7;
                puVar28 = puVar26;
                if (0 < (int)param_7) {
                  do {
                    dVar5 = DOUBLE_00108d80;
                    puVar31 = puVar28;
                    iVar17 = param_6;
                    if (0 < param_6) {
                      do {
                        (*pcVar19)(auStack_1b0,iVar24);
                        dVar32 = (double)local_1a4 * dVar6;
                        if (dVar5 <= dVar32) {
                          uVar23 = (uint)(int)(dVar32 - dVar5);
                          local_d0 = (longlong)(int)uVar23;
                          uVar23 = uVar23 ^ 0x80000000;
                        }
                        else {
                          uVar23 = (uint)(int)dVar32;
                          local_c8 = (longlong)(int)uVar23;
                        }
                        dVar32 = (double)local_1a8 * dVar6;
                        if (DOUBLE_00108d80 <= dVar32) {
                          local_e0 = (longlong)(int)(dVar32 - DOUBLE_00108d80);
                          uVar18 = (int)(dVar32 - DOUBLE_00108d80) ^ 0x80000000;
                        }
                        else {
                          uVar18 = (uint)(int)dVar32;
                          local_d8 = (longlong)(int)uVar18;
                        }
                        dVar32 = (double)local_1ac * dVar6;
                        if (DOUBLE_00108d80 <= dVar32) {
                          local_f0 = (longlong)(int)(dVar32 - DOUBLE_00108d80);
                          uVar12 = (int)(dVar32 - DOUBLE_00108d80) ^ 0x80000000;
                        }
                        else {
                          uVar12 = (uint)(int)dVar32;
                          local_e8 = (longlong)(int)uVar12;
                        }
                        dVar32 = (double)local_1a0 * dVar6;
                        if (DOUBLE_00108d80 <= dVar32) {
                          local_100 = (longlong)(int)(dVar32 - DOUBLE_00108d80);
                          uVar13 = (int)(dVar32 - DOUBLE_00108d80) ^ 0x80000000;
                        }
                        else {
                          uVar13 = (uint)(int)dVar32;
                          local_f8 = (longlong)(int)uVar13;
                        }
                        iVar17 = iVar17 + -1;
                        *puVar31 = uVar23 & 0xff000000 | uVar18 >> 8 & 0xff0000 |
                                   uVar12 >> 0x10 & 0xff00 | uVar13 >> 0x18;
                        iVar24 = iVar24 + local_b0;
                        puVar31 = puVar31 + 1;
                      } while (iVar17 != 0);
                    }
                    uVar22 = uVar22 - 1;
                    iVar24 = iVar24 + local_bc;
                    puVar28 = (uint *)((int)puVar28 + iVar21);
                  } while (uVar22 != 0);
                }
                param_8 = param_8 - 1;
                puVar26 = (uint *)((int)puVar26 + iVar27);
                iVar24 = iVar24 + local_b4;
              } while (param_8 != 0);
            }
            goto LAB_0002e240;
          }
          if (uVar3 == 0x8033) {
            if (0 < (int)param_8) {
              do {
                uVar22 = param_7;
                puVar28 = puVar26;
                if (0 < (int)param_7) {
                  do {
                    if (0 < param_6) {
                      local_90 = fVar7;
                      iVar17 = param_6;
                      puVar31 = puVar28;
                      do {
                        (*pcVar19)(auStack_1b0,iVar24);
                        iVar17 = iVar17 + -1;
                        local_c8 = (longlong)(int)(local_1a4 * fVar7);
                        local_d0 = (longlong)(int)(local_1a8 * fVar7);
                        local_d8 = (longlong)(int)(local_1ac * fVar7);
                        local_e0 = (longlong)(int)(local_1a0 * fVar7);
                        *(ushort *)puVar31 =
                             (ushort)(int)(local_1a4 * fVar7) & 0xf000 |
                             (ushort)((uint)(int)(local_1a8 * fVar7) >> 4) & 0xf00 |
                             (ushort)((uint)(int)(local_1ac * fVar7) >> 8) & 0xf0 |
                             (ushort)((uint)(int)(local_1a0 * fVar7) >> 0xc) & 0xf;
                        puVar31 = (uint *)((int)puVar31 + 2);
                        iVar24 = iVar24 + local_b0;
                      } while (iVar17 != 0);
                    }
                    uVar22 = uVar22 - 1;
                    iVar24 = iVar24 + local_bc;
                    puVar28 = (uint *)((int)puVar28 + iVar21);
                  } while (uVar22 != 0);
                }
                param_8 = param_8 - 1;
                puVar26 = (uint *)((int)puVar26 + iVar27);
                iVar24 = iVar24 + local_b4;
              } while (param_8 != 0);
            }
            goto LAB_0002e240;
          }
        }
        else {
          if (uVar3 == 0x8366) {
            if (0 < (int)param_8) {
              do {
                uVar22 = param_7;
                puVar28 = puVar26;
                if (0 < (int)param_7) {
                  do {
                    if (0 < param_6) {
                      local_90 = fVar7;
                      iVar17 = param_6;
                      puVar31 = puVar28;
                      do {
                        (*pcVar19)(auStack_1b0,iVar24);
                        iVar17 = iVar17 + -1;
                        local_c8 = (longlong)(int)(local_1a0 * fVar7);
                        local_d0 = (longlong)(int)(local_1ac * fVar7);
                        local_d8 = (longlong)(int)(local_1a8 * fVar7);
                        local_e0 = (longlong)(int)(local_1a4 * fVar7);
                        *(ushort *)puVar31 =
                             (ushort)(int)(local_1a0 * fVar7) & 0x8000 |
                             (ushort)((uint)(int)(local_1ac * fVar7) >> 1) & 0x7c00 |
                             (ushort)((uint)(int)(local_1a8 * fVar7) >> 6) & 0x3e0 |
                             (ushort)((uint)(int)(local_1a4 * fVar7) >> 0xb) & 0x1f;
                        puVar31 = (uint *)((int)puVar31 + 2);
                        iVar24 = iVar24 + local_b0;
                      } while (iVar17 != 0);
                    }
                    uVar22 = uVar22 - 1;
                    iVar24 = iVar24 + local_bc;
                    puVar28 = (uint *)((int)puVar28 + iVar21);
                  } while (uVar22 != 0);
                }
                param_8 = param_8 - 1;
                puVar26 = (uint *)((int)puVar26 + iVar27);
                iVar24 = iVar24 + local_b4;
              } while (param_8 != 0);
            }
            goto LAB_0002e240;
          }
          if (uVar3 < 0x8367) {
            if (uVar3 == 0x8365) {
              if (0 < (int)param_8) {
                do {
                  uVar22 = param_7;
                  puVar28 = puVar26;
                  if (0 < (int)param_7) {
                    do {
                      if (0 < param_6) {
                        local_90 = fVar7;
                        iVar17 = param_6;
                        puVar31 = puVar28;
                        do {
                          (*pcVar19)(auStack_1b0,iVar24);
                          iVar17 = iVar17 + -1;
                          local_c8 = (longlong)(int)(local_1a0 * fVar7);
                          local_d0 = (longlong)(int)(local_1ac * fVar7);
                          local_d8 = (longlong)(int)(local_1a8 * fVar7);
                          local_e0 = (longlong)(int)(local_1a4 * fVar7);
                          *(ushort *)puVar31 =
                               (ushort)(int)(local_1a0 * fVar7) & 0xf000 |
                               (ushort)((uint)(int)(local_1ac * fVar7) >> 4) & 0xf00 |
                               (ushort)((uint)(int)(local_1a8 * fVar7) >> 8) & 0xf0 |
                               (ushort)((uint)(int)(local_1a4 * fVar7) >> 0xc) & 0xf;
                          puVar31 = (uint *)((int)puVar31 + 2);
                          iVar24 = iVar24 + local_b0;
                        } while (iVar17 != 0);
                      }
                      uVar22 = uVar22 - 1;
                      iVar24 = iVar24 + local_bc;
                      puVar28 = (uint *)((int)puVar28 + iVar21);
                    } while (uVar22 != 0);
                  }
                  param_8 = param_8 - 1;
                  puVar26 = (uint *)((int)puVar26 + iVar27);
                  iVar24 = iVar24 + local_b4;
                } while (param_8 != 0);
              }
              goto LAB_0002e240;
            }
          }
          else {
            if (uVar3 == 0x8367) {
              if (0 < (int)param_8) {
                do {
                  uVar22 = param_7;
                  puVar28 = puVar26;
                  if (0 < (int)param_7) {
                    do {
                      dVar5 = DOUBLE_00108d80;
                      puVar31 = puVar28;
                      iVar17 = param_6;
                      if (0 < param_6) {
                        do {
                          (*pcVar19)(auStack_1b0,iVar24);
                          dVar32 = (double)local_1a0 * dVar6;
                          if (dVar5 <= dVar32) {
                            uVar23 = (uint)(int)(dVar32 - dVar5);
                            local_d0 = (longlong)(int)uVar23;
                            uVar23 = uVar23 ^ 0x80000000;
                          }
                          else {
                            uVar23 = (uint)(int)dVar32;
                            local_c8 = (longlong)(int)uVar23;
                          }
                          dVar32 = (double)local_1ac * dVar6;
                          if (DOUBLE_00108d80 <= dVar32) {
                            local_e0 = (longlong)(int)(dVar32 - DOUBLE_00108d80);
                            uVar18 = (int)(dVar32 - DOUBLE_00108d80) ^ 0x80000000;
                          }
                          else {
                            uVar18 = (uint)(int)dVar32;
                            local_d8 = (longlong)(int)uVar18;
                          }
                          dVar32 = (double)local_1a8 * dVar6;
                          if (DOUBLE_00108d80 <= dVar32) {
                            local_f0 = (longlong)(int)(dVar32 - DOUBLE_00108d80);
                            uVar12 = (int)(dVar32 - DOUBLE_00108d80) ^ 0x80000000;
                          }
                          else {
                            uVar12 = (uint)(int)dVar32;
                            local_e8 = (longlong)(int)uVar12;
                          }
                          dVar32 = (double)local_1a4 * dVar6;
                          if (DOUBLE_00108d80 <= dVar32) {
                            local_100 = (longlong)(int)(dVar32 - DOUBLE_00108d80);
                            uVar13 = (int)(dVar32 - DOUBLE_00108d80) ^ 0x80000000;
                          }
                          else {
                            uVar13 = (uint)(int)dVar32;
                            local_f8 = (longlong)(int)uVar13;
                          }
                          iVar17 = iVar17 + -1;
                          *puVar31 = uVar23 & 0xff000000 | uVar18 >> 8 & 0xff0000 |
                                     uVar12 >> 0x10 & 0xff00 | uVar13 >> 0x18;
                          iVar24 = iVar24 + local_b0;
                          puVar31 = puVar31 + 1;
                        } while (iVar17 != 0);
                      }
                      uVar22 = uVar22 - 1;
                      iVar24 = iVar24 + local_bc;
                      puVar28 = (uint *)((int)puVar28 + iVar21);
                    } while (uVar22 != 0);
                  }
                  param_8 = param_8 - 1;
                  puVar26 = (uint *)((int)puVar26 + iVar27);
                  iVar24 = iVar24 + local_b4;
                } while (param_8 != 0);
              }
              goto LAB_0002e240;
            }
            if (uVar3 == 0x8368) {
              if (0 < (int)param_8) {
                do {
                  uVar22 = param_7;
                  puVar28 = puVar26;
                  if (0 < (int)param_7) {
                    do {
                      dVar5 = DOUBLE_00108d80;
                      puVar31 = puVar28;
                      iVar17 = param_6;
                      if (0 < param_6) {
                        do {
                          (*pcVar19)(auStack_1b0,iVar24);
                          dVar32 = (double)local_1a0 * dVar6;
                          if (dVar5 <= dVar32) {
                            uVar23 = (uint)(int)(dVar32 - dVar5);
                            local_d0 = (longlong)(int)uVar23;
                            uVar23 = uVar23 ^ 0x80000000;
                          }
                          else {
                            uVar23 = (uint)(int)dVar32;
                            local_c8 = (longlong)(int)uVar23;
                          }
                          dVar32 = (double)local_1ac * dVar6;
                          if (DOUBLE_00108d80 <= dVar32) {
                            local_e0 = (longlong)(int)(dVar32 - DOUBLE_00108d80);
                            uVar18 = (int)(dVar32 - DOUBLE_00108d80) ^ 0x80000000;
                          }
                          else {
                            uVar18 = (uint)(int)dVar32;
                            local_d8 = (longlong)(int)uVar18;
                          }
                          dVar32 = (double)local_1a8 * dVar6;
                          if (DOUBLE_00108d80 <= dVar32) {
                            local_f0 = (longlong)(int)(dVar32 - DOUBLE_00108d80);
                            uVar12 = (int)(dVar32 - DOUBLE_00108d80) ^ 0x80000000;
                          }
                          else {
                            uVar12 = (uint)(int)dVar32;
                            local_e8 = (longlong)(int)uVar12;
                          }
                          dVar32 = (double)local_1a4 * dVar6;
                          if (DOUBLE_00108d80 <= dVar32) {
                            local_100 = (longlong)(int)(dVar32 - DOUBLE_00108d80);
                            uVar13 = (int)(dVar32 - DOUBLE_00108d80) ^ 0x80000000;
                          }
                          else {
                            uVar13 = (uint)(int)dVar32;
                            local_f8 = (longlong)(int)uVar13;
                          }
                          iVar17 = iVar17 + -1;
                          *puVar31 = uVar23 & 0xc0000000 | uVar18 >> 2 & 0x3ff00000 |
                                     uVar12 >> 0xc & 0xffc00 | uVar13 >> 0x16;
                          iVar24 = iVar24 + local_b0;
                          puVar31 = puVar31 + 1;
                        } while (iVar17 != 0);
                      }
                      uVar22 = uVar22 - 1;
                      iVar24 = iVar24 + local_bc;
                      puVar28 = (uint *)((int)puVar28 + iVar21);
                    } while (uVar22 != 0);
                  }
                  param_8 = param_8 - 1;
                  puVar26 = (uint *)((int)puVar26 + iVar27);
                  iVar24 = iVar24 + local_b4;
                } while (param_8 != 0);
              }
              goto LAB_0002e240;
            }
          }
        }
        if (0 < (int)param_8) {
          do {
            uVar22 = param_7;
            puVar28 = puVar26;
            if (0 < (int)param_7) {
              do {
                fVar9 = FLOAT_00108f70;
                fVar8 = FLOAT_00108e54;
                fVar7 = FLOAT_00108e50;
                iVar29 = param_6;
                puVar31 = puVar28;
                if (0 < param_6) {
                  do {
                    (*pcVar19)(auStack_1b0,iVar24);
                    if (fVar8 < local_1a4) {
                      uVar16 = 0xff;
                    }
                    else {
                      uVar16 = 0;
                      if (fVar7 <= local_1a4) {
                        (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)(int)(local_1a4 * fVar9);
                        uVar16 = (undefined1)local_c8;
                        local_c8 = (longlong)(int)(local_1a4 * fVar9);
                      }
                    }
                    *(undefined1 *)puVar31 = uVar16;
                    if (fVar8 < local_1a8) {
                      uVar16 = 0xff;
                    }
                    else {
                      uVar16 = 0;
                      if (fVar7 <= local_1a8) {
                        (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)(int)(local_1a8 * fVar9);
                        uVar16 = (undefined1)local_c8;
                        local_c8 = (longlong)(int)(local_1a8 * fVar9);
                      }
                    }
                    *(undefined1 *)((int)puVar31 + 1) = uVar16;
                    if (fVar8 < local_1ac) {
                      uVar16 = 0xff;
                    }
                    else {
                      uVar16 = 0;
                      if (fVar7 <= local_1ac) {
                        (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)(int)(local_1ac * fVar9);
                        uVar16 = (undefined1)local_c8;
                        local_c8 = (longlong)(int)(local_1ac * fVar9);
                      }
                    }
                    *(undefined1 *)((int)puVar31 + 2) = uVar16;
                    if (fVar8 < local_1a0) {
                      uVar16 = 0xff;
                    }
                    else {
                      uVar16 = 0;
                      if (fVar7 <= local_1a0) {
                        (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)(int)(local_1a0 * fVar9);
                        uVar16 = (undefined1)local_c8;
                        local_c8 = (longlong)(int)(local_1a0 * fVar9);
                      }
                    }
                    iVar29 = iVar29 + -1;
                    *(undefined1 *)((int)puVar31 + 3) = uVar16;
                    iVar24 = iVar24 + local_b0;
                    puVar31 = (uint *)((int)puVar31 + iVar17);
                  } while (iVar29 != 0);
                }
                uVar22 = uVar22 - 1;
                iVar24 = iVar24 + local_bc;
                puVar28 = (uint *)((int)puVar28 + iVar21);
              } while (uVar22 != 0);
            }
            param_8 = param_8 - 1;
            puVar26 = (uint *)((int)puVar26 + iVar27);
            iVar24 = iVar24 + local_b4;
          } while (param_8 != 0);
        }
        goto LAB_0002e240;
      }
      uVar14 = 0x86dc;
    }
    else {
      if (uVar3 == 0x86f5) {
        if (0 < (int)param_8) {
          do {
            uVar22 = param_7;
            puVar28 = puVar26;
            if (0 < (int)param_7) {
              do {
                fVar9 = FLOAT_00108f6c;
                fVar8 = FLOAT_00108e58;
                fVar7 = FLOAT_00108e54;
                iVar29 = param_6;
                puVar31 = puVar28;
                if (0 < param_6) {
                  do {
                    (*pcVar19)(auStack_1b0,iVar24);
                    if (fVar7 < local_188) {
                      uVar16 = 0x7f;
                    }
                    else {
                      uVar16 = 0x81;
                      if (fVar8 <= local_188) {
                        iVar1 = (int)(local_188 * fVar9);
                        (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)iVar1;
                        uVar16 = (undefined1)local_c8;
                        local_c8 = (longlong)iVar1;
                      }
                    }
                    *(undefined1 *)((int)puVar31 + 1) = uVar16;
                    if (fVar7 < local_184) {
                      uVar16 = 0x7f;
                    }
                    else {
                      uVar16 = 0x81;
                      if (fVar8 <= local_184) {
                        iVar1 = (int)(local_184 * fVar9);
                        (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)iVar1;
                        uVar16 = (undefined1)local_c8;
                        local_c8 = (longlong)iVar1;
                      }
                    }
                    iVar29 = iVar29 + -1;
                    *(undefined1 *)puVar31 = uVar16;
                    iVar24 = iVar24 + local_b0;
                    puVar31 = (uint *)((int)puVar31 + iVar17);
                  } while (iVar29 != 0);
                }
                uVar22 = uVar22 - 1;
                iVar24 = iVar24 + local_bc;
                puVar28 = (uint *)((int)puVar28 + iVar21);
              } while (uVar22 != 0);
            }
            param_8 = param_8 - 1;
            puVar26 = (uint *)((int)puVar26 + iVar27);
            iVar24 = iVar24 + local_b4;
          } while (param_8 != 0);
        }
        goto LAB_0002e240;
      }
      uVar14 = 0x86f6;
    }
    if (uVar3 == uVar14) {
      if (0 < (int)param_8) {
        do {
          uVar22 = param_7;
          puVar28 = puVar26;
          if (0 < (int)param_7) {
            do {
              fVar11 = FLOAT_00108f70;
              fVar10 = FLOAT_00108f6c;
              fVar9 = FLOAT_00108e58;
              fVar8 = FLOAT_00108e54;
              fVar7 = FLOAT_00108e50;
              if (0 < param_6) {
                puVar30 = (undefined1 *)((int)puVar28 + 2);
                puVar31 = puVar28;
                iVar29 = param_6;
                do {
                  (*pcVar19)(auStack_1b0,iVar24);
                  if (fVar8 < local_188) {
                    uVar16 = 0x7f;
                  }
                  else {
                    uVar16 = 0x81;
                    if (fVar9 <= local_188) {
                      iVar1 = (int)(local_188 * fVar10);
                      (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)iVar1;
                      uVar16 = (undefined1)local_c8;
                      local_c8 = (longlong)iVar1;
                    }
                  }
                  puVar30[1] = uVar16;
                  if (fVar8 < local_184) {
                    uVar16 = 0x7f;
                  }
                  else {
                    uVar16 = 0x81;
                    if (fVar9 <= local_184) {
                      iVar1 = (int)(local_184 * fVar10);
                      (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)iVar1;
                      uVar16 = (undefined1)local_c8;
                      local_c8 = (longlong)iVar1;
                    }
                  }
                  *puVar30 = uVar16;
                  if (fVar8 < local_180) {
                    uVar16 = 0xff;
                  }
                  else {
                    uVar16 = 0;
                    if (fVar7 <= local_180) {
                      iVar1 = (int)(local_180 * fVar11);
                      (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)iVar1;
                      uVar16 = (undefined1)local_c8;
                      local_c8 = (longlong)iVar1;
                    }
                  }
                  *(undefined1 *)((int)puVar31 + 1) = uVar16;
                  if (fVar8 < local_1ac) {
                    uVar16 = 0xff;
                  }
                  else {
                    uVar16 = 0;
                    if (fVar7 <= local_1ac) {
                      iVar1 = (int)(local_1ac * fVar11);
                      (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)iVar1;
                      uVar16 = (undefined1)local_c8;
                      local_c8 = (longlong)iVar1;
                    }
                  }
                  iVar29 = iVar29 + -1;
                  *(undefined1 *)puVar31 = uVar16;
                  puVar30 = puVar30 + iVar17;
                  puVar31 = (uint *)((int)puVar31 + iVar17);
                  iVar24 = iVar24 + local_b0;
                } while (iVar29 != 0);
              }
              uVar22 = uVar22 - 1;
              iVar24 = iVar24 + local_bc;
              puVar28 = (uint *)((int)puVar28 + iVar21);
            } while (uVar22 != 0);
          }
          param_8 = param_8 - 1;
          puVar26 = (uint *)((int)puVar26 + iVar27);
          iVar24 = iVar24 + local_b4;
        } while (param_8 != 0);
      }
      goto LAB_0002e240;
    }
  }
  if (*(short *)(param_2 + 0x12) == 0x1400) {
    if (0 < (int)param_8) {
      do {
        uVar22 = param_7;
        puVar28 = puVar26;
        if (0 < (int)param_7) {
          do {
            fVar9 = FLOAT_00108f6c;
            fVar8 = FLOAT_00108e58;
            fVar7 = FLOAT_00108e54;
            iVar29 = param_6;
            puVar31 = puVar28;
            if (0 < param_6) {
              do {
                (*pcVar19)(auStack_1b0,iVar24);
                if (fVar7 < local_1ac) {
                  uVar16 = 0x7f;
                }
                else {
                  uVar16 = 0x81;
                  if (fVar8 <= local_1ac) {
                    (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)(int)(local_1ac * fVar9);
                    uVar16 = (undefined1)local_c8;
                    local_c8 = (longlong)(int)(local_1ac * fVar9);
                  }
                }
                iVar29 = iVar29 + -1;
                *(undefined1 *)puVar31 = uVar16;
                iVar24 = iVar24 + local_b0;
                puVar31 = (uint *)((int)puVar31 + iVar17);
              } while (iVar29 != 0);
            }
            uVar22 = uVar22 - 1;
            iVar24 = iVar24 + local_bc;
            puVar28 = (uint *)((int)puVar28 + iVar21);
          } while (uVar22 != 0);
        }
        param_8 = param_8 - 1;
        puVar26 = (uint *)((int)puVar26 + iVar27);
        iVar24 = iVar24 + local_b4;
      } while (param_8 != 0);
    }
  }
  else if (0 < (int)param_8) {
    do {
      uVar22 = param_7;
      puVar28 = puVar26;
      if (0 < (int)param_7) {
        do {
          fVar9 = FLOAT_00108f70;
          fVar8 = FLOAT_00108e54;
          fVar7 = FLOAT_00108e50;
          iVar29 = param_6;
          puVar31 = puVar28;
          if (0 < param_6) {
            do {
              (*pcVar19)(auStack_1b0,iVar24);
              if (fVar8 < local_1ac) {
                uVar16 = 0xff;
              }
              else {
                uVar16 = 0;
                if (fVar7 <= local_1ac) {
                  (*(unsigned char *)((unsigned char *)&(local_c8) + 7)) = (undefined1)(int)(local_1ac * fVar9);
                  uVar16 = (undefined1)local_c8;
                  local_c8 = (longlong)(int)(local_1ac * fVar9);
                }
              }
              iVar29 = iVar29 + -1;
              *(undefined1 *)puVar31 = uVar16;
              iVar24 = iVar24 + local_b0;
              puVar31 = (uint *)((int)puVar31 + iVar17);
            } while (iVar29 != 0);
          }
          uVar22 = uVar22 - 1;
          iVar24 = iVar24 + local_bc;
          puVar28 = (uint *)((int)puVar28 + iVar21);
        } while (uVar22 != 0);
      }
      param_8 = param_8 - 1;
      puVar26 = (uint *)((int)puVar26 + iVar27);
      iVar24 = iVar24 + local_b4;
    } while (param_8 != 0);
  }
LAB_0002e240:
  if (bVar4) {
    _free(param_13);
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

