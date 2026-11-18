#include "decls.h"

/* _gleVPBeginQuadStripTCL @ 0x1071ac (52 bytes) */
void _gleVPBeginQuadStripTCL(glContext)
  int glContext;
{
  undefined *vpFlushTriQuadStripTCL;
  
  vpFlushTriQuadStripTCL = PTR__gleVPFlushTriQuadStripTCL_0011161c;
  *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
  *(undefined **)(glContext + 0x4a0c) = vpFlushTriQuadStripTCL;
  *(undefined **)(glContext + 0x4a08) = PTR__gleRenderQuadStripTCLFunc_0011226c;
  return;
}

/* _gleVPBeginPolygonTCL @ 0x1071e0 (60 bytes) */
void _gleVPBeginPolygonTCL(glContext)
  int glContext;
{
  undefined *vpFlushPolygonTCL;
  undefined *renderPolygonTCLFunc;
  
  *(undefined1 *)(glContext + 0x4a18) = 0;
  renderPolygonTCLFunc = PTR__gleRenderPolygonTCLFunc_00112250;
  vpFlushPolygonTCL = PTR__gleVPFlushPolygonTCL_00111614;
  *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
  *(undefined **)(glContext + 0x4a0c) = vpFlushPolygonTCL;
  *(undefined **)(glContext + 0x4a08) = renderPolygonTCLFunc;
  return;
}

/* _gleVPBeginPointsTCLRDirty @ 0x10721c (52 bytes) */
void _gleVPBeginPointsTCLRDirty(glContext)
  int glContext;
{
  undefined *vpFlushAtomicTCLRDirty;
  
  vpFlushAtomicTCLRDirty = PTR__gleVPFlushAtomicTCLRDirty_00111610;
  *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
  *(undefined **)(glContext + 0x4a0c) = vpFlushAtomicTCLRDirty;
  *(undefined **)(glContext + 0x4a08) = PTR__gleRenderPointsTCLFunc_0011223c;
  return;
}

/* _gleVPBeginLinesTCLRDirty @ 0x107250 (52 bytes) */
void _gleVPBeginLinesTCLRDirty(glContext)
  int glContext;
{
  undefined *vpFlushAtomicTCLRDirty;
  
  vpFlushAtomicTCLRDirty = PTR__gleVPFlushAtomicTCLRDirty_00111610;
  *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
  *(undefined **)(glContext + 0x4a0c) = vpFlushAtomicTCLRDirty;
  *(undefined **)(glContext + 0x4a08) = PTR__gleRenderLinesTCLFunc_00112214;
  return;
}

/* _gleVPBeginLineLoopTCLRDirty @ 0x107284 (60 bytes) */
void _gleVPBeginLineLoopTCLRDirty(glContext)
  int glContext;
{
  undefined *vpFlushLineLoopTCLRDirty;
  undefined *renderLineLoopTCLFunc;
  
  *(undefined1 *)(glContext + 0x4a18) = 0;
  renderLineLoopTCLFunc = PTR__gleRenderLineLoopTCLFunc_001121d4;
  vpFlushLineLoopTCLRDirty = PTR__gleVPFlushLineLoopTCLRDirty_0011160c;
  *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
  *(undefined **)(glContext + 0x4a0c) = vpFlushLineLoopTCLRDirty;
  *(undefined **)(glContext + 0x4a08) = renderLineLoopTCLFunc;
  return;
}

/* _gleVPBeginLineStripTCLRDirty @ 0x1072c0 (60 bytes) */
void _gleVPBeginLineStripTCLRDirty(glContext)
  int glContext;
{
  undefined *vpFlushLineStripTCLRDirty;
  undefined *renderLineStripTCLFunc;
  
  *(undefined1 *)(glContext + 0x4a18) = 0;
  renderLineStripTCLFunc = PTR__gleRenderLineStripTCLFunc_001121f4;
  vpFlushLineStripTCLRDirty = PTR__gleVPFlushLineStripTCLRDirty_00111608;
  *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
  *(undefined **)(glContext + 0x4a0c) = vpFlushLineStripTCLRDirty;
  *(undefined **)(glContext + 0x4a08) = renderLineStripTCLFunc;
  return;
}

