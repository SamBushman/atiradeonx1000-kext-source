#include "decls.h"

/* ExportAddress__ctor_1260f4 @ 0x1260f4 (88 bytes) */
int ExportAddress__ctor_1260f4(param_1, param_2, param_3, param_4, compiler)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 compiler;
{
  undefined *vtable;
  
  VRegInfo__ctor_12379c(param_1,param_2,param_3,param_4,compiler);
  vtable = PTR_DAT_001e90d0;
  param_1[4] = 0x20;
  param_1[9] = param_1[9] | 2;
  *param_1 = vtable + 8;
  return;
}

/* ExportAddress__ctor_12614c @ 0x12614c (88 bytes) */
int ExportAddress__ctor_12614c(param_1, param_2, param_3, param_4, compiler)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 compiler;
{
  undefined *vtable;
  
  VRegInfo__ctor_12379c(param_1,param_2,param_3,param_4,compiler);
  vtable = PTR_DAT_001e90d0;
  param_1[4] = 0x20;
  param_1[9] = param_1[9] | 2;
  *param_1 = vtable + 8;
  return;
}

/* ImmedConstBuffer__ctor_1261a4 @ 0x1261a4 (68 bytes) */
int ImmedConstBuffer__ctor_1261a4(this, param_2, param_3, param_4, compiler)
  undefined4 *this;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 compiler;
{
  VRegInfo__ctor_12379c(this,param_2,param_3,param_4,compiler);
  *this = &PTR_FUN_001ea8d0;
  return;
}

/* ImmedConstBuffer__ctor_1261e8 @ 0x1261e8 (68 bytes) */
int ImmedConstBuffer__ctor_1261e8(this, param_2, param_3, param_4, compiler)
  undefined4 *this;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 compiler;
{
  VRegInfo__ctor_12379c(this,param_2,param_3,param_4,compiler);
  *this = &PTR_FUN_001ea8d0;
  return;
}

/* ExportSlot__ctor_12622c @ 0x12622c (256 bytes) */
int ExportSlot__ctor_12622c(this, param_2, param_3, param_4, compiler)
  undefined4 *this;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  int compiler;
{
  undefined4 arena;
  undefined4 *allocation;
  int operandRecord;
  undefined4 *puVar3;
  undefined4 uVar4;
  
  VRegInfo__ctor_12379c(this,param_2,param_3,param_4,compiler);
  this[4] = param_2;
  this[9] = this[9] | 2;
  *this = &PTR_FUN_001ea7f0;
  if ((*(uint *)(*(int *)(compiler + COMP_currentProgram) + 0x30) & 0x4000) != 0) {
    arena = *(undefined4 *)(compiler + COMP_arenaA);
    allocation = (undefined4 *)Arena__alloc(arena,0x168);
    puVar3 = allocation + 1;
    *allocation = arena;
    IRExport__ctor_108918(puVar3,compiler);
    allocation[0x28] = DAT_001afef0;
    IRInst__setOperandRef(puVar3,0,this);
    FUN_0012306c(this,puVar3);
    IRInst__setOperandRef(puVar3,1,this);
    uVar4 = DAT_001afeec;
    operandRecord = IRInst__getOperandRecord(puVar3,1);
    *(undefined4 *)(operandRecord + 0x10) = uVar4;
    VReg__addUse(this,1,puVar3);
    Program__addInst(*(undefined4 *)(compiler + COMP_currentProgram),puVar3);
    Block__appendInst(*(undefined4 *)(*(int *)(compiler + COMP_currentProgram) + 0x3a8),puVar3);
  }
  return;
}

/* ExportSlot__ctor_126378 @ 0x126378 (256 bytes) */
int ExportSlot__ctor_126378(this, param_2, param_3, param_4, compiler)
  undefined4 *this;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  int compiler;
{
  undefined4 arena;
  undefined4 *allocation;
  int operandRecord;
  undefined4 *puVar3;
  undefined4 uVar4;
  
  VRegInfo__ctor_12379c(this,param_2,param_3,param_4,compiler);
  this[4] = param_2;
  this[9] = this[9] | 2;
  *this = &PTR_FUN_001ea7f0;
  if ((*(uint *)(*(int *)(compiler + COMP_currentProgram) + 0x30) & 0x4000) != 0) {
    arena = *(undefined4 *)(compiler + COMP_arenaA);
    allocation = (undefined4 *)Arena__alloc(arena,0x168);
    puVar3 = allocation + 1;
    *allocation = arena;
    IRExport__ctor_108918(puVar3,compiler);
    allocation[0x28] = DAT_001afef0;
    IRInst__setOperandRef(puVar3,0,this);
    FUN_0012306c(this,puVar3);
    IRInst__setOperandRef(puVar3,1,this);
    uVar4 = DAT_001afeec;
    operandRecord = IRInst__getOperandRecord(puVar3,1);
    *(undefined4 *)(operandRecord + 0x10) = uVar4;
    VReg__addUse(this,1,puVar3);
    Program__addInst(*(undefined4 *)(compiler + COMP_currentProgram),puVar3);
    Block__appendInst(*(undefined4 *)(*(int *)(compiler + COMP_currentProgram) + 0x3a8),puVar3);
  }
  return;
}

/* LoopIndexedConstSet__ctor_1264c4 @ 0x1264c4 (116 bytes) */
int LoopIndexedConstSet__ctor_1264c4(this, param_2, param_3, param_4, compiler)
  undefined4 *this;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  int compiler;
{
  undefined *vtable;
  
  VRegInfo__ctor_12379c(this,param_2,param_3,param_4,compiler);
  vtable = PTR_DAT_001e90ec;
  this[0xc] = 0;
  *this = vtable + 8;
  *this = PTR_DAT_001e90e4 + 8;
  this[4] = *(undefined4 *)(compiler + 0x33c);
  *(int *)(compiler + 0x33c) = *(int *)(compiler + 0x33c) + 1;
  return;
}

