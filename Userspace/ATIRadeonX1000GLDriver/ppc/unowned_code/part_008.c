#include "decls.h"

/* R300VMachineAssembler__vslot41 @ 0x1d8e0c (4 bytes) */
int R300VMachineAssembler__vslot41()
{
  return;
}

/* R520MachineAssembler__vslot51 @ 0x1d8e10 (20 bytes) */
int R520MachineAssembler__vslot51(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  *(undefined1 *)(param_2 * 0x48 + *(int *)(param_1 + 0xa8) + 0xe) = param_3;
  return;
}

/* R520MachineAssembler__vslot52 @ 0x1d8e24 (20 bytes) */
int R520MachineAssembler__vslot52(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  *(undefined1 *)(param_2 * 0x48 + *(int *)(param_1 + 0xa8) + 0xf) = param_3;
  return;
}

/* R520MachineAssembler__vslot56 @ 0x1d8e38 (12 bytes) */
int R520MachineAssembler__vslot56(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  return param_2 + 0x8000;
}

/* R520MachineAssembler__vslot84 @ 0x1d8e44 (24 bytes) */
int R520MachineAssembler__vslot84(param_1, param_2)
  int param_1;
  int param_2;
{
  *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8) + 0x31) = param_2;
  return;
}

/* R520MachineAssembler__vslot57 @ 0x1d8e5c (24 bytes) */
int R520MachineAssembler__vslot57(param_1, param_2)
  int param_1;
  int param_2;
{
  *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8) + 0x30) = param_2;
  return;
}

/* R520MachineAssembler__vslot58 @ 0x1d8e74 (24 bytes) */
int R520MachineAssembler__vslot58(param_1, param_2)
  int param_1;
  int param_2;
{
  *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8) + 0x3f) = param_2;
  return;
}

/* R520MachineAssembler__vslot78 @ 0x1d8e8c (4 bytes) */
int R520MachineAssembler__vslot78()
{
  return;
}

/* R520MachineAssembler__vslot68 @ 0x1d8e90 (60 bytes) */
int R520MachineAssembler__vslot68(param_1)
  int param_1;
{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8);
  if (*(char *)(iVar1 + -0x14) == '\x01') {
    return 0;
  }
  *(undefined1 *)(iVar1 + -0x14) = 1;
  return 1;
}

/* R520MachineAssembler__vslot69 @ 0x1d8ecc (56 bytes) */
int R520MachineAssembler__vslot69(param_1)
  int param_1;
{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8);
  if (*(char *)(iVar1 + 0x34) == '\x01') {
    return 0;
  }
  *(undefined1 *)(iVar1 + 0x34) = 1;
  return 1;
}

/* R520MachineAssembler__vslot82 @ 0x1d8f04 (48 bytes) */
int R520MachineAssembler__vslot82(param_1)
  int param_1;
{
  *(undefined1 *)(*(int *)(param_1 + 0xb0) * 0x48 + *(int *)(param_1 + 0xa8) + 0x1b) = 1;
  *(undefined1 *)(*(int *)(param_1 + 0xb0) * 0x48 + *(int *)(param_1 + 0xa8) + 4) = 1;
  return;
}

/* R520MachineAssembler__vslot83 @ 0x1d8f34 (28 bytes) */
int R520MachineAssembler__vslot83(param_1)
  int param_1;
{
  *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8) + 4) = 1;
  return;
}

/* R520MachineAssembler__vslot85 @ 0x1d8f50 (4 bytes) */
int R520MachineAssembler__vslot85()
{
  return;
}

/* R520MachineAssembler__visitContinue @ 0x1d8f54 (4 bytes) */
int R520MachineAssembler__visitContinue()
{
  return;
}

