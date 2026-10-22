#include "decls.h"

/* FuncEndBlock__deleting_dtor @ 0x1cdf4c (104 bytes) */
int FuncEndBlock__deleting_dtor(this)
  undefined4 *this;
{
  *this = &PTR_FUN_001e9b60;
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
  *this = &PTR_FUN_001e9bb8;
  return Block__dtor_ea270(this);
}

/* LoopHeader__deleting_dtor @ 0x1cdfd8 (104 bytes) */
int LoopHeader__deleting_dtor(this)
  undefined4 *this;
{
  *this = &PTR_FUN_001e9bb8;
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
  *this = &PTR_FUN_001e9c10;
  return Block__dtor_ea270(this);
}

/* LoopFooter__deleting_dtor @ 0x1ce064 (104 bytes) */
int LoopFooter__deleting_dtor(this)
  undefined4 *this;
{
  *this = &PTR_FUN_001e9c10;
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
  *this = &PTR_FUN_001e9c68;
  return Block__dtor_ea270(this);
}

/* PostLoopFooter__deleting_dtor @ 0x1ce0f0 (104 bytes) */
int PostLoopFooter__deleting_dtor(this)
  undefined4 *this;
{
  *this = &PTR_FUN_001e9c68;
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
  *this = &PTR_FUN_001e9cc0;
  return Block__dtor_ea270(this);
}

/* IfHeader__deleting_dtor @ 0x1ce17c (104 bytes) */
int IfHeader__deleting_dtor(this)
  undefined4 *this;
{
  *this = &PTR_FUN_001e9cc0;
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
  *this = &PTR_FUN_001e9cc0;
  return Block__dtor_ea270(this);
}

/* IfHeader__dtor_1ce208 @ 0x1ce208 (104 bytes) */
int IfHeader__dtor_1ce208(this)
  undefined4 *this;
{
  *this = &PTR_FUN_001e9cc0;
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
  *this = &PTR_FUN_001e9d70;
  return Block__dtor_ea270(this);
}

/* IfFooter__deleting_dtor @ 0x1ce294 (104 bytes) */
int IfFooter__deleting_dtor(this)
  undefined4 *this;
{
  *this = &PTR_FUN_001e9d70;
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
  *this = &PTR_FUN_001e9d70;
  return Block__dtor_ea270(this);
}

/* IfFooter__dtor_1ce320 @ 0x1ce320 (104 bytes) */
int IfFooter__dtor_1ce320(this)
  undefined4 *this;
{
  *this = &PTR_FUN_001e9d70;
  Block__dtor_ea270(this);
  if (this != (undefined4 *)0x0) {
    Arena__free(this[-1],this + -1);
    return;
  }
  return;
}

/* BreakOrContinueBlock__dtor @ 0x1ce388 (36 bytes) */
int BreakOrContinueBlock__dtor(param_1)
  undefined4 *param_1;
{
  *param_1 = PTR_DAT_001e8b54 + 8;
  return Block__dtor_ea270(param_1);
}

