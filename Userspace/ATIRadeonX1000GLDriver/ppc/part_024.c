#include "decls.h"

/* ContinueBlock__clone @ 0xebff8 (64 bytes) */
int ContinueBlock__clone(this)
  int this;
{
  undefined4 *allocation;
  undefined4 arena;
  
  arena = *(undefined4 *)(*(int *)(this + 0xa8) + 0x374);
  allocation = (undefined4 *)Arena__alloc(arena,0x138);
  *allocation = arena;
  ContinueBlock__ctor_ebfb4(allocation + 1,this);
  return allocation + 1;
}

/* BreakBlock__ctor_ec070 @ 0xec070 (88 bytes) */
int BreakBlock__ctor_ec070(this, param_2, param_3, compiler)
  undefined4 *this;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 compiler;
{
  Block__ctor_ea148(this,compiler);
  this[0x4b] = param_2;
  this[0x4c] = param_3;
  *this = &PTR_FUN_001e9e20;
  return;
}

/* BreakBlock__ctor_ec0c8 @ 0xec0c8 (88 bytes) */
int BreakBlock__ctor_ec0c8(this, param_2, param_3, compiler)
  undefined4 *this;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 compiler;
{
  Block__ctor_ea148(this,compiler);
  this[0x4b] = param_2;
  this[0x4c] = param_3;
  *this = &PTR_FUN_001e9e20;
  return;
}

/* ContinueBlock__ctor_ec120 @ 0xec120 (88 bytes) */
int ContinueBlock__ctor_ec120(this, param_2, param_3, compiler)
  undefined4 *this;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 compiler;
{
  Block__ctor_ea148(this,compiler);
  this[0x4b] = param_2;
  this[0x4c] = param_3;
  *this = &PTR_FUN_001e9e78;
  return;
}

/* ContinueBlock__ctor_ec178 @ 0xec178 (88 bytes) */
int ContinueBlock__ctor_ec178(this, param_2, param_3, compiler)
  undefined4 *this;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 compiler;
{
  Block__ctor_ea148(this,compiler);
  this[0x4b] = param_2;
  this[0x4c] = param_3;
  *this = &PTR_FUN_001e9e78;
  return;
}

/* FUN_000ec1d0 @ 0xec1d0 (20 bytes) */
int FUN_000ec1d0(param_1)
  int param_1;
{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = *(undefined4 *)(param_1 + 0x3ac);
  iVar2 = FUN_00127534(uVar1,0x13,0,0);
  if (iVar2 == 0) {
    FUN_001275a0(uVar1,0x13,0,0);
    return;
  }
  return;
}

/* callTargetSlot25 @ 0xec1ec (28 bytes) */
int callTargetSlot25(param_1)
  int param_1;
{
  int *piVar1;
  
  piVar1 = *(int **)(*(int *)(param_1 + 8) + 0x30c);
                    
                    
  (**(code **)(*piVar1 + 100))(piVar1,param_1);
  return;
}

/* Program__registerFileOfIlType @ 0xec208 (80 bytes) */
int Program__registerFileOfIlType(program, ilRegisterType)
  int program;
  int ilRegisterType;
{
  int iVar1;
  
  iVar1 = *(int *)(ilRegisterType * 8 + *(int *)(*(int *)(*(int *)(program + 8) + 0x30c) + 4) + 4);
  if (iVar1 == -1) {
    Compiler__fail(*(int *)(program + 8),0xf);
  }
  return iVar1;
}

/* FUN_000ec258 @ 0xec258 (36 bytes) */
int FUN_000ec258(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  return *(undefined4 *)(PTR_DAT_001e8b5c + param_2 * 4);
}

/* FUN_000ec27c @ 0xec27c (36 bytes) */
int FUN_000ec27c(program, param_2)
  undefined4 program;
  int param_2;
{
  return *(undefined4 *)(PTR_DAT_001e8b68 + param_2 * 4);
}

/* FUN_000ec2a0 @ 0xec2a0 (36 bytes) */
int FUN_000ec2a0(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  return *(undefined4 *)(PTR_DAT_001e8b6c + param_2 * 4);
}

/* Table__interpolatorKindToCode @ 0xec2c4 (36 bytes) */
int Table__interpolatorKindToCode(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  return *(undefined4 *)(PTR_DAT_001e8b60 + param_2 * 4);
}

/* Program__freeWorkArrays @ 0xec2e8 (136 bytes) */
int Program__freeWorkArrays(program)
  int program;
{
  if (*(int *)(program + PROG_workArray0) != 0) {
    Arena__free(*(undefined4 *)(*(int *)(program + PROG_compiler) + COMP_arenaA),*(int *)(program + PROG_workArray0));
    *(undefined4 *)(program + PROG_workArray0) = 0;
  }
  if (*(int *)(program + PROG_workArray1) != 0) {
    Arena__free(*(undefined4 *)(*(int *)(program + PROG_compiler) + COMP_arenaA),*(int *)(program + PROG_workArray1));
    *(undefined4 *)(program + PROG_workArray1) = 0;
  }
  if (*(int *)(program + PROG_workArray2) != 0) {
    Arena__free(*(undefined4 *)(*(int *)(program + PROG_compiler) + COMP_arenaA),*(int *)(program + PROG_workArray2));
    *(undefined4 *)(program + PROG_workArray2) = 0;
  }
  return;
}

/* FUN_000ec370 @ 0xec370 (60 bytes) */
int FUN_000ec370(program, ref, node)
  undefined4 program;
  undefined4 ref;
  int node;
{
  DList__insertBefore(node,ref);
  *(undefined4 *)(node + 0xac) = program;
  return ((int (*)())Program__freeWorkArrays)(program);
}

/* Program__insertBlockAfter @ 0xec3ac (60 bytes) */
int Program__insertBlockAfter(program, ref, node)
  undefined4 program;
  undefined4 ref;
  int node;
{
  DList__insertAfter(node,ref);
  *(undefined4 *)(node + 0xac) = program;
  return ((int (*)())Program__freeWorkArrays)(program);
}

/* FUN_000ec3e8 @ 0xec3e8 (68 bytes) */
int FUN_000ec3e8(program, node)
  int program;
  int node;
{
  DList__pushFront(program + 0x37c,node);
  ((int (*)())Program__freeWorkArrays)(program);
  *(int *)(node + 0xac) = program;
  return ((int (*)())Program__freeWorkArrays)(program);
}

/* FUN_000ec42c @ 0xec42c (60 bytes) */
int FUN_000ec42c(program, node)
  int program;
  int node;
{
  DList__pushBack(program + 0x37c,node);
  *(int *)(node + 0xac) = program;
  return ((int (*)())Program__freeWorkArrays)(program);
}

/* FUN_000ec468 @ 0xec468 (136 bytes) */
int FUN_000ec468(param_1, param_2, param_3)
  int param_1;
  int param_2;
  uint param_3;
{
  undefined4 allocation;
  int iVar2;
  uint loopIndex;
  
  if (*(int *)(param_1 + 0x394) != 0) {
    Arena__free(*(undefined4 *)(*(int *)(param_1 + 8) + 0x374),*(int *)(param_1 + 0x394));
  }
  allocation = Arena__alloc(*(undefined4 *)(*(int *)(param_1 + 8) + 0x374),param_3 * 4 + 4);
  loopIndex = 0;
  *(undefined4 *)(param_1 + 0x394) = allocation;
  iVar2 = 0;
  do {
    loopIndex = loopIndex + 1;
    *(undefined4 *)(*(int *)(param_1 + 0x394) + iVar2) = *(undefined4 *)(param_2 + iVar2);
    iVar2 = iVar2 + 4;
  } while (loopIndex <= param_3);
  return;
}

/* FUN_000ec4f0 @ 0xec4f0 (124 bytes) */
int FUN_000ec4f0(param_1)
  int param_1;
{
  int iVar1;
  undefined4 *allocation;
  undefined4 arena;
  undefined4 *puVar4;
  
  iVar1 = *(int *)(param_1 + 0x394);
  if (iVar1 == 0) {
    arena = *(undefined4 *)(*(int *)(param_1 + 8) + 0x378);
    allocation = (undefined4 *)Arena__alloc(arena,0x2c);
    *allocation = arena;
    puVar4 = allocation + 1;
    FUN_000f7cd8(puVar4,param_1);
    FUN_000f816c(puVar4,*(undefined4 *)(param_1 + 0x3a0));
    ((int (*)())FUN_000ec468)(param_1,allocation[7],allocation[8]);
    FUN_000f8044(puVar4);
    if (puVar4 == (undefined4 *)0x0) {
      iVar1 = *(int *)(param_1 + 0x394);
    }
    else {
      Arena__free(*allocation,allocation);
      iVar1 = *(int *)(param_1 + 0x394);
    }
  }
  return iVar1;
}

/* FUN_000ec5b8 @ 0xec5b8 (160 bytes) */
int FUN_000ec5b8(param_1)
  int param_1;
{
  undefined4 allocation;
  int listCount;
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int loopIndex;
  
  iVar2 = *(int *)(param_1 + 0x398);
  if (iVar2 == 0) {
    listCount = DList__count(param_1 + 0x37c);
    allocation = Arena__alloc(*(undefined4 *)(*(int *)(param_1 + 8) + 0x374),listCount * 4 + 4);
    *(undefined4 *)(param_1 + 0x398) = allocation;
    puVar4 = (undefined4 *)((int (*)())FUN_000ec4f0)(param_1);
    **(undefined4 **)(param_1 + 0x398) = *puVar4;
    if (0 < listCount) {
      puVar4 = puVar4 + listCount;
      loopIndex = 1;
      do {
        iVar1 = loopIndex * 4;
        loopIndex = loopIndex + 1;
        uVar3 = *puVar4;
        puVar4 = puVar4 + -1;
        *(undefined4 *)(iVar1 + *(int *)(param_1 + 0x398)) = uVar3;
      } while (loopIndex <= listCount);
    }
    iVar2 = *(int *)(param_1 + 0x398);
  }
  return iVar2;
}

/* FUN_000ec658 @ 0xec658 (88 bytes) */
int FUN_000ec658(param_1)
  int param_1;
{
  int listCount;
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  iVar3 = *(int *)(param_1 + 900);
  iVar1 = *(int *)(iVar3 + 8);
  while (iVar1 != 0) {
    listCount = DList__count(iVar3 + 0x90);
    iVar3 = *(int *)(iVar3 + 8);
    iVar2 = iVar2 + listCount;
    iVar1 = *(int *)(iVar3 + 8);
  }
  return iVar2;
}

/* FUN_000ec6b0 @ 0xec6b0 (120 bytes) */
int FUN_000ec6b0(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 900);
  iVar1 = *(int *)(iVar2 + 8);
  while( true ) {
    if (iVar1 == 0) {
      return 0;
    }
    iVar1 = Block__predecessorCount(iVar2);
    if ((1 < iVar1) || (iVar1 = Block__successorCount(iVar2), 1 < iVar1)) break;
    iVar2 = *(int *)(iVar2 + 8);
    iVar1 = *(int *)(iVar2 + 8);
  }
  return 1;
}

/* FUN_000ec728 @ 0xec728 (444 bytes) */
int FUN_000ec728(program)
  int program;
{
  int loopIndex3;
  int iVar1;
  undefined4 inst;
  undefined4 uVar3;
  int loopIndex;
  int iVar5;
  int loopIndex2;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  int iVar10;
  int iVar11;
  
  iVar1 = *(int *)(program + 900);
  for (iVar8 = *(int *)(*(int *)(program + 900) + 8); iVar8 != 0; iVar8 = *(int *)(iVar8 + 8)) {
    iVar7 = *(int *)(*(int *)(iVar1 + 0x98) + 8);
    iVar10 = *(int *)(iVar1 + 0x98);
    if (iVar7 != 0) {
      do {
        iVar8 = iVar7;
        if (((*(uint *)(iVar10 + 0x14) & 1) != 0) && (iVar7 = *(int *)(iVar10 + 0x84), 0 < iVar7)) {
          loopIndex = 0;
          loopIndex2 = 0;
          iVar5 = iVar10;
          iVar11 = iVar7;
          do {
            if (*(int *)(iVar5 + 0xb0) - 2U < 3) {
              loopIndex2 = loopIndex2 + 1;
            }
            else if (*(int *)(iVar5 + 0xb0) == 0xc) {
              loopIndex = loopIndex + 1;
            }
            iVar5 = iVar5 + 0x18;
            iVar11 = iVar11 + -1;
          } while (iVar11 != 0);
          if ((loopIndex2 != 0) && (loopIndex != 0)) {
            loopIndex3 = 0;
            iVar8 = iVar10;
            do {
              loopIndex3 = loopIndex3 + 1;
              if (((*(int *)(iVar8 + 0xb0) - 2U < 3) && (loopIndex >= loopIndex2)) ||
                 ((*(int *)(iVar8 + 0xb0) == 0xc && (loopIndex < loopIndex2)))) {
                inst = IRInst__create(0x31,*(undefined4 *)(program + 8));
                uVar3 = *(undefined4 *)(program + 0x3ac);
                uVar9 = *(undefined4 *)(iVar8 + 0xa4);
                iVar11 = *(int *)(*(int *)(program + 8) + 0x3ac) + -1;
                *(int *)(*(int *)(program + 8) + 0x3ac) = iVar11;
                uVar3 = FUN_00127608(uVar3,0,iVar11,0);
                IRInst__setOperandRef(inst,0,uVar3);
                IRInst__setOperandRef(inst,1,uVar9);
                FUN_001235b8(uVar9,iVar10,inst);
                IRInst__setOperandRef(iVar10,loopIndex3,uVar3);
                Block__insertInstBefore(*(undefined4 *)(iVar10 + 0x158),iVar10,inst);
              }
              iVar8 = iVar8 + 0x18;
            } while (iVar7 != loopIndex3);
            iVar8 = *(int *)(iVar10 + 8);
          }
        }
        iVar7 = *(int *)(iVar8 + 8);
        iVar10 = iVar8;
      } while (*(int *)(iVar8 + 8) != 0);
      iVar8 = *(int *)(iVar1 + 8);
    }
    iVar1 = iVar8;
  }
  return;
}

/* FUN_000ec8e4 @ 0xec8e4 (60 bytes) */
int FUN_000ec8e4(param_1)
  int param_1;
{
  FUN_0012740c(*(undefined4 *)(param_1 + 0x3ac));
  *(uint *)(param_1 + 0x30) = *(uint *)(param_1 + 0x30) | 0x10;
  return;
}

/* FUN_000ec920 @ 0xec920 (240 bytes) */
int FUN_000ec920(param_1)
  int param_1;
{
  int listCount;
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  uint loopIndex2;
  int iVar5;
  int loopIndex;
  undefined4 *puVar7;
  int *piVar8;
  bool bVar9;
  
  puVar2 = (undefined4 *)((int (*)())FUN_000ec5b8)(param_1);
  do {
    bVar9 = false;
    loopIndex = 1;
    puVar7 = puVar2;
    while( true ) {
      puVar7 = puVar7 + 1;
      listCount = DList__count(param_1 + 0x37c);
      if (listCount < loopIndex) break;
      piVar8 = (int *)*puVar7;
      iVar3 = (**(code **)(*piVar8 + 0x20))(piVar8);
      if (iVar3 == 0) {
        iVar3 = piVar8[3];
        iVar5 = 0;
        for (loopIndex2 = 1; loopIndex2 <= *(uint *)(piVar8[0x34] + 4); loopIndex2 = loopIndex2 + 1) {
          iVar1 = *(int *)(*(int *)(piVar8[0x34] + 8) + iVar5);
          if (iVar1 != 0) {
            piVar8[3] = *(uint *)(iVar1 + 0xc) & 3 | piVar8[3];
          }
          iVar5 = iVar5 + 4;
        }
        bVar9 = iVar3 != piVar8[3];
      }
      loopIndex = loopIndex + 1;
    }
  } while (bVar9);
  return;
}

/* KhanVs__vslot17_isSimpleInst @ 0xeca10 (192 bytes) */
int KhanVs__vslot17_isSimpleInst(this, inst)
  undefined4 this;
  int *inst;
{
  int slotResult;
  uint excluded;
  
  slotResult = (**(code **)(*inst + 0x40))(inst,inst);
  if ((((slotResult != 0) || (slotResult = (**(code **)(*inst + 0x28))(inst), slotResult != 0)) ||
      (slotResult = (**(code **)(*inst + 0x60))(inst), slotResult != 0)) ||
     ((slotResult = (**(code **)(*inst + 0x5c))(inst), slotResult != 0 ||
      (excluded = 0, *(int *)(inst[0x22] + 8) == 0x84)))) {
    excluded = 1;
  }
  return excluded ^ 1;
}

/* KhanPs__vslot17_isSimpleInst @ 0xecad0 (192 bytes) */
int KhanPs__vslot17_isSimpleInst(this, inst)
  undefined4 this;
  int *inst;
{
  int slotResult;
  uint excluded;
  
  slotResult = (**(code **)(*inst + 0x40))(inst,inst);
  if ((((slotResult != 0) || (slotResult = (**(code **)(*inst + 0x28))(inst), slotResult != 0)) ||
      (slotResult = (**(code **)(*inst + 0x60))(inst), slotResult != 0)) ||
     ((slotResult = (**(code **)(*inst + 0x5c))(inst), slotResult != 0 ||
      (excluded = 0, *(int *)(inst[0x22] + 8) == 0x84)))) {
    excluded = 1;
  }
  return excluded ^ 1;
}

/* FUN_000ecb90 @ 0xecb90 (140 bytes) */
int FUN_000ecb90(param_1, compiler)
  int param_1;
  undefined4 compiler;
{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_0011379c(compiler,param_1);
  if (iVar1 == 0) {
    uVar2 = *(undefined4 *)(*(int *)(param_1 + 0x88) + 8);
    iVar1 = OpcodeTraits__flagBit2(uVar2,compiler);
    if (((iVar1 == 0) || (iVar1 = OpcodeTraits__flagBit9(uVar2,compiler), iVar1 != 0)) &&
       (iVar1 = OpcodeTraits__flagBit8(uVar2,compiler), iVar1 == 0)) {
      return 0;
    }
  }
  return 1;
}

/* FUN_000ecc1c @ 0xecc1c (268 bytes) */
int FUN_000ecc1c(inst, param_2, compiler)
  int *inst;
  undefined4 param_2;
  int compiler;
{
  int hasSingleUse;
  int iVar1;
  
  iVar1 = (**(code **)(*inst + 0x60))(inst,param_2,compiler);
  if (iVar1 != 0) {
    hasSingleUse = IRInst__hasSingleUse(inst,*(undefined4 *)(compiler + COMP_currentProgram));
    if (hasSingleUse == 0) {
      return 0;
    }
    iVar1 = FUN_0010c47c(inst,compiler);
    if (iVar1 == 0) {
      return 0;
    }
    inst = (int *)IRInst__getOperandSource(inst,1);
  }
  iVar1 = IRInst__hasSingleUse(inst,*(undefined4 *)(compiler + COMP_currentProgram));
  if ((((iVar1 != 0) &&
       (iVar1 = (**(code **)(**(int **)(compiler + COMP_target) + 0x44))
                          (*(int **)(compiler + COMP_target),inst), iVar1 != 0)) &&
      ((*(uint *)(inst[0x56] + 0xc) & 8) != 0)) &&
     ((iVar1 = SelectWord__areCompatible(param_2,0x10203), iVar1 != 0 ||
      (iVar1 = ((int (*)())FUN_000ecb90)(inst,compiler), iVar1 != 0)))) {
    return 1;
  }
  return 0;
}

/* FUN_000ecd28 @ 0xecd28 (424 bytes) */
int FUN_000ecd28(param_1, newSource, afterInst, param_4, param_5, param_6)
  int param_1;
  int *newSource;
  int *afterInst;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
{
  int operandRecord;
  int *piVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int local_28 [2];
  
  piVar2 = (int *)FUN_001084b8(0x31,*(undefined4 *)(param_1 + 8));
  IRInst__setOperandSource(piVar2,1,newSource,0,*(undefined4 *)(param_1 + 8));
  IRInst__setHardwareRegisterAndAdd(piVar2,param_1,param_4,param_5);
  (**(code **)(*piVar2 + 0x94))(piVar2,afterInst,*(undefined4 *)(param_1 + 8));
  SelectWord__clearReadComponents(local_28,param_6);
  piVar2[0x27] = local_28[0];
  operandRecord = IRInst__getOperandRecord(piVar2,1);
  *(undefined4 *)(operandRecord + 0x10) = param_6;
  iVar3 = newSource[0x56];
  if (iVar3 == afterInst[0x56]) {
    piVar4 = *(int **)(iVar3 + 0x98);
    for (piVar1 = (int *)(*(int **)(iVar3 + 0x98))[2]; piVar1 != (int *)0x0;
        piVar1 = (int *)piVar1[2]) {
      if ((piVar4[5] & 1U) != 0) {
        if (piVar4 == afterInst) break;
        if (piVar4 == newSource) goto LAB_000ece34;
      }
      piVar4 = piVar1;
    }
  }
  else if ((*(uint *)(iVar3 + 0xc) & 8) == 0) goto LAB_000ece34;
  afterInst = newSource;
LAB_000ece34:
  piVar4 = (int *)afterInst[0x56];
  iVar3 = (**(code **)(*piVar4 + 0x2c))(piVar4);
  if (iVar3 != 0) {
    Block__prependInst(piVar4[0x55],piVar2);
    return;
  }
  iVar3 = (**(code **)(*afterInst + 0x7c))(afterInst);
  if (iVar3 != 0) {
    FUN_000e8424(piVar4,piVar2);
    return;
  }
  return Block__insertInstAfter(piVar4,afterInst,piVar2);
}

