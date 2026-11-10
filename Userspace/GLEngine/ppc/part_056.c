#include "decls.h"

/* _gleVPBeginQuadStripTCL @ 0x1071ac (52 bytes) */
void _gleVPBeginQuadStripTCL(param_1)
  int param_1;
{
  undefined *puVar1;
  
  puVar1 = PTR__gleVPFlushTriQuadStripTCL_0011161c;
  *(undefined4 *)(param_1 + 0x4858) = *(undefined4 *)(param_1 + 0x4854);
  *(undefined **)(param_1 + 0x4a0c) = puVar1;
  *(undefined **)(param_1 + 0x4a08) = PTR__gleRenderQuadStripTCLFunc_0011226c;
  return;
}

/* _gleVPBeginPolygonTCL @ 0x1071e0 (60 bytes) */
void _gleVPBeginPolygonTCL(param_1)
  int param_1;
{
  undefined *puVar1;
  undefined *puVar2;
  
  *(undefined1 *)(param_1 + 0x4a18) = 0;
  puVar2 = PTR__gleRenderPolygonTCLFunc_00112250;
  puVar1 = PTR__gleVPFlushPolygonTCL_00111614;
  *(undefined4 *)(param_1 + 0x4858) = *(undefined4 *)(param_1 + 0x4854);
  *(undefined **)(param_1 + 0x4a0c) = puVar1;
  *(undefined **)(param_1 + 0x4a08) = puVar2;
  return;
}

/* _gleVPBeginPointsTCLRDirty @ 0x10721c (52 bytes) */
void _gleVPBeginPointsTCLRDirty(param_1)
  int param_1;
{
  undefined *puVar1;
  
  puVar1 = PTR__gleVPFlushAtomicTCLRDirty_00111610;
  *(undefined4 *)(param_1 + 0x4858) = *(undefined4 *)(param_1 + 0x4854);
  *(undefined **)(param_1 + 0x4a0c) = puVar1;
  *(undefined **)(param_1 + 0x4a08) = PTR__gleRenderPointsTCLFunc_0011223c;
  return;
}

/* _gleVPBeginLinesTCLRDirty @ 0x107250 (52 bytes) */
void _gleVPBeginLinesTCLRDirty(param_1)
  int param_1;
{
  undefined *puVar1;
  
  puVar1 = PTR__gleVPFlushAtomicTCLRDirty_00111610;
  *(undefined4 *)(param_1 + 0x4858) = *(undefined4 *)(param_1 + 0x4854);
  *(undefined **)(param_1 + 0x4a0c) = puVar1;
  *(undefined **)(param_1 + 0x4a08) = PTR__gleRenderLinesTCLFunc_00112214;
  return;
}

/* _gleVPBeginLineLoopTCLRDirty @ 0x107284 (60 bytes) */
void _gleVPBeginLineLoopTCLRDirty(param_1)
  int param_1;
{
  undefined *puVar1;
  undefined *puVar2;
  
  *(undefined1 *)(param_1 + 0x4a18) = 0;
  puVar2 = PTR__gleRenderLineLoopTCLFunc_001121d4;
  puVar1 = PTR__gleVPFlushLineLoopTCLRDirty_0011160c;
  *(undefined4 *)(param_1 + 0x4858) = *(undefined4 *)(param_1 + 0x4854);
  *(undefined **)(param_1 + 0x4a0c) = puVar1;
  *(undefined **)(param_1 + 0x4a08) = puVar2;
  return;
}

/* _gleVPBeginLineStripTCLRDirty @ 0x1072c0 (60 bytes) */
void _gleVPBeginLineStripTCLRDirty(param_1)
  int param_1;
{
  undefined *puVar1;
  undefined *puVar2;
  
  *(undefined1 *)(param_1 + 0x4a18) = 0;
  puVar2 = PTR__gleRenderLineStripTCLFunc_001121f4;
  puVar1 = PTR__gleVPFlushLineStripTCLRDirty_00111608;
  *(undefined4 *)(param_1 + 0x4858) = *(undefined4 *)(param_1 + 0x4854);
  *(undefined **)(param_1 + 0x4a0c) = puVar1;
  *(undefined **)(param_1 + 0x4a08) = puVar2;
  return;
}

