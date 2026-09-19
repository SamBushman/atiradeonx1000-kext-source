#include "decls.h"

/* dyld_stub_binding_helper @ 0x600 (48 bytes) */
int dyld_stub_binding_helper()
{
                    
                    
  (*dyld_lazy_symbol_binding_entry_point)();
  return;
}

/* __dyld_func_lookup @ 0x630 (32 bytes) */
int __dyld_func_lookup()
{
                    
                    
  (*dyld_func_lookup_pointer)();
  return;
}

/* _cxa_atexit_check_2 @ 0x650 (40 bytes) */
int _cxa_atexit_check_2(param_1)
  undefined4 *param_1;
{
  *param_1 = 1;
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

/* FUN_000009d4 @ 0x9d4 (32 bytes) */
int FUN_000009d4()
{
                    
                    
  (*dyld_func_lookup_pointer)();
  return;
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
         (iVar1 = (**(code **)((int)local_20 + 0x10))(_our_atexit), iVar1 == 0)) goto LAB_00000bc8;
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

/* FUN_00000c24 @ 0xc24 (32 bytes) */
int FUN_00000c24(param_1, param_2)
  code *param_1;
  code *param_2;
{
  int iVar1;
  code *pcStack00000018;
  code *pcStack0000001c;
  int iStack_28;
  code *pcStack_24;
  int iStack_18;
  
  iStack_28 = 0;
  pcStack00000018 = param_1;
  pcStack0000001c = param_2;
  pcStack_24 = param_1;
  iVar1 = (*param_1)(0x678,&iStack_28,&iStack_28);
  if (iVar1 == 0) {
    (*pcStack0000001c)(&iStack_28);
    if (iStack_28 == 0) {
      (*pcStack0000001c)(&iStack_28);
      iStack_28 = 0;
    }
    iStack_18 = iStack_28;
  }
  else {
    iStack_18 = -1;
  }
  return iStack_18;
}

/* FUN_00000c44 @ 0xc44 (32 bytes) */
int FUN_00000c44()
{
                    
                    
  (*(code *)PTR_dyld_stub_binding_helper_0000e61c)();
  return;
}

/* FUN_00000c64 @ 0xc64 (32 bytes) */
int FUN_00000c64()
{
  uint uVar1;
  char *pcVar2;
  int iVar3;
  undefined4 uVar4;
  uint uStack_38;
  code *pcStack_34;
  code *pcStack_30;
  code *pcStack_2c;
  code *pcStack_28;
  code *apcStack_24 [9];
  
  ((int (*)())__dyld_func_lookup)("__dyld_image_count",&pcStack_34);
  ((int (*)())__dyld_func_lookup)("__dyld_get_image_name",&pcStack_30);
  ((int (*)())__dyld_func_lookup)("__dyld_get_image_header",&pcStack_2c);
  ((int (*)())__dyld_func_lookup)("__dyld_NSLookupSymbolInImage",&pcStack_28);
  ((int (*)())__dyld_func_lookup)("__dyld_NSAddressOfSymbol",apcStack_24);
  if ((((pcStack_34 != (code *)0x0) && (pcStack_30 != (code *)0x0)) && (pcStack_2c != (code *)0x0))
     && ((pcStack_28 != (code *)0x0 && (apcStack_24[0] != (code *)0x0)))) {
    uVar1 = (*pcStack_34)();
    for (uStack_38 = 0; uStack_38 < uVar1; uStack_38 = uStack_38 + 1) {
      pcVar2 = (char *)(*pcStack_30)(uStack_38);
      iVar3 = _strcmp(pcVar2,"/usr/lib/libSystem.B.dylib");
      if (iVar3 == 0) {
        iVar3 = (*pcStack_2c)(uStack_38);
        if (iVar3 == 0) {
          return 0;
        }
        iVar3 = (*pcStack_28)(iVar3,"_atexit",4);
        if (iVar3 != 0) {
          uVar4 = (*apcStack_24[0])(iVar3);
          return uVar4;
        }
        return 0;
      }
    }
  }
  return 0;
}

/* FUN_00000c84 @ 0xc84 (32 bytes) */
int FUN_00000c84()
{
                    
                    
  (*(code *)PTR_dyld_stub_binding_helper_0000e608)();
  return;
}

/* FUN_00000ca4 @ 0xca4 (32 bytes) */
int FUN_00000ca4()
{
                    
                    
  (*(code *)PTR_dyld_stub_binding_helper_0000e620)();
  return;
}

/* FUN_00000cc4 @ 0xcc4 (32 bytes) */
int FUN_00000cc4()
{
                    
                    
  (*(code *)PTR_dyld_stub_binding_helper_0000e610)();
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

/* FUN_00000e10 @ 0xe10 (32 bytes) */
int FUN_00000e10()
{
                    
                    
  (*(code *)PTR_dyld_stub_binding_helper_0000e60c)();
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

/* FUN_00000f74 @ 0xf74 (32 bytes) */
int FUN_00000f74()
{
                    
                    
  (*(code *)PTR_dyld_stub_binding_helper_0000e614)();
  return;
}

/* FUN_00000f94 @ 0xf94 (32 bytes) */
int FUN_00000f94()
{
                    
                    
  (*(code *)PTR_dyld_stub_binding_helper_0000e618)();
  return;
}

/* _cxa_atexit_wrapper @ 0xfb4 (312 bytes) */
int _cxa_atexit_wrapper(param_1)
  undefined4 *param_1;
{
  undefined4 *puStack00000018;
  undefined1 uStack_28;
  undefined4 uStack_24;
  int iStack_20;
  
  uStack_24 = 0;
  uStack_28 = 0;
  puStack00000018 = param_1;
  iStack_20 = __keymgr_get_and_lock_processwide_ptr(0xe);
  if (iStack_20 != 0) {
    uStack_28 = *(undefined1 *)(iStack_20 + 2);
    *(undefined1 *)(iStack_20 + 2) = 1;
    uStack_24 = *(undefined4 *)(iStack_20 + 4);
    __keymgr_set_and_unlock_processwide_ptr(0xe,iStack_20);
  }
  if (param_1[1] == 0) {
    (*(code *)*param_1)();
  }
  else {
    (*(code *)*param_1)(param_1[2]);
  }
  if (iStack_20 != 0) {
    iStack_20 = __keymgr_get_and_lock_processwide_ptr(0xe);
  }
  if (iStack_20 != 0) {
    iStack_20 = ((int (*)())_run_routines)(iStack_20,uStack_24);
  }
  if (iStack_20 != 0) {
    *(undefined1 *)(iStack_20 + 2) = uStack_28;
    __keymgr_set_and_unlock_processwide_ptr(0xe,iStack_20);
  }
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

/* FUN_0000110c @ 0x110c (32 bytes) */
int FUN_0000110c()
{
                    
                    
  (*(code *)PTR_dyld_stub_binding_helper_0000e618)();
  return;
}

/* FUN_0000112c @ 0x112c (32 bytes) */
int FUN_0000112c()
{
                    
                    
  (*(code *)PTR_dyld_stub_binding_helper_0000e610)();
  return;
}

/* _our_atexit @ 0x114c (188 bytes) */
int _our_atexit()
{
  undefined1 uVar1;
  short *psVar2;
  int iVar3;
  
  psVar2 = (short *)__keymgr_get_and_lock_processwide_ptr(0xe);
  if (((psVar2 != (short *)0x0) && (*psVar2 == 0)) && (*(char *)((int)psVar2 + 3) == '\x01')) {
    uVar1 = *(undefined1 *)(psVar2 + 1);
    *(undefined1 *)(psVar2 + 1) = 1;
    iVar3 = ((int (*)())_run_routines)(psVar2,0);
    if (iVar3 != 0) {
      *(undefined1 *)(iVar3 + 2) = uVar1;
      __keymgr_set_and_unlock_processwide_ptr(0xe,iVar3);
    }
  }
  return;
}

/* FUN_00001208 @ 0x1208 (32 bytes) */
int FUN_00001208()
{
  __keymgr_set_and_unlock_processwide_ptr();
  return;
}

/* FUN_00001228 @ 0x1228 (32 bytes) */
int FUN_00001228(param_1, param_2)
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

/* FUN_00001248 @ 0x1248 (32 bytes) */
int FUN_00001248()
{
                    
                    
  (*(code *)PTR_dyld_stub_binding_helper_0000e610)();
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

/* FUN_00001528 @ 0x1528 (32 bytes) */
int FUN_00001528()
{
                    
                    
  (*(code *)PTR_dyld_stub_binding_helper_0000e618)();
  return;
}

/* FUN_00001548 @ 0x1548 (32 bytes) */
int FUN_00001548(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  int iStack00000018;
  undefined4 *puStack0000001c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  iStack00000018 = param_1;
  puStack0000001c = param_2;
  puVar3 = _malloc(0x10);
  if (puVar3 == (undefined4 *)0x0) {
    __keymgr_set_and_unlock_processwide_ptr(0xe,iStack00000018);
    uStack_14 = 0xffffffff;
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
      uStack_18 = 0;
    }
    else {
      uStack_18 = 0xffffffff;
    }
    uStack_14 = uStack_18;
  }
  return uStack_14;
}

/* FUN_00001568 @ 0x1568 (32 bytes) */
int FUN_00001568()
{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  void *pvStack_20;
  void *pvStack_18;
  
  pvStack_20 = (void *)__keymgr_get_and_lock_processwide_ptr(0xe);
  if ((pvStack_20 == (void *)0x0) && (pvStack_20 = _calloc(0x14,1), pvStack_20 == (void *)0x0)) {
    return (void *)0x0;
  }
  if (*(char *)((int)pvStack_20 + 3) == '\0') {
    iVar1 = _dlopen("/usr/lib/libSystem.B.dylib",0x10);
    if (iVar1 == 0) {
      *(undefined1 *)((int)pvStack_20 + 3) = 1;
      uVar2 = ((int (*)())_find_atexit_10_3)();
      *(undefined4 *)((int)pvStack_20 + 0x10) = uVar2;
      if ((*(int *)((int)pvStack_20 + 0x10) != 0) &&
         (iVar1 = (**(code **)((int)pvStack_20 + 0x10))(_our_atexit), iVar1 == 0))
      goto LAB_00000bc8;
    }
    else {
      uVar2 = _dlsym(iVar1,"__cxa_atexit");
      *(undefined4 *)((int)pvStack_20 + 8) = uVar2;
      uVar2 = _dlsym(iVar1,"__cxa_finalize");
      *(undefined4 *)((int)pvStack_20 + 0xc) = uVar2;
      if (((*(int *)((int)pvStack_20 + 8) != 0) && (*(int *)((int)pvStack_20 + 0xc) != 0)) &&
         (iVar3 = ((int (*)())_check_cxa_atexit)(*(undefined4 *)((int)pvStack_20 + 8),
                                    *(undefined4 *)((int)pvStack_20 + 0xc)), iVar3 != -1)) {
        if (iVar3 == 0) {
          *(undefined1 *)((int)pvStack_20 + 3) = 2;
        }
        else {
          uVar2 = _dlsym(iVar1,"atexit");
          *(undefined4 *)((int)pvStack_20 + 0x10) = uVar2;
          if (*(int *)((int)pvStack_20 + 0x10) == 0) goto LAB_00000bd4;
          *(undefined1 *)((int)pvStack_20 + 3) = 0x10;
        }
        goto LAB_00000bc8;
      }
    }
LAB_00000bd4:
    __keymgr_set_and_unlock_processwide_ptr(0xe,pvStack_20);
    pvStack_18 = (void *)0x0;
  }
  else {
LAB_00000bc8:
    pvStack_18 = pvStack_20;
  }
  return pvStack_18;
}

/* ___cxa_atexit @ 0x1588 (96 bytes) */
undefined8 ___cxa_atexit(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined8 uVar1;
  undefined4 uStack00000018;
  undefined4 uStack0000001c;
  undefined4 uStack00000020;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  
  uStack_24 = 1;
  uStack00000018 = param_1;
  uStack0000001c = param_2;
  uStack00000020 = param_3;
  uStack_28 = param_1;
  uStack_20 = param_2;
  uVar1 = ((int (*)())_atexit_common)(&uStack_28,param_3);
  return uVar1;
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

/* __AddRef @ 0x1b80 (20 bytes) */
int __AddRef(param_1)
  int param_1;
{
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
  return;
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

/* __GetBlitter @ 0x20e0 (224 bytes) */
undefined8 __GetBlitter(param_1, param_2, param_3, param_4, param_5)
  undefined8 param_1;
  undefined8 param_2;
  int param_3;
  uint param_4;
  undefined4 *param_5;
{
  code *pcVar1;
  
  param_4 = param_4 & 0x7ffff000;
  if (param_3 == 1) {
    if ((param_4 == 0) || (param_4 == 0x1000)) {
      pcVar1 = _radeonCopy;
      goto LAB_00002114;
    }
  }
  else {
    if (param_3 == 4) {
      pcVar1 = (code *)&_radeonCopyRegion;
      goto LAB_00002114;
    }
    if (param_3 == 0) {
      if (param_4 == 0x6000) {
LAB_000021a0:
        pcVar1 = _radeonFill;
        goto LAB_00002114;
      }
    }
    else if (param_3 == 0x40000) {
      if (param_4 == 0x6000) {
        pcVar1 = _radeonHighlight;
        goto LAB_00002114;
      }
    }
    else if (param_3 == 0x100) {
      if (param_4 == 0x5000) goto LAB_000021a0;
    }
    else if ((param_3 == 3) && (param_4 == 0x6000)) {
      pcVar1 = _radeonSolidScanlines;
      goto LAB_00002114;
    }
  }
  pcVar1 = (code *)0x0;
LAB_00002114:
  *param_5 = pcVar1;
  if (pcVar1 == (code *)0x0) {
    return 0xffffffffe00002c7;
  }
  return 0;
}

/* __Synchronize @ 0x21f0 (8 bytes) */
undefined8 __Synchronize()
{
  return 0;
}

/* __GetBeamPosition @ 0x2200 (104 bytes) */
int __GetBeamPosition(param_1, param_2, param_3)
  int param_1;
  undefined8 param_2;
  uint *param_3;
{
  undefined4 uStack_28;
  uint auStack_24 [9];
  
  auStack_24[0] = *(uint *)(param_1 + 0x90);
  uStack_28 = 4;
  _io_connect_method_structureI_structureO
            (*(undefined4 *)(param_1 + 0xc),0x10,auStack_24,4,auStack_24,&uStack_28);
  *param_3 = auStack_24[0] >> 0x10 & 0x7ff;
  return;
}

/* __WaitSurface @ 0x2270 (72 bytes) */
undefined8 __WaitSurface(param_1, param_2, param_3)
  int param_1;
  undefined8 param_2;
  int param_3;
{
  int iVar1;
  undefined8 uVar2;
  
  if (*(int **)(param_3 + 0x28) == (int *)0x0) {
    uVar2 = 0xffffffffe00002d8;
  }
  else {
    iVar1 = **(int **)(param_3 + 0x28);
    uVar2 = 0;
    if (iVar1 != 0) {
      uVar2 = _io_connect_method_scalarI_structureI(*(undefined4 *)(param_1 + 0xc),0xc,iVar1,1,0,0);
      return uVar2;
    }
  }
  return uVar2;
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

/* __Release @ 0x2420 (100 bytes) */
longlong __Release(param_1)
  void *param_1;
{
  longlong lVar1;
  int iVar2;
  
  lVar1 = (ulonglong)*(uint *)((int)param_1 + 8) - 1;
  iVar2 = (int)lVar1;
  *(int *)((int)param_1 + 8) = iVar2;
  if (iVar2 == 0) {
    iVar2 = *(int *)((int)param_1 + 4);
    _free(param_1);
    if (iVar2 != 0) {
      _CFPlugInRemoveInstanceForFactory(iVar2);
      _CFRelease(iVar2);
    }
  }
  return lVar1;
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

/* __Start @ 0x2610 (308 bytes) */
longlong __Start(param_1, param_2, param_3)
  int param_1;
  undefined8 param_2;
  undefined8 param_3;
{
  longlong lVar1;
  int iVar2;
  int iStack_a8;
  int aiStack_a4 [2];
  undefined1 auStack_9c [156];
  
  lVar1 = _IOAccelFindAccelerator(param_3,&iStack_a8,param_1 + 0x84);
  if (lVar1 == 0) {
    iVar2 = _IOObjectConformsTo(iStack_a8,"ATIRadeonX1000");
    if (iVar2 == 0) {
      iVar2 = _IOObjectGetClass(iStack_a8,auStack_9c);
      if (iVar2 == 0) {
        _printf_LDBLStub("Unusual class (%s)\n",auStack_9c);
        lVar1 = -0x1ffffd39;
      }
      else {
        lVar1 = -0x1ffffd39;
      }
    }
    else {
      lVar1 = _IOServiceOpen(iStack_a8,*(undefined4 *)PTR_0000e694,2,aiStack_a4);
      if (lVar1 == 0) {
        *(int *)(param_1 + 0x10) = iStack_a8;
        *(int *)(param_1 + 0xc) = aiStack_a4[0];
        aiStack_a4[1] = 2;
        lVar1 = _io_connect_method_scalarI_scalarO
                          (aiStack_a4[0],1,0,0,param_1 + 0x88,aiStack_a4 + 1);
        if ((lVar1 == 0) && (lVar1 = ((int (*)())__Reset)(param_1,0), lVar1 == 0)) {
          return 0;
        }
      }
      if (aiStack_a4[0] != 0) {
        _IOServiceClose();
      }
      if (iStack_a8 != 0) {
        _IOObjectRelease();
      }
    }
  }
  return lVar1;
}

