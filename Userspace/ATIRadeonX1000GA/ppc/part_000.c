#include "decls.h"

/* __dyld_func_lookup @ 0x630 (32 bytes) */
int __dyld_func_lookup()
{
                    
                    
  (*dyld_func_lookup_pointer)();
  return;
}

/* _cxa_atexit_check_1 @ 0x678 (120 bytes) */
int _cxa_atexit_check_1(param_1)
  undefined4 *param_1;
{
  int iVar1;
  undefined4 *puStack00000018;
  
  puStack00000018 = param_1;
  iVar1 = (*(code *)param_1[1])(0x650,param_1,param_1);
  if (iVar1 != 0) {
    *param_1 = 0xffffffff;
  }
  return;
}

/* _check_cxa_atexit @ 0x6f0 (204 bytes) */
int _check_cxa_atexit(param_1, param_2)
  code *param_1;
  code *param_2;
{
  int iVar1;
  code *pcStack00000018;
  code *pcStack0000001c;
  int local_28;
  code *local_24;
  int local_18;
  
  local_28 = 0;
  pcStack00000018 = param_1;
  pcStack0000001c = param_2;
  local_24 = param_1;
  iVar1 = (*param_1)(0x678,&local_28,&local_28);
  if (iVar1 == 0) {
    (*pcStack0000001c)(&local_28);
    if (local_28 == 0) {
      (*pcStack0000001c)(&local_28);
      local_28 = 0;
    }
    local_18 = local_28;
  }
  else {
    local_18 = -1;
  }
  return local_18;
}

/* _find_atexit_10_3 @ 0x7bc (504 bytes) */
int _find_atexit_10_3()
{
  uint uVar1;
  char *pcVar2;
  int iVar3;
  undefined4 uVar4;
  uint local_38;
  code *local_34;
  code *local_30;
  code *local_2c;
  code *local_28;
  code *local_24 [9];
  
  ((int (*)())__dyld_func_lookup)("__dyld_image_count",&local_34);
  ((int (*)())__dyld_func_lookup)("__dyld_get_image_name",&local_30);
  ((int (*)())__dyld_func_lookup)("__dyld_get_image_header",&local_2c);
  ((int (*)())__dyld_func_lookup)("__dyld_NSLookupSymbolInImage",&local_28);
  ((int (*)())__dyld_func_lookup)("__dyld_NSAddressOfSymbol",local_24);
  if ((((local_34 != (code *)0x0) && (local_30 != (code *)0x0)) && (local_2c != (code *)0x0)) &&
     ((local_28 != (code *)0x0 && (local_24[0] != (code *)0x0)))) {
    uVar1 = (*local_34)();
    for (local_38 = 0; local_38 < uVar1; local_38 = local_38 + 1) {
      pcVar2 = (char *)(*local_30)(local_38);
      iVar3 = _strcmp(pcVar2,"/usr/lib/libSystem.B.dylib");
      if (iVar3 == 0) {
        iVar3 = (*local_2c)(local_38);
        if (iVar3 == 0) {
          return 0;
        }
        iVar3 = (*local_28)(iVar3,"_atexit",4);
        if (iVar3 != 0) {
          uVar4 = (*local_24[0])(iVar3);
          return uVar4;
        }
        return 0;
      }
    }
  }
  return 0;
}

/* FUN_000009b4 @ 0x9b4 (32 bytes) */
int FUN_000009b4(param_1, param_2)
  char *param_1;
  char *param_2;
{
  int iVar1;
  
  iVar1 = _strcmp(param_1,param_2);
  return iVar1;
}

/* _get_globals @ 0x9f4 (528 bytes) */
int _get_globals()
{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  void *local_20;
  void *local_18;
  
  local_20 = (void *)__keymgr_get_and_lock_processwide_ptr(0xe);
  if ((local_20 == (void *)0x0) && (local_20 = _calloc(0x14,1), local_20 == (void *)0x0)) {
    return (void *)0x0;
  }
  if (*(char *)((int)local_20 + 3) == '\0') {
    iVar1 = _dlopen("/usr/lib/libSystem.B.dylib",0x10);
    if (iVar1 == 0) {
      *(undefined1 *)((int)local_20 + 3) = 1;
      uVar2 = ((int (*)())_find_atexit_10_3)();
      *(undefined4 *)((int)local_20 + 0x10) = uVar2;
      if ((*(int *)((int)local_20 + 0x10) != 0) &&
         (iVar1 = (**(code **)((int)local_20 + 0x10))(&_our_atexit), iVar1 == 0)) goto LAB_00000bc8;
    }
    else {
      uVar2 = _dlsym(iVar1,"__cxa_atexit");
      *(undefined4 *)((int)local_20 + 8) = uVar2;
      uVar2 = _dlsym(iVar1,"__cxa_finalize");
      *(undefined4 *)((int)local_20 + 0xc) = uVar2;
      if (((*(int *)((int)local_20 + 8) != 0) && (*(int *)((int)local_20 + 0xc) != 0)) &&
         (iVar3 = ((int (*)())_check_cxa_atexit)(*(undefined4 *)((int)local_20 + 8),
                                    *(undefined4 *)((int)local_20 + 0xc)), iVar3 != -1)) {
        if (iVar3 == 0) {
          *(undefined1 *)((int)local_20 + 3) = 2;
        }
        else {
          uVar2 = _dlsym(iVar1,"atexit");
          *(undefined4 *)((int)local_20 + 0x10) = uVar2;
          if (*(int *)((int)local_20 + 0x10) == 0) goto LAB_00000bd4;
          *(undefined1 *)((int)local_20 + 3) = 0x10;
        }
        goto LAB_00000bc8;
      }
    }
LAB_00000bd4:
    __keymgr_set_and_unlock_processwide_ptr(0xe,local_20);
    local_18 = (void *)0x0;
  }
  else {
LAB_00000bc8:
    local_18 = local_20;
  }
  return local_18;
}

/* FUN_00000c04 @ 0xc04 (32 bytes) */
int FUN_00000c04()
{
  __keymgr_set_and_unlock_processwide_ptr();
  return;
}

/* _add_routine @ 0xce4 (268 bytes) */
int _add_routine(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  int iStack00000018;
  undefined4 *puStack0000001c;
  undefined4 local_18;
  undefined4 local_14;
  
  iStack00000018 = param_1;
  puStack0000001c = param_2;
  puVar3 = _malloc(0x10);
  if (puVar3 == (undefined4 *)0x0) {
    __keymgr_set_and_unlock_processwide_ptr(0xe,iStack00000018);
    local_14 = 0xffffffff;
  }
  else {
    uVar1 = puStack0000001c[1];
    uVar2 = puStack0000001c[2];
    puVar3[1] = *puStack0000001c;
    puVar3[2] = uVar1;
    puVar3[3] = uVar2;
    *puVar3 = *(undefined4 *)(iStack00000018 + 4);
    *(undefined4 **)(iStack00000018 + 4) = puVar3;
    iVar4 = __keymgr_set_and_unlock_processwide_ptr(0xe,iStack00000018);
    if ((*(ushort *)(*(int *)(PTR_0000e68c + 8) + 4) < 4) || (iVar4 == 0)) {
      local_18 = 0;
    }
    else {
      local_18 = 0xffffffff;
    }
    local_14 = local_18;
  }
  return local_14;
}

/* FUN_00000df0 @ 0xdf0 (32 bytes) */
int FUN_00000df0()
{
  __keymgr_set_and_unlock_processwide_ptr();
  return;
}

