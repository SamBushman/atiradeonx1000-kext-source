#include "decls.h"

/* _gleSetEnable_CLIP_PLANE @ 0xcb284 (108 bytes) */
void _gleSetEnable_CLIP_PLANE(glContext, cap, enable, forwardedArg4)
  int glContext;
  int cap;
  int enable;
  undefined4 forwardedArg4;
{
  uint newClipPlaneBits;
  uint planeBit;
  uint planeIndex;
  
  planeIndex = cap - 0x3000;
  planeBit = enable << (planeIndex & 0x3f);
  newClipPlaneBits = *(uint *)(glContext + 0x4188) &
          (-2 << (planeIndex & 0x1f) | 0xfffffffeU >> 0x20 - (planeIndex & 0x1f)) | planeBit;
  if (*(uint *)(glContext + 0x4188) != newClipPlaneBits) {
    *(uint *)(glContext + 0x4188) = newClipPlaneBits;
    _gleUpdateClipPlane(glContext,cap,planeBit,forwardedArg4);
    *(uint *)(glContext + 0x318) = *(uint *)(glContext + 0x318) | 0x1000000 << (planeIndex & 0x3f);
  }
  return;
}

/* _gleSetEnable_TEXTURE_GEN_S @ 0xcb2f0 (104 bytes) */
void _gleSetEnable_TEXTURE_GEN_S(glContext, cap, enable)
  int glContext;
  undefined4 cap;
  uint enable;
{
  int texUnitState;
  uint texUnit;
  
  texUnit = *(uint *)(glContext + 0x53d4);
  texUnitState = texUnit * 0x94 + glContext;
  if (*(byte *)(texUnitState + 0x3d78) != enable) {
    *(char *)(texUnitState + 0x3d78) = (char)enable;
    _gleUpdateTextureCoordGen(glContext);
    _gleSelectVertexSubmitFunc(glContext);
    *(uint *)(glContext + 0x314) = *(uint *)(glContext + 0x314) | 0x10000 << (texUnit & 0x3f);
  }
  return;
}

/* _gleSetEnable_TEXTURE_GEN_T @ 0xcb358 (104 bytes) */
void _gleSetEnable_TEXTURE_GEN_T(glContext, cap, enable)
  int glContext;
  undefined4 cap;
  uint enable;
{
  int texUnitState;
  uint texUnit;
  
  texUnit = *(uint *)(glContext + 0x53d4);
  texUnitState = texUnit * 0x94 + glContext;
  if (*(byte *)(texUnitState + 0x3d79) != enable) {
    *(char *)(texUnitState + 0x3d79) = (char)enable;
    _gleUpdateTextureCoordGen(glContext);
    _gleSelectVertexSubmitFunc(glContext);
    *(uint *)(glContext + 0x314) = *(uint *)(glContext + 0x314) | 0x10000 << (texUnit & 0x3f);
  }
  return;
}

/* _gleSetEnable_TEXTURE_GEN_R @ 0xcb3c0 (96 bytes) */
void _gleSetEnable_TEXTURE_GEN_R(glContext, cap, enable)
  int glContext;
  undefined4 cap;
  uint enable;
{
  int texUnitState;
  uint texUnit;
  
  texUnit = *(uint *)(glContext + 0x53d4);
  texUnitState = texUnit * 0x94 + glContext;
  if (*(byte *)(texUnitState + 0x3d7a) != enable) {
    *(char *)(texUnitState + 0x3d7a) = (char)enable;
    _gleUpdateTextureCoordGen(glContext);
    *(uint *)(glContext + 0x314) = *(uint *)(glContext + 0x314) | 0x10000 << (texUnit & 0x3f);
  }
  return;
}

/* _gleSetEnable_TEXTURE_GEN_Q @ 0xcb420 (96 bytes) */
void _gleSetEnable_TEXTURE_GEN_Q(glContext, cap, enable)
  int glContext;
  undefined4 cap;
  uint enable;
{
  int texUnitState;
  uint texUnit;
  
  texUnit = *(uint *)(glContext + 0x53d4);
  texUnitState = texUnit * 0x94 + glContext;
  if (*(byte *)(texUnitState + 0x3d7b) != enable) {
    *(char *)(texUnitState + 0x3d7b) = (char)enable;
    _gleUpdateTextureCoordGen(glContext);
    *(uint *)(glContext + 0x314) = *(uint *)(glContext + 0x314) | 0x10000 << (texUnit & 0x3f);
  }
  return;
}

/* _gleSetEnable_MAP1_VERTEX_3 @ 0xcb480 (76 bytes) */
void _gleSetEnable_MAP1_VERTEX_3(glContext, cap, enable)
  int glContext;
  undefined4 cap;
  undefined4 enable;
{
  undefined1 outputBytes;
  
  outputBytes = 0x10;
  *(undefined1 *)(glContext + 0x74e0) = (undefined1)enable;
  if ((*(char *)(glContext + 0x74e1) == '\0') && (outputBytes = 0xc, *(char *)(glContext + 0x74e0) == '\0')) {
    outputBytes = 0;
  }
  *(undefined1 *)(glContext + 0x7514) = outputBytes;
  *(undefined **)(glContext + 0x4898) = PTR__gleSetVertexEval1Func_0011206c;
  return;
}

