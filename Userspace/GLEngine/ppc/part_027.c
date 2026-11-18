#include "decls.h"

/* _glStencilFuncSeparate_ListExec @ 0x907f8 (56 bytes) */
int _glStencilFuncSeparate_ListExec(glContext, listRecord)
  undefined4 glContext;
  undefined4 *listRecord;
{
  ((void (*)())_glStencilFuncSeparate_Exec)(glContext,*listRecord,listRecord[1],listRecord[2],listRecord[3]);
  return 0x10;
}

/* _glStencilFuncSeparate_Comp @ 0x90830 (100 bytes) */
int _glStencilFuncSeparate_Comp(glContext, face, func, ref, mask)
  undefined4 glContext;
  undefined4 face;
  undefined4 func;
  undefined4 ref;
  undefined4 mask;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glStencilFuncSeparate_ListExec_00110308,0x10);
  if (listRecord != (undefined4 *)0x0) {
    listRecord[3] = mask;
    *listRecord = face;
    listRecord[1] = func;
    listRecord[2] = ref;
  }
  return listRecord;
}

/* _glStencilFuncSeparate_Exec @ 0x90894 (212 bytes) */
void _glStencilFuncSeparate_Exec(glContext, face, func, ref, mask)
  int glContext;
  uint face;
  int func;
  uint ref;
  undefined4 mask;
{
  undefined4 glErrorCode;
  uint maxStencilRef;
  undefined2 funcWord16;
  
  if (-1 < *(short *)(glContext + 0x4a10)) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
    goto LAB_000908d0;
  }
  if (7 < func - 0x200U) goto LAB_000908c0;
  if ((int)ref < 0) {
    ref = 0;
  }
  else {
    maxStencilRef = 0xffffffff >> (0x20U - *(int *)(*(int *)(glContext + 0x468c) + 0x40) & 0x3f);
    if (maxStencilRef < ref) {
      ref = maxStencilRef;
    }
  }
  funcWord16 = (undefined2)func;
  if (face == 0x405) {
    *(undefined2 *)(glContext + 0x3510) = funcWord16;
    *(uint *)(glContext + 0x350c) = ref;
    *(undefined4 *)(glContext + 0x3508) = mask;
    goto LAB_00090958;
  }
  if (face < 0x406) {
    if (face == 0x404) {
LAB_0009094c:
      *(undefined2 *)(glContext + 0x3500) = funcWord16;
      *(uint *)(glContext + 0x34fc) = ref;
      *(undefined4 *)(glContext + 0x34f8) = mask;
LAB_00090958:
      *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x10000000;
      return;
    }
  }
  else if (face == 0x408) {
    *(undefined2 *)(glContext + 0x3510) = funcWord16;
    *(uint *)(glContext + 0x350c) = ref;
    *(undefined4 *)(glContext + 0x3508) = mask;
    goto LAB_0009094c;
  }
LAB_000908c0:
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  glErrorCode = 0x500;
LAB_000908d0:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glStencilFuncSeparate_CompExec @ 0x90968 (80 bytes) */
void _glStencilFuncSeparate_CompExec(glContext, face, func, ref, mask)
  undefined4 glContext;
  undefined4 face;
  undefined4 func;
  undefined4 ref;
  undefined4 mask;
{
  ((int (*)())_glStencilFuncSeparate_Comp)(glContext,face,func,ref,mask);
  ((void (*)())_glStencilFuncSeparate_Exec)(glContext,face,func,ref,mask);
  return;
}

/* _glLineStipple_ListExec @ 0x909b8 (44 bytes) */
int _glLineStipple_ListExec(glContext, listRecord)
  undefined4 glContext;
  undefined4 *listRecord;
{
  ((void (*)())_glLineStipple_Exec)(glContext,*listRecord,(uint)*(ushort *)(listRecord + 1));
  return 8;
}

/* _glLineStipple_Comp @ 0x909e4 (84 bytes) */
int _glLineStipple_Comp(glContext, factor, pattern)
  undefined4 glContext;
  undefined4 factor;
  undefined4 pattern;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glLineStipple_ListExec_00110324,8);
  if (listRecord != (undefined4 *)0x0) {
    *(undefined2 *)(listRecord + 1) = (*(unsigned short *)((unsigned char *)&(pattern) + 2));
    *listRecord = factor;
  }
  return listRecord;
}

/* _glLineStipple_Exec @ 0x90a38 (88 bytes) */
void _glLineStipple_Exec(glContext, factor, pattern)
  int glContext;
  int factor;
  undefined4 pattern;
{
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (factor < 1) {
      factor = 1;
    }
    else if (0xff < factor) {
      factor = 0xff;
    }
    *(int *)(glContext + 0x3184) = factor;
    *(undefined2 *)(glContext + 0x3188) = (*(unsigned short *)((unsigned char *)&(pattern) + 2));
    *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x8000;
    return;
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  *(undefined4 *)(glContext + 0x7574) = 0x502;
  return;
}

/* _glLineStipple_CompExec @ 0x90a90 (64 bytes) */
void _glLineStipple_CompExec(glContext, factor, pattern)
  undefined4 glContext;
  undefined4 factor;
  undefined4 pattern;
{
  ((int (*)())_glLineStipple_Comp)(glContext,factor,pattern);
  ((void (*)())_glLineStipple_Exec)(glContext,factor,pattern);
  return;
}

/* _glPolygonStipple_ListExec @ 0x90ad0 (40 bytes) */
int _glPolygonStipple_ListExec(glContext, listRecord)
  int glContext;
  int listRecord;
{
  int byteOffset;
  int remaining;
  
  remaining = 0x10;
  byteOffset = 0;
  do {
    *(undefined8 *)(byteOffset + glContext + 0x3448) = *(undefined8 *)(byteOffset + listRecord);
    byteOffset = byteOffset + 8;
    remaining = remaining + -1;
  } while (remaining != 0);
  return 0x80;
}

/* _glPolygonStipple_Comp @ 0x90af8 (304 bytes) */
int _glPolygonStipple_Comp(glContext, mask)
  int glContext;
  int mask;
{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  int byteOffset;
  int iVar5;
  int listRecord;
  int remaining;
  
  iVar5 = *(int *)(glContext + 0x4a6c);
  if (iVar5 != 0) {
    if (*(int *)(iVar5 + 0x38) < mask + 0x20) {
      if (*(int *)(glContext + 0x7574) != 0) {
        return glContext;
      }
      *(undefined4 *)(glContext + 0x7574) = 0x502;
      return glContext;
    }
    if (*(int *)(iVar5 + 0x40) != 0) {
      _gleSynchronizePluginBuffer(glContext,iVar5 + 0x10);
    }
    mask = mask + *(int *)(iVar5 + 0x30);
  }
  listRecord = _gleAddListItem(glContext,PTR__glPolygonStipple_ListExec_00110320,0x80);
  if (listRecord != 0) {
    uVar1 = *(uint *)(glContext + 0x31d8);
    iVar3 = *(int *)(glContext + 0x31d4);
    if ((((*(char *)(glContext + 0x31e5) != '\0') || (*(int *)(glContext + 0x31cc) != 0)) ||
        (4 < *(int *)(glContext + 0x31e0))) || ((uVar1 & 7) != 0)) {
      uVar2 = _gleFillImage(glContext,0x20,0x20,1,0x1900,0x1a00,mask,listRecord);
      return uVar2;
    }
    byteOffset = 0;
    remaining = 0x10;
    do {
      *(undefined8 *)(byteOffset + listRecord) =
           *(undefined8 *)(byteOffset + mask + iVar3 * 4 + ((int)uVar1 >> 3));
      byteOffset = byteOffset + 8;
      remaining = remaining + -1;
    } while (remaining != 0);
  }
  return listRecord;
}

/* _glPolygonStipple_Exec @ 0x90c28 (288 bytes) */
void _glPolygonStipple_Exec(glContext, mask)
  int glContext;
  int mask;
{
  uint skipPixels;
  int byteOffset;
  int skipRows;
  int pixelUnpackBuffer;
  int remaining;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    pixelUnpackBuffer = *(int *)(glContext + 0x4a6c);
    if (pixelUnpackBuffer != 0) {
      if (*(int *)(pixelUnpackBuffer + 0x38) < mask + 0x20) goto LAB_00090c68;
      if (*(int *)(pixelUnpackBuffer + 0x40) != 0) {
        _gleSynchronizePluginBuffer(glContext,pixelUnpackBuffer + 0x10);
      }
      mask = mask + *(int *)(pixelUnpackBuffer + 0x30);
    }
    skipPixels = *(uint *)(glContext + 0x31d8);
    skipRows = *(int *)(glContext + 0x31d4);
    if ((((*(char *)(glContext + 0x31e5) == '\0') && (*(int *)(glContext + 0x31cc) == 0)) &&
        (*(int *)(glContext + 0x31e0) < 5)) && ((skipPixels & 7) == 0)) {
      remaining = 0x10;
      byteOffset = 0;
      do {
        *(undefined8 *)(byteOffset + glContext + 0x3448) =
             *(undefined8 *)(byteOffset + mask + skipRows * 4 + ((int)skipPixels >> 3));
        byteOffset = byteOffset + 8;
        remaining = remaining + -1;
      } while (remaining != 0);
    }
    else {
      _gleFillImage(glContext,0x20,0x20,1,0x1900,0x1a00,mask,glContext + 0x3448);
    }
    *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x1000000;
  }
  else {
LAB_00090c68:
    if (*(int *)(glContext + 0x7574) == 0) {
      *(undefined4 *)(glContext + 0x7574) = 0x502;
    }
  }
  return;
}