/* BreakOrContinueBlock__deleting_dtor @ 0x1ce3ac (104 bytes) */
int BreakOrContinueBlock__deleting_dtor(param_1)
  undefined4 *param_1;
{
  *param_1 = PTR_DAT_001e8b54 + 8;
  Block__dtor_ea270(param_1);
  if (param_1 != (undefined4 *)0x0) {
    Arena__free(param_1[-1],param_1 + -1);
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
  *this = &PTR_FUN_001e9e78;
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
  *this = &PTR_FUN_001e9ed0;
  return Block__dtor_ea270(this);
}

/* ExitBlock__deleting_dtor @ 0x1ce4b0 (104 bytes) */
int ExitBlock__deleting_dtor(this)
  undefined4 *this;
{
  *this = &PTR_FUN_001e9ed0;
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
  *this = &PTR_FUN_001e9f28;
  return Block__dtor_ea270(this);
}

/* BreakBlock__dtor @ 0x1ce53c (52 bytes) */
int BreakBlock__dtor(this)
  undefined4 *this;
{
  undefined *vtable;
  
  vtable = PTR_DAT_001e8b54 + 8;
  *this = &PTR_FUN_001e9e20;
  *this = vtable;
  return Block__dtor_ea270(this);
}

/* BreakBlock__deleting_dtor @ 0x1ce570 (120 bytes) */
int BreakBlock__deleting_dtor(this)
  undefined4 *this;
{
  undefined *vtable;
  
  vtable = PTR_DAT_001e8b54 + 8;
  *this = &PTR_FUN_001e9e20;
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
  *this = &PTR_FUN_001e9e78;
  *this = vtable;
  return Block__dtor_ea270(this);
}

/* FUN_001ce6b4 @ 0x1ce6b4 (28 bytes) */
int FUN_001ce6b4()
{
  return "entry";
}

/* FUN_001ce6d8 @ 0x1ce6d8 (28 bytes) */
int FUN_001ce6d8()
{
  return "exit";
}

/* FUN_001ce6fc @ 0x1ce6fc (28 bytes) */
int FUN_001ce6fc()
{
  return "load";
}

/* FUN_001ce718 @ 0x1ce718 (28 bytes) */
int FUN_001ce718()
{
  return "buffer";
}

/* FUN_001ce734 @ 0x1ce734 (28 bytes) */
int FUN_001ce734()
{
  return "buffer_index";
}

/* FUN_001ce750 @ 0x1ce750 (28 bytes) */
int FUN_001ce750()
{
  return "icb";
}

/* FUN_001ce774 @ 0x1ce774 (28 bytes) */
int FUN_001ce774()
{
  return "load const";
}

/* FUN_001ce798 @ 0x1ce798 (28 bytes) */
int FUN_001ce798()
{
  return "load temp";
}

/* FUN_001ce7b4 @ 0x1ce7b4 (28 bytes) */
int FUN_001ce7b4()
{
  return "load v";
}

/* FUN_001ce7d8 @ 0x1ce7d8 (28 bytes) */
int FUN_001ce7d8()
{
  return "load interp";
}

/* FUN_001ce800 @ 0x1ce800 (28 bytes) */
int FUN_001ce800()
{
  return "ir_undefined";
}

/* FUN_001ce81c @ 0x1ce81c (28 bytes) */
int FUN_001ce81c()
{
  return "merge";
}

/* FUN_001ce860 @ 0x1ce860 (28 bytes) */
int FUN_001ce860()
{
  return "ir_projection";
}

/* FUN_001ce894 @ 0x1ce894 (28 bytes) */
int FUN_001ce894()
{
  return "ir_presub1";
}

/* FUN_001ce8d8 @ 0x1ce8d8 (28 bytes) */
int FUN_001ce8d8()
{
  return "ir_presub2";
}

/* FUN_001ce91c @ 0x1ce91c (28 bytes) */
int FUN_001ce91c()
{
  return "ir_mix";
}

/* FUN_001ce95c @ 0x1ce95c (28 bytes) */
int FUN_001ce95c()
{
  return "phi";
}

/* FUN_001ce9b4 @ 0x1ce9b4 (28 bytes) */
int FUN_001ce9b4()
{
  return "alu";
}

/* FUN_001cea24 @ 0x1cea24 (28 bytes) */
int FUN_001cea24()
{
  return "fetch";
}

/* FUN_001cebb4 @ 0x1cebb4 (28 bytes) */
int FUN_001cebb4()
{
  return "ir_cmp2";
}

/* FUN_001cebe4 @ 0x1cebe4 (28 bytes) */
int FUN_001cebe4()
{
  return "ir_cmp1s";
}

/* FUN_001cec50 @ 0x1cec50 (28 bytes) */
int FUN_001cec50()
{
  return "ir_loop";
}

/* IRInst__dtor_1cecc0 @ 0x1cecc0 (52 bytes) */
int IRInst__dtor_1cecc0(this)
  undefined4 *this;
{
  undefined *vtable;
  
  vtable = PTR_DAT_001e8b48 + 8;
  *this = &PTR_FUN_001e9fc8;
  *this = vtable;
  return;
}

/* IRInst__dtor_1cecf4 @ 0x1cecf4 (72 bytes) */
int IRInst__dtor_1cecf4(this)
  undefined4 *this;
{
  undefined *vtable;
  
  vtable = PTR_DAT_001e8b48 + 8;
  *this = &PTR_FUN_001e9fc8;
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
  *this = &PTR_FUN_001e9fc8;
  *this = vtable;
  return;
}

/* IRInst__deleting_dtor @ 0x1ced70 (72 bytes) */
int IRInst__deleting_dtor(this)
  undefined4 *this;
{
  undefined *vtable;
  
  vtable = PTR_DAT_001e8b48 + 8;
  *this = &PTR_FUN_001e9fc8;
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
  *this = &PTR_FUN_001e9fc8;
  *this = vtable;
  return;
}

/* IRInst__dtor_1cedec @ 0x1cedec (72 bytes) */
int IRInst__dtor_1cedec(this)
  undefined4 *this;
{
  undefined *vtable;
  
  vtable = PTR_DAT_001e8b48 + 8;
  *this = &PTR_FUN_001e9fc8;
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
  *this = &PTR_FUN_001e9fc8;
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
  *this = &PTR_FUN_001e9fc8;
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
  *this = &PTR_FUN_001e9fc8;
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
  *this = &PTR_FUN_001e9fc8;
  *this = vtable;
  return;
}

/* IRInst__dtor_1cef40 @ 0x1cef40 (52 bytes) */
int IRInst__dtor_1cef40(this)
  undefined4 *this;
{
  undefined *vtable;
  
  vtable = PTR_DAT_001e8b48 + 8;
  *this = &PTR_FUN_001e9fc8;
  *this = vtable;
  return;
}

/* IRInst__dtor_1cef74 @ 0x1cef74 (72 bytes) */
int IRInst__dtor_1cef74(this)
  undefined4 *this;
{
  undefined *vtable;
  
  vtable = PTR_DAT_001e8b48 + 8;
  *this = &PTR_FUN_001e9fc8;
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
  *this = &PTR_FUN_001e9fc8;
  *this = vtable;
  return;
}

/* IRInst__dtor_1ceff0 @ 0x1ceff0 (72 bytes) */
int IRInst__dtor_1ceff0(this2)
  undefined4 *this2;
{
  undefined *vtable;
  
  vtable = PTR_DAT_001e8b48 + 8;
  *this2 = &PTR_FUN_001e9fc8;
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
asm(".globl FUN_001cdf4c");
asm(".set FUN_001cdf4c, _FuncEndBlock__deleting_dtor");
asm(".globl FUN_001cdfb4");
asm(".set FUN_001cdfb4, _LoopHeader__dtor");
asm(".globl FUN_001cdfd8");
asm(".set FUN_001cdfd8, _LoopHeader__deleting_dtor");
asm(".globl FUN_001ce040");
asm(".set FUN_001ce040, _LoopFooter__dtor");
asm(".globl FUN_001ce064");
asm(".set FUN_001ce064, _LoopFooter__deleting_dtor");
asm(".globl FUN_001ce0cc");
asm(".set FUN_001ce0cc, _PostLoopFooter__dtor");
asm(".globl FUN_001ce0f0");
asm(".set FUN_001ce0f0, _PostLoopFooter__deleting_dtor");
asm(".globl FUN_001ce158");
asm(".set FUN_001ce158, _IfHeader__dtor_1ce158");
asm(".globl FUN_001ce17c");
asm(".set FUN_001ce17c, _IfHeader__deleting_dtor");
asm(".globl FUN_001ce1e4");
asm(".set FUN_001ce1e4, _IfHeader__dtor_1ce1e4");
asm(".globl FUN_001ce208");
asm(".set FUN_001ce208, _IfHeader__dtor_1ce208");
asm(".globl FUN_001ce270");
asm(".set FUN_001ce270, _IfFooter__dtor_1ce270");
asm(".globl FUN_001ce294");
asm(".set FUN_001ce294, _IfFooter__deleting_dtor");
asm(".globl FUN_001ce2fc");
asm(".set FUN_001ce2fc, _IfFooter__dtor_1ce2fc");
asm(".globl FUN_001ce320");
asm(".set FUN_001ce320, _IfFooter__dtor_1ce320");
asm(".globl FUN_001ce388");
asm(".set FUN_001ce388, _BreakOrContinueBlock__dtor");
asm(".globl FUN_001ce3ac");
asm(".set FUN_001ce3ac, _BreakOrContinueBlock__deleting_dtor");
asm(".globl FUN_001ce414");
asm(".set FUN_001ce414, _ContinueBlock__deleting_dtor");
asm(".globl FUN_001ce48c");
asm(".set FUN_001ce48c, _ExitBlock__dtor");
asm(".globl FUN_001ce4b0");
asm(".set FUN_001ce4b0, _ExitBlock__deleting_dtor");
asm(".globl FUN_001ce518");
asm(".set FUN_001ce518, _EntryBlock__dtor");
asm(".globl FUN_001ce53c");
asm(".set FUN_001ce53c, _BreakBlock__dtor");
asm(".globl FUN_001ce570");
asm(".set FUN_001ce570, _BreakBlock__deleting_dtor");
asm(".globl FUN_001ce5e8");
asm(".set FUN_001ce5e8, _ContinueBlock__dtor");
asm(".globl FUN_001ce6b4");
asm(".set FUN_001ce6b4, _FUN_001ce6b4");
asm(".globl FUN_001ce6d8");
asm(".set FUN_001ce6d8, _FUN_001ce6d8");
asm(".globl FUN_001ce6fc");
asm(".set FUN_001ce6fc, _FUN_001ce6fc");
asm(".globl FUN_001ce718");
asm(".set FUN_001ce718, _FUN_001ce718");
asm(".globl FUN_001ce734");
asm(".set FUN_001ce734, _FUN_001ce734");
asm(".globl FUN_001ce750");
asm(".set FUN_001ce750, _FUN_001ce750");
asm(".globl FUN_001ce774");
asm(".set FUN_001ce774, _FUN_001ce774");
asm(".globl FUN_001ce798");
asm(".set FUN_001ce798, _FUN_001ce798");
asm(".globl FUN_001ce7b4");
asm(".set FUN_001ce7b4, _FUN_001ce7b4");
asm(".globl FUN_001ce7d8");
asm(".set FUN_001ce7d8, _FUN_001ce7d8");
asm(".globl FUN_001ce800");
asm(".set FUN_001ce800, _FUN_001ce800");
asm(".globl FUN_001ce81c");
asm(".set FUN_001ce81c, _FUN_001ce81c");
asm(".globl FUN_001ce860");
asm(".set FUN_001ce860, _FUN_001ce860");
asm(".globl FUN_001ce894");
asm(".set FUN_001ce894, _FUN_001ce894");
asm(".globl FUN_001ce8d8");
asm(".set FUN_001ce8d8, _FUN_001ce8d8");
asm(".globl FUN_001ce91c");
asm(".set FUN_001ce91c, _FUN_001ce91c");
asm(".globl FUN_001ce95c");
asm(".set FUN_001ce95c, _FUN_001ce95c");
asm(".globl FUN_001ce9b4");
asm(".set FUN_001ce9b4, _FUN_001ce9b4");
asm(".globl FUN_001cea24");
asm(".set FUN_001cea24, _FUN_001cea24");
asm(".globl FUN_001cebb4");
asm(".set FUN_001cebb4, _FUN_001cebb4");
asm(".globl FUN_001cebe4");
asm(".set FUN_001cebe4, _FUN_001cebe4");
asm(".globl FUN_001cec50");
asm(".set FUN_001cec50, _FUN_001cec50");
asm(".globl FUN_001cecc0");
asm(".set FUN_001cecc0, _IRInst__dtor_1cecc0");
asm(".globl FUN_001cecf4");
asm(".set FUN_001cecf4, _IRInst__dtor_1cecf4");
asm(".globl FUN_001ced3c");
asm(".set FUN_001ced3c, _IRInst__dtor_1ced3c");
asm(".globl FUN_001ced70");
asm(".set FUN_001ced70, _IRInst__deleting_dtor");
asm(".globl FUN_001cedb8");
asm(".set FUN_001cedb8, _IRInst__dtor_1cedb8");
asm(".globl FUN_001cedec");
asm(".set FUN_001cedec, _IRInst__dtor_1cedec");
asm(".globl FUN_001cee34");
asm(".set FUN_001cee34, _IRInst__dtor_1cee34");
asm(".globl FUN_001cee7c");
asm(".set FUN_001cee7c, _IRInst__dtor_1cee7c");
asm(".globl FUN_001ceec4");
asm(".set FUN_001ceec4, _IRInst__dtor_1ceec4");
asm(".globl FUN_001cef0c");
asm(".set FUN_001cef0c, _IRInst__dtor_1cef0c");
asm(".globl FUN_001cef40");
asm(".set FUN_001cef40, _IRInst__dtor_1cef40");
asm(".globl FUN_001cef74");
asm(".set FUN_001cef74, _IRInst__dtor_1cef74");
asm(".globl FUN_001cefbc");
asm(".set FUN_001cefbc, _IRInst__dtor_1cefbc");
asm(".globl FUN_001ceff0");
asm(".set FUN_001ceff0, _IRInst__dtor_1ceff0");