/* LoopIndexedConstSet__ctor_126538 @ 0x126538 (116 bytes) */
int LoopIndexedConstSet__ctor_126538(this, param_2, param_3, param_4, compiler)
  undefined4 *this;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  int compiler;
{
  undefined *vtable;
  
  VRegInfo__ctor_12379c(this,param_2,param_3,param_4,compiler);
  vtable = PTR_DAT_001e90ec;
  this[0xc] = 0;
  *this = vtable + 8;
  *this = PTR_DAT_001e90e4 + 8;
  this[4] = *(undefined4 *)(compiler + 0x33c);
  *(int *)(compiler + 0x33c) = *(int *)(compiler + 0x33c) + 1;
  return;
}

/* LoopIndexedInputSet__ctor_1265ac @ 0x1265ac (116 bytes) */
int LoopIndexedInputSet__ctor_1265ac(this, param_2, param_3, param_4, compiler)
  undefined4 *this;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  int compiler;
{
  undefined *vtable;
  
  VRegInfo__ctor_12379c(this,param_2,param_3,param_4,compiler);
  vtable = PTR_DAT_001e90ec;
  this[0xc] = 0;
  *this = vtable + 8;
  *this = PTR_DAT_001e90d4 + 8;
  this[4] = *(undefined4 *)(compiler + 0x340);
  *(int *)(compiler + 0x340) = *(int *)(compiler + 0x340) + 1;
  return;
}

/* LoopIndexedInputSet__ctor_126620 @ 0x126620 (116 bytes) */
int LoopIndexedInputSet__ctor_126620(this, param_2, param_3, param_4, compiler)
  undefined4 *this;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  int compiler;
{
  undefined *vtable;
  
  VRegInfo__ctor_12379c(this,param_2,param_3,param_4,compiler);
  vtable = PTR_DAT_001e90ec;
  this[0xc] = 0;
  *this = vtable + 8;
  *this = PTR_DAT_001e90d4 + 8;
  this[4] = *(undefined4 *)(compiler + 0x340);
  *(int *)(compiler + 0x340) = *(int *)(compiler + 0x340) + 1;
  return;
}

/* LoopIndexedOutputSet__ctor_126694 @ 0x126694 (116 bytes) */
int LoopIndexedOutputSet__ctor_126694(this, param_2, param_3, param_4, compiler)
  undefined4 *this;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  int compiler;
{
  undefined *vtable;
  
  VRegInfo__ctor_12379c(this,param_2,param_3,param_4,compiler);
  vtable = PTR_DAT_001e90ec;
  this[0xc] = 0;
  *this = vtable + 8;
  *this = PTR_DAT_001e90dc + 8;
  this[4] = *(undefined4 *)(compiler + 0x344);
  *(int *)(compiler + 0x344) = *(int *)(compiler + 0x344) + 1;
  return;
}

/* RegKind__flagBit7 @ 0x126708 (44 bytes) */
int RegKind__flagBit7(param_1)
  int param_1;
{
  return *(uint *)(&DAT_001ea904 + param_1 * 0x10) >> 7 & 1;
}

/* RegKind__flagBit8 @ 0x126734 (44 bytes) */
int RegKind__flagBit8(param_1)
  int param_1;
{
  return *(uint *)(&DAT_001ea904 + param_1 * 0x10) >> 8 & 1;
}

/* RegKind__flagBit0 @ 0x126760 (44 bytes) */
int RegKind__flagBit0(kind)
  int kind;
{
  return *(uint *)(&DAT_001ea904 + kind * 0x10) & 1;
}

/* RegKind__flagBit6 @ 0x12678c (44 bytes) */
int RegKind__flagBit6(param_1)
  int param_1;
{
  return *(uint *)(&DAT_001ea904 + param_1 * 0x10) >> 6 & 1;
}

/* FUN_001267b8 @ 0x1267b8 (52 bytes) */
int FUN_001267b8(param_1)
  int param_1;
{
  return -(uint)(*(uint *)(&DAT_001ea904 + param_1 * 0x10) & 0x11) >> 0x1f;
}

/* ImmedConstBuffer__vslot283 @ 0x1267ec (84 bytes) */
int ImmedConstBuffer__vslot283(this, param_2, param_3, compiler)
  undefined4 this;
  undefined4 param_2;
  undefined4 param_3;
  int compiler;
{
  undefined4 *allocation;
  undefined4 arena;
  
  arena = *(undefined4 *)(compiler + COMP_arenaA);
  allocation = (undefined4 *)Arena__alloc(arena,0x34);
  *allocation = arena;
  ((int (*)())ImmedConstBuffer__ctor_1261e8)(allocation + 1,this,param_2,param_3,compiler);
  return allocation + 1;
}

/* RegKind__flagBit1 @ 0x126878 (44 bytes) */
int RegKind__flagBit1(param_1)
  int param_1;
{
  return *(uint *)(&DAT_001ea904 + param_1 * 0x10) >> 1 & 1;
}

/* RegKind__flagBit9 @ 0x1268a4 (44 bytes) */
int RegKind__flagBit9(param_1)
  int param_1;
{
  return *(uint *)(&DAT_001ea904 + param_1 * 0x10) >> 9 & 1;
}

/* RegKind__byte4 @ 0x1268d0 (40 bytes) */
int RegKind__byte4(param_1)
  int param_1;
{
  return (DAT_001ea908)[param_1 * 0x10];
}

/* ImmedConstBuffer__vslot235 @ 0x1268f8 (84 bytes) */
int ImmedConstBuffer__vslot235(this, param_2, param_3, compiler)
  undefined4 this;
  undefined4 param_2;
  undefined4 param_3;
  int compiler;
{
  undefined4 *allocation;
  undefined4 arena;
  
  arena = *(undefined4 *)(compiler + COMP_arenaA);
  allocation = (undefined4 *)Arena__alloc(arena,0x34);
  *allocation = arena;
  VertexRegister__ctor_1248ec(allocation + 1,this,param_2,param_3,compiler);
  return allocation + 1;
}

