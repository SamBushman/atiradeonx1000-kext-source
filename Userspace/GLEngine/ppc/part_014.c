#include "decls.h"

/* _glCopyPixels_NoopExec @ 0x6227c (672 bytes) */
void _glCopyPixels_NoopExec(int glContext,undefined4 x,undefined4 y,undefined4 width,undefined4 height,undefined4 type,double forwardedF1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
{
  int remaining;
  int loopIndex;
  bool rendererInfoByte79IsZero;
  bool noStateChangePending;
  char rendererInfoByte79;
  int *srcCursor;
  int dirtyBitArrayWord;
  int framebufferObject;
  undefined4 savedY;
  undefined4 savedWidth;
  undefined4 savedHeight;
  undefined4 savedType;
  int matrixChangeBits;
  uint dispatchFlags;
  uint changeWord3;
  int *changeWordCursor;
  double f1AfterCall;
  double f1AfterCall1;
  double f1AfterCall2;
  
  matrixChangeBits = *(int *)(glContext + 0x50ac);
  savedY = y;
  savedWidth = width;
  savedHeight = height;
  savedType = type;
  if (matrixChangeBits != 0 || (*(uint *)(glContext + 0x505c) & *(uint *)(glContext + 0x50b0)) != 0) {
    _gleUpdateMatrixFunc(glContext);
    forwardedF1 = f1AfterCall;
  }
  if (*(char *)(glContext + 0x4691) != '\0') {
    framebufferObject = *(int *)(glContext + 0x744c);
    changeWordCursor = (int *)(glContext + 0x310);
    rendererInfoByte79 = *(char *)(*(int *)(glContext + 0x468c) + 0x79);
    if ((framebufferObject != 0) && (*(int *)(framebufferObject + 0xec) != 0)) {
      ((void (*)())_gleUpdateFramebufferCompleteness)(glContext,framebufferObject + 0x10,savedY,savedWidth,savedHeight,savedType,matrixChangeBits,forwardedF1,forwardedFloatArg2,forwardedFloatArg3,
                 forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
      *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x80000000;
      forwardedF1 = forwardedF1;
    }
    if ((*(char *)(glContext + 0x4664) == '\0') && (*(int *)(glContext + 0x5430) == 0)) {
LAB_000623a4:
      changeWord3 = *(uint *)(glContext + 0x31c);
    }
    else {
      loopIndex = 0;
      srcCursor = (int *)(glContext + 0x324);
      do {
        dirtyBitArrayWord = *srcCursor;
        srcCursor = srcCursor + 1;
        if (dirtyBitArrayWord != 0) {
          *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x800000;
          break;
        }
        loopIndex = loopIndex + 1;
      } while (loopIndex < 9);
      changeWord3 = *(uint *)(glContext + 0x31c);
      if ((changeWord3 & 0x15555) != 0) {
        if (*(char *)(glContext + 0x2e54) != '\0') {
          forwardedF1 = (double)_gleUpdateLightRGBASums(glContext,glContext + 0x2c20,0);
        }
        if (*(char *)(glContext + 0x3094) != '\0') {
          forwardedF1 = (double)_gleUpdateLightRGBASums(glContext,glContext + 0x2e60,1);
        }
        goto LAB_000623a4;
      }
    }
    rendererInfoByte79IsZero = rendererInfoByte79 == '\0';
    if (rendererInfoByte79IsZero) {
      changeWord3 = changeWord3 & 0x17000000;
    }
    else {
      changeWord3 = changeWord3 & 0x17ffffff;
    }
    if (rendererInfoByte79IsZero) {
      noStateChangePending = ((*changeWordCursor == 0 && *(int *)(glContext + 0x314) == 0) && changeWord3 == 0) &&
              *(int *)(glContext + 800) == 0;
    }
    else {
      noStateChangePending = (((*changeWordCursor == 0 && *(int *)(glContext + 0x314) == 0) &&
               (*(uint *)(glContext + 0x318) & 0xfffffffd) == 0) && changeWord3 == 0) &&
              *(int *)(glContext + 800) == 0;
    }
    if (!noStateChangePending) {
      if (*(char *)(glContext + 0x85a8) == *(char *)(glContext + 0x85a6)) {
        dispatchFlags = (**(code **)(glContext + 0x4788))
                           (*(undefined4 *)(glContext + 0x4688),glContext + 0x4698,changeWordCursor);
        if ((((dispatchFlags & 3) != (uint)*(byte *)(glContext + 0x7580)) ||
            ((dispatchFlags & 4) != (uint)*(byte *)(glContext + 0x7581))) ||
           (forwardedF1 = f1AfterCall2, (dispatchFlags & 8) != (uint)(*(char *)(glContext + 0x759d) == '\0')))
        {
          if ((dispatchFlags & 4) == 0) {
            dispatchFlags = dispatchFlags & 0xfffffffe;
            *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x10000000;
          }
          forwardedF1 = (double)_gleUpdateDispatchCodeChange(glContext,dispatchFlags);
          if (*(char *)(glContext + 0x759d) == '\0') goto LAB_000624c4;
        }
      }
      else {
        forwardedF1 = (double)_gleSwitchToNonRevertRenderer(glContext);
      }
      remaining = 0x13;
      do {
        *changeWordCursor = 0;
        changeWordCursor = changeWordCursor + 1;
        remaining = remaining + -1;
      } while (remaining != 0);
    }
  }
  if (*(char *)(glContext + 0x759d) != '\0') {
    ((void (*)())_glCopyPixels_Exec)(glContext,x,y,width,height,type,forwardedF1,forwardedFloatArg2,forwardedFloatArg3,
                       forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
    return;
  }
LAB_000624c4:
  if (*(int *)(glContext + 0x7574) == 0) {
    *(undefined4 *)(glContext + 0x7574) = 0x506;
  }
  return;
}

/* _glDepthFunc_ListExec @ 0x6251c (40 bytes) */
int _glDepthFunc_ListExec(glContext, recordedArgs)
  undefined4 glContext;
  undefined4 *recordedArgs;
{
  _glDepthFunc_Exec(glContext,*recordedArgs);
  return 4;
}

/* _glDepthFunc_Comp @ 0x62544 (76 bytes) */
int _glDepthFunc_Comp(glContext, func)
  undefined4 glContext;
  undefined4 func;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glDepthFunc_ListExec_00110090,4);
  if (listRecord != (undefined4 *)0x0) {
    *listRecord = func;
  }
  return listRecord;
}

/* _glDepthFunc_CompExec @ 0x62590 (56 bytes) */
void _glDepthFunc_CompExec(glContext, func)
  undefined4 glContext;
  undefined4 func;
{
  ((int (*)())_glDepthFunc_Comp)(glContext,func);
  _glDepthFunc_Exec(glContext,func);
  return;
}

/* _glDepthRange_ListExec @ 0x625c8 (44 bytes) */
undefined4 _glDepthRange_ListExec(undefined4 glContext,double *recordedArgs,double unusedFloatArg1,double unusedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  double incomingStack_ffffffb8;
  double incomingStack_ffffffc0;
  double incomingStack_ffffffc8;
  double incomingStack_ffffffd0;
  double incomingStack_ffffffd8;
  
  ((void (*)())_glDepthRange_Exec)(glContext,*recordedArgs,recordedArgs[1],forwardedFloatArg3,forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,
                     forwardedFloatArg8,incomingStack_ffffffb8,incomingStack_ffffffc0,incomingStack_ffffffc8,
                     incomingStack_ffffffd0,incomingStack_ffffffd8);
  return 0x10;
}

/* _glDepthRange_Comp @ 0x625f4 (100 bytes) */
double * _glDepthRange_Comp(undefined4 glContext,double zNear,double zFar)
{
  double *listRecord;
  
  listRecord = (double *)_gleAddListItem(glContext,PTR__glDepthRange_ListExec_0011008c,0x10);
  if (listRecord != (double *)0x0) {
    listRecord[1] = zFar;
    *listRecord = zNear;
  }
  return listRecord;
}

/* _glDepthRange_Exec @ 0x62658 (320 bytes) */
void _glDepthRange_Exec(int glContext,double zNear,double zFar,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8,double forwardedFloatArg9,double forwardedFloatArg10,double forwardedFloatArg11,double forwardedFloatArg12,double forwardedFloatArg13)
{
  double doubleZero;
  byte dirtyBitIndex;
  uint clampedZNearHighWord;
  int dirtyWordAddress324;
  int dirtyWordAddress348;
  int glContextPtr5424;
  double dVar5;
  
  if (-1 < *(short *)(glContext + 0x4a10)) {
    if (*(int *)(glContext + 0x7574) == 0) {
      *(undefined4 *)(glContext + 0x7574) = 0x502;
      return;
    }
    return;
  }
  if (zNear < DOUBLE_00108d60) {
    clampedZNearHighWord = 0;
  }
  else {
    dVar5 = zNear;
    if (!(DOUBLE_00108d68 < zNear)) goto LAB_000626d0;
    clampedZNearHighWord = 0x3ff00000;
  }
  dVar5 = GH_U2D((unsigned long long)clampedZNearHighWord << 0x20);
LAB_000626d0:
  *(double *)(glContext + 0x1b90) = dVar5;
  doubleZero = DOUBLE_00108d60;
  if ((zFar < DOUBLE_00108d60) || (dVar5 = DOUBLE_00108d68, DOUBLE_00108d68 < zFar)) {
    zFar = dVar5;
  }
  *(double *)(glContext + 0x1b98) = zFar;
  *(float *)(glContext + 0x1bb4) = (float)zFar;
  *(float *)(glContext + 0x1bb0) = (float)*(double *)(glContext + 0x1b90);
  *(float *)(glContext + 0x1bb8) = (float)zFar - (float)*(double *)(glContext + 0x1b90);
  if (*(int *)(glContext + 0x5434) == 0) {
    dirtyBitIndex = *(byte *)(*(int *)(glContext + 0x5420) + 0x327);
  }
  else {
    dirtyBitIndex = *(byte *)(*(int *)(*(int *)(glContext + 0x5430) + 0x20) + 0x35b);
  }
  dirtyWordAddress324 = (dirtyBitIndex >> 3 & 0x1c) + glContext;
  glContextPtr5424 = *(int *)(glContext + 0x5424);
  *(uint *)(dirtyWordAddress324 + 0x324) = *(uint *)(dirtyWordAddress324 + 0x324) | 1 << (dirtyBitIndex & 0x1f);
  dirtyBitIndex = *(byte *)(glContextPtr5424 + 0x327);
  dirtyWordAddress348 = (dirtyBitIndex >> 3 & 0x1c) + glContext;
  *(uint *)(dirtyWordAddress348 + 0x348) = *(uint *)(dirtyWordAddress348 + 0x348) | 1 << (dirtyBitIndex & 0x1f);
  *(uint *)(glContext + 0x318) = *(uint *)(glContext + 0x318) | 1;
  ((void (*)())_gleUpdateDepthRangeData)(glContext,zNear,zFar,forwardedFloatArg3,forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8,
             forwardedFloatArg9,forwardedFloatArg10,forwardedFloatArg11,forwardedFloatArg12,forwardedFloatArg13);
  return;
}

/* _glDepthRange_CompExec @ 0x62798 (80 bytes) */
void _glDepthRange_CompExec(undefined4 glContext,double zNear,double zFar)
{
  undefined4 in_LR;
  double incomingFpr3;
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  
  ((double * (*)())_glDepthRange_Comp)(glContext,zNear,zFar);
  ((void (*)())_glDepthRange_Exec)(glContext,zNear,zFar,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,
                     (double)CONCAT44(in_LR,(*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0xc))),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),
                     (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
  return;
}

/* _glDepthBoundsEXT_ListExec @ 0x627e8 (44 bytes) */
int _glDepthBoundsEXT_ListExec(glContext, recordedArgs)
  undefined4 glContext;
  double *recordedArgs;
{
  ((void (*)())_glDepthBoundsEXT_Exec)(glContext,*recordedArgs,recordedArgs[1]);
  return 0x10;
}

/* _glDepthBoundsEXT_Comp @ 0x62814 (100 bytes) */
double * _glDepthBoundsEXT_Comp(undefined4 glContext,double zNear,double zFar)
{
  double *listRecord;
  
  listRecord = (double *)_gleAddListItem(glContext,PTR__glDepthBoundsEXT_ListExec_00110088,0x10);
  if (listRecord != (double *)0x0) {
    listRecord[1] = zFar;
    *listRecord = zNear;
  }
  return listRecord;
}

/* _glDepthBoundsEXT_Exec @ 0x62878 (212 bytes) */
void _glDepthBoundsEXT_Exec(int glContext,double zNear,double zFar)
{
  uint uVar1;
  
  if (-1 < *(short *)(glContext + 0x4a10)) {
    if (*(int *)(glContext + 0x7574) == 0) {
      *(undefined4 *)(glContext + 0x7574) = 0x502;
      return;
    }
    return;
  }
  if (zNear < DOUBLE_00108d60) {
    uVar1 = 0;
LAB_000628d8:
    zNear = GH_U2D((unsigned long long)uVar1 << 0x20);
  }
  else if (DOUBLE_00108d68 < zNear) {
    uVar1 = 0x3ff00000;
    goto LAB_000628d8;
  }
  *(double *)(glContext + 0x312c) = zNear;
  if (zFar < DOUBLE_00108d60) {
    uVar1 = 0;
  }
  else {
    if (!(DOUBLE_00108d68 < zFar)) goto LAB_00062934;
    uVar1 = 0x3ff00000;
  }
  zFar = GH_U2D((unsigned long long)uVar1 << 0x20);
LAB_00062934:
  *(double *)(glContext + 0x3134) = zFar;
  *(uint *)(glContext + 0x318) = *(uint *)(glContext + 0x318) | 1;
  return;
}

/* _glDepthBoundsEXT_CompExec @ 0x6294c (80 bytes) */
void _glDepthBoundsEXT_CompExec(undefined4 glContext,double zNear,double zFar)
{
  ((double * (*)())_glDepthBoundsEXT_Comp)(glContext,zNear,zFar);
  ((void (*)())_glDepthBoundsEXT_Exec)(glContext,zNear,zFar);
  return;
}

/* _glCallList_ListExec @ 0x6299c (40 bytes) */
int _glCallList_ListExec(glContext, recordedArgs)
  undefined4 glContext;
  undefined4 *recordedArgs;
{
  _glCallList_Exec(glContext,*recordedArgs);
  return 4;
}

/* _glCallList_Comp @ 0x629c4 (76 bytes) */
int _glCallList_Comp(glContext, list)
  undefined4 glContext;
  undefined4 list;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glCallList_ListExec_0011009c,4);
  if (listRecord != (undefined4 *)0x0) {
    *listRecord = list;
  }
  return listRecord;
}

