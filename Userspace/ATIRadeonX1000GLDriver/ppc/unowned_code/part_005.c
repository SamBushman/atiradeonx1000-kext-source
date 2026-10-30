#include "decls.h"

/* IrMinInt__fold @ 0x1d0528 (32 bytes) */
int IrMinInt__fold(param_1, param_2, param_3)
  undefined4 param_1;
  int *param_2;
  int param_3;
{
  int iVar1;
  
  iVar1 = *(int *)(param_3 + 4);
  if (*(int *)(param_3 + 8) <= *(int *)(param_3 + 4)) {
    iVar1 = *(int *)(param_3 + 8);
  }
  *param_2 = iVar1;
  return 1;
}

/* IrMinUInt__fold @ 0x1d0548 (32 bytes) */
int IrMinUInt__fold(param_1, param_2, param_3)
  undefined4 param_1;
  uint *param_2;
  int param_3;
{
  uint uVar1;
  
  uVar1 = *(uint *)(param_3 + 4);
  if (*(uint *)(param_3 + 8) <= *(uint *)(param_3 + 4)) {
    uVar1 = *(uint *)(param_3 + 8);
  }
  *param_2 = uVar1;
  return 1;
}

/* IrF2Int__fold @ 0x1d0568 (28 bytes) */
int IrF2Int__fold(param_1, param_2, param_3)
  undefined4 param_1;
  int *param_2;
  int param_3;
{
  *param_2 = (int)*(float *)(param_3 + 4);
  return 1;
}

/* IrF2UInt__fold @ 0x1d0584 (28 bytes) */
int IrF2UInt__fold(param_1, param_2, param_3)
  undefined4 param_1;
  int *param_2;
  int param_3;
{
  *param_2 = (int)*(float *)(param_3 + 4);
  return 1;
}

