#include "decls.h"

/* _gleUpdatePrimitiveData @ 0x66d8 (1928 bytes) */
int _gleUpdatePrimitiveData(param_1)
  int param_1;
{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  uint uVar4;
  
  if (*(int *)(param_1 + 0x4e1c) == 0x1c00) {
    if (*(char *)(param_1 + 0x7580) == '\0') {
      if (*(undefined **)(param_1 + 0x5408) == (undefined *)0x0) {
        uVar4 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x128) == 0);
        uVar4 = *(uint *)(param_1 + 0x4680) & uVar4 | *(uint *)(param_1 + 0x4684) & ~uVar4;
        puVar3 = PTR__glEnd_Exec_00112164;
      }
      else if (*(undefined **)(param_1 + 0x5408) == ((unsigned char *)0x00001300)) {
        uVar4 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x128) == 0);
        uVar4 = *(uint *)(param_1 + 0x4680) & uVar4 | *(uint *)(param_1 + 0x4684) & ~uVar4;
        puVar3 = PTR__glEnd_Comp_00112388;
      }
      else {
        uVar4 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x128) == 0);
        uVar4 = *(uint *)(param_1 + 0x4680) & uVar4 | *(uint *)(param_1 + 0x4684) & ~uVar4;
        puVar3 = PTR__glEnd_CompExec_00112384;
      }
      *(undefined **)(uVar4 + 0x128) = puVar3;
      puVar2 = PTR__gleVPBeginLines_0011237c;
      puVar1 = PTR__gleBeginLinesRenderSmooth_00112354;
      puVar3 = PTR__gleBeginLinesRenderFlat_00112330;
      if ((*(char *)(param_1 + 0x4664) == '\0') && (*(int *)(param_1 + 0x5434) == 0)) {
        if (*(int *)(param_1 + 0x34f4) == 0x1d01) {
          *(undefined **)(param_1 + 0x49e0) = PTR__gleBeginPointsRender_00112358;
          puVar3 = PTR__gleBeginLineLoopRenderSmooth_00112350;
          *(undefined **)(param_1 + 0x49e4) = puVar1;
          puVar1 = PTR__gleBeginLineStripRenderSmooth_0011234c;
          *(undefined **)(param_1 + 0x49e8) = puVar3;
          puVar3 = PTR__gleBeginTrianglesRenderSmooth_00112348;
          *(undefined **)(param_1 + 0x49ec) = puVar1;
          puVar1 = PTR__gleBeginTriangleStripRenderSmooth_00112344;
          *(undefined **)(param_1 + 0x49f0) = puVar3;
          puVar3 = PTR__gleBeginTriangleFanRenderSmooth_00112340;
          *(undefined **)(param_1 + 0x49f4) = puVar1;
          puVar1 = PTR__gleBeginQuadsRenderSmooth_0011233c;
          *(undefined **)(param_1 + 0x49f8) = puVar3;
          puVar3 = PTR__gleBeginQuadStripRenderSmooth_00112338;
          *(undefined **)(param_1 + 0x49fc) = puVar1;
          *(undefined **)(param_1 + 0x4a00) = puVar3;
          puVar3 = PTR__gleBeginPolygonRenderSmooth_00112334;
        }
        else {
          *(undefined **)(param_1 + 0x49e0) = PTR__gleBeginPointsRender_00112358;
          puVar2 = PTR__gleBeginLineLoopRenderFlat_0011232c;
          *(undefined **)(param_1 + 0x49e4) = puVar3;
          puVar1 = PTR__gleBeginLineStripRenderFlat_00112328;
          *(undefined **)(param_1 + 0x49e8) = puVar2;
          puVar3 = PTR__gleBeginTrianglesRenderFlat_00112324;
          *(undefined **)(param_1 + 0x49ec) = puVar1;
          puVar1 = PTR__gleBeginTriangleStripRenderFlat_00112320;
          *(undefined **)(param_1 + 0x49f0) = puVar3;
          puVar3 = PTR__gleBeginTriangleFanRenderFlat_0011231c;
          *(undefined **)(param_1 + 0x49f4) = puVar1;
          puVar1 = PTR__gleBeginQuadsRenderFlat_00112318;
          *(undefined **)(param_1 + 0x49f8) = puVar3;
          puVar3 = PTR__gleBeginQuadStripRenderFlat_00112314;
          *(undefined **)(param_1 + 0x49fc) = puVar1;
          *(undefined **)(param_1 + 0x4a00) = puVar3;
          puVar3 = PTR__gleBeginPolygonRenderFlat_00112310;
        }
      }
      else {
        *(undefined **)(param_1 + 0x49e0) = PTR__gleVPBeginPoints_00112380;
        puVar3 = PTR__gleVPBeginLineLoop_00112378;
        *(undefined **)(param_1 + 0x49e4) = puVar2;
        puVar1 = PTR__gleVPBeginLineStrip_00112374;
        *(undefined **)(param_1 + 0x49e8) = puVar3;
        puVar3 = PTR__gleVPBeginTriangles_00112370;
        *(undefined **)(param_1 + 0x49ec) = puVar1;
        puVar1 = PTR__gleVPBeginTriangleStrip_0011236c;
        *(undefined **)(param_1 + 0x49f0) = puVar3;
        puVar3 = PTR__gleVPBeginTriangleFan_00112368;
        *(undefined **)(param_1 + 0x49f4) = puVar1;
        puVar1 = PTR__gleVPBeginQuads_00112364;
        *(undefined **)(param_1 + 0x49f8) = puVar3;
        puVar3 = PTR__gleVPBeginQuadStrip_00112360;
        *(undefined **)(param_1 + 0x49fc) = puVar1;
        *(undefined **)(param_1 + 0x4a00) = puVar3;
        puVar3 = PTR__gleVPBeginPolygon_0011235c;
      }
    }
    else if (*(char *)(*(int *)(param_1 + 0x468c) + 0x7a) == '\0') {
      if (*(int *)(param_1 + 0x5408) == 0) {
        uVar4 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x128) == 0);
        *(undefined **)
         ((*(uint *)(param_1 + 0x4680) & uVar4 | *(uint *)(param_1 + 0x4684) & ~uVar4) + 0x128) =
             PTR__glEndRDirty_Exec_00112160;
      }
      puVar1 = PTR__gleVPBeginLinesTCLRDirty_001123d4;
      puVar3 = PTR__gleBeginLinesRenderTCLRDirty_001123ac;
      puVar2 = PTR__gleBeginPrimitiveTCLRDirtyFunc_001113d8;
      if (*(int *)(param_1 + 0x48d0) != 0) goto LAB_000068ec;
      if ((*(char *)(param_1 + 0x4664) == '\0') && (*(int *)(param_1 + 0x5434) == 0)) {
        *(undefined **)(param_1 + 0x49e0) = PTR__gleBeginPointsRenderTCLRDirty_001123b0;
        puVar2 = PTR__gleBeginLineLoopRenderTCLRDirty_001123a8;
        *(undefined **)(param_1 + 0x49e4) = puVar3;
        puVar1 = PTR__gleBeginLineStripRenderTCLRDirty_001123a4;
        *(undefined **)(param_1 + 0x49e8) = puVar2;
        puVar3 = PTR__gleBeginTrianglesRenderTCLRDirty_001123a0;
        *(undefined **)(param_1 + 0x49ec) = puVar1;
        puVar1 = PTR__gleBeginTriangleStripRenderTCLRDirty_0011239c;
        *(undefined **)(param_1 + 0x49f0) = puVar3;
        puVar3 = PTR__gleBeginTriangleFanRenderTCLRDirty_00112398;
        *(undefined **)(param_1 + 0x49f4) = puVar1;
        puVar1 = PTR__gleBeginQuadsRenderTCLRDirty_00112394;
        *(undefined **)(param_1 + 0x49f8) = puVar3;
        puVar3 = PTR__gleBeginQuadStripRenderTCLRDirty_00112390;
        *(undefined **)(param_1 + 0x49fc) = puVar1;
        *(undefined **)(param_1 + 0x4a00) = puVar3;
        puVar3 = PTR__gleBeginPolygonRenderTCLRDirty_0011238c;
      }
      else {
        *(undefined **)(param_1 + 0x49e0) = PTR__gleVPBeginPointsTCLRDirty_001123d8;
        puVar3 = PTR__gleVPBeginLineLoopTCLRDirty_001123d0;
        *(undefined **)(param_1 + 0x49e4) = puVar1;
        puVar1 = PTR__gleVPBeginLineStripTCLRDirty_001123cc;
        *(undefined **)(param_1 + 0x49e8) = puVar3;
        puVar3 = PTR__gleVPBeginTrianglesTCLRDirty_001123c8;
        *(undefined **)(param_1 + 0x49ec) = puVar1;
        puVar1 = PTR__gleVPBeginTriangleStripTCLRDirty_001123c4;
        *(undefined **)(param_1 + 0x49f0) = puVar3;
        puVar3 = PTR__gleVPBeginTriangleFanTCLRDirty_001123c0;
        *(undefined **)(param_1 + 0x49f4) = puVar1;
        puVar1 = PTR__gleVPBeginQuadsTCLRDirty_001123bc;
        *(undefined **)(param_1 + 0x49f8) = puVar3;
        puVar3 = PTR__gleVPBeginQuadStripTCLRDirty_001123b8;
        *(undefined **)(param_1 + 0x49fc) = puVar1;
        *(undefined **)(param_1 + 0x4a00) = puVar3;
        puVar3 = PTR__gleVPBeginPolygonTCLRDirty_001123b4;
      }
    }
    else {
      if (*(int *)(param_1 + 0x5408) == 0) {
        if (*(char *)(param_1 + 0x4df8) == '\0') {
          uVar4 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x128) == 0);
          uVar4 = *(uint *)(param_1 + 0x4680) & uVar4 | *(uint *)(param_1 + 0x4684) & ~uVar4;
          puVar3 = PTR__glEndNoMat_Exec_00112168;
        }
        else {
          uVar4 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x128) == 0);
          uVar4 = *(uint *)(param_1 + 0x4680) & uVar4 | *(uint *)(param_1 + 0x4684) & ~uVar4;
          puVar3 = PTR__glEnd_Exec_00112164;
        }
        *(undefined **)(uVar4 + 0x128) = puVar3;
      }
      puVar1 = PTR__gleVPBeginLinesTCL_00112424;
      puVar3 = PTR__gleBeginLinesRenderTCL_001123fc;
      puVar2 = PTR__gleBeginPrimitiveTCLFunc_001113dc;
      if (*(int *)(param_1 + 0x48d0) != 0) {
LAB_000068ec:
        *(undefined **)(param_1 + 0x4a04) = puVar2;
        *(undefined **)(param_1 + 0x49e0) = puVar2;
        *(undefined **)(param_1 + 0x49e4) = puVar2;
        *(undefined **)(param_1 + 0x49e8) = puVar2;
        *(undefined **)(param_1 + 0x49ec) = puVar2;
        *(undefined **)(param_1 + 0x49f0) = puVar2;
        *(undefined **)(param_1 + 0x49f4) = puVar2;
        *(undefined **)(param_1 + 0x49f8) = puVar2;
        *(undefined **)(param_1 + 0x49fc) = puVar2;
        *(undefined **)(param_1 + 0x4a00) = puVar2;
        goto LAB_00006d54;
      }
      if ((*(char *)(param_1 + 0x4664) == '\0') && (*(int *)(param_1 + 0x5434) == 0)) {
        *(undefined **)(param_1 + 0x49e0) = PTR__gleBeginPointsRenderTCL_00112400;
        puVar2 = PTR__gleBeginLineLoopRenderTCL_001123f8;
        *(undefined **)(param_1 + 0x49e4) = puVar3;
        puVar1 = PTR__gleBeginLineStripRenderTCL_001123f4;
        *(undefined **)(param_1 + 0x49e8) = puVar2;
        puVar3 = PTR__gleBeginTrianglesRenderTCL_001123f0;
        *(undefined **)(param_1 + 0x49ec) = puVar1;
        puVar1 = PTR__gleBeginTriangleStripRenderTCL_001123ec;
        *(undefined **)(param_1 + 0x49f0) = puVar3;
        puVar3 = PTR__gleBeginTriangleFanRenderTCL_001123e8;
        *(undefined **)(param_1 + 0x49f4) = puVar1;
        puVar1 = PTR__gleBeginQuadsRenderTCL_001123e4;
        *(undefined **)(param_1 + 0x49f8) = puVar3;
        puVar3 = PTR__gleBeginQuadStripRenderTCL_001123e0;
        *(undefined **)(param_1 + 0x49fc) = puVar1;
        *(undefined **)(param_1 + 0x4a00) = puVar3;
        puVar3 = PTR__gleBeginPolygonRenderTCL_001123dc;
      }
      else {
        *(undefined **)(param_1 + 0x49e0) = PTR__gleVPBeginPointsTCL_00112428;
        puVar3 = PTR__gleVPBeginLineLoopTCL_00112420;
        *(undefined **)(param_1 + 0x49e4) = puVar1;
        puVar1 = PTR__gleVPBeginLineStripTCL_0011241c;
        *(undefined **)(param_1 + 0x49e8) = puVar3;
        puVar3 = PTR__gleVPBeginTrianglesTCL_00112418;
        *(undefined **)(param_1 + 0x49ec) = puVar1;
        puVar1 = PTR__gleVPBeginTriangleStripTCL_00112414;
        *(undefined **)(param_1 + 0x49f0) = puVar3;
        puVar3 = PTR__gleVPBeginTriangleFanTCL_00112410;
        *(undefined **)(param_1 + 0x49f4) = puVar1;
        puVar1 = PTR__gleVPBeginQuadsTCL_0011240c;
        *(undefined **)(param_1 + 0x49f8) = puVar3;
        puVar3 = PTR__gleVPBeginQuadStripTCL_00112408;
        *(undefined **)(param_1 + 0x49fc) = puVar1;
        *(undefined **)(param_1 + 0x4a00) = puVar3;
        puVar3 = PTR__gleVPBeginPolygonTCL_00112404;
      }
    }
  }
  else {
    if (*(undefined **)(param_1 + 0x5408) == (undefined *)0x0) {
      uVar4 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x128) == 0);
      uVar4 = *(uint *)(param_1 + 0x4680) & uVar4 | *(uint *)(param_1 + 0x4684) & ~uVar4;
      puVar3 = PTR__glEnd_Exec_00112164;
    }
    else if (*(undefined **)(param_1 + 0x5408) == ((unsigned char *)0x00001300)) {
      uVar4 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x128) == 0);
      uVar4 = *(uint *)(param_1 + 0x4680) & uVar4 | *(uint *)(param_1 + 0x4684) & ~uVar4;
      puVar3 = PTR__glEnd_Comp_00112388;
    }
    else {
      uVar4 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x128) == 0);
      uVar4 = *(uint *)(param_1 + 0x4680) & uVar4 | *(uint *)(param_1 + 0x4684) & ~uVar4;
      puVar3 = PTR__glEnd_CompExec_00112384;
    }
    *(undefined **)(uVar4 + 0x128) = puVar3;
    puVar3 = PTR__gleBeginLinesSelectFeedback_00112308;
    *(undefined **)(param_1 + 0x49e0) = PTR__gleBeginPointsSelectFeedback_0011230c;
    puVar1 = PTR__gleBeginLineLoopSelectFeedback_00112304;
    *(undefined **)(param_1 + 0x49e4) = puVar3;
    puVar3 = PTR__gleBeginLineStripSelectFeedback_00112300;
    *(undefined **)(param_1 + 0x49e8) = puVar1;
    puVar1 = PTR__gleBeginTrianglesSelectFeedback_001122fc;
    *(undefined **)(param_1 + 0x49ec) = puVar3;
    puVar3 = PTR__gleBeginTriangleStripSelectFeedback_001122f8;
    *(undefined **)(param_1 + 0x49f0) = puVar1;
    puVar1 = PTR__gleBeginTriangleFanSelectFeedback_001122f4;
    *(undefined **)(param_1 + 0x49f4) = puVar3;
    puVar3 = PTR__gleBeginQuadsSelectFeedback_001122f0;
    *(undefined **)(param_1 + 0x49f8) = puVar1;
    *(undefined **)(param_1 + 0x49fc) = puVar3;
    puVar3 = PTR__gleBeginPolygonSelectFeedback_001122e8;
    *(undefined **)(param_1 + 0x4a00) = PTR__gleBeginQuadStripSelectFeedback_001122ec;
  }
  *(undefined **)(param_1 + 0x4a04) = puVar3;
LAB_00006d54:
  puVar3 = PTR__gleBeginRSLNoop_001113d4;
  if ((*(char *)(param_1 + 0x34da) != '\0') && (*(short *)(param_1 + 0x34d6) == 0x408)) {
    *(undefined **)(param_1 + 0x4a04) = PTR__gleBeginRSLNoop_001113d4;
    *(undefined **)(param_1 + 0x49f0) = puVar3;
    *(undefined **)(param_1 + 0x49f4) = puVar3;
    *(undefined **)(param_1 + 0x49f8) = puVar3;
    *(undefined **)(param_1 + 0x49fc) = puVar3;
    *(undefined **)(param_1 + 0x4a00) = puVar3;
  }
  if (*(char *)(param_1 + 0x759c) == '\0') {
    uVar4 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x10) == 0);
    uVar4 = *(uint *)(param_1 + 0x4680) & uVar4 | *(uint *)(param_1 + 0x4684) & ~uVar4;
    puVar3 = PTR__glBegin_NoopExec_00112078;
  }
  else if (*(undefined **)(param_1 + 0x5408) == (undefined *)0x0) {
    uVar4 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x10) == 0);
    uVar4 = *(uint *)(param_1 + 0x4680) & uVar4 | *(uint *)(param_1 + 0x4684) & ~uVar4;
    puVar3 = PTR__glBegin_Exec_00112074;
  }
  else if (*(undefined **)(param_1 + 0x5408) == ((unsigned char *)0x00001300)) {
    uVar4 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x10) == 0);
    uVar4 = *(uint *)(param_1 + 0x4680) & uVar4 | *(uint *)(param_1 + 0x4684) & ~uVar4;
    puVar3 = PTR__glBegin_Comp_001122e4;
  }
  else {
    uVar4 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x10) == 0);
    uVar4 = *(uint *)(param_1 + 0x4680) & uVar4 | *(uint *)(param_1 + 0x4684) & ~uVar4;
    puVar3 = PTR__glBegin_CompExec_001122e0;
  }
  *(undefined **)(uVar4 + 0x10) = puVar3;
  return;
}

/* _gleUpdateState @ 0x6e60 (480 bytes) */
int _gleUpdateState(param_1)
  int param_1;
{
  undefined *puVar1;
  undefined1 uVar2;
  undefined4 extraout_r4;
  undefined4 in_r5;
  undefined4 in_r6;
  int iVar3;
  int iVar4;
  double extraout_f1;
  double dVar5;
  double fparam_1;
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
  
  iVar3 = *(int *)(*(int *)(param_1 + 0x468c) + 0x10);
  iVar4 = *(int *)(*(int *)(param_1 + 0x468c) + 0xc);
  *(uint *)(param_1 + 0x314) = *(uint *)(param_1 + 0x314) | 0x3ffffff;
  *(uint *)(param_1 + 0x318) = *(uint *)(param_1 + 0x318) | 0xfffffffd;
  *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x7ffffff;
  *(undefined4 *)(param_1 + 800) = 0xffffffff;
  *(uint *)(param_1 + 0x50ac) = *(uint *)(param_1 + 0x50ac) | 1;
  *(undefined4 *)(param_1 + 0x310) = 0xffffffff;
  if (((*(char *)(param_1 + 0x30aa) == '\0') || (*(char *)(param_1 + 0x4664) != '\0')) ||
     (*(int *)(param_1 + 0x5434) != 0)) {
    uVar2 = *(undefined1 *)(param_1 + 0x4fea);
  }
  else {
    uVar2 = *(short *)(param_1 + 0x30a8) == -0x7e06;
  }
  *(undefined1 *)(param_1 + 0x316b) = uVar2;
  if (iVar4 < *(int *)(param_1 + 0x1ba8)) {
    *(int *)(param_1 + 0x1ba8) = iVar4;
  }
  if (iVar3 < *(int *)(param_1 + 0x1bac)) {
    *(int *)(param_1 + 0x1bac) = iVar3;
  }
  ((int (*)())_gleUpdateLightColorChangeFunc)(param_1);
  ((int (*)())_gleSetColorMaterialEnable)(param_1);
  *(undefined1 *)(*(int *)(param_1 + 0x4dd0) + 0x234) = 0x1f;
  *(undefined1 *)(*(int *)(param_1 + 0x4dd4) + 0x234) = 0x1f;
  iVar3 = 0;
  dVar5 = extraout_f1;
  do {
    dVar5 = (double)((double (*)())_gleUpdateLightPosition)(param_1,iVar3,dVar5);
    ((void (*)())_gleUpdateLightDirection)(param_1,iVar3,dVar5);
    ((int (*)())_gleUpdateLightExponents)(param_1,iVar3);
    iVar4 = iVar3 + 1;
    dVar5 = (double)((int (*)())_gleUpdateLightAttenuation)(param_1,iVar3);
    iVar3 = iVar4;
  } while (iVar4 < 8);
  ((int (*)())_gleUpdateInverseNeeds)(param_1);
  ((int (*)())_gleUpdateLightModel)(param_1);
  ((int (*)())_gleUpdateClipPlane)(param_1,extraout_r4,in_r5,in_r6);
  ((int (*)())_gleUpdateMatrixMode)(param_1);
  ((int (*)())_gleUpdateMatrixFunc)(param_1);
  ((void (*)())_gleUpdateDepthRangeData)(param_1,fparam_1,in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8,in_stack_ffffffb8,
             in_stack_ffffffc0,in_stack_ffffffc8,in_stack_ffffffd0,in_stack_ffffffd8);
  ((int (*)())_gleUpdateTextureCoordGen)(param_1);
  iVar3 = 0;
  do {
    iVar4 = iVar3 + 1;
    ((int (*)())_gleUpdateTextureParams)(param_1,iVar3);
    iVar3 = iVar4;
  } while (iVar4 < 0x10);
  ((double (*)())_gleUpdateFogData)(param_1);
  ((int (*)())_gleUpdatePolyMode)(param_1);
  dVar5 = (double)((int (*)())_gleUpdateEvalData)(param_1);
  ((void (*)())_gleUpdateViewScissorData)(param_1,dVar5,in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8);
  puVar1 = PTR__gleSetClipInterpFunc_00112038;
  *(undefined **)(param_1 + 0x49c8) = PTR__gleSetEyeInterpFunc_0011203c;
  *(undefined **)(param_1 + 0x49cc) = puVar1;
  ((int (*)())_gleSelectVertexAddMaterialFunc)(param_1);
  ((int (*)())_gleSelectVertexSubmitFunc)(param_1);
  return;
}

/* _gleUpdateLightColorChangeFunc @ 0x7040 (468 bytes) */
int _gleUpdateLightColorChangeFunc(param_1)
  int param_1;
{
  ushort uVar1;
  char cVar2;
  code *pcVar3;
  
  if (*(short *)(param_1 + 0x30a4) == 0x404) {
    uVar1 = *(ushort *)(param_1 + 0x30a6);
    pcVar3 = (code *)PTR__gleLightMaterialRGBAChange_F_D_001121bc;
    if (uVar1 != 0x1201) {
      if (uVar1 < 0x1202) {
        pcVar3 = (code *)PTR__gleLightMaterialRGBAChange_F_A_001121c0;
        if (uVar1 != 0x1200) {
LAB_000070d4:
          pcVar3 = (code *)PTR__gleLightMaterialRGBAChange_F_AD_001121b4;
        }
      }
      else {
        pcVar3 = (code *)PTR__gleLightMaterialRGBAChange_F_S_001121b8;
        if ((uVar1 != 0x1202) &&
           (pcVar3 = (code *)PTR__gleLightMaterialRGBAChange_F_E_001121c4, uVar1 != 0x1600))
        goto LAB_000070d4;
      }
    }
  }
  else if (*(short *)(param_1 + 0x30a4) == 0x405) {
    uVar1 = *(ushort *)(param_1 + 0x30a6);
    pcVar3 = (code *)PTR__gleLightMaterialRGBAChange_B_D_001121a8;
    if (uVar1 != 0x1201) {
      if (uVar1 < 0x1202) {
        pcVar3 = (code *)PTR__gleLightMaterialRGBAChange_B_A_001121ac;
        if (uVar1 != 0x1200) {
LAB_0000713c:
          pcVar3 = (code *)PTR__gleLightMaterialRGBAChange_B_AD_001121a0;
        }
      }
      else {
        pcVar3 = (code *)PTR__gleLightMaterialRGBAChange_B_S_001121a4;
        if ((uVar1 != 0x1202) &&
           (pcVar3 = (code *)PTR__gleLightMaterialRGBAChange_B_E_001121b0, uVar1 != 0x1600))
        goto LAB_0000713c;
      }
    }
  }
  else {
    uVar1 = *(ushort *)(param_1 + 0x30a6);
    pcVar3 = (code *)PTR__gleLightMaterialRGBAChange_FB_D_00112194;
    if (uVar1 != 0x1201) {
      if (uVar1 < 0x1202) {
        pcVar3 = (code *)PTR__gleLightMaterialRGBAChange_FB_A_00112198;
        if (uVar1 != 0x1200) {
LAB_000071a4:
          pcVar3 = (code *)PTR__gleLightMaterialRGBAChange_FB_AD_0011218c;
        }
      }
      else {
        pcVar3 = (code *)PTR__gleLightMaterialRGBAChange_FB_S_00112190;
        if ((uVar1 != 0x1202) &&
           (pcVar3 = (code *)PTR__gleLightMaterialRGBAChange_FB_E_0011219c, uVar1 != 0x1600))
        goto LAB_000071a4;
      }
    }
  }
  if (*(code **)(param_1 + 0x4de0) == pcVar3) goto LAB_000071fc;
  if (*(char *)(param_1 + 0x30ab) == '\0') {
LAB_000071dc:
    cVar2 = *(char *)(param_1 + 0x4df8);
  }
  else {
    cVar2 = *(char *)(param_1 + 0x4df8);
    if (cVar2 == '\0') {
      (**(code **)(param_1 + 0x4de0))(param_1,param_1 + 0x2a0);
      goto LAB_000071dc;
    }
  }
  if (cVar2 != '\0') {
    (*pcVar3)(param_1,param_1 + 0x2a0);
  }
LAB_000071fc:
  *(code **)(param_1 + 0x4de0) = pcVar3;
  return;
}

/* _gleSetColorMaterialEnable @ 0x7214 (656 bytes) */
int _gleSetColorMaterialEnable(param_1)
  int param_1;
{
  int iVar1;
  char cVar3;
  undefined *puVar2;
  uint uVar4;
  uint uVar5;
  
  cVar3 = '\0';
  if ((((*(char *)(param_1 + 0x7580) == '\0') && (*(char *)(param_1 + 0x30ab) != '\0')) &&
      (*(char *)(param_1 + 0x4664) == '\0')) && (*(int *)(param_1 + 0x5434) == 0)) {
    cVar3 = '\x01';
  }
  if (cVar3 == *(char *)(param_1 + 0x4df8)) {
    return;
  }
  iVar1 = *(int *)(param_1 + 0x5408);
  *(char *)(param_1 + 0x4df8) = cVar3;
  if (iVar1 == 0) {
    if (cVar3 == '\0') {
      uVar4 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x54) == 0);
      *(undefined **)
       ((*(uint *)(param_1 + 0x4680) & uVar4 | *(uint *)(param_1 + 0x4684) & ~uVar4) + 0x54) =
           PTR__glColor3f_NoColorMat_Exec_00112178;
      uVar4 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x58) == 0);
      *(undefined **)
       ((*(uint *)(param_1 + 0x4680) & uVar4 | *(uint *)(param_1 + 0x4684) & ~uVar4) + 0x58) =
           PTR__glColor3fv_NoColorMat_Exec_00112174;
      uVar4 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x94) == 0);
      *(undefined **)
       ((*(uint *)(param_1 + 0x4680) & uVar4 | *(uint *)(param_1 + 0x4684) & ~uVar4) + 0x94) =
           PTR__glColor4f_NoColorMat_Exec_00112170;
      uVar5 = *(uint *)(param_1 + 0x4684);
      uVar4 = *(uint *)(param_1 + 0x4680);
      iVar1 = *(int *)(uVar5 + 0x98);
      puVar2 = PTR__glColor4fv_NoColorMat_Exec_0011216c;
    }
    else {
      uVar4 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x54) == 0);
      *(undefined **)
       ((*(uint *)(param_1 + 0x4680) & uVar4 | *(uint *)(param_1 + 0x4684) & ~uVar4) + 0x54) =
           PTR__glColor3f_ColorMat_Exec_00112188;
      uVar4 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x58) == 0);
      *(undefined **)
       ((*(uint *)(param_1 + 0x4680) & uVar4 | *(uint *)(param_1 + 0x4684) & ~uVar4) + 0x58) =
           PTR__glColor3fv_ColorMat_Exec_00112184;
      uVar4 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x94) == 0);
      *(undefined **)
       ((*(uint *)(param_1 + 0x4680) & uVar4 | *(uint *)(param_1 + 0x4684) & ~uVar4) + 0x94) =
           PTR__glColor4f_ColorMat_Exec_00112180;
      uVar5 = *(uint *)(param_1 + 0x4684);
      uVar4 = *(uint *)(param_1 + 0x4680);
      iVar1 = *(int *)(uVar5 + 0x98);
      puVar2 = PTR__glColor4fv_ColorMat_Exec_0011217c;
    }
    *(undefined **)((uVar4 & -(uint)(iVar1 == 0) | uVar5 & ~-(uint)(iVar1 == 0)) + 0x98) = puVar2;
    iVar1 = *(int *)(param_1 + 0x5408);
  }
  if (iVar1 != 0) goto LAB_00007490;
  if ((*(char *)(param_1 + 0x7580) == '\0') || (*(int *)(param_1 + 0x4e1c) != 0x1c00)) {
LAB_00007464:
    uVar4 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x128) == 0);
    uVar4 = *(uint *)(param_1 + 0x4680) & uVar4 | *(uint *)(param_1 + 0x4684) & ~uVar4;
    puVar2 = PTR__glEnd_Exec_00112164;
  }
  else if (*(char *)(*(int *)(param_1 + 0x468c) + 0x7a) == '\0') {
    uVar4 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x128) == 0);
    uVar4 = *(uint *)(param_1 + 0x4680) & uVar4 | *(uint *)(param_1 + 0x4684) & ~uVar4;
    puVar2 = PTR__glEndRDirty_Exec_00112160;
  }
  else {
    if (*(char *)(param_1 + 0x4df8) != '\0') goto LAB_00007464;
    uVar4 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x128) == 0);
    uVar4 = *(uint *)(param_1 + 0x4680) & uVar4 | *(uint *)(param_1 + 0x4684) & ~uVar4;
    puVar2 = PTR__glEndNoMat_Exec_00112168;
  }
  *(undefined **)(uVar4 + 0x128) = puVar2;
LAB_00007490:
  if (cVar3 == '\0') {
    return;
  }
                    
                    
  (**(code **)(param_1 + 0x4de0))(param_1,param_1 + 0x2a0);
  return;
}

/* _gleUpdateLightPosition @ 0x74a4 (540 bytes) */
double _gleUpdateLightPosition(int param_1,int param_2,double fparam_1)
{
  byte bVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  undefined *puVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  int iVar10;
  int iVar11;
  undefined4 uVar12;
  
  iVar7 = param_1 + param_2 * 0x80;
  fVar2 = *(float *)(iVar7 + 0x2850);
  iVar8 = param_1 + param_2 * 0x6c;
  *(float *)(iVar8 + 0x4a70) = fVar2;
  fVar5 = FLOAT_00108e50;
  fVar3 = *(float *)(iVar7 + 0x2854);
  *(float *)(iVar8 + 0x4a74) = fVar3;
  fVar4 = *(float *)(iVar7 + 0x2858);
  *(float *)(iVar8 + 0x4a78) = fVar4;
  if (*(float *)(iVar7 + 0x285c) == fVar5) {
    *(undefined1 *)(iVar8 + 0x4ad9) = 1;
  }
  else {
    *(undefined1 *)(iVar8 + 0x4ad9) = 0;
    if (*(float *)(iVar7 + 0x285c) != FLOAT_00108e54) {
      fVar5 = FLOAT_00108e54 / *(float *)(iVar7 + 0x285c);
      *(float *)(iVar8 + 0x4a78) = fVar4 * fVar5;
      *(float *)(iVar8 + 0x4a70) = fVar2 * fVar5;
      *(float *)(iVar8 + 0x4a74) = fVar3 * fVar5;
    }
  }
  puVar6 = PTR__gleVectorNormalize_00112064;
  (**(code **)PTR__gleVectorNormalize_00112064)(param_1,iVar8 + 0x4a70,iVar8 + 0x4a7c);
  uVar9 = *(undefined4 *)(iVar8 + 0x4a7c);
  uVar12 = *(undefined4 *)(iVar8 + 0x4a80);
  *(undefined4 *)(iVar7 + 0x2888) = *(undefined4 *)(iVar8 + 0x4a84);
  fVar2 = FLOAT_00108e54;
  *(undefined4 *)(iVar7 + 0x2880) = uVar9;
  *(undefined4 *)(iVar7 + 0x2884) = uVar12;
  *(float *)(iVar7 + 0x2888) = *(float *)(iVar7 + 0x2888) + fVar2;
  (**(code **)puVar6)(param_1,iVar7 + 0x2880,iVar7 + 0x2880);
  ((int (*)())_gleUpdateLightFast)(param_1,param_2);
  ((int (*)())_gleUpdateLightModelFunc)(param_1);
  iVar7 = *(int *)(param_1 + 0x5434);
  if (iVar7 == 0) {
    bVar1 = *(byte *)(param_2 * 7 + *(int *)(param_1 + 0x5420) + 0x25b);
  }
  else {
    bVar1 = *(byte *)(param_2 * 7 + *(int *)(*(int *)(param_1 + 0x5430) + 0x20) + 0x28f);
  }
  iVar10 = param_2 * 7;
  iVar8 = (bVar1 >> 3 & 0x1c) + param_1;
  iVar11 = *(int *)(param_1 + 0x5424);
  *(uint *)(iVar8 + 0x324) = *(uint *)(iVar8 + 0x324) | 1 << (bVar1 & 0x1f);
  bVar1 = *(byte *)(iVar10 + iVar11 + 0x25b);
  iVar8 = (bVar1 >> 3 & 0x1c) + param_1;
  *(uint *)(iVar8 + 0x348) = *(uint *)(iVar8 + 0x348) | 1 << (bVar1 & 0x1f);
  if (iVar7 == 0) {
    bVar1 = *(byte *)(iVar10 + *(int *)(param_1 + 0x5420) + 0x25e);
  }
  else {
    bVar1 = *(byte *)(iVar10 + *(int *)(*(int *)(param_1 + 0x5430) + 0x20) + 0x292);
  }
  iVar7 = (bVar1 >> 3 & 0x1c) + param_1;
  *(uint *)(iVar7 + 0x324) = *(uint *)(iVar7 + 0x324) | 1 << (bVar1 & 0x1f);
  bVar1 = *(byte *)(iVar10 + iVar11 + 0x25e);
  iVar7 = (bVar1 >> 3 & 0x1c) + param_1;
  *(uint *)(iVar7 + 0x348) = *(uint *)(iVar7 + 0x348) | 1 << (bVar1 & 0x1f);
  return;
}

/* _gleVectorNormalizeNO @ 0x76c0 (204 bytes) */
double _gleVectorNormalizeNO(undefined4 param_1,float *param_2,float *param_3,double fparam_1)
{
  float fVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  double dVar7;
  
  dVar3 = (double)param_2[1];
  dVar4 = (double)*param_2;
  dVar5 = (double)param_2[2];
  fVar1 = (float)(dVar5 * dVar5 + (double)(float)(dVar4 * dVar4 + (double)(float)(dVar3 * dVar3)));
  dVar2 = (double)fVar1;
  if (DOUBLE_00108de8 < dVar2) {
    dVar7 = (double)(float)(0x5f375a00 - ((uint)GH_F2U(fVar1) >> 1));
    dVar2 = (double)(float)((double)(float)(dVar2 * dVar7) * dVar7);
    dVar6 = (double)(float)((double)FLOAT_00108f38 - dVar2);
    dVar2 = (double)(float)(dVar7 * DOUBLE_00108df0 * dVar6 *
                           -(double)(float)((double)(float)(dVar2 * dVar6) * dVar6 -
                                           (double)FLOAT_00108f48));
    dVar4 = (double)(float)(dVar4 * dVar2);
    dVar3 = (double)(float)(dVar3 * dVar2);
    fVar1 = (float)(dVar5 * dVar2);
  }
  else {
    dVar2 = (double)FLOAT_00108eb4;
    fVar1 = FLOAT_00108e58;
  }
  param_3[2] = fVar1;
  *param_3 = (float)dVar4;
  param_3[1] = (float)dVar3;
  return dVar2;
}

/* _gleUpdateLightFast @ 0x778c (152 bytes) */
int _gleUpdateLightFast(param_1, param_2)
  int param_1;
  uint param_2;
{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = 1 << (param_2 & 0x3f);
  uVar3 = *(uint *)(param_1 + 0x4ddc);
  iVar1 = param_1 + param_2 * 0x6c;
  if (((*(uint *)(param_1 + 0x30a0) & uVar2) == 0) ||
     (((*(char *)(iVar1 + 0x4ada) == '\0' && (*(char *)(param_1 + 0x30ad) == '\0')) &&
      (*(char *)(iVar1 + 0x4ad9) != '\0')))) {
    uVar2 = uVar3 & ~uVar2;
    *(undefined1 *)(iVar1 + 0x4ad8) = 1;
  }
  else {
    *(undefined1 *)(iVar1 + 0x4ad8) = 0;
    uVar2 = uVar3 | 1 << (param_2 & 0x3f);
  }
  *(uint *)(param_1 + 0x4ddc) = uVar2;
  if ((uVar3 != 0) == (*(int *)(param_1 + 0x4ddc) != 0)) {
    return;
  }
  *(uint *)(param_1 + 0x50ac) = *(uint *)(param_1 + 0x50ac) | 1;
  return;
}

