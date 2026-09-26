#include "decls.h"

/* fetch @ 0x97bc3a44 (100 bytes) */
int fetch(param_1)
  unsigned char * param_1;
{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  puVar2 = *(undefined4 **)param_1;
  if (*(int *)(param_1 + 8) != 0) {
    iVar1 = *(int *)(param_1 + 8) + -1;
    *(int *)(param_1 + 8) = iVar1;
    *(undefined4 *)param_1 = puVar2[1];
    if (iVar1 == 0) {
      *(undefined4 *)(param_1 + 4) = 0;
    }
    uVar3 = *puVar2;
    _free(puVar2);
  }
  return uVar3;
}

/* __ZN19ParseWhileLoopStackC2Ev @ 0x97bc3aa8 (4 bytes) */
int __ZN19ParseWhileLoopStackC2Ev(this)
  void *this;
{
  *(undefined4 *)this = 0;
  return;
}

/* __ZN19ParseWhileLoopStackC1Ev @ 0x97bc3aac (4 bytes) */
int __ZN19ParseWhileLoopStackC1Ev(this)
  void *this;
{
  *(undefined4 *)this = 0;
  return;
}

/* __ZN19ParseWhileLoopStackC4Ev @ 0x97bc3ab0 (12 bytes) */
int __ZN19ParseWhileLoopStackC4Ev(this)
  void *this;
{
  *(undefined4 *)this = 0;
  return;
}

/* ParseWhileLoopStack__empty @ 0x97bc3abc (16 bytes) */
int ParseWhileLoopStack__empty(this)
  unsigned char * this;
{
  return *(int *)this == 0;
}

/* ParseWhileLoopStack__push @ 0x97bc3acc (76 bytes) */
int ParseWhileLoopStack__push(this, param_2, param_3)
  unsigned char * this;
  char *param_2;
  char *param_3;
{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  puVar2 = operator_new(0xc);
  uVar1 = *(undefined4 *)this;
  *puVar2 = param_2;
  puVar2[1] = param_3;
  puVar2[2] = uVar1;
  *(undefined4 **)this = puVar2;
  return;
}

/* ParseWhileLoopStack__pop @ 0x97bc3b18 (64 bytes) */
int ParseWhileLoopStack__pop(this)
  unsigned char * this;
{
  void *pvVar1;
  undefined4 uVar2;
  
  pvVar1 = *(void **)this;
  if (pvVar1 != (void *)0x0) {
    uVar2 = *(undefined4 *)((int)pvVar1 + 8);
    __ZdlPv(pvVar1);
    *(undefined4 *)this = uVar2;
  }
  return;
}

/* ParseWhileLoopStack__continueLabel @ 0x97bc3b58 (28 bytes) */
int ParseWhileLoopStack__continueLabel(this)
  unsigned char * this;
{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (*(undefined4 **)this != (undefined4 *)0x0) {
    uVar1 = **(undefined4 **)this;
  }
  return uVar1;
}

/* ParseWhileLoopStack__breakLabel @ 0x97bc3b74 (28 bytes) */
int ParseWhileLoopStack__breakLabel(this)
  unsigned char * this;
{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (*(int *)this != 0) {
    uVar1 = *(undefined4 *)(*(int *)this + 4);
  }
  return uVar1;
}

/* __ZN18ParseFunctionStackC2Ev @ 0x97bc3b90 (4 bytes) */
int __ZN18ParseFunctionStackC2Ev(this)
  void *this;
{
  *(undefined4 *)this = 0;
  return;
}

/* __ZN18ParseFunctionStackC1Ev @ 0x97bc3b94 (4 bytes) */
int __ZN18ParseFunctionStackC1Ev(this)
  void *this;
{
  *(undefined4 *)this = 0;
  return;
}

/* __ZN18ParseFunctionStackC4Ev @ 0x97bc3b98 (12 bytes) */
int __ZN18ParseFunctionStackC4Ev(this)
  void *this;
{
  *(undefined4 *)this = 0;
  return;
}

/* ParseFunctionStack__empty @ 0x97bc3ba4 (16 bytes) */
int ParseFunctionStack__empty(this)
  unsigned char * this;
{
  return *(int *)this == 0;
}

/* ParseFunctionStack__push @ 0x97bc3bb4 (88 bytes) */
int ParseFunctionStack__push(this, param_2)
  unsigned char * this;
  char *param_2;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  puVar1 = operator_new(0x14);
  uVar2 = *(undefined4 *)this;
  *puVar1 = param_2;
  puVar1[2] = 0xffffffff;
  puVar1[4] = uVar2;
  puVar1[3] = 0;
  puVar1[1] = 0;
  *(undefined4 **)this = puVar1;
  return;
}

/* ParseFunctionStack__pop @ 0x97bc3c0c (80 bytes) */
int ParseFunctionStack__pop(this)
  unsigned char * this;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  puVar1 = *(undefined4 **)this;
  if (puVar1 != (undefined4 *)0x0) {
    uVar2 = puVar1[4];
    uVar3 = *puVar1;
    __ZdlPv(puVar1);
    *(undefined4 *)this = uVar2;
  }
  return uVar3;
}

/* ParseFunctionStack__current @ 0x97bc3c5c (28 bytes) */
int ParseFunctionStack__current(this)
  unsigned char * this;
{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (*(undefined4 **)this != (undefined4 *)0x0) {
    uVar1 = **(undefined4 **)this;
  }
  return uVar1;
}

/* ParseFunctionStack__getCurrentNumParams @ 0x97bc3c78 (28 bytes) */
int ParseFunctionStack__getCurrentNumParams(this)
  unsigned char * this;
{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (*(int *)this != 0) {
    uVar1 = *(undefined4 *)(*(int *)this + 4);
  }
  return uVar1;
}

/* ParseFunctionStack__setCurrentNumParams @ 0x97bc3c94 (20 bytes) */
int ParseFunctionStack__setCurrentNumParams(this, param_2)
  unsigned char * this;
  int param_2;
{
  if (*(int *)this == 0) {
    return;
  }
  *(int *)(*(int *)this + 4) = param_2;
  return;
}

/* ParseFunctionStack__getLastParamOpIndex @ 0x97bc3ca8 (28 bytes) */
int ParseFunctionStack__getLastParamOpIndex(this)
  unsigned char * this;
{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (*(int *)this != 0) {
    uVar1 = *(undefined4 *)(*(int *)this + 8);
  }
  return uVar1;
}

/* ParseFunctionStack__setLastParamOpIndex @ 0x97bc3cc4 (20 bytes) */
int ParseFunctionStack__setLastParamOpIndex(this, param_2)
  unsigned char * this;
  int param_2;
{
  if (*(int *)this == 0) {
    return;
  }
  *(int *)(*(int *)this + 8) = param_2;
  return;
}

/* ParseFunctionStack__getCurrentParamList @ 0x97bc3cd8 (28 bytes) */
int ParseFunctionStack__getCurrentParamList(this)
  unsigned char * this;
{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (*(int *)this != 0) {
    uVar1 = *(undefined4 *)(*(int *)this + 0xc);
  }
  return uVar1;
}

/* ParseFunctionStack__setCurrentParamList @ 0x97bc3cf4 (20 bytes) */
int ParseFunctionStack__setCurrentParamList(this, param_2)
  unsigned char * this;
  unsigned char ** param_2;
{
  if (*(int *)this == 0) {
    return;
  }
  *(unsigned char ***)(*(int *)this + 0xc) = param_2;
  return;
}

/* TPPStreamCompiler__getVertex @ 0x97bc3d08 (244 bytes) */
int TPPStreamCompiler__getVertex(this)
  unsigned char * this;
{
  unsigned char * this_00;
  unsigned char * pTVar1;
  unsigned char * this_01;
  unsigned char * this_02;
  
  this_00 = (unsigned char *)GetGlobalPoolAllocator();
  pTVar1 = (unsigned char *)TPoolAllocator__allocate(this_00,0x28);
  *(undefined ***)pTVar1 = &PTR___ZN5TTypeD1Ev_a7b7d808;
  *(undefined4 *)(pTVar1 + 0x20) = 0;
  *(uint *)(pTVar1 + 0x24) = *(uint *)(pTVar1 + 0x24) & 0x801ff | 0x6082000;
  *(undefined4 *)(pTVar1 + 4) = 0;
  *(undefined4 *)(pTVar1 + 8) = 0;
  *(undefined4 *)(pTVar1 + 0xc) = 0;
  *(undefined4 *)(pTVar1 + 0x10) = 0;
  *(undefined4 *)(pTVar1 + 0x14) = 0;
  *(undefined4 *)(pTVar1 + 0x18) = 0;
  *(undefined4 *)(pTVar1 + 0x1c) = 0;
  this_01 = operator_new(0x38);
  __ZN12ParseOperandC1Ev(this_01);
  this_02 = operator_new(100);
  __ZN11ParseSymbolC1Ev(this_02);
  *(undefined4 *)(this_02 + 0x28) = 0xffffffff;
  ParseSymbol__SetName(this_02,DAT_a7b7bd4c);
  ParseSymbol__SetParseTreeType(this_02,pTVar1);
  *(unsigned char **)this_01 = this_02;
  ParseSymbolTable__processOperand(*(unsigned char **)(this + 0x68),this_01);
  return this_01;
}

/* TPPStreamCompiler__getPosition @ 0x97bc3dfc (240 bytes) */
int TPPStreamCompiler__getPosition(this)
  unsigned char * this;
{
  unsigned char * this_00;
  unsigned char * pTVar1;
  unsigned char * this_01;
  unsigned char * this_02;
  
  this_00 = (unsigned char *)GetGlobalPoolAllocator();
  pTVar1 = (unsigned char *)TPoolAllocator__allocate(this_00,0x28);
  *(undefined ***)pTVar1 = &PTR___ZN5TTypeD1Ev_a7b7d808;
  *(undefined4 *)(pTVar1 + 0x20) = 0;
  *(undefined4 *)(pTVar1 + 4) = 0;
  *(undefined4 *)(pTVar1 + 8) = 0;
  *(undefined4 *)(pTVar1 + 0xc) = 0;
  *(undefined4 *)(pTVar1 + 0x10) = 0;
  *(undefined4 *)(pTVar1 + 0x14) = 0;
  *(undefined4 *)(pTVar1 + 0x18) = 0;
  *(undefined4 *)(pTVar1 + 0x1c) = 0;
  *(uint *)(pTVar1 + 0x24) = *(uint *)(pTVar1 + 0x24) & 0x801ff | 0x1a082000;
  this_01 = operator_new(0x38);
  __ZN12ParseOperandC1Ev(this_01);
  this_02 = operator_new(100);
  __ZN11ParseSymbolC1Ev(this_02);
  *(undefined4 *)(this_02 + 0x28) = 0xffffffff;
  ParseSymbol__SetName(this_02,_compileUtilString);
  ParseSymbol__SetParseTreeType(this_02,pTVar1);
  *(unsigned char **)this_01 = this_02;
  ParseSymbolTable__processOperand(*(unsigned char **)(this + 0x68),this_01);
  return this_01;
}

/* TPPStreamCompiler__getMVP @ 0x97bc3eec (248 bytes) */
int TPPStreamCompiler__getMVP(this)
  unsigned char * this;
{
  unsigned char * this_00;
  unsigned char * pTVar1;
  unsigned char * this_01;
  unsigned char * this_02;
  
  this_00 = (unsigned char *)GetGlobalPoolAllocator();
  pTVar1 = (unsigned char *)TPoolAllocator__allocate(this_00,0x28);
  *(undefined ***)pTVar1 = &PTR___ZN5TTypeD1Ev_a7b7d808;
  *(undefined4 *)(pTVar1 + 0x20) = 0;
  *(uint *)(pTVar1 + 0x24) = *(uint *)(pTVar1 + 0x24) & 0x1ff | 0xc082400;
  *(undefined4 *)(pTVar1 + 4) = 0;
  *(undefined4 *)(pTVar1 + 8) = 0;
  *(undefined4 *)(pTVar1 + 0xc) = 0;
  *(undefined4 *)(pTVar1 + 0x10) = 0;
  *(undefined4 *)(pTVar1 + 0x14) = 0;
  *(undefined4 *)(pTVar1 + 0x18) = 0;
  *(undefined4 *)(pTVar1 + 0x1c) = 0;
  this_01 = operator_new(0x38);
  __ZN12ParseOperandC1Ev(this_01);
  this_02 = operator_new(100);
  __ZN11ParseSymbolC1Ev(this_02);
  *(undefined4 *)(this_02 + 0x28) = 0xffffffff;
  ParseSymbol__SetName(this_02,DAT_a7b7bd48);
  ParseSymbol__SetParseTreeType(this_02,pTVar1);
  *(unsigned char **)this_01 = this_02;
  ParseSymbolTable__processOperand(*(unsigned char **)(this + 0x68),this_01);
  return this_01;
}

/* TPPStreamCompiler__newNodeFromOperand @ 0x97bc3fe4 (460 bytes) */
int TPPStreamCompiler__newNodeFromOperand(this, param_2)
  unsigned char * this;
  unsigned char * param_2;
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined4 a1;
  undefined4 a2;
  int a3;
  undefined4 a4;
  unsigned char * this_00;
  int *a0;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int a5;
  int *a0_00;
  
  if (*(int *)param_2 == 0) {
    return (int *)0x0;
  }
  a0_00 = *(int **)(*(int *)param_2 + 0xc);
  a1 = (**(code **)(*a0_00 + 0x20))(a0_00);
  a2 = (**(code **)(*a0_00 + 0x2c))(a0_00);
  a3 = (**(code **)(*a0_00 + 0x34))(a0_00);
  a4 = (**(code **)(*a0_00 + 0x38))(a0_00);
  a5 = a0_00[1];
  this_00 = (unsigned char *)GetGlobalPoolAllocator();
  a0 = (int *)TPoolAllocator__allocate(this_00,0x28);
  iVar10 = a0_00[2];
  iVar12 = a0_00[3];
  iVar11 = a0_00[4];
  iVar9 = a0_00[5];
  iVar8 = a0_00[6];
  iVar7 = a0_00[7];
  iVar6 = a0_00[8];
  a0[1] = a0_00[1];
  *a0 = (int)&PTR___ZN5TTypeD1Ev_a7b7d808;
  a0[2] = iVar10;
  a0[3] = iVar12;
  a0[4] = iVar11;
  a0[5] = iVar9;
  a0[6] = iVar8;
  a0[7] = iVar7;
  a0[8] = iVar6;
  uVar5 = a0[9];
  uVar2 = a0_00[9] & 0xfe000000;
  a0[9] = uVar2 | uVar5 & 0x1ffffff;
  uVar3 = ((uint)a0_00[9] >> 0x13 & 0x3f) << 0x13;
  a0[9] = uVar3 | uVar2 | uVar5 & 0x7ffff;
  uVar1 = a0_00[9] & 0x7f800;
  a0[9] = uVar1 | uVar3 | uVar2 | uVar5 & 0x7ff;
  uVar4 = ((uint)a0_00[9] >> 10 & 1) << 10;
  a0[9] = uVar4 | uVar1 | uVar3 | uVar2 | uVar5 & 0x3ff;
  a0[9] = ((uint)a0_00[9] >> 9 & 1) << 9 | uVar4 | uVar1 | uVar3 | uVar2 | uVar5 & 0x1ff;
  if (*(int *)(*(int *)param_2 + 0x48) != 0) {
    a4 = 0;
    a5 = 0;
  }
  if (a3 == 0) {
    iVar6 = *(int *)(param_2 + 0x20);
LAB_97bc4168:
    if (iVar6 == 0) goto LAB_97bc4174;
  }
  else {
    iVar6 = 0;
    if (*(uint *)(param_2 + 0x20) == 0) goto LAB_97bc4168;
    a3 = 0;
    if (*(uint *)(param_2 + 0x20) < 2) goto LAB_97bc4174;
  }
  a2 = 1;
LAB_97bc4174:
  (**(code **)(*a0 + 8))(a0,a1,a2,a3,a4,a5);
  return a0;
}

/* TPPStreamCompiler__newTemporary @ 0x97bc41b0 (400 bytes) */
int TPPStreamCompiler__newTemporary(this, param_2)
  unsigned char * this;
  unsigned char * param_2;
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  unsigned char * this_00;
  unsigned char * a0;
  unsigned char * this_01;
  unsigned char * this_02;
  undefined4 uVar7;
  undefined4 a3;
  undefined4 a4;
  undefined4 a5;
  undefined4 uVar8;
  undefined4 uVar9;
  char acStack_120 [264];
  
  this_00 = (unsigned char *)GetGlobalPoolAllocator();
  a0 = (unsigned char *)TPoolAllocator__allocate(this_00,0x28);
  uVar9 = *(undefined4 *)(param_2 + 0x10);
  a5 = *(undefined4 *)(param_2 + 0x14);
  a4 = *(undefined4 *)(param_2 + 0x18);
  a3 = *(undefined4 *)(param_2 + 0x1c);
  uVar7 = *(undefined4 *)(param_2 + 0x20);
  uVar8 = *(undefined4 *)(param_2 + 8);
  uVar5 = *(undefined4 *)(param_2 + 4);
  *(undefined4 *)(a0 + 0xc) = *(undefined4 *)(param_2 + 0xc);
  *(undefined4 *)(a0 + 0x10) = uVar9;
  *(undefined4 *)(a0 + 0x14) = a5;
  *(undefined4 *)(a0 + 0x18) = a4;
  *(undefined4 *)(a0 + 0x1c) = a3;
  *(undefined4 *)(a0 + 0x20) = uVar7;
  *(undefined4 *)(a0 + 8) = uVar8;
  *(undefined4 *)(a0 + 4) = uVar5;
  *(undefined ***)a0 = &PTR___ZN5TTypeD1Ev_a7b7d808;
  uVar6 = *(uint *)(a0 + 0x24);
  uVar2 = *(uint *)(param_2 + 0x24) & 0xfe000000;
  *(uint *)(a0 + 0x24) = uVar2 | uVar6 & 0x1ffffff;
  uVar3 = (*(uint *)(param_2 + 0x24) >> 0x13 & 0x3f) << 0x13;
  *(uint *)(a0 + 0x24) = uVar3 | uVar2 | uVar6 & 0x7ffff;
  uVar1 = *(uint *)(param_2 + 0x24) & 0x7f800;
  *(uint *)(a0 + 0x24) = uVar1 | uVar3 | uVar2 | uVar6 & 0x7ff;
  uVar4 = (*(uint *)(param_2 + 0x24) >> 10 & 1) << 10;
  *(uint *)(a0 + 0x24) = uVar4 | uVar1 | uVar3 | uVar2 | uVar6 & 0x3ff;
  *(uint *)(a0 + 0x24) =
       (*(uint *)(param_2 + 0x24) >> 9 & 1) << 9 | uVar4 | uVar1 | uVar3 | uVar2 | uVar6 & 0x1ff;
  this_01 = operator_new(0x38);
  __ZN12ParseOperandC1Ev(this_01);
  this_02 = operator_new(100);
  __ZN11ParseSymbolC1Ev(this_02);
  *(undefined4 *)(this_02 + 0x34) = 0;
  *(undefined4 *)(this_02 + 0x3c) = 1;
  (**(code **)(*(int *)a0 + 0x28))(a0,0,uVar7,a3,a4,a5,*(int *)a0);
  ParseSymbol__SetParseTreeType(this_02,a0);
  uVar5 = TemporaryAllocator__getTemporary
                    (*(unsigned char **)(this + 0x60),(uint)*(ushort *)(this_02 + 0x2c));
  uVar7 = GetGLStringForType((uint)*(ushort *)(this_02 + 0x2c));
  _sprintf(acStack_120,DAT_a7b7bd50,uVar5,uVar7);
  *(undefined4 *)(this_02 + 0x28) = uVar5;
  ParseSymbol__SetName(this_02,acStack_120);
  *(unsigned char **)this_01 = this_02;
  ParseSymbolTable__processOperand(*(unsigned char **)(this + 0x68),this_01);
  return this_01;
}

/* TPPStreamCompiler__newAddressTemp @ 0x97bc4340 (272 bytes) */
int TPPStreamCompiler__newAddressTemp(this)
  unsigned char * this;
{
  unsigned char * this_00;
  unsigned char * pTVar1;
  unsigned char * this_01;
  unsigned char * this_02;
  undefined4 uVar2;
  char acStack_120 [256];
  
  this_00 = (unsigned char *)GetGlobalPoolAllocator();
  pTVar1 = (unsigned char *)TPoolAllocator__allocate(this_00,0x28);
  *(undefined4 *)(pTVar1 + 4) = 0;
  *(uint *)(pTVar1 + 0x24) = *(uint *)(pTVar1 + 0x24) & 0x1ff | 0x100800;
  *(undefined ***)pTVar1 = &PTR___ZN5TTypeD1Ev_a7b7d808;
  *(undefined4 *)(pTVar1 + 8) = 0;
  *(undefined4 *)(pTVar1 + 0xc) = 0;
  *(undefined4 *)(pTVar1 + 0x10) = 0;
  *(undefined4 *)(pTVar1 + 0x14) = 0;
  *(undefined4 *)(pTVar1 + 0x18) = 0;
  *(undefined4 *)(pTVar1 + 0x1c) = 0;
  *(undefined4 *)(pTVar1 + 0x20) = 0;
  this_01 = operator_new(0x38);
  __ZN12ParseOperandC1Ev(this_01);
  this_02 = operator_new(100);
  __ZN11ParseSymbolC1Ev(this_02);
  *(undefined4 *)(this_02 + 0x34) = 0;
  *(undefined4 *)(this_02 + 0x58) = 1;
  ParseSymbol__SetParseTreeType(this_02,pTVar1);
  uVar2 = AddressTempAllocator__getTemporary(*(unsigned char **)(this + 100));
  _sprintf(acStack_120,DAT_a7b7bd54,uVar2);
  *(undefined4 *)(this_02 + 0x28) = uVar2;
  ParseSymbol__SetName(this_02,acStack_120);
  *(unsigned char **)this_01 = this_02;
  ParseSymbolTable__processOperand(*(unsigned char **)(this + 0x68),this_01);
  return this_01;
}

