#include "decls.h"

/* ExportAddress__ctor_1260f4 @ 0x1260f4 (88 bytes) */
int ExportAddress__ctor_1260f4(this, ctorWord2, ctorWord1, ctorWord3, compiler)
  undefined4 *this;
  undefined4 ctorWord2;
  undefined4 ctorWord1;
  undefined4 ctorWord3;
  undefined4 compiler;
{
  undefined *vtable;
  
  VRegInfo__ctor_12379c(this,ctorWord2,ctorWord1,ctorWord3,compiler);
  vtable = PTR_DAT_001e90d0;
  this[4] = 0x20;
  this[9] = this[9] | 2;
  *this = vtable + 8;
  return;
}

/* ExportAddress__ctor_12614c @ 0x12614c (88 bytes) */
int ExportAddress__ctor_12614c(this, ctorWord2, ctorWord1, ctorWord3, compiler)
  undefined4 *this;
  undefined4 ctorWord2;
  undefined4 ctorWord1;
  undefined4 ctorWord3;
  undefined4 compiler;
{
  undefined *vtable;
  
  VRegInfo__ctor_12379c(this,ctorWord2,ctorWord1,ctorWord3,compiler);
  vtable = PTR_DAT_001e90d0;
  this[4] = 0x20;
  this[9] = this[9] | 2;
  *this = vtable + 8;
  return;
}

/* ImmedConstBuffer__ctor_1261a4 @ 0x1261a4 (68 bytes) */
int ImmedConstBuffer__ctor_1261a4(this, ctorWord2, ctorWord1, ctorWord3, compiler)
  undefined4 *this;
  undefined4 ctorWord2;
  undefined4 ctorWord1;
  undefined4 ctorWord3;
  undefined4 compiler;
{
  VRegInfo__ctor_12379c(this,ctorWord2,ctorWord1,ctorWord3,compiler);
  *this = &PTR_FUN_001ea8d0;
  return;
}

/* ImmedConstBuffer__ctor_1261e8 @ 0x1261e8 (68 bytes) */
int ImmedConstBuffer__ctor_1261e8(this, ctorWord2, ctorWord1, ctorWord3, compiler)
  undefined4 *this;
  undefined4 ctorWord2;
  undefined4 ctorWord1;
  undefined4 ctorWord3;
  undefined4 compiler;
{
  VRegInfo__ctor_12379c(this,ctorWord2,ctorWord1,ctorWord3,compiler);
  *this = &PTR_FUN_001ea8d0;
  return;
}

/* ExportSlot__ctor_12622c @ 0x12622c (256 bytes) */
int ExportSlot__ctor_12622c(this, ctorWord2, ctorWord1, ctorWord3, compiler)
  undefined4 *this;
  undefined4 ctorWord2;
  undefined4 ctorWord1;
  undefined4 ctorWord3;
  int compiler;
{
  undefined4 arena;
  undefined4 *allocation;
  int operandRecord;
  undefined4 *exportInst;
  undefined4 exportStreamValue;
  
  VRegInfo__ctor_12379c(this,ctorWord2,ctorWord1,ctorWord3,compiler);
  this[4] = ctorWord2;
  this[9] = this[9] | 2;
  *this = &PTR_FUN_001ea7f0;
  if ((*(uint *)(*(int *)(compiler + COMP_currentProgram) + 0x30) & 0x4000) != 0) {
    arena = *(undefined4 *)(compiler + COMP_arenaA);
    allocation = (undefined4 *)Arena__alloc(arena,0x168);
    exportInst = allocation + 1;
    *allocation = arena;
    IRExport__ctor_108918(exportInst,compiler);
    allocation[0x28] = DAT_001afef0;
    IRInst__setOperandRef(exportInst,0,this);
    VReg__appendUser(this,exportInst);
    IRInst__setOperandRef(exportInst,1,this);
    exportStreamValue = DAT_001afeec;
    operandRecord = IRInst__getOperandRecord(exportInst,1);
    *(undefined4 *)(operandRecord + 0x10) = exportStreamValue;
    VReg__addUse(this,1,exportInst);
    Program__addInst(*(undefined4 *)(compiler + COMP_currentProgram),exportInst);
    Block__appendInst(*(undefined4 *)(*(int *)(compiler + COMP_currentProgram) + 0x3a8),exportInst);
  }
  return;
}

/* ExportSlot__ctor_126378 @ 0x126378 (256 bytes) */
int ExportSlot__ctor_126378(this, ctorWord2, ctorWord1, ctorWord3, compiler)
  undefined4 *this;
  undefined4 ctorWord2;
  undefined4 ctorWord1;
  undefined4 ctorWord3;
  int compiler;
{
  undefined4 arena;
  undefined4 *allocation;
  int operandRecord;
  undefined4 *exportInst;
  undefined4 exportStreamValue;
  
  VRegInfo__ctor_12379c(this,ctorWord2,ctorWord1,ctorWord3,compiler);
  this[4] = ctorWord2;
  this[9] = this[9] | 2;
  *this = &PTR_FUN_001ea7f0;
  if ((*(uint *)(*(int *)(compiler + COMP_currentProgram) + 0x30) & 0x4000) != 0) {
    arena = *(undefined4 *)(compiler + COMP_arenaA);
    allocation = (undefined4 *)Arena__alloc(arena,0x168);
    exportInst = allocation + 1;
    *allocation = arena;
    IRExport__ctor_108918(exportInst,compiler);
    allocation[0x28] = DAT_001afef0;
    IRInst__setOperandRef(exportInst,0,this);
    VReg__appendUser(this,exportInst);
    IRInst__setOperandRef(exportInst,1,this);
    exportStreamValue = DAT_001afeec;
    operandRecord = IRInst__getOperandRecord(exportInst,1);
    *(undefined4 *)(operandRecord + 0x10) = exportStreamValue;
    VReg__addUse(this,1,exportInst);
    Program__addInst(*(undefined4 *)(compiler + COMP_currentProgram),exportInst);
    Block__appendInst(*(undefined4 *)(*(int *)(compiler + COMP_currentProgram) + 0x3a8),exportInst);
  }
  return;
}