/* _gleUpdateLightModelFunc @ 0x7824 (208 bytes) */
int _gleUpdateLightModelFunc(param_1)
  int param_1;
{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  
  puVar2 = PTR__gleVtxLightSpecRGBABackPtr_00110e64;
  puVar1 = PTR__gleVtxLightRGBABackPtr_00110e54;
  puVar3 = PTR__gleVtxLightFastRGBABackPtr_00110e44;
  if ((*(char *)(param_1 + 0x30ae) == '\0') && (*(short *)(param_1 + 0x30a8) != -0x7e06)) {
    if (*(int *)(param_1 + 0x4ddc) == 0) {
      *(undefined **)(param_1 + 0x4de8) = PTR__gleVtxLightFastRGBAFront_00110e50;
      puVar1 = PTR__gleVtxLightFastRGBABack_00110e4c;
      *(undefined **)(param_1 + 0x4df4) = puVar3;
      *(undefined **)(param_1 + 0x4dec) = puVar1;
      puVar3 = PTR__gleVtxLightFastRGBAFrontPtr_00110e48;
    }
    else {
      *(undefined **)(param_1 + 0x4de8) = PTR__gleVtxLightRGBAFront_00110e60;
      *(undefined **)(param_1 + 0x4df4) = puVar1;
      puVar3 = PTR__gleVtxLightRGBAFrontPtr_00110e58;
      *(undefined **)(param_1 + 0x4dec) = PTR__gleVtxLightRGBABack_00110e5c;
    }
  }
  else {
    *(undefined **)(param_1 + 0x4de8) = PTR__gleVtxLightSpecRGBAFront_00110e70;
    puVar3 = PTR__gleVtxLightSpecRGBABack_00110e6c;
    *(undefined **)(param_1 + 0x4df4) = puVar2;
    *(undefined **)(param_1 + 0x4dec) = puVar3;
    puVar3 = PTR__gleVtxLightSpecRGBAFrontPtr_00110e68;
  }
  *(undefined **)(param_1 + 0x4df0) = puVar3;
  return;
}

/* _gleUpdateLightDirection @ 0x78f4 (220 bytes) */
void _gleUpdateLightDirection(int param_1,int param_2,double fparam_1)
{
  byte bVar1;
  int iVar2;
  int iVar3;
  
  (**(code **)PTR__gleVectorNormalize_00112064)
            (param_1,param_1 + param_2 * 0x80 + 0x2860,param_1 + param_2 * 0x6c + 0x4a88);
  if (*(int *)(param_1 + 0x5434) == 0) {
    bVar1 = *(byte *)(param_2 * 7 + *(int *)(param_1 + 0x5420) + 0x25c);
  }
  else {
    bVar1 = *(byte *)(param_2 * 7 + *(int *)(*(int *)(param_1 + 0x5430) + 0x20) + 0x290);
  }
  iVar3 = (bVar1 >> 3 & 0x1c) + param_1;
  iVar2 = *(int *)(param_1 + 0x5424);
  *(uint *)(iVar3 + 0x324) = *(uint *)(iVar3 + 0x324) | 1 << (bVar1 & 0x1f);
  bVar1 = *(byte *)(param_2 * 7 + iVar2 + 0x25c);
  iVar2 = (bVar1 >> 3 & 0x1c) + param_1;
  *(uint *)(iVar2 + 0x348) = *(uint *)(iVar2 + 0x348) | 1 << (bVar1 & 0x1f);
  return;
}

/* _gleUpdateLightExponents @ 0x79d0 (424 bytes) */
int _gleUpdateLightExponents(param_1, param_2)
  int param_1;
  int param_2;
{
  float fVar1;
  float fVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  float *pfVar7;
  double dVar8;
  double dVar9;
  double dVar10;
  double dVar11;
  
  iVar3 = param_1 + param_2 * 0x80;
  iVar6 = param_1 + param_2 * 0x6c;
  if (FLOAT_00108e50 <= *(float *)(iVar3 + 0x286c)) {
    *(undefined1 *)(iVar6 + 0x4ada) = 1;
    if (*(float *)(iVar6 + 0x4a94) != *(float *)(iVar3 + 0x287c)) {
      *(float *)(iVar6 + 0x4a94) = *(float *)(iVar3 + 0x287c);
      if (*(float *)(iVar3 + 0x287c) <= FLOAT_00108e80) {
        iVar3 = 0xb;
        *(undefined4 *)(iVar6 + 0x4aa4) = 0x3f800000;
        *(undefined4 *)(iVar6 + 0x4a98) = 0x3f800000;
        puVar4 = (undefined4 *)(iVar6 + 0x4aa8);
        *(undefined4 *)(iVar6 + 0x4a9c) = 0x3f800000;
        *(undefined4 *)(iVar6 + 0x4aa0) = 0x3f800000;
        do {
          *puVar4 = 0x3f800000;
          puVar4 = puVar4 + 1;
          iVar3 = iVar3 + -1;
        } while (iVar3 != 0);
      }
      else {
        pfVar7 = (float *)(iVar6 + 0x4aa8);
        dVar11 = (double)FLOAT_00108e54;
        iVar5 = 9;
        dVar9 = (double)_log(DOUBLE_00108dd8);
        fVar2 = FLOAT_00108f44;
        dVar9 = (double)_exp(dVar9 / (double)*(float *)(iVar3 + 0x287c));
        dVar10 = (double)(float)dVar9;
        dVar8 = (double)FLOAT_00108f40;
        *(float *)(iVar6 + 0x4a98) = (float)dVar9;
        dVar9 = DOUBLE_00108de0;
        *(float *)(iVar6 + 0x4aa0) = (float)(dVar8 / dVar10);
        *(float *)(iVar6 + 0x4a9c) = fVar2 / (float)(dVar11 - dVar10);
        dVar9 = (double)_pow(dVar9,(double)*(float *)(iVar3 + 0x287c));
        fVar1 = *(float *)(iVar6 + 0x4a98);
        *(float *)(iVar6 + 0x4aa4) = (float)(dVar9 - DOUBLE_00108d68);
        dVar9 = (double)fVar1;
        do {
          dVar8 = (double)_pow(dVar9,(double)*(float *)(iVar3 + 0x287c));
          iVar5 = iVar5 + -1;
          *pfVar7 = (float)dVar8;
          pfVar7 = pfVar7 + 1;
          dVar9 = (double)(float)(dVar9 + (double)((float)(dVar11 - (double)fVar1) / fVar2));
        } while (-1 < iVar5);
        *(undefined4 *)(iVar6 + 0x4ad0) = 0x3f800000;
      }
    }
  }
  else {
    *(undefined1 *)(iVar6 + 0x4ada) = 0;
  }
  ((int (*)())_gleUpdateLightFast)(param_1,param_2);
  ((int (*)())_gleUpdateLightModelFunc)(param_1);
  return;
}

/* _gleUpdateLightAttenuation @ 0x7b78 (280 bytes) */
int _gleUpdateLightAttenuation(param_1, param_2)
  int param_1;
  int param_2;
{
  byte bVar1;
  undefined1 uVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = param_1 + param_2 * 0x80;
  iVar4 = param_1 + param_2 * 0x6c;
  if ((FLOAT_00108e80 <= *(float *)(iVar3 + 0x2870)) ||
     (*(float *)(iVar3 + 0x2870) <= FLOAT_00108f3c)) {
    if ((*(float *)(iVar3 + 0x2874) != FLOAT_00108e50) ||
       (uVar2 = 1, *(float *)(iVar3 + 0x2878) != FLOAT_00108e50)) {
      uVar2 = 0;
    }
    *(undefined1 *)(iVar4 + 0x4adb) = uVar2;
    *(float *)(iVar4 + 0x4ad4) = FLOAT_00108e54 / *(float *)(iVar3 + 0x2870);
  }
  else {
    *(undefined1 *)(iVar4 + 0x4adb) = 0;
  }
  if (*(int *)(param_1 + 0x5434) == 0) {
    bVar1 = *(byte *)(param_2 * 7 + *(int *)(param_1 + 0x5420) + 0x25d);
  }
  else {
    bVar1 = *(byte *)(param_2 * 7 + *(int *)(*(int *)(param_1 + 0x5430) + 0x20) + 0x291);
  }
  iVar4 = (bVar1 >> 3 & 0x1c) + param_1;
  iVar3 = *(int *)(param_1 + 0x5424);
  *(uint *)(iVar4 + 0x324) = *(uint *)(iVar4 + 0x324) | 1 << (bVar1 & 0x1f);
  bVar1 = *(byte *)(param_2 * 7 + iVar3 + 0x25d);
  iVar3 = (bVar1 >> 3 & 0x1c) + param_1;
  *(uint *)(iVar3 + 0x348) = *(uint *)(iVar3 + 0x348) | 1 << (bVar1 & 0x1f);
  return;
}

/* _gleUpdateInverseNeeds @ 0x7c90 (192 bytes) */
int _gleUpdateInverseNeeds(param_1)
  int param_1;
{
  int iVar1;
  
  if (*(char *)(param_1 + 0x4664) == '\0') {
    if (*(int *)(param_1 + 0x5434) == 0) {
      if ((*(char *)(param_1 + 0x30aa) != '\0') || (iVar1 = 0, *(char *)(param_1 + 0x53e6) != '\0'))
      {
        if (*(char *)(param_1 + 0x4661) == '\0') {
          iVar1 = 0x10;
        }
        else {
          iVar1 = (0xffffffffU >> (0x20 - *(byte *)(param_1 + 0x4660) & 0x3f)) << 4;
        }
      }
    }
    else {
      iVar1 = *(int *)(*(int *)(*(int *)(param_1 + 0x5430) + 0x20) + 4);
    }
  }
  else {
    iVar1 = *(int *)(*(int *)(param_1 + 0x5420) + 0x20);
  }
  *(int *)(param_1 + 0x505c) = iVar1;
  if (*(char *)(param_1 + 0x466c) != '\0') {
    *(uint *)(param_1 + 0x505c) =
         *(uint *)(param_1 + 0x505c) | *(uint *)(*(int *)(param_1 + 0x5424) + 0x20);
  }
  if (*(int *)(param_1 + 0x5438) == 0) {
    return;
  }
  *(uint *)(param_1 + 0x505c) =
       *(uint *)(param_1 + 0x505c) | *(uint *)(*(int *)(*(int *)(param_1 + 0x5430) + 0x24) + 4);
  return;
}

/* _gleUpdateLightModel @ 0x7d50 (72 bytes) */
int _gleUpdateLightModel(param_1)
  undefined4 param_1;
{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  do {
    iVar2 = iVar1 + 1;
    ((int (*)())_gleUpdateLightFast)(param_1,iVar1);
    iVar1 = iVar2;
  } while (iVar2 < 8);
  ((int (*)())_gleUpdateLightModelFunc)(param_1);
  return;
}

/* _gleUpdateClipPlane @ 0x7d98 (108 bytes) */
int _gleUpdateClipPlane(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  char cVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  
  cVar1 = *(char *)(param_1 + 0x4e18);
  *(undefined1 *)(param_1 + 0x4e18) = 0;
  uVar3 = *(uint *)(param_1 + 0x4188);
  iVar6 = 6;
  uVar4 = 0;
  iVar5 = 0;
  puVar2 = (uint *)(param_1 + 0x4e00);
  do {
    if ((uVar3 & 1 << (uVar4 & 0x3f)) != 0) {
      *puVar2 = uVar4;
      iVar5 = iVar5 + 1;
      *(undefined1 *)(param_1 + 0x4e18) = 1;
      puVar2 = puVar2 + 1;
    }
    uVar4 = uVar4 + 1;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  *(int *)(param_1 + 0x4dfc) = iVar5;
  if (*(char *)(param_1 + 0x4e18) == cVar1) {
    return;
  }
  *(uint *)(param_1 + 0x50ac) = *(uint *)(param_1 + 0x50ac) | 1;
  return;
}

/* _gleUpdateMatrixMode @ 0x7e04 (68 bytes) */
int _gleUpdateMatrixMode(param_1)
  int param_1;
{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = *(uint *)(param_1 + 0x4ff4);
  if (0x17 < (int)uVar3) {
    return;
  }
  iVar2 = param_1 + uVar3 * 0x40;
  *(int *)(param_1 + 0x4ff0) = iVar2 + 0x21c0;
  *(int *)(param_1 + 0x4fec) = iVar2 + 0x1bc0;
  uVar1 = 1 << (uVar3 & 0x3f);
  if (uVar3 - 3 < 2) {
    uVar1 = uVar1 | 1;
  }
  *(uint *)(param_1 + 0x50a8) = uVar1;
  return;
}

/* _gleUpdateMatrixFunc @ 0x7e48 (2092 bytes) */
int _gleUpdateMatrixFunc(param_1)
  int param_1;
{
  undefined *puVar1;
  uint uVar2;
  int iVar3;
  byte bVar5;
  int iVar4;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  
  uVar9 = *(uint *)(param_1 + 0x50ac);
  bVar5 = 0;
  uVar8 = *(uint *)(param_1 + 0x50b0);
  if ((*(char *)(param_1 + 0x4e18) != '\0') ||
     (((*(char *)(param_1 + 0x30aa) != '\0' && (*(int *)(param_1 + 0x4ddc) != 0)) ||
      (*(char *)(param_1 + 0x53e5) != '\0')))) {
    bVar5 = 1;
  }
  *(byte *)(param_1 + 0x50b4) =
       bVar5 | *(char *)(param_1 + 0x316a) << 1 | *(char *)(param_1 + 0x4661) << 2;
  if (((uVar9 & 0x18) != 0) || (iVar3 = param_1, (*(uint *)(param_1 + 0x318) & 1) != 0)) {
    iVar3 = ((int (*)())_gleApplyViewScissorTransform)(param_1);
  }
  uVar8 = uVar8 & *(uint *)(param_1 + 0x505c);
  if (uVar8 != 0) {
    iVar3 = _gleInvertMatrices(param_1,uVar8);
  }
  puVar1 = PTR__gleSetModelviewFuncAll_0011222c;
  *(undefined **)(param_1 + 0x5068) = PTR__gleSetNormalFunc_00112230;
  *(undefined **)(param_1 + 0x5064) = puVar1;
  if ((uVar9 & 0x18) == 0) {
    if (((*(uint *)(param_1 + 0x318) & 1) == 0) && ((*(uint *)(param_1 + 0x31c) & 0x200000) == 0))
    goto LAB_00007f38;
  }
  *(undefined **)(param_1 + 0x5060) = PTR__gleSetProjectionFuncAll_00112228;
LAB_00007f38:
  if ((uVar9 & 0xff0000) != 0) {
    iVar3 = ((int (*)())_gleUpdateTextureTransform)(param_1);
  }
  if ((uVar9 & 4) != 0) {
    iVar3 = (**(code **)PTR__gleGenerateMatrixIdentifier_00112060)(param_1,param_1 + 0x1c40);
    if (iVar3 == -0x40100402) {
      uVar2 = *(uint *)(param_1 + 0x3410) & 0xfffffeff;
    }
    else {
      uVar2 = *(uint *)(param_1 + 0x3410) | 0x100;
    }
    *(uint *)(param_1 + 0x3410) = uVar2;
  }
  uVar8 = (uVar9 | uVar8) & 0xfffffc;
  *(uint *)(param_1 + 0x318) = *(uint *)(param_1 + 0x318) | uVar8;
  if ((*(char *)(param_1 + 0x4664) != '\0') || (*(int *)(param_1 + 0x5434) != 0)) {
    uVar9 = 0;
    iVar10 = 0x18;
    do {
      if (((uVar8 | (uVar8 >> 4 | uVar8 >> 3) & 1) >> (uVar9 & 0x3f) & 1) != 0) {
        iVar6 = *(int *)(param_1 + 0x5434);
        if (iVar6 == 0) {
          bVar5 = *(byte *)(uVar9 * 4 + *(int *)(param_1 + 0x5420) + 0x328);
        }
        else {
          bVar5 = *(byte *)(uVar9 * 4 + *(int *)(*(int *)(param_1 + 0x5430) + 0x20) + 0x35c);
        }
        iVar7 = uVar9 * 4;
        iVar4 = (bVar5 >> 3 & 0x1c) + param_1;
        *(uint *)(iVar4 + 0x324) = *(uint *)(iVar4 + 0x324) | 1 << (bVar5 & 0x1f);
        if (iVar6 == 0) {
          bVar5 = *(byte *)(iVar7 + *(int *)(param_1 + 0x5420) + 0x329);
        }
        else {
          bVar5 = *(byte *)(iVar7 + *(int *)(*(int *)(param_1 + 0x5430) + 0x20) + 0x35d);
        }
        iVar4 = (bVar5 >> 3 & 0x1c) + param_1;
        *(uint *)(iVar4 + 0x324) = *(uint *)(iVar4 + 0x324) | 1 << (bVar5 & 0x1f);
        if (iVar6 == 0) {
          bVar5 = *(byte *)(iVar7 + *(int *)(param_1 + 0x5420) + 0x32a);
        }
        else {
          bVar5 = *(byte *)(iVar7 + *(int *)(*(int *)(param_1 + 0x5430) + 0x20) + 0x35e);
        }
        iVar4 = (bVar5 >> 3 & 0x1c) + param_1;
        *(uint *)(iVar4 + 0x324) = *(uint *)(iVar4 + 0x324) | 1 << (bVar5 & 0x1f);
        if (iVar6 == 0) {
          bVar5 = *(byte *)(iVar7 + *(int *)(param_1 + 0x5420) + 0x32b);
        }
        else {
          bVar5 = *(byte *)(iVar7 + *(int *)(*(int *)(param_1 + 0x5430) + 0x20) + 0x35f);
        }
        iVar4 = (bVar5 >> 3 & 0x1c) + param_1;
        *(uint *)(iVar4 + 0x324) = *(uint *)(iVar4 + 0x324) | 1 << (bVar5 & 0x1f);
        if (iVar6 == 0) {
          bVar5 = *(byte *)(iVar7 + *(int *)(param_1 + 0x5420) + 0x388);
        }
        else {
          bVar5 = *(byte *)(iVar7 + *(int *)(*(int *)(param_1 + 0x5430) + 0x20) + 0x3bc);
        }
        iVar4 = (bVar5 >> 3 & 0x1c) + param_1;
        *(uint *)(iVar4 + 0x324) = *(uint *)(iVar4 + 0x324) | 1 << (bVar5 & 0x1f);
        if (iVar6 == 0) {
          bVar5 = *(byte *)(iVar7 + *(int *)(param_1 + 0x5420) + 0x389);
        }
        else {
          bVar5 = *(byte *)(iVar7 + *(int *)(*(int *)(param_1 + 0x5430) + 0x20) + 0x3bd);
        }
        iVar4 = (bVar5 >> 3 & 0x1c) + param_1;
        *(uint *)(iVar4 + 0x324) = *(uint *)(iVar4 + 0x324) | 1 << (bVar5 & 0x1f);
        if (iVar6 == 0) {
          bVar5 = *(byte *)(iVar7 + *(int *)(param_1 + 0x5420) + 0x38a);
        }
        else {
          bVar5 = *(byte *)(iVar7 + *(int *)(*(int *)(param_1 + 0x5430) + 0x20) + 0x3be);
        }
        iVar4 = (bVar5 >> 3 & 0x1c) + param_1;
        *(uint *)(iVar4 + 0x324) = *(uint *)(iVar4 + 0x324) | 1 << (bVar5 & 0x1f);
        if (iVar6 == 0) {
          bVar5 = *(byte *)(iVar7 + *(int *)(param_1 + 0x5420) + 0x38b);
        }
        else {
          bVar5 = *(byte *)(iVar7 + *(int *)(*(int *)(param_1 + 0x5430) + 0x20) + 0x3bf);
        }
        iVar4 = (bVar5 >> 3 & 0x1c) + param_1;
        *(uint *)(iVar4 + 0x324) = *(uint *)(iVar4 + 0x324) | 1 << (bVar5 & 0x1f);
        if (iVar6 == 0) {
          bVar5 = *(byte *)(iVar7 + *(int *)(param_1 + 0x5420) + 1000);
        }
        else {
          bVar5 = *(byte *)(iVar7 + *(int *)(*(int *)(param_1 + 0x5430) + 0x20) + 0x41c);
        }
        iVar4 = (bVar5 >> 3 & 0x1c) + param_1;
        *(uint *)(iVar4 + 0x324) = *(uint *)(iVar4 + 0x324) | 1 << (bVar5 & 0x1f);
        if (iVar6 == 0) {
          bVar5 = *(byte *)(iVar7 + *(int *)(param_1 + 0x5420) + 0x3e9);
        }
        else {
          bVar5 = *(byte *)(iVar7 + *(int *)(*(int *)(param_1 + 0x5430) + 0x20) + 0x41d);
        }
        iVar4 = (bVar5 >> 3 & 0x1c) + param_1;
        *(uint *)(iVar4 + 0x324) = *(uint *)(iVar4 + 0x324) | 1 << (bVar5 & 0x1f);
        if (iVar6 == 0) {
          bVar5 = *(byte *)(iVar7 + *(int *)(param_1 + 0x5420) + 0x3ea);
        }
        else {
          bVar5 = *(byte *)(iVar7 + *(int *)(*(int *)(param_1 + 0x5430) + 0x20) + 0x41e);
        }
        iVar4 = (bVar5 >> 3 & 0x1c) + param_1;
        *(uint *)(iVar4 + 0x324) = *(uint *)(iVar4 + 0x324) | 1 << (bVar5 & 0x1f);
        if (iVar6 == 0) {
          bVar5 = *(byte *)(iVar7 + *(int *)(param_1 + 0x5420) + 0x3eb);
        }
        else {
          bVar5 = *(byte *)(iVar7 + *(int *)(*(int *)(param_1 + 0x5430) + 0x20) + 0x41f);
        }
        iVar4 = (bVar5 >> 3 & 0x1c) + param_1;
        *(uint *)(iVar4 + 0x324) = *(uint *)(iVar4 + 0x324) | 1 << (bVar5 & 0x1f);
        if (iVar6 == 0) {
          bVar5 = *(byte *)(iVar7 + *(int *)(param_1 + 0x5420) + 0x448);
        }
        else {
          bVar5 = *(byte *)(iVar7 + *(int *)(*(int *)(param_1 + 0x5430) + 0x20) + 0x47c);
        }
        iVar4 = (bVar5 >> 3 & 0x1c) + param_1;
        *(uint *)(iVar4 + 0x324) = *(uint *)(iVar4 + 0x324) | 1 << (bVar5 & 0x1f);
        if (iVar6 == 0) {
          bVar5 = *(byte *)(iVar7 + *(int *)(param_1 + 0x5420) + 0x449);
        }
        else {
          bVar5 = *(byte *)(iVar7 + *(int *)(*(int *)(param_1 + 0x5430) + 0x20) + 0x47d);
        }
        iVar4 = (bVar5 >> 3 & 0x1c) + param_1;
        *(uint *)(iVar4 + 0x324) = *(uint *)(iVar4 + 0x324) | 1 << (bVar5 & 0x1f);
        if (iVar6 == 0) {
          bVar5 = *(byte *)(iVar7 + *(int *)(param_1 + 0x5420) + 0x44a);
        }
        else {
          bVar5 = *(byte *)(iVar7 + *(int *)(*(int *)(param_1 + 0x5430) + 0x20) + 0x47e);
        }
        iVar4 = (bVar5 >> 3 & 0x1c) + param_1;
        *(uint *)(iVar4 + 0x324) = *(uint *)(iVar4 + 0x324) | 1 << (bVar5 & 0x1f);
        if (iVar6 == 0) {
          bVar5 = *(byte *)(iVar7 + *(int *)(param_1 + 0x5420) + 1099);
        }
        else {
          bVar5 = *(byte *)(iVar7 + *(int *)(*(int *)(param_1 + 0x5430) + 0x20) + 0x47f);
        }
        iVar6 = (bVar5 >> 3 & 0x1c) + param_1;
        iVar7 = iVar7 + *(int *)(param_1 + 0x5424);
        *(uint *)(iVar6 + 0x324) = *(uint *)(iVar6 + 0x324) | 1 << (bVar5 & 0x1f);
        iVar6 = (*(byte *)(iVar7 + 0x328) >> 3 & 0x1c) + param_1;
        *(uint *)(iVar6 + 0x348) = *(uint *)(iVar6 + 0x348) | 1 << (*(byte *)(iVar7 + 0x328) & 0x1f)
        ;
        iVar6 = (*(byte *)(iVar7 + 0x329) >> 3 & 0x1c) + param_1;
        *(uint *)(iVar6 + 0x348) = *(uint *)(iVar6 + 0x348) | 1 << (*(byte *)(iVar7 + 0x329) & 0x1f)
        ;
        iVar6 = (*(byte *)(iVar7 + 0x32a) >> 3 & 0x1c) + param_1;
        *(uint *)(iVar6 + 0x348) = *(uint *)(iVar6 + 0x348) | 1 << (*(byte *)(iVar7 + 0x32a) & 0x1f)
        ;
        iVar6 = (*(byte *)(iVar7 + 0x32b) >> 3 & 0x1c) + param_1;
        *(uint *)(iVar6 + 0x348) = *(uint *)(iVar6 + 0x348) | 1 << (*(byte *)(iVar7 + 0x32b) & 0x1f)
        ;
        iVar6 = (*(byte *)(iVar7 + 0x388) >> 3 & 0x1c) + param_1;
        *(uint *)(iVar6 + 0x348) = *(uint *)(iVar6 + 0x348) | 1 << (*(byte *)(iVar7 + 0x388) & 0x1f)
        ;
        iVar6 = (*(byte *)(iVar7 + 0x389) >> 3 & 0x1c) + param_1;
        *(uint *)(iVar6 + 0x348) = *(uint *)(iVar6 + 0x348) | 1 << (*(byte *)(iVar7 + 0x389) & 0x1f)
        ;
        iVar6 = (*(byte *)(iVar7 + 0x38a) >> 3 & 0x1c) + param_1;
        *(uint *)(iVar6 + 0x348) = *(uint *)(iVar6 + 0x348) | 1 << (*(byte *)(iVar7 + 0x38a) & 0x1f)
        ;
        iVar6 = (*(byte *)(iVar7 + 0x38b) >> 3 & 0x1c) + param_1;
        *(uint *)(iVar6 + 0x348) = *(uint *)(iVar6 + 0x348) | 1 << (*(byte *)(iVar7 + 0x38b) & 0x1f)
        ;
        iVar6 = (*(byte *)(iVar7 + 1000) >> 3 & 0x1c) + param_1;
        *(uint *)(iVar6 + 0x348) = *(uint *)(iVar6 + 0x348) | 1 << (*(byte *)(iVar7 + 1000) & 0x1f);
        iVar6 = (*(byte *)(iVar7 + 0x3e9) >> 3 & 0x1c) + param_1;
        *(uint *)(iVar6 + 0x348) = *(uint *)(iVar6 + 0x348) | 1 << (*(byte *)(iVar7 + 0x3e9) & 0x1f)
        ;
        iVar6 = (*(byte *)(iVar7 + 0x3ea) >> 3 & 0x1c) + param_1;
        *(uint *)(iVar6 + 0x348) = *(uint *)(iVar6 + 0x348) | 1 << (*(byte *)(iVar7 + 0x3ea) & 0x1f)
        ;
        iVar6 = (*(byte *)(iVar7 + 0x3eb) >> 3 & 0x1c) + param_1;
        *(uint *)(iVar6 + 0x348) = *(uint *)(iVar6 + 0x348) | 1 << (*(byte *)(iVar7 + 0x3eb) & 0x1f)
        ;
        iVar6 = (*(byte *)(iVar7 + 0x448) >> 3 & 0x1c) + param_1;
        *(uint *)(iVar6 + 0x348) = *(uint *)(iVar6 + 0x348) | 1 << (*(byte *)(iVar7 + 0x448) & 0x1f)
        ;
        iVar6 = (*(byte *)(iVar7 + 0x449) >> 3 & 0x1c) + param_1;
        *(uint *)(iVar6 + 0x348) = *(uint *)(iVar6 + 0x348) | 1 << (*(byte *)(iVar7 + 0x449) & 0x1f)
        ;
        iVar6 = (*(byte *)(iVar7 + 0x44a) >> 3 & 0x1c) + param_1;
        *(uint *)(iVar6 + 0x348) = *(uint *)(iVar6 + 0x348) | 1 << (*(byte *)(iVar7 + 0x44a) & 0x1f)
        ;
        iVar6 = (*(byte *)(iVar7 + 1099) >> 3 & 0x1c) + param_1;
        *(uint *)(iVar6 + 0x348) = *(uint *)(iVar6 + 0x348) | 1 << (*(byte *)(iVar7 + 1099) & 0x1f);
      }
      uVar9 = uVar9 + 1;
      iVar10 = iVar10 + -1;
    } while (iVar10 != 0);
  }
  *(undefined4 *)(param_1 + 0x50ac) = 0;
  *(uint *)(param_1 + 0x497c) = *(uint *)(param_1 + 0x497c) | 0x1d;
  return iVar3;
}

/* _gleApplyViewScissorTransform @ 0x8674 (296 bytes) */
int _gleApplyViewScissorTransform(param_1)
  int param_1;
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  
  fVar1 = *(float *)(param_1 + 0x4a1c);
  fVar2 = *(float *)(param_1 + 0x4a20);
  fVar3 = *(float *)(param_1 + 0x4a24);
  fVar4 = *(float *)(param_1 + 0x4a28);
  ((int (*)())_gleMultMatrix)(param_1 + 0x1c80,param_1 + 0x1cc0,param_1 + 0x1bc0);
  *(float *)(param_1 + 0x27c0) =
       fVar1 * *(float *)(param_1 + 0x1bc0) + fVar2 * *(float *)(param_1 + 0x1bcc);
  *(float *)(param_1 + 0x27c4) =
       fVar3 * *(float *)(param_1 + 0x1bc4) + fVar4 * *(float *)(param_1 + 0x1bcc);
  *(undefined4 *)(param_1 + 0x27c8) = *(undefined4 *)(param_1 + 0x1bc8);
  *(undefined4 *)(param_1 + 0x27cc) = *(undefined4 *)(param_1 + 0x1bcc);
  *(float *)(param_1 + 0x27d0) =
       fVar1 * *(float *)(param_1 + 0x1bd0) + fVar2 * *(float *)(param_1 + 0x1bdc);
  *(float *)(param_1 + 0x27d4) =
       fVar3 * *(float *)(param_1 + 0x1bd4) + fVar4 * *(float *)(param_1 + 0x1bdc);
  *(undefined4 *)(param_1 + 0x27d8) = *(undefined4 *)(param_1 + 0x1bd8);
  *(undefined4 *)(param_1 + 0x27dc) = *(undefined4 *)(param_1 + 0x1bdc);
  *(float *)(param_1 + 0x27e0) =
       fVar1 * *(float *)(param_1 + 0x1be0) + fVar2 * *(float *)(param_1 + 0x1bec);
  *(float *)(param_1 + 0x27e4) =
       fVar3 * *(float *)(param_1 + 0x1be4) + fVar4 * *(float *)(param_1 + 0x1bec);
  *(undefined4 *)(param_1 + 0x27e8) = *(undefined4 *)(param_1 + 0x1be8);
  *(undefined4 *)(param_1 + 0x27ec) = *(undefined4 *)(param_1 + 0x1bec);
  *(float *)(param_1 + 0x27f0) =
       fVar1 * *(float *)(param_1 + 0x1bf0) + fVar2 * *(float *)(param_1 + 0x1bfc);
  *(float *)(param_1 + 0x27f4) =
       fVar3 * *(float *)(param_1 + 0x1bf4) + fVar4 * *(float *)(param_1 + 0x1bfc);
  *(undefined4 *)(param_1 + 0x27f8) = *(undefined4 *)(param_1 + 0x1bf8);
  *(undefined4 *)(param_1 + 0x27fc) = *(undefined4 *)(param_1 + 0x1bfc);
  ((int (*)())FUN_00008b68)();
  return;
}

/* saveFP @ 0x879c (12 bytes) */
int saveFP()
{
  return;
}

/* FUN_000087a8 @ 0x87a8 (4 bytes) */
int FUN_000087a8()
{
  return;
}

/* FUN_000087ac @ 0x87ac (4 bytes) */
int FUN_000087ac()
{
  return;
}

/* FUN_000087b0 @ 0x87b0 (8 bytes) */
int FUN_000087b0()
{
  return;
}

/* FUN_000087b8 @ 0x87b8 (8 bytes) */
int FUN_000087b8()
{
  return;
}

/* FUN_000087c0 @ 0x87c0 (4 bytes) */
int FUN_000087c0()
{
  return;
}

/* FUN_000087c4 @ 0x87c4 (4 bytes) */
int FUN_000087c4()
{
  return;
}

/* FUN_000087c8 @ 0x87c8 (4 bytes) */
int FUN_000087c8()
{
  return;
}

/* FUN_000087cc @ 0x87cc (4 bytes) */
int FUN_000087cc()
{
  return;
}

/* FUN_000087d0 @ 0x87d0 (4 bytes) */
int FUN_000087d0()
{
  return;
}

/* FUN_000087d4 @ 0x87d4 (24 bytes) */
int FUN_000087d4()
{
  return;
}

/* _gleMultMatrix @ 0x87ec (836 bytes) */
int _gleMultMatrix(param_1, param_2, param_3)
  float *param_1;
  float *param_2;
  float *param_3;
{
  *param_3 = param_1[0xc] * param_2[3] +
             (param_1[8] * param_2[2] + (*param_1 * *param_2 + param_1[4] * param_2[1]));
  param_3[4] = param_1[0xc] * param_2[7] +
               (param_1[8] * param_2[6] + (*param_1 * param_2[4] + param_1[4] * param_2[5]));
  param_3[8] = param_1[0xc] * param_2[0xb] +
               (param_1[8] * param_2[10] + (*param_1 * param_2[8] + param_1[4] * param_2[9]));
  param_3[0xc] = param_1[0xc] * param_2[0xf] +
                 (param_1[8] * param_2[0xe] + (*param_1 * param_2[0xc] + param_1[4] * param_2[0xd]));
  param_3[1] = param_1[0xd] * param_2[3] +
               (param_1[9] * param_2[2] + (param_1[1] * *param_2 + param_1[5] * param_2[1]));
  param_3[5] = param_1[0xd] * param_2[7] +
               (param_1[9] * param_2[6] + (param_1[1] * param_2[4] + param_1[5] * param_2[5]));
  param_3[9] = param_1[0xd] * param_2[0xb] +
               (param_1[9] * param_2[10] + (param_1[1] * param_2[8] + param_1[5] * param_2[9]));
  param_3[0xd] = param_1[0xd] * param_2[0xf] +
                 (param_1[9] * param_2[0xe] + (param_1[1] * param_2[0xc] + param_1[5] * param_2[0xd]));
  param_3[2] = param_1[0xe] * param_2[3] +
               (param_1[10] * param_2[2] + (param_1[2] * *param_2 + param_1[6] * param_2[1]));
  param_3[6] = param_1[0xe] * param_2[7] +
               (param_1[10] * param_2[6] + (param_1[2] * param_2[4] + param_1[6] * param_2[5]));
  param_3[10] = param_1[0xe] * param_2[0xb] +
                (param_1[10] * param_2[10] + (param_1[2] * param_2[8] + param_1[6] * param_2[9]));
  param_3[0xe] = param_1[0xe] * param_2[0xf] +
                 (param_1[10] * param_2[0xe] + (param_1[2] * param_2[0xc] + param_1[6] * param_2[0xd]));
  param_3[3] = param_1[0xf] * param_2[3] +
               (param_1[0xb] * param_2[2] + (param_1[3] * *param_2 + param_1[7] * param_2[1]));
  param_3[7] = param_1[0xf] * param_2[7] +
               (param_1[0xb] * param_2[6] + (param_1[3] * param_2[4] + param_1[7] * param_2[5]));
  param_3[0xb] = param_1[0xf] * param_2[0xb] +
                 (param_1[0xb] * param_2[10] + (param_1[3] * param_2[8] + param_1[7] * param_2[9]));
  param_3[0xf] = param_1[0xf] * param_2[0xf] +
                 (param_1[0xb] * param_2[0xe] + (param_1[3] * param_2[0xc] + param_1[7] * param_2[0xd]))
  ;
  return;
}

/* restFP @ 0x8b30 (56 bytes) */
int restFP()
{
  return;
}

/* FUN_00008b68 @ 0x8b68 (28 bytes) */
int FUN_00008b68()
{
  return;
}

/* _gleUpdateTextureTransform @ 0x8b84 (272 bytes) */
int _gleUpdateTextureTransform(param_1)
  int param_1;
{
  bool bVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  int iVar5;
  
  iVar5 = _gleTexEnableBits(param_1);
  puVar3 = PTR__gleTextureMatTransPtrDivW_001115ec;
  puVar2 = PTR__gleMultiTextureMatTransPtr_001115e0;
  puVar4 = PTR__gleTextureMatTrans_Identity_001115f4;
  if (((iVar5 != 0) && (*(char *)(param_1 + 0x4664) == '\0')) && (*(int *)(param_1 + 0x5434) == 0))
  {
    bVar1 = false;
    if (((*(uint *)(*(int *)(param_1 + 0x468c) + 0x94) & 4) == 0) &&
       (*(int *)(param_1 + 0x4e1c) == 0x1c00)) {
      bVar1 = true;
    }
    if (iVar5 != 1) {
      *(undefined **)(param_1 + 0x506c) = PTR__gleMultiTextureMatTrans_001115e4;
      *(undefined **)(param_1 + 0x5074) = puVar2;
      puVar3 = PTR__gleTextureMatTransPtrDivW_001115ec;
      puVar2 = PTR__gleTextureMatTrans_001115e8;
      if (bVar1) {
        *(undefined **)(param_1 + 0x5070) = PTR__gleTextureMatTransDivW_001115f0;
        *(undefined **)(param_1 + 0x5078) = puVar3;
        return;
      }
      *(undefined **)(param_1 + 0x5078) = PTR__gleTextureMatTrans_001115e8;
      *(undefined **)(param_1 + 0x5070) = puVar2;
      return;
    }
    puVar4 = PTR__gleTextureMatTrans_001115e8;
    if (bVar1) {
      *(undefined **)(param_1 + 0x506c) = PTR__gleTextureMatTransDivW_001115f0;
      *(undefined **)(param_1 + 0x5074) = puVar3;
      return;
    }
  }
  *(undefined **)(param_1 + 0x5074) = puVar4;
  *(undefined **)(param_1 + 0x506c) = puVar4;
  return;
}