/* TPPStreamCompiler__newReturnValue @ 0x97bc4450 (352 bytes) */
int TPPStreamCompiler__newReturnValue(param_1, param_2, param_3)
  unsigned char * param_1;
  char *param_2;
  char *param_3;
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  unsigned char * this;
  unsigned char * a0;
  unsigned char * this_00;
  unsigned char * this_01;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  
  this = (unsigned char *)GetGlobalPoolAllocator();
  a0 = (unsigned char *)TPoolAllocator__allocate(this,0x28);
  uVar12 = *(undefined4 *)(param_2 + 0xc);
  uVar11 = *(undefined4 *)(param_2 + 0x10);
  uVar10 = *(undefined4 *)(param_2 + 0x14);
  uVar9 = *(undefined4 *)(param_2 + 0x18);
  uVar8 = *(undefined4 *)(param_2 + 0x1c);
  uVar7 = *(undefined4 *)(param_2 + 0x20);
  uVar5 = *(undefined4 *)(param_2 + 4);
  *(undefined4 *)(a0 + 8) = *(undefined4 *)(param_2 + 8);
  *(undefined4 *)(a0 + 0xc) = uVar12;
  *(undefined4 *)(a0 + 0x10) = uVar11;
  *(undefined4 *)(a0 + 0x14) = uVar10;
  *(undefined4 *)(a0 + 0x18) = uVar9;
  *(undefined4 *)(a0 + 0x1c) = uVar8;
  *(undefined4 *)(a0 + 0x20) = uVar7;
  *(undefined4 *)(a0 + 4) = uVar5;
  *(undefined ***)a0 = &PTR___ZN5TTypeD1Ev_a7b7d808;
  uVar6 = *(uint *)(a0 + 0x24);
  uVar2 = *(uint *)(param_2 + 0x24) & 0xfe000000;
  *(uint *)(a0 + 0x24) = uVar2 | uVar6 & 0x1ffffff;
  uVar3 = (*(uint *)(param_2 + 0x24) >> 0x13 & 0x3f) << 0x13;
  *(uint *)(a0 + 0x24) = uVar3 | uVar2 | uVar6 & 0x7ffff;
  uVar1 = *(uint *)(param_2 + 0x24) & 0x7f800;
  *(uint *)(a0 + 0x24) = uVar1 | uVar3 | uVar2 | uVar6 & 0x7ff;
  uVar4 = (*(uint *)(param_2 + 0x24) >> 10 & 1) << 10;
  *(uint *)(a0 + 0x24) = uVar4 | uVar1 | uVar3 | uVar2 | uVar6 & 0x3ff;
  *(uint *)(a0 + 0x24) =
       (*(uint *)(param_2 + 0x24) >> 9 & 1) << 9 | uVar4 | uVar1 | uVar3 | uVar2 | uVar6 & 0x1ff;
  this_00 = operator_new(0x38);
  __ZN12ParseOperandC1Ev(this_00);
  this_01 = operator_new(100);
  __ZN11ParseSymbolC1Ev(this_01);
  *(undefined4 *)(this_01 + 0x38) = 1;
  *(undefined4 *)(this_01 + 0x3c) = 0;
  *(undefined4 *)(this_01 + 0x34) = 0;
  ParseSymbol__SetName(this_01,param_3);
  (**(code **)(*(int *)a0 + 0x28))(a0,0);
  ParseSymbol__SetParseTreeType(this_01,a0);
  *(unsigned char **)this_00 = this_01;
  ParseSymbolTable__processOperand(*(unsigned char **)(param_1 + 0x68),this_00);
  return this_00;
}

/* TPPStreamCompiler__newParam @ 0x97bc45b0 (408 bytes) */
int TPPStreamCompiler__newParam(this, param_2, param_3, param_4)
  unsigned char * this;
  unsigned char * param_2;
  char *param_3;
  int param_4;
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  unsigned char * this_00;
  unsigned char * a0;
  unsigned char * this_01;
  unsigned char * this_02;
  int iVar7;
  char *pcVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  
  this_00 = (unsigned char *)GetGlobalPoolAllocator();
  a0 = (unsigned char *)TPoolAllocator__allocate(this_00,0x28);
  uVar14 = *(undefined4 *)(param_2 + 0xc);
  uVar13 = *(undefined4 *)(param_2 + 0x10);
  uVar12 = *(undefined4 *)(param_2 + 0x14);
  uVar11 = *(undefined4 *)(param_2 + 0x18);
  uVar10 = *(undefined4 *)(param_2 + 0x1c);
  uVar9 = *(undefined4 *)(param_2 + 0x20);
  uVar5 = *(undefined4 *)(param_2 + 4);
  *(undefined4 *)(a0 + 8) = *(undefined4 *)(param_2 + 8);
  *(undefined4 *)(a0 + 0xc) = uVar14;
  *(undefined4 *)(a0 + 0x10) = uVar13;
  *(undefined4 *)(a0 + 0x14) = uVar12;
  *(undefined4 *)(a0 + 0x18) = uVar11;
  *(undefined4 *)(a0 + 0x1c) = uVar10;
  *(undefined4 *)(a0 + 0x20) = uVar9;
  *(undefined4 *)(a0 + 4) = uVar5;
  *(undefined ***)a0 = &PTR___ZN5TTypeD1Ev_a7b7d808;
  uVar6 = *(uint *)(a0 + 0x24);
  uVar2 = *(uint *)(param_2 + 0x24) & 0xfe000000;
  *(uint *)(a0 + 0x24) = uVar2 | uVar6 & 0x1ffffff;
  uVar3 = (*(uint *)(param_2 + 0x24) >> 0x13 & 0x3f) << 0x13;
  *(uint *)(a0 + 0x24) = uVar3 | uVar2 | uVar6 & 0x7ffff;
  uVar1 = *(uint *)(param_2 + 0x24) & 0x7f800;
  *(uint *)(a0 + 0x24) = uVar1 | uVar3 | uVar2 | uVar6 & 0x7ff;
  uVar4 = (*(uint *)(param_2 + 0x24) >> 10 & 1) << 10;
  *(uint *)(a0 + 0x24) = uVar4 | uVar1 | uVar3 | uVar2 | uVar6 & 0x3ff;
  *(uint *)(a0 + 0x24) =
       (*(uint *)(param_2 + 0x24) >> 9 & 1) << 9 | uVar4 | uVar1 | uVar3 | uVar2 | uVar6 & 0x1ff;
  this_01 = operator_new(0x38);
  __ZN12ParseOperandC1Ev(this_01);
  this_02 = operator_new(100);
  __ZN11ParseSymbolC1Ev(this_02);
  iVar7 = _strlen(param_3);
  pcVar8 = (char *)_malloc(iVar7 + 10);
  _sprintf(pcVar8,DAT_a7b7bd58,param_3,param_4);
  *(undefined4 *)(this_02 + 0x38) = 1;
  *(undefined4 *)(this_02 + 0x3c) = 0;
  *(undefined4 *)(this_02 + 0x34) = 0;
  ParseSymbol__SetName(this_02,pcVar8);
  (**(code **)(*(int *)a0 + 0x28))(a0,0);
  ParseSymbol__SetParseTreeType(this_02,a0);
  *(unsigned char **)this_01 = this_02;
  ParseSymbolTable__processOperand(*(unsigned char **)(this + 0x68),this_01);
  _free(pcVar8);
  return this_01;
}

/* TPPStreamCompiler__newIndirectOperandFromConstant @ 0x97bc4748 (2092 bytes) */
int TPPStreamCompiler__newIndirectOperandFromConstant(this, param_2, param_3)
  unsigned char * this;
  unsigned char * param_2;
  unsigned char * param_3;
{
  undefined4 uVar1;
  ushort uVar2;
  bool bVar3;
  bool bVar4;
  byte bVar5;
  double dVar6;
  unsigned char * this_00;
  undefined4 *puVar7;
  unsigned char * this_01;
  uint uVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  unsigned char * p_Var13;
  undefined4 a1;
  undefined4 a1_00;
  undefined4 in_r6;
  int in_r7;
  int in_r8;
  undefined4 *puVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  byte in_xer_so;
  unsigned char * pTStack00000020;
  undefined4 local_1f0;
  uint local_1ec;
  char acStack_1e0 [256];
  ushort local_e0 [8];
  int local_d0 [8];
  bool local_b0 [16];
  uint local_a0 [4];
  int *local_90;
  int local_8c;
  unsigned char * local_88;
  int local_84;
  int local_80;
  int local_7c;
  int local_78;
  int local_74;
  unsigned char * local_70;
  int local_6c;
  
  iVar16 = 0;
  bVar3 = false;
  local_90 = *(int **)(*(int *)(this + 0x70) + 0x10);
  iVar17 = *local_90;
  iVar15 = *(int *)(*(int *)(this + 0x70) + 0x2c);
  pTStack00000020 = param_3;
  local_88 = operator_new(0x38);
  __ZN12ParseOperandC1Ev(local_88);
  this_01 = operator_new(100);
  __ZN11ParseSymbolC1Ev(this_01);
  local_8c = 0;
  uVar8 = (**(code **)(*(int *)pTStack00000020 + 0x2c))
                    (pTStack00000020,a1,param_3,in_r6,in_r7,in_r8,pTStack00000020);
  iVar9 = ParseOperand__GetBaseSize(param_2);
  local_84 = (iVar9 - 1U) / uVar8 + 1;
  if (iVar17 == 0) {
    bVar4 = true;
LAB_97bc4c8c:
    if (bVar4) {
      iVar9 = 0;
      iVar16 = 0;
      if (local_84 < 1) {
        return local_88;
      }
      do {
        local_d0[0] = 0;
        local_d0[1] = 0;
        local_d0[2] = 0;
        local_d0[3] = 0;
        local_b0[0] = false;
        local_b0[1] = false;
        local_b0[2] = false;
        local_b0[3] = false;
        local_b0[4] = false;
        local_b0[5] = false;
        local_b0[6] = false;
        local_b0[7] = false;
        local_b0[8] = false;
        local_b0[9] = false;
        local_b0[10] = false;
        local_b0[0xb] = false;
        local_b0[0xc] = false;
        local_b0[0xd] = false;
        local_b0[0xe] = false;
        local_b0[0xf] = false;
        local_1ec = *(uint *)(*(int *)(this + 0x68) + 0x24);
        *(uint *)(*(int *)(this + 0x68) + 0x24) = local_1ec + 1;
        local_1f0 = 0x110000;
        local_1ec = local_1ec & 0xffff;
        uVar11 = getOpenGLTypeFromTType(pTStack00000020);
        uVar12 = GetPPStreamTypeForGLType(uVar11 & 0xffff);
        uVar11 = local_1f0 >> 0x10;
        local_1f0 = CONCAT22((ushort)((uVar8 - 1) * 0x1000000 >> 0x10) & 0x300 |
                             (ushort)(((uVar12 & 7) << 0x1a) >> 0x10) | (ushort)uVar11 & 0xff,
                             *(undefined2 *)(iVar15 + 10));
        if (0 < (int)uVar8) {
          puVar14 = (undefined4 *)(iVar9 * 4 + *(int *)(param_2 + 4));
          puVar7 = &local_1f0;
          uVar11 = uVar8;
          do {
            puVar7[0x50] = 1;
            iVar9 = iVar9 + 1;
            uVar1 = *puVar14;
            puVar14 = puVar14 + 1;
            puVar7[0x48] = uVar1;
            puVar7 = puVar7 + 1;
            uVar11 = uVar11 - 1;
          } while (uVar11 != 0);
        }
        if (*(int *)param_2 == 0) {
          uVar2 = *(ushort *)(param_2 + 0x18);
        }
        else {
          uVar2 = *(ushort *)(*(int *)param_2 + 0x2c);
        }
        uVar11 = (uint)uVar2;
        ConstantAllocationList__addConstant
                  ((unsigned char *)(this + 0x44),local_1ec & 0xffff,local_b0,uVar2);
        _PPStreamAddConstant(*(undefined4 *)(this + 0x70),local_d0);
        p_Var13 = (unsigned char *)_calloc(0x1c,1);
        *p_Var13 = 0x3;
        *(uint *)(p_Var13 + 0xc) = local_1f0;
        *(uint *)(p_Var13 + 0x10) = local_1ec;
        *(undefined4 *)(p_Var13 + 0x14) = 0;
        _PPStreamChunkListAddChunk(local_90,p_Var13);
        if (iVar16 == 0) {
          ParseSymbol__SetParseTreeType(this_01,pTStack00000020);
          uVar12 = local_1f0 & 0xffff;
          _sprintf(acStack_1e0,DAT_a7b7bd5c,uVar12);
          *(uint *)(this_01 + 0x28) = local_1f0 & 0xffff;
          ParseSymbol__SetName(this_01,acStack_1e0);
          iVar17 = (**(code **)(*(int *)pTStack00000020 + 0x24))
                             (pTStack00000020,a1_00,uVar12,uVar11,in_r7,in_r8,pTStack00000020);
          *(uint *)(this_01 + 0x38) = (uint)(iVar17 != 0);
          ParseSymbol__SetChunk(this_01,p_Var13);
          *(undefined4 *)(this_01 + 0x44) = 0;
          *(unsigned char **)local_88 = this_01;
          *(undefined4 *)(this_01 + 0x50) = 1;
          ParseSymbolTable__AddSymbol(*(unsigned char **)(this + 0x68),this_01);
          local_a0[1] = 0;
          local_a0[0] = local_1f0 & 0xffff;
          _PPStreamAddParamBindingArray(*(undefined4 *)(this + 0x70),local_a0);
        }
        else if ((iVar16 == local_84 + -1) &&
                (iVar17 = *(int *)(*(int *)(*(int *)(this + 0x70) + 0x14) + 4),
                *(short *)(iVar17 + 0x12) == 0)) {
          *(undefined2 *)(iVar17 + 0x12) = (*(unsigned short *)((unsigned char *)&(local_1f0) + 2));
        }
        iVar16 = iVar16 + 1;
      } while (iVar16 < local_84);
      return local_88;
    }
  }
  else {
    local_70 = this + 0x44;
    local_74 = (uint)(byte)(((int)uVar8 < 2) << 3 | (2 < (int)uVar8) << 2 | (uVar8 == 2) << 1 |
                           in_xer_so & 1) << 0x1c;
    local_80 = (uint)(byte)(((int)uVar8 < 1) << 3 | (1 < (int)uVar8) << 2 | (uVar8 == 1) << 1 |
                           in_xer_so & 1) << 0x1c;
    local_7c = (uint)(byte)(((int)uVar8 < 3) << 3 | (3 < (int)uVar8) << 2 | (uVar8 == 3) << 1 |
                           in_xer_so & 1) << 0x1c;
    local_78 = (uint)(byte)(((int)uVar8 < 4) << 3 | (4 < (int)uVar8) << 2 | (uVar8 == 4) << 1 |
                           in_xer_so & 1) << 0x1c;
    local_6c = local_74;
    do {
      local_d0[0] = 1;
      local_d0[1] = 1;
      local_d0[2] = 1;
      local_d0[3] = 1;
      local_1f0 = *(uint *)(iVar17 + 0xc);
      local_1ec = *(uint *)(iVar17 + 0x10);
      if ((local_1f0 & 0x1f0000) == 0x110000) {
        iVar9 = _PPStreamChunkListChunkAtIndex(iVar15,local_1f0 & 0xffff);
        ConstantAllocationList__getConstantUsage
                  ((unsigned char *)(this + 0x44),local_1ec & 0xffff,(bool *)local_d0,
                   local_e0);
        local_d0[5] = local_d0[0] + local_d0[1] + local_d0[2] + local_d0[3] ^ 0x80000000;
        local_d0[4] = 0x43300000;
        dVar6 = (double)CONCAT44(0x43300000,local_d0[5]);
        if (*(int *)param_2 == 0) {
          uVar2 = *(ushort *)(param_2 + 0x18);
        }
        else {
          uVar2 = *(ushort *)(*(int *)param_2 + 0x2c);
        }
        in_r8 = local_d0[0];
        if (local_e0[0] == uVar2) {
          local_d0[5] = uVar8 ^ 0x80000000;
          local_d0[4] = 0x43300000;
          if ((float)(dVar6 - 4503601774854144.0) ==
              (float)((double)CONCAT44(0x43300000,local_d0[5]) - 4503601774854144.0)) {
            in_r7 = 1;
            bVar5 = (byte)((uint)local_74 >> 0x18);
            if ((bool)(bVar5 >> 5 & 1)) {
LAB_97bc49e0:
              if ((local_d0[1] != 0) &&
                 (*(float *)(iVar16 * 4 + *(int *)(param_2 + 4) + 4) == *(float *)(iVar9 + 0x10))) {
LAB_97bc4a14:
                if ((local_d0[0] != 0) &&
                   (*(float *)(*(int *)(param_2 + 4) + iVar16 * 4) == *(float *)(iVar9 + 0xc)))
                goto LAB_97bc4a38;
              }
LAB_97bc4a34:
              in_r7 = 0;
            }
            else {
              if ((bool)(bVar5 >> 6 & 1)) {
                if ((bool)((byte)((uint)local_7c >> 0x1d) & 1)) {
LAB_97bc49bc:
                  if ((local_d0[2] != 0) &&
                     (*(float *)(iVar16 * 4 + *(int *)(param_2 + 4) + 8) == *(float *)(iVar9 + 0x14)
                     )) goto LAB_97bc49e0;
                }
                else {
                  if (!(bool)((byte)((uint)local_78 >> 0x1d) & 1)) goto LAB_97bc4a38;
                  if ((local_d0[3] != 0) &&
                     (*(float *)(iVar16 * 4 + *(int *)(param_2 + 4) + 0xc) ==
                      *(float *)(iVar9 + 0x18))) goto LAB_97bc49bc;
                }
                goto LAB_97bc4a34;
              }
              if ((bool)((byte)((uint)local_80 >> 0x1d) & 1)) goto LAB_97bc4a14;
            }
LAB_97bc4a38:
            iVar16 = iVar16 + uVar8;
            if ((in_r7 != 0) && (local_8c = iVar17, local_84 == 1)) {
              bVar3 = true;
            }
          }
        }
      }
      this_00 = local_70;
      iVar17 = *(int *)(iVar17 + 8);
      if (local_8c == 0) {
        bVar4 = !bVar3;
      }
      else {
        bVar4 = !bVar3;
        if (bVar4) {
          if (iVar17 != 0) {
            bVar5 = (byte)((uint)local_6c >> 0x18);
            iVar9 = iVar17;
            do {
              local_1f0 = *(uint *)(iVar9 + 0xc);
              local_1ec = *(uint *)(iVar9 + 0x10);
              if ((local_1f0 & 0x1f0000) == 0x110000) {
                iVar10 = _PPStreamChunkListChunkAtIndex(iVar15,local_1f0 & 0xffff);
                ConstantAllocationList__getConstantUsage
                          ((unsigned char *)this_00,local_1ec & 0xffff,(bool *)local_d0,
                           local_e0);
                local_d0[4] = 0x43300000;
                local_d0[5] = local_d0[0] + local_d0[1] + local_d0[2] + local_d0[3] ^ 0x80000000;
                dVar6 = (double)CONCAT44(0x43300000,local_d0[5]);
                if (*(int *)param_2 == 0) {
                  uVar2 = *(ushort *)(param_2 + 0x18);
                }
                else {
                  uVar2 = *(ushort *)(*(int *)param_2 + 0x2c);
                }
                in_r8 = local_d0[0];
                if (local_e0[0] == uVar2) {
                  local_d0[5] = uVar8 ^ 0x80000000;
                  local_d0[4] = 0x43300000;
                  if ((float)(dVar6 - 4503601774854144.0) ==
                      (float)((double)CONCAT44(0x43300000,local_d0[5]) - 4503601774854144.0)) {
                    in_r7 = 1;
                    if ((bool)(bVar5 >> 5 & 1)) {
LAB_97bc4bec:
                      if ((local_d0[1] != 0) &&
                         (*(float *)(iVar16 * 4 + *(int *)(param_2 + 4) + 4) ==
                          *(float *)(iVar10 + 0x10))) {
LAB_97bc4c10:
                        if ((local_d0[0] != 0) &&
                           (*(float *)(*(int *)(param_2 + 4) + iVar16 * 4) ==
                            *(float *)(iVar10 + 0xc))) goto LAB_97bc4c34;
                      }
LAB_97bc4c30:
                      in_r7 = 0;
                    }
                    else {
                      if ((bool)(bVar5 >> 6 & 1)) {
                        if ((bool)((byte)((uint)local_7c >> 0x1d) & 1)) {
LAB_97bc4bc8:
                          if ((local_d0[2] != 0) &&
                             (*(float *)(iVar16 * 4 + *(int *)(param_2 + 4) + 8) ==
                              *(float *)(iVar10 + 0x14))) goto LAB_97bc4bec;
                        }
                        else {
                          if (!(bool)((byte)((uint)local_78 >> 0x1d) & 1)) goto LAB_97bc4c34;
                          if ((local_d0[3] != 0) &&
                             (*(float *)(iVar16 * 4 + *(int *)(param_2 + 4) + 0xc) ==
                              *(float *)(iVar10 + 0x18))) goto LAB_97bc4bc8;
                        }
                        goto LAB_97bc4c30;
                      }
                      if ((bool)((byte)((uint)local_80 >> 0x1d) & 1)) goto LAB_97bc4c10;
                    }
LAB_97bc4c34:
                    iVar16 = iVar16 + uVar8;
                    if (in_r7 == 0) {
                      iVar16 = 0;
                      local_8c = 0;
                      goto LAB_97bc4c7c;
                    }
                  }
                }
              }
              iVar10 = ParseOperand__GetBaseSize(param_2);
              if (iVar10 <= iVar16) {
                bVar3 = true;
                bVar4 = false;
              }
              iVar9 = *(int *)(iVar9 + 8);
              if ((iVar9 == 0) || (!bVar4)) goto LAB_97bc4c7c;
            } while( true );
          }
          goto LAB_97bc4c8c;
        }
      }
LAB_97bc4c7c:
      if (iVar17 == 0) goto LAB_97bc4c8c;
    } while (bVar4);
  }
  local_1ec = *(undefined4 *)(local_8c + 0x10);
  local_1f0 = *(uint *)(local_8c + 0xc);
  ParseSymbol__SetParseTreeType(this_01,pTStack00000020);
  _sprintf(acStack_1e0,DAT_a7b7bd5c,local_1f0 & 0xffff);
  *(uint *)(this_01 + 0x28) = local_1f0 & 0xffff;
  ParseSymbol__SetName(this_01,acStack_1e0);
  *(unsigned char **)local_88 = this_01;
  ParseSymbolTable__processOperand(*(unsigned char **)(this + 0x68),local_88);
  return local_88;
}