/* _glCallList_CompExec @ 0x62a10 (56 bytes) */
void _glCallList_CompExec(glContext, list)
  undefined4 glContext;
  undefined4 list;
{
  ((int (*)())_glCallList_Comp)(glContext,list);
  _glCallList_Exec(glContext,list);
  return;
}

/* _glCallLists_ListExec @ 0x62a48 (64 bytes) */
int _glCallLists_ListExec(glContext, recordedArgs)
  undefined4 glContext;
  undefined4 *recordedArgs;
{
  ((void (*)())_glCallLists_Exec)(glContext,*recordedArgs,recordedArgs[2],recordedArgs + 3);
  return recordedArgs[1] + 0xc;
}

/* _glCallLists_Comp @ 0x62a88 (164 bytes) */
int _glCallLists_Comp(glContext, n, type, lists)
  undefined4 glContext;
  int n;
  int type;
  undefined4 lists;
{
  uint uVar1;
  int typeSize;
  int *listRecord;
  undefined4 uVar4;
  
  typeSize = _gleTypeSize(glContext,type);
  uVar1 = n * typeSize + 3U & 0xfffffffc;
  listRecord = (int *)_gleAddListItem(glContext,PTR__glCallLists_ListExec_00110098,uVar1 + 0xc);
  if (listRecord != (int *)0x0) {
    *listRecord = n;
    listRecord[2] = type;
    listRecord[1] = uVar1;
    uVar4 = _gleCopy(lists,listRecord + 3,n * typeSize,1,0,0);
    return uVar4;
  }
  return 0;
}

/* _glCallLists_Exec @ 0x62b2c (764 bytes) */
void _glCallLists_Exec(glContext, n, type, lists)
  int glContext;
  int n;
  undefined4 type;
  float *lists;
{
  int loopIndex3;
  int loopIndex2;
  int loopIndex;
  byte *pbVar1;
  short sVar2;
  ushort uVar3;
  double twoPow31;
  float fVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  float dVar9;
  
  twoPow31 = DOUBLE_00108d80;
  switch(type) {
  case 0x1400:
    loopIndex = 0;
    if (0 < n) {
      do {
        pbVar1 = (byte *)((int)lists + loopIndex);
        loopIndex = loopIndex + 1;
        _gleCallList(glContext,(int)(char)*pbVar1 + *(int *)(glContext + 0x5404));
      } while (loopIndex < n);
    }
    break;
  case 0x1401:
    loopIndex2 = 0;
    if (0 < n) {
      do {
        pbVar1 = (byte *)((int)lists + loopIndex2);
        loopIndex2 = loopIndex2 + 1;
        _gleCallList(glContext,(uint)*pbVar1 + *(int *)(glContext + 0x5404));
      } while (loopIndex2 < n);
    }
    break;
  case 0x1402:
    if (0 < n) {
      do {
        sVar2 = *(short *)lists;
        lists = (float *)((int)lists + 2);
        _gleCallList(glContext,(int)sVar2 + *(int *)(glContext + 0x5404));
        n = n + -1;
      } while (n != 0);
    }
    break;
  case 0x1403:
    if (0 < n) {
      do {
        uVar3 = *(ushort *)lists;
        lists = (float *)((int)lists + 2);
        _gleCallList(glContext,(uint)uVar3 + *(int *)(glContext + 0x5404));
        n = n + -1;
      } while (n != 0);
    }
    break;
  case 0x1404:
    if (0 < n) {
      do {
        iVar7 = *(int *)lists;
        lists = lists + 1;
        _gleCallList(glContext,iVar7 + *(int *)(glContext + 0x5404));
        n = n + -1;
      } while (n != 0);
    }
    break;
  case 0x1405:
    if (0 < n) {
      do {
        iVar7 = *(int *)lists;
        lists = lists + 1;
        _gleCallList(glContext,iVar7 + *(int *)(glContext + 0x5404));
        n = n + -1;
      } while (n != 0);
    }
    break;
  case 0x1406:
    if (0 < n) {
      do {
        fVar5 = *lists;
        dVar9 = (double)fVar5;
        lists = lists + 1;
        if (twoPow31 <= (double)dVar9) {
          uVar6 = (int)((double)dVar9 - twoPow31) ^ 0x80000000;
        }
        else {
          uVar6 = (uint)(int)fVar5;
        }
        _gleCallList(glContext,uVar6 + *(int *)(glContext + 0x5404));
        n = n + -1;
      } while (n != 0);
    }
    break;
  case 0x1407:
    loopIndex3 = 0;
    if (0 < n << 1) {
      do {
        loopIndex3 = loopIndex3 + 2;
        _gleCallList(glContext,(uint)*(byte *)lists * 0x100 + (uint)*(byte *)((int)lists + 1) +
                             *(int *)(glContext + 0x5404));
        lists = (float *)((int)lists + 2);
      } while (loopIndex3 < n << 1);
    }
    break;
  case 0x1408:
    iVar7 = 0;
    if (0 < n * 3) {
      do {
        iVar8 = iVar7 + 3;
        _gleCallList(glContext,(uint)*(byte *)((int)lists + iVar7) * 0x10000 +
                             (uint)*(byte *)((int)lists + iVar7 + 1) * 0x100 +
                             (uint)*(byte *)((int)lists + iVar7 + 2) + *(int *)(glContext + 0x5404))
        ;
        iVar7 = iVar8;
      } while (iVar8 < n * 3);
    }
    break;
  case 0x1409:
    iVar7 = 0;
    if (0 < n << 2) {
      do {
        iVar8 = iVar7 + 4;
        _gleCallList(glContext,(uint)*(byte *)((int)lists + iVar7) * 0x1000000 +
                             (uint)*(byte *)((int)lists + iVar7 + 1) * 0x10000 +
                             (uint)*(byte *)((int)lists + iVar7 + 2) * 0x100 +
                             (uint)*(byte *)((int)lists + iVar7 + 3) + *(int *)(glContext + 0x5404))
        ;
        iVar7 = iVar8;
      } while (iVar8 < n << 2);
    }
    break;
  default:
    if (*(int *)(glContext + 0x7574) == 0) {
      *(undefined4 *)(glContext + 0x7574) = 0x500;
    }
  }
  return;
}

