#include "decls.h"

/* IrAddFloat__deleting_dtor @ 0x1d773c (52 bytes) */
int IrAddFloat__deleting_dtor(this)
  undefined4 *this;
{
  undefined *vtable;
  
  vtable = PTR_DAT_001e8f28 + 8;
  *this = PTR_DAT_001e907c + 8;
  *this = vtable;
  return operator_delete(this);
}

/* IrAlloc__dtor @ 0x1d7770 (52 bytes) */
int IrAlloc__dtor(this)
  undefined4 *this;
{
  undefined *vtable;
  
  vtable = PTR_DAT_001e8f28 + 8;
  *this = PTR_DAT_001e8f08 + 8;
  *this = vtable;
  return;
}

/* IrAlloc__deleting_dtor @ 0x1d77a4 (52 bytes) */
int IrAlloc__deleting_dtor(this)
  undefined4 *this;
{
  undefined *vtable;
  
  vtable = PTR_DAT_001e8f28 + 8;
  *this = PTR_DAT_001e8f08 + 8;
  *this = vtable;
  return operator_delete(this);
}

/* IrCondJmp__dtor @ 0x1d77d8 (52 bytes) */
int IrCondJmp__dtor(this)
  undefined4 *this;
{
  undefined *vtable;
  
  vtable = PTR_DAT_001e8f28 + 8;
  *this = PTR_DAT_001e905c + 8;
  *this = vtable;
  return;
}

/* IrCondJmp__deleting_dtor @ 0x1d780c (52 bytes) */
int IrCondJmp__deleting_dtor(this)
  undefined4 *this;
{
  undefined *vtable;
  
  vtable = PTR_DAT_001e8f28 + 8;
  *this = PTR_DAT_001e905c + 8;
  *this = vtable;
  return operator_delete(this);
}

/* IrRet__dtor @ 0x1d7840 (52 bytes) */
int IrRet__dtor(this)
  undefined4 *this;
{
  undefined *vtable;
  
  vtable = PTR_DAT_001e8f28 + 8;
  *this = PTR_DAT_001e8efc + 8;
  *this = vtable;
  return;
}

/* IrRet__deleting_dtor @ 0x1d7874 (52 bytes) */
int IrRet__deleting_dtor(this)
  undefined4 *this;
{
  undefined *vtable;
  
  vtable = PTR_DAT_001e8f28 + 8;
  *this = PTR_DAT_001e8efc + 8;
  *this = vtable;
  return operator_delete(this);
}

/* VRegInfo__dtor @ 0x1d7950 (36 bytes) */
int VRegInfo__dtor(param_1)
  undefined4 *param_1;
{
  *param_1 = PTR_DAT_001e90f0 + 8;
  return;
}

/* VRegInfo__deleting_dtor @ 0x1d7974 (56 bytes) */
int VRegInfo__deleting_dtor(param_1)
  undefined4 *param_1;
{
  *param_1 = PTR_DAT_001e90f0 + 8;
  if (param_1 == (undefined4 *)0x0) {
    return;
  }
  return Arena__free(param_1[-1],param_1 + -1);
}

/* ImmedConstBuffer__deleting_dtor @ 0x1d79ac (72 bytes) */
int ImmedConstBuffer__deleting_dtor(this)
  undefined4 *this;
{
  undefined *vtable;
  
  vtable = PTR_DAT_001e90f0 + 8;
  *this = &PTR_FUN_001ea8d0;
  *this = vtable;
  if (this == (undefined4 *)0x0) {
    return;
  }
  return Arena__free(this[-1],this + -1);
}

/* TempValue__dtor_1d79f4 @ 0x1d79f4 (72 bytes) */
int TempValue__dtor_1d79f4(this)
  undefined4 *this;
{
  undefined *vtable;
  
  vtable = PTR_DAT_001e90f0 + 8;
  *this = &PTR_FUN_001ea7b8;
  *this = vtable;
  if (this == (undefined4 *)0x0) {
    return;
  }
  return Arena__free(this[-1],this + -1);
}

/* TempValue__dtor_1d7a3c @ 0x1d7a3c (52 bytes) */
int TempValue__dtor_1d7a3c(this)
  undefined4 *this;
{
  undefined *vtable;
  
  vtable = PTR_DAT_001e90f0 + 8;
  *this = &PTR_FUN_001ea7b8;
  *this = vtable;
  return;
}

