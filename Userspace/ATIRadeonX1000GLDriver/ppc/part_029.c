#include "decls.h"

/* IRUnary__new_107df4 @ 0x107df4 (68 bytes) */
int IRUnary__new_107df4(opcode, compiler)
  undefined4 opcode;
  int compiler;
{
  undefined4 *allocation;
  undefined4 arena;
  
  arena = *(undefined4 *)(compiler + COMP_arenaA);
  allocation = (undefined4 *)Arena__alloc(arena,0x168);
  *allocation = arena;
  IRInst__reinitAsUnary(allocation + 1,opcode,compiler);
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

/* IRBinary__ctor_107eec @ 0x107eec (76 bytes) */
int IRBinary__ctor_107eec(inst, opcode, compiler)
  undefined4 *inst;
  undefined4 opcode;
  undefined4 compiler;
{
  undefined *vtable;
  
  IRAlu__ctor_1071a8(inst,opcode,compiler);
  vtable = PTR_DAT_001e8bec;
  inst[0x21] = 2;
  *inst = vtable + 8;
  return;
}

/* IRKill2__ctor_107f38 @ 0x107f38 (96 bytes) */
int IRKill2__ctor_107f38(this, opcode, compiler)
  undefined4 *this;
  undefined4 opcode;
  int compiler;
{
  undefined *vtable;
  
  ((int (*)())IRBinary__ctor_107eec)(this,opcode,compiler);
  vtable = PTR_DAT_001e8c30 + 8;
  this[0x20] = 1;
  *this = vtable;
  this[5] = this[5] | 0x18;
  this[0x4b] = 0;
  return Program__addInst(*(undefined4 *)(compiler + 0x6c4),this);
}

/* IRCmp2__ctor_107fd0 @ 0x107fd0 (92 bytes) */
int IRCmp2__ctor_107fd0(this, unusedArg2, compiler)
  undefined4 *this;
  undefined4 unusedArg2;
  int compiler;
{
  undefined *vtable;
  
  ((int (*)())IRBinary__ctor_107eec)(this,0x8b,compiler);
  vtable = PTR_DAT_001e8be4;
  this[0x20] = 0;
  this[5] = this[5] | 0x18;
  *this = vtable + 8;
  return Program__addInst(*(undefined4 *)(compiler + COMP_currentProgram),this);
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
  ((int (*)())IRCmp2__ctor_107fd0)(allocation + 1,this,compiler);
  return allocation + 1;
}

/* IRCmp2__ctor_1080e0 @ 0x1080e0 (92 bytes) */
int IRCmp2__ctor_1080e0(this, unusedArg2, compiler)
  undefined4 *this;
  undefined4 unusedArg2;
  int compiler;
{
  undefined *vtable;
  
  ((int (*)())IRBinary__ctor_107eec)(this,0x8b,compiler);
  vtable = PTR_DAT_001e8be4;
  this[0x20] = 0;
  this[5] = this[5] | 0x18;
  *this = vtable + 8;
  return Program__addInst(*(undefined4 *)(compiler + 0x6c4),this);
}

/* IRInst__reinitAsBinary @ 0x108174 (76 bytes) */
int IRInst__reinitAsBinary(inst, opcode, compiler)
  undefined4 *inst;
  undefined4 opcode;
  undefined4 compiler;
{
  undefined *vtable;
  
  IRAlu__ctor_1071a8(inst,opcode,compiler);
  vtable = PTR_DAT_001e8bec;
  inst[0x21] = 2;
  *inst = vtable + 8;
  return;
}

/* IRBinary__new_1081c0 @ 0x1081c0 (68 bytes) */
int IRBinary__new_1081c0(opcode, compiler)
  undefined4 opcode;
  int compiler;
{
  undefined4 *allocation;
  undefined4 arena;
  
  arena = *(undefined4 *)(compiler + COMP_arenaA);
  allocation = (undefined4 *)Arena__alloc(arena,0x168);
  *allocation = arena;
  ((int (*)())IRInst__reinitAsBinary)(allocation + 1,opcode,compiler);
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

/* IRTrinary__ctor_1082b8 @ 0x1082b8 (76 bytes) */
int IRTrinary__ctor_1082b8(inst, opcode, compiler)
  undefined4 *inst;
  undefined4 opcode;
  undefined4 compiler;
{
  undefined *vtable;
  
  IRAlu__ctor_1071a8(inst,opcode,compiler);
  vtable = PTR_DAT_001e8c24;
  inst[0x21] = 3;
  *inst = vtable + 8;
  return;
}

/* IRInst__reinitAsTrinary @ 0x108304 (76 bytes) */
int IRInst__reinitAsTrinary(inst, opcode, compiler)
  undefined4 *inst;
  undefined4 opcode;
  undefined4 compiler;
{
  undefined *vtable;
  
  IRAlu__ctor_1071a8(inst,opcode,compiler);
  vtable = PTR_DAT_001e8c24;
  inst[0x21] = 3;
  *inst = vtable + 8;
  return;
}

/* IRTrinary__new_108350 @ 0x108350 (68 bytes) */
int IRTrinary__new_108350(opcode, compiler)
  undefined4 opcode;
  int compiler;
{
  undefined4 *allocation;
  undefined4 arena;
  
  arena = *(undefined4 *)(compiler + COMP_arenaA);
  allocation = (undefined4 *)Arena__alloc(arena,0x168);
  *allocation = arena;
  ((int (*)())IRInst__reinitAsTrinary)(allocation + 1,opcode,compiler);
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
int IRInst__reinitAsMov(this, opcode, compiler)
  undefined4 *this;
  undefined4 opcode;
  undefined4 compiler;
{
  bool moreLanes;
  undefined *vtable;
  int laneIndex;
  
  IRUnary__ctor_107cec(this,opcode,compiler);
  vtable = PTR_DAT_001e8bf0;
  this[0x20] = 1;
  *this = vtable + 8;
  laneIndex = 0;
  do {
    moreLanes = laneIndex != 1;
    this[0x25] = 0xffffffff;
    this[0x26] = 0;
    laneIndex = laneIndex + 1;
    this = this + 6;
  } while (moreLanes);
  return;
}

/* IRMov__new_1084b8 @ 0x1084b8 (68 bytes) */
int IRMov__new_1084b8(opcode, compiler)
  undefined4 opcode;
  int compiler;
{
  undefined4 *allocation;
  undefined4 arena;
  
  arena = *(undefined4 *)(compiler + COMP_arenaA);
  allocation = (undefined4 *)Arena__alloc(arena,0x168);
  *allocation = arena;
  ((int (*)())IRInst__reinitAsMov)(allocation + 1,opcode,compiler);
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
  undefined4 opcodeId;
  undefined4 defaultWord27;
  undefined4 opcodeInfo;
  
  IRAlu__ctor_1071a8(this,0x30,compiler);
  this[5] = this[5] | 0x12;
  *this = &ptrTo_IRInst__dtor_1cf608_001ea118;
  if ((*(uint *)(*(int *)(compiler + COMP_currentProgram) + 0x30) & 0x4000) == 0) {
    Program__addInst(*(int *)(compiler + COMP_currentProgram),this);
  }
  opcodeId = (**(code **)(**(int **)(compiler + COMP_target) + 0x178))(*(int **)(compiler + COMP_target),compiler);
  opcodeInfo = Opcode__getInfo(opcodeId);
  defaultWord27 = DAT_001af9c8;
  this[0x21] = 1;
  this[0x4f] = 0x32;
  this[0x27] = defaultWord27;
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

/* IRGeomExport__ctor_1086e8 @ 0x1086e8 (100 bytes) */
int IRGeomExport__ctor_1086e8(this, opcode, compiler)
  undefined4 *this;
  undefined4 opcode;
  undefined4 compiler;
{
  undefined *vtable;
  undefined4 opcodeInfo;
  
  ((int (*)())IRExport__ctor_1085b0)(this,compiler);
  vtable = PTR_DAT_001e8bfc;
  this[0x21] = 1;
  this[0x20] = 1;
  *this = vtable + 8;
  opcodeInfo = Opcode__getInfo(opcode);
  this[0x22] = opcodeInfo;
  return;
}

/* IRGeomExport__ctor_108770 @ 0x108770 (92 bytes) */
int IRGeomExport__ctor_108770(this, compiler)
  undefined4 *this;
  undefined4 compiler;
{
  undefined *vtable;
  undefined4 opcodeInfo;
  
  ((int (*)())IRExport__ctor_1085b0)(this,compiler);
  vtable = PTR_DAT_001e8bfc;
  this[0x21] = 1;
  this[0x20] = 1;
  *this = vtable + 8;
  opcodeInfo = Opcode__getInfo(0xf9);
  this[0x22] = opcodeInfo;
  return;
}

/* IRGeomExport__ctor_1087f0 @ 0x1087f0 (92 bytes) */
int IRGeomExport__ctor_1087f0(this, compiler)
  undefined4 *this;
  undefined4 compiler;
{
  undefined *vtable;
  undefined4 opcodeInfo;
  
  ((int (*)())IRExport__ctor_1085b0)(this,compiler);
  vtable = PTR_DAT_001e8bfc;
  this[0x21] = 1;
  this[0x20] = 1;
  *this = vtable + 8;
  opcodeInfo = Opcode__getInfo(0xf9);
  this[0x22] = opcodeInfo;
  return;
}

/* IRExportColorAndFog__ctor_108870 @ 0x108870 (84 bytes) */
int IRExportColorAndFog__ctor_108870(this, compiler)
  undefined4 *this;
  undefined4 compiler;
{
  undefined *vtable;
  
  ((int (*)())IRExport__ctor_1085b0)(this,compiler);
  vtable = PTR_DAT_001e8c28;
  this[0x21] = 2;
  this[0x26] = 0x16;
  *this = vtable + 8;
  return;
}

/* IRExportColorAndFog__ctor_1088c4 @ 0x1088c4 (84 bytes) */
int IRExportColorAndFog__ctor_1088c4(this, compiler)
  undefined4 *this;
  undefined4 compiler;
{
  undefined *vtable;
  
  ((int (*)())IRExport__ctor_1085b0)(this,compiler);
  vtable = PTR_DAT_001e8c28;
  this[0x21] = 2;
  this[0x26] = 0x16;
  *this = vtable + 8;
  return;
}

/* IRExport__ctor_108918 @ 0x108918 (276 bytes) */
int IRExport__ctor_108918(this, compiler)
  undefined4 *this;
  int compiler;
{
  undefined4 opcodeId;
  undefined4 defaultWord27;
  undefined4 opcodeInfo;
  
  IRAlu__ctor_1071a8(this,0x30,compiler);
  this[5] = this[5] | 0x12;
  *this = &ptrTo_IRInst__dtor_1cf608_001ea118;
  if ((*(uint *)(*(int *)(compiler + COMP_currentProgram) + 0x30) & 0x4000) == 0) {
    Program__addInst(*(int *)(compiler + COMP_currentProgram),this);
  }
  opcodeId = (**(code **)(**(int **)(compiler + COMP_target) + 0x178))(*(int **)(compiler + COMP_target),compiler);
  opcodeInfo = Opcode__getInfo(opcodeId);
  defaultWord27 = DAT_001af9c8;
  this[0x21] = 1;
  this[0x4f] = 0x32;
  this[0x27] = defaultWord27;
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

/* IRGeomExport__ctor_108a50 @ 0x108a50 (100 bytes) */
int IRGeomExport__ctor_108a50(this, opcode, compiler)
  undefined4 *this;
  undefined4 opcode;
  undefined4 compiler;
{
  undefined *vtable;
  undefined4 opcodeInfo;
  
  ((int (*)())IRExport__ctor_1085b0)(this,compiler);
  vtable = PTR_DAT_001e8bfc;
  this[0x21] = 1;
  this[0x20] = 1;
  *this = vtable + 8;
  opcodeInfo = Opcode__getInfo(opcode);
  this[0x22] = opcodeInfo;
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
  ((int (*)())IRGeomExport__ctor_108a50)(allocation + 1,this,compiler);
  return allocation + 1;
}

/* IRKill2__ctor_108b54 @ 0x108b54 (96 bytes) */
int IRKill2__ctor_108b54(this, opcode, compiler)
  undefined4 *this;
  undefined4 opcode;
  int compiler;
{
  undefined *vtable;
  
  ((int (*)())IRBinary__ctor_107eec)(this,opcode,compiler);
  vtable = PTR_DAT_001e8c30 + 8;
  this[0x20] = 1;
  *this = vtable;
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
  ((int (*)())IRKill2__ctor_108b54)(allocation + 1,this,compiler);
  return allocation + 1;
}

/* IRHeader__ctor_108c68 @ 0x108c68 (84 bytes) */
int IRHeader__ctor_108c68(this, compiler)
  undefined4 *this;
  undefined4 compiler;
{
  undefined *vtable;
  
  IRPseudo__ctor(this,0x86,compiler);
  vtable = PTR_DAT_001e8bf4;
  this[0x4b] = 0;
  *this = vtable + 8;
  return;
}

/* IRHeader__ctor_108cbc @ 0x108cbc (84 bytes) */
int IRHeader__ctor_108cbc(this, compiler)
  undefined4 *this;
  undefined4 compiler;
{
  undefined *vtable;
  
  IRPseudo__ctor(this,0x86,compiler);
  vtable = PTR_DAT_001e8bf4;
  this[0x4b] = 0;
  *this = vtable + 8;
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

/* IRLoad__ctor_108e40 @ 0x108e40 (76 bytes) */
int IRLoad__ctor_108e40(this, kind, compiler)
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

/* IRUndefined__ctor_108e8c @ 0x108e8c (84 bytes) */
int IRUndefined__ctor_108e8c(this, opcode, compiler)
  undefined4 *this;
  undefined4 opcode;
  undefined4 compiler;
{
  undefined *vtable;
  
  ((int (*)())IRLoad__ctor_108e40)(this,opcode,compiler);
  vtable = PTR_DAT_001e8c14;
  this[0x21] = 0;
  this[0x20] = 1;
  *this = vtable + 8;
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
int IRUndefined__ctor_108f5c(this, opcode, compiler)
  undefined4 *this;
  undefined4 opcode;
  undefined4 compiler;
{
  undefined *vtable;
  
  ((int (*)())IRLoad__ctor_108e40)(this,opcode,compiler);
  vtable = PTR_DAT_001e8c14;
  this[0x21] = 0;
  this[0x20] = 1;
  *this = vtable + 8;
  return;
}

/* IRUndefined__ctor_108fb0 @ 0x108fb0 (92 bytes) */
int IRUndefined__ctor_108fb0(this, compiler)
  undefined4 *this;
  undefined4 compiler;
{
  undefined *vtable;
  
  ((int (*)())IRLoad__ctor_108e40)(this,0x85,compiler);
  vtable = PTR_DAT_001e8c14;
  this[0x21] = 0;
  this[0x20] = 1;
  *this = vtable + 8;
  return;
}

/* IRUndefined__ctor_10900c @ 0x10900c (92 bytes) */
int IRUndefined__ctor_10900c(this, compiler)
  undefined4 *this;
  undefined4 compiler;
{
  undefined *vtable;
  
  ((int (*)())IRLoad__ctor_108e40)(this,0x85,compiler);
  vtable = PTR_DAT_001e8c14;
  this[0x21] = 0;
  this[0x20] = 1;
  *this = vtable + 8;
  return;
}

/* IRLoadMemBufferIndex__ctor_109068 @ 0x109068 (76 bytes) */
int IRLoadMemBufferIndex__ctor_109068(this, compiler)
  undefined4 *this;
  undefined4 compiler;
{
  ((int (*)())IRLoad__ctor_108e40)(this,0x79,compiler);
  *this = PTR_DAT_001e8bf8 + 8;
  return;
}

/* IRLoadMemBufferIndex__ctor_1090b4 @ 0x1090b4 (76 bytes) */
int IRLoadMemBufferIndex__ctor_1090b4(this, compiler)
  undefined4 *this;
  undefined4 compiler;
{
  ((int (*)())IRLoad__ctor_108e40)(this,0x79,compiler);
  *this = PTR_DAT_001e8bf8 + 8;
  return;
}

/* IRLoadMemBuffer__ctor_109100 @ 0x109100 (76 bytes) */
int IRLoadMemBuffer__ctor_109100(this, compiler)
  undefined4 *this;
  undefined4 compiler;
{
  ((int (*)())IRLoad__ctor_108e40)(this,0xfa,compiler);
  *this = PTR_DAT_001e8c34 + 8;
  return;
}

/* IRLoadMemBuffer__ctor_10914c @ 0x10914c (76 bytes) */
int IRLoadMemBuffer__ctor_10914c(this, compiler)
  undefined4 *this;
  undefined4 compiler;
{
  ((int (*)())IRLoad__ctor_108e40)(this,0xfa,compiler);
  *this = PTR_DAT_001e8c34 + 8;
  return;
}

/* IRLoadInterp__ctor_109198 @ 0x109198 (216 bytes) */
int IRLoadInterp__ctor_109198(this, compiler)
  undefined4 *this;
  undefined4 compiler;
{
  undefined *vtable;
  
  ((int (*)())IRLoad__ctor_108e40)(this,0x7e,compiler);
  vtable = PTR_DAT_001e8c3c + 8;
  this[0x20] = 1;
  *this = vtable;
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

/* IRLoadInterp__ctor_109270 @ 0x109270 (216 bytes) */
int IRLoadInterp__ctor_109270(this, compiler)
  undefined4 *this;
  undefined4 compiler;
{
  undefined *vtable;
  
  ((int (*)())IRLoad__ctor_108e40)(this,0x7e,compiler);
  vtable = PTR_DAT_001e8c3c + 8;
  this[0x20] = 1;
  *this = vtable;
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

/* IRLoadTemp__ctor_109348 @ 0x109348 (112 bytes) */
int IRLoadTemp__ctor_109348(this, sourceRecord, compiler)
  undefined4 *this;
  int sourceRecord;
  undefined4 compiler;
{
  undefined *vtable;
  undefined4 sourceWord8;
  
  ((int (*)())IRLoad__ctor_108e40)(this,0x7a,compiler);
  vtable = PTR_DAT_001e8c20;
  this[0x20] = 1;
  *this = vtable + 8;
  this[0x26] = *(undefined4 *)(sourceRecord + 4);
  sourceWord8 = *(undefined4 *)(sourceRecord + 8);
  this[0x21] = 0;
  this[0x25] = sourceWord8;
  this[0x23] = sourceRecord;
  return;
}

/* IRLoadTemp__ctor_1093b8 @ 0x1093b8 (112 bytes) */
int IRLoadTemp__ctor_1093b8(this, sourceRecord, compiler)
  undefined4 *this;
  int sourceRecord;
  undefined4 compiler;
{
  undefined *vtable;
  undefined4 sourceWord8;
  
  ((int (*)())IRLoad__ctor_108e40)(this,0x7a,compiler);
  vtable = PTR_DAT_001e8c20;
  this[0x20] = 1;
  *this = vtable + 8;
  this[0x26] = *(undefined4 *)(sourceRecord + 4);
  sourceWord8 = *(undefined4 *)(sourceRecord + 8);
  this[0x21] = 0;
  this[0x25] = sourceWord8;
  this[0x23] = sourceRecord;
  return;
}

/* IRLoadTemp__ctor_109428 @ 0x109428 (88 bytes) */
int IRLoadTemp__ctor_109428(this, opcode, compiler)
  undefined4 *this;
  undefined4 opcode;
  undefined4 compiler;
{
  undefined *vtable;
  
  ((int (*)())IRLoad__ctor_108e40)(this,opcode,compiler);
  vtable = PTR_DAT_001e8c20;
  this[0x21] = 0;
  this[0x20] = 1;
  *this = vtable + 8;
  this[0x26] = 0;
  return;
}

/* IRLoadTemp__new_109480 @ 0x109480 (68 bytes) */
int IRLoadTemp__new_109480(opcode, compiler)
  undefined4 opcode;
  int compiler;
{
  undefined4 *allocation;
  undefined4 arena;
  
  arena = *(undefined4 *)(compiler + COMP_arenaA);
  allocation = (undefined4 *)Arena__alloc(arena,0x168);
  *allocation = arena;
  ((int (*)())IRLoadTemp__ctor_109428)(allocation + 1,opcode,compiler);
  return allocation + 1;
}

/* IRLoadTemp__ctor_1094fc @ 0x1094fc (88 bytes) */
int IRLoadTemp__ctor_1094fc(this, opcode, compiler)
  undefined4 *this;
  undefined4 opcode;
  undefined4 compiler;
{
  undefined *vtable;
  
  ((int (*)())IRLoad__ctor_108e40)(this,opcode,compiler);
  vtable = PTR_DAT_001e8c20;
  this[0x21] = 0;
  this[0x20] = 1;
  *this = vtable + 8;
  this[0x26] = 0;
  return;
}

/* IRLoadTemp__ctor_109554 @ 0x109554 (96 bytes) */
int IRLoadTemp__ctor_109554(this, compiler)
  undefined4 *this;
  undefined4 compiler;
{
  undefined *vtable;
  
  ((int (*)())IRLoad__ctor_108e40)(this,0x7a,compiler);
  vtable = PTR_DAT_001e8c20;
  this[0x21] = 0;
  this[0x20] = 1;
  *this = vtable + 8;
  this[0x26] = 0;
  return;
}

/* IRLoadTemp__ctor_1095b4 @ 0x1095b4 (96 bytes) */
int IRLoadTemp__ctor_1095b4(this, compiler)
  undefined4 *this;
  undefined4 compiler;
{
  undefined *vtable;
  
  ((int (*)())IRLoad__ctor_108e40)(this,0x7a,compiler);
  vtable = PTR_DAT_001e8c20;
  this[0x21] = 0;
  this[0x20] = 1;
  *this = vtable + 8;
  this[0x26] = 0;
  return;
}

/* IRLoadConst__ctor_109614 @ 0x109614 (112 bytes) */
int IRLoadConst__ctor_109614(this, sourceRecord, compiler)
  undefined4 *this;
  int sourceRecord;
  int compiler;
{
  undefined4 sourceWord8;
  
  ((int (*)())IRLoad__ctor_108e40)(this,0x79,compiler);
  *this = &ptrTo_IRInst__dtor_1cf63c_001ea460;
  this[0x26] = *(undefined4 *)(sourceRecord + 4);
  sourceWord8 = *(undefined4 *)(sourceRecord + 8);
  this[0x23] = sourceRecord;
  this[0x25] = sourceWord8;
  this[0x20] = 1;
  this[0x21] = 0;
  return Program__appendToVector3c8(*(undefined4 *)(compiler + 0x6c4),this);
}

/* IRLoadConst__ctor_1096bc @ 0x1096bc (112 bytes) */
int IRLoadConst__ctor_1096bc(this, sourceRecord, compiler)
  undefined4 *this;
  int sourceRecord;
  int compiler;
{
  undefined4 sourceWord8;
  
  ((int (*)())IRLoad__ctor_108e40)(this,0x79,compiler);
  *this = &ptrTo_IRInst__dtor_1cf63c_001ea460;
  this[0x26] = *(undefined4 *)(sourceRecord + 4);
  sourceWord8 = *(undefined4 *)(sourceRecord + 8);
  this[0x23] = sourceRecord;
  this[0x25] = sourceWord8;
  this[0x20] = 1;
  this[0x21] = 0;
  return Program__appendToVector3c8(*(undefined4 *)(compiler + 0x6c4),this);
}

/* IRLoadVertex__ctor_109764 @ 0x109764 (116 bytes) */
int IRLoadVertex__ctor_109764(this, opcode, compiler)
  undefined4 *this;
  undefined4 opcode;
  undefined4 compiler;
{
  undefined *vtable;
  int preserveVertexInputsEnabled;
  
  ((int (*)())IRLoad__ctor_108e40)(this,opcode,compiler);
  vtable = PTR_DAT_001e8bdc;
  this[0x21] = 0;
  this[0x26] = 0x1a;
  *this = vtable + 8;
  this[0x20] = 1;
  this[0x4c] = 0;
  preserveVertexInputsEnabled = Compiler__isOptionEnabled(compiler,0x3e);
  if (preserveVertexInputsEnabled != 0) {
    this[5] = this[5] | 0x18;
  }
  return;
}

/* IRLoadVertex__new_109810 @ 0x109810 (68 bytes) */
int IRLoadVertex__new_109810(opcode, compiler)
  undefined4 opcode;
  int compiler;
{
  undefined4 *allocation;
  undefined4 arena;
  
  arena = *(undefined4 *)(compiler + COMP_arenaA);
  allocation = (undefined4 *)Arena__alloc(arena,0x168);
  *allocation = arena;
  ((int (*)())IRLoadVertex__ctor_109764)(allocation + 1,opcode,compiler);
  return allocation + 1;
}

/* IRLoadVertex__ctor_10988c @ 0x10988c (116 bytes) */
int IRLoadVertex__ctor_10988c(this, opcode, compiler)
  undefined4 *this;
  undefined4 opcode;
  undefined4 compiler;
{
  undefined *vtable;
  int preserveVertexInputsEnabled;
  
  ((int (*)())IRLoad__ctor_108e40)(this,opcode,compiler);
  vtable = PTR_DAT_001e8bdc;
  this[0x21] = 0;
  this[0x26] = 0x1a;
  *this = vtable + 8;
  this[0x20] = 1;
  this[0x4c] = 0;
  preserveVertexInputsEnabled = Compiler__isOptionEnabled(compiler,0x3e);
  if (preserveVertexInputsEnabled != 0) {
    this[5] = this[5] | 0x18;
  }
  return;
}

/* IRLoadConst__ctor_109938 @ 0x109938 (108 bytes) */
int IRLoadConst__ctor_109938(this, compiler)
  undefined4 *this;
  int compiler;
{
  ((int (*)())IRLoad__ctor_108e40)(this,0x79,compiler);
  this[0x26] = 2;
  *this = &ptrTo_IRInst__dtor_1cf63c_001ea460;
  this[0x20] = 1;
  this[0x21] = 0;
  this[0x4b] = 0xffffffff;
  return Program__appendToVector3c8(*(undefined4 *)(compiler + 0x6c4),this);
}

/* IRLoadConst__ctor_1099dc @ 0x1099dc (108 bytes) */
int IRLoadConst__ctor_1099dc(this, compiler)
  undefined4 *this;
  int compiler;
{
  ((int (*)())IRLoad__ctor_108e40)(this,0x79,compiler);
  this[0x26] = 2;
  *this = &ptrTo_IRInst__dtor_1cf63c_001ea460;
  this[0x20] = 1;
  this[0x21] = 0;
  this[0x4b] = 0xffffffff;
  return Program__appendToVector3c8(*(undefined4 *)(compiler + 0x6c4),this);
}


/* issue: auto-generated aliases bridging data.s/code.s references (written
 * without a leading underscore, matching the raw stock-binary symbol name)
 * against the real compiled C symbols (gcc adds one underscore automatically).
 * Needed because ld64 (required for this PPC binary's size - stock ld breaks on
 * large PPC links) does not silently reconcile this the way stock ld did. */
asm(".globl IRUnary__new_107df4");
asm(".set IRUnary__new_107df4, _IRUnary__new_107df4");
asm(".globl IRLoadConst__vslot43");
asm(".set IRLoadConst__vslot43, _IRLoadConst__vslot43");
asm(".globl IRLoadConst__vslot55");
asm(".set IRLoadConst__vslot55, _IRLoadConst__vslot55");
asm(".globl IRBinary__new_1081c0");
asm(".set IRBinary__new_1081c0, _IRBinary__new_1081c0");
asm(".globl IRLoadConst__vslot47");
asm(".set IRLoadConst__vslot47, _IRLoadConst__vslot47");
asm(".globl IRTrinary__new_108350");
asm(".set IRTrinary__new_108350, _IRTrinary__new_108350");
asm(".globl IRLoadConst__vslot49");
asm(".set IRLoadConst__vslot49, _IRLoadConst__vslot49");
asm(".globl IRMov__new_1084b8");
asm(".set IRMov__new_1084b8, _IRMov__new_1084b8");
asm(".globl IRLoadConst__vslot45");
asm(".set IRLoadConst__vslot45, _IRLoadConst__vslot45");
asm(".globl IRLoadConst__vslot77");
asm(".set IRLoadConst__vslot77, _IRLoadConst__vslot77");
asm(".globl IRLoadConst__vslot53");
asm(".set IRLoadConst__vslot53, _IRLoadConst__vslot53");
asm(".globl IRLoadConst__vslot63");
asm(".set IRLoadConst__vslot63, _IRLoadConst__vslot63");
