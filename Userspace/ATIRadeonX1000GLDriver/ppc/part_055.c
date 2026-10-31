#include "decls.h"

/* FuncEndBlock__deleting_dtor @ 0x1cdf4c (104 bytes) */
int FuncEndBlock__deleting_dtor(this)
  undefined4 *this;
{
  *this = &ptrTo_FuncEndBlock__dtor_001e9b60;
  Block__dtor_ea270(this);
  if (this != (undefined4 *)0x0) {
    Arena__free(this[-1],this + -1);
    return;
  }
  return;
}

/* LoopHeader__dtor @ 0x1cdfb4 (36 bytes) */
int LoopHeader__dtor(this)
  undefined4 *this;
{
  *this = &ptrTo_LoopHeader__dtor_001e9bb8;
  return Block__dtor_ea270(this);
}

/* LoopHeader__deleting_dtor @ 0x1cdfd8 (104 bytes) */
int LoopHeader__deleting_dtor(this)
  undefined4 *this;
{
  *this = &ptrTo_LoopHeader__dtor_001e9bb8;
  Block__dtor_ea270(this);
  if (this != (undefined4 *)0x0) {
    Arena__free(this[-1],this + -1);
    return;
  }
  return;
}

/* LoopFooter__dtor @ 0x1ce040 (36 bytes) */
int LoopFooter__dtor(this)
  undefined4 *this;
{
  *this = &ptrTo_LoopFooter__dtor_001e9c10;
  return Block__dtor_ea270(this);
}

/* LoopFooter__deleting_dtor @ 0x1ce064 (104 bytes) */
int LoopFooter__deleting_dtor(this)
  undefined4 *this;
{
  *this = &ptrTo_LoopFooter__dtor_001e9c10;
  Block__dtor_ea270(this);
  if (this != (undefined4 *)0x0) {
    Arena__free(this[-1],this + -1);
    return;
  }
  return;
}

/* PostLoopFooter__dtor @ 0x1ce0cc (36 bytes) */
int PostLoopFooter__dtor(this)
  undefined4 *this;
{
  *this = &ptrTo_PostLoopFooter__dtor_001e9c68;
  return Block__dtor_ea270(this);
}

/* PostLoopFooter__deleting_dtor @ 0x1ce0f0 (104 bytes) */
int PostLoopFooter__deleting_dtor(this)
  undefined4 *this;
{
  *this = &ptrTo_PostLoopFooter__dtor_001e9c68;
  Block__dtor_ea270(this);
  if (this != (undefined4 *)0x0) {
    Arena__free(this[-1],this + -1);
    return;
  }
  return;
}

/* IfHeader__dtor_1ce158 @ 0x1ce158 (36 bytes) */
int IfHeader__dtor_1ce158(this)
  undefined4 *this;
{
  *this = &ptrTo_IfHeader__dtor_1ce158_001e9cc0;
  return Block__dtor_ea270(this);
}

/* IfHeader__deleting_dtor @ 0x1ce17c (104 bytes) */
int IfHeader__deleting_dtor(this)
  undefined4 *this;
{
  *this = &ptrTo_IfHeader__dtor_1ce158_001e9cc0;
  Block__dtor_ea270(this);
  if (this != (undefined4 *)0x0) {
    Arena__free(this[-1],this + -1);
    return;
  }
  return;
}

/* IfHeader__dtor_1ce1e4 @ 0x1ce1e4 (36 bytes) */
int IfHeader__dtor_1ce1e4(this)
  undefined4 *this;
{
  *this = &ptrTo_IfHeader__dtor_1ce158_001e9cc0;
  return Block__dtor_ea270(this);
}

/* IfHeader__dtor_1ce208 @ 0x1ce208 (104 bytes) */
int IfHeader__dtor_1ce208(this)
  undefined4 *this;
{
  *this = &ptrTo_IfHeader__dtor_1ce158_001e9cc0;
  Block__dtor_ea270(this);
  if (this != (undefined4 *)0x0) {
    Arena__free(this[-1],this + -1);
    return;
  }
  return;
}

