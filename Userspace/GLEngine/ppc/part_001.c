#include "decls.h"

/* _gleUpdatePrimitiveData @ 0x66d8 (1928 bytes) */
void _gleUpdatePrimitiveData(glContext)
  int glContext;
{
  undefined *stagedFuncPtr1;
  undefined *stagedFuncPtr2;
  undefined *stagedFuncPtr3;
  uint dispatchTable;
  
  if (*(int *)(glContext + 0x4e1c) == 0x1c00) {
    if (*(char *)(glContext + 0x7580) == '\0') {
      if (*(undefined **)(glContext + 0x5408) == (undefined *)0x0) {
        dispatchTable = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x128) == 0);
        dispatchTable = *(uint *)(glContext + 0x4680) & dispatchTable | *(uint *)(glContext + 0x4684) & ~dispatchTable;
        stagedFuncPtr3 = PTR__glEnd_Exec_00112164;
      }
      else if (*(undefined **)(glContext + 0x5408) == ((unsigned char *)0x00001300)) {
        dispatchTable = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x128) == 0);
        dispatchTable = *(uint *)(glContext + 0x4680) & dispatchTable | *(uint *)(glContext + 0x4684) & ~dispatchTable;
        stagedFuncPtr3 = PTR__glEnd_Comp_00112388;
      }
      else {
        dispatchTable = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x128) == 0);
        dispatchTable = *(uint *)(glContext + 0x4680) & dispatchTable | *(uint *)(glContext + 0x4684) & ~dispatchTable;
        stagedFuncPtr3 = PTR__glEnd_CompExec_00112384;
      }
      *(undefined **)(dispatchTable + 0x128) = stagedFuncPtr3;
      stagedFuncPtr2 = PTR__gleVPBeginLines_0011237c;
      stagedFuncPtr1 = PTR__gleBeginLinesRenderSmooth_00112354;
      stagedFuncPtr3 = PTR__gleBeginLinesRenderFlat_00112330;
      if ((*(char *)(glContext + 0x4664) == '\0') && (*(int *)(glContext + 0x5434) == 0)) {
        if (*(int *)(glContext + 0x34f4) == 0x1d01) {
          *(undefined **)(glContext + 0x49e0) = PTR__gleBeginPointsRender_00112358;
          stagedFuncPtr3 = PTR__gleBeginLineLoopRenderSmooth_00112350;
          *(undefined **)(glContext + 0x49e4) = stagedFuncPtr1;
          stagedFuncPtr1 = PTR__gleBeginLineStripRenderSmooth_0011234c;
          *(undefined **)(glContext + 0x49e8) = stagedFuncPtr3;
          stagedFuncPtr3 = PTR__gleBeginTrianglesRenderSmooth_00112348;
          *(undefined **)(glContext + 0x49ec) = stagedFuncPtr1;
          stagedFuncPtr1 = PTR__gleBeginTriangleStripRenderSmooth_00112344;
          *(undefined **)(glContext + 0x49f0) = stagedFuncPtr3;
          stagedFuncPtr3 = PTR__gleBeginTriangleFanRenderSmooth_00112340;
          *(undefined **)(glContext + 0x49f4) = stagedFuncPtr1;
          stagedFuncPtr1 = PTR__gleBeginQuadsRenderSmooth_0011233c;
          *(undefined **)(glContext + 0x49f8) = stagedFuncPtr3;
          stagedFuncPtr3 = PTR__gleBeginQuadStripRenderSmooth_00112338;
          *(undefined **)(glContext + 0x49fc) = stagedFuncPtr1;
          *(undefined **)(glContext + 0x4a00) = stagedFuncPtr3;
          stagedFuncPtr3 = PTR__gleBeginPolygonRenderSmooth_00112334;
        }
        else {
          *(undefined **)(glContext + 0x49e0) = PTR__gleBeginPointsRender_00112358;
          stagedFuncPtr2 = PTR__gleBeginLineLoopRenderFlat_0011232c;
          *(undefined **)(glContext + 0x49e4) = stagedFuncPtr3;
          stagedFuncPtr1 = PTR__gleBeginLineStripRenderFlat_00112328;
          *(undefined **)(glContext + 0x49e8) = stagedFuncPtr2;
          stagedFuncPtr3 = PTR__gleBeginTrianglesRenderFlat_00112324;
          *(undefined **)(glContext + 0x49ec) = stagedFuncPtr1;
          stagedFuncPtr1 = PTR__gleBeginTriangleStripRenderFlat_00112320;
          *(undefined **)(glContext + 0x49f0) = stagedFuncPtr3;
          stagedFuncPtr3 = PTR__gleBeginTriangleFanRenderFlat_0011231c;
          *(undefined **)(glContext + 0x49f4) = stagedFuncPtr1;
          stagedFuncPtr1 = PTR__gleBeginQuadsRenderFlat_00112318;
          *(undefined **)(glContext + 0x49f8) = stagedFuncPtr3;
          stagedFuncPtr3 = PTR__gleBeginQuadStripRenderFlat_00112314;
          *(undefined **)(glContext + 0x49fc) = stagedFuncPtr1;
          *(undefined **)(glContext + 0x4a00) = stagedFuncPtr3;
          stagedFuncPtr3 = PTR__gleBeginPolygonRenderFlat_00112310;
        }
      }
      else {
        *(undefined **)(glContext + 0x49e0) = PTR__gleVPBeginPoints_00112380;
        stagedFuncPtr3 = PTR__gleVPBeginLineLoop_00112378;
        *(undefined **)(glContext + 0x49e4) = stagedFuncPtr2;
        stagedFuncPtr1 = PTR__gleVPBeginLineStrip_00112374;
        *(undefined **)(glContext + 0x49e8) = stagedFuncPtr3;
        stagedFuncPtr3 = PTR__gleVPBeginTriangles_00112370;
        *(undefined **)(glContext + 0x49ec) = stagedFuncPtr1;
        stagedFuncPtr1 = PTR__gleVPBeginTriangleStrip_0011236c;
        *(undefined **)(glContext + 0x49f0) = stagedFuncPtr3;
        stagedFuncPtr3 = PTR__gleVPBeginTriangleFan_00112368;
        *(undefined **)(glContext + 0x49f4) = stagedFuncPtr1;
        stagedFuncPtr1 = PTR__gleVPBeginQuads_00112364;
        *(undefined **)(glContext + 0x49f8) = stagedFuncPtr3;
        stagedFuncPtr3 = PTR__gleVPBeginQuadStrip_00112360;
        *(undefined **)(glContext + 0x49fc) = stagedFuncPtr1;
        *(undefined **)(glContext + 0x4a00) = stagedFuncPtr3;
        stagedFuncPtr3 = PTR__gleVPBeginPolygon_0011235c;
      }
    }
    else if (*(char *)(*(int *)(glContext + 0x468c) + 0x7a) == '\0') {
      if (*(int *)(glContext + 0x5408) == 0) {
        dispatchTable = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x128) == 0);
        *(undefined **)
         ((*(uint *)(glContext + 0x4680) & dispatchTable | *(uint *)(glContext + 0x4684) & ~dispatchTable) + 0x128) =
             PTR__glEndRDirty_Exec_00112160;
      }
      stagedFuncPtr1 = PTR__gleVPBeginLinesTCLRDirty_001123d4;
      stagedFuncPtr3 = PTR__gleBeginLinesRenderTCLRDirty_001123ac;
      stagedFuncPtr2 = PTR__gleBeginPrimitiveTCLRDirtyFunc_001113d8;
      if (*(int *)(glContext + 0x48d0) != 0) goto LAB_000068ec;
      if ((*(char *)(glContext + 0x4664) == '\0') && (*(int *)(glContext + 0x5434) == 0)) {
        *(undefined **)(glContext + 0x49e0) = PTR__gleBeginPointsRenderTCLRDirty_001123b0;
        stagedFuncPtr2 = PTR__gleBeginLineLoopRenderTCLRDirty_001123a8;
        *(undefined **)(glContext + 0x49e4) = stagedFuncPtr3;
        stagedFuncPtr1 = PTR__gleBeginLineStripRenderTCLRDirty_001123a4;
        *(undefined **)(glContext + 0x49e8) = stagedFuncPtr2;
        stagedFuncPtr3 = PTR__gleBeginTrianglesRenderTCLRDirty_001123a0;
        *(undefined **)(glContext + 0x49ec) = stagedFuncPtr1;
        stagedFuncPtr1 = PTR__gleBeginTriangleStripRenderTCLRDirty_0011239c;
        *(undefined **)(glContext + 0x49f0) = stagedFuncPtr3;
        stagedFuncPtr3 = PTR__gleBeginTriangleFanRenderTCLRDirty_00112398;
        *(undefined **)(glContext + 0x49f4) = stagedFuncPtr1;
        stagedFuncPtr1 = PTR__gleBeginQuadsRenderTCLRDirty_00112394;
        *(undefined **)(glContext + 0x49f8) = stagedFuncPtr3;
        stagedFuncPtr3 = PTR__gleBeginQuadStripRenderTCLRDirty_00112390;
        *(undefined **)(glContext + 0x49fc) = stagedFuncPtr1;
        *(undefined **)(glContext + 0x4a00) = stagedFuncPtr3;
        stagedFuncPtr3 = PTR__gleBeginPolygonRenderTCLRDirty_0011238c;
      }
      else {
        *(undefined **)(glContext + 0x49e0) = PTR__gleVPBeginPointsTCLRDirty_001123d8;
        stagedFuncPtr3 = PTR__gleVPBeginLineLoopTCLRDirty_001123d0;
        *(undefined **)(glContext + 0x49e4) = stagedFuncPtr1;
        stagedFuncPtr1 = PTR__gleVPBeginLineStripTCLRDirty_001123cc;
        *(undefined **)(glContext + 0x49e8) = stagedFuncPtr3;
        stagedFuncPtr3 = PTR__gleVPBeginTrianglesTCLRDirty_001123c8;
        *(undefined **)(glContext + 0x49ec) = stagedFuncPtr1;
        stagedFuncPtr1 = PTR__gleVPBeginTriangleStripTCLRDirty_001123c4;
        *(undefined **)(glContext + 0x49f0) = stagedFuncPtr3;
        stagedFuncPtr3 = PTR__gleVPBeginTriangleFanTCLRDirty_001123c0;
        *(undefined **)(glContext + 0x49f4) = stagedFuncPtr1;
        stagedFuncPtr1 = PTR__gleVPBeginQuadsTCLRDirty_001123bc;
        *(undefined **)(glContext + 0x49f8) = stagedFuncPtr3;
        stagedFuncPtr3 = PTR__gleVPBeginQuadStripTCLRDirty_001123b8;
        *(undefined **)(glContext + 0x49fc) = stagedFuncPtr1;
        *(undefined **)(glContext + 0x4a00) = stagedFuncPtr3;
        stagedFuncPtr3 = PTR__gleVPBeginPolygonTCLRDirty_001123b4;
      }
    }
    else {
      if (*(int *)(glContext + 0x5408) == 0) {
        if (*(char *)(glContext + 0x4df8) == '\0') {
          dispatchTable = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x128) == 0);
          dispatchTable = *(uint *)(glContext + 0x4680) & dispatchTable | *(uint *)(glContext + 0x4684) & ~dispatchTable;
          stagedFuncPtr3 = PTR__glEndNoMat_Exec_00112168;
        }
        else {
          dispatchTable = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x128) == 0);
          dispatchTable = *(uint *)(glContext + 0x4680) & dispatchTable | *(uint *)(glContext + 0x4684) & ~dispatchTable;
          stagedFuncPtr3 = PTR__glEnd_Exec_00112164;
        }
        *(undefined **)(dispatchTable + 0x128) = stagedFuncPtr3;
      }
      stagedFuncPtr1 = PTR__gleVPBeginLinesTCL_00112424;
      stagedFuncPtr3 = PTR__gleBeginLinesRenderTCL_001123fc;
      stagedFuncPtr2 = PTR__gleBeginPrimitiveTCLFunc_001113dc;
      if (*(int *)(glContext + 0x48d0) != 0) {
LAB_000068ec:
        *(undefined **)(glContext + 0x4a04) = stagedFuncPtr2;
        *(undefined **)(glContext + 0x49e0) = stagedFuncPtr2;
        *(undefined **)(glContext + 0x49e4) = stagedFuncPtr2;
        *(undefined **)(glContext + 0x49e8) = stagedFuncPtr2;
        *(undefined **)(glContext + 0x49ec) = stagedFuncPtr2;
        *(undefined **)(glContext + 0x49f0) = stagedFuncPtr2;
        *(undefined **)(glContext + 0x49f4) = stagedFuncPtr2;
        *(undefined **)(glContext + 0x49f8) = stagedFuncPtr2;
        *(undefined **)(glContext + 0x49fc) = stagedFuncPtr2;
        *(undefined **)(glContext + 0x4a00) = stagedFuncPtr2;
        goto LAB_00006d54;
      }
      if ((*(char *)(glContext + 0x4664) == '\0') && (*(int *)(glContext + 0x5434) == 0)) {
        *(undefined **)(glContext + 0x49e0) = PTR__gleBeginPointsRenderTCL_00112400;
        stagedFuncPtr2 = PTR__gleBeginLineLoopRenderTCL_001123f8;
        *(undefined **)(glContext + 0x49e4) = stagedFuncPtr3;
        stagedFuncPtr1 = PTR__gleBeginLineStripRenderTCL_001123f4;
        *(undefined **)(glContext + 0x49e8) = stagedFuncPtr2;
        stagedFuncPtr3 = PTR__gleBeginTrianglesRenderTCL_001123f0;
        *(undefined **)(glContext + 0x49ec) = stagedFuncPtr1;
        stagedFuncPtr1 = PTR__gleBeginTriangleStripRenderTCL_001123ec;
        *(undefined **)(glContext + 0x49f0) = stagedFuncPtr3;
        stagedFuncPtr3 = PTR__gleBeginTriangleFanRenderTCL_001123e8;
        *(undefined **)(glContext + 0x49f4) = stagedFuncPtr1;
        stagedFuncPtr1 = PTR__gleBeginQuadsRenderTCL_001123e4;
        *(undefined **)(glContext + 0x49f8) = stagedFuncPtr3;
        stagedFuncPtr3 = PTR__gleBeginQuadStripRenderTCL_001123e0;
        *(undefined **)(glContext + 0x49fc) = stagedFuncPtr1;
        *(undefined **)(glContext + 0x4a00) = stagedFuncPtr3;
        stagedFuncPtr3 = PTR__gleBeginPolygonRenderTCL_001123dc;
      }
      else {
        *(undefined **)(glContext + 0x49e0) = PTR__gleVPBeginPointsTCL_00112428;
        stagedFuncPtr3 = PTR__gleVPBeginLineLoopTCL_00112420;
        *(undefined **)(glContext + 0x49e4) = stagedFuncPtr1;
        stagedFuncPtr1 = PTR__gleVPBeginLineStripTCL_0011241c;
        *(undefined **)(glContext + 0x49e8) = stagedFuncPtr3;
        stagedFuncPtr3 = PTR__gleVPBeginTrianglesTCL_00112418;
        *(undefined **)(glContext + 0x49ec) = stagedFuncPtr1;
        stagedFuncPtr1 = PTR__gleVPBeginTriangleStripTCL_00112414;
        *(undefined **)(glContext + 0x49f0) = stagedFuncPtr3;
        stagedFuncPtr3 = PTR__gleVPBeginTriangleFanTCL_00112410;
        *(undefined **)(glContext + 0x49f4) = stagedFuncPtr1;
        stagedFuncPtr1 = PTR__gleVPBeginQuadsTCL_0011240c;
        *(undefined **)(glContext + 0x49f8) = stagedFuncPtr3;
        stagedFuncPtr3 = PTR__gleVPBeginQuadStripTCL_00112408;
        *(undefined **)(glContext + 0x49fc) = stagedFuncPtr1;
        *(undefined **)(glContext + 0x4a00) = stagedFuncPtr3;
        stagedFuncPtr3 = PTR__gleVPBeginPolygonTCL_00112404;
      }
    }
  }
  else {
    if (*(undefined **)(glContext + 0x5408) == (undefined *)0x0) {
      dispatchTable = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x128) == 0);
      dispatchTable = *(uint *)(glContext + 0x4680) & dispatchTable | *(uint *)(glContext + 0x4684) & ~dispatchTable;
      stagedFuncPtr3 = PTR__glEnd_Exec_00112164;
    }
    else if (*(undefined **)(glContext + 0x5408) == ((unsigned char *)0x00001300)) {
      dispatchTable = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x128) == 0);
      dispatchTable = *(uint *)(glContext + 0x4680) & dispatchTable | *(uint *)(glContext + 0x4684) & ~dispatchTable;
      stagedFuncPtr3 = PTR__glEnd_Comp_00112388;
    }
    else {
      dispatchTable = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x128) == 0);
      dispatchTable = *(uint *)(glContext + 0x4680) & dispatchTable | *(uint *)(glContext + 0x4684) & ~dispatchTable;
      stagedFuncPtr3 = PTR__glEnd_CompExec_00112384;
    }
    *(undefined **)(dispatchTable + 0x128) = stagedFuncPtr3;
    stagedFuncPtr3 = PTR__gleBeginLinesSelectFeedback_00112308;
    *(undefined **)(glContext + 0x49e0) = PTR__gleBeginPointsSelectFeedback_0011230c;
    stagedFuncPtr1 = PTR__gleBeginLineLoopSelectFeedback_00112304;
    *(undefined **)(glContext + 0x49e4) = stagedFuncPtr3;
    stagedFuncPtr3 = PTR__gleBeginLineStripSelectFeedback_00112300;
    *(undefined **)(glContext + 0x49e8) = stagedFuncPtr1;
    stagedFuncPtr1 = PTR__gleBeginTrianglesSelectFeedback_001122fc;
    *(undefined **)(glContext + 0x49ec) = stagedFuncPtr3;
    stagedFuncPtr3 = PTR__gleBeginTriangleStripSelectFeedback_001122f8;
    *(undefined **)(glContext + 0x49f0) = stagedFuncPtr1;
    stagedFuncPtr1 = PTR__gleBeginTriangleFanSelectFeedback_001122f4;
    *(undefined **)(glContext + 0x49f4) = stagedFuncPtr3;
    stagedFuncPtr3 = PTR__gleBeginQuadsSelectFeedback_001122f0;
    *(undefined **)(glContext + 0x49f8) = stagedFuncPtr1;
    *(undefined **)(glContext + 0x49fc) = stagedFuncPtr3;
    stagedFuncPtr3 = PTR__gleBeginPolygonSelectFeedback_001122e8;
    *(undefined **)(glContext + 0x4a00) = PTR__gleBeginQuadStripSelectFeedback_001122ec;
  }
  *(undefined **)(glContext + 0x4a04) = stagedFuncPtr3;
LAB_00006d54:
  stagedFuncPtr3 = PTR__gleBeginRSLNoop_001113d4;
  if ((*(char *)(glContext + 0x34da) != '\0') && (*(short *)(glContext + 0x34d6) == 0x408)) {
    *(undefined **)(glContext + 0x4a04) = PTR__gleBeginRSLNoop_001113d4;
    *(undefined **)(glContext + 0x49f0) = stagedFuncPtr3;
    *(undefined **)(glContext + 0x49f4) = stagedFuncPtr3;
    *(undefined **)(glContext + 0x49f8) = stagedFuncPtr3;
    *(undefined **)(glContext + 0x49fc) = stagedFuncPtr3;
    *(undefined **)(glContext + 0x4a00) = stagedFuncPtr3;
  }
  if (*(char *)(glContext + 0x759c) == '\0') {
    dispatchTable = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x10) == 0);
    dispatchTable = *(uint *)(glContext + 0x4680) & dispatchTable | *(uint *)(glContext + 0x4684) & ~dispatchTable;
    stagedFuncPtr3 = PTR__glBegin_NoopExec_00112078;
  }
  else if (*(undefined **)(glContext + 0x5408) == (undefined *)0x0) {
    dispatchTable = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x10) == 0);
    dispatchTable = *(uint *)(glContext + 0x4680) & dispatchTable | *(uint *)(glContext + 0x4684) & ~dispatchTable;
    stagedFuncPtr3 = PTR__glBegin_Exec_00112074;
  }
  else if (*(undefined **)(glContext + 0x5408) == ((unsigned char *)0x00001300)) {
    dispatchTable = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x10) == 0);
    dispatchTable = *(uint *)(glContext + 0x4680) & dispatchTable | *(uint *)(glContext + 0x4684) & ~dispatchTable;
    stagedFuncPtr3 = PTR__glBegin_Comp_001122e4;
  }
  else {
    dispatchTable = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x10) == 0);
    dispatchTable = *(uint *)(glContext + 0x4680) & dispatchTable | *(uint *)(glContext + 0x4684) & ~dispatchTable;
    stagedFuncPtr3 = PTR__glBegin_CompExec_001122e0;
  }
  *(undefined **)(dispatchTable + 0x10) = stagedFuncPtr3;
  return;
}

/* _gleUpdateState @ 0x6e60 (480 bytes) */
void _gleUpdateState(glContext)
  int glContext;
{
  undefined *clipInterpFuncPtr;
  undefined1 separateSpecular;
  undefined4 r4AfterCall;
  undefined4 incomingR5;
  undefined4 incomingR6;
  int rendererInfoWord10ThenLoopIndex;
  int rendererInfoWordCThenNextIndex;
  double f1AfterCall;
  double lastF1Result;
  double forwardedFloatArg1;
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
  
  rendererInfoWord10ThenLoopIndex = *(int *)(*(int *)(glContext + 0x468c) + 0x10);
  rendererInfoWordCThenNextIndex = *(int *)(*(int *)(glContext + 0x468c) + 0xc);
  *(uint *)(glContext + 0x314) = *(uint *)(glContext + 0x314) | 0x3ffffff;
  *(uint *)(glContext + 0x318) = *(uint *)(glContext + 0x318) | 0xfffffffd;
  *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x7ffffff;
  *(undefined4 *)(glContext + 800) = 0xffffffff;
  *(uint *)(glContext + 0x50ac) = *(uint *)(glContext + 0x50ac) | 1;
  *(undefined4 *)(glContext + 0x310) = 0xffffffff;
  if (((*(char *)(glContext + 0x30aa) == '\0') || (*(char *)(glContext + 0x4664) != '\0')) ||
     (*(int *)(glContext + 0x5434) != 0)) {
    separateSpecular = *(undefined1 *)(glContext + 0x4fea);
  }
  else {
    separateSpecular = *(short *)(glContext + 0x30a8) == -0x7e06;
  }
  *(undefined1 *)(glContext + 0x316b) = separateSpecular;
  if (rendererInfoWordCThenNextIndex < *(int *)(glContext + 0x1ba8)) {
    *(int *)(glContext + 0x1ba8) = rendererInfoWordCThenNextIndex;
  }
  if (rendererInfoWord10ThenLoopIndex < *(int *)(glContext + 0x1bac)) {
    *(int *)(glContext + 0x1bac) = rendererInfoWord10ThenLoopIndex;
  }
  ((void (*)())_gleUpdateLightColorChangeFunc)(glContext);
  ((void (*)())_gleSetColorMaterialEnable)(glContext);
  *(undefined1 *)(*(int *)(glContext + 0x4dd0) + 0x234) = 0x1f;
  *(undefined1 *)(*(int *)(glContext + 0x4dd4) + 0x234) = 0x1f;
  rendererInfoWord10ThenLoopIndex = 0;
  lastF1Result = f1AfterCall;
  do {
    lastF1Result = (double)((double (*)())_gleUpdateLightPosition)(glContext,rendererInfoWord10ThenLoopIndex,lastF1Result);
    ((void (*)())_gleUpdateLightDirection)(glContext,rendererInfoWord10ThenLoopIndex,lastF1Result);
    ((double (*)())_gleUpdateLightExponents)(glContext,rendererInfoWord10ThenLoopIndex);
    rendererInfoWordCThenNextIndex = rendererInfoWord10ThenLoopIndex + 1;
    lastF1Result = (double)((double (*)())_gleUpdateLightAttenuation)(glContext,rendererInfoWord10ThenLoopIndex);
    rendererInfoWord10ThenLoopIndex = rendererInfoWordCThenNextIndex;
  } while (rendererInfoWordCThenNextIndex < 8);
  ((void (*)())_gleUpdateInverseNeeds)(glContext);
  ((void (*)())_gleUpdateLightModel)(glContext);
  ((void (*)())_gleUpdateClipPlane)(glContext,r4AfterCall,incomingR5,incomingR6);
  ((void (*)())_gleUpdateMatrixMode)(glContext);
  ((int (*)())_gleUpdateMatrixFunc)(glContext);
  ((void (*)())_gleUpdateDepthRangeData)(glContext,forwardedFloatArg1,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,incomingStack_ffffffb8,
             incomingStack_ffffffc0,incomingStack_ffffffc8,incomingStack_ffffffd0,incomingStack_ffffffd8);
  ((void (*)())_gleUpdateTextureCoordGen)(glContext);
  rendererInfoWord10ThenLoopIndex = 0;
  do {
    rendererInfoWordCThenNextIndex = rendererInfoWord10ThenLoopIndex + 1;
    ((int (*)())_gleUpdateTextureParams)(glContext,rendererInfoWord10ThenLoopIndex);
    rendererInfoWord10ThenLoopIndex = rendererInfoWordCThenNextIndex;
  } while (rendererInfoWordCThenNextIndex < 0x10);
  ((double (*)())_gleUpdateFogData)(glContext);
  ((void (*)())_gleUpdatePolyMode)(glContext);
  lastF1Result = (double)((double (*)())_gleUpdateEvalData)(glContext);
  ((void (*)())_gleUpdateViewScissorData)(glContext,lastF1Result,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8);
  clipInterpFuncPtr = PTR__gleSetClipInterpFunc_00112038;
  *(undefined **)(glContext + 0x49c8) = PTR__gleSetEyeInterpFunc_0011203c;
  *(undefined **)(glContext + 0x49cc) = clipInterpFuncPtr;
  ((void (*)())_gleSelectVertexAddMaterialFunc)(glContext);
  ((void (*)())_gleSelectVertexSubmitFunc)(glContext);
  return;
}

/* _gleUpdateLightColorChangeFunc @ 0x7040 (468 bytes) */
void _gleUpdateLightColorChangeFunc(glContext)
  int glContext;
{
  ushort glContextShort30a6;
  char glContextByte4df8;
  code *pcVar3;
  
  if (*(short *)(glContext + 0x30a4) == 0x404) {
    glContextShort30a6 = *(ushort *)(glContext + 0x30a6);
    pcVar3 = (code *)PTR__gleLightMaterialRGBAChange_F_D_001121bc;
    if (glContextShort30a6 != 0x1201) {
      if (glContextShort30a6 < 0x1202) {
        pcVar3 = (code *)PTR__gleLightMaterialRGBAChange_F_A_001121c0;
        if (glContextShort30a6 != 0x1200) {
LAB_000070d4:
          pcVar3 = (code *)PTR__gleLightMaterialRGBAChange_F_AD_001121b4;
        }
      }
      else {
        pcVar3 = (code *)PTR__gleLightMaterialRGBAChange_F_S_001121b8;
        if ((glContextShort30a6 != 0x1202) &&
           (pcVar3 = (code *)PTR__gleLightMaterialRGBAChange_F_E_001121c4, glContextShort30a6 != 0x1600))
        goto LAB_000070d4;
      }
    }
  }
  else if (*(short *)(glContext + 0x30a4) == 0x405) {
    glContextShort30a6 = *(ushort *)(glContext + 0x30a6);
    pcVar3 = (code *)PTR__gleLightMaterialRGBAChange_B_D_001121a8;
    if (glContextShort30a6 != 0x1201) {
      if (glContextShort30a6 < 0x1202) {
        pcVar3 = (code *)PTR__gleLightMaterialRGBAChange_B_A_001121ac;
        if (glContextShort30a6 != 0x1200) {
LAB_0000713c:
          pcVar3 = (code *)PTR__gleLightMaterialRGBAChange_B_AD_001121a0;
        }
      }
      else {
        pcVar3 = (code *)PTR__gleLightMaterialRGBAChange_B_S_001121a4;
        if ((glContextShort30a6 != 0x1202) &&
           (pcVar3 = (code *)PTR__gleLightMaterialRGBAChange_B_E_001121b0, glContextShort30a6 != 0x1600))
        goto LAB_0000713c;
      }
    }
  }
  else {
    glContextShort30a6 = *(ushort *)(glContext + 0x30a6);
    pcVar3 = (code *)PTR__gleLightMaterialRGBAChange_FB_D_00112194;
    if (glContextShort30a6 != 0x1201) {
      if (glContextShort30a6 < 0x1202) {
        pcVar3 = (code *)PTR__gleLightMaterialRGBAChange_FB_A_00112198;
        if (glContextShort30a6 != 0x1200) {
LAB_000071a4:
          pcVar3 = (code *)PTR__gleLightMaterialRGBAChange_FB_AD_0011218c;
        }
      }
      else {
        pcVar3 = (code *)PTR__gleLightMaterialRGBAChange_FB_S_00112190;
        if ((glContextShort30a6 != 0x1202) &&
           (pcVar3 = (code *)PTR__gleLightMaterialRGBAChange_FB_E_0011219c, glContextShort30a6 != 0x1600))
        goto LAB_000071a4;
      }
    }
  }
  if (*(code **)(glContext + 0x4de0) == pcVar3) goto LAB_000071fc;
  if (*(char *)(glContext + 0x30ab) == '\0') {
LAB_000071dc:
    glContextByte4df8 = *(char *)(glContext + 0x4df8);
  }
  else {
    glContextByte4df8 = *(char *)(glContext + 0x4df8);
    if (glContextByte4df8 == '\0') {
      (**(code **)(glContext + 0x4de0))(glContext,glContext + 0x2a0);
      goto LAB_000071dc;
    }
  }
  if (glContextByte4df8 != '\0') {
    (*pcVar3)(glContext,glContext + 0x2a0);
  }
LAB_000071fc:
  *(code **)(glContext + 0x4de0) = pcVar3;
  return;
}

/* _gleSetColorMaterialEnable @ 0x7214 (656 bytes) */
void _gleSetColorMaterialEnable(glContext)
  int glContext;
{
  int glColor4fvSlot;
  int glContextWord5408;
  char colorMaterialActive;
  undefined *handlerPtr;
  uint selectMaskThenDispatchTable;
  uint glContextWord4680;
  uint glContextPtr4684;
  
  colorMaterialActive = '\0';
  if ((((*(char *)(glContext + 0x7580) == '\0') && (*(char *)(glContext + 0x30ab) != '\0')) &&
      (*(char *)(glContext + 0x4664) == '\0')) && (*(int *)(glContext + 0x5434) == 0)) {
    colorMaterialActive = '\x01';
  }
  if (colorMaterialActive == *(char *)(glContext + 0x4df8)) {
    return;
  }
  glContextWord5408 = *(int *)(glContext + 0x5408);
  *(char *)(glContext + 0x4df8) = colorMaterialActive;
  if (glContextWord5408 == 0) {
    if (colorMaterialActive == '\0') {
      selectMaskThenDispatchTable = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x54) == 0);
      *(undefined **)
       ((*(uint *)(glContext + 0x4680) & selectMaskThenDispatchTable | *(uint *)(glContext + 0x4684) & ~selectMaskThenDispatchTable) + 0x54) =
           PTR__glColor3f_NoColorMat_Exec_00112178;
      selectMaskThenDispatchTable = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x58) == 0);
      *(undefined **)
       ((*(uint *)(glContext + 0x4680) & selectMaskThenDispatchTable | *(uint *)(glContext + 0x4684) & ~selectMaskThenDispatchTable) + 0x58) =
           PTR__glColor3fv_NoColorMat_Exec_00112174;
      selectMaskThenDispatchTable = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x94) == 0);
      *(undefined **)
       ((*(uint *)(glContext + 0x4680) & selectMaskThenDispatchTable | *(uint *)(glContext + 0x4684) & ~selectMaskThenDispatchTable) + 0x94) =
           PTR__glColor4f_NoColorMat_Exec_00112170;
      glContextPtr4684 = *(uint *)(glContext + 0x4684);
      glContextWord4680 = *(uint *)(glContext + 0x4680);
      glColor4fvSlot = *(int *)(glContextPtr4684 + 0x98);
      handlerPtr = PTR__glColor4fv_NoColorMat_Exec_0011216c;
    }
    else {
      selectMaskThenDispatchTable = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x54) == 0);
      *(undefined **)
       ((*(uint *)(glContext + 0x4680) & selectMaskThenDispatchTable | *(uint *)(glContext + 0x4684) & ~selectMaskThenDispatchTable) + 0x54) =
           PTR__glColor3f_ColorMat_Exec_00112188;
      selectMaskThenDispatchTable = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x58) == 0);
      *(undefined **)
       ((*(uint *)(glContext + 0x4680) & selectMaskThenDispatchTable | *(uint *)(glContext + 0x4684) & ~selectMaskThenDispatchTable) + 0x58) =
           PTR__glColor3fv_ColorMat_Exec_00112184;
      selectMaskThenDispatchTable = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x94) == 0);
      *(undefined **)
       ((*(uint *)(glContext + 0x4680) & selectMaskThenDispatchTable | *(uint *)(glContext + 0x4684) & ~selectMaskThenDispatchTable) + 0x94) =
           PTR__glColor4f_ColorMat_Exec_00112180;
      glContextPtr4684 = *(uint *)(glContext + 0x4684);
      glContextWord4680 = *(uint *)(glContext + 0x4680);
      glColor4fvSlot = *(int *)(glContextPtr4684 + 0x98);
      handlerPtr = PTR__glColor4fv_ColorMat_Exec_0011217c;
    }
    *(undefined **)((glContextWord4680 & -(uint)(glColor4fvSlot == 0) | glContextPtr4684 & ~-(uint)(glColor4fvSlot == 0)) + 0x98) = handlerPtr;
    glContextWord5408 = *(int *)(glContext + 0x5408);
  }
  if (glContextWord5408 != 0) goto LAB_00007490;
  if ((*(char *)(glContext + 0x7580) == '\0') || (*(int *)(glContext + 0x4e1c) != 0x1c00)) {
LAB_00007464:
    selectMaskThenDispatchTable = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x128) == 0);
    selectMaskThenDispatchTable = *(uint *)(glContext + 0x4680) & selectMaskThenDispatchTable | *(uint *)(glContext + 0x4684) & ~selectMaskThenDispatchTable;
    handlerPtr = PTR__glEnd_Exec_00112164;
  }
  else if (*(char *)(*(int *)(glContext + 0x468c) + 0x7a) == '\0') {
    selectMaskThenDispatchTable = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x128) == 0);
    selectMaskThenDispatchTable = *(uint *)(glContext + 0x4680) & selectMaskThenDispatchTable | *(uint *)(glContext + 0x4684) & ~selectMaskThenDispatchTable;
    handlerPtr = PTR__glEndRDirty_Exec_00112160;
  }
  else {
    if (*(char *)(glContext + 0x4df8) != '\0') goto LAB_00007464;
    selectMaskThenDispatchTable = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x128) == 0);
    selectMaskThenDispatchTable = *(uint *)(glContext + 0x4680) & selectMaskThenDispatchTable | *(uint *)(glContext + 0x4684) & ~selectMaskThenDispatchTable;
    handlerPtr = PTR__glEndNoMat_Exec_00112168;
  }
  *(undefined **)(selectMaskThenDispatchTable + 0x128) = handlerPtr;
LAB_00007490:
  if (colorMaterialActive == '\0') {
    return;
  }
                    
                    
  (**(code **)(glContext + 0x4de0))(glContext,glContext + 0x2a0);
  return;
}

/* _gleUpdateLightPosition @ 0x74a4 (540 bytes) */
double _gleUpdateLightPosition(int glContext,int lightIndex,double unusedFloatArg1)
{
  float floatZero;
  float floatOne;
  byte dirtyBitNumber;
  float lightPositionX;
  float lightPositionY;
  float lightPositionZ;
  float inverseLightW;
  undefined *vectorNormalizeFunc;
  int lightState;
  int dirtyWord348Light25e;
  int dirtyWord324Light25e;
  int glContextWord5434;
  int lightDerivedState;
  int dirtyWord348Light25b;
  int dirtyWord324Light25b;
  undefined4 normalizedDirectionX;
  int lightDirtyTableOffset;
  undefined4 incomingR6;
  undefined4 incomingR7;
  int glContextWord5424;
  undefined4 incomingR8;
  undefined4 a6;
  
  lightState = glContext + lightIndex * 0x80;
  lightPositionX = *(float *)(lightState + 0x2850);
  lightDerivedState = glContext + lightIndex * 0x6c;
  *(float *)(lightDerivedState + 0x4a70) = lightPositionX;
  floatZero = FLOAT_00108e50;
  lightPositionY = *(float *)(lightState + 0x2854);
  *(float *)(lightDerivedState + 0x4a74) = lightPositionY;
  lightPositionZ = *(float *)(lightState + 0x2858);
  *(float *)(lightDerivedState + 0x4a78) = lightPositionZ;
  if (*(float *)(lightState + 0x285c) == floatZero) {
    *(undefined1 *)(lightDerivedState + 0x4ad9) = 1;
  }
  else {
    *(undefined1 *)(lightDerivedState + 0x4ad9) = 0;
    if (*(float *)(lightState + 0x285c) != FLOAT_00108e54) {
      inverseLightW = FLOAT_00108e54 / *(float *)(lightState + 0x285c);
      *(float *)(lightDerivedState + 0x4a78) = lightPositionZ * inverseLightW;
      *(float *)(lightDerivedState + 0x4a70) = lightPositionX * inverseLightW;
      *(float *)(lightDerivedState + 0x4a74) = lightPositionY * inverseLightW;
    }
  }
  vectorNormalizeFunc = PTR__gleVectorNormalize_00112064;
  (**(code **)PTR__gleVectorNormalize_00112064)(glContext,lightDerivedState + 0x4a70,lightDerivedState + 0x4a7c);
  normalizedDirectionX = *(undefined4 *)(lightDerivedState + 0x4a7c);
  a6 = *(undefined4 *)(lightDerivedState + 0x4a80);
  *(undefined4 *)(lightState + 0x2888) = *(undefined4 *)(lightDerivedState + 0x4a84);
  floatOne = FLOAT_00108e54;
  *(undefined4 *)(lightState + 0x2880) = normalizedDirectionX;
  *(undefined4 *)(lightState + 0x2884) = a6;
  *(float *)(lightState + 0x2888) = *(float *)(lightState + 0x2888) + floatOne;
  (**(code **)vectorNormalizeFunc)(glContext,lightState + 0x2880,lightState + 0x2880,incomingR6,incomingR7,incomingR8,a6);
  ((void (*)())_gleUpdateLightFast)(glContext,lightIndex);
  ((void (*)())_gleUpdateLightModelFunc)(glContext);
  glContextWord5434 = *(int *)(glContext + 0x5434);
  if (glContextWord5434 == 0) {
    dirtyBitNumber = *(byte *)(lightIndex * 7 + *(int *)(glContext + 0x5420) + 0x25b);
  }
  else {
    dirtyBitNumber = *(byte *)(lightIndex * 7 + *(int *)(*(int *)(glContext + 0x5430) + 0x20) + 0x28f);
  }
  lightDirtyTableOffset = lightIndex * 7;
  dirtyWord324Light25b = (dirtyBitNumber >> 3 & 0x1c) + glContext;
  glContextWord5424 = *(int *)(glContext + 0x5424);
  *(uint *)(dirtyWord324Light25b + 0x324) = *(uint *)(dirtyWord324Light25b + 0x324) | 1 << (dirtyBitNumber & 0x1f);
  dirtyBitNumber = *(byte *)(lightDirtyTableOffset + glContextWord5424 + 0x25b);
  dirtyWord348Light25b = (dirtyBitNumber >> 3 & 0x1c) + glContext;
  *(uint *)(dirtyWord348Light25b + 0x348) = *(uint *)(dirtyWord348Light25b + 0x348) | 1 << (dirtyBitNumber & 0x1f);
  if (glContextWord5434 == 0) {
    dirtyBitNumber = *(byte *)(lightDirtyTableOffset + *(int *)(glContext + 0x5420) + 0x25e);
  }
  else {
    dirtyBitNumber = *(byte *)(lightDirtyTableOffset + *(int *)(*(int *)(glContext + 0x5430) + 0x20) + 0x292);
  }
  dirtyWord324Light25e = (dirtyBitNumber >> 3 & 0x1c) + glContext;
  *(uint *)(dirtyWord324Light25e + 0x324) = *(uint *)(dirtyWord324Light25e + 0x324) | 1 << (dirtyBitNumber & 0x1f);
  dirtyBitNumber = *(byte *)(lightDirtyTableOffset + glContextWord5424 + 0x25e);
  dirtyWord348Light25e = (dirtyBitNumber >> 3 & 0x1c) + glContext;
  *(uint *)(dirtyWord348Light25e + 0x348) = *(uint *)(dirtyWord348Light25e + 0x348) | 1 << (dirtyBitNumber & 0x1f);
  return;
}

/* _gleVectorNormalizeNO @ 0x76c0 (204 bytes) */
double _gleVectorNormalizeNO(undefined4 unusedArg1,float *inVector,float *outVector,double unusedFloatArg1)
{
  float fVar1;
  float dVar2;
  float dVar3;
  float dVar4;
  float dVar5;
  float newtonCorrection;
  double reciprocalSqrtEstimate;
  
  dVar3 = (double)inVector[1];
  dVar4 = (double)*inVector;
  dVar5 = (double)inVector[2];
  fVar1 = (dVar5 * dVar5 + (dVar4 * dVar4 + (dVar3 * dVar3)));
  dVar2 = (double)fVar1;
  if ((double)dVar2 <= DOUBLE_00108de8) {
    dVar2 = (double)FLOAT_00108eb4;
    fVar1 = FLOAT_00108e58;
  }
  else {
    reciprocalSqrtEstimate = (double)GH_U2F((unsigned int)((0x5f375a00 - ((uint)GH_F2U(fVar1) >> 1))));
    dVar2 = (double)(float)((double)(float)((double)dVar2 * reciprocalSqrtEstimate) * reciprocalSqrtEstimate);
    newtonCorrection = (double)(FLOAT_00108f38 - dVar2);
    dVar2 = (double)(float)(reciprocalSqrtEstimate * DOUBLE_00108df0 * (double)newtonCorrection *
                           -(double)((dVar2 * newtonCorrection) * newtonCorrection - FLOAT_00108f48));
    dVar4 = (double)(dVar4 * dVar2);
    dVar3 = (double)(dVar3 * dVar2);
    fVar1 = (dVar5 * dVar2);
  }
  outVector[2] = fVar1;
  *outVector = (float)(double)dVar4;
  outVector[1] = (float)(double)dVar3;
  return (double)dVar2;
}

/* _gleUpdateLightFast @ 0x778c (152 bytes) */
void _gleUpdateLightFast(glContext, param_2)
  int glContext;
  uint param_2;
{
  int iVar1;
  uint uVar2;
  uint glContextWord4ddc;
  
  uVar2 = 1 << (param_2 & 0x3f);
  glContextWord4ddc = *(uint *)(glContext + 0x4ddc);
  iVar1 = glContext + param_2 * 0x6c;
  if (((*(uint *)(glContext + 0x30a0) & uVar2) == 0) ||
     (((*(char *)(iVar1 + 0x4ada) == '\0' && (*(char *)(glContext + 0x30ad) == '\0')) &&
      (*(char *)(iVar1 + 0x4ad9) != '\0')))) {
    uVar2 = glContextWord4ddc & ~uVar2;
    *(undefined1 *)(iVar1 + 0x4ad8) = 1;
  }
  else {
    *(undefined1 *)(iVar1 + 0x4ad8) = 0;
    uVar2 = glContextWord4ddc | 1 << (param_2 & 0x3f);
  }
  *(uint *)(glContext + 0x4ddc) = uVar2;
  if ((glContextWord4ddc != 0) == (*(int *)(glContext + 0x4ddc) != 0)) {
    return;
  }
  *(uint *)(glContext + 0x50ac) = *(uint *)(glContext + 0x50ac) | 1;
  return;
}

/* _gleUpdateLightModelFunc @ 0x7824 (208 bytes) */
void _gleUpdateLightModelFunc(glContext)
  int glContext;
{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  
  puVar2 = PTR__gleVtxLightSpecRGBABackPtr_00110e64;
  puVar1 = PTR__gleVtxLightRGBABackPtr_00110e54;
  puVar3 = PTR__gleVtxLightFastRGBABackPtr_00110e44;
  if ((*(char *)(glContext + 0x30ae) == '\0') && (*(short *)(glContext + 0x30a8) != -0x7e06)) {
    if (*(int *)(glContext + 0x4ddc) == 0) {
      *(undefined **)(glContext + 0x4de8) = PTR__gleVtxLightFastRGBAFront_00110e50;
      puVar1 = PTR__gleVtxLightFastRGBABack_00110e4c;
      *(undefined **)(glContext + 0x4df4) = puVar3;
      *(undefined **)(glContext + 0x4dec) = puVar1;
      puVar3 = PTR__gleVtxLightFastRGBAFrontPtr_00110e48;
    }
    else {
      *(undefined **)(glContext + 0x4de8) = PTR__gleVtxLightRGBAFront_00110e60;
      *(undefined **)(glContext + 0x4df4) = puVar1;
      puVar3 = PTR__gleVtxLightRGBAFrontPtr_00110e58;
      *(undefined **)(glContext + 0x4dec) = PTR__gleVtxLightRGBABack_00110e5c;
    }
  }
  else {
    *(undefined **)(glContext + 0x4de8) = PTR__gleVtxLightSpecRGBAFront_00110e70;
    puVar3 = PTR__gleVtxLightSpecRGBABack_00110e6c;
    *(undefined **)(glContext + 0x4df4) = puVar2;
    *(undefined **)(glContext + 0x4dec) = puVar3;
    puVar3 = PTR__gleVtxLightSpecRGBAFrontPtr_00110e68;
  }
  *(undefined **)(glContext + 0x4df0) = puVar3;
  return;
}

/* _gleUpdateLightDirection @ 0x78f4 (220 bytes) */
void _gleUpdateLightDirection(int glContext,int param_2,double unusedFloatArg1)
{
  byte dirtyBitIndex;
  int dirtyWordAddress348;
  int glContextWord5424;
  undefined4 incomingR6;
  int dirtyWordAddress324;
  
  (**(code **)PTR__gleVectorNormalize_00112064)
            (glContext,glContext + param_2 * 0x80 + 0x2860,glContext + param_2 * 0x6c + 0x4a88,incomingR6);
  if (*(int *)(glContext + 0x5434) == 0) {
    dirtyBitIndex = *(byte *)(param_2 * 7 + *(int *)(glContext + 0x5420) + 0x25c);
  }
  else {
    dirtyBitIndex = *(byte *)(param_2 * 7 + *(int *)(*(int *)(glContext + 0x5430) + 0x20) + 0x290);
  }
  dirtyWordAddress324 = (dirtyBitIndex >> 3 & 0x1c) + glContext;
  glContextWord5424 = *(int *)(glContext + 0x5424);
  *(uint *)(dirtyWordAddress324 + 0x324) = *(uint *)(dirtyWordAddress324 + 0x324) | 1 << (dirtyBitIndex & 0x1f);
  dirtyBitIndex = *(byte *)(param_2 * 7 + glContextWord5424 + 0x25c);
  dirtyWordAddress348 = (dirtyBitIndex >> 3 & 0x1c) + glContext;
  *(uint *)(dirtyWordAddress348 + 0x348) = *(uint *)(dirtyWordAddress348 + 0x348) | 1 << (dirtyBitIndex & 0x1f);
  return;
}

/* _gleUpdateLightExponents @ 0x79d0 (424 bytes) */
double _gleUpdateLightExponents(glContext, lightIndex)
  int glContext;
  int lightIndex;
{
  int remaining;
  float tableBaseReload;
  float float10;
  int lightRecord;
  undefined4 *dstCursor2;
  int remaining2;
  int lightCache;
  float *dstCursor;
  double constantThenPowResult;
  double logThenExpThenBaseThenPowThenSample;
  float tableBase;
  float floatOne;
  
  lightRecord = glContext + lightIndex * 0x80;
  lightCache = glContext + lightIndex * 0x6c;
  if (*(float *)(lightRecord + 0x286c) < FLOAT_00108e50) {
    *(undefined1 *)(lightCache + 0x4ada) = 0;
  }
  else {
    *(undefined1 *)(lightCache + 0x4ada) = 1;
    if (*(float *)(lightCache + 0x4a94) != *(float *)(lightRecord + 0x287c)) {
      *(float *)(lightCache + 0x4a94) = *(float *)(lightRecord + 0x287c);
      if (FLOAT_00108e80 < *(float *)(lightRecord + 0x287c)) {
        dstCursor = (float *)(lightCache + 0x4aa8);
        floatOne = (double)FLOAT_00108e54;
        remaining2 = 9;
        logThenExpThenBaseThenPowThenSample = _log(DOUBLE_00108dd8);
        float10 = FLOAT_00108f44;
        logThenExpThenBaseThenPowThenSample = _exp(logThenExpThenBaseThenPowThenSample / (double)*(float *)(lightRecord + 0x287c));
        tableBase = (double)(float)logThenExpThenBaseThenPowThenSample;
        constantThenPowResult = (double)FLOAT_00108f40;
        *(float *)(lightCache + 0x4a98) = (float)logThenExpThenBaseThenPowThenSample;
        logThenExpThenBaseThenPowThenSample = DOUBLE_00108de0;
        *(float *)(lightCache + 0x4aa0) = (float)(constantThenPowResult / (double)tableBase);
        *(float *)(lightCache + 0x4a9c) = float10 / (floatOne - tableBase);
        logThenExpThenBaseThenPowThenSample = _pow(logThenExpThenBaseThenPowThenSample,(double)*(float *)(lightRecord + 0x287c));
        tableBaseReload = *(float *)(lightCache + 0x4a98);
        *(float *)(lightCache + 0x4aa4) = (float)(logThenExpThenBaseThenPowThenSample - DOUBLE_00108d68);
        logThenExpThenBaseThenPowThenSample = (double)tableBaseReload;
        do {
          constantThenPowResult = _pow(logThenExpThenBaseThenPowThenSample,(double)*(float *)(lightRecord + 0x287c));
          remaining2 = remaining2 + -1;
          *dstCursor = (float)constantThenPowResult;
          dstCursor = dstCursor + 1;
          logThenExpThenBaseThenPowThenSample = (double)(float)(logThenExpThenBaseThenPowThenSample + (double)((floatOne - tableBaseReload) / float10));
        } while (-1 < remaining2);
        *(undefined4 *)(lightCache + 0x4ad0) = 0x3f800000;
      }
      else {
        remaining = 0xb;
        *(undefined4 *)(lightCache + 0x4aa4) = 0x3f800000;
        *(undefined4 *)(lightCache + 0x4a98) = 0x3f800000;
        dstCursor2 = (undefined4 *)(lightCache + 0x4aa8);
        *(undefined4 *)(lightCache + 0x4a9c) = 0x3f800000;
        *(undefined4 *)(lightCache + 0x4aa0) = 0x3f800000;
        do {
          *dstCursor2 = 0x3f800000;
          dstCursor2 = dstCursor2 + 1;
          remaining = remaining + -1;
        } while (remaining != 0);
      }
    }
  }
  ((void (*)())_gleUpdateLightFast)(glContext,lightIndex);
  ((void (*)())_gleUpdateLightModelFunc)(glContext);
  return;
}

/* _gleUpdateLightAttenuation @ 0x7b78 (280 bytes) */
double _gleUpdateLightAttenuation(glContext, param_2)
  int glContext;
  int param_2;
{
  byte bVar1;
  undefined1 uVar2;
  int iVar3;
  int glContextWord5424;
  int iVar4;
  
  iVar3 = glContext + param_2 * 0x80;
  iVar4 = glContext + param_2 * 0x6c;
  if ((*(float *)(iVar3 + 0x2870) < FLOAT_00108e80) && (FLOAT_00108f3c < *(float *)(iVar3 + 0x2870))
     ) {
    *(undefined1 *)(iVar4 + 0x4adb) = 0;
  }
  else {
    if ((*(float *)(iVar3 + 0x2874) != FLOAT_00108e50) ||
       (uVar2 = 1, *(float *)(iVar3 + 0x2878) != FLOAT_00108e50)) {
      uVar2 = 0;
    }
    *(undefined1 *)(iVar4 + 0x4adb) = uVar2;
    *(float *)(iVar4 + 0x4ad4) = FLOAT_00108e54 / *(float *)(iVar3 + 0x2870);
  }
  if (*(int *)(glContext + 0x5434) == 0) {
    bVar1 = *(byte *)(param_2 * 7 + *(int *)(glContext + 0x5420) + 0x25d);
  }
  else {
    bVar1 = *(byte *)(param_2 * 7 + *(int *)(*(int *)(glContext + 0x5430) + 0x20) + 0x291);
  }
  iVar4 = (bVar1 >> 3 & 0x1c) + glContext;
  glContextWord5424 = *(int *)(glContext + 0x5424);
  *(uint *)(iVar4 + 0x324) = *(uint *)(iVar4 + 0x324) | 1 << (bVar1 & 0x1f);
  bVar1 = *(byte *)(param_2 * 7 + glContextWord5424 + 0x25d);
  iVar3 = (bVar1 >> 3 & 0x1c) + glContext;
  *(uint *)(iVar3 + 0x348) = *(uint *)(iVar3 + 0x348) | 1 << (bVar1 & 0x1f);
  return;
}

/* _gleUpdateInverseNeeds @ 0x7c90 (192 bytes) */
void _gleUpdateInverseNeeds(glContext)
  int glContext;
{
  int iVar1;
  
  if (*(char *)(glContext + 0x4664) == '\0') {
    if (*(int *)(glContext + 0x5434) == 0) {
      if ((*(char *)(glContext + 0x30aa) != '\0') || (iVar1 = 0, *(char *)(glContext + 0x53e6) != '\0'))
      {
        if (*(char *)(glContext + 0x4661) == '\0') {
          iVar1 = 0x10;
        }
        else {
          iVar1 = (0xffffffffU >> (0x20 - *(byte *)(glContext + 0x4660) & 0x3f)) << 4;
        }
      }
    }
    else {
      iVar1 = *(int *)(*(int *)(*(int *)(glContext + 0x5430) + 0x20) + 4);
    }
  }
  else {
    iVar1 = *(int *)(*(int *)(glContext + 0x5420) + 0x20);
  }
  *(int *)(glContext + 0x505c) = iVar1;
  if (*(char *)(glContext + 0x466c) != '\0') {
    *(uint *)(glContext + 0x505c) =
         *(uint *)(glContext + 0x505c) | *(uint *)(*(int *)(glContext + 0x5424) + 0x20);
  }
  if (*(int *)(glContext + 0x5438) == 0) {
    return;
  }
  *(uint *)(glContext + 0x505c) =
       *(uint *)(glContext + 0x505c) | *(uint *)(*(int *)(*(int *)(glContext + 0x5430) + 0x24) + 4);
  return;
}

/* _gleUpdateLightModel @ 0x7d50 (72 bytes) */
void _gleUpdateLightModel(glContext)
  undefined4 glContext;
{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  do {
    iVar2 = iVar1 + 1;
    ((void (*)())_gleUpdateLightFast)(glContext,iVar1);
    iVar1 = iVar2;
  } while (iVar2 < 8);
  ((void (*)())_gleUpdateLightModelFunc)(glContext);
  return;
}

/* _gleUpdateClipPlane @ 0x7d98 (108 bytes) */
void _gleUpdateClipPlane(glContext, unusedArg2, unusedArg3, unusedArg4)
  int glContext;
  undefined4 unusedArg2;
  undefined4 unusedArg3;
  undefined4 unusedArg4;
{
  char glContextByte4e18;
  uint *dstCursor;
  uint glContextWord4188;
  uint loopIndex2;
  int loopIndex;
  int remaining;
  
  glContextByte4e18 = *(char *)(glContext + 0x4e18);
  *(undefined1 *)(glContext + 0x4e18) = 0;
  glContextWord4188 = *(uint *)(glContext + 0x4188);
  remaining = 6;
  loopIndex2 = 0;
  loopIndex = 0;
  dstCursor = (uint *)(glContext + 0x4e00);
  do {
    if ((glContextWord4188 & 1 << (loopIndex2 & 0x3f)) != 0) {
      *dstCursor = loopIndex2;
      loopIndex = loopIndex + 1;
      *(undefined1 *)(glContext + 0x4e18) = 1;
      dstCursor = dstCursor + 1;
    }
    loopIndex2 = loopIndex2 + 1;
    remaining = remaining + -1;
  } while (remaining != 0);
  *(int *)(glContext + 0x4dfc) = loopIndex;
  if (*(char *)(glContext + 0x4e18) == glContextByte4e18) {
    return;
  }
  *(uint *)(glContext + 0x50ac) = *(uint *)(glContext + 0x50ac) | 1;
  return;
}

/* _gleUpdateMatrixMode @ 0x7e04 (68 bytes) */
void _gleUpdateMatrixMode(glContext)
  int glContext;
{
  uint uVar1;
  int iVar2;
  uint matrixModeIndex;
  
  matrixModeIndex = *(uint *)(glContext + 0x4ff4);
  if (0x17 < (int)matrixModeIndex) {
    return;
  }
  iVar2 = glContext + matrixModeIndex * 0x40;
  *(int *)(glContext + 0x4ff0) = iVar2 + 0x21c0;
  *(int *)(glContext + 0x4fec) = iVar2 + 0x1bc0;
  uVar1 = 1 << (matrixModeIndex & 0x3f);
  if (matrixModeIndex - 3 < 2) {
    uVar1 = uVar1 | 1;
  }
  *(uint *)(glContext + 0x50a8) = uVar1;
  return;
}

/* _gleUpdateMatrixFunc @ 0x7e48 (2092 bytes) */
int _gleUpdateMatrixFunc(glContext)
  int glContext;
{
  uint loopIndex;
  undefined *setModelviewFuncAllPtr;
  uint flagsWord3410;
  int lastResult;
  byte stateBit0;
  byte dirtyBitIndex;
  int dirtyWord324Ptr;
  int dirtyWord324PtrLast;
  int dirtyWord348Ptr;
  int glContextWord5434;
  int tableEntry;
  uint pendingMatrixBits;
  uint matrixChangeBits;
  int remaining;
  
  matrixChangeBits = *(uint *)(glContext + 0x50ac);
  stateBit0 = 0;
  pendingMatrixBits = *(uint *)(glContext + 0x50b0);
  if ((*(char *)(glContext + 0x4e18) != '\0') ||
     (((*(char *)(glContext + 0x30aa) != '\0' && (*(int *)(glContext + 0x4ddc) != 0)) ||
      (*(char *)(glContext + 0x53e5) != '\0')))) {
    stateBit0 = 1;
  }
  *(byte *)(glContext + 0x50b4) =
       stateBit0 | *(char *)(glContext + 0x316a) << 1 | *(char *)(glContext + 0x4661) << 2;
  if (((matrixChangeBits & 0x18) != 0) || (lastResult = glContext, (*(uint *)(glContext + 0x318) & 1) != 0)) {
    lastResult = ((int (*)())_gleApplyViewScissorTransform)(glContext);
  }
  pendingMatrixBits = pendingMatrixBits & *(uint *)(glContext + 0x505c);
  if (pendingMatrixBits != 0) {
    lastResult = _gleInvertMatrices(glContext,pendingMatrixBits);
  }
  setModelviewFuncAllPtr = PTR__gleSetModelviewFuncAll_0011222c;
  *(undefined **)(glContext + 0x5068) = PTR__gleSetNormalFunc_00112230;
  *(undefined **)(glContext + 0x5064) = setModelviewFuncAllPtr;
  if ((matrixChangeBits & 0x18) == 0) {
    if (((*(uint *)(glContext + 0x318) & 1) == 0) && ((*(uint *)(glContext + 0x31c) & 0x200000) == 0))
    goto LAB_00007f38;
  }
  *(undefined **)(glContext + 0x5060) = PTR__gleSetProjectionFuncAll_00112228;
LAB_00007f38:
  if ((matrixChangeBits & 0xff0000) != 0) {
    lastResult = ((int (*)())_gleUpdateTextureTransform)(glContext);
  }
  if ((matrixChangeBits & 4) != 0) {
    lastResult = (**(code **)PTR__gleGenerateMatrixIdentifier_00112060)(glContext,glContext + 0x1c40);
    if (lastResult == -0x40100402) {
      flagsWord3410 = *(uint *)(glContext + 0x3410) & 0xfffffeff;
    }
    else {
      flagsWord3410 = *(uint *)(glContext + 0x3410) | 0x100;
    }
    *(uint *)(glContext + 0x3410) = flagsWord3410;
  }
  pendingMatrixBits = (matrixChangeBits | pendingMatrixBits) & 0xfffffc;
  *(uint *)(glContext + 0x318) = *(uint *)(glContext + 0x318) | pendingMatrixBits;
  if ((*(char *)(glContext + 0x4664) != '\0') || (*(int *)(glContext + 0x5434) != 0)) {
    loopIndex = 0;
    remaining = 0x18;
    do {
      if (((pendingMatrixBits | (pendingMatrixBits >> 4 | pendingMatrixBits >> 3) & 1) >> (loopIndex & 0x3f) & 1) != 0) {
        glContextWord5434 = *(int *)(glContext + 0x5434);
        if (glContextWord5434 == 0) {
          dirtyBitIndex = *(byte *)(loopIndex * 4 + *(int *)(glContext + 0x5420) + 0x328);
        }
        else {
          dirtyBitIndex = *(byte *)(loopIndex * 4 + *(int *)(*(int *)(glContext + 0x5430) + 0x20) + 0x35c);
        }
        tableEntry = loopIndex * 4;
        dirtyWord324Ptr = (dirtyBitIndex >> 3 & 0x1c) + glContext;
        *(uint *)(dirtyWord324Ptr + 0x324) = *(uint *)(dirtyWord324Ptr + 0x324) | 1 << (dirtyBitIndex & 0x1f);
        if (glContextWord5434 == 0) {
          dirtyBitIndex = *(byte *)(tableEntry + *(int *)(glContext + 0x5420) + 0x329);
        }
        else {
          dirtyBitIndex = *(byte *)(tableEntry + *(int *)(*(int *)(glContext + 0x5430) + 0x20) + 0x35d);
        }
        dirtyWord324Ptr = (dirtyBitIndex >> 3 & 0x1c) + glContext;
        *(uint *)(dirtyWord324Ptr + 0x324) = *(uint *)(dirtyWord324Ptr + 0x324) | 1 << (dirtyBitIndex & 0x1f);
        if (glContextWord5434 == 0) {
          dirtyBitIndex = *(byte *)(tableEntry + *(int *)(glContext + 0x5420) + 0x32a);
        }
        else {
          dirtyBitIndex = *(byte *)(tableEntry + *(int *)(*(int *)(glContext + 0x5430) + 0x20) + 0x35e);
        }
        dirtyWord324Ptr = (dirtyBitIndex >> 3 & 0x1c) + glContext;
        *(uint *)(dirtyWord324Ptr + 0x324) = *(uint *)(dirtyWord324Ptr + 0x324) | 1 << (dirtyBitIndex & 0x1f);
        if (glContextWord5434 == 0) {
          dirtyBitIndex = *(byte *)(tableEntry + *(int *)(glContext + 0x5420) + 0x32b);
        }
        else {
          dirtyBitIndex = *(byte *)(tableEntry + *(int *)(*(int *)(glContext + 0x5430) + 0x20) + 0x35f);
        }
        dirtyWord324Ptr = (dirtyBitIndex >> 3 & 0x1c) + glContext;
        *(uint *)(dirtyWord324Ptr + 0x324) = *(uint *)(dirtyWord324Ptr + 0x324) | 1 << (dirtyBitIndex & 0x1f);
        if (glContextWord5434 == 0) {
          dirtyBitIndex = *(byte *)(tableEntry + *(int *)(glContext + 0x5420) + 0x388);
        }
        else {
          dirtyBitIndex = *(byte *)(tableEntry + *(int *)(*(int *)(glContext + 0x5430) + 0x20) + 0x3bc);
        }
        dirtyWord324Ptr = (dirtyBitIndex >> 3 & 0x1c) + glContext;
        *(uint *)(dirtyWord324Ptr + 0x324) = *(uint *)(dirtyWord324Ptr + 0x324) | 1 << (dirtyBitIndex & 0x1f);
        if (glContextWord5434 == 0) {
          dirtyBitIndex = *(byte *)(tableEntry + *(int *)(glContext + 0x5420) + 0x389);
        }
        else {
          dirtyBitIndex = *(byte *)(tableEntry + *(int *)(*(int *)(glContext + 0x5430) + 0x20) + 0x3bd);
        }
        dirtyWord324Ptr = (dirtyBitIndex >> 3 & 0x1c) + glContext;
        *(uint *)(dirtyWord324Ptr + 0x324) = *(uint *)(dirtyWord324Ptr + 0x324) | 1 << (dirtyBitIndex & 0x1f);
        if (glContextWord5434 == 0) {
          dirtyBitIndex = *(byte *)(tableEntry + *(int *)(glContext + 0x5420) + 0x38a);
        }
        else {
          dirtyBitIndex = *(byte *)(tableEntry + *(int *)(*(int *)(glContext + 0x5430) + 0x20) + 0x3be);
        }
        dirtyWord324Ptr = (dirtyBitIndex >> 3 & 0x1c) + glContext;
        *(uint *)(dirtyWord324Ptr + 0x324) = *(uint *)(dirtyWord324Ptr + 0x324) | 1 << (dirtyBitIndex & 0x1f);
        if (glContextWord5434 == 0) {
          dirtyBitIndex = *(byte *)(tableEntry + *(int *)(glContext + 0x5420) + 0x38b);
        }
        else {
          dirtyBitIndex = *(byte *)(tableEntry + *(int *)(*(int *)(glContext + 0x5430) + 0x20) + 0x3bf);
        }
        dirtyWord324Ptr = (dirtyBitIndex >> 3 & 0x1c) + glContext;
        *(uint *)(dirtyWord324Ptr + 0x324) = *(uint *)(dirtyWord324Ptr + 0x324) | 1 << (dirtyBitIndex & 0x1f);
        if (glContextWord5434 == 0) {
          dirtyBitIndex = *(byte *)(tableEntry + *(int *)(glContext + 0x5420) + 1000);
        }
        else {
          dirtyBitIndex = *(byte *)(tableEntry + *(int *)(*(int *)(glContext + 0x5430) + 0x20) + 0x41c);
        }
        dirtyWord324Ptr = (dirtyBitIndex >> 3 & 0x1c) + glContext;
        *(uint *)(dirtyWord324Ptr + 0x324) = *(uint *)(dirtyWord324Ptr + 0x324) | 1 << (dirtyBitIndex & 0x1f);
        if (glContextWord5434 == 0) {
          dirtyBitIndex = *(byte *)(tableEntry + *(int *)(glContext + 0x5420) + 0x3e9);
        }
        else {
          dirtyBitIndex = *(byte *)(tableEntry + *(int *)(*(int *)(glContext + 0x5430) + 0x20) + 0x41d);
        }
        dirtyWord324Ptr = (dirtyBitIndex >> 3 & 0x1c) + glContext;
        *(uint *)(dirtyWord324Ptr + 0x324) = *(uint *)(dirtyWord324Ptr + 0x324) | 1 << (dirtyBitIndex & 0x1f);
        if (glContextWord5434 == 0) {
          dirtyBitIndex = *(byte *)(tableEntry + *(int *)(glContext + 0x5420) + 0x3ea);
        }
        else {
          dirtyBitIndex = *(byte *)(tableEntry + *(int *)(*(int *)(glContext + 0x5430) + 0x20) + 0x41e);
        }
        dirtyWord324Ptr = (dirtyBitIndex >> 3 & 0x1c) + glContext;
        *(uint *)(dirtyWord324Ptr + 0x324) = *(uint *)(dirtyWord324Ptr + 0x324) | 1 << (dirtyBitIndex & 0x1f);
        if (glContextWord5434 == 0) {
          dirtyBitIndex = *(byte *)(tableEntry + *(int *)(glContext + 0x5420) + 0x3eb);
        }
        else {
          dirtyBitIndex = *(byte *)(tableEntry + *(int *)(*(int *)(glContext + 0x5430) + 0x20) + 0x41f);
        }
        dirtyWord324Ptr = (dirtyBitIndex >> 3 & 0x1c) + glContext;
        *(uint *)(dirtyWord324Ptr + 0x324) = *(uint *)(dirtyWord324Ptr + 0x324) | 1 << (dirtyBitIndex & 0x1f);
        if (glContextWord5434 == 0) {
          dirtyBitIndex = *(byte *)(tableEntry + *(int *)(glContext + 0x5420) + 0x448);
        }
        else {
          dirtyBitIndex = *(byte *)(tableEntry + *(int *)(*(int *)(glContext + 0x5430) + 0x20) + 0x47c);
        }
        dirtyWord324Ptr = (dirtyBitIndex >> 3 & 0x1c) + glContext;
        *(uint *)(dirtyWord324Ptr + 0x324) = *(uint *)(dirtyWord324Ptr + 0x324) | 1 << (dirtyBitIndex & 0x1f);
        if (glContextWord5434 == 0) {
          dirtyBitIndex = *(byte *)(tableEntry + *(int *)(glContext + 0x5420) + 0x449);
        }
        else {
          dirtyBitIndex = *(byte *)(tableEntry + *(int *)(*(int *)(glContext + 0x5430) + 0x20) + 0x47d);
        }
        dirtyWord324Ptr = (dirtyBitIndex >> 3 & 0x1c) + glContext;
        *(uint *)(dirtyWord324Ptr + 0x324) = *(uint *)(dirtyWord324Ptr + 0x324) | 1 << (dirtyBitIndex & 0x1f);
        if (glContextWord5434 == 0) {
          dirtyBitIndex = *(byte *)(tableEntry + *(int *)(glContext + 0x5420) + 0x44a);
        }
        else {
          dirtyBitIndex = *(byte *)(tableEntry + *(int *)(*(int *)(glContext + 0x5430) + 0x20) + 0x47e);
        }
        dirtyWord324Ptr = (dirtyBitIndex >> 3 & 0x1c) + glContext;
        *(uint *)(dirtyWord324Ptr + 0x324) = *(uint *)(dirtyWord324Ptr + 0x324) | 1 << (dirtyBitIndex & 0x1f);
        if (glContextWord5434 == 0) {
          dirtyBitIndex = *(byte *)(tableEntry + *(int *)(glContext + 0x5420) + 1099);
        }
        else {
          dirtyBitIndex = *(byte *)(tableEntry + *(int *)(*(int *)(glContext + 0x5430) + 0x20) + 0x47f);
        }
        dirtyWord324PtrLast = (dirtyBitIndex >> 3 & 0x1c) + glContext;
        tableEntry = tableEntry + *(int *)(glContext + 0x5424);
        *(uint *)(dirtyWord324PtrLast + 0x324) = *(uint *)(dirtyWord324PtrLast + 0x324) | 1 << (dirtyBitIndex & 0x1f);
        dirtyWord348Ptr = (*(byte *)(tableEntry + 0x328) >> 3 & 0x1c) + glContext;
        *(uint *)(dirtyWord348Ptr + 0x348) = *(uint *)(dirtyWord348Ptr + 0x348) | 1 << (*(byte *)(tableEntry + 0x328) & 0x1f)
        ;
        dirtyWord348Ptr = (*(byte *)(tableEntry + 0x329) >> 3 & 0x1c) + glContext;
        *(uint *)(dirtyWord348Ptr + 0x348) = *(uint *)(dirtyWord348Ptr + 0x348) | 1 << (*(byte *)(tableEntry + 0x329) & 0x1f)
        ;
        dirtyWord348Ptr = (*(byte *)(tableEntry + 0x32a) >> 3 & 0x1c) + glContext;
        *(uint *)(dirtyWord348Ptr + 0x348) = *(uint *)(dirtyWord348Ptr + 0x348) | 1 << (*(byte *)(tableEntry + 0x32a) & 0x1f)
        ;
        dirtyWord348Ptr = (*(byte *)(tableEntry + 0x32b) >> 3 & 0x1c) + glContext;
        *(uint *)(dirtyWord348Ptr + 0x348) = *(uint *)(dirtyWord348Ptr + 0x348) | 1 << (*(byte *)(tableEntry + 0x32b) & 0x1f)
        ;
        dirtyWord348Ptr = (*(byte *)(tableEntry + 0x388) >> 3 & 0x1c) + glContext;
        *(uint *)(dirtyWord348Ptr + 0x348) = *(uint *)(dirtyWord348Ptr + 0x348) | 1 << (*(byte *)(tableEntry + 0x388) & 0x1f)
        ;
        dirtyWord348Ptr = (*(byte *)(tableEntry + 0x389) >> 3 & 0x1c) + glContext;
        *(uint *)(dirtyWord348Ptr + 0x348) = *(uint *)(dirtyWord348Ptr + 0x348) | 1 << (*(byte *)(tableEntry + 0x389) & 0x1f)
        ;
        dirtyWord348Ptr = (*(byte *)(tableEntry + 0x38a) >> 3 & 0x1c) + glContext;
        *(uint *)(dirtyWord348Ptr + 0x348) = *(uint *)(dirtyWord348Ptr + 0x348) | 1 << (*(byte *)(tableEntry + 0x38a) & 0x1f)
        ;
        dirtyWord348Ptr = (*(byte *)(tableEntry + 0x38b) >> 3 & 0x1c) + glContext;
        *(uint *)(dirtyWord348Ptr + 0x348) = *(uint *)(dirtyWord348Ptr + 0x348) | 1 << (*(byte *)(tableEntry + 0x38b) & 0x1f)
        ;
        dirtyWord348Ptr = (*(byte *)(tableEntry + 1000) >> 3 & 0x1c) + glContext;
        *(uint *)(dirtyWord348Ptr + 0x348) = *(uint *)(dirtyWord348Ptr + 0x348) | 1 << (*(byte *)(tableEntry + 1000) & 0x1f);
        dirtyWord348Ptr = (*(byte *)(tableEntry + 0x3e9) >> 3 & 0x1c) + glContext;
        *(uint *)(dirtyWord348Ptr + 0x348) = *(uint *)(dirtyWord348Ptr + 0x348) | 1 << (*(byte *)(tableEntry + 0x3e9) & 0x1f)
        ;
        dirtyWord348Ptr = (*(byte *)(tableEntry + 0x3ea) >> 3 & 0x1c) + glContext;
        *(uint *)(dirtyWord348Ptr + 0x348) = *(uint *)(dirtyWord348Ptr + 0x348) | 1 << (*(byte *)(tableEntry + 0x3ea) & 0x1f)
        ;
        dirtyWord348Ptr = (*(byte *)(tableEntry + 0x3eb) >> 3 & 0x1c) + glContext;
        *(uint *)(dirtyWord348Ptr + 0x348) = *(uint *)(dirtyWord348Ptr + 0x348) | 1 << (*(byte *)(tableEntry + 0x3eb) & 0x1f)
        ;
        dirtyWord348Ptr = (*(byte *)(tableEntry + 0x448) >> 3 & 0x1c) + glContext;
        *(uint *)(dirtyWord348Ptr + 0x348) = *(uint *)(dirtyWord348Ptr + 0x348) | 1 << (*(byte *)(tableEntry + 0x448) & 0x1f)
        ;
        dirtyWord348Ptr = (*(byte *)(tableEntry + 0x449) >> 3 & 0x1c) + glContext;
        *(uint *)(dirtyWord348Ptr + 0x348) = *(uint *)(dirtyWord348Ptr + 0x348) | 1 << (*(byte *)(tableEntry + 0x449) & 0x1f)
        ;
        dirtyWord348Ptr = (*(byte *)(tableEntry + 0x44a) >> 3 & 0x1c) + glContext;
        *(uint *)(dirtyWord348Ptr + 0x348) = *(uint *)(dirtyWord348Ptr + 0x348) | 1 << (*(byte *)(tableEntry + 0x44a) & 0x1f)
        ;
        dirtyWord348Ptr = (*(byte *)(tableEntry + 1099) >> 3 & 0x1c) + glContext;
        *(uint *)(dirtyWord348Ptr + 0x348) = *(uint *)(dirtyWord348Ptr + 0x348) | 1 << (*(byte *)(tableEntry + 1099) & 0x1f);
      }
      loopIndex = loopIndex + 1;
      remaining = remaining + -1;
    } while (remaining != 0);
  }
  *(undefined4 *)(glContext + 0x50ac) = 0;
  *(uint *)(glContext + 0x497c) = *(uint *)(glContext + 0x497c) | 0x1d;
  return lastResult;
}

/* _gleApplyViewScissorTransform @ 0x8674 (296 bytes) */
int _gleApplyViewScissorTransform(glContext)
  int glContext;
{
  float glContextFloat4a1c;
  float glContextFloat4a20;
  float glContextFloat4a24;
  float glContextFloat4a28;
  
  glContextFloat4a1c = *(float *)(glContext + 0x4a1c);
  glContextFloat4a20 = *(float *)(glContext + 0x4a20);
  glContextFloat4a24 = *(float *)(glContext + 0x4a24);
  glContextFloat4a28 = *(float *)(glContext + 0x4a28);
  ((void (*)())_gleMultMatrix)(glContext + 0x1c80,glContext + 0x1cc0,glContext + 0x1bc0);
  *(float *)(glContext + 0x27c0) =
       glContextFloat4a1c * *(float *)(glContext + 0x1bc0) + glContextFloat4a20 * *(float *)(glContext + 0x1bcc);
  *(float *)(glContext + 0x27c4) =
       glContextFloat4a24 * *(float *)(glContext + 0x1bc4) + glContextFloat4a28 * *(float *)(glContext + 0x1bcc);
  *(undefined4 *)(glContext + 0x27c8) = *(undefined4 *)(glContext + 0x1bc8);
  *(undefined4 *)(glContext + 0x27cc) = *(undefined4 *)(glContext + 0x1bcc);
  *(float *)(glContext + 0x27d0) =
       glContextFloat4a1c * *(float *)(glContext + 0x1bd0) + glContextFloat4a20 * *(float *)(glContext + 0x1bdc);
  *(float *)(glContext + 0x27d4) =
       glContextFloat4a24 * *(float *)(glContext + 0x1bd4) + glContextFloat4a28 * *(float *)(glContext + 0x1bdc);
  *(undefined4 *)(glContext + 0x27d8) = *(undefined4 *)(glContext + 0x1bd8);
  *(undefined4 *)(glContext + 0x27dc) = *(undefined4 *)(glContext + 0x1bdc);
  *(float *)(glContext + 0x27e0) =
       glContextFloat4a1c * *(float *)(glContext + 0x1be0) + glContextFloat4a20 * *(float *)(glContext + 0x1bec);
  *(float *)(glContext + 0x27e4) =
       glContextFloat4a24 * *(float *)(glContext + 0x1be4) + glContextFloat4a28 * *(float *)(glContext + 0x1bec);
  *(undefined4 *)(glContext + 0x27e8) = *(undefined4 *)(glContext + 0x1be8);
  *(undefined4 *)(glContext + 0x27ec) = *(undefined4 *)(glContext + 0x1bec);
  *(float *)(glContext + 0x27f0) =
       glContextFloat4a1c * *(float *)(glContext + 0x1bf0) + glContextFloat4a20 * *(float *)(glContext + 0x1bfc);
  *(float *)(glContext + 0x27f4) =
       glContextFloat4a24 * *(float *)(glContext + 0x1bf4) + glContextFloat4a28 * *(float *)(glContext + 0x1bfc);
  *(undefined4 *)(glContext + 0x27f8) = *(undefined4 *)(glContext + 0x1bf8);
  *(undefined4 *)(glContext + 0x27fc) = *(undefined4 *)(glContext + 0x1bfc);
  return;
}

/* saveFP @ 0x879c (12 bytes) */
void saveFP()
{
  return;
}

/* FUN_000087a8 @ 0x87a8 (4 bytes) */
void FUN_000087a8()
{
  return;
}

/* FUN_000087ac @ 0x87ac (4 bytes) */
void FUN_000087ac()
{
  return;
}

/* FUN_000087b0 @ 0x87b0 (8 bytes) */
void FUN_000087b0()
{
  return;
}

/* FUN_000087b8 @ 0x87b8 (8 bytes) */
void FUN_000087b8()
{
  return;
}

/* FUN_000087c0 @ 0x87c0 (4 bytes) */
void FUN_000087c0()
{
  return;
}

/* FUN_000087c4 @ 0x87c4 (4 bytes) */
void FUN_000087c4()
{
  return;
}

/* FUN_000087c8 @ 0x87c8 (4 bytes) */
void FUN_000087c8()
{
  return;
}

/* FUN_000087cc @ 0x87cc (4 bytes) */
void FUN_000087cc()
{
  return;
}

/* FUN_000087d0 @ 0x87d0 (4 bytes) */
void FUN_000087d0()
{
  return;
}

/* FUN_000087d4 @ 0x87d4 (24 bytes) */
void FUN_000087d4()
{
  return;
}

/* _gleMultMatrix @ 0x87ec (836 bytes) */
void _gleMultMatrix(leftMatrix, rightMatrix, product)
  float *leftMatrix;
  float *rightMatrix;
  float *product;
{
  *product = leftMatrix[0xc] * rightMatrix[3] +
             (leftMatrix[8] * rightMatrix[2] + (*leftMatrix * *rightMatrix + leftMatrix[4] * rightMatrix[1]));
  product[4] = leftMatrix[0xc] * rightMatrix[7] +
               (leftMatrix[8] * rightMatrix[6] + (*leftMatrix * rightMatrix[4] + leftMatrix[4] * rightMatrix[5]));
  product[8] = leftMatrix[0xc] * rightMatrix[0xb] +
               (leftMatrix[8] * rightMatrix[10] + (*leftMatrix * rightMatrix[8] + leftMatrix[4] * rightMatrix[9]));
  product[0xc] = leftMatrix[0xc] * rightMatrix[0xf] +
                 (leftMatrix[8] * rightMatrix[0xe] + (*leftMatrix * rightMatrix[0xc] + leftMatrix[4] * rightMatrix[0xd]));
  product[1] = leftMatrix[0xd] * rightMatrix[3] +
               (leftMatrix[9] * rightMatrix[2] + (leftMatrix[1] * *rightMatrix + leftMatrix[5] * rightMatrix[1]));
  product[5] = leftMatrix[0xd] * rightMatrix[7] +
               (leftMatrix[9] * rightMatrix[6] + (leftMatrix[1] * rightMatrix[4] + leftMatrix[5] * rightMatrix[5]));
  product[9] = leftMatrix[0xd] * rightMatrix[0xb] +
               (leftMatrix[9] * rightMatrix[10] + (leftMatrix[1] * rightMatrix[8] + leftMatrix[5] * rightMatrix[9]));
  product[0xd] = leftMatrix[0xd] * rightMatrix[0xf] +
                 (leftMatrix[9] * rightMatrix[0xe] + (leftMatrix[1] * rightMatrix[0xc] + leftMatrix[5] * rightMatrix[0xd]));
  product[2] = leftMatrix[0xe] * rightMatrix[3] +
               (leftMatrix[10] * rightMatrix[2] + (leftMatrix[2] * *rightMatrix + leftMatrix[6] * rightMatrix[1]));
  product[6] = leftMatrix[0xe] * rightMatrix[7] +
               (leftMatrix[10] * rightMatrix[6] + (leftMatrix[2] * rightMatrix[4] + leftMatrix[6] * rightMatrix[5]));
  product[10] = leftMatrix[0xe] * rightMatrix[0xb] +
                (leftMatrix[10] * rightMatrix[10] + (leftMatrix[2] * rightMatrix[8] + leftMatrix[6] * rightMatrix[9]));
  product[0xe] = leftMatrix[0xe] * rightMatrix[0xf] +
                 (leftMatrix[10] * rightMatrix[0xe] + (leftMatrix[2] * rightMatrix[0xc] + leftMatrix[6] * rightMatrix[0xd]));
  product[3] = leftMatrix[0xf] * rightMatrix[3] +
               (leftMatrix[0xb] * rightMatrix[2] + (leftMatrix[3] * *rightMatrix + leftMatrix[7] * rightMatrix[1]));
  product[7] = leftMatrix[0xf] * rightMatrix[7] +
               (leftMatrix[0xb] * rightMatrix[6] + (leftMatrix[3] * rightMatrix[4] + leftMatrix[7] * rightMatrix[5]));
  product[0xb] = leftMatrix[0xf] * rightMatrix[0xb] +
                 (leftMatrix[0xb] * rightMatrix[10] + (leftMatrix[3] * rightMatrix[8] + leftMatrix[7] * rightMatrix[9]));
  product[0xf] = leftMatrix[0xf] * rightMatrix[0xf] +
                 (leftMatrix[0xb] * rightMatrix[0xe] + (leftMatrix[3] * rightMatrix[0xc] + leftMatrix[7] * rightMatrix[0xd]))
  ;
  return;
}

/* restFP @ 0x8b30 (56 bytes) */
void restFP()
{
  return;
}

/* FUN_00008b68 @ 0x8b68 (28 bytes) */
void FUN_00008b68()
{
  return;
}

/* _gleUpdateTextureTransform @ 0x8b84 (272 bytes) */
int _gleUpdateTextureTransform(glContext)
  int glContext;
{
  bool bVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  int iVar5;
  
  iVar5 = _gleTexEnableBits(glContext);
  puVar3 = PTR__gleTextureMatTransPtrDivW_001115ec;
  puVar2 = PTR__gleMultiTextureMatTransPtr_001115e0;
  puVar4 = PTR__gleTextureMatTrans_Identity_001115f4;
  if (((iVar5 != 0) && (*(char *)(glContext + 0x4664) == '\0')) && (*(int *)(glContext + 0x5434) == 0))
  {
    bVar1 = false;
    if (((*(uint *)(*(int *)(glContext + 0x468c) + 0x94) & 4) == 0) &&
       (*(int *)(glContext + 0x4e1c) == 0x1c00)) {
      bVar1 = true;
    }
    if (iVar5 != 1) {
      *(undefined **)(glContext + 0x506c) = PTR__gleMultiTextureMatTrans_001115e4;
      *(undefined **)(glContext + 0x5074) = puVar2;
      puVar3 = PTR__gleTextureMatTransPtrDivW_001115ec;
      puVar2 = PTR__gleTextureMatTrans_001115e8;
      if (bVar1) {
        *(undefined **)(glContext + 0x5070) = PTR__gleTextureMatTransDivW_001115f0;
        *(undefined **)(glContext + 0x5078) = puVar3;
        return;
      }
      *(undefined **)(glContext + 0x5078) = PTR__gleTextureMatTrans_001115e8;
      *(undefined **)(glContext + 0x5070) = puVar2;
      return;
    }
    puVar4 = PTR__gleTextureMatTrans_001115e8;
    if (bVar1) {
      *(undefined **)(glContext + 0x506c) = PTR__gleTextureMatTransDivW_001115f0;
      *(undefined **)(glContext + 0x5074) = puVar3;
      return;
    }
  }
  *(undefined **)(glContext + 0x5074) = puVar4;
  *(undefined **)(glContext + 0x506c) = puVar4;
  return;
}

/* _gleUpdateDepthRangeData @ 0x8c94 (156 bytes) */
void _gleUpdateDepthRangeData(int glContext,double unusedFloatArg1,double unusedFloatArg2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  float depthFarFloat;
  float depthHalfRangeFloat;
  float depthCenterFloat;
  float rendererInfoFloat4;
  double depthNear;
  double depthHalfRange;
  
  depthNear = *(double *)(glContext + 0x1b90);
  depthFarFloat = (float)*(double *)(glContext + 0x1b98);
  depthHalfRange = (*(double *)(glContext + 0x1b98) - depthNear) * DOUBLE_00108dc0;
  rendererInfoFloat4 = *(float *)(*(int *)(glContext + 0x468c) + 4);
  *(float *)(glContext + 0xf8) = (float)depthNear;
  depthHalfRangeFloat = (float)depthHalfRange;
  *(float *)(glContext + 0x108) = depthFarFloat;
  *(float *)(glContext + 0x4a54) = rendererInfoFloat4;
  depthCenterFloat = (float)(depthHalfRange + depthNear);
  *(float *)(glContext + 0x1b78) = depthHalfRangeFloat;
  *(float *)(glContext + 0x4a3c) = depthHalfRangeFloat;
  *(float *)(glContext + 0x1b88) = depthCenterFloat;
  *(float *)(glContext + 0x4a40) = depthCenterFloat;
  if (*(int *)(glContext + 0x4e1c) == 0x1c00) {
    *(float *)(glContext + 0x1b88) = depthCenterFloat * rendererInfoFloat4;
    *(float *)(glContext + 0x108) = depthFarFloat * rendererInfoFloat4;
    *(float *)(glContext + 0x1b78) = depthHalfRangeFloat * rendererInfoFloat4;
    *(float *)(glContext + 0xf8) = (float)depthNear * rendererInfoFloat4;
  }
  *(uint *)(glContext + 0x318) = *(uint *)(glContext + 0x318) | 1;
  return;
}

/* _gleUpdateTextureCoordGen @ 0x8d30 (1120 bytes) */
void _gleUpdateTextureCoordGen(glContext)
  int glContext;
{
  bool texGenEnabledR;
  bool texGenEnabledS;
  bool texGenEnabledT;
  char glContextByte53e6;
  char previousUnitFlag;
  ushort genModeS;
  undefined *multiVtxTexGenWrapEyeFunc;
  undefined *multiVtxTexGenWrapObjectFunc;
  undefined *multiVtxTexGenObjectSlowFunc;
  undefined *vtxTexGenObjectSlowFunc;
  undefined *multiVtxTexGenEyeSlowFunc;
  undefined *vtxTexGenEyeSlowFunc;
  undefined *multiVtxTexGenNormalSTRFunc;
  undefined *vtxTexGenNormalSTRFunc;
  undefined *multiVtxTexGenReflectSTFunc;
  undefined *vtxTexGenReflectSTFunc;
  undefined *multiVtxTexGenNormalSTFunc;
  undefined *vtxTexGenNormalSTFunc;
  undefined *multiVtxTexGenSphereSTFunc;
  undefined *vtxTexGenSphereSTFunc;
  undefined *multiVtxTexGenObjectSTFunc;
  undefined *vtxTexGenObjectSTFunc;
  undefined *multiVtxTexGenEyeSTFunc;
  undefined *vtxTexGenEyeSTFunc;
  undefined *multiVtxTexGenNoopFunc;
  int texGenState;
  int loopIndex;
  char *texGenFlagCursor;
  undefined *vtxTexGenNoopFunc;
  undefined *multiVtxTexGenSTRFunc;
  undefined *vtxTexGenReflectSTRFunc;
  int unitStateBase;
  int remaining;
  
  vtxTexGenNoopFunc = PTR__gleVtxTextureCoordGenNoop_001114ac;
  multiVtxTexGenNoopFunc = PTR__gleMultiVtxTextureCoordGenNoop_001114a8;
  vtxTexGenEyeSTFunc = PTR__gleVtxTextureCoordGenEyeST_001114a4;
  multiVtxTexGenEyeSTFunc = PTR__gleMultiVtxTextureCoordGenEyeST_001114a0;
  vtxTexGenObjectSTFunc = PTR__gleVtxTextureCoordGenObjectST_0011149c;
  multiVtxTexGenObjectSTFunc = PTR__gleMultiVtxTextureCoordGenObjectST_00111498;
  vtxTexGenSphereSTFunc = PTR__gleVtxTextureCoordGenSphereST_00111494;
  multiVtxTexGenSphereSTFunc = PTR__gleMultiVtxTextureCoordGenSphereST_00111490;
  vtxTexGenNormalSTFunc = PTR__gleVtxTextureCoordGenNormalST_0011148c;
  multiVtxTexGenNormalSTFunc = PTR__gleMultiVtxTextureCoordGenNormalST_00111488;
  vtxTexGenReflectSTFunc = PTR__gleVtxTextureCoordGenReflectST_00111484;
  multiVtxTexGenReflectSTFunc = PTR__gleMultiVtxTextureCoordGenReflectST_00111480;
  vtxTexGenNormalSTRFunc = PTR__gleVtxTextureCoordGenNormalSTR_0011147c;
  multiVtxTexGenNormalSTRFunc = PTR__gleMultiVtxTextureCoordGenNormalSTR_00111478;
  vtxTexGenEyeSlowFunc = PTR__gleVtxTextureCoordGenEyeSlow_0011146c;
  multiVtxTexGenEyeSlowFunc = PTR__gleMultiVtxTextureCoordGenEyeSlow_00111468;
  vtxTexGenObjectSlowFunc = PTR__gleVtxTextureCoordGenObjectSlow_00111464;
  multiVtxTexGenObjectSlowFunc = PTR__gleMultiVtxTextureCoordGenObjectSlow_00111460;
  multiVtxTexGenWrapObjectFunc = PTR__gleMultiVtxTextureCoordGenWrapObject_0011145c;
  multiVtxTexGenWrapEyeFunc = PTR__gleMultiVtxTextureCoordGenWrapEye_00111458;
  *(undefined **)(glContext + 0x53e0) = PTR__gleVtxTextureCoordGenNoop_001114ac;
  *(undefined1 *)(glContext + 0x53e4) = 0;
  loopIndex = 0;
  *(undefined1 *)(glContext + 0x53e5) = 0;
  glContextByte53e6 = *(char *)(glContext + 0x53e6);
  texGenState = glContext + 0x3d70;
  *(undefined1 *)(glContext + 0x53e6) = 0;
  *(undefined **)(glContext + 0x53dc) = vtxTexGenNoopFunc;
  texGenFlagCursor = (char *)(glContext + 0x531c);
  remaining = 8;
  unitStateBase = glContext;
  do {
    *(undefined **)(texGenFlagCursor + -8) = multiVtxTexGenNoopFunc;
    *(undefined **)(texGenFlagCursor + -4) = multiVtxTexGenNoopFunc;
    previousUnitFlag = *texGenFlagCursor;
    if (((*(char *)(texGenState + 8) == '\0') || (*(char *)(texGenState + 9) == '\0')) ||
       (*(char *)(texGenState + 0xb) != '\0')) {
LAB_00008f68:
      if (((*(char *)(texGenState + 8) == '\0') && (*(char *)(texGenState + 9) == '\0')) &&
         ((*(char *)(texGenState + 10) == '\0' && (*(char *)(texGenState + 0xb) == '\0')))) {
        *texGenFlagCursor = '\0';
      }
      else {
        *texGenFlagCursor = '\x01';
        texGenEnabledS = *(char *)(texGenState + 8) != '\0';
        if ((((((texGenEnabledS) && (*(short *)(texGenState + -0x88) == 0x2402)) ||
              ((texGenEnabledT = *(char *)(texGenState + 9) != '\0', texGenEnabledT &&
               (*(short *)(unitStateBase + 0x3d0c) == 0x2402)))) ||
             ((((texGenEnabledS && (*(short *)(unitStateBase + 0x3ce8) == -0x7aef)) ||
               ((texGenEnabledT && (*(short *)(unitStateBase + 0x3d0c) == -0x7aef)))) ||
              ((texGenEnabledR = *(char *)(texGenState + 10) != '\0', texGenEnabledR &&
               (*(short *)(unitStateBase + 0x3d30) == -0x7aef)))))) ||
            ((texGenEnabledS && (*(short *)(unitStateBase + 0x3ce8) == -0x7aee)))) ||
           (((texGenEnabledT && (*(short *)(unitStateBase + 0x3d0c) == -0x7aee)) ||
            ((texGenEnabledR && (*(short *)(unitStateBase + 0x3d30) == -0x7aee)))))) {
          *(undefined1 *)(glContext + 0x53e6) = 1;
LAB_0000909c:
          *(undefined1 *)(glContext + 0x53e5) = 1;
          *(undefined **)(glContext + 0x53e0) = vtxTexGenEyeSlowFunc;
          *(undefined **)(texGenFlagCursor + -4) = multiVtxTexGenEyeSlowFunc;
        }
        else if ((((*(char *)(texGenState + 8) != '\0') && (*(short *)(texGenState + -0x88) == 0x2400)) ||
                 (((*(char *)(texGenState + 9) != '\0' && (*(short *)(unitStateBase + 0x3d0c) == 0x2400)) ||
                  ((*(char *)(texGenState + 10) != '\0' && (*(short *)(unitStateBase + 0x3d30) == 0x2400))))))
                || ((*(char *)(texGenState + 0xb) != '\0' && (*(short *)(unitStateBase + 0x3d54) == 0x2400))))
        goto LAB_0000909c;
        if (((((*(char *)(texGenState + 8) != '\0') && (*(short *)(texGenState + -0x88) == 0x2401)) ||
             ((*(char *)(texGenState + 9) != '\0' && (*(short *)(unitStateBase + 0x3d0c) == 0x2401)))) ||
            ((*(char *)(texGenState + 10) != '\0' && (*(short *)(unitStateBase + 0x3d30) == 0x2401)))) ||
           ((*(char *)(texGenState + 0xb) != '\0' && (*(short *)(unitStateBase + 0x3d54) == 0x2401)))) {
          *(undefined1 *)(glContext + 0x53e4) = 1;
          *(undefined **)(glContext + 0x53dc) = vtxTexGenObjectSlowFunc;
          *(undefined **)(texGenFlagCursor + -8) = multiVtxTexGenObjectSlowFunc;
        }
      }
    }
    else {
      *texGenFlagCursor = '\x01';
      vtxTexGenReflectSTRFunc = PTR__gleVtxTextureCoordGenReflectSTR_00111474;
      genModeS = *(ushort *)(texGenState + -0x88);
      if (genModeS != *(ushort *)(texGenState + -100)) goto LAB_00008f68;
      if (*(char *)(texGenState + 10) == '\0') {
        if (genModeS == 0x2401) {
          *(undefined1 *)(glContext + 0x53e4) = 1;
          *(undefined **)(glContext + 0x53dc) = vtxTexGenObjectSTFunc;
          *(undefined **)(texGenFlagCursor + -8) = multiVtxTexGenObjectSTFunc;
        }
        else if (genModeS < 0x2402) {
          if (genModeS == 0x2400) {
            *(undefined1 *)(glContext + 0x53e5) = 1;
            *(undefined **)(glContext + 0x53e0) = vtxTexGenEyeSTFunc;
            *(undefined **)(texGenFlagCursor + -4) = multiVtxTexGenEyeSTFunc;
          }
          else {
LAB_00008ef8:
            *(undefined1 *)(glContext + 0x53e5) = 1;
            *(undefined1 *)(glContext + 0x53e6) = 1;
            *(undefined **)(glContext + 0x53e0) = vtxTexGenReflectSTFunc;
            *(undefined **)(texGenFlagCursor + -4) = multiVtxTexGenReflectSTFunc;
          }
        }
        else if (genModeS == 0x2402) {
          *(undefined1 *)(glContext + 0x53e6) = 1;
          *(undefined1 *)(glContext + 0x53e5) = 1;
          *(undefined **)(glContext + 0x53e0) = vtxTexGenSphereSTFunc;
          *(undefined **)(texGenFlagCursor + -4) = multiVtxTexGenSphereSTFunc;
        }
        else {
          if (genModeS != 0x8511) goto LAB_00008ef8;
          *(undefined1 *)(glContext + 0x53e6) = 1;
          *(undefined1 *)(glContext + 0x53e5) = 1;
          *(undefined **)(glContext + 0x53e0) = vtxTexGenNormalSTFunc;
          *(undefined **)(texGenFlagCursor + -4) = multiVtxTexGenNormalSTFunc;
        }
      }
      else {
        if (genModeS != *(ushort *)(texGenState + -0x40)) goto LAB_00008f68;
        if (genModeS == 0x8511) {
          *(undefined **)(glContext + 0x53e0) = vtxTexGenNormalSTRFunc;
          *(undefined1 *)(glContext + 0x53e6) = 1;
          multiVtxTexGenSTRFunc = multiVtxTexGenNormalSTRFunc;
        }
        else {
          if (genModeS != 0x8512) goto LAB_00008f68;
          *(undefined1 *)(glContext + 0x53e6) = 1;
          *(undefined **)(glContext + 0x53e0) = vtxTexGenReflectSTRFunc;
          multiVtxTexGenSTRFunc = PTR__gleMultiVtxTextureCoordGenReflectSTR_00111470;
        }
        *(undefined1 *)(glContext + 0x53e5) = 1;
        *(undefined **)(texGenFlagCursor + -4) = multiVtxTexGenSTRFunc;
      }
    }
    if ((loopIndex != 0) && (*texGenFlagCursor != '\0')) {
      *(undefined **)(glContext + 0x53dc) = multiVtxTexGenWrapObjectFunc;
      *(undefined **)(glContext + 0x53e0) = multiVtxTexGenWrapEyeFunc;
    }
    if (*texGenFlagCursor != previousUnitFlag) {
      *(uint *)(glContext + 0x50ac) = *(uint *)(glContext + 0x50ac) | 1;
    }
    loopIndex = loopIndex + 1;
    texGenFlagCursor = texGenFlagCursor + 0xc;
    unitStateBase = unitStateBase + 0x94;
    texGenState = texGenState + 0x94;
    remaining = remaining + -1;
    if (remaining == 0) {
      if (*(char *)(glContext + 0x53e6) == glContextByte53e6) {
        return;
      }
      ((void (*)())_gleUpdateInverseNeeds)(glContext);
      return;
    }
  } while( true );
}

/* _gleUpdateTextureParams @ 0x9190 (280 bytes) */
int _gleUpdateTextureParams(glContext, param_2)
  int glContext;
  uint param_2;
{
  undefined *puVar1;
  uint uVar2;
  int extraout_r3;
  int iVar3;
  uint glContextWord514c;
  
  if (*(char *)(glContext + 0x3ce4) == '\0') {
    uVar2 = *(uint *)(param_2 * 0x7c + glContext + 0x3534) & 0x1f;
  }
  else {
    uVar2 = (uint)*(ushort *)(param_2 * 0x7c + glContext + 0x3564);
  }
  glContextWord514c = *(uint *)(glContext + 0x514c);
  iVar3 = glContext;
  if ((glContextWord514c >> (param_2 & 0x3f) & 1) != -((int)-uVar2 >> 0x1f)) {
    if (-((int)-uVar2 >> 0x1f) == 0) {
      *(uint *)(glContext + 0x514c) =
           glContextWord514c & (-2 << (param_2 & 0x1f) | 0xfffffffeU >> 0x20 - (param_2 & 0x1f));
      *(uint *)(glContext + 0x4980) = *(uint *)(glContext + 0x4980) & ~(8 << (param_2 & 0x3f));
    }
    else {
      *(uint *)(glContext + 0x514c) = glContextWord514c | 1 << (param_2 & 0x3f);
      *(uint *)(glContext + 0x4980) = *(uint *)(glContext + 0x4980) | 8 << (param_2 & 0x3f);
    }
    *(uint *)(glContext + 0x50ac) = *(uint *)(glContext + 0x50ac) | 0x10000 << (param_2 & 0x3f);
    ((void (*)())_gleSelectVertexSubmitFunc)(glContext);
    puVar1 = PTR__gleSetClipInterpFunc_00112038;
    *(undefined **)(glContext + 0x49c8) = PTR__gleSetEyeInterpFunc_0011203c;
    *(undefined **)(glContext + 0x49cc) = puVar1;
    iVar3 = extraout_r3;
  }
  *(uint *)(glContext + 0x314) = *(uint *)(glContext + 0x314) | 1 << (param_2 & 0x3f);
  return iVar3;
}

/* _gleUpdateFogData @ 0x92a8 (348 bytes) */
double _gleUpdateFogData(int glContext)
{
  float fVar1;
  float fVar2;
  undefined2 uVar4;
  uint uVar3;
  int glContextPtr4854;
  undefined *puVar6;
  bool bVar7;
  double in_f1;
  
  fVar1 = *(float *)(glContext + 0x3158) - *(float *)(glContext + 0x3154);
  bVar7 = fVar1 < FLOAT_00108e80;
  *(float *)(glContext + 0x315c) = fVar1;
  if ((!bVar7) || (fVar2 = FLOAT_00108eb4, !(FLOAT_00108f3c < fVar1))) {
    fVar2 = FLOAT_00108e54 / fVar1;
  }
  *(float *)(glContext + 0x315c) = fVar2;
  puVar6 = PTR__gleFogExp_00110e28;
  if (*(char *)(glContext + 0x316a) == '\0') {
    uVar3 = *(uint *)(glContext + 0x4980) & 0xfffffffb;
    *(undefined2 *)(glContext + 0x4fe8) = 0;
    *(undefined **)(glContext + 0x4fe4) = puVar6;
  }
  else {
    glContextPtr4854 = *(int *)(glContext + 0x4854);
    if (*(short *)(glContext + 0x3164) == 0x800) {
      uVar4 = 8;
    }
    else if (*(short *)(glContext + 0x3164) == 0x2601) {
      uVar4 = 4;
      puVar6 = PTR__gleFogLinear_00110e2c;
    }
    else {
      uVar4 = 0xc;
      puVar6 = PTR__gleFogExp2_00110e24;
    }
    *(undefined **)(glContext + 0x4fe4) = puVar6;
    *(undefined2 *)(glContext + 0x4fe8) = uVar4;
    if (*(short *)(glContext + 0x3166) == -0x7baf) {
      *(ushort *)(glContext + 0x4fe8) = *(ushort *)(glContext + 0x4fe8) | 0x10;
      fVar1 = *(float *)(glContextPtr4854 + -0x1a4);
    }
    else {
      fVar1 = *(float *)(glContextPtr4854 + -0x1d8);
    }
    in_f1 = (double)(**(double ( **)(int,double))(glContext + 0x4fe4))(glContext, (double)fVar1);
    *(float *)(glContextPtr4854 + -0x1b4) = (float)in_f1;
    uVar3 = *(uint *)(glContext + 0x4980) | 4;
  }
  *(uint *)(glContext + 0x4980) = uVar3;
  *(uint *)(glContext + 0x497c) = *(uint *)(glContext + 0x497c) | 4;
  *(uint *)(glContext + 0x50ac) = *(uint *)(glContext + 0x50ac) | 1;
  return in_f1;
}

/* _gleUpdatePolyMode @ 0x9404 (408 bytes) */
void _gleUpdatePolyMode(glContext)
  int glContext;
{
  char glContextByte34da;
  undefined1 uVar2;
  bool bVar3;
  
  glContextByte34da = *(char *)(glContext + 0x34da);
  *(bool *)(glContext + 0x4fe2) = *(int *)(glContext + 0x34d0) == 0x1b021b02;
  if (*(char *)(glContext + 0x4664) == '\0') {
    bVar3 = false;
    if ((*(short *)(glContext + 0x34d0) != *(short *)(glContext + 0x34d2)) ||
       ((*(char *)(glContext + 0x30aa) != '\0' && (*(char *)(glContext + 0x30ac) != '\0')))) {
      bVar3 = true;
    }
    uVar2 = 0;
    if ((bVar3) || (glContextByte34da != '\0')) {
      uVar2 = 1;
    }
    *(undefined1 *)(glContext + 0x4fe0) = uVar2;
    uVar2 = 0;
    if (!bVar3) {
      if (glContextByte34da == '\0') goto LAB_0000951c;
      if ((*(char *)(glContext + 0x4fe2) != '\0') && (*(char *)(glContext + 0x30aa) == '\0'))
      goto LAB_00009508;
    }
  }
  else {
    bVar3 = false;
    if ((*(short *)(glContext + 0x34d0) != *(short *)(glContext + 0x34d2)) ||
       (*(char *)(glContext + 0x4666) != '\0')) {
      bVar3 = true;
    }
    uVar2 = 0;
    if ((bVar3) || (glContextByte34da != '\0')) {
      uVar2 = 1;
    }
    *(undefined1 *)(glContext + 0x4fe0) = uVar2;
    uVar2 = 0;
    if (!bVar3) {
      if (glContextByte34da == '\0') goto LAB_0000951c;
      if (*(char *)(glContext + 0x4fe2) != '\0') {
LAB_00009508:
        uVar2 = 0;
        if (*(char *)(*(int *)(glContext + 0x468c) + 0x78) != '\0') goto LAB_0000951c;
      }
    }
  }
  uVar2 = 1;
LAB_0000951c:
  *(undefined1 *)(glContext + 0x34de) = uVar2;
  if ((*(int *)(glContext + 0x4e1c) == 0x1c00) &&
     ((**(uint **)(glContext + 0x468c) >> 1 & 1) != (**(uint **)(glContext + 0x468c) & 1))) {
    bVar3 = SUB41(-(uint)(*(ushort *)(glContext + 0x34d4) ^ 0x901) >> 0x1f,0);
  }
  else {
    bVar3 = *(short *)(glContext + 0x34d4) == 0x901;
  }
  *(bool *)(glContext + 0x4fe1) = bVar3;
  uVar2 = 2;
  if (glContextByte34da != '\0') {
    uVar2 = *(short *)(glContext + 0x34d6) == 0x404;
  }
  *(undefined1 *)(glContext + 0x4fe3) = uVar2;
  *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x800000;
  return;
}

/* _gleUpdateEvalData @ 0x959c (168 bytes) */
double _gleUpdateEvalData(glContext)
  int glContext;
{
  double dVar1;
  double dVar2;
  
  dVar2 = (double)CONCAT44(0x43300000,*(uint *)(glContext + 0x74c8) ^ 0x80000000) - DOUBLE_00108d58;
  dVar1 = (double)CONCAT44(0x43300000,*(uint *)(glContext + 0x74b8) ^ 0x80000000) - DOUBLE_00108d58;
  *(float *)(glContext + 0x74b4) =
       (*(float *)(glContext + 0x74b0) - *(float *)(glContext + 0x74ac)) /
       (float)((double)CONCAT44(0x43300000,
                                *(uint *)(0x74a4 + glContext + 4) ^ 0x80000000) -
              DOUBLE_00108d58);
  *(float *)(glContext + 0x74c4) =
       (*(float *)(glContext + 0x74c0) - *(float *)(glContext + 0x74bc)) / (float)dVar1;
  *(float *)(glContext + 0x74d4) =
       (*(float *)(glContext + 0x74d0) - *(float *)(glContext + 0x74cc)) / (float)dVar2;
  return;
}

/* _gleUpdateViewScissorData @ 0x9644 (1892 bytes) */
void _gleUpdateViewScissorData(int glContext,double unusedFloatArg1,double unusedFloatArg2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8)
{
  uint surfaceWidth;
  int surface;
  uint viewportTop;
  uint viewportRight;
  float floatOne;
  double intToDoubleMagic2;
  double intToDoubleMagic;
  float viewportXFloat;
  float surfaceHeightFloat;
  float offsetXFloat;
  float viewportYFloat;
  float clipWidthFloat2;
  float offsetYFloat;
  float viewportHalfWidth;
  float viewportTopFloat;
  float clipHeightFloat2;
  float clipWidthFloat;
  float viewportHalfHeight;
  float clipHeightFloat;
  float surfaceWidthFloat;
  float fVar6;
  float viewportRightFloat;
  float fVar7;
  uint uVar8;
  int glContextWord472c;
  uint scissorMaxYRaw;
  uint clipMinX;
  uint windowMinY;
  uint windowOffsetYThenMaxY;
  uint windowMinX;
  uint uVar14;
  uint glContextWord34e0;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  uint glContextWord34e4;
  uint uVar18;
  int glContextWord4730;
  uint rendererInfoFlags;
  uint viewportWidth;
  uint viewportHeight;
  uint surfaceHeight;
  uint viewportX;
  uint viewportY;
  double dVar26;
  double dVar27;
  double dVar28;
  double dVar29;
  
  intToDoubleMagic = DOUBLE_00108d58;
  surface = *(int *)(glContext + 0x744c);
  viewportX = *(uint *)(glContext + 0x1ba0);
  viewportY = *(uint *)(glContext + 0x1ba4);
  viewportWidth = *(uint *)(glContext + 0x1ba8);
  viewportHeight = *(uint *)(glContext + 0x1bac);
  viewportRight = viewportX + viewportWidth;
  viewportTop = viewportY + viewportHeight;
  if (surface == 0) {
    surfaceWidth = *(uint *)(glContext + 0x471c);
    surfaceHeight = *(uint *)(glContext + 0x4720);
  }
  else {
    surfaceWidth = (uint)*(ushort *)(surface + 0xca);
    surfaceHeight = (uint)*(ushort *)(surface + 0xcc);
  }
  viewportXFloat = (float)((double)CONCAT44(0x43300000,viewportX ^ 0x80000000) - DOUBLE_00108d58);
  viewportHalfWidth = (float)((double)CONCAT44(0x43300000,viewportWidth ^ 0x80000000) - DOUBLE_00108d58) *
          FLOAT_00108e90;
  viewportYFloat = (float)((double)CONCAT44(0x43300000,viewportY ^ 0x80000000) - DOUBLE_00108d58);
  viewportHalfHeight = (float)((double)CONCAT44(0x43300000,viewportHeight ^ 0x80000000) - DOUBLE_00108d58) *
          FLOAT_00108e90;
  *(float *)(glContext + 0x4a2c) = viewportHalfWidth;
  *(float *)(glContext + 0x4a34) = viewportHalfHeight;
  *(float *)(glContext + 0x4a30) = viewportHalfWidth + viewportXFloat;
  *(float *)(glContext + 19000) = viewportHalfHeight + viewportYFloat;
  intToDoubleMagic2 = DOUBLE_00108d58;
  if (*(int *)(glContext + 0x4e1c) == 0x1c00) {
    rendererInfoFlags = **(uint **)(glContext + 0x468c);
    if ((((*(char *)(glContext + 0x4664) == '\0') && (*(int *)(glContext + 0x5434) == 0)) &&
        (*(char *)(glContext + 0x34f0) != '\0')) &&
       (((rendererInfoFlags & 4) != 0 || (*(undefined **)(glContext + 0x507c) == ((unsigned char *)0x00001101))))) {
      glContextWord34e0 = *(uint *)(glContext + 0x34e0);
      glContextWord34e4 = *(uint *)(glContext + 0x34e4);
      uVar8 = *(int *)(glContext + 0x34e8) + glContextWord34e0;
      scissorMaxYRaw = *(int *)(glContext + 0x34ec) + glContextWord34e4;
      uVar15 = 0;
      if ((-1 < (int)glContextWord34e0) && (uVar15 = glContextWord34e0, (int)surfaceWidth < (int)glContextWord34e0)) {
        uVar15 = surfaceWidth;
      }
      uVar18 = 0;
      if ((-1 < (int)glContextWord34e4) && (uVar18 = glContextWord34e4, (int)surfaceHeight < (int)glContextWord34e4)) {
        uVar18 = surfaceHeight;
      }
      uVar14 = uVar15;
      if (((int)uVar15 <= (int)uVar8) && (uVar14 = uVar8, (int)surfaceWidth < (int)uVar8)) {
        uVar14 = surfaceWidth;
      }
      uVar8 = uVar18;
      if (((int)uVar18 <= (int)scissorMaxYRaw) && (uVar8 = scissorMaxYRaw, (int)surfaceHeight < (int)scissorMaxYRaw)) {
        uVar8 = surfaceHeight;
      }
    }
    else {
      uVar15 = 0;
      uVar18 = 0;
      uVar14 = surfaceWidth;
      uVar8 = surfaceHeight;
    }
    clipMinX = viewportX;
    if (((int)viewportX <= (int)uVar15) && (clipMinX = uVar15, (int)viewportRight < (int)uVar15)) {
      clipMinX = viewportRight;
    }
    uVar15 = viewportY;
    if (((int)viewportY <= (int)uVar18) && (uVar15 = uVar18, (int)viewportTop < (int)uVar18)) {
      uVar15 = viewportTop;
    }
    uVar18 = clipMinX;
    if (((int)clipMinX <= (int)uVar14) && (uVar18 = uVar14, (int)viewportRight < (int)uVar14)) {
      uVar18 = viewportRight;
    }
    uVar16 = uVar15;
    if (((int)uVar15 <= (int)uVar8) && (uVar16 = uVar8, (int)viewportTop < (int)uVar8)) {
      uVar16 = viewportTop;
    }
    uVar14 = *(uint *)(glContext + 0x4724);
    windowOffsetYThenMaxY = *(uint *)(glContext + 0x4728);
    uVar17 = uVar18 - clipMinX;
    uVar8 = uVar16 - uVar15;
    glContextWord472c = *(int *)(glContext + 0x472c);
    glContextWord4730 = *(int *)(glContext + 0x4730);
    offsetXFloat = (float)((double)CONCAT44(0x43300000,uVar14 ^ 0x80000000) - DOUBLE_00108d58);
    offsetYFloat = (float)((double)CONCAT44(0x43300000,windowOffsetYThenMaxY ^ 0x80000000) - DOUBLE_00108d58);
    clipWidthFloat = (float)((double)CONCAT44(0x43300000,uVar17 ^ 0x80000000) - DOUBLE_00108d58);
    clipHeightFloat = (float)((double)CONCAT44(0x43300000,uVar8 ^ 0x80000000) - DOUBLE_00108d58);
    fVar6 = FLOAT_00108f8c;
    if ((rendererInfoFlags & 8) != 0) {
      fVar6 = FLOAT_00108e90;
    }
    fVar7 = clipHeightFloat * fVar6;
    fVar6 = clipWidthFloat * fVar6;
    clipWidthFloat = clipWidthFloat * FLOAT_00108e90 +
            (float)((double)CONCAT44(0x43300000,clipMinX ^ 0x80000000) - DOUBLE_00108d58);
    clipHeightFloat = clipHeightFloat * FLOAT_00108e90 +
            (float)((double)CONCAT44(0x43300000,uVar15 ^ 0x80000000) - DOUBLE_00108d58);
    if ((rendererInfoFlags & 1) == 0) {
      windowMinX = clipMinX + uVar14;
      uVar14 = uVar18 + uVar14;
      dVar26 = (double)CONCAT44(0x43300000,windowMinX ^ 0x80000000) - DOUBLE_00108d58;
      *(float *)(glContext + 0x1b70) = fVar6;
      *(float *)(glContext + 0x1b80) = clipWidthFloat + offsetXFloat;
      *(undefined4 *)(glContext + 0x4a44) = 0x3f800000;
      *(float *)(glContext + 0x4a48) = offsetXFloat;
      *(float *)(glContext + 0xf0) = (float)dVar26;
      *(float *)(glContext + 0x100) =
           (float)((double)CONCAT44(0x43300000,uVar14 ^ 0x80000000) - intToDoubleMagic2);
      if (clipMinX == 0) {
        windowMinX = windowMinX - glContextWord472c;
      }
      if (uVar18 == surfaceWidth) {
        uVar14 = uVar14 + glContextWord472c;
      }
    }
    else {
      windowMinX = (surfaceWidth - uVar18) + uVar14;
      uVar14 = (surfaceWidth - clipMinX) + uVar14;
      surfaceWidthFloat = (float)((double)CONCAT44(0x43300000,surfaceWidth ^ 0x80000000) - DOUBLE_00108d58);
      dVar28 = (double)CONCAT44(0x43300000,windowMinX ^ 0x80000000) - DOUBLE_00108d58;
      dVar26 = (double)CONCAT44(0x43300000,uVar14 ^ 0x80000000) - DOUBLE_00108d58;
      *(undefined4 *)(glContext + 0x4a44) = 0xbf800000;
      *(float *)(glContext + 0x1b70) = -fVar6;
      *(float *)(glContext + 0x4a48) = surfaceWidthFloat + offsetXFloat;
      *(float *)(glContext + 0x1b80) = (surfaceWidthFloat - clipWidthFloat) + offsetXFloat;
      *(float *)(glContext + 0xf0) = (float)dVar28;
      *(float *)(glContext + 0x100) = (float)dVar26;
      if (clipMinX == 0) {
        uVar14 = uVar14 + glContextWord472c;
      }
      if (uVar18 == surfaceWidth) {
        windowMinX = windowMinX - glContextWord472c;
      }
    }
    intToDoubleMagic = DOUBLE_00108d58;
    if ((rendererInfoFlags & 2) == 0) {
      windowMinY = uVar15 + windowOffsetYThenMaxY;
      windowOffsetYThenMaxY = uVar16 + windowOffsetYThenMaxY;
      dVar28 = (double)CONCAT44(0x43300000,windowMinY ^ 0x80000000) - DOUBLE_00108d58;
      *(float *)(glContext + 0x1b74) = fVar7;
      *(undefined4 *)(glContext + 0x4a4c) = 0x3f800000;
      *(float *)(glContext + 0x4a50) = offsetYFloat;
      *(float *)(glContext + 0x1b84) = clipHeightFloat + offsetYFloat;
      *(float *)(glContext + 0xf4) = (float)dVar28;
      *(float *)(glContext + 0x104) =
           (float)((double)CONCAT44(0x43300000,windowOffsetYThenMaxY ^ 0x80000000) - intToDoubleMagic);
      if (uVar15 == 0) {
        windowMinY = windowMinY - glContextWord4730;
      }
      if (uVar16 == surfaceHeight) {
        windowOffsetYThenMaxY = windowOffsetYThenMaxY + glContextWord4730;
      }
    }
    else {
      windowMinY = (surfaceHeight - uVar16) + windowOffsetYThenMaxY;
      windowOffsetYThenMaxY = (surfaceHeight - uVar15) + windowOffsetYThenMaxY;
      surfaceHeightFloat = (float)((double)CONCAT44(0x43300000,surfaceHeight ^ 0x80000000) - DOUBLE_00108d58);
      dVar28 = (double)CONCAT44(0x43300000,windowMinY ^ 0x80000000) - DOUBLE_00108d58;
      dVar26 = (double)CONCAT44(0x43300000,windowOffsetYThenMaxY ^ 0x80000000) - DOUBLE_00108d58;
      *(undefined4 *)(glContext + 0x4a4c) = 0xbf800000;
      *(float *)(glContext + 0x4a50) = surfaceHeightFloat + offsetYFloat;
      *(float *)(glContext + 0x1b74) = -fVar7;
      *(float *)(glContext + 0x1b84) = (surfaceHeightFloat - clipHeightFloat) + offsetYFloat;
      *(float *)(glContext + 0xf4) = (float)dVar28;
      *(float *)(glContext + 0x104) = (float)dVar26;
      if (uVar15 == 0) {
        windowOffsetYThenMaxY = windowOffsetYThenMaxY + glContextWord4730;
      }
      if (uVar16 == surfaceHeight) {
        windowMinY = windowMinY - glContextWord4730;
      }
    }
    intToDoubleMagic = DOUBLE_00108d58;
    dVar27 = (double)CONCAT44(0x43300000,uVar14 ^ 0x80000000) - DOUBLE_00108d58;
    dVar29 = (double)CONCAT44(0x43300000,windowMinY ^ 0x80000000) - DOUBLE_00108d58;
    dVar28 = (double)CONCAT44(0x43300000,windowOffsetYThenMaxY ^ 0x80000000) - DOUBLE_00108d58;
    *(float *)(glContext + 0x110) =
         (float)((double)CONCAT44(0x43300000,windowMinX ^ 0x80000000) - DOUBLE_00108d58);
    *(float *)(glContext + 0x118) = (float)dVar27;
    *(float *)(glContext + 0x114) = (float)dVar29;
    *(float *)(glContext + 0x11c) = (float)dVar28;
    floatOne = FLOAT_00108e54;
    if ((uVar17 == 0) || (uVar8 == 0)) {
      *(undefined4 *)(glContext + 0x4a24) = 0x3f800000;
      *(undefined4 *)(glContext + 0x4a28) = 0;
      *(undefined4 *)(glContext + 0x4a1c) = 0x3f800000;
      *(undefined4 *)(glContext + 0x4a20) = 0;
    }
    else {
      clipWidthFloat2 = (float)((double)CONCAT44(0x43300000,uVar17 ^ 0x80000000) - intToDoubleMagic);
      clipHeightFloat2 = (float)((double)CONCAT44(0x43300000,uVar8 ^ 0x80000000) - intToDoubleMagic);
      *(float *)(glContext + 0x4a1c) =
           (float)((double)CONCAT44(0x43300000,viewportWidth ^ 0x80000000) - intToDoubleMagic) / clipWidthFloat2;
      *(float *)(glContext + 0x4a24) =
           (float)((double)CONCAT44(0x43300000,viewportHeight ^ 0x80000000) - intToDoubleMagic) / clipHeightFloat2;
      *(float *)(glContext + 0x4a28) =
           (float)((double)CONCAT44(0x43300000,(viewportY - uVar15) * 2 + viewportHeight ^ 0x80000000) - intToDoubleMagic
                  ) / clipHeightFloat2 - floatOne;
      *(float *)(glContext + 0x4a20) =
           (float)((double)CONCAT44(0x43300000,(viewportX - clipMinX) * 2 + viewportWidth ^ 0x80000000) - intToDoubleMagic
                  ) / clipWidthFloat2 - floatOne;
    }
  }
  else {
    *(float *)(glContext + 0x1b70) = viewportHalfWidth;
    *(float *)(glContext + 0x1b74) = viewportHalfHeight;
    viewportRightFloat = (float)((double)CONCAT44(0x43300000,viewportRight ^ 0x80000000) - intToDoubleMagic);
    *(float *)(glContext + 0x1b80) = viewportHalfWidth + viewportXFloat;
    *(float *)(glContext + 0x1b84) = viewportHalfHeight + viewportYFloat;
    viewportTopFloat = (float)((double)CONCAT44(0x43300000,viewportTop ^ 0x80000000) - intToDoubleMagic);
    *(undefined4 *)(glContext + 0x4a4c) = 0x3f800000;
    *(undefined4 *)(glContext + 0x4a50) = 0;
    *(float *)(glContext + 0xf0) = viewportXFloat;
    *(float *)(glContext + 0x100) = viewportRightFloat;
    *(float *)(glContext + 0xf4) = viewportYFloat;
    *(float *)(glContext + 0x104) = viewportTopFloat;
    *(undefined4 *)(glContext + 0x4a1c) = 0x3f800000;
    *(undefined4 *)(glContext + 0x4a24) = 0x3f800000;
    *(undefined4 *)(glContext + 0x4a20) = 0;
    *(undefined4 *)(glContext + 0x4a28) = 0;
    *(undefined4 *)(glContext + 0x4a44) = 0x3f800000;
    *(undefined4 *)(glContext + 0x4a48) = 0;
    *(float *)(glContext + 0x110) = viewportXFloat;
    *(float *)(glContext + 0x118) = viewportRightFloat;
    *(float *)(glContext + 0x114) = viewportYFloat;
    *(float *)(glContext + 0x11c) = viewportTopFloat;
  }
  *(uint *)(glContext + 0x50ac) = *(uint *)(glContext + 0x50ac) | 1;
  *(uint *)(glContext + 0x318) = *(uint *)(glContext + 0x318) | 1;
  return;
}

/* _gleSelectVertexAddMaterialFunc @ 0x9da8 (32 bytes) */
void _gleSelectVertexAddMaterialFunc(glContext)
  int glContext;
{
  *(undefined **)(glContext + 0x4de4) = PTR__gleSetAddVertexMaterialFunc_00110e34;
  return;
}

/* _gleSelectVertexSubmitFunc @ 0x9dc8 (272 bytes) */
void _gleSelectVertexSubmitFunc(glContext)
  int glContext;
{
  undefined *puVar1;
  undefined *puVar2;
  short sVar4;
  int iVar3;
  int glContextWord5434;
  
  puVar1 = PTR__gleSetVertexEval2Func_00112068;
  *(undefined **)(glContext + 0x4888) = PTR__gleSetVertexSubmitFunc_0011242c;
  puVar2 = PTR__gleSetVertexEval1Func_0011206c;
  *(undefined4 *)(glContext + 0x4890) = 0;
  *(undefined **)(glContext + 0x4898) = puVar2;
  *(undefined **)(glContext + 0x489c) = puVar1;
  if (((*(int *)(glContext + 0x4e1c) == 0x1c00) && (*(char *)(glContext + 0x7580) != '\0')) &&
     (*(int *)(glContext + 0x48d0) != 0)) {
    sVar4 = (ushort)*(byte *)(*(int *)(glContext + 0x48d0) + 2) << 2;
    *(short *)(glContext + 0x4880) = sVar4;
    if (*(int *)(glContext + 0x48d4) != 0) {
      sVar4 = (ushort)*(byte *)(*(int *)(glContext + 0x48d4) + 2) << 2;
    }
    *(short *)(glContext + 0x4882) = sVar4;
    return;
  }
  if (*(char *)(glContext + 0x4664) == '\0') {
    glContextWord5434 = *(int *)(glContext + 0x5434);
    if (glContextWord5434 == 0) {
      *(undefined2 *)(glContext + 0x487c) = 0x100;
      *(undefined4 *)(glContext + 0x485c) = *(undefined4 *)(glContext + 0x4860);
      return;
    }
  }
  else {
    glContextWord5434 = *(int *)(glContext + 0x5434);
  }
  if (glContextWord5434 == 0) {
    iVar3 = *(int *)(*(int *)(glContext + 0x5420) + 0x4cc);
  }
  else {
    iVar3 = *(int *)(*(int *)(*(int *)(glContext + 0x5430) + 0x20) + 0x508);
  }
  if (iVar3 != 0) {
    iVar3 = *(int *)(iVar3 + 0x20) * 0x10;
    *(short *)(glContext + 0x487c) = (short)iVar3;
    *(int *)(glContext + 0x485c) = *(int *)(glContext + 0x4854) + iVar3 * *(int *)(glContext + 0x4878);
    return;
  }
  return;
}

/* _gliSetCurrentPluginDispatchTable @ 0x9ed8 (288 bytes) */
void _gliSetCurrentPluginDispatchTable(glContext)
  int glContext;
{
  undefined *puVar1;
  undefined4 *dstCursor;
  uint uVar3;
  int remaining;
  double forwardedFloatArg1;
  double incomingFpr2;
  double incomingFpr3;
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  
  puVar1 = PTR__gliDispatchNoop_00111e14;
  if (*(char *)(glContext + 0x4692) == '\0') {
    uVar3 = (**(code **)(glContext + 0x4784))
                      (*(undefined4 *)(glContext + 0x4688),glContext + 0x4698,glContext + 0x471c);
    ((void (*)())_gleUpdateViewScissorData)(glContext,forwardedFloatArg1,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8);
    if ((uVar3 & 4) == 0) {
      *(undefined1 *)(glContext + 0x7581) = 4;
    }
    _gleUpdateDispatchCodeChange(glContext,uVar3);
    return;
  }
  remaining = 0x21;
  dstCursor = (undefined4 *)(glContext + 0x4698);
  do {
    *dstCursor = puVar1;
    dstCursor = dstCursor + 1;
    remaining = remaining + -1;
  } while (remaining != 0);
  if ((*(int *)(glContext + 0x48d0) != 0) || (*(int *)(glContext + 0x48d4) != 0)) {
    *(undefined4 *)(glContext + 0x48d0) = 0;
    *(undefined4 *)(glContext + 0x48d4) = 0;
    ((void (*)())_gleUpdatePrimitiveData)(glContext);
    uVar3 = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xc) == 0);
    *(undefined **)
     ((*(uint *)(glContext + 0x4680) & uVar3 | *(uint *)(glContext + 0x4684) & ~uVar3) + 0xc) =
         PTR__glArrayElement_Exec_001120e8;
    _gleUpdateDrawArraysFuncs(glContext);
    ((void (*)())_gleSelectVertexSubmitFunc)(glContext);
    *(undefined4 *)(glContext + 0x488c) = 0;
    *(undefined4 *)(glContext + 0x4890) = 0;
    *(undefined4 *)(glContext + 0x4894) = 0;
  }
  return;
}

/* _gliInitDispatchTable @ 0x9ff8 (8072 bytes) */
void _gliInitDispatchTable(glContext)
  int glContext;
{
  uint emptySlotMask;
  
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 8) == 0);
  *(undefined **)((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 8)
       = PTR__glAreTexturesResident_Exec_00113e08;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xcc) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xcc) =
       PTR__glColorPointer_Exec_00113e04;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xe8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xe8) =
       PTR__glDeleteLists_Exec_00113e00;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xec) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xec) =
       PTR__glDeleteTextures_Exec_00113dfc;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x100) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x100) =
       PTR__glDisableClientState_Exec_00113df8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x118) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x118) =
       PTR__glEdgeFlagPointer_Exec_00113df4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x124) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x124) =
       PTR__glEnableClientState_Exec_00113df0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 300) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 300) =
       PTR__glEndList_Exec_00113dec;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x160) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x160) =
       PTR__glFeedbackBuffer_Exec_00113de8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x164) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x164) =
       PTR__glFinish_Exec_00112114;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x168) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x168) =
       PTR__glFlush_Exec_00112118;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x184) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x184) =
       PTR__glGenLists_Exec_00113de4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x188) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x188) =
       PTR__glGenTextures_Exec_00113de0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x18c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x18c) =
       PTR__glGetBooleanv_Exec_00113ddc;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 400) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 400) =
       PTR__glGetClipPlane_Exec_00113dd8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x194) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x194) =
       PTR__glGetDoublev_Exec_00113dd4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x198) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x198) =
       PTR__glGetError_Exec_00113dd0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x19c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x19c) =
       PTR__glGetFloatv_Exec_00113dcc;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x1a0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x1a0) =
       PTR__glGetIntegerv_Exec_00113dc8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x1a4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x1a4) =
       PTR__glGetLightfv_Exec_00113dc4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x1a8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x1a8) =
       PTR__glGetLightiv_Exec_00113dc0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x1ac) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x1ac) =
       PTR__glGetMapdv_Exec_00113dbc;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x1b0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x1b0) =
       PTR__glGetMapfv_Exec_00113db8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x1b4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x1b4) =
       PTR__glGetMapiv_Exec_00113db4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x1b8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x1b8) =
       PTR__glGetMaterialfv_Exec_00113db0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x1bc) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x1bc) =
       PTR__glGetMaterialiv_Exec_00113dac;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x1c0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x1c0) =
       PTR__glGetPixelMapfv_Exec_00113da8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x1c4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x1c4) =
       PTR__glGetPixelMapuiv_Exec_00113da4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x1c8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x1c8) =
       PTR__glGetPixelMapusv_Exec_00113da0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x1cc) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x1cc) =
       PTR__glGetPointerv_Exec_00113d9c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x1d0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x1d0) =
       PTR__glGetPolygonStipple_Exec_00113d98;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x1d4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x1d4) =
       PTR__glGetString_Exec_00113d94;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x1d8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x1d8) =
       PTR__glGetTexEnvfv_Exec_00113d90;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x1dc) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x1dc) =
       PTR__glGetTexEnviv_Exec_00113d8c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x1e0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x1e0) =
       PTR__glGetTexGendv_Exec_00113d88;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x1e4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x1e4) =
       PTR__glGetTexGenfv_Exec_00113d84;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x1e8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x1e8) =
       PTR__glGetTexGeniv_Exec_00113d80;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x1ec) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x1ec) =
       PTR__glGetTexImage_Exec_00113d7c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x1f0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x1f0) =
       PTR__glGetTexLevelParameterfv_Exec_00113d78;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 500) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 500) =
       PTR__glGetTexLevelParameteriv_Exec_00113d74;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x1f8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x1f8) =
       PTR__glGetTexParameterfv_Exec_00113d70;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x1fc) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x1fc) =
       PTR__glGetTexParameteriv_Exec_00113d6c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x208) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x208) =
       PTR__glIndexPointer_Exec_00113d68;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x238) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x238) =
       PTR__glInterleavedArrays_Exec_00113d64;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x23c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x23c) =
       PTR__glIsEnabled_Exec_00113d60;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x240) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x240) =
       PTR__glIsList_Exec_00113d5c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x244) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x244) =
       PTR__glIsTexture_Exec_00113d58;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x2c4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x2c4) =
       PTR__glNewList_Exec_00113d54;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x2f0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x2f0) =
       PTR__glNormalPointer_Exec_00113d50;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x308) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x308) =
       PTR__glPixelStoref_Exec_00113d4c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x30c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x30c) =
       PTR__glPixelStorei_Exec_00113d48;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x330) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x330) =
       PTR__glPopClientAttrib_Exec_00113d44;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x344) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x344) =
       PTR__glPushClientAttrib_Exec_00113d40;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x3b4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x3b4) =
       PTR__glReadPixels_Exec_00113d3c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x3d8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x3d8) =
       PTR__glRenderMode_Exec_00113d38;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x3f0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x3f0) =
       PTR__glSelectBuffer_Exec_00113d34;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x484) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x484) =
       PTR__glTexCoordPointer_Exec_00113d30;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x538) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x538) =
       PTR__glVertexPointer_Exec_00113d2c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x54c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x54c) =
       PTR__glLockArraysEXT_Exec_00113d28;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x550) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x550) =
       PTR__glUnlockArraysEXT_Exec_00113d24;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x554) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x554) =
       PTR__glClientActiveTexture_Exec_00113d20;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x668) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x668) =
       PTR__glGetColorTable_Exec_00113d1c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x66c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x66c) =
       PTR__glGetColorTableParameterfv_Exec_00113d18;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x670) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x670) =
       PTR__glGetColorTableParameteriv_Exec_00113d14;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x69c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x69c) =
       PTR__glGetConvolutionFilter_Exec_00113d10;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x6a0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x6a0) =
       PTR__glGetConvolutionParameterfv_Exec_00113d0c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x6a4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x6a4) =
       PTR__glGetConvolutionParameteriv_Exec_00113d08;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x6a8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x6a8) =
       PTR__glGetSeparableFilter_Exec_00113d04;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x6b0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x6b0) =
       PTR__glGetHistogram_Exec_00113d00;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x6b4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x6b4) =
       PTR__glGetHistogramParameterfv_Exec_00113cfc;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x6b8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x6b8) =
       PTR__glGetHistogramParameteriv_Exec_00113cf8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x6bc) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x6bc) =
       PTR__glGetMinmax_Exec_00113cf4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x6c0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x6c0) =
       PTR__glGetMinmaxParameterfv_Exec_00113cf0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x6c4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x6c4) =
       PTR__glGetMinmaxParameteriv_Exec_00113cec;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x604) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x604) =
       PTR__glGetCompressedTexImage_Exec_00113ce8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x648) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x648) =
       PTR__glSecondaryColorPointer_Exec_00113ce4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x64c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x64c) =
       PTR__glVertexArrayRangeEXT_Exec_00113ce0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x650) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x650) =
       PTR__glFlushVertexArrayRangeEXT_Exec_00113cdc;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x700) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x700) =
       PTR__glGetCombinerInputParameterfvNV_Exec_00113cd8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x704) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x704) =
       PTR__glGetCombinerInputParameterivNV_Exec_00113cd4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x708) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x708) =
       PTR__glGetCombinerOutputParameterfvNV_Exec_00113cd0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x70c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x70c) =
       PTR__glGetCombinerOutputParameterivNV_Exec_00113ccc;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x710) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x710) =
       PTR__glGetFinalCombinerInputParameterfvNV_Exec_00113cc8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x714) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x714) =
       PTR__glGetFinalCombinerInputParameterivNV_Exec_00113cc4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x71c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x71c) =
       PTR__glGetCombinerStageParameterfvNV_Exec_00113cc0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x760) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x760) =
       PTR__glDeleteProgramsARB_Exec_00113cbc;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x764) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x764) =
       PTR__glGenProgramsARB_Exec_00113cb8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x768) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x768) =
       PTR__glIsProgramARB_Exec_00113cb4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x7fc) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x7fc) =
       PTR__glVertexAttribPointerARB_Exec_00113cb0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x800) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x800) =
       PTR__glEnableVertexAttribArrayARB_Exec_00113cac;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x804) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x804) =
       PTR__glDisableVertexAttribArrayARB_Exec_00113ca8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x808) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x808) =
       PTR__glGetVertexAttribdvARB_Exec_00113ca4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x80c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x80c) =
       PTR__glGetVertexAttribfvARB_Exec_00113ca0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x810) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x810) =
       PTR__glGetVertexAttribivARB_Exec_00113c9c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x814) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x814) =
       PTR__glGetVertexAttribPointervARB_Exec_00113c98;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x838) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x838) =
       PTR__glGetProgramEnvParameterdvARB_Exec_00113c94;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x83c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x83c) =
       PTR__glGetProgramEnvParameterfvARB_Exec_00113c90;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x840) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x840) =
       PTR__glGetProgramLocalParameterdvARB_Exec_00113c8c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x844) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x844) =
       PTR__glGetProgramLocalParameterfvARB_Exec_00113c88;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x84c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x84c) =
       PTR__glGetProgramStringARB_Exec_00113c84;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x850) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x850) =
       PTR__glGetProgramivARB_Exec_00113c80;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x85c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x85c) =
       PTR__glIsVertexAttribEnabledARB_Exec_00113c7c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x73c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x73c) =
       PTR__glGenFencesAPPLE_Exec_00113c78;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x740) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x740) =
       PTR__glDeleteFencesAPPLE_Exec_00113c74;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x748) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x748) =
       PTR__glIsFenceAPPLE_Exec_00113c70;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x74c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x74c) =
       PTR__glTestFenceAPPLE_Exec_00113c6c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x754) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x754) =
       PTR__glTestObjectAPPLE_Exec_00113c68;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x890) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x890) =
       PTR__glFogCoordPointer_Exec_00113c64;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x720) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x720) =
       PTR__glTextureRangeAPPLE_Exec_00113c60;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x724) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x724) =
       PTR__glGetTexParameterPointervAPPLE_Exec_00113c5c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x89c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x89c) =
       PTR__glDeleteVertexArraysEXT_Exec_00113c58;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x8a0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x8a0) =
       PTR__glGenVertexArraysEXT_Exec_00113c54;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x8a4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x8a4) =
       PTR__glIsVertexArrayEXT_Exec_00113c50;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x8a8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x8a8) =
       PTR__glElementPointerAPPLE_Exec_00113c4c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x8d4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x8d4) =
       PTR__glWeightPointerARB_Exec_00113c48;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x930) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x930) =
       PTR__glFlushRender_Exec_00113c44;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x934) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x934) =
       PTR__glFinishRender_Exec_00113c40;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x938) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x938) =
       PTR__glSwap_Exec_0011211c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x93c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x93c) =
       PTR__glDeleteObjectARB_Exec_00113c3c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x940) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x940) =
       PTR__glGetHandleARB_Exec_00113c38;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x944) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x944) =
       PTR__glDetachObjectARB_Exec_00113c34;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x948) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x948) =
       PTR__glCreateShaderObjectARB_Exec_00113c30;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x94c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x94c) =
       PTR__glShaderSourceARB_Exec_00113c2c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x950) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x950) =
       PTR__glCompileShaderARB_Exec_00113c28;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x954) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x954) =
       PTR__glCreateProgramObjectARB_Exec_00113c24;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x958) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x958) =
       PTR__glAttachObjectARB_Exec_00113c20;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x95c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x95c) =
       PTR__glLinkProgramARB_Exec_00113c1c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x964) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x964) =
       PTR__glValidateProgramARB_Exec_00113c18;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x9b4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x9b4) =
       PTR__glGetObjectParameterfvARB_Exec_00113c14;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x9b8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x9b8) =
       PTR__glGetObjectParameterivARB_Exec_00113c10;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x9bc) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x9bc) =
       PTR__glGetInfoLogARB_Exec_00113c0c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x9c0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x9c0) =
       PTR__glGetAttachedObjectsARB_Exec_00113c08;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x9c4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x9c4) =
       PTR__glGetUniformLocationARB_Exec_00113c04;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x9c8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x9c8) =
       PTR__glGetActiveUniformARB_Exec_00113c00;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x9cc) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x9cc) =
       PTR__glGetUniformfvARB_Exec_00113bfc;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x9d0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x9d0) =
       PTR__glGetUniformivARB_Exec_00113bf8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x9d4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x9d4) =
       PTR__glGetShaderSourceARB_Exec_00113bf4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x9d8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x9d8) =
       PTR__glBindAttribLocationARB_Exec_00113bf0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x9dc) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x9dc) =
       PTR__glGetActiveAttribARB_Exec_00113bec;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x9e0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x9e0) =
       PTR__glGetAttribLocationARB_Exec_00113be8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x9e8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x9e8) =
       PTR__glGenQueries_Exec_00113be4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x9ec) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x9ec) =
       PTR__glDeleteQueries_Exec_00113be0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x9f0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x9f0) =
       PTR__glIsQuery_Exec_00113bdc;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x9fc) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x9fc) =
       PTR__glGetQueryiv_Exec_00113bd8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xa00) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xa00) =
       PTR__glGetQueryObjectiv_Exec_00113bd4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xa04) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xa04) =
       PTR__glGetQueryObjectuiv_Exec_00113bd0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xa08) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xa08) =
       PTR__glBindBuffer_Exec_00113bcc;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xa0c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xa0c) =
       PTR__glDeleteBuffers_Exec_00113bc8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xa10) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xa10) =
       PTR__glGenBuffers_Exec_00113bc4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xa14) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xa14) =
       PTR__glIsBuffer_Exec_00113bc0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xa18) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xa18) =
       PTR__glBufferData_Exec_00113bbc;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xa1c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xa1c) =
       PTR__glBufferSubData_Exec_00113bb8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xa20) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xa20) =
       PTR__glGetBufferSubData_Exec_00113bb4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xa24) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xa24) =
       PTR__glMapBuffer_Exec_00113bb0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xa28) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xa28) =
       PTR__glUnmapBuffer_Exec_00113bac;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xa2c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xa2c) =
       PTR__glGetBufferParameteriv_Exec_00113ba8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xa30) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xa30) =
       PTR__glGetBufferPointerv_Exec_00113ba4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xa38) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xa38) =
       PTR__glDrawBuffersARB_Exec_00113ba0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xa3c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xa3c) =
       PTR__glIsShader_Exec_00113b9c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xa40) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xa40) =
       PTR__glIsProgram_Exec_00113b98;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xa44) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xa44) =
       PTR__glGetShaderiv_Exec_00113b94;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xa48) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xa48) =
       PTR__glGetProgramiv_Exec_00113b90;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xa4c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xa4c) =
       PTR__glGetShaderInfoLog_Exec_00113b8c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xa50) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xa50) =
       PTR__glGetProgramInfoLog_Exec_00113b88;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xa54) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xa54) =
       PTR__glStencilFuncSeparate_Exec_00113b84;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xa58) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xa58) =
       PTR__glStencilMaskSeparate_Exec_00113b80;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xa64) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xa64) =
       PTR__glIsRenderbufferEXT_Exec_00113b7c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xa68) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xa68) =
       PTR__glBindRenderbufferEXT_Exec_00113b78;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xa6c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xa6c) =
       PTR__glDeleteRenderbuffersEXT_Exec_00113b74;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xa70) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xa70) =
       PTR__glGenRenderbuffersEXT_Exec_00113b70;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xa74) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xa74) =
       PTR__glRenderbufferStorageEXT_Exec_00113b6c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xa78) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xa78) =
       PTR__glGetRenderbufferParameterivEXT_Exec_00113b68;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xa7c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xa7c) =
       PTR__glIsFramebufferEXT_Exec_00113b64;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xa80) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xa80) =
       PTR__glBindFramebufferEXT_Exec_00113b60;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xa84) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xa84) =
       PTR__glDeleteFramebuffersEXT_Exec_00113b5c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xa88) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xa88) =
       PTR__glGenFramebuffersEXT_Exec_00113b58;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xa8c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xa8c) =
       PTR__glCheckFramebufferStatusEXT_Exec_00113b54;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xa90) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xa90) =
       PTR__glFramebufferTexture1DEXT_Exec_00113b50;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xa94) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xa94) =
       PTR__glFramebufferTexture2DEXT_Exec_00113b4c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xa98) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xa98) =
       PTR__glFramebufferTexture3DEXT_Exec_00113b48;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xa9c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xa9c) =
       PTR__glFramebufferRenderbufferEXT_Exec_00113b44;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xaa0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xaa0) =
       PTR__glGetFramebufferAttachmentParameterivEXT_Exec_00113b40;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xaa4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xaa4) =
       PTR__glGenerateMipmapEXT_Exec_00113b3c;
  return;
}

/* _gliExecDispatchTable @ 0xbf80 (23616 bytes) */
void _gliExecDispatchTable(glContext)
  int glContext;
{
  uint table4680;
  uint selectedDispatchTable;
  int slotValue;
  undefined *slotHandler;
  uint emptySlotMask;
  uint table4684;
  
  emptySlotMask = -(uint)(**(int **)(glContext + 0x4684) == 0);
  *(undefined **)(*(uint *)(glContext + 0x4680) & emptySlotMask | (uint)*(int **)(glContext + 0x4684) & ~emptySlotMask)
       = PTR__glAccum_Exec_00113b38;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 4) == 0);
  *(undefined **)((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 4)
       = PTR__glAlphaFunc_Exec_00113b34;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xc) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xc) =
       PTR__glArrayElement_Exec_001120e8;
  if ((*(char *)(glContext + 0x759c) == '\0') || (*(char *)(glContext + 0x759d) == '\0')) {
    emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x10) == 0);
    selectedDispatchTable = *(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask;
    slotHandler = PTR__glBegin_NoopExec_00112078;
  }
  else {
    emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x10) == 0);
    selectedDispatchTable = *(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask;
    slotHandler = PTR__glBegin_Exec_00112074;
  }
  *(undefined **)(selectedDispatchTable + 0x10) = slotHandler;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x14) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x14) =
       PTR__glBindTexture_Exec_00113b30;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x18) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x18) =
       PTR__glBitmap_Exec_0011207c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x1c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x1c) =
       PTR__glBlendFunc_Exec_00113b2c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x20) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x20) =
       PTR__glCallList_Exec_00113b28;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x24) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x24) =
       PTR__glCallLists_Exec_00113b24;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x28) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x28) =
       PTR__glClear_Exec_0011209c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x2c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x2c) =
       PTR__glClearAccum_Exec_00113b20;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x30) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x30) =
       PTR__glClearColor_Exec_00113b1c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x34) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x34) =
       PTR__glClearDepth_Exec_00113b18;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x38) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x38) =
       PTR__glClearIndex_Exec_00113b14;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x3c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x3c) =
       PTR__glClearStencil_Exec_00113b10;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x40) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x40) =
       PTR__glClipPlane_Exec_00113b0c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x44) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x44) =
       PTR__glColor3b_Exec_00113b08;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x48) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x48) =
       PTR__glColor3bv_Exec_00113b04;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x4c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x4c) =
       PTR__glColor3d_Exec_00113b00;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x50) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x50) =
       PTR__glColor3dv_Exec_00113afc;
  if (*(char *)(glContext + 0x4df8) == '\0') {
    emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x54) == 0);
    *(undefined **)
     ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x54) =
         PTR__glColor3f_NoColorMat_Exec_00112178;
    emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x58) == 0);
    *(undefined **)
     ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x58) =
         PTR__glColor3fv_NoColorMat_Exec_00112174;
    emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x94) == 0);
    *(undefined **)
     ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x94) =
         PTR__glColor4f_NoColorMat_Exec_00112170;
    table4684 = *(uint *)(glContext + 0x4684);
    table4680 = *(uint *)(glContext + 0x4680);
    slotValue = *(int *)(table4684 + 0x98);
    slotHandler = PTR__glColor4fv_NoColorMat_Exec_0011216c;
  }
  else {
    emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x54) == 0);
    *(undefined **)
     ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x54) =
         PTR__glColor3f_ColorMat_Exec_00112188;
    emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x58) == 0);
    *(undefined **)
     ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x58) =
         PTR__glColor3fv_ColorMat_Exec_00112184;
    emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x94) == 0);
    *(undefined **)
     ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x94) =
         PTR__glColor4f_ColorMat_Exec_00112180;
    table4684 = *(uint *)(glContext + 0x4684);
    table4680 = *(uint *)(glContext + 0x4680);
    slotValue = *(int *)(table4684 + 0x98);
    slotHandler = PTR__glColor4fv_ColorMat_Exec_0011217c;
  }
  *(undefined **)((table4680 & -(uint)(slotValue == 0) | table4684 & ~-(uint)(slotValue == 0)) + 0x98) = slotHandler;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x5c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x5c) =
       PTR__glColor3i_Exec_00113af8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x60) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x60) =
       PTR__glColor3iv_Exec_00113af4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 100) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 100) =
       PTR__glColor3s_Exec_00113af0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x68) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x68) =
       PTR__glColor3sv_Exec_00113aec;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x6c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x6c) =
       PTR__glColor3ub_Exec_00113ae8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x70) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x70) =
       PTR__glColor3ubv_Exec_00113ae4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x74) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x74) =
       PTR__glColor3ui_Exec_00113ae0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x78) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x78) =
       PTR__glColor3uiv_Exec_00113adc;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x7c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x7c) =
       PTR__glColor3us_Exec_00113ad8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x80) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x80) =
       PTR__glColor3usv_Exec_00113ad4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x84) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x84) =
       PTR__glColor4b_Exec_00113ad0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x88) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x88) =
       PTR__glColor4bv_Exec_00113acc;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x8c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x8c) =
       PTR__glColor4d_Exec_00113ac8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x90) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x90) =
       PTR__glColor4dv_Exec_00113ac4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x9c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x9c) =
       PTR__glColor4i_Exec_00113ac0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xa0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xa0) =
       PTR__glColor4iv_Exec_00113abc;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xa4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xa4) =
       PTR__glColor4s_Exec_00113ab8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xa8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xa8) =
       PTR__glColor4sv_Exec_00113ab4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xac) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xac) =
       PTR__glColor4ub_Exec_00113ab0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xb0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xb0) =
       PTR__glColor4ubv_Exec_00113aac;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xb4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xb4) =
       PTR__glColor4ui_Exec_00113aa8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xb8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xb8) =
       PTR__glColor4uiv_Exec_00113aa4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xbc) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xbc) =
       PTR__glColor4us_Exec_00113aa0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xc0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xc0) =
       PTR__glColor4usv_Exec_00113a9c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xc4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xc4) =
       PTR__glColorMask_Exec_00113a98;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 200) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 200) =
       PTR__glColorMaterial_Exec_00113a94;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xd0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xd0) =
       PTR__glCopyPixels_Exec_00112098;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xd4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xd4) =
       PTR__glCopyTexImage1D_Exec_00112094;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xd8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xd8) =
       PTR__glCopyTexImage2D_Exec_00112090;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xdc) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xdc) =
       PTR__glCopyTexSubImage1D_Exec_0011208c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xe0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xe0) =
       PTR__glCopyTexSubImage2D_Exec_00112088;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xe4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xe4) =
       PTR__glCullFace_Exec_00113a90;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xf0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xf0) =
       PTR__glDepthFunc_Exec_00113a8c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xf4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xf4) =
       PTR__glDepthMask_Exec_00113a88;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xf8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xf8) =
       PTR__glDepthRange_Exec_00113a84;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xfc) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xfc) =
       PTR__glDisable_Exec_00113a80;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x104) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x104) =
       PTR__glDrawArrays_Exec_001120e4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x108) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x108) =
       PTR__glDrawBuffer_Exec_00113a7c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x10c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x10c) =
       PTR__glDrawElements_Exec_001120e0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x110) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x110) =
       PTR__glDrawPixels_Exec_00112080;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x114) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x114) =
       PTR__glEdgeFlag_Exec_00113a78;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x11c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x11c) =
       PTR__glEdgeFlagv_Exec_00113a74;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x120) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x120) =
       PTR__glEnable_Exec_00113a70;
  if ((*(char *)(glContext + 0x7580) != '\0') && (*(int *)(glContext + 0x4e1c) == 0x1c00)) {
    if ((*(int *)(glContext + 0x468c) == 0) || (*(char *)(*(int *)(glContext + 0x468c) + 0x7a) == '\0'))
    {
      emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x128) == 0);
      selectedDispatchTable = *(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask;
      slotHandler = PTR__glEndRDirty_Exec_00112160;
      goto LAB_0000ccc0;
    }
    if (*(char *)(glContext + 0x4df8) == '\0') {
      emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x128) == 0);
      selectedDispatchTable = *(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask;
      slotHandler = PTR__glEndNoMat_Exec_00112168;
      goto LAB_0000ccc0;
    }
  }
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x128) == 0);
  selectedDispatchTable = *(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask;
  slotHandler = PTR__glEnd_Exec_00112164;
LAB_0000ccc0:
  *(undefined **)(selectedDispatchTable + 0x128) = slotHandler;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x130) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x130) =
       PTR__glEvalCoord1d_Exec_00113a6c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x134) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x134) =
       PTR__glEvalCoord1dv_Exec_00113a68;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x138) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x138) =
       PTR__glEvalCoord1f_Exec_00113a64;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x13c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x13c) =
       PTR__glEvalCoord1fv_Exec_00113a60;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x140) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x140) =
       PTR__glEvalCoord2d_Exec_00113a5c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x144) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x144) =
       PTR__glEvalCoord2dv_Exec_00113a58;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x148) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x148) =
       PTR__glEvalCoord2f_Exec_00113a54;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x14c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x14c) =
       PTR__glEvalCoord2fv_Exec_00113a50;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x150) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x150) =
       PTR__glEvalMesh1_Exec_00113a4c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x154) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x154) =
       PTR__glEvalMesh2_Exec_00113a48;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x158) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x158) =
       PTR__glEvalPoint1_Exec_00113a44;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x15c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x15c) =
       PTR__glEvalPoint2_Exec_00113a40;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x16c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x16c) =
       PTR__glFogf_Exec_00113a3c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x170) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x170) =
       PTR__glFogfv_Exec_00113a38;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x174) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x174) =
       PTR__glFogi_Exec_00113a34;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x178) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x178) =
       PTR__glFogiv_Exec_00113a30;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x17c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x17c) =
       PTR__glFrontFace_Exec_00113a2c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x180) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x180) =
       PTR__glFrustum_Exec_00113a28;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x200) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x200) =
       PTR__glHint_Exec_00113a24;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x204) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x204) =
       PTR__glIndexMask_Exec_00113a20;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x20c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x20c) =
       PTR__glIndexd_Exec_00113a1c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x210) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x210) =
       PTR__glIndexdv_Exec_00113a18;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x214) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x214) =
       PTR__glIndexf_Exec_00113a14;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x218) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x218) =
       PTR__glIndexfv_Exec_00113a10;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x21c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x21c) =
       PTR__glIndexi_Exec_00113a0c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x220) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x220) =
       PTR__glIndexiv_Exec_00113a08;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x224) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x224) =
       PTR__glIndexs_Exec_00113a04;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x228) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x228) =
       PTR__glIndexsv_Exec_00113a00;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x22c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x22c) =
       PTR__glIndexub_Exec_001139fc;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x230) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x230) =
       PTR__glIndexubv_Exec_001139f8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x234) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x234) =
       PTR__glInitNames_Exec_001139f4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x248) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x248) =
       PTR__glLightModelf_Exec_001139f0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x24c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x24c) =
       PTR__glLightModelfv_Exec_001139ec;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x250) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x250) =
       PTR__glLightModeli_Exec_001139e8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x254) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x254) =
       PTR__glLightModeliv_Exec_001139e4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 600) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 600) =
       PTR__glLightf_Exec_001139e0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x25c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x25c) =
       PTR__glLightfv_Exec_001139dc;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x260) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x260) =
       PTR__glLighti_Exec_001139d8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x264) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x264) =
       PTR__glLightiv_Exec_001139d4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x268) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x268) =
       PTR__glLineStipple_Exec_001139d0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x26c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x26c) =
       PTR__glLineWidth_Exec_001139cc;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x270) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x270) =
       PTR__glListBase_Exec_001139c8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x274) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x274) =
       PTR__glLoadIdentity_Exec_001139c4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x278) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x278) =
       PTR__glLoadMatrixd_Exec_001139c0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x27c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x27c) =
       PTR__glLoadMatrixf_Exec_001139bc;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x280) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x280) =
       PTR__glLoadName_Exec_001139b8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x284) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x284) =
       PTR__glLogicOp_Exec_001139b4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x288) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x288) =
       PTR__glMap1d_Exec_001139b0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x28c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x28c) =
       PTR__glMap1f_Exec_001139ac;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x290) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x290) =
       PTR__glMap2d_Exec_001139a8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x294) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x294) =
       PTR__glMap2f_Exec_001139a4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x298) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x298) =
       PTR__glMapGrid1d_Exec_001139a0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x29c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x29c) =
       PTR__glMapGrid1f_Exec_0011399c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x2a0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x2a0) =
       PTR__glMapGrid2d_Exec_00113998;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x2a4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x2a4) =
       PTR__glMapGrid2f_Exec_00113994;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x2a8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x2a8) =
       PTR__glMaterialf_Exec_00113990;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x2ac) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x2ac) =
       PTR__glMaterialfv_Exec_0011398c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x2b0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x2b0) =
       PTR__glMateriali_Exec_00113988;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x2b4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x2b4) =
       PTR__glMaterialiv_Exec_00113984;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x2b8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x2b8) =
       PTR__glMatrixMode_Exec_00113980;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 700) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 700) =
       PTR__glMultMatrixd_Exec_0011397c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x2c0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x2c0) =
       PTR__glMultMatrixf_Exec_00113978;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x2c8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x2c8) =
       PTR__glNormal3b_Exec_00113974;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x2cc) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x2cc) =
       PTR__glNormal3bv_Exec_00113970;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x2d0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x2d0) =
       PTR__glNormal3d_Exec_0011396c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x2d4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x2d4) =
       PTR__glNormal3dv_Exec_00113968;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x2d8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x2d8) =
       PTR__glNormal3f_Exec_00113964;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x2dc) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x2dc) =
       PTR__glNormal3fv_Exec_00113960;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x2e0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x2e0) =
       PTR__glNormal3i_Exec_0011395c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x2e4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x2e4) =
       PTR__glNormal3iv_Exec_00113958;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x2e8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x2e8) =
       PTR__glNormal3s_Exec_00113954;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x2ec) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x2ec) =
       PTR__glNormal3sv_Exec_00113950;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x2f4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x2f4) =
       PTR__glOrtho_Exec_0011394c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x2f8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x2f8) =
       PTR__glPassThrough_Exec_00113948;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x2fc) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x2fc) =
       PTR__glPixelMapfv_Exec_00113944;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x300) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x300) =
       PTR__glPixelMapuiv_Exec_00113940;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x304) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x304) =
       PTR__glPixelMapusv_Exec_0011393c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x310) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x310) =
       PTR__glPixelTransferf_Exec_00113938;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x314) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x314) =
       PTR__glPixelTransferi_Exec_00113934;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x318) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x318) =
       PTR__glPixelZoom_Exec_00113930;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x31c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x31c) =
       PTR__glPointSize_Exec_0011392c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 800) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 800) =
       PTR__glPolygonMode_Exec_00113928;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x324) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x324) =
       PTR__glPolygonOffset_Exec_00113924;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x328) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x328) =
       PTR__glPolygonStipple_Exec_00113920;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x32c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x32c) =
       PTR__glPopAttrib_Exec_0011391c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x334) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x334) =
       PTR__glPopMatrix_Exec_00113918;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x338) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x338) =
       PTR__glPopName_Exec_00113914;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x33c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x33c) =
       PTR__glPrioritizeTextures_Exec_00113910;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x340) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x340) =
       PTR__glPushAttrib_Exec_0011390c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x348) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x348) =
       PTR__glPushMatrix_Exec_00113908;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x34c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x34c) =
       PTR__glPushName_Exec_00113904;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x350) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x350) =
       PTR__glRasterPos2d_Exec_00113900;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x354) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x354) =
       PTR__glRasterPos2dv_Exec_001138fc;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x358) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x358) =
       PTR__glRasterPos2f_Exec_001138f8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x35c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x35c) =
       PTR__glRasterPos2fv_Exec_001138f4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x360) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x360) =
       PTR__glRasterPos2i_Exec_001138f0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x364) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x364) =
       PTR__glRasterPos2iv_Exec_001138ec;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x368) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x368) =
       PTR__glRasterPos2s_Exec_001138e8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x36c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x36c) =
       PTR__glRasterPos2sv_Exec_001138e4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x370) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x370) =
       PTR__glRasterPos3d_Exec_001138e0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x374) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x374) =
       PTR__glRasterPos3dv_Exec_001138dc;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x378) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x378) =
       PTR__glRasterPos3f_Exec_001138d8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x37c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x37c) =
       PTR__glRasterPos3fv_Exec_001138d4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x380) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x380) =
       PTR__glRasterPos3i_Exec_001138d0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 900) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 900) =
       PTR__glRasterPos3iv_Exec_001138cc;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x388) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x388) =
       PTR__glRasterPos3s_Exec_001138c8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x38c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x38c) =
       PTR__glRasterPos3sv_Exec_001138c4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x390) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x390) =
       PTR__glRasterPos4d_Exec_001138c0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x394) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x394) =
       PTR__glRasterPos4dv_Exec_001138bc;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x398) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x398) =
       PTR__glRasterPos4f_Exec_001138b8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x39c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x39c) =
       PTR__glRasterPos4fv_Exec_001138b4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x3a0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x3a0) =
       PTR__glRasterPos4i_Exec_001138b0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x3a4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x3a4) =
       PTR__glRasterPos4iv_Exec_001138ac;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x3a8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x3a8) =
       PTR__glRasterPos4s_Exec_001138a8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x3ac) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x3ac) =
       PTR__glRasterPos4sv_Exec_001138a4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x3b0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x3b0) =
       PTR__glReadBuffer_Exec_001138a0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x3b8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x3b8) =
       PTR__glRectd_Exec_0011389c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x3bc) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x3bc) =
       PTR__glRectdv_Exec_00113898;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x3c0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x3c0) =
       PTR__glRectf_Exec_00113894;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x3c4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x3c4) =
       PTR__glRectfv_Exec_00113890;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x3c8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x3c8) =
       PTR__glRecti_Exec_0011388c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x3cc) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x3cc) =
       PTR__glRectiv_Exec_00113888;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x3d0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x3d0) =
       PTR__glRects_Exec_00113884;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x3d4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x3d4) =
       PTR__glRectsv_Exec_00113880;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x3dc) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x3dc) =
       PTR__glRotated_Exec_0011387c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x3e0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x3e0) =
       PTR__glRotatef_Exec_00113878;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x3e4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x3e4) =
       PTR__glScaled_Exec_00113874;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 1000) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 1000) =
       PTR__glScalef_Exec_00113870;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x3ec) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x3ec) =
       PTR__glScissor_Exec_0011386c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x3f4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x3f4) =
       PTR__glShadeModel_Exec_00113868;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x3f8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x3f8) =
       PTR__glStencilFunc_Exec_00113864;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x3fc) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x3fc) =
       PTR__glStencilMask_Exec_00113860;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x400) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x400) =
       PTR__glStencilOp_Exec_0011385c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x404) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x404) =
       PTR__glTexCoord1d_Exec_00113858;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x408) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x408) =
       PTR__glTexCoord1dv_Exec_00113854;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x40c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x40c) =
       PTR__glTexCoord1f_Exec_00113850;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x410) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x410) =
       PTR__glTexCoord1fv_Exec_0011384c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x414) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x414) =
       PTR__glTexCoord1i_Exec_00113848;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x418) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x418) =
       PTR__glTexCoord1iv_Exec_00113844;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x41c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x41c) =
       PTR__glTexCoord1s_Exec_00113840;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x420) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x420) =
       PTR__glTexCoord1sv_Exec_0011383c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x424) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x424) =
       PTR__glTexCoord2d_Exec_00113838;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x428) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x428) =
       PTR__glTexCoord2dv_Exec_00113834;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x42c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x42c) =
       PTR__glTexCoord2f_Exec_00113830;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x430) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x430) =
       PTR__glTexCoord2fv_Exec_0011382c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x434) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x434) =
       PTR__glTexCoord2i_Exec_00113828;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x438) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x438) =
       PTR__glTexCoord2iv_Exec_00113824;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x43c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x43c) =
       PTR__glTexCoord2s_Exec_00113820;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x440) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x440) =
       PTR__glTexCoord2sv_Exec_0011381c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x444) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x444) =
       PTR__glTexCoord3d_Exec_00113818;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x448) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x448) =
       PTR__glTexCoord3dv_Exec_00113814;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x44c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x44c) =
       PTR__glTexCoord3f_Exec_00113810;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x450) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x450) =
       PTR__glTexCoord3fv_Exec_0011380c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x454) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x454) =
       PTR__glTexCoord3i_Exec_00113808;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x458) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x458) =
       PTR__glTexCoord3iv_Exec_00113804;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x45c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x45c) =
       PTR__glTexCoord3s_Exec_00113800;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x460) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x460) =
       PTR__glTexCoord3sv_Exec_001137fc;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x464) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x464) =
       PTR__glTexCoord4d_Exec_001137f8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x468) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x468) =
       PTR__glTexCoord4dv_Exec_001137f4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x46c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x46c) =
       PTR__glTexCoord4f_Exec_001137f0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x470) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x470) =
       PTR__glTexCoord4fv_Exec_001137ec;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x474) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x474) =
       PTR__glTexCoord4i_Exec_001137e8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x478) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x478) =
       PTR__glTexCoord4iv_Exec_001137e4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x47c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x47c) =
       PTR__glTexCoord4s_Exec_001137e0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x480) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x480) =
       PTR__glTexCoord4sv_Exec_001137dc;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x488) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x488) =
       PTR__glTexEnvf_Exec_001137d8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x48c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x48c) =
       PTR__glTexEnvfv_Exec_001137d4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x490) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x490) =
       PTR__glTexEnvi_Exec_001137d0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x494) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x494) =
       PTR__glTexEnviv_Exec_001137cc;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x498) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x498) =
       PTR__glTexGend_Exec_001137c8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x49c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x49c) =
       PTR__glTexGendv_Exec_001137c4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x4a0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x4a0) =
       PTR__glTexGenf_Exec_001137c0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x4a4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x4a4) =
       PTR__glTexGenfv_Exec_001137bc;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x4a8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x4a8) =
       PTR__glTexGeni_Exec_001137b8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x4ac) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x4ac) =
       PTR__glTexGeniv_Exec_001137b4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x4b0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x4b0) =
       PTR__glTexImage1D_Exec_001137b0;
  if (*(char *)(glContext + 0x7587) == '\0') {
    emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x4b4) == 0);
    selectedDispatchTable = *(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask;
    slotHandler = PTR__glTexImage2D_Exec_001137ac;
  }
  else {
    emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x4b4) == 0);
    selectedDispatchTable = *(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask;
    slotHandler = PTR__glTexImage2D_FlushExec_001137a8;
  }
  *(undefined **)(selectedDispatchTable + 0x4b4) = slotHandler;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x4b8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x4b8) =
       PTR__glTexParameterf_Exec_001137a4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x4bc) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x4bc) =
       PTR__glTexParameterfv_Exec_001137a0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x4c0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x4c0) =
       PTR__glTexParameteri_Exec_0011379c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x4c4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x4c4) =
       PTR__glTexParameteriv_Exec_00113798;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x4c8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x4c8) =
       PTR__glTexSubImage1D_Exec_00113794;
  if (*(char *)(glContext + 0x7586) == '\0') {
    emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x4cc) == 0);
    selectedDispatchTable = *(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask;
    slotHandler = PTR__glTexSubImage2D_Exec_00113790;
  }
  else {
    emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x4cc) == 0);
    selectedDispatchTable = *(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask;
    slotHandler = PTR__glTexSubImage2D_FlushExec_0011378c;
  }
  *(undefined **)(selectedDispatchTable + 0x4cc) = slotHandler;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x4d0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x4d0) =
       PTR__glTranslated_Exec_00113788;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x4d4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x4d4) =
       PTR__glTranslatef_Exec_00113784;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x4d8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x4d8) =
       PTR__glVertex2d_Exec_00113780;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x4dc) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x4dc) =
       PTR__glVertex2dv_Exec_0011377c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x4e0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x4e0) =
       PTR__glVertex2f_Exec_00113778;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x4e4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x4e4) =
       PTR__glVertex2fv_Exec_00113774;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x4e8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x4e8) =
       PTR__glVertex2i_Exec_00113770;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x4ec) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x4ec) =
       PTR__glVertex2iv_Exec_0011376c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x4f0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x4f0) =
       PTR__glVertex2s_Exec_00113768;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x4f4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x4f4) =
       PTR__glVertex2sv_Exec_00113764;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x4f8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x4f8) =
       PTR__glVertex3d_Exec_00113760;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x4fc) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x4fc) =
       PTR__glVertex3dv_Exec_0011375c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x500) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x500) =
       PTR__glVertex3f_Exec_00113758;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x504) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x504) =
       PTR__glVertex3fv_Exec_00113754;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x508) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x508) =
       PTR__glVertex3i_Exec_00113750;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x50c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x50c) =
       PTR__glVertex3iv_Exec_0011374c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x510) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x510) =
       PTR__glVertex3s_Exec_00113748;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x514) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x514) =
       PTR__glVertex3sv_Exec_00113744;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x518) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x518) =
       PTR__glVertex4d_Exec_00113740;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x51c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x51c) =
       PTR__glVertex4dv_Exec_0011373c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x520) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x520) =
       PTR__glVertex4f_Exec_00113738;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x524) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x524) =
       PTR__glVertex4fv_Exec_00113734;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x528) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x528) =
       PTR__glVertex4i_Exec_00113730;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x52c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x52c) =
       PTR__glVertex4iv_Exec_0011372c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x530) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x530) =
       PTR__glVertex4s_Exec_00113728;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x534) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x534) =
       PTR__glVertex4sv_Exec_00113724;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x53c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x53c) =
       PTR__glViewport_Exec_00113720;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x544) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x544) =
       PTR__glBlendColor_Exec_0011371c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x548) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x548) =
       PTR__glBlendEquation_Exec_00113718;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x558) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x558) =
       PTR__glActiveTexture_Exec_00113714;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x55c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x55c) =
       PTR__glMultiTexCoord1d_Exec_00113710;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x560) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x560) =
       PTR__glMultiTexCoord1dv_Exec_0011370c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x564) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x564) =
       PTR__glMultiTexCoord1f_Exec_00113708;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x568) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x568) =
       PTR__glMultiTexCoord1fv_Exec_00113704;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x56c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x56c) =
       PTR__glMultiTexCoord1i_Exec_00113700;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x570) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x570) =
       PTR__glMultiTexCoord1iv_Exec_001136fc;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x574) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x574) =
       PTR__glMultiTexCoord1s_Exec_001136f8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x578) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x578) =
       PTR__glMultiTexCoord1sv_Exec_001136f4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x57c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x57c) =
       PTR__glMultiTexCoord2d_Exec_001136f0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x580) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x580) =
       PTR__glMultiTexCoord2dv_Exec_001136ec;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x584) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x584) =
       PTR__glMultiTexCoord2f_Exec_001136e8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x588) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x588) =
       PTR__glMultiTexCoord2fv_Exec_001136e4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x58c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x58c) =
       PTR__glMultiTexCoord2i_Exec_001136e0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x590) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x590) =
       PTR__glMultiTexCoord2iv_Exec_001136dc;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x594) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x594) =
       PTR__glMultiTexCoord2s_Exec_001136d8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x598) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x598) =
       PTR__glMultiTexCoord2sv_Exec_001136d4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x59c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x59c) =
       PTR__glMultiTexCoord3d_Exec_001136d0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x5a0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x5a0) =
       PTR__glMultiTexCoord3dv_Exec_001136cc;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x5a4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x5a4) =
       PTR__glMultiTexCoord3f_Exec_001136c8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x5a8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x5a8) =
       PTR__glMultiTexCoord3fv_Exec_001136c4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x5ac) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x5ac) =
       PTR__glMultiTexCoord3i_Exec_001136c0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x5b0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x5b0) =
       PTR__glMultiTexCoord3iv_Exec_001136bc;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x5b4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x5b4) =
       PTR__glMultiTexCoord3s_Exec_001136b8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x5b8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x5b8) =
       PTR__glMultiTexCoord3sv_Exec_001136b4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x5bc) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x5bc) =
       PTR__glMultiTexCoord4d_Exec_001136b0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x5c0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x5c0) =
       PTR__glMultiTexCoord4dv_Exec_001136ac;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x5c4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x5c4) =
       PTR__glMultiTexCoord4f_Exec_001136a8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x5c8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x5c8) =
       PTR__glMultiTexCoord4fv_Exec_001136a4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x5cc) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x5cc) =
       PTR__glMultiTexCoord4i_Exec_001136a0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x5d0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x5d0) =
       PTR__glMultiTexCoord4iv_Exec_0011369c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x5d4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x5d4) =
       PTR__glMultiTexCoord4s_Exec_00113698;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x5d8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x5d8) =
       PTR__glMultiTexCoord4sv_Exec_00113694;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x5dc) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x5dc) =
       PTR__glLoadTransposeMatrixd_Exec_00113690;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x5e0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x5e0) =
       PTR__glLoadTransposeMatrixf_Exec_0011368c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x5e4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x5e4) =
       PTR__glMultTransposeMatrixd_Exec_00113688;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x5e8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x5e8) =
       PTR__glMultTransposeMatrixf_Exec_00113684;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x654) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x654) =
       PTR__glDrawRangeElements_Exec_001120dc;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x6d8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x6d8) =
       PTR__glTexImage3D_Exec_00113680;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x6dc) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x6dc) =
       PTR__glTexSubImage3D_Exec_0011367c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x6e0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x6e0) =
       PTR__glCopyTexSubImage3D_Exec_00112084;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x658) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x658) =
       PTR__glColorTable_Exec_00113678;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x65c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x65c) =
       PTR__glColorTableParameterfv_Exec_00113674;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x660) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x660) =
       PTR__glColorTableParameteriv_Exec_00113670;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x664) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x664) =
       PTR__glCopyColorTable_Exec_0011366c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x674) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x674) =
       PTR__glColorSubTable_Exec_00113668;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x678) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x678) =
       PTR__glCopyColorSubTable_Exec_00113664;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x67c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x67c) =
       PTR__glConvolutionFilter1D_Exec_00113660;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x680) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x680) =
       PTR__glConvolutionFilter2D_Exec_0011365c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x684) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x684) =
       PTR__glConvolutionParameterf_Exec_00113658;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x688) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x688) =
       PTR__glConvolutionParameterfv_Exec_00113654;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x68c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x68c) =
       PTR__glConvolutionParameteri_Exec_00113650;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x690) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x690) =
       PTR__glConvolutionParameteriv_Exec_0011364c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x694) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x694) =
       PTR__glCopyConvolutionFilter1D_Exec_00113648;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x698) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x698) =
       PTR__glCopyConvolutionFilter2D_Exec_00113644;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x6ac) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x6ac) =
       PTR__glSeparableFilter2D_Exec_00113640;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x6c8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x6c8) =
       PTR__glHistogram_Exec_0011363c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x6cc) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x6cc) =
       PTR__glMinmax_Exec_00113638;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x6d0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x6d0) =
       PTR__glResetHistogram_Exec_00113634;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x6d4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x6d4) =
       PTR__glResetMinmax_Exec_00113630;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x5ec) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x5ec) =
       PTR__glCompressedTexImage3D_Exec_0011362c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x5f0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x5f0) =
       PTR__glCompressedTexImage2D_Exec_00113628;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x5f4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x5f4) =
       PTR__glCompressedTexImage1D_Exec_00113624;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x5f8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x5f8) =
       PTR__glCompressedTexSubImage3D_Exec_00113620;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x5fc) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x5fc) =
       PTR__glCompressedTexSubImage2D_Exec_0011361c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x600) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x600) =
       PTR__glCompressedTexSubImage1D_Exec_00113618;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x608) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x608) =
       PTR__glSecondaryColor3b_Exec_00113614;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x60c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x60c) =
       PTR__glSecondaryColor3bv_Exec_00113610;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x610) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x610) =
       PTR__glSecondaryColor3d_Exec_0011360c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x614) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x614) =
       PTR__glSecondaryColor3dv_Exec_00113608;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x618) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x618) =
       PTR__glSecondaryColor3f_Exec_00113604;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x61c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x61c) =
       PTR__glSecondaryColor3fv_Exec_00113600;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x620) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x620) =
       PTR__glSecondaryColor3i_Exec_001135fc;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x624) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x624) =
       PTR__glSecondaryColor3iv_Exec_001135f8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x628) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x628) =
       PTR__glSecondaryColor3s_Exec_001135f4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x62c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x62c) =
       PTR__glSecondaryColor3sv_Exec_001135f0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x630) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x630) =
       PTR__glSecondaryColor3ub_Exec_001135ec;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x634) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x634) =
       PTR__glSecondaryColor3ubv_Exec_001135e8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x638) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x638) =
       PTR__glSecondaryColor3ui_Exec_001135e4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x63c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x63c) =
       PTR__glSecondaryColor3uiv_Exec_001135e0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x640) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x640) =
       PTR__glSecondaryColor3us_Exec_001135dc;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x644) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x644) =
       PTR__glSecondaryColor3usv_Exec_001135d8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x72c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x72c) =
       PTR__glSampleCoverage_Exec_001135d4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x730) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x730) =
       PTR__glSamplePass_Exec_001135d0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x8e4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x8e4) =
       PTR__glWindowPos2d_Exec_001135cc;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x8e8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x8e8) =
       PTR__glWindowPos2dv_Exec_001135c8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x8ec) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x8ec) =
       PTR__glWindowPos2f_Exec_001135c4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x8f0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x8f0) =
       PTR__glWindowPos2fv_Exec_001135c0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x8f4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x8f4) =
       PTR__glWindowPos2i_Exec_001135bc;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x8f8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x8f8) =
       PTR__glWindowPos2iv_Exec_001135b8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x8fc) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x8fc) =
       PTR__glWindowPos2s_Exec_001135b4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x900) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x900) =
       PTR__glWindowPos2sv_Exec_001135b0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x904) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x904) =
       PTR__glWindowPos3d_Exec_001135ac;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x908) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x908) =
       PTR__glWindowPos3dv_Exec_001135a8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x90c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x90c) =
       PTR__glWindowPos3f_Exec_001135a4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x910) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x910) =
       PTR__glWindowPos3fv_Exec_001135a0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x914) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x914) =
       PTR__glWindowPos3i_Exec_0011359c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x918) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x918) =
       PTR__glWindowPos3iv_Exec_00113598;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x91c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x91c) =
       PTR__glWindowPos3s_Exec_00113594;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x920) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x920) =
       PTR__glWindowPos3sv_Exec_00113590;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x894) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x894) =
       PTR__glVertexArrayParameteriEXT_Exec_0011358c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x6e4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x6e4) =
       PTR__glCombinerParameterfvNV_Exec_00113588;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x6e8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x6e8) =
       PTR__glCombinerParameterfNV_Exec_00113584;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x6ec) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x6ec) =
       PTR__glCombinerParameterivNV_Exec_00113580;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x6f0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x6f0) =
       PTR__glCombinerParameteriNV_Exec_0011357c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x6f4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x6f4) =
       PTR__glCombinerInputNV_Exec_00113578;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x6f8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x6f8) =
       PTR__glCombinerOutputNV_Exec_00113574;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x6fc) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x6fc) =
       PTR__glFinalCombinerInputNV_Exec_00113570;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x718) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x718) =
       PTR__glCombinerStageParameterfvNV_Exec_0011356c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x738) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x738) =
       PTR__glPNTrianglesfATIX_Exec_00113568;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x734) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x734) =
       PTR__glPNTrianglesiATIX_Exec_00113564;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x75c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x75c) =
       PTR__glBindProgramARB_Exec_00113560;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x76c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x76c) =
       PTR__glVertexAttrib1sARB_Exec_0011355c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x770) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x770) =
       PTR__glVertexAttrib1fARB_Exec_00113558;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x774) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x774) =
       PTR__glVertexAttrib1dARB_Exec_00113554;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x778) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x778) =
       PTR__glVertexAttrib2sARB_Exec_00113550;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x77c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x77c) =
       PTR__glVertexAttrib2fARB_Exec_0011354c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x780) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x780) =
       PTR__glVertexAttrib2dARB_Exec_00113548;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x784) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x784) =
       PTR__glVertexAttrib3sARB_Exec_00113544;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x788) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x788) =
       PTR__glVertexAttrib3fARB_Exec_00113540;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x78c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x78c) =
       PTR__glVertexAttrib3dARB_Exec_0011353c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x790) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x790) =
       PTR__glVertexAttrib4sARB_Exec_00113538;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x794) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x794) =
       PTR__glVertexAttrib4fARB_Exec_00113534;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x798) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x798) =
       PTR__glVertexAttrib4dARB_Exec_00113530;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x79c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x79c) =
       PTR__glVertexAttrib4NubARB_Exec_0011352c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x7a0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x7a0) =
       PTR__glVertexAttrib1svARB_Exec_00113528;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x7a4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x7a4) =
       PTR__glVertexAttrib1fvARB_Exec_00113524;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x7a8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x7a8) =
       PTR__glVertexAttrib1dvARB_Exec_00113520;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x7ac) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x7ac) =
       PTR__glVertexAttrib2svARB_Exec_0011351c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x7b0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x7b0) =
       PTR__glVertexAttrib2fvARB_Exec_00113518;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x7b4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x7b4) =
       PTR__glVertexAttrib2dvARB_Exec_00113514;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x7b8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x7b8) =
       PTR__glVertexAttrib3svARB_Exec_00113510;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x7bc) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x7bc) =
       PTR__glVertexAttrib3fvARB_Exec_0011350c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x7c0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x7c0) =
       PTR__glVertexAttrib3dvARB_Exec_00113508;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x7c4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x7c4) =
       PTR__glVertexAttrib4bvARB_Exec_00113504;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x7c8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x7c8) =
       PTR__glVertexAttrib4svARB_Exec_00113500;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x7cc) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x7cc) =
       PTR__glVertexAttrib4ivARB_Exec_001134fc;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 2000) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 2000) =
       PTR__glVertexAttrib4ubvARB_Exec_001134f8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x7d4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x7d4) =
       PTR__glVertexAttrib4usvARB_Exec_001134f4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x7d8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x7d8) =
       PTR__glVertexAttrib4uivARB_Exec_001134f0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x7dc) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x7dc) =
       PTR__glVertexAttrib4fvARB_Exec_001134ec;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x7e0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x7e0) =
       PTR__glVertexAttrib4dvARB_Exec_001134e8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x7e4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x7e4) =
       PTR__glVertexAttrib4NbvARB_Exec_001134e4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x7e8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x7e8) =
       PTR__glVertexAttrib4NsvARB_Exec_001134e0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x7ec) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x7ec) =
       PTR__glVertexAttrib4NivARB_Exec_001134dc;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x7f0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x7f0) =
       PTR__glVertexAttrib4NubvARB_Exec_001134d8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x7f4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x7f4) =
       PTR__glVertexAttrib4NusvARB_Exec_001134d4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x7f8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x7f8) =
       PTR__glVertexAttrib4NuivARB_Exec_001134d0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x818) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x818) =
       PTR__glProgramEnvParameter4dARB_Exec_001134cc;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x81c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x81c) =
       PTR__glProgramEnvParameter4dvARB_Exec_001134c8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x820) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x820) =
       PTR__glProgramEnvParameter4fARB_Exec_001134c4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x824) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x824) =
       PTR__glProgramEnvParameter4fvARB_Exec_001134c0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x828) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x828) =
       PTR__glProgramLocalParameter4dARB_Exec_001134bc;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x82c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x82c) =
       PTR__glProgramLocalParameter4dvARB_Exec_001134b8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x830) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x830) =
       PTR__glProgramLocalParameter4fARB_Exec_001134b4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x834) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x834) =
       PTR__glProgramLocalParameter4fvARB_Exec_001134b0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x848) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x848) =
       PTR__glProgramStringARB_Exec_001134ac;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x854) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x854) =
       PTR__glEnableVertexAttribARB_Exec_001134a8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x858) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x858) =
       PTR__glDisableVertexAttribARB_Exec_001134a4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x860) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x860) =
       PTR__glMapVertexAttrib1dARB_Exec_001134a0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x864) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x864) =
       PTR__glMapVertexAttrib1fARB_Exec_0011349c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x868) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x868) =
       PTR__glMapVertexAttrib2dARB_Exec_00113498;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x86c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x86c) =
       PTR__glMapVertexAttrib2fARB_Exec_00113494;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x744) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x744) =
       PTR__glSetFenceAPPLE_Exec_00113490;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x750) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x750) =
       PTR__glFinishFenceAPPLE_Exec_0011348c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x758) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x758) =
       PTR__glFinishObjectAPPLE_Exec_00113488;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x870) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x870) =
       PTR__glPointParameterf_Exec_00113484;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x874) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x874) =
       PTR__glPointParameterfv_Exec_00113480;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x878) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x878) =
       PTR__glPointParameteriARB_Exec_0011347c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x87c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x87c) =
       PTR__glPointParameterivARB_Exec_00113478;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x880) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x880) =
       PTR__glFogCoordf_Exec_00113474;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x884) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x884) =
       PTR__glFogCoordfv_Exec_00113470;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x888) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x888) =
       PTR__glFogCoordd_Exec_0011346c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x88c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x88c) =
       PTR__glFogCoorddv_Exec_00113468;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x898) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x898) =
       PTR__glBindVertexArrayEXT_Exec_00113464;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x8ac) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x8ac) =
       PTR__glDrawElementArrayAPPLE_Exec_001120cc;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x8b0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x8b0) =
       PTR__glDrawRangeElementArrayAPPLE_Exec_001120d0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xa5c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xa5c) =
       PTR__glMultiDrawElementArrayAPPLE_Exec_001120c4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xa60) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xa60) =
       PTR__glMultiDrawRangeElementArrayAPPLE_Exec_001120c8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x540) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x540) =
       PTR__glBlendFuncSeparate_Exec_00113460;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x728) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x728) =
       PTR__glBlendEquationSeparateEXT_Exec_0011345c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x8dc) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x8dc) =
       PTR__glMultiDrawArrays_Exec_001120d8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x8e0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x8e0) =
       PTR__glMultiDrawElements_Exec_001120d4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x8b4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x8b4) =
       PTR__glWeightbvARB_Exec_00113458;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x8b8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x8b8) =
       PTR__glWeightsvARB_Exec_00113454;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x8bc) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x8bc) =
       PTR__glWeightivARB_Exec_00113450;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x8c0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x8c0) =
       PTR__glWeightfvARB_Exec_0011344c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x8c4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x8c4) =
       PTR__glWeightdvARB_Exec_00113448;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x8c8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x8c8) =
       PTR__glWeightubvARB_Exec_00113444;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x8cc) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x8cc) =
       PTR__glWeightusvARB_Exec_00113440;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x8d0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x8d0) =
       PTR__glWeightuivARB_Exec_0011343c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x8d8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x8d8) =
       PTR__glVertexBlendARB_Exec_00113438;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x924) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x924) =
       PTR__glActiveStencilFace_Exec_00113434;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x928) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x928) =
       PTR__glStencilOpSeparateATI_Exec_00113430;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x92c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x92c) =
       PTR__glStencilFuncSeparateATI_Exec_0011342c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x960) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x960) =
       PTR__glUseProgramObjectARB_Exec_00113428;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x968) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x968) =
       PTR__glUniform1fARB_Exec_00113424;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x96c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x96c) =
       PTR__glUniform2fARB_Exec_00113420;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x970) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x970) =
       PTR__glUniform3fARB_Exec_0011341c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x974) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x974) =
       PTR__glUniform4fARB_Exec_00113418;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x978) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x978) =
       PTR__glUniform1iARB_Exec_00113414;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x97c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x97c) =
       PTR__glUniform2iARB_Exec_00113410;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x980) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x980) =
       PTR__glUniform3iARB_Exec_0011340c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x984) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x984) =
       PTR__glUniform4iARB_Exec_00113408;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x988) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x988) =
       PTR__glUniform1fvARB_Exec_00113404;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x98c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x98c) =
       PTR__glUniform2fvARB_Exec_00113400;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x990) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x990) =
       PTR__glUniform3fvARB_Exec_001133fc;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x994) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x994) =
       PTR__glUniform4fvARB_Exec_001133f8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x998) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x998) =
       PTR__glUniform1ivARB_Exec_001133f4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x99c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x99c) =
       PTR__glUniform2ivARB_Exec_001133f0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x9a0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x9a0) =
       PTR__glUniform3ivARB_Exec_001133ec;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x9a4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x9a4) =
       PTR__glUniform4ivARB_Exec_001133e8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x9a8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x9a8) =
       PTR__glUniformMatrix2fvARB_Exec_001133e4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x9ac) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x9ac) =
       PTR__glUniformMatrix3fvARB_Exec_001133e0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x9b0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x9b0) =
       PTR__glUniformMatrix4fvARB_Exec_001133dc;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x9f4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x9f4) =
       PTR__glBeginQuery_Exec_001133d8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x9f8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x9f8) =
       PTR__glEndQuery_Exec_001133d4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xa34) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xa34) =
       PTR__glDepthBoundsEXT_Exec_001133d0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xa38) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xa38) =
       PTR__glDrawBuffersARB_Exec_00113ba0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xa3c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xa3c) =
       PTR__glIsShader_Exec_00113b9c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xa40) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xa40) =
       PTR__glIsProgram_Exec_00113b98;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xa44) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xa44) =
       PTR__glGetShaderiv_Exec_00113b94;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xa48) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xa48) =
       PTR__glGetProgramiv_Exec_00113b90;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xa4c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xa4c) =
       PTR__glGetShaderInfoLog_Exec_00113b8c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xa50) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xa50) =
       PTR__glGetProgramInfoLog_Exec_00113b88;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xa54) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xa54) =
       PTR__glStencilFuncSeparate_Exec_00113b84;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xa58) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xa58) =
       PTR__glStencilMaskSeparate_Exec_00113b80;
  if ((*(char *)(glContext + 0x759c) == '\0') || (*(char *)(glContext + 0x759d) == '\0')) {
    emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x104) == 0);
    *(undefined **)
     ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x104) =
         PTR__glDrawArrays_NoopExec_0011210c;
    emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x10c) == 0);
    *(undefined **)
     ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x10c) =
         PTR__glDrawElements_NoopExec_00112108;
    emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x654) == 0);
    *(undefined **)
     ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x654) =
         PTR__glDrawRangeElements_NoopExec_00112104;
    emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x8dc) == 0);
    *(undefined **)
     ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x8dc) =
         PTR__glMultiDrawArrays_NoopExec_00112100;
    emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x8e0) == 0);
    *(undefined **)
     ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x8e0) =
         PTR__glMultiDrawElements_NoopExec_001120fc;
    emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x8b0) == 0);
    *(undefined **)
     ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x8b0) =
         PTR__glDrawRangeElementArrayAPPLE_NoopExec_001120f8;
    emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x8ac) == 0);
    *(undefined **)
     ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x8ac) =
         PTR__glDrawElementArrayAPPLE_NoopExec_001120f4;
    emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xa60) == 0);
    *(undefined **)
     ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xa60) =
         PTR__glMultiDrawRangeElementArrayAPPLE_NoopExec_001120f0;
    emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xa5c) == 0);
    *(undefined **)
     ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xa5c) =
         PTR__glMultiDrawElementArrayAPPLE_NoopExec_001120ec;
  }
  else {
    emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x104) == 0);
    *(undefined **)
     ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x104) =
         PTR__glDrawArrays_Exec_001120e4;
    emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x10c) == 0);
    *(undefined **)
     ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x10c) =
         PTR__glDrawElements_Exec_001120e0;
    emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x654) == 0);
    *(undefined **)
     ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x654) =
         PTR__glDrawRangeElements_Exec_001120dc;
    emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x8dc) == 0);
    *(undefined **)
     ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x8dc) =
         PTR__glMultiDrawArrays_Exec_001120d8;
    emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x8e0) == 0);
    *(undefined **)
     ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x8e0) =
         PTR__glMultiDrawElements_Exec_001120d4;
    emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x8b0) == 0);
    *(undefined **)
     ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x8b0) =
         PTR__glDrawRangeElementArrayAPPLE_Exec_001120d0;
    emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x8ac) == 0);
    *(undefined **)
     ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x8ac) =
         PTR__glDrawElementArrayAPPLE_Exec_001120cc;
    emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xa60) == 0);
    *(undefined **)
     ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xa60) =
         PTR__glMultiDrawRangeElementArrayAPPLE_Exec_001120c8;
    emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xa5c) == 0);
    *(undefined **)
     ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xa5c) =
         PTR__glMultiDrawElementArrayAPPLE_Exec_001120c4;
  }
  return;
}

/* _glGetString_Exec @ 0x11bc0 (1596 bytes) */
int _glGetString_Exec(glContext, name)
  int glContext;
  uint name;
{
  undefined4 stringLength;
  char *cursor;
  bool bVar1;
  char cVar2;
  undefined4 glErrorCode;
  undefined **cursor2;
  char *pcVar5;
  char *srcCursor;
  char *pcVar6;
  char *dstCursor;
  uint loopIndex;
  
  if (-1 < *(short *)(glContext + 0x4a10)) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return (char *)0x0;
    }
    glErrorCode = 0x502;
    goto LAB_0001231c;
  }
  if (name == 0x1f03) {
    cursor2 = &_engine_extensions;
    dstCursor = (char *)(glContext + 0x759e);
    do {
      cursor = *cursor2;
      cursor2 = cursor2 + 1;
      cVar2 = *cursor;
      while (cVar2 != '\0') {
        *dstCursor = cVar2;
        dstCursor = dstCursor + 1;
        cursor = cursor + 1;
        cVar2 = *cursor;
      }
      *dstCursor = ' ';
      dstCursor = dstCursor + 1;
    } while ((int)cursor2 < 0x110389);
    loopIndex = 0;
    do {
      if ((*(uint *)(((int)loopIndex >> 5) * 4 + *(int *)(glContext + 0x468c) + 0x124) >> (loopIndex & 0x1f) &
          1) != 0) {
        srcCursor = (char *)0x0;
        switch(loopIndex) {
        case 0:
          srcCursor = "GL_ARB_imaging";
          break;
        case 1:
          srcCursor = "GL_ARB_point_parameters";
          break;
        case 2:
          srcCursor = "GL_ARB_texture_env_crossbar";
          break;
        case 3:
          srcCursor = "GL_ARB_texture_border_clamp";
          break;
        case 4:
          srcCursor = "GL_ARB_multitexture";
          break;
        case 5:
          srcCursor = "GL_ARB_texture_env_add";
          break;
        case 6:
          srcCursor = "GL_ARB_texture_cube_map";
          break;
        case 7:
          srcCursor = "GL_ARB_texture_env_dot3";
          break;
        case 8:
          srcCursor = "GL_ARB_multisample";
          break;
        case 9:
          srcCursor = "GL_ARB_texture_env_combine";
          break;
        case 10:
          srcCursor = "GL_ARB_texture_compression";
          break;
        case 0xb:
          srcCursor = "GL_ARB_texture_mirrored_repeat";
          break;
        case 0xc:
          srcCursor = "GL_ARB_shadow";
          break;
        case 0xd:
          srcCursor = "GL_ARB_depth_texture";
          break;
        case 0xe:
          srcCursor = "GL_ARB_shadow_ambient";
          break;
        case 0xf:
          srcCursor = "GL_ARB_fragment_program";
          break;
        case 0x10:
          srcCursor = "GL_ARB_fragment_shader";
          break;
        case 0x11:
          srcCursor = "GL_ARB_occlusion_query";
          break;
        case 0x12:
          srcCursor = "GL_ARB_point_sprite";
          break;
        case 0x13:
          srcCursor = "GL_ARB_texture_non_power_of_two";
          break;
        case 0x14:
          if (*(char *)(glContext + 0x7584) != '\0') goto LAB_000122ec;
          srcCursor = "GL_ARB_vertex_buffer_object";
          break;
        case 0x15:
          srcCursor = "GL_ARB_pixel_buffer_object";
          break;
        case 0x16:
          srcCursor = "GL_ARB_draw_buffers";
          break;
        case 0x17:
          srcCursor = "GL_EXT_compiled_vertex_array";
          break;
        case 0x18:
          srcCursor = "GL_EXT_framebuffer_object";
          break;
        case 0x19:
          srcCursor = "GL_EXT_texture_rectangle GL_ARB_texture_rectangle";
          break;
        case 0x1a:
          srcCursor = "GL_EXT_texture_env_add";
          break;
        case 0x1b:
          srcCursor = "GL_EXT_blend_color";
          break;
        case 0x1c:
          srcCursor = "GL_EXT_blend_minmax";
          break;
        case 0x1d:
          srcCursor = "GL_EXT_blend_subtract";
          break;
        case 0x1e:
          srcCursor = "GL_EXT_texture_lod_bias";
          break;
        case 0x1f:
          srcCursor = "GL_EXT_abgr";
          break;
        case 0x20:
          srcCursor = "GL_EXT_bgra";
          break;
        case 0x21:
          srcCursor = "GL_EXT_stencil_wrap";
          break;
        case 0x22:
          srcCursor = "GL_EXT_texture_filter_anisotropic";
          break;
        case 0x23:
          srcCursor = "GL_EXT_paletted_texture";
          break;
        case 0x24:
          srcCursor = "GL_EXT_shared_texture_palette";
          break;
        case 0x25:
          srcCursor = "GL_EXT_separate_specular_color";
          break;
        case 0x26:
          srcCursor = "GL_EXT_secondary_color";
          break;
        case 0x27:
          srcCursor = "GL_EXT_blend_func_separate";
          break;
        case 0x28:
          srcCursor = "GL_EXT_shadow_funcs";
          break;
        case 0x29:
          srcCursor = "GL_EXT_stencil_two_side";
          break;
        case 0x2a:
          srcCursor = "GL_EXT_depth_bounds_test";
          break;
        case 0x2b:
          srcCursor = "GL_EXT_texture_compression_s3tc GL_EXT_texture_compression_dxt1";
          break;
        case 0x2c:
          srcCursor = "GL_EXT_blend_equation_separate";
          break;
        case 0x2d:
          srcCursor = "GL_EXT_texture_mirror_clamp";
          break;
        case 0x2e:
          srcCursor = "GL_APPLE_ycbcr_422";
          break;
        case 0x2f:
          srcCursor = "GL_APPLE_vertex_array_range";
          break;
        case 0x30:
          srcCursor = "GL_APPLE_texture_range";
          break;
        case 0x31:
          srcCursor = "GL_APPLE_float_pixels GL_ATI_texture_float";
          break;
        case 0x32:
          srcCursor = "GL_APPLE_pixel_buffer";
          break;
        case 0x33:
          srcCursor = "GL_NV_point_sprite";
          break;
        case 0x34:
          srcCursor = "GL_NV_register_combiners";
          break;
        case 0x35:
          srcCursor = "GL_NV_register_combiners2";
          break;
        case 0x36:
          srcCursor = "GL_NV_blend_square";
          break;
        case 0x37:
          srcCursor = "GL_NV_texture_shader";
          break;
        case 0x38:
          srcCursor = "GL_NV_texture_shader2";
          break;
        case 0x39:
          srcCursor = "GL_NV_texture_shader3";
          break;
        case 0x3a:
          srcCursor = "GL_NV_fog_distance";
          break;
        case 0x3b:
          srcCursor = "GL_NV_depth_clamp";
          break;
        case 0x3c:
          srcCursor = "GL_NV_multisample_filter_hint";
          break;
        case 0x3d:
          srcCursor = "GL_NV_fragment_program_option";
          break;
        case 0x3e:
          srcCursor = "GL_NV_fragment_program2";
          break;
        case 0x3f:
          srcCursor = "GL_NV_vertex_program2_option";
          break;
        case 0x40:
          srcCursor = "GL_NV_vertex_program3";
          break;
        case 0x41:
          srcCursor = "GL_ATI_point_cull_mode";
          break;
        case 0x42:
          srcCursor = "GL_ATI_texture_mirror_once";
          break;
        case 0x43:
          srcCursor = "GL_ATI_text_fragment_shader";
          break;
        case 0x44:
          srcCursor = "GL_ATI_blend_equation_separate";
          break;
        case 0x45:
          srcCursor = "GL_ATI_blend_weighted_minmax";
          break;
        case 0x46:
          srcCursor = "GL_ATI_texture_env_combine3";
          break;
        case 0x47:
          srcCursor = "GL_ATI_separate_stencil";
          break;
        case 0x48:
          srcCursor = "GL_ATI_array_rev_comps_in_4_bytes";
          break;
        case 0x49:
          srcCursor = "GL_ATI_pn_triangles";
          break;
        case 0x4a:
          srcCursor = "GL_ATI_texture_compression_3dc";
          break;
        case 0x4b:
          srcCursor = "GL_ATIX_pn_triangles";
          break;
        case 0x4c:
          srcCursor = "GL_SGIS_texture_edge_clamp";
          break;
        case 0x4d:
          srcCursor = "GL_SGIS_texture_lod";
          break;
        case 0x4e:
          srcCursor = "GL_SGI_color_matrix";
        }
        if (srcCursor != (char *)0x0) {
          cVar2 = *srcCursor;
          while (cVar2 != '\0') {
            *dstCursor = cVar2;
            dstCursor = dstCursor + 1;
            srcCursor = srcCursor + 1;
            cVar2 = *srcCursor;
          }
          *dstCursor = ' ';
          dstCursor = dstCursor + 1;
        }
      }
LAB_000122ec:
      loopIndex = loopIndex + 1;
      if (0x4e < (int)loopIndex) {
        *dstCursor = '\0';
        return (char *)(glContext + 0x759e);
      }
    } while( true );
  }
  if (name < 0x1f04) {
    if (name == 0x1f01) {
      if (*(char *)(glContext + 0x7585) != '\0') {
        pcVar6 = (char *)(**(code **)(glContext + 0x47bc))(*(undefined4 *)(glContext + 0x4688));
        if (*(short *)((uint)*(byte *)(glContext + 0x85a8) * 0x2e0 + glContext + 0x888a) == 0x2402) {
          return pcVar6;
        }
        pcVar5 = _strstr(pcVar6,"FX");
        if (pcVar5 != (char *)0x0) {
          stringLength = _strlen(pcVar6);
          _memcpy(&_new_rend_str_0,pcVar6,stringLength);
          (new_rend_str_0_byte1)[(int)pcVar5 - (int)pcVar6] = 0x78;
          return &_new_rend_str_0;
        }
        return pcVar6;
      }
      goto LAB_00011cf8;
    }
    if (0x1f01 < name) goto LAB_00011cf8;
    bVar1 = name == 0x1f00;
LAB_00011c44:
    if (bVar1) {
LAB_00011cf8:
      pcVar6 = (char *)(**(code **)(glContext + 0x47bc))(*(undefined4 *)(glContext + 0x4688),name);
      return pcVar6;
    }
  }
  else {
    if (name == 0x8874) {
      return *(char **)(glContext + 0x5418);
    }
    if (name < 0x8875) {
      bVar1 = name == 0x1f04;
      goto LAB_00011c44;
    }
    if (name == 0x8b8c) {
      return "1.10";
    }
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return (char *)0x0;
  }
  glErrorCode = 0x500;
LAB_0001231c:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return (char *)0x0;
}

/* _glGenFencesAPPLE_Exec @ 0x12338 (164 bytes) */
void _glGenFencesAPPLE_Exec(glContext, n, fences)
  int glContext;
  int n;
  int *fences;
{
  undefined4 glErrorCode;
  int iVar2;
  int loopIndex;
  int iVar4;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (-1 < n) {
      iVar4 = ((int (*)())_gleGenHashNames)(glContext + 0x543c,n);
      if (iVar4 == 0) {
        return;
      }
      loopIndex = 0;
      if (n < 1) {
        return;
      }
      do {
        iVar2 = loopIndex + iVar4;
        loopIndex = loopIndex + 1;
        *fences = iVar2;
        fences = fences + 1;
        n = n + -1;
      } while (n != 0);
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

/* _gleGenHashNames @ 0x123dc (304 bytes) */
int _gleGenHashNames(hashTable, listRange)
  int hashTable;
  uint listRange;
{
  uint uVar1;
  int nextRangeCount;
  uint candidateEndName;
  undefined4 *previousRangeNode;
  undefined4 *allocatedBlock;
  int previousRangeCount;
  uint candidateFirstName;
  undefined4 *rangeNode;
  undefined4 *allocatedBlock2;
  
  uVar1 = 0;
  rangeNode = *(undefined4 **)(hashTable + 0x1000);
  if (listRange != 0) {
    if (rangeNode == (undefined4 *)0x0) {
      allocatedBlock2 = (undefined4 *)_malloc(0xc);
      *allocatedBlock2 = 0;
      allocatedBlock2[1] = 1;
      allocatedBlock2[2] = listRange;
      *(undefined4 **)(hashTable + 0x1000) = allocatedBlock2;
    }
    else {
      uVar1 = rangeNode[1];
      if (uVar1 != listRange + 1) {
        if (listRange < uVar1) {
          allocatedBlock = (undefined4 *)_malloc(0xc);
          *(undefined4 **)(hashTable + 0x1000) = allocatedBlock;
          *allocatedBlock = rangeNode;
          allocatedBlock[1] = 1;
          allocatedBlock[2] = listRange;
          return 1;
        }
        while( true ) {
          previousRangeNode = rangeNode;
          previousRangeCount = previousRangeNode[2];
          rangeNode = (undefined4 *)*previousRangeNode;
          candidateFirstName = uVar1 + previousRangeCount;
          candidateEndName = candidateFirstName + listRange;
          if (candidateEndName < candidateFirstName) {
            return 0;
          }
          if ((rangeNode == (undefined4 *)0x0) || (uVar1 = rangeNode[1], candidateEndName < uVar1)) break;
          if (candidateEndName == uVar1) {
            nextRangeCount = rangeNode[2];
            *previousRangeNode = *rangeNode;
            previousRangeNode[2] = previousRangeCount + listRange + nextRangeCount;
            _free(rangeNode);
            return candidateFirstName;
          }
        }
        previousRangeNode[2] = previousRangeCount + listRange;
        return candidateFirstName;
      }
      rangeNode[1] = 1;
      rangeNode[2] = rangeNode[2] + listRange;
    }
    uVar1 = 1;
  }
  return uVar1;
}

/* _gliAttachDrawableWithOptions @ 0x1250c (656 bytes) */
int _gliAttachDrawableWithOptions(glContext, param_2, param_3, param_4, forwardedArg5)
  int glContext;
  int param_2;
  int param_3;
  uint param_4;
  undefined4 forwardedArg5;
{
  bool bVar1;
  int iVar2;
  undefined1 uVar3;
  int iVar4;
  char cVar5;
  uint uVar6;
  uint glContextByte85a5;
  double extraout_f1;
  double fparam_1;
  double incomingFpr2;
  double incomingFpr3;
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  double incomingStack_ffffff98;
  double incomingStack_ffffffa0;
  double incomingStack_ffffffa8;
  double incomingStack_ffffffb0;
  double incomingStack_ffffffb8;
  
  iVar2 = -(uint)(*(byte *)(glContext + 0x85a8) ^ *(byte *)(glContext + 0x85a6));
  bVar1 = false;
  if ((glContext == 0) || (*(int *)(glContext + 0x467c) != 0x3463a223)) {
    return 0x2714;
  }
  if ((param_2 == 0) != (param_3 == 0)) {
    return 0x2715;
  }
  if (((int)param_4 < 0) || ((int)(uint)*(byte *)(glContext + 0x85a4) <= (int)param_4)) {
    return 0x2718;
  }
  *(char *)(glContext + 0x85a6) = (char)param_4;
  *(undefined1 *)(glContext + 0x85a7) = 0;
  iVar4 = param_4 * 0x2e0 + glContext;
  uVar6 = (**(code **)(*(int *)(iVar4 + 0x8884) + 0x138))
                    (*(undefined4 *)(iVar4 + 0x85ac),param_2,param_3,forwardedArg5);
  fparam_1 = extraout_f1;
  if ((uVar6 < 5) && (param_4 != *(byte *)(glContext + 0x85a8))) {
    fparam_1 = (double)_gliSwitchPlugin(glContext,param_4);
    bVar1 = true;
    uVar6 = 2;
  }
  if (uVar6 == 2) {
    ((void (*)())_gliUpdatePluginConfig)(glContext,fparam_1,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,incomingStack_ffffff98,
               incomingStack_ffffffa0,incomingStack_ffffffa8,incomingStack_ffffffb0,incomingStack_ffffffb8);
LAB_00012634:
    bVar1 = true;
LAB_00012638:
    if (iVar2 < 0) {
      _gliDetachRevert(glContext);
    }
LAB_000126b8:
    uVar6 = 0;
  }
  else {
    if ((uVar6 < 2) || (uVar6 == 4)) goto LAB_00012638;
    if (uVar6 < 4) goto LAB_00012634;
    if (uVar6 == 0x2720) {
      if ((param_2 == 0) || (glContextByte85a5 = (uint)*(byte *)(glContext + 0x85a5), glContextByte85a5 == 0xff)) {
        uVar6 = 0x2720;
        goto LAB_00012744;
      }
      *(undefined1 *)(glContext + 0x85a7) = 1;
      iVar2 = glContextByte85a5 * 0x2e0 + glContext;
      uVar6 = (**(code **)(*(int *)(iVar2 + 0x8884) + 0x138))
                        (*(undefined4 *)(iVar2 + 0x85ac),param_2,param_3,forwardedArg5);
      if (4 < uVar6) goto LAB_000126d8;
      if (glContextByte85a5 != *(byte *)(glContext + 0x85a8)) {
        _gliSwitchPlugin(glContext,glContextByte85a5);
        bVar1 = true;
      }
      goto LAB_000126b8;
    }
    if (iVar2 < 0) {
      _gliDetachRevert(glContext);
    }
LAB_000126d8:
    if (uVar6 != 0) {
LAB_00012744:
      *(undefined4 *)(glContext + 0x4848) = 0;
      *(undefined4 *)(glContext + 0x484c) = 0;
      if ((*(char *)(glContext + 0x4692) != '\0') && (*(char *)(glContext + 0x4691) == '\0')) {
        return uVar6;
      }
      *(undefined1 *)(glContext + 0x4691) = 0;
      *(undefined1 *)(glContext + 0x4692) = 1;
      goto LAB_00012774;
    }
  }
  cVar5 = '\0';
  if ((*(char *)(glContext + 0x4690) == '\0') || (param_3 == 0)) {
    cVar5 = '\x01';
  }
  *(int *)(glContext + 0x4848) = param_3;
  *(int *)(glContext + 0x484c) = param_2;
  if ((!bVar1) && (*(char *)(glContext + 0x4692) == cVar5)) {
    return uVar6;
  }
  *(char *)(glContext + 0x4692) = cVar5;
  uVar3 = 0;
  if ((*(int *)(glContext + 0x4e1c) == 0x1c00) && (cVar5 == '\0')) {
    uVar3 = 1;
  }
  *(undefined1 *)(glContext + 0x4691) = uVar3;
  *(undefined4 *)(glContext + 0x757c) = 0xffffffff;
LAB_00012774:
  ((void (*)())_gliSetCurrentPluginDispatchTable)(glContext);
  return uVar6;
}

/* _gliUpdatePluginConfig @ 0x127a4 (104 bytes) */
void _gliUpdatePluginConfig(int glContext,double forwardedFloatArg1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  undefined *puVar1;
  double fparam_1_00;
  double incomingStack_ffffffb8;
  double incomingStack_ffffffc0;
  double incomingStack_ffffffc8;
  double incomingStack_ffffffd0;
  double incomingStack_ffffffd8;
  
  ((void (*)())_gleUpdateDepthRangeData)(glContext,forwardedFloatArg1,forwardedFloatArg2,forwardedFloatArg3,forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8,
             incomingStack_ffffffb8,incomingStack_ffffffc0,incomingStack_ffffffc8,incomingStack_ffffffd0,
             incomingStack_ffffffd8);
  ((void (*)())_gleUpdatePolyMode)(glContext);
  ((void (*)())_gleUpdateViewScissorData)(glContext,fparam_1_00,forwardedFloatArg2,forwardedFloatArg3,forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
  ((int (*)())_gleUpdateTextureTransform)(glContext);
  puVar1 = PTR__gleSetClipInterpFunc_00112038;
  *(undefined **)(glContext + 0x49c8) = PTR__gleSetEyeInterpFunc_0011203c;
  *(undefined **)(glContext + 0x49cc) = puVar1;
  ((void (*)())_gleResetVertexArrays)(glContext);
  return;
}

/* _gleResetVertexArrays @ 0x1280c (128 bytes) */
void _gleResetVertexArrays(glContext)
  int glContext;
{
  undefined4 uVar1;
  int glContextWord49a8;
  
  glContextWord49a8 = *(int *)(glContext + 0x49a8);
  uVar1 = ((int (*)())_gleReinitFuncCache)(*(undefined4 *)(glContext + 0x49b4));
  *(undefined4 *)(glContext + 0x49b4) = uVar1;
  uVar1 = ((int (*)())_gleReinitFuncCache)(*(undefined4 *)(glContext + 0x49b8));
  *(undefined4 *)(glContext + 0x49b8) = uVar1;
  *(undefined2 *)(glContext + 0x49c2) = 1;
  *(undefined4 *)(glContext + 0x49c4) = 0;
  *(undefined2 *)(glContext + 0x49be) = 1;
  if (glContextWord49a8 != 0) {
    (**(code **)(glContext + 0x47cc))(*(undefined4 *)(glContext + 0x4688),glContextWord49a8);
    *(undefined4 *)(glContext + 0x49a8) = 0;
    *(uint *)(glContext + 0x4980) = (uint)*(ushort *)(glContext + 0x4982);
  }
  return;
}

/* _gleReinitFuncCache @ 0x1288c (168 bytes) */
int _gleReinitFuncCache(funcCache)
  int *funcCache;
{
  int *entry;
  int headerBlock;
  int *nextEntry;
  
  headerBlock = 0;
  if (funcCache != (int *)0x0) {
    entry = (int *)*funcCache;
    while (entry != funcCache) {
      nextEntry = (int *)*entry;
      _gleDCBFree(entry);
      entry = nextEntry;
    }
    headerBlock = ((int (*)())_gleDCBRealloc)(funcCache,0x24);
    *(undefined4 *)(headerBlock + 0x14) = 0xffffffff;
    *(undefined4 *)(headerBlock + 0x20) = 0x4e800020;
    *(undefined4 *)(headerBlock + 8) = 0xffffffff;
    *(undefined4 *)(headerBlock + 0xc) = 0xffffffff;
    *(undefined4 *)(headerBlock + 0x10) = 0xffffffff;
    *(int *)(headerBlock + 4) = headerBlock;
    *(int *)headerBlock = headerBlock;
    (*(code *)_glePushInstructions)(1,headerBlock + 0x20);
  }
  return headerBlock;
}

/* _gleDCBRealloc @ 0x12934 (256 bytes) */
int _gleDCBRealloc(glContext, param_2)
  int glContext;
  int param_2;
{
  int loopIndex;
  int iVar1;
  uint uVar2;
  uint uVar3;
  int remaining;
  int reallocatedBlock;
  int remaining2;
  uint uVar7;
  
  if (param_2 < 1) {
    if (glContext != 0) {
      _gleDCBFree(glContext);
    }
    uVar3 = 0;
  }
  else {
    if (glContext == 0) {
      uVar3 = _gleDCBAlloc(param_2);
      return uVar3;
    }
    uVar7 = (uint)*(byte *)(glContext + -1);
    reallocatedBlock = _realloc(glContext - uVar7,param_2 + 0x3fU & 0xffffffe0);
    uVar3 = 0;
    if (reallocatedBlock != 0) {
      uVar3 = reallocatedBlock + 0x20U & 0xffffffe0;
      uVar2 = uVar3 - reallocatedBlock & 0xff;
      if (uVar2 != uVar7) {
        remaining = param_2 + 3 >> 2;
        if (uVar2 < uVar7) {
          loopIndex = 0;
          if (0 < remaining) {
            do {
              iVar1 = loopIndex * 4;
              loopIndex = loopIndex + 1;
              *(undefined4 *)(iVar1 + uVar3) = *(undefined4 *)(iVar1 + reallocatedBlock + uVar7);
              remaining = remaining + -1;
            } while (remaining != 0);
          }
        }
        else {
          remaining2 = remaining + -1;
          if (-1 < remaining2) {
            do {
              iVar1 = remaining2 * 4;
              remaining2 = remaining2 + -1;
              *(undefined4 *)(iVar1 + uVar3) = *(undefined4 *)(iVar1 + reallocatedBlock + uVar7);
              remaining = remaining + -1;
            } while (remaining != 0);
          }
        }
        *(char *)(uVar3 - 1) = (char)(uVar3 - reallocatedBlock);
      }
    }
  }
  return uVar3;
}

/* _glGetIntegerv_Exec @ 0x12a34 (332 bytes) */
void _glGetIntegerv_Exec(glContext, pname, params)
  int glContext;
  undefined4 pname;
  int *params;
{
  undefined4 glErrorCode;
  int iVar2;
  double *cursor;
  int remaining;
  double dVar5;
  double dVar6;
  char local_b0 [16];
  double local_a0 [16];
  longlong local_20;
  int valueType [2];
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    cursor = local_a0;
    remaining = ((int (*)())_gleGetState)(glContext,pname,cursor,valueType,local_b0);
    dVar6 = DOUBLE_00108d90;
    if (remaining == 0) {
      if (*(int *)(glContext + 0x7574) != 0) {
        return;
      }
      glErrorCode = 0x500;
      goto LAB_00012aa8;
    }
    if (remaining != -1) {
      if (valueType[0] == 0x1404) {
        if (remaining < 1) {
          return;
        }
        do {
          iVar2 = *(int *)cursor;
          cursor = cursor + 1;
          *params = iVar2;
          params = params + 1;
          remaining = remaining + -1;
        } while (remaining != 0);
        return;
      }
      if (local_b0[0] == '\0') {
        if (remaining < 1) {
          return;
        }
        do {
          dVar6 = *cursor;
          cursor = cursor + 1;
          local_20 = (longlong)(int)dVar6;
          *params = (int)dVar6;
          params = params + 1;
          remaining = remaining + -1;
        } while (remaining != 0);
        return;
      }
      if (remaining < 1) {
        return;
      }
      do {
        dVar5 = *cursor;
        cursor = cursor + 1;
        local_20 = (longlong)(int)(dVar5 * dVar6);
        *params = (int)(dVar5 * dVar6);
        params = params + 1;
        remaining = remaining + -1;
      } while (remaining != 0);
      return;
    }
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  glErrorCode = 0x502;
LAB_00012aa8:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _gleGetState @ 0x12b80 (13228 bytes) */
int _gleGetState(glContext, pname, values, valueType, param_5)
  int glContext;
  uint pname;
  double *values;
  undefined4 *valueType;
  undefined1 *param_5;
{
  float rangeMax;
  float floatStateValueB;
  float glContextFloat2c8;
  uint scalarResult;
  int nextIndex;
  int attachmentRecord;
  int attachmentObject;
  uint otherLimit;
  int *srcCursor;
  undefined4 glContextWord4688;
  undefined4 rendererTextureName;
  undefined4 attachmentParamA;
  undefined4 attachmentParamB;
  undefined4 sizeQueryEnum;
  int attachmentIndexThenBody;
  int glContextPtr468c;
  code *glContextPtr479c;
  int iVar13;
  int drawBufferIndex;
  int fogCoordArrayBuffer;
  int secondaryColorArrayBuffer;
  int weightArrayBuffer;
  int clientArrayBuffer37c;
  int texCoordArrayBuffer;
  int colorArrayBuffer;
  int vertexArrayBuffer;
  int elementArrayBuffer;
  int normalArrayBuffer;
  int arrayBuffer;
  int edgeFlagArrayBuffer;
  int currentMatrixPtr;
  int formatIndex;
  int matrixPtr;
  int valueCount;
  int matrixModeIndex;
  int glContextPtr4854;
  int framebufferObject;
  int clientState;
  double intToDoubleMagicThenValue;
  double doubleStateValue;
  double fourthComponent2;
  double floatStateValue;
  double secondValue;
  double fourthComponent;
  longlong arrayEnableBit;
  
  *valueType = 0x1404;
  *param_5 = 0;
  intToDoubleMagicThenValue = DOUBLE_00108d58;
  valueCount = 1;
  if (pname == 0x6092) {
    scalarResult = (uint)*(ushort *)(glContext + 0x2808);
    goto LAB_00015f48;
  }
  if (0x6092 < pname) {
    if (pname == 0x84e2) {
      scalarResult = (uint)*(ushort *)(*(int *)(glContext + 0x468c) + 0xb4);
      goto LAB_00015f48;
    }
    if (0x84e2 < pname) {
      if (pname == 0x86aa) {
        scalarResult = *(uint *)(*(int *)(glContext + 0x4a60) + 0xac);
        goto LAB_00015f48;
      }
      if (pname < 0x86ab) {
        if (pname == 0x854e) {
          scalarResult = *(uint *)(glContext + 0x41fc);
          goto LAB_00015f48;
        }
        if (pname < 0x854f) {
          if (pname == 0x8505) {
            scalarResult = *(uint *)(*(int *)(glContext + 0x468c) + 0xa4);
            goto LAB_00015f48;
          }
          if (pname < 0x8506) {
            if (pname == 0x84ef) {
              scalarResult = (uint)*(ushort *)(glContext + 0x3176);
              goto LAB_00015f48;
            }
            if (pname < 0x84f0) {
              if (pname == 0x84e5) {
                if (7 < *(int *)(glContext + 0x53d4)) {
                  return -1;
                }
                matrixPtr = glContext + *(int *)(glContext + 0x53d4) * 0x40 + 0x1fc0;
              }
              else if (pname < 0x84e6) {
                if (pname == 0x84e3) {
                  matrixPtr = glContext + 0x1cc0;
                }
                else {
                  if (pname != 0x84e4) {
                    return 0;
                  }
                  matrixPtr = glContext + 0x1c80;
                }
              }
              else {
                if (pname != 0x84e6) {
                  if (pname != 0x84e8) {
                    return 0;
                  }
                  otherLimit = *(uint *)(*(int *)(glContext + 0x468c) + 0x10);
                  scalarResult = *(uint *)(*(int *)(glContext + 0x468c) + 0xc);
                  if ((int)otherLimit < (int)scalarResult) {
                    scalarResult = otherLimit;
                  }
                  goto LAB_00015efc;
                }
                matrixPtr = glContext + 0x1c40;
              }
              goto LAB_00014d40;
            }
            if (pname == 0x84f8) goto LAB_00015960;
            if (0x84f8 < pname) {
              if (pname == 0x84ff) {
                scalarResult = (uint)(int)*(float *)(*(int *)(glContext + 0x468c) + 0xac);
              }
              else if (pname < 0x8500) {
                if (pname != 0x84fd) {
                  return 0;
                }
                scalarResult = (uint)(int)*(float *)(*(int *)(glContext + 0x468c) + 0xb0);
              }
              else {
                if (pname != 0x8504) {
                  return 0;
                }
                scalarResult = *(uint *)(*(int *)(glContext + 0x468c) + 0xa0);
              }
              goto LAB_00015f48;
            }
            if (pname == 0x84f5) goto LAB_000155d4;
            if (pname != 0x84f6) {
              return 0;
            }
            goto LAB_00015948;
          }
          if (pname == 0x851f) {
            scalarResult = (uint)*(ushort *)(*(int *)(glContext + 0x4a60) + 0x342);
            goto LAB_00015f48;
          }
          if (0x851f < pname) {
            if (pname == 0x852a) {
              *values = (double)*(float *)(glContext + 0x4200);
              values[1] = (double)*(float *)(glContext + 0x4204);
              values[2] = (double)*(float *)(glContext + 0x4208);
              fourthComponent = (double)*(float *)(glContext + 0x420c);
            }
            else {
              if (pname < 0x852b) {
                if (pname == 0x8520) {
                  scalarResult = *(uint *)(*(int *)(glContext + 0x468c) + 0x8c);
                }
                else {
                  if (pname != 0x8522) {
                    return 0;
                  }
                  scalarResult = (uint)*(byte *)(glContext + 0x41f8);
                }
                goto LAB_00015f48;
              }
              if (pname == 0x8534) {
                scalarResult = (uint)*(ushort *)(glContext + 0x317a);
                goto LAB_00015f48;
              }
              if (0x8534 < pname) {
                if (pname != 0x854d) {
                  return 0;
                }
                scalarResult = *(uint *)(*(int *)(glContext + 0x468c) + 0x98);
                goto LAB_00015f48;
              }
              if (pname != 0x852b) {
                return 0;
              }
              *values = (double)*(float *)(glContext + 0x4210);
              values[1] = (double)*(float *)(glContext + 0x4214);
              values[2] = (double)*(float *)(glContext + 0x4218);
              fourthComponent = (double)*(float *)(glContext + 0x421c);
            }
            goto LAB_00015a8c;
          }
          if (pname == 0x8514) {
            scalarResult = *(uint *)(*(int *)(*(int *)(glContext + 0x53d4) * 0x14 + glContext + 0x5154) + 4);
            goto LAB_00015f48;
          }
          if (0x8514 < pname) {
            if (pname == 0x851c) {
              scalarResult = (uint)*(ushort *)(*(int *)(glContext + 0x468c) + 0xc2);
            }
            else {
              if (pname != 0x851e) {
                return 0;
              }
              scalarResult = *(uint *)(*(int *)(glContext + 0x4a60) + 0x348);
            }
            goto LAB_00015f48;
          }
          if (pname != 0x850a) {
            if (pname != 0x8513) {
              return 0;
            }
            scalarResult = *(uint *)(*(int *)(glContext + 0x53d4) * 0x7c + glContext + 0x3534) & 1;
            goto LAB_00015f48;
          }
          matrixPtr = glContext + 0x1d00;
        }
        else {
          if (pname != 0x8641) {
            if (0x8641 < pname) {
              if (pname == 0x86a3) {
                glContextPtr468c = *(int *)(glContext + 0x468c);
                formatIndex = 0;
                if (*(char *)(glContextPtr468c + 0xc6) != '\0') {
                  do {
                    nextIndex = formatIndex + 1;
                    *(uint *)(values + formatIndex) = *(uint *)(formatIndex * 4 + glContextPtr468c + 200);
                    glContextPtr468c = *(int *)(glContext + 0x468c);
                    formatIndex = nextIndex;
                  } while (nextIndex < (int)(uint)*(byte *)(glContextPtr468c + 0xc6));
                  return nextIndex;
                }
                return 0;
              }
              if (pname < 0x86a4) {
                if (pname == 0x864b) {
                  scalarResult = *(uint *)(glContext + 0x541c);
                }
                else if (pname < 0x864c) {
                  if (pname == 0x8642) {
                    scalarResult = (uint)*(byte *)(glContext + 0x4665);
                  }
                  else {
                    if (pname != 0x8643) {
                      return 0;
                    }
                    scalarResult = (uint)*(byte *)(glContext + 0x4666);
                  }
                }
                else if (pname == 0x864f) {
                  scalarResult = (uint)*(byte *)(glContext + 0x3129);
                }
                else {
                  if (pname != 0x86a2) {
                    return 0;
                  }
                  scalarResult = (uint)*(byte *)(*(int *)(glContext + 0x468c) + 0xc6);
                }
                goto LAB_00015f48;
              }
              if (pname == 0x86a6) {
                scalarResult = (uint)*(byte *)(glContext + 0x4662);
                goto LAB_00015f48;
              }
              if (pname < 0x86a7) {
                if (pname == 0x86a4) {
                  scalarResult = *(uint *)(*(int *)(glContext + 0x468c) + 0x90);
                }
                else {
                  if (pname != 0x86a5) {
                    return 0;
                  }
                  scalarResult = (uint)*(byte *)(glContext + 0x4660);
                }
                goto LAB_00015f48;
              }
              if (pname != 0x86a8) {
                if (pname < 0x86a9) {
                  scalarResult = (uint)*(byte *)(glContext + 0x4661);
                }
                else {
                  scalarResult = *(ushort *)(*(int *)(glContext + 0x4a60) + 0xb0) & 0xffff7fff;
                }
                goto LAB_00015f48;
              }
              *values = (double)*(float *)(glContext + 0x2d0);
              values[1] = (double)*(float *)(glContext + 0x2d4);
              values[2] = (double)*(float *)(glContext + 0x2d8);
              fourthComponent = (double)*(float *)(glContext + 0x2dc);
              goto LAB_00015a8c;
            }
            if (pname != 0x85b4) {
              if (pname < 0x85b5) {
                if (pname == 0x85b1) {
                  scalarResult = *(uint *)(glContext + 0x507c);
                  goto LAB_00015f48;
                }
                if (pname < 0x85b2) {
                  if (pname == 0x855a) {
                    scalarResult = (uint)*(ushort *)(glContext + 0x3168);
                  }
                  else {
                    if (pname != 0x85b0) {
                      return 0;
                    }
                    scalarResult = (uint)*(byte *)(glContext + 0x30ae);
                  }
                  goto LAB_00015f48;
                }
                if (pname == 0x85b2) {
                  scalarResult = (uint)*(byte *)(glContext + 0x31e6);
                  goto LAB_00015f48;
                }
                if (pname != 0x85b3) {
                  return 0;
                }
LAB_000155d4:
                scalarResult = *(uint *)(*(int *)(glContext + 0x53d4) * 0x7c + glContext + 0x3534) >> 2 & 1;
                goto LAB_00015f48;
              }
              if (pname == 0x8620) {
                scalarResult = (uint)*(byte *)(glContext + 0x4664);
                goto LAB_00015f48;
              }
              if (0x8620 < pname) {
                if (pname == 0x862f) {
                  scalarResult = 8;
                  goto LAB_00015f48;
                }
                if (pname < 0x8630) {
                  if (pname != 0x862e) {
                    return 0;
                  }
                  scalarResult = 2;
                  goto LAB_00015f48;
                }
                if (pname != 0x8640) {
                  return 0;
                }
                currentMatrixPtr = *(int *)(*(int *)(glContext + 0x4ff4) * 4 + glContext + 0x4ffc);
                goto LAB_00014c5c;
              }
              if (pname == 0x85b5) {
                scalarResult = *(uint *)(*(int *)(glContext + 0x4a60) + 4);
                goto LAB_00015f48;
              }
              if (pname != 0x85b6) {
                return 0;
              }
LAB_00015960:
              scalarResult = *(uint *)(*(int *)(glContext + 0x468c) + 0xe8);
              goto LAB_00015f48;
            }
LAB_00015948:
            scalarResult = *(uint *)(*(int *)(*(int *)(glContext + 0x53d4) * 0x14 + glContext + 0x515c) + 4);
            goto LAB_00015f48;
          }
          matrixPtr = glContext + *(int *)(glContext + 0x4ff4) * 0x40 + 0x1bc0;
        }
LAB_00014c84:
        _gleGetMatrixd(matrixPtr,values);
      }
      else {
        if (pname == 0x889b) {
          scalarResult = 0;
          edgeFlagArrayBuffer = *(int *)(*(int *)(glContext + 0x4a60) + 0x378);
          if (edgeFlagArrayBuffer != 0) {
            scalarResult = *(uint *)(edgeFlagArrayBuffer + 4);
          }
          goto LAB_00015f48;
        }
        if (pname < 0x889c) {
          if (pname == 0x883d) {
            scalarResult = (uint)*(ushort *)(glContext + 0x30e2);
            goto LAB_00015f48;
          }
          if (0x883d < pname) {
            if (pname == 0x8894) {
              scalarResult = 0;
              arrayBuffer = *(int *)(*(int *)(glContext + 0x4a60) + 0x358);
              if (arrayBuffer != 0) {
                scalarResult = *(uint *)(arrayBuffer + 4);
              }
              goto LAB_00015f48;
            }
            if (0x8894 < pname) {
              if (pname == 0x8897) {
                scalarResult = 0;
                normalArrayBuffer = *(int *)(*(int *)(glContext + 0x4a60) + 0x364);
                if (normalArrayBuffer != 0) {
                  scalarResult = *(uint *)(normalArrayBuffer + 4);
                }
              }
              else if (pname < 0x8898) {
                if (pname == 0x8895) {
                  scalarResult = 0;
                  elementArrayBuffer = *(int *)(*(int *)(glContext + 0x4a60) + 0x35c);
                  if (elementArrayBuffer != 0) {
                    scalarResult = *(uint *)(elementArrayBuffer + 4);
                  }
                }
                else {
                  if (pname != 0x8896) {
                    return 0;
                  }
                  scalarResult = 0;
                  vertexArrayBuffer = *(int *)(*(int *)(glContext + 0x4a60) + 0x360);
                  if (vertexArrayBuffer != 0) {
                    scalarResult = *(uint *)(vertexArrayBuffer + 4);
                  }
                }
              }
              else if (pname == 0x8899) {
                scalarResult = 0;
                if (*(int *)(glContext + 0x48f4) != 0) {
                  scalarResult = *(uint *)(*(int *)(glContext + 0x48f4) + 4);
                }
              }
              else if (pname < 0x889a) {
                scalarResult = 0;
                colorArrayBuffer = *(int *)(*(int *)(glContext + 0x4a60) + 0x368);
                if (colorArrayBuffer != 0) {
                  scalarResult = *(uint *)(colorArrayBuffer + 4);
                }
              }
              else {
                scalarResult = 0;
                texCoordArrayBuffer = *(int *)(*(int *)(glContext + 0x53d8) * 4 + *(int *)(glContext + 0x4a60) +
                                 0x380);
                if (texCoordArrayBuffer != 0) {
                  scalarResult = *(uint *)(texCoordArrayBuffer + 4);
                }
              }
              goto LAB_00015f48;
            }
            if (pname == 0x8872) {
              scalarResult = (uint)*(ushort *)(*(int *)(glContext + 0x468c) + 0xb6);
              goto LAB_00015f48;
            }
            if (pname < 0x8873) {
              if (pname == 0x8869) {
                scalarResult = 0x10;
              }
              else {
                if (pname != 0x8871) {
                  return 0;
                }
                scalarResult = (uint)*(ushort *)(*(int *)(glContext + 0x468c) + 0xba);
              }
              goto LAB_00015f48;
            }
            if (pname == 0x8890) {
              scalarResult = (uint)*(byte *)(glContext + 0x312a);
              goto LAB_00015f48;
            }
            if (pname != 0x8891) {
              return 0;
            }
            *values = *(double *)(glContext + 0x312c);
            secondValue = *(double *)(glContext + 0x3134);
LAB_00015cf4:
            valueCount = 2;
            values[1] = secondValue;
            goto LAB_00015d48;
          }
          if (pname == 0x8801) {
            scalarResult = (uint)*(ushort *)(glContext + 0x351a);
            goto LAB_00015f48;
          }
          if (0x8801 < pname) {
            if (pname == 0x8804) {
              scalarResult = (uint)*(byte *)(glContext + 0x466c);
            }
            else if (pname < 0x8805) {
              if (pname == 0x8802) {
                scalarResult = (uint)*(ushort *)(glContext + 0x351c);
              }
              else {
                if (pname != 0x8803) {
                  return 0;
                }
                scalarResult = (uint)*(ushort *)(glContext + 0x351e);
              }
            }
            else if (pname == 0x8824) {
              scalarResult = *(uint *)(*(int *)(glContext + 0x468c) + 0x14);
            }
            else {
              if (pname < 0x8824) {
                return 0;
              }
              if (0x8834 < pname) {
                return 0;
              }
              scalarResult = 0;
              drawBufferIndex = pname - 0x8825;
              if (drawBufferIndex < 4) {
                if (*(int *)(glContext + 0x744c) == 0) {
                  scalarResult = (uint)*(ushort *)(drawBufferIndex * 2 + glContext + 0x311a);
                }
                else {
                  scalarResult = (uint)*(ushort *)(drawBufferIndex * 2 + *(int *)(glContext + 0x744c) + 0xc0);
                }
              }
            }
            goto LAB_00015f48;
          }
          if (0x8723 < pname) {
            if (pname != 0x8800) {
              return 0;
            }
            scalarResult = (uint)*(ushort *)(glContext + 0x3518);
            goto LAB_00015f48;
          }
          if (pname < 0x8722) {
            if (pname == 0x86ab) {
              scalarResult = (uint)*(short *)(*(int *)(glContext + 0x4a60) + 0xb2);
            }
            else {
              if (pname != 0x86ad) {
                return 0;
              }
              scalarResult = *(uint *)(*(int *)(glContext + 0x4a60) + 0x334) >> 0x15 & 1;
            }
            goto LAB_00015f48;
          }
          matrixPtr = glContext + pname * 0x40 + -0x21ab40;
          goto LAB_00014c84;
        }
        if (pname == 0x8a10) {
          *(uint *)values = *(uint *)(*(int *)(glContext + 0x468c) + 0x1c);
          scalarResult = *(uint *)(*(int *)(glContext + 0x468c) + 0x20);
          goto LAB_00015638;
        }
        if (0x8a10 < pname) {
          if (pname == 0x8b4d) {
            scalarResult = 0x10;
          }
          else if (pname < 0x8b4e) {
            if (pname == 0x8b4a) {
              scalarResult = 0x200;
            }
            else if (pname < 0x8b4b) {
              if (pname == 0x8a11) {
                scalarResult = 0;
                clientArrayBuffer37c = *(int *)(*(int *)(glContext + 0x4a60) + 0x37c);
                if (clientArrayBuffer37c != 0) {
                  scalarResult = *(uint *)(clientArrayBuffer37c + 4);
                }
              }
              else {
                if (pname != 0x8b49) {
                  return 0;
                }
                scalarResult = 0x200;
              }
            }
            else if (pname == 0x8b4b) {
              scalarResult = 0x20;
            }
            else {
              if (pname != 0x8b4c) {
                return 0;
              }
              scalarResult = 0;
            }
          }
          else if (pname == 0x8ca6) {
            scalarResult = 0;
            if (*(int *)(glContext + 0x744c) != 0) {
              scalarResult = *(uint *)(*(int *)(glContext + 0x744c) + 4);
            }
          }
          else if (pname < 0x8ca7) {
            if (pname == 0x8b8b) {
              scalarResult = (uint)*(ushort *)(glContext + 0x317c);
            }
            else {
              if (pname != 0x8b8d) {
                return 0;
              }
              scalarResult = 0;
              if (*(int *)(glContext + 0x5430) != 0) {
                scalarResult = *(uint *)(*(int *)(glContext + 0x5430) + 4);
              }
            }
          }
          else if (pname == 0x8cdf) {
            scalarResult = *(uint *)(*(int *)(glContext + 0x468c) + 0x18);
          }
          else if (pname < 0x8ce0) {
            if (pname != 0x8ca7) {
              return 0;
            }
            scalarResult = 0;
            if (*(int *)(glContext + 0x7448) != 0) {
              scalarResult = *(uint *)(*(int *)(glContext + 0x7448) + 4);
            }
          }
          else {
            if (pname != 0x19262) {
              return 0;
            }
            scalarResult = (uint)*(byte *)(glContext + 0x50b5);
          }
          goto LAB_00015f48;
        }
        if (pname == 0x88ef) {
          scalarResult = 0;
          if (*(int *)(glContext + 0x4a6c) != 0) {
            scalarResult = *(uint *)(*(int *)(glContext + 0x4a6c) + 4);
          }
          goto LAB_00015f48;
        }
        if (0x88ef < pname) {
          if (pname == 0x897c) {
            scalarResult = (uint)*(byte *)(*(int *)(glContext + 0x4a60) + 0x34c);
          }
          else if (pname < 0x897d) {
            if (pname != 0x8910) {
              if (pname != 0x8911) {
                return 0;
              }
              scalarResult = *(byte *)(glContext + 0x7583) + 0x404;
              goto LAB_00015efc;
            }
            scalarResult = *(uint *)(glContext + 0x3520) >> 2 & 1;
          }
          else if (pname == 0x8a0d) {
            scalarResult = (uint)*(ushort *)(*(int *)(glContext + 0x4a60) + 0xe0);
          }
          else if (pname < 0x8a0e) {
            if (pname != 0x8a0c) {
              return 0;
            }
            scalarResult = *(uint *)(*(int *)(glContext + 0x4a60) + 0x334) >> 0x17 & 1;
          }
          else {
            if (pname != 0x8a0f) {
              return 0;
            }
            scalarResult = (uint)*(byte *)(*(int *)(glContext + 0x468c) + 0x27);
          }
          goto LAB_00015f48;
        }
        if (pname == 0x889e) {
          scalarResult = 0;
          weightArrayBuffer = *(int *)(*(int *)(glContext + 0x4a60) + 0x374);
          if (weightArrayBuffer != 0) {
            scalarResult = *(uint *)(weightArrayBuffer + 4);
          }
          goto LAB_00015f48;
        }
        if (pname < 0x889f) {
          if (pname == 0x889c) {
            scalarResult = 0;
            secondaryColorArrayBuffer = *(int *)(*(int *)(glContext + 0x4a60) + 0x370);
            if (secondaryColorArrayBuffer != 0) {
              scalarResult = *(uint *)(secondaryColorArrayBuffer + 4);
            }
          }
          else {
            if (pname != 0x889d) {
              return 0;
            }
            scalarResult = 0;
            fogCoordArrayBuffer = *(int *)(*(int *)(glContext + 0x4a60) + 0x36c);
            if (fogCoordArrayBuffer != 0) {
              scalarResult = *(uint *)(fogCoordArrayBuffer + 4);
            }
          }
          goto LAB_00015f48;
        }
        if (pname != 34999) {
          if (pname != 0x88ed) {
            return 0;
          }
          scalarResult = 0;
          if (*(int *)(glContext + 0x4a68) != 0) {
            scalarResult = *(uint *)(*(int *)(glContext + 0x4a68) + 4);
          }
          goto LAB_00015f48;
        }
        matrixPtr = glContext + *(int *)(glContext + 0x4ff4) * 0x40 + 0x1bc0;
LAB_00014d40:
        _gleGetTransposeMatrixd(matrixPtr,values);
      }
      valueCount = 0x10;
      goto LAB_00015d48;
    }
    if (pname == 0x809f) {
      scalarResult = (uint)*(byte *)(glContext + 0x41f2);
      goto LAB_00015f48;
    }
    if (pname < 0x80a0) {
      if (pname == 0x806d) {
        scalarResult = *(uint *)(glContext + 0x31dc);
        goto LAB_00015f48;
      }
      if (0x806d < pname) {
        if (pname == 0x807e) {
          scalarResult = *(ushort *)(*(int *)(glContext + 0x4a60) + 0x50) & 0xffff7fff;
        }
        else if (pname < 0x807f) {
          if (pname == 0x8076) {
            scalarResult = *(uint *)(*(int *)(glContext + 0x4a60) + 0x334) >> 0x12 & 1;
          }
          else if (pname < 0x8077) {
            if (pname == 0x8073) {
              scalarResult = (uint)*(ushort *)(*(int *)(glContext + 0x468c) + 0xbe);
            }
            else if (pname < 0x8074) {
              if (pname == 0x806e) {
                scalarResult = *(uint *)(glContext + 0x31d0);
              }
              else {
                if (pname != 0x806f) {
                  return 0;
                }
                scalarResult = *(uint *)(*(int *)(glContext + 0x53d4) * 0x7c + glContext + 0x3534) >> 1 & 1;
              }
            }
            else if (pname == 0x8074) {
              scalarResult = *(uint *)(*(int *)(glContext + 0x4a60) + 0x334) >> 0x10 & 1;
            }
            else {
              if (pname != 0x8075) {
                return 0;
              }
              scalarResult = *(uint *)(*(int *)(glContext + 0x4a60) + 0x334) >> 0x11 & 1;
            }
          }
          else if (pname == 0x8079) {
            scalarResult = *(uint *)(*(int *)(glContext + 0x4a60) + 0x334) >> 0x16 & 1;
          }
          else if (pname < 0x807a) {
            if (pname == 0x8077) {
              scalarResult = -(uint)*(ushort *)(glContext + 0x48ea) >> 0x1f;
            }
            else {
              if (pname != 0x8078) {
                return 0;
              }
              clientState = *(int *)(glContext + 0x4a60);
              arrayEnableBit = ___ashldi3(0,0x1000000,*(undefined4 *)(glContext + 0x53d8));
              scalarResult = 0;
              if ((*(uint *)(clientState + 0x330) & (uint)((ulonglong)arrayEnableBit >> 0x20)) != 0 ||
                  (*(uint *)(clientState + 0x334) & (uint)arrayEnableBit) != 0) {
                scalarResult = 1;
              }
            }
          }
          else if (pname == 0x807b) {
            scalarResult = (uint)*(ushort *)(*(int *)(glContext + 0x4a60) + 0x38);
          }
          else if (pname < 0x807b) {
            scalarResult = (uint)*(short *)(*(int *)(glContext + 0x4a60) + 0x3a);
          }
          else {
            if (pname != 0x807c) {
              return 0;
            }
            scalarResult = *(uint *)(*(int *)(glContext + 0x4a60) + 0x34);
          }
        }
        else if (pname == 0x8086) {
          scalarResult = *(uint *)(glContext + 0x48e4);
        }
        else if (pname < 0x8087) {
          if (pname == 0x8082) {
            scalarResult = *(ushort *)(*(int *)(glContext + 0x4a60) + 0x68) & 0xffff7fff;
          }
          else if (pname < 0x8083) {
            if (pname == 0x807f) {
              scalarResult = *(uint *)(*(int *)(glContext + 0x4a60) + 0x4c);
            }
            else {
              if (pname != 0x8081) {
                return 0;
              }
              scalarResult = (uint)*(short *)(*(int *)(glContext + 0x4a60) + 0x6a);
            }
          }
          else if (pname == 0x8083) {
            scalarResult = *(uint *)(*(int *)(glContext + 0x4a60) + 100);
          }
          else {
            if (pname != 0x8085) {
              return 0;
            }
            scalarResult = (uint)*(ushort *)(glContext + 0x48e8);
          }
        }
        else if (pname == 0x808a) {
          scalarResult = *(uint *)(*(int *)(glContext + 0x53d8) * 0x18 + *(int *)(glContext + 0x4a60) + 0xf4);
        }
        else if (pname < 0x808b) {
          if (pname == 0x8088) {
            scalarResult = (uint)*(short *)(*(int *)(glContext + 0x53d8) * 0x18 + *(int *)(glContext + 0x4a60)
                                    + 0xfa);
          }
          else {
            if (pname != 0x8089) {
              return 0;
            }
            scalarResult = (uint)*(ushort *)
                           (*(int *)(glContext + 0x53d8) * 0x18 + *(int *)(glContext + 0x4a60) + 0xf8);
          }
        }
        else if (pname == 0x809d) {
          scalarResult = (uint)*(byte *)(glContext + 0x41f0);
        }
        else if (pname < 0x809e) {
          if (pname != 0x808c) {
            return 0;
          }
          scalarResult = *(uint *)(*(int *)(glContext + 0x4a60) + 0xc4);
        }
        else {
          scalarResult = (uint)*(byte *)(glContext + 0x41f1);
        }
        goto LAB_00015f48;
      }
      if (pname == 0x8021) {
        floatStateValue = (double)*(float *)(glContext + 0x339c);
      }
      else if (pname < 0x8022) {
        if (pname == 0x8011) {
          scalarResult = *(uint *)(glContext + 0x3410) >> 1 & 1;
          goto LAB_00015f48;
        }
        if (pname < 0x8012) {
          if (pname != 0x8005) {
            if (pname < 0x8006) {
              if (pname == 0x6093) {
                scalarResult = (uint)*(ushort *)(glContext + 0x280a);
              }
              else {
                if (pname != 0x6094) {
                  return 0;
                }
                scalarResult = *(uint *)(glContext + 0x2800);
              }
            }
            else if (pname == 0x8009) {
              scalarResult = (uint)*(ushort *)(glContext + 0x30e0);
            }
            else {
              if (pname != 0x8010) {
                return 0;
              }
              scalarResult = *(uint *)(glContext + 0x3410) & 1;
            }
            goto LAB_00015f48;
          }
          *values = (double)*(float *)(glContext + 0x30d0);
          values[1] = (double)*(float *)(glContext + 0x30d4);
          values[2] = (double)*(float *)(glContext + 0x30d8);
          fourthComponent = (double)*(float *)(glContext + 0x30dc);
          goto LAB_00015a8c;
        }
        if (pname == 0x801d) {
          floatStateValue = (double)*(float *)(glContext + 0x3398);
        }
        else if (pname < 0x801e) {
          if (pname == 0x8012) {
            scalarResult = *(uint *)(glContext + 0x3410) >> 2 & 1;
            goto LAB_00015f48;
          }
          if (pname != 0x801c) {
            return 0;
          }
          floatStateValue = (double)*(float *)(glContext + 0x3390);
        }
        else if (pname == 0x801f) {
          floatStateValue = (double)*(float *)(glContext + 0x33a8);
        }
        else if (pname < 0x8020) {
          floatStateValue = (double)*(float *)(glContext + 0x33a0);
        }
        else {
          floatStateValue = (double)*(float *)(glContext + 0x3394);
        }
      }
      else if (pname == 0x8038) {
        floatStateValue = (double)*(float *)(glContext + 0x34c8);
      }
      else {
        if (0x8038 < pname) {
          if (pname == 0x8069) {
            scalarResult = *(uint *)(*(int *)(*(int *)(glContext + 0x53d4) * 0x14 + glContext + 0x5160) + 4);
          }
          else if (pname < 0x806a) {
            if (pname == 0x803a) {
              scalarResult = (uint)*(byte *)(glContext + 0x280e);
            }
            else {
              if (pname != 0x8068) {
                return 0;
              }
              scalarResult = *(uint *)(*(int *)(*(int *)(glContext + 0x53d4) * 0x14 + glContext + 0x5164) + 4);
            }
          }
          else if (pname == 0x806b) {
            scalarResult = *(uint *)(glContext + 0x31c0);
          }
          else if (pname < 0x806c) {
            scalarResult = *(uint *)(*(int *)(*(int *)(glContext + 0x53d4) * 0x14 + glContext + 0x5158) + 4);
          }
          else {
            scalarResult = *(uint *)(0x31b4 + glContext);
          }
          goto LAB_00015f48;
        }
        if (pname == 0x8024) {
          scalarResult = *(uint *)(glContext + 0x3410) >> 4 & 1;
          goto LAB_00015f48;
        }
        if (0x8024 < pname) {
          if (pname == 0x802e) {
            scalarResult = *(uint *)(glContext + 0x3410) >> 3 & 1;
          }
          else {
            if (pname != 0x8037) {
              return 0;
            }
            scalarResult = (uint)*(byte *)(glContext + 0x34dd);
          }
          goto LAB_00015f48;
        }
        if (pname == 0x8022) {
          floatStateValue = (double)*(float *)(glContext + 0x33a4);
        }
        else {
          if (pname != 0x8023) {
            return 0;
          }
          floatStateValue = (double)*(float *)(glContext + 0x33ac);
        }
      }
    }
    else {
      if (pname == 0x80f0) {
        scalarResult = *(uint *)(glContext + 0x5080);
        goto LAB_00015f48;
      }
      if (pname < 0x80f1) {
        if (pname == 0x80b8) {
          floatStateValue = (double)*(float *)(glContext + 0x3360);
        }
        else if (pname < 0x80b9) {
          if (pname == 0x80b1) {
            matrixPtr = glContext + 0x1c40;
            goto LAB_00014c84;
          }
          if (pname < 0x80b2) {
            if (pname == 0x80a9) {
              scalarResult = *(uint *)(*(int *)(glContext + 0x468c) + 0x5c);
              goto LAB_00015f48;
            }
            if (pname < 0x80aa) {
              if (pname == 0x80a0) {
                scalarResult = (uint)*(byte *)(glContext + 0x41f3);
              }
              else {
                if (pname != 0x80a8) {
                  return 0;
                }
                scalarResult = *(uint *)(*(int *)(glContext + 0x468c) + 0x58);
              }
              goto LAB_00015f48;
            }
            if (pname != 0x80aa) {
              if (pname != 0x80ab) {
                return 0;
              }
              scalarResult = (uint)*(byte *)(glContext + 0x41f4);
              goto LAB_00015f48;
            }
            floatStateValue = (double)*(float *)(glContext + 0x41ec);
          }
          else if (pname == 0x80b4) {
            floatStateValue = (double)*(float *)(glContext + 0x335c);
          }
          else {
            if (pname < 0x80b5) {
              if (pname != 0x80b2) {
                if (pname != 0x80b3) {
                  return 0;
                }
                scalarResult = 5;
                goto LAB_00015f48;
              }
              iVar13 = *(int *)(glContext + 0x5004);
              goto LAB_00014bf4;
            }
            if (pname == 0x80b6) {
              floatStateValue = (double)*(float *)(glContext + 0x336c);
            }
            else if (pname < 0x80b7) {
              floatStateValue = (double)*(float *)(glContext + 0x3364);
            }
            else {
              floatStateValue = (double)*(float *)(glContext + 0x3374);
            }
          }
        }
        else {
          if (pname == 0x80ca) {
            scalarResult = (uint)*(ushort *)(glContext + 0x30ce);
            goto LAB_00015f48;
          }
          if (0x80ca < pname) {
            if (pname == 0x80d1) {
              scalarResult = *(uint *)(glContext + 0x3410) >> 6 & 1;
            }
            else if (pname < 0x80d2) {
              if (pname == 0x80cb) {
                scalarResult = (uint)*(ushort *)(glContext + 0x30cc);
              }
              else {
                if (pname != 0x80d0) {
                  return 0;
                }
                scalarResult = *(uint *)(glContext + 0x3410) >> 5 & 1;
              }
            }
            else if (pname == 33000) {
              scalarResult = *(uint *)(*(int *)(glContext + 0x468c) + 0x88);
            }
            else if (pname < 0x80e9) {
              if (pname != 0x80d2) {
                return 0;
              }
              scalarResult = *(uint *)(glContext + 0x3410) >> 7 & 1;
            }
            else {
              if (pname != 0x80e9) {
                return 0;
              }
              scalarResult = 150000;
            }
            goto LAB_00015f48;
          }
          if (pname == 0x80bb) {
            floatStateValue = (double)*(float *)(glContext + 0x3378);
          }
          else {
            if (0x80bb < pname) {
              if (pname != 0x80c8) {
                if (pname != 0x80c9) {
                  return 0;
                }
                goto LAB_00014d8c;
              }
              goto LAB_00014d84;
            }
            if (pname == 0x80b9) {
              floatStateValue = (double)*(float *)(glContext + 0x3368);
            }
            else {
              if (pname != 0x80ba) {
                return 0;
              }
              floatStateValue = (double)*(float *)(glContext + 0x3370);
            }
          }
        }
      }
      else if (pname == 0x8453) {
        floatStateValue = (double)*(float *)(glContext + 0x2cc);
      }
      else {
        if (0x8453 < pname) {
          if (pname == 0x845b) {
            scalarResult = *(ushort *)(*(int *)(glContext + 0x4a60) + 0x98) & 0xffff7fff;
          }
          else if (pname < 0x845c) {
            if (pname == 0x8457) {
              scalarResult = *(uint *)(*(int *)(glContext + 0x4a60) + 0x334) >> 0x13 & 1;
            }
            else if (pname < 0x8458) {
              if (pname == 0x8454) {
                scalarResult = (uint)*(ushort *)(*(int *)(glContext + 0x4a60) + 0x80);
              }
              else {
                if (pname != 0x8455) {
                  return 0;
                }
                scalarResult = *(uint *)(*(int *)(glContext + 0x4a60) + 0x7c);
              }
            }
            else {
              if (pname == 0x8459) {
                valueCount = 4;
                *values = (double)*(float *)(glContext + 0x2c0);
                values[1] = (double)*(float *)(glContext + 0x2c4);
                glContextFloat2c8 = *(float *)(glContext + 0x2c8);
                *(uint *)(values + 3) = 0x3ff00000;
                *(uint *)((int)values + 0x1c) = 0;
                values[2] = (double)glContextFloat2c8;
                goto LAB_00015a90;
              }
              if (pname != 0x845a) {
                return 0;
              }
              scalarResult = (uint)*(short *)(*(int *)(glContext + 0x4a60) + 0x9a);
            }
          }
          else {
            if (pname == 0x846d) {
              scalarResult = (uint)(int)*(float *)(*(int *)(glContext + 0x468c) + 0x60);
              *(uint *)values = scalarResult;
              rangeMax = *(float *)(*(int *)(glContext + 0x468c) + 100);
LAB_00014828:
              *(int *)(values + 1) = (int)rangeMax;
              if (scalarResult == 0) {
                *(uint *)values = 1;
              }
              return 2;
            }
            if (0x846d < pname) {
              if (pname == 0x84e0) {
                iVar13 = *(int *)(glContext + 0x53d4);
              }
              else {
                if (pname < 0x84e1) {
                  if (pname != 0x846e) {
                    return 0;
                  }
                  scalarResult = (uint)(int)*(float *)(*(int *)(glContext + 0x468c) + 0x6c);
                  *(uint *)values = scalarResult;
                  rangeMax = *(float *)(*(int *)(glContext + 0x468c) + 0x70);
                  goto LAB_00014828;
                }
                iVar13 = *(int *)(glContext + 0x53d8);
              }
              scalarResult = iVar13 + 0x84c0;
              goto LAB_00015efc;
            }
            if (pname == 0x845c) {
              scalarResult = *(uint *)(*(int *)(glContext + 0x4a60) + 0x94);
            }
            else {
              if (pname != 0x845e) {
                return 0;
              }
              scalarResult = *(uint *)(*(int *)(glContext + 0x4a60) + 0x334) >> 0x14 & 1;
            }
          }
          goto LAB_00015f48;
        }
        if (pname == 0x81a8) {
          scalarResult = *(uint *)(glContext + 0x4984);
          goto LAB_00015f48;
        }
        if (0x81a8 < pname) {
          if (pname == 0x81fb) {
            scalarResult = *(uint *)(*(int *)(glContext + 0x53d4) * 0x7c + glContext + 0x3534) >> 8 & 1;
            goto LAB_00015f48;
          }
          if (pname < 0x81fc) {
            if (pname == 0x81a9) {
              scalarResult = *(uint *)(glContext + 0x4988);
            }
            else {
              if (pname != 0x81f8) {
                return 0;
              }
              scalarResult = (uint)*(ushort *)(glContext + 0x30a8);
            }
            goto LAB_00015f48;
          }
          if (pname != 0x8406) {
            if (pname < 0x8407) {
              if (pname != 0x8200) {
                return 0;
              }
              scalarResult = (uint)*(byte *)(glContext + 0x466c);
            }
            else {
              if (pname != 0x8450) {
                return 0;
              }
              scalarResult = (uint)*(ushort *)(glContext + 0x3166);
            }
            goto LAB_00015f48;
          }
          glContextPtr4854 = *(int *)(glContext + 0x4854);
          *values = (double)*(float *)(glContextPtr4854 + -0x1c0);
          values[1] = (double)*(float *)(glContextPtr4854 + -0x1bc);
          floatStateValueB = *(float *)(glContextPtr4854 + -0x1b8);
LAB_00015d40:
          valueCount = 3;
          values[2] = (double)floatStateValueB;
          goto LAB_00015d48;
        }
        if (pname == 0x8128) {
          floatStateValue = (double)*(float *)(glContext + 0x3428);
        }
        else {
          if (0x8128 < pname) {
            if (pname != 0x8129) {
              if (pname != 0x8192) {
                return 0;
              }
              scalarResult = (uint)*(ushort *)(glContext + 0x3178);
              goto LAB_00015f48;
            }
            *values = (double)*(float *)(glContext + 0x342c);
            values[1] = (double)*(float *)(glContext + 0x3430);
            floatStateValueB = *(float *)(glContext + 0x3434);
            goto LAB_00015d40;
          }
          if (pname == 0x8126) {
            floatStateValue = (double)*(float *)(glContext + 0x3420);
          }
          else {
            if (pname != 0x8127) {
              return 0;
            }
            floatStateValue = (double)*(float *)(glContext + 0x3424);
          }
        }
      }
    }
    goto LAB_0001467c;
  }
  if (pname == 0xc61) {
    if (7 < *(int *)(glContext + 0x53d4)) {
      return -1;
    }
    scalarResult = (uint)*(byte *)(*(int *)(glContext + 0x53d4) * 0x94 + glContext + 0x3d79);
    goto LAB_00015f48;
  }
  if (0xc61 < pname) {
    if (pname == 0xd3b) {
      scalarResult = 0x10;
      goto LAB_00015f48;
    }
    if (pname < 0xd3c) {
      if (pname == 0xd11) {
        scalarResult = *(uint *)(glContext + 0x3414) >> 1 & 1;
        goto LAB_00015f48;
      }
      if (pname < 0xd12) {
        if (pname == 0xcf0) {
          scalarResult = (uint)*(byte *)(glContext + 0x31e4);
        }
        else if (pname < 0xcf1) {
          if (pname == 0xcb3) {
            scalarResult = *(uint *)(glContext + 0x327c);
          }
          else if (pname < 0xcb4) {
            if (pname == 0xcb0) {
              scalarResult = *(uint *)(glContext + 0x3270);
            }
            else if (pname < 0xcb1) {
              if (pname == 0xc62) {
                if (7 < *(int *)(glContext + 0x53d4)) {
                  return -1;
                }
                scalarResult = (uint)*(byte *)(*(int *)(glContext + 0x53d4) * 0x94 + glContext + 0x3d7a);
              }
              else {
                if (pname != 0xc63) {
                  return 0;
                }
                if (7 < *(int *)(glContext + 0x53d4)) {
                  return -1;
                }
                scalarResult = (uint)*(byte *)(*(int *)(glContext + 0x53d4) * 0x94 + glContext + 0x3d7b);
              }
            }
            else if (pname == 0xcb1) {
              scalarResult = *(uint *)(glContext + 0x3274);
            }
            else {
              if (pname != 0xcb2) {
                return 0;
              }
              scalarResult = *(uint *)(glContext + 0x3278);
            }
          }
          else if (pname == 0xcb6) {
            scalarResult = *(uint *)(glContext + 0x3288);
          }
          else if (pname < 0xcb7) {
            if (pname == 0xcb4) {
              scalarResult = *(uint *)(glContext + 0x3280);
            }
            else {
              if (pname != 0xcb5) {
                return 0;
              }
              scalarResult = *(uint *)(glContext + 0x3284);
            }
          }
          else if (pname == 0xcb8) {
            scalarResult = *(uint *)(glContext + 0x3290);
          }
          else if (pname < 0xcb8) {
            scalarResult = *(uint *)(glContext + 0x328c);
          }
          else {
            if (pname != 0xcb9) {
              return 0;
            }
            scalarResult = *(uint *)(glContext + 0x3294);
          }
        }
        else if (pname == 0xd00) {
          scalarResult = (uint)*(byte *)(glContext + 0x31c8);
        }
        else if (pname < 0xd01) {
          if (pname == 0xcf3) {
            scalarResult = *(uint *)(glContext + 0x31d4);
          }
          else if (pname < 0xcf4) {
            if (pname == 0xcf1) {
              scalarResult = (uint)*(byte *)(glContext + 0x31e5);
            }
            else {
              if (pname != 0xcf2) {
                return 0;
              }
              scalarResult = *(uint *)(glContext + 0x31cc);
            }
          }
          else if (pname == 0xcf4) {
            scalarResult = *(uint *)(glContext + 0x31d8);
          }
          else {
            if (pname != 0xcf5) {
              return 0;
            }
            scalarResult = *(uint *)(glContext + 0x31e0);
          }
        }
        else if (pname == 0xd03) {
          scalarResult = *(uint *)(glContext + 0x31b8);
        }
        else if (pname < 0xd04) {
          if (pname == 0xd01) {
            scalarResult = (uint)*(byte *)(glContext + 0x31c9);
          }
          else {
            if (pname != 0xd02) {
              return 0;
            }
            scalarResult = *(uint *)(glContext + 0x31b0);
          }
        }
        else if (pname == 0xd05) {
          scalarResult = *(uint *)(glContext + 0x31c4);
        }
        else if (pname < 0xd05) {
          scalarResult = *(uint *)(glContext + 0x31bc);
        }
        else {
          if (pname != 0xd10) {
            return 0;
          }
          scalarResult = *(uint *)(glContext + 0x3414) & 1;
        }
        goto LAB_00015f48;
      }
      if (pname == 0xd1e) {
        floatStateValue = (double)*(float *)(glContext + 0x320c);
      }
      else if (pname < 0xd1f) {
        if (pname == 0xd17) {
          floatStateValue = (double)*(float *)(glContext + 0x31ac);
        }
        else if (pname < 0xd18) {
          if (pname == 0xd14) {
            floatStateValue = (double)*(float *)(glContext + 0x31ec);
          }
          else {
            if (pname < 0xd15) {
              if (pname == 0xd12) {
                scalarResult = *(uint *)(glContext + 0x3214);
              }
              else {
                if (pname != 0xd13) {
                  return 0;
                }
                scalarResult = *(uint *)(glContext + 0x3210);
              }
              goto LAB_00015f48;
            }
            if (pname == 0xd15) {
              floatStateValue = (double)*(float *)(glContext + 0x31e8);
            }
            else {
              if (pname != 0xd16) {
                return 0;
              }
              floatStateValue = (double)*(float *)(glContext + 0x31a8);
            }
          }
        }
        else if (pname == 0xd1a) {
          floatStateValue = (double)*(float *)(glContext + 0x31fc);
        }
        else if (pname < 0xd1b) {
          if (pname == 0xd18) {
            floatStateValue = (double)*(float *)(glContext + 0x31f4);
          }
          else {
            if (pname != 0xd19) {
              return 0;
            }
            floatStateValue = (double)*(float *)(glContext + 0x31f0);
          }
        }
        else if (pname == 0xd1c) {
          floatStateValue = (double)*(float *)(glContext + 0x3204);
        }
        else if (pname < 0xd1d) {
          floatStateValue = (double)*(float *)(glContext + 0x31f8);
        }
        else {
          floatStateValue = (double)*(float *)(glContext + 0x3200);
        }
      }
      else {
        if (pname == 0xd34) {
          scalarResult = 0x100;
          goto LAB_00015f48;
        }
        if (0xd34 < pname) {
          if (pname == 0xd37) {
            scalarResult = 100;
          }
          else if (pname < 0xd38) {
            if (pname == 0xd35) {
              scalarResult = 0x10;
            }
            else {
              if (pname != 0xd36) {
                return 0;
              }
              scalarResult = 0x20;
            }
          }
          else if (pname == 0xd39) {
            scalarResult = 5;
          }
          else {
            if (0xd39 < pname) {
              *(uint *)values = *(uint *)(*(int *)(glContext + 0x468c) + 0xc);
              scalarResult = *(uint *)(*(int *)(glContext + 0x468c) + 0x10);
              goto LAB_00015638;
            }
            scalarResult = 5;
          }
          goto LAB_00015f48;
        }
        if (pname == 0xd31) {
          scalarResult = 8;
          goto LAB_00015f48;
        }
        if (0xd31 < pname) {
          if (pname == 0xd32) {
            scalarResult = 6;
          }
          else {
            if (pname != 0xd33) {
              return 0;
            }
            scalarResult = (uint)*(ushort *)(*(int *)(glContext + 0x468c) + 0xbc);
          }
          goto LAB_00015f48;
        }
        if (pname != 0xd1f) {
          if (pname != 0xd30) {
            return 0;
          }
          scalarResult = 10;
          goto LAB_00015f48;
        }
        floatStateValue = (double)*(float *)(glContext + 0x3208);
      }
    }
    else {
      if (pname == 0xdb2) {
        scalarResult = (uint)*(byte *)(glContext + 0x74ed);
        goto LAB_00015f48;
      }
      if (pname < 0xdb3) {
        if (pname == 0xd70) {
          scalarResult = (*(int *)(glContext + 0x4fbc) - glContext) + -0x4e2c >> 2;
          goto LAB_00015efc;
        }
        if (0xd70 < pname) {
          if (pname == 0xd94) {
            scalarResult = (uint)*(byte *)(glContext + 0x74e6);
          }
          else if (pname < 0xd95) {
            if (pname == 0xd91) {
              scalarResult = (uint)*(byte *)(glContext + 0x74e3);
            }
            else if (pname < 0xd92) {
              if (pname == 0xd80) {
                scalarResult = (uint)*(byte *)(glContext + 0x74f2);
              }
              else {
                if (pname != 0xd90) {
                  return 0;
                }
                scalarResult = (uint)*(byte *)(glContext + 0x74e2);
              }
            }
            else if (pname == 0xd92) {
              scalarResult = (uint)*(byte *)(glContext + 0x74e4);
            }
            else {
              if (pname != 0xd93) {
                return 0;
              }
              scalarResult = (uint)*(byte *)(glContext + 0x74e5);
            }
          }
          else if (pname == 0xd97) {
            scalarResult = (uint)*(byte *)(glContext + 0x74e0);
          }
          else if (pname < 0xd98) {
            if (pname == 0xd95) {
              scalarResult = (uint)*(byte *)(glContext + 0x74e7);
            }
            else {
              if (pname != 0xd96) {
                return 0;
              }
              scalarResult = (uint)*(byte *)(glContext + 0x74e8);
            }
          }
          else if (pname == 0xdb0) {
            scalarResult = (uint)*(byte *)(glContext + 0x74eb);
          }
          else if (pname < 0xdb1) {
            if (pname != 0xd98) {
              return 0;
            }
            scalarResult = (uint)*(byte *)(glContext + 0x74e1);
          }
          else {
            scalarResult = (uint)*(byte *)(glContext + 0x74ec);
          }
          goto LAB_00015f48;
        }
        if (pname == 0xd55) {
          framebufferObject = *(int *)(glContext + 0x744c);
          if (framebufferObject == 0) {
            scalarResult = *(uint *)(*(int *)(glContext + 0x468c) + 0x38);
            goto LAB_00015f48;
          }
          attachmentIndexThenBody = 0;
          srcCursor = (int *)(framebufferObject + 0xd4);
          do {
            attachmentObject = *srcCursor;
            srcCursor = srcCursor + 1;
            if (attachmentObject != 0) break;
            attachmentIndexThenBody = attachmentIndexThenBody + 1;
          } while (attachmentIndexThenBody < 4);
          scalarResult = 0;
          if (attachmentIndexThenBody == 4) goto LAB_00015f48;
          attachmentRecord = attachmentIndexThenBody * 0x18 + framebufferObject;
          attachmentIndexThenBody = *(int *)(attachmentIndexThenBody * 4 + framebufferObject + 0xd4) + 0x10;
          attachmentParamB = *(undefined4 *)(attachmentRecord + 0x38);
          iVar13 = (uint)*(byte *)(glContext + 0x85a8) << 2;
          sizeQueryEnum = 0x805f;
        }
        else {
          if (0xd55 < pname) {
            if (pname == 0xd58) {
              scalarResult = *(uint *)(*(int *)(glContext + 0x468c) + 0x44);
              goto LAB_00015f48;
            }
            if (0xd58 < pname) {
              if (pname == 0xd5a) {
                scalarResult = *(uint *)(*(int *)(glContext + 0x468c) + 0x4c);
              }
              else if (pname < 0xd5a) {
                scalarResult = *(uint *)(*(int *)(glContext + 0x468c) + 0x48);
              }
              else {
                if (pname != 0xd5b) {
                  return 0;
                }
                scalarResult = *(uint *)(*(int *)(glContext + 0x468c) + 0x50);
              }
              goto LAB_00015f48;
            }
            if (pname != 0xd56) {
              if (pname != 0xd57) {
                return 0;
              }
              framebufferObject = *(int *)(glContext + 0x744c);
              if (framebufferObject == 0) {
                scalarResult = *(uint *)(*(int *)(glContext + 0x468c) + 0x40);
                goto LAB_00015f48;
              }
              scalarResult = 0;
              if (*(int *)(framebufferObject + 0xe8) == 0) goto LAB_00015450;
              glContextPtr479c = *(code **)(glContext + 0x479c);
              attachmentParamB = *(undefined4 *)(framebufferObject + 0xb0);
              rendererTextureName = *(undefined4 *)
                       (*(int *)(framebufferObject + 0xe8) + 0x10 + (uint)*(byte *)(glContext + 0x85a8) * 4);
              sizeQueryEnum = 0x884a;
              glContextWord4688 = *(undefined4 *)(glContext + 0x4688);
              attachmentParamA = *(undefined4 *)(framebufferObject + 0xac);
              goto LAB_00015488;
            }
            framebufferObject = *(int *)(glContext + 0x744c);
            if (framebufferObject == 0) {
              scalarResult = *(uint *)(*(int *)(glContext + 0x468c) + 0x3c);
              goto LAB_00015f48;
            }
            scalarResult = 0;
            if (*(int *)(framebufferObject + 0xe4) != 0) {
              glContextPtr479c = *(code **)(glContext + 0x479c);
              attachmentParamB = *(undefined4 *)(framebufferObject + 0x98);
              rendererTextureName = *(undefined4 *)
                       (*(int *)(framebufferObject + 0xe4) + 0x10 + (uint)*(byte *)(glContext + 0x85a8) * 4);
              sizeQueryEnum = 0x884a;
              glContextWord4688 = *(undefined4 *)(glContext + 0x4688);
              attachmentParamA = *(undefined4 *)(framebufferObject + 0x94);
              goto LAB_00015488;
            }
            goto LAB_00015450;
          }
          if (pname == 0xd52) {
            framebufferObject = *(int *)(glContext + 0x744c);
            if (framebufferObject == 0) {
              scalarResult = *(uint *)(*(int *)(glContext + 0x468c) + 0x2c);
              goto LAB_00015f48;
            }
            attachmentIndexThenBody = 0;
            srcCursor = (int *)(framebufferObject + 0xd4);
            do {
              attachmentObject = *srcCursor;
              srcCursor = srcCursor + 1;
              if (attachmentObject != 0) break;
              attachmentIndexThenBody = attachmentIndexThenBody + 1;
            } while (attachmentIndexThenBody < 4);
            scalarResult = 0;
            if (attachmentIndexThenBody == 4) goto LAB_00015f48;
            attachmentRecord = attachmentIndexThenBody * 0x18 + framebufferObject;
            attachmentIndexThenBody = *(int *)(attachmentIndexThenBody * 4 + framebufferObject + 0xd4) + 0x10;
            attachmentParamB = *(undefined4 *)(attachmentRecord + 0x38);
            iVar13 = (uint)*(byte *)(glContext + 0x85a8) << 2;
            sizeQueryEnum = 0x805c;
          }
          else {
            if (pname < 0xd53) {
              if (pname == 0xd50) {
                scalarResult = *(uint *)(*(int *)(glContext + 0x468c) + 8);
              }
              else {
                if (pname != 0xd51) {
                  return 0;
                }
                scalarResult = *(uint *)(*(int *)(glContext + 0x468c) + 0x28);
              }
              goto LAB_00015f48;
            }
            if (pname == 0xd53) {
              framebufferObject = *(int *)(glContext + 0x744c);
              if (framebufferObject == 0) {
                scalarResult = *(uint *)(*(int *)(glContext + 0x468c) + 0x30);
                goto LAB_00015f48;
              }
              attachmentIndexThenBody = 0;
              srcCursor = (int *)(framebufferObject + 0xd4);
              do {
                attachmentObject = *srcCursor;
                srcCursor = srcCursor + 1;
                if (attachmentObject != 0) break;
                attachmentIndexThenBody = attachmentIndexThenBody + 1;
              } while (attachmentIndexThenBody < 4);
              scalarResult = 0;
              if (attachmentIndexThenBody == 4) goto LAB_00015f48;
              attachmentRecord = attachmentIndexThenBody * 0x18 + framebufferObject;
              attachmentIndexThenBody = *(int *)(attachmentIndexThenBody * 4 + framebufferObject + 0xd4) + 0x10;
              attachmentParamB = *(undefined4 *)(attachmentRecord + 0x38);
              iVar13 = (uint)*(byte *)(glContext + 0x85a8) << 2;
              sizeQueryEnum = 0x805d;
            }
            else {
              if (pname != 0xd54) {
                return 0;
              }
              framebufferObject = *(int *)(glContext + 0x744c);
              if (framebufferObject == 0) {
                scalarResult = *(uint *)(*(int *)(glContext + 0x468c) + 0x34);
                goto LAB_00015f48;
              }
              attachmentIndexThenBody = 0;
              srcCursor = (int *)(framebufferObject + 0xd4);
              do {
                attachmentObject = *srcCursor;
                srcCursor = srcCursor + 1;
                if (attachmentObject != 0) break;
                attachmentIndexThenBody = attachmentIndexThenBody + 1;
              } while (attachmentIndexThenBody < 4);
              scalarResult = 0;
              if (attachmentIndexThenBody == 4) goto LAB_00015f48;
              attachmentRecord = attachmentIndexThenBody * 0x18 + framebufferObject;
              attachmentIndexThenBody = *(int *)(attachmentIndexThenBody * 4 + framebufferObject + 0xd4) + 0x10;
              attachmentParamB = *(undefined4 *)(attachmentRecord + 0x38);
              iVar13 = (uint)*(byte *)(glContext + 0x85a8) << 2;
              sizeQueryEnum = 0x805e;
            }
          }
        }
        rendererTextureName = *(undefined4 *)(attachmentIndexThenBody + iVar13);
        glContextPtr479c = *(code **)(glContext + 0x479c);
        glContextWord4688 = *(undefined4 *)(glContext + 0x4688);
        attachmentParamA = *(undefined4 *)(attachmentRecord + 0x34);
LAB_00015488:
        (*glContextPtr479c)(glContextWord4688,rendererTextureName,attachmentParamA,attachmentParamB,sizeQueryEnum,values);
        return 1;
      }
      if (pname == 0xdf1) {
        scalarResult = *(uint *)(glContext + 0x4fd4);
        goto LAB_00015f48;
      }
      if (pname < 0xdf2) {
        if (pname == 0xdb8) {
          scalarResult = (uint)*(byte *)(glContext + 0x74ea);
          goto LAB_00015f48;
        }
        if (pname < 0xdb9) {
          if (pname == 0xdb5) {
            scalarResult = (uint)*(byte *)(glContext + 0x74f0);
          }
          else if (pname < 0xdb6) {
            if (pname == 0xdb3) {
              scalarResult = (uint)*(byte *)(glContext + 0x74ee);
            }
            else {
              if (pname != 0xdb4) {
                return 0;
              }
              scalarResult = (uint)*(byte *)(glContext + 0x74ef);
            }
          }
          else if (pname == 0xdb6) {
            scalarResult = (uint)*(byte *)(glContext + 0x74f1);
          }
          else {
            if (pname != 0xdb7) {
              return 0;
            }
            scalarResult = (uint)*(byte *)(glContext + 0x74e9);
          }
          goto LAB_00015f48;
        }
        if (pname == 0xdd2) {
          *values = (double)*(float *)(glContext + 0x74bc);
          values[1] = (double)*(float *)(glContext + 0x74c0);
          values[2] = (double)*(float *)(glContext + 0x74cc);
          fourthComponent2 = (double)*(float *)(glContext + 0x74d0);
          goto LAB_00014704;
        }
        if (0xdd2 < pname) {
          if (pname == 0xde0) {
            scalarResult = *(uint *)(*(int *)(glContext + 0x53d4) * 0x7c + glContext + 0x3534) >> 4 & 1;
            goto LAB_00015f48;
          }
          if (0xde0 < pname) {
            if (pname != 0xde1) {
              return 0;
            }
            scalarResult = *(uint *)(*(int *)(glContext + 0x53d4) * 0x7c + glContext + 0x3534) >> 3 & 1;
            goto LAB_00015f48;
          }
          if (pname != 0xdd3) {
            return 0;
          }
          *values = (double)CONCAT44(0x43300000,*(uint *)(glContext + 0x74b8) ^ 0x80000000) -
                     DOUBLE_00108d58;
          intToDoubleMagicThenValue = (double)CONCAT44(0x43300000,*(uint *)(glContext + 0x74c8) ^ 0x80000000) - intToDoubleMagicThenValue;
          goto LAB_00014860;
        }
        if (pname == 0xdd0) {
          *values = (double)*(float *)(glContext + 0x74ac);
          secondValue = (double)*(float *)(glContext + 0x74b0);
          goto LAB_00015cf4;
        }
        if (pname != 0xdd1) {
          return 0;
        }
        floatStateValue = (double)CONCAT44(0x43300000,
                                  *(uint *)(0x74a4 + glContext + 4) ^ 0x80000000) -
                 DOUBLE_00108d58;
      }
      else {
        if (pname == 0x2a02) {
          scalarResult = (uint)*(byte *)(glContext + 0x34dc);
          goto LAB_00015f48;
        }
        if (0x2a02 < pname) {
          if (pname < 0x4008) {
            if (pname < 0x4000) {
              if (5 < pname - 0x3000) {
                return 0;
              }
              scalarResult = *(uint *)(glContext + 0x4188) >> (pname - 0x3000 & 0x3f) & 1;
            }
            else {
              scalarResult = *(uint *)(glContext + 0x30a0) >> (pname - 0x4000 & 0x3f) & 1;
            }
          }
          else if (pname == 0x6090) {
            scalarResult = (uint)*(byte *)(glContext + 0x280c);
          }
          else {
            if (pname != 0x6091) {
              return 0;
            }
            scalarResult = *(uint *)(*(int *)(glContext + 0x468c) + 0x9c);
          }
          goto LAB_00015f48;
        }
        if (pname == 0x1700) {
LAB_00014c74:
          matrixPtr = glContext + 0x1cc0;
          goto LAB_00014c84;
        }
        if (pname < 0x1701) {
          if (pname == 0xdf2) {
            scalarResult = *(uint *)(glContext + 0x4fd8);
          }
          else {
            if (pname != 0xdf4) {
              return 0;
            }
            scalarResult = *(uint *)(glContext + 0x4e28);
          }
          goto LAB_00015f48;
        }
        if (pname != 0x2a00) {
          if (pname != 0x2a01) {
            return 0;
          }
          scalarResult = (uint)*(byte *)(glContext + 0x34db);
          goto LAB_00015f48;
        }
        floatStateValue = (double)*(float *)(glContext + 0x34cc);
      }
    }
    goto LAB_0001467c;
  }
  if (pname == 0xb74) {
    scalarResult = (uint)*(ushort *)(glContext + 0x3124);
    goto LAB_00015f48;
  }
  if (pname < 0xb75) {
    if (pname == 0xb40) {
      *(uint *)values = (uint)*(ushort *)(glContext + 0x34d0);
      scalarResult = (uint)*(ushort *)(glContext + 0x34d2);
LAB_00015638:
      *(uint *)(values + 1) = scalarResult;
      return 2;
    }
    if (pname < 0xb41) {
      if (pname == 0xb12) {
        *values = (double)*(float *)(*(int *)(glContext + 0x468c) + 0x60);
        intToDoubleMagicThenValue = (double)*(float *)(*(int *)(glContext + 0x468c) + 100);
LAB_00014860:
        valueCount = 2;
        values[1] = intToDoubleMagicThenValue;
        goto LAB_00015d48;
      }
      if (0xb12 < pname) {
        if (pname == 0xb24) {
          scalarResult = (uint)*(byte *)(glContext + 0x318c);
          goto LAB_00015f48;
        }
        if (0xb24 < pname) {
          if (pname == 0xb30) {
            scalarResult = *(uint *)(glContext + 0x5408);
          }
          else if (pname < 0xb31) {
            if (pname == 0xb25) {
              scalarResult = (uint)*(ushort *)(glContext + 0x3188);
            }
            else {
              if (pname != 0xb26) {
                return 0;
              }
              scalarResult = *(uint *)(glContext + 0x3184);
            }
          }
          else if (pname == 0xb32) {
            scalarResult = *(uint *)(glContext + 0x5404);
          }
          else {
            scalarResult = 0x40;
            if (0xb31 < pname) {
              if (pname != 0xb33) {
                return 0;
              }
              scalarResult = 0;
              if (*(int *)(glContext + 0x5408) != 0) {
                scalarResult = *(uint *)(*(int *)(glContext + 0x53e8) + 4);
              }
            }
          }
          goto LAB_00015f48;
        }
        if (pname == 0xb21) {
          scalarResult = (uint)(int)*(float *)(glContext + 0x3180);
          goto LAB_00015f48;
        }
        if (pname < 0xb22) {
          if (pname != 0xb13) {
            if (pname != 0xb20) {
              return 0;
            }
            scalarResult = (uint)*(byte *)(glContext + 0x318d);
            goto LAB_00015f48;
          }
          floatStateValue = (double)*(float *)(*(int *)(glContext + 0x468c) + 0x68);
        }
        else {
          if (pname == 0xb22) {
            *values = (double)*(float *)(*(int *)(glContext + 0x468c) + 0x6c);
            intToDoubleMagicThenValue = (double)*(float *)(*(int *)(glContext + 0x468c) + 0x70);
            goto LAB_00014860;
          }
          if (pname != 0xb23) {
            return 0;
          }
          floatStateValue = (double)*(float *)(*(int *)(glContext + 0x468c) + 0x74);
        }
        goto LAB_0001467c;
      }
      if (pname == 0xb05) {
        *(uint *)values = 0x3ff00000;
        *(uint *)((int)values + 4) = 0;
        goto LAB_00015d48;
      }
      if (0xb05 < pname) {
        if (pname == 0xb08) {
          scalarResult = (uint)*(byte *)(glContext + 0x2ef);
          goto LAB_00015f48;
        }
        if (0xb08 < pname) {
          if (pname == 0xb10) {
            scalarResult = (uint)*(byte *)(glContext + 0x343c);
            goto LAB_00015f48;
          }
          if (0xb10 < pname) {
            scalarResult = (uint)(int)*(float *)(glContext + 0x341c);
            goto LAB_00015f48;
          }
          if (pname != 0xb09) {
            return 0;
          }
          floatStateValue = (double)*(float *)(*(int *)(glContext + 0x4854) + -0x1d8);
          goto LAB_0001467c;
        }
        if (pname == 0xb06) {
          if (7 < *(int *)(glContext + 0x53d4)) {
            return -1;
          }
          iVar13 = *(int *)(glContext + 0x53d4) * 0x10 + *(int *)(glContext + 0x4854) + -0x200;
          *values = (double)*(float *)(iVar13 + 0x80);
          values[1] = (double)*(float *)(iVar13 + 0x84);
          values[2] = (double)*(float *)(iVar13 + 0x88);
          fourthComponent2 = (double)*(float *)(iVar13 + 0x8c);
        }
        else {
          if (pname != 0xb07) {
            return 0;
          }
          glContextPtr4854 = *(int *)(glContext + 0x4854);
          *values = (double)*(float *)(glContext + 0x2e0);
          values[1] = (double)*(float *)(glContext + 0x2e4);
          values[2] = (double)*(float *)(glContext + 0x2e8);
          fourthComponent2 = (double)*(float *)(glContextPtr4854 + -0x1e4);
        }
LAB_00014704:
        valueCount = 4;
        values[3] = fourthComponent2;
        goto LAB_00015d48;
      }
      if (pname == 0xb02) {
        valueCount = 3;
        *values = (double)*(float *)(glContext + 0x2b0);
        values[1] = (double)*(float *)(glContext + 0x2b4);
        values[2] = (double)*(float *)(glContext + 0x2b8);
        goto LAB_00015a90;
      }
      if (pname < 0xb03) {
        if (pname != 0xb00) {
          if (pname != 0xb01) {
            return 0;
          }
          floatStateValue = (double)*(float *)(glContext + 700);
          goto LAB_00014670;
        }
        *values = (double)*(float *)(glContext + 0x2a0);
        values[1] = (double)*(float *)(glContext + 0x2a4);
        values[2] = (double)*(float *)(glContext + 0x2a8);
        fourthComponent = (double)*(float *)(glContext + 0x2ac);
      }
      else {
        if (pname == 0xb03) {
          if (7 < *(int *)(glContext + 0x53d4)) {
            return -1;
          }
          iVar13 = *(int *)(glContext + 0x53d4) * 0x10 + glContext;
          *values = (double)*(float *)(iVar13 + 0x120);
          values[1] = (double)*(float *)(iVar13 + 0x124);
          values[2] = (double)*(float *)(iVar13 + 0x128);
          fourthComponent2 = (double)*(float *)(iVar13 + 300);
          goto LAB_00014704;
        }
        if (pname != 0xb04) {
          return 0;
        }
        glContextPtr4854 = *(int *)(glContext + 0x4854);
        *values = (double)*(float *)(glContextPtr4854 + -0x1d0);
        values[1] = (double)*(float *)(glContextPtr4854 + -0x1cc);
        values[2] = (double)*(float *)(glContextPtr4854 + -0x1c8);
        fourthComponent = (double)*(float *)(glContextPtr4854 + -0x1c4);
      }
    }
    else {
      if (pname == 0xb56) {
        scalarResult = (uint)*(ushort *)(glContext + 0x30a6);
        goto LAB_00015f48;
      }
      if (0xb56 < pname) {
        if (pname == 0xb64) {
          floatStateValue = (double)*(float *)(glContext + 0x3158);
        }
        else {
          if (0xb64 < pname) {
            if (pname == 0xb70) {
              *values = *(double *)(glContext + 0x1b90);
              values[1] = *(double *)(glContext + 0x1b98);
              *valueType = 0x140a;
              *param_5 = 1;
              return 2;
            }
            if (0xb70 < pname) {
              if (pname == 0xb72) {
                scalarResult = (uint)*(byte *)(glContext + 0x31a4);
                goto LAB_00015f48;
              }
              if (pname < 0xb73) {
                scalarResult = (uint)*(byte *)(glContext + 0x3128);
                goto LAB_00015f48;
              }
              doubleStateValue = *(double *)(glContext + 0x30e8);
              goto LAB_00014d74;
            }
            if (pname == 0xb65) {
              scalarResult = (uint)*(ushort *)(glContext + 0x3164);
              goto LAB_00015f48;
            }
            if (pname != 0xb66) {
              return 0;
            }
            *values = (double)*(float *)(glContext + 0x3140);
            values[1] = (double)*(float *)(glContext + 0x3144);
            values[2] = (double)*(float *)(glContext + 0x3148);
            fourthComponent = (double)*(float *)(glContext + 0x314c);
            goto LAB_00015a8c;
          }
          if (pname == 0xb61) {
            floatStateValue = (double)*(float *)(glContext + 0x3160);
            goto LAB_00014670;
          }
          if (pname < 0xb62) {
            if (pname == 0xb57) {
              scalarResult = (uint)*(byte *)(glContext + 0x30ab);
            }
            else {
              if (pname != 0xb60) {
                return 0;
              }
              scalarResult = (uint)*(byte *)(glContext + 0x316a);
            }
            goto LAB_00015f48;
          }
          if (pname == 0xb62) {
            floatStateValue = (double)*(float *)(glContext + 0x3150);
          }
          else {
            if (pname != 0xb63) {
              return 0;
            }
            floatStateValue = (double)*(float *)(glContext + 0x3154);
          }
        }
LAB_0001467c:
        *values = floatStateValue;
LAB_00015d48:
        *valueType = 0x140a;
        return valueCount;
      }
      if (pname == 0xb46) {
        scalarResult = (uint)*(ushort *)(glContext + 0x34d4);
        goto LAB_00015f48;
      }
      if (pname < 0xb47) {
        if (pname == 0xb43) {
          scalarResult = (uint)*(byte *)(glContext + 0x2ec);
        }
        else if (pname < 0xb44) {
          if (pname == 0xb41) {
            scalarResult = (uint)*(byte *)(glContext + 0x34d9);
          }
          else {
            if (pname != 0xb42) {
              return 0;
            }
            scalarResult = (uint)*(byte *)(glContext + 0x34d8);
          }
        }
        else if (pname == 0xb44) {
          scalarResult = (uint)*(byte *)(glContext + 0x34da);
        }
        else {
          if (pname != 0xb45) {
            return 0;
          }
          scalarResult = (uint)*(ushort *)(glContext + 0x34d6);
        }
        goto LAB_00015f48;
      }
      if (pname == 0xb52) {
        scalarResult = (uint)*(byte *)(glContext + 0x30ac);
        goto LAB_00015f48;
      }
      if (pname < 0xb53) {
        if (pname == 0xb50) {
          scalarResult = (uint)*(byte *)(glContext + 0x30aa);
        }
        else {
          if (pname != 0xb51) {
            return 0;
          }
          scalarResult = (uint)*(byte *)(glContext + 0x30ad);
        }
        goto LAB_00015f48;
      }
      if (pname == 0xb54) {
        scalarResult = *(uint *)(glContext + 0x34f4);
        goto LAB_00015f48;
      }
      if (0xb54 < pname) {
        scalarResult = (uint)*(ushort *)(glContext + 0x30a4);
        goto LAB_00015f48;
      }
      *values = (double)*(float *)(glContext + 0x2810);
      values[1] = (double)*(float *)(glContext + 0x2814);
      values[2] = (double)*(float *)(glContext + 0x2818);
      fourthComponent = (double)*(float *)(glContext + 0x281c);
    }
LAB_00015a8c:
    valueCount = 4;
    values[3] = fourthComponent;
LAB_00015a90:
    *valueType = 0x140a;
    *param_5 = 1;
    return valueCount;
  }
  if (pname == 0xbe0) {
LAB_00014d84:
    scalarResult = (uint)*(ushort *)(glContext + 0x30ca);
    goto LAB_00015f48;
  }
  if (0xbe0 < pname) {
    if (pname == 0xc22) {
      *values = (double)*(float *)(glContext + 0x3100);
      values[1] = (double)*(float *)(glContext + 0x3104);
      values[2] = (double)*(float *)(glContext + 0x3108);
      fourthComponent = (double)*(float *)(glContext + 0x310c);
      goto LAB_00015a8c;
    }
    if (0xc22 < pname) {
      if (pname == 0xc40) {
        scalarResult = *(uint *)(glContext + 0x4e1c);
      }
      else if (pname < 0xc41) {
        if (pname == 0xc31) {
          scalarResult = 1;
        }
        else if (pname < 0xc32) {
          if (pname == 0xc23) {
            *(uint *)values = (uint)*(byte *)(glContext + 0x31a0);
            *(uint *)(values + 1) = (uint)*(byte *)(glContext + 0x31a1);
            *(uint *)(values + 2) = (uint)*(byte *)(glContext + 0x31a2);
            scalarResult = (uint)*(byte *)(glContext + 0x31a3);
            goto LAB_00014ed8;
          }
          if (pname != 0xc30) {
            return 0;
          }
          scalarResult = 0;
        }
        else if (pname == 0xc32) {
          scalarResult = (uint)*(byte *)(glContext + 0x7582);
        }
        else {
          if (pname != 0xc33) {
            return 0;
          }
          scalarResult = (uint)*(byte *)(*(int *)(glContext + 0x468c) + 0x26);
        }
      }
      else if (pname == 0xc52) {
        scalarResult = (uint)*(ushort *)(0x3170 + glContext);
      }
      else if (pname < 0xc53) {
        if (pname == 0xc50) {
          scalarResult = (uint)*(ushort *)(glContext + 0x316c);
        }
        else {
          if (pname != 0xc51) {
            return 0;
          }
          scalarResult = (uint)*(ushort *)(glContext + 0x316e);
        }
      }
      else if (pname == 0xc54) {
        scalarResult = (uint)*(ushort *)(glContext + 0x3174);
      }
      else if (pname < 0xc54) {
        scalarResult = (uint)*(ushort *)(glContext + 0x3172);
      }
      else {
        if (pname != 0xc60) {
          return 0;
        }
        if (7 < *(int *)(glContext + 0x53d4)) {
          return -1;
        }
        scalarResult = (uint)*(byte *)(*(int *)(glContext + 0x53d4) * 0x94 + glContext + 0x3d78);
      }
      goto LAB_00015f48;
    }
    if (pname == 0xc00) {
      scalarResult = *(uint *)(*(int *)(glContext + 0x468c) + 0x54);
      goto LAB_00015f48;
    }
    if (pname < 0xc01) {
      if (pname == 0xbf0) {
        scalarResult = (uint)*(ushort *)(glContext + 0x3190);
        goto LAB_00015f48;
      }
      if (0xbf0 < pname) {
        if (pname == 0xbf1) {
          scalarResult = (uint)*(byte *)(glContext + 0x3192);
        }
        else {
          if (pname != 0xbf2) {
            return 0;
          }
          scalarResult = (uint)*(byte *)(glContext + 0x3193);
        }
        goto LAB_00015f48;
      }
      if (pname != 0xbe1) {
        if (pname != 0xbe2) {
          return 0;
        }
        scalarResult = (uint)*(byte *)(glContext + 0x30e4);
        goto LAB_00015f48;
      }
LAB_00014d8c:
      scalarResult = (uint)*(ushort *)(glContext + 0x30c8);
      goto LAB_00015f48;
    }
    if (pname == 0xc10) {
      *(uint *)values = *(uint *)(glContext + 0x34e0);
      *(uint *)(values + 1) = *(uint *)(glContext + 0x34e4);
      *(uint *)(values + 2) = *(uint *)(glContext + 0x34e8);
      scalarResult = *(uint *)(glContext + 0x34ec);
      goto LAB_00014ed8;
    }
    if (pname < 0xc11) {
      if (pname == 0xc01) {
        if (*(int *)(glContext + 0x744c) == 0) {
          scalarResult = (uint)*(ushort *)(glContext + 0x311a);
        }
        else {
          scalarResult = (uint)*(ushort *)(*(int *)(glContext + 0x744c) + 0xc0);
        }
      }
      else {
        if (pname != 0xc02) {
          return 0;
        }
        if (*(int *)(glContext + 0x744c) == 0) {
          scalarResult = (uint)*(ushort *)(glContext + 0x3118);
        }
        else {
          scalarResult = (uint)*(ushort *)(*(int *)(glContext + 0x744c) + 200);
        }
      }
      goto LAB_00015f48;
    }
    if (pname != 0xc20) {
      if (pname < 0xc21) {
        if (pname != 0xc11) {
          return 0;
        }
        scalarResult = (uint)*(byte *)(glContext + 0x34f0);
      }
      else {
        scalarResult = *(uint *)(glContext + 0x3194);
      }
      goto LAB_00015f48;
    }
    floatStateValue = (double)*(float *)(glContext + 0x3110);
LAB_00014670:
    floatStateValue = floatStateValue * DOUBLE_00108d98;
    goto LAB_0001467c;
  }
  if (pname == 0xba2) {
    *(uint *)values = *(uint *)(glContext + 0x1ba0);
    *(uint *)(values + 1) = *(uint *)(glContext + 0x1ba4);
    *(uint *)(values + 2) = *(uint *)(glContext + 0x1ba8);
    scalarResult = *(uint *)(glContext + 0x1bac);
LAB_00014ed8:
    *(uint *)(values + 3) = scalarResult;
    return 4;
  }
  if (0xba2 < pname) {
    if (pname == 0xba8) {
      if (7 < *(int *)(glContext + 0x53d4)) {
        return -1;
      }
      matrixPtr = glContext + *(int *)(glContext + 0x53d4) * 0x40 + 0x1fc0;
    }
    else {
      if (0xba8 < pname) {
        if (pname == 0xbc0) {
          scalarResult = (uint)*(byte *)(glContext + 0x30c6);
          goto LAB_00015f48;
        }
        if (pname < 0xbc1) {
          if (pname == 0xbb0) {
            scalarResult = *(uint *)(glContext + 0x50fc);
          }
          else {
            if (pname != 0xbb1) {
              return 0;
            }
            scalarResult = *(uint *)(glContext + 0x5144);
          }
          goto LAB_00015f48;
        }
        if (pname != 0xbc2) {
          if (pname < 0xbc2) {
            scalarResult = (uint)*(ushort *)(glContext + 0x30c4);
          }
          else {
            if (pname != 0xbd0) {
              return 0;
            }
            scalarResult = (uint)*(byte *)(glContext + 0x313c);
          }
          goto LAB_00015f48;
        }
        doubleStateValue = (double)*(float *)(glContext + 0x30c0);
LAB_00014d74:
        *values = doubleStateValue;
        goto LAB_00015a90;
      }
      if (pname == 0xba5) {
        if (7 < *(int *)(glContext + 0x53d4)) {
          return -1;
        }
        currentMatrixPtr = *(int *)(*(int *)(glContext + 0x53d4) * 4 + glContext + 0x503c);
LAB_00014c5c:
        scalarResult = currentMatrixPtr + 1;
LAB_00015450:
        *(uint *)values = scalarResult;
        return 1;
      }
      if (pname < 0xba6) {
        if (pname == 0xba3) {
          iVar13 = *(int *)(glContext + 0x500c);
        }
        else {
          if (pname != 0xba4) {
            return 0;
          }
          iVar13 = *(int *)(glContext + 0x5008);
        }
LAB_00014bf4:
        scalarResult = iVar13 + 1;
        goto LAB_00015efc;
      }
      if (pname == 0xba6) goto LAB_00014c74;
      if (pname != 0xba7) {
        return 0;
      }
      matrixPtr = glContext + 0x1c80;
    }
    goto LAB_00014c84;
  }
  if (pname == 0xb94) {
    scalarResult = (uint)*(ushort *)((uint)*(byte *)(glContext + 0x7583) * 0x10 + glContext + 0x3502);
    goto LAB_00015f48;
  }
  if (pname < 0xb95) {
    if (pname == 0xb91) {
      scalarResult = *(uint *)(glContext + 0x3114);
      goto LAB_00015f48;
    }
    if (0xb91 < pname) {
      if (pname == 0xb92) {
        scalarResult = (uint)*(ushort *)((uint)*(byte *)(glContext + 0x7583) * 0x10 + glContext + 0x3500);
      }
      else {
        if (pname != 0xb93) {
          return 0;
        }
        scalarResult = *(uint *)((uint)*(byte *)(glContext + 0x7583) * 0x10 + glContext + 0x34f8);
      }
      goto LAB_00015f48;
    }
    if (pname != 0xb80) {
      if (pname != 0xb90) {
        return 0;
      }
      scalarResult = *(uint *)(glContext + 0x3520) >> (*(byte *)(glContext + 0x7583) & 0x3f) & 1;
      goto LAB_00015f48;
    }
    *values = (double)*(float *)(glContext + 0x30f0);
    values[1] = (double)*(float *)(glContext + 0x30f4);
    values[2] = (double)*(float *)(glContext + 0x30f8);
    fourthComponent = (double)*(float *)(glContext + 0x30fc);
    goto LAB_00015a8c;
  }
  if (pname == 0xb97) {
    scalarResult = *(uint *)((uint)*(byte *)(glContext + 0x7583) * 0x10 + glContext + 0x34fc);
    goto LAB_00015f48;
  }
  if (pname < 0xb98) {
    if (pname == 0xb95) {
      scalarResult = (uint)*(ushort *)((uint)*(byte *)(glContext + 0x7583) * 0x10 + glContext + 0x3504);
    }
    else {
      if (pname != 0xb96) {
        return 0;
      }
      scalarResult = (uint)*(ushort *)((uint)*(byte *)(glContext + 0x7583) * 0x10 + glContext + 0x3506);
    }
    goto LAB_00015f48;
  }
  if (pname != 0xba0) {
    if (pname < 0xba1) {
      if (pname != 0xb98) {
        return 0;
      }
      scalarResult = *(uint *)((uint)*(byte *)(glContext + 0x7583) * 4 + glContext + 0x3198);
    }
    else {
      scalarResult = (uint)*(byte *)(glContext + 0x280d);
    }
    goto LAB_00015f48;
  }
  matrixModeIndex = *(int *)(glContext + 0x4ff4);
  switch(matrixModeIndex) {
  default:
    scalarResult = 0x1702;
    break;
  case 2:
    scalarResult = 0x1800;
    break;
  case 3:
    scalarResult = 0x1701;
    break;
  case 4:
    scalarResult = 0x1700;
    break;
  case 5:
    scalarResult = 0x850a;
    break;
  case 6:
  case 7:
    scalarResult = matrixModeIndex + 0x871c;
    goto LAB_00015efc;
  case 8:
  case 9:
  case 10:
  case 0xb:
  case 0xc:
  case 0xd:
  case 0xe:
  case 0xf:
    scalarResult = matrixModeIndex + 35000;
LAB_00015efc:
    *(uint *)values = scalarResult;
    return 1;
  }
LAB_00015f48:
  *(uint *)values = scalarResult;
  return 1;
}

/* _glViewport_Exec @ 0x15f6c (136 bytes) */
void _glViewport_Exec(int glContext,undefined4 x,undefined4 y,int width,int height,double forwardedFloatArg1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
{
  int iVar1;
  undefined4 glErrorCode;
  int iVar3;
  
  iVar3 = *(int *)(*(int *)(glContext + 0x468c) + 0x10);
  iVar1 = *(int *)(*(int *)(glContext + 0x468c) + 0xc);
  if (*(short *)(glContext + 0x4a10) < 0) {
    if ((-1 < width) && (-1 < height)) {
      *(undefined4 *)(glContext + 0x1ba0) = x;
      *(undefined4 *)(glContext + 0x1ba4) = y;
      if (iVar1 < width) {
        *(int *)(glContext + 0x1ba8) = iVar1;
      }
      else {
        *(int *)(glContext + 0x1ba8) = width;
      }
      if (iVar3 < height) {
        *(int *)(glContext + 0x1bac) = iVar3;
      }
      else {
        *(int *)(glContext + 0x1bac) = height;
      }
      ((void (*)())_gleUpdateViewScissorData)(glContext,forwardedFloatArg1,forwardedFloatArg2,forwardedFloatArg3,forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
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

/* _glMatrixMode_Exec @ 0x15ff4 (236 bytes) */
void _glMatrixMode_Exec(glContext, mode)
  int glContext;
  uint mode;
{
  undefined4 glErrorCode;
  int iVar2;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (mode == 0x850a) {
      iVar2 = 5;
      goto LAB_000160d8;
    }
    if (mode < 0x850b) {
      if (mode == 0x1701) {
        iVar2 = 3;
        goto LAB_000160d8;
      }
      if (mode < 0x1702) {
        if (mode == 0x1700) {
          iVar2 = 4;
          goto LAB_000160d8;
        }
      }
      else {
        if (mode == 0x1702) {
          iVar2 = *(int *)(glContext + 0x53d4) + 0x10;
          goto LAB_000160d8;
        }
        if (mode == 0x1800) {
          iVar2 = 2;
          goto LAB_000160d8;
        }
      }
    }
    else if (0x8721 < mode) {
      if (mode < 0x8724) {
        iVar2 = mode - 0x871c;
LAB_000160d8:
        *(int *)(glContext + 0x4ff4) = iVar2;
        ((void (*)())_gleUpdateMatrixMode)(glContext);
        return;
      }
      if (mode - 0x88c0 < 8) {
        iVar2 = mode - 35000;
        goto LAB_000160d8;
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

/* _glLoadIdentity_Exec @ 0x160e0 (176 bytes) */
int _glLoadIdentity_Exec(glContext)
  int glContext;
{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined4 currentMatrix;
  
  currentMatrix = *(undefined4 *)(glContext + 0x4fec);
  if ((*(short *)(glContext + 0x4a10) < 0) && (*(int *)(glContext + 0x4ff4) < 0x18)) {
    iVar2 = _gleMakeIdentityMatrix(currentMatrix);
    uVar3 = *(uint *)(glContext + 0x50a8);
    *(uint *)(glContext + 0x50ac) = *(uint *)(glContext + 0x50ac) | uVar3;
    if ((uVar3 & *(uint *)(glContext + 0x505c) & 0xfffffc) != 0) {
      iVar2 = _gleCopyMatrix(currentMatrix,*(undefined4 *)(glContext + 0x4ff0));
      uVar1 = uVar3 & 0xfffffc;
      uVar3 = uVar3 & 0xff000003;
      *(uint *)(glContext + 0x50b0) = *(uint *)(glContext + 0x50b0) & ~uVar1;
    }
    *(uint *)(glContext + 0x50b0) = *(uint *)(glContext + 0x50b0) | uVar3;
  }
  else {
    iVar2 = glContext;
    if (*(int *)(glContext + 0x7574) == 0) {
      *(undefined4 *)(glContext + 0x7574) = 0x502;
    }
  }
  return iVar2;
}

/* _glOrtho_Exec @ 0x16190 (616 bytes) */
void _glOrtho_Exec(int glContext,double left,double right,double bottom,double top,double zNear,double zFar,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  float rightMinusLeft;
  float scaleZ;
  float topMinusBottom;
  float scaleX;
  float nearMinusFar;
  float scaleY;
  float absRightMinusLeft;
  float translateZ;
  float absNearMinusFar;
  float absTopMinusBottom;
  float translateX;
  float translateY;
  undefined4 glErrorCode;
  float *currentMatrix;
  double inverseNearMinusFar;
  double inverseTopMinusBottom;
  double inverseRightMinusLeft;
  
  currentMatrix = *(float **)(glContext + 0x4fec);
  if ((*(short *)(glContext + 0x4a10) < 0) && (*(int *)(glContext + 0x4ff4) < 0x18)) {
    rightMinusLeft = (float)(right - left);
    topMinusBottom = (float)(top - bottom);
    nearMinusFar = (float)(zNear - zFar);
    absRightMinusLeft = rightMinusLeft;
    if (!(FLOAT_00108e50 <= rightMinusLeft)) {
      absRightMinusLeft = -rightMinusLeft;
    }
    if (!(absRightMinusLeft < FLOAT_00108e80)) {
      absTopMinusBottom = topMinusBottom;
      if (!(FLOAT_00108e50 <= topMinusBottom)) {
        absTopMinusBottom = -topMinusBottom;
      }
      if (!(absTopMinusBottom < FLOAT_00108e80)) {
        absNearMinusFar = nearMinusFar;
        if (!(FLOAT_00108e50 <= nearMinusFar)) {
          absNearMinusFar = -nearMinusFar;
        }
        if (!(absNearMinusFar < FLOAT_00108e80)) {
          inverseTopMinusBottom = (double)(1.0 / topMinusBottom);
          inverseRightMinusLeft = (double)(1.0 / rightMinusLeft);
          inverseNearMinusFar = (double)(1.0 / nearMinusFar);
          translateZ = (float)((zFar + zNear) * inverseNearMinusFar);
          translateX = (float)(-(right + left) * inverseRightMinusLeft);
          scaleZ = (float)(inverseNearMinusFar + inverseNearMinusFar);
          translateY = (float)(-(top + bottom) * inverseTopMinusBottom);
          scaleX = (float)(inverseRightMinusLeft + inverseRightMinusLeft);
          scaleY = (float)(inverseTopMinusBottom + inverseTopMinusBottom);
          currentMatrix[0xc] = currentMatrix[0xc] + (currentMatrix[8] * translateZ + (*currentMatrix * translateX + currentMatrix[4] * translateY));
          currentMatrix[0xd] = currentMatrix[0xd] + (currentMatrix[9] * translateZ + (currentMatrix[1] * translateX + currentMatrix[5] * translateY));
          currentMatrix[0xe] = currentMatrix[0xe] + (currentMatrix[10] * translateZ + (currentMatrix[2] * translateX + currentMatrix[6] * translateY));
          currentMatrix[0xf] = currentMatrix[0xf] + (currentMatrix[0xb] * translateZ + (currentMatrix[3] * translateX + currentMatrix[7] * translateY));
          currentMatrix[3] = currentMatrix[3] * scaleX;
          currentMatrix[7] = currentMatrix[7] * scaleY;
          currentMatrix[0xb] = currentMatrix[0xb] * scaleZ;
          *currentMatrix = *currentMatrix * scaleX;
          currentMatrix[1] = currentMatrix[1] * scaleX;
          currentMatrix[2] = currentMatrix[2] * scaleX;
          currentMatrix[4] = currentMatrix[4] * scaleY;
          currentMatrix[5] = currentMatrix[5] * scaleY;
          currentMatrix[6] = currentMatrix[6] * scaleY;
          currentMatrix[8] = currentMatrix[8] * scaleZ;
          currentMatrix[9] = currentMatrix[9] * scaleZ;
          currentMatrix[10] = currentMatrix[10] * scaleZ;
          *(uint *)(glContext + 0x50ac) = *(uint *)(glContext + 0x50ac) | *(uint *)(glContext + 0x50a8);
          *(uint *)(glContext + 0x50b0) = *(uint *)(glContext + 0x50b0) | *(uint *)(glContext + 0x50a8);
          return;
        }
      }
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

/* _glEnable_Exec @ 0x163f8 (108 bytes) */
double _glEnable_Exec(glContext, cap)
  int glContext;
  uint cap;
{
  undefined4 glErrorCode;
  uint *puVar2;
  
  puVar2 = (uint *)(*(int *)(glContext + 0x4850) + (cap & 0x3ff) * 0x10);
  if (*(short *)(glContext + 0x4a10) < 0) {
    do {
      if (*puVar2 == cap) {
                    
                    
        (*(code *)puVar2[1])(glContext,cap,1);
        return;
      }
      puVar2 = (uint *)puVar2[2];
    } while (puVar2 != (uint *)0x0);
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

/* _gleSetEnable_ALPHA_TEST @ 0x16464 (32 bytes) */
void _gleSetEnable_ALPHA_TEST(param_1, unusedArg2, param_3)
  int param_1;
  undefined4 unusedArg2;
  uint param_3;
{
  if (*(byte *)(param_1 + 0x30c6) == param_3) {
    return;
  }
  *(char *)(param_1 + 0x30c6) = (char)param_3;
  *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 1;
  return;
}