/* TempValue__dtor_1d7a70 @ 0x1d7a70 (72 bytes) */
int TempValue__dtor_1d7a70(this)
  undefined4 *this;
{
  undefined *vtable;
  
  vtable = PTR_DAT_001e90f0 + 8;
  *this = &PTR_FUN_001ea7b8;
  *this = vtable;
  if (this == (undefined4 *)0x0) {
    return;
  }
  return Arena__free(this[-1],this + -1);
}

/* TempValue__dtor_1d7ab8 @ 0x1d7ab8 (52 bytes) */
int TempValue__dtor_1d7ab8(this)
  undefined4 *this;
{
  undefined *vtable;
  
  vtable = PTR_DAT_001e90f0 + 8;
  *this = &PTR_FUN_001ea7b8;
  *this = vtable;
  return;
}

/* Physical__dtor @ 0x1d7aec (52 bytes) */
int Physical__dtor(this)
  undefined4 *this;
{
  undefined *vtable;
  
  vtable = PTR_DAT_001e90f0 + 8;
  *this = PTR_DAT_001e90d8 + 8;
  *this = vtable;
  return;
}

/* Physical__deleting_dtor @ 0x1d7b20 (72 bytes) */
int Physical__deleting_dtor(this)
  undefined4 *this;
{
  undefined *vtable;
  
  vtable = PTR_DAT_001e90f0 + 8;
  *this = PTR_DAT_001e90d8 + 8;
  *this = vtable;
  if (this == (undefined4 *)0x0) {
    return;
  }
  return Arena__free(this[-1],this + -1);
}

/* AddrIndexedSet__dtor @ 0x1d7b68 (52 bytes) */
int AddrIndexedSet__dtor(this)
  undefined4 *this;
{
  undefined *vtable;
  
  vtable = PTR_DAT_001e90f0 + 8;
  *this = PTR_DAT_001e90cc + 8;
  *this = vtable;
  return;
}

/* AddrIndexedSet__deleting_dtor @ 0x1d7b9c (72 bytes) */
int AddrIndexedSet__deleting_dtor(this)
  undefined4 *this;
{
  undefined *vtable;
  
  vtable = PTR_DAT_001e90f0 + 8;
  *this = PTR_DAT_001e90cc + 8;
  *this = vtable;
  if (this == (undefined4 *)0x0) {
    return;
  }
  return Arena__free(this[-1],this + -1);
}

/* LoopRegister__dtor @ 0x1d7be4 (52 bytes) */
int LoopRegister__dtor(this)
  undefined4 *this;
{
  undefined *vtable;
  
  vtable = PTR_DAT_001e90f0 + 8;
  *this = PTR_DAT_001e90e8 + 8;
  *this = vtable;
  return;
}

/* LoopRegister__deleting_dtor @ 0x1d7c18 (72 bytes) */
int LoopRegister__deleting_dtor(this)
  undefined4 *this;
{
  undefined *vtable;
  
  vtable = PTR_DAT_001e90f0 + 8;
  *this = PTR_DAT_001e90e8 + 8;
  *this = vtable;
  if (this == (undefined4 *)0x0) {
    return;
  }
  return Arena__free(this[-1],this + -1);
}

/* LoopIndexedSet__dtor @ 0x1d7c60 (52 bytes) */
int LoopIndexedSet__dtor(this)
  undefined4 *this;
{
  undefined *vtable;
  
  vtable = PTR_DAT_001e90f0 + 8;
  *this = PTR_DAT_001e90ec + 8;
  *this = vtable;
  return;
}

/* LoopIndexedSet__deleting_dtor @ 0x1d7c94 (72 bytes) */
int LoopIndexedSet__deleting_dtor(this)
  undefined4 *this;
{
  undefined *vtable;
  
  vtable = PTR_DAT_001e90f0 + 8;
  *this = PTR_DAT_001e90ec + 8;
  *this = vtable;
  if (this == (undefined4 *)0x0) {
    return;
  }
  return Arena__free(this[-1],this + -1);
}

/* ExportAddress__dtor @ 0x1d7cdc (52 bytes) */
int ExportAddress__dtor(this)
  undefined4 *this;
{
  undefined *vtable;
  
  vtable = PTR_DAT_001e90f0 + 8;
  *this = PTR_DAT_001e90d0 + 8;
  *this = vtable;
  return;
}