/* IfFooter__dtor_1ce270 @ 0x1ce270 (36 bytes) */
int IfFooter__dtor_1ce270(this)
  undefined4 *this;
{
  *this = &ptrTo_IfFooter__dtor_1ce270_001e9d70;
  return Block__dtor_ea270(this);
}

/* IfFooter__deleting_dtor @ 0x1ce294 (104 bytes) */
int IfFooter__deleting_dtor(this)
  undefined4 *this;
{
  *this = &ptrTo_IfFooter__dtor_1ce270_001e9d70;
  Block__dtor_ea270(this);
  if (this != (undefined4 *)0x0) {
    Arena__free(this[-1],this + -1);
    return;
  }
  return;
}

/* IfFooter__dtor_1ce2fc @ 0x1ce2fc (36 bytes) */
int IfFooter__dtor_1ce2fc(this)
  undefined4 *this;
{
  *this = &ptrTo_IfFooter__dtor_1ce270_001e9d70;
  return Block__dtor_ea270(this);
}

/* IfFooter__dtor_1ce320 @ 0x1ce320 (104 bytes) */
int IfFooter__dtor_1ce320(this)
  undefined4 *this;
{
  *this = &ptrTo_IfFooter__dtor_1ce270_001e9d70;
  Block__dtor_ea270(this);
  if (this != (undefined4 *)0x0) {
    Arena__free(this[-1],this + -1);
    return;
  }
  return;
}

/* BreakOrContinueBlock__dtor @ 0x1ce388 (36 bytes) */
int BreakOrContinueBlock__dtor(this)
  undefined4 *this;
{
  *this = PTR_DAT_001e8b54 + 8;
  return Block__dtor_ea270(this);
}

/* BreakOrContinueBlock__deleting_dtor @ 0x1ce3ac (104 bytes) */
int BreakOrContinueBlock__deleting_dtor(this)
  undefined4 *this;
{
  *this = PTR_DAT_001e8b54 + 8;
  Block__dtor_ea270(this);
  if (this != (undefined4 *)0x0) {
    Arena__free(this[-1],this + -1);
    return;
  }
  return;
}

/* ContinueBlock__deleting_dtor @ 0x1ce414 (120 bytes) */
int ContinueBlock__deleting_dtor(this)
  undefined4 *this;
{
  undefined *vtable;
  
  vtable = PTR_DAT_001e8b54 + 8;
  *this = &ptrTo_ContinueBlock__dtor_001e9e78;
  *this = vtable;
  Block__dtor_ea270(this);
  if (this != (undefined4 *)0x0) {
    Arena__free(this[-1],this + -1);
    return;
  }
  return;
}

/* ExitBlock__dtor @ 0x1ce48c (36 bytes) */
int ExitBlock__dtor(this)
  undefined4 *this;
{
  *this = &ptrTo_ExitBlock__dtor_001e9ed0;
  return Block__dtor_ea270(this);
}

/* ExitBlock__deleting_dtor @ 0x1ce4b0 (104 bytes) */
int ExitBlock__deleting_dtor(this)
  undefined4 *this;
{
  *this = &ptrTo_ExitBlock__dtor_001e9ed0;
  Block__dtor_ea270(this);
  if (this != (undefined4 *)0x0) {
    Arena__free(this[-1],this + -1);
    return;
  }
  return;
}

/* EntryBlock__dtor @ 0x1ce518 (36 bytes) */
int EntryBlock__dtor(this)
  undefined4 *this;
{
  *this = &ptrTo_EntryBlock__dtor_001e9f28;
  return Block__dtor_ea270(this);
}

