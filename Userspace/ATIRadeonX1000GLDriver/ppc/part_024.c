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

/* Program__interpSlotOfIlType @ 0xec258 (36 bytes) */
int Program__interpSlotOfIlType(program, ilType)
  undefined4 program;
  int ilType;
{
  return *(undefined4 *)(PTR_DAT_001e8b5c + ilType * 4);
}

/* Program__lookupTable8b68 @ 0xec27c (36 bytes) */
int Program__lookupTable8b68(program, ilType)
  undefined4 program;
  int ilType;
{
  return *(undefined4 *)(PTR_DAT_001e8b68 + ilType * 4);
}

/* Program__laneKindOfInterpSlot @ 0xec2a0 (36 bytes) */
int Program__laneKindOfInterpSlot(program, interpSlot)
  undefined4 program;
  int interpSlot;
{
  return *(undefined4 *)(PTR_DAT_001e8b6c + interpSlot * 4);
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

/* Program__insertBlockBefore @ 0xec370 (60 bytes) */
int Program__insertBlockBefore(program, ref, node)
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
  int loopCounter;
  uint loopIndex;
  
  if (*(int *)(param_1 + 0x394) != 0) {
    Arena__free(*(undefined4 *)(*(int *)(param_1 + 8) + 0x374),*(int *)(param_1 + 0x394));
  }
  allocation = Arena__alloc(*(undefined4 *)(*(int *)(param_1 + 8) + 0x374),param_3 * 4 + 4);
  loopIndex = 0;
  *(undefined4 *)(param_1 + 0x394) = allocation;
  loopCounter = 0;
  do {
    loopIndex = loopIndex + 1;
    *(undefined4 *)(*(int *)(param_1 + 0x394) + loopCounter) = *(undefined4 *)(param_2 + loopCounter);
    loopCounter = loopCounter + 4;
  } while (loopIndex <= param_3);
  return;
}

