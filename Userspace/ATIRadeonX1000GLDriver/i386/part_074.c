#include "decls.h"

/* FUN_001c57dc @ 0x1c57dc (10 bytes) */
int FUN_001c57dc()
{
  return 1;
}

/* FUN_001c57e6 @ 0x1c57e6 (5 bytes) */
int FUN_001c57e6()
{
  return;
}

/* FUN_001c57ec @ 0x1c57ec (10 bytes) */
int FUN_001c57ec()
{
  return 1;
}

/* FUN_001c57f6 @ 0x1c57f6 (73 bytes) */
int FUN_001c57f6(param_1)
  undefined4 *param_1;
{
  *param_1 = &PTR_FUN_001fdd88;
  *param_1 = PTR_DAT_00213a05 + 8;
  *param_1 = PTR_DAT_002139f5 + 8;
  if (param_1 != (undefined4 *)0x0) {
    FUN_001a7aba(param_1[-1],param_1 + -1);
  }
  return;
}

/* FUN_001c5840 @ 0x1c5840 (43 bytes) */
int FUN_001c5840(param_1)
  undefined4 *param_1;
{
  *param_1 = &PTR_FUN_001fdd88;
  *param_1 = PTR_DAT_00213a05 + 8;
  *param_1 = PTR_DAT_002139f5 + 8;
  return;
}

/* FUN_001c586c @ 0x1c586c (5 bytes) */
int FUN_001c586c()
{
  return;
}

/* FUN_001c5872 @ 0x1c5872 (5 bytes) */
int FUN_001c5872()
{
  return;
}

/* FUN_001c5878 @ 0x1c5878 (5 bytes) */
int FUN_001c5878()
{
  return;
}

/* FUN_001c587e @ 0x1c587e (5 bytes) */
int FUN_001c587e()
{
  return;
}

/* FUN_001c5884 @ 0x1c5884 (5 bytes) */
int FUN_001c5884()
{
  return;
}

/* FUN_001c588a @ 0x1c588a (5 bytes) */
int FUN_001c588a()
{
  return;
}

/* FUN_001c5890 @ 0x1c5890 (5 bytes) */
int FUN_001c5890()
{
  return;
}

/* FUN_001c5896 @ 0x1c5896 (5 bytes) */
int FUN_001c5896()
{
  return;
}

/* FUN_001c589c @ 0x1c589c (5 bytes) */
int FUN_001c589c()
{
  return;
}

/* FUN_001c58a2 @ 0x1c58a2 (24 bytes) */
int FUN_001c58a2(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  *(undefined1 *)(*(int *)(param_1 + 0x58) + 0xe + param_2 * 0x48) = param_3;
  return;
}

/* FUN_001c58ba @ 0x1c58ba (24 bytes) */
int FUN_001c58ba(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  *(undefined1 *)(*(int *)(param_1 + 0x58) + 0xf + param_2 * 0x48) = param_3;
  return;
}

/* FUN_001c58d2 @ 0x1c58d2 (7 bytes) */
int FUN_001c58d2()
{
  return 0;
}

/* FUN_001c58da @ 0x1c58da (13 bytes) */
int FUN_001c58da(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  return param_2 + 0x8000;
}

/* FUN_001c58e8 @ 0x1c58e8 (24 bytes) */
int FUN_001c58e8(param_1, param_2)
  int param_1;
  int param_2;
{
  *(undefined1 *)(*(int *)(param_1 + 0x58) + 0x30 + *(int *)(param_1 + 0x60) * 0x48) = param_2;
  return;
}

/* FUN_001c5900 @ 0x1c5900 (24 bytes) */
int FUN_001c5900(param_1, param_2)
  int param_1;
  int param_2;
{
  *(undefined1 *)(*(int *)(param_1 + 0x58) + 0x3f + *(int *)(param_1 + 0x60) * 0x48) = param_2;
  return;
}

/* FUN_001c5918 @ 0x1c5918 (5 bytes) */
int FUN_001c5918()
{
  return;
}

/* FUN_001c591e @ 0x1c591e (5 bytes) */
int FUN_001c591e()
{
  return;
}

/* FUN_001c5924 @ 0x1c5924 (40 bytes) */
int FUN_001c5924(param_1)
  int param_1;
{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x58) + -0x48 + *(int *)(param_1 + 0x60) * 0x48;
  if (*(char *)(iVar1 + 0x34) != '\x01') {
    *(undefined1 *)(iVar1 + 0x34) = 1;
    return 1;
  }
  return 0;
}

/* FUN_001c594c @ 0x1c594c (39 bytes) */
int FUN_001c594c(param_1)
  int param_1;
{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x58) + *(int *)(param_1 + 0x60) * 0x48;
  if (*(char *)(iVar1 + 0x34) != '\x01') {
    *(undefined1 *)(iVar1 + 0x34) = 1;
    return 1;
  }
  return 0;
}

/* FUN_001c5974 @ 0x1c5974 (5 bytes) */
int FUN_001c5974()
{
  return;
}

/* FUN_001c597a @ 0x1c597a (5 bytes) */
int FUN_001c597a()
{
  return;
}

/* FUN_001c5980 @ 0x1c5980 (5 bytes) */
int FUN_001c5980()
{
  return;
}

/* FUN_001c5986 @ 0x1c5986 (5 bytes) */
int FUN_001c5986()
{
  return;
}