/* BreakBlock__dtor @ 0x1ce53c (52 bytes) */
int BreakBlock__dtor(this)
  undefined4 *this;
{
  undefined *vtable;
  
  vtable = PTR_DAT_001e8b54 + 8;
  *this = &ptrTo_BreakBlock__dtor_001e9e20;
  *this = vtable;
  return Block__dtor_ea270(this);
}

/* BreakBlock__deleting_dtor @ 0x1ce570 (120 bytes) */
int BreakBlock__deleting_dtor(this)
  undefined4 *this;
{
  undefined *vtable;
  
  vtable = PTR_DAT_001e8b54 + 8;
  *this = &ptrTo_BreakBlock__dtor_001e9e20;
  *this = vtable;
  Block__dtor_ea270(this);
  if (this != (undefined4 *)0x0) {
    Arena__free(this[-1],this + -1);
    return;
  }
  return;
}

/* ContinueBlock__dtor @ 0x1ce5e8 (52 bytes) */
int ContinueBlock__dtor(this)
  undefined4 *this;
{
  undefined *vtable;
  
  vtable = PTR_DAT_001e8b54 + 8;
  *this = &ptrTo_ContinueBlock__dtor_001e9e78;
  *this = vtable;
  return Block__dtor_ea270(this);
}

/* IREntry__getKindName @ 0x1ce6b4 (28 bytes) */
int IREntry__getKindName()
{
  return "entry";
}

/* IRExit__getKindName @ 0x1ce6d8 (28 bytes) */
int IRExit__getKindName()
{
  return "exit";
}

/* IRLoad__getKindName @ 0x1ce6fc (28 bytes) */
int IRLoad__getKindName()
{
  return "load";
}

/* IRLoadMemBuffer__getKindName @ 0x1ce718 (28 bytes) */
int IRLoadMemBuffer__getKindName()
{
  return "buffer";
}

/* IRLoadMemBufferIndex__getKindName @ 0x1ce734 (28 bytes) */
int IRLoadMemBufferIndex__getKindName()
{
  return "buffer_index";
}

/* IRImmedConstBuff__getKindName @ 0x1ce750 (28 bytes) */
int IRImmedConstBuff__getKindName()
{
  return "icb";
}

/* IRLoadConst__getKindName @ 0x1ce774 (28 bytes) */
int IRLoadConst__getKindName()
{
  return "load const";
}

/* IRLoadTemp__getKindName @ 0x1ce798 (28 bytes) */
int IRLoadTemp__getKindName()
{
  return "load temp";
}

/* IRLoadVertex__getKindName @ 0x1ce7b4 (28 bytes) */
int IRLoadVertex__getKindName()
{
  return "load v";
}

/* IRLoadInterp__getKindName @ 0x1ce7d8 (28 bytes) */
int IRLoadInterp__getKindName()
{
  return "load interp";
}

/* IRUndefined__getKindName @ 0x1ce800 (28 bytes) */
int IRUndefined__getKindName()
{
  return "ir_undefined";
}

/* IRMerge__getKindName @ 0x1ce81c (28 bytes) */
int IRMerge__getKindName()
{
  return "merge";
}

/* IRProjection__getKindName @ 0x1ce860 (28 bytes) */
int IRProjection__getKindName()
{
  return "ir_projection";
}

/* IRPresub1__getKindName @ 0x1ce894 (28 bytes) */
int IRPresub1__getKindName()
{
  return "ir_presub1";
}

/* IRPresub2__getKindName @ 0x1ce8d8 (28 bytes) */
int IRPresub2__getKindName()
{
  return "ir_presub2";
}

/* IRMix__getKindName @ 0x1ce91c (28 bytes) */
int IRMix__getKindName()
{
  return "ir_mix";
}

/* IRPhiNode__getKindName @ 0x1ce95c (28 bytes) */
int IRPhiNode__getKindName()
{
  return "phi";
}

/* IRAlu__getKindName @ 0x1ce9b4 (28 bytes) */
int IRAlu__getKindName()
{
  return "alu";
}