/* _glPolygonStipple_CompExec @ 0x90d48 (56 bytes) */
void _glPolygonStipple_CompExec(glContext, mask)
  undefined4 glContext;
  undefined4 mask;
{
  ((int (*)())_glPolygonStipple_Comp)(glContext,mask);
  ((void (*)())_glPolygonStipple_Exec)(glContext,mask);
  return;
}

/* _glGetPolygonStipple_Exec @ 0x90d80 (284 bytes) */
void _glGetPolygonStipple_Exec(glContext, mask)
  int glContext;
  int mask;
{
  uint skipPixels;
  int byteOffset;
  int skipRows;
  int pixelPackBuffer;
  int remaining;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    pixelPackBuffer = *(int *)(glContext + 0x4a68);
    if (pixelPackBuffer != 0) {
      if (*(int *)(pixelPackBuffer + 0x38) < mask + 0x20) goto LAB_00090dc0;
      if (*(int *)(pixelPackBuffer + 0x40) != 0) {
        _gleSynchronizePluginBuffer(glContext,pixelPackBuffer + 0x10);
      }
      mask = mask + *(int *)(pixelPackBuffer + 0x30);
    }
    skipPixels = *(uint *)(glContext + 0x31bc);
    skipRows = *(int *)(0x31b4 + glContext + 4);
    if ((((*(char *)(glContext + 0x31c9) != '\0') || (*(int *)(glContext + 0x31b0) != 0)) ||
        (4 < *(int *)(glContext + 0x31c4))) || ((skipPixels & 7) != 0)) {
      _gleEmptyImage(glContext,0x20,0x20,0x1900,0x1a00,glContext + 0x3448,mask);
      return;
    }
    remaining = 0x10;
    byteOffset = 0;
    do {
      *(undefined8 *)(byteOffset + mask + skipRows * 4 + ((int)skipPixels >> 3)) =
           *(undefined8 *)(byteOffset + glContext + 0x3448);
      byteOffset = byteOffset + 8;
      remaining = remaining + -1;
    } while (remaining != 0);
  }
  else {
LAB_00090dc0:
    if (*(int *)(glContext + 0x7574) == 0) {
      *(undefined4 *)(glContext + 0x7574) = 0x502;
    }
  }
  return;
}

/* _glSwap_RevertExec @ 0x90e9c (224 bytes) */
void _glSwap_RevertExec(glContext)
  int glContext;
{
  byte bVar1;
  undefined *puVar2;
  int iVar3;
  double fparam_1;
  double fparam_1_00;
  double incomingFpr2;
  double incomingFpr3;
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  double incomingStack_ffffffb8;
  double incomingStack_ffffffc0;
  double incomingStack_ffffffc8;
  double incomingStack_ffffffd0;
  double incomingStack_ffffffd8;
  
  bVar1 = *(byte *)(glContext + 0x85a5);
  if (*(short *)(glContext + 0x4a10) < 0) {
    _gleRevertSwapToPrimary(glContext);
    (**(code **)(glContext + 0x46f8))(*(undefined4 *)(glContext + 0x4688));
    iVar3 = (uint)bVar1 * 0x2e0 + glContext;
    (**(code **)(*(int *)(iVar3 + 0x8884) + 0x138))
              (*(undefined4 *)(iVar3 + 0x85ac),*(undefined4 *)(glContext + 0x484c),
               *(undefined4 *)(glContext + 0x4848),0);
    fparam_1 = (double)_gleSwitchToRenderer(glContext,(uint)bVar1);
    ((void (*)())_gleUpdateDepthRangeData)(glContext,fparam_1,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,incomingStack_ffffffb8,
               incomingStack_ffffffc0,incomingStack_ffffffc8,incomingStack_ffffffd0,incomingStack_ffffffd8);
    _gleUpdatePolyMode(glContext);
    ((void (*)())_gleUpdateViewScissorData)(glContext,fparam_1_00,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8);
    _gleUpdateTextureTransform(glContext);
    puVar2 = PTR__gleSetClipInterpFunc_00112038;
    *(undefined **)(glContext + 0x49c8) = PTR__gleSetEyeInterpFunc_0011203c;
    *(undefined **)(glContext + 0x49cc) = puVar2;
  }
  else if (*(int *)(glContext + 0x7574) == 0) {
    *(undefined4 *)(glContext + 0x7574) = 0x502;
  }
  return;
}

/* _glAreTexturesResident_Exec @ 0x90f7c (416 bytes) */
int _glAreTexturesResident_Exec(glContext, n, textures, residences)
  int glContext;
  int n;
  undefined4 *textures;
  int residences;
{
  undefined4 uVar1;
  undefined4 glErrorCode;
  int iVar2;
  int iVar3;
  int hashObject;
  int iVar4;
  int loopIndex;
  
  iVar4 = 1;
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (n < 0) {
      if (*(int *)(glContext + 0x7574) != 0) {
        return 0;
      }
      glErrorCode = 0x501;
    }
    else {
      if (n == 0) {
        return 0;
      }
      iVar2 = _malloc(n);
      if (iVar2 != 0) {
        if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) != '\0') {
          _pthread_mutex_lock(*(int *)(glContext + 0x5148) + 0x8028);
        }
        loopIndex = 0;
        if (0 < n) {
          do {
            uVar1 = *textures;
            textures = textures + 1;
            hashObject = _gleLookupHashObject(*(int *)(glContext + 0x5148) + 0x2008,uVar1);
            if (hashObject == 0) {
              if (*(int *)(glContext + 0x7574) == 0) {
                *(undefined4 *)(glContext + 0x7574) = 0x501;
              }
              iVar4 = 0;
              goto LAB_000910e0;
            }
            iVar3 = (**(code **)(glContext + 0x47ac))
                              (*(undefined4 *)(glContext + 0x4688),
                               *(undefined4 *)((uint)*(byte *)(glContext + 0x85a8) * 4 + iVar3 + 0x10)
                              );
            if (iVar3 == 0) {
              iVar4 = 0;
              *(undefined1 *)(iVar2 + loopIndex) = 0;
            }
            else {
              *(undefined1 *)(iVar2 + loopIndex) = 1;
            }
            loopIndex = loopIndex + 1;
          } while (loopIndex < n);
          if ((iVar4 == 0) && (loopIndex = 0, 0 < n)) {
            do {
              *(undefined1 *)(residences + loopIndex) = *(undefined1 *)(iVar2 + loopIndex);
              loopIndex = loopIndex + 1;
            } while (loopIndex < n);
          }
        }
LAB_000910e0:
        _free(iVar2);
        if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) != '\0') {
          _pthread_mutex_unlock(*(int *)(glContext + 0x5148) + 0x8028);
          return iVar4;
        }
        return iVar4;
      }
      if (*(int *)(glContext + 0x7574) != 0) {
        return 0;
      }
      glErrorCode = 0x505;
    }
  }
  else {
    if (*(int *)(glContext + 0x7574) != 0) {
      return 0;
    }
    glErrorCode = 0x502;
  }
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return 0;
}

/* _glIsTexture_Exec @ 0x9111c (168 bytes) */
int _glIsTexture_Exec(glContext, texture)
  int glContext;
  undefined4 texture;
{
  int sharedStateThenTextureObject;
  bool objectExists;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    sharedStateThenTextureObject = *(int *)(glContext + 0x5148);
    if (*(char *)(sharedStateThenTextureObject + 0x8024) != '\0') {
      _pthread_mutex_lock(sharedStateThenTextureObject + 0x8028);
      sharedStateThenTextureObject = *(int *)(glContext + 0x5148);
    }
    sharedStateThenTextureObject = _gleLookupHashObject(sharedStateThenTextureObject + 0x2008,texture);
    if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) != '\0') {
      _pthread_mutex_unlock(*(int *)(glContext + 0x5148) + 0x8028);
    }
    objectExists = sharedStateThenTextureObject != 0;
  }
  else {
    if (*(int *)(glContext + 0x7574) == 0) {
      *(undefined4 *)(glContext + 0x7574) = 0x502;
    }
    objectExists = false;
  }
  return objectExists;
}

/* _glBindTexture_ListExec @ 0x911c4 (44 bytes) */
int _glBindTexture_ListExec(glContext, listRecord)
  undefined4 glContext;
  undefined4 *listRecord;
{
  _glBindTexture_Exec(glContext,*listRecord,listRecord[1]);
  return 8;
}

/* _glBindTexture_Comp @ 0x911f0 (84 bytes) */
int _glBindTexture_Comp(glContext, target, texture)
  undefined4 glContext;
  undefined4 target;
  undefined4 texture;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glBindTexture_ListExec_00110390,8);
  if (listRecord != (undefined4 *)0x0) {
    listRecord[1] = texture;
    *listRecord = target;
  }
  return listRecord;
}

/* _glBindTexture_CompExec @ 0x91244 (64 bytes) */
void _glBindTexture_CompExec(glContext, target, texture)
  undefined4 glContext;
  undefined4 target;
  undefined4 texture;
{
  ((int (*)())_glBindTexture_Comp)(glContext,target,texture);
  _glBindTexture_Exec(glContext,target,texture);
  return;
}

/* _glPrioritizeTextures_ListExec @ 0x91284 (72 bytes) */
int _glPrioritizeTextures_ListExec(glContext, listRecord)
  undefined4 glContext;
  int *listRecord;
{
  int iVar1;
  
  iVar1 = *listRecord;
  _glPrioritizeTextures_Exec(glContext,iVar1,listRecord + 1,listRecord + iVar1 + 1);
  return iVar1 * 8 + 4;
}

