#include "decls.h"

/* _glStencilFuncSeparate_ListExec @ 0x907f8 (56 bytes) */
int _glStencilFuncSeparate_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  ((int (*)())_glStencilFuncSeparate_Exec)(param_1,*param_2,param_2[1],param_2[2],param_2[3]);
  return 0x10;
}

/* _glStencilFuncSeparate_Comp @ 0x90830 (100 bytes) */
int _glStencilFuncSeparate_Comp(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glStencilFuncSeparate_ListExec_00110308,0x10);
  if (puVar1 != (undefined4 *)0x0) {
    puVar1[3] = param_5;
    *puVar1 = param_2;
    puVar1[1] = param_3;
    puVar1[2] = param_4;
  }
  return puVar1;
}

/* _glStencilFuncSeparate_Exec @ 0x90894 (212 bytes) */
int _glStencilFuncSeparate_Exec(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  uint param_2;
  int param_3;
  uint param_4;
  undefined4 param_5;
{
  undefined4 uVar1;
  uint uVar2;
  undefined2 uVar3;
  
  if (-1 < *(short *)(param_1 + 0x4a10)) {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar1 = 0x502;
    goto LAB_000908d0;
  }
  if (7 < param_3 - 0x200U) goto LAB_000908c0;
  if ((int)param_4 < 0) {
    param_4 = 0;
  }
  else {
    uVar2 = 0xffffffff >> (0x20U - *(int *)(*(int *)(param_1 + 0x468c) + 0x40) & 0x3f);
    if (uVar2 < param_4) {
      param_4 = uVar2;
    }
  }
  uVar3 = (undefined2)param_3;
  if (param_2 == 0x405) {
    *(undefined2 *)(param_1 + 0x3510) = uVar3;
    *(uint *)(param_1 + 0x350c) = param_4;
    *(undefined4 *)(param_1 + 0x3508) = param_5;
    goto LAB_00090958;
  }
  if (param_2 < 0x406) {
    if (param_2 == 0x404) {
LAB_0009094c:
      *(undefined2 *)(param_1 + 0x3500) = uVar3;
      *(uint *)(param_1 + 0x34fc) = param_4;
      *(undefined4 *)(param_1 + 0x34f8) = param_5;
LAB_00090958:
      *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x10000000;
      return;
    }
  }
  else if (param_2 == 0x408) {
    *(undefined2 *)(param_1 + 0x3510) = uVar3;
    *(uint *)(param_1 + 0x350c) = param_4;
    *(undefined4 *)(param_1 + 0x3508) = param_5;
    goto LAB_0009094c;
  }
LAB_000908c0:
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  uVar1 = 0x500;
LAB_000908d0:
  *(undefined4 *)(param_1 + 0x7574) = uVar1;
  return;
}

/* _glStencilFuncSeparate_CompExec @ 0x90968 (80 bytes) */
int _glStencilFuncSeparate_CompExec(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  ((int (*)())_glStencilFuncSeparate_Comp)(param_1,param_2,param_3,param_4,param_5);
  ((int (*)())_glStencilFuncSeparate_Exec)(param_1,param_2,param_3,param_4,param_5);
  return;
}

/* _glLineStipple_ListExec @ 0x909b8 (44 bytes) */
int _glLineStipple_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  ((int (*)())_glLineStipple_Exec)(param_1,*param_2,(uint)*(ushort *)(param_2 + 1));
  return 8;
}

/* _glLineStipple_Comp @ 0x909e4 (84 bytes) */
int _glLineStipple_Comp(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glLineStipple_ListExec_00110324,8);
  if (puVar1 != (undefined4 *)0x0) {
    *(undefined2 *)(puVar1 + 1) = (*(unsigned short *)((unsigned char *)&(param_3) + 2));
    *puVar1 = param_2;
  }
  return puVar1;
}

/* _glLineStipple_Exec @ 0x90a38 (88 bytes) */
int _glLineStipple_Exec(param_1, param_2, param_3)
  int param_1;
  int param_2;
  undefined4 param_3;
{
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if (param_2 < 1) {
      param_2 = 1;
    }
    else if (0xff < param_2) {
      param_2 = 0xff;
    }
    *(int *)(param_1 + 0x3184) = param_2;
    *(undefined2 *)(param_1 + 0x3188) = (*(unsigned short *)((unsigned char *)&(param_3) + 2));
    *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x8000;
    return;
  }
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  *(undefined4 *)(param_1 + 0x7574) = 0x502;
  return;
}

/* _glLineStipple_CompExec @ 0x90a90 (64 bytes) */
int _glLineStipple_CompExec(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  ((int (*)())_glLineStipple_Comp)(param_1,param_2,param_3);
  ((int (*)())_glLineStipple_Exec)(param_1,param_2,param_3);
  return;
}