/* TPPStreamCompiler__equalOperands @ 0x97bc4f74 (2416 bytes) */
int TPPStreamCompiler__equalOperands(this, param_2, param_3, param_4, param_5)
  unsigned char * this;
  unsigned char * param_2;
  unsigned char ** param_3;
  unsigned char ** param_4;
  int param_5;
{
  short sVar1;
  ushort uVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  int *a0;
  int iVar6;
  char *p0;
  unsigned char * pPVar7;
  unsigned char * pPVar8;
  undefined4 uVar9;
  uint uVar10;
  void *this_00;
  unsigned char * pPVar11;
  uint uVar12;
  undefined4 extraout_r4;
  undefined4 extraout_r4_00;
  undefined4 extraout_r4_01;
  undefined4 extraout_r4_02;
  undefined4 extraout_r4_03;
  undefined4 extraout_r4_04;
  unsigned char ** ppPVar13;
  unsigned char ** a3;
  undefined4 in_r8;
  undefined4 uVar14;
  unsigned char * in_r10;
  undefined4 uVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  unsigned char ** a0_00;
  unsigned char ** a1;
  undefined8 uVar19;
  uint local_e0;
  uint local_dc;
  uint local_d8;
  undefined4 local_d4;
  uint local_d0;
  undefined4 local_cc;
  uint local_c8;
  undefined4 local_c4;
  undefined4 local_c0;
  undefined4 local_bc;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined4 local_b0;
  undefined4 local_ac;
  uint local_a0;
  undefined4 local_9c;
  uint local_90;
  undefined4 local_8c;
  uint local_80;
  undefined4 local_7c;
  unsigned char * local_70 [2];
  unsigned char * local_68 [9];
  
  local_70[0] = (unsigned char *)0x0;
  ppPVar13 = param_3;
  a3 = param_4;
  iVar18 = param_5;
  ((int (*)())__ZN17TPPStreamCompiler22IndirectAddressHandlerEPP12ParseOperandS2_S2_)(this,local_70,param_3,param_4);
  local_68[0] = *param_3;
  bVar3 = false;
  local_68[1] = *param_4;
  if ((*(int *)local_68[0] != 0) &&
     ((sVar1 = *(short *)(*(int *)local_68[0] + 0x2c), sVar1 == 0x7ffe || (sVar1 == 0x7fff)))) {
    iVar4 = ((int (*)())TPPStreamCompiler__generateAddressLoad)(this,local_68[0]);
    if (iVar4 != 0) {
      TPPStreamCompiler__equalOperands__source0Indirect = 1;
    }
    iVar5 = ((int (*)())TPPStreamCompiler__generateAddressLoad)(this,local_68[1]);
    if (iVar5 != 0) {
      TPPStreamCompiler__equalOperands__source1Indirect = 1;
    }
    bVar3 = iVar5 != 0 || iVar4 != 0;
  }
  uVar19 = CONCAT44(local_70[0],local_68[0]);
  iVar4 = *(int *)local_68[0];
  if ((iVar4 == 0) || (*(short *)(iVar4 + 0x2c) != 0x7ffe)) {
    iVar4 = *(int *)local_68[0];
    if ((iVar4 == 0) || (*(short *)(iVar4 + 0x2c) != 0x7fff)) {
      uVar9 = 0;
      local_dc = 0;
      local_b0 = *(undefined4 *)(this + 0x90);
      local_b8 = 0;
      local_b4 = 0;
      local_e0 = 0x40000000;
      local_d8 = 0;
      local_d4 = 0;
      local_d0 = 0;
      local_cc = 0;
      local_c8 = 0;
      local_c4 = 0;
      local_c0 = 0;
      local_bc = 0;
      local_ac = 0;
      ((int (*)())TPPStreamCompiler__getOperandAsSourceVar)((unsigned char *)&local_80,this,local_68[0],a3,iVar18,in_r8,0,0);
      local_d0 = local_80;
      local_cc = local_7c;
      if (TPPStreamCompiler__equalOperands__source0Indirect != 0) {
        local_d0 = local_80 & 0x8fffff00 | 0x80000000;
      }
      ((int (*)())TPPStreamCompiler__getOperandAsSourceVar)((unsigned char *)&local_80,this,local_68[1],a3,iVar18,in_r8,local_80,uVar9);
      local_c8 = local_80;
      local_c4 = local_7c;
      if (TPPStreamCompiler__equalOperands__source1Indirect != 0) {
        local_c8 = local_80 & 0x8fffff00 | 0x80000000;
      }
      local_70[0] = (unsigned char *)((int (*)())TPPStreamCompiler__newTemporary)(this,param_2);
      ((int (*)())TPPStreamCompiler__getOperandAsDestVar)((unsigned char *)&local_80,this,local_70[0],a3,iVar18,in_r8);
      local_d4 = local_7c;
      iVar18 = 0x31;
      local_d8 = local_80;
      if (param_5 == 0) {
        iVar18 = 0x36;
      }
      local_e0 = iVar18 << 0x12 | local_e0 & 0xfc03ffff;
      local_dc = (local_80 >> 0xc & 1) << 0x1c | local_dc & 0xefffffff;
      if (*(int *)local_70[0] == 0) {
        uVar2 = *(ushort *)(local_70[0] + 0x18);
      }
      else {
        uVar2 = *(ushort *)(*(int *)local_70[0] + 0x2c);
      }
      uVar10 = GetPPStreamTypeForGLType((uint)uVar2);
      local_dc = (uVar10 & 7) << 0x17 | local_dc & 0xfc7fffff;
      iVar18 = ParseOperand__GetLogicalSize(local_70[0]);
      local_dc = (iVar18 + -1) * 0x4000000 & 0xc000000U | local_dc & 0xf3f3ffff;
      _PPStreamAddOperation(*(undefined4 *)(this + 0x70),&local_e0,0,0);
    }
    else {
      uVar10 = (int)*(short *)(iVar4 + 0x2e) - 1;
      if (-1 < (int)uVar10) {
        do {
          iVar4 = 0;
          iVar18 = 1;
          do {
            this_00 = operator_new(0x38);
            __ZN12ParseOperandC1Ev(this_00);
            *(void **)((int)local_68 + iVar4 + 8) = this_00;
            pPVar8 = operator_new(100);
            __ZN11ParseSymbolC1Ev(pPVar8);
            ParseSymbol__SetName(pPVar8,*(char **)(**(int **)((int)local_68 + iVar4) + 0x14));
            ParseSymbol__AddDirectIndex(pPVar8,uVar10);
            _sprintf((char *)&local_e0,DAT_a7b7bd90,uVar10);
            ParseSymbol__CatName(pPVar8,(char *)&local_e0);
            *(undefined4 *)(pPVar8 + 0x40) =
                 *(undefined4 *)(**(int **)((int)local_68 + iVar4) + 0x40);
            *(undefined4 *)(pPVar8 + 0x3c) =
                 *(undefined4 *)(**(int **)((int)local_68 + iVar4) + 0x3c);
            ParseSymbol__SetParseTreeType
                      (pPVar8,*(unsigned char **)(**(int **)((int)local_68 + iVar4) + 0xc));
            iVar5 = **(int **)((int)local_68 + iVar4);
            *(undefined4 *)(pPVar8 + 0x48) = 1;
            *(undefined4 *)(pPVar8 + 0x28) = *(undefined4 *)(iVar5 + 0x28);
            ParseSymbol__ResolveOpenGLType(pPVar8);
            **(undefined4 **)((int)local_68 + iVar4 + 8) = pPVar8;
            if ((*(short *)(pPVar8 + 0x2c) != 0x7ffe) && (*(short *)(pPVar8 + 0x2c) != 0x7fff)) {
              ParseSymbolTable__processOperand
                        (*(unsigned char **)(this + 0x68),
                         *(unsigned char **)((int)local_68 + iVar4 + 8));
            }
            pPVar7 = local_70[0];
            iVar18 = iVar18 + -1;
            iVar4 = iVar4 + 4;
          } while (-1 < iVar18);
          ppPVar13 = local_68 + 3;
          iVar18 = param_5;
          local_70[0] = (unsigned char *)((int (*)())TPPStreamCompiler__equalOperands)(this,param_2,local_68 + 2,ppPVar13,param_5);
          pPVar11 = local_68[2];
          if (local_68[2] != (void *)0x0) {
            __ZN12ParseOperandD1Ev(local_68[2]);
            __ZdlPv(pPVar11);
          }
          pPVar11 = local_68[3];
          if (local_68[3] != (void *)0x0) {
            __ZN12ParseOperandD1Ev(local_68[3]);
            __ZdlPv(pPVar11);
          }
          pPVar11 = local_70[0];
          if ((pPVar7 != (unsigned char *)0x0) && (local_70[0] != (unsigned char *)0x0)) {
            pPVar11 = (unsigned char *)((int (*)())TPPStreamCompiler__newTemporary)(this,param_2);
            local_dc = 0;
            local_b0 = *(undefined4 *)(this + 0x90);
            local_e0 = 0x40000000;
            local_d8 = 0;
            local_d4 = 0;
            local_d0 = 0;
            local_cc = 0;
            local_c8 = 0;
            local_c4 = 0;
            local_c0 = 0;
            local_bc = 0;
            local_b8 = 0;
            local_b4 = 0;
            local_ac = 0;
            ((int (*)())TPPStreamCompiler__getOperandAsDestVar)((unsigned char *)&local_90,this,pPVar11,ppPVar13,iVar18,in_r8);
            local_d8 = local_90;
            local_d4 = local_8c;
            ((int (*)())TPPStreamCompiler__getOperandAsSourceVar)((unsigned char *)&local_90,this,pPVar7,ppPVar13,iVar18,in_r8,iVar5,in_r10);
            local_d0 = local_90;
            local_cc = local_8c;
            ((int (*)())TPPStreamCompiler__getOperandAsSourceVar)((unsigned char *)&local_90,this,local_70[0],ppPVar13,iVar18,in_r8,iVar5,in_r10
                      );
            local_e0 = ((param_5 == 0) + 0x24) * 0x40000 | local_e0 & 0xfc03ffff;
            local_dc = (local_d8 >> 0xc & 1) << 0x1c | local_dc & 0xefffffff;
            local_c8 = local_90;
            local_c4 = local_8c;
            if (*(int *)local_70[0] == 0) {
              uVar2 = *(ushort *)(local_70[0] + 0x18);
            }
            else {
              uVar2 = *(ushort *)(*(int *)local_70[0] + 0x2c);
            }
            in_r10 = local_70[0];
            uVar12 = GetPPStreamTypeForGLType((uint)uVar2);
            local_dc = (uVar12 & 7) << 0x17 | local_dc & 0xfc7fffff;
            iVar18 = ParseOperand__GetLogicalSize(local_70[0]);
            local_dc = (iVar18 + -1) * 0x4000000 & 0xc000000U | local_dc & 0xf3f3ffff;
            _PPStreamAddOperation(*(undefined4 *)(this + 0x70),&local_e0,0,0);
            __ZN12ParseOperandD1Ev(pPVar7);
            __ZdlPv(pPVar7);
            pPVar7 = local_70[0];
            if (local_70[0] != (unsigned char *)0x0) {
              __ZN12ParseOperandD1Ev(local_70[0]);
              __ZdlPv(pPVar7);
            }
          }
          local_70[0] = pPVar11;
          uVar10 = uVar10 - 1;
        } while (-1 < (int)uVar10);
      }
    }
  }
  else {
    iVar4 = *(int *)(*(int *)(iVar4 + 0xc) + 8);
    if (iVar4 != 0) {
      iVar5 = *(int *)(iVar4 + 4);
      iVar16 = (*(int *)(iVar4 + 8) - iVar5 >> 3) + -1;
      if (-1 < iVar16) {
        while( true ) {
          iVar17 = 0;
          while( true ) {
            local_70[0] = (unsigned char *)((ulonglong)uVar19 >> 0x20);
            a0 = *(int **)(iVar5 + iVar16 * 8);
            a0_00 = *(unsigned char ***)(*(int *)local_68[iVar17] + 0x14);
            iVar5 = (**(code **)(*a0 + 0x1c))
                              (a0,(int)uVar19,ppPVar13,a3,iVar18,in_r8,local_68[iVar17]);
            *(undefined1 *)(*(int *)(iVar5 + 4) + *(int *)(*(int *)(iVar5 + 4) + -0xc)) =
                 *DAT_a7b7bd9c;
            a1 = *(unsigned char ***)(iVar5 + 4);
            iVar5 = _strlen(a1);
            iVar5 = iVar5 + 1;
            if (a0_00 != (unsigned char **)0x0) {
              iVar6 = _strlen(a0_00);
              iVar5 = iVar5 + iVar6 + 1;
            }
            p0 = (char *)_malloc(iVar5);
            if (a0_00 == (unsigned char **)0x0) {
              _strcpy(p0,a1);
            }
            else {
              _sprintf(p0,DAT_a7b7bd8c,(int)a0_00,(int)a1);
              ppPVar13 = a0_00;
              a3 = a1;
            }
            pPVar7 = operator_new(0x38);
            __ZN12ParseOperandC1Ev(pPVar7);
            local_68[iVar17 + 2] = pPVar7;
            pPVar8 = operator_new(100);
            __ZN11ParseSymbolC1Ev(pPVar8);
            ParseSymbol__SetName(pPVar8,p0);
            _free(p0);
            *(undefined4 *)(pPVar8 + 0x40) = *(undefined4 *)(*(int *)local_68[iVar17] + 0x40);
            *(undefined4 *)(pPVar8 + 0x3c) = *(undefined4 *)(*(int *)local_68[iVar17] + 0x3c);
            ParseSymbol__SetParseTreeType(pPVar8,*(unsigned char **)(*(int *)(iVar4 + 4) + iVar16 * 8));
            *(undefined4 *)(pPVar8 + 0x28) = *(undefined4 *)(*(int *)local_68[iVar17] + 0x28);
            *(unsigned char **)local_68[iVar17 + 2] = pPVar8;
            uVar9 = extraout_r4;
            if ((*(short *)(pPVar8 + 0x2c) != 0x7ffe) && (*(short *)(pPVar8 + 0x2c) != 0x7fff)) {
              ParseSymbolTable__processOperand
                        (*(unsigned char **)(this + 0x68),local_68[iVar17 + 2]);
              uVar9 = extraout_r4_00;
            }
            pPVar7 = local_70[0];
            uVar19 = CONCAT44(local_70[0],uVar9);
            iVar17 = iVar17 + 1;
            if (1 < iVar17) break;
            iVar5 = *(int *)(iVar4 + 4);
          }
          ppPVar13 = local_68 + 2;
          a3 = local_68 + 3;
          iVar18 = param_5;
          uVar19 = ((int (*)())TPPStreamCompiler__equalOperands)(this,param_2,ppPVar13,a3,param_5);
          pPVar11 = local_68[2];
          local_70[0] = (unsigned char *)((ulonglong)uVar19 >> 0x20);
          if (local_68[2] != (void *)0x0) {
            __ZN12ParseOperandD1Ev(local_68[2]);
            __ZdlPv(pPVar11);
            uVar19 = CONCAT44(local_70[0],extraout_r4_01);
          }
          pPVar11 = local_68[3];
          local_70[0] = (unsigned char *)((ulonglong)uVar19 >> 0x20);
          if (local_68[3] != (void *)0x0) {
            __ZN12ParseOperandD1Ev(local_68[3]);
            __ZdlPv(pPVar11);
            uVar19 = CONCAT44(local_70[0],extraout_r4_02);
          }
          local_70[0] = (unsigned char *)((ulonglong)uVar19 >> 0x20);
          if ((pPVar7 != (unsigned char *)0x0) && (local_70[0] != (unsigned char *)0x0)) {
            uVar9 = ((int (*)())TPPStreamCompiler__newTemporary)(this,param_2);
            uVar14 = 0;
            uVar15 = 0;
            local_dc = 0;
            local_b0 = *(undefined4 *)(this + 0x90);
            local_b8 = 0;
            local_b4 = 0;
            local_d8 = 0;
            local_d4 = 0;
            local_d0 = 0;
            local_cc = 0;
            local_c8 = 0;
            local_c4 = 0;
            local_c0 = 0;
            local_bc = 0;
            local_ac = 0;
            local_e0 = 0x40000000;
            ((int (*)())TPPStreamCompiler__getOperandAsDestVar)((unsigned char *)&local_a0,this,uVar9,a3,iVar18,in_r8);
            local_d8 = local_a0;
            local_d4 = local_9c;
            ((int (*)())TPPStreamCompiler__getOperandAsSourceVar)((unsigned char *)&local_a0,this,pPVar7,a3,iVar18,in_r8,uVar14,uVar15);
            local_d0 = local_a0;
            local_cc = local_9c;
            ((int (*)())TPPStreamCompiler__getOperandAsSourceVar)((unsigned char *)&local_a0,this,local_70[0],a3,iVar18,in_r8,uVar14,uVar15);
            local_e0 = ((param_5 == 0) + 0x24) * 0x40000 | local_e0 & 0xfc03ffff;
            local_dc = (local_d8 >> 0xc & 1) << 0x1c | local_dc & 0xefffffff;
            local_c8 = local_a0;
            local_c4 = local_9c;
            if (*(int *)local_70[0] == 0) {
              uVar2 = *(ushort *)(local_70[0] + 0x18);
            }
            else {
              uVar2 = *(ushort *)(*(int *)local_70[0] + 0x2c);
            }
            uVar10 = GetPPStreamTypeForGLType((uint)uVar2);
            local_dc = (uVar10 & 7) << 0x17 | local_dc & 0xfc7fffff;
            iVar5 = ParseOperand__GetLogicalSize(local_70[0]);
            local_dc = (iVar5 + -1) * 0x4000000 & 0xc000000U | local_dc & 0xf3f3ffff;
            ppPVar13 = (unsigned char **)0x0;
            a3 = (unsigned char **)0x0;
            _PPStreamAddOperation(*(undefined4 *)(this + 0x70),&local_e0);
            __ZN12ParseOperandD1Ev(pPVar7);
            __ZdlPv(pPVar7);
            pPVar7 = local_70[0];
            uVar19 = CONCAT44(uVar9,extraout_r4_03);
            if (local_70[0] != (unsigned char *)0x0) {
              __ZN12ParseOperandD1Ev(local_70[0]);
              __ZdlPv(pPVar7);
              uVar19 = CONCAT44(uVar9,extraout_r4_04);
            }
          }
          local_70[0] = (unsigned char *)((ulonglong)uVar19 >> 0x20);
          iVar16 = iVar16 + -1;
          if (iVar16 < 0) break;
          iVar5 = *(int *)(iVar4 + 4);
        }
      }
    }
  }
  if (bVar3) {
    TPPStreamCompiler__equalOperands__source1Indirect = 0;
    TPPStreamCompiler__equalOperands__source0Indirect = 0;
  }
  return local_70[0];
}