/* _glPrioritizeTextures_Comp @ 0x912cc (144 bytes) */
int _glPrioritizeTextures_Comp(glContext, n, textures, priorities)
  undefined4 glContext;
  int n;
  int textures;
  int priorities;
{
  int *listRecord;
  int elementIndex;
  int remaining;
  
  listRecord = (int *)_gleAddListItem(glContext,PTR__glPrioritizeTextures_ListExec_0011038c,
                                  n * 8 + 4);
  if (listRecord != (int *)0x0) {
    elementIndex = 0;
    *listRecord = n;
    remaining = n;
    if (0 < n) {
      do {
        listRecord[elementIndex + 1] = *(int *)(textures + elementIndex * 4);
        listRecord[n + elementIndex + 1] = *(int *)(priorities + elementIndex * 4);
        remaining = remaining + -1;
        elementIndex = elementIndex + 1;
      } while (remaining != 0);
    }
  }
  return listRecord;
}

/* _glPrioritizeTextures_CompExec @ 0x9135c (72 bytes) */
void _glPrioritizeTextures_CompExec(glContext, n, textures, priorities)
  undefined4 glContext;
  undefined4 n;
  undefined4 textures;
  undefined4 priorities;
{
  ((int (*)())_glPrioritizeTextures_Comp)(glContext,n,textures,priorities);
  _glPrioritizeTextures_Exec(glContext,n,textures,priorities);
  return;
}

/* _glCompressedTexImage3D_ListExec @ 0x913a4 (96 bytes) */
int _glCompressedTexImage3D_ListExec(glContext, listRecord)
  undefined4 glContext;
  undefined4 *listRecord;
{
  ((int (*)())_glCompressedTexImage3D_Exec)(glContext,*listRecord,listRecord[1],listRecord[2],listRecord[3],listRecord[4],listRecord[5],listRecord[6],
             listRecord[7],listRecord + 8);
  return listRecord[7] + 0x20;
}

/* _glCompressedTexImage2D_ListExec @ 0x91404 (88 bytes) */
int _glCompressedTexImage2D_ListExec(glContext, listRecord)
  undefined4 glContext;
  undefined4 *listRecord;
{
  ((int (*)())_glCompressedTexImage2D_Exec)(glContext,*listRecord,listRecord[1],listRecord[2],listRecord[3],listRecord[4],listRecord[5],listRecord[6],
             listRecord + 7);
  return listRecord[6] + 0x1c;
}

/* _glCompressedTexSubImage3D_ListExec @ 0x91464 (112 bytes) */
int _glCompressedTexSubImage3D_ListExec(glContext, listRecord)
  undefined4 glContext;
  undefined4 *listRecord;
{
  ((int (*)())_glCompressedTexSubImage3D_Exec)(glContext,*listRecord,listRecord[1],listRecord[2],listRecord[3],listRecord[4],listRecord[5],listRecord[6],
             listRecord[7],listRecord[8],listRecord[9],listRecord + 10);
  return listRecord[9] + 0x28;
}

/* _glCompressedTexSubImage2D_ListExec @ 0x914d4 (96 bytes) */
int _glCompressedTexSubImage2D_ListExec(glContext, listRecord)
  undefined4 glContext;
  undefined4 *listRecord;
{
  ((int (*)())_glCompressedTexSubImage2D_Exec)(glContext,*listRecord,listRecord[1],listRecord[2],listRecord[3],listRecord[4],listRecord[5],listRecord[6],
             listRecord[7],listRecord + 8);
  return listRecord[7] + 0x20;
}

/* _glCompressedTexImage3D_Comp @ 0x9153c (344 bytes) */
int _glCompressedTexImage3D_Comp(glContext, target, level, internalformat, width, height, depth, border, imageSize, data)
  int *glContext;
  int target;
  int level;
  uint internalformat;
  int width;
  int height;
  int depth;
  int border;
  int imageSize;
  int data;
{
  undefined4 uVar1;
  int iVar2;
  
  if (target == 0x8070) {
    uVar1 = ((int (*)())_glCompressedTexImage3D_Exec)(glContext,0x8070,level,internalformat,width,height,depth,border,imageSize,
                       data);
    return uVar1;
  }
  if ((internalformat < 0x83f0) || (((0x83f3 < internalformat && (internalformat != 0x8837)) || (imageSize < 1)))) {
LAB_000915e4:
    if (glContext[0x1d5d] == 0) {
      glContext[0x1d5d] = 0x502;
    }
  }
  else {
    iVar2 = glContext[0x129b];
    if (iVar2 != 0) {
      if (*(int *)(iVar2 + 0x38) < imageSize + data) goto LAB_000915e4;
      if (*(int *)(iVar2 + 0x40) != 0) {
        _gleSynchronizePluginBuffer(glContext,iVar2 + 0x10);
      }
      data = data + *(int *)(iVar2 + 0x30);
    }
    glContext = (int *)_gleAddListItem(glContext,PTR__glCompressedTexImage3D_ListExec_001103a0,
                                     imageSize + 0x20);
    if (glContext != (int *)0x0) {
      *glContext = target;
      glContext[1] = level;
      glContext[2] = internalformat;
      glContext[6] = border;
      glContext[3] = width;
      glContext[4] = height;
      glContext[5] = depth;
      glContext[7] = imageSize;
      if (data != 0) {
        uVar1 = _memcpy(glContext + 8,data,imageSize);
        return uVar1;
      }
    }
  }
  return glContext;
}

/* _glCompressedTexImage2D_Comp @ 0x91694 (404 bytes) */
int _glCompressedTexImage2D_Comp(glContext, target, level, internalformat, width, height, border, imageSize, data)
  int *glContext;
  int target;
  int level;
  uint internalformat;
  int width;
  int height;
  int border;
  int imageSize;
  int data;
{
  undefined4 calleeResult;
  int pixelUnpackBuffer;
  
  if (((target == 0x8064) || (target == 0x851b)) || (target == 0x84f7)) {
    calleeResult = ((int (*)())_glCompressedTexImage2D_Exec)(glContext,target,level,internalformat,width,height,border,imageSize,data);
    return calleeResult;
  }
  if (((internalformat < 0x83f0) || ((0x83f3 < internalformat && (internalformat != 0x8837)))) || (imageSize < 1)) {
LAB_0009177c:
    if (glContext[0x1d5d] == 0) {
      glContext[0x1d5d] = 0x502;
    }
  }
  else {
    pixelUnpackBuffer = glContext[0x129b];
    if (pixelUnpackBuffer != 0) {
      if (*(int *)(pixelUnpackBuffer + 0x38) < imageSize + data) goto LAB_0009177c;
      if (*(int *)(pixelUnpackBuffer + 0x40) != 0) {
        _gleSynchronizePluginBuffer(glContext,pixelUnpackBuffer + 0x10);
      }
      data = data + *(int *)(pixelUnpackBuffer + 0x30);
    }
    glContext = (int *)_gleAddListItem(glContext,PTR__glCompressedTexImage2D_ListExec_0011039c,
                                     imageSize + 0x1c);
    if (glContext != (int *)0x0) {
      *glContext = target;
      glContext[1] = level;
      glContext[2] = internalformat;
      glContext[5] = border;
      glContext[3] = width;
      glContext[4] = height;
      glContext[6] = imageSize;
      if (data != 0) {
        calleeResult = _memcpy(glContext + 7,data,imageSize);
        return calleeResult;
      }
    }
  }
  return glContext;
}

/* _glCompressedTexImage1D_Comp @ 0x91828 (76 bytes) */
void _glCompressedTexImage1D_Comp(glContext, target, level, internalformat)
  int glContext;
  undefined4 target;
  undefined4 level;
  uint internalformat;
{
  undefined4 glErrorCode;
  
  if ((internalformat < 0x83f0) || ((0x83f3 < internalformat && (internalformat != 0x8837)))) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
  }
  else {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x500;
  }
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glCompressedTexSubImage3D_Comp @ 0x91874 (360 bytes) */
int _glCompressedTexSubImage3D_Comp(glContext, target, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, data)
  int *glContext;
  int target;
  int level;
  int xoffset;
  int yoffset;
  int zoffset;
  int width;
  int height;
  int depth;
  uint format;
  int imageSize;
  int data;
{
  undefined4 calleeResult;
  int pixelUnpackBuffer;
  
  if (target == 0x8070) {
    calleeResult = ((int (*)())_glCompressedTexSubImage3D_Exec)(glContext,0x8070,level,xoffset,yoffset,zoffset,width,height,depth,
                       format,imageSize,data);
    return calleeResult;
  }
  if ((format < 0x83f0) || (((0x83f3 < format && (format != 0x8837)) || (imageSize < 1)))) {
LAB_00091924:
    if (glContext[0x1d5d] == 0) {
      glContext[0x1d5d] = 0x502;
    }
  }
  else {
    pixelUnpackBuffer = glContext[0x129b];
    if (pixelUnpackBuffer != 0) {
      if (*(int *)(pixelUnpackBuffer + 0x38) < imageSize + data) goto LAB_00091924;
      if (*(int *)(pixelUnpackBuffer + 0x40) != 0) {
        _gleSynchronizePluginBuffer(glContext,pixelUnpackBuffer + 0x10);
      }
      data = data + *(int *)(pixelUnpackBuffer + 0x30);
    }
    glContext = (int *)_gleAddListItem(glContext,PTR__glCompressedTexSubImage3D_ListExec_00110398,
                                     imageSize + 0x28);
    if (glContext != (int *)0x0) {
      *glContext = target;
      glContext[1] = level;
      glContext[8] = format;
      glContext[2] = xoffset;
      glContext[3] = yoffset;
      glContext[4] = zoffset;
      glContext[5] = width;
      glContext[6] = height;
      glContext[7] = depth;
      glContext[9] = imageSize;
      if (data != 0) {
        calleeResult = _memcpy(glContext + 10,data,imageSize);
        return calleeResult;
      }
    }
  }
  return glContext;
}