/* IRFetch__getKindName @ 0x1cea24 (28 bytes) */
int IRFetch__getKindName()
{
  return "fetch";
}

/* IRCmp2__getKindName @ 0x1cebb4 (28 bytes) */
int IRCmp2__getKindName()
{
  return "ir_cmp2";
}

/* IRCmp1S__getKindName @ 0x1cebe4 (28 bytes) */
int IRCmp1S__getKindName()
{
  return "ir_cmp1s";
}

/* IRLoopStart__getKindName @ 0x1cec50 (28 bytes) */
int IRLoopStart__getKindName()
{
  return "ir_loop";
}

/* IRInst__dtor_1cecc0 @ 0x1cecc0 (52 bytes) */
int IRInst__dtor_1cecc0(this)
  undefined4 *this;
{
  undefined *vtable;
  
  vtable = PTR_DAT_001e8b48 + 8;
  *this = &ptrTo_IRInst__dtor_1ced3c_001e9fc8;
  *this = vtable;
  return;
}

/* IRInst__dtor_1cecf4 @ 0x1cecf4 (72 bytes) */
int IRInst__dtor_1cecf4(this)
  undefined4 *this;
{
  undefined *vtable;
  
  vtable = PTR_DAT_001e8b48 + 8;
  *this = &ptrTo_IRInst__dtor_1ced3c_001e9fc8;
  *this = vtable;
  if (this == (undefined4 *)0x0) {
    return;
  }
  return Arena__free(this[-1],this + -1);
}

/* IRInst__dtor_1ced3c @ 0x1ced3c (52 bytes) */
int IRInst__dtor_1ced3c(this)
  undefined4 *this;
{
  undefined *vtable;
  
  vtable = PTR_DAT_001e8b48 + 8;
  *this = &ptrTo_IRInst__dtor_1ced3c_001e9fc8;
  *this = vtable;
  return;
}

/* IRInst__deleting_dtor @ 0x1ced70 (72 bytes) */
int IRInst__deleting_dtor(this)
  undefined4 *this;
{
  undefined *vtable;
  
  vtable = PTR_DAT_001e8b48 + 8;
  *this = &ptrTo_IRInst__dtor_1ced3c_001e9fc8;
  *this = vtable;
  if (this == (undefined4 *)0x0) {
    return;
  }
  return Arena__free(this[-1],this + -1);
}

/* IRInst__dtor_1cedb8 @ 0x1cedb8 (52 bytes) */
int IRInst__dtor_1cedb8(this)
  undefined4 *this;
{
  undefined *vtable;
  
  vtable = PTR_DAT_001e8b48 + 8;
  *this = &ptrTo_IRInst__dtor_1ced3c_001e9fc8;
  *this = vtable;
  return;
}

/* IRInst__dtor_1cedec @ 0x1cedec (72 bytes) */
int IRInst__dtor_1cedec(this)
  undefined4 *this;
{
  undefined *vtable;
  
  vtable = PTR_DAT_001e8b48 + 8;
  *this = &ptrTo_IRInst__dtor_1ced3c_001e9fc8;
  *this = vtable;
  if (this == (undefined4 *)0x0) {
    return;
  }
  return Arena__free(this[-1],this + -1);
}

/* IRInst__dtor_1cee34 @ 0x1cee34 (72 bytes) */
int IRInst__dtor_1cee34(this)
  undefined4 *this;
{
  undefined *vtable;
  
  vtable = PTR_DAT_001e8b48 + 8;
  *this = &ptrTo_IRInst__dtor_1ced3c_001e9fc8;
  *this = vtable;
  if (this == (undefined4 *)0x0) {
    return;
  }
  return Arena__free(this[-1],this + -1);
}