/* _gleVPBeginTrianglesTCLRDirty @ 0x1072fc (52 bytes) */
void _gleVPBeginTrianglesTCLRDirty(glContext)
  int glContext;
{
  undefined *vpFlushAtomicTCLRDirty;
  
  vpFlushAtomicTCLRDirty = PTR__gleVPFlushAtomicTCLRDirty_00111610;
  *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
  *(undefined **)(glContext + 0x4a0c) = vpFlushAtomicTCLRDirty;
  *(undefined **)(glContext + 0x4a08) = PTR__gleRenderTrianglesTCLFunc_001122d4;
  return;
}

/* _gleVPBeginTriangleStripTCLRDirty @ 0x107330 (52 bytes) */
void _gleVPBeginTriangleStripTCLRDirty(glContext)
  int glContext;
{
  undefined *vpFlushTriQuadStripTCLRDirty;
  
  vpFlushTriQuadStripTCLRDirty = PTR__gleVPFlushTriQuadStripTCLRDirty_00111604;
  *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
  *(undefined **)(glContext + 0x4a0c) = vpFlushTriQuadStripTCLRDirty;
  *(undefined **)(glContext + 0x4a08) = PTR__gleRenderTriangleStripTCLFunc_001122b8;
  return;
}

/* _gleVPBeginTriangleFanTCLRDirty @ 0x107364 (52 bytes) */
void _gleVPBeginTriangleFanTCLRDirty(glContext)
  int glContext;
{
  undefined *vpFlushTriangleFanTCLRDirty;
  
  vpFlushTriangleFanTCLRDirty = PTR__gleVPFlushTriangleFanTCLRDirty_00111600;
  *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
  *(undefined **)(glContext + 0x4a0c) = vpFlushTriangleFanTCLRDirty;
  *(undefined **)(glContext + 0x4a08) = PTR__gleRenderTriangleFanTCLFunc_00112298;
  return;
}

/* _gleVPBeginQuadsTCLRDirty @ 0x107398 (52 bytes) */
void _gleVPBeginQuadsTCLRDirty(glContext)
  int glContext;
{
  undefined *vpFlushAtomicTCLRDirty;
  
  vpFlushAtomicTCLRDirty = PTR__gleVPFlushAtomicTCLRDirty_00111610;
  *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
  *(undefined **)(glContext + 0x4a0c) = vpFlushAtomicTCLRDirty;
  *(undefined **)(glContext + 0x4a08) = PTR__gleRenderQuadsTCLFunc_00112280;
  return;
}

/* _gleVPBeginQuadStripTCLRDirty @ 0x1073cc (52 bytes) */
void _gleVPBeginQuadStripTCLRDirty(glContext)
  int glContext;
{
  undefined *vpFlushTriQuadStripTCLRDirty;
  
  vpFlushTriQuadStripTCLRDirty = PTR__gleVPFlushTriQuadStripTCLRDirty_00111604;
  *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
  *(undefined **)(glContext + 0x4a0c) = vpFlushTriQuadStripTCLRDirty;
  *(undefined **)(glContext + 0x4a08) = PTR__gleRenderQuadStripTCLFunc_0011226c;
  return;
}

/* _gleVPBeginPolygonTCLRDirty @ 0x107400 (60 bytes) */
void _gleVPBeginPolygonTCLRDirty(glContext)
  int glContext;
{
  undefined *vpFlushPolygonTCLRDirty;
  undefined *renderPolygonTCLFunc;
  
  *(undefined1 *)(glContext + 0x4a18) = 0;
  renderPolygonTCLFunc = PTR__gleRenderPolygonTCLFunc_00112250;
  vpFlushPolygonTCLRDirty = PTR__gleVPFlushPolygonTCLRDirty_001115fc;
  *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
  *(undefined **)(glContext + 0x4a0c) = vpFlushPolygonTCLRDirty;
  *(undefined **)(glContext + 0x4a08) = renderPolygonTCLFunc;
  return;
}