/* FUN_000eced0 @ 0xeced0 (140 bytes) */
int FUN_000eced0(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  undefined4 *allocation;
  undefined4 arena;
  
  arena = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
  allocation = (undefined4 *)Arena__alloc(arena,0x168);
  *allocation = arena;
  IRInst__ctor_10502c(allocation + 1,0x93,*(undefined4 *)(param_1 + 8));
  *(undefined4 **)(param_1 + 0x33c) = allocation + 1;
  allocation[0x27] = 0x2d;
  allocation[0x26] = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x33c) + 300) = 0;
  *(uint *)(*(int *)(param_1 + 0x3a0) + 0xc) = *(uint *)(*(int *)(param_1 + 0x3a0) + 0xc) | 8;
  Block__prependInst(*(undefined4 *)(param_1 + 0x3a0),*(undefined4 *)(param_1 + 0x33c));
  iVar1 = *(int *)(param_1 + 900);
  for (iVar2 = *(int *)(*(int *)(param_1 + 900) + 8); iVar2 != 0; iVar2 = *(int *)(iVar2 + 8)) {
    *(uint *)(iVar1 + 0xc) = *(uint *)(iVar1 + 0xc) | 8;
    iVar1 = iVar2;
  }
  return;
}

/* FUN_000ecfac @ 0xecfac (312 bytes) */
int FUN_000ecfac(param_1)
  int param_1;
{
  int iVar1;
  undefined *puVar2;
  
  iVar1 = *(int *)(param_1 + 0x430);
  if (iVar1 != 0) {
    Arena__free(*(undefined4 *)(iVar1 + -4),iVar1 + -4);
  }
  iVar1 = *(int *)(param_1 + 0x42c);
  if (iVar1 != 0) {
    Arena__free(*(undefined4 *)(iVar1 + -4),iVar1 + -4);
  }
  iVar1 = *(int *)(param_1 + 0x3c8);
  if (iVar1 != 0) {
    Arena__free(*(undefined4 *)(iVar1 + 0xc),*(undefined4 *)(iVar1 + 8));
    Arena__free(*(undefined4 *)(iVar1 + -4),iVar1 + -4);
  }
  iVar1 = *(int *)(param_1 + 0x3c4);
  if (iVar1 != 0) {
    Arena__free(*(undefined4 *)(iVar1 + 0xc),*(undefined4 *)(iVar1 + 8));
    Arena__free(*(undefined4 *)(iVar1 + -4),iVar1 + -4);
  }
  iVar1 = *(int *)(param_1 + 0x3ac);
  if (iVar1 != 0) {
    FUN_00127470(iVar1);
    Arena__free(*(undefined4 *)(iVar1 + -4),iVar1 + -4);
  }
  Arena__free(*(undefined4 *)(*(int *)(param_1 + 8) + 0x374),*(undefined4 *)(param_1 + 0x460));
  Arena__free(*(undefined4 *)(*(int *)(param_1 + 8) + 0x374),*(undefined4 *)(param_1 + 0x45c));
  Arena__free(*(undefined4 *)(*(int *)(param_1 + 8) + 0x374),*(undefined4 *)(param_1 + 0x458));
  Arena__free(*(undefined4 *)(*(int *)(param_1 + 8) + 0x374),*(undefined4 *)(param_1 + 0x394));
  Arena__free(*(undefined4 *)(*(int *)(param_1 + 8) + 0x374),*(undefined4 *)(param_1 + 0x398));
  Arena__free(*(undefined4 *)(*(int *)(param_1 + 8) + 0x374),*(undefined4 *)(param_1 + 0x39c));
  DListNode__clear((undefined4 *)(param_1 + 0x37c));
  puVar2 = PTR_DAT_001e8b48 + 8;
  *(undefined4 *)(param_1 + 0x37c) = puVar2;
  *(undefined **)(param_1 + 0x388) = puVar2;
  return;
}

/* FUN_000ed124 @ 0xed124 (312 bytes) */
int FUN_000ed124(param_1)
  int param_1;
{
  int iVar1;
  undefined *puVar2;
  
  iVar1 = *(int *)(param_1 + 0x430);
  if (iVar1 != 0) {
    Arena__free(*(undefined4 *)(iVar1 + -4),iVar1 + -4);
  }
  iVar1 = *(int *)(param_1 + 0x42c);
  if (iVar1 != 0) {
    Arena__free(*(undefined4 *)(iVar1 + -4),iVar1 + -4);
  }
  iVar1 = *(int *)(param_1 + 0x3c8);
  if (iVar1 != 0) {
    Arena__free(*(undefined4 *)(iVar1 + 0xc),*(undefined4 *)(iVar1 + 8));
    Arena__free(*(undefined4 *)(iVar1 + -4),iVar1 + -4);
  }
  iVar1 = *(int *)(param_1 + 0x3c4);
  if (iVar1 != 0) {
    Arena__free(*(undefined4 *)(iVar1 + 0xc),*(undefined4 *)(iVar1 + 8));
    Arena__free(*(undefined4 *)(iVar1 + -4),iVar1 + -4);
  }
  iVar1 = *(int *)(param_1 + 0x3ac);
  if (iVar1 != 0) {
    FUN_00127470(iVar1);
    Arena__free(*(undefined4 *)(iVar1 + -4),iVar1 + -4);
  }
  Arena__free(*(undefined4 *)(*(int *)(param_1 + 8) + 0x374),*(undefined4 *)(param_1 + 0x460));
  Arena__free(*(undefined4 *)(*(int *)(param_1 + 8) + 0x374),*(undefined4 *)(param_1 + 0x45c));
  Arena__free(*(undefined4 *)(*(int *)(param_1 + 8) + 0x374),*(undefined4 *)(param_1 + 0x458));
  Arena__free(*(undefined4 *)(*(int *)(param_1 + 8) + 0x374),*(undefined4 *)(param_1 + 0x394));
  Arena__free(*(undefined4 *)(*(int *)(param_1 + 8) + 0x374),*(undefined4 *)(param_1 + 0x398));
  Arena__free(*(undefined4 *)(*(int *)(param_1 + 8) + 0x374),*(undefined4 *)(param_1 + 0x39c));
  DListNode__clear((undefined4 *)(param_1 + 0x37c));
  puVar2 = PTR_DAT_001e8b48 + 8;
  *(undefined4 *)(param_1 + 0x37c) = puVar2;
  *(undefined **)(param_1 + 0x388) = puVar2;
  return;
}

/* HwLimits__vslot43_prependDefaultMov @ 0xed29c (264 bytes) */
int HwLimits__vslot43_prependDefaultMov(this, inst, param_3, compiler)
  undefined4 this;
  int inst;
  undefined4 param_3;
  int compiler;
{
  int lanesLeft;
  int laneIndex;
  int destRecord;
  int inst2;
  int destRecord2;
  double fparam_1;
  undefined4 unwrittenLaneMask;
  undefined4 destSelectBytes [8];
  
  if (inst == 0) {
    Compiler__fail(compiler,0xf);
  }
  destRecord = IRInst__getOperandRecord(inst,0);
  if (*(int *)(destRecord + 0x10) != DAT_001aa800) {
    inst2 = IRInst__create(0x31,compiler);
    fparam_1 = (double)FLOAT_001aa0d4;
    ((void (*)())IRInst__makeLiteralVec4Float)(inst2,*(undefined4 *)(compiler + COMP_currentProgram),1,fparam_1,fparam_1,fparam_1,
                 (double)FLOAT_001aa0e8);
    IRInst__setOperandRef(inst2,0,*(undefined4 *)(inst + 0xa4));
    destRecord2 = IRInst__getOperandRecord(inst,0);
    laneIndex = 0;
    destSelectBytes[0] = *(undefined4 *)(destRecord2 + 0x10);
    lanesLeft = 4;
    do {
      *(byte *)((int)destSelectBytes + laneIndex + -4) =
           (byte)(-(uint)(*(byte *)((int)destSelectBytes + laneIndex) ^ 1) >> 0x1f);
      laneIndex = laneIndex + 1;
      lanesLeft = lanesLeft + -1;
    } while (lanesLeft != 0);
    *(undefined4 *)(inst2 + 0x9c) = unwrittenLaneMask;
    Block__prependInst(*(undefined4 *)(inst + 0x158),inst2);
    *(int *)(inst + 0x9c) = DAT_001aa800;
  }
  return;
}

/* FUN_000ed63c @ 0xed63c (424 bytes) */
int FUN_000ed63c(param_1, inst)
  int param_1;
  int inst;
{
  int operandRecord;
  int operandRecord2;
  int *piVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int loopIndex;
  undefined4 uVar6;
  code *pcVar7;
  int iVar8;
  
  if (*(int *)(inst + 0x80) != 0) {
    piVar1 = (int *)FUN_00127608(*(undefined4 *)(param_1 + 0x3ac),*(undefined4 *)(inst + 0x98),
                                 *(undefined4 *)(inst + 0x94),0);
    pcVar7 = *(code **)(*piVar1 + 0x28);
    operandRecord2 = IRInst__getOperandRecord(inst,0);
    piVar3 = (int *)(*pcVar7)(piVar1,*(undefined4 *)(operandRecord2 + 0x10),param_1);
    if ((piVar3 == (int *)0x0) || (piVar1 == piVar3)) {
      FUN_0012306c(piVar1,inst);
      IRInst__setOperandRef(inst,0,piVar1);
    }
    else {
      FUN_0012306c(piVar3,inst);
      IRInst__setOperandRef(inst,0,piVar3);
      if ((*(uint *)(param_1 + 0x30) & 0x4000) != 0) {
        Block__insertInstAfter(*(undefined4 *)(inst + 0x158),inst,piVar1[0xc]);
      }
    }
  }
  if (0 < *(int *)(inst + 0x84)) {
    loopIndex = 1;
    iVar2 = inst;
    do {
      iVar4 = *(int *)(iVar2 + 0xb0);
      if (iVar4 == 0x1c) {
        iVar8 = *(int *)(*(int *)(param_1 + 8) + 0x3ac) + -1;
        *(int *)(*(int *)(param_1 + 8) + 0x3ac) = iVar8;
        uVar6 = *(undefined4 *)(iVar2 + 0xb0);
        operandRecord = IRInst__getOperandRecord(inst,loopIndex);
        *(int *)(operandRecord + 8) = iVar8;
        *(undefined4 *)(operandRecord + 0xc) = uVar6;
        iVar4 = *(int *)(iVar2 + 0xb0);
      }
      piVar1 = (int *)FUN_00127608(*(undefined4 *)(param_1 + 0x3ac),iVar4,
                                   *(undefined4 *)(iVar2 + 0xac),0);
      piVar3 = (int *)(**(code **)(*piVar1 + 0x28))(piVar1,DAT_001aa80c,param_1);
      if (piVar3 != (int *)0x0) {
        piVar1 = piVar3;
      }
      VReg__addUse(piVar1,loopIndex,inst);
      IRInst__setOperandRef(inst,loopIndex,piVar1);
      loopIndex = loopIndex + 1;
      iVar2 = iVar2 + 0x18;
    } while (loopIndex <= *(int *)(inst + 0x84));
  }
  return;
}

/* Program__beginPass @ 0xed7e4 (184 bytes) */
int Program__beginPass(program, param_2)
  int program;
  uint param_2;
{
  int iVar1;
  int iVar2;
  uint extraout_r4;
  int iVar3;
  int *a0;
  uint loopIndex;
  
  a0 = *(int **)(program + PROG_blockListHead);
  iVar1 = a0[2];
  while (iVar1 != 0) {
    (**(code **)(*a0 + 0x48))(a0,param_2);
    a0 = (int *)a0[2];
    param_2 = extraout_r4;
    iVar1 = a0[2];
  }
  iVar1 = *(int *)(program + PROG_instructionVector);
  iVar3 = 0;
  for (loopIndex = 1; loopIndex <= *(uint *)(iVar1 + 4); loopIndex = loopIndex + 1) {
    iVar2 = *(int *)(*(int *)(iVar1 + 8) + iVar3);
    if ((*(uint *)(iVar2 + 0x14) & 1) != 0) {
      IRInst__getOperandRecord(iVar2,0);
      iVar1 = *(int *)(program + PROG_instructionVector);
    }
    iVar3 = iVar3 + 4;
  }
  return 1;
}

/* FUN_000ed89c @ 0xed89c (852 bytes) */
int FUN_000ed89c(param_1)
  int param_1;
{
  int operandRecord;
  bool bVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  undefined4 *allocation;
  undefined4 *puVar7;
  int iVar8;
  int iVar9;
  int *piVar10;
  undefined4 uVar11;
  int *piVar12;
  int iVar13;
  undefined4 uVar14;
  int *piVar15;
  undefined4 arena;
  undefined4 arenaAt374;
  int iVar18;
  int local_58;
  int local_54;
  int local_50 [6];
  
  iVar2 = *(int *)(param_1 + 900);
  iVar5 = *(int *)(*(int *)(param_1 + 900) + 8);
  do {
    if (iVar5 == 0) {
      return;
    }
    piVar3 = (int *)(*(int **)(iVar2 + 0x98))[2];
    if (piVar3 != (int *)0x0) {
      piVar12 = (int *)0x0;
      piVar15 = (int *)0x0;
      bVar1 = true;
      piVar10 = *(int **)(iVar2 + 0x98);
      do {
        piVar4 = piVar3;
        if ((piVar10[5] & 1U) != 0) {
          iVar13 = piVar10[0x2c];
          iVar5 = (**(code **)(*piVar10 + 0x28))(piVar10);
          if (((iVar5 == 0) || (iVar5 = (**(code **)(*piVar10 + 0x2c))(piVar10), iVar5 == 0)) ||
             ((iVar13 != 0x1f && (((iVar13 != 0xd && (iVar13 != 0xe)) && (iVar13 != 0xf)))))) {
            piVar4 = (int *)piVar10[2];
          }
          else {
            arena = *(undefined4 *)(*(int *)(param_1 + 8) + 0x378);
            allocation = (undefined4 *)Arena__alloc(arena,0x18);
            *allocation = arena;
            allocation[5] = piVar12;
            allocation[2] = piVar10;
            piVar10[0x4d] = 1;
            operandRecord = IRInst__getOperandRecord(piVar10,1);
            iVar5 = *(int *)(operandRecord + 0x10);
            FUN_00104364(piVar10,&local_58,&local_54,local_50);
            allocation[3] = local_54;
            allocation[4] = local_50[0];
            piVar3 = piVar15;
            if (!bVar1) {
              do {
                if (((*piVar3 == local_58) && (iVar13 == piVar3[1])) && (piVar3[2] == iVar5)) {
                  if (local_54 < piVar3[5]) {
                    piVar3[3] = (int)piVar10;
                    piVar3[5] = local_54;
                  }
                  if (piVar3[6] < local_54 + local_50[0]) {
                    piVar3[6] = local_54 + local_50[0];
                  }
                  piVar3[4] = piVar3[4] + 1;
                  goto LAB_000eda98;
                }
                piVar12 = piVar3 + 0xb;
                piVar3 = (int *)*piVar12;
              } while ((int *)*piVar12 != (int *)0x0);
            }
            arena = *(undefined4 *)(*(int *)(param_1 + 8) + 0x378);
            puVar7 = (undefined4 *)Arena__alloc(arena,0x34);
            *puVar7 = arena;
            piVar3 = puVar7 + 1;
            bVar1 = piVar3 == (int *)0x0;
            puVar7[2] = iVar13;
            puVar7[1] = local_58;
            puVar7[3] = iVar5;
            puVar7[6] = local_54;
            puVar7[0xc] = piVar15;
            puVar7[7] = local_54 + local_50[0];
            puVar7[5] = 1;
            puVar7[4] = piVar10;
            piVar15 = piVar3;
LAB_000eda98:
            allocation[1] = piVar3;
            piVar4 = (int *)piVar10[2];
            piVar12 = allocation + 1;
          }
        }
        piVar3 = (int *)piVar4[2];
        piVar10 = piVar4;
      } while ((int *)piVar4[2] != (int *)0x0);
      if (!bVar1) {
        do {
          arena = FUN_00127608(*(undefined4 *)(param_1 + 0x3ac),0x22,0,0);
          piVar3 = (int *)0x0;
          do {
            iVar5 = piVar15[3];
            piVar10 = (int *)piVar15[0xb];
            piVar15[7] = iVar5;
            piVar15[0xb] = 0;
            uVar14 = *(undefined4 *)(iVar5 + 0x8c);
            operandRecord = IRInst__getOperandRecord(iVar5,0);
            uVar11 = *(undefined4 *)(operandRecord + 0x10);
            IRInst__setOperandRef(piVar15[7],0,arena);
            *(undefined4 *)(piVar15[7] + 0x9c) = DAT_001aa800;
            FUN_0012306c(arena,piVar15[7]);
            arenaAt374 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
            allocation = (undefined4 *)Arena__alloc(arenaAt374,0x168);
            *allocation = arenaAt374;
            puVar7 = allocation + 1;
            IRProjection__ctor_109e28(puVar7,0x84,*(undefined4 *)(param_1 + 8));
            IRInst__setOperandRef(puVar7,0,uVar14);
            allocation[0x28] = uVar11;
            IRInst__setOperandRef(puVar7,1,arena);
            FUN_0012306c(uVar14,puVar7);
            VReg__addUse(arena,1,puVar7);
            Block__insertInstAfter(iVar2,piVar15[7],puVar7);
            *(undefined4 **)(piVar15[7] + 0x138) = puVar7;
            piVar15[9] = piVar15[5];
            piVar15[8] = (int)puVar7;
            piVar15[10] = 0;
            *(undefined4 *)(piVar15[7] + 0x13c) = 0;
            if (8 < piVar15[6] - piVar15[5]) {
              piVar15[0xb] = (int)piVar3;
              piVar15[5] = piVar15[6] + 1;
              piVar15[6] = 0;
              piVar15[3] = 0;
              piVar15[4] = 0;
              piVar3 = piVar15;
            }
            piVar15 = piVar10;
          } while (piVar10 != (int *)0x0);
          piVar10 = (int *)0x0;
          piVar15 = piVar12;
          while (piVar12 = piVar10, piVar15 != (int *)0x0) {
            iVar18 = *piVar15;
            piVar4 = (int *)piVar15[4];
            piVar15[4] = 0;
            iVar13 = piVar15[1];
            iVar9 = piVar15[2];
            iVar8 = piVar15[3];
            iVar5 = (iVar9 + iVar8) - *(int *)(iVar18 + 0x24);
            piVar10 = piVar12;
            if (iVar13 == *(int *)(iVar18 + 0x1c)) {
              piVar15 = piVar4;
              if (*(int *)(iVar18 + 0x28) < iVar5) {
                *(int *)(iVar18 + 0x28) = iVar5;
                *(int *)(iVar13 + 0x13c) = iVar5;
              }
            }
            else if (iVar5 < 9) {
              if (*(int *)(iVar18 + 0x28) < iVar5) {
                *(int *)(iVar18 + 0x28) = iVar5;
                *(int *)(*(int *)(iVar18 + 0x1c) + 0x13c) = iVar5;
                iVar13 = piVar15[1];
              }
              DList__unlink(iVar13);
              DList__insertAfter(piVar15[1],*(undefined4 *)(iVar18 + 0x20));
              IRInst__appendSource(piVar15[1],arena);
              VReg__addUse(arena,*(undefined4 *)(piVar15[1] + 0x84),piVar15[1]);
              piVar15 = piVar4;
            }
            else {
              if (iVar9 < *(int *)(iVar18 + 0x14)) {
                *(int *)(iVar18 + 0xc) = iVar13;
                *(int *)(iVar18 + 0x14) = piVar15[2];
                iVar9 = piVar15[2];
                iVar8 = piVar15[3];
              }
              if (*(int *)(iVar18 + 0x18) < iVar9 + iVar8) {
                *(int *)(iVar18 + 0x18) = iVar9 + iVar8;
              }
              *(int *)(iVar18 + 0x10) = *(int *)(iVar18 + 0x10) + 1;
              piVar15[4] = (int)piVar12;
              piVar10 = piVar15;
              piVar15 = piVar4;
            }
          }
          piVar15 = piVar3;
        } while (piVar3 != (int *)0x0);
      }
      iVar5 = *(int *)(iVar2 + 8);
    }
    iVar2 = iVar5;
    iVar5 = *(int *)(iVar5 + 8);
  } while( true );
}