/* _gleSetEnable_MAP1_VERTEX_4 @ 0xcb4cc (76 bytes) */
void _gleSetEnable_MAP1_VERTEX_4(glContext, cap, enable)
  int glContext;
  undefined4 cap;
  undefined4 enable;
{
  undefined1 outputBytes;
  
  *(undefined1 *)(glContext + 0x74e1) = (undefined1)enable;
  outputBytes = 0x10;
  if ((*(char *)(glContext + 0x74e1) == '\0') && (outputBytes = 0xc, *(char *)(glContext + 0x74e0) == '\0')) {
    outputBytes = 0;
  }
  *(undefined1 *)(glContext + 0x7514) = outputBytes;
  *(undefined **)(glContext + 0x4898) = PTR__gleSetVertexEval1Func_0011206c;
  return;
}

/* _gleSetEnable_MAP1_COLOR_4 @ 0xcb518 (52 bytes) */
void _gleSetEnable_MAP1_COLOR_4(glContext, cap, enable)
  int glContext;
  undefined4 cap;
  undefined4 enable;
{
  *(undefined1 *)(glContext + 0x74e2) = (undefined1)enable;
  *(undefined **)(glContext + 0x4898) = PTR__gleSetVertexEval1Func_0011206c;
  *(byte *)(glContext + 0x7516) = (byte)(-(uint)*(byte *)(glContext + 0x74e2) >> 0x1b) & 0x10;
  return;
}

/* _gleSetEnable_MAP1_NORMAL @ 0xcb554 (60 bytes) */
void _gleSetEnable_MAP1_NORMAL(glContext, cap, enable)
  int glContext;
  undefined4 cap;
  undefined4 enable;
{
  undefined1 outputBytes;
  
  *(undefined1 *)(glContext + 0x74e4) = (undefined1)enable;
  outputBytes = 0xc;
  if (*(char *)(glContext + 0x74e4) == '\0') {
    outputBytes = 0;
  }
  *(undefined1 *)(glContext + 0x7515) = outputBytes;
  *(undefined **)(glContext + 0x4898) = PTR__gleSetVertexEval1Func_0011206c;
  return;
}

/* _gleSetEnable_MAP1_TEXTURE_COORD_1 @ 0xcb590 (100 bytes) */
void _gleSetEnable_MAP1_TEXTURE_COORD_1(glContext, cap, enable)
  int glContext;
  undefined4 cap;
  undefined4 enable;
{
  byte outputBytes;
  
  outputBytes = 0x10;
  *(undefined1 *)(glContext + 0x74e5) = (undefined1)enable;
  if (((*(char *)(glContext + 0x74e8) == '\0') && (outputBytes = 0xc, *(char *)(glContext + 0x74e7) == '\0'))
     && (outputBytes = 8, *(char *)(glContext + 0x74e6) == '\0')) {
    outputBytes = (byte)(-(uint)*(byte *)(glContext + 0x74e5) >> 0x1d) & 4;
  }
  *(byte *)(glContext + 0x751c) = outputBytes;
  *(undefined **)(glContext + 0x4898) = PTR__gleSetVertexEval1Func_0011206c;
  return;
}

/* _gleSetEnable_MAP1_TEXTURE_COORD_2 @ 0xcb5f4 (100 bytes) */
void _gleSetEnable_MAP1_TEXTURE_COORD_2(glContext, cap, enable)
  int glContext;
  undefined4 cap;
  undefined4 enable;
{
  byte outputBytes;
  
  outputBytes = 0x10;
  *(undefined1 *)(glContext + 0x74e6) = (undefined1)enable;
  if (((*(char *)(glContext + 0x74e8) == '\0') && (outputBytes = 0xc, *(char *)(glContext + 0x74e7) == '\0'))
     && (outputBytes = 8, *(char *)(glContext + 0x74e6) == '\0')) {
    outputBytes = (byte)(-(uint)*(byte *)(glContext + 0x74e5) >> 0x1d) & 4;
  }
  *(byte *)(glContext + 0x751c) = outputBytes;
  *(undefined **)(glContext + 0x4898) = PTR__gleSetVertexEval1Func_0011206c;
  return;
}

/* _gleSetEnable_MAP1_TEXTURE_COORD_3 @ 0xcb658 (100 bytes) */
void _gleSetEnable_MAP1_TEXTURE_COORD_3(glContext, cap, enable)
  int glContext;
  undefined4 cap;
  undefined4 enable;
{
  byte outputBytes;
  
  outputBytes = 0x10;
  *(undefined1 *)(glContext + 0x74e7) = (undefined1)enable;
  if (((*(char *)(glContext + 0x74e8) == '\0') && (outputBytes = 0xc, *(char *)(glContext + 0x74e7) == '\0'))
     && (outputBytes = 8, *(char *)(glContext + 0x74e6) == '\0')) {
    outputBytes = (byte)(-(uint)*(byte *)(glContext + 0x74e5) >> 0x1d) & 4;
  }
  *(byte *)(glContext + 0x751c) = outputBytes;
  *(undefined **)(glContext + 0x4898) = PTR__gleSetVertexEval1Func_0011206c;
  return;
}