/* _gleVPEmulate @ 0x10743c (340 bytes) */
int _gleVPEmulate(glContext, param_2)
  int glContext;
  int param_2;
{
  uint uVar1;
  undefined4 uVar2;
  undefined2 uVar3;
  int iVar4;
  undefined4 uVar5;
  byte *pbVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  double dVar10;
  
  iVar8 = *(int *)(glContext + 0x4a5c);
  iVar7 = *(int *)(glContext + 0x4864);
  if (*(int *)(glContext + 0x5434) == 0) {
    uVar5 = *(undefined4 *)(*(int *)(glContext + 0x5420) + 0x4e0);
    iVar4 = *(int *)(*(int *)(glContext + 0x5420) + 0x4e4);
  }
  else {
    iVar4 = *(int *)(*(int *)(glContext + 0x5430) + 0x20);
    uVar5 = *(undefined4 *)(iVar4 + 0x51c);
    iVar4 = *(int *)(iVar4 + 0x4dc);
  }
  uVar3 = 0;
  if (iVar4 != 0) {
    *(undefined4 *)(iVar8 + 0xd8c) = *(undefined4 *)(glContext + 0x4854);
    *(int *)(iVar8 + 0xd9c) = glContext;
    *(int *)(iVar8 + 0xd88) = iVar7;
    uVar2 = *(undefined4 *)(iVar4 + 0xb0);
    *(undefined4 *)(iVar8 + 0xd98) = uVar5;
    *(undefined4 *)(iVar8 + 0xd90) = uVar2;
    *(int *)(iVar8 + 0xd94) = glContext + 0x360;
    _PPEmulatorAttachProgram(iVar8,iVar4);
    *(undefined4 *)(iVar4 + 0xb8) = 0x100;
    uVar3 = _PPEmulatorRun(iVar8,param_2);
    iVar8 = param_2;
    if (*(char *)(glContext + 0x316a) != '\0') {
      for (; iVar8 != 0; iVar8 = iVar8 + -1) {
        dVar10 = (double)(**(double ( **)(int,double))(glContext + 0x4fe4))(glContext, (double)*(float *)(iVar7 + 0x5c));
        *(float *)(iVar7 + 0x4c) = (float)dVar10;
        iVar7 = iVar7 + 0x100;
      }
    }
    if (*(int *)(glContext + 0x34d0) != 0x1b021b02) {
      uVar9 = 0;
      iVar7 = *(int *)(glContext + 0x30b0);
      if (0 < param_2) {
        pbVar6 = (byte *)(*(int *)(glContext + 0x4864) + 0x7c);
        do {
          iVar8 = (int)uVar9 >> 5;
          uVar1 = uVar9 & 0x1f;
          uVar9 = uVar9 + 1;
          *pbVar6 = (byte)(*(uint *)(iVar7 + iVar8 * 4) >> uVar1) & 1;
          pbVar6 = pbVar6 + 0x100;
          param_2 = param_2 + -1;
        } while (param_2 != 0);
      }
    }
  }
  return uVar3;
}