/* _gleVPBeginTrianglesTCLRDirty @ 0x1072fc (52 bytes) */
void _gleVPBeginTrianglesTCLRDirty(param_1)
  int param_1;
{
  undefined *puVar1;
  
  puVar1 = PTR__gleVPFlushAtomicTCLRDirty_00111610;
  *(undefined4 *)(param_1 + 0x4858) = *(undefined4 *)(param_1 + 0x4854);
  *(undefined **)(param_1 + 0x4a0c) = puVar1;
  *(undefined **)(param_1 + 0x4a08) = PTR__gleRenderTrianglesTCLFunc_001122d4;
  return;
}

/* _gleVPBeginTriangleStripTCLRDirty @ 0x107330 (52 bytes) */
void _gleVPBeginTriangleStripTCLRDirty(param_1)
  int param_1;
{
  undefined *puVar1;
  
  puVar1 = PTR__gleVPFlushTriQuadStripTCLRDirty_00111604;
  *(undefined4 *)(param_1 + 0x4858) = *(undefined4 *)(param_1 + 0x4854);
  *(undefined **)(param_1 + 0x4a0c) = puVar1;
  *(undefined **)(param_1 + 0x4a08) = PTR__gleRenderTriangleStripTCLFunc_001122b8;
  return;
}

/* _gleVPBeginTriangleFanTCLRDirty @ 0x107364 (52 bytes) */
void _gleVPBeginTriangleFanTCLRDirty(param_1)
  int param_1;
{
  undefined *puVar1;
  
  puVar1 = PTR__gleVPFlushTriangleFanTCLRDirty_00111600;
  *(undefined4 *)(param_1 + 0x4858) = *(undefined4 *)(param_1 + 0x4854);
  *(undefined **)(param_1 + 0x4a0c) = puVar1;
  *(undefined **)(param_1 + 0x4a08) = PTR__gleRenderTriangleFanTCLFunc_00112298;
  return;
}

/* _gleVPBeginQuadsTCLRDirty @ 0x107398 (52 bytes) */
void _gleVPBeginQuadsTCLRDirty(param_1)
  int param_1;
{
  undefined *puVar1;
  
  puVar1 = PTR__gleVPFlushAtomicTCLRDirty_00111610;
  *(undefined4 *)(param_1 + 0x4858) = *(undefined4 *)(param_1 + 0x4854);
  *(undefined **)(param_1 + 0x4a0c) = puVar1;
  *(undefined **)(param_1 + 0x4a08) = PTR__gleRenderQuadsTCLFunc_00112280;
  return;
}

/* _gleVPBeginQuadStripTCLRDirty @ 0x1073cc (52 bytes) */
void _gleVPBeginQuadStripTCLRDirty(param_1)
  int param_1;
{
  undefined *puVar1;
  
  puVar1 = PTR__gleVPFlushTriQuadStripTCLRDirty_00111604;
  *(undefined4 *)(param_1 + 0x4858) = *(undefined4 *)(param_1 + 0x4854);
  *(undefined **)(param_1 + 0x4a0c) = puVar1;
  *(undefined **)(param_1 + 0x4a08) = PTR__gleRenderQuadStripTCLFunc_0011226c;
  return;
}

/* _gleVPBeginPolygonTCLRDirty @ 0x107400 (60 bytes) */
void _gleVPBeginPolygonTCLRDirty(param_1)
  int param_1;
{
  undefined *puVar1;
  undefined *puVar2;
  
  *(undefined1 *)(param_1 + 0x4a18) = 0;
  puVar2 = PTR__gleRenderPolygonTCLFunc_00112250;
  puVar1 = PTR__gleVPFlushPolygonTCLRDirty_001115fc;
  *(undefined4 *)(param_1 + 0x4858) = *(undefined4 *)(param_1 + 0x4854);
  *(undefined **)(param_1 + 0x4a0c) = puVar1;
  *(undefined **)(param_1 + 0x4a08) = puVar2;
  return;
}

