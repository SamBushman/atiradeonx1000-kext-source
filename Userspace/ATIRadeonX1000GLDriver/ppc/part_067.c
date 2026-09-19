#include "decls.h"

/* FUN_001d8850 @ 0x1d8850 (36 bytes) */
int FUN_001d8850(param_1)
  undefined4 *param_1;
{
  *param_1 = &PTR_FUN_001eb2f0;
  return;
}

/* FUN_001d8874 @ 0x1d8874 (36 bytes) */
int FUN_001d8874(param_1)
  undefined4 *param_1;
{
  *param_1 = &PTR_FUN_001eb260;
  return;
}

/* FUN_001d8944 @ 0x1d8944 (72 bytes) */
int FUN_001d8944(param_1)
  undefined4 *param_1;
{
  undefined *puVar1;
  
  puVar1 = PTR_DAT_001e90fc + 8;
  *param_1 = &PTR_LAB_001eb328;
  *param_1 = puVar1;
  if (param_1 == (undefined4 *)0x0) {
    return;
  }
  FUN_00193cc0(param_1[-1],param_1 + -1);
  return;
}

/* FUN_001d8a28 @ 0x1d8a28 (52 bytes) */
int FUN_001d8a28(param_1)
  undefined4 *param_1;
{
  undefined *puVar1;
  
  puVar1 = PTR_DAT_001e90fc + 8;
  *param_1 = &PTR_FUN_001eb3c0;
  *param_1 = puVar1;
  return;
}

/* FUN_001d8a5c @ 0x1d8a5c (72 bytes) */
int FUN_001d8a5c(param_1)
  undefined4 *param_1;
{
  undefined *puVar1;
  
  puVar1 = PTR_DAT_001e90fc + 8;
  *param_1 = &PTR_FUN_001eb3c0;
  *param_1 = puVar1;
  if (param_1 == (undefined4 *)0x0) {
    return;
  }
  FUN_00193cc0(param_1[-1],param_1 + -1);
  return;
}

/* FUN_001d8af4 @ 0x1d8af4 (68 bytes) */
int FUN_001d8af4(param_1)
  undefined4 *param_1;
{
  undefined *puVar1;
  undefined *puVar2;
  
  puVar1 = PTR_DAT_001e8c74;
  *param_1 = &PTR_FUN_001eb5e8;
  puVar2 = PTR_DAT_001e8c88;
  *param_1 = puVar1 + 8;
  *param_1 = puVar2 + 8;
  operator_delete(param_1);
  return;
}

/* FUN_001d8b38 @ 0x1d8b38 (68 bytes) */
int FUN_001d8b38(param_1)
  undefined4 *param_1;
{
  undefined *puVar1;
  undefined *puVar2;
  
  puVar2 = PTR_DAT_001e9144;
  *param_1 = &PTR_FUN_001eb450;
  puVar1 = PTR_DAT_001e9108;
  *param_1 = puVar2 + 8;
  *param_1 = puVar1 + 8;
  operator_delete(param_1);
  return;
}

/* FUN_001d8b7c @ 0x1d8b7c (68 bytes) */
int FUN_001d8b7c(param_1)
  undefined4 *param_1;
{
  undefined *puVar1;
  undefined *puVar2;
  
  puVar1 = PTR_DAT_001e8c74;
  *param_1 = &PTR_FUN_001eb5e8;
  puVar2 = PTR_DAT_001e8c88;
  *param_1 = puVar1 + 8;
  *param_1 = puVar2 + 8;
  return;
}

/* FUN_001d8bc0 @ 0x1d8bc0 (68 bytes) */
int FUN_001d8bc0(param_1)
  undefined4 *param_1;
{
  undefined *puVar1;
  undefined *puVar2;
  
  puVar2 = PTR_DAT_001e9144;
  *param_1 = &PTR_FUN_001eb450;
  puVar1 = PTR_DAT_001e9108;
  *param_1 = puVar2 + 8;
  *param_1 = puVar1 + 8;
  return;
}

/* FUN_001d8c18 @ 0x1d8c18 (88 bytes) */
int FUN_001d8c18(param_1)
  undefined4 *param_1;
{
  undefined *puVar1;
  undefined *puVar2;
  
  puVar1 = PTR_DAT_001e90f4;
  *param_1 = &PTR_FUN_001eb608;
  puVar2 = PTR_DAT_001e90fc;
  *param_1 = puVar1 + 8;
  *param_1 = puVar2 + 8;
  if (param_1 == (undefined4 *)0x0) {
    return;
  }
  FUN_00193cc0(param_1[-1],param_1 + -1);
  return;
}

/* FUN_001d8c70 @ 0x1d8c70 (68 bytes) */
int FUN_001d8c70(param_1)
  undefined4 *param_1;
{
  undefined *puVar1;
  undefined *puVar2;
  
  puVar1 = PTR_DAT_001e90f4;
  *param_1 = &PTR_FUN_001eb608;
  puVar2 = PTR_DAT_001e90fc;
  *param_1 = puVar1 + 8;
  *param_1 = puVar2 + 8;
  return;
}

/* FUN_001d8f58 @ 0x1d8f58 (104 bytes) */
int FUN_001d8f58(param_1)
  undefined4 *param_1;
{
  *param_1 = &PTR_FUN_001eb9a8;
  FUN_00196dbc();
  if (param_1 != (undefined4 *)0x0) {
    FUN_00193cc0(param_1[-1],param_1 + -1);
    return;
  }
  return;
}

/* FUN_001d8fc0 @ 0x1d8fc0 (36 bytes) */
int FUN_001d8fc0(param_1)
  undefined4 *param_1;
{
  *param_1 = &PTR_FUN_001eb9a8;
  FUN_00196dbc();
  return;
}

