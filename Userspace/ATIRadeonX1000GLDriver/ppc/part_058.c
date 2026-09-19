#include "decls.h"

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