/* _glCompressedTexSubImage2D_Comp @ 0x919dc (416 bytes) */
int _glCompressedTexSubImage2D_Comp(glContext, target, level, xoffset, yoffset, width, height, format, imageSize, data)
  int *glContext;
  int target;
  int level;
  int xoffset;
  int yoffset;
  int width;
  int height;
  uint format;
  int imageSize;
  int data;
{
  undefined4 uVar1;
  int iVar2;
  
  if (((target == 0x8064) || (target == 0x851b)) || (target == 0x84f7)) {
    uVar1 = ((int (*)())_glCompressedTexSubImage2D_Exec)(glContext,target,level,xoffset,yoffset,width,height,format,imageSize,
                       data);
    return uVar1;
  }
  if (((format < 0x83f0) || ((0x83f3 < format && (format != 0x8837)))) || (imageSize < 1)) {
LAB_00091acc:
    if (glContext[0x1d5d] == 0) {
      glContext[0x1d5d] = 0x502;
    }
  }
  else {
    iVar2 = glContext[0x129b];
    if (iVar2 != 0) {
      if (*(int *)(iVar2 + 0x38) < imageSize + data) goto LAB_00091acc;
      if (*(int *)(iVar2 + 0x40) != 0) {
        _gleSynchronizePluginBuffer(glContext,iVar2 + 0x10);
      }
      data = data + *(int *)(iVar2 + 0x30);
    }
    glContext = (int *)_gleAddListItem(glContext,PTR__glCompressedTexSubImage2D_ListExec_00110394,
                                     imageSize + 0x20);
    if (glContext != (int *)0x0) {
      *glContext = target;
      glContext[1] = level;
      glContext[6] = format;
      glContext[2] = xoffset;
      glContext[3] = yoffset;
      glContext[4] = width;
      glContext[5] = height;
      glContext[7] = imageSize;
      if (data != 0) {
        uVar1 = _memcpy(glContext + 8,data,imageSize);
        return uVar1;
      }
    }
  }
  return glContext;
}

/* _glCompressedTexSubImage1D_Comp @ 0x91b7c (76 bytes) */
void _glCompressedTexSubImage1D_Comp(glContext, target, level, xoffset, width, format)
  int glContext;
  undefined4 target;
  undefined4 level;
  undefined4 xoffset;
  undefined4 width;
  uint format;
{
  undefined4 glErrorCode;
  
  if ((format < 0x83f0) || ((0x83f3 < format && (format != 0x8837)))) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
  }
  else {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x500;
  }
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glCompressedTexImage3D_Exec @ 0x91bc8 (700 bytes) */
int _glCompressedTexImage3D_Exec(glContext, target, level, internalformat, width, height, depth, border, imageSize, data)
  int glContext;
  int target;
  int level;
  undefined4 internalformat;
  undefined4 width;
  undefined4 height;
  undefined4 depth;
  undefined4 border;
  int imageSize;
  int data;
{
  byte levelFlags;
  ushort objectFlags;
  undefined4 pluginResult;
  undefined4 glErrorCode;
  uint faceIndex;
  int contextThenTextureObject;
  int pixelUnpackBuffer;
  int createResult;
  int levelRecord;
  int textureLevel;
  
  contextThenTextureObject = glContext;
  if (*(short *)(glContext + 0x4a10) < 0) {
    if ((data == 0) && (*(char *)(glContext + 0x31e6) != '\0')) {
      if (*(int *)(glContext + 0x7574) != 0) {
        return glContext;
      }
      glErrorCode = 0x501;
      goto LAB_00091ce0;
    }
    pixelUnpackBuffer = *(int *)(glContext + 0x4a6c);
    if (pixelUnpackBuffer != 0) {
      if (*(int *)(pixelUnpackBuffer + 0x38) < imageSize + data) goto LAB_00091cd0;
      if (*(int *)(pixelUnpackBuffer + 0x40) != 0) {
        _gleSynchronizePluginBuffer(glContext,pixelUnpackBuffer + 0x10);
      }
      data = data + *(int *)(pixelUnpackBuffer + 0x30);
    }
    contextThenTextureObject = _gleCheckCompressedTexImage3DArgs
                      (glContext,target,level,internalformat,width,height,depth,border,imageSize);
    if (contextThenTextureObject == 0) {
      return 0;
    }
    objectFlags = *(ushort *)(contextThenTextureObject + 0x24);
    if ((objectFlags & 0x3c00) == 0x1000) {
LAB_00091ce8:
      faceIndex = target - 0x8515;
      if (5 < faceIndex) {
        faceIndex = 0;
      }
      levelRecord = contextThenTextureObject + faceIndex * 0x168 + level * 0x18;
      textureLevel = levelRecord + 0xc4;
      if ((*(byte *)(levelRecord + 0xcf) & 0x20) != 0) {
        _gleDeletePluginTextureLevel(glContext,contextThenTextureObject,textureLevel,faceIndex,level);
        if (*(int *)(levelRecord + 0xd8) != 0) {
          levelFlags = *(byte *)(levelRecord + 0xcf);
          if ((levelFlags & 1) == 0) {
            _gleFreeTextureLevel(glContext,contextThenTextureObject,textureLevel);
            levelFlags = *(byte *)(levelRecord + 0xcf);
          }
          else {
            *(undefined4 *)(levelRecord + 0xd8) = 0;
          }
          *(byte *)(levelRecord + 0xcf) = levelFlags & 0xef;
        }
        *(byte *)(levelRecord + 0xcf) = *(byte *)(levelRecord + 0xcf) & 0xdf;
      }
      createResult = _gleCreateTextureLevel
                        (glContext,contextThenTextureObject,textureLevel,internalformat,width,height,depth,border,internalformat,0,1,
                         data);
      if ((createResult != 0) && (data != 0)) {
        _gleCompressedTextureImagePut
                  (glContext,textureLevel,0,0,0,width,height,depth,internalformat,imageSize,data);
      }
      pluginResult = _gleCreatePluginTextureLevel(glContext,contextThenTextureObject,textureLevel,faceIndex,level,internalformat);
      if ((((*(uint *)(contextThenTextureObject + 0x6c) & 0x8000) != 0) && (*(short *)(contextThenTextureObject + 0x60) == level)) &&
         (contextThenTextureObject = _gleGenMipmapsToLevel(glContext,contextThenTextureObject,0,level,0xf,1), pluginResult = 0, contextThenTextureObject != 0)) {
        return contextThenTextureObject;
      }
      *(uint *)(glContext + 0x314) =
           *(uint *)(glContext + 0x314) | 1 << (*(uint *)(glContext + 0x53d4) & 0x3f);
      return pluginResult;
    }
    if ((objectFlags & 0x3c00) == 0) {
      *(ushort *)(contextThenTextureObject + 0x24) = objectFlags | 0x1000;
      goto LAB_00091ce8;
    }
    if ((objectFlags & 0xc00) == 0) goto LAB_00091ce8;
  }
LAB_00091cd0:
  if (*(int *)(glContext + 0x7574) != 0) {
    return contextThenTextureObject;
  }
  glErrorCode = 0x502;
LAB_00091ce0:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return contextThenTextureObject;
}

/* _glCompressedTexImage2D_Exec @ 0x91e84 (692 bytes) */
int _glCompressedTexImage2D_Exec(glContext, target, level, internalformat, width, height, border, imageSize, data)
  int glContext;
  int target;
  int level;
  undefined4 internalformat;
  undefined4 width;
  undefined4 height;
  undefined4 border;
  int imageSize;
  int data;
{
  byte levelFlags;
  ushort textureTargetBits;
  undefined4 glErrorCode;
  uint faceIndex;
  int levelCreated;
  int levelSlot;
  int unpackBuffer;
  int textureObject;
  int textureLevel;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    if ((data == 0) && (*(char *)(glContext + 0x31e6) != '\0')) {
      if (*(int *)(glContext + 0x7574) != 0) {
        return;
      }
      glErrorCode = 0x501;
      goto LAB_00091f94;
    }
    unpackBuffer = *(int *)(glContext + 0x4a6c);
    if (unpackBuffer != 0) {
      if (*(int *)(unpackBuffer + 0x38) < imageSize + data) goto LAB_00091f84;
      if (*(int *)(unpackBuffer + 0x40) != 0) {
        _gleSynchronizePluginBuffer(glContext,unpackBuffer + 0x10);
      }
      data = data + *(int *)(unpackBuffer + 0x30);
    }
    textureObject = _gleCheckCompressedTexImage2DArgs
                      (glContext,target,level,internalformat,width,height,border,imageSize);
    if (textureObject == 0) {
      return;
    }
    textureTargetBits = *(ushort *)(textureObject + 0x24);
    if ((textureTargetBits & 0x3c00) == 0x1000) {
LAB_00091f9c:
      faceIndex = target - 0x8515;
      if (5 < faceIndex) {
        faceIndex = 0;
      }
      levelSlot = textureObject + faceIndex * 0x168 + level * 0x18;
      textureLevel = levelSlot + 0xc4;
      if ((*(byte *)(levelSlot + 0xcf) & 0x20) != 0) {
        _gleDeletePluginTextureLevel(glContext,textureObject,textureLevel,faceIndex,level);
        if (*(int *)(levelSlot + 0xd8) != 0) {
          levelFlags = *(byte *)(levelSlot + 0xcf);
          if ((levelFlags & 1) == 0) {
            _gleFreeTextureLevel(glContext,textureObject,textureLevel);
            levelFlags = *(byte *)(levelSlot + 0xcf);
          }
          else {
            *(undefined4 *)(levelSlot + 0xd8) = 0;
          }
          *(byte *)(levelSlot + 0xcf) = levelFlags & 0xef;
        }
        *(byte *)(levelSlot + 0xcf) = *(byte *)(levelSlot + 0xcf) & 0xdf;
      }
      levelCreated = _gleCreateTextureLevel
                        (glContext,textureObject,textureLevel,internalformat,width,height,1,border,internalformat,0,1,data);
      if ((levelCreated != 0) && (data != 0)) {
        _gleCompressedTextureImagePut(glContext,textureLevel,0,0,0,width,height,1,internalformat,imageSize,data)
        ;
      }
      _gleCreatePluginTextureLevel(glContext,textureObject,textureLevel,faceIndex,level,internalformat);
      if ((((*(uint *)(textureObject + 0x6c) & 0x8000) != 0) && (*(short *)(textureObject + 0x60) == level)) &&
         (textureObject = _gleGenMipmapsToLevel(glContext,textureObject,faceIndex,level,0xf,1), textureObject != 0)) {
        return;
      }
      *(uint *)(glContext + 0x314) =
           *(uint *)(glContext + 0x314) | 1 << (*(uint *)(glContext + 0x53d4) & 0x3f);
      return;
    }
    if ((textureTargetBits & 0x3c00) == 0) {
      *(ushort *)(textureObject + 0x24) = textureTargetBits | 0x1000;
      goto LAB_00091f9c;
    }
    if ((textureTargetBits & 0xc00) == 0) goto LAB_00091f9c;
  }