/* _gleSetWindowPos @ 0x107590 (424 bytes) */
double _gleSetWindowPos(int glContext,float floatArg1,float floatArg2,double floatArg3)
{
  undefined4 *texCoordSourcePtr;
  undefined4 normalYThenTexCoordT;
  undefined4 normalZThenTexCoordR;
  undefined4 texCoordQ;
  float floatZero;
  int vertexBufferStart;
  int recordTexCoordCursor;
  int texCoordSetCursor;
  int unitsLeft;
  double floatZeroThenWindowZThenFogThenHitResult;
  
  floatZero = FLOAT_00108e50;
  floatZeroThenWindowZThenFogThenHitResult = (double)FLOAT_00108e50;
  *(undefined1 *)(glContext + 0x2ef) = 1;
  vertexBufferStart = *(int *)(glContext + 0x4854);
  *(undefined4 *)(vertexBufferStart + -0x184) = *(undefined4 *)(glContext + 0x2ec);
  *(undefined1 *)(vertexBufferStart + -0x181) = 0;
  *(float *)(glContext + 0x2e0) = (float)floatArg1;
  *(float *)(glContext + 0x2e4) = (float)floatArg2;
  if (floatArg3 < floatZeroThenWindowZThenFogThenHitResult) {
    floatZeroThenWindowZThenFogThenHitResult = *(double *)(glContext + 0x1b90);
  }
  else if (1.0 < floatArg3) {
    floatZeroThenWindowZThenFogThenHitResult = *(double *)(glContext + 0x1b98);
  }
  else {
    floatZeroThenWindowZThenFogThenHitResult = floatArg3 * (*(double *)(glContext + 0x1b98) - *(double *)(glContext + 0x1b90)) +
             *(double *)(glContext + 0x1b90);
  }
  *(float *)(glContext + 0x2e8) = (float)floatZeroThenWindowZThenFogThenHitResult;
  *(undefined4 *)(vertexBufferStart + -500) = 0x3f800000;
  if (*(short *)(glContext + 0x3166) == -0x7baf) {
    floatZeroThenWindowZThenFogThenHitResult = (double)(**(double ( **)(int,double))(glContext + 0x4fe4))(glContext, (double)*(float *)(glContext + 0x2cc));
    *(float *)(vertexBufferStart + -0x1b4) = (float)floatZeroThenWindowZThenFogThenHitResult;
    *(undefined4 *)(vertexBufferStart + -0x1d8) = *(undefined4 *)(glContext + 0x2cc);
  }
  else {
    floatZeroThenWindowZThenFogThenHitResult = (double)(**(double ( **)(int,double))(glContext + 0x4fe4))(glContext, (double)FLOAT_00108e50);
    *(float *)(vertexBufferStart + -0x1d8) = floatZero;
    *(float *)(vertexBufferStart + -0x1b4) = (float)floatZeroThenWindowZThenFogThenHitResult;
  }
  normalYThenTexCoordT = *(undefined4 *)(glContext + 0x2b4);
  unitsLeft = 8;
  normalZThenTexCoordR = *(undefined4 *)(glContext + 0x2b8);
  *(undefined4 *)(vertexBufferStart + -0x1c0) = *(undefined4 *)(glContext + 0x2b0);
  *(undefined4 *)(vertexBufferStart + -0x1bc) = normalYThenTexCoordT;
  *(undefined4 *)(vertexBufferStart + -0x1b8) = normalZThenTexCoordR;
  *(undefined8 *)(vertexBufferStart + -0x1d0) = *(undefined8 *)(glContext + 0x2a0);
  *(undefined8 *)(vertexBufferStart + -0x1c8) = *(undefined8 *)(glContext + 0x2a8);
  *(undefined8 *)(vertexBufferStart + -0x1b0) = *(undefined8 *)(glContext + 0x2c0);
  *(undefined4 *)(vertexBufferStart + -0x1a8) = *(undefined4 *)(glContext + 0x2c8);
  recordTexCoordCursor = vertexBufferStart + -0x200;
  texCoordSetCursor = glContext;
  do {
    texCoordSourcePtr = (undefined4 *)(texCoordSetCursor + 0x120);
    normalYThenTexCoordT = *(undefined4 *)(texCoordSetCursor + 0x124);
    normalZThenTexCoordR = *(undefined4 *)(texCoordSetCursor + 0x128);
    texCoordQ = *(undefined4 *)(texCoordSetCursor + 300);
    texCoordSetCursor = texCoordSetCursor + 0x10;
    *(undefined4 *)(recordTexCoordCursor + 0x80) = *texCoordSourcePtr;
    *(undefined4 *)(recordTexCoordCursor + 0x84) = normalYThenTexCoordT;
    *(undefined4 *)(recordTexCoordCursor + 0x88) = normalZThenTexCoordR;
    *(undefined4 *)(recordTexCoordCursor + 0x8c) = texCoordQ;
    recordTexCoordCursor = recordTexCoordCursor + 0x10;
    unitsLeft = unitsLeft + -1;
  } while (unitsLeft != 0);
  if (*(int *)(glContext + 0x4e1c) == 0x1c02) {
    floatZeroThenWindowZThenFogThenHitResult = (double)_gleSelectHit(glContext,vertexBufferStart + -0x200);
    return floatZeroThenWindowZThenFogThenHitResult;
  }
  return floatZeroThenWindowZThenFogThenHitResult;
}

/* _glepDeletePlugin @ 0x107740 (164 bytes) */
int _glepDeletePlugin(param_1)
  int *param_1;
{
  bool bVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  
  if (param_1 == (int *)0x0) {
    return (int *)0x0;
  }
  if (param_1 == _glep_plugin_head) {
    piVar4 = (int *)*_glep_plugin_head;
    _glep_plugin_head = piVar4;
LAB_001077c4:
    _free(param_1);
  }
  else {
    bVar1 = _glep_plugin_head == (int *)0x0;
    if (!bVar1) {
      piVar4 = (int *)*_glep_plugin_head;
      piVar3 = _glep_plugin_head;
      while (piVar2 = piVar4, param_1 != piVar2) {
        if (piVar2 == (int *)0x0) goto LAB_001077b0;
        bVar1 = false;
        piVar3 = piVar2;
        piVar4 = (int *)*piVar2;
      }
      if (!bVar1) {
        piVar4 = (int *)*param_1;
        *piVar3 = (int)piVar4;
        goto LAB_001077c4;
      }
    }
LAB_001077b0:
    piVar4 = (int *)0x0;
  }
  return piVar4;
}

