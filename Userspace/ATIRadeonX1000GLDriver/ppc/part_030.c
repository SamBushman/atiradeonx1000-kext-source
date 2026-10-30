#include "decls.h"

/* IRLoad__ctor_109a80 @ 0x109a80 (76 bytes) */
int IRLoad__ctor_109a80(this, kind, compiler)
  undefined4 *this;
  undefined4 kind;
  undefined4 compiler;
{
  undefined *vtable;
  
  IRPseudo__ctor(this,kind,compiler);
  vtable = PTR_DAT_001e8c54;
  this[0x20] = 1;
  *this = vtable + 8;
  return;
}

/* IRImmedConstBuff__ctor_109acc @ 0x109acc (84 bytes) */
int IRImmedConstBuff__ctor_109acc(this, kind, compiler)
  undefined4 *this;
  undefined4 kind;
  undefined4 compiler;
{
  undefined *vtable;
  
  IRPseudo__ctor(this,kind,compiler);
  vtable = PTR_DAT_001e8c04;
  this[0x21] = 0;
  this[0x20] = 1;
  *this = vtable + 8;
  return;
}

/* IRImmedConstBuff__ctor_109b20 @ 0x109b20 (84 bytes) */
int IRImmedConstBuff__ctor_109b20(this, kind, compiler)
  undefined4 *this;
  undefined4 kind;
  undefined4 compiler;
{
  undefined *vtable;
  
  IRPseudo__ctor(this,kind,compiler);
  vtable = PTR_DAT_001e8c04;
  this[0x21] = 0;
  this[0x20] = 1;
  *this = vtable + 8;
  return;
}

/* IRImmedConstBuff__new_109b74 @ 0x109b74 (68 bytes) */
int IRImmedConstBuff__new_109b74(opcode, compiler)
  undefined4 opcode;
  int compiler;
{
  undefined4 *allocation;
  undefined4 arena;
  
  arena = *(undefined4 *)(compiler + COMP_arenaA);
  allocation = (undefined4 *)Arena__alloc(arena,0x168);
  *allocation = arena;
  ((int (*)())IRImmedConstBuff__ctor_109b20)(allocation + 1,opcode,compiler);
  return allocation + 1;
}

/* IRMerge__ctor_109bf0 @ 0x109bf0 (92 bytes) */
int IRMerge__ctor_109bf0(this, compiler)
  undefined4 *this;
  undefined4 compiler;
{
  undefined *vtable;
  
  IRPseudo__ctor(this,0x83,compiler);
  vtable = PTR_DAT_001e8c1c;
  this[0x21] = 0;
  this[0x20] = 1;
  *this = vtable + 8;
  return;
}

/* IRMerge__ctor_109c4c @ 0x109c4c (92 bytes) */
int IRMerge__ctor_109c4c(this, compiler)
  undefined4 *this;
  undefined4 compiler;
{
  undefined *vtable;
  
  IRPseudo__ctor(this,0x83,compiler);
  vtable = PTR_DAT_001e8c1c;
  this[0x21] = 0;
  this[0x20] = 1;
  *this = vtable + 8;
  return;
}

/* IRMerge__ctor_109ca8 @ 0x109ca8 (84 bytes) */
int IRMerge__ctor_109ca8(this, kind, compiler)
  undefined4 *this;
  undefined4 kind;
  undefined4 compiler;
{
  undefined *vtable;
  
  IRPseudo__ctor(this,kind,compiler);
  vtable = PTR_DAT_001e8c1c;
  this[0x21] = 0;
  this[0x20] = 1;
  *this = vtable + 8;
  return;
}

/* IRMerge__ctor_109cfc @ 0x109cfc (84 bytes) */
int IRMerge__ctor_109cfc(this, kind, compiler)
  undefined4 *this;
  undefined4 kind;
  undefined4 compiler;
{
  undefined *vtable;
  
  IRPseudo__ctor(this,kind,compiler);
  vtable = PTR_DAT_001e8c1c;
  this[0x21] = 0;
  this[0x20] = 1;
  *this = vtable + 8;
  return;
}

/* IRLoadConst__vslot79 @ 0x109d50 (68 bytes) */
int IRLoadConst__vslot79(this, compiler)
  undefined4 this;
  int compiler;
{
  undefined4 *allocation;
  undefined4 arena;
  
  arena = *(undefined4 *)(compiler + COMP_arenaA);
  allocation = (undefined4 *)Arena__alloc(arena,0x168);
  *allocation = arena;
  ((int (*)())IRMerge__ctor_109cfc)(allocation + 1,this,compiler);
  return allocation + 1;
}

/* IRProjection__ctor_109dcc @ 0x109dcc (92 bytes) */
int IRProjection__ctor_109dcc(this, kind, compiler)
  undefined4 *this;
  undefined4 kind;
  undefined4 compiler;
{
  IRPseudo__ctor(this,kind,compiler);
  this[0x4c] = 0;
  *this = &PTR_FUN_001ea3b8;
  this[0x21] = 1;
  this[0x20] = 1;
  this[0x4b] = 0;
  return;
}

/* IRProjection__ctor_109e28 @ 0x109e28 (92 bytes) */
int IRProjection__ctor_109e28(this, kind, compiler)
  undefined4 *this;
  undefined4 kind;
  undefined4 compiler;
{
  IRPseudo__ctor(this,kind,compiler);
  this[0x4c] = 0;
  *this = &PTR_FUN_001ea3b8;
  this[0x21] = 1;
  this[0x20] = 1;
  this[0x4b] = 0;
  return;
}

/* IRLoadConst__vslot61 @ 0x109e84 (68 bytes) */
int IRLoadConst__vslot61(this, compiler)
  undefined4 this;
  int compiler;
{
  undefined4 *allocation;
  undefined4 arena;
  
  arena = *(undefined4 *)(compiler + COMP_arenaA);
  allocation = (undefined4 *)Arena__alloc(arena,0x168);
  *allocation = arena;
  ((int (*)())IRProjection__ctor_109e28)(allocation + 1,this,compiler);
  return allocation + 1;
}

/* IRPresub1__ctor_109f00 @ 0x109f00 (80 bytes) */
int IRPresub1__ctor_109f00(this, kind, compiler)
  undefined4 *this;
  undefined4 kind;
  undefined4 compiler;
{
  IRPseudo__ctor(this,kind,compiler);
  this[0x21] = 1;
  *this = &PTR_FUN_001ea268;
  this[0x20] = 1;
  return;
}

