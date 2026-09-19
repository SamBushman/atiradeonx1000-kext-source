#include "decls.h"

/* FUN_001bd34a @ 0x1bd34a (61 bytes) */
int FUN_001bd34a(param_1)
  undefined4 *param_1;
{
  *param_1 = &PTR_FUN_001fc348;
  FUN_000ebc7a(param_1);
  if (param_1 != (undefined4 *)0x0) {
    FUN_001a7aba(param_1[-1],param_1 + -1);
  }
  return;
}

/* FUN_001bd388 @ 0x1bd388 (28 bytes) */
int FUN_001bd388(param_1)
  undefined4 *param_1;
{
  *param_1 = &PTR_FUN_001fc348;
  FUN_000ebc7a();
  return;
}

/* FUN_001bd3a4 @ 0x1bd3a4 (61 bytes) */
int FUN_001bd3a4(param_1)
  undefined4 *param_1;
{
  *param_1 = &PTR_FUN_001fc348;
  FUN_000ebc7a(param_1);
  if (param_1 != (undefined4 *)0x0) {
    FUN_001a7aba(param_1[-1],param_1 + -1);
  }
  return;
}

/* FUN_001bd3e2 @ 0x1bd3e2 (31 bytes) */
int FUN_001bd3e2(param_1)
  undefined4 *param_1;
{
  *param_1 = PTR_DAT_0021344d + 8;
  FUN_000ebc7a();
  return;
}

/* FUN_001bd402 @ 0x1bd402 (64 bytes) */
int FUN_001bd402(param_1)
  undefined4 *param_1;
{
  *param_1 = PTR_DAT_0021344d + 8;
  FUN_000ebc7a(param_1);
  if (param_1 != (undefined4 *)0x0) {
    FUN_001a7aba(param_1[-1],param_1 + -1);
  }
  return;
}

/* FUN_001bd442 @ 0x1bd442 (72 bytes) */
int FUN_001bd442(param_1)
  undefined4 *param_1;
{
  *param_1 = &PTR_FUN_001fc468;
  *param_1 = PTR_DAT_0021344d + 8;
  FUN_000ebc7a(param_1);
  if (param_1 != (undefined4 *)0x0) {
    FUN_001a7aba(param_1[-1],param_1 + -1);
  }
  return;
}

/* FUN_001bd48a @ 0x1bd48a (28 bytes) */
int FUN_001bd48a(param_1)
  undefined4 *param_1;
{
  *param_1 = &PTR_FUN_001fc4c8;
  FUN_000ebc7a();
  return;
}

/* FUN_001bd4a6 @ 0x1bd4a6 (61 bytes) */
int FUN_001bd4a6(param_1)
  undefined4 *param_1;
{
  *param_1 = &PTR_FUN_001fc4c8;
  FUN_000ebc7a(param_1);
  if (param_1 != (undefined4 *)0x0) {
    FUN_001a7aba(param_1[-1],param_1 + -1);
  }
  return;
}

/* FUN_001bd4e4 @ 0x1bd4e4 (28 bytes) */
int FUN_001bd4e4(param_1)
  undefined4 *param_1;
{
  *param_1 = &PTR_FUN_001fc528;
  FUN_000ebc7a();
  return;
}

/* FUN_001bd500 @ 0x1bd500 (39 bytes) */
int FUN_001bd500(param_1)
  undefined4 *param_1;
{
  *param_1 = &PTR_FUN_001fc408;
  *param_1 = PTR_DAT_0021344d + 8;
  FUN_000ebc7a();
  return;
}

/* FUN_001bd528 @ 0x1bd528 (72 bytes) */
int FUN_001bd528(param_1)
  undefined4 *param_1;
{
  *param_1 = &PTR_FUN_001fc408;
  *param_1 = PTR_DAT_0021344d + 8;
  FUN_000ebc7a(param_1);
  if (param_1 != (undefined4 *)0x0) {
    FUN_001a7aba(param_1[-1],param_1 + -1);
  }
  return;
}

/* FUN_001bd570 @ 0x1bd570 (39 bytes) */
int FUN_001bd570(param_1)
  undefined4 *param_1;
{
  *param_1 = &PTR_FUN_001fc468;
  *param_1 = PTR_DAT_0021344d + 8;
  FUN_000ebc7a();
  return;
}

/* FUN_001bd598 @ 0x1bd598 (111 bytes) */
int FUN_001bd598(param_1, param_2)
  int param_1;
  int *param_2;
{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(param_1 + 0x88) + 4);
  if (iVar1 == 7) {
                    
                    
    (**(code **)(*param_2 + 0x50))();
    return;
  }
  if (iVar1 != 9) {
    if (iVar1 != 6) {
      return;
    }
                    
                    
    (**(code **)(*param_2 + 0x4c))();
    return;
  }
                    
                    
  (**(code **)(*param_2 + 0x38))();
  return;
}

/* FUN_001bd608 @ 0x1bd608 (16 bytes) */
int FUN_001bd608()
{
  return "unknown";
}

/* FUN_001bd618 @ 0x1bd618 (10 bytes) */
int FUN_001bd618()
{
  return 1;
}

/* FUN_001bd622 @ 0x1bd622 (16 bytes) */
int FUN_001bd622()
{
  return "entry";
}

/* FUN_001bd632 @ 0x1bd632 (10 bytes) */
int FUN_001bd632()
{
  return 1;
}

/* FUN_001bd63c @ 0x1bd63c (16 bytes) */
int FUN_001bd63c()
{
  return "exit";
}

/* FUN_001bd64c @ 0x1bd64c (10 bytes) */
int FUN_001bd64c()
{
  return 1;
}