/* _gleSetEnable_MAP1_TEXTURE_COORD_4 @ 0xcb6bc (100 bytes) */
void _gleSetEnable_MAP1_TEXTURE_COORD_4(glContext, cap, enable)
  int glContext;
  undefined4 cap;
  undefined4 enable;
{
  byte outputBytes;
  
  *(undefined1 *)(glContext + 0x74e8) = (undefined1)enable;
  outputBytes = 0x10;
  if (((*(char *)(glContext + 0x74e8) == '\0') && (outputBytes = 0xc, *(char *)(glContext + 0x74e7) == '\0'))
     && (outputBytes = 8, *(char *)(glContext + 0x74e6) == '\0')) {
    outputBytes = (byte)(-(uint)*(byte *)(glContext + 0x74e5) >> 0x1d) & 4;
  }
  *(byte *)(glContext + 0x751c) = outputBytes;
  *(undefined **)(glContext + 0x4898) = PTR__gleSetVertexEval1Func_0011206c;
  return;
}

/* _gleSetEnable_MAP2_VERTEX_3 @ 0xcb720 (76 bytes) */
void _gleSetEnable_MAP2_VERTEX_3(glContext, cap, enable)
  int glContext;
  undefined4 cap;
  undefined4 enable;
{
  undefined1 outputBytes;
  
  outputBytes = 0x10;
  *(undefined1 *)(glContext + 0x74e9) = (undefined1)enable;
  if ((*(char *)(glContext + 0x74ea) == '\0') && (outputBytes = 0xc, *(char *)(glContext + 0x74e9) == '\0')) {
    outputBytes = 0;
  }
  *(undefined1 *)(glContext + 0x7554) = outputBytes;
  *(undefined **)(glContext + 0x489c) = PTR__gleSetVertexEval2Func_00112068;
  return;
}

/* _gleSetEnable_MAP2_VERTEX_4 @ 0xcb76c (76 bytes) */
void _gleSetEnable_MAP2_VERTEX_4(glContext, cap, enable)
  int glContext;
  undefined4 cap;
  undefined4 enable;
{
  undefined1 outputBytes;
  
  *(undefined1 *)(glContext + 0x74ea) = (undefined1)enable;
  outputBytes = 0x10;
  if ((*(char *)(glContext + 0x74ea) == '\0') && (outputBytes = 0xc, *(char *)(glContext + 0x74e9) == '\0')) {
    outputBytes = 0;
  }
  *(undefined1 *)(glContext + 0x7554) = outputBytes;
  *(undefined **)(glContext + 0x489c) = PTR__gleSetVertexEval2Func_00112068;
  return;
}

/* _gleSetEnable_MAP2_COLOR_4 @ 0xcb7b8 (52 bytes) */
void _gleSetEnable_MAP2_COLOR_4(glContext, cap, enable)
  int glContext;
  undefined4 cap;
  undefined4 enable;
{
  *(undefined1 *)(glContext + 0x74eb) = (undefined1)enable;
  *(undefined **)(glContext + 0x489c) = PTR__gleSetVertexEval2Func_00112068;
  *(byte *)(glContext + 0x7556) = (byte)(-(uint)*(byte *)(glContext + 0x74eb) >> 0x1b) & 0x10;
  return;
}

/* _gleSetEnable_MAP2_NORMAL @ 0xcb7f4 (72 bytes) */
void _gleSetEnable_MAP2_NORMAL(glContext, cap, enable)
  int glContext;
  undefined4 cap;
  undefined4 enable;
{
  undefined1 outputBytes;
  
  *(undefined1 *)(glContext + 0x74ed) = (undefined1)enable;
  if ((*(char *)(glContext + 0x74ed) != '\0') || (outputBytes = 0, *(char *)(glContext + 0x74f2) != '\0')) {
    outputBytes = 0xc;
  }
  *(undefined1 *)(glContext + 0x7555) = outputBytes;
  *(undefined **)(glContext + 0x489c) = PTR__gleSetVertexEval2Func_00112068;
  return;
}

/* _gleSetEnable_MAP2_TEXTURE_COORD_1 @ 0xcb83c (100 bytes) */
void _gleSetEnable_MAP2_TEXTURE_COORD_1(glContext, cap, enable)
  int glContext;
  undefined4 cap;
  undefined4 enable;
{
  byte outputBytes;
  
  outputBytes = 0x10;
  *(undefined1 *)(glContext + 0x74ee) = (undefined1)enable;
  if (((*(char *)(glContext + 0x74f1) == '\0') && (outputBytes = 0xc, *(char *)(glContext + 0x74f0) == '\0'))
     && (outputBytes = 8, *(char *)(glContext + 0x74ef) == '\0')) {
    outputBytes = (byte)(-(uint)*(byte *)(glContext + 0x74ee) >> 0x1d) & 4;
  }
  *(byte *)(glContext + 0x755c) = outputBytes;
  *(undefined **)(glContext + 0x489c) = PTR__gleSetVertexEval2Func_00112068;
  return;
}