/* IRPresub1__ctor_109f50 @ 0x109f50 (80 bytes) */
int IRPresub1__ctor_109f50(this, kind, compiler)
  undefined4 *this;
  undefined4 kind;
  undefined4 compiler;
{
  IRPseudo__ctor(this,kind,compiler);
  this[0x21] = 1;
  *this = &PTR_FUN_001ea268;
  this[0x20] = 1;
  return;
}

/* IRLoadConst__vslot67 @ 0x109fa0 (68 bytes) */
int IRLoadConst__vslot67(this, compiler)
  undefined4 this;
  int compiler;
{
  undefined4 *allocation;
  undefined4 arena;
  
  arena = *(undefined4 *)(compiler + COMP_arenaA);
  allocation = (undefined4 *)Arena__alloc(arena,0x168);
  *allocation = arena;
  ((int (*)())IRPresub1__ctor_109f50)(allocation + 1,this,compiler);
  return allocation + 1;
}

/* IRPresub2__ctor_10a01c @ 0x10a01c (84 bytes) */
int IRPresub2__ctor_10a01c(this, kind, compiler)
  undefined4 *this;
  undefined4 kind;
  undefined4 compiler;
{
  IRPseudo__ctor(this,kind,compiler);
  this[0x21] = 2;
  *this = &PTR_FUN_001ea310;
  this[0x20] = 1;
  return;
}

/* IRPresub2__ctor_10a070 @ 0x10a070 (84 bytes) */
int IRPresub2__ctor_10a070(this, kind, compiler)
  undefined4 *this;
  undefined4 kind;
  undefined4 compiler;
{
  IRPseudo__ctor(this,kind,compiler);
  this[0x21] = 2;
  *this = &PTR_FUN_001ea310;
  this[0x20] = 1;
  return;
}

/* IRLoadConst__vslot69 @ 0x10a0c4 (68 bytes) */
int IRLoadConst__vslot69(this, compiler)
  undefined4 this;
  int compiler;
{
  undefined4 *allocation;
  undefined4 arena;
  
  arena = *(undefined4 *)(compiler + COMP_arenaA);
  allocation = (undefined4 *)Arena__alloc(arena,0x168);
  *allocation = arena;
  ((int (*)())IRPresub2__ctor_10a070)(allocation + 1,this,compiler);
  return allocation + 1;
}

/* IRMix__ctor_10a140 @ 0x10a140 (128 bytes) */
int IRMix__ctor_10a140(this, kind, compiler)
  undefined4 *this;
  undefined4 kind;
  undefined4 compiler;
{
  undefined4 laneDefaultWord;
  undefined4 defaultWord27;
  int remaining;
  
  IRPseudo__ctor(this,kind,compiler);
  defaultWord27 = DAT_001af9c8;
  this[0x20] = 1;
  laneDefaultWord = DAT_001af9c4;
  *this = &PTR_FUN_001ea070;
  remaining = 4;
  this[0x4b] = 0;
  this[0x27] = defaultWord27;
  this[0x21] = 0;
  do {
    this[0x2d] = laneDefaultWord;
    this = this + 6;
    remaining = remaining + -1;
  } while (remaining != 0);
  return;
}

/* IRMix__ctor_10a1c0 @ 0x10a1c0 (128 bytes) */
int IRMix__ctor_10a1c0(this, kind, compiler)
  undefined4 *this;
  undefined4 kind;
  undefined4 compiler;
{
  undefined4 laneDefaultWord;
  undefined4 defaultWord27;
  int remaining;
  
  IRPseudo__ctor(this,kind,compiler);
  defaultWord27 = DAT_001af9c8;
  this[0x20] = 1;
  laneDefaultWord = DAT_001af9c4;
  *this = &PTR_FUN_001ea070;
  remaining = 4;
  this[0x4b] = 0;
  this[0x27] = defaultWord27;
  this[0x21] = 0;
  do {
    this[0x2d] = laneDefaultWord;
    this = this + 6;
    remaining = remaining + -1;
  } while (remaining != 0);
  return;
}

/* IRLoadConst__vslot73 @ 0x10a240 (68 bytes) */
int IRLoadConst__vslot73(this, compiler)
  undefined4 this;
  int compiler;
{
  undefined4 *allocation;
  undefined4 arena;
  
  arena = *(undefined4 *)(compiler + COMP_arenaA);
  allocation = (undefined4 *)Arena__alloc(arena,0x168);
  *allocation = arena;
  ((int (*)())IRMix__ctor_10a1c0)(allocation + 1,this,compiler);
  return allocation + 1;
}

/* IRPhiNode__ctor_10a2bc @ 0x10a2bc (184 bytes) */
int IRPhiNode__ctor_10a2bc(this, compiler)
  undefined4 *this;
  int compiler;
{
  bool moreRows;
  int rowTable;
  undefined4 rowAlloc;
  int columnByteOffset;
  int rowByteOffset;
  int columnCountdown;
  
  IRPseudo__ctor(this,0x8e,compiler);
  this[0x20] = 1;
  *this = &PTR_FUN_001ea1c0;
  rowTable = Arena__alloc(*(undefined4 *)(compiler + COMP_arenaB),0x84);
  rowByteOffset = 0;
  do {
    rowAlloc = Arena__alloc(*(undefined4 *)(compiler + COMP_arenaB),0x10);
    *(undefined4 *)(rowByteOffset + rowTable) = rowAlloc;
    columnCountdown = 4;
    columnByteOffset = 0;
    do {
      *(undefined4 *)(columnByteOffset + *(int *)(rowByteOffset + rowTable)) = 1;
      columnByteOffset = columnByteOffset + 4;
      columnCountdown = columnCountdown + -1;
    } while (columnCountdown != 0);
    moreRows = rowByteOffset != 0x80;
    rowByteOffset = rowByteOffset + 4;
  } while (moreRows);
  this[0x4e] = rowTable;
  this[0x4d] = 0;
  return;
}