/* ImmedConstBuffer__vslot15 @ 0x126984 (84 bytes) */
int ImmedConstBuffer__vslot15(this, param_2, param_3, compiler)
  undefined4 this;
  undefined4 param_2;
  undefined4 param_3;
  int compiler;
{
  undefined4 *allocation;
  undefined4 arena;
  
  arena = *(undefined4 *)(compiler + COMP_arenaA);
  allocation = (undefined4 *)Arena__alloc(arena,0x38);
  *allocation = arena;
  TempValue__ctor_124e04(allocation + 1,this,param_2,param_3,compiler);
  return allocation + 1;
}

/* ImmedConstBuffer__vslot23 @ 0x126a10 (84 bytes) */
int ImmedConstBuffer__vslot23(this, param_2, param_3, compiler)
  undefined4 this;
  undefined4 param_2;
  undefined4 param_3;
  int compiler;
{
  undefined4 *allocation;
  undefined4 arena;
  
  arena = *(undefined4 *)(compiler + COMP_arenaA);
  allocation = (undefined4 *)Arena__alloc(arena,0x34);
  *allocation = arena;
  FixedValue__ctor_124724(allocation + 1,this,param_2,param_3,compiler);
  return allocation + 1;
}

/* ImmedConstBuffer__vslot83 @ 0x126a9c (84 bytes) */
int ImmedConstBuffer__vslot83(this, param_2, param_3, compiler)
  undefined4 this;
  undefined4 param_2;
  undefined4 param_3;
  int compiler;
{
  undefined4 *allocation;
  undefined4 arena;
  
  arena = *(undefined4 *)(compiler + COMP_arenaA);
  allocation = (undefined4 *)Arena__alloc(arena,0x44);
  *allocation = arena;
  Interpolator__ctor_1257b0(allocation + 1,this,param_2,param_3,compiler);
  return allocation + 1;
}

/* ImmedConstBuffer__vslot67 @ 0x126b28 (84 bytes) */
int ImmedConstBuffer__vslot67(this, param_2, param_3, compiler)
  undefined4 this;
  undefined4 param_2;
  undefined4 param_3;
  int compiler;
{
  undefined4 *allocation;
  undefined4 arena;
  
  arena = *(undefined4 *)(compiler + COMP_arenaA);
  allocation = (undefined4 *)Arena__alloc(arena,0x38);
  *allocation = arena;
  StandardIndex__ctor_124b24(allocation + 1,this,param_2,param_3,compiler);
  return allocation + 1;
}

/* ImmedConstBuffer__vslot71 @ 0x126bb4 (84 bytes) */
int ImmedConstBuffer__vslot71(this, param_2, param_3, compiler)
  undefined4 this;
  undefined4 param_2;
  undefined4 param_3;
  int compiler;
{
  undefined4 *allocation;
  undefined4 arena;
  
  arena = *(undefined4 *)(compiler + COMP_arenaA);
  allocation = (undefined4 *)Arena__alloc(arena,0x38);
  *allocation = arena;
  PrimitiveIndex__ctor_125db8(allocation + 1,this,param_2,param_3,compiler);
  return allocation + 1;
}

/* ImmedConstBuffer__vslot35 @ 0x126c40 (84 bytes) */
int ImmedConstBuffer__vslot35(this, param_2, param_3, compiler)
  undefined4 this;
  undefined4 param_2;
  undefined4 param_3;
  int compiler;
{
  undefined4 *allocation;
  undefined4 arena;
  
  arena = *(undefined4 *)(compiler + COMP_arenaA);
  allocation = (undefined4 *)Arena__alloc(arena,0x34);
  *allocation = arena;
  Resource__ctor_125d60(allocation + 1,this,param_2,param_3,compiler);
  return allocation + 1;
}

/* ImmedConstBuffer__vslot167 @ 0x126ccc (84 bytes) */
int ImmedConstBuffer__vslot167(this, param_2, param_3, compiler)
  undefined4 this;
  undefined4 param_2;
  undefined4 param_3;
  int compiler;
{
  undefined4 *allocation;
  undefined4 arena;
  
  arena = *(undefined4 *)(compiler + COMP_arenaA);
  allocation = (undefined4 *)Arena__alloc(arena,0x38);
  *allocation = arena;
  AddrIndexedSet__ctor_125f94(allocation + 1,this,param_2,param_3,compiler);
  return allocation + 1;
}

/* ImmedConstBuffer__vslot171 @ 0x126d58 (84 bytes) */
int ImmedConstBuffer__vslot171(this, param_2, param_3, compiler)
  undefined4 this;
  undefined4 param_2;
  undefined4 param_3;
  int compiler;
{
  undefined4 *allocation;
  undefined4 arena;
  
  arena = *(undefined4 *)(compiler + COMP_arenaA);
  allocation = (undefined4 *)Arena__alloc(arena,0x34);
  *allocation = arena;
  LoopRegister__ctor_126034(allocation + 1,this,param_2,param_3,compiler);
  return allocation + 1;
}

/* LoopIndexedSet__ctor_126de4 @ 0x126de4 (92 bytes) */
int LoopIndexedSet__ctor_126de4(param_1, param_2, param_3, compiler)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  int compiler;
{
  undefined *vtable;
  undefined4 *allocation;
  undefined4 arena;
  undefined4 *puVar4;
  
  arena = *(undefined4 *)(compiler + COMP_arenaA);
  allocation = (undefined4 *)Arena__alloc(arena,0x38);
  puVar4 = allocation + 1;
  *allocation = arena;
  VRegInfo__ctor_12379c(puVar4,param_1,param_2,param_3,compiler);
  vtable = PTR_DAT_001e90ec;
  allocation[0xd] = 0;
  *puVar4 = vtable + 8;
  return puVar4;
}

/* ImmedConstBuffer__vslot183 @ 0x126e90 (84 bytes) */
int ImmedConstBuffer__vslot183(this, param_2, param_3, compiler)
  undefined4 this;
  undefined4 param_2;
  undefined4 param_3;
  int compiler;
{
  undefined4 *allocation;
  undefined4 arena;
  
  arena = *(undefined4 *)(compiler + COMP_arenaA);
  allocation = (undefined4 *)Arena__alloc(arena,0x38);
  *allocation = arena;
  LoopIndexedOutputSet__ctor_126080(allocation + 1,this,param_2,param_3,compiler);
  return allocation + 1;
}