/* _gleSetEnable_MAP2_TEXTURE_COORD_2 @ 0xcb8a0 (100 bytes) */
void _gleSetEnable_MAP2_TEXTURE_COORD_2(glContext, cap, enable)
  int glContext;
  undefined4 cap;
  undefined4 enable;
{
  byte outputBytes;
  
  outputBytes = 0x10;
  *(undefined1 *)(glContext + 0x74ef) = (undefined1)enable;
  if (((*(char *)(glContext + 0x74f1) == '\0') && (outputBytes = 0xc, *(char *)(glContext + 0x74f0) == '\0'))
     && (outputBytes = 8, *(char *)(glContext + 0x74ef) == '\0')) {
    outputBytes = (byte)(-(uint)*(byte *)(glContext + 0x74ee) >> 0x1d) & 4;
  }
  *(byte *)(glContext + 0x755c) = outputBytes;
  *(undefined **)(glContext + 0x489c) = PTR__gleSetVertexEval2Func_00112068;
  return;
}

/* _gleSetEnable_MAP2_TEXTURE_COORD_3 @ 0xcb904 (100 bytes) */
void _gleSetEnable_MAP2_TEXTURE_COORD_3(glContext, cap, enable)
  int glContext;
  undefined4 cap;
  undefined4 enable;
{
  byte outputBytes;
  
  outputBytes = 0x10;
  *(undefined1 *)(glContext + 0x74f0) = (undefined1)enable;
  if (((*(char *)(glContext + 0x74f1) == '\0') && (outputBytes = 0xc, *(char *)(glContext + 0x74f0) == '\0'))
     && (outputBytes = 8, *(char *)(glContext + 0x74ef) == '\0')) {
    outputBytes = (byte)(-(uint)*(byte *)(glContext + 0x74ee) >> 0x1d) & 4;
  }
  *(byte *)(glContext + 0x755c) = outputBytes;
  *(undefined **)(glContext + 0x489c) = PTR__gleSetVertexEval2Func_00112068;
  return;
}

/* _gleSetEnable_MAP2_TEXTURE_COORD_4 @ 0xcb968 (100 bytes) */
void _gleSetEnable_MAP2_TEXTURE_COORD_4(glContext, cap, enable)
  int glContext;
  undefined4 cap;
  undefined4 enable;
{
  byte outputBytes;
  
  *(undefined1 *)(glContext + 0x74f1) = (undefined1)enable;
  outputBytes = 0x10;
  if (((*(char *)(glContext + 0x74f1) == '\0') && (outputBytes = 0xc, *(char *)(glContext + 0x74f0) == '\0'))
     && (outputBytes = 8, *(char *)(glContext + 0x74ef) == '\0')) {
    outputBytes = (byte)(-(uint)*(byte *)(glContext + 0x74ee) >> 0x1d) & 4;
  }
  *(byte *)(glContext + 0x755c) = outputBytes;
  *(undefined **)(glContext + 0x489c) = PTR__gleSetVertexEval2Func_00112068;
  return;
}

/* _gleSetEnable_POINT_SMOOTH @ 0xcb9cc (32 bytes) */
void _gleSetEnable_POINT_SMOOTH(glContext, cap, enable)
  int glContext;
  undefined4 cap;
  uint enable;
{
  if (*(byte *)(glContext + 0x343c) == enable) {
    return;
  }
  *(char *)(glContext + 0x343c) = (char)enable;
  *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x400000;
  return;
}

/* _gleSetEnable_COLOR_MATERIAL @ 0xcb9ec (136 bytes) */
void _gleSetEnable_COLOR_MATERIAL(glContext, cap, enable)
  int glContext;
  undefined4 cap;
  uint enable;
{
  char colorCallbackFlagBefore;
  
  if (*(byte *)(glContext + 0x30ab) != enable) {
    *(char *)(glContext + 0x30ab) = (char)enable;
    colorCallbackFlagBefore = *(char *)(glContext + 0x4df8);
    _gleSetColorMaterialEnable(glContext);
    if (((enable == 0) && (colorCallbackFlagBefore == '\0')) && (*(char *)(glContext + 0x4df8) == '\0')) {
      (**(code **)(glContext + 0x4de0))(glContext,glContext + 0x2a0);
    }
    _gleSelectVertexSubmitFunc(glContext);
    *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x40000;
  }
  return;
}

/* _gleSetEnable_AUTO_NORMAL @ 0xcba74 (72 bytes) */
void _gleSetEnable_AUTO_NORMAL(glContext, cap, enable)
  int glContext;
  undefined4 cap;
  undefined4 enable;
{
  undefined1 outputBytes;
  
  *(undefined1 *)(glContext + 0x74f2) = (undefined1)enable;
  if ((*(char *)(glContext + 0x74ed) != '\0') || (outputBytes = 0, *(char *)(glContext + 0x74f2) != '\0')) {
    outputBytes = 0xc;
  }
  *(undefined1 *)(glContext + 0x7555) = outputBytes;
  *(undefined **)(glContext + 0x489c) = PTR__gleSetVertexEval2Func_00112068;
  return;
}