/* IrMovFloat__fold @ 0x1d05a0 (16 bytes) */
int IrMovFloat__fold(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 *param_2;
  int param_3;
{
  *param_2 = *(undefined4 *)(param_3 + 4);
  return 1;
}

/* IrMulIEEE__fold @ 0x1d096c (24 bytes) */
int IrMulIEEE__fold(param_1, param_2, param_3)
  undefined4 param_1;
  float *param_2;
  int param_3;
{
  *param_2 = *(float *)(param_3 + 4) * *(float *)(param_3 + 8);
  return 1;
}

/* IrMulHiInt__fold @ 0x1d0984 (24 bytes) */
int IrMulHiInt__fold(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 *param_2;
  int param_3;
{
  *param_2 = (int)((ulonglong)((longlong)*(int *)(param_3 + 4) * (longlong)*(int *)(param_3 + 8)) >>
                  0x20);
  return 1;
}

/* IrMulHiUInt__fold @ 0x1d099c (24 bytes) */
int IrMulHiUInt__fold(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 *param_2;
  int param_3;
{
  *param_2 = (int)((ulonglong)*(uint *)(param_3 + 4) * (ulonglong)*(uint *)(param_3 + 8) >> 0x20);
  return 1;
}

/* IrDot2AddIEEE__foldVector @ 0x1d0b6c (40 bytes) */
int IrDot2AddIEEE__foldVector(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  float *param_2;
  float *param_3;
  float *param_4;
  int param_5;
{
  *param_2 = *param_3 * *param_4 + param_3[1] * param_4[1] + *(float *)(param_5 + 8);
  return;
}

/* IrSetEFloat__fold @ 0x1d0cb4 (36 bytes) */
int IrSetEFloat__fold(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 *param_2;
  int param_3;
{
  undefined4 uVar1;
  
  uVar1 = 0x3f800000;
  if (*(float *)(param_3 + 4) != *(float *)(param_3 + 8)) {
    uVar1 = 0;
  }
  *param_2 = uVar1;
  return 1;
}

/* IrSetGEFloat__fold @ 0x1d0d1c (44 bytes) */
int IrSetGEFloat__fold(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 *param_2;
  int param_3;
{
  undefined4 uVar1;
  
  if (*(float *)(param_3 + 4) < *(float *)(param_3 + 8)) {
    uVar1 = 0;
  }
  else {
    uVar1 = 0x3f800000;
  }
  *param_2 = uVar1;
  return 1;
}

/* orph_1d0d38 @ 0x1d0d38 (16 bytes) */
int orph_1d0d38(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  *param_2 = 0;
  return 1;
}

/* IrSetNEFloat__fold @ 0x1d0d48 (36 bytes) */
int IrSetNEFloat__fold(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 *param_2;
  int param_3;
{
  undefined4 uVar1;
  
  uVar1 = 0x3f800000;
  if (*(float *)(param_3 + 4) == *(float *)(param_3 + 8)) {
    uVar1 = 0;
  }
  *param_2 = uVar1;
  return 1;
}

/* IrMovaRoundFloat__vslot6_getMovaRoundFlag @ 0x1d0d6c (8 bytes) */
int IrMovaRoundFloat__vslot6_getMovaRoundFlag()
{
  return 1;
}

/* IrMovaRound__vslot6_getMovaRoundFlag @ 0x1d0d74 (8 bytes) */
int IrMovaRound__vslot6_getMovaRoundFlag()
{
  return 1;
}

/* IrDot4IEEE__foldVector @ 0x1d0d7c (56 bytes) */
int IrDot4IEEE__foldVector(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  float *param_2;
  float *param_3;
  float *param_4;
{
  *param_2 = param_3[3] * param_4[3] +
             param_3[2] * param_4[2] + *param_3 * *param_4 + param_3[1] * param_4[1];
  return;
}

/* IrScatter__init @ 0x1d0db4 (4 bytes) */
int IrScatter__init(param_1, param_2)
  int param_1;
  int param_2;
{
  *(undefined4 *)(param_2 + 0x84) = 3;
  *(undefined4 *)(param_2 + 0x80) = 1;
  *(undefined4 *)(param_1 + 4) = 9;
  return;
}

/* IrMovaRoundFloat__init @ 0x1d0db8 (4 bytes) */
int IrMovaRoundFloat__init(param_1, param_2)
  int param_1;
  int param_2;
{
  *(undefined4 *)(param_2 + 0x84) = 1;
  *(undefined4 *)(param_2 + 0x80) = 1;
  *(undefined4 *)(param_1 + 4) = 6;
  return;
}

/* IrMovaRound__init @ 0x1d0dbc (4 bytes) */
int IrMovaRound__init(param_1, param_2)
  int param_1;
  int param_2;
{
  *(undefined4 *)(param_2 + 0x84) = 1;
  *(undefined4 *)(param_2 + 0x80) = 1;
  *(undefined4 *)(param_1 + 4) = 6;
  return;
}

/* IrMovaFloor__init @ 0x1d0dc0 (4 bytes) */
int IrMovaFloor__init(param_1, param_2)
  int param_1;
  int param_2;
{
  *(undefined4 *)(param_2 + 0x84) = 1;
  *(undefined4 *)(param_2 + 0x80) = 1;
  *(undefined4 *)(param_1 + 4) = 6;
  return;
}

/* IrMovaFlr__init @ 0x1d0dc4 (4 bytes) */
int IrMovaFlr__init(param_1, param_2)
  int param_1;
  int param_2;
{
  *(undefined4 *)(param_2 + 0x84) = 1;
  *(undefined4 *)(param_2 + 0x80) = 1;
  *(undefined4 *)(param_1 + 4) = 6;
  return;
}

/* IrMovaFloorGprInt__init @ 0x1d0dc8 (4 bytes) */
int IrMovaFloorGprInt__init(param_1, param_2)
  int param_1;
  int param_2;
{
  *(undefined4 *)(param_2 + 0x84) = 1;
  *(undefined4 *)(param_2 + 0x80) = 1;
  *(undefined4 *)(param_1 + 4) = 6;
  return;
}

/* IrMovaFloorInt__init @ 0x1d0dcc (4 bytes) */
int IrMovaFloorInt__init(param_1, param_2)
  int param_1;
  int param_2;
{
  *(undefined4 *)(param_2 + 0x84) = 1;
  *(undefined4 *)(param_2 + 0x80) = 1;
  *(undefined4 *)(param_1 + 4) = 6;
  return;
}

/* IrAllocPos__init @ 0x1d0dd0 (4 bytes) */
int IrAllocPos__init(param_1, param_2)
  int param_1;
  int param_2;
{
  *(undefined4 *)(param_2 + 0x84) = 0;
  *(undefined4 *)(param_2 + 300) = 0;
  *(undefined4 *)(param_2 + 0x80) = 1;
  *(uint *)(param_2 + 0x14) = *(uint *)(param_2 + 0x14) | 0x18000;
  *(undefined4 *)(param_1 + 4) = 1;
  return;
}

/* IrAllocMem__init @ 0x1d0dd4 (4 bytes) */
int IrAllocMem__init(param_1, param_2)
  int param_1;
  int param_2;
{
  *(undefined4 *)(param_2 + 0x84) = 0;
  *(undefined4 *)(param_2 + 300) = 0;
  *(undefined4 *)(param_2 + 0x80) = 1;
  *(uint *)(param_2 + 0x14) = *(uint *)(param_2 + 0x14) | 0x18000;
  *(undefined4 *)(param_1 + 4) = 1;
  return;
}

/* IrAllocColor__init @ 0x1d0dd8 (4 bytes) */
int IrAllocColor__init(param_1, param_2)
  int param_1;
  int param_2;
{
  *(undefined4 *)(param_2 + 0x84) = 0;
  *(undefined4 *)(param_2 + 300) = 0;
  *(undefined4 *)(param_2 + 0x80) = 1;
  *(uint *)(param_2 + 0x14) = *(uint *)(param_2 + 0x14) | 0x18000;
  *(undefined4 *)(param_1 + 4) = 1;
  return;
}

/* IrAllocInterp__init @ 0x1d0ddc (4 bytes) */
int IrAllocInterp__init(param_1, param_2)
  int param_1;
  int param_2;
{
  *(undefined4 *)(param_2 + 0x84) = 0;
  *(undefined4 *)(param_2 + 300) = 0;
  *(undefined4 *)(param_2 + 0x80) = 1;
  *(uint *)(param_2 + 0x14) = *(uint *)(param_2 + 0x14) | 0x18000;
  *(undefined4 *)(param_1 + 4) = 1;
  return;
}

/* IrKillE__init @ 0x1d0de0 (4 bytes) */
int IrKillE__init(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  OpcodeSetup__mode7(param_1,param_2,param_3);
  return;
}

/* IrKillGT__init @ 0x1d0de4 (4 bytes) */
int IrKillGT__init(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  OpcodeSetup__mode7(param_1,param_2,param_3);
  return;
}

/* IrKillGE__init @ 0x1d0de8 (4 bytes) */
int IrKillGE__init(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  OpcodeSetup__mode7(param_1,param_2,param_3);
  return;
}

/* IrKillNE__init @ 0x1d0dec (4 bytes) */
int IrKillNE__init(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  OpcodeSetup__mode7(param_1,param_2,param_3);
  return;
}

/* IrKillOne__init @ 0x1d0df0 (4 bytes) */
int IrKillOne__init(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  OpcodeSetup__mode7(param_1,param_2,param_3);
  return;
}

/* IrCmp1D__init @ 0x1d0df4 (4 bytes) */
int IrCmp1D__init(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  OpcodeSetup__mode8(param_1,param_2,param_3);
  return;
}

/* IrWhileStart__init @ 0x1d0df8 (4 bytes) */
int IrWhileStart__init(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  OpcodeSetup__mode5(param_1,param_2,param_3);
  return;
}

/* IrLoopIndex__init @ 0x1d0dfc (4 bytes) */
int IrLoopIndex__init(param_1, param_2)
  int param_1;
  int param_2;
{
  *(undefined4 *)(param_2 + 0x84) = 1;
  *(undefined4 *)(param_2 + 0x80) = 1;
  *(uint *)(param_2 + 0x14) = *(uint *)(param_2 + 0x14) | 0x18000;
  *(undefined4 *)(param_1 + 4) = 3;
  return;
}

/* IrRet__init @ 0x1d0e00 (4 bytes) */
int IrRet__init(param_1, param_2)
  int param_1;
  int param_2;
{
  *(undefined4 *)(param_2 + 0x84) = 0;
  *(undefined4 *)(param_2 + 0x80) = 0;
  *(uint *)(param_2 + 0x14) = *(uint *)(param_2 + 0x14) | 0x18000;
  *(undefined4 *)(param_1 + 4) = 2;
  return;
}

/* IrDyamicReturn__init @ 0x1d0e04 (4 bytes) */
int IrDyamicReturn__init(param_1, param_2)
  int param_1;
  int param_2;
{
  *(undefined4 *)(param_2 + 0x84) = 0;
  *(undefined4 *)(param_2 + 0x80) = 0;
  *(uint *)(param_2 + 0x14) = *(uint *)(param_2 + 0x14) | 0x18000;
  *(undefined4 *)(param_1 + 4) = 2;
  return;
}

/* IrDyamicReturnSwitch__init @ 0x1d0e08 (4 bytes) */
int IrDyamicReturnSwitch__init(param_1, param_2)
  int param_1;
  int param_2;
{
  *(undefined4 *)(param_2 + 0x84) = 0;
  *(undefined4 *)(param_2 + 0x80) = 0;
  *(uint *)(param_2 + 0x14) = *(uint *)(param_2 + 0x14) | 0x18000;
  *(undefined4 *)(param_1 + 4) = 2;
  return;
}

/* VRegInfo__clone @ 0x1d78a8 (8 bytes) */
int VRegInfo__clone()
{
  return 0;
}

/* VRegInfo__isInterpolator @ 0x1d78b0 (8 bytes) */
int VRegInfo__isInterpolator()
{
  return 0;
}

/* VRegInfo__isExportValue @ 0x1d78b8 (8 bytes) */
int VRegInfo__isExportValue()
{
  return 0;
}

/* VRegInfo__isFixedValueOrVertexRegister @ 0x1d78c0 (8 bytes) */
int VRegInfo__isFixedValueOrVertexRegister()
{
  return 0;
}

/* VRegInfo__isTempValue @ 0x1d78c8 (8 bytes) */
int VRegInfo__isTempValue()
{
  return 0;
}

/* VRegInfo__isLoopIndexedSet @ 0x1d78d0 (8 bytes) */
int VRegInfo__isLoopIndexedSet()
{
  return 0;
}

/* VRegInfo__isResource @ 0x1d78d8 (8 bytes) */
int VRegInfo__isResource()
{
  return 0;
}

/* VRegInfo__vslot9 @ 0x1d78e0 (8 bytes) */
int VRegInfo__vslot9()
{
  return 0;
}

/* VRegInfo__vslot10 @ 0x1d78e8 (8 bytes) */
int VRegInfo__vslot10()
{
  return 0;
}

/* VRegInfo__vslot11 @ 0x1d78f0 (8 bytes) */
int VRegInfo__vslot11()
{
  return 0;
}

/* Interpolator__isInterpolator @ 0x1d78f8 (8 bytes) */
int Interpolator__isInterpolator()
{
  return 1;
}

/* Interpolator__vslot11 @ 0x1d7900 (8 bytes) */
int Interpolator__vslot11(param_1)
  int param_1;
{
  return *(undefined4 *)(param_1 + 0x30);
}

/* FixedValue__isFixedValueOrVertexRegister @ 0x1d7908 (8 bytes) */
int FixedValue__isFixedValueOrVertexRegister()
{
  return 1;
}

/* VertexRegister__isFixedValueOrVertexRegister @ 0x1d7910 (8 bytes) */
int VertexRegister__isFixedValueOrVertexRegister()
{
  return 1;
}

/* TempValue__isTempValue @ 0x1d7918 (8 bytes) */
int TempValue__isTempValue()
{
  return 1;
}

/* ExportValue__isExportValue @ 0x1d7920 (8 bytes) */
int ExportValue__isExportValue()
{
  return 1;
}

/* ExportValue__vslot11 @ 0x1d7928 (8 bytes) */
int ExportValue__vslot11(param_1)
  int param_1;
{
  return *(undefined4 *)(param_1 + 0x30);
}

/* Resource__isResource @ 0x1d7930 (8 bytes) */
int Resource__isResource()
{
  return 1;
}

/* AddrIndexedSet__vslot9 @ 0x1d7938 (8 bytes) */
int AddrIndexedSet__vslot9(param_1)
  int param_1;
{
  return *(undefined4 *)(param_1 + 0x30);
}

/* LoopIndexedSet__isLoopIndexedSet @ 0x1d7940 (8 bytes) */
int LoopIndexedSet__isLoopIndexedSet()
{
  return 1;
}

/* LoopIndexedSet__vslot9 @ 0x1d7948 (8 bytes) */
int LoopIndexedSet__vslot9(param_1)
  int param_1;
{
  return *(undefined4 *)(param_1 + 0x30);
}

/* KhanPs__vslot29 @ 0x1d82c4 (4 bytes) */
int KhanPs__vslot29()
{
  return;
}