LAB_00091f84:
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  glErrorCode = 0x502;
LAB_00091f94:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glCompressedTexImage1D_Exec @ 0x92138 (76 bytes) */
void _glCompressedTexImage1D_Exec(glContext, target, level, internalformat)
  int glContext;
  undefined4 target;
  undefined4 level;
  uint internalformat;
{
  undefined4 glErrorCode;
  
  if ((internalformat < 0x83f0) || ((0x83f3 < internalformat && (internalformat != 0x8837)))) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
  }
  else {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x500;
  }
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glCompressedTexSubImage3D_Exec @ 0x92184 (1464 bytes) */
int _glCompressedTexSubImage3D_Exec(glContext, target, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, data)
  int glContext;
  undefined4 target;
  uint level;
  undefined4 xoffset;
  undefined4 yoffset;
  undefined4 zoffset;
  int width;
  int height;
  undefined4 depth;
  undefined4 format;
  int imageSize;
  int data;
{
  int levelBase;
  int textureObject;
  int returnValue;
  byte levelFlagByte;
  int textureLevel;
  uint mipLevel;
  int pixelUnpackBuffer;
  int mipLevelRecord;
  
  returnValue = glContext;
  if (*(short *)(glContext + 0x4a10) < 0) {
    pixelUnpackBuffer = *(int *)(glContext + 0x4a6c);
    if (pixelUnpackBuffer != 0) {
      if (*(int *)(pixelUnpackBuffer + 0x38) < imageSize + data) goto LAB_000921f0;
      data = data + *(int *)(pixelUnpackBuffer + 0x30);
    }
    if ((width != 0) && (height != 0)) {
      textureObject = _gleCheckCompressedTexSubImage3DArgs
                        (glContext,target,level,xoffset,yoffset,zoffset,width,height,depth,
                         format,imageSize);
      returnValue = 0;
      if (textureObject != 0) {
        levelBase = textureObject + level * 0x18;
        textureLevel = levelBase + 0xc4;
        if (pixelUnpackBuffer != 0) {
          if (((((int)(uint)*(byte *)(textureObject + 0x8d) <= (int)level) &&
               ((int)level <= (int)(uint)*(byte *)(textureObject + 0x8f))) &&
              ((*(ushort *)(textureObject + 0x94) >> (level & 0x3f) & 1) != 0)) &&
             (returnValue = (**(code **)(glContext + 0x4710))
                                (*(undefined4 *)(glContext + 0x4688),
                                 *(undefined4 *)(textureObject + (uint)*(byte *)(glContext + 0x85a8) * 4),0,
                                 level,xoffset,yoffset,zoffset,width), returnValue != 0)) {
            *(undefined4 *)(textureObject + 0x20) =
                 *(undefined4 *)
                  ((uint)*(byte *)(glContext + 0x85a8) * 4 + *(int *)(glContext + 0x5148) + 0x8054);
            if (*(int *)(levelBase + 0xd8) != 0) {
              levelFlagByte = *(byte *)(levelBase + 0xcf);
              if (((levelFlagByte & 1) == 0) && (*(short *)(textureObject + 0x3e) == -0x7a43)) {
                returnValue = _gleFreeTextureLevel(glContext,textureObject,textureLevel);
                levelFlagByte = *(byte *)(levelBase + 0xcf);
              }
              *(byte *)(levelBase + 0xcf) = levelFlagByte & 0xef;
              *(ushort *)(textureObject + 0xa0) =
                   *(ushort *)(textureObject + 0xa0) &
                   ((ushort)(-2 << (level & 0x1f)) |
                   (ushort)(0xfffffffe >> 0x20 - (level & 0x1f)));
            }
            *(byte *)(levelBase + 0xcf) = *(byte *)(levelBase + 0xcf) | 0x40;
            if ((*(uint *)(textureObject + 0x6c) & 0x8000) == 0) {
              return returnValue;
            }
            if ((int)*(short *)(textureObject + 0x60) != level) {
              return returnValue;
            }
            mipLevel = level + 1;
            if ((int)(uint)*(byte *)(textureObject + 0x83) < (int)mipLevel) {
              return returnValue;
            }
            mipLevelRecord = mipLevel * 0x18 + textureObject + 0xc4;
            do {
              if (*(int *)(mipLevelRecord + 0x14) != 0) {
                if (((*(byte *)(mipLevelRecord + 0xb) & 1) == 0) && (*(short *)(textureObject + 0x3e) == -0x7a43)) {
                  returnValue = _gleFreeTextureLevel(glContext,textureObject,mipLevelRecord);
                }
                *(byte *)(mipLevelRecord + 0xb) = *(byte *)(mipLevelRecord + 0xb) & 0xef;
                *(ushort *)(textureObject + 0xa0) =
                     *(ushort *)(textureObject + 0xa0) & ~(ushort)(1 << (mipLevel & 0x3f));
              }
              mipLevel = mipLevel + 1;
              *(byte *)(mipLevelRecord + 0xb) = *(byte *)(mipLevelRecord + 0xb) | 0x40;
              mipLevelRecord = mipLevelRecord + 0x18;
            } while ((int)mipLevel <= (int)(uint)*(byte *)(textureObject + 0x83));
            return returnValue;
          }
          if (*(int *)(pixelUnpackBuffer + 0x40) != 0) {
            _gleSynchronizePluginBuffer(glContext,pixelUnpackBuffer + 0x10);
          }
        }
        if (((((int)level < (int)(uint)*(byte *)(textureObject + 0x8d)) ||
             ((int)(uint)*(byte *)(textureObject + 0x8f) < (int)level)) ||
            ((*(ushort *)(textureObject + 0x94) >> (level & 0x3f) & 1) == 0)) ||
           (returnValue = (**(code **)(glContext + 0x4710))
                              (*(undefined4 *)(glContext + 0x4688),
                               *(undefined4 *)(textureObject + (uint)*(byte *)(glContext + 0x85a8) * 4),0,
                               level,xoffset,yoffset,zoffset,width), returnValue == 0)) {
          levelFlagByte = *(byte *)(levelBase + 0xcf);
          if ((levelFlagByte & 0x10) == 0) {
            if ((levelFlagByte & 0x40) == 0) {
              if (*(int *)(levelBase + 0xd8) == 0) {
                _gleAllocateTextureLevel(glContext,textureObject,textureLevel);
                levelFlagByte = *(byte *)(levelBase + 0xcf);
              }
              *(byte *)(levelBase + 0xcf) = levelFlagByte | 0x10;
            }
            else {
              _gleUploadPluginTextureLevel
                        (glContext,textureObject,textureLevel,0,level,(uint)*(byte *)(glContext + 0x85a8));
            }
          }
          returnValue = _gleModifyPluginTextureLevel
                            (glContext,textureObject,textureLevel,0,level,xoffset,yoffset,zoffset,width,height,
                             depth);
          if (data != 0) {
            returnValue = _gleCompressedTextureImagePut
                              (glContext,textureLevel,xoffset,yoffset,zoffset,width,height,depth,
                               format,imageSize,data);
          }
          if ((((*(uint *)(textureObject + 0x6c) & 0x8000) == 0) ||
              ((int)*(short *)(textureObject + 0x60) != level)) ||
             (returnValue = _gleGenMipmapsToLevel(glContext,textureObject,0,level,0xf,1), returnValue == 0)) {
            *(uint *)(glContext + 0x314) =
                 *(uint *)(glContext + 0x314) | 1 << (*(uint *)(glContext + 0x53d4) & 0x3f);
          }
        }
        else {
          *(undefined4 *)(textureObject + 0x20) =
               *(undefined4 *)
                ((uint)*(byte *)(glContext + 0x85a8) * 4 + *(int *)(glContext + 0x5148) + 0x8054);
          if (*(int *)(levelBase + 0xd8) != 0) {
            levelFlagByte = *(byte *)(levelBase + 0xcf);
            if (((levelFlagByte & 1) == 0) && (*(short *)(textureObject + 0x3e) == -0x7a43)) {
              returnValue = _gleFreeTextureLevel(glContext,textureObject,textureLevel);
              levelFlagByte = *(byte *)(levelBase + 0xcf);
            }
            *(byte *)(levelBase + 0xcf) = levelFlagByte & 0xef;
            *(ushort *)(textureObject + 0xa0) =
                 *(ushort *)(textureObject + 0xa0) &
                 ((ushort)(-2 << (level & 0x1f)) | (ushort)(0xfffffffe >> 0x20 - (level & 0x1f))
                 );
          }
          *(byte *)(levelBase + 0xcf) = *(byte *)(levelBase + 0xcf) | 0x40;
          if ((((*(uint *)(textureObject + 0x6c) & 0x8000) != 0) &&
              ((int)*(short *)(textureObject + 0x60) == level)) &&
             (mipLevel = level + 1, (int)mipLevel <= (int)(uint)*(byte *)(textureObject + 0x83))) {
            mipLevelRecord = mipLevel * 0x18 + textureObject + 0xc4;
            do {
              if (*(int *)(mipLevelRecord + 0x14) != 0) {
                if (((*(byte *)(mipLevelRecord + 0xb) & 1) == 0) && (*(short *)(textureObject + 0x3e) == -0x7a43)) {
                  returnValue = _gleFreeTextureLevel(glContext,textureObject,mipLevelRecord);
                }
                *(byte *)(mipLevelRecord + 0xb) = *(byte *)(mipLevelRecord + 0xb) & 0xef;
                *(ushort *)(textureObject + 0xa0) =
                     *(ushort *)(textureObject + 0xa0) & ~(ushort)(1 << (mipLevel & 0x3f));
              }
              mipLevel = mipLevel + 1;
              *(byte *)(mipLevelRecord + 0xb) = *(byte *)(mipLevelRecord + 0xb) | 0x40;
              mipLevelRecord = mipLevelRecord + 0x18;
            } while ((int)mipLevel <= (int)(uint)*(byte *)(textureObject + 0x83));
          }
        }
      }
    }
  }
  else {
LAB_000921f0:
    if (*(int *)(glContext + 0x7574) == 0) {
      *(undefined4 *)(glContext + 0x7574) = 0x502;
    }
  }
  return returnValue;
}

