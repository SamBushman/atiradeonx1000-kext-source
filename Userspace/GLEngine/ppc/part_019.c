#include "decls.h"

/* _glMapVertexAttrib2fARB_Comp @ 0x7192c (520 bytes) */
void _glMapVertexAttrib2fARB_Comp(int glContext,undefined4 index,uint size,undefined4 u1Shadow,undefined4 u2Shadow,undefined4 ustride,int uorder,undefined4 v1Shadow,undefined4 v2Shadow,undefined4 vstride,int vorder,undefined4 points,float u1,float u2,float v1,float v2)
{
  undefined4 *listRecord;
  undefined4 extraout_r4;
  undefined4 extraout_r4_00;
  undefined4 extraout_r4_01;
  undefined4 extraout_r4_02;
  int payloadBytes;
  undefined4 forwardedUstride;
  int forwardedUorder;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  double incomingFpr9;
  double incomingFpr10;
  double incomingFpr11;
  double incomingFpr12;
  double incomingFpr13;
  
  if (size == 2) {
    payloadBytes = (100 - uorder * vorder) * -8 + 0x344;
    forwardedUstride = ustride;
    forwardedUorder = uorder;
    listRecord = (undefined4 *)
             _gleAddListItem(glContext,PTR__glMap2VertexAttrib2ARB_ListExec_0011019c,payloadBytes);
    if (listRecord == (undefined4 *)0x0) goto LAB_00071b28;
    ((void (*)())_gleMap2VertexAttrib2fLoad)(glContext,extraout_r4_00,payloadBytes,ustride,uorder,forwardedUstride,forwardedUorder,vstride,vorder,points,
               listRecord + 1,u1,u2,v1,v2,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,incomingFpr9,incomingFpr10,
               incomingFpr11,incomingFpr12,incomingFpr13);
  }
  else if (size < 3) {
    if (size != 1) {
LAB_00071b14:
      if (*(int *)(glContext + 0x7574) == 0) {
        *(undefined4 *)(glContext + 0x7574) = 0x501;
      }
      goto LAB_00071b28;
    }
    payloadBytes = (100 - uorder * vorder) * -4 + 0x1b4;
    forwardedUstride = ustride;
    forwardedUorder = uorder;
    listRecord = (undefined4 *)
             _gleAddListItem(glContext,PTR__glMap2VertexAttrib1ARB_ListExec_001101a0,payloadBytes);
    if (listRecord == (undefined4 *)0x0) goto LAB_00071b28;
    ((void (*)())_gleMap2VertexAttrib1fLoad)(glContext,extraout_r4,payloadBytes,ustride,uorder,forwardedUstride,forwardedUorder,vstride,vorder,points,
               listRecord + 1,u1,u2,v1,v2,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,incomingFpr9,incomingFpr10,
               incomingFpr11,incomingFpr12,incomingFpr13);
  }
  else if (size == 3) {
    payloadBytes = (100 - uorder * vorder) * -0xc + 0x4d4;
    forwardedUstride = ustride;
    forwardedUorder = uorder;
    listRecord = (undefined4 *)
             _gleAddListItem(glContext,PTR__glMap2VertexAttrib3ARB_ListExec_00110198,payloadBytes);
    if (listRecord == (undefined4 *)0x0) goto LAB_00071b28;
    ((void (*)())_gleMap2VertexAttrib3fLoad)(glContext,extraout_r4_01,payloadBytes,ustride,uorder,forwardedUstride,forwardedUorder,vstride,vorder,points,
               listRecord + 1,u1,u2,v1,v2,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,incomingFpr9,incomingFpr10,
               incomingFpr11,incomingFpr12,incomingFpr13);
  }
  else {
    if (size != 4) goto LAB_00071b14;
    payloadBytes = (100 - uorder * vorder) * -0x10 + 0x664;
    forwardedUstride = ustride;
    forwardedUorder = uorder;
    listRecord = (undefined4 *)
             _gleAddListItem(glContext,PTR__glMap2VertexAttrib4ARB_ListExec_00110194,payloadBytes);
    if (listRecord == (undefined4 *)0x0) goto LAB_00071b28;
    ((void (*)())_gleMap2VertexAttrib4fLoad)(glContext,extraout_r4_02,payloadBytes,ustride,uorder,forwardedUstride,forwardedUorder,vstride,vorder,points,
               listRecord + 1,u1,u2,v1,v2,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,incomingFpr9,incomingFpr10,
               incomingFpr11,incomingFpr12,incomingFpr13);
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
  undefined4 r4AfterCall;
  uint sizeCopy;
  int ustrideCopy;
  int uorderCopy;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  double incomingFpr9;
  double incomingFpr10;
  double incomingFpr11;
  double incomingFpr12;
  double incomingFpr13;
  
  sizeCopy = size;
  ustrideCopy = ustride;
  uorderCopy = uorder;
  mapData = _gleGetMapData(glContext);
  if (*(short *)(glContext + 0x4a10) < 0) {
    if ((((index < 0x10) && (u1 != u2)) && (v1 != v2)) &&
       (((0 < uorder && (uorder < 0xb)) && ((0 < vorder && (vorder < 0xb)))))) {
      if (size == 2) {
        if ((1 < ustride) && (1 < vstride)) {
          ((void (*)())_gleMap2VertexAttrib2fLoad)(glContext,r4AfterCall,sizeCopy,ustride,uorder,ustrideCopy,uorderCopy,vstride,vorder,
                     points,mapData + index * 0x660 + 0x37a8,u1,u2,v1,v2,
                     incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,incomingFpr9,incomingFpr10,incomingFpr11,incomingFpr12,incomingFpr13);
          goto LAB_00071d40;
        }
      }
      else if (size < 3) {
        if (((size == 1) && (0 < ustride)) && (0 < vstride)) {
          ((void (*)())_gleMap2VertexAttrib1fLoad)(glContext,r4AfterCall,sizeCopy,ustride,uorder,ustrideCopy,uorderCopy,vstride,vorder,
                     points,mapData + index * 0x660 + 0x37a8,u1,u2,v1,v2,
                     incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,incomingFpr9,incomingFpr10,incomingFpr11,incomingFpr12,incomingFpr13);
          goto LAB_00071d40;
        }
      }
      else if (size == 3) {
        if ((2 < ustride) && (2 < vstride)) {
          ((void (*)())_gleMap2VertexAttrib3fLoad)(glContext,r4AfterCall,sizeCopy,ustride,uorder,ustrideCopy,uorderCopy,vstride,vorder,
                     points,mapData + index * 0x660 + 0x37a8,u1,u2,v1,v2,
                     incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,incomingFpr9,incomingFpr10,incomingFpr11,incomingFpr12,incomingFpr13);
          goto LAB_00071d40;
        }
      }
      else if (((size == 4) && (3 < ustride)) && (3 < vstride)) {
        ((void (*)())_gleMap2VertexAttrib4fLoad)(glContext,r4AfterCall,sizeCopy,ustride,uorder,ustrideCopy,uorderCopy,vstride,vorder,points,
                   mapData + index * 0x660 + 0x37a8,u1,u2,v1,v2,incomingFpr5,incomingFpr6,
                   incomingFpr7,incomingFpr8,incomingFpr9,incomingFpr10,incomingFpr11,incomingFpr12,incomingFpr13);
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
  undefined4 incomingStackWord_ffffff98;
  
  ((void (*)())_glMapVertexAttrib2fARB_Comp)(glContext,index,size,u1Shadow,u2Shadow,ustride,uorder,v1Shadow,incomingStackWord_ffffff98,
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
  int payloadBytes;
  undefined4 forwardedUstride;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  double incomingFpr9;
  double incomingFpr10;
  double incomingFpr11;
  double incomingFpr12;
  double incomingFpr13;
  undefined4 incomingStackWord_ffffff88;
  undefined4 incomingStackWord_ffffff8c;
  undefined4 incomingStackWord_ffffff90;
  
  if (size == 2) {
    payloadBytes = (100 - uorder * vorder) * -8 + 0x344;
    forwardedUstride = ustride;
    listRecord = (undefined4 *)
             _gleAddListItem(glContext,PTR__glMap2VertexAttrib2ARB_ListExec_0011019c,payloadBytes);
    if (listRecord == (undefined4 *)0x0) goto LAB_00072010;
    ((void (*)())_gleMap2VertexAttrib2dLoad)(glContext,extraout_r4_00,payloadBytes,u1ShadowHi,u1ShadowLo,ustride,uorder,forwardedUstride,incomingStackWord_ffffff88,
               incomingStackWord_ffffff8c,incomingStackWord_ffffff90,vstride,vorder,points,listRecord + 1,u1,
               u2,v1,v2,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,incomingFpr9,incomingFpr10,incomingFpr11,incomingFpr12,incomingFpr13)
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
    payloadBytes = (100 - uorder * vorder) * -4 + 0x1b4;
    forwardedUstride = ustride;
    listRecord = (undefined4 *)
             _gleAddListItem(glContext,PTR__glMap2VertexAttrib1ARB_ListExec_001101a0,payloadBytes);
    if (listRecord == (undefined4 *)0x0) goto LAB_00072010;
    ((void (*)())_gleMap2VertexAttrib1dLoad)(glContext,extraout_r4,payloadBytes,u1ShadowHi,u1ShadowLo,ustride,uorder,forwardedUstride,incomingStackWord_ffffff88,
               incomingStackWord_ffffff8c,incomingStackWord_ffffff90,vstride,vorder,points,listRecord + 1,u1,
               u2,v1,v2,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,incomingFpr9,incomingFpr10,incomingFpr11,incomingFpr12,incomingFpr13)
    ;
  }
  else if (size == 3) {
    payloadBytes = (100 - uorder * vorder) * -0xc + 0x4d4;
    forwardedUstride = ustride;
    listRecord = (undefined4 *)
             _gleAddListItem(glContext,PTR__glMap2VertexAttrib3ARB_ListExec_00110198,payloadBytes);
    if (listRecord == (undefined4 *)0x0) goto LAB_00072010;
    ((void (*)())_gleMap2VertexAttrib3dLoad)(glContext,extraout_r4_01,payloadBytes,u1ShadowHi,u1ShadowLo,ustride,uorder,forwardedUstride,incomingStackWord_ffffff88,
               incomingStackWord_ffffff8c,incomingStackWord_ffffff90,vstride,vorder,points,listRecord + 1,u1,
               u2,v1,v2,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,incomingFpr9,incomingFpr10,incomingFpr11,incomingFpr12,incomingFpr13)
    ;
  }
  else {
    if (size != 4) goto LAB_00071ffc;
    payloadBytes = (100 - uorder * vorder) * -0x10 + 0x664;
    forwardedUstride = ustride;
    listRecord = (undefined4 *)
             _gleAddListItem(glContext,PTR__glMap2VertexAttrib4ARB_ListExec_00110194,payloadBytes);
    if (listRecord == (undefined4 *)0x0) goto LAB_00072010;
    ((void (*)())_gleMap2VertexAttrib4dLoad)(glContext,extraout_r4_02,payloadBytes,u1ShadowHi,u1ShadowLo,ustride,uorder,forwardedUstride,incomingStackWord_ffffff88,
               incomingStackWord_ffffff8c,incomingStackWord_ffffff90,vstride,vorder,points,listRecord + 1,u1,
               u2,v1,v2,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,incomingFpr9,incomingFpr10,incomingFpr11,incomingFpr12,incomingFpr13)
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
  undefined4 r4AfterCall;
  uint sizeCopy;
  int ustrideCopy;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  double incomingFpr9;
  double incomingFpr10;
  double incomingFpr11;
  double incomingFpr12;
  double incomingFpr13;
  undefined4 incomingStackWord_ffffff88;
  undefined4 incomingStackWord_ffffff8c;
  undefined4 incomingStackWord_ffffff90;
  
  sizeCopy = size;
  ustrideCopy = ustride;
  mapData = _gleGetMapData(glContext);
  if (*(short *)(glContext + 0x4a10) < 0) {
    if ((((index < 0x10) && (u1 != u2)) && (v1 != v2)) &&
       (((0 < uorder && (uorder < 0xb)) && ((0 < vorder && (vorder < 0xb)))))) {
      if (size == 2) {
        if ((1 < ustride) && (1 < vstride)) {
          ((void (*)())_gleMap2VertexAttrib2dLoad)(glContext,r4AfterCall,sizeCopy,u1ShadowHi,u1ShadowLo,ustride,uorder,ustrideCopy,
                     incomingStackWord_ffffff88,incomingStackWord_ffffff8c,incomingStackWord_ffffff90,vstride,vorder,
                     points,mapData + index * 0x660 + 0x37a8,u1,u2,v1,v2,
                     incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,incomingFpr9,incomingFpr10,incomingFpr11,incomingFpr12,incomingFpr13);
          goto LAB_00072228;
        }
      }
      else if (size < 3) {
        if (((size == 1) && (0 < ustride)) && (0 < vstride)) {
          ((void (*)())_gleMap2VertexAttrib1dLoad)(glContext,r4AfterCall,sizeCopy,u1ShadowHi,u1ShadowLo,ustride,uorder,ustrideCopy,
                     incomingStackWord_ffffff88,incomingStackWord_ffffff8c,incomingStackWord_ffffff90,vstride,vorder,
                     points,mapData + index * 0x660 + 0x37a8,u1,u2,v1,v2,
                     incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,incomingFpr9,incomingFpr10,incomingFpr11,incomingFpr12,incomingFpr13);
          goto LAB_00072228;
        }
      }
      else if (size == 3) {
        if ((2 < ustride) && (2 < vstride)) {
          ((void (*)())_gleMap2VertexAttrib3dLoad)(glContext,r4AfterCall,sizeCopy,u1ShadowHi,u1ShadowLo,ustride,uorder,ustrideCopy,
                     incomingStackWord_ffffff88,incomingStackWord_ffffff8c,incomingStackWord_ffffff90,vstride,vorder,
                     points,mapData + index * 0x660 + 0x37a8,u1,u2,v1,v2,
                     incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,incomingFpr9,incomingFpr10,incomingFpr11,incomingFpr12,incomingFpr13);
          goto LAB_00072228;
        }
      }
      else if (((size == 4) && (3 < ustride)) && (3 < vstride)) {
        ((void (*)())_gleMap2VertexAttrib4dLoad)(glContext,r4AfterCall,sizeCopy,u1ShadowHi,u1ShadowLo,ustride,uorder,ustrideCopy,incomingStackWord_ffffff88
                   ,incomingStackWord_ffffff8c,incomingStackWord_ffffff90,vstride,vorder,points,
                   mapData + index * 0x660 + 0x37a8,u1,u2,v1,v2,incomingFpr5,incomingFpr6,
                   incomingFpr7,incomingFpr8,incomingFpr9,incomingFpr10,incomingFpr11,incomingFpr12,incomingFpr13);
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
  undefined4 incomingStackWord_ffffff8c;
  undefined4 incomingStackWord_ffffff90;
  undefined4 incomingStackWord_ffffff94;
  undefined4 incomingStackWord_ffffff98;
  
  ((void (*)())_glMapVertexAttrib2dARB_Comp)(glContext,index,size,u1ShadowHi,u1ShadowLo,u2ShadowHi,u2ShadowLo,ustride,uorder,
             incomingStackWord_ffffff8c,incomingStackWord_ffffff90,incomingStackWord_ffffff94,incomingStackWord_ffffff98,vstride,
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
  float coefficient;
  undefined4 glErrorCode;
  uint uOrder;
  int controlPointIndex;
  float *srcCursor;
  uint *srcCursor2;
  uint *mapData;
  uint order;
  uint vOrder;
  uint loopIndex2;
  uint vOrderLimit;
  double *dstCursor;
  int dstOffset;
  uint loopIndex;
  double intToDoubleBias;
  double domainV2;
  double domainU2;
  
  mapData = (uint *)_gleGetMapData(glContext);
  intToDoubleBias = DOUBLE_00108d70;
  if (*(short *)(glContext + 0x4a10) < 0) {
    switch(target) {
    case 0xd90:
      if (query == 0xa01) {
        order = mapData[0x70];
LAB_00072910:
        *v = (double)CONCAT44(0x43300000,order) - DOUBLE_00108d70;
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
        domainU2 = (double)GH_U2F((unsigned int)(mapData[0x72]));
LAB_00072928:
        v[1] = domainU2;
        return;
      }
      break;
    case 0xd91:
      if (query == 0xa01) {
        order = mapData[0x9c];
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
            coefficient = *srcCursor;
            loopIndex2 = loopIndex2 + 1;
            srcCursor = srcCursor + 1;
            *v = (double)coefficient;
            v = v + 1;
          } while (loopIndex2 < mapData[0x9c]);
          return;
        }
      }
      else if (query == 0xa02) {
        *v = (double)GH_U2F((unsigned int)(mapData[0x9d]));
        domainU2 = (double)GH_U2F((unsigned int)(mapData[0x9e]));
        goto LAB_00072928;
      }
      break;
    case 0xd92:
      if (query == 0xa01) {
        order = mapData[0x4e];
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
        domainU2 = (double)GH_U2F((unsigned int)(mapData[0x50]));
        goto LAB_00072928;
      }
      break;
    case 0xd93:
      if (query == 0xa01) {
        order = mapData[0xaa];
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
            coefficient = *srcCursor;
            loopIndex2 = loopIndex2 + 1;
            srcCursor = srcCursor + 1;
            *v = (double)coefficient;
            v = v + 1;
          } while (loopIndex2 < mapData[0xaa]);
          return;
        }
      }
      else if (query == 0xa02) {
        *v = (double)GH_U2F((unsigned int)(mapData[0xab]));
        domainU2 = (double)GH_U2F((unsigned int)(mapData[0xac]));
        goto LAB_00072928;
      }
      break;
    case 0xd94:
      if (query == 0xa01) {
        order = mapData[0xb8];
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
        domainU2 = (double)GH_U2F((unsigned int)(mapData[0xba]));
        goto LAB_00072928;
      }
      break;
    case 0xd95:
      if (query == 0xa01) {
        order = mapData[0xd0];
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
        domainU2 = (double)GH_U2F((unsigned int)(mapData[0xd2]));
        goto LAB_00072928;
      }
      break;
    case 0xd96:
      if (query == 0xa01) {
        order = mapData[0xf2];
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
        domainU2 = (double)GH_U2F((unsigned int)(mapData[0xf4]));
        goto LAB_00072928;
      }
      break;
    case 0xd97:
      if (query == 0xa01) {
        order = *mapData;
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
        domainU2 = (double)GH_U2F((unsigned int)(mapData[2]));
        goto LAB_00072928;
      }
      break;
    case 0xd98:
      if (query == 0xa01) {
        order = mapData[0x22];
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
        domainU2 = (double)GH_U2F((unsigned int)(mapData[0x24]));
        goto LAB_00072928;
      }
      break;
    case 0xdb0:
      if (query == 0xa01) {
        *v = (double)CONCAT44(0x43300000,mapData[0x51e]) - DOUBLE_00108d70;
        vOrder = mapData[0x51f];
LAB_000731d8:
        v[1] = (double)CONCAT44(0x43300000,vOrder) - intToDoubleBias;
        return;
      }
      if (query < 0xa02) {
        if (query == 0xa00) {
          vOrderLimit = mapData[0x51f];
          dstOffset = 0;
          loopIndex2 = 0;
          if (vOrderLimit == 0) {
            return;
          }
          uOrder = mapData[0x51e];
          do {
            loopIndex = 0;
            if (uOrder != 0) {
              dstCursor = v + dstOffset;
              do {
                dstOffset = dstOffset + 4;
                controlPointIndex = loopIndex2 * uOrder + loopIndex;
                loopIndex = loopIndex + 1;
                *dstCursor = (double)GH_U2F((unsigned int)(mapData[controlPointIndex * 4 + 0x526]));
                dstCursor[1] = (double)GH_U2F((unsigned int)(mapData[controlPointIndex * 4 + 0x527]));
                dstCursor[2] = (double)GH_U2F((unsigned int)(mapData[controlPointIndex * 4 + 0x528]));
                dstCursor[3] = (double)GH_U2F((unsigned int)(mapData[controlPointIndex * 4 + 0x529]));
                uOrder = mapData[0x51e];
                dstCursor = dstCursor + 4;
              } while (loopIndex < uOrder);
              vOrderLimit = mapData[0x51f];
            }
            loopIndex2 = loopIndex2 + 1;
          } while (loopIndex2 < vOrderLimit);
          return;
        }
      }
      else if (query == 0xa02) {
        *v = (double)GH_U2F((unsigned int)(mapData[0x520]));
        v[1] = (double)GH_U2F((unsigned int)(mapData[0x521]));
        v[2] = (double)GH_U2F((unsigned int)(mapData[0x522]));
        domainV2 = (double)GH_U2F((unsigned int)(mapData[0x523]));
LAB_0007320c:
        v[3] = domainV2;
        return;
      }
      break;
    case 0xdb1:
      if (query == 0xa01) {
        *v = (double)CONCAT44(0x43300000,mapData[0x6b6]) - DOUBLE_00108d70;
        vOrder = mapData[0x6b7];
        goto LAB_000731d8;
      }
      if (query < 0xa02) {
        if (query == 0xa00) {
          vOrderLimit = mapData[0x6b7];
          dstOffset = 0;
          loopIndex2 = 0;
          if (vOrderLimit == 0) {
            return;
          }
          uOrder = mapData[0x6b6];
          do {
            loopIndex = 0;
            if (uOrder != 0) {
              dstCursor = v + dstOffset;
              do {
                dstOffset = dstOffset + 1;
                controlPointIndex = loopIndex2 * uOrder + loopIndex;
                loopIndex = loopIndex + 1;
                *dstCursor = (double)GH_U2F((unsigned int)(mapData[controlPointIndex + 0x6be]));
                dstCursor = dstCursor + 1;
                uOrder = mapData[0x6b6];
              } while (loopIndex < uOrder);
              vOrderLimit = mapData[0x6b7];
            }
            loopIndex2 = loopIndex2 + 1;
          } while (loopIndex2 < vOrderLimit);
          return;
        }
      }
      else if (query == 0xa02) {
        *v = (double)GH_U2F((unsigned int)(mapData[0x6b8]));
        v[1] = (double)GH_U2F((unsigned int)(mapData[0x6b9]));
        v[2] = (double)GH_U2F((unsigned int)(mapData[0x6ba]));
        domainV2 = (double)GH_U2F((unsigned int)(mapData[0x6bb]));
        goto LAB_0007320c;
      }
      break;
    case 0xdb2:
      if (query == 0xa01) {
        *v = (double)CONCAT44(0x43300000,mapData[0x3ea]) - DOUBLE_00108d70;
        vOrder = mapData[0x3eb];
        goto LAB_000731d8;
      }
      if (query < 0xa02) {
        if (query == 0xa00) {
          vOrderLimit = mapData[0x3eb];
          dstOffset = 0;
          loopIndex2 = 0;
          if (vOrderLimit == 0) {
            return;
          }
          uOrder = mapData[0x3ea];
          do {
            loopIndex = 0;
            if (uOrder != 0) {
              dstCursor = v + dstOffset;
              do {
                dstOffset = dstOffset + 3;
                controlPointIndex = loopIndex2 * uOrder + loopIndex;
                loopIndex = loopIndex + 1;
                *dstCursor = (double)GH_U2F((unsigned int)(mapData[controlPointIndex * 3 + 0x3f2]));
                dstCursor[1] = (double)GH_U2F((unsigned int)(mapData[controlPointIndex * 3 + 0x3f3]));
                dstCursor[2] = (double)GH_U2F((unsigned int)(mapData[controlPointIndex * 3 + 0x3f4]));
                uOrder = mapData[0x3ea];
                dstCursor = dstCursor + 3;
              } while (loopIndex < uOrder);
              vOrderLimit = mapData[0x3eb];
            }
            loopIndex2 = loopIndex2 + 1;
          } while (loopIndex2 < vOrderLimit);
          return;
        }
      }
      else if (query == 0xa02) {
        *v = (double)GH_U2F((unsigned int)(mapData[0x3ec]));
        v[1] = (double)GH_U2F((unsigned int)(mapData[0x3ed]));
        v[2] = (double)GH_U2F((unsigned int)(mapData[0x3ee]));
        domainV2 = (double)GH_U2F((unsigned int)(mapData[0x3ef]));
        goto LAB_0007320c;
      }
      break;
    case 0xdb3:
      if (query == 0xa01) {
        *v = (double)CONCAT44(0x43300000,mapData[0x722]) - DOUBLE_00108d70;
        vOrder = mapData[0x723];
        goto LAB_000731d8;
      }
      if (query < 0xa02) {
        if (query == 0xa00) {
          vOrderLimit = mapData[0x723];
          dstOffset = 0;
          loopIndex2 = 0;
          if (vOrderLimit == 0) {
            return;
          }
          uOrder = mapData[0x722];
          do {
            loopIndex = 0;
            if (uOrder != 0) {
              dstCursor = v + dstOffset;
              do {
                dstOffset = dstOffset + 1;
                controlPointIndex = loopIndex2 * uOrder + loopIndex;
                loopIndex = loopIndex + 1;
                *dstCursor = (double)GH_U2F((unsigned int)(mapData[controlPointIndex + 0x72a]));
                dstCursor = dstCursor + 1;
                uOrder = mapData[0x722];
              } while (loopIndex < uOrder);
              vOrderLimit = mapData[0x723];
            }
            loopIndex2 = loopIndex2 + 1;
          } while (loopIndex2 < vOrderLimit);
          return;
        }
      }
      else if (query == 0xa02) {
        *v = (double)GH_U2F((unsigned int)(mapData[0x724]));
        v[1] = (double)GH_U2F((unsigned int)(mapData[0x725]));
        v[2] = (double)GH_U2F((unsigned int)(mapData[0x726]));
        domainV2 = (double)GH_U2F((unsigned int)(mapData[0x727]));
        goto LAB_0007320c;
      }
      break;
    case 0xdb4:
      if (query == 0xa01) {
        *v = (double)CONCAT44(0x43300000,mapData[0x78e]) - DOUBLE_00108d70;
        vOrder = mapData[0x78f];
        goto LAB_000731d8;
      }
      if (query < 0xa02) {
        if (query == 0xa00) {
          vOrderLimit = mapData[0x78f];
          dstOffset = 0;
          loopIndex2 = 0;
          if (vOrderLimit == 0) {
            return;
          }
          uOrder = mapData[0x78e];
          do {
            loopIndex = 0;
            if (uOrder != 0) {
              dstCursor = v + dstOffset;
              do {
                dstOffset = dstOffset + 2;
                controlPointIndex = loopIndex2 * uOrder + loopIndex;
                loopIndex = loopIndex + 1;
                *dstCursor = (double)GH_U2F((unsigned int)(mapData[controlPointIndex * 2 + 0x796]));
                dstCursor[1] = (double)GH_U2F((unsigned int)(mapData[controlPointIndex * 2 + 0x797]));
                uOrder = mapData[0x78e];
                dstCursor = dstCursor + 2;
              } while (loopIndex < uOrder);
              vOrderLimit = mapData[0x78f];
            }
            loopIndex2 = loopIndex2 + 1;
          } while (loopIndex2 < vOrderLimit);
          return;
        }
      }
      else if (query == 0xa02) {
        *v = (double)GH_U2F((unsigned int)(mapData[0x790]));
        v[1] = (double)GH_U2F((unsigned int)(mapData[0x791]));
        v[2] = (double)GH_U2F((unsigned int)(mapData[0x792]));
        domainV2 = (double)GH_U2F((unsigned int)(mapData[0x793]));
        goto LAB_0007320c;
      }
      break;
    case 0xdb5:
      if (query == 0xa01) {
        *v = (double)CONCAT44(0x43300000,mapData[0x85e]) - DOUBLE_00108d70;
        vOrder = mapData[0x85f];
        goto LAB_000731d8;
      }
      if (query < 0xa02) {
        if (query == 0xa00) {
          vOrderLimit = mapData[0x85f];
          dstOffset = 0;
          loopIndex2 = 0;
          if (vOrderLimit == 0) {
            return;
          }
          uOrder = mapData[0x85e];
          do {
            loopIndex = 0;
            if (uOrder != 0) {
              dstCursor = v + dstOffset;
              do {
                dstOffset = dstOffset + 3;
                controlPointIndex = loopIndex2 * uOrder + loopIndex;
                loopIndex = loopIndex + 1;
                *dstCursor = (double)GH_U2F((unsigned int)(mapData[controlPointIndex * 3 + 0x866]));
                dstCursor[1] = (double)GH_U2F((unsigned int)(mapData[controlPointIndex * 3 + 0x867]));
                dstCursor[2] = (double)GH_U2F((unsigned int)(mapData[controlPointIndex * 3 + 0x868]));
                uOrder = mapData[0x85e];
                dstCursor = dstCursor + 3;
              } while (loopIndex < uOrder);
              vOrderLimit = mapData[0x85f];
            }
            loopIndex2 = loopIndex2 + 1;
          } while (loopIndex2 < vOrderLimit);
          return;
        }
      }
      else if (query == 0xa02) {
        *v = (double)GH_U2F((unsigned int)(mapData[0x860]));
        v[1] = (double)GH_U2F((unsigned int)(mapData[0x861]));
        v[2] = (double)GH_U2F((unsigned int)(mapData[0x862]));
        domainV2 = (double)GH_U2F((unsigned int)(mapData[0x863]));
        goto LAB_0007320c;
      }
      break;
    case 0xdb6:
      if (query == 0xa01) {
        *v = (double)CONCAT44(0x43300000,mapData[0x992]) - DOUBLE_00108d70;
        vOrder = mapData[0x993];
        goto LAB_000731d8;
      }
      if (query < 0xa02) {
        if (query == 0xa00) {
          vOrderLimit = mapData[0x993];
          dstOffset = 0;
          loopIndex2 = 0;
          if (vOrderLimit == 0) {
            return;
          }
          uOrder = mapData[0x992];
          do {
            loopIndex = 0;
            if (uOrder != 0) {
              dstCursor = v + dstOffset;
              do {
                dstOffset = dstOffset + 4;
                controlPointIndex = loopIndex2 * uOrder + loopIndex;
                loopIndex = loopIndex + 1;
                *dstCursor = (double)GH_U2F((unsigned int)(mapData[controlPointIndex * 4 + 0x99a]));
                dstCursor[1] = (double)GH_U2F((unsigned int)(mapData[controlPointIndex * 4 + 0x99b]));
                dstCursor[2] = (double)GH_U2F((unsigned int)(mapData[controlPointIndex * 4 + 0x99c]));
                dstCursor[3] = (double)GH_U2F((unsigned int)(mapData[controlPointIndex * 4 + 0x99d]));
                uOrder = mapData[0x992];
                dstCursor = dstCursor + 4;
              } while (loopIndex < uOrder);
              vOrderLimit = mapData[0x993];
            }
            loopIndex2 = loopIndex2 + 1;
          } while (loopIndex2 < vOrderLimit);
          return;
        }
      }
      else if (query == 0xa02) {
        *v = (double)GH_U2F((unsigned int)(mapData[0x994]));
        v[1] = (double)GH_U2F((unsigned int)(mapData[0x995]));
        v[2] = (double)GH_U2F((unsigned int)(mapData[0x996]));
        domainV2 = (double)GH_U2F((unsigned int)(mapData[0x997]));
        goto LAB_0007320c;
      }
      break;
    case 0xdb7:
      if (query == 0xa01) {
        *v = (double)CONCAT44(0x43300000,mapData[0x11e]) - DOUBLE_00108d70;
        vOrder = mapData[0x11f];
        goto LAB_000731d8;
      }
      if (query < 0xa02) {
        if (query == 0xa00) {
          vOrderLimit = mapData[0x11f];
          dstOffset = 0;
          loopIndex2 = 0;
          if (vOrderLimit == 0) {
            return;
          }
          uOrder = mapData[0x11e];
          do {
            loopIndex = 0;
            if (uOrder != 0) {
              dstCursor = v + dstOffset;
              do {
                dstOffset = dstOffset + 3;
                controlPointIndex = loopIndex2 * uOrder + loopIndex;
                loopIndex = loopIndex + 1;
                *dstCursor = (double)GH_U2F((unsigned int)(mapData[controlPointIndex * 3 + 0x126]));
                dstCursor[1] = (double)GH_U2F((unsigned int)(mapData[controlPointIndex * 3 + 0x127]));
                dstCursor[2] = (double)GH_U2F((unsigned int)(mapData[controlPointIndex * 3 + 0x128]));
                uOrder = mapData[0x11e];
                dstCursor = dstCursor + 3;
              } while (loopIndex < uOrder);
              vOrderLimit = mapData[0x11f];
            }
            loopIndex2 = loopIndex2 + 1;
          } while (loopIndex2 < vOrderLimit);
          return;
        }
      }
      else if (query == 0xa02) {
        *v = (double)GH_U2F((unsigned int)(mapData[0x120]));
        v[1] = (double)GH_U2F((unsigned int)(mapData[0x121]));
        v[2] = (double)GH_U2F((unsigned int)(mapData[0x122]));
        domainV2 = (double)GH_U2F((unsigned int)(mapData[0x123]));
        goto LAB_0007320c;
      }
      break;
    case 0xdb8:
      if (query == 0xa01) {
        *v = (double)CONCAT44(0x43300000,mapData[0x252]) - DOUBLE_00108d70;
        vOrder = mapData[0x253];
        goto LAB_000731d8;
      }
      if (query < 0xa02) {
        if (query == 0xa00) {
          vOrderLimit = mapData[0x253];
          dstOffset = 0;
          loopIndex2 = 0;
          if (vOrderLimit == 0) {
            return;
          }
          uOrder = mapData[0x252];
          do {
            loopIndex = 0;
            if (uOrder != 0) {
              dstCursor = v + dstOffset;
              do {
                dstOffset = dstOffset + 4;
                controlPointIndex = loopIndex2 * uOrder + loopIndex;
                loopIndex = loopIndex + 1;
                *dstCursor = (double)GH_U2F((unsigned int)(mapData[controlPointIndex * 4 + 0x25a]));
                dstCursor[1] = (double)GH_U2F((unsigned int)(mapData[controlPointIndex * 4 + 0x25b]));
                dstCursor[2] = (double)GH_U2F((unsigned int)(mapData[controlPointIndex * 4 + 0x25c]));
                dstCursor[3] = (double)GH_U2F((unsigned int)(mapData[controlPointIndex * 4 + 0x25d]));
                uOrder = mapData[0x252];
                dstCursor = dstCursor + 4;
              } while (loopIndex < uOrder);
              vOrderLimit = mapData[0x253];
            }
            loopIndex2 = loopIndex2 + 1;
          } while (loopIndex2 < vOrderLimit);
          return;
        }
      }
      else if (query == 0xa02) {
        *v = (double)GH_U2F((unsigned int)(mapData[0x254]));
        v[1] = (double)GH_U2F((unsigned int)(mapData[0x255]));
        v[2] = (double)GH_U2F((unsigned int)(mapData[0x256]));
        domainV2 = (double)GH_U2F((unsigned int)(mapData[599]));
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
  float domainU2;
  float domainV2;
  float coefficient;
  double intToDoubleBias;
  undefined4 glErrorCode;
  uint uOrder;
  int controlPointIndex;
  float *dstCursor;
  float *srcCursor;
  uint *srcCursor2;
  uint *mapData;
  uint order;
  uint vOrder;
  uint loopIndex2;
  uint vOrderLimit;
  int dstOffset;
  uint loopIndex;
  
  mapData = (uint *)_gleGetMapData(glContext);
  intToDoubleBias = DOUBLE_00108d70;
  if (*(short *)(glContext + 0x4a10) < 0) {
    switch(target) {
    case 0xd90:
      if (query == 0xa01) {
        order = mapData[0x70];
LAB_0007384c:
        *v = (float)((double)CONCAT44(0x43300000,order) - DOUBLE_00108d70);
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
        domainU2 = GH_U2F((unsigned int)(mapData[0x72]));
LAB_00073868:
        v[1] = domainU2;
        return;
      }
      break;
    case 0xd91:
      if (query == 0xa01) {
        order = mapData[0x9c];
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
            coefficient = *srcCursor;
            loopIndex2 = loopIndex2 + 1;
            srcCursor = srcCursor + 1;
            *v = coefficient;
            v = v + 1;
          } while (loopIndex2 < mapData[0x9c]);
          return;
        }
      }
      else if (query == 0xa02) {
        *v = GH_U2F((unsigned int)(mapData[0x9d]));
        domainU2 = GH_U2F((unsigned int)(mapData[0x9e]));
        goto LAB_00073868;
      }
      break;
    case 0xd92:
      if (query == 0xa01) {
        order = mapData[0x4e];
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
        domainU2 = GH_U2F((unsigned int)(mapData[0x50]));
        goto LAB_00073868;
      }
      break;
    case 0xd93:
      if (query == 0xa01) {
        order = mapData[0xaa];
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
            coefficient = *srcCursor;
            loopIndex2 = loopIndex2 + 1;
            srcCursor = srcCursor + 1;
            *v = coefficient;
            v = v + 1;
          } while (loopIndex2 < mapData[0xaa]);
          return;
        }
      }
      else if (query == 0xa02) {
        *v = GH_U2F((unsigned int)(mapData[0xab]));
        domainU2 = GH_U2F((unsigned int)(mapData[0xac]));
        goto LAB_00073868;
      }
      break;
    case 0xd94:
      if (query == 0xa01) {
        order = mapData[0xb8];
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
        domainU2 = GH_U2F((unsigned int)(mapData[0xba]));
        goto LAB_00073868;
      }
      break;
    case 0xd95:
      if (query == 0xa01) {
        order = mapData[0xd0];
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
        domainU2 = GH_U2F((unsigned int)(mapData[0xd2]));
        goto LAB_00073868;
      }
      break;
    case 0xd96:
      if (query == 0xa01) {
        order = mapData[0xf2];
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
        domainU2 = GH_U2F((unsigned int)(mapData[0xf4]));
        goto LAB_00073868;
      }
      break;
    case 0xd97:
      if (query == 0xa01) {
        order = *mapData;
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
        domainU2 = GH_U2F((unsigned int)(mapData[2]));
        goto LAB_00073868;
      }
      break;
    case 0xd98:
      if (query == 0xa01) {
        order = mapData[0x22];
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
        domainU2 = GH_U2F((unsigned int)(mapData[0x24]));
        goto LAB_00073868;
      }
      break;
    case 0xdb0:
      if (query == 0xa01) {
        *v = (float)((double)CONCAT44(0x43300000,mapData[0x51e]) - DOUBLE_00108d70);
        vOrder = mapData[0x51f];
LAB_0007413c:
        v[1] = (float)((double)CONCAT44(0x43300000,vOrder) - intToDoubleBias);
        return;
      }
      if (query < 0xa02) {
        if (query == 0xa00) {
          vOrderLimit = mapData[0x51f];
          dstOffset = 0;
          loopIndex2 = 0;
          if (vOrderLimit == 0) {
            return;
          }
          uOrder = mapData[0x51e];
          do {
            loopIndex = 0;
            if (uOrder != 0) {
              dstCursor = v + dstOffset;
              do {
                dstOffset = dstOffset + 4;
                controlPointIndex = loopIndex2 * uOrder + loopIndex;
                loopIndex = loopIndex + 1;
                *dstCursor = GH_U2F((unsigned int)(mapData[controlPointIndex * 4 + 0x526]));
                dstCursor[1] = GH_U2F((unsigned int)(mapData[controlPointIndex * 4 + 0x527]));
                dstCursor[2] = GH_U2F((unsigned int)(mapData[controlPointIndex * 4 + 0x528]));
                dstCursor[3] = GH_U2F((unsigned int)(mapData[controlPointIndex * 4 + 0x529]));
                uOrder = mapData[0x51e];
                dstCursor = dstCursor + 4;
              } while (loopIndex < uOrder);
              vOrderLimit = mapData[0x51f];
            }
            loopIndex2 = loopIndex2 + 1;
          } while (loopIndex2 < vOrderLimit);
          return;
        }
      }
      else if (query == 0xa02) {
        *v = GH_U2F((unsigned int)(mapData[0x520]));
        v[1] = GH_U2F((unsigned int)(mapData[0x521]));
        v[2] = GH_U2F((unsigned int)(mapData[0x522]));
        domainV2 = GH_U2F((unsigned int)(mapData[0x523]));
LAB_00074174:
        v[3] = domainV2;
        return;
      }
      break;
    case 0xdb1:
      if (query == 0xa01) {
        *v = (float)((double)CONCAT44(0x43300000,mapData[0x6b6]) - DOUBLE_00108d70);
        vOrder = mapData[0x6b7];
        goto LAB_0007413c;
      }
      if (query < 0xa02) {
        if (query == 0xa00) {
          vOrderLimit = mapData[0x6b7];
          dstOffset = 0;
          loopIndex2 = 0;
          if (vOrderLimit == 0) {
            return;
          }
          uOrder = mapData[0x6b6];
          do {
            loopIndex = 0;
            if (uOrder != 0) {
              dstCursor = v + dstOffset;
              do {
                dstOffset = dstOffset + 1;
                controlPointIndex = loopIndex2 * uOrder + loopIndex;
                loopIndex = loopIndex + 1;
                *dstCursor = GH_U2F((unsigned int)(mapData[controlPointIndex + 0x6be]));
                dstCursor = dstCursor + 1;
                uOrder = mapData[0x6b6];
              } while (loopIndex < uOrder);
              vOrderLimit = mapData[0x6b7];
            }
            loopIndex2 = loopIndex2 + 1;
          } while (loopIndex2 < vOrderLimit);
          return;
        }
      }
      else if (query == 0xa02) {
        *v = GH_U2F((unsigned int)(mapData[0x6b8]));
        v[1] = GH_U2F((unsigned int)(mapData[0x6b9]));
        v[2] = GH_U2F((unsigned int)(mapData[0x6ba]));
        domainV2 = GH_U2F((unsigned int)(mapData[0x6bb]));
        goto LAB_00074174;
      }
      break;
    case 0xdb2:
      if (query == 0xa01) {
        *v = (float)((double)CONCAT44(0x43300000,mapData[0x3ea]) - DOUBLE_00108d70);
        vOrder = mapData[0x3eb];
        goto LAB_0007413c;
      }
      if (query < 0xa02) {
        if (query == 0xa00) {
          vOrderLimit = mapData[0x3eb];
          dstOffset = 0;
          loopIndex2 = 0;
          if (vOrderLimit == 0) {
            return;
          }
          uOrder = mapData[0x3ea];
          do {
            loopIndex = 0;
            if (uOrder != 0) {
              dstCursor = v + dstOffset;
              do {
                dstOffset = dstOffset + 3;
                controlPointIndex = loopIndex2 * uOrder + loopIndex;
                loopIndex = loopIndex + 1;
                *dstCursor = GH_U2F((unsigned int)(mapData[controlPointIndex * 3 + 0x3f2]));
                dstCursor[1] = GH_U2F((unsigned int)(mapData[controlPointIndex * 3 + 0x3f3]));
                dstCursor[2] = GH_U2F((unsigned int)(mapData[controlPointIndex * 3 + 0x3f4]));
                uOrder = mapData[0x3ea];
                dstCursor = dstCursor + 3;
              } while (loopIndex < uOrder);
              vOrderLimit = mapData[0x3eb];
            }
            loopIndex2 = loopIndex2 + 1;
          } while (loopIndex2 < vOrderLimit);
          return;
        }
      }
      else if (query == 0xa02) {
        *v = GH_U2F((unsigned int)(mapData[0x3ec]));
        v[1] = GH_U2F((unsigned int)(mapData[0x3ed]));
        v[2] = GH_U2F((unsigned int)(mapData[0x3ee]));
        domainV2 = GH_U2F((unsigned int)(mapData[0x3ef]));
        goto LAB_00074174;
      }
      break;
    case 0xdb3:
      if (query == 0xa01) {
        *v = (float)((double)CONCAT44(0x43300000,mapData[0x722]) - DOUBLE_00108d70);
        vOrder = mapData[0x723];
        goto LAB_0007413c;
      }
      if (query < 0xa02) {
        if (query == 0xa00) {
          vOrderLimit = mapData[0x723];
          dstOffset = 0;
          loopIndex2 = 0;
          if (vOrderLimit == 0) {
            return;
          }
          uOrder = mapData[0x722];
          do {
            loopIndex = 0;
            if (uOrder != 0) {
              dstCursor = v + dstOffset;
              do {
                dstOffset = dstOffset + 1;
                controlPointIndex = loopIndex2 * uOrder + loopIndex;
                loopIndex = loopIndex + 1;
                *dstCursor = GH_U2F((unsigned int)(mapData[controlPointIndex + 0x72a]));
                dstCursor = dstCursor + 1;
                uOrder = mapData[0x722];
              } while (loopIndex < uOrder);
              vOrderLimit = mapData[0x723];
            }
            loopIndex2 = loopIndex2 + 1;
          } while (loopIndex2 < vOrderLimit);
          return;
        }
      }
      else if (query == 0xa02) {
        *v = GH_U2F((unsigned int)(mapData[0x724]));
        v[1] = GH_U2F((unsigned int)(mapData[0x725]));
        v[2] = GH_U2F((unsigned int)(mapData[0x726]));
        domainV2 = GH_U2F((unsigned int)(mapData[0x727]));
        goto LAB_00074174;
      }
      break;
    case 0xdb4:
      if (query == 0xa01) {
        *v = (float)((double)CONCAT44(0x43300000,mapData[0x78e]) - DOUBLE_00108d70);
        vOrder = mapData[0x78f];
        goto LAB_0007413c;
      }
      if (query < 0xa02) {
        if (query == 0xa00) {
          vOrderLimit = mapData[0x78f];
          dstOffset = 0;
          loopIndex2 = 0;
          if (vOrderLimit == 0) {
            return;
          }
          uOrder = mapData[0x78e];
          do {
            loopIndex = 0;
            if (uOrder != 0) {
              dstCursor = v + dstOffset;
              do {
                dstOffset = dstOffset + 2;
                controlPointIndex = loopIndex2 * uOrder + loopIndex;
                loopIndex = loopIndex + 1;
                *dstCursor = GH_U2F((unsigned int)(mapData[controlPointIndex * 2 + 0x796]));
                dstCursor[1] = GH_U2F((unsigned int)(mapData[controlPointIndex * 2 + 0x797]));
                uOrder = mapData[0x78e];
                dstCursor = dstCursor + 2;
              } while (loopIndex < uOrder);
              vOrderLimit = mapData[0x78f];
            }
            loopIndex2 = loopIndex2 + 1;
          } while (loopIndex2 < vOrderLimit);
          return;
        }
      }
      else if (query == 0xa02) {
        *v = GH_U2F((unsigned int)(mapData[0x790]));
        v[1] = GH_U2F((unsigned int)(mapData[0x791]));
        v[2] = GH_U2F((unsigned int)(mapData[0x792]));
        domainV2 = GH_U2F((unsigned int)(mapData[0x793]));
        goto LAB_00074174;
      }
      break;
    case 0xdb5:
      if (query == 0xa01) {
        *v = (float)((double)CONCAT44(0x43300000,mapData[0x85e]) - DOUBLE_00108d70);
        vOrder = mapData[0x85f];
        goto LAB_0007413c;
      }
      if (query < 0xa02) {
        if (query == 0xa00) {
          vOrderLimit = mapData[0x85f];
          dstOffset = 0;
          loopIndex2 = 0;
          if (vOrderLimit == 0) {
            return;
          }
          uOrder = mapData[0x85e];
          do {
            loopIndex = 0;
            if (uOrder != 0) {
              dstCursor = v + dstOffset;
              do {
                dstOffset = dstOffset + 3;
                controlPointIndex = loopIndex2 * uOrder + loopIndex;
                loopIndex = loopIndex + 1;
                *dstCursor = GH_U2F((unsigned int)(mapData[controlPointIndex * 3 + 0x866]));
                dstCursor[1] = GH_U2F((unsigned int)(mapData[controlPointIndex * 3 + 0x867]));
                dstCursor[2] = GH_U2F((unsigned int)(mapData[controlPointIndex * 3 + 0x868]));
                uOrder = mapData[0x85e];
                dstCursor = dstCursor + 3;
              } while (loopIndex < uOrder);
              vOrderLimit = mapData[0x85f];
            }
            loopIndex2 = loopIndex2 + 1;
          } while (loopIndex2 < vOrderLimit);
          return;
        }
      }
      else if (query == 0xa02) {
        *v = GH_U2F((unsigned int)(mapData[0x860]));
        v[1] = GH_U2F((unsigned int)(mapData[0x861]));
        v[2] = GH_U2F((unsigned int)(mapData[0x862]));
        domainV2 = GH_U2F((unsigned int)(mapData[0x863]));
        goto LAB_00074174;
      }
      break;
    case 0xdb6:
      if (query == 0xa01) {
        *v = (float)((double)CONCAT44(0x43300000,mapData[0x992]) - DOUBLE_00108d70);
        vOrder = mapData[0x993];
        goto LAB_0007413c;
      }
      if (query < 0xa02) {
        if (query == 0xa00) {
          vOrderLimit = mapData[0x993];
          dstOffset = 0;
          loopIndex2 = 0;
          if (vOrderLimit == 0) {
            return;
          }
          uOrder = mapData[0x992];
          do {
            loopIndex = 0;
            if (uOrder != 0) {
              dstCursor = v + dstOffset;
              do {
                dstOffset = dstOffset + 4;
                controlPointIndex = loopIndex2 * uOrder + loopIndex;
                loopIndex = loopIndex + 1;
                *dstCursor = GH_U2F((unsigned int)(mapData[controlPointIndex * 4 + 0x99a]));
                dstCursor[1] = GH_U2F((unsigned int)(mapData[controlPointIndex * 4 + 0x99b]));
                dstCursor[2] = GH_U2F((unsigned int)(mapData[controlPointIndex * 4 + 0x99c]));
                dstCursor[3] = GH_U2F((unsigned int)(mapData[controlPointIndex * 4 + 0x99d]));
                uOrder = mapData[0x992];
                dstCursor = dstCursor + 4;
              } while (loopIndex < uOrder);
              vOrderLimit = mapData[0x993];
            }
            loopIndex2 = loopIndex2 + 1;
          } while (loopIndex2 < vOrderLimit);
          return;
        }
      }
      else if (query == 0xa02) {
        *v = GH_U2F((unsigned int)(mapData[0x994]));
        v[1] = GH_U2F((unsigned int)(mapData[0x995]));
        v[2] = GH_U2F((unsigned int)(mapData[0x996]));
        domainV2 = GH_U2F((unsigned int)(mapData[0x997]));
        goto LAB_00074174;
      }
      break;
    case 0xdb7:
      if (query == 0xa01) {
        *v = (float)((double)CONCAT44(0x43300000,mapData[0x11e]) - DOUBLE_00108d70);
        vOrder = mapData[0x11f];
        goto LAB_0007413c;
      }
      if (query < 0xa02) {
        if (query == 0xa00) {
          vOrderLimit = mapData[0x11f];
          dstOffset = 0;
          loopIndex2 = 0;
          if (vOrderLimit == 0) {
            return;
          }
          uOrder = mapData[0x11e];
          do {
            loopIndex = 0;
            if (uOrder != 0) {
              dstCursor = v + dstOffset;
              do {
                dstOffset = dstOffset + 3;
                controlPointIndex = loopIndex2 * uOrder + loopIndex;
                loopIndex = loopIndex + 1;
                *dstCursor = GH_U2F((unsigned int)(mapData[controlPointIndex * 3 + 0x126]));
                dstCursor[1] = GH_U2F((unsigned int)(mapData[controlPointIndex * 3 + 0x127]));
                dstCursor[2] = GH_U2F((unsigned int)(mapData[controlPointIndex * 3 + 0x128]));
                uOrder = mapData[0x11e];
                dstCursor = dstCursor + 3;
              } while (loopIndex < uOrder);
              vOrderLimit = mapData[0x11f];
            }
            loopIndex2 = loopIndex2 + 1;
          } while (loopIndex2 < vOrderLimit);
          return;
        }
      }
      else if (query == 0xa02) {
        *v = GH_U2F((unsigned int)(mapData[0x120]));
        v[1] = GH_U2F((unsigned int)(mapData[0x121]));
        v[2] = GH_U2F((unsigned int)(mapData[0x122]));
        domainV2 = GH_U2F((unsigned int)(mapData[0x123]));
        goto LAB_00074174;
      }
      break;
    case 0xdb8:
      if (query == 0xa01) {
        *v = (float)((double)CONCAT44(0x43300000,mapData[0x252]) - DOUBLE_00108d70);
        vOrder = mapData[0x253];
        goto LAB_0007413c;
      }
      if (query < 0xa02) {
        if (query == 0xa00) {
          vOrderLimit = mapData[0x253];
          dstOffset = 0;
          loopIndex2 = 0;
          if (vOrderLimit == 0) {
            return;
          }
          uOrder = mapData[0x252];
          do {
            loopIndex = 0;
            if (uOrder != 0) {
              dstCursor = v + dstOffset;
              do {
                dstOffset = dstOffset + 4;
                controlPointIndex = loopIndex2 * uOrder + loopIndex;
                loopIndex = loopIndex + 1;
                *dstCursor = GH_U2F((unsigned int)(mapData[controlPointIndex * 4 + 0x25a]));
                dstCursor[1] = GH_U2F((unsigned int)(mapData[controlPointIndex * 4 + 0x25b]));
                dstCursor[2] = GH_U2F((unsigned int)(mapData[controlPointIndex * 4 + 0x25c]));
                dstCursor[3] = GH_U2F((unsigned int)(mapData[controlPointIndex * 4 + 0x25d]));
                uOrder = mapData[0x252];
                dstCursor = dstCursor + 4;
              } while (loopIndex < uOrder);
              vOrderLimit = mapData[0x253];
            }
            loopIndex2 = loopIndex2 + 1;
          } while (loopIndex2 < vOrderLimit);
          return;
        }
      }
      else if (query == 0xa02) {
        *v = GH_U2F((unsigned int)(mapData[0x254]));
        v[1] = GH_U2F((unsigned int)(mapData[0x255]));
        v[2] = GH_U2F((unsigned int)(mapData[0x256]));
        domainV2 = GH_U2F((unsigned int)(mapData[599]));
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
  float domainU2;
  float domainV2;
  float coefficient;
  float floatHalf;
  undefined4 glErrorCode;
  uint uOrder;
  int controlPointIndex;
  uint *mapData;
  uint order;
  uint vOrder;
  uint loopIndex2;
  float *srcCursor;
  uint vOrderLimit;
  uint *dstCursor;
  uint *srcCursor2;
  int dstOffset;
  uint loopIndex;
  
  mapData = (uint *)_gleGetMapData(glContext);
  floatHalf = FLOAT_00108e90;
  if (*(short *)(glContext + 0x4a10) < 0) {
    switch(target) {
    case 0xd90:
      if (query == 0xa01) {
        order = mapData[0x70];
LAB_00074a1c:
        *v = order;
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
            *v = (int)(GH_U2F((unsigned int)(srcCursor2[0x74])) + floatHalf);
            v[1] = (int)(GH_U2F((unsigned int)(srcCursor2[0x75])) + floatHalf);
            v[2] = (int)(GH_U2F((unsigned int)(srcCursor2[0x76])) + floatHalf);
            v[3] = (int)(GH_U2F((unsigned int)(srcCursor2[0x77])) + floatHalf);
            v = v + 4;
            srcCursor2 = srcCursor2 + 4;
          } while (loopIndex2 < mapData[0x70]);
          return;
        }
      }
      else if (query == 0xa02) {
        *v = (int)(GH_U2F((unsigned int)(mapData[0x71])) + FLOAT_00108e90);
        domainU2 = GH_U2F((unsigned int)(mapData[0x72]));
LAB_00074a48:
        v[1] = (int)(domainU2 + floatHalf);
        return;
      }
      break;
    case 0xd91:
      if (query == 0xa01) {
        order = mapData[0x9c];
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
            coefficient = *srcCursor;
            loopIndex2 = loopIndex2 + 1;
            srcCursor = srcCursor + 1;
            *v = (int)(coefficient + floatHalf);
            v = v + 1;
          } while (loopIndex2 < mapData[0x9c]);
          return;
        }
      }
      else if (query == 0xa02) {
        *v = (int)(GH_U2F((unsigned int)(mapData[0x9d])) + FLOAT_00108e90);
        domainU2 = GH_U2F((unsigned int)(mapData[0x9e]));
        goto LAB_00074a48;
      }
      break;
    case 0xd92:
      if (query == 0xa01) {
        order = mapData[0x4e];
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
            *v = (int)(GH_U2F((unsigned int)(srcCursor2[0x52])) + floatHalf);
            v[1] = (int)(GH_U2F((unsigned int)(srcCursor2[0x53])) + floatHalf);
            v[2] = (int)(GH_U2F((unsigned int)(srcCursor2[0x54])) + floatHalf);
            v = v + 3;
            srcCursor2 = srcCursor2 + 3;
          } while (loopIndex2 < mapData[0x4e]);
          return;
        }
      }
      else if (query == 0xa02) {
        *v = (int)(GH_U2F((unsigned int)(mapData[0x4f])) + FLOAT_00108e90);
        domainU2 = GH_U2F((unsigned int)(mapData[0x50]));
        goto LAB_00074a48;
      }
      break;
    case 0xd93:
      if (query == 0xa01) {
        order = mapData[0xaa];
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
            coefficient = *srcCursor;
            loopIndex2 = loopIndex2 + 1;
            srcCursor = srcCursor + 1;
            *v = (int)(coefficient + floatHalf);
            v = v + 1;
          } while (loopIndex2 < mapData[0xaa]);
          return;
        }
      }
      else if (query == 0xa02) {
        *v = (int)(GH_U2F((unsigned int)(mapData[0xab])) + FLOAT_00108e90);
        domainU2 = GH_U2F((unsigned int)(mapData[0xac]));
        goto LAB_00074a48;
      }
      break;
    case 0xd94:
      if (query == 0xa01) {
        order = mapData[0xb8];
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
            *v = (int)(GH_U2F((unsigned int)(srcCursor2[0xbc])) + floatHalf);
            v[1] = (int)(GH_U2F((unsigned int)(srcCursor2[0xbd])) + floatHalf);
            v = v + 2;
            srcCursor2 = srcCursor2 + 2;
          } while (loopIndex2 < mapData[0xb8]);
          return;
        }
      }
      else if (query == 0xa02) {
        *v = (int)(GH_U2F((unsigned int)(mapData[0xb9])) + FLOAT_00108e90);
        domainU2 = GH_U2F((unsigned int)(mapData[0xba]));
        goto LAB_00074a48;
      }
      break;
    case 0xd95:
      if (query == 0xa01) {
        order = mapData[0xd0];
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
            *v = (int)(GH_U2F((unsigned int)(srcCursor2[0xd4])) + floatHalf);
            v[1] = (int)(GH_U2F((unsigned int)(srcCursor2[0xd5])) + floatHalf);
            v[2] = (int)(GH_U2F((unsigned int)(srcCursor2[0xd6])) + floatHalf);
            v = v + 3;
            srcCursor2 = srcCursor2 + 3;
          } while (loopIndex2 < mapData[0xd0]);
          return;
        }
      }
      else if (query == 0xa02) {
        *v = (int)(GH_U2F((unsigned int)(mapData[0xd1])) + FLOAT_00108e90);
        domainU2 = GH_U2F((unsigned int)(mapData[0xd2]));
        goto LAB_00074a48;
      }
      break;
    case 0xd96:
      if (query == 0xa01) {
        order = mapData[0xf2];
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
            *v = (int)(GH_U2F((unsigned int)(srcCursor2[0xf6])) + floatHalf);
            v[1] = (int)(GH_U2F((unsigned int)(srcCursor2[0xf7])) + floatHalf);
            v[2] = (int)(GH_U2F((unsigned int)(srcCursor2[0xf8])) + floatHalf);
            v[3] = (int)(GH_U2F((unsigned int)(srcCursor2[0xf9])) + floatHalf);
            v = v + 4;
            srcCursor2 = srcCursor2 + 4;
          } while (loopIndex2 < mapData[0xf2]);
          return;
        }
      }
      else if (query == 0xa02) {
        *v = (int)(GH_U2F((unsigned int)(mapData[0xf3])) + FLOAT_00108e90);
        domainU2 = GH_U2F((unsigned int)(mapData[0xf4]));
        goto LAB_00074a48;
      }
      break;
    case 0xd97:
      if (query == 0xa01) {
        order = *mapData;
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
            *v = (int)(GH_U2F((unsigned int)(srcCursor2[4])) + floatHalf);
            v[1] = (int)(GH_U2F((unsigned int)(srcCursor2[5])) + floatHalf);
            v[2] = (int)(GH_U2F((unsigned int)(srcCursor2[6])) + floatHalf);
            v = v + 3;
            srcCursor2 = srcCursor2 + 3;
          } while (loopIndex2 < *mapData);
          return;
        }
      }
      else if (query == 0xa02) {
        *v = (int)(GH_U2F((unsigned int)(mapData[1])) + FLOAT_00108e90);
        domainU2 = GH_U2F((unsigned int)(mapData[2]));
        goto LAB_00074a48;
      }
      break;
    case 0xd98:
      if (query == 0xa01) {
        order = mapData[0x22];
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
            *v = (int)(GH_U2F((unsigned int)(srcCursor2[0x26])) + floatHalf);
            v[1] = (int)(GH_U2F((unsigned int)(srcCursor2[0x27])) + floatHalf);
            v[2] = (int)(GH_U2F((unsigned int)(srcCursor2[0x28])) + floatHalf);
            v[3] = (int)(GH_U2F((unsigned int)(srcCursor2[0x29])) + floatHalf);
            v = v + 4;
            srcCursor2 = srcCursor2 + 4;
          } while (loopIndex2 < mapData[0x22]);
          return;
        }
      }
      else if (query == 0xa02) {
        *v = (int)(GH_U2F((unsigned int)(mapData[0x23])) + FLOAT_00108e90);
        domainU2 = GH_U2F((unsigned int)(mapData[0x24]));
        goto LAB_00074a48;
      }
      break;
    case 0xdb0:
      if (query == 0xa01) {
        *v = mapData[0x51e];
        vOrder = mapData[0x51f];
LAB_000755a4:
        v[1] = vOrder;
        return;
      }
      if (query < 0xa02) {
        if (query == 0xa00) {
          vOrderLimit = mapData[0x51f];
          dstOffset = 0;
          loopIndex2 = 0;
          if (vOrderLimit == 0) {
            return;
          }
          uOrder = mapData[0x51e];
          do {
            floatHalf = FLOAT_00108e90;
            loopIndex = 0;
            if (uOrder != 0) {
              dstCursor = v + dstOffset;
              do {
                dstOffset = dstOffset + 4;
                controlPointIndex = loopIndex2 * uOrder + loopIndex;
                loopIndex = loopIndex + 1;
                *dstCursor = (int)(GH_U2F((unsigned int)(mapData[controlPointIndex * 4 + 0x526])) + floatHalf);
                dstCursor[1] = (int)(GH_U2F((unsigned int)(mapData[controlPointIndex * 4 + 0x527])) + floatHalf);
                dstCursor[2] = (int)(GH_U2F((unsigned int)(mapData[controlPointIndex * 4 + 0x528])) + floatHalf);
                dstCursor[3] = (int)(GH_U2F((unsigned int)(mapData[controlPointIndex * 4 + 0x529])) + floatHalf);
                uOrder = mapData[0x51e];
                dstCursor = dstCursor + 4;
              } while (loopIndex < uOrder);
              vOrderLimit = mapData[0x51f];
            }
            loopIndex2 = loopIndex2 + 1;
          } while (loopIndex2 < vOrderLimit);
          return;
        }
      }
      else if (query == 0xa02) {
        *v = (int)(GH_U2F((unsigned int)(mapData[0x520])) + FLOAT_00108e90);
        v[1] = (int)(GH_U2F((unsigned int)(mapData[0x521])) + floatHalf);
        v[2] = (int)(GH_U2F((unsigned int)(mapData[0x522])) + floatHalf);
        domainV2 = GH_U2F((unsigned int)(mapData[0x523]));
LAB_00075600:
        v[3] = (int)(domainV2 + floatHalf);
        return;
      }
      break;
    case 0xdb1:
      if (query == 0xa01) {
        *v = mapData[0x6b6];
        vOrder = mapData[0x6b7];
        goto LAB_000755a4;
      }
      if (query < 0xa02) {
        if (query == 0xa00) {
          vOrderLimit = mapData[0x6b7];
          dstOffset = 0;
          loopIndex2 = 0;
          if (vOrderLimit == 0) {
            return;
          }
          uOrder = mapData[0x6b6];
          do {
            floatHalf = FLOAT_00108e90;
            loopIndex = 0;
            if (uOrder != 0) {
              dstCursor = v + dstOffset;
              do {
                dstOffset = dstOffset + 1;
                controlPointIndex = loopIndex2 * uOrder + loopIndex;
                loopIndex = loopIndex + 1;
                *dstCursor = (int)(GH_U2F((unsigned int)(mapData[controlPointIndex + 0x6be])) + floatHalf);
                dstCursor = dstCursor + 1;
                uOrder = mapData[0x6b6];
              } while (loopIndex < uOrder);
              vOrderLimit = mapData[0x6b7];
            }
            loopIndex2 = loopIndex2 + 1;
          } while (loopIndex2 < vOrderLimit);
          return;
        }
      }
      else if (query == 0xa02) {
        *v = (int)(GH_U2F((unsigned int)(mapData[0x6b8])) + FLOAT_00108e90);
        v[1] = (int)(GH_U2F((unsigned int)(mapData[0x6b9])) + floatHalf);
        v[2] = (int)(GH_U2F((unsigned int)(mapData[0x6ba])) + floatHalf);
        domainV2 = GH_U2F((unsigned int)(mapData[0x6bb]));
        goto LAB_00075600;
      }
      break;
    case 0xdb2:
      if (query == 0xa01) {
        *v = mapData[0x3ea];
        vOrder = mapData[0x3eb];
        goto LAB_000755a4;
      }
      if (query < 0xa02) {
        if (query == 0xa00) {
          vOrderLimit = mapData[0x3eb];
          dstOffset = 0;
          loopIndex2 = 0;
          if (vOrderLimit == 0) {
            return;
          }
          uOrder = mapData[0x3ea];
          do {
            floatHalf = FLOAT_00108e90;
            loopIndex = 0;
            if (uOrder != 0) {
              dstCursor = v + dstOffset;
              do {
                dstOffset = dstOffset + 3;
                controlPointIndex = loopIndex2 * uOrder + loopIndex;
                loopIndex = loopIndex + 1;
                *dstCursor = (int)(GH_U2F((unsigned int)(mapData[controlPointIndex * 3 + 0x3f2])) + floatHalf);
                dstCursor[1] = (int)(GH_U2F((unsigned int)(mapData[controlPointIndex * 3 + 0x3f3])) + floatHalf);
                dstCursor[2] = (int)(GH_U2F((unsigned int)(mapData[controlPointIndex * 3 + 0x3f4])) + floatHalf);
                uOrder = mapData[0x3ea];
                dstCursor = dstCursor + 3;
              } while (loopIndex < uOrder);
              vOrderLimit = mapData[0x3eb];
            }
            loopIndex2 = loopIndex2 + 1;
          } while (loopIndex2 < vOrderLimit);
          return;
        }
      }
      else if (query == 0xa02) {
        *v = (int)(GH_U2F((unsigned int)(mapData[0x3ec])) + FLOAT_00108e90);
        v[1] = (int)(GH_U2F((unsigned int)(mapData[0x3ed])) + floatHalf);
        v[2] = (int)(GH_U2F((unsigned int)(mapData[0x3ee])) + floatHalf);
        domainV2 = GH_U2F((unsigned int)(mapData[0x3ef]));
        goto LAB_00075600;
      }
      break;
    case 0xdb3:
      if (query == 0xa01) {
        *v = mapData[0x722];
        vOrder = mapData[0x723];
        goto LAB_000755a4;
      }
      if (query < 0xa02) {
        if (query == 0xa00) {
          vOrderLimit = mapData[0x723];
          dstOffset = 0;
          loopIndex2 = 0;
          if (vOrderLimit == 0) {
            return;
          }
          uOrder = mapData[0x722];
          do {
            floatHalf = FLOAT_00108e90;
            loopIndex = 0;
            if (uOrder != 0) {
              dstCursor = v + dstOffset;
              do {
                dstOffset = dstOffset + 1;
                controlPointIndex = loopIndex2 * uOrder + loopIndex;
                loopIndex = loopIndex + 1;
                *dstCursor = (int)(GH_U2F((unsigned int)(mapData[controlPointIndex + 0x72a])) + floatHalf);
                dstCursor = dstCursor + 1;
                uOrder = mapData[0x722];
              } while (loopIndex < uOrder);
              vOrderLimit = mapData[0x723];
            }
            loopIndex2 = loopIndex2 + 1;
          } while (loopIndex2 < vOrderLimit);
          return;
        }
      }
      else if (query == 0xa02) {
        *v = (int)(GH_U2F((unsigned int)(mapData[0x724])) + FLOAT_00108e90);
        v[1] = (int)(GH_U2F((unsigned int)(mapData[0x725])) + floatHalf);
        v[2] = (int)(GH_U2F((unsigned int)(mapData[0x726])) + floatHalf);
        domainV2 = GH_U2F((unsigned int)(mapData[0x727]));
        goto LAB_00075600;
      }
      break;
    case 0xdb4:
      if (query == 0xa01) {
        *v = mapData[0x78e];
        vOrder = mapData[0x78f];
        goto LAB_000755a4;
      }
      if (query < 0xa02) {
        if (query == 0xa00) {
          vOrderLimit = mapData[0x78f];
          dstOffset = 0;
          loopIndex2 = 0;
          if (vOrderLimit == 0) {
            return;
          }
          uOrder = mapData[0x78e];
          do {
            floatHalf = FLOAT_00108e90;
            loopIndex = 0;
            if (uOrder != 0) {
              dstCursor = v + dstOffset;
              do {
                dstOffset = dstOffset + 2;
                controlPointIndex = loopIndex2 * uOrder + loopIndex;
                loopIndex = loopIndex + 1;
                *dstCursor = (int)(GH_U2F((unsigned int)(mapData[controlPointIndex * 2 + 0x796])) + floatHalf);
                dstCursor[1] = (int)(GH_U2F((unsigned int)(mapData[controlPointIndex * 2 + 0x797])) + floatHalf);
                uOrder = mapData[0x78e];
                dstCursor = dstCursor + 2;
              } while (loopIndex < uOrder);
              vOrderLimit = mapData[0x78f];
            }
            loopIndex2 = loopIndex2 + 1;
          } while (loopIndex2 < vOrderLimit);
          return;
        }
      }
      else if (query == 0xa02) {
        *v = (int)(GH_U2F((unsigned int)(mapData[0x790])) + FLOAT_00108e90);
        v[1] = (int)(GH_U2F((unsigned int)(mapData[0x791])) + floatHalf);
        v[2] = (int)(GH_U2F((unsigned int)(mapData[0x792])) + floatHalf);
        domainV2 = GH_U2F((unsigned int)(mapData[0x793]));
        goto LAB_00075600;
      }
      break;
    case 0xdb5:
      if (query == 0xa01) {
        *v = mapData[0x85e];
        vOrder = mapData[0x85f];
        goto LAB_000755a4;
      }
      if (query < 0xa02) {
        if (query == 0xa00) {
          vOrderLimit = mapData[0x85f];
          dstOffset = 0;
          loopIndex2 = 0;
          if (vOrderLimit == 0) {
            return;
          }
          uOrder = mapData[0x85e];
          do {
            floatHalf = FLOAT_00108e90;
            loopIndex = 0;
            if (uOrder != 0) {
              dstCursor = v + dstOffset;
              do {
                dstOffset = dstOffset + 3;
                controlPointIndex = loopIndex2 * uOrder + loopIndex;
                loopIndex = loopIndex + 1;
                *dstCursor = (int)(GH_U2F((unsigned int)(mapData[controlPointIndex * 3 + 0x866])) + floatHalf);
                dstCursor[1] = (int)(GH_U2F((unsigned int)(mapData[controlPointIndex * 3 + 0x867])) + floatHalf);
                dstCursor[2] = (int)(GH_U2F((unsigned int)(mapData[controlPointIndex * 3 + 0x868])) + floatHalf);
                uOrder = mapData[0x85e];
                dstCursor = dstCursor + 3;
              } while (loopIndex < uOrder);
              vOrderLimit = mapData[0x85f];
            }
            loopIndex2 = loopIndex2 + 1;
          } while (loopIndex2 < vOrderLimit);
          return;
        }
      }
      else if (query == 0xa02) {
        *v = (int)(GH_U2F((unsigned int)(mapData[0x860])) + FLOAT_00108e90);
        v[1] = (int)(GH_U2F((unsigned int)(mapData[0x861])) + floatHalf);
        v[2] = (int)(GH_U2F((unsigned int)(mapData[0x862])) + floatHalf);
        domainV2 = GH_U2F((unsigned int)(mapData[0x863]));
        goto LAB_00075600;
      }
      break;
    case 0xdb6:
      if (query == 0xa01) {
        *v = mapData[0x992];
        vOrder = mapData[0x993];
        goto LAB_000755a4;
      }
      if (query < 0xa02) {
        if (query == 0xa00) {
          vOrderLimit = mapData[0x993];
          dstOffset = 0;
          loopIndex2 = 0;
          if (vOrderLimit == 0) {
            return;
          }
          uOrder = mapData[0x992];
          do {
            floatHalf = FLOAT_00108e90;
            loopIndex = 0;
            if (uOrder != 0) {
              dstCursor = v + dstOffset;
              do {
                dstOffset = dstOffset + 4;
                controlPointIndex = loopIndex2 * uOrder + loopIndex;
                loopIndex = loopIndex + 1;
                *dstCursor = (int)(GH_U2F((unsigned int)(mapData[controlPointIndex * 4 + 0x99a])) + floatHalf);
                dstCursor[1] = (int)(GH_U2F((unsigned int)(mapData[controlPointIndex * 4 + 0x99b])) + floatHalf);
                dstCursor[2] = (int)(GH_U2F((unsigned int)(mapData[controlPointIndex * 4 + 0x99c])) + floatHalf);
                dstCursor[3] = (int)(GH_U2F((unsigned int)(mapData[controlPointIndex * 4 + 0x99d])) + floatHalf);
                uOrder = mapData[0x992];
                dstCursor = dstCursor + 4;
              } while (loopIndex < uOrder);
              vOrderLimit = mapData[0x993];
            }
            loopIndex2 = loopIndex2 + 1;
          } while (loopIndex2 < vOrderLimit);
          return;
        }
      }
      else if (query == 0xa02) {
        *v = (int)(GH_U2F((unsigned int)(mapData[0x994])) + FLOAT_00108e90);
        v[1] = (int)(GH_U2F((unsigned int)(mapData[0x995])) + floatHalf);
        v[2] = (int)(GH_U2F((unsigned int)(mapData[0x996])) + floatHalf);
        domainV2 = GH_U2F((unsigned int)(mapData[0x997]));
        goto LAB_00075600;
      }
      break;
    case 0xdb7:
      if (query == 0xa01) {
        *v = mapData[0x11e];
        vOrder = mapData[0x11f];
        goto LAB_000755a4;
      }
      if (query < 0xa02) {
        if (query == 0xa00) {
          vOrderLimit = mapData[0x11f];
          dstOffset = 0;
          loopIndex2 = 0;
          if (vOrderLimit == 0) {
            return;
          }
          uOrder = mapData[0x11e];
          do {
            floatHalf = FLOAT_00108e90;
            loopIndex = 0;
            if (uOrder != 0) {
              dstCursor = v + dstOffset;
              do {
                dstOffset = dstOffset + 3;
                controlPointIndex = loopIndex2 * uOrder + loopIndex;
                loopIndex = loopIndex + 1;
                *dstCursor = (int)(GH_U2F((unsigned int)(mapData[controlPointIndex * 3 + 0x126])) + floatHalf);
                dstCursor[1] = (int)(GH_U2F((unsigned int)(mapData[controlPointIndex * 3 + 0x127])) + floatHalf);
                dstCursor[2] = (int)(GH_U2F((unsigned int)(mapData[controlPointIndex * 3 + 0x128])) + floatHalf);
                uOrder = mapData[0x11e];
                dstCursor = dstCursor + 3;
              } while (loopIndex < uOrder);
              vOrderLimit = mapData[0x11f];
            }
            loopIndex2 = loopIndex2 + 1;
          } while (loopIndex2 < vOrderLimit);
          return;
        }
      }
      else if (query == 0xa02) {
        *v = (int)(GH_U2F((unsigned int)(mapData[0x120])) + FLOAT_00108e90);
        v[1] = (int)(GH_U2F((unsigned int)(mapData[0x121])) + floatHalf);
        v[2] = (int)(GH_U2F((unsigned int)(mapData[0x122])) + floatHalf);
        domainV2 = GH_U2F((unsigned int)(mapData[0x123]));
        goto LAB_00075600;
      }
      break;
    case 0xdb8:
      if (query == 0xa01) {
        *v = mapData[0x252];
        vOrder = mapData[0x253];
        goto LAB_000755a4;
      }
      if (query < 0xa02) {
        if (query == 0xa00) {
          vOrderLimit = mapData[0x253];
          dstOffset = 0;
          loopIndex2 = 0;
          if (vOrderLimit == 0) {
            return;
          }
          uOrder = mapData[0x252];
          do {
            floatHalf = FLOAT_00108e90;
            loopIndex = 0;
            if (uOrder != 0) {
              dstCursor = v + dstOffset;
              do {
                dstOffset = dstOffset + 4;
                controlPointIndex = loopIndex2 * uOrder + loopIndex;
                loopIndex = loopIndex + 1;
                *dstCursor = (int)(GH_U2F((unsigned int)(mapData[controlPointIndex * 4 + 0x25a])) + floatHalf);
                dstCursor[1] = (int)(GH_U2F((unsigned int)(mapData[controlPointIndex * 4 + 0x25b])) + floatHalf);
                dstCursor[2] = (int)(GH_U2F((unsigned int)(mapData[controlPointIndex * 4 + 0x25c])) + floatHalf);
                dstCursor[3] = (int)(GH_U2F((unsigned int)(mapData[controlPointIndex * 4 + 0x25d])) + floatHalf);
                uOrder = mapData[0x252];
                dstCursor = dstCursor + 4;
              } while (loopIndex < uOrder);
              vOrderLimit = mapData[0x253];
            }
            loopIndex2 = loopIndex2 + 1;
          } while (loopIndex2 < vOrderLimit);
          return;
        }
      }
      else if (query == 0xa02) {
        *v = (int)(GH_U2F((unsigned int)(mapData[0x254])) + FLOAT_00108e90);
        v[1] = (int)(GH_U2F((unsigned int)(mapData[0x255])) + floatHalf);
        v[2] = (int)(GH_U2F((unsigned int)(mapData[0x256])) + floatHalf);
        domainV2 = GH_U2F((unsigned int)(mapData[599]));
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
  double incomingStackWord_ffffffb8;
  double incomingStackWord_ffffffc0;
  double incomingStackWord_ffffffc8;
  double incomingStackWord_ffffffd0;
  
  ((void (*)())_glMapGrid1d_Exec)(glContext,*listRecord,(double)GH_U2F((unsigned int)(listRecord[1])),(double)GH_U2F((unsigned int)(listRecord[2])),forwardedFloatArg3,
                    forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8,incomingStackWord_ffffffb8,incomingStackWord_ffffffc0
                    ,incomingStackWord_ffffffc8,incomingStackWord_ffffffd0);
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
  double intToDoubleBias;
  undefined4 glErrorCode;
  
  intToDoubleBias = DOUBLE_00108d58;
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (0 < (int)un) {
      *(uint *)(0x74a4 + glContext + 4) = un;
      *(float *)(glContext + 0x74ac) = (float)u1;
      *(float *)(glContext + 0x74b0) = (float)u2;
      *(float *)(glContext + 0x74b4) =
           (u2 - u1) /
           (float)((double)CONCAT44(0x43300000,un ^ 0x80000000) - intToDoubleBias);
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
  double incomingFpr3;
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  
  ((int (*)())_glMapGrid1f_Comp)(glContext,un,u1,u2);
  ((void (*)())_glMapGrid1f_Exec)(glContext,un,u1,u2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,
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
  double intToDoubleBias;
  undefined4 glErrorCode;
  
  intToDoubleBias = DOUBLE_00108d58;
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (0 < (int)un) {
      *(uint *)(0x74a4 + glContext + 4) = un;
      *(float *)(glContext + 0x74ac) = (float)u1;
      *(float *)(glContext + 0x74b0) = (float)u2;
      *(float *)(glContext + 0x74b4) =
           (float)((u2 - u1) /
                  ((double)CONCAT44(0x43300000,un ^ 0x80000000) - intToDoubleBias));
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
  double incomingFpr3;
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  
  ((int (*)())_glMapGrid1d_Comp)(glContext,un,u1,u2);
  ((void (*)())_glMapGrid1d_Exec)(glContext,un,u1,u2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,
                    (double)CONCAT44(in_LR,(*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0xc))),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),
                    (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)));
  return;
}