/* _glPolygonStipple_ListExec @ 0x90ad0 (40 bytes) */
int _glPolygonStipple_ListExec(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  
  iVar2 = 0x10;
  iVar1 = 0;
  do {
    *(undefined8 *)(iVar1 + param_1 + 0x3448) = *(undefined8 *)(iVar1 + param_2);
    iVar1 = iVar1 + 8;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return 0x80;
}

/* _glPolygonStipple_Comp @ 0x90af8 (304 bytes) */
int _glPolygonStipple_Comp(param_1, param_2)
  int param_1;
  int param_2;
{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar5 = *(int *)(param_1 + 0x4a6c);
  if (iVar5 != 0) {
    if (*(int *)(iVar5 + 0x38) < param_2 + 0x20) {
      if (*(int *)(param_1 + 0x7574) != 0) {
        return param_1;
      }
      *(undefined4 *)(param_1 + 0x7574) = 0x502;
      return param_1;
    }
    if (*(int *)(iVar5 + 0x40) != 0) {
      _gleSynchronizePluginBuffer(param_1,iVar5 + 0x10);
    }
    param_2 = param_2 + *(int *)(iVar5 + 0x30);
  }
  iVar5 = _gleAddListItem(param_1,PTR__glPolygonStipple_ListExec_00110320,0x80);
  if (iVar5 != 0) {
    uVar1 = *(uint *)(param_1 + 0x31d8);
    iVar3 = *(int *)(param_1 + 0x31d4);
    if ((((*(char *)(param_1 + 0x31e5) != '\0') || (*(int *)(param_1 + 0x31cc) != 0)) ||
        (4 < *(int *)(param_1 + 0x31e0))) || ((uVar1 & 7) != 0)) {
      uVar2 = _gleFillImage(param_1,0x20,0x20,1,0x1900,0x1a00,param_2,iVar5);
      return uVar2;
    }
    iVar4 = 0;
    iVar6 = 0x10;
    do {
      *(undefined8 *)(iVar4 + iVar5) =
           *(undefined8 *)(iVar4 + param_2 + iVar3 * 4 + ((int)uVar1 >> 3));
      iVar4 = iVar4 + 8;
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
  }
  return iVar5;
}

/* _glPolygonStipple_Exec @ 0x90c28 (288 bytes) */
int _glPolygonStipple_Exec(param_1, param_2)
  int param_1;
  int param_2;
{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    iVar3 = *(int *)(param_1 + 0x4a6c);
    if (iVar3 != 0) {
      if (*(int *)(iVar3 + 0x38) < param_2 + 0x20) goto LAB_00090c68;
      if (*(int *)(iVar3 + 0x40) != 0) {
        _gleSynchronizePluginBuffer(param_1,iVar3 + 0x10);
      }
      param_2 = param_2 + *(int *)(iVar3 + 0x30);
    }
    uVar1 = *(uint *)(param_1 + 0x31d8);
    iVar3 = *(int *)(param_1 + 0x31d4);
    if ((((*(char *)(param_1 + 0x31e5) == '\0') && (*(int *)(param_1 + 0x31cc) == 0)) &&
        (*(int *)(param_1 + 0x31e0) < 5)) && ((uVar1 & 7) == 0)) {
      iVar4 = 0x10;
      iVar2 = 0;
      do {
        *(undefined8 *)(iVar2 + param_1 + 0x3448) =
             *(undefined8 *)(iVar2 + param_2 + iVar3 * 4 + ((int)uVar1 >> 3));
        iVar2 = iVar2 + 8;
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
    }
    else {
      _gleFillImage(param_1,0x20,0x20,1,0x1900,0x1a00,param_2,param_1 + 0x3448);
    }
    *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x1000000;
  }
  else {
LAB_00090c68:
    if (*(int *)(param_1 + 0x7574) == 0) {
      *(undefined4 *)(param_1 + 0x7574) = 0x502;
    }
  }
  return;
}

/* _glPolygonStipple_CompExec @ 0x90d48 (56 bytes) */
int _glPolygonStipple_CompExec(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  ((int (*)())_glPolygonStipple_Comp)(param_1,param_2);
  ((int (*)())_glPolygonStipple_Exec)(param_1,param_2);
  return;
}

/* _glGetPolygonStipple_Exec @ 0x90d80 (284 bytes) */
int _glGetPolygonStipple_Exec(param_1, param_2)
  int param_1;
  int param_2;
{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    iVar3 = *(int *)(param_1 + 0x4a68);
    if (iVar3 != 0) {
      if (*(int *)(iVar3 + 0x38) < param_2 + 0x20) goto LAB_00090dc0;
      if (*(int *)(iVar3 + 0x40) != 0) {
        _gleSynchronizePluginBuffer(param_1,iVar3 + 0x10);
      }
      param_2 = param_2 + *(int *)(iVar3 + 0x30);
    }
    uVar1 = *(uint *)(param_1 + 0x31bc);
    iVar3 = *(int *)(0x31b4 + param_1 + 4);
    if ((((*(char *)(param_1 + 0x31c9) != '\0') || (*(int *)(param_1 + 0x31b0) != 0)) ||
        (4 < *(int *)(param_1 + 0x31c4))) || ((uVar1 & 7) != 0)) {
      _gleEmptyImage(param_1,0x20,0x20,0x1900,0x1a00,param_1 + 0x3448,param_2);
      return;
    }
    iVar4 = 0x10;
    iVar2 = 0;
    do {
      *(undefined8 *)(iVar2 + param_2 + iVar3 * 4 + ((int)uVar1 >> 3)) =
           *(undefined8 *)(iVar2 + param_1 + 0x3448);
      iVar2 = iVar2 + 8;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
  }
  else {
LAB_00090dc0:
    if (*(int *)(param_1 + 0x7574) == 0) {
      *(undefined4 *)(param_1 + 0x7574) = 0x502;
    }
  }
  return;
}

/* _glSwap_RevertExec @ 0x90e9c (224 bytes) */
int _glSwap_RevertExec(param_1)
  int param_1;
{
  byte bVar1;
  undefined *puVar2;
  int iVar3;
  double fparam_1;
  double fparam_1_00;
  double in_f2;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  double in_stack_ffffffb8;
  double in_stack_ffffffc0;
  double in_stack_ffffffc8;
  double in_stack_ffffffd0;
  double in_stack_ffffffd8;
  
  bVar1 = *(byte *)(param_1 + 0x85a5);
  if (*(short *)(param_1 + 0x4a10) < 0) {
    _gleRevertSwapToPrimary(param_1);
    (**(code **)(param_1 + 0x46f8))(*(undefined4 *)(param_1 + 0x4688));
    iVar3 = (uint)bVar1 * 0x2e0 + param_1;
    (**(code **)(*(int *)(iVar3 + 0x8884) + 0x138))
              (*(undefined4 *)(iVar3 + 0x85ac),*(undefined4 *)(param_1 + 0x484c),
               *(undefined4 *)(param_1 + 0x4848),0);
    fparam_1 = (double)_gleSwitchToRenderer(param_1,(uint)bVar1);
    ((void (*)())_gleUpdateDepthRangeData)(param_1,fparam_1,in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8,in_stack_ffffffb8,
               in_stack_ffffffc0,in_stack_ffffffc8,in_stack_ffffffd0,in_stack_ffffffd8);
    _gleUpdatePolyMode(param_1);
    ((void (*)())_gleUpdateViewScissorData)(param_1,fparam_1_00,in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8);
    _gleUpdateTextureTransform(param_1);
    puVar2 = PTR__gleSetClipInterpFunc_00112038;
    *(undefined **)(param_1 + 0x49c8) = PTR__gleSetEyeInterpFunc_0011203c;
    *(undefined **)(param_1 + 0x49cc) = puVar2;
  }
  else if (*(int *)(param_1 + 0x7574) == 0) {
    *(undefined4 *)(param_1 + 0x7574) = 0x502;
  }
  return;
}

/* _glAreTexturesResident_Exec @ 0x90f7c (416 bytes) */
int _glAreTexturesResident_Exec(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  undefined4 *param_3;
  int param_4;
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = 1;
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if (param_2 < 0) {
      if (*(int *)(param_1 + 0x7574) != 0) {
        return 0;
      }
      uVar1 = 0x501;
    }
    else {
      if (param_2 == 0) {
        return 0;
      }
      iVar2 = _malloc(param_2);
      if (iVar2 != 0) {
        if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) != '\0') {
          _pthread_mutex_lock(*(int *)(param_1 + 0x5148) + 0x8028);
        }
        iVar5 = 0;
        if (0 < param_2) {
          do {
            uVar1 = *param_3;
            param_3 = param_3 + 1;
            iVar3 = _gleLookupHashObject(*(int *)(param_1 + 0x5148) + 0x2008,uVar1);
            if (iVar3 == 0) {
              if (*(int *)(param_1 + 0x7574) == 0) {
                *(undefined4 *)(param_1 + 0x7574) = 0x501;
              }
              iVar4 = 0;
              goto LAB_000910e0;
            }
            iVar3 = (**(code **)(param_1 + 0x47ac))
                              (*(undefined4 *)(param_1 + 0x4688),
                               *(undefined4 *)((uint)*(byte *)(param_1 + 0x85a8) * 4 + iVar3 + 0x10)
                              );
            if (iVar3 == 0) {
              iVar4 = 0;
              *(undefined1 *)(iVar2 + iVar5) = 0;
            }
            else {
              *(undefined1 *)(iVar2 + iVar5) = 1;
            }
            iVar5 = iVar5 + 1;
          } while (iVar5 < param_2);
          if ((iVar4 == 0) && (iVar5 = 0, 0 < param_2)) {
            do {
              *(undefined1 *)(param_4 + iVar5) = *(undefined1 *)(iVar2 + iVar5);
              iVar5 = iVar5 + 1;
            } while (iVar5 < param_2);
          }
        }
LAB_000910e0:
        _free(iVar2);
        if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) != '\0') {
          _pthread_mutex_unlock(*(int *)(param_1 + 0x5148) + 0x8028);
          return iVar4;
        }
        return iVar4;
      }
      if (*(int *)(param_1 + 0x7574) != 0) {
        return 0;
      }
      uVar1 = 0x505;
    }
  }
  else {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return 0;
    }
    uVar1 = 0x502;
  }
  *(undefined4 *)(param_1 + 0x7574) = uVar1;
  return 0;
}

/* _glIsTexture_Exec @ 0x9111c (168 bytes) */
int _glIsTexture_Exec(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  int iVar1;
  bool bVar2;
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    iVar1 = *(int *)(param_1 + 0x5148);
    if (*(char *)(iVar1 + 0x8024) != '\0') {
      _pthread_mutex_lock(iVar1 + 0x8028);
      iVar1 = *(int *)(param_1 + 0x5148);
    }
    iVar1 = _gleLookupHashObject(iVar1 + 0x2008,param_2);
    if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) != '\0') {
      _pthread_mutex_unlock(*(int *)(param_1 + 0x5148) + 0x8028);
    }
    bVar2 = iVar1 != 0;
  }
  else {
    if (*(int *)(param_1 + 0x7574) == 0) {
      *(undefined4 *)(param_1 + 0x7574) = 0x502;
    }
    bVar2 = false;
  }
  return bVar2;
}

/* _glBindTexture_ListExec @ 0x911c4 (44 bytes) */
int _glBindTexture_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  _glBindTexture_Exec(param_1,*param_2,param_2[1]);
  return 8;
}

/* _glBindTexture_Comp @ 0x911f0 (84 bytes) */
int _glBindTexture_Comp(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glBindTexture_ListExec_00110390,8);
  if (puVar1 != (undefined4 *)0x0) {
    puVar1[1] = param_3;
    *puVar1 = param_2;
  }
  return puVar1;
}

/* _glBindTexture_CompExec @ 0x91244 (64 bytes) */
int _glBindTexture_CompExec(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  ((int (*)())_glBindTexture_Comp)(param_1,param_2,param_3);
  _glBindTexture_Exec(param_1,param_2,param_3);
  return;
}

/* _glPrioritizeTextures_ListExec @ 0x91284 (72 bytes) */
int _glPrioritizeTextures_ListExec(param_1, param_2)
  undefined4 param_1;
  int *param_2;
{
  int iVar1;
  
  iVar1 = *param_2;
  _glPrioritizeTextures_Exec(param_1,iVar1,param_2 + 1,param_2 + iVar1 + 1);
  return iVar1 * 8 + 4;
}