/* TPPStreamCompiler__duplicateDestinationSource @ 0x97bc58e4 (636 bytes) */
int TPPStreamCompiler__duplicateDestinationSource(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  uint param_2;
  uint param_3;
  uint param_4;
  uint param_5;
{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  
  uVar4 = 1;
  if ((param_2 >> 0x11 & 7) != (param_4 >> 0x17 & 7)) {
    return 0;
  }
  if ((param_3 & 0xffff) != (param_5 & 0xffff)) {
    return 0;
  }
  if ((param_2 >> 0xc & 1) != (param_4 >> 0xe & 1)) {
    return 0;
  }
  if ((param_4 & 0x8000000) != 0) {
    return 0;
  }
  if ((param_3 & 0xf0000000) != (param_4 & 0xf0000000)) {
    return 0;
  }
  if ((int)(param_3 << 4 | param_3 >> 0x1c) >> 0x18 != (int)(char)param_4) {
    return 0;
  }
  if ((param_2 & 0x7ff00000) != 0) {
    return 0;
  }
  uVar2 = param_2 >> 10 & 3;
  if (uVar2 != 1) {
    if (uVar2 == 0) goto LAB_97bc5aec;
    if (uVar2 != 2) {
      if (uVar2 != 3) {
        return uVar4;
      }
      if ((param_2 & 0x10000) != 0) {
        uVar2 = param_2 >> 2 & 3;
        if (uVar2 == 1) {
          uVar2 = param_4 & 0x180000;
          uVar3 = 0x180000;
LAB_97bc59d0:
          bVar1 = uVar2 == uVar3;
LAB_97bc59e8:
          if (bVar1) goto LAB_97bc59f0;
        }
        else {
          if (uVar2 == 0) {
            uVar2 = param_4 & 0x600000;
            uVar3 = 0x600000;
            goto LAB_97bc59d0;
          }
          if (uVar2 == 2) {
            uVar2 = param_4 & 0x60000;
            uVar3 = 0x60000;
            goto LAB_97bc59d0;
          }
          if (uVar2 == 3) {
            bVar1 = (param_4 & 0x18000) == 0x18000;
            goto LAB_97bc59e8;
          }
        }
        uVar4 = 0;
      }
    }
LAB_97bc59f0:
    if ((param_2 & 0x8000) != 0) {
      uVar2 = param_2 >> 4 & 3;
      if (uVar2 == 1) {
        uVar3 = 0x100000;
        uVar2 = param_4 & 0x180000;
LAB_97bc5a60:
        if (uVar2 == uVar3) goto LAB_97bc5a6c;
      }
      else {
        if (uVar2 == 0) {
          uVar3 = 0x400000;
          uVar2 = param_4 & 0x600000;
          goto LAB_97bc5a60;
        }
        if (uVar2 == 2) {
          uVar3 = 0x40000;
          uVar2 = param_4 & 0x60000;
          goto LAB_97bc5a60;
        }
        if (uVar2 == 3) {
          uVar3 = 0x10000;
          uVar2 = param_4 & 0x18000;
          goto LAB_97bc5a60;
        }
      }
      uVar4 = 0;
    }
  }
LAB_97bc5a6c:
  if ((param_2 & 0x4000) == 0) goto LAB_97bc5aec;
  uVar2 = param_2 >> 6 & 3;
  if (uVar2 == 1) {
    uVar3 = 0x80000;
    uVar2 = param_4 & 0x180000;
LAB_97bc5ac8:
    bVar1 = uVar2 == uVar3;
LAB_97bc5ae4:
    if (bVar1) goto LAB_97bc5aec;
  }
  else {
    if (uVar2 == 0) {
      uVar3 = 0x200000;
      uVar2 = param_4 & 0x600000;
      goto LAB_97bc5ac8;
    }
    if (uVar2 == 2) {
      uVar3 = 0x20000;
      uVar2 = param_4 & 0x60000;
      goto LAB_97bc5ac8;
    }
    if (uVar2 == 3) {
      bVar1 = (param_4 & 0x18000) == 0x8000;
      goto LAB_97bc5ae4;
    }
  }
  uVar4 = 0;
LAB_97bc5aec:
  if ((param_2 & 0x2000) == 0) {
    return uVar4;
  }
  uVar2 = param_2 >> 8 & 3;
  if (uVar2 == 1) {
    if ((param_4 & 0x180000) == 0) {
      return uVar4;
    }
  }
  else if (uVar2 == 0) {
    if ((param_4 & 0x600000) == 0) {
      return uVar4;
    }
  }
  else if (uVar2 == 2) {
    if ((param_4 & 0x60000) == 0) {
      return uVar4;
    }
  }
  else if ((uVar2 == 3) && ((param_4 & 0x18000) == 0)) {
    return uVar4;
  }
  return 0;
}

/* TPPStreamCompiler__assignOperands @ 0x97bc5b60 (1892 bytes) */
int TPPStreamCompiler__assignOperands(this, param_2, param_3, param_4)
  unsigned char * this;
  unsigned char ** param_2;
  unsigned char ** param_3;
  int param_4;
{
  ushort uVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int *a0;
  int iVar6;
  char *p0;
  unsigned char * pPVar7;
  unsigned char * pPVar8;
  void *this_00;
  unsigned char * extraout_r4;
  unsigned char * extraout_r4_00;
  unsigned char * extraout_r4_01;
  unsigned char * extraout_r4_02;
  unsigned char * extraout_r4_03;
  unsigned char ** ppPVar9;
  undefined4 in_r7;
  undefined4 in_r8;
  undefined4 in_r9;
  int iVar10;
  undefined4 in_r10;
  int iVar11;
  int iVar12;
  unsigned char ** a0_00;
  int a1;
  unsigned char * pPVar13;
  uint local_c0;
  uint local_bc;
  uint local_b0;
  uint local_ac;
  uint local_a8;
  uint local_a4;
  uint local_a0;
  uint local_9c;
  uint local_98;
  uint local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  uint local_70;
  uint local_6c;
  unsigned char * local_60 [4];
  unsigned char * local_50 [4];
  
  ppPVar9 = param_3;
  iVar12 = param_4;
  ((int (*)())__ZN17TPPStreamCompiler22IndirectAddressHandlerEPP12ParseOperandS2_)(this,param_2,param_3);
  local_60[0] = *param_2;
  bVar2 = false;
  local_60[1] = *param_3;
  if ((*(short *)(*(int *)local_60[0] + 0x2c) == 0x7ffe) ||
     (*(short *)(*(int *)local_60[0] + 0x2c) == 0x7fff)) {
    iVar4 = ((int (*)())TPPStreamCompiler__generateAddressLoad)(this,local_60[0]);
    if (iVar4 != 0) {
      TPPStreamCompiler__assignOperands__destIndirect = 1;
    }
    iVar5 = ((int (*)())TPPStreamCompiler__generateAddressLoad)(this,local_60[1]);
    if (iVar5 != 0) {
      TPPStreamCompiler__assignOperands__sourceIndirect = 1;
    }
    bVar2 = iVar5 != 0 || iVar4 != 0;
  }
  iVar4 = *(int *)local_60[0];
  if (*(short *)(iVar4 + 0x2c) == 0x7ffe) {
    iVar4 = *(int *)(*(int *)(iVar4 + 0xc) + 8);
    if (iVar4 != 0) {
      iVar10 = *(int *)(iVar4 + 4);
      iVar5 = *(int *)(iVar4 + 8) - iVar10 >> 3;
      pPVar7 = local_60[0];
      if (iVar5 != 0) {
        while( true ) {
          iVar5 = iVar5 + -1;
          iVar11 = 0;
          while( true ) {
            a0 = *(int **)(iVar10 + iVar5 * 8);
            a0_00 = *(unsigned char ***)(*(int *)local_60[iVar11] + 0x14);
            iVar10 = (**(code **)(*a0 + 0x1c))
                               (a0,pPVar7,ppPVar9,iVar12,in_r7,in_r8,local_60[iVar11]);
            *(undefined1 *)(*(int *)(iVar10 + 4) + *(int *)(*(int *)(iVar10 + 4) + -0xc)) =
                 *DAT_a7b7bd9c;
            a1 = *(int *)(iVar10 + 4);
            iVar10 = _strlen(a1);
            iVar10 = iVar10 + 1;
            if (a0_00 != (unsigned char **)0x0) {
              iVar6 = _strlen(a0_00);
              iVar10 = iVar10 + iVar6 + 1;
            }
            p0 = (char *)_malloc(iVar10);
            if (a0_00 == (unsigned char **)0x0) {
              _strcpy(p0,a1);
            }
            else {
              _sprintf(p0,DAT_a7b7bd8c,(int)a0_00,a1);
              ppPVar9 = a0_00;
              iVar12 = a1;
            }
            pPVar7 = operator_new(0x38);
            __ZN12ParseOperandC1Ev(pPVar7);
            local_60[iVar11 + 2] = pPVar7;
            pPVar8 = operator_new(100);
            __ZN11ParseSymbolC1Ev(pPVar8);
            ParseSymbol__SetName(pPVar8,p0);
            _free(p0);
            *(undefined4 *)(pPVar8 + 0x3c) = 0;
            *(undefined4 *)(pPVar8 + 0x40) = 0;
            ParseSymbol__SetParseTreeType(pPVar8,*(unsigned char **)(*(int *)(iVar4 + 4) + iVar5 * 8));
            *(undefined4 *)(pPVar8 + 0x28) = *(undefined4 *)(*(int *)local_60[iVar11] + 0x28);
            *(unsigned char **)local_60[iVar11 + 2] = pPVar8;
            pPVar7 = extraout_r4;
            if ((*(short *)(pPVar8 + 0x2c) != 0x7ffe) && (*(short *)(pPVar8 + 0x2c) != 0x7fff)) {
              ParseSymbolTable__processOperand
                        (*(unsigned char **)(this + 0x68),local_60[iVar11 + 2]);
              pPVar7 = extraout_r4_00;
            }
            iVar11 = iVar11 + 1;
            if (1 < iVar11) break;
            iVar10 = *(int *)(iVar4 + 4);
          }
          ppPVar9 = local_60 + 3;
          iVar12 = param_4;
          ((int (*)())TPPStreamCompiler__assignOperands)(this,local_60 + 2,ppPVar9,param_4);
          pPVar13 = local_60[2];
          pPVar7 = extraout_r4_01;
          if (local_60[2] != (void *)0x0) {
            __ZN12ParseOperandD1Ev(local_60[2]);
            __ZdlPv(pPVar13);
            pPVar7 = extraout_r4_02;
          }
          pPVar13 = local_60[3];
          if (local_60[3] != (void *)0x0) {
            __ZN12ParseOperandD1Ev(local_60[3]);
            __ZdlPv(pPVar13);
            pPVar7 = extraout_r4_03;
          }
          if (iVar5 == 0) break;
          iVar10 = *(int *)(iVar4 + 4);
        }
      }
    }
  }
  else if (*(short *)(iVar4 + 0x2c) == 0x7fff) {
    uVar3 = (uint)*(short *)(iVar4 + 0x2e);
    while (uVar3 != 0) {
      uVar3 = uVar3 - 1;
      iVar4 = 0;
      iVar12 = 1;
      do {
        this_00 = operator_new(0x38);
        __ZN12ParseOperandC1Ev(this_00);
        *(void **)((int)local_60 + iVar4 + 0x10) = this_00;
        pPVar8 = operator_new(100);
        __ZN11ParseSymbolC1Ev(pPVar8);
        ParseSymbol__SetName(pPVar8,*(char **)(**(int **)((int)local_60 + iVar4) + 0x14));
        ParseSymbol__AddDirectIndex(pPVar8,uVar3);
        _sprintf((char *)&local_c0,DAT_a7b7bd90,uVar3);
        ParseSymbol__CatName(pPVar8,(char *)&local_c0);
        *(undefined4 *)(pPVar8 + 0x40) = 0;
        *(undefined4 *)(pPVar8 + 0x3c) = 0;
        ParseSymbol__SetParseTreeType(pPVar8,*(unsigned char **)(**(int **)((int)local_60 + iVar4) + 0xc));
        iVar5 = **(int **)((int)local_60 + iVar4);
        *(undefined4 *)(pPVar8 + 0x48) = 1;
        *(undefined4 *)(pPVar8 + 0x28) = *(undefined4 *)(iVar5 + 0x28);
        ParseSymbol__ResolveOpenGLType(pPVar8);
        **(undefined4 **)((int)local_60 + iVar4 + 0x10) = pPVar8;
        if ((*(short *)(pPVar8 + 0x2c) != 0x7ffe) && (*(short *)(pPVar8 + 0x2c) != 0x7fff)) {
          ParseSymbolTable__processOperand
                    (*(unsigned char **)(this + 0x68),
                     *(unsigned char **)((int)local_60 + iVar4 + 0x10));
        }
        iVar12 = iVar12 + -1;
        iVar4 = iVar4 + 4;
      } while (-1 < iVar12);
      ((int (*)())TPPStreamCompiler__assignOperands)(this,local_60 + 4,local_60 + 5,param_4);
      pPVar7 = local_50[0];
      if (local_50[0] != (void *)0x0) {
        __ZN12ParseOperandD1Ev(local_50[0]);
        __ZdlPv(pPVar7);
      }
      pPVar7 = local_50[1];
      if (local_50[1] != (void *)0x0) {
        __ZN12ParseOperandD1Ev(local_50[1]);
        __ZdlPv(pPVar7);
      }
    }
  }
  else {
    pPVar7 = *(unsigned char **)(this + 0x88);
    local_80 = *(undefined4 *)(this + 0x90);
    local_88 = 0;
    local_84 = 0;
    local_b0 = 0;
    local_ac = 0;
    local_a8 = 0;
    local_a4 = 0;
    local_a0 = 0;
    local_9c = 0;
    local_98 = 0;
    local_94 = 0;
    local_90 = 0;
    local_8c = 0;
    local_7c = 0;
    if (pPVar7 == (unsigned char *)0x0) {
      local_b0 = 0x20000000;
      ((int (*)())TPPStreamCompiler__getOperandAsDestVar)((unsigned char *)&local_c0,this,*param_2,iVar12,in_r7,in_r8);
      local_a8 = local_c0;
      local_a4 = local_bc;
      if (TPPStreamCompiler__assignOperands__destIndirect != 0) {
        local_a4 = local_bc & 0x800fffff | 0x80000000;
      }
      ((int (*)())TPPStreamCompiler__getOperandAsSourceVar)((unsigned char *)&local_c0,this,*param_3,iVar12,in_r7,in_r8,in_r9,in_r10)
      ;
      local_a0 = local_c0;
      local_9c = local_bc;
      if (TPPStreamCompiler__assignOperands__sourceIndirect != 0) {
        (*(unsigned int *)((unsigned char *)&(local_a0) + 0)) = (uint3)(local_c0 >> 8) & 0x8fffff | 0x800000;
        local_a0 = (uint)(*(unsigned int *)((unsigned char *)&(local_a0) + 0)) << 8;
      }
      local_ac = (local_a8 >> 0xc & 1) << 0x1c | local_ac & 0xefffffff;
      iVar12 = *(int *)*param_2;
      if (iVar12 == 0) {
        uVar1 = *(ushort *)(*param_2 + 0x18);
      }
      else {
        uVar1 = *(ushort *)(iVar12 + 0x2c);
      }
      uVar3 = GetPPStreamTypeForGLType((uint)uVar1);
      local_ac = (uVar3 & 7) << 0x17 | local_ac & 0xfc7fffff;
      iVar12 = ParseOperand__GetLogicalSize(*param_2);
      local_ac = (iVar12 + -1) * 0x4000000 & 0xc000000U | local_ac & 0xf3f3ffff;
      local_70 = local_a8;
      local_6c = local_a4;
      local_c0 = local_a0;
      local_bc = local_9c;
      iVar12 = ((int (*)())TPPStreamCompiler__duplicateDestinationSource)(this,local_a8,local_a4,local_a0,local_9c);
      if ((iVar12 == 0) &&
         (((param_4 == 0 || (*(int *)(this + 0xc4) < 2)) ||
          (iVar12 = ((int (*)())TPPStreamCompiler__copyPropagateCompilerTemp)(this,(unsigned char *)&local_b0,*param_3),
          iVar12 == 0)))) {
        _PPStreamAddOperation(*(undefined4 *)(this + 0x70),&local_b0,0,0);
      }
    }
    else {
      pPVar13 = *param_2;
      local_50[2] = *(unsigned char **)(pPVar7 + 0xc);
      if (pPVar13 != (unsigned char *)0x0) {
        __ZN12ParseOperandD1Ev(pPVar13);
        __ZdlPv(pPVar13);
        pPVar7 = *(unsigned char **)(this + 0x88);
      }
      *param_2 = pPVar7;
      ppPVar9 = local_60 + 6;
      *(undefined4 *)(this + 0x88) = 0;
      *(undefined4 *)(*param_2 + 0xc) = 0;
      local_b0 = local_b0 & 0x1c03ffff | 0x41b40000;
      ((int (*)())__ZN17TPPStreamCompiler22IndirectAddressHandlerEPP12ParseOperandS2_S2_)(this,param_2,param_3,ppPVar9);
      ParseOperand__RemoveDirectIndex(*param_2);
      ((int (*)())TPPStreamCompiler__getOperandAsDestVar)((unsigned char *)&local_c0,this,*param_2,ppPVar9,in_r7,in_r8);
      local_a8 = local_c0;
      local_a4 = local_bc;
      ((int (*)())TPPStreamCompiler__getOperandAsSourceVar)((unsigned char *)&local_c0,this,*param_3,ppPVar9,in_r7,in_r8,in_r9,in_r10);
      local_a0 = local_c0;
      local_9c = local_bc;
      ((int (*)())TPPStreamCompiler__getOperandAsSourceVar)((unsigned char *)&local_c0,this,local_50[2],ppPVar9,in_r7,in_r8,in_r9,in_r10);
      local_ac = (local_a8 >> 0xc & 1) << 0x1c | local_ac & 0xefffffff;
      local_98 = local_c0;
      local_94 = local_bc;
      iVar12 = *(int *)*param_2;
      if (iVar12 == 0) {
        uVar1 = *(ushort *)(*param_2 + 0x18);
      }
      else {
        uVar1 = *(ushort *)(iVar12 + 0x2c);
      }
      uVar3 = GetPPStreamTypeForGLType((uint)uVar1);
      local_ac = (uVar3 & 7) << 0x17 | local_ac & 0xfc7fffff;
      iVar12 = ParseOperand__GetLogicalSize(*param_2);
      local_ac = (iVar12 + -1) * 0x4000000 & 0xc000000U | local_ac & 0xf3f3ffff;
      _PPStreamAddOperation(*(undefined4 *)(this + 0x70),&local_b0,0,0);
      pPVar7 = local_50[2];
      if (local_50[2] != (void *)0x0) {
        __ZN12ParseOperandD1Ev(local_50[2]);
        __ZdlPv(pPVar7);
      }
    }
  }
  if (bVar2) {
    TPPStreamCompiler__assignOperands__sourceIndirect = 0;
    TPPStreamCompiler__assignOperands__destIndirect = 0;
  }
  return;
}

/* TPPStreamCompiler__getArrayOffset @ 0x97bc62c4 (404 bytes) */
int TPPStreamCompiler__getArrayOffset(this, param_2)
  unsigned char * this;
  unsigned char * param_2;
{
  bool bVar1;
  byte bVar2;
  undefined4 *puVar3;
  unsigned char * this_00;
  undefined4 in_r7;
  undefined4 in_r8;
  undefined4 in_r10;
  uint uVar4;
  uint uVar5;
  char acStack_30 [20];
  
  uVar4 = 0;
  puVar3 = (undefined4 *)
           ParseSymbolTable__FindFirstElement
                     (*(unsigned char **)(this + 0x68),*(unsigned char **)param_2);
  if (puVar3 != (undefined4 *)0x0) {
    bVar2 = *(byte *)*puVar3;
    if (bVar2 != 2) {
      if (bVar2 < 3) {
        bVar1 = bVar2 == 0;
      }
      else {
        if (bVar2 == 3) goto LAB_97bc632c;
        bVar1 = bVar2 == 4;
      }
      if (!bVar1) goto LAB_97bc6330;
    }
LAB_97bc632c:
    uVar4 = (uint)*(ushort *)((byte *)*puVar3 + 0x12);
  }
LAB_97bc6330:
  this_00 = operator_new(100);
  __ZN11ParseSymbolC1Ev(this_00);
  ParseSymbol__SetName(this_00,*(char **)(*(int *)param_2 + 0x14));
  ParseSymbol__RemoveArrayIndex(this_00);
  ParseSymbol__AddDirectIndex(this_00,1);
  _sprintf(acStack_30,DAT_a7b7bd90,1);
  ParseSymbol__CatName(this_00,acStack_30);
  *(undefined4 *)(this_00 + 0x28) = *(undefined4 *)(*(int *)param_2 + 0x28);
  ParseSymbol__SetParseTreeType(this_00,*(unsigned char **)(*(int *)param_2 + 0xc));
  *(undefined4 *)(this_00 + 0x48) = *(undefined4 *)(*(int *)param_2 + 0x48);
  ParseSymbol__ResolveOpenGLType(this_00);
  puVar3 = (undefined4 *)
           ParseSymbolTable__FindFirstElement(*(unsigned char **)(this + 0x68),this_00);
  if (this_00 != (unsigned char *)0x0) {
    __ZN11ParseSymbolD1Ev(this_00);
    __ZdlPv(this_00);
  }
  if (puVar3 == (undefined4 *)0x0) {
    TPPStreamCompiler__warning(this,(char *)0x0,*(char **)(*(int *)param_2 + 0x14),DAT_a7b7bd3c,in_r7,in_r8,
            *(int *)param_2,in_r10);
    uVar5 = uVar4;
    goto LAB_97bc6440;
  }
  bVar2 = *(byte *)*puVar3;
  if (bVar2 != 2) {
    if (bVar2 < 3) {
      bVar1 = bVar2 == 0;
    }
    else {
      if (bVar2 == 3) goto LAB_97bc6414;
      bVar1 = bVar2 == 4;
    }
    uVar5 = 0;
    if (!bVar1) goto LAB_97bc6440;
  }
LAB_97bc6414:
  uVar5 = (uint)*(ushort *)((byte *)*puVar3 + 0x12);
LAB_97bc6440:
  return uVar5 - uVar4;
}

/* TPPStreamCompiler__constructReplicate @ 0x97bc6458 (640 bytes) */
int TPPStreamCompiler__constructReplicate(param_1, param_2, param_3, param_4)
  unsigned char ** param_1;
  unsigned char ** param_2;
  int param_3;
  undefined4 param_4;
{
  bool bVar1;
  ushort uVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  undefined4 in_r7;
  undefined4 in_r8;
  undefined4 uVar6;
  undefined4 uVar7;
  int iVar8;
  undefined4 local_80;
  uint local_7c;
  uint local_78;
  undefined4 local_74;
  uint local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  unsigned char * local_50;
  undefined4 local_4c;
  uint local_40;
  undefined4 local_3c;
  undefined4 local_30 [6];
  
  local_30[0] = 0;
  ((int (*)())__ZN17TPPStreamCompiler22IndirectAddressHandlerEPP12ParseOperandS2_)(param_1,param_2,(unsigned char **)param_3);
  uVar6 = 0;
  uVar7 = 0;
  local_7c = 0;
  local_50 = param_1[0x24];
  local_4c = 0;
  local_80 = 0x20000000;
  local_58 = 0;
  local_54 = 0;
  local_78 = 0;
  local_74 = 0;
  local_70 = 0;
  local_6c = 0;
  local_68 = 0;
  local_64 = 0;
  local_60 = 0;
  local_5c = 0;
  ((int (*)())TPPStreamCompiler__getOperandAsDestVar)((unsigned char *)&local_40,param_1,*param_2,param_4,in_r7,in_r8);
  piVar5 = *(int **)param_3;
  local_78 = local_40 & 0xfffe1c2f | 0x6c;
  local_74 = local_3c;
  if (*piVar5 == 0) {
    uVar2 = *(ushort *)(piVar5 + 6);
    if (uVar2 == 0x1406) {
      local_30[0] = *(undefined4 *)piVar5[1];
    }
    else {
      if (uVar2 < 0x1407) {
        bVar1 = uVar2 == 0x1404;
      }
      else {
        bVar1 = uVar2 == 0x8b56;
      }
      if (bVar1) {
        local_30[0] = *(undefined4 *)piVar5[1];
      }
    }
    if (*piVar5 == 0) {
      uVar2 = *(ushort *)(piVar5 + 6);
    }
    else {
      uVar2 = *(ushort *)(*piVar5 + 0x2c);
    }
    ((int (*)())TPPStreamCompiler__getConstantAsSourceVar)((unsigned char *)&local_40,(uint)param_1,local_30,1,(uint)uVar2);
  }
  else {
    ((int (*)())TPPStreamCompiler__getOperandAsSourceVar)((unsigned char *)&local_40,param_1,piVar5,param_4,in_r7,in_r8,uVar6,uVar7);
  }
  local_70 = local_40;
  local_6c = local_3c;
  for (iVar8 = 0; iVar3 = ParseOperand__GetLogicalSize(*param_2), iVar8 < iVar3; iVar8 = iVar8 + 1)
  {
    if (iVar8 == 1) {
      local_78 = local_78 & 0xffffff3f | 0x4000;
    }
    else if (iVar8 < 2) {
      if (iVar8 == 0) {
        local_78 = local_78 & 0xfffffcff | 0x2000;
      }
    }
    else if (iVar8 == 2) {
      local_78 = local_78 & 0xffffffcf | 0x8000;
    }
    else if (iVar8 == 3) {
      local_78 = local_78 & 0xfffffff3 | 0x10000;
    }
  }
  local_7c = (local_78 >> 0xc & 1) << 0x1c | local_7c & 0xefffffff;
  iVar8 = *(int *)*param_2;
  if (iVar8 == 0) {
    uVar2 = *(ushort *)(*param_2 + 0x18);
  }
  else {
    uVar2 = *(ushort *)(iVar8 + 0x2c);
  }
  uVar4 = GetPPStreamTypeForGLType((uint)uVar2);
  local_7c = (uVar4 & 7) << 0x17 | local_7c & 0xfc7fffff;
  iVar8 = ParseOperand__GetLogicalSize(*param_2);
  local_7c = (iVar8 + -1) * 0x4000000 & 0xc000000U | local_7c & 0xf3f3ffff;
  ((int (*)())TPPStreamCompiler__AddOperation)((unsigned char *)param_1,param_2,(unsigned char *)&local_80,(char *)0x0,0);
  return 1;
}

/* TPPStreamCompiler__constructDiagonal @ 0x97bc66d8 (1452 bytes) */
int TPPStreamCompiler__constructDiagonal(param_1, param_2, param_3, param_4)
  unsigned char ** param_1;
  unsigned char ** param_2;
  int param_3;
  undefined4 param_4;
{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  ushort uVar4;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  undefined4 in_r7;
  undefined4 in_r8;
  uint uVar9;
  undefined4 in_r10;
  int *piVar10;
  int iVar11;
  undefined4 *puVar12;
  int iVar13;
  undefined4 local_f0;
  uint local_ec;
  uint local_e8;
  undefined4 local_e4;
  uint local_e0;
  undefined4 local_dc;
  undefined4 local_d8;
  undefined4 local_d4;
  undefined4 local_d0;
  undefined4 local_cc;
  undefined4 local_c8;
  undefined4 local_c4;
  unsigned char * local_c0;
  undefined4 local_bc;
  undefined4 local_b0;
  uint local_ac;
  uint local_a8;
  undefined4 local_a4;
  uint local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  unsigned char * local_80;
  undefined4 local_7c;
  undefined4 local_70 [4];
  uint local_60;
  undefined4 local_5c;
  
  ((int (*)())__ZN17TPPStreamCompiler22IndirectAddressHandlerEPP12ParseOperandS2_)(param_1,param_2,(unsigned char **)param_3);
  iVar13 = 0;
  iVar6 = ParseOperand__GetLogicalSize(*param_2);
  iVar7 = ParseOperand__IsMatrix(*param_2);
  iVar11 = iVar6;
  if (iVar7 == 0) {
    iVar11 = 1;
  }
  if (iVar11 != 0) {
    bVar1 = iVar6 != 4;
    puVar12 = local_70;
    do {
      puVar5 = local_70;
      iVar7 = 4;
      do {
        *puVar5 = 0;
        puVar5 = puVar5 + 1;
        iVar7 = iVar7 + -1;
      } while (iVar7 != 0);
      bVar2 = iVar13 == 0;
      if (bVar2) {
        ParseOperand__AddDirectIndex(*param_2,0);
      }
      else {
        *(int *)(*(int *)(*param_2 + 0x20) * 4 + *(int *)(*param_2 + 0x1c) + -4) = iVar13;
      }
      local_80 = param_1[0x24];
      local_7c = 0;
      local_b0 = 0x20000000;
      local_a8 = 0;
      local_a4 = 0;
      local_a0 = 0;
      local_9c = 0;
      local_98 = 0;
      local_94 = 0;
      local_90 = 0;
      local_8c = 0;
      local_88 = 0;
      local_84 = 0;
      local_ac = 0;
      ((int (*)())TPPStreamCompiler__getOperandAsDestVar)((unsigned char *)&local_60,param_1,*param_2,param_4,in_r7,in_r8);
      piVar10 = *(int **)param_3;
      uVar8 = local_60 & 0xfffe1c0f;
      uVar9 = uVar8 | 0x6c;
      local_a4 = local_5c;
      local_a8 = uVar9;
      if (*piVar10 == 0) {
        uVar4 = *(ushort *)(piVar10 + 6);
        if (uVar4 == 0x1406) {
          *puVar12 = *(undefined4 *)piVar10[1];
        }
        else {
          if (uVar4 < 0x1407) {
            bVar3 = uVar4 == 0x1404;
          }
          else {
            bVar3 = uVar4 == 0x8b56;
          }
          if (bVar3) {
            *puVar12 = *(undefined4 *)piVar10[1];
          }
        }
        if (iVar13 == 1) {
          local_a8 = uVar8 | 0x406c;
        }
        else if (iVar13 < 2) {
          if (bVar2) {
            local_a8 = uVar8 | 0x206c;
          }
        }
        else if (iVar13 == 2) {
          local_a8 = uVar8 | 0x806c;
        }
        else if (iVar13 == 3) {
          local_a8 = uVar9 & 0xfffffff3 | 0x1000c;
        }
      }
      else {
        local_ec = 0;
        local_c0 = param_1[0x24];
        local_f0 = 0x20000000;
        local_bc = 0;
        local_e8 = 0;
        local_e4 = 0;
        local_e0 = 0;
        local_dc = 0;
        local_d8 = 0;
        local_d4 = 0;
        local_d0 = 0;
        local_cc = 0;
        local_c8 = 0;
        local_c4 = 0;
        ((int (*)())TPPStreamCompiler__getOperandAsDestVar)((unsigned char *)&local_60,param_1,*param_2,param_4,in_r7,in_r8);
        local_e8 = local_60 & 0xfffe1c03 | 0x6c;
        local_e4 = local_5c;
        ((int (*)())TPPStreamCompiler__getOperandAsSourceVar)((unsigned char *)&local_60,param_1,*(undefined4 *)param_3,param_4,in_r7,in_r8,
                   uVar9,in_r10);
        local_e0 = local_60;
        local_dc = local_5c;
        if (iVar13 == 1) {
          local_e8 = local_e8 & 0xffffff3f | 0x4000;
        }
        else if (iVar13 < 2) {
          if (bVar2) {
            local_e8 = local_e8 & 0xfffffcff | 0x2000;
          }
        }
        else if (iVar13 == 2) {
          local_e8 = local_e8 & 0xffffffcf | 0x8000;
        }
        else if (iVar13 == 3) {
          local_e8 = local_e8 & 0xfffffff3 | 0x10000;
        }
        local_ec = (local_e8 >> 0xc & 1) << 0x1c | local_ec & 0xefffffff;
        iVar7 = *(int *)*param_2;
        if (iVar7 == 0) {
          uVar4 = *(ushort *)(*param_2 + 0x18);
        }
        else {
          uVar4 = *(ushort *)(iVar7 + 0x2c);
        }
        uVar8 = GetPPStreamTypeForGLType((uint)uVar4);
        local_ec = (uVar8 & 7) << 0x17 | local_ec & 0xfc7fffff;
        iVar7 = ParseOperand__GetLogicalSize(*param_2);
        local_ec = (iVar7 + -1) * 0x4000000 & 0xc000000U | local_ec & 0xf3f3ffff;
        ((int (*)())TPPStreamCompiler__AddOperation)((unsigned char *)param_1,param_2,(unsigned char *)&local_f0,
                     (char *)0x0,0);
        piVar10 = *(int **)param_3;
      }
      if (iVar13 == 1) {
        uVar8 = local_a8 & 0xfffffcff | 0x2000;
        if (iVar6 != 3) {
          if (bVar1) goto LAB_97bc6b98;
          uVar8 = local_a8 & 0xfffffcf3 | 0x1200c;
        }
LAB_97bc6b90:
        uVar8 = uVar8 & 0xffffffcf | 0x8020;
      }
      else {
        uVar8 = local_a8;
        if (iVar13 < 2) {
          if (bVar2) {
            if (iVar6 == 3) {
LAB_97bc6ae0:
              local_a8 = local_a8 & 0xffffffcf | 0x8020;
LAB_97bc6af8:
              uVar8 = local_a8 & 0xffffff3f | 0x4040;
            }
            else if (iVar6 < 4) {
              if (iVar6 == 2) goto LAB_97bc6af8;
            }
            else if (!bVar1) {
              local_a8 = local_a8 & 0xfffffff3 | 0x1000c;
              goto LAB_97bc6ae0;
            }
          }
        }
        else if (iVar13 == 2) {
          uVar8 = local_a8 & 0xfffffc3f | 0x6040;
          if (!bVar1) {
            uVar8 = local_a8 & 0xfffffc33 | 0x1604c;
          }
        }
        else if (iVar13 == 3) {
          uVar8 = local_a8 & 0xfffffc3f | 0x6040;
          goto LAB_97bc6b90;
        }
      }
LAB_97bc6b98:
      local_a8 = uVar8;
      if (*piVar10 == 0) {
        uVar4 = *(ushort *)(piVar10 + 6);
      }
      else {
        uVar4 = *(ushort *)(*piVar10 + 0x2c);
      }
      ((int (*)())TPPStreamCompiler__getConstantAsSourceVar)((unsigned char *)&local_60,(uint)param_1,local_70,iVar6,(uint)uVar4);
      local_ac = (local_a8 >> 0xc & 1) << 0x1c | local_ac & 0xefffffff;
      local_a0 = local_60;
      local_9c = local_5c;
      iVar7 = *(int *)*param_2;
      if (iVar7 == 0) {
        uVar4 = *(ushort *)(*param_2 + 0x18);
      }
      else {
        uVar4 = *(ushort *)(iVar7 + 0x2c);
      }
      uVar8 = GetPPStreamTypeForGLType((uint)uVar4);
      local_ac = (uVar8 & 7) << 0x17 | local_ac & 0xfc7fffff;
      iVar13 = iVar13 + 1;
      iVar7 = ParseOperand__GetLogicalSize(*param_2);
      local_ac = (iVar7 + -1) * 0x4000000 & 0xc000000U | local_ac & 0xf3f3ffff;
      param_4 = 0;
      in_r7 = 0;
      ((int (*)())TPPStreamCompiler__AddOperation)((unsigned char *)param_1,param_2,(unsigned char *)&local_b0,(char *)0x0,
                   0);
      puVar12 = puVar12 + 1;
    } while (iVar13 != iVar11);
  }
  ParseOperand__RemoveDirectIndex(*param_2);
  return 1;
}

/* TPPStreamCompiler__constructElement @ 0x97bc6c84 (1744 bytes) */
int TPPStreamCompiler__constructElement(this, param_2, param_3, param_4)
  unsigned char * this;
  unsigned char ** param_2;
  unsigned char ** param_3;
  int param_4;
{
  bool bVar1;
  ushort uVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  undefined4 *in_r7;
  uint in_r8;
  undefined4 uVar8;
  int in_r10;
  uint uVar9;
  uint uVar10;
  undefined1 *puVar11;
  uint uVar12;
  int iVar13;
  int iVar14;
  unsigned char ** ppPVar15;
  int iVar16;
  int iVar17;
  undefined4 local_100;
  uint local_fc;
  uint local_f8;
  undefined4 local_f4;
  uint local_f0;
  undefined4 local_ec;
  undefined4 local_e8;
  undefined4 local_e4;
  undefined4 local_e0;
  undefined4 local_dc;
  undefined4 local_d8;
  undefined4 local_d4;
  undefined4 local_d0;
  undefined4 local_cc;
  undefined4 local_c0;
  uint local_bc;
  uint local_b8;
  undefined4 local_b4;
  uint local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_80 [4];
  uint local_70;
  undefined4 local_6c;
  int local_60;
  int local_5c;
  uint local_58;
  uint local_54;
  
  iVar13 = param_4;
  ppPVar15 = param_3;
  if (0 < param_4) {
    do {
      ((int (*)())__ZN17TPPStreamCompiler22IndirectAddressHandlerEPP12ParseOperandS2_)(this,param_2,ppPVar15);
      iVar13 = iVar13 + -1;
      ppPVar15 = ppPVar15 + 1;
    } while (iVar13 != 0);
  }
  local_60 = 0;
  uVar9 = 0;
  iVar4 = ParseOperand__GetLogicalSize(*param_2);
  uVar12 = 0;
  iVar5 = ParseOperand__IsMatrix(*param_2);
  local_5c = 0;
  iVar13 = iVar4;
  if (iVar5 == 0) {
    iVar13 = 1;
  }
  local_58 = 0xffffffff;
  local_54 = 0;
  uVar10 = 0;
  iVar5 = -1;
  if (iVar13 != 0) {
    do {
      bVar1 = local_5c == 0;
      if ((bVar1) || (uVar10 != 0)) {
        iVar17 = 4;
        puVar3 = local_80;
        do {
          *puVar3 = 0;
          puVar3 = puVar3 + 1;
          iVar17 = iVar17 + -1;
        } while (iVar17 != 0);
        uVar10 = 0;
      }
      iVar16 = 0;
      iVar17 = ParseOperand__IsMatrix(*param_2);
      if (iVar17 != 0) {
        if (bVar1) {
          ParseOperand__AddDirectIndex(*param_2,0);
        }
        else {
          *(int *)(*(int *)(*param_2 + 0x20) * 4 + *(int *)(*param_2 + 0x1c) + -4) = local_5c;
        }
      }
      local_bc = 0;
      local_90 = *(undefined4 *)(this + 0x90);
      local_c0 = 0x20000000;
      bVar1 = iVar4 == 0;
      local_b8 = 0;
      local_b4 = 0;
      local_b0 = 0;
      local_ac = 0;
      local_a8 = 0;
      local_a4 = 0;
      local_a0 = 0;
      local_9c = 0;
      local_98 = 0;
      local_94 = 0;
      local_8c = 0;
      ((int (*)())TPPStreamCompiler__getOperandAsDestVar)((unsigned char *)&local_70,this,*param_2,param_4,in_r7,in_r8);
      local_b8 = local_70 & 0xfffe1c2f | 0x6c;
      local_b4 = local_6c;
      if (!bVar1) {
        puVar11 = &STACKARG(0xfffffec0) + uVar10 * 4;
        uVar7 = in_r8;
        do {
          iVar17 = iVar5 << 2;
          in_r8 = uVar12;
          if (uVar12 == uVar9) {
            local_58 = local_58 + 1;
            if (local_58 == local_54) {
              iVar5 = iVar5 + 1;
              iVar17 = iVar5 * 4;
              local_60 = local_60 + 1;
              uVar9 = ParseOperand__GetLogicalSize(param_3[iVar5]);
              iVar6 = ParseOperand__IsMatrix(param_3[iVar5]);
              if ((iVar6 == 0) || (local_54 = uVar9, *(int *)(param_3[iVar5] + 0x20) != 0)) {
                local_54 = 1;
              }
              local_58 = 0;
            }
            in_r8 = 0;
            if (1 < (int)local_54) {
              if (local_58 == 0) {
                ParseOperand__AddDirectIndex(*(unsigned char **)(iVar17 + (int)param_3),0);
              }
              else {
                *(uint *)(*(int *)(*(int *)(iVar17 + (int)param_3) + 0x20) * 4 +
                          *(int *)(*(int *)(iVar17 + (int)param_3) + 0x1c) + -4) = local_58;
              }
            }
          }
          uVar12 = in_r8;
          if (**(int **)(iVar17 + (int)param_3) == 0) {
            iVar6 = uVar9 - in_r8;
            if (iVar4 - iVar16 < (int)(uVar9 - in_r8)) {
              iVar6 = iVar4 - iVar16;
            }
            if ((int)in_r8 < (int)(in_r8 + iVar6)) {
              iVar6 = (in_r8 + iVar6) - in_r8;
              param_4 = 0x8b56;
              in_r7 = (undefined4 *)(puVar11 + 0xc0);
              do {
                iVar14 = **(int **)(iVar17 + (int)param_3);
                if (iVar14 == 0) {
                  uVar2 = *(ushort *)(*(int **)(iVar17 + (int)param_3) + 6);
                }
                else {
                  uVar2 = *(ushort *)(iVar14 + 0x2c);
                }
                if (uVar2 == 0x1406) {
                  local_80[uVar10] =
                       *(undefined4 *)(in_r8 * 4 + *(int *)(*(int *)(iVar17 + (int)param_3) + 4));
                }
                else if (uVar2 < 0x1407) {
                  if (uVar2 == 0x1404) {
                    in_r10 = in_r8 * 4;
                    local_80[uVar10] =
                         *(undefined4 *)(in_r10 + *(int *)(*(int *)(iVar17 + (int)param_3) + 4));
                  }
                }
                else if (uVar2 == 0x8b56) {
                  *in_r7 = *(undefined4 *)
                            (in_r8 * 4 + *(int *)(*(int *)(iVar17 + (int)param_3) + 4));
                }
                if (iVar16 == 1) {
                  local_b8 = (uVar10 & 3) << 6 | local_b8 & 0xffffff3f | 0x4000;
                }
                else if (iVar16 < 2) {
                  if (iVar16 == 0) {
                    local_b8 = (uVar10 & 3) << 8 | local_b8 & 0xfffffcff | 0x2000;
                  }
                }
                else if (iVar16 == 2) {
                  local_b8 = (uVar10 & 3) << 4 | local_b8 & 0xffffffcf | 0x8000;
                }
                else if (iVar16 == 3) {
                  local_b8 = (uVar10 & 3) << 2 | local_b8 & 0xfffffff3 | 0x10000;
                }
                iVar16 = iVar16 + 1;
                uVar10 = uVar10 + 1;
                puVar11 = puVar11 + 4;
                in_r7 = in_r7 + 1;
                uVar12 = uVar12 + 1;
                in_r8 = in_r8 + 1;
                iVar6 = iVar6 + -1;
              } while (iVar6 != 0);
              bVar1 = iVar16 == iVar4;
            }
          }
          else {
            local_fc = 0;
            uVar8 = 1;
            local_d0 = *(undefined4 *)(this + 0x90);
            iVar14 = 0;
            local_100 = 0x20000000;
            local_f8 = 0;
            local_f4 = 0;
            local_f0 = 0;
            local_ec = 0;
            local_e8 = 0;
            local_e4 = 0;
            local_e0 = 0;
            local_dc = 0;
            local_d8 = 0;
            local_d4 = 0;
            local_cc = 0;
            ((int (*)())TPPStreamCompiler__getOperandAsDestVar)((unsigned char *)&local_70,this,*param_2,param_4,in_r7,uVar7);
            local_f8 = local_70 & 0xfffe1c2f | 0x6c;
            local_f4 = local_6c;
            ((int (*)())TPPStreamCompiler__getOperandAsSourceVar)((unsigned char *)&local_70,this,*(undefined4 *)(iVar17 + (int)param_3),param_4
                       ,in_r7,uVar7,uVar8,in_r10);
            local_f0 = local_70;
            local_ec = local_6c;
            iVar6 = uVar9 - in_r8;
            if (iVar4 - iVar16 < (int)(uVar9 - in_r8)) {
              iVar6 = iVar4 - iVar16;
            }
            if (0 < iVar6) {
              do {
                if (iVar16 == 1) {
                  local_f8 = (in_r8 & 3) << 6 | local_f8 & 0xffffff3f | 0x4000;
LAB_97bc704c:
                  iVar14 = iVar14 + 1;
                }
                else {
                  if (1 < iVar16) {
                    if (iVar16 == 2) {
                      local_f8 = (in_r8 & 3) << 4 | local_f8 & 0xffffffcf | 0x8000;
                    }
                    else {
                      if (iVar16 != 3) goto LAB_97bc7050;
                      local_f8 = (in_r8 & 3) << 2 | local_f8 & 0xfffffff3 | 0x10000;
                    }
                    goto LAB_97bc704c;
                  }
                  if (iVar16 == 0) {
                    local_f8 = (in_r8 & 3) << 8 | local_f8 & 0xfffffcff | 0x2000;
                    goto LAB_97bc704c;
                  }
                }
LAB_97bc7050:
                in_r8 = in_r8 + 1;
                iVar16 = iVar16 + 1;
                iVar6 = iVar6 + -1;
              } while (iVar6 != 0);
              bVar1 = iVar16 == iVar4;
              uVar12 = in_r8;
            }
            in_r8 = uVar7;
            if (((1 < iVar13) || (*(int *)(this + 0xc4) < 2)) ||
               (iVar17 = ((int (*)())TPPStreamCompiler__copyPropagateCompilerTemp)(this,(unsigned char *)&local_100,
                                    *(unsigned char **)(iVar17 + (int)param_3)), in_r8 = uVar7,
               iVar17 == 0)) {
              local_fc = (local_f8 >> 0xc & 1) << 0x1c | local_fc & 0xefffffff;
              iVar17 = *(int *)*param_2;
              if (iVar17 == 0) {
                uVar2 = *(ushort *)(*param_2 + 0x18);
              }
              else {
                uVar2 = *(ushort *)(iVar17 + 0x2c);
              }
              uVar7 = GetPPStreamTypeForGLType((uint)uVar2);
              local_fc = (iVar14 + -1) * 0x4000000 & 0xc000000U |
                         (uVar7 & 7) << 0x17 | local_fc & 0xf073ffff;
              param_4 = 0;
              in_r7 = (undefined4 *)0x0;
              ((int (*)())TPPStreamCompiler__AddOperation)(this,param_2,(unsigned char *)&local_100,(char *)0x0,0);
            }
          }
          uVar7 = in_r8;
        } while (!bVar1);
      }
      if (uVar10 != 0) {
        iVar17 = *(int *)param_3[iVar5];
        if (iVar17 == 0) {
          uVar2 = *(ushort *)(param_3[iVar5] + 0x18);
        }
        else {
          uVar2 = *(ushort *)(iVar17 + 0x2c);
        }
        ((int (*)())TPPStreamCompiler__getConstantAsSourceVar)((unsigned char *)&local_70,(uint)this,local_80,uVar10,(uint)uVar2);
        local_bc = (local_b8 >> 0xc & 1) << 0x1c | local_bc & 0xefffffff;
        local_b0 = local_70;
        local_ac = local_6c;
        iVar17 = *(int *)*param_2;
        if (iVar17 == 0) {
          uVar2 = *(ushort *)(*param_2 + 0x18);
        }
        else {
          uVar2 = *(ushort *)(iVar17 + 0x2c);
        }
        uVar7 = GetPPStreamTypeForGLType((uint)uVar2);
        local_bc = (uVar10 - 1) * 0x4000000 & 0xc000000 |
                   (uVar7 & 7) << 0x17 | local_bc & 0xf073ffff;
        param_4 = 0;
        in_r7 = (undefined4 *)0x0;
        ((int (*)())TPPStreamCompiler__AddOperation)(this,param_2,(unsigned char *)&local_c0,(char *)0x0,0);
      }
      local_5c = local_5c + 1;
    } while (local_5c != iVar13);
  }
  iVar13 = ParseOperand__IsMatrix(*param_2);
  if (iVar13 != 0) {
    ParseOperand__RemoveDirectIndex(*param_2);
  }
  return local_60;
}

/* TPPStreamCompiler__constructFromOperand @ 0x97bc7354 (1620 bytes) */
int TPPStreamCompiler__constructFromOperand(this, param_2, param_3, param_4)
  unsigned char * this;
  unsigned char ** param_2;
  unsigned char ** param_3;
  int param_4;
{
  bool bVar1;
  short sVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  char *pcVar6;
  unsigned char * pPVar7;
  unsigned char ** ppPVar8;
  int iVar9;
  int iVar10;
  unsigned char * this_00;
  unsigned char ** extraout_r4;
  unsigned char ** extraout_r4_00;
  unsigned char ** extraout_r4_01;
  unsigned char ** extraout_r4_02;
  unsigned char ** a2;
  uint uVar11;
  undefined4 in_r7;
  undefined4 in_r8;
  unsigned char * pPVar12;
  uint a6;
  uint uVar13;
  uint uVar14;
  int iVar15;
  int iVar16;
  uint uVar17;
  void *this_01;
  uint uVar18;
  undefined4 uVar19;
  undefined8 uVar20;
  char acStack_70 [16];
  unsigned char * local_60;
  unsigned char * local_5c;
  int local_58;
  int local_54;
  
  pPVar12 = *param_2;
  iVar15 = 0;
  iVar16 = 0;
  if (pPVar12 != (unsigned char *)0x0) {
    iVar3 = *(int *)pPVar12;
    sVar2 = *(short *)(iVar3 + 0x2c);
    iVar16 = iVar15;
    if (sVar2 == 0x7ffe) {
      local_58 = *(int *)(iVar3 + 0x14);
      iVar15 = *(int *)(*(int *)(iVar3 + 0xc) + 8);
      if (iVar15 != 0) {
        uVar14 = 0;
        iVar3 = *(int *)(iVar15 + 4);
        uVar13 = *(int *)(iVar15 + 8) - iVar3 >> 3;
        if (uVar13 != 0) {
          a6 = 0xa7b7736c;
          bVar1 = local_58 == 0;
          local_54 = -0x58488c94;
          a2 = param_3;
          uVar11 = param_4;
          while( true ) {
            piVar4 = *(int **)(iVar3 + uVar14 * 8);
            iVar3 = (**(code **)(*piVar4 + 0x1c))(piVar4,param_2,a2,uVar11,in_r7,in_r8,a6);
            a6 = *(uint *)(*(int *)(iVar3 + 4) + -0xc);
            *(undefined1 *)(*(int *)(iVar3 + 4) + a6) = **(undefined1 **)(local_54 + 0x4a30);
            uVar18 = *(uint *)(iVar3 + 4);
            iVar3 = _strlen(uVar18);
            iVar3 = iVar3 + 1;
            if (!bVar1) {
              iVar5 = _strlen(local_58);
              iVar3 = iVar3 + iVar5 + 1;
            }
            pcVar6 = (char *)_malloc(iVar3);
            if (bVar1) {
              _strcpy(pcVar6,uVar18);
            }
            else {
              _sprintf(pcVar6,DAT_a7b7bd8c,local_58,uVar18);
              uVar11 = uVar18;
            }
            pPVar12 = operator_new(0x38);
            __ZN12ParseOperandC1Ev(pPVar12);
            local_60 = pPVar12;
            pPVar7 = operator_new(100);
            __ZN11ParseSymbolC1Ev(pPVar7);
            ParseSymbol__SetName(pPVar7,pcVar6);
            _free(pcVar6);
            ParseSymbol__SetParseTreeType(pPVar7,*(unsigned char **)(*(int *)(iVar15 + 4) + uVar14 * 8));
            *(unsigned char **)local_60 = pPVar7;
            if ((*(short *)(pPVar7 + 0x2c) == 0x7ffe) || (*(short *)(pPVar7 + 0x2c) == 0x7fff)) {
              a2 = param_3 + iVar16;
              iVar3 = *(int *)param_3[iVar16];
              if (*(short *)(iVar3 + 0x2c) == 0x7ffe) {
                iVar5 = *(int *)(iVar3 + 0x14);
                iVar3 = *(int *)(*(int *)(iVar3 + 0xc) + 8);
                param_2 = extraout_r4;
                if (iVar3 != 0) {
                  uVar11 = 0;
                  uVar18 = *(int *)(iVar3 + 8) - *(int *)(iVar3 + 4) >> 3;
                  ppPVar8 = (unsigned char **)_malloc(uVar13 << 2);
                  if (uVar18 != 0) {
                    do {
                      piVar4 = *(int **)(*(int *)(iVar3 + 4) + uVar11 * 8);
                      iVar9 = (**(code **)(*piVar4 + 0x1c))(piVar4);
                      a6 = (uint)*DAT_a7b7bd9c;
                      *(byte *)(*(int *)(iVar9 + 4) + *(int *)(*(int *)(iVar9 + 4) + -0xc)) =
                           *DAT_a7b7bd9c;
                      uVar19 = *(undefined4 *)(iVar9 + 4);
                      iVar9 = _strlen(uVar19);
                      iVar9 = iVar9 + 1;
                      if (iVar5 != 0) {
                        iVar10 = _strlen(iVar5);
                        iVar9 = iVar9 + iVar10 + 1;
                      }
                      pcVar6 = (char *)_malloc(iVar9);
                      if (iVar5 == 0) {
                        _strcpy(pcVar6,uVar19);
                      }
                      else {
                        _sprintf(pcVar6,DAT_a7b7bd8c,iVar5,uVar19);
                      }
                      pPVar12 = operator_new(0x38);
                      __ZN12ParseOperandC1Ev(pPVar12);
                      ppPVar8[uVar11] = pPVar12;
                      this_00 = operator_new(100);
                      __ZN11ParseSymbolC1Ev(this_00);
                      ParseSymbol__SetName(this_00,pcVar6);
                      _free(pcVar6);
                      ParseSymbol__SetParseTreeType
                                (this_00,*(unsigned char **)(*(int *)(iVar3 + 4) + uVar11 * 8));
                      *(unsigned char **)ppPVar8[uVar11] = this_00;
                      if ((*(short *)(this_00 + 0x2c) != 0x7ffe) &&
                         (*(short *)(this_00 + 0x2c) != 0x7fff)) {
                        ParseSymbolTable__processOperand
                                  (*(unsigned char **)(this + 0x68),ppPVar8[uVar11]);
                      }
                      uVar11 = uVar11 + 1;
                    } while (uVar11 < uVar18);
                  }
                  uVar17 = 0;
                  a2 = ppPVar8;
                  uVar11 = uVar18;
                  ((int (*)())TPPStreamCompiler__constructFromOperand)(this,&local_60,ppPVar8,uVar18);
                  iVar16 = iVar16 + 1;
                  if (uVar18 != 0) {
                    do {
                      this_01 = *(void **)ppPVar8[uVar17];
                      if (((*(short *)((int)this_01 + 0x2c) == 0x7ffe) ||
                          (*(short *)((int)this_01 + 0x2c) == 0x7fff)) && (this_01 != (void *)0x0))
                      {
                        __ZN11ParseSymbolD1Ev(this_01);
                        __ZdlPv(this_01);
                      }
                      pPVar12 = ppPVar8[uVar17];
                      if (pPVar12 != (unsigned char *)0x0) {
                        __ZN12ParseOperandD1Ev(pPVar12);
                        __ZdlPv(pPVar12);
                      }
                      uVar17 = uVar17 + 1;
                    } while (uVar17 < uVar18);
                  }
                  _free(ppPVar8);
                  param_2 = extraout_r4_00;
                }
              }
              else {
                uVar11 = param_4 - iVar16;
                uVar20 = ((int (*)())TPPStreamCompiler__constructFromOperand)(this,&local_60,a2,uVar11);
                param_2 = (unsigned char **)uVar20;
                iVar16 = iVar16 + (int)((ulonglong)uVar20 >> 0x20);
              }
              if (pPVar7 != (unsigned char *)0x0) {
                __ZN11ParseSymbolD1Ev(pPVar7);
                __ZdlPv(pPVar7);
                param_2 = extraout_r4_01;
              }
              *(undefined4 *)local_60 = 0;
            }
            else {
              ParseSymbolTable__processOperand(*(unsigned char **)(this + 0x68),local_60);
              uVar11 = param_4 - iVar16;
              a2 = param_3 + iVar16;
              uVar20 = ((int (*)())TPPStreamCompiler__constructFromOperand)(this,&local_60,a2,uVar11);
              param_2 = (unsigned char **)uVar20;
              iVar16 = iVar16 + (int)((ulonglong)uVar20 >> 0x20);
            }
            pPVar12 = local_60;
            if (local_60 != (unsigned char *)0x0) {
              __ZN12ParseOperandD1Ev(local_60);
              __ZdlPv(pPVar12);
              param_2 = extraout_r4_02;
            }
            uVar14 = uVar14 + 1;
            if (uVar13 <= uVar14) break;
            iVar3 = *(int *)(iVar15 + 4);
          }
        }
      }
    }
    else if (sVar2 == 0x7fff) {
      uVar13 = 0;
      if (0 < *(short *)(iVar3 + 0x2e)) {
        do {
          pPVar12 = operator_new(0x38);
          __ZN12ParseOperandC1Ev(pPVar12);
          local_5c = pPVar12;
          pPVar7 = operator_new(100);
          __ZN11ParseSymbolC1Ev(pPVar7);
          ParseSymbol__SetName(pPVar7,*(char **)(*(int *)*param_2 + 0x14));
          ParseSymbol__AddDirectIndex(pPVar7,uVar13);
          _sprintf(acStack_70,DAT_a7b7bd90,uVar13);
          ParseSymbol__CatName(pPVar7,acStack_70);
          ParseSymbol__SetParseTreeType(pPVar7,*(unsigned char **)(*(int *)*param_2 + 0xc));
          *(undefined4 *)(pPVar7 + 0x48) = 1;
          ParseSymbol__ResolveOpenGLType(pPVar7);
          *(unsigned char **)local_5c = pPVar7;
          if ((*(short *)(pPVar7 + 0x2c) == 0x7ffe) || (*(short *)(pPVar7 + 0x2c) == 0x7fff)) {
            iVar16 = ((int (*)())TPPStreamCompiler__constructFromOperand)(this,&local_5c,param_3 + iVar15,param_4 - iVar15);
            if (pPVar7 != (unsigned char *)0x0) {
              __ZN11ParseSymbolD1Ev(pPVar7);
              __ZdlPv(pPVar7);
            }
            *(undefined4 *)local_5c = 0;
          }
          else {
            ParseSymbolTable__processOperand(*(unsigned char **)(this + 0x68),local_5c);
            iVar16 = ((int (*)())TPPStreamCompiler__constructFromOperand)(this,&local_5c,param_3 + iVar15,param_4 - iVar15);
          }
          pPVar12 = local_5c;
          iVar16 = iVar15 + iVar16;
          if (local_5c != (unsigned char *)0x0) {
            __ZN12ParseOperandD1Ev(local_5c);
            __ZdlPv(pPVar12);
          }
          uVar13 = uVar13 + 1;
          iVar15 = iVar16;
        } while ((int)uVar13 < (int)*(short *)(*(int *)*param_2 + 0x2e));
      }
    }
    else {
      if (iVar3 == 0) {
        sVar2 = *(short *)(pPVar12 + 0x18);
      }
      switch(sVar2) {
      case -0x74b0:
      case -0x74af:
      case -0x74ae:
      case -0x74ad:
      case -0x74ac:
      case -0x74ab:
      case -0x74a9:
      case -0x74a8:
      case -0x74a7:
        if ((param_4 == 1) && (iVar16 = ParseOperand__GetLogicalSize(*param_3), iVar16 == 1)) {
          iVar16 = ((int (*)())TPPStreamCompiler__constructReplicate)((unsigned char **)this,param_2,(int)param_3,1);
          return iVar16;
        }
        break;
      case -0x74a6:
      case -0x74a5:
      case -0x74a4:
        if ((param_4 == 1) && (iVar16 = ParseOperand__GetLogicalSize(*param_3), iVar16 == 1)) {
          iVar16 = ((int (*)())TPPStreamCompiler__constructDiagonal)((unsigned char **)this,param_2,(int)param_3,1);
          return iVar16;
        }
      }
      iVar16 = ((int (*)())TPPStreamCompiler__constructElement)(this,param_2,param_3,param_4);
    }
  }
  return iVar16;
}

/* TPPStreamCompiler__construct @ 0x97bc79dc (296 bytes) */
int TPPStreamCompiler__construct(this, param_2, param_3, param_4)
  unsigned char * this;
  unsigned char * param_2;
  unsigned char ** param_3;
  int param_4;
{
  bool bVar1;
  short sVar2;
  short sVar3;
  unsigned char * pPVar4;
  int iVar5;
  int iVar6;
  unsigned char * local_30 [7];
  
  local_30[0] = (unsigned char *)((int (*)())TPPStreamCompiler__newTemporary)(this,param_2);
  if (param_4 == 1) {
    if (*(int *)local_30[0] == 0) {
      sVar2 = *(short *)(local_30[0] + 0x18);
    }
    else {
      sVar2 = *(short *)(*(int *)local_30[0] + 0x2c);
    }
    iVar5 = *(int *)*param_3;
    if (iVar5 == 0) {
      sVar3 = *(short *)(*param_3 + 0x18);
    }
    else {
      sVar3 = *(short *)(iVar5 + 0x2c);
    }
    if (sVar2 == sVar3) {
      iVar5 = ParseOperand__GetLogicalSize(local_30[0]);
      iVar6 = ParseOperand__GetLogicalSize(*param_3);
      if (iVar5 == iVar6) {
        iVar6 = 1;
        iVar5 = ParseOperand__IsMatrix(local_30[0]);
        if (iVar5 != 0) {
          iVar6 = ParseOperand__GetLogicalSize(local_30[0]);
        }
        iVar5 = ParseOperand__IsMatrix(*param_3);
        if ((iVar5 == 0) || (*(int *)(*param_3 + 0x20) != 0)) {
          bVar1 = iVar6 == 1;
        }
        else {
          iVar5 = ParseOperand__GetLogicalSize(*param_3);
          bVar1 = iVar6 == iVar5;
        }
        pPVar4 = local_30[0];
        if (bVar1) {
          if (local_30[0] != (unsigned char *)0x0) {
            __ZN12ParseOperandD1Ev(local_30[0]);
            __ZdlPv(pPVar4);
          }
          return *param_3;
        }
      }
    }
  }
  ((int (*)())TPPStreamCompiler__constructFromOperand)(this,local_30,param_3,param_4);
  return local_30[0];
}

/* TPPStreamCompiler__FinishScalerSelect @ 0x97bc7b04 (464 bytes) */
int TPPStreamCompiler__FinishScalerSelect(this, param_2)
  unsigned char * this;
  unsigned char ** param_2;
{
  ushort uVar1;
  uint uVar2;
  unsigned char ** ppPVar3;
  undefined4 in_r7;
  undefined4 in_r8;
  int iVar4;
  undefined4 uVar5;
  undefined4 in_r10;
  unsigned char * pPVar6;
  uint local_70;
  uint local_6c;
  uint local_68;
  undefined4 local_64;
  uint local_60;
  undefined4 local_5c;
  uint local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  uint local_30;
  undefined4 local_2c;
  unsigned char * local_20 [4];
  
  iVar4 = *(int *)(this + 0x88);
  if (iVar4 != 0) {
    local_20[0] = *(unsigned char **)(iVar4 + 0xc);
    *(undefined4 *)(iVar4 + 0xc) = 0;
    ppPVar3 = local_20;
    uVar5 = *(undefined4 *)(this + 0x90);
    local_3c = 0;
    local_70 = 0x40000000;
    local_6c = 0;
    local_68 = 0;
    local_64 = 0;
    local_60 = 0;
    local_5c = 0;
    local_58 = 0;
    local_54 = 0;
    local_50 = 0;
    local_4c = 0;
    local_48 = 0;
    local_44 = 0;
    local_40 = uVar5;
    ((int (*)())__ZN17TPPStreamCompiler22IndirectAddressHandlerEPP12ParseOperandS2_S2_)(this,(unsigned char **)(this + 0x88),param_2,ppPVar3);
    local_70 = local_70 & 0xfc03ffff | 0x1b40000;
    ParseOperand__RemoveDirectIndex(*(unsigned char **)(this + 0x88));
    ((int (*)())TPPStreamCompiler__getOperandAsDestVar)((unsigned char *)&local_30,this,*(undefined4 *)(this + 0x88),ppPVar3,in_r7,
                        in_r8);
    local_68 = local_30;
    local_64 = local_2c;
    ((int (*)())TPPStreamCompiler__getOperandAsSourceVar)((unsigned char *)&local_30,this,*param_2,ppPVar3,in_r7,in_r8,uVar5,in_r10);
    local_60 = local_30;
    local_5c = local_2c;
    ((int (*)())TPPStreamCompiler__getOperandAsSourceVar)((unsigned char *)&local_30,this,local_20[0],ppPVar3,in_r7,in_r8,uVar5,in_r10);
    local_6c = (local_68 >> 0xc & 1) << 0x1c | local_6c & 0xefffffff;
    local_58 = local_30;
    local_54 = local_2c;
    iVar4 = **(int **)(this + 0x88);
    if (iVar4 == 0) {
      uVar1 = *(ushort *)(*(int **)(this + 0x88) + 6);
    }
    else {
      uVar1 = *(ushort *)(iVar4 + 0x2c);
    }
    uVar2 = GetPPStreamTypeForGLType((uint)uVar1);
    local_6c = (uVar2 & 7) << 0x17 | local_6c & 0xfc7fffff;
    iVar4 = ParseOperand__GetLogicalSize(*(unsigned char **)(this + 0x88));
    local_6c = (iVar4 + -1) * 0x4000000 & 0xc000000U | local_6c & 0xf3f3ffff;
    _PPStreamAddOperation(*(undefined4 *)(this + 0x70),&local_70,0,0);
    pPVar6 = *param_2;
    if (pPVar6 != (unsigned char *)0x0) {
      __ZN12ParseOperandD1Ev(pPVar6);
      __ZdlPv(pPVar6);
    }
    pPVar6 = local_20[0];
    if (local_20[0] != (unsigned char *)0x0) {
      __ZN12ParseOperandD1Ev(local_20[0]);
      __ZdlPv(pPVar6);
    }
    *param_2 = *(unsigned char **)(this + 0x88);
    *(undefined4 *)(this + 0x88) = 0;
  }
  return;
}

/* TPPStreamCompiler__LastOperationIndex @ 0x97bc7cd4 (36 bytes) */
int TPPStreamCompiler__LastOperationIndex(this)
  unsigned char * this;
{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(*(int *)(this + 0x70) + 0x20) + 4);
  if (iVar1 == 0) {
    return 0xffffffff;
  }
  return *(uint *)(iVar1 + 0xc) & 0x3ffff;
}

