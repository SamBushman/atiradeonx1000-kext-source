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
int _cxa_atexit_check_2(state)
  undefined4 *state;
{
  *state = 1;
  return;
}

/* _cxa_atexit_check_1 @ 0x678 (120 bytes) */
int _cxa_atexit_check_1(state)
  undefined4 *state;
{
  int status;
  undefined4 *stateHome;
  
  stateHome = state;
  status = (*(code *)state[1])(0x650,state,state);
  if (status != 0) {
    *state = 0xffffffff;
  }
  return;
}

/* _check_cxa_atexit @ 0x6f0 (204 bytes) */
int _check_cxa_atexit(cxaAtexitFn, cxaFinalizeFn)
  code *cxaAtexitFn;
  code *cxaFinalizeFn;
{
  int status;
  code *cxaAtexitFnHome;
  code *cxaFinalizeFnHome;
  int state;
  code *cxaAtexitFnCopy;
  int result;
  
  state = 0;
  cxaAtexitFnHome = cxaAtexitFn;
  cxaFinalizeFnHome = cxaFinalizeFn;
  cxaAtexitFnCopy = cxaAtexitFn;
  status = (*cxaAtexitFn)(0x678,&state,&state);
  if (status == 0) {
    (*cxaFinalizeFnHome)(&state);
    if (state == 0) {
      (*cxaFinalizeFnHome)(&state);
      state = 0;
    }
    result = state;
  }
  else {
    result = -1;
  }
  return result;
}