/* _glCallLists_CompExec @ 0x62e50 (72 bytes) */
void _glCallLists_CompExec(glContext, n, type, lists)
  undefined4 glContext;
  undefined4 n;
  undefined4 type;
  undefined4 lists;
{
  ((int (*)())_glCallLists_Comp)(glContext,n,type,lists);
  ((void (*)())_glCallLists_Exec)(glContext,n,type,lists);
  return;
}

/* _glIsList_Exec @ 0x62e98 (80 bytes) */
int _glIsList_Exec(glContext, list)
  int glContext;
  undefined4 list;
{
  undefined4 uVar1;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    uVar1 = _gleIsHashName(*(int *)(glContext + 0x5148) + 0x300c,list);
  }
  else {
    if (*(int *)(glContext + 0x7574) == 0) {
      *(undefined4 *)(glContext + 0x7574) = 0x502;
    }
    uVar1 = 0;
  }
  return uVar1;
}

/* _glListBase_ListExec @ 0x62ee8 (40 bytes) */
int _glListBase_ListExec(glContext, recordedArgs)
  undefined4 glContext;
  undefined4 *recordedArgs;
{
  ((void (*)())_glListBase_Exec)(glContext,*recordedArgs);
  return 4;
}

/* _glListBase_Comp @ 0x62f10 (76 bytes) */
int _glListBase_Comp(glContext, base)
  undefined4 glContext;
  undefined4 base;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glListBase_ListExec_00110094,4);
  if (listRecord != (undefined4 *)0x0) {
    *listRecord = base;
  }
  return listRecord;
}

/* _glListBase_Exec @ 0x62f5c (44 bytes) */
void _glListBase_Exec(glContext, base)
  int glContext;
  undefined4 base;
{
  if (*(short *)(glContext + 0x4a10) < 0) {
    *(undefined4 *)(glContext + 0x5404) = base;
    return;
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  *(undefined4 *)(glContext + 0x7574) = 0x502;
  return;
}

/* _glListBase_CompExec @ 0x62f88 (56 bytes) */
void _glListBase_CompExec(glContext, base)
  undefined4 glContext;
  undefined4 base;
{
  ((int (*)())_glListBase_Comp)(glContext,base);
  ((void (*)())_glListBase_Exec)(glContext,base);
  return;
}

/* _glDrawBuffer_ListExec @ 0x62fc0 (40 bytes) */
int _glDrawBuffer_ListExec(glContext, recordedArgs, forwardedArg3, forwardedArg4, forwardedArg5, forwardedArg6, forwardedArg7)
  undefined4 glContext;
  undefined4 *recordedArgs;
  undefined4 forwardedArg3;
  undefined4 forwardedArg4;
  undefined4 forwardedArg5;
  undefined4 forwardedArg6;
  undefined4 forwardedArg7;
{
  ((void (*)())_glDrawBuffer_Exec)(glContext,*recordedArgs,forwardedArg3,forwardedArg4,forwardedArg5,forwardedArg6,forwardedArg7);
  return 4;
}

/* _glDrawBuffer_Comp @ 0x62fe8 (76 bytes) */
int _glDrawBuffer_Comp(glContext, mode)
  undefined4 glContext;
  undefined4 mode;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glDrawBuffer_ListExec_001100a4,4);
  if (listRecord != (undefined4 *)0x0) {
    *listRecord = mode;
  }
  return listRecord;
}

/* _glDrawBuffer_Exec @ 0x63034 (472 bytes) */
void _glDrawBuffer_Exec(glContext, mode, unusedArg3, unusedArg4, unusedArg5, unusedArg6, unusedArg7)
  int glContext;
  uint mode;
  undefined4 unusedArg3;
  undefined4 unusedArg4;
  undefined4 unusedArg5;
  undefined4 unusedArg6;
  undefined4 unusedArg7;
{
  int loopIndex;
  int remaining;
  bool bVar1;
  char cVar2;
  int slotByteOffset;
  undefined4 glErrorCode;
  undefined2 *dstCursor;
  int framebufferObject;
  int remaining2;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (mode == 0x404) {
LAB_000630bc:
      if (*(int *)(glContext + 0x744c) == 0) {
        framebufferObject = 0;
        goto LAB_00063184;
      }
    }
    else {
      if (mode < 0x405) {
        if (mode == 0x401) goto LAB_000630e0;
        if (mode < 0x402) {
          if (mode == 0) {
            framebufferObject = *(int *)(glContext + 0x744c);
            goto LAB_00063184;
          }
          bVar1 = mode == 0x400;
LAB_000630a0:
          if (!bVar1) goto LAB_0006313c;
          goto LAB_000630bc;
        }
        if (mode == 0x402) goto LAB_000630cc;
        if (mode != 0x403) goto LAB_0006313c;
        if ((*(int *)(glContext + 0x744c) != 0) || (*(char *)(glContext + 0x7582) == '\0'))
        goto LAB_000631f8;
LAB_000630ec:
        cVar2 = *(char *)(*(int *)(glContext + 0x468c) + 0x26);
LAB_000630f4:
        framebufferObject = 0;
        bVar1 = cVar2 == '\0';
      }
      else {
        if (mode == 0x407) {
LAB_000630e0:
          if (*(int *)(glContext + 0x744c) != 0) goto LAB_000631f8;
          goto LAB_000630ec;
        }
        if (mode < 0x408) {
          if (mode != 0x405) {
            bVar1 = mode == 0x406;
            goto LAB_000630a0;
          }
LAB_000630cc:
          if (*(int *)(glContext + 0x744c) != 0) goto LAB_000631f8;
          cVar2 = *(char *)(glContext + 0x7582);
          goto LAB_000630f4;
        }
        if (mode == 0x408) goto LAB_000630bc;
        if (mode < 0x40d) {
          if ((*(int *)(glContext + 0x744c) == 0) &&
             (mode < *(int *)(*(int *)(glContext + 0x468c) + 0x54) + 0x409U)) {
            framebufferObject = 0;
            goto LAB_00063184;
          }
          goto LAB_000631f8;
        }
LAB_0006313c:
        if (((int)(mode - 0x8ce0) < 0) ||
           (*(uint *)(*(int *)(glContext + 0x468c) + 0x18) <= mode - 0x8ce0)) {
          if (*(int *)(glContext + 0x7574) != 0) {
            return;
          }
          glErrorCode = 0x500;
          goto LAB_00063168;
        }
        framebufferObject = *(int *)(glContext + 0x744c);
        bVar1 = framebufferObject == 0;
      }
      if (!bVar1) {
LAB_00063184:
        if (framebufferObject == 0) {
          *(short *)(glContext + 0x311a) = (short)mode;
          remaining = 3;
          dstCursor = (undefined2 *)(glContext + 0x311c);
          do {
            *dstCursor = 0;
            dstCursor = dstCursor + 1;
            remaining = remaining + -1;
          } while (remaining != 0);
        }
        else {
          *(short *)(framebufferObject + 0xc0) = (short)mode;
          remaining2 = 3;
          loopIndex = 1;
          do {
            slotByteOffset = loopIndex * 2;
            loopIndex = loopIndex + 1;
            *(undefined2 *)(slotByteOffset + *(int *)(glContext + 0x744c) + 0xc0) = 0;
            remaining2 = remaining2 + -1;
          } while (remaining2 != 0);
          *(undefined4 *)(*(int *)(glContext + 0x744c) + 0xec) = 1;
        }
        *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x80;
        return;
      }
    }
  }
