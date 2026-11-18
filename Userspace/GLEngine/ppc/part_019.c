#include "decls.h"

/* _glMapVertexAttrib2fARB_Comp @ 0x7192c (520 bytes) */
void _glMapVertexAttrib2fARB_Comp(int glContext,undefined4 index,uint size,undefined4 u1Shadow,undefined4 u2Shadow,undefined4 ustride,int uorder,undefined4 v1Shadow,undefined4 v2Shadow,undefined4 vstride,int vorder,undefined4 points,float u1,float u2,float v1,float v2)
{
  undefined4 *listRecord;
  undefined4 extraout_r4;
  undefined4 extraout_r4_00;
  undefined4 extraout_r4_01;
  undefined4 extraout_r4_02;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  double in_f9;
  double in_f10;
  double in_f11;
  double in_f12;
  double in_f13;
  
  if (size == 2) {
    iVar2 = (100 - uorder * vorder) * -8 + 0x344;
    uVar3 = ustride;
    iVar4 = uorder;
    listRecord = (undefined4 *)
             _gleAddListItem(glContext,PTR__glMap2VertexAttrib2ARB_ListExec_0011019c,iVar2);
    if (listRecord == (undefined4 *)0x0) goto LAB_00071b28;
    ((void (*)())_gleMap2VertexAttrib2fLoad)(glContext,extraout_r4_00,iVar2,ustride,uorder,uVar3,iVar4,vstride,vorder,points,
               listRecord + 1,u1,u2,v1,v2,in_f5,in_f6,in_f7,in_f8,in_f9,in_f10,
               in_f11,in_f12,in_f13);
  }
  else if (size < 3) {
    if (size != 1) {
LAB_00071b14:
      if (*(int *)(glContext + 0x7574) == 0) {
        *(undefined4 *)(glContext + 0x7574) = 0x501;
      }
      goto LAB_00071b28;
    }
    iVar2 = (100 - uorder * vorder) * -4 + 0x1b4;
    uVar3 = ustride;
    iVar4 = uorder;
    listRecord = (undefined4 *)
             _gleAddListItem(glContext,PTR__glMap2VertexAttrib1ARB_ListExec_001101a0,iVar2);
    if (listRecord == (undefined4 *)0x0) goto LAB_00071b28;
    ((void (*)())_gleMap2VertexAttrib1fLoad)(glContext,extraout_r4,iVar2,ustride,uorder,uVar3,iVar4,vstride,vorder,points,
               listRecord + 1,u1,u2,v1,v2,in_f5,in_f6,in_f7,in_f8,in_f9,in_f10,
               in_f11,in_f12,in_f13);
  }
  else if (size == 3) {
    iVar2 = (100 - uorder * vorder) * -0xc + 0x4d4;
    uVar3 = ustride;
    iVar4 = uorder;
    listRecord = (undefined4 *)
             _gleAddListItem(glContext,PTR__glMap2VertexAttrib3ARB_ListExec_00110198,iVar2);
    if (listRecord == (undefined4 *)0x0) goto LAB_00071b28;
    ((void (*)())_gleMap2VertexAttrib3fLoad)(glContext,extraout_r4_01,iVar2,ustride,uorder,uVar3,iVar4,vstride,vorder,points,
               listRecord + 1,u1,u2,v1,v2,in_f5,in_f6,in_f7,in_f8,in_f9,in_f10,
               in_f11,in_f12,in_f13);
  }
  else {
    if (size != 4) goto LAB_00071b14;
    iVar2 = (100 - uorder * vorder) * -0x10 + 0x664;
    uVar3 = ustride;
    iVar4 = uorder;
    listRecord = (undefined4 *)
             _gleAddListItem(glContext,PTR__glMap2VertexAttrib4ARB_ListExec_00110194,iVar2);
    if (listRecord == (undefined4 *)0x0) goto LAB_00071b28;
    ((void (*)())_gleMap2VertexAttrib4fLoad)(glContext,extraout_r4_02,iVar2,ustride,uorder,uVar3,iVar4,vstride,vorder,points,
               listRecord + 1,u1,u2,v1,v2,in_f5,in_f6,in_f7,in_f8,in_f9,in_f10,
               in_f11,in_f12,in_f13);
  }
  *listRecord = index;
LAB_00071b28:
  return;
}

/* _glMapVertexAttrib2fARB_Exec @ 0x71b34 (572 bytes) */
void _glMapVertexAttrib2fARB_Exec(int glContext,uint index,uint size,undefined4 u1Shadow,undefined4 u2Shadow,int ustride,int uorder,undefined4 v1Shadow,undefined4 v2Shadow,int vstride,int vorder,undefined4 points,float u1,float u2,float v1,float v2)
{
  undefined4 glErrorCode;
  int mapData;
  undefined4 extraout_r4;
  uint uVar3;
  int iVar4;
  int iVar5;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  double in_f9;
  double in_f10;
  double in_f11;
  double in_f12;
  double in_f13;
  
  uVar3 = size;
  iVar4 = ustride;
  iVar5 = uorder;
  mapData = _gleGetMapData(glContext);
  if (*(short *)(glContext + 0x4a10) < 0) {
    if ((((index < 0x10) && (u1 != u2)) && (v1 != v2)) &&
       (((0 < uorder && (uorder < 0xb)) && ((0 < vorder && (vorder < 0xb)))))) {
      if (size == 2) {
        if ((1 < ustride) && (1 < vstride)) {
          ((void (*)())_gleMap2VertexAttrib2fLoad)(glContext,extraout_r4,uVar3,ustride,uorder,iVar4,iVar5,vstride,vorder,
                     points,mapData + index * 0x660 + 0x37a8,u1,u2,v1,v2,
                     in_f5,in_f6,in_f7,in_f8,in_f9,in_f10,in_f11,in_f12,in_f13);
          goto LAB_00071d40;
        }
      }
      else if (size < 3) {
        if (((size == 1) && (0 < ustride)) && (0 < vstride)) {
          ((void (*)())_gleMap2VertexAttrib1fLoad)(glContext,extraout_r4,uVar3,ustride,uorder,iVar4,iVar5,vstride,vorder,
                     points,mapData + index * 0x660 + 0x37a8,u1,u2,v1,v2,
                     in_f5,in_f6,in_f7,in_f8,in_f9,in_f10,in_f11,in_f12,in_f13);
          goto LAB_00071d40;
        }
      }
      else if (size == 3) {
        if ((2 < ustride) && (2 < vstride)) {
          ((void (*)())_gleMap2VertexAttrib3fLoad)(glContext,extraout_r4,uVar3,ustride,uorder,iVar4,iVar5,vstride,vorder,
                     points,mapData + index * 0x660 + 0x37a8,u1,u2,v1,v2,
                     in_f5,in_f6,in_f7,in_f8,in_f9,in_f10,in_f11,in_f12,in_f13);
          goto LAB_00071d40;
        }
      }
      else if (((size == 4) && (3 < ustride)) && (3 < vstride)) {
        ((void (*)())_gleMap2VertexAttrib4fLoad)(glContext,extraout_r4,uVar3,ustride,uorder,iVar4,iVar5,vstride,vorder,points,
                   mapData + index * 0x660 + 0x37a8,u1,u2,v1,v2,in_f5,in_f6,
                   in_f7,in_f8,in_f9,in_f10,in_f11,in_f12,in_f13);
LAB_00071d40:
        *(char *)(index + mapData + 0x9db8) = (char)size;
        goto LAB_00071d64;
      }
    }
    if (*(int *)(glContext + 0x7574) != 0) goto LAB_00071d64;
    glErrorCode = 0x501;
  }
  else {
    if (*(int *)(glContext + 0x7574) != 0) goto LAB_00071d64;
    glErrorCode = 0x502;
  }
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
LAB_00071d64:
  return;
}

/* _glMapVertexAttrib2fARB_CompExec @ 0x71d70 (164 bytes) */
void _glMapVertexAttrib2fARB_CompExec(undefined4 glContext,undefined4 index,undefined4 size,undefined4 u1Shadow,undefined4 u2Shadow,undefined4 ustride,undefined4 uorder,undefined4 v1Shadow,undefined4 v2Shadow,undefined4 vstride,undefined4 vorder,undefined4 points,float u1,float u2,float v1,float v2)
{
  undefined4 in_stack_ffffff98;
  
  ((void (*)())_glMapVertexAttrib2fARB_Comp)(glContext,index,size,u1Shadow,u2Shadow,ustride,uorder,v1Shadow,in_stack_ffffff98,
             vstride,vorder,points,u1,u2,v1,v2);
  ((void (*)())_glMapVertexAttrib2fARB_Exec)(glContext,index,size,u1Shadow,u2Shadow,ustride,uorder,v1Shadow,v2Shadow,vstride,
             vorder,points,u1,u2,v1,v2);
  return;
}

/* _glMapVertexAttrib2dARB_Comp @ 0x71e14 (520 bytes) */
void _glMapVertexAttrib2dARB_Comp(int glContext,undefined4 index,uint size,undefined4 u1ShadowHi,undefined4 u1ShadowLo,undefined4 u2ShadowHi,undefined4 u2ShadowLo,undefined4 ustride,int uorder,undefined4 v1ShadowHi,undefined4 v1ShadowLo,undefined4 v2ShadowHi,undefined4 v2ShadowLo,undefined4 vstride,int vorder,undefined4 points,double u1,double u2,double v1,double v2)
{
  undefined4 *listRecord;
  undefined4 extraout_r4;
  undefined4 extraout_r4_00;
  undefined4 extraout_r4_01;
  undefined4 extraout_r4_02;
  int iVar2;
  undefined4 uVar3;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  double in_f9;
  double in_f10;
  double in_f11;
  double in_f12;
  double in_f13;
  undefined4 in_stack_ffffff88;
  undefined4 in_stack_ffffff8c;
  undefined4 in_stack_ffffff90;
  
  if (size == 2) {
    iVar2 = (100 - uorder * vorder) * -8 + 0x344;
    uVar3 = ustride;
    listRecord = (undefined4 *)
             _gleAddListItem(glContext,PTR__glMap2VertexAttrib2ARB_ListExec_0011019c,iVar2);
    if (listRecord == (undefined4 *)0x0) goto LAB_00072010;
    ((void (*)())_gleMap2VertexAttrib2dLoad)(glContext,extraout_r4_00,iVar2,u1ShadowHi,u1ShadowLo,ustride,uorder,uVar3,in_stack_ffffff88,
               in_stack_ffffff8c,in_stack_ffffff90,vstride,vorder,points,listRecord + 1,u1,
               u2,v1,v2,in_f5,in_f6,in_f7,in_f8,in_f9,in_f10,in_f11,in_f12,in_f13)
    ;
  }
  else if (size < 3) {
    if (size != 1) {
LAB_00071ffc:
      if (*(int *)(glContext + 0x7574) == 0) {
        *(undefined4 *)(glContext + 0x7574) = 0x501;
      }
      goto LAB_00072010;
    }
    iVar2 = (100 - uorder * vorder) * -4 + 0x1b4;
    uVar3 = ustride;
    listRecord = (undefined4 *)
             _gleAddListItem(glContext,PTR__glMap2VertexAttrib1ARB_ListExec_001101a0,iVar2);
    if (listRecord == (undefined4 *)0x0) goto LAB_00072010;
    ((void (*)())_gleMap2VertexAttrib1dLoad)(glContext,extraout_r4,iVar2,u1ShadowHi,u1ShadowLo,ustride,uorder,uVar3,in_stack_ffffff88,
               in_stack_ffffff8c,in_stack_ffffff90,vstride,vorder,points,listRecord + 1,u1,
               u2,v1,v2,in_f5,in_f6,in_f7,in_f8,in_f9,in_f10,in_f11,in_f12,in_f13)
    ;
  }
  else if (size == 3) {
    iVar2 = (100 - uorder * vorder) * -0xc + 0x4d4;
    uVar3 = ustride;
    listRecord = (undefined4 *)
             _gleAddListItem(glContext,PTR__glMap2VertexAttrib3ARB_ListExec_00110198,iVar2);
    if (listRecord == (undefined4 *)0x0) goto LAB_00072010;
    ((void (*)())_gleMap2VertexAttrib3dLoad)(glContext,extraout_r4_01,iVar2,u1ShadowHi,u1ShadowLo,ustride,uorder,uVar3,in_stack_ffffff88,
               in_stack_ffffff8c,in_stack_ffffff90,vstride,vorder,points,listRecord + 1,u1,
               u2,v1,v2,in_f5,in_f6,in_f7,in_f8,in_f9,in_f10,in_f11,in_f12,in_f13)
    ;
  }
  else {
    if (size != 4) goto LAB_00071ffc;
    iVar2 = (100 - uorder * vorder) * -0x10 + 0x664;
    uVar3 = ustride;
    listRecord = (undefined4 *)
             _gleAddListItem(glContext,PTR__glMap2VertexAttrib4ARB_ListExec_00110194,iVar2);
    if (listRecord == (undefined4 *)0x0) goto LAB_00072010;
    ((void (*)())_gleMap2VertexAttrib4dLoad)(glContext,extraout_r4_02,iVar2,u1ShadowHi,u1ShadowLo,ustride,uorder,uVar3,in_stack_ffffff88,
               in_stack_ffffff8c,in_stack_ffffff90,vstride,vorder,points,listRecord + 1,u1,
               u2,v1,v2,in_f5,in_f6,in_f7,in_f8,in_f9,in_f10,in_f11,in_f12,in_f13)
    ;
  }
  *listRecord = index;
LAB_00072010:
  return;
}

/* _glMapVertexAttrib2dARB_Exec @ 0x7201c (572 bytes) */
void _glMapVertexAttrib2dARB_Exec(int glContext,uint index,uint size,undefined4 u1ShadowHi,undefined4 u1ShadowLo,undefined4 u2ShadowHi,undefined4 u2ShadowLo,int ustride,int uorder,undefined4 v1ShadowHi,undefined4 v1ShadowLo,undefined4 v2ShadowHi,undefined4 v2ShadowLo,int vstride,int vorder,undefined4 points,double u1,double u2,double v1,double v2)
{
  undefined4 glErrorCode;
  int mapData;
  undefined4 extraout_r4;
  uint uVar3;
  int iVar4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  double in_f9;
  double in_f10;
  double in_f11;
  double in_f12;
  double in_f13;
  undefined4 in_stack_ffffff88;
  undefined4 in_stack_ffffff8c;
  undefined4 in_stack_ffffff90;
  
  uVar3 = size;
  iVar4 = ustride;
  mapData = _gleGetMapData(glContext);
  if (*(short *)(glContext + 0x4a10) < 0) {
    if ((((index < 0x10) && (u1 != u2)) && (v1 != v2)) &&
       (((0 < uorder && (uorder < 0xb)) && ((0 < vorder && (vorder < 0xb)))))) {
      if (size == 2) {
        if ((1 < ustride) && (1 < vstride)) {
          ((void (*)())_gleMap2VertexAttrib2dLoad)(glContext,extraout_r4,uVar3,u1ShadowHi,u1ShadowLo,ustride,uorder,iVar4,
                     in_stack_ffffff88,in_stack_ffffff8c,in_stack_ffffff90,vstride,vorder,
                     points,mapData + index * 0x660 + 0x37a8,u1,u2,v1,v2,
                     in_f5,in_f6,in_f7,in_f8,in_f9,in_f10,in_f11,in_f12,in_f13);
          goto LAB_00072228;
        }
      }
      else if (size < 3) {
        if (((size == 1) && (0 < ustride)) && (0 < vstride)) {
          ((void (*)())_gleMap2VertexAttrib1dLoad)(glContext,extraout_r4,uVar3,u1ShadowHi,u1ShadowLo,ustride,uorder,iVar4,
                     in_stack_ffffff88,in_stack_ffffff8c,in_stack_ffffff90,vstride,vorder,
                     points,mapData + index * 0x660 + 0x37a8,u1,u2,v1,v2,
                     in_f5,in_f6,in_f7,in_f8,in_f9,in_f10,in_f11,in_f12,in_f13);
          goto LAB_00072228;
        }
      }
      else if (size == 3) {
        if ((2 < ustride) && (2 < vstride)) {
          ((void (*)())_gleMap2VertexAttrib3dLoad)(glContext,extraout_r4,uVar3,u1ShadowHi,u1ShadowLo,ustride,uorder,iVar4,
                     in_stack_ffffff88,in_stack_ffffff8c,in_stack_ffffff90,vstride,vorder,
                     points,mapData + index * 0x660 + 0x37a8,u1,u2,v1,v2,
                     in_f5,in_f6,in_f7,in_f8,in_f9,in_f10,in_f11,in_f12,in_f13);
          goto LAB_00072228;
        }
      }
      else if (((size == 4) && (3 < ustride)) && (3 < vstride)) {
        ((void (*)())_gleMap2VertexAttrib4dLoad)(glContext,extraout_r4,uVar3,u1ShadowHi,u1ShadowLo,ustride,uorder,iVar4,in_stack_ffffff88
                   ,in_stack_ffffff8c,in_stack_ffffff90,vstride,vorder,points,
                   mapData + index * 0x660 + 0x37a8,u1,u2,v1,v2,in_f5,in_f6,
                   in_f7,in_f8,in_f9,in_f10,in_f11,in_f12,in_f13);
LAB_00072228:
        *(char *)(index + mapData + 0x9db8) = (char)size;
        goto LAB_0007224c;
      }
    }
    if (*(int *)(glContext + 0x7574) != 0) goto LAB_0007224c;
    glErrorCode = 0x501;
  }
  else {
    if (*(int *)(glContext + 0x7574) != 0) goto LAB_0007224c;
    glErrorCode = 0x502;
  }
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
LAB_0007224c:
  return;
}

/* _glMapVertexAttrib2dARB_CompExec @ 0x72258 (168 bytes) */
void _glMapVertexAttrib2dARB_CompExec(undefined4 glContext,undefined4 index,undefined4 size,undefined4 u1ShadowHi,undefined4 u1ShadowLo,undefined4 u2ShadowHi,undefined4 u2ShadowLo,undefined4 ustride,undefined4 uorder,undefined4 v1ShadowHi,undefined4 v1ShadowLo,undefined4 v2ShadowHi,undefined4 v2ShadowLo,undefined4 vstride,undefined4 vorder,undefined4 points,double u1,double u2,double v1,double v2)
{
  undefined4 in_stack_ffffff8c;
  undefined4 in_stack_ffffff90;
  undefined4 in_stack_ffffff94;
  undefined4 in_stack_ffffff98;
  
  ((void (*)())_glMapVertexAttrib2dARB_Comp)(glContext,index,size,u1ShadowHi,u1ShadowLo,u2ShadowHi,u2ShadowLo,ustride,uorder,
             in_stack_ffffff8c,in_stack_ffffff90,in_stack_ffffff94,in_stack_ffffff98,vstride,
             vorder,points,u1,u2,v1,v2);
  ((void (*)())_glMapVertexAttrib2dARB_Exec)(glContext,index,size,u1ShadowHi,u1ShadowLo,u2ShadowHi,u2ShadowLo,ustride,uorder,v1ShadowHi,
             v1ShadowLo,v2ShadowHi,v2ShadowLo,vstride,vorder,points,u1,u2,v1,
             v2);
  return;
}