/* IRInst__dtor_1cee7c @ 0x1cee7c (72 bytes) */
int IRInst__dtor_1cee7c(this)
  undefined4 *this;
{
  undefined *vtable;
  
  vtable = PTR_DAT_001e8b48 + 8;
  *this = &ptrTo_IRInst__dtor_1ced3c_001e9fc8;
  *this = vtable;
  if (this == (undefined4 *)0x0) {
    return;
  }
  return Arena__free(this[-1],this + -1);
}

/* IRInst__dtor_1ceec4 @ 0x1ceec4 (72 bytes) */
int IRInst__dtor_1ceec4(this)
  undefined4 *this;
{
  undefined *vtable;
  
  vtable = PTR_DAT_001e8b48 + 8;
  *this = &ptrTo_IRInst__dtor_1ced3c_001e9fc8;
  *this = vtable;
  if (this == (undefined4 *)0x0) {
    return;
  }
  return Arena__free(this[-1],this + -1);
}

/* IRInst__dtor_1cef0c @ 0x1cef0c (52 bytes) */
int IRInst__dtor_1cef0c(this)
  undefined4 *this;
{
  undefined *vtable;
  
  vtable = PTR_DAT_001e8b48 + 8;
  *this = &ptrTo_IRInst__dtor_1ced3c_001e9fc8;
  *this = vtable;
  return;
}

/* IRInst__dtor_1cef40 @ 0x1cef40 (52 bytes) */
int IRInst__dtor_1cef40(this)
  undefined4 *this;
{
  undefined *vtable;
  
  vtable = PTR_DAT_001e8b48 + 8;
  *this = &ptrTo_IRInst__dtor_1ced3c_001e9fc8;
  *this = vtable;
  return;
}

/* IRInst__dtor_1cef74 @ 0x1cef74 (72 bytes) */
int IRInst__dtor_1cef74(this)
  undefined4 *this;
{
  undefined *vtable;
  
  vtable = PTR_DAT_001e8b48 + 8;
  *this = &ptrTo_IRInst__dtor_1ced3c_001e9fc8;
  *this = vtable;
  if (this == (undefined4 *)0x0) {
    return;
  }
  return Arena__free(this[-1],this + -1);
}

/* IRInst__dtor_1cefbc @ 0x1cefbc (52 bytes) */
int IRInst__dtor_1cefbc(this)
  undefined4 *this;
{
  undefined *vtable;
  
  vtable = PTR_DAT_001e8b48 + 8;
  *this = &ptrTo_IRInst__dtor_1ced3c_001e9fc8;
  *this = vtable;
  return;
}

/* IRInst__dtor_1ceff0 @ 0x1ceff0 (72 bytes) */
int IRInst__dtor_1ceff0(this2)
  undefined4 *this2;
{
  undefined *vtable;
  
  vtable = PTR_DAT_001e8b48 + 8;
  *this2 = &ptrTo_IRInst__dtor_1ced3c_001e9fc8;
  *this2 = vtable;
  if (this2 == (undefined4 *)0x0) {
    return;
  }
  return Arena__free(this2[-1],this2 + -1);
}


/* issue: auto-generated aliases bridging data.s/code.s references (written
 * without a leading underscore, matching the raw stock-binary symbol name)
 * against the real compiled C symbols (gcc adds one underscore automatically).
 * Needed because ld64 (required for this PPC binary's size - stock ld breaks on
 * large PPC links) does not silently reconcile this the way stock ld did. */