/* _glPrioritizeTextures_Comp @ 0x912cc (144 bytes) */
int _glPrioritizeTextures_Comp(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  int param_2;
  int param_3;
  int param_4;
{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  piVar1 = (int *)_gleAddListItem(param_1,PTR__glPrioritizeTextures_ListExec_0011038c,
                                  param_2 * 8 + 4);
  if (piVar1 != (int *)0x0) {
    iVar2 = 0;
    *piVar1 = param_2;
    iVar3 = param_2;
    if (0 < param_2) {
      do {
        piVar1[iVar2 + 1] = *(int *)(param_3 + iVar2 * 4);
        piVar1[param_2 + iVar2 + 1] = *(int *)(param_4 + iVar2 * 4);
        iVar3 = iVar3 + -1;
        iVar2 = iVar2 + 1;
      } while (iVar3 != 0);
    }
  }
  return piVar1;
}

/* _glPrioritizeTextures_CompExec @ 0x9135c (72 bytes) */
int _glPrioritizeTextures_CompExec(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  ((int (*)())_glPrioritizeTextures_Comp)(param_1,param_2,param_3,param_4);
  _glPrioritizeTextures_Exec(param_1,param_2,param_3,param_4);
  return;
}

/* _glCompressedTexImage3D_ListExec @ 0x913a4 (96 bytes) */
int _glCompressedTexImage3D_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  ((int (*)())_glCompressedTexImage3D_Exec)(param_1,*param_2,param_2[1],param_2[2],param_2[3],param_2[4],param_2[5],param_2[6],
             param_2[7],param_2 + 8);
  return param_2[7] + 0x20;
}

/* _glCompressedTexImage2D_ListExec @ 0x91404 (88 bytes) */
int _glCompressedTexImage2D_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  ((int (*)())_glCompressedTexImage2D_Exec)(param_1,*param_2,param_2[1],param_2[2],param_2[3],param_2[4],param_2[5],param_2[6],
             param_2 + 7);
  return param_2[6] + 0x1c;
}

/* _glCompressedTexSubImage3D_ListExec @ 0x91464 (112 bytes) */
int _glCompressedTexSubImage3D_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  ((int (*)())_glCompressedTexSubImage3D_Exec)(param_1,*param_2,param_2[1],param_2[2],param_2[3],param_2[4],param_2[5],param_2[6],
             param_2[7],param_2[8],param_2[9],param_2 + 10);
  return param_2[9] + 0x28;
}

/* _glCompressedTexSubImage2D_ListExec @ 0x914d4 (96 bytes) */
int _glCompressedTexSubImage2D_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  ((int (*)())_glCompressedTexSubImage2D_Exec)(param_1,*param_2,param_2[1],param_2[2],param_2[3],param_2[4],param_2[5],param_2[6],
             param_2[7],param_2 + 8);
  return param_2[7] + 0x20;
}

/* _glCompressedTexImage3D_Comp @ 0x9153c (344 bytes) */
int _glCompressedTexImage3D_Comp(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10)
  int *param_1;
  int param_2;
  int param_3;
  uint param_4;
  int param_5;
  int param_6;
  int param_7;
  int param_8;
  int param_9;
  int param_10;
{
  undefined4 uVar1;
  int iVar2;
  
  if (param_2 == 0x8070) {
    uVar1 = ((int (*)())_glCompressedTexImage3D_Exec)(param_1,0x8070,param_3,param_4,param_5,param_6,param_7,param_8,param_9,
                       param_10);
    return uVar1;
  }
  if ((param_4 < 0x83f0) || (((0x83f3 < param_4 && (param_4 != 0x8837)) || (param_9 < 1)))) {
LAB_000915e4:
    if (param_1[0x1d5d] == 0) {
      param_1[0x1d5d] = 0x502;
    }
  }
  else {
    iVar2 = param_1[0x129b];
    if (iVar2 != 0) {
      if (*(int *)(iVar2 + 0x38) < param_9 + param_10) goto LAB_000915e4;
      if (*(int *)(iVar2 + 0x40) != 0) {
        _gleSynchronizePluginBuffer(param_1,iVar2 + 0x10);
      }
      param_10 = param_10 + *(int *)(iVar2 + 0x30);
    }
    param_1 = (int *)_gleAddListItem(param_1,PTR__glCompressedTexImage3D_ListExec_001103a0,
                                     param_9 + 0x20);
    if (param_1 != (int *)0x0) {
      *param_1 = param_2;
      param_1[1] = param_3;
      param_1[2] = param_4;
      param_1[6] = param_8;
      param_1[3] = param_5;
      param_1[4] = param_6;
      param_1[5] = param_7;
      param_1[7] = param_9;
      if (param_10 != 0) {
        uVar1 = _memcpy(param_1 + 8,param_10,param_9);
        return uVar1;
      }
    }
  }
  return param_1;
}

/* _glCompressedTexImage2D_Comp @ 0x91694 (404 bytes) */
int _glCompressedTexImage2D_Comp(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9)
  int *param_1;
  int param_2;
  int param_3;
  uint param_4;
  int param_5;
  int param_6;
  int param_7;
  int param_8;
  int param_9;
{
  undefined4 uVar1;
  int iVar2;
  
  if (((param_2 == 0x8064) || (param_2 == 0x851b)) || (param_2 == 0x84f7)) {
    uVar1 = ((int (*)())_glCompressedTexImage2D_Exec)(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9);
    return uVar1;
  }
  if (((param_4 < 0x83f0) || ((0x83f3 < param_4 && (param_4 != 0x8837)))) || (param_8 < 1)) {
LAB_0009177c:
    if (param_1[0x1d5d] == 0) {
      param_1[0x1d5d] = 0x502;
    }
  }
  else {
    iVar2 = param_1[0x129b];
    if (iVar2 != 0) {
      if (*(int *)(iVar2 + 0x38) < param_8 + param_9) goto LAB_0009177c;
      if (*(int *)(iVar2 + 0x40) != 0) {
        _gleSynchronizePluginBuffer(param_1,iVar2 + 0x10);
      }
      param_9 = param_9 + *(int *)(iVar2 + 0x30);
    }
    param_1 = (int *)_gleAddListItem(param_1,PTR__glCompressedTexImage2D_ListExec_0011039c,
                                     param_8 + 0x1c);
    if (param_1 != (int *)0x0) {
      *param_1 = param_2;
      param_1[1] = param_3;
      param_1[2] = param_4;
      param_1[5] = param_7;
      param_1[3] = param_5;
      param_1[4] = param_6;
      param_1[6] = param_8;
      if (param_9 != 0) {
        uVar1 = _memcpy(param_1 + 7,param_9,param_8);
        return uVar1;
      }
    }
  }
  return param_1;
}

