#include "decls.h"

/* _glSecondaryColor3f_Exec @ 0x5e9bc (16 bytes) */
void _glSecondaryColor3f_Exec(int glContext,float red,float green,float blue)
{
  *(float *)(glContext + 0x2c8) = (float)blue;
  *(float *)(glContext + 0x2c0) = (float)red;
  *(float *)(glContext + 0x2c4) = (float)green;
  return;
}

/* _glSecondaryColor3f_Comp @ 0x5e9cc (116 bytes) */
float * _glSecondaryColor3f_Comp(undefined4 glContext,float red,float green,float blue)
{
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glSecondaryColor3_ListExec_00110064,0xc);
  if (listRecord != (float *)0x0) {
    listRecord[2] = (float)blue;
    *listRecord = (float)red;
    listRecord[1] = (float)green;
  }
  return listRecord;
}

/* _glSecondaryColor3f_CompExec @ 0x5ea40 (96 bytes) */
void _glSecondaryColor3f_CompExec(undefined4 glContext,float red,float green,float blue)
{
  ((float * (*)())_glSecondaryColor3f_Comp)(glContext,red,green,blue);
  ((void (*)())_glSecondaryColor3f_Exec)(glContext,red,green,blue);
  return;
}

/* _glSecondaryColor3fv_Exec @ 0x5eaa0 (28 bytes) */
double _glSecondaryColor3fv_Exec(glContext, v)
  int glContext;
  undefined4 *v;
{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = *v;
  uVar2 = v[1];
  *(undefined4 *)(glContext + 0x2c8) = v[2];
  *(undefined4 *)(glContext + 0x2c0) = uVar1;
  *(undefined4 *)(glContext + 0x2c4) = uVar2;
  return;
}

/* _glSecondaryColor3fv_Comp @ 0x5eabc (96 bytes) */
int _glSecondaryColor3fv_Comp(glContext, v)
  undefined4 glContext;
  undefined4 *v;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glSecondaryColor3_ListExec_00110064,0xc);
  if (listRecord != (undefined4 *)0x0) {
    *listRecord = *v;
    listRecord[1] = v[1];
    listRecord[2] = v[2];
  }
  return listRecord;
}

/* _glSecondaryColor3fv_CompExec @ 0x5eb1c (56 bytes) */
void _glSecondaryColor3fv_CompExec(glContext, v)
  undefined4 glContext;
  undefined4 v;
{
  ((int (*)())_glSecondaryColor3fv_Comp)(glContext,v);
  ((double (*)())_glSecondaryColor3fv_Exec)(glContext,v);
  return;
}

/* _glSecondaryColor3d_Exec @ 0x5eb54 (28 bytes) */
void _glSecondaryColor3d_Exec(int glContext,double red,double green,double blue)
{
  *(float *)(glContext + 0x2c0) = (float)red;
  *(float *)(glContext + 0x2c4) = (float)green;
  *(float *)(glContext + 0x2c8) = (float)blue;
  return;
}

/* _glSecondaryColor3d_Comp @ 0x5eb70 (128 bytes) */
float * _glSecondaryColor3d_Comp(undefined4 glContext,double red,double green,double blue)
{
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glSecondaryColor3_ListExec_00110064,0xc);
  if (listRecord != (float *)0x0) {
    *listRecord = (float)red;
    listRecord[1] = (float)green;
    listRecord[2] = (float)blue;
  }
  return listRecord;
}

/* _glSecondaryColor3d_CompExec @ 0x5ebf0 (96 bytes) */
void _glSecondaryColor3d_CompExec(undefined4 glContext,double red,double green,double blue)
{
  ((float * (*)())_glSecondaryColor3d_Comp)(glContext,red,green,blue);
  ((void (*)())_glSecondaryColor3d_Exec)(glContext,red,green,blue);
  return;
}

/* _glSecondaryColor3dv_Exec @ 0x5ec50 (40 bytes) */
double _glSecondaryColor3dv_Exec(glContext, v)
  int glContext;
  double *v;
{
  double dVar1;
  double dVar2;
  
  dVar1 = *v;
  dVar2 = v[1];
  *(float *)(glContext + 0x2c8) = (float)v[2];
  *(float *)(glContext + 0x2c0) = (float)dVar1;
  *(float *)(glContext + 0x2c4) = (float)dVar2;
  return;
}

/* _glSecondaryColor3dv_Comp @ 0x5ec78 (108 bytes) */
int _glSecondaryColor3dv_Comp(glContext, v)
  undefined4 glContext;
  double *v;
{
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glSecondaryColor3_ListExec_00110064,0xc);
  if (listRecord != (float *)0x0) {
    *listRecord = (float)*v;
    listRecord[1] = (float)v[1];
    listRecord[2] = (float)v[2];
  }
  return listRecord;
}

/* _glSecondaryColor3dv_CompExec @ 0x5ece4 (56 bytes) */
void _glSecondaryColor3dv_CompExec(glContext, v)
  undefined4 glContext;
  undefined4 v;
{
  ((int (*)())_glSecondaryColor3dv_Comp)(glContext,v);
  ((double (*)())_glSecondaryColor3dv_Exec)(glContext,v);
  return;
}

/* _glSecondaryColor3ub_Exec @ 0x5ed1c (120 bytes) */
void _glSecondaryColor3ub_Exec(glContext, red, green, blue)
  int glContext;
  uint red;
  uint green;
  uint blue;
{
  float fVar1;
  float fVar2;
  
  fVar1 = (GH_U2F((unsigned int)((blue | 0x4b000000))) - 8388608.0) * FLOAT_00108e78;
  fVar2 = (GH_U2F((unsigned int)((green | 0x4b000000))) - 8388608.0) * FLOAT_00108e78;
  *(float *)(glContext + 0x2c0) = (GH_U2F((unsigned int)((red | 0x4b000000))) - 8388608.0) * FLOAT_00108e78;
  *(float *)(glContext + 0x2c8) = fVar1;
  *(float *)(glContext + 0x2c4) = fVar2;
  return;
}

/* _glSecondaryColor3ub_Comp @ 0x5ed94 (192 bytes) */
int _glSecondaryColor3ub_Comp(glContext, red, green, blue)
  undefined4 glContext;
  uint red;
  uint green;
  uint blue;
{
  float fVar1;
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glSecondaryColor3_ListExec_00110064,0xc);
  fVar1 = FLOAT_00108e78;
  if (listRecord != (float *)0x0) {
    *listRecord = (GH_U2F((unsigned int)((red | 0x4b000000))) - 8388608.0) * FLOAT_00108e78;
    listRecord[1] = (GH_U2F((unsigned int)((green | 0x4b000000))) - 8388608.0) * fVar1;
    listRecord[2] = (GH_U2F((unsigned int)((blue | 0x4b000000))) - 8388608.0) * fVar1;
  }
  return listRecord;
}

/* _glSecondaryColor3ub_CompExec @ 0x5ee54 (72 bytes) */
void _glSecondaryColor3ub_CompExec(glContext, red, green, blue)
  undefined4 glContext;
  undefined4 red;
  undefined4 green;
  undefined4 blue;
{
  ((int (*)())_glSecondaryColor3ub_Comp)(glContext,red,green,blue);
  ((void (*)())_glSecondaryColor3ub_Exec)(glContext,red,green,blue);
  return;
}

/* _glSecondaryColor3ubv_Exec @ 0x5ee9c (132 bytes) */
double _glSecondaryColor3ubv_Exec(glContext, v)
  int glContext;
  byte *v;
{
  float fVar1;
  float fVar2;
  
  fVar1 = (GH_U2F((unsigned int)((v[2] | 0x4b000000))) - 8388608.0) * FLOAT_00108e78;
  fVar2 = (GH_U2F((unsigned int)((v[1] | 0x4b000000))) - 8388608.0) * FLOAT_00108e78;
  *(float *)(glContext + 0x2c0) = (GH_U2F((unsigned int)((*v | 0x4b000000))) - 8388608.0) * FLOAT_00108e78;
  *(float *)(glContext + 0x2c8) = fVar1;
  *(float *)(glContext + 0x2c4) = fVar2;
  return;
}

/* _glSecondaryColor3ubv_Comp @ 0x5ef20 (196 bytes) */
int _glSecondaryColor3ubv_Comp(glContext, v)
  undefined4 glContext;
  byte *v;
{
  float fVar1;
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glSecondaryColor3_ListExec_00110064,0xc);
  fVar1 = FLOAT_00108e78;
  if (listRecord != (float *)0x0) {
    *listRecord = (GH_U2F((unsigned int)((*v | 0x4b000000))) - 8388608.0) * FLOAT_00108e78;
    listRecord[1] = (GH_U2F((unsigned int)((v[1] | 0x4b000000))) - 8388608.0) * fVar1;
    listRecord[2] = (GH_U2F((unsigned int)((v[2] | 0x4b000000))) - 8388608.0) * fVar1;
  }
  return listRecord;
}

/* _glSecondaryColor3ubv_CompExec @ 0x5efe4 (56 bytes) */
void _glSecondaryColor3ubv_CompExec(glContext, v)
  undefined4 glContext;
  undefined4 v;
{
  ((int (*)())_glSecondaryColor3ubv_Comp)(glContext,v);
  ((double (*)())_glSecondaryColor3ubv_Exec)(glContext,v);
  return;
}

/* _glSecondaryColor3us_Exec @ 0x5f01c (120 bytes) */
void _glSecondaryColor3us_Exec(glContext, red, green, blue)
  int glContext;
  uint red;
  uint green;
  uint blue;
{
  float fVar1;
  float fVar2;
  
  fVar1 = (GH_U2F((unsigned int)((blue | 0x4b000000))) - 8388608.0) * FLOAT_00108e74;
  fVar2 = (GH_U2F((unsigned int)((green | 0x4b000000))) - 8388608.0) * FLOAT_00108e74;
  *(float *)(glContext + 0x2c0) = (GH_U2F((unsigned int)((red | 0x4b000000))) - 8388608.0) * FLOAT_00108e74;
  *(float *)(glContext + 0x2c8) = fVar1;
  *(float *)(glContext + 0x2c4) = fVar2;
  return;
}