/* TPPStreamCompiler__AddOperation @ 0x97bc7cf8 (100 bytes) */
int TPPStreamCompiler__AddOperation(this, param_2, param_3, param_4, param_5)
  unsigned char * this;
  unsigned char ** param_2;
  unsigned char * param_3;
  char *param_4;
  uint param_5;
{
  _PPStreamAddOperation(*(undefined4 *)(this + 0x70),param_3,param_4,param_5);
  if (param_2 != (unsigned char **)0x0) {
    ((int (*)())TPPStreamCompiler__FinishScalerSelect)(this,param_2);
    return;
  }
  return;
}

/* __ZN17TPPStreamCompiler22IndirectAddressHandlerEPP12ParseOperandi @ 0x97bc7d5c (952 bytes) */
int __ZN17TPPStreamCompiler22IndirectAddressHandlerEPP12ParseOperandi(this, param_2, param_3)
  void *this;
  unsigned char ** param_2;
  int param_3;
{
  ushort uVar1;
  bool bVar2;
  unsigned char * pPVar3;
  unsigned char ** ppPVar4;
  unsigned char * pTVar5;
  uint uVar6;
  int iVar7;
  undefined4 in_r7;
  undefined4 in_r8;
  undefined4 uVar8;
  undefined4 in_r10;
  int iVar9;
  int iVar10;
  uint local_a0;
  uint local_9c;
  uint local_98;
  undefined4 local_94;
  uint local_90;
  undefined4 local_8c;
  uint local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  uint local_60;
  undefined4 local_5c;
  unsigned char * local_50;
  unsigned char * local_4c;
  unsigned char * local_48 [5];
  
  pPVar3 = *param_2;
  if ((pPVar3 != (unsigned char *)0x0) && (*(int *)(pPVar3 + 0xc) != 0)) {
    *(unsigned char **)((int)this + 0x88) = pPVar3;
    pTVar5 = (unsigned char *)((int (*)())TPPStreamCompiler__newNodeFromOperand)(this,*param_2);
    pPVar3 = (unsigned char *)((int (*)())TPPStreamCompiler__newTemporary)(this,pTVar5);
    *param_2 = pPVar3;
  }
  iVar10 = 1;
  if (1 < param_3) {
    do {
      pPVar3 = *(unsigned char **)(param_2[iVar10] + 0xc);
      if (pPVar3 != (unsigned char *)0x0) {
        *(undefined4 *)(param_2[iVar10] + 0xc) = 0;
        local_9c = 0;
        uVar8 = *(undefined4 *)((int)this + 0x90);
        local_a0 = 0x40000000;
        local_98 = 0;
        local_94 = 0;
        local_90 = 0;
        local_8c = 0;
        local_88 = 0;
        local_84 = 0;
        local_80 = 0;
        local_7c = 0;
        local_78 = 0;
        local_74 = 0;
        local_6c = 0;
        local_70 = uVar8;
        local_4c = pPVar3;
        pTVar5 = (unsigned char *)((int (*)())TPPStreamCompiler__newNodeFromOperand)(this,param_2[iVar10]);
        local_50 = (unsigned char *)((int (*)())TPPStreamCompiler__newTemporary)(this,pTVar5);
        ppPVar4 = &local_4c;
        ((int (*)())__ZN17TPPStreamCompiler22IndirectAddressHandlerEPP12ParseOperandS2_S2_)(this,&local_50,param_2 + iVar10,ppPVar4);
        local_a0 = local_a0 & 0xfc03ffff | 0xe40000;
        ((int (*)())TPPStreamCompiler__getOperandAsDestVar)((unsigned char *)&local_60,this,local_50,ppPVar4,in_r7,in_r8);
        local_98 = local_60;
        local_94 = local_5c;
        ParseOperand__RemoveDirectIndex(param_2[iVar10]);
        ((int (*)())TPPStreamCompiler__getOperandAsSourceVar)((unsigned char *)&local_60,this,param_2[iVar10],ppPVar4,in_r7,in_r8,uVar8,in_r10);
        local_90 = local_60;
        local_8c = local_5c;
        ((int (*)())TPPStreamCompiler__getOperandAsSourceVar)((unsigned char *)&local_60,this,local_4c,ppPVar4,in_r7,in_r8,uVar8,in_r10);
        local_9c = (local_98 >> 0xc & 1) << 0x1c | local_9c & 0xefffffff;
        local_88 = local_60;
        local_84 = local_5c;
        if (*(int *)local_50 == 0) {
          uVar1 = *(ushort *)(local_50 + 0x18);
        }
        else {
          uVar1 = *(ushort *)(*(int *)local_50 + 0x2c);
        }
        uVar6 = GetPPStreamTypeForGLType((uint)uVar1);
        local_9c = (uVar6 & 7) << 0x17 | local_9c & 0xfc7fffff;
        iVar7 = ParseOperand__GetLogicalSize(local_50);
        local_9c = (iVar7 + -1) * 0x4000000 & 0xc000000U | local_9c & 0xf3f3ffff;
        _PPStreamAddOperation(*(undefined4 *)((int)this + 0x70),&local_a0,0,0);
        iVar7 = 0;
        ppPVar4 = param_2;
        if (0 < param_3) {
          do {
            if ((iVar7 != iVar10) && (param_2[iVar10] == *ppPVar4)) {
              *(unsigned char **)(param_2[iVar10] + 0xc) = local_4c;
              goto LAB_97bc7fe0;
            }
            iVar7 = iVar7 + 1;
            ppPVar4 = ppPVar4 + 1;
          } while (iVar7 < param_3);
        }
        pPVar3 = param_2[iVar10];
        if (pPVar3 != (unsigned char *)0x0) {
          __ZN12ParseOperandD1Ev(pPVar3);
          __ZdlPv(pPVar3);
        }
        pPVar3 = local_4c;
        if (local_4c != (unsigned char *)0x0) {
          __ZN12ParseOperandD1Ev(local_4c);
          __ZdlPv(pPVar3);
        }
LAB_97bc7fe0:
        param_2[iVar10] = local_50;
      }
      iVar10 = iVar10 + 1;
    } while (iVar10 < param_3);
  }
  ppPVar4 = param_2;
  iVar10 = param_3;
  iVar7 = 0;
  if (0 < param_3) {
    do {
      iVar10 = iVar7;
      if ((*ppPVar4 != (unsigned char *)0x0) && (*(int *)(*ppPVar4 + 8) != 0)) break;
      iVar7 = iVar10 + 1;
      ppPVar4 = ppPVar4 + 1;
      iVar10 = param_3;
    } while (iVar7 < param_3);
  }
  iVar10 = iVar10 + *(int *)((int)this + 0x9c);
  do {
    if (param_3 <= iVar10) {
      return;
    }
    if (*(int *)(param_2[iVar10] + 8) != 0) {
      pTVar5 = (unsigned char *)((int (*)())TPPStreamCompiler__newNodeFromOperand)(this,param_2[iVar10]);
      local_48[0] = (unsigned char *)((int (*)())TPPStreamCompiler__newTemporary)(this,pTVar5);
      bVar2 = false;
      ((int (*)())TPPStreamCompiler__assignOperands)(this,local_48,param_2 + iVar10,0);
      iVar9 = 0;
      ppPVar4 = param_2;
      iVar7 = param_3;
      if (param_3 < 1) {
LAB_97bc80d0:
        pPVar3 = param_2[iVar10];
        if (pPVar3 != (unsigned char *)0x0) {
          __ZN12ParseOperandD1Ev(pPVar3);
          __ZdlPv(pPVar3);
        }
      }
      else {
        do {
          if ((iVar9 != iVar10) && (param_2[iVar10] == *ppPVar4)) {
            bVar2 = true;
          }
          iVar9 = iVar9 + 1;
          iVar7 = iVar7 + -1;
          ppPVar4 = ppPVar4 + 1;
        } while (iVar7 != 0);
        if (!bVar2) goto LAB_97bc80d0;
      }
      param_2[iVar10] = local_48[0];
    }
    iVar10 = iVar10 + 1;
  } while( true );
}