/* _gleUpdateDepthRangeData @ 0x8c94 (156 bytes) */
void _gleUpdateDepthRangeData(int param_1,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  double dVar5;
  double dVar6;
  
  dVar5 = *(double *)(param_1 + 0x1b90);
  fVar1 = (float)*(double *)(param_1 + 0x1b98);
  dVar6 = (*(double *)(param_1 + 0x1b98) - dVar5) * DOUBLE_00108dc0;
  fVar4 = *(float *)(*(int *)(param_1 + 0x468c) + 4);
  *(float *)(param_1 + 0xf8) = (float)dVar5;
  fVar2 = (float)dVar6;
  *(float *)(param_1 + 0x108) = fVar1;
  *(float *)(param_1 + 0x4a54) = fVar4;
  fVar3 = (float)(dVar6 + dVar5);
  *(float *)(param_1 + 0x1b78) = fVar2;
  *(float *)(param_1 + 0x4a3c) = fVar2;
  *(float *)(param_1 + 0x1b88) = fVar3;
  *(float *)(param_1 + 0x4a40) = fVar3;
  if (*(int *)(param_1 + 0x4e1c) == 0x1c00) {
    *(float *)(param_1 + 0x1b88) = fVar3 * fVar4;
    *(float *)(param_1 + 0x108) = fVar1 * fVar4;
    *(float *)(param_1 + 0x1b78) = fVar2 * fVar4;
    *(float *)(param_1 + 0xf8) = (float)dVar5 * fVar4;
  }
  *(uint *)(param_1 + 0x318) = *(uint *)(param_1 + 0x318) | 1;
  return;
}

/* _gleUpdateTextureCoordGen @ 0x8d30 (1120 bytes) */
int _gleUpdateTextureCoordGen(param_1)
  int param_1;
{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  char cVar4;
  char cVar5;
  ushort uVar6;
  undefined *puVar7;
  undefined *puVar8;
  undefined *puVar9;
  undefined *puVar10;
  undefined *puVar11;
  undefined *puVar12;
  undefined *puVar13;
  undefined *puVar14;
  undefined *puVar15;
  undefined *puVar16;
  undefined *puVar17;
  undefined *puVar18;
  undefined *puVar19;
  undefined *puVar20;
  undefined *puVar21;
  undefined *puVar22;
  undefined *puVar23;
  undefined *puVar24;
  undefined *puVar25;
  int iVar26;
  int iVar27;
  char *pcVar28;
  undefined *puVar29;
  int iVar30;
  int iVar31;
  
  puVar29 = PTR__gleVtxTextureCoordGenNoop_001114ac;
  puVar25 = PTR__gleMultiVtxTextureCoordGenNoop_001114a8;
  puVar24 = PTR__gleVtxTextureCoordGenEyeST_001114a4;
  puVar23 = PTR__gleMultiVtxTextureCoordGenEyeST_001114a0;
  puVar22 = PTR__gleVtxTextureCoordGenObjectST_0011149c;
  puVar21 = PTR__gleMultiVtxTextureCoordGenObjectST_00111498;
  puVar20 = PTR__gleVtxTextureCoordGenSphereST_00111494;
  puVar19 = PTR__gleMultiVtxTextureCoordGenSphereST_00111490;
  puVar18 = PTR__gleVtxTextureCoordGenNormalST_0011148c;
  puVar17 = PTR__gleMultiVtxTextureCoordGenNormalST_00111488;
  puVar16 = PTR__gleVtxTextureCoordGenReflectST_00111484;
  puVar15 = PTR__gleMultiVtxTextureCoordGenReflectST_00111480;
  puVar14 = PTR__gleVtxTextureCoordGenNormalSTR_0011147c;
  puVar13 = PTR__gleMultiVtxTextureCoordGenNormalSTR_00111478;
  puVar12 = PTR__gleVtxTextureCoordGenEyeSlow_0011146c;
  puVar11 = PTR__gleMultiVtxTextureCoordGenEyeSlow_00111468;
  puVar10 = PTR__gleVtxTextureCoordGenObjectSlow_00111464;
  puVar9 = PTR__gleMultiVtxTextureCoordGenObjectSlow_00111460;
  puVar8 = PTR__gleMultiVtxTextureCoordGenWrapObject_0011145c;
  puVar7 = PTR__gleMultiVtxTextureCoordGenWrapEye_00111458;
  *(undefined **)(param_1 + 0x53e0) = PTR__gleVtxTextureCoordGenNoop_001114ac;
  *(undefined1 *)(param_1 + 0x53e4) = 0;
  iVar27 = 0;
  *(undefined1 *)(param_1 + 0x53e5) = 0;
  cVar4 = *(char *)(param_1 + 0x53e6);
  iVar26 = param_1 + 0x3d70;
  *(undefined1 *)(param_1 + 0x53e6) = 0;
  *(undefined **)(param_1 + 0x53dc) = puVar29;
  pcVar28 = (char *)(param_1 + 0x531c);
  iVar31 = 8;
  iVar30 = param_1;
  do {
    *(undefined **)(pcVar28 + -8) = puVar25;
    *(undefined **)(pcVar28 + -4) = puVar25;
    cVar5 = *pcVar28;
    if (((*(char *)(iVar26 + 8) == '\0') || (*(char *)(iVar26 + 9) == '\0')) ||
       (*(char *)(iVar26 + 0xb) != '\0')) {
LAB_00008f68:
      if (((*(char *)(iVar26 + 8) == '\0') && (*(char *)(iVar26 + 9) == '\0')) &&
         ((*(char *)(iVar26 + 10) == '\0' && (*(char *)(iVar26 + 0xb) == '\0')))) {
        *pcVar28 = '\0';
      }
      else {
        *pcVar28 = '\x01';
        bVar2 = *(char *)(iVar26 + 8) != '\0';
        if ((((((bVar2) && (*(short *)(iVar26 + -0x88) == 0x2402)) ||
              ((bVar3 = *(char *)(iVar26 + 9) != '\0', bVar3 &&
               (*(short *)(iVar30 + 0x3d0c) == 0x2402)))) ||
             ((((bVar2 && (*(short *)(iVar30 + 0x3ce8) == -0x7aef)) ||
               ((bVar3 && (*(short *)(iVar30 + 0x3d0c) == -0x7aef)))) ||
              ((bVar1 = *(char *)(iVar26 + 10) != '\0', bVar1 &&
               (*(short *)(iVar30 + 0x3d30) == -0x7aef)))))) ||
            ((bVar2 && (*(short *)(iVar30 + 0x3ce8) == -0x7aee)))) ||
           (((bVar3 && (*(short *)(iVar30 + 0x3d0c) == -0x7aee)) ||
            ((bVar1 && (*(short *)(iVar30 + 0x3d30) == -0x7aee)))))) {
          *(undefined1 *)(param_1 + 0x53e6) = 1;
LAB_0000909c:
          *(undefined1 *)(param_1 + 0x53e5) = 1;
          *(undefined **)(param_1 + 0x53e0) = puVar12;
          *(undefined **)(pcVar28 + -4) = puVar11;
        }
        else if ((((*(char *)(iVar26 + 8) != '\0') && (*(short *)(iVar26 + -0x88) == 0x2400)) ||
                 (((*(char *)(iVar26 + 9) != '\0' && (*(short *)(iVar30 + 0x3d0c) == 0x2400)) ||
                  ((*(char *)(iVar26 + 10) != '\0' && (*(short *)(iVar30 + 0x3d30) == 0x2400))))))
                || ((*(char *)(iVar26 + 0xb) != '\0' && (*(short *)(iVar30 + 0x3d54) == 0x2400))))
        goto LAB_0000909c;
        if (((((*(char *)(iVar26 + 8) != '\0') && (*(short *)(iVar26 + -0x88) == 0x2401)) ||
             ((*(char *)(iVar26 + 9) != '\0' && (*(short *)(iVar30 + 0x3d0c) == 0x2401)))) ||
            ((*(char *)(iVar26 + 10) != '\0' && (*(short *)(iVar30 + 0x3d30) == 0x2401)))) ||
           ((*(char *)(iVar26 + 0xb) != '\0' && (*(short *)(iVar30 + 0x3d54) == 0x2401)))) {
          *(undefined1 *)(param_1 + 0x53e4) = 1;
          *(undefined **)(param_1 + 0x53dc) = puVar10;
          *(undefined **)(pcVar28 + -8) = puVar9;
        }
      }
    }
    else {
      *pcVar28 = '\x01';
      puVar29 = PTR__gleVtxTextureCoordGenReflectSTR_00111474;
      uVar6 = *(ushort *)(iVar26 + -0x88);
      if (uVar6 != *(ushort *)(iVar26 + -100)) goto LAB_00008f68;
      if (*(char *)(iVar26 + 10) == '\0') {
        if (uVar6 == 0x2401) {
          *(undefined1 *)(param_1 + 0x53e4) = 1;
          *(undefined **)(param_1 + 0x53dc) = puVar22;
          *(undefined **)(pcVar28 + -8) = puVar21;
        }
        else if (uVar6 < 0x2402) {
          if (uVar6 == 0x2400) {
            *(undefined1 *)(param_1 + 0x53e5) = 1;
            *(undefined **)(param_1 + 0x53e0) = puVar24;
            *(undefined **)(pcVar28 + -4) = puVar23;
          }
          else {
LAB_00008ef8:
            *(undefined1 *)(param_1 + 0x53e5) = 1;
            *(undefined1 *)(param_1 + 0x53e6) = 1;
            *(undefined **)(param_1 + 0x53e0) = puVar16;
            *(undefined **)(pcVar28 + -4) = puVar15;
          }
        }
        else if (uVar6 == 0x2402) {
          *(undefined1 *)(param_1 + 0x53e6) = 1;
          *(undefined1 *)(param_1 + 0x53e5) = 1;
          *(undefined **)(param_1 + 0x53e0) = puVar20;
          *(undefined **)(pcVar28 + -4) = puVar19;
        }
        else {
          if (uVar6 != 0x8511) goto LAB_00008ef8;
          *(undefined1 *)(param_1 + 0x53e6) = 1;
          *(undefined1 *)(param_1 + 0x53e5) = 1;
          *(undefined **)(param_1 + 0x53e0) = puVar18;
          *(undefined **)(pcVar28 + -4) = puVar17;
        }
      }
      else {
        if (uVar6 != *(ushort *)(iVar26 + -0x40)) goto LAB_00008f68;
        if (uVar6 == 0x8511) {
          *(undefined **)(param_1 + 0x53e0) = puVar14;
          *(undefined1 *)(param_1 + 0x53e6) = 1;
          puVar29 = puVar13;
        }
        else {
          if (uVar6 != 0x8512) goto LAB_00008f68;
          *(undefined1 *)(param_1 + 0x53e6) = 1;
          *(undefined **)(param_1 + 0x53e0) = puVar29;
          puVar29 = PTR__gleMultiVtxTextureCoordGenReflectSTR_00111470;
        }
        *(undefined1 *)(param_1 + 0x53e5) = 1;
        *(undefined **)(pcVar28 + -4) = puVar29;
      }
    }
    if ((iVar27 != 0) && (*pcVar28 != '\0')) {
      *(undefined **)(param_1 + 0x53dc) = puVar8;
      *(undefined **)(param_1 + 0x53e0) = puVar7;
    }
    if (*pcVar28 != cVar5) {
      *(uint *)(param_1 + 0x50ac) = *(uint *)(param_1 + 0x50ac) | 1;
    }
    iVar27 = iVar27 + 1;
    pcVar28 = pcVar28 + 0xc;
    iVar30 = iVar30 + 0x94;
    iVar26 = iVar26 + 0x94;
    iVar31 = iVar31 + -1;
    if (iVar31 == 0) {
      if (*(char *)(param_1 + 0x53e6) == cVar4) {
        return;
      }
      ((int (*)())_gleUpdateInverseNeeds)(param_1);
      return;
    }
  } while( true );
}

/* _gleUpdateTextureParams @ 0x9190 (280 bytes) */
int _gleUpdateTextureParams(param_1, param_2)
  int param_1;
  uint param_2;
{
  undefined *puVar1;
  uint uVar2;
  int extraout_r3;
  int iVar3;
  uint uVar4;
  
  if (*(char *)(param_1 + 0x3ce4) == '\0') {
    uVar2 = *(uint *)(param_2 * 0x7c + param_1 + 0x3534) & 0x1f;
  }
  else {
    uVar2 = (uint)*(ushort *)(param_2 * 0x7c + param_1 + 0x3564);
  }
  uVar4 = *(uint *)(param_1 + 0x514c);
  iVar3 = param_1;
  if ((uVar4 >> (param_2 & 0x3f) & 1) != -((int)-uVar2 >> 0x1f)) {
    if (-((int)-uVar2 >> 0x1f) == 0) {
      *(uint *)(param_1 + 0x514c) =
           uVar4 & (-2 << (param_2 & 0x1f) | 0xfffffffeU >> 0x20 - (param_2 & 0x1f));
      *(uint *)(param_1 + 0x4980) = *(uint *)(param_1 + 0x4980) & ~(8 << (param_2 & 0x3f));
    }
    else {
      *(uint *)(param_1 + 0x514c) = uVar4 | 1 << (param_2 & 0x3f);
      *(uint *)(param_1 + 0x4980) = *(uint *)(param_1 + 0x4980) | 8 << (param_2 & 0x3f);
    }
    *(uint *)(param_1 + 0x50ac) = *(uint *)(param_1 + 0x50ac) | 0x10000 << (param_2 & 0x3f);
    ((int (*)())_gleSelectVertexSubmitFunc)(param_1);
    puVar1 = PTR__gleSetClipInterpFunc_00112038;
    *(undefined **)(param_1 + 0x49c8) = PTR__gleSetEyeInterpFunc_0011203c;
    *(undefined **)(param_1 + 0x49cc) = puVar1;
    iVar3 = extraout_r3;
  }
  *(uint *)(param_1 + 0x314) = *(uint *)(param_1 + 0x314) | 1 << (param_2 & 0x3f);
  return iVar3;
}

/* _gleUpdateFogData @ 0x92a8 (348 bytes) */
double _gleUpdateFogData(int param_1)
{
  float fVar1;
  float fVar2;
  undefined2 uVar4;
  uint uVar3;
  int iVar5;
  undefined *puVar6;
  bool bVar7;
  double in_f1;
  
  fVar1 = *(float *)(param_1 + 0x3158) - *(float *)(param_1 + 0x3154);
  bVar7 = FLOAT_00108e80 <= fVar1;
  *(float *)(param_1 + 0x315c) = fVar1;
  if ((bVar7) || (fVar2 = FLOAT_00108eb4, fVar1 <= FLOAT_00108f3c)) {
    fVar2 = FLOAT_00108e54 / fVar1;
  }
  *(float *)(param_1 + 0x315c) = fVar2;
  puVar6 = PTR__gleFogExp_00110e28;
  if (*(char *)(param_1 + 0x316a) == '\0') {
    uVar3 = *(uint *)(param_1 + 0x4980) & 0xfffffffb;
    *(undefined2 *)(param_1 + 0x4fe8) = 0;
    *(undefined **)(param_1 + 0x4fe4) = puVar6;
  }
  else {
    iVar5 = *(int *)(param_1 + 0x4854);
    if (*(short *)(param_1 + 0x3164) == 0x800) {
      uVar4 = 8;
    }
    else if (*(short *)(param_1 + 0x3164) == 0x2601) {
      uVar4 = 4;
      puVar6 = PTR__gleFogLinear_00110e2c;
    }
    else {
      uVar4 = 0xc;
      puVar6 = PTR__gleFogExp2_00110e24;
    }
    *(undefined **)(param_1 + 0x4fe4) = puVar6;
    *(undefined2 *)(param_1 + 0x4fe8) = uVar4;
    if (*(short *)(param_1 + 0x3166) == -0x7baf) {
      *(ushort *)(param_1 + 0x4fe8) = *(ushort *)(param_1 + 0x4fe8) | 0x10;
      fVar1 = *(float *)(iVar5 + -0x1a4);
    }
    else {
      fVar1 = *(float *)(iVar5 + -0x1d8);
    }
    in_f1 = (double)(**(double ( **)(int,double))(param_1 + 0x4fe4))(param_1, (double)fVar1);
    *(float *)(iVar5 + -0x1b4) = (float)in_f1;
    uVar3 = *(uint *)(param_1 + 0x4980) | 4;
  }
  *(uint *)(param_1 + 0x4980) = uVar3;
  *(uint *)(param_1 + 0x497c) = *(uint *)(param_1 + 0x497c) | 4;
  *(uint *)(param_1 + 0x50ac) = *(uint *)(param_1 + 0x50ac) | 1;
  return in_f1;
}

/* _gleUpdatePolyMode @ 0x9404 (408 bytes) */
int _gleUpdatePolyMode(param_1)
  int param_1;
{
  char cVar1;
  undefined1 uVar2;
  bool bVar3;
  
  cVar1 = *(char *)(param_1 + 0x34da);
  *(bool *)(param_1 + 0x4fe2) = *(int *)(param_1 + 0x34d0) == 0x1b021b02;
  if (*(char *)(param_1 + 0x4664) == '\0') {
    bVar3 = false;
    if ((*(short *)(param_1 + 0x34d0) != *(short *)(param_1 + 0x34d2)) ||
       ((*(char *)(param_1 + 0x30aa) != '\0' && (*(char *)(param_1 + 0x30ac) != '\0')))) {
      bVar3 = true;
    }
    uVar2 = 0;
    if ((bVar3) || (cVar1 != '\0')) {
      uVar2 = 1;
    }
    *(undefined1 *)(param_1 + 0x4fe0) = uVar2;
    uVar2 = 0;
    if (!bVar3) {
      if (cVar1 == '\0') goto LAB_0000951c;
      if ((*(char *)(param_1 + 0x4fe2) != '\0') && (*(char *)(param_1 + 0x30aa) == '\0'))
      goto LAB_00009508;
    }
  }
  else {
    bVar3 = false;
    if ((*(short *)(param_1 + 0x34d0) != *(short *)(param_1 + 0x34d2)) ||
       (*(char *)(param_1 + 0x4666) != '\0')) {
      bVar3 = true;
    }
    uVar2 = 0;
    if ((bVar3) || (cVar1 != '\0')) {
      uVar2 = 1;
    }
    *(undefined1 *)(param_1 + 0x4fe0) = uVar2;
    uVar2 = 0;
    if (!bVar3) {
      if (cVar1 == '\0') goto LAB_0000951c;
      if (*(char *)(param_1 + 0x4fe2) != '\0') {
LAB_00009508:
        uVar2 = 0;
        if (*(char *)(*(int *)(param_1 + 0x468c) + 0x78) != '\0') goto LAB_0000951c;
      }
    }
  }
  uVar2 = 1;
LAB_0000951c:
  *(undefined1 *)(param_1 + 0x34de) = uVar2;
  if ((*(int *)(param_1 + 0x4e1c) == 0x1c00) &&
     ((**(uint **)(param_1 + 0x468c) >> 1 & 1) != (**(uint **)(param_1 + 0x468c) & 1))) {
    bVar3 = SUB41(-(uint)(*(ushort *)(param_1 + 0x34d4) ^ 0x901) >> 0x1f,0);
  }
  else {
    bVar3 = *(short *)(param_1 + 0x34d4) == 0x901;
  }
  *(bool *)(param_1 + 0x4fe1) = bVar3;
  uVar2 = 2;
  if (cVar1 != '\0') {
    uVar2 = *(short *)(param_1 + 0x34d6) == 0x404;
  }
  *(undefined1 *)(param_1 + 0x4fe3) = uVar2;
  *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x800000;
  return;
}

/* _gleUpdateEvalData @ 0x959c (168 bytes) */
int _gleUpdateEvalData(param_1)
  int param_1;
{
  double dVar1;
  double dVar2;
  
  dVar2 = (double)CONCAT44(0x43300000,*(uint *)(param_1 + 0x74c8) ^ 0x80000000) - DOUBLE_00108d58;
  dVar1 = (double)CONCAT44(0x43300000,*(uint *)(param_1 + 0x74b8) ^ 0x80000000) - DOUBLE_00108d58;
  *(float *)(param_1 + 0x74b4) =
       (*(float *)(param_1 + 0x74b0) - *(float *)(param_1 + 0x74ac)) /
       (float)((double)CONCAT44(0x43300000,
                                *(uint *)(0x74a4 + param_1 + 4) ^ 0x80000000) -
              DOUBLE_00108d58);
  *(float *)(param_1 + 0x74c4) =
       (*(float *)(param_1 + 0x74c0) - *(float *)(param_1 + 0x74bc)) / (float)dVar1;
  *(float *)(param_1 + 0x74d4) =
       (*(float *)(param_1 + 0x74d0) - *(float *)(param_1 + 0x74cc)) / (float)dVar2;
  return;
}

/* _gleUpdateViewScissorData @ 0x9644 (1892 bytes) */
void _gleUpdateViewScissorData(int param_1,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  int iVar19;
  uint uVar20;
  uint uVar21;
  uint uVar22;
  uint uVar23;
  uint uVar24;
  uint uVar25;
  double dVar26;
  double dVar27;
  double dVar28;
  double dVar29;
  
  dVar26 = DOUBLE_00108d58;
  iVar9 = *(int *)(param_1 + 0x744c);
  uVar24 = *(uint *)(param_1 + 0x1ba0);
  uVar25 = *(uint *)(param_1 + 0x1ba4);
  uVar21 = *(uint *)(param_1 + 0x1ba8);
  uVar22 = *(uint *)(param_1 + 0x1bac);
  uVar16 = uVar24 + uVar21;
  uVar12 = uVar25 + uVar22;
  if (iVar9 == 0) {
    uVar11 = *(uint *)(param_1 + 0x471c);
    uVar23 = *(uint *)(param_1 + 0x4720);
  }
  else {
    uVar11 = (uint)*(ushort *)(iVar9 + 0xca);
    uVar23 = (uint)*(ushort *)(iVar9 + 0xcc);
  }
  fVar1 = (float)((double)CONCAT44(0x43300000,uVar24 ^ 0x80000000) - DOUBLE_00108d58);
  fVar3 = (float)((double)CONCAT44(0x43300000,uVar21 ^ 0x80000000) - DOUBLE_00108d58) *
          FLOAT_00108e90;
  fVar2 = (float)((double)CONCAT44(0x43300000,uVar25 ^ 0x80000000) - DOUBLE_00108d58);
  fVar4 = (float)((double)CONCAT44(0x43300000,uVar22 ^ 0x80000000) - DOUBLE_00108d58) *
          FLOAT_00108e90;
  *(float *)(param_1 + 0x4a2c) = fVar3;
  *(float *)(param_1 + 0x4a34) = fVar4;
  *(float *)(param_1 + 0x4a30) = fVar3 + fVar1;
  *(float *)(param_1 + 19000) = fVar4 + fVar2;
  dVar28 = DOUBLE_00108d58;
  if (*(int *)(param_1 + 0x4e1c) == 0x1c00) {
    uVar20 = **(uint **)(param_1 + 0x468c);
    if ((((*(char *)(param_1 + 0x4664) == '\0') && (*(int *)(param_1 + 0x5434) == 0)) &&
        (*(char *)(param_1 + 0x34f0) != '\0')) &&
       (((uVar20 & 4) != 0 || (*(undefined **)(param_1 + 0x507c) == ((unsigned char *)0x00001101))))) {
      uVar14 = *(uint *)(param_1 + 0x34e0);
      uVar17 = *(uint *)(param_1 + 0x34e4);
      uVar8 = *(int *)(param_1 + 0x34e8) + uVar14;
      uVar10 = *(int *)(param_1 + 0x34ec) + uVar17;
      uVar15 = 0;
      if ((-1 < (int)uVar14) && (uVar15 = uVar14, (int)uVar11 < (int)uVar14)) {
        uVar15 = uVar11;
      }
      uVar18 = 0;
      if ((-1 < (int)uVar17) && (uVar18 = uVar17, (int)uVar23 < (int)uVar17)) {
        uVar18 = uVar23;
      }
      uVar14 = uVar15;
      if (((int)uVar15 <= (int)uVar8) && (uVar14 = uVar8, (int)uVar11 < (int)uVar8)) {
        uVar14 = uVar11;
      }
      uVar8 = uVar18;
      if (((int)uVar18 <= (int)uVar10) && (uVar8 = uVar10, (int)uVar23 < (int)uVar10)) {
        uVar8 = uVar23;
      }
    }
    else {
      uVar15 = 0;
      uVar18 = 0;
      uVar14 = uVar11;
      uVar8 = uVar23;
    }
    uVar10 = uVar24;
    if (((int)uVar24 <= (int)uVar15) && (uVar10 = uVar15, (int)uVar16 < (int)uVar15)) {
      uVar10 = uVar16;
    }
    uVar15 = uVar25;
    if (((int)uVar25 <= (int)uVar18) && (uVar15 = uVar18, (int)uVar12 < (int)uVar18)) {
      uVar15 = uVar12;
    }
    uVar18 = uVar10;
    if (((int)uVar10 <= (int)uVar14) && (uVar18 = uVar14, (int)uVar16 < (int)uVar14)) {
      uVar18 = uVar16;
    }
    uVar16 = uVar15;
    if (((int)uVar15 <= (int)uVar8) && (uVar16 = uVar8, (int)uVar12 < (int)uVar8)) {
      uVar16 = uVar12;
    }
    uVar14 = *(uint *)(param_1 + 0x4724);
    uVar12 = *(uint *)(param_1 + 0x4728);
    uVar17 = uVar18 - uVar10;
    uVar8 = uVar16 - uVar15;
    iVar9 = *(int *)(param_1 + 0x472c);
    iVar19 = *(int *)(param_1 + 0x4730);
    fVar1 = (float)((double)CONCAT44(0x43300000,uVar14 ^ 0x80000000) - DOUBLE_00108d58);
    fVar2 = (float)((double)CONCAT44(0x43300000,uVar12 ^ 0x80000000) - DOUBLE_00108d58);
    fVar3 = (float)((double)CONCAT44(0x43300000,uVar17 ^ 0x80000000) - DOUBLE_00108d58);
    fVar4 = (float)((double)CONCAT44(0x43300000,uVar8 ^ 0x80000000) - DOUBLE_00108d58);
    fVar6 = FLOAT_00108f8c;
    if ((uVar20 & 8) != 0) {
      fVar6 = FLOAT_00108e90;
    }
    fVar7 = fVar4 * fVar6;
    fVar6 = fVar3 * fVar6;
    fVar3 = fVar3 * FLOAT_00108e90 +
            (float)((double)CONCAT44(0x43300000,uVar10 ^ 0x80000000) - DOUBLE_00108d58);
    fVar4 = fVar4 * FLOAT_00108e90 +
            (float)((double)CONCAT44(0x43300000,uVar15 ^ 0x80000000) - DOUBLE_00108d58);
    if ((uVar20 & 1) == 0) {
      uVar13 = uVar10 + uVar14;
      uVar14 = uVar18 + uVar14;
      dVar26 = (double)CONCAT44(0x43300000,uVar13 ^ 0x80000000) - DOUBLE_00108d58;
      *(float *)(param_1 + 0x1b70) = fVar6;
      *(float *)(param_1 + 0x1b80) = fVar3 + fVar1;
      *(undefined4 *)(param_1 + 0x4a44) = 0x3f800000;
      *(float *)(param_1 + 0x4a48) = fVar1;
      *(float *)(param_1 + 0xf0) = (float)dVar26;
      *(float *)(param_1 + 0x100) =
           (float)((double)CONCAT44(0x43300000,uVar14 ^ 0x80000000) - dVar28);
      if (uVar10 == 0) {
        uVar13 = uVar13 - iVar9;
      }
      if (uVar18 == uVar11) {
        uVar14 = uVar14 + iVar9;
      }
    }
    else {
      uVar13 = (uVar11 - uVar18) + uVar14;
      uVar14 = (uVar11 - uVar10) + uVar14;
      fVar5 = (float)((double)CONCAT44(0x43300000,uVar11 ^ 0x80000000) - DOUBLE_00108d58);
      dVar28 = (double)CONCAT44(0x43300000,uVar13 ^ 0x80000000) - DOUBLE_00108d58;
      dVar26 = (double)CONCAT44(0x43300000,uVar14 ^ 0x80000000) - DOUBLE_00108d58;
      *(undefined4 *)(param_1 + 0x4a44) = 0xbf800000;
      *(float *)(param_1 + 0x1b70) = -fVar6;
      *(float *)(param_1 + 0x4a48) = fVar5 + fVar1;
      *(float *)(param_1 + 0x1b80) = (fVar5 - fVar3) + fVar1;
      *(float *)(param_1 + 0xf0) = (float)dVar28;
      *(float *)(param_1 + 0x100) = (float)dVar26;
      if (uVar10 == 0) {
        uVar14 = uVar14 + iVar9;
      }
      if (uVar18 == uVar11) {
        uVar13 = uVar13 - iVar9;
      }
    }
    dVar26 = DOUBLE_00108d58;
    if ((uVar20 & 2) == 0) {
      uVar11 = uVar15 + uVar12;
      uVar12 = uVar16 + uVar12;
      dVar28 = (double)CONCAT44(0x43300000,uVar11 ^ 0x80000000) - DOUBLE_00108d58;
      *(float *)(param_1 + 0x1b74) = fVar7;
      *(undefined4 *)(param_1 + 0x4a4c) = 0x3f800000;
      *(float *)(param_1 + 0x4a50) = fVar2;
      *(float *)(param_1 + 0x1b84) = fVar4 + fVar2;
      *(float *)(param_1 + 0xf4) = (float)dVar28;
      *(float *)(param_1 + 0x104) =
           (float)((double)CONCAT44(0x43300000,uVar12 ^ 0x80000000) - dVar26);
      if (uVar15 == 0) {
        uVar11 = uVar11 - iVar19;
      }
      if (uVar16 == uVar23) {
        uVar12 = uVar12 + iVar19;
      }
    }
    else {
      uVar11 = (uVar23 - uVar16) + uVar12;
      uVar12 = (uVar23 - uVar15) + uVar12;
      fVar1 = (float)((double)CONCAT44(0x43300000,uVar23 ^ 0x80000000) - DOUBLE_00108d58);
      dVar28 = (double)CONCAT44(0x43300000,uVar11 ^ 0x80000000) - DOUBLE_00108d58;
      dVar26 = (double)CONCAT44(0x43300000,uVar12 ^ 0x80000000) - DOUBLE_00108d58;
      *(undefined4 *)(param_1 + 0x4a4c) = 0xbf800000;
      *(float *)(param_1 + 0x4a50) = fVar1 + fVar2;
      *(float *)(param_1 + 0x1b74) = -fVar7;
      *(float *)(param_1 + 0x1b84) = (fVar1 - fVar4) + fVar2;
      *(float *)(param_1 + 0xf4) = (float)dVar28;
      *(float *)(param_1 + 0x104) = (float)dVar26;
      if (uVar15 == 0) {
        uVar12 = uVar12 + iVar19;
      }
      if (uVar16 == uVar23) {
        uVar11 = uVar11 - iVar19;
      }
    }
    dVar26 = DOUBLE_00108d58;
    dVar27 = (double)CONCAT44(0x43300000,uVar14 ^ 0x80000000) - DOUBLE_00108d58;
    dVar29 = (double)CONCAT44(0x43300000,uVar11 ^ 0x80000000) - DOUBLE_00108d58;
    dVar28 = (double)CONCAT44(0x43300000,uVar12 ^ 0x80000000) - DOUBLE_00108d58;
    *(float *)(param_1 + 0x110) =
         (float)((double)CONCAT44(0x43300000,uVar13 ^ 0x80000000) - DOUBLE_00108d58);
    *(float *)(param_1 + 0x118) = (float)dVar27;
    *(float *)(param_1 + 0x114) = (float)dVar29;
    *(float *)(param_1 + 0x11c) = (float)dVar28;
    fVar1 = FLOAT_00108e54;
    if ((uVar17 == 0) || (uVar8 == 0)) {
      *(undefined4 *)(param_1 + 0x4a24) = 0x3f800000;
      *(undefined4 *)(param_1 + 0x4a28) = 0;
      *(undefined4 *)(param_1 + 0x4a1c) = 0x3f800000;
      *(undefined4 *)(param_1 + 0x4a20) = 0;
    }
    else {
      fVar2 = (float)((double)CONCAT44(0x43300000,uVar17 ^ 0x80000000) - dVar26);
      fVar3 = (float)((double)CONCAT44(0x43300000,uVar8 ^ 0x80000000) - dVar26);
      *(float *)(param_1 + 0x4a1c) =
           (float)((double)CONCAT44(0x43300000,uVar21 ^ 0x80000000) - dVar26) / fVar2;
      *(float *)(param_1 + 0x4a24) =
           (float)((double)CONCAT44(0x43300000,uVar22 ^ 0x80000000) - dVar26) / fVar3;
      *(float *)(param_1 + 0x4a28) =
           (float)((double)CONCAT44(0x43300000,(uVar25 - uVar15) * 2 + uVar22 ^ 0x80000000) - dVar26
                  ) / fVar3 - fVar1;
      *(float *)(param_1 + 0x4a20) =
           (float)((double)CONCAT44(0x43300000,(uVar24 - uVar10) * 2 + uVar21 ^ 0x80000000) - dVar26
                  ) / fVar2 - fVar1;
    }
  }
  else {
    *(float *)(param_1 + 0x1b70) = fVar3;
    *(float *)(param_1 + 0x1b74) = fVar4;
    fVar6 = (float)((double)CONCAT44(0x43300000,uVar16 ^ 0x80000000) - dVar26);
    *(float *)(param_1 + 0x1b80) = fVar3 + fVar1;
    *(float *)(param_1 + 0x1b84) = fVar4 + fVar2;
    fVar3 = (float)((double)CONCAT44(0x43300000,uVar12 ^ 0x80000000) - dVar26);
    *(undefined4 *)(param_1 + 0x4a4c) = 0x3f800000;
    *(undefined4 *)(param_1 + 0x4a50) = 0;
    *(float *)(param_1 + 0xf0) = fVar1;
    *(float *)(param_1 + 0x100) = fVar6;
    *(float *)(param_1 + 0xf4) = fVar2;
    *(float *)(param_1 + 0x104) = fVar3;
    *(undefined4 *)(param_1 + 0x4a1c) = 0x3f800000;
    *(undefined4 *)(param_1 + 0x4a24) = 0x3f800000;
    *(undefined4 *)(param_1 + 0x4a20) = 0;
    *(undefined4 *)(param_1 + 0x4a28) = 0;
    *(undefined4 *)(param_1 + 0x4a44) = 0x3f800000;
    *(undefined4 *)(param_1 + 0x4a48) = 0;
    *(float *)(param_1 + 0x110) = fVar1;
    *(float *)(param_1 + 0x118) = fVar6;
    *(float *)(param_1 + 0x114) = fVar2;
    *(float *)(param_1 + 0x11c) = fVar3;
  }
  *(uint *)(param_1 + 0x50ac) = *(uint *)(param_1 + 0x50ac) | 1;
  *(uint *)(param_1 + 0x318) = *(uint *)(param_1 + 0x318) | 1;
  return;
}

/* _gleSelectVertexAddMaterialFunc @ 0x9da8 (32 bytes) */
int _gleSelectVertexAddMaterialFunc(param_1)
  int param_1;
{
  *(undefined **)(param_1 + 0x4de4) = PTR__gleSetAddVertexMaterialFunc_00110e34;
  return;
}

/* _gleSelectVertexSubmitFunc @ 0x9dc8 (272 bytes) */
int _gleSelectVertexSubmitFunc(param_1)
  int param_1;
{
  undefined *puVar1;
  undefined *puVar2;
  short sVar4;
  int iVar3;
  
  puVar1 = PTR__gleSetVertexEval2Func_00112068;
  *(undefined **)(param_1 + 0x4888) = PTR__gleSetVertexSubmitFunc_0011242c;
  puVar2 = PTR__gleSetVertexEval1Func_0011206c;
  *(undefined4 *)(param_1 + 0x4890) = 0;
  *(undefined **)(param_1 + 0x4898) = puVar2;
  *(undefined **)(param_1 + 0x489c) = puVar1;
  if (((*(int *)(param_1 + 0x4e1c) == 0x1c00) && (*(char *)(param_1 + 0x7580) != '\0')) &&
     (*(int *)(param_1 + 0x48d0) != 0)) {
    sVar4 = (ushort)*(byte *)(*(int *)(param_1 + 0x48d0) + 2) << 2;
    *(short *)(param_1 + 0x4880) = sVar4;
    if (*(int *)(param_1 + 0x48d4) != 0) {
      sVar4 = (ushort)*(byte *)(*(int *)(param_1 + 0x48d4) + 2) << 2;
    }
    *(short *)(param_1 + 0x4882) = sVar4;
    return;
  }
  if (*(char *)(param_1 + 0x4664) == '\0') {
    iVar3 = *(int *)(param_1 + 0x5434);
    if (iVar3 == 0) {
      *(undefined2 *)(param_1 + 0x487c) = 0x100;
      *(undefined4 *)(param_1 + 0x485c) = *(undefined4 *)(param_1 + 0x4860);
      return;
    }
  }
  else {
    iVar3 = *(int *)(param_1 + 0x5434);
  }
  if (iVar3 == 0) {
    iVar3 = *(int *)(*(int *)(param_1 + 0x5420) + 0x4cc);
  }
  else {
    iVar3 = *(int *)(*(int *)(*(int *)(param_1 + 0x5430) + 0x20) + 0x508);
  }
  if (iVar3 != 0) {
    iVar3 = *(int *)(iVar3 + 0x20) * 0x10;
    *(short *)(param_1 + 0x487c) = (short)iVar3;
    *(int *)(param_1 + 0x485c) = *(int *)(param_1 + 0x4854) + iVar3 * *(int *)(param_1 + 0x4878);
    return;
  }
  return;
}