/* _glSecondaryColor3us_Comp @ 0x5f094 (192 bytes) */
int _glSecondaryColor3us_Comp(glContext, red, green, blue)
  undefined4 glContext;
  uint red;
  uint green;
  uint blue;
{
  float fVar1;
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glSecondaryColor3_ListExec_00110064,0xc);
  fVar1 = FLOAT_00108e74;
  if (listRecord != (float *)0x0) {
    *listRecord = (GH_U2F((unsigned int)((red | 0x4b000000))) - 8388608.0) * FLOAT_00108e74;
    listRecord[1] = (GH_U2F((unsigned int)((green | 0x4b000000))) - 8388608.0) * fVar1;
    listRecord[2] = (GH_U2F((unsigned int)((blue | 0x4b000000))) - 8388608.0) * fVar1;
  }
  return listRecord;
}

/* _glSecondaryColor3us_CompExec @ 0x5f154 (72 bytes) */
void _glSecondaryColor3us_CompExec(glContext, red, green, blue)
  undefined4 glContext;
  undefined4 red;
  undefined4 green;
  undefined4 blue;
{
  ((int (*)())_glSecondaryColor3us_Comp)(glContext,red,green,blue);
  ((void (*)())_glSecondaryColor3us_Exec)(glContext,red,green,blue);
  return;
}

/* _glSecondaryColor3usv_Exec @ 0x5f19c (132 bytes) */
double _glSecondaryColor3usv_Exec(glContext, v)
  int glContext;
  ushort *v;
{
  float fVar1;
  float fVar2;
  
  fVar1 = (GH_U2F((unsigned int)((v[2] | 0x4b000000))) - 8388608.0) * FLOAT_00108e74;
  fVar2 = (GH_U2F((unsigned int)((v[1] | 0x4b000000))) - 8388608.0) * FLOAT_00108e74;
  *(float *)(glContext + 0x2c0) = (GH_U2F((unsigned int)((*v | 0x4b000000))) - 8388608.0) * FLOAT_00108e74;
  *(float *)(glContext + 0x2c8) = fVar1;
  *(float *)(glContext + 0x2c4) = fVar2;
  return;
}

/* _glSecondaryColor3usv_Comp @ 0x5f220 (196 bytes) */
int _glSecondaryColor3usv_Comp(glContext, v)
  undefined4 glContext;
  ushort *v;
{
  float fVar1;
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glSecondaryColor3_ListExec_00110064,0xc);
  fVar1 = FLOAT_00108e74;
  if (listRecord != (float *)0x0) {
    *listRecord = (GH_U2F((unsigned int)((*v | 0x4b000000))) - 8388608.0) * FLOAT_00108e74;
    listRecord[1] = (GH_U2F((unsigned int)((v[1] | 0x4b000000))) - 8388608.0) * fVar1;
    listRecord[2] = (GH_U2F((unsigned int)((v[2] | 0x4b000000))) - 8388608.0) * fVar1;
  }
  return listRecord;
}

/* _glSecondaryColor3usv_CompExec @ 0x5f2e4 (56 bytes) */
void _glSecondaryColor3usv_CompExec(glContext, v)
  undefined4 glContext;
  undefined4 v;
{
  ((int (*)())_glSecondaryColor3usv_Comp)(glContext,v);
  ((double (*)())_glSecondaryColor3usv_Exec)(glContext,v);
  return;
}

/* _glSecondaryColor3ui_Exec @ 0x5f31c (116 bytes) */
void _glSecondaryColor3ui_Exec(glContext, red, green, blue)
  int glContext;
  undefined4 red;
  undefined4 green;
  undefined4 blue;
{
  float fVar1;
  float fVar2;
  
  fVar1 = (float)((double)CONCAT44(0x43300000,blue) - DOUBLE_00108d70) * FLOAT_00108e6c;
  fVar2 = (float)((double)CONCAT44(0x43300000,green) - DOUBLE_00108d70) * FLOAT_00108e6c;
  *(float *)(glContext + 0x2c0) =
       (float)((double)CONCAT44(0x43300000,red) - DOUBLE_00108d70) * FLOAT_00108e6c;
  *(float *)(glContext + 0x2c8) = fVar1;
  *(float *)(glContext + 0x2c4) = fVar2;
  return;
}

/* _glSecondaryColor3ui_Comp @ 0x5f390 (184 bytes) */
int _glSecondaryColor3ui_Comp(glContext, red, green, blue)
  undefined4 glContext;
  undefined4 red;
  undefined4 green;
  undefined4 blue;
{
  double dVar1;
  float fVar2;
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glSecondaryColor3_ListExec_00110064,0xc);
  fVar2 = FLOAT_00108e6c;
  dVar1 = DOUBLE_00108d70;
  if (listRecord != (float *)0x0) {
    *listRecord = (float)((double)CONCAT44(0x43300000,red) - DOUBLE_00108d70) * FLOAT_00108e6c;
    listRecord[1] = (float)((double)CONCAT44(0x43300000,green) - dVar1) * fVar2;
    listRecord[2] = (float)((double)CONCAT44(0x43300000,blue) - dVar1) * fVar2;
  }
  return listRecord;
}

/* _glSecondaryColor3ui_CompExec @ 0x5f448 (72 bytes) */
void _glSecondaryColor3ui_CompExec(glContext, red, green, blue)
  undefined4 glContext;
  undefined4 red;
  undefined4 green;
  undefined4 blue;
{
  ((int (*)())_glSecondaryColor3ui_Comp)(glContext,red,green,blue);
  ((void (*)())_glSecondaryColor3ui_Exec)(glContext,red,green,blue);
  return;
}

/* _glSecondaryColor3uiv_Exec @ 0x5f490 (128 bytes) */
double _glSecondaryColor3uiv_Exec(glContext, v)
  int glContext;
  undefined4 *v;
{
  float fVar1;
  float fVar2;
  
  fVar1 = (float)((double)CONCAT44(0x43300000,v[2]) - DOUBLE_00108d70) * FLOAT_00108e6c;
  fVar2 = (float)((double)CONCAT44(0x43300000,v[1]) - DOUBLE_00108d70) * FLOAT_00108e6c;
  *(float *)(glContext + 0x2c0) =
       (float)((double)CONCAT44(0x43300000,*v) - DOUBLE_00108d70) * FLOAT_00108e6c;
  *(float *)(glContext + 0x2c8) = fVar1;
  *(float *)(glContext + 0x2c4) = fVar2;
  return;
}

/* _glSecondaryColor3uiv_Comp @ 0x5f510 (188 bytes) */
int _glSecondaryColor3uiv_Comp(glContext, v)
  undefined4 glContext;
  undefined4 *v;
{
  double dVar1;
  float fVar2;
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glSecondaryColor3_ListExec_00110064,0xc);
  fVar2 = FLOAT_00108e6c;
  dVar1 = DOUBLE_00108d70;
  if (listRecord != (float *)0x0) {
    *listRecord = (float)((double)CONCAT44(0x43300000,*v) - DOUBLE_00108d70) * FLOAT_00108e6c;
    listRecord[1] = (float)((double)CONCAT44(0x43300000,v[1]) - dVar1) * fVar2;
    listRecord[2] = (float)((double)CONCAT44(0x43300000,v[2]) - dVar1) * fVar2;
  }
  return listRecord;
}

/* _glSecondaryColor3uiv_CompExec @ 0x5f5cc (56 bytes) */
void _glSecondaryColor3uiv_CompExec(glContext, v)
  undefined4 glContext;
  undefined4 v;
{
  ((int (*)())_glSecondaryColor3uiv_Comp)(glContext,v);
  ((double (*)())_glSecondaryColor3uiv_Exec)(glContext,v);
  return;
}

/* _glColorTable_ListExec @ 0x5f604 (644 bytes) */
int _glColorTable_ListExec(glContext, recordedArgs)
  int glContext;
  uint *recordedArgs;
{
  byte bVar1;
  ushort uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint *pixels;
  int iVar9;
  int textureLevel;
  
  iVar7 = recordedArgs[5] + 0x18;
  iVar5 = _gleCheckColorTableArgs(glContext,*recordedArgs,recordedArgs[1],recordedArgs[2],recordedArgs[3],recordedArgs[4]);
  if (iVar5 != 0) {
    uVar2 = *(ushort *)(iVar5 + 0x24);
    if ((uVar2 & 0x3c00) != 0x1000) {
      if ((uVar2 & 0x3c00) == 0) {
        *(ushort *)(iVar5 + 0x24) = uVar2 | 0x1000;
      }
      else if ((uVar2 & 0xc00) != 0) {
        if (*(int *)(glContext + 0x7574) != 0) {
          return iVar7;
        }
        *(undefined4 *)(glContext + 0x7574) = 0x502;
        return iVar7;
      }
    }
    textureLevel = iVar5 + 0xac;
    if ((*(byte *)(iVar5 + 0xb7) & 0x20) != 0) {
      _gleDeletePluginTextureLevel(glContext,iVar5,textureLevel,0,0xffffffff);
      if (*(int *)(iVar5 + 0xc0) != 0) {
        bVar1 = *(byte *)(iVar5 + 0xb7);
        if ((bVar1 & 1) == 0) {
          _gleFreeTextureLevel(glContext,iVar5,textureLevel);
          bVar1 = *(byte *)(iVar5 + 0xb7);
        }
        else {
          *(undefined4 *)(iVar5 + 0xc0) = 0;
        }
        *(byte *)(iVar5 + 0xb7) = bVar1 & 0xef;
      }
      *(byte *)(iVar5 + 0xb7) = *(byte *)(iVar5 + 0xb7) & 0xdf;
    }
    uVar4 = *recordedArgs;
    iVar9 = glContext + 0x33d0;
    if (uVar4 != 0x80d1) {
      if (uVar4 < 0x80d2) {
        iVar9 = glContext + 0x33b0;
        uVar3 = 0x80d0;
      }
      else {
        iVar9 = glContext + 0x33f0;
        uVar3 = 0x80d2;
      }
      if (uVar4 != uVar3) {
        iVar9 = 0;
      }
    }
    pixels = recordedArgs + 6;
    if (iVar9 == 0) {
      iVar9 = _gleCreateTextureLevel
                        (glContext,iVar5,textureLevel,recordedArgs[1],recordedArgs[2],1,1,0,recordedArgs[3],recordedArgs[4],0,
                         pixels);
      if (iVar9 != 0) {
        _gleTextureImagePut(glContext,textureLevel,0,0,0,recordedArgs[2],1,1,recordedArgs[3],recordedArgs[4],0,0,pixels);
      }
      *(uint *)(glContext + 0x314) =
           *(uint *)(glContext + 0x314) | 1 << (*(uint *)(glContext + 0x53d4) & 0x3f);
    }
    else {
      iVar6 = _gleCreateColorTableLevel
                        (glContext,iVar5,textureLevel,recordedArgs[1],recordedArgs[2],recordedArgs[3],recordedArgs[4],pixels);
      if ((iVar6 != 0) && (pixels != (uint *)0x0)) {
        _gleColorTable(glContext,iVar9,textureLevel,recordedArgs[2],recordedArgs[3],recordedArgs[4],pixels);
      }
      *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x40000000;
    }
    _gleCreatePluginTextureLevel(glContext,iVar5,textureLevel,0,0xffffffff,recordedArgs[1]);
  }
  return iVar7;
}