/* _gleSetEnable_POLYGON_OFFSET_POINT @ 0xcbabc (48 bytes) */
void _gleSetEnable_POLYGON_OFFSET_POINT(glContext, cap, enable)
  int glContext;
  undefined4 cap;
  uint enable;
{
  if (*(byte *)(glContext + 0x34db) == enable) {
    return;
  }
  if (enable != 0) {
    *(uint *)(glContext + 0x4980) = (uint)*(ushort *)(glContext + 0x4982);
  }
  *(char *)(glContext + 0x34db) = (char)enable;
  *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x800000;
  return;
}

/* _gleSetEnable_POLYGON_OFFSET_LINE @ 0xcbaec (48 bytes) */
void _gleSetEnable_POLYGON_OFFSET_LINE(glContext, cap, enable)
  int glContext;
  undefined4 cap;
  uint enable;
{
  if (*(byte *)(glContext + 0x34dc) == enable) {
    return;
  }
  if (enable != 0) {
    *(uint *)(glContext + 0x4980) = (uint)*(ushort *)(glContext + 0x4982);
  }
  *(char *)(glContext + 0x34dc) = (char)enable;
  *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x800000;
  return;
}

/* _gleSetEnable_POLYGON_OFFSET_FILL @ 0xcbb1c (48 bytes) */
void _gleSetEnable_POLYGON_OFFSET_FILL(glContext, cap, enable)
  int glContext;
  undefined4 cap;
  uint enable;
{
  if (*(byte *)(glContext + 0x34dd) == enable) {
    return;
  }
  if (enable != 0) {
    *(uint *)(glContext + 0x4980) = (uint)*(ushort *)(glContext + 0x4982);
  }
  *(char *)(glContext + 0x34dd) = (char)enable;
  *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x800000;
  return;
}

/* _gleSetEnable_REGISTER_COMBINERS_NV @ 0xcbb4c (32 bytes) */
void _gleSetEnable_REGISTER_COMBINERS_NV(glContext, cap, enable)
  int glContext;
  undefined4 cap;
  uint enable;
{
  if (*(byte *)(glContext + 0x41f8) == enable) {
    return;
  }
  *(char *)(glContext + 0x41f8) = (char)enable;
  *(uint *)(glContext + 0x314) = *(uint *)(glContext + 0x314) | 0x1000000;
  return;
}

/* _gleSetEnable_PER_STAGE_CONSTANTS_NV @ 0xcbb6c (32 bytes) */
void _gleSetEnable_PER_STAGE_CONSTANTS_NV(glContext, cap, enable)
  int glContext;
  undefined4 cap;
  uint enable;
{
  if (*(byte *)(glContext + 0x41f9) == enable) {
    return;
  }
  *(char *)(glContext + 0x41f9) = (char)enable;
  *(uint *)(glContext + 0x314) = *(uint *)(glContext + 0x314) | 0x1000000;
  return;
}

/* _gleSetEnable_TEXTURE_SHADER_NV @ 0xcbb8c (96 bytes) */
void _gleSetEnable_TEXTURE_SHADER_NV(glContext, cap, enable)
  int glContext;
  undefined4 cap;
  uint enable;
{
  uint texUnit;
  uint nextUnit;
  
  if (*(byte *)(glContext + 0x3ce4) != enable) {
    *(char *)(glContext + 0x3ce4) = (char)enable;
    *(uint *)(glContext + 0x314) = *(uint *)(glContext + 0x314) | 0x2000000;
    texUnit = 0;
    do {
      nextUnit = texUnit + 1;
      _gleUpdateTextureParams(glContext,texUnit);
      texUnit = nextUnit;
    } while (nextUnit < 0x10);
  }
  return;
}

/* _gleSetEnable_POINT_SPRITE_ARB @ 0xcbbec (32 bytes) */
void _gleSetEnable_POINT_SPRITE_ARB(glContext, cap, enable)
  int glContext;
  undefined4 cap;
  uint enable;
{
  if (*(byte *)(glContext + 0x343d) == enable) {
    return;
  }
  *(char *)(glContext + 0x343d) = (char)enable;
  *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x400000;
  return;
}

/* _gleSetEnable_DEPTH_CLAMP_NV @ 0xcbc0c (32 bytes) */
void _gleSetEnable_DEPTH_CLAMP_NV(glContext, cap, enable)
  int glContext;
  undefined4 cap;
  uint enable;
{
  if (*(byte *)(glContext + 0x3129) == enable) {
    return;
  }
  *(char *)(glContext + 0x3129) = (char)enable;
  *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x200;
  return;
}

/* _gleSetEnable_RASTER_POSITION_UNCLIPPED_IBM @ 0xcbc2c (8 bytes) */
void _gleSetEnable_RASTER_POSITION_UNCLIPPED_IBM(glContext, cap, enable)
  int glContext;
  undefined4 cap;
  undefined4 enable;
{
  *(undefined1 *)(glContext + 0x50b5) = (undefined1)enable;
  return;
}