/* _glCompressedTexImage1D_Comp @ 0x91828 (76 bytes) */
int _glCompressedTexImage1D_Comp(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  uint param_4;
{
  undefined4 uVar1;
  
  if ((param_4 < 0x83f0) || ((0x83f3 < param_4 && (param_4 != 0x8837)))) {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar1 = 0x502;
  }
  else {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar1 = 0x500;
  }
  *(undefined4 *)(param_1 + 0x7574) = uVar1;
  return;
}

/* _glCompressedTexSubImage3D_Comp @ 0x91874 (360 bytes) */
int _glCompressedTexSubImage3D_Comp(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12)
  int *param_1;
  int param_2;
  int param_3;
  int param_4;
  int param_5;
  int param_6;
  int param_7;
  int param_8;
  int param_9;
  uint param_10;
  int param_11;
  int param_12;
{
  undefined4 uVar1;
  int iVar2;
  
  if (param_2 == 0x8070) {
    uVar1 = ((int (*)())_glCompressedTexSubImage3D_Exec)(param_1,0x8070,param_3,param_4,param_5,param_6,param_7,param_8,param_9,
                       param_10,param_11,param_12);
    return uVar1;
  }
  if ((param_10 < 0x83f0) || (((0x83f3 < param_10 && (param_10 != 0x8837)) || (param_11 < 1)))) {
LAB_00091924:
    if (param_1[0x1d5d] == 0) {
      param_1[0x1d5d] = 0x502;
    }
  }
  else {
    iVar2 = param_1[0x129b];
    if (iVar2 != 0) {
      if (*(int *)(iVar2 + 0x38) < param_11 + param_12) goto LAB_00091924;
      if (*(int *)(iVar2 + 0x40) != 0) {
        _gleSynchronizePluginBuffer(param_1,iVar2 + 0x10);
      }
      param_12 = param_12 + *(int *)(iVar2 + 0x30);
    }
    param_1 = (int *)_gleAddListItem(param_1,PTR__glCompressedTexSubImage3D_ListExec_00110398,
                                     param_11 + 0x28);
    if (param_1 != (int *)0x0) {
      *param_1 = param_2;
      param_1[1] = param_3;
      param_1[8] = param_10;
      param_1[2] = param_4;
      param_1[3] = param_5;
      param_1[4] = param_6;
      param_1[5] = param_7;
      param_1[6] = param_8;
      param_1[7] = param_9;
      param_1[9] = param_11;
      if (param_12 != 0) {
        uVar1 = _memcpy(param_1 + 10,param_12,param_11);
        return uVar1;
      }
    }
  }
  return param_1;
}

/* _glCompressedTexSubImage2D_Comp @ 0x919dc (416 bytes) */
int _glCompressedTexSubImage2D_Comp(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10)
  int *param_1;
  int param_2;
  int param_3;
  int param_4;
  int param_5;
  int param_6;
  int param_7;
  uint param_8;
  int param_9;
  int param_10;
{
  undefined4 uVar1;
  int iVar2;
  
  if (((param_2 == 0x8064) || (param_2 == 0x851b)) || (param_2 == 0x84f7)) {
    uVar1 = ((int (*)())_glCompressedTexSubImage2D_Exec)(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,
                       param_10);
    return uVar1;
  }
  if (((param_8 < 0x83f0) || ((0x83f3 < param_8 && (param_8 != 0x8837)))) || (param_9 < 1)) {
LAB_00091acc:
    if (param_1[0x1d5d] == 0) {
      param_1[0x1d5d] = 0x502;
    }
  }
  else {
    iVar2 = param_1[0x129b];
    if (iVar2 != 0) {
      if (*(int *)(iVar2 + 0x38) < param_9 + param_10) goto LAB_00091acc;
      if (*(int *)(iVar2 + 0x40) != 0) {
        _gleSynchronizePluginBuffer(param_1,iVar2 + 0x10);
      }
      param_10 = param_10 + *(int *)(iVar2 + 0x30);
    }
    param_1 = (int *)_gleAddListItem(param_1,PTR__glCompressedTexSubImage2D_ListExec_00110394,
                                     param_9 + 0x20);
    if (param_1 != (int *)0x0) {
      *param_1 = param_2;
      param_1[1] = param_3;
      param_1[6] = param_8;
      param_1[2] = param_4;
      param_1[3] = param_5;
      param_1[4] = param_6;
      param_1[5] = param_7;
      param_1[7] = param_9;
      if (param_10 != 0) {
        uVar1 = _memcpy(param_1 + 8,param_10,param_9);
        return uVar1;
      }
    }
  }
  return param_1;
}

/* _glCompressedTexSubImage1D_Comp @ 0x91b7c (76 bytes) */
int _glCompressedTexSubImage1D_Comp(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  uint param_6;
{
  undefined4 uVar1;
  
  if ((param_6 < 0x83f0) || ((0x83f3 < param_6 && (param_6 != 0x8837)))) {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar1 = 0x502;
  }
  else {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar1 = 0x500;
  }
  *(undefined4 *)(param_1 + 0x7574) = uVar1;
  return;
}

/* _glCompressedTexImage3D_Exec @ 0x91bc8 (700 bytes) */
int _glCompressedTexImage3D_Exec(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10)
  int param_1;
  int param_2;
  int param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
  int param_9;
  int param_10;
{
  byte bVar1;
  ushort uVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  iVar5 = param_1;
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if ((param_10 == 0) && (*(char *)(param_1 + 0x31e6) != '\0')) {
      if (*(int *)(param_1 + 0x7574) != 0) {
        return param_1;
      }
      uVar3 = 0x501;
      goto LAB_00091ce0;
    }
    iVar6 = *(int *)(param_1 + 0x4a6c);
    if (iVar6 != 0) {
      if (*(int *)(iVar6 + 0x38) < param_9 + param_10) goto LAB_00091cd0;
      if (*(int *)(iVar6 + 0x40) != 0) {
        _gleSynchronizePluginBuffer(param_1,iVar6 + 0x10);
      }
      param_10 = param_10 + *(int *)(iVar6 + 0x30);
    }
    iVar5 = _gleCheckCompressedTexImage3DArgs
                      (param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9);
    if (iVar5 == 0) {
      return 0;
    }
    uVar2 = *(ushort *)(iVar5 + 0x24);
    if ((uVar2 & 0x3c00) == 0x1000) {
LAB_00091ce8:
      uVar4 = param_2 - 0x8515;
      if (5 < uVar4) {
        uVar4 = 0;
      }
      iVar6 = iVar5 + uVar4 * 0x168 + param_3 * 0x18;
      iVar7 = iVar6 + 0xc4;
      if ((*(byte *)(iVar6 + 0xcf) & 0x20) != 0) {
        _gleDeletePluginTextureLevel(param_1,iVar5,iVar7,uVar4,param_3);
        if (*(int *)(iVar6 + 0xd8) != 0) {
          bVar1 = *(byte *)(iVar6 + 0xcf);
          if ((bVar1 & 1) == 0) {
            _gleFreeTextureLevel(param_1,iVar5,iVar7);
            bVar1 = *(byte *)(iVar6 + 0xcf);
          }
          else {
            *(undefined4 *)(iVar6 + 0xd8) = 0;
          }
          *(byte *)(iVar6 + 0xcf) = bVar1 & 0xef;
        }
        *(byte *)(iVar6 + 0xcf) = *(byte *)(iVar6 + 0xcf) & 0xdf;
      }
      iVar6 = _gleCreateTextureLevel
                        (param_1,iVar5,iVar7,param_4,param_5,param_6,param_7,param_8,param_4,0,1,
                         param_10);
      if ((iVar6 != 0) && (param_10 != 0)) {
        _gleCompressedTextureImagePut
                  (param_1,iVar7,0,0,0,param_5,param_6,param_7,param_4,param_9,param_10);
      }
      uVar3 = _gleCreatePluginTextureLevel(param_1,iVar5,iVar7,uVar4,param_3,param_4);
      if ((((*(uint *)(iVar5 + 0x6c) & 0x8000) != 0) && (*(short *)(iVar5 + 0x60) == param_3)) &&
         (iVar5 = _gleGenMipmapsToLevel(param_1,iVar5,0,param_3,0xf,1), uVar3 = 0, iVar5 != 0)) {
        return iVar5;
      }
      *(uint *)(param_1 + 0x314) =
           *(uint *)(param_1 + 0x314) | 1 << (*(uint *)(param_1 + 0x53d4) & 0x3f);
      return uVar3;
    }
    if ((uVar2 & 0x3c00) == 0) {
      *(ushort *)(iVar5 + 0x24) = uVar2 | 0x1000;
      goto LAB_00091ce8;
    }
    if ((uVar2 & 0xc00) == 0) goto LAB_00091ce8;
  }
LAB_00091cd0:
  if (*(int *)(param_1 + 0x7574) != 0) {
    return iVar5;
  }
  uVar3 = 0x502;
LAB_00091ce0:
  *(undefined4 *)(param_1 + 0x7574) = uVar3;
  return iVar5;
}

/* _glCompressedTexImage2D_Exec @ 0x91e84 (692 bytes) */
int _glCompressedTexImage2D_Exec(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9)
  int param_1;
  int param_2;
  int param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  int param_8;
  int param_9;
{
  byte bVar1;
  ushort uVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if ((param_9 == 0) && (*(char *)(param_1 + 0x31e6) != '\0')) {
      if (*(int *)(param_1 + 0x7574) != 0) {
        return;
      }
      uVar3 = 0x501;
      goto LAB_00091f94;
    }
    iVar6 = *(int *)(param_1 + 0x4a6c);
    if (iVar6 != 0) {
      if (*(int *)(iVar6 + 0x38) < param_8 + param_9) goto LAB_00091f84;
      if (*(int *)(iVar6 + 0x40) != 0) {
        _gleSynchronizePluginBuffer(param_1,iVar6 + 0x10);
      }
      param_9 = param_9 + *(int *)(iVar6 + 0x30);
    }
    iVar6 = _gleCheckCompressedTexImage2DArgs
                      (param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
    if (iVar6 == 0) {
      return;
    }
    uVar2 = *(ushort *)(iVar6 + 0x24);
    if ((uVar2 & 0x3c00) == 0x1000) {
LAB_00091f9c:
      uVar4 = param_2 - 0x8515;
      if (5 < uVar4) {
        uVar4 = 0;
      }
      iVar5 = iVar6 + uVar4 * 0x168 + param_3 * 0x18;
      iVar7 = iVar5 + 0xc4;
      if ((*(byte *)(iVar5 + 0xcf) & 0x20) != 0) {
        _gleDeletePluginTextureLevel(param_1,iVar6,iVar7,uVar4,param_3);
        if (*(int *)(iVar5 + 0xd8) != 0) {
          bVar1 = *(byte *)(iVar5 + 0xcf);
          if ((bVar1 & 1) == 0) {
            _gleFreeTextureLevel(param_1,iVar6,iVar7);
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
                        (param_1,iVar6,iVar7,param_4,param_5,param_6,1,param_7,param_4,0,1,param_9);
      if ((iVar5 != 0) && (param_9 != 0)) {
        _gleCompressedTextureImagePut(param_1,iVar7,0,0,0,param_5,param_6,1,param_4,param_8,param_9)
        ;
      }
      _gleCreatePluginTextureLevel(param_1,iVar6,iVar7,uVar4,param_3,param_4);
      if ((((*(uint *)(iVar6 + 0x6c) & 0x8000) != 0) && (*(short *)(iVar6 + 0x60) == param_3)) &&
         (iVar6 = _gleGenMipmapsToLevel(param_1,iVar6,uVar4,param_3,0xf,1), iVar6 != 0)) {
        return;
      }
      *(uint *)(param_1 + 0x314) =
           *(uint *)(param_1 + 0x314) | 1 << (*(uint *)(param_1 + 0x53d4) & 0x3f);
      return;
    }
    if ((uVar2 & 0x3c00) == 0) {
      *(ushort *)(iVar6 + 0x24) = uVar2 | 0x1000;
      goto LAB_00091f9c;
    }
    if ((uVar2 & 0xc00) == 0) goto LAB_00091f9c;
  }
LAB_00091f84:
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  uVar3 = 0x502;
LAB_00091f94:
  *(undefined4 *)(param_1 + 0x7574) = uVar3;
  return;
}

/* _glCompressedTexImage1D_Exec @ 0x92138 (76 bytes) */
int _glCompressedTexImage1D_Exec(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  uint param_4;
{
  undefined4 uVar1;
  
  if ((param_4 < 0x83f0) || ((0x83f3 < param_4 && (param_4 != 0x8837)))) {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar1 = 0x502;
  }
  else {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar1 = 0x500;
  }
  *(undefined4 *)(param_1 + 0x7574) = uVar1;
  return;
}

/* _glCompressedTexSubImage3D_Exec @ 0x92184 (1464 bytes) */
int _glCompressedTexSubImage3D_Exec(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12)
  int param_1;
  undefined4 param_2;
  uint param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  int param_7;
  int param_8;
  undefined4 param_9;
  undefined4 param_10;
  int param_11;
  int param_12;
{
  int iVar1;
  int iVar2;
  int iVar3;
  byte bVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  
  iVar3 = param_1;
  if (*(short *)(param_1 + 0x4a10) < 0) {
    iVar7 = *(int *)(param_1 + 0x4a6c);
    if (iVar7 != 0) {
      if (*(int *)(iVar7 + 0x38) < param_11 + param_12) goto LAB_000921f0;
      param_12 = param_12 + *(int *)(iVar7 + 0x30);
    }
    if ((param_7 != 0) && (param_8 != 0)) {
      iVar2 = _gleCheckCompressedTexSubImage3DArgs
                        (param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,
                         param_10,param_11);
      iVar3 = 0;
      if (iVar2 != 0) {
        iVar1 = iVar2 + param_3 * 0x18;
        iVar5 = iVar1 + 0xc4;
        if (iVar7 != 0) {
          if (((((int)(uint)*(byte *)(iVar2 + 0x8d) <= (int)param_3) &&
               ((int)param_3 <= (int)(uint)*(byte *)(iVar2 + 0x8f))) &&
              ((*(ushort *)(iVar2 + 0x94) >> (param_3 & 0x3f) & 1) != 0)) &&
             (iVar3 = (**(code **)(param_1 + 0x4710))
                                (*(undefined4 *)(param_1 + 0x4688),
                                 *(undefined4 *)(iVar2 + (uint)*(byte *)(param_1 + 0x85a8) * 4),0,
                                 param_3,param_4,param_5,param_6,param_7), iVar3 != 0)) {
            *(undefined4 *)(iVar2 + 0x20) =
                 *(undefined4 *)
                  ((uint)*(byte *)(param_1 + 0x85a8) * 4 + *(int *)(param_1 + 0x5148) + 0x8054);
            if (*(int *)(iVar1 + 0xd8) != 0) {
              bVar4 = *(byte *)(iVar1 + 0xcf);
              if (((bVar4 & 1) == 0) && (*(short *)(iVar2 + 0x3e) == -0x7a43)) {
                iVar3 = _gleFreeTextureLevel(param_1,iVar2,iVar5);
                bVar4 = *(byte *)(iVar1 + 0xcf);
              }
              *(byte *)(iVar1 + 0xcf) = bVar4 & 0xef;
              *(ushort *)(iVar2 + 0xa0) =
                   *(ushort *)(iVar2 + 0xa0) &
                   ((ushort)(-2 << (param_3 & 0x1f)) |
                   (ushort)(0xfffffffe >> 0x20 - (param_3 & 0x1f)));
            }
            *(byte *)(iVar1 + 0xcf) = *(byte *)(iVar1 + 0xcf) | 0x40;
            if ((*(uint *)(iVar2 + 0x6c) & 0x8000) == 0) {
              return iVar3;
            }
            if ((int)*(short *)(iVar2 + 0x60) != param_3) {
              return iVar3;
            }
            uVar6 = param_3 + 1;
            if ((int)(uint)*(byte *)(iVar2 + 0x83) < (int)uVar6) {
              return iVar3;
            }
            iVar7 = uVar6 * 0x18 + iVar2 + 0xc4;
            do {
              if (*(int *)(iVar7 + 0x14) != 0) {
                if (((*(byte *)(iVar7 + 0xb) & 1) == 0) && (*(short *)(iVar2 + 0x3e) == -0x7a43)) {
                  iVar3 = _gleFreeTextureLevel(param_1,iVar2,iVar7);
                }
                *(byte *)(iVar7 + 0xb) = *(byte *)(iVar7 + 0xb) & 0xef;
                *(ushort *)(iVar2 + 0xa0) =
                     *(ushort *)(iVar2 + 0xa0) & ~(ushort)(1 << (uVar6 & 0x3f));
              }
              uVar6 = uVar6 + 1;
              *(byte *)(iVar7 + 0xb) = *(byte *)(iVar7 + 0xb) | 0x40;
              iVar7 = iVar7 + 0x18;
            } while ((int)uVar6 <= (int)(uint)*(byte *)(iVar2 + 0x83));
            return iVar3;
          }
          if (*(int *)(iVar7 + 0x40) != 0) {
            _gleSynchronizePluginBuffer(param_1,iVar7 + 0x10);
          }
        }
        if (((((int)param_3 < (int)(uint)*(byte *)(iVar2 + 0x8d)) ||
             ((int)(uint)*(byte *)(iVar2 + 0x8f) < (int)param_3)) ||
            ((*(ushort *)(iVar2 + 0x94) >> (param_3 & 0x3f) & 1) == 0)) ||
           (iVar3 = (**(code **)(param_1 + 0x4710))
                              (*(undefined4 *)(param_1 + 0x4688),
                               *(undefined4 *)(iVar2 + (uint)*(byte *)(param_1 + 0x85a8) * 4),0,
                               param_3,param_4,param_5,param_6,param_7), iVar3 == 0)) {
          bVar4 = *(byte *)(iVar1 + 0xcf);
          if ((bVar4 & 0x10) == 0) {
            if ((bVar4 & 0x40) == 0) {
              if (*(int *)(iVar1 + 0xd8) == 0) {
                _gleAllocateTextureLevel(param_1,iVar2,iVar5);
                bVar4 = *(byte *)(iVar1 + 0xcf);
              }
              *(byte *)(iVar1 + 0xcf) = bVar4 | 0x10;
            }
            else {
              _gleUploadPluginTextureLevel
                        (param_1,iVar2,iVar5,0,param_3,(uint)*(byte *)(param_1 + 0x85a8));
            }
          }
          iVar3 = _gleModifyPluginTextureLevel
                            (param_1,iVar2,iVar5,0,param_3,param_4,param_5,param_6,param_7);
          if (param_12 != 0) {
            iVar3 = _gleCompressedTextureImagePut
                              (param_1,iVar5,param_4,param_5,param_6,param_7,param_8,param_9,
                               param_10,param_11,param_12);
          }
          if ((((*(uint *)(iVar2 + 0x6c) & 0x8000) == 0) ||
              ((int)*(short *)(iVar2 + 0x60) != param_3)) ||
             (iVar3 = _gleGenMipmapsToLevel(param_1,iVar2,0,param_3,0xf,1), iVar3 == 0)) {
            *(uint *)(param_1 + 0x314) =
                 *(uint *)(param_1 + 0x314) | 1 << (*(uint *)(param_1 + 0x53d4) & 0x3f);
          }
        }
        else {
          *(undefined4 *)(iVar2 + 0x20) =
               *(undefined4 *)
                ((uint)*(byte *)(param_1 + 0x85a8) * 4 + *(int *)(param_1 + 0x5148) + 0x8054);
          if (*(int *)(iVar1 + 0xd8) != 0) {
            bVar4 = *(byte *)(iVar1 + 0xcf);
            if (((bVar4 & 1) == 0) && (*(short *)(iVar2 + 0x3e) == -0x7a43)) {
              iVar3 = _gleFreeTextureLevel(param_1,iVar2,iVar5);
              bVar4 = *(byte *)(iVar1 + 0xcf);
            }
            *(byte *)(iVar1 + 0xcf) = bVar4 & 0xef;
            *(ushort *)(iVar2 + 0xa0) =
                 *(ushort *)(iVar2 + 0xa0) &
                 ((ushort)(-2 << (param_3 & 0x1f)) | (ushort)(0xfffffffe >> 0x20 - (param_3 & 0x1f))
                 );
          }
          *(byte *)(iVar1 + 0xcf) = *(byte *)(iVar1 + 0xcf) | 0x40;
          if ((((*(uint *)(iVar2 + 0x6c) & 0x8000) != 0) &&
              ((int)*(short *)(iVar2 + 0x60) == param_3)) &&
             (uVar6 = param_3 + 1, (int)uVar6 <= (int)(uint)*(byte *)(iVar2 + 0x83))) {
            iVar7 = uVar6 * 0x18 + iVar2 + 0xc4;
            do {
              if (*(int *)(iVar7 + 0x14) != 0) {
                if (((*(byte *)(iVar7 + 0xb) & 1) == 0) && (*(short *)(iVar2 + 0x3e) == -0x7a43)) {
                  iVar3 = _gleFreeTextureLevel(param_1,iVar2,iVar7);
                }
                *(byte *)(iVar7 + 0xb) = *(byte *)(iVar7 + 0xb) & 0xef;
                *(ushort *)(iVar2 + 0xa0) =
                     *(ushort *)(iVar2 + 0xa0) & ~(ushort)(1 << (uVar6 & 0x3f));
              }
              uVar6 = uVar6 + 1;
              *(byte *)(iVar7 + 0xb) = *(byte *)(iVar7 + 0xb) | 0x40;
              iVar7 = iVar7 + 0x18;
            } while ((int)uVar6 <= (int)(uint)*(byte *)(iVar2 + 0x83));
          }
        }
      }
    }
  }
  else {
LAB_000921f0:
    if (*(int *)(param_1 + 0x7574) == 0) {
      *(undefined4 *)(param_1 + 0x7574) = 0x502;
    }
  }
  return iVar3;
}

/* _glCompressedTexSubImage2D_Exec @ 0x9273c (1552 bytes) */
int _glCompressedTexSubImage2D_Exec(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10)
  int param_1;
  int param_2;
  uint param_3;
  undefined4 param_4;
  undefined4 param_5;
  int param_6;
  int param_7;
  undefined4 param_8;
  int param_9;
  int param_10;
{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  byte bVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    iVar9 = *(int *)(param_1 + 0x4a6c);
    if (iVar9 != 0) {
      if (*(int *)(iVar9 + 0x38) < param_9 + param_10) goto LAB_000927a4;
      param_10 = param_10 + *(int *)(iVar9 + 0x30);
    }
    if (((param_6 != 0) && (param_7 != 0)) &&
       (iVar3 = _gleCheckCompressedTexSubImage2DArgs
                          (param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9),
       iVar3 != 0)) {
      uVar1 = param_2 - 0x8515;
      if (5 < uVar1) {
        uVar1 = 0;
      }
      iVar7 = uVar1 * 0x168;
      iVar2 = iVar3 + iVar7 + param_3 * 0x18;
      iVar8 = iVar2 + 0xc4;
      if (iVar9 != 0) {
        if ((((int)(uint)*(byte *)(iVar3 + 0x8d) <= (int)param_3) &&
            ((int)param_3 <= (int)(uint)*(byte *)(iVar3 + 0x8f))) &&
           ((iVar5 = uVar1 * 2, (*(ushort *)(iVar5 + iVar3 + 0x94) >> (param_3 & 0x3f) & 1) != 0 &&
            (iVar4 = (**(code **)(param_1 + 0x4710))
                               (*(undefined4 *)(param_1 + 0x4688),
                                *(undefined4 *)(iVar3 + (uint)*(byte *)(param_1 + 0x85a8) * 4),uVar1
                                ,param_3,param_4,param_5,0,param_6), iVar4 != 0)))) {
          *(undefined4 *)(iVar3 + 0x20) =
               *(undefined4 *)
                ((uint)*(byte *)(param_1 + 0x85a8) * 4 + *(int *)(param_1 + 0x5148) + 0x8054);
          if (*(int *)(iVar2 + 0xd8) != 0) {
            bVar6 = *(byte *)(iVar2 + 0xcf);
            if (((bVar6 & 1) == 0) && (*(short *)(iVar3 + 0x3e) == -0x7a43)) {
              _gleFreeTextureLevel(param_1,iVar3,iVar8);
              bVar6 = *(byte *)(iVar2 + 0xcf);
            }
            *(byte *)(iVar2 + 0xcf) = bVar6 & 0xef;
            *(ushort *)(iVar5 + iVar3 + 0xa0) =
                 *(ushort *)(iVar5 + iVar3 + 0xa0) &
                 ((ushort)(-2 << (param_3 & 0x1f)) | (ushort)(0xfffffffe >> 0x20 - (param_3 & 0x1f))
                 );
          }
          *(byte *)(iVar2 + 0xcf) = *(byte *)(iVar2 + 0xcf) | 0x40;
          if ((*(uint *)(iVar3 + 0x6c) & 0x8000) == 0) {
            return;
          }
          if ((int)*(short *)(iVar3 + 0x60) != param_3) {
            return;
          }
          uVar1 = param_3 + 1;
          if ((int)(uint)*(byte *)(iVar3 + 0x83) < (int)uVar1) {
            return;
          }
          iVar9 = uVar1 * 0x18 + iVar7 + iVar3 + 0xc4;
          do {
            if (*(int *)(iVar9 + 0x14) != 0) {
              if (((*(byte *)(iVar9 + 0xb) & 1) == 0) && (*(short *)(iVar3 + 0x3e) == -0x7a43)) {
                _gleFreeTextureLevel(param_1,iVar3,iVar9);
              }
              *(byte *)(iVar9 + 0xb) = *(byte *)(iVar9 + 0xb) & 0xef;
              *(ushort *)(iVar5 + iVar3 + 0xa0) =
                   *(ushort *)(iVar5 + iVar3 + 0xa0) & ~(ushort)(1 << (uVar1 & 0x3f));
            }
            uVar1 = uVar1 + 1;
            *(byte *)(iVar9 + 0xb) = *(byte *)(iVar9 + 0xb) | 0x40;
            iVar9 = iVar9 + 0x18;
          } while ((int)uVar1 <= (int)(uint)*(byte *)(iVar3 + 0x83));
          return;
        }
        if (*(int *)(iVar9 + 0x40) != 0) {
          _gleSynchronizePluginBuffer(param_1,iVar9 + 0x10);
        }
      }
      if (((((int)param_3 < (int)(uint)*(byte *)(iVar3 + 0x8d)) ||
           ((int)(uint)*(byte *)(iVar3 + 0x8f) < (int)param_3)) ||
          (iVar9 = uVar1 * 2, (*(ushort *)(iVar9 + iVar3 + 0x94) >> (param_3 & 0x3f) & 1) == 0)) ||
         (iVar5 = (**(code **)(param_1 + 0x4710))
                            (*(undefined4 *)(param_1 + 0x4688),
                             *(undefined4 *)(iVar3 + (uint)*(byte *)(param_1 + 0x85a8) * 4),uVar1,
                             param_3,param_4,param_5,0,param_6), iVar5 == 0)) {
        bVar6 = *(byte *)(iVar2 + 0xcf);
        if ((bVar6 & 0x10) == 0) {
          if ((bVar6 & 0x40) == 0) {
            if (*(int *)(iVar2 + 0xd8) == 0) {
              _gleAllocateTextureLevel(param_1,iVar3,iVar8);
              bVar6 = *(byte *)(iVar2 + 0xcf);
            }
            *(byte *)(iVar2 + 0xcf) = bVar6 | 0x10;
          }
          else {
            _gleUploadPluginTextureLevel
                      (param_1,iVar3,iVar8,uVar1,param_3,(uint)*(byte *)(param_1 + 0x85a8));
          }
        }
        _gleModifyPluginTextureLevel(param_1,iVar3,iVar8,uVar1,param_3,param_4,param_5,0,param_6);
        if (param_10 != 0) {
          _gleCompressedTextureImagePut
                    (param_1,iVar8,param_4,param_5,0,param_6,param_7,1,param_8,param_9,param_10);
        }
        if ((((*(uint *)(iVar3 + 0x6c) & 0x8000) == 0) || ((int)*(short *)(iVar3 + 0x60) != param_3)
            ) || (iVar9 = _gleGenMipmapsToLevel(param_1,iVar3,uVar1,param_3,0xf,1), iVar9 == 0)) {
          *(uint *)(param_1 + 0x314) =
               *(uint *)(param_1 + 0x314) | 1 << (*(uint *)(param_1 + 0x53d4) & 0x3f);
        }
      }
      else {
        *(undefined4 *)(iVar3 + 0x20) =
             *(undefined4 *)
              ((uint)*(byte *)(param_1 + 0x85a8) * 4 + *(int *)(param_1 + 0x5148) + 0x8054);
        if (*(int *)(iVar2 + 0xd8) != 0) {
          bVar6 = *(byte *)(iVar2 + 0xcf);
          if (((bVar6 & 1) == 0) && (*(short *)(iVar3 + 0x3e) == -0x7a43)) {
            _gleFreeTextureLevel(param_1,iVar3,iVar8);
            bVar6 = *(byte *)(iVar2 + 0xcf);
          }
          *(byte *)(iVar2 + 0xcf) = bVar6 & 0xef;
          *(ushort *)(iVar9 + iVar3 + 0xa0) =
               *(ushort *)(iVar9 + iVar3 + 0xa0) &
               ((ushort)(-2 << (param_3 & 0x1f)) | (ushort)(0xfffffffe >> 0x20 - (param_3 & 0x1f)));
        }
        *(byte *)(iVar2 + 0xcf) = *(byte *)(iVar2 + 0xcf) | 0x40;
        if ((((*(uint *)(iVar3 + 0x6c) & 0x8000) != 0) && ((int)*(short *)(iVar3 + 0x60) == param_3)
            ) && (uVar1 = param_3 + 1, (int)uVar1 <= (int)(uint)*(byte *)(iVar3 + 0x83))) {
          iVar2 = uVar1 * 0x18 + iVar7 + iVar3 + 0xc4;
          do {
            if (*(int *)(iVar2 + 0x14) != 0) {
              if (((*(byte *)(iVar2 + 0xb) & 1) == 0) && (*(short *)(iVar3 + 0x3e) == -0x7a43)) {
                _gleFreeTextureLevel(param_1,iVar3,iVar2);
              }
              *(byte *)(iVar2 + 0xb) = *(byte *)(iVar2 + 0xb) & 0xef;
              *(ushort *)(iVar9 + iVar3 + 0xa0) =
                   *(ushort *)(iVar9 + iVar3 + 0xa0) & ~(ushort)(1 << (uVar1 & 0x3f));
            }
            uVar1 = uVar1 + 1;
            *(byte *)(iVar2 + 0xb) = *(byte *)(iVar2 + 0xb) | 0x40;
            iVar2 = iVar2 + 0x18;
          } while ((int)uVar1 <= (int)(uint)*(byte *)(iVar3 + 0x83));
        }
      }
    }
  }
  else {
LAB_000927a4:
    if (*(int *)(param_1 + 0x7574) == 0) {
      *(undefined4 *)(param_1 + 0x7574) = 0x502;
    }
  }
  return;
}

/* _glCompressedTexSubImage1D_Exec @ 0x92d4c (76 bytes) */
int _glCompressedTexSubImage1D_Exec(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  uint param_6;
{
  undefined4 uVar1;
  
  if ((param_6 < 0x83f0) || ((0x83f3 < param_6 && (param_6 != 0x8837)))) {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar1 = 0x502;
  }
  else {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar1 = 0x500;
  }
  *(undefined4 *)(param_1 + 0x7574) = uVar1;
  return;
}

/* _glGetCompressedTexImage_Exec @ 0x92d98 (660 bytes) */
int _glGetCompressedTexImage_Exec(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  uint param_3;
  int param_4;
{
  byte bVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined1 *puVar8;
  int *piVar9;
  int iVar10;
  int iVar11;
  undefined4 local_c0;
  undefined4 local_bc;
  undefined4 local_b8;
  undefined4 local_b4;
  int local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  uint local_9c;
  undefined4 local_98;
  uint local_94;
  uint local_90;
  undefined1 local_54;
  undefined4 local_50;
  undefined1 auStack_4c [4];
  int local_48;
  undefined1 auStack_44 [4];
  undefined1 auStack_40 [4];
  int local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c [4];
  
  iVar5 = _gleLookUpNonProxyTexture(param_1,param_2);
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if (iVar5 == 0) {
      if (*(int *)(param_1 + 0x7574) != 0) {
        return;
      }
      uVar2 = 0x500;
      goto LAB_00092efc;
    }
    if (0xe < param_3) {
      if (*(int *)(param_1 + 0x7574) != 0) {
        return;
      }
      uVar2 = 0x501;
      goto LAB_00092efc;
    }
    uVar3 = param_2 - 0x8515;
    if (5 < uVar3) {
      uVar3 = 0;
    }
    iVar4 = iVar5 + uVar3 * 0x168 + param_3 * 0x18;
    bVar1 = *(byte *)(iVar4 + 0xcf);
    if ((bVar1 & 0x20) == 0) {
      return;
    }
    if ((((int)param_3 < (int)(uint)*(byte *)(iVar5 + 0x8d)) ||
        ((int)(uint)*(byte *)(iVar5 + 0x8f) < (int)param_3)) || ((bVar1 & 0x40) == 0)) {
      if ((bVar1 & 0x10) == 0) {
        return;
      }
    }
    else {
      _gleUploadPluginTextureLevel
                (param_1,iVar5,iVar4 + 0xc4,uVar3,param_3,(uint)*(byte *)(param_1 + 0x85a8));
    }
    uVar3 = (uint)*(ushort *)(iVar4 + 0xca);
    iVar10 = param_1 + 0x31b0;
    puVar8 = auStack_40;
    piVar9 = &local_3c;
    _glePixelPackSettings
              (param_1,(uint)*(ushort *)(iVar5 + 0x78),0,(uint)*(ushort *)(iVar4 + 200),uVar3,iVar10
               ,puVar8,piVar9,&local_50,auStack_4c,&local_48,auStack_44);
    iVar11 = *(int *)(param_1 + 0x4a68);
    if (iVar11 == 0) {
LAB_00092f24:
      if ((((*(byte *)(iVar4 + 0xcf) & 1) != 0) && (param_4 + local_3c == *(int *)(iVar4 + 0xd8)))
         && (*(short *)(iVar4 + 0xd6) == 0)) {
        return;
      }
      local_9c = (uint)(*(char *)(param_1 + 0x31c8) != '\0');
      uVar2 = _gleRowBytes((uint)*(ushort *)(iVar4 + 0xd4),(uint)*(ushort *)(iVar4 + 0xd6),
                           (uint)*(ushort *)(iVar4 + 0xd0));
      _glgConvertType((uint)*(ushort *)(iVar4 + 0xd4),(uint)*(ushort *)(iVar4 + 0xd6),&local_38,
                      &local_34,uVar3,iVar10,puVar8,piVar9);
      puVar6 = &local_30;
      puVar7 = local_2c;
      _glgConvertType((uint)*(ushort *)(iVar5 + 0x78),0,puVar6,puVar7,uVar3,iVar10,puVar8,piVar9);
      local_b8 = local_38;
      local_b4 = local_34;
      local_ac = local_50;
      local_a8 = local_30;
      local_a4 = local_2c[0];
      local_98 = 1;
      local_a0 = 2;
      local_94 = (uint)*(ushort *)(iVar4 + 200);
      local_90 = (uint)*(ushort *)(iVar4 + 0xca);
      local_b0 = param_4 + local_3c;
      local_c0 = *(undefined4 *)(iVar4 + 0xd8);
      local_54 = 0;
      local_bc = uVar2;
      _glgProcessPixels(param_1 + 0x31a8,&local_c0,puVar6,puVar7,uVar3,iVar10,local_90,piVar9);
      return;
    }
    if (local_48 + param_4 <= *(int *)(iVar11 + 0x38)) {
      if (*(int *)(iVar11 + 0x40) != 0) {
        _gleSynchronizePluginBuffer(param_1,iVar11 + 0x10);
      }
      param_4 = param_4 + *(int *)(iVar11 + 0x30);
      goto LAB_00092f24;
    }
  }
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  uVar2 = 0x502;
LAB_00092efc:
  *(undefined4 *)(param_1 + 0x7574) = uVar2;
  return;
}

/* _glCompressedTexImage3D_CompExec @ 0x9302c (128 bytes) */
int _glCompressedTexImage3D_CompExec(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10)
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
  ((int (*)())_glCompressedTexImage3D_Comp)(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,param_10);
  ((int (*)())_glCompressedTexImage3D_Exec)(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,param_10);
  return;
}

/* _glCompressedTexImage2D_CompExec @ 0x930ac (116 bytes) */
int _glCompressedTexImage2D_CompExec(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9)
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
  ((int (*)())_glCompressedTexImage2D_Comp)(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9);
  ((int (*)())_glCompressedTexImage2D_Exec)(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9);
  return;
}

/* _glCompressedTexImage1D_CompExec @ 0x93120 (104 bytes) */
int _glCompressedTexImage1D_CompExec(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  ((int (*)())_glCompressedTexImage1D_Comp)(param_1,param_2,param_3,param_4);
  ((int (*)())_glCompressedTexImage1D_Exec)(param_1,param_2,param_3,param_4);
  return;
}

/* _glCompressedTexSubImage3D_CompExec @ 0x93188 (152 bytes) */
int _glCompressedTexSubImage3D_CompExec(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12)
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
  undefined4 param_11;
  undefined4 param_12;
{
  ((int (*)())_glCompressedTexSubImage3D_Comp)(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,param_10,
             param_11,param_12);
  ((int (*)())_glCompressedTexSubImage3D_Exec)(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,param_10,
             param_11,param_12);
  return;
}

/* _glCompressedTexSubImage2D_CompExec @ 0x93220 (128 bytes) */
int _glCompressedTexSubImage2D_CompExec(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10)
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
  ((int (*)())_glCompressedTexSubImage2D_Comp)(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,param_10);
  ((int (*)())_glCompressedTexSubImage2D_Exec)(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,param_10);
  return;
}

/* _glCompressedTexSubImage1D_CompExec @ 0x932a0 (104 bytes) */
int _glCompressedTexSubImage1D_CompExec(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  ((int (*)())_glCompressedTexSubImage1D_Comp)(param_1,param_2,param_3,param_4,param_5,param_6);
  ((int (*)())_glCompressedTexSubImage1D_Exec)(param_1,param_2,param_3,param_4,param_5,param_6);
  return;
}

/* _glTexCoord1_ListExec @ 0x93308 (36 bytes) */
int _glTexCoord1_ListExec(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  *(undefined4 *)(param_1 + 0x120) = *param_2;
  *(undefined4 *)(param_1 + 300) = *(undefined4 *)(param_1 + 0x24);
  *(undefined4 *)(param_1 + 0x128) = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)(param_1 + 0x124) = *(undefined4 *)(param_1 + 0x20);
  return 4;
}

/* _glTexCoord3_ListExec @ 0x9332c (52 bytes) */
int _glTexCoord3_ListExec(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  uVar1 = param_2[2];
  uVar2 = *param_2;
  uVar3 = param_2[1];
  *(uint *)(param_1 + 0x486c) = *(uint *)(param_1 + 0x486c) | 1;
  *(undefined4 *)(param_1 + 0x120) = uVar2;
  *(undefined4 *)(param_1 + 0x124) = uVar3;
  *(undefined4 *)(param_1 + 0x128) = uVar1;
  *(undefined4 *)(param_1 + 300) = *(undefined4 *)(param_1 + 0x24);
  return 0xc;
}

/* _glTexCoord4_ListExec @ 0x93360 (52 bytes) */
int _glTexCoord4_ListExec(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  uVar1 = param_2[3];
  uVar2 = param_2[1];
  uVar3 = param_2[2];
  *(undefined4 *)(param_1 + 0x120) = *param_2;
  *(uint *)(param_1 + 0x486c) = *(uint *)(param_1 + 0x486c) | 3;
  *(undefined4 *)(param_1 + 0x124) = uVar2;
  *(undefined4 *)(param_1 + 0x128) = uVar3;
  *(undefined4 *)(param_1 + 300) = uVar1;
  return 0x10;
}

/* _glTexCoord1d_Exec @ 0x93394 (32 bytes) */
void _glTexCoord1d_Exec(int param_1,double fparam_1)
{
  *(undefined4 *)(param_1 + 0x128) = *(undefined4 *)(param_1 + 0x20);
  *(float *)(param_1 + 0x120) = (float)fparam_1;
  *(undefined4 *)(param_1 + 300) = *(undefined4 *)(param_1 + 0x24);
  *(undefined4 *)(param_1 + 0x124) = *(undefined4 *)(param_1 + 0x20);
  return;
}

/* _glTexCoord1d_Comp @ 0x933b4 (88 bytes) */
float * _glTexCoord1d_Comp(undefined4 param_1,double fparam_1)
{
  float *pfVar1;
  
  pfVar1 = (float *)_gleAddListItem(param_1,PTR__glTexCoord1_ListExec_001103c0,4);
  if (pfVar1 != (float *)0x0) {
    *pfVar1 = (float)fparam_1;
  }
  return pfVar1;
}

/* _glTexCoord1d_CompExec @ 0x9340c (64 bytes) */
void _glTexCoord1d_CompExec(undefined4 param_1,double fparam_1)
{
  ((float * (*)())_glTexCoord1d_Comp)(param_1,fparam_1);
  ((void (*)())_glTexCoord1d_Exec)(param_1,fparam_1);
  return;
}

/* _glTexCoord1dv_Exec @ 0x9344c (36 bytes) */
int _glTexCoord1dv_Exec(param_1, param_2)
  int param_1;
  double *param_2;
{
  double dVar1;
  
  dVar1 = *param_2;
  *(undefined4 *)(param_1 + 0x128) = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)(param_1 + 300) = *(undefined4 *)(param_1 + 0x24);
  *(float *)(param_1 + 0x120) = (float)dVar1;
  *(undefined4 *)(param_1 + 0x124) = *(undefined4 *)(param_1 + 0x20);
  return;
}