/* _glGetMapdv_Exec @ 0x72300 (3736 bytes) */
void _glGetMapdv_Exec(glContext, target, query, v)
  int glContext;
  undefined4 target;
  uint query;
  double *v;
{
  float fVar1;
  undefined4 glErrorCode;
  uint uVar3;
  int iVar4;
  float *srcCursor;
  uint *srcCursor2;
  uint *mapData;
  uint uVar8;
  uint loopIndex2;
  uint uVar9;
  double *pdVar10;
  double *dstCursor;
  int iVar11;
  uint loopIndex;
  double dVar13;
  
  mapData = (uint *)_gleGetMapData(glContext);
  dVar13 = DOUBLE_00108d70;
  if (*(short *)(glContext + 0x4a10) < 0) {
    switch(target) {
    case 0xd90:
      if (query == 0xa01) {
        uVar8 = mapData[0x70];
LAB_00072910:
        *v = (double)CONCAT44(0x43300000,uVar8) - DOUBLE_00108d70;
        return;
      }
      if (query < 0xa02) {
        if (query == 0xa00) {
          loopIndex2 = 0;
          srcCursor2 = mapData;
          if (mapData[0x70] == 0) {
            return;
          }
          do {
            loopIndex2 = loopIndex2 + 1;
            *v = (double)GH_U2F((unsigned int)(srcCursor2[0x74]));
            v[1] = (double)GH_U2F((unsigned int)(srcCursor2[0x75]));
            v[2] = (double)GH_U2F((unsigned int)(srcCursor2[0x76]));
            v[3] = (double)GH_U2F((unsigned int)(srcCursor2[0x77]));
            v = v + 4;
            srcCursor2 = srcCursor2 + 4;
          } while (loopIndex2 < mapData[0x70]);
          return;
        }
      }
      else if (query == 0xa02) {
        *v = (double)GH_U2F((unsigned int)(mapData[0x71]));
        dVar13 = (double)GH_U2F((unsigned int)(mapData[0x72]));
LAB_00072928:
        v[1] = dVar13;
        return;
      }
      break;
    case 0xd91:
      if (query == 0xa01) {
        uVar8 = mapData[0x9c];
        goto LAB_00072910;
      }
      if (query < 0xa02) {
        if (query == 0xa00) {
          loopIndex2 = 0;
          if (mapData[0x9c] == 0) {
            return;
          }
          srcCursor = (float *)(mapData + 0xa0);
          do {
            fVar1 = *srcCursor;
            loopIndex2 = loopIndex2 + 1;
            srcCursor = srcCursor + 1;
            *v = (double)fVar1;
            v = v + 1;
          } while (loopIndex2 < mapData[0x9c]);
          return;
        }
      }
      else if (query == 0xa02) {
        *v = (double)GH_U2F((unsigned int)(mapData[0x9d]));
        dVar13 = (double)GH_U2F((unsigned int)(mapData[0x9e]));
        goto LAB_00072928;
      }
      break;
    case 0xd92:
      if (query == 0xa01) {
        uVar8 = mapData[0x4e];
        goto LAB_00072910;
      }
      if (query < 0xa02) {
        if (query == 0xa00) {
          loopIndex2 = 0;
          srcCursor2 = mapData;
          if (mapData[0x4e] == 0) {
            return;
          }
          do {
            loopIndex2 = loopIndex2 + 1;
            *v = (double)GH_U2F((unsigned int)(srcCursor2[0x52]));
            v[1] = (double)GH_U2F((unsigned int)(srcCursor2[0x53]));
            v[2] = (double)GH_U2F((unsigned int)(srcCursor2[0x54]));
            v = v + 3;
            srcCursor2 = srcCursor2 + 3;
          } while (loopIndex2 < mapData[0x4e]);
          return;
        }
      }
      else if (query == 0xa02) {
        *v = (double)GH_U2F((unsigned int)(mapData[0x4f]));
        dVar13 = (double)GH_U2F((unsigned int)(mapData[0x50]));
        goto LAB_00072928;
      }
      break;
    case 0xd93:
      if (query == 0xa01) {
        uVar8 = mapData[0xaa];
        goto LAB_00072910;
      }
      if (query < 0xa02) {
        if (query == 0xa00) {
          loopIndex2 = 0;
          if (mapData[0xaa] == 0) {
            return;
          }
          srcCursor = (float *)(mapData + 0xae);
          do {
            fVar1 = *srcCursor;
            loopIndex2 = loopIndex2 + 1;
            srcCursor = srcCursor + 1;
            *v = (double)fVar1;
            v = v + 1;
          } while (loopIndex2 < mapData[0xaa]);
          return;
        }
      }
      else if (query == 0xa02) {
        *v = (double)GH_U2F((unsigned int)(mapData[0xab]));
        dVar13 = (double)GH_U2F((unsigned int)(mapData[0xac]));
        goto LAB_00072928;
      }
      break;
    case 0xd94:
      if (query == 0xa01) {
        uVar8 = mapData[0xb8];
        goto LAB_00072910;
      }
      if (query < 0xa02) {
        if (query == 0xa00) {
          loopIndex2 = 0;
          srcCursor2 = mapData;
          if (mapData[0xb8] == 0) {
            return;
          }
          do {
            loopIndex2 = loopIndex2 + 1;
            *v = (double)GH_U2F((unsigned int)(srcCursor2[0xbc]));
            v[1] = (double)GH_U2F((unsigned int)(srcCursor2[0xbd]));
            v = v + 2;
            srcCursor2 = srcCursor2 + 2;
          } while (loopIndex2 < mapData[0xb8]);
          return;
        }
      }
      else if (query == 0xa02) {
        *v = (double)GH_U2F((unsigned int)(mapData[0xb9]));
        dVar13 = (double)GH_U2F((unsigned int)(mapData[0xba]));
        goto LAB_00072928;
      }
      break;
    case 0xd95:
      if (query == 0xa01) {
        uVar8 = mapData[0xd0];
        goto LAB_00072910;
      }
      if (query < 0xa02) {
        if (query == 0xa00) {
          loopIndex2 = 0;
          srcCursor2 = mapData;
          if (mapData[0xd0] == 0) {
            return;
          }
          do {
            loopIndex2 = loopIndex2 + 1;
            *v = (double)GH_U2F((unsigned int)(srcCursor2[0xd4]));
            v[1] = (double)GH_U2F((unsigned int)(srcCursor2[0xd5]));
            v[2] = (double)GH_U2F((unsigned int)(srcCursor2[0xd6]));
            v = v + 3;
            srcCursor2 = srcCursor2 + 3;
          } while (loopIndex2 < mapData[0xd0]);
          return;
        }
      }
      else if (query == 0xa02) {
        *v = (double)GH_U2F((unsigned int)(mapData[0xd1]));
        dVar13 = (double)GH_U2F((unsigned int)(mapData[0xd2]));
        goto LAB_00072928;
      }
      break;
    case 0xd96:
      if (query == 0xa01) {
        uVar8 = mapData[0xf2];
        goto LAB_00072910;
      }
      if (query < 0xa02) {
        if (query == 0xa00) {
          loopIndex2 = 0;
          srcCursor2 = mapData;
          if (mapData[0xf2] == 0) {
            return;
          }
          do {
            loopIndex2 = loopIndex2 + 1;
            *v = (double)GH_U2F((unsigned int)(srcCursor2[0xf6]));
            v[1] = (double)GH_U2F((unsigned int)(srcCursor2[0xf7]));
            v[2] = (double)GH_U2F((unsigned int)(srcCursor2[0xf8]));
            v[3] = (double)GH_U2F((unsigned int)(srcCursor2[0xf9]));
            v = v + 4;
            srcCursor2 = srcCursor2 + 4;
          } while (loopIndex2 < mapData[0xf2]);
          return;
        }
      }
      else if (query == 0xa02) {
        *v = (double)GH_U2F((unsigned int)(mapData[0xf3]));
        dVar13 = (double)GH_U2F((unsigned int)(mapData[0xf4]));
        goto LAB_00072928;
      }
      break;
    case 0xd97:
      if (query == 0xa01) {
        uVar8 = *mapData;
        goto LAB_00072910;
      }
      if (query < 0xa02) {
        if (query == 0xa00) {
          loopIndex2 = 0;
          srcCursor2 = mapData;
          if (*mapData == 0) {
            return;
          }
          do {
            loopIndex2 = loopIndex2 + 1;
            *v = (double)GH_U2F((unsigned int)(srcCursor2[4]));
            v[1] = (double)GH_U2F((unsigned int)(srcCursor2[5]));
            v[2] = (double)GH_U2F((unsigned int)(srcCursor2[6]));
            v = v + 3;
            srcCursor2 = srcCursor2 + 3;
          } while (loopIndex2 < *mapData);
          return;
        }
      }
      else if (query == 0xa02) {
        *v = (double)GH_U2F((unsigned int)(mapData[1]));
        dVar13 = (double)GH_U2F((unsigned int)(mapData[2]));
        goto LAB_00072928;
      }
      break;
    case 0xd98:
      if (query == 0xa01) {
        uVar8 = mapData[0x22];
        goto LAB_00072910;
      }
      if (query < 0xa02) {
        if (query == 0xa00) {
          loopIndex2 = 0;
          srcCursor2 = mapData;
          if (mapData[0x22] == 0) {
            return;
          }
          do {
            loopIndex2 = loopIndex2 + 1;
            *v = (double)GH_U2F((unsigned int)(srcCursor2[0x26]));
            v[1] = (double)GH_U2F((unsigned int)(srcCursor2[0x27]));
            v[2] = (double)GH_U2F((unsigned int)(srcCursor2[0x28]));
            v[3] = (double)GH_U2F((unsigned int)(srcCursor2[0x29]));
            v = v + 4;
            srcCursor2 = srcCursor2 + 4;
          } while (loopIndex2 < mapData[0x22]);
          return;
        }
      }
      else if (query == 0xa02) {
        *v = (double)GH_U2F((unsigned int)(mapData[0x23]));
        dVar13 = (double)GH_U2F((unsigned int)(mapData[0x24]));
        goto LAB_00072928;
      }
      break;
    case 0xdb0:
      if (query == 0xa01) {
        *v = (double)CONCAT44(0x43300000,mapData[0x51e]) - DOUBLE_00108d70;
        uVar8 = mapData[0x51f];
LAB_000731d8:
        v[1] = (double)CONCAT44(0x43300000,uVar8) - dVar13;
        return;
      }
      if (query < 0xa02) {
        if (query == 0xa00) {
          uVar9 = mapData[0x51f];
          iVar11 = 0;
          loopIndex2 = 0;
          if (uVar9 == 0) {
            return;
          }
          uVar3 = mapData[0x51e];
          do {
            loopIndex = 0;
            if (uVar3 != 0) {
              pdVar10 = v + iVar11;
              do {
                iVar11 = iVar11 + 4;
                iVar4 = loopIndex2 * uVar3 + loopIndex;
                loopIndex = loopIndex + 1;
                *pdVar10 = (double)GH_U2F((unsigned int)(mapData[iVar4 * 4 + 0x526]));
                pdVar10[1] = (double)GH_U2F((unsigned int)(mapData[iVar4 * 4 + 0x527]));
                pdVar10[2] = (double)GH_U2F((unsigned int)(mapData[iVar4 * 4 + 0x528]));
                pdVar10[3] = (double)GH_U2F((unsigned int)(mapData[iVar4 * 4 + 0x529]));
                uVar3 = mapData[0x51e];
                pdVar10 = pdVar10 + 4;
              } while (loopIndex < uVar3);
              uVar9 = mapData[0x51f];
            }
            loopIndex2 = loopIndex2 + 1;
          } while (loopIndex2 < uVar9);
          return;
        }
      }
      else if (query == 0xa02) {
        *v = (double)GH_U2F((unsigned int)(mapData[0x520]));
        v[1] = (double)GH_U2F((unsigned int)(mapData[0x521]));
        v[2] = (double)GH_U2F((unsigned int)(mapData[0x522]));
        dVar13 = (double)GH_U2F((unsigned int)(mapData[0x523]));
LAB_0007320c:
        v[3] = dVar13;
        return;
      }
      break;
    case 0xdb1:
      if (query == 0xa01) {
        *v = (double)CONCAT44(0x43300000,mapData[0x6b6]) - DOUBLE_00108d70;
        uVar8 = mapData[0x6b7];
        goto LAB_000731d8;
      }
      if (query < 0xa02) {
        if (query == 0xa00) {
          uVar9 = mapData[0x6b7];
          iVar11 = 0;
          loopIndex2 = 0;
          if (uVar9 == 0) {
            return;
          }
          uVar3 = mapData[0x6b6];
          do {
            loopIndex = 0;
            if (uVar3 != 0) {
              dstCursor = v + iVar11;
              do {
                iVar11 = iVar11 + 1;
                iVar4 = loopIndex2 * uVar3 + loopIndex;
                loopIndex = loopIndex + 1;
                *dstCursor = (double)GH_U2F((unsigned int)(mapData[iVar4 + 0x6be]));
                dstCursor = dstCursor + 1;
                uVar3 = mapData[0x6b6];
              } while (loopIndex < uVar3);
              uVar9 = mapData[0x6b7];
            }
            loopIndex2 = loopIndex2 + 1;
          } while (loopIndex2 < uVar9);
          return;
        }
      }
      else if (query == 0xa02) {
        *v = (double)GH_U2F((unsigned int)(mapData[0x6b8]));
        v[1] = (double)GH_U2F((unsigned int)(mapData[0x6b9]));
        v[2] = (double)GH_U2F((unsigned int)(mapData[0x6ba]));
        dVar13 = (double)GH_U2F((unsigned int)(mapData[0x6bb]));
        goto LAB_0007320c;
      }
      break;
    case 0xdb2:
      if (query == 0xa01) {
        *v = (double)CONCAT44(0x43300000,mapData[0x3ea]) - DOUBLE_00108d70;
        uVar8 = mapData[0x3eb];
        goto LAB_000731d8;
      }
      if (query < 0xa02) {
        if (query == 0xa00) {
          uVar9 = mapData[0x3eb];
          iVar11 = 0;
          loopIndex2 = 0;
          if (uVar9 == 0) {
            return;
          }
          uVar3 = mapData[0x3ea];
          do {
            loopIndex = 0;
            if (uVar3 != 0) {
              pdVar10 = v + iVar11;
              do {
                iVar11 = iVar11 + 3;
                iVar4 = loopIndex2 * uVar3 + loopIndex;
                loopIndex = loopIndex + 1;
                *pdVar10 = (double)GH_U2F((unsigned int)(mapData[iVar4 * 3 + 0x3f2]));
                pdVar10[1] = (double)GH_U2F((unsigned int)(mapData[iVar4 * 3 + 0x3f3]));
                pdVar10[2] = (double)GH_U2F((unsigned int)(mapData[iVar4 * 3 + 0x3f4]));
                uVar3 = mapData[0x3ea];
                pdVar10 = pdVar10 + 3;
              } while (loopIndex < uVar3);
              uVar9 = mapData[0x3eb];
            }
            loopIndex2 = loopIndex2 + 1;
          } while (loopIndex2 < uVar9);
          return;
        }
      }
      else if (query == 0xa02) {
        *v = (double)GH_U2F((unsigned int)(mapData[0x3ec]));
        v[1] = (double)GH_U2F((unsigned int)(mapData[0x3ed]));
        v[2] = (double)GH_U2F((unsigned int)(mapData[0x3ee]));
        dVar13 = (double)GH_U2F((unsigned int)(mapData[0x3ef]));
        goto LAB_0007320c;
      }
      break;
    case 0xdb3:
      if (query == 0xa01) {
        *v = (double)CONCAT44(0x43300000,mapData[0x722]) - DOUBLE_00108d70;
        uVar8 = mapData[0x723];
        goto LAB_000731d8;
      }
      if (query < 0xa02) {
        if (query == 0xa00) {
          uVar9 = mapData[0x723];
          iVar11 = 0;
          loopIndex2 = 0;
          if (uVar9 == 0) {
            return;
          }
          uVar3 = mapData[0x722];
          do {
            loopIndex = 0;
            if (uVar3 != 0) {
              dstCursor = v + iVar11;
              do {
                iVar11 = iVar11 + 1;
                iVar4 = loopIndex2 * uVar3 + loopIndex;
                loopIndex = loopIndex + 1;
                *dstCursor = (double)GH_U2F((unsigned int)(mapData[iVar4 + 0x72a]));
                dstCursor = dstCursor + 1;
                uVar3 = mapData[0x722];
              } while (loopIndex < uVar3);
              uVar9 = mapData[0x723];
            }
            loopIndex2 = loopIndex2 + 1;
          } while (loopIndex2 < uVar9);
          return;
        }
      }
      else if (query == 0xa02) {
        *v = (double)GH_U2F((unsigned int)(mapData[0x724]));
        v[1] = (double)GH_U2F((unsigned int)(mapData[0x725]));
        v[2] = (double)GH_U2F((unsigned int)(mapData[0x726]));
        dVar13 = (double)GH_U2F((unsigned int)(mapData[0x727]));
        goto LAB_0007320c;
      }
      break;
    case 0xdb4:
      if (query == 0xa01) {
        *v = (double)CONCAT44(0x43300000,mapData[0x78e]) - DOUBLE_00108d70;
        uVar8 = mapData[0x78f];
        goto LAB_000731d8;
      }
      if (query < 0xa02) {
        if (query == 0xa00) {
          uVar9 = mapData[0x78f];
          iVar11 = 0;
          loopIndex2 = 0;
          if (uVar9 == 0) {
            return;
          }
          uVar3 = mapData[0x78e];
          do {
            loopIndex = 0;
            if (uVar3 != 0) {
              pdVar10 = v + iVar11;
              do {
                iVar11 = iVar11 + 2;
                iVar4 = loopIndex2 * uVar3 + loopIndex;
                loopIndex = loopIndex + 1;
                *pdVar10 = (double)GH_U2F((unsigned int)(mapData[iVar4 * 2 + 0x796]));
                pdVar10[1] = (double)GH_U2F((unsigned int)(mapData[iVar4 * 2 + 0x797]));
                uVar3 = mapData[0x78e];
                pdVar10 = pdVar10 + 2;
              } while (loopIndex < uVar3);
              uVar9 = mapData[0x78f];
            }
            loopIndex2 = loopIndex2 + 1;
          } while (loopIndex2 < uVar9);
          return;
        }
      }
      else if (query == 0xa02) {
        *v = (double)GH_U2F((unsigned int)(mapData[0x790]));
        v[1] = (double)GH_U2F((unsigned int)(mapData[0x791]));
        v[2] = (double)GH_U2F((unsigned int)(mapData[0x792]));
        dVar13 = (double)GH_U2F((unsigned int)(mapData[0x793]));
        goto LAB_0007320c;
      }
      break;
    case 0xdb5:
      if (query == 0xa01) {
        *v = (double)CONCAT44(0x43300000,mapData[0x85e]) - DOUBLE_00108d70;
        uVar8 = mapData[0x85f];
        goto LAB_000731d8;
      }
      if (query < 0xa02) {
        if (query == 0xa00) {
          uVar9 = mapData[0x85f];
          iVar11 = 0;
          loopIndex2 = 0;
          if (uVar9 == 0) {
            return;
          }
          uVar3 = mapData[0x85e];
          do {
            loopIndex = 0;
            if (uVar3 != 0) {
              pdVar10 = v + iVar11;
              do {
                iVar11 = iVar11 + 3;
                iVar4 = loopIndex2 * uVar3 + loopIndex;
                loopIndex = loopIndex + 1;
                *pdVar10 = (double)GH_U2F((unsigned int)(mapData[iVar4 * 3 + 0x866]));
                pdVar10[1] = (double)GH_U2F((unsigned int)(mapData[iVar4 * 3 + 0x867]));
                pdVar10[2] = (double)GH_U2F((unsigned int)(mapData[iVar4 * 3 + 0x868]));
                uVar3 = mapData[0x85e];
                pdVar10 = pdVar10 + 3;
              } while (loopIndex < uVar3);
              uVar9 = mapData[0x85f];
            }
            loopIndex2 = loopIndex2 + 1;
          } while (loopIndex2 < uVar9);
          return;
        }
      }
      else if (query == 0xa02) {
        *v = (double)GH_U2F((unsigned int)(mapData[0x860]));
        v[1] = (double)GH_U2F((unsigned int)(mapData[0x861]));
        v[2] = (double)GH_U2F((unsigned int)(mapData[0x862]));
        dVar13 = (double)GH_U2F((unsigned int)(mapData[0x863]));
        goto LAB_0007320c;
      }
      break;
    case 0xdb6:
      if (query == 0xa01) {
        *v = (double)CONCAT44(0x43300000,mapData[0x992]) - DOUBLE_00108d70;
        uVar8 = mapData[0x993];
        goto LAB_000731d8;
      }
      if (query < 0xa02) {
        if (query == 0xa00) {
          uVar9 = mapData[0x993];
          iVar11 = 0;
          loopIndex2 = 0;
          if (uVar9 == 0) {
            return;
          }
          uVar3 = mapData[0x992];
          do {
            loopIndex = 0;
            if (uVar3 != 0) {
              pdVar10 = v + iVar11;
              do {
                iVar11 = iVar11 + 4;
                iVar4 = loopIndex2 * uVar3 + loopIndex;
                loopIndex = loopIndex + 1;
                *pdVar10 = (double)GH_U2F((unsigned int)(mapData[iVar4 * 4 + 0x99a]));
                pdVar10[1] = (double)GH_U2F((unsigned int)(mapData[iVar4 * 4 + 0x99b]));
                pdVar10[2] = (double)GH_U2F((unsigned int)(mapData[iVar4 * 4 + 0x99c]));
                pdVar10[3] = (double)GH_U2F((unsigned int)(mapData[iVar4 * 4 + 0x99d]));
                uVar3 = mapData[0x992];
                pdVar10 = pdVar10 + 4;
              } while (loopIndex < uVar3);
              uVar9 = mapData[0x993];
            }
            loopIndex2 = loopIndex2 + 1;
          } while (loopIndex2 < uVar9);
          return;
        }
      }
      else if (query == 0xa02) {
        *v = (double)GH_U2F((unsigned int)(mapData[0x994]));
        v[1] = (double)GH_U2F((unsigned int)(mapData[0x995]));
        v[2] = (double)GH_U2F((unsigned int)(mapData[0x996]));
        dVar13 = (double)GH_U2F((unsigned int)(mapData[0x997]));
        goto LAB_0007320c;
      }
      break;
    case 0xdb7:
      if (query == 0xa01) {
        *v = (double)CONCAT44(0x43300000,mapData[0x11e]) - DOUBLE_00108d70;
        uVar8 = mapData[0x11f];
        goto LAB_000731d8;
      }
      if (query < 0xa02) {
        if (query == 0xa00) {
          uVar9 = mapData[0x11f];
          iVar11 = 0;
          loopIndex2 = 0;
          if (uVar9 == 0) {
            return;
          }
          uVar3 = mapData[0x11e];
          do {
            loopIndex = 0;
            if (uVar3 != 0) {
              pdVar10 = v + iVar11;
              do {
                iVar11 = iVar11 + 3;
                iVar4 = loopIndex2 * uVar3 + loopIndex;
                loopIndex = loopIndex + 1;
                *pdVar10 = (double)GH_U2F((unsigned int)(mapData[iVar4 * 3 + 0x126]));
                pdVar10[1] = (double)GH_U2F((unsigned int)(mapData[iVar4 * 3 + 0x127]));
                pdVar10[2] = (double)GH_U2F((unsigned int)(mapData[iVar4 * 3 + 0x128]));
                uVar3 = mapData[0x11e];
                pdVar10 = pdVar10 + 3;
              } while (loopIndex < uVar3);
              uVar9 = mapData[0x11f];
            }
            loopIndex2 = loopIndex2 + 1;
          } while (loopIndex2 < uVar9);
          return;
        }
      }
      else if (query == 0xa02) {
        *v = (double)GH_U2F((unsigned int)(mapData[0x120]));
        v[1] = (double)GH_U2F((unsigned int)(mapData[0x121]));
        v[2] = (double)GH_U2F((unsigned int)(mapData[0x122]));
        dVar13 = (double)GH_U2F((unsigned int)(mapData[0x123]));
        goto LAB_0007320c;
      }
      break;
    case 0xdb8:
      if (query == 0xa01) {
        *v = (double)CONCAT44(0x43300000,mapData[0x252]) - DOUBLE_00108d70;
        uVar8 = mapData[0x253];
        goto LAB_000731d8;
      }
      if (query < 0xa02) {
        if (query == 0xa00) {
          uVar9 = mapData[0x253];
          iVar11 = 0;
          loopIndex2 = 0;
          if (uVar9 == 0) {
            return;
          }
          uVar3 = mapData[0x252];
          do {
            loopIndex = 0;
            if (uVar3 != 0) {
              pdVar10 = v + iVar11;
              do {
                iVar11 = iVar11 + 4;
                iVar4 = loopIndex2 * uVar3 + loopIndex;
                loopIndex = loopIndex + 1;
                *pdVar10 = (double)GH_U2F((unsigned int)(mapData[iVar4 * 4 + 0x25a]));
                pdVar10[1] = (double)GH_U2F((unsigned int)(mapData[iVar4 * 4 + 0x25b]));
                pdVar10[2] = (double)GH_U2F((unsigned int)(mapData[iVar4 * 4 + 0x25c]));
                pdVar10[3] = (double)GH_U2F((unsigned int)(mapData[iVar4 * 4 + 0x25d]));
                uVar3 = mapData[0x252];
                pdVar10 = pdVar10 + 4;
              } while (loopIndex < uVar3);
              uVar9 = mapData[0x253];
            }
            loopIndex2 = loopIndex2 + 1;
          } while (loopIndex2 < uVar9);
          return;
        }
      }
      else if (query == 0xa02) {
        *v = (double)GH_U2F((unsigned int)(mapData[0x254]));
        v[1] = (double)GH_U2F((unsigned int)(mapData[0x255]));
        v[2] = (double)GH_U2F((unsigned int)(mapData[0x256]));
        dVar13 = (double)GH_U2F((unsigned int)(mapData[599]));
        goto LAB_0007320c;
      }
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
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glGetMapfv_Exec @ 0x7323c (3780 bytes) */
void _glGetMapfv_Exec(glContext, target, query, v)
  int glContext;
  undefined4 target;
  uint query;
  float *v;
{
  float fVar1;
  double dVar2;
  undefined4 glErrorCode;
  uint uVar4;
  int iVar5;
  float *pfVar6;
  float *dstCursor;
  float *srcCursor;
  uint *srcCursor2;
  uint *mapData;
  uint uVar9;
  uint loopIndex2;
  uint uVar10;
  int iVar11;
  uint loopIndex;
  
  mapData = (uint *)_gleGetMapData(glContext);
  dVar2 = DOUBLE_00108d70;
  if (*(short *)(glContext + 0x4a10) < 0) {
    switch(target) {
    case 0xd90:
      if (query == 0xa01) {
        uVar9 = mapData[0x70];
LAB_0007384c:
        *v = (float)((double)CONCAT44(0x43300000,uVar9) - DOUBLE_00108d70);
        return;
      }
      if (query < 0xa02) {
        if (query == 0xa00) {
          loopIndex2 = 0;
          srcCursor2 = mapData;
          if (mapData[0x70] == 0) {
            return;
          }
          do {
            loopIndex2 = loopIndex2 + 1;
            *v = GH_U2F((unsigned int)(srcCursor2[0x74]));
            v[1] = GH_U2F((unsigned int)(srcCursor2[0x75]));
            v[2] = GH_U2F((unsigned int)(srcCursor2[0x76]));
            v[3] = GH_U2F((unsigned int)(srcCursor2[0x77]));
            v = v + 4;
            srcCursor2 = srcCursor2 + 4;
          } while (loopIndex2 < mapData[0x70]);
          return;
        }
      }
      else if (query == 0xa02) {
        *v = GH_U2F((unsigned int)(mapData[0x71]));
        fVar1 = GH_U2F((unsigned int)(mapData[0x72]));
LAB_00073868:
        v[1] = fVar1;
        return;
      }
      break;
    case 0xd91:
      if (query == 0xa01) {
        uVar9 = mapData[0x9c];
        goto LAB_0007384c;
      }
      if (query < 0xa02) {
        if (query == 0xa00) {
          loopIndex2 = 0;
          if (mapData[0x9c] == 0) {
            return;
          }
          srcCursor = (float *)(mapData + 0xa0);
          do {
            fVar1 = *srcCursor;
            loopIndex2 = loopIndex2 + 1;
            srcCursor = srcCursor + 1;
            *v = fVar1;
            v = v + 1;
          } while (loopIndex2 < mapData[0x9c]);
          return;
        }
      }
      else if (query == 0xa02) {
        *v = GH_U2F((unsigned int)(mapData[0x9d]));
        fVar1 = GH_U2F((unsigned int)(mapData[0x9e]));
        goto LAB_00073868;
      }
      break;
    case 0xd92:
      if (query == 0xa01) {
        uVar9 = mapData[0x4e];
        goto LAB_0007384c;
      }
      if (query < 0xa02) {
        if (query == 0xa00) {
          loopIndex2 = 0;
          srcCursor2 = mapData;
          if (mapData[0x4e] == 0) {
            return;
          }
          do {
            loopIndex2 = loopIndex2 + 1;
            *v = GH_U2F((unsigned int)(srcCursor2[0x52]));
            v[1] = GH_U2F((unsigned int)(srcCursor2[0x53]));
            v[2] = GH_U2F((unsigned int)(srcCursor2[0x54]));
            v = v + 3;
            srcCursor2 = srcCursor2 + 3;
          } while (loopIndex2 < mapData[0x4e]);
          return;
        }
      }
      else if (query == 0xa02) {
        *v = GH_U2F((unsigned int)(mapData[0x4f]));
        fVar1 = GH_U2F((unsigned int)(mapData[0x50]));
        goto LAB_00073868;
      }
      break;
    case 0xd93:
      if (query == 0xa01) {
        uVar9 = mapData[0xaa];
        goto LAB_0007384c;
      }
      if (query < 0xa02) {
        if (query == 0xa00) {
          loopIndex2 = 0;
          if (mapData[0xaa] == 0) {
            return;
          }
          srcCursor = (float *)(mapData + 0xae);
          do {
            fVar1 = *srcCursor;
            loopIndex2 = loopIndex2 + 1;
            srcCursor = srcCursor + 1;
            *v = fVar1;
            v = v + 1;
          } while (loopIndex2 < mapData[0xaa]);
          return;
        }
      }
      else if (query == 0xa02) {
        *v = GH_U2F((unsigned int)(mapData[0xab]));
        fVar1 = GH_U2F((unsigned int)(mapData[0xac]));
        goto LAB_00073868;
      }
      break;
    case 0xd94:
      if (query == 0xa01) {
        uVar9 = mapData[0xb8];
        goto LAB_0007384c;
      }
      if (query < 0xa02) {
        if (query == 0xa00) {
          loopIndex2 = 0;
          srcCursor2 = mapData;
          if (mapData[0xb8] == 0) {
            return;
          }
          do {
            loopIndex2 = loopIndex2 + 1;
            *v = GH_U2F((unsigned int)(srcCursor2[0xbc]));
            v[1] = GH_U2F((unsigned int)(srcCursor2[0xbd]));
            v = v + 2;
            srcCursor2 = srcCursor2 + 2;
          } while (loopIndex2 < mapData[0xb8]);
          return;
        }
      }
      else if (query == 0xa02) {
        *v = GH_U2F((unsigned int)(mapData[0xb9]));
        fVar1 = GH_U2F((unsigned int)(mapData[0xba]));
        goto LAB_00073868;
      }
      break;
    case 0xd95:
      if (query == 0xa01) {
        uVar9 = mapData[0xd0];
        goto LAB_0007384c;
      }
      if (query < 0xa02) {
        if (query == 0xa00) {
          loopIndex2 = 0;
          srcCursor2 = mapData;
          if (mapData[0xd0] == 0) {
            return;
          }
          do {
            loopIndex2 = loopIndex2 + 1;
            *v = GH_U2F((unsigned int)(srcCursor2[0xd4]));
            v[1] = GH_U2F((unsigned int)(srcCursor2[0xd5]));
            v[2] = GH_U2F((unsigned int)(srcCursor2[0xd6]));
            v = v + 3;
            srcCursor2 = srcCursor2 + 3;
          } while (loopIndex2 < mapData[0xd0]);
          return;
        }
      }
      else if (query == 0xa02) {
        *v = GH_U2F((unsigned int)(mapData[0xd1]));
        fVar1 = GH_U2F((unsigned int)(mapData[0xd2]));
        goto LAB_00073868;
      }
      break;
    case 0xd96:
      if (query == 0xa01) {
        uVar9 = mapData[0xf2];
        goto LAB_0007384c;
      }
      if (query < 0xa02) {
        if (query == 0xa00) {
          loopIndex2 = 0;
          srcCursor2 = mapData;
          if (mapData[0xf2] == 0) {
            return;
          }
          do {
            loopIndex2 = loopIndex2 + 1;
            *v = GH_U2F((unsigned int)(srcCursor2[0xf6]));
            v[1] = GH_U2F((unsigned int)(srcCursor2[0xf7]));
            v[2] = GH_U2F((unsigned int)(srcCursor2[0xf8]));
            v[3] = GH_U2F((unsigned int)(srcCursor2[0xf9]));
            v = v + 4;
            srcCursor2 = srcCursor2 + 4;
          } while (loopIndex2 < mapData[0xf2]);
          return;
        }
      }
      else if (query == 0xa02) {
        *v = GH_U2F((unsigned int)(mapData[0xf3]));
        fVar1 = GH_U2F((unsigned int)(mapData[0xf4]));
        goto LAB_00073868;
      }
      break;
    case 0xd97:
      if (query == 0xa01) {
        uVar9 = *mapData;
        goto LAB_0007384c;
      }
      if (query < 0xa02) {
        if (query == 0xa00) {
          loopIndex2 = 0;
          srcCursor2 = mapData;
          if (*mapData == 0) {
            return;
          }
          do {
            loopIndex2 = loopIndex2 + 1;
            *v = GH_U2F((unsigned int)(srcCursor2[4]));
            v[1] = GH_U2F((unsigned int)(srcCursor2[5]));
            v[2] = GH_U2F((unsigned int)(srcCursor2[6]));
            v = v + 3;
            srcCursor2 = srcCursor2 + 3;
          } while (loopIndex2 < *mapData);
          return;
        }
      }
      else if (query == 0xa02) {
        *v = GH_U2F((unsigned int)(mapData[1]));
        fVar1 = GH_U2F((unsigned int)(mapData[2]));
        goto LAB_00073868;
      }
      break;
    case 0xd98:
      if (query == 0xa01) {
        uVar9 = mapData[0x22];
        goto LAB_0007384c;
      }
      if (query < 0xa02) {
        if (query == 0xa00) {
          loopIndex2 = 0;
          srcCursor2 = mapData;
          if (mapData[0x22] == 0) {
            return;
          }
          do {
            loopIndex2 = loopIndex2 + 1;
            *v = GH_U2F((unsigned int)(srcCursor2[0x26]));
            v[1] = GH_U2F((unsigned int)(srcCursor2[0x27]));
            v[2] = GH_U2F((unsigned int)(srcCursor2[0x28]));
            v[3] = GH_U2F((unsigned int)(srcCursor2[0x29]));
            v = v + 4;
            srcCursor2 = srcCursor2 + 4;
          } while (loopIndex2 < mapData[0x22]);
          return;
        }
      }
      else if (query == 0xa02) {
        *v = GH_U2F((unsigned int)(mapData[0x23]));
        fVar1 = GH_U2F((unsigned int)(mapData[0x24]));
        goto LAB_00073868;
      }
      break;
    case 0xdb0:
      if (query == 0xa01) {
        *v = (float)((double)CONCAT44(0x43300000,mapData[0x51e]) - DOUBLE_00108d70);
        uVar9 = mapData[0x51f];
LAB_0007413c:
        v[1] = (float)((double)CONCAT44(0x43300000,uVar9) - dVar2);
        return;
      }
      if (query < 0xa02) {
        if (query == 0xa00) {
          uVar10 = mapData[0x51f];
          iVar11 = 0;
          loopIndex2 = 0;
          if (uVar10 == 0) {
            return;
          }
          uVar4 = mapData[0x51e];
          do {
            loopIndex = 0;
            if (uVar4 != 0) {
              pfVar6 = v + iVar11;
              do {
                iVar11 = iVar11 + 4;
                iVar5 = loopIndex2 * uVar4 + loopIndex;
                loopIndex = loopIndex + 1;
                *pfVar6 = GH_U2F((unsigned int)(mapData[iVar5 * 4 + 0x526]));
                pfVar6[1] = GH_U2F((unsigned int)(mapData[iVar5 * 4 + 0x527]));
                pfVar6[2] = GH_U2F((unsigned int)(mapData[iVar5 * 4 + 0x528]));
                pfVar6[3] = GH_U2F((unsigned int)(mapData[iVar5 * 4 + 0x529]));
                uVar4 = mapData[0x51e];
                pfVar6 = pfVar6 + 4;
              } while (loopIndex < uVar4);
              uVar10 = mapData[0x51f];
            }
            loopIndex2 = loopIndex2 + 1;
          } while (loopIndex2 < uVar10);
          return;
        }
      }
      else if (query == 0xa02) {
        *v = GH_U2F((unsigned int)(mapData[0x520]));
        v[1] = GH_U2F((unsigned int)(mapData[0x521]));
        v[2] = GH_U2F((unsigned int)(mapData[0x522]));
        fVar1 = GH_U2F((unsigned int)(mapData[0x523]));
LAB_00074174:
        v[3] = fVar1;
        return;
      }
      break;
    case 0xdb1:
      if (query == 0xa01) {
        *v = (float)((double)CONCAT44(0x43300000,mapData[0x6b6]) - DOUBLE_00108d70);
        uVar9 = mapData[0x6b7];
        goto LAB_0007413c;
      }
      if (query < 0xa02) {
        if (query == 0xa00) {
          uVar10 = mapData[0x6b7];
          iVar11 = 0;
          loopIndex2 = 0;
          if (uVar10 == 0) {
            return;
          }
          uVar4 = mapData[0x6b6];
          do {
            loopIndex = 0;
            if (uVar4 != 0) {
              dstCursor = v + iVar11;
              do {
                iVar11 = iVar11 + 1;
                iVar5 = loopIndex2 * uVar4 + loopIndex;
                loopIndex = loopIndex + 1;
                *dstCursor = GH_U2F((unsigned int)(mapData[iVar5 + 0x6be]));
                dstCursor = dstCursor + 1;
                uVar4 = mapData[0x6b6];
              } while (loopIndex < uVar4);
              uVar10 = mapData[0x6b7];
            }
            loopIndex2 = loopIndex2 + 1;
          } while (loopIndex2 < uVar10);
          return;
        }
      }
      else if (query == 0xa02) {
        *v = GH_U2F((unsigned int)(mapData[0x6b8]));
        v[1] = GH_U2F((unsigned int)(mapData[0x6b9]));
        v[2] = GH_U2F((unsigned int)(mapData[0x6ba]));
        fVar1 = GH_U2F((unsigned int)(mapData[0x6bb]));
        goto LAB_00074174;
      }
      break;
    case 0xdb2:
      if (query == 0xa01) {
        *v = (float)((double)CONCAT44(0x43300000,mapData[0x3ea]) - DOUBLE_00108d70);
        uVar9 = mapData[0x3eb];
        goto LAB_0007413c;
      }
      if (query < 0xa02) {
        if (query == 0xa00) {
          uVar10 = mapData[0x3eb];
          iVar11 = 0;
          loopIndex2 = 0;
          if (uVar10 == 0) {
            return;
          }
          uVar4 = mapData[0x3ea];
          do {
            loopIndex = 0;
            if (uVar4 != 0) {
              pfVar6 = v + iVar11;
              do {
                iVar11 = iVar11 + 3;
                iVar5 = loopIndex2 * uVar4 + loopIndex;
                loopIndex = loopIndex + 1;
                *pfVar6 = GH_U2F((unsigned int)(mapData[iVar5 * 3 + 0x3f2]));
                pfVar6[1] = GH_U2F((unsigned int)(mapData[iVar5 * 3 + 0x3f3]));
                pfVar6[2] = GH_U2F((unsigned int)(mapData[iVar5 * 3 + 0x3f4]));
                uVar4 = mapData[0x3ea];
                pfVar6 = pfVar6 + 3;
              } while (loopIndex < uVar4);
              uVar10 = mapData[0x3eb];
            }
            loopIndex2 = loopIndex2 + 1;
          } while (loopIndex2 < uVar10);
          return;
        }
      }
      else if (query == 0xa02) {
        *v = GH_U2F((unsigned int)(mapData[0x3ec]));
        v[1] = GH_U2F((unsigned int)(mapData[0x3ed]));
        v[2] = GH_U2F((unsigned int)(mapData[0x3ee]));
        fVar1 = GH_U2F((unsigned int)(mapData[0x3ef]));
        goto LAB_00074174;
      }
      break;
    case 0xdb3:
      if (query == 0xa01) {
        *v = (float)((double)CONCAT44(0x43300000,mapData[0x722]) - DOUBLE_00108d70);
        uVar9 = mapData[0x723];
        goto LAB_0007413c;
      }
      if (query < 0xa02) {
        if (query == 0xa00) {
          uVar10 = mapData[0x723];
          iVar11 = 0;
          loopIndex2 = 0;
          if (uVar10 == 0) {
            return;
          }
          uVar4 = mapData[0x722];
          do {
            loopIndex = 0;
            if (uVar4 != 0) {
              dstCursor = v + iVar11;
              do {
                iVar11 = iVar11 + 1;
                iVar5 = loopIndex2 * uVar4 + loopIndex;
                loopIndex = loopIndex + 1;
                *dstCursor = GH_U2F((unsigned int)(mapData[iVar5 + 0x72a]));
                dstCursor = dstCursor + 1;
                uVar4 = mapData[0x722];
              } while (loopIndex < uVar4);
              uVar10 = mapData[0x723];
            }
            loopIndex2 = loopIndex2 + 1;
          } while (loopIndex2 < uVar10);
          return;
        }
      }
      else if (query == 0xa02) {
        *v = GH_U2F((unsigned int)(mapData[0x724]));
        v[1] = GH_U2F((unsigned int)(mapData[0x725]));
        v[2] = GH_U2F((unsigned int)(mapData[0x726]));
        fVar1 = GH_U2F((unsigned int)(mapData[0x727]));
        goto LAB_00074174;
      }
      break;
    case 0xdb4:
      if (query == 0xa01) {
        *v = (float)((double)CONCAT44(0x43300000,mapData[0x78e]) - DOUBLE_00108d70);
        uVar9 = mapData[0x78f];
        goto LAB_0007413c;
      }
      if (query < 0xa02) {
        if (query == 0xa00) {
          uVar10 = mapData[0x78f];
          iVar11 = 0;
          loopIndex2 = 0;
          if (uVar10 == 0) {
            return;
          }
          uVar4 = mapData[0x78e];
          do {
            loopIndex = 0;
            if (uVar4 != 0) {
              pfVar6 = v + iVar11;
              do {
                iVar11 = iVar11 + 2;
                iVar5 = loopIndex2 * uVar4 + loopIndex;
                loopIndex = loopIndex + 1;
                *pfVar6 = GH_U2F((unsigned int)(mapData[iVar5 * 2 + 0x796]));
                pfVar6[1] = GH_U2F((unsigned int)(mapData[iVar5 * 2 + 0x797]));
                uVar4 = mapData[0x78e];
                pfVar6 = pfVar6 + 2;
              } while (loopIndex < uVar4);
              uVar10 = mapData[0x78f];
            }
            loopIndex2 = loopIndex2 + 1;
          } while (loopIndex2 < uVar10);
          return;
        }
      }
      else if (query == 0xa02) {
        *v = GH_U2F((unsigned int)(mapData[0x790]));
        v[1] = GH_U2F((unsigned int)(mapData[0x791]));
        v[2] = GH_U2F((unsigned int)(mapData[0x792]));
        fVar1 = GH_U2F((unsigned int)(mapData[0x793]));
        goto LAB_00074174;
      }
      break;
    case 0xdb5:
      if (query == 0xa01) {
        *v = (float)((double)CONCAT44(0x43300000,mapData[0x85e]) - DOUBLE_00108d70);
        uVar9 = mapData[0x85f];
        goto LAB_0007413c;
      }
      if (query < 0xa02) {
        if (query == 0xa00) {
          uVar10 = mapData[0x85f];
          iVar11 = 0;
          loopIndex2 = 0;
          if (uVar10 == 0) {
            return;
          }
          uVar4 = mapData[0x85e];
          do {
            loopIndex = 0;
            if (uVar4 != 0) {
              pfVar6 = v + iVar11;
              do {
                iVar11 = iVar11 + 3;
                iVar5 = loopIndex2 * uVar4 + loopIndex;
                loopIndex = loopIndex + 1;
                *pfVar6 = GH_U2F((unsigned int)(mapData[iVar5 * 3 + 0x866]));
                pfVar6[1] = GH_U2F((unsigned int)(mapData[iVar5 * 3 + 0x867]));
                pfVar6[2] = GH_U2F((unsigned int)(mapData[iVar5 * 3 + 0x868]));
                uVar4 = mapData[0x85e];
                pfVar6 = pfVar6 + 3;
              } while (loopIndex < uVar4);
              uVar10 = mapData[0x85f];
            }
            loopIndex2 = loopIndex2 + 1;
          } while (loopIndex2 < uVar10);
          return;
        }
      }
      else if (query == 0xa02) {
        *v = GH_U2F((unsigned int)(mapData[0x860]));
        v[1] = GH_U2F((unsigned int)(mapData[0x861]));
        v[2] = GH_U2F((unsigned int)(mapData[0x862]));
        fVar1 = GH_U2F((unsigned int)(mapData[0x863]));
        goto LAB_00074174;
      }
      break;
    case 0xdb6:
      if (query == 0xa01) {
        *v = (float)((double)CONCAT44(0x43300000,mapData[0x992]) - DOUBLE_00108d70);
        uVar9 = mapData[0x993];
        goto LAB_0007413c;
      }
      if (query < 0xa02) {
        if (query == 0xa00) {
          uVar10 = mapData[0x993];
          iVar11 = 0;
          loopIndex2 = 0;
          if (uVar10 == 0) {
            return;
          }
          uVar4 = mapData[0x992];
          do {
            loopIndex = 0;
            if (uVar4 != 0) {
              pfVar6 = v + iVar11;
              do {
                iVar11 = iVar11 + 4;
                iVar5 = loopIndex2 * uVar4 + loopIndex;
                loopIndex = loopIndex + 1;
                *pfVar6 = GH_U2F((unsigned int)(mapData[iVar5 * 4 + 0x99a]));
                pfVar6[1] = GH_U2F((unsigned int)(mapData[iVar5 * 4 + 0x99b]));
                pfVar6[2] = GH_U2F((unsigned int)(mapData[iVar5 * 4 + 0x99c]));
                pfVar6[3] = GH_U2F((unsigned int)(mapData[iVar5 * 4 + 0x99d]));
                uVar4 = mapData[0x992];
                pfVar6 = pfVar6 + 4;
              } while (loopIndex < uVar4);
              uVar10 = mapData[0x993];
            }
            loopIndex2 = loopIndex2 + 1;
          } while (loopIndex2 < uVar10);
          return;
        }
      }
      else if (query == 0xa02) {
        *v = GH_U2F((unsigned int)(mapData[0x994]));
        v[1] = GH_U2F((unsigned int)(mapData[0x995]));
        v[2] = GH_U2F((unsigned int)(mapData[0x996]));
        fVar1 = GH_U2F((unsigned int)(mapData[0x997]));
        goto LAB_00074174;
      }
      break;
    case 0xdb7:
      if (query == 0xa01) {
        *v = (float)((double)CONCAT44(0x43300000,mapData[0x11e]) - DOUBLE_00108d70);
        uVar9 = mapData[0x11f];
        goto LAB_0007413c;
      }
      if (query < 0xa02) {
        if (query == 0xa00) {
          uVar10 = mapData[0x11f];
          iVar11 = 0;
          loopIndex2 = 0;
          if (uVar10 == 0) {
            return;
          }
          uVar4 = mapData[0x11e];
          do {
            loopIndex = 0;
            if (uVar4 != 0) {
              pfVar6 = v + iVar11;
              do {
                iVar11 = iVar11 + 3;
                iVar5 = loopIndex2 * uVar4 + loopIndex;
                loopIndex = loopIndex + 1;
                *pfVar6 = GH_U2F((unsigned int)(mapData[iVar5 * 3 + 0x126]));
                pfVar6[1] = GH_U2F((unsigned int)(mapData[iVar5 * 3 + 0x127]));
                pfVar6[2] = GH_U2F((unsigned int)(mapData[iVar5 * 3 + 0x128]));
                uVar4 = mapData[0x11e];
                pfVar6 = pfVar6 + 3;
              } while (loopIndex < uVar4);
              uVar10 = mapData[0x11f];
            }
            loopIndex2 = loopIndex2 + 1;
          } while (loopIndex2 < uVar10);
          return;
        }
      }
      else if (query == 0xa02) {
        *v = GH_U2F((unsigned int)(mapData[0x120]));
        v[1] = GH_U2F((unsigned int)(mapData[0x121]));
        v[2] = GH_U2F((unsigned int)(mapData[0x122]));
        fVar1 = GH_U2F((unsigned int)(mapData[0x123]));
        goto LAB_00074174;
      }
      break;
    case 0xdb8:
      if (query == 0xa01) {
        *v = (float)((double)CONCAT44(0x43300000,mapData[0x252]) - DOUBLE_00108d70);
        uVar9 = mapData[0x253];
        goto LAB_0007413c;
      }
      if (query < 0xa02) {
        if (query == 0xa00) {
          uVar10 = mapData[0x253];
          iVar11 = 0;
          loopIndex2 = 0;
          if (uVar10 == 0) {
            return;
          }
          uVar4 = mapData[0x252];
          do {
            loopIndex = 0;
            if (uVar4 != 0) {
              pfVar6 = v + iVar11;
              do {
                iVar11 = iVar11 + 4;
                iVar5 = loopIndex2 * uVar4 + loopIndex;
                loopIndex = loopIndex + 1;
                *pfVar6 = GH_U2F((unsigned int)(mapData[iVar5 * 4 + 0x25a]));
                pfVar6[1] = GH_U2F((unsigned int)(mapData[iVar5 * 4 + 0x25b]));
                pfVar6[2] = GH_U2F((unsigned int)(mapData[iVar5 * 4 + 0x25c]));
                pfVar6[3] = GH_U2F((unsigned int)(mapData[iVar5 * 4 + 0x25d]));
                uVar4 = mapData[0x252];
                pfVar6 = pfVar6 + 4;
              } while (loopIndex < uVar4);
              uVar10 = mapData[0x253];
            }
            loopIndex2 = loopIndex2 + 1;
          } while (loopIndex2 < uVar10);
          return;
        }
      }
      else if (query == 0xa02) {
        *v = GH_U2F((unsigned int)(mapData[0x254]));
        v[1] = GH_U2F((unsigned int)(mapData[0x255]));
        v[2] = GH_U2F((unsigned int)(mapData[0x256]));
        fVar1 = GH_U2F((unsigned int)(mapData[599]));
        goto LAB_00074174;
      }
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
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glGetMapiv_Exec @ 0x741a4 (5112 bytes) */
void _glGetMapiv_Exec(glContext, target, query, v)
  int glContext;
  undefined4 target;
  uint query;
  uint *v;
{
  float fVar1;
  float fVar2;
  undefined4 glErrorCode;
  uint uVar4;
  int iVar5;
  uint *mapData;
  uint uVar7;
  uint loopIndex2;
  float *srcCursor;
  uint uVar9;
  uint *puVar10;
  uint *dstCursor;
  uint *srcCursor2;
  int iVar11;
  uint loopIndex;
  
  mapData = (uint *)_gleGetMapData(glContext);
  fVar2 = FLOAT_00108e90;
  if (*(short *)(glContext + 0x4a10) < 0) {
    switch(target) {
    case 0xd90:
      if (query == 0xa01) {
        uVar7 = mapData[0x70];
LAB_00074a1c:
        *v = uVar7;
        return;
      }
      if (query < 0xa02) {
        if (query == 0xa00) {
          loopIndex2 = 0;
          srcCursor2 = mapData;
          if (mapData[0x70] == 0) {
            return;
          }
          do {
            loopIndex2 = loopIndex2 + 1;
            *v = (int)(GH_U2F((unsigned int)(srcCursor2[0x74])) + fVar2);
            v[1] = (int)(GH_U2F((unsigned int)(srcCursor2[0x75])) + fVar2);
            v[2] = (int)(GH_U2F((unsigned int)(srcCursor2[0x76])) + fVar2);
            v[3] = (int)(GH_U2F((unsigned int)(srcCursor2[0x77])) + fVar2);
            v = v + 4;
            srcCursor2 = srcCursor2 + 4;
          } while (loopIndex2 < mapData[0x70]);
          return;
        }
      }
      else if (query == 0xa02) {
        *v = (int)(GH_U2F((unsigned int)(mapData[0x71])) + FLOAT_00108e90);
        fVar1 = GH_U2F((unsigned int)(mapData[0x72]));
LAB_00074a48:
        v[1] = (int)(fVar1 + fVar2);
        return;
      }
      break;
    case 0xd91:
      if (query == 0xa01) {
        uVar7 = mapData[0x9c];
        goto LAB_00074a1c;
      }
      if (query < 0xa02) {
        if (query == 0xa00) {
          loopIndex2 = 0;
          if (mapData[0x9c] == 0) {
            return;
          }
          srcCursor = (float *)(mapData + 0xa0);
          do {
            fVar1 = *srcCursor;
            loopIndex2 = loopIndex2 + 1;
            srcCursor = srcCursor + 1;
            *v = (int)(fVar1 + fVar2);
            v = v + 1;
          } while (loopIndex2 < mapData[0x9c]);
          return;
        }
      }
      else if (query == 0xa02) {
        *v = (int)(GH_U2F((unsigned int)(mapData[0x9d])) + FLOAT_00108e90);
        fVar1 = GH_U2F((unsigned int)(mapData[0x9e]));
        goto LAB_00074a48;
      }
      break;
    case 0xd92:
      if (query == 0xa01) {
        uVar7 = mapData[0x4e];
        goto LAB_00074a1c;
      }
      if (query < 0xa02) {
        if (query == 0xa00) {
          loopIndex2 = 0;
          srcCursor2 = mapData;
          if (mapData[0x4e] == 0) {
            return;
          }
          do {
            loopIndex2 = loopIndex2 + 1;
            *v = (int)(GH_U2F((unsigned int)(srcCursor2[0x52])) + fVar2);
            v[1] = (int)(GH_U2F((unsigned int)(srcCursor2[0x53])) + fVar2);
            v[2] = (int)(GH_U2F((unsigned int)(srcCursor2[0x54])) + fVar2);
            v = v + 3;
            srcCursor2 = srcCursor2 + 3;
          } while (loopIndex2 < mapData[0x4e]);
          return;
        }
      }
      else if (query == 0xa02) {
        *v = (int)(GH_U2F((unsigned int)(mapData[0x4f])) + FLOAT_00108e90);
        fVar1 = GH_U2F((unsigned int)(mapData[0x50]));
        goto LAB_00074a48;
      }
      break;
    case 0xd93:
      if (query == 0xa01) {
        uVar7 = mapData[0xaa];
        goto LAB_00074a1c;
      }
      if (query < 0xa02) {
        if (query == 0xa00) {
          loopIndex2 = 0;
          if (mapData[0xaa] == 0) {
            return;
          }
          srcCursor = (float *)(mapData + 0xae);
          do {
            fVar1 = *srcCursor;
            loopIndex2 = loopIndex2 + 1;
            srcCursor = srcCursor + 1;
            *v = (int)(fVar1 + fVar2);
            v = v + 1;
          } while (loopIndex2 < mapData[0xaa]);
          return;
        }
      }
      else if (query == 0xa02) {
        *v = (int)(GH_U2F((unsigned int)(mapData[0xab])) + FLOAT_00108e90);
        fVar1 = GH_U2F((unsigned int)(mapData[0xac]));
        goto LAB_00074a48;
      }
      break;
    case 0xd94:
      if (query == 0xa01) {
        uVar7 = mapData[0xb8];
        goto LAB_00074a1c;
      }
      if (query < 0xa02) {
        if (query == 0xa00) {
          loopIndex2 = 0;
          srcCursor2 = mapData;
          if (mapData[0xb8] == 0) {
            return;
          }
          do {
            loopIndex2 = loopIndex2 + 1;
            *v = (int)(GH_U2F((unsigned int)(srcCursor2[0xbc])) + fVar2);
            v[1] = (int)(GH_U2F((unsigned int)(srcCursor2[0xbd])) + fVar2);
            v = v + 2;
            srcCursor2 = srcCursor2 + 2;
          } while (loopIndex2 < mapData[0xb8]);
          return;
        }
      }
      else if (query == 0xa02) {
        *v = (int)(GH_U2F((unsigned int)(mapData[0xb9])) + FLOAT_00108e90);
        fVar1 = GH_U2F((unsigned int)(mapData[0xba]));
        goto LAB_00074a48;
      }
      break;
    case 0xd95:
      if (query == 0xa01) {
        uVar7 = mapData[0xd0];
        goto LAB_00074a1c;
      }
      if (query < 0xa02) {
        if (query == 0xa00) {
          loopIndex2 = 0;
          srcCursor2 = mapData;
          if (mapData[0xd0] == 0) {
            return;
          }
          do {
            loopIndex2 = loopIndex2 + 1;
            *v = (int)(GH_U2F((unsigned int)(srcCursor2[0xd4])) + fVar2);
            v[1] = (int)(GH_U2F((unsigned int)(srcCursor2[0xd5])) + fVar2);
            v[2] = (int)(GH_U2F((unsigned int)(srcCursor2[0xd6])) + fVar2);
            v = v + 3;
            srcCursor2 = srcCursor2 + 3;
          } while (loopIndex2 < mapData[0xd0]);
          return;
        }
      }
      else if (query == 0xa02) {
        *v = (int)(GH_U2F((unsigned int)(mapData[0xd1])) + FLOAT_00108e90);
        fVar1 = GH_U2F((unsigned int)(mapData[0xd2]));
        goto LAB_00074a48;
      }
      break;
    case 0xd96:
      if (query == 0xa01) {
        uVar7 = mapData[0xf2];
        goto LAB_00074a1c;
      }
      if (query < 0xa02) {
        if (query == 0xa00) {
          loopIndex2 = 0;
          srcCursor2 = mapData;
          if (mapData[0xf2] == 0) {
            return;
          }
          do {
            loopIndex2 = loopIndex2 + 1;
            *v = (int)(GH_U2F((unsigned int)(srcCursor2[0xf6])) + fVar2);
            v[1] = (int)(GH_U2F((unsigned int)(srcCursor2[0xf7])) + fVar2);
            v[2] = (int)(GH_U2F((unsigned int)(srcCursor2[0xf8])) + fVar2);
            v[3] = (int)(GH_U2F((unsigned int)(srcCursor2[0xf9])) + fVar2);
            v = v + 4;
            srcCursor2 = srcCursor2 + 4;
          } while (loopIndex2 < mapData[0xf2]);
          return;
        }
      }
      else if (query == 0xa02) {
        *v = (int)(GH_U2F((unsigned int)(mapData[0xf3])) + FLOAT_00108e90);
        fVar1 = GH_U2F((unsigned int)(mapData[0xf4]));
        goto LAB_00074a48;
      }
      break;
    case 0xd97:
      if (query == 0xa01) {
        uVar7 = *mapData;
        goto LAB_00074a1c;
      }
      if (query < 0xa02) {
        if (query == 0xa00) {
          loopIndex2 = 0;
          srcCursor2 = mapData;
          if (*mapData == 0) {
            return;
          }
          do {
            loopIndex2 = loopIndex2 + 1;
            *v = (int)(GH_U2F((unsigned int)(srcCursor2[4])) + fVar2);
            v[1] = (int)(GH_U2F((unsigned int)(srcCursor2[5])) + fVar2);
            v[2] = (int)(GH_U2F((unsigned int)(srcCursor2[6])) + fVar2);
            v = v + 3;
            srcCursor2 = srcCursor2 + 3;
          } while (loopIndex2 < *mapData);
          return;
        }
      }
      else if (query == 0xa02) {
        *v = (int)(GH_U2F((unsigned int)(mapData[1])) + FLOAT_00108e90);
        fVar1 = GH_U2F((unsigned int)(mapData[2]));
        goto LAB_00074a48;
      }
      break;
    case 0xd98:
      if (query == 0xa01) {
        uVar7 = mapData[0x22];
        goto LAB_00074a1c;
      }
      if (query < 0xa02) {
        if (query == 0xa00) {
          loopIndex2 = 0;
          srcCursor2 = mapData;
          if (mapData[0x22] == 0) {
            return;
          }
          do {
            loopIndex2 = loopIndex2 + 1;
            *v = (int)(GH_U2F((unsigned int)(srcCursor2[0x26])) + fVar2);
            v[1] = (int)(GH_U2F((unsigned int)(srcCursor2[0x27])) + fVar2);
            v[2] = (int)(GH_U2F((unsigned int)(srcCursor2[0x28])) + fVar2);
            v[3] = (int)(GH_U2F((unsigned int)(srcCursor2[0x29])) + fVar2);
            v = v + 4;
            srcCursor2 = srcCursor2 + 4;
          } while (loopIndex2 < mapData[0x22]);
          return;
        }
      }
      else if (query == 0xa02) {
        *v = (int)(GH_U2F((unsigned int)(mapData[0x23])) + FLOAT_00108e90);
        fVar1 = GH_U2F((unsigned int)(mapData[0x24]));
        goto LAB_00074a48;
      }
      break;
    case 0xdb0:
      if (query == 0xa01) {
        *v = mapData[0x51e];
        uVar7 = mapData[0x51f];
LAB_000755a4:
        v[1] = uVar7;
        return;
      }
      if (query < 0xa02) {
        if (query == 0xa00) {
          uVar9 = mapData[0x51f];
          iVar11 = 0;
          loopIndex2 = 0;
          if (uVar9 == 0) {
            return;
          }
          uVar4 = mapData[0x51e];
          do {
            fVar2 = FLOAT_00108e90;
            loopIndex = 0;
            if (uVar4 != 0) {
              puVar10 = v + iVar11;
              do {
                iVar11 = iVar11 + 4;
                iVar5 = loopIndex2 * uVar4 + loopIndex;
                loopIndex = loopIndex + 1;
                *puVar10 = (int)(GH_U2F((unsigned int)(mapData[iVar5 * 4 + 0x526])) + fVar2);
                puVar10[1] = (int)(GH_U2F((unsigned int)(mapData[iVar5 * 4 + 0x527])) + fVar2);
                puVar10[2] = (int)(GH_U2F((unsigned int)(mapData[iVar5 * 4 + 0x528])) + fVar2);
                puVar10[3] = (int)(GH_U2F((unsigned int)(mapData[iVar5 * 4 + 0x529])) + fVar2);
                uVar4 = mapData[0x51e];
                puVar10 = puVar10 + 4;
              } while (loopIndex < uVar4);
              uVar9 = mapData[0x51f];
            }
            loopIndex2 = loopIndex2 + 1;
          } while (loopIndex2 < uVar9);
          return;
        }
      }
      else if (query == 0xa02) {
        *v = (int)(GH_U2F((unsigned int)(mapData[0x520])) + FLOAT_00108e90);
        v[1] = (int)(GH_U2F((unsigned int)(mapData[0x521])) + fVar2);
        v[2] = (int)(GH_U2F((unsigned int)(mapData[0x522])) + fVar2);
        fVar1 = GH_U2F((unsigned int)(mapData[0x523]));
LAB_00075600:
        v[3] = (int)(fVar1 + fVar2);
        return;
      }
      break;
    case 0xdb1:
      if (query == 0xa01) {
        *v = mapData[0x6b6];
        uVar7 = mapData[0x6b7];
        goto LAB_000755a4;
      }
      if (query < 0xa02) {
        if (query == 0xa00) {
          uVar9 = mapData[0x6b7];
          iVar11 = 0;
          loopIndex2 = 0;
          if (uVar9 == 0) {
            return;
          }
          uVar4 = mapData[0x6b6];
          do {
            fVar2 = FLOAT_00108e90;
            loopIndex = 0;
            if (uVar4 != 0) {
              dstCursor = v + iVar11;
              do {
                iVar11 = iVar11 + 1;
                iVar5 = loopIndex2 * uVar4 + loopIndex;
                loopIndex = loopIndex + 1;
                *dstCursor = (int)(GH_U2F((unsigned int)(mapData[iVar5 + 0x6be])) + fVar2);
                dstCursor = dstCursor + 1;
                uVar4 = mapData[0x6b6];
              } while (loopIndex < uVar4);
              uVar9 = mapData[0x6b7];
            }
            loopIndex2 = loopIndex2 + 1;
          } while (loopIndex2 < uVar9);
          return;
        }
      }
      else if (query == 0xa02) {
        *v = (int)(GH_U2F((unsigned int)(mapData[0x6b8])) + FLOAT_00108e90);
        v[1] = (int)(GH_U2F((unsigned int)(mapData[0x6b9])) + fVar2);
        v[2] = (int)(GH_U2F((unsigned int)(mapData[0x6ba])) + fVar2);
        fVar1 = GH_U2F((unsigned int)(mapData[0x6bb]));
        goto LAB_00075600;
      }
      break;
    case 0xdb2:
      if (query == 0xa01) {
        *v = mapData[0x3ea];
        uVar7 = mapData[0x3eb];
        goto LAB_000755a4;
      }
      if (query < 0xa02) {
        if (query == 0xa00) {
          uVar9 = mapData[0x3eb];
          iVar11 = 0;
          loopIndex2 = 0;
          if (uVar9 == 0) {
            return;
          }
          uVar4 = mapData[0x3ea];
          do {
            fVar2 = FLOAT_00108e90;
            loopIndex = 0;
            if (uVar4 != 0) {
              puVar10 = v + iVar11;
              do {
                iVar11 = iVar11 + 3;
                iVar5 = loopIndex2 * uVar4 + loopIndex;
                loopIndex = loopIndex + 1;
                *puVar10 = (int)(GH_U2F((unsigned int)(mapData[iVar5 * 3 + 0x3f2])) + fVar2);
                puVar10[1] = (int)(GH_U2F((unsigned int)(mapData[iVar5 * 3 + 0x3f3])) + fVar2);
                puVar10[2] = (int)(GH_U2F((unsigned int)(mapData[iVar5 * 3 + 0x3f4])) + fVar2);
                uVar4 = mapData[0x3ea];
                puVar10 = puVar10 + 3;
              } while (loopIndex < uVar4);
              uVar9 = mapData[0x3eb];
            }
            loopIndex2 = loopIndex2 + 1;
          } while (loopIndex2 < uVar9);
          return;
        }
      }
      else if (query == 0xa02) {
        *v = (int)(GH_U2F((unsigned int)(mapData[0x3ec])) + FLOAT_00108e90);
        v[1] = (int)(GH_U2F((unsigned int)(mapData[0x3ed])) + fVar2);
        v[2] = (int)(GH_U2F((unsigned int)(mapData[0x3ee])) + fVar2);
        fVar1 = GH_U2F((unsigned int)(mapData[0x3ef]));
        goto LAB_00075600;
      }
      break;
    case 0xdb3:
      if (query == 0xa01) {
        *v = mapData[0x722];
        uVar7 = mapData[0x723];
        goto LAB_000755a4;
      }
      if (query < 0xa02) {
        if (query == 0xa00) {
          uVar9 = mapData[0x723];
          iVar11 = 0;
          loopIndex2 = 0;
          if (uVar9 == 0) {
            return;
          }
          uVar4 = mapData[0x722];
          do {
            fVar2 = FLOAT_00108e90;
            loopIndex = 0;
            if (uVar4 != 0) {
              dstCursor = v + iVar11;
              do {
                iVar11 = iVar11 + 1;
                iVar5 = loopIndex2 * uVar4 + loopIndex;
                loopIndex = loopIndex + 1;
                *dstCursor = (int)(GH_U2F((unsigned int)(mapData[iVar5 + 0x72a])) + fVar2);
                dstCursor = dstCursor + 1;
                uVar4 = mapData[0x722];
              } while (loopIndex < uVar4);
              uVar9 = mapData[0x723];
            }
            loopIndex2 = loopIndex2 + 1;
          } while (loopIndex2 < uVar9);
          return;
        }
      }
      else if (query == 0xa02) {
        *v = (int)(GH_U2F((unsigned int)(mapData[0x724])) + FLOAT_00108e90);
        v[1] = (int)(GH_U2F((unsigned int)(mapData[0x725])) + fVar2);
        v[2] = (int)(GH_U2F((unsigned int)(mapData[0x726])) + fVar2);
        fVar1 = GH_U2F((unsigned int)(mapData[0x727]));
        goto LAB_00075600;
      }
      break;
    case 0xdb4:
      if (query == 0xa01) {
        *v = mapData[0x78e];
        uVar7 = mapData[0x78f];
        goto LAB_000755a4;
      }
      if (query < 0xa02) {
        if (query == 0xa00) {
          uVar9 = mapData[0x78f];
          iVar11 = 0;
          loopIndex2 = 0;
          if (uVar9 == 0) {
            return;
          }
          uVar4 = mapData[0x78e];
          do {
            fVar2 = FLOAT_00108e90;
            loopIndex = 0;
            if (uVar4 != 0) {
              puVar10 = v + iVar11;
              do {
                iVar11 = iVar11 + 2;
                iVar5 = loopIndex2 * uVar4 + loopIndex;
                loopIndex = loopIndex + 1;
                *puVar10 = (int)(GH_U2F((unsigned int)(mapData[iVar5 * 2 + 0x796])) + fVar2);
                puVar10[1] = (int)(GH_U2F((unsigned int)(mapData[iVar5 * 2 + 0x797])) + fVar2);
                uVar4 = mapData[0x78e];
                puVar10 = puVar10 + 2;
              } while (loopIndex < uVar4);
              uVar9 = mapData[0x78f];
            }
            loopIndex2 = loopIndex2 + 1;
          } while (loopIndex2 < uVar9);
          return;
        }
      }
      else if (query == 0xa02) {
        *v = (int)(GH_U2F((unsigned int)(mapData[0x790])) + FLOAT_00108e90);
        v[1] = (int)(GH_U2F((unsigned int)(mapData[0x791])) + fVar2);
        v[2] = (int)(GH_U2F((unsigned int)(mapData[0x792])) + fVar2);
        fVar1 = GH_U2F((unsigned int)(mapData[0x793]));
        goto LAB_00075600;
      }
      break;
    case 0xdb5:
      if (query == 0xa01) {
        *v = mapData[0x85e];
        uVar7 = mapData[0x85f];
        goto LAB_000755a4;
      }
      if (query < 0xa02) {
        if (query == 0xa00) {
          uVar9 = mapData[0x85f];
          iVar11 = 0;
          loopIndex2 = 0;
          if (uVar9 == 0) {
            return;
          }
          uVar4 = mapData[0x85e];
          do {
            fVar2 = FLOAT_00108e90;
            loopIndex = 0;
            if (uVar4 != 0) {
              puVar10 = v + iVar11;
              do {
                iVar11 = iVar11 + 3;
                iVar5 = loopIndex2 * uVar4 + loopIndex;
                loopIndex = loopIndex + 1;
                *puVar10 = (int)(GH_U2F((unsigned int)(mapData[iVar5 * 3 + 0x866])) + fVar2);
                puVar10[1] = (int)(GH_U2F((unsigned int)(mapData[iVar5 * 3 + 0x867])) + fVar2);
                puVar10[2] = (int)(GH_U2F((unsigned int)(mapData[iVar5 * 3 + 0x868])) + fVar2);
                uVar4 = mapData[0x85e];
                puVar10 = puVar10 + 3;
              } while (loopIndex < uVar4);
              uVar9 = mapData[0x85f];
            }
            loopIndex2 = loopIndex2 + 1;
          } while (loopIndex2 < uVar9);
          return;
        }
      }
      else if (query == 0xa02) {
        *v = (int)(GH_U2F((unsigned int)(mapData[0x860])) + FLOAT_00108e90);
        v[1] = (int)(GH_U2F((unsigned int)(mapData[0x861])) + fVar2);
        v[2] = (int)(GH_U2F((unsigned int)(mapData[0x862])) + fVar2);
        fVar1 = GH_U2F((unsigned int)(mapData[0x863]));
        goto LAB_00075600;
      }
      break;
    case 0xdb6:
      if (query == 0xa01) {
        *v = mapData[0x992];
        uVar7 = mapData[0x993];
        goto LAB_000755a4;
      }
      if (query < 0xa02) {
        if (query == 0xa00) {
          uVar9 = mapData[0x993];
          iVar11 = 0;
          loopIndex2 = 0;
          if (uVar9 == 0) {
            return;
          }
          uVar4 = mapData[0x992];
          do {
            fVar2 = FLOAT_00108e90;
            loopIndex = 0;
            if (uVar4 != 0) {
              puVar10 = v + iVar11;
              do {
                iVar11 = iVar11 + 4;
                iVar5 = loopIndex2 * uVar4 + loopIndex;
                loopIndex = loopIndex + 1;
                *puVar10 = (int)(GH_U2F((unsigned int)(mapData[iVar5 * 4 + 0x99a])) + fVar2);
                puVar10[1] = (int)(GH_U2F((unsigned int)(mapData[iVar5 * 4 + 0x99b])) + fVar2);
                puVar10[2] = (int)(GH_U2F((unsigned int)(mapData[iVar5 * 4 + 0x99c])) + fVar2);
                puVar10[3] = (int)(GH_U2F((unsigned int)(mapData[iVar5 * 4 + 0x99d])) + fVar2);
                uVar4 = mapData[0x992];
                puVar10 = puVar10 + 4;
              } while (loopIndex < uVar4);
              uVar9 = mapData[0x993];
            }
            loopIndex2 = loopIndex2 + 1;
          } while (loopIndex2 < uVar9);
          return;
        }
      }
      else if (query == 0xa02) {
        *v = (int)(GH_U2F((unsigned int)(mapData[0x994])) + FLOAT_00108e90);
        v[1] = (int)(GH_U2F((unsigned int)(mapData[0x995])) + fVar2);
        v[2] = (int)(GH_U2F((unsigned int)(mapData[0x996])) + fVar2);
        fVar1 = GH_U2F((unsigned int)(mapData[0x997]));
        goto LAB_00075600;
      }
      break;
    case 0xdb7:
      if (query == 0xa01) {
        *v = mapData[0x11e];
        uVar7 = mapData[0x11f];
        goto LAB_000755a4;
      }
      if (query < 0xa02) {
        if (query == 0xa00) {
          uVar9 = mapData[0x11f];
          iVar11 = 0;
          loopIndex2 = 0;
          if (uVar9 == 0) {
            return;
          }
          uVar4 = mapData[0x11e];
          do {
            fVar2 = FLOAT_00108e90;
            loopIndex = 0;
            if (uVar4 != 0) {
              puVar10 = v + iVar11;
              do {
                iVar11 = iVar11 + 3;
                iVar5 = loopIndex2 * uVar4 + loopIndex;
                loopIndex = loopIndex + 1;
                *puVar10 = (int)(GH_U2F((unsigned int)(mapData[iVar5 * 3 + 0x126])) + fVar2);
                puVar10[1] = (int)(GH_U2F((unsigned int)(mapData[iVar5 * 3 + 0x127])) + fVar2);
                puVar10[2] = (int)(GH_U2F((unsigned int)(mapData[iVar5 * 3 + 0x128])) + fVar2);
                uVar4 = mapData[0x11e];
                puVar10 = puVar10 + 3;
              } while (loopIndex < uVar4);
              uVar9 = mapData[0x11f];
            }
            loopIndex2 = loopIndex2 + 1;
          } while (loopIndex2 < uVar9);
          return;
        }
      }
      else if (query == 0xa02) {
        *v = (int)(GH_U2F((unsigned int)(mapData[0x120])) + FLOAT_00108e90);
        v[1] = (int)(GH_U2F((unsigned int)(mapData[0x121])) + fVar2);
        v[2] = (int)(GH_U2F((unsigned int)(mapData[0x122])) + fVar2);
        fVar1 = GH_U2F((unsigned int)(mapData[0x123]));
        goto LAB_00075600;
      }
      break;
    case 0xdb8:
      if (query == 0xa01) {
        *v = mapData[0x252];
        uVar7 = mapData[0x253];
        goto LAB_000755a4;
      }
      if (query < 0xa02) {
        if (query == 0xa00) {
          uVar9 = mapData[0x253];
          iVar11 = 0;
          loopIndex2 = 0;
          if (uVar9 == 0) {
            return;
          }
          uVar4 = mapData[0x252];
          do {
            fVar2 = FLOAT_00108e90;
            loopIndex = 0;
            if (uVar4 != 0) {
              puVar10 = v + iVar11;
              do {
                iVar11 = iVar11 + 4;
                iVar5 = loopIndex2 * uVar4 + loopIndex;
                loopIndex = loopIndex + 1;
                *puVar10 = (int)(GH_U2F((unsigned int)(mapData[iVar5 * 4 + 0x25a])) + fVar2);
                puVar10[1] = (int)(GH_U2F((unsigned int)(mapData[iVar5 * 4 + 0x25b])) + fVar2);
                puVar10[2] = (int)(GH_U2F((unsigned int)(mapData[iVar5 * 4 + 0x25c])) + fVar2);
                puVar10[3] = (int)(GH_U2F((unsigned int)(mapData[iVar5 * 4 + 0x25d])) + fVar2);
                uVar4 = mapData[0x252];
                puVar10 = puVar10 + 4;
              } while (loopIndex < uVar4);
              uVar9 = mapData[0x253];
            }
            loopIndex2 = loopIndex2 + 1;
          } while (loopIndex2 < uVar9);
          return;
        }
      }
      else if (query == 0xa02) {
        *v = (int)(GH_U2F((unsigned int)(mapData[0x254])) + FLOAT_00108e90);
        v[1] = (int)(GH_U2F((unsigned int)(mapData[0x255])) + fVar2);
        v[2] = (int)(GH_U2F((unsigned int)(mapData[0x256])) + fVar2);
        fVar1 = GH_U2F((unsigned int)(mapData[599]));
        goto LAB_00075600;
      }
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
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glMapGrid1_ListExec @ 0x75640 (48 bytes) */
undefined4 _glMapGrid1_ListExec(undefined4 glContext,undefined4 *listRecord,double unusedFloatArg1,double unusedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12)
{
  double in_stack_ffffffb8;
  double in_stack_ffffffc0;
  double in_stack_ffffffc8;
  double in_stack_ffffffd0;
  
  ((void (*)())_glMapGrid1d_Exec)(glContext,*listRecord,(double)GH_U2F((unsigned int)(listRecord[1])),(double)GH_U2F((unsigned int)(listRecord[2])),forwardedFloatArg3,
                    forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8,in_stack_ffffffb8,in_stack_ffffffc0
                    ,in_stack_ffffffc8,in_stack_ffffffd0);
  return 0x10;
}

/* _glMapGrid1f_Comp @ 0x75670 (224 bytes) */
int _glMapGrid1f_Comp(int glContext,uint un,float u1,float u2)
{
  undefined4 glErrorCode;
  uint *listRecord;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (0 < (int)un) {
      listRecord = (uint *)_gleAddListItem(glContext,PTR__glMapGrid1_ListExec_001101c8,0x10);
      if (listRecord == (uint *)0x0) {
        return 0;
      }
      *listRecord = un;
      listRecord[1] = (uint)GH_F2U((float)u1);
      listRecord[2] = (uint)GH_F2U((float)u2);
      listRecord[3] = (uint)GH_F2U((float)((u2 - u1) /
                        (float)((double)CONCAT44(0x43300000,un ^ 0x80000000) - DOUBLE_00108d58)
                        ));
      return (int)listRecord;
    }
    if (*(int *)(glContext + 0x7574) != 0) {
      return glContext;
    }
    glErrorCode = 0x501;
  }
  else {
    if (*(int *)(glContext + 0x7574) != 0) {
      return glContext;
    }
    glErrorCode = 0x502;
  }
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return glContext;
}

/* _glMapGrid1f_Exec @ 0x75750 (144 bytes) */
void _glMapGrid1f_Exec(int glContext,uint un,float u1,float u2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12)
{
  double dVar1;
  undefined4 glErrorCode;
  
  dVar1 = DOUBLE_00108d58;
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (0 < (int)un) {
      *(uint *)(0x74a4 + glContext + 4) = un;
      *(float *)(glContext + 0x74ac) = (float)u1;
      *(float *)(glContext + 0x74b0) = (float)u2;
      *(float *)(glContext + 0x74b4) =
           (u2 - u1) /
           (float)((double)CONCAT44(0x43300000,un ^ 0x80000000) - dVar1);
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

/* _glMapGrid1f_CompExec @ 0x757e0 (88 bytes) */
void _glMapGrid1f_CompExec(undefined4 glContext,undefined4 un,float u1,float u2)
{
  undefined4 in_LR;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  
  ((int (*)())_glMapGrid1f_Comp)(glContext,un,u1,u2);
  ((void (*)())_glMapGrid1f_Exec)(glContext,un,u1,u2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8,
                    (double)CONCAT44(in_LR,(*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0xc))),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),
                    (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)));
  return;
}

/* _glMapGrid1d_Comp @ 0x75838 (232 bytes) */
int _glMapGrid1d_Comp(int glContext,uint un,double u1,double u2)
{
  undefined4 glErrorCode;
  uint *listRecord;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (0 < (int)un) {
      listRecord = (uint *)_gleAddListItem(glContext,PTR__glMapGrid1_ListExec_001101c8,0x10);
      if (listRecord == (uint *)0x0) {
        return 0;
      }
      *listRecord = un;
      listRecord[1] = (uint)GH_F2U((float)u1);
      listRecord[2] = (uint)GH_F2U((float)u2);
      listRecord[3] = (uint)GH_F2U((float)((u2 - u1) /
                               ((double)CONCAT44(0x43300000,un ^ 0x80000000) - DOUBLE_00108d58)
                               ));
      return (int)listRecord;
    }
    if (*(int *)(glContext + 0x7574) != 0) {
      return glContext;
    }
    glErrorCode = 0x501;
  }
  else {
    if (*(int *)(glContext + 0x7574) != 0) {
      return glContext;
    }
    glErrorCode = 0x502;
  }
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return glContext;
}

/* _glMapGrid1d_Exec @ 0x75920 (152 bytes) */
void _glMapGrid1d_Exec(int glContext,uint un,double u1,double u2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12)
{
  double dVar1;
  undefined4 glErrorCode;
  
  dVar1 = DOUBLE_00108d58;
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (0 < (int)un) {
      *(uint *)(0x74a4 + glContext + 4) = un;
      *(float *)(glContext + 0x74ac) = (float)u1;
      *(float *)(glContext + 0x74b0) = (float)u2;
      *(float *)(glContext + 0x74b4) =
           (float)((u2 - u1) /
                  ((double)CONCAT44(0x43300000,un ^ 0x80000000) - dVar1));
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

/* _glMapGrid1d_CompExec @ 0x759b8 (88 bytes) */
void _glMapGrid1d_CompExec(undefined4 glContext,undefined4 un,double u1,double u2)
{
  undefined4 in_LR;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  
  ((int (*)())_glMapGrid1d_Comp)(glContext,un,u1,u2);
  ((void (*)())_glMapGrid1d_Exec)(glContext,un,u1,u2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8,
                    (double)CONCAT44(in_LR,(*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0xc))),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),
                    (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)));
  return;
}

/* _glMapGrid2_ListExec @ 0x75a10 (60 bytes) */
undefined4 _glMapGrid2_ListExec(undefined4 glContext,undefined4 *listRecord,double unusedFloatArg1,double unusedFloatArg2,double unusedFloatArg3,double unusedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  undefined4 in_r5;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  double in_stack_ffffffa8;
  double in_stack_ffffffb0;
  double in_stack_ffffffb8;
  double in_stack_ffffffc0;
  double in_stack_ffffffc8;
  
  ((void (*)())_glMapGrid2d_Exec)(glContext,*listRecord,in_r5,in_r6,in_r7,in_r8,listRecord[4],(double)GH_U2F((unsigned int)(listRecord[1])),
                    (double)GH_U2F((unsigned int)(listRecord[2])),(double)GH_U2F((unsigned int)(listRecord[5])),(double)GH_U2F((unsigned int)(listRecord[6])),
                    forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8,in_stack_ffffffa8,in_stack_ffffffb0,
                    in_stack_ffffffb8,in_stack_ffffffc0,in_stack_ffffffc8);
  return 0x20;
}

/* _glMapGrid2f_Comp @ 0x75a4c (268 bytes) */
void _glMapGrid2f_Comp(int glContext,uint un,undefined4 u1Shadow,undefined4 u2Shadow,uint vn,float u1,float u2,float v1,float v2)
{
  double dVar1;
  undefined4 glErrorCode;
  uint *listRecord;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    if ((0 < (int)un) && (0 < (int)vn)) {
      listRecord = (uint *)_gleAddListItem(glContext,PTR__glMapGrid2_ListExec_001101cc,0x20);
      if (listRecord != (uint *)0x0) {
        *listRecord = un;
        listRecord[1] = (uint)GH_F2U((float)u1);
        listRecord[2] = (uint)GH_F2U((float)u2);
        dVar1 = DOUBLE_00108d58;
        listRecord[4] = vn;
        listRecord[5] = (uint)GH_F2U((float)v1);
        listRecord[6] = (uint)GH_F2U((float)v2);
        listRecord[3] = (uint)GH_F2U((float)((u2 - u1) /
                          (float)((double)CONCAT44(0x43300000,un ^ 0x80000000) - dVar1)));
        listRecord[7] = (uint)GH_F2U((float)((v2 - v1) /
                          (float)((double)CONCAT44(0x43300000,vn ^ 0x80000000) - dVar1)));
      }
      goto LAB_00075b4c;
    }
    if (*(int *)(glContext + 0x7574) != 0) goto LAB_00075b4c;
    glErrorCode = 0x501;
  }
  else {
    if (*(int *)(glContext + 0x7574) != 0) goto LAB_00075b4c;
    glErrorCode = 0x502;
  }
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
LAB_00075b4c:
  return;
}

/* _glMapGrid2f_Exec @ 0x75b58 (196 bytes) */
void _glMapGrid2f_Exec(int glContext,uint un,undefined4 u1Shadow,undefined4 u2Shadow,uint vn,float u1,float u2,float v1,float v2,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11)
{
  double dVar1;
  undefined4 glErrorCode;
  double dVar3;
  
  dVar1 = DOUBLE_00108d58;
  if (*(short *)(glContext + 0x4a10) < 0) {
    if ((0 < (int)un) && (0 < (int)vn)) {
      dVar3 = (double)CONCAT44(0x43300000,un ^ 0x80000000) - DOUBLE_00108d58;
      *(uint *)(glContext + 0x74b8) = un;
      *(float *)(glContext + 0x74bc) = (float)u1;
      *(float *)(glContext + 0x74c0) = (float)u2;
      *(uint *)(glContext + 0x74c8) = vn;
      *(float *)(glContext + 0x74cc) = (float)v1;
      *(float *)(glContext + 0x74d0) = (float)v2;
      *(float *)(glContext + 0x74c4) = (u2 - u1) / (float)dVar3;
      *(float *)(glContext + 0x74d4) =
           (v2 - v1) /
           (float)((double)CONCAT44(0x43300000,vn ^ 0x80000000) - dVar1);
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

/* _glMapGrid2f_CompExec @ 0x75c1c (112 bytes) */
void _glMapGrid2f_CompExec(undefined4 glContext,undefined4 un,undefined4 u1Shadow,undefined4 u2Shadow,undefined4 vn,float u1,float u2,float v1,float v2)
{
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  
  ((void (*)())_glMapGrid2f_Comp)(glContext,un,u1Shadow,u2Shadow,vn,u1,u2,v1,v2);
  ((void (*)())_glMapGrid2f_Exec)(glContext,un,u1Shadow,u2Shadow,vn,u1,u2,v1,v2,
                    in_f5,in_f6,in_f7,in_f8,(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x8)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)));
  return;
}

/* _glMapGrid2d_Comp @ 0x75c8c (284 bytes) */
void _glMapGrid2d_Comp(int glContext,uint un,undefined4 u1ShadowHi,undefined4 u1ShadowLo,undefined4 u2ShadowHi,undefined4 u2ShadowLo,uint vn,double u1,double u2,double v1,double v2)
{
  double dVar1;
  undefined4 glErrorCode;
  uint *listRecord;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    if ((0 < (int)un) && (0 < (int)vn)) {
      listRecord = (uint *)_gleAddListItem(glContext,PTR__glMapGrid2_ListExec_001101cc,0x20);
      if (listRecord != (uint *)0x0) {
        *listRecord = un;
        listRecord[1] = (uint)GH_F2U((float)u1);
        listRecord[2] = (uint)GH_F2U((float)u2);
        dVar1 = DOUBLE_00108d58;
        listRecord[5] = (uint)GH_F2U((float)v1);
        listRecord[6] = (uint)GH_F2U((float)v2);
        listRecord[4] = vn;
        listRecord[3] = (uint)GH_F2U((float)((u2 - u1) /
                                 ((double)CONCAT44(0x43300000,un ^ 0x80000000) - dVar1)));
        listRecord[7] = (uint)GH_F2U((float)((v2 - v1) /
                                 ((double)CONCAT44(0x43300000,vn ^ 0x80000000) - dVar1)));
      }
      goto LAB_00075d9c;
    }
    if (*(int *)(glContext + 0x7574) != 0) goto LAB_00075d9c;
    glErrorCode = 0x501;
  }
  else {
    if (*(int *)(glContext + 0x7574) != 0) goto LAB_00075d9c;
    glErrorCode = 0x502;
  }
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
LAB_00075d9c:
  return;
}

/* _glMapGrid2d_Exec @ 0x75da8 (212 bytes) */
void _glMapGrid2d_Exec(int glContext,uint un,undefined4 u1ShadowHi,undefined4 u1ShadowLo,undefined4 u2ShadowHi,undefined4 u2ShadowLo,uint vn,double u1,double u2,double v1,double v2,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  double dVar1;
  undefined4 glErrorCode;
  double dVar3;
  
  dVar1 = DOUBLE_00108d58;
  if (*(short *)(glContext + 0x4a10) < 0) {
    if ((0 < (int)un) && (0 < (int)vn)) {
      dVar3 = (double)CONCAT44(0x43300000,un ^ 0x80000000) - DOUBLE_00108d58;
      *(uint *)(glContext + 0x74b8) = un;
      *(float *)(glContext + 0x74bc) = (float)u1;
      *(uint *)(glContext + 0x74c8) = vn;
      *(float *)(glContext + 0x74cc) = (float)v1;
      *(float *)(glContext + 0x74c4) = (float)((u2 - u1) / dVar3);
      *(float *)(glContext + 0x74d4) =
           (float)((v2 - v1) /
                  ((double)CONCAT44(0x43300000,vn ^ 0x80000000) - dVar1));
      *(float *)(glContext + 0x74c0) = (float)u2;
      *(float *)(glContext + 0x74d0) = (float)v2;
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

/* _glMapGrid2d_CompExec @ 0x75e7c (112 bytes) */
void _glMapGrid2d_CompExec(undefined4 glContext,undefined4 un,undefined4 u1ShadowHi,undefined4 u1ShadowLo,undefined4 u2ShadowHi,undefined4 u2ShadowLo,undefined4 vn,double u1,double u2,double v1,double v2)
{
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  
  ((void (*)())_glMapGrid2d_Comp)(glContext,un,u1ShadowHi,u1ShadowLo,u2ShadowHi,u2ShadowLo,vn,u1,u2,
                    v1,v2);
  ((void (*)())_glMapGrid2d_Exec)(glContext,un,u1ShadowHi,u1ShadowLo,u2ShadowHi,u2ShadowLo,vn,u1,u2,
                    v1,v2,in_f5,in_f6,in_f7,in_f8,(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x8)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),
                    (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
  return;
}

/* _glIndexMask_ListExec @ 0x75eec (40 bytes) */
int _glIndexMask_ListExec(glContext, listRecord)
  undefined4 glContext;
  undefined4 *listRecord;
{
  ((void (*)())_glIndexMask_Exec)(glContext,*listRecord);
  return 4;
}

/* _glIndexMask_Comp @ 0x75f14 (76 bytes) */
int _glIndexMask_Comp(glContext, mask)
  undefined4 glContext;
  undefined4 mask;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glIndexMask_ListExec_001101e0,4);
  if (listRecord != (undefined4 *)0x0) {
    *listRecord = mask;
  }
  return listRecord;
}

/* _glIndexMask_Exec @ 0x75f60 (56 bytes) */
void _glIndexMask_Exec(glContext, mask)
  int glContext;
  undefined4 mask;
{
  if (*(short *)(glContext + 0x4a10) < 0) {
    *(undefined4 *)(glContext + 0x3194) = mask;
    *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x40000;
    return;
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  *(undefined4 *)(glContext + 0x7574) = 0x502;
  return;
}

/* _glIndexMask_CompExec @ 0x75f98 (56 bytes) */
void _glIndexMask_CompExec(glContext, mask)
  undefined4 glContext;
  undefined4 mask;
{
  ((int (*)())_glIndexMask_Comp)(glContext,mask);
  ((void (*)())_glIndexMask_Exec)(glContext,mask);
  return;
}

/* _glColorMask_ListExec @ 0x75fd0 (56 bytes) */
int _glColorMask_ListExec(glContext, listRecord)
  undefined4 glContext;
  byte *listRecord;
{
  _glColorMask_Exec(glContext,(uint)*listRecord,(uint)listRecord[1],(uint)listRecord[2],(uint)listRecord[3]);
  return 4;
}

/* _glStencilMask_ListExec @ 0x76008 (40 bytes) */
int _glStencilMask_ListExec(glContext, listRecord)
  undefined4 glContext;
  undefined4 *listRecord;
{
  _glStencilMask_Exec(glContext,*listRecord);
  return 4;
}

/* _glStencilMask_Comp @ 0x76030 (76 bytes) */
int _glStencilMask_Comp(glContext, mask)
  undefined4 glContext;
  undefined4 mask;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glStencilMask_ListExec_001101d4,4);
  if (listRecord != (undefined4 *)0x0) {
    *listRecord = mask;
  }
  return listRecord;
}

/* _glStencilMask_CompExec @ 0x7607c (56 bytes) */
void _glStencilMask_CompExec(glContext, mask)
  undefined4 glContext;
  undefined4 mask;
{
  ((int (*)())_glStencilMask_Comp)(glContext,mask);
  _glStencilMask_Exec(glContext,mask);
  return;
}

/* _glStencilMaskSeparate_ListExec @ 0x760b4 (44 bytes) */
int _glStencilMaskSeparate_ListExec(glContext, listRecord)
  undefined4 glContext;
  undefined4 *listRecord;
{
  ((void (*)())_glStencilMaskSeparate_Exec)(glContext,*listRecord,listRecord[1]);
  return 8;
}

/* _glStencilMaskSeparate_Comp @ 0x760e0 (84 bytes) */
int _glStencilMaskSeparate_Comp(glContext, face, mask)
  undefined4 glContext;
  undefined4 face;
  undefined4 mask;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glStencilMaskSeparate_ListExec_001101d0,8);
  if (listRecord != (undefined4 *)0x0) {
    listRecord[1] = mask;
    *listRecord = face;
  }
  return listRecord;
}

/* _glStencilMaskSeparate_Exec @ 0x76134 (132 bytes) */
void _glStencilMaskSeparate_Exec(glContext, face, mask)
  int glContext;
  uint face;
  undefined4 mask;
{
  undefined4 glErrorCode;
  
  if (-1 < *(short *)(glContext + 0x4a10)) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
    goto LAB_000761a0;
  }
  if (face == 0x405) {
    *(undefined4 *)(glContext + 0x319c) = mask;
    goto LAB_000761a8;
  }
  if (face < 0x406) {
    if (face == 0x404) {
LAB_00076188:
      *(undefined4 *)(glContext + 0x3198) = mask;
LAB_000761a8:
      *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x100000;
      return;
    }
  }
  else if (face == 0x408) {
    *(undefined4 *)(glContext + 0x319c) = mask;
    goto LAB_00076188;
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  glErrorCode = 0x500;
LAB_000761a0:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glStencilMaskSeparate_CompExec @ 0x761b8 (64 bytes) */
void _glStencilMaskSeparate_CompExec(glContext, face, mask)
  undefined4 glContext;
  undefined4 face;
  undefined4 mask;
{
  ((int (*)())_glStencilMaskSeparate_Comp)(glContext,face,mask);
  ((void (*)())_glStencilMaskSeparate_Exec)(glContext,face,mask);
  return;
}

/* _glMaterialf_ListExec @ 0x761f8 (52 bytes) */
undefined4 _glMaterialf_ListExec(undefined4 glContext,undefined4 *listRecord,double unusedFloatArg1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
{
  ((void (*)())_glMaterialf_Exec)(glContext,*listRecord,listRecord[1],(double)GH_U2F((unsigned int)(listRecord[2])),forwardedFloatArg2,forwardedFloatArg3,forwardedFloatArg4
                    ,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
  return 0xc;
}

/* _glMaterialf_Comp @ 0x7622c (100 bytes) */
undefined4 * _glMaterialf_Comp(undefined4 glContext,undefined4 face,undefined4 pname,float param)
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glMaterialf_ListExec_001101f0,0xc);
  if (listRecord != (undefined4 *)0x0) {
    listRecord[2] = (float)param;
    *listRecord = face;
    listRecord[1] = pname;
  }
  return listRecord;
}

/* _glMaterialf_CompExec @ 0x76290 (80 bytes) */
void _glMaterialf_CompExec(undefined4 glContext,undefined4 face,undefined4 pname,float param)
{
  double in_f2;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  
  ((undefined4 * (*)())_glMaterialf_Comp)(glContext,face,pname,param);
  ((void (*)())_glMaterialf_Exec)(glContext,face,pname,param,in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8);
  return;
}

/* _glMateriali_ListExec @ 0x762e0 (52 bytes) */
undefined4 _glMateriali_ListExec(undefined4 glContext,undefined4 *listRecord,double forwardedFloatArg1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
{
  ((void (*)())_glMateriali_Exec)(glContext,*listRecord,listRecord[1],listRecord[2],forwardedFloatArg1,forwardedFloatArg2,forwardedFloatArg3,forwardedFloatArg4,
                    forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
  return 0xc;
}

/* _glMateriali_Comp @ 0x76314 (92 bytes) */
int _glMateriali_Comp(glContext, face, pname, param)
  undefined4 glContext;
  undefined4 face;
  undefined4 pname;
  undefined4 param;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glMateriali_ListExec_001101e8,0xc);
  if (listRecord != (undefined4 *)0x0) {
    listRecord[2] = param;
    *listRecord = face;
    listRecord[1] = pname;
  }
  return listRecord;
}

/* _glMateriali_Exec @ 0x76370 (356 bytes) */
void _glMateriali_Exec(int glContext,uint face,int pname,uint param,double forwardedFloatArg1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
{
  undefined4 glErrorCode;
  
  if (((*(char *)(glContext + 0x7580) != '\0') && (-1 < *(short *)(glContext + 0x4a10))) &&
     (*(char *)(glContext + 0x4664) == '\0')) {
    ((undefined4 (*)())_gleForceToSoftwareTCL)(glContext,forwardedFloatArg1,forwardedFloatArg2,forwardedFloatArg3,forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
  }
  if (pname == 0x1601) {
    if (((int)param < 0) || (*(int *)(*(int *)(glContext + 0x468c) + 0xa0) < (int)param)) {
      if (*(int *)(glContext + 0x7574) != 0) {
        return;
      }
      glErrorCode = 0x501;
      goto LAB_000764bc;
    }
    if (face == 0x405) {
      ((void (*)())_gleLightMaterialShineChange_B)(glContext,(double)(float)((double)CONCAT44(0x43300000,param ^ 0x80000000) -
                                        DOUBLE_00108d58));
      return;
    }
    if (face < 0x406) {
      if (face == 0x404) {
        ((void (*)())_gleLightMaterialShineChange_F)(glContext,(double)(float)((double)CONCAT44(0x43300000,param ^ 0x80000000) -
                                          DOUBLE_00108d58));
        return;
      }
    }
    else if (face == 0x408) {
      ((void (*)())_gleLightMaterialShineChange_FB)(glContext,(double)(float)((double)CONCAT44(0x43300000,param ^ 0x80000000) -
                                        DOUBLE_00108d58));
      return;
    }
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  glErrorCode = 0x500;
LAB_000764bc:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glMateriali_CompExec @ 0x764d4 (72 bytes) */
void _glMateriali_CompExec(glContext, face, pname, param)
  undefined4 glContext;
  undefined4 face;
  undefined4 pname;
  undefined4 param;
{
  double fparam_1;
  double in_f2;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  
  ((int (*)())_glMateriali_Comp)(glContext,face,pname,param);
  ((void (*)())_glMateriali_Exec)(glContext,face,pname,param,fparam_1,in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,
                    in_f8);
  return;
}

/* _glMaterialiv_ListExec @ 0x7651c (52 bytes) */
undefined4 _glMaterialiv_ListExec(undefined4 glContext,undefined4 *listRecord,double forwardedFloatArg1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
{
  ((void (*)())_glMaterialiv_Exec)(glContext,*listRecord,listRecord[1],listRecord + 2,forwardedFloatArg1,forwardedFloatArg2,forwardedFloatArg3,forwardedFloatArg4,
                     forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
  return 0x18;
}

/* _glMaterialiv_Comp @ 0x76550 (284 bytes) */
int _glMaterialiv_Comp(glContext, face, pname, params)
  int glContext;
  undefined4 face;
  undefined *pname;
  undefined4 *params;
{
  undefined *puVar1;
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glMaterialiv_ListExec_001101e4,0x18);
  if (listRecord == (undefined4 *)0x0) {
    return listRecord;
  }
  if (pname != (undefined *)0x1600) {
    if (pname < (undefined *)0x1601) {
      if (pname != ((unsigned char *)0x00001201)) {
        if (((unsigned char *)0x00001201) < pname) {
          puVar1 = ((unsigned char *)0x00001202);
        }
        else {
          puVar1 = ((unsigned char *)0x00001200);
        }
        if (pname != puVar1) goto LAB_00076644;
      }
    }
    else if (pname != (undefined *)0x1602) {
      if (pname < (undefined *)0x1602) {
        *listRecord = face;
        listRecord[1] = pname;
        listRecord[2] = *params;
        return listRecord;
      }
      if (pname == (undefined *)0x1603) {
        *listRecord = face;
        listRecord[1] = 0x1603;
        listRecord[2] = *params;
        listRecord[3] = params[1];
        listRecord[4] = params[2];
        return listRecord;
      }
LAB_00076644:
      if (*(int *)(glContext + 0x7574) != 0) {
        return listRecord;
      }
      *(undefined4 *)(glContext + 0x7574) = 0x500;
      return listRecord;
    }
  }
  *listRecord = face;
  listRecord[1] = pname;
  listRecord[2] = *params;
  listRecord[3] = params[1];
  listRecord[4] = params[2];
  listRecord[5] = params[3];
  return listRecord;
}

/* _glMaterialiv_Exec @ 0x7666c (1968 bytes) */
void _glMaterialiv_Exec(int glContext,uint face,undefined *pname,uint *params,double forwardedFloatArg1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
{
  int remaining;
  undefined4 glErrorCode;
  uint uVar3;
  int iVar4;
  uint uVar5;
  double dVar6;
  double dVar7;
  double dVar8;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  undefined4 local_30;
  uint uStack_2c;
  
  if (((*(char *)(glContext + 0x7580) != '\0') && (-1 < *(short *)(glContext + 0x4a10))) &&
     (*(char *)(glContext + 0x4664) == '\0')) {
    ((undefined4 (*)())_gleForceToSoftwareTCL)(glContext,forwardedFloatArg1,forwardedFloatArg2,forwardedFloatArg3,forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
  }
  if (pname == (undefined *)0x1600) {
    local_30 = 0x43300000;
    uStack_2c = params[3] ^ 0x80000000;
    local_40 = (float)((double)CONCAT44(0x43300000,*params ^ 0x80000000) - DOUBLE_00108d58) *
               FLOAT_00108e68 + FLOAT_00108e6c;
    local_3c = (float)((double)CONCAT44(0x43300000,params[1] ^ 0x80000000) - DOUBLE_00108d58) *
               FLOAT_00108e68 + FLOAT_00108e6c;
    local_34 = (float)((double)CONCAT44(0x43300000,uStack_2c) - DOUBLE_00108d58) * FLOAT_00108e68 +
               FLOAT_00108e6c;
    local_38 = (float)((double)CONCAT44(0x43300000,params[2] ^ 0x80000000) - DOUBLE_00108d58) *
               FLOAT_00108e68 + FLOAT_00108e6c;
    if (face == 0x405) {
      _gleLightMaterialRGBAChange_B_E(glContext,&local_40);
      goto LAB_00076dd8;
    }
    if (face < 0x406) {
      if (face == 0x404) {
        _gleLightMaterialRGBAChange_F_E(glContext,&local_40);
        goto LAB_00076dd8;
      }
    }
    else if (face == 0x408) {
      _gleLightMaterialRGBAChange_FB_E(glContext,&local_40);
      goto LAB_00076dd8;
    }
  }
  else if (pname < (undefined *)0x1601) {
    if (pname == ((unsigned char *)0x00001201)) {
      local_30 = 0x43300000;
      uStack_2c = params[3] ^ 0x80000000;
      local_40 = (float)((double)CONCAT44(0x43300000,*params ^ 0x80000000) - DOUBLE_00108d58) *
                 FLOAT_00108e68 + FLOAT_00108e6c;
      local_3c = (float)((double)CONCAT44(0x43300000,params[1] ^ 0x80000000) - DOUBLE_00108d58) *
                 FLOAT_00108e68 + FLOAT_00108e6c;
      local_34 = (float)((double)CONCAT44(0x43300000,uStack_2c) - DOUBLE_00108d58) * FLOAT_00108e68
                 + FLOAT_00108e6c;
      local_38 = (float)((double)CONCAT44(0x43300000,params[2] ^ 0x80000000) - DOUBLE_00108d58) *
                 FLOAT_00108e68 + FLOAT_00108e6c;
      if (face == 0x405) {
        _gleLightMaterialRGBAChange_B_D(glContext,&local_40);
        goto LAB_00076dd8;
      }
      if (face < 0x406) {
        if (face == 0x404) {
          _gleLightMaterialRGBAChange_F_D(glContext,&local_40);
          goto LAB_00076dd8;
        }
      }
      else if (face == 0x408) {
        _gleLightMaterialRGBAChange_FB_D(glContext,&local_40);
        goto LAB_00076dd8;
      }
    }
    else if (((unsigned char *)0x00001201) < pname) {
      if (pname == ((unsigned char *)0x00001202)) {
        local_30 = 0x43300000;
        uStack_2c = params[3] ^ 0x80000000;
        local_40 = (float)((double)CONCAT44(0x43300000,*params ^ 0x80000000) - DOUBLE_00108d58) *
                   FLOAT_00108e68 + FLOAT_00108e6c;
        local_3c = (float)((double)CONCAT44(0x43300000,params[1] ^ 0x80000000) - DOUBLE_00108d58) *
                   FLOAT_00108e68 + FLOAT_00108e6c;
        local_34 = (float)((double)CONCAT44(0x43300000,uStack_2c) - DOUBLE_00108d58) *
                   FLOAT_00108e68 + FLOAT_00108e6c;
        local_38 = (float)((double)CONCAT44(0x43300000,params[2] ^ 0x80000000) - DOUBLE_00108d58) *
                   FLOAT_00108e68 + FLOAT_00108e6c;
        if (face == 0x405) {
          _gleLightMaterialRGBAChange_B_S(glContext,&local_40);
          goto LAB_00076dd8;
        }
        if (face < 0x406) {
          if (face == 0x404) {
            _gleLightMaterialRGBAChange_F_S(glContext,&local_40);
            goto LAB_00076dd8;
          }
        }
        else if (face == 0x408) {
          _gleLightMaterialRGBAChange_FB_S(glContext,&local_40);
          goto LAB_00076dd8;
        }
      }
    }
    else if (pname == ((unsigned char *)0x00001200)) {
      local_30 = 0x43300000;
      uStack_2c = params[3] ^ 0x80000000;
      local_40 = (float)((double)CONCAT44(0x43300000,*params ^ 0x80000000) - DOUBLE_00108d58) *
                 FLOAT_00108e68 + FLOAT_00108e6c;
      local_3c = (float)((double)CONCAT44(0x43300000,params[1] ^ 0x80000000) - DOUBLE_00108d58) *
                 FLOAT_00108e68 + FLOAT_00108e6c;
      local_34 = (float)((double)CONCAT44(0x43300000,uStack_2c) - DOUBLE_00108d58) * FLOAT_00108e68
                 + FLOAT_00108e6c;
      local_38 = (float)((double)CONCAT44(0x43300000,params[2] ^ 0x80000000) - DOUBLE_00108d58) *
                 FLOAT_00108e68 + FLOAT_00108e6c;
      if (face == 0x405) {
        _gleLightMaterialRGBAChange_B_A(glContext,&local_40);
        goto LAB_00076dd8;
      }
      if (face < 0x406) {
        if (face == 0x404) {
          _gleLightMaterialRGBAChange_F_A(glContext,&local_40);
          goto LAB_00076dd8;
        }
      }
      else if (face == 0x408) {
        _gleLightMaterialRGBAChange_FB_A(glContext,&local_40);
        goto LAB_00076dd8;
      }
    }
  }
  else if (pname == (undefined *)0x1602) {
    local_30 = 0x43300000;
    uStack_2c = params[3] ^ 0x80000000;
    local_40 = (float)((double)CONCAT44(0x43300000,*params ^ 0x80000000) - DOUBLE_00108d58) *
               FLOAT_00108e68 + FLOAT_00108e6c;
    local_3c = (float)((double)CONCAT44(0x43300000,params[1] ^ 0x80000000) - DOUBLE_00108d58) *
               FLOAT_00108e68 + FLOAT_00108e6c;
    local_34 = (float)((double)CONCAT44(0x43300000,uStack_2c) - DOUBLE_00108d58) * FLOAT_00108e68 +
               FLOAT_00108e6c;
    local_38 = (float)((double)CONCAT44(0x43300000,params[2] ^ 0x80000000) - DOUBLE_00108d58) *
               FLOAT_00108e68 + FLOAT_00108e6c;
    if (face == 0x405) {
      _gleLightMaterialRGBAChange_B_AD(glContext,&local_40);
      goto LAB_00076dd8;
    }
    if (face < 0x406) {
      if (face == 0x404) {
        _gleLightMaterialRGBAChange_F_AD(glContext,&local_40);
        goto LAB_00076dd8;
      }
    }
    else if (face == 0x408) {
      _gleLightMaterialRGBAChange_FB_AD(glContext,&local_40);
      goto LAB_00076dd8;
    }
  }
  else if (pname < (undefined *)0x1602) {
    uStack_2c = *params;
    if (((int)uStack_2c < 0) || (*(int *)(*(int *)(glContext + 0x468c) + 0xa0) < (int)uStack_2c)) {
      if (*(int *)(glContext + 0x7574) != 0) {
        return;
      }
      glErrorCode = 0x501;
      goto LAB_00076dd0;
    }
    if (face == 0x405) {
      uStack_2c = uStack_2c ^ 0x80000000;
      local_30 = 0x43300000;
      ((void (*)())_gleLightMaterialShineChange_B)(glContext,(double)(float)((double)CONCAT44(0x43300000,uStack_2c) - DOUBLE_00108d58));
      goto LAB_00076dd8;
    }
    if (face < 0x406) {
      if (face == 0x404) {
        uStack_2c = uStack_2c ^ 0x80000000;
        local_30 = 0x43300000;
        ((void (*)())_gleLightMaterialShineChange_F)(glContext,(double)(float)((double)CONCAT44(0x43300000,uStack_2c) - DOUBLE_00108d58)
                  );
        goto LAB_00076dd8;
      }
    }
    else if (face == 0x408) {
      uStack_2c = uStack_2c ^ 0x80000000;
      local_30 = 0x43300000;
      ((void (*)())_gleLightMaterialShineChange_FB)(glContext,(double)(float)((double)CONCAT44(0x43300000,uStack_2c) - DOUBLE_00108d58));
      goto LAB_00076dd8;
    }
  }
  else if (pname == (undefined *)0x1603) {
    local_30 = 0x43300000;
    uStack_2c = params[2] * 0x101 ^ 0x80000000;
    dVar7 = (double)CONCAT44(0x43300000,*params * 0x101 ^ 0x80000000) - DOUBLE_00108d58;
    dVar6 = (double)CONCAT44(0x43300000,uStack_2c) - DOUBLE_00108d58;
    dVar8 = (double)CONCAT44(0x43300000,params[1] * 0x101 ^ 0x80000000) - DOUBLE_00108d58;
    if (face == 0x405) {
      uVar5 = 1;
      uVar3 = 1;
LAB_00076d88:
      if (uVar3 <= uVar5) {
        remaining = (uVar5 + 1) - uVar3;
        iVar4 = uVar3 * 0x10 + glContext;
        do {
          *(float *)(iVar4 + 0x2f0) = (float)dVar7;
          *(float *)(iVar4 + 0x2f4) = (float)dVar8;
          *(float *)(iVar4 + 0x2f8) = (float)dVar6;
          iVar4 = iVar4 + 0x10;
          remaining = remaining + -1;
        } while (remaining != 0);
      }
LAB_00076dd8:
      if (((*(char *)(glContext + 0x4df8) != '\0') && (pname != (undefined *)0x1601)) &&
         (pname != (undefined *)0x1603)) {
        (**(code **)(glContext + 0x4de0))(glContext,glContext + 0x2a0);
      }
      return;
    }
    if (face < 0x406) {
      if (face == 0x404) {
        uVar5 = 0;
        uVar3 = 0;
        goto LAB_00076d88;
      }
    }
    else if (face == 0x408) {
      uVar3 = 0;
      uVar5 = 1;
      goto LAB_00076d88;
    }
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  glErrorCode = 0x500;
LAB_00076dd0:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glMaterialiv_CompExec @ 0x76e1c (72 bytes) */
void _glMaterialiv_CompExec(glContext, face, pname, params)
  undefined4 glContext;
  undefined4 face;
  undefined4 pname;
  undefined4 params;
{
  double fparam_1;
  double in_f2;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  
  ((int (*)())_glMaterialiv_Comp)(glContext,face,pname,params);
  ((void (*)())_glMaterialiv_Exec)(glContext,face,pname,params,fparam_1,in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,
                     in_f8);
  return;
}

/* _glGetMaterialfv_Exec @ 0x76e64 (584 bytes) */
void _glGetMaterialfv_Exec(glContext, face, pname, params)
  int glContext;
  int face;
  undefined *pname;
  float *params;
{
  float fVar1;
  double dVar2;
  undefined4 glErrorCode;
  int iVar4;
  
  if (-1 < *(short *)(glContext + 0x4a10)) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
    goto LAB_00077094;
  }
  if ((*(char *)(glContext + 0x30ab) != '\0') && (*(char *)(glContext + 0x4df8) == '\0')) {
    (**(code **)(glContext + 0x4de0))(glContext,glContext + 0x2a0);
  }
  dVar2 = DOUBLE_00108d98;
  if (face == 0x404) {
    iVar4 = 0;
LAB_00076ef4:
    if (pname == ((unsigned char *)0x00001202)) {
      iVar4 = iVar4 * 4 + glContext;
      *params = *(float *)(*(int *)(iVar4 + 0x4dd0) + 0x20);
      params[1] = *(float *)(*(int *)(iVar4 + 0x4dd0) + 0x24);
      params[2] = *(float *)(*(int *)(iVar4 + 0x4dd0) + 0x28);
      fVar1 = *(float *)(*(int *)(iVar4 + 0x4dd0) + 0x2c);
      goto LAB_0007701c;
    }
    if (((unsigned char *)0x00001202) < pname) {
      if (pname == (undefined *)0x1601) {
        *params = *(float *)(*(int *)(iVar4 * 4 + glContext + 0x4dd0) + 0x40);
        return;
      }
      if (pname < (undefined *)0x1602) {
        if (pname == (undefined *)0x1600) {
          iVar4 = iVar4 * 4 + glContext;
          *params = *(float *)(*(int *)(iVar4 + 0x4dd0) + 0x30);
          params[1] = *(float *)(*(int *)(iVar4 + 0x4dd0) + 0x34);
          params[2] = *(float *)(*(int *)(iVar4 + 0x4dd0) + 0x38);
          fVar1 = *(float *)(*(int *)(iVar4 + 0x4dd0) + 0x3c);
          goto LAB_0007701c;
        }
      }
      else if (pname == (undefined *)0x1603) {
        iVar4 = iVar4 * 0x10 + glContext;
        *params = (float)((double)*(float *)(iVar4 + 0x2f0) * DOUBLE_00108d98);
        params[1] = (float)((double)*(float *)(iVar4 + 0x2f4) * dVar2);
        params[2] = (float)((double)*(float *)(iVar4 + 0x2f8) * dVar2);
        return;
      }
    }
    else {
      if (pname == ((unsigned char *)0x00001200)) {
        iVar4 = iVar4 * 4 + glContext;
        *params = **(float **)(iVar4 + 0x4dd0);
        params[1] = *(float *)(*(int *)(iVar4 + 0x4dd0) + 4);
        params[2] = *(float *)(*(int *)(iVar4 + 0x4dd0) + 8);
        fVar1 = *(float *)(*(int *)(iVar4 + 0x4dd0) + 0xc);
LAB_0007701c:
        params[3] = fVar1;
        return;
      }
      if (pname == ((unsigned char *)0x00001201)) {
        iVar4 = iVar4 * 4 + glContext;
        *params = *(float *)(*(int *)(iVar4 + 0x4dd0) + 0x10);
        params[1] = *(float *)(*(int *)(iVar4 + 0x4dd0) + 0x14);
        params[2] = *(float *)(*(int *)(iVar4 + 0x4dd0) + 0x18);
        fVar1 = *(float *)(*(int *)(iVar4 + 0x4dd0) + 0x1c);
        goto LAB_0007701c;
      }
    }
  }
  else if (face == 0x405) {
    iVar4 = 1;
    goto LAB_00076ef4;
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  glErrorCode = 0x500;
LAB_00077094:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glGetMaterialiv_Exec @ 0x770ac (832 bytes) */
void _glGetMaterialiv_Exec(glContext, face, pname, params)
  int glContext;
  int face;
  undefined *pname;
  int *params;
{
  float fVar1;
  double dVar2;
  float fVar3;
  float fVar4;
  undefined4 glErrorCode;
  int iVar6;
  
  fVar4 = FLOAT_00108e94;
  fVar3 = FLOAT_00108e90;
  dVar2 = DOUBLE_00108d98;
  if (-1 < *(short *)(glContext + 0x4a10)) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
    goto LAB_00077110;
  }
  if (face == 0x404) {
    iVar6 = 0;
LAB_00077118:
    if (pname == ((unsigned char *)0x00001202)) {
      iVar6 = iVar6 * 4 + glContext;
      *params = (int)(*(float *)(*(int *)(iVar6 + 0x4dd0) + 0x20) * FLOAT_00108e94 - FLOAT_00108e90
                      );
      params[1] = (int)(*(float *)(*(int *)(iVar6 + 0x4dd0) + 0x24) * fVar4 - fVar3);
      params[2] = (int)(*(float *)(*(int *)(iVar6 + 0x4dd0) + 0x28) * fVar4 - fVar3);
      fVar1 = *(float *)(*(int *)(iVar6 + 0x4dd0) + 0x2c);
      goto LAB_00077254;
    }
    if (((unsigned char *)0x00001202) < pname) {
      if (pname == (undefined *)0x1601) {
        *params = (int)(*(float *)(*(int *)(iVar6 * 4 + glContext + 0x4dd0) + 0x40) + FLOAT_00108e90)
        ;
        return;
      }
      if (pname < (undefined *)0x1602) {
        if (pname == (undefined *)0x1600) {
          iVar6 = iVar6 * 4 + glContext;
          *params = (int)(*(float *)(*(int *)(iVar6 + 0x4dd0) + 0x30) * FLOAT_00108e94 -
                          FLOAT_00108e90);
          params[1] = (int)(*(float *)(*(int *)(iVar6 + 0x4dd0) + 0x34) * fVar4 - fVar3);
          params[2] = (int)(*(float *)(*(int *)(iVar6 + 0x4dd0) + 0x38) * fVar4 - fVar3);
          fVar1 = *(float *)(*(int *)(iVar6 + 0x4dd0) + 0x3c);
          goto LAB_00077254;
        }
      }
      else if (pname == (undefined *)0x1603) {
        iVar6 = iVar6 * 0x10 + glContext;
        *params = (int)((double)*(float *)(iVar6 + 0x2f0) * DOUBLE_00108d98);
        params[1] = (int)((double)*(float *)(iVar6 + 0x2f4) * dVar2);
        params[2] = (int)((double)*(float *)(iVar6 + 0x2f8) * dVar2);
        return;
      }
    }
    else {
      if (pname == ((unsigned char *)0x00001200)) {
        iVar6 = iVar6 * 4 + glContext;
        *params = (int)(**(float **)(iVar6 + 0x4dd0) * FLOAT_00108e94 - FLOAT_00108e90);
        params[1] = (int)(*(float *)(*(int *)(iVar6 + 0x4dd0) + 4) * fVar4 - fVar3);
        params[2] = (int)(*(float *)(*(int *)(iVar6 + 0x4dd0) + 8) * fVar4 - fVar3);
        fVar1 = *(float *)(*(int *)(iVar6 + 0x4dd0) + 0xc);
LAB_00077254:
        params[3] = (int)(fVar1 * fVar4 - fVar3);
        return;
      }
      if (pname == ((unsigned char *)0x00001201)) {
        iVar6 = iVar6 * 4 + glContext;
        *params = (int)(*(float *)(*(int *)(iVar6 + 0x4dd0) + 0x10) * FLOAT_00108e94 -
                        FLOAT_00108e90);
        params[1] = (int)(*(float *)(*(int *)(iVar6 + 0x4dd0) + 0x14) * fVar4 - fVar3);
        params[2] = (int)(*(float *)(*(int *)(iVar6 + 0x4dd0) + 0x18) * fVar4 - fVar3);
        fVar1 = *(float *)(*(int *)(iVar6 + 0x4dd0) + 0x1c);
        goto LAB_00077254;
      }
    }
  }
  else if (face == 0x405) {
    iVar6 = 1;
    goto LAB_00077118;
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  glErrorCode = 0x500;
LAB_00077110:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glLoadIdentity_ListExec @ 0x773ec (36 bytes) */
int _glLoadIdentity_ListExec(glContext)
  undefined4 glContext;
{
  _glLoadIdentity_Exec(glContext);
  return 0;
}

/* _glLoadIdentity_Comp @ 0x77410 (32 bytes) */
int _glLoadIdentity_Comp(glContext)
  undefined4 glContext;
{
  undefined4 listRecord;
  
  listRecord = _gleAddListItem(glContext,PTR__glLoadIdentity_ListExec_0011020c,0);
  return listRecord;
}

/* _glLoadIdentity_CompExec @ 0x77430 (48 bytes) */
void _glLoadIdentity_CompExec(glContext)
  undefined4 glContext;
{
  ((int (*)())_glLoadIdentity_Comp)(glContext);
  _glLoadIdentity_Exec(glContext);
  return;
}

/* _glLoadMatrixd_ListExec @ 0x77460 (36 bytes) */
int _glLoadMatrixd_ListExec(glContext, listRecord)
  undefined4 glContext;
  undefined4 listRecord;
{
  _glLoadMatrixd_Exec(glContext,listRecord);
  return 0x80;
}

/* _glLoadMatrixd_Comp @ 0x77484 (100 bytes) */
int _glLoadMatrixd_Comp(glContext, m)
  undefined4 glContext;
  int m;
{
  int iVar1;
  int listRecord;
  int remaining;
  
  listRecord = _gleAddListItem(glContext,PTR__glLoadMatrixd_ListExec_00110208,0x80);
  if (listRecord != 0) {
    iVar1 = 0;
    remaining = 0x10;
    do {
      *(undefined8 *)(iVar1 + listRecord) = *(undefined8 *)(iVar1 + m);
      iVar1 = iVar1 + 8;
      remaining = remaining + -1;
    } while (remaining != 0);
  }
  return listRecord;
}

/* _glLoadMatrixd_CompExec @ 0x774e8 (56 bytes) */
void _glLoadMatrixd_CompExec(glContext, m)
  undefined4 glContext;
  undefined4 m;
{
  ((int (*)())_glLoadMatrixd_Comp)(glContext,m);
  _glLoadMatrixd_Exec(glContext,m);
  return;
}

/* _glLoadMatrixf_ListExec @ 0x77520 (36 bytes) */
int _glLoadMatrixf_ListExec(glContext, listRecord)
  undefined4 glContext;
  undefined4 listRecord;
{
  _glLoadMatrixf_Exec(glContext,listRecord);
  return 0x40;
}

/* _glLoadMatrixf_Comp @ 0x77544 (100 bytes) */
int _glLoadMatrixf_Comp(glContext, m)
  undefined4 glContext;
  int m;
{
  int iVar1;
  int listRecord;
  int remaining;
  
  listRecord = _gleAddListItem(glContext,PTR__glLoadMatrixf_ListExec_00110204,0x40);
  if (listRecord != 0) {
    iVar1 = 0;
    remaining = 0x10;
    do {
      *(undefined4 *)(iVar1 + listRecord) = *(undefined4 *)(iVar1 + m);
      iVar1 = iVar1 + 4;
      remaining = remaining + -1;
    } while (remaining != 0);
  }
  return listRecord;
}

/* _glLoadMatrixf_CompExec @ 0x775a8 (56 bytes) */
void _glLoadMatrixf_CompExec(glContext, m)
  undefined4 glContext;
  undefined4 m;
{
  ((int (*)())_glLoadMatrixf_Comp)(glContext,m);
  _glLoadMatrixf_Exec(glContext,m);
  return;
}

/* _glLoadTransposeMatrixd_ListExec @ 0x775e0 (36 bytes) */
int _glLoadTransposeMatrixd_ListExec(glContext, listRecord)
  undefined4 glContext;
  undefined4 listRecord;
{
  ((int (*)())_glLoadTransposeMatrixd_Exec)(glContext,listRecord);
  return 0x80;
}

/* _glLoadTransposeMatrixd_Comp @ 0x77604 (100 bytes) */
int _glLoadTransposeMatrixd_Comp(glContext, m)
  undefined4 glContext;
  int m;
{
  int iVar1;
  int listRecord;
  int remaining;
  
  listRecord = _gleAddListItem(glContext,PTR__glLoadTransposeMatrixd_ListExec_00110200,0x80);
  if (listRecord != 0) {
    iVar1 = 0;
    remaining = 0x10;
    do {
      *(undefined8 *)(iVar1 + listRecord) = *(undefined8 *)(iVar1 + m);
      iVar1 = iVar1 + 8;
      remaining = remaining + -1;
    } while (remaining != 0);
  }
  return listRecord;
}

/* _glLoadTransposeMatrixd_Exec @ 0x77668 (128 bytes) */
int _glLoadTransposeMatrixd_Exec(glContext, m)
  int glContext;
  undefined4 m;
{
  if ((*(short *)(glContext + 0x4a10) < 0) && (*(int *)(glContext + 0x4ff4) < 0x18)) {
    m = _gleLoadTransposeMatrixd(m,*(undefined4 *)(glContext + 0x4fec));
    *(uint *)(glContext + 0x50ac) = *(uint *)(glContext + 0x50ac) | *(uint *)(glContext + 0x50a8);
    *(uint *)(glContext + 0x50b0) = *(uint *)(glContext + 0x50b0) | *(uint *)(glContext + 0x50a8);
  }
  else if (*(int *)(glContext + 0x7574) == 0) {
    *(undefined4 *)(glContext + 0x7574) = 0x502;
  }
  return m;
}