/* _gleVPEmulate @ 0x10743c (340 bytes) */
int _gleVPEmulate(param_1, param_2)
  int param_1;
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
  
  iVar8 = *(int *)(param_1 + 0x4a5c);
  iVar7 = *(int *)(param_1 + 0x4864);
  if (*(int *)(param_1 + 0x5434) == 0) {
    uVar5 = *(undefined4 *)(*(int *)(param_1 + 0x5420) + 0x4e0);
    iVar4 = *(int *)(*(int *)(param_1 + 0x5420) + 0x4e4);
  }
  else {
    iVar4 = *(int *)(*(int *)(param_1 + 0x5430) + 0x20);
    uVar5 = *(undefined4 *)(iVar4 + 0x51c);
    iVar4 = *(int *)(iVar4 + 0x4dc);
  }
  uVar3 = 0;
  if (iVar4 != 0) {
    *(undefined4 *)(iVar8 + 0xd8c) = *(undefined4 *)(param_1 + 0x4854);
    *(int *)(iVar8 + 0xd9c) = param_1;
    *(int *)(iVar8 + 0xd88) = iVar7;
    uVar2 = *(undefined4 *)(iVar4 + 0xb0);
    *(undefined4 *)(iVar8 + 0xd98) = uVar5;
    *(undefined4 *)(iVar8 + 0xd90) = uVar2;
    *(int *)(iVar8 + 0xd94) = param_1 + 0x360;
    _PPEmulatorAttachProgram(iVar8,iVar4);
    *(undefined4 *)(iVar4 + 0xb8) = 0x100;
    uVar3 = _PPEmulatorRun(iVar8,param_2);
    iVar8 = param_2;
    if (*(char *)(param_1 + 0x316a) != '\0') {
      for (; iVar8 != 0; iVar8 = iVar8 + -1) {
        dVar10 = (double)(**(double ( **)(int,double))(param_1 + 0x4fe4))(param_1, (double)*(float *)(iVar7 + 0x5c));
        *(float *)(iVar7 + 0x4c) = (float)dVar10;
        iVar7 = iVar7 + 0x100;
      }
    }
    if (*(int *)(param_1 + 0x34d0) != 0x1b021b02) {
      uVar9 = 0;
      iVar7 = *(int *)(param_1 + 0x30b0);
      if (0 < param_2) {
        pbVar6 = (byte *)(*(int *)(param_1 + 0x4864) + 0x7c);
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
double _gleSetWindowPos(int param_1,float fparam_1,float fparam_2,double fparam_3)
{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  float fVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  double dVar10;
  
  fVar5 = FLOAT_00108e50;
  dVar10 = (double)FLOAT_00108e50;
  *(undefined1 *)(param_1 + 0x2ef) = 1;
  iVar6 = *(int *)(param_1 + 0x4854);
  *(undefined4 *)(iVar6 + -0x184) = *(undefined4 *)(param_1 + 0x2ec);
  *(undefined1 *)(iVar6 + -0x181) = 0;
  *(float *)(param_1 + 0x2e0) = (float)fparam_1;
  *(float *)(param_1 + 0x2e4) = (float)fparam_2;
  if (fparam_3 < dVar10) {
    dVar10 = *(double *)(param_1 + 0x1b90);
  }
  else if (1.0 < fparam_3) {
    dVar10 = *(double *)(param_1 + 0x1b98);
  }
  else {
    dVar10 = fparam_3 * (*(double *)(param_1 + 0x1b98) - *(double *)(param_1 + 0x1b90)) +
             *(double *)(param_1 + 0x1b90);
  }
  *(float *)(param_1 + 0x2e8) = (float)dVar10;
  *(undefined4 *)(iVar6 + -500) = 0x3f800000;
  if (*(short *)(param_1 + 0x3166) == -0x7baf) {
    dVar10 = (double)(**(double ( **)(int,double))(param_1 + 0x4fe4))(param_1, (double)*(float *)(param_1 + 0x2cc));
    *(float *)(iVar6 + -0x1b4) = (float)dVar10;
    *(undefined4 *)(iVar6 + -0x1d8) = *(undefined4 *)(param_1 + 0x2cc);
  }
  else {
    dVar10 = (double)(**(double ( **)(int,double))(param_1 + 0x4fe4))(param_1, (double)FLOAT_00108e50);
    *(float *)(iVar6 + -0x1d8) = fVar5;
    *(float *)(iVar6 + -0x1b4) = (float)dVar10;
  }
  uVar2 = *(undefined4 *)(param_1 + 0x2b4);
  iVar9 = 8;
  uVar3 = *(undefined4 *)(param_1 + 0x2b8);
  *(undefined4 *)(iVar6 + -0x1c0) = *(undefined4 *)(param_1 + 0x2b0);
  *(undefined4 *)(iVar6 + -0x1bc) = uVar2;
  *(undefined4 *)(iVar6 + -0x1b8) = uVar3;
  *(undefined8 *)(iVar6 + -0x1d0) = *(undefined8 *)(param_1 + 0x2a0);
  *(undefined8 *)(iVar6 + -0x1c8) = *(undefined8 *)(param_1 + 0x2a8);
  *(undefined8 *)(iVar6 + -0x1b0) = *(undefined8 *)(param_1 + 0x2c0);
  *(undefined4 *)(iVar6 + -0x1a8) = *(undefined4 *)(param_1 + 0x2c8);
  iVar7 = iVar6 + -0x200;
  iVar8 = param_1;
  do {
    puVar1 = (undefined4 *)(iVar8 + 0x120);
    uVar2 = *(undefined4 *)(iVar8 + 0x124);
    uVar3 = *(undefined4 *)(iVar8 + 0x128);
    uVar4 = *(undefined4 *)(iVar8 + 300);
    iVar8 = iVar8 + 0x10;
    *(undefined4 *)(iVar7 + 0x80) = *puVar1;
    *(undefined4 *)(iVar7 + 0x84) = uVar2;
    *(undefined4 *)(iVar7 + 0x88) = uVar3;
    *(undefined4 *)(iVar7 + 0x8c) = uVar4;
    iVar7 = iVar7 + 0x10;
    iVar9 = iVar9 + -1;
  } while (iVar9 != 0);
  if (*(int *)(param_1 + 0x4e1c) == 0x1c02) {
    dVar10 = (double)_gleSelectHit(param_1,iVar6 + -0x200);
    return dVar10;
  }
  return dVar10;
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
void _gliGetAttribute(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  if (param_1 == 0) {
    return;
  }
  _gleGetAttrib(param_1,param_2,param_3);
  return;
}

/* _gliSetAttribute @ 0x1077f0 (72 bytes) */
void _gliSetAttribute(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  if (param_1 != 0) {
    _gleSetAttrib(param_1,param_2,param_3);
    _gleUpdateState(param_1);
    return;
  }
  return;
}

/* _gliCopyAttributes @ 0x107838 (120 bytes) */
void _gliCopyAttributes(param_1, param_2)
  int param_1;
  int param_2;
{
  uint uVar1;
  uint uVar2;
  undefined1 auStack_2c60 [11340];
  
  if ((param_1 != 0) && (param_2 != 0)) {
    uVar2 = 1;
    do {
      _gleGetAttrib(param_1,uVar2,auStack_2c60);
      uVar1 = uVar2 << 1;
      _gleSetAttrib(param_2,uVar2,auStack_2c60);
      uVar2 = uVar1;
    } while (uVar1 < 0xfffff);
    _gleUpdateState(param_2);
  }
  return;
}

/* _gliSwitchPlugin @ 0x1078b0 (332 bytes) */
double _gliSwitchPlugin(param_1, param_2)
  int param_1;
  int param_2;
{
  uint uVar1;
  undefined *puVar2;
  undefined4 uVar3;
  int iVar4;
  double fparam_1;
  double fparam_1_00;
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
  
  _gleSynchronizePluginFramebuffer(param_1);
  _gleSynchronizePluginTextures(param_1);
  _gleSynchronizePluginBuffers(param_1);
  *(char *)(param_1 + 0x85a8) = (char)param_2;
  iVar4 = param_2 * 0x2e0 + param_1;
  uVar3 = *(undefined4 *)(iVar4 + 0x85ac);
  *(int *)(param_1 + 0x468c) = iVar4 + 0x85b0;
  *(undefined4 *)(param_1 + 0x4688) = uVar3;
  _memcpy(param_1 + 0x4754,*(int *)(iVar4 + 0x8884) + 0x114,0xf4);
  *(undefined4 *)(param_1 + 800) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x310) = 0xffffffff;
  *(uint *)(param_1 + 0x314) = *(uint *)(param_1 + 0x314) | 0x3ffffff;
  *(uint *)(param_1 + 0x318) = *(uint *)(param_1 + 0x318) | 0xfffffffd;
  *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x7ffffff;
  ((void (*)())_gleUpdateDepthRangeData)(param_1,fparam_1,in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8,in_stack_ffffffb8,
             in_stack_ffffffc0,in_stack_ffffffc8,in_stack_ffffffd0,in_stack_ffffffd8);
  _gleUpdatePolyMode(param_1);
  ((void (*)())_gleUpdateViewScissorData)(param_1,fparam_1_00,in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8);
  _gleUpdateTextureTransform(param_1);
  puVar2 = PTR__gleSetClipInterpFunc_00112038;
  *(undefined **)(param_1 + 0x49c8) = PTR__gleSetEyeInterpFunc_0011203c;
  *(undefined **)(param_1 + 0x49cc) = puVar2;
  _gleUpdatePrimitiveData(param_1);
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0xc) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0xc) =
       PTR__glArrayElement_Exec_001120e8;
  _gleUpdateDrawArraysFuncs(param_1);
  _gleSelectVertexSubmitFunc(param_1);
  *(undefined4 *)(param_1 + 0x488c) = 0;
  *(undefined4 *)(param_1 + 0x4890) = 0;
  *(undefined4 *)(param_1 + 0x4894) = 0;
  _gleResetVertexArrays(param_1);
  return;
}

/* _gliDetachRevert @ 0x1079fc (220 bytes) */
void _gliDetachRevert(param_1)
  int param_1;
{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = (uint)*(byte *)(param_1 + 0x85a5);
  if (uVar2 == *(byte *)(param_1 + 0x85a8)) {
    return;
  }
  if (uVar2 == 0xff) {
    return;
  }
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x938) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x938) =
       PTR__glSwap_Exec_0011211c;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x168) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x168) =
       PTR__glFlush_Exec_00112118;
  iVar3 = uVar2 * 0x2e0 + param_1;
  uVar2 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x164) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar2 | *(uint *)(param_1 + 0x4684) & ~uVar2) + 0x164) =
       PTR__glFinish_Exec_00112114;
                    
                    
  (**(code **)(*(int *)(iVar3 + 0x8884) + 0x138))(*(undefined4 *)(iVar3 + 0x85ac),0,0,0);
  return;
}