/* __ZN17TPPStreamCompiler22IndirectAddressHandlerEPP12ParseOperandS2_ @ 0x97bc8114 (88 bytes) */
int __ZN17TPPStreamCompiler22IndirectAddressHandlerEPP12ParseOperandS2_(this, param_2, param_3)
  void *this;
  unsigned char ** param_2;
  unsigned char ** param_3;
{
  unsigned char * local_20;
  unsigned char * local_1c;
  
  local_20 = *param_2;
  local_1c = *param_3;
  ((int (*)())__ZN17TPPStreamCompiler22IndirectAddressHandlerEPP12ParseOperandi)(this,&local_20,2);
  *param_2 = local_20;
  *param_3 = local_1c;
  return;
}

/* __ZN17TPPStreamCompiler22IndirectAddressHandlerEPP12ParseOperandS2_S2_ @ 0x97bc816c (108 bytes) */
int __ZN17TPPStreamCompiler22IndirectAddressHandlerEPP12ParseOperandS2_S2_(this, param_2, param_3, param_4)
  void *this;
  unsigned char ** param_2;
  unsigned char ** param_3;
  unsigned char ** param_4;
{
  unsigned char * local_30;
  unsigned char * local_2c;
  unsigned char * local_28;
  
  local_30 = *param_2;
  local_2c = *param_3;
  local_28 = *param_4;
  ((int (*)())__ZN17TPPStreamCompiler22IndirectAddressHandlerEPP12ParseOperandi)(this,&local_30,3);
  *param_2 = local_30;
  *param_3 = local_2c;
  *param_4 = local_28;
  return;
}