/* IRPhiNode__ctor_10a398 @ 0x10a398 (184 bytes) */
int IRPhiNode__ctor_10a398(this, compiler)
  undefined4 *this;
  int compiler;
{
  bool moreRows;
  int rowTable;
  undefined4 rowAlloc;
  int columnByteOffset;
  int rowByteOffset;
  int columnCountdown;
  
  IRPseudo__ctor(this,0x8e,compiler);
  this[0x20] = 1;
  *this = &PTR_FUN_001ea1c0;
  rowTable = Arena__alloc(*(undefined4 *)(compiler + COMP_arenaB),0x84);
  rowByteOffset = 0;
  do {
    rowAlloc = Arena__alloc(*(undefined4 *)(compiler + COMP_arenaB),0x10);
    *(undefined4 *)(rowByteOffset + rowTable) = rowAlloc;
    columnCountdown = 4;
    columnByteOffset = 0;
    do {
      *(undefined4 *)(columnByteOffset + *(int *)(rowByteOffset + rowTable)) = 1;
      columnByteOffset = columnByteOffset + 4;
      columnCountdown = columnCountdown + -1;
    } while (columnCountdown != 0);
    moreRows = rowByteOffset != 0x80;
    rowByteOffset = rowByteOffset + 4;
  } while (moreRows);
  this[0x4e] = rowTable;
  this[0x4d] = 0;
  return;
}

/* IRLoopStart__ctor_10a474 @ 0x10a474 (96 bytes) */
int IRLoopStart__ctor_10a474(this, unusedArg2, compiler)
  undefined4 *this;
  undefined4 unusedArg2;
  int compiler;
{
  undefined *vtable;
  
  IRPseudo__ctor(this,0x81,compiler);
  vtable = PTR_DAT_001e8c38;
  this[0x21] = 1;
  this[5] = this[5] | 0x18;
  *this = vtable + 8;
  this[0x20] = 1;
  return Program__addInst(*(undefined4 *)(compiler + COMP_currentProgram),this);
}

/* IRLoopStart__ctor_10a50c @ 0x10a50c (96 bytes) */
int IRLoopStart__ctor_10a50c(this, unusedArg2, compiler)
  undefined4 *this;
  undefined4 unusedArg2;
  int compiler;
{
  undefined *vtable;
  
  IRPseudo__ctor(this,0x81,compiler);
  vtable = PTR_DAT_001e8c38;
  this[0x21] = 1;
  this[5] = this[5] | 0x18;
  *this = vtable + 8;
  this[0x20] = 1;
  return Program__addInst(*(undefined4 *)(compiler + COMP_currentProgram),this);
}

/* IRLoadConst__vslot65 @ 0x10a5a4 (68 bytes) */
int IRLoadConst__vslot65(this, compiler)
  undefined4 this;
  int compiler;
{
  undefined4 *allocation;
  undefined4 arena;
  
  arena = *(undefined4 *)(compiler + COMP_arenaA);
  allocation = (undefined4 *)Arena__alloc(arena,0x168);
  *allocation = arena;
  ((int (*)())IRLoopStart__ctor_10a50c)(allocation + 1,this,compiler);
  return allocation + 1;
}

/* IRCmp1S__ctor_10a620 @ 0x10a620 (100 bytes) */
int IRCmp1S__ctor_10a620(this, unusedArg2, compiler)
  undefined4 *this;
  undefined4 unusedArg2;
  int compiler;
{
  undefined *vtable;
  
  IRPseudo__ctor(this,0x8d,compiler);
  vtable = PTR_DAT_001e8c40 + 8;
  this[0x20] = 0;
  *this = vtable;
  this[5] = this[5] | 0x18;
  this[0x21] = 1;
  return Program__addInst(*(undefined4 *)(compiler + COMP_currentProgram),this);
}

/* IRCmp1S__ctor_10a6bc @ 0x10a6bc (100 bytes) */
int IRCmp1S__ctor_10a6bc(this, unusedArg2, compiler)
  undefined4 *this;
  undefined4 unusedArg2;
  int compiler;
{
  undefined *vtable;
  
  IRPseudo__ctor(this,0x8d,compiler);
  vtable = PTR_DAT_001e8c40 + 8;
  this[0x20] = 0;
  *this = vtable;
  this[5] = this[5] | 0x18;
  this[0x21] = 1;
  return Program__addInst(*(undefined4 *)(compiler + COMP_currentProgram),this);
}

/* IRLoadConst__vslot57 @ 0x10a758 (68 bytes) */
int IRLoadConst__vslot57(this, compiler)
  undefined4 this;
  int compiler;
{
  undefined4 *allocation;
  undefined4 arena;
  
  arena = *(undefined4 *)(compiler + COMP_arenaA);
  allocation = (undefined4 *)Arena__alloc(arena,0x168);
  *allocation = arena;
  ((int (*)())IRCmp1S__ctor_10a6bc)(allocation + 1,this,compiler);
  return allocation + 1;
}

/* IRStartMakeCall__ctor_10a7d4 @ 0x10a7d4 (104 bytes) */
int IRStartMakeCall__ctor_10a7d4(this, ctorWord4b, ctorWord4c, compiler)
  undefined4 *this;
  undefined4 ctorWord4b;
  undefined4 ctorWord4c;
  undefined4 compiler;
{
  undefined *vtable;
  
  IRPseudo__ctor(this,0x90,compiler);
  vtable = PTR_DAT_001e8c18;
  this[0x4b] = ctorWord4b;
  this[5] = this[5] | 0x100;
  *this = vtable + 8;
  this[0x4c] = ctorWord4c;
  return;
}

/* IRStartMakeCall__ctor_10a83c @ 0x10a83c (104 bytes) */
int IRStartMakeCall__ctor_10a83c(this, ctorWord4b, ctorWord4c, compiler)
  undefined4 *this;
  undefined4 ctorWord4b;
  undefined4 ctorWord4c;
  undefined4 compiler;
{
  undefined *vtable;
  
  IRPseudo__ctor(this,0x90,compiler);
  vtable = PTR_DAT_001e8c18;
  this[0x4b] = ctorWord4b;
  this[5] = this[5] | 0x100;
  *this = vtable + 8;
  this[0x4c] = ctorWord4c;
  return;
}

/* IRStartCallRoutine__ctor_10a8a4 @ 0x10a8a4 (104 bytes) */
int IRStartCallRoutine__ctor_10a8a4(this, ctorWord4b, ctorWord4c, compiler)
  undefined4 *this;
  undefined4 ctorWord4b;
  undefined4 ctorWord4c;
  undefined4 compiler;
{
  undefined *vtable;
  
  IRPseudo__ctor(this,0x8f,compiler);
  vtable = PTR_DAT_001e8c4c;
  this[0x4b] = ctorWord4b;
  this[5] = this[5] | 0x100;
  *this = vtable + 8;
  this[0x4c] = ctorWord4c;
  return;
}