/* _gleSetEnable_PN_TRIANGLES_ATI @ 0xcbc34 (32 bytes) */
void _gleSetEnable_PN_TRIANGLES_ATI(glContext, cap, enable)
  int glContext;
  undefined4 cap;
  uint enable;
{
  if (*(byte *)(glContext + 0x280c) == enable) {
    return;
  }
  *(char *)(glContext + 0x280c) = (char)enable;
  *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x80000;
  return;
}

/* _gleSetEnable_MULTISAMPLE @ 0xcbc54 (32 bytes) */
void _gleSetEnable_MULTISAMPLE(glContext, cap, enable)
  int glContext;
  undefined4 cap;
  uint enable;
{
  if (*(byte *)(glContext + 0x41f0) == enable) {
    return;
  }
  *(char *)(glContext + 0x41f0) = (char)enable;
  *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x20000000;
  return;
}

/* _gleSetEnable_SAMPLE_ALPHA_TO_COVERAGE @ 0xcbc74 (32 bytes) */
void _gleSetEnable_SAMPLE_ALPHA_TO_COVERAGE(glContext, cap, enable)
  int glContext;
  undefined4 cap;
  uint enable;
{
  if (*(byte *)(glContext + 0x41f1) == enable) {
    return;
  }
  *(char *)(glContext + 0x41f1) = (char)enable;
  *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x20000000;
  return;
}

/* _gleSetEnable_SAMPLE_ALPHA_TO_ONE @ 0xcbc94 (32 bytes) */
void _gleSetEnable_SAMPLE_ALPHA_TO_ONE(glContext, cap, enable)
  int glContext;
  undefined4 cap;
  uint enable;
{
  if (*(byte *)(glContext + 0x41f2) == enable) {
    return;
  }
  *(char *)(glContext + 0x41f2) = (char)enable;
  *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x20000000;
  return;
}

/* _gleSetEnable_SAMPLE_COVERAGE @ 0xcbcb4 (32 bytes) */
void _gleSetEnable_SAMPLE_COVERAGE(glContext, cap, enable)
  int glContext;
  undefined4 cap;
  uint enable;
{
  if (*(byte *)(glContext + 0x41f3) == enable) {
    return;
  }
  *(char *)(glContext + 0x41f3) = (char)enable;
  *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x20000000;
  return;
}

/* _gleSetEnable_VERTEX_BLEND_ARB @ 0xcbcd4 (92 bytes) */
void _gleSetEnable_VERTEX_BLEND_ARB(glContext, cap, enable)
  int glContext;
  undefined4 cap;
  uint enable;
{
  if (*(byte *)(glContext + 0x4661) != enable) {
    *(char *)(glContext + 0x4661) = (char)enable;
    _gleUpdateInverseNeeds(glContext);
    _gleSelectVertexSubmitFunc(glContext);
    *(uint *)(glContext + 0x50ac) = *(uint *)(glContext + 0x50ac) | 1;
    *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x200000;
  }
  return;
}

/* _gleSetEnable_WEIGHT_SUM_UNITY_ARB @ 0xcbd30 (32 bytes) */
void _gleSetEnable_WEIGHT_SUM_UNITY_ARB(glContext, cap, enable)
  int glContext;
  undefined4 cap;
  uint enable;
{
  if (*(byte *)(glContext + 0x4662) == enable) {
    return;
  }
  *(char *)(glContext + 0x4662) = (char)enable;
  *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x200000;
  return;
}

/* _gleSetEnable_VERTEX_PROGRAM_POINT_SIZE_ARB @ 0xcbd50 (32 bytes) */
void _gleSetEnable_VERTEX_PROGRAM_POINT_SIZE_ARB(glContext, cap, enable)
  int glContext;
  undefined4 cap;
  uint enable;
{
  if (*(byte *)(glContext + 0x4665) == enable) {
    return;
  }
  *(char *)(glContext + 0x4665) = (char)enable;
  *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x800000;
  return;
}

/* _gleSetEnable_VERTEX_PROGRAM_TWO_SIDE_ARB @ 0xcbd70 (72 bytes) */
void _gleSetEnable_VERTEX_PROGRAM_TWO_SIDE_ARB(glContext, cap, enable)
  int glContext;
  undefined4 cap;
  uint enable;
{
  if (*(byte *)(glContext + 0x4666) != enable) {
    *(char *)(glContext + 0x4666) = (char)enable;
    _gleUpdatePolyMode(glContext);
    *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x800000;
  }
  return;
}

/* _gleSetEnable_COLOR_SUM @ 0xcbdd8 (192 bytes) */
void _gleSetEnable_COLOR_SUM(glContext, cap, enable)
  int glContext;
  undefined4 cap;
  uint enable;
{
  undefined *clipInterpFunc;
  undefined *eyeInterpFunc;
  char vertexProgramFlag;
  
  if (*(byte *)(glContext + 0x4fea) != enable) {
    *(char *)(glContext + 0x4fea) = (char)enable;
    if (*(char *)(glContext + 0x30aa) == '\0') {
      vertexProgramFlag = *(char *)(glContext + 0x4664);
    }
    else {
      vertexProgramFlag = *(char *)(glContext + 0x4664);
      if ((vertexProgramFlag == '\0') && (*(int *)(glContext + 0x5434) == 0)) {
        return;
      }
    }
    *(char *)(glContext + 0x316b) = (char)enable;
    if ((vertexProgramFlag == '\0') && (*(int *)(glContext + 0x5434) == 0)) {
      _gleSelectVertexSubmitFunc(glContext);
    }
    else {
      *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x800000;
    }
    eyeInterpFunc = PTR__gleSetEyeInterpFunc_0011203c;
    clipInterpFunc = PTR__gleSetClipInterpFunc_00112038;
    *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x800;
    *(undefined **)(glContext + 0x49c8) = eyeInterpFunc;
    *(undefined **)(glContext + 0x49cc) = clipInterpFunc;
  }
  return;
}

