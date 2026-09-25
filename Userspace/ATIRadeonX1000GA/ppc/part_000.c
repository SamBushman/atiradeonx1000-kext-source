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
  code *local_24 [7];
  
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
  _strcmp(param_1,param_2);
  return;
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
  code *apcStack_24 [7];
  
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
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  int iStack00000018;
  undefined4 *puStack0000001c;
  undefined4 local_18;
  undefined4 local_14;
  
  iStack00000018 = param_1;
  puStack0000001c = param_2;
  puVar2 = _malloc(0x10);
  if (puVar2 == (undefined4 *)0x0) {
    __keymgr_set_and_unlock_processwide_ptr(0xe,iStack00000018);
    local_14 = 0xffffffff;
  }
  else {
    uVar4 = puStack0000001c[1];
    uVar1 = puStack0000001c[2];
    puVar2[1] = *puStack0000001c;
    puVar2[2] = uVar4;
    puVar2[3] = uVar1;
    *puVar2 = *(undefined4 *)(iStack00000018 + 4);
    *(undefined4 **)(iStack00000018 + 4) = puVar2;
    iVar3 = __keymgr_set_and_unlock_processwide_ptr(0xe,iStack00000018);
    if ((*(ushort *)(*(int *)(PTR_0000e68c + 8) + 4) < 4) || (iVar3 == 0)) {
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
  undefined1 local_28;
  undefined4 local_24;
  int local_20;
  
  local_24 = 0;
  local_28 = 0;
  puStack00000018 = param_1;
  local_20 = __keymgr_get_and_lock_processwide_ptr(0xe);
  if (local_20 != 0) {
    local_28 = *(undefined1 *)(local_20 + 2);
    *(undefined1 *)(local_20 + 2) = 1;
    local_24 = *(undefined4 *)(local_20 + 4);
    __keymgr_set_and_unlock_processwide_ptr(0xe,local_20);
  }
  if (param_1[1] == 0) {
    (*(code *)*param_1)();
  }
  else {
    (*(code *)*param_1)(param_1[2]);
  }
  if (local_20 != 0) {
    local_20 = __keymgr_get_and_lock_processwide_ptr(0xe);
  }
  if (local_20 != 0) {
    local_20 = ((int (*)())_run_routines)(local_20,local_24);
  }
  if (local_20 != 0) {
    *(undefined1 *)(local_20 + 2) = local_28;
    __keymgr_set_and_unlock_processwide_ptr(0xe,local_20);
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
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  undefined4 *puStack00000018;
  undefined4 uStack0000001c;
  undefined4 local_18;
  
  puStack00000018 = param_1;
  uStack0000001c = param_2;
  iVar3 = ((int (*)())_get_globals)();
  if (iVar3 == 0) {
    local_18 = 0xffffffff;
  }
  else if ((*(char *)(iVar3 + 2) == '\0') && (*(char *)(iVar3 + 3) != '\x01')) {
    if (*(byte *)(iVar3 + 3) < 0x10) {
      pcVar1 = *(code **)(iVar3 + 8);
      iVar3 = __keymgr_set_and_unlock_processwide_ptr(0xe,iVar3);
      if ((*(ushort *)(*(int *)(PTR_0000e68c + 8) + 4) < 4) || (iVar3 == 0)) {
        puVar4 = _malloc(0xc);
        if (puVar4 == (undefined4 *)0x0) {
          local_18 = 0xffffffff;
        }
        else {
          uVar5 = puStack00000018[1];
          uVar2 = puStack00000018[2];
          *puVar4 = *puStack00000018;
          puVar4[1] = uVar5;
          puVar4[2] = uVar2;
          local_18 = (*pcVar1)(0xfb4,puVar4,uStack0000001c);
        }
      }
      else {
        local_18 = 0xffffffff;
      }
    }
    else if (puStack00000018[1] == 0) {
      pcVar1 = *(code **)(iVar3 + 0x10);
      iVar3 = __keymgr_set_and_unlock_processwide_ptr(0xe,iVar3);
      if ((*(ushort *)(*(int *)(PTR_0000e68c + 8) + 4) < 4) || (iVar3 == 0)) {
        local_18 = (*pcVar1)(*puStack00000018);
      }
      else {
        local_18 = 0xffffffff;
      }
    }
    else {
      pcVar1 = *(code **)(iVar3 + 8);
      iVar3 = __keymgr_set_and_unlock_processwide_ptr(0xe,iVar3);
      if ((*(ushort *)(*(int *)(PTR_0000e68c + 8) + 4) < 4) || (iVar3 == 0)) {
        local_18 = (*pcVar1)(*puStack00000018,puStack00000018[2],uStack0000001c);
      }
      else {
        local_18 = 0xffffffff;
      }
    }
  }
  else {
    local_18 = ((int (*)())_add_routine)(iVar3,puStack00000018);
  }
  return local_18;
}

/* FUN_00001508 @ 0x1508 (32 bytes) */
int FUN_00001508(param_1)
  size_t param_1;
{
  _malloc(param_1);
  return;
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
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  int iStack00000018;
  undefined4 *puStack0000001c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  iStack00000018 = param_1;
  puStack0000001c = param_2;
  puVar2 = _malloc(0x10);
  if (puVar2 == (undefined4 *)0x0) {
    __keymgr_set_and_unlock_processwide_ptr(0xe,iStack00000018);
    uStack_14 = 0xffffffff;
  }
  else {
    uVar4 = puStack0000001c[1];
    uVar1 = puStack0000001c[2];
    puVar2[1] = *puStack0000001c;
    puVar2[2] = uVar4;
    puVar2[3] = uVar1;
    *puVar2 = *(undefined4 *)(iStack00000018 + 4);
    *(undefined4 **)(iStack00000018 + 4) = puVar2;
    iVar3 = __keymgr_set_and_unlock_processwide_ptr(0xe,iStack00000018);
    if ((*(ushort *)(*(int *)(PTR_0000e68c + 8) + 4) < 4) || (iVar3 == 0)) {
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
int ___cxa_atexit(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined4 uVar1;
  undefined4 uStack00000018;
  undefined4 uStack0000001c;
  undefined4 uStack00000020;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  local_24 = 1;
  uStack00000018 = param_1;
  uStack0000001c = param_2;
  uStack00000020 = param_3;
  local_28 = param_1;
  local_20 = param_2;
  uVar1 = ((int (*)())_atexit_common)(&local_28,param_3);
  return uVar1;
}

/* FUN_000015e8 @ 0x15e8 (32 bytes) */
int FUN_000015e8(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  ((int (*)())_atexit_common)(param_1,param_2);
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
int FUN_00001664(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  ((int (*)())_atexit_common)(param_1,param_2);
  return;
}

/* __SetSurface @ 0x1690 (184 bytes) */
int __SetSurface(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  int param_3;
{
  int iVar1;
  undefined4 local_28;
  int local_24;
  uint local_20;
  
  if ((param_2 & 0x800) == 0) {
    local_24 = *(int *)(param_1 + 0x84);
    local_20 = 0;
  }
  else {
    if (*(int *)(param_3 + 0x28) == 0) {
      return -0x1ffffd28;
    }
    local_24 = *(int *)(*(int *)(param_3 + 0x28) + 8);
    local_20 = param_2;
  }
  local_28 = 0x30;
  iVar1 = _io_connect_method_scalarI_structureO
                    (*(undefined4 *)(param_1 + 0xc),0,&local_24,2,param_1 + 0x4c,&local_28);
  if (iVar1 == 0) {
    if ((local_24 == 0) || (local_20 == 0)) {
      param_3 = 0;
    }
    *(int *)(param_1 + 0x8c) = param_3;
    iVar1 = 0;
  }
  return iVar1;
}

/* __SetDestination @ 0x1750 (8 bytes) */
int __SetDestination(param_1, param_2, param_3)
  undefined4 param_1;
  uint param_2;
  undefined4 param_3;
{
  undefined4 uVar1;
  
  uVar1 = ((int (*)())__SetSurface)(param_1,(param_2 & 1) << 0xb,param_3);
  return uVar1;
}

/* __LockSurface @ 0x1760 (160 bytes) */
int __LockSurface(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  int *param_4;
{
  int iVar1;
  int iVar2;
  undefined4 local_28;
  int local_24;
  undefined4 local_20;
  
  if (*(int *)(param_3 + 0x28) == 0) {
    iVar2 = -0x1ffffd28;
  }
  else {
    iVar1 = *(int *)(*(int *)(param_3 + 0x28) + 4);
    if (iVar1 == 0) {
      local_28 = 2;
      local_24 = param_2;
      iVar2 = _io_connect_method_scalarI_scalarO
                        (*(undefined4 *)(param_1 + 0xc),5,&local_24,1,&local_24,&local_28);
      if (iVar2 == 0) {
        *param_4 = local_24;
        *(undefined4 *)(param_3 + 0x18) = local_20;
      }
    }
    else {
      iVar2 = 0;
      *param_4 = iVar1;
    }
  }
  return iVar2;
}

/* __UnlockSurface @ 0x1820 (144 bytes) */
int __UnlockSurface(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 param_2;
  int param_3;
  undefined4 *param_4;
{
  undefined4 uVar1;
  undefined4 local_28;
  undefined4 local_24 [7];
  
  if (*(int *)(param_3 + 0x28) == 0) {
    uVar1 = 0xe00002d8;
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
int __SwapSurface(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 param_2;
  int param_3;
  undefined4 *param_4;
{
  undefined4 uVar1;
  undefined4 local_28;
  undefined4 local_24 [7];
  
  if (*(int *)(param_3 + 0x28) == 0) {
    uVar1 = 0xe00002d8;
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
int __Probe(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 *param_4;
{
  *param_4 = 2000;
  return 0;
}

/* _window_mode_to_ati_format @ 0x1960 (148 bytes) */
int _window_mode_to_ati_format(param_1)
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
int __QueryInterface(param_1, param_2, param_3, param_4, param_5, param_6)
  int *param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 *param_6;
{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
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
  iVar3 = _CFEqual(uVar1,uVar2);
  if (iVar3 == 0) {
    uVar2 = _CFUUIDGetConstantUUIDWithBytes(0,0,0,0,0,0,0,0);
    iVar3 = _CFEqual(uVar1,uVar2);
    if (iVar3 == 0) {
      *param_6 = 0;
      return 0x80000004;
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
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  undefined2 uVar12;
  undefined4 uVar11;
  int iVar13;
  uint uVar14;
  int iVar15;
  
  if ((param_2 & 0x7ffff000) == 0x6000) {
    uVar7 = 0xffffffff;
    uVar14 = 0xffffffff;
  }
  else {
    uVar14 = ((uint *)*param_1)[1];
    uVar7 = *(uint *)*param_1;
    uVar7 = uVar7 >> 0x18 | uVar7 >> 8 & 0xff00 | (uVar7 & 0xff00) << 8 | uVar7 << 0x18;
    uVar14 = uVar14 >> 0x18 | uVar14 >> 8 & 0xff00 | (uVar14 & 0xff00) << 8 | uVar14 << 0x18;
  }
  if (DAT_0000e724 == 0x10) {
    iVar8 = 0;
    iVar15 = 0x20;
    uVar10 = 0x80000000;
    iVar2 = _textureBufferWidth * 0x10;
    iVar3 = _textureBufferWidth * 2;
    iVar4 = _textureBufferWidth * 8;
    iVar13 = iVar2 + _textureBufferBytes;
    iVar9 = _textureBufferBytes;
    do {
      uVar12 = (short)param_4;
      if ((uVar7 & uVar10) == 0) {
        uVar12 = (short)param_3;
      }
      bVar1 = iVar8 == 7;
      iVar5 = iVar8 * 2;
      iVar6 = iVar4 + iVar8;
      iVar8 = iVar8 + 1;
      *(undefined2 *)(iVar9 + iVar5) = uVar12;
      *(undefined2 *)(iVar5 + iVar9 + 0x10) = uVar12;
      *(undefined2 *)(iVar6 * 2 + iVar9) = uVar12;
      *(undefined2 *)(iVar13 + iVar5 + 0x10) = uVar12;
      if (bVar1) {
        iVar9 = iVar9 + iVar3;
        iVar8 = 0;
        iVar13 = iVar2 + iVar9;
      }
      uVar10 = uVar10 >> 1;
      iVar15 = iVar15 + -1;
    } while (iVar15 != 0);
    iVar8 = 0;
    uVar7 = 0x80000000;
    iVar15 = 0x20;
    while( true ) {
      uVar12 = (short)param_4;
      if ((uVar14 & uVar7) == 0) {
        uVar12 = (short)param_3;
      }
      bVar1 = iVar8 == 7;
      iVar5 = iVar8 * 2;
      iVar6 = iVar8 + iVar4;
      iVar8 = iVar8 + 1;
      *(undefined2 *)(iVar9 + iVar5) = uVar12;
      *(undefined2 *)(iVar5 + iVar9 + 0x10) = uVar12;
      *(undefined2 *)(iVar6 * 2 + iVar9) = uVar12;
      *(undefined2 *)(iVar13 + iVar5 + 0x10) = uVar12;
      if (bVar1) {
        iVar9 = iVar9 + iVar3;
        iVar8 = 0;
      }
      uVar7 = uVar7 >> 1;
      iVar15 = iVar15 + -1;
      if (iVar15 == 0) break;
      iVar13 = iVar2 + iVar9;
    }
  }
  else {
    iVar8 = 0;
    uVar10 = 0x80000000;
    iVar15 = 0x20;
    iVar2 = _textureBufferWidth * 0x20;
    iVar3 = _textureBufferWidth * 4;
    iVar4 = _textureBufferWidth * 8;
    iVar13 = iVar2 + _textureBufferBytes;
    iVar9 = _textureBufferBytes;
    do {
      uVar11 = param_4;
      if ((uVar7 & uVar10) == 0) {
        uVar11 = param_3;
      }
      bVar1 = iVar8 == 7;
      iVar5 = iVar8 * 4;
      iVar6 = iVar4 + iVar8;
      iVar8 = iVar8 + 1;
      *(undefined4 *)(iVar9 + iVar5) = uVar11;
      *(undefined4 *)(iVar5 + iVar9 + 0x20) = uVar11;
      *(undefined4 *)(iVar6 * 4 + iVar9) = uVar11;
      *(undefined4 *)(iVar13 + iVar5 + 0x20) = uVar11;
      if (bVar1) {
        iVar9 = iVar9 + iVar3;
        iVar8 = 0;
        iVar13 = iVar2 + iVar9;
      }
      uVar10 = uVar10 >> 1;
      iVar15 = iVar15 + -1;
    } while (iVar15 != 0);
    iVar8 = 0;
    uVar7 = 0x80000000;
    iVar15 = 0x20;
    while( true ) {
      uVar11 = param_4;
      if ((uVar14 & uVar7) == 0) {
        uVar11 = param_3;
      }
      bVar1 = iVar8 == 7;
      iVar5 = iVar8 * 4;
      iVar6 = iVar8 + iVar4;
      iVar8 = iVar8 + 1;
      *(undefined4 *)(iVar9 + iVar5) = uVar11;
      *(undefined4 *)(iVar5 + iVar9 + 0x20) = uVar11;
      *(undefined4 *)(iVar6 * 4 + iVar9) = uVar11;
      *(undefined4 *)(iVar13 + iVar5 + 0x20) = uVar11;
      if (bVar1) {
        iVar9 = iVar9 + iVar3;
        iVar8 = 0;
      }
      uVar7 = uVar7 >> 1;
      iVar15 = iVar15 + -1;
      if (iVar15 == 0) break;
      iVar13 = iVar2 + iVar9;
    }
  }
  return;
}

/* __GetCapabilities @ 0x2030 (156 bytes) */
int __GetCapabilities(param_1, param_2, param_3)
  int param_1;
  int param_2;
  undefined4 *param_3;
{
  undefined4 uVar1;
  
  if (param_2 != 0x63676c73) {
    if (param_2 == 0x736d766c) {
      if ((param_1 != 0) && (*(int *)(param_1 + 0xc) != 0)) {
        uVar1 = _io_connect_method_scalarI_structureI(*(int *)(param_1 + 0xc),0xf,param_3,1,0,0);
        return uVar1;
      }
      return 0xe00002d8;
    }
    if (param_2 != 0x42475241) {
      return 0xe00002c7;
    }
  }
  *param_3 = *(undefined4 *)PTR_0000e698;
  return 0;
}

/* __GetBlitter @ 0x20e0 (224 bytes) */
int __GetBlitter(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  undefined4 param_2;
  int param_3;
  uint param_4;
  undefined4 *param_5;
{
  uint uVar1;
  code *pcVar2;
  
  uVar1 = param_4 & 0x7ffff000;
  if (param_3 == 1) {
    if ((uVar1 == 0) || (uVar1 == 0x1000)) {
      pcVar2 = _radeonCopy;
      goto LAB_00002114;
    }
  }
  else {
    if (param_3 == 4) {
      pcVar2 = (code *)&_radeonCopyRegion;
      goto LAB_00002114;
    }
    if (param_3 == 0) {
      if (uVar1 == 0x6000) {
LAB_000021a0:
        pcVar2 = _radeonFill;
        goto LAB_00002114;
      }
    }
    else if (param_3 == 0x40000) {
      if (uVar1 == 0x6000) {
        pcVar2 = _radeonHighlight;
        goto LAB_00002114;
      }
    }
    else if (param_3 == 0x100) {
      if (uVar1 == 0x5000) goto LAB_000021a0;
    }
    else if ((param_3 == 3) && (uVar1 == 0x6000)) {
      pcVar2 = _radeonSolidScanlines;
      goto LAB_00002114;
    }
  }
  pcVar2 = (code *)0x0;
LAB_00002114:
  *param_5 = pcVar2;
  if (pcVar2 == (code *)0x0) {
    return 0xe00002c7;
  }
  return 0;
}

/* __Synchronize @ 0x21f0 (8 bytes) */
int __Synchronize()
{
  return 0;
}

/* __GetBeamPosition @ 0x2200 (104 bytes) */
int __GetBeamPosition(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  uint *param_3;
{
  undefined4 local_28;
  uint local_24 [6];
  
  local_24[0] = *(uint *)(param_1 + 0x90);
  local_28 = 4;
  _io_connect_method_structureI_structureO
            (*(undefined4 *)(param_1 + 0xc),0x10,local_24,4,local_24,&local_28);
  *param_3 = local_24[0] >> 0x10 & 0x7ff;
  return;
}

/* __WaitSurface @ 0x2270 (72 bytes) */
int __WaitSurface(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  int param_3;
{
  undefined4 uVar1;
  int iVar2;
  
  if (*(int **)(param_3 + 0x28) == (int *)0x0) {
    uVar1 = 0xe00002d8;
  }
  else {
    iVar2 = **(int **)(param_3 + 0x28);
    uVar1 = 0;
    if (iVar2 != 0) {
      uVar1 = _io_connect_method_scalarI_structureI(*(undefined4 *)(param_1 + 0xc),0xc,iVar2,1,0,0);
      return uVar1;
    }
  }
  return uVar1;
}

/* _ATIRadeonX1000GAFactory @ 0x22d0 (324 bytes) */
int _ATIRadeonX1000GAFactory(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar2 = _CFUUIDGetConstantUUIDWithBytes(0,0xac,0xcf,0,0,0,0,0);
  iVar3 = _CFEqual(param_2,uVar2);
  puVar1 = (undefined4 *)0x0;
  if (iVar3 != 0) {
    iVar3 = _CFUUIDGetConstantUUIDWithBytes(0,0x10,2,0x71,0,0,0,0);
    puVar1 = _calloc(1,0x98);
    *puVar1 = &_radeonGAInterface;
    if (iVar3 != 0) {
      uVar2 = _CFRetain(iVar3);
      puVar1[1] = uVar2;
      _CFPlugInAddInstanceForFactory(iVar3);
    }
    puVar1[2] = 1;
  }
  return puVar1;
}

/* __Release @ 0x2420 (100 bytes) */
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
    }
  }
  return iVar2;
}

/* __Reset @ 0x2490 (360 bytes) */
int __Reset(param_1)
  int param_1;
{
  uint *puVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 local_28;
  int local_24;
  int local_20 [4];
  
  if (*(int *)(param_1 + 0xc) == 0) {
    uVar3 = 0xe00002d8;
  }
  else {
    iVar2 = _IOConnectMapMemory(*(int *)(param_1 + 0xc),1,*(undefined4 *)PTR_0000e694,local_20,
                                &local_28,1);
    if ((iVar2 == 0) && (local_20[0] != 0)) {
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
    iVar2 = _IOConnectMapMemory(*(undefined4 *)(param_1 + 0xc),0,*(undefined4 *)PTR_0000e694,
                                &local_24,&local_28,1);
    if ((iVar2 == 0) && (local_24 != 0)) {
      *(int *)(param_1 + 0x18) = local_24;
      *(int *)(param_1 + 0x80) = local_24 + 0x20;
      *(int *)(param_1 + 0x7c) = local_24 + 0x1c;
      *(undefined4 *)(local_24 + 0x1c) = 0;
    }
    uVar3 = 0x310;
    if (*(int *)(param_1 + 0x84) == 0) {
      uVar3 = 0x210;
    }
    *(undefined4 *)(param_1 + 0x90) = uVar3;
    *(undefined4 *)(param_1 + 0x94) = 0;
    uVar3 = ((int (*)())__SetDestination)(param_1,0,0);
    _memcpy((void *)(param_1 + 0x1c),(void *)(param_1 + 0x4c),0x30);
  }
  return uVar3;
}

/* __Start @ 0x2610 (308 bytes) */
int __Start(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  int iVar1;
  int iVar2;
  int local_a8;
  int local_a4 [2];
  undefined1 auStack_9c [144];
  
  iVar2 = param_1 + 0x84;
  iVar1 = _IOAccelFindAccelerator(param_3,&local_a8);
  if (iVar1 == 0) {
    iVar1 = _IOObjectConformsTo(local_a8,"ATIRadeonX1000");
    if (iVar1 == 0) {
      iVar1 = _IOObjectGetClass(local_a8,auStack_9c);
      if (iVar1 == 0) {
        _printf_LDBLStub("Unusual class (%s)\n",auStack_9c,iVar2,param_4,param_5,param_6,param_7,
                         param_8);
        iVar1 = -0x1ffffd39;
      }
      else {
        iVar1 = -0x1ffffd39;
      }
    }
    else {
      iVar1 = _IOServiceOpen(local_a8,*(undefined4 *)PTR_0000e694,2,local_a4);
      if (iVar1 == 0) {
        *(int *)(param_1 + 0x10) = local_a8;
        *(int *)(param_1 + 0xc) = local_a4[0];
        local_a4[1] = 2;
        iVar1 = _io_connect_method_scalarI_scalarO(local_a4[0],1,0,0,param_1 + 0x88,local_a4 + 1);
        if ((iVar1 == 0) && (iVar1 = ((int (*)())__Reset)(param_1), iVar1 == 0)) {
          return 0;
        }
      }
      if (local_a4[0] != 0) {
        _IOServiceClose();
      }
      if (local_a8 != 0) {
        _IOObjectRelease();
      }
    }
  }
  return iVar1;
}