/* IRStartCallRoutine__ctor_10a90c @ 0x10a90c (104 bytes) */
int IRStartCallRoutine__ctor_10a90c(this, ctorWord4b, ctorWord4c, compiler)
  undefined4 *this;
  undefined4 ctorWord4b;
  undefined4 ctorWord4c;
  undefined4 compiler;
{
  undefined *vtable;
  
  IRPseudo__ctor(this,0x8f,compiler);
  vtable = PTR_DAT_001e8c4c;
  this[0x4b] = ctorWord4b;
  this[5] = this[5] | 0x100;
  *this = vtable + 8;
  this[0x4c] = ctorWord4c;
  return;
}

/* IREndMakeCall__ctor_10a974 @ 0x10a974 (88 bytes) */
int IREndMakeCall__ctor_10a974(this, compiler)
  undefined4 *this;
  undefined4 compiler;
{
  undefined *vtable;
  
  IRPseudo__ctor(this,0x92,compiler);
  vtable = PTR_DAT_001e8c00 + 8;
  this[5] = this[5] | 0x100;
  *this = vtable;
  return;
}

/* IREndMakeCall__ctor_10a9cc @ 0x10a9cc (88 bytes) */
int IREndMakeCall__ctor_10a9cc(this, compiler)
  undefined4 *this;
  undefined4 compiler;
{
  undefined *vtable;
  
  IRPseudo__ctor(this,0x92,compiler);
  vtable = PTR_DAT_001e8c00 + 8;
  this[5] = this[5] | 0x100;
  *this = vtable;
  return;
}

/* IREndCallRoutine__ctor_10aa24 @ 0x10aa24 (88 bytes) */
int IREndCallRoutine__ctor_10aa24(this, compiler)
  undefined4 *this;
  undefined4 compiler;
{
  undefined *vtable;
  
  IRPseudo__ctor(this,0x91,compiler);
  vtable = PTR_DAT_001e8be0 + 8;
  this[5] = this[5] | 0x100;
  *this = vtable;
  return;
}

/* IREndCallRoutine__ctor_10aa7c @ 0x10aa7c (88 bytes) */
int IREndCallRoutine__ctor_10aa7c(this, compiler)
  undefined4 *this;
  undefined4 compiler;
{
  undefined *vtable;
  
  IRPseudo__ctor(this,0x91,compiler);
  vtable = PTR_DAT_001e8be0 + 8;
  this[5] = this[5] | 0x100;
  *this = vtable;
  return;
}

/* outputScaleFromExponent @ 0x10aad4 (40 bytes) */
double outputScaleFromExponent(int exponent)
{
  return (double)*(float *)(&DAT_001af9ec + exponent * 4);
}

/* isOutputScaleValue @ 0x10aafc (68 bytes) */
undefined4 isOutputScaleValue(double scale)
{
  float *scaleTablePtr;
  int remaining;
  
  scaleTablePtr = (float *)&DAT_001af9e0;
  remaining = 7;
  do {
    if ((double)*scaleTablePtr == scale) {
      return 1;
    }
    scaleTablePtr = scaleTablePtr + 1;
    remaining = remaining + -1;
  } while (remaining != 0);
  return 0;
}

/* outputScaleExponent @ 0x10ab40 (76 bytes) */
int outputScaleExponent(double scale)
{
  float *scaleTablePtr;
  int tableIndex;
  int remaining;
  
  tableIndex = 0;
  scaleTablePtr = (float *)&DAT_001af9e0;
  remaining = 7;
  do {
    if ((double)*scaleTablePtr == scale) {
      return tableIndex + -3;
    }
    tableIndex = tableIndex + 1;
    scaleTablePtr = scaleTablePtr + 1;
    remaining = remaining + -1;
  } while (remaining != 0);
  return 0;
}

/* tryOutputScaleExponent @ 0x10ab8c (172 bytes) */
undefined4 tryOutputScaleExponent(undefined4 unusedArg1,undefined4 *outExponent,double scale)
{
  undefined4 exponent;
  
  exponent = 0xfffffffd;
  if ((((scale != (double)FLOAT_001aa170) &&
       (exponent = 0xfffffffe, scale != (double)FLOAT_001aa110)) &&
      (exponent = 0xffffffff, scale != (double)FLOAT_001aa10c)) &&
     (((exponent = 0, scale != (double)FLOAT_001aa0e8 &&
       (exponent = 1, scale != (double)FLOAT_001aa108)) &&
      (exponent = 2, scale != (double)FLOAT_001aa104)))) {
    if (scale != (double)FLOAT_001aa100) {
      return 0;
    }
    exponent = 3;
  }
  *outExponent = exponent;
  return 1;
}

/* IRInst__swapOperands @ 0x10ac38 (304 bytes) */
int IRInst__swapOperands(inst, operandA, operandB, compiler)
  int *inst;
  int operandA;
  int operandB;
  uint compiler;
{
  int recBFlags;
  int kindA;
  int recASelect;
  int kindB;
  int recAHeader;
  int vslotArgA;
  int vslotArgB;
  int extraout_r4;
  int recARegOffset;
  int recBRegOffset;
  int recAReg;
  int recBReg;
  int recASource;
  int recAFlags;
  int recBSource;
  
  vslotArgA = operandA;
  vslotArgB = operandB;
  if (0 < operandA) {
    (**(code **)(*inst + 0x14))(inst,operandA,operandB,compiler);
    vslotArgA = extraout_r4;
  }
  if (0 < operandB) {
    (**(code **)(*inst + 0x14))(inst,vslotArgA,vslotArgB,compiler);
  }
  recAHeader = inst[operandA * 6 + 0x23];
  recASource = inst[operandA * 6 + 0x24];
  recAReg = inst[operandA * 6 + 0x25];
  recARegOffset = inst[operandA * 6 + 0x26];
  recASelect = inst[operandA * 6 + 0x27];
  recAFlags = inst[operandA * 6 + 0x28];
  recBSource = inst[operandB * 6 + 0x24];
  recBReg = inst[operandB * 6 + 0x25];
  recBRegOffset = inst[operandB * 6 + 0x26];
  inst[operandA * 6 + 0x23] = inst[operandB * 6 + 0x23];
  inst[operandA * 6 + 0x24] = recBSource;
  inst[operandA * 6 + 0x25] = recBReg;
  inst[operandA * 6 + 0x26] = recBRegOffset;
  recBFlags = inst[operandB * 6 + 0x28];
  inst[operandA * 6 + 0x27] = inst[operandB * 6 + 0x27];
  inst[operandA * 6 + 0x28] = recBFlags;
  inst[operandB * 6 + 0x24] = recASource;
  inst[operandB * 6 + 0x25] = recAReg;
  inst[operandB * 6 + 0x26] = recARegOffset;
  inst[operandB * 6 + 0x23] = recAHeader;
  inst[operandB * 6 + 0x27] = recASelect;
  kindB = inst[operandB + 0x41];
  kindA = inst[operandA + 0x41];
  inst[operandB * 6 + 0x28] = recAFlags;
  inst[operandA + 0x41] = kindB;
  inst[operandB + 0x41] = kindA;
  return;
}