/* ExportAddress__deleting_dtor @ 0x1d7d10 (72 bytes) */
int ExportAddress__deleting_dtor(this)
  undefined4 *this;
{
  undefined *vtable;
  
  vtable = PTR_DAT_001e90f0 + 8;
  *this = PTR_DAT_001e90d0 + 8;
  *this = vtable;
  if (this == (undefined4 *)0x0) {
    return;
  }
  return Arena__free(this[-1],this + -1);
}

/* ExportValue__dtor @ 0x1d7d58 (52 bytes) */
int ExportValue__dtor(this)
  undefined4 *this;
{
  undefined *vtable;
  
  vtable = PTR_DAT_001e90f0 + 8;
  *this = &PTR_FUN_001ea748;
  *this = vtable;
  return;
}

/* ExportValue__deleting_dtor @ 0x1d7d8c (72 bytes) */
int ExportValue__deleting_dtor(this)
  undefined4 *this;
{
  undefined *vtable;
  
  vtable = PTR_DAT_001e90f0 + 8;
  *this = &PTR_FUN_001ea748;
  *this = vtable;
  if (this == (undefined4 *)0x0) {
    return;
  }
  return Arena__free(this[-1],this + -1);
}

/* Interpolator__dtor @ 0x1d7dd4 (52 bytes) */
int Interpolator__dtor(this)
  undefined4 *this;
{
  undefined *vtable;
  
  vtable = PTR_DAT_001e90f0 + 8;
  *this = &PTR_FUN_001ea780;
  *this = vtable;
  return;
}

/* Interpolator__deleting_dtor @ 0x1d7e08 (72 bytes) */
int Interpolator__deleting_dtor(this)
  undefined4 *this;
{
  undefined *vtable;
  
  vtable = PTR_DAT_001e90f0 + 8;
  *this = &PTR_FUN_001ea780;
  *this = vtable;
  if (this == (undefined4 *)0x0) {
    return;
  }
  return Arena__free(this[-1],this + -1);
}

/* TempValue__dtor_1d7e50 @ 0x1d7e50 (52 bytes) */
int TempValue__dtor_1d7e50(this)
  undefined4 *this;
{
  undefined *vtable;
  
  vtable = PTR_DAT_001e90f0 + 8;
  *this = &PTR_FUN_001ea7b8;
  *this = vtable;
  return;
}

/* TempValue__deleting_dtor @ 0x1d7e84 (72 bytes) */
int TempValue__deleting_dtor(this)
  undefined4 *this;
{
  undefined *vtable;
  
  vtable = PTR_DAT_001e90f0 + 8;
  *this = &PTR_FUN_001ea7b8;
  *this = vtable;
  if (this == (undefined4 *)0x0) {
    return;
  }
  return Arena__free(this[-1],this + -1);
}

/* ExportSlot__dtor @ 0x1d7ecc (52 bytes) */
int ExportSlot__dtor(this)
  undefined4 *this;
{
  undefined *vtable;
  
  vtable = PTR_DAT_001e90f0 + 8;
  *this = &PTR_FUN_001ea7f0;
  *this = vtable;
  return;
}

/* ExportSlot__deleting_dtor @ 0x1d7f00 (72 bytes) */
int ExportSlot__deleting_dtor(this)
  undefined4 *this;
{
  undefined *vtable;
  
  vtable = PTR_DAT_001e90f0 + 8;
  *this = &PTR_FUN_001ea7f0;
  *this = vtable;
  if (this == (undefined4 *)0x0) {
    return;
  }
  return Arena__free(this[-1],this + -1);
}

/* Resource__dtor @ 0x1d7f48 (52 bytes) */
int Resource__dtor(this)
  undefined4 *this;
{
  undefined *vtable;
  
  vtable = PTR_DAT_001e90f0 + 8;
  *this = &PTR_FUN_001ea828;
  *this = vtable;
  return;
}

/* Resource__deleting_dtor @ 0x1d7f7c (72 bytes) */
int Resource__deleting_dtor(this)
  undefined4 *this;
{
  undefined *vtable;
  
  vtable = PTR_DAT_001e90f0 + 8;
  *this = &PTR_FUN_001ea828;
  *this = vtable;
  if (this == (undefined4 *)0x0) {
    return;
  }
  return Arena__free(this[-1],this + -1);
}