LAB_000631f8:
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  glErrorCode = 0x502;
LAB_00063168:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glDrawBuffer_CompExec @ 0x6320c (56 bytes) */
void _glDrawBuffer_CompExec(glContext, mode)
  undefined4 glContext;
  undefined4 mode;
{
  undefined4 incomingR5;
  undefined4 incomingR6;
  undefined4 incomingR7;
  undefined4 incomingR8;
  undefined4 incomingR9;
  
  ((int (*)())_glDrawBuffer_Comp)(glContext,mode);
  ((void (*)())_glDrawBuffer_Exec)(glContext,mode,incomingR5,incomingR6,incomingR7,incomingR8,incomingR9);
  return;
}

/* _glDrawBuffersARB_ListExec @ 0x63244 (48 bytes) */
int _glDrawBuffersARB_ListExec(glContext, recordedArgs)
  undefined4 glContext;
  undefined4 *recordedArgs;
{
  ((void (*)())_glDrawBuffersARB_Exec)(glContext,*recordedArgs,recordedArgs + 1);
  return 0x14;
}

/* _glDrawBuffersARB_Comp @ 0x63274 (152 bytes) */
int _glDrawBuffersARB_Comp(glContext, n, bufs)
  int *glContext;
  int n;
  int *bufs;
{
  int iVar1;
  
  if (n < 5) {
    glContext = (int *)_gleAddListItem(glContext,PTR__glDrawBuffersARB_ListExec_001100a0,0x14);
    if ((glContext != (int *)0x0) && (*glContext = n, 0 < n)) {
      glContext = glContext + 1;
      do {
        iVar1 = *bufs;
        bufs = bufs + 1;
        *glContext = iVar1;
        glContext = glContext + 1;
        n = n + -1;
      } while (n != 0);
    }
  }
  else if (glContext[0x1d5d] == 0) {
    glContext[0x1d5d] = 0x502;
  }
  return glContext;
}

/* _glDrawBuffersARB_Exec @ 0x6330c (652 bytes) */
void _glDrawBuffersARB_Exec(glContext, n, bufs)
  int glContext;
  int n;
  int *bufs;
{
  int loopIndex2;
  int loopIndex;
  undefined2 bufferEnumLow16;
  int framebufferZeroOffset;
  undefined4 glErrorCode;
  int *cursor;
  undefined2 *dstCursor;
  undefined2 *srcCursor;
  undefined2 *srcCursor2;
  uint loopIndex3;
  int dupCheckIndexThenRendererInfo;
  int contextZeroOffset;
  uint colorAttachmentIndex;
  int fillIndex;
  int remaining;
  int framebufferObject;
  
  loopIndex3 = 0;
  if ((-1 < *(short *)(glContext + 0x4a10)) || (4 < n)) {
LAB_000635b8:
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
LAB_000634a0:
    *(undefined4 *)(glContext + 0x7574) = glErrorCode;
    return;
  }
  loopIndex = 0;
  if (0 < n) {
    do {
      if (bufs[loopIndex] == 0) goto LAB_000634c4;
      dupCheckIndexThenRendererInfo = 0;
      cursor = bufs;
      if (0 < loopIndex) {
        do {
          if (bufs[loopIndex] == *cursor) goto LAB_000635b8;
          dupCheckIndexThenRendererInfo = dupCheckIndexThenRendererInfo + 1;
          cursor = cursor + 1;
        } while (dupCheckIndexThenRendererInfo < loopIndex);
      }
      switch(bufs[loopIndex]) {
      case 0x400:
      case 0x404:
      case 0x406:
      case 0x408:
        if (*(int *)(glContext + 0x744c) == 0) goto LAB_00063408;
        goto LAB_000635b8;
      case 0x401:
      case 0x407:
        if (*(int *)(glContext + 0x744c) == 0) goto LAB_00063438;
        goto LAB_000635b8;
      case 0x402:
      case 0x405:
        if ((*(int *)(glContext + 0x744c) != 0) || (*(char *)(glContext + 0x7582) == '\0'))
        goto LAB_000635b8;
LAB_00063408:
        dupCheckIndexThenRendererInfo = *(int *)(glContext + 0x468c);
        break;
      case 0x403:
        if ((*(int *)(glContext + 0x744c) != 0) || (*(char *)(glContext + 0x7582) == '\0'))
        goto LAB_000635b8;
LAB_00063438:
        dupCheckIndexThenRendererInfo = *(int *)(glContext + 0x468c);
        if (*(char *)(dupCheckIndexThenRendererInfo + 0x26) == '\0') goto LAB_000635b8;
        break;
      case 0x409:
      case 0x40a:
      case 0x40b:
      case 0x40c:
        if ((*(int *)(glContext + 0x744c) != 0) ||
           (dupCheckIndexThenRendererInfo = *(int *)(glContext + 0x468c),
           *(int *)(dupCheckIndexThenRendererInfo + 0x54) + 0x409U <= (uint)bufs[loopIndex])) goto LAB_000635b8;
        break;
      default:
        colorAttachmentIndex = bufs[loopIndex] - 0x8ce0;
        if (((int)colorAttachmentIndex < 0) ||
           (dupCheckIndexThenRendererInfo = *(int *)(glContext + 0x468c), *(uint *)(dupCheckIndexThenRendererInfo + 0x18) <= colorAttachmentIndex)) {
          if (*(int *)(glContext + 0x7574) != 0) {
            return;
          }
          glErrorCode = 0x500;
          goto LAB_000634a0;
        }
        if (*(int *)(glContext + 0x744c) == 0) goto LAB_000635b8;
        loopIndex3 = loopIndex3 + 1;
      }
      if (*(uint *)(dupCheckIndexThenRendererInfo + 0x14) <= loopIndex3) goto LAB_000635b8;
LAB_000634c4:
      loopIndex = loopIndex + 1;
    } while (loopIndex < n);
  }
  framebufferObject = *(int *)(glContext + 0x744c);
  if (framebufferObject == 0) {
    fillIndex = 0;
    if (0 < n) {
      srcCursor2 = (undefined2 *)((int)bufs + 2);
      dstCursor = (undefined2 *)(glContext + 0x311a);
      remaining = n;
      do {
        bufferEnumLow16 = *srcCursor2;
        srcCursor2 = srcCursor2 + 2;
        *dstCursor = bufferEnumLow16;
        dstCursor = dstCursor + 1;
        remaining = remaining + -1;
      } while (remaining != 0);
      fillIndex = n;
      if (3 < n) goto LAB_000635a8;
    }
    do {
      contextZeroOffset = fillIndex * 2;
      fillIndex = fillIndex + 1;
      *(undefined2 *)(contextZeroOffset + glContext + 0x311a) = 0;
    } while (fillIndex < 4);
    goto LAB_000635a8;
  }
  loopIndex2 = 0;
  if (n < 1) {
LAB_00063528:
    while( true ) {
      framebufferZeroOffset = loopIndex2 * 2;
      loopIndex2 = loopIndex2 + 1;
      *(undefined2 *)(framebufferZeroOffset + framebufferObject + 0xc0) = 0;
      if (3 < loopIndex2) break;
      framebufferObject = *(int *)(glContext + 0x744c);
    }
    framebufferObject = *(int *)(glContext + 0x744c);
  }
  else {
    srcCursor = (undefined2 *)((int)bufs + 2);
    while( true ) {
      bufferEnumLow16 = *srcCursor;
      srcCursor = srcCursor + 2;
      *(undefined2 *)(loopIndex2 * 2 + framebufferObject + 0xc0) = bufferEnumLow16;
      loopIndex2 = loopIndex2 + 1;
      n = n + -1;
      if (n == 0) break;
      framebufferObject = *(int *)(glContext + 0x744c);
    }
    framebufferObject = *(int *)(glContext + 0x744c);
    if (loopIndex2 < 4) goto LAB_00063528;
  }
  *(undefined4 *)(framebufferObject + 0xec) = 1;
LAB_000635a8:
  *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x80;
  return;
}

/* _glDrawBuffersARB_CompExec @ 0x635cc (64 bytes) */
void _glDrawBuffersARB_CompExec(glContext, n, bufs)
  undefined4 glContext;
  undefined4 n;
  undefined4 bufs;
{
  ((int (*)())_glDrawBuffersARB_Comp)(glContext,n,bufs);
  ((void (*)())_glDrawBuffersARB_Exec)(glContext,n,bufs);
  return;
}