/* __ZN17TPPStreamCompiler22IndirectAddressHandlerEPP12ParseOperandS2_S2_S2_ @ 0x97bc81d8 (128 bytes) */
int __ZN17TPPStreamCompiler22IndirectAddressHandlerEPP12ParseOperandS2_S2_S2_(this, param_2, param_3, param_4, param_5)
  void *this;
  unsigned char ** param_2;
  unsigned char ** param_3;
  unsigned char ** param_4;
  unsigned char ** param_5;
{
  unsigned char * local_30;
  unsigned char * local_2c;
  unsigned char * local_28;
  unsigned char * local_24;
  
  local_30 = *param_2;
  local_2c = *param_3;
  local_28 = *param_4;
  local_24 = *param_5;
  ((int (*)())__ZN17TPPStreamCompiler22IndirectAddressHandlerEPP12ParseOperandi)(this,&local_30,4);
  *param_2 = local_30;
  *param_3 = local_2c;
  *param_4 = local_28;
  *param_5 = local_24;
  return;
}

/* __ZN17TPPStreamCompiler22IndirectAddressHandlerEPP12ParseOperandS2_i @ 0x97bc8258 (188 bytes) */
int __ZN17TPPStreamCompiler22IndirectAddressHandlerEPP12ParseOperandS2_i(this, param_2, param_3, param_4)
  void *this;
  unsigned char ** param_2;
  unsigned char ** param_3;
  int param_4;
{
  unsigned char ** ppPVar1;
  int iVar2;
  unsigned char ** ppPVar3;
  unsigned char ** ppPVar4;
  unsigned char * apPStack_20 [2];
  
  iVar2 = -(param_4 * 4 + 0x22U & 0xfffffff0);
  *(unsigned char **)(&STACKARG(0xffffffa0) + iVar2) = ((unsigned int)__builtin_frame_address(0));
  ppPVar4 = (unsigned char **)((int)apPStack_20 + iVar2);
  *ppPVar4 = *param_2;
  ppPVar3 = param_3;
  iVar2 = param_4;
  ppPVar1 = ppPVar4;
  if (0 < param_4) {
    do {
      ppPVar1[1] = *ppPVar3;
      iVar2 = iVar2 + -1;
      ppPVar3 = ppPVar3 + 1;
      ppPVar1 = ppPVar1 + 1;
    } while (iVar2 != 0);
  }
  ((int (*)())__ZN17TPPStreamCompiler22IndirectAddressHandlerEPP12ParseOperandi)(this,ppPVar4,param_4 + 1);
  *param_2 = *ppPVar4;
  if (0 < param_4) {
    do {
      ppPVar4 = ppPVar4 + 1;
      *param_3 = *ppPVar4;
      param_3 = param_3 + 1;
      param_4 = param_4 + -1;
    } while (param_4 != 0);
  }
  return;
}

/* TPPStreamCompiler__getNewConstantSourceVar @ 0x97bc8314 (472 bytes) */
int TPPStreamCompiler__getNewConstantSourceVar(param_1, param_2, param_3, param_4, param_5)
  unsigned char * param_1;
  uint param_2;
  int param_3;
  int param_4;
  undefined4 param_5;
{
  undefined4 uVar1;
  undefined2 uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined1 *puVar6;
  undefined4 *puVar7;
  undefined4 uVar8;
  int iVar9;
  undefined4 local_60 [4];
  undefined4 local_50;
  uint local_4c;
  undefined4 local_40 [5];
  
  iVar9 = *(int *)(*(int *)(param_2 + 0x70) + 0x2c);
  uVar8 = *(undefined4 *)(*(int *)(param_2 + 0x70) + 0x10);
  local_60[0] = 0;
  local_60[1] = 0;
  local_60[2] = 0;
  local_60[3] = 0;
  local_4c = *(uint *)(*(int *)(param_2 + 0x68) + 0x24);
  *(uint *)(*(int *)(param_2 + 0x68) + 0x24) = local_4c + 1;
  local_50 = 0x110000;
  local_4c = local_4c & 0xffff;
  uVar5 = GetPPStreamTypeForGLType(param_5);
  uVar4 = local_4c;
  uVar3 = (uint)local_50 >> 0x10;
  uVar2 = *(undefined2 *)(iVar9 + 10);
  *(undefined4 *)param_1 = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  *(short *)(param_1 + 6) = (short)local_4c;
  *(uint *)param_1 = (param_4 + -1) * 0x1000 & 0x3000U | *(uint *)param_1 & 0xf409cfff | 0x10d8000;
  local_50 = CONCAT22((ushort)((uint)((param_4 + -1) * 0x1000000) >> 0x10) & 0x300 |
                      (ushort)(((uVar5 & 7) << 0x1a) >> 0x10) | (ushort)uVar3 & 0xff,uVar2);
  if (*(int *)(param_2 + 0xc4) == 3) {
    local_40[3] = 0;
    local_40[0] = 0;
    local_40[1] = 0;
    local_40[2] = 0;
    if (param_4 != 0) {
      puVar7 = local_40;
      iVar9 = 0;
      do {
        uVar1 = *(undefined4 *)(param_3 + iVar9 * 4);
        *puVar7 = 1;
        puVar7 = puVar7 + 1;
        local_60[iVar9] = uVar1;
        param_4 = param_4 + -1;
        iVar9 = iVar9 + 1;
      } while (param_4 != 0);
    }
    ConstantAllocationList__addConstant
              ((unsigned char *)(param_2 + 0x44),uVar4 & 0xffff,(bool *)local_40,
               (ushort)param_5);
  }
  else {
    iVar9 = 0;
    for (; param_4 != 0; param_4 = param_4 + -1) {
      local_60[iVar9] = *(undefined4 *)(param_3 + iVar9 * 4);
      iVar9 = iVar9 + 1;
    }
  }
  _PPStreamAddConstant(*(undefined4 *)(param_2 + 0x70),local_60);
  puVar6 = (undefined1 *)_calloc(0x1c,1);
  *puVar6 = 3;
  *(undefined4 *)(puVar6 + 0xc) = local_50;
  *(undefined4 *)(puVar6 + 0x14) = 0;
  *(uint *)(puVar6 + 0x10) = local_4c;
  _PPStreamChunkListAddChunk(uVar8,puVar6);
  return param_1;
}

/* TPPStreamCompiler__getConstantAsSourceVar @ 0x97bc84ec (1296 bytes) */
int TPPStreamCompiler__getConstantAsSourceVar(param_1, param_2, param_3, param_4, param_5)
  unsigned char * param_1;
  uint param_2;
  float *param_3;
  uint param_4;
  uint param_5;
{
  bool bVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  int *piVar6;
  int iVar7;
  uint local_80;
  undefined4 local_7c;
  int local_70 [4];
  ushort local_60 [8];
  int local_50 [5];
  
  if (*(int *)(param_2 + 0xc4) != 1) {
    bVar1 = false;
    local_70[1] = DAT_97c39254;
    local_70[0] = DAT_97c39250;
    local_70[2] = DAT_97c39258;
    local_70[3] = DAT_97c3925c;
    piVar6 = *(int **)(*(int *)(param_2 + 0x70) + 0x10);
    uVar5 = *(undefined4 *)(*(int *)(param_2 + 0x70) + 0x2c);
    iVar7 = *piVar6;
    *(undefined4 *)param_1 = 0;
    *(undefined4 *)(param_1 + 4) = 0;
    *(uint *)param_1 = (param_4 - 1) * 0x1000 & 0x3000 | *(uint *)param_1 & 0xfc09cfff | 0x10d8000;
    if (iVar7 != 0) {
      do {
        local_80 = *(uint *)(iVar7 + 0xc);
        local_7c = *(uint *)(iVar7 + 0x10);
        if ((local_80 & 0x1f0000) == 0x110000) {
          iVar4 = _PPStreamChunkListChunkAtIndex(uVar5,local_80 & 0xffff);
          if (*(int *)(param_2 + 0xc4) == 3) {
            ConstantAllocationList__getConstantUsage
                      ((unsigned char *)(param_2 + 0x44),local_7c & 0xffff,(bool *)local_70
                       ,local_60);
          }
          if (local_60[0] == param_5) {
            if (param_4 == 2) {
LAB_97bc86b4:
              if ((local_70[1] != 0) && (param_3[1] == *(float *)(iVar4 + 0x10))) {
LAB_97bc86d0:
                if ((local_70[0] != 0) && (*param_3 == *(float *)(iVar4 + 0xc))) goto LAB_97bc86ec;
              }
            }
            else {
              if (2 < param_4) {
                if (param_4 != 3) {
                  if (param_4 != 4) goto LAB_97bc86ec;
                  if ((local_70[3] == 0) || (param_3[3] != *(float *)(iVar4 + 0x18)))
                  goto LAB_97bc86f8;
                }
                if ((local_70[2] == 0) || (param_3[2] != *(float *)(iVar4 + 0x14)))
                goto LAB_97bc86f8;
                goto LAB_97bc86b4;
              }
              if (param_4 == 1) goto LAB_97bc86d0;
LAB_97bc86ec:
              bVar1 = true;
              *(undefined2 *)(param_1 + 6) = (*(unsigned short *)((unsigned char *)&(local_7c) + 2));
            }
          }
        }
LAB_97bc86f8:
        iVar7 = *(int *)(iVar7 + 8);
        if (iVar7 == 0) {
          bVar1 = !bVar1;
          goto LAB_97bc8720;
        }
      } while (!bVar1);
      goto LAB_97bc89bc;
    }
    bVar1 = true;
LAB_97bc8720:
    if (!bVar1) goto LAB_97bc89bc;
    if (*(int *)(param_2 + 0xc4) != 2) {
      iVar7 = *piVar6;
      if (iVar7 != 0) {
        do {
          local_50[0] = 0;
          local_50[1] = 0;
          local_50[2] = 0;
          local_50[3] = 0;
          local_80 = *(uint *)(iVar7 + 0xc);
          local_7c = *(uint *)(iVar7 + 0x10);
          if ((local_80 & 0x1f0000) == 0x110000) {
            iVar4 = _PPStreamChunkListChunkAtIndex(uVar5,local_80 & 0xffff);
            if (*(int *)(param_2 + 0xc4) == 3) {
              ConstantAllocationList__getConstantUsage
                        ((unsigned char *)(param_2 + 0x44),local_7c & 0xffff,
                         (bool *)local_70,local_60);
            }
            if (local_60[0] == param_5) {
              bVar2 = true;
              if (param_4 == 2) {
LAB_97bc8838:
                if ((local_70[1] == 1) && (param_3[1] == *(float *)(iVar4 + 0x10))) {
                  local_50[1] = local_70[1];
                }
                else if (local_70[1] != 0) {
                  bVar2 = false;
                }
LAB_97bc8868:
                if ((local_70[0] == 1) && (*param_3 == *(float *)(iVar4 + 0xc))) {
                  local_50[0] = local_70[0];
                }
                else if (local_70[0] != 0) {
                  bVar2 = false;
                }
                if (!bVar2) goto LAB_97bc897c;
              }
              else {
                if (2 < param_4) {
                  if (param_4 != 3) {
                    if (param_4 != 4) goto LAB_97bc88a0;
                    if ((local_70[3] == 1) && (param_3[3] == *(float *)(iVar4 + 0x18))) {
                      local_50[3] = 1;
                    }
                    else if (local_70[3] != 0) {
                      bVar2 = false;
                    }
                  }
                  if ((local_70[2] == 1) && (param_3[2] == *(float *)(iVar4 + 0x14))) {
                    local_50[2] = local_70[2];
                  }
                  else if (local_70[2] != 0) {
                    bVar2 = false;
                  }
                  goto LAB_97bc8838;
                }
                if (param_4 == 1) goto LAB_97bc8868;
              }
LAB_97bc88a0:
              uVar3 = 0;
              if (param_4 != 0) {
                do {
                  if (local_50[uVar3] == 0) {
                    if (local_70[uVar3] != 0) {
                      bVar2 = false;
                      break;
                    }
                    ((float *)(iVar4 + 0xc))[uVar3] = param_3[uVar3];
                    local_50[uVar3] = 1;
                    local_70[uVar3] = 1;
                  }
                  uVar3 = uVar3 + 1;
                } while (uVar3 < param_4);
              }
              if (param_4 != 0) {
                piVar6 = local_50;
                uVar3 = param_4;
                do {
                  iVar4 = *piVar6;
                  piVar6 = piVar6 + 1;
                  if (iVar4 == 0) {
                    bVar2 = false;
                  }
                  uVar3 = uVar3 - 1;
                } while (uVar3 != 0);
              }
              if (bVar2) {
                *(undefined2 *)(param_1 + 6) = (*(unsigned short *)((unsigned char *)&(local_7c) + 2));
                *(uint *)(iVar7 + 0xc) =
                     (local_70[0] + local_70[1] + local_70[2] + local_70[3] + -1) * 0x1000000 &
                     0x3000000U | *(uint *)(iVar7 + 0xc) & 0xfcffffff;
                bVar1 = false;
                ConstantAllocationList__updateConstant
                          ((unsigned char *)(param_2 + 0x44),local_7c & 0xffff,
                           (bool *)local_70,param_5);
              }
            }
          }
LAB_97bc897c:
          iVar7 = *(int *)(iVar7 + 8);
          if (iVar7 == 0) goto LAB_97bc8990;
        } while (bVar1);
        goto LAB_97bc89bc;
      }
LAB_97bc8990:
      if (!bVar1) goto LAB_97bc89bc;
    }
  }
  ((int (*)())TPPStreamCompiler__getNewConstantSourceVar)((unsigned char *)&local_80,param_2,param_3,param_4,param_5);
  *(uint *)(param_1 + 4) = local_7c;
  *(uint *)param_1 = local_80;
LAB_97bc89bc:
  if (param_4 == 1) {
    uVar3 = *(uint *)param_1 >> 0x15 & 3;
    *(uint *)param_1 = uVar3 << 0xf | uVar3 << 0x11 | uVar3 << 0x13 | *(uint *)param_1 & 0xffe07fff;
  }
  return param_1;
}

/* TPPStreamCompiler__generateAddressLoad @ 0x97bc89fc (256 bytes) */
int TPPStreamCompiler__generateAddressLoad(this, param_2)
  unsigned char * this;
  unsigned char * param_2;
{
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  void *this_00;
  undefined4 local_70;
  undefined4 local_6c;
  uint local_68;
  uint local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_30;
  undefined4 local_2c;
  
  this_00 = *(void **)(param_2 + 8);
  if (this_00 != (void *)0x0) {
    local_6c = 0;
    local_40 = *(undefined4 *)(this + 0x90);
    local_48 = 0;
    local_44 = 0;
    local_68 = 0;
    local_64 = 0;
    local_60 = 0;
    local_5c = 0;
    local_58 = 0;
    local_54 = 0;
    local_50 = 0;
    local_4c = 0;
    local_70 = 0x21200000;
    local_3c = 0;
    ((int (*)())TPPStreamCompiler__getOperandAsSourceVar)((unsigned char *)&local_30,this,this_00,in_r6,in_r7,in_r8,0,0);
    local_68 = local_68 & 0xfff1ffff | 0x82000;
    local_60 = local_30;
    local_5c = local_2c;
    local_64 = local_64 & 0xffff0000;
    _PPStreamAddOperation(*(undefined4 *)(this + 0x70),&local_70,0,0);
    __ZN12ParseOperandD1Ev(this_00);
    __ZdlPv(this_00);
    *(undefined4 *)(param_2 + 8) = 0;
  }
  return this_00 != (void *)0x0;
}

/* TPPStreamCompiler__getOperandAsDestVar @ 0x97bc8afc (76 bytes) */
int TPPStreamCompiler__getOperandAsDestVar(param_1, param_2, param_3, param_4, param_5, param_6)
  unsigned char * param_1;
  unsigned char * param_2;
  unsigned char * param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
{
  undefined4 uVar1;
  
  uVar1 = ((int (*)())TPPStreamCompiler__generateAddressLoad)(param_2,param_3);
  ParseOperand__GetAsDestVar(param_1,param_3,uVar1);
  return param_1;
}

/* TPPStreamCompiler__getOperandAsSourceVar @ 0x97bc8b48 (420 bytes) */
int TPPStreamCompiler__getOperandAsSourceVar(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  unsigned char * param_1;
  unsigned char * param_2;
  unsigned char * param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  bool bVar1;
  ushort uVar2;
  undefined4 *puVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  int iVar7;
  undefined4 local_50 [4];
  undefined4 local_40;
  undefined4 local_3c;
  
  if (*(int *)param_3 == 0) {
    if (*(int *)(param_3 + 8) != 0) {
      error(param_2,(char *)0x1,(char *)0x0,_compileErrorString,param_5,param_6,param_7,param_8);
    }
    uVar5 = 4;
    iVar7 = 4;
    puVar3 = local_50;
    do {
      *puVar3 = 0;
      puVar3 = puVar3 + 1;
      iVar7 = iVar7 + -1;
    } while (iVar7 != 0);
    iVar7 = 0;
    for (uVar6 = 0; uVar4 = ParseOperand__GetLogicalSize(param_3), uVar6 < uVar4; uVar6 = uVar6 + 1)
    {
      if (uVar6 < 4) {
        if (*(int *)param_3 == 0) {
          uVar2 = *(ushort *)(param_3 + 0x18);
        }
        else {
          uVar2 = *(ushort *)(*(int *)param_3 + 0x2c);
        }
        if (uVar2 == 0x1406) {
          *(undefined4 *)(iVar7 + (int)local_50) = *(undefined4 *)(iVar7 + *(int *)(param_3 + 4));
        }
        else {
          if (uVar2 < 0x1407) {
            bVar1 = uVar2 == 0x1404;
          }
          else {
            bVar1 = uVar2 == 0x8b56;
          }
          if (bVar1) {
            *(undefined4 *)(iVar7 + (int)local_50) = *(undefined4 *)(iVar7 + *(int *)(param_3 + 4));
          }
        }
      }
      else {
        error(param_2,(char *)0x1,(char *)0x0,DAT_a7b7bd14,param_5,param_6,uVar5,param_8);
      }
      iVar7 = iVar7 + 4;
    }
    uVar5 = ParseOperand__GetLogicalSize(param_3);
    if (*(int *)param_3 == 0) {
      uVar2 = *(ushort *)(param_3 + 0x18);
    }
    else {
      uVar2 = *(ushort *)(*(int *)param_3 + 0x2c);
    }
    ((int (*)())TPPStreamCompiler__getConstantAsSourceVar)((unsigned char *)&local_40,(uint)param_2,local_50,uVar5,(uint)uVar2);
  }
  else {
    uVar5 = ((int (*)())TPPStreamCompiler__generateAddressLoad)(param_2,param_3);
    ParseOperand__GetAsSourceVar(local_50,param_3,uVar5);
    local_40 = local_50[0];
    local_3c = local_50[1];
  }
  *(undefined4 *)param_1 = local_40;
  *(undefined4 *)(param_1 + 4) = local_3c;
  return param_1;
}

/* TPPStreamCompiler__removeOrphanedCompilerTemp @ 0x97bc8cec (544 bytes) */
int TPPStreamCompiler__removeOrphanedCompilerTemp(this, param_2, param_3)
  unsigned char * this;
  unsigned char * param_2;
  unsigned char * param_3;
{
  byte bVar1;
  ushort uVar2;
  bool bVar3;
  ushort uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  byte *pbVar8;
  undefined4 *this_00;
  byte *pbVar9;
  uint uVar10;
  
  bVar3 = false;
  iVar6 = **(int **)(*(int *)(this + 0x70) + 0x20);
  if (iVar6 != 0) {
    uVar5 = *(uint *)(param_2 + 0x10) >> 0x17 & 7;
    while( true ) {
      uVar10 = *(uint *)(iVar6 + 0xc) >> 0x1d;
      if (uVar10 != 0) {
        iVar7 = iVar6 + 0x10;
        do {
          if (((*(uint *)(iVar7 + 0xc) >> 0x17 & 7) == uVar5) &&
             (*(short *)(iVar7 + 0x12) == *(short *)(param_2 + 0x16))) {
            bVar3 = true;
          }
          iVar7 = iVar7 + 8;
          uVar10 = uVar10 - 1;
        } while (uVar10 != 0);
      }
      if (((*(uint *)(iVar6 + 0x14) >> 0x11 & 7) == uVar5) &&
         (*(short *)(iVar6 + 0x1a) == *(short *)(param_2 + 0x16))) {
        bVar3 = true;
      }
      iVar6 = *(int *)(iVar6 + 8);
      if (iVar6 == 0) break;
      if (bVar3) {
        return;
      }
    }
  }
  if (bVar3) {
    return;
  }
  iVar6 = ParseSymbolTable__RemoveEndSymbol
                    (*(unsigned char **)(this + 0x68),*(unsigned char **)param_3);
  if (iVar6 == 0) {
    return;
  }
  this_00 = *(undefined4 **)param_3;
  uVar5 = 3;
  uVar2 = *(ushort *)(this_00 + 0xb);
  pbVar8 = (byte *)*this_00;
  if (uVar2 != 0x8b5b) {
    if (uVar2 < 0x8b5c) {
      uVar5 = 2;
      uVar4 = 0x8b5a;
    }
    else {
      uVar5 = 4;
      uVar4 = 0x8b5c;
    }
    if (uVar2 != uVar4) {
      uVar5 = 1;
    }
  }
  if (this_00[0xf] != 0) {
    TemporaryAllocator__releaseTemporary
              (*(unsigned char **)(this + 0x60),(uint)*(ushort *)(this_00 + 0xb),this_00[10]);
    this_00 = *(undefined4 **)param_3;
  }
  if (this_00 != (undefined4 *)0x0) {
    __ZN11ParseSymbolD1Ev(this_00);
    __ZdlPv(this_00);
  }
  *(undefined4 *)param_3 = 0;
  bVar1 = *pbVar8;
  if (bVar1 == 2) {
    iVar6 = *(int *)(*(int *)(this + 0x70) + 0x18);
    goto LAB_97bc8ebc;
  }
  if (bVar1 < 3) {
    if (bVar1 == 0) {
      iVar6 = *(int *)(*(int *)(this + 0x70) + 4);
      goto LAB_97bc8ebc;
    }
  }
  else {
    if (bVar1 == 3) {
      iVar6 = *(int *)(*(int *)(this + 0x70) + 0x10);
      goto LAB_97bc8ebc;
    }
    if (bVar1 == 4) {
      iVar6 = *(int *)(*(int *)(this + 0x70) + 0x1c);
      goto LAB_97bc8ebc;
    }
  }
  iVar6 = 0;
LAB_97bc8ebc:
  if ((iVar6 != 0) && (uVar10 = 0, uVar5 != 0)) {
    do {
      pbVar9 = *(byte **)(pbVar8 + 8);
      if (pbVar8 == (byte *)0x0) {
        return;
      }
      uVar10 = uVar10 + 1;
      _PPStreamChunkListRemoveChunk(iVar6,pbVar8);
      pbVar8 = pbVar9;
    } while (uVar10 < uVar5);
  }
  return;
}