/* _gliGetAttribute @ 0x1077e4 (12 bytes) */
void _gliGetAttribute(glContext, attribBit, attribBuffer)
  int glContext;
  undefined4 attribBit;
  undefined4 attribBuffer;
{
  if (glContext == 0) {
    return;
  }
  _gleGetAttrib(glContext,attribBit,attribBuffer);
  return;
}

/* _gliSetAttribute @ 0x1077f0 (72 bytes) */
void _gliSetAttribute(glContext, attribBit, attribBuffer)
  int glContext;
  undefined4 attribBit;
  undefined4 attribBuffer;
{
  if (glContext != 0) {
    _gleSetAttrib(glContext,attribBit,attribBuffer);
    _gleUpdateState(glContext);
    return;
  }
  return;
}

/* _gliCopyAttributes @ 0x107838 (120 bytes) */
void _gliCopyAttributes(glContext, glContext2)
  int glContext;
  int glContext2;
{
  uint nextAttribBit;
  uint attribBit;
  undefined1 attribBuffer [11340];
  
  if ((glContext != 0) && (glContext2 != 0)) {
    attribBit = 1;
    do {
      _gleGetAttrib(glContext,attribBit,attribBuffer);
      nextAttribBit = attribBit << 1;
      _gleSetAttrib(glContext2,attribBit,attribBuffer);
      attribBit = nextAttribBit;
    } while (nextAttribBit < 0xfffff);
    _gleUpdateState(glContext2);
  }
  return;
}

/* _gliSwitchPlugin @ 0x1078b0 (332 bytes) */
double _gliSwitchPlugin(glContext, rendererIndex)
  int glContext;
  int rendererIndex;
{
  uint slotEmptyMask;
  undefined *setClipInterpFunc;
  undefined4 rendererHandle;
  int rendererRecord;
  double floatArg1;
  double incomingFpr1;
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
  
  _gleSynchronizePluginFramebuffer(glContext);
  _gleSynchronizePluginTextures(glContext);
  _gleSynchronizePluginBuffers(glContext);
  *(char *)(glContext + 0x85a8) = (char)rendererIndex;
  rendererRecord = rendererIndex * 0x2e0 + glContext;
  rendererHandle = *(undefined4 *)(rendererRecord + 0x85ac);
  *(int *)(glContext + 0x468c) = rendererRecord + 0x85b0;
  *(undefined4 *)(glContext + 0x4688) = rendererHandle;
  _memcpy(glContext + 0x4754,*(int *)(rendererRecord + 0x8884) + 0x114,0xf4);
  *(undefined4 *)(glContext + 800) = 0xffffffff;
  *(undefined4 *)(glContext + 0x310) = 0xffffffff;
  *(uint *)(glContext + 0x314) = *(uint *)(glContext + 0x314) | 0x3ffffff;
  *(uint *)(glContext + 0x318) = *(uint *)(glContext + 0x318) | 0xfffffffd;
  *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x7ffffff;
  ((void (*)())_gleUpdateDepthRangeData)(glContext,floatArg1,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,incomingStack_ffffffb8,
             incomingStack_ffffffc0,incomingStack_ffffffc8,incomingStack_ffffffd0,incomingStack_ffffffd8);
  _gleUpdatePolyMode(glContext);
  ((void (*)())_gleUpdateViewScissorData)(glContext,incomingFpr1,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8);
  _gleUpdateTextureTransform(glContext);
  setClipInterpFunc = PTR__gleSetClipInterpFunc_00112038;
  *(undefined **)(glContext + 0x49c8) = PTR__gleSetEyeInterpFunc_0011203c;
  *(undefined **)(glContext + 0x49cc) = setClipInterpFunc;
  _gleUpdatePrimitiveData(glContext);
  slotEmptyMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xc) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & slotEmptyMask | *(uint *)(glContext + 0x4684) & ~slotEmptyMask) + 0xc) =
       PTR__glArrayElement_Exec_001120e8;
  _gleUpdateDrawArraysFuncs(glContext);
  _gleSelectVertexSubmitFunc(glContext);
  *(undefined4 *)(glContext + 0x488c) = 0;
  *(undefined4 *)(glContext + 0x4890) = 0;
  *(undefined4 *)(glContext + 0x4894) = 0;
  _gleResetVertexArrays(glContext);
  return;
}