/* _glColorTable_Comp @ 0x5f888 (840 bytes) */
int _glColorTable_Comp(glContext, target, internalformat, width, format, type, table)
  int glContext;
  uint target;
  uint internalformat;
  uint width;
  uint format;
  uint type;
  int table;
{
  undefined4 glErrorCode;
  bool bVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int pixelBytes;
  uint *listRecord;
  int iVar7;
  int pixelUnpackBuffer;
  double dVar9;
  
  pixelUnpackBuffer = *(int *)(glContext + 0x4a6c);
  iVar5 = glContext;
  if (pixelUnpackBuffer == 0) {
LAB_0005f94c:
    if (target < 0x80d3) {
      if (target < 0x80d0) {
        if (target < 0x8065) {
          if (0x8062 < target) goto LAB_0005fa24;
          if (1 < target - 0xde0) goto LAB_0005fb20;
        }
        else if (target != 0x806f) {
          uVar2 = 0x8070;
LAB_0005f9ec:
          if (target == uVar2) {
LAB_0005fa24:
            uVar3 = ((int (*)())_glColorTable_Exec)(glContext,target,internalformat,width,format,type,table);
            return uVar3;
          }
          goto LAB_0005fb20;
        }
      }
LAB_0005fa48:
      if ((int)width < 0) {
        if (*(int *)(glContext + 0x7574) != 0) {
          return iVar5;
        }
        glErrorCode = 0x501;
        goto LAB_0005fb30;
      }
      if (type < 0x8037) {
        if (0x8032 < type) {
LAB_0005faf4:
          if (format == 0x1908) goto LAB_0005fb38;
          bVar1 = format == 0x80e1;
LAB_0005fb08:
          if (bVar1) {
LAB_0005fb38:
            pixelBytes = _glePixelBytes(format,type);
            if ((int)(pixelBytes * width) < 1) {
              return pixelBytes;
            }
            uVar2 = pixelBytes * width + 3 & 0xfffffffc;
            listRecord = (uint *)_gleAddListItem(glContext,PTR__glColorTable_ListExec_00110074,
                                             uVar2 + 0x18);
            if (listRecord == (uint *)0x0) {
              return 0;
            }
            *listRecord = target;
            listRecord[1] = internalformat;
            listRecord[5] = uVar2;
            listRecord[2] = width;
            listRecord[3] = format;
            listRecord[4] = type;
            if ((int)uVar2 < 1) {
              return (int)listRecord;
            }
            if (table == 0) {
              return (int)listRecord;
            }
            uVar3 = _gleFillImage(glContext,width,1,1,format,type,table,listRecord + 6);
            return uVar3;
          }
          goto LAB_0005fb0c;
        }
        if (0x13ff < type) {
          if (type < 0x1407) {
            if (format == 0x8000) goto LAB_0005fb38;
            if (format < 0x8001) {
              bVar1 = 7 < format - 0x1903;
            }
            else {
              bVar1 = 1 < format - 0x80e0;
            }
            if (!bVar1) goto LAB_0005fb38;
            goto LAB_0005fb0c;
          }
          if (type == 0x8032) goto LAB_0005faec;
        }
      }
      else if (0x8361 < type) {
        if (type < 0x8365) {
LAB_0005faec:
          bVar1 = format == 0x1907;
          goto LAB_0005fb08;
        }
        if (type < 0x8369) goto LAB_0005faf4;
      }
    }
    else {
      if (target == 0x84f5) goto LAB_0005fa48;
      if (0x84f5 < target) {
        if (target != 0x8513) {
          if (target < 0x8514) {
            uVar2 = 0x84f7;
            goto LAB_0005f9ec;
          }
          if (target == 0x851b) goto LAB_0005fa24;
          if (target != 0x85b3) goto LAB_0005fb20;
          target = 0x84f5;
        }
        goto LAB_0005fa48;
      }
      if (target < 0x80d6) goto LAB_0005fa24;
      if (target == 0x81fb) goto LAB_0005fa48;
    }
LAB_0005fb20:
    if (*(int *)(glContext + 0x7574) != 0) {
      return iVar5;
    }
    glErrorCode = 0x500;
  }
  else {
    iVar4 = _gleOffsetLimitImage(glContext + 0x31cc,width,1,format,type,table);
    iVar7 = *(int *)(pixelUnpackBuffer + 0x38);
    dVar9 = (double)((double (*)())_gleBytesPerElement)(type);
    iVar5 = (int)dVar9;
    if (iVar4 <= iVar7) {
      if (iVar5 == 0) {
        iVar5 = _glePixelBytes(format,type);
      }
      if (table == (table / iVar5) * iVar5) {
        if (*(int *)(pixelUnpackBuffer + 0x40) != 0) {
          _gleSynchronizePluginBuffer(glContext,pixelUnpackBuffer + 0x10);
        }
        table = table + *(int *)(pixelUnpackBuffer + 0x30);
        goto LAB_0005f94c;
      }
    }
LAB_0005fb0c:
    if (*(int *)(glContext + 0x7574) != 0) {
      return iVar5;
    }
    glErrorCode = 0x502;
  }
LAB_0005fb30:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return iVar5;
}