/* VertexRegister__dtor @ 0x1d7fc4 (52 bytes) */
int VertexRegister__dtor(this)
  undefined4 *this;
{
  undefined *vtable;
  
  vtable = PTR_DAT_001e90f0 + 8;
  *this = &PTR_FUN_001ea860;
  *this = vtable;
  return;
}

/* VertexRegister__deleting_dtor @ 0x1d7ff8 (72 bytes) */
int VertexRegister__deleting_dtor(this)
  undefined4 *this;
{
  undefined *vtable;
  
  vtable = PTR_DAT_001e90f0 + 8;
  *this = &PTR_FUN_001ea860;
  *this = vtable;
  if (this == (undefined4 *)0x0) {
    return;
  }
  return Arena__free(this[-1],this + -1);
}

/* FixedValue__dtor @ 0x1d8040 (52 bytes) */
int FixedValue__dtor(this)
  undefined4 *this;
{
  undefined *vtable;
  
  vtable = PTR_DAT_001e90f0 + 8;
  *this = &PTR_FUN_001ea898;
  *this = vtable;
  return;
}

/* FixedValue__deleting_dtor @ 0x1d8074 (72 bytes) */
int FixedValue__deleting_dtor(this)
  undefined4 *this;
{
  undefined *vtable;
  
  vtable = PTR_DAT_001e90f0 + 8;
  *this = &PTR_FUN_001ea898;
  *this = vtable;
  if (this == (undefined4 *)0x0) {
    return;
  }
  return Arena__free(this[-1],this + -1);
}

/* ImmedConstBuffer__dtor @ 0x1d80bc (52 bytes) */
int ImmedConstBuffer__dtor(this)
  undefined4 *this;
{
  undefined *vtable;
  
  vtable = PTR_DAT_001e90f0 + 8;
  *this = &PTR_FUN_001ea8d0;
  *this = vtable;
  return;
}

/* LoopIndexedConstSet__dtor @ 0x1d80f0 (68 bytes) */
int LoopIndexedConstSet__dtor(param_1)
  undefined4 *param_1;
{
  undefined *puVar1;
  undefined *puVar2;
  
  puVar1 = PTR_DAT_001e90ec;
  *param_1 = PTR_DAT_001e90e4 + 8;
  puVar2 = PTR_DAT_001e90f0;
  *param_1 = puVar1 + 8;
  *param_1 = puVar2 + 8;
  return;
}

/* LoopIndexedConstSet__deleting_dtor @ 0x1d8134 (88 bytes) */
int LoopIndexedConstSet__deleting_dtor(param_1)
  undefined4 *param_1;
{
  undefined *puVar1;
  undefined *puVar2;
  
  puVar1 = PTR_DAT_001e90ec;
  *param_1 = PTR_DAT_001e90e4 + 8;
  puVar2 = PTR_DAT_001e90f0;
  *param_1 = puVar1 + 8;
  *param_1 = puVar2 + 8;
  if (param_1 == (undefined4 *)0x0) {
    return;
  }
  return Arena__free(param_1[-1],param_1 + -1);
}

/* LoopIndexedInputSet__dtor @ 0x1d818c (68 bytes) */
int LoopIndexedInputSet__dtor(param_1)
  undefined4 *param_1;
{
  undefined *puVar1;
  undefined *puVar2;
  
  puVar1 = PTR_DAT_001e90ec;
  *param_1 = PTR_DAT_001e90d4 + 8;
  puVar2 = PTR_DAT_001e90f0;
  *param_1 = puVar1 + 8;
  *param_1 = puVar2 + 8;
  return;
}

/* LoopIndexedInputSet__deleting_dtor @ 0x1d81d0 (88 bytes) */
int LoopIndexedInputSet__deleting_dtor(param_1)
  undefined4 *param_1;
{
  undefined *puVar1;
  undefined *puVar2;
  
  puVar1 = PTR_DAT_001e90ec;
  *param_1 = PTR_DAT_001e90d4 + 8;
  puVar2 = PTR_DAT_001e90f0;
  *param_1 = puVar1 + 8;
  *param_1 = puVar2 + 8;
  if (param_1 == (undefined4 *)0x0) {
    return;
  }
  return Arena__free(param_1[-1],param_1 + -1);
}