/* TPPStreamCompiler__copyPropagateCompilerTemp @ 0x97bc8f0c (1476 bytes) */
int TPPStreamCompiler__copyPropagateCompilerTemp(this, param_2, param_3)
  unsigned char * this;
  unsigned char * param_2;
  unsigned char * param_3;
{
  bool bVar1;
  bool bVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  bool bVar9;
  bool bVar10;
  bool bVar11;
  int iVar12;
  uint uVar13;
  int iVar14;
  uint uVar15;
  int iVar16;
  unsigned char * p_Var17;
  undefined4 uVar18;
  uint in_r7;
  uint uVar19;
  uint *puVar20;
  undefined4 uVar21;
  uint uVar22;
  uint local_b0 [3];
  uint *local_a4;
  uint local_a0 [3];
  uint *local_94;
  uint local_90 [4];
  uint local_80 [4];
  uint local_70 [4];
  uint local_60 [4];
  uint local_50 [7];
  
  iVar16 = *(int *)param_3;
  uVar21 = 0;
  bVar10 = false;
  bVar9 = false;
  if ((iVar16 != 0) && ((*(int *)(iVar16 + 0x3c) != 0 || (*(int *)(iVar16 + 0x40) != 0)))) {
    uVar13 = *(uint *)(param_2 + 8);
    uVar19 = *(uint *)(this + 0x70);
    puVar20 = (uint *)(uVar13 >> 0x10 & 1);
    local_a0[0] = uVar13 >> 0xd & 1;
    local_a0[1] = uVar13 >> 0xe & 1;
    local_a0[2] = uVar13 >> 0xf & 1;
    local_b0[0] = local_a0[0];
    uVar13 = local_a0[0] | local_a0[1] | local_a0[2] | (uint)puVar20;
    local_b0[1] = local_a0[1];
    local_b0[2] = local_a0[2];
    local_a4 = puVar20;
    iVar16 = 0;
    for (iVar12 = **(int **)(uVar19 + 0x20); iVar12 != 0; iVar12 = *(int *)(iVar12 + 8)) {
      iVar16 = iVar12;
    }
    iVar12 = 0;
    for (iVar14 = **(int **)(uVar19 + 0x24); iVar14 != 0; iVar14 = *(int *)(iVar14 + 8)) {
      iVar12 = iVar14;
    }
    bVar1 = *(int *)(param_2 + 0xc) < 0;
    uVar22 = *(uint *)param_2 >> 0x1d;
    if (uVar22 != 0) {
      p_Var17 = param_2 + 0x10;
      do {
        iVar14 = *(int *)p_Var17;
        p_Var17 = p_Var17 + 8;
        if (iVar14 < 0) {
          bVar1 = true;
        }
        uVar22 = uVar22 - 1;
      } while (uVar22 != 0);
    }
    bVar2 = uVar13 == 0;
    local_94 = puVar20;
    if ((!bVar2) && (iVar16 != 0)) {
      bVar11 = bVar2;
      do {
        if (iVar12 == 0) {
          uVar22 = *(uint *)(iVar16 + 0xc);
LAB_97bc9078:
          if (((uVar22 & 0x3fc0000) == 0x1300000) ||
             ((bVar1 && ((uVar22 & 0x3fc0000) == 0x1200000)))) goto LAB_97bc909c;
          uVar22 = uVar22 >> 0x1d;
          uVar15 = 0;
          if (uVar22 != 0) {
            iVar14 = iVar16 + 0x10;
            puVar20 = (uint *)(*(uint *)(param_2 + 0x10) >> 0x17 & 7);
            do {
              uVar19 = uVar22;
              if (((uint *)(*(uint *)(iVar14 + 0xc) >> 0x17 & 7) == puVar20) &&
                 (*(short *)(iVar14 + 0x12) == *(short *)(param_2 + 0x16))) {
                bVar9 = true;
                break;
              }
              uVar15 = uVar15 + 1;
              iVar14 = iVar14 + 8;
            } while (uVar15 < uVar22);
          }
        }
        else {
          uVar22 = *(uint *)(iVar16 + 0xc);
          if (*(uint *)(iVar12 + 0xc) <= (uVar22 & 0x3ffff)) goto LAB_97bc9078;
LAB_97bc909c:
          uVar13 = 0;
          bVar11 = true;
        }
        bVar2 = true;
        if (bVar11) break;
        puVar20 = *(uint **)(param_2 + 0x10);
        if ((((((uint)puVar20 & 0x8000000) == 0) &&
             ((*(uint *)(iVar16 + 0x14) >> 0x11 & 7) == ((uint)puVar20 >> 0x17 & 7))) &&
            (*(short *)(iVar16 + 0x1a) == *(short *)(param_2 + 0x16))) &&
           ((*(uint *)(iVar16 + 0x14) >> 0xc & 1) == ((uint)puVar20 >> 0xe & 1))) {
          bVar2 = false;
          local_90[0] = DAT_97c39260;
          local_90[1] = DAT_97c39264;
          local_90[2] = DAT_97c39268;
          local_90[3] = DAT_97c3926c;
          local_a0[0] = 0;
          local_a0[1] = 0;
          local_a0[2] = 0;
          local_94 = (uint *)0x0;
          uVar22 = *(uint *)(iVar16 + 0xc) & 0x3fc0000;
          if (((((((uVar22 == 0xb80000) || (uVar22 == 0x1080000)) ||
                 ((uVar22 == 0x10c0000 || ((uVar22 == 0x1100000 || (uVar22 == 0x1140000)))))) ||
                (uVar22 == 0x1180000)) || ((uVar22 == 0x11c0000 || (uVar22 == 0x2c0000)))) &&
              ((*(uint *)(iVar16 + 0x10) >> 0x1a & 3) == (*(uint *)(param_2 + 4) >> 0x1a & 3))) ||
             ((((uVar22 = *(uint *)(iVar16 + 0xc) & 0x3fc0000, uVar22 == 0x9c0000 ||
                (uVar22 == 0xac0000)) || (uVar22 == 0x480000)) ||
              (((uVar22 == 0x200000 || (uVar22 == 0x240000)) ||
               ((*(uint *)(iVar16 + 0x10) >> 0x1a & 3) <= (*(uint *)(param_2 + 4) >> 0x1a & 3)))))))
          {
            uVar22 = *(uint *)(param_2 + 8);
            in_r7 = (uint)puVar20 >> 0x15 & 3;
            local_80[0] = *(uint *)(iVar16 + 0x14) >> 8 & 3;
            local_80[1] = *(uint *)(iVar16 + 0x14) >> 6 & 3;
            local_80[2] = *(uint *)(iVar16 + 0x14) >> 4 & 3;
            local_80[3] = *(uint *)(iVar16 + 0x14) >> 2 & 3;
            local_70[0] = *(uint *)(iVar16 + 0x14) >> 0xd & 1;
            local_70[1] = *(uint *)(iVar16 + 0x14) >> 0xe & 1;
            local_70[2] = *(uint *)(iVar16 + 0x14) >> 0xf & 1;
            local_60[2] = (uint)puVar20 >> 0x11 & 3;
            local_50[0] = uVar22 >> 8 & 3;
            local_70[3] = *(uint *)(iVar16 + 0x14) >> 0x10 & 1;
            iVar14 = 4;
            local_60[0] = in_r7;
            local_60[1] = (uint)puVar20 >> 0x13 & 3;
            uVar19 = 0;
            local_60[3] = (uint)puVar20 >> 0xf & 3;
            local_50[1] = uVar22 >> 6 & 3;
            local_50[2] = uVar22 >> 4 & 3;
            local_50[3] = uVar22 >> 2 & 3;
            puVar20 = local_b0;
            do {
              if ((*puVar20 != 0) && (uVar15 = local_60[puVar20[0x18]], local_70[uVar15] != 0)) {
                *puVar20 = 0;
                bVar2 = true;
                uVar15 = local_80[uVar15];
                puVar20[4] = 1;
                uVar13 = (uint)(((local_b0[0] != 0 || local_b0[1] != 0) || local_b0[2] != 0) ||
                               local_a4 != (uint *)0x0);
                puVar20[8] = uVar15;
              }
              puVar20 = puVar20 + 1;
              iVar14 = iVar14 + -1;
            } while (iVar14 != 0);
            if (bVar2) {
              uVar18 = *(undefined4 *)(param_2 + 0xc);
              *(uint *)(iVar16 + 0x14) = uVar22;
              bVar10 = true;
              *(undefined4 *)(iVar16 + 0x18) = uVar18;
              uVar15 = (local_a0[0] & 1) << 0xd;
              *(uint *)(iVar16 + 0x14) = uVar15 | uVar22 & 0xffffdfff;
              uVar3 = (local_a0[1] & 1) << 0xe;
              *(uint *)(iVar16 + 0x14) = uVar3 | uVar15 | uVar22 & 0xffff9fff;
              uVar4 = (local_a0[2] & 1) << 0xf;
              *(uint *)(iVar16 + 0x14) = uVar4 | uVar3 | uVar15 | uVar22 & 0xffff1fff;
              uVar5 = ((uint)local_94 & 1) << 0x10;
              *(uint *)(iVar16 + 0x14) = uVar5 | uVar4 | uVar3 | uVar15 | uVar22 & 0xfffe1fff;
              uVar6 = (local_90[0] & 3) << 8;
              *(uint *)(iVar16 + 0x14) =
                   uVar6 | uVar5 | uVar4 | uVar3 | uVar15 | uVar22 & 0xfffe1cff;
              uVar7 = (local_90[1] & 3) << 6;
              *(uint *)(iVar16 + 0x14) =
                   uVar7 | uVar6 | uVar5 | uVar4 | uVar3 | uVar15 | uVar22 & 0xfffe1c3f;
              uVar8 = (local_90[2] & 3) << 4;
              *(uint *)(iVar16 + 0x14) =
                   uVar8 | uVar7 | uVar6 | uVar5 | uVar4 | uVar3 | uVar15 | uVar22 & 0xfffe1c0f;
              *(uint *)(iVar16 + 0x14) =
                   (local_90[3] & 3) << 2 |
                   uVar8 | uVar7 | uVar6 | uVar5 | uVar4 | uVar3 | uVar15 | uVar22 & 0xfffe1c03;
            }
          }
          else {
            uVar13 = 0;
          }
        }
        iVar16 = *(int *)(iVar16 + 4);
        bVar2 = uVar13 == 0;
        if (bVar9) {
          uVar13 = 0;
        }
        bVar2 = bVar9 || bVar2;
        if ((bVar2) || (bVar11 = false, iVar16 == 0)) break;
      } while( true );
    }
    uVar13 = local_b0[0] | local_b0[1] | local_b0[2] | (uint)local_a4;
    if ((uVar13 != 0) && (bVar10)) {
      TPPStreamCompiler__warning(this,(char *)0x0,(char *)0x0,DAT_a7b7bd40,in_r7,uVar19,uVar13,puVar20);
    }
    if (bVar2) {
      if (bVar10) {
        uVar21 = 1;
        ((int (*)())TPPStreamCompiler__removeOrphanedCompilerTemp)(this,param_2,param_3);
      }
    }
    else if (bVar10) {
      *(uint *)(param_2 + 8) =
           ((uint)local_a4 & 1) << 0x10 |
           (local_b0[2] & 1) << 0xf |
           (local_b0[1] & 1) << 0xe | (local_b0[0] & 1) << 0xd | *(uint *)(param_2 + 8) & 0xfffe1fff
      ;
    }
  }
  return uVar21;
}

/* TPPStreamCompiler__parseIntermediateTree @ 0x97bc94d0 (480 bytes) */
int TPPStreamCompiler__parseIntermediateTree(this, param_2)
  unsigned char * this;
  unsigned char * param_2;
{
  int iVar1;
  undefined4 in_r5;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  void *pvVar2;
  unsigned char * pQVar3;
  bool bVar4;
  undefined4 local_30 [7];
  
  bVar4 = false;
  if (param_2 != (unsigned char *)0x0) {
    pvVar2 = *(void **)(this + 0x60);
    *(undefined4 *)(this + 0xac) = 0;
    *(undefined4 *)(this + 0x8c) = 0;
    *(undefined4 *)(this + 0x94) = 0;
    *(undefined4 *)(this + 0xa0) = 0;
    *(undefined4 *)(this + 0xa8) = 0;
    if (pvVar2 != (void *)0x0) {
      __ZN18TemporaryAllocatorD1Ev(pvVar2);
      __ZdlPv(pvVar2);
    }
    pvVar2 = operator_new(200);
    __ZN18TemporaryAllocatorC1Ev(pvVar2);
    *(void **)(this + 0x60) = pvVar2;
    *(void **)PTR_temporaryAllocator_a7b7c0fc = pvVar2;
    pvVar2 = *(void **)(this + 100);
    if (pvVar2 != (void *)0x0) {
      __ZN20AddressTempAllocatorD1Ev(pvVar2);
      __ZdlPv(pvVar2);
    }
    pvVar2 = operator_new(8);
    __ZN20AddressTempAllocatorC1Ev(pvVar2);
    *(void **)(this + 100) = pvVar2;
    *(void **)PTR_addressTempAllocator_a7b7c0f8 = pvVar2;
    pQVar3 = (unsigned char *)(this + 0x4c);
    while( true ) {
      iVar1 = size(pQVar3);
      if (iVar1 == 0) break;
      ((int (*)())fetch)(pQVar3);
    }
    newQueue(pQVar3);
    *(undefined4 *)(this + 0x98) = 0;
    ConstantAllocationList__clear((unsigned char *)(this + 0x44));
    while (iVar1 = ((int (*)())ParseFunctionStack__empty)((unsigned char *)(this + 0x58)), iVar1 == 0) {
      ((int (*)())ParseFunctionStack__pop)((unsigned char *)(this + 0x58));
    }
    if (*(int *)(this + 8) == 0) {
      pvVar2 = (void *)((int (*)())TPPStreamCompiler__getPosition)(this);
      if (pvVar2 != (void *)0x0) {
        __ZN12ParseOperandD1Ev(pvVar2);
        __ZdlPv(pvVar2);
      }
    }
    *(undefined4 *)(*(int *)(this + 0x68) + 0x50) = 1;
    (**(code **)(*(int *)param_2 + 0x10))(param_2,this,in_r5,in_r6,in_r7,in_r8,*(int *)param_2);
    *(undefined4 *)(*(int *)(this + 0x68) + 0x50) = 0;
    if (*(int *)(this + 0xa8) == 1) {
      local_30[0] = 0;
      _PPStreamAddAddressUsage(*(undefined4 *)(this + 0x70),local_30);
    }
    *(undefined4 *)(this + 0x94) = 0;
    *(undefined4 *)(this + 0x8c) = 0;
    pvVar2 = (void *)(**(code **)(*(int *)param_2 + 0xc))(param_2,this);
    if (pvVar2 != (void *)0x0) {
      __ZN12ParseOperandD1Ev(pvVar2);
      __ZdlPv(pvVar2);
    }
    ParseSymbolTable__ClearCompilerTempData(*(unsigned char **)(this + 0x68));
    bVar4 = *(int *)(this + 0xa0) != 1;
  }
  return bVar4;
}

/* __ZN17TPPStreamCompilerC2E11EShLanguagei @ 0x97bc96b0 (4 bytes) */
int __ZN17TPPStreamCompilerC2E11EShLanguagei(this, param_2, param_3)
  void *this;
  undefined4 param_2;
  undefined4 param_3;
{
  int iVar1;
  undefined *puVar2;
  int *piVar3;
  char in_RESERVE;
  byte in_cr0;
  
  *(undefined4 *)((int)this + 8) = param_2;
  *(undefined ***)this = &PTR___ZN9TCompilerD1Ev_a7b7d850;
  *(int *)((int)this + 4) = (int)this + 0xb0;
  *(undefined4 *)((int)this + 0xc) = 0;
  __ZN14TPoolAllocatorC1Ebii((void *)((int)this + 0x10),false,0x2000,0x10);
  *(int *)this = DAT_a7b7bd98 + 8;
  __ZN22ConstantAllocationListC1Ev((void *)((int)this + 0x44));
  ((int (*)())__ZN18ParseFunctionStackC1Ev)((void *)((int)this + 0x58));
  ((int (*)())__ZN19ParseWhileLoopStackC1Ev)((void *)((int)this + 0x5c));
  puVar2 = PTR__S_empty_rep_storage_a7b7c0f0;
  piVar3 = (int *)(PTR__S_empty_rep_storage_a7b7c0f0 + 8);
  do {
    if (in_RESERVE != '\0') {
      iVar1 = storeWordConditionalIndexed(*piVar3 + 1,0,piVar3);
      *piVar3 = iVar1;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  *(undefined4 *)((int)this + 0xb4) = 4;
  *(undefined **)((int)this + 0xb0) = puVar2 + 0xc;
  do {
    if (in_RESERVE != '\0') {
      iVar1 = storeWordConditionalIndexed(*piVar3 + 1,0,piVar3);
      *piVar3 = iVar1;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  *(undefined4 *)((int)this + 0xbc) = 4;
  *(undefined **)((int)this + 0xb8) = puVar2 + 0xc;
  *(undefined4 *)((int)this + 0xc0) = param_3;
  newQueue((unsigned char *)((int)this + 0x4c));
  *(undefined4 *)((int)this + 0x88) = 0;
  *(undefined4 *)((int)this + 0x9c) = 1;
  *(undefined4 *)((int)this + 0x68) = 0;
  *(undefined4 *)((int)this + 0x6c) = 0;
  *(undefined4 *)((int)this + 0x74) = 0;
  *(undefined4 *)((int)this + 0x70) = 0;
  *(undefined4 *)((int)this + 0x7c) = 0;
  *(undefined4 *)((int)this + 0x80) = 0;
  *(undefined4 *)((int)this + 0x78) = 0;
  *(undefined4 *)((int)this + 0x84) = 0;
  *(undefined4 *)((int)this + 0x60) = 0;
  *(undefined4 *)((int)this + 100) = 0;
  return;
}

/* __ZN17TPPStreamCompilerC1E11EShLanguagei @ 0x97bc96b4 (4 bytes) */
int __ZN17TPPStreamCompilerC1E11EShLanguagei(this, param_2, param_3)
  void *this;
  undefined4 param_2;
  undefined4 param_3;
{
  int iVar1;
  undefined *puVar2;
  int *piVar3;
  char in_RESERVE;
  byte in_cr0;
  
  *(undefined4 *)((int)this + 8) = param_2;
  *(undefined ***)this = &PTR___ZN9TCompilerD1Ev_a7b7d850;
  *(int *)((int)this + 4) = (int)this + 0xb0;
  *(undefined4 *)((int)this + 0xc) = 0;
  __ZN14TPoolAllocatorC1Ebii((void *)((int)this + 0x10),false,0x2000,0x10);
  *(int *)this = DAT_a7b7bd98 + 8;
  __ZN22ConstantAllocationListC1Ev((void *)((int)this + 0x44));
  ((int (*)())__ZN18ParseFunctionStackC1Ev)((void *)((int)this + 0x58));
  ((int (*)())__ZN19ParseWhileLoopStackC1Ev)((void *)((int)this + 0x5c));
  puVar2 = PTR__S_empty_rep_storage_a7b7c0f0;
  piVar3 = (int *)(PTR__S_empty_rep_storage_a7b7c0f0 + 8);
  do {
    if (in_RESERVE != '\0') {
      iVar1 = storeWordConditionalIndexed(*piVar3 + 1,0,piVar3);
      *piVar3 = iVar1;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  *(undefined4 *)((int)this + 0xb4) = 4;
  *(undefined **)((int)this + 0xb0) = puVar2 + 0xc;
  do {
    if (in_RESERVE != '\0') {
      iVar1 = storeWordConditionalIndexed(*piVar3 + 1,0,piVar3);
      *piVar3 = iVar1;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  *(undefined4 *)((int)this + 0xbc) = 4;
  *(undefined **)((int)this + 0xb8) = puVar2 + 0xc;
  *(undefined4 *)((int)this + 0xc0) = param_3;
  newQueue((unsigned char *)((int)this + 0x4c));
  *(undefined4 *)((int)this + 0x88) = 0;
  *(undefined4 *)((int)this + 0x9c) = 1;
  *(undefined4 *)((int)this + 0x68) = 0;
  *(undefined4 *)((int)this + 0x6c) = 0;
  *(undefined4 *)((int)this + 0x74) = 0;
  *(undefined4 *)((int)this + 0x70) = 0;
  *(undefined4 *)((int)this + 0x7c) = 0;
  *(undefined4 *)((int)this + 0x80) = 0;
  *(undefined4 *)((int)this + 0x78) = 0;
  *(undefined4 *)((int)this + 0x84) = 0;
  *(undefined4 *)((int)this + 0x60) = 0;
  *(undefined4 *)((int)this + 100) = 0;
  return;
}

/* __ZN17TPPStreamCompilerC4E11EShLanguagei @ 0x97bc96b8 (284 bytes) */
int __ZN17TPPStreamCompilerC4E11EShLanguagei(this, param_2, param_3)
  void *this;
  undefined4 param_2;
  undefined4 param_3;
{
  int iVar1;
  undefined *puVar2;
  int *piVar3;
  char in_RESERVE;
  byte in_cr0;
  
  *(undefined4 *)((int)this + 8) = param_2;
  *(undefined ***)this = &PTR___ZN9TCompilerD1Ev_a7b7d850;
  *(int *)((int)this + 4) = (int)this + 0xb0;
  *(undefined4 *)((int)this + 0xc) = 0;
  __ZN14TPoolAllocatorC1Ebii((void *)((int)this + 0x10),0,0x2000,0x10);
  *(int *)this = DAT_a7b7bd98 + 8;
  __ZN22ConstantAllocationListC1Ev((void *)((int)this + 0x44));
  ((int (*)())__ZN18ParseFunctionStackC1Ev)((void *)((int)this + 0x58));
  ((int (*)())__ZN19ParseWhileLoopStackC1Ev)((void *)((int)this + 0x5c));
  puVar2 = PTR__S_empty_rep_storage_a7b7c0f0;
  piVar3 = (int *)(PTR__S_empty_rep_storage_a7b7c0f0 + 8);
  do {
    if (in_RESERVE != '\0') {
      iVar1 = storeWordConditionalIndexed(*piVar3 + 1,0,piVar3);
      *piVar3 = iVar1;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  *(undefined4 *)((int)this + 0xb4) = 4;
  *(undefined **)((int)this + 0xb0) = puVar2 + 0xc;
  do {
    if (in_RESERVE != '\0') {
      iVar1 = storeWordConditionalIndexed(*piVar3 + 1,0,piVar3);
      *piVar3 = iVar1;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  *(undefined4 *)((int)this + 0xbc) = 4;
  *(undefined **)((int)this + 0xb8) = puVar2 + 0xc;
  *(undefined4 *)((int)this + 0xc0) = param_3;
  newQueue((unsigned char *)((int)this + 0x4c));
  *(undefined4 *)((int)this + 0x88) = 0;
  *(undefined4 *)((int)this + 0x9c) = 1;
  *(undefined4 *)((int)this + 0x68) = 0;
  *(undefined4 *)((int)this + 0x6c) = 0;
  *(undefined4 *)((int)this + 0x74) = 0;
  *(undefined4 *)((int)this + 0x70) = 0;
  *(undefined4 *)((int)this + 0x7c) = 0;
  *(undefined4 *)((int)this + 0x80) = 0;
  *(undefined4 *)((int)this + 0x78) = 0;
  *(undefined4 *)((int)this + 0x84) = 0;
  *(undefined4 *)((int)this + 0x60) = 0;
  *(undefined4 *)((int)this + 100) = 0;
  return;
}

/* __ZN17TPPStreamCompilerD2Ev @ 0x97bc97d4 (8 bytes) */
int __ZN17TPPStreamCompilerD2Ev(this)
  void *this;
{
  __ZN17TPPStreamCompilerD4Ev(this,0);
  return;
}