/* _gliSetCurrentPluginDispatchTable @ 0x9ed8 (288 bytes) */
int _gliSetCurrentPluginDispatchTable(param_1)
  int param_1;
{
  undefined *puVar1;
  undefined4 *puVar2;
  uint uVar3;
  int iVar4;
  double fparam_1;
  double in_f2;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  
  puVar1 = PTR__gliDispatchNoop_00111e14;
  if (*(char *)(param_1 + 0x4692) == '\0') {
    uVar3 = (**(code **)(param_1 + 0x4784))
                      (*(undefined4 *)(param_1 + 0x4688),param_1 + 0x4698,param_1 + 0x471c);
    ((void (*)())_gleUpdateViewScissorData)(param_1,fparam_1,in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8);
    if ((uVar3 & 4) == 0) {
      *(undefined1 *)(param_1 + 0x7581) = 4;
    }
    _gleUpdateDispatchCodeChange(param_1,uVar3);
    return;
  }
  iVar4 = 0x21;
  puVar2 = (undefined4 *)(param_1 + 0x4698);
  do {
    *puVar2 = puVar1;
    puVar2 = puVar2 + 1;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  if ((*(int *)(param_1 + 0x48d0) != 0) || (*(int *)(param_1 + 0x48d4) != 0)) {
    *(undefined4 *)(param_1 + 0x48d0) = 0;
    *(undefined4 *)(param_1 + 0x48d4) = 0;
    ((int (*)())_gleUpdatePrimitiveData)(param_1);
    uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0xc) == 0);
    *(undefined **)
     ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0xc) =
         PTR__glArrayElement_Exec_001120e8;
    _gleUpdateDrawArraysFuncs(param_1);
    ((int (*)())_gleSelectVertexSubmitFunc)(param_1);
    *(undefined4 *)(param_1 + 0x488c) = 0;
    *(undefined4 *)(param_1 + 0x4890) = 0;
    *(undefined4 *)(param_1 + 0x4894) = 0;
  }
  return;
}

/* _gliInitDispatchTable @ 0x9ff8 (8072 bytes) */
int _gliInitDispatchTable(param_1)
  int param_1;
{
  uint uVar1;
  
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 8) == 0);
  *(undefined **)((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 8)
       = PTR__glAreTexturesResident_Exec_00113e08;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0xcc) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0xcc) =
       PTR__glColorPointer_Exec_00113e04;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0xe8) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0xe8) =
       PTR__glDeleteLists_Exec_00113e00;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0xec) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0xec) =
       PTR__glDeleteTextures_Exec_00113dfc;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x100) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x100) =
       PTR__glDisableClientState_Exec_00113df8;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x118) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x118) =
       PTR__glEdgeFlagPointer_Exec_00113df4;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x124) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x124) =
       PTR__glEnableClientState_Exec_00113df0;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 300) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 300) =
       PTR__glEndList_Exec_00113dec;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x160) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x160) =
       PTR__glFeedbackBuffer_Exec_00113de8;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x164) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x164) =
       PTR__glFinish_Exec_00112114;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x168) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x168) =
       PTR__glFlush_Exec_00112118;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x184) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x184) =
       PTR__glGenLists_Exec_00113de4;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x188) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x188) =
       PTR__glGenTextures_Exec_00113de0;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x18c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x18c) =
       PTR__glGetBooleanv_Exec_00113ddc;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 400) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 400) =
       PTR__glGetClipPlane_Exec_00113dd8;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x194) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x194) =
       PTR__glGetDoublev_Exec_00113dd4;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x198) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x198) =
       PTR__glGetError_Exec_00113dd0;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x19c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x19c) =
       PTR__glGetFloatv_Exec_00113dcc;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x1a0) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x1a0) =
       PTR__glGetIntegerv_Exec_00113dc8;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x1a4) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x1a4) =
       PTR__glGetLightfv_Exec_00113dc4;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x1a8) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x1a8) =
       PTR__glGetLightiv_Exec_00113dc0;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x1ac) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x1ac) =
       PTR__glGetMapdv_Exec_00113dbc;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x1b0) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x1b0) =
       PTR__glGetMapfv_Exec_00113db8;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x1b4) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x1b4) =
       PTR__glGetMapiv_Exec_00113db4;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x1b8) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x1b8) =
       PTR__glGetMaterialfv_Exec_00113db0;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x1bc) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x1bc) =
       PTR__glGetMaterialiv_Exec_00113dac;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x1c0) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x1c0) =
       PTR__glGetPixelMapfv_Exec_00113da8;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x1c4) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x1c4) =
       PTR__glGetPixelMapuiv_Exec_00113da4;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x1c8) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x1c8) =
       PTR__glGetPixelMapusv_Exec_00113da0;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x1cc) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x1cc) =
       PTR__glGetPointerv_Exec_00113d9c;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x1d0) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x1d0) =
       PTR__glGetPolygonStipple_Exec_00113d98;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x1d4) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x1d4) =
       PTR__glGetString_Exec_00113d94;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x1d8) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x1d8) =
       PTR__glGetTexEnvfv_Exec_00113d90;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x1dc) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x1dc) =
       PTR__glGetTexEnviv_Exec_00113d8c;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x1e0) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x1e0) =
       PTR__glGetTexGendv_Exec_00113d88;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x1e4) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x1e4) =
       PTR__glGetTexGenfv_Exec_00113d84;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x1e8) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x1e8) =
       PTR__glGetTexGeniv_Exec_00113d80;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x1ec) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x1ec) =
       PTR__glGetTexImage_Exec_00113d7c;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x1f0) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x1f0) =
       PTR__glGetTexLevelParameterfv_Exec_00113d78;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 500) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 500) =
       PTR__glGetTexLevelParameteriv_Exec_00113d74;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x1f8) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x1f8) =
       PTR__glGetTexParameterfv_Exec_00113d70;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x1fc) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x1fc) =
       PTR__glGetTexParameteriv_Exec_00113d6c;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x208) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x208) =
       PTR__glIndexPointer_Exec_00113d68;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x238) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x238) =
       PTR__glInterleavedArrays_Exec_00113d64;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x23c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x23c) =
       PTR__glIsEnabled_Exec_00113d60;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x240) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x240) =
       PTR__glIsList_Exec_00113d5c;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x244) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x244) =
       PTR__glIsTexture_Exec_00113d58;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x2c4) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x2c4) =
       PTR__glNewList_Exec_00113d54;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x2f0) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x2f0) =
       PTR__glNormalPointer_Exec_00113d50;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x308) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x308) =
       PTR__glPixelStoref_Exec_00113d4c;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x30c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x30c) =
       PTR__glPixelStorei_Exec_00113d48;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x330) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x330) =
       PTR__glPopClientAttrib_Exec_00113d44;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x344) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x344) =
       PTR__glPushClientAttrib_Exec_00113d40;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x3b4) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x3b4) =
       PTR__glReadPixels_Exec_00113d3c;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x3d8) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x3d8) =
       PTR__glRenderMode_Exec_00113d38;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x3f0) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x3f0) =
       PTR__glSelectBuffer_Exec_00113d34;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x484) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x484) =
       PTR__glTexCoordPointer_Exec_00113d30;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x538) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x538) =
       PTR__glVertexPointer_Exec_00113d2c;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x54c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x54c) =
       PTR__glLockArraysEXT_Exec_00113d28;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x550) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x550) =
       PTR__glUnlockArraysEXT_Exec_00113d24;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x554) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x554) =
       PTR__glClientActiveTexture_Exec_00113d20;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x668) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x668) =
       PTR__glGetColorTable_Exec_00113d1c;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x66c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x66c) =
       PTR__glGetColorTableParameterfv_Exec_00113d18;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x670) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x670) =
       PTR__glGetColorTableParameteriv_Exec_00113d14;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x69c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x69c) =
       PTR__glGetConvolutionFilter_Exec_00113d10;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x6a0) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x6a0) =
       PTR__glGetConvolutionParameterfv_Exec_00113d0c;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x6a4) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x6a4) =
       PTR__glGetConvolutionParameteriv_Exec_00113d08;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x6a8) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x6a8) =
       PTR__glGetSeparableFilter_Exec_00113d04;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x6b0) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x6b0) =
       PTR__glGetHistogram_Exec_00113d00;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x6b4) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x6b4) =
       PTR__glGetHistogramParameterfv_Exec_00113cfc;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x6b8) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x6b8) =
       PTR__glGetHistogramParameteriv_Exec_00113cf8;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x6bc) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x6bc) =
       PTR__glGetMinmax_Exec_00113cf4;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x6c0) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x6c0) =
       PTR__glGetMinmaxParameterfv_Exec_00113cf0;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x6c4) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x6c4) =
       PTR__glGetMinmaxParameteriv_Exec_00113cec;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x604) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x604) =
       PTR__glGetCompressedTexImage_Exec_00113ce8;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x648) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x648) =
       PTR__glSecondaryColorPointer_Exec_00113ce4;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x64c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x64c) =
       PTR__glVertexArrayRangeEXT_Exec_00113ce0;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x650) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x650) =
       PTR__glFlushVertexArrayRangeEXT_Exec_00113cdc;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x700) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x700) =
       PTR__glGetCombinerInputParameterfvNV_Exec_00113cd8;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x704) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x704) =
       PTR__glGetCombinerInputParameterivNV_Exec_00113cd4;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x708) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x708) =
       PTR__glGetCombinerOutputParameterfvNV_Exec_00113cd0;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x70c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x70c) =
       PTR__glGetCombinerOutputParameterivNV_Exec_00113ccc;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x710) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x710) =
       PTR__glGetFinalCombinerInputParameterfvNV_Exec_00113cc8;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x714) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x714) =
       PTR__glGetFinalCombinerInputParameterivNV_Exec_00113cc4;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x71c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x71c) =
       PTR__glGetCombinerStageParameterfvNV_Exec_00113cc0;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x760) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x760) =
       PTR__glDeleteProgramsARB_Exec_00113cbc;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x764) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x764) =
       PTR__glGenProgramsARB_Exec_00113cb8;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x768) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x768) =
       PTR__glIsProgramARB_Exec_00113cb4;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x7fc) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x7fc) =
       PTR__glVertexAttribPointerARB_Exec_00113cb0;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x800) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x800) =
       PTR__glEnableVertexAttribArrayARB_Exec_00113cac;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x804) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x804) =
       PTR__glDisableVertexAttribArrayARB_Exec_00113ca8;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x808) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x808) =
       PTR__glGetVertexAttribdvARB_Exec_00113ca4;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x80c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x80c) =
       PTR__glGetVertexAttribfvARB_Exec_00113ca0;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x810) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x810) =
       PTR__glGetVertexAttribivARB_Exec_00113c9c;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x814) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x814) =
       PTR__glGetVertexAttribPointervARB_Exec_00113c98;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x838) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x838) =
       PTR__glGetProgramEnvParameterdvARB_Exec_00113c94;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x83c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x83c) =
       PTR__glGetProgramEnvParameterfvARB_Exec_00113c90;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x840) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x840) =
       PTR__glGetProgramLocalParameterdvARB_Exec_00113c8c;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x844) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x844) =
       PTR__glGetProgramLocalParameterfvARB_Exec_00113c88;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x84c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x84c) =
       PTR__glGetProgramStringARB_Exec_00113c84;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x850) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x850) =
       PTR__glGetProgramivARB_Exec_00113c80;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x85c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x85c) =
       PTR__glIsVertexAttribEnabledARB_Exec_00113c7c;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x73c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x73c) =
       PTR__glGenFencesAPPLE_Exec_00113c78;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x740) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x740) =
       PTR__glDeleteFencesAPPLE_Exec_00113c74;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x748) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x748) =
       PTR__glIsFenceAPPLE_Exec_00113c70;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x74c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x74c) =
       PTR__glTestFenceAPPLE_Exec_00113c6c;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x754) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x754) =
       PTR__glTestObjectAPPLE_Exec_00113c68;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x890) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x890) =
       PTR__glFogCoordPointer_Exec_00113c64;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x720) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x720) =
       PTR__glTextureRangeAPPLE_Exec_00113c60;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x724) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x724) =
       PTR__glGetTexParameterPointervAPPLE_Exec_00113c5c;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x89c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x89c) =
       PTR__glDeleteVertexArraysEXT_Exec_00113c58;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x8a0) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x8a0) =
       PTR__glGenVertexArraysEXT_Exec_00113c54;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x8a4) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x8a4) =
       PTR__glIsVertexArrayEXT_Exec_00113c50;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x8a8) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x8a8) =
       PTR__glElementPointerAPPLE_Exec_00113c4c;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x8d4) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x8d4) =
       PTR__glWeightPointerARB_Exec_00113c48;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x930) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x930) =
       PTR__glFlushRender_Exec_00113c44;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x934) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x934) =
       PTR__glFinishRender_Exec_00113c40;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x938) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x938) =
       PTR__glSwap_Exec_0011211c;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x93c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x93c) =
       PTR__glDeleteObjectARB_Exec_00113c3c;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x940) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x940) =
       PTR__glGetHandleARB_Exec_00113c38;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x944) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x944) =
       PTR__glDetachObjectARB_Exec_00113c34;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x948) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x948) =
       PTR__glCreateShaderObjectARB_Exec_00113c30;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x94c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x94c) =
       PTR__glShaderSourceARB_Exec_00113c2c;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x950) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x950) =
       PTR__glCompileShaderARB_Exec_00113c28;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x954) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x954) =
       PTR__glCreateProgramObjectARB_Exec_00113c24;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x958) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x958) =
       PTR__glAttachObjectARB_Exec_00113c20;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x95c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x95c) =
       PTR__glLinkProgramARB_Exec_00113c1c;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x964) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x964) =
       PTR__glValidateProgramARB_Exec_00113c18;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x9b4) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x9b4) =
       PTR__glGetObjectParameterfvARB_Exec_00113c14;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x9b8) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x9b8) =
       PTR__glGetObjectParameterivARB_Exec_00113c10;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x9bc) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x9bc) =
       PTR__glGetInfoLogARB_Exec_00113c0c;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x9c0) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x9c0) =
       PTR__glGetAttachedObjectsARB_Exec_00113c08;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x9c4) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x9c4) =
       PTR__glGetUniformLocationARB_Exec_00113c04;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x9c8) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x9c8) =
       PTR__glGetActiveUniformARB_Exec_00113c00;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x9cc) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x9cc) =
       PTR__glGetUniformfvARB_Exec_00113bfc;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x9d0) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x9d0) =
       PTR__glGetUniformivARB_Exec_00113bf8;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x9d4) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x9d4) =
       PTR__glGetShaderSourceARB_Exec_00113bf4;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x9d8) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x9d8) =
       PTR__glBindAttribLocationARB_Exec_00113bf0;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x9dc) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x9dc) =
       PTR__glGetActiveAttribARB_Exec_00113bec;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x9e0) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x9e0) =
       PTR__glGetAttribLocationARB_Exec_00113be8;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x9e8) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x9e8) =
       PTR__glGenQueries_Exec_00113be4;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x9ec) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x9ec) =
       PTR__glDeleteQueries_Exec_00113be0;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x9f0) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x9f0) =
       PTR__glIsQuery_Exec_00113bdc;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x9fc) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x9fc) =
       PTR__glGetQueryiv_Exec_00113bd8;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0xa00) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0xa00) =
       PTR__glGetQueryObjectiv_Exec_00113bd4;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0xa04) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0xa04) =
       PTR__glGetQueryObjectuiv_Exec_00113bd0;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0xa08) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0xa08) =
       PTR__glBindBuffer_Exec_00113bcc;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0xa0c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0xa0c) =
       PTR__glDeleteBuffers_Exec_00113bc8;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0xa10) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0xa10) =
       PTR__glGenBuffers_Exec_00113bc4;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0xa14) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0xa14) =
       PTR__glIsBuffer_Exec_00113bc0;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0xa18) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0xa18) =
       PTR__glBufferData_Exec_00113bbc;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0xa1c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0xa1c) =
       PTR__glBufferSubData_Exec_00113bb8;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0xa20) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0xa20) =
       PTR__glGetBufferSubData_Exec_00113bb4;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0xa24) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0xa24) =
       PTR__glMapBuffer_Exec_00113bb0;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0xa28) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0xa28) =
       PTR__glUnmapBuffer_Exec_00113bac;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0xa2c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0xa2c) =
       PTR__glGetBufferParameteriv_Exec_00113ba8;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0xa30) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0xa30) =
       PTR__glGetBufferPointerv_Exec_00113ba4;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0xa38) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0xa38) =
       PTR__glDrawBuffersARB_Exec_00113ba0;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0xa3c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0xa3c) =
       PTR__glIsShader_Exec_00113b9c;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0xa40) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0xa40) =
       PTR__glIsProgram_Exec_00113b98;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0xa44) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0xa44) =
       PTR__glGetShaderiv_Exec_00113b94;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0xa48) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0xa48) =
       PTR__glGetProgramiv_Exec_00113b90;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0xa4c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0xa4c) =
       PTR__glGetShaderInfoLog_Exec_00113b8c;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0xa50) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0xa50) =
       PTR__glGetProgramInfoLog_Exec_00113b88;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0xa54) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0xa54) =
       PTR__glStencilFuncSeparate_Exec_00113b84;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0xa58) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0xa58) =
       PTR__glStencilMaskSeparate_Exec_00113b80;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0xa64) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0xa64) =
       PTR__glIsRenderbufferEXT_Exec_00113b7c;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0xa68) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0xa68) =
       PTR__glBindRenderbufferEXT_Exec_00113b78;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0xa6c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0xa6c) =
       PTR__glDeleteRenderbuffersEXT_Exec_00113b74;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0xa70) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0xa70) =
       PTR__glGenRenderbuffersEXT_Exec_00113b70;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0xa74) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0xa74) =
       PTR__glRenderbufferStorageEXT_Exec_00113b6c;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0xa78) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0xa78) =
       PTR__glGetRenderbufferParameterivEXT_Exec_00113b68;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0xa7c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0xa7c) =
       PTR__glIsFramebufferEXT_Exec_00113b64;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0xa80) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0xa80) =
       PTR__glBindFramebufferEXT_Exec_00113b60;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0xa84) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0xa84) =
       PTR__glDeleteFramebuffersEXT_Exec_00113b5c;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0xa88) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0xa88) =
       PTR__glGenFramebuffersEXT_Exec_00113b58;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0xa8c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0xa8c) =
       PTR__glCheckFramebufferStatusEXT_Exec_00113b54;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0xa90) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0xa90) =
       PTR__glFramebufferTexture1DEXT_Exec_00113b50;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0xa94) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0xa94) =
       PTR__glFramebufferTexture2DEXT_Exec_00113b4c;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0xa98) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0xa98) =
       PTR__glFramebufferTexture3DEXT_Exec_00113b48;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0xa9c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0xa9c) =
       PTR__glFramebufferRenderbufferEXT_Exec_00113b44;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0xaa0) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0xaa0) =
       PTR__glGetFramebufferAttachmentParameterivEXT_Exec_00113b40;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0xaa4) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0xaa4) =
       PTR__glGenerateMipmapEXT_Exec_00113b3c;
  return;
}