/* FUN_000edd98 @ 0xedd98 (1216 bytes) */
int FUN_000edd98(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  undefined4 *allocation;
  undefined4 *puVar2;
  undefined4 arena;
  int iVar4;
  
  param_1[2] = param_2;
  *param_1 = 0;
  param_1[0xc] = 0;
  param_1[0x1f] = 0xffffffff;
  param_1[0x20] = 0xffffffff;
  param_1[0x21] = 0;
  param_1[0x22] = 0;
  param_1[0x23] = 0;
  param_1[0x24] = 0;
  param_1[0x25] = 0;
  param_1[0x26] = 0;
  param_1[0x27] = 0;
  param_1[0x28] = 0;
  param_1[0x29] = 0;
  param_1[0x2a] = 0;
  param_1[0x2b] = 0;
  param_1[0x2c] = 0;
  param_1[0x2d] = 0;
  param_1[0x2e] = 0;
  param_1[0x2f] = 0;
  param_1[0x30] = 0;
  param_1[0x31] = 0;
  param_1[0x32] = 0;
  param_1[0x33] = 0;
  param_1[0x34] = 0;
  param_1[0x35] = 0;
  param_1[0x36] = 0;
  param_1[0x37] = 0;
  param_1[0x38] = 0;
  param_1[0x39] = 0;
  param_1[0x3a] = 0;
  param_1[0x3b] = 0;
  param_1[0x3c] = 0;
  param_1[0x3d] = 0;
  param_1[0x3e] = 0;
  param_1[0x3f] = 0;
  param_1[0x40] = 0;
  param_1[0x41] = 0;
  param_1[0x42] = 0;
  param_1[0x43] = 0;
  param_1[0x44] = 0;
  param_1[0x45] = 0;
  param_1[0x46] = 0;
  param_1[0x47] = 0;
  param_1[0x48] = 0;
  param_1[0x49] = 0;
  param_1[0x4a] = 0;
  param_1[0x4b] = 0;
  param_1[0x4c] = 0;
  param_1[0x4d] = 0;
  param_1[0x4e] = 0;
  param_1[0x4f] = 0;
  param_1[0x50] = 0;
  param_1[0x51] = 0;
  param_1[0x52] = 0;
  param_1[0x53] = 0;
  param_1[0x54] = 0;
  param_1[0x55] = 0;
  param_1[0x56] = 0;
  param_1[0x57] = 0;
  param_1[0x58] = 0;
  param_1[0x59] = 0;
  param_1[0x5a] = 0;
  param_1[0x5b] = 0;
  param_1[0x5c] = 0;
  param_1[0x5d] = 0;
  param_1[0x5e] = 0;
  param_1[0x5f] = 0;
  param_1[0x60] = 0;
  param_1[0x61] = 0;
  param_1[0x62] = 0;
  param_1[99] = 0;
  param_1[100] = 0;
  param_1[0x65] = 0;
  param_1[0x66] = 0;
  param_1[0x67] = 0;
  param_1[0x68] = 0;
  param_1[0x69] = 0;
  param_1[0x6a] = 0;
  param_1[0x6b] = 0;
  param_1[0x6c] = 0;
  param_1[0x6d] = 0;
  param_1[0x6e] = 0;
  param_1[0x6f] = 0;
  param_1[0x70] = 0;
  param_1[0x71] = 0;
  param_1[0x72] = 0;
  param_1[0x73] = 0;
  param_1[0x74] = 0;
  param_1[0x75] = 0;
  param_1[0x76] = 0;
  param_1[0x77] = 0;
  param_1[0x78] = 0;
  param_1[0x79] = 0;
  param_1[0x7a] = 0;
  param_1[0x7b] = 0;
  param_1[0x7c] = 0;
  param_1[0x7d] = 0;
  param_1[0x7e] = 0;
  param_1[0x7f] = 0;
  param_1[0x80] = 0;
  param_1[0x81] = 0;
  param_1[0x82] = 0;
  param_1[0x83] = 0;
  param_1[0x84] = 0;
  param_1[0x85] = 0;
  param_1[0x86] = 0;
  param_1[0x87] = 0;
  param_1[0x88] = 0;
  param_1[0x89] = 0;
  param_1[0x8a] = 0;
  param_1[0x8b] = 0;
  param_1[0x8c] = 0;
  param_1[0x8d] = 0;
  param_1[0x8e] = 0;
  param_1[0x8f] = 0;
  param_1[0x90] = 0;
  param_1[0x91] = 0;
  param_1[0x92] = 0;
  param_1[0x93] = 0;
  param_1[0x94] = 0;
  param_1[0x95] = 0;
  param_1[0x96] = 0;
  param_1[0x97] = 0;
  param_1[0x98] = 0;
  param_1[0x99] = 0;
  param_1[0x9a] = 0;
  param_1[0x9b] = 0;
  param_1[0x9c] = 0;
  param_1[0x9d] = 0;
  param_1[0x9e] = 0;
  param_1[0x9f] = 0;
  param_1[0xa0] = 0;
  param_1[0xa1] = 0;
  param_1[0xa2] = 0;
  param_1[0xa3] = 0;
  param_1[0xa4] = 0;
  param_1[0xa5] = 0;
  param_1[0xa6] = 0;
  param_1[0xa7] = 0;
  param_1[0xa8] = 0;
  param_1[0xa9] = 0;
  param_1[0xaa] = 0;
  param_1[0xab] = 0;
  param_1[0xcc] = 0;
  param_1[0xce] = 0;
  param_1[0xcf] = 0;
  param_1[0xd1] = 0;
  param_1[0xd2] = 0;
  param_1[0xd3] = 0;
  param_1[0xd4] = 0;
  param_1[0xd6] = 0;
  param_1[0xd7] = 0;
  param_1[0xd8] = 0;
  param_1[0xd9] = 0;
  param_1[0xda] = 0;
  param_1[0xdd] = 0;
  DListNode__init(param_1 + 0xdf);
  iVar4 = 0x10;
  param_1[0xfa] = 0x7fffffff;
  param_1[0xfe] = 1;
  param_1[0xf6] = 0x7fffffff;
  param_1[0x10a] = 0xffffffff;
  param_1[0x11f] = 0;
  param_1[0xe5] = 0;
  param_1[0xe6] = 0;
  param_1[0xe7] = 0;
  param_1[0xe9] = 0;
  param_1[0xed] = 0;
  param_1[0xf0] = 0;
  param_1[0xf3] = 0;
  param_1[0xf5] = 0;
  param_1[0xf7] = 0xffffffff;
  param_1[0xf8] = 0;
  param_1[0xf9] = 0;
  param_1[0xfb] = 0xffffffff;
  param_1[0xfc] = 0;
  param_1[0x11d] = 0;
  param_1[0x11e] = 0;
  allocation = param_1;
  do {
    allocation[0xe] = 0;
    allocation = allocation + 1;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  iVar4 = 0x20;
  allocation = param_1;
  do {
    allocation[0xac] = 0;
    allocation = allocation + 1;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  arena = *(undefined4 *)(param_1[2] + 0x374);
  allocation = (undefined4 *)Arena__alloc(arena,0x6c);
  *allocation = arena;
  FUN_001272cc(allocation + 1,param_1[2]);
  param_1[0xeb] = allocation + 1;
  arena = *(undefined4 *)(param_1[2] + 0x374);
  puVar2 = (undefined4 *)Arena__alloc(arena,0x20c);
  puVar2[1] = 0x80;
  iVar4 = 0x80;
  *puVar2 = arena;
  puVar2[2] = 0x1000;
  allocation = puVar2 + 1;
  do {
    allocation[2] = 0;
    allocation = allocation + 1;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  param_1[0xec] = puVar2 + 1;
  arena = *(undefined4 *)(param_1[2] + 0x374);
  puVar2 = (undefined4 *)Arena__alloc(arena,0x8c);
  puVar2[1] = 0x20;
  *puVar2 = arena;
  puVar2[2] = 0x400;
  iVar4 = 0x20;
  allocation = puVar2 + 1;
  do {
    allocation[2] = 0;
    allocation = allocation + 1;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  param_1[0xef] = puVar2 + 1;
  arena = *(undefined4 *)(param_1[2] + 0x374);
  allocation = (undefined4 *)Arena__alloc(arena,0x14);
  *allocation = arena;
  allocation[1] = 2;
  allocation[4] = arena;
  allocation[2] = 0;
  arena = Arena__alloc(arena,8);
  allocation[3] = arena;
  param_1[0xf1] = allocation + 1;
  arena = *(undefined4 *)(param_1[2] + 0x374);
  allocation = (undefined4 *)Arena__alloc(arena,0x14);
  *allocation = arena;
  allocation[1] = 2;
  allocation[2] = 0;
  allocation[4] = arena;
  arena = Arena__alloc(arena,8);
  allocation[3] = arena;
  iVar4 = 4;
  param_1[0xf2] = allocation + 1;
  allocation = param_1;
  do {
    allocation[4] = 0;
    allocation[8] = 0;
    allocation = allocation + 1;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  param_1[0xde] = 0;
  return;
}

/* FUN_000ee29c @ 0xee29c (1216 bytes) */
int FUN_000ee29c(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  undefined4 *allocation;
  undefined4 *puVar2;
  undefined4 arena;
  int iVar4;
  
  param_1[2] = param_2;
  *param_1 = 0;
  param_1[0xc] = 0;
  param_1[0x1f] = 0xffffffff;
  param_1[0x20] = 0xffffffff;
  param_1[0x21] = 0;
  param_1[0x22] = 0;
  param_1[0x23] = 0;
  param_1[0x24] = 0;
  param_1[0x25] = 0;
  param_1[0x26] = 0;
  param_1[0x27] = 0;
  param_1[0x28] = 0;
  param_1[0x29] = 0;
  param_1[0x2a] = 0;
  param_1[0x2b] = 0;
  param_1[0x2c] = 0;
  param_1[0x2d] = 0;
  param_1[0x2e] = 0;
  param_1[0x2f] = 0;
  param_1[0x30] = 0;
  param_1[0x31] = 0;
  param_1[0x32] = 0;
  param_1[0x33] = 0;
  param_1[0x34] = 0;
  param_1[0x35] = 0;
  param_1[0x36] = 0;
  param_1[0x37] = 0;
  param_1[0x38] = 0;
  param_1[0x39] = 0;
  param_1[0x3a] = 0;
  param_1[0x3b] = 0;
  param_1[0x3c] = 0;
  param_1[0x3d] = 0;
  param_1[0x3e] = 0;
  param_1[0x3f] = 0;
  param_1[0x40] = 0;
  param_1[0x41] = 0;
  param_1[0x42] = 0;
  param_1[0x43] = 0;
  param_1[0x44] = 0;
  param_1[0x45] = 0;
  param_1[0x46] = 0;
  param_1[0x47] = 0;
  param_1[0x48] = 0;
  param_1[0x49] = 0;
  param_1[0x4a] = 0;
  param_1[0x4b] = 0;
  param_1[0x4c] = 0;
  param_1[0x4d] = 0;
  param_1[0x4e] = 0;
  param_1[0x4f] = 0;
  param_1[0x50] = 0;
  param_1[0x51] = 0;
  param_1[0x52] = 0;
  param_1[0x53] = 0;
  param_1[0x54] = 0;
  param_1[0x55] = 0;
  param_1[0x56] = 0;
  param_1[0x57] = 0;
  param_1[0x58] = 0;
  param_1[0x59] = 0;
  param_1[0x5a] = 0;
  param_1[0x5b] = 0;
  param_1[0x5c] = 0;
  param_1[0x5d] = 0;
  param_1[0x5e] = 0;
  param_1[0x5f] = 0;
  param_1[0x60] = 0;
  param_1[0x61] = 0;
  param_1[0x62] = 0;
  param_1[99] = 0;
  param_1[100] = 0;
  param_1[0x65] = 0;
  param_1[0x66] = 0;
  param_1[0x67] = 0;
  param_1[0x68] = 0;
  param_1[0x69] = 0;
  param_1[0x6a] = 0;
  param_1[0x6b] = 0;
  param_1[0x6c] = 0;
  param_1[0x6d] = 0;
  param_1[0x6e] = 0;
  param_1[0x6f] = 0;
  param_1[0x70] = 0;
  param_1[0x71] = 0;
  param_1[0x72] = 0;
  param_1[0x73] = 0;
  param_1[0x74] = 0;
  param_1[0x75] = 0;
  param_1[0x76] = 0;
  param_1[0x77] = 0;
  param_1[0x78] = 0;
  param_1[0x79] = 0;
  param_1[0x7a] = 0;
  param_1[0x7b] = 0;
  param_1[0x7c] = 0;
  param_1[0x7d] = 0;
  param_1[0x7e] = 0;
  param_1[0x7f] = 0;
  param_1[0x80] = 0;
  param_1[0x81] = 0;
  param_1[0x82] = 0;
  param_1[0x83] = 0;
  param_1[0x84] = 0;
  param_1[0x85] = 0;
  param_1[0x86] = 0;
  param_1[0x87] = 0;
  param_1[0x88] = 0;
  param_1[0x89] = 0;
  param_1[0x8a] = 0;
  param_1[0x8b] = 0;
  param_1[0x8c] = 0;
  param_1[0x8d] = 0;
  param_1[0x8e] = 0;
  param_1[0x8f] = 0;
  param_1[0x90] = 0;
  param_1[0x91] = 0;
  param_1[0x92] = 0;
  param_1[0x93] = 0;
  param_1[0x94] = 0;
  param_1[0x95] = 0;
  param_1[0x96] = 0;
  param_1[0x97] = 0;
  param_1[0x98] = 0;
  param_1[0x99] = 0;
  param_1[0x9a] = 0;
  param_1[0x9b] = 0;
  param_1[0x9c] = 0;
  param_1[0x9d] = 0;
  param_1[0x9e] = 0;
  param_1[0x9f] = 0;
  param_1[0xa0] = 0;
  param_1[0xa1] = 0;
  param_1[0xa2] = 0;
  param_1[0xa3] = 0;
  param_1[0xa4] = 0;
  param_1[0xa5] = 0;
  param_1[0xa6] = 0;
  param_1[0xa7] = 0;
  param_1[0xa8] = 0;
  param_1[0xa9] = 0;
  param_1[0xaa] = 0;
  param_1[0xab] = 0;
  param_1[0xcc] = 0;
  param_1[0xce] = 0;
  param_1[0xcf] = 0;
  param_1[0xd1] = 0;
  param_1[0xd2] = 0;
  param_1[0xd3] = 0;
  param_1[0xd4] = 0;
  param_1[0xd6] = 0;
  param_1[0xd7] = 0;
  param_1[0xd8] = 0;
  param_1[0xd9] = 0;
  param_1[0xda] = 0;
  param_1[0xdd] = 0;
  DListNode__init(param_1 + 0xdf);
  iVar4 = 0x10;
  param_1[0xfa] = 0x7fffffff;
  param_1[0xfe] = 1;
  param_1[0xf6] = 0x7fffffff;
  param_1[0x10a] = 0xffffffff;
  param_1[0x11f] = 0;
  param_1[0xe5] = 0;
  param_1[0xe6] = 0;
  param_1[0xe7] = 0;
  param_1[0xe9] = 0;
  param_1[0xed] = 0;
  param_1[0xf0] = 0;
  param_1[0xf3] = 0;
  param_1[0xf5] = 0;
  param_1[0xf7] = 0xffffffff;
  param_1[0xf8] = 0;
  param_1[0xf9] = 0;
  param_1[0xfb] = 0xffffffff;
  param_1[0xfc] = 0;
  param_1[0x11d] = 0;
  param_1[0x11e] = 0;
  allocation = param_1;
  do {
    allocation[0xe] = 0;
    allocation = allocation + 1;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  iVar4 = 0x20;
  allocation = param_1;
  do {
    allocation[0xac] = 0;
    allocation = allocation + 1;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  arena = *(undefined4 *)(param_1[2] + 0x374);
  allocation = (undefined4 *)Arena__alloc(arena,0x6c);
  *allocation = arena;
  FUN_001272cc(allocation + 1,param_1[2]);
  param_1[0xeb] = allocation + 1;
  arena = *(undefined4 *)(param_1[2] + 0x374);
  puVar2 = (undefined4 *)Arena__alloc(arena,0x20c);
  puVar2[1] = 0x80;
  iVar4 = 0x80;
  *puVar2 = arena;
  puVar2[2] = 0x1000;
  allocation = puVar2 + 1;
  do {
    allocation[2] = 0;
    allocation = allocation + 1;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  param_1[0xec] = puVar2 + 1;
  arena = *(undefined4 *)(param_1[2] + 0x374);
  puVar2 = (undefined4 *)Arena__alloc(arena,0x8c);
  puVar2[1] = 0x20;
  *puVar2 = arena;
  puVar2[2] = 0x400;
  iVar4 = 0x20;
  allocation = puVar2 + 1;
  do {
    allocation[2] = 0;
    allocation = allocation + 1;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  param_1[0xef] = puVar2 + 1;
  arena = *(undefined4 *)(param_1[2] + 0x374);
  allocation = (undefined4 *)Arena__alloc(arena,0x14);
  *allocation = arena;
  allocation[1] = 2;
  allocation[4] = arena;
  allocation[2] = 0;
  arena = Arena__alloc(arena,8);
  allocation[3] = arena;
  param_1[0xf1] = allocation + 1;
  arena = *(undefined4 *)(param_1[2] + 0x374);
  allocation = (undefined4 *)Arena__alloc(arena,0x14);
  *allocation = arena;
  allocation[1] = 2;
  allocation[2] = 0;
  allocation[4] = arena;
  arena = Arena__alloc(arena,8);
  allocation[3] = arena;
  iVar4 = 4;
  param_1[0xf2] = allocation + 1;
  allocation = param_1;
  do {
    allocation[4] = 0;
    allocation[8] = 0;
    allocation = allocation + 1;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  param_1[0xde] = 0;
  return;
}

/* FUN_000ee7a0 @ 0xee7a0 (144 bytes) */
int FUN_000ee7a0(param_1)
  int param_1;
{
  int listCount;
  int loopIndex2;
  int iVar1;
  undefined4 *allocation;
  int *piVar3;
  int loopIndex;
  int iVar5;
  uint uVar6;
  undefined4 arena;
  uint *puVar8;
  int iVar9;
  int iVar10;
  int local_138 [69];
  
  iVar1 = *(int *)(param_1 + 8);
  if (-1 < *(int *)(*(int *)(iVar1 + 0x30c) + 0x4c)) {
    loopIndex2 = 0;
    piVar3 = local_138;
    do {
      arena = *(undefined4 *)(iVar1 + 0x378);
      allocation = (undefined4 *)Arena__alloc(arena,0x14);
      *allocation = arena;
      allocation[1] = 2;
      allocation[4] = arena;
      allocation[2] = 0;
      arena = Arena__alloc(arena,8);
      allocation[3] = arena;
      loopIndex2 = loopIndex2 + 1;
      *piVar3 = (int)(allocation + 1);
      piVar3 = piVar3 + 1;
      iVar1 = *(int *)(param_1 + 8);
    } while (loopIndex2 <= *(int *)(*(int *)(iVar1 + 0x30c) + 0x4c));
  }
  iVar1 = *(int *)(param_1 + 900);
  iVar5 = *(int *)(iVar1 + 8);
  while (iVar5 != 0) {
    puVar8 = (uint *)local_138[*(int *)(iVar1 + 0xb8)];
    uVar6 = puVar8[1];
    if (uVar6 < *puVar8) {
      _memset((void *)(uVar6 * 4 + puVar8[2]),0,4);
      piVar3 = (int *)(uVar6 * 4 + puVar8[2]);
      puVar8[1] = uVar6 + 1;
    }
    else {
      piVar3 = (int *)Vector__elementRefGrow(puVar8,uVar6);
    }
    *piVar3 = iVar1;
    iVar1 = *(int *)(iVar1 + 8);
    iVar5 = *(int *)(iVar1 + 8);
  }
  listCount = DList__count(param_1 + 0x37c);
  iVar5 = listCount + -1;
  arena = Arena__alloc(*(undefined4 *)(*(int *)(param_1 + 8) + 0x374),listCount * 4 + 4);
  iVar1 = *(int *)(param_1 + 8);
  *(undefined4 *)(param_1 + 0x39c) = arena;
  if (-1 < *(int *)(*(int *)(iVar1 + 0x30c) + 0x4c)) {
    loopIndex = 0;
    do {
      iVar10 = iVar5 << 2;
      iVar9 = local_138[loopIndex];
      uVar6 = *(uint *)(iVar9 + 4);
      if (uVar6 != 0) {
        do {
          iVar1 = *(int *)(param_1 + 0x39c);
          allocation = (undefined4 *)0x0;
          if (uVar6 - 1 < uVar6) {
            allocation = (undefined4 *)((uVar6 - 1) * 4 + *(int *)(iVar9 + 8));
          }
          arena = *allocation;
          iVar5 = iVar5 + -1;
          Vector__removeAt(iVar9,uVar6 - 1);
          *(undefined4 *)(iVar10 + iVar1) = arena;
          uVar6 = *(uint *)(iVar9 + 4);
          iVar10 = iVar10 + -4;
        } while (uVar6 != 0);
        iVar1 = *(int *)(param_1 + 8);
      }
      loopIndex = loopIndex + 1;
    } while (loopIndex <= *(int *)(*(int *)(iVar1 + 0x30c) + 0x4c));
  }
  return *(undefined4 *)(param_1 + 0x39c);
}

/* Program__addInst @ 0xee9ac (120 bytes) */
int Program__addInst(program, inst)
  int program;
  undefined4 inst;
{
  undefined4 *elementRef;
  uint count;
  uint *vectorHeader;
  
  vectorHeader = *(uint **)(program + PROG_instructionVector);
  count = vectorHeader[1];
  if (count < *vectorHeader) {
    _memset(count * 4 + vectorHeader[2],0,4);
    elementRef = (undefined4 *)(count * 4 + vectorHeader[2]);
    vectorHeader[1] = count + 1;
  }
  else {
    elementRef = (undefined4 *)Vector__elementRefGrow(vectorHeader,count);
  }
  *elementRef = inst;
  return;
}

/* FUN_000eea24 @ 0xeea24 (556 bytes) */
int FUN_000eea24(program)
  int program;
{
  int iVar1;
  int iVar2;
  int *a0;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  uint loopIndex;
  undefined4 uVar7;
  
  if (((*(uint *)(program + 0x30) & 1) != 0) &&
     (a0 = *(int **)(*(int *)(program + 8) + 0x30c), iVar3 = (**(code **)(*a0 + 0xe4))(a0),
     *(int *)(program + 0x3d4) != 0)) {
    if ((*(uint *)(*(int *)(*(int *)(program + 8) + 0x30c) + 8) & 0x2000) == 0) {
      iVar1 = iVar3;
      if ((*(int *)(program + 0x3e4) != 0) && (iVar1 = *(int *)(program + 0x3ec), iVar1 <= iVar3)) {
        iVar1 = iVar3 + 1;
      }
      iVar3 = *(int *)(program + 0x3d8);
      *(int *)(program + 0x3e0) = iVar1 - iVar3;
      if (iVar3 < *(int *)(program + 0x3dc)) {
        do {
          uVar7 = *(undefined4 *)(program + 0x3ac);
          uVar4 = ((int (*)())Program__registerFileOfIlType)(program,5);
          iVar1 = FUN_00127534(uVar7,uVar4,iVar3,0);
          if (iVar1 != 0) {
            iVar5 = 0;
            for (loopIndex = 1; loopIndex <= *(uint *)(*(int *)(iVar1 + 0x18) + 4); loopIndex = loopIndex + 1) {
              iVar2 = *(int *)(iVar5 + *(int *)(*(int *)(iVar1 + 0x18) + 8));
              if ((*(uint *)(iVar2 + 0x14) & 1) != 0) {
                *(uint *)(iVar2 + 0x14) = *(uint *)(iVar2 + 0x14) | 0x10;
                ((int (*)())Program__addInst)(program,iVar2);
              }
              iVar5 = iVar5 + 4;
            }
            *(int *)(iVar1 + 0x10) = iVar3 + *(int *)(program + 0x3e0);
            *(uint *)(iVar1 + 0x24) = *(uint *)(iVar1 + 0x24) | 2;
            Program__markHwRegUsed(program,iVar3 + *(int *)(program + 0x3e0));
            FUN_00130bd4(program,iVar3 + *(int *)(program + 0x3e0));
          }
          iVar3 = iVar3 + 1;
        } while (iVar3 < *(int *)(program + 0x3dc));
      }
    }
    else {
      iVar3 = *(int *)(program + 0x3d8);
      if (iVar3 < *(int *)(program + 0x3dc)) {
        do {
          uVar7 = *(undefined4 *)(program + 0x3ac);
          uVar4 = ((int (*)())Program__registerFileOfIlType)(program,5);
          iVar1 = FUN_00127534(uVar7,uVar4,iVar3,0);
          if (iVar1 != 0) {
            iVar5 = 0;
            for (loopIndex = 1; loopIndex <= *(uint *)(*(int *)(iVar1 + 0x18) + 4); loopIndex = loopIndex + 1) {
              iVar2 = *(int *)(iVar5 + *(int *)(*(int *)(iVar1 + 0x18) + 8));
              if ((*(uint *)(iVar2 + 0x14) & 1) != 0) {
                *(uint *)(iVar2 + 0x14) = *(uint *)(iVar2 + 0x14) | 0x10;
                ((int (*)())Program__addInst)(program,iVar2);
              }
              iVar5 = iVar5 + 4;
            }
          }
          iVar3 = iVar3 + 1;
        } while (iVar3 < *(int *)(program + 0x3dc));
      }
    }
  }
  return;
}

/* FUN_000eec50 @ 0xeec50 (1072 bytes) */
int FUN_000eec50(program, param_2)
  int program;
  undefined4 param_2;
{
  int operandRecord4;
  int operandRecord3;
  int newInst;
  int operandRecord2;
  int newInst2;
  int operandRecord;
  int *piVar1;
  int inst;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 *allocation;
  undefined4 arena;
  undefined4 uVar10;
  undefined4 *puVar11;
  int *piVar12;
  double dVar13;
  
  if (*(int *)(program + 0x3e4) != 0) {
    piVar12 = *(int **)(*(int *)(program + 0x3a0) + 0x98);
    for (piVar1 = (int *)piVar12[2]; piVar1 != (int *)0x0; piVar1 = (int *)piVar1[2]) {
      if ((piVar12[5] & 1U) != 0) {
        iVar7 = (**(code **)(*piVar12 + 0x4c))(piVar12);
        if (iVar7 != 0) {
          if ((((*(int *)(program + 0x3e4) != 0) && (piVar12[0x51] == *(int *)(program + 0x3f4))) &&
              (*(int *)(program + 1000) <= piVar12[0x52])) &&
             (piVar12[0x52] < *(int *)(program + 0x3ec))) {
            piVar12[5] = piVar12[5] | 0x10;
            ((int (*)())Program__addInst)(program,piVar12);
            piVar1 = (int *)piVar12[2];
            goto LAB_000eed14;
          }
        }
        piVar1 = (int *)piVar12[2];
      }
LAB_000eed14:
      piVar12 = piVar1;
    }
    *(int *)(program + 0x3f0) = -*(int *)(program + 1000);
  }
  if ((*(int *)(program + 0x348) == 0) && (*(int *)(program + 0x350) == 0)) {
    iVar7 = *(int *)(program + 0x34c);
    if (iVar7 != 0) goto LAB_000eee08;
    arena = *(undefined4 *)(*(int *)(program + 8) + 0x374);
    allocation = (undefined4 *)Arena__alloc(arena,0x168);
    *allocation = arena;
    puVar11 = allocation + 1;
    IRExport__ctor_108918(puVar11,*(undefined4 *)(program + 8));
    *(undefined4 **)(program + 0x348) = puVar11;
    operandRecord4 = IRInst__getOperandRecord(puVar11,0);
    arena = DAT_001aa800;
    dVar13 = (double)FLOAT_001aa0d4;
    *(undefined4 *)(operandRecord4 + 0xc) = 9;
    *(undefined4 *)(operandRecord4 + 8) = 0;
    allocation[0x28] = arena;
    ((void (*)())IRInst__makeLiteralVec4Float)(puVar11,program,1,dVar13,dVar13,dVar13,dVar13);
    Program__appendInst(program,puVar11,*(undefined4 *)(program + 0x3a8));
  }
  iVar7 = *(int *)(program + 0x34c);
  if (iVar7 == 0) {
    return;
  }
LAB_000eee08:
  if ((*(uint *)(*(int *)(*(int *)(program + 8) + 0x30c) + 8) & 0x4000) == 0) {
    return;
  }
  inst = IRInst__create(0x17,*(undefined4 *)(program + 8));
  IRInst__setOperandRef(inst,1,*(undefined4 *)(iVar7 + 0xa4));
  operandRecord = IRInst__getOperandRecord(iVar7,1);
  dVar13 = (double)FLOAT_001aa0d4;
  arena = *(undefined4 *)(operandRecord + 0x10);
  operandRecord = IRInst__getOperandRecord(inst,1);
  *(undefined4 *)(operandRecord + 0x10) = arena;
  ((void (*)())IRInst__makeLiteralVec4Float)(inst,program,2,0.5000000596046448,dVar13,dVar13,dVar13);
  arena = *(undefined4 *)(program + 0x3ac);
  iVar3 = *(int *)(*(int *)(program + 8) + 0x3ac) + -1;
  *(int *)(*(int *)(program + 8) + 0x3ac) = iVar3;
  uVar4 = FUN_00127608(arena,0,iVar3,0);
  IRInst__setOperandRef(inst,0,uVar4);
  arena = DAT_001aa800;
  *(undefined4 *)(inst + 0x120) = 1;
  *(undefined4 *)(inst + 0x9c) = arena;
  newInst2 = IRInst__create(0x13,*(undefined4 *)(program + 8));
  IRInst__setOperandRef(newInst2,1,*(undefined4 *)(iVar7 + 0xa4));
  operandRecord2 = IRInst__getOperandRecord(iVar7,1);
  uVar10 = *(undefined4 *)(operandRecord2 + 0x10);
  operandRecord2 = IRInst__getOperandRecord(newInst2,1);
  *(undefined4 *)(operandRecord2 + 0x10) = uVar10;
  ((void (*)())IRInst__makeLiteralVec4Float)(newInst2,program,2,0.9999999403953552,dVar13,dVar13,dVar13);
  uVar10 = *(undefined4 *)(program + 0x3ac);
  iVar5 = *(int *)(*(int *)(program + 8) + 0x3ac) + -1;
  *(int *)(*(int *)(program + 8) + 0x3ac) = iVar5;
  uVar10 = FUN_00127608(uVar10,0,iVar5,0);
  IRInst__setOperandRef(newInst2,0,uVar10);
  *(undefined4 *)(newInst2 + 0x120) = 1;
  *(undefined4 *)(newInst2 + 0x9c) = arena;
  newInst = IRInst__create(0x14,*(undefined4 *)(program + 8));
  IRInst__setOperandRef(newInst,1,uVar4);
  uVar4 = DAT_001aa810;
  operandRecord3 = IRInst__getOperandRecord(newInst,1);
  *(undefined4 *)(operandRecord3 + 0x10) = uVar4;
  ((void (*)())IRInst__makeLiteralVec4Float)(newInst,program,2,0.9999999403953552,dVar13,dVar13,dVar13);
  IRInst__setOperandRef(newInst,3,uVar10);
  operandRecord3 = IRInst__getOperandRecord(newInst,3);
  *(undefined4 *)(operandRecord3 + 0x10) = uVar4;
  uVar4 = *(undefined4 *)(program + 0x3ac);
  iVar6 = *(int *)(*(int *)(program + 8) + 0x3ac) + -1;
  *(int *)(*(int *)(program + 8) + 0x3ac) = iVar6;
  uVar4 = FUN_00127608(uVar4,0,iVar6,0);
  IRInst__setOperandRef(newInst,0,uVar4);
  *(undefined4 *)(newInst + 0x120) = 0;
  *(undefined4 *)(newInst + 0x9c) = arena;
  IRInst__setOperandRef(iVar7,1,uVar4);
  arena = *(undefined4 *)(iVar7 + 0x158);
  Block__insertInstBefore(arena,iVar7,newInst);
  Block__insertInstBefore(arena,newInst,newInst2);
  Block__insertInstBefore(arena,newInst2,inst);
  return;
}

/* FUN_000eee4c @ 0xeee4c (492 bytes) */
int FUN_000eee4c(program)
  int program;
{
  int operandRecord2;
  int operandRecord;
  int iVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  undefined4 *allocation;
  int iVar6;
  int *a0;
  int iVar7;
  int *piVar8;
  undefined4 arena;
  code *pcVar10;
  int iVar11;
  int *piVar12;
  
  iVar1 = *(int *)(program + 900);
  iVar3 = *(int *)(*(int *)(program + 900) + 8);
  do {
    if (iVar3 == 0) {
      return;
    }
    piVar2 = (int *)(*(int **)(iVar1 + 0x98))[2];
    piVar12 = *(int **)(iVar1 + 0x98);
    if (piVar2 != (int *)0x0) {
      do {
        piVar4 = piVar2;
        if ((piVar12[5] & 1U) != 0) {
          piVar2 = *(int **)(*(int *)(program + 8) + 0x30c);
          iVar3 = (**(code **)(*piVar2 + 0xcc))(piVar2);
          if (iVar3 == 0) {
            if (*(int *)(piVar12[0x22] + 8) == 0x77) {
              arena = FUN_00127608(*(undefined4 *)(program + 0x3ac),0x30,0,0);
              IRInst__setOperandRef(piVar12,0,arena);
              piVar12[5] = piVar12[5] | 0x10;
              FUN_0012306c(arena,piVar12);
              ((int (*)())Program__addInst)(program,piVar12);
            }
          }
          else if ((((piVar12[5] & 2U) != 0) && (iVar3 = FUN_0010406c(piVar12[0x26]), iVar3 == 9))
                  && (iVar3 = FUN_00127534(*(undefined4 *)(program + 0x3ac),0x21,0,0), iVar3 != 0))
          {
            IRInst__appendSource(piVar12,iVar3);
          }
          iVar3 = piVar12[0x26];
          if (iVar3 == 0x2a) {
            iVar3 = *(int *)(program + 1000);
            piVar2 = piVar12;
            if (iVar3 < *(int *)(program + 0x3ec)) {
              do {
                piVar4 = (int *)FUN_00127608(*(undefined4 *)(program + 0x3ac),
                                             *(undefined4 *)(program + 0x3f4),iVar3,0);
                arena = *(undefined4 *)(*(int *)(program + 8) + 0x374);
                allocation = (undefined4 *)Arena__alloc(arena,0x168);
                *allocation = arena;
                piVar8 = allocation + 1;
                IRProjection__ctor_109e28(piVar8,0x84,*(undefined4 *)(program + 8));
                allocation[0x4b] = iVar3;
                pcVar10 = *(code **)(*piVar4 + 0x28);
                operandRecord = IRInst__getOperandRecord(piVar12,0);
                iVar6 = (*pcVar10)(piVar4,*(undefined4 *)(operandRecord + 0x10),program);
                a0 = *(int **)(*(int *)(program + 8) + 0x30c);
                iVar7 = (**(code **)(*a0 + 0xd8))(a0);
                if (iVar7 != 0) {
                  *(int *)(iVar6 + 0x10) = iVar3;
                  *(uint *)(iVar6 + 0x24) = *(uint *)(iVar6 + 0x24) | 2;
                  Program__markHwRegUsed(program,iVar3);
                  FUN_00130bd4(program,iVar3);
                }
                iVar11 = piVar12[0x23];
                IRInst__setOperandRef(piVar8,0,iVar6);
                iVar3 = iVar3 + 1;
                operandRecord2 = IRInst__getOperandRecord(piVar12,0);
                allocation[0x28] = *(undefined4 *)(operandRecord2 + 0x10);
                FUN_0012306c(iVar6,piVar8);
                IRInst__setOperandRef(piVar8,1,iVar11);
                VReg__addUse(iVar11,1,piVar8);
                IRInst__appendSource(piVar8,iVar6);
                VReg__addUse(iVar6,2,piVar8);
                Block__insertInstAfter(iVar1,piVar2,piVar8);
                iVar6 = (**(code **)(*piVar4 + 0x2c))(piVar4);
                *(undefined4 *)(iVar6 + 0x144) = 1;
                piVar2 = piVar8;
              } while (iVar3 < *(int *)(program + 0x3ec));
              piVar4 = (int *)allocation[3];
            }
            else {
LAB_000ef1c8:
              piVar4 = (int *)piVar12[2];
            }
          }
          else {
            if ((piVar12[0x21] == 0) || ((iVar3 != 0x3b && (iVar3 != 0x2c)))) {
              if ((piVar12[0x20] == 0) ||
                 ((iVar3 = FUN_000f3154(piVar12), iVar3 == 0 ||
                  (iVar3 = (**(code **)(*piVar12 + 0x4c))(piVar12), iVar3 != 0))))
              goto LAB_000ef1c8;
              iVar3 = piVar12[0x23];
              IRInst__appendSource(piVar12,iVar3);
            }
            else {
              iVar3 = piVar12[0x23];
              iVar6 = piVar12[0x21] + 1;
              piVar12[0x21] = iVar6;
              IRInst__setOperandRef(piVar12,iVar6,iVar3);
            }
            VReg__addUse(iVar3,piVar12[0x21],piVar12);
            piVar4 = (int *)piVar12[2];
          }
        }
        piVar2 = (int *)piVar4[2];
        piVar12 = piVar4;
      } while ((int *)piVar4[2] != (int *)0x0);
      iVar3 = *(int *)(iVar1 + 8);
    }
    iVar1 = iVar3;
    iVar3 = *(int *)(iVar3 + 8);
  } while( true );
}

/* FUN_000ef204 @ 0xef204 (660 bytes) */
int FUN_000ef204(program)
  int program;
{
  int cloneResult;
  int splitIntoScalarExportsEnabled;
  int splitRgbAlphaExportsEnabled;
  int operandRecord2;
  int operandRecord;
  bool bVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int cloneResult2;
  int iVar7;
  uint uVar8;
  
  piVar3 = *(int **)(*(int *)(program + 8) + 0x30c);
  iVar4 = (**(code **)(*piVar3 + 0x16c))(piVar3);
  splitRgbAlphaExportsEnabled = Compiler__isOptionEnabled(*(undefined4 *)(program + 8),0x31);
  if (splitRgbAlphaExportsEnabled == 0) {
    splitIntoScalarExportsEnabled = Compiler__isOptionEnabled(*(undefined4 *)(program + 8),0x33);
    if (splitIntoScalarExportsEnabled != 0) {
      piVar3 = *(int **)(*(int *)(program + 0x3a8) + 0x98);
      for (piVar2 = (int *)piVar3[2]; piVar2 != (int *)0x0; piVar2 = (int *)piVar2[2]) {
        if ((piVar3[5] & 1U) != 0) {
          iVar5 = (**(code **)(*piVar3 + 0x68))(piVar3);
          if ((((iVar5 != 0) && (piVar3[0x26] != 7)) &&
              (*(int *)(*(int *)(piVar3[0x22] + 8) * 0x38 + iVar4 + 0x34) == 0)) &&
             (iVar5 = IRInst__countWrittenComponents(piVar3), 1 < iVar5)) {
            iVar7 = 0;
            piVar2 = (int *)PTR_DAT_001e8b64;
            do {
              operandRecord2 = IRInst__getOperandRecord(piVar3,0);
              if (*(char *)(iVar7 + operandRecord2 + 0x10) != '\x01') {
                if (iVar5 < 2) {
                  piVar3[0x27] = *piVar2;
                }
                else {
                  cloneResult2 = IRInst__clone(piVar3,*(undefined4 *)(program + 8),0);
                  *(int *)(cloneResult2 + 0x9c) = *piVar2;
                  Block__insertInstBefore(*(undefined4 *)(program + 0x3a8),piVar3,cloneResult2);
                  ((int (*)())Program__addInst)(program,cloneResult2);
                }
                iVar5 = iVar5 + -1;
              }
              bVar1 = iVar7 != 3;
              piVar2 = piVar2 + 1;
              iVar7 = iVar7 + 1;
            } while (bVar1);
          }
          piVar2 = (int *)piVar3[2];
        }
        piVar3 = piVar2;
      }
    }
  }
  else {
    piVar3 = *(int **)(*(int *)(program + 0x3a8) + 0x98);
    for (piVar2 = (int *)piVar3[2]; piVar2 != (int *)0x0; piVar2 = (int *)piVar2[2]) {
      if ((piVar3[5] & 1U) != 0) {
        iVar5 = (**(code **)(*piVar3 + 0x68))(piVar3);
        if (((iVar5 != 0) && (iVar5 = piVar3[0x26], iVar5 != 6)) &&
           ((iVar5 != 7 &&
            ((iVar5 != 0x2c && (*(int *)(*(int *)(piVar3[0x22] + 8) * 0x38 + iVar4 + 0x34) == 0)))))
           ) {
          operandRecord = IRInst__getOperandRecord(piVar3,0);
          uVar8 = *(uint *)(operandRecord + 0x10);
          iVar5 = FUN_000f2e18(uVar8);
          if (iVar5 == 0) {
            cloneResult = IRInst__clone(piVar3,*(undefined4 *)(program + 8),0);
            *(uint *)(cloneResult + 0x9c) = uVar8 & 0xffffff00 | 1;
            piVar3[0x27] = 0x1010100;
            Block__insertInstBefore(*(undefined4 *)(program + 0x3a8),piVar3,cloneResult);
            ((int (*)())Program__addInst)(program,cloneResult);
            piVar2 = (int *)piVar3[2];
            goto LAB_000ef344;
          }
        }
        piVar2 = (int *)piVar3[2];
      }
LAB_000ef344:
      piVar3 = piVar2;
    }
  }
  return;
}

/* FUN_000ef498 @ 0xef498 (860 bytes) */
int FUN_000ef498(program, ilReader)
  int program;
  undefined4 ilReader;
{
  uint loopIndex;
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 *allocation;
  undefined4 *puVar5;
  char *extraout_r4;
  undefined4 extraout_r4_00;
  char *pcVar6;
  int iVar7;
  int *piVar8;
  undefined4 arena;
  uint uVar10;
  uint uVar11;
  
  iVar7 = *(int *)(program + 8);
  piVar8 = *(int **)(iVar7 + 0x30c);
  iVar2 = (**(code **)(*piVar8 + 0x138))(piVar8,iVar7);
  iVar3 = (**(code **)(*piVar8 + 0x140))(piVar8,iVar7);
  iVar7 = (**(code **)(*piVar8 + 0x13c))(piVar8,iVar7);
  iVar7 = iVar2 + iVar3 + iVar7;
  arena = *(undefined4 *)(*(int *)(program + 8) + 0x374);
  uVar11 = iVar7 + 0x1fU >> 5;
  iVar2 = uVar11 * 4 + 0xc;
  allocation = (undefined4 *)Arena__alloc(arena,iVar2);
  piVar8 = allocation + 1;
  *allocation = arena;
  allocation[1] = uVar11;
  allocation[2] = iVar7;
  if (uVar11 != 0) {
    piVar1 = piVar8;
    uVar10 = uVar11;
    if (uVar11 == 0) {
      uVar10 = 1;
    }
    do {
      piVar1[2] = 0;
      piVar1 = piVar1 + 1;
      uVar10 = uVar10 - 1;
    } while (uVar10 != 0);
  }
  *(int **)(program + 0x42c) = piVar8;
  iVar3 = *piVar8;
  if (iVar3 != 0) {
    if (iVar3 == 0) {
      iVar3 = 1;
    }
    do {
      piVar8[2] = -1;
      piVar8 = piVar8 + 1;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  arena = *(undefined4 *)(*(int *)(program + 8) + 0x374);
  allocation = (undefined4 *)Arena__alloc(arena,iVar2);
  piVar8 = allocation + 1;
  *allocation = arena;
  allocation[1] = uVar11;
  allocation[2] = iVar7;
  if (uVar11 != 0) {
    piVar1 = piVar8;
    if (uVar11 == 0) {
      uVar11 = 1;
    }
    do {
      piVar1[2] = 0;
      piVar1 = piVar1 + 1;
      uVar11 = uVar11 - 1;
    } while (uVar11 != 0);
  }
  *(int **)(program + 0x430) = piVar8;
  iVar2 = *piVar8;
  if (iVar2 != 0) {
    if (iVar2 == 0) {
      iVar2 = 1;
    }
    do {
      piVar8[2] = -1;
      piVar8 = piVar8 + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  arena = *(undefined4 *)(*(int *)(program + 8) + 0x374);
  puVar5 = (undefined4 *)Arena__alloc(arena,0x8c);
  puVar5[1] = 0x20;
  iVar2 = 0x20;
  *puVar5 = arena;
  puVar5[2] = 0x400;
  allocation = puVar5 + 1;
  do {
    allocation[2] = 0;
    allocation = allocation + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  *(undefined4 **)(program + 0x434) = puVar5 + 1;
  *(undefined4 *)(program + 0x43c) = 0;
  piVar8 = *(int **)(*(int *)(program + 8) + 0x30c);
  iVar2 = (**(code **)(*piVar8 + 0x138))(piVar8,*(int *)(program + 8));
  *(int *)(program + 0x448) = iVar2;
  *(int *)(program + 0x440) = iVar2;
  piVar8 = *(int **)(*(int *)(program + 8) + 0x30c);
  iVar3 = (**(code **)(*piVar8 + 0x140))(piVar8,*(int *)(program + 8));
  iVar2 = iVar2 + iVar3;
  *(int *)(program + 0x44c) = iVar2;
  *(int *)(program + 0x444) = iVar2;
  piVar8 = *(int **)(*(int *)(program + 8) + 0x30c);
  iVar3 = (**(code **)(*piVar8 + 0x13c))(piVar8,*(int *)(program + 8));
  *(int *)(program + 0x450) = iVar2 + iVar3;
  arena = Arena__alloc(*(undefined4 *)(*(int *)(program + 8) + 0x374),
                       *(int *)(*(int *)(*(int *)(program + 8) + 0x30c) + 0x50) * 0xc);
  *(undefined4 *)(program + 0x78) = arena;
  arena = *(undefined4 *)(*(int *)(program + 8) + 0x374);
  allocation = (undefined4 *)Arena__alloc(arena,0x134);
  *allocation = arena;
  allocation = allocation + 1;
  EntryBlock__ctor_eab70(allocation,*(undefined4 *)(program + 8));
  *(undefined4 **)(program + 0x3a0) = allocation;
  ((int (*)())FUN_000ec3e8)(program,allocation);
  arena = *(undefined4 *)(*(int *)(program + 8) + 0x374);
  allocation = (undefined4 *)Arena__alloc(arena,0x130);
  *allocation = arena;
  allocation = allocation + 1;
  ExitBlock__ctor_eaae8(allocation,*(undefined4 *)(program + 8));
  *(undefined4 **)(program + 0x3a8) = allocation;
  ((int (*)())FUN_000ec42c)(program,allocation);
  FUN_00127994(*(undefined4 *)(program + 0x3ac),*(uint *)(program + 0x30) & 1);
  piVar8 = *(int **)(*(int *)(program + 8) + 0x30c);
  (**(code **)(*piVar8 + 0x10))(piVar8,*(int *)(program + 8));
  FUN_000fd5c8(program,ilReader);
  if ((*(uint *)(program + 0x30) & 1) == 0) {
    if ((*(uint *)(program + 0x30) & 0x2000) == 0) {
      arena = 2;
      iVar2 = 2;
    }
    else {
      arena = 1;
      iVar2 = 1;
    }
  }
  else {
    arena = 0;
    iVar2 = 0;
  }
  piVar8 = *(int **)(*(int *)(program + 8) + 0x30c);
  (**(code **)(*piVar8 + 0x14))(piVar8,arena,*(int *)(program + 8));
  if (iVar2 == 1) {
    ((int (*)())FUN_000eec50)(program,extraout_r4_00);
  }
  else if ((iVar2 == 2) || (iVar2 == 0)) {
    piVar8 = *(int **)(*(int *)(program + 8) + 0x30c);
    (**(code **)(*piVar8 + 0xac))(piVar8,*(undefined4 *)(program + 0x358),program,*(int *)(program + 8));
  }
  ((int (*)())FUN_000ef204)(program);
  FUN_0012eacc(program);
  ((int (*)())FUN_000eee4c)(program);
  ((int (*)())FUN_000eea24)(program);
  FUN_00138130(program);
  pcVar6 = "non_local_set";
  piVar8 = *(int **)(program + 900);
  iVar2 = piVar8[2];
  while (iVar2 != 0) {
    (**(code **)(*piVar8 + 0x48))(piVar8,pcVar6);
    piVar8 = (int *)piVar8[2];
    pcVar6 = extraout_r4;
    iVar2 = piVar8[2];
  }
  iVar2 = *(int *)(program + 0x3c4);
  iVar3 = 0;
  for (loopIndex = 1; loopIndex <= *(uint *)(iVar2 + 4); loopIndex = loopIndex + 1) {
    iVar7 = *(int *)(*(int *)(iVar2 + 8) + iVar3);
    if ((*(uint *)(iVar7 + 0x14) & 1) != 0) {
      IRInst__getOperandRecord(iVar7,0);
      iVar2 = *(int *)(program + 0x3c4);
    }
    iVar3 = iVar3 + 4;
  }
  return 1;
}

/* FUN_000ef8f8 @ 0xef8f8 (120 bytes) */
int FUN_000ef8f8(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  undefined4 *puVar1;
  uint uVar2;
  uint *puVar3;
  
  puVar3 = *(uint **)(param_1 + 0x3c8);
  uVar2 = puVar3[1];
  if (uVar2 < *puVar3) {
    _memset(uVar2 * 4 + puVar3[2],0,4);
    puVar1 = (undefined4 *)(uVar2 * 4 + puVar3[2]);
    puVar3[1] = uVar2 + 1;
  }
  else {
    puVar1 = (undefined4 *)Vector__elementRefGrow(puVar3,uVar2);
  }
  *puVar1 = param_2;
  return;
}

/* Program__removeInst @ 0xef970 (220 bytes) */
int Program__removeInst(program, inst)
  int program;
  int inst;
{
  uint count;
  int *elementRef;
  uint index;
  uint nextIndex;
  uint *vectorHeader;
  uint *vectorHeaderAlias;
  
  vectorHeader = *(uint **)(program + PROG_instructionVector);
  count = vectorHeader[1];
  if (count != 0) {
    index = 0;
    do {
      if (index < *vectorHeader) {
        vectorHeaderAlias = vectorHeader;
        if (count <= index) {
          _memset(count * 4 + vectorHeader[2],0,(index - count) * 4 + 4);
          vectorHeader[1] = index + 1;
          vectorHeaderAlias = *(uint **)(program + PROG_instructionVector);
        }
        elementRef = (int *)(index * 4 + vectorHeader[2]);
        vectorHeader = vectorHeaderAlias;
      }
      else {
        elementRef = (int *)Vector__elementRefGrow(vectorHeader,index);
        vectorHeader = *(uint **)(program + PROG_instructionVector);
      }
      nextIndex = index + 1;
      if (*elementRef == inst) {
        Vector__removeAt(vectorHeader,index);
        vectorHeader = *(uint **)(program + PROG_instructionVector);
      }
      count = vectorHeader[1];
      index = nextIndex;
    } while (nextIndex < count);
  }
  return;
}

/* FUN_000efa4c @ 0xefa4c (164 bytes) */
int FUN_000efa4c(program)
  int program;
{
  uint loopIndex;
  bool bVar1;
  int *piVar2;
  undefined4 *allocation;
  undefined4 *vectorAlloc;
  undefined4 *puVar5;
  int iVar6;
  uint *puVar7;
  int iVar8;
  uint *puVar9;
  undefined4 arena;
  uint uVar11;
  uint uVar12;
  int iVar13;
  
  arena = *(undefined4 *)(*(int *)(program + 8) + 0x378);
  allocation = (undefined4 *)Arena__alloc(arena,0x14);
  puVar9 = allocation + 1;
  *allocation = arena;
  allocation[1] = 2;
  allocation[2] = 0;
  allocation[4] = arena;
  arena = Arena__alloc(arena,8);
  allocation[3] = arena;
  arena = *(undefined4 *)(*(int *)(program + 8) + 0x378);
  vectorAlloc = (undefined4 *)Arena__alloc(arena,0x14);
  puVar7 = vectorAlloc + 1;
  *vectorAlloc = arena;
  vectorAlloc[1] = 2;
  vectorAlloc[2] = 0;
  vectorAlloc[4] = arena;
  arena = Arena__alloc(arena,8);
  vectorAlloc[3] = arena;
  iVar13 = *(int *)(program + 900);
  for (iVar6 = *(int *)(*(int *)(program + 900) + 8); iVar6 != 0; iVar6 = *(int *)(iVar6 + 8)) {
    *(undefined4 *)(iVar13 + 0x118) = 0;
    iVar13 = iVar6;
  }
  uVar11 = allocation[2];
  arena = *(undefined4 *)(program + 0x3a0);
  if (uVar11 < *puVar9) {
    _memset((void *)(uVar11 * 4 + allocation[3]),0,4);
    puVar5 = (undefined4 *)(uVar11 * 4 + allocation[3]);
    allocation[2] = uVar11 + 1;
  }
  else {
    puVar5 = (undefined4 *)Vector__elementRefGrow(puVar9,uVar11);
  }
  *puVar5 = arena;
  *(undefined4 *)(*(int *)(program + 0x3a0) + 0x118) = 1;
code_r0x000efd60:
  uVar11 = allocation[2];
  if (uVar11 == 0) {
    DList__initSentinel(program + 0x37c);
    iVar13 = vectorAlloc[2];
    while (iVar13 != 0) {
      allocation = (undefined4 *)0x0;
      if (iVar13 - 1U < (uint)vectorAlloc[2]) {
        allocation = (undefined4 *)((iVar13 - 1U) * 4 + vectorAlloc[3]);
      }
      arena = *allocation;
      Vector__removeAt(puVar7,vectorAlloc[2] - 1);
      DList__pushBack(program + 0x37c,arena);
      ((int (*)())Program__freeWorkArrays)(program);
      iVar13 = vectorAlloc[2];
    }
    return;
  }
  piVar2 = (int *)0x0;
  if (uVar11 - 1 < uVar11) {
    piVar2 = (int *)((uVar11 - 1) * 4 + allocation[3]);
  }
  iVar13 = *piVar2;
  Vector__removeAt(puVar9,uVar11 - 1);
  uVar11 = allocation[2];
  if (uVar11 < *puVar9) {
    _memset((void *)(uVar11 * 4 + allocation[3]),0,4);
    piVar2 = (int *)(uVar11 * 4 + allocation[3]);
    allocation[2] = uVar11 + 1;
  }
  else {
    piVar2 = (int *)Vector__elementRefGrow(puVar9,uVar11);
  }
  *piVar2 = iVar13;
  iVar6 = FUN_000e79e8(iVar13);
  if (iVar6 != 0) goto code_r0x000efc2c;
  goto code_r0x000efce4;
code_r0x000efc2c:
  bVar1 = true;
  iVar6 = 0;
  for (loopIndex = 1; loopIndex <= *(uint *)(*(int *)(iVar13 + 0xd0) + 4); loopIndex = loopIndex + 1) {
    iVar8 = *(int *)(iVar6 + *(int *)(*(int *)(iVar13 + 0xd0) + 8));
    if ((iVar8 != 0) && (*(int *)(iVar8 + 0x118) == 0)) {
      uVar12 = allocation[2];
      if (uVar12 < *puVar9) {
        _memset((void *)(uVar12 * 4 + allocation[3]),0,4);
        piVar2 = (int *)(uVar12 * 4 + allocation[3]);
        allocation[2] = uVar12 + 1;
      }
      else {
        piVar2 = (int *)Vector__elementRefGrow(puVar9,uVar12);
      }
      *piVar2 = iVar8;
      bVar1 = false;
      *(undefined4 *)(iVar8 + 0x118) = 1;
    }
    iVar6 = iVar6 + 4;
  }
  if (bVar1) {
code_r0x000efce4:
    uVar11 = allocation[2];
    puVar5 = (undefined4 *)0x0;
    if (uVar11 - 1 < uVar11) {
      puVar5 = (undefined4 *)((uVar11 - 1) * 4 + allocation[3]);
    }
    arena = *puVar5;
    Vector__removeAt(puVar9,uVar11 - 1);
    uVar11 = vectorAlloc[2];
    if (uVar11 < *puVar7) {
      _memset((void *)(uVar11 * 4 + vectorAlloc[3]),0,4);
      puVar5 = (undefined4 *)(uVar11 * 4 + vectorAlloc[3]);
      vectorAlloc[2] = uVar11 + 1;
    }
    else {
      puVar5 = (undefined4 *)Vector__elementRefGrow(puVar7,uVar11);
    }
    *puVar5 = arena;
  }
  goto code_r0x000efd60;
}

/* FUN_000efde4 @ 0xefde4 (536 bytes) */
int FUN_000efde4(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  uint loopIndex;
  int *piVar1;
  undefined4 *allocation;
  undefined4 *puVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint *puVar8;
  undefined4 arena;
  uint uVar10;
  
  if (((*(uint *)(param_1 + 0x30) & 1) == 0) && ((*(uint *)(param_1 + 0x30) & 0x2000) != 0)) {
    arena = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
    allocation = (undefined4 *)Arena__alloc(arena,0x168);
    *allocation = arena;
    allocation = allocation + 1;
    IRInst__ctor_10502c(allocation,0x95,*(undefined4 *)(param_1 + 8));
  }
  else {
    arena = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
    allocation = (undefined4 *)Arena__alloc(arena,0x168);
    *allocation = arena;
    allocation = allocation + 1;
    IRInst__ctor_10502c(allocation,0x96,*(undefined4 *)(param_1 + 8));
  }
  *(undefined4 **)(param_1 + 0x33c) = allocation;
  iVar5 = *(int *)(param_1 + 0x33c);
  *(undefined4 *)(iVar5 + 0x98) = 0x2d;
  *(undefined4 *)(iVar5 + 0x94) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x33c) + 300) = 0;
  iVar5 = *(int *)(param_1 + 0x3a8);
  *(uint *)(iVar5 + 0xc) = *(uint *)(iVar5 + 0xc) | 8;
  do {
    iVar7 = iVar5;
    iVar5 = *(int *)(iVar7 + 0xf0);
    if (iVar5 == 0) goto LAB_000eff14;
    *(uint *)(iVar7 + 0xc) = *(uint *)(iVar7 + 0xc) | 8;
    uVar6 = *(uint *)(iVar5 + 0xc);
  } while ((((uVar6 & 2) == 0) && ((uVar6 & 1) == 0)) && ((uVar6 & 4) == 0));
  if (*(int *)(*(int *)(iVar7 + 0xd4) + 4) == 1) {
    *(uint *)(iVar5 + 0xc) = uVar6 | 8;
    iVar7 = iVar5;
  }
LAB_000eff14:
  piVar4 = *(int **)(iVar7 + 0x98);
  piVar1 = (int *)(*(int **)(iVar7 + 0x98))[2];
  do {
    if (piVar1 == (int *)0x0) {
LAB_000eff98:
      *(uint *)(iVar7 + 0xc) = *(uint *)(iVar7 + 0xc) | 8;
      if (*(int *)(param_1 + 0x344) != 0) {
        (**(code **)(**(int **)(param_1 + 0x33c) + 0x94))
                  (*(int **)(param_1 + 0x33c),*(int *)(param_1 + 0x344),*(undefined4 *)(param_1 + 8)
                  );
      }
      arena = *(undefined4 *)(*(int *)(param_1 + 8) + 0x378);
      allocation = (undefined4 *)Arena__alloc(arena,0x14);
      puVar8 = allocation + 1;
      *allocation = arena;
      allocation[1] = 2;
      allocation[4] = arena;
      allocation[2] = 0;
      arena = Arena__alloc(arena,8);
      iVar5 = 0;
      allocation[3] = arena;
      for (loopIndex = 1; loopIndex <= *(uint *)(*(int *)(iVar7 + 0xf4) + 4); loopIndex = loopIndex + 1) {
        arena = *(undefined4 *)(*(int *)(*(int *)(iVar7 + 0xf4) + 8) + iVar5);
        uVar10 = allocation[2];
        if (uVar10 < *puVar8) {
          _memset((void *)(uVar10 * 4 + allocation[3]),0,4);
          puVar3 = (undefined4 *)(uVar10 * 4 + allocation[3]);
          allocation[2] = uVar10 + 1;
        }
        else {
          puVar3 = (undefined4 *)Vector__elementRefGrow(puVar8,uVar10);
        }
        iVar5 = iVar5 + 4;
        *puVar3 = arena;
      }
      while (allocation[2] != 0) {
        if (*puVar8 == 0) {
          piVar4 = (int *)Vector__elementRefGrow(puVar8,0);
        }
        else {
          piVar4 = (int *)allocation[3];
        }
        iVar7 = *piVar4;
        Vector__removeAt(puVar8,0);
        iVar5 = 0;
        *(uint *)(iVar7 + 0xc) = *(uint *)(iVar7 + 0xc) | 8;
        for (loopIndex = 1; loopIndex <= *(uint *)(*(int *)(iVar7 + 0xf4) + 4); loopIndex = loopIndex + 1) {
          arena = *(undefined4 *)(*(int *)(*(int *)(iVar7 + 0xf4) + 8) + iVar5);
          uVar10 = allocation[2];
          if (uVar10 < *puVar8) {
            _memset((void *)(uVar10 * 4 + allocation[3]),0,4);
            puVar3 = (undefined4 *)(uVar10 * 4 + allocation[3]);
            allocation[2] = uVar10 + 1;
          }
          else {
            puVar3 = (undefined4 *)Vector__elementRefGrow(puVar8,uVar10);
          }
          iVar5 = iVar5 + 4;
          *puVar3 = arena;
        }
      }
      return;
    }
    if ((piVar4[5] & 1U) != 0) {
      iVar5 = (**(code **)(*piVar4 + 0x7c))(piVar4);
      if ((iVar5 == 0) && (iVar5 = (**(code **)(*piVar4 + 0x34))(piVar4), iVar5 == 0)) {
        Block__insertInstBefore(iVar7,piVar4,*(undefined4 *)(param_1 + 0x33c));
        goto LAB_000eff98;
      }
      piVar1 = (int *)piVar4[2];
    }
    piVar4 = piVar1;
    piVar1 = (int *)piVar1[2];
  } while( true );
}

/* FUN_000f019c @ 0xf019c (292 bytes) */
int FUN_000f019c(param_1)
  int param_1;
{
  int sourceDef;
  int *operandVReg;
  uint loopIndex;
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined4 *allocation;
  int iVar5;
  undefined4 *puVar6;
  int *piVar7;
  int iVar8;
  uint *puVar9;
  uint *puVar10;
  int *piVar11;
  undefined4 arena;
  
  if (((*(uint *)(param_1 + 0x30) & 0x4000) != 0) && ((*(uint *)(param_1 + 0x30) & 0x80000) == 0)) {
    uVar3 = (*(uint **)(param_1 + 0x3c4))[1];
    if (uVar3 == 0) {
      iVar8 = 0;
    }
    else {
      loopIndex = 0;
      iVar8 = 0;
      puVar9 = *(uint **)(param_1 + 0x3c4);
      do {
        if (loopIndex < *puVar9) {
          puVar10 = puVar9;
          if (uVar3 <= loopIndex) {
            _memset(uVar3 * 4 + puVar9[2],0,(loopIndex - uVar3) * 4 + 4);
            puVar9[1] = loopIndex + 1;
            puVar10 = *(uint **)(param_1 + 0x3c4);
          }
          piVar7 = (int *)(loopIndex * 4 + puVar9[2]);
        }
        else {
          piVar7 = (int *)Vector__elementRefGrow(puVar9,loopIndex);
          puVar10 = *(uint **)(param_1 + 0x3c4);
        }
        loopIndex = loopIndex + 1;
        if (*(int *)(*piVar7 + 0x98) == 0x2c) {
          iVar8 = *piVar7;
        }
        uVar3 = puVar10[1];
        puVar9 = puVar10;
      } while (loopIndex < uVar3);
    }
    arena = *(undefined4 *)(*(int *)(param_1 + 8) + 0x378);
    allocation = (undefined4 *)Arena__alloc(arena,0x14);
    *allocation = arena;
    allocation[1] = 2;
    allocation[2] = 0;
    allocation[4] = arena;
    arena = Arena__alloc(arena,8);
    allocation[3] = arena;
    sourceDef = IRInst__getOperandSource(iVar8,1);
    while (*(int *)(sourceDef + 0x84) != 0) {
      iVar1 = *(int *)(*(int *)(sourceDef + 0x88) + 8);
      if ((iVar1 == 0xf7) || (iVar1 == 0x107)) {
        uVar3 = allocation[2];
        if (uVar3 < (uint)allocation[1]) {
          _memset(uVar3 * 4 + allocation[3],0,4);
          allocation[2] = uVar3 + 1;
          piVar7 = (int *)(uVar3 * 4 + allocation[3]);
        }
        else {
          piVar7 = (int *)Vector__elementRefGrow(allocation + 1,uVar3);
        }
        *piVar7 = sourceDef;
        sourceDef = IRInst__getOperandSource(sourceDef,1);
      }
      else if (iVar1 == 0xf9) {
        sourceDef = IRInst__getOperandSource(sourceDef,2);
      }
      else {
        if (iVar1 == 0x8e) {
          return;
        }
        sourceDef = IRInst__getOperandSource(sourceDef,1);
      }
    }
    uVar3 = allocation[2];
    if (*(int *)(param_1 + 0x3f8) < (int)uVar3) {
      uVar2 = uVar3 - *(int *)(param_1 + 0x3f8);
      puVar6 = (undefined4 *)0x0;
      if (uVar2 < uVar3) {
        puVar6 = (undefined4 *)(uVar2 * 4 + allocation[3]);
      }
      piVar11 = (int *)*puVar6;
      operandVReg = (int *)IRInst__getOperandSource(iVar8,1);
      while (piVar11 != operandVReg) {
        iVar5 = *(int *)(operandVReg[0x22] + 8);
        if (((iVar5 == 0xf7) || (iVar5 == 0x107)) || (iVar5 != 0xf9)) {
          (**(code **)(*operandVReg + 0xc))(operandVReg,0,*(undefined4 *)(param_1 + 8));
          operandVReg = (int *)IRInst__getOperandSource(operandVReg,1);
        }
        else {
          (**(code **)(*operandVReg + 0xc))(operandVReg,0,*(undefined4 *)(param_1 + 8));
          operandVReg = (int *)IRInst__getOperandSource(operandVReg,2);
        }
      }
      IRInst__setOperandSource(iVar8,1,piVar11,0,*(undefined4 *)(param_1 + 8));
      IRInst__setOperandSourceRaw(iVar8,2,piVar11,*(undefined4 *)(param_1 + 8));
      return;
    }
  }
  return;
}

/* FUN_000f04d4 @ 0xf04d4 (724 bytes) */
int FUN_000f04d4(param_1, inst)
  int param_1;
  int *inst;
{
  int operandRecord2;
  int operandRecord;
  int *operandVReg;
  bool bVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  float fVar6;
  uint uVar7;
  uint uVar8;
  
  iVar3 = (**(code **)(*inst + 0x68))(inst,inst);
  if ((iVar3 == 0) && (iVar3 = (**(code **)(*inst + 100))(inst), iVar3 != 0)) {
    for (iVar3 = 1; iVar4 = (**(code **)(*inst + 0x14))(inst), iVar3 <= iVar4;
        iVar3 = iVar3 + 1) {
      if ((((inst[iVar3 * 6 + 0x28] & 1U) != 0) || ((inst[iVar3 * 6 + 0x28] & 2U) != 0)) ||
         (iVar4 = IRInst__isSourceSelectIdentity(inst,iVar3), iVar4 == 0)) goto LAB_000f0628;
    }
    if ((inst[0x48] == 0) && (inst[0x49] == 0)) {
      if (((inst[0x20] != 0) &&
          ((iVar3 = RegKind__flagBit0(inst[0x26]), iVar3 != 0 && ((inst[5] & 2U) == 0)))) &&
         (iVar3 = (**(code **)(*inst + 0x50))(inst), iVar3 == 0)) {
        iVar3 = 4;
        piVar5 = inst;
        do {
          if ((uint)(*(byte *)(piVar5 + 0x27) - 2) < 2) goto LAB_000f0628;
          piVar5 = (int *)((int)piVar5 + 1);
          iVar3 = iVar3 + -1;
        } while (iVar3 != 0);
      }
      IRInst__getOperandRecord(inst,0);
      FUN_00105dbc(inst,0);
    }
  }
LAB_000f0628:
  operandVReg = (int *)IRInst__getOperandSource(inst,1);
  iVar3 = 0;
  uVar7 = 0xffffffff;
  bVar2 = true;
  fVar6 = 0.0;
  (**(code **)(*operandVReg + 0x48))(operandVReg);
  do {
    operandRecord2 = IRInst__getOperandRecord(inst,0);
    if (*(char *)(iVar3 + operandRecord2 + 0x10) != '\x01') {
      iVar4 = IRInst__getOperandRecord(inst,1);
      uVar8 = (uint)*(byte *)(iVar3 + iVar4 + 0x10);
      if ((((int)*(char *)(operandVReg + 0x57) >> (uVar8 & 0x3f) & 1U) == 0) ||
         (iVar4 = ((undefined4 (*)())isOutputScaleValue)((double)GH_U2F((unsigned int)(operandVReg[uVar8 * 6 + 8]))), iVar4 == 0)) {
        bVar2 = false;
      }
      else if (uVar7 == 0xffffffff) {
        fVar6 = GH_U2F((unsigned int)(operandVReg[uVar8 * 6 + 8]));
        uVar7 = uVar8;
      }
      else if (fVar6 != GH_U2F((unsigned int)(operandVReg[uVar8 * 6 + 8]))) {
        return 0;
      }
    }
    bVar1 = iVar3 != 3;
    iVar3 = iVar3 + 1;
  } while (bVar1);
  if (bVar2) {
    iVar3 = ((int (*)())outputScaleExponent)((double)GH_U2F((unsigned int)(operandVReg[uVar7 * 6 + 8])));
    piVar5 = *(int **)(*(int *)(param_1 + 8) + 0x30c);
    iVar4 = (**(code **)(*piVar5 + 0xfc))(piVar5,iVar3,inst);
    if (iVar4 != 0) {
      ((void (*)())IRInst__makeLiteralVec4Float)(inst,*(undefined4 *)(*(int *)(param_1 + 8) + 0x6c4),1,1.0,1.0,1.0,1.0);
      inst[0x49] = iVar3;
      operandRecord = IRInst__getOperandRecord(inst,1);
      *(undefined4 *)(operandRecord + 0x10) = 0x10203;
      return 1;
    }
  }
  return 0;
}

/* FUN_000f07a8 @ 0xf07a8 (464 bytes) */
int FUN_000f07a8(pass, afterInst, inst)
  int pass;
  undefined4 afterInst;
  int *inst;
{
  int operandRecord3;
  int operandRecord4;
  int operandRecord;
  int operandRecord2;
  int *operandVReg;
  bool bVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  undefined4 *allocation;
  undefined4 *vectorAlloc;
  undefined4 *puVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  uint *puVar11;
  uint *puVar12;
  uint uVar13;
  int *piVar14;
  int iVar15;
  undefined4 arena;
  int local_88;
  int local_84;
  int local_80;
  undefined4 local_7c;
  undefined1 auStack_78 [4];
  undefined4 local_74 [7];
  int local_58;
  int local_54;
  undefined4 local_50;
  int local_4c [6];
  
  piVar3 = *(int **)(*(int *)(pass + 8) + 0x30c);
  iVar4 = (**(code **)(*piVar3 + 0xb8))(piVar3,afterInst,inst);
  if ((((iVar4 == 0) && ((inst[5] & 8U) == 0)) &&
      (iVar4 = (**(code **)(*inst + 0x18))(inst), iVar4 < 2)) &&
     (iVar4 = (**(code **)(*inst + 0x14))(inst), iVar4 != 0)) {
    piVar3 = (int *)IRInst__getOperandSource(inst,1);
    iVar4 = (**(code **)(*inst + 0x68))(inst);
    if (((iVar4 != 0) || (iVar4 = (**(code **)(*inst + 100))(inst), iVar4 != 0)) &&
       (((inst[0x2e] & 1U) == 0 && ((inst[0x2e] & 2U) == 0)))) {
      operandRecord = IRInst__getOperandRecord(inst,1);
      arena = *(undefined4 *)(operandRecord + 0x10);
      operandRecord = IRInst__getOperandRecord(inst,0);
      WriteMask__fromSelectWord(&local_50,*(undefined4 *)(operandRecord + 0x10));
      SelectWord__maskUnused(local_4c,arena,local_50);
      local_88 = local_4c[0];
      iVar4 = ((int (*)())FUN_000ecc1c)(piVar3,local_4c[0],*(undefined4 *)(pass + 8));
      if (iVar4 != 0) {
        iVar4 = (**(code **)(*piVar3 + 0x60))(piVar3);
        if (iVar4 != 0) {
          piVar3 = (int *)FUN_0010cb48(piVar3,*(undefined4 *)(pass + 8));
          IRInst__setOperandSource(inst,1,piVar3,0,*(undefined4 *)(pass + 8));
        }
        iVar4 = inst[0x26];
        arena = *(undefined4 *)(*(int *)(pass + 8) + 0x378);
        iVar10 = inst[0x25];
        allocation = (undefined4 *)Arena__alloc(arena,0x14);
        puVar11 = allocation + 1;
        *allocation = arena;
        allocation[1] = 2;
        allocation[4] = arena;
        allocation[2] = 0;
        arena = Arena__alloc(arena,8);
        allocation[3] = arena;
        arena = *(undefined4 *)(*(int *)(pass + 8) + 0x378);
        vectorAlloc = (undefined4 *)Arena__alloc(arena,0x14);
        puVar12 = vectorAlloc + 1;
        *vectorAlloc = arena;
        vectorAlloc[1] = 2;
        vectorAlloc[2] = 0;
        vectorAlloc[4] = arena;
        arena = Arena__alloc(arena,8);
        uVar2 = allocation[1];
        uVar13 = allocation[2];
        vectorAlloc[3] = arena;
        if (uVar13 < uVar2) {
          _memset(uVar13 * 4 + allocation[3],0,4);
          allocation[2] = uVar13 + 1;
          puVar7 = (undefined4 *)(uVar13 * 4 + allocation[3]);
        }
        else {
          puVar7 = (undefined4 *)Vector__elementRefGrow(puVar11,uVar13);
        }
        iVar15 = local_88;
        *puVar7 = piVar3;
        uVar2 = vectorAlloc[2];
        if (uVar2 < *puVar12) {
          _memset(uVar2 * 4 + vectorAlloc[3],0,4);
          piVar3 = (int *)(uVar2 * 4 + vectorAlloc[3]);
          vectorAlloc[2] = uVar2 + 1;
        }
        else {
          piVar3 = (int *)Vector__elementRefGrow(puVar12,uVar2);
        }
        *piVar3 = iVar15;
        *(int *)(pass + 0x474) = *(int *)(pass + 0x474) + 1;
code_r0x000f1384:
        do {
          while( true ) {
            do {
              do {
                uVar2 = allocation[2];
                if (uVar2 == 0) {
                  (**(code **)(*inst + 0xc))(inst,0,*(undefined4 *)(pass + 8));
                  if (puVar11 != (uint *)0x0) {
                    Arena__free(allocation[4],allocation[3]);
                    Arena__free(*allocation,allocation);
                  }
                  if (puVar12 == (uint *)0x0) {
                    return;
                  }
                  Arena__free(vectorAlloc[4],vectorAlloc[3]);
                  Arena__free(*vectorAlloc,vectorAlloc);
                  return;
                }
                puVar7 = (undefined4 *)0x0;
                if (uVar2 - 1 < uVar2) {
                  puVar7 = (undefined4 *)((uVar2 - 1) * 4 + allocation[3]);
                }
                piVar3 = (int *)*puVar7;
                Vector__removeAt(puVar11,uVar2 - 1);
                uVar2 = vectorAlloc[2];
                piVar14 = (int *)0x0;
                if (uVar2 - 1 < uVar2) {
                  piVar14 = (int *)((uVar2 - 1) * 4 + vectorAlloc[3]);
                }
                iVar15 = *piVar14;
                Vector__removeAt(puVar12,uVar2 - 1);
                local_88 = iVar15;
                iVar15 = ((int (*)())FUN_000ecc1c)(piVar3,iVar15,*(undefined4 *)(pass + 8));
                if ((iVar15 != 0) && (iVar15 = (**(code **)(*piVar3 + 0x60))(piVar3), iVar15 != 0))
                {
                  piVar3 = (int *)FUN_0010cb48(piVar3,*(undefined4 *)(pass + 8));
                }
              } while ((*(int *)(pass + 0x474) == piVar3[0x54]) &&
                      (*(int *)(piVar3[0x22] + 8) == 0x8e));
              piVar3[0x54] = *(int *)(pass + 0x474);
              iVar15 = (**(code **)(*piVar3 + 0x50))(piVar3);
            } while (iVar15 != 0);
            local_80 = local_88;
            local_84 = local_88;
            operandRecord2 = IRInst__getOperandRecord(piVar3,0);
            iVar9 = 0;
            local_7c = *(undefined4 *)(operandRecord2 + 0x10);
            iVar15 = 4;
            do {
              if (*(byte *)((int)&local_88 + iVar9) != 4) {
                if (auStack_78[*(byte *)((int)&local_88 + iVar9) - 4] == '\x01') {
                  *(undefined1 *)((int)&local_84 + iVar9) = 4;
                }
                else {
                  *(undefined1 *)((int)&local_80 + iVar9) = 4;
                }
              }
              iVar8 = local_80;
              iVar9 = iVar9 + 1;
              iVar15 = iVar15 + -1;
            } while (iVar15 != 0);
            if (local_84 != 0x4040404) break;
            if (((piVar3[5] & 0x200U) != 0) && (local_80 != 0x4040404)) {
              uVar2 = vectorAlloc[2];
              if (uVar2 < *puVar12) {
                _memset(uVar2 * 4 + vectorAlloc[3],0,4);
                vectorAlloc[2] = uVar2 + 1;
                piVar14 = (int *)(uVar2 * 4 + vectorAlloc[3]);
              }
              else {
                piVar14 = (int *)Vector__elementRefGrow(puVar12,uVar2);
              }
              *piVar14 = iVar8;
              arena = IRInst__getOperandSource(piVar3,piVar3[0x21]);
              uVar2 = allocation[2];
              if (uVar2 < *puVar11) {
                _memset(uVar2 * 4 + allocation[3],0,4);
                allocation[2] = uVar2 + 1;
                puVar7 = (undefined4 *)(uVar2 * 4 + allocation[3]);
              }
              else {
                puVar7 = (undefined4 *)Vector__elementRefGrow(puVar11,uVar2);
              }
              *puVar7 = arena;
            }
          }
          iVar15 = ((int (*)())FUN_000ecc1c)(piVar3,local_84,*(undefined4 *)(pass + 8));
          if (iVar15 != 0) {
            iVar9 = (**(code **)(*piVar3 + 0x7c))(piVar3);
            iVar15 = local_80;
            if (iVar9 == 0) {
              if (((piVar3[5] & 0x200U) != 0) && (local_80 != 0x4040404)) {
                uVar2 = vectorAlloc[2];
                if (uVar2 < *puVar12) {
                  _memset(uVar2 * 4 + vectorAlloc[3],0,4);
                  vectorAlloc[2] = uVar2 + 1;
                  piVar14 = (int *)(uVar2 * 4 + vectorAlloc[3]);
                }
                else {
                  piVar14 = (int *)Vector__elementRefGrow(puVar12,uVar2);
                }
                *piVar14 = iVar15;
                arena = IRInst__getOperandSource(piVar3,piVar3[0x21]);
                uVar2 = allocation[2];
                if (uVar2 < *puVar11) {
                  _memset(uVar2 * 4 + allocation[3],0,4);
                  allocation[2] = uVar2 + 1;
                  puVar7 = (undefined4 *)(uVar2 * 4 + allocation[3]);
                }
                else {
                  puVar7 = (undefined4 *)Vector__elementRefGrow(puVar11,uVar2);
                }
                *puVar7 = arena;
                IRInst__setOperandSource(piVar3,piVar3[0x21],0,0,*(undefined4 *)(pass + 8));
                piVar3[0x21] = piVar3[0x21] + -1;
                piVar3[5] = piVar3[5] & 0xfffffdff;
              }
              iVar15 = (**(code **)(*piVar3 + 100))(piVar3);
              if (iVar15 != 0) {
                for (iVar15 = 1; iVar9 = (**(code **)(*piVar3 + 0x14))(piVar3), iVar15 <= iVar9;
                    iVar15 = iVar15 + 1) {
                  if ((((piVar3[iVar15 * 6 + 0x28] & 1U) != 0) ||
                      ((piVar3[iVar15 * 6 + 0x28] & 2U) != 0)) ||
                     (iVar9 = IRInst__isSourceSelectIdentity(piVar3,iVar15), iVar9 == 0)) goto code_r0x000f101c;
                }
                if ((piVar3[0x48] == 0) && (piVar3[0x49] == 0)) {
                  if (((piVar3[0x20] != 0) &&
                      ((iVar15 = RegKind__flagBit0(piVar3[0x26]), iVar15 != 0 && ((piVar3[5] & 2U) == 0))
                      )) && (iVar15 = (**(code **)(*piVar3 + 0x50))(piVar3), iVar15 == 0)) {
                    iVar15 = 4;
                    piVar14 = piVar3;
                    do {
                      if ((uint)(*(byte *)(piVar14 + 0x27) - 2) < 2) goto code_r0x000f101c;
                      piVar14 = (int *)((int)piVar14 + 1);
                      iVar15 = iVar15 + -1;
                    } while (iVar15 != 0);
                  }
                  IRInst__getOperandRecord(piVar3,0);
                  iVar15 = FUN_00105dbc(piVar3,0);
                  if ((iVar15 == 0) && ((piVar3[5] & 2U) == 0)) {
                    arena = IRInst__getOperandSource(piVar3,1);
                    iVar9 = ((int (*)())FUN_000ecc1c)(arena,local_84,*(undefined4 *)(pass + 8));
                    iVar15 = local_84;
                    if (iVar9 != 0) {
                      uVar2 = vectorAlloc[2];
                      if (uVar2 < *puVar12) {
                        _memset(uVar2 * 4 + vectorAlloc[3],0,4);
                        vectorAlloc[2] = uVar2 + 1;
                        piVar14 = (int *)(uVar2 * 4 + vectorAlloc[3]);
                      }
                      else {
                        piVar14 = (int *)Vector__elementRefGrow(puVar12,uVar2);
                      }
                      *piVar14 = iVar15;
                      arena = IRInst__getOperandSource(piVar3,1);
                      uVar2 = allocation[2];
                      if (uVar2 < *puVar11) {
                        _memset(uVar2 * 4 + allocation[3],0,4);
                        allocation[2] = uVar2 + 1;
                        puVar7 = (undefined4 *)(uVar2 * 4 + allocation[3]);
                      }
                      else {
                        puVar7 = (undefined4 *)Vector__elementRefGrow(puVar11,uVar2);
                      }
                      *puVar7 = arena;
                      goto code_r0x000f1140;
                    }
                  }
                }
              }
code_r0x000f101c:
              IRInst__setHardwareRegisterAndAdd(piVar3,pass,iVar4,iVar10);
              (**(code **)(*piVar3 + 0x94))(piVar3,afterInst,*(undefined4 *)(pass + 8));
              SelectWord__clearReadComponents(&local_58,local_84);
              piVar3[0x27] = local_58;
              iVar15 = SelectWord__areCompatible(local_84,0x10203);
              if ((iVar15 == 0) &&
                 (iVar15 = FUN_0011379c(*(undefined4 *)(pass + 8),piVar3), iVar15 != 0)) {
                for (iVar15 = 1; iVar9 = (**(code **)(*piVar3 + 0x14))(piVar3), iVar15 <= iVar9;
                    iVar15 = iVar15 + 1) {
                  operandRecord3 = IRInst__getOperandRecord(piVar3,iVar15);
                  ((int (*)())SelectWord__compose)(&local_54,*(undefined4 *)(operandRecord3 + 0x10),local_84);
                  iVar9 = local_54;
                  if (iVar15 == 0) {
                    piVar3[0x27] = local_54;
                  }
                  else {
                    operandRecord4 = IRInst__getOperandRecord(piVar3,iVar15);
                    *(int *)(operandRecord4 + 0x10) = iVar9;
                  }
                }
              }
              iVar15 = (**(code **)(*piVar3 + 100))(piVar3);
              if (iVar15 != 0) {
                for (iVar15 = 1; iVar9 = (**(code **)(*piVar3 + 0x14))(piVar3), iVar15 <= iVar9;
                    iVar15 = iVar15 + 1) {
                  if ((((piVar3[iVar15 * 6 + 0x28] & 1U) != 0) ||
                      ((piVar3[iVar15 * 6 + 0x28] & 2U) != 0)) ||
                     (iVar9 = IRInst__isSourceSelectIdentity(piVar3,iVar15), iVar9 == 0)) goto code_r0x000f1384;
                }
                if ((piVar3[0x48] == 0) && (piVar3[0x49] == 0)) {
                  if (((piVar3[0x20] != 0) &&
                      ((iVar15 = RegKind__flagBit0(piVar3[0x26]), iVar15 != 0 && ((piVar3[5] & 2U) == 0))
                      )) && (iVar15 = (**(code **)(*piVar3 + 0x50))(piVar3), iVar15 == 0)) {
                    iVar15 = 4;
                    piVar14 = piVar3;
                    do {
                      if ((uint)(*(byte *)(piVar14 + 0x27) - 2) < 2) goto code_r0x000f1384;
                      piVar14 = (int *)((int)piVar14 + 1);
                      iVar15 = iVar15 + -1;
                    } while (iVar15 != 0);
                  }
                  IRInst__getOperandRecord(piVar3,0);
                  iVar15 = FUN_00105dbc(piVar3,0);
                  if (iVar15 == 0) {
                    operandVReg = (int *)IRInst__getOperandSource(piVar3,1);
                    iVar15 = (**(code **)(*operandVReg + 0x48))();
                    if (iVar15 != 0) {
                      iVar15 = 4;
                      puVar7 = local_74;
                      do {
                        *puVar7 = 0x7ffffffe;
                        puVar7 = puVar7 + 1;
                        iVar15 = iVar15 + -1;
                      } while (iVar15 != 0);
                      local_74[0] = 0x3f800000;
                      local_74[3] = 0x3f800000;
                      local_74[2] = 0x3f800000;
                      local_74[1] = 0x3f800000;
                      piVar14 = *(int **)(*(int *)(pass + 8) + 0x30c);
                      iVar15 = (**(code **)(*piVar14 + 0xe8))(piVar14,local_74,auStack_78,0x10203);
                      if (iVar15 != 0) {
                        ((int (*)())FUN_000f04d4)(pass,piVar3);
                      }
                    }
                  }
                }
              }
            }
            else {
              iVar15 = piVar3[0x21];
              if (0 < iVar15) {
                iVar9 = 1;
                bVar1 = true;
                do {
                  operandVReg = (int *)IRInst__getOperandSource(piVar3,iVar9);
                  iVar15 = (**(code **)(*operandVReg + 0x7c))();
                  if ((iVar15 != 0) ||
                     (iVar15 = ((int (*)())FUN_000ecc1c)(operandVReg,local_84,*(undefined4 *)(pass + 8)),
                     iVar15 == 0)) {
                    bVar1 = false;
                  }
                  iVar15 = piVar3[0x21];
                  iVar9 = iVar9 + 1;
                } while (iVar9 <= iVar15);
                if (!bVar1) goto code_r0x000f0d0c;
              }
              iVar9 = 1;
              if (0 < iVar15) {
                do {
                  iVar15 = local_88;
                  uVar2 = vectorAlloc[2];
                  if (uVar2 < *puVar12) {
                    _memset(uVar2 * 4 + vectorAlloc[3],0,4);
                    vectorAlloc[2] = uVar2 + 1;
                    piVar14 = (int *)(uVar2 * 4 + vectorAlloc[3]);
                  }
                  else {
                    piVar14 = (int *)Vector__elementRefGrow(puVar12,uVar2);
                  }
                  *piVar14 = iVar15;
                  arena = IRInst__getOperandSource(piVar3,iVar9);
                  uVar2 = allocation[2];
                  if (uVar2 < *puVar11) {
                    _memset(uVar2 * 4 + allocation[3],0,4);
                    allocation[2] = uVar2 + 1;
                    puVar7 = (undefined4 *)(uVar2 * 4 + allocation[3]);
                  }
                  else {
                    puVar7 = (undefined4 *)Vector__elementRefGrow(puVar11,uVar2);
                  }
                  *puVar7 = arena;
                  iVar9 = iVar9 + 1;
                } while (iVar9 <= piVar3[0x21]);
              }
code_r0x000f1140:
              (**(code **)(*piVar3 + 0xc))(piVar3,0,*(undefined4 *)(pass + 8));
            }
            goto code_r0x000f1384;
          }
code_r0x000f0d0c:
          ((int (*)())FUN_000ecd28)(pass,piVar3,afterInst,iVar4,iVar10,local_88);
        } while( true );
      }
    }
  }
  return (**(code **)(*inst + 0x94))(inst,afterInst,*(undefined4 *)(pass + 8));
}

/* FUN_000f14f8 @ 0xf14f8 (132 bytes) */
int FUN_000f14f8(program, inst, inst2)
  int program;
  int *inst;
  int *inst2;
{
  int allocPlacementEnabled;
  int operandRecord4;
  int operandRecord2;
  int operandRecord;
  int operandRecord3;
  int *operandVReg2;
  bool bVar1;
  code *UNRECOVERED_JUMPTABLE;
  uint uVar2;
  undefined4 *allocation;
  int iVar4;
  int *piVar5;
  int iVar6;
  int *operandVReg;
  int *piVar8;
  int iVar9;
  int *piVar10;
  undefined4 uVar11;
  int iVar12;
  undefined4 uVar13;
  undefined4 arena;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38 [3];
  
  arena = *(undefined4 *)(*(int *)(program + 8) + 0x374);
  allocation = (undefined4 *)Arena__alloc(arena,0x168);
  *allocation = arena;
  IRInst__ctor_10502c(allocation + 1,0x93,*(undefined4 *)(program + 8));
  *(undefined4 **)(program + 0x340) = allocation + 1;
  allocation[0x27] = 0x2e;
  allocation[0x26] = 0;
  *(undefined4 *)(*(int *)(program + 0x340) + 300) = 0;
  allocPlacementEnabled = Compiler__isOptionEnabled(*(undefined4 *)(program + 8),0x23);
  if (allocPlacementEnabled == 0) {
    if (((*(uint *)(program + 0x30) & 1) != 0) && (inst != (int *)0x0)) {
      Block__prependInst(inst[0x56],*(undefined4 *)(program + 0x340));
      (**(code **)(*inst + 0x94))
                (inst,*(undefined4 *)(program + 0x340),*(undefined4 *)(program + 8));
      if (inst2 != (int *)0x0) {
        *(undefined4 *)(*(int *)(program + 0x340) + 300) = 1;
        uVar11 = *(undefined4 *)(program + 8);
        UNRECOVERED_JUMPTABLE = *(code **)(*inst2 + 0x94);
        arena = *(undefined4 *)(program + 0x340);
        inst = inst2;
        goto LAB_000f1940;
      }
    }
  }
  else if (((*(uint *)(program + 0x30) & 1) != 0) && (inst != (int *)0x0)) {
    iVar4 = inst[0x56];
    if (inst2 == (int *)0x0) {
      piVar5 = (int *)IRInst__getOperandSource(inst,1);
      operandRecord2 = IRInst__getOperandRecord(inst,1);
      iVar12 = *(int *)(operandRecord2 + 0x10);
      iVar6 = (**(code **)(**(int **)(*(int *)(program + 8) + 0x30c) + 0xb8))();
      if (((iVar6 == 0) && (iVar6 = (**(code **)(*piVar5 + 0x7c))(piVar5), iVar6 == 0)) &&
         ((((iVar6 = FUN_0011379c(*(undefined4 *)(program + 8),piVar5), iVar6 != 0 &&
            ((iVar6 = piVar5[0x58] - *(int *)(program + 0x478), iVar6 < 0 || (iVar6 < 2)))) &&
           (iVar6 = (**(code **)(*piVar5 + 0x28))(piVar5), iVar6 == 0)) &&
          ((piVar5[0x21] != 0 && (iVar12 == DAT_001aa804)))))) {
        operandRecord = IRInst__getOperandRecord(inst,0);
        arena = *(undefined4 *)(operandRecord + 0x10);
        ((int (*)())Program__removeInst)(program,inst);
        (**(code **)(*inst + 0xc))(inst,0,*(undefined4 *)(program + 8));
        iVar6 = piVar5[0x56];
        IRInst__setHardwareRegisterAndAdd(piVar5,program,6,0);
        (**(code **)(*piVar5 + 0x94))
                  (piVar5,*(undefined4 *)(program + 0x340),*(undefined4 *)(program + 8));
        operandRecord = IRInst__getOperandRecord(piVar5,0);
        FUN_000f302c(&local_44,arena,*(undefined4 *)(operandRecord + 0x10));
        uVar2 = piVar5[5];
        iVar4 = local_44;
        do {
          if ((uVar2 & 0x200) == 0) {
code_r0x000e76c4:
            iVar4 = *(int *)(program + 0x340);
            DList__insertAfter(iVar4,*(undefined4 *)(iVar6 + 200));
            *(int *)(iVar4 + 0x158) = iVar6;
            return;
          }
          operandVReg = (int *)IRInst__getOperandSource(piVar5,piVar5[0x21]);
          IRInst__setOperandSource(piVar5,piVar5[0x21],0,0,*(undefined4 *)(program + 8));
          iVar12 = *operandVReg;
          piVar5[0x21] = piVar5[0x21] + -1;
          piVar5[5] = piVar5[5] & 0xfffffdff;
          iVar12 = (**(code **)(iVar12 + 0x7c))(operandVReg);
          if ((((iVar12 != 0) ||
               (iVar12 = FUN_0011379c(*(undefined4 *)(program + 8),operandVReg), iVar12 == 0)) ||
              ((iVar12 = operandVReg[0x58] - *(int *)(program + 0x478), -1 < iVar12 && (1 < iVar12)))) ||
             (((iVar6 != operandVReg[0x56] ||
               (iVar12 = (**(code **)(*operandVReg + 0x28))(operandVReg), iVar12 != 0)) || (operandVReg[0x21] == 0)
              ))) {
            piVar8 = (int *)FUN_001084b8(0x31,*(undefined4 *)(program + 8));
            IRInst__setOperandSource(piVar8,1,operandVReg,0,*(undefined4 *)(program + 8));
            (**(code **)(*piVar8 + 0x94))
                      (piVar8,*(undefined4 *)(program + 0x340),*(undefined4 *)(program + 8));
            IRInst__setHardwareRegisterAndAdd(piVar8,program,6,0);
            piVar8[0x27] = iVar4;
            Block__insertInstBefore(iVar6,piVar5,piVar8);
            goto code_r0x000e76c4;
          }
          (**(code **)(*operandVReg + 0x94))
                    (operandVReg,*(undefined4 *)(program + 0x340),*(undefined4 *)(program + 8));
          IRInst__setHardwareRegisterAndAdd(operandVReg,program,6,0);
          operandRecord3 = IRInst__getOperandRecord(operandVReg,0);
          FUN_000f302c(&local_40,iVar4,*(undefined4 *)(operandRecord3 + 0x10));
          uVar2 = operandVReg[5];
          piVar5 = operandVReg;
          iVar4 = local_40;
        } while( true );
      }
      FUN_000e8424(iVar4,*(undefined4 *)(program + 0x340));
      uVar11 = *(undefined4 *)(program + 8);
      UNRECOVERED_JUMPTABLE = *(code **)(*inst + 0x94);
      arena = *(undefined4 *)(program + 0x340);
    }
    else {
      *(undefined4 *)(*(int *)(program + 0x340) + 300) = 1;
      piVar5 = (int *)IRInst__getOperandSource(inst,1);
      operandVReg = (int *)IRInst__getOperandSource(inst2,1);
      if ((((piVar5[0x56] == operandVReg[0x56]) &&
           (iVar6 = (**(code **)(*piVar5 + 0x7c))(piVar5), iVar6 == 0)) &&
          (iVar6 = (**(code **)(*operandVReg + 0x7c))(operandVReg), iVar6 == 0)) &&
         ((piVar5[0x21] != 0 && (operandVReg[0x21] != 0)))) {
        uVar2 = (uint)(1 < *(int *)(program + 0x478));
        if (((((int)(piVar5[0x58] - uVar2) < 0) || (piVar5[0x58] == uVar2)) &&
            (((iVar6 = operandVReg[0x58] - *(int *)(program + 0x478), iVar6 < 0 || (iVar6 < 2)) &&
             (iVar6 = (**(code **)(*piVar5 + 0x28))(piVar5), iVar6 == 0)))) &&
           (iVar6 = (**(code **)(*operandVReg + 0x28))(operandVReg), iVar6 == 0)) {
          iVar6 = piVar5[0x56];
          operandRecord = IRInst__getOperandRecord(inst,0);
          uVar13 = *(undefined4 *)(operandRecord + 0x10);
          arena = 6;
          operandRecord = IRInst__getOperandRecord(inst2,0);
          uVar11 = *(undefined4 *)(operandRecord + 0x10);
          ((int (*)())Program__removeInst)(program,inst2);
          iVar12 = 0;
          ((int (*)())Program__removeInst)(program,inst);
          (**(code **)(*inst + 0xc))(inst,0,*(undefined4 *)(program + 8));
          (**(code **)(*inst2 + 0xc))(inst2,0,*(undefined4 *)(program + 8));
          Block__prependInst(iVar6,*(undefined4 *)(program + 0x340));
          operandRecord = IRInst__getOperandRecord(piVar5,0);
          FUN_000f302c(&local_3c,uVar13,*(undefined4 *)(operandRecord + 0x10));
          do {
            (**(code **)(*piVar5 + 0x94))
                      (piVar5,*(undefined4 *)(program + 0x340),*(undefined4 *)(program + 8));
            IRInst__setHardwareRegisterAndAdd(piVar5,program,arena,0);
            uVar2 = piVar5[5];
            iVar4 = local_3c;
            while ((uVar2 & 0x200) != 0) {
              operandVReg2 = (int *)IRInst__getOperandSource(piVar5,piVar5[0x21]);
              iVar9 = (**(code **)(*operandVReg2 + 0x7c))();
              if ((((iVar9 != 0) ||
                   (iVar9 = FUN_0011379c(*(undefined4 *)(program + 8),operandVReg2), iVar9 == 0)) ||
                  ((iVar9 = operandVReg2[0x58] - *(int *)(program + 0x478), -1 < iVar9 && (1 < iVar9))))
                 || (((iVar6 != operandVReg2[0x56] ||
                      (iVar9 = (**(code **)(*operandVReg2 + 0x28))(operandVReg2), iVar9 != 0)) ||
                     (operandVReg2[0x21] == 0)))) {
                piVar10 = (int *)FUN_001084b8(0x31,*(undefined4 *)(program + 8));
                IRInst__setOperandSource(piVar10,1,operandVReg2,0,*(undefined4 *)(program + 8));
                IRInst__setHardwareRegisterAndAdd(piVar10,program,arena,0);
                (**(code **)(*piVar10 + 0x94))
                          (piVar10,*(undefined4 *)(program + 0x340),*(undefined4 *)(program + 8));
                piVar10[0x27] = iVar4;
                Block__insertInstBefore(iVar6,piVar5,piVar10);
                break;
              }
              (**(code **)(*operandVReg2 + 0x94))
                        (operandVReg2,*(undefined4 *)(program + 0x340),*(undefined4 *)(program + 8));
              IRInst__setHardwareRegisterAndAdd(operandVReg2,program,arena,0);
              operandRecord4 = IRInst__getOperandRecord(operandVReg2,0);
              FUN_000f302c(local_38,iVar4,*(undefined4 *)(operandRecord4 + 0x10));
              iVar4 = local_38[0];
              piVar5 = operandVReg2;
              uVar2 = operandVReg2[5];
            }
            iVar4 = IRInst__getOperandRecord(operandVReg,0);
            arena = 7;
            FUN_000f302c(&local_48,uVar11,*(undefined4 *)(iVar4 + 0x10));
            bVar1 = iVar12 == 1;
            iVar12 = iVar12 + 1;
            local_3c = local_48;
            piVar5 = operandVReg;
            if (bVar1) {
              return;
            }
          } while( true );
        }
      }
      FUN_000e8424(iVar4,*(undefined4 *)(program + 0x340));
      (**(code **)(*inst + 0x94))
                (inst,*(undefined4 *)(program + 0x340),*(undefined4 *)(program + 8));
      uVar11 = *(undefined4 *)(program + 8);
      UNRECOVERED_JUMPTABLE = *(code **)(*inst2 + 0x94);
      arena = *(undefined4 *)(program + 0x340);
      inst = inst2;
    }
LAB_000f1940:
                    
                    
    (*UNRECOVERED_JUMPTABLE)(inst,arena,uVar11);
    return;
  }
  return;
}

/* FUN_000f1d7c @ 0xf1d7c (3008 bytes) */
int FUN_000f1d7c(pass, afterInst, inst)
  int pass;
  undefined4 afterInst;
  dword *inst;
{
  int sourceDef;
  int operandRecord;
  int *operandVReg;
  int loopIndex;
  bool bVar1;
  undefined4 *puVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 predecessor;
  undefined4 a1;
  dword *a2;
  uint uVar8;
  dword argR6;
  undefined4 argR7;
  undefined4 in_r8;
  uint uVar9;
  dword dVar10;
  dword *pdVar11;
  int *piVar12;
  char local_8c;
  char cStack_8b;
  char cStack_8a;
  char cStack_89;
  /* issue #64 (auto): growable-vector header (capacity/count/data-pointer/arena) used with Vector__elementRefGrow - vecCapacity/vecCount/vecData/vecArena are its four words by their own hex offsets. Vector__elementRefGrow unconditionally reads all four on every call (even its "no grow needed" path reallocs+copies+frees), so they must be one contiguous buffer; left as four separate locals, an -O0 rebuild does not place them contiguously. Merged into one 0x10-byte buffer (part of the issue #64 live-differential sweep). */
  unsigned char local_88_buf [0x10];
  #define vecCapacity (*(uint *)(local_88_buf + 0x00))
  #define vecCount (*(uint *)(local_88_buf + 0x04))
  #define vecData (*(int *)(local_88_buf + 0x08))
  #define vecArena (*(undefined4 *)(local_88_buf + 0x0c))
  /* issue #64 (auto): growable-vector header (capacity/count/data-pointer/arena) used with Vector__elementRefGrow - vec2Capacity/vec2Count/vec2Data/vec2Arena are its four words by their own hex offsets. Vector__elementRefGrow unconditionally reads all four on every call (even its "no grow needed" path reallocs+copies+frees), so they must be one contiguous buffer; left as four separate locals, an -O0 rebuild does not place them contiguously. Merged into one 0x10-byte buffer (part of the issue #64 live-differential sweep). */
  unsigned char local_78_buf [0x10];
  #define vec2Capacity (*(uint *)(local_78_buf + 0x00))
  #define vec2Count (*(uint *)(local_78_buf + 0x04))
  #define vec2Data (*(int *)(local_78_buf + 0x08))
  #define vec2Arena (*(undefined4 *)(local_78_buf + 0x0c))
  /* issue #64 (auto): growable-vector header (capacity/count/data-pointer/arena) used with Vector__elementRefGrow - vec3Capacity/vec3Count/vec3Data/vec3Arena are its four words by their own hex offsets. Vector__elementRefGrow unconditionally reads all four on every call (even its "no grow needed" path reallocs+copies+frees), so they must be one contiguous buffer; left as four separate locals, an -O0 rebuild does not place them contiguously. Merged into one 0x10-byte buffer (part of the issue #64 live-differential sweep). */
  unsigned char local_68_buf [0x10];
  #define vec3Capacity (*(uint *)(local_68_buf + 0x00))
  #define vec3Count (*(uint *)(local_68_buf + 0x04))
  #define vec3Data (*(int *)(local_68_buf + 0x08))
  #define vec3Arena (*(undefined4 *)(local_68_buf + 0x0c))
  /* issue #64 (auto): growable-vector header (capacity/count/data-pointer/arena) used with Vector__elementRefGrow - vec4Capacity/vec4Count/vec4Data/vec4Arena are its four words by their own hex offsets. Vector__elementRefGrow unconditionally reads all four on every call (even its "no grow needed" path reallocs+copies+frees), so they must be one contiguous buffer; left as four separate locals, an -O0 rebuild does not place them contiguously. Merged into one 0x10-byte buffer (part of the issue #64 live-differential sweep). */
  unsigned char local_58_buf [0x10];
  #define vec4Capacity (*(uint *)(local_58_buf + 0x00))
  #define vec4Count (*(uint *)(local_58_buf + 0x04))
  #define vec4Data (*(int *)(local_58_buf + 0x08))
  #define vec4Arena (*(undefined4 *)(local_58_buf + 0x0c))
  int local_48;
  uint local_44;
  uint local_40;
  undefined4 local_3c;
  dword local_38 [2];
  
  *(int *)(pass + 0x474) = *(int *)(pass + 0x474) + 1;
  vec4Arena = *(undefined4 *)(*(int *)(pass + 8) + 0x378);
  vec4Count = 0;
  vec4Capacity = 2;
  pdVar11 = (dword *)inst[0x26];
  dVar10 = inst[0x25];
  a2 = inst;
  vec4Data = Arena__alloc(vec4Arena,8);
  vecArena = *(undefined4 *)(*(int *)(pass + 8) + 0x378);
  vecCount = 0;
  vecCapacity = 2;
  vecData = Arena__alloc(vecArena,8);
  vec2Arena = *(undefined4 *)(*(int *)(pass + 8) + 0x378);
  vec2Count = 0;
  vec2Capacity = 2;
  vec2Data = Arena__alloc(vec2Arena,8);
  vec3Arena = *(undefined4 *)(*(int *)(pass + 8) + 0x378);
  vec3Count = 0;
  vec3Capacity = 2;
  vec3Data = Arena__alloc(vec3Arena,8);
  uVar8 = vec4Count;
  if (vec4Count < vec4Capacity) {
    iVar4 = vec4Count * 4;
    a2 = ((unsigned char *)0x4);
    _memset(iVar4 + vec4Data,0,4);
    vec4Count = uVar8 + 1;
    puVar2 = (undefined4 *)(iVar4 + vec4Data);
  }
  else {
    puVar2 = (undefined4 *)Vector__elementRefGrow(&vec4Capacity,vec4Count);
  }
  uVar8 = vecCount;
  *puVar2 = inst;
  if (vecCount < vecCapacity) {
    iVar4 = vecCount * 4;
    a2 = ((unsigned char *)0x4);
    _memset(iVar4 + vecData,0,4);
    vecCount = uVar8 + 1;
    puVar2 = (undefined4 *)(iVar4 + vecData);
  }
  else {
    puVar2 = (undefined4 *)Vector__elementRefGrow(&vecCapacity,vecCount);
  }
  *puVar2 = 1;
  piVar3 = (int *)IRInst__getOperandSource(inst,1);
  bVar1 = true;
  uVar8 = vec4Count;
LAB_000f26b0:
  do {
    while( true ) {
      if (uVar8 == 0) {
        operandRecord = IRInst__getOperandRecord(inst,0);
        WriteMask__fromSelectWord(&local_40,*(undefined4 *)(operandRecord + 0x10));
        while (vec2Count != 0) {
          uVar8 = vec2Count - 1;
          puVar2 = (undefined4 *)0x0;
          if (uVar8 < vec2Count) {
            puVar2 = (undefined4 *)(uVar8 * 4 + vec2Data);
          }
          piVar12 = (int *)*puVar2;
          Vector__removeAt(&vec2Capacity,uVar8);
          piVar3 = (int *)0x0;
          uVar8 = vec3Count - 1;
          if (uVar8 < vec3Count) {
            piVar3 = (int *)(uVar8 * 4 + vec3Data);
          }
          iVar4 = *piVar3;
          Vector__removeAt(&vec3Capacity,uVar8);
          operandVReg = (int *)IRInst__getOperandSource(piVar12,iVar4);
          if (((dword *)operandVReg[0x26] != pdVar11) &&
             (iVar5 = (**(code **)(*operandVReg + 0x50))(operandVReg), iVar5 == 0)) {
            uVar8 = operandVReg[3];
            iVar5 = FUN_001084b8(0x31,*(undefined4 *)(pass + 8));
            IRInst__setOperandSource(iVar5,1,operandVReg,0,*(undefined4 *)(pass + 8));
            IRInst__setHardwareRegisterAndAdd(iVar5,pass,pdVar11,dVar10);
            SelectWord__selectWhereMasked(&local_3c,0,local_40 & uVar8);
            *(undefined4 *)(iVar5 + 0x9c) = local_3c;
            FUN_000f4698(iVar5,1,pass);
            iVar6 = FUN_001055cc(piVar12);
            if (iVar6 == 0) {
              iVar6 = (**(code **)(*piVar12 + 0x7c))(piVar12);
              if (iVar6 == 0) {
                IRInst__setOperandSource(piVar12,iVar4,iVar5,0,*(undefined4 *)(pass + 8));
                Block__insertInstBefore(piVar12[0x56],piVar12,iVar5);
              }
              else {
                IRInst__setOperandSource(piVar12,iVar4,iVar5,0,*(undefined4 *)(pass + 8));
                predecessor = Block__getPredecessor(piVar12[0x56],iVar4 + -1);
                Block__appendInst(predecessor,iVar5);
              }
            }
            else {
              IRInst__setExtraOperandSource(piVar12,iVar5,0,*(undefined4 *)(pass + 8));
              Block__insertInstAfter(operandVReg[0x56],operandVReg,iVar5);
            }
          }
        }
        sourceDef = IRInst__getOperandSource(inst,1);
        uVar8 = local_40 & *(uint *)(sourceDef + 0xc);
        SelectWord__selectWhereMasked(local_38,0,uVar8);
        inst[0x27] = local_38[0];
        FUN_000f4698(inst,1,pass);
        cStack_89 = (char)uVar8;
        cStack_8a = (char)(uVar8 >> 8);
        cStack_8b = (char)(uVar8 >> 0x10);
        local_8c = (char)(uVar8 >> 0x18);
        if (((cStack_89 == '\0' && cStack_8a == '\0') && cStack_8b == '\0') && local_8c == '\0') {
          (**(code **)(*inst + 0xc))(inst,0,*(undefined4 *)(pass + 8));
        }
        else {
          ((int (*)())FUN_000f07a8)(pass,afterInst,inst);
        }
        Arena__free(vec3Arena,vec3Data);
        Arena__free(vec2Arena,vec2Data);
        Arena__free(vecArena,vecData);
        Arena__free(vec4Arena,vec4Data);
        return;
      }
      if (!bVar1) break;
      if (piVar3 == (int *)0x0) {
        piVar3 = (int *)0x0;
        bVar1 = false;
      }
      else if (*(int *)(pass + 0x474) == piVar3[0x54]) {
LAB_000f26a4:
        bVar1 = false;
      }
      else {
        piVar3[0x54] = *(int *)(pass + 0x474);
        operandRecord = IRInst__getOperandRecord(piVar3,0);
        WriteMask__fromSelectWord(&local_48,*(undefined4 *)(operandRecord + 0x10));
        piVar3[3] = local_48;
        iVar4 = (**(code **)(*piVar3 + 0x7c))
                          (piVar3,a1,a2,argR6,argR7,in_r8,*(code **)(*piVar3 + 0x7c));
        uVar8 = vec4Count;
        if (iVar4 == 0) {
          iVar4 = FUN_00104fd0(piVar3);
          uVar8 = vec4Count;
          if (iVar4 == 0) {
            if ((piVar3[5] & 0x200U) == 0) goto LAB_000f26a4;
            if (vec4Count < vec4Capacity) {
              iVar4 = vec4Count * 4;
              a2 = ((unsigned char *)0x4);
              _memset(iVar4 + vec4Data,0,4);
              vec4Count = uVar8 + 1;
              puVar2 = (undefined4 *)(iVar4 + vec4Data);
            }
            else {
              puVar2 = (undefined4 *)Vector__elementRefGrow(&vec4Capacity,vec4Count);
            }
            uVar8 = vecCount;
            *puVar2 = piVar3;
            iVar4 = piVar3[0x21];
            if (vecCount < vecCapacity) {
              iVar5 = vecCount * 4;
              a2 = ((unsigned char *)0x4);
              _memset(iVar5 + vecData,0,4);
              vecCount = uVar8 + 1;
              piVar12 = (int *)(iVar5 + vecData);
            }
            else {
              piVar12 = (int *)Vector__elementRefGrow(&vecCapacity,vecCount);
            }
            *piVar12 = iVar4;
            piVar3 = (int *)IRInst__getOperandSource(piVar3,piVar3[0x21]);
          }
          else {
            if (vec4Count < vec4Capacity) {
              iVar4 = vec4Count * 4;
              a2 = ((unsigned char *)0x4);
              _memset(iVar4 + vec4Data,0,4);
              vec4Count = uVar8 + 1;
              puVar2 = (undefined4 *)(iVar4 + vec4Data);
            }
            else {
              puVar2 = (undefined4 *)Vector__elementRefGrow(&vec4Capacity,vec4Count);
            }
            uVar8 = vecCount;
            *puVar2 = piVar3;
            if (vecCount < vecCapacity) {
              iVar4 = vecCount * 4;
              a2 = ((unsigned char *)0x4);
              _memset(iVar4 + vecData,0,4);
              vecCount = uVar8 + 1;
              puVar2 = (undefined4 *)(iVar4 + vecData);
            }
            else {
              puVar2 = (undefined4 *)Vector__elementRefGrow(&vecCapacity,vecCount);
            }
            *puVar2 = 2;
            piVar3 = (int *)IRInst__getOperandSource(piVar3,2);
          }
        }
        else {
          if (vec4Count < vec4Capacity) {
            iVar4 = vec4Count * 4;
            a2 = ((unsigned char *)0x4);
            _memset(iVar4 + vec4Data,0,4);
            vec4Count = uVar8 + 1;
            puVar2 = (undefined4 *)(iVar4 + vec4Data);
          }
          else {
            puVar2 = (undefined4 *)Vector__elementRefGrow(&vec4Capacity,vec4Count);
          }
          uVar8 = vecCount;
          *puVar2 = piVar3;
          if (vecCount < vecCapacity) {
            iVar4 = vecCount * 4;
            a2 = ((unsigned char *)0x4);
            _memset(iVar4 + vecData,0,4);
            vecCount = uVar8 + 1;
            puVar2 = (undefined4 *)(iVar4 + vecData);
          }
          else {
            puVar2 = (undefined4 *)Vector__elementRefGrow(&vecCapacity,vecCount);
          }
          *puVar2 = 1;
          piVar3 = (int *)IRInst__getOperandSource(piVar3,1);
        }
LAB_000f2690:
        bVar1 = true;
        uVar8 = vec4Count;
      }
    }
    uVar9 = uVar8 - 1;
    puVar2 = (undefined4 *)0x0;
    if (uVar9 < uVar8) {
      puVar2 = (undefined4 *)(uVar9 * 4 + vec4Data);
    }
    bVar1 = piVar3 != (int *)0x0;
    piVar3 = (int *)*puVar2;
    if (bVar1) {
      piVar12 = (int *)0x0;
      uVar8 = vecCount - 1;
      if (uVar8 < vecCount) {
        piVar12 = (int *)(uVar8 * 4 + vecData);
      }
      if (*piVar12 != piVar3[0x21]) {
        piVar12 = (int *)0x0;
        if (uVar8 < vecCount) {
          piVar12 = (int *)(uVar8 * 4 + vecData);
        }
        iVar4 = *piVar12;
        Vector__removeAt(&vecCapacity,uVar8);
        uVar8 = vecCount;
        if (vecCount < vecCapacity) {
          iVar5 = vecCount * 4;
          a2 = ((unsigned char *)0x4);
          _memset(iVar5 + vecData,0,4);
          vecCount = uVar8 + 1;
          piVar12 = (int *)(iVar5 + vecData);
        }
        else {
          piVar12 = (int *)Vector__elementRefGrow(&vecCapacity,vecCount);
        }
        *piVar12 = iVar4 + 1;
        piVar3 = (int *)IRInst__getOperandSource(piVar3,iVar4 + 1);
        goto LAB_000f2690;
      }
    }
    Vector__removeAt(&vec4Capacity,uVar9);
    Vector__removeAt(&vecCapacity,vecCount - 1);
    operandRecord = IRInst__getOperandRecord(piVar3,0);
    WriteMask__fromSelectWord(&local_44,*(undefined4 *)(operandRecord + 0x10));
    uVar8 = local_44;
    iVar4 = FUN_001055cc(piVar3);
    if (iVar4 == 0) {
      iVar4 = (**(code **)(*piVar3 + 0x7c))(piVar3);
      if (iVar4 == 0) {
        iVar4 = FUN_00104fd0(piVar3);
        if (iVar4 != 0) {
          sourceDef = IRInst__getOperandSource(piVar3,2);
          iVar5 = IRInst__getOperandSource(piVar3,3);
          uVar9 = ~*(uint *)(sourceDef + 0xc);
          if ((uVar8 & (uVar9 << 0x18 | (uVar9 & 0xff00) << 8 | uVar9 >> 8 & 0xff00 | uVar9 >> 0x18)
              ) == 0) {
            uVar9 = ~*(uint *)(iVar5 + 0xc);
            if ((uVar8 & (uVar9 << 0x18 | (uVar9 & 0xff00) << 8 | uVar9 >> 8 & 0xff00 |
                         uVar9 >> 0x18)) == 0) goto LAB_000f25ac;
            FUN_0010c010(piVar3,3,*(undefined4 *)(pass + 8));
          }
          else {
            FUN_0010c010(piVar3,2,*(undefined4 *)(pass + 8));
          }
          a2 = pdVar11;
          argR6 = dVar10;
          IRInst__setHardwareRegisterAndAdd(piVar3,pass,pdVar11,dVar10);
          uVar9 = vec2Count;
          if (vec2Count < vec2Capacity) {
            iVar4 = vec2Count * 4;
            a2 = ((unsigned char *)0x4);
            _memset(iVar4 + vec2Data,0,4);
            vec2Count = uVar9 + 1;
            puVar2 = (undefined4 *)(iVar4 + vec2Data);
          }
          else {
            puVar2 = (undefined4 *)Vector__elementRefGrow(&vec2Capacity,vec2Count);
          }
          uVar9 = vec3Count;
          *puVar2 = piVar3;
          if (vec3Count < vec3Capacity) {
            iVar4 = vec3Count * 4;
            a2 = ((unsigned char *)0x4);
            _memset(iVar4 + vec3Data,0,4);
            vec3Count = uVar9 + 1;
            puVar2 = (undefined4 *)(iVar4 + vec3Data);
          }
          else {
            puVar2 = (undefined4 *)Vector__elementRefGrow(&vec3Capacity,vec3Count);
          }
          *puVar2 = 3;
          piVar3[3] = 0;
        }
LAB_000f25ac:
        if ((piVar3[5] & 0x200U) != 0) {
          sourceDef = IRInst__getOperandSource(piVar3,piVar3[0x21]);
          piVar3[3] = uVar8 | *(uint *)(sourceDef + 0xc);
          if ((dword *)*(undefined1 **)(sourceDef + 0x98) == pdVar11) {
            a2 = (dword *)0x0;
            argR6 = 0;
            argR7 = *(undefined4 *)(pass + 8);
            IRInst__setOperandSource(piVar3,piVar3[0x21],0,0,argR7);
            piVar3[0x21] = piVar3[0x21] + -1;
            piVar3[5] = piVar3[5] & 0xfffffdff;
          }
        }
      }
      else {
        loopIndex = 1;
        if (0 < piVar3[0x21]) {
          do {
            iVar5 = IRInst__getOperandSource(piVar3,loopIndex);
            uVar9 = ~*(uint *)(iVar5 + 0xc);
            if ((uVar8 & (uVar9 << 0x18 | (uVar9 & 0xff00) << 8 | uVar9 >> 8 & 0xff00 |
                         uVar9 >> 0x18)) != 0) {
              a2 = pdVar11;
              argR6 = dVar10;
              IRInst__setHardwareRegisterAndAdd(piVar3,pass,pdVar11,dVar10);
              piVar3[3] = 0;
              if (0 < piVar3[0x21]) {
                loopIndex = 1;
                do {
                  iVar5 = IRInst__getOperandSource(piVar3,loopIndex);
                  uVar9 = vec2Count;
                  if ((uVar8 & *(uint *)(iVar5 + 0xc)) != 0) {
                    if (vec2Count < vec2Capacity) {
                      iVar5 = vec2Count * 4;
                      a2 = ((unsigned char *)0x4);
                      _memset(iVar5 + vec2Data,0,4);
                      vec2Count = uVar9 + 1;
                      puVar2 = (undefined4 *)(iVar5 + vec2Data);
                    }
                    else {
                      puVar2 = (undefined4 *)Vector__elementRefGrow(&vec2Capacity,vec2Count);
                    }
                    uVar9 = vec3Count;
                    *puVar2 = piVar3;
                    if (vec3Count < vec3Capacity) {
                      iVar5 = vec3Count * 4;
                      a2 = ((unsigned char *)0x4);
                      _memset(iVar5 + vec3Data,0,4);
                      vec3Count = uVar9 + 1;
                      piVar12 = (int *)(iVar5 + vec3Data);
                    }
                    else {
                      piVar12 = (int *)Vector__elementRefGrow(&vec3Capacity,vec3Count);
                    }
                    *piVar12 = loopIndex;
                  }
                  loopIndex = loopIndex + 1;
                } while (loopIndex <= piVar3[0x21]);
              }
              break;
            }
            loopIndex = loopIndex + 1;
          } while (loopIndex <= piVar3[0x21]);
        }
      }
LAB_000f260c:
      bVar1 = false;
      uVar8 = vec4Count;
      goto LAB_000f26b0;
    }
    a2 = pdVar11;
    argR6 = dVar10;
    IRInst__setHardwareRegisterAndAdd(piVar3,pass,pdVar11,dVar10);
    sourceDef = IRInst__getOperandSource(piVar3,piVar3[0x21]);
    uVar9 = vec2Count;
    piVar3[3] = 0;
    if ((uVar8 & *(uint *)(sourceDef + 0xc)) == 0) goto LAB_000f260c;
    if (vec2Count < vec2Capacity) {
      iVar4 = vec2Count * 4;
      a2 = ((unsigned char *)0x4);
      _memset(iVar4 + vec2Data,0,4);
      vec2Count = uVar9 + 1;
      puVar2 = (undefined4 *)(iVar4 + vec2Data);
    }
    else {
      puVar2 = (undefined4 *)Vector__elementRefGrow(&vec2Capacity,vec2Count);
    }
    uVar8 = vec3Count;
    *puVar2 = piVar3;
    iVar4 = piVar3[0x21];
    if (vec3Count < vec3Capacity) {
      iVar5 = vec3Count * 4;
      a2 = ((unsigned char *)0x4);
      _memset(iVar5 + vec3Data,0,4);
      vec3Count = uVar8 + 1;
      piVar12 = (int *)(iVar5 + vec3Data);
    }
    else {
      piVar12 = (int *)Vector__elementRefGrow(&vec3Capacity,vec3Count);
    }
    *piVar12 = iVar4;
    bVar1 = false;
    uVar8 = vec4Count;
  } while( true );
}
#undef vec4Capacity
#undef vec4Count
#undef vec4Data
#undef vec4Arena
#undef vecCapacity
#undef vecCount
#undef vecData
#undef vecArena
#undef vec2Capacity
#undef vec2Count
#undef vec2Data
#undef vec2Arena
#undef vec3Capacity
#undef vec3Count
#undef vec3Data
#undef vec3Arena

/* FUN_000f29f4 @ 0xf29f4 (488 bytes) */
int FUN_000f29f4(param_1)
  int param_1;
{
  int loopIndex;
  int *piVar1;
  int iVar2;
  undefined4 extraout_r4;
  undefined4 in_r5;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  int iVar3;
  int *piVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  int *piVar8;
  int *piVar9;
  
  FUN_0010ea30(param_1);
  ((int (*)())Program__beginPass)(param_1,(int)"assign_slots");
  piVar1 = *(int **)(*(int *)(param_1 + 8) + 0x30c);
  iVar3 = *piVar1;
  iVar2 = (**(code **)(iVar3 + 0xd8))(piVar1);
  if (iVar2 == 0) {
    ((int (*)())FUN_000eced0)(param_1);
    piVar1 = *(int **)(*(int *)(param_1 + 0x3a8) + 0x98);
    for (piVar9 = (int *)piVar1[2]; piVar9 != (int *)0x0; piVar9 = (int *)piVar9[2]) {
      iVar2 = (**(code **)(*piVar1 + 0x68))(piVar1);
      if (iVar2 != 0) {
        if (piVar1[0x51] == 0) {
          ((int (*)())FUN_000f07a8)(param_1,*(undefined4 *)(param_1 + 0x33c),piVar1);
        }
        else {
          ((int (*)())FUN_000f1d7c)(param_1,*(undefined4 *)(param_1 + 0x33c),piVar1);
        }
      }
      piVar1 = piVar9;
    }
  }
  else {
    ((int (*)())FUN_000ec920)(param_1);
    ((int (*)())FUN_000efde4)(param_1,extraout_r4,in_r5,in_r6,in_r7,in_r8,iVar3);
    piVar9 = *(int **)(*(int *)(param_1 + 0x3a8) + 0x98);
    piVar1 = (int *)piVar9[2];
    if (piVar1 == (int *)0x0) {
      piVar7 = (int *)0x0;
      piVar5 = (int *)0x0;
      loopIndex = 0;
    }
    else {
      loopIndex = 0;
      piVar4 = (int *)0x0;
      piVar6 = (int *)0x0;
      do {
        piVar8 = piVar1;
        iVar3 = (**(code **)(*piVar9 + 0x68))(piVar9);
        piVar5 = piVar4;
        piVar7 = piVar6;
        if (((iVar3 != 0) && (piVar7 = piVar9, piVar9[0x4f] != 6)) &&
           (piVar5 = piVar9, piVar7 = piVar6, piVar9[0x4f] != 7)) {
          loopIndex = loopIndex + 1;
          ((int (*)())FUN_000f07a8)(param_1,*(undefined4 *)(param_1 + 0x33c),piVar9);
          piVar5 = piVar4;
        }
        piVar1 = (int *)piVar8[2];
        piVar4 = piVar5;
        piVar6 = piVar7;
        piVar9 = piVar8;
      } while (piVar1 != (int *)0x0);
    }
    iVar3 = 0;
    if (loopIndex != 0) {
      iVar3 = loopIndex + -1;
    }
    *(int *)(*(int *)(param_1 + 0x33c) + 300) = iVar3;
    if (piVar7 != (int *)0x0) {
      ((int (*)())FUN_000f14f8)(param_1,piVar7,piVar5);
    }
  }
  *(uint *)(param_1 + 0x30) = *(uint *)(param_1 + 0x30) | 0x800;
  ((int (*)())callTargetSlot25)(param_1);
  return ((int (*)())Program__beginPass)(param_1,(int)"mark_io");
}

/* SelectWord__compose @ 0xf2bdc (128 bytes) */
int SelectWord__compose(param_1, param_2, param_3)
  uint *param_1;
  undefined4 param_2;
  uint param_3;
{
  unsigned int ghidra_home[8] = { param_1, param_2, param_3, 0, 0, 0, 0, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  
  (*(unsigned int *)((unsigned char *)ghidra_home + 4)) = param_2;
  (*(unsigned int *)((unsigned char *)ghidra_home + 8)) = param_3;
  (*(byte *)((unsigned char *)ghidra_home + 10)) = (byte)(param_3 >> 8);
  (*(byte *)((unsigned char *)ghidra_home + 9)) = (byte)(param_3 >> 0x10);
  (*(byte *)((unsigned char *)ghidra_home + 8)) = (byte)(param_3 >> 0x18);
  *param_1 = (uint)(*(byte *)((unsigned char *)ghidra_home + 8)) << 0x18 | (uint)(*(byte *)((unsigned char *)ghidra_home + 9)) << 0x10 | (uint)(*(byte *)((unsigned char *)ghidra_home + 10)) << 8
             | param_3 & 0xff;
  if ((*(byte *)((unsigned char *)ghidra_home + 8)) < 4) {
    *(undefined1 *)param_1 = *(undefined1 *)((int)&(*(unsigned int *)((unsigned char *)ghidra_home + 4)) + (uint)(*(byte *)((unsigned char *)ghidra_home + 8)));
  }
  if ((*(byte *)((unsigned char *)ghidra_home + 9)) < 4) {
    *(undefined1 *)((int)param_1 + 1) =
         *(undefined1 *)((int)&(*(unsigned int *)((unsigned char *)ghidra_home + 4)) + (uint)(*(byte *)((unsigned char *)ghidra_home + 9)));
  }
  if ((*(byte *)((unsigned char *)ghidra_home + 10)) < 4) {
    *(undefined1 *)((int)param_1 + 2) =
         *(undefined1 *)((int)&(*(unsigned int *)((unsigned char *)ghidra_home + 4)) + (uint)(*(byte *)((unsigned char *)ghidra_home + 10)));
  }
  if (3 < (param_3 & 0xff)) {
    return;
  }
  *(undefined1 *)((int)param_1 + 3) = *(undefined1 *)((int)&(*(unsigned int *)((unsigned char *)ghidra_home + 4)) + (param_3 & 0xff));
  return;
}

/* SelectWord__isSplat @ 0xf2c5c (80 bytes) */
int SelectWord__isSplat(param_1)
  undefined4 param_1;
{
  unsigned int ghidra_home[8] = { param_1, 0, 0, 0, 0, 0, 0, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  char cVar1;
  char *pcVar2;
  char cVar3;
  char cVar4;
  int iVar5;
  
  (*(unsigned int *)((unsigned char *)ghidra_home + 0)) = param_1;
  iVar5 = 4;
  pcVar2 = (char *)&(*(unsigned int *)((unsigned char *)ghidra_home + 0));
  cVar3 = '\x04';
  while (((cVar1 = *pcVar2, cVar4 = cVar3, cVar1 == '\x04' || (cVar4 = cVar1, cVar3 == '\x04')) ||
         (cVar4 = cVar3, cVar1 == cVar3))) {
    pcVar2 = pcVar2 + 1;
    iVar5 = iVar5 + -1;
    cVar3 = cVar4;
    if (iVar5 == 0) {
      return 1;
    }
  }
  return 0;
}

/* FUN_000f2cac @ 0xf2cac (92 bytes) */
int FUN_000f2cac(param_1)
  undefined4 param_1;
{
  unsigned int ghidra_home[8] = { param_1, 0, 0, 0, 0, 0, 0, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  char *pcVar1;
  int iVar2;
  int iVar3;
  
  (*(unsigned int *)((unsigned char *)ghidra_home + 0)) = param_1;
  ((int (*)())SelectWord__isSplat)(param_1);
  iVar3 = 4;
  iVar2 = 0;
  pcVar1 = (char *)&(*(unsigned int *)((unsigned char *)ghidra_home + 0));
  do {
    if (*pcVar1 != '\x04') {
      return (uint)*(byte *)((int)&(*(unsigned int *)((unsigned char *)ghidra_home + 0)) + iVar2);
    }
    iVar2 = iVar2 + 1;
    pcVar1 = pcVar1 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return 0xffffffff;
}

/* FUN_000f2d08 @ 0xf2d08 (16 bytes) */
int FUN_000f2d08(param_1)
  uint param_1;
{
  return param_1 < 4;
}


/* issue: auto-generated aliases bridging data.s/code.s references (written
 * without a leading underscore, matching the raw stock-binary symbol name)
 * against the real compiled C symbols (gcc adds one underscore automatically).
 * Needed because ld64 (required for this PPC binary's size - stock ld breaks on
 * large PPC links) does not silently reconcile this the way stock ld did. */
asm(".globl FUN_000ebff8");
asm(".set FUN_000ebff8, _ContinueBlock__clone");
asm(".globl FUN_000eca10");
asm(".set FUN_000eca10, _KhanVs__vslot17_isSimpleInst");
asm(".globl FUN_000ecad0");
asm(".set FUN_000ecad0, _KhanPs__vslot17_isSimpleInst");
asm(".globl FUN_000ed29c");
asm(".set FUN_000ed29c, _HwLimits__vslot43_prependDefaultMov");
