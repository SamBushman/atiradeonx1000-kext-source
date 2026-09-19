#include "decls.h"

/* _cxa_atexit_check_2 @ 0x7ae (17 bytes) */
int _cxa_atexit_check_2(param_1)
  undefined4 *param_1;
{
  *param_1 = 1;
  return;
}

/* _cxa_atexit_check_1 @ 0x7bf (68 bytes) */
int _cxa_atexit_check_1(param_1)
  undefined4 *param_1;
{
  int iVar1;
  int unaff_EBX;
  
  ((int (*)())___i686_get_pc_thunk_bx)();
  iVar1 = (*(code *)param_1[1])(unaff_EBX + -0x1d,param_1,param_1);
  if (iVar1 != 0) {
    *param_1 = 0xffffffff;
  }
  return;
}

/* _check_cxa_atexit @ 0x803 (117 bytes) */
int _check_cxa_atexit(param_1, param_2)
  code *param_1;
  code *param_2;
{
  int iVar1;
  int unaff_EBX;
  int local_20;
  int local_14;
  code *local_10;
  
  ((int (*)())___i686_get_pc_thunk_bx)();
  local_14 = 0;
  local_10 = param_1;
  iVar1 = (*param_1)(unaff_EBX + -0x50,&local_14,&local_14);
  if (iVar1 == 0) {
    (*param_2)(&local_14);
    if (local_14 == 0) {
      (*param_2)(&local_14);
      local_14 = 0;
    }
    local_20 = local_14;
  }
  else {
    local_20 = -1;
  }
  return local_20;
}

/* _get_globals @ 0x878 (365 bytes) */
int _get_globals()
{
  int iVar1;
  undefined4 uVar2;
  int unaff_EBX;
  void *local_1c;
  void *local_18;
  int local_14;
  int local_10;
  
  ((int (*)())___i686_get_pc_thunk_bx)();
  iVar1 = __keymgr_get_and_lock_processwide_ptr_2(0xe,&local_1c);
  if (iVar1 != 0) {
    return (void *)0x0;
  }
  local_18 = local_1c;
  if ((local_1c == (void *)0x0) && (local_18 = _calloc(0x14,1), local_18 == (void *)0x0)) {
    return (void *)0x0;
  }
  if (*(char *)((int)local_18 + 3) != '\0') {
    return local_18;
  }
  local_14 = _dlopen(unaff_EBX + 0xc6a5,0x10);
  if (local_14 != 0) {
    uVar2 = _dlsym(local_14,unaff_EBX + 0xc6c0);
    *(undefined4 *)((int)local_18 + 8) = uVar2;
    uVar2 = _dlsym(local_14,unaff_EBX + 0xc6cd);
    *(undefined4 *)((int)local_18 + 0xc) = uVar2;
    if (((*(int *)((int)local_18 + 8) != 0) && (*(int *)((int)local_18 + 0xc) != 0)) &&
       (local_10 = ((int (*)())_check_cxa_atexit)(*(undefined4 *)((int)local_18 + 8),
                                     *(undefined4 *)((int)local_18 + 0xc)), local_10 != -1)) {
      if (local_10 == 0) {
        *(undefined1 *)((int)local_18 + 3) = 2;
      }
      else {
        uVar2 = _dlsym(local_14,unaff_EBX + 0xc6dc);
        *(undefined4 *)((int)local_18 + 0x10) = uVar2;
        if (*(int *)((int)local_18 + 0x10) == 0) goto LAB_000009c2;
        *(undefined1 *)((int)local_18 + 3) = 0x10;
      }
      return local_18;
    }
  }
LAB_000009c2:
  __keymgr_set_and_unlock_processwide_ptr(0xe,local_18);
  return (void *)0x0;
}

/* _add_routine @ 0x9e5 (153 bytes) */
int _add_routine(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  undefined4 *puVar1;
  int iVar2;
  undefined4 local_24;
  undefined4 local_20;
  
  puVar1 = _malloc(0x10);
  if (puVar1 == (undefined4 *)0x0) {
    __keymgr_set_and_unlock_processwide_ptr(0xe,param_1);
    local_24 = 0xffffffff;
  }
  else {
    puVar1[1] = *param_2;
    puVar1[2] = param_2[1];
    puVar1[3] = param_2[2];
    *puVar1 = *(undefined4 *)(param_1 + 4);
    *(undefined4 **)(param_1 + 4) = puVar1;
    iVar2 = __keymgr_set_and_unlock_processwide_ptr(0xe,param_1);
    if (iVar2 == 0) {
      local_20 = 0;
    }
    else {
      local_20 = 0xffffffff;
    }
    local_24 = local_20;
  }
  return local_24;
}

/* _run_routines @ 0xa7e (188 bytes) */
int _run_routines(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  undefined4 *puVar1;
  uint uVar2;
  byte local_20;
  
  while( true ) {
    puVar1 = *(undefined4 **)(param_1 + 4);
    if (puVar1 == (undefined4 *)0x0) {
      return param_1;
    }
    if (puVar1 == param_2) break;
    *(undefined4 *)(param_1 + 4) = *puVar1;
    __keymgr_set_and_unlock_processwide_ptr(0xe,param_1);
    if ((uint)puVar1[2] < 6) {
      local_20 = (byte)puVar1[2];
      uVar2 = 1 << (local_20 & 0x1f);
      if ((uVar2 & 0x15) == 0) {
        if ((uVar2 & 0x2a) != 0) {
          (*(code *)puVar1[1])(puVar1[3]);
        }
      }
      else {
        (*(code *)puVar1[1])();
      }
    }
    _free(puVar1);
    param_1 = __keymgr_get_and_lock_processwide_ptr(0xe);
    if (param_1 == 0) {
      return 0;
    }
  }
  return param_1;
}

/* _cxa_atexit_wrapper @ 0xb3a (209 bytes) */
int _cxa_atexit_wrapper(param_1)
  undefined4 *param_1;
{
  int local_18;
  undefined4 local_14;
  undefined1 local_d;
  
  local_14 = 0;
  local_d = 0;
  local_18 = __keymgr_get_and_lock_processwide_ptr(0xe);
  if (local_18 != 0) {
    local_d = *(undefined1 *)(local_18 + 2);
    *(undefined1 *)(local_18 + 2) = 1;
    local_14 = *(undefined4 *)(local_18 + 4);
    __keymgr_set_and_unlock_processwide_ptr(0xe,local_18);
  }
  if (param_1[1] == 0) {
    (*(code *)*param_1)();
  }
  else {
    (*(code *)*param_1)(param_1[2]);
  }
  if (local_18 != 0) {
    local_18 = __keymgr_get_and_lock_processwide_ptr(0xe);
  }
  if (local_18 != 0) {
    local_18 = ((int (*)())_run_routines)(local_18,local_14);
  }
  if (local_18 != 0) {
    *(undefined1 *)(local_18 + 2) = local_d;
    __keymgr_set_and_unlock_processwide_ptr(0xe,local_18);
  }
  return;
}

/* _atexit_common @ 0xc0b (406 bytes) */
int _atexit_common(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  code *pcVar1;
  int iVar2;
  undefined4 *puVar3;
  int unaff_EBX;
  undefined4 local_30;
  
  ((int (*)())___i686_get_pc_thunk_bx)();
  iVar2 = ((int (*)())_get_globals)();
  if (iVar2 == 0) {
    local_30 = 0xffffffff;
  }
  else if ((*(char *)(iVar2 + 2) == '\0') && (*(char *)(iVar2 + 3) != '\x01')) {
    if (*(byte *)(iVar2 + 3) < 0x10) {
      pcVar1 = *(code **)(iVar2 + 8);
      iVar2 = __keymgr_set_and_unlock_processwide_ptr(0xe,iVar2);
      if (iVar2 == 0) {
        puVar3 = _malloc(0xc);
        if (puVar3 == (undefined4 *)0x0) {
          local_30 = 0xffffffff;
        }
        else {
          *puVar3 = *param_1;
          puVar3[1] = param_1[1];
          puVar3[2] = param_1[2];
          local_30 = (*pcVar1)(unaff_EBX + -0xdd,puVar3,param_2);
        }
      }
      else {
        local_30 = 0xffffffff;
      }
    }
    else if (param_1[1] == 0) {
      pcVar1 = *(code **)(iVar2 + 0x10);
      iVar2 = __keymgr_set_and_unlock_processwide_ptr(0xe,iVar2);
      if (iVar2 == 0) {
        local_30 = (*pcVar1)(*param_1);
      }
      else {
        local_30 = 0xffffffff;
      }
    }
    else {
      pcVar1 = *(code **)(iVar2 + 8);
      iVar2 = __keymgr_set_and_unlock_processwide_ptr(0xe,iVar2);
      if (iVar2 == 0) {
        local_30 = (*pcVar1)(*param_1,param_1[2],param_2);
      }
      else {
        local_30 = 0xffffffff;
      }
    }
  }
  else {
    local_30 = ((int (*)())_add_routine)(iVar2,param_1);
  }
  return local_30;
}

/* ___cxa_atexit @ 0xda1 (45 bytes) */
int ___cxa_atexit(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  local_18 = param_1;
  local_14 = 1;
  local_10 = param_2;
  ((int (*)())_atexit_common)(&local_18,param_3);
  return;
}

/* _atexit @ 0xdce (54 bytes) */
int _atexit(param_1)
  void *param_1;
{
  int iVar1;
  int unaff_EBX;
  void *local_18;
  undefined4 local_14;
  
  ((int (*)())___i686_get_pc_thunk_bx)();
  local_18 = param_1;
  local_14 = 0;
  iVar1 = ((int (*)())_atexit_common)(&local_18,*(undefined4 *)(&DAT_0000d2b2 + unaff_EBX));
  return iVar1;
}