/* _gliExecDispatchTable @ 0xbf80 (23616 bytes) */
int _gliExecDispatchTable(param_1)
  int param_1;
{
  int iVar1;
  undefined *puVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = -(uint)(**(int **)(param_1 + 0x4684) == 0);
  *(undefined **)(*(uint *)(param_1 + 0x4680) & uVar3 | (uint)*(int **)(param_1 + 0x4684) & ~uVar3)
       = PTR__glAccum_Exec_00113b38;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 4) == 0);
  *(undefined **)((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 4)
       = PTR__glAlphaFunc_Exec_00113b34;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0xc) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0xc) =
       PTR__glArrayElement_Exec_001120e8;
  if ((*(char *)(param_1 + 0x759c) == '\0') || (*(char *)(param_1 + 0x759d) == '\0')) {
    uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x10) == 0);
    uVar3 = *(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3;
    puVar2 = PTR__glBegin_NoopExec_00112078;
  }
  else {
    uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x10) == 0);
    uVar3 = *(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3;
    puVar2 = PTR__glBegin_Exec_00112074;
  }
  *(undefined **)(uVar3 + 0x10) = puVar2;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x14) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x14) =
       PTR__glBindTexture_Exec_00113b30;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x18) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x18) =
       PTR__glBitmap_Exec_0011207c;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x1c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x1c) =
       PTR__glBlendFunc_Exec_00113b2c;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x20) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x20) =
       PTR__glCallList_Exec_00113b28;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x24) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x24) =
       PTR__glCallLists_Exec_00113b24;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x28) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x28) =
       PTR__glClear_Exec_0011209c;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x2c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x2c) =
       PTR__glClearAccum_Exec_00113b20;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x30) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x30) =
       PTR__glClearColor_Exec_00113b1c;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x34) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x34) =
       PTR__glClearDepth_Exec_00113b18;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x38) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x38) =
       PTR__glClearIndex_Exec_00113b14;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x3c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x3c) =
       PTR__glClearStencil_Exec_00113b10;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x40) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x40) =
       PTR__glClipPlane_Exec_00113b0c;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x44) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x44) =
       PTR__glColor3b_Exec_00113b08;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x48) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x48) =
       PTR__glColor3bv_Exec_00113b04;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x4c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x4c) =
       PTR__glColor3d_Exec_00113b00;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x50) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x50) =
       PTR__glColor3dv_Exec_00113afc;
  if (*(char *)(param_1 + 0x4df8) == '\0') {
    uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x54) == 0);
    *(undefined **)
     ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x54) =
         PTR__glColor3f_NoColorMat_Exec_00112178;
    uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x58) == 0);
    *(undefined **)
     ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x58) =
         PTR__glColor3fv_NoColorMat_Exec_00112174;
    uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x94) == 0);
    *(undefined **)
     ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x94) =
         PTR__glColor4f_NoColorMat_Exec_00112170;
    uVar4 = *(uint *)(param_1 + 0x4684);
    uVar3 = *(uint *)(param_1 + 0x4680);
    iVar1 = *(int *)(uVar4 + 0x98);
    puVar2 = PTR__glColor4fv_NoColorMat_Exec_0011216c;
  }
  else {
    uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x54) == 0);
    *(undefined **)
     ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x54) =
         PTR__glColor3f_ColorMat_Exec_00112188;
    uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x58) == 0);
    *(undefined **)
     ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x58) =
         PTR__glColor3fv_ColorMat_Exec_00112184;
    uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x94) == 0);
    *(undefined **)
     ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x94) =
         PTR__glColor4f_ColorMat_Exec_00112180;
    uVar4 = *(uint *)(param_1 + 0x4684);
    uVar3 = *(uint *)(param_1 + 0x4680);
    iVar1 = *(int *)(uVar4 + 0x98);
    puVar2 = PTR__glColor4fv_ColorMat_Exec_0011217c;
  }
  *(undefined **)((uVar3 & -(uint)(iVar1 == 0) | uVar4 & ~-(uint)(iVar1 == 0)) + 0x98) = puVar2;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x5c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x5c) =
       PTR__glColor3i_Exec_00113af8;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x60) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x60) =
       PTR__glColor3iv_Exec_00113af4;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 100) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 100) =
       PTR__glColor3s_Exec_00113af0;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x68) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x68) =
       PTR__glColor3sv_Exec_00113aec;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x6c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x6c) =
       PTR__glColor3ub_Exec_00113ae8;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x70) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x70) =
       PTR__glColor3ubv_Exec_00113ae4;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x74) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x74) =
       PTR__glColor3ui_Exec_00113ae0;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x78) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x78) =
       PTR__glColor3uiv_Exec_00113adc;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x7c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x7c) =
       PTR__glColor3us_Exec_00113ad8;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x80) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x80) =
       PTR__glColor3usv_Exec_00113ad4;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x84) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x84) =
       PTR__glColor4b_Exec_00113ad0;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x88) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x88) =
       PTR__glColor4bv_Exec_00113acc;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x8c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x8c) =
       PTR__glColor4d_Exec_00113ac8;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x90) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x90) =
       PTR__glColor4dv_Exec_00113ac4;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x9c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x9c) =
       PTR__glColor4i_Exec_00113ac0;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0xa0) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0xa0) =
       PTR__glColor4iv_Exec_00113abc;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0xa4) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0xa4) =
       PTR__glColor4s_Exec_00113ab8;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0xa8) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0xa8) =
       PTR__glColor4sv_Exec_00113ab4;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0xac) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0xac) =
       PTR__glColor4ub_Exec_00113ab0;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0xb0) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0xb0) =
       PTR__glColor4ubv_Exec_00113aac;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0xb4) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0xb4) =
       PTR__glColor4ui_Exec_00113aa8;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0xb8) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0xb8) =
       PTR__glColor4uiv_Exec_00113aa4;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0xbc) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0xbc) =
       PTR__glColor4us_Exec_00113aa0;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0xc0) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0xc0) =
       PTR__glColor4usv_Exec_00113a9c;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0xc4) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0xc4) =
       PTR__glColorMask_Exec_00113a98;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 200) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 200) =
       PTR__glColorMaterial_Exec_00113a94;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0xd0) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0xd0) =
       PTR__glCopyPixels_Exec_00112098;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0xd4) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0xd4) =
       PTR__glCopyTexImage1D_Exec_00112094;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0xd8) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0xd8) =
       PTR__glCopyTexImage2D_Exec_00112090;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0xdc) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0xdc) =
       PTR__glCopyTexSubImage1D_Exec_0011208c;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0xe0) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0xe0) =
       PTR__glCopyTexSubImage2D_Exec_00112088;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0xe4) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0xe4) =
       PTR__glCullFace_Exec_00113a90;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0xf0) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0xf0) =
       PTR__glDepthFunc_Exec_00113a8c;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0xf4) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0xf4) =
       PTR__glDepthMask_Exec_00113a88;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0xf8) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0xf8) =
       PTR__glDepthRange_Exec_00113a84;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0xfc) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0xfc) =
       PTR__glDisable_Exec_00113a80;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x104) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x104) =
       PTR__glDrawArrays_Exec_001120e4;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x108) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x108) =
       PTR__glDrawBuffer_Exec_00113a7c;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x10c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x10c) =
       PTR__glDrawElements_Exec_001120e0;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x110) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x110) =
       PTR__glDrawPixels_Exec_00112080;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x114) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x114) =
       PTR__glEdgeFlag_Exec_00113a78;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x11c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x11c) =
       PTR__glEdgeFlagv_Exec_00113a74;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x120) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x120) =
       PTR__glEnable_Exec_00113a70;
  if ((*(char *)(param_1 + 0x7580) != '\0') && (*(int *)(param_1 + 0x4e1c) == 0x1c00)) {
    if ((*(int *)(param_1 + 0x468c) == 0) || (*(char *)(*(int *)(param_1 + 0x468c) + 0x7a) == '\0'))
    {
      uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x128) == 0);
      uVar3 = *(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3;
      puVar2 = PTR__glEndRDirty_Exec_00112160;
      goto LAB_0000ccc0;
    }
    if (*(char *)(param_1 + 0x4df8) == '\0') {
      uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x128) == 0);
      uVar3 = *(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3;
      puVar2 = PTR__glEndNoMat_Exec_00112168;
      goto LAB_0000ccc0;
    }
  }
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x128) == 0);
  uVar3 = *(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3;
  puVar2 = PTR__glEnd_Exec_00112164;
LAB_0000ccc0:
  *(undefined **)(uVar3 + 0x128) = puVar2;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x130) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x130) =
       PTR__glEvalCoord1d_Exec_00113a6c;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x134) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x134) =
       PTR__glEvalCoord1dv_Exec_00113a68;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x138) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x138) =
       PTR__glEvalCoord1f_Exec_00113a64;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x13c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x13c) =
       PTR__glEvalCoord1fv_Exec_00113a60;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x140) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x140) =
       PTR__glEvalCoord2d_Exec_00113a5c;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x144) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x144) =
       PTR__glEvalCoord2dv_Exec_00113a58;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x148) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x148) =
       PTR__glEvalCoord2f_Exec_00113a54;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x14c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x14c) =
       PTR__glEvalCoord2fv_Exec_00113a50;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x150) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x150) =
       PTR__glEvalMesh1_Exec_00113a4c;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x154) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x154) =
       PTR__glEvalMesh2_Exec_00113a48;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x158) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x158) =
       PTR__glEvalPoint1_Exec_00113a44;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x15c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x15c) =
       PTR__glEvalPoint2_Exec_00113a40;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x16c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x16c) =
       PTR__glFogf_Exec_00113a3c;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x170) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x170) =
       PTR__glFogfv_Exec_00113a38;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x174) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x174) =
       PTR__glFogi_Exec_00113a34;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x178) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x178) =
       PTR__glFogiv_Exec_00113a30;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x17c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x17c) =
       PTR__glFrontFace_Exec_00113a2c;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x180) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x180) =
       PTR__glFrustum_Exec_00113a28;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x200) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x200) =
       PTR__glHint_Exec_00113a24;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x204) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x204) =
       PTR__glIndexMask_Exec_00113a20;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x20c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x20c) =
       PTR__glIndexd_Exec_00113a1c;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x210) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x210) =
       PTR__glIndexdv_Exec_00113a18;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x214) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x214) =
       PTR__glIndexf_Exec_00113a14;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x218) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x218) =
       PTR__glIndexfv_Exec_00113a10;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x21c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x21c) =
       PTR__glIndexi_Exec_00113a0c;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x220) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x220) =
       PTR__glIndexiv_Exec_00113a08;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x224) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x224) =
       PTR__glIndexs_Exec_00113a04;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x228) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x228) =
       PTR__glIndexsv_Exec_00113a00;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x22c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x22c) =
       PTR__glIndexub_Exec_001139fc;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x230) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x230) =
       PTR__glIndexubv_Exec_001139f8;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x234) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x234) =
       PTR__glInitNames_Exec_001139f4;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x248) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x248) =
       PTR__glLightModelf_Exec_001139f0;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x24c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x24c) =
       PTR__glLightModelfv_Exec_001139ec;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x250) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x250) =
       PTR__glLightModeli_Exec_001139e8;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x254) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x254) =
       PTR__glLightModeliv_Exec_001139e4;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 600) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 600) =
       PTR__glLightf_Exec_001139e0;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x25c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x25c) =
       PTR__glLightfv_Exec_001139dc;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x260) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x260) =
       PTR__glLighti_Exec_001139d8;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x264) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x264) =
       PTR__glLightiv_Exec_001139d4;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x268) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x268) =
       PTR__glLineStipple_Exec_001139d0;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x26c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x26c) =
       PTR__glLineWidth_Exec_001139cc;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x270) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x270) =
       PTR__glListBase_Exec_001139c8;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x274) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x274) =
       PTR__glLoadIdentity_Exec_001139c4;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x278) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x278) =
       PTR__glLoadMatrixd_Exec_001139c0;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x27c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x27c) =
       PTR__glLoadMatrixf_Exec_001139bc;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x280) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x280) =
       PTR__glLoadName_Exec_001139b8;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x284) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x284) =
       PTR__glLogicOp_Exec_001139b4;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x288) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x288) =
       PTR__glMap1d_Exec_001139b0;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x28c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x28c) =
       PTR__glMap1f_Exec_001139ac;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x290) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x290) =
       PTR__glMap2d_Exec_001139a8;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x294) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x294) =
       PTR__glMap2f_Exec_001139a4;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x298) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x298) =
       PTR__glMapGrid1d_Exec_001139a0;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x29c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x29c) =
       PTR__glMapGrid1f_Exec_0011399c;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x2a0) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x2a0) =
       PTR__glMapGrid2d_Exec_00113998;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x2a4) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x2a4) =
       PTR__glMapGrid2f_Exec_00113994;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x2a8) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x2a8) =
       PTR__glMaterialf_Exec_00113990;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x2ac) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x2ac) =
       PTR__glMaterialfv_Exec_0011398c;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x2b0) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x2b0) =
       PTR__glMateriali_Exec_00113988;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x2b4) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x2b4) =
       PTR__glMaterialiv_Exec_00113984;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x2b8) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x2b8) =
       PTR__glMatrixMode_Exec_00113980;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 700) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 700) =
       PTR__glMultMatrixd_Exec_0011397c;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x2c0) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x2c0) =
       PTR__glMultMatrixf_Exec_00113978;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x2c8) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x2c8) =
       PTR__glNormal3b_Exec_00113974;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x2cc) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x2cc) =
       PTR__glNormal3bv_Exec_00113970;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x2d0) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x2d0) =
       PTR__glNormal3d_Exec_0011396c;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x2d4) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x2d4) =
       PTR__glNormal3dv_Exec_00113968;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x2d8) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x2d8) =
       PTR__glNormal3f_Exec_00113964;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x2dc) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x2dc) =
       PTR__glNormal3fv_Exec_00113960;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x2e0) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x2e0) =
       PTR__glNormal3i_Exec_0011395c;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x2e4) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x2e4) =
       PTR__glNormal3iv_Exec_00113958;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x2e8) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x2e8) =
       PTR__glNormal3s_Exec_00113954;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x2ec) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x2ec) =
       PTR__glNormal3sv_Exec_00113950;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x2f4) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x2f4) =
       PTR__glOrtho_Exec_0011394c;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x2f8) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x2f8) =
       PTR__glPassThrough_Exec_00113948;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x2fc) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x2fc) =
       PTR__glPixelMapfv_Exec_00113944;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x300) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x300) =
       PTR__glPixelMapuiv_Exec_00113940;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x304) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x304) =
       PTR__glPixelMapusv_Exec_0011393c;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x310) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x310) =
       PTR__glPixelTransferf_Exec_00113938;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x314) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x314) =
       PTR__glPixelTransferi_Exec_00113934;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x318) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x318) =
       PTR__glPixelZoom_Exec_00113930;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x31c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x31c) =
       PTR__glPointSize_Exec_0011392c;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 800) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 800) =
       PTR__glPolygonMode_Exec_00113928;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x324) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x324) =
       PTR__glPolygonOffset_Exec_00113924;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x328) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x328) =
       PTR__glPolygonStipple_Exec_00113920;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x32c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x32c) =
       PTR__glPopAttrib_Exec_0011391c;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x334) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x334) =
       PTR__glPopMatrix_Exec_00113918;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x338) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x338) =
       PTR__glPopName_Exec_00113914;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x33c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x33c) =
       PTR__glPrioritizeTextures_Exec_00113910;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x340) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x340) =
       PTR__glPushAttrib_Exec_0011390c;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x348) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x348) =
       PTR__glPushMatrix_Exec_00113908;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x34c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x34c) =
       PTR__glPushName_Exec_00113904;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x350) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x350) =
       PTR__glRasterPos2d_Exec_00113900;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x354) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x354) =
       PTR__glRasterPos2dv_Exec_001138fc;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x358) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x358) =
       PTR__glRasterPos2f_Exec_001138f8;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x35c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x35c) =
       PTR__glRasterPos2fv_Exec_001138f4;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x360) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x360) =
       PTR__glRasterPos2i_Exec_001138f0;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x364) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x364) =
       PTR__glRasterPos2iv_Exec_001138ec;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x368) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x368) =
       PTR__glRasterPos2s_Exec_001138e8;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x36c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x36c) =
       PTR__glRasterPos2sv_Exec_001138e4;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x370) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x370) =
       PTR__glRasterPos3d_Exec_001138e0;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x374) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x374) =
       PTR__glRasterPos3dv_Exec_001138dc;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x378) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x378) =
       PTR__glRasterPos3f_Exec_001138d8;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x37c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x37c) =
       PTR__glRasterPos3fv_Exec_001138d4;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x380) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x380) =
       PTR__glRasterPos3i_Exec_001138d0;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 900) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 900) =
       PTR__glRasterPos3iv_Exec_001138cc;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x388) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x388) =
       PTR__glRasterPos3s_Exec_001138c8;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x38c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x38c) =
       PTR__glRasterPos3sv_Exec_001138c4;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x390) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x390) =
       PTR__glRasterPos4d_Exec_001138c0;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x394) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x394) =
       PTR__glRasterPos4dv_Exec_001138bc;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x398) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x398) =
       PTR__glRasterPos4f_Exec_001138b8;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x39c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x39c) =
       PTR__glRasterPos4fv_Exec_001138b4;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x3a0) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x3a0) =
       PTR__glRasterPos4i_Exec_001138b0;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x3a4) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x3a4) =
       PTR__glRasterPos4iv_Exec_001138ac;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x3a8) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x3a8) =
       PTR__glRasterPos4s_Exec_001138a8;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x3ac) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x3ac) =
       PTR__glRasterPos4sv_Exec_001138a4;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x3b0) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x3b0) =
       PTR__glReadBuffer_Exec_001138a0;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x3b8) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x3b8) =
       PTR__glRectd_Exec_0011389c;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x3bc) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x3bc) =
       PTR__glRectdv_Exec_00113898;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x3c0) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x3c0) =
       PTR__glRectf_Exec_00113894;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x3c4) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x3c4) =
       PTR__glRectfv_Exec_00113890;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x3c8) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x3c8) =
       PTR__glRecti_Exec_0011388c;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x3cc) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x3cc) =
       PTR__glRectiv_Exec_00113888;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x3d0) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x3d0) =
       PTR__glRects_Exec_00113884;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x3d4) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x3d4) =
       PTR__glRectsv_Exec_00113880;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x3dc) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x3dc) =
       PTR__glRotated_Exec_0011387c;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x3e0) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x3e0) =
       PTR__glRotatef_Exec_00113878;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x3e4) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x3e4) =
       PTR__glScaled_Exec_00113874;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 1000) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 1000) =
       PTR__glScalef_Exec_00113870;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x3ec) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x3ec) =
       PTR__glScissor_Exec_0011386c;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x3f4) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x3f4) =
       PTR__glShadeModel_Exec_00113868;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x3f8) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x3f8) =
       PTR__glStencilFunc_Exec_00113864;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x3fc) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x3fc) =
       PTR__glStencilMask_Exec_00113860;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x400) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x400) =
       PTR__glStencilOp_Exec_0011385c;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x404) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x404) =
       PTR__glTexCoord1d_Exec_00113858;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x408) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x408) =
       PTR__glTexCoord1dv_Exec_00113854;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x40c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x40c) =
       PTR__glTexCoord1f_Exec_00113850;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x410) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x410) =
       PTR__glTexCoord1fv_Exec_0011384c;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x414) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x414) =
       PTR__glTexCoord1i_Exec_00113848;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x418) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x418) =
       PTR__glTexCoord1iv_Exec_00113844;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x41c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x41c) =
       PTR__glTexCoord1s_Exec_00113840;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x420) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x420) =
       PTR__glTexCoord1sv_Exec_0011383c;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x424) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x424) =
       PTR__glTexCoord2d_Exec_00113838;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x428) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x428) =
       PTR__glTexCoord2dv_Exec_00113834;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x42c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x42c) =
       PTR__glTexCoord2f_Exec_00113830;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x430) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x430) =
       PTR__glTexCoord2fv_Exec_0011382c;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x434) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x434) =
       PTR__glTexCoord2i_Exec_00113828;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x438) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x438) =
       PTR__glTexCoord2iv_Exec_00113824;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x43c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x43c) =
       PTR__glTexCoord2s_Exec_00113820;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x440) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x440) =
       PTR__glTexCoord2sv_Exec_0011381c;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x444) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x444) =
       PTR__glTexCoord3d_Exec_00113818;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x448) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x448) =
       PTR__glTexCoord3dv_Exec_00113814;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x44c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x44c) =
       PTR__glTexCoord3f_Exec_00113810;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x450) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x450) =
       PTR__glTexCoord3fv_Exec_0011380c;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x454) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x454) =
       PTR__glTexCoord3i_Exec_00113808;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x458) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x458) =
       PTR__glTexCoord3iv_Exec_00113804;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x45c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x45c) =
       PTR__glTexCoord3s_Exec_00113800;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x460) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x460) =
       PTR__glTexCoord3sv_Exec_001137fc;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x464) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x464) =
       PTR__glTexCoord4d_Exec_001137f8;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x468) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x468) =
       PTR__glTexCoord4dv_Exec_001137f4;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x46c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x46c) =
       PTR__glTexCoord4f_Exec_001137f0;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x470) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x470) =
       PTR__glTexCoord4fv_Exec_001137ec;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x474) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x474) =
       PTR__glTexCoord4i_Exec_001137e8;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x478) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x478) =
       PTR__glTexCoord4iv_Exec_001137e4;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x47c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x47c) =
       PTR__glTexCoord4s_Exec_001137e0;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x480) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x480) =
       PTR__glTexCoord4sv_Exec_001137dc;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x488) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x488) =
       PTR__glTexEnvf_Exec_001137d8;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x48c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x48c) =
       PTR__glTexEnvfv_Exec_001137d4;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x490) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x490) =
       PTR__glTexEnvi_Exec_001137d0;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x494) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x494) =
       PTR__glTexEnviv_Exec_001137cc;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x498) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x498) =
       PTR__glTexGend_Exec_001137c8;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x49c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x49c) =
       PTR__glTexGendv_Exec_001137c4;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x4a0) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x4a0) =
       PTR__glTexGenf_Exec_001137c0;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x4a4) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x4a4) =
       PTR__glTexGenfv_Exec_001137bc;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x4a8) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x4a8) =
       PTR__glTexGeni_Exec_001137b8;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x4ac) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x4ac) =
       PTR__glTexGeniv_Exec_001137b4;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x4b0) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x4b0) =
       PTR__glTexImage1D_Exec_001137b0;
  if (*(char *)(param_1 + 0x7587) == '\0') {
    uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x4b4) == 0);
    uVar3 = *(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3;
    puVar2 = PTR__glTexImage2D_Exec_001137ac;
  }
  else {
    uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x4b4) == 0);
    uVar3 = *(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3;
    puVar2 = PTR__glTexImage2D_FlushExec_001137a8;
  }
  *(undefined **)(uVar3 + 0x4b4) = puVar2;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x4b8) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x4b8) =
       PTR__glTexParameterf_Exec_001137a4;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x4bc) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x4bc) =
       PTR__glTexParameterfv_Exec_001137a0;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x4c0) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x4c0) =
       PTR__glTexParameteri_Exec_0011379c;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x4c4) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x4c4) =
       PTR__glTexParameteriv_Exec_00113798;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x4c8) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x4c8) =
       PTR__glTexSubImage1D_Exec_00113794;
  if (*(char *)(param_1 + 0x7586) == '\0') {
    uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x4cc) == 0);
    uVar3 = *(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3;
    puVar2 = PTR__glTexSubImage2D_Exec_00113790;
  }
  else {
    uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x4cc) == 0);
    uVar3 = *(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3;
    puVar2 = PTR__glTexSubImage2D_FlushExec_0011378c;
  }
  *(undefined **)(uVar3 + 0x4cc) = puVar2;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x4d0) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x4d0) =
       PTR__glTranslated_Exec_00113788;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x4d4) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x4d4) =
       PTR__glTranslatef_Exec_00113784;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x4d8) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x4d8) =
       PTR__glVertex2d_Exec_00113780;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x4dc) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x4dc) =
       PTR__glVertex2dv_Exec_0011377c;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x4e0) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x4e0) =
       PTR__glVertex2f_Exec_00113778;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x4e4) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x4e4) =
       PTR__glVertex2fv_Exec_00113774;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x4e8) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x4e8) =
       PTR__glVertex2i_Exec_00113770;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x4ec) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x4ec) =
       PTR__glVertex2iv_Exec_0011376c;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x4f0) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x4f0) =
       PTR__glVertex2s_Exec_00113768;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x4f4) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x4f4) =
       PTR__glVertex2sv_Exec_00113764;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x4f8) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x4f8) =
       PTR__glVertex3d_Exec_00113760;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x4fc) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x4fc) =
       PTR__glVertex3dv_Exec_0011375c;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x500) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x500) =
       PTR__glVertex3f_Exec_00113758;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x504) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x504) =
       PTR__glVertex3fv_Exec_00113754;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x508) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x508) =
       PTR__glVertex3i_Exec_00113750;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x50c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x50c) =
       PTR__glVertex3iv_Exec_0011374c;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x510) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x510) =
       PTR__glVertex3s_Exec_00113748;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x514) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x514) =
       PTR__glVertex3sv_Exec_00113744;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x518) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x518) =
       PTR__glVertex4d_Exec_00113740;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x51c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x51c) =
       PTR__glVertex4dv_Exec_0011373c;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x520) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x520) =
       PTR__glVertex4f_Exec_00113738;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x524) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x524) =
       PTR__glVertex4fv_Exec_00113734;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x528) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x528) =
       PTR__glVertex4i_Exec_00113730;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x52c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x52c) =
       PTR__glVertex4iv_Exec_0011372c;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x530) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x530) =
       PTR__glVertex4s_Exec_00113728;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x534) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x534) =
       PTR__glVertex4sv_Exec_00113724;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x53c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x53c) =
       PTR__glViewport_Exec_00113720;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x544) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x544) =
       PTR__glBlendColor_Exec_0011371c;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x548) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x548) =
       PTR__glBlendEquation_Exec_00113718;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x558) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x558) =
       PTR__glActiveTexture_Exec_00113714;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x55c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x55c) =
       PTR__glMultiTexCoord1d_Exec_00113710;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x560) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x560) =
       PTR__glMultiTexCoord1dv_Exec_0011370c;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x564) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x564) =
       PTR__glMultiTexCoord1f_Exec_00113708;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x568) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x568) =
       PTR__glMultiTexCoord1fv_Exec_00113704;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x56c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x56c) =
       PTR__glMultiTexCoord1i_Exec_00113700;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x570) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x570) =
       PTR__glMultiTexCoord1iv_Exec_001136fc;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x574) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x574) =
       PTR__glMultiTexCoord1s_Exec_001136f8;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x578) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x578) =
       PTR__glMultiTexCoord1sv_Exec_001136f4;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x57c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x57c) =
       PTR__glMultiTexCoord2d_Exec_001136f0;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x580) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x580) =
       PTR__glMultiTexCoord2dv_Exec_001136ec;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x584) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x584) =
       PTR__glMultiTexCoord2f_Exec_001136e8;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x588) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x588) =
       PTR__glMultiTexCoord2fv_Exec_001136e4;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x58c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x58c) =
       PTR__glMultiTexCoord2i_Exec_001136e0;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x590) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x590) =
       PTR__glMultiTexCoord2iv_Exec_001136dc;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x594) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x594) =
       PTR__glMultiTexCoord2s_Exec_001136d8;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x598) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x598) =
       PTR__glMultiTexCoord2sv_Exec_001136d4;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x59c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x59c) =
       PTR__glMultiTexCoord3d_Exec_001136d0;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x5a0) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x5a0) =
       PTR__glMultiTexCoord3dv_Exec_001136cc;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x5a4) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x5a4) =
       PTR__glMultiTexCoord3f_Exec_001136c8;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x5a8) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x5a8) =
       PTR__glMultiTexCoord3fv_Exec_001136c4;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x5ac) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x5ac) =
       PTR__glMultiTexCoord3i_Exec_001136c0;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x5b0) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x5b0) =
       PTR__glMultiTexCoord3iv_Exec_001136bc;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x5b4) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x5b4) =
       PTR__glMultiTexCoord3s_Exec_001136b8;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x5b8) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x5b8) =
       PTR__glMultiTexCoord3sv_Exec_001136b4;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x5bc) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x5bc) =
       PTR__glMultiTexCoord4d_Exec_001136b0;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x5c0) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x5c0) =
       PTR__glMultiTexCoord4dv_Exec_001136ac;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x5c4) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x5c4) =
       PTR__glMultiTexCoord4f_Exec_001136a8;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x5c8) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x5c8) =
       PTR__glMultiTexCoord4fv_Exec_001136a4;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x5cc) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x5cc) =
       PTR__glMultiTexCoord4i_Exec_001136a0;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x5d0) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x5d0) =
       PTR__glMultiTexCoord4iv_Exec_0011369c;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x5d4) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x5d4) =
       PTR__glMultiTexCoord4s_Exec_00113698;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x5d8) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x5d8) =
       PTR__glMultiTexCoord4sv_Exec_00113694;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x5dc) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x5dc) =
       PTR__glLoadTransposeMatrixd_Exec_00113690;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x5e0) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x5e0) =
       PTR__glLoadTransposeMatrixf_Exec_0011368c;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x5e4) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x5e4) =
       PTR__glMultTransposeMatrixd_Exec_00113688;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x5e8) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x5e8) =
       PTR__glMultTransposeMatrixf_Exec_00113684;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x654) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x654) =
       PTR__glDrawRangeElements_Exec_001120dc;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x6d8) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x6d8) =
       PTR__glTexImage3D_Exec_00113680;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x6dc) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x6dc) =
       PTR__glTexSubImage3D_Exec_0011367c;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x6e0) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x6e0) =
       PTR__glCopyTexSubImage3D_Exec_00112084;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x658) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x658) =
       PTR__glColorTable_Exec_00113678;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x65c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x65c) =
       PTR__glColorTableParameterfv_Exec_00113674;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x660) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x660) =
       PTR__glColorTableParameteriv_Exec_00113670;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x664) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x664) =
       PTR__glCopyColorTable_Exec_0011366c;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x674) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x674) =
       PTR__glColorSubTable_Exec_00113668;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x678) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x678) =
       PTR__glCopyColorSubTable_Exec_00113664;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x67c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x67c) =
       PTR__glConvolutionFilter1D_Exec_00113660;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x680) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x680) =
       PTR__glConvolutionFilter2D_Exec_0011365c;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x684) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x684) =
       PTR__glConvolutionParameterf_Exec_00113658;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x688) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x688) =
       PTR__glConvolutionParameterfv_Exec_00113654;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x68c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x68c) =
       PTR__glConvolutionParameteri_Exec_00113650;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x690) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x690) =
       PTR__glConvolutionParameteriv_Exec_0011364c;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x694) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x694) =
       PTR__glCopyConvolutionFilter1D_Exec_00113648;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x698) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x698) =
       PTR__glCopyConvolutionFilter2D_Exec_00113644;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x6ac) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x6ac) =
       PTR__glSeparableFilter2D_Exec_00113640;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x6c8) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x6c8) =
       PTR__glHistogram_Exec_0011363c;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x6cc) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x6cc) =
       PTR__glMinmax_Exec_00113638;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x6d0) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x6d0) =
       PTR__glResetHistogram_Exec_00113634;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x6d4) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x6d4) =
       PTR__glResetMinmax_Exec_00113630;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x5ec) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x5ec) =
       PTR__glCompressedTexImage3D_Exec_0011362c;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x5f0) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x5f0) =
       PTR__glCompressedTexImage2D_Exec_00113628;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x5f4) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x5f4) =
       PTR__glCompressedTexImage1D_Exec_00113624;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x5f8) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x5f8) =
       PTR__glCompressedTexSubImage3D_Exec_00113620;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x5fc) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x5fc) =
       PTR__glCompressedTexSubImage2D_Exec_0011361c;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x600) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x600) =
       PTR__glCompressedTexSubImage1D_Exec_00113618;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x608) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x608) =
       PTR__glSecondaryColor3b_Exec_00113614;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x60c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x60c) =
       PTR__glSecondaryColor3bv_Exec_00113610;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x610) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x610) =
       PTR__glSecondaryColor3d_Exec_0011360c;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x614) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x614) =
       PTR__glSecondaryColor3dv_Exec_00113608;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x618) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x618) =
       PTR__glSecondaryColor3f_Exec_00113604;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x61c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x61c) =
       PTR__glSecondaryColor3fv_Exec_00113600;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x620) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x620) =
       PTR__glSecondaryColor3i_Exec_001135fc;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x624) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x624) =
       PTR__glSecondaryColor3iv_Exec_001135f8;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x628) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x628) =
       PTR__glSecondaryColor3s_Exec_001135f4;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x62c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x62c) =
       PTR__glSecondaryColor3sv_Exec_001135f0;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x630) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x630) =
       PTR__glSecondaryColor3ub_Exec_001135ec;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x634) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x634) =
       PTR__glSecondaryColor3ubv_Exec_001135e8;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x638) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x638) =
       PTR__glSecondaryColor3ui_Exec_001135e4;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x63c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x63c) =
       PTR__glSecondaryColor3uiv_Exec_001135e0;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x640) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x640) =
       PTR__glSecondaryColor3us_Exec_001135dc;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x644) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x644) =
       PTR__glSecondaryColor3usv_Exec_001135d8;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x72c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x72c) =
       PTR__glSampleCoverage_Exec_001135d4;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x730) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x730) =
       PTR__glSamplePass_Exec_001135d0;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x8e4) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x8e4) =
       PTR__glWindowPos2d_Exec_001135cc;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x8e8) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x8e8) =
       PTR__glWindowPos2dv_Exec_001135c8;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x8ec) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x8ec) =
       PTR__glWindowPos2f_Exec_001135c4;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x8f0) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x8f0) =
       PTR__glWindowPos2fv_Exec_001135c0;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x8f4) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x8f4) =
       PTR__glWindowPos2i_Exec_001135bc;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x8f8) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x8f8) =
       PTR__glWindowPos2iv_Exec_001135b8;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x8fc) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x8fc) =
       PTR__glWindowPos2s_Exec_001135b4;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x900) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x900) =
       PTR__glWindowPos2sv_Exec_001135b0;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x904) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x904) =
       PTR__glWindowPos3d_Exec_001135ac;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x908) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x908) =
       PTR__glWindowPos3dv_Exec_001135a8;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x90c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x90c) =
       PTR__glWindowPos3f_Exec_001135a4;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x910) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x910) =
       PTR__glWindowPos3fv_Exec_001135a0;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x914) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x914) =
       PTR__glWindowPos3i_Exec_0011359c;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x918) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x918) =
       PTR__glWindowPos3iv_Exec_00113598;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x91c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x91c) =
       PTR__glWindowPos3s_Exec_00113594;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x920) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x920) =
       PTR__glWindowPos3sv_Exec_00113590;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x894) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x894) =
       PTR__glVertexArrayParameteriEXT_Exec_0011358c;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x6e4) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x6e4) =
       PTR__glCombinerParameterfvNV_Exec_00113588;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x6e8) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x6e8) =
       PTR__glCombinerParameterfNV_Exec_00113584;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x6ec) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x6ec) =
       PTR__glCombinerParameterivNV_Exec_00113580;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x6f0) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x6f0) =
       PTR__glCombinerParameteriNV_Exec_0011357c;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x6f4) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x6f4) =
       PTR__glCombinerInputNV_Exec_00113578;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x6f8) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x6f8) =
       PTR__glCombinerOutputNV_Exec_00113574;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x6fc) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x6fc) =
       PTR__glFinalCombinerInputNV_Exec_00113570;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x718) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x718) =
       PTR__glCombinerStageParameterfvNV_Exec_0011356c;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x738) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x738) =
       PTR__glPNTrianglesfATIX_Exec_00113568;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x734) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x734) =
       PTR__glPNTrianglesiATIX_Exec_00113564;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x75c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x75c) =
       PTR__glBindProgramARB_Exec_00113560;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x76c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x76c) =
       PTR__glVertexAttrib1sARB_Exec_0011355c;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x770) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x770) =
       PTR__glVertexAttrib1fARB_Exec_00113558;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x774) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x774) =
       PTR__glVertexAttrib1dARB_Exec_00113554;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x778) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x778) =
       PTR__glVertexAttrib2sARB_Exec_00113550;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x77c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x77c) =
       PTR__glVertexAttrib2fARB_Exec_0011354c;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x780) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x780) =
       PTR__glVertexAttrib2dARB_Exec_00113548;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x784) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x784) =
       PTR__glVertexAttrib3sARB_Exec_00113544;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x788) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x788) =
       PTR__glVertexAttrib3fARB_Exec_00113540;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x78c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x78c) =
       PTR__glVertexAttrib3dARB_Exec_0011353c;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x790) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x790) =
       PTR__glVertexAttrib4sARB_Exec_00113538;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x794) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x794) =
       PTR__glVertexAttrib4fARB_Exec_00113534;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x798) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x798) =
       PTR__glVertexAttrib4dARB_Exec_00113530;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x79c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x79c) =
       PTR__glVertexAttrib4NubARB_Exec_0011352c;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x7a0) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x7a0) =
       PTR__glVertexAttrib1svARB_Exec_00113528;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x7a4) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x7a4) =
       PTR__glVertexAttrib1fvARB_Exec_00113524;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x7a8) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x7a8) =
       PTR__glVertexAttrib1dvARB_Exec_00113520;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x7ac) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x7ac) =
       PTR__glVertexAttrib2svARB_Exec_0011351c;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x7b0) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x7b0) =
       PTR__glVertexAttrib2fvARB_Exec_00113518;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x7b4) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x7b4) =
       PTR__glVertexAttrib2dvARB_Exec_00113514;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x7b8) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x7b8) =
       PTR__glVertexAttrib3svARB_Exec_00113510;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x7bc) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x7bc) =
       PTR__glVertexAttrib3fvARB_Exec_0011350c;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x7c0) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x7c0) =
       PTR__glVertexAttrib3dvARB_Exec_00113508;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x7c4) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x7c4) =
       PTR__glVertexAttrib4bvARB_Exec_00113504;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x7c8) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x7c8) =
       PTR__glVertexAttrib4svARB_Exec_00113500;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x7cc) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x7cc) =
       PTR__glVertexAttrib4ivARB_Exec_001134fc;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 2000) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 2000) =
       PTR__glVertexAttrib4ubvARB_Exec_001134f8;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x7d4) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x7d4) =
       PTR__glVertexAttrib4usvARB_Exec_001134f4;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x7d8) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x7d8) =
       PTR__glVertexAttrib4uivARB_Exec_001134f0;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x7dc) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x7dc) =
       PTR__glVertexAttrib4fvARB_Exec_001134ec;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x7e0) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x7e0) =
       PTR__glVertexAttrib4dvARB_Exec_001134e8;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x7e4) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x7e4) =
       PTR__glVertexAttrib4NbvARB_Exec_001134e4;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x7e8) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x7e8) =
       PTR__glVertexAttrib4NsvARB_Exec_001134e0;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x7ec) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x7ec) =
       PTR__glVertexAttrib4NivARB_Exec_001134dc;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x7f0) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x7f0) =
       PTR__glVertexAttrib4NubvARB_Exec_001134d8;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x7f4) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x7f4) =
       PTR__glVertexAttrib4NusvARB_Exec_001134d4;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x7f8) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x7f8) =
       PTR__glVertexAttrib4NuivARB_Exec_001134d0;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x818) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x818) =
       PTR__glProgramEnvParameter4dARB_Exec_001134cc;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x81c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x81c) =
       PTR__glProgramEnvParameter4dvARB_Exec_001134c8;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x820) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x820) =
       PTR__glProgramEnvParameter4fARB_Exec_001134c4;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x824) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x824) =
       PTR__glProgramEnvParameter4fvARB_Exec_001134c0;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x828) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x828) =
       PTR__glProgramLocalParameter4dARB_Exec_001134bc;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x82c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x82c) =
       PTR__glProgramLocalParameter4dvARB_Exec_001134b8;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x830) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x830) =
       PTR__glProgramLocalParameter4fARB_Exec_001134b4;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x834) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x834) =
       PTR__glProgramLocalParameter4fvARB_Exec_001134b0;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x848) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x848) =
       PTR__glProgramStringARB_Exec_001134ac;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x854) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x854) =
       PTR__glEnableVertexAttribARB_Exec_001134a8;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x858) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x858) =
       PTR__glDisableVertexAttribARB_Exec_001134a4;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x860) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x860) =
       PTR__glMapVertexAttrib1dARB_Exec_001134a0;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x864) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x864) =
       PTR__glMapVertexAttrib1fARB_Exec_0011349c;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x868) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x868) =
       PTR__glMapVertexAttrib2dARB_Exec_00113498;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x86c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x86c) =
       PTR__glMapVertexAttrib2fARB_Exec_00113494;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x744) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x744) =
       PTR__glSetFenceAPPLE_Exec_00113490;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x750) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x750) =
       PTR__glFinishFenceAPPLE_Exec_0011348c;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x758) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x758) =
       PTR__glFinishObjectAPPLE_Exec_00113488;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x870) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x870) =
       PTR__glPointParameterf_Exec_00113484;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x874) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x874) =
       PTR__glPointParameterfv_Exec_00113480;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x878) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x878) =
       PTR__glPointParameteriARB_Exec_0011347c;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x87c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x87c) =
       PTR__glPointParameterivARB_Exec_00113478;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x880) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x880) =
       PTR__glFogCoordf_Exec_00113474;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x884) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x884) =
       PTR__glFogCoordfv_Exec_00113470;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x888) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x888) =
       PTR__glFogCoordd_Exec_0011346c;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x88c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x88c) =
       PTR__glFogCoorddv_Exec_00113468;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x898) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x898) =
       PTR__glBindVertexArrayEXT_Exec_00113464;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x8ac) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x8ac) =
       PTR__glDrawElementArrayAPPLE_Exec_001120cc;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x8b0) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x8b0) =
       PTR__glDrawRangeElementArrayAPPLE_Exec_001120d0;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0xa5c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0xa5c) =
       PTR__glMultiDrawElementArrayAPPLE_Exec_001120c4;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0xa60) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0xa60) =
       PTR__glMultiDrawRangeElementArrayAPPLE_Exec_001120c8;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x540) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x540) =
       PTR__glBlendFuncSeparate_Exec_00113460;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x728) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x728) =
       PTR__glBlendEquationSeparateEXT_Exec_0011345c;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x8dc) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x8dc) =
       PTR__glMultiDrawArrays_Exec_001120d8;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x8e0) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x8e0) =
       PTR__glMultiDrawElements_Exec_001120d4;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x8b4) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x8b4) =
       PTR__glWeightbvARB_Exec_00113458;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x8b8) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x8b8) =
       PTR__glWeightsvARB_Exec_00113454;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x8bc) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x8bc) =
       PTR__glWeightivARB_Exec_00113450;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x8c0) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x8c0) =
       PTR__glWeightfvARB_Exec_0011344c;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x8c4) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x8c4) =
       PTR__glWeightdvARB_Exec_00113448;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x8c8) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x8c8) =
       PTR__glWeightubvARB_Exec_00113444;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x8cc) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x8cc) =
       PTR__glWeightusvARB_Exec_00113440;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x8d0) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x8d0) =
       PTR__glWeightuivARB_Exec_0011343c;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x8d8) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x8d8) =
       PTR__glVertexBlendARB_Exec_00113438;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x924) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x924) =
       PTR__glActiveStencilFace_Exec_00113434;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x928) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x928) =
       PTR__glStencilOpSeparateATI_Exec_00113430;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x92c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x92c) =
       PTR__glStencilFuncSeparateATI_Exec_0011342c;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x960) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x960) =
       PTR__glUseProgramObjectARB_Exec_00113428;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x968) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x968) =
       PTR__glUniform1fARB_Exec_00113424;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x96c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x96c) =
       PTR__glUniform2fARB_Exec_00113420;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x970) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x970) =
       PTR__glUniform3fARB_Exec_0011341c;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x974) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x974) =
       PTR__glUniform4fARB_Exec_00113418;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x978) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x978) =
       PTR__glUniform1iARB_Exec_00113414;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x97c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x97c) =
       PTR__glUniform2iARB_Exec_00113410;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x980) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x980) =
       PTR__glUniform3iARB_Exec_0011340c;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x984) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x984) =
       PTR__glUniform4iARB_Exec_00113408;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x988) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x988) =
       PTR__glUniform1fvARB_Exec_00113404;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x98c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x98c) =
       PTR__glUniform2fvARB_Exec_00113400;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x990) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x990) =
       PTR__glUniform3fvARB_Exec_001133fc;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x994) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x994) =
       PTR__glUniform4fvARB_Exec_001133f8;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x998) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x998) =
       PTR__glUniform1ivARB_Exec_001133f4;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x99c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x99c) =
       PTR__glUniform2ivARB_Exec_001133f0;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x9a0) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x9a0) =
       PTR__glUniform3ivARB_Exec_001133ec;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x9a4) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x9a4) =
       PTR__glUniform4ivARB_Exec_001133e8;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x9a8) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x9a8) =
       PTR__glUniformMatrix2fvARB_Exec_001133e4;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x9ac) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x9ac) =
       PTR__glUniformMatrix3fvARB_Exec_001133e0;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x9b0) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x9b0) =
       PTR__glUniformMatrix4fvARB_Exec_001133dc;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x9f4) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x9f4) =
       PTR__glBeginQuery_Exec_001133d8;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x9f8) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x9f8) =
       PTR__glEndQuery_Exec_001133d4;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0xa34) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0xa34) =
       PTR__glDepthBoundsEXT_Exec_001133d0;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0xa38) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0xa38) =
       PTR__glDrawBuffersARB_Exec_00113ba0;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0xa3c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0xa3c) =
       PTR__glIsShader_Exec_00113b9c;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0xa40) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0xa40) =
       PTR__glIsProgram_Exec_00113b98;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0xa44) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0xa44) =
       PTR__glGetShaderiv_Exec_00113b94;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0xa48) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0xa48) =
       PTR__glGetProgramiv_Exec_00113b90;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0xa4c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0xa4c) =
       PTR__glGetShaderInfoLog_Exec_00113b8c;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0xa50) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0xa50) =
       PTR__glGetProgramInfoLog_Exec_00113b88;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0xa54) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0xa54) =
       PTR__glStencilFuncSeparate_Exec_00113b84;
  uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0xa58) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0xa58) =
       PTR__glStencilMaskSeparate_Exec_00113b80;
  if ((*(char *)(param_1 + 0x759c) == '\0') || (*(char *)(param_1 + 0x759d) == '\0')) {
    uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x104) == 0);
    *(undefined **)
     ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x104) =
         PTR__glDrawArrays_NoopExec_0011210c;
    uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x10c) == 0);
    *(undefined **)
     ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x10c) =
         PTR__glDrawElements_NoopExec_00112108;
    uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x654) == 0);
    *(undefined **)
     ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x654) =
         PTR__glDrawRangeElements_NoopExec_00112104;
    uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x8dc) == 0);
    *(undefined **)
     ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x8dc) =
         PTR__glMultiDrawArrays_NoopExec_00112100;
    uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x8e0) == 0);
    *(undefined **)
     ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x8e0) =
         PTR__glMultiDrawElements_NoopExec_001120fc;
    uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x8b0) == 0);
    *(undefined **)
     ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x8b0) =
         PTR__glDrawRangeElementArrayAPPLE_NoopExec_001120f8;
    uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x8ac) == 0);
    *(undefined **)
     ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x8ac) =
         PTR__glDrawElementArrayAPPLE_NoopExec_001120f4;
    uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0xa60) == 0);
    *(undefined **)
     ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0xa60) =
         PTR__glMultiDrawRangeElementArrayAPPLE_NoopExec_001120f0;
    uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0xa5c) == 0);
    *(undefined **)
     ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0xa5c) =
         PTR__glMultiDrawElementArrayAPPLE_NoopExec_001120ec;
  }
  else {
    uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x104) == 0);
    *(undefined **)
     ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x104) =
         PTR__glDrawArrays_Exec_001120e4;
    uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x10c) == 0);
    *(undefined **)
     ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x10c) =
         PTR__glDrawElements_Exec_001120e0;
    uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x654) == 0);
    *(undefined **)
     ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x654) =
         PTR__glDrawRangeElements_Exec_001120dc;
    uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x8dc) == 0);
    *(undefined **)
     ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x8dc) =
         PTR__glMultiDrawArrays_Exec_001120d8;
    uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x8e0) == 0);
    *(undefined **)
     ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x8e0) =
         PTR__glMultiDrawElements_Exec_001120d4;
    uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x8b0) == 0);
    *(undefined **)
     ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x8b0) =
         PTR__glDrawRangeElementArrayAPPLE_Exec_001120d0;
    uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x8ac) == 0);
    *(undefined **)
     ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x8ac) =
         PTR__glDrawElementArrayAPPLE_Exec_001120cc;
    uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0xa60) == 0);
    *(undefined **)
     ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0xa60) =
         PTR__glMultiDrawRangeElementArrayAPPLE_Exec_001120c8;
    uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0xa5c) == 0);
    *(undefined **)
     ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0xa5c) =
         PTR__glMultiDrawElementArrayAPPLE_Exec_001120c4;
  }
  return;
}

/* _glGetString_Exec @ 0x11bc0 (1596 bytes) */
int _glGetString_Exec(param_1, param_2)
  int param_1;
  uint param_2;
{
  bool bVar1;
  char cVar2;
  undefined4 uVar3;
  undefined **ppuVar4;
  char *pcVar5;
  size_t sVar6;
  char *pcVar7;
  uint uVar8;
  
  if (-1 < *(short *)(param_1 + 0x4a10)) {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return (char *)0x0;
    }
    uVar3 = 0x502;
    goto LAB_0001231c;
  }
  if (param_2 == 0x1f03) {
    ppuVar4 = &_engine_extensions;
    pcVar7 = (char *)(param_1 + 0x759e);
    do {
      pcVar5 = *ppuVar4;
      ppuVar4 = ppuVar4 + 1;
      cVar2 = *pcVar5;
      while (cVar2 != '\0') {
        *pcVar7 = cVar2;
        pcVar7 = pcVar7 + 1;
        pcVar5 = pcVar5 + 1;
        cVar2 = *pcVar5;
      }
      *pcVar7 = ' ';
      pcVar7 = pcVar7 + 1;
    } while ((int)ppuVar4 < 0x110389);
    uVar8 = 0;
    do {
      if ((*(uint *)(((int)uVar8 >> 5) * 4 + *(int *)(param_1 + 0x468c) + 0x124) >> (uVar8 & 0x1f) &
          1) != 0) {
        pcVar5 = (char *)0x0;
        switch(uVar8) {
        case 0:
          pcVar5 = "GL_ARB_imaging";
          break;
        case 1:
          pcVar5 = "GL_ARB_point_parameters";
          break;
        case 2:
          pcVar5 = "GL_ARB_texture_env_crossbar";
          break;
        case 3:
          pcVar5 = "GL_ARB_texture_border_clamp";
          break;
        case 4:
          pcVar5 = "GL_ARB_multitexture";
          break;
        case 5:
          pcVar5 = "GL_ARB_texture_env_add";
          break;
        case 6:
          pcVar5 = "GL_ARB_texture_cube_map";
          break;
        case 7:
          pcVar5 = "GL_ARB_texture_env_dot3";
          break;
        case 8:
          pcVar5 = "GL_ARB_multisample";
          break;
        case 9:
          pcVar5 = "GL_ARB_texture_env_combine";
          break;
        case 10:
          pcVar5 = "GL_ARB_texture_compression";
          break;
        case 0xb:
          pcVar5 = "GL_ARB_texture_mirrored_repeat";
          break;
        case 0xc:
          pcVar5 = "GL_ARB_shadow";
          break;
        case 0xd:
          pcVar5 = "GL_ARB_depth_texture";
          break;
        case 0xe:
          pcVar5 = "GL_ARB_shadow_ambient";
          break;
        case 0xf:
          pcVar5 = "GL_ARB_fragment_program";
          break;
        case 0x10:
          pcVar5 = "GL_ARB_fragment_shader";
          break;
        case 0x11:
          pcVar5 = "GL_ARB_occlusion_query";
          break;
        case 0x12:
          pcVar5 = "GL_ARB_point_sprite";
          break;
        case 0x13:
          pcVar5 = "GL_ARB_texture_non_power_of_two";
          break;
        case 0x14:
          if (*(char *)(param_1 + 0x7584) != '\0') goto LAB_000122ec;
          pcVar5 = "GL_ARB_vertex_buffer_object";
          break;
        case 0x15:
          pcVar5 = "GL_ARB_pixel_buffer_object";
          break;
        case 0x16:
          pcVar5 = "GL_ARB_draw_buffers";
          break;
        case 0x17:
          pcVar5 = "GL_EXT_compiled_vertex_array";
          break;
        case 0x18:
          pcVar5 = "GL_EXT_framebuffer_object";
          break;
        case 0x19:
          pcVar5 = "GL_EXT_texture_rectangle GL_ARB_texture_rectangle";
          break;
        case 0x1a:
          pcVar5 = "GL_EXT_texture_env_add";
          break;
        case 0x1b:
          pcVar5 = "GL_EXT_blend_color";
          break;
        case 0x1c:
          pcVar5 = "GL_EXT_blend_minmax";
          break;
        case 0x1d:
          pcVar5 = "GL_EXT_blend_subtract";
          break;
        case 0x1e:
          pcVar5 = "GL_EXT_texture_lod_bias";
          break;
        case 0x1f:
          pcVar5 = "GL_EXT_abgr";
          break;
        case 0x20:
          pcVar5 = "GL_EXT_bgra";
          break;
        case 0x21:
          pcVar5 = "GL_EXT_stencil_wrap";
          break;
        case 0x22:
          pcVar5 = "GL_EXT_texture_filter_anisotropic";
          break;
        case 0x23:
          pcVar5 = "GL_EXT_paletted_texture";
          break;
        case 0x24:
          pcVar5 = "GL_EXT_shared_texture_palette";
          break;
        case 0x25:
          pcVar5 = "GL_EXT_separate_specular_color";
          break;
        case 0x26:
          pcVar5 = "GL_EXT_secondary_color";
          break;
        case 0x27:
          pcVar5 = "GL_EXT_blend_func_separate";
          break;
        case 0x28:
          pcVar5 = "GL_EXT_shadow_funcs";
          break;
        case 0x29:
          pcVar5 = "GL_EXT_stencil_two_side";
          break;
        case 0x2a:
          pcVar5 = "GL_EXT_depth_bounds_test";
          break;
        case 0x2b:
          pcVar5 = "GL_EXT_texture_compression_s3tc GL_EXT_texture_compression_dxt1";
          break;
        case 0x2c:
          pcVar5 = "GL_EXT_blend_equation_separate";
          break;
        case 0x2d:
          pcVar5 = "GL_EXT_texture_mirror_clamp";
          break;
        case 0x2e:
          pcVar5 = "GL_APPLE_ycbcr_422";
          break;
        case 0x2f:
          pcVar5 = "GL_APPLE_vertex_array_range";
          break;
        case 0x30:
          pcVar5 = "GL_APPLE_texture_range";
          break;
        case 0x31:
          pcVar5 = "GL_APPLE_float_pixels GL_ATI_texture_float";
          break;
        case 0x32:
          pcVar5 = "GL_APPLE_pixel_buffer";
          break;
        case 0x33:
          pcVar5 = "GL_NV_point_sprite";
          break;
        case 0x34:
          pcVar5 = "GL_NV_register_combiners";
          break;
        case 0x35:
          pcVar5 = "GL_NV_register_combiners2";
          break;
        case 0x36:
          pcVar5 = "GL_NV_blend_square";
          break;
        case 0x37:
          pcVar5 = "GL_NV_texture_shader";
          break;
        case 0x38:
          pcVar5 = "GL_NV_texture_shader2";
          break;
        case 0x39:
          pcVar5 = "GL_NV_texture_shader3";
          break;
        case 0x3a:
          pcVar5 = "GL_NV_fog_distance";
          break;
        case 0x3b:
          pcVar5 = "GL_NV_depth_clamp";
          break;
        case 0x3c:
          pcVar5 = "GL_NV_multisample_filter_hint";
          break;
        case 0x3d:
          pcVar5 = "GL_NV_fragment_program_option";
          break;
        case 0x3e:
          pcVar5 = "GL_NV_fragment_program2";
          break;
        case 0x3f:
          pcVar5 = "GL_NV_vertex_program2_option";
          break;
        case 0x40:
          pcVar5 = "GL_NV_vertex_program3";
          break;
        case 0x41:
          pcVar5 = "GL_ATI_point_cull_mode";
          break;
        case 0x42:
          pcVar5 = "GL_ATI_texture_mirror_once";
          break;
        case 0x43:
          pcVar5 = "GL_ATI_text_fragment_shader";
          break;
        case 0x44:
          pcVar5 = "GL_ATI_blend_equation_separate";
          break;
        case 0x45:
          pcVar5 = "GL_ATI_blend_weighted_minmax";
          break;
        case 0x46:
          pcVar5 = "GL_ATI_texture_env_combine3";
          break;
        case 0x47:
          pcVar5 = "GL_ATI_separate_stencil";
          break;
        case 0x48:
          pcVar5 = "GL_ATI_array_rev_comps_in_4_bytes";
          break;
        case 0x49:
          pcVar5 = "GL_ATI_pn_triangles";
          break;
        case 0x4a:
          pcVar5 = "GL_ATI_texture_compression_3dc";
          break;
        case 0x4b:
          pcVar5 = "GL_ATIX_pn_triangles";
          break;
        case 0x4c:
          pcVar5 = "GL_SGIS_texture_edge_clamp";
          break;
        case 0x4d:
          pcVar5 = "GL_SGIS_texture_lod";
          break;
        case 0x4e:
          pcVar5 = "GL_SGI_color_matrix";
        }
        if (pcVar5 != (char *)0x0) {
          cVar2 = *pcVar5;
          while (cVar2 != '\0') {
            *pcVar7 = cVar2;
            pcVar7 = pcVar7 + 1;
            pcVar5 = pcVar5 + 1;
            cVar2 = *pcVar5;
          }
          *pcVar7 = ' ';
          pcVar7 = pcVar7 + 1;
        }
      }
LAB_000122ec:
      uVar8 = uVar8 + 1;
      if (0x4e < (int)uVar8) {
        *pcVar7 = '\0';
        return (char *)(param_1 + 0x759e);
      }
    } while( true );
  }
  if (param_2 < 0x1f04) {
    if (param_2 == 0x1f01) {
      if (*(char *)(param_1 + 0x7585) != '\0') {
        pcVar7 = (char *)(**(code **)(param_1 + 0x47bc))(*(undefined4 *)(param_1 + 0x4688));
        if (*(short *)((uint)*(byte *)(param_1 + 0x85a8) * 0x2e0 + param_1 + 0x888a) == 0x2402) {
          return pcVar7;
        }
        pcVar5 = _strstr(pcVar7,"FX");
        if (pcVar5 != (char *)0x0) {
          sVar6 = _strlen(pcVar7);
          _memcpy(&_new_rend_str_0,pcVar7,sVar6);
          (DAT_00113e61)[(int)pcVar5 - (int)pcVar7] = 0x78;
          return &_new_rend_str_0;
        }
        return pcVar7;
      }
      goto LAB_00011cf8;
    }
    if (0x1f01 < param_2) goto LAB_00011cf8;
    bVar1 = param_2 == 0x1f00;
LAB_00011c44:
    if (bVar1) {
LAB_00011cf8:
      pcVar7 = (char *)(**(code **)(param_1 + 0x47bc))(*(undefined4 *)(param_1 + 0x4688),param_2);
      return pcVar7;
    }
  }
  else {
    if (param_2 == 0x8874) {
      return *(char **)(param_1 + 0x5418);
    }
    if (param_2 < 0x8875) {
      bVar1 = param_2 == 0x1f04;
      goto LAB_00011c44;
    }
    if (param_2 == 0x8b8c) {
      return "1.10";
    }
  }
  if (*(int *)(param_1 + 0x7574) != 0) {
    return (char *)0x0;
  }
  uVar3 = 0x500;