/* IRInst__newOpcode8c @ 0x10ad68 (76 bytes) */
int IRInst__newOpcode8c(operandWord2, compiler)
  undefined4 operandWord2;
  int compiler;
{
  undefined4 arena;
  undefined4 *allocation;
  int operandRecord;
  undefined4 defaultSwizzle;
  undefined4 *newInst;
  
  arena = *(undefined4 *)(compiler + COMP_arenaA);
  allocation = (undefined4 *)Arena__alloc(arena,0x168);
  newInst = allocation + 1;
  *allocation = arena;
  IRInst__ctor_10502c(newInst,0x8c,compiler);
  operandRecord = IRInst__getOperandRecord(newInst,1);
  *(undefined4 *)(operandRecord + 8) = operandWord2;
  *(undefined4 *)(operandRecord + 0xc) = 0;
  defaultSwizzle = UNK_001af9d4;
  operandRecord = IRInst__getOperandRecord(newInst,1);
  *(undefined4 *)(operandRecord + 0x10) = defaultSwizzle;
  allocation[0x4c] = 0;
  return newInst;
}

/* IRInst__replaceBodyKeepLinks @ 0x10ae20 (200 bytes) */
int IRInst__replaceBodyKeepLinks(inst, srcInst, program)
  int inst;
  int *srcInst;
  int program;
{
  int useEpoch;
  int useCount;
  undefined4 nextLink;
  undefined4 ownerBlock;
  undefined4 counterSnapshot;
  undefined4 counterSnapshotUseCount;
  undefined4 counterSnapshotInstId;
  
  counterSnapshot = 0;
  counterSnapshotUseCount = 0;
  counterSnapshotInstId = 0;
  IRInst__saveCounters(inst,&counterSnapshot,0xffffffff);
  nextLink = *(undefined4 *)(inst + 4);
  ownerBlock = *(undefined4 *)(inst + 0x158);
  useCount = IRInst__useCount(inst,program);
  DList__unlink(inst);
  IRInst__copyBodyFrom(inst,srcInst);
  IRInst__restoreCounters(inst,&counterSnapshot);
  useEpoch = *(int *)(program + 0x478);
  *(undefined4 *)(inst + 0x94) = *(undefined4 *)(inst + 0x14c);
  *(int *)(inst + 0x160) = useCount + useEpoch;
  *(undefined4 *)(inst + 0x98) = 0;
  Block__insertInstAfter(ownerBlock,nextLink,inst);
  return (**(code **)(*srcInst + 0xc))(srcInst,0,*(undefined4 *)(program + 8));
}

/* IRInst__scaleByOutputScale @ 0x10aee8 (80 bytes) */
int IRInst__scaleByOutputScale(outValue, inst, valueBits)
  float *outValue;
  int inst;
  unsigned int valueBits;
{
  float value = GH_U2F(valueBits);
  double outputScale;
  
  outputScale = (double)((double (*)())outputScaleFromExponent)(*(undefined4 *)(inst + 0x124));
  *outValue = (float)(outputScale * (double)value);
  return outValue;
}

/* IRInst__cloneIfPresub @ 0x10af38 (200 bytes) */
int IRInst__cloneIfPresub(inst, program, trackUses)
  int *inst;
  int program;
  int trackUses;
{
  undefined4 *allocation;
  int operandIndex2;
  int operandIndex;
  int operandRecord;
  int needsClone;
  int *result;
  undefined4 *vectorAlloc;
  uint userCount;
  int sourceInst;
  undefined4 arena;
  uint *userVector;
  
  needsClone = (**(code **)(*inst + 0x5c))(inst,program,trackUses);
  result = inst;
  if (needsClone != 0) {
    result = (int *)IRInst__clone(inst,*(undefined4 *)(program + 8),0);
    sourceInst = result[0x53];
    operandRecord = IRInst__getOperandRecord(result,0);
    *(int *)(operandRecord + 8) = sourceInst;
    Block__insertInstBefore(inst[0x56],inst,result);
    result[0x58] = *(int *)(program + 0x478);
    if (trackUses != 0) {
      arena = *(undefined4 *)(*(int *)(program + 8) + 0x378);
      allocation = (undefined4 *)Arena__alloc(arena,0x14);
      allocation[1] = 2;
      *allocation = arena;
      allocation[2] = 0;
      allocation[4] = arena;
      arena = Arena__alloc(arena,8);
      allocation[3] = arena;
      result[4] = (int)(allocation + 1);
      for (operandIndex = 1; sourceInst = (**(code **)(*result + 0x14))(result), operandIndex <= sourceInst;
          operandIndex = operandIndex + 1) {
        sourceInst = IRInst__getOperandSource(result,operandIndex);
        userVector = *(uint **)(sourceInst + 0x10);
        userCount = userVector[1];
        if (userCount < *userVector) {
          _memset(userCount * 4 + userVector[2],0,4);
          vectorAlloc = (undefined4 *)(userCount * 4 + userVector[2]);
          userVector[1] = userCount + 1;
        }
        else {
          vectorAlloc = (undefined4 *)Vector__elementRefGrow(userVector,userCount);
        }
        *vectorAlloc = result;
      }
    }
    for (operandIndex2 = 1; sourceInst = (**(code **)(*result + 0x14))(result), operandIndex2 <= sourceInst; operandIndex2 = operandIndex2 + 1
        ) {
      sourceInst = IRInst__getOperandSource(result,operandIndex2);
      if (*(int *)(program + 0x478) < *(int *)(sourceInst + 0x160)) {
        *(int *)(sourceInst + 0x160) = *(int *)(sourceInst + 0x160) + 1;
      }
      else {
        *(int *)(sourceInst + 0x160) = *(int *)(program + 0x478) + 1;
      }
    }
  }
  return result;
}