/* _glCompressedTexSubImage2D_Exec @ 0x9273c (1552 bytes) */
int _glCompressedTexSubImage2D_Exec(glContext, target, level, xoffset, yoffset, width, height, format, imageSize, data)
  int glContext;
  int target;
  uint level;
  undefined4 xoffset;
  undefined4 yoffset;
  int width;
  int height;
  undefined4 format;
  int imageSize;
  int data;
{
  uint faceIndex;
  uint nextLevel;
  int levelRecord;
  int levelImageCursor2;
  int textureObject;
  int pluginResult;
  int iVar5;
  byte levelFlags;
  int faceOffset;
  int textureLevel;
  int iVar9;
  int levelImageCursor;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    iVar9 = *(int *)(glContext + 0x4a6c);
    if (iVar9 != 0) {
      if (*(int *)(iVar9 + 0x38) < imageSize + data) goto LAB_000927a4;
      data = data + *(int *)(iVar9 + 0x30);
    }
    if (((width != 0) && (height != 0)) &&
       (textureObject = _gleCheckCompressedTexSubImage2DArgs
                          (glContext,target,level,xoffset,yoffset,width,height,format,imageSize),
       textureObject != 0)) {
      faceIndex = target - 0x8515;
      if (5 < faceIndex) {
        faceIndex = 0;
      }
      faceOffset = faceIndex * 0x168;
      levelRecord = textureObject + faceOffset + level * 0x18;
      textureLevel = levelRecord + 0xc4;
      if (iVar9 != 0) {
        if ((((int)(uint)*(byte *)(textureObject + 0x8d) <= (int)level) &&
            ((int)level <= (int)(uint)*(byte *)(textureObject + 0x8f))) &&
           ((iVar5 = faceIndex * 2, (*(ushort *)(iVar5 + textureObject + 0x94) >> (level & 0x3f) & 1) != 0 &&
            (pluginResult = (**(code **)(glContext + 0x4710))
                               (*(undefined4 *)(glContext + 0x4688),
                                *(undefined4 *)(textureObject + (uint)*(byte *)(glContext + 0x85a8) * 4),faceIndex
                                ,level,xoffset,yoffset,0,width), pluginResult != 0)))) {
          *(undefined4 *)(textureObject + 0x20) =
               *(undefined4 *)
                ((uint)*(byte *)(glContext + 0x85a8) * 4 + *(int *)(glContext + 0x5148) + 0x8054);
          if (*(int *)(levelRecord + 0xd8) != 0) {
            levelFlags = *(byte *)(levelRecord + 0xcf);
            if (((levelFlags & 1) == 0) && (*(short *)(textureObject + 0x3e) == -0x7a43)) {
              _gleFreeTextureLevel(glContext,textureObject,textureLevel);
              levelFlags = *(byte *)(levelRecord + 0xcf);
            }
            *(byte *)(levelRecord + 0xcf) = levelFlags & 0xef;
            *(ushort *)(iVar5 + textureObject + 0xa0) =
                 *(ushort *)(iVar5 + textureObject + 0xa0) &
                 ((ushort)(-2 << (level & 0x1f)) | (ushort)(0xfffffffe >> 0x20 - (level & 0x1f))
                 );
          }
          *(byte *)(levelRecord + 0xcf) = *(byte *)(levelRecord + 0xcf) | 0x40;
          if ((*(uint *)(textureObject + 0x6c) & 0x8000) == 0) {
            return;
          }
          if ((int)*(short *)(textureObject + 0x60) != level) {
            return;
          }
          nextLevel = level + 1;
          if ((int)(uint)*(byte *)(textureObject + 0x83) < (int)nextLevel) {
            return;
          }
          levelImageCursor = nextLevel * 0x18 + faceOffset + textureObject + 0xc4;
          do {
            if (*(int *)(levelImageCursor + 0x14) != 0) {
              if (((*(byte *)(levelImageCursor + 0xb) & 1) == 0) && (*(short *)(textureObject + 0x3e) == -0x7a43)) {
                _gleFreeTextureLevel(glContext,textureObject,levelImageCursor);
              }
              *(byte *)(levelImageCursor + 0xb) = *(byte *)(levelImageCursor + 0xb) & 0xef;
              *(ushort *)(iVar5 + textureObject + 0xa0) =
                   *(ushort *)(iVar5 + textureObject + 0xa0) & ~(ushort)(1 << (nextLevel & 0x3f));
            }
            nextLevel = nextLevel + 1;
            *(byte *)(levelImageCursor + 0xb) = *(byte *)(levelImageCursor + 0xb) | 0x40;
            levelImageCursor = levelImageCursor + 0x18;
          } while ((int)nextLevel <= (int)(uint)*(byte *)(textureObject + 0x83));
          return;
        }
        if (*(int *)(iVar9 + 0x40) != 0) {
          _gleSynchronizePluginBuffer(glContext,iVar9 + 0x10);
        }
      }
      if (((((int)level < (int)(uint)*(byte *)(textureObject + 0x8d)) ||
           ((int)(uint)*(byte *)(textureObject + 0x8f) < (int)level)) ||
          (iVar9 = faceIndex * 2, (*(ushort *)(iVar9 + textureObject + 0x94) >> (level & 0x3f) & 1) == 0)) ||
         (iVar5 = (**(code **)(glContext + 0x4710))
                            (*(undefined4 *)(glContext + 0x4688),
                             *(undefined4 *)(textureObject + (uint)*(byte *)(glContext + 0x85a8) * 4),faceIndex,
                             level,xoffset,yoffset,0,width), iVar5 == 0)) {
        levelFlags = *(byte *)(levelRecord + 0xcf);
        if ((levelFlags & 0x10) == 0) {
          if ((levelFlags & 0x40) == 0) {
            if (*(int *)(levelRecord + 0xd8) == 0) {
              _gleAllocateTextureLevel(glContext,textureObject,textureLevel);
              levelFlags = *(byte *)(levelRecord + 0xcf);
            }
            *(byte *)(levelRecord + 0xcf) = levelFlags | 0x10;
          }
          else {
            _gleUploadPluginTextureLevel
                      (glContext,textureObject,textureLevel,faceIndex,level,(uint)*(byte *)(glContext + 0x85a8));
          }
        }
        _gleModifyPluginTextureLevel
                  (glContext,textureObject,textureLevel,faceIndex,level,xoffset,yoffset,0,width,height,1);
        if (data != 0) {
          _gleCompressedTextureImagePut
                    (glContext,textureLevel,xoffset,yoffset,0,width,height,1,format,imageSize,data);
        }
        if ((((*(uint *)(textureObject + 0x6c) & 0x8000) == 0) || ((int)*(short *)(textureObject + 0x60) != level)
            ) || (iVar9 = _gleGenMipmapsToLevel(glContext,textureObject,faceIndex,level,0xf,1), iVar9 == 0)) {
          *(uint *)(glContext + 0x314) =
               *(uint *)(glContext + 0x314) | 1 << (*(uint *)(glContext + 0x53d4) & 0x3f);
        }
      }
      else {
        *(undefined4 *)(textureObject + 0x20) =
             *(undefined4 *)
              ((uint)*(byte *)(glContext + 0x85a8) * 4 + *(int *)(glContext + 0x5148) + 0x8054);
        if (*(int *)(levelRecord + 0xd8) != 0) {
          levelFlags = *(byte *)(levelRecord + 0xcf);
          if (((levelFlags & 1) == 0) && (*(short *)(textureObject + 0x3e) == -0x7a43)) {
            _gleFreeTextureLevel(glContext,textureObject,textureLevel);
            levelFlags = *(byte *)(levelRecord + 0xcf);
          }
          *(byte *)(levelRecord + 0xcf) = levelFlags & 0xef;
          *(ushort *)(iVar9 + textureObject + 0xa0) =
               *(ushort *)(iVar9 + textureObject + 0xa0) &
               ((ushort)(-2 << (level & 0x1f)) | (ushort)(0xfffffffe >> 0x20 - (level & 0x1f)));
        }
        *(byte *)(levelRecord + 0xcf) = *(byte *)(levelRecord + 0xcf) | 0x40;
        if ((((*(uint *)(textureObject + 0x6c) & 0x8000) != 0) && ((int)*(short *)(textureObject + 0x60) == level)
            ) && (faceIndex = level + 1, (int)faceIndex <= (int)(uint)*(byte *)(textureObject + 0x83))) {
          levelImageCursor2 = faceIndex * 0x18 + faceOffset + textureObject + 0xc4;
          do {
            if (*(int *)(levelImageCursor2 + 0x14) != 0) {
              if (((*(byte *)(levelImageCursor2 + 0xb) & 1) == 0) && (*(short *)(textureObject + 0x3e) == -0x7a43)) {
                _gleFreeTextureLevel(glContext,textureObject,levelImageCursor2);
              }
              *(byte *)(levelImageCursor2 + 0xb) = *(byte *)(levelImageCursor2 + 0xb) & 0xef;
              *(ushort *)(iVar9 + textureObject + 0xa0) =
                   *(ushort *)(iVar9 + textureObject + 0xa0) & ~(ushort)(1 << (faceIndex & 0x3f));
            }
            faceIndex = faceIndex + 1;
            *(byte *)(levelImageCursor2 + 0xb) = *(byte *)(levelImageCursor2 + 0xb) | 0x40;
            levelImageCursor2 = levelImageCursor2 + 0x18;
          } while ((int)faceIndex <= (int)(uint)*(byte *)(textureObject + 0x83));
        }
      }
    }
  }
  else {
LAB_000927a4:
    if (*(int *)(glContext + 0x7574) == 0) {
      *(undefined4 *)(glContext + 0x7574) = 0x502;
    }
  }
  return;
}