/* _glMapGrid2_ListExec @ 0x75a10 (60 bytes) */
undefined4 _glMapGrid2_ListExec(undefined4 glContext,undefined4 *listRecord,double unusedFloatArg1,double unusedFloatArg2,double unusedFloatArg3,double unusedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  undefined4 incomingR5;
  undefined4 incomingR6;
  undefined4 incomingR7;
  undefined4 incomingR8;
  double incomingStackWord_ffffffa8;
  double incomingStackWord_ffffffb0;
  double incomingStackWord_ffffffb8;
  double incomingStackWord_ffffffc0;
  double incomingStackWord_ffffffc8;
  
  ((void (*)())_glMapGrid2d_Exec)(glContext,*listRecord,incomingR5,incomingR6,incomingR7,incomingR8,listRecord[4],(double)GH_U2F((unsigned int)(listRecord[1])),
                    (double)GH_U2F((unsigned int)(listRecord[2])),(double)GH_U2F((unsigned int)(listRecord[5])),(double)GH_U2F((unsigned int)(listRecord[6])),
                    forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8,incomingStackWord_ffffffa8,incomingStackWord_ffffffb0,
                    incomingStackWord_ffffffb8,incomingStackWord_ffffffc0,incomingStackWord_ffffffc8);
  return 0x20;
}