/* _glTexCoord1dv_Comp @ 0x93470 (84 bytes) */
int _glTexCoord1dv_Comp(param_1, param_2)
  undefined4 param_1;
  double *param_2;
{
  float *pfVar1;
  
  pfVar1 = (float *)_gleAddListItem(param_1,PTR__glTexCoord1_ListExec_001103c0,4);
  if (pfVar1 != (float *)0x0) {
    *pfVar1 = (float)*param_2;
  }
  return pfVar1;
}

/* _glTexCoord1dv_CompExec @ 0x934c4 (56 bytes) */
int _glTexCoord1dv_CompExec(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  ((int (*)())_glTexCoord1dv_Comp)(param_1,param_2);
  ((int (*)())_glTexCoord1dv_Exec)(param_1,param_2);
  return;
}

/* _glTexCoord2d_Exec @ 0x934fc (36 bytes) */
void _glTexCoord2d_Exec(int param_1,double fparam_1,double fparam_2)
{
  *(undefined4 *)(param_1 + 0x128) = *(undefined4 *)(param_1 + 0x20);
  *(float *)(param_1 + 0x120) = (float)fparam_1;
  *(undefined4 *)(param_1 + 300) = *(undefined4 *)(param_1 + 0x24);
  *(float *)(param_1 + 0x124) = (float)fparam_2;
  return;
}