/* ImmedConstBuffer__vslot179 @ 0x126f1c (84 bytes) */
int ImmedConstBuffer__vslot179(this, param_2, param_3, compiler)
  undefined4 this;
  undefined4 param_2;
  undefined4 param_3;
  int compiler;
{
  undefined4 *allocation;
  undefined4 arena;
  
  arena = *(undefined4 *)(compiler + COMP_arenaA);
  allocation = (undefined4 *)Arena__alloc(arena,0x38);
  *allocation = arena;
  ((int (*)())LoopIndexedInputSet__ctor_126620)(allocation + 1,this,param_2,param_3,compiler);
  return allocation + 1;
}

/* ImmedConstBuffer__vslot175 @ 0x126fa8 (84 bytes) */
int ImmedConstBuffer__vslot175(this, param_2, param_3, compiler)
  undefined4 this;
  undefined4 param_2;
  undefined4 param_3;
  int compiler;
{
  undefined4 *allocation;
  undefined4 arena;
  
  arena = *(undefined4 *)(compiler + COMP_arenaA);
  allocation = (undefined4 *)Arena__alloc(arena,0x38);
  *allocation = arena;
  ((int (*)())LoopIndexedConstSet__ctor_126538)(allocation + 1,this,param_2,param_3,compiler);
  return allocation + 1;
}

/* ImmedConstBuffer__vslot187 @ 0x127034 (84 bytes) */
int ImmedConstBuffer__vslot187(this, param_2, param_3, compiler)
  undefined4 this;
  undefined4 param_2;
  undefined4 param_3;
  int compiler;
{
  undefined4 *allocation;
  undefined4 arena;
  
  arena = *(undefined4 *)(compiler + COMP_arenaA);
  allocation = (undefined4 *)Arena__alloc(arena,0x34);
  *allocation = arena;
  ((int (*)())ExportAddress__ctor_12614c)(allocation + 1,this,param_2,param_3,compiler);
  return allocation + 1;
}

/* ImmedConstBuffer__vslot191 @ 0x1270c0 (84 bytes) */
int ImmedConstBuffer__vslot191(this, param_2, param_3, compiler)
  undefined4 this;
  undefined4 param_2;
  undefined4 param_3;
  int compiler;
{
  undefined4 *allocation;
  undefined4 arena;
  
  arena = *(undefined4 *)(compiler + COMP_arenaA);
  allocation = (undefined4 *)Arena__alloc(arena,0x34);
  *allocation = arena;
  ((int (*)())ExportSlot__ctor_126378)(allocation + 1,this,param_2,param_3,compiler);
  return allocation + 1;
}

/* ImmedConstBuffer__vslot79 @ 0x12714c (84 bytes) */
int ImmedConstBuffer__vslot79(this, param_2, param_3, compiler)
  undefined4 this;
  undefined4 param_2;
  undefined4 param_3;
  int compiler;
{
  undefined4 *allocation;
  undefined4 arena;
  
  arena = *(undefined4 *)(compiler + COMP_arenaA);
  allocation = (undefined4 *)Arena__alloc(arena,0x34);
  *allocation = arena;
  Physical__ctor_125c8c(allocation + 1,this,param_2,param_3,compiler);
  return allocation + 1;
}

/* ImmedConstBuffer__vslot39 @ 0x1271d8 (84 bytes) */
int ImmedConstBuffer__vslot39(this, param_2, param_3, compiler)
  undefined4 this;
  undefined4 param_2;
  undefined4 param_3;
  int compiler;
{
  undefined4 *allocation;
  undefined4 arena;
  
  arena = *(undefined4 *)(compiler + COMP_arenaA);
  allocation = (undefined4 *)Arena__alloc(arena,0x3c);
  *allocation = arena;
  ExportValue__ctor_1250dc(allocation + 1,this,param_2,param_3,compiler);
  return allocation + 1;
}

/* ConstKey__lanes1 @ 0x127264 (8 bytes) */
int ConstKey__lanes1(param_1)
  int param_1;
{
  return *(undefined4 *)(param_1 + 0x20);
}

/* ConstKey__lanes2 @ 0x12726c (16 bytes) */
int ConstKey__lanes2(param_1)
  int param_1;
{
  return *(int *)(param_1 + 0x20) + *(int *)(param_1 + 0x38);
}

/* ConstKey__lanes3 @ 0x12727c (24 bytes) */
int ConstKey__lanes3(param_1)
  int param_1;
{
  return *(int *)(param_1 + 0x20) + *(int *)(param_1 + 0x38) + *(int *)(param_1 + 0x50);
}

/* ConstKey__lanes4 @ 0x127294 (32 bytes) */
int ConstKey__lanes4(param_1)
  int param_1;
{
  return *(int *)(param_1 + 0x20) + *(int *)(param_1 + 0x38) + *(int *)(param_1 + 0x50) +
         *(int *)(param_1 + 0x68);
}

/* FUN_001272b4 @ 0x1272b4 (16 bytes) */
int FUN_001272b4(param_1)
  int param_1;
{
  return *(int *)(param_1 + 4) + *(int *)(param_1 + 8);
}

/* FUN_001272cc @ 0x1272cc (8 bytes) */
int FUN_001272cc(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  *param_1 = param_2;
  return;
}