/* _run_routines @ 0xe30 (292 bytes) */
int _run_routines(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  undefined4 *puVar1;
  uint uVar2;
  int iStack00000018;
  undefined4 *puStack0000001c;
  
  iStack00000018 = param_1;
  puStack0000001c = param_2;
  while( true ) {
    puVar1 = *(undefined4 **)(iStack00000018 + 4);
    if (puVar1 == (undefined4 *)0x0) {
      return iStack00000018;
    }
    if (puVar1 == puStack0000001c) break;
    *(undefined4 *)(iStack00000018 + 4) = *puVar1;
    __keymgr_set_and_unlock_processwide_ptr(0xe,iStack00000018);
    if ((uint)puVar1[2] < 6) {
      uVar2 = 1 << (puVar1[2] & 0x3f);
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
    iStack00000018 = __keymgr_get_and_lock_processwide_ptr(0xe);
    if (iStack00000018 == 0) {
      return 0;
    }
  }
  return iStack00000018;
}

/* FUN_00000f54 @ 0xf54 (32 bytes) */
int FUN_00000f54()
{
  __keymgr_get_and_lock_processwide_ptr();
  return;
}

/* FUN_000010ec @ 0x10ec (32 bytes) */
int FUN_000010ec(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  undefined4 *puVar1;
  uint uVar2;
  int iStack00000018;
  undefined4 *puStack0000001c;
  
  iStack00000018 = param_1;
  puStack0000001c = param_2;
  while( true ) {
    puVar1 = *(undefined4 **)(iStack00000018 + 4);
    if (puVar1 == (undefined4 *)0x0) {
      return iStack00000018;
    }
    if (puVar1 == puStack0000001c) break;
    *(undefined4 *)(iStack00000018 + 4) = *puVar1;
    __keymgr_set_and_unlock_processwide_ptr(0xe,iStack00000018);
    if ((uint)puVar1[2] < 6) {
      uVar2 = 1 << (puVar1[2] & 0x3f);
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
    iStack00000018 = __keymgr_get_and_lock_processwide_ptr(0xe);
    if (iStack00000018 == 0) {
      return 0;
    }
  }
  return iStack00000018;
}

/* FUN_00001208 @ 0x1208 (32 bytes) */
int FUN_00001208()
{
  __keymgr_set_and_unlock_processwide_ptr();
  return;
}

/* _atexit_common @ 0x1268 (672 bytes) */
int _atexit_common(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  code *pcVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puStack00000018;
  undefined4 uStack0000001c;
  undefined4 local_18;
  
  puStack00000018 = param_1;
  uStack0000001c = param_2;
  iVar4 = ((int (*)())_get_globals)();
  if (iVar4 == 0) {
    local_18 = 0xffffffff;
  }
  else if ((*(char *)(iVar4 + 2) == '\0') && (*(char *)(iVar4 + 3) != '\x01')) {
    if (*(byte *)(iVar4 + 3) < 0x10) {
      pcVar1 = *(code **)(iVar4 + 8);
      iVar4 = __keymgr_set_and_unlock_processwide_ptr(0xe,iVar4);
      if ((*(ushort *)(*(int *)(PTR_0000e68c + 8) + 4) < 4) || (iVar4 == 0)) {
        puVar5 = _malloc(0xc);
        if (puVar5 == (undefined4 *)0x0) {
          local_18 = 0xffffffff;
        }
        else {
          uVar2 = puStack00000018[1];
          uVar3 = puStack00000018[2];
          *puVar5 = *puStack00000018;
          puVar5[1] = uVar2;
          puVar5[2] = uVar3;
          local_18 = (*pcVar1)(0xfb4,puVar5,uStack0000001c);
        }
      }
      else {
        local_18 = 0xffffffff;
      }
    }
    else if (puStack00000018[1] == 0) {
      pcVar1 = *(code **)(iVar4 + 0x10);
      iVar4 = __keymgr_set_and_unlock_processwide_ptr(0xe,iVar4);
      if ((*(ushort *)(*(int *)(PTR_0000e68c + 8) + 4) < 4) || (iVar4 == 0)) {
        local_18 = (*pcVar1)(*puStack00000018);
      }
      else {
        local_18 = 0xffffffff;
      }
    }
    else {
      pcVar1 = *(code **)(iVar4 + 8);
      iVar4 = __keymgr_set_and_unlock_processwide_ptr(0xe,iVar4);
      if ((*(ushort *)(*(int *)(PTR_0000e68c + 8) + 4) < 4) || (iVar4 == 0)) {
        local_18 = (*pcVar1)(*puStack00000018,puStack00000018[2],uStack0000001c);
      }
      else {
        local_18 = 0xffffffff;
      }
    }
  }
  else {
    local_18 = ((int (*)())_add_routine)(iVar4,puStack00000018);
  }
  return local_18;
}

/* FUN_00001508 @ 0x1508 (32 bytes) */
int FUN_00001508(param_1)
  size_t param_1;
{
  void *pvVar1;
  
  pvVar1 = _malloc(param_1);
  return pvVar1;
}

/* FUN_000015e8 @ 0x15e8 (32 bytes) */
int FUN_000015e8()
{
  ((int (*)())_atexit_common)();
  return;
}

/* _atexit @ 0x1608 (92 bytes) */
int _atexit(param_1)
  void *param_1;
{
  int iVar1;
  void *pvStack00000018;
  void *local_28;
  undefined4 local_24;
  
  local_24 = 0;
  pvStack00000018 = param_1;
  local_28 = param_1;
  iVar1 = ((int (*)())_atexit_common)(&local_28,PTR_0000e690);
  return iVar1;
}

/* FUN_00001664 @ 0x1664 (32 bytes) */
int FUN_00001664()
{
  ((int (*)())_atexit_common)();
  return;
}

/* __SetSurface @ 0x1690 (184 bytes) */
undefined8 __SetSurface(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  int param_3;
{
  undefined8 uVar1;
  undefined4 local_28;
  int local_24;
  uint local_20;
  
  if ((param_2 & 0x800) == 0) {
    local_24 = *(int *)(param_1 + 0x84);
    local_20 = 0;
  }
  else {
    if (*(int *)(param_3 + 0x28) == 0) {
      return 0xffffffffe00002d8;
    }
    local_24 = *(int *)(*(int *)(param_3 + 0x28) + 8);
    local_20 = param_2;
  }
  local_28 = 0x30;
  uVar1 = _io_connect_method_scalarI_structureO
                    (*(undefined4 *)(param_1 + 0xc),0,&local_24,2,param_1 + 0x4c,&local_28);
  if ((int)uVar1 == 0) {
    if ((local_24 == 0) || (local_20 == 0)) {
      param_3 = 0;
    }
    *(int *)(param_1 + 0x8c) = param_3;
    uVar1 = 0;
  }
  return uVar1;
}

/* __SetDestination @ 0x1750 (8 bytes) */
int __SetDestination(param_1, param_2)
  undefined8 param_1;
  ulonglong param_2;
{
  ((int (*)())__SetSurface)(param_1,(param_2 & 1) << 0xb);
  return;
}

/* __LockSurface @ 0x1760 (160 bytes) */
undefined8 __LockSurface(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  int *param_4;
{
  int iVar1;
  undefined8 uVar2;
  undefined4 local_28;
  int local_24;
  undefined4 local_20;
  
  if (*(int *)(param_3 + 0x28) == 0) {
    uVar2 = 0xffffffffe00002d8;
  }
  else {
    iVar1 = *(int *)(*(int *)(param_3 + 0x28) + 4);
    if (iVar1 == 0) {
      local_28 = 2;
      local_24 = param_2;
      uVar2 = _io_connect_method_scalarI_scalarO
                        (*(undefined4 *)(param_1 + 0xc),5,&local_24,1,&local_24,&local_28);
      if ((int)uVar2 == 0) {
        *param_4 = local_24;
        *(undefined4 *)(param_3 + 0x18) = local_20;
      }
    }
    else {
      uVar2 = 0;
      *param_4 = iVar1;
    }
  }
  return uVar2;
}

/* __UnlockSurface @ 0x1820 (144 bytes) */
undefined8 __UnlockSurface(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 param_2;
  int param_3;
  undefined4 *param_4;
{
  undefined8 uVar1;
  undefined4 local_28;
  undefined4 local_24 [9];
  
  if (*(int *)(param_3 + 0x28) == 0) {
    uVar1 = 0xffffffffe00002d8;
  }
  else {
    uVar1 = 0;
    if (*(int *)(*(int *)(param_3 + 0x28) + 4) == 0) {
      local_28 = 1;
      local_24[0] = param_2;
      uVar1 = _io_connect_method_scalarI_scalarO
                        (*(undefined4 *)(param_1 + 0xc),6,local_24,1,local_24,&local_28);
      if (param_4 != (undefined4 *)0x0) {
        *param_4 = local_24[0];
      }
    }
  }
  return uVar1;
}

/* __SwapSurface @ 0x18c0 (128 bytes) */
undefined8 __SwapSurface(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 param_2;
  int param_3;
  undefined4 *param_4;
{
  undefined8 uVar1;
  undefined4 local_28;
  undefined4 local_24 [9];
  
  if (*(int *)(param_3 + 0x28) == 0) {
    uVar1 = 0xffffffffe00002d8;
  }
  else {
    local_28 = 1;
    local_24[0] = param_2;
    uVar1 = _io_connect_method_scalarI_scalarO
                      (*(undefined4 *)(param_1 + 0xc),3,local_24,1,local_24,&local_28);
    if (param_4 != (undefined4 *)0x0) {
      *param_4 = local_24[0];
    }
  }
  return uVar1;
}

/* __Probe @ 0x1950 (16 bytes) */
undefined8 __Probe()
{
  undefined4 *in_r6;
  
  *in_r6 = 2000;
  return 0;
}

/* _window_mode_to_ati_format @ 0x1960 (148 bytes) */
undefined8 _window_mode_to_ati_format(param_1)
  uint param_1;
{
  switch(param_1 & 0xf) {
  case 3:
    return 7;
  case 4:
    return 0xb;
  default:
    return 0;
  case 6:
    return 0x27;
  case 7:
    return 0x2b;
  case 8:
    return 0x2c;
  case 9:
    return 0x2a;
  case 10:
    return 8;
  case 0xb:
    return 0x18;
  case 0xc:
    return 0x1e;
  case 0xd:
    return 0x12;
  }
}

/* __QueryInterface @ 0x1a20 (340 bytes) */
undefined8 __QueryInterface(param_1, param_2, param_3, param_4, param_5, param_6)
  int *param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 *param_6;
{
  undefined8 uVar1;
  undefined8 uVar2;
  longlong lVar3;
  int iVar4;
  undefined4 uStack0000001c;
  undefined4 uStack00000020;
  undefined4 uStack00000024;
  undefined4 uStack00000028;
  
  uStack0000001c = param_2;
  uStack00000020 = param_3;
  uStack00000024 = param_4;
  uStack00000028 = param_5;
  uVar1 = _CFUUIDCreateFromUUIDBytes(0);
  uVar2 = _CFUUIDGetConstantUUIDWithBytes(0,0x67,0x66,0xe9,0x4a,0,0,0);
  lVar3 = _CFEqual(uVar1,uVar2);
  if (lVar3 == 0) {
    uVar2 = _CFUUIDGetConstantUUIDWithBytes(0,0,0,0,0,0,0,0);
    iVar4 = _CFEqual(uVar1,uVar2);
    if (iVar4 == 0) {
      *param_6 = 0;
      return 0xffffffff80000004;
    }
  }
  (**(code **)(*param_1 + 8))(param_1);
  *param_6 = param_1;
  return 0;
}

/* __DecodePixelFormat @ 0x1ba0 (468 bytes) */
undefined8 __DecodePixelFormat(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
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
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  
  if (param_1 != 0x32767579) {
    if (param_1 < 0x3276757a) {
      if (param_1 == 0x10) {
        uVar4 = 3;
        uVar7 = 1;
        uVar3 = 2;
        uVar5 = 1;
        uVar6 = 7;
        uVar1 = 0xb;
        uVar2 = 3;
      }
      else if (param_1 == 0x20) {
        uVar4 = 6;
        uVar7 = 2;
        uVar3 = 4;
        uVar5 = 2;
        uVar6 = 0xb;
        uVar1 = 6;
        uVar2 = 4;
      }
      else {
        if (param_1 != 8) {
          return 0;
        }
        uVar4 = 9;
        uVar7 = 0;
        uVar3 = 1;
        uVar5 = 0;
        uVar6 = 0;
        uVar1 = 0;
        uVar2 = 0;
      }
      goto LAB_00001cfc;
    }
    if (param_1 == 0x42475241) {
      uVar4 = 6;
      uVar7 = 2;
      uVar3 = 4;
      uVar5 = 0;
      uVar6 = 8;
      uVar1 = 6;
      uVar2 = 10;
      goto LAB_00001cfc;
    }
    if (param_1 < 0x42475242) {
      if (param_1 != 0x42343434) {
        return 0;
      }
      uVar4 = 3;
      uVar7 = 1;
      uVar3 = 2;
      uVar5 = 1;
      uVar6 = 6;
      uVar1 = 10;
      uVar2 = 0;
      goto LAB_00001cfc;
    }
    if (param_1 != 0x59565955) {
      if (param_1 != 0x79757673) {
        return 0;
      }
      uVar4 = 3;
      uVar7 = 1;
      uVar3 = 2;
      uVar5 = 0;
      uVar6 = 0x26;
      uVar1 = 0x14;
      uVar2 = 6;
      goto LAB_00001cfc;
    }
  }
  uVar4 = 3;
  uVar7 = 1;
  uVar3 = 2;
  uVar5 = 0;
  uVar6 = 0x27;
  uVar1 = 0x15;
  uVar2 = 9;
LAB_00001cfc:
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = uVar1;
  }
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = uVar5;
  }
  if (param_5 != (undefined4 *)0x0) {
    *param_5 = uVar4;
  }
  if (param_4 != (undefined4 *)0x0) {
    *param_4 = uVar3;
  }
  if (param_6 != (undefined4 *)0x0) {
    *param_6 = uVar7;
  }
  if (param_7 != (undefined4 *)0x0) {
    *param_7 = uVar2;
  }
  if (param_8 != (undefined4 *)0x0) {
    *param_8 = uVar6;
  }
  return 1;
}

/* _fillTextureWithPattern @ 0x1d90 (664 bytes) */
int _fillTextureWithPattern(param_1, param_2, param_3, param_4)
  int *param_1;
  uint param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  ulonglong uVar8;
  int iVar9;
  longlong lVar10;
  int iVar11;
  ulonglong uVar12;
  undefined2 uVar14;
  undefined4 uVar13;
  int iVar15;
  ulonglong uVar16;
  longlong lVar17;
  
  if ((param_2 & 0x7ffff000) == 0x6000) {
    uVar7 = 0xffffffffffffffff;
    uVar16 = 0xffffffffffffffff;
  }
  else {
    uVar1 = ((uint *)*param_1)[1];
    uVar2 = *(uint *)*param_1;
    uVar7 = (ulonglong)(uVar2 >> 0x18) | (ulonglong)(uVar2 >> 8) & 0xff00 |
            ((ulonglong)uVar2 & 0xff00) << 8 | ((ulonglong)uVar2 & 0xff) << 0x18;
    uVar16 = (ulonglong)(uVar1 >> 0x18) | (ulonglong)(uVar1 >> 8) & 0xff00 |
             ((ulonglong)uVar1 & 0xff00) << 8 | ((ulonglong)uVar1 & 0xff) << 0x18;
  }
  if (DAT_0000e724 == 0x10) {
    uVar8 = 0;
    lVar17 = 0x20;
    uVar12 = 0xffffffff80000000;
    iVar3 = _textureBufferWidth * 0x10;
    iVar4 = _textureBufferWidth * 2;
    lVar10 = ((ulonglong)_textureBufferWidth & 0x1fffffff) * 8;
    iVar15 = iVar3 + _textureBufferBytes;
    iVar11 = _textureBufferBytes;
    do {
      uVar14 = (short)param_4;
      if ((uVar7 & uVar12) == 0) {
        uVar14 = (short)param_3;
      }
      iVar9 = (int)uVar8;
      iVar5 = (int)((uVar8 & 0xffffffff) << 1);
      uVar6 = lVar10 + uVar8;
      uVar8 = uVar8 + 1;
      *(undefined2 *)(iVar11 + iVar5) = uVar14;
      *(undefined2 *)(iVar5 + iVar11 + 0x10) = uVar14;
      *(undefined2 *)((int)((uVar6 & 0xffffffff) << 1) + iVar11) = uVar14;
      *(undefined2 *)(iVar15 + iVar5 + 0x10) = uVar14;
      if (iVar9 == 7) {
        iVar11 = iVar11 + iVar4;
        uVar8 = 0;
        iVar15 = iVar3 + iVar11;
      }
      uVar12 = (uVar12 & 0xffffffff) >> 1;
      lVar17 = lVar17 + -1;
    } while (lVar17 != 0);
    uVar12 = 0;
    uVar7 = 0xffffffff80000000;
    lVar17 = 0x20;
    while( true ) {
      uVar14 = (short)param_4;
      if ((uVar16 & uVar7) == 0) {
        uVar14 = (short)param_3;
      }
      iVar9 = (int)uVar12;
      iVar5 = (int)((uVar12 & 0xffffffff) << 1);
      uVar8 = uVar12 + lVar10;
      uVar12 = uVar12 + 1;
      *(undefined2 *)(iVar11 + iVar5) = uVar14;
      *(undefined2 *)(iVar5 + iVar11 + 0x10) = uVar14;
      *(undefined2 *)((int)((uVar8 & 0xffffffff) << 1) + iVar11) = uVar14;
      *(undefined2 *)(iVar15 + iVar5 + 0x10) = uVar14;
      if (iVar9 == 7) {
        iVar11 = iVar11 + iVar4;
        uVar12 = 0;
      }
      uVar7 = (uVar7 & 0xffffffff) >> 1;
      lVar17 = lVar17 + -1;
      if (lVar17 == 0) break;
      iVar15 = iVar3 + iVar11;
    }
  }
  else {
    uVar8 = 0;
    uVar12 = 0xffffffff80000000;
    lVar17 = 0x20;
    iVar3 = _textureBufferWidth * 0x20;
    iVar4 = _textureBufferWidth * 4;
    lVar10 = ((ulonglong)_textureBufferWidth & 0x1fffffff) * 8;
    iVar15 = iVar3 + _textureBufferBytes;
    iVar11 = _textureBufferBytes;
    do {
      uVar13 = param_4;
      if ((uVar7 & uVar12) == 0) {
        uVar13 = param_3;
      }
      iVar9 = (int)uVar8;
      iVar5 = (int)((uVar8 & 0xffffffff) << 2);
      uVar6 = lVar10 + uVar8;
      uVar8 = uVar8 + 1;
      *(undefined4 *)(iVar11 + iVar5) = uVar13;
      *(undefined4 *)(iVar5 + iVar11 + 0x20) = uVar13;
      *(undefined4 *)((int)((uVar6 & 0xffffffff) << 2) + iVar11) = uVar13;
      *(undefined4 *)(iVar15 + iVar5 + 0x20) = uVar13;
      if (iVar9 == 7) {
        iVar11 = iVar11 + iVar4;
        uVar8 = 0;
        iVar15 = iVar3 + iVar11;
      }
      uVar12 = (uVar12 & 0xffffffff) >> 1;
      lVar17 = lVar17 + -1;
    } while (lVar17 != 0);
    uVar12 = 0;
    uVar7 = 0xffffffff80000000;
    lVar17 = 0x20;
    while( true ) {
      uVar13 = param_4;
      if ((uVar16 & uVar7) == 0) {
        uVar13 = param_3;
      }
      iVar9 = (int)uVar12;
      iVar5 = (int)((uVar12 & 0xffffffff) << 2);
      uVar8 = uVar12 + lVar10;
      uVar12 = uVar12 + 1;
      *(undefined4 *)(iVar11 + iVar5) = uVar13;
      *(undefined4 *)(iVar5 + iVar11 + 0x20) = uVar13;
      *(undefined4 *)((int)((uVar8 & 0xffffffff) << 2) + iVar11) = uVar13;
      *(undefined4 *)(iVar15 + iVar5 + 0x20) = uVar13;
      if (iVar9 == 7) {
        iVar11 = iVar11 + iVar4;
        uVar12 = 0;
      }
      uVar7 = (uVar7 & 0xffffffff) >> 1;
      lVar17 = lVar17 + -1;
      if (lVar17 == 0) break;
      iVar15 = iVar3 + iVar11;
    }
  }
  return;
}

/* __GetCapabilities @ 0x2030 (156 bytes) */
undefined8 __GetCapabilities(param_1, param_2, param_3)
  int param_1;
  int param_2;
  undefined4 *param_3;
{
  undefined8 uVar1;
  
  if (param_2 != 0x63676c73) {
    if (param_2 == 0x736d766c) {
      if ((param_1 != 0) && (*(int *)(param_1 + 0xc) != 0)) {
        uVar1 = _io_connect_method_scalarI_structureI(*(int *)(param_1 + 0xc),0xf,param_3,1,0,0);
        return uVar1;
      }
      return 0xffffffffe00002d8;
    }
    if (param_2 != 0x42475241) {
      return 0xffffffffe00002c7;
    }
  }
  *param_3 = *(undefined4 *)PTR_0000e698;
  return 0;
}

/* _ATIRadeonX1000GAFactory @ 0x22d0 (324 bytes) */
int _ATIRadeonX1000GAFactory(param_1, param_2)
  undefined8 param_1;
  undefined8 param_2;
{
  undefined8 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  
  uVar1 = _CFUUIDGetConstantUUIDWithBytes(0,0xac,0xcf,0,0,0,0,0);
  iVar2 = _CFEqual(param_2,uVar1);
  puVar3 = (undefined4 *)0x0;
  if (iVar2 != 0) {
    uVar1 = _CFUUIDGetConstantUUIDWithBytes(0,0x10,2,0x71,0,0,0,0);
    puVar3 = _calloc(1,0x98);
    *puVar3 = &_radeonGAInterface;
    if ((int)uVar1 != 0) {
      uVar4 = _CFRetain(uVar1);
      puVar3[1] = uVar4;
      _CFPlugInAddInstanceForFactory(uVar1);
    }
    puVar3[2] = 1;
  }
  return puVar3;
}

/* __Reset @ 0x2490 (360 bytes) */
undefined8 __Reset(param_1)
  int param_1;
{
  uint *puVar1;
  undefined4 uVar2;
  int iVar3;
  undefined8 uVar4;
  undefined4 local_28;
  int local_24;
  int local_20 [8];
  
  if (*(int *)(param_1 + 0xc) == 0) {
    uVar4 = 0xffffffffe00002d8;
  }
  else {
    iVar3 = _IOConnectMapMemory(*(int *)(param_1 + 0xc),1,*(undefined4 *)PTR_0000e694,local_20,
                                &local_28,1);
    if ((iVar3 == 0) && (local_20[0] != 0)) {
      *(int *)(param_1 + 0x14) = local_20[0];
      local_28 = 1;
      *(undefined4 *)(local_20[0] + 0x20) = 0x80000000;
      *(undefined4 *)(local_20[0] + 0x14) = 1;
    }
    if (*(int *)(param_1 + 0x18) != 0) {
      **(undefined4 **)(param_1 + 0x80) = 0x1000000;
      puVar1 = *(uint **)(param_1 + 0x7c);
      *puVar1 = *(int *)(param_1 + 0x80) - (int)puVar1 >> 2 | *puVar1;
    }
    iVar3 = _IOConnectMapMemory(*(undefined4 *)(param_1 + 0xc),0,*(undefined4 *)PTR_0000e694,
                                &local_24,&local_28,1);
    if ((iVar3 == 0) && (local_24 != 0)) {
      *(int *)(param_1 + 0x18) = local_24;
      *(int *)(param_1 + 0x80) = local_24 + 0x20;
      *(int *)(param_1 + 0x7c) = local_24 + 0x1c;
      *(undefined4 *)(local_24 + 0x1c) = 0;
    }
    uVar2 = 0x310;
    if (*(int *)(param_1 + 0x84) == 0) {
      uVar2 = 0x210;
    }
    *(undefined4 *)(param_1 + 0x90) = uVar2;
    *(undefined4 *)(param_1 + 0x94) = 0;
    uVar4 = ((int (*)())__SetDestination)(param_1,0,0);
    _memcpy((void *)(param_1 + 0x1c),(void *)(param_1 + 0x4c),0x30);
  }
  return uVar4;
}

/* __AllocateSurface @ 0x2750 (1420 bytes) */
longlong __AllocateSurface(param_1, param_2, param_3, param_4)
  int param_1;
  uint param_2;
  uint *param_3;
  undefined4 param_4;
{
  uint uVar1;
  longlong lVar2;
  longlong lVar3;
  int iVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  int iVar8;
  size_t sVar9;
  int iVar10;
  ulonglong uVar11;
  uint uVar12;
  size_t sVar13;
  void *pvVar14;
  void *pvVar15;
  uint uVar16;
  ushort uVar18;
  int *piVar17;
  uint local_78;
  undefined4 local_74;
  uint local_70;
  int *local_6c;
  undefined4 local_68;
  uint local_64;
  uint local_60;
  uint local_5c;
  undefined4 *puVar4;
  
  puVar4 = _calloc(1,0x3c);
  lVar2 = (longlong)(int)puVar4;
  if ((param_2 & 1) == 0) {
    if ((param_2 & 8) == 0) {
      iVar5 = ((int (*)())__DecodePixelFormat)(param_3[1],lVar2 + 0x30,lVar2 + 0x34,lVar2 + 0x28,&local_70,
                                  lVar2 + 0x2c,0,lVar2 + 0x38);
      if (iVar5 == 0) goto LAB_00002cb0;
      uVar1 = param_3[6];
      uVar16 = puVar4[10];
      iVar8 = 1;
      *(undefined2 *)((int)puVar4 + 0xe) = 0;
      *(undefined2 *)(puVar4 + 3) = 0;
      puVar4[7] = uVar1 / uVar16;
      uVar1 = param_3[4];
      *(short *)(puVar4 + 4) = (short)uVar1;
      uVar12 = param_3[5];
      puVar4[5] = uVar1;
      *(short *)((int)puVar4 + 0x12) = (short)uVar12;
      puVar4[6] = uVar12;
      uVar7 = (longlong)(int)uVar16 * (longlong)(int)(uVar1 * uVar12) + 3U & 0xfffffffc;
      uVar6 = uVar7 >> 2;
      iVar5 = (int)uVar6;
      local_60 = (int)uVar7 + 0xfffU & 0xfffff000;
      while (0x3fff < uVar6) {
        uVar6 = uVar6 >> 1;
        iVar5 = (int)uVar6;
        iVar8 = iVar8 << 1;
      }
      local_74 = 2;
      local_64 = ((iVar5 + 0xd) * iVar8 + 0x27U & 0x3ffffff8) << 2;
      lVar3 = _io_connect_method_scalarI_scalarO
                        (*(undefined4 *)(param_1 + 0xc),9,&local_64,2,&local_6c,&local_74);
      if (lVar3 == 0) {
        *puVar4 = local_68;
        uVar1 = param_3[4];
        uVar12 = param_3[5];
        uVar7 = (ulonglong)uVar12;
        pvVar14 = (void *)*param_3;
        sVar13 = uVar16 * uVar1;
        uVar6 = ((longlong)(int)uVar16 * (longlong)(int)(uVar1 * uVar12) & 0xffffffffU) >> 2;
        if (uVar6 < 0x4000) {
          iVar5 = 1;
        }
        else {
          iVar5 = 1;
          uVar11 = uVar7;
          do {
            uVar6 = uVar6 >> 1;
            uVar7 = uVar7 >> 1;
            uVar11 = uVar11 >> 1;
            uVar12 = (uint)uVar11;
            iVar5 = iVar5 << 1;
          } while (0x3fff < uVar6);
        }
        iVar8 = (int)uVar6 + 0xd;
        sVar9 = 0x20;
        if (0x1f < sVar13) {
          sVar9 = sVar13;
        }
        *local_6c = iVar8 * iVar5 + 8;
        local_6c[6] = iVar8;
        local_6c[7] = iVar5;
        local_6c[5] = sVar9 * (int)uVar7;
        local_6c[0x20] = 0x1393;
        local_6c[0x21] = 10;
        local_6c[0x22] = 0x5c8;
        piVar17 = local_6c + 0x24;
        local_6c[0x23] = 0x20000;
        iVar8 = 3;
        if (local_70 != 3) {
          iVar8 = 0;
        }
        if (iVar5 != 0) {
          iVar10 = 0;
          do {
            *piVar17 = 0x5cb;
            piVar17[1] = iVar8;
            piVar17[2] = 0x51b;
            piVar17[3] = (local_70 & 0xf) << 8 | 0x53cc30f2;
            piVar17[4] = 0x10501;
            piVar17[5] = 0;
            piVar17[6] = sVar9;
            piVar17[7] = 0x5c0;
            piVar17[8] = 0;
            piVar17[9] = 0x1050e;
            piVar17[10] = 0;
            piVar17[0xb] = uVar1 | (uint)(uVar7 << 0x10);
            piVar17[0xc] = (uint)((uVar6 - 1 & 0xffffffff) << 0x10) | 0x85f0;
            piVar17 = piVar17 + 0xd;
            if (uVar12 != 0) {
              uVar16 = 0;
              pvVar15 = pvVar14;
              do {
                uVar16 = uVar16 + 1;
                pvVar14 = (void *)((int)pvVar15 + sVar13);
                _bcopy(pvVar15,piVar17,sVar13);
                piVar17 = (int *)((int)piVar17 + (sVar13 & 0xfffffffc));
                pvVar15 = pvVar14;
              } while (uVar16 != uVar12);
            }
            iVar10 = iVar10 + 1;
          } while (iVar5 != iVar10);
        }
        *piVar17 = 0xd0b;
        piVar17[1] = 5;
        piVar17[2] = 0x5c8;
        piVar17[3] = 0x10000;
        lVar3 = 0;
        goto LAB_00002ce0;
      }
    }
    else {
      uVar18 = (ushort)param_3[6] & 0x3f;
      if (((param_3[6] & 0x3f) == 0) &&
         (iVar5 = ((int (*)())__DecodePixelFormat)(param_3[1],lVar2 + 0x30,lVar2 + 0x34,lVar2 + 0x28,0,
                                      lVar2 + 0x2c,0,lVar2 + 0x38), iVar5 != 0)) {
        uVar1 = param_3[6];
        *(ushort *)((int)puVar4 + 0xe) = uVar18;
        *(ushort *)(puVar4 + 3) = uVar18;
        puVar4[7] = uVar1 / (uint)puVar4[10];
        uVar16 = param_3[4];
        *(short *)(puVar4 + 4) = (short)uVar16;
        local_5c = param_3[5];
        puVar4[5] = uVar16;
        *(short *)((int)puVar4 + 0x12) = (short)local_5c;
        puVar4[6] = local_5c;
        local_74 = 1;
        local_5c = local_5c * uVar1;
        local_60 = *param_3;
        local_64 = param_2;
        lVar3 = _io_connect_method_scalarI_scalarO
                          (*(undefined4 *)(param_1 + 0xc),8,&local_64,3,lVar2,&local_74);
        if (lVar3 == 0) goto LAB_00002ce0;
      }
      else {
LAB_00002cb0:
        lVar3 = -0x1ffffd39;
      }
    }
  }
  else {
    puVar4[2] = param_4;
    param_3[10] = (uint)puVar4;
    lVar3 = ((int (*)())__SetDestination)(param_1,1,param_3);
    if (lVar3 == 0) {
      if ((param_2 & 2) != 0) {
        local_60 = param_3[4];
        local_5c = param_3[5];
        local_74 = 0;
        local_64 = param_2;
        lVar3 = _io_connect_method_scalarI_scalarO
                          (*(undefined4 *)(param_1 + 0xc),4,&local_64,3,0,&local_74);
        if (lVar3 != 0) goto LAB_00002cb8;
      }
      if (((param_2 & 0x10) != 0) &&
         (iVar5 = ((int (*)())__DecodePixelFormat)(param_3[1],lVar2 + 0x30,lVar2 + 0x34,lVar2 + 0x28,0,
                                      lVar2 + 0x2c,&local_78,lVar2 + 0x38), iVar5 != 0)) {
        uVar1 = param_3[4] * puVar4[10] + 0x7f & 0xffffff80;
        local_60 = (param_3[5] + 1) * uVar1;
        param_3[6] = uVar1;
        local_64 = local_78;
        local_74 = 2;
        iVar5 = _io_connect_method_scalarI_scalarO
                          (*(undefined4 *)(param_1 + 0xc),10,&local_64,2,&local_6c,&local_74);
        if (iVar5 == 0) {
          lVar3 = 0;
          *puVar4 = local_68;
          uVar1 = param_3[6];
          *(undefined2 *)((int)puVar4 + 0xe) = 0;
          *(undefined2 *)(puVar4 + 3) = 0;
          puVar4[7] = uVar1 / (uint)puVar4[10];
          uVar1 = param_3[4];
          *(short *)(puVar4 + 4) = (short)uVar1;
          uVar16 = param_3[5];
          puVar4[5] = uVar1;
          *(short *)((int)puVar4 + 0x12) = (short)uVar16;
          puVar4[6] = uVar16;
          puVar4[1] = local_6c;
          param_3[9] = 2;
          goto LAB_00002ce0;
        }
      }
      lVar3 = 0;
      goto LAB_00002ce0;
    }
  }
LAB_00002cb8:
  _free(puVar4);
  puVar4 = (undefined4 *)0x0;
LAB_00002ce0:
  param_3[10] = (uint)puVar4;
  return lVar3;
}

/* _radeon3DCopySetup @ 0x2d10 (2048 bytes) */
longlong _radeon3DCopySetup(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  undefined8 param_1;
  int param_2;
  int param_3;
  longlong param_4;
  int param_5;
  ulonglong param_6;
  int param_7;
  int param_8;
{
  int iVar1;
  int iVar2;
  ulonglong uVar3;
  uint uVar4;
  uint uVar5;
  
  if (*(uint *)(param_3 + 0x2c) == 0) {
    uVar5 = (uint)param_4;
    if (uVar5 == 6) {
      uVar3 = 0xfffffffffffffff9;
      uVar5 = 0xc;
    }
    else if (uVar5 == 3) {
      uVar3 = 0xfffffffffffffff8;
      uVar5 = 0xb;
    }
    else {
      uVar5 = uVar5 & 0x1f;
      uVar3 = param_4 - 0x13;
    }
  }
  else {
    uVar3 = (ulonglong)
            (*(uint *)(&DAT_0000e018 + (*(uint *)(param_3 + 0x2c) & 0xff) * 0x1c) >> 0x13) & 0x1f;
    uVar5 = (uint)uVar3;
    uVar3 = uVar3 - 0x13;
  }
  *(undefined **)(param_2 + (int)((param_6 & 0xffffffff) << 2)) = ((unsigned char *)0x000010ea);
  *(undefined4 *)(param_2 + (int)((param_6 + 1 & 0xffffffff) << 2)) = 0x2da49525;
  *(undefined4 *)(param_2 + (int)((param_6 + 2 & 0xffffffff) << 2)) = 0x10fa;
  *(undefined4 *)(param_2 + (int)((param_6 + 3 & 0xffffffff) << 2)) = 0xffffff;
  *(undefined **)(param_2 + (int)((param_6 + 4 & 0xffffffff) << 2)) = ((unsigned char *)0x00001004);
  *(undefined4 *)(param_2 + (int)((param_6 + 5 & 0xffffffff) << 2)) = 0x66666666;
  *(undefined **)(param_2 + (int)((param_6 + 6 & 0xffffffff) << 2)) = ((unsigned char *)0x00001005);
  *(undefined4 *)(param_2 + (int)((param_6 + 7 & 0xffffffff) << 2)) = 0x6666666;
  *(undefined4 *)(param_2 + (int)((param_6 + 8 & 0xffffffff) << 2)) = 0x13c1;
  *(undefined4 *)(param_2 + (int)((param_6 + 9 & 0xffffffff) << 2)) = 0;
  *(undefined4 *)(param_2 + (int)((param_6 + 10 & 0xffffffff) << 2)) = 0x850;
  *(undefined4 *)(param_2 + (int)((param_6 + 0xb & 0xffffffff) << 2)) = 0x100;
  *(undefined4 *)(param_2 + (int)((param_6 + 0xc & 0xffffffff) << 2)) = 0x887;
  *(undefined4 *)(param_2 + (int)((param_6 + 0xd & 0xffffffff) << 2)) = 0x1c000;
  *(undefined4 *)(param_2 + (int)((param_6 + 0xe & 0xffffffff) << 2)) = 0x82c;
  *(undefined4 *)(param_2 + (int)((param_6 + 0xf & 0xffffffff) << 2)) = 0;
  *(undefined **)(param_2 + (int)((param_6 + 0x10 & 0xffffffff) << 2)) = ((unsigned char *)0x000010ae);
  *(undefined4 *)(param_2 + (int)((param_6 + 0x11 & 0xffffffff) << 2)) = 0;
  *(undefined **)(param_2 + (int)((param_6 + 0x12 & 0xffffffff) << 2)) = ((unsigned char *)0x00001002);
  *(undefined4 *)(param_2 + (int)((param_6 + 0x13 & 0xffffffff) << 2)) = 0;
  *(undefined4 *)(param_2 + (int)((param_6 + 0x14 & 0xffffffff) << 2)) = 0x824;
  *(undefined4 *)(param_2 + (int)((param_6 + 0x15 & 0xffffffff) << 2)) = 1;
  *(undefined4 *)(param_2 + (int)((param_6 + 0x16 & 0xffffffff) << 2)) = 0x825;
  *(undefined4 *)(param_2 + (int)((param_6 + 0x17 & 0xffffffff) << 2)) = 2;
  *(undefined4 *)(param_2 + (int)((param_6 + 0x18 & 0xffffffff) << 2)) = 0x82d;
  *(undefined4 *)(param_2 + (int)((param_6 + 0x19 & 0xffffffff) << 2)) = 3;
  *(undefined4 *)(param_2 + (int)((param_6 + 0x1a & 0xffffffff) << 2)) = 0x854;
  *(undefined4 *)(param_2 + (int)((param_6 + 0x1b & 0xffffffff) << 2)) = 0x26010006;
  *(undefined4 *)(param_2 + (int)((param_6 + 0x1c & 0xffffffff) << 2)) = 0x878;
  *(undefined4 *)(param_2 + (int)((param_6 + 0x1d & 0xffffffff) << 2)) = 0xf688f688;
  *(undefined4 *)(param_2 + (int)((param_6 + 0x1e & 0xffffffff) << 2)) = 0x13c0;
  *(undefined4 *)(param_2 + (int)((param_6 + 0x1f & 0xffffffff) << 2)) = 0;
  *(undefined4 *)((int)((param_6 + 0x20 & 0xffffffff) << 2) + param_2) = 0x13c1;
  *(undefined4 *)((int)((param_6 + 0x21 & 0xffffffff) << 2) + param_2) = 0;
  *(undefined4 *)((int)((param_6 + 0x22 & 0xffffffff) << 2) + param_2) = 0x12f5;
  *(undefined4 *)((int)((param_6 + 0x23 & 0xffffffff) << 2) + param_2) = 0;
  *(undefined4 *)(param_2 + (int)((param_6 + 0x24 & 0xffffffff) << 2)) = 0x12f0;
  *(undefined4 *)(param_2 + (int)((param_6 + 0x25 & 0xffffffff) << 2)) = 0;
  *(undefined **)(param_2 + (int)((param_6 + 0x26 & 0xffffffff) << 2)) = ((unsigned char *)0x000010a2);
  *(undefined4 *)(param_2 + (int)((param_6 + 0x27 & 0xffffffff) << 2)) = 0;
  *(undefined4 *)(param_2 + (int)((param_6 + 0x28 & 0xffffffff) << 2)) = 0x1381;
  *(undefined4 *)(param_2 + (int)((param_6 + 0x29 & 0xffffffff) << 2)) = 0;
  *(undefined **)(param_2 + (int)((param_6 + 0x2a & 0xffffffff) << 2)) = ((unsigned char *)0x0000109e);
  *(undefined4 *)(param_2 + (int)((param_6 + 0x2b & 0xffffffff) << 2)) = 5;
  *(undefined **)(param_2 + (int)((param_6 + 0x2c & 0xffffffff) << 2)) = ((unsigned char *)0x00001041);
  *(undefined4 *)(param_2 + (int)((param_6 + 0x2d & 0xffffffff) << 2)) = 1;
  *(undefined **)(param_2 + (int)((param_6 + 0x2e & 0xffffffff) << 2)) = ((unsigned char *)0x00001094);
  *(undefined4 *)(param_2 + (int)((param_6 + 0x2f & 0xffffffff) << 2)) = 0;
  *(undefined **)(param_2 + (int)((param_6 + 0x30 & 0xffffffff) << 2)) = ((unsigned char *)0x00001095);
  *(undefined4 *)(param_2 + (int)((param_6 + 0x31 & 0xffffffff) << 2)) = 0x7803;
  *(undefined **)(param_2 + (int)((param_6 + 0x32 & 0xffffffff) << 2)) = ((unsigned char *)0x00001095);
  *(undefined4 *)(param_2 + (int)((param_6 + 0x33 & 0xffffffff) << 2)) = 0x2400000;
  *(undefined **)(param_2 + (int)((param_6 + 0x34 & 0xffffffff) << 2)) = ((unsigned char *)0x00001095);
  *(undefined4 *)(param_2 + (int)((param_6 + 0x35 & 0xffffffff) << 2)) = 0xe400e400;
  *(undefined **)(param_2 + (int)((param_6 + 0x36 & 0xffffffff) << 2)) = ((unsigned char *)0x00001095);
  *(undefined4 *)(param_2 + (int)((param_6 + 0x37 & 0xffffffff) << 2)) = 0;
  *(undefined **)(param_2 + (int)((param_6 + 0x38 & 0xffffffff) << 2)) = ((unsigned char *)0x00001095);
  *(undefined4 *)(param_2 + (int)((param_6 + 0x39 & 0xffffffff) << 2)) = 0;
  *(undefined **)(param_2 + (int)((param_6 + 0x3a & 0xffffffff) << 2)) = ((unsigned char *)0x00001095);
  *(undefined4 *)(param_2 + (int)((param_6 + 0x3b & 0xffffffff) << 2)) = 0;
  *(undefined **)(param_2 + (int)((param_6 + 0x3c & 0xffffffff) << 2)) = ((unsigned char *)0x00001095);
  *(undefined4 *)(param_2 + (int)((param_6 + 0x3d & 0xffffffff) << 2)) = 0x78105;
  *(undefined **)(param_2 + (int)((param_6 + 0x3e & 0xffffffff) << 2)) = ((unsigned char *)0x00001095);
  *(undefined4 *)(param_2 + (int)((param_6 + 0x3f & 0xffffffff) << 2)) = 0;
  *(undefined **)(param_2 + (int)((param_6 + 0x40 & 0xffffffff) << 2)) = ((unsigned char *)0x00001095);
  *(undefined4 *)(param_2 + (int)((param_6 + 0x41 & 0xffffffff) << 2)) = 0;
  *(undefined **)(param_2 + (int)((param_6 + 0x42 & 0xffffffff) << 2)) = ((unsigned char *)0x00001095);
  *(undefined4 *)(param_2 + (int)((param_6 + 0x43 & 0xffffffff) << 2)) = 0xdb0220;
  *(undefined **)(param_2 + (int)((param_6 + 0x44 & 0xffffffff) << 2)) = ((unsigned char *)0x00001095);
  *(undefined4 *)(param_2 + (int)((param_6 + 0x45 & 0xffffffff) << 2)) = 0xc0c000;
  *(undefined **)(param_2 + (int)((param_6 + 0x46 & 0xffffffff) << 2)) = ((unsigned char *)0x00001095);
  *(undefined4 *)(param_2 + (int)((param_6 + 0x47 & 0xffffffff) << 2)) = 0x20490000;
  *(undefined **)(param_2 + (int)((param_6 + 0x48 & 0xffffffff) << 2)) = ((unsigned char *)0x00001189);
  *(undefined4 *)(param_2 + (int)((param_6 + 0x49 & 0xffffffff) << 2)) = 0;
  *(undefined **)(param_2 + (int)((param_6 + 0x4a & 0xffffffff) << 2)) = ((unsigned char *)0x00001181);
  *(undefined4 *)(param_2 + (int)((param_6 + 0x4b & 0xffffffff) << 2)) = 1;
  *(undefined **)(param_2 + (int)((param_6 + 0x4c & 0xffffffff) << 2)) = ((unsigned char *)0x0000118d);
  *(undefined4 *)(param_2 + (int)((param_6 + 0x4d & 0xffffffff) << 2)) = 0x10000;
  *(undefined **)(param_2 + (int)((param_6 + 0x4e & 0xffffffff) << 2)) = ((unsigned char *)0x0000118e);
  *(undefined4 *)(param_2 + (int)((param_6 + 0x4f & 0xffffffff) << 2)) = 0;
  *(undefined **)(param_2 + (int)((param_6 + 0x50 & 0xffffffff) << 2)) = ((unsigned char *)0x0000118c);
  *(undefined4 *)(param_2 + (int)((param_6 + 0x51 & 0xffffffff) << 2)) = 0x10000;
  *(undefined **)(param_2 + (int)((param_6 + 0x52 & 0xffffffff) << 2)) = ((unsigned char *)0x000011a9);
  if (2 < uVar3) {
    *(undefined4 *)(param_2 + (int)((param_6 + 0x53 & 0xffffffff) << 2)) = 0x6c01;
  }
  else {
    *(undefined4 *)(param_2 + (int)((param_6 + 0x53 & 0xffffffff) << 2)) = 0x1b01;
  }
  *(undefined **)(param_2 + (int)((param_6 + 0x54 & 0xffffffff) << 2)) = ((unsigned char *)0x000011aa);
  *(undefined4 *)(param_2 + (int)((param_6 + 0x55 & 0xffffffff) << 2)) = 0xf;
  *(undefined **)(param_2 + (int)((param_6 + 0x56 & 0xffffffff) << 2)) = ((unsigned char *)0x000011ab);
  *(undefined4 *)(param_2 + (int)((param_6 + 0x57 & 0xffffffff) << 2)) = 0xf;
  *(undefined1 **)(param_2 + (int)((param_6 + 0x58 & 0xffffffff) << 2)) = ((unsigned char *)0x000011ac);
  *(undefined4 *)(param_2 + (int)((param_6 + 0x59 & 0xffffffff) << 2)) = 0xf;
  *(undefined **)(param_2 + (int)((param_6 + 0x5a & 0xffffffff) << 2)) = ((unsigned char *)0x000010c0);
  *(undefined4 *)(param_2 + (int)((param_6 + 0x5b & 0xffffffff) << 2)) = 0x40002;
  *(undefined **)(param_2 + (int)((param_6 + 0x5c & 0xffffffff) << 2)) = ((unsigned char *)0x000010c1);
  *(undefined4 *)(param_2 + (int)((param_6 + 0x5d & 0xffffffff) << 2)) = 0;
  *(undefined **)(param_2 + (int)((param_6 + 0x5e & 0xffffffff) << 2)) = ((unsigned char *)0x000010c8);
  *(undefined4 *)(param_2 + (int)((param_6 + 0x5f & 0xffffffff) << 2)) = 0x10;
  *(undefined **)(param_2 + (int)((param_6 + 0x60 & 0xffffffff) << 2)) = ((unsigned char *)0x0000101d);
  *(undefined4 *)(param_2 + (int)((param_6 + 0x61 & 0xffffffff) << 2)) = 0x280c2040;
  *(undefined **)(param_2 + (int)((param_6 + 0x62 & 0xffffffff) << 2)) = ((unsigned char *)0x00001040);
  *(undefined4 *)(param_2 + (int)((param_6 + 99 & 0xffffffff) << 2)) = 0;
  *(undefined4 *)(param_2 + (int)((param_6 + 100 & 0xffffffff) << 2)) = 0x1100;
  uVar4 = 0x1492;
  if (param_5 == 0) {
    uVar4 = 0xa92;
  }
  *(uint *)(param_2 + (int)((param_6 + 0x65 & 0xffffffff) << 2)) = uVar4 | 0x2000;
  *(undefined **)(param_2 + (int)((param_6 + 0x66 & 0xffffffff) << 2)) = ((unsigned char *)0x00001120);
  iVar1 = param_7;
  if (param_7 == 0) {
    iVar1 = (int)*(short *)(param_3 + 4);
  }
  iVar2 = param_8;
  if (param_8 == 0) {
    iVar2 = (int)*(short *)(param_3 + 6);
  }
  *(uint *)(param_2 + (int)((param_6 + 0x67 & 0xffffffff) << 2)) =
       iVar1 - 1U & 0x7ff | (iVar2 + -1) * 0x800 & 0x3ff800U | 0x80000000;
  *(undefined **)(param_2 + (int)((param_6 + 0x68 & 0xffffffff) << 2)) = ((unsigned char *)0x00001130);
  if (2 < uVar3) {
    uVar4 = 0;
  }
  else {
    uVar4 = 0x400000;
  }
  *(uint *)(param_2 + (int)((param_6 + 0x69 & 0xffffffff) << 2)) = uVar4 | uVar5 | 0x53000;
  *(undefined **)(param_2 + (int)((param_6 + 0x6a & 0xffffffff) << 2)) = ((unsigned char *)0x00001140);
  if (param_7 == 0) {
    param_7 = (int)*(short *)(param_3 + 4);
  }
  if (param_8 == 0) {
    param_8 = (int)*(short *)(param_3 + 6);
  }
  *(uint *)(param_2 + (int)((param_6 + 0x6b & 0xffffffff) << 2)) =
       (param_8 + -1) * 0x20 & 0x10000U |
       (param_7 + -1) * 0x10 & 0x8000U | *(int *)(param_3 + 0x10) - 1U & 0x3fff;
  *(undefined4 *)(param_2 + (int)((param_6 + 0x6c & 0xffffffff) << 2)) = 0x10f4;
  *(undefined4 *)(param_2 + (int)((param_6 + 0x6d & 0xffffffff) << 2)) = 0xffff;
  return param_6 + 0x6e;
}

/* _radeon3DFillSetup @ 0x3540 (2020 bytes) */
longlong _radeon3DFillSetup(param_1, param_2, param_3, param_4)
  int param_1;
  ulonglong param_2;
  uint param_3;
  int param_4;
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  
  *(undefined4 *)(param_1 + (int)((param_2 & 0xffffffff) << 2)) = 0x850;
  *(undefined4 *)(param_1 + (int)((param_2 + 1 & 0xffffffff) << 2)) = 0x100;
  *(undefined4 *)(param_1 + (int)((param_2 + 2 & 0xffffffff) << 2)) = 0x887;
  *(undefined4 *)(param_1 + (int)((param_2 + 3 & 0xffffffff) << 2)) = 0x1c000;
  *(undefined4 *)(param_1 + (int)((param_2 + 4 & 0xffffffff) << 2)) = 0x82c;
  *(undefined4 *)(param_1 + (int)((param_2 + 5 & 0xffffffff) << 2)) = 0;
  *(undefined **)(param_1 + (int)((param_2 + 6 & 0xffffffff) << 2)) = ((unsigned char *)0x00001002);
  *(undefined4 *)(param_1 + (int)((param_2 + 7 & 0xffffffff) << 2)) = 0;
  *(undefined4 *)(param_1 + (int)((param_2 + 8 & 0xffffffff) << 2)) = 0x824;
  *(undefined4 *)(param_1 + (int)((param_2 + 9 & 0xffffffff) << 2)) = 1;
  *(undefined4 *)(param_1 + (int)((param_2 + 10 & 0xffffffff) << 2)) = 0x825;
  *(undefined4 *)(param_1 + (int)((param_2 + 0xb & 0xffffffff) << 2)) = 4;
  *(undefined4 *)(param_1 + (int)((param_2 + 0xc & 0xffffffff) << 2)) = 0x82d;
  *(undefined4 *)(param_1 + (int)((param_2 + 0xd & 0xffffffff) << 2)) = 3;
  *(undefined4 *)(param_1 + (int)((param_2 + 0xe & 0xffffffff) << 2)) = 0x854;
  *(undefined4 *)(param_1 + (int)((param_2 + 0xf & 0xffffffff) << 2)) = 0x26000001;
  *(undefined4 *)(param_1 + (int)((param_2 + 0x10 & 0xffffffff) << 2)) = 0x878;
  *(undefined4 *)(param_1 + (int)((param_2 + 0x11 & 0xffffffff) << 2)) = 0xfb24fb08;
  *(undefined **)(param_1 + (int)((param_2 + 0x12 & 0xffffffff) << 2)) = ((unsigned char *)0x000010a2);
  *(undefined4 *)(param_1 + (int)((param_2 + 0x13 & 0xffffffff) << 2)) = 0;
  *(undefined4 *)(param_1 + (int)((param_2 + 0x14 & 0xffffffff) << 2)) = 0x1381;
  *(undefined4 *)(param_1 + (int)((param_2 + 0x15 & 0xffffffff) << 2)) = 0;
  *(undefined **)(param_1 + (int)((param_2 + 0x16 & 0xffffffff) << 2)) = ((unsigned char *)0x0000109e);
  *(undefined4 *)(param_1 + (int)((param_2 + 0x17 & 0xffffffff) << 2)) = 5;
  *(undefined4 *)(param_1 + (int)((param_2 + 0x18 & 0xffffffff) << 2)) = 0x1383;
  *(undefined4 *)(param_1 + (int)((param_2 + 0x19 & 0xffffffff) << 2)) = 0xf;
  *(undefined **)(param_1 + (int)((param_2 + 0x1a & 0xffffffff) << 2)) = ((unsigned char *)0x00001004);
  *(undefined4 *)(param_1 + (int)((param_2 + 0x1b & 0xffffffff) << 2)) = 0x66666666;
  *(undefined **)(param_1 + (int)((param_2 + 0x1c & 0xffffffff) << 2)) = ((unsigned char *)0x00001005);
  *(undefined4 *)(param_1 + (int)((param_2 + 0x1d & 0xffffffff) << 2)) = 0x66666666;
  *(undefined **)(param_1 + (int)((param_2 + 0x1e & 0xffffffff) << 2)) = ((unsigned char *)0x000010ae);
  *(undefined4 *)(param_1 + (int)((param_2 + 0x1f & 0xffffffff) << 2)) = 0;
  *(undefined **)(param_1 + (int)((param_2 + 0x20 & 0xffffffff) << 2)) = ((unsigned char *)0x000010ea);
  *(undefined4 *)(param_1 + (int)((param_2 + 0x21 & 0xffffffff) << 2)) = 0x2da49525;
  *(undefined4 *)(param_1 + (int)((param_2 + 0x22 & 0xffffffff) << 2)) = 0x10fa;
  *(undefined4 *)(param_1 + (int)((param_2 + 0x23 & 0xffffffff) << 2)) = 0xffffff;
  *(undefined4 *)(param_1 + (int)((param_2 + 0x24 & 0xffffffff) << 2)) = 0x10f4;
  *(undefined4 *)(param_1 + (int)((param_2 + 0x25 & 0xffffffff) << 2)) = 0xffff;
  *(undefined4 *)(param_1 + (int)((param_2 + 0x26 & 0xffffffff) << 2)) = 0x10f8;
  *(undefined4 *)(param_1 + (int)((param_2 + 0x27 & 0xffffffff) << 2)) = 0;
  *(undefined4 *)(param_1 + (int)((param_2 + 0x28 & 0xffffffff) << 2)) = 0x10f9;
  *(uint *)(param_1 + (int)((param_2 + 0x29 & 0xffffffff) << 2)) =
       *(uint *)(param_4 + 0x54) & 0x1fff | (*(uint *)(param_4 + 0x58) & 0x1fff) << 0xd;
  *(undefined4 *)(param_1 + (int)((param_2 + 0x2a & 0xffffffff) << 2)) = 0x13c0;
  *(undefined4 *)(param_1 + (int)((param_2 + 0x2b & 0xffffffff) << 2)) = 0;
  *(undefined4 *)(param_1 + (int)((param_2 + 0x2c & 0xffffffff) << 2)) = 0x13c1;
  *(undefined4 *)(param_1 + (int)((param_2 + 0x2d & 0xffffffff) << 2)) = 0;
  *(undefined **)(param_1 + (int)((param_2 + 0x2e & 0xffffffff) << 2)) = ((unsigned char *)0x000010c0);
  *(undefined4 *)(param_1 + (int)((param_2 + 0x2f & 0xffffffff) << 2)) = 4;
  *(undefined **)(param_1 + (int)((param_2 + 0x30 & 0xffffffff) << 2)) = ((unsigned char *)0x000010c1);
  *(undefined4 *)(param_1 + (int)((param_2 + 0x31 & 0xffffffff) << 2)) = 0;
  *(undefined **)(param_1 + (int)((param_2 + 0x32 & 0xffffffff) << 2)) = ((unsigned char *)0x000010c8);
  *(undefined4 *)(param_1 + (int)((param_2 + 0x33 & 0xffffffff) << 2)) = 0x10;
  *(undefined **)(param_1 + (int)((param_2 + 0x34 & 0xffffffff) << 2)) = ((unsigned char *)0x0000101d);
  *(undefined4 *)(param_1 + (int)((param_2 + 0x35 & 0xffffffff) << 2)) = 0xc2040;
  *(undefined **)(param_1 + (int)((param_2 + 0x36 & 0xffffffff) << 2)) = ((unsigned char *)0x00001041);
  *(undefined4 *)(param_1 + (int)((param_2 + 0x37 & 0xffffffff) << 2)) = 0;
  *(undefined **)(param_1 + (int)((param_2 + 0x38 & 0xffffffff) << 2)) = ((unsigned char *)0x00001040);
  *(undefined4 *)(param_1 + (int)((param_2 + 0x39 & 0xffffffff) << 2)) = 0;
  if (*(int *)(param_4 + 0x70) == 3) {
    fVar1 = (float)((double)CONCAT44(0x43300000,param_3 & 0x1f) - DOUBLE_0000cfd8) / FLOAT_0000cff8;
    fVar3 = (float)((double)CONCAT44(0x43300000,param_3 >> 10 & 0x1f) - DOUBLE_0000cfd8) /
            FLOAT_0000cff8;
    fVar2 = (float)((double)CONCAT44(0x43300000,param_3 >> 5 & 0x1f) - DOUBLE_0000cfd8) /
            FLOAT_0000cff8;
    fVar4 = (float)((double)CONCAT44(0x43300000,param_3 >> 0xf & 1) - DOUBLE_0000cfd8);
  }
  else {
    fVar1 = (float)((double)CONCAT44(0x43300000,param_3 & 0xff) - DOUBLE_0000cfd8) / FLOAT_0000cffc;
    fVar4 = (float)((double)CONCAT44(0x43300000,param_3 >> 0x18) - DOUBLE_0000cfd8) / FLOAT_0000cffc
    ;
    fVar3 = (float)((double)CONCAT44(0x43300000,param_3 >> 0x10 & 0xff) - DOUBLE_0000cfd8) /
            FLOAT_0000cffc;
    fVar2 = (float)((double)CONCAT44(0x43300000,param_3 >> 8 & 0xff) - DOUBLE_0000cfd8) /
            FLOAT_0000cffc;
  }
  *(undefined **)(param_1 + (int)((param_2 + 0x3a & 0xffffffff) << 2)) = ((unsigned char *)0x00001094);
  *(undefined4 *)(param_1 + (int)((param_2 + 0x3b & 0xffffffff) << 2)) = 0x10000;
  *(undefined **)(param_1 + (int)((param_2 + 0x3c & 0xffffffff) << 2)) = ((unsigned char *)0x00001095);
  *(float *)(param_1 + (int)((param_2 + 0x3d & 0xffffffff) << 2)) = fVar3;
  *(undefined **)(param_1 + (int)((param_2 + 0x3e & 0xffffffff) << 2)) = ((unsigned char *)0x00001095);
  *(float *)(param_1 + (int)((param_2 + 0x3f & 0xffffffff) << 2)) = fVar2;
  *(undefined **)(param_1 + (int)((param_2 + 0x40 & 0xffffffff) << 2)) = ((unsigned char *)0x00001095);
  *(float *)(param_1 + (int)((param_2 + 0x41 & 0xffffffff) << 2)) = fVar1;
  *(undefined **)(param_1 + (int)((param_2 + 0x42 & 0xffffffff) << 2)) = ((unsigned char *)0x00001095);
  *(float *)(param_1 + (int)((param_2 + 0x43 & 0xffffffff) << 2)) = fVar4;
  *(undefined **)(param_1 + (int)((param_2 + 0x44 & 0xffffffff) << 2)) = ((unsigned char *)0x00001094);
  *(undefined4 *)(param_1 + (int)((param_2 + 0x45 & 0xffffffff) << 2)) = 0;
  *(undefined **)(param_1 + (int)((param_2 + 0x46 & 0xffffffff) << 2)) = ((unsigned char *)0x00001095);
  *(undefined4 *)(param_1 + (int)((param_2 + 0x47 & 0xffffffff) << 2)) = 0x78105;
  *(undefined **)(param_1 + (int)((param_2 + 0x48 & 0xffffffff) << 2)) = ((unsigned char *)0x00001095);
  *(undefined4 *)(param_1 + (int)((param_2 + 0x49 & 0xffffffff) << 2)) = 0x100;
  *(undefined **)(param_1 + (int)((param_2 + 0x4a & 0xffffffff) << 2)) = ((unsigned char *)0x00001095);
  *(undefined4 *)(param_1 + (int)((param_2 + 0x4b & 0xffffffff) << 2)) = 0x100;
  *(undefined **)(param_1 + (int)((param_2 + 0x4c & 0xffffffff) << 2)) = ((unsigned char *)0x00001095);
  *(undefined4 *)(param_1 + (int)((param_2 + 0x4d & 0xffffffff) << 2)) = 0xdb0220;
  *(undefined **)(param_1 + (int)((param_2 + 0x4e & 0xffffffff) << 2)) = ((unsigned char *)0x00001095);
  *(undefined4 *)(param_1 + (int)((param_2 + 0x4f & 0xffffffff) << 2)) = 0xc0c000;
  *(undefined **)(param_1 + (int)((param_2 + 0x50 & 0xffffffff) << 2)) = ((unsigned char *)0x00001095);
  *(undefined4 *)(param_1 + (int)((param_2 + 0x51 & 0xffffffff) << 2)) = 0x20490000;
  *(undefined **)(param_1 + (int)((param_2 + 0x52 & 0xffffffff) << 2)) = ((unsigned char *)0x00001189);
  *(undefined4 *)(param_1 + (int)((param_2 + 0x53 & 0xffffffff) << 2)) = 0;
  *(undefined **)(param_1 + (int)((param_2 + 0x54 & 0xffffffff) << 2)) = ((unsigned char *)0x00001181);
  *(undefined4 *)(param_1 + (int)((param_2 + 0x55 & 0xffffffff) << 2)) = 1;
  *(undefined **)(param_1 + (int)((param_2 + 0x56 & 0xffffffff) << 2)) = ((unsigned char *)0x0000118d);
  *(undefined4 *)(param_1 + (int)((param_2 + 0x57 & 0xffffffff) << 2)) = 0;
  *(undefined **)(param_1 + (int)((param_2 + 0x58 & 0xffffffff) << 2)) = ((unsigned char *)0x0000118e);
  *(undefined4 *)(param_1 + (int)((param_2 + 0x59 & 0xffffffff) << 2)) = 0;
  *(undefined **)(param_1 + (int)((param_2 + 0x5a & 0xffffffff) << 2)) = ((unsigned char *)0x0000118c);
  *(undefined4 *)(param_1 + (int)((param_2 + 0x5b & 0xffffffff) << 2)) = 0;
  *(undefined **)(param_1 + (int)((param_2 + 0x5c & 0xffffffff) << 2)) = ((unsigned char *)0x000011a9);
  *(undefined4 *)(param_1 + (int)((param_2 + 0x5d & 0xffffffff) << 2)) = 0x1b01;
  *(undefined **)(param_1 + (int)((param_2 + 0x5e & 0xffffffff) << 2)) = ((unsigned char *)0x000011aa);
  *(undefined4 *)(param_1 + (int)((param_2 + 0x5f & 0xffffffff) << 2)) = 0xf;
  *(undefined **)(param_1 + (int)((param_2 + 0x60 & 0xffffffff) << 2)) = ((unsigned char *)0x000011ab);
  *(undefined4 *)(param_1 + (int)((param_2 + 0x61 & 0xffffffff) << 2)) = 0xf;
  *(undefined1 **)(param_1 + (int)((param_2 + 0x62 & 0xffffffff) << 2)) = ((unsigned char *)0x000011ac);
  *(undefined4 *)(param_1 + (int)((param_2 + 99 & 0xffffffff) << 2)) = 0xf;
  *(undefined4 *)(param_1 + (int)((param_2 + 100 & 0xffffffff) << 2)) = 0x12f0;
  *(undefined4 *)(param_1 + (int)((param_2 + 0x65 & 0xffffffff) << 2)) = 0;
  *(undefined4 *)(param_1 + (int)((param_2 + 0x66 & 0xffffffff) << 2)) = 0x12f5;
  *(undefined4 *)(param_1 + (int)((param_2 + 0x67 & 0xffffffff) << 2)) = 0;
  return param_2 + 0x68;
}

/* __Flush @ 0x3d30 (344 bytes) */
undefined8 __Flush(param_1, param_2)
  int param_1;
  ulonglong param_2;
{
  uint *puVar1;
  undefined *puVar2;
  int iVar3;
  undefined4 *puVar4;
  int local_28;
  int local_24 [9];
  
  puVar4 = *(undefined4 **)(param_1 + 0x80);
  if (puVar4 != (undefined4 *)(*(int *)(param_1 + 0x18) + 0x20)) {
    if ((param_2 & 0x10000) == 0) {
      iVar3 = *(int *)(param_1 + 0x8c);
    }
    else {
      iVar3 = 0;
      if (*(int *)(param_1 + 0x8c) != 0) {
        puVar1 = *(uint **)(param_1 + 0x7c);
        *puVar1 = (int)puVar4 - (int)puVar1 >> 2 | *puVar1;
        *(undefined4 **)(param_1 + 0x7c) = puVar4;
        *puVar4 = 0x2000000;
        puVar4 = puVar4 + 1;
        iVar3 = *(int *)(param_1 + 0x8c);
      }
    }
    local_24[0] = *(int *)(param_1 + 0x18);
    local_28 = 0;
    if (iVar3 == 0) {
      *puVar4 = 0x5c8;
      local_28 = 2;
      puVar4[1] = 0xc000;
      *(undefined4 *)(param_1 + 0x94) = 0;
    }
    puVar4[local_28] = 0x1000000;
    puVar2 = PTR_0000e694;
    puVar1 = *(uint **)(param_1 + 0x7c);
    *puVar1 = ((int)puVar4 - (int)puVar1 >> 2) + local_28 | *puVar1;
    iVar3 = _IOConnectMapMemory(*(undefined4 *)(param_1 + 0xc),0,*(undefined4 *)puVar2,local_24,
                                &local_28,1);
    if (iVar3 == 0) {
      *(undefined4 *)(local_24[0] + 0x1c) = 0;
      *(int *)(param_1 + 0x18) = local_24[0];
      iVar3 = local_24[0] + 0x20;
      *(int *)(param_1 + 0x7c) = local_24[0] + 0x1c;
    }
    else {
      iVar3 = 0;
      *(undefined4 *)(param_1 + 0x7c) = 0;
      *(undefined4 *)(param_1 + 0x18) = 0;
    }
    *(int *)(param_1 + 0x80) = iVar3;
  }
  return 0;
}

/* __WaitComplete @ 0x3ea0 (140 bytes) */
int __WaitComplete(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  undefined4 uStack0000001c;
  
  uStack0000001c = param_2;
  if (((*(int *)(param_1 + 0x80) != 0) && (*(int *)(param_1 + 0x8c) != 0)) &&
     (*(int *)(param_1 + 0x94) != 0)) {
    *(undefined4 *)(param_1 + 0x94) = 0;
    uStack0000001c = 1;
  }
  ((int (*)())__Flush)(param_1,0);
  _io_connect_method_scalarI_structureI(*(undefined4 *)(param_1 + 0xc),7,&STACKARG(0x1c),1,0,0);
  return;
}

/* __FreeSurface @ 0x3f30 (224 bytes) */
undefined8 __FreeSurface(param_1, param_2, param_3)
  int param_1;
  ulonglong param_2;
  int param_3;
{
  int iVar1;
  int *piVar2;
  undefined8 uVar3;
  
  iVar1 = *(int *)(param_3 + 0x28);
  if (iVar1 == 0) {
    uVar3 = 0xffffffffe00002d8;
  }
  else {
    if (((param_2 & 8) != 0) && (*(int *)(param_1 + 0x94) != 0)) {
      ((int (*)())__WaitComplete)(param_1,0x88);
      iVar1 = *(int *)(param_3 + 0x28);
    }
    uVar3 = 0;
    *(undefined4 *)(iVar1 + 8) = 0;
    if (param_3 == *(int *)(param_1 + 0x8c)) {
      uVar3 = ((int (*)())__SetDestination)(param_1,0,0);
    }
    piVar2 = *(int **)(param_3 + 0x28);
    if (*piVar2 != 0) {
      uVar3 = _io_connect_method_scalarI_structureI
                        (*(undefined4 *)(param_1 + 0xc),0xb,*piVar2,1,0,0);
      piVar2 = *(int **)(param_3 + 0x28);
    }
    piVar2[2] = 0;
    _free(*(void **)(param_3 + 0x28));
    *(undefined4 *)(param_3 + 0x28) = 0;
  }
  return uVar3;
}

/* _createTextureBuffer @ 0x4020 (584 bytes) */
undefined8 _createTextureBuffer(param_1, param_2, param_3, param_4)
  int param_1;
  longlong param_2;
  int param_3;
  int param_4;
{
  int iVar1;
  undefined8 uVar2;
  uint uVar3;
  ulonglong uVar4;
  
  if (_textureBufferBytes == (void *)0x0) {
    uVar4 = param_2 + 0x20U & 0xffffffe0;
    uVar3 = param_3 + 0x20U & 0xffffffe0;
    goto LAB_00004194;
  }
  if (param_4 == 0) {
    if (DAT_0000e724 == 0x42475241) goto LAB_000040bc;
  }
  else if (DAT_0000e724 == 0x10) {
LAB_000040bc:
    uVar4 = param_2 + 0x20U & 0xffffffe0;
    if (((int)uVar4 == _textureBufferWidth) &&
       (uVar3 = param_3 + 0x20U & 0xffffffe0, uVar3 == _textureBufferHeight)) {
      iVar1 = _io_connect_method_scalarI_structureI
                        (*(undefined4 *)(param_1 + 0xc),0xc,*DAT_0000e748,1,0,0);
      if (iVar1 == 0) {
        return 1;
      }
      if (_textureBufferBytes == (void *)0x0) goto LAB_00004194;
    }
  }
  uVar4 = param_2 + 0x20U & 0xffffffe0;
  uVar3 = param_3 + 0x20U & 0xffffffe0;
  *(int *)(param_1 + 0x94) = *(int *)(param_1 + 0x94) + -1;
  ((int (*)())__FreeSurface)(param_1,8,&_textureBuffer);
  _free(_textureBufferBytes);
  _textureBufferBytes = (void *)0x0;
LAB_00004194:
  _textureBufferWidth = (int)uVar4;
  if (param_4 == 0) {
    DAT_0000e738 = (undefined4)(uVar4 << 2);
    DAT_0000e724 = 0x42475241;
    _textureBufferSize = _textureBufferWidth * uVar3 * 4;
  }
  else {
    DAT_0000e738 = (undefined4)(uVar4 << 1);
    _textureBufferSize = _textureBufferWidth * uVar3 * 2;
    DAT_0000e724 = 0x10;
  }
  _textureBufferHeight = uVar3;
  DAT_0000e730 = _textureBufferWidth;
  DAT_0000e734 = uVar3;
  _textureBufferBytes = _malloc(_textureBufferSize);
  uVar2 = 0;
  if (_textureBufferBytes != (void *)0x0) {
    _textureBuffer = _textureBufferBytes;
    iVar1 = ((int (*)())__AllocateSurface)(param_1,8,&_textureBuffer,0);
    if (iVar1 == 0) {
      uVar2 = 1;
      *(int *)(param_1 + 0x94) = *(int *)(param_1 + 0x94) + 1;
    }
    else {
      _free(_textureBufferBytes);
      uVar2 = 0;
      _textureBufferBytes = (void *)0x0;
    }
  }
  return uVar2;
}

/* _createOffscreenBuffer @ 0x4290 (588 bytes) */
undefined8 _createOffscreenBuffer(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  ulonglong uVar1;
  int iVar2;
  undefined8 uVar3;
  
  if (_offscreenBufferBytes == (void *)0x0) goto LAB_000043f0;
  if (param_3 == 0) {
    if (DAT_0000e6c0 == 0x42475241) goto LAB_0000430c;
  }
  else if (DAT_0000e6c0 == 0x10) {
LAB_0000430c:
    if ((((int)*(short *)(param_2 + 4) + 0x20U & 0xffffffe0) == _offscreenBufferWidth) &&
       (((int)*(short *)(param_2 + 6) + 0x20U & 0xffffffe0) == _offscreenBufferHeight)) {
      iVar2 = _io_connect_method_scalarI_structureI
                        (*(undefined4 *)(param_1 + 0xc),0xc,*DAT_0000e6e4,1,0,0);
      if (iVar2 == 0) {
        return 1;
      }
      if (_offscreenBufferBytes == (void *)0x0) goto LAB_000043f0;
    }
  }
  *(int *)(param_1 + 0x94) = *(int *)(param_1 + 0x94) + -1;
  ((int (*)())__FreeSurface)(param_1,0,&_offscreenBuffer);
  _free(_offscreenBufferBytes);
  _offscreenBufferBytes = (void *)0x0;
LAB_000043f0:
  uVar1 = (longlong)*(short *)(param_2 + 4) + 0x20U & 0xffffffe0;
  _offscreenBufferWidth = (uint)uVar1;
  _offscreenBufferHeight = (int)*(short *)(param_2 + 6) + 0x20U & 0xffffffe0;
  if (param_3 == 0) {
    DAT_0000e6d4 = (undefined4)(uVar1 << 2);
    DAT_0000e6c0 = 0x42475241;
    _offscreenBufferSize = _offscreenBufferWidth * _offscreenBufferHeight * 4;
  }
  else {
    DAT_0000e6d4 = (undefined4)(uVar1 << 1);
    _offscreenBufferSize = _offscreenBufferWidth * _offscreenBufferHeight * 2;
    DAT_0000e6c0 = 0x10;
  }
  DAT_0000e6cc = _offscreenBufferWidth;
  DAT_0000e6d0 = _offscreenBufferHeight;
  _offscreenBufferBytes = _malloc(_offscreenBufferSize);
  uVar3 = 0;
  if (_offscreenBufferBytes != (void *)0x0) {
    _offscreenBuffer = _offscreenBufferBytes;
    iVar2 = ((int (*)())__AllocateSurface)(param_1,0,&_offscreenBuffer,0);
    if (iVar2 == 0) {
      uVar3 = 1;
      *(int *)(param_1 + 0x94) = *(int *)(param_1 + 0x94) + 1;
    }
    else {
      _free(_offscreenBufferBytes);
      uVar3 = 0;
      _offscreenBufferBytes = (void *)0x0;
    }
  }
  return uVar3;
}

/* __Stop @ 0x4500 (248 bytes) */
undefined8 __Stop(param_1)
  int param_1;
{
  int iVar1;
  
  if (_offscreenBufferBytes != (void *)0x0) {
    *(int *)(param_1 + 0x94) = *(int *)(param_1 + 0x94) + -1;
    ((int (*)())__FreeSurface)(param_1,0,&_offscreenBuffer);
    _free(_offscreenBufferBytes);
    _offscreenBufferBytes = (void *)0x0;
  }
  if (_textureBufferBytes != (void *)0x0) {
    *(int *)(param_1 + 0x94) = *(int *)(param_1 + 0x94) + -1;
    ((int (*)())__FreeSurface)(param_1,8,&_textureBuffer);
    _free(_textureBufferBytes);
    _textureBufferBytes = (void *)0x0;
  }
  ((int (*)())__Flush)(param_1,0);
  iVar1 = *(int *)(param_1 + 0x10);
  if (iVar1 != 0) {
    if (*(int *)(param_1 + 0xc) != 0) {
      _IOServiceClose(*(int *)(param_1 + 0xc));
      iVar1 = *(int *)(param_1 + 0x10);
    }
    _IOObjectRelease(iVar1);
    *(undefined4 *)(param_1 + 0xc) = 0;
    *(undefined4 *)(param_1 + 0x10) = 0;
  }
  return 0;
}

/* _printf_LDBLStub @ 0xc89c (172 bytes) */
int _printf_LDBLStub(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  ulonglong param_1;
  ulonglong param_2;
  ulonglong param_3;
  ulonglong param_4;
  ulonglong param_5;
  ulonglong param_6;
  ulonglong param_7;
  ulonglong param_8;
{
  if (_funcptr == (code *)0x0) {
    _funcptr = (code *)((int (*)())___stub_getrealaddr)("printf");
    param_1 = param_1 & 0xffffffff;
    param_8 = param_8 & 0xffffffff;
    param_7 = param_7 & 0xffffffff;
    param_6 = param_6 & 0xffffffff;
    param_5 = param_5 & 0xffffffff;
    param_4 = param_4 & 0xffffffff;
    param_3 = param_3 & 0xffffffff;
    param_2 = param_2 & 0xffffffff;
  }
                    
                    
  (*_funcptr)(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
  return;
}

/* FUN_0000c954 @ 0xc954 (12 bytes) */
int FUN_0000c954()
{
  return;
}

/* FUN_0000c960 @ 0xc960 (8 bytes) */
int FUN_0000c960()
{
  return;
}

/* FUN_0000c968 @ 0xc968 (12 bytes) */
int FUN_0000c968()
{
  return;
}

/* FUN_0000c974 @ 0xc974 (36 bytes) */
int FUN_0000c974()
{
  return;
}

/* ___stub_getrealaddr @ 0xc9ec (164 bytes) */
int ___stub_getrealaddr(param_1)
  char *param_1;
{
  undefined4 uVar1;
  char cVar2;
  size_t sVar3;
  int iVar4;
  char local_58 [4];
  char acStack_54 [4];
  char acStack_50 [80];
  
  local_58[0] = '_';
  _strcpy(local_58 + 1,param_1);
  sVar3 = _strlen(local_58);
  cVar2 = s__LDBL128_0000cfbc[8];
  uVar1 = (*(unsigned int *)((unsigned char *)&(s__LDBL128_0000cfbc) + 4));
  *(undefined4 *)(local_58 + sVar3) = (*(unsigned int *)((unsigned char *)&(s__LDBL128_0000cfbc) + 0));
  acStack_50[sVar3] = cVar2;
  *(undefined4 *)(acStack_54 + sVar3) = uVar1;
  iVar4 = _NSIsSymbolNameDefinedWithHint(local_58,"libSystem.");
  if (iVar4 == 0) {
    local_58[sVar3] = '\0';
  }
  _NSLookupAndBindSymbolWithHint(local_58,"libSystem.");
  _NSAddressOfSymbol();
  return;
}