/* _glTexCoord2d_Comp @ 0x93520 (108 bytes) */
float * _glTexCoord2d_Comp(undefined4 param_1,double fparam_1,double fparam_2)
{
  float *pfVar1;
  
  pfVar1 = (float *)_gleAddListItem(param_1,PTR__glTexCoord2_ListExec_001103bc,8);
  if (pfVar1 != (float *)0x0) {
    *pfVar1 = (float)fparam_1;
    pfVar1[1] = (float)fparam_2;
  }
  return pfVar1;
}

/* _glTexCoord2d_CompExec @ 0x9358c (80 bytes) */
void _glTexCoord2d_CompExec(undefined4 param_1,double fparam_1,double fparam_2)
{
  ((float * (*)())_glTexCoord2d_Comp)(param_1,fparam_1,fparam_2);
  ((void (*)())_glTexCoord2d_Exec)(param_1,fparam_1,fparam_2);
  return;
}

/* _glTexCoord2dv_Exec @ 0x935dc (44 bytes) */
int _glTexCoord2dv_Exec(param_1, param_2)
  int param_1;
  double *param_2;
{
  double dVar1;
  double dVar2;
  
  dVar2 = param_2[1];
  dVar1 = *param_2;
  *(undefined4 *)(param_1 + 0x128) = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)(param_1 + 300) = *(undefined4 *)(param_1 + 0x24);
  *(float *)(param_1 + 0x120) = (float)dVar1;
  *(float *)(param_1 + 0x124) = (float)dVar2;
  return;
}

/* _glTexCoord2dv_Comp @ 0x93608 (96 bytes) */
int _glTexCoord2dv_Comp(param_1, param_2)
  undefined4 param_1;
  double *param_2;
{
  float *pfVar1;
  
  pfVar1 = (float *)_gleAddListItem(param_1,PTR__glTexCoord2_ListExec_001103bc,8);
  if (pfVar1 != (float *)0x0) {
    *pfVar1 = (float)*param_2;
    pfVar1[1] = (float)param_2[1];
  }
  return pfVar1;
}

/* _glTexCoord2dv_CompExec @ 0x93668 (56 bytes) */
int _glTexCoord2dv_CompExec(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  ((int (*)())_glTexCoord2dv_Comp)(param_1,param_2);
  ((int (*)())_glTexCoord2dv_Exec)(param_1,param_2);
  return;
}