/* _glCompressedTexSubImage1D_Exec @ 0x92d4c (76 bytes) */
void _glCompressedTexSubImage1D_Exec(glContext, target, level, xoffset, width, format)
  int glContext;
  undefined4 target;
  undefined4 level;
  undefined4 xoffset;
  undefined4 width;
  uint format;
{
  undefined4 glErrorCode;
  
  if ((format < 0x83f0) || ((0x83f3 < format && (format != 0x8837)))) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
  }
  else {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x500;
  }
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glGetCompressedTexImage_Exec @ 0x92d98 (660 bytes) */
void _glGetCompressedTexImage_Exec(glContext, target, lod, img)
  int glContext;
  int target;
  uint lod;
  int img;
{
  byte levelFlags;
  undefined4 glErrorCode;
  undefined4 rowBytes;
  uint faceIndexThenHeight;
  int levelRecord;
  int textureObject;
  undefined4 *dstConvertDescPtrA;
  undefined4 *dstConvertDescPtrB;
  undefined1 *forwardedArg7;
  int *forwardedArg8;
  int packSettings;
  int pixelPackBuffer;
  undefined4 srcImagePtr;
  undefined4 srcRowBytes;
  undefined4 srcConvertDescA;
  undefined4 srcConvertDescB;
  int dstImagePtr;
  undefined4 dstRowBytes;
  undefined4 dstConvertDescA;
  undefined4 dstConvertDescB;
  undefined4 unitCount;
  uint packSwapBytes;
  undefined4 local_98;
  uint imageWidth;
  uint imageHeight;
  undefined1 processReserved;
  undefined4 packedRowBytes;
  undefined1 rowPadding [4];
  int imageBytes;
  undefined1 imagePadding [4];
  undefined1 packPixelBytes [4];
  int packOffset;
  undefined4 srcConvertDescAOut;
  undefined4 srcConvertDescBOut;
  undefined4 dstConvertDescAOut;
  undefined4 dstConvertDescBOut [4];
  
  textureObject = _gleLookUpNonProxyTexture(glContext,target);
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (textureObject == 0) {
      if (*(int *)(glContext + 0x7574) != 0) {
        return;
      }
      glErrorCode = 0x500;
      goto LAB_00092efc;
    }
    if (0xe < lod) {
      if (*(int *)(glContext + 0x7574) != 0) {
        return;
      }
      glErrorCode = 0x501;
      goto LAB_00092efc;
    }
    faceIndexThenHeight = target - 0x8515;
    if (5 < faceIndexThenHeight) {
      faceIndexThenHeight = 0;
    }
    levelRecord = textureObject + faceIndexThenHeight * 0x168 + lod * 0x18;
    levelFlags = *(byte *)(levelRecord + 0xcf);
    if ((levelFlags & 0x20) == 0) {
      return;
    }
    if ((((int)lod < (int)(uint)*(byte *)(textureObject + 0x8d)) ||
        ((int)(uint)*(byte *)(textureObject + 0x8f) < (int)lod)) || ((levelFlags & 0x40) == 0)) {
      if ((levelFlags & 0x10) == 0) {
        return;
      }
    }
    else {
      _gleUploadPluginTextureLevel
                (glContext,textureObject,levelRecord + 0xc4,faceIndexThenHeight,lod,(uint)*(byte *)(glContext + 0x85a8));
    }
    faceIndexThenHeight = (uint)*(ushort *)(levelRecord + 0xca);
    packSettings = glContext + 0x31b0;
    forwardedArg7 = packPixelBytes;
    forwardedArg8 = &packOffset;
    _glePixelPackSettings
              (glContext,(uint)*(ushort *)(textureObject + 0x78),0,(uint)*(ushort *)(levelRecord + 200),faceIndexThenHeight,packSettings
               ,forwardedArg7,forwardedArg8,&packedRowBytes,rowPadding,&imageBytes,imagePadding);
    pixelPackBuffer = *(int *)(glContext + 0x4a68);
    if (pixelPackBuffer == 0) {
LAB_00092f24:
      if ((((*(byte *)(levelRecord + 0xcf) & 1) != 0) && (img + packOffset == *(int *)(levelRecord + 0xd8)))
         && (*(short *)(levelRecord + 0xd6) == 0)) {
        return;
      }
      packSwapBytes = (uint)(*(char *)(glContext + 0x31c8) != '\0');
      rowBytes = _gleRowBytes((uint)*(ushort *)(levelRecord + 0xd4),(uint)*(ushort *)(levelRecord + 0xd6),
                           (uint)*(ushort *)(levelRecord + 0xd0));
      _glgConvertType((uint)*(ushort *)(levelRecord + 0xd4),(uint)*(ushort *)(levelRecord + 0xd6),&srcConvertDescAOut,
                      &srcConvertDescBOut,faceIndexThenHeight,packSettings,forwardedArg7,forwardedArg8);
      dstConvertDescPtrA = &dstConvertDescAOut;
      dstConvertDescPtrB = dstConvertDescBOut;
      _glgConvertType((uint)*(ushort *)(textureObject + 0x78),0,dstConvertDescPtrA,dstConvertDescPtrB,faceIndexThenHeight,packSettings,forwardedArg7,forwardedArg8);
      srcConvertDescA = srcConvertDescAOut;
      srcConvertDescB = srcConvertDescBOut;
      dstRowBytes = packedRowBytes;
      dstConvertDescA = dstConvertDescAOut;
      dstConvertDescB = dstConvertDescBOut[0];
      local_98 = 1;
      unitCount = 2;
      imageWidth = (uint)*(ushort *)(levelRecord + 200);
      imageHeight = (uint)*(ushort *)(levelRecord + 0xca);
      dstImagePtr = img + packOffset;
      srcImagePtr = *(undefined4 *)(levelRecord + 0xd8);
      processReserved = 0;
      srcRowBytes = rowBytes;
      _glgProcessPixels(glContext + 0x31a8,&srcImagePtr,dstConvertDescPtrA,dstConvertDescPtrB,faceIndexThenHeight,packSettings,imageHeight,forwardedArg8);
      return;
    }
    if (imageBytes + img <= *(int *)(pixelPackBuffer + 0x38)) {
      if (*(int *)(pixelPackBuffer + 0x40) != 0) {
        _gleSynchronizePluginBuffer(glContext,pixelPackBuffer + 0x10);
      }
      img = img + *(int *)(pixelPackBuffer + 0x30);
      goto LAB_00092f24;
    }
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  glErrorCode = 0x502;
LAB_00092efc:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glCompressedTexImage3D_CompExec @ 0x9302c (128 bytes) */
void _glCompressedTexImage3D_CompExec(glContext, target, level, internalformat, width, height, depth, border, imageSize, data)
  undefined4 glContext;
  undefined4 target;
  undefined4 level;
  undefined4 internalformat;
  undefined4 width;
  undefined4 height;
  undefined4 depth;
  undefined4 border;
  undefined4 imageSize;
  undefined4 data;
{
  ((int (*)())_glCompressedTexImage3D_Comp)(glContext,target,level,internalformat,width,height,depth,border,imageSize,data);
  ((int (*)())_glCompressedTexImage3D_Exec)(glContext,target,level,internalformat,width,height,depth,border,imageSize,data);
  return;
}

/* _glCompressedTexImage2D_CompExec @ 0x930ac (116 bytes) */
void _glCompressedTexImage2D_CompExec(glContext, target, level, internalformat, width, height, border, imageSize, data)
  undefined4 glContext;
  undefined4 target;
  undefined4 level;
  undefined4 internalformat;
  undefined4 width;
  undefined4 height;
  undefined4 border;
  undefined4 imageSize;
  undefined4 data;
{
  ((int (*)())_glCompressedTexImage2D_Comp)(glContext,target,level,internalformat,width,height,border,imageSize,data);
  ((int (*)())_glCompressedTexImage2D_Exec)(glContext,target,level,internalformat,width,height,border,imageSize,data);
  return;
}

/* _glCompressedTexImage1D_CompExec @ 0x93120 (104 bytes) */
void _glCompressedTexImage1D_CompExec(glContext, target, level, internalformat, width, border, imageSize, data)
  undefined4 glContext;
  undefined4 target;
  undefined4 level;
  undefined4 internalformat;
  undefined4 width;
  undefined4 border;
  undefined4 imageSize;
  undefined4 data;
{
  ((void (*)())_glCompressedTexImage1D_Comp)(glContext,target,level,internalformat);
  ((void (*)())_glCompressedTexImage1D_Exec)(glContext,target,level,internalformat);
  return;
}

/* _glCompressedTexSubImage3D_CompExec @ 0x93188 (152 bytes) */
void _glCompressedTexSubImage3D_CompExec(glContext, target, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, data)
  undefined4 glContext;
  undefined4 target;
  undefined4 level;
  undefined4 xoffset;
  undefined4 yoffset;
  undefined4 zoffset;
  undefined4 width;
  undefined4 height;
  undefined4 depth;
  undefined4 format;
  undefined4 imageSize;
  undefined4 data;
{
  ((int (*)())_glCompressedTexSubImage3D_Comp)(glContext,target,level,xoffset,yoffset,zoffset,width,height,depth,format,
             imageSize,data);
  ((int (*)())_glCompressedTexSubImage3D_Exec)(glContext,target,level,xoffset,yoffset,zoffset,width,height,depth,format,
             imageSize,data);
  return;
}

/* _glCompressedTexSubImage2D_CompExec @ 0x93220 (128 bytes) */
void _glCompressedTexSubImage2D_CompExec(glContext, target, level, xoffset, yoffset, width, height, format, imageSize, data)
  undefined4 glContext;
  undefined4 target;
  undefined4 level;
  undefined4 xoffset;
  undefined4 yoffset;
  undefined4 width;
  undefined4 height;
  undefined4 format;
  undefined4 imageSize;
  undefined4 data;
{
  ((int (*)())_glCompressedTexSubImage2D_Comp)(glContext,target,level,xoffset,yoffset,width,height,format,imageSize,data);
  ((int (*)())_glCompressedTexSubImage2D_Exec)(glContext,target,level,xoffset,yoffset,width,height,format,imageSize,data);
  return;
}

/* _glCompressedTexSubImage1D_CompExec @ 0x932a0 (104 bytes) */
void _glCompressedTexSubImage1D_CompExec(glContext, target, level, xoffset, width, format, imageSize, data)
  undefined4 glContext;
  undefined4 target;
  undefined4 level;
  undefined4 xoffset;
  undefined4 width;
  undefined4 format;
  undefined4 imageSize;
  undefined4 data;
{
  ((void (*)())_glCompressedTexSubImage1D_Comp)(glContext,target,level,xoffset,width,format);
  ((void (*)())_glCompressedTexSubImage1D_Exec)(glContext,target,level,xoffset,width,format);
  return;
}

/* _glTexCoord1_ListExec @ 0x93308 (36 bytes) */
int _glTexCoord1_ListExec(glContext, listRecord)
  int glContext;
  undefined4 *listRecord;
{
  *(undefined4 *)(glContext + 0x120) = *listRecord;
  *(undefined4 *)(glContext + 300) = *(undefined4 *)(glContext + 0x24);
  *(undefined4 *)(glContext + 0x128) = *(undefined4 *)(glContext + 0x20);
  *(undefined4 *)(glContext + 0x124) = *(undefined4 *)(glContext + 0x20);
  return 4;
}

/* _glTexCoord3_ListExec @ 0x9332c (52 bytes) */
int _glTexCoord3_ListExec(glContext, listRecord)
  int glContext;
  undefined4 *listRecord;
{
  undefined4 texCoordR;
  undefined4 texCoordS;
  undefined4 texCoordT;
  
  texCoordR = listRecord[2];
  texCoordS = *listRecord;
  texCoordT = listRecord[1];
  *(uint *)(glContext + 0x486c) = *(uint *)(glContext + 0x486c) | 1;
  *(undefined4 *)(glContext + 0x120) = texCoordS;
  *(undefined4 *)(glContext + 0x124) = texCoordT;
  *(undefined4 *)(glContext + 0x128) = texCoordR;
  *(undefined4 *)(glContext + 300) = *(undefined4 *)(glContext + 0x24);
  return 0xc;
}

/* _glTexCoord4_ListExec @ 0x93360 (52 bytes) */
int _glTexCoord4_ListExec(glContext, listRecord)
  int glContext;
  undefined4 *listRecord;
{
  undefined4 texCoordQ;
  undefined4 texCoordT;
  undefined4 texCoordR;
  
  texCoordQ = listRecord[3];
  texCoordT = listRecord[1];
  texCoordR = listRecord[2];
  *(undefined4 *)(glContext + 0x120) = *listRecord;
  *(uint *)(glContext + 0x486c) = *(uint *)(glContext + 0x486c) | 3;
  *(undefined4 *)(glContext + 0x124) = texCoordT;
  *(undefined4 *)(glContext + 0x128) = texCoordR;
  *(undefined4 *)(glContext + 300) = texCoordQ;
  return 0x10;
}

/* _glTexCoord1d_Exec @ 0x93394 (32 bytes) */
void _glTexCoord1d_Exec(int glContext,double sCoord)
{
  *(undefined4 *)(glContext + 0x128) = *(undefined4 *)(glContext + 0x20);
  *(float *)(glContext + 0x120) = (float)sCoord;
  *(undefined4 *)(glContext + 300) = *(undefined4 *)(glContext + 0x24);
  *(undefined4 *)(glContext + 0x124) = *(undefined4 *)(glContext + 0x20);
  return;
}

/* _glTexCoord1d_Comp @ 0x933b4 (88 bytes) */
float * _glTexCoord1d_Comp(undefined4 glContext,double sCoord)
{
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glTexCoord1_ListExec_001103c0,4);
  if (listRecord != (float *)0x0) {
    *listRecord = (float)sCoord;
  }
  return listRecord;
}