/* FUN_001c598c @ 0x1c598c (5 bytes) */
int FUN_001c598c()
{
  return;
}

/* FUN_001c5992 @ 0x1c5992 (24 bytes) */
int FUN_001c5992(param_1, param_2)
  int param_1;
  int param_2;
{
  *(undefined1 *)(*(int *)(param_1 + 0x58) + 0x31 + *(int *)(param_1 + 0x60) * 0x48) = param_2;
  return;
}

/* FUN_001c59aa @ 0x1c59aa (14 bytes) */
int FUN_001c59aa(param_1)
  int param_1;
{
  return *(int *)(param_1 + 0x58) << 4;
}

/* FUN_001c59b8 @ 0x1c59b8 (48 bytes) */
int FUN_001c59b8(param_1)
  int param_1;
{
  FUN_001b2fd0(param_1,*(undefined4 *)(param_1 + 0x58),*(undefined4 *)(param_1 + 0x44),0x10,
               *(undefined4 *)(param_1 + 0xc));
  return;
}

/* FUN_001c59e8 @ 0x1c59e8 (5 bytes) */
int FUN_001c59e8()
{
  return;
}

/* FUN_001c59ee @ 0x1c59ee (27 bytes) */
int FUN_001c59ee(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  *(undefined1 *)(*(int *)(param_1 + 0xa8) + 0xe + param_2 * 0x48) = param_3;
  return;
}

/* FUN_001c5a0a @ 0x1c5a0a (27 bytes) */
int FUN_001c5a0a(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  *(undefined1 *)(*(int *)(param_1 + 0xa8) + 0xf + param_2 * 0x48) = param_3;
  return;
}

/* FUN_001c5a26 @ 0x1c5a26 (13 bytes) */
int FUN_001c5a26(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  return param_2 + 0x8000;
}

/* FUN_001c5a34 @ 0x1c5a34 (27 bytes) */
int FUN_001c5a34(param_1, param_2)
  int param_1;
  int param_2;
{
  *(undefined1 *)(*(int *)(param_1 + 0xa8) + 0x31 + *(int *)(param_1 + 0x60) * 0x48) = param_2;
  return;
}

/* FUN_001c5a50 @ 0x1c5a50 (27 bytes) */
int FUN_001c5a50(param_1, param_2)
  int param_1;
  int param_2;
{
  *(undefined1 *)(*(int *)(param_1 + 0xa8) + 0x30 + *(int *)(param_1 + 0x60) * 0x48) = param_2;
  return;
}

/* FUN_001c5a6c @ 0x1c5a6c (27 bytes) */
int FUN_001c5a6c(param_1, param_2)
  int param_1;
  int param_2;
{
  *(undefined1 *)(*(int *)(param_1 + 0xa8) + 0x3f + *(int *)(param_1 + 0x60) * 0x48) = param_2;
  return;
}

/* FUN_001c5a88 @ 0x1c5a88 (5 bytes) */
int FUN_001c5a88()
{
  return;
}

/* FUN_001c5a8e @ 0x1c5a8e (43 bytes) */
int FUN_001c5a8e(param_1)
  int param_1;
{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0xa8) + -0x48 + *(int *)(param_1 + 0x60) * 0x48;
  if (*(char *)(iVar1 + 0x34) != '\x01') {
    *(undefined1 *)(iVar1 + 0x34) = 1;
    return 1;
  }
  return 0;
}

/* FUN_001c5aba @ 0x1c5aba (42 bytes) */
int FUN_001c5aba(param_1)
  int param_1;
{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0xa8) + *(int *)(param_1 + 0x60) * 0x48;
  if (*(char *)(iVar1 + 0x34) != '\x01') {
    *(undefined1 *)(iVar1 + 0x34) = 1;
    return 1;
  }
  return 0;
}

/* FUN_001c5ae4 @ 0x1c5ae4 (48 bytes) */
int FUN_001c5ae4(param_1)
  int param_1;
{
  *(undefined1 *)(*(int *)(param_1 + 0xa8) + 0x1b + *(int *)(param_1 + 0xb0) * 0x48) = 1;
  *(undefined1 *)(*(int *)(param_1 + 0xa8) + 4 + *(int *)(param_1 + 0xb0) * 0x48) = 1;
  return;
}

/* FUN_001c5b14 @ 0x1c5b14 (25 bytes) */
int FUN_001c5b14(param_1)
  int param_1;
{
  *(undefined1 *)(*(int *)(param_1 + 0xa8) + 4 + *(int *)(param_1 + 0x60) * 0x48) = 1;
  return;
}

/* FUN_001c5b2e @ 0x1c5b2e (5 bytes) */
int FUN_001c5b2e()
{
  return;
}

/* FUN_001c5b34 @ 0x1c5b34 (5 bytes) */
int FUN_001c5b34()
{
  return;
}

/* FUN_001c5b3a @ 0x1c5b3a (61 bytes) */
int FUN_001c5b3a(param_1)
  undefined4 *param_1;
{
  *param_1 = &PTR_FUN_001fe168;
  FUN_001aa7dc(param_1);
  if (param_1 != (undefined4 *)0x0) {
    FUN_001a7aba(param_1[-1],param_1 + -1);
  }
  return;
}

/* FUN_001c5b78 @ 0x1c5b78 (28 bytes) */
int FUN_001c5b78(param_1)
  undefined4 *param_1;
{
  *param_1 = &PTR_FUN_001fe168;
  FUN_001aa7dc();
  return;
}