/* _gleSetEnable_COLOR_TABLE @ 0xcbe98 (48 bytes) */
void _gleSetEnable_COLOR_TABLE(glContext, cap, enable)
  int glContext;
  undefined4 cap;
  int enable;
{
  uint newImagingBits;
  
  newImagingBits = *(uint *)(glContext + 0x3410) & 0xffffffdf;
  if (enable != 0) {
    newImagingBits = newImagingBits | 0x20;
  }
  if (*(uint *)(glContext + 0x3410) == newImagingBits) {
    return;
  }
  *(uint *)(glContext + 0x3410) = newImagingBits;
  *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x40000000;
  return;
}

/* _gleSetEnable_POST_COLOR_MATRIX_COLOR_TABLE @ 0xcbec8 (48 bytes) */
void _gleSetEnable_POST_COLOR_MATRIX_COLOR_TABLE(glContext, cap, enable)
  int glContext;
  undefined4 cap;
  int enable;
{
  uint newImagingBits;
  
  newImagingBits = *(uint *)(glContext + 0x3410) & 0xffffff7f;
  if (enable != 0) {
    newImagingBits = newImagingBits | 0x80;
  }
  if (*(uint *)(glContext + 0x3410) == newImagingBits) {
    return;
  }
  *(uint *)(glContext + 0x3410) = newImagingBits;
  *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x40000000;
  return;
}

/* _gleSetEnable_POST_CONVOLUTION_COLOR_TABLE @ 0xcbef8 (48 bytes) */
void _gleSetEnable_POST_CONVOLUTION_COLOR_TABLE(glContext, cap, enable)
  int glContext;
  undefined4 cap;
  int enable;
{
  uint newImagingBits;
  
  newImagingBits = *(uint *)(glContext + 0x3410) & 0xffffffbf;
  if (enable != 0) {
    newImagingBits = newImagingBits | 0x40;
  }
  if (*(uint *)(glContext + 0x3410) == newImagingBits) {
    return;
  }
  *(uint *)(glContext + 0x3410) = newImagingBits;
  *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x40000000;
  return;
}

/* _gleSetEnable_HISTOGRAM @ 0xcbf28 (36 bytes) */
void _gleSetEnable_HISTOGRAM(glContext, cap, enable)
  int glContext;
  undefined4 cap;
  int enable;
{
  uint newImagingBits;
  
  newImagingBits = *(uint *)(glContext + 0x3410) & 0xffffffef;
  if (enable != 0) {
    newImagingBits = newImagingBits | 0x10;
  }
  if (*(uint *)(glContext + 0x3410) == newImagingBits) {
    return;
  }
  *(uint *)(glContext + 0x3410) = newImagingBits;
  return;
}

/* _gleSetEnable_MINMAX @ 0xcbf4c (36 bytes) */
void _gleSetEnable_MINMAX(glContext, cap, enable)
  int glContext;
  undefined4 cap;
  int enable;
{
  uint newImagingBits;
  
  newImagingBits = *(uint *)(glContext + 0x3410) & 0xfffffff7;
  if (enable != 0) {
    newImagingBits = newImagingBits | 8;
  }
  if (*(uint *)(glContext + 0x3410) == newImagingBits) {
    return;
  }
  *(uint *)(glContext + 0x3410) = newImagingBits;
  return;
}

/* _gleSetEnable_CONVOLUTION_1D @ 0xcbf70 (36 bytes) */
void _gleSetEnable_CONVOLUTION_1D(glContext, cap, enable)
  int glContext;
  undefined4 cap;
  int enable;
{
  uint newImagingBits;
  
  newImagingBits = (uint)(enable != 0) | *(uint *)(glContext + 0x3410) & 0xfffffffe;
  if (*(uint *)(glContext + 0x3410) == newImagingBits) {
    return;
  }
  *(uint *)(glContext + 0x3410) = newImagingBits;
  return;
}

/* _gleSetEnable_CONVOLUTION_2D @ 0xcbf94 (36 bytes) */
void _gleSetEnable_CONVOLUTION_2D(glContext, cap, enable)
  int glContext;
  undefined4 cap;
  int enable;
{
  uint newImagingBits;
  
  newImagingBits = *(uint *)(glContext + 0x3410) & 0xfffffffd;
  if (enable != 0) {
    newImagingBits = newImagingBits | 2;
  }
  if (*(uint *)(glContext + 0x3410) == newImagingBits) {
    return;
  }
  *(uint *)(glContext + 0x3410) = newImagingBits;
  return;
}