/* IRInst__clampOutputValue @ 0x10b118 (108 bytes) */
int IRInst__clampOutputValue(outValue, inst, valueBits)
  float *outValue;
  int inst;
  unsigned int valueBits;
{
  float value = GH_U2F(valueBits);
  float result;
  
  result = value;
  if ((*(int *)(inst + 0x120) != 0) && (result = FLOAT_001aa0e8, value <= FLOAT_001aa0e8)) {
    result = value;
    if (value < 0.0) {
      result = FLOAT_001aa0d4;
    }
    if (-value < 0.0) {
      result = value;
    }
  }
  *outValue = result;
  return;
}

/* IRInst__findConstantOperandWithValue @ 0x10b184 (256 bytes) */
int IRInst__findConstantOperandWithValue(int *inst,undefined4 vslot60Arg2,int *outChannel,double value)
{
  bool lastChannel;
  uint selectByte;
  int scratch;
  int operandRecord;
  undefined4 vslot60Arg4;
  undefined4 vslot60Arg5;
  int channel;
  int operandIndex;
  
  channel = 0;
  (**(code **)(*inst + 0x60))(inst,vslot60Arg2,outChannel,vslot60Arg4,vslot60Arg5);
  do {
    scratch = IRInst__getOperandRecord(inst,0);
    operandIndex = 1;
    if (*(char *)(channel + scratch + 0x10) != '\x01') {
      for (; scratch = (**(code **)(*inst + 0x14))(inst), operandIndex <= scratch; operandIndex = operandIndex + 1) {
        scratch = IRInst__getOperandSource(inst,operandIndex);
        if (*(int *)(scratch + 0x98) == 0x33) {
          operandRecord = IRInst__getOperandRecord(inst,operandIndex);
          selectByte = (uint)*(byte *)(channel + operandRecord + 0x10);
          if ((selectByte != 4) && ((double)*(float *)(selectByte * 0x18 + scratch + 0x20) == value)) {
            *outChannel = channel;
            return operandIndex;
          }
        }
      }
    }
    lastChannel = channel == 3;
    channel = channel + 1;
    if (lastChannel) {
      return 0;
    }
  } while( true );
}

/* IRInst__applyNegateModifier @ 0x10b284 (88 bytes) */
int IRInst__applyNegateModifier(outValue, inst, operandIndex, valueBits)
  float *outValue;
  int inst;
  int operandIndex;
  unsigned int valueBits;
{
  float value = GH_U2F(valueBits);
  float result;
  
  result = value;
  if ((*(uint *)(operandIndex * 0x18 + inst + 0xa0) & 1) != 0) {
    result = FLOAT_001aa0d4;
    if (value != FLOAT_001aa0d4) {
      result = -value;
    }
  }
  *outValue = result;
  return;
}

/* IRInst__applyAbsModifier @ 0x10b2dc (80 bytes) */
int IRInst__applyAbsModifier(outValue, inst, operandIndex, valueBits)
  float *outValue;
  int inst;
  int operandIndex;
  unsigned int valueBits;
{
  float value = GH_U2F(valueBits);
  if ((*(uint *)(operandIndex * 0x18 + inst + 0xa0) & 2) != 0) {
    if (value < FLOAT_001aa0d4) {
      value = -value;
    }
  }
  *outValue = value;
  return;
}

/* IRInst__createCompareConstInst @ 0x10b32c (100 bytes) */
int IRInst__createCompareConstInst(undefined4 compareKind,undefined4 operandWord2,undefined4 operandWord3,undefined4 unusedArg4,int compiler,double value)
{
  undefined4 defaultSelect;
  undefined4 literalLaneCount;
  bool swapOperands;
  undefined4 opcode;
  int inst;
  int operandRecord;
  undefined4 currentProgram;
  int nextTempId;
  
  switch(compareKind) {
  case 0:
    opcode = 0x2a;
    swapOperands = false;
    break;
  case 1:
    opcode = 0x27;
    swapOperands = false;
    break;
  case 2:
    opcode = 0x29;
    swapOperands = true;
    break;
  case 3:
    opcode = 0x28;
    swapOperands = true;
    break;
  case 4:
    opcode = 0x29;
    swapOperands = false;
    break;
  case 5:
    opcode = 0x28;
    swapOperands = false;
    break;
  default:
    opcode = 0;
    swapOperands = false;
  }
  currentProgram = *(undefined4 *)(compiler + 0x6c4);
  inst = IRInst__create(opcode,compiler);
  operandRecord = IRInst__getOperandRecord(inst,2 - (uint)!swapOperands);
  *(undefined4 *)(operandRecord + 0xc) = operandWord3;
  *(undefined4 *)(operandRecord + 8) = operandWord2;
  if (!swapOperands) {
    literalLaneCount = 2;
  }
  else {
    literalLaneCount = 1;
  }
  ((void (*)())IRInst__makeLiteralVec4Float)(inst,currentProgram,literalLaneCount,value,value,value,value);
  nextTempId = *(int *)(compiler + 0x3ac) + -1;
  *(int *)(compiler + 0x3ac) = nextTempId;
  operandRecord = IRInst__getOperandRecord(inst,0);
  defaultSelect = _UNK_001af9d8;
  *(undefined4 *)(operandRecord + 0xc) = 0;
  *(int *)(operandRecord + 8) = nextTempId;
  *(undefined4 *)(inst + 0x9c) = defaultSelect;
  return inst;
}