/* LoopIndexedConstSet__ctor_1264c4 @ 0x1264c4 (116 bytes) */
int LoopIndexedConstSet__ctor_1264c4(this, ctorWord2, ctorWord1, ctorWord3, compiler)
  undefined4 *this;
  undefined4 ctorWord2;
  undefined4 ctorWord1;
  undefined4 ctorWord3;
  int compiler;
{
  undefined *vtable;
  
  VRegInfo__ctor_12379c(this,ctorWord2,ctorWord1,ctorWord3,compiler);
  vtable = PTR_DAT_001e90ec;
  this[0xc] = 0;
  *this = vtable + 8;
  *this = PTR_DAT_001e90e4 + 8;
  this[4] = *(undefined4 *)(compiler + 0x33c);
  *(int *)(compiler + 0x33c) = *(int *)(compiler + 0x33c) + 1;
  return;
}

/* LoopIndexedConstSet__ctor_126538 @ 0x126538 (116 bytes) */
int LoopIndexedConstSet__ctor_126538(this, ctorWord2, ctorWord1, ctorWord3, compiler)
  undefined4 *this;
  undefined4 ctorWord2;
  undefined4 ctorWord1;
  undefined4 ctorWord3;
  int compiler;
{
  undefined *vtable;
  
  VRegInfo__ctor_12379c(this,ctorWord2,ctorWord1,ctorWord3,compiler);
  vtable = PTR_DAT_001e90ec;
  this[0xc] = 0;
  *this = vtable + 8;
  *this = PTR_DAT_001e90e4 + 8;
  this[4] = *(undefined4 *)(compiler + 0x33c);
  *(int *)(compiler + 0x33c) = *(int *)(compiler + 0x33c) + 1;
  return;
}

/* LoopIndexedInputSet__ctor_1265ac @ 0x1265ac (116 bytes) */
int LoopIndexedInputSet__ctor_1265ac(this, ctorWord2, ctorWord1, ctorWord3, compiler)
  undefined4 *this;
  undefined4 ctorWord2;
  undefined4 ctorWord1;
  undefined4 ctorWord3;
  int compiler;
{
  undefined *vtable;
  
  VRegInfo__ctor_12379c(this,ctorWord2,ctorWord1,ctorWord3,compiler);
  vtable = PTR_DAT_001e90ec;
  this[0xc] = 0;
  *this = vtable + 8;
  *this = PTR_DAT_001e90d4 + 8;
  this[4] = *(undefined4 *)(compiler + 0x340);
  *(int *)(compiler + 0x340) = *(int *)(compiler + 0x340) + 1;
  return;
}

/* LoopIndexedInputSet__ctor_126620 @ 0x126620 (116 bytes) */
int LoopIndexedInputSet__ctor_126620(this, ctorWord2, ctorWord1, ctorWord3, compiler)
  undefined4 *this;
  undefined4 ctorWord2;
  undefined4 ctorWord1;
  undefined4 ctorWord3;
  int compiler;
{
  undefined *vtable;
  
  VRegInfo__ctor_12379c(this,ctorWord2,ctorWord1,ctorWord3,compiler);
  vtable = PTR_DAT_001e90ec;
  this[0xc] = 0;
  *this = vtable + 8;
  *this = PTR_DAT_001e90d4 + 8;
  this[4] = *(undefined4 *)(compiler + 0x340);
  *(int *)(compiler + 0x340) = *(int *)(compiler + 0x340) + 1;
  return;
}