/* _gliDetachRevert @ 0x1079fc (220 bytes) */
void _gliDetachRevert(glContext)
  int glContext;
{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = (uint)*(byte *)(glContext + 0x85a5);
  if (uVar2 == *(byte *)(glContext + 0x85a8)) {
    return;
  }
  if (uVar2 == 0xff) {
    return;
  }
  uVar1 = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x938) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & uVar1 | *(uint *)(glContext + 0x4684) & ~uVar1) + 0x938) =
       PTR__glSwap_Exec_0011211c;
  uVar1 = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x168) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & uVar1 | *(uint *)(glContext + 0x4684) & ~uVar1) + 0x168) =
       PTR__glFlush_Exec_00112118;
  iVar3 = uVar2 * 0x2e0 + glContext;
  uVar2 = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x164) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & uVar2 | *(uint *)(glContext + 0x4684) & ~uVar2) + 0x164) =
       PTR__glFinish_Exec_00112114;
                    
                    
  (**(code **)(*(int *)(iVar3 + 0x8884) + 0x138))(*(undefined4 *)(iVar3 + 0x85ac),0,0,0);
  return;
}

/* _gliAttachDrawable @ 0x107ad8 (8 bytes) */
void _gliAttachDrawable(glContext, forwardedArg2, forwardedArg3, forwardedArg4)
  undefined4 glContext;
  undefined4 forwardedArg2;
  undefined4 forwardedArg3;
  undefined4 forwardedArg4;
{
  _gliAttachDrawableWithOptions(glContext,forwardedArg2,forwardedArg3,forwardedArg4,0);
  return;
}

