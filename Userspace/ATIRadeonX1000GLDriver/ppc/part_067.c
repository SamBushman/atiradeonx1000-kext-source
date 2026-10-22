#include "decls.h"

/* ThreadModel__dtor @ 0x1d8850 (36 bytes) */
int ThreadModel__dtor(this)
  undefined4 *this;
{
  *this = &PTR_FUN_001eb2f0;
  return;
}

/* ResourceModel__dtor @ 0x1d8874 (36 bytes) */
int ResourceModel__dtor(this)
  undefined4 *this;
{
  *this = &PTR_FUN_001eb260;
  return;
}

/* R300SchedModel__dtor @ 0x1d8944 (72 bytes) */
int R300SchedModel__dtor(this)
  undefined4 *this;
{
  undefined *vtable;
  
  vtable = PTR_DAT_001e90fc + 8;
  *this = &PTR_DAT_001eb328;
  *this = vtable;
  if (this == (undefined4 *)0x0) {
    return;
  }
  return FUN_00193cc0(this[-1],this + -1);
}

/* R300VSchedModel__dtor @ 0x1d8a28 (52 bytes) */
int R300VSchedModel__dtor(this)
  undefined4 *this;
{
  undefined *vtable;
  
  vtable = PTR_DAT_001e90fc + 8;
  *this = &PTR_FUN_001eb3c0;
  *this = vtable;
  return;
}

/* R300VSchedModel__deleting_dtor @ 0x1d8a5c (72 bytes) */
int R300VSchedModel__deleting_dtor(this)
  undefined4 *this;
{
  undefined *vtable;
  
  vtable = PTR_DAT_001e90fc + 8;
  *this = &PTR_FUN_001eb3c0;
  *this = vtable;
  if (this == (undefined4 *)0x0) {
    return;
  }
  return FUN_00193cc0(this[-1],this + -1);
}

/* FudoChip__deleting_dtor @ 0x1d8af4 (68 bytes) */
int FudoChip__deleting_dtor(this)
  undefined4 *this;
{
  undefined *puVar1;
  undefined *puVar2;
  
  puVar1 = PTR_DAT_001e8c74;
  *this = &PTR_FUN_001eb5e8;
  puVar2 = PTR_DAT_001e8c88;
  *this = puVar1 + 8;
  *this = puVar2 + 8;
  return operator_delete(this);
}

/* FudoPs__deleting_dtor @ 0x1d8b38 (68 bytes) */
int FudoPs__deleting_dtor(this)
  undefined4 *this;
{
  undefined *puVar1;
  undefined *puVar2;
  
  puVar2 = PTR_DAT_001e9144;
  *this = &PTR_FUN_001eb450;
  puVar1 = PTR_DAT_001e9108;
  *this = puVar2 + 8;
  *this = puVar1 + 8;
  return operator_delete(this);
}

/* FudoChip__dtor @ 0x1d8b7c (68 bytes) */
int FudoChip__dtor(this)
  undefined4 *this;
{
  undefined *puVar1;
  undefined *puVar2;
  
  puVar1 = PTR_DAT_001e8c74;
  *this = &PTR_FUN_001eb5e8;
  puVar2 = PTR_DAT_001e8c88;
  *this = puVar1 + 8;
  *this = puVar2 + 8;
  return;
}

/* FudoPs__dtor @ 0x1d8bc0 (68 bytes) */
int FudoPs__dtor(this)
  undefined4 *this;
{
  undefined *puVar1;
  undefined *puVar2;
  
  puVar2 = PTR_DAT_001e9144;
  *this = &PTR_FUN_001eb450;
  puVar1 = PTR_DAT_001e9108;
  *this = puVar2 + 8;
  *this = puVar1 + 8;
  return;
}

/* R520SchedModel__deleting_dtor @ 0x1d8c18 (88 bytes) */
int R520SchedModel__deleting_dtor(this)
  undefined4 *this;
{
  undefined *puVar1;
  undefined *puVar2;
  
  puVar1 = PTR_DAT_001e90f4;
  *this = &PTR_FUN_001eb608;
  puVar2 = PTR_DAT_001e90fc;
  *this = puVar1 + 8;
  *this = puVar2 + 8;
  if (this == (undefined4 *)0x0) {
    return;
  }
  return FUN_00193cc0(this[-1],this + -1);
}

/* R520SchedModel__dtor @ 0x1d8c70 (68 bytes) */
int R520SchedModel__dtor(this)
  undefined4 *this;
{
  undefined *puVar1;
  undefined *puVar2;
  
  puVar1 = PTR_DAT_001e90f4;
  *this = &PTR_FUN_001eb608;
  puVar2 = PTR_DAT_001e90fc;
  *this = puVar1 + 8;
  *this = puVar2 + 8;
  return;
}

/* R520MachineAssembler__deleting_dtor @ 0x1d8f58 (104 bytes) */
int R520MachineAssembler__deleting_dtor(this)
  undefined4 *this;
{
  *this = &PTR_FUN_001eb9a8;
  R300MachineAssembler__dtor_196dbc(this);
  if (this != (undefined4 *)0x0) {
    FUN_00193cc0(this[-1],this + -1);
    return;
  }
  return;
}

/* R520MachineAssembler__dtor @ 0x1d8fc0 (36 bytes) */
int R520MachineAssembler__dtor(this2)
  undefined4 *this2;
{
  *this2 = &PTR_FUN_001eb9a8;
  return R300MachineAssembler__dtor_196dbc(this2);
}


/* issue: auto-generated aliases bridging data.s/code.s references (written
 * without a leading underscore, matching the raw stock-binary symbol name)
 * against the real compiled C symbols (gcc adds one underscore automatically).
 * Needed because ld64 (required for this PPC binary's size - stock ld breaks on
 * large PPC links) does not silently reconcile this the way stock ld did. */
asm(".globl FUN_001d8850");
asm(".set FUN_001d8850, _ThreadModel__dtor");
asm(".globl FUN_001d8874");
asm(".set FUN_001d8874, _ResourceModel__dtor");
asm(".globl FUN_001d8944");
asm(".set FUN_001d8944, _R300SchedModel__dtor");
asm(".globl FUN_001d8a28");
asm(".set FUN_001d8a28, _R300VSchedModel__dtor");
asm(".globl FUN_001d8a5c");
asm(".set FUN_001d8a5c, _R300VSchedModel__deleting_dtor");
asm(".globl FUN_001d8af4");
asm(".set FUN_001d8af4, _FudoChip__deleting_dtor");
asm(".globl FUN_001d8b38");
asm(".set FUN_001d8b38, _FudoPs__deleting_dtor");
asm(".globl FUN_001d8b7c");
asm(".set FUN_001d8b7c, _FudoChip__dtor");
asm(".globl FUN_001d8bc0");
asm(".set FUN_001d8bc0, _FudoPs__dtor");
asm(".globl FUN_001d8c18");
asm(".set FUN_001d8c18, _R520SchedModel__deleting_dtor");
asm(".globl FUN_001d8c70");
asm(".set FUN_001d8c70, _R520SchedModel__dtor");
asm(".globl FUN_001d8f58");
asm(".set FUN_001d8f58, _R520MachineAssembler__deleting_dtor");
asm(".globl FUN_001d8fc0");
asm(".set FUN_001d8fc0, _R520MachineAssembler__dtor");