/* _find_atexit_10_3 @ 0x7bc (504 bytes) */
int _find_atexit_10_3()
{
  undefined4 uVar1;
  uint imageCount;
  int iVar3;
  uint imageIndex;
  code *imageCountFn;
  code *imageNameFn;
  code *imageHeaderFn;
  code *lookupSymbolFn;
  code *addressOfSymbolFn [7];
  
  ((int (*)())__dyld_func_lookup)("__dyld_image_count",&imageCountFn);
  ((int (*)())__dyld_func_lookup)("__dyld_get_image_name",&imageNameFn);
  ((int (*)())__dyld_func_lookup)("__dyld_get_image_header",&imageHeaderFn);
  ((int (*)())__dyld_func_lookup)("__dyld_NSLookupSymbolInImage",&lookupSymbolFn);
  uVar1 = ((int (*)())__dyld_func_lookup)("__dyld_NSAddressOfSymbol",addressOfSymbolFn);
  if ((((imageCountFn != (code *)0x0) && (imageNameFn != (code *)0x0)) && (imageHeaderFn != (code *)0x0)) &&
     ((lookupSymbolFn != (code *)0x0 && (addressOfSymbolFn[0] != (code *)0x0)))) {
    imageCount = (*imageCountFn)(uVar1);
    for (imageIndex = 0; imageIndex < imageCount; imageIndex = imageIndex + 1) {
      uVar1 = (*imageNameFn)(imageIndex);
      iVar3 = _strcmp(uVar1,"/usr/lib/libSystem.B.dylib");
      if (iVar3 == 0) {
        iVar3 = (*imageHeaderFn)(imageIndex);
        if (iVar3 == 0) {
          return 0;
        }
        iVar3 = (*lookupSymbolFn)(iVar3,"_atexit",4);
        if (iVar3 != 0) {
          uVar1 = (*addressOfSymbolFn[0])(iVar3);
          return uVar1;
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
  int libSystemHandle;
  undefined4 symbolAddress;
  int checkResult;
  int globals;
  int result;
  
  globals = __keymgr_get_and_lock_processwide_ptr(0xe);
  if ((globals == 0) && (globals = _calloc(0x14,1), globals == 0)) {
    return 0;
  }
  if (*(char *)(globals + 3) == '\0') {
    libSystemHandle = _dlopen("/usr/lib/libSystem.B.dylib",0x10);
    if (libSystemHandle == 0) {
      *(undefined1 *)(globals + 3) = 1;
      symbolAddress = ((int (*)())_find_atexit_10_3)();
      *(undefined4 *)(globals + 0x10) = symbolAddress;
      if ((*(int *)(globals + 0x10) != 0) &&
         (libSystemHandle = (**(code **)(globals + 0x10))(_our_atexit), libSystemHandle == 0)) goto LAB_00000bc8;
    }
    else {
      symbolAddress = _dlsym(libSystemHandle,"__cxa_atexit");
      *(undefined4 *)(globals + 8) = symbolAddress;
      symbolAddress = _dlsym(libSystemHandle,"__cxa_finalize");
      *(undefined4 *)(globals + 0xc) = symbolAddress;
      if (((*(int *)(globals + 8) != 0) && (*(int *)(globals + 0xc) != 0)) &&
         (checkResult = ((int (*)())_check_cxa_atexit)(*(undefined4 *)(globals + 8),*(undefined4 *)(globals + 0xc)),
         checkResult != -1)) {
        if (checkResult == 0) {
          *(undefined1 *)(globals + 3) = 2;
        }
        else {
          symbolAddress = _dlsym(libSystemHandle,"atexit");
          *(undefined4 *)(globals + 0x10) = symbolAddress;
          if (*(int *)(globals + 0x10) == 0) goto LAB_00000bd4;
          *(undefined1 *)(globals + 3) = 0x10;
        }
        goto LAB_00000bc8;
      }
    }
LAB_00000bd4:
    __keymgr_set_and_unlock_processwide_ptr(0xe,globals);
    result = 0;
  }
  else {
LAB_00000bc8:
    result = globals;
  }
  return result;
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
int _add_routine(globals, routine)
  int globals;
  undefined4 *routine;
{
  undefined4 argument;
  undefined4 *node;
  int unlockResult;
  undefined4 kind;
  int globalsHome;
  undefined4 *routineHome;
  undefined4 status;
  undefined4 result;
  
  globalsHome = globals;
  routineHome = routine;
  node = (undefined4 *)_malloc(0x10);
  if (node == (undefined4 *)0x0) {
    __keymgr_set_and_unlock_processwide_ptr(0xe,globalsHome);
    result = 0xffffffff;
  }
  else {
    kind = routineHome[1];
    argument = routineHome[2];
    node[1] = *routineHome;
    node[2] = kind;
    node[3] = argument;
    *node = *(undefined4 *)(globalsHome + 4);
    *(undefined4 **)(globalsHome + 4) = node;
    unlockResult = __keymgr_set_and_unlock_processwide_ptr(0xe,globalsHome);
    if ((*(ushort *)(*(int *)(PTR_0000e68c + 8) + 4) < 4) || (unlockResult == 0)) {
      status = 0;
    }
    else {
      status = 0xffffffff;
    }
    result = status;
  }
  return result;
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
int _run_routines(globals, stopNode)
  int globals;
  undefined4 *stopNode;
{
  undefined4 *node;
  uint kindMask;
  undefined4 unlockResult;
  undefined4 a1;
  undefined4 in_r5;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  int globalsHome;
  undefined4 *stopNodeHome;
  
  globalsHome = globals;
  stopNodeHome = stopNode;
  while( true ) {
    node = *(undefined4 **)(globalsHome + 4);
    if (node == (undefined4 *)0x0) {
      return globalsHome;
    }
    if (node == stopNodeHome) break;
    *(undefined4 *)(globalsHome + 4) = *node;
    unlockResult = __keymgr_set_and_unlock_processwide_ptr(0xe,globalsHome);
    if ((uint)node[2] < 6) {
      kindMask = 1 << (node[2] & 0x3f);
      if ((kindMask & 0x15) == 0) {
        if ((kindMask & 0x2a) != 0) {
          (*(code *)node[1])(node[3],a1,in_r5,in_r6,in_r7,in_r8,(code *)node[1]);
        }
      }
      else {
        (*(code *)node[1])(unlockResult);
      }
    }
    _free(node);
    globalsHome = __keymgr_get_and_lock_processwide_ptr(0xe);
    if (globalsHome == 0) {
      return 0;
    }
  }
  return globalsHome;
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
int _cxa_atexit_wrapper(entry)
  undefined4 *entry;
{
  undefined4 a0;
  undefined4 extraout_r4;
  undefined4 extraout_r4_00;
  undefined4 a1;
  undefined4 in_r5;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  undefined4 *entryHome;
  undefined1 savedRunning;
  undefined4 savedList;
  int globals;
  
  savedList = 0;
  savedRunning = 0;
  entryHome = entry;
  globals = __keymgr_get_and_lock_processwide_ptr(0xe);
  a0 = 0;
  a1 = extraout_r4;
  if (globals != 0) {
    savedRunning = *(undefined1 *)(globals + 2);
    *(undefined1 *)(globals + 2) = 1;
    savedList = *(undefined4 *)(globals + 4);
    a0 = __keymgr_set_and_unlock_processwide_ptr(0xe,globals);
    a1 = extraout_r4_00;
  }
  if (entry[1] == 0) {
    (*(code *)*entry)(a0);
  }
  else {
    (*(code *)*entry)(entry[2],a1,in_r5,in_r6,in_r7,in_r8,(code *)*entry);
  }
  if (globals != 0) {
    globals = __keymgr_get_and_lock_processwide_ptr(0xe);
  }
  if (globals != 0) {
    globals = ((int (*)())_run_routines)(globals,savedList);
  }
  if (globals != 0) {
    *(undefined1 *)(globals + 2) = savedRunning;
    __keymgr_set_and_unlock_processwide_ptr(0xe,globals);
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
  undefined1 savedRunning;
  short *globals;
  int relocked;
  
  globals = (short *)__keymgr_get_and_lock_processwide_ptr(0xe);
  if (((globals != (short *)0x0) && (*globals == 0)) && (*(char *)((int)globals + 3) == '\x01')) {
    savedRunning = *(undefined1 *)(globals + 1);
    *(undefined1 *)(globals + 1) = 1;
    relocked = ((int (*)())_run_routines)(globals,0);
    if (relocked != 0) {
      *(undefined1 *)(relocked + 2) = savedRunning;
      __keymgr_set_and_unlock_processwide_ptr(0xe,relocked);
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
int _atexit_common(entry, dsoHandle)
  undefined4 *entry;
  undefined4 dsoHandle;
{
  code *registerFn;
  undefined4 uVar2;
  int globals;
  undefined4 *entryCopy;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  undefined4 uVar4;
  undefined4 *entryHome;
  undefined4 dsoHandleHome;
  undefined4 result;
  
  entryHome = entry;
  dsoHandleHome = dsoHandle;
  globals = ((int (*)())_get_globals)();
  if (globals == 0) {
    result = 0xffffffff;
  }
  else if ((*(char *)(globals + 2) == '\0') && (*(char *)(globals + 3) != '\x01')) {
    if (*(byte *)(globals + 3) < 0x10) {
      registerFn = *(code **)(globals + 8);
      globals = __keymgr_set_and_unlock_processwide_ptr(0xe,globals);
      if ((*(ushort *)(*(int *)(PTR_0000e68c + 8) + 4) < 4) || (globals == 0)) {
        entryCopy = (undefined4 *)_malloc(0xc);
        if (entryCopy == (undefined4 *)0x0) {
          result = 0xffffffff;
        }
        else {
          uVar4 = entryHome[1];
          uVar2 = entryHome[2];
          *entryCopy = *entryHome;
          entryCopy[1] = uVar4;
          entryCopy[2] = uVar2;
          result = (*registerFn)(0xfb4,entryCopy,dsoHandleHome,in_r6,in_r7,in_r8,entryCopy);
        }
      }
      else {
        result = 0xffffffff;
      }
    }
    else if (entryHome[1] == 0) {
      registerFn = *(code **)(globals + 0x10);
      globals = __keymgr_set_and_unlock_processwide_ptr(0xe,globals);
      if ((*(ushort *)(*(int *)(PTR_0000e68c + 8) + 4) < 4) || (globals == 0)) {
        result = (*registerFn)(*entryHome);
      }
      else {
        result = 0xffffffff;
      }
    }
    else {
      registerFn = *(code **)(globals + 8);
      globals = __keymgr_set_and_unlock_processwide_ptr(0xe,globals);
      if ((*(ushort *)(*(int *)(PTR_0000e68c + 8) + 4) < 4) || (globals == 0)) {
        result = (*registerFn)(*entryHome,entryHome[2],dsoHandleHome,in_r6,in_r7,in_r8,
                             *entryHome);
      }
      else {
        result = 0xffffffff;
      }
    }
  }
  else {
    result = ((int (*)())_add_routine)(globals,entryHome);
  }
  return result;
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
int ___cxa_atexit(function, argument, dsoHandle)
  undefined4 function;
  undefined4 argument;
  undefined4 dsoHandle;
{
  undefined4 result;
  undefined4 uStack00000018;
  undefined4 uStack0000001c;
  undefined4 uStack00000020;
  undefined4 entryFunction;
  undefined4 entryKind;
  undefined4 entryArgument;
  
  entryKind = 1;
  uStack00000018 = function;
  uStack0000001c = argument;
  uStack00000020 = dsoHandle;
  entryFunction = function;
  entryArgument = argument;
  result = ((int (*)())_atexit_common)(&entryFunction,dsoHandle);
  return result;
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
int _atexit(function)
  void *function;
{
  int result;
  void *pvStack00000018;
  void *entryFunction;
  undefined4 entryKind;
  
  entryKind = 0;
  pvStack00000018 = function;
  entryFunction = function;
  result = ((int (*)())_atexit_common)(&entryFunction,PTR_0000e690);
  return result;
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
int __SetSurface(accel, flags, surfaceDesc)
  int accel;
  uint flags;
  int surfaceDesc;
{
  int status;
  undefined4 outSize;
  int scalarIn0;
  uint scalarIn1;
  
  if ((flags & 0x800) == 0) {
    scalarIn0 = *(int *)(accel + 0x84);
    scalarIn1 = 0;
  }
  else {
    if (*(int *)(surfaceDesc + 0x28) == 0) {
      return -0x1ffffd28;
    }
    scalarIn0 = *(int *)(*(int *)(surfaceDesc + 0x28) + 8);
    scalarIn1 = flags;
  }
  outSize = 0x30;
  status = _io_connect_method_scalarI_structureO
                    (*(undefined4 *)(accel + 0xc),0,&scalarIn0,2,accel + 0x4c,&outSize);
  if (status == 0) {
    if ((scalarIn0 == 0) || (scalarIn1 == 0)) {
      surfaceDesc = 0;
    }
    *(int *)(accel + 0x8c) = surfaceDesc;
    status = 0;
  }
  return status;
}

/* __SetDestination @ 0x1750 (8 bytes) */
int __SetDestination(accel, destFlag, surfaceDesc)
  undefined4 accel;
  uint destFlag;
  undefined4 surfaceDesc;
{
  undefined4 status;
  
  status = ((int (*)())__SetSurface)(accel,(destFlag & 1) << 0xb,surfaceDesc);
  return status;
}

/* __LockSurface @ 0x1760 (160 bytes) */
int __LockSurface(accel, lockArg, surfaceDesc, outAddress)
  int accel;
  int lockArg;
  int surfaceDesc;
  int *outAddress;
{
  int mappedAddress;
  int status;
  undefined4 outCount;
  int scalarIn0;
  undefined4 scalarOut1;
  
  if (*(int *)(surfaceDesc + 0x28) == 0) {
    status = -0x1ffffd28;
  }
  else {
    mappedAddress = *(int *)(*(int *)(surfaceDesc + 0x28) + 4);
    if (mappedAddress == 0) {
      outCount = 2;
      scalarIn0 = lockArg;
      status = _io_connect_method_scalarI_scalarO
                        (*(undefined4 *)(accel + 0xc),5,&scalarIn0,1,&scalarIn0,&outCount);
      if (status == 0) {
        *outAddress = scalarIn0;
        *(undefined4 *)(surfaceDesc + 0x18) = scalarOut1;
      }
    }
    else {
      status = 0;
      *outAddress = mappedAddress;
    }
  }
  return status;
}

/* __UnlockSurface @ 0x1820 (144 bytes) */
int __UnlockSurface(accel, unlockArg, surfaceDesc, outValue)
  int accel;
  undefined4 unlockArg;
  int surfaceDesc;
  undefined4 *outValue;
{
  undefined4 status;
  undefined4 outCount;
  undefined4 scalarIO [7];
  
  if (*(int *)(surfaceDesc + 0x28) == 0) {
    status = 0xe00002d8;
  }
  else {
    status = 0;
    if (*(int *)(*(int *)(surfaceDesc + 0x28) + 4) == 0) {
      outCount = 1;
      scalarIO[0] = unlockArg;
      status = _io_connect_method_scalarI_scalarO
                        (*(undefined4 *)(accel + 0xc),6,scalarIO,1,scalarIO,&outCount);
      if (outValue != (undefined4 *)0x0) {
        *outValue = scalarIO[0];
      }
    }
  }
  return status;
}

/* __SwapSurface @ 0x18c0 (128 bytes) */
int __SwapSurface(accel, swapArg, surfaceDesc, outValue)
  int accel;
  undefined4 swapArg;
  int surfaceDesc;
  undefined4 *outValue;
{
  undefined4 status;
  undefined4 outCount;
  undefined4 scalarIO [7];
  
  if (*(int *)(surfaceDesc + 0x28) == 0) {
    status = 0xe00002d8;
  }
  else {
    outCount = 1;
    scalarIO[0] = swapArg;
    status = _io_connect_method_scalarI_scalarO
                      (*(undefined4 *)(accel + 0xc),3,scalarIO,1,scalarIO,&outCount);
    if (outValue != (undefined4 *)0x0) {
      *outValue = scalarIO[0];
    }
  }
  return status;
}

/* __Probe @ 0x1950 (16 bytes) */
int __Probe(unusedArg1, unusedArg2, unusedArg3, outScore)
  undefined4 unusedArg1;
  undefined4 unusedArg2;
  undefined4 unusedArg3;
  undefined4 *outScore;
{
  *outScore = 2000;
  return 0;
}

/* _window_mode_to_ati_format @ 0x1960 (148 bytes) */
int _window_mode_to_ati_format(windowMode)
  uint windowMode;
{
  switch(windowMode & 0xf) {
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
int __QueryInterface(instance, uuidWord0, uuidWord1, uuidWord2, uuidWord3, outInterface)
  int *instance;
  undefined4 uuidWord0;
  undefined4 uuidWord1;
  undefined4 uuidWord2;
  undefined4 uuidWord3;
  undefined4 *outInterface;
{
  undefined4 requestedUUID;
  undefined4 knownUUID;
  int isEqual;
  undefined4 uuidHome0;
  undefined4 uuidHome1;
  undefined4 uuidHome2;
  undefined4 uuidHome3;
  
  uuidHome0 = uuidWord0;
  uuidHome1 = uuidWord1;
  uuidHome2 = uuidWord2;
  uuidHome3 = uuidWord3;
  requestedUUID = _CFUUIDCreateFromUUIDBytes(0,uuidWord0,uuidWord1,uuidWord2,uuidWord3);
  knownUUID = _CFUUIDGetConstantUUIDWithBytes
                    (0,0x67,0x66,0xe9,0x4a,0,0,0,0,0,0,0,10,0x27,0x89,0x90,0x4e);
  isEqual = _CFEqual(requestedUUID,knownUUID);
  if (isEqual == 0) {
    knownUUID = _CFUUIDGetConstantUUIDWithBytes(0,0,0,0,0,0,0,0,0,0xc0,0,0,0,0,0,0,0x46);
    isEqual = _CFEqual(requestedUUID,knownUUID);
    if (isEqual == 0) {
      *outInterface = 0;
      return 0x80000004;
    }
  }
  (**(code **)(*instance + 8))(instance);
  *outInterface = instance;
  return 0;
}

/* __AddRef @ 0x1b80 (20 bytes) */
int __AddRef(instance)
  int instance;
{
  *(int *)(instance + 8) = *(int *)(instance + 8) + 1;
  return;
}

/* __DecodePixelFormat @ 0x1ba0 (468 bytes) */
int __DecodePixelFormat(pixelFormat, outDstFormat, outPixelClass, outBytesPerPixel, outHwColorFormat, outLog2BytesPerPixel, outTileFormat, outAtiFormat)
  uint pixelFormat;
  undefined4 *outDstFormat;
  undefined4 *outPixelClass;
  undefined4 *outBytesPerPixel;
  undefined4 *outHwColorFormat;
  undefined4 *outLog2BytesPerPixel;
  undefined4 *outTileFormat;
  undefined4 *outAtiFormat;
{
  undefined4 dstFormat;
  undefined4 tileFormat;
  undefined4 bytesPerPixel;
  undefined4 hwColorFormat;
  undefined4 pixelClass;
  undefined4 atiFormat;
  undefined4 log2BytesPerPixel;
  
  if (pixelFormat != 0x32767579) {
    if (pixelFormat < 0x3276757a) {
      if (pixelFormat == 0x10) {
        hwColorFormat = 3;
        log2BytesPerPixel = 1;
        bytesPerPixel = 2;
        pixelClass = 1;
        atiFormat = 7;
        dstFormat = 0xb;
        tileFormat = 3;
      }
      else if (pixelFormat == 0x20) {
        hwColorFormat = 6;
        log2BytesPerPixel = 2;
        bytesPerPixel = 4;
        pixelClass = 2;
        atiFormat = 0xb;
        dstFormat = 6;
        tileFormat = 4;
      }
      else {
        if (pixelFormat != 8) {
          return 0;
        }
        hwColorFormat = 9;
        log2BytesPerPixel = 0;
        bytesPerPixel = 1;
        pixelClass = 0;
        atiFormat = 0;
        dstFormat = 0;
        tileFormat = 0;
      }
      goto LAB_00001cfc;
    }
    if (pixelFormat == 0x42475241) {
      hwColorFormat = 6;
      log2BytesPerPixel = 2;
      bytesPerPixel = 4;
      pixelClass = 0;
      atiFormat = 8;
      dstFormat = 6;
      tileFormat = 10;
      goto LAB_00001cfc;
    }
    if (pixelFormat < 0x42475242) {
      if (pixelFormat != 0x42343434) {
        return 0;
      }
      hwColorFormat = 3;
      log2BytesPerPixel = 1;
      bytesPerPixel = 2;
      pixelClass = 1;
      atiFormat = 6;
      dstFormat = 10;
      tileFormat = 0;
      goto LAB_00001cfc;
    }
    if (pixelFormat != 0x59565955) {
      if (pixelFormat != 0x79757673) {
        return 0;
      }
      hwColorFormat = 3;
      log2BytesPerPixel = 1;
      bytesPerPixel = 2;
      pixelClass = 0;
      atiFormat = 0x26;
      dstFormat = 0x14;
      tileFormat = 6;
      goto LAB_00001cfc;
    }
  }
  hwColorFormat = 3;
  log2BytesPerPixel = 1;
  bytesPerPixel = 2;
  pixelClass = 0;
  atiFormat = 0x27;
  dstFormat = 0x15;
  tileFormat = 9;
LAB_00001cfc:
  if (outDstFormat != (undefined4 *)0x0) {
    *outDstFormat = dstFormat;
  }
  if (outPixelClass != (undefined4 *)0x0) {
    *outPixelClass = pixelClass;
  }
  if (outHwColorFormat != (undefined4 *)0x0) {
    *outHwColorFormat = hwColorFormat;
  }
  if (outBytesPerPixel != (undefined4 *)0x0) {
    *outBytesPerPixel = bytesPerPixel;
  }
  if (outLog2BytesPerPixel != (undefined4 *)0x0) {
    *outLog2BytesPerPixel = log2BytesPerPixel;
  }
  if (outTileFormat != (undefined4 *)0x0) {
    *outTileFormat = tileFormat;
  }
  if (outAtiFormat != (undefined4 *)0x0) {
    *outAtiFormat = atiFormat;
  }
  return 1;
}

/* _fillTextureWithPattern @ 0x1d90 (664 bytes) */
int _fillTextureWithPattern(patternRef, opFlags, backColor, foreColor)
  int *patternRef;
  uint opFlags;
  undefined4 backColor;
  undefined4 foreColor;
{
  bool columnIsLast;
  int eightRowsBytes;
  int rowBytes;
  int eightRowsTexels;
  int columnByteOffset;
  int eightRowsTexelIndex;
  uint patternWord0Cursor;
  int column;
  int dstPtr;
  uint bitCursor;
  undefined2 texel16;
  undefined4 texel32;
  int secondRowBase;
  uint patternWord1;
  int bitsLeft;
  
  if ((opFlags & 0x7ffff000) == 0x6000) {
    patternWord0Cursor = 0xffffffff;
    patternWord1 = 0xffffffff;
  }
  else {
    patternWord1 = ((uint *)*patternRef)[1];
    patternWord0Cursor = *(uint *)*patternRef;
    patternWord0Cursor = patternWord0Cursor >> 0x18 | patternWord0Cursor >> 8 & 0xff00 | (patternWord0Cursor & 0xff00) << 8 | patternWord0Cursor << 0x18;
    patternWord1 = patternWord1 >> 0x18 | patternWord1 >> 8 & 0xff00 | (patternWord1 & 0xff00) << 8 | patternWord1 << 0x18;
  }
  if (DAT_0000e724 == 0x10) {
    column = 0;
    bitsLeft = 0x20;
    bitCursor = 0x80000000;
    eightRowsBytes = _textureBufferWidth * 0x10;
    rowBytes = _textureBufferWidth * 2;
    eightRowsTexels = _textureBufferWidth * 8;
    secondRowBase = eightRowsBytes + _textureBufferBytes;
    dstPtr = _textureBufferBytes;
    do {
      texel16 = (short)foreColor;
      if ((patternWord0Cursor & bitCursor) == 0) {
        texel16 = (short)backColor;
      }
      columnIsLast = column == 7;
      columnByteOffset = column * 2;
      eightRowsTexelIndex = eightRowsTexels + column;
      column = column + 1;
      *(undefined2 *)(dstPtr + columnByteOffset) = texel16;
      *(undefined2 *)(columnByteOffset + dstPtr + 0x10) = texel16;
      *(undefined2 *)(eightRowsTexelIndex * 2 + dstPtr) = texel16;
      *(undefined2 *)(secondRowBase + columnByteOffset + 0x10) = texel16;
      if (columnIsLast) {
        dstPtr = dstPtr + rowBytes;
        column = 0;
        secondRowBase = eightRowsBytes + dstPtr;
      }
      bitCursor = bitCursor >> 1;
      bitsLeft = bitsLeft + -1;
    } while (bitsLeft != 0);
    column = 0;
    patternWord0Cursor = 0x80000000;
    bitsLeft = 0x20;
    while( true ) {
      texel16 = (short)foreColor;
      if ((patternWord1 & patternWord0Cursor) == 0) {
        texel16 = (short)backColor;
      }
      columnIsLast = column == 7;
      columnByteOffset = column * 2;
      eightRowsTexelIndex = column + eightRowsTexels;
      column = column + 1;
      *(undefined2 *)(dstPtr + columnByteOffset) = texel16;
      *(undefined2 *)(columnByteOffset + dstPtr + 0x10) = texel16;
      *(undefined2 *)(eightRowsTexelIndex * 2 + dstPtr) = texel16;
      *(undefined2 *)(secondRowBase + columnByteOffset + 0x10) = texel16;
      if (columnIsLast) {
        dstPtr = dstPtr + rowBytes;
        column = 0;
      }
      patternWord0Cursor = patternWord0Cursor >> 1;
      bitsLeft = bitsLeft + -1;
      if (bitsLeft == 0) break;
      secondRowBase = eightRowsBytes + dstPtr;
    }
  }
  else {
    column = 0;
    bitCursor = 0x80000000;
    bitsLeft = 0x20;
    eightRowsBytes = _textureBufferWidth * 0x20;
    rowBytes = _textureBufferWidth * 4;
    eightRowsTexels = _textureBufferWidth * 8;
    secondRowBase = eightRowsBytes + _textureBufferBytes;
    dstPtr = _textureBufferBytes;
    do {
      texel32 = foreColor;
      if ((patternWord0Cursor & bitCursor) == 0) {
        texel32 = backColor;
      }
      columnIsLast = column == 7;
      columnByteOffset = column * 4;
      eightRowsTexelIndex = eightRowsTexels + column;
      column = column + 1;
      *(undefined4 *)(dstPtr + columnByteOffset) = texel32;
      *(undefined4 *)(columnByteOffset + dstPtr + 0x20) = texel32;
      *(undefined4 *)(eightRowsTexelIndex * 4 + dstPtr) = texel32;
      *(undefined4 *)(secondRowBase + columnByteOffset + 0x20) = texel32;
      if (columnIsLast) {
        dstPtr = dstPtr + rowBytes;
        column = 0;
        secondRowBase = eightRowsBytes + dstPtr;
      }
      bitCursor = bitCursor >> 1;
      bitsLeft = bitsLeft + -1;
    } while (bitsLeft != 0);
    column = 0;
    patternWord0Cursor = 0x80000000;
    bitsLeft = 0x20;
    while( true ) {
      texel32 = foreColor;
      if ((patternWord1 & patternWord0Cursor) == 0) {
        texel32 = backColor;
      }
      columnIsLast = column == 7;
      columnByteOffset = column * 4;
      eightRowsTexelIndex = column + eightRowsTexels;
      column = column + 1;
      *(undefined4 *)(dstPtr + columnByteOffset) = texel32;
      *(undefined4 *)(columnByteOffset + dstPtr + 0x20) = texel32;
      *(undefined4 *)(eightRowsTexelIndex * 4 + dstPtr) = texel32;
      *(undefined4 *)(secondRowBase + columnByteOffset + 0x20) = texel32;
      if (columnIsLast) {
        dstPtr = dstPtr + rowBytes;
        column = 0;
      }
      patternWord0Cursor = patternWord0Cursor >> 1;
      bitsLeft = bitsLeft + -1;
      if (bitsLeft == 0) break;
      secondRowBase = eightRowsBytes + dstPtr;
    }
  }
  return;
}

/* __GetCapabilities @ 0x2030 (156 bytes) */
int __GetCapabilities(accel, capabilityTag, outCaps)
  int accel;
  int capabilityTag;
  undefined4 *outCaps;
{
  undefined4 status;
  
  if (capabilityTag != 0x63676c73) {
    if (capabilityTag == 0x736d766c) {
      if ((accel != 0) && (*(int *)(accel + 0xc) != 0)) {
        status = _io_connect_method_scalarI_structureI(*(int *)(accel + 0xc),0xf,outCaps,1,0,0);
        return status;
      }
      return 0xe00002d8;
    }
    if (capabilityTag != 0x42475241) {
      return 0xe00002c7;
    }
  }
  *outCaps = *(undefined4 *)PTR_0000e698;
  return 0;
}

/* __GetBlitter @ 0x20e0 (224 bytes) */
int __GetBlitter(accel, unusedArg2, operation, blitFlags, outBlitter)
  undefined4 accel;
  undefined4 unusedArg2;
  int operation;
  uint blitFlags;
  undefined4 *outBlitter;
{
  uint blitClass;
  code *blitter;
  
  blitClass = blitFlags & 0x7ffff000;
  if (operation == 1) {
    if ((blitClass == 0) || (blitClass == 0x1000)) {
      blitter = _radeonCopy;
      goto LAB_00002114;
    }
  }
  else {
    if (operation == 4) {
      blitter = (code *)&_radeonCopyRegion;
      goto LAB_00002114;
    }
    if (operation == 0) {
      if (blitClass == 0x6000) {
LAB_000021a0:
        blitter = _radeonFill;
        goto LAB_00002114;
      }
    }
    else if (operation == 0x40000) {
      if (blitClass == 0x6000) {
        blitter = _radeonHighlight;
        goto LAB_00002114;
      }
    }
    else if (operation == 0x100) {
      if (blitClass == 0x5000) goto LAB_000021a0;
    }
    else if ((operation == 3) && (blitClass == 0x6000)) {
      blitter = _radeonSolidScanlines;
      goto LAB_00002114;
    }
  }
  blitter = (code *)0x0;
LAB_00002114:
  *outBlitter = blitter;
  if (blitter == (code *)0x0) {
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
int __GetBeamPosition(accel, unusedArg2, outScanline)
  int accel;
  undefined4 unusedArg2;
  uint *outScanline;
{
  undefined4 outSize;
  uint beamData [6];
  
  beamData[0] = *(uint *)(accel + 0x90);
  outSize = 4;
  _io_connect_method_structureI_structureO
            (*(undefined4 *)(accel + 0xc),0x10,beamData,4,beamData,&outSize);
  *outScanline = beamData[0] >> 0x10 & 0x7ff;
  return;
}

/* __WaitSurface @ 0x2270 (72 bytes) */
int __WaitSurface(accel, unusedArg2, surfaceDesc)
  int accel;
  undefined4 unusedArg2;
  int surfaceDesc;
{
  undefined4 status;
  int surfaceHandle;
  
  if (*(int **)(surfaceDesc + 0x28) == (int *)0x0) {
    status = 0xe00002d8;
  }
  else {
    surfaceHandle = **(int **)(surfaceDesc + 0x28);
    status = 0;
    if (surfaceHandle != 0) {
      status = _io_connect_method_scalarI_structureI(*(undefined4 *)(accel + 0xc),0xc,surfaceHandle,1,0,0);
      return status;
    }
  }
  return status;
}

/* _ATIRadeonX1000GAFactory @ 0x22d0 (324 bytes) */
int _ATIRadeonX1000GAFactory(allocator, typeUUID)
  undefined4 allocator;
  undefined4 typeUUID;
{
  undefined4 *instance;
  undefined4 uuidRef;
  int factoryUUIDOrIsEqual;
  
  uuidRef = _CFUUIDGetConstantUUIDWithBytes(0,0xac,0xcf,0,0,0,0,0,0,0,0,0,10,0x27,0x89,0x90,0x4e);
  factoryUUIDOrIsEqual = _CFEqual(typeUUID,uuidRef);
  instance = (undefined4 *)0x0;
  if (factoryUUIDOrIsEqual != 0) {
    factoryUUIDOrIsEqual = _CFUUIDGetConstantUUIDWithBytes(0,0x10,2,0x71,0,0,0,0,0,0,0,0,10,0x27,0x89,0x8d,0x3e);
    instance = (undefined4 *)_calloc(1,0x98);
    *instance = &_radeonGAInterface;
    if (factoryUUIDOrIsEqual != 0) {
      uuidRef = _CFRetain(factoryUUIDOrIsEqual);
      instance[1] = uuidRef;
      _CFPlugInAddInstanceForFactory(factoryUUIDOrIsEqual);
    }
    instance[2] = 1;
  }
  return instance;
}

/* __Release @ 0x2420 (100 bytes) */
int __Release(instance)
  int instance;
{
  int factoryID;
  int refCount;
  
  refCount = *(int *)(instance + 8) + -1;
  *(int *)(instance + 8) = refCount;
  if (refCount == 0) {
    factoryID = *(int *)(instance + 4);
    _free(instance);
    if (factoryID != 0) {
      _CFPlugInRemoveInstanceForFactory(factoryID);
      _CFRelease(factoryID);
    }
  }
  return refCount;
}

/* __Reset @ 0x2490 (360 bytes) */
int __Reset(accel)
  int accel;
{
  uint *lastHeader;
  int status;
  undefined4 result;
  undefined4 mapSize;
  int cmdBufferAddr;
  int sharedAddr [4];
  
  if (*(int *)(accel + 0xc) == 0) {
    result = 0xe00002d8;
  }
  else {
    status = _IOConnectMapMemory(*(int *)(accel + 0xc),1,*(undefined4 *)PTR_0000e694,sharedAddr,
                                &mapSize,1);
    if ((status == 0) && (sharedAddr[0] != 0)) {
      *(int *)(accel + 0x14) = sharedAddr[0];
      mapSize = 1;
      *(undefined4 *)(sharedAddr[0] + 0x20) = 0x80000000;
      *(undefined4 *)(sharedAddr[0] + 0x14) = 1;
    }
    if (*(int *)(accel + 0x18) != 0) {
      **(undefined4 **)(accel + 0x80) = 0x1000000;
      lastHeader = *(uint **)(accel + 0x7c);
      *lastHeader = *(int *)(accel + 0x80) - (int)lastHeader >> 2 | *lastHeader;
    }
    status = _IOConnectMapMemory(*(undefined4 *)(accel + 0xc),0,*(undefined4 *)PTR_0000e694,
                                &cmdBufferAddr,&mapSize,1);
    if ((status == 0) && (cmdBufferAddr != 0)) {
      *(int *)(accel + 0x18) = cmdBufferAddr;
      *(int *)(accel + 0x80) = cmdBufferAddr + 0x20;
      *(int *)(accel + 0x7c) = cmdBufferAddr + 0x1c;
      *(undefined4 *)(cmdBufferAddr + 0x1c) = 0;
    }
    result = 0x310;
    if (*(int *)(accel + 0x84) == 0) {
      result = 0x210;
    }
    *(undefined4 *)(accel + 0x90) = result;
    *(undefined4 *)(accel + 0x94) = 0;
    result = ((int (*)())__SetDestination)(accel,0,0);
    _memcpy(accel + 0x1c,accel + 0x4c,0x30);
  }
  return result;
}

/* __Start @ 0x2610 (308 bytes) */
int __Start(accel, unusedArg2, displayID, unusedArg4, unusedArg5, unusedArg6, unusedArg7, unusedArg8)
  int accel;
  undefined4 unusedArg2;
  undefined4 displayID;
  undefined4 unusedArg4;
  undefined4 unusedArg5;
  undefined4 unusedArg6;
  undefined4 unusedArg7;
  undefined4 unusedArg8;
{
  int status;
  int accelIdSlot;
  int service;
  int connectAndCount [2];
  undefined1 className [144];
  
  accelIdSlot = accel + 0x84;
  status = _IOAccelFindAccelerator(displayID,&service,accelIdSlot);
  if (status == 0) {
    status = _IOObjectConformsTo(service,"ATIRadeonX1000");
    if (status == 0) {
      status = _IOObjectGetClass(service,className);
      if (status == 0) {
        _printf_LDBLStub("Unusual class (%s)\n",className,accelIdSlot,unusedArg4,unusedArg5,unusedArg6,unusedArg7,
                         unusedArg8);
        status = -0x1ffffd39;
      }
      else {
        status = -0x1ffffd39;
      }
    }
    else {
      status = _IOServiceOpen(service,*(undefined4 *)PTR_0000e694,2,connectAndCount);
      if (status == 0) {
        *(int *)(accel + 0x10) = service;
        *(int *)(accel + 0xc) = connectAndCount[0];
        connectAndCount[1] = 2;
        status = _io_connect_method_scalarI_scalarO(connectAndCount[0],1,0,0,accel + 0x88,connectAndCount + 1);
        if ((status == 0) && (status = ((int (*)())__Reset)(accel), status == 0)) {
          return 0;
        }
      }
      if (connectAndCount[0] != 0) {
        _IOServiceClose(connectAndCount[0]);
      }
      if (service != 0) {
        _IOObjectRelease(service);
      }
    }
  }
  return status;
}