/* _glDrawPixels_ListExec @ 0x6360c (1320 bytes) */
int _glDrawPixels_ListExec(int glContext,uint *recordedArgs,double forwardedFloatArg1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
{
  int remaining;
  int loopIndex;
  bool formatInvalid;
  bool rendererByte79Clear;
  bool noStateChangePending;
  char rendererInfoByte79;
  undefined4 glErrorCode;
  uint requiredFormat;
  int rasterScratchEndThenFastResult;
  uint type;
  uint format;
  uint glContextWord4e1c;
  int *srcCursor;
  int dirtyWord;
  int framebufferObject;
  undefined4 incomingR5;
  undefined4 incomingR6;
  undefined4 incomingR7;
  undefined4 incomingR8;
  uint width;
  uint dispatchFlags;
  uint changeWord3;
  int matrixChangeBits;
  int *changeWordCursor;
  int recordSize;
  float *rasterPos;
  double f1AfterCall;
  
  rasterScratchEndThenFastResult = *(int *)(glContext + 0x4854);
  rasterPos = (float *)(rasterScratchEndThenFastResult + -0x200);
  recordSize = recordedArgs[4] + 0x14;
  if (-1 < *(short *)(glContext + 0x4a10)) {
LAB_00063798:
    if (*(int *)(glContext + 0x7574) != 0) {
      return recordSize;
    }
    glErrorCode = 0x502;
    goto LAB_00063b18;
  }
  width = *recordedArgs;
  if (((int)width < 0) || ((int)recordedArgs[1] < 0)) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return recordSize;
    }
    glErrorCode = 0x501;
    goto LAB_00063b18;
  }
  type = recordedArgs[3];
  if (type < 0x8037) {
    if (0x8032 < type) {
LAB_00063748:
      format = recordedArgs[2];
      if (format != 0x1908) {
        requiredFormat = 0x80e1;
        goto LAB_0006375c;
      }
      goto LAB_000637ac;
    }
    if (type == 0x140b) {
LAB_000636f4:
      format = recordedArgs[2];
      if (format != 0x8000) {
        if (format < 0x8001) {
          formatInvalid = 10 < format - 0x1900;
        }
        else {
          formatInvalid = 1 < format - 0x80e0;
        }
        if (formatInvalid) goto LAB_00063798;
      }
      goto LAB_000637ac;
    }
    if (type < 0x140c) {
      if (type - 0x1400 < 7) goto LAB_000636f4;
    }
    else if (type == 0x1a00) {
      if (recordedArgs[2] - 0x1900 < 2) goto LAB_000637ac;
    }
    else if (type == 0x8032) goto LAB_00063730;
  }
  else {
    if (type < 0x8369) {
      if (0x8364 < type) goto LAB_00063748;
      if (type < 0x8362) goto LAB_00063b08;
LAB_00063730:
      format = recordedArgs[2];
      if (format == 0x1907) goto LAB_000637ac;
      requiredFormat = 0x80e0;
LAB_0006375c:
      if (format != requiredFormat) goto LAB_00063798;
    }
    else {
      if (1 < type - 0x85ba) goto LAB_00063b08;
      if ((recordedArgs[2] != 0x85b9) || ((width & 1) != 0)) goto LAB_00063798;
    }
LAB_000637ac:
    if (*(char *)(glContext + 0x2ef) == '\0') {
      return recordSize;
    }
    glContextWord4e1c = *(uint *)(glContext + 0x4e1c);
    if (glContextWord4e1c == 0x1c01) {
      *rasterPos = *(float *)(glContext + 0x2e0);
      *(undefined4 *)(rasterScratchEndThenFastResult + -0x1fc) = *(undefined4 *)(glContext + 0x2e4);
      *(undefined4 *)(rasterScratchEndThenFastResult + -0x1f8) = *(undefined4 *)(glContext + 0x2e8);
      _gleFeedbackDrawPixels(glContext,rasterPos);
      return recordSize;
    }
    if (glContextWord4e1c < 0x1c02) {
      if (glContextWord4e1c == 0x1c00) {
        if (*(float *)(glContext + 0x31a8) == FLOAT_00108e50) {
          return recordSize;
        }
        if (*(float *)(glContext + 0x31ac) == FLOAT_00108e50) {
          return recordSize;
        }
        if (width == 0) {
          return recordSize;
        }
        if (recordedArgs[1] == 0) {
          return recordSize;
        }
        matrixChangeBits = *(int *)(glContext + 0x50ac);
        if (matrixChangeBits != 0 || (*(uint *)(glContext + 0x505c) & *(uint *)(glContext + 0x50b0)) != 0) {
          _gleUpdateMatrixFunc(glContext);
          forwardedFloatArg1 = f1AfterCall;
        }
        if (*(char *)(glContext + 0x4691) == '\0') goto LAB_00063a3c;
        framebufferObject = *(int *)(glContext + 0x744c);
        changeWordCursor = (int *)(glContext + 0x310);
        rendererInfoByte79 = *(char *)(*(int *)(glContext + 0x468c) + 0x79);
        if ((framebufferObject != 0) && (*(int *)(framebufferObject + 0xec) != 0)) {
          ((void (*)())_gleUpdateFramebufferCompleteness)(glContext,framebufferObject + 0x10,incomingR5,incomingR6,incomingR7,incomingR8,matrixChangeBits,forwardedFloatArg1,forwardedFloatArg2,forwardedFloatArg3,
                     forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
          *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x80000000;
        }
        if ((*(char *)(glContext + 0x4664) == '\0') && (*(int *)(glContext + 0x5430) == 0)) {
LAB_00063918:
          changeWord3 = *(uint *)(glContext + 0x31c);
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
          changeWord3 = *(uint *)(glContext + 0x31c);
          if ((changeWord3 & 0x15555) != 0) {
            if (*(char *)(glContext + 0x2e54) != '\0') {
              _gleUpdateLightRGBASums(glContext,glContext + 0x2c20,0);
            }
            if (*(char *)(glContext + 0x3094) != '\0') {
              _gleUpdateLightRGBASums(glContext,glContext + 0x2e60,1);
            }
            goto LAB_00063918;
          }
        }
        rendererByte79Clear = rendererInfoByte79 == '\0';
        if (rendererByte79Clear) {
          changeWord3 = changeWord3 & 0x17000000;
        }
        else {
          changeWord3 = changeWord3 & 0x17ffffff;
        }
        if (rendererByte79Clear) {
          noStateChangePending = ((*changeWordCursor == 0 && *(int *)(glContext + 0x314) == 0) && changeWord3 == 0) &&
                  *(int *)(glContext + 800) == 0;
        }
        else {
          noStateChangePending = (((*changeWordCursor == 0 && *(int *)(glContext + 0x314) == 0) &&
                   (*(uint *)(glContext + 0x318) & 0xfffffffd) == 0) && changeWord3 == 0) &&
                  *(int *)(glContext + 800) == 0;
        }
        if (!noStateChangePending) {
          if (*(char *)(glContext + 0x85a8) == *(char *)(glContext + 0x85a6)) {
            dispatchFlags = (**(code **)(glContext + 0x4788))
                              (*(undefined4 *)(glContext + 0x4688),glContext + 0x4698,changeWordCursor);
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
                  return recordSize;
                }
                glErrorCode = 0x506;
                goto LAB_00063b18;
              }
            }
          }
          else {
            _gleSwitchToNonRevertRenderer(glContext);
          }
          remaining = 0x13;
          do {
            *changeWordCursor = 0;
            changeWordCursor = changeWordCursor + 1;
            remaining = remaining + -1;
          } while (remaining != 0);
        }
LAB_00063a3c:
        *rasterPos = *(float *)(glContext + 0x4a44) * *(float *)(glContext + 0x2e0) +
                   *(float *)(glContext + 0x4a48);
        *(float *)(rasterScratchEndThenFastResult + -0x1fc) =
             *(float *)(glContext + 0x4a4c) * *(float *)(glContext + 0x2e4) +
             *(float *)(glContext + 0x4a50);
        *(float *)(rasterScratchEndThenFastResult + -0x1f8) = *(float *)(glContext + 0x4a54) * *(float *)(glContext + 0x2e8);
        if ((*(char *)(*(int *)(glContext + 0x468c) + 0x7b) != '\0') &&
           (rasterScratchEndThenFastResult = _gleDrawPixelsFast(glContext,*recordedArgs,recordedArgs[1],recordedArgs[2],recordedArgs[3],recordedArgs + 5
                                      ), rasterScratchEndThenFastResult != 0)) {
          return recordSize;
        }
        (**(code **)(glContext + 0x46a4))
                  (*(undefined4 *)(glContext + 0x4688),rasterPos,*recordedArgs,recordedArgs[1],recordedArgs[2],
                   recordedArgs[3],recordedArgs + 5,1);
        return recordSize;
      }
    }
    else if (glContextWord4e1c == 0x1c02) {
      return recordSize;
    }
  }
LAB_00063b08:
  if (*(int *)(glContext + 0x7574) != 0) {
    return recordSize;
  }
  glErrorCode = 0x500;
LAB_00063b18:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return recordSize;
}