/* FUN_001bd656 @ 0x1bd656 (16 bytes) */
int FUN_001bd656()
{
  return "load";
}

/* FUN_001bd666 @ 0x1bd666 (16 bytes) */
int FUN_001bd666()
{
  return "buffer";
}

/* FUN_001bd676 @ 0x1bd676 (16 bytes) */
int FUN_001bd676()
{
  return "buffer_index";
}

/* FUN_001bd686 @ 0x1bd686 (16 bytes) */
int FUN_001bd686()
{
  return "icb";
}

/* FUN_001bd696 @ 0x1bd696 (10 bytes) */
int FUN_001bd696()
{
  return 1;
}

/* FUN_001bd6a0 @ 0x1bd6a0 (16 bytes) */
int FUN_001bd6a0()
{
  return "load const";
}

/* FUN_001bd6b0 @ 0x1bd6b0 (10 bytes) */
int FUN_001bd6b0()
{
  return 1;
}

/* FUN_001bd6ba @ 0x1bd6ba (16 bytes) */
int FUN_001bd6ba()
{
  return "load temp";
}

/* FUN_001bd6ca @ 0x1bd6ca (16 bytes) */
int FUN_001bd6ca()
{
  return "load v";
}

/* FUN_001bd6da @ 0x1bd6da (10 bytes) */
int FUN_001bd6da()
{
  return 1;
}

/* FUN_001bd6e4 @ 0x1bd6e4 (16 bytes) */
int FUN_001bd6e4()
{
  return "load interp";
}

/* FUN_001bd6f4 @ 0x1bd6f4 (8 bytes) */
int FUN_001bd6f4(param_1)
  undefined4 param_1;
{
  return param_1;
}

/* FUN_001bd6fc @ 0x1bd6fc (10 bytes) */
int FUN_001bd6fc()
{
  return 1;
}

/* FUN_001bd706 @ 0x1bd706 (16 bytes) */
int FUN_001bd706()
{
  return "ir_undefined";
}

/* FUN_001bd716 @ 0x1bd716 (16 bytes) */
int FUN_001bd716()
{
  return "merge";
}

/* FUN_001bd726 @ 0x1bd726 (10 bytes) */
int FUN_001bd726()
{
  return 1;
}

/* FUN_001bd730 @ 0x1bd730 (10 bytes) */
int FUN_001bd730()
{
  return 1;
}

/* FUN_001bd73a @ 0x1bd73a (14 bytes) */
int FUN_001bd73a(param_1)
  int param_1;
{
  return *(undefined4 *)(param_1 + 0x84);
}

/* FUN_001bd748 @ 0x1bd748 (10 bytes) */
int FUN_001bd748()
{
  return 1;
}

/* FUN_001bd752 @ 0x1bd752 (10 bytes) */
int FUN_001bd752()
{
  return 1;
}

/* FUN_001bd75c @ 0x1bd75c (16 bytes) */
int FUN_001bd75c()
{
  return "ir_projection";
}

/* FUN_001bd76c @ 0x1bd76c (10 bytes) */
int FUN_001bd76c()
{
  return 1;
}

/* FUN_001bd776 @ 0x1bd776 (10 bytes) */
int FUN_001bd776()
{
  return 1;
}

/* FUN_001bd780 @ 0x1bd780 (10 bytes) */
int FUN_001bd780()
{
  return 1;
}

/* FUN_001bd78a @ 0x1bd78a (16 bytes) */
int FUN_001bd78a()
{
  return "ir_presub1";
}

/* FUN_001bd79a @ 0x1bd79a (10 bytes) */
int FUN_001bd79a()
{
  return 1;
}

/* FUN_001bd7a4 @ 0x1bd7a4 (5 bytes) */
int FUN_001bd7a4()
{
  return;
}

/* FUN_001bd7aa @ 0x1bd7aa (5 bytes) */
int FUN_001bd7aa()
{
  return;
}

/* FUN_001bd7b0 @ 0x1bd7b0 (7 bytes) */
int FUN_001bd7b0()
{
  return 0;
}

/* FUN_001bd7b8 @ 0x1bd7b8 (10 bytes) */
int FUN_001bd7b8()
{
  return 1;
}

/* FUN_001bd7c2 @ 0x1bd7c2 (10 bytes) */
int FUN_001bd7c2()
{
  return 2;
}

/* FUN_001bd7cc @ 0x1bd7cc (16 bytes) */
int FUN_001bd7cc()
{
  return "ir_presub2";
}

/* FUN_001bd7dc @ 0x1bd7dc (10 bytes) */
int FUN_001bd7dc()
{
  return 1;
}

/* FUN_001bd7e6 @ 0x1bd7e6 (5 bytes) */
int FUN_001bd7e6()
{
  return;
}

/* FUN_001bd7ec @ 0x1bd7ec (5 bytes) */
int FUN_001bd7ec()
{
  return;
}

/* FUN_001bd7f2 @ 0x1bd7f2 (7 bytes) */
int FUN_001bd7f2()
{
  return 0;
}

/* FUN_001bd7fa @ 0x1bd7fa (10 bytes) */
int FUN_001bd7fa()
{
  return 1;
}

/* FUN_001bd804 @ 0x1bd804 (14 bytes) */
int FUN_001bd804(param_1)
  int param_1;
{
  return *(undefined4 *)(param_1 + 0x84);
}

/* FUN_001bd812 @ 0x1bd812 (16 bytes) */
int FUN_001bd812()
{
  return "ir_mix";
}

/* FUN_001bd822 @ 0x1bd822 (10 bytes) */
int FUN_001bd822()
{
  return 1;
}

/* FUN_001bd82c @ 0x1bd82c (5 bytes) */
int FUN_001bd82c()
{
  return;
}