/* LoopIndexedOutputSet__dtor @ 0x1d8228 (68 bytes) */
int LoopIndexedOutputSet__dtor(param_1)
  undefined4 *param_1;
{
  undefined *puVar1;
  undefined *puVar2;
  
  puVar1 = PTR_DAT_001e90ec;
  *param_1 = PTR_DAT_001e90dc + 8;
  puVar2 = PTR_DAT_001e90f0;
  *param_1 = puVar1 + 8;
  *param_1 = puVar2 + 8;
  return;
}

/* LoopIndexedOutputSet__deleting_dtor @ 0x1d826c (88 bytes) */
int LoopIndexedOutputSet__deleting_dtor(param_1)
  undefined4 *param_1;
{
  undefined *puVar1;
  undefined *puVar2;
  
  puVar1 = PTR_DAT_001e90ec;
  *param_1 = PTR_DAT_001e90dc + 8;
  puVar2 = PTR_DAT_001e90f0;
  *param_1 = puVar1 + 8;
  *param_1 = puVar2 + 8;
  if (param_1 == (undefined4 *)0x0) {
    return;
  }
  return Arena__free(param_1[-1],param_1 + -1);
}

/* KhanPs__deleting_dtor @ 0x1d8318 (52 bytes) */
int KhanPs__deleting_dtor(this)
  undefined4 *this;
{
  undefined *vtable;
  
  vtable = PTR_DAT_001e9108 + 8;
  *this = &PTR_FUN_001ead88;
  *this = vtable;
  return operator_delete(this);
}

/* KhanChip__deleting_dtor @ 0x1d834c (52 bytes) */
int KhanChip__deleting_dtor(this)
  undefined4 *this;
{
  undefined *vtable;
  
  vtable = PTR_DAT_001e8c88 + 8;
  *this = &PTR_FUN_001ead68;
  *this = vtable;
  return operator_delete(this);
}

/* KhanChip__dtor @ 0x1d8380 (52 bytes) */
int KhanChip__dtor(this)
  undefined4 *this;
{
  undefined *vtable;
  
  vtable = PTR_DAT_001e8c88 + 8;
  *this = &PTR_FUN_001ead68;
  *this = vtable;
  return;
}

/* KhanPs__dtor @ 0x1d83b4 (52 bytes) */
int KhanPs__dtor(this)
  undefined4 *this;
{
  undefined *vtable;
  
  vtable = PTR_DAT_001e9108 + 8;
  *this = &PTR_FUN_001ead88;
  *this = vtable;
  return;
}

/* KhanVs__deleting_dtor_1d84ac @ 0x1d84ac (52 bytes) */
int KhanVs__deleting_dtor_1d84ac(this)
  undefined4 *this;
{
  undefined *vtable;
  
  vtable = PTR_DAT_001e9108 + 8;
  *this = &PTR_FUN_001eaf20;
  *this = vtable;
  return operator_delete(this);
}

/* KhanVs__dtor_1d84e0 @ 0x1d84e0 (52 bytes) */
int KhanVs__dtor_1d84e0(this)
  undefined4 *this;
{
  undefined *vtable;
  
  vtable = PTR_DAT_001e9108 + 8;
  *this = &PTR_FUN_001eaf20;
  *this = vtable;
  return;
}

/* KhanVs__deleting_dtor_1d8514 @ 0x1d8514 (52 bytes) */
int KhanVs__deleting_dtor_1d8514(this)
  undefined4 *this;
{
  undefined *vtable;
  
  vtable = PTR_DAT_001e9108 + 8;
  *this = &PTR_FUN_001eaf20;
  *this = vtable;
  return operator_delete(this);
}

/* KhanVs__dtor_1d8548 @ 0x1d8548 (52 bytes) */
int KhanVs__dtor_1d8548(this)
  undefined4 *this;
{
  undefined *vtable;
  
  vtable = PTR_DAT_001e9108 + 8;
  *this = &PTR_FUN_001eaf20;
  *this = vtable;
  return;
}

/* FUN_001d8584 @ 0x1d8584 (28 bytes) */
int FUN_001d8584()
{
  return "MIRROR";
}

/* MirrorBlock__deleting_dtor @ 0x1d85a0 (104 bytes) */
int MirrorBlock__deleting_dtor(param_1)
  undefined4 *param_1;
{
  *param_1 = PTR_DAT_001e9134 + 8;
  Block__dtor_ea270(param_1);
  if (param_1 != (undefined4 *)0x0) {
    Arena__free(param_1[-1],param_1 + -1);
    return;
  }
  return;
}