/* FUN_001272d4 @ 0x1272d4 (80 bytes) */
int FUN_001272d4(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  int *param_3;
{
  if (*param_2 != 0x24) {
    return;
  }
  if (*param_3 == *(int *)(param_1 + 0x44)) {
    *param_2 = 6;
    *param_3 = 0;
    return;
  }
  if (*param_3 != *(int *)(param_1 + 0x48)) {
    return;
  }
  *param_2 = 7;
  *param_3 = 0;
  return;
}

/* FUN_00127324 @ 0x127324 (232 bytes) */
int FUN_00127324(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int param_2;
  int param_3;
  undefined4 *param_4;
  undefined4 *param_5;
{
  if (param_2 == 0x24) {
    if (*(int *)(param_1 + 0x4c) == param_3) {
      *param_4 = 0x3f;
      *param_5 = 0;
      return 1;
    }
    if (param_3 == *(int *)(param_1 + 0x54)) {
      *param_4 = 0x3f;
      *param_5 = 1;
      return 1;
    }
    if (param_3 == *(int *)(param_1 + 0x50)) {
      *param_4 = 0x40;
      *param_5 = 0;
      return 1;
    }
    if (param_3 == *(int *)(param_1 + 0x58)) {
      *param_4 = 0x40;
      *param_5 = 1;
      return 1;
    }
    if (param_3 == *(int *)(param_1 + 0x5c)) {
      *param_4 = 0x3e;
      *param_5 = 0;
      return 1;
    }
    if (param_3 == *(int *)(param_1 + 0x60)) {
      *param_4 = 0x41;
      *param_5 = 0;
      return 1;
    }
  }
  return 0;
}

/* FUN_0012740c @ 0x12740c (100 bytes) */
int FUN_0012740c(param_1)
  int param_1;
{
  /* issue #64 live-repro: same iterator-object split as FUN_0011eaa0 (part_037.c), fixed earlier
   * this session - auStack_38 is walked by FUN_00194938/FUN_00194a94 as param_1[0..4] (0x14 bytes)
   * but declared only 16 bytes; local_28, the missing 5th word, is what this loop reads back as its
   * own continuation value. Separated, FUN_00194938's real update never reached local_28, so the
   * loop never saw it become null - not just a hang: the same (unchanging) local_28 object got
   * re-passed to the vtable call on every spin instead of the real next node, repeatedly
   * re-processing/re-freeing one object - a plausible source of the unrelated heap corruption seen
   * elsewhere on this issue (FUN_00121000: an objects own vtable-like field changing under it
   * between two visits). Merged into one 0x14-byte buffer. */
  unsigned char auStack_38 [0x14];
#define local_28 (*(int **)(auStack_38 + 0x10))
  
  FUN_00194a94(auStack_38,*(undefined4 *)(param_1 + 4));
  while (local_28 != (int *)0x0) {
    (**(code **)(*local_28 + 4))(local_28);
    FUN_00194938(auStack_38);
  }
  return;
}

/* FUN_00127470 @ 0x127470 (196 bytes) */
int FUN_00127470(param_1)
  int param_1;
{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint *puVar4;
  uint loopIndex;
  
  ((int (*)())FUN_0012740c)(param_1);
  puVar4 = *(uint **)(param_1 + 4);
  if (puVar4 != (uint *)0x0) {
    uVar1 = *puVar4;
    if (uVar1 == 0) {
      uVar3 = puVar4[2];
    }
    else {
      uVar3 = puVar4[2];
      loopIndex = 0;
      do {
        iVar2 = *(int *)(loopIndex * 4 + uVar3);
        if (iVar2 != 0) {
          Arena__free(puVar4[5],iVar2);
          uVar1 = *puVar4;
          uVar3 = puVar4[2];
        }
        loopIndex = loopIndex + 1;
      } while (loopIndex < uVar1);
    }
    Arena__free(puVar4[5],uVar3);
    Arena__free(puVar4[-1],puVar4 + -1);
    return;
  }
  return;
}

/* FUN_00127534 @ 0x127534 (108 bytes) */
int FUN_00127534(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  unsigned int ghidra_home[8] = { param_1, param_2, param_3, param_4, 0, 0, 0, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  undefined4 callResult;
  
  (*(unsigned int *)((unsigned char *)ghidra_home + 4)) = param_2;
  (*(unsigned int *)((unsigned char *)ghidra_home + 8)) = param_3;
  ((int (*)())FUN_001272d4)(param_1,&(*(unsigned int *)((unsigned char *)ghidra_home + 4)),&(*(unsigned int *)((unsigned char *)ghidra_home + 8)));
  *(undefined4 *)(*(int *)(param_1 + 0x24) + 8) = (*(unsigned int *)((unsigned char *)ghidra_home + 8));
  *(undefined4 *)(*(int *)(param_1 + 0x24) + 4) = (*(unsigned int *)((unsigned char *)ghidra_home + 4));
  *(undefined4 *)(*(int *)(param_1 + 0x24) + 0xc) = param_4;
  callResult = HashTable__find(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 0x24));
  return callResult;
}

/* FUN_001275a0 @ 0x1275a0 (104 bytes) */
int FUN_001275a0(param_1, param_2, param_3, param_4)
  uint *param_1;
  undefined4 param_2;
  undefined4 param_3;
  uint param_4;
{
  unsigned int ghidra_home[8] = { param_1, param_2, param_3, param_4, 0, 0, 0, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  undefined4 callResult;
  
  (*(unsigned int *)((unsigned char *)ghidra_home + 4)) = param_2;
  (*(unsigned int *)((unsigned char *)ghidra_home + 8)) = param_3;
  ((int (*)())FUN_001272d4)(param_1,&(*(unsigned int *)((unsigned char *)ghidra_home + 4)),&(*(unsigned int *)((unsigned char *)ghidra_home + 8)));
  callResult = FUN_00122e90((*(unsigned int *)((unsigned char *)ghidra_home + 8)),(*(unsigned int *)((unsigned char *)ghidra_home + 4)),param_4,*param_1);
  HashTable__insert(param_1[1],callResult);
  return callResult;
}

/* FUN_00127608 @ 0x127608 (100 bytes) */
int FUN_00127608(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  int callResult;
  undefined4 callResult2;
  
  callResult = ((int (*)())FUN_00127534)(param_1,param_2,param_3,param_4);
  if (callResult == 0) {
    callResult2 = ((int (*)())FUN_001275a0)(param_1,param_2,param_3,param_4);
    return callResult2;
  }
  return callResult;
}

/* ConstKey__compare1 @ 0x12766c (52 bytes) */
int ConstKey__compare1(param_1, param_2)
  int param_1;
  int param_2;
{
  if (((*(byte *)(param_1 + 0x15c) & 1) == (*(byte *)(param_2 + 0x15c) & 1)) &&
     (*(int *)(param_1 + 0x20) == *(int *)(param_2 + 0x20))) {
    return 0;
  }
  return 0xffffffff;
}

/* ConstKey__compare2 @ 0x1276a0 (92 bytes) */
int ConstKey__compare2(param_1, param_2)
  int param_1;
  int param_2;
{
  if ((((((int)*(char *)(param_1 + 0x15c) & 1U) == ((int)*(char *)(param_2 + 0x15c) & 1U)) &&
       (*(int *)(param_1 + 0x20) == *(int *)(param_2 + 0x20))) &&
      (((uint)(int)*(char *)(param_1 + 0x15c) >> 1 & 1) ==
       ((uint)(int)*(char *)(param_2 + 0x15c) >> 1 & 1))) &&
     (*(int *)(param_1 + 0x38) == *(int *)(param_2 + 0x38))) {
    return 0;
  }
  return 0xffffffff;
}

/* ConstKey__compare3 @ 0x1276fc (124 bytes) */
int ConstKey__compare3(param_1, param_2)
  int param_1;
  int param_2;
{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (uint)*(char *)(param_1 + 0x15c);
  uVar1 = (uint)*(char *)(param_2 + 0x15c);
  if (((((uVar2 & 1) == (uVar1 & 1)) && (*(int *)(param_1 + 0x20) == *(int *)(param_2 + 0x20))) &&
      ((uVar2 >> 1 & 1) == (uVar1 >> 1 & 1))) &&
     (((*(int *)(param_1 + 0x38) == *(int *)(param_2 + 0x38) &&
       ((uVar2 >> 2 & 1) == (uVar1 >> 2 & 1))) &&
      (*(int *)(param_1 + 0x50) == *(int *)(param_2 + 0x50))))) {
    return 0;
  }
  return 0xffffffff;
}

/* ConstKey__compare4 @ 0x127778 (156 bytes) */
int ConstKey__compare4(param_1, param_2)
  int param_1;
  int param_2;
{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (uint)*(char *)(param_1 + 0x15c);
  uVar1 = (uint)*(char *)(param_2 + 0x15c);
  if ((((((uVar2 & 1) == (uVar1 & 1)) && (*(int *)(param_1 + 0x20) == *(int *)(param_2 + 0x20))) &&
       ((uVar2 >> 1 & 1) == (uVar1 >> 1 & 1))) &&
      ((*(int *)(param_1 + 0x38) == *(int *)(param_2 + 0x38) &&
       ((uVar2 >> 2 & 1) == (uVar1 >> 2 & 1))))) &&
     ((*(int *)(param_1 + 0x50) == *(int *)(param_2 + 0x50) &&
      (((uVar2 >> 3 & 1) == (uVar1 >> 3 & 1) &&
       (*(int *)(param_1 + 0x68) == *(int *)(param_2 + 0x68))))))) {
    return 0;
  }
  return 0xffffffff;
}

/* keyEqualsThreeWords @ 0x127814 (60 bytes) */
int keyEqualsThreeWords(param_1, param_2)
  int param_1;
  int param_2;
{
  if (((*(int *)(param_1 + 8) == *(int *)(param_2 + 8)) &&
      (*(int *)(param_1 + 4) == *(int *)(param_2 + 4))) &&
     (*(int *)(param_1 + 0xc) == *(int *)(param_2 + 0xc))) {
    return 0;
  }
  return 0xffffffff;
}

/* FUN_00127850 @ 0x127850 (128 bytes) */
int FUN_00127850(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  /* issue #64 live-repro: same iterator-object split as FUN_0011eaa0 (part_037.c), fixed earlier
   * this session - auStack_38 is walked by FUN_00194938/FUN_00194a94 as param_1[0..4] (0x14 bytes)
   * but declared only 16 bytes; local_28, the missing 5th word, is what this loop reads back as its
   * own continuation value. Separated, FUN_00194938's real update never reached local_28, so the
   * loop never saw it become null - not just a hang: the same (unchanging) local_28 object got
   * re-passed to the vtable call on every spin instead of the real next node, repeatedly
   * re-processing/re-freeing one object - a plausible source of the unrelated heap corruption seen
   * elsewhere on this issue (FUN_00121000: an objects own vtable-like field changing under it
   * between two visits). Merged into one 0x14-byte buffer. */
  unsigned char auStack_38 [0x14];
#define local_28 (*(int **)(auStack_38 + 0x10))
  
  FUN_00194a94(auStack_38,*(undefined4 *)(param_1 + 4));
  iVar2 = 0;
  while (local_28 != (int *)0x0) {
    iVar1 = (**(code **)(*local_28 + 0x18))(local_28);
    if (iVar1 != 0) {
      iVar2 = iVar2 + 1;
    }
    FUN_00194938(auStack_38);
  }
  return iVar2;
}
#undef local_28

/* FUN_001278d0 @ 0x1278d0 (196 bytes) */
int FUN_001278d0(param_1)
  int param_1;
{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint *puVar4;
  uint loopIndex;
  
  ((int (*)())FUN_0012740c)(param_1);
  puVar4 = *(uint **)(param_1 + 4);
  if (puVar4 != (uint *)0x0) {
    uVar1 = *puVar4;
    if (uVar1 == 0) {
      uVar3 = puVar4[2];
    }
    else {
      uVar3 = puVar4[2];
      loopIndex = 0;
      do {
        iVar2 = *(int *)(loopIndex * 4 + uVar3);
        if (iVar2 != 0) {
          Arena__free(puVar4[5],iVar2);
          uVar1 = *puVar4;
          uVar3 = puVar4[2];
        }
        loopIndex = loopIndex + 1;
      } while (loopIndex < uVar1);
    }
    Arena__free(puVar4[5],uVar3);
    Arena__free(puVar4[-1],puVar4 + -1);
    return;
  }
  return;
}

/* VRegInfo__new_127994 @ 0x127994 (1024 bytes) */
int VRegInfo__new_127994(compiler, param_2)
  int *compiler;
  int param_2;
{
  uint uVar1;
  undefined4 *allocation;
  int iVar3;
  undefined4 arena;
  uint *puVar5;
  
  compiler[0xb] = param_2;
  compiler[0xc] = -1;
  iVar3 = *(int *)(*(int *)(*compiler + 0x30c) + 0x30);
  compiler[0x10] = 0;
  compiler[0xd] = iVar3;
  compiler[0xe] = 0;
  compiler[0xf] = 0;
  arena = *(undefined4 *)(*compiler + 0x374);
  allocation = (undefined4 *)Arena__alloc(arena,0x1c);
  puVar5 = allocation + 1;
  *allocation = arena;
  uVar1 = 1;
  allocation[4] = keyEqualsThreeWords;
  allocation[1] = 1;
  iVar3 = 0x20;
  allocation[5] = FUN_001272b4;
  allocation[6] = arena;
  do {
    uVar1 = uVar1 << 1;
    if (0xf < uVar1) break;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  *puVar5 = uVar1;
  allocation[2] = 0;
  arena = Arena__alloc(arena,*puVar5 << 2);
  allocation[3] = arena;
  _memset(arena,0,*puVar5 << 2);
  compiler[1] = (int)puVar5;
  arena = *(undefined4 *)(*compiler + 0x374);
  allocation = (undefined4 *)Arena__alloc(arena,0x1c);
  puVar5 = allocation + 1;
  *allocation = arena;
  uVar1 = 1;
  allocation[4] = ConstKey__compare1;
  allocation[1] = 1;
  iVar3 = 0x20;
  allocation[5] = ConstKey__lanes1;
  allocation[6] = arena;
  do {
    uVar1 = uVar1 << 1;
    if (0xf < uVar1) break;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  *puVar5 = uVar1;
  allocation[2] = 0;
  arena = Arena__alloc(arena,*puVar5 << 2);
  allocation[3] = arena;
  _memset(arena,0,*puVar5 << 2);
  compiler[2] = (int)puVar5;
  arena = *(undefined4 *)(*compiler + 0x374);
  allocation = (undefined4 *)Arena__alloc(arena,0x1c);
  puVar5 = allocation + 1;
  *allocation = arena;
  uVar1 = 1;
  allocation[4] = ConstKey__compare2;
  allocation[1] = 1;
  iVar3 = 0x20;
  allocation[5] = ConstKey__lanes2;
  allocation[6] = arena;
  do {
    uVar1 = uVar1 << 1;
    if (0xf < uVar1) break;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  *puVar5 = uVar1;
  allocation[2] = 0;
  arena = Arena__alloc(arena,*puVar5 << 2);
  allocation[3] = arena;
  _memset(arena,0,*puVar5 << 2);
  compiler[3] = (int)puVar5;
  arena = *(undefined4 *)(*compiler + 0x374);
  allocation = (undefined4 *)Arena__alloc(arena,0x1c);
  puVar5 = allocation + 1;
  *allocation = arena;
  uVar1 = 1;
  allocation[4] = ConstKey__compare3;
  allocation[1] = 1;
  iVar3 = 0x20;
  allocation[5] = ConstKey__lanes3;
  allocation[6] = arena;
  do {
    uVar1 = uVar1 << 1;
    if (0xf < uVar1) break;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  *puVar5 = uVar1;
  allocation[2] = 0;
  arena = Arena__alloc(arena,*puVar5 << 2);
  allocation[3] = arena;
  _memset(arena,0,*puVar5 << 2);
  compiler[4] = (int)puVar5;
  arena = *(undefined4 *)(*compiler + 0x374);
  allocation = (undefined4 *)Arena__alloc(arena,0x1c);
  puVar5 = allocation + 1;
  *allocation = arena;
  uVar1 = 1;
  allocation[4] = ConstKey__compare4;
  allocation[1] = 1;
  iVar3 = 0x20;
  allocation[5] = ConstKey__lanes4;
  allocation[6] = arena;
  do {
    uVar1 = uVar1 << 1;
    if (0xf < uVar1) break;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  *puVar5 = uVar1;
  allocation[2] = 0;
  arena = Arena__alloc(arena,*puVar5 << 2);
  allocation[3] = arena;
  _memset(arena,0,*puVar5 << 2);
  compiler[5] = (int)puVar5;
  arena = *(undefined4 *)(*compiler + 0x374);
  allocation = (undefined4 *)Arena__alloc(arena,0x14);
  *allocation = arena;
  allocation[1] = 2;
  allocation[4] = arena;
  allocation[2] = 0;
  arena = Arena__alloc(arena,8);
  allocation[3] = arena;
  compiler[6] = (int)(allocation + 1);
  arena = *(undefined4 *)(*compiler + 0x374);
  allocation = (undefined4 *)Arena__alloc(arena,0x14);
  *allocation = arena;
  allocation[1] = 2;
  allocation[2] = 0;
  allocation[4] = arena;
  arena = Arena__alloc(arena,8);
  allocation[3] = arena;
  compiler[8] = (int)(allocation + 1);
  compiler[7] = 0;
  arena = *(undefined4 *)(*compiler + 0x374);
  allocation = (undefined4 *)Arena__alloc(arena,0x34);
  *allocation = arena;
  VRegInfo__ctor_1238e8(allocation + 1,0,0,0,*compiler);
  compiler[9] = (int)(allocation + 1);
  arena = *(undefined4 *)(*compiler + 0x374);
  allocation = (undefined4 *)Arena__alloc(arena,0x168);
  *allocation = arena;
  IRLoadConst__ctor_109938(allocation + 1,*compiler);
  compiler[10] = (int)(allocation + 1);
  *(undefined4 *)(*compiler + 0x348) = 0;
  *(undefined4 *)(*compiler + 0x334) = 1;
  *(undefined4 *)(*compiler + 0x338) = 0;
  compiler[0x19] = -1;
  compiler[0x11] = -1;
  compiler[0x12] = -1;
  compiler[0x13] = -1;
  compiler[0x14] = -1;
  compiler[0x15] = -1;
  compiler[0x16] = -1;
  compiler[0x17] = -1;
  compiler[0x18] = -1;
  return;
}

/* KhanPs__vslot21_appendRegisterBinding @ 0x127e48 (132 bytes) */
int KhanPs__vslot21_appendRegisterBinding(this, regIndex, bindingKind, param_4, laneSelectWord, param_6, param_7, param_8, param_9, param_10)
  int this;
  undefined4 regIndex;
  undefined4 bindingKind;
  undefined4 param_4;
  undefined4 laneSelectWord;
  int param_6;
  undefined4 param_7;
  undefined4 param_8;
  undefined4 param_9;
  undefined4 param_10;
{
  int record;
  
  record = *(int *)(((unsigned char *)0x0000172c) + this);
  *(int *)(((unsigned char *)0x0000172c) + this) = record + 1;
  record = this + record * 0x34 + 0x60;
  *(undefined4 *)(record + 8) = bindingKind;
  *(undefined4 *)(record + 0xc) = param_4;
  *(undefined4 *)(record + 0x10) = param_10;
  *(undefined4 *)(record + 0x1c) = 1;
  *(undefined1 *)(record + 0x37) = (undefined1)regIndex;
  *(char *)(record + 0x38) = (char)((uint)laneSelectWord >> 0x18);
  *(char *)(record + 0x39) = (char)((uint)laneSelectWord >> 0x10);
  *(char *)(record + 0x3a) = (char)((uint)laneSelectWord >> 8);
  *(char *)(record + 0x3b) = (char)laneSelectWord;
  *(uint *)(record + 0x24) = (uint)(param_6 == 0);
  *(undefined4 *)(record + 0x18) = param_9;
  *(undefined1 *)(record + 0x34) = (undefined1)regIndex;
  *(undefined1 *)(record + 0x35) = (undefined1)regIndex;
  *(undefined1 *)(record + 0x36) = (undefined1)regIndex;
  return;
}

/* KhanPs__vslot78_getLimit_0x20Or0x40 @ 0x127ecc (24 bytes) */
int KhanPs__vslot78_getLimit_0x20Or0x40(this)
  int this;
{
  if (*(int *)(0x00001740 + this) == 2) {
    return 0x40;
  }
  return 0x20;
}


/* issue: auto-generated aliases bridging data.s/code.s references (written
 * without a leading underscore, matching the raw stock-binary symbol name)
 * against the real compiled C symbols (gcc adds one underscore automatically).
 * Needed because ld64 (required for this PPC binary's size - stock ld breaks on
 * large PPC links) does not silently reconcile this the way stock ld did. */
asm(".globl FUN_001267ec");
asm(".set FUN_001267ec, _ImmedConstBuffer__vslot283");
asm(".globl FUN_001268f8");
asm(".set FUN_001268f8, _ImmedConstBuffer__vslot235");
asm(".globl FUN_00126984");
asm(".set FUN_00126984, _ImmedConstBuffer__vslot15");
asm(".globl FUN_00126a10");
asm(".set FUN_00126a10, _ImmedConstBuffer__vslot23");
asm(".globl FUN_00126a9c");
asm(".set FUN_00126a9c, _ImmedConstBuffer__vslot83");
asm(".globl FUN_00126b28");
asm(".set FUN_00126b28, _ImmedConstBuffer__vslot67");
asm(".globl FUN_00126bb4");
asm(".set FUN_00126bb4, _ImmedConstBuffer__vslot71");
asm(".globl FUN_00126c40");
asm(".set FUN_00126c40, _ImmedConstBuffer__vslot35");
asm(".globl FUN_00126ccc");
asm(".set FUN_00126ccc, _ImmedConstBuffer__vslot167");
asm(".globl FUN_00126d58");
asm(".set FUN_00126d58, _ImmedConstBuffer__vslot171");
asm(".globl FUN_00126e90");
asm(".set FUN_00126e90, _ImmedConstBuffer__vslot183");
asm(".globl FUN_00126f1c");
asm(".set FUN_00126f1c, _ImmedConstBuffer__vslot179");
asm(".globl FUN_00126fa8");
asm(".set FUN_00126fa8, _ImmedConstBuffer__vslot175");
asm(".globl FUN_00127034");
asm(".set FUN_00127034, _ImmedConstBuffer__vslot187");
asm(".globl FUN_001270c0");
asm(".set FUN_001270c0, _ImmedConstBuffer__vslot191");
asm(".globl FUN_0012714c");
asm(".set FUN_0012714c, _ImmedConstBuffer__vslot79");
asm(".globl FUN_001271d8");
asm(".set FUN_001271d8, _ImmedConstBuffer__vslot39");
asm(".globl FUN_00127e48");
asm(".set FUN_00127e48, _KhanPs__vslot21_appendRegisterBinding");
asm(".globl FUN_00127ecc");
asm(".set FUN_00127ecc, _KhanPs__vslot78_getLimit_0x20Or0x40");

/* issue #75 (follow-up #3): Ghidra recognized this as a THUNK - a pure trampoline stub that
 * just branches straight to the real function below, no different behavior or arguments - but
 * decls.h declares "thunk_FUN_xxx" as its own separate extern function that nothing in this
 * corpus ever DEFINES a body for. The stock ld apparently tolerated the resulting undefined
 * reference (never actually called in a way that mattered, or silently resolved some other
 * way); ld64 leaves it a real unresolved lazy symbol, crashing the moment this call path is
 * first taken. Real fix: alias the thunk name directly onto the real function, so calling
 * "thunk_FUN_xxx" IS calling FUN_xxx - which is exactly what the original binary's trampoline
 * did. */
asm(".globl _thunk_FUN_001268a4");
asm(".set _thunk_FUN_001268a4, _RegKind__flagBit9");