/* _glDrawPixels_Comp @ 0x63b34 (600 bytes) */
int _glDrawPixels_Comp(glContext, width, height, format, type, pixels)
  int glContext;
  undefined4 width;
  int height;
  undefined4 format;
  undefined4 type;
  int pixels;
{
  uint recordDataSize;
  int imageEndOffset;
  int rowBytes;
  int resultThenElementSize;
  int pixelUnpackBuffer;
  undefined4 *listRecord;
  undefined4 *dstConvertDescPtrA;
  undefined4 *dstConvertDescPtrB;
  undefined1 *packPixelBytesPtr;
  int *packOffsetPtr;
  int unpackSettings;
  int unpackBufferSize;
  int forwardedArg5;
  int glContextPtr4a6c2;
  double bytesPerElement;
  int srcImagePtr;
  undefined4 srcRowBytes;
  undefined4 srcConvertDescA;
  undefined4 srcConvertDescB;
  undefined4 *dstImagePtr;
  int dstRowBytes;
  undefined4 dstConvertDescA;
  undefined4 dstConvertDescB;
  undefined4 unitCount;
  uint copyFlags;
  undefined4 pixelOpFlags;
  undefined4 imageWidth;
  int imageHeight;
  undefined1 processReserved;
  undefined4 packedRowBytes;
  undefined1 rowPadding [4];
  undefined1 imageBytes [4];
  undefined1 imagePadding [4];
  undefined1 packPixelBytes [4];
  int packOffset;
  undefined4 convertDescAOut;
  undefined4 convertDescBOut [2];
  
  glContextPtr4a6c2 = *(int *)(glContext + 0x4a6c);
  if (glContextPtr4a6c2 == 0) {
LAB_00063c10:
    unpackSettings = glContext + 0x31cc;
    packPixelBytesPtr = packPixelBytes;
    packOffsetPtr = &packOffset;
    forwardedArg5 = height;
    _glePixelPackSettings
              (glContext,format,type,width,height,unpackSettings,packPixelBytesPtr,packOffsetPtr,&packedRowBytes,rowPadding,
               imageBytes,imagePadding);
    rowBytes = _gleRowBytes(format,type,width);
    recordDataSize = rowBytes * height + 3U & 0xfffffffc;
    listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glDrawPixels_ListExec_001100a8,recordDataSize + 0x14)
    ;
    resultThenElementSize = 0;
    if (listRecord != (undefined4 *)0x0) {
      listRecord[4] = recordDataSize;
      *listRecord = width;
      listRecord[1] = height;
      listRecord[2] = format;
      listRecord[3] = type;
      if ((*(uint *)(glContext + 0x31e4) & 0xffff0000) == 0) {
        resultThenElementSize = _gleCopy(pixels + packOffset,listRecord + 5,rowBytes,height,packedRowBytes,rowBytes);
      }
      else {
        dstConvertDescPtrA = &convertDescAOut;
        dstConvertDescPtrB = convertDescBOut;
        _glgConvertType(format,type,dstConvertDescPtrA,dstConvertDescPtrB,forwardedArg5,unpackSettings,packPixelBytesPtr,packOffsetPtr);
        srcRowBytes = packedRowBytes;
        dstConvertDescA = convertDescAOut;
        dstConvertDescB = convertDescBOut[0];
        unitCount = 2;
        pixelOpFlags = 5;
        processReserved = 0;
        srcConvertDescA = convertDescAOut;
        srcConvertDescB = convertDescBOut[0];
        copyFlags = (uint)(*(char *)(glContext + 0x31e4) != '\0');
        if (*(char *)(glContext + 0x31e5) != '\0') {
          copyFlags = copyFlags | 4;
        }
        srcImagePtr = pixels + packOffset;
        dstImagePtr = listRecord + 5;
        dstRowBytes = rowBytes;
        imageWidth = width;
        imageHeight = height;
        resultThenElementSize = _glgProcessPixels(0,&srcImagePtr,dstConvertDescPtrA,dstConvertDescPtrB,forwardedArg5,unpackSettings,convertDescBOut[0],convertDescAOut);
      }
    }
  }
  else {
    imageEndOffset = _gleOffsetLimitImage(glContext + 0x31cc,width,height,format,type,pixels);
    unpackBufferSize = *(int *)(glContextPtr4a6c2 + 0x38);
    bytesPerElement = (double)((double (*)())_gleBytesPerElement)(type);
    resultThenElementSize = (int)bytesPerElement;
    if (imageEndOffset <= unpackBufferSize) {
      if (resultThenElementSize == 0) {
        resultThenElementSize = _glePixelBytes(format,type);
      }
      if (pixels == (pixels / resultThenElementSize) * resultThenElementSize) {
        pixelUnpackBuffer = *(int *)(glContext + 0x4a6c);
        if ((pixelUnpackBuffer != 0) && (*(int *)(pixelUnpackBuffer + 0x40) != 0)) {
          _gleSynchronizePluginBuffer(glContext,pixelUnpackBuffer + 0x10);
        }
        pixels = pixels + *(int *)(glContextPtr4a6c2 + 0x30);
        goto LAB_00063c10;
      }
    }
    if (*(int *)(glContext + 0x7574) == 0) {
      *(undefined4 *)(glContext + 0x7574) = 0x502;
    }
  }
  return resultThenElementSize;
}

/* _glDrawPixels_Exec @ 0x63d8c (1520 bytes) */
void _glDrawPixels_Exec(int glContext,uint width,int height,uint format,uint type,int pixels,double fparam_1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
{
  int remaining;
  int loopIndex;
  bool bVar1;
  bool noStateChangePending;
  char rendererInfoByte79;
  undefined4 glErrorCode;
  uint glContextWord4e1c;
  int iVar5;
  int iVar6;
  int *srcCursor;
  int imageEndOffset;
  int framebufferObject;
  int elementBytes;
  int matrixChangeBits;
  uint uVar10;
  int iVar11;
  uint uVar12;
  uint dispatchFlags;
  uint changeWord3;
  int pixelUnpackBuffer;
  float *rasterPositionVertex;
  int bufferSize;
  int *changeWordCursor;
  double extraout_f1;
  double extraout_f1_00;
  
  iVar6 = *(int *)(glContext + 0x4854);
  rasterPositionVertex = (float *)(iVar6 + -0x200);
  if (-1 < *(short *)(glContext + 0x4a10)) goto LAB_00063f78;
  if (((int)width < 0) || (height < 0)) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x501;
    goto LAB_0006435c;
  }
  if (type < 0x8037) {
    if (0x8032 < type) {
LAB_00063ec4:
      if (format != 0x1908) {
        uVar12 = 0x80e1;
        goto LAB_00063ed4;
      }
      goto LAB_00063f08;
    }
    if (type == 0x140b) {
LAB_00063e78:
      if (format != 0x8000) {
        if (format < 0x8001) {
          bVar1 = 10 < format - 0x1900;
        }
        else {
          bVar1 = 1 < format - 0x80e0;
        }
        if (bVar1) goto LAB_00063f78;
      }
      goto LAB_00063f08;
    }
    if (type < 0x140c) {
      if (type - 0x1400 < 7) goto LAB_00063e78;
    }
    else if (type == 0x1a00) {
      if (format - 0x1900 < 2) goto LAB_00063f08;
    }
    else if (type == 0x8032) goto LAB_00063eb0;
    goto LAB_0006434c;
  }
  if (type < 0x8369) {
    if (0x8364 < type) goto LAB_00063ec4;
    if (type < 0x8362) goto LAB_0006434c;
LAB_00063eb0:
    if (format == 0x1907) goto LAB_00063f08;
    uVar12 = 0x80e0;
LAB_00063ed4:
    if (format != uVar12) goto LAB_00063f78;
  }
  else {
    if (1 < type - 0x85ba) goto LAB_0006434c;
    if ((format != 0x85b9) || ((width & 1) != 0)) goto LAB_00063f78;
  }
LAB_00063f08:
  pixelUnpackBuffer = *(int *)(glContext + 0x4a6c);
  iVar11 = height;
  uVar12 = format;
  uVar10 = type;
  iVar5 = pixels;
  if (pixelUnpackBuffer != 0) {
    imageEndOffset = _gleOffsetLimitImage(glContext + 0x31cc,width,height,format,type,pixels);
    bufferSize = *(int *)(pixelUnpackBuffer + 0x38);
    fparam_1 = (double)((double (*)())_gleBytesPerElement)(type);
    elementBytes = (int)fparam_1;
    if (imageEndOffset <= bufferSize) {
      if (elementBytes == 0) {
        elementBytes = _glePixelBytes(format,type);
        fparam_1 = extraout_f1;
      }
      if (pixels == (pixels / elementBytes) * elementBytes) {
        pixels = pixels + *(int *)(pixelUnpackBuffer + 0x30);
        goto LAB_00063f94;
      }
    }
LAB_00063f78:
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
    goto LAB_0006435c;
  }
LAB_00063f94:
  if (*(char *)(glContext + 0x2ef) == '\0') {
    return;
  }
  glContextWord4e1c = *(uint *)(glContext + 0x4e1c);
  if (glContextWord4e1c == 0x1c01) {
    *rasterPositionVertex = *(float *)(glContext + 0x2e0);
    *(undefined4 *)(iVar6 + -0x1fc) = *(undefined4 *)(glContext + 0x2e4);
    *(undefined4 *)(iVar6 + -0x1f8) = *(undefined4 *)(glContext + 0x2e8);
    _gleFeedbackDrawPixels(glContext,rasterPositionVertex);
    return;
  }
  if (glContextWord4e1c < 0x1c02) {
    if (glContextWord4e1c == 0x1c00) {
      if (*(float *)(glContext + 0x31a8) == FLOAT_00108e50) {
        return;
      }
      if (*(float *)(glContext + 0x31ac) == FLOAT_00108e50) {
        return;
      }
      if (width == 0) {
        return;
      }
      if (height == 0) {
        return;
      }
      matrixChangeBits = *(int *)(glContext + 0x50ac);
      if (matrixChangeBits != 0 || (*(uint *)(glContext + 0x505c) & *(uint *)(glContext + 0x50b0)) != 0) {
        _gleUpdateMatrixFunc(glContext);
        fparam_1 = extraout_f1_00;
      }
      if (*(char *)(glContext + 0x4691) == '\0') goto LAB_00064218;
      framebufferObject = *(int *)(glContext + 0x744c);
      changeWordCursor = (int *)(glContext + 0x310);
      rendererInfoByte79 = *(char *)(*(int *)(glContext + 0x468c) + 0x79);
      if ((framebufferObject != 0) && (*(int *)(framebufferObject + 0xec) != 0)) {
        ((void (*)())_gleUpdateFramebufferCompleteness)(glContext,framebufferObject + 0x10,iVar11,uVar12,uVar10,iVar5,matrixChangeBits,fparam_1,forwardedFloatArg2,forwardedFloatArg3,
                   forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
        *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x80000000;
      }
      if ((*(char *)(glContext + 0x4664) == '\0') && (*(int *)(glContext + 0x5430) == 0)) {
LAB_000640f4:
        changeWord3 = *(uint *)(glContext + 0x31c);
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
        changeWord3 = *(uint *)(glContext + 0x31c);
        if ((changeWord3 & 0x15555) != 0) {
          if (*(char *)(glContext + 0x2e54) != '\0') {
            _gleUpdateLightRGBASums(glContext,glContext + 0x2c20,0);
          }
          if (*(char *)(glContext + 0x3094) != '\0') {
            _gleUpdateLightRGBASums(glContext,glContext + 0x2e60,1);
          }
          goto LAB_000640f4;
        }
      }
      bVar1 = rendererInfoByte79 == '\0';
      if (bVar1) {
        changeWord3 = changeWord3 & 0x17000000;
      }
      else {
        changeWord3 = changeWord3 & 0x17ffffff;
      }
      if (bVar1) {
        noStateChangePending = ((*changeWordCursor == 0 && *(int *)(glContext + 0x314) == 0) && changeWord3 == 0) &&
                *(int *)(glContext + 800) == 0;
      }
      else {
        noStateChangePending = (((*changeWordCursor == 0 && *(int *)(glContext + 0x314) == 0) &&
                 (*(uint *)(glContext + 0x318) & 0xfffffffd) == 0) && changeWord3 == 0) &&
                *(int *)(glContext + 800) == 0;
      }
      if (!noStateChangePending) {
        if (*(char *)(glContext + 0x85a8) == *(char *)(glContext + 0x85a6)) {
          dispatchFlags = (**(code **)(glContext + 0x4788))
                             (*(undefined4 *)(glContext + 0x4688),glContext + 0x4698,changeWordCursor);
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
              goto LAB_0006435c;
            }
          }
        }
        else {
          _gleSwitchToNonRevertRenderer(glContext);
        }
        remaining = 0x13;
        do {
          *changeWordCursor = 0;
          changeWordCursor = changeWordCursor + 1;
          remaining = remaining + -1;
        } while (remaining != 0);
      }
LAB_00064218:
      *rasterPositionVertex = *(float *)(glContext + 0x4a44) * *(float *)(glContext + 0x2e0) +
                 *(float *)(glContext + 0x4a48);
      *(float *)(iVar6 + -0x1fc) =
           *(float *)(glContext + 0x4a4c) * *(float *)(glContext + 0x2e4) + *(float *)(glContext + 0x4a50)
      ;
      *(float *)(iVar6 + -0x1f8) = *(float *)(glContext + 0x4a54) * *(float *)(glContext + 0x2e8);
      if (pixelUnpackBuffer != 0) {
        iVar6 = (**(code **)(glContext + 0x46a4))
                          (*(undefined4 *)(glContext + 0x4688),rasterPositionVertex,width,height,format,type
                           ,pixels,0);
        if (iVar6 != 0) {
          return;
        }
        if (*(int *)(pixelUnpackBuffer + 0x40) != 0) {
          _gleSynchronizePluginBuffer(glContext,pixelUnpackBuffer + 0x10);
        }
      }
      if ((*(char *)(*(int *)(glContext + 0x468c) + 0x7b) != '\0') &&
         (iVar6 = _gleDrawPixelsFast(glContext,width,height,format,type,pixels), iVar6 != 0))
      {
        return;
      }
      (**(code **)(glContext + 0x46a4))
                (*(undefined4 *)(glContext + 0x4688),rasterPositionVertex,width,height,format,type,pixels,0
                );
      return;
    }
  }
  else if (glContextWord4e1c == 0x1c02) {
    return;
  }