/* IRInst__isOperandConstZero @ 0x10b498 (352 bytes) */
int IRInst__isOperandConstZero(inst, operandIndex)
  undefined4 inst;
  undefined4 operandIndex;
{
  int operandRecord2;
  bool lastLane;
  float zero;
  int isConstant;
  int *operandVReg;
  int lane;
  uint componentSel;
  
  zero = FLOAT_001aa0d4;
  lane = 0;
  do {
    operandRecord2 = IRInst__getOperandRecord(inst,0);
    if (*(char *)(lane + operandRecord2 + 0x10) != '\x01') {
      operandRecord2 = IRInst__getOperandRecord(inst,operandIndex);
      componentSel = (uint)*(byte *)(lane + operandRecord2 + 0x10);
      operandVReg = (int *)IRInst__getOperandSource(inst,operandIndex);
      while (operandRecord2 = (**(code **)(*operandVReg + 100))(operandVReg), operandRecord2 != 0) {
        operandRecord2 = IRInst__getOperandRecord(operandVReg,0);
        if (*(char *)(componentSel + operandRecord2 + 0x10) == '\0') {
          operandRecord2 = IRInst__getOperandRecord(operandVReg,1);
          componentSel = (uint)*(byte *)(componentSel + operandRecord2 + 0x10);
          operandVReg = (int *)IRInst__getOperandSource(operandVReg,1);
        }
        else {
          operandVReg = (int *)IRInst__getOperandSource(operandVReg,operandVReg[0x21]);
        }
      }
      isConstant = (**(code **)(*operandVReg + 0x48))(operandVReg);
      if (((isConstant == 0) || (((int)*(char *)(operandVReg + 0x57) >> (componentSel & 0x3f) & 1U) == 0)) ||
         (GH_U2F((unsigned int)(operandVReg[componentSel * 6 + 8])) != zero)) {
        return 0;
      }
    }
    lastLane = lane == 3;
    lane = lane + 1;
    if (lastLane) {
      return 1;
    }
  } while( true );
}

/* IRInst__getCompareCondition @ 0x10b5f8 (112 bytes) */
int IRInst__getCompareCondition(inst)
  int inst;
{
  switch(*(undefined4 *)(*(int *)(inst + 0x88) + 8)) {
  case 0x20:
  case 0x24:
  case 0x27:
    return 0;
  case 0x21:
  case 0x26:
  case 0x28:
    return 2;
  case 0x22:
  case 0x25:
  case 0x29:
    return 3;
  case 0x23:
  case 0x2a:
    return 1;
  default:
    return 8;
  case 0x8b:
  case 0x8c:
  case 0x8d:
    return *(undefined4 *)(inst + 300);
  }
}

/* evaluateCompareFloats @ 0x10b820 (220 bytes) */
bool evaluateCompareFloats(undefined4 inst,double lhs,double rhs)
{
  undefined4 compareCondition;
  bool result;
  
  compareCondition = ((int (*)())IRInst__getCompareCondition)(inst);
  result = false;
  switch(compareCondition) {
  case 0:
    result = lhs == rhs;
    break;
  case 1:
    result = lhs != rhs;
    break;
  case 2:
    result = rhs < lhs;
    break;
  case 3:
    result = rhs <= lhs;
    break;
  case 4:
    result = lhs < rhs;
    break;
  case 5:
    result = lhs <= rhs;
  }
  return result;
}

/* IRInst__setCompareCondition @ 0x10b914 (40 bytes) */
int IRInst__setCompareCondition(inst, condition)
  int inst;
  undefined4 condition;
{
  int opcode;
  
  opcode = *(int *)(*(int *)(inst + 0x88) + 8);
  if (((opcode != 0x8c) && (opcode != 0x8d)) && (opcode != 0x8b)) {
    return;
  }
  *(undefined4 *)(inst + 300) = condition;
  return;
}

/* IRInst__foldCompareConstResult @ 0x10b93c (344 bytes) */
int IRInst__foldCompareConstResult(outValue, inst, operandSlot, valueBits, compiler)
  float *outValue;
  int inst;
  int operandSlot;
  unsigned int valueBits;
  int compiler;
{
  float value = GH_U2F(valueBits);
  uint instFlags;
  float selectedValue;
  double foldedValue;
  
  foldedValue = (double)value;
  (**(code **)(**(int **)(compiler + 0x30c) + 0xf0))(foldedValue,*(int **)(compiler + 0x30c));
  switch(*(undefined4 *)(*(int *)(inst + 0x88) + 8)) {
  case 0x12:
    break;
  case 0x13:
    if (operandSlot != 1) {
      foldedValue = (double)FLOAT_001aa0e8;
    }
    goto LAB_0010badc;
  case 0x14:
    if (operandSlot == 2) {
      if ((*(uint *)(inst + 0xe8) & 1) == 0) {
        selectedValue = 0.0;
      }
      else {
        selectedValue = 1.0;
      }
      goto LAB_0010baf4;
    }
    if (operandSlot == 3) {
      instFlags = *(uint *)(inst + 0xe8);
      goto joined_r0x0010bad0;
    }
    if (operandSlot == 1) {
      instFlags = *(uint *)(inst + 0xe8);
      goto joined_r0x0010baa4;
    }
  default:
    selectedValue = GH_U2F(0x7ffffffdU);
LAB_0010baf4:
    *outValue = selectedValue;
    return outValue;
  case 0x16:
  case 0x17:
  case 0x19:
  case 0x31:
    *outValue = value;
    return outValue;
  }
  if (operandSlot == 1) {
    instFlags = *(uint *)(inst + 0xb8);
joined_r0x0010bad0:
    if ((instFlags & 1) == 0) goto LAB_0010badc;
  }
  else {
    instFlags = *(uint *)(inst + 0xb8);
joined_r0x0010baa4:
    if ((instFlags & 1) != 0) goto LAB_0010badc;
  }
  foldedValue = (double)FLOAT_001aa0d4;
LAB_0010badc:
  *outValue = (float)foldedValue;
  return outValue;
}

/* IRInst__compareResultIsConstant @ 0x10bb14 (136 bytes) */
int IRInst__compareResultIsConstant(inst)
  int inst;
{
  int opcode;
  
  opcode = *(int *)(*(int *)(inst + 0x88) + 8);
  if (opcode == 0x13) {
    if ((*(uint *)(inst + 0xb8) & 1) == (*(uint *)(inst + 0xd0) & 1)) {
      return 1;
    }
  }
  else if (opcode == 0x14) {
    if ((*(uint *)(inst + 0xb8) & 1) == (*(uint *)(inst + 0xd0) & 1)) {
      return 1;
    }
    if ((*(uint *)(inst + 0xe8) & 1) != 0) {
      return 1;
    }
  }
  else if ((opcode == 0x12) &&
          (((*(uint *)(inst + 0xb8) & 1) == 0 || ((*(uint *)(inst + 0xd0) & 1) == 0)))) {
    return 1;
  }
  return 0;
}