/* _glTexCoord1d_CompExec @ 0x9340c (64 bytes) */
void _glTexCoord1d_CompExec(undefined4 glContext,double sCoord)
{
  ((float * (*)())_glTexCoord1d_Comp)(glContext,sCoord);
  ((void (*)())_glTexCoord1d_Exec)(glContext,sCoord);
  return;
}

/* _glTexCoord1dv_Exec @ 0x9344c (36 bytes) */
void _glTexCoord1dv_Exec(glContext, v)
  int glContext;
  double *v;
{
  double texCoordS;
  
  texCoordS = *v;
  *(undefined4 *)(glContext + 0x128) = *(undefined4 *)(glContext + 0x20);
  *(undefined4 *)(glContext + 300) = *(undefined4 *)(glContext + 0x24);
  *(float *)(glContext + 0x120) = (float)texCoordS;
  *(undefined4 *)(glContext + 0x124) = *(undefined4 *)(glContext + 0x20);
  return;
}

/* _glTexCoord1dv_Comp @ 0x93470 (84 bytes) */
int _glTexCoord1dv_Comp(glContext, v)
  undefined4 glContext;
  double *v;
{
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glTexCoord1_ListExec_001103c0,4);
  if (listRecord != (float *)0x0) {
    *listRecord = (float)*v;
  }
  return listRecord;
}

/* _glTexCoord1dv_CompExec @ 0x934c4 (56 bytes) */
void _glTexCoord1dv_CompExec(glContext, v)
  undefined4 glContext;
  undefined4 v;
{
  ((int (*)())_glTexCoord1dv_Comp)(glContext,v);
  ((void (*)())_glTexCoord1dv_Exec)(glContext,v);
  return;
}

/* _glTexCoord2d_Exec @ 0x934fc (36 bytes) */
void _glTexCoord2d_Exec(int glContext,double sCoord,double t)
{
  *(undefined4 *)(glContext + 0x128) = *(undefined4 *)(glContext + 0x20);
  *(float *)(glContext + 0x120) = (float)sCoord;
  *(undefined4 *)(glContext + 300) = *(undefined4 *)(glContext + 0x24);
  *(float *)(glContext + 0x124) = (float)t;
  return;
}

/* _glTexCoord2d_Comp @ 0x93520 (108 bytes) */
float * _glTexCoord2d_Comp(undefined4 glContext,double sCoord,double t)
{
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glTexCoord2_ListExec_001103bc,8);
  if (listRecord != (float *)0x0) {
    *listRecord = (float)sCoord;
    listRecord[1] = (float)t;
  }
  return listRecord;
}

/* _glTexCoord2d_CompExec @ 0x9358c (80 bytes) */
void _glTexCoord2d_CompExec(undefined4 glContext,double sCoord,double t)
{
  ((float * (*)())_glTexCoord2d_Comp)(glContext,sCoord,t);
  ((void (*)())_glTexCoord2d_Exec)(glContext,sCoord,t);
  return;
}

/* _glTexCoord2dv_Exec @ 0x935dc (44 bytes) */
void _glTexCoord2dv_Exec(glContext, v)
  int glContext;
  double *v;
{
  double texCoordS;
  double texCoordT;
  
  texCoordT = v[1];
  texCoordS = *v;
  *(undefined4 *)(glContext + 0x128) = *(undefined4 *)(glContext + 0x20);
  *(undefined4 *)(glContext + 300) = *(undefined4 *)(glContext + 0x24);
  *(float *)(glContext + 0x120) = (float)texCoordS;
  *(float *)(glContext + 0x124) = (float)texCoordT;
  return;
}

/* _glTexCoord2dv_Comp @ 0x93608 (96 bytes) */
int _glTexCoord2dv_Comp(glContext, v)
  undefined4 glContext;
  double *v;
{
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glTexCoord2_ListExec_001103bc,8);
  if (listRecord != (float *)0x0) {
    *listRecord = (float)*v;
    listRecord[1] = (float)v[1];
  }
  return listRecord;
}

/* _glTexCoord2dv_CompExec @ 0x93668 (56 bytes) */
void _glTexCoord2dv_CompExec(glContext, v)
  undefined4 glContext;
  undefined4 v;
{
  ((int (*)())_glTexCoord2dv_Comp)(glContext,v);
  ((void (*)())_glTexCoord2dv_Exec)(glContext,v);
  return;
}