LAB_0006434c:
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  glErrorCode = 0x500;
LAB_0006435c:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glDrawPixels_CompExec @ 0x6437c (88 bytes) */
void _glDrawPixels_CompExec(glContext, width, height, format, type, pixels)
  undefined4 glContext;
  undefined4 width;
  undefined4 height;
  undefined4 format;
  undefined4 type;
  undefined4 pixels;
{
  double forwardedFloatArg1;
  double incomingFpr2;
  double incomingFpr3;
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  
  ((int (*)())_glDrawPixels_Comp)(glContext,width,height,format,type,pixels);
  ((void (*)())_glDrawPixels_Exec)(glContext,width,height,format,type,pixels,forwardedFloatArg1,incomingFpr2,incomingFpr3,incomingFpr4,
                     incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8);
  return;
}

/* _glDrawPixels_NoopExec @ 0x643d4 (672 bytes) */
void _glDrawPixels_NoopExec(int glContext,undefined4 width,undefined4 height,undefined4 format,undefined4 type,undefined4 pixels,double fparam_1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
{
  int remaining;
  int loopIndex;
  bool bVar1;
  bool noStateChangePending;
  char rendererInfoByte79;
  int *srcCursor;
  int iVar4;
  int framebufferObject;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  int matrixChangeBits;
  uint dispatchFlags;
  uint changeWord3;
  int *changeWordCursor;
  double extraout_f1;
  double extraout_f1_00;
  double extraout_f1_01;
  
  matrixChangeBits = *(int *)(glContext + 0x50ac);
  uVar5 = height;
  uVar6 = format;
  uVar7 = type;
  uVar8 = pixels;
  if (matrixChangeBits != 0 || (*(uint *)(glContext + 0x505c) & *(uint *)(glContext + 0x50b0)) != 0) {
    _gleUpdateMatrixFunc(glContext);
    fparam_1 = extraout_f1;
  }
  if (*(char *)(glContext + 0x4691) != '\0') {
    framebufferObject = *(int *)(glContext + 0x744c);
    changeWordCursor = (int *)(glContext + 0x310);
    rendererInfoByte79 = *(char *)(*(int *)(glContext + 0x468c) + 0x79);
    if ((framebufferObject != 0) && (*(int *)(framebufferObject + 0xec) != 0)) {
      ((void (*)())_gleUpdateFramebufferCompleteness)(glContext,framebufferObject + 0x10,uVar5,uVar6,uVar7,uVar8,matrixChangeBits,fparam_1,forwardedFloatArg2,forwardedFloatArg3,
                 forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
      *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x80000000;
      fparam_1 = fparam_1;
    }
    if ((*(char *)(glContext + 0x4664) == '\0') && (*(int *)(glContext + 0x5430) == 0)) {
LAB_000644fc:
      changeWord3 = *(uint *)(glContext + 0x31c);
    }
    else {
      loopIndex = 0;
      srcCursor = (int *)(glContext + 0x324);
      do {
        iVar4 = *srcCursor;
        srcCursor = srcCursor + 1;
        if (iVar4 != 0) {
          *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x800000;
          break;
        }
        loopIndex = loopIndex + 1;
      } while (loopIndex < 9);
      changeWord3 = *(uint *)(glContext + 0x31c);
      if ((changeWord3 & 0x15555) != 0) {
        if (*(char *)(glContext + 0x2e54) != '\0') {
          fparam_1 = (double)_gleUpdateLightRGBASums(glContext,glContext + 0x2c20,0);
        }
        if (*(char *)(glContext + 0x3094) != '\0') {
          fparam_1 = (double)_gleUpdateLightRGBASums(glContext,glContext + 0x2e60,1);
        }
        goto LAB_000644fc;
      }
    }
    bVar1 = rendererInfoByte79 == '\0';
    if (bVar1) {
      changeWord3 = changeWord3 & 0x17000000;
    }
    else {
      changeWord3 = changeWord3 & 0x17ffffff;
    }
    if (bVar1) {
      noStateChangePending = ((*changeWordCursor == 0 && *(int *)(glContext + 0x314) == 0) && changeWord3 == 0) &&
              *(int *)(glContext + 800) == 0;
    }
    else {
      noStateChangePending = (((*changeWordCursor == 0 && *(int *)(glContext + 0x314) == 0) &&
               (*(uint *)(glContext + 0x318) & 0xfffffffd) == 0) && changeWord3 == 0) &&
              *(int *)(glContext + 800) == 0;
    }
    if (!noStateChangePending) {
      if (*(char *)(glContext + 0x85a8) == *(char *)(glContext + 0x85a6)) {
        dispatchFlags = (**(code **)(glContext + 0x4788))
                           (*(undefined4 *)(glContext + 0x4688),glContext + 0x4698,changeWordCursor);
        if ((((dispatchFlags & 3) != (uint)*(byte *)(glContext + 0x7580)) ||
            ((dispatchFlags & 4) != (uint)*(byte *)(glContext + 0x7581))) ||
           (fparam_1 = extraout_f1_01, (dispatchFlags & 8) != (uint)(*(char *)(glContext + 0x759d) == '\0')))
        {
          if ((dispatchFlags & 4) == 0) {
            dispatchFlags = dispatchFlags & 0xfffffffe;
            *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x10000000;
          }
          fparam_1 = (double)_gleUpdateDispatchCodeChange(glContext,dispatchFlags);
          if (*(char *)(glContext + 0x759d) == '\0') goto LAB_0006461c;
        }
      }
      else {
        fparam_1 = (double)_gleSwitchToNonRevertRenderer(glContext);
      }
      remaining = 0x13;
      do {
        *changeWordCursor = 0;
        changeWordCursor = changeWordCursor + 1;
        remaining = remaining + -1;
      } while (remaining != 0);
    }
  }
  if (*(char *)(glContext + 0x759d) != '\0') {
    ((void (*)())_glDrawPixels_Exec)(glContext,width,height,format,type,pixels,fparam_1,forwardedFloatArg2,forwardedFloatArg3,
                       forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
    return;
  }
LAB_0006461c:
  if (*(int *)(glContext + 0x7574) == 0) {
    *(undefined4 *)(glContext + 0x7574) = 0x506;
  }
  return;
}

/* _glEdgeFlag_ListExec @ 0x64674 (40 bytes) */
int _glEdgeFlag_ListExec(glContext, recordedArgs)
  undefined4 glContext;
  byte *recordedArgs;
{
  ((double (*)())_glEdgeFlag_Exec)(glContext,(uint)*recordedArgs);
  return 4;
}

/* _glEdgeFlag_Comp @ 0x6469c (76 bytes) */
int _glEdgeFlag_Comp(glContext, flag)
  undefined4 glContext;
  undefined4 flag;
{
  undefined1 *listRecord;
  
  listRecord = (undefined1 *)_gleAddListItem(glContext,PTR__glEdgeFlag_ListExec_001100ac,4);
  if (listRecord != (undefined1 *)0x0) {
    *listRecord = (undefined1)flag;
  }
  return listRecord;
}

/* _glEdgeFlag_Exec @ 0x646e8 (16 bytes) */
double _glEdgeFlag_Exec(glContext, flag)
  int glContext;
  int flag;
{
  *(byte *)(glContext + 0x2ec) = (byte)((uint)-flag >> 0x1f);
  return;
}

/* _glEdgeFlag_CompExec @ 0x646f8 (56 bytes) */
void _glEdgeFlag_CompExec(glContext, flag)
  undefined4 glContext;
  undefined4 flag;
{
  ((int (*)())_glEdgeFlag_Comp)(glContext,flag);
  ((double (*)())_glEdgeFlag_Exec)(glContext,flag);
  return;
}

/* _glEdgeFlagv_Comp @ 0x64730 (80 bytes) */
int _glEdgeFlagv_Comp(glContext, flag)
  undefined4 glContext;
  undefined1 *flag;
{
  undefined1 *listRecord;
  
  listRecord = (undefined1 *)_gleAddListItem(glContext,PTR__glEdgeFlag_ListExec_001100ac,4);
  if (listRecord != (undefined1 *)0x0) {
    *listRecord = *flag;
  }
  return listRecord;
}

/* _glEdgeFlagv_Exec @ 0x64780 (20 bytes) */
void _glEdgeFlagv_Exec(glContext, flag)
  int glContext;
  byte *flag;
{
  *(byte *)(glContext + 0x2ec) = (byte)(-(uint)*flag >> 0x1f);
  return;
}

/* _glEdgeFlagv_CompExec @ 0x64794 (56 bytes) */
void _glEdgeFlagv_CompExec(glContext, flag)
  undefined4 glContext;
  undefined4 flag;
{
  ((int (*)())_glEdgeFlagv_Comp)(glContext,flag);
  ((void (*)())_glEdgeFlagv_Exec)(glContext,flag);
  return;
}

/* _glEvalCoord1d_ListExec_body @ 0x647d0 (40 bytes) */
undefined4 _glEvalCoord1d_ListExec_body(undefined4 glContext,double fparam_1)
{
  ((void (*)())_gleEvalMap1)(glContext,(double)(float)fparam_1);
  return 8;
}

/* _glEvalCoord1d_Comp @ 0x647f8 (84 bytes) */
double * _glEvalCoord1d_Comp(undefined4 glContext,double u)
{
  double *listRecord;
  
  listRecord = (double *)_gleAddListItem(glContext,PTR__glEvalCoord1d_ListExec_001100c0,8);
  if (listRecord != (double *)0x0) {
    *listRecord = u;
  }
  return listRecord;
}

/* _glEvalCoord1d_CompExec @ 0x64854 (72 bytes) */
void _glEvalCoord1d_CompExec(undefined4 glContext,double u)
{
  ((double * (*)())_glEvalCoord1d_Comp)(glContext,u);
  ((void (*)())_gleEvalMap1)(glContext,(double)(float)u);
  return;
}

/* _glEvalCoord1dv_Comp @ 0x64894 (80 bytes) */
int _glEvalCoord1dv_Comp(glContext, u)
  undefined4 glContext;
  undefined8 *u;
{
  undefined8 *listRecord;
  
  listRecord = (undefined8 *)_gleAddListItem(glContext,PTR__glEvalCoord1d_ListExec_001100c0,8);
  if (listRecord != (undefined8 *)0x0) {
    *listRecord = *u;
  }
  return listRecord;
}

/* _glEvalCoord1dv_Exec @ 0x648e4 (12 bytes) */
void _glEvalCoord1dv_Exec(glContext, u)
  undefined4 glContext;
  double *u;
{
  ((void (*)())_gleEvalMap1)(glContext,(double)(float)*u);
  return;
}

/* _glEvalCoord1dv_CompExec @ 0x648f0 (56 bytes) */
void _glEvalCoord1dv_CompExec(glContext, u)
  undefined4 glContext;
  undefined4 u;
{
  ((int (*)())_glEvalCoord1dv_Comp)(glContext,u);
  ((void (*)())_glEvalCoord1dv_Exec)(glContext,u);
  return;
}

/* _glEvalCoord1f_ListExec @ 0x64928 (40 bytes) */
int _glEvalCoord1f_ListExec(glContext, recordedArgs)
  undefined4 glContext;
  float *recordedArgs;
{
  ((void (*)())_gleEvalMap1)(glContext,(double)*recordedArgs);
  return 4;
}

/* _glEvalCoord1f_Comp @ 0x64950 (84 bytes) */
float * _glEvalCoord1f_Comp(undefined4 glContext,float u)
{
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glEvalCoord1f_ListExec_001100bc,4);
  if (listRecord != (float *)0x0) {
    *listRecord = (float)u;
  }
  return listRecord;
}

/* _glEvalCoord1f_CompExec @ 0x649a8 (68 bytes) */
void _glEvalCoord1f_CompExec(undefined4 glContext,float u)
{
  ((float * (*)())_glEvalCoord1f_Comp)(glContext,u);
  ((void (*)())_gleEvalMap1)(glContext,u);
  return;
}

/* _glEvalCoord1fv_Comp @ 0x649e8 (80 bytes) */
int _glEvalCoord1fv_Comp(glContext, u)
  undefined4 glContext;
  undefined4 *u;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glEvalCoord1f_ListExec_001100bc,4);
  if (listRecord != (undefined4 *)0x0) {
    *listRecord = *u;
  }
  return listRecord;
}