/* _glMapGrid2f_Comp @ 0x75a4c (268 bytes) */
void _glMapGrid2f_Comp(int glContext,uint un,undefined4 u1Shadow,undefined4 u2Shadow,uint vn,float u1,float u2,float v1,float v2)
{
  double intToDoubleBias;
  undefined4 glErrorCode;
  uint *listRecord;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    if ((0 < (int)un) && (0 < (int)vn)) {
      listRecord = (uint *)_gleAddListItem(glContext,PTR__glMapGrid2_ListExec_001101cc,0x20);
      if (listRecord != (uint *)0x0) {
        *listRecord = un;
        listRecord[1] = (uint)GH_F2U((float)u1);
        listRecord[2] = (uint)GH_F2U((float)u2);
        intToDoubleBias = DOUBLE_00108d58;
        listRecord[4] = vn;
        listRecord[5] = (uint)GH_F2U((float)v1);
        listRecord[6] = (uint)GH_F2U((float)v2);
        listRecord[3] = (uint)GH_F2U((float)((u2 - u1) /
                          (float)((double)CONCAT44(0x43300000,un ^ 0x80000000) - intToDoubleBias)));
        listRecord[7] = (uint)GH_F2U((float)((v2 - v1) /
                          (float)((double)CONCAT44(0x43300000,vn ^ 0x80000000) - intToDoubleBias)));
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
  double intToDoubleBias;
  undefined4 glErrorCode;
  double unAsDouble;
  
  intToDoubleBias = DOUBLE_00108d58;
  if (*(short *)(glContext + 0x4a10) < 0) {
    if ((0 < (int)un) && (0 < (int)vn)) {
      unAsDouble = (double)CONCAT44(0x43300000,un ^ 0x80000000) - DOUBLE_00108d58;
      *(uint *)(glContext + 0x74b8) = un;
      *(float *)(glContext + 0x74bc) = (float)u1;
      *(float *)(glContext + 0x74c0) = (float)u2;
      *(uint *)(glContext + 0x74c8) = vn;
      *(float *)(glContext + 0x74cc) = (float)v1;
      *(float *)(glContext + 0x74d0) = (float)v2;
      *(float *)(glContext + 0x74c4) = (u2 - u1) / (float)unAsDouble;
      *(float *)(glContext + 0x74d4) =
           (v2 - v1) /
           (float)((double)CONCAT44(0x43300000,vn ^ 0x80000000) - intToDoubleBias);
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
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  
  ((void (*)())_glMapGrid2f_Comp)(glContext,un,u1Shadow,u2Shadow,vn,u1,u2,v1,v2);
  ((void (*)())_glMapGrid2f_Exec)(glContext,un,u1Shadow,u2Shadow,vn,u1,u2,v1,v2,
                    incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x8)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)));
  return;
}

/* _glMapGrid2d_Comp @ 0x75c8c (284 bytes) */
void _glMapGrid2d_Comp(int glContext,uint un,undefined4 u1ShadowHi,undefined4 u1ShadowLo,undefined4 u2ShadowHi,undefined4 u2ShadowLo,uint vn,double u1,double u2,double v1,double v2)
{
  double intToDoubleBias;
  undefined4 glErrorCode;
  uint *listRecord;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    if ((0 < (int)un) && (0 < (int)vn)) {
      listRecord = (uint *)_gleAddListItem(glContext,PTR__glMapGrid2_ListExec_001101cc,0x20);
      if (listRecord != (uint *)0x0) {
        *listRecord = un;
        listRecord[1] = (uint)GH_F2U((float)u1);
        listRecord[2] = (uint)GH_F2U((float)u2);
        intToDoubleBias = DOUBLE_00108d58;
        listRecord[5] = (uint)GH_F2U((float)v1);
        listRecord[6] = (uint)GH_F2U((float)v2);
        listRecord[4] = vn;
        listRecord[3] = (uint)GH_F2U((float)((u2 - u1) /
                                 ((double)CONCAT44(0x43300000,un ^ 0x80000000) - intToDoubleBias)));
        listRecord[7] = (uint)GH_F2U((float)((v2 - v1) /
                                 ((double)CONCAT44(0x43300000,vn ^ 0x80000000) - intToDoubleBias)));
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
  double intToDoubleBias;
  undefined4 glErrorCode;
  double unAsDouble;
  
  intToDoubleBias = DOUBLE_00108d58;
  if (*(short *)(glContext + 0x4a10) < 0) {
    if ((0 < (int)un) && (0 < (int)vn)) {
      unAsDouble = (double)CONCAT44(0x43300000,un ^ 0x80000000) - DOUBLE_00108d58;
      *(uint *)(glContext + 0x74b8) = un;
      *(float *)(glContext + 0x74bc) = (float)u1;
      *(uint *)(glContext + 0x74c8) = vn;
      *(float *)(glContext + 0x74cc) = (float)v1;
      *(float *)(glContext + 0x74c4) = (float)((u2 - u1) / unAsDouble);
      *(float *)(glContext + 0x74d4) =
           (float)((v2 - v1) /
                  ((double)CONCAT44(0x43300000,vn ^ 0x80000000) - intToDoubleBias));
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
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  
  ((void (*)())_glMapGrid2d_Comp)(glContext,un,u1ShadowHi,u1ShadowLo,u2ShadowHi,u2ShadowLo,vn,u1,u2,
                    v1,v2);
  ((void (*)())_glMapGrid2d_Exec)(glContext,un,u1ShadowHi,u1ShadowLo,u2ShadowHi,u2ShadowLo,vn,u1,u2,
                    v1,v2,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x8)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),
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
  double incomingFpr2;
  double incomingFpr3;
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  
  ((undefined4 * (*)())_glMaterialf_Comp)(glContext,face,pname,param);
  ((void (*)())_glMaterialf_Exec)(glContext,face,pname,param,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8);
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
  double forwardedFloatArg1;
  double incomingFpr2;
  double incomingFpr3;
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  
  ((int (*)())_glMateriali_Comp)(glContext,face,pname,param);
  ((void (*)())_glMateriali_Exec)(glContext,face,pname,param,forwardedFloatArg1,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,
                    incomingFpr8);
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
  uint firstFaceIndex;
  int faceMaterialEntry;
  uint lastFaceIndex;
  double specularIndexAsDouble;
  double ambientIndexAsDouble;
  double diffuseIndexAsDouble;
  float materialRed;
  float materialGreen;
  float materialBlue;
  float materialAlpha;
  undefined4 intToDoubleHigh;
  uint intToDoubleLow;
  
  if (((*(char *)(glContext + 0x7580) != '\0') && (-1 < *(short *)(glContext + 0x4a10))) &&
     (*(char *)(glContext + 0x4664) == '\0')) {
    ((undefined4 (*)())_gleForceToSoftwareTCL)(glContext,forwardedFloatArg1,forwardedFloatArg2,forwardedFloatArg3,forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
  }
  if (pname == (undefined *)0x1600) {
    intToDoubleHigh = 0x43300000;
    intToDoubleLow = params[3] ^ 0x80000000;
    materialRed = (float)((double)CONCAT44(0x43300000,*params ^ 0x80000000) - DOUBLE_00108d58) *
               FLOAT_00108e68 + FLOAT_00108e6c;
    materialGreen = (float)((double)CONCAT44(0x43300000,params[1] ^ 0x80000000) - DOUBLE_00108d58) *
               FLOAT_00108e68 + FLOAT_00108e6c;
    materialAlpha = (float)((double)CONCAT44(0x43300000,intToDoubleLow) - DOUBLE_00108d58) * FLOAT_00108e68 +
               FLOAT_00108e6c;
    materialBlue = (float)((double)CONCAT44(0x43300000,params[2] ^ 0x80000000) - DOUBLE_00108d58) *
               FLOAT_00108e68 + FLOAT_00108e6c;
    if (face == 0x405) {
      _gleLightMaterialRGBAChange_B_E(glContext,&materialRed);
      goto LAB_00076dd8;
    }
    if (face < 0x406) {
      if (face == 0x404) {
        _gleLightMaterialRGBAChange_F_E(glContext,&materialRed);
        goto LAB_00076dd8;
      }
    }
    else if (face == 0x408) {
      _gleLightMaterialRGBAChange_FB_E(glContext,&materialRed);
      goto LAB_00076dd8;
    }
  }
  else if (pname < (undefined *)0x1601) {
    if (pname == ((unsigned char *)0x00001201)) {
      intToDoubleHigh = 0x43300000;
      intToDoubleLow = params[3] ^ 0x80000000;
      materialRed = (float)((double)CONCAT44(0x43300000,*params ^ 0x80000000) - DOUBLE_00108d58) *
                 FLOAT_00108e68 + FLOAT_00108e6c;
      materialGreen = (float)((double)CONCAT44(0x43300000,params[1] ^ 0x80000000) - DOUBLE_00108d58) *
                 FLOAT_00108e68 + FLOAT_00108e6c;
      materialAlpha = (float)((double)CONCAT44(0x43300000,intToDoubleLow) - DOUBLE_00108d58) * FLOAT_00108e68
                 + FLOAT_00108e6c;
      materialBlue = (float)((double)CONCAT44(0x43300000,params[2] ^ 0x80000000) - DOUBLE_00108d58) *
                 FLOAT_00108e68 + FLOAT_00108e6c;
      if (face == 0x405) {
        _gleLightMaterialRGBAChange_B_D(glContext,&materialRed);
        goto LAB_00076dd8;
      }
      if (face < 0x406) {
        if (face == 0x404) {
          _gleLightMaterialRGBAChange_F_D(glContext,&materialRed);
          goto LAB_00076dd8;
        }
      }
      else if (face == 0x408) {
        _gleLightMaterialRGBAChange_FB_D(glContext,&materialRed);
        goto LAB_00076dd8;
      }
    }
    else if (((unsigned char *)0x00001201) < pname) {
      if (pname == ((unsigned char *)0x00001202)) {
        intToDoubleHigh = 0x43300000;
        intToDoubleLow = params[3] ^ 0x80000000;
        materialRed = (float)((double)CONCAT44(0x43300000,*params ^ 0x80000000) - DOUBLE_00108d58) *
                   FLOAT_00108e68 + FLOAT_00108e6c;
        materialGreen = (float)((double)CONCAT44(0x43300000,params[1] ^ 0x80000000) - DOUBLE_00108d58) *
                   FLOAT_00108e68 + FLOAT_00108e6c;
        materialAlpha = (float)((double)CONCAT44(0x43300000,intToDoubleLow) - DOUBLE_00108d58) *
                   FLOAT_00108e68 + FLOAT_00108e6c;
        materialBlue = (float)((double)CONCAT44(0x43300000,params[2] ^ 0x80000000) - DOUBLE_00108d58) *
                   FLOAT_00108e68 + FLOAT_00108e6c;
        if (face == 0x405) {
          _gleLightMaterialRGBAChange_B_S(glContext,&materialRed);
          goto LAB_00076dd8;
        }
        if (face < 0x406) {
          if (face == 0x404) {
            _gleLightMaterialRGBAChange_F_S(glContext,&materialRed);
            goto LAB_00076dd8;
          }
        }
        else if (face == 0x408) {
          _gleLightMaterialRGBAChange_FB_S(glContext,&materialRed);
          goto LAB_00076dd8;
        }
      }
    }
    else if (pname == ((unsigned char *)0x00001200)) {
      intToDoubleHigh = 0x43300000;
      intToDoubleLow = params[3] ^ 0x80000000;
      materialRed = (float)((double)CONCAT44(0x43300000,*params ^ 0x80000000) - DOUBLE_00108d58) *
                 FLOAT_00108e68 + FLOAT_00108e6c;
      materialGreen = (float)((double)CONCAT44(0x43300000,params[1] ^ 0x80000000) - DOUBLE_00108d58) *
                 FLOAT_00108e68 + FLOAT_00108e6c;
      materialAlpha = (float)((double)CONCAT44(0x43300000,intToDoubleLow) - DOUBLE_00108d58) * FLOAT_00108e68
                 + FLOAT_00108e6c;
      materialBlue = (float)((double)CONCAT44(0x43300000,params[2] ^ 0x80000000) - DOUBLE_00108d58) *
                 FLOAT_00108e68 + FLOAT_00108e6c;
      if (face == 0x405) {
        _gleLightMaterialRGBAChange_B_A(glContext,&materialRed);
        goto LAB_00076dd8;
      }
      if (face < 0x406) {
        if (face == 0x404) {
          _gleLightMaterialRGBAChange_F_A(glContext,&materialRed);
          goto LAB_00076dd8;
        }
      }
      else if (face == 0x408) {
        _gleLightMaterialRGBAChange_FB_A(glContext,&materialRed);
        goto LAB_00076dd8;
      }
    }
  }
  else if (pname == (undefined *)0x1602) {
    intToDoubleHigh = 0x43300000;
    intToDoubleLow = params[3] ^ 0x80000000;
    materialRed = (float)((double)CONCAT44(0x43300000,*params ^ 0x80000000) - DOUBLE_00108d58) *
               FLOAT_00108e68 + FLOAT_00108e6c;
    materialGreen = (float)((double)CONCAT44(0x43300000,params[1] ^ 0x80000000) - DOUBLE_00108d58) *
               FLOAT_00108e68 + FLOAT_00108e6c;
    materialAlpha = (float)((double)CONCAT44(0x43300000,intToDoubleLow) - DOUBLE_00108d58) * FLOAT_00108e68 +
               FLOAT_00108e6c;
    materialBlue = (float)((double)CONCAT44(0x43300000,params[2] ^ 0x80000000) - DOUBLE_00108d58) *
               FLOAT_00108e68 + FLOAT_00108e6c;
    if (face == 0x405) {
      _gleLightMaterialRGBAChange_B_AD(glContext,&materialRed);
      goto LAB_00076dd8;
    }
    if (face < 0x406) {
      if (face == 0x404) {
        _gleLightMaterialRGBAChange_F_AD(glContext,&materialRed);
        goto LAB_00076dd8;
      }
    }
    else if (face == 0x408) {
      _gleLightMaterialRGBAChange_FB_AD(glContext,&materialRed);
      goto LAB_00076dd8;
    }
  }
  else if (pname < (undefined *)0x1602) {
    intToDoubleLow = *params;
    if (((int)intToDoubleLow < 0) || (*(int *)(*(int *)(glContext + 0x468c) + 0xa0) < (int)intToDoubleLow)) {
      if (*(int *)(glContext + 0x7574) != 0) {
        return;
      }
      glErrorCode = 0x501;
      goto LAB_00076dd0;
    }
    if (face == 0x405) {
      intToDoubleLow = intToDoubleLow ^ 0x80000000;
      intToDoubleHigh = 0x43300000;
      ((void (*)())_gleLightMaterialShineChange_B)(glContext,(double)(float)((double)CONCAT44(0x43300000,intToDoubleLow) - DOUBLE_00108d58));
      goto LAB_00076dd8;
    }
    if (face < 0x406) {
      if (face == 0x404) {
        intToDoubleLow = intToDoubleLow ^ 0x80000000;
        intToDoubleHigh = 0x43300000;
        ((void (*)())_gleLightMaterialShineChange_F)(glContext,(double)(float)((double)CONCAT44(0x43300000,intToDoubleLow) - DOUBLE_00108d58)
                  );
        goto LAB_00076dd8;
      }
    }
    else if (face == 0x408) {
      intToDoubleLow = intToDoubleLow ^ 0x80000000;
      intToDoubleHigh = 0x43300000;
      ((void (*)())_gleLightMaterialShineChange_FB)(glContext,(double)(float)((double)CONCAT44(0x43300000,intToDoubleLow) - DOUBLE_00108d58));
      goto LAB_00076dd8;
    }
  }
  else if (pname == (undefined *)0x1603) {
    intToDoubleHigh = 0x43300000;
    intToDoubleLow = params[2] * 0x101 ^ 0x80000000;
    ambientIndexAsDouble = (double)CONCAT44(0x43300000,*params * 0x101 ^ 0x80000000) - DOUBLE_00108d58;
    specularIndexAsDouble = (double)CONCAT44(0x43300000,intToDoubleLow) - DOUBLE_00108d58;
    diffuseIndexAsDouble = (double)CONCAT44(0x43300000,params[1] * 0x101 ^ 0x80000000) - DOUBLE_00108d58;
    if (face == 0x405) {
      lastFaceIndex = 1;
      firstFaceIndex = 1;
LAB_00076d88:
      if (firstFaceIndex <= lastFaceIndex) {
        remaining = (lastFaceIndex + 1) - firstFaceIndex;
        faceMaterialEntry = firstFaceIndex * 0x10 + glContext;
        do {
          *(float *)(faceMaterialEntry + 0x2f0) = (float)ambientIndexAsDouble;
          *(float *)(faceMaterialEntry + 0x2f4) = (float)diffuseIndexAsDouble;
          *(float *)(faceMaterialEntry + 0x2f8) = (float)specularIndexAsDouble;
          faceMaterialEntry = faceMaterialEntry + 0x10;
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
        lastFaceIndex = 0;
        firstFaceIndex = 0;
        goto LAB_00076d88;
      }
    }
    else if (face == 0x408) {
      firstFaceIndex = 0;
      lastFaceIndex = 1;
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
  double incomingFpr1;
  double incomingFpr2;
  double incomingFpr3;
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  
  ((int (*)())_glMaterialiv_Comp)(glContext,face,pname,params);
  ((void (*)())_glMaterialiv_Exec)(glContext,face,pname,params,incomingFpr1,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,
                     incomingFpr8);
  return;
}

/* _glGetMaterialfv_Exec @ 0x76e64 (584 bytes) */
void _glGetMaterialfv_Exec(glContext, face, pname, params)
  int glContext;
  int face;
  undefined *pname;
  float *params;
{
  float materialFourthComponent;
  double channelScale;
  undefined4 glErrorCode;
  int faceIndexThenMaterialSlotBase;
  
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
  channelScale = DOUBLE_00108d98;
  if (face == 0x404) {
    faceIndexThenMaterialSlotBase = 0;
LAB_00076ef4:
    if (pname == ((unsigned char *)0x00001202)) {
      faceIndexThenMaterialSlotBase = faceIndexThenMaterialSlotBase * 4 + glContext;
      *params = *(float *)(*(int *)(faceIndexThenMaterialSlotBase + 0x4dd0) + 0x20);
      params[1] = *(float *)(*(int *)(faceIndexThenMaterialSlotBase + 0x4dd0) + 0x24);
      params[2] = *(float *)(*(int *)(faceIndexThenMaterialSlotBase + 0x4dd0) + 0x28);
      materialFourthComponent = *(float *)(*(int *)(faceIndexThenMaterialSlotBase + 0x4dd0) + 0x2c);
      goto LAB_0007701c;
    }
    if (((unsigned char *)0x00001202) < pname) {
      if (pname == (undefined *)0x1601) {
        *params = *(float *)(*(int *)(faceIndexThenMaterialSlotBase * 4 + glContext + 0x4dd0) + 0x40);
        return;
      }
      if (pname < (undefined *)0x1602) {
        if (pname == (undefined *)0x1600) {
          faceIndexThenMaterialSlotBase = faceIndexThenMaterialSlotBase * 4 + glContext;
          *params = *(float *)(*(int *)(faceIndexThenMaterialSlotBase + 0x4dd0) + 0x30);
          params[1] = *(float *)(*(int *)(faceIndexThenMaterialSlotBase + 0x4dd0) + 0x34);
          params[2] = *(float *)(*(int *)(faceIndexThenMaterialSlotBase + 0x4dd0) + 0x38);
          materialFourthComponent = *(float *)(*(int *)(faceIndexThenMaterialSlotBase + 0x4dd0) + 0x3c);
          goto LAB_0007701c;
        }
      }
      else if (pname == (undefined *)0x1603) {
        faceIndexThenMaterialSlotBase = faceIndexThenMaterialSlotBase * 0x10 + glContext;
        *params = (float)((double)*(float *)(faceIndexThenMaterialSlotBase + 0x2f0) * DOUBLE_00108d98);
        params[1] = (float)((double)*(float *)(faceIndexThenMaterialSlotBase + 0x2f4) * channelScale);
        params[2] = (float)((double)*(float *)(faceIndexThenMaterialSlotBase + 0x2f8) * channelScale);
        return;
      }
    }
    else {
      if (pname == ((unsigned char *)0x00001200)) {
        faceIndexThenMaterialSlotBase = faceIndexThenMaterialSlotBase * 4 + glContext;
        *params = **(float **)(faceIndexThenMaterialSlotBase + 0x4dd0);
        params[1] = *(float *)(*(int *)(faceIndexThenMaterialSlotBase + 0x4dd0) + 4);
        params[2] = *(float *)(*(int *)(faceIndexThenMaterialSlotBase + 0x4dd0) + 8);
        materialFourthComponent = *(float *)(*(int *)(faceIndexThenMaterialSlotBase + 0x4dd0) + 0xc);
LAB_0007701c:
        params[3] = materialFourthComponent;
        return;
      }
      if (pname == ((unsigned char *)0x00001201)) {
        faceIndexThenMaterialSlotBase = faceIndexThenMaterialSlotBase * 4 + glContext;
        *params = *(float *)(*(int *)(faceIndexThenMaterialSlotBase + 0x4dd0) + 0x10);
        params[1] = *(float *)(*(int *)(faceIndexThenMaterialSlotBase + 0x4dd0) + 0x14);
        params[2] = *(float *)(*(int *)(faceIndexThenMaterialSlotBase + 0x4dd0) + 0x18);
        materialFourthComponent = *(float *)(*(int *)(faceIndexThenMaterialSlotBase + 0x4dd0) + 0x1c);
        goto LAB_0007701c;
      }
    }
  }
  else if (face == 0x405) {
    faceIndexThenMaterialSlotBase = 1;
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
  double channelScale;
  float floatHalf;
  float float2147483520;
  undefined4 glErrorCode;
  int iVar6;
  
  float2147483520 = FLOAT_00108e94;
  floatHalf = FLOAT_00108e90;
  channelScale = DOUBLE_00108d98;
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
      params[1] = (int)(*(float *)(*(int *)(iVar6 + 0x4dd0) + 0x24) * float2147483520 - floatHalf);
      params[2] = (int)(*(float *)(*(int *)(iVar6 + 0x4dd0) + 0x28) * float2147483520 - floatHalf);
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
          params[1] = (int)(*(float *)(*(int *)(iVar6 + 0x4dd0) + 0x34) * float2147483520 - floatHalf);
          params[2] = (int)(*(float *)(*(int *)(iVar6 + 0x4dd0) + 0x38) * float2147483520 - floatHalf);
          fVar1 = *(float *)(*(int *)(iVar6 + 0x4dd0) + 0x3c);
          goto LAB_00077254;
        }
      }
      else if (pname == (undefined *)0x1603) {
        iVar6 = iVar6 * 0x10 + glContext;
        *params = (int)((double)*(float *)(iVar6 + 0x2f0) * DOUBLE_00108d98);
        params[1] = (int)((double)*(float *)(iVar6 + 0x2f4) * channelScale);
        params[2] = (int)((double)*(float *)(iVar6 + 0x2f8) * channelScale);
        return;
      }
    }
    else {
      if (pname == ((unsigned char *)0x00001200)) {
        iVar6 = iVar6 * 4 + glContext;
        *params = (int)(**(float **)(iVar6 + 0x4dd0) * FLOAT_00108e94 - FLOAT_00108e90);
        params[1] = (int)(*(float *)(*(int *)(iVar6 + 0x4dd0) + 4) * float2147483520 - floatHalf);
        params[2] = (int)(*(float *)(*(int *)(iVar6 + 0x4dd0) + 8) * float2147483520 - floatHalf);
        fVar1 = *(float *)(*(int *)(iVar6 + 0x4dd0) + 0xc);
LAB_00077254:
        params[3] = (int)(fVar1 * float2147483520 - floatHalf);
        return;
      }
      if (pname == ((unsigned char *)0x00001201)) {
        iVar6 = iVar6 * 4 + glContext;
        *params = (int)(*(float *)(*(int *)(iVar6 + 0x4dd0) + 0x10) * FLOAT_00108e94 -
                        FLOAT_00108e90);
        params[1] = (int)(*(float *)(*(int *)(iVar6 + 0x4dd0) + 0x14) * float2147483520 - floatHalf);
        params[2] = (int)(*(float *)(*(int *)(iVar6 + 0x4dd0) + 0x18) * float2147483520 - floatHalf);
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
  int byteOffset;
  int listRecord;
  int remaining;
  
  listRecord = _gleAddListItem(glContext,PTR__glLoadMatrixd_ListExec_00110208,0x80);
  if (listRecord != 0) {
    byteOffset = 0;
    remaining = 0x10;
    do {
      *(undefined8 *)(byteOffset + listRecord) = *(undefined8 *)(byteOffset + m);
      byteOffset = byteOffset + 8;
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
  int byteOffset;
  int listRecord;
  int remaining;
  
  listRecord = _gleAddListItem(glContext,PTR__glLoadMatrixf_ListExec_00110204,0x40);
  if (listRecord != 0) {
    byteOffset = 0;
    remaining = 0x10;
    do {
      *(undefined4 *)(byteOffset + listRecord) = *(undefined4 *)(byteOffset + m);
      byteOffset = byteOffset + 4;
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
  int byteOffset;
  int listRecord;
  int remaining;
  
  listRecord = _gleAddListItem(glContext,PTR__glLoadTransposeMatrixd_ListExec_00110200,0x80);
  if (listRecord != 0) {
    byteOffset = 0;
    remaining = 0x10;
    do {
      *(undefined8 *)(byteOffset + listRecord) = *(undefined8 *)(byteOffset + m);
      byteOffset = byteOffset + 8;
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