asm(".globl FuncEndBlock__deleting_dtor");
asm(".set FuncEndBlock__deleting_dtor, _FuncEndBlock__deleting_dtor");
asm(".globl LoopHeader__dtor");
asm(".set LoopHeader__dtor, _LoopHeader__dtor");
asm(".globl LoopHeader__deleting_dtor");
asm(".set LoopHeader__deleting_dtor, _LoopHeader__deleting_dtor");
asm(".globl LoopFooter__dtor");
asm(".set LoopFooter__dtor, _LoopFooter__dtor");
asm(".globl LoopFooter__deleting_dtor");
asm(".set LoopFooter__deleting_dtor, _LoopFooter__deleting_dtor");
asm(".globl PostLoopFooter__dtor");
asm(".set PostLoopFooter__dtor, _PostLoopFooter__dtor");
asm(".globl PostLoopFooter__deleting_dtor");
asm(".set PostLoopFooter__deleting_dtor, _PostLoopFooter__deleting_dtor");
asm(".globl IfHeader__dtor_1ce158");
asm(".set IfHeader__dtor_1ce158, _IfHeader__dtor_1ce158");
asm(".globl IfHeader__deleting_dtor");
asm(".set IfHeader__deleting_dtor, _IfHeader__deleting_dtor");
asm(".globl IfHeader__dtor_1ce1e4");
asm(".set IfHeader__dtor_1ce1e4, _IfHeader__dtor_1ce1e4");
asm(".globl IfHeader__dtor_1ce208");
asm(".set IfHeader__dtor_1ce208, _IfHeader__dtor_1ce208");
asm(".globl IfFooter__dtor_1ce270");
asm(".set IfFooter__dtor_1ce270, _IfFooter__dtor_1ce270");
asm(".globl IfFooter__deleting_dtor");
asm(".set IfFooter__deleting_dtor, _IfFooter__deleting_dtor");
asm(".globl IfFooter__dtor_1ce2fc");
asm(".set IfFooter__dtor_1ce2fc, _IfFooter__dtor_1ce2fc");
asm(".globl IfFooter__dtor_1ce320");
asm(".set IfFooter__dtor_1ce320, _IfFooter__dtor_1ce320");
asm(".globl BreakOrContinueBlock__dtor");
asm(".set BreakOrContinueBlock__dtor, _BreakOrContinueBlock__dtor");
asm(".globl BreakOrContinueBlock__deleting_dtor");
asm(".set BreakOrContinueBlock__deleting_dtor, _BreakOrContinueBlock__deleting_dtor");
asm(".globl ContinueBlock__deleting_dtor");
asm(".set ContinueBlock__deleting_dtor, _ContinueBlock__deleting_dtor");
asm(".globl ExitBlock__dtor");
asm(".set ExitBlock__dtor, _ExitBlock__dtor");
asm(".globl ExitBlock__deleting_dtor");
asm(".set ExitBlock__deleting_dtor, _ExitBlock__deleting_dtor");
asm(".globl EntryBlock__dtor");
asm(".set EntryBlock__dtor, _EntryBlock__dtor");
asm(".globl BreakBlock__dtor");
asm(".set BreakBlock__dtor, _BreakBlock__dtor");
asm(".globl BreakBlock__deleting_dtor");
asm(".set BreakBlock__deleting_dtor, _BreakBlock__deleting_dtor");
asm(".globl ContinueBlock__dtor");
asm(".set ContinueBlock__dtor, _ContinueBlock__dtor");
asm(".globl IREntry__getKindName");
asm(".set IREntry__getKindName, _IREntry__getKindName");
asm(".globl IRExit__getKindName");
asm(".set IRExit__getKindName, _IRExit__getKindName");
asm(".globl IRLoad__getKindName");
asm(".set IRLoad__getKindName, _IRLoad__getKindName");
asm(".globl IRLoadMemBuffer__getKindName");
asm(".set IRLoadMemBuffer__getKindName, _IRLoadMemBuffer__getKindName");
asm(".globl IRLoadMemBufferIndex__getKindName");
asm(".set IRLoadMemBufferIndex__getKindName, _IRLoadMemBufferIndex__getKindName");
asm(".globl IRImmedConstBuff__getKindName");
asm(".set IRImmedConstBuff__getKindName, _IRImmedConstBuff__getKindName");
asm(".globl IRLoadConst__getKindName");
asm(".set IRLoadConst__getKindName, _IRLoadConst__getKindName");
asm(".globl IRLoadTemp__getKindName");
asm(".set IRLoadTemp__getKindName, _IRLoadTemp__getKindName");
asm(".globl IRLoadVertex__getKindName");
asm(".set IRLoadVertex__getKindName, _IRLoadVertex__getKindName");
asm(".globl IRLoadInterp__getKindName");
asm(".set IRLoadInterp__getKindName, _IRLoadInterp__getKindName");
asm(".globl IRUndefined__getKindName");
asm(".set IRUndefined__getKindName, _IRUndefined__getKindName");
asm(".globl IRMerge__getKindName");
asm(".set IRMerge__getKindName, _IRMerge__getKindName");
asm(".globl IRProjection__getKindName");
asm(".set IRProjection__getKindName, _IRProjection__getKindName");
asm(".globl IRPresub1__getKindName");
asm(".set IRPresub1__getKindName, _IRPresub1__getKindName");
asm(".globl IRPresub2__getKindName");
asm(".set IRPresub2__getKindName, _IRPresub2__getKindName");
asm(".globl IRMix__getKindName");
asm(".set IRMix__getKindName, _IRMix__getKindName");
asm(".globl IRPhiNode__getKindName");
asm(".set IRPhiNode__getKindName, _IRPhiNode__getKindName");
asm(".globl IRAlu__getKindName");
asm(".set IRAlu__getKindName, _IRAlu__getKindName");
asm(".globl IRFetch__getKindName");
asm(".set IRFetch__getKindName, _IRFetch__getKindName");
asm(".globl IRCmp2__getKindName");
asm(".set IRCmp2__getKindName, _IRCmp2__getKindName");
asm(".globl IRCmp1S__getKindName");
asm(".set IRCmp1S__getKindName, _IRCmp1S__getKindName");
asm(".globl IRLoopStart__getKindName");
asm(".set IRLoopStart__getKindName, _IRLoopStart__getKindName");
asm(".globl IRInst__dtor_1cecc0");
asm(".set IRInst__dtor_1cecc0, _IRInst__dtor_1cecc0");
asm(".globl IRInst__dtor_1cecf4");
asm(".set IRInst__dtor_1cecf4, _IRInst__dtor_1cecf4");
asm(".globl IRInst__dtor_1ced3c");
asm(".set IRInst__dtor_1ced3c, _IRInst__dtor_1ced3c");
asm(".globl IRInst__deleting_dtor");
asm(".set IRInst__deleting_dtor, _IRInst__deleting_dtor");
asm(".globl IRInst__dtor_1cedb8");
asm(".set IRInst__dtor_1cedb8, _IRInst__dtor_1cedb8");
asm(".globl IRInst__dtor_1cedec");
asm(".set IRInst__dtor_1cedec, _IRInst__dtor_1cedec");
asm(".globl IRInst__dtor_1cee34");
asm(".set IRInst__dtor_1cee34, _IRInst__dtor_1cee34");
asm(".globl IRInst__dtor_1cee7c");
asm(".set IRInst__dtor_1cee7c, _IRInst__dtor_1cee7c");
asm(".globl IRInst__dtor_1ceec4");
asm(".set IRInst__dtor_1ceec4, _IRInst__dtor_1ceec4");
asm(".globl IRInst__dtor_1cef0c");
asm(".set IRInst__dtor_1cef0c, _IRInst__dtor_1cef0c");
asm(".globl IRInst__dtor_1cef40");
asm(".set IRInst__dtor_1cef40, _IRInst__dtor_1cef40");
asm(".globl IRInst__dtor_1cef74");
asm(".set IRInst__dtor_1cef74, _IRInst__dtor_1cef74");
asm(".globl IRInst__dtor_1cefbc");
asm(".set IRInst__dtor_1cefbc, _IRInst__dtor_1cefbc");
asm(".globl IRInst__dtor_1ceff0");
asm(".set IRInst__dtor_1ceff0, _IRInst__dtor_1ceff0");