/* _glColorTable_Exec @ 0x5fbd0 (860 bytes) */
int _glColorTable_Exec(glContext, target, internalformat, width, format, type, table)
  int glContext;
  uint target;
  undefined4 internalformat;
  int width;
  undefined4 format;
  undefined4 type;
  int table;
{
  bool bVar1;
  byte bVar2;
  ushort uVar3;
  undefined4 glErrorCode;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int pixelUnpackBuffer;
  double dVar10;
  
  pixelUnpackBuffer = *(int *)(glContext + 0x4a6c);
  if (pixelUnpackBuffer == 0) {
LAB_0005fc94:
    if (*(short *)(glContext + 0x4a10) < 0) {
      bVar1 = table != 0;
      if ((!bVar1) && (*(char *)(glContext + 0x31e6) != '\0')) {
        if (*(int *)(glContext + 0x7574) != 0) {
          return;
        }
        glErrorCode = 0x501;
        goto LAB_0005fd2c;
      }
      iVar9 = _gleCheckColorTableArgs(glContext,target,internalformat,width,format,type);
      if (iVar9 == 0) {
        return;
      }
      uVar3 = *(ushort *)(iVar9 + 0x24);
      if ((uVar3 & 0x3c00) == 0x1000) {
LAB_0005fd34:
        iVar7 = iVar9 + 0xac;
        if ((*(byte *)(iVar9 + 0xb7) & 0x20) != 0) {
          _gleDeletePluginTextureLevel(glContext,iVar9,iVar7,0,0xffffffff);
          if (*(int *)(iVar9 + 0xc0) != 0) {
            bVar2 = *(byte *)(iVar9 + 0xb7);
            if ((bVar2 & 1) == 0) {
              _gleFreeTextureLevel(glContext,iVar9,iVar7);
              bVar2 = *(byte *)(iVar9 + 0xb7);
            }
            else {
              *(undefined4 *)(iVar9 + 0xc0) = 0;
            }
            *(byte *)(iVar9 + 0xb7) = bVar2 & 0xef;
          }
          *(byte *)(iVar9 + 0xb7) = *(byte *)(iVar9 + 0xb7) & 0xdf;
        }
        iVar6 = glContext + 0x33d0;
        if (target != 0x80d1) {
          if (target < 0x80d2) {
            iVar6 = glContext + 0x33b0;
            uVar5 = 0x80d0;
          }
          else {
            iVar6 = glContext + 0x33f0;
            uVar5 = 0x80d2;
          }
          if (target != uVar5) {
            iVar6 = 0;
          }
        }
        if (iVar6 == 0) {
          iVar6 = _gleCreateTextureLevel
                            (glContext,iVar9,iVar7,internalformat,width,1,1,0,format,type,1,table);
          if ((iVar6 != 0) && (bVar1)) {
            _gleTextureImagePut(glContext,iVar7,0,0,0,width,1,1,format,type,0,glContext + 0x31cc,
                                table);
          }
          *(uint *)(glContext + 0x314) =
               *(uint *)(glContext + 0x314) | 1 << (*(uint *)(glContext + 0x53d4) & 0x3f);
        }
        else {
          iVar8 = _gleCreateColorTableLevel
                            (glContext,iVar9,iVar7,internalformat,width,format,type,table);
          if ((iVar8 != 0) && (bVar1)) {
            _gleColorTable(glContext,iVar6,iVar7,width,format,type,table);
          }
          *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x40000000;
        }
        if (width == 0) {
          return;
        }
        _gleCreatePluginTextureLevel(glContext,iVar9,iVar7,0,0xffffffff,internalformat);
        return;
      }
      if ((uVar3 & 0x3c00) == 0) {
        *(ushort *)(iVar9 + 0x24) = uVar3 | 0x1000;
        goto LAB_0005fd34;
      }
      if ((uVar3 & 0xc00) == 0) goto LAB_0005fd34;
    }
  }
  else {
    iVar6 = _gleOffsetLimitImage(glContext + 0x31cc,width,1,format,type,table);
    iVar8 = *(int *)(pixelUnpackBuffer + 0x38);
    dVar10 = (double)((double (*)())_gleBytesPerElement)(type);
    iVar7 = (int)dVar10;
    if (iVar6 <= iVar8) {
      if (iVar7 == 0) {
        iVar7 = _glePixelBytes(format,type);
      }
      if (table == (table / iVar7) * iVar7) {
        if (*(int *)(pixelUnpackBuffer + 0x40) != 0) {
          _gleSynchronizePluginBuffer(glContext,pixelUnpackBuffer + 0x10);
        }
        table = table + *(int *)(pixelUnpackBuffer + 0x30);
        goto LAB_0005fc94;
      }
    }
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  glErrorCode = 0x502;
LAB_0005fd2c:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glColorTable_CompExec @ 0x5ff2c (96 bytes) */
void _glColorTable_CompExec(glContext, target, internalformat, width, format, type, table)
  undefined4 glContext;
  undefined4 target;
  undefined4 internalformat;
  undefined4 width;
  undefined4 format;
  undefined4 type;
  undefined4 table;
{
  ((int (*)())_glColorTable_Comp)(glContext,target,internalformat,width,format,type,table);
  ((int (*)())_glColorTable_Exec)(glContext,target,internalformat,width,format,type,table);
  return;
}

/* _glColorSubTable_ListExec @ 0x5ff8c (504 bytes) */
int _glColorSubTable_ListExec(glContext, recordedArgs)
  int glContext;
  uint *recordedArgs;
{
  uint uVar1;
  uint uVar2;
  byte bVar4;
  uint uVar3;
  int iVar5;
  int textureLevel;
  
  uVar2 = recordedArgs[5];
  if (*(short *)(glContext + 0x4a10) < 0) {
    iVar5 = _gleCheckColorSubTableArgs(glContext,*recordedArgs,recordedArgs[1],recordedArgs[2],recordedArgs[3],recordedArgs[4])
    ;
    if (iVar5 != 0) {
      textureLevel = iVar5 + 0xac;
      bVar4 = *(byte *)(iVar5 + 0xb7);
      if ((bVar4 & 0x10) == 0) {
        if ((bVar4 & 0x40) == 0) {
          if (*(int *)(iVar5 + 0xc0) == 0) {
            _gleAllocateTextureLevel(glContext,iVar5,textureLevel);
            bVar4 = *(byte *)(iVar5 + 0xb7);
          }
          *(byte *)(iVar5 + 0xb7) = bVar4 | 0x10;
        }
        else {
          _gleUploadPluginTextureLevel
                    (glContext,iVar5,textureLevel,0,0xffffffff,(uint)*(byte *)(glContext + 0x85a8));
        }
      }
      _gleModifyPluginTextureLevel(glContext,iVar5,textureLevel,0,0xffffffff,recordedArgs[1],0,0,recordedArgs[2],1,1);
      uVar3 = *recordedArgs;
      iVar5 = glContext + 0x33d0;
      if (uVar3 != 0x80d1) {
        if (uVar3 < 0x80d2) {
          iVar5 = glContext + 0x33b0;
          uVar1 = 0x80d0;
        }
        else {
          iVar5 = glContext + 0x33f0;
          uVar1 = 0x80d2;
        }
        if (uVar3 != uVar1) {
          iVar5 = 0;
        }
      }
      if (iVar5 == 0) {
        _gleTextureImagePut(glContext,textureLevel,recordedArgs[1],0,0,recordedArgs[2],1,1,recordedArgs[3],recordedArgs[4],0,0,
                            recordedArgs + 6);
        *(uint *)(glContext + 0x314) =
             *(uint *)(glContext + 0x314) | 1 << (*(uint *)(glContext + 0x53d4) & 0x3f);
      }
      else {
        _gleColorSubTable(glContext,iVar5,textureLevel,recordedArgs[1],recordedArgs[2],recordedArgs[3],recordedArgs[4],
                          recordedArgs + 6);
        *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x40000000;
      }
    }
  }
  else if (*(int *)(glContext + 0x7574) == 0) {
    *(undefined4 *)(glContext + 0x7574) = 0x502;
  }
  return uVar2 + 0x18;
}

/* _glColorSubTable_Comp @ 0x60184 (656 bytes) */
int _glColorSubTable_Comp(glContext, target, start, count, format, type, data)
  int glContext;
  uint target;
  uint start;
  uint count;
  uint format;
  uint type;
  int data;
{
  undefined4 glErrorCode;
  bool bVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int pixelBytes;
  uint *listRecord;
  int iVar7;
  int pixelUnpackBuffer;
  double dVar9;
  
  pixelUnpackBuffer = *(int *)(glContext + 0x4a6c);
  iVar5 = glContext;
  if (pixelUnpackBuffer == 0) {
LAB_00060248:
    if (data == 0) {
      return iVar5;
    }
    if (target < 0x80d3) {
      if (target < 0x80d0) {
        if (target < 0xde0) goto LAB_00060374;
        if (0xde1 < target) {
          uVar2 = 0x806f;
          goto LAB_00060294;
        }
      }
LAB_0006029c:
      if ((int)count < 0) {
        if (*(int *)(glContext + 0x7574) != 0) {
          return iVar5;
        }
        glErrorCode = 0x501;
        goto LAB_00060384;
      }
      if (type < 0x8037) {
        if (0x8032 < type) {
LAB_00060348:
          if (format == 0x1908) goto LAB_0006038c;
          bVar1 = format == 0x80e1;
LAB_0006035c:
          if (bVar1) {
LAB_0006038c:
            pixelBytes = _glePixelBytes(format,type);
            if ((int)(pixelBytes * count) < 1) {
              return pixelBytes;
            }
            uVar2 = pixelBytes * count + 3 & 0xfffffffc;
            listRecord = (uint *)_gleAddListItem(glContext,PTR__glColorSubTable_ListExec_00110070,
                                             uVar2 + 0x18);
            if (listRecord == (uint *)0x0) {
              return 0;
            }
            *listRecord = target;
            listRecord[1] = start;
            listRecord[5] = uVar2;
            listRecord[2] = count;
            listRecord[3] = format;
            listRecord[4] = type;
            uVar3 = _gleFillImage(glContext,count,1,1,format,type,data,listRecord + 6);
            return uVar3;
          }
          goto LAB_00060360;
        }
        if (0x13ff < type) {
          if (type < 0x1407) {
            if (format == 0x8000) goto LAB_0006038c;
            if (format < 0x8001) {
              bVar1 = 7 < format - 0x1903;
            }
            else {
              bVar1 = 1 < format - 0x80e0;
            }
            if (!bVar1) goto LAB_0006038c;
            goto LAB_00060360;
          }
          if (type == 0x8032) goto LAB_00060340;
        }
      }
      else if (0x8361 < type) {
        if (type < 0x8365) {
LAB_00060340:
          bVar1 = format == 0x1907;
          goto LAB_0006035c;
        }
        if (type < 0x8369) goto LAB_00060348;
      }
    }
    else {
      if (target == 0x81fb) goto LAB_0006029c;
      uVar2 = 0x8513;
LAB_00060294:
      if (target == uVar2) goto LAB_0006029c;
    }
LAB_00060374:
    if (*(int *)(glContext + 0x7574) != 0) {
      return iVar5;
    }
    glErrorCode = 0x500;
  }
  else {
    iVar4 = _gleOffsetLimitImage(glContext + 0x31cc,count,1,format,type,data);
    iVar7 = *(int *)(pixelUnpackBuffer + 0x38);
    dVar9 = (double)((double (*)())_gleBytesPerElement)(type);
    iVar5 = (int)dVar9;
    if (iVar4 <= iVar7) {
      if (iVar5 == 0) {
        iVar5 = _glePixelBytes(format,type);
      }
      if (data == (data / iVar5) * iVar5) {
        if (*(int *)(pixelUnpackBuffer + 0x40) != 0) {
          _gleSynchronizePluginBuffer(glContext,pixelUnpackBuffer + 0x10);
        }
        data = data + *(int *)(pixelUnpackBuffer + 0x30);
        goto LAB_00060248;
      }
    }
LAB_00060360:
    if (*(int *)(glContext + 0x7574) != 0) {
      return iVar5;
    }
    glErrorCode = 0x502;
  }
LAB_00060384:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return iVar5;
}

/* _glColorSubTable_Exec @ 0x60414 (652 bytes) */
void _glColorSubTable_Exec(glContext, target, start, count, format, type, data)
  int glContext;
  uint target;
  undefined4 start;
  int count;
  undefined4 format;
  undefined4 type;
  int data;
{
  uint uVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int pixelUnpackBuffer;
  int iVar6;
  double dVar7;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    pixelUnpackBuffer = *(int *)(glContext + 0x4a6c);
    if (pixelUnpackBuffer == 0) {
LAB_000604f4:
      if (count == 0) {
        return;
      }
      iVar5 = _gleCheckColorSubTableArgs(glContext,target,start,count,format,type);
      if (iVar5 == 0) {
        return;
      }
      iVar4 = iVar5 + 0xac;
      bVar2 = *(byte *)(iVar5 + 0xb7);
      if ((bVar2 & 0x10) == 0) {
        if ((bVar2 & 0x40) == 0) {
          if (*(int *)(iVar5 + 0xc0) == 0) {
            _gleAllocateTextureLevel(glContext,iVar5,iVar4);
            bVar2 = *(byte *)(iVar5 + 0xb7);
          }
          *(byte *)(iVar5 + 0xb7) = bVar2 | 0x10;
        }
        else {
          _gleUploadPluginTextureLevel
                    (glContext,iVar5,iVar4,0,0xffffffff,(uint)*(byte *)(glContext + 0x85a8));
        }
      }
      _gleModifyPluginTextureLevel(glContext,iVar5,iVar4,0,0xffffffff,start,0,0,count,1,1);
      iVar5 = glContext + 0x33d0;
      if (target != 0x80d1) {
        if (target < 0x80d2) {
          iVar5 = glContext + 0x33b0;
          uVar1 = 0x80d0;
        }
        else {
          iVar5 = glContext + 0x33f0;
          uVar1 = 0x80d2;
        }
        if (target != uVar1) {
          iVar5 = 0;
        }
      }
      if (iVar5 != 0) {
        _gleColorSubTable(glContext,iVar5,iVar4,start,count,format,type,data);
        *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x40000000;
        return;
      }
      _gleTextureImagePut(glContext,iVar4,start,0,0,count,1,1,format,type,0,glContext + 0x31cc,
                          data);
      *(uint *)(glContext + 0x314) =
           *(uint *)(glContext + 0x314) | 1 << (*(uint *)(glContext + 0x53d4) & 0x3f);
      return;
    }
    iVar3 = _gleOffsetLimitImage(glContext + 0x31cc,count,1,format,type,data);
    iVar6 = *(int *)(pixelUnpackBuffer + 0x38);
    dVar7 = (double)((double (*)())_gleBytesPerElement)(type);
    iVar4 = (int)dVar7;
    if (iVar3 <= iVar6) {
      if (iVar4 == 0) {
        iVar4 = _glePixelBytes(format,type);
      }
      if (data == (data / iVar4) * iVar4) {
        if (*(int *)(pixelUnpackBuffer + 0x40) != 0) {
          _gleSynchronizePluginBuffer(glContext,pixelUnpackBuffer + 0x10);
        }
        data = data + *(int *)(pixelUnpackBuffer + 0x30);
        goto LAB_000604f4;
      }
    }
  }
  if (*(int *)(glContext + 0x7574) == 0) {
    *(undefined4 *)(glContext + 0x7574) = 0x502;
  }
  return;
}

/* _glColorSubTable_CompExec @ 0x606a0 (96 bytes) */
void _glColorSubTable_CompExec(glContext, target, start, count, format, type, data)
  undefined4 glContext;
  undefined4 target;
  undefined4 start;
  undefined4 count;
  undefined4 format;
  undefined4 type;
  undefined4 data;
{
  ((int (*)())_glColorSubTable_Comp)(glContext,target,start,count,format,type,data);
  ((void (*)())_glColorSubTable_Exec)(glContext,target,start,count,format,type,data);
  return;
}

/* _glCopyColorTable_ListExec @ 0x60700 (60 bytes) */
undefined4 _glCopyColorTable_ListExec(undefined4 glContext,undefined4 *recordedArgs,double forwardedFloatArg1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
{
  ((void (*)())_glCopyColorTable_Exec)(glContext,*recordedArgs,recordedArgs[1],recordedArgs[2],recordedArgs[3],recordedArgs[4],forwardedFloatArg1,forwardedFloatArg2,forwardedFloatArg3
             ,forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
  return 0x14;
}

/* _glCopyColorTable_Comp @ 0x6073c (108 bytes) */
int _glCopyColorTable_Comp(glContext, target, internalformat, x, y, width)
  undefined4 glContext;
  undefined4 target;
  undefined4 internalformat;
  undefined4 x;
  undefined4 y;
  undefined4 width;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glCopyColorTable_ListExec_0011006c,0x14);
  if (listRecord != (undefined4 *)0x0) {
    listRecord[4] = width;
    *listRecord = target;
    listRecord[1] = internalformat;
    listRecord[2] = x;
    listRecord[3] = y;
  }
  return listRecord;
}

/* _glCopyColorTable_Exec @ 0x607a8 (1232 bytes) */
void _glCopyColorTable_Exec(int glContext,uint target,undefined4 internalformat,undefined4 x,undefined4 y,undefined4 width,double fparam_1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
{
  int remaining;
  int loopIndex;
  undefined4 glErrorCode;
  bool bVar1;
  char cVar2;
  byte bVar3;
  ushort uVar4;
  undefined4 uVar5;
  int *srcCursor;
  int iVar7;
  int iVar8;
  int framebufferObject;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  int iVar12;
  int matrixChangeBits;
  uint uVar13;
  int iVar14;
  int *piVar15;
  double extraout_f1;
  
  if ((*(int *)(glContext + 0x744c) != 0) || (*(int *)(glContext + 0x310) < 0)) {
    matrixChangeBits = *(int *)(glContext + 0x50ac);
    uVar5 = internalformat;
    uVar9 = x;
    uVar10 = y;
    uVar11 = width;
    if (matrixChangeBits != 0 || (*(uint *)(glContext + 0x505c) & *(uint *)(glContext + 0x50b0)) != 0) {
      _gleUpdateMatrixFunc(glContext);
      fparam_1 = extraout_f1;
    }
    if (*(char *)(glContext + 0x4691) != '\0') {
      framebufferObject = *(int *)(glContext + 0x744c);
      piVar15 = (int *)(glContext + 0x310);
      cVar2 = *(char *)(*(int *)(glContext + 0x468c) + 0x79);
      if ((framebufferObject != 0) && (*(int *)(framebufferObject + 0xec) != 0)) {
        ((void (*)())_gleUpdateFramebufferCompleteness)(glContext,framebufferObject + 0x10,uVar5,uVar9,uVar10,uVar11,matrixChangeBits,fparam_1,forwardedFloatArg2,forwardedFloatArg3,
                   forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
        *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x80000000;
      }
      if ((*(char *)(glContext + 0x4664) == '\0') && (*(int *)(glContext + 0x5430) == 0)) {
LAB_000608e8:
        uVar13 = *(uint *)(glContext + 0x31c);
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
        uVar13 = *(uint *)(glContext + 0x31c);
        if ((uVar13 & 0x15555) != 0) {
          if (*(char *)(glContext + 0x2e54) != '\0') {
            _gleUpdateLightRGBASums(glContext,glContext + 0x2c20,0);
          }
          if (*(char *)(glContext + 0x3094) != '\0') {
            _gleUpdateLightRGBASums(glContext,glContext + 0x2e60,1);
          }
          goto LAB_000608e8;
        }
      }
      bVar1 = cVar2 == '\0';
      if (bVar1) {
        uVar13 = uVar13 & 0x17000000;
      }
      else {
        uVar13 = uVar13 & 0x17ffffff;
      }
      if (bVar1) {
        bVar1 = ((*piVar15 == 0 && *(int *)(glContext + 0x314) == 0) && uVar13 == 0) &&
                *(int *)(glContext + 800) == 0;
      }
      else {
        bVar1 = (((*piVar15 == 0 && *(int *)(glContext + 0x314) == 0) &&
                 (*(uint *)(glContext + 0x318) & 0xfffffffd) == 0) && uVar13 == 0) &&
                *(int *)(glContext + 800) == 0;
      }
      if (!bVar1) {
        if (*(char *)(glContext + 0x85a8) == *(char *)(glContext + 0x85a6)) {
          uVar13 = (**(code **)(glContext + 0x4788))
                             (*(undefined4 *)(glContext + 0x4688),glContext + 0x4698,piVar15);
          if ((((uVar13 & 3) != (uint)*(byte *)(glContext + 0x7580)) ||
              ((uVar13 & 4) != (uint)*(byte *)(glContext + 0x7581))) ||
             ((uVar13 & 8) != (uint)(*(char *)(glContext + 0x759d) == '\0'))) {
            if ((uVar13 & 4) == 0) {
              uVar13 = uVar13 & 0xfffffffe;
              *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x10000000;
            }
            _gleUpdateDispatchCodeChange(glContext,uVar13);
            if (*(char *)(glContext + 0x759d) == '\0') {
              if (*(int *)(glContext + 0x7574) != 0) {
                return;
              }
              glErrorCode = 0x506;
              goto LAB_00060a74;
            }
          }
        }
        else {
          _gleSwitchToNonRevertRenderer(glContext);
        }
        remaining = 0x13;
        do {
          *piVar15 = 0;
          piVar15 = piVar15 + 1;
          remaining = remaining + -1;
        } while (remaining != 0);
      }
    }
  }
  if (*(short *)(glContext + 0x4a10) < 0) {
    iVar12 = _gleCheckCopyColorTableArgs(glContext,target,internalformat,width);
    if (iVar12 == 0) {
      return;
    }
    uVar4 = *(ushort *)(iVar12 + 0x24);
    if ((uVar4 & 0x3c00) == 0x1000) {
LAB_00060a7c:
      iVar8 = iVar12 + 0xac;
      if ((*(byte *)(iVar12 + 0xb7) & 0x20) != 0) {
        _gleDeletePluginTextureLevel(glContext,iVar12,iVar8,0,0xffffffff);
        if (*(int *)(iVar12 + 0xc0) != 0) {
          bVar3 = *(byte *)(iVar12 + 0xb7);
          if ((bVar3 & 1) == 0) {
            _gleFreeTextureLevel(glContext,iVar12,iVar8);
            bVar3 = *(byte *)(iVar12 + 0xb7);
          }
          else {
            *(undefined4 *)(iVar12 + 0xc0) = 0;
          }
          *(byte *)(iVar12 + 0xb7) = bVar3 & 0xef;
        }
        *(byte *)(iVar12 + 0xb7) = *(byte *)(iVar12 + 0xb7) & 0xdf;
      }
      iVar14 = glContext + 0x33d0;
      if (target != 0x80d1) {
        if (target < 0x80d2) {
          iVar14 = glContext + 0x33b0;
          uVar13 = 0x80d0;
        }
        else {
          iVar14 = glContext + 0x33f0;
          uVar13 = 0x80d2;
        }
        if (target != uVar13) {
          iVar14 = 0;
        }
      }
      if (iVar14 == 0) {
        iVar14 = _gleCreateTextureLevel
                           (glContext,iVar12,iVar8,internalformat,width,1,1,0,0x1908,0x1401,0,0x1000);
        if (iVar14 != 0) {
          _gleTextureImageCopy(glContext,iVar8,internalformat,x,y,width,1);
        }
        *(uint *)(glContext + 0x314) =
             *(uint *)(glContext + 0x314) | 1 << (*(uint *)(glContext + 0x53d4) & 0x3f);
      }
      else {
        iVar7 = _gleCreateColorTableLevel(glContext,iVar12,iVar8,internalformat,width,0x1908,0x1401,0x1000)
        ;
        if (iVar7 != 0) {
          _gleTextureImageCopy(glContext,iVar8,internalformat,x,y,width,1);
        }
        _gleImagingScaleAndBias
                  (glContext,iVar14,*(undefined4 *)(iVar12 + 0xc0),(uint)*(ushort *)(iVar12 + 0xbc),0,
                   width,1);
        *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x40000000;
      }
      _gleCreatePluginTextureLevel(glContext,iVar12,iVar8,0,0xffffffff,internalformat);
      return;
    }
    if ((uVar4 & 0x3c00) == 0) {
      *(ushort *)(iVar12 + 0x24) = uVar4 | 0x1000;
      goto LAB_00060a7c;
    }
    if ((uVar4 & 0xc00) == 0) goto LAB_00060a7c;
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  glErrorCode = 0x502;
LAB_00060a74:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glCopyColorTable_CompExec @ 0x60c78 (88 bytes) */
void _glCopyColorTable_CompExec(glContext, target, internalformat, x, y, width)
  undefined4 glContext;
  undefined4 target;
  undefined4 internalformat;
  undefined4 x;
  undefined4 y;
  undefined4 width;
{
  double forwardedFloatArg1;
  double incomingFpr2;
  double incomingFpr3;
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  
  ((int (*)())_glCopyColorTable_Comp)(glContext,target,internalformat,x,y,width);
  ((void (*)())_glCopyColorTable_Exec)(glContext,target,internalformat,x,y,width,forwardedFloatArg1,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,
             incomingFpr7,incomingFpr8);
  return;
}

/* _glCopyColorSubTable_ListExec @ 0x60cd0 (60 bytes) */
undefined4 _glCopyColorSubTable_ListExec(undefined4 glContext,undefined4 *recordedArgs,double forwardedFloatArg1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
{
  ((void (*)())_glCopyColorSubTable_Exec)(glContext,*recordedArgs,recordedArgs[1],recordedArgs[2],recordedArgs[3],recordedArgs[4],forwardedFloatArg1,forwardedFloatArg2,forwardedFloatArg3
             ,forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
  return 0x14;
}

/* _glCopyColorSubTable_Comp @ 0x60d0c (108 bytes) */
int _glCopyColorSubTable_Comp(glContext, target, start, x, y, width)
  undefined4 glContext;
  undefined4 target;
  undefined4 start;
  undefined4 x;
  undefined4 y;
  undefined4 width;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glCopyColorSubTable_ListExec_00110068,0x14);
  if (listRecord != (undefined4 *)0x0) {
    listRecord[4] = width;
    *listRecord = target;
    listRecord[1] = start;
    listRecord[2] = x;
    listRecord[3] = y;
  }
  return listRecord;
}

/* _glCopyColorSubTable_Exec @ 0x60d78 (1044 bytes) */
void _glCopyColorSubTable_Exec(int glContext,uint target,undefined4 start,undefined4 x,undefined4 y,int width,double fparam_1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
{
  int remaining;
  int loopIndex;
  undefined4 glErrorCode;
  bool bVar1;
  char cVar2;
  undefined4 uVar3;
  int *srcCursor;
  byte bVar5;
  int iVar6;
  int framebufferObject;
  undefined4 uVar7;
  undefined4 uVar8;
  int iVar9;
  int matrixChangeBits;
  int iVar10;
  uint uVar11;
  int *piVar12;
  double extraout_f1;
  
  if ((*(int *)(glContext + 0x744c) != 0) || (*(int *)(glContext + 0x310) < 0)) {
    matrixChangeBits = *(int *)(glContext + 0x50ac);
    uVar3 = start;
    uVar7 = x;
    uVar8 = y;
    iVar10 = width;
    if (matrixChangeBits != 0 || (*(uint *)(glContext + 0x505c) & *(uint *)(glContext + 0x50b0)) != 0) {
      _gleUpdateMatrixFunc(glContext);
      fparam_1 = extraout_f1;
    }
    if (*(char *)(glContext + 0x4691) != '\0') {
      framebufferObject = *(int *)(glContext + 0x744c);
      piVar12 = (int *)(glContext + 0x310);
      cVar2 = *(char *)(*(int *)(glContext + 0x468c) + 0x79);
      if ((framebufferObject != 0) && (*(int *)(framebufferObject + 0xec) != 0)) {
        ((void (*)())_gleUpdateFramebufferCompleteness)(glContext,framebufferObject + 0x10,uVar3,uVar7,uVar8,iVar10,matrixChangeBits,fparam_1,forwardedFloatArg2,forwardedFloatArg3,
                   forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
        *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x80000000;
      }
      if ((*(char *)(glContext + 0x4664) == '\0') && (*(int *)(glContext + 0x5430) == 0)) {
LAB_00060eb8:
        uVar11 = *(uint *)(glContext + 0x31c);
      }
      else {
        loopIndex = 0;
        srcCursor = (int *)(glContext + 0x324);
        do {
          iVar9 = *srcCursor;
          srcCursor = srcCursor + 1;
          if (iVar9 != 0) {
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
          goto LAB_00060eb8;
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
              goto LAB_00060ff8;
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
    iVar10 = _gleCheckCopyColorSubTableArgs(glContext,target,start,width);
    if (iVar10 == 0) {
      return;
    }
    iVar9 = iVar10 + 0xac;
    bVar5 = *(byte *)(iVar10 + 0xb7);
    if ((bVar5 & 0x10) == 0) {
      if ((bVar5 & 0x40) == 0) {
        if (*(int *)(iVar10 + 0xc0) == 0) {
          _gleAllocateTextureLevel(glContext,iVar10,iVar9);
          bVar5 = *(byte *)(iVar10 + 0xb7);
        }
        *(byte *)(iVar10 + 0xb7) = bVar5 | 0x10;
      }
      else {
        _gleUploadPluginTextureLevel
                  (glContext,iVar10,iVar9,0,0xffffffff,(uint)*(byte *)(glContext + 0x85a8));
      }
    }
    iVar6 = glContext + 0x33d0;
    _gleModifyPluginTextureLevel(glContext,iVar10,iVar9,0,0xffffffff,start,0,0,width,1,1);
    if (target != 0x80d1) {
      if (target < 0x80d2) {
        iVar6 = glContext + 0x33b0;
        uVar11 = 0x80d0;
      }
      else {
        iVar6 = glContext + 0x33f0;
        uVar11 = 0x80d2;
      }
      if (target != uVar11) {
        iVar6 = 0;
      }
    }
    _gleTextureSubImageCopy(glContext,iVar9,start,0,0,x,y,width,1);
    if (iVar6 != 0) {
      _gleImagingScaleAndBias
                (glContext,iVar6,*(undefined4 *)(iVar10 + 0xc0),(uint)*(ushort *)(iVar10 + 0xbc),
                 start,width,1);
      *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x40000000;
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
LAB_00060ff8:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glCopyColorSubTable_CompExec @ 0x6118c (88 bytes) */
void _glCopyColorSubTable_CompExec(glContext, target, start, x, y, width)
  undefined4 glContext;
  undefined4 target;
  undefined4 start;
  undefined4 x;
  undefined4 y;
  undefined4 width;
{
  double forwardedFloatArg1;
  double incomingFpr2;
  double incomingFpr3;
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  
  ((int (*)())_glCopyColorSubTable_Comp)(glContext,target,start,x,y,width);
  ((void (*)())_glCopyColorSubTable_Exec)(glContext,target,start,x,y,width,forwardedFloatArg1,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,
             incomingFpr7,incomingFpr8);
  return;
}

/* _glGetColorTable_Exec @ 0x611e4 (852 bytes) */
void _glGetColorTable_Exec(glContext, target, format, type, table)
  int glContext;
  undefined4 target;
  uint format;
  uint type;
  int table;
{
  undefined4 glErrorCode;
  bool bVar1;
  byte bVar2;
  undefined4 rowBytes;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  uint uVar9;
  uint glContextByte31c8;
  undefined1 *puVar11;
  int *piVar12;
  int pixelPackBuffer;
  int iVar14;
  double dVar15;
  undefined4 local_d0;
  undefined4 local_cc;
  undefined4 local_c8;
  undefined4 local_c4;
  int local_c0;
  undefined4 local_bc;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined4 local_b0;
  uint local_ac;
  undefined4 local_a8;
  uint local_a4;
  uint local_a0;
  undefined1 local_64;
  undefined4 local_60;
  undefined1 auStack_5c [4];
  undefined1 auStack_58 [4];
  undefined1 auStack_54 [4];
  undefined1 auStack_50 [4];
  int local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c [5];
  
  iVar4 = _gleLookUpNonProxyColorTable(glContext,target);
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (iVar4 != 0) {
      if (type < 0x8037) {
        if (0x8032 < type) {
LAB_000612b0:
          if (format != 0x1908) {
            bVar1 = format == 0x80e1;
LAB_000612c4:
            if (!bVar1) goto LAB_00061354;
          }
LAB_000612e0:
          pixelPackBuffer = *(int *)(glContext + 0x4a68);
          if (pixelPackBuffer == 0) {
LAB_0006138c:
            bVar2 = *(byte *)(iVar4 + 0xb7);
            if ((bVar2 & 0x20) == 0) {
              return;
            }
            if ((bVar2 & 0x40) == 0) {
              if ((bVar2 & 0x10) == 0) {
                return;
              }
            }
            else {
              _gleUploadPluginTextureLevel
                        (glContext,iVar4,iVar4 + 0xac,0,0xffffffff,(uint)*(byte *)(glContext + 0x85a8));
            }
            uVar9 = (uint)*(ushort *)(iVar4 + 0xb2);
            puVar11 = auStack_50;
            piVar12 = &local_4c;
            _glePixelPackSettings
                      (glContext,format,type,(uint)*(ushort *)(iVar4 + 0xb0),uVar9,
                       glContext + 0x31b0,puVar11,piVar12,&local_60,auStack_5c,auStack_58,auStack_54);
            if (((((*(byte *)(iVar4 + 0xb7) & 1) == 0) ||
                 (table + local_4c != *(int *)(iVar4 + 0xc0))) ||
                (format != *(ushort *)(iVar4 + 0xbc))) || (type != *(ushort *)(iVar4 + 0xbe))) {
              glContextByte31c8 = (uint)*(byte *)(glContext + 0x31c8);
            }
            else {
              glContextByte31c8 = (uint)*(byte *)(glContext + 0x31c8);
              if (glContextByte31c8 == 0) {
                return;
              }
            }
            local_ac = (uint)(glContextByte31c8 != 0);
            rowBytes = _gleRowBytes((uint)*(ushort *)(iVar4 + 0xbc),(uint)*(ushort *)(iVar4 + 0xbe),
                                 (uint)*(ushort *)(iVar4 + 0xb8));
            _glgConvertType((uint)*(ushort *)(iVar4 + 0xbc),(uint)*(ushort *)(iVar4 + 0xbe),
                            &local_48,&local_44,uVar9,glContextByte31c8,puVar11,piVar12);
            puVar7 = &local_40;
            puVar8 = local_3c;
            _glgConvertType(format,type,puVar7,puVar8,uVar9,glContextByte31c8,puVar11,piVar12);
            local_c8 = local_48;
            local_c4 = local_44;
            local_bc = local_60;
            local_b8 = local_40;
            local_b4 = local_3c[0];
            local_a8 = 1;
            local_b0 = 2;
            local_a4 = (uint)*(ushort *)(iVar4 + 0xb0);
            local_a0 = (uint)*(ushort *)(iVar4 + 0xb2);
            local_c0 = table + local_4c;
            local_d0 = *(undefined4 *)(iVar4 + 0xc0);
            local_64 = 0;
            local_cc = rowBytes;
            _glgProcessPixels(glContext + 0x31a8,&local_d0,puVar7,puVar8,uVar9,glContextByte31c8,local_a0,piVar12
                             );
            return;
          }
          iVar5 = _gleOffsetLimitImage
                            (glContext + 0x31b0,(uint)*(ushort *)(iVar4 + 0xb0),
                             (uint)*(ushort *)(iVar4 + 0xb2),format,type,table);
          iVar14 = *(int *)(pixelPackBuffer + 0x38);
          dVar15 = (double)((double (*)())_gleBytesPerElement)(type);
          iVar6 = (int)dVar15;
          if (iVar5 <= iVar14) {
            if (iVar6 == 0) {
              iVar6 = _glePixelBytes(format,type);
            }
            if (table == (table / iVar6) * iVar6) {
              if (*(int *)(pixelPackBuffer + 0x40) != 0) {
                _gleSynchronizePluginBuffer(glContext,pixelPackBuffer + 0x10);
              }
              table = table + *(int *)(pixelPackBuffer + 0x30);
              goto LAB_0006138c;
            }
          }
          goto LAB_00061354;
        }
        if (0x13ff < type) {
          if (type < 0x1407) {
            if (format != 0x8000) {
              if (format < 0x8001) {
                bVar1 = 7 < format - 0x1903;
              }
              else {
                bVar1 = 1 < format - 0x80e0;
              }
              if (bVar1) goto LAB_00061354;
            }
            goto LAB_000612e0;
          }
          if (type == 0x8032) goto LAB_000612a8;
        }
      }
      else if (0x8361 < type) {
        if (type < 0x8365) {
LAB_000612a8:
          bVar1 = format == 0x1907;
          goto LAB_000612c4;
        }
        if (type < 0x8369) goto LAB_000612b0;
      }
    }
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x500;
  }
  else {
LAB_00061354:
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
  }
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glColorTableParameterfv_ListExec @ 0x61538 (52 bytes) */
int _glColorTableParameterfv_ListExec(glContext, recordedArgs)
  undefined4 glContext;
  undefined4 *recordedArgs;
{
  ((void (*)())_glColorTableParameterfv_Exec)(glContext,*recordedArgs,recordedArgs[1],recordedArgs + 2);
  return 0x18;
}

/* _glColorTableParameterfv_Comp @ 0x6156c (136 bytes) */
int _glColorTableParameterfv_Comp(glContext, target, pname, params)
  undefined4 glContext;
  undefined4 target;
  int pname;
  undefined4 *params;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)
           _gleAddListItem(glContext,PTR__glColorTableParameterfv_ListExec_0011007c,0x18);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = target;
    puVar1[1] = pname;
    if (pname - 0x80d6U < 2) {
      puVar1[2] = *params;
      puVar1[3] = params[1];
      puVar1[4] = params[2];
      puVar1[5] = params[3];
    }
  }
  return puVar1;
}

/* _glColorTableParameterfv_Exec @ 0x615f4 (260 bytes) */
void _glColorTableParameterfv_Exec(glContext, target, pname, params)
  int glContext;
  undefined4 target;
  int pname;
  undefined4 *params;
{
  undefined4 glErrorCode;
  undefined4 *puVar2;
  
  if (-1 < *(short *)(glContext + 0x4a10)) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
    goto LAB_00061690;
  }
  switch(target) {
  case 0x80d0:
  case 0x80d3:
    puVar2 = (undefined4 *)(glContext + 0x33b0);
    break;
  case 0x80d1:
  case 0x80d4:
    puVar2 = (undefined4 *)(glContext + 0x33d0);
    break;
  case 0x80d2:
  case 0x80d5:
    puVar2 = (undefined4 *)(glContext + 0x33f0);
    break;
  default:
    goto switchD_0006164c_default;
  }
  if (pname == 0x80d6) {
    *puVar2 = *params;
    puVar2[2] = params[1];
    puVar2[4] = params[2];
    puVar2[6] = params[3];
  }
  else {
    if (pname != 0x80d7) {
switchD_0006164c_default:
      if (*(int *)(glContext + 0x7574) != 0) {
        return;
      }
      glErrorCode = 0x500;
LAB_00061690:
      *(undefined4 *)(glContext + 0x7574) = glErrorCode;
      return;
    }
    puVar2[1] = *params;
    puVar2[3] = params[1];
    puVar2[5] = params[2];
    puVar2[7] = params[3];
  }
  *(uint *)(glContext + 0x314) = *(uint *)(glContext + 0x314) | 0x40000000;
  return;
}

/* _glColorTableParameterfv_CompExec @ 0x61710 (72 bytes) */
void _glColorTableParameterfv_CompExec(glContext, target, pname, params)
  undefined4 glContext;
  undefined4 target;
  undefined4 pname;
  undefined4 params;
{
  ((int (*)())_glColorTableParameterfv_Comp)(glContext,target,pname,params);
  ((void (*)())_glColorTableParameterfv_Exec)(glContext,target,pname,params);
  return;
}

/* _glColorTableParameteriv_ListExec @ 0x61758 (52 bytes) */
int _glColorTableParameteriv_ListExec(glContext, recordedArgs)
  undefined4 glContext;
  undefined4 *recordedArgs;
{
  ((void (*)())_glColorTableParameteriv_Exec)(glContext,*recordedArgs,recordedArgs[1],recordedArgs + 2);
  return 0x18;
}

/* _glColorTableParameteriv_Comp @ 0x6178c (136 bytes) */
int _glColorTableParameteriv_Comp(glContext, target, pname, params)
  undefined4 glContext;
  undefined4 target;
  int pname;
  undefined4 *params;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)
           _gleAddListItem(glContext,PTR__glColorTableParameteriv_ListExec_00110078,0x18);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = target;
    puVar1[1] = pname;
    if (pname - 0x80d6U < 2) {
      puVar1[2] = *params;
      puVar1[3] = params[1];
      puVar1[4] = params[2];
      puVar1[5] = params[3];
    }
  }
  return puVar1;
}

/* _glColorTableParameteriv_Exec @ 0x61814 (476 bytes) */
void _glColorTableParameteriv_Exec(glContext, target, pname, params)
  int glContext;
  undefined4 target;
  int pname;
  uint *params;
{
  double intToDoubleMagic;
  undefined4 glErrorCode;
  float *pfVar3;
  
  intToDoubleMagic = DOUBLE_00108d58;
  if (-1 < *(short *)(glContext + 0x4a10)) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
    goto LAB_000618b0;
  }
  switch(target) {
  case 0x80d0:
  case 0x80d3:
    pfVar3 = (float *)(glContext + 0x33b0);
    break;
  case 0x80d1:
  case 0x80d4:
    pfVar3 = (float *)(glContext + 0x33d0);
    break;
  case 0x80d2:
  case 0x80d5:
    pfVar3 = (float *)(glContext + 0x33f0);
    break;
  default:
    goto switchD_0006186c_default;
  }
  if (pname == 0x80d6) {
    *pfVar3 = (float)((double)CONCAT44(0x43300000,*params ^ 0x80000000) - DOUBLE_00108d58);
    pfVar3[2] = (float)((double)CONCAT44(0x43300000,params[1] ^ 0x80000000) - intToDoubleMagic);
    pfVar3[4] = (float)((double)CONCAT44(0x43300000,params[2] ^ 0x80000000) - intToDoubleMagic);
    pfVar3[6] = (float)((double)CONCAT44(0x43300000,params[3] ^ 0x80000000) - intToDoubleMagic);
  }
  else {
    if (pname != 0x80d7) {
switchD_0006186c_default:
      if (*(int *)(glContext + 0x7574) != 0) {
        return;
      }
      glErrorCode = 0x500;
LAB_000618b0:
      *(undefined4 *)(glContext + 0x7574) = glErrorCode;
      return;
    }
    pfVar3[1] = (float)((double)CONCAT44(0x43300000,*params ^ 0x80000000) - DOUBLE_00108d58);
    pfVar3[3] = (float)((double)CONCAT44(0x43300000,params[1] ^ 0x80000000) - intToDoubleMagic);
    pfVar3[5] = (float)((double)CONCAT44(0x43300000,params[2] ^ 0x80000000) - intToDoubleMagic);
    pfVar3[7] = (float)((double)CONCAT44(0x43300000,params[3] ^ 0x80000000) - intToDoubleMagic);
  }
  *(uint *)(glContext + 0x314) = *(uint *)(glContext + 0x314) | 0x40000000;
  return;
}

/* _glColorTableParameteriv_CompExec @ 0x61a08 (72 bytes) */
void _glColorTableParameteriv_CompExec(glContext, target, pname, params)
  undefined4 glContext;
  undefined4 target;
  undefined4 pname;
  undefined4 params;
{
  ((int (*)())_glColorTableParameteriv_Comp)(glContext,target,pname,params);
  ((void (*)())_glColorTableParameteriv_Exec)(glContext,target,pname,params);
  return;
}

/* _glGetColorTableParameterfv_Exec @ 0x61a50 (368 bytes) */
void _glGetColorTableParameterfv_Exec(glContext, target, pname, params)
  int glContext;
  undefined4 target;
  undefined4 pname;
  float *params;
{
  float fVar1;
  ushort uVar2;
  undefined4 glErrorCode;
  int iVar4;
  float *pfVar5;
  
  iVar4 = _gleLookUpColorTable(glContext,target);
  if (-1 < *(short *)(glContext + 0x4a10)) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
    goto LAB_00061be8;
  }
  if (iVar4 == 0) {
switchD_00061acc_default:
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x500;
LAB_00061be8:
    *(undefined4 *)(glContext + 0x7574) = glErrorCode;
    return;
  }
  switch(target) {
  case 0x80d0:
  case 0x80d3:
    pfVar5 = (float *)(glContext + 0x33b0);
    break;
  case 0x80d1:
  case 0x80d4:
    pfVar5 = (float *)(glContext + 0x33d0);
    break;
  case 0x80d2:
  case 0x80d5:
    pfVar5 = (float *)(glContext + 0x33f0);
    break;
  default:
    goto switchD_00061acc_default;
  }
  switch(pname) {
  case 0x80d6:
    *params = *pfVar5;
    params[1] = pfVar5[2];
    params[2] = pfVar5[4];
    fVar1 = pfVar5[6];
    break;
  case 0x80d7:
    *params = pfVar5[1];
    params[1] = pfVar5[3];
    params[2] = pfVar5[5];
    fVar1 = pfVar5[7];
    break;
  case 0x80d8:
    uVar2 = *(ushort *)(iVar4 + 0xbc);
    goto LAB_00061ba4;
  case 0x80d9:
    uVar2 = *(ushort *)(iVar4 + 0xb0);
LAB_00061ba4:
    *params = GH_U2F((unsigned int)((uVar2 | 0x4b000000))) - 8388608.0;
    return;
  case 0x80da:
  case 0x80db:
  case 0x80dc:
  case 0x80dd:
  case 0x80de:
  case 0x80df:
    *params = 8.0;
    return;
  default:
    goto switchD_00061acc_default;
  }
  params[3] = fVar1;
  return;
}

/* _glGetColorTableParameteriv_Exec @ 0x61c00 (416 bytes) */
void _glGetColorTableParameteriv_Exec(glContext, target, pname, params)
  int glContext;
  undefined4 target;
  undefined4 pname;
  uint *params;
{
  float fVar1;
  undefined4 glErrorCode;
  uint uVar3;
  int iVar4;
  float *pfVar5;
  
  iVar4 = _gleLookUpColorTable(glContext,target);
  if (-1 < *(short *)(glContext + 0x4a10)) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
    goto LAB_00061dc8;
  }
  if (iVar4 == 0) {
switchD_00061c7c_default:
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x500;
LAB_00061dc8:
    *(undefined4 *)(glContext + 0x7574) = glErrorCode;
    return;
  }
  switch(target) {
  case 0x80d0:
  case 0x80d3:
    pfVar5 = (float *)(glContext + 0x33b0);
    break;
  case 0x80d1:
  case 0x80d4:
    pfVar5 = (float *)(glContext + 0x33d0);
    break;
  case 0x80d2:
  case 0x80d5:
    pfVar5 = (float *)(glContext + 0x33f0);
    break;
  default:
    goto switchD_00061c7c_default;
  }
  switch(pname) {
  case 0x80d6:
    *params = (int)*pfVar5;
    params[1] = (int)pfVar5[2];
    params[2] = (int)pfVar5[4];
    fVar1 = pfVar5[6];
    goto LAB_00061d88;
  case 0x80d7:
    *params = (int)pfVar5[1];
    params[1] = (int)pfVar5[3];
    params[2] = (int)pfVar5[5];
    fVar1 = pfVar5[7];
LAB_00061d88:
    params[3] = (int)fVar1;
    return;
  case 0x80d8:
    uVar3 = (uint)*(ushort *)(iVar4 + 0xbc);
    break;
  case 0x80d9:
    uVar3 = (uint)*(ushort *)(iVar4 + 0xb0);
    break;
  case 0x80da:
  case 0x80db:
  case 0x80dc:
  case 0x80dd:
  case 0x80de:
  case 0x80df:
    uVar3 = 8;
    break;
  default:
    goto switchD_00061c7c_default;
  }
  *params = uVar3;
  return;
}

/* _glCopyPixels_ListExec @ 0x61de0 (876 bytes) */
undefined4 _glCopyPixels_ListExec(int glContext,undefined4 *recordedArgs,double fparam_1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
{
  int remaining;
  int loopIndex;
  bool bVar1;
  char cVar2;
  uint uVar3;
  uint glContextWord4e1c;
  undefined4 glErrorCode;
  int glContextPtr4854;
  int *srcCursor;
  int iVar7;
  int framebufferObject;
  undefined4 incomingR5;
  undefined4 incomingR6;
  undefined4 incomingR7;
  undefined4 incomingR8;
  int matrixChangeBits;
  int *piVar9;
  float *pfVar10;
  double extraout_f1;
  
  glContextPtr4854 = *(int *)(glContext + 0x4854);
  pfVar10 = (float *)(glContextPtr4854 + -0x200);
  if (*(char *)(glContext + 0x2ef) == '\0') {
    return 0x14;
  }
  glContextWord4e1c = *(uint *)(glContext + 0x4e1c);
  if (glContextWord4e1c == 0x1c01) {
    *(undefined4 *)(glContextPtr4854 + -0x200) = *(undefined4 *)(glContext + 0x2e0);
    *(undefined4 *)(glContextPtr4854 + -0x1fc) = *(undefined4 *)(glContext + 0x2e4);
    *(undefined4 *)(glContextPtr4854 + -0x1f8) = *(undefined4 *)(glContext + 0x2e8);
    _gleFeedbackCopyPixels(glContext,pfVar10);
    return 0x14;
  }
  if (glContextWord4e1c < 0x1c02) {
    if (glContextWord4e1c == 0x1c00) {
      if (*(float *)(glContext + 0x31a8) == FLOAT_00108e50) {
        return 0x14;
      }
      if (*(float *)(glContext + 0x31ac) == FLOAT_00108e50) {
        return 0x14;
      }
      if (recordedArgs[2] == 0) {
        return 0x14;
      }
      if (recordedArgs[3] == 0) {
        return 0x14;
      }
      matrixChangeBits = *(int *)(glContext + 0x50ac);
      if (matrixChangeBits != 0 || (*(uint *)(glContext + 0x505c) & *(uint *)(glContext + 0x50b0)) != 0) {
        _gleUpdateMatrixFunc(glContext);
        fparam_1 = extraout_f1;
      }
      if (*(char *)(glContext + 0x4691) == '\0') goto LAB_00062098;
      framebufferObject = *(int *)(glContext + 0x744c);
      piVar9 = (int *)(glContext + 0x310);
      cVar2 = *(char *)(*(int *)(glContext + 0x468c) + 0x79);
      if ((framebufferObject != 0) && (*(int *)(framebufferObject + 0xec) != 0)) {
        ((void (*)())_gleUpdateFramebufferCompleteness)(glContext,framebufferObject + 0x10,incomingR5,incomingR6,incomingR7,incomingR8,matrixChangeBits,fparam_1,forwardedFloatArg2,forwardedFloatArg3,
                   forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
        *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x80000000;
      }
      if ((*(char *)(glContext + 0x4664) == '\0') && (*(int *)(glContext + 0x5430) == 0)) {
LAB_00061f74:
        uVar3 = *(uint *)(glContext + 0x31c);
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
        uVar3 = *(uint *)(glContext + 0x31c);
        if ((uVar3 & 0x15555) != 0) {
          if (*(char *)(glContext + 0x2e54) != '\0') {
            _gleUpdateLightRGBASums(glContext,glContext + 0x2c20,0);
          }
          if (*(char *)(glContext + 0x3094) != '\0') {
            _gleUpdateLightRGBASums(glContext,glContext + 0x2e60,1);
          }
          goto LAB_00061f74;
        }
      }
      bVar1 = cVar2 == '\0';
      if (bVar1) {
        uVar3 = uVar3 & 0x17000000;
      }
      else {
        uVar3 = uVar3 & 0x17ffffff;
      }
      if (bVar1) {
        bVar1 = ((*piVar9 == 0 && *(int *)(glContext + 0x314) == 0) && uVar3 == 0) &&
                *(int *)(glContext + 800) == 0;
      }
      else {
        bVar1 = (((*piVar9 == 0 && *(int *)(glContext + 0x314) == 0) &&
                 (*(uint *)(glContext + 0x318) & 0xfffffffd) == 0) && uVar3 == 0) &&
                *(int *)(glContext + 800) == 0;
      }
      if (!bVar1) {
        if (*(char *)(glContext + 0x85a8) == *(char *)(glContext + 0x85a6)) {
          uVar3 = (**(code **)(glContext + 0x4788))
                            (*(undefined4 *)(glContext + 0x4688),glContext + 0x4698,piVar9);
          if ((((uVar3 & 3) != (uint)*(byte *)(glContext + 0x7580)) ||
              ((uVar3 & 4) != (uint)*(byte *)(glContext + 0x7581))) ||
             ((uVar3 & 8) != (uint)(*(char *)(glContext + 0x759d) == '\0'))) {
            if ((uVar3 & 4) == 0) {
              uVar3 = uVar3 & 0xfffffffe;
              *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x10000000;
            }
            _gleUpdateDispatchCodeChange(glContext,uVar3);
            if (*(char *)(glContext + 0x759d) == '\0') {
              if (*(int *)(glContext + 0x7574) != 0) {
                return 0x14;
              }
              glErrorCode = 0x506;
              goto LAB_00062130;
            }
          }
        }
        else {
          _gleSwitchToNonRevertRenderer(glContext);
        }
        remaining = 0x13;
        do {
          *piVar9 = 0;
          piVar9 = piVar9 + 1;
          remaining = remaining + -1;
        } while (remaining != 0);
      }
LAB_00062098:
      *pfVar10 = *(float *)(glContext + 0x4a44) * *(float *)(glContext + 0x2e0) +
                 *(float *)(glContext + 0x4a48);
      *(float *)(glContextPtr4854 + -0x1fc) =
           *(float *)(glContext + 0x4a4c) * *(float *)(glContext + 0x2e4) + *(float *)(glContext + 0x4a50)
      ;
      *(float *)(glContextPtr4854 + -0x1f8) = *(float *)(glContext + 0x4a54) * *(float *)(glContext + 0x2e8);
      (**(code **)(glContext + 0x46a8))
                (*(undefined4 *)(glContext + 0x4688),pfVar10,*recordedArgs,recordedArgs[1],recordedArgs[2],recordedArgs[3]
                 ,recordedArgs[4]);
      return 0x14;
    }
  }
  else if (glContextWord4e1c == 0x1c02) {
    return 0x14;
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return 0x14;
  }
  glErrorCode = 0x500;
LAB_00062130:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return 0x14;
}

/* _glCopyPixels_Comp @ 0x6214c (216 bytes) */
int _glCopyPixels_Comp(glContext, x, y, width, height, type)
  int glContext;
  undefined4 x;
  undefined4 y;
  int width;
  int height;
  int type;
{
  undefined4 glErrorCode;
  undefined4 *listRecord;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    if ((width < 0) || (height < 0)) {
      if (*(int *)(glContext + 0x7574) != 0) {
        return glContext;
      }
      glErrorCode = 0x501;
    }
    else {
      if (type - 0x1800U < 3) {
        listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glCopyPixels_ListExec_00110080,0x14);
        if (listRecord == (undefined4 *)0x0) {
          return 0;
        }
        listRecord[4] = type;
        *listRecord = x;
        listRecord[1] = y;
        listRecord[2] = width;
        listRecord[3] = height;
        return (int)listRecord;
      }
      if (*(int *)(glContext + 0x7574) != 0) {
        return glContext;
      }
      glErrorCode = 0x500;
    }
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

/* _glCopyPixels_CompExec @ 0x62224 (88 bytes) */
void _glCopyPixels_CompExec(glContext, x, y, width, height, type)
  undefined4 glContext;
  undefined4 x;
  undefined4 y;
  undefined4 width;
  undefined4 height;
  undefined4 type;
{
  double forwardedFloatArg1;
  double incomingFpr2;
  double incomingFpr3;
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  
  ((int (*)())_glCopyPixels_Comp)(glContext,x,y,width,height,type);
  ((void (*)())_glCopyPixels_Exec)(glContext,x,y,width,height,type,forwardedFloatArg1,incomingFpr2,incomingFpr3,incomingFpr4,
                     incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8);
  return;
}

