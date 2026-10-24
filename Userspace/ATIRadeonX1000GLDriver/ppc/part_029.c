#include "decls.h"

/* FUN_00107df4 @ 0x107df4 (68 bytes) */
int FUN_00107df4(param_1, compiler)
  undefined4 param_1;
  int compiler;
{
  undefined4 *allocation;
  undefined4 arena;
  
  arena = *(undefined4 *)(compiler + COMP_arenaA);
  allocation = (undefined4 *)Arena__alloc(arena,0x168);
  *allocation = arena;
  IRInst__reinitAsUnary(allocation + 1,param_1,compiler);
  return allocation + 1;
}

/* IRLoadConst__vslot43 @ 0x107e70 (68 bytes) */
int IRLoadConst__vslot43(this, compiler)
  undefined4 this;
  int compiler;
{
  undefined4 *allocation;
  undefined4 arena;
  
  arena = *(undefined4 *)(compiler + COMP_arenaA);
  allocation = (undefined4 *)Arena__alloc(arena,0x168);
  *allocation = arena;
  IRInst__reinitAsUnary(allocation + 1,this,compiler);
  return allocation + 1;
}

/* FUN_00107eec @ 0x107eec (76 bytes) */
int FUN_00107eec(inst, param_2, compiler)
  undefined4 *inst;
  undefined4 param_2;
  undefined4 compiler;
{
  undefined *puVar1;
  
  IRAlu__ctor_1071a8(inst,param_2,compiler);
  puVar1 = PTR_DAT_001e8bec;
  inst[0x21] = 2;
  *inst = puVar1 + 8;
  return;
}

/* FUN_00107f38 @ 0x107f38 (96 bytes) */
int FUN_00107f38(this, param_2, param_3)
  undefined4 *this;
  undefined4 param_2;
  int param_3;
{
  undefined *puVar1;
  
  ((int (*)())FUN_00107eec)(this,param_2,param_3);
  puVar1 = PTR_DAT_001e8c30 + 8;
  this[0x20] = 1;
  *this = puVar1;
  this[5] = this[5] | 0x18;
  this[0x4b] = 0;
  return Program__addInst(*(undefined4 *)(param_3 + 0x6c4),this);
}

/* FUN_00107fd0 @ 0x107fd0 (92 bytes) */
int FUN_00107fd0(param_1, param_2, compiler)
  undefined4 *param_1;
  undefined4 param_2;
  int compiler;
{
  undefined *puVar1;
  
  ((int (*)())FUN_00107eec)(param_1,0x8b,compiler);
  puVar1 = PTR_DAT_001e8be4;
  param_1[0x20] = 0;
  param_1[5] = param_1[5] | 0x18;
  *param_1 = puVar1 + 8;
  return Program__addInst(*(undefined4 *)(compiler + COMP_currentProgram),param_1);
}

/* IRLoadConst__vslot55 @ 0x108064 (68 bytes) */
int IRLoadConst__vslot55(this, compiler)
  undefined4 this;
  int compiler;
{
  undefined4 *allocation;
  undefined4 arena;
  
  arena = *(undefined4 *)(compiler + COMP_arenaA);
  allocation = (undefined4 *)Arena__alloc(arena,0x168);
  *allocation = arena;
  ((int (*)())FUN_00107fd0)(allocation + 1,this,compiler);
  return allocation + 1;
}