/* MirrorBlock__dtor @ 0x1d8608 (36 bytes) */
int MirrorBlock__dtor(param_1)
  undefined4 *param_1;
{
  *param_1 = PTR_DAT_001e9134 + 8;
  return Block__dtor_ea270(param_1);
}

/* SchedNode__dtor @ 0x1d862c (52 bytes) */
int SchedNode__dtor(this)
  undefined4 *this;
{
  undefined *vtable;
  
  vtable = PTR_DAT_001e8b48 + 8;
  *this = PTR_DAT_001e9138 + 8;
  *this = vtable;
  return;
}

/* SchedNode__deleting_dtor @ 0x1d8660 (72 bytes) */
int SchedNode__deleting_dtor(this)
  undefined4 *this;
{
  undefined *vtable;
  
  vtable = PTR_DAT_001e8b48 + 8;
  *this = PTR_DAT_001e9138 + 8;
  *this = vtable;
  if (this == (undefined4 *)0x0) {
    return;
  }
  return Arena__free(this[-1],this + -1);
}

/* ResourceModel__deleting_dtor @ 0x1d86b4 (56 bytes) */
int ResourceModel__deleting_dtor(this)
  undefined4 *this;
{
  *this = &PTR_FUN_001eb260;
  if (this == (undefined4 *)0x0) {
    return;
  }
  return Arena__free(this[-1],this + -1);
}