/* _gliSwapBuffers @ 0x107ae0 (664 bytes) */
void _gliSwapBuffers(int glContext,double forwardedFloatArg1,double floatArg2,double floatArg3,double floatArg4,double floatArg5,double floatArg6,double floatArg7,double floatArg8)
{
  bool stateIsCleanOrFlag;
  char rendererInfoByte79;
  undefined4 errorCode;
  int *dirtyWordCursor;
  int framebufferObjectThenDirtyWord;
  undefined4 incomingR5;
  undefined4 incomingR6;
  undefined4 incomingR7;
  undefined4 incomingR8;
  int matrixFuncDirtyThenCounter;
  uint dirtyBitsThenDispatchFlags;
  int *dirtyFlagWords;
  double f1AfterCall;
  
  if (-1 < *(short *)(glContext + 0x4a10)) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    errorCode = 0x502;
    goto LAB_00107d18;
  }
  if (*(char *)(glContext + 0x7582) == '\0') {
    return;
  }
  matrixFuncDirtyThenCounter = *(int *)(glContext + 0x50ac);
  if (matrixFuncDirtyThenCounter != 0 || (*(uint *)(glContext + 0x505c) & *(uint *)(glContext + 0x50b0)) != 0) {
    _gleUpdateMatrixFunc(glContext);
    forwardedFloatArg1 = f1AfterCall;
  }
  if (*(char *)(glContext + 0x4691) == '\0') goto LAB_00107d44;
  framebufferObjectThenDirtyWord = *(int *)(glContext + 0x744c);
  dirtyFlagWords = (int *)(glContext + 0x310);
  rendererInfoByte79 = *(char *)(*(int *)(glContext + 0x468c) + 0x79);
  if ((framebufferObjectThenDirtyWord != 0) && (*(int *)(framebufferObjectThenDirtyWord + 0xec) != 0)) {
    ((void (*)())_gleUpdateFramebufferCompleteness)(glContext,framebufferObjectThenDirtyWord + 0x10,incomingR5,incomingR6,incomingR7,incomingR8,matrixFuncDirtyThenCounter,forwardedFloatArg1,floatArg2,floatArg3,
               floatArg4,floatArg5,floatArg6,floatArg7,floatArg8);
    *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x80000000;
  }
  if ((*(char *)(glContext + 0x4664) == '\0') && (*(int *)(glContext + 0x5430) == 0)) {
LAB_00107c1c:
    dirtyBitsThenDispatchFlags = *(uint *)(glContext + 0x31c);
  }
  else {
    matrixFuncDirtyThenCounter = 0;
    dirtyWordCursor = (int *)(glContext + 0x324);
    do {
      framebufferObjectThenDirtyWord = *dirtyWordCursor;
      dirtyWordCursor = dirtyWordCursor + 1;
      if (framebufferObjectThenDirtyWord != 0) {
        *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x800000;
        break;
      }
      matrixFuncDirtyThenCounter = matrixFuncDirtyThenCounter + 1;
    } while (matrixFuncDirtyThenCounter < 9);
    dirtyBitsThenDispatchFlags = *(uint *)(glContext + 0x31c);
    if ((dirtyBitsThenDispatchFlags & 0x15555) != 0) {
      if (*(char *)(glContext + 0x2e54) != '\0') {
        _gleUpdateLightRGBASums(glContext,glContext + 0x2c20,0);
      }
      if (*(char *)(glContext + 0x3094) != '\0') {
        _gleUpdateLightRGBASums(glContext,glContext + 0x2e60,1);
      }
      goto LAB_00107c1c;
    }
  }
  stateIsCleanOrFlag = rendererInfoByte79 == '\0';
  if (stateIsCleanOrFlag) {
    dirtyBitsThenDispatchFlags = dirtyBitsThenDispatchFlags & 0x17000000;
  }
  else {
    dirtyBitsThenDispatchFlags = dirtyBitsThenDispatchFlags & 0x17ffffff;
  }
  if (stateIsCleanOrFlag) {
    stateIsCleanOrFlag = ((*dirtyFlagWords == 0 && *(int *)(glContext + 0x314) == 0) && dirtyBitsThenDispatchFlags == 0) &&
            *(int *)(glContext + 800) == 0;
  }
  else {
    stateIsCleanOrFlag = (((*dirtyFlagWords == 0 && *(int *)(glContext + 0x314) == 0) &&
             (*(uint *)(glContext + 0x318) & 0xfffffffd) == 0) && dirtyBitsThenDispatchFlags == 0) &&
            *(int *)(glContext + 800) == 0;
  }
  if (!stateIsCleanOrFlag) {
    if (*(char *)(glContext + 0x85a8) == *(char *)(glContext + 0x85a6)) {
      dirtyBitsThenDispatchFlags = (**(code **)(glContext + 0x4788))
                        (*(undefined4 *)(glContext + 0x4688),glContext + 0x4698,dirtyFlagWords);
      if ((((dirtyBitsThenDispatchFlags & 3) != (uint)*(byte *)(glContext + 0x7580)) ||
          ((dirtyBitsThenDispatchFlags & 4) != (uint)*(byte *)(glContext + 0x7581))) ||
         ((dirtyBitsThenDispatchFlags & 8) != (uint)(*(char *)(glContext + 0x759d) == '\0'))) {
        if ((dirtyBitsThenDispatchFlags & 4) == 0) {
          dirtyBitsThenDispatchFlags = dirtyBitsThenDispatchFlags & 0xfffffffe;
          *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x10000000;
        }
        _gleUpdateDispatchCodeChange(glContext,dirtyBitsThenDispatchFlags);
        if (*(char *)(glContext + 0x759d) == '\0') {
          if (*(int *)(glContext + 0x7574) != 0) {
            return;
          }
          errorCode = 0x506;
LAB_00107d18:
          *(undefined4 *)(glContext + 0x7574) = errorCode;
          return;
        }
      }
    }
    else {
      _gleSwitchToNonRevertRenderer(glContext);
    }
    matrixFuncDirtyThenCounter = 0x13;
    do {
      *dirtyFlagWords = 0;
      dirtyFlagWords = dirtyFlagWords + 1;
      matrixFuncDirtyThenCounter = matrixFuncDirtyThenCounter + -1;
    } while (matrixFuncDirtyThenCounter != 0);
  }
LAB_00107d44:
                    
                    
  (**(code **)(glContext + 0x46f8))(*(undefined4 *)(glContext + 0x4688));
  return;
}