/* IRInst__retargetOpcode @ 0x10bb9c (220 bytes) */
int IRInst__retargetOpcode(inst, select0, select1, select2, invert, compiler)
  int *inst;
  int select0;
  int select1;
  int select2;
  int invert;
  undefined4 compiler;
{
  undefined *selectTable;
  int operandCount;
  undefined4 field4;
  int opcodeInfo;
  
  operandCount = (**(code **)(*inst + 0x14))(inst,select0,select1,select2,invert,compiler);
  field4 = OpcodeTraits__getField4(*(undefined4 *)(inst[0x22] + 8),compiler);
  opcodeInfo = Opcode__getInfo(field4);
  inst[0x22] = opcodeInfo;
  if (invert != 0) {
    opcodeInfo = Opcode__getInfo(0x35);
    inst[0x22] = opcodeInfo;
    IROperand__setModifierBits(inst + 0x2f,1,inst[0x34] & 1U ^ 1);
  }
  selectTable = PTR_DAT_001e8b8c;
  inst[0x2d] = *(int *)(PTR_DAT_001e8b8c + select0 * 4);
  if (1 < operandCount) {
    inst[0x33] = *(int *)(selectTable + select1 * 4);
  }
  if (2 < operandCount) {
    inst[0x39] = *(int *)(selectTable + select2 * 4);
  }
  return;
}

/* IRInst__retargetOpcodeFromOperands @ 0x10bc78 (216 bytes) */
int IRInst__retargetOpcodeFromOperands(inst, compiler)
  int *inst;
  undefined4 compiler;
{
  int opcodeInfo;
  int oldOpcode;
  undefined4 field4;
  int operandCount;
  int operandWord0;
  int operandWord1;
  int operandWord2 [4];
  
  oldOpcode = *(int *)(inst[0x22] + 8);
  field4 = OpcodeTraits__getField4(oldOpcode,compiler);
  opcodeInfo = Opcode__getInfo(field4);
  inst[0x22] = opcodeInfo;
  operandCount = (**(code **)(*inst + 0x14))(inst);
  SelectWord__fillUnusedWithFirstUsed(&operandWord0,inst[0x2d]);
  inst[0x2d] = operandWord0;
  if (1 < operandCount) {
    SelectWord__fillUnusedWithFirstUsed(&operandWord1,inst[0x33]);
    inst[0x33] = operandWord1;
  }
  if (2 < operandCount) {
    SelectWord__fillUnusedWithFirstUsed(operandWord2,inst[0x39]);
    inst[0x39] = operandWord2[0];
  }
  if (oldOpcode == 0x35) {
    IROperand__setModifierBits(inst + 0x2f,1,inst[0x34] & 1U ^ 1);
  }
  return oldOpcode == 0x35;
}

/* IRInst__setLiteralOperandAndSource @ 0x10bd50 (332 bytes) */
void IRInst__setLiteralOperandAndSource(int inst,undefined4 unusedArg2,int operandIndex,int compiler,double value)
{
  int operandRecord;
  int *elementRef;
  undefined4 *allocation;
  int vreg;
  undefined4 arena;
  int defInst;
  undefined4 *valueKey;
  
  *(int *)(inst + 0x84) = operandIndex;
  ((void (*)())IRInst__makeLiteralVec4Float)(inst,*(undefined4 *)(compiler + 0x6c4),operandIndex,value,value,value,value)
  ;
  arena = DAT_001af9fc;
  if (operandIndex == 0) {
    *(undefined4 *)(inst + 0x9c) = DAT_001af9fc;
  }
  else {
    operandRecord = IRInst__getOperandRecord(inst,operandIndex);
    *(undefined4 *)(operandRecord + 0x10) = arena;
  }
  if ((*(uint *)(*(int *)(compiler + 0x6c4) + 0x30) & 8) == 0) {
    vreg = *(int *)(operandIndex * 0x18 + inst + 0x8c);
    elementRef = *(int **)(vreg + 0x18);
    if (*elementRef == 0) {
      elementRef = (int *)Vector__elementRefGrow(elementRef,0);
    }
    else {
      if (elementRef[1] == 0) {
        *(undefined4 *)elementRef[2] = 0;
        elementRef[1] = 1;
      }
      elementRef = (int *)elementRef[2];
    }
    defInst = *elementRef;
    if (*(int *)(*(int *)(vreg + 0x2c) + 4) == 0) {
      arena = *(undefined4 *)(compiler + 0x378);
      allocation = (undefined4 *)Arena__alloc(arena,0x240);
      valueKey = allocation + 1;
      *allocation = arena;
      ValueKey__init(valueKey,defInst,compiler);
      ValueKey__fill(valueKey);
      FUN_00174e0c(valueKey);
      ValueKey__propagateLaneValues(valueKey);
      VReg__pushDefinition(vreg,*(undefined4 *)(*(int *)(defInst + 0x158) + 0xb0),valueKey);
    }
    IRInst__setOperandSource(inst,operandIndex,defInst,0,compiler);
    return;
  }
  return;
}


/* issue: auto-generated aliases bridging data.s/code.s references (written
 * without a leading underscore, matching the raw stock-binary symbol name)
 * against the real compiled C symbols (gcc adds one underscore automatically).
 * Needed because ld64 (required for this PPC binary's size - stock ld breaks on
 * large PPC links) does not silently reconcile this the way stock ld did. */
asm(".globl IRLoadConst__vslot79");
asm(".set IRLoadConst__vslot79, _IRLoadConst__vslot79");
asm(".globl IRLoadConst__vslot61");
asm(".set IRLoadConst__vslot61, _IRLoadConst__vslot61");
asm(".globl IRLoadConst__vslot67");
asm(".set IRLoadConst__vslot67, _IRLoadConst__vslot67");
asm(".globl IRLoadConst__vslot69");
asm(".set IRLoadConst__vslot69, _IRLoadConst__vslot69");
asm(".globl IRLoadConst__vslot73");
asm(".set IRLoadConst__vslot73, _IRLoadConst__vslot73");
asm(".globl IRLoadConst__vslot65");
asm(".set IRLoadConst__vslot65, _IRLoadConst__vslot65");
asm(".globl IRLoadConst__vslot57");
asm(".set IRLoadConst__vslot57, _IRLoadConst__vslot57");