/* ThreadModel__deleting_dtor @ 0x1d87a8 (56 bytes) */
int ThreadModel__deleting_dtor(this2)
  undefined4 *this2;
{
  *this2 = &PTR_FUN_001eb2f0;
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
asm(".globl FUN_001d773c");
asm(".set FUN_001d773c, _IrAddFloat__deleting_dtor");
asm(".globl FUN_001d7770");
asm(".set FUN_001d7770, _IrAlloc__dtor");
asm(".globl FUN_001d77a4");
asm(".set FUN_001d77a4, _IrAlloc__deleting_dtor");
asm(".globl FUN_001d77d8");
asm(".set FUN_001d77d8, _IrCondJmp__dtor");
asm(".globl FUN_001d780c");
asm(".set FUN_001d780c, _IrCondJmp__deleting_dtor");
asm(".globl FUN_001d7840");
asm(".set FUN_001d7840, _IrRet__dtor");
asm(".globl FUN_001d7874");
asm(".set FUN_001d7874, _IrRet__deleting_dtor");
asm(".globl FUN_001d7950");
asm(".set FUN_001d7950, _VRegInfo__dtor");
asm(".globl FUN_001d7974");
asm(".set FUN_001d7974, _VRegInfo__deleting_dtor");
asm(".globl FUN_001d79ac");
asm(".set FUN_001d79ac, _ImmedConstBuffer__deleting_dtor");
asm(".globl FUN_001d79f4");
asm(".set FUN_001d79f4, _TempValue__dtor_1d79f4");
asm(".globl FUN_001d7a3c");
asm(".set FUN_001d7a3c, _TempValue__dtor_1d7a3c");
asm(".globl FUN_001d7a70");
asm(".set FUN_001d7a70, _TempValue__dtor_1d7a70");
asm(".globl FUN_001d7ab8");
asm(".set FUN_001d7ab8, _TempValue__dtor_1d7ab8");
asm(".globl FUN_001d7aec");
asm(".set FUN_001d7aec, _Physical__dtor");
asm(".globl FUN_001d7b20");
asm(".set FUN_001d7b20, _Physical__deleting_dtor");
asm(".globl FUN_001d7b68");
asm(".set FUN_001d7b68, _AddrIndexedSet__dtor");
asm(".globl FUN_001d7b9c");
asm(".set FUN_001d7b9c, _AddrIndexedSet__deleting_dtor");
asm(".globl FUN_001d7be4");
asm(".set FUN_001d7be4, _LoopRegister__dtor");
asm(".globl FUN_001d7c18");
asm(".set FUN_001d7c18, _LoopRegister__deleting_dtor");
asm(".globl FUN_001d7c60");
asm(".set FUN_001d7c60, _LoopIndexedSet__dtor");
asm(".globl FUN_001d7c94");
asm(".set FUN_001d7c94, _LoopIndexedSet__deleting_dtor");
asm(".globl FUN_001d7cdc");
asm(".set FUN_001d7cdc, _ExportAddress__dtor");
asm(".globl FUN_001d7d10");
asm(".set FUN_001d7d10, _ExportAddress__deleting_dtor");
asm(".globl FUN_001d7d58");
asm(".set FUN_001d7d58, _ExportValue__dtor");
asm(".globl FUN_001d7d8c");
asm(".set FUN_001d7d8c, _ExportValue__deleting_dtor");
asm(".globl FUN_001d7dd4");
asm(".set FUN_001d7dd4, _Interpolator__dtor");
asm(".globl FUN_001d7e08");
asm(".set FUN_001d7e08, _Interpolator__deleting_dtor");
asm(".globl FUN_001d7e50");
asm(".set FUN_001d7e50, _TempValue__dtor_1d7e50");
asm(".globl FUN_001d7e84");
asm(".set FUN_001d7e84, _TempValue__deleting_dtor");
asm(".globl FUN_001d7ecc");
asm(".set FUN_001d7ecc, _ExportSlot__dtor");
asm(".globl FUN_001d7f00");
asm(".set FUN_001d7f00, _ExportSlot__deleting_dtor");
asm(".globl FUN_001d7f48");
asm(".set FUN_001d7f48, _Resource__dtor");
asm(".globl FUN_001d7f7c");
asm(".set FUN_001d7f7c, _Resource__deleting_dtor");
asm(".globl FUN_001d7fc4");
asm(".set FUN_001d7fc4, _VertexRegister__dtor");
asm(".globl FUN_001d7ff8");
asm(".set FUN_001d7ff8, _VertexRegister__deleting_dtor");
asm(".globl FUN_001d8040");
asm(".set FUN_001d8040, _FixedValue__dtor");
asm(".globl FUN_001d8074");
asm(".set FUN_001d8074, _FixedValue__deleting_dtor");
asm(".globl FUN_001d80bc");
asm(".set FUN_001d80bc, _ImmedConstBuffer__dtor");
asm(".globl FUN_001d80f0");
asm(".set FUN_001d80f0, _LoopIndexedConstSet__dtor");
asm(".globl FUN_001d8134");
asm(".set FUN_001d8134, _LoopIndexedConstSet__deleting_dtor");
asm(".globl FUN_001d818c");
asm(".set FUN_001d818c, _LoopIndexedInputSet__dtor");
asm(".globl FUN_001d81d0");
asm(".set FUN_001d81d0, _LoopIndexedInputSet__deleting_dtor");
asm(".globl FUN_001d8228");
asm(".set FUN_001d8228, _LoopIndexedOutputSet__dtor");
asm(".globl FUN_001d826c");
asm(".set FUN_001d826c, _LoopIndexedOutputSet__deleting_dtor");
asm(".globl FUN_001d8318");
asm(".set FUN_001d8318, _KhanPs__deleting_dtor");
asm(".globl FUN_001d834c");
asm(".set FUN_001d834c, _KhanChip__deleting_dtor");
asm(".globl FUN_001d8380");
asm(".set FUN_001d8380, _KhanChip__dtor");
asm(".globl FUN_001d83b4");
asm(".set FUN_001d83b4, _KhanPs__dtor");
asm(".globl FUN_001d84ac");
asm(".set FUN_001d84ac, _KhanVs__deleting_dtor_1d84ac");
asm(".globl FUN_001d84e0");
asm(".set FUN_001d84e0, _KhanVs__dtor_1d84e0");
asm(".globl FUN_001d8514");
asm(".set FUN_001d8514, _KhanVs__deleting_dtor_1d8514");
asm(".globl FUN_001d8548");
asm(".set FUN_001d8548, _KhanVs__dtor_1d8548");
asm(".globl FUN_001d8584");
asm(".set FUN_001d8584, _FUN_001d8584");
asm(".globl FUN_001d85a0");
asm(".set FUN_001d85a0, _MirrorBlock__deleting_dtor");
asm(".globl FUN_001d8608");
asm(".set FUN_001d8608, _MirrorBlock__dtor");
asm(".globl FUN_001d862c");
asm(".set FUN_001d862c, _SchedNode__dtor");
asm(".globl FUN_001d8660");
asm(".set FUN_001d8660, _SchedNode__deleting_dtor");
asm(".globl FUN_001d86b4");
asm(".set FUN_001d86b4, _ResourceModel__deleting_dtor");
asm(".globl FUN_001d87a8");
asm(".set FUN_001d87a8, _ThreadModel__deleting_dtor");