/* LoopIndexedOutputSet__ctor_126694 @ 0x126694 (116 bytes) */
int LoopIndexedOutputSet__ctor_126694(this, ctorWord2, ctorWord1, ctorWord3, compiler)
  undefined4 *this;
  undefined4 ctorWord2;
  undefined4 ctorWord1;
  undefined4 ctorWord3;
  int compiler;
{
  undefined *vtable;
  
  VRegInfo__ctor_12379c(this,ctorWord2,ctorWord1,ctorWord3,compiler);
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
int RegKind__flagBit8(movSourceKind)
  int movSourceKind;
{
  return *(uint *)(&DAT_001ea904 + movSourceKind * 0x10) >> 8 & 1;
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

/* Table1ea904__hasFlag0x11 @ 0x1267b8 (52 bytes) */
int Table1ea904__hasFlag0x11(param_1)
  int param_1;
{
  return -(uint)(*(uint *)(&DAT_001ea904 + param_1 * 0x10) & 0x11) >> 0x1f;
}

/* ImmedConstBuffer__vslot283 @ 0x1267ec (84 bytes) */
int ImmedConstBuffer__vslot283(this, ctorWord1, ctorWord3, compiler)
  undefined4 this;
  undefined4 ctorWord1;
  undefined4 ctorWord3;
  int compiler;
{
  undefined4 *allocation;
  undefined4 arena;
  
  arena = *(undefined4 *)(compiler + COMP_arenaA);
  allocation = (undefined4 *)Arena__alloc(arena,0x34);
  *allocation = arena;
  ((int (*)())ImmedConstBuffer__ctor_1261e8)(allocation + 1,this,ctorWord1,ctorWord3,compiler);
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
int ImmedConstBuffer__vslot235(this, ctorWord1, ctorWord3, compiler)
  undefined4 this;
  undefined4 ctorWord1;
  undefined4 ctorWord3;
  int compiler;
{
  undefined4 *allocation;
  undefined4 arena;
  
  arena = *(undefined4 *)(compiler + COMP_arenaA);
  allocation = (undefined4 *)Arena__alloc(arena,0x34);
  *allocation = arena;
  VertexRegister__ctor_1248ec(allocation + 1,this,ctorWord1,ctorWord3,compiler);
  return allocation + 1;
}

/* ImmedConstBuffer__vslot15 @ 0x126984 (84 bytes) */
int ImmedConstBuffer__vslot15(this, ctorWord1, ctorWord3, compiler)
  undefined4 this;
  undefined4 ctorWord1;
  undefined4 ctorWord3;
  int compiler;
{
  undefined4 *allocation;
  undefined4 arena;
  
  arena = *(undefined4 *)(compiler + COMP_arenaA);
  allocation = (undefined4 *)Arena__alloc(arena,0x38);
  *allocation = arena;
  TempValue__ctor_124e04(allocation + 1,this,ctorWord1,ctorWord3,compiler);
  return allocation + 1;
}

/* ImmedConstBuffer__vslot23 @ 0x126a10 (84 bytes) */
int ImmedConstBuffer__vslot23(this, registerFile, baseCtorArg4, compiler)
  undefined4 this;
  undefined4 registerFile;
  undefined4 baseCtorArg4;
  int compiler;
{
  undefined4 *allocation;
  undefined4 arena;
  
  arena = *(undefined4 *)(compiler + COMP_arenaA);
  allocation = (undefined4 *)Arena__alloc(arena,0x34);
  *allocation = arena;
  FixedValue__ctor_124724(allocation + 1,this,registerFile,baseCtorArg4,compiler);
  return allocation + 1;
}

/* ImmedConstBuffer__vslot83 @ 0x126a9c (84 bytes) */
int ImmedConstBuffer__vslot83(this, interpolatorKind, baseCtorArg4, compiler)
  undefined4 this;
  undefined4 interpolatorKind;
  undefined4 baseCtorArg4;
  int compiler;
{
  undefined4 *allocation;
  undefined4 arena;
  
  arena = *(undefined4 *)(compiler + COMP_arenaA);
  allocation = (undefined4 *)Arena__alloc(arena,0x44);
  *allocation = arena;
  Interpolator__ctor_1257b0(allocation + 1,this,interpolatorKind,baseCtorArg4,compiler);
  return allocation + 1;
}

/* ImmedConstBuffer__vslot67 @ 0x126b28 (84 bytes) */
int ImmedConstBuffer__vslot67(this, baseCtorArg3, baseCtorArg4, compiler)
  undefined4 this;
  undefined4 baseCtorArg3;
  undefined4 baseCtorArg4;
  int compiler;
{
  undefined4 *allocation;
  undefined4 arena;
  
  arena = *(undefined4 *)(compiler + COMP_arenaA);
  allocation = (undefined4 *)Arena__alloc(arena,0x38);
  *allocation = arena;
  StandardIndex__ctor_124b24(allocation + 1,this,baseCtorArg3,baseCtorArg4,compiler);
  return allocation + 1;
}

/* ImmedConstBuffer__vslot71 @ 0x126bb4 (84 bytes) */
int ImmedConstBuffer__vslot71(this, baseCtorArg3, baseCtorArg4, compiler)
  undefined4 this;
  undefined4 baseCtorArg3;
  undefined4 baseCtorArg4;
  int compiler;
{
  undefined4 *allocation;
  undefined4 arena;
  
  arena = *(undefined4 *)(compiler + COMP_arenaA);
  allocation = (undefined4 *)Arena__alloc(arena,0x38);
  *allocation = arena;
  PrimitiveIndex__ctor_125db8(allocation + 1,this,baseCtorArg3,baseCtorArg4,compiler);
  return allocation + 1;
}

/* ImmedConstBuffer__vslot35 @ 0x126c40 (84 bytes) */
int ImmedConstBuffer__vslot35(this, ctorWord1, ctorWord3, compiler)
  undefined4 this;
  undefined4 ctorWord1;
  undefined4 ctorWord3;
  int compiler;
{
  undefined4 *allocation;
  undefined4 arena;
  
  arena = *(undefined4 *)(compiler + COMP_arenaA);
  allocation = (undefined4 *)Arena__alloc(arena,0x34);
  *allocation = arena;
  Resource__ctor_125d60(allocation + 1,this,ctorWord1,ctorWord3,compiler);
  return allocation + 1;
}

/* ImmedConstBuffer__vslot167 @ 0x126ccc (84 bytes) */
int ImmedConstBuffer__vslot167(this, ctorWord1, ctorWord3, compiler)
  undefined4 this;
  undefined4 ctorWord1;
  undefined4 ctorWord3;
  int compiler;
{
  undefined4 *allocation;
  undefined4 arena;
  
  arena = *(undefined4 *)(compiler + COMP_arenaA);
  allocation = (undefined4 *)Arena__alloc(arena,0x38);
  *allocation = arena;
  AddrIndexedSet__ctor_125f94(allocation + 1,this,ctorWord1,ctorWord3,compiler);
  return allocation + 1;
}

/* ImmedConstBuffer__vslot171 @ 0x126d58 (84 bytes) */
int ImmedConstBuffer__vslot171(this, ctorWord1, ctorWord3, compiler)
  undefined4 this;
  undefined4 ctorWord1;
  undefined4 ctorWord3;
  int compiler;
{
  undefined4 *allocation;
  undefined4 arena;
  
  arena = *(undefined4 *)(compiler + COMP_arenaA);
  allocation = (undefined4 *)Arena__alloc(arena,0x34);
  *allocation = arena;
  LoopRegister__ctor_126034(allocation + 1,this,ctorWord1,ctorWord3,compiler);
  return allocation + 1;
}

/* LoopIndexedSet__ctor_126de4 @ 0x126de4 (92 bytes) */
int LoopIndexedSet__ctor_126de4(ctorWord2, ctorWord1, ctorWord3, compiler)
  undefined4 ctorWord2;
  undefined4 ctorWord1;
  undefined4 ctorWord3;
  int compiler;
{
  undefined *vtable;
  undefined4 *allocation;
  undefined4 arena;
  undefined4 *object;
  
  arena = *(undefined4 *)(compiler + COMP_arenaA);
  allocation = (undefined4 *)Arena__alloc(arena,0x38);
  object = allocation + 1;
  *allocation = arena;
  VRegInfo__ctor_12379c(object,ctorWord2,ctorWord1,ctorWord3,compiler);
  vtable = PTR_DAT_001e90ec;
  allocation[0xd] = 0;
  *object = vtable + 8;
  return object;
}

/* ImmedConstBuffer__vslot183 @ 0x126e90 (84 bytes) */
int ImmedConstBuffer__vslot183(this, ctorWord1, ctorWord3, compiler)
  undefined4 this;
  undefined4 ctorWord1;
  undefined4 ctorWord3;
  int compiler;
{
  undefined4 *allocation;
  undefined4 arena;
  
  arena = *(undefined4 *)(compiler + COMP_arenaA);
  allocation = (undefined4 *)Arena__alloc(arena,0x38);
  *allocation = arena;
  LoopIndexedOutputSet__ctor_126080(allocation + 1,this,ctorWord1,ctorWord3,compiler);
  return allocation + 1;
}

/* ImmedConstBuffer__vslot179 @ 0x126f1c (84 bytes) */
int ImmedConstBuffer__vslot179(this, ctorWord1, ctorWord3, compiler)
  undefined4 this;
  undefined4 ctorWord1;
  undefined4 ctorWord3;
  int compiler;
{
  undefined4 *allocation;
  undefined4 arena;
  
  arena = *(undefined4 *)(compiler + COMP_arenaA);
  allocation = (undefined4 *)Arena__alloc(arena,0x38);
  *allocation = arena;
  ((int (*)())LoopIndexedInputSet__ctor_126620)(allocation + 1,this,ctorWord1,ctorWord3,compiler);
  return allocation + 1;
}

/* ImmedConstBuffer__vslot175 @ 0x126fa8 (84 bytes) */
int ImmedConstBuffer__vslot175(this, ctorWord1, ctorWord3, compiler)
  undefined4 this;
  undefined4 ctorWord1;
  undefined4 ctorWord3;
  int compiler;
{
  undefined4 *allocation;
  undefined4 arena;
  
  arena = *(undefined4 *)(compiler + COMP_arenaA);
  allocation = (undefined4 *)Arena__alloc(arena,0x38);
  *allocation = arena;
  ((int (*)())LoopIndexedConstSet__ctor_126538)(allocation + 1,this,ctorWord1,ctorWord3,compiler);
  return allocation + 1;
}

/* ImmedConstBuffer__vslot187 @ 0x127034 (84 bytes) */
int ImmedConstBuffer__vslot187(this, ctorWord1, ctorWord3, compiler)
  undefined4 this;
  undefined4 ctorWord1;
  undefined4 ctorWord3;
  int compiler;
{
  undefined4 *allocation;
  undefined4 arena;
  
  arena = *(undefined4 *)(compiler + COMP_arenaA);
  allocation = (undefined4 *)Arena__alloc(arena,0x34);
  *allocation = arena;
  ((int (*)())ExportAddress__ctor_12614c)(allocation + 1,this,ctorWord1,ctorWord3,compiler);
  return allocation + 1;
}

/* ImmedConstBuffer__vslot191 @ 0x1270c0 (84 bytes) */
int ImmedConstBuffer__vslot191(this, ctorWord1, ctorWord3, compiler)
  undefined4 this;
  undefined4 ctorWord1;
  undefined4 ctorWord3;
  int compiler;
{
  undefined4 *allocation;
  undefined4 arena;
  
  arena = *(undefined4 *)(compiler + COMP_arenaA);
  allocation = (undefined4 *)Arena__alloc(arena,0x34);
  *allocation = arena;
  ((int (*)())ExportSlot__ctor_126378)(allocation + 1,this,ctorWord1,ctorWord3,compiler);
  return allocation + 1;
}

/* ImmedConstBuffer__vslot79 @ 0x12714c (84 bytes) */
int ImmedConstBuffer__vslot79(this, ctorWord1, ctorWord3, compiler)
  undefined4 this;
  undefined4 ctorWord1;
  undefined4 ctorWord3;
  int compiler;
{
  undefined4 *allocation;
  undefined4 arena;
  
  arena = *(undefined4 *)(compiler + COMP_arenaA);
  allocation = (undefined4 *)Arena__alloc(arena,0x34);
  *allocation = arena;
  Physical__ctor_125c8c(allocation + 1,this,ctorWord1,ctorWord3,compiler);
  return allocation + 1;
}

/* ImmedConstBuffer__vslot39 @ 0x1271d8 (84 bytes) */
int ImmedConstBuffer__vslot39(this, interpolatorKind, baseCtorArg4, compiler)
  undefined4 this;
  undefined4 interpolatorKind;
  undefined4 baseCtorArg4;
  int compiler;
{
  undefined4 *allocation;
  undefined4 arena;
  
  arena = *(undefined4 *)(compiler + COMP_arenaA);
  allocation = (undefined4 *)Arena__alloc(arena,0x3c);
  *allocation = arena;
  ExportValue__ctor_1250dc(allocation + 1,this,interpolatorKind,baseCtorArg4,compiler);
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
int ConstKey__lanes3(key)
  int key;
{
  return *(int *)(key + 0x20) + *(int *)(key + 0x38) + *(int *)(key + 0x50);
}

/* ConstKey__lanes4 @ 0x127294 (32 bytes) */
int ConstKey__lanes4(key)
  int key;
{
  return *(int *)(key + 0x20) + *(int *)(key + 0x38) + *(int *)(key + 0x50) +
         *(int *)(key + 0x68);
}

/* Object__sumWords4And8 @ 0x1272b4 (16 bytes) */
int Object__sumWords4And8(param_1)
  int param_1;
{
  return *(int *)(param_1 + 4) + *(int *)(param_1 + 8);
}

/* Object__setWord0 @ 0x1272cc (8 bytes) */
int Object__setWord0(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  *param_1 = param_2;
  return;
}

/* VRegPool__canonicalizeKey @ 0x1272d4 (80 bytes) */
int VRegPool__canonicalizeKey(cache, kindRef, valueRef)
  int cache;
  int *kindRef;
  int *valueRef;
{
  if (*kindRef != 0x24) {
    return;
  }
  if (*valueRef == *(int *)(cache + 0x44)) {
    *kindRef = 6;
    *valueRef = 0;
    return;
  }
  if (*valueRef != *(int *)(cache + 0x48)) {
    return;
  }
  *kindRef = 7;
  *valueRef = 0;
  return;
}

/* FUN_00127324 @ 0x127324 (232 bytes) */
int FUN_00127324(program, registerFileKind, vregId, kindOut, indexOut)
  int program;
  int registerFileKind;
  int vregId;
  undefined4 *kindOut;
  undefined4 *indexOut;
{
  if (registerFileKind == 0x24) {
    if (*(int *)(program + 0x4c) == vregId) {
      *kindOut = 0x3f;
      *indexOut = 0;
      return 1;
    }
    if (vregId == *(int *)(program + 0x54)) {
      *kindOut = 0x3f;
      *indexOut = 1;
      return 1;
    }
    if (vregId == *(int *)(program + 0x50)) {
      *kindOut = 0x40;
      *indexOut = 0;
      return 1;
    }
    if (vregId == *(int *)(program + 0x58)) {
      *kindOut = 0x40;
      *indexOut = 1;
      return 1;
    }
    if (vregId == *(int *)(program + 0x5c)) {
      *kindOut = 0x3e;
      *indexOut = 0;
      return 1;
    }
    if (vregId == *(int *)(program + 0x60)) {
      *kindOut = 0x41;
      *indexOut = 0;
      return 1;
    }
  }
  return 0;
}

/* VRegPool__destroyEntries @ 0x12740c (100 bytes) */
int VRegPool__destroyEntries(owner)
  int owner;
{
  /* issue #64 live-repro: same iterator-object split as Program__insertPhiNodes (part_037.c), fixed earlier
   * this session - auStack_38 is walked by HashTableIterator__advance/HashTableIterator__begin as owner[0..4] (0x14 bytes)
   * but declared only 16 bytes; local_28, the missing 5th word, is what this loop reads back as its
   * own continuation value. Separated, HashTableIterator__advance's real update never reached local_28, so the
   * loop never saw it become null - not just a hang: the same (unchanging) local_28 object got
   * re-passed to the vtable call on every spin instead of the real next node, repeatedly
   * re-processing/re-freeing one object - a plausible source of the unrelated heap corruption seen
   * elsewhere on this issue (Program__hoistInstructions: an objects own vtable-like field changing under it
   * between two visits). Merged into one 0x14-byte buffer. */
  unsigned char auStack_38 [0x14];
#define local_28 (*(int **)(auStack_38 + 0x10))
  
  HashTableIterator__begin(auStack_38,*(undefined4 *)(owner + 4));
  while (local_28 != (int *)0x0) {
    (**(code **)(*local_28 + 4))(local_28);
    HashTableIterator__advance(auStack_38);
  }
  return;
}

/* VRegPool__dtor_127470 @ 0x127470 (196 bytes) */
int VRegPool__dtor_127470(owner)
  int owner;
{
  uint bucketCount;
  int bucketChain;
  uint bucketArray;
  uint *hashTable;
  uint loopIndex;
  
  ((int (*)())VRegPool__destroyEntries)(owner);
  hashTable = *(uint **)(owner + 4);
  if (hashTable != (uint *)0x0) {
    bucketCount = *hashTable;
    if (bucketCount == 0) {
      bucketArray = hashTable[2];
    }
    else {
      bucketArray = hashTable[2];
      loopIndex = 0;
      do {
        bucketChain = *(int *)(loopIndex * 4 + bucketArray);
        if (bucketChain != 0) {
          Arena__free(hashTable[5],bucketChain);
          bucketCount = *hashTable;
          bucketArray = hashTable[2];
        }
        loopIndex = loopIndex + 1;
      } while (loopIndex < bucketCount);
    }
    Arena__free(hashTable[5],bucketArray);
    Arena__free(hashTable[-1],hashTable + -1);
    return;
  }
  return;
}

/* VRegPool__find @ 0x127534 (108 bytes) */
int VRegPool__find(cache, keyA, keyB, keyExtra)
  int cache;
  undefined4 keyA;
  undefined4 keyB;
  undefined4 keyExtra;
{
  unsigned int ghidra_home[8] = { cache, keyA, keyB, keyExtra, 0, 0, 0, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  undefined4 callResult;
  
  (*(unsigned int *)((unsigned char *)ghidra_home + 4)) = keyA;
  (*(unsigned int *)((unsigned char *)ghidra_home + 8)) = keyB;
  ((int (*)())VRegPool__canonicalizeKey)(cache,&(*(unsigned int *)((unsigned char *)ghidra_home + 4)),&(*(unsigned int *)((unsigned char *)ghidra_home + 8)));
  *(undefined4 *)(*(int *)(cache + 0x24) + 8) = (*(unsigned int *)((unsigned char *)ghidra_home + 8));
  *(undefined4 *)(*(int *)(cache + 0x24) + 4) = (*(unsigned int *)((unsigned char *)ghidra_home + 4));
  *(undefined4 *)(*(int *)(cache + 0x24) + 0xc) = keyExtra;
  callResult = HashTable__find(*(undefined4 *)(cache + 4),*(undefined4 *)(cache + 0x24));
  return callResult;
}

/* VRegPool__create @ 0x1275a0 (104 bytes) */
int VRegPool__create(cache, keyA, keyB, keyExtra)
  uint *cache;
  undefined4 keyA;
  undefined4 keyB;
  uint keyExtra;
{
  unsigned int ghidra_home[8] = { cache, keyA, keyB, keyExtra, 0, 0, 0, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  undefined4 callResult;
  
  (*(unsigned int *)((unsigned char *)ghidra_home + 4)) = keyA;
  (*(unsigned int *)((unsigned char *)ghidra_home + 8)) = keyB;
  ((int (*)())VRegPool__canonicalizeKey)(cache,&(*(unsigned int *)((unsigned char *)ghidra_home + 4)),&(*(unsigned int *)((unsigned char *)ghidra_home + 8)));
  callResult = VRegPool__constructByKind((*(unsigned int *)((unsigned char *)ghidra_home + 8)),(*(unsigned int *)((unsigned char *)ghidra_home + 4)),keyExtra,*cache);
  HashTable__insert(cache[1],callResult);
  return callResult;
}

/* VRegPool__findOrCreate @ 0x127608 (100 bytes) */
int VRegPool__findOrCreate(cache, keyA, keyB, keyExtra)
  undefined4 cache;
  undefined4 keyA;
  undefined4 keyB;
  undefined4 keyExtra;
{
  int callResult;
  undefined4 callResult2;
  
  callResult = ((int (*)())VRegPool__find)(cache,keyA,keyB,keyExtra);
  if (callResult == 0) {
    callResult2 = ((int (*)())VRegPool__create)(cache,keyA,keyB,keyExtra);
    return callResult2;
  }
  return callResult;
}

/* ConstKey__compare1 @ 0x12766c (52 bytes) */
int ConstKey__compare1(keyA, keyB)
  int keyA;
  int keyB;
{
  if (((*(byte *)(keyA + 0x15c) & 1) == (*(byte *)(keyB + 0x15c) & 1)) &&
     (*(int *)(keyA + 0x20) == *(int *)(keyB + 0x20))) {
    return 0;
  }
  return 0xffffffff;
}

/* ConstKey__compare2 @ 0x1276a0 (92 bytes) */
int ConstKey__compare2(keyA, keyB)
  int keyA;
  int keyB;
{
  if ((((((int)*(char *)(keyA + 0x15c) & 1U) == ((int)*(char *)(keyB + 0x15c) & 1U)) &&
       (*(int *)(keyA + 0x20) == *(int *)(keyB + 0x20))) &&
      (((uint)(int)*(char *)(keyA + 0x15c) >> 1 & 1) ==
       ((uint)(int)*(char *)(keyB + 0x15c) >> 1 & 1))) &&
     (*(int *)(keyA + 0x38) == *(int *)(keyB + 0x38))) {
    return 0;
  }
  return 0xffffffff;
}

/* ConstKey__compare3 @ 0x1276fc (124 bytes) */
int ConstKey__compare3(keyA, keyB)
  int keyA;
  int keyB;
{
  uint flagsB;
  uint flagsA;
  
  flagsA = (uint)*(char *)(keyA + 0x15c);
  flagsB = (uint)*(char *)(keyB + 0x15c);
  if (((((flagsA & 1) == (flagsB & 1)) && (*(int *)(keyA + 0x20) == *(int *)(keyB + 0x20))) &&
      ((flagsA >> 1 & 1) == (flagsB >> 1 & 1))) &&
     (((*(int *)(keyA + 0x38) == *(int *)(keyB + 0x38) &&
       ((flagsA >> 2 & 1) == (flagsB >> 2 & 1))) &&
      (*(int *)(keyA + 0x50) == *(int *)(keyB + 0x50))))) {
    return 0;
  }
  return 0xffffffff;
}

/* ConstKey__compare4 @ 0x127778 (156 bytes) */
int ConstKey__compare4(keyA, keyB)
  int keyA;
  int keyB;
{
  uint keyBFlags;
  uint keyAFlags;
  
  keyAFlags = (uint)*(char *)(keyA + 0x15c);
  keyBFlags = (uint)*(char *)(keyB + 0x15c);
  if ((((((keyAFlags & 1) == (keyBFlags & 1)) && (*(int *)(keyA + 0x20) == *(int *)(keyB + 0x20))) &&
       ((keyAFlags >> 1 & 1) == (keyBFlags >> 1 & 1))) &&
      ((*(int *)(keyA + 0x38) == *(int *)(keyB + 0x38) &&
       ((keyAFlags >> 2 & 1) == (keyBFlags >> 2 & 1))))) &&
     ((*(int *)(keyA + 0x50) == *(int *)(keyB + 0x50) &&
      (((keyAFlags >> 3 & 1) == (keyBFlags >> 3 & 1) &&
       (*(int *)(keyA + 0x68) == *(int *)(keyB + 0x68))))))) {
    return 0;
  }
  return 0xffffffff;
}

/* keyEqualsThreeWords @ 0x127814 (60 bytes) */
int keyEqualsThreeWords(keyA, keyB)
  int keyA;
  int keyB;
{
  if (((*(int *)(keyA + 8) == *(int *)(keyB + 8)) &&
      (*(int *)(keyA + 4) == *(int *)(keyB + 4))) &&
     (*(int *)(keyA + 0xc) == *(int *)(keyB + 0xc))) {
    return 0;
  }
  return 0xffffffff;
}

/* VRegPool__countEntriesWithQuery18 @ 0x127850 (128 bytes) */
int VRegPool__countEntriesWithQuery18(owner)
  int owner;
{
  int elementQuery18;
  int matchCount;
  /* issue #64 live-repro: same iterator-object split as Program__insertPhiNodes (part_037.c), fixed earlier
   * this session - iteratorState is walked by HashTableIterator__advance/HashTableIterator__begin as owner[0..4] (0x14 bytes)
   * but declared only 16 bytes; iteratorCurrent, the missing 5th word, is what this loop reads back as its
   * own continuation value. Separated, HashTableIterator__advance's real update never reached iteratorCurrent, so the
   * loop never saw it become null - not just a hang: the same (unchanging) iteratorCurrent object got
   * re-passed to the vtable call on every spin instead of the real next node, repeatedly
   * re-processing/re-freeing one object - a plausible source of the unrelated heap corruption seen
   * elsewhere on this issue (Program__hoistInstructions: an objects own vtable-like field changing under it
   * between two visits). Merged into one 0x14-byte buffer. */
  unsigned char iteratorState [0x14];
#define iteratorCurrent (*(int **)(iteratorState + 0x10))
  
  HashTableIterator__begin(iteratorState,*(undefined4 *)(owner + 4));
  matchCount = 0;
  while (iteratorCurrent != (int *)0x0) {
    elementQuery18 = (**(code **)(*iteratorCurrent + 0x18))(iteratorCurrent);
    if (elementQuery18 != 0) {
      matchCount = matchCount + 1;
    }
    HashTableIterator__advance(iteratorState);
  }
  return matchCount;
}
#undef iteratorCurrent

/* VRegPool__dtor_1278d0 @ 0x1278d0 (196 bytes) */
int VRegPool__dtor_1278d0(owner)
  int owner;
{
  uint bucketCount;
  int bucketChain;
  uint bucketArray;
  uint *hashTable;
  uint loopIndex;
  
  ((int (*)())VRegPool__destroyEntries)(owner);
  hashTable = *(uint **)(owner + 4);
  if (hashTable != (uint *)0x0) {
    bucketCount = *hashTable;
    if (bucketCount == 0) {
      bucketArray = hashTable[2];
    }
    else {
      bucketArray = hashTable[2];
      loopIndex = 0;
      do {
        bucketChain = *(int *)(loopIndex * 4 + bucketArray);
        if (bucketChain != 0) {
          Arena__free(hashTable[5],bucketChain);
          bucketCount = *hashTable;
          bucketArray = hashTable[2];
        }
        loopIndex = loopIndex + 1;
      } while (loopIndex < bucketCount);
    }
    Arena__free(hashTable[5],bucketArray);
    Arena__free(hashTable[-1],hashTable + -1);
    return;
  }
  return;
}

/* VRegInfo__new_127994 @ 0x127994 (1024 bytes) */
int VRegInfo__new_127994(compiler, ownerArg)
  int *compiler;
  int ownerArg;
{
  uint *constLanes4Table;
  uint *constLanes3Table;
  uint *constLanes2Table;
  uint *constLanes1Table;
  int sizeLoopCountdown;
  uint hashTableSize;
  undefined4 *allocation;
  int backendDefaultWord;
  undefined4 arena;
  uint *threeWordKeyTable;
  
  compiler[0xb] = ownerArg;
  compiler[0xc] = -1;
  backendDefaultWord = *(int *)(*(int *)(*compiler + 0x30c) + 0x30);
  compiler[0x10] = 0;
  compiler[0xd] = backendDefaultWord;
  compiler[0xe] = 0;
  compiler[0xf] = 0;
  arena = *(undefined4 *)(*compiler + 0x374);
  allocation = (undefined4 *)Arena__alloc(arena,0x1c);
  threeWordKeyTable = allocation + 1;
  *allocation = arena;
  hashTableSize = 1;
  allocation[4] = keyEqualsThreeWords;
  allocation[1] = 1;
  sizeLoopCountdown = 0x20;
  allocation[5] = Object__sumWords4And8;
  allocation[6] = arena;
  do {
    hashTableSize = hashTableSize << 1;
    if (0xf < hashTableSize) break;
    sizeLoopCountdown = sizeLoopCountdown + -1;
  } while (sizeLoopCountdown != 0);
  *threeWordKeyTable = hashTableSize;
  allocation[2] = 0;
  arena = Arena__alloc(arena,*threeWordKeyTable << 2);
  allocation[3] = arena;
  _memset(arena,0,*threeWordKeyTable << 2);
  compiler[1] = (int)threeWordKeyTable;
  arena = *(undefined4 *)(*compiler + 0x374);
  allocation = (undefined4 *)Arena__alloc(arena,0x1c);
  constLanes1Table = allocation + 1;
  *allocation = arena;
  hashTableSize = 1;
  allocation[4] = ConstKey__compare1;
  allocation[1] = 1;
  sizeLoopCountdown = 0x20;
  allocation[5] = ConstKey__lanes1;
  allocation[6] = arena;
  do {
    hashTableSize = hashTableSize << 1;
    if (0xf < hashTableSize) break;
    sizeLoopCountdown = sizeLoopCountdown + -1;
  } while (sizeLoopCountdown != 0);
  *constLanes1Table = hashTableSize;
  allocation[2] = 0;
  arena = Arena__alloc(arena,*constLanes1Table << 2);
  allocation[3] = arena;
  _memset(arena,0,*constLanes1Table << 2);
  compiler[2] = (int)constLanes1Table;
  arena = *(undefined4 *)(*compiler + 0x374);
  allocation = (undefined4 *)Arena__alloc(arena,0x1c);
  constLanes2Table = allocation + 1;
  *allocation = arena;
  hashTableSize = 1;
  allocation[4] = ConstKey__compare2;
  allocation[1] = 1;
  sizeLoopCountdown = 0x20;
  allocation[5] = ConstKey__lanes2;
  allocation[6] = arena;
  do {
    hashTableSize = hashTableSize << 1;
    if (0xf < hashTableSize) break;
    sizeLoopCountdown = sizeLoopCountdown + -1;
  } while (sizeLoopCountdown != 0);
  *constLanes2Table = hashTableSize;
  allocation[2] = 0;
  arena = Arena__alloc(arena,*constLanes2Table << 2);
  allocation[3] = arena;
  _memset(arena,0,*constLanes2Table << 2);
  compiler[3] = (int)constLanes2Table;
  arena = *(undefined4 *)(*compiler + 0x374);
  allocation = (undefined4 *)Arena__alloc(arena,0x1c);
  constLanes3Table = allocation + 1;
  *allocation = arena;
  hashTableSize = 1;
  allocation[4] = ConstKey__compare3;
  allocation[1] = 1;
  sizeLoopCountdown = 0x20;
  allocation[5] = ConstKey__lanes3;
  allocation[6] = arena;
  do {
    hashTableSize = hashTableSize << 1;
    if (0xf < hashTableSize) break;
    sizeLoopCountdown = sizeLoopCountdown + -1;
  } while (sizeLoopCountdown != 0);
  *constLanes3Table = hashTableSize;
  allocation[2] = 0;
  arena = Arena__alloc(arena,*constLanes3Table << 2);
  allocation[3] = arena;
  _memset(arena,0,*constLanes3Table << 2);
  compiler[4] = (int)constLanes3Table;
  arena = *(undefined4 *)(*compiler + 0x374);
  allocation = (undefined4 *)Arena__alloc(arena,0x1c);
  constLanes4Table = allocation + 1;
  *allocation = arena;
  hashTableSize = 1;
  allocation[4] = ConstKey__compare4;
  allocation[1] = 1;
  sizeLoopCountdown = 0x20;
  allocation[5] = ConstKey__lanes4;
  allocation[6] = arena;
  do {
    hashTableSize = hashTableSize << 1;
    if (0xf < hashTableSize) break;
    sizeLoopCountdown = sizeLoopCountdown + -1;
  } while (sizeLoopCountdown != 0);
  *constLanes4Table = hashTableSize;
  allocation[2] = 0;
  arena = Arena__alloc(arena,*constLanes4Table << 2);
  allocation[3] = arena;
  _memset(arena,0,*constLanes4Table << 2);
  compiler[5] = (int)constLanes4Table;
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
asm(".globl ImmedConstBuffer__vslot283");
asm(".set ImmedConstBuffer__vslot283, _ImmedConstBuffer__vslot283");
asm(".globl ImmedConstBuffer__vslot235");
asm(".set ImmedConstBuffer__vslot235, _ImmedConstBuffer__vslot235");
asm(".globl ImmedConstBuffer__vslot15");
asm(".set ImmedConstBuffer__vslot15, _ImmedConstBuffer__vslot15");
asm(".globl ImmedConstBuffer__vslot23");
asm(".set ImmedConstBuffer__vslot23, _ImmedConstBuffer__vslot23");
asm(".globl ImmedConstBuffer__vslot83");
asm(".set ImmedConstBuffer__vslot83, _ImmedConstBuffer__vslot83");
asm(".globl ImmedConstBuffer__vslot67");
asm(".set ImmedConstBuffer__vslot67, _ImmedConstBuffer__vslot67");
asm(".globl ImmedConstBuffer__vslot71");
asm(".set ImmedConstBuffer__vslot71, _ImmedConstBuffer__vslot71");
asm(".globl ImmedConstBuffer__vslot35");
asm(".set ImmedConstBuffer__vslot35, _ImmedConstBuffer__vslot35");
asm(".globl ImmedConstBuffer__vslot167");
asm(".set ImmedConstBuffer__vslot167, _ImmedConstBuffer__vslot167");
asm(".globl ImmedConstBuffer__vslot171");
asm(".set ImmedConstBuffer__vslot171, _ImmedConstBuffer__vslot171");
asm(".globl ImmedConstBuffer__vslot183");
asm(".set ImmedConstBuffer__vslot183, _ImmedConstBuffer__vslot183");
asm(".globl ImmedConstBuffer__vslot179");
asm(".set ImmedConstBuffer__vslot179, _ImmedConstBuffer__vslot179");
asm(".globl ImmedConstBuffer__vslot175");
asm(".set ImmedConstBuffer__vslot175, _ImmedConstBuffer__vslot175");
asm(".globl ImmedConstBuffer__vslot187");
asm(".set ImmedConstBuffer__vslot187, _ImmedConstBuffer__vslot187");
asm(".globl ImmedConstBuffer__vslot191");
asm(".set ImmedConstBuffer__vslot191, _ImmedConstBuffer__vslot191");
asm(".globl ImmedConstBuffer__vslot79");
asm(".set ImmedConstBuffer__vslot79, _ImmedConstBuffer__vslot79");
asm(".globl ImmedConstBuffer__vslot39");
asm(".set ImmedConstBuffer__vslot39, _ImmedConstBuffer__vslot39");
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