/* FUN_001080e0 @ 0x1080e0 (92 bytes) */
int FUN_001080e0(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  int param_3;
{
  undefined *puVar1;
  
  ((int (*)())FUN_00107eec)(param_1,0x8b,param_3);
  puVar1 = PTR_DAT_001e8be4;
  param_1[0x20] = 0;
  param_1[5] = param_1[5] | 0x18;
  *param_1 = puVar1 + 8;
  return Program__addInst(*(undefined4 *)(param_3 + 0x6c4),param_1);
}

/* IRInst__reinitAsBinary @ 0x108174 (76 bytes) */
int IRInst__reinitAsBinary(inst, param_2, compiler)
  undefined4 *inst;
  undefined4 param_2;
  undefined4 compiler;
{
  undefined *puVar1;
  
  IRAlu__ctor_1071a8(inst,param_2,compiler);
  puVar1 = PTR_DAT_001e8bec;
  inst[0x21] = 2;
  *inst = puVar1 + 8;
  return;
}

/* FUN_001081c0 @ 0x1081c0 (68 bytes) */
int FUN_001081c0(param_1, compiler)
  undefined4 param_1;
  int compiler;
{
  undefined4 *allocation;
  undefined4 arena;
  
  arena = *(undefined4 *)(compiler + COMP_arenaA);
  allocation = (undefined4 *)Arena__alloc(arena,0x168);
  *allocation = arena;
  ((int (*)())IRInst__reinitAsBinary)(allocation + 1,param_1,compiler);
  return allocation + 1;
}

/* IRLoadConst__vslot47 @ 0x10823c (68 bytes) */
int IRLoadConst__vslot47(this, compiler)
  undefined4 this;
  int compiler;
{
  undefined4 *allocation;
  undefined4 arena;
  
  arena = *(undefined4 *)(compiler + COMP_arenaA);
  allocation = (undefined4 *)Arena__alloc(arena,0x168);
  *allocation = arena;
  ((int (*)())IRInst__reinitAsBinary)(allocation + 1,this,compiler);
  return allocation + 1;
}

/* FUN_001082b8 @ 0x1082b8 (76 bytes) */
int FUN_001082b8(inst, param_2, compiler)
  undefined4 *inst;
  undefined4 param_2;
  undefined4 compiler;
{
  undefined *puVar1;
  
  IRAlu__ctor_1071a8(inst,param_2,compiler);
  puVar1 = PTR_DAT_001e8c24;
  inst[0x21] = 3;
  *inst = puVar1 + 8;
  return;
}

/* IRInst__reinitAsTrinary @ 0x108304 (76 bytes) */
int IRInst__reinitAsTrinary(inst, param_2, compiler)
  undefined4 *inst;
  undefined4 param_2;
  undefined4 compiler;
{
  undefined *puVar1;
  
  IRAlu__ctor_1071a8(inst,param_2,compiler);
  puVar1 = PTR_DAT_001e8c24;
  inst[0x21] = 3;
  *inst = puVar1 + 8;
  return;
}

/* FUN_00108350 @ 0x108350 (68 bytes) */
int FUN_00108350(param_1, compiler)
  undefined4 param_1;
  int compiler;
{
  undefined4 *allocation;
  undefined4 arena;
  
  arena = *(undefined4 *)(compiler + COMP_arenaA);
  allocation = (undefined4 *)Arena__alloc(arena,0x168);
  *allocation = arena;
  ((int (*)())IRInst__reinitAsTrinary)(allocation + 1,param_1,compiler);
  return allocation + 1;
}

/* IRLoadConst__vslot49 @ 0x1083cc (68 bytes) */
int IRLoadConst__vslot49(this, compiler)
  undefined4 this;
  int compiler;
{
  undefined4 *allocation;
  undefined4 arena;
  
  arena = *(undefined4 *)(compiler + COMP_arenaA);
  allocation = (undefined4 *)Arena__alloc(arena,0x168);
  *allocation = arena;
  ((int (*)())IRInst__reinitAsTrinary)(allocation + 1,this,compiler);
  return allocation + 1;
}

/* IRInst__reinitAsMov @ 0x108448 (112 bytes) */
int IRInst__reinitAsMov(param_1, param_2, compiler)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 compiler;
{
  bool bVar1;
  undefined *puVar2;
  int iVar3;
  
  IRUnary__ctor_107cec(param_1,param_2,compiler);
  puVar2 = PTR_DAT_001e8bf0;
  param_1[0x20] = 1;
  *param_1 = puVar2 + 8;
  iVar3 = 0;
  do {
    bVar1 = iVar3 != 1;
    param_1[0x25] = 0xffffffff;
    param_1[0x26] = 0;
    iVar3 = iVar3 + 1;
    param_1 = param_1 + 6;
  } while (bVar1);
  return;
}

/* FUN_001084b8 @ 0x1084b8 (68 bytes) */
int FUN_001084b8(param_1, compiler)
  undefined4 param_1;
  int compiler;
{
  undefined4 *allocation;
  undefined4 arena;
  
  arena = *(undefined4 *)(compiler + COMP_arenaA);
  allocation = (undefined4 *)Arena__alloc(arena,0x168);
  *allocation = arena;
  ((int (*)())IRInst__reinitAsMov)(allocation + 1,param_1,compiler);
  return allocation + 1;
}

/* IRLoadConst__vslot45 @ 0x108534 (68 bytes) */
int IRLoadConst__vslot45(this, compiler)
  undefined4 this;
  int compiler;
{
  undefined4 *allocation;
  undefined4 arena;
  
  arena = *(undefined4 *)(compiler + COMP_arenaA);
  allocation = (undefined4 *)Arena__alloc(arena,0x168);
  *allocation = arena;
  ((int (*)())IRInst__reinitAsMov)(allocation + 1,this,compiler);
  return allocation + 1;
}

/* IRExport__ctor_1085b0 @ 0x1085b0 (276 bytes) */
int IRExport__ctor_1085b0(this, compiler)
  undefined4 *this;
  int compiler;
{
  undefined4 uVar1;
  undefined4 opcodeInfo;
  
  IRAlu__ctor_1071a8(this,0x30,compiler);
  this[5] = this[5] | 0x12;
  *this = &PTR_FUN_001ea118;
  if ((*(uint *)(*(int *)(compiler + COMP_currentProgram) + 0x30) & 0x4000) == 0) {
    Program__addInst(*(int *)(compiler + COMP_currentProgram),this);
  }
  uVar1 = (**(code **)(**(int **)(compiler + COMP_target) + 0x178))(*(int **)(compiler + COMP_target),compiler);
  opcodeInfo = Opcode__getInfo(uVar1);
  uVar1 = DAT_001af9c8;
  this[0x21] = 1;
  this[0x4f] = 0x32;
  this[0x27] = uVar1;
  this[0x22] = opcodeInfo;
  this[0x20] = 0;
  this[0x50] = 0;
  IRLoadInterp__setLaneKindAndIndex(this,0,5,0);
  IRLoadInterp__setLaneKindAndIndex(this,1,5,0);
  IRLoadInterp__setLaneKindAndIndex(this,2,5,0);
  IRLoadInterp__setLaneKindAndIndex(this,3,5,0);
  this[0x51] = 0;
  return;
}

/* FUN_001086e8 @ 0x1086e8 (100 bytes) */
int FUN_001086e8(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined *puVar1;
  undefined4 opcodeInfo;
  
  ((int (*)())IRExport__ctor_1085b0)(param_1,param_3);
  puVar1 = PTR_DAT_001e8bfc;
  param_1[0x21] = 1;
  param_1[0x20] = 1;
  *param_1 = puVar1 + 8;
  opcodeInfo = Opcode__getInfo(param_2);
  param_1[0x22] = opcodeInfo;
  return;
}

/* FUN_00108770 @ 0x108770 (92 bytes) */
int FUN_00108770(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  undefined *puVar1;
  undefined4 opcodeInfo;
  
  ((int (*)())IRExport__ctor_1085b0)(param_1,param_2);
  puVar1 = PTR_DAT_001e8bfc;
  param_1[0x21] = 1;
  param_1[0x20] = 1;
  *param_1 = puVar1 + 8;
  opcodeInfo = Opcode__getInfo(0xf9);
  param_1[0x22] = opcodeInfo;
  return;
}

/* FUN_001087f0 @ 0x1087f0 (92 bytes) */
int FUN_001087f0(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  undefined *puVar1;
  undefined4 opcodeInfo;
  
  ((int (*)())IRExport__ctor_1085b0)(param_1,param_2);
  puVar1 = PTR_DAT_001e8bfc;
  param_1[0x21] = 1;
  param_1[0x20] = 1;
  *param_1 = puVar1 + 8;
  opcodeInfo = Opcode__getInfo(0xf9);
  param_1[0x22] = opcodeInfo;
  return;
}

/* IRExportColorAndFog__ctor_108870 @ 0x108870 (84 bytes) */
int IRExportColorAndFog__ctor_108870(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  undefined *puVar1;
  
  ((int (*)())IRExport__ctor_1085b0)(param_1,param_2);
  puVar1 = PTR_DAT_001e8c28;
  param_1[0x21] = 2;
  param_1[0x26] = 0x16;
  *param_1 = puVar1 + 8;
  return;
}

/* IRExportColorAndFog__ctor_1088c4 @ 0x1088c4 (84 bytes) */
int IRExportColorAndFog__ctor_1088c4(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  undefined *puVar1;
  
  ((int (*)())IRExport__ctor_1085b0)(param_1,param_2);
  puVar1 = PTR_DAT_001e8c28;
  param_1[0x21] = 2;
  param_1[0x26] = 0x16;
  *param_1 = puVar1 + 8;
  return;
}

/* IRExport__ctor_108918 @ 0x108918 (276 bytes) */
int IRExport__ctor_108918(this, compiler)
  undefined4 *this;
  int compiler;
{
  undefined4 uVar1;
  undefined4 opcodeInfo;
  
  IRAlu__ctor_1071a8(this,0x30,compiler);
  this[5] = this[5] | 0x12;
  *this = &PTR_FUN_001ea118;
  if ((*(uint *)(*(int *)(compiler + COMP_currentProgram) + 0x30) & 0x4000) == 0) {
    Program__addInst(*(int *)(compiler + COMP_currentProgram),this);
  }
  uVar1 = (**(code **)(**(int **)(compiler + COMP_target) + 0x178))(*(int **)(compiler + COMP_target),compiler);
  opcodeInfo = Opcode__getInfo(uVar1);
  uVar1 = DAT_001af9c8;
  this[0x21] = 1;
  this[0x4f] = 0x32;
  this[0x27] = uVar1;
  this[0x22] = opcodeInfo;
  this[0x20] = 0;
  this[0x50] = 0;
  IRLoadInterp__setLaneKindAndIndex(this,0,5,0);
  IRLoadInterp__setLaneKindAndIndex(this,1,5,0);
  IRLoadInterp__setLaneKindAndIndex(this,2,5,0);
  IRLoadInterp__setLaneKindAndIndex(this,3,5,0);
  this[0x51] = 0;
  return;
}

/* FUN_00108a50 @ 0x108a50 (100 bytes) */
int FUN_00108a50(param_1, param_2, compiler)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 compiler;
{
  undefined *puVar1;
  undefined4 opcodeInfo;
  
  ((int (*)())IRExport__ctor_1085b0)(param_1,compiler);
  puVar1 = PTR_DAT_001e8bfc;
  param_1[0x21] = 1;
  param_1[0x20] = 1;
  *param_1 = puVar1 + 8;
  opcodeInfo = Opcode__getInfo(param_2);
  param_1[0x22] = opcodeInfo;
  return;
}

/* IRLoadConst__vslot77 @ 0x108ad8 (68 bytes) */
int IRLoadConst__vslot77(this, compiler)
  undefined4 this;
  int compiler;
{
  undefined4 *allocation;
  undefined4 arena;
  
  arena = *(undefined4 *)(compiler + COMP_arenaA);
  allocation = (undefined4 *)Arena__alloc(arena,0x168);
  *allocation = arena;
  ((int (*)())FUN_00108a50)(allocation + 1,this,compiler);
  return allocation + 1;
}

/* FUN_00108b54 @ 0x108b54 (96 bytes) */
int FUN_00108b54(this, param_2, compiler)
  undefined4 *this;
  undefined4 param_2;
  int compiler;
{
  undefined *puVar1;
  
  ((int (*)())FUN_00107eec)(this,param_2,compiler);
  puVar1 = PTR_DAT_001e8c30 + 8;
  this[0x20] = 1;
  *this = puVar1;
  this[5] = this[5] | 0x18;
  this[0x4b] = 0;
  return Program__addInst(*(undefined4 *)(compiler + COMP_currentProgram),this);
}

/* IRLoadConst__vslot53 @ 0x108bec (68 bytes) */
int IRLoadConst__vslot53(this, compiler)
  undefined4 this;
  int compiler;
{
  undefined4 *allocation;
  undefined4 arena;
  
  arena = *(undefined4 *)(compiler + COMP_arenaA);
  allocation = (undefined4 *)Arena__alloc(arena,0x168);
  *allocation = arena;
  ((int (*)())FUN_00108b54)(allocation + 1,this,compiler);
  return allocation + 1;
}

/* FUN_00108c68 @ 0x108c68 (84 bytes) */
int FUN_00108c68(this, compiler)
  undefined4 *this;
  undefined4 compiler;
{
  undefined *puVar1;
  
  IRPseudo__ctor(this,0x86,compiler);
  puVar1 = PTR_DAT_001e8bf4;
  this[0x4b] = 0;
  *this = puVar1 + 8;
  return;
}

/* FUN_00108cbc @ 0x108cbc (84 bytes) */
int FUN_00108cbc(this, compiler)
  undefined4 *this;
  undefined4 compiler;
{
  undefined *puVar1;
  
  IRPseudo__ctor(this,0x86,compiler);
  puVar1 = PTR_DAT_001e8bf4;
  this[0x4b] = 0;
  *this = puVar1 + 8;
  return;
}

/* IREntry__ctor_108d10 @ 0x108d10 (76 bytes) */
int IREntry__ctor_108d10(this, compiler)
  undefined4 *this;
  undefined4 compiler;
{
  IRPseudo__ctor(this,0x87,compiler);
  *this = PTR_DAT_001e8c44 + 8;
  return;
}

/* IREntry__ctor_108d5c @ 0x108d5c (76 bytes) */
int IREntry__ctor_108d5c(this, compiler)
  undefined4 *this;
  undefined4 compiler;
{
  IRPseudo__ctor(this,0x87,compiler);
  *this = PTR_DAT_001e8c44 + 8;
  return;
}

/* IRExit__ctor_108da8 @ 0x108da8 (76 bytes) */
int IRExit__ctor_108da8(this, compiler)
  undefined4 *this;
  undefined4 compiler;
{
  IRPseudo__ctor(this,0x88,compiler);
  *this = PTR_DAT_001e8c5c + 8;
  return;
}

/* IRExit__ctor_108df4 @ 0x108df4 (76 bytes) */
int IRExit__ctor_108df4(this, compiler)
  undefined4 *this;
  undefined4 compiler;
{
  IRPseudo__ctor(this,0x88,compiler);
  *this = PTR_DAT_001e8c5c + 8;
  return;
}

/* FUN_00108e40 @ 0x108e40 (76 bytes) */
int FUN_00108e40(this, kind, compiler)
  undefined4 *this;
  undefined4 kind;
  undefined4 compiler;
{
  undefined *puVar1;
  
  IRPseudo__ctor(this,kind,compiler);
  puVar1 = PTR_DAT_001e8c54;
  this[0x20] = 1;
  *this = puVar1 + 8;
  return;
}

/* IRUndefined__ctor_108e8c @ 0x108e8c (84 bytes) */
int IRUndefined__ctor_108e8c(param_1, param_2, compiler)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 compiler;
{
  undefined *puVar1;
  
  ((int (*)())FUN_00108e40)(param_1,param_2,compiler);
  puVar1 = PTR_DAT_001e8c14;
  param_1[0x21] = 0;
  param_1[0x20] = 1;
  *param_1 = puVar1 + 8;
  return;
}

/* IRLoadConst__vslot63 @ 0x108ee0 (68 bytes) */
int IRLoadConst__vslot63(this, compiler)
  undefined4 this;
  int compiler;
{
  undefined4 *allocation;
  undefined4 arena;
  
  arena = *(undefined4 *)(compiler + COMP_arenaA);
  allocation = (undefined4 *)Arena__alloc(arena,0x168);
  *allocation = arena;
  ((int (*)())IRUndefined__ctor_108e8c)(allocation + 1,this,compiler);
  return allocation + 1;
}

/* IRUndefined__ctor_108f5c @ 0x108f5c (84 bytes) */
int IRUndefined__ctor_108f5c(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined *puVar1;
  
  ((int (*)())FUN_00108e40)(param_1,param_2,param_3);
  puVar1 = PTR_DAT_001e8c14;
  param_1[0x21] = 0;
  param_1[0x20] = 1;
  *param_1 = puVar1 + 8;
  return;
}

/* FUN_00108fb0 @ 0x108fb0 (92 bytes) */
int FUN_00108fb0(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  undefined *puVar1;
  
  ((int (*)())FUN_00108e40)(param_1,0x85,param_2);
  puVar1 = PTR_DAT_001e8c14;
  param_1[0x21] = 0;
  param_1[0x20] = 1;
  *param_1 = puVar1 + 8;
  return;
}

/* IRUndefined__ctor_10900c @ 0x10900c (92 bytes) */
int IRUndefined__ctor_10900c(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  undefined *puVar1;
  
  ((int (*)())FUN_00108e40)(param_1,0x85,param_2);
  puVar1 = PTR_DAT_001e8c14;
  param_1[0x21] = 0;
  param_1[0x20] = 1;
  *param_1 = puVar1 + 8;
  return;
}

/* IRLoadMemBufferIndex__ctor_109068 @ 0x109068 (76 bytes) */
int IRLoadMemBufferIndex__ctor_109068(this, param_2)
  undefined4 *this;
  undefined4 param_2;
{
  ((int (*)())FUN_00108e40)(this,0x79,param_2);
  *this = PTR_DAT_001e8bf8 + 8;
  return;
}

/* IRLoadMemBufferIndex__ctor_1090b4 @ 0x1090b4 (76 bytes) */
int IRLoadMemBufferIndex__ctor_1090b4(this, param_2)
  undefined4 *this;
  undefined4 param_2;
{
  ((int (*)())FUN_00108e40)(this,0x79,param_2);
  *this = PTR_DAT_001e8bf8 + 8;
  return;
}

/* IRLoadMemBuffer__ctor_109100 @ 0x109100 (76 bytes) */
int IRLoadMemBuffer__ctor_109100(this, param_2)
  undefined4 *this;
  undefined4 param_2;
{
  ((int (*)())FUN_00108e40)(this,0xfa,param_2);
  *this = PTR_DAT_001e8c34 + 8;
  return;
}

/* IRLoadMemBuffer__ctor_10914c @ 0x10914c (76 bytes) */
int IRLoadMemBuffer__ctor_10914c(this, param_2)
  undefined4 *this;
  undefined4 param_2;
{
  ((int (*)())FUN_00108e40)(this,0xfa,param_2);
  *this = PTR_DAT_001e8c34 + 8;
  return;
}

/* FUN_00109198 @ 0x109198 (216 bytes) */
int FUN_00109198(this, param_2)
  undefined4 *this;
  undefined4 param_2;
{
  undefined *puVar1;
  
  ((int (*)())FUN_00108e40)(this,0x7e,param_2);
  puVar1 = PTR_DAT_001e8c3c + 8;
  this[0x20] = 1;
  *this = puVar1;
  this[5] = this[5] | 0x40;
  this[0x51] = 0x32;
  this[0x52] = 0;
  this[0x21] = 0;
  this[0x50] = 0;
  this[0x4f] = 0;
  IRLoadInterp__setLane(this,0,0,5,0);
  IRLoadInterp__setLane(this,1,0,5,0);
  IRLoadInterp__setLane(this,2,0,5,0);
  return IRLoadInterp__setLane(this,3,0,5,0);
}

/* FUN_00109270 @ 0x109270 (216 bytes) */
int FUN_00109270(this, param_2)
  undefined4 *this;
  undefined4 param_2;
{
  undefined *puVar1;
  
  ((int (*)())FUN_00108e40)(this,0x7e,param_2);
  puVar1 = PTR_DAT_001e8c3c + 8;
  this[0x20] = 1;
  *this = puVar1;
  this[5] = this[5] | 0x40;
  this[0x51] = 0x32;
  this[0x52] = 0;
  this[0x21] = 0;
  this[0x50] = 0;
  this[0x4f] = 0;
  IRLoadInterp__setLane(this,0,0,5,0);
  IRLoadInterp__setLane(this,1,0,5,0);
  IRLoadInterp__setLane(this,2,0,5,0);
  return IRLoadInterp__setLane(this,3,0,5,0);
}

/* FUN_00109348 @ 0x109348 (112 bytes) */
int FUN_00109348(param_1, param_2, param_3)
  undefined4 *param_1;
  int param_2;
  undefined4 param_3;
{
  undefined *puVar1;
  undefined4 uVar2;
  
  ((int (*)())FUN_00108e40)(param_1,0x7a,param_3);
  puVar1 = PTR_DAT_001e8c20;
  param_1[0x20] = 1;
  *param_1 = puVar1 + 8;
  param_1[0x26] = *(undefined4 *)(param_2 + 4);
  uVar2 = *(undefined4 *)(param_2 + 8);
  param_1[0x21] = 0;
  param_1[0x25] = uVar2;
  param_1[0x23] = param_2;
  return;
}

/* IRLoadTemp__ctor_1093b8 @ 0x1093b8 (112 bytes) */
int IRLoadTemp__ctor_1093b8(param_1, param_2, param_3)
  undefined4 *param_1;
  int param_2;
  undefined4 param_3;
{
  undefined *puVar1;
  undefined4 uVar2;
  
  ((int (*)())FUN_00108e40)(param_1,0x7a,param_3);
  puVar1 = PTR_DAT_001e8c20;
  param_1[0x20] = 1;
  *param_1 = puVar1 + 8;
  param_1[0x26] = *(undefined4 *)(param_2 + 4);
  uVar2 = *(undefined4 *)(param_2 + 8);
  param_1[0x21] = 0;
  param_1[0x25] = uVar2;
  param_1[0x23] = param_2;
  return;
}

/* FUN_00109428 @ 0x109428 (88 bytes) */
int FUN_00109428(param_1, param_2, compiler)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 compiler;
{
  undefined *puVar1;
  
  ((int (*)())FUN_00108e40)(param_1,param_2,compiler);
  puVar1 = PTR_DAT_001e8c20;
  param_1[0x21] = 0;
  param_1[0x20] = 1;
  *param_1 = puVar1 + 8;
  param_1[0x26] = 0;
  return;
}

/* FUN_00109480 @ 0x109480 (68 bytes) */
int FUN_00109480(param_1, compiler)
  undefined4 param_1;
  int compiler;
{
  undefined4 *allocation;
  undefined4 arena;
  
  arena = *(undefined4 *)(compiler + COMP_arenaA);
  allocation = (undefined4 *)Arena__alloc(arena,0x168);
  *allocation = arena;
  ((int (*)())FUN_00109428)(allocation + 1,param_1,compiler);
  return allocation + 1;
}

/* IRLoadTemp__ctor_1094fc @ 0x1094fc (88 bytes) */
int IRLoadTemp__ctor_1094fc(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined *puVar1;
  
  ((int (*)())FUN_00108e40)(param_1,param_2,param_3);
  puVar1 = PTR_DAT_001e8c20;
  param_1[0x21] = 0;
  param_1[0x20] = 1;
  *param_1 = puVar1 + 8;
  param_1[0x26] = 0;
  return;
}

/* FUN_00109554 @ 0x109554 (96 bytes) */
int FUN_00109554(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  undefined *puVar1;
  
  ((int (*)())FUN_00108e40)(param_1,0x7a,param_2);
  puVar1 = PTR_DAT_001e8c20;
  param_1[0x21] = 0;
  param_1[0x20] = 1;
  *param_1 = puVar1 + 8;
  param_1[0x26] = 0;
  return;
}

/* IRLoadTemp__ctor_1095b4 @ 0x1095b4 (96 bytes) */
int IRLoadTemp__ctor_1095b4(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  undefined *puVar1;
  
  ((int (*)())FUN_00108e40)(param_1,0x7a,param_2);
  puVar1 = PTR_DAT_001e8c20;
  param_1[0x21] = 0;
  param_1[0x20] = 1;
  *param_1 = puVar1 + 8;
  param_1[0x26] = 0;
  return;
}

/* IRLoadConst__ctor_109614 @ 0x109614 (112 bytes) */
int IRLoadConst__ctor_109614(this, param_2, param_3)
  undefined4 *this;
  int param_2;
  int param_3;
{
  undefined4 uVar1;
  
  ((int (*)())FUN_00108e40)(this,0x79,param_3);
  *this = &PTR_FUN_001ea460;
  this[0x26] = *(undefined4 *)(param_2 + 4);
  uVar1 = *(undefined4 *)(param_2 + 8);
  this[0x23] = param_2;
  this[0x25] = uVar1;
  this[0x20] = 1;
  this[0x21] = 0;
  return FUN_000ef8f8(*(undefined4 *)(param_3 + 0x6c4),this);
}

/* IRLoadConst__ctor_1096bc @ 0x1096bc (112 bytes) */
int IRLoadConst__ctor_1096bc(this, param_2, param_3)
  undefined4 *this;
  int param_2;
  int param_3;
{
  undefined4 uVar1;
  
  ((int (*)())FUN_00108e40)(this,0x79,param_3);
  *this = &PTR_FUN_001ea460;
  this[0x26] = *(undefined4 *)(param_2 + 4);
  uVar1 = *(undefined4 *)(param_2 + 8);
  this[0x23] = param_2;
  this[0x25] = uVar1;
  this[0x20] = 1;
  this[0x21] = 0;
  return FUN_000ef8f8(*(undefined4 *)(param_3 + 0x6c4),this);
}

/* FUN_00109764 @ 0x109764 (116 bytes) */
int FUN_00109764(param_1, param_2, compiler)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 compiler;
{
  undefined *puVar1;
  int preserveVertexInputsEnabled;
  
  ((int (*)())FUN_00108e40)(param_1,param_2,compiler);
  puVar1 = PTR_DAT_001e8bdc;
  param_1[0x21] = 0;
  param_1[0x26] = 0x1a;
  *param_1 = puVar1 + 8;
  param_1[0x20] = 1;
  param_1[0x4c] = 0;
  preserveVertexInputsEnabled = Compiler__isOptionEnabled(compiler,0x3e);
  if (preserveVertexInputsEnabled != 0) {
    param_1[5] = param_1[5] | 0x18;
  }
  return;
}

/* FUN_00109810 @ 0x109810 (68 bytes) */
int FUN_00109810(param_1, compiler)
  undefined4 param_1;
  int compiler;
{
  undefined4 *allocation;
  undefined4 arena;
  
  arena = *(undefined4 *)(compiler + COMP_arenaA);
  allocation = (undefined4 *)Arena__alloc(arena,0x168);
  *allocation = arena;
  ((int (*)())FUN_00109764)(allocation + 1,param_1,compiler);
  return allocation + 1;
}

/* FUN_0010988c @ 0x10988c (116 bytes) */
int FUN_0010988c(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined *puVar1;
  int preserveVertexInputsEnabled;
  
  ((int (*)())FUN_00108e40)(param_1,param_2,param_3);
  puVar1 = PTR_DAT_001e8bdc;
  param_1[0x21] = 0;
  param_1[0x26] = 0x1a;
  *param_1 = puVar1 + 8;
  param_1[0x20] = 1;
  param_1[0x4c] = 0;
  preserveVertexInputsEnabled = Compiler__isOptionEnabled(param_3,0x3e);
  if (preserveVertexInputsEnabled != 0) {
    param_1[5] = param_1[5] | 0x18;
  }
  return;
}

/* IRLoadConst__ctor_109938 @ 0x109938 (108 bytes) */
int IRLoadConst__ctor_109938(this, param_2)
  undefined4 *this;
  int param_2;
{
  ((int (*)())FUN_00108e40)(this,0x79,param_2);
  this[0x26] = 2;
  *this = &PTR_FUN_001ea460;
  this[0x20] = 1;
  this[0x21] = 0;
  this[0x4b] = 0xffffffff;
  return FUN_000ef8f8(*(undefined4 *)(param_2 + 0x6c4),this);
}

/* IRLoadConst__ctor_1099dc @ 0x1099dc (108 bytes) */
int IRLoadConst__ctor_1099dc(this, param_2)
  undefined4 *this;
  int param_2;
{
  ((int (*)())FUN_00108e40)(this,0x79,param_2);
  this[0x26] = 2;
  *this = &PTR_FUN_001ea460;
  this[0x20] = 1;
  this[0x21] = 0;
  this[0x4b] = 0xffffffff;
  return FUN_000ef8f8(*(undefined4 *)(param_2 + 0x6c4),this);
}


/* issue: auto-generated aliases bridging data.s/code.s references (written
 * without a leading underscore, matching the raw stock-binary symbol name)
 * against the real compiled C symbols (gcc adds one underscore automatically).
 * Needed because ld64 (required for this PPC binary's size - stock ld breaks on
 * large PPC links) does not silently reconcile this the way stock ld did. */
asm(".globl FUN_00107df4");
asm(".set FUN_00107df4, _FUN_00107df4");
asm(".globl FUN_00107e70");
asm(".set FUN_00107e70, _IRLoadConst__vslot43");
asm(".globl FUN_00108064");
asm(".set FUN_00108064, _IRLoadConst__vslot55");
asm(".globl FUN_001081c0");
asm(".set FUN_001081c0, _FUN_001081c0");
asm(".globl FUN_0010823c");
asm(".set FUN_0010823c, _IRLoadConst__vslot47");
asm(".globl FUN_00108350");
asm(".set FUN_00108350, _FUN_00108350");
asm(".globl FUN_001083cc");
asm(".set FUN_001083cc, _IRLoadConst__vslot49");
asm(".globl FUN_001084b8");
asm(".set FUN_001084b8, _FUN_001084b8");
asm(".globl FUN_00108534");
asm(".set FUN_00108534, _IRLoadConst__vslot45");
asm(".globl FUN_00108ad8");
asm(".set FUN_00108ad8, _IRLoadConst__vslot77");
asm(".globl FUN_00108bec");
asm(".set FUN_00108bec, _IRLoadConst__vslot53");
asm(".globl FUN_00108ee0");
asm(".set FUN_00108ee0, _IRLoadConst__vslot63");