/* __SetSurface @ 0xe04 (159 bytes) */
int __SetSurface(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  int param_3;
{
  int iVar1;
  int local_18;
  uint local_14;
  undefined4 local_10;
  
  if ((param_2 & 0x800) == 0) {
    local_18 = *(int *)(param_1 + 0x84);
    local_14 = 0;
  }
  else {
    if (*(int *)(param_3 + 0x28) == 0) {
      return -0x1ffffd28;
    }
    local_18 = *(int *)(*(int *)(param_3 + 0x28) + 8);
    local_14 = param_2;
  }
  local_10 = 0x30;
  iVar1 = _io_connect_method_scalarI_structureO
                    (*(undefined4 *)(param_1 + 0xc),0,&local_18,2,param_1 + 0x4c,&local_10);
  if (iVar1 == 0) {
    if ((local_18 == 0) || (local_14 == 0)) {
      param_3 = 0;
    }
    *(int *)(param_1 + 0x8c) = param_3;
    iVar1 = 0;
  }
  return iVar1;
}

/* __SetDestination @ 0xea3 (25 bytes) */
int __SetDestination()
{
  ((int (*)())__SetSurface)();
  return;
}

/* __LockSurface @ 0xebc (141 bytes) */
int __LockSurface(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  int *param_4;
{
  int iVar1;
  int local_18;
  undefined4 local_14;
  undefined4 local_10 [2];
  
  if (*(int *)(param_3 + 0x28) == 0) {
    return -0x1ffffd28;
  }
  iVar1 = *(int *)(*(int *)(param_3 + 0x28) + 4);
  if (iVar1 == 0) {
    local_18 = param_2;
    local_10[0] = 2;
    iVar1 = _io_connect_method_scalarI_scalarO
                      (*(undefined4 *)(param_1 + 0xc),5,&local_18,1,&local_18,local_10);
    if (iVar1 == 0) {
      *param_4 = local_18;
      *(undefined4 *)(param_3 + 0x18) = local_14;
      return 0;
    }
  }
  else {
    *param_4 = iVar1;
    iVar1 = 0;
  }
  return iVar1;
}

/* __UnlockSurface @ 0xf49 (120 bytes) */
int __UnlockSurface(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 param_2;
  int param_3;
  undefined4 *param_4;
{
  undefined4 uVar1;
  undefined4 local_14;
  undefined4 local_10 [3];
  
  if (*(int *)(param_3 + 0x28) == 0) {
    return 0xe00002d8;
  }
  if (*(int *)(*(int *)(param_3 + 0x28) + 4) == 0) {
    local_14 = param_2;
    local_10[0] = 1;
    uVar1 = _io_connect_method_scalarI_scalarO
                      (*(undefined4 *)(param_1 + 0xc),6,&local_14,1,&local_14,local_10);
    if (param_4 != (undefined4 *)0x0) {
      *param_4 = local_14;
      return uVar1;
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

/* __SwapSurface @ 0xfc1 (113 bytes) */
int __SwapSurface(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 param_2;
  int param_3;
  undefined4 *param_4;
{
  undefined4 uVar1;
  undefined4 local_14;
  undefined4 local_10 [2];
  
  if (*(int *)(param_3 + 0x28) != 0) {
    local_14 = param_2;
    local_10[0] = 1;
    uVar1 = _io_connect_method_scalarI_scalarO
                      (*(undefined4 *)(param_1 + 0xc),3,&local_14,1,&local_14,local_10);
    if (param_4 != (undefined4 *)0x0) {
      *param_4 = local_14;
    }
    return uVar1;
  }
  return 0xe00002d8;
}

/* __Probe @ 0x1032 (16 bytes) */
int __Probe()
{
  undefined4 *in_stack_00000010;
  
  *in_stack_00000010 = 2000;
  return 0;
}

/* _window_mode_to_ati_format @ 0x1044 (37 bytes) */
int _window_mode_to_ati_format(param_1)
  uint param_1;
{
  uint uVar1;
  undefined4 uVar2;
  int extraout_ECX;
  
  ((int (*)())___i686_get_pc_thunk_cx)();
  uVar1 = (param_1 & 0xf) - 3;
  if (uVar1 < 0xb) {
                    
                    
    uVar2 = (*(code *)(*(int *)(extraout_ECX + 0x1c + uVar1 * 4) + extraout_ECX))();
    return uVar2;
  }
  return 0;
}

/* __QueryInterface @ 0x10d7 (407 bytes) */
int __QueryInterface(param_1, param_2, param_3, param_4, param_5, param_6)
  int *param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 *param_6;
{
  char cVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  uVar2 = _CFUUIDCreateFromUUIDBytes(0,param_2,param_3,param_4,param_5);
  uVar3 = _CFUUIDGetConstantUUIDWithBytes
                    (0,0x67,0x66,0xe9,0x4a,0,0,0,0,0,0,0,10,0x27,0x89,0x90,0x4e);
  cVar1 = _CFEqual(uVar2,uVar3);
  if (cVar1 == '\0') {
    uVar3 = _CFUUIDGetConstantUUIDWithBytes(0,0,0,0,0,0,0,0,0,0xc0,0,0,0,0,0,0,0x46);
    cVar1 = _CFEqual(uVar2,uVar3);
    if (cVar1 == '\0') {
      *param_6 = 0;
      return 0x80000004;
    }
  }
  (**(code **)(*param_1 + 8))(param_1);
  *param_6 = param_1;
  return 0;
}

/* __AddRef @ 0x126e (17 bytes) */
int __AddRef(param_1)
  int param_1;
{
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
  return;
}

/* __DecodePixelFormat @ 0x127f (531 bytes) */
int __DecodePixelFormat(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  uint param_1;
  undefined4 *param_2;
  undefined4 *param_3;
  undefined4 *param_4;
  undefined4 *param_5;
  undefined4 *param_6;
  undefined4 *param_7;
  undefined4 *param_8;
{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_14;
  undefined4 local_10;
  
  if (param_1 != 0x32767579) {
    if (param_1 < 0x3276757a) {
      if (param_1 == 0x10) {
        local_14 = 3;
        uVar3 = 1;
        uVar2 = 2;
        local_10 = 1;
        uVar1 = 7;
        local_24 = 0xb;
        local_20 = 3;
      }
      else if (param_1 == 0x20) {
        local_14 = 6;
        uVar3 = 2;
        uVar2 = 4;
        local_10 = 2;
        uVar1 = 0xb;
        local_24 = 6;
        local_20 = 4;
      }
      else {
        if (param_1 != 8) {
          return 0;
        }
        local_14 = 9;
        uVar3 = 0;
        uVar2 = 1;
        local_10 = 0;
        uVar1 = 0;
        local_24 = 0;
        local_20 = 0;
      }
      goto LAB_0000132b;
    }
    if (param_1 == 0x42475241) {
      local_14 = 6;
      uVar3 = 2;
      uVar2 = 4;
      local_10 = 0;
      uVar1 = 8;
      local_24 = 6;
      local_20 = 10;
      goto LAB_0000132b;
    }
    if (param_1 < 0x42475242) {
      if (param_1 != 0x42343434) {
        return 0;
      }
      local_14 = 3;
      uVar3 = 1;
      uVar2 = 2;
      local_10 = 1;
      uVar1 = 6;
      local_24 = 10;
      local_20 = 0;
      goto LAB_0000132b;
    }
    if (param_1 != 0x59565955) {
      if (param_1 != 0x79757673) {
        return 0;
      }
      local_14 = 3;
      uVar3 = 1;
      uVar2 = 2;
      local_10 = 0;
      uVar1 = 0x26;
      local_24 = 0x14;
      local_20 = 6;
      goto LAB_0000132b;
    }
  }
  local_14 = 3;
  uVar3 = 1;
  uVar2 = 2;
  local_10 = 0;
  uVar1 = 0x27;
  local_24 = 0x15;
  local_20 = 9;
LAB_0000132b:
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = local_24;
  }
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = local_10;
  }
  if (param_5 != (undefined4 *)0x0) {
    *param_5 = local_14;
  }
  if (param_4 != (undefined4 *)0x0) {
    *param_4 = uVar2;
  }
  if (param_6 != (undefined4 *)0x0) {
    *param_6 = uVar3;
  }
  if (param_7 != (undefined4 *)0x0) {
    *param_7 = local_20;
  }
  if (param_8 != (undefined4 *)0x0) {
    *param_8 = uVar1;
  }
  return 1;
}

/* _fillTextureWithPattern @ 0x1492 (671 bytes) */
int _fillTextureWithPattern(param_1)
  undefined4 param_1;
{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined2 uVar4;
  undefined4 uVar5;
  undefined4 extraout_ECX;
  int iVar6;
  int unaff_EBX;
  int iVar7;
  int iVar8;
  undefined8 uVar9;
  int local_7c;
  int local_78;
  uint local_58;
  uint local_54;
  uint local_50;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  uint local_1c;
  uint local_18;
  uint local_14;
  
  uVar9 = ((int (*)())___i686_get_pc_thunk_bx)();
  if (((uint)((ulonglong)uVar9 >> 0x20) & 0x7ffff000) == 0x6000) {
    local_54 = 0xffffffff;
    local_50 = 0xffffffff;
    iVar7 = *(int *)(unaff_EBX + 0xc244);
  }
  else {
    uVar2 = *(uint *)*(int *)uVar9;
    local_54 = uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 | uVar2 << 0x18;
    uVar2 = ((uint *)*(int *)uVar9)[1];
    local_50 = uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 | uVar2 << 0x18;
    iVar7 = *(int *)(unaff_EBX + 0xc244);
  }
  if (iVar7 == 0x10) {
    iVar7 = *(int *)(unaff_EBX + 0xc1ac);
    iVar3 = *(int *)(unaff_EBX + 0xc1a8);
    iVar6 = iVar3 * 0x10;
    iVar8 = 0;
    local_14 = 0x80000000;
    local_24 = 0x20;
    local_7c = iVar6 + iVar7;
    do {
      while( true ) {
        uVar4 = (short)param_1;
        if ((local_54 & local_14) == 0) {
          uVar4 = (short)extraout_ECX;
        }
        iVar1 = iVar8 * 2;
        *(undefined2 *)(iVar1 + iVar7) = uVar4;
        *(undefined2 *)(iVar1 + 0x10 + iVar7) = uVar4;
        *(undefined2 *)(iVar7 + (iVar3 * 8 + iVar8) * 2) = uVar4;
        *(undefined2 *)(local_7c + 0x10 + iVar1) = uVar4;
        iVar8 = iVar8 + 1;
        if (iVar8 != 8) break;
        iVar7 = iVar7 + iVar3 * 2;
        iVar8 = 0;
        local_7c = iVar6 + iVar7;
        local_14 = local_14 >> 1;
        local_24 = local_24 + -1;
        if (local_24 == 0) goto LAB_000016cb;
      }
      local_14 = local_14 >> 1;
      local_24 = local_24 + -1;
    } while (local_24 != 0);
LAB_000016cb:
    iVar8 = 0;
    local_18 = 0x80000000;
    local_20 = 0x20;
    while( true ) {
      uVar4 = (short)param_1;
      if ((local_50 & local_18) == 0) {
        uVar4 = (short)extraout_ECX;
      }
      iVar1 = iVar8 * 2;
      *(undefined2 *)(iVar1 + iVar7) = uVar4;
      *(undefined2 *)(iVar1 + 0x10 + iVar7) = uVar4;
      *(undefined2 *)(iVar7 + (iVar3 * 8 + iVar8) * 2) = uVar4;
      *(undefined2 *)(local_7c + 0x10 + iVar1) = uVar4;
      iVar8 = iVar8 + 1;
      if (iVar8 == 8) {
        iVar7 = iVar7 + iVar3 * 2;
        iVar8 = 0;
      }
      local_18 = local_18 >> 1;
      local_20 = local_20 + -1;
      if (local_20 == 0) break;
      local_7c = iVar6 + iVar7;
    }
  }
  else {
    iVar7 = *(int *)(unaff_EBX + 0xc1ac);
    iVar3 = *(int *)(unaff_EBX + 0xc1a8);
    iVar6 = iVar3 * 0x20;
    iVar8 = 0;
    local_1c = 0x80000000;
    local_2c = 0x20;
    local_78 = iVar6 + iVar7;
    do {
      while( true ) {
        uVar5 = param_1;
        if ((local_54 & local_1c) == 0) {
          uVar5 = extraout_ECX;
        }
        iVar1 = iVar8 * 4;
        *(undefined4 *)(iVar1 + iVar7) = uVar5;
        *(undefined4 *)(iVar1 + 0x20 + iVar7) = uVar5;
        *(undefined4 *)(iVar7 + (iVar3 * 8 + iVar8) * 4) = uVar5;
        *(undefined4 *)(local_78 + 0x20 + iVar1) = uVar5;
        iVar8 = iVar8 + 1;
        if (iVar8 != 8) break;
        iVar7 = iVar7 + iVar3 * 4;
        iVar8 = 0;
        local_78 = iVar6 + iVar7;
        local_1c = local_1c >> 1;
        local_2c = local_2c + -1;
        if (local_2c == 0) goto LAB_000015a4;
      }
      local_1c = local_1c >> 1;
      local_2c = local_2c + -1;
    } while (local_2c != 0);
LAB_000015a4:
    iVar8 = 0;
    local_58 = 0x80000000;
    local_28 = 0x20;
    while( true ) {
      uVar5 = param_1;
      if ((local_50 & local_58) == 0) {
        uVar5 = extraout_ECX;
      }
      iVar1 = iVar8 * 4;
      *(undefined4 *)(iVar1 + iVar7) = uVar5;
      *(undefined4 *)(iVar1 + 0x20 + iVar7) = uVar5;
      *(undefined4 *)(iVar7 + (iVar3 * 8 + iVar8) * 4) = uVar5;
      *(undefined4 *)(local_78 + 0x20 + iVar1) = uVar5;
      iVar8 = iVar8 + 1;
      if (iVar8 == 8) {
        iVar7 = iVar7 + iVar3 * 4;
        iVar8 = 0;
      }
      if (local_28 == 1) break;
      local_28 = local_28 + -1;
      local_58 = local_58 >> 1;
      local_78 = iVar6 + iVar7;
    }
  }
  return;
}

/* __GetCapabilities @ 0x1731 (145 bytes) */
int __GetCapabilities(param_1, param_2, param_3)
  int param_1;
  int param_2;
  undefined4 *param_3;
{
  undefined4 uVar1;
  int unaff_EBX;
  
  ((int (*)())___i686_get_pc_thunk_bx)();
  if (param_2 != 0x63676c73) {
    if (param_2 == 0x736d766c) {
      if ((param_1 == 0) || (*(int *)(param_1 + 0xc) == 0)) {
        return 0xe00002d8;
      }
      uVar1 = _io_connect_method_scalarI_structureI(*(int *)(param_1 + 0xc),0xf,param_3,1,0,0);
    }
    else {
      if (param_2 == 0x42475241) goto LAB_00001760;
      uVar1 = 0xe00002c7;
    }
    return uVar1;
  }
LAB_00001760:
  *param_3 = **(undefined4 **)(unaff_EBX + 0xc957);
  return 0;
}

/* __GetBlitter @ 0x17c2 (170 bytes) */
int __GetBlitter(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  undefined4 param_2;
  int param_3;
  uint param_4;
  int *param_5;
{
  int extraout_ECX;
  int iVar1;
  
  ((int (*)())___i686_get_pc_thunk_cx)();
  param_4 = param_4 & 0x7ffff000;
  if (param_3 == 1) {
    if ((param_4 == 0) || (param_4 == 0x1000)) {
      iVar1 = extraout_ECX + 0x216e;
      *param_5 = iVar1;
      goto joined_r0x00001827;
    }
LAB_000017f7:
    iVar1 = 0;
  }
  else {
    if (param_3 != 4) {
      if (param_3 == 0) {
        if (param_4 == 0x6000) {
LAB_0000180e:
          iVar1 = extraout_ECX + 0x6df0;
          goto LAB_000017f9;
        }
      }
      else if (param_3 == 0x40000) {
        if (param_4 == 0x6000) {
          iVar1 = extraout_ECX + 0x9459;
          goto LAB_000017f9;
        }
      }
      else if (param_3 == 0x100) {
        if (param_4 == 0x5000) goto LAB_0000180e;
      }
      else if ((param_3 == 3) && (param_4 == 0x6000)) {
        iVar1 = extraout_ECX + 0xa877;
        goto LAB_000017f9;
      }
      goto LAB_000017f7;
    }
    iVar1 = extraout_ECX + 0x3409;
  }
LAB_000017f9:
  *param_5 = iVar1;
joined_r0x00001827:
  if (iVar1 == 0) {
    return 0xe00002c7;
  }
  return 0;
}

/* __Synchronize @ 0x186c (7 bytes) */
int __Synchronize()
{
  return 0;
}

/* __GetBeamPosition @ 0x1873 (87 bytes) */
int __GetBeamPosition(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  uint *param_3;
{
  uint local_14 [4];
  
  local_14[1] = 4;
  local_14[0] = *(uint *)(param_1 + 0x90);
  _io_connect_method_structureI_structureO
            (*(undefined4 *)(param_1 + 0xc),0x10,local_14,4,local_14,local_14 + 1);
  *param_3 = local_14[0] >> 0x10 & 0x7ff;
  return;
}

/* __WaitSurface @ 0x18ca (81 bytes) */
int __WaitSurface(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  int param_3;
{
  int iVar1;
  undefined4 uVar2;
  
  if (*(int **)(param_3 + 0x28) != (int *)0x0) {
    iVar1 = **(int **)(param_3 + 0x28);
    uVar2 = 0;
    if (iVar1 != 0) {
      uVar2 = _io_connect_method_scalarI_structureI(*(undefined4 *)(param_1 + 0xc),0xc,iVar1,1,0,0);
    }
    return uVar2;
  }
  return 0xe00002d8;
}

/* _ATIRadeonX1000GAFactory @ 0x191b (395 bytes) */
int _ATIRadeonX1000GAFactory(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int unaff_EBX;
  
  ((int (*)())___i686_get_pc_thunk_bx)();
  uVar2 = _CFUUIDGetConstantUUIDWithBytes(0,0xac,0xcf,0,0,0,0,0,0,0,0,0,10,0x27,0x89,0x90,0x4e);
  cVar1 = _CFEqual(param_2,uVar2);
  if (cVar1 == '\0') {
    return (int *)0x0;
  }
  iVar3 = _CFUUIDGetConstantUUIDWithBytes(0,0x10,2,0x71,0,0,0,0,0,0,0,0,10,0x27,0x89,0x8d,0x3e);
  piVar4 = _calloc(1,0x98);
  *piVar4 = unaff_EBX + 0xbc37;
  if (iVar3 != 0) {
    iVar5 = _CFRetain(iVar3);
    piVar4[1] = iVar5;
    _CFPlugInAddInstanceForFactory(iVar3);
  }
  piVar4[2] = 1;
  return piVar4;
}

/* __Release @ 0x1aa6 (73 bytes) */
int __Release(param_1)
  void *param_1;
{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)((int)param_1 + 8) + -1;
  *(int *)((int)param_1 + 8) = iVar2;
  if (iVar2 == 0) {
    iVar1 = *(int *)((int)param_1 + 4);
    _free(param_1);
    if (iVar1 != 0) {
      _CFPlugInRemoveInstanceForFactory(iVar1);
      _CFRelease(iVar1);
      return 0;
    }
  }
  return iVar2;
}

/* __Reset @ 0x1aef (389 bytes) */
int __Reset(param_1)
  int param_1;
{
  uint *puVar1;
  int iVar2;
  undefined4 uVar3;
  int unaff_EBX;
  int local_28;
  int local_24 [5];
  
  ((int (*)())___i686_get_pc_thunk_bx)();
  if (*(int *)(param_1 + 0xc) == 0) {
    return 0xe00002d8;
  }
  iVar2 = _IOConnectMapMemory(*(int *)(param_1 + 0xc),1,**(undefined4 **)(unaff_EBX + 0xc593),
                              &local_28,local_24 + 1,1);
  if ((iVar2 == 0) && (local_28 != 0)) {
    *(int *)(param_1 + 0x14) = local_28;
    local_24[1] = 1;
    *(undefined4 *)(local_28 + 0x20) = 0x80000000;
    *(undefined4 *)(local_28 + 0x14) = 1;
  }
  if (*(int *)(param_1 + 0x18) != 0) {
    **(undefined4 **)(param_1 + 0x80) = 0x1000000;
    puVar1 = *(uint **)(param_1 + 0x7c);
    *puVar1 = *puVar1 | *(int *)(param_1 + 0x80) - (int)puVar1 >> 2;
  }
  iVar2 = _IOConnectMapMemory(*(undefined4 *)(param_1 + 0xc),0,**(undefined4 **)(unaff_EBX + 0xc593)
                              ,local_24,local_24 + 1,1);
  if ((iVar2 == 0) && (local_24[0] != 0)) {
    *(int *)(param_1 + 0x18) = local_24[0];
    *(int *)(param_1 + 0x80) = local_24[0] + 0x20;
    *(int *)(param_1 + 0x7c) = local_24[0] + 0x1c;
    *(undefined4 *)(local_24[0] + 0x1c) = 0;
  }
  *(uint *)(param_1 + 0x90) = (-(uint)(*(int *)(param_1 + 0x84) == 0) & 0xffffff00) + 0x310;
  *(undefined4 *)(param_1 + 0x94) = 0;
  uVar3 = ((int (*)())__SetDestination)(param_1,0,0);
  *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(param_1 + 0x4c);
  *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(param_1 + 0x50);
  *(undefined4 *)(param_1 + 0x24) = *(undefined4 *)(param_1 + 0x54);
  *(undefined4 *)(param_1 + 0x28) = *(undefined4 *)(param_1 + 0x58);
  *(undefined4 *)(param_1 + 0x2c) = *(undefined4 *)(param_1 + 0x5c);
  *(undefined4 *)(param_1 + 0x30) = *(undefined4 *)(param_1 + 0x60);
  *(undefined4 *)(param_1 + 0x34) = *(undefined4 *)(param_1 + 100);
  *(undefined4 *)(param_1 + 0x38) = *(undefined4 *)(param_1 + 0x68);
  *(undefined4 *)(param_1 + 0x3c) = *(undefined4 *)(param_1 + 0x6c);
  *(undefined4 *)(param_1 + 0x40) = *(undefined4 *)(param_1 + 0x70);
  *(undefined4 *)(param_1 + 0x44) = *(undefined4 *)(param_1 + 0x74);
  *(undefined4 *)(param_1 + 0x48) = *(undefined4 *)(param_1 + 0x78);
  return uVar3;
}

/* __Start @ 0x1c74 (360 bytes) */
int __Start(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  int iVar1;
  int unaff_EBX;
  undefined1 local_a8 [128];
  undefined4 local_28;
  int local_24;
  int local_20 [4];
  
  ((int (*)())___i686_get_pc_thunk_bx)();
  iVar1 = _IOAccelFindAccelerator(param_3,local_20,param_1 + 0x84);
  if (iVar1 == 0) {
    iVar1 = _IOObjectConformsTo(local_20[0],unaff_EBX + 0xb2e3);
    if (iVar1 == 0) {
      iVar1 = _IOObjectGetClass(local_20[0],local_a8);
      if (iVar1 == 0) {
        _printf((char *)(unaff_EBX + 0xb2f2),local_a8);
        iVar1 = -0x1ffffd39;
      }
      else {
        iVar1 = -0x1ffffd39;
      }
    }
    else {
      iVar1 = _IOServiceOpen(local_20[0],**(undefined4 **)(unaff_EBX + 0xc40b),2,&local_24);
      if (iVar1 == 0) {
        *(int *)(param_1 + 0x10) = local_20[0];
        *(int *)(param_1 + 0xc) = local_24;
        local_28 = 2;
        iVar1 = _io_connect_method_scalarI_scalarO(local_24,1,0,0,param_1 + 0x88,&local_28);
        if ((iVar1 == 0) && (iVar1 = ((int (*)())__Reset)(param_1,0), iVar1 == 0)) {
          return 0;
        }
      }
      if (local_24 != 0) {
        _IOServiceClose(local_24);
      }
      if (local_20[0] != 0) {
        _IOObjectRelease(local_20[0]);
        return iVar1;
      }
    }
  }
  return iVar1;
}

/* __AllocateSurface @ 0x1ddc (1564 bytes) */
int __AllocateSurface(param_1, param_2, param_3, param_4)
  int param_1;
  uint param_2;
  uint *param_3;
  undefined4 param_4;
{
  char cVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int *piVar6;
  uint uVar7;
  uint uVar8;
  bool bVar9;
  undefined4 *local_74;
  uint local_6c;
  int local_68;
  void *local_5c;
  uint local_48;
  int local_44;
  uint local_34;
  uint local_30;
  uint local_2c;
  int *local_20;
  undefined4 local_1c;
  uint local_18 [3];
  
  local_74 = _calloc(1,0x3c);
  if ((param_2 & 1) == 0) {
    if ((param_2 & 8) == 0) {
      cVar1 = ((int (*)())__DecodePixelFormat)(local_74 + 10,local_18,local_74 + 0xb,0,local_74 + 0xe);
      if (cVar1 == '\0') goto LAB_00001e1b;
      uVar7 = local_74[10];
      local_74[7] = param_3[6] / uVar7;
      *(undefined2 *)(local_74 + 3) = 0;
      *(undefined2 *)((int)local_74 + 0xe) = 0;
      uVar2 = param_3[4];
      *(short *)(local_74 + 4) = (short)uVar2;
      uVar4 = param_3[5];
      *(short *)((int)local_74 + 0x12) = (short)uVar4;
      local_74[5] = uVar2;
      local_74[6] = uVar4;
      uVar2 = uVar2 * uVar4 * uVar7 + 3;
      uVar4 = uVar2 >> 2;
      local_30 = (uVar2 & 0xfffffffc) + 0xfff & 0xfffff000;
      if (uVar4 < 0x4000) {
        iVar5 = 1;
      }
      else {
        iVar5 = 1;
        do {
          uVar4 = uVar4 >> 1;
          iVar5 = iVar5 * 2;
        } while (0x3fff < uVar4);
      }
      local_34 = ((uVar4 + 0xd) * iVar5 + 0x27 & 0xfffffff8) << 2;
      local_18[1] = 2;
      iVar5 = _io_connect_method_scalarI_scalarO
                        (*(undefined4 *)(param_1 + 0xc),9,&local_34,2,&local_20,local_18 + 1);
      if (iVar5 == 0) {
        *local_74 = local_1c;
        uVar2 = param_3[4];
        local_6c = param_3[5];
        uVar4 = uVar2 * uVar7;
        local_5c = (void *)*param_3;
        uVar7 = uVar7 * uVar2 * local_6c >> 2;
        local_48 = local_6c;
        if (uVar7 < 0x4000) {
          local_44 = 1;
        }
        else {
          local_44 = 1;
          do {
            local_48 = local_48 >> 1;
            local_6c = local_6c >> 1;
            uVar7 = uVar7 >> 1;
            local_44 = local_44 << 1;
          } while (0x3fff < uVar7);
        }
        uVar3 = 0x20;
        if (0x1f < uVar4) {
          uVar3 = uVar4;
        }
        local_20[5] = uVar3 * local_48;
        local_20[7] = local_44;
        *local_20 = local_44 * (uVar7 + 0xd) + 8;
        local_20[6] = uVar7 + 0xd;
        local_20[0x20] = 0x1393;
        local_20[0x21] = 10;
        local_20[0x22] = 0x5c8;
        piVar6 = local_20 + 0x24;
        local_20[0x23] = 0x20000;
        bVar9 = local_18[0] == 3;
        if (local_44 != 0) {
          local_68 = 0;
          do {
            *piVar6 = 0x5cb;
            piVar6[1] = (uint)bVar9 * 3;
            piVar6[2] = 0x51b;
            piVar6[3] = (local_18[0] & 0xf) << 8 | 0x53cc30f2;
            piVar6[4] = 0x10501;
            piVar6[5] = 0;
            piVar6[6] = uVar3;
            piVar6[7] = 0x5c0;
            piVar6[8] = 0;
            piVar6[9] = 0x1050e;
            piVar6[10] = 0;
            piVar6[0xb] = local_48 << 0x10 | uVar2;
            piVar6[0xc] = (uVar7 - 1) * 0x10000 | 0x85f0;
            piVar6 = piVar6 + 0xd;
            if (local_6c != 0) {
              uVar8 = 0;
              do {
                _bcopy(local_5c,piVar6,uVar4);
                local_5c = (void *)((int)local_5c + uVar4);
                piVar6 = (int *)((int)piVar6 + (uVar4 & 0xfffffffc));
                uVar8 = uVar8 + 1;
              } while (uVar8 != local_6c);
            }
            local_68 = local_68 + 1;
          } while (local_44 != local_68);
        }
        *piVar6 = 0xd0b;
        piVar6[1] = 5;
        piVar6[2] = 0x5c8;
        piVar6[3] = 0x10000;
        iVar5 = 0;
        goto LAB_00001e32;
      }
    }
    else if (((param_3[6] & 0x3f) == 0) &&
            (cVar1 = ((int (*)())__DecodePixelFormat)(local_74 + 10,0,local_74 + 0xb,0,local_74 + 0xe),
            cVar1 != '\0')) {
      uVar7 = param_3[6];
      local_74[7] = uVar7 / (uint)local_74[10];
      *(undefined2 *)(local_74 + 3) = 0;
      *(undefined2 *)((int)local_74 + 0xe) = 0;
      uVar2 = param_3[4];
      *(short *)(local_74 + 4) = (short)uVar2;
      local_2c = param_3[5];
      *(short *)((int)local_74 + 0x12) = (short)local_2c;
      local_74[5] = uVar2;
      local_74[6] = local_2c;
      local_34 = param_2;
      local_30 = *param_3;
      local_2c = local_2c * uVar7;
      local_18[1] = 1;
      iVar5 = _io_connect_method_scalarI_scalarO
                        (*(undefined4 *)(param_1 + 0xc),8,&local_34,3,local_74,local_18 + 1);
      if (iVar5 == 0) goto LAB_00001e32;
    }
    else {
LAB_00001e1b:
      iVar5 = -0x1ffffd39;
    }
  }
  else {
    local_74[2] = param_4;
    param_3[10] = (uint)local_74;
    iVar5 = ((int (*)())__SetDestination)(param_1,1,param_3);
    if (iVar5 == 0) {
      if ((param_2 & 2) != 0) {
        local_34 = param_2;
        local_30 = param_3[4];
        local_2c = param_3[5];
        local_18[1] = 0;
        iVar5 = _io_connect_method_scalarI_scalarO
                          (*(undefined4 *)(param_1 + 0xc),4,&local_34,3,0,local_18 + 1);
        if (iVar5 != 0) goto LAB_00001e20;
      }
      if (((param_2 & 0x10) == 0) ||
         (cVar1 = ((int (*)())__DecodePixelFormat)(local_74 + 10,0,local_74 + 0xb,local_18 + 2,local_74 + 0xe),
         cVar1 == '\0')) {
LAB_00002147:
        param_3[10] = (uint)local_74;
        return 0;
      }
      local_30 = local_74[10] * param_3[4] + 0x7f & 0xffffff80;
      param_3[6] = local_30;
      local_34 = local_18[2];
      local_30 = local_30 * (param_3[5] + 1);
      local_18[1] = 2;
      iVar5 = _io_connect_method_scalarI_scalarO
                        (*(undefined4 *)(param_1 + 0xc),10,&local_34,2,&local_20,local_18 + 1);
      if (iVar5 != 0) goto LAB_00002147;
      *local_74 = local_1c;
      local_74[7] = param_3[6] / (uint)local_74[10];
      *(undefined2 *)(local_74 + 3) = 0;
      *(undefined2 *)((int)local_74 + 0xe) = 0;
      uVar7 = param_3[4];
      *(short *)(local_74 + 4) = (short)uVar7;
      uVar2 = param_3[5];
      *(short *)((int)local_74 + 0x12) = (short)uVar2;
      local_74[5] = uVar7;
      local_74[6] = uVar2;
      local_74[1] = local_20;
      param_3[9] = 2;
      iVar5 = 0;
      goto LAB_00001e32;
    }
  }
LAB_00001e20:
  _free(local_74);
  local_74 = (undefined4 *)0x0;
LAB_00001e32:
  param_3[10] = (uint)local_74;
  return iVar5;
}

/* _radeon3DCopySetup @ 0x23f8 (1684 bytes) */
int _radeon3DCopySetup(param_1, param_2, param_3, param_4, param_5)
  uint param_1;
  int param_2;
  int param_3;
  int param_4;
  int param_5;
{
  int iVar1;
  int iVar2;
  int extraout_ECX;
  int extraout_EDX;
  uint uVar3;
  int unaff_EBX;
  int iVar4;
  uint local_18;
  
  ((int (*)())___i686_get_pc_thunk_bx)();
  if (*(uint *)(extraout_ECX + 0x2c) == 0) {
    if (param_1 == 6) {
      uVar3 = 0xfffffff9;
      local_18 = 0xc;
    }
    else if (param_1 == 3) {
      uVar3 = 0xfffffff8;
      local_18 = 0xb;
    }
    else {
      uVar3 = param_1 - 0x13;
      local_18 = param_1 & 0x1f;
    }
  }
  else {
    local_18 = (uint)(*(byte *)(unaff_EBX + (*(uint *)(extraout_ECX + 0x2c) & 0xff) * 0x1c + 0xac2f)
                     & 0x1f);
    uVar3 = local_18 - 0x13;
  }
  *(undefined4 *)(extraout_EDX + param_3 * 4) = 0x10ea;
  *(undefined4 *)(extraout_EDX + 4 + param_3 * 4) = 0x2da49525;
  *(undefined4 *)(extraout_EDX + 8 + param_3 * 4) = 0x10fa;
  *(undefined4 *)(extraout_EDX + 0xc + param_3 * 4) = 0xffffff;
  *(undefined4 *)(extraout_EDX + 0x10 + param_3 * 4) = 0x1004;
  *(undefined4 *)(extraout_EDX + 0x14 + param_3 * 4) = 0x66666666;
  *(undefined4 *)(extraout_EDX + 0x18 + param_3 * 4) = 0x1005;
  *(undefined4 *)(extraout_EDX + 0x1c + param_3 * 4) = 0x6666666;
  *(undefined4 *)(extraout_EDX + 0x20 + param_3 * 4) = 0x13c1;
  *(undefined4 *)(extraout_EDX + 0x24 + param_3 * 4) = 0;
  *(undefined4 *)(extraout_EDX + 0x28 + param_3 * 4) = 0x850;
  *(undefined4 *)(extraout_EDX + 0x2c + param_3 * 4) = 0x100;
  *(undefined4 *)(extraout_EDX + 0x30 + param_3 * 4) = 0x887;
  *(undefined4 *)(extraout_EDX + 0x34 + param_3 * 4) = 0x1c000;
  *(undefined4 *)(extraout_EDX + 0x38 + param_3 * 4) = 0x82c;
  *(undefined4 *)(extraout_EDX + 0x3c + param_3 * 4) = 0;
  *(undefined1 **)(extraout_EDX + 0x40 + param_3 * 4) = ((unsigned char *)0x000010ae);
  *(undefined4 *)(extraout_EDX + 0x44 + param_3 * 4) = 0;
  *(undefined4 *)(extraout_EDX + 0x48 + param_3 * 4) = 0x1002;
  *(undefined4 *)(extraout_EDX + 0x4c + param_3 * 4) = 0;
  *(undefined4 *)(extraout_EDX + 0x50 + param_3 * 4) = 0x824;
  *(undefined4 *)(extraout_EDX + 0x54 + param_3 * 4) = 1;
  *(undefined4 *)(extraout_EDX + 0x58 + param_3 * 4) = 0x825;
  *(undefined4 *)(extraout_EDX + 0x5c + param_3 * 4) = 2;
  *(undefined4 *)(extraout_EDX + 0x60 + param_3 * 4) = 0x82d;
  *(undefined4 *)(extraout_EDX + 100 + param_3 * 4) = 3;
  *(undefined4 *)(extraout_EDX + 0x68 + param_3 * 4) = 0x854;
  *(undefined4 *)(extraout_EDX + 0x6c + param_3 * 4) = 0x26010006;
  *(undefined4 *)(extraout_EDX + 0x70 + param_3 * 4) = 0x878;
  *(undefined4 *)(extraout_EDX + 0x74 + param_3 * 4) = 0xf688f688;
  *(undefined4 *)(extraout_EDX + 0x78 + param_3 * 4) = 0x13c0;
  *(undefined4 *)(extraout_EDX + 0x7c + param_3 * 4) = 0;
  *(undefined4 *)(extraout_EDX + 0x80 + param_3 * 4) = 0x13c1;
  *(undefined4 *)(extraout_EDX + 0x84 + param_3 * 4) = 0;
  *(undefined4 *)(extraout_EDX + 0x88 + param_3 * 4) = 0x12f5;
  *(undefined4 *)(extraout_EDX + 0x8c + param_3 * 4) = 0;
  *(undefined4 *)(extraout_EDX + 0x90 + param_3 * 4) = 0x12f0;
  *(undefined4 *)(extraout_EDX + 0x94 + param_3 * 4) = 0;
  *(undefined1 **)(extraout_EDX + 0x98 + param_3 * 4) = ((unsigned char *)0x000010a2);
  *(undefined4 *)(extraout_EDX + 0x9c + param_3 * 4) = 0;
  *(undefined4 *)(extraout_EDX + 0xa0 + param_3 * 4) = 0x1381;
  *(undefined4 *)(extraout_EDX + 0xa4 + param_3 * 4) = 0;
  *(undefined **)(extraout_EDX + 0xa8 + param_3 * 4) = ((unsigned char *)0x0000109e);
  *(undefined4 *)(extraout_EDX + 0xac + param_3 * 4) = 5;
  *(undefined4 *)(extraout_EDX + 0xb0 + param_3 * 4) = 0x1041;
  *(undefined4 *)(extraout_EDX + 0xb4 + param_3 * 4) = 1;
  *(undefined4 *)(extraout_EDX + 0xb8 + param_3 * 4) = 0x1094;
  *(undefined4 *)(extraout_EDX + 0xbc + param_3 * 4) = 0;
  *(undefined4 *)(extraout_EDX + 0xc0 + param_3 * 4) = 0x1095;
  *(undefined4 *)(extraout_EDX + 0xc4 + param_3 * 4) = 0x7803;
  *(undefined4 *)(extraout_EDX + 200 + param_3 * 4) = 0x1095;
  *(undefined4 *)(extraout_EDX + 0xcc + param_3 * 4) = 0x2400000;
  *(undefined4 *)(extraout_EDX + 0xd0 + param_3 * 4) = 0x1095;
  *(undefined4 *)(extraout_EDX + 0xd4 + param_3 * 4) = 0xe400e400;
  *(undefined4 *)(extraout_EDX + 0xd8 + param_3 * 4) = 0x1095;
  *(undefined4 *)(extraout_EDX + 0xdc + param_3 * 4) = 0;
  *(undefined4 *)(extraout_EDX + 0xe0 + param_3 * 4) = 0x1095;
  *(undefined4 *)(extraout_EDX + 0xe4 + param_3 * 4) = 0;
  *(undefined4 *)(extraout_EDX + 0xe8 + param_3 * 4) = 0x1095;
  *(undefined4 *)(extraout_EDX + 0xec + param_3 * 4) = 0;
  *(undefined4 *)(extraout_EDX + 0xf0 + param_3 * 4) = 0x1095;
  *(undefined4 *)(extraout_EDX + 0xf4 + param_3 * 4) = 0x78105;
  *(undefined4 *)(extraout_EDX + 0xf8 + param_3 * 4) = 0x1095;
  *(undefined4 *)(extraout_EDX + 0xfc + param_3 * 4) = 0;
  *(undefined4 *)(extraout_EDX + 0x100 + param_3 * 4) = 0x1095;
  *(undefined4 *)(extraout_EDX + 0x104 + param_3 * 4) = 0;
  *(undefined4 *)(extraout_EDX + 0x108 + param_3 * 4) = 0x1095;
  *(undefined4 *)(extraout_EDX + 0x10c + param_3 * 4) = 0xdb0220;
  *(undefined4 *)(extraout_EDX + 0x110 + param_3 * 4) = 0x1095;
  *(undefined4 *)(extraout_EDX + 0x114 + param_3 * 4) = 0xc0c000;
  *(undefined4 *)(extraout_EDX + 0x118 + param_3 * 4) = 0x1095;
  *(undefined4 *)(extraout_EDX + 0x11c + param_3 * 4) = 0x20490000;
  *(undefined4 *)(extraout_EDX + 0x120 + param_3 * 4) = 0x1189;
  *(undefined4 *)(extraout_EDX + 0x124 + param_3 * 4) = 0;
  *(undefined4 *)(extraout_EDX + 0x128 + param_3 * 4) = 0x1181;
  *(undefined4 *)(extraout_EDX + 300 + param_3 * 4) = 1;
  *(undefined4 *)(extraout_EDX + 0x130 + param_3 * 4) = 0x118d;
  *(undefined4 *)(extraout_EDX + 0x134 + param_3 * 4) = 0x10000;
  *(undefined4 *)(extraout_EDX + 0x138 + param_3 * 4) = 0x118e;
  *(undefined4 *)(extraout_EDX + 0x13c + param_3 * 4) = 0;
  *(undefined4 *)(extraout_EDX + 0x140 + param_3 * 4) = 0x118c;
  *(undefined4 *)(extraout_EDX + 0x144 + param_3 * 4) = 0x10000;
  *(undefined4 *)(extraout_EDX + 0x148 + param_3 * 4) = 0x11a9;
  if (uVar3 < 3) {
    *(undefined4 *)(extraout_EDX + (param_3 + 0x53) * 4) = 0x1b01;
  }
  else {
    *(undefined4 *)(extraout_EDX + (param_3 + 0x53) * 4) = 0x6c01;
  }
  iVar4 = param_3 + 0x54;
  *(undefined4 *)(extraout_EDX + iVar4 * 4) = 0x11aa;
  *(undefined4 *)(extraout_EDX + 4 + iVar4 * 4) = 0xf;
  *(undefined4 *)(extraout_EDX + 8 + iVar4 * 4) = 0x11ab;
  *(undefined4 *)(extraout_EDX + 0xc + iVar4 * 4) = 0xf;
  *(undefined4 *)(extraout_EDX + 0x10 + iVar4 * 4) = 0x11ac;
  *(undefined4 *)(extraout_EDX + 0x14 + iVar4 * 4) = 0xf;
  *(undefined **)(extraout_EDX + 0x18 + iVar4 * 4) = ((unsigned char *)0x000010c0);
  *(undefined4 *)(extraout_EDX + 0x1c + iVar4 * 4) = 0x40002;
  *(undefined **)(extraout_EDX + 0x20 + iVar4 * 4) = ((unsigned char *)0x000010c1);
  *(undefined4 *)(extraout_EDX + 0x24 + iVar4 * 4) = 0;
  *(undefined **)(extraout_EDX + 0x28 + iVar4 * 4) = ((unsigned char *)0x000010c8);
  *(undefined4 *)(extraout_EDX + 0x2c + iVar4 * 4) = 0x10;
  *(undefined4 *)(extraout_EDX + 0x30 + iVar4 * 4) = 0x101d;
  *(undefined4 *)(extraout_EDX + 0x34 + iVar4 * 4) = 0x280c2040;
  *(undefined4 *)(extraout_EDX + 0x38 + iVar4 * 4) = 0x1040;
  *(undefined4 *)(extraout_EDX + 0x3c + iVar4 * 4) = 0;
  *(undefined4 *)(extraout_EDX + 0x40 + iVar4 * 4) = 0x1100;
  *(uint *)(extraout_EDX + 0x44 + iVar4 * 4) =
       (uint)(_fillTextureWithPattern + (-(uint)(param_2 == '\0') & 0xfffff600)) | 0x2000;
  *(undefined4 *)(extraout_EDX + 0x48 + iVar4 * 4) = 0x1120;
  iVar1 = param_4;
  if (param_4 == 0) {
    iVar1 = (int)*(short *)(extraout_ECX + 4);
  }
  iVar2 = param_5;
  if (param_5 == 0) {
    iVar2 = (int)*(short *)(extraout_ECX + 6);
  }
  *(uint *)(extraout_EDX + (param_3 + 0x67) * 4) =
       iVar1 - 1U & 0x7ff | (iVar2 - 1U & 0x7ff) << 0xb | 0x80000000;
  *(undefined4 *)(extraout_EDX + 0x50 + iVar4 * 4) = 0x1130;
  *(uint *)(extraout_EDX + 0x54 + iVar4 * 4) =
       (int)((uint)(uVar3 < 3) << 0x1f) >> 0x1f & 0x400000U | local_18 | 0x53000;
  *(undefined4 *)(extraout_EDX + 0x58 + iVar4 * 4) = 0x1140;
  if (param_4 == 0) {
    param_4 = (int)*(short *)(extraout_ECX + 4);
  }
  if (param_5 == 0) {
    param_5 = (int)*(short *)(extraout_ECX + 6);
  }
  *(uint *)(extraout_EDX + (param_3 + 0x6b) * 4) =
       (param_5 - 1U & 0x800) << 5 |
       (param_4 - 1U & 0x800) << 4 | *(int *)(extraout_ECX + 0x10) - 1U & 0x3fff;
  *(undefined4 *)(extraout_EDX + 0x60 + iVar4 * 4) = 0x10f4;
  *(undefined4 *)(extraout_EDX + 100 + iVar4 * 4) = 0xffff;
  return param_3 + 0x6e;
}

/* _radeon3DFillSetup @ 0x2a8c (1752 bytes) */
int _radeon3DFillSetup(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint extraout_ECX;
  int iVar4;
  int unaff_EBX;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  undefined8 uVar9;
  
  uVar9 = ((int (*)())___i686_get_pc_thunk_bx)();
  iVar4 = (int)((ulonglong)uVar9 >> 0x20);
  iVar2 = (int)uVar9;
  iVar1 = *(int *)(param_1 + 0x70);
  *(undefined4 *)(iVar2 + iVar4 * 4) = 0x850;
  *(undefined4 *)(iVar2 + 4 + iVar4 * 4) = 0x100;
  *(undefined4 *)(iVar2 + 8 + iVar4 * 4) = 0x887;
  *(undefined4 *)(iVar2 + 0xc + iVar4 * 4) = 0x1c000;
  *(undefined4 *)(iVar2 + 0x10 + iVar4 * 4) = 0x82c;
  *(undefined4 *)(iVar2 + 0x14 + iVar4 * 4) = 0;
  *(undefined4 *)(iVar2 + 0x18 + iVar4 * 4) = 0x1002;
  *(undefined4 *)(iVar2 + 0x1c + iVar4 * 4) = 0;
  *(undefined4 *)(iVar2 + 0x20 + iVar4 * 4) = 0x824;
  *(undefined4 *)(iVar2 + 0x24 + iVar4 * 4) = 1;
  *(undefined4 *)(iVar2 + 0x28 + iVar4 * 4) = 0x825;
  *(undefined4 *)(iVar2 + 0x2c + iVar4 * 4) = 4;
  *(undefined4 *)(iVar2 + 0x30 + iVar4 * 4) = 0x82d;
  *(undefined4 *)(iVar2 + 0x34 + iVar4 * 4) = 3;
  *(undefined4 *)(iVar2 + 0x38 + iVar4 * 4) = 0x854;
  *(undefined4 *)(iVar2 + 0x3c + iVar4 * 4) = 0x26000001;
  *(undefined4 *)(iVar2 + 0x40 + iVar4 * 4) = 0x878;
  *(undefined4 *)(iVar2 + 0x44 + iVar4 * 4) = 0xfb24fb08;
  *(undefined1 **)(iVar2 + 0x48 + iVar4 * 4) = ((unsigned char *)0x000010a2);
  *(undefined4 *)(iVar2 + 0x4c + iVar4 * 4) = 0;
  *(undefined4 *)(iVar2 + 0x50 + iVar4 * 4) = 0x1381;
  *(undefined4 *)(iVar2 + 0x54 + iVar4 * 4) = 0;
  *(undefined **)(iVar2 + 0x58 + iVar4 * 4) = ((unsigned char *)0x0000109e);
  *(undefined4 *)(iVar2 + 0x5c + iVar4 * 4) = 5;
  *(undefined4 *)(iVar2 + 0x60 + iVar4 * 4) = 0x1383;
  *(undefined4 *)(iVar2 + 100 + iVar4 * 4) = 0xf;
  *(undefined4 *)(iVar2 + 0x68 + iVar4 * 4) = 0x1004;
  *(undefined4 *)(iVar2 + 0x6c + iVar4 * 4) = 0x66666666;
  *(undefined4 *)(iVar2 + 0x70 + iVar4 * 4) = 0x1005;
  *(undefined4 *)(iVar2 + 0x74 + iVar4 * 4) = 0x66666666;
  *(undefined1 **)(iVar2 + 0x78 + iVar4 * 4) = ((unsigned char *)0x000010ae);
  *(undefined4 *)(iVar2 + 0x7c + iVar4 * 4) = 0;
  *(undefined4 *)(iVar2 + 0x80 + iVar4 * 4) = 0x10ea;
  *(undefined4 *)(iVar2 + 0x84 + iVar4 * 4) = 0x2da49525;
  *(undefined4 *)(iVar2 + 0x88 + iVar4 * 4) = 0x10fa;
  *(undefined4 *)(iVar2 + 0x8c + iVar4 * 4) = 0xffffff;
  *(undefined4 *)(iVar2 + 0x90 + iVar4 * 4) = 0x10f4;
  *(undefined4 *)(iVar2 + 0x94 + iVar4 * 4) = 0xffff;
  *(undefined4 *)(iVar2 + 0x98 + iVar4 * 4) = 0x10f8;
  *(undefined4 *)(iVar2 + 0x9c + iVar4 * 4) = 0;
  *(undefined4 *)(iVar2 + 0xa0 + iVar4 * 4) = 0x10f9;
  *(uint *)(iVar2 + 0xa4 + iVar4 * 4) =
       *(uint *)(param_1 + 0x54) & 0x1fff | (*(uint *)(param_1 + 0x58) & 0x1fff) << 0xd;
  *(undefined4 *)(iVar2 + 0xa8 + iVar4 * 4) = 0x13c0;
  *(undefined4 *)(iVar2 + 0xac + iVar4 * 4) = 0;
  *(undefined4 *)(iVar2 + 0xb0 + iVar4 * 4) = 0x13c1;
  *(undefined4 *)(iVar2 + 0xb4 + iVar4 * 4) = 0;
  *(undefined **)(iVar2 + 0xb8 + iVar4 * 4) = ((unsigned char *)0x000010c0);
  *(undefined4 *)(iVar2 + 0xbc + iVar4 * 4) = 4;
  *(undefined **)(iVar2 + 0xc0 + iVar4 * 4) = ((unsigned char *)0x000010c1);
  *(undefined4 *)(iVar2 + 0xc4 + iVar4 * 4) = 0;
  *(undefined **)(iVar2 + 200 + iVar4 * 4) = ((unsigned char *)0x000010c8);
  *(undefined4 *)(iVar2 + 0xcc + iVar4 * 4) = 0x10;
  *(undefined4 *)(iVar2 + 0xd0 + iVar4 * 4) = 0x101d;
  *(undefined4 *)(iVar2 + 0xd4 + iVar4 * 4) = 0xc2040;
  *(undefined4 *)(iVar2 + 0xd8 + iVar4 * 4) = 0x1041;
  *(undefined4 *)(iVar2 + 0xdc + iVar4 * 4) = 0;
  *(undefined4 *)(iVar2 + 0xe0 + iVar4 * 4) = 0x1040;
  *(undefined4 *)(iVar2 + 0xe4 + iVar4 * 4) = 0;
  if (iVar1 == 3) {
    fVar7 = (float)((extraout_ECX & 0x8000) >> 0xf);
    fVar5 = *(float *)(unaff_EBX + 0xa4fa);
    fVar8 = (float)((extraout_ECX & 0x7c00) >> 10) / fVar5;
    fVar6 = (float)((extraout_ECX & 0x3e0) >> 5) / fVar5;
    uVar3 = extraout_ECX & 0x1f;
  }
  else {
    fVar5 = *(float *)(unaff_EBX + 0xa4fe);
    fVar7 = (float)(extraout_ECX >> 0x18) / fVar5;
    fVar8 = (float)((extraout_ECX & 0xff0000) >> 0x10) / fVar5;
    fVar6 = (float)((extraout_ECX & 0xff00) >> 8) / fVar5;
    uVar3 = extraout_ECX & 0xff;
  }
  *(undefined4 *)(iVar2 + (iVar4 + 0x3a) * 4) = 0x1094;
  *(undefined4 *)(iVar2 + 0xec + iVar4 * 4) = 0x10000;
  *(undefined4 *)(iVar2 + 0xf0 + iVar4 * 4) = 0x1095;
  *(float *)(iVar2 + 0xf4 + iVar4 * 4) = fVar8;
  *(undefined4 *)(iVar2 + 0xf8 + iVar4 * 4) = 0x1095;
  *(float *)(iVar2 + 0xfc + iVar4 * 4) = fVar6;
  *(undefined4 *)(iVar2 + 0x100 + iVar4 * 4) = 0x1095;
  *(float *)(iVar2 + 0x104 + iVar4 * 4) = (float)uVar3 / fVar5;
  *(undefined4 *)(iVar2 + 0x108 + iVar4 * 4) = 0x1095;
  *(float *)(iVar2 + 0x10c + iVar4 * 4) = fVar7;
  *(undefined4 *)(iVar2 + 0x110 + iVar4 * 4) = 0x1094;
  *(undefined4 *)(iVar2 + 0x114 + iVar4 * 4) = 0;
  *(undefined4 *)(iVar2 + 0x118 + iVar4 * 4) = 0x1095;
  *(undefined4 *)(iVar2 + 0x11c + iVar4 * 4) = 0x78105;
  *(undefined4 *)(iVar2 + 0x120 + iVar4 * 4) = 0x1095;
  *(undefined4 *)(iVar2 + 0x124 + iVar4 * 4) = 0x100;
  *(undefined4 *)(iVar2 + 0x128 + iVar4 * 4) = 0x1095;
  *(undefined4 *)(iVar2 + 300 + iVar4 * 4) = 0x100;
  *(undefined4 *)(iVar2 + 0x130 + iVar4 * 4) = 0x1095;
  *(undefined4 *)(iVar2 + 0x134 + iVar4 * 4) = 0xdb0220;
  *(undefined4 *)(iVar2 + 0x138 + iVar4 * 4) = 0x1095;
  *(undefined4 *)(iVar2 + 0x13c + iVar4 * 4) = 0xc0c000;
  *(undefined4 *)(iVar2 + 0x140 + iVar4 * 4) = 0x1095;
  *(undefined4 *)(iVar2 + 0x144 + iVar4 * 4) = 0x20490000;
  *(undefined4 *)(iVar2 + 0x148 + iVar4 * 4) = 0x1189;
  *(undefined4 *)(iVar2 + 0x14c + iVar4 * 4) = 0;
  *(undefined4 *)(iVar2 + 0x150 + iVar4 * 4) = 0x1181;
  *(undefined4 *)(iVar2 + 0x154 + iVar4 * 4) = 1;
  *(undefined4 *)(iVar2 + 0x158 + iVar4 * 4) = 0x118d;
  *(undefined4 *)(iVar2 + 0x15c + iVar4 * 4) = 0;
  *(undefined4 *)(iVar2 + 0x160 + iVar4 * 4) = 0x118e;
  *(undefined4 *)(iVar2 + 0x164 + iVar4 * 4) = 0;
  *(undefined4 *)(iVar2 + 0x168 + iVar4 * 4) = 0x118c;
  *(undefined4 *)(iVar2 + 0x16c + iVar4 * 4) = 0;
  *(undefined4 *)(iVar2 + 0x170 + iVar4 * 4) = 0x11a9;
  *(undefined4 *)(iVar2 + 0x174 + iVar4 * 4) = 0x1b01;
  *(undefined4 *)(iVar2 + 0x178 + iVar4 * 4) = 0x11aa;
  *(undefined4 *)(iVar2 + 0x17c + iVar4 * 4) = 0xf;
  *(undefined4 *)(iVar2 + 0x180 + iVar4 * 4) = 0x11ab;
  *(undefined4 *)(iVar2 + 0x184 + iVar4 * 4) = 0xf;
  *(undefined4 *)(iVar2 + 0x188 + iVar4 * 4) = 0x11ac;
  *(undefined4 *)(iVar2 + 0x18c + iVar4 * 4) = 0xf;
  *(undefined4 *)(iVar2 + 400 + iVar4 * 4) = 0x12f0;
  *(undefined4 *)(iVar2 + 0x194 + iVar4 * 4) = 0;
  *(undefined4 *)(iVar2 + 0x198 + iVar4 * 4) = 0x12f5;
  *(undefined4 *)(iVar2 + 0x19c + iVar4 * 4) = 0;
  return iVar4 + 0x68;
}

/* __Flush @ 0x3164 (318 bytes) */
int __Flush(param_1, param_2)
  int param_1;
  uint param_2;
{
  uint *puVar1;
  int iVar2;
  undefined4 *puVar3;
  int unaff_EBX;
  int local_14;
  int local_10;
  
  ((int (*)())___i686_get_pc_thunk_bx)();
  local_14 = *(int *)(param_1 + 0x18);
  puVar3 = *(undefined4 **)(param_1 + 0x80);
  if (puVar3 != (undefined4 *)(local_14 + 0x20)) {
    if ((param_2 & 0x10000) == 0) {
      iVar2 = *(int *)(param_1 + 0x8c);
    }
    else {
      iVar2 = 0;
      if (*(int *)(param_1 + 0x8c) != 0) {
        puVar1 = *(uint **)(param_1 + 0x7c);
        *puVar1 = *puVar1 | (int)puVar3 - (int)puVar1 >> 2;
        *(undefined4 **)(param_1 + 0x7c) = puVar3;
        *puVar3 = 0x2000000;
        puVar3 = puVar3 + 1;
        local_14 = *(int *)(param_1 + 0x18);
        iVar2 = *(int *)(param_1 + 0x8c);
      }
    }
    local_10 = 0;
    if (iVar2 == 0) {
      *puVar3 = 0x5c8;
      local_10 = 2;
      puVar3[1] = 0xc000;
      *(undefined4 *)(param_1 + 0x94) = 0;
    }
    puVar3[local_10] = 0x1000000;
    puVar1 = *(uint **)(param_1 + 0x7c);
    *puVar1 = *puVar1 | ((int)puVar3 - (int)puVar1 >> 2) + local_10;
    iVar2 = _IOConnectMapMemory(*(undefined4 *)(param_1 + 0xc),0,
                                **(undefined4 **)(unaff_EBX + 0xaf1f),&local_14,&local_10,1);
    if (iVar2 == 0) {
      *(undefined4 *)(local_14 + 0x1c) = 0;
      *(int *)(param_1 + 0x7c) = local_14 + 0x1c;
      *(int *)(param_1 + 0x18) = local_14;
      local_14 = local_14 + 0x20;
    }
    else {
      *(undefined4 *)(param_1 + 0x18) = 0;
      *(undefined4 *)(param_1 + 0x7c) = 0;
      local_14 = 0;
    }
    *(int *)(param_1 + 0x80) = local_14;
  }
  return 0;
}

/* __WaitComplete @ 0x32a2 (129 bytes) */
int __WaitComplete(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  if (((*(int *)(param_1 + 0x80) != 0) && (*(int *)(param_1 + 0x8c) != 0)) &&
     (*(int *)(param_1 + 0x94) != 0)) {
    *(undefined4 *)(param_1 + 0x94) = 0;
    param_2 = 1;
  }
  ((int (*)())__Flush)(param_1,0);
  _io_connect_method_scalarI_structureI(*(undefined4 *)(param_1 + 0xc),7,&param_2,1,0,0);
  return;
}

/* __FreeSurface @ 0x3323 (239 bytes) */
int __FreeSurface(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  int *piVar1;
  undefined4 uVar2;
  
  if (*(int *)(param_3 + 0x28) != 0) {
    if (((param_2 & 8) != 0) && (*(int *)(param_1 + 0x94) != 0)) {
      ((int (*)())__WaitComplete)(param_1,0x88);
    }
    *(undefined4 *)(*(int *)(param_3 + 0x28) + 8) = 0;
    if (param_3 == *(int *)(param_1 + 0x8c)) {
      uVar2 = ((int (*)())__SetDestination)(param_1,0,0);
    }
    else {
      uVar2 = 0;
    }
    piVar1 = *(int **)(param_3 + 0x28);
    if (*piVar1 != 0) {
      uVar2 = _io_connect_method_scalarI_structureI
                        (*(undefined4 *)(param_1 + 0xc),0xb,*piVar1,1,0,0);
      piVar1 = *(int **)(param_3 + 0x28);
    }
    piVar1[2] = 0;
    _free(*(void **)(param_3 + 0x28));
    *(undefined4 *)(param_3 + 0x28) = 0;
    return uVar2;
  }
  return 0xe00002d8;
}

/* _createTextureBuffer @ 0x3412 (573 bytes) */
int _createTextureBuffer(param_1)
  int param_1;
{
  int iVar1;
  void *pvVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int extraout_ECX;
  int unaff_EBX;
  undefined8 uVar6;
  uint local_30;
  uint local_2c;
  int local_28;
  
  uVar6 = ((int (*)())___i686_get_pc_thunk_bx)();
  iVar3 = (int)((ulonglong)uVar6 >> 0x20);
  iVar1 = (int)uVar6;
  if (*(int *)(unaff_EBX + 0xa22c) == 0) {
    local_2c = iVar3 + 0x20U & 0xffffffe0;
    local_30 = extraout_ECX + 0x20U & 0xffffffe0;
    goto LAB_000034a6;
  }
  if (param_1 == '\0') {
    if (*(int *)(unaff_EBX + 0xa2c4) == 0x42475241) goto LAB_00003553;
  }
  else if (*(int *)(unaff_EBX + 0xa2c4) == 0x10) {
LAB_00003553:
    local_2c = iVar3 + 0x20U & 0xffffffe0;
    if ((local_2c == *(uint *)(unaff_EBX + 0xa228)) &&
       (local_30 = extraout_ECX + 0x20U & 0xffffffe0, local_30 == *(uint *)(unaff_EBX + 0xa224))) {
      iVar5 = _io_connect_method_scalarI_structureI
                        (*(undefined4 *)(iVar1 + 0xc),0xc,**(undefined4 **)(unaff_EBX + 0xa2e8),1,0,
                         0);
      if (iVar5 == 0) {
        return 1;
      }
      if (*(int *)(unaff_EBX + 0xa22c) == 0) goto LAB_000034a6;
    }
  }
  local_2c = iVar3 + 0x20;
  local_30 = extraout_ECX + 0x20;
  *(int *)(iVar1 + 0x94) = *(int *)(iVar1 + 0x94) + -1;
  ((int (*)())__FreeSurface)(iVar1,8,unaff_EBX + 0xa2c0);
  _free(*(void **)(unaff_EBX + 0xa22c));
  *(undefined4 *)(unaff_EBX + 0xa22c) = 0;
  local_2c = local_2c & 0xffffffe0;
  local_30 = local_30 & 0xffffffe0;
LAB_000034a6:
  local_28 = unaff_EBX + 0xa2c0;
  *(uint *)(unaff_EBX + 0xa228) = local_2c;
  *(uint *)(unaff_EBX + 0xa224) = local_30;
  if (param_1 == '\0') {
    *(uint *)(unaff_EBX + 0xa220) = local_2c * local_30 * 4;
    *(undefined4 *)(unaff_EBX + 0xa2c4) = 0x42475241;
    *(uint *)(unaff_EBX + 0xa2d8) = local_2c * 4;
  }
  else {
    *(uint *)(unaff_EBX + 0xa220) = local_2c * local_30 * 2;
    *(undefined4 *)(unaff_EBX + 0xa2c4) = 0x10;
    *(uint *)(unaff_EBX + 0xa2d8) = local_2c * 2;
  }
  *(uint *)(unaff_EBX + 0xa2d0) = local_2c;
  *(uint *)(unaff_EBX + 0xa2d4) = local_30;
  pvVar2 = _malloc(*(size_t *)(unaff_EBX + 0xa220));
  *(void **)(unaff_EBX + 0xa22c) = pvVar2;
  uVar4 = 0;
  if (pvVar2 != (void *)0x0) {
    *(void **)(unaff_EBX + 0xa2c0) = pvVar2;
    iVar3 = ((int (*)())__AllocateSurface)(iVar1,8,local_28,0);
    if (iVar3 != 0) {
      _free(*(void **)(unaff_EBX + 0xa22c));
      *(undefined4 *)(unaff_EBX + 0xa22c) = 0;
      return 0;
    }
    *(int *)(iVar1 + 0x94) = *(int *)(iVar1 + 0x94) + 1;
    uVar4 = 1;
  }
  return uVar4;
}

/* _createOffscreenBuffer @ 0x364f (521 bytes) */
int _createOffscreenBuffer()
{
  int iVar1;
  void *pvVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  char extraout_CL;
  uint uVar6;
  uint uVar7;
  int unaff_EBX;
  undefined8 uVar8;
  int local_24;
  
  uVar8 = ((int (*)())___i686_get_pc_thunk_bx)();
  iVar3 = (int)((ulonglong)uVar8 >> 0x20);
  iVar1 = (int)uVar8;
  if (*(int *)(unaff_EBX + 0x9fff) == 0) goto LAB_000036c3;
  if (extraout_CL == '\0') {
    if (*(int *)(unaff_EBX + 0xa007) == 0x42475241) goto LAB_00003782;
  }
  else if (*(int *)(unaff_EBX + 0xa007) == 0x10) {
LAB_00003782:
    if ((((int)*(short *)(iVar3 + 4) + 0x20U & 0xffffffe0) == *(uint *)(unaff_EBX + 0x9ffb)) &&
       (((int)*(short *)(iVar3 + 6) + 0x20U & 0xffffffe0) == *(uint *)(unaff_EBX + 0x9ff7))) {
      iVar5 = _io_connect_method_scalarI_structureI
                        (*(undefined4 *)(iVar1 + 0xc),0xc,**(undefined4 **)(unaff_EBX + 0xa02b),1,0,
                         0);
      if (iVar5 == 0) {
        return 1;
      }
      if (*(int *)(unaff_EBX + 0x9fff) == 0) goto LAB_000036c3;
    }
  }
  *(int *)(iVar1 + 0x94) = *(int *)(iVar1 + 0x94) + -1;
  ((int (*)())__FreeSurface)(iVar1,0,unaff_EBX + 0xa003);
  _free(*(void **)(unaff_EBX + 0x9fff));
  *(undefined4 *)(unaff_EBX + 0x9fff) = 0;
LAB_000036c3:
  local_24 = unaff_EBX + 0xa003;
  uVar6 = (int)*(short *)(iVar3 + 4) + 0x20U & 0xffffffe0;
  *(uint *)(unaff_EBX + 0x9ffb) = uVar6;
  uVar7 = (int)*(short *)(iVar3 + 6) + 0x20U & 0xffffffe0;
  *(uint *)(unaff_EBX + 0x9ff7) = uVar7;
  if (extraout_CL == '\0') {
    *(uint *)(unaff_EBX + 0x9ff3) = uVar6 * uVar7 * 4;
    *(undefined4 *)(unaff_EBX + 0xa007) = 0x42475241;
    *(uint *)(unaff_EBX + 0xa01b) = uVar6 * 4;
  }
  else {
    *(uint *)(unaff_EBX + 0x9ff3) = uVar6 * uVar7 * 2;
    *(undefined4 *)(unaff_EBX + 0xa007) = 0x10;
    *(uint *)(unaff_EBX + 0xa01b) = uVar6 * 2;
  }
  *(uint *)(unaff_EBX + 0xa013) = uVar6;
  *(uint *)(unaff_EBX + 0xa017) = uVar7;
  pvVar2 = _malloc(*(size_t *)(unaff_EBX + 0x9ff3));
  *(void **)(unaff_EBX + 0x9fff) = pvVar2;
  uVar4 = 0;
  if (pvVar2 != (void *)0x0) {
    *(void **)(unaff_EBX + 0xa003) = pvVar2;
    iVar3 = ((int (*)())__AllocateSurface)(iVar1,0,local_24,0);
    if (iVar3 != 0) {
      _free(*(void **)(unaff_EBX + 0x9fff));
      *(undefined4 *)(unaff_EBX + 0x9fff) = 0;
      return 0;
    }
    *(int *)(iVar1 + 0x94) = *(int *)(iVar1 + 0x94) + 1;
    uVar4 = 1;
  }
  return uVar4;
}

/* __Stop @ 0x3858 (224 bytes) */
int __Stop(param_1)
  int param_1;
{
  int unaff_EBX;
  
  ((int (*)())___i686_get_pc_thunk_bx)();
  if (*(int *)(unaff_EBX + 0x9df7) != 0) {
    *(int *)(param_1 + 0x94) = *(int *)(param_1 + 0x94) + -1;
    ((int (*)())__FreeSurface)(param_1,0,unaff_EBX + 0x9dfb);
    _free(*(void **)(unaff_EBX + 0x9df7));
    *(undefined4 *)(unaff_EBX + 0x9df7) = 0;
  }
  if (*(int *)(unaff_EBX + 0x9de7) != 0) {
    *(int *)(param_1 + 0x94) = *(int *)(param_1 + 0x94) + -1;
    ((int (*)())__FreeSurface)(param_1,8,unaff_EBX + 0x9e7b);
    _free(*(void **)(unaff_EBX + 0x9de7));
    *(undefined4 *)(unaff_EBX + 0x9de7) = 0;
  }
  ((int (*)())__Flush)(param_1,0);
  if (*(int *)(param_1 + 0x10) != 0) {
    if (*(int *)(param_1 + 0xc) != 0) {
      _IOServiceClose(*(int *)(param_1 + 0xc));
    }
    _IOObjectRelease(*(undefined4 *)(param_1 + 0x10));
    *(undefined4 *)(param_1 + 0x10) = 0;
    *(undefined4 *)(param_1 + 0xc) = 0;
  }
  return 0;
}

/* _radeonCopy @ 0x3938 (4763 bytes) */
int _radeonCopy(param_1)
  int param_1;
{
  float *pfVar1;
  int iVar2;
  int iVar3;
  uint *puVar4;
  double dVar5;
  bool bVar6;
  char cVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  dword *pdVar12;
  int iVar13;
  uint uVar14;
  dword *pdVar15;
  int unaff_EBX;
  uint uVar16;
  uint uVar17;
  int iVar18;
  uint uVar19;
  uint uVar20;
  dword *pdVar21;
  float fVar22;
  float fVar23;
  float fVar24;
  float fVar25;
  int in_stack_00000014;
  int local_230;
  int local_17c;
  uint local_178;
  uint local_174;
  uint local_170;
  dword *local_110;
  dword *local_10c;
  dword *local_108;
  dword *local_104;
  int local_100;
  int local_fc;
  int local_f8;
  int local_f4;
  int local_f0;
  int local_ec;
  int local_e8;
  int local_e4;
  int local_e0;
  int local_dc;
  int local_d8;
  int local_d4;
  int local_d0;
  int local_cc;
  int local_c8;
  int local_c4;
  int local_c0;
  int local_bc;
  int local_b8;
  int local_b4;
  dword *local_b0;
  dword *local_ac;
  dword *local_a8;
  dword *local_a4;
  int local_a0;
  int local_9c;
  int local_98;
  int local_94;
  int local_90;
  int local_8c;
  int local_88;
  int local_84;
  int local_80;
  int local_7c;
  int local_78;
  int local_74;
  int local_70;
  int local_6c;
  int local_68;
  int local_64;
  int local_60;
  int local_5c;
  int local_58;
  int local_54;
  int *local_50;
  uint local_4c;
  float local_2c;
  float local_28;
  float local_24;
  float local_20 [4];
  
  ((int (*)())___i686_get_pc_thunk_bx)();
  iVar2 = *(int *)(in_stack_00000014 + 0x58);
  uVar16 = *(int *)(*(int *)(param_1 + 0x18) + 0x10) - 7;
  local_50 = (int *)(in_stack_00000014 + 0x5c);
  pdVar21 = *(dword **)(param_1 + 0x80);
  if (pdVar21 != (dword *)0x0) {
    local_178 = uVar16 - ((int)pdVar21 - (*(int *)(param_1 + 0x18) + 0x20) >> 2);
    if ((0x1000 < *(short *)(param_1 + 0x50)) || (0x1000 < *(short *)(param_1 + 0x52))) {
      return 0xe00002c7;
    }
    cVar7 = ((int (*)())_createOffscreenBuffer)();
    if (cVar7 != '\0') {
      iVar3 = *(int *)(unaff_EBX + 0x9d3f);
      uVar20 = *(uint *)(param_1 + 0x70);
      if (uVar20 == 3) {
        local_174 = 0xb;
      }
      else {
        local_174 = 0xc;
        if (uVar20 != 6) {
          local_174 = uVar20;
        }
      }
      uVar20 = *(uint *)(iVar3 + 0x30);
      if (uVar20 == 3) {
        local_170 = 0xb;
      }
      else {
        local_170 = 0xc;
        if (uVar20 != 6) {
          local_170 = uVar20;
        }
      }
      if (iVar2 != 0) {
        bVar6 = true;
        local_17c = 0;
        do {
          iVar8 = *(int *)(param_1 + 0x60) + *local_50;
          fVar22 = (float)iVar8;
          iVar9 = *(int *)(param_1 + 100) + local_50[1];
          fVar24 = (float)iVar9;
          fVar23 = fVar22 + (float)local_50[4];
          fVar25 = fVar24 + (float)local_50[5];
          if (fVar22 <= 0.0) {
            fVar22 = 0.0;
          }
          pfVar1 = (float *)(unaff_EBX + 0x9667);
          uVar20 = (int)(fVar22 - (float)(-(uint)(*pfVar1 <= fVar22) & (uint)*pfVar1)) +
                   (uint)(*pfVar1 <= fVar22) * -0x80000000 |
                   -(uint)(*(float *)(unaff_EBX + 0x9677) <= fVar22);
          if (fVar24 <= 0.0) {
            fVar24 = 0.0;
          }
          uVar14 = (int)(fVar24 - (float)(-(uint)(*pfVar1 <= fVar24) & (uint)*pfVar1)) |
                   -(uint)(*(float *)(unaff_EBX + 0x9677) <= fVar24);
          fVar22 = fVar23;
          if (fVar23 <= 0.0) {
            fVar22 = 0.0;
          }
          uVar17 = (int)(fVar22 - (float)(-(uint)(*pfVar1 <= fVar22) & (uint)*pfVar1)) +
                   (uint)(*pfVar1 <= fVar22) * -0x80000000 |
                   -(uint)(*(float *)(unaff_EBX + 0x9677) <= fVar22);
          fVar22 = fVar25;
          if (fVar25 <= 0.0) {
            fVar22 = 0.0;
          }
          uVar19 = (int)(fVar22 - (float)(-(uint)(*pfVar1 <= fVar22) & (uint)*pfVar1)) |
                   -(uint)(*(float *)(unaff_EBX + 0x9677) <= fVar22);
          if (bVar6) {
            if (local_178 < 0x8a) {
              local_2c = 0.0;
              local_20[0] = *(float *)(param_1 + 0x18);
              if (*(int *)(param_1 + 0x8c) == 0) {
                *pdVar21 = 0x5c8;
                local_2c = 2.8026e-45;
                pdVar21[1] = 0xc000;
                *(undefined4 *)(param_1 + 0x94) = 0;
              }
              pdVar21[(int)local_2c] = 0x1000000;
              puVar4 = *(uint **)(param_1 + 0x7c);
              *puVar4 = *puVar4 | ((int)pdVar21 - (int)puVar4 >> 2) + (int)local_2c;
              iVar18 = _IOConnectMapMemory(*(undefined4 *)(param_1 + 0xc),0,
                                           **(undefined4 **)(unaff_EBX + 0xa747),local_20,&local_2c,
                                           1);
              if (iVar18 == 0) {
                *(undefined4 *)((int)local_20[0] + 0x1c) = 0;
                fVar22 = local_20[0];
                goto LAB_00004868;
              }
LAB_0000474d:
              *(undefined4 *)(param_1 + 0x18) = 0;
              *(undefined4 *)(param_1 + 0x7c) = 0;
              bVar6 = true;
              pdVar21 = (dword *)0x0;
              local_110 = &__mh_bundle_header.cputype;
              pdVar12 = &__mh_bundle_header.cpusubtype;
              local_10c = &__mh_bundle_header.filetype;
              local_108 = &__mh_bundle_header.ncmds;
              local_104 = &__mh_bundle_header.sizeofcmds;
              pdVar15 = &__mh_bundle_header.flags;
              local_178 = uVar16;
            }
            else {
              local_110 = pdVar21 + 1;
              pdVar12 = pdVar21 + 2;
              local_10c = pdVar21 + 3;
              local_108 = pdVar21 + 4;
              local_104 = pdVar21 + 5;
              pdVar15 = pdVar21 + 6;
              bVar6 = true;
            }
          }
          else if (local_178 < 0x22) {
            local_20[0] = 0.0;
            local_2c = *(float *)(param_1 + 0x18);
            if (*(int *)(param_1 + 0x8c) == 0) {
              *pdVar21 = 0x5c8;
              local_20[0] = 2.8026e-45;
              pdVar21[1] = 0xc000;
              *(undefined4 *)(param_1 + 0x94) = 0;
            }
            pdVar21[(int)local_20[0]] = 0x1000000;
            puVar4 = *(uint **)(param_1 + 0x7c);
            *puVar4 = *puVar4 | ((int)pdVar21 - (int)puVar4 >> 2) + (int)local_20[0];
            iVar18 = _IOConnectMapMemory(*(undefined4 *)(param_1 + 0xc),0,
                                         **(undefined4 **)(unaff_EBX + 0xa747),&local_2c,local_20,1)
            ;
            if (iVar18 != 0) goto LAB_0000474d;
            *(undefined4 *)((int)local_2c + 0x1c) = 0;
            fVar22 = local_2c;
LAB_00004868:
            *(int *)(param_1 + 0x7c) = (int)fVar22 + 0x1c;
            *(float *)(param_1 + 0x18) = fVar22;
            pdVar21 = (dword *)((int)fVar22 + 0x20);
            local_110 = (dword *)((int)fVar22 + 0x24);
            pdVar12 = (dword *)((int)fVar22 + 0x28);
            local_10c = (dword *)((int)fVar22 + 0x2c);
            local_108 = (dword *)((int)fVar22 + 0x30);
            local_104 = (dword *)((int)fVar22 + 0x34);
            pdVar15 = (dword *)((int)fVar22 + 0x38);
            bVar6 = true;
            local_178 = uVar16;
          }
          else {
            local_110 = pdVar21 + 1;
            pdVar12 = pdVar21 + 2;
            local_10c = pdVar21 + 3;
            local_108 = pdVar21 + 4;
            local_104 = pdVar21 + 5;
            pdVar15 = pdVar21 + 6;
            bVar6 = false;
          }
          puVar4 = *(uint **)(param_1 + 0x7c);
          *puVar4 = *puVar4 | (int)pdVar21 - (int)puVar4 >> 2;
          *(dword **)(param_1 + 0x7c) = pdVar21;
          *pdVar21 = 0xe000000;
          *local_110 = 0;
          puVar4 = *(uint **)(param_1 + 0x7c);
          *puVar4 = *puVar4 | (int)pdVar12 - (int)puVar4 >> 2;
          *(dword **)(param_1 + 0x7c) = pdVar12;
          *pdVar12 = 0x10000000;
          *local_10c = *(dword *)**(undefined4 **)(unaff_EBX + 0x9d3f);
          *local_108 = *(dword *)(*(int *)(unaff_EBX + 0x9d3f) + 0x1c);
          *local_104 = 6;
          if (bVar6) {
            local_b4 = ((int (*)())_radeon3DCopySetup)(local_174,0,0,0,0);
            local_230 = local_b4 * 4;
            local_100 = local_b4 + 1;
            local_fc = local_b4 + 2;
            local_f8 = local_b4 + 3;
            local_f4 = local_b4 + 4;
            iVar18 = local_b4 + 5;
            local_f0 = local_b4 + 6;
            local_ec = local_b4 + 7;
            iVar13 = local_b4 + 8;
            local_e8 = local_b4 + 9;
            local_e4 = local_b4 + 10;
            local_e0 = local_b4 + 0xb;
            local_dc = local_b4 + 0xc;
            local_d8 = local_b4 + 0xd;
            local_d4 = local_b4 + 0xe;
            local_d0 = local_b4 + 0xf;
            local_cc = local_b4 + 0x10;
            local_c8 = local_b4 + 0x11;
            local_c4 = local_b4 + 0x12;
            local_c0 = local_b4 + 0x13;
            local_bc = local_b4 + 0x14;
            local_b8 = local_b4 + 0x15;
            local_b4 = local_b4 + 0x16;
          }
          else {
            *pdVar15 = 0x1120;
            pdVar15[1] = (int)*(short *)(param_1 + 0x50) - 1U & 0x7ff |
                         ((int)*(short *)(param_1 + 0x52) - 1U & 0x7ff) << 0xb | 0x80000000;
            pdVar15[2] = 0x1130;
            pdVar15[3] = local_174 & 0x1f | 0x53000;
            pdVar15[4] = 0x1140;
            pdVar15[5] = *(int *)(param_1 + 0x5c) - 1U & 0x3fff |
                         ((int)*(short *)(param_1 + 0x50) - 1U & 0x800) << 4 |
                         ((int)*(short *)(param_1 + 0x52) - 1U & 0x800) << 5;
            local_230 = 0x18;
            local_100 = 7;
            local_fc = 8;
            local_f8 = 9;
            local_f4 = 10;
            iVar18 = 0xb;
            local_f0 = 0xc;
            local_ec = 0xd;
            iVar13 = 0xe;
            local_e8 = 0xf;
            local_e4 = 0x10;
            local_e0 = 0x11;
            local_dc = 0x12;
            local_d8 = 0x13;
            local_d4 = 0x14;
            local_d0 = 0x15;
            local_cc = 0x16;
            local_c8 = 0x17;
            local_c4 = 0x18;
            local_c0 = 0x19;
            local_bc = 0x1a;
            local_b8 = 0x1b;
            local_b4 = 0x1c;
          }
          *(undefined4 *)(local_230 + (int)pdVar15) = 0x10f8;
          pdVar15[local_100] = uVar20 & 0x1fff | (uVar14 & 0x1fff) << 0xd;
          pdVar15[local_fc] = 0x10f9;
          pdVar15[local_f8] = uVar17 & 0x1fff | (uVar19 & 0x1fff) << 0xd;
          pdVar15[local_f4] = 0xc00c3500;
          pdVar15[iVar18] = 0x4003d;
          dVar5 = *(double *)(unaff_EBX + 0x96a7) / (double)(int)*(short *)(param_1 + 0x50);
          local_28 = (float)((double)iVar8 * dVar5);
          local_24 = (float)((double)fVar23 * dVar5);
          dVar5 = *(double *)(unaff_EBX + 0x96a7) / (double)(int)*(short *)(param_1 + 0x52);
          local_20[0] = (float)((double)iVar9 * dVar5);
          local_2c = (float)((double)fVar25 * dVar5);
          uVar19 = uVar19 << 0x10;
          pdVar15[local_f0] = uVar20 | uVar19;
          pdVar15[local_ec] = (dword)local_28;
          pdVar15[iVar13] = (dword)local_2c;
          uVar14 = uVar14 << 0x10;
          pdVar15[local_e8] = uVar20 | uVar14;
          pdVar15[local_e4] = (dword)local_28;
          pdVar15[local_e0] = (dword)local_20[0];
          pdVar15[local_dc] = uVar14 | uVar17;
          pdVar15[local_d8] = (dword)local_24;
          pdVar15[local_d4] = (dword)local_20[0];
          pdVar15[local_d0] = uVar19 | uVar17;
          pdVar15[local_cc] = (dword)local_24;
          pdVar15[local_c8] = (dword)local_2c;
          pdVar15[local_c4] = 0x1393;
          pdVar15[local_c0] = 10;
          pdVar15[local_bc] = 0x5c8;
          pdVar15[local_b8] = 0x20000;
          local_4c = (local_178 - 6) - local_b4;
          pdVar15 = pdVar15 + local_b4;
          uVar20 = *(int *)(param_1 + 0x60) + local_50[2];
          iVar13 = *(int *)(param_1 + 100) + local_50[3];
          uVar14 = uVar20 + local_50[4];
          iVar18 = local_50[5];
          if (local_4c < 0x22) {
            local_28 = 0.0;
            local_24 = *(float *)(param_1 + 0x18);
            if (*(int *)(param_1 + 0x8c) == 0) {
              *pdVar15 = 0x5c8;
              local_28 = 2.8026e-45;
              pdVar15[1] = 0xc000;
              *(undefined4 *)(param_1 + 0x94) = 0;
            }
            pdVar15[(int)local_28] = 0x1000000;
            puVar4 = *(uint **)(param_1 + 0x7c);
            *puVar4 = *puVar4 | ((int)pdVar15 - (int)puVar4 >> 2) + (int)local_28;
            iVar10 = _IOConnectMapMemory(*(undefined4 *)(param_1 + 0xc),0,
                                         **(undefined4 **)(unaff_EBX + 0xa747),&local_24,&local_28,1
                                        );
            local_4c = uVar16;
            if (iVar10 == 0) {
              *(undefined4 *)((int)local_24 + 0x1c) = 0;
              *(int *)(param_1 + 0x7c) = (int)local_24 + 0x1c;
              *(float *)(param_1 + 0x18) = local_24;
              pdVar15 = (dword *)((int)local_24 + 0x20);
              local_b0 = (dword *)((int)local_24 + 0x24);
              local_ac = (dword *)((int)local_24 + 0x28);
              local_a8 = (dword *)((int)local_24 + 0x2c);
              pdVar12 = (dword *)((int)local_24 + 0x30);
              local_a4 = (dword *)((int)local_24 + 0x34);
              pdVar21 = (dword *)((int)local_24 + 0x38);
              bVar6 = true;
            }
            else {
              *(undefined4 *)(param_1 + 0x18) = 0;
              *(undefined4 *)(param_1 + 0x7c) = 0;
              bVar6 = true;
              pdVar15 = (dword *)0x0;
              local_b0 = &__mh_bundle_header.cputype;
              local_ac = &__mh_bundle_header.cpusubtype;
              local_a8 = &__mh_bundle_header.filetype;
              pdVar12 = &__mh_bundle_header.ncmds;
              local_a4 = &__mh_bundle_header.sizeofcmds;
              pdVar21 = &__mh_bundle_header.flags;
            }
          }
          else {
            local_b0 = pdVar15 + 1;
            local_ac = pdVar15 + 2;
            local_a8 = pdVar15 + 3;
            pdVar12 = pdVar15 + 4;
            local_a4 = pdVar15 + 5;
            pdVar21 = pdVar15 + 6;
            bVar6 = false;
          }
          puVar4 = *(uint **)(param_1 + 0x7c);
          *puVar4 = *puVar4 | (int)pdVar15 - (int)puVar4 >> 2;
          *(dword **)(param_1 + 0x7c) = pdVar15;
          *pdVar15 = 0x12000000;
          *local_b0 = 0;
          *local_ac = 0;
          *local_a8 = 0;
          puVar4 = *(uint **)(param_1 + 0x7c);
          *puVar4 = *puVar4 | (int)pdVar12 - (int)puVar4 >> 2;
          *(dword **)(param_1 + 0x7c) = pdVar12;
          *pdVar12 = 0x4000000;
          *local_a4 = *(dword *)**(undefined4 **)(unaff_EBX + 0x9d3f);
          if (bVar6) {
            local_54 = ((int (*)())_radeon3DCopySetup)(local_170,0,0,0,0);
            local_230 = local_54 * 4;
            local_a0 = local_54 + 1;
            local_9c = local_54 + 2;
            local_98 = local_54 + 3;
            local_94 = local_54 + 4;
            iVar10 = local_54 + 5;
            local_90 = local_54 + 6;
            local_8c = local_54 + 7;
            iVar11 = local_54 + 8;
            local_88 = local_54 + 9;
            local_84 = local_54 + 10;
            local_80 = local_54 + 0xb;
            local_7c = local_54 + 0xc;
            local_78 = local_54 + 0xd;
            local_74 = local_54 + 0xe;
            local_70 = local_54 + 0xf;
            local_6c = local_54 + 0x10;
            local_68 = local_54 + 0x11;
            local_64 = local_54 + 0x12;
            local_60 = local_54 + 0x13;
            local_5c = local_54 + 0x14;
            local_58 = local_54 + 0x15;
            local_54 = local_54 + 0x16;
          }
          else {
            *pdVar21 = 0x1120;
            pdVar21[1] = (int)*(short *)(iVar3 + 0x10) - 1U & 0x7ff |
                         ((int)*(short *)(iVar3 + 0x12) - 1U & 0x7ff) << 0xb | 0x80000000;
            pdVar21[2] = 0x1130;
            pdVar21[3] = local_170 & 0x1f | 0x53000;
            pdVar21[4] = 0x1140;
            pdVar21[5] = *(int *)(iVar3 + 0x1c) - 1U & 0x3fff |
                         ((int)*(short *)(iVar3 + 0x10) - 1U & 0x800) << 4 |
                         ((int)*(short *)(iVar3 + 0x12) - 1U & 0x800) << 5;
            local_230 = 0x18;
            local_a0 = 7;
            local_9c = 8;
            local_98 = 9;
            local_94 = 10;
            iVar10 = 0xb;
            local_90 = 0xc;
            local_8c = 0xd;
            iVar11 = 0xe;
            local_88 = 0xf;
            local_84 = 0x10;
            local_80 = 0x11;
            local_7c = 0x12;
            local_78 = 0x13;
            local_74 = 0x14;
            local_70 = 0x15;
            local_6c = 0x16;
            local_68 = 0x17;
            local_64 = 0x18;
            local_60 = 0x19;
            local_5c = 0x1a;
            local_58 = 0x1b;
            local_54 = 0x1c;
          }
          *(undefined4 *)(local_230 + (int)pdVar21) = 0x10f8;
          pdVar21[local_a0] = uVar20 & 0x1fff | iVar13 * 0x2000 & 0x3ffe000U;
          pdVar21[local_9c] = 0x10f9;
          pdVar21[local_98] = uVar14 & 0x1fff | (iVar13 + iVar18) * 0x2000 & 0x3ffe000U;
          pdVar21[local_94] = 0xc00c3500;
          pdVar21[iVar10] = 0x4003d;
          local_20[0] = (float)((double)iVar8 *
                               (*(double *)(unaff_EBX + 0x96a7) /
                               (double)(int)*(short *)(iVar3 + 0x10)));
          local_2c = (float)((double)fVar23 *
                            (*(double *)(unaff_EBX + 0x96a7) / (double)(int)*(short *)(iVar3 + 0x10)
                            ));
          local_28 = (float)((double)iVar9 *
                            (*(double *)(unaff_EBX + 0x96a7) / (double)(int)*(short *)(iVar3 + 0x12)
                            ));
          local_24 = (float)((double)fVar25 *
                            (*(double *)(unaff_EBX + 0x96a7) / (double)(int)*(short *)(iVar3 + 0x12)
                            ));
          uVar17 = (iVar13 + iVar18) * 0x10000;
          pdVar21[local_90] = uVar20 | uVar17;
          pdVar21[local_8c] = (dword)local_20[0];
          pdVar21[iVar11] = (dword)local_24;
          pdVar21[local_88] = uVar20 | iVar13 * 0x10000;
          pdVar21[local_84] = (dword)local_20[0];
          pdVar21[local_80] = (dword)local_28;
          pdVar21[local_7c] = iVar13 * 0x10000 | uVar14;
          pdVar21[local_78] = (dword)local_2c;
          pdVar21[local_74] = (dword)local_28;
          pdVar21[local_70] = uVar14 | uVar17;
          pdVar21[local_6c] = (dword)local_2c;
          pdVar21[local_68] = (dword)local_24;
          pdVar21[local_64] = 0x1393;
          pdVar21[local_60] = 10;
          pdVar21[local_5c] = 0x5c8;
          pdVar21[local_58] = 0x20000;
          local_178 = (local_4c - 6) - local_54;
          pdVar21 = pdVar21 + local_54;
          local_17c = local_17c + 1;
          local_50 = local_50 + 6;
          bVar6 = false;
        } while (iVar2 != local_17c);
      }
      *(dword **)(param_1 + 0x80) = pdVar21;
      return 0;
    }
  }
  return 0xe00002be;
}

/* _radeonCopyRegion @ 0x4bd3 (14823 bytes) */
int _radeonCopyRegion(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  uint param_4;
  int param_5;
  dword param_6;
{
  float *pfVar1;
  short sVar2;
  int *piVar3;
  uint *puVar4;
  undefined4 *puVar5;
  bool bVar6;
  char cVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  int iVar14;
  int iVar15;
  uint uVar16;
  int unaff_EBX;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  dword *pdVar20;
  dword *pdVar21;
  float fVar22;
  float fVar23;
  float fVar24;
  float fVar25;
  float fVar26;
  float fVar27;
  float fVar28;
  float fVar29;
  dword *local_4c8;
  int local_4c4;
  dword *local_4c0;
  int local_4a4;
  int local_3d4;
  int *local_3d0;
  undefined4 *local_3cc;
  int local_3bc;
  uint local_3b8;
  int local_3b4;
  int local_3b0;
  int local_3ac;
  int local_3a8;
  uint local_3a4;
  uint local_3a0;
  dword local_39c;
  dword local_394;
  uint local_330;
  uint local_32c;
  dword local_2f0;
  char local_2e9;
  int local_2e8;
  int local_2e4;
  int local_2e0;
  int local_2dc;
  int local_2d8;
  int local_2d4;
  int local_2d0;
  int local_2cc;
  int local_2c8;
  int local_2c4;
  int local_2c0;
  int local_2bc;
  int local_2b8;
  int local_2b4;
  int local_2b0;
  int local_2ac;
  int local_2a8;
  int local_2a4;
  int local_2a0;
  int local_29c;
  dword *local_298;
  dword *local_294;
  dword *local_290;
  int local_28c;
  int local_288;
  int local_284;
  int local_280;
  int local_27c;
  int local_278;
  int local_274;
  int local_270;
  int local_26c;
  int local_268;
  int local_264;
  int local_260;
  int local_25c;
  int local_258;
  int local_254;
  int local_250;
  int local_24c;
  int local_248;
  int local_244;
  int local_240;
  dword *local_23c;
  dword *local_238;
  dword *local_234;
  dword *local_230;
  int local_22c;
  int local_228;
  int local_224;
  int local_220;
  int local_21c;
  int local_218;
  int local_214;
  int local_210;
  int local_20c;
  int local_208;
  int local_204;
  int local_200;
  int local_1fc;
  int local_1f8;
  int local_1f4;
  int local_1f0;
  int local_1ec;
  int local_1e8;
  int local_1e4;
  int local_1e0;
  dword *local_1dc;
  dword *local_1d8;
  dword *local_1d4;
  dword *local_1d0;
  int local_1cc;
  int local_1c8;
  int local_1c4;
  int local_1c0;
  int local_1bc;
  int local_1b8;
  int local_1b4;
  int local_1b0;
  int local_1ac;
  int local_1a8;
  int local_1a4;
  int local_1a0;
  int local_19c;
  int local_198;
  int local_194;
  int local_190;
  int local_18c;
  int local_188;
  int local_184;
  int local_180;
  int local_17c;
  int local_178;
  int local_174;
  int local_170;
  int local_16c;
  int local_168;
  int local_164;
  int local_160;
  int local_15c;
  int local_158;
  int local_154;
  int local_150;
  int local_14c;
  int local_148;
  int local_144;
  int local_140;
  int local_13c;
  int local_138;
  int local_134;
  int local_130;
  dword *local_12c;
  dword *local_128;
  dword *local_124;
  dword *local_120;
  dword *local_11c;
  dword *local_118;
  dword *local_114;
  dword *local_110;
  dword *local_10c;
  dword *local_108;
  int *local_104;
  int *local_100;
  int *local_fc;
  int *local_f8;
  uint local_f4;
  dword *local_e8;
  dword *local_e4;
  dword *local_e0;
  int local_7c;
  int local_78;
  int local_74;
  undefined4 local_68;
  short local_64;
  dword local_38 [2];
  float local_30;
  float local_2c;
  float local_28;
  float local_24 [5];
  
  ((int (*)())___i686_get_pc_thunk_bx)();
  piVar3 = *(int **)(param_5 + 0x60);
  local_3d4 = *piVar3;
  iVar8 = *(int *)(param_1 + 0x18);
  iVar14 = *(int *)(iVar8 + 0x10);
  uVar19 = iVar14 - 7;
  param_4 = param_4 & 0x7ffff000;
  pdVar20 = *(dword **)(param_1 + 0x80);
  if (pdVar20 == (dword *)0x0) {
LAB_00004c22:
    iVar8 = -0x1ffffd42;
  }
  else {
    if (param_4 == 0x1000) {
      local_3cc = (undefined4 *)(param_1 + 0x1c);
      local_39c = *(dword *)(param_1 + 0x84);
      local_3ac = *(int *)(param_1 + 0x30);
      local_3a8 = *(int *)(param_1 + 0x34);
      iVar9 = 0x9000000;
LAB_00004c72:
      local_64 = *(short *)(local_3cc + 1);
      if ((0x1000 < local_64) || (0x1000 < *(short *)((int)local_3cc + 6))) {
        return -0x1ffffd39;
      }
      local_2f0 = iVar9 + 0x1000000;
    }
    else {
      if (param_4 < 0x1001) {
        if (param_4 != 0) {
          return -0x1ffffd44;
        }
        local_3cc = (undefined4 *)(param_1 + 0x4c);
        local_3ac = 0;
        local_3a8 = 0;
        local_39c = 0;
        iVar9 = 0xd000000;
        goto LAB_00004c72;
      }
      if (param_4 == 0x3000) {
        puVar5 = *(undefined4 **)(param_6 + 0x28);
        local_3cc = puVar5 + 3;
        local_39c = *(dword *)*puVar5;
        *(int *)(param_1 + 0x94) = *(int *)(param_1 + 0x94) + 1;
        local_3ac = 0;
        local_3a8 = 0;
        local_2f0 = 0x8000000;
        local_64 = *(short *)(puVar5 + 4);
      }
      else {
        if (param_4 != 0x7000) {
          return -0x1ffffd44;
        }
        local_39c = param_6;
        local_38[0] = param_6;
        local_38[1] = 0x800;
        local_24[1] = 6.72623e-44;
        local_3cc = &local_68;
        iVar9 = _io_connect_method_scalarI_structureO
                          (*(undefined4 *)(param_1 + 0xc),2,local_38,2,local_3cc,local_24 + 1);
        if (iVar9 != 0) {
          return iVar9;
        }
        local_3ac = 0;
        local_3a8 = 0;
        local_2f0 = 0xc000000;
      }
    }
    if (local_3d4 == 0) {
      local_3d0 = piVar3 + 1;
      local_3d4 = 1;
    }
    else {
      local_3d0 = piVar3 + 3;
    }
    local_3b4 = *(int *)(param_5 + 0x58) - (int)(short)piVar3[1];
    local_3b0 = *(int *)(param_5 + 0x5c) - (int)*(short *)((int)piVar3 + 6);
    local_f4 = uVar19 - ((int)pdVar20 - (iVar8 + 0x20) >> 2);
    uVar17 = local_3cc[9];
    iVar8 = local_3cc[4];
    iVar9 = local_3cc[7];
    if (local_3cc[2] == (int)local_64) {
      uVar16 = (uint)*(short *)((int)local_3cc + 6);
      if (local_3cc[3] != uVar16) goto LAB_00004dfd;
      local_2e9 = '\0';
    }
    else {
      uVar16 = (uint)*(short *)((int)local_3cc + 6);
LAB_00004dfd:
      local_2e9 = '\x01';
    }
    if (uVar17 == 3) {
      local_3a4 = 0xb;
    }
    else {
      local_3a4 = 0xc;
      if (uVar17 != 6) {
        local_3a4 = uVar17;
      }
    }
    fVar22 = (float)(int)local_64 / (float)(uint)local_3cc[2];
    fVar23 = (float)(int)uVar16 / (float)(uint)local_3cc[3];
    for (; ((uint)pdVar20 & 0x1f) != 0; pdVar20 = pdVar20 + 1) {
      while (local_f4 == 0) {
        local_28 = 0.0;
        local_24[0] = *(float *)(param_1 + 0x18);
        if (*(int *)(param_1 + 0x8c) == 0) {
          *pdVar20 = 0x5c8;
          local_28 = 2.8026e-45;
          pdVar20[1] = 0xc000;
          *(undefined4 *)(param_1 + 0x94) = 0;
        }
        pdVar20[(int)local_28] = 0x1000000;
        puVar4 = *(uint **)(param_1 + 0x7c);
        *puVar4 = *puVar4 | ((int)pdVar20 - (int)puVar4 >> 2) + (int)local_28;
        iVar10 = _IOConnectMapMemory(*(undefined4 *)(param_1 + 0xc),0,
                                     **(undefined4 **)(unaff_EBX + 0x94ac),local_24,&local_28,1);
        if (iVar10 == 0) {
          *(undefined4 *)((int)local_24[0] + 0x1c) = 0;
          *(int *)(param_1 + 0x7c) = (int)local_24[0] + 0x1c;
          *(float *)(param_1 + 0x18) = local_24[0];
          pdVar20 = (dword *)((int)local_24[0] + 0x20);
        }
        else {
          *(undefined4 *)(param_1 + 0x18) = 0;
          *(undefined4 *)(param_1 + 0x7c) = 0;
          pdVar20 = (dword *)0x0;
        }
        local_f4 = uVar19;
        if (((uint)pdVar20 & 0x1f) == 0) goto LAB_00004f2a;
      }
      *pdVar20 = 0x80000000;
      local_f4 = local_f4 - 1;
    }
LAB_00004f2a:
    if ((local_2e9 == '\0') && (local_3a4 == *(uint *)(param_1 + 0x70))) {
      local_3b4 = local_3b4 + *(int *)(param_1 + 0x60);
      local_3b0 = local_3b0 + *(int *)(param_1 + 100);
    }
    if (local_3cc[10] == 1) {
      local_394 = 1;
    }
    else {
      local_394 = (uint)(local_3cc[10] == 2) * 2;
    }
    local_4a4 = (int)*(short *)(local_3cc + 1);
    if (((param_4 == 0x1000) || (param_4 == 0)) && (*(int *)(param_1 + 0x8c) == 0)) {
      cVar7 = ((int (*)())_createOffscreenBuffer)();
      if (cVar7 == '\0') goto LAB_00004c22;
      iVar8 = *(int *)(unaff_EBX + 0x8aa4);
      uVar17 = *(uint *)(iVar8 + 0x30);
      if (uVar17 == 3) {
        local_3a0 = 0xb;
      }
      else {
        local_3a0 = 0xc;
        if (uVar17 != 6) {
          local_3a0 = uVar17;
        }
      }
      if (local_3d4 != 0) {
        local_f8 = local_3d0;
        bVar6 = true;
        local_3bc = 0;
        do {
          iVar14 = (short)*local_f8 + local_3ac;
          fVar23 = (float)iVar14;
          iVar9 = *(short *)((int)local_f8 + 2) + local_3a8;
          fVar25 = (float)iVar9;
          fVar22 = fVar23 + (float)(int)(short)local_f8[1];
          fVar24 = fVar25 + (float)(int)*(short *)((int)local_f8 + 6);
          if (fVar23 <= 0.0) {
            fVar23 = 0.0;
          }
          pfVar1 = (float *)(unaff_EBX + 0x83ec);
          uVar17 = (int)(fVar23 - (float)(-(uint)(*pfVar1 <= fVar23) & (uint)*pfVar1)) +
                   (uint)(*pfVar1 <= fVar23) * -0x80000000 |
                   -(uint)(*(float *)(unaff_EBX + 0x83fc) <= fVar23);
          if (fVar25 <= 0.0) {
            fVar25 = 0.0;
          }
          uVar16 = (int)(fVar25 - (float)(-(uint)(*pfVar1 <= fVar25) & (uint)*pfVar1)) |
                   -(uint)(*(float *)(unaff_EBX + 0x83fc) <= fVar25);
          fVar23 = fVar22;
          if (fVar22 <= 0.0) {
            fVar23 = 0.0;
          }
          uVar13 = (int)(fVar23 - (float)(-(uint)(*pfVar1 <= fVar23) & (uint)*pfVar1)) +
                   (uint)(*pfVar1 <= fVar23) * -0x80000000 |
                   -(uint)(*(float *)(unaff_EBX + 0x83fc) <= fVar23);
          fVar23 = fVar24;
          if (fVar24 <= 0.0) {
            fVar23 = 0.0;
          }
          uVar18 = (int)(fVar23 - (float)(-(uint)(*pfVar1 <= fVar23) & (uint)*pfVar1)) |
                   -(uint)(*(float *)(unaff_EBX + 0x83fc) <= fVar23);
          if (bVar6) {
            if (local_f4 < 0x8a) {
              local_24[0] = 0.0;
              local_28 = *(float *)(param_1 + 0x18);
              if (*(int *)(param_1 + 0x8c) == 0) {
                *pdVar20 = 0x5c8;
                local_24[0] = 2.8026e-45;
                pdVar20[1] = 0xc000;
                *(undefined4 *)(param_1 + 0x94) = 0;
              }
              pdVar20[(int)local_24[0]] = 0x1000000;
              puVar4 = *(uint **)(param_1 + 0x7c);
              *puVar4 = *puVar4 | ((int)pdVar20 - (int)puVar4 >> 2) + (int)local_24[0];
              iVar10 = _IOConnectMapMemory(*(undefined4 *)(param_1 + 0xc),0,
                                           **(undefined4 **)(unaff_EBX + 0x94ac),&local_28,local_24,
                                           1);
              if (iVar10 == 0) {
                *(undefined4 *)((int)local_28 + 0x1c) = 0;
                fVar23 = local_28;
                goto LAB_0000844d;
              }
LAB_00008212:
              *(undefined4 *)(param_1 + 0x18) = 0;
              *(undefined4 *)(param_1 + 0x7c) = 0;
              pdVar20 = (dword *)0x0;
              pdVar21 = &__mh_bundle_header.cputype;
LAB_0000822c:
              bVar6 = true;
              local_f4 = uVar19;
            }
            else {
              pdVar21 = pdVar20 + 1;
              bVar6 = true;
            }
          }
          else {
            if (local_f4 < 0x22) {
              local_28 = 0.0;
              local_24[0] = *(float *)(param_1 + 0x18);
              if (*(int *)(param_1 + 0x8c) == 0) {
                *pdVar20 = 0x5c8;
                local_28 = 2.8026e-45;
                pdVar20[1] = 0xc000;
                *(undefined4 *)(param_1 + 0x94) = 0;
              }
              pdVar20[(int)local_28] = 0x1000000;
              puVar4 = *(uint **)(param_1 + 0x7c);
              *puVar4 = *puVar4 | ((int)pdVar20 - (int)puVar4 >> 2) + (int)local_28;
              iVar10 = _IOConnectMapMemory(*(undefined4 *)(param_1 + 0xc),0,
                                           **(undefined4 **)(unaff_EBX + 0x94ac),local_24,&local_28,
                                           1);
              if (iVar10 != 0) goto LAB_00008212;
              *(undefined4 *)((int)local_24[0] + 0x1c) = 0;
              fVar23 = local_24[0];
LAB_0000844d:
              *(int *)(param_1 + 0x7c) = (int)fVar23 + 0x1c;
              *(float *)(param_1 + 0x18) = fVar23;
              pdVar20 = (dword *)((int)fVar23 + 0x20);
              pdVar21 = (dword *)((int)fVar23 + 0x24);
              goto LAB_0000822c;
            }
            pdVar21 = pdVar20 + 1;
            bVar6 = false;
          }
          if (param_4 == 0x1000) {
            puVar4 = *(uint **)(param_1 + 0x7c);
            *puVar4 = *puVar4 | (int)pdVar20 - (int)puVar4 >> 2;
            *(dword **)(param_1 + 0x7c) = pdVar20;
            *pdVar20 = 0xa000000;
          }
          else {
            puVar4 = *(uint **)(param_1 + 0x7c);
            *puVar4 = *puVar4 | (int)pdVar20 - (int)puVar4 >> 2;
            *(dword **)(param_1 + 0x7c) = pdVar20;
            *pdVar20 = 0xe000000;
          }
          *pdVar21 = local_39c;
          puVar4 = *(uint **)(param_1 + 0x7c);
          *puVar4 = *puVar4 | (int)(pdVar21 + 1) - (int)puVar4 >> 2;
          *(dword **)(param_1 + 0x7c) = pdVar21 + 1;
          pdVar21[1] = 0x10000000;
          pdVar21[2] = *(dword *)**(undefined4 **)(unaff_EBX + 0x8aa4);
          pdVar21[3] = *(dword *)(*(int *)(unaff_EBX + 0x8aa4) + 0x1c);
          pdVar21[4] = 6;
          if (bVar6) {
            local_180 = ((int (*)())_radeon3DCopySetup)(local_3a4,0,0,0,0);
            local_4c4 = local_180 * 4;
            local_1cc = local_180 + 1;
            local_1c8 = local_180 + 2;
            local_1c4 = local_180 + 3;
            local_1c0 = local_180 + 4;
            iVar10 = local_180 + 5;
            local_1bc = local_180 + 6;
            local_1b8 = local_180 + 7;
            iVar12 = local_180 + 8;
            local_1b4 = local_180 + 9;
            local_1b0 = local_180 + 10;
            local_1ac = local_180 + 0xb;
            local_1a8 = local_180 + 0xc;
            local_1a4 = local_180 + 0xd;
            local_1a0 = local_180 + 0xe;
            local_19c = local_180 + 0xf;
            local_198 = local_180 + 0x10;
            local_194 = local_180 + 0x11;
            local_190 = local_180 + 0x12;
            local_18c = local_180 + 0x13;
            local_188 = local_180 + 0x14;
            local_184 = local_180 + 0x15;
            local_180 = local_180 + 0x16;
          }
          else {
            pdVar21[5] = 0x1120;
            pdVar21[6] = (int)*(short *)(local_3cc + 1) - 1U & 0x7ff |
                         ((int)*(short *)((int)local_3cc + 6) - 1U & 0x7ff) << 0xb | 0x80000000;
            pdVar21[7] = 0x1130;
            pdVar21[8] = local_3a4 & 0x1f | 0x53000;
            pdVar21[9] = 0x1140;
            pdVar21[10] = local_3cc[4] - 1 & 0x3fff |
                          ((int)*(short *)(local_3cc + 1) - 1U & 0x800) << 4 |
                          ((int)*(short *)((int)local_3cc + 6) - 1U & 0x800) << 5;
            local_4c4 = 0x18;
            local_1cc = 7;
            local_1c8 = 8;
            local_1c4 = 9;
            local_1c0 = 10;
            iVar10 = 0xb;
            local_1bc = 0xc;
            local_1b8 = 0xd;
            iVar12 = 0xe;
            local_1b4 = 0xf;
            local_1b0 = 0x10;
            local_1ac = 0x11;
            local_1a8 = 0x12;
            local_1a4 = 0x13;
            local_1a0 = 0x14;
            local_19c = 0x15;
            local_198 = 0x16;
            local_194 = 0x17;
            local_190 = 0x18;
            local_18c = 0x19;
            local_188 = 0x1a;
            local_184 = 0x1b;
            local_180 = 0x1c;
          }
          *(undefined4 *)((int)pdVar21 + local_4c4 + 0x14) = 0x10f8;
          pdVar21[local_1cc + 5] = uVar17 & 0x1fff | (uVar16 & 0x1fff) << 0xd;
          pdVar21[local_1c8 + 5] = 0x10f9;
          pdVar21[local_1c4 + 5] = uVar13 & 0x1fff | (uVar18 & 0x1fff) << 0xd;
          pdVar21[local_1c0 + 5] = 0xc00c3500;
          pdVar21[iVar10 + 5] = 0x4003d;
          local_30 = (float)((double)iVar14 *
                            (*(double *)(unaff_EBX + 0x840c) /
                            (double)(int)*(short *)(local_3cc + 1)));
          local_2c = (float)((double)fVar22 *
                            (*(double *)(unaff_EBX + 0x840c) /
                            (double)(int)*(short *)(local_3cc + 1)));
          local_28 = (float)((double)iVar9 *
                            (*(double *)(unaff_EBX + 0x840c) /
                            (double)(int)*(short *)((int)local_3cc + 6)));
          local_24[0] = (float)((double)fVar24 *
                               (*(double *)(unaff_EBX + 0x840c) /
                               (double)(int)*(short *)((int)local_3cc + 6)));
          uVar18 = uVar18 << 0x10;
          pdVar21[local_1bc + 5] = uVar17 | uVar18;
          pdVar21[local_1b8 + 5] = (dword)local_30;
          pdVar21[iVar12 + 5] = (dword)local_24[0];
          uVar16 = uVar16 << 0x10;
          pdVar21[local_1b4 + 5] = uVar17 | uVar16;
          pdVar21[local_1b0 + 5] = (dword)local_30;
          pdVar21[local_1ac + 5] = (dword)local_28;
          pdVar21[local_1a8 + 5] = uVar16 | uVar13;
          pdVar21[local_1a4 + 5] = (dword)local_2c;
          pdVar21[local_1a0 + 5] = (dword)local_28;
          pdVar21[local_19c + 5] = uVar18 | uVar13;
          pdVar21[local_198 + 5] = (dword)local_2c;
          pdVar21[local_194 + 5] = (dword)local_24[0];
          pdVar21[local_190 + 5] = 0x1393;
          pdVar21[local_18c + 5] = 10;
          pdVar21[local_188 + 5] = 0x5c8;
          pdVar21[local_184 + 5] = 0x20000;
          local_3b8 = (local_f4 - 6) - local_180;
          pdVar21 = pdVar21 + local_180 + 5;
          uVar17 = (short)*local_f8 + local_3b4;
          iVar10 = *(short *)((int)local_f8 + 2) + local_3b0;
          uVar16 = (int)(short)local_f8[1] + uVar17;
          iVar12 = *(short *)((int)local_f8 + 6) + iVar10;
          if (local_3b8 < 0x22) {
            local_30 = 0.0;
            local_2c = *(float *)(param_1 + 0x18);
            if (*(int *)(param_1 + 0x8c) == 0) {
              *pdVar21 = 0x5c8;
              local_30 = 2.8026e-45;
              pdVar21[1] = 0xc000;
              *(undefined4 *)(param_1 + 0x94) = 0;
            }
            pdVar21[(int)local_30] = 0x1000000;
            puVar4 = *(uint **)(param_1 + 0x7c);
            *puVar4 = *puVar4 | ((int)pdVar21 - (int)puVar4 >> 2) + (int)local_30;
            iVar11 = _IOConnectMapMemory(*(undefined4 *)(param_1 + 0xc),0,
                                         **(undefined4 **)(unaff_EBX + 0x94ac),&local_2c,&local_30,1
                                        );
            if (iVar11 == 0) {
              *(undefined4 *)((int)local_2c + 0x1c) = 0;
              *(int *)(param_1 + 0x7c) = (int)local_2c + 0x1c;
              *(float *)(param_1 + 0x18) = local_2c;
              pdVar21 = (dword *)((int)local_2c + 0x20);
              pdVar20 = (dword *)((int)local_2c + 0x24);
            }
            else {
              *(undefined4 *)(param_1 + 0x18) = 0;
              *(undefined4 *)(param_1 + 0x7c) = 0;
              pdVar21 = (dword *)0x0;
              pdVar20 = &__mh_bundle_header.cputype;
            }
            bVar6 = true;
            local_3b8 = uVar19;
          }
          else {
            pdVar20 = pdVar21 + 1;
            bVar6 = false;
          }
          if (param_4 == 0x1000) {
            puVar4 = *(uint **)(param_1 + 0x7c);
            *puVar4 = *puVar4 | (int)pdVar21 - (int)puVar4 >> 2;
            *(dword **)(param_1 + 0x7c) = pdVar21;
            *pdVar21 = 0x11000000;
          }
          else {
            puVar4 = *(uint **)(param_1 + 0x7c);
            *puVar4 = *puVar4 | (int)pdVar21 - (int)puVar4 >> 2;
            *(dword **)(param_1 + 0x7c) = pdVar21;
            *pdVar21 = 0x12000000;
          }
          *pdVar20 = local_39c;
          pdVar20[1] = 0;
          pdVar20[2] = 0;
          puVar4 = *(uint **)(param_1 + 0x7c);
          *puVar4 = *puVar4 | (int)(pdVar20 + 3) - (int)puVar4 >> 2;
          *(dword **)(param_1 + 0x7c) = pdVar20 + 3;
          pdVar20[3] = 0x4000000;
          pdVar20[4] = *(dword *)**(undefined4 **)(unaff_EBX + 0x8aa4);
          if (bVar6) {
            local_130 = ((int (*)())_radeon3DCopySetup)(local_3a0,0,0,0,0);
            local_4c4 = local_130 * 4;
            local_17c = local_130 + 1;
            local_178 = local_130 + 2;
            local_174 = local_130 + 3;
            local_170 = local_130 + 4;
            iVar11 = local_130 + 5;
            local_16c = local_130 + 6;
            local_168 = local_130 + 7;
            iVar15 = local_130 + 8;
            local_164 = local_130 + 9;
            local_160 = local_130 + 10;
            local_15c = local_130 + 0xb;
            local_158 = local_130 + 0xc;
            local_154 = local_130 + 0xd;
            local_150 = local_130 + 0xe;
            local_14c = local_130 + 0xf;
            local_148 = local_130 + 0x10;
            local_144 = local_130 + 0x11;
            local_140 = local_130 + 0x12;
            local_13c = local_130 + 0x13;
            local_138 = local_130 + 0x14;
            local_134 = local_130 + 0x15;
            local_130 = local_130 + 0x16;
          }
          else {
            pdVar20[5] = 0x1120;
            pdVar20[6] = (int)*(short *)(iVar8 + 0x10) - 1U & 0x7ff |
                         ((int)*(short *)(iVar8 + 0x12) - 1U & 0x7ff) << 0xb | 0x80000000;
            pdVar20[7] = 0x1130;
            pdVar20[8] = local_3a0 & 0x1f | 0x53000;
            pdVar20[9] = 0x1140;
            pdVar20[10] = *(int *)(iVar8 + 0x1c) - 1U & 0x3fff |
                          ((int)*(short *)(iVar8 + 0x10) - 1U & 0x800) << 4 |
                          ((int)*(short *)(iVar8 + 0x12) - 1U & 0x800) << 5;
            local_4c4 = 0x18;
            local_17c = 7;
            local_178 = 8;
            local_174 = 9;
            local_170 = 10;
            iVar11 = 0xb;
            local_16c = 0xc;
            local_168 = 0xd;
            iVar15 = 0xe;
            local_164 = 0xf;
            local_160 = 0x10;
            local_15c = 0x11;
            local_158 = 0x12;
            local_154 = 0x13;
            local_150 = 0x14;
            local_14c = 0x15;
            local_148 = 0x16;
            local_144 = 0x17;
            local_140 = 0x18;
            local_13c = 0x19;
            local_138 = 0x1a;
            local_134 = 0x1b;
            local_130 = 0x1c;
          }
          *(undefined4 *)((int)pdVar20 + local_4c4 + 0x14) = 0x10f8;
          pdVar20[local_17c + 5] = uVar17 & 0x1fff | iVar10 * 0x2000 & 0x3ffe000U;
          pdVar20[local_178 + 5] = 0x10f9;
          pdVar20[local_174 + 5] = uVar16 & 0x1fff | iVar12 * 0x2000 & 0x3ffe000U;
          pdVar20[local_170 + 5] = 0xc00c3500;
          pdVar20[iVar11 + 5] = 0x4003d;
          local_24[0] = (float)((double)iVar14 *
                               (*(double *)(unaff_EBX + 0x840c) /
                               (double)(int)*(short *)(iVar8 + 0x10)));
          local_28 = (float)((double)fVar22 *
                            (*(double *)(unaff_EBX + 0x840c) / (double)(int)*(short *)(iVar8 + 0x10)
                            ));
          local_30 = (float)((double)iVar9 *
                            (*(double *)(unaff_EBX + 0x840c) / (double)(int)*(short *)(iVar8 + 0x12)
                            ));
          local_2c = (float)((double)fVar24 *
                            (*(double *)(unaff_EBX + 0x840c) / (double)(int)*(short *)(iVar8 + 0x12)
                            ));
          uVar13 = iVar12 * 0x10000;
          pdVar20[local_16c + 5] = uVar17 | uVar13;
          pdVar20[local_168 + 5] = (dword)local_24[0];
          pdVar20[iVar15 + 5] = (dword)local_2c;
          pdVar20[local_164 + 5] = uVar17 | iVar10 * 0x10000;
          pdVar20[local_160 + 5] = (dword)local_24[0];
          pdVar20[local_15c + 5] = (dword)local_30;
          pdVar20[local_158 + 5] = iVar10 * 0x10000 | uVar16;
          pdVar20[local_154 + 5] = (dword)local_28;
          pdVar20[local_150 + 5] = (dword)local_30;
          pdVar20[local_14c + 5] = uVar16 | uVar13;
          pdVar20[local_148 + 5] = (dword)local_28;
          pdVar20[local_144 + 5] = (dword)local_2c;
          pdVar20[local_140 + 5] = 0x1393;
          pdVar20[local_13c + 5] = 10;
          pdVar20[local_138 + 5] = 0x5c8;
          pdVar20[local_134 + 5] = 0x20000;
          local_f4 = (local_3b8 - 6) - local_130;
          pdVar20 = pdVar20 + local_130 + 5;
          local_3bc = local_3bc + 1;
          local_f8 = local_f8 + 2;
          bVar6 = false;
        } while (local_3d4 != local_3bc);
      }
    }
    else if (local_4a4 < 0x1001) {
      if (local_3d4 != 0) {
        local_104 = local_3d0;
        bVar6 = true;
        local_7c = 0;
        do {
          fVar24 = (float)(local_3ac + (short)*local_104);
          fVar26 = (float)(local_3a8 + *(short *)((int)local_104 + 2));
          fVar25 = (float)(int)*(short *)((int)local_104 + 6) + fVar26;
          uVar16 = (short)*local_104 + local_3b4;
          iVar14 = *(short *)((int)local_104 + 2) + local_3b0;
          uVar17 = (int)(short)local_104[1] + uVar16;
          local_330 = *(short *)((int)local_104 + 6) + iVar14;
          if (*(short *)((int)local_3cc + 6) < 0x1000) {
            local_32c = (uint)*(short *)((int)local_3cc + 6);
            if ((int)local_32c < 0) {
              fVar27 = (float)local_32c;
            }
            else {
              fVar27 = (float)(int)local_32c;
            }
          }
          else {
            fVar27 = *(float *)(unaff_EBX + 0x83b8);
            if (fVar27 <= fVar25) {
              local_330 = local_3b0 + 0x1000;
              local_32c = 0x1000;
              fVar25 = fVar27;
            }
            else {
              local_32c = 0x1000;
            }
          }
          fVar28 = (*(float *)(unaff_EBX + 0x83bc) / (float)local_4a4) * fVar22;
          fVar29 = fVar24 * fVar28;
          fVar28 = ((float)(int)(short)local_104[1] + fVar24) * fVar28;
          fVar24 = (*(float *)(unaff_EBX + 0x83bc) / fVar27) * fVar23;
          fVar26 = fVar26 * fVar24;
          fVar25 = fVar25 * fVar24;
          if (bVar6) {
            if (local_f4 < 0x8a) {
              local_24[0] = 0.0;
              local_28 = *(float *)(param_1 + 0x18);
              if (*(int *)(param_1 + 0x8c) == 0) {
                *pdVar20 = 0x5c8;
                local_24[0] = 2.8026e-45;
                pdVar20[1] = 0xc000;
                *(undefined4 *)(param_1 + 0x94) = 0;
              }
              pdVar20[(int)local_24[0]] = 0x1000000;
              puVar4 = *(uint **)(param_1 + 0x7c);
              *puVar4 = *puVar4 | ((int)pdVar20 - (int)puVar4 >> 2) + (int)local_24[0];
              iVar10 = _IOConnectMapMemory(*(undefined4 *)(param_1 + 0xc),0,
                                           **(undefined4 **)(unaff_EBX + 0x94ac),&local_28,local_24,
                                           1);
              if (iVar10 == 0) {
                *(undefined4 *)((int)local_28 + 0x1c) = 0;
                fVar24 = local_28;
                goto LAB_00005cbb;
              }
LAB_00005999:
              *(undefined4 *)(param_1 + 0x18) = 0;
              *(undefined4 *)(param_1 + 0x7c) = 0;
              pdVar20 = (dword *)0x0;
              local_298 = &__mh_bundle_header.cputype;
              local_294 = &__mh_bundle_header.cpusubtype;
              local_290 = &__mh_bundle_header.filetype;
              pdVar21 = &__mh_bundle_header.ncmds;
              local_4c0 = &__mh_bundle_header.sizeofcmds;
              local_e4 = &__mh_bundle_header.flags;
              local_f4 = uVar19;
            }
            else {
              local_298 = pdVar20 + 1;
              local_294 = pdVar20 + 2;
              local_290 = pdVar20 + 3;
              pdVar21 = pdVar20 + 4;
              local_4c0 = pdVar20 + 5;
              local_e4 = pdVar20 + 6;
            }
LAB_000059f1:
            puVar4 = *(uint **)(param_1 + 0x7c);
            *puVar4 = *puVar4 | (int)pdVar20 - (int)puVar4 >> 2;
            *(dword **)(param_1 + 0x7c) = pdVar20;
            *pdVar20 = local_2f0;
            *local_298 = local_39c;
            *local_294 = local_394;
            *local_290 = 0;
            *pdVar21 = 0;
            *local_4c0 = 0;
            local_f4 = local_f4 - 6;
            local_29c = ((int (*)())_radeon3DCopySetup)(local_3a4,local_2e9,0,0,local_32c);
            iVar11 = local_29c * 4;
            iVar10 = local_29c + 1;
            iVar12 = local_29c + 2;
            local_2e8 = local_29c + 3;
            local_2e4 = local_29c + 4;
            local_2e0 = local_29c + 5;
            local_2dc = local_29c + 6;
            local_2d8 = local_29c + 7;
            local_2d4 = local_29c + 8;
            local_2d0 = local_29c + 9;
            local_2cc = local_29c + 10;
            local_2c8 = local_29c + 0xb;
            local_2c4 = local_29c + 0xc;
            local_2c0 = local_29c + 0xd;
            local_2bc = local_29c + 0xe;
            local_2b8 = local_29c + 0xf;
            local_2b4 = local_29c + 0x10;
            local_2b0 = local_29c + 0x11;
            local_2ac = local_29c + 0x12;
            local_2a8 = local_29c + 0x13;
            local_2a4 = local_29c + 0x14;
            local_2a0 = local_29c + 0x15;
            local_29c = local_29c + 0x16;
          }
          else {
            if (local_f4 < 0x16) {
              local_28 = 0.0;
              local_24[0] = *(float *)(param_1 + 0x18);
              if (*(int *)(param_1 + 0x8c) == 0) {
                *pdVar20 = 0x5c8;
                local_28 = 2.8026e-45;
                pdVar20[1] = 0xc000;
                *(undefined4 *)(param_1 + 0x94) = 0;
              }
              pdVar20[(int)local_28] = 0x1000000;
              puVar4 = *(uint **)(param_1 + 0x7c);
              *puVar4 = *puVar4 | ((int)pdVar20 - (int)puVar4 >> 2) + (int)local_28;
              iVar10 = _IOConnectMapMemory(*(undefined4 *)(param_1 + 0xc),0,
                                           **(undefined4 **)(unaff_EBX + 0x94ac),local_24,&local_28,
                                           1);
              if (iVar10 != 0) goto LAB_00005999;
              *(undefined4 *)((int)local_24[0] + 0x1c) = 0;
              fVar24 = local_24[0];
LAB_00005cbb:
              *(int *)(param_1 + 0x7c) = (int)fVar24 + 0x1c;
              *(float *)(param_1 + 0x18) = fVar24;
              pdVar20 = (dword *)((int)fVar24 + 0x20);
              local_298 = (dword *)((int)fVar24 + 0x24);
              local_294 = (dword *)((int)fVar24 + 0x28);
              local_290 = (dword *)((int)fVar24 + 0x2c);
              pdVar21 = (dword *)((int)fVar24 + 0x30);
              local_4c0 = (dword *)((int)fVar24 + 0x34);
              local_e4 = (dword *)((int)fVar24 + 0x38);
              local_f4 = uVar19;
              goto LAB_000059f1;
            }
            iVar11 = 0;
            iVar10 = 1;
            iVar12 = 2;
            local_2e8 = 3;
            local_2e4 = 4;
            local_2e0 = 5;
            local_2dc = 6;
            local_2d8 = 7;
            local_2d4 = 8;
            local_2d0 = 9;
            local_2cc = 10;
            local_2c8 = 0xb;
            local_2c4 = 0xc;
            local_2c0 = 0xd;
            local_2bc = 0xe;
            local_2b8 = 0xf;
            local_2b4 = 0x10;
            local_2b0 = 0x11;
            local_2ac = 0x12;
            local_2a8 = 0x13;
            local_2a4 = 0x14;
            local_2a0 = 0x15;
            local_29c = 0x16;
            local_e4 = pdVar20;
          }
          *(undefined4 *)((int)local_e4 + iVar11) = 0x10f8;
          local_e4[iVar10] = iVar14 * 0x2000 & 0x3ffe000U | uVar16 & 0x1fff;
          local_e4[iVar12] = 0x10f9;
          local_e4[local_2e8] = (local_330 & 0x1fff) << 0xd | uVar17 & 0x1fff;
          local_e4[local_2e4] = 0xc00c3500;
          local_e4[local_2e0] = 0x4003d;
          local_e4[local_2dc] = uVar16 | local_330 << 0x10;
          local_e4[local_2d8] = (dword)fVar29;
          local_e4[local_2d4] = (dword)fVar25;
          local_e4[local_2d0] = uVar16 | iVar14 * 0x10000;
          local_e4[local_2cc] = (dword)fVar29;
          local_e4[local_2c8] = (dword)fVar26;
          local_e4[local_2c4] = iVar14 * 0x10000 | uVar17;
          local_e4[local_2c0] = (dword)fVar28;
          local_e4[local_2bc] = (dword)fVar26;
          local_e4[local_2b8] = local_330 << 0x10 | uVar17;
          local_e4[local_2b4] = (dword)fVar28;
          local_e4[local_2b0] = (dword)fVar25;
          local_e4[local_2ac] = 0x1393;
          local_e4[local_2a8] = 10;
          local_e4[local_2a4] = 0x5c8;
          local_e4[local_2a0] = 0x20000;
          local_f4 = local_f4 - local_29c;
          pdVar20 = local_e4 + local_29c;
          iVar14 = (int)*(short *)((int)local_104 + 2) + (int)*(short *)((int)local_104 + 6);
          local_28 = fVar26;
          local_24[0] = fVar25;
          if (iVar14 < 0x1000) {
            bVar6 = false;
            local_30 = fVar28;
            local_2c = fVar29;
          }
          else {
            iVar10 = local_3b0 + *(short *)((int)local_104 + 2) +
                     (int)*(short *)((int)local_104 + 6);
            uVar13 = (int)*(short *)((int)local_3cc + 6) - 0x1000;
            fVar24 = (*(float *)(unaff_EBX + 0x83bc) / (float)uVar13) * fVar23;
            fVar27 = fVar24 * *(float *)(unaff_EBX + 0x83c0);
            fVar24 = (float)(local_3a8 + -0x1000 + iVar14) * fVar24;
            if (local_f4 < 0x8a) {
              local_2c = 0.0;
              local_30 = *(float *)(param_1 + 0x18);
              if (*(int *)(param_1 + 0x8c) == 0) {
                *pdVar20 = 0x5c8;
                local_2c = 2.8026e-45;
                pdVar20[1] = 0xc000;
                *(undefined4 *)(param_1 + 0x94) = 0;
              }
              pdVar20[(int)local_2c] = 0x1000000;
              puVar4 = *(uint **)(param_1 + 0x7c);
              *puVar4 = *puVar4 | ((int)pdVar20 - (int)puVar4 >> 2) + (int)local_2c;
              iVar14 = _IOConnectMapMemory(*(undefined4 *)(param_1 + 0xc),0,
                                           **(undefined4 **)(unaff_EBX + 0x94ac),&local_30,&local_2c
                                           ,1);
              if (iVar14 == 0) {
                *(undefined4 *)((int)local_30 + 0x1c) = 0;
                *(int *)(param_1 + 0x7c) = (int)local_30 + 0x1c;
                *(float *)(param_1 + 0x18) = local_30;
                pdVar20 = (dword *)((int)local_30 + 0x20);
                local_12c = (dword *)((int)local_30 + 0x24);
                local_128 = (dword *)((int)local_30 + 0x28);
                local_124 = (dword *)((int)local_30 + 0x2c);
                pdVar21 = (dword *)((int)local_30 + 0x30);
                local_4c0 = (dword *)((int)local_30 + 0x34);
                local_120 = (dword *)((int)local_30 + 0x38);
                local_f4 = uVar19;
              }
              else {
                *(undefined4 *)(param_1 + 0x18) = 0;
                *(undefined4 *)(param_1 + 0x7c) = 0;
                pdVar20 = (dword *)0x0;
                local_12c = &__mh_bundle_header.cputype;
                local_128 = &__mh_bundle_header.cpusubtype;
                local_124 = &__mh_bundle_header.filetype;
                pdVar21 = &__mh_bundle_header.ncmds;
                local_4c0 = &__mh_bundle_header.sizeofcmds;
                local_120 = &__mh_bundle_header.flags;
                local_f4 = uVar19;
              }
            }
            else {
              local_12c = pdVar20 + 1;
              local_128 = pdVar20 + 2;
              local_124 = pdVar20 + 3;
              pdVar21 = pdVar20 + 4;
              local_4c0 = pdVar20 + 5;
              local_120 = pdVar20 + 6;
              local_30 = fVar28;
              local_2c = fVar29;
            }
            puVar4 = *(uint **)(param_1 + 0x7c);
            *puVar4 = *puVar4 | (int)pdVar20 - (int)puVar4 >> 2;
            *(dword **)(param_1 + 0x7c) = pdVar20;
            *pdVar20 = local_2f0;
            *local_12c = local_39c;
            *local_128 = local_394;
            *local_124 = iVar8 * iVar9 * 0x1000;
            *pdVar21 = 0;
            *local_4c0 = 0;
            iVar14 = ((int (*)())_radeon3DCopySetup)(local_3a4,local_2e9,0,0,uVar13);
            local_120[iVar14] = 0x10f8;
            local_120[iVar14 + 1] = uVar16 & 0x1fff | (local_3b0 + 0x1000) * 0x2000 & 0x3ffe000U;
            local_120[iVar14 + 2] = 0x10f9;
            local_120[iVar14 + 3] = uVar17 & 0x1fff | iVar10 * 0x2000 & 0x3ffe000U;
            local_120[iVar14 + 4] = 0xc00c3500;
            local_120[iVar14 + 5] = 0x4003d;
            uVar18 = iVar10 * 0x10000;
            local_120[iVar14 + 6] = uVar16 | uVar18;
            local_120[iVar14 + 7] = (dword)fVar29;
            local_120[iVar14 + 8] = (dword)fVar24;
            uVar13 = (local_3b0 + 0x1000) * 0x10000;
            local_120[iVar14 + 9] = uVar16 | uVar13;
            local_120[iVar14 + 10] = (dword)fVar29;
            local_120[iVar14 + 0xb] = (dword)fVar27;
            local_120[iVar14 + 0xc] = uVar13 | uVar17;
            local_120[iVar14 + 0xd] = (dword)fVar28;
            local_120[iVar14 + 0xe] = (dword)fVar27;
            local_120[iVar14 + 0xf] = uVar17 | uVar18;
            local_120[iVar14 + 0x10] = (dword)fVar28;
            local_120[iVar14 + 0x11] = (dword)fVar24;
            local_120[iVar14 + 0x12] = 0x1393;
            local_120[iVar14 + 0x13] = 10;
            local_120[iVar14 + 0x14] = 0x5c8;
            local_120[iVar14 + 0x15] = 0x20000;
            local_f4 = (local_f4 - 6) - (iVar14 + 0x16);
            pdVar20 = local_120 + iVar14 + 0x16;
            bVar6 = true;
            local_30 = fVar24;
            local_2c = fVar27;
            local_28 = fVar28;
            local_24[0] = fVar29;
          }
          local_7c = local_7c + 1;
          local_104 = local_104 + 2;
          if (local_3d4 == local_7c) break;
          local_4a4 = (int)*(short *)(local_3cc + 1);
        } while( true );
      }
    }
    else {
      uVar17 = local_4a4 >> 1 & 0xfffffe00;
      iVar8 = uVar17 + 2;
      local_4a4 = local_4a4 - uVar17;
      fVar25 = *(float *)(unaff_EBX + 0x83bc);
      fVar24 = fVar25 / (float)(int)*(short *)((int)local_3cc + 6);
      if (local_3d4 != 0) {
        local_fc = local_3d0;
        bVar6 = true;
        local_78 = 0;
        do {
          iVar9 = (int)(short)*local_fc;
          if (local_3ac + iVar9 < iVar8) {
            iVar10 = iVar9 + (short)local_fc[1] + local_3ac;
            if (iVar8 <= iVar10) {
              iVar10 = iVar8;
            }
            sVar2 = *(short *)((int)local_fc + 2);
            iVar12 = local_3b4 + iVar9 + (int)(short)local_fc[1];
            if (iVar8 < iVar12) {
              iVar12 = local_3b4 + iVar8;
            }
            uVar16 = (short)*local_fc + local_3b4;
            fVar26 = (float)iVar12;
            if ((float)iVar12 <= 0.0) {
              fVar26 = 0.0;
            }
            uVar13 = (uint)(*(float *)(unaff_EBX + 0x83ec) <= fVar26);
            uVar13 = (int)(fVar26 - (float)((uint)*(float *)(unaff_EBX + 0x83ec) & -uVar13)) +
                     uVar13 * -0x80000000 | -(uint)(*(float *)(unaff_EBX + 0x83fc) <= fVar26);
            iVar12 = sVar2 + local_3b0;
            iVar11 = *(short *)((int)local_fc + 6) + iVar12;
            fVar29 = (float)(local_3ac + iVar9) * (fVar25 / (float)iVar8) * fVar22;
            fVar28 = (float)iVar10 * (fVar25 / (float)iVar8) * fVar22;
            fVar27 = (float)(local_3a8 + sVar2) * fVar24 * fVar23;
            fVar26 = (float)((int)sVar2 + (int)*(short *)((int)local_fc + 6) + local_3a8) * fVar24 *
                     fVar23;
            if (bVar6) {
              if (local_f4 < 0x9e) {
                local_24[0] = 0.0;
                local_28 = *(float *)(param_1 + 0x18);
                if (*(int *)(param_1 + 0x8c) == 0) {
                  *pdVar20 = 0x5c8;
                  local_24[0] = 2.8026e-45;
                  pdVar20[1] = 0xc000;
                  *(undefined4 *)(param_1 + 0x94) = 0;
                }
                pdVar20[(int)local_24[0]] = 0x1000000;
                puVar4 = *(uint **)(param_1 + 0x7c);
                *puVar4 = *puVar4 | ((int)pdVar20 - (int)puVar4 >> 2) + (int)local_24[0];
                iVar9 = _IOConnectMapMemory(*(undefined4 *)(param_1 + 0xc),0,
                                            **(undefined4 **)(unaff_EBX + 0x94ac),&local_28,local_24
                                            ,1);
                if (iVar9 == 0) {
                  *(undefined4 *)((int)local_28 + 0x1c) = 0;
                  *(int *)(param_1 + 0x7c) = (int)local_28 + 0x1c;
                  *(float *)(param_1 + 0x18) = local_28;
                  pdVar20 = (dword *)((int)local_28 + 0x20);
                  local_11c = (dword *)((int)local_28 + 0x24);
                  local_118 = (dword *)((int)local_28 + 0x28);
                  local_114 = (dword *)((int)local_28 + 0x2c);
                  pdVar21 = (dword *)((int)local_28 + 0x30);
                  local_4c0 = (dword *)((int)local_28 + 0x34);
                  local_e8 = (dword *)((int)local_28 + 0x38);
                  local_f4 = uVar19;
                }
                else {
                  *(undefined4 *)(param_1 + 0x18) = 0;
                  *(undefined4 *)(param_1 + 0x7c) = 0;
                  pdVar20 = (dword *)0x0;
                  local_11c = &__mh_bundle_header.cputype;
                  local_118 = &__mh_bundle_header.cpusubtype;
                  local_114 = &__mh_bundle_header.filetype;
                  pdVar21 = &__mh_bundle_header.ncmds;
                  local_4c0 = &__mh_bundle_header.sizeofcmds;
                  local_e8 = &__mh_bundle_header.flags;
                  local_f4 = uVar19;
                }
              }
              else {
                local_11c = pdVar20 + 1;
                local_118 = pdVar20 + 2;
                local_114 = pdVar20 + 3;
                pdVar21 = pdVar20 + 4;
                local_4c0 = pdVar20 + 5;
                local_e8 = pdVar20 + 6;
              }
              puVar4 = *(uint **)(param_1 + 0x7c);
              *puVar4 = *puVar4 | (int)pdVar20 - (int)puVar4 >> 2;
              *(dword **)(param_1 + 0x7c) = pdVar20;
              *pdVar20 = local_2f0;
              *local_11c = local_39c;
              *local_118 = local_394;
              *local_114 = 0;
              *pdVar21 = 0;
              *local_4c0 = 0;
              local_f4 = local_f4 - 4;
              local_240 = ((int (*)())_radeon3DCopySetup)(local_3a4,local_2e9,0,iVar8,0);
              local_4c4 = local_240 * 4;
              local_28c = local_240 + 1;
              local_288 = local_240 + 2;
              iVar9 = local_240 + 3;
              local_284 = local_240 + 4;
              iVar10 = local_240 + 5;
              local_280 = local_240 + 6;
              local_27c = local_240 + 7;
              local_278 = local_240 + 8;
              local_274 = local_240 + 9;
              local_270 = local_240 + 10;
              local_26c = local_240 + 0xb;
              local_268 = local_240 + 0xc;
              local_264 = local_240 + 0xd;
              local_260 = local_240 + 0xe;
              local_25c = local_240 + 0xf;
              local_258 = local_240 + 0x10;
              local_254 = local_240 + 0x11;
              local_250 = local_240 + 0x12;
              local_24c = local_240 + 0x13;
              local_248 = local_240 + 0x14;
              local_244 = local_240 + 0x15;
              local_240 = local_240 + 0x16;
            }
            else if (local_f4 < 0x2a) {
              local_28 = 0.0;
              local_24[0] = *(float *)(param_1 + 0x18);
              if (*(int *)(param_1 + 0x8c) == 0) {
                *pdVar20 = 0x5c8;
                local_28 = 2.8026e-45;
                pdVar20[1] = 0xc000;
                *(undefined4 *)(param_1 + 0x94) = 0;
              }
              pdVar20[(int)local_28] = 0x1000000;
              puVar4 = *(uint **)(param_1 + 0x7c);
              *puVar4 = *puVar4 | ((int)pdVar20 - (int)puVar4 >> 2) + (int)local_28;
              iVar9 = _IOConnectMapMemory(*(undefined4 *)(param_1 + 0xc),0,
                                          **(undefined4 **)(unaff_EBX + 0x94ac),local_24,&local_28,1
                                         );
              if (iVar9 == 0) {
                *(undefined4 *)((int)local_24[0] + 0x1c) = 0;
                *(int *)(param_1 + 0x7c) = (int)local_24[0] + 0x1c;
                *(float *)(param_1 + 0x18) = local_24[0];
                pdVar20 = (dword *)((int)local_24[0] + 0x20);
                local_23c = (dword *)((int)local_24[0] + 0x24);
                local_238 = (dword *)((int)local_24[0] + 0x28);
                local_234 = (dword *)((int)local_24[0] + 0x2c);
                local_230 = (dword *)((int)local_24[0] + 0x30);
                local_4c8 = (dword *)((int)local_24[0] + 0x34);
                local_e8 = (dword *)((int)local_24[0] + 0x38);
              }
              else {
                *(undefined4 *)(param_1 + 0x18) = 0;
                *(undefined4 *)(param_1 + 0x7c) = 0;
                pdVar20 = (dword *)0x0;
                local_23c = &__mh_bundle_header.cputype;
                local_238 = &__mh_bundle_header.cpusubtype;
                local_234 = &__mh_bundle_header.filetype;
                local_230 = &__mh_bundle_header.ncmds;
                local_4c8 = &__mh_bundle_header.sizeofcmds;
                local_e8 = &__mh_bundle_header.flags;
              }
              puVar4 = *(uint **)(param_1 + 0x7c);
              *puVar4 = *puVar4 | (int)pdVar20 - (int)puVar4 >> 2;
              *(dword **)(param_1 + 0x7c) = pdVar20;
              *pdVar20 = local_2f0;
              *local_23c = local_39c;
              *local_238 = local_394;
              *local_234 = 0;
              *local_230 = 0;
              *local_4c8 = 0;
              local_f4 = iVar14 - 0xb;
              local_240 = ((int (*)())_radeon3DCopySetup)(local_3a4,local_2e9,0,iVar8,0);
              local_4c4 = local_240 * 4;
              local_28c = local_240 + 1;
              local_288 = local_240 + 2;
              iVar9 = local_240 + 3;
              local_284 = local_240 + 4;
              iVar10 = local_240 + 5;
              local_280 = local_240 + 6;
              local_27c = local_240 + 7;
              local_278 = local_240 + 8;
              local_274 = local_240 + 9;
              local_270 = local_240 + 10;
              local_26c = local_240 + 0xb;
              local_268 = local_240 + 0xc;
              local_264 = local_240 + 0xd;
              local_260 = local_240 + 0xe;
              local_25c = local_240 + 0xf;
              local_258 = local_240 + 0x10;
              local_254 = local_240 + 0x11;
              local_250 = local_240 + 0x12;
              local_24c = local_240 + 0x13;
              local_248 = local_240 + 0x14;
              local_244 = local_240 + 0x15;
              local_240 = local_240 + 0x16;
            }
            else {
              local_4c4 = 0;
              local_28c = 1;
              local_288 = 2;
              iVar9 = 3;
              local_284 = 4;
              iVar10 = 5;
              local_280 = 6;
              local_27c = 7;
              local_278 = 8;
              local_274 = 9;
              local_270 = 10;
              local_26c = 0xb;
              local_268 = 0xc;
              local_264 = 0xd;
              local_260 = 0xe;
              local_25c = 0xf;
              local_258 = 0x10;
              local_254 = 0x11;
              local_250 = 0x12;
              local_24c = 0x13;
              local_248 = 0x14;
              local_244 = 0x15;
              local_240 = 0x16;
              local_e8 = pdVar20;
            }
            *(undefined4 *)((int)local_e8 + local_4c4) = 0x10f8;
            local_e8[local_28c] = uVar16 & 0x1fff | iVar12 * 0x2000 & 0x3ffe000U;
            local_e8[local_288] = 0x10f9;
            local_e8[iVar9] = uVar13 & 0x1fff | iVar11 * 0x2000 & 0x3ffe000U;
            local_e8[local_284] = 0xc00c3500;
            local_e8[iVar10] = 0x4003d;
            uVar18 = iVar11 * 0x10000;
            local_e8[local_280] = uVar16 | uVar18;
            local_e8[local_27c] = (dword)fVar29;
            local_e8[local_278] = (dword)fVar26;
            local_e8[local_274] = uVar16 | iVar12 * 0x10000;
            local_e8[local_270] = (dword)fVar29;
            local_e8[local_26c] = (dword)fVar27;
            local_e8[local_268] = iVar12 * 0x10000 | uVar13;
            local_e8[local_264] = (dword)fVar28;
            local_e8[local_260] = (dword)fVar27;
            local_e8[local_25c] = uVar18 | uVar13;
            local_e8[local_258] = (dword)fVar28;
            local_e8[local_254] = (dword)fVar26;
            local_e8[local_250] = 0x1393;
            local_e8[local_24c] = 10;
            local_e8[local_248] = 0x5c8;
            local_e8[local_244] = 0x20000;
            local_f4 = local_f4 - local_240;
            pdVar20 = local_e8 + local_240;
            bVar6 = false;
            local_30 = fVar29;
            local_2c = fVar28;
            local_28 = fVar27;
            local_24[0] = fVar26;
          }
          local_78 = local_78 + 1;
          local_fc = local_fc + 2;
        } while (local_3d4 != local_78);
        local_100 = local_3d0;
        bVar6 = true;
        local_74 = 0;
        do {
          iVar8 = (int)(short)*local_100;
          iVar9 = iVar8 + (short)local_100[1] + local_3ac;
          if ((int)uVar17 < iVar9) {
            uVar16 = local_3ac + iVar8;
            if (local_3ac + iVar8 <= (int)uVar17) {
              uVar16 = uVar17;
            }
            sVar2 = *(short *)((int)local_100 + 2);
            iVar8 = local_3b4 + iVar8;
            if (iVar8 <= (int)uVar17) {
              iVar8 = local_3b4 + uVar17;
            }
            fVar26 = (float)iVar8;
            if ((float)iVar8 <= 0.0) {
              fVar26 = 0.0;
            }
            uVar13 = (uint)(*(float *)(unaff_EBX + 0x83ec) <= fVar26);
            uVar18 = (int)(fVar26 - (float)((uint)*(float *)(unaff_EBX + 0x83ec) & -uVar13)) +
                     uVar13 * -0x80000000 | -(uint)(*(float *)(unaff_EBX + 0x83fc) <= fVar26);
            uVar13 = (short)*local_100 + local_3b4 + (int)(short)local_100[1];
            iVar8 = sVar2 + local_3b0;
            iVar10 = *(short *)((int)local_100 + 6) + iVar8;
            fVar26 = ((float)(int)uVar16 - (float)(int)uVar17) * (fVar25 / (float)local_4a4) *
                     fVar22;
            fVar29 = (float)(int)(iVar9 - uVar17) * (fVar25 / (float)local_4a4) * fVar22;
            fVar28 = (float)(local_3a8 + sVar2) * fVar24 * fVar23;
            fVar27 = (float)((int)sVar2 + (int)*(short *)((int)local_100 + 6) + local_3ac) * fVar24
                     * fVar23;
            if (bVar6) {
              if (local_f4 < 0x9e) {
                local_30 = 0.0;
                local_2c = *(float *)(param_1 + 0x18);
                if (*(int *)(param_1 + 0x8c) == 0) {
                  *pdVar20 = 0x5c8;
                  local_30 = 2.8026e-45;
                  pdVar20[1] = 0xc000;
                  *(undefined4 *)(param_1 + 0x94) = 0;
                }
                pdVar20[(int)local_30] = 0x1000000;
                puVar4 = *(uint **)(param_1 + 0x7c);
                *puVar4 = *puVar4 | ((int)pdVar20 - (int)puVar4 >> 2) + (int)local_30;
                iVar9 = _IOConnectMapMemory(*(undefined4 *)(param_1 + 0xc),0,
                                            **(undefined4 **)(unaff_EBX + 0x94ac),&local_2c,
                                            &local_30,1);
                if (iVar9 == 0) {
                  *(undefined4 *)((int)local_2c + 0x1c) = 0;
                  *(int *)(param_1 + 0x7c) = (int)local_2c + 0x1c;
                  *(float *)(param_1 + 0x18) = local_2c;
                  pdVar20 = (dword *)((int)local_2c + 0x20);
                  local_110 = (dword *)((int)local_2c + 0x24);
                  local_10c = (dword *)((int)local_2c + 0x28);
                  local_108 = (dword *)((int)local_2c + 0x2c);
                  pdVar21 = (dword *)((int)local_2c + 0x30);
                  local_4c0 = (dword *)((int)local_2c + 0x34);
                  local_e0 = (dword *)((int)local_2c + 0x38);
                  local_f4 = uVar19;
                }
                else {
                  *(undefined4 *)(param_1 + 0x18) = 0;
                  *(undefined4 *)(param_1 + 0x7c) = 0;
                  pdVar20 = (dword *)0x0;
                  local_110 = &__mh_bundle_header.cputype;
                  local_10c = &__mh_bundle_header.cpusubtype;
                  local_108 = &__mh_bundle_header.filetype;
                  pdVar21 = &__mh_bundle_header.ncmds;
                  local_4c0 = &__mh_bundle_header.sizeofcmds;
                  local_e0 = &__mh_bundle_header.flags;
                  local_f4 = uVar19;
                }
              }
              else {
                local_110 = pdVar20 + 1;
                local_10c = pdVar20 + 2;
                local_108 = pdVar20 + 3;
                pdVar21 = pdVar20 + 4;
                local_4c0 = pdVar20 + 5;
                local_e0 = pdVar20 + 6;
              }
              puVar4 = *(uint **)(param_1 + 0x7c);
              *puVar4 = *puVar4 | (int)pdVar20 - (int)puVar4 >> 2;
              *(dword **)(param_1 + 0x7c) = pdVar20;
              *pdVar20 = local_2f0;
              *local_110 = local_39c;
              *local_10c = local_394;
              *local_108 = 0;
              *pdVar21 = local_3cc[0xb];
              *local_4c0 = uVar17;
              local_f4 = local_f4 - 4;
              local_1e0 = ((int (*)())_radeon3DCopySetup)(local_3a4,local_2e9,0,local_4a4,0);
              local_4c4 = local_1e0 * 4;
              local_22c = local_1e0 + 1;
              local_228 = local_1e0 + 2;
              iVar9 = local_1e0 + 3;
              local_224 = local_1e0 + 4;
              iVar12 = local_1e0 + 5;
              local_220 = local_1e0 + 6;
              local_21c = local_1e0 + 7;
              local_218 = local_1e0 + 8;
              local_214 = local_1e0 + 9;
              local_210 = local_1e0 + 10;
              local_20c = local_1e0 + 0xb;
              local_208 = local_1e0 + 0xc;
              local_204 = local_1e0 + 0xd;
              local_200 = local_1e0 + 0xe;
              local_1fc = local_1e0 + 0xf;
              local_1f8 = local_1e0 + 0x10;
              local_1f4 = local_1e0 + 0x11;
              local_1f0 = local_1e0 + 0x12;
              local_1ec = local_1e0 + 0x13;
              local_1e8 = local_1e0 + 0x14;
              local_1e4 = local_1e0 + 0x15;
              local_1e0 = local_1e0 + 0x16;
            }
            else if (local_f4 < 0x2a) {
              local_2c = 0.0;
              local_30 = *(float *)(param_1 + 0x18);
              if (*(int *)(param_1 + 0x8c) == 0) {
                *pdVar20 = 0x5c8;
                local_2c = 2.8026e-45;
                pdVar20[1] = 0xc000;
                *(undefined4 *)(param_1 + 0x94) = 0;
              }
              pdVar20[(int)local_2c] = 0x1000000;
              puVar4 = *(uint **)(param_1 + 0x7c);
              *puVar4 = *puVar4 | ((int)pdVar20 - (int)puVar4 >> 2) + (int)local_2c;
              iVar9 = _IOConnectMapMemory(*(undefined4 *)(param_1 + 0xc),0,
                                          **(undefined4 **)(unaff_EBX + 0x94ac),&local_30,&local_2c,
                                          1);
              if (iVar9 == 0) {
                *(undefined4 *)((int)local_30 + 0x1c) = 0;
                *(int *)(param_1 + 0x7c) = (int)local_30 + 0x1c;
                *(float *)(param_1 + 0x18) = local_30;
                pdVar20 = (dword *)((int)local_30 + 0x20);
                local_1dc = (dword *)((int)local_30 + 0x24);
                local_1d8 = (dword *)((int)local_30 + 0x28);
                local_1d4 = (dword *)((int)local_30 + 0x2c);
                local_1d0 = (dword *)((int)local_30 + 0x30);
                local_4c8 = (dword *)((int)local_30 + 0x34);
                local_e0 = (dword *)((int)local_30 + 0x38);
              }
              else {
                *(undefined4 *)(param_1 + 0x18) = 0;
                *(undefined4 *)(param_1 + 0x7c) = 0;
                pdVar20 = (dword *)0x0;
                local_1dc = &__mh_bundle_header.cputype;
                local_1d8 = &__mh_bundle_header.cpusubtype;
                local_1d4 = &__mh_bundle_header.filetype;
                local_1d0 = &__mh_bundle_header.ncmds;
                local_4c8 = &__mh_bundle_header.sizeofcmds;
                local_e0 = &__mh_bundle_header.flags;
              }
              puVar4 = *(uint **)(param_1 + 0x7c);
              *puVar4 = *puVar4 | (int)pdVar20 - (int)puVar4 >> 2;
              *(dword **)(param_1 + 0x7c) = pdVar20;
              *pdVar20 = local_2f0;
              *local_1dc = local_39c;
              *local_1d8 = local_394;
              *local_1d4 = 0;
              *local_1d0 = local_3cc[0xb];
              *local_4c8 = uVar17;
              local_f4 = iVar14 - 0xb;
              local_1e0 = ((int (*)())_radeon3DCopySetup)(local_3a4,local_2e9,0,local_4a4,0);
              local_4c4 = local_1e0 * 4;
              local_22c = local_1e0 + 1;
              local_228 = local_1e0 + 2;
              iVar9 = local_1e0 + 3;
              local_224 = local_1e0 + 4;
              iVar12 = local_1e0 + 5;
              local_220 = local_1e0 + 6;
              local_21c = local_1e0 + 7;
              local_218 = local_1e0 + 8;
              local_214 = local_1e0 + 9;
              local_210 = local_1e0 + 10;
              local_20c = local_1e0 + 0xb;
              local_208 = local_1e0 + 0xc;
              local_204 = local_1e0 + 0xd;
              local_200 = local_1e0 + 0xe;
              local_1fc = local_1e0 + 0xf;
              local_1f8 = local_1e0 + 0x10;
              local_1f4 = local_1e0 + 0x11;
              local_1f0 = local_1e0 + 0x12;
              local_1ec = local_1e0 + 0x13;
              local_1e8 = local_1e0 + 0x14;
              local_1e4 = local_1e0 + 0x15;
              local_1e0 = local_1e0 + 0x16;
            }
            else {
              local_4c4 = 0;
              local_22c = 1;
              local_228 = 2;
              iVar9 = 3;
              local_224 = 4;
              iVar12 = 5;
              local_220 = 6;
              local_21c = 7;
              local_218 = 8;
              local_214 = 9;
              local_210 = 10;
              local_20c = 0xb;
              local_208 = 0xc;
              local_204 = 0xd;
              local_200 = 0xe;
              local_1fc = 0xf;
              local_1f8 = 0x10;
              local_1f4 = 0x11;
              local_1f0 = 0x12;
              local_1ec = 0x13;
              local_1e8 = 0x14;
              local_1e4 = 0x15;
              local_1e0 = 0x16;
              local_e0 = pdVar20;
            }
            *(undefined4 *)((int)local_e0 + local_4c4) = 0x10f8;
            local_e0[local_22c] = uVar18 & 0x1fff | iVar8 * 0x2000 & 0x3ffe000U;
            local_e0[local_228] = 0x10f9;
            local_e0[iVar9] = uVar13 & 0x1fff | iVar10 * 0x2000 & 0x3ffe000U;
            local_e0[local_224] = 0xc00c3500;
            local_e0[iVar12] = 0x4003d;
            uVar16 = iVar10 * 0x10000;
            local_e0[local_220] = uVar18 | uVar16;
            local_e0[local_21c] = (dword)fVar26;
            local_e0[local_218] = (dword)fVar27;
            local_e0[local_214] = uVar18 | iVar8 * 0x10000;
            local_e0[local_210] = (dword)fVar26;
            local_e0[local_20c] = (dword)fVar28;
            local_e0[local_208] = iVar8 * 0x10000 | uVar13;
            local_e0[local_204] = (dword)fVar29;
            local_e0[local_200] = (dword)fVar28;
            local_e0[local_1fc] = uVar13 | uVar16;
            local_e0[local_1f8] = (dword)fVar29;
            local_e0[local_1f4] = (dword)fVar27;
            local_e0[local_1f0] = 0x1393;
            local_e0[local_1ec] = 10;
            local_e0[local_1e8] = 0x5c8;
            local_e0[local_1e4] = 0x20000;
            local_f4 = local_f4 - local_1e0;
            pdVar20 = local_e0 + local_1e0;
            bVar6 = false;
            local_30 = fVar27;
            local_2c = fVar26;
            local_28 = fVar29;
            local_24[0] = fVar28;
          }
          local_74 = local_74 + 1;
          local_100 = local_100 + 2;
        } while (local_3d4 != local_74);
      }
    }
    *(dword **)(param_1 + 0x80) = pdVar20;
    iVar8 = 0;
  }
  return iVar8;
}

/* _radeonFill @ 0x85ba (9833 bytes) */
int _radeonFill(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  undefined4 param_2;
  uint param_3;
  uint param_4;
  int param_5;
  undefined4 param_6;
{
  double dVar1;
  uint uVar2;
  uint *puVar3;
  char cVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  dword *pdVar15;
  uint uVar16;
  dword *pdVar17;
  int unaff_EBX;
  int iVar18;
  float *pfVar19;
  dword *pdVar20;
  int iVar21;
  float *pfVar22;
  bool bVar23;
  float fVar24;
  float fVar25;
  float fVar26;
  float fVar27;
  float fVar28;
  float fVar29;
  float *local_234;
  char local_204;
  float *local_1ec;
  float *local_1e8;
  float *local_1e4;
  float *local_1e0;
  float *local_1dc;
  float *local_1d8;
  float *local_1d4;
  float *local_1d0;
  float *local_1cc;
  int local_1c8;
  undefined4 *local_19c;
  uint local_198;
  uint local_194;
  uint local_18c;
  dword *local_17c;
  uint local_174;
  uint local_15c;
  uint local_158;
  uint local_154;
  int local_14c;
  int local_148;
  int local_144;
  int local_140;
  int local_13c;
  int local_138;
  int local_134;
  int local_130;
  int local_12c;
  int local_128;
  int local_124;
  int local_120;
  int local_11c;
  int local_118;
  int local_114;
  int local_110;
  int local_10c;
  int local_108;
  int local_104;
  int local_100;
  int local_fc;
  int local_f8;
  int local_f4;
  int local_f0;
  int local_ec;
  int local_e8;
  dword *local_e4;
  dword *local_e0;
  dword *local_dc;
  int local_d8;
  int local_d4;
  int local_d0;
  int local_cc;
  int local_c8;
  int local_c4;
  int local_c0;
  int local_bc;
  int local_b8;
  int local_b4;
  int local_b0;
  int local_ac;
  int local_a8;
  int local_a4;
  int local_a0;
  int local_9c;
  int local_98;
  int local_94;
  int local_90;
  int local_8c;
  int local_88;
  int local_84;
  int local_80;
  uint local_7c;
  dword *local_78;
  dword *local_74;
  dword *local_70;
  undefined4 *local_68;
  int local_64;
  uint local_58;
  uint local_54;
  uint local_50;
  float local_44;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  
  ((int (*)())___i686_get_pc_thunk_bx)();
  if (((param_4 & 0x7ffff000) == 0x6000) && ((param_3 & 0xf000) == 0)) {
    iVar10 = *(int *)(*(int *)(param_1 + 0x18) + 0x10);
    uVar2 = iVar10 - 7;
    local_19c = *(undefined4 **)(param_1 + 0x80);
    if (local_19c != (undefined4 *)0x0) {
      local_198 = uVar2 - ((int)local_19c - (*(int *)(param_1 + 0x18) + 0x20) >> 2);
      iVar10 = (iVar10 - 0x75U) / 0xc - 1;
      uVar12 = *(uint *)(param_5 + 0x58);
      if (uVar12 != 0) {
        local_194 = 0;
        do {
          if (local_198 < iVar10 * 0xc + 0x6eU) {
            local_44 = 0.0;
            local_2c = *(float *)(param_1 + 0x18);
            if (*(int *)(param_1 + 0x8c) == 0) {
              *local_19c = 0x5c8;
              local_44 = 2.8026e-45;
              local_19c[1] = 0xc000;
              *(undefined4 *)(param_1 + 0x94) = 0;
            }
            local_19c[(int)local_44] = 0x1000000;
            puVar3 = *(uint **)(param_1 + 0x7c);
            *puVar3 = *puVar3 | ((int)local_19c - (int)puVar3 >> 2) + (int)local_44;
            iVar11 = _IOConnectMapMemory(*(undefined4 *)(param_1 + 0xc),0,
                                         **(undefined4 **)(unaff_EBX + 0x5ac5),&local_2c,&local_44,1
                                        );
            local_198 = uVar2;
            if (iVar11 == 0) {
              *(undefined4 *)((int)local_2c + 0x1c) = 0;
              *(int *)(param_1 + 0x7c) = (int)local_2c + 0x1c;
              *(float *)(param_1 + 0x18) = local_2c;
              local_68 = (undefined4 *)((int)local_2c + 0x20);
              uVar12 = *(uint *)(param_5 + 0x58);
            }
            else {
              *(undefined4 *)(param_1 + 0x18) = 0;
              *(undefined4 *)(param_1 + 0x7c) = 0;
              local_68 = (undefined4 *)0x0;
              uVar12 = *(uint *)(param_5 + 0x58);
            }
          }
          else {
            local_68 = local_19c;
          }
          uVar6 = local_194 + iVar10;
          uVar5 = uVar6;
          if (uVar12 <= uVar6) {
            uVar5 = uVar12;
          }
          iVar11 = ((int (*)())_radeon3DFillSetup)(param_1);
          iVar18 = uVar5 - local_194;
          local_68[iVar11] = iVar18 * 0xc0000 | 0xc0003500;
          local_64 = iVar11 + 2;
          local_68[iVar11 + 1] = iVar18 * 0x40000 | 0x3d;
          if (local_194 < uVar5) {
            local_18c = local_194;
            iVar11 = local_194 * 0x10 + param_5;
            pfVar22 = (float *)(local_68 + local_64);
            local_1cc = pfVar22 + -1;
            local_1d0 = pfVar22 + 10;
            local_1d4 = pfVar22 + 9;
            local_1d8 = pfVar22 + 8;
            local_1dc = pfVar22 + 7;
            local_1e0 = pfVar22 + 6;
            local_1e4 = pfVar22 + 5;
            local_1e8 = pfVar22 + 4;
            local_1ec = pfVar22 + 3;
            pfVar19 = pfVar22 + 2;
            local_234 = pfVar22 + 1;
            do {
              iVar21 = *(int *)(param_1 + 0x60) + *(int *)(iVar11 + 0x5c);
              local_2c = (float)iVar21;
              local_28 = (float)(iVar21 + *(int *)(iVar11 + 100));
              iVar21 = *(int *)(param_1 + 100) + *(int *)(iVar11 + 0x60);
              local_24 = (float)iVar21;
              local_20 = (float)(iVar21 + *(int *)(iVar11 + 0x68));
              *pfVar22 = local_2c;
              *local_234 = local_20;
              *pfVar19 = 0.0;
              *local_1ec = local_2c;
              *local_1e8 = local_24;
              *local_1e4 = 0.0;
              *local_1e0 = local_28;
              *local_1dc = local_24;
              *local_1d8 = 0.0;
              *local_1d4 = local_28;
              *local_1d0 = local_20;
              local_64 = local_64 + 0xc;
              pfVar22 = pfVar22 + 0xc;
              local_234 = local_234 + 0xc;
              pfVar19 = pfVar19 + 0xc;
              local_1ec = local_1ec + 0xc;
              local_1e8 = local_1e8 + 0xc;
              local_1e4 = local_1e4 + 0xc;
              local_1e0 = local_1e0 + 0xc;
              local_1dc = local_1dc + 0xc;
              local_1d8 = local_1d8 + 0xc;
              local_1d4 = local_1d4 + 0xc;
              local_1d0 = local_1d0 + 0xc;
              local_1cc = local_1cc + 0xc;
              *local_1cc = 0.0;
              local_18c = local_18c + 1;
              iVar11 = iVar11 + 0x10;
            } while (local_194 + iVar18 != local_18c);
          }
          local_68[local_64] = 0x1393;
          local_68[local_64 + 1] = 10;
          local_68[local_64 + 2] = 0x5c8;
          local_68[local_64 + 3] = 0x20000;
          local_19c = local_68 + local_64 + 4;
          local_198 = local_198 - (local_64 + 4);
          uVar12 = *(uint *)(param_5 + 0x58);
          local_194 = uVar6;
        } while (uVar6 < uVar12);
      }
      *(undefined4 **)(param_1 + 0x80) = local_19c;
      return 0;
    }
  }
  else {
    iVar10 = *(int *)(param_1 + 0x18);
    uVar12 = *(int *)(iVar10 + 0x10) - 7;
    param_3 = param_3 & 0xc000;
    uVar2 = *(uint *)(param_5 + 0x14);
    local_17c = *(dword **)(param_1 + 0x80);
    if ((local_17c != (dword *)0x0) &&
       ((cVar4 = ((int (*)())_createOffscreenBuffer)(), cVar4 != '\0' &&
        (cVar4 = ((int (*)())_createTextureBuffer)(*(int *)(param_1 + 0x70) == 3), cVar4 != '\0')))) {
      iVar11 = *(int *)(unaff_EBX + 0x513d);
      if ((param_4 & 0x7ffff000) == 0x6000) {
        ((int (*)())_fillTextureWithPattern)(param_6);
      }
      else {
        ((int (*)())_fillTextureWithPattern)(*(undefined4 *)(param_5 + 4));
      }
      local_54 = uVar12 - ((int)local_17c - (iVar10 + 0x20) >> 2);
      if (*(int *)(param_5 + 0x58) != 0) {
        local_174 = 0;
        local_1c8 = param_5;
        uVar5 = param_3 >> 0xe & 1;
        do {
          uVar13 = *(int *)(param_1 + 0x60) + *(int *)(local_1c8 + 0x5c);
          uVar14 = uVar13 + *(int *)(local_1c8 + 100);
          uVar6 = *(int *)(param_1 + 100) + *(int *)(local_1c8 + 0x60);
          uVar7 = uVar6 + *(int *)(local_1c8 + 0x68);
          local_158 = uVar6 + 8;
          if (uVar7 <= uVar6 + 8) {
            local_158 = uVar7;
          }
          fVar29 = (float)(*(int *)(param_5 + 8) + (uVar13 & 7));
          fVar28 = (float)(*(int *)(param_5 + 0xc) + (uVar6 & 7));
          if (uVar6 < uVar7) {
            uVar8 = uVar13 + 8;
            uVar9 = uVar8;
            if (uVar14 <= uVar8) {
              uVar9 = uVar14;
            }
            bVar23 = true;
            local_15c = uVar6;
            do {
              if (uVar13 < uVar14) {
                local_154 = uVar8;
                local_50 = uVar9;
                local_58 = uVar13;
                if (!bVar23) {
                  fVar24 = (float)local_15c;
                  fVar26 = (float)local_158;
                  goto LAB_000097a6;
                }
                if (local_54 < 0xd4) {
                  local_40 = 0.0;
                  local_3c = *(float *)(param_1 + 0x18);
                  if (*(int *)(param_1 + 0x8c) == 0) {
                    *local_17c = 0x5c8;
                    local_40 = 2.8026e-45;
                    local_17c[1] = 0xc000;
                    *(undefined4 *)(param_1 + 0x94) = 0;
                  }
                  local_17c[(int)local_40] = 0x1000000;
                  puVar3 = *(uint **)(param_1 + 0x7c);
                  *puVar3 = *puVar3 | ((int)local_17c - (int)puVar3 >> 2) + (int)local_40;
                  iVar10 = _IOConnectMapMemory(*(undefined4 *)(param_1 + 0xc),0,
                                               **(undefined4 **)(unaff_EBX + 0x5ac5),&local_3c,
                                               &local_40,1);
                  if (iVar10 == 0) {
                    *(undefined4 *)((int)local_3c + 0x1c) = 0;
                    *(int *)(param_1 + 0x7c) = (int)local_3c + 0x1c;
                    *(float *)(param_1 + 0x18) = local_3c;
                    local_17c = (dword *)((int)local_3c + 0x20);
                    local_e4 = (dword *)((int)local_3c + 0x24);
                    pdVar20 = (dword *)((int)local_3c + 0x28);
                    local_e0 = (dword *)((int)local_3c + 0x2c);
                    local_dc = (dword *)((int)local_3c + 0x30);
                    pdVar17 = (dword *)((int)local_3c + 0x34);
                    pdVar15 = (dword *)((int)local_3c + 0x38);
                    local_54 = uVar12;
                  }
                  else {
                    *(undefined4 *)(param_1 + 0x18) = 0;
                    *(undefined4 *)(param_1 + 0x7c) = 0;
                    local_17c = (dword *)0x0;
                    local_e4 = &__mh_bundle_header.cputype;
                    pdVar20 = &__mh_bundle_header.cpusubtype;
                    local_e0 = &__mh_bundle_header.filetype;
                    local_dc = &__mh_bundle_header.ncmds;
                    pdVar17 = &__mh_bundle_header.sizeofcmds;
                    pdVar15 = &__mh_bundle_header.flags;
                    local_54 = uVar12;
                  }
                }
                else {
                  local_e4 = local_17c + 1;
                  pdVar20 = local_17c + 2;
                  local_e0 = local_17c + 3;
                  local_dc = local_17c + 4;
                  pdVar17 = local_17c + 5;
                  pdVar15 = local_17c + 6;
                }
LAB_000088a1:
                puVar3 = *(uint **)(param_1 + 0x7c);
                *puVar3 = *puVar3 | (int)local_17c - (int)puVar3 >> 2;
                *(dword **)(param_1 + 0x7c) = local_17c;
                *local_17c = 0xa000000;
                *local_e4 = *(dword *)(param_1 + 0x84);
                puVar3 = *(uint **)(param_1 + 0x7c);
                *puVar3 = *puVar3 | (int)pdVar20 - (int)puVar3 >> 2;
                *(dword **)(param_1 + 0x7c) = pdVar20;
                *pdVar20 = 0x10000000;
                *local_e0 = *(dword *)**(undefined4 **)(unaff_EBX + 0x50bd);
                *local_dc = *(dword *)(*(int *)(unaff_EBX + 0x50bd) + 0x1c);
                *pdVar17 = (uint)(*(int *)(unaff_EBX + 0x5099) != 0x10) * 3 + 3;
                puVar3 = *(uint **)(param_1 + 0x7c);
                *puVar3 = *puVar3 | (int)pdVar15 - (int)puVar3 >> 2;
                *(dword **)(param_1 + 0x7c) = pdVar15;
                *pdVar15 = 0x13000000;
                pdVar15[1] = *(undefined4 *)**(undefined4 **)(unaff_EBX + 0x513d);
                pdVar15[2] = 0;
                local_17c = pdVar15 + 4;
                pdVar15[3] = 0;
                local_54 = local_54 - 10;
                bVar23 = *(int *)(param_1 + 0x70) == 3;
                uVar16 = (uint)bVar23;
                pdVar15[4] = 0x850;
                pdVar15[5] = 0x100;
                pdVar15[6] = 0x887;
                pdVar15[7] = 0x1c000;
                pdVar15[8] = 0x82c;
                pdVar15[9] = 0;
                pdVar15[10] = 0x1002;
                pdVar15[0xb] = 0;
                pdVar15[0xc] = 0x824;
                pdVar15[0xd] = 1;
                pdVar15[0xe] = 0x825;
                pdVar15[0xf] = 0x12;
                pdVar15[0x10] = 0x82d;
                pdVar15[0x11] = 5;
                pdVar15[0x12] = 0x854;
                pdVar15[0x13] = 0x6010006;
                pdVar15[0x14] = 0x855;
                pdVar15[0x15] = 0x2701;
                pdVar15[0x16] = 0x878;
                pdVar15[0x17] = 0xf688f688;
                pdVar15[0x18] = 0x879;
                pdVar15[0x19] = 0xfb24f688;
                pdVar15[0x1a] = (dword)((unsigned char *)0x000010a2);
                pdVar15[0x1b] = 0;
                pdVar15[0x1c] = 0x1381;
                pdVar15[0x1d] = 0;
                pdVar15[0x1e] = (dword)((unsigned char *)0x0000109e);
                pdVar15[0x1f] = 5;
                pdVar15[0x20] = 0x1383;
                pdVar15[0x21] = 0xf;
                pdVar15[0x22] = 0x1004;
                pdVar15[0x23] = 0x66666666;
                pdVar15[0x24] = 0x1005;
                pdVar15[0x25] = 0x66666666;
                pdVar15[0x26] = (dword)((unsigned char *)0x000010ae);
                pdVar15[0x27] = 0;
                pdVar15[0x28] = 0x10ea;
                pdVar15[0x29] = 0x2da49525;
                pdVar15[0x2a] = 0x10fa;
                pdVar15[0x2b] = 0xffffff;
                pdVar15[0x2c] = 0x10f4;
                pdVar15[0x2d] = 0xffff;
                pdVar15[0x2e] = 0x10f8;
                pdVar15[0x2f] = 0;
                pdVar15[0x30] = 0x10f9;
                pdVar15[0x31] =
                     *(uint *)(param_1 + 0x54) & 0x1fff |
                     (*(uint *)(param_1 + 0x58) & 0x1fff) << 0xd;
                pdVar15[0x32] = 0x13c0;
                pdVar15[0x33] = 0;
                pdVar15[0x34] = 0x13c1;
                pdVar15[0x35] = 0;
                pdVar15[0x36] = (dword)((unsigned char *)0x000010c0);
                pdVar15[0x37] = 0x40004;
                pdVar15[0x38] = (dword)((unsigned char *)0x000010c1);
                pdVar15[0x39] = 1;
                pdVar15[0x3a] = (dword)((unsigned char *)0x000010c8);
                pdVar15[0x3b] = 0x10;
                pdVar15[0x3c] = (dword)((unsigned char *)0x000010c9);
                pdVar15[0x3d] = 0x31;
                pdVar15[0x3e] = 0x101d;
                pdVar15[0x3f] = 0x28ffe040;
                pdVar15[0x40] = 0x101e;
                pdVar15[0x41] = 0x28ffe0c2;
                pdVar15[0x42] = 0x1041;
                pdVar15[0x43] = 3;
                pdVar15[0x44] = 0x1040;
                pdVar15[0x45] = 0;
                pdVar15[0x46] = 0x1100;
                pdVar15[0x47] = 0x2a92;
                pdVar15[0x48] = 0x1101;
                pdVar15[0x49] = 0x10002a92;
                pdVar15[0x4a] = 0x1120;
                pdVar15[0x4b] =
                     (int)*(short *)(param_1 + 0x50) - 1U & 0x7ff |
                     ((int)*(short *)(param_1 + 0x52) - 1U & 0x7ff) << 0xb | 0x80000000;
                pdVar15[0x4c] = 0x1121;
                pdVar15[0x4d] =
                     (int)*(short *)(iVar11 + 0x10) - 1U & 0x7ff |
                     ((int)*(short *)(iVar11 + 0x12) - 1U & 0x7ff) << 0xb | 0x80000000;
                pdVar15[0x4e] = 0x1130;
                pdVar15[0x4f] = ((int)(uVar16 << 0x1f) >> 0x1f) + 0x5300c;
                pdVar15[0x50] = 0x1131;
                pdVar15[0x51] = ((int)(uVar16 << 0x1f) >> 0x1f) + 0x5300c;
                pdVar15[0x52] = 0x1140;
                pdVar15[0x53] =
                     *(int *)(param_1 + 0x5c) - 1U & 0x3fff |
                     ((int)*(short *)(param_1 + 0x50) - 1U & 0x800) << 4 |
                     ((int)*(short *)(param_1 + 0x52) - 1U & 0x800) << 5;
                pdVar15[0x54] = 0x1141;
                pdVar15[0x55] =
                     *(int *)(iVar11 + 0x1c) - 1U & 0x3fff |
                     ((int)*(short *)(iVar11 + 0x10) - 1U & 0x800) << 4 |
                     ((int)*(short *)(iVar11 + 0x12) - 1U & 0x800) << 5;
                if (param_3 == 0) {
                  iVar21 = 0x52;
                  iVar10 = 0x148;
                  local_d8 = 0x53;
                  local_d4 = 0x54;
                  local_d0 = 0x55;
                  local_cc = 0x56;
                  local_c8 = 0x57;
                  local_c4 = 0x58;
                  local_c0 = 0x59;
                  local_bc = 0x5a;
                  local_b8 = 0x5b;
                  local_b4 = 0x5c;
                  local_b0 = 0x5d;
                  local_ac = 0x5e;
                  local_a8 = 0x5f;
                  local_a4 = 0x60;
                  local_a0 = 0x61;
                  local_9c = 0x62;
                  local_98 = 99;
                  local_94 = 100;
                  local_90 = 0x65;
                  local_8c = 0x66;
                  local_88 = 0x67;
                  local_84 = 0x68;
                  local_80 = 0x69;
                  iVar18 = 0x6a;
                  local_234 = (float *)0x6b;
                  local_e8 = 0x6c;
                }
                else {
                  if (bVar23) {
                    fVar24 = (float)((uVar2 & 0x8000) >> 0xf);
                    fVar26 = *(float *)(unaff_EBX + 0x49c9);
                    fVar27 = (float)((uVar2 & 0x7c00) >> 10) / fVar26;
                    fVar25 = (float)((uVar2 & 0x3e0) >> 5) / fVar26;
                    uVar16 = uVar2 & 0x1f;
                  }
                  else {
                    fVar26 = *(float *)(unaff_EBX + 0x49cd);
                    fVar24 = (float)(uVar2 >> 0x18) / fVar26;
                    fVar27 = (float)((uVar2 & 0xff0000) >> 0x10) / fVar26;
                    fVar25 = (float)((uVar2 & 0xff00) >> 8) / fVar26;
                    uVar16 = uVar2 & 0xff;
                  }
                  pdVar15[0x56] = 0x1094;
                  pdVar15[0x57] = 0x10000;
                  pdVar15[0x58] = 0x1095;
                  pdVar15[0x59] = (dword)fVar27;
                  pdVar15[0x5a] = 0x1095;
                  pdVar15[0x5b] = (dword)fVar25;
                  pdVar15[0x5c] = 0x1095;
                  pdVar15[0x5d] = (dword)((float)uVar16 / fVar26);
                  pdVar15[0x5e] = 0x1095;
                  pdVar15[0x5f] = (dword)fVar24;
                  iVar21 = 0x5c;
                  iVar10 = 0x170;
                  local_d8 = 0x5d;
                  local_d4 = 0x5e;
                  local_d0 = 0x5f;
                  local_cc = 0x60;
                  local_c8 = 0x61;
                  local_c4 = 0x62;
                  local_c0 = 99;
                  local_bc = 100;
                  local_b8 = 0x65;
                  local_b4 = 0x66;
                  local_b0 = 0x67;
                  local_ac = 0x68;
                  local_a8 = 0x69;
                  local_a4 = 0x6a;
                  local_a0 = 0x6b;
                  local_9c = 0x6c;
                  local_98 = 0x6d;
                  local_94 = 0x6e;
                  local_90 = 0x6f;
                  local_8c = 0x70;
                  local_88 = 0x71;
                  local_84 = 0x72;
                  local_80 = 0x73;
                  iVar18 = 0x74;
                  local_234 = (float *)0x75;
                  local_e8 = 0x76;
                }
                *(undefined4 *)(iVar10 + (int)local_17c) = 0x1094;
                local_17c[local_d8] = 0;
                local_17c[local_d4] = 0x1095;
                local_17c[local_d0] = 0x7803;
                local_17c[local_cc] = 0x1095;
                local_17c[local_c8] = 0x2410000;
                local_17c[local_c4] = 0x1095;
                local_17c[local_c0] = 0x3901e401;
                local_17c[local_bc] = 0x1095;
                local_17c[local_b8] = 0;
                local_17c[local_b4] = 0x1095;
                local_17c[local_b0] = 0;
                local_17c[local_ac] = 0x1095;
                local_17c[local_a8] = 0;
                if (param_3 == 0) {
                  local_17c[local_a4] = 0x1095;
                  local_17c[local_a0] = 0x78105;
                  local_17c[local_9c] = 0x1095;
                  local_17c[local_98] = 1;
                  local_17c[local_94] = 0x1095;
                  local_17c[local_90] = 1;
                  local_17c[local_8c] = 0x1095;
                  local_17c[local_88] = 0xdb0220;
                  local_17c[local_84] = 0x1095;
                  local_17c[local_80] = 0xc0c006;
                  local_17c[iVar18] = 0x1095;
                  local_17c[(int)local_234] = 0x20490000;
                }
                else {
                  local_17c[local_a4] = 0x1095;
                  local_17c[local_a0] = 0x7807;
                  local_17c[local_9c] = 0x1095;
                  local_17c[local_98] = 0x2400000;
                  local_17c[local_94] = 0x1095;
                  local_17c[local_90] = 0x3900e400;
                  local_17c[local_8c] = 0x1095;
                  local_17c[local_88] = 0;
                  local_17c[local_84] = 0x1095;
                  local_17c[local_80] = 0;
                  local_17c[iVar18] = 0x1095;
                  local_17c[(int)local_234] = 0;
                  local_17c[local_e8] = 0x1095;
                  pdVar15[iVar21 + 0x1f] = 0x7804;
                  pdVar15[iVar21 + 0x20] = 0x1095;
                  pdVar15[iVar21 + 0x21] = 0x40040000;
                  pdVar15[iVar21 + 0x22] = 0x1095;
                  pdVar15[iVar21 + 0x23] = 0x40040000;
                  pdVar15[iVar21 + 0x24] = 0x1095;
                  pdVar15[iVar21 + 0x25] = 0xdb0490;
                  pdVar15[iVar21 + 0x26] = 0x1095;
                  pdVar15[iVar21 + 0x27] = 0xc10026;
                  pdVar15[iVar21 + 0x28] = 0x1095;
                  pdVar15[iVar21 + 0x29] = 0xdfa23028;
                  pdVar15[iVar21 + 0x2a] = 0x1095;
                  pdVar15[iVar21 + 0x2b] = 0x7800;
                  pdVar15[iVar21 + 0x2c] = 0x1095;
                  pdVar15[iVar21 + 0x2d] = 2;
                  pdVar15[iVar21 + 0x2e] = 0x1095;
                  pdVar15[iVar21 + 0x2f] = 2;
                  pdVar15[iVar21 + 0x30] = 0x1095;
                  pdVar15[iVar21 + 0x31] = 0xdb0220;
                  pdVar15[iVar21 + 0x32] = 0x1095;
                  pdVar15[iVar21 + 0x33] = 0xc0c021;
                  pdVar15[iVar21 + 0x34] = 0x1095;
                  pdVar15[iVar21 + 0x35] = 0x22;
                  pdVar15[iVar21 + 0x36] = 0x1095;
                  pdVar15[iVar21 + 0x37] = 0x78101;
                  pdVar15[iVar21 + 0x38] = 0x1095;
                  local_204 = (char)uVar5;
                  pdVar15[iVar21 + 0x39] = -(uint)(local_204 == '\0') & 0x400 | uVar5 | 0x200000;
                  pdVar15[iVar21 + 0x3a] = 0x1095;
                  pdVar15[iVar21 + 0x3b] = -(uint)(local_204 == '\0') & 0x400 | uVar5 | 0x200000;
                  pdVar15[iVar21 + 0x3c] = 0x1095;
                  pdVar15[iVar21 + 0x3d] = 0x440221;
                  pdVar15[iVar21 + 0x3e] = 0x1095;
                  pdVar15[iVar21 + 0x3f] = 0x60d006;
                  pdVar15[iVar21 + 0x40] = 0x1095;
                  local_e8 = iVar21 + 0x3e;
                  pdVar15[iVar21 + 0x41] = 0xdda22008;
                }
                local_17c[local_e8] = 0x1189;
                pdVar15[local_e8 + 5] = 0;
                pdVar15[local_e8 + 6] = 0x1181;
                pdVar15[local_e8 + 7] = 5;
                pdVar15[local_e8 + 8] = 0x118d;
                pdVar15[local_e8 + 9] = (-(uint)(param_3 == 0) & 0xfffd0000) + 0x40000;
                pdVar15[local_e8 + 10] = 0x118e;
                pdVar15[local_e8 + 0xb] = 0;
                pdVar15[local_e8 + 0xc] = 0x118c;
                pdVar15[local_e8 + 0xd] = (-(uint)(param_3 == 0) & 0xfffd0000) + 0x40000;
                pdVar15[local_e8 + 0xe] = 0x11a9;
                pdVar15[local_e8 + 0xf] = 0x1b01;
                pdVar15[local_e8 + 0x10] = 0x11aa;
                pdVar15[local_e8 + 0x11] = 0xf;
                pdVar15[local_e8 + 0x12] = 0x11ab;
                pdVar15[local_e8 + 0x13] = 0xf;
                pdVar15[local_e8 + 0x14] = 0x11ac;
                pdVar15[local_e8 + 0x15] = 0xf;
                pdVar15[local_e8 + 0x16] = 0x12f0;
                pdVar15[local_e8 + 0x17] = 0;
                pdVar15[local_e8 + 0x18] = 0x12f5;
                pdVar15[local_e8 + 0x19] = 0;
                local_14c = local_e8 * 4 + 0x58;
                iVar10 = local_e8 + 0x17;
                local_148 = local_e8 + 0x18;
                local_144 = local_e8 + 0x19;
                local_140 = local_e8 + 0x1a;
                local_13c = local_e8 + 0x1b;
                local_138 = local_e8 + 0x1c;
                local_134 = local_e8 + 0x1d;
                local_130 = local_e8 + 0x1e;
                local_12c = local_e8 + 0x1f;
                local_128 = local_e8 + 0x20;
                local_124 = local_e8 + 0x21;
                local_120 = local_e8 + 0x22;
                local_11c = local_e8 + 0x23;
                local_118 = local_e8 + 0x24;
                local_114 = local_e8 + 0x25;
                local_110 = local_e8 + 0x26;
                local_10c = local_e8 + 0x27;
                local_108 = local_e8 + 0x28;
                local_104 = local_e8 + 0x29;
                local_100 = local_e8 + 0x2a;
                local_fc = local_e8 + 0x2b;
                local_f8 = local_e8 + 0x2c;
                local_f4 = local_e8 + 0x2d;
                local_f0 = local_e8 + 0x2e;
                local_ec = local_e8 + 0x2f;
                local_e8 = local_e8 + 0x30;
                fVar24 = (float)local_15c;
                fVar26 = (float)local_158;
                do {
                  local_7c = local_158 << 0x10;
                  fVar25 = *(float *)(unaff_EBX + 0x49d5);
                  local_24 = fVar25 / (float)(int)*(short *)(param_1 + 0x50);
                  local_20 = local_24 * (float)local_58;
                  local_24 = local_24 * (float)local_50;
                  local_2c = fVar25 / (float)(int)*(short *)(param_1 + 0x52);
                  local_28 = local_2c * fVar24;
                  local_2c = local_2c * fVar26;
                  *(undefined4 *)(local_14c + (int)local_17c) = 0xc0143500;
                  local_17c[iVar10] = 0x4003d;
                  if (local_50 - local_58 == 8) {
                    uVar16 = local_158 - local_15c;
                    if (uVar16 != 8) goto LAB_000094cb;
                    pfVar19 = (float *)(unaff_EBX + 0x49d5);
                    local_30 = (fVar29 + 0.0) * (*pfVar19 / (float)(int)*(short *)(iVar11 + 0x10));
                    local_34 = (fVar29 + *(float *)(unaff_EBX + 0x49dd)) *
                               (*pfVar19 / (float)(int)*(short *)(iVar11 + 0x10));
                    local_38 = (fVar28 + 0.0) * (*pfVar19 / (float)(int)*(short *)(iVar11 + 0x12));
                    local_44 = (*(float *)(unaff_EBX + 0x49dd) + fVar28) *
                               (*pfVar19 / (float)(int)*(short *)(iVar11 + 0x12));
                  }
                  else {
                    uVar16 = local_158 - local_15c;
LAB_000094cb:
                    local_30 = (fVar29 + 0.0) * (fVar25 / (float)(int)*(short *)(iVar11 + 0x10));
                    local_34 = ((float)(local_50 - local_58) + fVar29) *
                               (fVar25 / (float)(int)*(short *)(iVar11 + 0x10));
                    local_38 = (fVar28 + 0.0) * (fVar25 / (float)(int)*(short *)(iVar11 + 0x12));
                    local_44 = ((float)uVar16 + fVar28) *
                               (fVar25 / (float)(int)*(short *)(iVar11 + 0x12));
                  }
                  local_17c[local_148] = local_58 | local_7c;
                  local_17c[local_144] = (dword)local_20;
                  local_17c[local_140] = (dword)local_2c;
                  local_17c[local_13c] = (dword)local_30;
                  local_17c[local_138] = (dword)local_44;
                  local_17c[local_134] = local_58 | local_15c << 0x10;
                  local_17c[local_130] = (dword)local_20;
                  local_17c[local_12c] = (dword)local_28;
                  local_17c[local_128] = (dword)local_30;
                  local_17c[local_124] = (dword)local_38;
                  local_17c[local_120] = local_50 | local_15c << 0x10;
                  local_17c[local_11c] = (dword)local_24;
                  local_17c[local_118] = (dword)local_28;
                  local_17c[local_114] = (dword)local_34;
                  local_17c[local_110] = (dword)local_38;
                  local_17c[local_10c] = local_50 | local_7c;
                  local_17c[local_108] = (dword)local_24;
                  local_17c[local_104] = (dword)local_2c;
                  local_17c[local_100] = (dword)local_34;
                  local_17c[local_fc] = (dword)local_44;
                  local_17c[local_f8] = 0x1393;
                  local_17c[local_f4] = 10;
                  local_17c[local_f0] = 0x5c8;
                  local_17c[local_ec] = 0x20000;
                  local_54 = local_54 - local_e8;
                  local_17c = local_17c + local_e8;
                  local_50 = local_58 + 0x10;
                  if (uVar14 <= local_58 + 0x10) {
                    local_50 = uVar14;
                  }
                  if (uVar14 <= local_154) {
                    bVar23 = false;
                    break;
                  }
                  local_58 = local_154;
                  local_154 = local_154 + 8;
LAB_000097a6:
                  if (local_54 < 0x1a) goto LAB_0000a982;
                  local_e8 = 0x1a;
                  local_ec = 0x19;
                  local_f0 = 0x18;
                  local_f4 = 0x17;
                  local_f8 = 0x16;
                  local_fc = 0x15;
                  local_100 = 0x14;
                  local_104 = 0x13;
                  local_108 = 0x12;
                  local_10c = 0x11;
                  local_110 = 0x10;
                  local_114 = 0xf;
                  local_118 = 0xe;
                  local_11c = 0xd;
                  local_120 = 0xc;
                  local_124 = 0xb;
                  local_128 = 10;
                  local_12c = 9;
                  local_130 = 8;
                  local_134 = 7;
                  local_138 = 6;
                  local_13c = 5;
                  local_140 = 4;
                  local_144 = 3;
                  local_148 = 2;
                  iVar10 = 1;
                  local_14c = 0;
                } while( true );
              }
              uVar16 = local_15c + 8;
              local_158 = local_15c + 0x10;
              if (uVar7 <= local_15c + 0x10) {
                local_158 = uVar7;
              }
              local_15c = uVar16;
            } while (uVar16 < uVar7);
          }
          if (local_54 < 0x86) {
            local_40 = 0.0;
            local_3c = *(float *)(param_1 + 0x18);
            if (*(int *)(param_1 + 0x8c) == 0) {
              *local_17c = 0x5c8;
              local_40 = 2.8026e-45;
              local_17c[1] = 0xc000;
              *(undefined4 *)(param_1 + 0x94) = 0;
            }
            local_17c[(int)local_40] = 0x1000000;
            puVar3 = *(uint **)(param_1 + 0x7c);
            *puVar3 = *puVar3 | ((int)local_17c - (int)puVar3 >> 2) + (int)local_40;
            iVar10 = _IOConnectMapMemory(*(undefined4 *)(param_1 + 0xc),0,
                                         **(undefined4 **)(unaff_EBX + 0x5ac5),&local_3c,&local_40,1
                                        );
            if (iVar10 == 0) {
              *(undefined4 *)((int)local_3c + 0x1c) = 0;
              *(int *)(param_1 + 0x7c) = (int)local_3c + 0x1c;
              *(float *)(param_1 + 0x18) = local_3c;
              local_17c = (dword *)((int)local_3c + 0x20);
              local_78 = (dword *)((int)local_3c + 0x24);
              local_74 = (dword *)((int)local_3c + 0x28);
              pdVar20 = (dword *)((int)local_3c + 0x2c);
              pdVar17 = (dword *)((int)local_3c + 0x30);
              pdVar15 = (dword *)((int)local_3c + 0x34);
              local_70 = (dword *)((int)local_3c + 0x38);
              local_54 = uVar12;
            }
            else {
              *(undefined4 *)(param_1 + 0x18) = 0;
              *(undefined4 *)(param_1 + 0x7c) = 0;
              local_17c = (dword *)0x0;
              local_78 = &__mh_bundle_header.cputype;
              local_74 = &__mh_bundle_header.cpusubtype;
              pdVar20 = &__mh_bundle_header.filetype;
              pdVar17 = &__mh_bundle_header.ncmds;
              pdVar15 = &__mh_bundle_header.sizeofcmds;
              local_70 = &__mh_bundle_header.flags;
              local_54 = uVar12;
            }
          }
          else {
            local_78 = local_17c + 1;
            local_74 = local_17c + 2;
            pdVar20 = local_17c + 3;
            pdVar17 = local_17c + 4;
            pdVar15 = local_17c + 5;
            local_70 = local_17c + 6;
          }
          puVar3 = *(uint **)(param_1 + 0x7c);
          *puVar3 = *puVar3 | (int)local_17c - (int)puVar3 >> 2;
          *(dword **)(param_1 + 0x7c) = local_17c;
          *local_17c = 0x11000000;
          *local_78 = *(dword *)(param_1 + 0x84);
          *local_74 = 0;
          *pdVar20 = 0;
          puVar3 = *(uint **)(param_1 + 0x7c);
          *puVar3 = *puVar3 | (int)pdVar17 - (int)puVar3 >> 2;
          *(dword **)(param_1 + 0x7c) = pdVar17;
          *pdVar17 = 0x4000000;
          *pdVar15 = *(dword *)**(undefined4 **)(unaff_EBX + 0x50bd);
          iVar10 = *(int *)(unaff_EBX + 0x50bd);
          iVar18 = *(int *)(iVar10 + 0x30);
          if (iVar18 == 3) {
            iVar18 = 0xb;
          }
          else if (iVar18 == 6) {
            iVar18 = 0xc;
          }
          iVar18 = ((int (*)())_radeon3DCopySetup)(iVar18,0,0,0,0);
          local_70[iVar18] = 0xc00c3500;
          local_70[iVar18 + 1] = 0x4003d;
          dVar1 = *(double *)(unaff_EBX + 0x4a25);
          local_2c = (float)((double)uVar13 * (dVar1 / (double)(int)*(short *)(iVar10 + 0x10)));
          local_44 = (float)((double)uVar14 * (dVar1 / (double)(int)*(short *)(iVar10 + 0x10)));
          local_40 = (float)((double)uVar6 * (dVar1 / (double)(int)*(short *)(iVar10 + 0x12)));
          local_3c = (float)((double)uVar7 * (dVar1 / (double)(int)*(short *)(iVar10 + 0x12)));
          local_70[iVar18 + 2] = uVar13 | uVar7 * 0x10000;
          local_70[iVar18 + 3] = (dword)local_2c;
          local_70[iVar18 + 4] = (dword)local_3c;
          local_70[iVar18 + 5] = uVar13 | uVar6 * 0x10000;
          local_70[iVar18 + 6] = (dword)local_2c;
          local_70[iVar18 + 7] = (dword)local_40;
          local_70[iVar18 + 8] = uVar6 * 0x10000 | uVar14;
          local_70[iVar18 + 9] = (dword)local_44;
          local_70[iVar18 + 10] = (dword)local_40;
          local_70[iVar18 + 0xb] = uVar14 | uVar7 * 0x10000;
          local_70[iVar18 + 0xc] = (dword)local_44;
          local_70[iVar18 + 0xd] = (dword)local_3c;
          local_70[iVar18 + 0xe] = 0x1393;
          local_70[iVar18 + 0xf] = 10;
          local_70[iVar18 + 0x10] = 0x5c8;
          local_70[iVar18 + 0x11] = 0x20000;
          local_54 = (local_54 - 6) - (iVar18 + 0x12);
          local_17c = local_70 + iVar18 + 0x12;
          local_174 = local_174 + 1;
          local_1c8 = local_1c8 + 0x10;
        } while (local_174 < *(uint *)(param_5 + 0x58));
      }
      *(dword **)(param_1 + 0x80) = local_17c;
      return 0;
    }
  }
  return 0xe00002be;
LAB_0000a982:
  local_3c = 0.0;
  local_40 = *(float *)(param_1 + 0x18);
  if (*(int *)(param_1 + 0x8c) == 0) {
    *local_17c = 0x5c8;
    local_3c = 2.8026e-45;
    local_17c[1] = 0xc000;
    *(undefined4 *)(param_1 + 0x94) = 0;
  }
  local_17c[(int)local_3c] = 0x1000000;
  puVar3 = *(uint **)(param_1 + 0x7c);
  *puVar3 = *puVar3 | ((int)local_17c - (int)puVar3 >> 2) + (int)local_3c;
  iVar10 = _IOConnectMapMemory(*(undefined4 *)(param_1 + 0xc),0,
                               **(undefined4 **)(unaff_EBX + 0x5ac5),&local_40,&local_3c,1);
  if (iVar10 == 0) {
    *(undefined4 *)((int)local_40 + 0x1c) = 0;
    *(int *)(param_1 + 0x7c) = (int)local_40 + 0x1c;
    *(float *)(param_1 + 0x18) = local_40;
    local_17c = (dword *)((int)local_40 + 0x20);
    local_e4 = (dword *)((int)local_40 + 0x24);
    pdVar20 = (dword *)((int)local_40 + 0x28);
    local_e0 = (dword *)((int)local_40 + 0x2c);
    local_dc = (dword *)((int)local_40 + 0x30);
    pdVar17 = (dword *)((int)local_40 + 0x34);
    pdVar15 = (dword *)((int)local_40 + 0x38);
    local_154 = local_58 + 8;
    local_54 = uVar12;
  }
  else {
    *(undefined4 *)(param_1 + 0x18) = 0;
    *(undefined4 *)(param_1 + 0x7c) = 0;
    pdVar15 = &__mh_bundle_header.flags;
    pdVar17 = &__mh_bundle_header.sizeofcmds;
    local_dc = &__mh_bundle_header.ncmds;
    local_e0 = &__mh_bundle_header.filetype;
    pdVar20 = &__mh_bundle_header.cpusubtype;
    local_e4 = &__mh_bundle_header.cputype;
    local_17c = (dword *)0x0;
    local_154 = local_58 + 8;
    local_54 = uVar12;
  }
  goto LAB_000088a1;
}

/* _radeonHighlight @ 0xac23 (5150 bytes) */
int _radeonHighlight(param_1)
  int param_1;
{
  double dVar1;
  uint uVar2;
  uint *puVar3;
  char cVar4;
  undefined4 uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  undefined4 *puVar14;
  int unaff_EBX;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  dword *pdVar18;
  dword *pdVar19;
  bool bVar20;
  float fVar21;
  float fVar22;
  float fVar23;
  float fVar24;
  uint *in_stack_00000014;
  uint in_stack_00000018;
  dword *local_d4;
  uint *local_c0;
  uint local_9c;
  uint local_94;
  dword *local_68;
  dword *local_64;
  dword *local_60;
  dword *local_5c;
  dword *local_58;
  dword *local_54;
  dword *local_50;
  dword *local_4c;
  dword *local_48;
  uint local_44;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  
  ((int (*)())___i686_get_pc_thunk_bx)();
  iVar7 = *(int *)(param_1 + 0x18);
  uVar10 = *(int *)(iVar7 + 0x10) - 7;
  pdVar19 = *(dword **)(param_1 + 0x80);
  if ((pdVar19 == (dword *)0x0) || (cVar4 = ((int (*)())_createOffscreenBuffer)(), cVar4 == '\0')) {
    uVar5 = 0xe00002be;
  }
  else {
    uVar2 = *in_stack_00000014;
    local_44 = uVar10 - ((int)pdVar19 - (iVar7 + 0x20) >> 2);
    if (in_stack_00000014[0x16] != 0) {
      local_94 = 0;
      local_c0 = in_stack_00000014;
      do {
        if (local_44 < 0xda) {
          local_2c = 0.0;
          local_30 = *(float *)(param_1 + 0x18);
          if (*(int *)(param_1 + 0x8c) == 0) {
            *pdVar19 = 0x5c8;
            local_2c = 2.8026e-45;
            pdVar19[1] = 0xc000;
            *(undefined4 *)(param_1 + 0x94) = 0;
          }
          pdVar19[(int)local_2c] = 0x1000000;
          puVar3 = *(uint **)(param_1 + 0x7c);
          *puVar3 = *puVar3 | ((int)pdVar19 - (int)puVar3 >> 2) + (int)local_2c;
          iVar7 = _IOConnectMapMemory(*(undefined4 *)(param_1 + 0xc),0,
                                      **(undefined4 **)(unaff_EBX + 0x345c),&local_30,&local_2c,1);
          local_44 = uVar10;
          if (iVar7 == 0) {
            *(undefined4 *)((int)local_30 + 0x1c) = 0;
            *(int *)(param_1 + 0x7c) = (int)local_30 + 0x1c;
            *(float *)(param_1 + 0x18) = local_30;
            pdVar19 = (dword *)((int)local_30 + 0x20);
            local_68 = (dword *)((int)local_30 + 0x24);
            local_d4 = (dword *)((int)local_30 + 0x28);
            local_64 = (dword *)((int)local_30 + 0x2c);
            local_60 = (dword *)((int)local_30 + 0x30);
            local_5c = (dword *)((int)local_30 + 0x34);
            pdVar18 = (dword *)((int)local_30 + 0x38);
          }
          else {
            *(undefined4 *)(param_1 + 0x18) = 0;
            *(undefined4 *)(param_1 + 0x7c) = 0;
            pdVar19 = (dword *)0x0;
            local_68 = &__mh_bundle_header.cputype;
            local_d4 = &__mh_bundle_header.cpusubtype;
            local_64 = &__mh_bundle_header.filetype;
            local_60 = &__mh_bundle_header.ncmds;
            local_5c = &__mh_bundle_header.sizeofcmds;
            pdVar18 = &__mh_bundle_header.flags;
          }
        }
        else {
          local_68 = pdVar19 + 1;
          local_d4 = pdVar19 + 2;
          local_64 = pdVar19 + 3;
          local_60 = pdVar19 + 4;
          local_5c = pdVar19 + 5;
          pdVar18 = pdVar19 + 6;
        }
        puVar3 = *(uint **)(param_1 + 0x7c);
        *puVar3 = *puVar3 | (int)pdVar19 - (int)puVar3 >> 2;
        *(dword **)(param_1 + 0x7c) = pdVar19;
        *pdVar19 = 0xa000000;
        *local_68 = *(dword *)(param_1 + 0x84);
        puVar3 = *(uint **)(param_1 + 0x7c);
        *puVar3 = *puVar3 | (int)local_d4 - (int)puVar3 >> 2;
        *(dword **)(param_1 + 0x7c) = local_d4;
        *local_d4 = 0x10000000;
        *local_64 = *(dword *)**(undefined4 **)(unaff_EBX + 0x2a54);
        *local_60 = *(dword *)(*(int *)(unaff_EBX + 0x2a54) + 0x1c);
        *local_5c = (uint)(*(int *)(unaff_EBX + 0x2a30) != 0x10) * 3 + 3;
        bVar20 = *(int *)(param_1 + 0x70) == 3;
        *pdVar18 = 0x850;
        pdVar18[1] = 0x100;
        pdVar18[2] = 0x887;
        pdVar18[3] = 0x1c000;
        pdVar18[4] = 0x82c;
        pdVar18[5] = 0;
        pdVar18[6] = 0x1002;
        pdVar18[7] = 0;
        pdVar18[8] = 0x824;
        pdVar18[9] = 1;
        pdVar18[10] = 0x825;
        pdVar18[0xb] = 2;
        pdVar18[0xc] = 0x82d;
        pdVar18[0xd] = 3;
        pdVar18[0xe] = 0x854;
        pdVar18[0xf] = 0x26010006;
        pdVar18[0x10] = 0x878;
        pdVar18[0x11] = 0xf688f688;
        pdVar18[0x12] = (dword)((unsigned char *)0x000010a2);
        pdVar18[0x13] = 0;
        pdVar18[0x14] = 0x1381;
        pdVar18[0x15] = 0;
        pdVar18[0x16] = (dword)((unsigned char *)0x0000109e);
        pdVar18[0x17] = 5;
        pdVar18[0x18] = 0x1383;
        pdVar18[0x19] = 0xf;
        pdVar18[0x1a] = 0x1004;
        pdVar18[0x1b] = 0x66666666;
        pdVar18[0x1c] = 0x1005;
        pdVar18[0x1d] = 0x66666666;
        pdVar18[0x1e] = (dword)((unsigned char *)0x000010ae);
        pdVar18[0x1f] = 0;
        pdVar18[0x20] = 0x10ea;
        pdVar18[0x21] = 0x2da49525;
        pdVar18[0x22] = 0x10fa;
        pdVar18[0x23] = 0xffffff;
        pdVar18[0x24] = 0x10f4;
        pdVar18[0x25] = 0xffff;
        pdVar18[0x26] = 0x10f8;
        pdVar18[0x27] = 0;
        pdVar18[0x28] = 0x10f9;
        pdVar18[0x29] =
             *(uint *)(param_1 + 0x54) & 0x1fff | (*(uint *)(param_1 + 0x58) & 0x1fff) << 0xd;
        pdVar18[0x2a] = 0x13c0;
        pdVar18[0x2b] = 0;
        pdVar18[0x2c] = 0x13c1;
        pdVar18[0x2d] = 0;
        pdVar18[0x2e] = (dword)((unsigned char *)0x000010c0);
        pdVar18[0x2f] = 0x40002;
        pdVar18[0x30] = (dword)((unsigned char *)0x000010c1);
        pdVar18[0x31] = 0;
        pdVar18[0x32] = (dword)((unsigned char *)0x000010c8);
        pdVar18[0x33] = 0x10;
        pdVar18[0x34] = 0x101d;
        pdVar18[0x35] = 0x280c2040;
        pdVar18[0x36] = 0x1041;
        pdVar18[0x37] = 1;
        pdVar18[0x38] = 0x1040;
        pdVar18[0x39] = 0;
        pdVar18[0x3a] = 0x1100;
        pdVar18[0x3b] = 0x2a92;
        pdVar18[0x3c] = 0x1120;
        pdVar18[0x3d] =
             (int)*(short *)(param_1 + 0x50) - 1U & 0x7ff |
             ((int)*(short *)(param_1 + 0x52) - 1U & 0x7ff) << 0xb | 0x80000000;
        pdVar18[0x3e] = 0x1130;
        pdVar18[0x3f] = ((int)((uint)bVar20 << 0x1f) >> 0x1f) + 0x5300c;
        pdVar18[0x40] = 0x1140;
        pdVar18[0x41] =
             *(int *)(param_1 + 0x5c) - 1U & 0x3fff |
             ((int)*(short *)(param_1 + 0x50) - 1U & 0x800) << 4 |
             ((int)*(short *)(param_1 + 0x52) - 1U & 0x800) << 5;
        if (bVar20) {
          fVar23 = (float)((in_stack_00000018 & 0x8000) >> 0xf);
          fVar22 = *(float *)(unaff_EBX + 0x2360);
          fVar24 = (float)((in_stack_00000018 & 0x7c00) >> 10) / fVar22;
          fVar21 = (float)((in_stack_00000018 & 0x3e0) >> 5) / fVar22;
          uVar6 = in_stack_00000018 & 0x1f;
        }
        else {
          fVar22 = *(float *)(unaff_EBX + 0x2364);
          fVar23 = (float)(in_stack_00000018 >> 0x18) / fVar22;
          fVar24 = (float)((in_stack_00000018 & 0xff0000) >> 0x10) / fVar22;
          fVar21 = (float)((in_stack_00000018 & 0xff00) >> 8) / fVar22;
          uVar6 = in_stack_00000018 & 0xff;
        }
        pdVar18[0x42] = 0x1094;
        pdVar18[0x43] = 0x10000;
        pdVar18[0x44] = 0x1095;
        pdVar18[0x45] = (dword)fVar24;
        pdVar18[0x46] = 0x1095;
        pdVar18[0x47] = (dword)fVar21;
        pdVar18[0x48] = 0x1095;
        pdVar18[0x49] = (dword)((float)uVar6 / fVar22);
        pdVar18[0x4a] = 0x1095;
        pdVar18[0x4b] = (dword)fVar23;
        if (bVar20) {
          fVar23 = (float)((uVar2 & 0x8000) >> 0xf);
          fVar22 = *(float *)(unaff_EBX + 0x2360);
          fVar24 = (float)((uVar2 & 0x7c00) >> 10) / fVar22;
          fVar21 = (float)((uVar2 & 0x3e0) >> 5) / fVar22;
          uVar6 = uVar2 & 0x1f;
        }
        else {
          fVar22 = *(float *)(unaff_EBX + 0x2364);
          fVar23 = (float)(uVar2 >> 0x18) / fVar22;
          fVar24 = (float)((uVar2 & 0xff0000) >> 0x10) / fVar22;
          fVar21 = (float)((uVar2 & 0xff00) >> 8) / fVar22;
          uVar6 = uVar2 & 0xff;
        }
        pdVar18[0x4c] = 0x1095;
        pdVar18[0x4d] = (dword)fVar24;
        pdVar18[0x4e] = 0x1095;
        pdVar18[0x4f] = (dword)fVar21;
        pdVar18[0x50] = 0x1095;
        pdVar18[0x51] = (dword)((float)uVar6 / fVar22);
        pdVar18[0x52] = 0x1095;
        pdVar18[0x53] = (dword)fVar23;
        pdVar18[0x54] = 0x1094;
        pdVar18[0x55] = 0;
        pdVar18[0x56] = 0x1095;
        pdVar18[0x57] = 0x7803;
        pdVar18[0x58] = 0x1095;
        pdVar18[0x59] = 0x2400000;
        pdVar18[0x5a] = 0x1095;
        pdVar18[0x5b] = 0x3900e400;
        pdVar18[0x5c] = 0x1095;
        pdVar18[0x5d] = 0;
        pdVar18[0x5e] = 0x1095;
        pdVar18[0x5f] = 0;
        pdVar18[0x60] = 0x1095;
        pdVar18[0x61] = 0;
        pdVar18[0x62] = 0x1095;
        pdVar18[99] = 0x7804;
        pdVar18[100] = 0x1095;
        pdVar18[0x65] = 0x40040000;
        pdVar18[0x66] = 0x1095;
        pdVar18[0x67] = 0x40040000;
        pdVar18[0x68] = 0x1095;
        pdVar18[0x69] = 0xdb0490;
        pdVar18[0x6a] = 0x1095;
        pdVar18[0x6b] = 0xc10016;
        pdVar18[0x6c] = 0x1095;
        pdVar18[0x6d] = 0xdfa23018;
        pdVar18[0x6e] = 0x1095;
        pdVar18[0x6f] = 0x7800;
        pdVar18[0x70] = 0x1095;
        pdVar18[0x71] = 1;
        pdVar18[0x72] = 0x1095;
        pdVar18[0x73] = 1;
        pdVar18[0x74] = 0x1095;
        pdVar18[0x75] = 0xdb0220;
        pdVar18[0x76] = 0x1095;
        pdVar18[0x77] = 0xc0c011;
        pdVar18[0x78] = 0x1095;
        pdVar18[0x79] = 0x12;
        pdVar18[0x7a] = 0x1095;
        pdVar18[0x7b] = 0x7800;
        pdVar18[0x7c] = 0x1095;
        pdVar18[0x7d] = 0x140400;
        pdVar18[0x7e] = 0x1095;
        pdVar18[0x7f] = 0x140400;
        pdVar18[0x80] = 0x1095;
        pdVar18[0x81] = 0x440221;
        pdVar18[0x82] = 0x1095;
        pdVar18[0x83] = 0x60d036;
        pdVar18[0x84] = 0x1095;
        pdVar18[0x85] = 0xdda22038;
        pdVar18[0x86] = 0x1095;
        pdVar18[0x87] = 0x7800;
        pdVar18[0x88] = 0x1095;
        pdVar18[0x89] = 0x40040400;
        pdVar18[0x8a] = 0x1095;
        pdVar18[0x8b] = 0x40040400;
        pdVar18[0x8c] = 0x1095;
        pdVar18[0x8d] = 0xdb0490;
        pdVar18[0x8e] = 0x1095;
        pdVar18[0x8f] = 0xc10016;
        pdVar18[0x90] = 0x1095;
        pdVar18[0x91] = 0xdfa23018;
        pdVar18[0x92] = 0x1095;
        pdVar18[0x93] = 0x7800;
        pdVar18[0x94] = 0x1095;
        pdVar18[0x95] = 1;
        pdVar18[0x96] = 0x1095;
        pdVar18[0x97] = 1;
        pdVar18[0x98] = 0x1095;
        pdVar18[0x99] = 0xdb0220;
        pdVar18[0x9a] = 0x1095;
        pdVar18[0x9b] = 0xc0c011;
        pdVar18[0x9c] = 0x1095;
        pdVar18[0x9d] = 0x12;
        pdVar18[0x9e] = 0x1095;
        pdVar18[0x9f] = 0x78101;
        pdVar18[0xa0] = 0x1095;
        pdVar18[0xa1] = 0x140003;
        pdVar18[0xa2] = 0x1095;
        pdVar18[0xa3] = 0x140003;
        pdVar18[0xa4] = 0x1095;
        pdVar18[0xa5] = 0x440221;
        pdVar18[0xa6] = 0x1095;
        pdVar18[0xa7] = 0x60d006;
        pdVar18[0xa8] = 0x1095;
        pdVar18[0xa9] = 0xdda22008;
        pdVar18[0xaa] = 0x1189;
        pdVar18[0xab] = 0;
        pdVar18[0xac] = 0x1181;
        pdVar18[0xad] = 5;
        pdVar18[0xae] = 0x118d;
        pdVar18[0xaf] = 0x60000;
        pdVar18[0xb0] = 0x118e;
        pdVar18[0xb1] = 0;
        pdVar18[0xb2] = 0x118c;
        pdVar18[0xb3] = 0x60000;
        pdVar18[0xb4] = 0x11a9;
        pdVar18[0xb5] = 0x1b01;
        pdVar18[0xb6] = 0x11aa;
        pdVar18[0xb7] = 0xf;
        pdVar18[0xb8] = 0x11ab;
        pdVar18[0xb9] = 0xf;
        pdVar18[0xba] = 0x11ac;
        pdVar18[0xbb] = 0xf;
        pdVar18[0xbc] = 0x12f0;
        pdVar18[0xbd] = 0;
        pdVar18[0xbe] = 0x12f5;
        pdVar18[0xbf] = 0;
        uVar8 = *(int *)(param_1 + 0x60) + local_c0[0x17];
        uVar15 = local_c0[0x19] + uVar8;
        uVar11 = *(int *)(param_1 + 100) + local_c0[0x18];
        uVar16 = uVar11 + local_c0[0x1a];
        local_20 = *(float *)(unaff_EBX + 0x236c) / (float)(int)*(short *)(param_1 + 0x50);
        fVar22 = local_20 * (float)(int)uVar8;
        local_20 = local_20 * (float)(int)uVar15;
        local_28 = *(float *)(unaff_EBX + 0x236c) / (float)(int)*(short *)(param_1 + 0x52);
        local_24 = local_28 * (float)(int)uVar11;
        local_28 = local_28 * (float)(int)uVar16;
        pdVar18[0xc0] = 0xc00c3500;
        pdVar18[0xc1] = 0x4003d;
        uVar17 = uVar8 | uVar16 * 0x10000;
        pdVar18[0xc2] = uVar17;
        pdVar18[0xc3] = (dword)fVar22;
        pdVar18[0xc4] = (dword)local_28;
        uVar6 = uVar8 | uVar11 * 0x10000;
        pdVar18[0xc5] = uVar6;
        pdVar18[0xc6] = (dword)fVar22;
        pdVar18[199] = (dword)local_24;
        uVar12 = uVar11 * 0x10000 | uVar15;
        pdVar18[200] = uVar12;
        pdVar18[0xc9] = (dword)local_20;
        pdVar18[0xca] = (dword)local_24;
        uVar9 = uVar16 * 0x10000 | uVar15;
        pdVar18[0xcb] = uVar9;
        pdVar18[0xcc] = (dword)local_20;
        pdVar18[0xcd] = (dword)local_28;
        pdVar18[0xce] = 0x1393;
        pdVar18[0xcf] = 10;
        pdVar18[0xd0] = 0x5c8;
        pdVar18[0xd1] = 0x20000;
        puVar14 = pdVar18 + 0xd2;
        if (local_44 - 0xd8 < 0x86) {
          local_30 = 0.0;
          local_2c = *(float *)(param_1 + 0x18);
          if (*(int *)(param_1 + 0x8c) == 0) {
            pdVar18[0xd2] = 0x5c8;
            local_30 = 2.8026e-45;
            pdVar18[0xd3] = 0xc000;
            *(undefined4 *)(param_1 + 0x94) = 0;
          }
          puVar14[(int)local_30] = 0x1000000;
          puVar3 = *(uint **)(param_1 + 0x7c);
          *puVar3 = *puVar3 | ((int)puVar14 - (int)puVar3 >> 2) + (int)local_30;
          iVar7 = _IOConnectMapMemory(*(undefined4 *)(param_1 + 0xc),0,
                                      **(undefined4 **)(unaff_EBX + 0x345c),&local_2c,&local_30,1);
          local_9c = uVar10;
          if (iVar7 == 0) {
            *(undefined4 *)((int)local_2c + 0x1c) = 0;
            *(int *)(param_1 + 0x7c) = (int)local_2c + 0x1c;
            *(float *)(param_1 + 0x18) = local_2c;
            puVar14 = (undefined4 *)((int)local_2c + 0x20);
            local_58 = (dword *)((int)local_2c + 0x24);
            local_54 = (dword *)((int)local_2c + 0x28);
            local_50 = (dword *)((int)local_2c + 0x2c);
            local_4c = (dword *)((int)local_2c + 0x30);
            local_48 = (dword *)((int)local_2c + 0x34);
            pdVar18 = (dword *)((int)local_2c + 0x38);
          }
          else {
            *(undefined4 *)(param_1 + 0x18) = 0;
            *(undefined4 *)(param_1 + 0x7c) = 0;
            puVar14 = (undefined4 *)0x0;
            local_58 = &__mh_bundle_header.cputype;
            local_54 = &__mh_bundle_header.cpusubtype;
            local_50 = &__mh_bundle_header.filetype;
            local_4c = &__mh_bundle_header.ncmds;
            local_48 = &__mh_bundle_header.sizeofcmds;
            pdVar18 = &__mh_bundle_header.flags;
          }
        }
        else {
          local_58 = pdVar18 + 0xd3;
          local_54 = pdVar18 + 0xd4;
          local_50 = pdVar18 + 0xd5;
          local_4c = pdVar18 + 0xd6;
          local_48 = pdVar18 + 0xd7;
          pdVar18 = pdVar18 + 0xd8;
          local_9c = local_44 - 0xd8;
        }
        puVar3 = *(uint **)(param_1 + 0x7c);
        *puVar3 = *puVar3 | (int)puVar14 - (int)puVar3 >> 2;
        *(undefined4 **)(param_1 + 0x7c) = puVar14;
        *puVar14 = 0x11000000;
        *local_58 = *(dword *)(param_1 + 0x84);
        *local_54 = 0;
        *local_50 = 0;
        puVar3 = *(uint **)(param_1 + 0x7c);
        *puVar3 = *puVar3 | (int)local_4c - (int)puVar3 >> 2;
        *(dword **)(param_1 + 0x7c) = local_4c;
        *local_4c = 0x4000000;
        *local_48 = *(dword *)**(undefined4 **)(unaff_EBX + 0x2a54);
        iVar7 = *(int *)(unaff_EBX + 0x2a54);
        iVar13 = *(int *)(iVar7 + 0x30);
        if (iVar13 == 3) {
          iVar13 = 0xb;
        }
        else if (iVar13 == 6) {
          iVar13 = 0xc;
        }
        iVar13 = ((int (*)())_radeon3DCopySetup)(iVar13,0,0,0,0);
        pdVar18[iVar13] = 0xc00c3500;
        pdVar18[iVar13 + 1] = 0x4003d;
        dVar1 = *(double *)(unaff_EBX + 0x23bc);
        local_2c = (float)((double)uVar8 * (dVar1 / (double)(int)*(short *)(iVar7 + 0x10)));
        fVar22 = (float)((double)uVar15 * (dVar1 / (double)(int)*(short *)(iVar7 + 0x10)));
        fVar21 = (float)((double)uVar11 * (dVar1 / (double)(int)*(short *)(iVar7 + 0x12)));
        local_30 = (float)((double)uVar16 * (dVar1 / (double)(int)*(short *)(iVar7 + 0x12)));
        pdVar18[iVar13 + 2] = uVar17;
        pdVar18[iVar13 + 3] = (dword)local_2c;
        pdVar18[iVar13 + 4] = (dword)local_30;
        pdVar18[iVar13 + 5] = uVar6;
        pdVar18[iVar13 + 6] = (dword)local_2c;
        pdVar18[iVar13 + 7] = (dword)fVar21;
        pdVar18[iVar13 + 8] = uVar12;
        pdVar18[iVar13 + 9] = (dword)fVar22;
        pdVar18[iVar13 + 10] = (dword)fVar21;
        pdVar18[iVar13 + 0xb] = uVar9;
        pdVar18[iVar13 + 0xc] = (dword)fVar22;
        pdVar18[iVar13 + 0xd] = (dword)local_30;
        pdVar18[iVar13 + 0xe] = 0x1393;
        pdVar18[iVar13 + 0xf] = 10;
        pdVar18[iVar13 + 0x10] = 0x5c8;
        pdVar18[iVar13 + 0x11] = 0x20000;
        local_44 = (local_9c - 6) - (iVar13 + 0x12);
        pdVar19 = pdVar18 + iVar13 + 0x12;
        local_94 = local_94 + 1;
        local_c0 = local_c0 + 4;
      } while (local_94 < in_stack_00000014[0x16]);
    }
    *(dword **)(param_1 + 0x80) = pdVar19;
    uVar5 = 0;
  }
  return uVar5;
}

/* _radeonSolidScanlines @ 0xc041 (3816 bytes) */
int _radeonSolidScanlines(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  uint param_4;
  int param_5;
{
  double *pdVar1;
  uint *puVar2;
  bool bVar3;
  bool bVar4;
  char cVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  char *pcVar11;
  float *pfVar12;
  float *pfVar13;
  dword *pdVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  int unaff_EBX;
  undefined4 *puVar19;
  int *piVar20;
  int iVar21;
  uint uVar22;
  uint uVar23;
  dword *pdVar24;
  float fVar25;
  float fVar26;
  float fVar27;
  float fVar28;
  dword *local_d0;
  int local_c4;
  uint local_b4;
  uint local_b0;
  int local_ac;
  float local_a8;
  float local_a4;
  uint local_90;
  uint local_8c;
  uint local_88;
  int local_84;
  int local_80;
  int local_7c;
  dword *local_78;
  dword *local_74;
  dword *local_70;
  dword *local_6c;
  dword *local_68;
  segment_command *local_64;
  dword *local_60;
  uint local_48;
  uint local_44;
  int local_38;
  int local_34;
  dword *local_30;
  float local_28;
  float local_24;
  float local_20;
  
  ((int (*)())___i686_get_pc_thunk_bx)();
  if ((param_4 & 0x7ffff000) == 0x6000) {
    fVar28 = *(float *)(param_1 + 0x18);
    puVar19 = *(undefined4 **)(param_1 + 0x80);
    if (puVar19 != (undefined4 *)0x0) {
      if ((uint)((*(int *)((int)fVar28 + 0x10) + -7) - ((int)puVar19 - ((int)fVar28 + 0x20) >> 2)) <
          *(int *)(param_5 + 0x58) * 0xc + 0x6eU) {
        local_28 = 0.0;
        if (*(int *)(param_1 + 0x8c) == 0) {
          *puVar19 = 0x5c8;
          local_28 = 2.8026e-45;
          puVar19[1] = 0xc000;
          *(undefined4 *)(param_1 + 0x94) = 0;
        }
        puVar19[(int)local_28] = 0x1000000;
        puVar2 = *(uint **)(param_1 + 0x7c);
        *puVar2 = *puVar2 | ((int)puVar19 - (int)puVar2 >> 2) + (int)local_28;
        local_24 = fVar28;
        iVar7 = _IOConnectMapMemory(*(undefined4 *)(param_1 + 0xc),0,
                                    **(undefined4 **)(unaff_EBX + 0x203e),&local_24,&local_28,1);
        if (iVar7 == 0) {
          *(undefined4 *)((int)local_24 + 0x1c) = 0;
          *(int *)(param_1 + 0x7c) = (int)local_24 + 0x1c;
          *(float *)(param_1 + 0x18) = local_24;
          puVar19 = (undefined4 *)((int)local_24 + 0x20);
        }
        else {
          *(undefined4 *)(param_1 + 0x18) = 0;
          *(undefined4 *)(param_1 + 0x7c) = 0;
          puVar19 = (undefined4 *)0x0;
        }
      }
      iVar7 = ((int (*)())_radeon3DFillSetup)(param_1);
      puVar2 = puVar19 + iVar7;
      *puVar2 = *(int *)(param_5 + 0x58) * 0xc0000 | 0xc0003500;
      pfVar13 = (float *)(puVar2 + 2);
      puVar2[1] = *(int *)(param_5 + 0x58) << 0x12 | 0x3d;
      iVar7 = *(int *)(param_1 + 100) + *(int *)(param_5 + 0x5c);
      fVar28 = (float)iVar7;
      fVar25 = (float)(iVar7 + *(int *)(param_5 + 0x60));
      if (*(int *)(param_5 + 0x58) != 0) {
        uVar6 = 0;
        piVar20 = (int *)(param_5 + 0x68);
        pfVar12 = pfVar13;
        do {
          fVar26 = (float)(piVar20[-1] + *(int *)(param_1 + 0x60));
          fVar27 = (float)(*(int *)(param_1 + 0x60) + *piVar20);
          *pfVar12 = fVar26;
          pfVar12[1] = fVar25;
          pfVar12[2] = 0.0;
          pfVar12[3] = fVar26;
          pfVar12[4] = fVar28;
          pfVar12[5] = 0.0;
          pfVar12[6] = fVar27;
          pfVar12[7] = fVar28;
          pfVar12[8] = 0.0;
          pfVar12[9] = fVar27;
          pfVar12[10] = fVar25;
          pfVar13 = pfVar12 + 0xc;
          pfVar12[0xb] = 0.0;
          uVar6 = uVar6 + 1;
          piVar20 = piVar20 + 2;
          pfVar12 = pfVar13;
        } while (uVar6 < *(uint *)(param_5 + 0x58));
      }
      *pfVar13 = 7.02191e-42;
      pfVar13[1] = 1.4013e-44;
      pfVar13[2] = 2.07392e-42;
      pfVar13[3] = 1.83671e-40;
      *(float **)(param_1 + 0x80) = pfVar13 + 4;
      return 0;
    }
  }
  else {
    iVar7 = *(int *)(param_1 + 0x18);
    uVar6 = *(int *)(iVar7 + 0x10) - 7;
    local_30 = *(dword **)(param_1 + 0x80);
    if ((local_30 != (dword *)0x0) &&
       (cVar5 = ((int (*)())_createTextureBuffer)(*(int *)(param_1 + 0x70) == 3), cVar5 != '\0')) {
      local_b0 = uVar6 - ((int)local_30 - (iVar7 + 0x20) >> 2);
      ((int (*)())_fillTextureWithPattern)(*(undefined4 *)(param_5 + 4));
      iVar7 = *(int *)(unaff_EBX + 0x16b6);
      iVar21 = *(int *)(iVar7 + 0x30);
      if (iVar21 == 3) {
        local_ac = 0xb;
      }
      else {
        local_ac = 0xc;
        if (iVar21 != 6) {
          local_ac = iVar21;
        }
      }
      uVar22 = *(int *)(param_1 + 100) + *(int *)(param_5 + 0x5c);
      uVar23 = uVar22 + *(int *)(param_5 + 0x60);
      local_a4 = (float)(*(int *)(param_5 + 0xc) + (uVar22 & 7));
      uVar16 = *(uint *)(param_5 + 0x58);
      if (uVar16 != 0) {
        uVar8 = uVar22 + 8;
        if (uVar23 <= uVar22 + 8) {
          uVar8 = uVar23;
        }
        bVar3 = true;
        local_b4 = 0;
        local_c4 = 0;
        do {
          uVar17 = *(int *)(param_5 + 100 + local_c4 * 4) + *(int *)(param_1 + 0x60);
          uVar9 = *(int *)(param_1 + 0x60) + *(int *)(param_5 + 0x68 + local_c4 * 4);
          local_a8 = (float)(*(int *)(param_5 + 8) + (uVar17 & 7));
          if (uVar22 < uVar23) {
            uVar18 = uVar17 + 8;
            uVar16 = uVar18;
            if (uVar9 <= uVar18) {
              uVar16 = uVar9;
            }
            bVar4 = true;
            local_90 = uVar22;
            local_8c = uVar8;
            do {
              if (uVar17 < uVar9) {
                local_48 = uVar18;
                local_88 = uVar16;
                local_44 = uVar17;
                if (!bVar3) goto LAB_0000c800;
                if (local_b0 < 0x8e) {
                  local_28 = 0.0;
                  local_24 = *(float *)(param_1 + 0x18);
                  if (*(int *)(param_1 + 0x8c) == 0) {
                    *local_30 = 0x5c8;
                    local_28 = 2.8026e-45;
                    pcVar11 = (char *)(local_30 + 1);
                    pcVar11[0] = '\0';
                    pcVar11[1] = -0x40;
                    pcVar11[2] = '\0';
                    pcVar11[3] = '\0';
                    *(undefined4 *)(param_1 + 0x94) = 0;
                  }
                  local_30[(int)local_28] = 0x1000000;
                  puVar2 = *(uint **)(param_1 + 0x7c);
                  *puVar2 = *puVar2 | ((int)local_30 - (int)puVar2 >> 2) + (int)local_28;
                  iVar21 = _IOConnectMapMemory(*(undefined4 *)(param_1 + 0xc),0,
                                               **(undefined4 **)(unaff_EBX + 0x203e),&local_24,
                                               &local_28,1);
                  if (iVar21 == 0) {
                    *(undefined4 *)((int)local_24 + 0x1c) = 0;
                    *(int *)(param_1 + 0x7c) = (int)local_24 + 0x1c;
                    *(float *)(param_1 + 0x18) = local_24;
                    local_30 = (dword *)((int)local_24 + 0x20);
                    local_78 = (dword *)((int)local_24 + 0x24);
                    local_74 = (dword *)((int)local_24 + 0x28);
                    local_70 = (dword *)((int)local_24 + 0x2c);
                    pdVar14 = (dword *)((int)local_24 + 0x30);
                    local_6c = (dword *)((int)local_24 + 0x34);
                    local_68 = (dword *)((int)local_24 + 0x38);
                    local_64 = (segment_command *)((int)local_24 + 0x3c);
                    local_60 = (dword *)((int)local_24 + 0x40);
                    local_d0 = (dword *)((int)local_24 + 0x44);
                    pdVar24 = (dword *)((int)local_24 + 0x48);
                    local_b0 = uVar6;
                  }
                  else {
                    *(undefined4 *)(param_1 + 0x18) = 0;
                    *(undefined4 *)(param_1 + 0x7c) = 0;
                    local_30 = (dword *)0x0;
                    local_78 = &__mh_bundle_header.cputype;
                    local_74 = &__mh_bundle_header.cpusubtype;
                    local_70 = &__mh_bundle_header.filetype;
                    pdVar14 = &__mh_bundle_header.ncmds;
                    local_6c = &__mh_bundle_header.sizeofcmds;
                    local_68 = &__mh_bundle_header.flags;
                    local_64 = &segment_command_0000001c;
                    local_60 = &segment_command_0000001c.cmdsize;
                    local_d0 = (dword *)segment_command_0000001c.segname;
                    pdVar24 = (dword *)(segment_command_0000001c.segname + 4);
                    local_b0 = uVar6;
                  }
                }
                else {
                  local_78 = local_30 + 1;
                  local_74 = local_30 + 2;
                  local_70 = local_30 + 3;
                  pdVar14 = local_30 + 4;
                  local_6c = local_30 + 5;
                  local_68 = local_30 + 6;
                  local_64 = (segment_command *)(local_30 + 7);
                  local_60 = local_30 + 8;
                  local_d0 = local_30 + 9;
                  pdVar24 = local_30 + 10;
                }
LAB_0000c4d0:
                puVar2 = *(uint **)(param_1 + 0x7c);
                *puVar2 = *puVar2 | (int)local_30 - (int)puVar2 >> 2;
                *(dword **)(param_1 + 0x7c) = local_30;
                *local_30 = 0x11000000;
                *local_78 = *(dword *)(param_1 + 0x84);
                *local_74 = 0;
                *local_70 = 0;
                puVar2 = *(uint **)(param_1 + 0x7c);
                *puVar2 = *puVar2 | (int)pdVar14 - (int)puVar2 >> 2;
                *(dword **)(param_1 + 0x7c) = pdVar14;
                *pdVar14 = 0x8000000;
                *local_6c = *(dword *)**(undefined4 **)(unaff_EBX + 0x16b6);
                *local_68 = 0;
                local_64->cmd = 0;
                *local_60 = 0;
                *local_d0 = 0;
                local_b0 = local_b0 - 10;
                iVar10 = ((int (*)())_radeon3DCopySetup)(local_ac,0,0,0,0);
                local_84 = iVar10 * 4;
                iVar21 = iVar10 + 1;
                local_80 = iVar10 + 2;
                local_7c = iVar10 + 3;
                local_34 = iVar10 + 4;
                local_30 = pdVar24;
                if (bVar4) goto LAB_0000c843;
LAB_0000c5c0:
                local_38 = local_34;
                local_34 = iVar10;
                do {
                  if (local_88 - local_44 == 8) {
                    uVar15 = local_8c - local_90;
                    if (uVar15 != 8) goto LAB_0000c5e7;
                    fVar28 = *(float *)(unaff_EBX + 0xf56);
                    pcVar11 = (char *)(local_84 + (int)local_30);
                    pcVar11[0] = '\0';
                    pcVar11[1] = '5';
                    pcVar11[2] = '\f';
                    pcVar11[3] = -0x40;
                    local_30[iVar21] = 0x4003d;
                    pdVar1 = (double *)(unaff_EBX + 0xf9e);
                    local_20 = (float)((double)(local_a8 + 0.0) *
                                      (*pdVar1 / (double)(int)*(short *)(iVar7 + 0x10)));
                    local_28 = (float)((double)(local_a8 + fVar28) *
                                      (*pdVar1 / (double)(int)*(short *)(iVar7 + 0x10)));
                    local_24 = (float)((double)(local_a4 + 0.0) *
                                      (*pdVar1 / (double)(int)*(short *)(iVar7 + 0x12)));
                    fVar28 = (float)((double)(fVar28 + local_a4) *
                                    (*pdVar1 / (double)(int)*(short *)(iVar7 + 0x12)));
                    local_30[local_80] = local_44 | local_8c << 0x10;
                    local_30[local_7c] = (dword)local_20;
                    local_30[local_38] = (dword)fVar28;
                    local_30[local_34 + 5] = local_44 | local_90 << 0x10;
                    local_30[local_34 + 6] = (dword)local_20;
                    local_30[local_34 + 7] = (dword)local_24;
                    local_30[local_34 + 8] = local_90 << 0x10 | local_88;
                    local_30[local_34 + 9] = (dword)local_28;
                    local_30[local_34 + 10] = (dword)local_24;
                    local_30[local_34 + 0xb] = local_88 | local_8c << 0x10;
                    local_30[local_34 + 0xc] = (dword)local_28;
                    local_30[local_34 + 0xd] = (dword)fVar28;
                  }
                  else {
                    uVar15 = local_8c - local_90;
LAB_0000c5e7:
                    pcVar11 = (char *)(local_84 + (int)local_30);
                    pcVar11[0] = '\0';
                    pcVar11[1] = '5';
                    pcVar11[2] = '\f';
                    pcVar11[3] = -0x40;
                    local_30[iVar21] = 0x4003d;
                    pdVar1 = (double *)(unaff_EBX + 0xf9e);
                    fVar28 = (float)((double)(local_a8 + 0.0) *
                                    (*pdVar1 / (double)(int)*(short *)(iVar7 + 0x10)));
                    local_20 = (float)((double)((float)(local_88 - local_44) + local_a8) *
                                      (*pdVar1 / (double)(int)*(short *)(iVar7 + 0x10)));
                    local_24 = (float)((double)(local_a4 + 0.0) *
                                      (*pdVar1 / (double)(int)*(short *)(iVar7 + 0x12)));
                    local_28 = (float)((double)((float)uVar15 + local_a4) *
                                      (*pdVar1 / (double)(int)*(short *)(iVar7 + 0x12)));
                    local_30[local_80] = local_44 | local_8c << 0x10;
                    local_30[local_7c] = (dword)fVar28;
                    local_30[local_38] = (dword)local_28;
                    local_30[local_34 + 5] = local_44 | local_90 << 0x10;
                    local_30[local_34 + 6] = (dword)fVar28;
                    local_30[local_34 + 7] = (dword)local_24;
                    local_30[local_34 + 8] = local_90 << 0x10 | local_88;
                    local_30[local_34 + 9] = (dword)local_20;
                    local_30[local_34 + 10] = (dword)local_24;
                    local_30[local_34 + 0xb] = local_8c << 0x10 | local_88;
                    local_30[local_34 + 0xc] = (dword)local_20;
                    local_30[local_34 + 0xd] = (dword)local_28;
                  }
                  local_30[local_34 + 0xe] = 0x1393;
                  local_30[local_34 + 0xf] = 10;
                  local_30[local_34 + 0x10] = 0x5c8;
                  local_30[local_34 + 0x11] = 0x20000;
                  local_b0 = local_b0 - (local_34 + 0x12);
                  local_30 = local_30 + local_34 + 0x12;
                  local_88 = local_44 + 0x10;
                  if (uVar9 <= local_44 + 0x10) {
                    local_88 = uVar9;
                  }
                  if (uVar9 <= local_48) {
                    bVar3 = false;
                    bVar4 = false;
                    break;
                  }
                  local_44 = local_48;
                  bVar4 = false;
                  local_48 = local_48 + 8;
LAB_0000c800:
                  if (local_b0 < 0x16) {
                    local_24 = 0.0;
                    local_28 = *(float *)(param_1 + 0x18);
                    if (*(int *)(param_1 + 0x8c) == 0) {
                      *local_30 = 0x5c8;
                      local_24 = 2.8026e-45;
                      pcVar11 = (char *)(local_30 + 1);
                      pcVar11[0] = '\0';
                      pcVar11[1] = -0x40;
                      pcVar11[2] = '\0';
                      pcVar11[3] = '\0';
                      *(undefined4 *)(param_1 + 0x94) = 0;
                    }
                    local_30[(int)local_24] = 0x1000000;
                    puVar2 = *(uint **)(param_1 + 0x7c);
                    *puVar2 = *puVar2 | ((int)local_30 - (int)puVar2 >> 2) + (int)local_24;
                    iVar21 = _IOConnectMapMemory(*(undefined4 *)(param_1 + 0xc),0,
                                                 **(undefined4 **)(unaff_EBX + 0x203e),&local_28,
                                                 &local_24,1);
                    if (iVar21 == 0) {
                      *(undefined4 *)((int)local_28 + 0x1c) = 0;
                      *(int *)(param_1 + 0x7c) = (int)local_28 + 0x1c;
                      *(float *)(param_1 + 0x18) = local_28;
                      local_30 = (dword *)((int)local_28 + 0x20);
                      local_78 = (dword *)((int)local_28 + 0x24);
                      local_74 = (dword *)((int)local_28 + 0x28);
                      local_70 = (dword *)((int)local_28 + 0x2c);
                      pdVar14 = (dword *)((int)local_28 + 0x30);
                      local_6c = (dword *)((int)local_28 + 0x34);
                      local_68 = (dword *)((int)local_28 + 0x38);
                      local_64 = (segment_command *)((int)local_28 + 0x3c);
                      local_60 = (dword *)((int)local_28 + 0x40);
                      local_d0 = (dword *)((int)local_28 + 0x44);
                      pdVar24 = (dword *)((int)local_28 + 0x48);
                      bVar4 = true;
                      local_b0 = uVar6;
                      local_48 = local_44 + 8;
                    }
                    else {
                      *(undefined4 *)(param_1 + 0x18) = 0;
                      *(undefined4 *)(param_1 + 0x7c) = 0;
                      pdVar24 = (dword *)(segment_command_0000001c.segname + 4);
                      local_d0 = (dword *)segment_command_0000001c.segname;
                      local_60 = &segment_command_0000001c.cmdsize;
                      local_64 = &segment_command_0000001c;
                      local_68 = &__mh_bundle_header.flags;
                      local_6c = &__mh_bundle_header.sizeofcmds;
                      pdVar14 = &__mh_bundle_header.ncmds;
                      local_70 = &__mh_bundle_header.filetype;
                      local_74 = &__mh_bundle_header.cpusubtype;
                      local_78 = &__mh_bundle_header.cputype;
                      local_30 = (dword *)0x0;
                      bVar4 = true;
                      local_b0 = uVar6;
                      local_48 = local_44 + 8;
                    }
                    goto LAB_0000c4d0;
                  }
                  local_34 = 4;
                  local_7c = 3;
                  local_80 = 2;
                  iVar21 = 1;
                  local_84 = 0;
                  iVar10 = 0;
                  if (!bVar4) goto LAB_0000c5c0;
LAB_0000c843:
                  pcVar11 = (char *)((int)local_30 + local_84);
                  pcVar11[0] = -8;
                  pcVar11[1] = '\x10';
                  pcVar11[2] = '\0';
                  pcVar11[3] = '\0';
                  local_30[iVar21] = uVar17 & 0x1fff | (uVar22 & 0x1fff) << 0xd;
                  local_30[local_80] = 0x10f9;
                  local_30[local_7c] = uVar9 & 0x1fff | (uVar23 & 0x1fff) << 0xd;
                  local_84 = local_34 << 2;
                  iVar21 = local_34 + 1;
                  local_80 = local_34 + 2;
                  local_7c = local_34 + 3;
                  local_38 = local_34 + 4;
                } while( true );
              }
              uVar15 = local_90 + 8;
              local_8c = local_90 + 0x10;
              if (uVar23 <= local_90 + 0x10) {
                local_8c = uVar23;
              }
              local_90 = uVar15;
            } while (uVar15 < uVar23);
            uVar16 = *(uint *)(param_5 + 0x58);
          }
          local_b4 = local_b4 + 1;
          local_c4 = local_c4 + 2;
        } while (local_b4 < uVar16);
      }
      *(dword **)(param_1 + 0x80) = local_30;
      return 0;
    }
  }
  return 0xe00002be;
}

/* ___i686_get_pc_thunk_bx @ 0xcf8b (4 bytes) */
int ___i686_get_pc_thunk_bx()
{
  return;
}

/* ___i686_get_pc_thunk_cx @ 0xcf8f (4 bytes) */
int ___i686_get_pc_thunk_cx()
{
  return;
}