LAB_0001231c:
  *(undefined4 *)(param_1 + 0x7574) = uVar3;
  return (char *)0x0;
}

/* _glGenFencesAPPLE_Exec @ 0x12338 (164 bytes) */
int _glGenFencesAPPLE_Exec(param_1, param_2, param_3)
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
      iVar4 = ((int (*)())_gleGenHashNames)(param_1 + 0x543c,param_2);
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

/* _gleGenHashNames @ 0x123dc (304 bytes) */
int _gleGenHashNames(param_1, param_2)
  int param_1;
  uint param_2;
{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  int iVar5;
  uint uVar6;
  undefined4 *puVar7;
  
  uVar1 = 0;
  puVar7 = *(undefined4 **)(param_1 + 0x1000);
  if (param_2 != 0) {
    if (puVar7 == (undefined4 *)0x0) {
      puVar7 = _malloc(0xc);
      *puVar7 = 0;
      puVar7[1] = 1;
      puVar7[2] = param_2;
      *(undefined4 **)(param_1 + 0x1000) = puVar7;
    }
    else {
      uVar1 = puVar7[1];
      if (uVar1 != param_2 + 1) {
        if (param_2 < uVar1) {
          puVar4 = _malloc(0xc);
          *(undefined4 **)(param_1 + 0x1000) = puVar4;
          *puVar4 = puVar7;
          puVar4[1] = 1;
          puVar4[2] = param_2;
          return 1;
        }
        while( true ) {
          puVar4 = puVar7;
          iVar5 = puVar4[2];
          puVar7 = (undefined4 *)*puVar4;
          uVar6 = uVar1 + iVar5;
          uVar3 = uVar6 + param_2;
          if (uVar3 < uVar6) {
            return 0;
          }
          if ((puVar7 == (undefined4 *)0x0) || (uVar1 = puVar7[1], uVar3 < uVar1)) break;
          if (uVar3 == uVar1) {
            iVar2 = puVar7[2];
            *puVar4 = *puVar7;
            puVar4[2] = iVar5 + param_2 + iVar2;
            _free(puVar7);
            return uVar6;
          }
        }
        puVar4[2] = iVar5 + param_2;
        return uVar6;
      }
      puVar7[1] = 1;
      puVar7[2] = puVar7[2] + param_2;
    }
    uVar1 = 1;
  }
  return uVar1;
}