/* FUN_000ec4f0 @ 0xec4f0 (124 bytes) */
int FUN_000ec4f0(param_1)
  int param_1;
{
  int iVar1;
  undefined4 *allocation;
  undefined4 arenaB;
  undefined4 *puVar4;
  
  iVar1 = *(int *)(param_1 + 0x394);
  if (iVar1 == 0) {
    arenaB = *(undefined4 *)(*(int *)(param_1 + 8) + 0x378);
    allocation = (undefined4 *)Arena__alloc(arenaB,0x2c);
    *allocation = arenaB;
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

/* Program__getBlocksArray @ 0xec5b8 (160 bytes) */
int Program__getBlocksArray(program)
  int program;
{
  undefined4 allocation;
  int listCount;
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int loopIndex;
  
  iVar2 = *(int *)(program + 0x398);
  if (iVar2 == 0) {
    listCount = DList__count(program + 0x37c);
    allocation = Arena__alloc(*(undefined4 *)(*(int *)(program + 8) + 0x374),listCount * 4 + 4);
    *(undefined4 *)(program + 0x398) = allocation;
    puVar4 = (undefined4 *)((int (*)())FUN_000ec4f0)(program);
    **(undefined4 **)(program + 0x398) = *puVar4;
    if (0 < listCount) {
      puVar4 = puVar4 + listCount;
      loopIndex = 1;
      do {
        iVar1 = loopIndex * 4;
        loopIndex = loopIndex + 1;
        uVar3 = *puVar4;
        puVar4 = puVar4 + -1;
        *(undefined4 *)(iVar1 + *(int *)(program + 0x398)) = uVar3;
      } while (loopIndex <= listCount);
    }
    iVar2 = *(int *)(program + 0x398);
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
  int newTempIndex;
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
                newTempIndex = *(int *)(*(int *)(program + 8) + 0x3ac) + -1;
                *(int *)(*(int *)(program + 8) + 0x3ac) = newTempIndex;
                uVar3 = FUN_00127608(uVar3,0,newTempIndex,0);
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
  int loopCounter;
  int loopIndex;
  undefined4 *puVar7;
  int *piVar8;
  bool bVar9;
  
  puVar2 = (undefined4 *)((int (*)())Program__getBlocksArray)(param_1);
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
        loopCounter = 0;
        for (loopIndex2 = 1; loopIndex2 <= *(uint *)(piVar8[0x34] + 4); loopIndex2 = loopIndex2 + 1) {
          iVar1 = *(int *)(*(int *)(piVar8[0x34] + 8) + loopCounter);
          if (iVar1 != 0) {
            piVar8[3] = *(uint *)(iVar1 + 0xc) & 3 | piVar8[3];
          }
          loopCounter = loopCounter + 4;
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

/* IRInst__isForwardable @ 0xecc1c (268 bytes) */
int IRInst__isForwardable(inst, selectWord, compiler)
  int *inst;
  undefined4 selectWord;
  int compiler;
{
  int hasSingleUse;
  int iVar1;
  
  iVar1 = (**(code **)(*inst + 0x60))(inst,selectWord,compiler);
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
     ((iVar1 = SelectWord__areCompatible(selectWord,0x10203), iVar1 != 0 ||
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
  
  piVar2 = (int *)IRMov__new_1084b8(0x31,*(undefined4 *)(param_1 + 8));
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
  undefined4 arenaA;
  
  arenaA = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
  allocation = (undefined4 *)Arena__alloc(arenaA,0x168);
  *allocation = arenaA;
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

/* IRInst__bindOperandRegisters @ 0xed63c (424 bytes) */
int IRInst__bindOperandRegisters(program, inst)
  int program;
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
  int newTempIndex;
  
  if (*(int *)(inst + 0x80) != 0) {
    piVar1 = (int *)FUN_00127608(*(undefined4 *)(program + 0x3ac),*(undefined4 *)(inst + 0x98),
                                 *(undefined4 *)(inst + 0x94),0);
    pcVar7 = *(code **)(*piVar1 + 0x28);
    operandRecord2 = IRInst__getOperandRecord(inst,0);
    piVar3 = (int *)(*pcVar7)(piVar1,*(undefined4 *)(operandRecord2 + 0x10),program);
    if ((piVar3 == (int *)0x0) || (piVar1 == piVar3)) {
      FUN_0012306c(piVar1,inst);
      IRInst__setOperandRef(inst,0,piVar1);
    }
    else {
      FUN_0012306c(piVar3,inst);
      IRInst__setOperandRef(inst,0,piVar3);
      if ((*(uint *)(program + 0x30) & 0x4000) != 0) {
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
        newTempIndex = *(int *)(*(int *)(program + 8) + 0x3ac) + -1;
        *(int *)(*(int *)(program + 8) + 0x3ac) = newTempIndex;
        uVar6 = *(undefined4 *)(iVar2 + 0xb0);
        operandRecord = IRInst__getOperandRecord(inst,loopIndex);
        *(int *)(operandRecord + 8) = newTempIndex;
        *(undefined4 *)(operandRecord + 0xc) = uVar6;
        iVar4 = *(int *)(iVar2 + 0xb0);
      }
      piVar1 = (int *)FUN_00127608(*(undefined4 *)(program + 0x3ac),iVar4,
                                   *(undefined4 *)(iVar2 + 0xac),0);
      piVar3 = (int *)(**(code **)(*piVar1 + 0x28))(piVar1,DAT_001aa80c,program);
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
  int loopCounter;
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
  loopCounter = 0;
  for (loopIndex = 1; loopIndex <= *(uint *)(iVar1 + 4); loopIndex = loopIndex + 1) {
    iVar2 = *(int *)(*(int *)(iVar1 + 8) + loopCounter);
    if ((*(uint *)(iVar2 + 0x14) & 1) != 0) {
      IRInst__getOperandRecord(iVar2,0);
      iVar1 = *(int *)(program + PROG_instructionVector);
    }
    loopCounter = loopCounter + 4;
  }
  return 1;
}

/* FUN_000ed89c @ 0xed89c (852 bytes) */
int FUN_000ed89c(param_1)
  int param_1;
{
  undefined4 arena;
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
  undefined4 virtualRegister;
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
          virtualRegister = FUN_00127608(*(undefined4 *)(param_1 + 0x3ac),0x22,0,0);
          piVar3 = (int *)0x0;
          do {
            iVar5 = piVar15[3];
            piVar10 = (int *)piVar15[0xb];
            piVar15[7] = iVar5;
            piVar15[0xb] = 0;
            uVar14 = *(undefined4 *)(iVar5 + 0x8c);
            operandRecord = IRInst__getOperandRecord(iVar5,0);
            uVar11 = *(undefined4 *)(operandRecord + 0x10);
            IRInst__setOperandRef(piVar15[7],0,virtualRegister);
            *(undefined4 *)(piVar15[7] + 0x9c) = DAT_001aa800;
            FUN_0012306c(virtualRegister,piVar15[7]);
            arenaAt374 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
            allocation = (undefined4 *)Arena__alloc(arenaAt374,0x168);
            *allocation = arenaAt374;
            puVar7 = allocation + 1;
            IRProjection__ctor_109e28(puVar7,0x84,*(undefined4 *)(param_1 + 8));
            IRInst__setOperandRef(puVar7,0,uVar14);
            allocation[0x28] = uVar11;
            IRInst__setOperandRef(puVar7,1,virtualRegister);
            FUN_0012306c(uVar14,puVar7);
            VReg__addUse(virtualRegister,1,puVar7);
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
              IRInst__appendSource(piVar15[1],virtualRegister);
              VReg__addUse(virtualRegister,*(undefined4 *)(piVar15[1] + 0x84),piVar15[1]);
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

/* Program__ctor_edd98 @ 0xedd98 (1216 bytes) */
int Program__ctor_edd98(program, compiler)
  undefined4 *program;
  undefined4 compiler;
{
  int clearCount4;
  int hwTableClearCount;
  int tableClearCount;
  int clearCount1;
  undefined4 *hwRegisterTableAlloc;
  undefined4 *tableData;
  undefined4 vectorData;
  undefined4 *allocation;
  undefined4 *zeroCursor;
  undefined4 *registerTableAlloc;
  undefined4 arenaA;
  int clearCount0;
  
  program[2] = compiler;
  *program = 0;
  program[0xc] = 0;
  program[0x1f] = 0xffffffff;
  program[0x20] = 0xffffffff;
  program[0x21] = 0;
  program[0x22] = 0;
  program[0x23] = 0;
  program[0x24] = 0;
  program[0x25] = 0;
  program[0x26] = 0;
  program[0x27] = 0;
  program[0x28] = 0;
  program[0x29] = 0;
  program[0x2a] = 0;
  program[0x2b] = 0;
  program[0x2c] = 0;
  program[0x2d] = 0;
  program[0x2e] = 0;
  program[0x2f] = 0;
  program[0x30] = 0;
  program[0x31] = 0;
  program[0x32] = 0;
  program[0x33] = 0;
  program[0x34] = 0;
  program[0x35] = 0;
  program[0x36] = 0;
  program[0x37] = 0;
  program[0x38] = 0;
  program[0x39] = 0;
  program[0x3a] = 0;
  program[0x3b] = 0;
  program[0x3c] = 0;
  program[0x3d] = 0;
  program[0x3e] = 0;
  program[0x3f] = 0;
  program[0x40] = 0;
  program[0x41] = 0;
  program[0x42] = 0;
  program[0x43] = 0;
  program[0x44] = 0;
  program[0x45] = 0;
  program[0x46] = 0;
  program[0x47] = 0;
  program[0x48] = 0;
  program[0x49] = 0;
  program[0x4a] = 0;
  program[0x4b] = 0;
  program[0x4c] = 0;
  program[0x4d] = 0;
  program[0x4e] = 0;
  program[0x4f] = 0;
  program[0x50] = 0;
  program[0x51] = 0;
  program[0x52] = 0;
  program[0x53] = 0;
  program[0x54] = 0;
  program[0x55] = 0;
  program[0x56] = 0;
  program[0x57] = 0;
  program[0x58] = 0;
  program[0x59] = 0;
  program[0x5a] = 0;
  program[0x5b] = 0;
  program[0x5c] = 0;
  program[0x5d] = 0;
  program[0x5e] = 0;
  program[0x5f] = 0;
  program[0x60] = 0;
  program[0x61] = 0;
  program[0x62] = 0;
  program[99] = 0;
  program[100] = 0;
  program[0x65] = 0;
  program[0x66] = 0;
  program[0x67] = 0;
  program[0x68] = 0;
  program[0x69] = 0;
  program[0x6a] = 0;
  program[0x6b] = 0;
  program[0x6c] = 0;
  program[0x6d] = 0;
  program[0x6e] = 0;
  program[0x6f] = 0;
  program[0x70] = 0;
  program[0x71] = 0;
  program[0x72] = 0;
  program[0x73] = 0;
  program[0x74] = 0;
  program[0x75] = 0;
  program[0x76] = 0;
  program[0x77] = 0;
  program[0x78] = 0;
  program[0x79] = 0;
  program[0x7a] = 0;
  program[0x7b] = 0;
  program[0x7c] = 0;
  program[0x7d] = 0;
  program[0x7e] = 0;
  program[0x7f] = 0;
  program[0x80] = 0;
  program[0x81] = 0;
  program[0x82] = 0;
  program[0x83] = 0;
  program[0x84] = 0;
  program[0x85] = 0;
  program[0x86] = 0;
  program[0x87] = 0;
  program[0x88] = 0;
  program[0x89] = 0;
  program[0x8a] = 0;
  program[0x8b] = 0;
  program[0x8c] = 0;
  program[0x8d] = 0;
  program[0x8e] = 0;
  program[0x8f] = 0;
  program[0x90] = 0;
  program[0x91] = 0;
  program[0x92] = 0;
  program[0x93] = 0;
  program[0x94] = 0;
  program[0x95] = 0;
  program[0x96] = 0;
  program[0x97] = 0;
  program[0x98] = 0;
  program[0x99] = 0;
  program[0x9a] = 0;
  program[0x9b] = 0;
  program[0x9c] = 0;
  program[0x9d] = 0;
  program[0x9e] = 0;
  program[0x9f] = 0;
  program[0xa0] = 0;
  program[0xa1] = 0;
  program[0xa2] = 0;
  program[0xa3] = 0;
  program[0xa4] = 0;
  program[0xa5] = 0;
  program[0xa6] = 0;
  program[0xa7] = 0;
  program[0xa8] = 0;
  program[0xa9] = 0;
  program[0xaa] = 0;
  program[0xab] = 0;
  program[0xcc] = 0;
  program[0xce] = 0;
  program[0xcf] = 0;
  program[0xd1] = 0;
  program[0xd2] = 0;
  program[0xd3] = 0;
  program[0xd4] = 0;
  program[0xd6] = 0;
  program[0xd7] = 0;
  program[0xd8] = 0;
  program[0xd9] = 0;
  program[0xda] = 0;
  program[0xdd] = 0;
  DListNode__init(program + 0xdf);
  clearCount0 = 0x10;
  program[0xfa] = 0x7fffffff;
  program[0xfe] = 1;
  program[0xf6] = 0x7fffffff;
  program[0x10a] = 0xffffffff;
  program[0x11f] = 0;
  program[0xe5] = 0;
  program[0xe6] = 0;
  program[0xe7] = 0;
  program[0xe9] = 0;
  program[0xed] = 0;
  program[0xf0] = 0;
  program[0xf3] = 0;
  program[0xf5] = 0;
  program[0xf7] = 0xffffffff;
  program[0xf8] = 0;
  program[0xf9] = 0;
  program[0xfb] = 0xffffffff;
  program[0xfc] = 0;
  program[0x11d] = 0;
  program[0x11e] = 0;
  zeroCursor = program;
  do {
    zeroCursor[0xe] = 0;
    zeroCursor = zeroCursor + 1;
    clearCount0 = clearCount0 + -1;
  } while (clearCount0 != 0);
  clearCount1 = 0x20;
  zeroCursor = program;
  do {
    zeroCursor[0xac] = 0;
    zeroCursor = zeroCursor + 1;
    clearCount1 = clearCount1 + -1;
  } while (clearCount1 != 0);
  arenaA = *(undefined4 *)(program[2] + 0x374);
  allocation = (undefined4 *)Arena__alloc(arenaA,0x6c);
  *allocation = arenaA;
  FUN_001272cc(allocation + 1,program[2]);
  program[0xeb] = allocation + 1;
  arenaA = *(undefined4 *)(program[2] + 0x374);
  registerTableAlloc = (undefined4 *)Arena__alloc(arenaA,0x20c);
  registerTableAlloc[1] = 0x80;
  tableClearCount = 0x80;
  *registerTableAlloc = arenaA;
  registerTableAlloc[2] = 0x1000;
  tableData = registerTableAlloc + 1;
  do {
    tableData[2] = 0;
    tableData = tableData + 1;
    tableClearCount = tableClearCount + -1;
  } while (tableClearCount != 0);
  program[0xec] = registerTableAlloc + 1;
  arenaA = *(undefined4 *)(program[2] + 0x374);
  hwRegisterTableAlloc = (undefined4 *)Arena__alloc(arenaA,0x8c);
  hwRegisterTableAlloc[1] = 0x20;
  *hwRegisterTableAlloc = arenaA;
  hwRegisterTableAlloc[2] = 0x400;
  hwTableClearCount = 0x20;
  tableData = hwRegisterTableAlloc + 1;
  do {
    tableData[2] = 0;
    tableData = tableData + 1;
    hwTableClearCount = hwTableClearCount + -1;
  } while (hwTableClearCount != 0);
  program[0xef] = hwRegisterTableAlloc + 1;
  arenaA = *(undefined4 *)(program[2] + 0x374);
  allocation = (undefined4 *)Arena__alloc(arenaA,0x14);
  *allocation = arenaA;
  allocation[1] = 2;
  allocation[4] = arenaA;
  allocation[2] = 0;
  vectorData = Arena__alloc(arenaA,8);
  allocation[3] = vectorData;
  program[0xf1] = allocation + 1;
  arenaA = *(undefined4 *)(program[2] + 0x374);
  allocation = (undefined4 *)Arena__alloc(arenaA,0x14);
  *allocation = arenaA;
  allocation[1] = 2;
  allocation[2] = 0;
  allocation[4] = arenaA;
  vectorData = Arena__alloc(arenaA,8);
  allocation[3] = vectorData;
  clearCount4 = 4;
  program[0xf2] = allocation + 1;
  zeroCursor = program;
  do {
    zeroCursor[4] = 0;
    zeroCursor[8] = 0;
    zeroCursor = zeroCursor + 1;
    clearCount4 = clearCount4 + -1;
  } while (clearCount4 != 0);
  program[0xde] = 0;
  return;
}

/* Program__ctor_ee29c @ 0xee29c (1216 bytes) */
int Program__ctor_ee29c(program, compiler)
  undefined4 *program;
  undefined4 compiler;
{
  int clearCount4;
  int hwTableClearCount;
  int tableClearCount;
  int clearCount1;
  undefined4 *hwRegisterTableAlloc;
  undefined4 *tableData;
  undefined4 vectorData;
  undefined4 *allocation;
  undefined4 *zeroCursor;
  undefined4 *registerTableAlloc;
  undefined4 arenaA;
  int clearCount0;
  
  program[2] = compiler;
  *program = 0;
  program[0xc] = 0;
  program[0x1f] = 0xffffffff;
  program[0x20] = 0xffffffff;
  program[0x21] = 0;
  program[0x22] = 0;
  program[0x23] = 0;
  program[0x24] = 0;
  program[0x25] = 0;
  program[0x26] = 0;
  program[0x27] = 0;
  program[0x28] = 0;
  program[0x29] = 0;
  program[0x2a] = 0;
  program[0x2b] = 0;
  program[0x2c] = 0;
  program[0x2d] = 0;
  program[0x2e] = 0;
  program[0x2f] = 0;
  program[0x30] = 0;
  program[0x31] = 0;
  program[0x32] = 0;
  program[0x33] = 0;
  program[0x34] = 0;
  program[0x35] = 0;
  program[0x36] = 0;
  program[0x37] = 0;
  program[0x38] = 0;
  program[0x39] = 0;
  program[0x3a] = 0;
  program[0x3b] = 0;
  program[0x3c] = 0;
  program[0x3d] = 0;
  program[0x3e] = 0;
  program[0x3f] = 0;
  program[0x40] = 0;
  program[0x41] = 0;
  program[0x42] = 0;
  program[0x43] = 0;
  program[0x44] = 0;
  program[0x45] = 0;
  program[0x46] = 0;
  program[0x47] = 0;
  program[0x48] = 0;
  program[0x49] = 0;
  program[0x4a] = 0;
  program[0x4b] = 0;
  program[0x4c] = 0;
  program[0x4d] = 0;
  program[0x4e] = 0;
  program[0x4f] = 0;
  program[0x50] = 0;
  program[0x51] = 0;
  program[0x52] = 0;
  program[0x53] = 0;
  program[0x54] = 0;
  program[0x55] = 0;
  program[0x56] = 0;
  program[0x57] = 0;
  program[0x58] = 0;
  program[0x59] = 0;
  program[0x5a] = 0;
  program[0x5b] = 0;
  program[0x5c] = 0;
  program[0x5d] = 0;
  program[0x5e] = 0;
  program[0x5f] = 0;
  program[0x60] = 0;
  program[0x61] = 0;
  program[0x62] = 0;
  program[99] = 0;
  program[100] = 0;
  program[0x65] = 0;
  program[0x66] = 0;
  program[0x67] = 0;
  program[0x68] = 0;
  program[0x69] = 0;
  program[0x6a] = 0;
  program[0x6b] = 0;
  program[0x6c] = 0;
  program[0x6d] = 0;
  program[0x6e] = 0;
  program[0x6f] = 0;
  program[0x70] = 0;
  program[0x71] = 0;
  program[0x72] = 0;
  program[0x73] = 0;
  program[0x74] = 0;
  program[0x75] = 0;
  program[0x76] = 0;
  program[0x77] = 0;
  program[0x78] = 0;
  program[0x79] = 0;
  program[0x7a] = 0;
  program[0x7b] = 0;
  program[0x7c] = 0;
  program[0x7d] = 0;
  program[0x7e] = 0;
  program[0x7f] = 0;
  program[0x80] = 0;
  program[0x81] = 0;
  program[0x82] = 0;
  program[0x83] = 0;
  program[0x84] = 0;
  program[0x85] = 0;
  program[0x86] = 0;
  program[0x87] = 0;
  program[0x88] = 0;
  program[0x89] = 0;
  program[0x8a] = 0;
  program[0x8b] = 0;
  program[0x8c] = 0;
  program[0x8d] = 0;
  program[0x8e] = 0;
  program[0x8f] = 0;
  program[0x90] = 0;
  program[0x91] = 0;
  program[0x92] = 0;
  program[0x93] = 0;
  program[0x94] = 0;
  program[0x95] = 0;
  program[0x96] = 0;
  program[0x97] = 0;
  program[0x98] = 0;
  program[0x99] = 0;
  program[0x9a] = 0;
  program[0x9b] = 0;
  program[0x9c] = 0;
  program[0x9d] = 0;
  program[0x9e] = 0;
  program[0x9f] = 0;
  program[0xa0] = 0;
  program[0xa1] = 0;
  program[0xa2] = 0;
  program[0xa3] = 0;
  program[0xa4] = 0;
  program[0xa5] = 0;
  program[0xa6] = 0;
  program[0xa7] = 0;
  program[0xa8] = 0;
  program[0xa9] = 0;
  program[0xaa] = 0;
  program[0xab] = 0;
  program[0xcc] = 0;
  program[0xce] = 0;
  program[0xcf] = 0;
  program[0xd1] = 0;
  program[0xd2] = 0;
  program[0xd3] = 0;
  program[0xd4] = 0;
  program[0xd6] = 0;
  program[0xd7] = 0;
  program[0xd8] = 0;
  program[0xd9] = 0;
  program[0xda] = 0;
  program[0xdd] = 0;
  DListNode__init(program + 0xdf);
  clearCount0 = 0x10;
  program[0xfa] = 0x7fffffff;
  program[0xfe] = 1;
  program[0xf6] = 0x7fffffff;
  program[0x10a] = 0xffffffff;
  program[0x11f] = 0;
  program[0xe5] = 0;
  program[0xe6] = 0;
  program[0xe7] = 0;
  program[0xe9] = 0;
  program[0xed] = 0;
  program[0xf0] = 0;
  program[0xf3] = 0;
  program[0xf5] = 0;
  program[0xf7] = 0xffffffff;
  program[0xf8] = 0;
  program[0xf9] = 0;
  program[0xfb] = 0xffffffff;
  program[0xfc] = 0;
  program[0x11d] = 0;
  program[0x11e] = 0;
  zeroCursor = program;
  do {
    zeroCursor[0xe] = 0;
    zeroCursor = zeroCursor + 1;
    clearCount0 = clearCount0 + -1;
  } while (clearCount0 != 0);
  clearCount1 = 0x20;
  zeroCursor = program;
  do {
    zeroCursor[0xac] = 0;
    zeroCursor = zeroCursor + 1;
    clearCount1 = clearCount1 + -1;
  } while (clearCount1 != 0);
  arenaA = *(undefined4 *)(program[2] + 0x374);
  allocation = (undefined4 *)Arena__alloc(arenaA,0x6c);
  *allocation = arenaA;
  FUN_001272cc(allocation + 1,program[2]);
  program[0xeb] = allocation + 1;
  arenaA = *(undefined4 *)(program[2] + 0x374);
  registerTableAlloc = (undefined4 *)Arena__alloc(arenaA,0x20c);
  registerTableAlloc[1] = 0x80;
  tableClearCount = 0x80;
  *registerTableAlloc = arenaA;
  registerTableAlloc[2] = 0x1000;
  tableData = registerTableAlloc + 1;
  do {
    tableData[2] = 0;
    tableData = tableData + 1;
    tableClearCount = tableClearCount + -1;
  } while (tableClearCount != 0);
  program[0xec] = registerTableAlloc + 1;
  arenaA = *(undefined4 *)(program[2] + 0x374);
  hwRegisterTableAlloc = (undefined4 *)Arena__alloc(arenaA,0x8c);
  hwRegisterTableAlloc[1] = 0x20;
  *hwRegisterTableAlloc = arenaA;
  hwRegisterTableAlloc[2] = 0x400;
  hwTableClearCount = 0x20;
  tableData = hwRegisterTableAlloc + 1;
  do {
    tableData[2] = 0;
    tableData = tableData + 1;
    hwTableClearCount = hwTableClearCount + -1;
  } while (hwTableClearCount != 0);
  program[0xef] = hwRegisterTableAlloc + 1;
  arenaA = *(undefined4 *)(program[2] + 0x374);
  allocation = (undefined4 *)Arena__alloc(arenaA,0x14);
  *allocation = arenaA;
  allocation[1] = 2;
  allocation[4] = arenaA;
  allocation[2] = 0;
  vectorData = Arena__alloc(arenaA,8);
  allocation[3] = vectorData;
  program[0xf1] = allocation + 1;
  arenaA = *(undefined4 *)(program[2] + 0x374);
  allocation = (undefined4 *)Arena__alloc(arenaA,0x14);
  *allocation = arenaA;
  allocation[1] = 2;
  allocation[2] = 0;
  allocation[4] = arenaA;
  vectorData = Arena__alloc(arenaA,8);
  allocation[3] = vectorData;
  clearCount4 = 4;
  program[0xf2] = allocation + 1;
  zeroCursor = program;
  do {
    zeroCursor[4] = 0;
    zeroCursor[8] = 0;
    zeroCursor = zeroCursor + 1;
    clearCount4 = clearCount4 + -1;
  } while (clearCount4 != 0);
  program[0xde] = 0;
  return;
}

/* FUN_000ee7a0 @ 0xee7a0 (144 bytes) */
int FUN_000ee7a0(param_1)
  int param_1;
{
  undefined4 *allocation;
  undefined4 vectorData;
  undefined4 arena;
  int listCount;
  int loopIndex2;
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  int loopIndex;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
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
      vectorData = Arena__alloc(arena,8);
      allocation[3] = vectorData;
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
          puVar2 = (undefined4 *)0x0;
          if (uVar6 - 1 < uVar6) {
            puVar2 = (undefined4 *)((uVar6 - 1) * 4 + *(int *)(iVar9 + 8));
          }
          uVar7 = *puVar2;
          iVar5 = iVar5 + -1;
          Vector__removeAt(iVar9,uVar6 - 1);
          *(undefined4 *)(iVar10 + iVar1) = uVar7;
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
  int loopCounter;
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
            loopCounter = 0;
            for (loopIndex = 1; loopIndex <= *(uint *)(*(int *)(iVar1 + 0x18) + 4); loopIndex = loopIndex + 1) {
              iVar2 = *(int *)(loopCounter + *(int *)(*(int *)(iVar1 + 0x18) + 8));
              if ((*(uint *)(iVar2 + 0x14) & 1) != 0) {
                *(uint *)(iVar2 + 0x14) = *(uint *)(iVar2 + 0x14) | 0x10;
                ((int (*)())Program__addInst)(program,iVar2);
              }
              loopCounter = loopCounter + 4;
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
            loopCounter = 0;
            for (loopIndex = 1; loopIndex <= *(uint *)(*(int *)(iVar1 + 0x18) + 4); loopIndex = loopIndex + 1) {
              iVar2 = *(int *)(loopCounter + *(int *)(*(int *)(iVar1 + 0x18) + 8));
              if ((*(uint *)(iVar2 + 0x14) & 1) != 0) {
                *(uint *)(iVar2 + 0x14) = *(uint *)(iVar2 + 0x14) | 0x10;
                ((int (*)())Program__addInst)(program,iVar2);
              }
              loopCounter = loopCounter + 4;
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
  undefined4 mulResultReg;
  undefined4 finalResultReg;
  undefined4 identitySelect;
  int exportInst;
  undefined4 parentBlock;
  undefined4 registerMap;
  undefined4 sourceSelectWord;
  undefined4 allComponentsSelect;
  int operandRecord4;
  int operandRecord3;
  int newInst;
  int operandRecord2;
  int newInst2;
  int operandRecord;
  int *nextInst;
  int inst;
  int madTempIndex;
  undefined4 madResultReg;
  int mulTempIndex;
  int finalTempIndex;
  int isInsertable;
  undefined4 *allocation;
  undefined4 arenaA;
  undefined4 sourceSelectWord2;
  undefined4 *newExport;
  int *candidate;
  double zeroFloat;
  
  if (*(int *)(program + 0x3e4) != 0) {
    candidate = *(int **)(*(int *)(program + 0x3a0) + 0x98);
    for (nextInst = (int *)candidate[2]; nextInst != (int *)0x0; nextInst = (int *)nextInst[2]) {
      if ((candidate[5] & 1U) != 0) {
        isInsertable = (**(code **)(*candidate + 0x4c))(candidate);
        if (isInsertable != 0) {
          if ((((*(int *)(program + 0x3e4) != 0) && (candidate[0x51] == *(int *)(program + 0x3f4))) &&
              (*(int *)(program + 1000) <= candidate[0x52])) &&
             (candidate[0x52] < *(int *)(program + 0x3ec))) {
            candidate[5] = candidate[5] | 0x10;
            ((int (*)())Program__addInst)(program,candidate);
            nextInst = (int *)candidate[2];
            goto LAB_000eed14;
          }
        }
        nextInst = (int *)candidate[2];
      }
LAB_000eed14:
      candidate = nextInst;
    }
    *(int *)(program + 0x3f0) = -*(int *)(program + 1000);
  }
  if ((*(int *)(program + 0x348) == 0) && (*(int *)(program + 0x350) == 0)) {
    exportInst = *(int *)(program + 0x34c);
    if (exportInst != 0) goto LAB_000eee08;
    arenaA = *(undefined4 *)(*(int *)(program + 8) + 0x374);
    allocation = (undefined4 *)Arena__alloc(arenaA,0x168);
    *allocation = arenaA;
    newExport = allocation + 1;
    IRExport__ctor_108918(newExport,*(undefined4 *)(program + 8));
    *(undefined4 **)(program + 0x348) = newExport;
    operandRecord4 = IRInst__getOperandRecord(newExport,0);
    allComponentsSelect = DAT_001aa800;
    zeroFloat = (double)FLOAT_001aa0d4;
    *(undefined4 *)(operandRecord4 + 0xc) = 9;
    *(undefined4 *)(operandRecord4 + 8) = 0;
    allocation[0x28] = allComponentsSelect;
    ((void (*)())IRInst__makeLiteralVec4Float)(newExport,program,1,zeroFloat,zeroFloat,zeroFloat,zeroFloat);
    Program__appendInst(program,newExport,*(undefined4 *)(program + 0x3a8));
  }
  exportInst = *(int *)(program + 0x34c);
  if (exportInst == 0) {
    return;
  }
LAB_000eee08:
  if ((*(uint *)(*(int *)(*(int *)(program + 8) + 0x30c) + 8) & 0x4000) == 0) {
    return;
  }
  inst = IRInst__create(0x17,*(undefined4 *)(program + 8));
  IRInst__setOperandRef(inst,1,*(undefined4 *)(exportInst + 0xa4));
  operandRecord = IRInst__getOperandRecord(exportInst,1);
  zeroFloat = (double)FLOAT_001aa0d4;
  sourceSelectWord = *(undefined4 *)(operandRecord + 0x10);
  operandRecord = IRInst__getOperandRecord(inst,1);
  *(undefined4 *)(operandRecord + 0x10) = sourceSelectWord;
  ((void (*)())IRInst__makeLiteralVec4Float)(inst,program,2,0.5000000596046448,zeroFloat,zeroFloat,zeroFloat);
  registerMap = *(undefined4 *)(program + 0x3ac);
  madTempIndex = *(int *)(*(int *)(program + 8) + 0x3ac) + -1;
  *(int *)(*(int *)(program + 8) + 0x3ac) = madTempIndex;
  madResultReg = FUN_00127608(registerMap,0,madTempIndex,0);
  IRInst__setOperandRef(inst,0,madResultReg);
  allComponentsSelect = DAT_001aa800;
  *(undefined4 *)(inst + 0x120) = 1;
  *(undefined4 *)(inst + 0x9c) = allComponentsSelect;
  newInst2 = IRInst__create(0x13,*(undefined4 *)(program + 8));
  IRInst__setOperandRef(newInst2,1,*(undefined4 *)(exportInst + 0xa4));
  operandRecord2 = IRInst__getOperandRecord(exportInst,1);
  sourceSelectWord2 = *(undefined4 *)(operandRecord2 + 0x10);
  operandRecord2 = IRInst__getOperandRecord(newInst2,1);
  *(undefined4 *)(operandRecord2 + 0x10) = sourceSelectWord2;
  ((void (*)())IRInst__makeLiteralVec4Float)(newInst2,program,2,0.9999999403953552,zeroFloat,zeroFloat,zeroFloat);
  mulResultReg = *(undefined4 *)(program + 0x3ac);
  mulTempIndex = *(int *)(*(int *)(program + 8) + 0x3ac) + -1;
  *(int *)(*(int *)(program + 8) + 0x3ac) = mulTempIndex;
  mulResultReg = FUN_00127608(mulResultReg,0,mulTempIndex,0);
  IRInst__setOperandRef(newInst2,0,mulResultReg);
  *(undefined4 *)(newInst2 + 0x120) = 1;
  *(undefined4 *)(newInst2 + 0x9c) = allComponentsSelect;
  newInst = IRInst__create(0x14,*(undefined4 *)(program + 8));
  IRInst__setOperandRef(newInst,1,madResultReg);
  identitySelect = DAT_001aa810;
  operandRecord3 = IRInst__getOperandRecord(newInst,1);
  *(undefined4 *)(operandRecord3 + 0x10) = identitySelect;
  ((void (*)())IRInst__makeLiteralVec4Float)(newInst,program,2,0.9999999403953552,zeroFloat,zeroFloat,zeroFloat);
  IRInst__setOperandRef(newInst,3,mulResultReg);
  operandRecord3 = IRInst__getOperandRecord(newInst,3);
  *(undefined4 *)(operandRecord3 + 0x10) = identitySelect;
  finalResultReg = *(undefined4 *)(program + 0x3ac);
  finalTempIndex = *(int *)(*(int *)(program + 8) + 0x3ac) + -1;
  *(int *)(*(int *)(program + 8) + 0x3ac) = finalTempIndex;
  finalResultReg = FUN_00127608(finalResultReg,0,finalTempIndex,0);
  IRInst__setOperandRef(newInst,0,finalResultReg);
  *(undefined4 *)(newInst + 0x120) = 0;
  *(undefined4 *)(newInst + 0x9c) = allComponentsSelect;
  IRInst__setOperandRef(exportInst,1,finalResultReg);
  parentBlock = *(undefined4 *)(exportInst + 0x158);
  Block__insertInstBefore(parentBlock,exportInst,newInst);
  Block__insertInstBefore(parentBlock,newInst,newInst2);
  Block__insertInstBefore(parentBlock,newInst2,inst);
  return;
}

/* FUN_000eee4c @ 0xeee4c (492 bytes) */
int FUN_000eee4c(program)
  int program;
{
  int *subVReg;
  int resultVReg;
  int hwRegIndex;
  int destKind;
  int isPixelShaderHw;
  int *insertAfterInst;
  int *hwDescription;
  int newSourceIndex;
  int regInfo;
  undefined4 arenaA;
  int operandRecord2;
  int operandRecord;
  int block;
  int *nextInst;
  int nextBlock;
  int *followingInst;
  undefined4 *allocation;
  int iVar6;
  int *hwDescriptionObj;
  int supportsProjection;
  int *projection;
  undefined4 tempVReg;
  code *createSubReg;
  int resultVRegCopy;
  int *inst;
  
  block = *(int *)(program + 900);
  nextBlock = *(int *)(*(int *)(program + 900) + 8);
  do {
    if (nextBlock == 0) {
      return;
    }
    nextInst = (int *)(*(int **)(block + 0x98))[2];
    inst = *(int **)(block + 0x98);
    if (nextInst != (int *)0x0) {
      do {
        followingInst = nextInst;
        if ((inst[5] & 1U) != 0) {
          hwDescription = *(int **)(*(int *)(program + 8) + 0x30c);
          isPixelShaderHw = (**(code **)(*hwDescription + 0xcc))(hwDescription);
          if (isPixelShaderHw == 0) {
            if (*(int *)(inst[0x22] + 8) == 0x77) {
              tempVReg = FUN_00127608(*(undefined4 *)(program + 0x3ac),0x30,0,0);
              IRInst__setOperandRef(inst,0,tempVReg);
              inst[5] = inst[5] | 0x10;
              FUN_0012306c(tempVReg,inst);
              ((int (*)())Program__addInst)(program,inst);
            }
          }
          else if ((((inst[5] & 2U) != 0) && (isPixelShaderHw = RegKind__vectorWidthKind(inst[0x26]), isPixelShaderHw == 9))
                  && (isPixelShaderHw = FUN_00127534(*(undefined4 *)(program + 0x3ac),0x21,0,0), isPixelShaderHw != 0))
          {
            IRInst__appendSource(inst,isPixelShaderHw);
          }
          destKind = inst[0x26];
          if (destKind == 0x2a) {
            hwRegIndex = *(int *)(program + 1000);
            insertAfterInst = inst;
            if (hwRegIndex < *(int *)(program + 0x3ec)) {
              do {
                subVReg = (int *)FUN_00127608(*(undefined4 *)(program + 0x3ac),
                                             *(undefined4 *)(program + 0x3f4),hwRegIndex,0);
                arenaA = *(undefined4 *)(*(int *)(program + 8) + 0x374);
                allocation = (undefined4 *)Arena__alloc(arenaA,0x168);
                *allocation = arenaA;
                projection = allocation + 1;
                IRProjection__ctor_109e28(projection,0x84,*(undefined4 *)(program + 8));
                allocation[0x4b] = hwRegIndex;
                createSubReg = *(code **)(*subVReg + 0x28);
                operandRecord = IRInst__getOperandRecord(inst,0);
                iVar6 = (*createSubReg)(subVReg,*(undefined4 *)(operandRecord + 0x10),program);
                hwDescriptionObj = *(int **)(*(int *)(program + 8) + 0x30c);
                supportsProjection = (**(code **)(*hwDescriptionObj + 0xd8))(hwDescriptionObj);
                if (supportsProjection != 0) {
                  *(int *)(iVar6 + 0x10) = hwRegIndex;
                  *(uint *)(iVar6 + 0x24) = *(uint *)(iVar6 + 0x24) | 2;
                  Program__markHwRegUsed(program,hwRegIndex);
                  FUN_00130bd4(program,hwRegIndex);
                }
                resultVRegCopy = inst[0x23];
                IRInst__setOperandRef(projection,0,iVar6);
                hwRegIndex = hwRegIndex + 1;
                operandRecord2 = IRInst__getOperandRecord(inst,0);
                allocation[0x28] = *(undefined4 *)(operandRecord2 + 0x10);
                FUN_0012306c(iVar6,projection);
                IRInst__setOperandRef(projection,1,resultVRegCopy);
                VReg__addUse(resultVRegCopy,1,projection);
                IRInst__appendSource(projection,iVar6);
                VReg__addUse(iVar6,2,projection);
                Block__insertInstAfter(block,insertAfterInst,projection);
                regInfo = (**(code **)(*subVReg + 0x2c))(subVReg);
                *(undefined4 *)(regInfo + 0x144) = 1;
                insertAfterInst = projection;
              } while (hwRegIndex < *(int *)(program + 0x3ec));
              followingInst = (int *)allocation[3];
            }
            else {
LAB_000ef1c8:
              followingInst = (int *)inst[2];
            }
          }
          else {
            if ((inst[0x21] == 0) || ((destKind != 0x3b && (destKind != 0x2c)))) {
              if ((inst[0x20] == 0) ||
                 ((destKind = FUN_000f3154(inst), destKind == 0 ||
                  (destKind = (**(code **)(*inst + 0x4c))(inst), destKind != 0))))
              goto LAB_000ef1c8;
              resultVReg = inst[0x23];
              IRInst__appendSource(inst,resultVReg);
            }
            else {
              resultVReg = inst[0x23];
              newSourceIndex = inst[0x21] + 1;
              inst[0x21] = newSourceIndex;
              IRInst__setOperandRef(inst,newSourceIndex,resultVReg);
            }
            VReg__addUse(resultVReg,inst[0x21],inst);
            followingInst = (int *)inst[2];
          }
        }
        nextInst = (int *)followingInst[2];
        inst = followingInst;
      } while ((int *)followingInst[2] != (int *)0x0);
      nextBlock = *(int *)(block + 8);
    }
    block = nextBlock;
    nextBlock = *(int *)(nextBlock + 8);
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
  int loopCounter;
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
            loopCounter = 0;
            piVar2 = (int *)PTR_DAT_001e8b64;
            do {
              operandRecord2 = IRInst__getOperandRecord(piVar3,0);
              if (*(char *)(loopCounter + operandRecord2 + 0x10) != '\x01') {
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
              bVar1 = loopCounter != 3;
              piVar2 = piVar2 + 1;
              loopCounter = loopCounter + 1;
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
  int compiler;
  int *blockCursor;
  int *bitsetData;
  int hwCountSlot13c;
  int bitsetWordsLeft;
  int hwCountSlot140;
  int tableSize;
  int bitsetWords;
  int bitsetBytes;
  int hwCountSlot138;
  undefined4 shaderKind;
  undefined4 registerTable;
  uint loopIndex;
  int *wordCursor;
  int iVar2;
  int loopCounter;
  undefined4 *allocation;
  undefined4 *tableAlloc;
  char *extraout_r4;
  undefined4 extraout_r4_00;
  char *pcVar6;
  int iVar7;
  int *hwDescription;
  undefined4 arenaA;
  uint wordsLeft;
  uint bitsetWordCount;
  
  compiler = *(int *)(program + 8);
  hwDescription = *(int **)(compiler + 0x30c);
  hwCountSlot138 = (**(code **)(*hwDescription + 0x138))(hwDescription,compiler);
  hwCountSlot140 = (**(code **)(*hwDescription + 0x140))(hwDescription,compiler);
  compiler = (**(code **)(*hwDescription + 0x13c))(hwDescription,compiler);
  compiler = hwCountSlot138 + hwCountSlot140 + compiler;
  arenaA = *(undefined4 *)(*(int *)(program + 8) + 0x374);
  bitsetWordCount = compiler + 0x1fU >> 5;
  bitsetBytes = bitsetWordCount * 4 + 0xc;
  allocation = (undefined4 *)Arena__alloc(arenaA,bitsetBytes);
  bitsetData = allocation + 1;
  *allocation = arenaA;
  allocation[1] = bitsetWordCount;
  allocation[2] = compiler;
  if (bitsetWordCount != 0) {
    wordCursor = bitsetData;
    wordsLeft = bitsetWordCount;
    if (bitsetWordCount == 0) {
      wordsLeft = 1;
    }
    do {
      wordCursor[2] = 0;
      wordCursor = wordCursor + 1;
      wordsLeft = wordsLeft - 1;
    } while (wordsLeft != 0);
  }
  *(int **)(program + 0x42c) = bitsetData;
  bitsetWordsLeft = *bitsetData;
  if (bitsetWordsLeft != 0) {
    if (bitsetWordsLeft == 0) {
      bitsetWordsLeft = 1;
    }
    do {
      bitsetData[2] = -1;
      bitsetData = bitsetData + 1;
      bitsetWordsLeft = bitsetWordsLeft + -1;
    } while (bitsetWordsLeft != 0);
  }
  arenaA = *(undefined4 *)(*(int *)(program + 8) + 0x374);
  allocation = (undefined4 *)Arena__alloc(arenaA,bitsetBytes);
  bitsetData = allocation + 1;
  *allocation = arenaA;
  allocation[1] = bitsetWordCount;
  allocation[2] = compiler;
  if (bitsetWordCount != 0) {
    wordCursor = bitsetData;
    if (bitsetWordCount == 0) {
      bitsetWordCount = 1;
    }
    do {
      wordCursor[2] = 0;
      wordCursor = wordCursor + 1;
      bitsetWordCount = bitsetWordCount - 1;
    } while (bitsetWordCount != 0);
  }
  *(int **)(program + 0x430) = bitsetData;
  bitsetWords = *bitsetData;
  if (bitsetWords != 0) {
    if (bitsetWords == 0) {
      bitsetWords = 1;
    }
    do {
      bitsetData[2] = -1;
      bitsetData = bitsetData + 1;
      bitsetWords = bitsetWords + -1;
    } while (bitsetWords != 0);
  }
  arenaA = *(undefined4 *)(*(int *)(program + 8) + 0x374);
  tableAlloc = (undefined4 *)Arena__alloc(arenaA,0x8c);
  tableAlloc[1] = 0x20;
  tableSize = 0x20;
  *tableAlloc = arenaA;
  tableAlloc[2] = 0x400;
  allocation = tableAlloc + 1;
  do {
    allocation[2] = 0;
    allocation = allocation + 1;
    tableSize = tableSize + -1;
  } while (tableSize != 0);
  *(undefined4 **)(program + 0x434) = tableAlloc + 1;
  *(undefined4 *)(program + 0x43c) = 0;
  hwDescription = *(int **)(*(int *)(program + 8) + 0x30c);
  hwCountSlot138 = (**(code **)(*hwDescription + 0x138))(hwDescription,*(int *)(program + 8));
  *(int *)(program + 0x448) = hwCountSlot138;
  *(int *)(program + 0x440) = hwCountSlot138;
  hwDescription = *(int **)(*(int *)(program + 8) + 0x30c);
  hwCountSlot140 = (**(code **)(*hwDescription + 0x140))(hwDescription,*(int *)(program + 8));
  hwCountSlot138 = hwCountSlot138 + hwCountSlot140;
  *(int *)(program + 0x44c) = hwCountSlot138;
  *(int *)(program + 0x444) = hwCountSlot138;
  hwDescription = *(int **)(*(int *)(program + 8) + 0x30c);
  hwCountSlot13c = (**(code **)(*hwDescription + 0x13c))(hwDescription,*(int *)(program + 8));
  *(int *)(program + 0x450) = hwCountSlot138 + hwCountSlot13c;
  registerTable = Arena__alloc(*(undefined4 *)(*(int *)(program + 8) + 0x374),
                       *(int *)(*(int *)(*(int *)(program + 8) + 0x30c) + 0x50) * 0xc);
  *(undefined4 *)(program + 0x78) = registerTable;
  arenaA = *(undefined4 *)(*(int *)(program + 8) + 0x374);
  allocation = (undefined4 *)Arena__alloc(arenaA,0x134);
  *allocation = arenaA;
  allocation = allocation + 1;
  EntryBlock__ctor_eab70(allocation,*(undefined4 *)(program + 8));
  *(undefined4 **)(program + 0x3a0) = allocation;
  ((int (*)())FUN_000ec3e8)(program,allocation);
  arenaA = *(undefined4 *)(*(int *)(program + 8) + 0x374);
  allocation = (undefined4 *)Arena__alloc(arenaA,0x130);
  *allocation = arenaA;
  allocation = allocation + 1;
  ExitBlock__ctor_eaae8(allocation,*(undefined4 *)(program + 8));
  *(undefined4 **)(program + 0x3a8) = allocation;
  ((int (*)())FUN_000ec42c)(program,allocation);
  VRegInfo__new_127994(*(undefined4 *)(program + 0x3ac),*(uint *)(program + 0x30) & 1);
  hwDescription = *(int **)(*(int *)(program + 8) + 0x30c);
  (**(code **)(*hwDescription + 0x10))(hwDescription,*(int *)(program + 8));
  FUN_000fd5c8(program,ilReader);
  if ((*(uint *)(program + 0x30) & 1) == 0) {
    if ((*(uint *)(program + 0x30) & 0x2000) == 0) {
      shaderKind = 2;
      iVar2 = 2;
    }
    else {
      shaderKind = 1;
      iVar2 = 1;
    }
  }
  else {
    shaderKind = 0;
    iVar2 = 0;
  }
  hwDescription = *(int **)(*(int *)(program + 8) + 0x30c);
  (**(code **)(*hwDescription + 0x14))(hwDescription,shaderKind,*(int *)(program + 8));
  if (iVar2 == 1) {
    ((int (*)())FUN_000eec50)(program,extraout_r4_00);
  }
  else if ((iVar2 == 2) || (iVar2 == 0)) {
    hwDescription = *(int **)(*(int *)(program + 8) + 0x30c);
    (**(code **)(*hwDescription + 0xac))(hwDescription,*(undefined4 *)(program + 0x358),program,*(int *)(program + 8));
  }
  ((int (*)())FUN_000ef204)(program);
  FUN_0012eacc(program);
  ((int (*)())FUN_000eee4c)(program);
  ((int (*)())FUN_000eea24)(program);
  FUN_00138130(program);
  pcVar6 = "non_local_set";
  blockCursor = *(int **)(program + 900);
  iVar2 = blockCursor[2];
  while (iVar2 != 0) {
    (**(code **)(*blockCursor + 0x48))(blockCursor,pcVar6);
    blockCursor = (int *)blockCursor[2];
    pcVar6 = extraout_r4;
    iVar2 = blockCursor[2];
  }
  iVar2 = *(int *)(program + 0x3c4);
  loopCounter = 0;
  for (loopIndex = 1; loopIndex <= *(uint *)(iVar2 + 4); loopIndex = loopIndex + 1) {
    iVar7 = *(int *)(*(int *)(iVar2 + 8) + loopCounter);
    if ((*(uint *)(iVar7 + 0x14) & 1) != 0) {
      IRInst__getOperandRecord(iVar7,0);
      iVar2 = *(int *)(program + 0x3c4);
    }
    loopCounter = loopCounter + 4;
  }
  return 1;
}

/* Program__appendToVector3c8 @ 0xef8f8 (120 bytes) */
int Program__appendToVector3c8(program, value)
  int program;
  undefined4 value;
{
  undefined4 *puVar1;
  uint uVar2;
  uint *puVar3;
  
  puVar3 = *(uint **)(program + 0x3c8);
  uVar2 = puVar3[1];
  if (uVar2 < *puVar3) {
    _memset(uVar2 * 4 + puVar3[2],0,4);
    puVar1 = (undefined4 *)(uVar2 * 4 + puVar3[2]);
    puVar3[1] = uVar2 + 1;
  }
  else {
    puVar1 = (undefined4 *)Vector__elementRefGrow(puVar3,uVar2);
  }
  *puVar1 = value;
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
  int block;
  int postOrderRemaining;
  int successorByteOffset;
  int hasSuccessors;
  undefined4 *postOrderSlot;
  undefined4 *walkTopEntry;
  int *dfsStackSlot;
  uint postOrderCount;
  undefined4 postOrderBlock;
  undefined4 finishedBlock;
  undefined4 entryBlock;
  undefined4 vectorData;
  uint loopIndex;
  bool allSuccessorsVisited;
  int *dfsStackTop;
  undefined4 *allocation;
  undefined4 *vectorAlloc;
  undefined4 *entryPushSlot;
  int blockCursor;
  uint *postOrder;
  int successor;
  uint *dfsStack;
  undefined4 arenaB;
  uint dfsStackCount;
  uint dfsStackCountPush;
  int previousBlock;
  
  arenaB = *(undefined4 *)(*(int *)(program + 8) + 0x378);
  allocation = (undefined4 *)Arena__alloc(arenaB,0x14);
  dfsStack = allocation + 1;
  *allocation = arenaB;
  allocation[1] = 2;
  allocation[2] = 0;
  allocation[4] = arenaB;
  vectorData = Arena__alloc(arenaB,8);
  allocation[3] = vectorData;
  arenaB = *(undefined4 *)(*(int *)(program + 8) + 0x378);
  vectorAlloc = (undefined4 *)Arena__alloc(arenaB,0x14);
  postOrder = vectorAlloc + 1;
  *vectorAlloc = arenaB;
  vectorAlloc[1] = 2;
  vectorAlloc[2] = 0;
  vectorAlloc[4] = arenaB;
  vectorData = Arena__alloc(arenaB,8);
  vectorAlloc[3] = vectorData;
  previousBlock = *(int *)(program + 900);
  for (blockCursor = *(int *)(*(int *)(program + 900) + 8); blockCursor != 0; blockCursor = *(int *)(blockCursor + 8)) {
    *(undefined4 *)(previousBlock + 0x118) = 0;
    previousBlock = blockCursor;
  }
  dfsStackCount = allocation[2];
  entryBlock = *(undefined4 *)(program + 0x3a0);
  if (dfsStackCount < *dfsStack) {
    _memset((void *)(dfsStackCount * 4 + allocation[3]),0,4);
    entryPushSlot = (undefined4 *)(dfsStackCount * 4 + allocation[3]);
    allocation[2] = dfsStackCount + 1;
  }
  else {
    entryPushSlot = (undefined4 *)Vector__elementRefGrow(dfsStack,dfsStackCount);
  }
  *entryPushSlot = entryBlock;
  *(undefined4 *)(*(int *)(program + 0x3a0) + 0x118) = 1;
code_r0x000efd60:
  dfsStackCount = allocation[2];
  if (dfsStackCount == 0) {
    DList__initSentinel(program + 0x37c);
    postOrderRemaining = vectorAlloc[2];
    while (postOrderRemaining != 0) {
      allocation = (undefined4 *)0x0;
      if (postOrderRemaining - 1U < (uint)vectorAlloc[2]) {
        allocation = (undefined4 *)((postOrderRemaining - 1U) * 4 + vectorAlloc[3]);
      }
      finishedBlock = *allocation;
      Vector__removeAt(postOrder,vectorAlloc[2] - 1);
      DList__pushBack(program + 0x37c,finishedBlock);
      ((int (*)())Program__freeWorkArrays)(program);
      postOrderRemaining = vectorAlloc[2];
    }
    return;
  }
  dfsStackTop = (int *)0x0;
  if (dfsStackCount - 1 < dfsStackCount) {
    dfsStackTop = (int *)((dfsStackCount - 1) * 4 + allocation[3]);
  }
  block = *dfsStackTop;
  Vector__removeAt(dfsStack,dfsStackCount - 1);
  dfsStackCount = allocation[2];
  if (dfsStackCount < *dfsStack) {
    _memset((void *)(dfsStackCount * 4 + allocation[3]),0,4);
    dfsStackSlot = (int *)(dfsStackCount * 4 + allocation[3]);
    allocation[2] = dfsStackCount + 1;
  }
  else {
    dfsStackSlot = (int *)Vector__elementRefGrow(dfsStack,dfsStackCount);
  }
  *dfsStackSlot = block;
  hasSuccessors = Block__hasSuccessors(block);
  if (hasSuccessors != 0) goto code_r0x000efc2c;
  goto code_r0x000efce4;
code_r0x000efc2c:
  allSuccessorsVisited = true;
  successorByteOffset = 0;
  for (loopIndex = 1; loopIndex <= *(uint *)(*(int *)(block + 0xd0) + 4); loopIndex = loopIndex + 1) {
    successor = *(int *)(successorByteOffset + *(int *)(*(int *)(block + 0xd0) + 8));
    if ((successor != 0) && (*(int *)(successor + 0x118) == 0)) {
      dfsStackCountPush = allocation[2];
      if (dfsStackCountPush < *dfsStack) {
        _memset((void *)(dfsStackCountPush * 4 + allocation[3]),0,4);
        dfsStackSlot = (int *)(dfsStackCountPush * 4 + allocation[3]);
        allocation[2] = dfsStackCountPush + 1;
      }
      else {
        dfsStackSlot = (int *)Vector__elementRefGrow(dfsStack,dfsStackCountPush);
      }
      *dfsStackSlot = successor;
      allSuccessorsVisited = false;
      *(undefined4 *)(successor + 0x118) = 1;
    }
    successorByteOffset = successorByteOffset + 4;
  }
  if (allSuccessorsVisited) {
code_r0x000efce4:
    dfsStackCount = allocation[2];
    walkTopEntry = (undefined4 *)0x0;
    if (dfsStackCount - 1 < dfsStackCount) {
      walkTopEntry = (undefined4 *)((dfsStackCount - 1) * 4 + allocation[3]);
    }
    postOrderBlock = *walkTopEntry;
    Vector__removeAt(dfsStack,dfsStackCount - 1);
    postOrderCount = vectorAlloc[2];
    if (postOrderCount < *postOrder) {
      _memset((void *)(postOrderCount * 4 + vectorAlloc[3]),0,4);
      postOrderSlot = (undefined4 *)(postOrderCount * 4 + vectorAlloc[3]);
      vectorAlloc[2] = postOrderCount + 1;
    }
    else {
      postOrderSlot = (undefined4 *)Vector__elementRefGrow(postOrder,postOrderCount);
    }
    *postOrderSlot = postOrderBlock;
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
  int loopCounter;
  undefined4 *allocation;
  undefined4 vectorData;
  undefined4 arena;
  uint loopIndex;
  int *piVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint *puVar8;
  undefined4 uVar9;
  uint uVar10;
  
  if (((*(uint *)(param_1 + 0x30) & 1) == 0) && ((*(uint *)(param_1 + 0x30) & 0x2000) != 0)) {
    arena = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
    puVar2 = (undefined4 *)Arena__alloc(arena,0x168);
    *puVar2 = arena;
    puVar2 = puVar2 + 1;
    IRInst__ctor_10502c(puVar2,0x95,*(undefined4 *)(param_1 + 8));
  }
  else {
    arena = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
    puVar2 = (undefined4 *)Arena__alloc(arena,0x168);
    *puVar2 = arena;
    puVar2 = puVar2 + 1;
    IRInst__ctor_10502c(puVar2,0x96,*(undefined4 *)(param_1 + 8));
  }
  *(undefined4 **)(param_1 + 0x33c) = puVar2;
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
      vectorData = Arena__alloc(arena,8);
      loopCounter = 0;
      allocation[3] = vectorData;
      for (loopIndex = 1; loopIndex <= *(uint *)(*(int *)(iVar7 + 0xf4) + 4); loopIndex = loopIndex + 1) {
        uVar9 = *(undefined4 *)(*(int *)(*(int *)(iVar7 + 0xf4) + 8) + loopCounter);
        uVar10 = allocation[2];
        if (uVar10 < *puVar8) {
          _memset((void *)(uVar10 * 4 + allocation[3]),0,4);
          puVar3 = (undefined4 *)(uVar10 * 4 + allocation[3]);
          allocation[2] = uVar10 + 1;
        }
        else {
          puVar3 = (undefined4 *)Vector__elementRefGrow(puVar8,uVar10);
        }
        loopCounter = loopCounter + 4;
        *puVar3 = uVar9;
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
        loopCounter = 0;
        *(uint *)(iVar7 + 0xc) = *(uint *)(iVar7 + 0xc) | 8;
        for (loopIndex = 1; loopIndex <= *(uint *)(*(int *)(iVar7 + 0xf4) + 4); loopIndex = loopIndex + 1) {
          uVar9 = *(undefined4 *)(*(int *)(*(int *)(iVar7 + 0xf4) + 8) + loopCounter);
          uVar10 = allocation[2];
          if (uVar10 < *puVar8) {
            _memset((void *)(uVar10 * 4 + allocation[3]),0,4);
            puVar3 = (undefined4 *)(uVar10 * 4 + allocation[3]);
            allocation[2] = uVar10 + 1;
          }
          else {
            puVar3 = (undefined4 *)Vector__elementRefGrow(puVar8,uVar10);
          }
          loopCounter = loopCounter + 4;
          *puVar3 = uVar9;
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
  undefined4 vectorData;
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
  undefined4 arenaB;
  
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
    arenaB = *(undefined4 *)(*(int *)(param_1 + 8) + 0x378);
    allocation = (undefined4 *)Arena__alloc(arenaB,0x14);
    *allocation = arenaB;
    allocation[1] = 2;
    allocation[2] = 0;
    allocation[4] = arenaB;
    vectorData = Arena__alloc(arenaB,8);
    allocation[3] = vectorData;
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
  int loopCounter;
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
        loopCounter = 4;
        piVar5 = inst;
        do {
          if ((uint)(*(byte *)(piVar5 + 0x27) - 2) < 2) goto LAB_000f0628;
          piVar5 = (int *)((int)piVar5 + 1);
          loopCounter = loopCounter + -1;
        } while (loopCounter != 0);
      }
      IRInst__getOperandRecord(inst,0);
      IRInst__operandKindClass(inst,0);
    }
  }
LAB_000f0628:
  operandVReg = (int *)IRInst__getOperandSource(inst,1);
  loopCounter = 0;
  uVar7 = 0xffffffff;
  bVar2 = true;
  fVar6 = 0.0;
  (**(code **)(*operandVReg + 0x48))(operandVReg);
  do {
    operandRecord2 = IRInst__getOperandRecord(inst,0);
    if (*(char *)(loopCounter + operandRecord2 + 0x10) != '\x01') {
      iVar4 = IRInst__getOperandRecord(inst,1);
      uVar8 = (uint)*(byte *)(loopCounter + iVar4 + 0x10);
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
    bVar1 = loopCounter != 3;
    loopCounter = loopCounter + 1;
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
  uint consumerStackCount;
  uint maskStackCount;
  undefined4 *identityCursor;
  undefined4 *consumerStackTop;
  int *hwDescriptionObj;
  int *selectBytePtr;
  int *maskStackSlot;
  int *consumer;
  int *moveSource;
  int lastSourceIndex;
  int destKindClass;
  int sourceIndexB;
  int lanesLeft;
  int poppedSelectWord;
  int pushedSelectWord;
  int sourceIndex;
  int laneIndex;
  int destRegisterOffset;
  undefined4 pushedSource;
  undefined4 vectorData;
  undefined4 arenaB;
  int operandRecord3;
  int operandRecord4;
  int operandRecord;
  int operandRecord2;
  int *operandVReg;
  bool bVar1;
  uint initialCapacity;
  int *hwDescription;
  int iVar4;
  undefined4 *allocation;
  undefined4 *vectorAlloc;
  undefined4 *consumerStackSlot;
  int iVar8;
  int iVar9;
  int destRegister;
  uint *consumerStack;
  uint *maskStack;
  uint consumerStackCountInit;
  int *maskStackTop;
  int iVar15;
  undefined4 moveSourceSelect;
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
  
  hwDescription = *(int **)(*(int *)(pass + 8) + 0x30c);
  iVar4 = (**(code **)(*hwDescription + 0xb8))(hwDescription,afterInst,inst);
  if ((((iVar4 == 0) && ((inst[5] & 8U) == 0)) &&
      (iVar4 = (**(code **)(*inst + 0x18))(inst), iVar4 < 2)) &&
     (iVar4 = (**(code **)(*inst + 0x14))(inst), iVar4 != 0)) {
    moveSource = (int *)IRInst__getOperandSource(inst,1);
    iVar4 = (**(code **)(*inst + 0x68))(inst);
    if (((iVar4 != 0) || (iVar4 = (**(code **)(*inst + 100))(inst), iVar4 != 0)) &&
       (((inst[0x2e] & 1U) == 0 && ((inst[0x2e] & 2U) == 0)))) {
      operandRecord = IRInst__getOperandRecord(inst,1);
      moveSourceSelect = *(undefined4 *)(operandRecord + 0x10);
      operandRecord = IRInst__getOperandRecord(inst,0);
      WriteMask__fromSelectWord(&local_50,*(undefined4 *)(operandRecord + 0x10));
      SelectWord__maskUnused(local_4c,moveSourceSelect,local_50);
      local_88 = local_4c[0];
      iVar4 = ((int (*)())IRInst__isForwardable)(moveSource,local_4c[0],*(undefined4 *)(pass + 8));
      if (iVar4 != 0) {
        iVar4 = (**(code **)(*moveSource + 0x60))(moveSource);
        if (iVar4 != 0) {
          moveSource = (int *)FUN_0010cb48(moveSource,*(undefined4 *)(pass + 8));
          IRInst__setOperandSource(inst,1,moveSource,0,*(undefined4 *)(pass + 8));
        }
        destRegisterOffset = inst[0x26];
        arenaB = *(undefined4 *)(*(int *)(pass + 8) + 0x378);
        destRegister = inst[0x25];
        allocation = (undefined4 *)Arena__alloc(arenaB,0x14);
        consumerStack = allocation + 1;
        *allocation = arenaB;
        allocation[1] = 2;
        allocation[4] = arenaB;
        allocation[2] = 0;
        vectorData = Arena__alloc(arenaB,8);
        allocation[3] = vectorData;
        arenaB = *(undefined4 *)(*(int *)(pass + 8) + 0x378);
        vectorAlloc = (undefined4 *)Arena__alloc(arenaB,0x14);
        maskStack = vectorAlloc + 1;
        *vectorAlloc = arenaB;
        vectorAlloc[1] = 2;
        vectorAlloc[2] = 0;
        vectorAlloc[4] = arenaB;
        vectorData = Arena__alloc(arenaB,8);
        initialCapacity = allocation[1];
        consumerStackCountInit = allocation[2];
        vectorAlloc[3] = vectorData;
        if (consumerStackCountInit < initialCapacity) {
          _memset(consumerStackCountInit * 4 + allocation[3],0,4);
          allocation[2] = consumerStackCountInit + 1;
          consumerStackSlot = (undefined4 *)(consumerStackCountInit * 4 + allocation[3]);
        }
        else {
          consumerStackSlot = (undefined4 *)Vector__elementRefGrow(consumerStack,consumerStackCountInit);
        }
        pushedSelectWord = local_88;
        *consumerStackSlot = moveSource;
        maskStackCount = vectorAlloc[2];
        if (maskStackCount < *maskStack) {
          _memset(maskStackCount * 4 + vectorAlloc[3],0,4);
          consumer = (int *)(maskStackCount * 4 + vectorAlloc[3]);
          vectorAlloc[2] = maskStackCount + 1;
        }
        else {
          consumer = (int *)Vector__elementRefGrow(maskStack,maskStackCount);
        }
        *consumer = pushedSelectWord;
        *(int *)(pass + 0x474) = *(int *)(pass + 0x474) + 1;
code_r0x000f1384:
        do {
          while( true ) {
            do {
              do {
                consumerStackCount = allocation[2];
                if (consumerStackCount == 0) {
                  (**(code **)(*inst + 0xc))(inst,0,*(undefined4 *)(pass + 8));
                  if (consumerStack != (uint *)0x0) {
                    Arena__free(allocation[4],allocation[3]);
                    Arena__free(*allocation,allocation);
                  }
                  if (maskStack == (uint *)0x0) {
                    return;
                  }
                  Arena__free(vectorAlloc[4],vectorAlloc[3]);
                  Arena__free(*vectorAlloc,vectorAlloc);
                  return;
                }
                consumerStackTop = (undefined4 *)0x0;
                if (consumerStackCount - 1 < consumerStackCount) {
                  consumerStackTop = (undefined4 *)((consumerStackCount - 1) * 4 + allocation[3]);
                }
                consumer = (int *)*consumerStackTop;
                Vector__removeAt(consumerStack,consumerStackCount - 1);
                maskStackCount = vectorAlloc[2];
                maskStackTop = (int *)0x0;
                if (maskStackCount - 1 < maskStackCount) {
                  maskStackTop = (int *)((maskStackCount - 1) * 4 + vectorAlloc[3]);
                }
                poppedSelectWord = *maskStackTop;
                Vector__removeAt(maskStack,maskStackCount - 1);
                local_88 = poppedSelectWord;
                poppedSelectWord = ((int (*)())IRInst__isForwardable)(consumer,poppedSelectWord,*(undefined4 *)(pass + 8));
                if ((poppedSelectWord != 0) && (poppedSelectWord = (**(code **)(*consumer + 0x60))(consumer), poppedSelectWord != 0))
                {
                  consumer = (int *)FUN_0010cb48(consumer,*(undefined4 *)(pass + 8));
                }
              } while ((*(int *)(pass + 0x474) == consumer[0x54]) &&
                      (*(int *)(consumer[0x22] + 8) == 0x8e));
              consumer[0x54] = *(int *)(pass + 0x474);
              iVar15 = (**(code **)(*consumer + 0x50))(consumer);
            } while (iVar15 != 0);
            local_80 = local_88;
            local_84 = local_88;
            operandRecord2 = IRInst__getOperandRecord(consumer,0);
            laneIndex = 0;
            local_7c = *(undefined4 *)(operandRecord2 + 0x10);
            lanesLeft = 4;
            do {
              if (*(byte *)((int)&local_88 + laneIndex) != 4) {
                if (auStack_78[*(byte *)((int)&local_88 + laneIndex) - 4] == '\x01') {
                  *(undefined1 *)((int)&local_84 + laneIndex) = 4;
                }
                else {
                  *(undefined1 *)((int)&local_80 + laneIndex) = 4;
                }
              }
              iVar8 = local_80;
              laneIndex = laneIndex + 1;
              lanesLeft = lanesLeft + -1;
            } while (lanesLeft != 0);
            if (local_84 != 0x4040404) break;
            if (((consumer[5] & 0x200U) != 0) && (local_80 != 0x4040404)) {
              maskStackCount = vectorAlloc[2];
              if (maskStackCount < *maskStack) {
                _memset(maskStackCount * 4 + vectorAlloc[3],0,4);
                vectorAlloc[2] = maskStackCount + 1;
                maskStackSlot = (int *)(maskStackCount * 4 + vectorAlloc[3]);
              }
              else {
                maskStackSlot = (int *)Vector__elementRefGrow(maskStack,maskStackCount);
              }
              *maskStackSlot = iVar8;
              pushedSource = IRInst__getOperandSource(consumer,consumer[0x21]);
              consumerStackCount = allocation[2];
              if (consumerStackCount < *consumerStack) {
                _memset(consumerStackCount * 4 + allocation[3],0,4);
                allocation[2] = consumerStackCount + 1;
                consumerStackSlot = (undefined4 *)(consumerStackCount * 4 + allocation[3]);
              }
              else {
                consumerStackSlot = (undefined4 *)Vector__elementRefGrow(consumerStack,consumerStackCount);
              }
              *consumerStackSlot = pushedSource;
            }
          }
          iVar15 = ((int (*)())IRInst__isForwardable)(consumer,local_84,*(undefined4 *)(pass + 8));
          if (iVar15 != 0) {
            iVar9 = (**(code **)(*consumer + 0x7c))(consumer);
            iVar15 = local_80;
            if (iVar9 == 0) {
              if (((consumer[5] & 0x200U) != 0) && (local_80 != 0x4040404)) {
                maskStackCount = vectorAlloc[2];
                if (maskStackCount < *maskStack) {
                  _memset(maskStackCount * 4 + vectorAlloc[3],0,4);
                  vectorAlloc[2] = maskStackCount + 1;
                  maskStackSlot = (int *)(maskStackCount * 4 + vectorAlloc[3]);
                }
                else {
                  maskStackSlot = (int *)Vector__elementRefGrow(maskStack,maskStackCount);
                }
                *maskStackSlot = iVar15;
                pushedSource = IRInst__getOperandSource(consumer,consumer[0x21]);
                consumerStackCount = allocation[2];
                if (consumerStackCount < *consumerStack) {
                  _memset(consumerStackCount * 4 + allocation[3],0,4);
                  allocation[2] = consumerStackCount + 1;
                  consumerStackSlot = (undefined4 *)(consumerStackCount * 4 + allocation[3]);
                }
                else {
                  consumerStackSlot = (undefined4 *)Vector__elementRefGrow(consumerStack,consumerStackCount);
                }
                *consumerStackSlot = pushedSource;
                IRInst__setOperandSource(consumer,consumer[0x21],0,0,*(undefined4 *)(pass + 8));
                consumer[0x21] = consumer[0x21] + -1;
                consumer[5] = consumer[5] & 0xfffffdff;
              }
              iVar15 = (**(code **)(*consumer + 100))(consumer);
              if (iVar15 != 0) {
                for (sourceIndexB = 1; iVar9 = (**(code **)(*consumer + 0x14))(consumer), sourceIndexB <= iVar9;
                    sourceIndexB = sourceIndexB + 1) {
                  if ((((consumer[sourceIndexB * 6 + 0x28] & 1U) != 0) ||
                      ((consumer[sourceIndexB * 6 + 0x28] & 2U) != 0)) ||
                     (iVar9 = IRInst__isSourceSelectIdentity(consumer,sourceIndexB), iVar9 == 0)) goto code_r0x000f101c;
                }
                if ((consumer[0x48] == 0) && (consumer[0x49] == 0)) {
                  if (((consumer[0x20] != 0) &&
                      ((sourceIndexB = RegKind__flagBit0(consumer[0x26]), sourceIndexB != 0 && ((consumer[5] & 2U) == 0))
                      )) && (sourceIndexB = (**(code **)(*consumer + 0x50))(consumer), sourceIndexB == 0)) {
                    lanesLeft = 4;
                    selectBytePtr = consumer;
                    do {
                      if ((uint)(*(byte *)(selectBytePtr + 0x27) - 2) < 2) goto code_r0x000f101c;
                      selectBytePtr = (int *)((int)selectBytePtr + 1);
                      lanesLeft = lanesLeft + -1;
                    } while (lanesLeft != 0);
                  }
                  IRInst__getOperandRecord(consumer,0);
                  destKindClass = IRInst__operandKindClass(consumer,0);
                  if ((destKindClass == 0) && ((consumer[5] & 2U) == 0)) {
                    pushedSource = IRInst__getOperandSource(consumer,1);
                    iVar9 = ((int (*)())IRInst__isForwardable)(pushedSource,local_84,*(undefined4 *)(pass + 8));
                    pushedSelectWord = local_84;
                    if (iVar9 != 0) {
                      maskStackCount = vectorAlloc[2];
                      if (maskStackCount < *maskStack) {
                        _memset(maskStackCount * 4 + vectorAlloc[3],0,4);
                        vectorAlloc[2] = maskStackCount + 1;
                        maskStackSlot = (int *)(maskStackCount * 4 + vectorAlloc[3]);
                      }
                      else {
                        maskStackSlot = (int *)Vector__elementRefGrow(maskStack,maskStackCount);
                      }
                      *maskStackSlot = pushedSelectWord;
                      pushedSource = IRInst__getOperandSource(consumer,1);
                      consumerStackCount = allocation[2];
                      if (consumerStackCount < *consumerStack) {
                        _memset(consumerStackCount * 4 + allocation[3],0,4);
                        allocation[2] = consumerStackCount + 1;
                        consumerStackSlot = (undefined4 *)(consumerStackCount * 4 + allocation[3]);
                      }
                      else {
                        consumerStackSlot = (undefined4 *)Vector__elementRefGrow(consumerStack,consumerStackCount);
                      }
                      *consumerStackSlot = pushedSource;
                      goto code_r0x000f1140;
                    }
                  }
                }
              }
code_r0x000f101c:
              IRInst__setHardwareRegisterAndAdd(consumer,pass,destRegisterOffset,destRegister);
              (**(code **)(*consumer + 0x94))(consumer,afterInst,*(undefined4 *)(pass + 8));
              SelectWord__clearReadComponents(&local_58,local_84);
              consumer[0x27] = local_58;
              iVar15 = SelectWord__areCompatible(local_84,0x10203);
              if ((iVar15 == 0) &&
                 (iVar15 = FUN_0011379c(*(undefined4 *)(pass + 8),consumer), iVar15 != 0)) {
                for (sourceIndexB = 1; iVar9 = (**(code **)(*consumer + 0x14))(consumer), sourceIndexB <= iVar9;
                    sourceIndexB = sourceIndexB + 1) {
                  operandRecord3 = IRInst__getOperandRecord(consumer,sourceIndexB);
                  ((int (*)())SelectWord__compose)(&local_54,*(undefined4 *)(operandRecord3 + 0x10),local_84);
                  iVar9 = local_54;
                  if (sourceIndexB == 0) {
                    consumer[0x27] = local_54;
                  }
                  else {
                    operandRecord4 = IRInst__getOperandRecord(consumer,sourceIndexB);
                    *(int *)(operandRecord4 + 0x10) = iVar9;
                  }
                }
              }
              iVar15 = (**(code **)(*consumer + 100))(consumer);
              if (iVar15 != 0) {
                for (sourceIndexB = 1; iVar9 = (**(code **)(*consumer + 0x14))(consumer), sourceIndexB <= iVar9;
                    sourceIndexB = sourceIndexB + 1) {
                  if ((((consumer[sourceIndexB * 6 + 0x28] & 1U) != 0) ||
                      ((consumer[sourceIndexB * 6 + 0x28] & 2U) != 0)) ||
                     (iVar9 = IRInst__isSourceSelectIdentity(consumer,sourceIndexB), iVar9 == 0)) goto code_r0x000f1384;
                }
                if ((consumer[0x48] == 0) && (consumer[0x49] == 0)) {
                  if (((consumer[0x20] != 0) &&
                      ((sourceIndexB = RegKind__flagBit0(consumer[0x26]), sourceIndexB != 0 && ((consumer[5] & 2U) == 0))
                      )) && (sourceIndexB = (**(code **)(*consumer + 0x50))(consumer), sourceIndexB == 0)) {
                    lanesLeft = 4;
                    selectBytePtr = consumer;
                    do {
                      if ((uint)(*(byte *)(selectBytePtr + 0x27) - 2) < 2) goto code_r0x000f1384;
                      selectBytePtr = (int *)((int)selectBytePtr + 1);
                      lanesLeft = lanesLeft + -1;
                    } while (lanesLeft != 0);
                  }
                  IRInst__getOperandRecord(consumer,0);
                  destKindClass = IRInst__operandKindClass(consumer,0);
                  if (destKindClass == 0) {
                    operandVReg = (int *)IRInst__getOperandSource(consumer,1);
                    iVar15 = (**(code **)(*operandVReg + 0x48))();
                    if (iVar15 != 0) {
                      lanesLeft = 4;
                      identityCursor = local_74;
                      do {
                        *identityCursor = 0x7ffffffe;
                        identityCursor = identityCursor + 1;
                        lanesLeft = lanesLeft + -1;
                      } while (lanesLeft != 0);
                      local_74[0] = 0x3f800000;
                      local_74[3] = 0x3f800000;
                      local_74[2] = 0x3f800000;
                      local_74[1] = 0x3f800000;
                      hwDescriptionObj = *(int **)(*(int *)(pass + 8) + 0x30c);
                      iVar15 = (**(code **)(*hwDescriptionObj + 0xe8))(hwDescriptionObj,local_74,auStack_78,0x10203);
                      if (iVar15 != 0) {
                        ((int (*)())FUN_000f04d4)(pass,consumer);
                      }
                    }
                  }
                }
              }
            }
            else {
              lastSourceIndex = consumer[0x21];
              if (0 < lastSourceIndex) {
                sourceIndex = 1;
                bVar1 = true;
                do {
                  operandVReg = (int *)IRInst__getOperandSource(consumer,sourceIndex);
                  iVar15 = (**(code **)(*operandVReg + 0x7c))();
                  if ((iVar15 != 0) ||
                     (iVar15 = ((int (*)())IRInst__isForwardable)(operandVReg,local_84,*(undefined4 *)(pass + 8)),
                     iVar15 == 0)) {
                    bVar1 = false;
                  }
                  lastSourceIndex = consumer[0x21];
                  sourceIndex = sourceIndex + 1;
                } while (sourceIndex <= lastSourceIndex);
                if (!bVar1) goto code_r0x000f0d0c;
              }
              sourceIndex = 1;
              if (0 < lastSourceIndex) {
                do {
                  pushedSelectWord = local_88;
                  maskStackCount = vectorAlloc[2];
                  if (maskStackCount < *maskStack) {
                    _memset(maskStackCount * 4 + vectorAlloc[3],0,4);
                    vectorAlloc[2] = maskStackCount + 1;
                    maskStackSlot = (int *)(maskStackCount * 4 + vectorAlloc[3]);
                  }
                  else {
                    maskStackSlot = (int *)Vector__elementRefGrow(maskStack,maskStackCount);
                  }
                  *maskStackSlot = pushedSelectWord;
                  pushedSource = IRInst__getOperandSource(consumer,sourceIndex);
                  consumerStackCount = allocation[2];
                  if (consumerStackCount < *consumerStack) {
                    _memset(consumerStackCount * 4 + allocation[3],0,4);
                    allocation[2] = consumerStackCount + 1;
                    consumerStackSlot = (undefined4 *)(consumerStackCount * 4 + allocation[3]);
                  }
                  else {
                    consumerStackSlot = (undefined4 *)Vector__elementRefGrow(consumerStack,consumerStackCount);
                  }
                  *consumerStackSlot = pushedSource;
                  sourceIndex = sourceIndex + 1;
                } while (sourceIndex <= consumer[0x21]);
              }
code_r0x000f1140:
              (**(code **)(*consumer + 0xc))(consumer,0,*(undefined4 *)(pass + 8));
            }
            goto code_r0x000f1384;
          }
code_r0x000f0d0c:
          ((int (*)())FUN_000ecd28)(pass,consumer,afterInst,destRegisterOffset,destRegister,local_88);
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
  undefined4 chainSelectWord;
  uint secondPassFlag;
  int foldedCount;
  int moveSourceSelect;
  int isStoreLike;
  int sourceBlock;
  int composedSelectWord;
  int placementInstRef;
  undefined4 hwRegisterFile;
  undefined4 destSelectWord;
  undefined4 placementInst;
  int allocPlacementEnabled;
  int operandRecord4;
  int operandRecord2;
  int operandRecord;
  int operandRecord3;
  int *operandVReg2;
  bool bVar1;
  code *UNRECOVERED_JUMPTABLE;
  uint instFlags;
  undefined4 *allocation;
  int block;
  int *moveSource;
  int hwFoldRejects;
  int *operandVReg;
  int *newMov;
  int iVar9;
  int *newMov2;
  undefined4 compiler;
  int iVar12;
  undefined4 destSelectWord2;
  undefined4 arenaA;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38 [3];
  
  arenaA = *(undefined4 *)(*(int *)(program + 8) + 0x374);
  allocation = (undefined4 *)Arena__alloc(arenaA,0x168);
  *allocation = arenaA;
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
        compiler = *(undefined4 *)(program + 8);
        UNRECOVERED_JUMPTABLE = *(code **)(*inst2 + 0x94);
        placementInst = *(undefined4 *)(program + 0x340);
        inst = inst2;
        goto LAB_000f1940;
      }
    }
  }
  else if (((*(uint *)(program + 0x30) & 1) != 0) && (inst != (int *)0x0)) {
    block = inst[0x56];
    if (inst2 == (int *)0x0) {
      moveSource = (int *)IRInst__getOperandSource(inst,1);
      operandRecord2 = IRInst__getOperandRecord(inst,1);
      moveSourceSelect = *(int *)(operandRecord2 + 0x10);
      hwFoldRejects = (**(code **)(**(int **)(*(int *)(program + 8) + 0x30c) + 0xb8))();
      if (((hwFoldRejects == 0) && (hwFoldRejects = (**(code **)(*moveSource + 0x7c))(moveSource), hwFoldRejects == 0)) &&
         ((((hwFoldRejects = FUN_0011379c(*(undefined4 *)(program + 8),moveSource), hwFoldRejects != 0 &&
            ((hwFoldRejects = moveSource[0x58] - *(int *)(program + 0x478), hwFoldRejects < 0 || (hwFoldRejects < 2)))) &&
           (hwFoldRejects = (**(code **)(*moveSource + 0x28))(moveSource), hwFoldRejects == 0)) &&
          ((moveSource[0x21] != 0 && (moveSourceSelect == DAT_001aa804)))))) {
        operandRecord = IRInst__getOperandRecord(inst,0);
        destSelectWord = *(undefined4 *)(operandRecord + 0x10);
        ((int (*)())Program__removeInst)(program,inst);
        (**(code **)(*inst + 0xc))(inst,0,*(undefined4 *)(program + 8));
        sourceBlock = moveSource[0x56];
        IRInst__setHardwareRegisterAndAdd(moveSource,program,6,0);
        (**(code **)(*moveSource + 0x94))
                  (moveSource,*(undefined4 *)(program + 0x340),*(undefined4 *)(program + 8));
        operandRecord = IRInst__getOperandRecord(moveSource,0);
        SelectWord__markEqualLanes(&local_44,destSelectWord,*(undefined4 *)(operandRecord + 0x10));
        instFlags = moveSource[5];
        block = local_44;
        do {
          if ((instFlags & 0x200) == 0) {
code_r0x000e76c4:
            placementInstRef = *(int *)(program + 0x340);
            DList__insertAfter(placementInstRef,*(undefined4 *)(sourceBlock + 200));
            *(int *)(placementInstRef + 0x158) = sourceBlock;
            return;
          }
          operandVReg = (int *)IRInst__getOperandSource(moveSource,moveSource[0x21]);
          IRInst__setOperandSource(moveSource,moveSource[0x21],0,0,*(undefined4 *)(program + 8));
          iVar12 = *operandVReg;
          moveSource[0x21] = moveSource[0x21] + -1;
          moveSource[5] = moveSource[5] & 0xfffffdff;
          iVar12 = (**(code **)(iVar12 + 0x7c))(operandVReg);
          if ((((iVar12 != 0) ||
               (iVar12 = FUN_0011379c(*(undefined4 *)(program + 8),operandVReg), iVar12 == 0)) ||
              ((iVar12 = operandVReg[0x58] - *(int *)(program + 0x478), -1 < iVar12 && (1 < iVar12)))) ||
             (((sourceBlock != operandVReg[0x56] ||
               (iVar12 = (**(code **)(*operandVReg + 0x28))(operandVReg), iVar12 != 0)) || (operandVReg[0x21] == 0)
              ))) {
            newMov = (int *)IRMov__new_1084b8(0x31,*(undefined4 *)(program + 8));
            IRInst__setOperandSource(newMov,1,operandVReg,0,*(undefined4 *)(program + 8));
            (**(code **)(*newMov + 0x94))
                      (newMov,*(undefined4 *)(program + 0x340),*(undefined4 *)(program + 8));
            IRInst__setHardwareRegisterAndAdd(newMov,program,6,0);
            newMov[0x27] = block;
            Block__insertInstBefore(sourceBlock,moveSource,newMov);
            goto code_r0x000e76c4;
          }
          (**(code **)(*operandVReg + 0x94))
                    (operandVReg,*(undefined4 *)(program + 0x340),*(undefined4 *)(program + 8));
          IRInst__setHardwareRegisterAndAdd(operandVReg,program,6,0);
          operandRecord3 = IRInst__getOperandRecord(operandVReg,0);
          SelectWord__markEqualLanes(&local_40,block,*(undefined4 *)(operandRecord3 + 0x10));
          instFlags = operandVReg[5];
          moveSource = operandVReg;
          block = local_40;
        } while( true );
      }
      FUN_000e8424(block,*(undefined4 *)(program + 0x340));
      compiler = *(undefined4 *)(program + 8);
      UNRECOVERED_JUMPTABLE = *(code **)(*inst + 0x94);
      placementInst = *(undefined4 *)(program + 0x340);
    }
    else {
      *(undefined4 *)(*(int *)(program + 0x340) + 300) = 1;
      moveSource = (int *)IRInst__getOperandSource(inst,1);
      operandVReg = (int *)IRInst__getOperandSource(inst2,1);
      if ((((moveSource[0x56] == operandVReg[0x56]) &&
           (isStoreLike = (**(code **)(*moveSource + 0x7c))(moveSource), isStoreLike == 0)) &&
          (isStoreLike = (**(code **)(*operandVReg + 0x7c))(operandVReg), isStoreLike == 0)) &&
         ((moveSource[0x21] != 0 && (operandVReg[0x21] != 0)))) {
        secondPassFlag = (uint)(1 < *(int *)(program + 0x478));
        if (((((int)(moveSource[0x58] - secondPassFlag) < 0) || (moveSource[0x58] == secondPassFlag)) &&
            (((isStoreLike = operandVReg[0x58] - *(int *)(program + 0x478), isStoreLike < 0 || (isStoreLike < 2)) &&
             (isStoreLike = (**(code **)(*moveSource + 0x28))(moveSource), isStoreLike == 0)))) &&
           (isStoreLike = (**(code **)(*operandVReg + 0x28))(operandVReg), isStoreLike == 0)) {
          sourceBlock = moveSource[0x56];
          operandRecord = IRInst__getOperandRecord(inst,0);
          destSelectWord2 = *(undefined4 *)(operandRecord + 0x10);
          hwRegisterFile = 6;
          operandRecord = IRInst__getOperandRecord(inst2,0);
          chainSelectWord = *(undefined4 *)(operandRecord + 0x10);
          ((int (*)())Program__removeInst)(program,inst2);
          foldedCount = 0;
          ((int (*)())Program__removeInst)(program,inst);
          (**(code **)(*inst + 0xc))(inst,0,*(undefined4 *)(program + 8));
          (**(code **)(*inst2 + 0xc))(inst2,0,*(undefined4 *)(program + 8));
          Block__prependInst(sourceBlock,*(undefined4 *)(program + 0x340));
          operandRecord = IRInst__getOperandRecord(moveSource,0);
          SelectWord__markEqualLanes(&local_3c,destSelectWord2,*(undefined4 *)(operandRecord + 0x10));
          do {
            (**(code **)(*moveSource + 0x94))
                      (moveSource,*(undefined4 *)(program + 0x340),*(undefined4 *)(program + 8));
            IRInst__setHardwareRegisterAndAdd(moveSource,program,hwRegisterFile,0);
            instFlags = moveSource[5];
            composedSelectWord = local_3c;
            while ((instFlags & 0x200) != 0) {
              operandVReg2 = (int *)IRInst__getOperandSource(moveSource,moveSource[0x21]);
              iVar9 = (**(code **)(*operandVReg2 + 0x7c))();
              if ((((iVar9 != 0) ||
                   (iVar9 = FUN_0011379c(*(undefined4 *)(program + 8),operandVReg2), iVar9 == 0)) ||
                  ((iVar9 = operandVReg2[0x58] - *(int *)(program + 0x478), -1 < iVar9 && (1 < iVar9))))
                 || (((sourceBlock != operandVReg2[0x56] ||
                      (iVar9 = (**(code **)(*operandVReg2 + 0x28))(operandVReg2), iVar9 != 0)) ||
                     (operandVReg2[0x21] == 0)))) {
                newMov2 = (int *)IRMov__new_1084b8(0x31,*(undefined4 *)(program + 8));
                IRInst__setOperandSource(newMov2,1,operandVReg2,0,*(undefined4 *)(program + 8));
                IRInst__setHardwareRegisterAndAdd(newMov2,program,hwRegisterFile,0);
                (**(code **)(*newMov2 + 0x94))
                          (newMov2,*(undefined4 *)(program + 0x340),*(undefined4 *)(program + 8));
                newMov2[0x27] = composedSelectWord;
                Block__insertInstBefore(sourceBlock,moveSource,newMov2);
                break;
              }
              (**(code **)(*operandVReg2 + 0x94))
                        (operandVReg2,*(undefined4 *)(program + 0x340),*(undefined4 *)(program + 8));
              IRInst__setHardwareRegisterAndAdd(operandVReg2,program,hwRegisterFile,0);
              operandRecord4 = IRInst__getOperandRecord(operandVReg2,0);
              SelectWord__markEqualLanes(local_38,composedSelectWord,*(undefined4 *)(operandRecord4 + 0x10));
              composedSelectWord = local_38[0];
              moveSource = operandVReg2;
              instFlags = operandVReg2[5];
            }
            block = IRInst__getOperandRecord(operandVReg,0);
            hwRegisterFile = 7;
            SelectWord__markEqualLanes(&local_48,chainSelectWord,*(undefined4 *)(block + 0x10));
            bVar1 = foldedCount == 1;
            foldedCount = foldedCount + 1;
            local_3c = local_48;
            moveSource = operandVReg;
            if (bVar1) {
              return;
            }
          } while( true );
        }
      }
      FUN_000e8424(block,*(undefined4 *)(program + 0x340));
      (**(code **)(*inst + 0x94))
                (inst,*(undefined4 *)(program + 0x340),*(undefined4 *)(program + 8));
      compiler = *(undefined4 *)(program + 8);
      UNRECOVERED_JUMPTABLE = *(code **)(*inst2 + 0x94);
      placementInst = *(undefined4 *)(program + 0x340);
      inst = inst2;
    }
LAB_000f1940:
                    
                    
    (*UNRECOVERED_JUMPTABLE)(inst,placementInst,compiler);
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
  uint fixupIndexCountB;
  uint fixupInstCount;
  uint unusedMask;
  uint fixupIndexCount;
  uint walkIndexTopIndex;
  uint maskedUse;
  uint readMask;
  uint fixupIndexTopIndex;
  uint fixupInstTopIndex;
  uint walkIndexCount;
  uint walkInstCount;
  undefined4 *fixupIndexSlotB;
  undefined4 *fixupInstSlot;
  undefined4 *walkInstTop;
  undefined4 *fixupInstTop;
  undefined4 *walkIndexSlotB;
  int *fixupIndexSlot;
  int *walkIndexTop;
  int *walkIndexSlot;
  int *fixupIndexTop;
  int fixupIndexByteOffset;
  int fixupInstByteOffset;
  int walkIndexByteOffset;
  int walkInstByteOffset;
  bool hasNode;
  int sourceDef;
  int operandRecord;
  int *operandVReg;
  int loopIndex;
  bool walking;
  undefined4 *walkInstSlot;
  int *node;
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
  dword destRegister;
  dword *destRegisterOffset;
  int *fixupConsumer;
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
  destRegisterOffset = (dword *)inst[0x26];
  destRegister = inst[0x25];
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
  walkInstCount = vec4Count;
  if (vec4Count < vec4Capacity) {
    walkInstByteOffset = vec4Count * 4;
    a2 = ((unsigned char *)0x4);
    _memset(walkInstByteOffset + vec4Data,0,4);
    vec4Count = walkInstCount + 1;
    walkInstSlot = (undefined4 *)(walkInstByteOffset + vec4Data);
  }
  else {
    walkInstSlot = (undefined4 *)Vector__elementRefGrow(&vec4Capacity,vec4Count);
  }
  walkIndexCount = vecCount;
  *walkInstSlot = inst;
  if (vecCount < vecCapacity) {
    walkIndexByteOffset = vecCount * 4;
    a2 = ((unsigned char *)0x4);
    _memset(walkIndexByteOffset + vecData,0,4);
    vecCount = walkIndexCount + 1;
    walkIndexSlotB = (undefined4 *)(walkIndexByteOffset + vecData);
  }
  else {
    walkIndexSlotB = (undefined4 *)Vector__elementRefGrow(&vecCapacity,vecCount);
  }
  *walkIndexSlotB = 1;
  node = (int *)IRInst__getOperandSource(inst,1);
  walking = true;
  walkInstCount = vec4Count;
LAB_000f26b0:
  do {
    while( true ) {
      if (walkInstCount == 0) {
        operandRecord = IRInst__getOperandRecord(inst,0);
        WriteMask__fromSelectWord(&local_40,*(undefined4 *)(operandRecord + 0x10));
        while (vec2Count != 0) {
          fixupInstTopIndex = vec2Count - 1;
          fixupInstTop = (undefined4 *)0x0;
          if (fixupInstTopIndex < vec2Count) {
            fixupInstTop = (undefined4 *)(fixupInstTopIndex * 4 + vec2Data);
          }
          fixupConsumer = (int *)*fixupInstTop;
          Vector__removeAt(&vec2Capacity,fixupInstTopIndex);
          fixupIndexTop = (int *)0x0;
          fixupIndexTopIndex = vec3Count - 1;
          if (fixupIndexTopIndex < vec3Count) {
            fixupIndexTop = (int *)(fixupIndexTopIndex * 4 + vec3Data);
          }
          iVar4 = *fixupIndexTop;
          Vector__removeAt(&vec3Capacity,fixupIndexTopIndex);
          operandVReg = (int *)IRInst__getOperandSource(fixupConsumer,iVar4);
          if (((dword *)operandVReg[0x26] != destRegisterOffset) &&
             (iVar5 = (**(code **)(*operandVReg + 0x50))(operandVReg), iVar5 == 0)) {
            readMask = operandVReg[3];
            iVar5 = IRMov__new_1084b8(0x31,*(undefined4 *)(pass + 8));
            IRInst__setOperandSource(iVar5,1,operandVReg,0,*(undefined4 *)(pass + 8));
            IRInst__setHardwareRegisterAndAdd(iVar5,pass,destRegisterOffset,destRegister);
            SelectWord__selectWhereMasked(&local_3c,0,local_40 & readMask);
            *(undefined4 *)(iVar5 + 0x9c) = local_3c;
            IRInst__maskUnusedLanesOfOperand(iVar5,1,pass);
            iVar6 = IRInst__isProjectionOfOpcode2a(fixupConsumer);
            if (iVar6 == 0) {
              iVar6 = (**(code **)(*fixupConsumer + 0x7c))(fixupConsumer);
              if (iVar6 == 0) {
                IRInst__setOperandSource(fixupConsumer,iVar4,iVar5,0,*(undefined4 *)(pass + 8));
                Block__insertInstBefore(fixupConsumer[0x56],fixupConsumer,iVar5);
              }
              else {
                IRInst__setOperandSource(fixupConsumer,iVar4,iVar5,0,*(undefined4 *)(pass + 8));
                predecessor = Block__getPredecessor(fixupConsumer[0x56],iVar4 + -1);
                Block__appendInst(predecessor,iVar5);
              }
            }
            else {
              IRInst__setExtraOperandSource(fixupConsumer,iVar5,0,*(undefined4 *)(pass + 8));
              Block__insertInstAfter(operandVReg[0x56],operandVReg,iVar5);
            }
          }
        }
        sourceDef = IRInst__getOperandSource(inst,1);
        maskedUse = local_40 & *(uint *)(sourceDef + 0xc);
        SelectWord__selectWhereMasked(local_38,0,maskedUse);
        inst[0x27] = local_38[0];
        IRInst__maskUnusedLanesOfOperand(inst,1,pass);
        cStack_89 = (char)maskedUse;
        cStack_8a = (char)(maskedUse >> 8);
        cStack_8b = (char)(maskedUse >> 0x10);
        local_8c = (char)(maskedUse >> 0x18);
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
      if (!walking) break;
      if (node == (int *)0x0) {
        node = (int *)0x0;
        walking = false;
      }
      else if (*(int *)(pass + 0x474) == node[0x54]) {
LAB_000f26a4:
        walking = false;
      }
      else {
        node[0x54] = *(int *)(pass + 0x474);
        operandRecord = IRInst__getOperandRecord(node,0);
        WriteMask__fromSelectWord(&local_48,*(undefined4 *)(operandRecord + 0x10));
        node[3] = local_48;
        iVar4 = (**(code **)(*node + 0x7c))
                          (node,a1,a2,argR6,argR7,in_r8,*(code **)(*node + 0x7c));
        walkInstCount = vec4Count;
        if (iVar4 == 0) {
          iVar4 = IRInst__opcodeIsInSet(node);
          walkInstCount = vec4Count;
          if (iVar4 == 0) {
            if ((node[5] & 0x200U) == 0) goto LAB_000f26a4;
            if (vec4Count < vec4Capacity) {
              walkInstByteOffset = vec4Count * 4;
              a2 = ((unsigned char *)0x4);
              _memset(walkInstByteOffset + vec4Data,0,4);
              vec4Count = walkInstCount + 1;
              walkInstSlot = (undefined4 *)(walkInstByteOffset + vec4Data);
            }
            else {
              walkInstSlot = (undefined4 *)Vector__elementRefGrow(&vec4Capacity,vec4Count);
            }
            walkIndexCount = vecCount;
            *walkInstSlot = node;
            iVar4 = node[0x21];
            if (vecCount < vecCapacity) {
              iVar5 = vecCount * 4;
              a2 = ((unsigned char *)0x4);
              _memset(iVar5 + vecData,0,4);
              vecCount = walkIndexCount + 1;
              walkIndexSlot = (int *)(iVar5 + vecData);
            }
            else {
              walkIndexSlot = (int *)Vector__elementRefGrow(&vecCapacity,vecCount);
            }
            *walkIndexSlot = iVar4;
            node = (int *)IRInst__getOperandSource(node,node[0x21]);
          }
          else {
            if (vec4Count < vec4Capacity) {
              walkInstByteOffset = vec4Count * 4;
              a2 = ((unsigned char *)0x4);
              _memset(walkInstByteOffset + vec4Data,0,4);
              vec4Count = walkInstCount + 1;
              walkInstSlot = (undefined4 *)(walkInstByteOffset + vec4Data);
            }
            else {
              walkInstSlot = (undefined4 *)Vector__elementRefGrow(&vec4Capacity,vec4Count);
            }
            walkIndexCount = vecCount;
            *walkInstSlot = node;
            if (vecCount < vecCapacity) {
              walkIndexByteOffset = vecCount * 4;
              a2 = ((unsigned char *)0x4);
              _memset(walkIndexByteOffset + vecData,0,4);
              vecCount = walkIndexCount + 1;
              walkIndexSlotB = (undefined4 *)(walkIndexByteOffset + vecData);
            }
            else {
              walkIndexSlotB = (undefined4 *)Vector__elementRefGrow(&vecCapacity,vecCount);
            }
            *walkIndexSlotB = 2;
            node = (int *)IRInst__getOperandSource(node,2);
          }
        }
        else {
          if (vec4Count < vec4Capacity) {
            walkInstByteOffset = vec4Count * 4;
            a2 = ((unsigned char *)0x4);
            _memset(walkInstByteOffset + vec4Data,0,4);
            vec4Count = walkInstCount + 1;
            walkInstSlot = (undefined4 *)(walkInstByteOffset + vec4Data);
          }
          else {
            walkInstSlot = (undefined4 *)Vector__elementRefGrow(&vec4Capacity,vec4Count);
          }
          walkIndexCount = vecCount;
          *walkInstSlot = node;
          if (vecCount < vecCapacity) {
            walkIndexByteOffset = vecCount * 4;
            a2 = ((unsigned char *)0x4);
            _memset(walkIndexByteOffset + vecData,0,4);
            vecCount = walkIndexCount + 1;
            walkIndexSlotB = (undefined4 *)(walkIndexByteOffset + vecData);
          }
          else {
            walkIndexSlotB = (undefined4 *)Vector__elementRefGrow(&vecCapacity,vecCount);
          }
          *walkIndexSlotB = 1;
          node = (int *)IRInst__getOperandSource(node,1);
        }
LAB_000f2690:
        walking = true;
        walkInstCount = vec4Count;
      }
    }
    uVar9 = walkInstCount - 1;
    walkInstTop = (undefined4 *)0x0;
    if (uVar9 < walkInstCount) {
      walkInstTop = (undefined4 *)(uVar9 * 4 + vec4Data);
    }
    hasNode = node != (int *)0x0;
    node = (int *)*walkInstTop;
    if (hasNode) {
      walkIndexTop = (int *)0x0;
      walkIndexTopIndex = vecCount - 1;
      if (walkIndexTopIndex < vecCount) {
        walkIndexTop = (int *)(walkIndexTopIndex * 4 + vecData);
      }
      if (*walkIndexTop != node[0x21]) {
        walkIndexTop = (int *)0x0;
        if (walkIndexTopIndex < vecCount) {
          walkIndexTop = (int *)(walkIndexTopIndex * 4 + vecData);
        }
        iVar4 = *walkIndexTop;
        Vector__removeAt(&vecCapacity,walkIndexTopIndex);
        walkIndexCount = vecCount;
        if (vecCount < vecCapacity) {
          iVar5 = vecCount * 4;
          a2 = ((unsigned char *)0x4);
          _memset(iVar5 + vecData,0,4);
          vecCount = walkIndexCount + 1;
          walkIndexSlot = (int *)(iVar5 + vecData);
        }
        else {
          walkIndexSlot = (int *)Vector__elementRefGrow(&vecCapacity,vecCount);
        }
        *walkIndexSlot = iVar4 + 1;
        node = (int *)IRInst__getOperandSource(node,iVar4 + 1);
        goto LAB_000f2690;
      }
    }
    Vector__removeAt(&vec4Capacity,uVar9);
    Vector__removeAt(&vecCapacity,vecCount - 1);
    operandRecord = IRInst__getOperandRecord(node,0);
    WriteMask__fromSelectWord(&local_44,*(undefined4 *)(operandRecord + 0x10));
    uVar8 = local_44;
    iVar4 = IRInst__isProjectionOfOpcode2a(node);
    if (iVar4 == 0) {
      iVar4 = (**(code **)(*node + 0x7c))(node);
      if (iVar4 == 0) {
        iVar4 = IRInst__opcodeIsInSet(node);
        if (iVar4 != 0) {
          sourceDef = IRInst__getOperandSource(node,2);
          iVar5 = IRInst__getOperandSource(node,3);
          unusedMask = ~*(uint *)(sourceDef + 0xc);
          if ((uVar8 & (unusedMask << 0x18 | (unusedMask & 0xff00) << 8 | unusedMask >> 8 & 0xff00 | unusedMask >> 0x18)
              ) == 0) {
            unusedMask = ~*(uint *)(iVar5 + 0xc);
            if ((uVar8 & (unusedMask << 0x18 | (unusedMask & 0xff00) << 8 | unusedMask >> 8 & 0xff00 |
                         unusedMask >> 0x18)) == 0) goto LAB_000f25ac;
            IRInst__reduceTernaryToBinary(node,3,*(undefined4 *)(pass + 8));
          }
          else {
            IRInst__reduceTernaryToBinary(node,2,*(undefined4 *)(pass + 8));
          }
          a2 = destRegisterOffset;
          argR6 = destRegister;
          IRInst__setHardwareRegisterAndAdd(node,pass,destRegisterOffset,destRegister);
          fixupInstCount = vec2Count;
          if (vec2Count < vec2Capacity) {
            fixupInstByteOffset = vec2Count * 4;
            a2 = ((unsigned char *)0x4);
            _memset(fixupInstByteOffset + vec2Data,0,4);
            vec2Count = fixupInstCount + 1;
            fixupInstSlot = (undefined4 *)(fixupInstByteOffset + vec2Data);
          }
          else {
            fixupInstSlot = (undefined4 *)Vector__elementRefGrow(&vec2Capacity,vec2Count);
          }
          fixupIndexCountB = vec3Count;
          *fixupInstSlot = node;
          if (vec3Count < vec3Capacity) {
            fixupIndexByteOffset = vec3Count * 4;
            a2 = ((unsigned char *)0x4);
            _memset(fixupIndexByteOffset + vec3Data,0,4);
            vec3Count = fixupIndexCountB + 1;
            fixupIndexSlotB = (undefined4 *)(fixupIndexByteOffset + vec3Data);
          }
          else {
            fixupIndexSlotB = (undefined4 *)Vector__elementRefGrow(&vec3Capacity,vec3Count);
          }
          *fixupIndexSlotB = 3;
          node[3] = 0;
        }
LAB_000f25ac:
        if ((node[5] & 0x200U) != 0) {
          sourceDef = IRInst__getOperandSource(node,node[0x21]);
          node[3] = uVar8 | *(uint *)(sourceDef + 0xc);
          if ((dword *)*(undefined1 **)(sourceDef + 0x98) == destRegisterOffset) {
            a2 = (dword *)0x0;
            argR6 = 0;
            argR7 = *(undefined4 *)(pass + 8);
            IRInst__setOperandSource(node,node[0x21],0,0,argR7);
            node[0x21] = node[0x21] + -1;
            node[5] = node[5] & 0xfffffdff;
          }
        }
      }
      else {
        loopIndex = 1;
        if (0 < node[0x21]) {
          do {
            iVar5 = IRInst__getOperandSource(node,loopIndex);
            unusedMask = ~*(uint *)(iVar5 + 0xc);
            if ((uVar8 & (unusedMask << 0x18 | (unusedMask & 0xff00) << 8 | unusedMask >> 8 & 0xff00 |
                         unusedMask >> 0x18)) != 0) {
              a2 = destRegisterOffset;
              argR6 = destRegister;
              IRInst__setHardwareRegisterAndAdd(node,pass,destRegisterOffset,destRegister);
              node[3] = 0;
              if (0 < node[0x21]) {
                loopIndex = 1;
                do {
                  iVar5 = IRInst__getOperandSource(node,loopIndex);
                  fixupInstCount = vec2Count;
                  if ((uVar8 & *(uint *)(iVar5 + 0xc)) != 0) {
                    if (vec2Count < vec2Capacity) {
                      iVar5 = vec2Count * 4;
                      a2 = ((unsigned char *)0x4);
                      _memset(iVar5 + vec2Data,0,4);
                      vec2Count = fixupInstCount + 1;
                      fixupInstSlot = (undefined4 *)(iVar5 + vec2Data);
                    }
                    else {
                      fixupInstSlot = (undefined4 *)Vector__elementRefGrow(&vec2Capacity,vec2Count);
                    }
                    fixupIndexCountB = vec3Count;
                    *fixupInstSlot = node;
                    if (vec3Count < vec3Capacity) {
                      iVar5 = vec3Count * 4;
                      a2 = ((unsigned char *)0x4);
                      _memset(iVar5 + vec3Data,0,4);
                      vec3Count = fixupIndexCountB + 1;
                      fixupIndexSlot = (int *)(iVar5 + vec3Data);
                    }
                    else {
                      fixupIndexSlot = (int *)Vector__elementRefGrow(&vec3Capacity,vec3Count);
                    }
                    *fixupIndexSlot = loopIndex;
                  }
                  loopIndex = loopIndex + 1;
                } while (loopIndex <= node[0x21]);
              }
              break;
            }
            loopIndex = loopIndex + 1;
          } while (loopIndex <= node[0x21]);
        }
      }
LAB_000f260c:
      walking = false;
      walkInstCount = vec4Count;
      goto LAB_000f26b0;
    }
    a2 = destRegisterOffset;
    argR6 = destRegister;
    IRInst__setHardwareRegisterAndAdd(node,pass,destRegisterOffset,destRegister);
    sourceDef = IRInst__getOperandSource(node,node[0x21]);
    fixupInstCount = vec2Count;
    node[3] = 0;
    if ((uVar8 & *(uint *)(sourceDef + 0xc)) == 0) goto LAB_000f260c;
    if (vec2Count < vec2Capacity) {
      fixupInstByteOffset = vec2Count * 4;
      a2 = ((unsigned char *)0x4);
      _memset(fixupInstByteOffset + vec2Data,0,4);
      vec2Count = fixupInstCount + 1;
      fixupInstSlot = (undefined4 *)(fixupInstByteOffset + vec2Data);
    }
    else {
      fixupInstSlot = (undefined4 *)Vector__elementRefGrow(&vec2Capacity,vec2Count);
    }
    fixupIndexCount = vec3Count;
    *fixupInstSlot = node;
    iVar4 = node[0x21];
    if (vec3Count < vec3Capacity) {
      iVar5 = vec3Count * 4;
      a2 = ((unsigned char *)0x4);
      _memset(iVar5 + vec3Data,0,4);
      vec3Count = fixupIndexCount + 1;
      fixupIndexSlot = (int *)(iVar5 + vec3Data);
    }
    else {
      fixupIndexSlot = (int *)Vector__elementRefGrow(&vec3Capacity,vec3Count);
    }
    *fixupIndexSlot = iVar4;
    walking = false;
    walkInstCount = vec4Count;
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
  int loopCounter;
  
  (*(unsigned int *)((unsigned char *)ghidra_home + 0)) = param_1;
  loopCounter = 4;
  pcVar2 = (char *)&(*(unsigned int *)((unsigned char *)ghidra_home + 0));
  cVar3 = '\x04';
  while (((cVar1 = *pcVar2, cVar4 = cVar3, cVar1 == '\x04' || (cVar4 = cVar1, cVar3 == '\x04')) ||
         (cVar4 = cVar3, cVar1 == cVar3))) {
    pcVar2 = pcVar2 + 1;
    loopCounter = loopCounter + -1;
    cVar3 = cVar4;
    if (loopCounter == 0) {
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
  int loopCounter;
  int loopCounterB;
  
  (*(unsigned int *)((unsigned char *)ghidra_home + 0)) = param_1;
  ((int (*)())SelectWord__isSplat)(param_1);
  loopCounterB = 4;
  loopCounter = 0;
  pcVar1 = (char *)&(*(unsigned int *)((unsigned char *)ghidra_home + 0));
  do {
    if (*pcVar1 != '\x04') {
      return (uint)*(byte *)((int)&(*(unsigned int *)((unsigned char *)ghidra_home + 0)) + loopCounter);
    }
    loopCounter = loopCounter + 1;
    pcVar1 = pcVar1 + 1;
    loopCounterB = loopCounterB + -1;
  } while (loopCounterB != 0);
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
asm(".globl ContinueBlock__clone");
asm(".set ContinueBlock__clone, _ContinueBlock__clone");
asm(".globl FUN_000eca10");
asm(".set FUN_000eca10, _KhanVs__vslot17_isSimpleInst");
asm(".globl FUN_000ecad0");
asm(".set FUN_000ecad0, _KhanPs__vslot17_isSimpleInst");
asm(".globl FUN_000ed29c");
asm(".set FUN_000ed29c, _HwLimits__vslot43_prependDefaultMov");