/* _gleSetEnable_SEPARABLE_2D @ 0xcbfb8 (36 bytes) */
void _gleSetEnable_SEPARABLE_2D(glContext, cap, enable)
  int glContext;
  undefined4 cap;
  int enable;
{
  uint newImagingBits;
  
  newImagingBits = *(uint *)(glContext + 0x3410) & 0xfffffffb;
  if (enable != 0) {
    newImagingBits = newImagingBits | 4;
  }
  if (*(uint *)(glContext + 0x3410) == newImagingBits) {
    return;
  }
  *(uint *)(glContext + 0x3410) = newImagingBits;
  return;
}

/* _gleSetEnable_STENCIL_TEST_TWO_SIDE_EXT @ 0xcbfdc (44 bytes) */
void _gleSetEnable_STENCIL_TEST_TWO_SIDE_EXT(glContext, cap, enable)
  int glContext;
  undefined4 cap;
  int enable;
{
  uint newBits;
  
  newBits = *(uint *)(glContext + 0x3520) & 0xfffffffb | enable << 2;
  if (*(uint *)(glContext + 0x3520) == newBits) {
    return;
  }
  *(uint *)(glContext + 0x3520) = newBits;
  *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x10000000;
  return;
}

/* _gleSetEnable_DEPTH_BOUNDS_TEST_EXT @ 0xcc008 (32 bytes) */
void _gleSetEnable_DEPTH_BOUNDS_TEST_EXT(glContext, cap, enable)
  int glContext;
  undefined4 cap;
  uint enable;
{
  if (*(byte *)(glContext + 0x312a) == enable) {
    return;
  }
  *(char *)(glContext + 0x312a) = (char)enable;
  *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x200;
  return;
}

/* _gleSetEnable_Error @ 0xcc028 (24 bytes) */
void _gleSetEnable_Error(glContext)
  int glContext;
{
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  *(undefined4 *)(glContext + 0x7574) = 0x500;
  return;
}

/* _gleFeedbackCopyPixels @ 0xcc040 (72 bytes) */
void _gleFeedbackCopyPixels(glContext, vertex)
  undefined4 glContext;
  undefined4 vertex;
{
  ((void (*)())_gleFeedbackToken)(glContext,(double)FLOAT_00108f1c);
  _gleFeedbackHitRecord(glContext,vertex);
  return;
}

/* _gleFeedbackDrawPixels @ 0xcc088 (72 bytes) */
void _gleFeedbackDrawPixels(glContext, param_2)
  undefined4 glContext;
  undefined4 param_2;
{
  ((void (*)())_gleFeedbackToken)(glContext,(double)FLOAT_00108f20);
  _gleFeedbackHitRecord(glContext,param_2);
  return;
}

/* _gleFeedbackBitmap @ 0xcc0d0 (72 bytes) */
void _gleFeedbackBitmap(glContext, param_2)
  undefined4 glContext;
  undefined4 param_2;
{
  ((void (*)())_gleFeedbackToken)(glContext,(double)FLOAT_00108f24);
  _gleFeedbackHitRecord(glContext,param_2);
  return;
}

/* _gleFeedbackPoints @ 0xcc118 (112 bytes) */
void _gleFeedbackPoints(glContext, vertexCursor, vertexCount)
  undefined4 glContext;
  uint vertexCursor;
  int vertexCount;
{
  uint vertexEnd;
  
  vertexEnd = vertexCursor + vertexCount * 0x100;
  for (; vertexCursor < vertexEnd; vertexCursor = vertexCursor + 0x100) {
    ((void (*)())_gleFeedbackToken)(glContext,(double)FLOAT_00108f28);
    _gleFeedbackHitRecord(glContext,vertexCursor);
  }
  return;
}

/* _gleFeedbackPointsPtr @ 0xcc188 (112 bytes) */
void _gleFeedbackPointsPtr(glContext, vertexPtrCursor, vertexCount)
  undefined4 glContext;
  undefined4 *vertexPtrCursor;
  int vertexCount;
{
  undefined4 *vertexPtrEnd;
  
  vertexPtrEnd = vertexPtrCursor + vertexCount;
  for (; vertexPtrCursor < vertexPtrEnd; vertexPtrCursor = vertexPtrCursor + 1) {
    ((void (*)())_gleFeedbackToken)(glContext,(double)FLOAT_00108f28);
    _gleFeedbackHitRecord(glContext,*vertexPtrCursor);
  }
  return;
}

/* _gleFeedbackLines_body @ 0xcc204 (116 bytes) */
void _gleFeedbackLines_body(glContext, vertexCursor, vertexEnd)
  undefined4 glContext;
  uint vertexCursor;
  int vertexEnd;
{
  for (; vertexCursor < vertexEnd - 0x100U; vertexCursor = vertexCursor + 0x200) {
    ((void (*)())_gleFeedbackToken)(glContext,(double)FLOAT_00108f2c);
    _gleFeedbackHitRecord(glContext,vertexCursor);
    _gleFeedbackHitRecord(glContext,vertexCursor + 0x100);
  }
  return;
}