/* _gliAttachDrawableWithOptions @ 0x1250c (656 bytes) */
int _gliAttachDrawableWithOptions(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int param_2;
  int param_3;
  uint param_4;
  undefined4 param_5;
{
  bool bVar1;
  int iVar2;
  undefined1 uVar3;
  int iVar4;
  char cVar5;
  uint uVar6;
  uint uVar7;
  double extraout_f1;
  double fparam_1;
  double in_f2;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  double in_stack_ffffff98;
  double in_stack_ffffffa0;
  double in_stack_ffffffa8;
  double in_stack_ffffffb0;
  double in_stack_ffffffb8;
  
  iVar2 = -(uint)(*(byte *)(param_1 + 0x85a8) ^ *(byte *)(param_1 + 0x85a6));
  bVar1 = false;
  if ((param_1 == 0) || (*(int *)(param_1 + 0x467c) != 0x3463a223)) {
    return 0x2714;
  }
  if ((param_2 == 0) != (param_3 == 0)) {
    return 0x2715;
  }
  if (((int)param_4 < 0) || ((int)(uint)*(byte *)(param_1 + 0x85a4) <= (int)param_4)) {
    return 0x2718;
  }
  *(char *)(param_1 + 0x85a6) = (char)param_4;
  *(undefined1 *)(param_1 + 0x85a7) = 0;
  iVar4 = param_4 * 0x2e0 + param_1;
  uVar6 = (**(code **)(*(int *)(iVar4 + 0x8884) + 0x138))
                    (*(undefined4 *)(iVar4 + 0x85ac),param_2,param_3,param_5);
  fparam_1 = extraout_f1;
  if ((uVar6 < 5) && (param_4 != *(byte *)(param_1 + 0x85a8))) {
    fparam_1 = (double)_gliSwitchPlugin(param_1,param_4);
    bVar1 = true;
    uVar6 = 2;
  }
  if (uVar6 == 2) {
    ((void (*)())_gliUpdatePluginConfig)(param_1,fparam_1,in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8,in_stack_ffffff98,
               in_stack_ffffffa0,in_stack_ffffffa8,in_stack_ffffffb0,in_stack_ffffffb8);
LAB_00012634:
    bVar1 = true;
LAB_00012638:
    if (iVar2 < 0) {
      _gliDetachRevert(param_1);
    }
LAB_000126b8:
    uVar6 = 0;
  }
  else {
    if ((uVar6 < 2) || (uVar6 == 4)) goto LAB_00012638;
    if (uVar6 < 4) goto LAB_00012634;
    if (uVar6 == 0x2720) {
      if ((param_2 == 0) || (uVar7 = (uint)*(byte *)(param_1 + 0x85a5), uVar7 == 0xff)) {
        uVar6 = 0x2720;
        goto LAB_00012744;
      }
      *(undefined1 *)(param_1 + 0x85a7) = 1;
      iVar2 = uVar7 * 0x2e0 + param_1;
      uVar6 = (**(code **)(*(int *)(iVar2 + 0x8884) + 0x138))
                        (*(undefined4 *)(iVar2 + 0x85ac),param_2,param_3,param_5);
      if (4 < uVar6) goto LAB_000126d8;
      if (uVar7 != *(byte *)(param_1 + 0x85a8)) {
        _gliSwitchPlugin(param_1,uVar7);
        bVar1 = true;
      }
      goto LAB_000126b8;
    }
    if (iVar2 < 0) {
      _gliDetachRevert(param_1);
    }
LAB_000126d8:
    if (uVar6 != 0) {
LAB_00012744:
      *(undefined4 *)(param_1 + 0x4848) = 0;
      *(undefined4 *)(param_1 + 0x484c) = 0;
      if ((*(char *)(param_1 + 0x4692) != '\0') && (*(char *)(param_1 + 0x4691) == '\0')) {
        return uVar6;
      }
      *(undefined1 *)(param_1 + 0x4691) = 0;
      *(undefined1 *)(param_1 + 0x4692) = 1;
      goto LAB_00012774;
    }
  }
  cVar5 = '\0';
  if ((*(char *)(param_1 + 0x4690) == '\0') || (param_3 == 0)) {
    cVar5 = '\x01';
  }
  *(int *)(param_1 + 0x4848) = param_3;
  *(int *)(param_1 + 0x484c) = param_2;
  if ((!bVar1) && (*(char *)(param_1 + 0x4692) == cVar5)) {
    return uVar6;
  }
  *(char *)(param_1 + 0x4692) = cVar5;
  uVar3 = 0;
  if ((*(int *)(param_1 + 0x4e1c) == 0x1c00) && (cVar5 == '\0')) {
    uVar3 = 1;
  }
  *(undefined1 *)(param_1 + 0x4691) = uVar3;
  *(undefined4 *)(param_1 + 0x757c) = 0xffffffff;
LAB_00012774:
  ((int (*)())_gliSetCurrentPluginDispatchTable)(param_1);
  return uVar6;
}

/* _gliUpdatePluginConfig @ 0x127a4 (104 bytes) */
void _gliUpdatePluginConfig(int param_1,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  undefined *puVar1;
  double fparam_1_00;
  double in_stack_ffffffb8;
  double in_stack_ffffffc0;
  double in_stack_ffffffc8;
  double in_stack_ffffffd0;
  double in_stack_ffffffd8;
  
  ((void (*)())_gleUpdateDepthRangeData)(param_1,fparam_1,fparam_2,fparam_3,fparam_4,fparam_5,fparam_6,fparam_7,fparam_8,
             in_stack_ffffffb8,in_stack_ffffffc0,in_stack_ffffffc8,in_stack_ffffffd0,
             in_stack_ffffffd8);
  ((int (*)())_gleUpdatePolyMode)(param_1);
  ((void (*)())_gleUpdateViewScissorData)(param_1,fparam_1_00,fparam_2,fparam_3,fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
  ((int (*)())_gleUpdateTextureTransform)(param_1);
  puVar1 = PTR__gleSetClipInterpFunc_00112038;
  *(undefined **)(param_1 + 0x49c8) = PTR__gleSetEyeInterpFunc_0011203c;
  *(undefined **)(param_1 + 0x49cc) = puVar1;
  ((int (*)())_gleResetVertexArrays)(param_1);
  return;
}

/* _gleResetVertexArrays @ 0x1280c (128 bytes) */
int _gleResetVertexArrays(param_1)
  int param_1;
{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x49a8);
  uVar1 = ((int (*)())_gleReinitFuncCache)(*(undefined4 *)(param_1 + 0x49b4));
  *(undefined4 *)(param_1 + 0x49b4) = uVar1;
  uVar1 = ((int (*)())_gleReinitFuncCache)(*(undefined4 *)(param_1 + 0x49b8));
  *(undefined4 *)(param_1 + 0x49b8) = uVar1;
  *(undefined2 *)(param_1 + 0x49c2) = 1;
  *(undefined4 *)(param_1 + 0x49c4) = 0;
  *(undefined2 *)(param_1 + 0x49be) = 1;
  if (iVar2 != 0) {
    (**(code **)(param_1 + 0x47cc))(*(undefined4 *)(param_1 + 0x4688),iVar2);
    *(undefined4 *)(param_1 + 0x49a8) = 0;
    *(uint *)(param_1 + 0x4980) = (uint)*(ushort *)(param_1 + 0x4982);
  }
  return;
}

/* _gleReinitFuncCache @ 0x1288c (168 bytes) */
int _gleReinitFuncCache(param_1)
  int *param_1;
{
  int *piVar1;
  int iVar2;
  int *piVar3;
  
  iVar2 = 0;
  if (param_1 != (int *)0x0) {
    piVar1 = (int *)*param_1;
    while (piVar1 != param_1) {
      piVar3 = (int *)*piVar1;
      _gleDCBFree(piVar1);
      piVar1 = piVar3;
    }
    iVar2 = ((int (*)())_gleDCBRealloc)(param_1,0x24);
    *(undefined4 *)(iVar2 + 0x14) = 0xffffffff;
    *(undefined4 *)(iVar2 + 0x20) = 0x4e800020;
    *(undefined4 *)(iVar2 + 8) = 0xffffffff;
    *(undefined4 *)(iVar2 + 0xc) = 0xffffffff;
    *(undefined4 *)(iVar2 + 0x10) = 0xffffffff;
    *(int *)(iVar2 + 4) = iVar2;
    *(int *)iVar2 = iVar2;
    (*(code *)_glePushInstructions)(1,iVar2 + 0x20);
  }
  return iVar2;
}

/* _gleDCBRealloc @ 0x12934 (256 bytes) */
int _gleDCBRealloc(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  void *pvVar5;
  int iVar6;
  uint uVar7;
  
  if (param_2 < 1) {
    if (param_1 != 0) {
      _gleDCBFree(param_1);
    }
    uVar3 = 0;
  }
  else {
    if (param_1 == 0) {
      uVar3 = _gleDCBAlloc(param_2);
      return uVar3;
    }
    uVar7 = (uint)*(byte *)(param_1 + -1);
    pvVar5 = _realloc((void *)(param_1 - uVar7),param_2 + 0x3fU & 0xffffffe0);
    uVar3 = 0;
    if (pvVar5 != (void *)0x0) {
      uVar3 = (int)pvVar5 + 0x20U & 0xffffffe0;
      uVar2 = uVar3 - (int)pvVar5 & 0xff;
      if (uVar2 != uVar7) {
        iVar4 = param_2 + 3 >> 2;
        if (uVar2 < uVar7) {
          iVar6 = 0;
          if (0 < iVar4) {
            do {
              iVar1 = iVar6 * 4;
              iVar6 = iVar6 + 1;
              *(undefined4 *)(iVar1 + uVar3) = *(undefined4 *)((int)pvVar5 + iVar1 + uVar7);
              iVar4 = iVar4 + -1;
            } while (iVar4 != 0);
          }
        }
        else {
          iVar6 = iVar4 + -1;
          if (-1 < iVar6) {
            do {
              iVar1 = iVar6 * 4;
              iVar6 = iVar6 + -1;
              *(undefined4 *)(iVar1 + uVar3) = *(undefined4 *)((int)pvVar5 + iVar1 + uVar7);
              iVar4 = iVar4 + -1;
            } while (iVar4 != 0);
          }
        }
        *(char *)(uVar3 - 1) = (char)(uVar3 - (int)pvVar5);
      }
    }
  }
  return uVar3;
}

/* _glGetIntegerv_Exec @ 0x12a34 (332 bytes) */
int _glGetIntegerv_Exec(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  int *param_3;
{
  undefined4 uVar1;
  int iVar2;
  double *pdVar3;
  int iVar4;
  double dVar5;
  double dVar6;
  char local_b0 [16];
  double local_a0 [16];
  longlong local_20;
  int local_18 [2];
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    pdVar3 = local_a0;
    iVar4 = ((int (*)())_gleGetState)(param_1,param_2,pdVar3,local_18,local_b0);
    dVar6 = DOUBLE_00108d90;
    if (iVar4 == 0) {
      if (*(int *)(param_1 + 0x7574) != 0) {
        return;
      }
      uVar1 = 0x500;
      goto LAB_00012aa8;
    }
    if (iVar4 != -1) {
      if (local_18[0] == 0x1404) {
        if (iVar4 < 1) {
          return;
        }
        do {
          iVar2 = *(int *)pdVar3;
          pdVar3 = pdVar3 + 1;
          *param_3 = iVar2;
          param_3 = param_3 + 1;
          iVar4 = iVar4 + -1;
        } while (iVar4 != 0);
        return;
      }
      if (local_b0[0] == '\0') {
        if (iVar4 < 1) {
          return;
        }
        do {
          dVar6 = *pdVar3;
          pdVar3 = pdVar3 + 1;
          local_20 = (longlong)(int)dVar6;
          *param_3 = (int)dVar6;
          param_3 = param_3 + 1;
          iVar4 = iVar4 + -1;
        } while (iVar4 != 0);
        return;
      }
      if (iVar4 < 1) {
        return;
      }
      do {
        dVar5 = *pdVar3;
        pdVar3 = pdVar3 + 1;
        local_20 = (longlong)(int)(dVar5 * dVar6);
        *param_3 = (int)(dVar5 * dVar6);
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
LAB_00012aa8:
  *(undefined4 *)(param_1 + 0x7574) = uVar1;
  return;
}

/* _gleGetState @ 0x12b80 (13228 bytes) */
int _gleGetState(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  uint param_2;
  double *param_3;
  undefined4 *param_4;
  undefined1 *param_5;
{
  float fVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  int iVar11;
  code *pcVar12;
  int iVar13;
  double dVar14;
  undefined8 uVar15;
  
  *param_4 = 0x1404;
  *param_5 = 0;
  dVar14 = DOUBLE_00108d58;
  iVar13 = 1;
  if (param_2 == 0x6092) {
    uVar2 = (uint)*(ushort *)(param_1 + 0x2808);
    goto LAB_00015f48;
  }
  if (0x6092 < param_2) {
    if (param_2 == 0x84e2) {
      uVar2 = (uint)*(ushort *)(*(int *)(param_1 + 0x468c) + 0xb4);
      goto LAB_00015f48;
    }
    if (0x84e2 < param_2) {
      if (param_2 == 0x86aa) {
        uVar2 = *(uint *)(*(int *)(param_1 + 0x4a60) + 0xac);
        goto LAB_00015f48;
      }
      if (param_2 < 0x86ab) {
        if (param_2 == 0x854e) {
          uVar2 = *(uint *)(param_1 + 0x41fc);
          goto LAB_00015f48;
        }
        if (param_2 < 0x854f) {
          if (param_2 == 0x8505) {
            uVar2 = *(uint *)(*(int *)(param_1 + 0x468c) + 0xa4);
            goto LAB_00015f48;
          }
          if (param_2 < 0x8506) {
            if (param_2 == 0x84ef) {
              uVar2 = (uint)*(ushort *)(param_1 + 0x3176);
              goto LAB_00015f48;
            }
            if (param_2 < 0x84f0) {
              if (param_2 == 0x84e5) {
                if (7 < *(int *)(param_1 + 0x53d4)) {
                  return -1;
                }
                iVar13 = param_1 + *(int *)(param_1 + 0x53d4) * 0x40 + 0x1fc0;
              }
              else if (param_2 < 0x84e6) {
                if (param_2 == 0x84e3) {
                  iVar13 = param_1 + 0x1cc0;
                }
                else {
                  if (param_2 != 0x84e4) {
                    return 0;
                  }
                  iVar13 = param_1 + 0x1c80;
                }
              }
              else {
                if (param_2 != 0x84e6) {
                  if (param_2 != 0x84e8) {
                    return 0;
                  }
                  uVar4 = *(uint *)(*(int *)(param_1 + 0x468c) + 0x10);
                  uVar2 = *(uint *)(*(int *)(param_1 + 0x468c) + 0xc);
                  if ((int)uVar4 < (int)uVar2) {
                    uVar2 = uVar4;
                  }
                  goto LAB_00015efc;
                }
                iVar13 = param_1 + 0x1c40;
              }
              goto LAB_00014d40;
            }
            if (param_2 == 0x84f8) goto LAB_00015960;
            if (0x84f8 < param_2) {
              if (param_2 == 0x84ff) {
                uVar2 = (uint)(int)*(float *)(*(int *)(param_1 + 0x468c) + 0xac);
              }
              else if (param_2 < 0x8500) {
                if (param_2 != 0x84fd) {
                  return 0;
                }
                uVar2 = (uint)(int)*(float *)(*(int *)(param_1 + 0x468c) + 0xb0);
              }
              else {
                if (param_2 != 0x8504) {
                  return 0;
                }
                uVar2 = *(uint *)(*(int *)(param_1 + 0x468c) + 0xa0);
              }
              goto LAB_00015f48;
            }
            if (param_2 == 0x84f5) goto LAB_000155d4;
            if (param_2 != 0x84f6) {
              return 0;
            }
            goto LAB_00015948;
          }
          if (param_2 == 0x851f) {
            uVar2 = (uint)*(ushort *)(*(int *)(param_1 + 0x4a60) + 0x342);
            goto LAB_00015f48;
          }
          if (0x851f < param_2) {
            if (param_2 == 0x852a) {
              *param_3 = (double)*(float *)(param_1 + 0x4200);
              param_3[1] = (double)*(float *)(param_1 + 0x4204);
              param_3[2] = (double)*(float *)(param_1 + 0x4208);
              dVar14 = (double)*(float *)(param_1 + 0x420c);
            }
            else {
              if (param_2 < 0x852b) {
                if (param_2 == 0x8520) {
                  uVar2 = *(uint *)(*(int *)(param_1 + 0x468c) + 0x8c);
                }
                else {
                  if (param_2 != 0x8522) {
                    return 0;
                  }
                  uVar2 = (uint)*(byte *)(param_1 + 0x41f8);
                }
                goto LAB_00015f48;
              }
              if (param_2 == 0x8534) {
                uVar2 = (uint)*(ushort *)(param_1 + 0x317a);
                goto LAB_00015f48;
              }
              if (0x8534 < param_2) {
                if (param_2 != 0x854d) {
                  return 0;
                }
                uVar2 = *(uint *)(*(int *)(param_1 + 0x468c) + 0x98);
                goto LAB_00015f48;
              }
              if (param_2 != 0x852b) {
                return 0;
              }
              *param_3 = (double)*(float *)(param_1 + 0x4210);
              param_3[1] = (double)*(float *)(param_1 + 0x4214);
              param_3[2] = (double)*(float *)(param_1 + 0x4218);
              dVar14 = (double)*(float *)(param_1 + 0x421c);
            }
            goto LAB_00015a8c;
          }
          if (param_2 == 0x8514) {
            uVar2 = *(uint *)(*(int *)(*(int *)(param_1 + 0x53d4) * 0x14 + param_1 + 0x5154) + 4);
            goto LAB_00015f48;
          }
          if (0x8514 < param_2) {
            if (param_2 == 0x851c) {
              uVar2 = (uint)*(ushort *)(*(int *)(param_1 + 0x468c) + 0xc2);
            }
            else {
              if (param_2 != 0x851e) {
                return 0;
              }
              uVar2 = *(uint *)(*(int *)(param_1 + 0x4a60) + 0x348);
            }
            goto LAB_00015f48;
          }
          if (param_2 != 0x850a) {
            if (param_2 != 0x8513) {
              return 0;
            }
            uVar2 = *(uint *)(*(int *)(param_1 + 0x53d4) * 0x7c + param_1 + 0x3534) & 1;
            goto LAB_00015f48;
          }
          iVar13 = param_1 + 0x1d00;
        }
        else {
          if (param_2 != 0x8641) {
            if (0x8641 < param_2) {
              if (param_2 == 0x86a3) {
                iVar11 = *(int *)(param_1 + 0x468c);
                iVar13 = 0;
                if (*(char *)(iVar11 + 0xc6) != '\0') {
                  do {
                    iVar3 = iVar13 + 1;
                    *(uint *)(param_3 + iVar13) = *(uint *)(iVar13 * 4 + iVar11 + 200);
                    iVar11 = *(int *)(param_1 + 0x468c);
                    iVar13 = iVar3;
                  } while (iVar3 < (int)(uint)*(byte *)(iVar11 + 0xc6));
                  return iVar3;
                }
                return 0;
              }
              if (param_2 < 0x86a4) {
                if (param_2 == 0x864b) {
                  uVar2 = *(uint *)(param_1 + 0x541c);
                }
                else if (param_2 < 0x864c) {
                  if (param_2 == 0x8642) {
                    uVar2 = (uint)*(byte *)(param_1 + 0x4665);
                  }
                  else {
                    if (param_2 != 0x8643) {
                      return 0;
                    }
                    uVar2 = (uint)*(byte *)(param_1 + 0x4666);
                  }
                }
                else if (param_2 == 0x864f) {
                  uVar2 = (uint)*(byte *)(param_1 + 0x3129);
                }
                else {
                  if (param_2 != 0x86a2) {
                    return 0;
                  }
                  uVar2 = (uint)*(byte *)(*(int *)(param_1 + 0x468c) + 0xc6);
                }
                goto LAB_00015f48;
              }
              if (param_2 == 0x86a6) {
                uVar2 = (uint)*(byte *)(param_1 + 0x4662);
                goto LAB_00015f48;
              }
              if (param_2 < 0x86a7) {
                if (param_2 == 0x86a4) {
                  uVar2 = *(uint *)(*(int *)(param_1 + 0x468c) + 0x90);
                }
                else {
                  if (param_2 != 0x86a5) {
                    return 0;
                  }
                  uVar2 = (uint)*(byte *)(param_1 + 0x4660);
                }
                goto LAB_00015f48;
              }
              if (param_2 != 0x86a8) {
                if (param_2 < 0x86a9) {
                  uVar2 = (uint)*(byte *)(param_1 + 0x4661);
                }
                else {
                  uVar2 = *(ushort *)(*(int *)(param_1 + 0x4a60) + 0xb0) & 0xffff7fff;
                }
                goto LAB_00015f48;
              }
              *param_3 = (double)*(float *)(param_1 + 0x2d0);
              param_3[1] = (double)*(float *)(param_1 + 0x2d4);
              param_3[2] = (double)*(float *)(param_1 + 0x2d8);
              dVar14 = (double)*(float *)(param_1 + 0x2dc);
              goto LAB_00015a8c;
            }
            if (param_2 != 0x85b4) {
              if (param_2 < 0x85b5) {
                if (param_2 == 0x85b1) {
                  uVar2 = *(uint *)(param_1 + 0x507c);
                  goto LAB_00015f48;
                }
                if (param_2 < 0x85b2) {
                  if (param_2 == 0x855a) {
                    uVar2 = (uint)*(ushort *)(param_1 + 0x3168);
                  }
                  else {
                    if (param_2 != 0x85b0) {
                      return 0;
                    }
                    uVar2 = (uint)*(byte *)(param_1 + 0x30ae);
                  }
                  goto LAB_00015f48;
                }
                if (param_2 == 0x85b2) {
                  uVar2 = (uint)*(byte *)(param_1 + 0x31e6);
                  goto LAB_00015f48;
                }
                if (param_2 != 0x85b3) {
                  return 0;
                }
LAB_000155d4:
                uVar2 = *(uint *)(*(int *)(param_1 + 0x53d4) * 0x7c + param_1 + 0x3534) >> 2 & 1;
                goto LAB_00015f48;
              }
              if (param_2 == 0x8620) {
                uVar2 = (uint)*(byte *)(param_1 + 0x4664);
                goto LAB_00015f48;
              }
              if (0x8620 < param_2) {
                if (param_2 == 0x862f) {
                  uVar2 = 8;
                  goto LAB_00015f48;
                }
                if (param_2 < 0x8630) {
                  if (param_2 != 0x862e) {
                    return 0;
                  }
                  uVar2 = 2;
                  goto LAB_00015f48;
                }
                if (param_2 != 0x8640) {
                  return 0;
                }
                iVar13 = *(int *)(*(int *)(param_1 + 0x4ff4) * 4 + param_1 + 0x4ffc);
                goto LAB_00014c5c;
              }
              if (param_2 == 0x85b5) {
                uVar2 = *(uint *)(*(int *)(param_1 + 0x4a60) + 4);
                goto LAB_00015f48;
              }
              if (param_2 != 0x85b6) {
                return 0;
              }
LAB_00015960:
              uVar2 = *(uint *)(*(int *)(param_1 + 0x468c) + 0xe8);
              goto LAB_00015f48;
            }
LAB_00015948:
            uVar2 = *(uint *)(*(int *)(*(int *)(param_1 + 0x53d4) * 0x14 + param_1 + 0x515c) + 4);
            goto LAB_00015f48;
          }
          iVar13 = param_1 + *(int *)(param_1 + 0x4ff4) * 0x40 + 0x1bc0;
        }
LAB_00014c84:
        _gleGetMatrixd(iVar13,param_3);
      }
      else {
        if (param_2 == 0x889b) {
          uVar2 = 0;
          iVar13 = *(int *)(*(int *)(param_1 + 0x4a60) + 0x378);
          if (iVar13 != 0) {
            uVar2 = *(uint *)(iVar13 + 4);
          }
          goto LAB_00015f48;
        }
        if (param_2 < 0x889c) {
          if (param_2 == 0x883d) {
            uVar2 = (uint)*(ushort *)(param_1 + 0x30e2);
            goto LAB_00015f48;
          }
          if (0x883d < param_2) {
            if (param_2 == 0x8894) {
              uVar2 = 0;
              iVar13 = *(int *)(*(int *)(param_1 + 0x4a60) + 0x358);
              if (iVar13 != 0) {
                uVar2 = *(uint *)(iVar13 + 4);
              }
              goto LAB_00015f48;
            }
            if (0x8894 < param_2) {
              if (param_2 == 0x8897) {
                uVar2 = 0;
                iVar13 = *(int *)(*(int *)(param_1 + 0x4a60) + 0x364);
                if (iVar13 != 0) {
                  uVar2 = *(uint *)(iVar13 + 4);
                }
              }
              else if (param_2 < 0x8898) {
                if (param_2 == 0x8895) {
                  uVar2 = 0;
                  iVar13 = *(int *)(*(int *)(param_1 + 0x4a60) + 0x35c);
                  if (iVar13 != 0) {
                    uVar2 = *(uint *)(iVar13 + 4);
                  }
                }
                else {
                  if (param_2 != 0x8896) {
                    return 0;
                  }
                  uVar2 = 0;
                  iVar13 = *(int *)(*(int *)(param_1 + 0x4a60) + 0x360);
                  if (iVar13 != 0) {
                    uVar2 = *(uint *)(iVar13 + 4);
                  }
                }
              }
              else if (param_2 == 0x8899) {
                uVar2 = 0;
                if (*(int *)(param_1 + 0x48f4) != 0) {
                  uVar2 = *(uint *)(*(int *)(param_1 + 0x48f4) + 4);
                }
              }
              else if (param_2 < 0x889a) {
                uVar2 = 0;
                iVar13 = *(int *)(*(int *)(param_1 + 0x4a60) + 0x368);
                if (iVar13 != 0) {
                  uVar2 = *(uint *)(iVar13 + 4);
                }
              }
              else {
                uVar2 = 0;
                iVar13 = *(int *)(*(int *)(param_1 + 0x53d8) * 4 + *(int *)(param_1 + 0x4a60) +
                                 0x380);
                if (iVar13 != 0) {
                  uVar2 = *(uint *)(iVar13 + 4);
                }
              }
              goto LAB_00015f48;
            }
            if (param_2 == 0x8872) {
              uVar2 = (uint)*(ushort *)(*(int *)(param_1 + 0x468c) + 0xb6);
              goto LAB_00015f48;
            }
            if (param_2 < 0x8873) {
              if (param_2 == 0x8869) {
                uVar2 = 0x10;
              }
              else {
                if (param_2 != 0x8871) {
                  return 0;
                }
                uVar2 = (uint)*(ushort *)(*(int *)(param_1 + 0x468c) + 0xba);
              }
              goto LAB_00015f48;
            }
            if (param_2 == 0x8890) {
              uVar2 = (uint)*(byte *)(param_1 + 0x312a);
              goto LAB_00015f48;
            }
            if (param_2 != 0x8891) {
              return 0;
            }
            *param_3 = *(double *)(param_1 + 0x312c);
            dVar14 = *(double *)(param_1 + 0x3134);
LAB_00015cf4:
            iVar13 = 2;
            param_3[1] = dVar14;
            goto LAB_00015d48;
          }
          if (param_2 == 0x8801) {
            uVar2 = (uint)*(ushort *)(param_1 + 0x351a);
            goto LAB_00015f48;
          }
          if (0x8801 < param_2) {
            if (param_2 == 0x8804) {
              uVar2 = (uint)*(byte *)(param_1 + 0x466c);
            }
            else if (param_2 < 0x8805) {
              if (param_2 == 0x8802) {
                uVar2 = (uint)*(ushort *)(param_1 + 0x351c);
              }
              else {
                if (param_2 != 0x8803) {
                  return 0;
                }
                uVar2 = (uint)*(ushort *)(param_1 + 0x351e);
              }
            }
            else if (param_2 == 0x8824) {
              uVar2 = *(uint *)(*(int *)(param_1 + 0x468c) + 0x14);
            }
            else {
              if (param_2 < 0x8824) {
                return 0;
              }
              if (0x8834 < param_2) {
                return 0;
              }
              uVar2 = 0;
              iVar13 = param_2 - 0x8825;
              if (iVar13 < 4) {
                if (*(int *)(param_1 + 0x744c) == 0) {
                  uVar2 = (uint)*(ushort *)(iVar13 * 2 + param_1 + 0x311a);
                }
                else {
                  uVar2 = (uint)*(ushort *)(iVar13 * 2 + *(int *)(param_1 + 0x744c) + 0xc0);
                }
              }
            }
            goto LAB_00015f48;
          }
          if (0x8723 < param_2) {
            if (param_2 != 0x8800) {
              return 0;
            }
            uVar2 = (uint)*(ushort *)(param_1 + 0x3518);
            goto LAB_00015f48;
          }
          if (param_2 < 0x8722) {
            if (param_2 == 0x86ab) {
              uVar2 = (uint)*(short *)(*(int *)(param_1 + 0x4a60) + 0xb2);
            }
            else {
              if (param_2 != 0x86ad) {
                return 0;
              }
              uVar2 = *(uint *)(*(int *)(param_1 + 0x4a60) + 0x334) >> 0x15 & 1;
            }
            goto LAB_00015f48;
          }
          iVar13 = param_1 + param_2 * 0x40 + -0x21ab40;
          goto LAB_00014c84;
        }
        if (param_2 == 0x8a10) {
          *(uint *)param_3 = *(uint *)(*(int *)(param_1 + 0x468c) + 0x1c);
          uVar2 = *(uint *)(*(int *)(param_1 + 0x468c) + 0x20);
          goto LAB_00015638;
        }
        if (0x8a10 < param_2) {
          if (param_2 == 0x8b4d) {
            uVar2 = 0x10;
          }
          else if (param_2 < 0x8b4e) {
            if (param_2 == 0x8b4a) {
              uVar2 = 0x200;
            }
            else if (param_2 < 0x8b4b) {
              if (param_2 == 0x8a11) {
                uVar2 = 0;
                iVar13 = *(int *)(*(int *)(param_1 + 0x4a60) + 0x37c);
                if (iVar13 != 0) {
                  uVar2 = *(uint *)(iVar13 + 4);
                }
              }
              else {
                if (param_2 != 0x8b49) {
                  return 0;
                }
                uVar2 = 0x200;
              }
            }
            else if (param_2 == 0x8b4b) {
              uVar2 = 0x20;
            }
            else {
              if (param_2 != 0x8b4c) {
                return 0;
              }
              uVar2 = 0;
            }
          }
          else if (param_2 == 0x8ca6) {
            uVar2 = 0;
            if (*(int *)(param_1 + 0x744c) != 0) {
              uVar2 = *(uint *)(*(int *)(param_1 + 0x744c) + 4);
            }
          }
          else if (param_2 < 0x8ca7) {
            if (param_2 == 0x8b8b) {
              uVar2 = (uint)*(ushort *)(param_1 + 0x317c);
            }
            else {
              if (param_2 != 0x8b8d) {
                return 0;
              }
              uVar2 = 0;
              if (*(int *)(param_1 + 0x5430) != 0) {
                uVar2 = *(uint *)(*(int *)(param_1 + 0x5430) + 4);
              }
            }
          }
          else if (param_2 == 0x8cdf) {
            uVar2 = *(uint *)(*(int *)(param_1 + 0x468c) + 0x18);
          }
          else if (param_2 < 0x8ce0) {
            if (param_2 != 0x8ca7) {
              return 0;
            }
            uVar2 = 0;
            if (*(int *)(param_1 + 0x7448) != 0) {
              uVar2 = *(uint *)(*(int *)(param_1 + 0x7448) + 4);
            }
          }
          else {
            if (param_2 != 0x19262) {
              return 0;
            }
            uVar2 = (uint)*(byte *)(param_1 + 0x50b5);
          }
          goto LAB_00015f48;
        }
        if (param_2 == 0x88ef) {
          uVar2 = 0;
          if (*(int *)(param_1 + 0x4a6c) != 0) {
            uVar2 = *(uint *)(*(int *)(param_1 + 0x4a6c) + 4);
          }
          goto LAB_00015f48;
        }
        if (0x88ef < param_2) {
          if (param_2 == 0x897c) {
            uVar2 = (uint)*(byte *)(*(int *)(param_1 + 0x4a60) + 0x34c);
          }
          else if (param_2 < 0x897d) {
            if (param_2 != 0x8910) {
              if (param_2 != 0x8911) {
                return 0;
              }
              uVar2 = *(byte *)(param_1 + 0x7583) + 0x404;
              goto LAB_00015efc;
            }
            uVar2 = *(uint *)(param_1 + 0x3520) >> 2 & 1;
          }
          else if (param_2 == 0x8a0d) {
            uVar2 = (uint)*(ushort *)(*(int *)(param_1 + 0x4a60) + 0xe0);
          }
          else if (param_2 < 0x8a0e) {
            if (param_2 != 0x8a0c) {
              return 0;
            }
            uVar2 = *(uint *)(*(int *)(param_1 + 0x4a60) + 0x334) >> 0x17 & 1;
          }
          else {
            if (param_2 != 0x8a0f) {
              return 0;
            }
            uVar2 = (uint)*(byte *)(*(int *)(param_1 + 0x468c) + 0x27);
          }
          goto LAB_00015f48;
        }
        if (param_2 == 0x889e) {
          uVar2 = 0;
          iVar13 = *(int *)(*(int *)(param_1 + 0x4a60) + 0x374);
          if (iVar13 != 0) {
            uVar2 = *(uint *)(iVar13 + 4);
          }
          goto LAB_00015f48;
        }
        if (param_2 < 0x889f) {
          if (param_2 == 0x889c) {
            uVar2 = 0;
            iVar13 = *(int *)(*(int *)(param_1 + 0x4a60) + 0x370);
            if (iVar13 != 0) {
              uVar2 = *(uint *)(iVar13 + 4);
            }
          }
          else {
            if (param_2 != 0x889d) {
              return 0;
            }
            uVar2 = 0;
            iVar13 = *(int *)(*(int *)(param_1 + 0x4a60) + 0x36c);
            if (iVar13 != 0) {
              uVar2 = *(uint *)(iVar13 + 4);
            }
          }
          goto LAB_00015f48;
        }
        if (param_2 != 34999) {
          if (param_2 != 0x88ed) {
            return 0;
          }
          uVar2 = 0;
          if (*(int *)(param_1 + 0x4a68) != 0) {
            uVar2 = *(uint *)(*(int *)(param_1 + 0x4a68) + 4);
          }
          goto LAB_00015f48;
        }
        iVar13 = param_1 + *(int *)(param_1 + 0x4ff4) * 0x40 + 0x1bc0;
LAB_00014d40:
        _gleGetTransposeMatrixd(iVar13,param_3);
      }
      iVar13 = 0x10;
      goto LAB_00015d48;
    }
    if (param_2 == 0x809f) {
      uVar2 = (uint)*(byte *)(param_1 + 0x41f2);
      goto LAB_00015f48;
    }
    if (param_2 < 0x80a0) {
      if (param_2 == 0x806d) {
        uVar2 = *(uint *)(param_1 + 0x31dc);
        goto LAB_00015f48;
      }
      if (0x806d < param_2) {
        if (param_2 == 0x807e) {
          uVar2 = *(ushort *)(*(int *)(param_1 + 0x4a60) + 0x50) & 0xffff7fff;
        }
        else if (param_2 < 0x807f) {
          if (param_2 == 0x8076) {
            uVar2 = *(uint *)(*(int *)(param_1 + 0x4a60) + 0x334) >> 0x12 & 1;
          }
          else if (param_2 < 0x8077) {
            if (param_2 == 0x8073) {
              uVar2 = (uint)*(ushort *)(*(int *)(param_1 + 0x468c) + 0xbe);
            }
            else if (param_2 < 0x8074) {
              if (param_2 == 0x806e) {
                uVar2 = *(uint *)(param_1 + 0x31d0);
              }
              else {
                if (param_2 != 0x806f) {
                  return 0;
                }
                uVar2 = *(uint *)(*(int *)(param_1 + 0x53d4) * 0x7c + param_1 + 0x3534) >> 1 & 1;
              }
            }
            else if (param_2 == 0x8074) {
              uVar2 = *(uint *)(*(int *)(param_1 + 0x4a60) + 0x334) >> 0x10 & 1;
            }
            else {
              if (param_2 != 0x8075) {
                return 0;
              }
              uVar2 = *(uint *)(*(int *)(param_1 + 0x4a60) + 0x334) >> 0x11 & 1;
            }
          }
          else if (param_2 == 0x8079) {
            uVar2 = *(uint *)(*(int *)(param_1 + 0x4a60) + 0x334) >> 0x16 & 1;
          }
          else if (param_2 < 0x807a) {
            if (param_2 == 0x8077) {
              uVar2 = -(uint)*(ushort *)(param_1 + 0x48ea) >> 0x1f;
            }
            else {
              if (param_2 != 0x8078) {
                return 0;
              }
              iVar13 = *(int *)(param_1 + 0x4a60);
              uVar15 = ___ashldi3(0,0x1000000,*(undefined4 *)(param_1 + 0x53d8));
              uVar2 = 0;
              if ((*(uint *)(iVar13 + 0x330) & (uint)((ulonglong)uVar15 >> 0x20)) != 0 ||
                  (*(uint *)(iVar13 + 0x334) & (uint)uVar15) != 0) {
                uVar2 = 1;
              }
            }
          }
          else if (param_2 == 0x807b) {
            uVar2 = (uint)*(ushort *)(*(int *)(param_1 + 0x4a60) + 0x38);
          }
          else if (param_2 < 0x807b) {
            uVar2 = (uint)*(short *)(*(int *)(param_1 + 0x4a60) + 0x3a);
          }
          else {
            if (param_2 != 0x807c) {
              return 0;
            }
            uVar2 = *(uint *)(*(int *)(param_1 + 0x4a60) + 0x34);
          }
        }
        else if (param_2 == 0x8086) {
          uVar2 = *(uint *)(param_1 + 0x48e4);
        }
        else if (param_2 < 0x8087) {
          if (param_2 == 0x8082) {
            uVar2 = *(ushort *)(*(int *)(param_1 + 0x4a60) + 0x68) & 0xffff7fff;
          }
          else if (param_2 < 0x8083) {
            if (param_2 == 0x807f) {
              uVar2 = *(uint *)(*(int *)(param_1 + 0x4a60) + 0x4c);
            }
            else {
              if (param_2 != 0x8081) {
                return 0;
              }
              uVar2 = (uint)*(short *)(*(int *)(param_1 + 0x4a60) + 0x6a);
            }
          }
          else if (param_2 == 0x8083) {
            uVar2 = *(uint *)(*(int *)(param_1 + 0x4a60) + 100);
          }
          else {
            if (param_2 != 0x8085) {
              return 0;
            }
            uVar2 = (uint)*(ushort *)(param_1 + 0x48e8);
          }
        }
        else if (param_2 == 0x808a) {
          uVar2 = *(uint *)(*(int *)(param_1 + 0x53d8) * 0x18 + *(int *)(param_1 + 0x4a60) + 0xf4);
        }
        else if (param_2 < 0x808b) {
          if (param_2 == 0x8088) {
            uVar2 = (uint)*(short *)(*(int *)(param_1 + 0x53d8) * 0x18 + *(int *)(param_1 + 0x4a60)
                                    + 0xfa);
          }
          else {
            if (param_2 != 0x8089) {
              return 0;
            }
            uVar2 = (uint)*(ushort *)
                           (*(int *)(param_1 + 0x53d8) * 0x18 + *(int *)(param_1 + 0x4a60) + 0xf8);
          }
        }
        else if (param_2 == 0x809d) {
          uVar2 = (uint)*(byte *)(param_1 + 0x41f0);
        }
        else if (param_2 < 0x809e) {
          if (param_2 != 0x808c) {
            return 0;
          }
          uVar2 = *(uint *)(*(int *)(param_1 + 0x4a60) + 0xc4);
        }
        else {
          uVar2 = (uint)*(byte *)(param_1 + 0x41f1);
        }
        goto LAB_00015f48;
      }
      if (param_2 == 0x8021) {
        dVar14 = (double)*(float *)(param_1 + 0x339c);
      }
      else if (param_2 < 0x8022) {
        if (param_2 == 0x8011) {
          uVar2 = *(uint *)(param_1 + 0x3410) >> 1 & 1;
          goto LAB_00015f48;
        }
        if (param_2 < 0x8012) {
          if (param_2 != 0x8005) {
            if (param_2 < 0x8006) {
              if (param_2 == 0x6093) {
                uVar2 = (uint)*(ushort *)(param_1 + 0x280a);
              }
              else {
                if (param_2 != 0x6094) {
                  return 0;
                }
                uVar2 = *(uint *)(param_1 + 0x2800);
              }
            }
            else if (param_2 == 0x8009) {
              uVar2 = (uint)*(ushort *)(param_1 + 0x30e0);
            }
            else {
              if (param_2 != 0x8010) {
                return 0;
              }
              uVar2 = *(uint *)(param_1 + 0x3410) & 1;
            }
            goto LAB_00015f48;
          }
          *param_3 = (double)*(float *)(param_1 + 0x30d0);
          param_3[1] = (double)*(float *)(param_1 + 0x30d4);
          param_3[2] = (double)*(float *)(param_1 + 0x30d8);
          dVar14 = (double)*(float *)(param_1 + 0x30dc);
          goto LAB_00015a8c;
        }
        if (param_2 == 0x801d) {
          dVar14 = (double)*(float *)(param_1 + 0x3398);
        }
        else if (param_2 < 0x801e) {
          if (param_2 == 0x8012) {
            uVar2 = *(uint *)(param_1 + 0x3410) >> 2 & 1;
            goto LAB_00015f48;
          }
          if (param_2 != 0x801c) {
            return 0;
          }
          dVar14 = (double)*(float *)(param_1 + 0x3390);
        }
        else if (param_2 == 0x801f) {
          dVar14 = (double)*(float *)(param_1 + 0x33a8);
        }
        else if (param_2 < 0x8020) {
          dVar14 = (double)*(float *)(param_1 + 0x33a0);
        }
        else {
          dVar14 = (double)*(float *)(param_1 + 0x3394);
        }
      }
      else if (param_2 == 0x8038) {
        dVar14 = (double)*(float *)(param_1 + 0x34c8);
      }
      else {
        if (0x8038 < param_2) {
          if (param_2 == 0x8069) {
            uVar2 = *(uint *)(*(int *)(*(int *)(param_1 + 0x53d4) * 0x14 + param_1 + 0x5160) + 4);
          }
          else if (param_2 < 0x806a) {
            if (param_2 == 0x803a) {
              uVar2 = (uint)*(byte *)(param_1 + 0x280e);
            }
            else {
              if (param_2 != 0x8068) {
                return 0;
              }
              uVar2 = *(uint *)(*(int *)(*(int *)(param_1 + 0x53d4) * 0x14 + param_1 + 0x5164) + 4);
            }
          }
          else if (param_2 == 0x806b) {
            uVar2 = *(uint *)(param_1 + 0x31c0);
          }
          else if (param_2 < 0x806c) {
            uVar2 = *(uint *)(*(int *)(*(int *)(param_1 + 0x53d4) * 0x14 + param_1 + 0x5158) + 4);
          }
          else {
            uVar2 = *(uint *)(0x31b4 + param_1);
          }
          goto LAB_00015f48;
        }
        if (param_2 == 0x8024) {
          uVar2 = *(uint *)(param_1 + 0x3410) >> 4 & 1;
          goto LAB_00015f48;
        }
        if (0x8024 < param_2) {
          if (param_2 == 0x802e) {
            uVar2 = *(uint *)(param_1 + 0x3410) >> 3 & 1;
          }
          else {
            if (param_2 != 0x8037) {
              return 0;
            }
            uVar2 = (uint)*(byte *)(param_1 + 0x34dd);
          }
          goto LAB_00015f48;
        }
        if (param_2 == 0x8022) {
          dVar14 = (double)*(float *)(param_1 + 0x33a4);
        }
        else {
          if (param_2 != 0x8023) {
            return 0;
          }
          dVar14 = (double)*(float *)(param_1 + 0x33ac);
        }
      }
    }
    else {
      if (param_2 == 0x80f0) {
        uVar2 = *(uint *)(param_1 + 0x5080);
        goto LAB_00015f48;
      }
      if (param_2 < 0x80f1) {
        if (param_2 == 0x80b8) {
          dVar14 = (double)*(float *)(param_1 + 0x3360);
        }
        else if (param_2 < 0x80b9) {
          if (param_2 == 0x80b1) {
            iVar13 = param_1 + 0x1c40;
            goto LAB_00014c84;
          }
          if (param_2 < 0x80b2) {
            if (param_2 == 0x80a9) {
              uVar2 = *(uint *)(*(int *)(param_1 + 0x468c) + 0x5c);
              goto LAB_00015f48;
            }
            if (param_2 < 0x80aa) {
              if (param_2 == 0x80a0) {
                uVar2 = (uint)*(byte *)(param_1 + 0x41f3);
              }
              else {
                if (param_2 != 0x80a8) {
                  return 0;
                }
                uVar2 = *(uint *)(*(int *)(param_1 + 0x468c) + 0x58);
              }
              goto LAB_00015f48;
            }
            if (param_2 != 0x80aa) {
              if (param_2 != 0x80ab) {
                return 0;
              }
              uVar2 = (uint)*(byte *)(param_1 + 0x41f4);
              goto LAB_00015f48;
            }
            dVar14 = (double)*(float *)(param_1 + 0x41ec);
          }
          else if (param_2 == 0x80b4) {
            dVar14 = (double)*(float *)(param_1 + 0x335c);
          }
          else {
            if (param_2 < 0x80b5) {
              if (param_2 != 0x80b2) {
                if (param_2 != 0x80b3) {
                  return 0;
                }
                uVar2 = 5;
                goto LAB_00015f48;
              }
              iVar13 = *(int *)(param_1 + 0x5004);
              goto LAB_00014bf4;
            }
            if (param_2 == 0x80b6) {
              dVar14 = (double)*(float *)(param_1 + 0x336c);
            }
            else if (param_2 < 0x80b7) {
              dVar14 = (double)*(float *)(param_1 + 0x3364);
            }
            else {
              dVar14 = (double)*(float *)(param_1 + 0x3374);
            }
          }
        }
        else {
          if (param_2 == 0x80ca) {
            uVar2 = (uint)*(ushort *)(param_1 + 0x30ce);
            goto LAB_00015f48;
          }
          if (0x80ca < param_2) {
            if (param_2 == 0x80d1) {
              uVar2 = *(uint *)(param_1 + 0x3410) >> 6 & 1;
            }
            else if (param_2 < 0x80d2) {
              if (param_2 == 0x80cb) {
                uVar2 = (uint)*(ushort *)(param_1 + 0x30cc);
              }
              else {
                if (param_2 != 0x80d0) {
                  return 0;
                }
                uVar2 = *(uint *)(param_1 + 0x3410) >> 5 & 1;
              }
            }
            else if (param_2 == 33000) {
              uVar2 = *(uint *)(*(int *)(param_1 + 0x468c) + 0x88);
            }
            else if (param_2 < 0x80e9) {
              if (param_2 != 0x80d2) {
                return 0;
              }
              uVar2 = *(uint *)(param_1 + 0x3410) >> 7 & 1;
            }
            else {
              if (param_2 != 0x80e9) {
                return 0;
              }
              uVar2 = 150000;
            }
            goto LAB_00015f48;
          }
          if (param_2 == 0x80bb) {
            dVar14 = (double)*(float *)(param_1 + 0x3378);
          }
          else {
            if (0x80bb < param_2) {
              if (param_2 != 0x80c8) {
                if (param_2 != 0x80c9) {
                  return 0;
                }
                goto LAB_00014d8c;
              }
              goto LAB_00014d84;
            }
            if (param_2 == 0x80b9) {
              dVar14 = (double)*(float *)(param_1 + 0x3368);
            }
            else {
              if (param_2 != 0x80ba) {
                return 0;
              }
              dVar14 = (double)*(float *)(param_1 + 0x3370);
            }
          }
        }
      }
      else if (param_2 == 0x8453) {
        dVar14 = (double)*(float *)(param_1 + 0x2cc);
      }
      else {
        if (0x8453 < param_2) {
          if (param_2 == 0x845b) {
            uVar2 = *(ushort *)(*(int *)(param_1 + 0x4a60) + 0x98) & 0xffff7fff;
          }
          else if (param_2 < 0x845c) {
            if (param_2 == 0x8457) {
              uVar2 = *(uint *)(*(int *)(param_1 + 0x4a60) + 0x334) >> 0x13 & 1;
            }
            else if (param_2 < 0x8458) {
              if (param_2 == 0x8454) {
                uVar2 = (uint)*(ushort *)(*(int *)(param_1 + 0x4a60) + 0x80);
              }
              else {
                if (param_2 != 0x8455) {
                  return 0;
                }
                uVar2 = *(uint *)(*(int *)(param_1 + 0x4a60) + 0x7c);
              }
            }
            else {
              if (param_2 == 0x8459) {
                iVar13 = 4;
                *param_3 = (double)*(float *)(param_1 + 0x2c0);
                param_3[1] = (double)*(float *)(param_1 + 0x2c4);
                fVar1 = *(float *)(param_1 + 0x2c8);
                *(uint *)(param_3 + 3) = 0x3ff00000;
                *(uint *)((int)param_3 + 0x1c) = 0;
                param_3[2] = (double)fVar1;
                goto LAB_00015a90;
              }
              if (param_2 != 0x845a) {
                return 0;
              }
              uVar2 = (uint)*(short *)(*(int *)(param_1 + 0x4a60) + 0x9a);
            }
          }
          else {
            if (param_2 == 0x846d) {
              uVar2 = (uint)(int)*(float *)(*(int *)(param_1 + 0x468c) + 0x60);
              *(uint *)param_3 = uVar2;
              fVar1 = *(float *)(*(int *)(param_1 + 0x468c) + 100);
LAB_00014828:
              *(int *)(param_3 + 1) = (int)fVar1;
              if (uVar2 == 0) {
                *(uint *)param_3 = 1;
              }
              return 2;
            }
            if (0x846d < param_2) {
              if (param_2 == 0x84e0) {
                iVar13 = *(int *)(param_1 + 0x53d4);
              }
              else {
                if (param_2 < 0x84e1) {
                  if (param_2 != 0x846e) {
                    return 0;
                  }
                  uVar2 = (uint)(int)*(float *)(*(int *)(param_1 + 0x468c) + 0x6c);
                  *(uint *)param_3 = uVar2;
                  fVar1 = *(float *)(*(int *)(param_1 + 0x468c) + 0x70);
                  goto LAB_00014828;
                }
                iVar13 = *(int *)(param_1 + 0x53d8);
              }
              uVar2 = iVar13 + 0x84c0;
              goto LAB_00015efc;
            }
            if (param_2 == 0x845c) {
              uVar2 = *(uint *)(*(int *)(param_1 + 0x4a60) + 0x94);
            }
            else {
              if (param_2 != 0x845e) {
                return 0;
              }
              uVar2 = *(uint *)(*(int *)(param_1 + 0x4a60) + 0x334) >> 0x14 & 1;
            }
          }
          goto LAB_00015f48;
        }
        if (param_2 == 0x81a8) {
          uVar2 = *(uint *)(param_1 + 0x4984);
          goto LAB_00015f48;
        }
        if (0x81a8 < param_2) {
          if (param_2 == 0x81fb) {
            uVar2 = *(uint *)(*(int *)(param_1 + 0x53d4) * 0x7c + param_1 + 0x3534) >> 8 & 1;
            goto LAB_00015f48;
          }
          if (param_2 < 0x81fc) {
            if (param_2 == 0x81a9) {
              uVar2 = *(uint *)(param_1 + 0x4988);
            }
            else {
              if (param_2 != 0x81f8) {
                return 0;
              }
              uVar2 = (uint)*(ushort *)(param_1 + 0x30a8);
            }
            goto LAB_00015f48;
          }
          if (param_2 != 0x8406) {
            if (param_2 < 0x8407) {
              if (param_2 != 0x8200) {
                return 0;
              }
              uVar2 = (uint)*(byte *)(param_1 + 0x466c);
            }
            else {
              if (param_2 != 0x8450) {
                return 0;
              }
              uVar2 = (uint)*(ushort *)(param_1 + 0x3166);
            }
            goto LAB_00015f48;
          }
          iVar13 = *(int *)(param_1 + 0x4854);
          *param_3 = (double)*(float *)(iVar13 + -0x1c0);
          param_3[1] = (double)*(float *)(iVar13 + -0x1bc);
          fVar1 = *(float *)(iVar13 + -0x1b8);
LAB_00015d40:
          iVar13 = 3;
          param_3[2] = (double)fVar1;
          goto LAB_00015d48;
        }
        if (param_2 == 0x8128) {
          dVar14 = (double)*(float *)(param_1 + 0x3428);
        }
        else {
          if (0x8128 < param_2) {
            if (param_2 != 0x8129) {
              if (param_2 != 0x8192) {
                return 0;
              }
              uVar2 = (uint)*(ushort *)(param_1 + 0x3178);
              goto LAB_00015f48;
            }
            *param_3 = (double)*(float *)(param_1 + 0x342c);
            param_3[1] = (double)*(float *)(param_1 + 0x3430);
            fVar1 = *(float *)(param_1 + 0x3434);
            goto LAB_00015d40;
          }
          if (param_2 == 0x8126) {
            dVar14 = (double)*(float *)(param_1 + 0x3420);
          }
          else {
            if (param_2 != 0x8127) {
              return 0;
            }
            dVar14 = (double)*(float *)(param_1 + 0x3424);
          }
        }
      }
    }
    goto LAB_0001467c;
  }
  if (param_2 == 0xc61) {
    if (7 < *(int *)(param_1 + 0x53d4)) {
      return -1;
    }
    uVar2 = (uint)*(byte *)(*(int *)(param_1 + 0x53d4) * 0x94 + param_1 + 0x3d79);
    goto LAB_00015f48;
  }
  if (0xc61 < param_2) {
    if (param_2 == 0xd3b) {
      uVar2 = 0x10;
      goto LAB_00015f48;
    }
    if (param_2 < 0xd3c) {
      if (param_2 == 0xd11) {
        uVar2 = *(uint *)(param_1 + 0x3414) >> 1 & 1;
        goto LAB_00015f48;
      }
      if (param_2 < 0xd12) {
        if (param_2 == 0xcf0) {
          uVar2 = (uint)*(byte *)(param_1 + 0x31e4);
        }
        else if (param_2 < 0xcf1) {
          if (param_2 == 0xcb3) {
            uVar2 = *(uint *)(param_1 + 0x327c);
          }
          else if (param_2 < 0xcb4) {
            if (param_2 == 0xcb0) {
              uVar2 = *(uint *)(param_1 + 0x3270);
            }
            else if (param_2 < 0xcb1) {
              if (param_2 == 0xc62) {
                if (7 < *(int *)(param_1 + 0x53d4)) {
                  return -1;
                }
                uVar2 = (uint)*(byte *)(*(int *)(param_1 + 0x53d4) * 0x94 + param_1 + 0x3d7a);
              }
              else {
                if (param_2 != 0xc63) {
                  return 0;
                }
                if (7 < *(int *)(param_1 + 0x53d4)) {
                  return -1;
                }
                uVar2 = (uint)*(byte *)(*(int *)(param_1 + 0x53d4) * 0x94 + param_1 + 0x3d7b);
              }
            }
            else if (param_2 == 0xcb1) {
              uVar2 = *(uint *)(param_1 + 0x3274);
            }
            else {
              if (param_2 != 0xcb2) {
                return 0;
              }
              uVar2 = *(uint *)(param_1 + 0x3278);
            }
          }
          else if (param_2 == 0xcb6) {
            uVar2 = *(uint *)(param_1 + 0x3288);
          }
          else if (param_2 < 0xcb7) {
            if (param_2 == 0xcb4) {
              uVar2 = *(uint *)(param_1 + 0x3280);
            }
            else {
              if (param_2 != 0xcb5) {
                return 0;
              }
              uVar2 = *(uint *)(param_1 + 0x3284);
            }
          }
          else if (param_2 == 0xcb8) {
            uVar2 = *(uint *)(param_1 + 0x3290);
          }
          else if (param_2 < 0xcb8) {
            uVar2 = *(uint *)(param_1 + 0x328c);
          }
          else {
            if (param_2 != 0xcb9) {
              return 0;
            }
            uVar2 = *(uint *)(param_1 + 0x3294);
          }
        }
        else if (param_2 == 0xd00) {
          uVar2 = (uint)*(byte *)(param_1 + 0x31c8);
        }
        else if (param_2 < 0xd01) {
          if (param_2 == 0xcf3) {
            uVar2 = *(uint *)(param_1 + 0x31d4);
          }
          else if (param_2 < 0xcf4) {
            if (param_2 == 0xcf1) {
              uVar2 = (uint)*(byte *)(param_1 + 0x31e5);
            }
            else {
              if (param_2 != 0xcf2) {
                return 0;
              }
              uVar2 = *(uint *)(param_1 + 0x31cc);
            }
          }
          else if (param_2 == 0xcf4) {
            uVar2 = *(uint *)(param_1 + 0x31d8);
          }
          else {
            if (param_2 != 0xcf5) {
              return 0;
            }
            uVar2 = *(uint *)(param_1 + 0x31e0);
          }
        }
        else if (param_2 == 0xd03) {
          uVar2 = *(uint *)(param_1 + 0x31b8);
        }
        else if (param_2 < 0xd04) {
          if (param_2 == 0xd01) {
            uVar2 = (uint)*(byte *)(param_1 + 0x31c9);
          }
          else {
            if (param_2 != 0xd02) {
              return 0;
            }
            uVar2 = *(uint *)(param_1 + 0x31b0);
          }
        }
        else if (param_2 == 0xd05) {
          uVar2 = *(uint *)(param_1 + 0x31c4);
        }
        else if (param_2 < 0xd05) {
          uVar2 = *(uint *)(param_1 + 0x31bc);
        }
        else {
          if (param_2 != 0xd10) {
            return 0;
          }
          uVar2 = *(uint *)(param_1 + 0x3414) & 1;
        }
        goto LAB_00015f48;
      }
      if (param_2 == 0xd1e) {
        dVar14 = (double)*(float *)(param_1 + 0x320c);
      }
      else if (param_2 < 0xd1f) {
        if (param_2 == 0xd17) {
          dVar14 = (double)*(float *)(param_1 + 0x31ac);
        }
        else if (param_2 < 0xd18) {
          if (param_2 == 0xd14) {
            dVar14 = (double)*(float *)(param_1 + 0x31ec);
          }
          else {
            if (param_2 < 0xd15) {
              if (param_2 == 0xd12) {
                uVar2 = *(uint *)(param_1 + 0x3214);
              }
              else {
                if (param_2 != 0xd13) {
                  return 0;
                }
                uVar2 = *(uint *)(param_1 + 0x3210);
              }
              goto LAB_00015f48;
            }
            if (param_2 == 0xd15) {
              dVar14 = (double)*(float *)(param_1 + 0x31e8);
            }
            else {
              if (param_2 != 0xd16) {
                return 0;
              }
              dVar14 = (double)*(float *)(param_1 + 0x31a8);
            }
          }
        }
        else if (param_2 == 0xd1a) {
          dVar14 = (double)*(float *)(param_1 + 0x31fc);
        }
        else if (param_2 < 0xd1b) {
          if (param_2 == 0xd18) {
            dVar14 = (double)*(float *)(param_1 + 0x31f4);
          }
          else {
            if (param_2 != 0xd19) {
              return 0;
            }
            dVar14 = (double)*(float *)(param_1 + 0x31f0);
          }
        }
        else if (param_2 == 0xd1c) {
          dVar14 = (double)*(float *)(param_1 + 0x3204);
        }
        else if (param_2 < 0xd1d) {
          dVar14 = (double)*(float *)(param_1 + 0x31f8);
        }
        else {
          dVar14 = (double)*(float *)(param_1 + 0x3200);
        }
      }
      else {
        if (param_2 == 0xd34) {
          uVar2 = 0x100;
          goto LAB_00015f48;
        }
        if (0xd34 < param_2) {
          if (param_2 == 0xd37) {
            uVar2 = 100;
          }
          else if (param_2 < 0xd38) {
            if (param_2 == 0xd35) {
              uVar2 = 0x10;
            }
            else {
              if (param_2 != 0xd36) {
                return 0;
              }
              uVar2 = 0x20;
            }
          }
          else if (param_2 == 0xd39) {
            uVar2 = 5;
          }
          else {
            if (0xd39 < param_2) {
              *(uint *)param_3 = *(uint *)(*(int *)(param_1 + 0x468c) + 0xc);
              uVar2 = *(uint *)(*(int *)(param_1 + 0x468c) + 0x10);
              goto LAB_00015638;
            }
            uVar2 = 5;
          }
          goto LAB_00015f48;
        }
        if (param_2 == 0xd31) {
          uVar2 = 8;
          goto LAB_00015f48;
        }
        if (0xd31 < param_2) {
          if (param_2 == 0xd32) {
            uVar2 = 6;
          }
          else {
            if (param_2 != 0xd33) {
              return 0;
            }
            uVar2 = (uint)*(ushort *)(*(int *)(param_1 + 0x468c) + 0xbc);
          }
          goto LAB_00015f48;
        }
        if (param_2 != 0xd1f) {
          if (param_2 != 0xd30) {
            return 0;
          }
          uVar2 = 10;
          goto LAB_00015f48;
        }
        dVar14 = (double)*(float *)(param_1 + 0x3208);
      }
    }
    else {
      if (param_2 == 0xdb2) {
        uVar2 = (uint)*(byte *)(param_1 + 0x74ed);
        goto LAB_00015f48;
      }
      if (param_2 < 0xdb3) {
        if (param_2 == 0xd70) {
          uVar2 = (*(int *)(param_1 + 0x4fbc) - param_1) + -0x4e2c >> 2;
          goto LAB_00015efc;
        }
        if (0xd70 < param_2) {
          if (param_2 == 0xd94) {
            uVar2 = (uint)*(byte *)(param_1 + 0x74e6);
          }
          else if (param_2 < 0xd95) {
            if (param_2 == 0xd91) {
              uVar2 = (uint)*(byte *)(param_1 + 0x74e3);
            }
            else if (param_2 < 0xd92) {
              if (param_2 == 0xd80) {
                uVar2 = (uint)*(byte *)(param_1 + 0x74f2);
              }
              else {
                if (param_2 != 0xd90) {
                  return 0;
                }
                uVar2 = (uint)*(byte *)(param_1 + 0x74e2);
              }
            }
            else if (param_2 == 0xd92) {
              uVar2 = (uint)*(byte *)(param_1 + 0x74e4);
            }
            else {
              if (param_2 != 0xd93) {
                return 0;
              }
              uVar2 = (uint)*(byte *)(param_1 + 0x74e5);
            }
          }
          else if (param_2 == 0xd97) {
            uVar2 = (uint)*(byte *)(param_1 + 0x74e0);
          }
          else if (param_2 < 0xd98) {
            if (param_2 == 0xd95) {
              uVar2 = (uint)*(byte *)(param_1 + 0x74e7);
            }
            else {
              if (param_2 != 0xd96) {
                return 0;
              }
              uVar2 = (uint)*(byte *)(param_1 + 0x74e8);
            }
          }
          else if (param_2 == 0xdb0) {
            uVar2 = (uint)*(byte *)(param_1 + 0x74eb);
          }
          else if (param_2 < 0xdb1) {
            if (param_2 != 0xd98) {
              return 0;
            }
            uVar2 = (uint)*(byte *)(param_1 + 0x74e1);
          }
          else {
            uVar2 = (uint)*(byte *)(param_1 + 0x74ec);
          }
          goto LAB_00015f48;
        }
        if (param_2 == 0xd55) {
          iVar13 = *(int *)(param_1 + 0x744c);
          if (iVar13 == 0) {
            uVar2 = *(uint *)(*(int *)(param_1 + 0x468c) + 0x38);
            goto LAB_00015f48;
          }
          iVar11 = 0;
          piVar5 = (int *)(iVar13 + 0xd4);
          do {
            iVar3 = *piVar5;
            piVar5 = piVar5 + 1;
            if (iVar3 != 0) break;
            iVar11 = iVar11 + 1;
          } while (iVar11 < 4);
          uVar2 = 0;
          if (iVar11 == 4) goto LAB_00015f48;
          iVar3 = iVar11 * 0x18 + iVar13;
          iVar11 = *(int *)(iVar11 * 4 + iVar13 + 0xd4) + 0x10;
          uVar9 = *(undefined4 *)(iVar3 + 0x38);
          iVar13 = (uint)*(byte *)(param_1 + 0x85a8) << 2;
          uVar10 = 0x805f;
        }
        else {
          if (0xd55 < param_2) {
            if (param_2 == 0xd58) {
              uVar2 = *(uint *)(*(int *)(param_1 + 0x468c) + 0x44);
              goto LAB_00015f48;
            }
            if (0xd58 < param_2) {
              if (param_2 == 0xd5a) {
                uVar2 = *(uint *)(*(int *)(param_1 + 0x468c) + 0x4c);
              }
              else if (param_2 < 0xd5a) {
                uVar2 = *(uint *)(*(int *)(param_1 + 0x468c) + 0x48);
              }
              else {
                if (param_2 != 0xd5b) {
                  return 0;
                }
                uVar2 = *(uint *)(*(int *)(param_1 + 0x468c) + 0x50);
              }
              goto LAB_00015f48;
            }
            if (param_2 != 0xd56) {
              if (param_2 != 0xd57) {
                return 0;
              }
              iVar13 = *(int *)(param_1 + 0x744c);
              if (iVar13 == 0) {
                uVar2 = *(uint *)(*(int *)(param_1 + 0x468c) + 0x40);
                goto LAB_00015f48;
              }
              uVar2 = 0;
              if (*(int *)(iVar13 + 0xe8) == 0) goto LAB_00015450;
              pcVar12 = *(code **)(param_1 + 0x479c);
              uVar9 = *(undefined4 *)(iVar13 + 0xb0);
              uVar7 = *(undefined4 *)
                       (*(int *)(iVar13 + 0xe8) + 0x10 + (uint)*(byte *)(param_1 + 0x85a8) * 4);
              uVar10 = 0x884a;
              uVar6 = *(undefined4 *)(param_1 + 0x4688);
              uVar8 = *(undefined4 *)(iVar13 + 0xac);
              goto LAB_00015488;
            }
            iVar13 = *(int *)(param_1 + 0x744c);
            if (iVar13 == 0) {
              uVar2 = *(uint *)(*(int *)(param_1 + 0x468c) + 0x3c);
              goto LAB_00015f48;
            }
            uVar2 = 0;
            if (*(int *)(iVar13 + 0xe4) != 0) {
              pcVar12 = *(code **)(param_1 + 0x479c);
              uVar9 = *(undefined4 *)(iVar13 + 0x98);
              uVar7 = *(undefined4 *)
                       (*(int *)(iVar13 + 0xe4) + 0x10 + (uint)*(byte *)(param_1 + 0x85a8) * 4);
              uVar10 = 0x884a;
              uVar6 = *(undefined4 *)(param_1 + 0x4688);
              uVar8 = *(undefined4 *)(iVar13 + 0x94);
              goto LAB_00015488;
            }
            goto LAB_00015450;
          }
          if (param_2 == 0xd52) {
            iVar13 = *(int *)(param_1 + 0x744c);
            if (iVar13 == 0) {
              uVar2 = *(uint *)(*(int *)(param_1 + 0x468c) + 0x2c);
              goto LAB_00015f48;
            }
            iVar11 = 0;
            piVar5 = (int *)(iVar13 + 0xd4);
            do {
              iVar3 = *piVar5;
              piVar5 = piVar5 + 1;
              if (iVar3 != 0) break;
              iVar11 = iVar11 + 1;
            } while (iVar11 < 4);
            uVar2 = 0;
            if (iVar11 == 4) goto LAB_00015f48;
            iVar3 = iVar11 * 0x18 + iVar13;
            iVar11 = *(int *)(iVar11 * 4 + iVar13 + 0xd4) + 0x10;
            uVar9 = *(undefined4 *)(iVar3 + 0x38);
            iVar13 = (uint)*(byte *)(param_1 + 0x85a8) << 2;
            uVar10 = 0x805c;
          }
          else {
            if (param_2 < 0xd53) {
              if (param_2 == 0xd50) {
                uVar2 = *(uint *)(*(int *)(param_1 + 0x468c) + 8);
              }
              else {
                if (param_2 != 0xd51) {
                  return 0;
                }
                uVar2 = *(uint *)(*(int *)(param_1 + 0x468c) + 0x28);
              }
              goto LAB_00015f48;
            }
            if (param_2 == 0xd53) {
              iVar13 = *(int *)(param_1 + 0x744c);
              if (iVar13 == 0) {
                uVar2 = *(uint *)(*(int *)(param_1 + 0x468c) + 0x30);
                goto LAB_00015f48;
              }
              iVar11 = 0;
              piVar5 = (int *)(iVar13 + 0xd4);
              do {
                iVar3 = *piVar5;
                piVar5 = piVar5 + 1;
                if (iVar3 != 0) break;
                iVar11 = iVar11 + 1;
              } while (iVar11 < 4);
              uVar2 = 0;
              if (iVar11 == 4) goto LAB_00015f48;
              iVar3 = iVar11 * 0x18 + iVar13;
              iVar11 = *(int *)(iVar11 * 4 + iVar13 + 0xd4) + 0x10;
              uVar9 = *(undefined4 *)(iVar3 + 0x38);
              iVar13 = (uint)*(byte *)(param_1 + 0x85a8) << 2;
              uVar10 = 0x805d;
            }
            else {
              if (param_2 != 0xd54) {
                return 0;
              }
              iVar13 = *(int *)(param_1 + 0x744c);
              if (iVar13 == 0) {
                uVar2 = *(uint *)(*(int *)(param_1 + 0x468c) + 0x34);
                goto LAB_00015f48;
              }
              iVar11 = 0;
              piVar5 = (int *)(iVar13 + 0xd4);
              do {
                iVar3 = *piVar5;
                piVar5 = piVar5 + 1;
                if (iVar3 != 0) break;
                iVar11 = iVar11 + 1;
              } while (iVar11 < 4);
              uVar2 = 0;
              if (iVar11 == 4) goto LAB_00015f48;
              iVar3 = iVar11 * 0x18 + iVar13;
              iVar11 = *(int *)(iVar11 * 4 + iVar13 + 0xd4) + 0x10;
              uVar9 = *(undefined4 *)(iVar3 + 0x38);
              iVar13 = (uint)*(byte *)(param_1 + 0x85a8) << 2;
              uVar10 = 0x805e;
            }
          }
        }
        uVar7 = *(undefined4 *)(iVar11 + iVar13);
        pcVar12 = *(code **)(param_1 + 0x479c);
        uVar6 = *(undefined4 *)(param_1 + 0x4688);
        uVar8 = *(undefined4 *)(iVar3 + 0x34);
LAB_00015488:
        (*pcVar12)(uVar6,uVar7,uVar8,uVar9,uVar10,param_3);
        return 1;
      }
      if (param_2 == 0xdf1) {
        uVar2 = *(uint *)(param_1 + 0x4fd4);
        goto LAB_00015f48;
      }
      if (param_2 < 0xdf2) {
        if (param_2 == 0xdb8) {
          uVar2 = (uint)*(byte *)(param_1 + 0x74ea);
          goto LAB_00015f48;
        }
        if (param_2 < 0xdb9) {
          if (param_2 == 0xdb5) {
            uVar2 = (uint)*(byte *)(param_1 + 0x74f0);
          }
          else if (param_2 < 0xdb6) {
            if (param_2 == 0xdb3) {
              uVar2 = (uint)*(byte *)(param_1 + 0x74ee);
            }
            else {
              if (param_2 != 0xdb4) {
                return 0;
              }
              uVar2 = (uint)*(byte *)(param_1 + 0x74ef);
            }
          }
          else if (param_2 == 0xdb6) {
            uVar2 = (uint)*(byte *)(param_1 + 0x74f1);
          }
          else {
            if (param_2 != 0xdb7) {
              return 0;
            }
            uVar2 = (uint)*(byte *)(param_1 + 0x74e9);
          }
          goto LAB_00015f48;
        }
        if (param_2 == 0xdd2) {
          *param_3 = (double)*(float *)(param_1 + 0x74bc);
          param_3[1] = (double)*(float *)(param_1 + 0x74c0);
          param_3[2] = (double)*(float *)(param_1 + 0x74cc);
          dVar14 = (double)*(float *)(param_1 + 0x74d0);
          goto LAB_00014704;
        }
        if (0xdd2 < param_2) {
          if (param_2 == 0xde0) {
            uVar2 = *(uint *)(*(int *)(param_1 + 0x53d4) * 0x7c + param_1 + 0x3534) >> 4 & 1;
            goto LAB_00015f48;
          }
          if (0xde0 < param_2) {
            if (param_2 != 0xde1) {
              return 0;
            }
            uVar2 = *(uint *)(*(int *)(param_1 + 0x53d4) * 0x7c + param_1 + 0x3534) >> 3 & 1;
            goto LAB_00015f48;
          }
          if (param_2 != 0xdd3) {
            return 0;
          }
          *param_3 = (double)CONCAT44(0x43300000,*(uint *)(param_1 + 0x74b8) ^ 0x80000000) -
                     DOUBLE_00108d58;
          dVar14 = (double)CONCAT44(0x43300000,*(uint *)(param_1 + 0x74c8) ^ 0x80000000) - dVar14;
          goto LAB_00014860;
        }
        if (param_2 == 0xdd0) {
          *param_3 = (double)*(float *)(param_1 + 0x74ac);
          dVar14 = (double)*(float *)(param_1 + 0x74b0);
          goto LAB_00015cf4;
        }
        if (param_2 != 0xdd1) {
          return 0;
        }
        dVar14 = (double)CONCAT44(0x43300000,
                                  *(uint *)(0x74a4 + param_1 + 4) ^ 0x80000000) -
                 DOUBLE_00108d58;
      }
      else {
        if (param_2 == 0x2a02) {
          uVar2 = (uint)*(byte *)(param_1 + 0x34dc);
          goto LAB_00015f48;
        }
        if (0x2a02 < param_2) {
          if (param_2 < 0x4008) {
            if (param_2 < 0x4000) {
              if (5 < param_2 - 0x3000) {
                return 0;
              }
              uVar2 = *(uint *)(param_1 + 0x4188) >> (param_2 - 0x3000 & 0x3f) & 1;
            }
            else {
              uVar2 = *(uint *)(param_1 + 0x30a0) >> (param_2 - 0x4000 & 0x3f) & 1;
            }
          }
          else if (param_2 == 0x6090) {
            uVar2 = (uint)*(byte *)(param_1 + 0x280c);
          }
          else {
            if (param_2 != 0x6091) {
              return 0;
            }
            uVar2 = *(uint *)(*(int *)(param_1 + 0x468c) + 0x9c);
          }
          goto LAB_00015f48;
        }
        if (param_2 == 0x1700) {
LAB_00014c74:
          iVar13 = param_1 + 0x1cc0;
          goto LAB_00014c84;
        }
        if (param_2 < 0x1701) {
          if (param_2 == 0xdf2) {
            uVar2 = *(uint *)(param_1 + 0x4fd8);
          }
          else {
            if (param_2 != 0xdf4) {
              return 0;
            }
            uVar2 = *(uint *)(param_1 + 0x4e28);
          }
          goto LAB_00015f48;
        }
        if (param_2 != 0x2a00) {
          if (param_2 != 0x2a01) {
            return 0;
          }
          uVar2 = (uint)*(byte *)(param_1 + 0x34db);
          goto LAB_00015f48;
        }
        dVar14 = (double)*(float *)(param_1 + 0x34cc);
      }
    }
    goto LAB_0001467c;
  }
  if (param_2 == 0xb74) {
    uVar2 = (uint)*(ushort *)(param_1 + 0x3124);
    goto LAB_00015f48;
  }
  if (param_2 < 0xb75) {
    if (param_2 == 0xb40) {
      *(uint *)param_3 = (uint)*(ushort *)(param_1 + 0x34d0);
      uVar2 = (uint)*(ushort *)(param_1 + 0x34d2);
LAB_00015638:
      *(uint *)(param_3 + 1) = uVar2;
      return 2;
    }
    if (param_2 < 0xb41) {
      if (param_2 == 0xb12) {
        *param_3 = (double)*(float *)(*(int *)(param_1 + 0x468c) + 0x60);
        dVar14 = (double)*(float *)(*(int *)(param_1 + 0x468c) + 100);
LAB_00014860:
        iVar13 = 2;
        param_3[1] = dVar14;
        goto LAB_00015d48;
      }
      if (0xb12 < param_2) {
        if (param_2 == 0xb24) {
          uVar2 = (uint)*(byte *)(param_1 + 0x318c);
          goto LAB_00015f48;
        }
        if (0xb24 < param_2) {
          if (param_2 == 0xb30) {
            uVar2 = *(uint *)(param_1 + 0x5408);
          }
          else if (param_2 < 0xb31) {
            if (param_2 == 0xb25) {
              uVar2 = (uint)*(ushort *)(param_1 + 0x3188);
            }
            else {
              if (param_2 != 0xb26) {
                return 0;
              }
              uVar2 = *(uint *)(param_1 + 0x3184);
            }
          }
          else if (param_2 == 0xb32) {
            uVar2 = *(uint *)(param_1 + 0x5404);
          }
          else {
            uVar2 = 0x40;
            if (0xb31 < param_2) {
              if (param_2 != 0xb33) {
                return 0;
              }
              uVar2 = 0;
              if (*(int *)(param_1 + 0x5408) != 0) {
                uVar2 = *(uint *)(*(int *)(param_1 + 0x53e8) + 4);
              }
            }
          }
          goto LAB_00015f48;
        }
        if (param_2 == 0xb21) {
          uVar2 = (uint)(int)*(float *)(param_1 + 0x3180);
          goto LAB_00015f48;
        }
        if (param_2 < 0xb22) {
          if (param_2 != 0xb13) {
            if (param_2 != 0xb20) {
              return 0;
            }
            uVar2 = (uint)*(byte *)(param_1 + 0x318d);
            goto LAB_00015f48;
          }
          dVar14 = (double)*(float *)(*(int *)(param_1 + 0x468c) + 0x68);
        }
        else {
          if (param_2 == 0xb22) {
            *param_3 = (double)*(float *)(*(int *)(param_1 + 0x468c) + 0x6c);
            dVar14 = (double)*(float *)(*(int *)(param_1 + 0x468c) + 0x70);
            goto LAB_00014860;
          }
          if (param_2 != 0xb23) {
            return 0;
          }
          dVar14 = (double)*(float *)(*(int *)(param_1 + 0x468c) + 0x74);
        }
        goto LAB_0001467c;
      }
      if (param_2 == 0xb05) {
        *(uint *)param_3 = 0x3ff00000;
        *(uint *)((int)param_3 + 4) = 0;
        goto LAB_00015d48;
      }
      if (0xb05 < param_2) {
        if (param_2 == 0xb08) {
          uVar2 = (uint)*(byte *)(param_1 + 0x2ef);
          goto LAB_00015f48;
        }
        if (0xb08 < param_2) {
          if (param_2 == 0xb10) {
            uVar2 = (uint)*(byte *)(param_1 + 0x343c);
            goto LAB_00015f48;
          }
          if (0xb10 < param_2) {
            uVar2 = (uint)(int)*(float *)(param_1 + 0x341c);
            goto LAB_00015f48;
          }
          if (param_2 != 0xb09) {
            return 0;
          }
          dVar14 = (double)*(float *)(*(int *)(param_1 + 0x4854) + -0x1d8);
          goto LAB_0001467c;
        }
        if (param_2 == 0xb06) {
          if (7 < *(int *)(param_1 + 0x53d4)) {
            return -1;
          }
          iVar13 = *(int *)(param_1 + 0x53d4) * 0x10 + *(int *)(param_1 + 0x4854) + -0x200;
          *param_3 = (double)*(float *)(iVar13 + 0x80);
          param_3[1] = (double)*(float *)(iVar13 + 0x84);
          param_3[2] = (double)*(float *)(iVar13 + 0x88);
          dVar14 = (double)*(float *)(iVar13 + 0x8c);
        }
        else {
          if (param_2 != 0xb07) {
            return 0;
          }
          iVar13 = *(int *)(param_1 + 0x4854);
          *param_3 = (double)*(float *)(param_1 + 0x2e0);
          param_3[1] = (double)*(float *)(param_1 + 0x2e4);
          param_3[2] = (double)*(float *)(param_1 + 0x2e8);
          dVar14 = (double)*(float *)(iVar13 + -0x1e4);
        }
LAB_00014704:
        iVar13 = 4;
        param_3[3] = dVar14;
        goto LAB_00015d48;
      }
      if (param_2 == 0xb02) {
        iVar13 = 3;
        *param_3 = (double)*(float *)(param_1 + 0x2b0);
        param_3[1] = (double)*(float *)(param_1 + 0x2b4);
        param_3[2] = (double)*(float *)(param_1 + 0x2b8);
        goto LAB_00015a90;
      }
      if (param_2 < 0xb03) {
        if (param_2 != 0xb00) {
          if (param_2 != 0xb01) {
            return 0;
          }
          dVar14 = (double)*(float *)(param_1 + 700);
          goto LAB_00014670;
        }
        *param_3 = (double)*(float *)(param_1 + 0x2a0);
        param_3[1] = (double)*(float *)(param_1 + 0x2a4);
        param_3[2] = (double)*(float *)(param_1 + 0x2a8);
        dVar14 = (double)*(float *)(param_1 + 0x2ac);
      }
      else {
        if (param_2 == 0xb03) {
          if (7 < *(int *)(param_1 + 0x53d4)) {
            return -1;
          }
          iVar13 = *(int *)(param_1 + 0x53d4) * 0x10 + param_1;
          *param_3 = (double)*(float *)(iVar13 + 0x120);
          param_3[1] = (double)*(float *)(iVar13 + 0x124);
          param_3[2] = (double)*(float *)(iVar13 + 0x128);
          dVar14 = (double)*(float *)(iVar13 + 300);
          goto LAB_00014704;
        }
        if (param_2 != 0xb04) {
          return 0;
        }
        iVar13 = *(int *)(param_1 + 0x4854);
        *param_3 = (double)*(float *)(iVar13 + -0x1d0);
        param_3[1] = (double)*(float *)(iVar13 + -0x1cc);
        param_3[2] = (double)*(float *)(iVar13 + -0x1c8);
        dVar14 = (double)*(float *)(iVar13 + -0x1c4);
      }
    }
    else {
      if (param_2 == 0xb56) {
        uVar2 = (uint)*(ushort *)(param_1 + 0x30a6);
        goto LAB_00015f48;
      }
      if (0xb56 < param_2) {
        if (param_2 == 0xb64) {
          dVar14 = (double)*(float *)(param_1 + 0x3158);
        }
        else {
          if (0xb64 < param_2) {
            if (param_2 == 0xb70) {
              *param_3 = *(double *)(param_1 + 0x1b90);
              param_3[1] = *(double *)(param_1 + 0x1b98);
              *param_4 = 0x140a;
              *param_5 = 1;
              return 2;
            }
            if (0xb70 < param_2) {
              if (param_2 == 0xb72) {
                uVar2 = (uint)*(byte *)(param_1 + 0x31a4);
                goto LAB_00015f48;
              }
              if (param_2 < 0xb73) {
                uVar2 = (uint)*(byte *)(param_1 + 0x3128);
                goto LAB_00015f48;
              }
              dVar14 = *(double *)(param_1 + 0x30e8);
              goto LAB_00014d74;
            }
            if (param_2 == 0xb65) {
              uVar2 = (uint)*(ushort *)(param_1 + 0x3164);
              goto LAB_00015f48;
            }
            if (param_2 != 0xb66) {
              return 0;
            }
            *param_3 = (double)*(float *)(param_1 + 0x3140);
            param_3[1] = (double)*(float *)(param_1 + 0x3144);
            param_3[2] = (double)*(float *)(param_1 + 0x3148);
            dVar14 = (double)*(float *)(param_1 + 0x314c);
            goto LAB_00015a8c;
          }
          if (param_2 == 0xb61) {
            dVar14 = (double)*(float *)(param_1 + 0x3160);
            goto LAB_00014670;
          }
          if (param_2 < 0xb62) {
            if (param_2 == 0xb57) {
              uVar2 = (uint)*(byte *)(param_1 + 0x30ab);
            }
            else {
              if (param_2 != 0xb60) {
                return 0;
              }
              uVar2 = (uint)*(byte *)(param_1 + 0x316a);
            }
            goto LAB_00015f48;
          }
          if (param_2 == 0xb62) {
            dVar14 = (double)*(float *)(param_1 + 0x3150);
          }
          else {
            if (param_2 != 0xb63) {
              return 0;
            }
            dVar14 = (double)*(float *)(param_1 + 0x3154);
          }
        }
LAB_0001467c:
        *param_3 = dVar14;
LAB_00015d48:
        *param_4 = 0x140a;
        return iVar13;
      }
      if (param_2 == 0xb46) {
        uVar2 = (uint)*(ushort *)(param_1 + 0x34d4);
        goto LAB_00015f48;
      }
      if (param_2 < 0xb47) {
        if (param_2 == 0xb43) {
          uVar2 = (uint)*(byte *)(param_1 + 0x2ec);
        }
        else if (param_2 < 0xb44) {
          if (param_2 == 0xb41) {
            uVar2 = (uint)*(byte *)(param_1 + 0x34d9);
          }
          else {
            if (param_2 != 0xb42) {
              return 0;
            }
            uVar2 = (uint)*(byte *)(param_1 + 0x34d8);
          }
        }
        else if (param_2 == 0xb44) {
          uVar2 = (uint)*(byte *)(param_1 + 0x34da);
        }
        else {
          if (param_2 != 0xb45) {
            return 0;
          }
          uVar2 = (uint)*(ushort *)(param_1 + 0x34d6);
        }
        goto LAB_00015f48;
      }
      if (param_2 == 0xb52) {
        uVar2 = (uint)*(byte *)(param_1 + 0x30ac);
        goto LAB_00015f48;
      }
      if (param_2 < 0xb53) {
        if (param_2 == 0xb50) {
          uVar2 = (uint)*(byte *)(param_1 + 0x30aa);
        }
        else {
          if (param_2 != 0xb51) {
            return 0;
          }
          uVar2 = (uint)*(byte *)(param_1 + 0x30ad);
        }
        goto LAB_00015f48;
      }
      if (param_2 == 0xb54) {
        uVar2 = *(uint *)(param_1 + 0x34f4);
        goto LAB_00015f48;
      }
      if (0xb54 < param_2) {
        uVar2 = (uint)*(ushort *)(param_1 + 0x30a4);
        goto LAB_00015f48;
      }
      *param_3 = (double)*(float *)(param_1 + 0x2810);
      param_3[1] = (double)*(float *)(param_1 + 0x2814);
      param_3[2] = (double)*(float *)(param_1 + 0x2818);
      dVar14 = (double)*(float *)(param_1 + 0x281c);
    }
LAB_00015a8c:
    iVar13 = 4;
    param_3[3] = dVar14;
LAB_00015a90:
    *param_4 = 0x140a;
    *param_5 = 1;
    return iVar13;
  }
  if (param_2 == 0xbe0) {
LAB_00014d84:
    uVar2 = (uint)*(ushort *)(param_1 + 0x30ca);
    goto LAB_00015f48;
  }
  if (0xbe0 < param_2) {
    if (param_2 == 0xc22) {
      *param_3 = (double)*(float *)(param_1 + 0x3100);
      param_3[1] = (double)*(float *)(param_1 + 0x3104);
      param_3[2] = (double)*(float *)(param_1 + 0x3108);
      dVar14 = (double)*(float *)(param_1 + 0x310c);
      goto LAB_00015a8c;
    }
    if (0xc22 < param_2) {
      if (param_2 == 0xc40) {
        uVar2 = *(uint *)(param_1 + 0x4e1c);
      }
      else if (param_2 < 0xc41) {
        if (param_2 == 0xc31) {
          uVar2 = 1;
        }
        else if (param_2 < 0xc32) {
          if (param_2 == 0xc23) {
            *(uint *)param_3 = (uint)*(byte *)(param_1 + 0x31a0);
            *(uint *)(param_3 + 1) = (uint)*(byte *)(param_1 + 0x31a1);
            *(uint *)(param_3 + 2) = (uint)*(byte *)(param_1 + 0x31a2);
            uVar2 = (uint)*(byte *)(param_1 + 0x31a3);
            goto LAB_00014ed8;
          }
          if (param_2 != 0xc30) {
            return 0;
          }
          uVar2 = 0;
        }
        else if (param_2 == 0xc32) {
          uVar2 = (uint)*(byte *)(param_1 + 0x7582);
        }
        else {
          if (param_2 != 0xc33) {
            return 0;
          }
          uVar2 = (uint)*(byte *)(*(int *)(param_1 + 0x468c) + 0x26);
        }
      }
      else if (param_2 == 0xc52) {
        uVar2 = (uint)*(ushort *)(0x3170 + param_1);
      }
      else if (param_2 < 0xc53) {
        if (param_2 == 0xc50) {
          uVar2 = (uint)*(ushort *)(param_1 + 0x316c);
        }
        else {
          if (param_2 != 0xc51) {
            return 0;
          }
          uVar2 = (uint)*(ushort *)(param_1 + 0x316e);
        }
      }
      else if (param_2 == 0xc54) {
        uVar2 = (uint)*(ushort *)(param_1 + 0x3174);
      }
      else if (param_2 < 0xc54) {
        uVar2 = (uint)*(ushort *)(param_1 + 0x3172);
      }
      else {
        if (param_2 != 0xc60) {
          return 0;
        }
        if (7 < *(int *)(param_1 + 0x53d4)) {
          return -1;
        }
        uVar2 = (uint)*(byte *)(*(int *)(param_1 + 0x53d4) * 0x94 + param_1 + 0x3d78);
      }
      goto LAB_00015f48;
    }
    if (param_2 == 0xc00) {
      uVar2 = *(uint *)(*(int *)(param_1 + 0x468c) + 0x54);
      goto LAB_00015f48;
    }
    if (param_2 < 0xc01) {
      if (param_2 == 0xbf0) {
        uVar2 = (uint)*(ushort *)(param_1 + 0x3190);
        goto LAB_00015f48;
      }
      if (0xbf0 < param_2) {
        if (param_2 == 0xbf1) {
          uVar2 = (uint)*(byte *)(param_1 + 0x3192);
        }
        else {
          if (param_2 != 0xbf2) {
            return 0;
          }
          uVar2 = (uint)*(byte *)(param_1 + 0x3193);
        }
        goto LAB_00015f48;
      }
      if (param_2 != 0xbe1) {
        if (param_2 != 0xbe2) {
          return 0;
        }
        uVar2 = (uint)*(byte *)(param_1 + 0x30e4);
        goto LAB_00015f48;
      }
LAB_00014d8c:
      uVar2 = (uint)*(ushort *)(param_1 + 0x30c8);
      goto LAB_00015f48;
    }
    if (param_2 == 0xc10) {
      *(uint *)param_3 = *(uint *)(param_1 + 0x34e0);
      *(uint *)(param_3 + 1) = *(uint *)(param_1 + 0x34e4);
      *(uint *)(param_3 + 2) = *(uint *)(param_1 + 0x34e8);
      uVar2 = *(uint *)(param_1 + 0x34ec);
      goto LAB_00014ed8;
    }
    if (param_2 < 0xc11) {
      if (param_2 == 0xc01) {
        if (*(int *)(param_1 + 0x744c) == 0) {
          uVar2 = (uint)*(ushort *)(param_1 + 0x311a);
        }
        else {
          uVar2 = (uint)*(ushort *)(*(int *)(param_1 + 0x744c) + 0xc0);
        }
      }
      else {
        if (param_2 != 0xc02) {
          return 0;
        }
        if (*(int *)(param_1 + 0x744c) == 0) {
          uVar2 = (uint)*(ushort *)(param_1 + 0x3118);
        }
        else {
          uVar2 = (uint)*(ushort *)(*(int *)(param_1 + 0x744c) + 200);
        }
      }
      goto LAB_00015f48;
    }
    if (param_2 != 0xc20) {
      if (param_2 < 0xc21) {
        if (param_2 != 0xc11) {
          return 0;
        }
        uVar2 = (uint)*(byte *)(param_1 + 0x34f0);
      }
      else {
        uVar2 = *(uint *)(param_1 + 0x3194);
      }
      goto LAB_00015f48;
    }
    dVar14 = (double)*(float *)(param_1 + 0x3110);
LAB_00014670:
    dVar14 = dVar14 * DOUBLE_00108d98;
    goto LAB_0001467c;
  }
  if (param_2 == 0xba2) {
    *(uint *)param_3 = *(uint *)(param_1 + 0x1ba0);
    *(uint *)(param_3 + 1) = *(uint *)(param_1 + 0x1ba4);
    *(uint *)(param_3 + 2) = *(uint *)(param_1 + 0x1ba8);
    uVar2 = *(uint *)(param_1 + 0x1bac);
LAB_00014ed8:
    *(uint *)(param_3 + 3) = uVar2;
    return 4;
  }
  if (0xba2 < param_2) {
    if (param_2 == 0xba8) {
      if (7 < *(int *)(param_1 + 0x53d4)) {
        return -1;
      }
      iVar13 = param_1 + *(int *)(param_1 + 0x53d4) * 0x40 + 0x1fc0;
    }
    else {
      if (0xba8 < param_2) {
        if (param_2 == 0xbc0) {
          uVar2 = (uint)*(byte *)(param_1 + 0x30c6);
          goto LAB_00015f48;
        }
        if (param_2 < 0xbc1) {
          if (param_2 == 0xbb0) {
            uVar2 = *(uint *)(param_1 + 0x50fc);
          }
          else {
            if (param_2 != 0xbb1) {
              return 0;
            }
            uVar2 = *(uint *)(param_1 + 0x5144);
          }
          goto LAB_00015f48;
        }
        if (param_2 != 0xbc2) {
          if (param_2 < 0xbc2) {
            uVar2 = (uint)*(ushort *)(param_1 + 0x30c4);
          }
          else {
            if (param_2 != 0xbd0) {
              return 0;
            }
            uVar2 = (uint)*(byte *)(param_1 + 0x313c);
          }
          goto LAB_00015f48;
        }
        dVar14 = (double)*(float *)(param_1 + 0x30c0);
LAB_00014d74:
        *param_3 = dVar14;
        goto LAB_00015a90;
      }
      if (param_2 == 0xba5) {
        if (7 < *(int *)(param_1 + 0x53d4)) {
          return -1;
        }
        iVar13 = *(int *)(*(int *)(param_1 + 0x53d4) * 4 + param_1 + 0x503c);
LAB_00014c5c:
        uVar2 = iVar13 + 1;
LAB_00015450:
        *(uint *)param_3 = uVar2;
        return 1;
      }
      if (param_2 < 0xba6) {
        if (param_2 == 0xba3) {
          iVar13 = *(int *)(param_1 + 0x500c);
        }
        else {
          if (param_2 != 0xba4) {
            return 0;
          }
          iVar13 = *(int *)(param_1 + 0x5008);
        }
LAB_00014bf4:
        uVar2 = iVar13 + 1;
        goto LAB_00015efc;
      }
      if (param_2 == 0xba6) goto LAB_00014c74;
      if (param_2 != 0xba7) {
        return 0;
      }
      iVar13 = param_1 + 0x1c80;
    }
    goto LAB_00014c84;
  }
  if (param_2 == 0xb94) {
    uVar2 = (uint)*(ushort *)((uint)*(byte *)(param_1 + 0x7583) * 0x10 + param_1 + 0x3502);
    goto LAB_00015f48;
  }
  if (param_2 < 0xb95) {
    if (param_2 == 0xb91) {
      uVar2 = *(uint *)(param_1 + 0x3114);
      goto LAB_00015f48;
    }
    if (0xb91 < param_2) {
      if (param_2 == 0xb92) {
        uVar2 = (uint)*(ushort *)((uint)*(byte *)(param_1 + 0x7583) * 0x10 + param_1 + 0x3500);
      }
      else {
        if (param_2 != 0xb93) {
          return 0;
        }
        uVar2 = *(uint *)((uint)*(byte *)(param_1 + 0x7583) * 0x10 + param_1 + 0x34f8);
      }
      goto LAB_00015f48;
    }
    if (param_2 != 0xb80) {
      if (param_2 != 0xb90) {
        return 0;
      }
      uVar2 = *(uint *)(param_1 + 0x3520) >> (*(byte *)(param_1 + 0x7583) & 0x3f) & 1;
      goto LAB_00015f48;
    }
    *param_3 = (double)*(float *)(param_1 + 0x30f0);
    param_3[1] = (double)*(float *)(param_1 + 0x30f4);
    param_3[2] = (double)*(float *)(param_1 + 0x30f8);
    dVar14 = (double)*(float *)(param_1 + 0x30fc);
    goto LAB_00015a8c;
  }
  if (param_2 == 0xb97) {
    uVar2 = *(uint *)((uint)*(byte *)(param_1 + 0x7583) * 0x10 + param_1 + 0x34fc);
    goto LAB_00015f48;
  }
  if (param_2 < 0xb98) {
    if (param_2 == 0xb95) {
      uVar2 = (uint)*(ushort *)((uint)*(byte *)(param_1 + 0x7583) * 0x10 + param_1 + 0x3504);
    }
    else {
      if (param_2 != 0xb96) {
        return 0;
      }
      uVar2 = (uint)*(ushort *)((uint)*(byte *)(param_1 + 0x7583) * 0x10 + param_1 + 0x3506);
    }
    goto LAB_00015f48;
  }
  if (param_2 != 0xba0) {
    if (param_2 < 0xba1) {
      if (param_2 != 0xb98) {
        return 0;
      }
      uVar2 = *(uint *)((uint)*(byte *)(param_1 + 0x7583) * 4 + param_1 + 0x3198);
    }
    else {
      uVar2 = (uint)*(byte *)(param_1 + 0x280d);
    }
    goto LAB_00015f48;
  }
  iVar13 = *(int *)(param_1 + 0x4ff4);
  switch(iVar13) {
  default:
    uVar2 = 0x1702;
    break;
  case 2:
    uVar2 = 0x1800;
    break;
  case 3:
    uVar2 = 0x1701;
    break;
  case 4:
    uVar2 = 0x1700;
    break;
  case 5:
    uVar2 = 0x850a;
    break;
  case 6:
  case 7:
    uVar2 = iVar13 + 0x871c;
    goto LAB_00015efc;
  case 8:
  case 9:
  case 10:
  case 0xb:
  case 0xc:
  case 0xd:
  case 0xe:
  case 0xf:
    uVar2 = iVar13 + 35000;
LAB_00015efc:
    *(uint *)param_3 = uVar2;
    return 1;
  }
LAB_00015f48:
  *(uint *)param_3 = uVar2;
  return 1;
}

/* _glViewport_Exec @ 0x15f6c (136 bytes) */
void _glViewport_Exec(int param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = *(int *)(*(int *)(param_1 + 0x468c) + 0x10);
  iVar1 = *(int *)(*(int *)(param_1 + 0x468c) + 0xc);
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if ((-1 < param_4) && (-1 < param_5)) {
      *(undefined4 *)(param_1 + 0x1ba0) = param_2;
      *(undefined4 *)(param_1 + 0x1ba4) = param_3;
      if (iVar1 < param_4) {
        *(int *)(param_1 + 0x1ba8) = iVar1;
      }
      else {
        *(int *)(param_1 + 0x1ba8) = param_4;
      }
      if (iVar3 < param_5) {
        *(int *)(param_1 + 0x1bac) = iVar3;
      }
      else {
        *(int *)(param_1 + 0x1bac) = param_5;
      }
      ((void (*)())_gleUpdateViewScissorData)(param_1,fparam_1,fparam_2,fparam_3,fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
      return;
    }
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar2 = 0x501;
  }
  else {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar2 = 0x502;
  }
  *(undefined4 *)(param_1 + 0x7574) = uVar2;
  return;
}

/* _glMatrixMode_Exec @ 0x15ff4 (236 bytes) */
int _glMatrixMode_Exec(param_1, param_2)
  int param_1;
  uint param_2;
{
  undefined4 uVar1;
  int iVar2;
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if (param_2 == 0x850a) {
      iVar2 = 5;
      goto LAB_000160d8;
    }
    if (param_2 < 0x850b) {
      if (param_2 == 0x1701) {
        iVar2 = 3;
        goto LAB_000160d8;
      }
      if (param_2 < 0x1702) {
        if (param_2 == 0x1700) {
          iVar2 = 4;
          goto LAB_000160d8;
        }
      }
      else {
        if (param_2 == 0x1702) {
          iVar2 = *(int *)(param_1 + 0x53d4) + 0x10;
          goto LAB_000160d8;
        }
        if (param_2 == 0x1800) {
          iVar2 = 2;
          goto LAB_000160d8;
        }
      }
    }
    else if (0x8721 < param_2) {
      if (param_2 < 0x8724) {
        iVar2 = param_2 - 0x871c;
LAB_000160d8:
        *(int *)(param_1 + 0x4ff4) = iVar2;
        ((int (*)())_gleUpdateMatrixMode)(param_1);
        return;
      }
      if (param_2 - 0x88c0 < 8) {
        iVar2 = param_2 - 35000;
        goto LAB_000160d8;
      }
    }
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar1 = 0x500;
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

/* _glLoadIdentity_Exec @ 0x160e0 (176 bytes) */
int _glLoadIdentity_Exec(param_1)
  int param_1;
{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  
  uVar4 = *(undefined4 *)(param_1 + 0x4fec);
  if ((*(short *)(param_1 + 0x4a10) < 0) && (*(int *)(param_1 + 0x4ff4) < 0x18)) {
    iVar2 = _gleMakeIdentityMatrix(uVar4);
    uVar3 = *(uint *)(param_1 + 0x50a8);
    *(uint *)(param_1 + 0x50ac) = *(uint *)(param_1 + 0x50ac) | uVar3;
    if ((uVar3 & *(uint *)(param_1 + 0x505c) & 0xfffffc) != 0) {
      iVar2 = _gleCopyMatrix(uVar4,*(undefined4 *)(param_1 + 0x4ff0));
      uVar1 = uVar3 & 0xfffffc;
      uVar3 = uVar3 & 0xff000003;
      *(uint *)(param_1 + 0x50b0) = *(uint *)(param_1 + 0x50b0) & ~uVar1;
    }
    *(uint *)(param_1 + 0x50b0) = *(uint *)(param_1 + 0x50b0) | uVar3;
  }
  else {
    iVar2 = param_1;
    if (*(int *)(param_1 + 0x7574) == 0) {
      *(undefined4 *)(param_1 + 0x7574) = 0x502;
    }
  }
  return iVar2;
}

/* _glOrtho_Exec @ 0x16190 (616 bytes) */
void _glOrtho_Exec(int param_1,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  undefined4 uVar7;
  float *pfVar8;
  double dVar9;
  double dVar10;
  double dVar11;
  
  pfVar8 = *(float **)(param_1 + 0x4fec);
  if ((*(short *)(param_1 + 0x4a10) < 0) && (*(int *)(param_1 + 0x4ff4) < 0x18)) {
    fVar1 = (float)(fparam_2 - fparam_1);
    fVar2 = (float)(fparam_4 - fparam_3);
    fVar3 = (float)(fparam_5 - fparam_6);
    fVar4 = fVar1;
    if (fVar1 < FLOAT_00108e50) {
      fVar4 = -fVar1;
    }
    if (FLOAT_00108e80 <= fVar4) {
      fVar4 = fVar2;
      if (fVar2 < FLOAT_00108e50) {
        fVar4 = -fVar2;
      }
      if (FLOAT_00108e80 <= fVar4) {
        fVar4 = fVar3;
        if (fVar3 < FLOAT_00108e50) {
          fVar4 = -fVar3;
        }
        if (FLOAT_00108e80 <= fVar4) {
          dVar10 = (double)(1.0 / fVar2);
          dVar11 = (double)(1.0 / fVar1);
          dVar9 = (double)(1.0 / fVar3);
          fVar4 = (float)((fparam_6 + fparam_5) * dVar9);
          fVar5 = (float)(-(fparam_2 + fparam_1) * dVar11);
          fVar1 = (float)(dVar9 + dVar9);
          fVar6 = (float)(-(fparam_4 + fparam_3) * dVar10);
          fVar2 = (float)(dVar11 + dVar11);
          fVar3 = (float)(dVar10 + dVar10);
          pfVar8[0xc] = pfVar8[0xc] + (pfVar8[8] * fVar4 + (*pfVar8 * fVar5 + pfVar8[4] * fVar6));
          pfVar8[0xd] = pfVar8[0xd] + (pfVar8[9] * fVar4 + (pfVar8[1] * fVar5 + pfVar8[5] * fVar6));
          pfVar8[0xe] = pfVar8[0xe] + (pfVar8[10] * fVar4 + (pfVar8[2] * fVar5 + pfVar8[6] * fVar6));
          pfVar8[0xf] = pfVar8[0xf] + (pfVar8[0xb] * fVar4 + (pfVar8[3] * fVar5 + pfVar8[7] * fVar6));
          pfVar8[3] = pfVar8[3] * fVar2;
          pfVar8[7] = pfVar8[7] * fVar3;
          pfVar8[0xb] = pfVar8[0xb] * fVar1;
          *pfVar8 = *pfVar8 * fVar2;
          pfVar8[1] = pfVar8[1] * fVar2;
          pfVar8[2] = pfVar8[2] * fVar2;
          pfVar8[4] = pfVar8[4] * fVar3;
          pfVar8[5] = pfVar8[5] * fVar3;
          pfVar8[6] = pfVar8[6] * fVar3;
          pfVar8[8] = pfVar8[8] * fVar1;
          pfVar8[9] = pfVar8[9] * fVar1;
          pfVar8[10] = pfVar8[10] * fVar1;
          *(uint *)(param_1 + 0x50ac) = *(uint *)(param_1 + 0x50ac) | *(uint *)(param_1 + 0x50a8);
          *(uint *)(param_1 + 0x50b0) = *(uint *)(param_1 + 0x50b0) | *(uint *)(param_1 + 0x50a8);
          return;
        }
      }
    }
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar7 = 0x501;
  }
  else {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar7 = 0x502;
  }
  *(undefined4 *)(param_1 + 0x7574) = uVar7;
  return;
}

/* _glEnable_Exec @ 0x163f8 (108 bytes) */
int _glEnable_Exec(param_1, param_2)
  int param_1;
  uint param_2;
{
  undefined4 uVar1;
  uint *puVar2;
  
  puVar2 = (uint *)(*(int *)(param_1 + 0x4850) + (param_2 & 0x3ff) * 0x10);
  if (*(short *)(param_1 + 0x4a10) < 0) {
    do {
      if (*puVar2 == param_2) {
                    
                    
        (*(code *)puVar2[1])(param_1,param_2,1);
        return;
      }
      puVar2 = (uint *)puVar2[2];
    } while (puVar2 != (uint *)0x0);
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar1 = 0x500;
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

/* _gleSetEnable_ALPHA_TEST @ 0x16464 (32 bytes) */
int _gleSetEnable_ALPHA_TEST(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  uint param_3;
{
  if (*(byte *)(param_1 + 0x30c6) == param_3) {
    return;
  }
  *(char *)(param_1 + 0x30c6) = (char)param_3;
  *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 1;
  return;
}