/* _gliAttachDrawable @ 0x107ad8 (8 bytes) */
void _gliAttachDrawable(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  _gliAttachDrawableWithOptions(param_1,param_2,param_3,param_4,0);
  return;
}

/* _gliSwapBuffers @ 0x107ae0 (664 bytes) */
void _gliSwapBuffers(int param_1,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  bool bVar1;
  char cVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  undefined4 in_r5;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  int iVar6;
  uint uVar7;
  int *piVar8;
  double extraout_f1;
  
  if (-1 < *(short *)(param_1 + 0x4a10)) {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar3 = 0x502;
    goto LAB_00107d18;
  }
  if (*(char *)(param_1 + 0x7582) == '\0') {
    return;
  }
  iVar6 = *(int *)(param_1 + 0x50ac);
  if (iVar6 != 0 || (*(uint *)(param_1 + 0x505c) & *(uint *)(param_1 + 0x50b0)) != 0) {
    _gleUpdateMatrixFunc(param_1);
    fparam_1 = extraout_f1;
  }
  if (*(char *)(param_1 + 0x4691) == '\0') goto LAB_00107d44;
  iVar5 = *(int *)(param_1 + 0x744c);
  piVar8 = (int *)(param_1 + 0x310);
  cVar2 = *(char *)(*(int *)(param_1 + 0x468c) + 0x79);
  if ((iVar5 != 0) && (*(int *)(iVar5 + 0xec) != 0)) {
    ((void (*)())_gleUpdateFramebufferCompleteness)(param_1,iVar5 + 0x10,in_r5,in_r6,in_r7,in_r8,iVar6,fparam_1,fparam_2,fparam_3,
               fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
    *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x80000000;
  }
  if ((*(char *)(param_1 + 0x4664) == '\0') && (*(int *)(param_1 + 0x5430) == 0)) {
LAB_00107c1c:
    uVar7 = *(uint *)(param_1 + 0x31c);
  }
  else {
    iVar6 = 0;
    piVar4 = (int *)(param_1 + 0x324);
    do {
      iVar5 = *piVar4;
      piVar4 = piVar4 + 1;
      if (iVar5 != 0) {
        *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x800000;
        break;
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < 9);
    uVar7 = *(uint *)(param_1 + 0x31c);
    if ((uVar7 & 0x15555) != 0) {
      if (*(char *)(param_1 + 0x2e54) != '\0') {
        _gleUpdateLightRGBASums(param_1,param_1 + 0x2c20,0);
      }
      if (*(char *)(param_1 + 0x3094) != '\0') {
        _gleUpdateLightRGBASums(param_1,param_1 + 0x2e60,1);
      }
      goto LAB_00107c1c;
    }
  }
  bVar1 = cVar2 == '\0';
  if (bVar1) {
    uVar7 = uVar7 & 0x17000000;
  }
  else {
    uVar7 = uVar7 & 0x17ffffff;
  }
  if (bVar1) {
    bVar1 = ((*piVar8 == 0 && *(int *)(param_1 + 0x314) == 0) && uVar7 == 0) &&
            *(int *)(param_1 + 800) == 0;
  }
  else {
    bVar1 = (((*piVar8 == 0 && *(int *)(param_1 + 0x314) == 0) &&
             (*(uint *)(param_1 + 0x318) & 0xfffffffd) == 0) && uVar7 == 0) &&
            *(int *)(param_1 + 800) == 0;
  }
  if (!bVar1) {
    if (*(char *)(param_1 + 0x85a8) == *(char *)(param_1 + 0x85a6)) {
      uVar7 = (**(code **)(param_1 + 0x4788))
                        (*(undefined4 *)(param_1 + 0x4688),param_1 + 0x4698,piVar8);
      if ((((uVar7 & 3) != (uint)*(byte *)(param_1 + 0x7580)) ||
          ((uVar7 & 4) != (uint)*(byte *)(param_1 + 0x7581))) ||
         ((uVar7 & 8) != (uint)(*(char *)(param_1 + 0x759d) == '\0'))) {
        if ((uVar7 & 4) == 0) {
          uVar7 = uVar7 & 0xfffffffe;
          *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x10000000;
        }
        _gleUpdateDispatchCodeChange(param_1,uVar7);
        if (*(char *)(param_1 + 0x759d) == '\0') {
          if (*(int *)(param_1 + 0x7574) != 0) {
            return;
          }
          uVar3 = 0x506;
LAB_00107d18:
          *(undefined4 *)(param_1 + 0x7574) = uVar3;
          return;
        }
      }
    }
    else {
      _gleSwitchToNonRevertRenderer(param_1);
    }
    iVar6 = 0x13;
    do {
      *piVar8 = 0;
      piVar8 = piVar8 + 1;
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
  }
LAB_00107d44:
                    
                    
  (**(code **)(param_1 + 0x46f8))(*(undefined4 *)(param_1 + 0x4688));
  return;
}

