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
  undefined4 uVar6;
  undefined4 uVar7;
  int iVar8;
  undefined4 uVar9;
  unsigned char * this_00;
  int *piVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  int *piVar19;
  
  if (*(int *)param_2 == 0) {
    return (int *)0x0;
  }
  piVar19 = *(int **)(*(int *)param_2 + 0xc);
  uVar6 = (**(code **)(*piVar19 + 0x20))(piVar19);
  uVar7 = (**(code **)(*piVar19 + 0x2c))(piVar19);
  iVar8 = (**(code **)(*piVar19 + 0x34))(piVar19);
  uVar9 = (**(code **)(*piVar19 + 0x38))(piVar19);
  iVar18 = piVar19[1];
  this_00 = (unsigned char *)GetGlobalPoolAllocator();
  piVar10 = (int *)TPoolAllocator__allocate(this_00,0x28);
  iVar15 = piVar19[2];
  iVar17 = piVar19[3];
  iVar16 = piVar19[4];
  iVar14 = piVar19[5];
  iVar13 = piVar19[6];
  iVar12 = piVar19[7];
  iVar11 = piVar19[8];
  piVar10[1] = piVar19[1];
  *piVar10 = (int)&PTR___ZN5TTypeD1Ev_a7b7d808;
  piVar10[2] = iVar15;
  piVar10[3] = iVar17;
  piVar10[4] = iVar16;
  piVar10[5] = iVar14;
  piVar10[6] = iVar13;
  piVar10[7] = iVar12;
  piVar10[8] = iVar11;
  uVar5 = piVar10[9];
  uVar2 = piVar19[9] & 0xfe000000;
  piVar10[9] = uVar2 | uVar5 & 0x1ffffff;
  uVar3 = ((uint)piVar19[9] >> 0x13 & 0x3f) << 0x13;
  piVar10[9] = uVar3 | uVar2 | uVar5 & 0x7ffff;
  uVar1 = piVar19[9] & 0x7f800;
  piVar10[9] = uVar1 | uVar3 | uVar2 | uVar5 & 0x7ff;
  uVar4 = ((uint)piVar19[9] >> 10 & 1) << 10;
  piVar10[9] = uVar4 | uVar1 | uVar3 | uVar2 | uVar5 & 0x3ff;
  piVar10[9] = ((uint)piVar19[9] >> 9 & 1) << 9 | uVar4 | uVar1 | uVar3 | uVar2 | uVar5 & 0x1ff;
  if (*(int *)(*(int *)param_2 + 0x48) != 0) {
    uVar9 = 0;
    iVar18 = 0;
  }
  if (iVar8 == 0) {
    iVar11 = *(int *)(param_2 + 0x20);
LAB_97bc4168:
    if (iVar11 == 0) goto LAB_97bc4174;
  }
  else {
    iVar11 = 0;
    if (*(uint *)(param_2 + 0x20) == 0) goto LAB_97bc4168;
    iVar8 = 0;
    if (*(uint *)(param_2 + 0x20) < 2) goto LAB_97bc4174;
  }
  uVar7 = 1;
LAB_97bc4174:
  (**(code **)(*piVar10 + 8))(piVar10,uVar6,uVar7,iVar8,uVar9,iVar18);
  return piVar10;
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
  unsigned char * pTVar7;
  unsigned char * this_01;
  unsigned char * this_02;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  char acStack_120 [264];
  
  this_00 = (unsigned char *)GetGlobalPoolAllocator();
  pTVar7 = (unsigned char *)TPoolAllocator__allocate(this_00,0x28);
  uVar13 = *(undefined4 *)(param_2 + 0x10);
  uVar11 = *(undefined4 *)(param_2 + 0x14);
  uVar10 = *(undefined4 *)(param_2 + 0x18);
  uVar9 = *(undefined4 *)(param_2 + 0x1c);
  uVar8 = *(undefined4 *)(param_2 + 0x20);
  uVar12 = *(undefined4 *)(param_2 + 8);
  uVar5 = *(undefined4 *)(param_2 + 4);
  *(undefined4 *)(pTVar7 + 0xc) = *(undefined4 *)(param_2 + 0xc);
  *(undefined4 *)(pTVar7 + 0x10) = uVar13;
  *(undefined4 *)(pTVar7 + 0x14) = uVar11;
  *(undefined4 *)(pTVar7 + 0x18) = uVar10;
  *(undefined4 *)(pTVar7 + 0x1c) = uVar9;
  *(undefined4 *)(pTVar7 + 0x20) = uVar8;
  *(undefined4 *)(pTVar7 + 8) = uVar12;
  *(undefined4 *)(pTVar7 + 4) = uVar5;
  *(undefined ***)pTVar7 = &PTR___ZN5TTypeD1Ev_a7b7d808;
  uVar6 = *(uint *)(pTVar7 + 0x24);
  uVar2 = *(uint *)(param_2 + 0x24) & 0xfe000000;
  *(uint *)(pTVar7 + 0x24) = uVar2 | uVar6 & 0x1ffffff;
  uVar3 = (*(uint *)(param_2 + 0x24) >> 0x13 & 0x3f) << 0x13;
  *(uint *)(pTVar7 + 0x24) = uVar3 | uVar2 | uVar6 & 0x7ffff;
  uVar1 = *(uint *)(param_2 + 0x24) & 0x7f800;
  *(uint *)(pTVar7 + 0x24) = uVar1 | uVar3 | uVar2 | uVar6 & 0x7ff;
  uVar4 = (*(uint *)(param_2 + 0x24) >> 10 & 1) << 10;
  *(uint *)(pTVar7 + 0x24) = uVar4 | uVar1 | uVar3 | uVar2 | uVar6 & 0x3ff;
  *(uint *)(pTVar7 + 0x24) =
       (*(uint *)(param_2 + 0x24) >> 9 & 1) << 9 | uVar4 | uVar1 | uVar3 | uVar2 | uVar6 & 0x1ff;
  this_01 = operator_new(0x38);
  __ZN12ParseOperandC1Ev(this_01);
  this_02 = operator_new(100);
  __ZN11ParseSymbolC1Ev(this_02);
  *(undefined4 *)(this_02 + 0x34) = 0;
  *(undefined4 *)(this_02 + 0x3c) = 1;
  (**(code **)(*(int *)pTVar7 + 0x28))(pTVar7,0);
  ParseSymbol__SetParseTreeType(this_02,pTVar7);
  uVar5 = TemporaryAllocator__getTemporary
                    (*(unsigned char **)(this + 0x60),*(ushort *)(this_02 + 0x2c));
  uVar8 = GetGLStringForType(*(ushort *)(this_02 + 0x2c));
  _sprintf(acStack_120,DAT_a7b7bd50,uVar5,uVar8);
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
  unsigned char * pTVar7;
  unsigned char * this_00;
  unsigned char * this_01;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  
  this = (unsigned char *)GetGlobalPoolAllocator();
  pTVar7 = (unsigned char *)TPoolAllocator__allocate(this,0x28);
  uVar13 = *(undefined4 *)(param_2 + 0xc);
  uVar12 = *(undefined4 *)(param_2 + 0x10);
  uVar11 = *(undefined4 *)(param_2 + 0x14);
  uVar10 = *(undefined4 *)(param_2 + 0x18);
  uVar9 = *(undefined4 *)(param_2 + 0x1c);
  uVar8 = *(undefined4 *)(param_2 + 0x20);
  uVar5 = *(undefined4 *)(param_2 + 4);
  *(undefined4 *)(pTVar7 + 8) = *(undefined4 *)(param_2 + 8);
  *(undefined4 *)(pTVar7 + 0xc) = uVar13;
  *(undefined4 *)(pTVar7 + 0x10) = uVar12;
  *(undefined4 *)(pTVar7 + 0x14) = uVar11;
  *(undefined4 *)(pTVar7 + 0x18) = uVar10;
  *(undefined4 *)(pTVar7 + 0x1c) = uVar9;
  *(undefined4 *)(pTVar7 + 0x20) = uVar8;
  *(undefined4 *)(pTVar7 + 4) = uVar5;
  *(undefined ***)pTVar7 = &PTR___ZN5TTypeD1Ev_a7b7d808;
  uVar6 = *(uint *)(pTVar7 + 0x24);
  uVar2 = *(uint *)(param_2 + 0x24) & 0xfe000000;
  *(uint *)(pTVar7 + 0x24) = uVar2 | uVar6 & 0x1ffffff;
  uVar3 = (*(uint *)(param_2 + 0x24) >> 0x13 & 0x3f) << 0x13;
  *(uint *)(pTVar7 + 0x24) = uVar3 | uVar2 | uVar6 & 0x7ffff;
  uVar1 = *(uint *)(param_2 + 0x24) & 0x7f800;
  *(uint *)(pTVar7 + 0x24) = uVar1 | uVar3 | uVar2 | uVar6 & 0x7ff;
  uVar4 = (*(uint *)(param_2 + 0x24) >> 10 & 1) << 10;
  *(uint *)(pTVar7 + 0x24) = uVar4 | uVar1 | uVar3 | uVar2 | uVar6 & 0x3ff;
  *(uint *)(pTVar7 + 0x24) =
       (*(uint *)(param_2 + 0x24) >> 9 & 1) << 9 | uVar4 | uVar1 | uVar3 | uVar2 | uVar6 & 0x1ff;
  this_00 = operator_new(0x38);
  __ZN12ParseOperandC1Ev(this_00);
  this_01 = operator_new(100);
  __ZN11ParseSymbolC1Ev(this_01);
  *(undefined4 *)(this_01 + 0x38) = 1;
  *(undefined4 *)(this_01 + 0x3c) = 0;
  *(undefined4 *)(this_01 + 0x34) = 0;
  ParseSymbol__SetName(this_01,param_3);
  (**(code **)(*(int *)pTVar7 + 0x28))(pTVar7,0);
  ParseSymbol__SetParseTreeType(this_01,pTVar7);
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
  unsigned char * pTVar7;
  unsigned char * this_01;
  unsigned char * this_02;
  size_t sVar8;
  char *pcVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  
  this_00 = (unsigned char *)GetGlobalPoolAllocator();
  pTVar7 = (unsigned char *)TPoolAllocator__allocate(this_00,0x28);
  uVar15 = *(undefined4 *)(param_2 + 0xc);
  uVar14 = *(undefined4 *)(param_2 + 0x10);
  uVar13 = *(undefined4 *)(param_2 + 0x14);
  uVar12 = *(undefined4 *)(param_2 + 0x18);
  uVar11 = *(undefined4 *)(param_2 + 0x1c);
  uVar10 = *(undefined4 *)(param_2 + 0x20);
  uVar5 = *(undefined4 *)(param_2 + 4);
  *(undefined4 *)(pTVar7 + 8) = *(undefined4 *)(param_2 + 8);
  *(undefined4 *)(pTVar7 + 0xc) = uVar15;
  *(undefined4 *)(pTVar7 + 0x10) = uVar14;
  *(undefined4 *)(pTVar7 + 0x14) = uVar13;
  *(undefined4 *)(pTVar7 + 0x18) = uVar12;
  *(undefined4 *)(pTVar7 + 0x1c) = uVar11;
  *(undefined4 *)(pTVar7 + 0x20) = uVar10;
  *(undefined4 *)(pTVar7 + 4) = uVar5;
  *(undefined ***)pTVar7 = &PTR___ZN5TTypeD1Ev_a7b7d808;
  uVar6 = *(uint *)(pTVar7 + 0x24);
  uVar2 = *(uint *)(param_2 + 0x24) & 0xfe000000;
  *(uint *)(pTVar7 + 0x24) = uVar2 | uVar6 & 0x1ffffff;
  uVar3 = (*(uint *)(param_2 + 0x24) >> 0x13 & 0x3f) << 0x13;
  *(uint *)(pTVar7 + 0x24) = uVar3 | uVar2 | uVar6 & 0x7ffff;
  uVar1 = *(uint *)(param_2 + 0x24) & 0x7f800;
  *(uint *)(pTVar7 + 0x24) = uVar1 | uVar3 | uVar2 | uVar6 & 0x7ff;
  uVar4 = (*(uint *)(param_2 + 0x24) >> 10 & 1) << 10;
  *(uint *)(pTVar7 + 0x24) = uVar4 | uVar1 | uVar3 | uVar2 | uVar6 & 0x3ff;
  *(uint *)(pTVar7 + 0x24) =
       (*(uint *)(param_2 + 0x24) >> 9 & 1) << 9 | uVar4 | uVar1 | uVar3 | uVar2 | uVar6 & 0x1ff;
  this_01 = operator_new(0x38);
  __ZN12ParseOperandC1Ev(this_01);
  this_02 = operator_new(100);
  __ZN11ParseSymbolC1Ev(this_02);
  sVar8 = _strlen(param_3);
  pcVar9 = _malloc(sVar8 + 10);
  _sprintf(pcVar9,DAT_a7b7bd58,param_3,param_4);
  *(undefined4 *)(this_02 + 0x38) = 1;
  *(undefined4 *)(this_02 + 0x3c) = 0;
  *(undefined4 *)(this_02 + 0x34) = 0;
  ParseSymbol__SetName(this_02,pcVar9);
  (**(code **)(*(int *)pTVar7 + 0x28))(pTVar7,0);
  ParseSymbol__SetParseTreeType(this_02,pTVar7);
  *(unsigned char **)this_01 = this_02;
  ParseSymbolTable__processOperand(*(unsigned char **)(this + 0x68),this_01);
  _free(pcVar9);
  return this_01;
}

