#include "decls.h"

/* _gleSetEnable_CLIP_PLANE @ 0xcb284 (108 bytes) */
int _gleSetEnable_CLIP_PLANE(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  undefined4 param_4;
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = param_2 - 0x3000;
  uVar2 = param_3 << (uVar3 & 0x3f);
  uVar1 = *(uint *)(param_1 + 0x4188) &
          (-2 << (uVar3 & 0x1f) | 0xfffffffeU >> 0x20 - (uVar3 & 0x1f)) | uVar2;
  if (*(uint *)(param_1 + 0x4188) != uVar1) {
    *(uint *)(param_1 + 0x4188) = uVar1;
    _gleUpdateClipPlane(param_1,param_2,uVar2,param_4);
    *(uint *)(param_1 + 0x318) = *(uint *)(param_1 + 0x318) | 0x1000000 << (uVar3 & 0x3f);
  }
  return;
}

/* _gleSetEnable_TEXTURE_GEN_S @ 0xcb2f0 (104 bytes) */
int _gleSetEnable_TEXTURE_GEN_S(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  uint param_3;
{
  int iVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(param_1 + 0x53d4);
  iVar1 = uVar2 * 0x94 + param_1;
  if (*(byte *)(iVar1 + 0x3d78) != param_3) {
    *(char *)(iVar1 + 0x3d78) = (char)param_3;
    _gleUpdateTextureCoordGen(param_1);
    _gleSelectVertexSubmitFunc(param_1);
    *(uint *)(param_1 + 0x314) = *(uint *)(param_1 + 0x314) | 0x10000 << (uVar2 & 0x3f);
  }
  return;
}

/* _gleSetEnable_TEXTURE_GEN_T @ 0xcb358 (104 bytes) */
int _gleSetEnable_TEXTURE_GEN_T(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  uint param_3;
{
  int iVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(param_1 + 0x53d4);
  iVar1 = uVar2 * 0x94 + param_1;
  if (*(byte *)(iVar1 + 0x3d79) != param_3) {
    *(char *)(iVar1 + 0x3d79) = (char)param_3;
    _gleUpdateTextureCoordGen(param_1);
    _gleSelectVertexSubmitFunc(param_1);
    *(uint *)(param_1 + 0x314) = *(uint *)(param_1 + 0x314) | 0x10000 << (uVar2 & 0x3f);
  }
  return;
}

/* _gleSetEnable_TEXTURE_GEN_R @ 0xcb3c0 (96 bytes) */
int _gleSetEnable_TEXTURE_GEN_R(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  uint param_3;
{
  int iVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(param_1 + 0x53d4);
  iVar1 = uVar2 * 0x94 + param_1;
  if (*(byte *)(iVar1 + 0x3d7a) != param_3) {
    *(char *)(iVar1 + 0x3d7a) = (char)param_3;
    _gleUpdateTextureCoordGen(param_1);
    *(uint *)(param_1 + 0x314) = *(uint *)(param_1 + 0x314) | 0x10000 << (uVar2 & 0x3f);
  }
  return;
}

/* _gleSetEnable_TEXTURE_GEN_Q @ 0xcb420 (96 bytes) */
int _gleSetEnable_TEXTURE_GEN_Q(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  uint param_3;
{
  int iVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(param_1 + 0x53d4);
  iVar1 = uVar2 * 0x94 + param_1;
  if (*(byte *)(iVar1 + 0x3d7b) != param_3) {
    *(char *)(iVar1 + 0x3d7b) = (char)param_3;
    _gleUpdateTextureCoordGen(param_1);
    *(uint *)(param_1 + 0x314) = *(uint *)(param_1 + 0x314) | 0x10000 << (uVar2 & 0x3f);
  }
  return;
}

/* _gleSetEnable_MAP1_VERTEX_3 @ 0xcb480 (76 bytes) */
int _gleSetEnable_MAP1_VERTEX_3(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined1 uVar1;
  
  uVar1 = 0x10;
  *(undefined1 *)(param_1 + 0x74e0) = (undefined1)param_3;
  if ((*(char *)(param_1 + 0x74e1) == '\0') && (uVar1 = 0xc, *(char *)(param_1 + 0x74e0) == '\0')) {
    uVar1 = 0;
  }
  *(undefined1 *)(param_1 + 0x7514) = uVar1;
  *(undefined **)(param_1 + 0x4898) = PTR__gleSetVertexEval1Func_0011206c;
  return;
}

/* _gleSetEnable_MAP1_VERTEX_4 @ 0xcb4cc (76 bytes) */
int _gleSetEnable_MAP1_VERTEX_4(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined1 uVar1;
  
  *(undefined1 *)(param_1 + 0x74e1) = (undefined1)param_3;
  uVar1 = 0x10;
  if ((*(char *)(param_1 + 0x74e1) == '\0') && (uVar1 = 0xc, *(char *)(param_1 + 0x74e0) == '\0')) {
    uVar1 = 0;
  }
  *(undefined1 *)(param_1 + 0x7514) = uVar1;
  *(undefined **)(param_1 + 0x4898) = PTR__gleSetVertexEval1Func_0011206c;
  return;
}

/* _gleSetEnable_MAP1_COLOR_4 @ 0xcb518 (52 bytes) */
int _gleSetEnable_MAP1_COLOR_4(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  *(undefined1 *)(param_1 + 0x74e2) = (undefined1)param_3;
  *(undefined **)(param_1 + 0x4898) = PTR__gleSetVertexEval1Func_0011206c;
  *(byte *)(param_1 + 0x7516) = (byte)(-(uint)*(byte *)(param_1 + 0x74e2) >> 0x1b) & 0x10;
  return;
}

/* _gleSetEnable_MAP1_NORMAL @ 0xcb554 (60 bytes) */
int _gleSetEnable_MAP1_NORMAL(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined1 uVar1;
  
  *(undefined1 *)(param_1 + 0x74e4) = (undefined1)param_3;
  uVar1 = 0xc;
  if (*(char *)(param_1 + 0x74e4) == '\0') {
    uVar1 = 0;
  }
  *(undefined1 *)(param_1 + 0x7515) = uVar1;
  *(undefined **)(param_1 + 0x4898) = PTR__gleSetVertexEval1Func_0011206c;
  return;
}

/* _gleSetEnable_MAP1_TEXTURE_COORD_1 @ 0xcb590 (100 bytes) */
int _gleSetEnable_MAP1_TEXTURE_COORD_1(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  byte bVar1;
  
  bVar1 = 0x10;
  *(undefined1 *)(param_1 + 0x74e5) = (undefined1)param_3;
  if (((*(char *)(param_1 + 0x74e8) == '\0') && (bVar1 = 0xc, *(char *)(param_1 + 0x74e7) == '\0'))
     && (bVar1 = 8, *(char *)(param_1 + 0x74e6) == '\0')) {
    bVar1 = (byte)(-(uint)*(byte *)(param_1 + 0x74e5) >> 0x1d) & 4;
  }
  *(byte *)(param_1 + 0x751c) = bVar1;
  *(undefined **)(param_1 + 0x4898) = PTR__gleSetVertexEval1Func_0011206c;
  return;
}

/* _gleSetEnable_MAP1_TEXTURE_COORD_2 @ 0xcb5f4 (100 bytes) */
int _gleSetEnable_MAP1_TEXTURE_COORD_2(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  byte bVar1;
  
  bVar1 = 0x10;
  *(undefined1 *)(param_1 + 0x74e6) = (undefined1)param_3;
  if (((*(char *)(param_1 + 0x74e8) == '\0') && (bVar1 = 0xc, *(char *)(param_1 + 0x74e7) == '\0'))
     && (bVar1 = 8, *(char *)(param_1 + 0x74e6) == '\0')) {
    bVar1 = (byte)(-(uint)*(byte *)(param_1 + 0x74e5) >> 0x1d) & 4;
  }
  *(byte *)(param_1 + 0x751c) = bVar1;
  *(undefined **)(param_1 + 0x4898) = PTR__gleSetVertexEval1Func_0011206c;
  return;
}

/* _gleSetEnable_MAP1_TEXTURE_COORD_3 @ 0xcb658 (100 bytes) */
int _gleSetEnable_MAP1_TEXTURE_COORD_3(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  byte bVar1;
  
  bVar1 = 0x10;
  *(undefined1 *)(param_1 + 0x74e7) = (undefined1)param_3;
  if (((*(char *)(param_1 + 0x74e8) == '\0') && (bVar1 = 0xc, *(char *)(param_1 + 0x74e7) == '\0'))
     && (bVar1 = 8, *(char *)(param_1 + 0x74e6) == '\0')) {
    bVar1 = (byte)(-(uint)*(byte *)(param_1 + 0x74e5) >> 0x1d) & 4;
  }
  *(byte *)(param_1 + 0x751c) = bVar1;
  *(undefined **)(param_1 + 0x4898) = PTR__gleSetVertexEval1Func_0011206c;
  return;
}

/* _gleSetEnable_MAP1_TEXTURE_COORD_4 @ 0xcb6bc (100 bytes) */
int _gleSetEnable_MAP1_TEXTURE_COORD_4(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  byte bVar1;
  
  *(undefined1 *)(param_1 + 0x74e8) = (undefined1)param_3;
  bVar1 = 0x10;
  if (((*(char *)(param_1 + 0x74e8) == '\0') && (bVar1 = 0xc, *(char *)(param_1 + 0x74e7) == '\0'))
     && (bVar1 = 8, *(char *)(param_1 + 0x74e6) == '\0')) {
    bVar1 = (byte)(-(uint)*(byte *)(param_1 + 0x74e5) >> 0x1d) & 4;
  }
  *(byte *)(param_1 + 0x751c) = bVar1;
  *(undefined **)(param_1 + 0x4898) = PTR__gleSetVertexEval1Func_0011206c;
  return;
}

/* _gleSetEnable_MAP2_VERTEX_3 @ 0xcb720 (76 bytes) */
int _gleSetEnable_MAP2_VERTEX_3(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined1 uVar1;
  
  uVar1 = 0x10;
  *(undefined1 *)(param_1 + 0x74e9) = (undefined1)param_3;
  if ((*(char *)(param_1 + 0x74ea) == '\0') && (uVar1 = 0xc, *(char *)(param_1 + 0x74e9) == '\0')) {
    uVar1 = 0;
  }
  *(undefined1 *)(param_1 + 0x7554) = uVar1;
  *(undefined **)(param_1 + 0x489c) = PTR__gleSetVertexEval2Func_00112068;
  return;
}

/* _gleSetEnable_MAP2_VERTEX_4 @ 0xcb76c (76 bytes) */
int _gleSetEnable_MAP2_VERTEX_4(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined1 uVar1;
  
  *(undefined1 *)(param_1 + 0x74ea) = (undefined1)param_3;
  uVar1 = 0x10;
  if ((*(char *)(param_1 + 0x74ea) == '\0') && (uVar1 = 0xc, *(char *)(param_1 + 0x74e9) == '\0')) {
    uVar1 = 0;
  }
  *(undefined1 *)(param_1 + 0x7554) = uVar1;
  *(undefined **)(param_1 + 0x489c) = PTR__gleSetVertexEval2Func_00112068;
  return;
}

/* _gleSetEnable_MAP2_COLOR_4 @ 0xcb7b8 (52 bytes) */
int _gleSetEnable_MAP2_COLOR_4(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  *(undefined1 *)(param_1 + 0x74eb) = (undefined1)param_3;
  *(undefined **)(param_1 + 0x489c) = PTR__gleSetVertexEval2Func_00112068;
  *(byte *)(param_1 + 0x7556) = (byte)(-(uint)*(byte *)(param_1 + 0x74eb) >> 0x1b) & 0x10;
  return;
}

/* _gleSetEnable_MAP2_NORMAL @ 0xcb7f4 (72 bytes) */
int _gleSetEnable_MAP2_NORMAL(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined1 uVar1;
  
  *(undefined1 *)(param_1 + 0x74ed) = (undefined1)param_3;
  if ((*(char *)(param_1 + 0x74ed) != '\0') || (uVar1 = 0, *(char *)(param_1 + 0x74f2) != '\0')) {
    uVar1 = 0xc;
  }
  *(undefined1 *)(param_1 + 0x7555) = uVar1;
  *(undefined **)(param_1 + 0x489c) = PTR__gleSetVertexEval2Func_00112068;
  return;
}

/* _gleSetEnable_MAP2_TEXTURE_COORD_1 @ 0xcb83c (100 bytes) */
int _gleSetEnable_MAP2_TEXTURE_COORD_1(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  byte bVar1;
  
  bVar1 = 0x10;
  *(undefined1 *)(param_1 + 0x74ee) = (undefined1)param_3;
  if (((*(char *)(param_1 + 0x74f1) == '\0') && (bVar1 = 0xc, *(char *)(param_1 + 0x74f0) == '\0'))
     && (bVar1 = 8, *(char *)(param_1 + 0x74ef) == '\0')) {
    bVar1 = (byte)(-(uint)*(byte *)(param_1 + 0x74ee) >> 0x1d) & 4;
  }
  *(byte *)(param_1 + 0x755c) = bVar1;
  *(undefined **)(param_1 + 0x489c) = PTR__gleSetVertexEval2Func_00112068;
  return;
}

/* _gleSetEnable_MAP2_TEXTURE_COORD_2 @ 0xcb8a0 (100 bytes) */
int _gleSetEnable_MAP2_TEXTURE_COORD_2(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  byte bVar1;
  
  bVar1 = 0x10;
  *(undefined1 *)(param_1 + 0x74ef) = (undefined1)param_3;
  if (((*(char *)(param_1 + 0x74f1) == '\0') && (bVar1 = 0xc, *(char *)(param_1 + 0x74f0) == '\0'))
     && (bVar1 = 8, *(char *)(param_1 + 0x74ef) == '\0')) {
    bVar1 = (byte)(-(uint)*(byte *)(param_1 + 0x74ee) >> 0x1d) & 4;
  }
  *(byte *)(param_1 + 0x755c) = bVar1;
  *(undefined **)(param_1 + 0x489c) = PTR__gleSetVertexEval2Func_00112068;
  return;
}

/* _gleSetEnable_MAP2_TEXTURE_COORD_3 @ 0xcb904 (100 bytes) */
int _gleSetEnable_MAP2_TEXTURE_COORD_3(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  byte bVar1;
  
  bVar1 = 0x10;
  *(undefined1 *)(param_1 + 0x74f0) = (undefined1)param_3;
  if (((*(char *)(param_1 + 0x74f1) == '\0') && (bVar1 = 0xc, *(char *)(param_1 + 0x74f0) == '\0'))
     && (bVar1 = 8, *(char *)(param_1 + 0x74ef) == '\0')) {
    bVar1 = (byte)(-(uint)*(byte *)(param_1 + 0x74ee) >> 0x1d) & 4;
  }
  *(byte *)(param_1 + 0x755c) = bVar1;
  *(undefined **)(param_1 + 0x489c) = PTR__gleSetVertexEval2Func_00112068;
  return;
}

/* _gleSetEnable_MAP2_TEXTURE_COORD_4 @ 0xcb968 (100 bytes) */
int _gleSetEnable_MAP2_TEXTURE_COORD_4(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  byte bVar1;
  
  *(undefined1 *)(param_1 + 0x74f1) = (undefined1)param_3;
  bVar1 = 0x10;
  if (((*(char *)(param_1 + 0x74f1) == '\0') && (bVar1 = 0xc, *(char *)(param_1 + 0x74f0) == '\0'))
     && (bVar1 = 8, *(char *)(param_1 + 0x74ef) == '\0')) {
    bVar1 = (byte)(-(uint)*(byte *)(param_1 + 0x74ee) >> 0x1d) & 4;
  }
  *(byte *)(param_1 + 0x755c) = bVar1;
  *(undefined **)(param_1 + 0x489c) = PTR__gleSetVertexEval2Func_00112068;
  return;
}

/* _gleSetEnable_POINT_SMOOTH @ 0xcb9cc (32 bytes) */
int _gleSetEnable_POINT_SMOOTH(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  uint param_3;
{
  if (*(byte *)(param_1 + 0x343c) == param_3) {
    return;
  }
  *(char *)(param_1 + 0x343c) = (char)param_3;
  *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x400000;
  return;
}

/* _gleSetEnable_COLOR_MATERIAL @ 0xcb9ec (136 bytes) */
int _gleSetEnable_COLOR_MATERIAL(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  uint param_3;
{
  char cVar1;
  
  if (*(byte *)(param_1 + 0x30ab) != param_3) {
    *(char *)(param_1 + 0x30ab) = (char)param_3;
    cVar1 = *(char *)(param_1 + 0x4df8);
    _gleSetColorMaterialEnable(param_1);
    if (((param_3 == 0) && (cVar1 == '\0')) && (*(char *)(param_1 + 0x4df8) == '\0')) {
      (**(code **)(param_1 + 0x4de0))(param_1,param_1 + 0x2a0);
    }
    _gleSelectVertexSubmitFunc(param_1);
    *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x40000;
  }
  return;
}

/* _gleSetEnable_AUTO_NORMAL @ 0xcba74 (72 bytes) */
int _gleSetEnable_AUTO_NORMAL(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined1 uVar1;
  
  *(undefined1 *)(param_1 + 0x74f2) = (undefined1)param_3;
  if ((*(char *)(param_1 + 0x74ed) != '\0') || (uVar1 = 0, *(char *)(param_1 + 0x74f2) != '\0')) {
    uVar1 = 0xc;
  }
  *(undefined1 *)(param_1 + 0x7555) = uVar1;
  *(undefined **)(param_1 + 0x489c) = PTR__gleSetVertexEval2Func_00112068;
  return;
}

/* _gleSetEnable_POLYGON_OFFSET_POINT @ 0xcbabc (48 bytes) */
int _gleSetEnable_POLYGON_OFFSET_POINT(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  uint param_3;
{
  if (*(byte *)(param_1 + 0x34db) == param_3) {
    return;
  }
  if (param_3 != 0) {
    *(uint *)(param_1 + 0x4980) = (uint)*(ushort *)(param_1 + 0x4982);
  }
  *(char *)(param_1 + 0x34db) = (char)param_3;
  *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x800000;
  return;
}

/* _gleSetEnable_POLYGON_OFFSET_LINE @ 0xcbaec (48 bytes) */
int _gleSetEnable_POLYGON_OFFSET_LINE(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  uint param_3;
{
  if (*(byte *)(param_1 + 0x34dc) == param_3) {
    return;
  }
  if (param_3 != 0) {
    *(uint *)(param_1 + 0x4980) = (uint)*(ushort *)(param_1 + 0x4982);
  }
  *(char *)(param_1 + 0x34dc) = (char)param_3;
  *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x800000;
  return;
}

/* _gleSetEnable_POLYGON_OFFSET_FILL @ 0xcbb1c (48 bytes) */
int _gleSetEnable_POLYGON_OFFSET_FILL(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  uint param_3;
{
  if (*(byte *)(param_1 + 0x34dd) == param_3) {
    return;
  }
  if (param_3 != 0) {
    *(uint *)(param_1 + 0x4980) = (uint)*(ushort *)(param_1 + 0x4982);
  }
  *(char *)(param_1 + 0x34dd) = (char)param_3;
  *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x800000;
  return;
}

/* _gleSetEnable_REGISTER_COMBINERS_NV @ 0xcbb4c (32 bytes) */
int _gleSetEnable_REGISTER_COMBINERS_NV(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  uint param_3;
{
  if (*(byte *)(param_1 + 0x41f8) == param_3) {
    return;
  }
  *(char *)(param_1 + 0x41f8) = (char)param_3;
  *(uint *)(param_1 + 0x314) = *(uint *)(param_1 + 0x314) | 0x1000000;
  return;
}

/* _gleSetEnable_PER_STAGE_CONSTANTS_NV @ 0xcbb6c (32 bytes) */
int _gleSetEnable_PER_STAGE_CONSTANTS_NV(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  uint param_3;
{
  if (*(byte *)(param_1 + 0x41f9) == param_3) {
    return;
  }
  *(char *)(param_1 + 0x41f9) = (char)param_3;
  *(uint *)(param_1 + 0x314) = *(uint *)(param_1 + 0x314) | 0x1000000;
  return;
}

/* _gleSetEnable_TEXTURE_SHADER_NV @ 0xcbb8c (96 bytes) */
int _gleSetEnable_TEXTURE_SHADER_NV(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  uint param_3;
{
  uint uVar1;
  uint uVar2;
  
  if (*(byte *)(param_1 + 0x3ce4) != param_3) {
    *(char *)(param_1 + 0x3ce4) = (char)param_3;
    *(uint *)(param_1 + 0x314) = *(uint *)(param_1 + 0x314) | 0x2000000;
    uVar1 = 0;
    do {
      uVar2 = uVar1 + 1;
      _gleUpdateTextureParams(param_1,uVar1);
      uVar1 = uVar2;
    } while (uVar2 < 0x10);
  }
  return;
}

/* _gleSetEnable_POINT_SPRITE_ARB @ 0xcbbec (32 bytes) */
int _gleSetEnable_POINT_SPRITE_ARB(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  uint param_3;
{
  if (*(byte *)(param_1 + 0x343d) == param_3) {
    return;
  }
  *(char *)(param_1 + 0x343d) = (char)param_3;
  *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x400000;
  return;
}

/* _gleSetEnable_DEPTH_CLAMP_NV @ 0xcbc0c (32 bytes) */
int _gleSetEnable_DEPTH_CLAMP_NV(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  uint param_3;
{
  if (*(byte *)(param_1 + 0x3129) == param_3) {
    return;
  }
  *(char *)(param_1 + 0x3129) = (char)param_3;
  *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x200;
  return;
}

/* _gleSetEnable_RASTER_POSITION_UNCLIPPED_IBM @ 0xcbc2c (8 bytes) */
int _gleSetEnable_RASTER_POSITION_UNCLIPPED_IBM(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  *(undefined1 *)(param_1 + 0x50b5) = (undefined1)param_3;
  return;
}

/* _gleSetEnable_PN_TRIANGLES_ATI @ 0xcbc34 (32 bytes) */
int _gleSetEnable_PN_TRIANGLES_ATI(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  uint param_3;
{
  if (*(byte *)(param_1 + 0x280c) == param_3) {
    return;
  }
  *(char *)(param_1 + 0x280c) = (char)param_3;
  *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x80000;
  return;
}

/* _gleSetEnable_MULTISAMPLE @ 0xcbc54 (32 bytes) */
int _gleSetEnable_MULTISAMPLE(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  uint param_3;
{
  if (*(byte *)(param_1 + 0x41f0) == param_3) {
    return;
  }
  *(char *)(param_1 + 0x41f0) = (char)param_3;
  *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x20000000;
  return;
}

/* _gleSetEnable_SAMPLE_ALPHA_TO_COVERAGE @ 0xcbc74 (32 bytes) */
int _gleSetEnable_SAMPLE_ALPHA_TO_COVERAGE(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  uint param_3;
{
  if (*(byte *)(param_1 + 0x41f1) == param_3) {
    return;
  }
  *(char *)(param_1 + 0x41f1) = (char)param_3;
  *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x20000000;
  return;
}

/* _gleSetEnable_SAMPLE_ALPHA_TO_ONE @ 0xcbc94 (32 bytes) */
int _gleSetEnable_SAMPLE_ALPHA_TO_ONE(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  uint param_3;
{
  if (*(byte *)(param_1 + 0x41f2) == param_3) {
    return;
  }
  *(char *)(param_1 + 0x41f2) = (char)param_3;
  *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x20000000;
  return;
}

/* _gleSetEnable_SAMPLE_COVERAGE @ 0xcbcb4 (32 bytes) */
int _gleSetEnable_SAMPLE_COVERAGE(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  uint param_3;
{
  if (*(byte *)(param_1 + 0x41f3) == param_3) {
    return;
  }
  *(char *)(param_1 + 0x41f3) = (char)param_3;
  *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x20000000;
  return;
}

/* _gleSetEnable_VERTEX_BLEND_ARB @ 0xcbcd4 (92 bytes) */
int _gleSetEnable_VERTEX_BLEND_ARB(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  uint param_3;
{
  if (*(byte *)(param_1 + 0x4661) != param_3) {
    *(char *)(param_1 + 0x4661) = (char)param_3;
    _gleUpdateInverseNeeds(param_1);
    _gleSelectVertexSubmitFunc(param_1);
    *(uint *)(param_1 + 0x50ac) = *(uint *)(param_1 + 0x50ac) | 1;
    *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x200000;
  }
  return;
}

/* _gleSetEnable_WEIGHT_SUM_UNITY_ARB @ 0xcbd30 (32 bytes) */
int _gleSetEnable_WEIGHT_SUM_UNITY_ARB(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  uint param_3;
{
  if (*(byte *)(param_1 + 0x4662) == param_3) {
    return;
  }
  *(char *)(param_1 + 0x4662) = (char)param_3;
  *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x200000;
  return;
}

/* _gleSetEnable_VERTEX_PROGRAM_POINT_SIZE_ARB @ 0xcbd50 (32 bytes) */
int _gleSetEnable_VERTEX_PROGRAM_POINT_SIZE_ARB(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  uint param_3;
{
  if (*(byte *)(param_1 + 0x4665) == param_3) {
    return;
  }
  *(char *)(param_1 + 0x4665) = (char)param_3;
  *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x800000;
  return;
}

/* _gleSetEnable_VERTEX_PROGRAM_TWO_SIDE_ARB @ 0xcbd70 (72 bytes) */
int _gleSetEnable_VERTEX_PROGRAM_TWO_SIDE_ARB(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  uint param_3;
{
  if (*(byte *)(param_1 + 0x4666) != param_3) {
    *(char *)(param_1 + 0x4666) = (char)param_3;
    _gleUpdatePolyMode(param_1);
    *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x800000;
  }
  return;
}

/* _gleSetEnable_COLOR_SUM @ 0xcbdd8 (192 bytes) */
int _gleSetEnable_COLOR_SUM(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  uint param_3;
{
  undefined *puVar1;
  undefined *puVar2;
  char cVar3;
  
  if (*(byte *)(param_1 + 0x4fea) != param_3) {
    *(char *)(param_1 + 0x4fea) = (char)param_3;
    if (*(char *)(param_1 + 0x30aa) == '\0') {
      cVar3 = *(char *)(param_1 + 0x4664);
    }
    else {
      cVar3 = *(char *)(param_1 + 0x4664);
      if ((cVar3 == '\0') && (*(int *)(param_1 + 0x5434) == 0)) {
        return;
      }
    }
    *(char *)(param_1 + 0x316b) = (char)param_3;
    if ((cVar3 == '\0') && (*(int *)(param_1 + 0x5434) == 0)) {
      _gleSelectVertexSubmitFunc(param_1);
    }
    else {
      *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x800000;
    }
    puVar2 = PTR__gleSetEyeInterpFunc_0011203c;
    puVar1 = PTR__gleSetClipInterpFunc_00112038;
    *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x800;
    *(undefined **)(param_1 + 0x49c8) = puVar2;
    *(undefined **)(param_1 + 0x49cc) = puVar1;
  }
  return;
}

/* _gleSetEnable_COLOR_TABLE @ 0xcbe98 (48 bytes) */
int _gleSetEnable_COLOR_TABLE(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  int param_3;
{
  uint uVar1;
  
  uVar1 = *(uint *)(param_1 + 0x3410) & 0xffffffdf;
  if (param_3 != 0) {
    uVar1 = uVar1 | 0x20;
  }
  if (*(uint *)(param_1 + 0x3410) == uVar1) {
    return;
  }
  *(uint *)(param_1 + 0x3410) = uVar1;
  *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x40000000;
  return;
}

/* _gleSetEnable_POST_COLOR_MATRIX_COLOR_TABLE @ 0xcbec8 (48 bytes) */
int _gleSetEnable_POST_COLOR_MATRIX_COLOR_TABLE(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  int param_3;
{
  uint uVar1;
  
  uVar1 = *(uint *)(param_1 + 0x3410) & 0xffffff7f;
  if (param_3 != 0) {
    uVar1 = uVar1 | 0x80;
  }
  if (*(uint *)(param_1 + 0x3410) == uVar1) {
    return;
  }
  *(uint *)(param_1 + 0x3410) = uVar1;
  *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x40000000;
  return;
}

/* _gleSetEnable_POST_CONVOLUTION_COLOR_TABLE @ 0xcbef8 (48 bytes) */
int _gleSetEnable_POST_CONVOLUTION_COLOR_TABLE(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  int param_3;
{
  uint uVar1;
  
  uVar1 = *(uint *)(param_1 + 0x3410) & 0xffffffbf;
  if (param_3 != 0) {
    uVar1 = uVar1 | 0x40;
  }
  if (*(uint *)(param_1 + 0x3410) == uVar1) {
    return;
  }
  *(uint *)(param_1 + 0x3410) = uVar1;
  *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x40000000;
  return;
}

/* _gleSetEnable_HISTOGRAM @ 0xcbf28 (36 bytes) */
int _gleSetEnable_HISTOGRAM(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  int param_3;
{
  uint uVar1;
  
  uVar1 = *(uint *)(param_1 + 0x3410) & 0xffffffef;
  if (param_3 != 0) {
    uVar1 = uVar1 | 0x10;
  }
  if (*(uint *)(param_1 + 0x3410) == uVar1) {
    return;
  }
  *(uint *)(param_1 + 0x3410) = uVar1;
  return;
}

/* _gleSetEnable_MINMAX @ 0xcbf4c (36 bytes) */
int _gleSetEnable_MINMAX(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  int param_3;
{
  uint uVar1;
  
  uVar1 = *(uint *)(param_1 + 0x3410) & 0xfffffff7;
  if (param_3 != 0) {
    uVar1 = uVar1 | 8;
  }
  if (*(uint *)(param_1 + 0x3410) == uVar1) {
    return;
  }
  *(uint *)(param_1 + 0x3410) = uVar1;
  return;
}

/* _gleSetEnable_CONVOLUTION_1D @ 0xcbf70 (36 bytes) */
int _gleSetEnable_CONVOLUTION_1D(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  int param_3;
{
  uint uVar1;
  
  uVar1 = (uint)(param_3 != 0) | *(uint *)(param_1 + 0x3410) & 0xfffffffe;
  if (*(uint *)(param_1 + 0x3410) == uVar1) {
    return;
  }
  *(uint *)(param_1 + 0x3410) = uVar1;
  return;
}

/* _gleSetEnable_CONVOLUTION_2D @ 0xcbf94 (36 bytes) */
int _gleSetEnable_CONVOLUTION_2D(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  int param_3;
{
  uint uVar1;
  
  uVar1 = *(uint *)(param_1 + 0x3410) & 0xfffffffd;
  if (param_3 != 0) {
    uVar1 = uVar1 | 2;
  }
  if (*(uint *)(param_1 + 0x3410) == uVar1) {
    return;
  }
  *(uint *)(param_1 + 0x3410) = uVar1;
  return;
}

/* _gleSetEnable_SEPARABLE_2D @ 0xcbfb8 (36 bytes) */
int _gleSetEnable_SEPARABLE_2D(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  int param_3;
{
  uint uVar1;
  
  uVar1 = *(uint *)(param_1 + 0x3410) & 0xfffffffb;
  if (param_3 != 0) {
    uVar1 = uVar1 | 4;
  }
  if (*(uint *)(param_1 + 0x3410) == uVar1) {
    return;
  }
  *(uint *)(param_1 + 0x3410) = uVar1;
  return;
}

/* _gleSetEnable_STENCIL_TEST_TWO_SIDE_EXT @ 0xcbfdc (44 bytes) */
int _gleSetEnable_STENCIL_TEST_TWO_SIDE_EXT(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  int param_3;
{
  uint uVar1;
  
  uVar1 = *(uint *)(param_1 + 0x3520) & 0xfffffffb | param_3 << 2;
  if (*(uint *)(param_1 + 0x3520) == uVar1) {
    return;
  }
  *(uint *)(param_1 + 0x3520) = uVar1;
  *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x10000000;
  return;
}

/* _gleSetEnable_DEPTH_BOUNDS_TEST_EXT @ 0xcc008 (32 bytes) */
int _gleSetEnable_DEPTH_BOUNDS_TEST_EXT(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  uint param_3;
{
  if (*(byte *)(param_1 + 0x312a) == param_3) {
    return;
  }
  *(char *)(param_1 + 0x312a) = (char)param_3;
  *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x200;
  return;
}

/* _gleSetEnable_Error @ 0xcc028 (24 bytes) */
int _gleSetEnable_Error(param_1)
  int param_1;
{
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  *(undefined4 *)(param_1 + 0x7574) = 0x500;
  return;
}

/* _gleFeedbackCopyPixels @ 0xcc040 (72 bytes) */
int _gleFeedbackCopyPixels(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  ((void (*)())_gleFeedbackToken)(param_1,(double)FLOAT_00108f1c);
  _gleFeedbackHitRecord(param_1,param_2);
  return;
}

/* _gleFeedbackDrawPixels @ 0xcc088 (72 bytes) */
int _gleFeedbackDrawPixels(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  ((void (*)())_gleFeedbackToken)(param_1,(double)FLOAT_00108f20);
  _gleFeedbackHitRecord(param_1,param_2);
  return;
}

/* _gleFeedbackBitmap @ 0xcc0d0 (72 bytes) */
int _gleFeedbackBitmap(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  ((void (*)())_gleFeedbackToken)(param_1,(double)FLOAT_00108f24);
  _gleFeedbackHitRecord(param_1,param_2);
  return;
}

/* _gleFeedbackPoints @ 0xcc118 (112 bytes) */
int _gleFeedbackPoints(param_1, param_2)
  undefined4 param_1;
  uint param_2;
{
  int in_r5;
  uint uVar1;
  
  uVar1 = param_2 + in_r5 * 0x100;
  for (; param_2 < uVar1; param_2 = param_2 + 0x100) {
    ((void (*)())_gleFeedbackToken)(param_1,(double)FLOAT_00108f28);
    _gleFeedbackHitRecord(param_1,param_2);
  }
  return;
}

/* _gleFeedbackPointsPtr @ 0xcc188 (112 bytes) */
int _gleFeedbackPointsPtr(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  int in_r5;
  undefined4 *puVar1;
  
  puVar1 = param_2 + in_r5;
  for (; param_2 < puVar1; param_2 = param_2 + 1) {
    ((void (*)())_gleFeedbackToken)(param_1,(double)FLOAT_00108f28);
    _gleFeedbackHitRecord(param_1,*param_2);
  }
  return;
}

/* FUN_000cc204 @ 0xcc204 (116 bytes) */
int FUN_000cc204(param_1, param_2, param_3)
  undefined4 param_1;
  uint param_2;
  int param_3;
{
  for (; param_2 < param_3 - 0x100U; param_2 = param_2 + 0x200) {
    ((void (*)())_gleFeedbackToken)(param_1,(double)FLOAT_00108f2c);
    _gleFeedbackHitRecord(param_1,param_2);
    _gleFeedbackHitRecord(param_1,param_2 + 0x100);
  }
  return;
}