/* _glEvalCoord1fv_Exec @ 0x64a38 (8 bytes) */
void _glEvalCoord1fv_Exec(glContext, u)
  undefined4 glContext;
  float *u;
{
  ((void (*)())_gleEvalMap1)(glContext,(double)*u);
  return;
}

/* _glEvalCoord1fv_CompExec @ 0x64a40 (56 bytes) */
void _glEvalCoord1fv_CompExec(glContext, u)
  undefined4 glContext;
  undefined4 u;
{
  ((int (*)())_glEvalCoord1fv_Comp)(glContext,u);
  ((void (*)())_glEvalCoord1fv_Exec)(glContext,u);
  return;
}

/* _glEvalCoord2d_ListExec @ 0x64a78 (44 bytes) */
undefined4 _glEvalCoord2d_ListExec(undefined4 glContext,float *recordedArgs,double unusedFloatArg1,double unusedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12)
{
  double incomingStack_ffffffb8;
  double incomingStack_ffffffc0;
  double incomingStack_ffffffc8;
  double incomingStack_ffffffd0;
  
  ((void (*)())_gleEvalMap2)(glContext,(double)*recordedArgs,(double)recordedArgs[1],forwardedFloatArg3,forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,
               forwardedFloatArg7,forwardedFloatArg8,incomingStack_ffffffb8,incomingStack_ffffffc0,incomingStack_ffffffc8,
               incomingStack_ffffffd0);
  return 8;
}

/* _glEvalCoord2d_Comp @ 0x64aa4 (108 bytes) */
float * _glEvalCoord2d_Comp(undefined4 glContext,double u,double v)
{
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glEvalCoord2d_ListExec_001100c8,8);
  if (listRecord != (float *)0x0) {
    *listRecord = (float)u;
    listRecord[1] = (float)v;
  }
  return listRecord;
}

/* _glEvalCoord2d_CompExec @ 0x64b1c (92 bytes) */
void _glEvalCoord2d_CompExec(undefined4 glContext,double u,double v,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8,double fparam_9,double forwardedFloatArg10,double forwardedFloatArg11,double forwardedFloatArg12)
{
  undefined4 in_LR;
  
  ((float * (*)())_glEvalCoord2d_Comp)(glContext,u,v);
  ((void (*)())_gleEvalMap2)(glContext,(double)(float)u,(double)(float)v,forwardedFloatArg3,forwardedFloatArg4,forwardedFloatArg5,
               forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8,(double)CONCAT44(in_LR,(*(unsigned int *)((unsigned char *)&(fparam_9) + 4))),forwardedFloatArg10,forwardedFloatArg11
               ,forwardedFloatArg12);
  return;
}

/* _glEvalCoord2dv_Comp @ 0x64b6c (96 bytes) */
int _glEvalCoord2dv_Comp(glContext, u)
  undefined4 glContext;
  double *u;
{
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glEvalCoord2d_ListExec_001100c8,8);
  if (listRecord != (float *)0x0) {
    *listRecord = (float)*u;
    listRecord[1] = (float)u[1];
  }
  return listRecord;
}