/* TPPStreamCompiler__newIndirectOperandFromConstant @ 0x97bc4748 (2092 bytes) */
int TPPStreamCompiler__newIndirectOperandFromConstant(this, param_2, param_3)
  unsigned char * this;
  unsigned char * param_2;
  unsigned char * param_3;
{
  undefined4 uVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  byte bVar5;
  double dVar6;
  double dVar7;
  double dVar8;
  int iVar9;
  unsigned char * this_00;
  undefined4 *puVar10;
  unsigned char * this_01;
  uint uVar11;
  int iVar12;
  int iVar13;
  ushort uVar17;
  uint uVar14;
  unsigned char * p_Var15;
  int iVar16;
  undefined4 *puVar18;
  int iVar19;
  int iVar20;
  int iVar21;
  int iVar22;
  int iVar23;
  byte in_xer_so;
  uint uVar24;
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
  
  iVar20 = 0;
  bVar4 = false;
  local_90 = *(int **)(*(int *)(this + 0x70) + 0x10);
  iVar23 = *local_90;
  iVar19 = *(int *)(*(int *)(this + 0x70) + 0x2c);
  pTStack00000020 = param_3;
  local_88 = operator_new(0x38);
  __ZN12ParseOperandC1Ev(local_88);
  this_01 = operator_new(100);
  __ZN11ParseSymbolC1Ev(this_01);
  local_8c = 0;
  uVar11 = (**(code **)(*(int *)pTStack00000020 + 0x2c))(pTStack00000020);
  iVar12 = ParseOperand__GetBaseSize(param_2);
  iVar9 = DAT_97c3925c;
  iVar16 = DAT_97c39258;
  iVar22 = DAT_97c39254;
  iVar21 = DAT_97c39250;
  dVar8 = DOUBLE_97c30a58;
  local_84 = (iVar12 - 1U) / uVar11 + 1;
  if (iVar23 == 0) {
    bVar2 = true;
LAB_97bc4c8c:
    if (bVar2) {
      iVar21 = 0;
      iVar22 = 0;
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
        uVar17 = getOpenGLTypeFromTType(pTStack00000020);
        uVar14 = GetPPStreamTypeForGLType(uVar17);
        uVar24 = local_1f0 >> 0x10;
        local_1f0 = CONCAT22((ushort)((uVar11 - 1) * 0x1000000 >> 0x10) & 0x300 |
                             (ushort)(((uVar14 & 7) << 0x1a) >> 0x10) | (ushort)uVar24 & 0xff,
                             *(undefined2 *)(iVar19 + 10));
        if (0 < (int)uVar11) {
          puVar18 = (undefined4 *)(iVar21 * 4 + *(int *)(param_2 + 4));
          puVar10 = &local_1f0;
          uVar24 = uVar11;
          do {
            puVar10[0x50] = 1;
            iVar21 = iVar21 + 1;
            uVar1 = *puVar18;
            puVar18 = puVar18 + 1;
            puVar10[0x48] = uVar1;
            puVar10 = puVar10 + 1;
            uVar24 = uVar24 - 1;
          } while (uVar24 != 0);
        }
        if (*(int *)param_2 == 0) {
          uVar17 = *(ushort *)(param_2 + 0x18);
        }
        else {
          uVar17 = *(ushort *)(*(int *)param_2 + 0x2c);
        }
        ConstantAllocationList__addConstant
                  ((unsigned char *)(this + 0x44),local_1ec & 0xffff,local_b0,uVar17);
        _PPStreamAddConstant(*(undefined4 *)(this + 0x70),local_d0);
        p_Var15 = _calloc(0x1c,1);
        *p_Var15 = 0x3;
        *(uint *)(p_Var15 + 0xc) = local_1f0;
        *(uint *)(p_Var15 + 0x10) = local_1ec;
        *(undefined4 *)(p_Var15 + 0x14) = 0;
        _PPStreamChunkListAddChunk(local_90,p_Var15);
        if (iVar22 == 0) {
          ParseSymbol__SetParseTreeType(this_01,pTStack00000020);
          _sprintf(acStack_1e0,DAT_a7b7bd5c,local_1f0 & 0xffff);
          *(uint *)(this_01 + 0x28) = local_1f0 & 0xffff;
          ParseSymbol__SetName(this_01,acStack_1e0);
          iVar16 = (**(code **)(*(int *)pTStack00000020 + 0x24))(pTStack00000020);
          *(uint *)(this_01 + 0x38) = (uint)(iVar16 != 0);
          ParseSymbol__SetChunk(this_01,p_Var15);
          *(undefined4 *)(this_01 + 0x44) = 0;
          *(unsigned char **)local_88 = this_01;
          *(undefined4 *)(this_01 + 0x50) = 1;
          ParseSymbolTable__AddSymbol(*(unsigned char **)(this + 0x68),this_01);
          local_a0[1] = 0;
          local_a0[0] = local_1f0 & 0xffff;
          _PPStreamAddParamBindingArray(*(undefined4 *)(this + 0x70),local_a0);
        }
        else if ((iVar22 == local_84 + -1) &&
                (iVar16 = *(int *)(*(int *)(*(int *)(this + 0x70) + 0x14) + 4),
                *(short *)(iVar16 + 0x12) == 0)) {
          *(undefined2 *)(iVar16 + 0x12) = (*(unsigned short *)((unsigned char *)&(local_1f0) + 2));
        }
        iVar22 = iVar22 + 1;
      } while (iVar22 < local_84);
      return local_88;
    }
  }
  else {
    local_70 = this + 0x44;
    local_74 = (uint)(byte)(((int)uVar11 < 2) << 3 | (2 < (int)uVar11) << 2 | (uVar11 == 2) << 1 |
                           in_xer_so & 1) << 0x1c;
    local_80 = (uint)(byte)(((int)uVar11 < 1) << 3 | (1 < (int)uVar11) << 2 | (uVar11 == 1) << 1 |
                           in_xer_so & 1) << 0x1c;
    local_7c = (uint)(byte)(((int)uVar11 < 3) << 3 | (3 < (int)uVar11) << 2 | (uVar11 == 3) << 1 |
                           in_xer_so & 1) << 0x1c;
    local_78 = (uint)(byte)(((int)uVar11 < 4) << 3 | (4 < (int)uVar11) << 2 | (uVar11 == 4) << 1 |
                           in_xer_so & 1) << 0x1c;
    local_6c = local_74;
    do {
      local_d0[0] = iVar21;
      local_d0[1] = iVar22;
      local_d0[2] = iVar16;
      local_d0[3] = iVar9;
      local_1f0 = *(uint *)(iVar23 + 0xc);
      local_1ec = *(uint *)(iVar23 + 0x10);
      if ((local_1f0 & 0x1f0000) == 0x110000) {
        iVar12 = _PPStreamChunkListChunkAtIndex(iVar19,local_1f0 & 0xffff);
        ConstantAllocationList__getConstantUsage
                  ((unsigned char *)(this + 0x44),local_1ec & 0xffff,(bool *)local_d0,
                   local_e0);
        local_d0[5] = local_d0[0] + local_d0[1] + local_d0[2] + local_d0[3] ^ 0x80000000;
        local_d0[4] = 0x43300000;
        dVar6 = (double)CONCAT44(0x43300000,local_d0[5]);
        if (*(int *)param_2 == 0) {
          uVar17 = *(ushort *)(param_2 + 0x18);
        }
        else {
          uVar17 = *(ushort *)(*(int *)param_2 + 0x2c);
        }
        if (local_e0[0] == uVar17) {
          local_d0[5] = uVar11 ^ 0x80000000;
          local_d0[4] = 0x43300000;
          if ((float)(dVar6 - dVar8) == (float)((double)CONCAT44(0x43300000,local_d0[5]) - dVar8)) {
            bVar2 = true;
            bVar5 = (byte)((uint)local_74 >> 0x18);
            if ((bool)(bVar5 >> 5 & 1)) {
LAB_97bc49e0:
              if ((local_d0[1] != 0) &&
                 (*(float *)(iVar20 * 4 + *(int *)(param_2 + 4) + 4) == *(float *)(iVar12 + 0x10)))
              {
LAB_97bc4a14:
                if ((local_d0[0] != 0) &&
                   (*(float *)(*(int *)(param_2 + 4) + iVar20 * 4) == *(float *)(iVar12 + 0xc)))
                goto LAB_97bc4a38;
              }
LAB_97bc4a34:
              bVar2 = false;
            }
            else {
              if ((bool)(bVar5 >> 6 & 1)) {
                if ((bool)((byte)((uint)local_7c >> 0x1d) & 1)) {
LAB_97bc49bc:
                  if ((local_d0[2] != 0) &&
                     (*(float *)(iVar20 * 4 + *(int *)(param_2 + 4) + 8) ==
                      *(float *)(iVar12 + 0x14))) goto LAB_97bc49e0;
                }
                else {
                  if (!(bool)((byte)((uint)local_78 >> 0x1d) & 1)) goto LAB_97bc4a38;
                  if ((local_d0[3] != 0) &&
                     (*(float *)(iVar20 * 4 + *(int *)(param_2 + 4) + 0xc) ==
                      *(float *)(iVar12 + 0x18))) goto LAB_97bc49bc;
                }
                goto LAB_97bc4a34;
              }
              if ((bool)((byte)((uint)local_80 >> 0x1d) & 1)) goto LAB_97bc4a14;
            }
LAB_97bc4a38:
            iVar20 = iVar20 + uVar11;
            if ((bVar2) && (local_8c = iVar23, local_84 == 1)) {
              bVar4 = true;
            }
          }
        }
      }
      this_00 = local_70;
      dVar6 = DOUBLE_97c30a58;
      iVar23 = *(int *)(iVar23 + 8);
      if (local_8c == 0) {
        bVar2 = !bVar4;
      }
      else {
        bVar2 = !bVar4;
        if (bVar2) {
          if (iVar23 != 0) {
            bVar5 = (byte)((uint)local_6c >> 0x18);
            iVar12 = iVar23;
            do {
              local_1f0 = *(uint *)(iVar12 + 0xc);
              local_1ec = *(uint *)(iVar12 + 0x10);
              if ((local_1f0 & 0x1f0000) == 0x110000) {
                iVar13 = _PPStreamChunkListChunkAtIndex(iVar19,local_1f0 & 0xffff);
                ConstantAllocationList__getConstantUsage
                          ((unsigned char *)this_00,local_1ec & 0xffff,(bool *)local_d0,
                           local_e0);
                local_d0[4] = 0x43300000;
                local_d0[5] = local_d0[0] + local_d0[1] + local_d0[2] + local_d0[3] ^ 0x80000000;
                dVar7 = (double)CONCAT44(0x43300000,local_d0[5]);
                if (*(int *)param_2 == 0) {
                  uVar17 = *(ushort *)(param_2 + 0x18);
                }
                else {
                  uVar17 = *(ushort *)(*(int *)param_2 + 0x2c);
                }
                if (local_e0[0] == uVar17) {
                  local_d0[5] = uVar11 ^ 0x80000000;
                  local_d0[4] = 0x43300000;
                  if ((float)(dVar7 - dVar6) ==
                      (float)((double)CONCAT44(0x43300000,local_d0[5]) - dVar6)) {
                    bVar3 = true;
                    if ((bool)(bVar5 >> 5 & 1)) {
LAB_97bc4bec:
                      if ((local_d0[1] != 0) &&
                         (*(float *)(iVar20 * 4 + *(int *)(param_2 + 4) + 4) ==
                          *(float *)(iVar13 + 0x10))) {
LAB_97bc4c10:
                        if ((local_d0[0] != 0) &&
                           (*(float *)(*(int *)(param_2 + 4) + iVar20 * 4) ==
                            *(float *)(iVar13 + 0xc))) goto LAB_97bc4c34;
                      }
LAB_97bc4c30:
                      bVar3 = false;
                    }
                    else {
                      if ((bool)(bVar5 >> 6 & 1)) {
                        if ((bool)((byte)((uint)local_7c >> 0x1d) & 1)) {
LAB_97bc4bc8:
                          if ((local_d0[2] != 0) &&
                             (*(float *)(iVar20 * 4 + *(int *)(param_2 + 4) + 8) ==
                              *(float *)(iVar13 + 0x14))) goto LAB_97bc4bec;
                        }
                        else {
                          if (!(bool)((byte)((uint)local_78 >> 0x1d) & 1)) goto LAB_97bc4c34;
                          if ((local_d0[3] != 0) &&
                             (*(float *)(iVar20 * 4 + *(int *)(param_2 + 4) + 0xc) ==
                              *(float *)(iVar13 + 0x18))) goto LAB_97bc4bc8;
                        }
                        goto LAB_97bc4c30;
                      }
                      if ((bool)((byte)((uint)local_80 >> 0x1d) & 1)) goto LAB_97bc4c10;
                    }
LAB_97bc4c34:
                    iVar20 = iVar20 + uVar11;
                    if (!bVar3) {
                      iVar20 = 0;
                      local_8c = 0;
                      goto LAB_97bc4c7c;
                    }
                  }
                }
              }
              iVar13 = ParseOperand__GetBaseSize(param_2);
              if (iVar13 <= iVar20) {
                bVar4 = true;
                bVar2 = false;
              }
              iVar12 = *(int *)(iVar12 + 8);
              if ((iVar12 == 0) || (!bVar2)) goto LAB_97bc4c7c;
            } while( true );
          }
          goto LAB_97bc4c8c;
        }
      }
LAB_97bc4c7c:
      if (iVar23 == 0) goto LAB_97bc4c8c;
    } while (bVar2);
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
  bool bVar2;
  int iVar3;
  int iVar4;
  size_t sVar5;
  size_t sVar6;
  char *pcVar7;
  unsigned char * pPVar8;
  unsigned char * pPVar9;
  unsigned char * pPVar10;
  uint uVar11;
  void *this_00;
  uint uVar12;
  unsigned char ** ppPVar14;
  undefined3 in_register_0000001c;
  int iVar15;
  undefined4 in_r8;
  undefined4 uVar16;
  unsigned char * in_r10;
  undefined4 uVar17;
  int iVar18;
  int iVar19;
  char *pcVar20;
  char *pcVar21;
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
  ushort uVar13;
  
  iVar15 = CONCAT31(in_register_0000001c,param_5);
  local_70[0] = (unsigned char *)0x0;
  ppPVar14 = param_4;
  iVar18 = iVar15;
  ((int (*)())__ZN17TPPStreamCompiler22IndirectAddressHandlerEPP12ParseOperandS2_S2_)(this,local_70,param_3,param_4);
  local_68[0] = *param_3;
  bVar2 = false;
  local_68[1] = *param_4;
  if ((*(int *)local_68[0] != 0) &&
     ((sVar1 = *(short *)(*(int *)local_68[0] + 0x2c), sVar1 == 0x7ffe || (sVar1 == 0x7fff)))) {
    iVar3 = ((int (*)())TPPStreamCompiler__generateAddressLoad)(this,local_68[0]);
    if (iVar3 != 0) {
      TPPStreamCompiler__equalOperands__source0Indirect = 1;
    }
    iVar4 = ((int (*)())TPPStreamCompiler__generateAddressLoad)(this,local_68[1]);
    if (iVar4 != 0) {
      TPPStreamCompiler__equalOperands__source1Indirect = 1;
    }
    bVar2 = iVar4 != 0 || iVar3 != 0;
  }
  iVar3 = *(int *)local_68[0];
  if ((iVar3 == 0) || (*(short *)(iVar3 + 0x2c) != 0x7ffe)) {
    iVar3 = *(int *)local_68[0];
    if ((iVar3 == 0) || (*(short *)(iVar3 + 0x2c) != 0x7fff)) {
      uVar16 = 0;
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
      ((int (*)())TPPStreamCompiler__getOperandAsSourceVar)((unsigned char *)&local_80,this,local_68[0],ppPVar14,iVar18,in_r8,0,0);
      local_d0 = local_80;
      local_cc = local_7c;
      if (TPPStreamCompiler__equalOperands__source0Indirect != 0) {
        local_d0 = local_80 & 0x8fffff00 | 0x80000000;
      }
      ((int (*)())TPPStreamCompiler__getOperandAsSourceVar)((unsigned char *)&local_80,this,local_68[1],ppPVar14,iVar18,in_r8,local_80,uVar16);
      local_c8 = local_80;
      local_c4 = local_7c;
      if (TPPStreamCompiler__equalOperands__source1Indirect != 0) {
        local_c8 = local_80 & 0x8fffff00 | 0x80000000;
      }
      local_70[0] = (unsigned char *)((int (*)())TPPStreamCompiler__newTemporary)(this,param_2);
      ((int (*)())TPPStreamCompiler__getOperandAsDestVar)((unsigned char *)&local_80,this,local_70[0],ppPVar14,iVar18,in_r8);
      local_d4 = local_7c;
      iVar18 = 0x31;
      local_d8 = local_80;
      if (iVar15 == 0) {
        iVar18 = 0x36;
      }
      local_e0 = iVar18 << 0x12 | local_e0 & 0xfc03ffff;
      local_dc = (local_80 >> 0xc & 1) << 0x1c | local_dc & 0xefffffff;
      if (*(int *)local_70[0] == 0) {
        uVar13 = *(ushort *)(local_70[0] + 0x18);
      }
      else {
        uVar13 = *(ushort *)(*(int *)local_70[0] + 0x2c);
      }
      uVar11 = GetPPStreamTypeForGLType(uVar13);
      local_dc = (uVar11 & 7) << 0x17 | local_dc & 0xfc7fffff;
      iVar18 = ParseOperand__GetLogicalSize(local_70[0]);
      local_dc = (iVar18 + -1) * 0x4000000 & 0xc000000U | local_dc & 0xf3f3ffff;
      _PPStreamAddOperation(*(undefined4 *)(this + 0x70),&local_e0,0,0);
    }
    else {
      uVar11 = (int)*(short *)(iVar3 + 0x2e) - 1;
      if (-1 < (int)uVar11) {
        do {
          iVar3 = 0;
          iVar18 = 1;
          do {
            this_00 = operator_new(0x38);
            __ZN12ParseOperandC1Ev(this_00);
            *(void **)((int)local_68 + iVar3 + 8) = this_00;
            pPVar9 = operator_new(100);
            __ZN11ParseSymbolC1Ev(pPVar9);
            ParseSymbol__SetName(pPVar9,*(char **)(**(int **)((int)local_68 + iVar3) + 0x14));
            ParseSymbol__AddDirectIndex(pPVar9,uVar11);
            _sprintf((char *)&local_e0,DAT_a7b7bd90,uVar11);
            ParseSymbol__CatName(pPVar9,(char *)&local_e0);
            *(undefined4 *)(pPVar9 + 0x40) =
                 *(undefined4 *)(**(int **)((int)local_68 + iVar3) + 0x40);
            *(undefined4 *)(pPVar9 + 0x3c) =
                 *(undefined4 *)(**(int **)((int)local_68 + iVar3) + 0x3c);
            ParseSymbol__SetParseTreeType
                      (pPVar9,*(unsigned char **)(**(int **)((int)local_68 + iVar3) + 0xc));
            iVar4 = **(int **)((int)local_68 + iVar3);
            *(undefined4 *)(pPVar9 + 0x48) = 1;
            *(undefined4 *)(pPVar9 + 0x28) = *(undefined4 *)(iVar4 + 0x28);
            ParseSymbol__ResolveOpenGLType(pPVar9);
            **(undefined4 **)((int)local_68 + iVar3 + 8) = pPVar9;
            if ((*(short *)(pPVar9 + 0x2c) != 0x7ffe) && (*(short *)(pPVar9 + 0x2c) != 0x7fff)) {
              ParseSymbolTable__processOperand
                        (*(unsigned char **)(this + 0x68),
                         *(unsigned char **)((int)local_68 + iVar3 + 8));
            }
            pPVar8 = local_70;
            iVar18 = iVar18 + -1;
            iVar3 = iVar3 + 4;
          } while (-1 < iVar18);
          ppPVar14 = local_68 + 3;
          iVar18 = iVar15;
          local_70[0] = (unsigned char *)((int (*)())TPPStreamCompiler__equalOperands)(this,param_2,local_68 + 2,ppPVar14,param_5);
          pPVar10 = local_68[2];
          if (local_68[2] != (void *)0x0) {
            __ZN12ParseOperandD1Ev(local_68[2]);
            __ZdlPv(pPVar10);
          }
          pPVar10 = local_68[3];
          if (local_68[3] != (void *)0x0) {
            __ZN12ParseOperandD1Ev(local_68[3]);
            __ZdlPv(pPVar10);
          }
          pPVar10 = local_70;
          if ((pPVar8 != (unsigned char *)0x0) && (local_70[0] != (unsigned char *)0x0)) {
            pPVar10 = (unsigned char *)((int (*)())TPPStreamCompiler__newTemporary)(this,param_2);
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
            ((int (*)())TPPStreamCompiler__getOperandAsDestVar)((unsigned char *)&local_90,this,pPVar10,ppPVar14,iVar18,in_r8);
            local_d8 = local_90;
            local_d4 = local_8c;
            ((int (*)())TPPStreamCompiler__getOperandAsSourceVar)((unsigned char *)&local_90,this,pPVar8,ppPVar14,iVar18,in_r8,iVar4,in_r10);
            local_d0 = local_90;
            local_cc = local_8c;
            ((int (*)())TPPStreamCompiler__getOperandAsSourceVar)((unsigned char *)&local_90,this,local_70[0],ppPVar14,iVar18,in_r8,iVar4,in_r10
                      );
            local_e0 = ((iVar15 == 0) + 0x24) * 0x40000 | local_e0 & 0xfc03ffff;
            local_dc = (local_d8 >> 0xc & 1) << 0x1c | local_dc & 0xefffffff;
            local_c8 = local_90;
            local_c4 = local_8c;
            if (*(int *)local_70[0] == 0) {
              uVar13 = *(ushort *)(local_70[0] + 0x18);
            }
            else {
              uVar13 = *(ushort *)(*(int *)local_70[0] + 0x2c);
            }
            in_r10 = local_70[0];
            uVar12 = GetPPStreamTypeForGLType(uVar13);
            local_dc = (uVar12 & 7) << 0x17 | local_dc & 0xfc7fffff;
            iVar18 = ParseOperand__GetLogicalSize(local_70[0]);
            local_dc = (iVar18 + -1) * 0x4000000 & 0xc000000U | local_dc & 0xf3f3ffff;
            _PPStreamAddOperation(*(undefined4 *)(this + 0x70),&local_e0,0,0);
            __ZN12ParseOperandD1Ev(pPVar8);
            __ZdlPv(pPVar8);
            pPVar8 = local_70;
            if (local_70[0] != (unsigned char *)0x0) {
              __ZN12ParseOperandD1Ev(local_70[0]);
              __ZdlPv(pPVar8);
            }
          }
          local_70[0] = pPVar10;
          uVar11 = uVar11 - 1;
        } while (-1 < (int)uVar11);
      }
    }
  }
  else {
    iVar18 = *(int *)(*(int *)(iVar3 + 0xc) + 8);
    if (iVar18 != 0) {
      iVar3 = *(int *)(iVar18 + 4);
      iVar4 = (*(int *)(iVar18 + 8) - iVar3 >> 3) + -1;
      if (-1 < iVar4) {
        while( true ) {
          iVar19 = 0;
          while( true ) {
            pcVar20 = *(char **)(*(int *)local_68[iVar19] + 0x14);
            iVar3 = (**(code **)(**(int **)(iVar3 + iVar4 * 8) + 0x1c))();
            *(undefined1 *)(*(int *)(iVar3 + 4) + *(int *)(*(int *)(iVar3 + 4) + -0xc)) =
                 *DAT_a7b7bd9c;
            pcVar21 = *(char **)(iVar3 + 4);
            sVar5 = _strlen(pcVar21);
            sVar5 = sVar5 + 1;
            if (pcVar20 != (char *)0x0) {
              sVar6 = _strlen(pcVar20);
              sVar5 = sVar5 + sVar6 + 1;
            }
            pcVar7 = _malloc(sVar5);
            if (pcVar20 == (char *)0x0) {
              _strcpy(pcVar7,pcVar21);
            }
            else {
              _sprintf(pcVar7,DAT_a7b7bd8c,pcVar20,pcVar21);
            }
            pPVar8 = operator_new(0x38);
            __ZN12ParseOperandC1Ev(pPVar8);
            local_68[iVar19 + 2] = pPVar8;
            pPVar9 = operator_new(100);
            __ZN11ParseSymbolC1Ev(pPVar9);
            ParseSymbol__SetName(pPVar9,pcVar7);
            _free(pcVar7);
            *(undefined4 *)(pPVar9 + 0x40) = *(undefined4 *)(*(int *)local_68[iVar19] + 0x40);
            *(undefined4 *)(pPVar9 + 0x3c) = *(undefined4 *)(*(int *)local_68[iVar19] + 0x3c);
            ParseSymbol__SetParseTreeType(pPVar9,*(unsigned char **)(*(int *)(iVar18 + 4) + iVar4 * 8));
            *(undefined4 *)(pPVar9 + 0x28) = *(undefined4 *)(*(int *)local_68[iVar19] + 0x28);
            *(unsigned char **)local_68[iVar19 + 2] = pPVar9;
            if ((*(short *)(pPVar9 + 0x2c) != 0x7ffe) && (*(short *)(pPVar9 + 0x2c) != 0x7fff)) {
              ParseSymbolTable__processOperand
                        (*(unsigned char **)(this + 0x68),local_68[iVar19 + 2]);
            }
            pPVar8 = local_70;
            iVar19 = iVar19 + 1;
            if (1 < iVar19) break;
            iVar3 = *(int *)(iVar18 + 4);
          }
          ppPVar14 = local_68 + 3;
          iVar3 = iVar15;
          local_70[0] = (unsigned char *)((int (*)())TPPStreamCompiler__equalOperands)(this,param_2,local_68 + 2,ppPVar14,param_5);
          pPVar10 = local_68[2];
          if (local_68[2] != (void *)0x0) {
            __ZN12ParseOperandD1Ev(local_68[2]);
            __ZdlPv(pPVar10);
          }
          pPVar10 = local_68[3];
          if (local_68[3] != (void *)0x0) {
            __ZN12ParseOperandD1Ev(local_68[3]);
            __ZdlPv(pPVar10);
          }
          pPVar10 = local_70;
          if ((pPVar8 != (unsigned char *)0x0) && (local_70[0] != (unsigned char *)0x0)) {
            pPVar10 = (unsigned char *)((int (*)())TPPStreamCompiler__newTemporary)(this,param_2);
            uVar16 = 0;
            uVar17 = 0;
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
            ((int (*)())TPPStreamCompiler__getOperandAsDestVar)((unsigned char *)&local_a0,this,pPVar10,ppPVar14,iVar3,in_r8);
            local_d8 = local_a0;
            local_d4 = local_9c;
            ((int (*)())TPPStreamCompiler__getOperandAsSourceVar)((unsigned char *)&local_a0,this,pPVar8,ppPVar14,iVar3,in_r8,uVar16,uVar17);
            local_d0 = local_a0;
            local_cc = local_9c;
            ((int (*)())TPPStreamCompiler__getOperandAsSourceVar)((unsigned char *)&local_a0,this,local_70[0],ppPVar14,iVar3,in_r8,uVar16,uVar17
                      );
            local_e0 = ((iVar15 == 0) + 0x24) * 0x40000 | local_e0 & 0xfc03ffff;
            local_dc = (local_d8 >> 0xc & 1) << 0x1c | local_dc & 0xefffffff;
            local_c8 = local_a0;
            local_c4 = local_9c;
            if (*(int *)local_70[0] == 0) {
              uVar13 = *(ushort *)(local_70[0] + 0x18);
            }
            else {
              uVar13 = *(ushort *)(*(int *)local_70[0] + 0x2c);
            }
            uVar11 = GetPPStreamTypeForGLType(uVar13);
            local_dc = (uVar11 & 7) << 0x17 | local_dc & 0xfc7fffff;
            iVar3 = ParseOperand__GetLogicalSize(local_70[0]);
            local_dc = (iVar3 + -1) * 0x4000000 & 0xc000000U | local_dc & 0xf3f3ffff;
            _PPStreamAddOperation(*(undefined4 *)(this + 0x70),&local_e0,0,0);
            __ZN12ParseOperandD1Ev(pPVar8);
            __ZdlPv(pPVar8);
            pPVar8 = local_70;
            if (local_70[0] != (unsigned char *)0x0) {
              __ZN12ParseOperandD1Ev(local_70[0]);
              __ZdlPv(pPVar8);
            }
          }
          local_70[0] = pPVar10;
          iVar4 = iVar4 + -1;
          if (iVar4 < 0) break;
          iVar3 = *(int *)(iVar18 + 4);
        }
      }
    }
  }
  if (bVar2) {
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
  bool bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  size_t sVar5;
  size_t sVar6;
  char *pcVar7;
  unsigned char * pPVar8;
  unsigned char * pPVar9;
  void *this_00;
  ushort uVar10;
  undefined3 in_register_00000018;
  unsigned char ** ppPVar11;
  undefined4 in_r7;
  undefined4 in_r8;
  undefined4 in_r9;
  undefined4 in_r10;
  int iVar12;
  int iVar13;
  char *pcVar14;
  char *pcVar15;
  unsigned char * this_01;
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
  
  iVar12 = CONCAT31(in_register_00000018,param_4);
  ((int (*)())__ZN17TPPStreamCompiler22IndirectAddressHandlerEPP12ParseOperandS2_)(this,param_2,param_3);
  local_60[0] = *param_2;
  bVar1 = false;
  local_60[1] = *param_3;
  if ((*(short *)(*(int *)local_60[0] + 0x2c) == 0x7ffe) ||
     (*(short *)(*(int *)local_60[0] + 0x2c) == 0x7fff)) {
    iVar3 = ((int (*)())TPPStreamCompiler__generateAddressLoad)(this,local_60[0]);
    if (iVar3 != 0) {
      TPPStreamCompiler__assignOperands__destIndirect = 1;
    }
    iVar4 = ((int (*)())TPPStreamCompiler__generateAddressLoad)(this,local_60[1]);
    if (iVar4 != 0) {
      TPPStreamCompiler__assignOperands__sourceIndirect = 1;
    }
    bVar1 = iVar4 != 0 || iVar3 != 0;
  }
  iVar3 = *(int *)local_60[0];
  if (*(short *)(iVar3 + 0x2c) == 0x7ffe) {
    iVar12 = *(int *)(*(int *)(iVar3 + 0xc) + 8);
    if (iVar12 != 0) {
      iVar4 = *(int *)(iVar12 + 4);
      iVar3 = *(int *)(iVar12 + 8) - iVar4 >> 3;
      if (iVar3 != 0) {
        while( true ) {
          iVar3 = iVar3 + -1;
          iVar13 = 0;
          while( true ) {
            pcVar14 = *(char **)(*(int *)local_60[iVar13] + 0x14);
            iVar4 = (**(code **)(**(int **)(iVar4 + iVar3 * 8) + 0x1c))();
            *(undefined1 *)(*(int *)(iVar4 + 4) + *(int *)(*(int *)(iVar4 + 4) + -0xc)) =
                 *DAT_a7b7bd9c;
            pcVar15 = *(char **)(iVar4 + 4);
            sVar5 = _strlen(pcVar15);
            sVar5 = sVar5 + 1;
            if (pcVar14 != (char *)0x0) {
              sVar6 = _strlen(pcVar14);
              sVar5 = sVar5 + sVar6 + 1;
            }
            pcVar7 = _malloc(sVar5);
            if (pcVar14 == (char *)0x0) {
              _strcpy(pcVar7,pcVar15);
            }
            else {
              _sprintf(pcVar7,DAT_a7b7bd8c,pcVar14,pcVar15);
            }
            pPVar8 = operator_new(0x38);
            __ZN12ParseOperandC1Ev(pPVar8);
            local_60[iVar13 + 2] = pPVar8;
            pPVar9 = operator_new(100);
            __ZN11ParseSymbolC1Ev(pPVar9);
            ParseSymbol__SetName(pPVar9,pcVar7);
            _free(pcVar7);
            *(undefined4 *)(pPVar9 + 0x3c) = 0;
            *(undefined4 *)(pPVar9 + 0x40) = 0;
            ParseSymbol__SetParseTreeType(pPVar9,*(unsigned char **)(*(int *)(iVar12 + 4) + iVar3 * 8));
            *(undefined4 *)(pPVar9 + 0x28) = *(undefined4 *)(*(int *)local_60[iVar13] + 0x28);
            *(unsigned char **)local_60[iVar13 + 2] = pPVar9;
            if ((*(short *)(pPVar9 + 0x2c) != 0x7ffe) && (*(short *)(pPVar9 + 0x2c) != 0x7fff)) {
              ParseSymbolTable__processOperand
                        (*(unsigned char **)(this + 0x68),local_60[iVar13 + 2]);
            }
            iVar13 = iVar13 + 1;
            if (1 < iVar13) break;
            iVar4 = *(int *)(iVar12 + 4);
          }
          ((int (*)())TPPStreamCompiler__assignOperands)(this,local_60 + 2,local_60 + 3,param_4);
          pPVar8 = local_60[2];
          if (local_60[2] != (void *)0x0) {
            __ZN12ParseOperandD1Ev(local_60[2]);
            __ZdlPv(pPVar8);
          }
          pPVar8 = local_60[3];
          if (local_60[3] != (void *)0x0) {
            __ZN12ParseOperandD1Ev(local_60[3]);
            __ZdlPv(pPVar8);
          }
          if (iVar3 == 0) break;
          iVar4 = *(int *)(iVar12 + 4);
        }
      }
    }
  }
  else if (*(short *)(iVar3 + 0x2c) == 0x7fff) {
    uVar2 = (uint)*(short *)(iVar3 + 0x2e);
    while (uVar2 != 0) {
      uVar2 = uVar2 - 1;
      iVar3 = 0;
      iVar12 = 1;
      do {
        this_00 = operator_new(0x38);
        __ZN12ParseOperandC1Ev(this_00);
        *(void **)((int)local_60 + iVar3 + 0x10) = this_00;
        pPVar9 = operator_new(100);
        __ZN11ParseSymbolC1Ev(pPVar9);
        ParseSymbol__SetName(pPVar9,*(char **)(**(int **)((int)local_60 + iVar3) + 0x14));
        ParseSymbol__AddDirectIndex(pPVar9,uVar2);
        _sprintf((char *)&local_c0,DAT_a7b7bd90,uVar2);
        ParseSymbol__CatName(pPVar9,(char *)&local_c0);
        *(undefined4 *)(pPVar9 + 0x40) = 0;
        *(undefined4 *)(pPVar9 + 0x3c) = 0;
        ParseSymbol__SetParseTreeType(pPVar9,*(unsigned char **)(**(int **)((int)local_60 + iVar3) + 0xc));
        iVar4 = **(int **)((int)local_60 + iVar3);
        *(undefined4 *)(pPVar9 + 0x48) = 1;
        *(undefined4 *)(pPVar9 + 0x28) = *(undefined4 *)(iVar4 + 0x28);
        ParseSymbol__ResolveOpenGLType(pPVar9);
        **(undefined4 **)((int)local_60 + iVar3 + 0x10) = pPVar9;
        if ((*(short *)(pPVar9 + 0x2c) != 0x7ffe) && (*(short *)(pPVar9 + 0x2c) != 0x7fff)) {
          ParseSymbolTable__processOperand
                    (*(unsigned char **)(this + 0x68),
                     *(unsigned char **)((int)local_60 + iVar3 + 0x10));
        }
        iVar12 = iVar12 + -1;
        iVar3 = iVar3 + 4;
      } while (-1 < iVar12);
      ((int (*)())TPPStreamCompiler__assignOperands)(this,local_60 + 4,local_60 + 5,param_4);
      pPVar8 = local_50;
      if (local_50[0] != (void *)0x0) {
        __ZN12ParseOperandD1Ev(local_50[0]);
        __ZdlPv(pPVar8);
      }
      pPVar8 = local_50[1];
      if (local_50[1] != (void *)0x0) {
        __ZN12ParseOperandD1Ev(local_50[1]);
        __ZdlPv(pPVar8);
      }
    }
  }
  else {
    pPVar8 = *(unsigned char **)(this + 0x88);
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
    if (pPVar8 == (unsigned char *)0x0) {
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
        uVar10 = *(ushort *)(*param_2 + 0x18);
      }
      else {
        uVar10 = *(ushort *)(iVar12 + 0x2c);
      }
      uVar2 = GetPPStreamTypeForGLType(uVar10);
      local_ac = (uVar2 & 7) << 0x17 | local_ac & 0xfc7fffff;
      iVar12 = ParseOperand__GetLogicalSize(*param_2);
      local_ac = (iVar12 + -1) * 0x4000000 & 0xc000000U | local_ac & 0xf3f3ffff;
      local_70 = local_a8;
      local_6c = local_a4;
      local_c0 = local_a0;
      local_bc = local_9c;
      iVar12 = ((int (*)())TPPStreamCompiler__duplicateDestinationSource)(this,local_a8,local_a4,local_a0,local_9c);
      if ((iVar12 == 0) &&
         (((CONCAT31(in_register_00000018,param_4) == 0 || (*(int *)(this + 0xc4) < 2)) ||
          (iVar12 = ((int (*)())TPPStreamCompiler__copyPropagateCompilerTemp)(this,(unsigned char *)&local_b0,*param_3),
          iVar12 == 0)))) {
        _PPStreamAddOperation(*(undefined4 *)(this + 0x70),&local_b0,0,0);
      }
    }
    else {
      this_01 = *param_2;
      local_50[2] = *(unsigned char **)(pPVar8 + 0xc);
      if (this_01 != (unsigned char *)0x0) {
        __ZN12ParseOperandD1Ev(this_01);
        __ZdlPv(this_01);
        pPVar8 = *(unsigned char **)(this + 0x88);
      }
      *param_2 = pPVar8;
      ppPVar11 = local_60 + 6;
      *(undefined4 *)(this + 0x88) = 0;
      *(undefined4 *)(*param_2 + 0xc) = 0;
      local_b0 = local_b0 & 0x1c03ffff | 0x41b40000;
      ((int (*)())__ZN17TPPStreamCompiler22IndirectAddressHandlerEPP12ParseOperandS2_S2_)(this,param_2,param_3,ppPVar11);
      ParseOperand__RemoveDirectIndex(*param_2);
      ((int (*)())TPPStreamCompiler__getOperandAsDestVar)((unsigned char *)&local_c0,this,*param_2,ppPVar11,in_r7,in_r8);
      local_a8 = local_c0;
      local_a4 = local_bc;
      ((int (*)())TPPStreamCompiler__getOperandAsSourceVar)((unsigned char *)&local_c0,this,*param_3,ppPVar11,in_r7,in_r8,in_r9,in_r10);
      local_a0 = local_c0;
      local_9c = local_bc;
      ((int (*)())TPPStreamCompiler__getOperandAsSourceVar)((unsigned char *)&local_c0,this,local_50[2],ppPVar11,in_r7,in_r8,in_r9,in_r10);
      local_ac = (local_a8 >> 0xc & 1) << 0x1c | local_ac & 0xefffffff;
      local_98 = local_c0;
      local_94 = local_bc;
      iVar12 = *(int *)*param_2;
      if (iVar12 == 0) {
        uVar10 = *(ushort *)(*param_2 + 0x18);
      }
      else {
        uVar10 = *(ushort *)(iVar12 + 0x2c);
      }
      uVar2 = GetPPStreamTypeForGLType(uVar10);
      local_ac = (uVar2 & 7) << 0x17 | local_ac & 0xfc7fffff;
      iVar12 = ParseOperand__GetLogicalSize(*param_2);
      local_ac = (iVar12 + -1) * 0x4000000 & 0xc000000U | local_ac & 0xf3f3ffff;
      _PPStreamAddOperation(*(undefined4 *)(this + 0x70),&local_b0,0,0);
      pPVar8 = local_50[2];
      if (local_50[2] != (void *)0x0) {
        __ZN12ParseOperandD1Ev(local_50[2]);
        __ZdlPv(pPVar8);
      }
    }
  }
  if (bVar1) {
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
    TPPStreamCompiler__warning(SUB41(this,0),(char *)0x0,*(char **)(*(int *)param_2 + 0x14),DAT_a7b7bd3c,in_r7,in_r8,
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
int TPPStreamCompiler__constructReplicate(param_1, param_2, param_3)
  unsigned char ** param_1;
  unsigned char ** param_2;
  int param_3;
{
  bool bVar1;
  int iVar2;
  uint uVar3;
  int *piVar5;
  undefined4 in_r6;
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
  undefined4 local_30;
  ushort uVar4;
  
  local_30 = 0;
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
  ((int (*)())TPPStreamCompiler__getOperandAsDestVar)((unsigned char *)&local_40,param_1,*param_2,in_r6,in_r7,in_r8);
  piVar5 = *(int **)param_3;
  local_78 = local_40 & 0xfffe1c2f | 0x6c;
  local_74 = local_3c;
  if (*piVar5 == 0) {
    uVar4 = *(ushort *)(piVar5 + 6);
    if (uVar4 == 0x1406) {
      local_30 = *(undefined4 *)piVar5[1];
    }
    else {
      if (uVar4 < 0x1407) {
        bVar1 = uVar4 == 0x1404;
      }
      else {
        bVar1 = uVar4 == 0x8b56;
      }
      if (bVar1) {
        local_30 = *(undefined4 *)piVar5[1];
      }
    }
    if (*piVar5 == 0) {
      uVar4 = *(ushort *)(piVar5 + 6);
    }
    else {
      uVar4 = *(ushort *)(*piVar5 + 0x2c);
    }
    ((int (*)())TPPStreamCompiler__getConstantAsSourceVar)((unsigned char *)&local_40,(uint)param_1,(short)&STACKARG(0xffffff40) + 0x90,1,(uint)uVar4);
  }
  else {
    ((int (*)())TPPStreamCompiler__getOperandAsSourceVar)((unsigned char *)&local_40,param_1,piVar5,in_r6,in_r7,in_r8,uVar6,uVar7);
  }
  local_70 = local_40;
  local_6c = local_3c;
  for (iVar8 = 0; iVar2 = ParseOperand__GetLogicalSize(*param_2), iVar8 < iVar2; iVar8 = iVar8 + 1)
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
    uVar4 = *(ushort *)(*param_2 + 0x18);
  }
  else {
    uVar4 = *(ushort *)(iVar8 + 0x2c);
  }
  uVar3 = GetPPStreamTypeForGLType(uVar4);
  local_7c = (uVar3 & 7) << 0x17 | local_7c & 0xfc7fffff;
  iVar8 = ParseOperand__GetLogicalSize(*param_2);
  local_7c = (iVar8 + -1) * 0x4000000 & 0xc000000U | local_7c & 0xf3f3ffff;
  ((int (*)())TPPStreamCompiler__AddOperation)((unsigned char *)param_1,param_2,(unsigned char *)&local_80,(char *)0x0,0);
  return 1;
}

/* TPPStreamCompiler__constructDiagonal @ 0x97bc66d8 (1452 bytes) */
int TPPStreamCompiler__constructDiagonal(param_1, param_2, param_3)
  unsigned char ** param_1;
  unsigned char ** param_2;
  int param_3;
{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  undefined4 in_r6;
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
  ushort uVar8;
  
  ((int (*)())__ZN17TPPStreamCompiler22IndirectAddressHandlerEPP12ParseOperandS2_)(param_1,param_2,(unsigned char **)param_3);
  iVar13 = 0;
  iVar5 = ParseOperand__GetLogicalSize(*param_2);
  iVar6 = ParseOperand__IsMatrix(*param_2);
  iVar11 = iVar5;
  if (iVar6 == 0) {
    iVar11 = 1;
  }
  if (iVar11 != 0) {
    bVar1 = iVar5 != 4;
    puVar12 = local_70;
    do {
      puVar4 = local_70;
      iVar6 = 4;
      do {
        *puVar4 = 0;
        puVar4 = puVar4 + 1;
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
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
      ((int (*)())TPPStreamCompiler__getOperandAsDestVar)((unsigned char *)&local_60,param_1,*param_2,in_r6,in_r7,in_r8);
      piVar10 = *(int **)param_3;
      uVar7 = local_60 & 0xfffe1c0f;
      uVar9 = uVar7 | 0x6c;
      local_a4 = local_5c;
      local_a8 = uVar9;
      if (*piVar10 == 0) {
        uVar8 = *(ushort *)(piVar10 + 6);
        if (uVar8 == 0x1406) {
          *puVar12 = *(undefined4 *)piVar10[1];
        }
        else {
          if (uVar8 < 0x1407) {
            bVar3 = uVar8 == 0x1404;
          }
          else {
            bVar3 = uVar8 == 0x8b56;
          }
          if (bVar3) {
            *puVar12 = *(undefined4 *)piVar10[1];
          }
        }
        if (iVar13 == 1) {
          local_a8 = uVar7 | 0x406c;
        }
        else if (iVar13 < 2) {
          if (bVar2) {
            local_a8 = uVar7 | 0x206c;
          }
        }
        else if (iVar13 == 2) {
          local_a8 = uVar7 | 0x806c;
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
        ((int (*)())TPPStreamCompiler__getOperandAsDestVar)((unsigned char *)&local_60,param_1,*param_2,in_r6,in_r7,in_r8);
        local_e8 = local_60 & 0xfffe1c03 | 0x6c;
        local_e4 = local_5c;
        ((int (*)())TPPStreamCompiler__getOperandAsSourceVar)((unsigned char *)&local_60,param_1,*(undefined4 *)param_3,in_r6,in_r7,in_r8,uVar9,
                   in_r10);
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
        iVar6 = *(int *)*param_2;
        if (iVar6 == 0) {
          uVar8 = *(ushort *)(*param_2 + 0x18);
        }
        else {
          uVar8 = *(ushort *)(iVar6 + 0x2c);
        }
        uVar7 = GetPPStreamTypeForGLType(uVar8);
        local_ec = (uVar7 & 7) << 0x17 | local_ec & 0xfc7fffff;
        iVar6 = ParseOperand__GetLogicalSize(*param_2);
        local_ec = (iVar6 + -1) * 0x4000000 & 0xc000000U | local_ec & 0xf3f3ffff;
        ((int (*)())TPPStreamCompiler__AddOperation)((unsigned char *)param_1,param_2,(unsigned char *)&local_f0,
                     (char *)0x0,0);
        piVar10 = *(int **)param_3;
      }
      if (iVar13 == 1) {
        uVar7 = local_a8 & 0xfffffcff | 0x2000;
        if (iVar5 != 3) {
          if (bVar1) goto LAB_97bc6b98;
          uVar7 = local_a8 & 0xfffffcf3 | 0x1200c;
        }
LAB_97bc6b90:
        uVar7 = uVar7 & 0xffffffcf | 0x8020;
      }
      else {
        uVar7 = local_a8;
        if (iVar13 < 2) {
          if (bVar2) {
            if (iVar5 == 3) {
LAB_97bc6ae0:
              local_a8 = local_a8 & 0xffffffcf | 0x8020;
LAB_97bc6af8:
              uVar7 = local_a8 & 0xffffff3f | 0x4040;
            }
            else if (iVar5 < 4) {
              if (iVar5 == 2) goto LAB_97bc6af8;
            }
            else if (!bVar1) {
              local_a8 = local_a8 & 0xfffffff3 | 0x1000c;
              goto LAB_97bc6ae0;
            }
          }
        }
        else if (iVar13 == 2) {
          uVar7 = local_a8 & 0xfffffc3f | 0x6040;
          if (!bVar1) {
            uVar7 = local_a8 & 0xfffffc33 | 0x1604c;
          }
        }
        else if (iVar13 == 3) {
          uVar7 = local_a8 & 0xfffffc3f | 0x6040;
          goto LAB_97bc6b90;
        }
      }
LAB_97bc6b98:
      local_a8 = uVar7;
      if (*piVar10 == 0) {
        uVar8 = *(ushort *)(piVar10 + 6);
      }
      else {
        uVar8 = *(ushort *)(*piVar10 + 0x2c);
      }
      ((int (*)())TPPStreamCompiler__getConstantAsSourceVar)((unsigned char *)&local_60,(uint)param_1,(ushort)local_70,iVar5,(uint)uVar8);
      local_ac = (local_a8 >> 0xc & 1) << 0x1c | local_ac & 0xefffffff;
      local_a0 = local_60;
      local_9c = local_5c;
      iVar6 = *(int *)*param_2;
      if (iVar6 == 0) {
        uVar8 = *(ushort *)(*param_2 + 0x18);
      }
      else {
        uVar8 = *(ushort *)(iVar6 + 0x2c);
      }
      uVar7 = GetPPStreamTypeForGLType(uVar8);
      local_ac = (uVar7 & 7) << 0x17 | local_ac & 0xfc7fffff;
      iVar13 = iVar13 + 1;
      iVar6 = ParseOperand__GetLogicalSize(*param_2);
      local_ac = (iVar6 + -1) * 0x4000000 & 0xc000000U | local_ac & 0xf3f3ffff;
      in_r6 = 0;
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
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
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
  ushort uVar7;
  
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
  iVar3 = ParseOperand__GetLogicalSize(*param_2);
  uVar12 = 0;
  iVar4 = ParseOperand__IsMatrix(*param_2);
  local_5c = 0;
  iVar13 = iVar3;
  if (iVar4 == 0) {
    iVar13 = 1;
  }
  local_58 = 0xffffffff;
  local_54 = 0;
  uVar10 = 0;
  iVar4 = -1;
  if (iVar13 != 0) {
    do {
      bVar1 = local_5c == 0;
      if ((bVar1) || (uVar10 != 0)) {
        iVar17 = 4;
        puVar2 = local_80;
        do {
          *puVar2 = 0;
          puVar2 = puVar2 + 1;
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
      bVar1 = iVar3 == 0;
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
        uVar6 = in_r8;
        do {
          iVar17 = iVar4 << 2;
          in_r8 = uVar12;
          if (uVar12 == uVar9) {
            local_58 = local_58 + 1;
            if (local_58 == local_54) {
              iVar4 = iVar4 + 1;
              iVar17 = iVar4 * 4;
              local_60 = local_60 + 1;
              uVar9 = ParseOperand__GetLogicalSize(param_3[iVar4]);
              iVar5 = ParseOperand__IsMatrix(param_3[iVar4]);
              if ((iVar5 == 0) || (local_54 = uVar9, *(int *)(param_3[iVar4] + 0x20) != 0)) {
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
            iVar5 = uVar9 - in_r8;
            if (iVar3 - iVar16 < (int)(uVar9 - in_r8)) {
              iVar5 = iVar3 - iVar16;
            }
            if ((int)in_r8 < (int)(in_r8 + iVar5)) {
              iVar5 = (in_r8 + iVar5) - in_r8;
              param_4 = 0x8b56;
              in_r7 = (undefined4 *)(puVar11 + 0xc0);
              do {
                iVar14 = **(int **)(iVar17 + (int)param_3);
                if (iVar14 == 0) {
                  uVar7 = *(ushort *)(*(int **)(iVar17 + (int)param_3) + 6);
                }
                else {
                  uVar7 = *(ushort *)(iVar14 + 0x2c);
                }
                if (uVar7 == 0x1406) {
                  local_80[uVar10] =
                       *(undefined4 *)(in_r8 * 4 + *(int *)(*(int *)(iVar17 + (int)param_3) + 4));
                }
                else if (uVar7 < 0x1407) {
                  if (uVar7 == 0x1404) {
                    in_r10 = in_r8 * 4;
                    local_80[uVar10] =
                         *(undefined4 *)(in_r10 + *(int *)(*(int *)(iVar17 + (int)param_3) + 4));
                  }
                }
                else if (uVar7 == 0x8b56) {
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
                iVar5 = iVar5 + -1;
              } while (iVar5 != 0);
              bVar1 = iVar16 == iVar3;
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
            ((int (*)())TPPStreamCompiler__getOperandAsDestVar)((unsigned char *)&local_70,this,*param_2,param_4,in_r7,uVar6);
            local_f8 = local_70 & 0xfffe1c2f | 0x6c;
            local_f4 = local_6c;
            ((int (*)())TPPStreamCompiler__getOperandAsSourceVar)((unsigned char *)&local_70,this,*(undefined4 *)(iVar17 + (int)param_3),param_4
                       ,in_r7,uVar6,uVar8,in_r10);
            local_f0 = local_70;
            local_ec = local_6c;
            iVar5 = uVar9 - in_r8;
            if (iVar3 - iVar16 < (int)(uVar9 - in_r8)) {
              iVar5 = iVar3 - iVar16;
            }
            if (0 < iVar5) {
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
                iVar5 = iVar5 + -1;
              } while (iVar5 != 0);
              bVar1 = iVar16 == iVar3;
              uVar12 = in_r8;
            }
            in_r8 = uVar6;
            if (((1 < iVar13) || (*(int *)(this + 0xc4) < 2)) ||
               (iVar17 = ((int (*)())TPPStreamCompiler__copyPropagateCompilerTemp)(this,(unsigned char *)&local_100,
                                    *(unsigned char **)(iVar17 + (int)param_3)), in_r8 = uVar6,
               iVar17 == 0)) {
              local_fc = (local_f8 >> 0xc & 1) << 0x1c | local_fc & 0xefffffff;
              iVar17 = *(int *)*param_2;
              if (iVar17 == 0) {
                uVar7 = *(ushort *)(*param_2 + 0x18);
              }
              else {
                uVar7 = *(ushort *)(iVar17 + 0x2c);
              }
              uVar6 = GetPPStreamTypeForGLType(uVar7);
              local_fc = (iVar14 + -1) * 0x4000000 & 0xc000000U |
                         (uVar6 & 7) << 0x17 | local_fc & 0xf073ffff;
              param_4 = 0;
              in_r7 = (undefined4 *)0x0;
              ((int (*)())TPPStreamCompiler__AddOperation)(this,param_2,(unsigned char *)&local_100,(char *)0x0,0);
            }
          }
          uVar6 = in_r8;
        } while (!bVar1);
      }
      if (uVar10 != 0) {
        iVar17 = *(int *)param_3[iVar4];
        if (iVar17 == 0) {
          uVar7 = *(ushort *)(param_3[iVar4] + 0x18);
        }
        else {
          uVar7 = *(ushort *)(iVar17 + 0x2c);
        }
        ((int (*)())TPPStreamCompiler__getConstantAsSourceVar)((unsigned char *)&local_70,(uint)this,(short)&STACKARG(0xfffffec0) + 0xc0,uVar10,
                   (uint)uVar7);
        local_bc = (local_b8 >> 0xc & 1) << 0x1c | local_bc & 0xefffffff;
        local_b0 = local_70;
        local_ac = local_6c;
        iVar17 = *(int *)*param_2;
        if (iVar17 == 0) {
          uVar7 = *(ushort *)(*param_2 + 0x18);
        }
        else {
          uVar7 = *(ushort *)(iVar17 + 0x2c);
        }
        uVar6 = GetPPStreamTypeForGLType(uVar7);
        local_bc = (uVar10 - 1) * 0x4000000 & 0xc000000 |
                   (uVar6 & 7) << 0x17 | local_bc & 0xf073ffff;
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
  size_t sVar4;
  size_t sVar5;
  char *pcVar6;
  unsigned char * pPVar7;
  unsigned char ** ppPVar8;
  int iVar9;
  char *pcVar10;
  unsigned char * this_00;
  unsigned char * pPVar11;
  uint uVar12;
  uint uVar13;
  int iVar14;
  int iVar15;
  uint uVar16;
  uint uVar17;
  void *this_01;
  char *pcVar18;
  char acStack_70 [16];
  unsigned char * local_60;
  unsigned char * local_5c;
  char *local_58;
  int local_54;
  
  pPVar11 = *param_2;
  iVar14 = 0;
  iVar15 = 0;
  if (pPVar11 != (unsigned char *)0x0) {
    iVar3 = *(int *)pPVar11;
    sVar2 = *(short *)(iVar3 + 0x2c);
    iVar15 = iVar14;
    if (sVar2 == 0x7ffe) {
      local_58 = *(char **)(iVar3 + 0x14);
      iVar14 = *(int *)(*(int *)(iVar3 + 0xc) + 8);
      if (iVar14 != 0) {
        uVar13 = 0;
        iVar3 = *(int *)(iVar14 + 4);
        uVar12 = *(int *)(iVar14 + 8) - iVar3 >> 3;
        if (uVar12 != 0) {
          bVar1 = local_58 == (char *)0x0;
          local_54 = -0x58488c94;
          while( true ) {
            iVar3 = (**(code **)(**(int **)(iVar3 + uVar13 * 8) + 0x1c))();
            *(undefined1 *)(*(int *)(iVar3 + 4) + *(int *)(*(int *)(iVar3 + 4) + -0xc)) =
                 **(undefined1 **)(local_54 + 0x4a30);
            pcVar18 = *(char **)(iVar3 + 4);
            sVar4 = _strlen(pcVar18);
            sVar4 = sVar4 + 1;
            if (!bVar1) {
              sVar5 = _strlen(local_58);
              sVar4 = sVar4 + sVar5 + 1;
            }
            pcVar6 = _malloc(sVar4);
            if (bVar1) {
              _strcpy(pcVar6,pcVar18);
            }
            else {
              _sprintf(pcVar6,DAT_a7b7bd8c,local_58,pcVar18);
            }
            pPVar11 = operator_new(0x38);
            __ZN12ParseOperandC1Ev(pPVar11);
            local_60 = pPVar11;
            pPVar7 = operator_new(100);
            __ZN11ParseSymbolC1Ev(pPVar7);
            ParseSymbol__SetName(pPVar7,pcVar6);
            _free(pcVar6);
            ParseSymbol__SetParseTreeType(pPVar7,*(unsigned char **)(*(int *)(iVar14 + 4) + uVar13 * 8));
            *(unsigned char **)local_60 = pPVar7;
            if ((*(short *)(pPVar7 + 0x2c) == 0x7ffe) || (*(short *)(pPVar7 + 0x2c) == 0x7fff)) {
              iVar3 = *(int *)param_3[iVar15];
              if (*(short *)(iVar3 + 0x2c) == 0x7ffe) {
                pcVar18 = *(char **)(iVar3 + 0x14);
                iVar3 = *(int *)(*(int *)(iVar3 + 0xc) + 8);
                if (iVar3 != 0) {
                  uVar17 = 0;
                  uVar16 = *(int *)(iVar3 + 8) - *(int *)(iVar3 + 4) >> 3;
                  ppPVar8 = _malloc(uVar12 << 2);
                  if (uVar16 != 0) {
                    do {
                      iVar9 = (**(code **)(**(int **)(*(int *)(iVar3 + 4) + uVar17 * 8) + 0x1c))();
                      *(undefined1 *)(*(int *)(iVar9 + 4) + *(int *)(*(int *)(iVar9 + 4) + -0xc)) =
                           *DAT_a7b7bd9c;
                      pcVar6 = *(char **)(iVar9 + 4);
                      sVar4 = _strlen(pcVar6);
                      sVar4 = sVar4 + 1;
                      if (pcVar18 != (char *)0x0) {
                        sVar5 = _strlen(pcVar18);
                        sVar4 = sVar4 + sVar5 + 1;
                      }
                      pcVar10 = _malloc(sVar4);
                      if (pcVar18 == (char *)0x0) {
                        _strcpy(pcVar10,pcVar6);
                      }
                      else {
                        _sprintf(pcVar10,DAT_a7b7bd8c,pcVar18,pcVar6);
                      }
                      pPVar11 = operator_new(0x38);
                      __ZN12ParseOperandC1Ev(pPVar11);
                      ppPVar8[uVar17] = pPVar11;
                      this_00 = operator_new(100);
                      __ZN11ParseSymbolC1Ev(this_00);
                      ParseSymbol__SetName(this_00,pcVar10);
                      _free(pcVar10);
                      ParseSymbol__SetParseTreeType
                                (this_00,*(unsigned char **)(*(int *)(iVar3 + 4) + uVar17 * 8));
                      *(unsigned char **)ppPVar8[uVar17] = this_00;
                      if ((*(short *)(this_00 + 0x2c) != 0x7ffe) &&
                         (*(short *)(this_00 + 0x2c) != 0x7fff)) {
                        ParseSymbolTable__processOperand
                                  (*(unsigned char **)(this + 0x68),ppPVar8[uVar17]);
                      }
                      uVar17 = uVar17 + 1;
                    } while (uVar17 < uVar16);
                  }
                  uVar17 = 0;
                  ((int (*)())TPPStreamCompiler__constructFromOperand)(this,&local_60,ppPVar8,uVar16);
                  iVar15 = iVar15 + 1;
                  if (uVar16 != 0) {
                    do {
                      this_01 = *(void **)ppPVar8[uVar17];
                      if (((*(short *)((int)this_01 + 0x2c) == 0x7ffe) ||
                          (*(short *)((int)this_01 + 0x2c) == 0x7fff)) && (this_01 != (void *)0x0))
                      {
                        __ZN11ParseSymbolD1Ev(this_01);
                        __ZdlPv(this_01);
                      }
                      pPVar11 = ppPVar8[uVar17];
                      if (pPVar11 != (unsigned char *)0x0) {
                        __ZN12ParseOperandD1Ev(pPVar11);
                        __ZdlPv(pPVar11);
                      }
                      uVar17 = uVar17 + 1;
                    } while (uVar17 < uVar16);
                  }
                  _free(ppPVar8);
                }
              }
              else {
                iVar3 = ((int (*)())TPPStreamCompiler__constructFromOperand)(this,&local_60,param_3 + iVar15,param_4 - iVar15);
                iVar15 = iVar15 + iVar3;
              }
              if (pPVar7 != (unsigned char *)0x0) {
                __ZN11ParseSymbolD1Ev(pPVar7);
                __ZdlPv(pPVar7);
              }
              *(undefined4 *)local_60 = 0;
            }
            else {
              ParseSymbolTable__processOperand(*(unsigned char **)(this + 0x68),local_60);
              iVar3 = ((int (*)())TPPStreamCompiler__constructFromOperand)(this,&local_60,param_3 + iVar15,param_4 - iVar15);
              iVar15 = iVar15 + iVar3;
            }
            pPVar11 = local_60;
            if (local_60 != (unsigned char *)0x0) {
              __ZN12ParseOperandD1Ev(local_60);
              __ZdlPv(pPVar11);
            }
            uVar13 = uVar13 + 1;
            if (uVar12 <= uVar13) break;
            iVar3 = *(int *)(iVar14 + 4);
          }
        }
      }
    }
    else if (sVar2 == 0x7fff) {
      uVar12 = 0;
      if (0 < *(short *)(iVar3 + 0x2e)) {
        do {
          pPVar11 = operator_new(0x38);
          __ZN12ParseOperandC1Ev(pPVar11);
          local_5c = pPVar11;
          pPVar7 = operator_new(100);
          __ZN11ParseSymbolC1Ev(pPVar7);
          ParseSymbol__SetName(pPVar7,*(char **)(*(int *)*param_2 + 0x14));
          ParseSymbol__AddDirectIndex(pPVar7,uVar12);
          _sprintf(acStack_70,DAT_a7b7bd90,uVar12);
          ParseSymbol__CatName(pPVar7,acStack_70);
          ParseSymbol__SetParseTreeType(pPVar7,*(unsigned char **)(*(int *)*param_2 + 0xc));
          *(undefined4 *)(pPVar7 + 0x48) = 1;
          ParseSymbol__ResolveOpenGLType(pPVar7);
          *(unsigned char **)local_5c = pPVar7;
          if ((*(short *)(pPVar7 + 0x2c) == 0x7ffe) || (*(short *)(pPVar7 + 0x2c) == 0x7fff)) {
            iVar15 = ((int (*)())TPPStreamCompiler__constructFromOperand)(this,&local_5c,param_3 + iVar14,param_4 - iVar14);
            if (pPVar7 != (unsigned char *)0x0) {
              __ZN11ParseSymbolD1Ev(pPVar7);
              __ZdlPv(pPVar7);
            }
            *(undefined4 *)local_5c = 0;
          }
          else {
            ParseSymbolTable__processOperand(*(unsigned char **)(this + 0x68),local_5c);
            iVar15 = ((int (*)())TPPStreamCompiler__constructFromOperand)(this,&local_5c,param_3 + iVar14,param_4 - iVar14);
          }
          pPVar11 = local_5c;
          iVar15 = iVar14 + iVar15;
          if (local_5c != (unsigned char *)0x0) {
            __ZN12ParseOperandD1Ev(local_5c);
            __ZdlPv(pPVar11);
          }
          uVar12 = uVar12 + 1;
          iVar14 = iVar15;
        } while ((int)uVar12 < (int)*(short *)(*(int *)*param_2 + 0x2e));
      }
    }
    else {
      if (iVar3 == 0) {
        sVar2 = *(short *)(pPVar11 + 0x18);
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
        if ((param_4 == 1) && (iVar15 = ParseOperand__GetLogicalSize(*param_3), iVar15 == 1)) {
          iVar15 = ((int (*)())TPPStreamCompiler__constructReplicate)((unsigned char **)this,param_2,(int)param_3);
          return iVar15;
        }
        break;
      case -0x74a6:
      case -0x74a5:
      case -0x74a4:
        if ((param_4 == 1) && (iVar15 = ParseOperand__GetLogicalSize(*param_3), iVar15 == 1)) {
          iVar15 = ((int (*)())TPPStreamCompiler__constructDiagonal)((unsigned char **)this,param_2,(int)param_3);
          return iVar15;
        }
      }
      iVar15 = ((int (*)())TPPStreamCompiler__constructElement)(this,param_2,param_3,param_4);
    }
  }
  return iVar15;
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
        pPVar4 = local_30;
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
  uint uVar1;
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
  ushort uVar2;
  
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
      uVar2 = *(ushort *)(*(int **)(this + 0x88) + 6);
    }
    else {
      uVar2 = *(ushort *)(iVar4 + 0x2c);
    }
    uVar1 = GetPPStreamTypeForGLType(uVar2);
    local_6c = (uVar1 & 7) << 0x17 | local_6c & 0xfc7fffff;
    iVar4 = ParseOperand__GetLogicalSize(*(unsigned char **)(this + 0x88));
    local_6c = (iVar4 + -1) * 0x4000000 & 0xc000000U | local_6c & 0xf3f3ffff;
    _PPStreamAddOperation(*(undefined4 *)(this + 0x70),&local_70,0,0);
    pPVar6 = *param_2;
    if (pPVar6 != (unsigned char *)0x0) {
      __ZN12ParseOperandD1Ev(pPVar6);
      __ZdlPv(pPVar6);
    }
    pPVar6 = local_20;
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
  bool bVar1;
  unsigned char * pPVar2;
  unsigned char ** ppPVar3;
  unsigned char * pTVar4;
  uint uVar5;
  int iVar6;
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
  ushort uVar7;
  
  pPVar2 = *param_2;
  if ((pPVar2 != (unsigned char *)0x0) && (*(int *)(pPVar2 + 0xc) != 0)) {
    *(unsigned char **)((int)this + 0x88) = pPVar2;
    pTVar4 = (unsigned char *)((int (*)())TPPStreamCompiler__newNodeFromOperand)(this,*param_2);
    pPVar2 = (unsigned char *)((int (*)())TPPStreamCompiler__newTemporary)(this,pTVar4);
    *param_2 = pPVar2;
  }
  iVar10 = 1;
  if (1 < param_3) {
    do {
      pPVar2 = *(unsigned char **)(param_2[iVar10] + 0xc);
      if (pPVar2 != (unsigned char *)0x0) {
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
        local_4c = pPVar2;
        pTVar4 = (unsigned char *)((int (*)())TPPStreamCompiler__newNodeFromOperand)(this,param_2[iVar10]);
        local_50 = (unsigned char *)((int (*)())TPPStreamCompiler__newTemporary)(this,pTVar4);
        ppPVar3 = &local_4c;
        ((int (*)())__ZN17TPPStreamCompiler22IndirectAddressHandlerEPP12ParseOperandS2_S2_)(this,&local_50,param_2 + iVar10,ppPVar3);
        local_a0 = local_a0 & 0xfc03ffff | 0xe40000;
        ((int (*)())TPPStreamCompiler__getOperandAsDestVar)((unsigned char *)&local_60,this,local_50,ppPVar3,in_r7,in_r8);
        local_98 = local_60;
        local_94 = local_5c;
        ParseOperand__RemoveDirectIndex(param_2[iVar10]);
        ((int (*)())TPPStreamCompiler__getOperandAsSourceVar)((unsigned char *)&local_60,this,param_2[iVar10],ppPVar3,in_r7,in_r8,uVar8,in_r10);
        local_90 = local_60;
        local_8c = local_5c;
        ((int (*)())TPPStreamCompiler__getOperandAsSourceVar)((unsigned char *)&local_60,this,local_4c,ppPVar3,in_r7,in_r8,uVar8,in_r10);
        local_9c = (local_98 >> 0xc & 1) << 0x1c | local_9c & 0xefffffff;
        local_88 = local_60;
        local_84 = local_5c;
        if (*(int *)local_50 == 0) {
          uVar7 = *(ushort *)(local_50 + 0x18);
        }
        else {
          uVar7 = *(ushort *)(*(int *)local_50 + 0x2c);
        }
        uVar5 = GetPPStreamTypeForGLType(uVar7);
        local_9c = (uVar5 & 7) << 0x17 | local_9c & 0xfc7fffff;
        iVar6 = ParseOperand__GetLogicalSize(local_50);
        local_9c = (iVar6 + -1) * 0x4000000 & 0xc000000U | local_9c & 0xf3f3ffff;
        _PPStreamAddOperation(*(undefined4 *)((int)this + 0x70),&local_a0,0,0);
        iVar6 = 0;
        ppPVar3 = param_2;
        if (0 < param_3) {
          do {
            if ((iVar6 != iVar10) && (param_2[iVar10] == *ppPVar3)) {
              *(unsigned char **)(param_2[iVar10] + 0xc) = local_4c;
              goto LAB_97bc7fe0;
            }
            iVar6 = iVar6 + 1;
            ppPVar3 = ppPVar3 + 1;
          } while (iVar6 < param_3);
        }
        pPVar2 = param_2[iVar10];
        if (pPVar2 != (unsigned char *)0x0) {
          __ZN12ParseOperandD1Ev(pPVar2);
          __ZdlPv(pPVar2);
        }
        pPVar2 = local_4c;
        if (local_4c != (unsigned char *)0x0) {
          __ZN12ParseOperandD1Ev(local_4c);
          __ZdlPv(pPVar2);
        }
LAB_97bc7fe0:
        param_2[iVar10] = local_50;
      }
      iVar10 = iVar10 + 1;
    } while (iVar10 < param_3);
  }
  ppPVar3 = param_2;
  iVar10 = param_3;
  iVar6 = 0;
  if (0 < param_3) {
    do {
      iVar10 = iVar6;
      if ((*ppPVar3 != (unsigned char *)0x0) && (*(int *)(*ppPVar3 + 8) != 0)) break;
      iVar6 = iVar10 + 1;
      ppPVar3 = ppPVar3 + 1;
      iVar10 = param_3;
    } while (iVar6 < param_3);
  }
  iVar10 = iVar10 + *(int *)((int)this + 0x9c);
  do {
    if (param_3 <= iVar10) {
      return;
    }
    if (*(int *)(param_2[iVar10] + 8) != 0) {
      pTVar4 = (unsigned char *)((int (*)())TPPStreamCompiler__newNodeFromOperand)(this,param_2[iVar10]);
      local_48[0] = (unsigned char *)((int (*)())TPPStreamCompiler__newTemporary)(this,pTVar4);
      bVar1 = false;
      ((int (*)())TPPStreamCompiler__assignOperands)(this,local_48,param_2 + iVar10,false);
      iVar9 = 0;
      ppPVar3 = param_2;
      iVar6 = param_3;
      if (param_3 < 1) {
LAB_97bc80d0:
        pPVar2 = param_2[iVar10];
        if (pPVar2 != (unsigned char *)0x0) {
          __ZN12ParseOperandD1Ev(pPVar2);
          __ZdlPv(pPVar2);
        }
      }
      else {
        do {
          if ((iVar9 != iVar10) && (param_2[iVar10] == *ppPVar3)) {
            bVar1 = true;
          }
          iVar9 = iVar9 + 1;
          iVar6 = iVar6 + -1;
          ppPVar3 = ppPVar3 + 1;
        } while (iVar6 != 0);
        if (!bVar1) goto LAB_97bc80d0;
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
  undefined2 in_register_00000014;
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
  uVar5 = GetPPStreamTypeForGLType((*(unsigned short *)((unsigned char *)&(param_5) + 2)));
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
        uVar1 = *(undefined4 *)(CONCAT22(in_register_00000014,param_3) + iVar9 * 4);
        *puVar7 = 1;
        puVar7 = puVar7 + 1;
        local_60[iVar9] = uVar1;
        param_4 = param_4 + -1;
        iVar9 = iVar9 + 1;
      } while (param_4 != 0);
    }
    ConstantAllocationList__addConstant
              ((unsigned char *)(param_2 + 0x44),uVar4 & 0xffff,(bool *)local_40,
               (*(unsigned short *)((unsigned char *)&(param_5) + 2)));
  }
  else {
    iVar9 = 0;
    for (; param_4 != 0; param_4 = param_4 + -1) {
      local_60[iVar9] = *(undefined4 *)(CONCAT22(in_register_00000014,param_3) + iVar9 * 4);
      iVar9 = iVar9 + 1;
    }
  }
  _PPStreamAddConstant(*(undefined4 *)(param_2 + 0x70),local_60);
  puVar6 = _calloc(0x1c,1);
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
  int param_3;
  uint param_4;
  uint param_5;
{
  bool bVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  undefined2 in_register_00000014;
  float *pfVar5;
  undefined4 uVar6;
  int *piVar7;
  int iVar8;
  uint local_80;
  undefined4 local_7c;
  int local_70 [4];
  ushort local_60 [8];
  int local_50 [5];
  
  pfVar5 = (float *)CONCAT22(in_register_00000014,param_3);
  if (*(int *)(param_2 + 0xc4) != 1) {
    bVar1 = false;
    local_70[1] = DAT_97c39254;
    local_70[0] = DAT_97c39250;
    local_70[2] = DAT_97c39258;
    local_70[3] = DAT_97c3925c;
    piVar7 = *(int **)(*(int *)(param_2 + 0x70) + 0x10);
    uVar6 = *(undefined4 *)(*(int *)(param_2 + 0x70) + 0x2c);
    iVar8 = *piVar7;
    *(undefined4 *)param_1 = 0;
    *(undefined4 *)(param_1 + 4) = 0;
    *(uint *)param_1 = (param_4 - 1) * 0x1000 & 0x3000 | *(uint *)param_1 & 0xfc09cfff | 0x10d8000;
    if (iVar8 != 0) {
      do {
        local_80 = *(uint *)(iVar8 + 0xc);
        local_7c = *(uint *)(iVar8 + 0x10);
        if ((local_80 & 0x1f0000) == 0x110000) {
          iVar4 = _PPStreamChunkListChunkAtIndex(uVar6,local_80 & 0xffff);
          if (*(int *)(param_2 + 0xc4) == 3) {
            ConstantAllocationList__getConstantUsage
                      ((unsigned char *)(param_2 + 0x44),local_7c & 0xffff,(bool *)local_70
                       ,local_60);
          }
          if (local_60[0] == param_5) {
            if (param_4 == 2) {
LAB_97bc86b4:
              if ((local_70[1] != 0) && (pfVar5[1] == *(float *)(iVar4 + 0x10))) {
LAB_97bc86d0:
                if ((local_70[0] != 0) && (*pfVar5 == *(float *)(iVar4 + 0xc))) goto LAB_97bc86ec;
              }
            }
            else {
              if (2 < param_4) {
                if (param_4 != 3) {
                  if (param_4 != 4) goto LAB_97bc86ec;
                  if ((local_70[3] == 0) || (pfVar5[3] != *(float *)(iVar4 + 0x18)))
                  goto LAB_97bc86f8;
                }
                if ((local_70[2] == 0) || (pfVar5[2] != *(float *)(iVar4 + 0x14)))
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
        iVar8 = *(int *)(iVar8 + 8);
        if (iVar8 == 0) {
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
      iVar8 = *piVar7;
      if (iVar8 != 0) {
        do {
          local_50[0] = 0;
          local_50[1] = 0;
          local_50[2] = 0;
          local_50[3] = 0;
          local_80 = *(uint *)(iVar8 + 0xc);
          local_7c = *(uint *)(iVar8 + 0x10);
          if ((local_80 & 0x1f0000) == 0x110000) {
            iVar4 = _PPStreamChunkListChunkAtIndex(uVar6,local_80 & 0xffff);
            if (*(int *)(param_2 + 0xc4) == 3) {
              ConstantAllocationList__getConstantUsage
                        ((unsigned char *)(param_2 + 0x44),local_7c & 0xffff,
                         (bool *)local_70,local_60);
            }
            if (local_60[0] == param_5) {
              bVar2 = true;
              if (param_4 == 2) {
LAB_97bc8838:
                if ((local_70[1] == 1) && (pfVar5[1] == *(float *)(iVar4 + 0x10))) {
                  local_50[1] = local_70[1];
                }
                else if (local_70[1] != 0) {
                  bVar2 = false;
                }
LAB_97bc8868:
                if ((local_70[0] == 1) && (*pfVar5 == *(float *)(iVar4 + 0xc))) {
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
                    if ((local_70[3] == 1) && (pfVar5[3] == *(float *)(iVar4 + 0x18))) {
                      local_50[3] = 1;
                    }
                    else if (local_70[3] != 0) {
                      bVar2 = false;
                    }
                  }
                  if ((local_70[2] == 1) && (pfVar5[2] == *(float *)(iVar4 + 0x14))) {
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
                    ((float *)(iVar4 + 0xc))[uVar3] = pfVar5[uVar3];
                    local_50[uVar3] = 1;
                    local_70[uVar3] = 1;
                  }
                  uVar3 = uVar3 + 1;
                } while (uVar3 < param_4);
              }
              if (param_4 != 0) {
                piVar7 = local_50;
                uVar3 = param_4;
                do {
                  iVar4 = *piVar7;
                  piVar7 = piVar7 + 1;
                  if (iVar4 == 0) {
                    bVar2 = false;
                  }
                  uVar3 = uVar3 - 1;
                } while (uVar3 != 0);
              }
              if (bVar2) {
                *(undefined2 *)(param_1 + 6) = (*(unsigned short *)((unsigned char *)&(local_7c) + 2));
                *(uint *)(iVar8 + 0xc) =
                     (local_70[0] + local_70[1] + local_70[2] + local_70[3] + -1) * 0x1000000 &
                     0x3000000U | *(uint *)(iVar8 + 0xc) & 0xfcffffff;
                bVar1 = false;
                ConstantAllocationList__updateConstant
                          ((unsigned char *)(param_2 + 0x44),local_7c & 0xffff,
                           (bool *)local_70,(ushort)param_5);
              }
            }
          }
LAB_97bc897c:
          iVar8 = *(int *)(iVar8 + 8);
          if (iVar8 == 0) goto LAB_97bc8990;
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
  ParseOperand__GetAsDestVar(SUB41(param_1,0),param_3,uVar1);
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
      error(SUB41(param_2,0),(char *)0x1,(char *)0x0,_compileErrorString,param_5,param_6,param_7,
            param_8);
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
        error(SUB41(param_2,0),(char *)0x1,(char *)0x0,DAT_a7b7bd14,param_5,param_6,uVar5,param_8);
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
    ((int (*)())TPPStreamCompiler__getConstantAsSourceVar)((unsigned char *)&local_40,(uint)param_2,(short)&STACKARG(0xffffff70) + 0x40,uVar5,(uint)uVar2
              );
  }
  else {
    uVar5 = ((int (*)())TPPStreamCompiler__generateAddressLoad)(param_2,param_3);
    ParseOperand__GetAsSourceVar((bool)((char)&STACKARG(0xffffff70) + '@'),param_3,uVar5);
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
              (*(unsigned char **)(this + 0x60),*(ushort *)(this_00 + 0xb),this_00[10]);
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
      TPPStreamCompiler__warning(SUB41(this,0),(char *)0x0,(char *)0x0,DAT_a7b7bd40,in_r7,uVar19,uVar13,puVar20);
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
    (**(code **)(*(int *)param_2 + 0x10))(param_2,this);
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
  int *this;
  int param_2;
  int param_3;
{
  int iVar1;
  undefined *puVar2;
  int *piVar3;
  char in_RESERVE;
  byte in_cr0;
  
  this[2] = param_2;
  *this = (int)&PTR___ZN9TCompilerD1Ev_a7b7d850;
  this[1] = (int)(this + 0x2c);
  this[3] = 0;
  __ZN14TPoolAllocatorC1Ebii(this + 4,false,0x2000,0x10);
  *this = DAT_a7b7bd98 + 8;
  __ZN22ConstantAllocationListC1Ev(this + 0x11);
  ((int (*)())__ZN18ParseFunctionStackC1Ev)(this + 0x16);
  ((int (*)())__ZN19ParseWhileLoopStackC1Ev)(this + 0x17);
  puVar2 = PTR__S_empty_rep_storage_a7b7c0f0;
  piVar3 = (int *)(PTR__S_empty_rep_storage_a7b7c0f0 + 8);
  do {
    if (in_RESERVE != '\0') {
      iVar1 = storeWordConditionalIndexed(*piVar3 + 1,0,piVar3);
      *piVar3 = iVar1;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  this[0x2d] = 4;
  this[0x2c] = (int)(puVar2 + 0xc);
  do {
    if (in_RESERVE != '\0') {
      iVar1 = storeWordConditionalIndexed(*piVar3 + 1,0,piVar3);
      *piVar3 = iVar1;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  this[0x2f] = 4;
  this[0x2e] = (int)(puVar2 + 0xc);
  this[0x30] = param_3;
  newQueue((unsigned char *)(this + 0x13));
  this[0x22] = 0;
  this[0x27] = 1;
  this[0x1a] = 0;
  this[0x1b] = 0;
  this[0x1d] = 0;
  this[0x1c] = 0;
  this[0x1f] = 0;
  this[0x20] = 0;
  this[0x1e] = 0;
  this[0x21] = 0;
  this[0x18] = 0;
  this[0x19] = 0;
  return;
}

/* __ZN17TPPStreamCompilerC1E11EShLanguagei @ 0x97bc96b4 (4 bytes) */
int __ZN17TPPStreamCompilerC1E11EShLanguagei(this, param_2, param_3)
  int *this;
  int param_2;
  int param_3;
{
  int iVar1;
  undefined *puVar2;
  int *piVar3;
  char in_RESERVE;
  byte in_cr0;
  
  this[2] = param_2;
  *this = (int)&PTR___ZN9TCompilerD1Ev_a7b7d850;
  this[1] = (int)(this + 0x2c);
  this[3] = 0;
  __ZN14TPoolAllocatorC1Ebii(this + 4,false,0x2000,0x10);
  *this = DAT_a7b7bd98 + 8;
  __ZN22ConstantAllocationListC1Ev(this + 0x11);
  ((int (*)())__ZN18ParseFunctionStackC1Ev)(this + 0x16);
  ((int (*)())__ZN19ParseWhileLoopStackC1Ev)(this + 0x17);
  puVar2 = PTR__S_empty_rep_storage_a7b7c0f0;
  piVar3 = (int *)(PTR__S_empty_rep_storage_a7b7c0f0 + 8);
  do {
    if (in_RESERVE != '\0') {
      iVar1 = storeWordConditionalIndexed(*piVar3 + 1,0,piVar3);
      *piVar3 = iVar1;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  this[0x2d] = 4;
  this[0x2c] = (int)(puVar2 + 0xc);
  do {
    if (in_RESERVE != '\0') {
      iVar1 = storeWordConditionalIndexed(*piVar3 + 1,0,piVar3);
      *piVar3 = iVar1;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  this[0x2f] = 4;
  this[0x2e] = (int)(puVar2 + 0xc);
  this[0x30] = param_3;
  newQueue((unsigned char *)(this + 0x13));
  this[0x22] = 0;
  this[0x27] = 1;
  this[0x1a] = 0;
  this[0x1b] = 0;
  this[0x1d] = 0;
  this[0x1c] = 0;
  this[0x1f] = 0;
  this[0x20] = 0;
  this[0x1e] = 0;
  this[0x21] = 0;
  this[0x18] = 0;
  this[0x19] = 0;
  return;
}

/* __ZN17TPPStreamCompilerC4E11EShLanguagei @ 0x97bc96b8 (284 bytes) */
int __ZN17TPPStreamCompilerC4E11EShLanguagei(this, param_2, param_3)
  int *this;
  int param_2;
  int param_3;
{
  int iVar1;
  undefined *puVar2;
  int *piVar3;
  char in_RESERVE;
  byte in_cr0;
  
  this[2] = param_2;
  *this = (int)&PTR___ZN9TCompilerD1Ev_a7b7d850;
  this[1] = (int)(this + 0x2c);
  this[3] = 0;
  __ZN14TPoolAllocatorC1Ebii(this + 4,false,0x2000,0x10);
  *this = DAT_a7b7bd98 + 8;
  __ZN22ConstantAllocationListC1Ev(this + 0x11);
  ((int (*)())__ZN18ParseFunctionStackC1Ev)(this + 0x16);
  ((int (*)())__ZN19ParseWhileLoopStackC1Ev)(this + 0x17);
  puVar2 = PTR__S_empty_rep_storage_a7b7c0f0;
  piVar3 = (int *)(PTR__S_empty_rep_storage_a7b7c0f0 + 8);
  do {
    if (in_RESERVE != '\0') {
      iVar1 = storeWordConditionalIndexed(*piVar3 + 1,0,piVar3);
      *piVar3 = iVar1;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  this[0x2d] = 4;
  this[0x2c] = (int)(puVar2 + 0xc);
  do {
    if (in_RESERVE != '\0') {
      iVar1 = storeWordConditionalIndexed(*piVar3 + 1,0,piVar3);
      *piVar3 = iVar1;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  this[0x2f] = 4;
  this[0x2e] = (int)(puVar2 + 0xc);
  this[0x30] = param_3;
  newQueue((unsigned char *)(this + 0x13));
  this[0x22] = 0;
  this[0x27] = 1;
  this[0x1a] = 0;
  this[0x1b] = 0;
  this[0x1d] = 0;
  this[0x1c] = 0;
  this[0x1f] = 0;
  this[0x20] = 0;
  this[0x1e] = 0;
  this[0x21] = 0;
  this[0x18] = 0;
  this[0x19] = 0;
  return;
}

/* __ZN17TPPStreamCompilerD2Ev @ 0x97bc97d4 (8 bytes) */
int __ZN17TPPStreamCompilerD2Ev(this)
  void *this;
{
  __ZN17TPPStreamCompilerD4Ev(this);
  return;
}

