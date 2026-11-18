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
  byte tableFlags;
  ushort objectFlags;
  uint nonProxyTarget;
  uint target;
  int colorTable;
  int createdColorTableLevel;
  int recordSize;
  uint *pixels;
  int tableSlot;
  int createdLevel;
  int textureLevel;
  
  recordSize = recordedArgs[5] + 0x18;
  colorTable = _gleCheckColorTableArgs(glContext,*recordedArgs,recordedArgs[1],recordedArgs[2],recordedArgs[3],recordedArgs[4]);
  if (colorTable != 0) {
    objectFlags = *(ushort *)(colorTable + 0x24);
    if ((objectFlags & 0x3c00) != 0x1000) {
      if ((objectFlags & 0x3c00) == 0) {
        *(ushort *)(colorTable + 0x24) = objectFlags | 0x1000;
      }
      else if ((objectFlags & 0xc00) != 0) {
        if (*(int *)(glContext + 0x7574) != 0) {
          return recordSize;
        }
        *(undefined4 *)(glContext + 0x7574) = 0x502;
        return recordSize;
      }
    }
    textureLevel = colorTable + 0xac;
    if ((*(byte *)(colorTable + 0xb7) & 0x20) != 0) {
      _gleDeletePluginTextureLevel(glContext,colorTable,textureLevel,0,0xffffffff);
      if (*(int *)(colorTable + 0xc0) != 0) {
        tableFlags = *(byte *)(colorTable + 0xb7);
        if ((tableFlags & 1) == 0) {
          _gleFreeTextureLevel(glContext,colorTable,textureLevel);
          tableFlags = *(byte *)(colorTable + 0xb7);
        }
        else {
          *(undefined4 *)(colorTable + 0xc0) = 0;
        }
        *(byte *)(colorTable + 0xb7) = tableFlags & 0xef;
      }
      *(byte *)(colorTable + 0xb7) = *(byte *)(colorTable + 0xb7) & 0xdf;
    }
    target = *recordedArgs;
    tableSlot = glContext + 0x33d0;
    if (target != 0x80d1) {
      if (target < 0x80d2) {
        tableSlot = glContext + 0x33b0;
        nonProxyTarget = 0x80d0;
      }
      else {
        tableSlot = glContext + 0x33f0;
        nonProxyTarget = 0x80d2;
      }
      if (target != nonProxyTarget) {
        tableSlot = 0;
      }
    }
    pixels = recordedArgs + 6;
    if (tableSlot == 0) {
      createdLevel = _gleCreateTextureLevel
                        (glContext,colorTable,textureLevel,recordedArgs[1],recordedArgs[2],1,1,0,recordedArgs[3],recordedArgs[4],0,
                         pixels);
      if (createdLevel != 0) {
        _gleTextureImagePut(glContext,textureLevel,0,0,0,recordedArgs[2],1,1,recordedArgs[3],recordedArgs[4],0,0,pixels);
      }
      *(uint *)(glContext + 0x314) =
           *(uint *)(glContext + 0x314) | 1 << (*(uint *)(glContext + 0x53d4) & 0x3f);
    }
    else {
      createdColorTableLevel = _gleCreateColorTableLevel
                        (glContext,colorTable,textureLevel,recordedArgs[1],recordedArgs[2],recordedArgs[3],recordedArgs[4],pixels);
      if ((createdColorTableLevel != 0) && (pixels != (uint *)0x0)) {
        _gleColorTable(glContext,tableSlot,textureLevel,recordedArgs[2],recordedArgs[3],recordedArgs[4],pixels);
      }
      *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x40000000;
    }
    _gleCreatePluginTextureLevel(glContext,colorTable,textureLevel,0,0xffffffff,recordedArgs[1]);
  }
  return recordSize;
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
  int imageEndOffset;
  int iVar5;
  int pixelBytes;
  uint *listRecord;
  int iVar7;
  int pixelUnpackBuffer;
  double bytesPerElement;
  
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
    imageEndOffset = _gleOffsetLimitImage(glContext + 0x31cc,width,1,format,type,table);
    iVar7 = *(int *)(pixelUnpackBuffer + 0x38);
    bytesPerElement = (double)((double (*)())_gleBytesPerElement)(type);
    iVar5 = (int)bytesPerElement;
    if (imageEndOffset <= iVar7) {
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
  int imageEndOffset;
  int iVar7;
  int iVar8;
  int colorTable;
  int pixelUnpackBuffer;
  double bytesPerElement;
  
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
      colorTable = _gleCheckColorTableArgs(glContext,target,internalformat,width,format,type);
      if (colorTable == 0) {
        return;
      }
      uVar3 = *(ushort *)(colorTable + 0x24);
      if ((uVar3 & 0x3c00) == 0x1000) {
LAB_0005fd34:
        iVar7 = colorTable + 0xac;
        if ((*(byte *)(colorTable + 0xb7) & 0x20) != 0) {
          _gleDeletePluginTextureLevel(glContext,colorTable,iVar7,0,0xffffffff);
          if (*(int *)(colorTable + 0xc0) != 0) {
            bVar2 = *(byte *)(colorTable + 0xb7);
            if ((bVar2 & 1) == 0) {
              _gleFreeTextureLevel(glContext,colorTable,iVar7);
              bVar2 = *(byte *)(colorTable + 0xb7);
            }
            else {
              *(undefined4 *)(colorTable + 0xc0) = 0;
            }
            *(byte *)(colorTable + 0xb7) = bVar2 & 0xef;
          }
          *(byte *)(colorTable + 0xb7) = *(byte *)(colorTable + 0xb7) & 0xdf;
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
                            (glContext,colorTable,iVar7,internalformat,width,1,1,0,format,type,1,table);
          if ((iVar6 != 0) && (bVar1)) {
            _gleTextureImagePut(glContext,iVar7,0,0,0,width,1,1,format,type,0,glContext + 0x31cc,
                                table);
          }
          *(uint *)(glContext + 0x314) =
               *(uint *)(glContext + 0x314) | 1 << (*(uint *)(glContext + 0x53d4) & 0x3f);
        }
        else {
          iVar8 = _gleCreateColorTableLevel
                            (glContext,colorTable,iVar7,internalformat,width,format,type,table);
          if ((iVar8 != 0) && (bVar1)) {
            _gleColorTable(glContext,iVar6,iVar7,width,format,type,table);
          }
          *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x40000000;
        }
        if (width == 0) {
          return;
        }
        _gleCreatePluginTextureLevel(glContext,colorTable,iVar7,0,0xffffffff,internalformat);
        return;
      }
      if ((uVar3 & 0x3c00) == 0) {
        *(ushort *)(colorTable + 0x24) = uVar3 | 0x1000;
        goto LAB_0005fd34;
      }
      if ((uVar3 & 0xc00) == 0) goto LAB_0005fd34;
    }
  }
  else {
    imageEndOffset = _gleOffsetLimitImage(glContext + 0x31cc,width,1,format,type,table);
    iVar8 = *(int *)(pixelUnpackBuffer + 0x38);
    bytesPerElement = (double)((double (*)())_gleBytesPerElement)(type);
    iVar7 = (int)bytesPerElement;
    if (imageEndOffset <= iVar8) {
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
  int colorTable;
  int textureLevel;
  
  uVar2 = recordedArgs[5];
  if (*(short *)(glContext + 0x4a10) < 0) {
    colorTable = _gleCheckColorSubTableArgs(glContext,*recordedArgs,recordedArgs[1],recordedArgs[2],recordedArgs[3],recordedArgs[4])
    ;
    if (colorTable != 0) {
      textureLevel = colorTable + 0xac;
      bVar4 = *(byte *)(colorTable + 0xb7);
      if ((bVar4 & 0x10) == 0) {
        if ((bVar4 & 0x40) == 0) {
          if (*(int *)(colorTable + 0xc0) == 0) {
            _gleAllocateTextureLevel(glContext,colorTable,textureLevel);
            bVar4 = *(byte *)(colorTable + 0xb7);
          }
          *(byte *)(colorTable + 0xb7) = bVar4 | 0x10;
        }
        else {
          _gleUploadPluginTextureLevel
                    (glContext,colorTable,textureLevel,0,0xffffffff,(uint)*(byte *)(glContext + 0x85a8));
        }
      }
      _gleModifyPluginTextureLevel(glContext,colorTable,textureLevel,0,0xffffffff,recordedArgs[1],0,0,recordedArgs[2],1,1);
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
  int imageEndOffset;
  int iVar5;
  int pixelBytes;
  uint *listRecord;
  int iVar7;
  int pixelUnpackBuffer;
  double bytesPerElement;
  
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
    imageEndOffset = _gleOffsetLimitImage(glContext + 0x31cc,count,1,format,type,data);
    iVar7 = *(int *)(pixelUnpackBuffer + 0x38);
    bytesPerElement = (double)((double (*)())_gleBytesPerElement)(type);
    iVar5 = (int)bytesPerElement;
    if (imageEndOffset <= iVar7) {
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
  int imageEndOffset;
  int iVar4;
  int iVar5;
  int colorTable;
  int pixelUnpackBuffer;
  int iVar6;
  double bytesPerElement;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    pixelUnpackBuffer = *(int *)(glContext + 0x4a6c);
    if (pixelUnpackBuffer == 0) {
LAB_000604f4:
      if (count == 0) {
        return;
      }
      colorTable = _gleCheckColorSubTableArgs(glContext,target,start,count,format,type);
      if (colorTable == 0) {
        return;
      }
      iVar4 = colorTable + 0xac;
      bVar2 = *(byte *)(colorTable + 0xb7);
      if ((bVar2 & 0x10) == 0) {
        if ((bVar2 & 0x40) == 0) {
          if (*(int *)(colorTable + 0xc0) == 0) {
            _gleAllocateTextureLevel(glContext,colorTable,iVar4);
            bVar2 = *(byte *)(colorTable + 0xb7);
          }
          *(byte *)(colorTable + 0xb7) = bVar2 | 0x10;
        }
        else {
          _gleUploadPluginTextureLevel
                    (glContext,colorTable,iVar4,0,0xffffffff,(uint)*(byte *)(glContext + 0x85a8));
        }
      }
      _gleModifyPluginTextureLevel(glContext,colorTable,iVar4,0,0xffffffff,start,0,0,count,1,1);
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
    imageEndOffset = _gleOffsetLimitImage(glContext + 0x31cc,count,1,format,type,data);
    iVar6 = *(int *)(pixelUnpackBuffer + 0x38);
    bytesPerElement = (double)((double (*)())_gleBytesPerElement)(type);
    iVar4 = (int)bytesPerElement;
    if (imageEndOffset <= iVar6) {
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
void _glCopyColorTable_Exec(int glContext,uint target,undefined4 internalformat,undefined4 x,undefined4 y,undefined4 width,double forwardedFloatArg1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
{
  int remaining;
  int loopIndex;
  undefined4 glErrorCode;
  bool rendererInfoByte79Zero;
  bool noStateChangePending;
  char rendererInfoByte79;
  byte levelFlags;
  ushort textureTargetBits;
  undefined4 forwardedInternalformat;
  int *srcCursor;
  int createdColorTableLevel;
  int dirtyWord;
  int textureLevel;
  int framebufferObject;
  undefined4 forwardedX;
  undefined4 forwardedY;
  undefined4 forwardedWidth;
  int textureObject;
  int matrixChangeBits;
  uint nonProxyTarget;
  uint dispatchFlags;
  uint changeWord3;
  int createdLevel;
  int tableScaleBias;
  int *changeWordCursor;
  double f1AfterCall;
  
  if ((*(int *)(glContext + 0x744c) != 0) || (*(int *)(glContext + 0x310) < 0)) {
    matrixChangeBits = *(int *)(glContext + 0x50ac);
    forwardedInternalformat = internalformat;
    forwardedX = x;
    forwardedY = y;
    forwardedWidth = width;
    if (matrixChangeBits != 0 || (*(uint *)(glContext + 0x505c) & *(uint *)(glContext + 0x50b0)) != 0) {
      _gleUpdateMatrixFunc(glContext);
      forwardedFloatArg1 = f1AfterCall;
    }
    if (*(char *)(glContext + 0x4691) != '\0') {
      framebufferObject = *(int *)(glContext + 0x744c);
      changeWordCursor = (int *)(glContext + 0x310);
      rendererInfoByte79 = *(char *)(*(int *)(glContext + 0x468c) + 0x79);
      if ((framebufferObject != 0) && (*(int *)(framebufferObject + 0xec) != 0)) {
        ((void (*)())_gleUpdateFramebufferCompleteness)(glContext,framebufferObject + 0x10,forwardedInternalformat,forwardedX,forwardedY,forwardedWidth,matrixChangeBits,forwardedFloatArg1,forwardedFloatArg2,forwardedFloatArg3,
                   forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
        *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x80000000;
      }
      if ((*(char *)(glContext + 0x4664) == '\0') && (*(int *)(glContext + 0x5430) == 0)) {
LAB_000608e8:
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
          goto LAB_000608e8;
        }
      }
      rendererInfoByte79Zero = rendererInfoByte79 == '\0';
      if (rendererInfoByte79Zero) {
        changeWord3 = changeWord3 & 0x17000000;
      }
      else {
        changeWord3 = changeWord3 & 0x17ffffff;
      }
      if (rendererInfoByte79Zero) {
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
              goto LAB_00060a74;
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
    }
  }
  if (*(short *)(glContext + 0x4a10) < 0) {
    textureObject = _gleCheckCopyColorTableArgs(glContext,target,internalformat,width);
    if (textureObject == 0) {
      return;
    }
    textureTargetBits = *(ushort *)(textureObject + 0x24);
    if ((textureTargetBits & 0x3c00) == 0x1000) {
LAB_00060a7c:
      textureLevel = textureObject + 0xac;
      if ((*(byte *)(textureObject + 0xb7) & 0x20) != 0) {
        _gleDeletePluginTextureLevel(glContext,textureObject,textureLevel,0,0xffffffff);
        if (*(int *)(textureObject + 0xc0) != 0) {
          levelFlags = *(byte *)(textureObject + 0xb7);
          if ((levelFlags & 1) == 0) {
            _gleFreeTextureLevel(glContext,textureObject,textureLevel);
            levelFlags = *(byte *)(textureObject + 0xb7);
          }
          else {
            *(undefined4 *)(textureObject + 0xc0) = 0;
          }
          *(byte *)(textureObject + 0xb7) = levelFlags & 0xef;
        }
        *(byte *)(textureObject + 0xb7) = *(byte *)(textureObject + 0xb7) & 0xdf;
      }
      tableScaleBias = glContext + 0x33d0;
      if (target != 0x80d1) {
        if (target < 0x80d2) {
          tableScaleBias = glContext + 0x33b0;
          nonProxyTarget = 0x80d0;
        }
        else {
          tableScaleBias = glContext + 0x33f0;
          nonProxyTarget = 0x80d2;
        }
        if (target != nonProxyTarget) {
          tableScaleBias = 0;
        }
      }
      if (tableScaleBias == 0) {
        createdLevel = _gleCreateTextureLevel
                           (glContext,textureObject,textureLevel,internalformat,width,1,1,0,0x1908,0x1401,0,0x1000);
        if (createdLevel != 0) {
          _gleTextureImageCopy(glContext,textureLevel,internalformat,x,y,width,1);
        }
        *(uint *)(glContext + 0x314) =
             *(uint *)(glContext + 0x314) | 1 << (*(uint *)(glContext + 0x53d4) & 0x3f);
      }
      else {
        createdColorTableLevel = _gleCreateColorTableLevel(glContext,textureObject,textureLevel,internalformat,width,0x1908,0x1401,0x1000)
        ;
        if (createdColorTableLevel != 0) {
          _gleTextureImageCopy(glContext,textureLevel,internalformat,x,y,width,1);
        }
        _gleImagingScaleAndBias
                  (glContext,tableScaleBias,*(undefined4 *)(textureObject + 0xc0),(uint)*(ushort *)(textureObject + 0xbc),0,
                   width,1);
        *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x40000000;
      }
      _gleCreatePluginTextureLevel(glContext,textureObject,textureLevel,0,0xffffffff,internalformat);
      return;
    }
    if ((textureTargetBits & 0x3c00) == 0) {
      *(ushort *)(textureObject + 0x24) = textureTargetBits | 0x1000;
      goto LAB_00060a7c;
    }
    if ((textureTargetBits & 0xc00) == 0) goto LAB_00060a7c;
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
  bool rendererByte79IsZero;
  bool noStateChangePending;
  char rendererInfoByte79;
  undefined4 forwardedStart;
  int *srcCursor;
  byte tableFlags;
  int scaleBiasSettings;
  int framebufferObject;
  undefined4 forwardedX;
  undefined4 forwardedY;
  int changeWordThenTableLevel;
  int matrixChangeBits;
  int forwardedWidthThenColorTable;
  uint scaleBiasTarget;
  uint dispatchFlags;
  uint changeWord3;
  int *changeWordCursor;
  double f1AfterCall;
  
  if ((*(int *)(glContext + 0x744c) != 0) || (*(int *)(glContext + 0x310) < 0)) {
    matrixChangeBits = *(int *)(glContext + 0x50ac);
    forwardedStart = start;
    forwardedX = x;
    forwardedY = y;
    forwardedWidthThenColorTable = width;
    if (matrixChangeBits != 0 || (*(uint *)(glContext + 0x505c) & *(uint *)(glContext + 0x50b0)) != 0) {
      _gleUpdateMatrixFunc(glContext);
      fparam_1 = f1AfterCall;
    }
    if (*(char *)(glContext + 0x4691) != '\0') {
      framebufferObject = *(int *)(glContext + 0x744c);
      changeWordCursor = (int *)(glContext + 0x310);
      rendererInfoByte79 = *(char *)(*(int *)(glContext + 0x468c) + 0x79);
      if ((framebufferObject != 0) && (*(int *)(framebufferObject + 0xec) != 0)) {
        ((void (*)())_gleUpdateFramebufferCompleteness)(glContext,framebufferObject + 0x10,forwardedStart,forwardedX,forwardedY,forwardedWidthThenColorTable,matrixChangeBits,fparam_1,forwardedFloatArg2,forwardedFloatArg3,
                   forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
        *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x80000000;
      }
      if ((*(char *)(glContext + 0x4664) == '\0') && (*(int *)(glContext + 0x5430) == 0)) {
LAB_00060eb8:
        changeWord3 = *(uint *)(glContext + 0x31c);
      }
      else {
        loopIndex = 0;
        srcCursor = (int *)(glContext + 0x324);
        do {
          changeWordThenTableLevel = *srcCursor;
          srcCursor = srcCursor + 1;
          if (changeWordThenTableLevel != 0) {
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
          goto LAB_00060eb8;
        }
      }
      rendererByte79IsZero = rendererInfoByte79 == '\0';
      if (rendererByte79IsZero) {
        changeWord3 = changeWord3 & 0x17000000;
      }
      else {
        changeWord3 = changeWord3 & 0x17ffffff;
      }
      if (rendererByte79IsZero) {
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
              goto LAB_00060ff8;
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
    }
  }
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (width == 0) {
      return;
    }
    forwardedWidthThenColorTable = _gleCheckCopyColorSubTableArgs(glContext,target,start,width);
    if (forwardedWidthThenColorTable == 0) {
      return;
    }
    changeWordThenTableLevel = forwardedWidthThenColorTable + 0xac;
    tableFlags = *(byte *)(forwardedWidthThenColorTable + 0xb7);
    if ((tableFlags & 0x10) == 0) {
      if ((tableFlags & 0x40) == 0) {
        if (*(int *)(forwardedWidthThenColorTable + 0xc0) == 0) {
          _gleAllocateTextureLevel(glContext,forwardedWidthThenColorTable,changeWordThenTableLevel);
          tableFlags = *(byte *)(forwardedWidthThenColorTable + 0xb7);
        }
        *(byte *)(forwardedWidthThenColorTable + 0xb7) = tableFlags | 0x10;
      }
      else {
        _gleUploadPluginTextureLevel
                  (glContext,forwardedWidthThenColorTable,changeWordThenTableLevel,0,0xffffffff,(uint)*(byte *)(glContext + 0x85a8));
      }
    }
    scaleBiasSettings = glContext + 0x33d0;
    _gleModifyPluginTextureLevel(glContext,forwardedWidthThenColorTable,changeWordThenTableLevel,0,0xffffffff,start,0,0,width,1,1);
    if (target != 0x80d1) {
      if (target < 0x80d2) {
        scaleBiasSettings = glContext + 0x33b0;
        scaleBiasTarget = 0x80d0;
      }
      else {
        scaleBiasSettings = glContext + 0x33f0;
        scaleBiasTarget = 0x80d2;
      }
      if (target != scaleBiasTarget) {
        scaleBiasSettings = 0;
      }
    }
    _gleTextureSubImageCopy(glContext,changeWordThenTableLevel,start,0,0,x,y,width,1);
    if (scaleBiasSettings != 0) {
      _gleImagingScaleAndBias
                (glContext,scaleBiasSettings,*(undefined4 *)(forwardedWidthThenColorTable + 0xc0),(uint)*(ushort *)(forwardedWidthThenColorTable + 0xbc),
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
  bool formatCheck;
  byte tableFlags;
  undefined4 rowBytes;
  int colorTable;
  int imageEndOffset;
  int elementBytes;
  undefined4 *userConvertAPtr;
  undefined4 *userConvertBPtr;
  uint tableHeight;
  uint glContextByte31c8;
  undefined1 *puVar11;
  int *packOffsetPtr;
  int pixelPackBuffer;
  int bufferSize;
  double bytesPerElement;
  undefined4 procSrcAddress;
  undefined4 procSrcRowBytes;
  undefined4 procSrcConvertA;
  undefined4 procSrcConvertB;
  int procDstAddress;
  undefined4 procDstRowBytes;
  undefined4 procDstConvertA;
  undefined4 procDstConvertB;
  undefined4 procMode;
  uint procFlags;
  undefined4 procMask;
  uint procWidth;
  uint procHeight;
  undefined1 procEnd;
  undefined4 packRowBytes;
  undefined1 auStack_5c [4];
  undefined1 auStack_58 [4];
  undefined1 auStack_54 [4];
  undefined1 auStack_50 [4];
  int packOffset;
  undefined4 tableConvertA;
  undefined4 tableConvertB;
  undefined4 userConvertA;
  undefined4 userConvertB [5];
  
  colorTable = _gleLookUpNonProxyColorTable(glContext,target);
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (colorTable != 0) {
      if (type < 0x8037) {
        if (0x8032 < type) {
LAB_000612b0:
          if (format != 0x1908) {
            formatCheck = format == 0x80e1;
LAB_000612c4:
            if (!formatCheck) goto LAB_00061354;
          }
LAB_000612e0:
          pixelPackBuffer = *(int *)(glContext + 0x4a68);
          if (pixelPackBuffer == 0) {
LAB_0006138c:
            tableFlags = *(byte *)(colorTable + 0xb7);
            if ((tableFlags & 0x20) == 0) {
              return;
            }
            if ((tableFlags & 0x40) == 0) {
              if ((tableFlags & 0x10) == 0) {
                return;
              }
            }
            else {
              _gleUploadPluginTextureLevel
                        (glContext,colorTable,colorTable + 0xac,0,0xffffffff,(uint)*(byte *)(glContext + 0x85a8));
            }
            tableHeight = (uint)*(ushort *)(colorTable + 0xb2);
            puVar11 = auStack_50;
            packOffsetPtr = &packOffset;
            _glePixelPackSettings
                      (glContext,format,type,(uint)*(ushort *)(colorTable + 0xb0),tableHeight,
                       glContext + 0x31b0,puVar11,packOffsetPtr,&packRowBytes,auStack_5c,auStack_58,auStack_54);
            if (((((*(byte *)(colorTable + 0xb7) & 1) == 0) ||
                 (table + packOffset != *(int *)(colorTable + 0xc0))) ||
                (format != *(ushort *)(colorTable + 0xbc))) || (type != *(ushort *)(colorTable + 0xbe))) {
              glContextByte31c8 = (uint)*(byte *)(glContext + 0x31c8);
            }
            else {
              glContextByte31c8 = (uint)*(byte *)(glContext + 0x31c8);
              if (glContextByte31c8 == 0) {
                return;
              }
            }
            procFlags = (uint)(glContextByte31c8 != 0);
            rowBytes = _gleRowBytes((uint)*(ushort *)(colorTable + 0xbc),(uint)*(ushort *)(colorTable + 0xbe),
                                 (uint)*(ushort *)(colorTable + 0xb8));
            _glgConvertType((uint)*(ushort *)(colorTable + 0xbc),(uint)*(ushort *)(colorTable + 0xbe),
                            &tableConvertA,&tableConvertB,tableHeight,glContextByte31c8,puVar11,packOffsetPtr);
            userConvertAPtr = &userConvertA;
            userConvertBPtr = userConvertB;
            _glgConvertType(format,type,userConvertAPtr,userConvertBPtr,tableHeight,glContextByte31c8,puVar11,packOffsetPtr);
            procSrcConvertA = tableConvertA;
            procSrcConvertB = tableConvertB;
            procDstRowBytes = packRowBytes;
            procDstConvertA = userConvertA;
            procDstConvertB = userConvertB[0];
            procMask = 1;
            procMode = 2;
            procWidth = (uint)*(ushort *)(colorTable + 0xb0);
            procHeight = (uint)*(ushort *)(colorTable + 0xb2);
            procDstAddress = table + packOffset;
            procSrcAddress = *(undefined4 *)(colorTable + 0xc0);
            procEnd = 0;
            procSrcRowBytes = rowBytes;
            _glgProcessPixels(glContext + 0x31a8,&procSrcAddress,userConvertAPtr,userConvertBPtr,tableHeight,glContextByte31c8,procHeight,packOffsetPtr
                             );
            return;
          }
          imageEndOffset = _gleOffsetLimitImage
                            (glContext + 0x31b0,(uint)*(ushort *)(colorTable + 0xb0),
                             (uint)*(ushort *)(colorTable + 0xb2),format,type,table);
          bufferSize = *(int *)(pixelPackBuffer + 0x38);
          bytesPerElement = (double)((double (*)())_gleBytesPerElement)(type);
          elementBytes = (int)bytesPerElement;
          if (imageEndOffset <= bufferSize) {
            if (elementBytes == 0) {
              elementBytes = _glePixelBytes(format,type);
            }
            if (table == (table / elementBytes) * elementBytes) {
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
                formatCheck = 7 < format - 0x1903;
              }
              else {
                formatCheck = 1 < format - 0x80e0;
              }
              if (formatCheck) goto LAB_00061354;
            }
            goto LAB_000612e0;
          }
          if (type == 0x8032) goto LAB_000612a8;
        }
      }
      else if (0x8361 < type) {
        if (type < 0x8365) {
LAB_000612a8:
          formatCheck = format == 0x1907;
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
  int colorTable;
  float *pfVar5;
  
  colorTable = _gleLookUpColorTable(glContext,target);
  if (-1 < *(short *)(glContext + 0x4a10)) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
    goto LAB_00061be8;
  }
  if (colorTable == 0) {
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
    uVar2 = *(ushort *)(colorTable + 0xbc);
    goto LAB_00061ba4;
  case 0x80d9:
    uVar2 = *(ushort *)(colorTable + 0xb0);
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
  int colorTable;
  float *pfVar5;
  
  colorTable = _gleLookUpColorTable(glContext,target);
  if (-1 < *(short *)(glContext + 0x4a10)) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
    goto LAB_00061dc8;
  }
  if (colorTable == 0) {
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
    uVar3 = (uint)*(ushort *)(colorTable + 0xbc);
    break;
  case 0x80d9:
    uVar3 = (uint)*(ushort *)(colorTable + 0xb0);
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
  bool noStateChangePending;
  char rendererInfoByte79;
  uint dispatchFlags;
  uint changeWord3;
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
  int *changeWordCursor;
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
      changeWordCursor = (int *)(glContext + 0x310);
      rendererInfoByte79 = *(char *)(*(int *)(glContext + 0x468c) + 0x79);
      if ((framebufferObject != 0) && (*(int *)(framebufferObject + 0xec) != 0)) {
        ((void (*)())_gleUpdateFramebufferCompleteness)(glContext,framebufferObject + 0x10,incomingR5,incomingR6,incomingR7,incomingR8,matrixChangeBits,fparam_1,forwardedFloatArg2,forwardedFloatArg3,
                   forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
        *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x80000000;
      }
      if ((*(char *)(glContext + 0x4664) == '\0') && (*(int *)(glContext + 0x5430) == 0)) {
LAB_00061f74:
        changeWord3 = *(uint *)(glContext + 0x31c);
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
        changeWord3 = *(uint *)(glContext + 0x31c);
        if ((changeWord3 & 0x15555) != 0) {
          if (*(char *)(glContext + 0x2e54) != '\0') {
            _gleUpdateLightRGBASums(glContext,glContext + 0x2c20,0);
          }
          if (*(char *)(glContext + 0x3094) != '\0') {
            _gleUpdateLightRGBASums(glContext,glContext + 0x2e60,1);
          }
          goto LAB_00061f74;
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
          *changeWordCursor = 0;
          changeWordCursor = changeWordCursor + 1;
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

