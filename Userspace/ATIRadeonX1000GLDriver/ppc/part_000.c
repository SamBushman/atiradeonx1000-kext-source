#include "decls.h"

/* dyld_stub_binding_helper @ 0x1740 (48 bytes) */
int dyld_stub_binding_helper()
{
                    
                    
  (*DAT_001e8740)();
  return;
}

/* dyld_func_lookup_stub @ 0x1770 (32 bytes) */
int dyld_func_lookup_stub(param_1, param_2)
  uint param_1;
  uint param_2;
{
                    
                    
  (*DAT_001e8744)(param_1,param_2);
  return;
}

/* cxa_atexit_check_2 @ 0x1790 (40 bytes) */
int cxa_atexit_check_2(state)
  undefined4 *state;
{
  *state = 1;
  return;
}

/* cxa_atexit_check_1 @ 0x17b8 (120 bytes) */
int cxa_atexit_check_1(state)
  undefined4 *state;
{
  int status;
  undefined4 *stateHome;
  
  stateHome = state;
  status = (*(code *)state[1])(cxa_atexit_check_2,state,state);
  if (status != 0) {
    *state = 0xffffffff;
  }
  return;
}

/* check_cxa_atexit @ 0x1830 (204 bytes) */
int check_cxa_atexit(cxaAtexitFn, cxaFinalizeFn)
  code *cxaAtexitFn;
  code *cxaFinalizeFn;
{
  int status;
  code *cxaAtexitFnHome;
  code *cxaFinalizeFnHome;
  /* issue #75 (follow-up): state (flag/arg, at Ghidra-derived stack offset -0x28) and
   * cxaAtexitFnCopy (the real __cxa_atexit pointer, at offset -0x24, i.e. exactly 4 bytes higher)
   * were declared as two SEPARATE C locals, but cxa_atexit_check_1 reaches cxaAtexitFnCopy purely via raw
   * pointer arithmetic on the address of state (`cxaAtexitFn[1]`, i.e. `&state + 4`) - an
   * assumption baked in from the STOCK binary's original gcc-4.0.1 stack layout, which this
   * rebuild's gcc-7 has no reason to honor. Confirmed live: gdb showed &state = 0xbffe70cc
   * but &cxaAtexitFnCopy = 0xbffe70bc (16 bytes away, not 4) - so `cxaAtexitFn[1]` inside cxa_atexit_check_1 was
   * reading an unrelated stack slot instead of the real __cxa_atexit pointer, landing on 0 and
   * crashing with pc=0 the moment __cxa_finalize (called a few lines below) invoked it. Fixed
   * by merging the two into one real struct, so their relative layout is guaranteed regardless
   * of compiler - matching the adjacency the original raw offsets assumed. */
  struct { int flag; code *real_atexit_fn; } local_2818;
  int result;

  local_2818.flag = 0;
  cxaAtexitFnHome = cxaAtexitFn;
  cxaFinalizeFnHome = cxaFinalizeFn;
  local_2818.real_atexit_fn = cxaAtexitFn;
  status = (*cxaAtexitFn)(cxa_atexit_check_1,&local_2818.flag,&local_2818.flag);
  if (status == 0) {
    (*cxaFinalizeFnHome)(&local_2818.flag);
    if (local_2818.flag == 0) {
      (*cxaFinalizeFnHome)(&local_2818.flag);
      local_2818.flag = 0;
    }
    result = local_2818.flag;
  }
  else {
    result = -1;
  }
  return result;
}

/* find_atexit_10_3 @ 0x18fc (504 bytes) */
int find_atexit_10_3()
{
  int compareResult;
  undefined4 uVar1;
  uint imageCount;
  int iVar3;
  uint imageIndex;
  code *imageCountFn;
  code *imageNameFn;
  code *imageHeaderFn;
  code *lookupSymbolFn;
  code *addressOfSymbolFn [7];
  
  ((int (*)())dyld_func_lookup_stub)((int)"__dyld_image_count",(uint)&imageCountFn);
  ((int (*)())dyld_func_lookup_stub)((int)"__dyld_get_image_name",(uint)&imageNameFn);
  ((int (*)())dyld_func_lookup_stub)((int)"__dyld_get_image_header",(uint)&imageHeaderFn);
  ((int (*)())dyld_func_lookup_stub)((int)"__dyld_NSLookupSymbolInImage",(uint)&lookupSymbolFn);
  uVar1 = ((int (*)())dyld_func_lookup_stub)((int)"__dyld_NSAddressOfSymbol",(uint)addressOfSymbolFn);
  if ((((imageCountFn != (code *)0x0) && (imageNameFn != (code *)0x0)) && (imageHeaderFn != (code *)0x0)) &&
     ((lookupSymbolFn != (code *)0x0 && (addressOfSymbolFn[0] != (code *)0x0)))) {
    imageCount = (*imageCountFn)(uVar1);
    for (imageIndex = 0; imageIndex < imageCount; imageIndex = imageIndex + 1) {
      uVar1 = (*imageNameFn)(imageIndex);
      compareResult = _strcmp(uVar1,"/usr/lib/libSystem.B.dylib");
      if (compareResult == 0) {
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

/* FUN_00001af4 @ 0x1af4 (32 bytes) */
int FUN_00001af4(param_1, param_2)
  char *param_1;
  char *param_2;
{
  _strcmp(param_1,param_2);
  return;
}

/* FUN_00001b14 @ 0x1b14 (32 bytes) */
int FUN_00001b14()
{
                    
                    
  (*DAT_001e8744)();
  return;
}

/* get_globals @ 0x1b34 (528 bytes) */
int get_globals()
{
  int libSystemHandle;
  undefined4 symbolAddress;
  int checkResult;
  int atexit_globals;
  int result;
  
  atexit_globals = __keymgr_get_and_lock_processwide_ptr(0xe);
  if ((atexit_globals == 0) && (atexit_globals = _calloc(0x14,1), atexit_globals == 0)) {
    return 0;
  }
  if (*(char *)(atexit_globals + 3) == '\0') {
    libSystemHandle = _dlopen("/usr/lib/libSystem.B.dylib",0x10);
    if (libSystemHandle == 0) {
      *(undefined1 *)(atexit_globals + 3) = 1;
      symbolAddress = ((int (*)())find_atexit_10_3)();
      *(undefined4 *)(atexit_globals + 0x10) = symbolAddress;
      if ((*(int *)(atexit_globals + 0x10) != 0) &&
         (libSystemHandle = (**(code **)(atexit_globals + 0x10))(our_atexit), libSystemHandle == 0)) goto LAB_00001d08;
    }
    else {
      symbolAddress = _dlsym(libSystemHandle,"__cxa_atexit");
      *(undefined4 *)(atexit_globals + 8) = symbolAddress;
      symbolAddress = _dlsym(libSystemHandle,"__cxa_finalize");
      *(undefined4 *)(atexit_globals + 0xc) = symbolAddress;
      if (((*(int *)(atexit_globals + 8) != 0) && (*(int *)(atexit_globals + 0xc) != 0)) &&
         (checkResult = ((int (*)())check_cxa_atexit)(*(undefined4 *)(atexit_globals + 8),*(undefined4 *)(atexit_globals + 0xc)),
         checkResult != -1)) {
        if (checkResult == 0) {
          *(undefined1 *)(atexit_globals + 3) = 2;
        }
        else {
          symbolAddress = _dlsym(libSystemHandle,"atexit");
          *(undefined4 *)(atexit_globals + 0x10) = symbolAddress;
          if (*(int *)(atexit_globals + 0x10) == 0) goto LAB_00001d14;
          *(undefined1 *)(atexit_globals + 3) = 0x10;
        }
        goto LAB_00001d08;
      }
    }
LAB_00001d14:
    __keymgr_set_and_unlock_processwide_ptr(0xe,atexit_globals);
    result = 0;
  }
  else {
LAB_00001d08:
    result = atexit_globals;
  }
  return result;
}

/* FUN_00001d44 @ 0x1d44 (32 bytes) */
int FUN_00001d44()
{
  __keymgr_set_and_unlock_processwide_ptr();
  return;
}

/* FUN_00001d64 @ 0x1d64 (32 bytes) */
int FUN_00001d64(param_1, param_2)
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
  iVar1 = (*param_1)(cxa_atexit_check_1,&iStack_28,&iStack_28);
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

/* dlsym_stub_00001d84 @ 0x1d84 (32 bytes) */
int dlsym_stub_00001d84()
{
  _dlsym();
  return;
}

/* FUN_00001da4 @ 0x1da4 (32 bytes) */
int FUN_00001da4()
{
  int compareResult;
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
  
  ((int (*)())dyld_func_lookup_stub)("__dyld_image_count",&pcStack_34);
  ((int (*)())dyld_func_lookup_stub)("__dyld_get_image_name",&pcStack_30);
  ((int (*)())dyld_func_lookup_stub)("__dyld_get_image_header",&pcStack_2c);
  ((int (*)())dyld_func_lookup_stub)("__dyld_NSLookupSymbolInImage",&pcStack_28);
  ((int (*)())dyld_func_lookup_stub)("__dyld_NSAddressOfSymbol",apcStack_24);
  if ((((pcStack_34 != (code *)0x0) && (pcStack_30 != (code *)0x0)) && (pcStack_2c != (code *)0x0))
     && ((pcStack_28 != (code *)0x0 && (apcStack_24[0] != (code *)0x0)))) {
    uVar1 = (*pcStack_34)();
    for (uStack_38 = 0; uStack_38 < uVar1; uStack_38 = uStack_38 + 1) {
      pcVar2 = (char *)(*pcStack_30)(uStack_38);
      compareResult = _strcmp(pcVar2,"/usr/lib/libSystem.B.dylib");
      if (compareResult == 0) {
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

/* dlopen_stub_00001dc4 @ 0x1dc4 (32 bytes) */
int dlopen_stub_00001dc4()
{
  _dlopen();
  return;
}

/* calloc_stub_00001de4 @ 0x1de4 (32 bytes) */
int calloc_stub_00001de4(count, size)
  size_t count;
  size_t size;
{
  _calloc(count,size);
  return;
}

/* FUN_00001e04 @ 0x1e04 (32 bytes) */
int FUN_00001e04()
{
  __keymgr_get_and_lock_processwide_ptr();
  return;
}

/* add_routine @ 0x1e24 (268 bytes) */
int add_routine(atexit_globals, routine)
  int atexit_globals;
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
  
  globalsHome = atexit_globals;
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
    if ((*(ushort *)(*(int *)(PTR_001e88a4 + 8) + 4) < 4) || (unlockResult == 0)) {
      status = 0;
    }
    else {
      status = 0xffffffff;
    }
    result = status;
  }
  return result;
}

/* FUN_00001f30 @ 0x1f30 (32 bytes) */
int FUN_00001f30()
{
  __keymgr_set_and_unlock_processwide_ptr();
  return;
}

/* malloc_stub_00001f50 @ 0x1f50 (32 bytes) */
int malloc_stub_00001f50(size)
  size_t size;
{
  _malloc(size);
  return;
}

/* run_routines @ 0x1f70 (292 bytes) */
int run_routines(atexit_globals, stopNode)
  int atexit_globals;
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
  
  globalsHome = atexit_globals;
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

/* FUN_00002094 @ 0x2094 (32 bytes) */
int FUN_00002094()
{
  __keymgr_get_and_lock_processwide_ptr();
  return;
}

/* free_stub_000020b4 @ 0x20b4 (32 bytes) */
int free_stub_000020b4(ptr)
  void *ptr;
{
  _free(ptr);
  return;
}

/* FUN_000020d4 @ 0x20d4 (32 bytes) */
int FUN_000020d4()
{
  __keymgr_set_and_unlock_processwide_ptr();
  return;
}

/* cxa_atexit_wrapper @ 0x20f4 (312 bytes) */
int cxa_atexit_wrapper(atexit_entry)
  undefined4 *atexit_entry;
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
  int atexit_globals;
  
  savedList = 0;
  savedRunning = 0;
  entryHome = atexit_entry;
  atexit_globals = __keymgr_get_and_lock_processwide_ptr(0xe);
  a0 = 0;
  a1 = extraout_r4;
  if (atexit_globals != 0) {
    savedRunning = *(undefined1 *)(atexit_globals + 2);
    *(undefined1 *)(atexit_globals + 2) = 1;
    savedList = *(undefined4 *)(atexit_globals + 4);
    a0 = __keymgr_set_and_unlock_processwide_ptr(0xe,atexit_globals);
    a1 = extraout_r4_00;
  }
  if (atexit_entry[1] == 0) {
    (*(code *)*atexit_entry)(a0);
  }
  else {
    (*(code *)*atexit_entry)(atexit_entry[2],a1,in_r5,in_r6,in_r7,in_r8,(code *)*atexit_entry);
  }
  if (atexit_globals != 0) {
    atexit_globals = __keymgr_get_and_lock_processwide_ptr(0xe);
  }
  if (atexit_globals != 0) {
    atexit_globals = ((int (*)())run_routines)(atexit_globals,savedList);
  }
  if (atexit_globals != 0) {
    *(undefined1 *)(atexit_globals + 2) = savedRunning;
    __keymgr_set_and_unlock_processwide_ptr(0xe,atexit_globals);
  }
  return;
}

/* run_routines_stub_0000222c @ 0x222c (32 bytes) */
int run_routines_stub_0000222c(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  ((int (*)())run_routines)(param_1,param_2);
  return;
}

/* FUN_0000224c @ 0x224c (32 bytes) */
int FUN_0000224c()
{
  __keymgr_set_and_unlock_processwide_ptr();
  return;
}

/* FUN_0000226c @ 0x226c (32 bytes) */
int FUN_0000226c()
{
  __keymgr_get_and_lock_processwide_ptr();
  return;
}

/* our_atexit @ 0x228c (188 bytes) */
int our_atexit()
{
  undefined1 savedRunning;
  short *atexit_globals;
  int relocked;
  
  atexit_globals = (short *)__keymgr_get_and_lock_processwide_ptr(0xe);
  if (((atexit_globals != (short *)0x0) && (*atexit_globals == 0)) && (*(char *)((int)atexit_globals + 3) == '\x01')) {
    savedRunning = *(undefined1 *)(atexit_globals + 1);
    *(undefined1 *)(atexit_globals + 1) = 1;
    relocked = ((int (*)())run_routines)(atexit_globals,0);
    if (relocked != 0) {
      *(undefined1 *)(relocked + 2) = savedRunning;
      __keymgr_set_and_unlock_processwide_ptr(0xe,relocked);
    }
  }
  return;
}

/* FUN_00002348 @ 0x2348 (32 bytes) */
int FUN_00002348()
{
  __keymgr_set_and_unlock_processwide_ptr();
  return;
}

/* FUN_00002368 @ 0x2368 (32 bytes) */
int FUN_00002368(param_1, param_2)
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

/* FUN_00002388 @ 0x2388 (32 bytes) */
int FUN_00002388()
{
  __keymgr_get_and_lock_processwide_ptr();
  return;
}

/* atexit_common @ 0x23a8 (672 bytes) */
int atexit_common(atexit_entry, dsoHandle)
  undefined4 *atexit_entry;
  undefined4 dsoHandle;
{
  code *registerFn;
  undefined4 uVar2;
  int atexit_globals;
  undefined4 *entryCopy;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  undefined4 uVar4;
  undefined4 *entryHome;
  undefined4 dsoHandleHome;
  undefined4 result;
  
  entryHome = atexit_entry;
  dsoHandleHome = dsoHandle;
  atexit_globals = ((int (*)())get_globals)();
  if (atexit_globals == 0) {
    result = 0xffffffff;
  }
  else if ((*(char *)(atexit_globals + 2) == '\0') && (*(char *)(atexit_globals + 3) != '\x01')) {
    if (*(byte *)(atexit_globals + 3) < 0x10) {
      registerFn = *(code **)(atexit_globals + 8);
      atexit_globals = __keymgr_set_and_unlock_processwide_ptr(0xe,atexit_globals);
      if ((*(ushort *)(*(int *)(PTR_001e88a4 + 8) + 4) < 4) || (atexit_globals == 0)) {
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
          result = (*registerFn)(cxa_atexit_wrapper,entryCopy,dsoHandleHome,in_r6,in_r7,in_r8,entryCopy);
        }
      }
      else {
        result = 0xffffffff;
      }
    }
    else if (entryHome[1] == 0) {
      registerFn = *(code **)(atexit_globals + 0x10);
      atexit_globals = __keymgr_set_and_unlock_processwide_ptr(0xe,atexit_globals);
      if ((*(ushort *)(*(int *)(PTR_001e88a4 + 8) + 4) < 4) || (atexit_globals == 0)) {
        result = (*registerFn)(*entryHome);
      }
      else {
        result = 0xffffffff;
      }
    }
    else {
      registerFn = *(code **)(atexit_globals + 8);
      atexit_globals = __keymgr_set_and_unlock_processwide_ptr(0xe,atexit_globals);
      if ((*(ushort *)(*(int *)(PTR_001e88a4 + 8) + 4) < 4) || (atexit_globals == 0)) {
        result = (*registerFn)(*entryHome,entryHome[2],dsoHandleHome,in_r6,in_r7,in_r8,
                             *entryHome);
      }
      else {
        result = 0xffffffff;
      }
    }
  }
  else {
    result = ((int (*)())add_routine)(atexit_globals,entryHome);
  }
  return result;
}

/* malloc_stub_00002648 @ 0x2648 (32 bytes) */
int malloc_stub_00002648(size)
  size_t size;
{
  _malloc(size);
  return;
}

/* FUN_00002668 @ 0x2668 (32 bytes) */
int FUN_00002668()
{
  __keymgr_set_and_unlock_processwide_ptr();
  return;
}

/* FUN_00002688 @ 0x2688 (32 bytes) */
int FUN_00002688(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  undefined4 uVar1;
  undefined4 *allocation;
  int iVar3;
  undefined4 uVar4;
  int iStack00000018;
  undefined4 *puStack0000001c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  iStack00000018 = param_1;
  puStack0000001c = param_2;
  allocation = _malloc(0x10);
  if (allocation == (undefined4 *)0x0) {
    __keymgr_set_and_unlock_processwide_ptr(0xe,iStack00000018);
    uStack_14 = 0xffffffff;
  }
  else {
    uVar4 = puStack0000001c[1];
    uVar1 = puStack0000001c[2];
    allocation[1] = *puStack0000001c;
    allocation[2] = uVar4;
    allocation[3] = uVar1;
    *allocation = *(undefined4 *)(iStack00000018 + 4);
    *(undefined4 **)(iStack00000018 + 4) = allocation;
    iVar3 = __keymgr_set_and_unlock_processwide_ptr(0xe,iStack00000018);
    if ((*(ushort *)(*(int *)(PTR_001e88a4 + 8) + 4) < 4) || (iVar3 == 0)) {
      uStack_18 = 0;
    }
    else {
      uStack_18 = 0xffffffff;
    }
    uStack_14 = uStack_18;
  }
  return uStack_14;
}

/* FUN_000026a8 @ 0x26a8 (32 bytes) */
int FUN_000026a8()
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
      uVar2 = ((int (*)())find_atexit_10_3)();
      *(undefined4 *)((int)pvStack_20 + 0x10) = uVar2;
      if ((*(int *)((int)pvStack_20 + 0x10) != 0) &&
         (iVar1 = (**(code **)((int)pvStack_20 + 0x10))(our_atexit), iVar1 == 0))
      goto LAB_00001d08;
    }
    else {
      uVar2 = _dlsym(iVar1,"__cxa_atexit");
      *(undefined4 *)((int)pvStack_20 + 8) = uVar2;
      uVar2 = _dlsym(iVar1,"__cxa_finalize");
      *(undefined4 *)((int)pvStack_20 + 0xc) = uVar2;
      if (((*(int *)((int)pvStack_20 + 8) != 0) && (*(int *)((int)pvStack_20 + 0xc) != 0)) &&
         (iVar3 = ((int (*)())check_cxa_atexit)(*(undefined4 *)((int)pvStack_20 + 8),
                               *(undefined4 *)((int)pvStack_20 + 0xc)), iVar3 != -1)) {
        if (iVar3 == 0) {
          *(undefined1 *)((int)pvStack_20 + 3) = 2;
        }
        else {
          uVar2 = _dlsym(iVar1,"atexit");
          *(undefined4 *)((int)pvStack_20 + 0x10) = uVar2;
          if (*(int *)((int)pvStack_20 + 0x10) == 0) goto LAB_00001d14;
          *(undefined1 *)((int)pvStack_20 + 3) = 0x10;
        }
        goto LAB_00001d08;
      }
    }
LAB_00001d14:
    __keymgr_set_and_unlock_processwide_ptr(0xe,pvStack_20);
    pvStack_18 = (void *)0x0;
  }
  else {
LAB_00001d08:
    pvStack_18 = pvStack_20;
  }
  return pvStack_18;
}

/* cxa_atexit @ 0x26c8 (96 bytes) */
int cxa_atexit(atexit_function, argument, dsoHandle)
  undefined4 atexit_function;
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
  uStack00000018 = atexit_function;
  uStack0000001c = argument;
  uStack00000020 = dsoHandle;
  entryFunction = atexit_function;
  entryArgument = argument;
  result = ((int (*)())atexit_common)(&entryFunction,dsoHandle);
  return result;
}

/* FUN_00002728 @ 0x2728 (32 bytes) */
int FUN_00002728(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  int exceptionGlobals;
  code *pcVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *allocation;
  undefined4 uVar5;
  undefined4 *puStack00000018;
  undefined4 uStack0000001c;
  undefined4 uStack_18;
  
  puStack00000018 = param_1;
  uStack0000001c = param_2;
  exceptionGlobals = ((int (*)())get_globals)();
  if (exceptionGlobals == 0) {
    uStack_18 = 0xffffffff;
  }
  else if ((*(char *)(exceptionGlobals + 2) == '\0') && (*(char *)(exceptionGlobals + 3) != '\x01')) {
    if (*(byte *)(exceptionGlobals + 3) < 0x10) {
      pcVar1 = *(code **)(exceptionGlobals + 8);
      iVar3 = __keymgr_set_and_unlock_processwide_ptr(0xe,exceptionGlobals);
      if ((*(ushort *)(*(int *)(PTR_001e88a4 + 8) + 4) < 4) || (iVar3 == 0)) {
        allocation = _malloc(0xc);
        if (allocation == (undefined4 *)0x0) {
          uStack_18 = 0xffffffff;
        }
        else {
          uVar5 = puStack00000018[1];
          uVar2 = puStack00000018[2];
          *allocation = *puStack00000018;
          allocation[1] = uVar5;
          allocation[2] = uVar2;
          uStack_18 = (*pcVar1)(cxa_atexit_wrapper,allocation,uStack0000001c);
        }
      }
      else {
        uStack_18 = 0xffffffff;
      }
    }
    else if (puStack00000018[1] == 0) {
      pcVar1 = *(code **)(exceptionGlobals + 0x10);
      iVar3 = __keymgr_set_and_unlock_processwide_ptr(0xe,exceptionGlobals);
      if ((*(ushort *)(*(int *)(PTR_001e88a4 + 8) + 4) < 4) || (iVar3 == 0)) {
        uStack_18 = (*pcVar1)(*puStack00000018);
      }
      else {
        uStack_18 = 0xffffffff;
      }
    }
    else {
      pcVar1 = *(code **)(exceptionGlobals + 8);
      iVar3 = __keymgr_set_and_unlock_processwide_ptr(0xe,exceptionGlobals);
      if ((*(ushort *)(*(int *)(PTR_001e88a4 + 8) + 4) < 4) || (iVar3 == 0)) {
        uStack_18 = (*pcVar1)(*puStack00000018,puStack00000018[2],uStack0000001c);
      }
      else {
        uStack_18 = 0xffffffff;
      }
    }
  }
  else {
    uStack_18 = ((int (*)())add_routine)(exceptionGlobals,puStack00000018);
  }
  return uStack_18;
}

/* atexit @ 0x2748 (92 bytes) */
int atexit(atexit_function)
  undefined4 atexit_function;
{
  undefined4 result;
  undefined4 uStack00000018;
  undefined4 entryFunction;
  undefined4 entryKind;
  
  entryKind = 0;
  uStack00000018 = atexit_function;
  entryFunction = atexit_function;
  result = ((int (*)())atexit_common)(&entryFunction,PTR_001e88a8);
  return result;
}

/* FUN_000027a4 @ 0x27a4 (32 bytes) */
int FUN_000027a4(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  int exceptionGlobals;
  code *pcVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *allocation;
  undefined4 uVar5;
  undefined4 *puStack00000018;
  undefined4 uStack0000001c;
  undefined4 uStack_18;
  
  puStack00000018 = param_1;
  uStack0000001c = param_2;
  exceptionGlobals = ((int (*)())get_globals)();
  if (exceptionGlobals == 0) {
    uStack_18 = 0xffffffff;
  }
  else if ((*(char *)(exceptionGlobals + 2) == '\0') && (*(char *)(exceptionGlobals + 3) != '\x01')) {
    if (*(byte *)(exceptionGlobals + 3) < 0x10) {
      pcVar1 = *(code **)(exceptionGlobals + 8);
      iVar3 = __keymgr_set_and_unlock_processwide_ptr(0xe,exceptionGlobals);
      if ((*(ushort *)(*(int *)(PTR_001e88a4 + 8) + 4) < 4) || (iVar3 == 0)) {
        allocation = _malloc(0xc);
        if (allocation == (undefined4 *)0x0) {
          uStack_18 = 0xffffffff;
        }
        else {
          uVar5 = puStack00000018[1];
          uVar2 = puStack00000018[2];
          *allocation = *puStack00000018;
          allocation[1] = uVar5;
          allocation[2] = uVar2;
          uStack_18 = (*pcVar1)(cxa_atexit_wrapper,allocation,uStack0000001c);
        }
      }
      else {
        uStack_18 = 0xffffffff;
      }
    }
    else if (puStack00000018[1] == 0) {
      pcVar1 = *(code **)(exceptionGlobals + 0x10);
      iVar3 = __keymgr_set_and_unlock_processwide_ptr(0xe,exceptionGlobals);
      if ((*(ushort *)(*(int *)(PTR_001e88a4 + 8) + 4) < 4) || (iVar3 == 0)) {
        uStack_18 = (*pcVar1)(*puStack00000018);
      }
      else {
        uStack_18 = 0xffffffff;
      }
    }
    else {
      pcVar1 = *(code **)(exceptionGlobals + 8);
      iVar3 = __keymgr_set_and_unlock_processwide_ptr(0xe,exceptionGlobals);
      if ((*(ushort *)(*(int *)(PTR_001e88a4 + 8) + 4) < 4) || (iVar3 == 0)) {
        uStack_18 = (*pcVar1)(*puStack00000018,puStack00000018[2],uStack0000001c);
      }
      else {
        uStack_18 = 0xffffffff;
      }
    }
  }
  else {
    uStack_18 = ((int (*)())add_routine)(exceptionGlobals,puStack00000018);
  }
  return uStack_18;
}

/* FUN_000027d0 @ 0x27d0 (776 bytes) */
int FUN_000027d0(ctx, param_2)
  int ctx;
  int param_2;
{
  int loopIndex;
  uint uVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  undefined1 uVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined8 *puVar8;
  undefined8 *puVar9;
  int iVar10;
  int renderHeight;
  uint uVar12;
  int iVar13;
  int iVar14;
  int renderWidth;
  uint uVar16;
  undefined1 uStack_66;
  undefined1 uStack_65;
  
  if (((unsigned char *)0x00003190)[param_2] == '\0') {
    if ((((*(float *)(((unsigned char *)0x00002d90) + param_2) < FLOAT_001aa0d4) ||
         (*(float *)(((unsigned char *)0x00002d94) + param_2) < FLOAT_001aa0d4)) ||
        (*(float *)(((unsigned char *)0x00002d98) + param_2) < FLOAT_001aa0d4)) ||
       (uVar4 = 0, *(float *)(((unsigned char *)0x00002d9c) + param_2) < FLOAT_001aa0d4)) {
      uVar4 = 1;
    }
    renderWidth = *(int *)(ctx + 0x15c);
    renderHeight = *(int *)(ctx + 0x160);
    iVar14 = 0;
    iVar5 = 0;
    *(undefined1 *)(ctx + 0x140) = uVar4;
    uVar12 = renderWidth + 7U & 0xfffffff8;
    iVar13 = renderHeight;
  }
  else {
    renderHeight = *(int *)(ctx + 0x160);
    *(undefined1 *)(ctx + 0x140) = 1;
    iVar14 = *(int *)(((unsigned char *)0x00003180) + param_2);
    uVar12 = iVar14 + *(int *)(((unsigned char *)0x00003188) + param_2);
    iVar5 = renderHeight - (*(int *)(((unsigned char *)0x0000318c) + param_2) + *(int *)(((unsigned char *)0x00003184) + param_2));
    iVar13 = *(int *)(((unsigned char *)0x0000318c) + param_2) + iVar5;
    if (iVar14 < 0) {
      iVar14 = 0;
    }
    if (iVar5 < 0) {
      iVar5 = 0;
    }
    renderWidth = *(int *)(ctx + 0x15c);
    uVar1 = renderWidth + 7U & 0xfffffff8;
    if ((int)uVar1 < (int)uVar12) {
      uVar12 = uVar1;
    }
    iVar10 = renderHeight;
    if (iVar13 <= renderHeight) {
      iVar10 = iVar13;
    }
    uVar12 = uVar12 - iVar14;
    iVar13 = iVar10 - iVar5;
  }
  if ((0 < (int)uVar12) && (0 < iVar13)) {
    uVar1 = renderWidth + 7U & 0xfffffff8;
    iVar14 = iVar14 + uVar1 * (renderHeight - (iVar5 + iVar13));
    if (*(char *)(ctx + 0x141) == '\x01') {
      puVar6 = (undefined4 *)(iVar14 * 4 + *(int *)(ctx + 0x148));
      uVar2 = CONCAT31(CONCAT21(CONCAT11((char)(int)(*(float *)(((unsigned char *)0x00002d90) + param_2) *
                                                    FLOAT_001aa0cc),
                                         (char)(int)(*(float *)(((unsigned char *)0x00002d94) + param_2) *
                                                    FLOAT_001aa0cc)),
                                (char)(int)(*(float *)(((unsigned char *)0x00002d98) + param_2) * FLOAT_001aa0cc)),
                       (char)(int)(*(float *)(((unsigned char *)0x00002d9c) + param_2) * FLOAT_001aa0cc));
      if ((iVar13 == 1) || (uVar12 == uVar1)) {
        iVar13 = uVar12 * iVar13;
        if (0 < iVar13) {
          do {
            *puVar6 = uVar2;
            puVar6 = puVar6 + 1;
            iVar13 = iVar13 + -1;
          } while (iVar13 != 0);
        }
      }
      else {
        loopIndex = 0;
        uVar16 = uVar12;
        puVar7 = puVar6;
        do {
          do {
            *puVar6 = uVar2;
            puVar6 = puVar6 + 1;
            uVar16 = uVar16 - 1;
          } while (uVar16 != 0);
          loopIndex = loopIndex + 1;
          puVar6 = puVar7 + uVar1;
          uVar16 = uVar12;
          puVar7 = puVar6;
        } while (iVar13 != loopIndex);
      }
    }
    else if (*(char *)(ctx + 0x141) == '\x02') {
      puVar8 = (undefined8 *)(iVar14 * 8 + *(int *)(ctx + 0x148));
      uStack_66 = (undefined1)
                  ((uint)(int)(*(float *)(((unsigned char *)0x00002d94) + param_2) * FLOAT_001aa0d0) >> 8);
      uStack_65 = (undefined1)(int)(*(float *)(((unsigned char *)0x00002d94) + param_2) * FLOAT_001aa0d0);
      uVar3 = CONCAT62(CONCAT42(CONCAT31(CONCAT21((short)(int)(*(float *)(((unsigned char *)0x00002d90) + param_2) *
                                                              FLOAT_001aa0d0),uStack_66),uStack_65),
                                (short)(int)(*(float *)(((unsigned char *)0x00002d98) + param_2) * FLOAT_001aa0d0)),
                       (short)(int)(*(float *)(((unsigned char *)0x00002d9c) + param_2) * FLOAT_001aa0d0));
      if ((iVar13 == 1) || (uVar12 == uVar1)) {
        iVar13 = uVar12 * iVar13;
        if (0 < iVar13) {
          do {
            *puVar8 = uVar3;
            puVar8 = puVar8 + 1;
            iVar13 = iVar13 + -1;
          } while (iVar13 != 0);
        }
      }
      else {
        loopIndex = 0;
        uVar16 = uVar12;
        puVar9 = puVar8;
        do {
          do {
            *puVar8 = uVar3;
            puVar8 = puVar8 + 1;
            uVar16 = uVar16 - 1;
          } while (uVar16 != 0);
          loopIndex = loopIndex + 1;
          puVar8 = puVar9 + uVar1;
          uVar16 = uVar12;
          puVar9 = puVar8;
        } while (iVar13 != loopIndex);
      }
    }
  }
  return;
}

/* glAccum_impl @ 0x2ae0 (88 bytes) */
void glAccum_impl(int glContext,undefined4 op,double value)
{
  double zeroD;
  float valueScaleB;
  float reciprocalValue;
  float alphaScale;
  char valueByte;
  int alphaClamped8to16;
  int greenClamped8to16;
  int alphaByte;
  ushort blueClamped16to16;
  ushort greenClamped16to16;
  ushort redClamped16to16;
  ushort blueClamped8to16;
  ushort pixelShr9;
  uint rectBottomRet2;
  uint blueByte;
  uint redClamped16to32;
  uint redClamped8to32;
  uint texelShl5;
  uint blueClamped16to32;
  uint rectRight;
  uint greenClamped16to32;
  uint rectTopB;
  uint rectBottomA;
  uint paddedWidthB;
  uint rectXB;
  int rowBytes;
  int rectBottomRaw;
  int rectWidthPixels;
  int alphaClamped16to16;
  int redClamped8to16;
  int accumBufferD;
  int rectTopAdd;
  int rectTopMul;
  int rowCounterC;
  int rectXThenRowStartB;
  int accumBufferB;
  int rowStartPixelRetB;
  int shiftCount;
  int fullWidthB;
  int rowStartPixelRet;
  int rectBottomClampB;
  int rowCounterB;
  int multiplierInt;
  int divisor;
  int fullHeightB;
  int rectHeightThenBottom;
  int engineStateB;
  int rowCounter;
  int fixedValue;
  int rectHeight;
  int engineState;
  int accumBuffer;
  uint rectBottomRet;
  short *accumShortCursorRet;
  short *accumShortEndRet;
  char *accumByteCursorRet;
  char *accumByteEndRet;
  ushort *accumHalfEndRet;
  ushort *readbackHalfDestCursor;
  ushort *accumHalfCursorSrc16;
  ushort *accumHalfCursor;
  float valueScale;
  float redOut;
  byte texelShr8;
  byte texelShr3;
  float scaledSample;
  float alpha1Out;
  float green5Out;
  float blue5Out;
  float red5Out;
  ushort pixelShr16;
  float zeroF;
  float channelMax31;
  uint pixelWord;
  char hasNegativeValues;
  ushort pixelShr17;
  int alphaClamped8to32;
  int redByte;
  int greenByte;
  uint alphaClamped16to32;
  int fullWidth;
  uint rectWidth;
  void *readbackPixels;
  int rectXThenRowStart;
  undefined1 *accumRawByteCursor;
  undefined2 *accumRaw16Cursor;
  int fullHeight;
  ushort texel16;
  int rowCounterLoad;
  uint rectTop;
  char *accumByteEnd;
  uint paddedWidthA;
  byte *accumUByteEnd;
  ushort *accumHalfEnd;
  int rectBottomClamp;
  byte *accumUByteCursor;
  int accumBufferC;
  char *accumByteCursor;
  short *accumShortCursor;
  ushort pixelShr1;
  short *accumShortEnd;
  int rowCounterD;
  ushort *readbackHalfCursor;
  uint *readbackWordCursor;
  uint greenClamped8to32;
  uint paddedRowPixels;
  uint blueClamped8to32;
  undefined1 *accumRawByteEnd;
  ushort *accumHalfEndSrc16;
  undefined2 *accumRaw16End;
  double scaledSampleD;
  double intBiasD;
  double clampMinD;
  double channelMax255D;
  double blueOut;
  double greenOut;
  double alphaOut;
  short accumFixedValueA8S16;
  short accumFixedValueA16S16;
  short accumFixedValueA8S32;
  short accumFixedValueA16S32;
  short loadFixedValueA8S16;
  short loadFixedValueA16S16;
  short loadFixedValueA8S32;
  short loadFixedValueA16S32;
  short addFixedValueA8;
  
  accumBuffer = *(int *)(glContext + 0x148);
  if (accumBuffer == 0) {
    return;
  }
  switch(op) {
  case 0x100:
    if ((*(uint *)(glContext + 0x154) & 3) == 0) {
      engineState = *(int *)(glContext + 0x10);
      if (((unsigned char *)0x00003190)[engineState] == '\0') {
        fullWidth = *(int *)(glContext + 0x15c);
        fullHeight = *(int *)(glContext + 0x160);
        rectXThenRowStart = 0;
        rectTop = 0;
        rectWidth = fullWidth + 7U & 0xfffffff8;
        rectHeight = fullHeight;
      }
      else {
        rectXThenRowStart = *(int *)(((unsigned char *)0x00003180) + engineState);
        fullHeight = *(int *)(glContext + 0x160);
        rectWidth = rectXThenRowStart + *(int *)(((unsigned char *)0x00003188) + engineState);
        rectTop = fullHeight - (*(int *)(((unsigned char *)0x0000318c) + engineState) + *(int *)(((unsigned char *)0x00003184) + engineState));
        engineState = *(int *)(((unsigned char *)0x0000318c) + engineState) + rectTop;
        if (rectXThenRowStart < 0) {
          rectXThenRowStart = 0;
        }
        if ((int)rectTop < 0) {
          rectTop = 0;
        }
        fullWidth = *(int *)(glContext + 0x15c);
        paddedWidthA = fullWidth + 7U & 0xfffffff8;
        if ((int)paddedWidthA < (int)rectWidth) {
          rectWidth = paddedWidthA;
        }
        rectBottomClamp = fullHeight;
        if (engineState <= fullHeight) {
          rectBottomClamp = engineState;
        }
        rectWidth = rectWidth - rectXThenRowStart;
        rectHeight = rectBottomClamp - rectTop;
      }
      if (rectWidth == 0) {
        return;
      }
      if (rectHeight == 0) {
        return;
      }
      readbackPixels = _malloc((fullWidth + 7U & 0xfffffff8) * fullHeight * 4);
      glReadPixels_entry(glContext,0,0,*(int *)(glContext + 0x15c) + 7U & 0xfffffff8,
                   *(undefined4 *)(glContext + 0x160),0x80e1,0x8367,readbackPixels,2,0);
      rectBottomA = rectTop + rectHeight;
      if (value < (double)FLOAT_001aa0d4) {
        *(undefined1 *)(glContext + 0x140) = 1;
      }
      paddedRowPixels = *(int *)(glContext + 0x15c) + 7U & 0xfffffff8;
      rectXThenRowStart = rectXThenRowStart + paddedRowPixels * ((*(int *)(glContext + 0x160) - rectTop) + -1);
      if (*(char *)(glContext + 0x141) == '\x01') {
        accumFixedValueA8S32 = (short)(int)(value * (double)FLOAT_001aa0d8);
        fixedValue = (int)accumFixedValueA8S32;
        if (rectTop < rectBottomA) {
          rowCounter = 0;
          do {
            readbackWordCursor = (uint *)((int)readbackPixels + rectXThenRowStart * 4);
            accumByteCursor = (char *)(rectXThenRowStart * 4 + *(int *)(glContext + 0x148));
            accumByteEnd = accumByteCursor + rectWidth * 4;
            for (; accumByteCursor < accumByteEnd; accumByteCursor = accumByteCursor + 4) {
              pixelWord = *readbackWordCursor;
              readbackWordCursor = readbackWordCursor + 1;
              *accumByteCursor = (char)((int)(fixedValue * (pixelWord >> 9 & 0x7f80 | pixelWord >> 0x11 & 0x7f)) >>
                               0x17) + *accumByteCursor;
              accumByteCursor[3] = (char)((int)(fixedValue * (pixelWord >> 0x11 & 0x7f80 | pixelWord >> 0x19)) >> 0x17
                                 ) + accumByteCursor[3];
              accumByteCursor[1] = (char)((int)(fixedValue * (pixelWord >> 1 & 0x7f80 | pixelWord >> 9 & 0x7f)) >>
                                 0x17) + accumByteCursor[1];
              accumByteCursor[2] = (char)((int)(fixedValue * ((pixelWord & 0xff) << 7 | pixelWord >> 1 & 0x7f)) >>
                                 0x17) + accumByteCursor[2];
            }
            rowCounter = rowCounter + 1;
            rectXThenRowStart = rectXThenRowStart - paddedRowPixels;
          } while (rectBottomA - rectTop != rowCounter);
        }
      }
      else {
        accumFixedValueA16S32 = (short)(int)(value * (double)FLOAT_001aa0d8);
        fixedValue = (int)accumFixedValueA16S32;
        if (rectTop < rectBottomA) {
          rowCounter = 0;
          do {
            readbackWordCursor = (uint *)((int)readbackPixels + rectXThenRowStart * 4);
            accumShortCursor = (short *)(rectXThenRowStart * 8 + *(int *)(glContext + 0x148));
            accumShortEnd = accumShortCursor + rectWidth * 4;
            for (; accumShortCursor < accumShortEnd; accumShortCursor = accumShortCursor + 4) {
              pixelWord = *readbackWordCursor;
              readbackWordCursor = readbackWordCursor + 1;
              *accumShortCursor = (short)((int)(fixedValue * (pixelWord >> 9 & 0x7f80 | pixelWord >> 0x11 & 0x7f)) >>
                                0xf) + *accumShortCursor;
              accumShortCursor[3] = (short)((int)(fixedValue * (pixelWord >> 0x11 & 0x7f80 | pixelWord >> 0x19)) >> 0xf
                                  ) + accumShortCursor[3];
              accumShortCursor[1] = (short)((int)(fixedValue * (pixelWord >> 1 & 0x7f80 | pixelWord >> 9 & 0x7f)) >>
                                  0xf) + accumShortCursor[1];
              accumShortCursor[2] = (short)((int)(fixedValue * ((pixelWord & 0xff) << 7 | pixelWord >> 1 & 0x7f)) >>
                                  0xf) + accumShortCursor[2];
            }
            rowCounter = rowCounter + 1;
            rectXThenRowStart = rectXThenRowStart - paddedRowPixels;
          } while (rectBottomA - rectTop != rowCounter);
        }
      }
    }
    else {
      engineState = *(int *)(glContext + 0x10);
      if (((unsigned char *)0x00003190)[engineState] == '\0') {
        fullWidth = *(int *)(glContext + 0x15c);
        fullHeight = *(int *)(glContext + 0x160);
        rectXThenRowStart = 0;
        rectTop = 0;
        rectWidth = fullWidth + 7U & 0xfffffff8;
        rectHeight = fullHeight;
      }
      else {
        rectXThenRowStart = *(int *)(((unsigned char *)0x00003180) + engineState);
        fullHeight = *(int *)(glContext + 0x160);
        rectWidth = rectXThenRowStart + *(int *)(((unsigned char *)0x00003188) + engineState);
        rectTop = fullHeight - (*(int *)(((unsigned char *)0x0000318c) + engineState) + *(int *)(((unsigned char *)0x00003184) + engineState));
        engineState = *(int *)(((unsigned char *)0x0000318c) + engineState) + rectTop;
        if (rectXThenRowStart < 0) {
          rectXThenRowStart = 0;
        }
        if ((int)rectTop < 0) {
          rectTop = 0;
        }
        fullWidth = *(int *)(glContext + 0x15c);
        paddedWidthA = fullWidth + 7U & 0xfffffff8;
        if ((int)paddedWidthA < (int)rectWidth) {
          rectWidth = paddedWidthA;
        }
        rectBottomClamp = fullHeight;
        if (engineState <= fullHeight) {
          rectBottomClamp = engineState;
        }
        rectWidth = rectWidth - rectXThenRowStart;
        rectHeight = rectBottomClamp - rectTop;
      }
      if (rectWidth == 0) {
        return;
      }
      if (rectHeight == 0) {
        return;
      }
      readbackPixels = _malloc((fullWidth + 7U & 0xfffffff8) * fullHeight * 2);
      glReadPixels_entry(glContext,0,0,*(int *)(glContext + 0x15c) + 7U & 0xfffffff8,
                   *(undefined4 *)(glContext + 0x160),0x80e1,0x8366,readbackPixels,2,0);
      rectBottomA = rectTop + rectHeight;
      if (value < (double)FLOAT_001aa0d4) {
        *(undefined1 *)(glContext + 0x140) = 1;
      }
      paddedRowPixels = *(int *)(glContext + 0x15c) + 7U & 0xfffffff8;
      rectXThenRowStart = rectXThenRowStart + paddedRowPixels * ((*(int *)(glContext + 0x160) - rectTop) + -1);
      if (*(char *)(glContext + 0x141) == '\x01') {
        accumFixedValueA8S16 = (short)(int)(value * (double)FLOAT_001aa0d8);
        fixedValue = (int)accumFixedValueA8S16;
        if (rectTop < rectBottomA) {
          rowCounter = 0;
          do {
            readbackHalfCursor = (ushort *)((int)readbackPixels + rectXThenRowStart * 2);
            accumByteCursor = (char *)(rectXThenRowStart * 4 + *(int *)(glContext + 0x148));
            accumByteEnd = accumByteCursor + rectWidth * 4;
            for (; accumByteCursor < accumByteEnd; accumByteCursor = accumByteCursor + 4) {
              texel16 = *readbackHalfCursor;
              readbackHalfCursor = readbackHalfCursor + 1;
              texelShl5 = (uint)texel16 << 5;
              accumByteCursor[1] = (char)((int)(fixedValue * (texelShl5 & 0x7c00 | texel16 & 0x3e0 |
                                                 texel16 >> 5 & 0x1f)) >> 0x17) + accumByteCursor[1];
              accumByteCursor[3] = (char)((int)(fixedValue * (-(uint)(texel16 >> 0xf) & 0x7fff)) >> 0x17) +
                           accumByteCursor[3];
              *accumByteCursor = (char)((int)(fixedValue * (texel16 & 0x7c00 | texel16 >> 5 & 0x3e0 |
                                               texel16 >> 10 & 0x1f)) >> 0x17) + *accumByteCursor;
              accumByteCursor[2] = (char)((int)(fixedValue * ((texel16 & 0x1f) << 10 | texelShl5 & 0x3e0 |
                                                 texel16 & 0x1f)) >> 0x17) + accumByteCursor[2];
            }
            rowCounter = rowCounter + 1;
            rectXThenRowStart = rectXThenRowStart - paddedRowPixels;
          } while (rectBottomA - rectTop != rowCounter);
        }
      }
      else {
        accumFixedValueA16S16 = (short)(int)(value * (double)FLOAT_001aa0d8);
        fixedValue = (int)accumFixedValueA16S16;
        if (rectTop < rectBottomA) {
          rowCounter = 0;
          do {
            readbackHalfCursor = (ushort *)((int)readbackPixels + rectXThenRowStart * 2);
            accumShortCursor = (short *)(rectXThenRowStart * 8 + *(int *)(glContext + 0x148));
            accumShortEnd = accumShortCursor + rectWidth * 4;
            for (; accumShortCursor < accumShortEnd; accumShortCursor = accumShortCursor + 4) {
              texel16 = *readbackHalfCursor;
              readbackHalfCursor = readbackHalfCursor + 1;
              texelShl5 = (uint)texel16 << 5;
              accumShortCursor[1] = (short)((int)(fixedValue * (texelShl5 & 0x7c00 | texel16 & 0x3e0 |
                                                  texel16 >> 5 & 0x1f)) >> 0xf) + accumShortCursor[1];
              accumShortCursor[3] = (short)((int)(fixedValue * (-(uint)(texel16 >> 0xf) & 0x7fff)) >> 0xf) +
                           accumShortCursor[3];
              *accumShortCursor = (short)((int)(fixedValue * (texel16 & 0x7c00 | texel16 >> 5 & 0x3e0 |
                                                texel16 >> 10 & 0x1f)) >> 0xf) + *accumShortCursor;
              accumShortCursor[2] = (short)((int)(fixedValue * ((texel16 & 0x1f) << 10 | texelShl5 & 0x3e0 |
                                                  texel16 & 0x1f)) >> 0xf) + accumShortCursor[2];
            }
            rowCounter = rowCounter + 1;
            rectXThenRowStart = rectXThenRowStart - paddedRowPixels;
          } while (rectBottomA - rectTop != rowCounter);
        }
      }
    }
    goto code_r0x00003264;
  case 0x101:
    if ((*(uint *)(glContext + 0x154) & 3) == 0) {
      engineState = *(int *)(glContext + 0x10);
      if (((unsigned char *)0x00003190)[engineState] == '\0') {
        fullWidth = *(int *)(glContext + 0x15c);
        fullHeight = *(int *)(glContext + 0x160);
        rectXThenRowStart = 0;
        rectTop = 0;
        rectWidth = fullWidth + 7U & 0xfffffff8;
        rectHeight = fullHeight;
      }
      else {
        rectXThenRowStart = *(int *)(((unsigned char *)0x00003180) + engineState);
        fullHeight = *(int *)(glContext + 0x160);
        rectWidth = rectXThenRowStart + *(int *)(((unsigned char *)0x00003188) + engineState);
        rectTop = fullHeight - (*(int *)(((unsigned char *)0x0000318c) + engineState) + *(int *)(((unsigned char *)0x00003184) + engineState));
        engineState = *(int *)(((unsigned char *)0x0000318c) + engineState) + rectTop;
        if (rectXThenRowStart < 0) {
          rectXThenRowStart = 0;
        }
        if ((int)rectTop < 0) {
          rectTop = 0;
        }
        fullWidth = *(int *)(glContext + 0x15c);
        paddedWidthA = fullWidth + 7U & 0xfffffff8;
        if ((int)paddedWidthA < (int)rectWidth) {
          rectWidth = paddedWidthA;
        }
        rectBottomClamp = fullHeight;
        if (engineState <= fullHeight) {
          rectBottomClamp = engineState;
        }
        rectWidth = rectWidth - rectXThenRowStart;
        rectHeight = rectBottomClamp - rectTop;
      }
      if (rectWidth == 0) {
        return;
      }
      if (rectHeight == 0) {
        return;
      }
      readbackPixels = _malloc((fullWidth + 7U & 0xfffffff8) * fullHeight * 4);
      glReadPixels_entry(glContext,0,0,*(int *)(glContext + 0x15c) + 7U & 0xfffffff8,
                   *(undefined4 *)(glContext + 0x160),0x80e1,0x8367,readbackPixels,2,0);
      rectBottomA = rectTop + rectHeight;
      if (value < (double)FLOAT_001aa0d4) {
        *(undefined1 *)(glContext + 0x140) = 1;
      }
      paddedRowPixels = *(int *)(glContext + 0x15c) + 7U & 0xfffffff8;
      rectXThenRowStart = rectXThenRowStart + paddedRowPixels * ((*(int *)(glContext + 0x160) - rectTop) + -1);
      if (*(char *)(glContext + 0x141) == '\x01') {
        if (value == (double)FLOAT_001aa0e8) {
          if (rectTop < rectBottomA) {
            rowCounterLoad = 0;
            do {
              readbackWordCursor = (uint *)((int)readbackPixels + rectXThenRowStart * 4);
              accumUByteCursor = (byte *)(rectXThenRowStart * 4 + *(int *)(glContext + 0x148));
              accumUByteEnd = accumUByteCursor + rectWidth * 4;
              for (; accumUByteCursor < accumUByteEnd; accumUByteCursor = accumUByteCursor + 4) {
                pixelWord = *readbackWordCursor;
                readbackWordCursor = readbackWordCursor + 1;
                *accumUByteCursor = (byte)(pixelWord >> 0x11) & 0x7f;
                accumUByteCursor[3] = (byte)(pixelWord >> 0x19);
                accumUByteCursor[1] = (byte)(pixelWord >> 9) & 0x7f;
                accumUByteCursor[2] = (byte)(pixelWord >> 1) & 0x7f;
              }
              rowCounterLoad = rowCounterLoad + 1;
              rectXThenRowStart = rectXThenRowStart - paddedRowPixels;
            } while (rectBottomA - rectTop != rowCounterLoad);
          }
        }
        else {
          loadFixedValueA8S32 = (short)(int)(value * (double)FLOAT_001aa0d8);
          fixedValue = (int)loadFixedValueA8S32;
          if (rectTop < rectBottomA) {
            rowCounter = 0;
            do {
              readbackWordCursor = (uint *)((int)readbackPixels + rectXThenRowStart * 4);
              accumRawByteCursor = (undefined1 *)(rectXThenRowStart * 4 + *(int *)(glContext + 0x148));
              accumRawByteEnd = accumRawByteCursor + rectWidth * 4;
              for (; accumRawByteCursor < accumRawByteEnd; accumRawByteCursor = accumRawByteCursor + 4) {
                pixelWord = *readbackWordCursor;
                readbackWordCursor = readbackWordCursor + 1;
                *accumRawByteCursor = (char)((int)(fixedValue * (pixelWord >> 9 & 0x7f80 | pixelWord >> 0x11 & 0x7f)) >>
                                 0x17);
                accumRawByteCursor[3] = (char)((int)(fixedValue * (pixelWord >> 0x11 & 0x7f80 | pixelWord >> 0x19)) >>
                                   0x17);
                accumRawByteCursor[1] = (char)((int)(fixedValue * (pixelWord >> 1 & 0x7f80 | pixelWord >> 9 & 0x7f)) >>
                                   0x17);
                accumRawByteCursor[2] = (char)((int)(fixedValue * ((pixelWord & 0xff) << 7 | pixelWord >> 1 & 0x7f)) >>
                                   0x17);
              }
              rowCounter = rowCounter + 1;
              rectXThenRowStart = rectXThenRowStart - paddedRowPixels;
            } while (rectBottomA - rectTop != rowCounter);
          }
        }
      }
      else if (value == (double)FLOAT_001aa0e8) {
        if (rectTop < rectBottomA) {
          rowCounterLoad = 0;
          do {
            readbackWordCursor = (uint *)((int)readbackPixels + rectXThenRowStart * 4);
            accumHalfCursor = (ushort *)(rectXThenRowStart * 8 + *(int *)(glContext + 0x148));
            accumHalfEnd = accumHalfCursor + rectWidth * 4;
            for (; accumHalfCursor < accumHalfEnd; accumHalfCursor = accumHalfCursor + 4) {
              pixelWord = *readbackWordCursor;
              readbackWordCursor = readbackWordCursor + 1;
              pixelShr16 = (ushort)(pixelWord >> 0x10);
              pixelShr17 = pixelShr16 >> 1;
              pixelShr9 = (ushort)(pixelWord >> 9);
              pixelShr1 = (ushort)(pixelWord >> 1);
              accumHalfCursor[3] = pixelShr17 & 0x7f80 | pixelShr16 >> 9;
              *accumHalfCursor = pixelShr9 & 0x7f80 | pixelShr17 & 0x7f;
              accumHalfCursor[1] = pixelShr1 & 0x7f80 | pixelShr9 & 0x7f;
              accumHalfCursor[2] = (ushort)(pixelWord << 7) & 0x7f80 | pixelShr1 & 0x7f;
            }
            rowCounterLoad = rowCounterLoad + 1;
            rectXThenRowStart = rectXThenRowStart - paddedRowPixels;
          } while (rectBottomA - rectTop != rowCounterLoad);
        }
      }
      else {
        loadFixedValueA16S32 = (short)(int)(value * (double)FLOAT_001aa0d8);
        fixedValue = (int)loadFixedValueA16S32;
        if (rectTop < rectBottomA) {
          rowCounter = 0;
          do {
            readbackWordCursor = (uint *)((int)readbackPixels + rectXThenRowStart * 4);
            accumRaw16Cursor = (undefined2 *)(rectXThenRowStart * 8 + *(int *)(glContext + 0x148));
            accumRaw16End = accumRaw16Cursor + rectWidth * 4;
            for (; accumRaw16Cursor < accumRaw16End; accumRaw16Cursor = accumRaw16Cursor + 4) {
              pixelWord = *readbackWordCursor;
              readbackWordCursor = readbackWordCursor + 1;
              *accumRaw16Cursor = (short)((int)(fixedValue * (pixelWord >> 9 & 0x7f80 | pixelWord >> 0x11 & 0x7f)) >>
                                0xf);
              accumRaw16Cursor[3] = (short)((int)(fixedValue * (pixelWord >> 0x11 & 0x7f80 | pixelWord >> 0x19)) >> 0xf
                                  );
              accumRaw16Cursor[1] = (short)((int)(fixedValue * (pixelWord >> 1 & 0x7f80 | pixelWord >> 9 & 0x7f)) >>
                                  0xf);
              accumRaw16Cursor[2] = (short)((int)(fixedValue * ((pixelWord & 0xff) << 7 | pixelWord >> 1 & 0x7f)) >>
                                  0xf);
            }
            rowCounter = rowCounter + 1;
            rectXThenRowStart = rectXThenRowStart - paddedRowPixels;
          } while (rectBottomA - rectTop != rowCounter);
        }
      }
    }
    else {
      engineState = *(int *)(glContext + 0x10);
      if (((unsigned char *)0x00003190)[engineState] == '\0') {
        fullWidth = *(int *)(glContext + 0x15c);
        fullHeight = *(int *)(glContext + 0x160);
        rectXThenRowStart = 0;
        rectTop = 0;
        rectWidth = fullWidth + 7U & 0xfffffff8;
        rectHeight = fullHeight;
      }
      else {
        rectXThenRowStart = *(int *)(((unsigned char *)0x00003180) + engineState);
        fullHeight = *(int *)(glContext + 0x160);
        rectWidth = rectXThenRowStart + *(int *)(((unsigned char *)0x00003188) + engineState);
        rectTop = fullHeight - (*(int *)(((unsigned char *)0x0000318c) + engineState) + *(int *)(((unsigned char *)0x00003184) + engineState));
        engineState = *(int *)(((unsigned char *)0x0000318c) + engineState) + rectTop;
        if (rectXThenRowStart < 0) {
          rectXThenRowStart = 0;
        }
        if ((int)rectTop < 0) {
          rectTop = 0;
        }
        fullWidth = *(int *)(glContext + 0x15c);
        paddedWidthA = fullWidth + 7U & 0xfffffff8;
        if ((int)paddedWidthA < (int)rectWidth) {
          rectWidth = paddedWidthA;
        }
        rectBottomClamp = fullHeight;
        if (engineState <= fullHeight) {
          rectBottomClamp = engineState;
        }
        rectWidth = rectWidth - rectXThenRowStart;
        rectHeight = rectBottomClamp - rectTop;
      }
      if (rectWidth == 0) {
        return;
      }
      if (rectHeight == 0) {
        return;
      }
      readbackPixels = _malloc((fullWidth + 7U & 0xfffffff8) * fullHeight * 2);
      glReadPixels_entry(glContext,0,0,*(int *)(glContext + 0x15c) + 7U & 0xfffffff8,
                   *(undefined4 *)(glContext + 0x160),0x80e1,0x8366,readbackPixels,2,0);
      rectBottomA = rectTop + rectHeight;
      if (value < (double)FLOAT_001aa0d4) {
        *(undefined1 *)(glContext + 0x140) = 1;
      }
      paddedRowPixels = *(int *)(glContext + 0x15c) + 7U & 0xfffffff8;
      rectXThenRowStart = rectXThenRowStart + paddedRowPixels * ((*(int *)(glContext + 0x160) - rectTop) + -1);
      if (*(char *)(glContext + 0x141) == '\x01') {
        if (value == (double)FLOAT_001aa0e8) {
          if (rectTop < rectBottomA) {
            rowCounterLoad = 0;
            do {
              readbackHalfCursor = (ushort *)((int)readbackPixels + rectXThenRowStart * 2);
              accumUByteCursor = (byte *)(rectXThenRowStart * 4 + *(int *)(glContext + 0x148));
              accumUByteEnd = accumUByteCursor + rectWidth * 4;
              for (; accumUByteCursor < accumUByteEnd; accumUByteCursor = accumUByteCursor + 4) {
                texel16 = *readbackHalfCursor;
                readbackHalfCursor = readbackHalfCursor + 1;
                texelShr8 = (byte)(texel16 >> 8);
                texelShr3 = (byte)(texel16 >> 3);
                accumUByteCursor[2] = ((byte)texel16 & 0x1f) << 2 | texelShr3 & 3;
                accumUByteCursor[3] = (char)texelShr8 >> 7 & 0x7f;
                *accumUByteCursor = texelShr8 & 0x7c | texelShr8 >> 5 & 3;
                accumUByteCursor[1] = texelShr3 & 0x7c | texelShr8 & 3;
              }
              rowCounterLoad = rowCounterLoad + 1;
              rectXThenRowStart = rectXThenRowStart - paddedRowPixels;
            } while (rectBottomA - rectTop != rowCounterLoad);
          }
        }
        else {
          loadFixedValueA8S16 = (short)(int)(value * (double)FLOAT_001aa0d8);
          fixedValue = (int)loadFixedValueA8S16;
          if (rectTop < rectBottomA) {
            rowCounter = 0;
            do {
              readbackHalfCursor = (ushort *)((int)readbackPixels + rectXThenRowStart * 2);
              accumRawByteCursor = (undefined1 *)(rectXThenRowStart * 4 + *(int *)(glContext + 0x148));
              accumRawByteEnd = accumRawByteCursor + rectWidth * 4;
              for (; accumRawByteCursor < accumRawByteEnd; accumRawByteCursor = accumRawByteCursor + 4) {
                texel16 = *readbackHalfCursor;
                readbackHalfCursor = readbackHalfCursor + 1;
                texelShl5 = (uint)texel16 << 5;
                accumRawByteCursor[1] = (char)((int)(fixedValue * (texelShl5 & 0x7c00 | texel16 & 0x3e0 |
                                                   texel16 >> 5 & 0x1f)) >> 0x17);
                accumRawByteCursor[3] = (char)((int)(fixedValue * (-(uint)(texel16 >> 0xf) & 0x7fff)) >> 0x17);
                *accumRawByteCursor = (char)((int)(fixedValue * (texel16 & 0x7c00 | texel16 >> 5 & 0x3e0 |
                                                 texel16 >> 10 & 0x1f)) >> 0x17);
                accumRawByteCursor[2] = (char)((int)(fixedValue * ((texel16 & 0x1f) << 10 | texelShl5 & 0x3e0 |
                                                   texel16 & 0x1f)) >> 0x17);
              }
              rowCounter = rowCounter + 1;
              rectXThenRowStart = rectXThenRowStart - paddedRowPixels;
            } while (rectBottomA - rectTop != rowCounter);
          }
        }
      }
      else if (value == (double)FLOAT_001aa0e8) {
        if (rectTop < rectBottomA) {
          rowCounterLoad = 0;
          do {
            readbackHalfCursor = (ushort *)((int)readbackPixels + rectXThenRowStart * 2);
            accumHalfCursorSrc16 = (ushort *)(rectXThenRowStart * 8 + *(int *)(glContext + 0x148));
            accumHalfEndSrc16 = accumHalfCursorSrc16 + rectWidth * 4;
            for (; accumHalfCursorSrc16 < accumHalfEndSrc16; accumHalfCursorSrc16 = accumHalfCursorSrc16 + 4) {
              texel16 = *readbackHalfCursor;
              readbackHalfCursor = readbackHalfCursor + 1;
              accumHalfCursorSrc16[1] = texel16 << 5 & 0x7c00 | texel16 & 0x3e0 | texel16 >> 5 & 0x1f;
              accumHalfCursorSrc16[2] = (texel16 & 0x1f) << 10 | texel16 << 5 & 0x3e0 | texel16 & 0x1f;
              *accumHalfCursorSrc16 = texel16 & 0x7c00 | texel16 >> 5 & 0x3e0 | texel16 >> 10 & 0x1f;
              accumHalfCursorSrc16[3] = (short)texel16 >> 0xf & 0x7fff;
            }
            rowCounterLoad = rowCounterLoad + 1;
            rectXThenRowStart = rectXThenRowStart - paddedRowPixels;
          } while (rectBottomA - rectTop != rowCounterLoad);
        }
      }
      else {
        loadFixedValueA16S16 = (short)(int)(value * (double)FLOAT_001aa0d8);
        fixedValue = (int)loadFixedValueA16S16;
        if (rectTop < rectBottomA) {
          rowCounter = 0;
          do {
            readbackHalfCursor = (ushort *)((int)readbackPixels + rectXThenRowStart * 2);
            accumRaw16Cursor = (undefined2 *)(rectXThenRowStart * 8 + *(int *)(glContext + 0x148));
            accumRaw16End = accumRaw16Cursor + rectWidth * 4;
            for (; accumRaw16Cursor < accumRaw16End; accumRaw16Cursor = accumRaw16Cursor + 4) {
              texel16 = *readbackHalfCursor;
              readbackHalfCursor = readbackHalfCursor + 1;
              texelShl5 = (uint)texel16 << 5;
              accumRaw16Cursor[1] = (short)((int)(fixedValue * (texelShl5 & 0x7c00 | texel16 & 0x3e0 |
                                                  texel16 >> 5 & 0x1f)) >> 0xf);
              accumRaw16Cursor[3] = (short)((int)(fixedValue * (-(uint)(texel16 >> 0xf) & 0x7fff)) >> 0xf);
              *accumRaw16Cursor = (short)((int)(fixedValue * (texel16 & 0x7c00 | texel16 >> 5 & 0x3e0 |
                                                texel16 >> 10 & 0x1f)) >> 0xf);
              accumRaw16Cursor[2] = (short)((int)(fixedValue * ((texel16 & 0x1f) << 10 | texelShl5 & 0x3e0 |
                                                  texel16 & 0x1f)) >> 0xf);
            }
            rowCounter = rowCounter + 1;
            rectXThenRowStart = rectXThenRowStart - paddedRowPixels;
          } while (rectBottomA - rectTop != rowCounter);
        }
      }
    }
code_r0x00003264:
                    
                    
    (*(code *)PTR_FUN_001e8754)(readbackPixels);
    return;
  case 0x102:
    if ((*(uint *)(glContext + 0x154) & 3) == 0) {
      engineState = *(int *)(glContext + 0x10);
      if (*(int *)(((unsigned char *)0x00002e40U) + engineState) != 0) {
        if (((unsigned char *)0x00003190)[engineState] == '\0') {
          fullWidth = *(int *)(glContext + 0x15c);
          fullHeight = *(int *)(glContext + 0x160);
          rectXThenRowStart = 0;
          rectTop = 0;
          rectWidth = fullWidth + 7U & 0xfffffff8;
          rectHeight = fullHeight;
        }
        else {
          rectXThenRowStart = *(int *)(((unsigned char *)0x00003180) + engineState);
          fullHeight = *(int *)(glContext + 0x160);
          rectWidth = rectXThenRowStart + *(int *)(((unsigned char *)0x00003188) + engineState);
          rectTop = fullHeight - (*(int *)(((unsigned char *)0x0000318c) + engineState) + *(int *)(((unsigned char *)0x00003184) + engineState));
          engineState = *(int *)(((unsigned char *)0x0000318c) + engineState) + rectTop;
          if (rectXThenRowStart < 0) {
            rectXThenRowStart = 0;
          }
          if ((int)rectTop < 0) {
            rectTop = 0;
          }
          fullWidth = *(int *)(glContext + 0x15c);
          paddedWidthA = fullWidth + 7U & 0xfffffff8;
          if ((int)paddedWidthA < (int)rectWidth) {
            rectWidth = paddedWidthA;
          }
          rectBottomClamp = fullHeight;
          if (engineState <= fullHeight) {
            rectBottomClamp = engineState;
          }
          rectWidth = rectWidth - rectXThenRowStart;
          rectHeight = rectBottomClamp - rectTop;
        }
        if ((rectWidth != 0) && (rectHeight != 0)) {
          readbackPixels = _malloc((fullWidth + 7U & 0xfffffff8) * fullHeight * 4);
          fullHeight = *(int *)(glContext + 0x160);
          rectBottomRet = rectTop + rectHeight;
          fullWidth = *(int *)(glContext + 0x15c);
          paddedWidthA = fullWidth + 7U & 0xfffffff8;
          hasNegativeValues = *(char *)(glContext + 0x140);
          rowStartPixelRetB = rectXThenRowStart + paddedWidthA * ((fullHeight - rectTop) + -1);
          if (*(char *)(glContext + 0x141) == '\x01') {
            if (value == (double)FLOAT_001aa0e8) {
              if (rectTop < rectBottomRet) {
                accumBufferC = *(int *)(glContext + 0x148);
                rowCounterD = 0;
                do {
                  accumUByteCursor = (byte *)(rowStartPixelRetB * 4 + accumBufferC);
                  readbackWordCursor = (uint *)((int)readbackPixels + rowStartPixelRetB * 4);
                  accumUByteEnd = accumUByteCursor + rectWidth * 4;
                  if (hasNegativeValues == '\0') {
                    for (; accumUByteCursor < accumUByteEnd; accumUByteCursor = accumUByteCursor + 4) {
                      *readbackWordCursor = (uint)accumUByteCursor[3] << 0x19 | (*accumUByteCursor & 0x7f) << 0x11 |
                                 (accumUByteCursor[1] & 0x7f) << 9 | (accumUByteCursor[2] & 0x7f) << 1;
                      readbackWordCursor = readbackWordCursor + 1;
                    }
                  }
                  else {
                    for (; accumUByteCursor < accumUByteEnd; accumUByteCursor = accumUByteCursor + 4) {
                      redClamped8to32 = 0;
                      if (-1 < (char)*accumUByteCursor) {
                        redClamped8to32 = (int)(char)*accumUByteCursor;
                      }
                      greenClamped8to32 = 0;
                      if (-1 < (char)accumUByteCursor[1]) {
                        greenClamped8to32 = (int)(char)accumUByteCursor[1];
                      }
                      blueClamped8to32 = 0;
                      if (-1 < (char)accumUByteCursor[2]) {
                        blueClamped8to32 = (int)(char)accumUByteCursor[2];
                      }
                      alphaClamped8to32 = 0;
                      if (-1 < (char)accumUByteCursor[3]) {
                        alphaClamped8to32 = (int)(char)accumUByteCursor[3];
                      }
                      *readbackWordCursor = alphaClamped8to32 << 0x19 | (redClamped8to32 & 0x7f) << 0x11 | (greenClamped8to32 & 0x7f) << 9 |
                                 (blueClamped8to32 & 0x7f) << 1;
                      readbackWordCursor = readbackWordCursor + 1;
                    }
                  }
                  rowCounterD = rowCounterD + 1;
                  rowStartPixelRetB = rowStartPixelRetB - paddedWidthA;
                } while (rowCounterD != rectBottomRet - rectTop);
              }
            }
            else {
              valueScale = (float)(value * (double)FLOAT_001aa0dc);
              if (rectTop < rectBottomRet) {
                accumBufferD = *(int *)(glContext + 0x148);
                rowCounterC = 0;
                do {
                  intBiasD = DOUBLE_001aa1e0;
                  accumByteCursorRet = (char *)(rowStartPixelRetB * 4 + accumBufferD);
                  readbackWordCursor = (uint *)((int)readbackPixels + rowStartPixelRetB * 4);
                  accumByteEndRet = accumByteCursorRet + rectWidth * 4;
                  if (accumByteCursorRet < accumByteEndRet) {
                    clampMinD = (double)FLOAT_001aa0d4;
                    channelMax255D = (double)FLOAT_001aa0f0;
                    do {
                      scaledSampleD = (double)(valueScale * (float)((double)CONCAT44(0x43300000,
                                                                         (int)*accumByteCursorRet ^ 0x80000000)
                                                       - intBiasD));
                      redOut = FLOAT_001aa0d4;
                      if (clampMinD <= scaledSampleD) {
                        redOut = (float)(scaledSampleD * channelMax255D);
                      }
                      greenOut = (double)FLOAT_001aa0d4;
                      scaledSampleD = (double)(valueScale * (float)((double)CONCAT44(0x43300000,
                                                                         (int)accumByteCursorRet[1] ^
                                                                         0x80000000) - intBiasD));
                      if (greenOut <= scaledSampleD) {
                        greenOut = (double)(float)(scaledSampleD * channelMax255D);
                      }
                      blueOut = (double)FLOAT_001aa0d4;
                      scaledSampleD = (double)(valueScale * (float)((double)CONCAT44(0x43300000,
                                                                         (int)accumByteCursorRet[2] ^
                                                                         0x80000000) - intBiasD));
                      if (blueOut <= scaledSampleD) {
                        blueOut = (double)(float)(scaledSampleD * channelMax255D);
                      }
                      alphaOut = (double)FLOAT_001aa0d4;
                      scaledSampleD = (double)(valueScale * (float)((double)CONCAT44(0x43300000,
                                                                         (int)accumByteCursorRet[3] ^
                                                                         0x80000000) - intBiasD));
                      if (alphaOut <= scaledSampleD) {
                        alphaOut = (double)(float)(scaledSampleD * channelMax255D);
                      }
                      if (DOUBLE_001aa1e8 <= alphaOut) {
                        alphaByte = (int)(alphaOut - DOUBLE_001aa1e8) + -0x80000000;
                      }
                      else {
                        alphaByte = (int)alphaOut;
                      }
                      if (DOUBLE_001aa1e8 <= (double)redOut) {
                        redByte = (int)((double)redOut - DOUBLE_001aa1e8) + -0x80000000;
                      }
                      else {
                        redByte = (int)redOut;
                      }
                      if (DOUBLE_001aa1e8 <= greenOut) {
                        greenByte = (int)(greenOut - DOUBLE_001aa1e8) + -0x80000000;
                      }
                      else {
                        greenByte = (int)greenOut;
                      }
                      if (DOUBLE_001aa1e8 <= blueOut) {
                        blueByte = (int)(blueOut - DOUBLE_001aa1e8) + 0x80000000;
                      }
                      else {
                        blueByte = (uint)(int)blueOut;
                      }
                      accumByteCursorRet = accumByteCursorRet + 4;
                      *readbackWordCursor = alphaByte << 0x18 | redByte << 0x10 | greenByte << 8 | blueByte;
                      readbackWordCursor = readbackWordCursor + 1;
                    } while (accumByteCursorRet < accumByteEndRet);
                  }
                  rowCounterC = rowCounterC + 1;
                  rowStartPixelRetB = rowStartPixelRetB - paddedWidthA;
                } while (rowCounterC != rectBottomRet - rectTop);
              }
            }
          }
          else if (value == (double)FLOAT_001aa0e8) {
            if (rectTop < rectBottomRet) {
              accumBufferC = *(int *)(glContext + 0x148);
              rowCounterD = 0;
              do {
                accumShortCursor = (short *)(rowStartPixelRetB * 8 + accumBufferC);
                readbackWordCursor = (uint *)((int)readbackPixels + rowStartPixelRetB * 4);
                accumShortEnd = accumShortCursor + rectWidth * 4;
                if (hasNegativeValues == '\0') {
                  for (; accumShortCursor < accumShortEnd; accumShortCursor = accumShortCursor + 4) {
                    *readbackWordCursor = ((int)accumShortCursor[3] & 0x7f80U) << 0x11 | ((int)*accumShortCursor & 0x7f80U) << 9
                               | ((int)accumShortCursor[1] & 0x7f80U) << 1 |
                               (uint)(int)accumShortCursor[2] >> 7 & 0xff;
                    readbackWordCursor = readbackWordCursor + 1;
                  }
                }
                else {
                  for (; accumShortCursor < accumShortEnd; accumShortCursor = accumShortCursor + 4) {
                    redClamped16to32 = 0;
                    if (-1 < *accumShortCursor) {
                      redClamped16to32 = (int)*accumShortCursor;
                    }
                    greenClamped16to32 = 0;
                    if (-1 < accumShortCursor[1]) {
                      greenClamped16to32 = (int)accumShortCursor[1];
                    }
                    blueClamped16to32 = 0;
                    if (-1 < accumShortCursor[2]) {
                      blueClamped16to32 = (int)accumShortCursor[2] >> 7;
                    }
                    alphaClamped16to32 = 0;
                    if (-1 < accumShortCursor[3]) {
                      alphaClamped16to32 = (int)accumShortCursor[3];
                    }
                    *readbackWordCursor = (alphaClamped16to32 & 0x7f80) << 0x11 | (redClamped16to32 & 0x7f80) << 9 |
                               (greenClamped16to32 & 0x7f80) << 1 | blueClamped16to32 & 0xff;
                    readbackWordCursor = readbackWordCursor + 1;
                  }
                }
                rowCounterD = rowCounterD + 1;
                rowStartPixelRetB = rowStartPixelRetB - paddedWidthA;
              } while (rowCounterD != rectBottomRet - rectTop);
            }
          }
          else {
            valueScale = (float)(value * (double)FLOAT_001aa0e4);
            if (rectTop < rectBottomRet) {
              accumBufferD = *(int *)(glContext + 0x148);
              rowCounterC = 0;
              do {
                intBiasD = DOUBLE_001aa1e0;
                accumShortCursorRet = (short *)(rowStartPixelRetB * 8 + accumBufferD);
                readbackWordCursor = (uint *)((int)readbackPixels + rowStartPixelRetB * 4);
                accumShortEndRet = accumShortCursorRet + rectWidth * 4;
                if (accumShortCursorRet < accumShortEndRet) {
                  clampMinD = (double)FLOAT_001aa0d4;
                  channelMax255D = (double)FLOAT_001aa0f0;
                  do {
                    scaledSampleD = (double)(valueScale * (float)((double)CONCAT44(0x43300000,
                                                                       (int)*accumShortCursorRet ^ 0x80000000) -
                                                     intBiasD));
                    redOut = FLOAT_001aa0d4;
                    if (clampMinD <= scaledSampleD) {
                      redOut = (float)(scaledSampleD * channelMax255D);
                    }
                    greenOut = (double)FLOAT_001aa0d4;
                    scaledSampleD = (double)(valueScale * (float)((double)CONCAT44(0x43300000,
                                                                       (int)accumShortCursorRet[1] ^ 0x80000000)
                                                     - intBiasD));
                    if (greenOut <= scaledSampleD) {
                      greenOut = (double)(float)(scaledSampleD * channelMax255D);
                    }
                    blueOut = (double)FLOAT_001aa0d4;
                    scaledSampleD = (double)(valueScale * (float)((double)CONCAT44(0x43300000,
                                                                       (int)accumShortCursorRet[2] ^ 0x80000000)
                                                     - intBiasD));
                    if (blueOut <= scaledSampleD) {
                      blueOut = (double)(float)(scaledSampleD * channelMax255D);
                    }
                    alphaOut = (double)FLOAT_001aa0d4;
                    scaledSampleD = (double)(valueScale * (float)((double)CONCAT44(0x43300000,
                                                                       (int)accumShortCursorRet[3] ^ 0x80000000)
                                                     - intBiasD));
                    if (alphaOut <= scaledSampleD) {
                      alphaOut = (double)(float)(scaledSampleD * channelMax255D);
                    }
                    if (DOUBLE_001aa1e8 <= alphaOut) {
                      alphaByte = (int)(alphaOut - DOUBLE_001aa1e8) + -0x80000000;
                    }
                    else {
                      alphaByte = (int)alphaOut;
                    }
                    if (DOUBLE_001aa1e8 <= (double)redOut) {
                      redByte = (int)((double)redOut - DOUBLE_001aa1e8) + -0x80000000;
                    }
                    else {
                      redByte = (int)redOut;
                    }
                    if (DOUBLE_001aa1e8 <= greenOut) {
                      greenByte = (int)(greenOut - DOUBLE_001aa1e8) + -0x80000000;
                    }
                    else {
                      greenByte = (int)greenOut;
                    }
                    if (DOUBLE_001aa1e8 <= blueOut) {
                      blueByte = (int)(blueOut - DOUBLE_001aa1e8) + 0x80000000;
                    }
                    else {
                      blueByte = (uint)(int)blueOut;
                    }
                    accumShortCursorRet = accumShortCursorRet + 4;
                    *readbackWordCursor = alphaByte << 0x18 | redByte << 0x10 | greenByte << 8 | blueByte;
                    readbackWordCursor = readbackWordCursor + 1;
                  } while (accumShortCursorRet < accumShortEndRet);
                }
                rowCounterC = rowCounterC + 1;
                rowStartPixelRetB = rowStartPixelRetB - paddedWidthA;
              } while (rowCounterC != rectBottomRet - rectTop);
            }
          }
          gld_drawPixelsAtRasterPos(glContext,rectXThenRowStart,rectTop,rectWidth,rectHeight,0x8367,
                       (void *)((int)readbackPixels +
                               (((fullHeight - rectTop) - rectHeight) * (fullWidth + 7U & 0xfffffff8) + rectXThenRowStart)
                               * 4));
          goto code_r0x00003264;
        }
      }
    }
    else {
      engineState = *(int *)(glContext + 0x10);
      if (*(int *)(((unsigned char *)0x00002e40U) + engineState) != 0) {
        if (((unsigned char *)0x00003190)[engineState] == '\0') {
          fullWidth = *(int *)(glContext + 0x15c);
          fullHeight = *(int *)(glContext + 0x160);
          rectXB = 0;
          rectTopB = 0;
          rectWidth = fullWidth + 7U & 0xfffffff8;
          rectHeight = fullHeight;
        }
        else {
          rectXB = *(uint *)(((unsigned char *)0x00003180) + engineState);
          fullHeight = *(int *)(glContext + 0x160);
          rectWidth = rectXB + *(int *)(((unsigned char *)0x00003188) + engineState);
          rectTopB = fullHeight - (*(int *)(((unsigned char *)0x0000318c) + engineState) + *(int *)(((unsigned char *)0x00003184) + engineState));
          engineState = *(int *)(((unsigned char *)0x0000318c) + engineState) + rectTopB;
          if ((int)rectXB < 0) {
            rectXB = 0;
          }
          if ((int)rectTopB < 0) {
            rectTopB = 0;
          }
          fullWidth = *(int *)(glContext + 0x15c);
          paddedRowPixels = fullWidth + 7U & 0xfffffff8;
          if ((int)paddedRowPixels < (int)rectWidth) {
            rectWidth = paddedRowPixels;
          }
          rectBottomClampB = fullHeight;
          if (engineState <= fullHeight) {
            rectBottomClampB = engineState;
          }
          rectWidth = rectWidth - rectXB;
          rectHeight = rectBottomClampB - rectTopB;
        }
        if ((rectWidth != 0) && (rectHeight != 0)) {
          readbackPixels = _malloc((fullWidth + 7U & 0xfffffff8) * fullHeight * 2);
          alphaScale = FLOAT_001aa0e0;
          fullHeight = *(int *)(glContext + 0x160);
          rectRight = rectXB + rectWidth;
          fullWidth = *(int *)(glContext + 0x15c);
          hasNegativeValues = *(char *)(glContext + 0x140);
          paddedRowPixels = fullWidth + 7U & 0xfffffff8;
          rectBottomRet2 = rectTopB + rectHeight;
          rowStartPixelRet = rectXB + paddedRowPixels * ((fullHeight - rectTopB) + -1);
          if (*(char *)(glContext + 0x141) == '\x01') {
            if (value == (double)FLOAT_001aa0e8) {
              if (rectTopB < rectBottomRet2) {
                accumBufferB = *(int *)(glContext + 0x148);
                rowCounterC = 0;
                do {
                  accumUByteCursor = (byte *)(rowStartPixelRet * 4 + accumBufferB);
                  readbackHalfCursor = (ushort *)((int)readbackPixels + rowStartPixelRet * 2);
                  accumUByteEnd = accumUByteCursor + rectWidth * 4;
                  if (hasNegativeValues == '\0') {
                    for (; accumUByteCursor < accumUByteEnd; accumUByteCursor = accumUByteCursor + 4) {
                      *readbackHalfCursor = ((short)(char)accumUByteCursor[3] & 0x40U) << 9 | (*accumUByteCursor & 0x7c) << 8 |
                                 (accumUByteCursor[1] & 0x7c) << 3 | accumUByteCursor[2] >> 2 & 0x1f;
                      readbackHalfCursor = readbackHalfCursor + 1;
                    }
                  }
                  else {
                    for (; accumUByteCursor < accumUByteEnd; accumUByteCursor = accumUByteCursor + 4) {
                      redClamped8to16 = 0;
                      if (-1 < (char)*accumUByteCursor) {
                        redClamped8to16 = (int)(char)*accumUByteCursor;
                      }
                      greenClamped8to16 = 0;
                      if (-1 < (char)accumUByteCursor[1]) {
                        greenClamped8to16 = (int)(char)accumUByteCursor[1];
                      }
                      blueClamped8to16 = 0;
                      if (-1 < (char)accumUByteCursor[2]) {
                        blueClamped8to16 = (ushort)((int)(char)accumUByteCursor[2] >> 2);
                      }
                      alphaClamped8to16 = 0;
                      if (-1 < (char)accumUByteCursor[3]) {
                        alphaClamped8to16 = (int)(char)accumUByteCursor[3];
                      }
                      *readbackHalfCursor = (ushort)(alphaClamped8to16 << 9) & 0x8000 | (ushort)(redClamped8to16 << 8) & 0x7c00 |
                                 (ushort)(greenClamped8to16 << 3) & 0x3e0 | blueClamped8to16 & 0x1f;
                      readbackHalfCursor = readbackHalfCursor + 1;
                    }
                  }
                  rowCounterC = rowCounterC + 1;
                  rowStartPixelRet = rowStartPixelRet - paddedRowPixels;
                } while (rectBottomRet2 - rectTopB != rowCounterC);
              }
            }
            else {
              valueScaleB = (float)(value * (double)FLOAT_001aa0dc);
              if (rectTopB < rectBottomRet2) {
                accumBufferB = *(int *)(glContext + 0x148);
                rowCounterC = 0;
                do {
                  intBiasD = DOUBLE_001aa1e0;
                  channelMax31 = FLOAT_001aa0ec;
                  zeroF = FLOAT_001aa0d4;
                  accumByteCursor = (char *)(rowStartPixelRet * 4 + accumBufferB);
                  readbackHalfCursor = (ushort *)((int)readbackPixels + rowStartPixelRet * 2);
                  rectWidthPixels = rectRight - rectXB;
                  if (rectXB < rectRight) {
                    do {
                      scaledSample = valueScaleB * (float)((double)CONCAT44(0x43300000,(int)*accumByteCursor ^ 0x80000000
                                                              ) - intBiasD);
                      red5Out = FLOAT_001aa0d4;
                      if (zeroF <= scaledSample) {
                        red5Out = scaledSample * channelMax31;
                      }
                      scaledSample = valueScaleB * (float)((double)CONCAT44(0x43300000,
                                                               (int)accumByteCursor[1] ^ 0x80000000) -
                                             intBiasD);
                      green5Out = FLOAT_001aa0d4;
                      if (FLOAT_001aa0d4 <= scaledSample) {
                        green5Out = scaledSample * channelMax31;
                      }
                      scaledSample = valueScaleB * (float)((double)CONCAT44(0x43300000,
                                                               (int)accumByteCursor[2] ^ 0x80000000) -
                                             intBiasD);
                      blue5Out = FLOAT_001aa0d4;
                      if (FLOAT_001aa0d4 <= scaledSample) {
                        blue5Out = scaledSample * channelMax31;
                      }
                      scaledSample = valueScaleB * (float)((double)CONCAT44(0x43300000,
                                                               (int)accumByteCursor[3] ^ 0x80000000) -
                                             intBiasD);
                      alpha1Out = FLOAT_001aa0d4;
                      if (FLOAT_001aa0d4 <= scaledSample) {
                        alpha1Out = scaledSample * alphaScale;
                      }
                      accumByteCursor = accumByteCursor + 4;
                      *readbackHalfCursor = (ushort)(int)blue5Out |
                                 (ushort)((int)alpha1Out << 0xf) | (ushort)((int)red5Out << 10) |
                                 (ushort)((int)green5Out << 5);
                      readbackHalfCursor = readbackHalfCursor + 1;
                      rectWidthPixels = rectWidthPixels + -1;
                    } while (rectWidthPixels != 0);
                  }
                  rowCounterC = rowCounterC + 1;
                  rowStartPixelRet = rowStartPixelRet - paddedRowPixels;
                } while (rectBottomRet2 - rectTopB != rowCounterC);
              }
            }
          }
          else if (value == (double)FLOAT_001aa0e8) {
            if (rectTopB < rectBottomRet2) {
              accumBufferB = *(int *)(glContext + 0x148);
              rowCounterC = 0;
              do {
                accumHalfCursor = (ushort *)(rowStartPixelRet * 8 + accumBufferB);
                readbackHalfDestCursor = (ushort *)((int)readbackPixels + rowStartPixelRet * 2);
                accumHalfEndRet = accumHalfCursor + rectWidth * 4;
                if (hasNegativeValues == '\0') {
                  for (; accumHalfCursor < accumHalfEndRet; accumHalfCursor = accumHalfCursor + 4) {
                    *readbackHalfDestCursor = (accumHalfCursor[3] & 0x4000) << 1 | *accumHalfCursor & 0x7c00 |
                               (ushort)((uint)(int)(short)accumHalfCursor[1] >> 5) & 0x3e0 |
                               (ushort)((uint)(int)(short)accumHalfCursor[2] >> 10) & 0x1f;
                    readbackHalfDestCursor = readbackHalfDestCursor + 1;
                  }
                }
                else {
                  for (; accumHalfCursor < accumHalfEndRet; accumHalfCursor = accumHalfCursor + 4) {
                    redClamped16to16 = 0;
                    if (-1 < (short)*accumHalfCursor) {
                      redClamped16to16 = *accumHalfCursor & 0x7c00;
                    }
                    greenClamped16to16 = 0;
                    if (-1 < (short)accumHalfCursor[1]) {
                      greenClamped16to16 = (short)accumHalfCursor[1] >> 5;
                    }
                    blueClamped16to16 = 0;
                    if (-1 < (short)accumHalfCursor[2]) {
                      blueClamped16to16 = (short)accumHalfCursor[2] >> 10;
                    }
                    alphaClamped16to16 = 0;
                    if (-1 < (short)accumHalfCursor[3]) {
                      alphaClamped16to16 = (int)(short)accumHalfCursor[3];
                    }
                    *readbackHalfDestCursor = redClamped16to16 | (ushort)(alphaClamped16to16 << 1) & 0x8000 | greenClamped16to16 & 0x3e0 |
                               blueClamped16to16 & 0x1f;
                    readbackHalfDestCursor = readbackHalfDestCursor + 1;
                  }
                }
                rowCounterC = rowCounterC + 1;
                rowStartPixelRet = rowStartPixelRet - paddedRowPixels;
              } while (rectBottomRet2 - rectTopB != rowCounterC);
            }
          }
          else {
            valueScaleB = (float)(value * (double)FLOAT_001aa0e4);
            if (rectTopB < rectBottomRet2) {
              accumBufferB = *(int *)(glContext + 0x148);
              rowCounterC = 0;
              do {
                intBiasD = DOUBLE_001aa1e0;
                channelMax31 = FLOAT_001aa0ec;
                zeroF = FLOAT_001aa0d4;
                accumShortCursor = (short *)(rowStartPixelRet * 8 + accumBufferB);
                readbackHalfCursor = (ushort *)((int)readbackPixels + rowStartPixelRet * 2);
                rectWidthPixels = rectRight - rectXB;
                if (rectXB < rectRight) {
                  do {
                    scaledSample = valueScaleB * (float)((double)CONCAT44(0x43300000,(int)*accumShortCursor ^ 0x80000000)
                                           - intBiasD);
                    red5Out = FLOAT_001aa0d4;
                    if (zeroF <= scaledSample) {
                      red5Out = scaledSample * channelMax31;
                    }
                    scaledSample = valueScaleB * (float)((double)CONCAT44(0x43300000,(int)accumShortCursor[1] ^ 0x80000000
                                                            ) - intBiasD);
                    green5Out = FLOAT_001aa0d4;
                    if (FLOAT_001aa0d4 <= scaledSample) {
                      green5Out = scaledSample * channelMax31;
                    }
                    scaledSample = valueScaleB * (float)((double)CONCAT44(0x43300000,(int)accumShortCursor[2] ^ 0x80000000
                                                            ) - intBiasD);
                    blue5Out = FLOAT_001aa0d4;
                    if (FLOAT_001aa0d4 <= scaledSample) {
                      blue5Out = scaledSample * channelMax31;
                    }
                    scaledSample = valueScaleB * (float)((double)CONCAT44(0x43300000,(int)accumShortCursor[3] ^ 0x80000000
                                                            ) - intBiasD);
                    alpha1Out = FLOAT_001aa0d4;
                    if (FLOAT_001aa0d4 <= scaledSample) {
                      alpha1Out = scaledSample * alphaScale;
                    }
                    accumShortCursor = accumShortCursor + 4;
                    *readbackHalfCursor = (ushort)(int)blue5Out |
                               (ushort)((int)alpha1Out << 0xf) | (ushort)((int)red5Out << 10) |
                               (ushort)((int)green5Out << 5);
                    readbackHalfCursor = readbackHalfCursor + 1;
                    rectWidthPixels = rectWidthPixels + -1;
                  } while (rectWidthPixels != 0);
                }
                rowCounterC = rowCounterC + 1;
                rowStartPixelRet = rowStartPixelRet - paddedRowPixels;
              } while (rectBottomRet2 - rectTopB != rowCounterC);
            }
          }
          gld_drawPixelsAtRasterPos(glContext,rectXB,rectTopB,rectWidth,rectHeight,0x8366,
                       (void *)((int)readbackPixels +
                               (((fullHeight - rectTopB) - rectHeight) * (fullWidth + 7U & 0xfffffff8) + rectXB)
                               * 2));
          goto code_r0x00003264;
        }
      }
    }
    break;
  case 0x103:
    engineStateB = *(int *)(glContext + 0x10);
    if (((unsigned char *)0x00003190)[engineStateB] == '\0') {
      fullWidthB = *(int *)(glContext + 0x15c);
      rectHeightThenBottom = *(int *)(glContext + 0x160);
      rectXThenRowStartB = 0;
      rectTopMul = 0;
      rectWidth = fullWidthB + 7U & 0xfffffff8;
      fullHeightB = rectHeightThenBottom;
    }
    else {
      rectXThenRowStartB = *(int *)(((unsigned char *)0x00003180) + engineStateB);
      fullHeightB = *(int *)(glContext + 0x160);
      rectWidth = rectXThenRowStartB + *(int *)(((unsigned char *)0x00003188) + engineStateB);
      rectTopMul = fullHeightB - (*(int *)(((unsigned char *)0x0000318c) + engineStateB) + *(int *)(((unsigned char *)0x00003184) + engineStateB));
      rectBottomRaw = *(int *)(((unsigned char *)0x0000318c) + engineStateB) + rectTopMul;
      if (rectXThenRowStartB < 0) {
        rectXThenRowStartB = 0;
      }
      if (rectTopMul < 0) {
        rectTopMul = 0;
      }
      fullWidthB = *(int *)(glContext + 0x15c);
      paddedWidthB = fullWidthB + 7U & 0xfffffff8;
      if ((int)paddedWidthB < (int)rectWidth) {
        rectWidth = paddedWidthB;
      }
      rectHeightThenBottom = fullHeightB;
      if (rectBottomRaw <= fullHeightB) {
        rectHeightThenBottom = rectBottomRaw;
      }
      rectWidth = rectWidth - rectXThenRowStartB;
      rectHeightThenBottom = rectHeightThenBottom - rectTopMul;
    }
    if ((int)rectWidth < 1) {
      return;
    }
    if (rectHeightThenBottom < 1) {
      return;
    }
    rowBytes = rectWidth * 4;
    rectHeightThenBottom = rectTopMul + rectHeightThenBottom;
    zeroD = (double)FLOAT_001aa0d4;
    if (value < zeroD) {
      *(undefined1 *)(glContext + 0x140) = 1;
    }
    paddedWidthB = fullWidthB + 7U & 0xfffffff8;
    rectXThenRowStartB = rectXThenRowStartB + paddedWidthB * ((fullHeightB - rectTopMul) + -1);
    if (value != zeroD) {
      reciprocalValue = (float)((double)FLOAT_001aa0e8 / value);
      if ((((reciprocalValue == FLOAT_001aa0f8) || (reciprocalValue == FLOAT_001aa0fc)) || (reciprocalValue == FLOAT_001aa100)) ||
         ((reciprocalValue == FLOAT_001aa104 || (reciprocalValue == FLOAT_001aa108)))) {
        divisor = (int)((double)FLOAT_001aa0e8 / value);
        shiftCount = 2;
        if (divisor != 4) {
          if (divisor < 5) {
            shiftCount = 1;
            if (divisor == 2) goto code_r0x00004f90;
          }
          else {
            shiftCount = 3;
            if ((divisor == 8) || (shiftCount = 4, divisor == 0x10)) goto code_r0x00004f90;
          }
          shiftCount = 5;
        }
code_r0x00004f90:
        if (*(char *)(glContext + 0x141) == '\x01') {
          if (rectHeightThenBottom <= rectTopMul) {
            return;
          }
          rowCounterB = 0;
          while( true ) {
            accumByteCursor = (char *)(rectXThenRowStartB * 4 + accumBuffer);
            accumByteEnd = accumByteCursor + rowBytes;
            for (; accumByteCursor < accumByteEnd; accumByteCursor = accumByteCursor + 4) {
              *accumByteCursor = (char)((int)*accumByteCursor >> shiftCount);
              accumByteCursor[1] = (char)((int)accumByteCursor[1] >> shiftCount);
              accumByteCursor[2] = (char)((int)accumByteCursor[2] >> shiftCount);
              accumByteCursor[3] = (char)((int)accumByteCursor[3] >> shiftCount);
            }
            rowCounterB = rowCounterB + 1;
            rectXThenRowStartB = rectXThenRowStartB - paddedWidthB;
            if (rowCounterB == rectHeightThenBottom - rectTopMul) break;
            accumBuffer = *(int *)(glContext + 0x148);
          }
          return;
        }
        if (rectHeightThenBottom <= rectTopMul) {
          return;
        }
        rowCounterB = 0;
        while( true ) {
          accumShortCursor = (short *)(rectXThenRowStartB * 8 + accumBuffer);
          accumShortEnd = accumShortCursor + rectWidth * 4;
          for (; accumShortCursor < accumShortEnd; accumShortCursor = accumShortCursor + 4) {
            *accumShortCursor = (short)((int)*accumShortCursor >> shiftCount);
            accumShortCursor[1] = (short)((int)accumShortCursor[1] >> shiftCount);
            accumShortCursor[2] = (short)((int)accumShortCursor[2] >> shiftCount);
            accumShortCursor[3] = (short)((int)accumShortCursor[3] >> shiftCount);
          }
          rowCounterB = rowCounterB + 1;
          rectXThenRowStartB = rectXThenRowStartB - paddedWidthB;
          if (rowCounterB == rectHeightThenBottom - rectTopMul) break;
          accumBuffer = *(int *)(glContext + 0x148);
        }
        return;
      }
    }
    if ((((value != (double)FLOAT_001aa0f8) && (value != (double)FLOAT_001aa0fc)) &&
        (value != (double)FLOAT_001aa100)) &&
       ((value != (double)FLOAT_001aa104 && (value != (double)FLOAT_001aa108)))) {
      if (*(char *)(glContext + 0x141) == '\x01') {
        if (rectHeightThenBottom <= rectTopMul) {
          return;
        }
        rowCounterB = 0;
        while( true ) {
          intBiasD = DOUBLE_001aa1e0;
          accumByteCursor = (char *)(rectXThenRowStartB * 4 + accumBuffer);
          accumByteEnd = accumByteCursor + rowBytes;
          for (; accumByteCursor < accumByteEnd; accumByteCursor = accumByteCursor + 4) {
            *accumByteCursor = (char)(int)(value *
                                  (double)(float)((double)CONCAT44(0x43300000,
                                                                   (int)*accumByteCursor ^ 0x80000000) -
                                                 intBiasD));
            accumByteCursor[1] = (char)(int)(value *
                                    (double)(float)((double)CONCAT44(0x43300000,
                                                                     (int)accumByteCursor[1] ^ 0x80000000) -
                                                   intBiasD));
            accumByteCursor[2] = (char)(int)(value *
                                    (double)(float)((double)CONCAT44(0x43300000,
                                                                     (int)accumByteCursor[2] ^ 0x80000000) -
                                                   intBiasD));
            accumByteCursor[3] = (char)(int)(value *
                                    (double)(float)((double)CONCAT44(0x43300000,
                                                                     (int)accumByteCursor[3] ^ 0x80000000) -
                                                   intBiasD));
          }
          rowCounterB = rowCounterB + 1;
          rectXThenRowStartB = rectXThenRowStartB - paddedWidthB;
          if (rowCounterB == rectHeightThenBottom - rectTopMul) break;
          accumBuffer = *(int *)(glContext + 0x148);
        }
        return;
      }
      if (rectHeightThenBottom <= rectTopMul) {
        return;
      }
      rowCounterB = 0;
      while( true ) {
        intBiasD = DOUBLE_001aa1e0;
        accumShortCursor = (short *)(rectXThenRowStartB * 8 + accumBuffer);
        accumShortEnd = accumShortCursor + rectWidth * 4;
        for (; accumShortCursor < accumShortEnd; accumShortCursor = accumShortCursor + 4) {
          *accumShortCursor = (short)(int)(value *
                                 (double)(float)((double)CONCAT44(0x43300000,
                                                                  (int)*accumShortCursor ^ 0x80000000) -
                                                intBiasD));
          accumShortCursor[1] = (short)(int)(value *
                                   (double)(float)((double)CONCAT44(0x43300000,
                                                                    (int)accumShortCursor[1] ^ 0x80000000) -
                                                  intBiasD));
          accumShortCursor[2] = (short)(int)(value *
                                   (double)(float)((double)CONCAT44(0x43300000,
                                                                    (int)accumShortCursor[2] ^ 0x80000000) -
                                                  intBiasD));
          accumShortCursor[3] = (short)(int)(value *
                                   (double)(float)((double)CONCAT44(0x43300000,
                                                                    (int)accumShortCursor[3] ^ 0x80000000) -
                                                  intBiasD));
        }
        rowCounterB = rowCounterB + 1;
        rectXThenRowStartB = rectXThenRowStartB - paddedWidthB;
        if (rowCounterB == rectHeightThenBottom - rectTopMul) break;
        accumBuffer = *(int *)(glContext + 0x148);
      }
      return;
    }
    multiplierInt = (int)value;
    shiftCount = 2;
    if (multiplierInt != 4) {
      if (multiplierInt < 5) {
        shiftCount = 1;
        if (multiplierInt != 2) {
code_r0x0000510c:
          shiftCount = 5;
        }
      }
      else {
        shiftCount = 3;
        if ((multiplierInt != 8) && (shiftCount = 4, multiplierInt != 0x10)) goto code_r0x0000510c;
      }
    }
    if (*(char *)(glContext + 0x141) == '\x01') {
      if (rectTopMul < rectHeightThenBottom) {
        rowCounterB = 0;
        while( true ) {
          accumByteCursor = (char *)(rectXThenRowStartB * 4 + accumBuffer);
          accumByteEnd = accumByteCursor + rowBytes;
          for (; accumByteCursor < accumByteEnd; accumByteCursor = accumByteCursor + 4) {
            *accumByteCursor = *accumByteCursor << shiftCount;
            accumByteCursor[1] = accumByteCursor[1] << shiftCount;
            accumByteCursor[2] = accumByteCursor[2] << shiftCount;
            accumByteCursor[3] = accumByteCursor[3] << shiftCount;
          }
          rowCounterB = rowCounterB + 1;
          rectXThenRowStartB = rectXThenRowStartB - paddedWidthB;
          if (rowCounterB == rectHeightThenBottom - rectTopMul) break;
          accumBuffer = *(int *)(glContext + 0x148);
        }
      }
    }
    else if (rectTopMul < rectHeightThenBottom) {
      rowCounterB = 0;
      while( true ) {
        accumShortCursor = (short *)(rectXThenRowStartB * 8 + accumBuffer);
        accumShortEnd = accumShortCursor + rectWidth * 4;
        for (; accumShortCursor < accumShortEnd; accumShortCursor = accumShortCursor + 4) {
          *accumShortCursor = (short)((int)*accumShortCursor << shiftCount);
          accumShortCursor[1] = (short)((int)accumShortCursor[1] << shiftCount);
          accumShortCursor[2] = (short)((int)accumShortCursor[2] << shiftCount);
          accumShortCursor[3] = (short)((int)accumShortCursor[3] << shiftCount);
        }
        rowCounterB = rowCounterB + 1;
        rectXThenRowStartB = rectXThenRowStartB - paddedWidthB;
        if (rowCounterB == rectHeightThenBottom - rectTopMul) break;
        accumBuffer = *(int *)(glContext + 0x148);
      }
    }
    break;
  case 0x104:
    engineStateB = *(int *)(glContext + 0x10);
    if (((unsigned char *)0x00003190)[engineStateB] == '\0') {
      fullWidthB = *(int *)(glContext + 0x15c);
      rectHeightThenBottom = *(int *)(glContext + 0x160);
      rectXThenRowStartB = 0;
      rectTopAdd = 0;
      rectWidth = fullWidthB + 7U & 0xfffffff8;
      fullHeightB = rectHeightThenBottom;
    }
    else {
      rectXThenRowStartB = *(int *)(((unsigned char *)0x00003180) + engineStateB);
      fullHeightB = *(int *)(glContext + 0x160);
      rectWidth = rectXThenRowStartB + *(int *)(((unsigned char *)0x00003188) + engineStateB);
      rectTopAdd = fullHeightB - (*(int *)(((unsigned char *)0x0000318c) + engineStateB) + *(int *)(((unsigned char *)0x00003184) + engineStateB));
      rectBottomRaw = *(int *)(((unsigned char *)0x0000318c) + engineStateB) + rectTopAdd;
      if (rectXThenRowStartB < 0) {
        rectXThenRowStartB = 0;
      }
      if (rectTopAdd < 0) {
        rectTopAdd = 0;
      }
      fullWidthB = *(int *)(glContext + 0x15c);
      paddedWidthB = fullWidthB + 7U & 0xfffffff8;
      if ((int)paddedWidthB < (int)rectWidth) {
        rectWidth = paddedWidthB;
      }
      rectHeightThenBottom = fullHeightB;
      if (rectBottomRaw <= fullHeightB) {
        rectHeightThenBottom = rectBottomRaw;
      }
      rectWidth = rectWidth - rectXThenRowStartB;
      rectHeightThenBottom = rectHeightThenBottom - rectTopAdd;
    }
    if ((0 < (int)rectWidth) && (0 < rectHeightThenBottom)) {
      rectHeightThenBottom = rectTopAdd + rectHeightThenBottom;
      if (value < (double)FLOAT_001aa0d4) {
        *(undefined1 *)(glContext + 0x140) = 1;
      }
      paddedWidthB = fullWidthB + 7U & 0xfffffff8;
      rectXThenRowStartB = rectXThenRowStartB + paddedWidthB * ((fullHeightB - rectTopAdd) + -1);
      if (*(char *)(glContext + 0x141) == '\x01') {
        valueByte = (char)(int)(value * (double)FLOAT_001aa0f4);
        if (rectTopAdd < rectHeightThenBottom) {
          rowCounterB = 0;
          while( true ) {
            accumByteCursor = (char *)(rectXThenRowStartB * 4 + accumBuffer);
            accumByteEnd = accumByteCursor + rectWidth * 4;
            for (; accumByteCursor < accumByteEnd; accumByteCursor = accumByteCursor + 4) {
              *accumByteCursor = valueByte + *accumByteCursor;
              accumByteCursor[1] = valueByte + accumByteCursor[1];
              accumByteCursor[2] = valueByte + accumByteCursor[2];
              accumByteCursor[3] = valueByte + accumByteCursor[3];
            }
            rowCounterB = rowCounterB + 1;
            rectXThenRowStartB = rectXThenRowStartB - paddedWidthB;
            if (rowCounterB == rectHeightThenBottom - rectTopAdd) break;
            accumBuffer = *(int *)(glContext + 0x148);
          }
        }
      }
      else {
        addFixedValueA8 = (short)(int)(value * (double)FLOAT_001aa0d8);
        if (rectTopAdd < rectHeightThenBottom) {
          rowCounterB = 0;
          while( true ) {
            accumShortCursor = (short *)(rectXThenRowStartB * 8 + accumBuffer);
            accumShortEnd = accumShortCursor + rectWidth * 4;
            for (; accumShortCursor < accumShortEnd; accumShortCursor = accumShortCursor + 4) {
              *accumShortCursor = addFixedValueA8 + *accumShortCursor;
              accumShortCursor[1] = addFixedValueA8 + accumShortCursor[1];
              accumShortCursor[2] = addFixedValueA8 + accumShortCursor[2];
              accumShortCursor[3] = addFixedValueA8 + accumShortCursor[3];
            }
            rowCounterB = rowCounterB + 1;
            rectXThenRowStartB = rectXThenRowStartB - paddedWidthB;
            if (rowCounterB == rectHeightThenBottom - rectTopAdd) break;
            accumBuffer = *(int *)(glContext + 0x148);
          }
        }
      }
    }
  }
  return;
}

/* _gldSetInteger @ 0x5630 (1116 bytes) */
int _gldSetInteger(ctx, pname, values)
  int ctx;
  uint pname;
  uint *values;
{
  uint textureTarget;
  int statusOrObject;
  undefined4 connectionOrError;
  undefined4 selector;
  bool enable;
  uint scalarIn0;
  uint scalarIn1;
  uint scalarIn2;
  uint scalarIn3;
  
  if (values == (uint *)0x0) {
    return 0x271e;
  }
  statusOrObject = FUN_00017100(ctx,pname,values);
  if (statusOrObject != 0) {
    return 0;
  }
  if (pname == 0x124) {
    scalarIn0 = *values;
    statusOrObject = _io_connect_method_scalarI_structureI(*(undefined4 *)(ctx + GLD_connect),0xc,&scalarIn0,1,0,0);
    connectionOrError = 0x2719;
joined_r0x000058fc:
    if (statusOrObject != 0) {
      return connectionOrError;
    }
  }
  else {
    if (pname < 0x125) {
      if (pname == 0xcb) {
        scalarIn0 = (uint)*(byte *)(ctx + GLD_swapIntervalNumerator);
        scalarIn1 = *values;
        *(char *)(ctx + GLD_swapIntervalDenominator) = (char)scalarIn1;
        _io_connect_method_scalarI_structureI(*(undefined4 *)(ctx + GLD_connect),2,&scalarIn0,2,0,0);
        return 0;
      }
      if (pname < 0xcc) {
        if (pname == 200) {
          if ((-1 < (int)values[2]) && (-1 < (int)values[3])) {
            scalarIn0 = *values;
            *(uint *)(ctx + GLD_swapRectX) = scalarIn0;
            scalarIn1 = values[1];
            *(uint *)(ctx + GLD_swapRectY) = scalarIn1;
            scalarIn2 = values[2];
            *(uint *)(ctx + GLD_swapRectWidth) = scalarIn2;
            scalarIn3 = values[3];
            *(uint *)(ctx + GLD_swapRectHeight) = scalarIn3;
            if (*(char *)(ctx + GLD_swapRectEnabled) == '\0') {
              return 0;
            }
            _io_connect_method_scalarI_structureI(*(undefined4 *)(ctx + GLD_connect),1,&scalarIn0,4,0,0);
            return 0;
          }
          return 0x2718;
        }
        if (pname == 0xc9) {
          enable = *values != 0;
          if (enable == (bool)*(char *)(ctx + GLD_swapRectEnabled)) {
            return 0;
          }
          *(bool *)(ctx + GLD_swapRectEnabled) = enable;
          if (enable) {
            scalarIn0 = *(uint *)(ctx + GLD_swapRectX);
            scalarIn1 = *(undefined4 *)(ctx + GLD_swapRectY);
            scalarIn2 = *(undefined4 *)(ctx + GLD_swapRectWidth);
            scalarIn3 = *(undefined4 *)(ctx + GLD_swapRectHeight);
          }
          else {
            scalarIn0 = 0;
            scalarIn1 = 0;
            scalarIn2 = 0;
            scalarIn3 = 0;
          }
          _io_connect_method_scalarI_structureI(*(undefined4 *)(ctx + GLD_connect),1,&scalarIn0,4,0,0);
          return 0;
        }
      }
      else {
        if (pname == 0xde) {
          scalarIn0 = *values;
          scalarIn1 = (uint)*(byte *)(ctx + GLD_swapIntervalDenominator);
          *(char *)(ctx + GLD_swapIntervalNumerator) = (char)scalarIn0;
          _io_connect_method_scalarI_structureI(*(undefined4 *)(ctx + GLD_connect),2,&scalarIn0,2,0,0);
          return 0;
        }
        if (pname == 0xec) {
          return 0;
        }
      }
LAB_00005690:
      connectionOrError = gld_setIntegerEngineParam(ctx,pname,values);
      return connectionOrError;
    }
    if (pname == 0x29a) {
      *(char *)(ctx + 0x21) = '\x01' - (*values == 0);
      return 0;
    }
    if (pname < 0x29b) {
      if (pname == 0x12a) {
        *(undefined1 *)(ctx + GLD_scaleEnabled) = 1;
        *(uint *)(ctx + GLD_scaleFlags) = *values;
        *(uint *)(ctx + GLD_scaleX) = values[1];
        *(uint *)(ctx + GLD_scaleY) = values[2];
        return 0;
      }
      if (pname != 0x132) goto LAB_00005690;
      connectionOrError = *(undefined4 *)(ctx + GLD_connect);
      selector = 0x10;
      scalarIn0 = (uint)(*values != 0);
      *(bool *)(ctx + GLD_surfaceVolatile) = *values != 0;
    }
    else {
      if (pname == 0x29d) {
        statusOrObject = *(int *)(*(int *)(ctx + GLD_engineObjects) + 0x194);
        if (statusOrObject == 0) {
          return 0;
        }
        scalarIn0 = *(uint *)(statusOrObject + 0x228);
      }
      else {
        if (pname == 0x1f96) {
          scalarIn0 = *values;
          scalarIn1 = values[1];
          if (scalarIn0 == 0) {
            *(uint *)(ctx + GLD_drawableFlags) = *(uint *)(ctx + GLD_drawableFlags) & 0xffffffef;
            *(undefined1 *)(*(int *)(ctx + GLD_capsBlock) + 0x26) = 0;
          }
          else {
            *(uint *)(ctx + GLD_drawableFlags) = *(uint *)(ctx + GLD_drawableFlags) | 0x10;
            *(undefined1 *)(*(int *)(ctx + GLD_capsBlock) + 0x26) = 1;
          }
          statusOrObject = _io_connect_method_scalarI_structureI
                            (*(undefined4 *)(ctx + GLD_connect),0x13,&scalarIn0,2,0,0);
          connectionOrError = 0x2712;
          goto joined_r0x000058fc;
        }
        if (pname != 0x29c) goto LAB_00005690;
        textureTarget = values[1];
        if (0xf < *values) {
          return 0x2718;
        }
        if (textureTarget == 0x806f) {
          statusOrObject = 1;
        }
        else if (textureTarget < 0x8070) {
          if (textureTarget == 0xde0) {
            statusOrObject = 4;
          }
          else {
            if (textureTarget != 0xde1) {
              return 0x271a;
            }
            statusOrObject = 3;
          }
        }
        else if (textureTarget == 0x84f5) {
          statusOrObject = 2;
        }
        else {
          if (textureTarget != 0x8513) {
            return 0x271a;
          }
          statusOrObject = 0;
        }
        statusOrObject = *(int *)(*(int *)(ctx + GLD_engineObjects) + (*values * 5 + statusOrObject) * 4);
        if (statusOrObject == 0) {
          return 0;
        }
        scalarIn0 = *(uint *)(statusOrObject + 0x34);
      }
      if (scalarIn0 == 0) {
        return 0;
      }
      connectionOrError = *(undefined4 *)(ctx + GLD_connect);
      selector = 0xf;
    }
    _io_connect_method_scalarI_structureI(connectionOrError,selector,&scalarIn0,1,0,0);
  }
  return 0;
}

/* _gldGetInteger @ 0x5aa0 (616 bytes) */
int _gldGetInteger(ctx, pname, values, extraArg3, extraArg4, extraArg5)
  int ctx;
  uint pname;
  uint *values;
  undefined4 extraArg3;
  undefined4 extraArg4;
  undefined4 extraArg5;
{
  int status;
  undefined4 returnCode;
  uint texture;
  undefined4 outCount;
  uint scalarOut0;
  uint scalarOut1;
  uint scalarOut2;
  
  if (values == (uint *)0x0) {
    return 0x271e;
  }
  if (pname == 0xde) {
    *values = (uint)*(byte *)(ctx + GLD_swapIntervalNumerator);
    return 0;
  }
  if (pname < 0xdf) {
    if (pname == 0xc9) {
      *values = (uint)*(byte *)(ctx + GLD_swapRectEnabled);
      return 0;
    }
    if (pname != 0xcb) {
      if (pname != 200) {
        return 0x271a;
      }
      *values = *(uint *)(ctx + GLD_swapRectX);
      values[1] = *(uint *)(ctx + GLD_swapRectY);
      values[2] = *(uint *)(ctx + GLD_swapRectWidth);
      values[3] = *(uint *)(ctx + GLD_swapRectHeight);
      return 0;
    }
    *values = (uint)*(byte *)(ctx + GLD_swapIntervalDenominator);
    return 0;
  }
  if (pname == 0x132) {
    *values = (uint)*(byte *)(ctx + GLD_surfaceVolatile);
    return 0;
  }
  if (pname < 0x133) {
    if (pname != 0x126) {
      return 0x271a;
    }
    texture = *values;
    if (((*(byte *)(texture + 0x39) & 7) != 0) &&
       (status = gldTextureMakeResident(ctx,texture,values,extraArg3,extraArg4,extraArg5), status == 0)) {
      *values = 0;
      return 0;
    }
    *values = *(uint *)(*(int *)(texture + 0x34) + 4);
    return 0;
  }
  if (pname == 0x29a) {
    *values = (uint)*(byte *)(ctx + 0x21);
    return 0;
  }
  if (pname != 0x3e3) {
    return 0x271a;
  }
  outCount = 3;
  status = _io_connect_method_scalarI_scalarO
                    (*(undefined4 *)(ctx + GLD_connect),6,values,1,&scalarOut0,&outCount);
  if (status == 0) {
    switch(scalarOut0 & 0xf) {
    case 3:
      *values = 0x1908;
      values[1] = 0x8366;
      break;
    case 4:
      *values = 0x1908;
      values[1] = 0x8367;
      break;
    default:
      goto switchD_00005c44_caseD_5;
    case 6:
    case 7:
    case 8:
    case 9:
      *values = 0x85b9;
      values[1] = 0x85bb;
      break;
    case 10:
      *values = 0x80e1;
      values[1] = 0x8367;
      break;
    case 0xb:
      *values = 0x1908;
      values[1] = (uint)((unsigned char *)0x00001403U);
      break;
    case 0xc:
      *values = 0x1908;
      values[1] = (uint)((unsigned char *)0x0000140bU);
      break;
    case 0xd:
      *values = 0x1908;
      values[1] = (uint)((unsigned char *)0x00001406U);
    }
    returnCode = 0;
    values[2] = scalarOut1;
    values[3] = scalarOut2;
  }
  else {
switchD_00005c44_caseD_5:
    returnCode = 0x2722;
  }
  return returnCode;
}

/* _gldCreateBuffer @ 0x5d50 (96 bytes) */
int _gldCreateBuffer(ctx, bufferOut, initialWord0, initialWord1)
  undefined4 ctx;
  int *bufferOut;
  undefined4 initialWord0;
  undefined4 initialWord1;
{
  undefined4 *buffer;
  
  buffer = (undefined4 *)_malloc(0x24);
  _memset(buffer,0,0x24);
  *bufferOut = (int)buffer;
  *buffer = initialWord0;
  buffer[1] = initialWord1;
  buffer[2] = 0;
  return 0;
}

/* gld_waitBufferStamp @ 0x5db0 (244 bytes) */
int gld_waitBufferStamp(ctx, buffer)
  int ctx;
  int buffer;
{
  int retired;
  undefined4 connection;
  int pluginRecord;
  
  if ((*(int **)(buffer + 8) != (int *)0x0) && (pluginRecord = **(int **)(buffer + 8), pluginRecord != 0)) {
    if (*(char *)(pluginRecord + 0x16) == '\x06') {
      if (0x1ffff < *(int *)(pluginRecord + 0x10)) {
        _gldFlush(ctx);
      }
      retired = gld_isStampRetired(ctx,*(undefined4 *)(pluginRecord + 8));
      if (retired == 0) {
        connection = *(undefined4 *)(ctx + GLD_connect);
        pluginRecord = pluginRecord + 8;
LAB_00005e6c:
        _io_connect_method_scalarI_structureI(connection,9,pluginRecord,1,0,0);
        return;
      }
    }
    else if (*(char *)(pluginRecord + 0x16) == '\a') {
      if (0x1ffff < *(int *)(pluginRecord + 0x10)) {
        _gldFlush(ctx);
      }
      retired = gld_isStampRetired(ctx,*(undefined4 *)(pluginRecord + 0xc));
      if (retired == 0) {
        connection = *(undefined4 *)(ctx + GLD_connect);
        pluginRecord = pluginRecord + 0xc;
        goto LAB_00005e6c;
      }
    }
  }
  return;
}

/* FUN_00005eb0 @ 0x5eb0 (184 bytes) */
int FUN_00005eb0(ctx, buffer)
  undefined4 ctx;
  int buffer;
{
  undefined4 retired;
  int pluginRecord;
  
  if ((*(int **)(buffer + 8) != (int *)0x0) && (pluginRecord = **(int **)(buffer + 8), pluginRecord != 0)) {
    if (*(char *)(pluginRecord + 0x16) == '\x06') {
      if (0x1ffff < *(int *)(pluginRecord + 0x10)) {
        _gldFlush(ctx);
      }
      retired = gld_isStampRetired(ctx,*(undefined4 *)(pluginRecord + 8));
      return retired;
    }
    if (*(char *)(pluginRecord + 0x16) == '\a') {
      if (0x1ffff < *(int *)(pluginRecord + 0x10)) {
        _gldFlush(ctx);
      }
      retired = gld_isStampRetired(ctx,*(undefined4 *)(pluginRecord + 0xc));
      return retired;
    }
  }
  return 1;
}

/* _gldFlushBuffer @ 0x5f70 (164 bytes) */
int _gldFlushBuffer(ctx, buffer, flushRegion, flushArg4, flushArg5, flushArg6, flushArg7, flushArg8)
  undefined4 ctx;
  int buffer;
  int flushRegion;
  undefined4 flushArg4;
  undefined4 flushArg5;
  undefined4 flushArg6;
  undefined4 flushArg7;
  undefined4 flushArg8;
{
  int *pluginData;
  int pluginRecord;
  
  pluginData = *(int **)(buffer + 8);
  if ((pluginData != (int *)0x0) && (*pluginData != 0)) {
    if (flushRegion != 0) {
      gldFlushDataCacheRange(ctx,flushRegion,flushArg4,flushArg4,flushArg5,flushArg6,flushArg7,flushArg8);
      pluginData = *(int **)(buffer + 8);
    }
    if (*(char *)(*pluginData + 0x16) == '\a') {
      *(undefined1 *)(*pluginData + 0x14) = 1;
      pluginRecord = **(int **)(buffer + 8);
      *(ushort *)(pluginRecord + 0x28) = *(ushort *)(pluginRecord + 0x28) & ~*(ushort *)(pluginRecord + 0x1c);
    }
    **(uint **)(buffer + 4) = **(uint **)(buffer + 4) & 0xfffffffc;
  }
  return;
}

/* _gldGetMemoryPluginData @ 0x6020 (60 bytes) */
int _gldGetMemoryPluginData(ctx, buffer, pluginDataOut)
  undefined4 ctx;
  int buffer;
  int *pluginDataOut;
{
  int *pluginData;
  int pluginRecord;
  
  pluginData = *(int **)(buffer + 8);
  if ((pluginData != (int *)0x0) && (pluginRecord = *pluginData, pluginRecord != 0)) {
    *(ushort *)(pluginRecord + 0x1c) = *(ushort *)(pluginRecord + 0x1c) | *(ushort *)(pluginRecord + 0x28);
    pluginData = *(int **)(buffer + 8);
  }
  *pluginDataOut = (int)pluginData;
  *(undefined4 *)(buffer + 8) = 0;
  return;
}

/* _gldSetMemoryPluginData @ 0x6060 (100 bytes) */
int _gldSetMemoryPluginData(ctx, buffer, pluginData)
  undefined4 ctx;
  int buffer;
  int *pluginData;
{
  int pluginRecord;
  
  *(int **)(buffer + 8) = pluginData;
  if (pluginData == (int *)0x0) {
    return;
  }
  pluginRecord = *pluginData;
  if (pluginRecord == 0) {
    return;
  }
  *(undefined1 *)(pluginRecord + 0x14) = 1;
  if (*(char *)(**(int **)(buffer + 8) + 0x16) == '\a') {
    *(ushort *)(pluginRecord + 0x28) = *(ushort *)(pluginRecord + 0x28) & ~*(ushort *)(pluginRecord + 0x1c);
  }
  **(uint **)(buffer + 4) = **(uint **)(buffer + 4) & 0xfffffffe;
  return;
}

/* _gldFinishMemoryPluginData @ 0x60d0 (212 bytes) */
int _gldFinishMemoryPluginData(ctx, pluginData)
  int ctx;
  int *pluginData;
{
  int busy;
  undefined4 connection;
  int pluginRecord;
  
  if ((pluginData == (int *)0x0) || (pluginRecord = *pluginData, pluginRecord == 0)) {
    return;
  }
  if ((0x1ffff < (int)*(uint *)(pluginRecord + 0x10)) || ((*(uint *)(pluginRecord + 0x10) & 0xffff) != 0)) {
    _gldFlush(ctx);
  }
  if (*(char *)(pluginRecord + 0x16) == '\x06') {
    busy = gld_isStampRetired(ctx,*(undefined4 *)(pluginRecord + 8));
    if (busy != 0) {
      return;
    }
    connection = *(undefined4 *)(ctx + GLD_connect);
    pluginRecord = pluginRecord + 8;
  }
  else {
    if (*(char *)(pluginRecord + 0x16) != '\a') {
      return;
    }
    busy = gld_isStampRetired(ctx,*(undefined4 *)(pluginRecord + 0xc));
    if (busy != 0) {
      return;
    }
    connection = *(undefined4 *)(ctx + GLD_connect);
    pluginRecord = pluginRecord + 0xc;
  }
  _io_connect_method_scalarI_structureI(connection,9,pluginRecord,1,0,0);
  return;
}

/* _gldTestMemoryPluginData @ 0x61b0 (156 bytes) */
int _gldTestMemoryPluginData(ctx, pluginData)
  undefined4 ctx;
  int *pluginData;
{
  undefined4 isComplete;
  int pluginRecord;
  
  if ((pluginData == (int *)0x0) || (pluginRecord = *pluginData, pluginRecord == 0)) {
LAB_00006230:
    isComplete = 1;
  }
  else {
    if (*(char *)(pluginRecord + 0x16) == '\x06') {
      if (*(int *)(pluginRecord + 0x10) < 0x20000) {
        isComplete = gld_isStampRetired(ctx,*(undefined4 *)(pluginRecord + 8));
        return isComplete;
      }
    }
    else {
      if (*(char *)(pluginRecord + 0x16) != '\a') goto LAB_00006230;
      if (*(int *)(pluginRecord + 0x10) < 0x20000) {
        isComplete = gld_isStampRetired(ctx,*(undefined4 *)(pluginRecord + 0xc));
        return isComplete;
      }
    }
    isComplete = 0;
  }
  return isComplete;
}

/* _gldDestroyMemoryPluginData @ 0x6260 (212 bytes) */
int _gldDestroyMemoryPluginData(ctx, pluginData)
  int ctx;
  int *pluginData;
{
  int updatedRefCount;
  int *refCountSlot;
  int oldRefCount;
  int pluginRecord;
  char reservation;
  byte crBits;
  
  crBits = (pluginData == (int *)0x0) << 1;
  if (pluginData != (int *)0x0) {
    pluginRecord = *pluginData;
    if (pluginRecord != 0) {
      if ((0x1ffff < (int)*(uint *)(pluginRecord + 0x10)) || ((*(uint *)(pluginRecord + 0x10) & 0xffff) != 0)) {
        _gldFlush(ctx);
      }
      ((int (*)())_gldFinishMemoryPluginData)(ctx,pluginData);
      refCountSlot = (int *)(pluginRecord + 0x10);
      do {
        oldRefCount = *refCountSlot;
        if (reservation != '\0') {
          updatedRefCount = storeWordConditionalIndexed(oldRefCount + -0x10000,0,refCountSlot);
          *refCountSlot = updatedRefCount;
          crBits = 2;
        }
      } while (!(bool)(crBits >> 1 & 1));
      if (oldRefCount == 0x10000) {
        _io_connect_method_scalarI_structureI(*(undefined4 *)(ctx + GLD_connect),0xb,pluginRecord,1,0,0);
      }
      *pluginData = 0;
    }
    _free(pluginData);
    return;
  }
  return;
}

/* _gldReclaimBuffer @ 0x6340 (236 bytes) */
int _gldReclaimBuffer(ctx, buffer)
  int ctx;
  int buffer;
{
  int updatedRefCount;
  int *pluginData;
  int oldRefCount;
  int pluginRecord;
  char reservation;
  byte crBits;
  
  pluginData = *(int **)(buffer + 8);
  if (pluginData != (int *)0x0) {
    pluginRecord = *pluginData;
    if (pluginRecord != 0) {
      if ((0x1ffff < (int)*(uint *)(pluginRecord + 0x10)) || ((*(uint *)(pluginRecord + 0x10) & 0xffff) != 0)) {
        _gldFlush(ctx);
      }
      ((int (*)())gld_waitBufferStamp)(ctx,buffer);
      pluginData = (int *)(pluginRecord + 0x10);
      do {
        oldRefCount = *pluginData;
        if (reservation != '\0') {
          updatedRefCount = storeWordConditionalIndexed(oldRefCount + -0x10000,0,pluginData);
          *pluginData = updatedRefCount;
          crBits = 2;
        }
      } while (!(bool)(crBits >> 1 & 1));
      if (oldRefCount == 0x10000) {
        _io_connect_method_scalarI_structureI(*(undefined4 *)(ctx + GLD_connect),0xb,pluginRecord,1,0,0);
      }
      **(undefined4 **)(buffer + 8) = 0;
      *(undefined4 *)(*(int *)(buffer + 8) + 4) = 0;
      pluginData = *(int **)(buffer + 8);
    }
    _free(pluginData);
    *(undefined4 *)(buffer + 8) = 0;
  }
  return;
}

/* _gldDestroyBuffer @ 0x6430 (56 bytes) */
int _gldDestroyBuffer(ctx, buffer)
  undefined4 ctx;
  undefined4 buffer;
{
  ((int (*)())_gldReclaimBuffer)(ctx,buffer);
  _free(buffer);
  return 0;
}

/* gld_setBufferAgpRefBacking @ 0x6470 (312 bytes) */
int gld_setBufferAgpRefBacking(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  char in_RESERVE;
  byte in_cr0;
  undefined4 local_38;
  undefined1 auStack_34 [4];
  int local_30;
  
  piVar2 = *(int **)(param_2 + 8);
  if (piVar2 == (int *)0x0) {
    iVar5 = 0;
    piVar2 = (int *)_malloc(8);
    *(int **)(param_2 + 8) = piVar2;
  }
  else {
    iVar5 = *piVar2;
  }
  *piVar2 = 0;
  uVar4 = 0;
  *(undefined4 *)(*(int *)(param_2 + 8) + 4) = 0;
  *(undefined4 *)(param_2 + 0x10) = 6;
  *(undefined4 *)(param_2 + 0x14) = param_3;
  *(undefined4 *)(param_2 + 0x18) = param_4;
  *(undefined4 *)(param_2 + 0x1c) = param_5;
  local_38 = 8;
  iVar3 = _io_connect_method_structureI_structureO
                    (*(undefined4 *)(param_1 + 4),10,param_2 + 0x10,0x14,auStack_34,&local_38);
  if (iVar3 == 0) {
    **(int **)(param_2 + 8) = local_30;
    piVar2 = (int *)(local_30 + 0x10);
    do {
      if (in_RESERVE != '\0') {
        iVar3 = storeWordConditionalIndexed(*piVar2 + 0x10000,0,piVar2);
        *piVar2 = iVar3;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    uVar4 = 1;
    *(undefined1 *)(local_30 + 0x14) = 1;
  }
  if (iVar5 != 0) {
    piVar2 = (int *)(iVar5 + 0x10);
    do {
      iVar3 = *piVar2;
      if (in_RESERVE != '\0') {
        iVar1 = storeWordConditionalIndexed(iVar3 + -0x10000,0,piVar2);
        *piVar2 = iVar1;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if (iVar3 == 0x10000) {
      _io_connect_method_scalarI_structureI(*(undefined4 *)(param_1 + 4),0xb,iVar5,1,0,0);
    }
  }
  return uVar4;
}

/* gld_setBufferNewTextureBacking @ 0x65b0 (328 bytes) */
int gld_setBufferNewTextureBacking(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  char in_RESERVE;
  byte in_cr0;
  undefined4 local_48;
  undefined4 local_44;
  int local_40;
  
  piVar2 = *(int **)(param_2 + 8);
  if (piVar2 == (int *)0x0) {
    iVar5 = 0;
    piVar2 = (int *)_malloc(8);
    *(int **)(param_2 + 8) = piVar2;
  }
  else {
    iVar5 = *piVar2;
  }
  *piVar2 = 0;
  uVar4 = 0;
  *(undefined4 *)(*(int *)(param_2 + 8) + 4) = 0;
  *(undefined4 *)(param_2 + 0x10) = 7;
  *(undefined4 *)(param_2 + 0x14) = param_3;
  *(undefined4 *)(param_2 + 0x18) = param_4;
  *(undefined4 *)(param_2 + 0x1c) = param_5;
  *(undefined4 *)(param_2 + 0x20) = param_6;
  local_48 = 8;
  iVar3 = _io_connect_method_structureI_structureO
                    (*(undefined4 *)(param_1 + 4),10,param_2 + 0x10,0x14,&local_44,&local_48);
  if (iVar3 == 0) {
    piVar2 = (int *)(local_40 + 0x10);
    **(int **)(param_2 + 8) = local_40;
    do {
      if (in_RESERVE != '\0') {
        iVar3 = storeWordConditionalIndexed(*piVar2 + 0x10000,0,piVar2);
        *piVar2 = iVar3;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    uVar4 = 1;
    *(undefined1 *)(local_40 + 0x14) = 1;
    *(undefined4 *)(*(int *)(param_2 + 8) + 4) = local_44;
  }
  if (iVar5 != 0) {
    piVar2 = (int *)(iVar5 + 0x10);
    do {
      iVar3 = *piVar2;
      if (in_RESERVE != '\0') {
        iVar1 = storeWordConditionalIndexed(iVar3 + -0x10000,0,piVar2);
        *piVar2 = iVar1;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if (iVar3 == 0x10000) {
      _io_connect_method_scalarI_structureI(*(undefined4 *)(param_1 + 4),0xb,iVar5,1,0,0);
    }
  }
  return uVar4;
}

/* _gldCreateContext @ 0x6700 (1696 bytes) */
int _gldCreateContext(contextOut, pixelFormat, contextArg3, shareContext, stateBlock, contextArg6, contextArg7)
  int *contextOut;
  int pixelFormat;
  uint contextArg3;
  int shareContext;
  uint stateBlock;
  uint contextArg6;
  uint contextArg7;
{
  short auxBuffers;
  undefined *libraryOrTaskPtr;
  uint scratch1;
  int status;
  uint *ctx;
  uint scratch0;
  uint scratch2;
  undefined4 task;
  uint *fenceTablePtr;
  uint *fenceTableSize;
  undefined4 mapOptions;
  int clearCount;
  uint scalarOut [6];
  
  if (contextOut == (int *)0x0) {
    return 0x271e;
  }
  *contextOut = 0;
  status = FUN_0001ac30(pixelFormat);
  libraryOrTaskPtr = PTR_DAT_001e88ac;
  if (status != 0) {
    return status;
  }
  if (((*(uint *)(pixelFormat + 0x30) & *(uint *)PTR_DAT_001e88ac) == 0) ||
     ((*(uint *)(pixelFormat + 0x30) & ~*(uint *)PTR_DAT_001e88ac) != 0)) {
    return 0x2716;
  }
  ctx = (uint *)_malloc(((unsigned char *)0x00002b98U));
  if (*(int *)(libraryOrTaskPtr + 4) != 0) {
    scalarOut[0] = 0;
    if ((*(uint *)(pixelFormat + 0x30) & 1) == 0) {
      do {
        scalarOut[0] = scalarOut[0] + 1;
        if (*(uint *)(PTR_DAT_001e88ac + 4) <= scalarOut[0]) break;
      } while ((1 << (scalarOut[0] & 0x3f) & *(uint *)(pixelFormat + 0x30)) == 0);
      goto LAB_00006798;
    }
  }
  scalarOut[0] = 0;
LAB_00006798:
  *ctx = scalarOut[0];
  libraryOrTaskPtr = PTR_DAT_001e88ac;
  ctx[GLD_connect / 4] = 0;
  status = _IOServiceOpen(*(undefined4 *)(scalarOut[0] * 4 + *(int *)(libraryOrTaskPtr + 8)),
                         *(undefined4 *)PTR_001e88b4,1,ctx + GLD_connect / 4);
  if (status == 0) {
    if ((shareContext == 0) ||
       (status = _IOConnectAddClient(ctx[GLD_connect / 4],*(undefined4 *)(shareContext + 4)), status == 0)) {
      scalarOut[0] = 3;
      status = _io_connect_method_scalarI_scalarO(ctx[GLD_connect / 4],3,0,0,ctx + GLD_hwConfig0 / 4,scalarOut);
      libraryOrTaskPtr = PTR_001e88b4;
      if (status == 0) {
        task = *(undefined4 *)PTR_001e88b4;
        ctx[GLD_retireCounter / 4] = 0;
        status = _IOConnectMapMemory(ctx[GLD_connect / 4],0,task,ctx + GLD_retireCounter / 4,scalarOut,0x101);
        if (status == 0) {
          task = *(undefined4 *)libraryOrTaskPtr;
          ctx[GLD_ringMap / 4] = 0;
          status = _IOConnectMapMemory(ctx[GLD_connect / 4],1,task,ctx + GLD_ringMap / 4,ctx + GLD_ringMapSize / 4,1);
          if (status == 0) {
            task = *(undefined4 *)libraryOrTaskPtr;
            ctx[GLD_contextBufferMap / 4] = 0;
            ctx[GLD_dataBase / 4] = 0;
            ctx[GLD_dataBufferId / 4] = 0;
            ctx[GLD_dataCursor / 4] = 0;
            ctx[GLD_dataLimit / 4] = 0;
            ctx[GLD_dataRefillCount / 4] = 0;
            status = _IOConnectMapMemory(ctx[GLD_connect / 4],2,task,ctx + GLD_contextBufferMap / 4,ctx + GLD_contextBufferMapSize / 4,1);
            if (status == 0) {
              task = *(undefined4 *)libraryOrTaskPtr;
              fenceTablePtr = ctx + GLD_statusRegion / 4;
              fenceTableSize = ctx + GLD_statusRegionSize / 4;
              mapOptions = 1;
              ctx[GLD_statusRegion / 4] = 0;
              status = _IOConnectMapMemory(ctx[GLD_connect / 4],4,task,fenceTablePtr,fenceTableSize,1);
              if (status == 0) {
                scratch0 = _malloc(ctx[GLD_statusRegionSize / 4] >> 5);
                ctx[GLD_fenceBitmap / 4] = scratch0;
                scratch2 = ctx[GLD_statusRegionSize / 4] >> 5;
                _memset(scratch0,0,scratch2);
                ctx[GLD_queryRecord / 4] = 0;
                ctx[GLD_queryPool / 4] = 0;
                ctx[GLD_queryPoolBytes / 4] = 0;
                ctx[GLD_queryBitmap / 4] = 0;
                scratch0 = *(uint *)PTR_001e88b0;
                ctx[GLD_queryCapacity / 4] = 0;
                if ((scratch0 & 8) == 0) {
                  if ((scratch0 & 0x10) == 0) {
                    *(undefined1 *)(ctx + GLD_cacheLineSize / 4) = 0x20;
                  }
                  else {
                    *(undefined1 *)(ctx + GLD_cacheLineSize / 4) = 0x80;
                  }
                }
                else {
                  *(undefined1 *)(ctx + GLD_cacheLineSize / 4) = 0x40;
                }
                scratch0 = (uint)DAT_001f65e0;
                ctx[GLD_submitEpoch / 4] = 0;
                DAT_001f65e0 = ctx + GLD_listSelf / 4;
                ctx[GLD_listSelf / 4] = (uint)ctx;
                ctx[GLD_listNext / 4] = scratch0;
                ctx[GLD_mutex / 4] = contextArg3;
                ctx[GLD_engineState / 4] = contextArg6;
                ctx[GLD_engineObjects / 4] = contextArg7;
                ctx[0xd] = 0;
                scratch0 = *(uint *)(pixelFormat + 8);
                ctx[0x45] = 0x19;
                ctx[0x46] = 0x32;
                ctx[GLD_drawableFlags / 4] = 0;
                *(undefined1 *)((int)ctx + 0x143) = 1;
                ctx[GLD_capsBlock / 4] = stateBlock;
                ctx[GLD_dispatchTable / 4] = 0;
                ctx[0xc] = 0;
                ctx[0xe] = 0;
                ctx[GLD_drawableWidth / 4] = 0;
                ctx[GLD_drawableHeight / 4] = 0;
                ctx[0x43] = 0;
                ctx[0x44] = 0;
                ctx[GLD_boundFramebuffer / 4] = 0;
                ctx[GLD_vertexChunkCount / 4] = 0;
                ctx[GLD_vertexChunkList / 4] = 0;
                ctx[GLD_lastError / 4] = 0;
                if ((scratch0 & 0x800) != 0) {
                  ctx[GLD_drawableFlags / 4] = 0x2000;
                }
                scratch1 = *(uint *)(pixelFormat + 0xc);
                if ((scratch1 & 8) == 0) {
                  if ((scratch0 & 2) == 0) {
                    ctx[GLD_drawableFlags / 4] = ctx[GLD_drawableFlags / 4] | 0x800;
                  }
                }
                else {
                  ctx[GLD_drawableFlags / 4] = ctx[GLD_drawableFlags / 4] | 0x400;
                }
                scratch1 = scratch1 & 2;
                if (scratch1 != 0) {
                  ctx[GLD_drawableFlags / 4] = ctx[GLD_drawableFlags / 4] | 0x10;
                }
                scratch0 = *(uint *)(pixelFormat + 0x10);
                if ((scratch0 & 0xfffffc) == 0) {
                  if ((scratch0 & 0x3f000000) != 0) {
                    scratch1 = scratch0 & 0x3f00000;
                    if (scratch1 == 0) {
                      if ((scratch0 & 0xc000000) != 0) {
                        ctx[GLD_drawableFlags / 4] = ctx[GLD_drawableFlags / 4] | 0xd;
                      }
                    }
                    else {
                      ctx[GLD_drawableFlags / 4] = ctx[GLD_drawableFlags / 4] | 0xc;
                    }
                  }
                }
                else {
                  scratch1 = scratch0 & 0x3fc0;
                  if (scratch1 == 0) {
                    if ((scratch0 & 0xfc000) == 0) {
                      scratch1 = scratch0 & 0x3f00000;
                      if (scratch1 != 0) {
                        ctx[GLD_drawableFlags / 4] = ctx[GLD_drawableFlags / 4] | 0xb;
                      }
                    }
                    else {
                      ctx[GLD_drawableFlags / 4] = ctx[GLD_drawableFlags / 4] | 4;
                    }
                  }
                  else {
                    ctx[GLD_drawableFlags / 4] = ctx[GLD_drawableFlags / 4] | 3;
                  }
                }
                if (*(int *)(pixelFormat + 0x18) != 1) {
                  ctx[GLD_drawableFlags / 4] = ctx[GLD_drawableFlags / 4] | 0x40;
                }
                if (*(int *)(pixelFormat + 0x1c) != 1) {
                  ctx[GLD_drawableFlags / 4] = ctx[GLD_drawableFlags / 4] | 0x80;
                }
                if (*(int *)(pixelFormat + 0x14) == 0x8000) {
                  *(undefined1 *)((int)ctx + GLD_softwareBufferFormat) = 1;
                }
                else if (*(int *)(pixelFormat + 0x14) == 0x800000) {
                  *(undefined1 *)((int)ctx + GLD_softwareBufferFormat) = 2;
                }
                else {
                  *(undefined1 *)((int)ctx + GLD_softwareBufferFormat) = 0;
                }
                auxBuffers = *(short *)(pixelFormat + 0x22);
                *(undefined1 *)(ctx + 0x50) = 0;
                ctx[GLD_softwareBuffer / 4] = 0;
                ctx[GLD_softwareBufferSize / 4] = 0;
                if (auxBuffers == 1) {
                  ctx[GLD_drawableFlags / 4] = ctx[GLD_drawableFlags / 4] | 0x100;
                }
                else if (auxBuffers == 2) {
                  ctx[GLD_drawableFlags / 4] = ctx[GLD_drawableFlags / 4] | 0x200;
                }
                if (0 < *(short *)(pixelFormat + 0x24)) {
                  ctx[GLD_drawableFlags / 4] = ctx[GLD_drawableFlags / 4] | 0x1000;
                }
                FUN_00017a40(ctx + GLD_drawableFlags / 4,pixelFormat,scratch2,fenceTablePtr,fenceTableSize,mapOptions,scratch1);
                scratch2 = ctx[GLD_drawableFlags / 4];
                ctx[0xe] = 0x4000;
                if ((scratch2 & 0x40) != 0) {
                  ctx[0xe] = (uint)((unsigned char *)0x00004100U);
                }
                if ((scratch2 & 0x80) == 0) {
                  scratch0 = ctx[0xe];
                }
                else {
                  scratch0 = ctx[0xe] | 0x400;
                  ctx[0xe] = scratch0;
                }
                if (*(char *)((int)ctx + GLD_softwareBufferFormat) != '\0') {
                  scratch0 = scratch0 | 0x200;
                  ctx[0xe] = scratch0;
                }
                *(undefined1 *)((int)ctx + GLD_swapIntervalDenominator) = 1;
                ctx[GLD_renderFlags / 4] = scratch2;
                ctx[GLD_renderBufferMask / 4] = scratch0;
                ctx[GLD_renderHeight / 4] = ctx[GLD_drawableHeight / 4];
                ctx[0x59] = ctx[0x43];
                ctx[0x5a] = ctx[0x44];
                ctx[0x5b] = ctx[0x45];
                ctx[0x5c] = ctx[0x46];
                *(undefined1 *)((int)ctx + 0x21) = 1;
                *(undefined1 *)((int)ctx + GLD_surfaceVolatile) = 0;
                ctx[GLD_attachedDrawable / 4] = 0;
                *(undefined1 *)(ctx + 8) = 0;
                ctx[GLD_swapRectX / 4] = 0;
                ctx[GLD_swapRectY / 4] = 0;
                ctx[GLD_swapRectWidth / 4] = 0;
                ctx[GLD_swapRectHeight / 4] = 0;
                *(undefined1 *)(ctx + GLD_swapRectEnabled / 4) = 0;
                *(undefined1 *)((int)ctx + GLD_swapIntervalNumerator) = 0;
                *(undefined1 *)((int)ctx + GLD_scaleEnabled) = 0;
                ctx[0x47] = 0;
                ctx[0x48] = 0;
                ctx[0x5d] = 3;
                ctx[GLD_renderWidth / 4] = ctx[GLD_drawableWidth / 4];
                clearCount = 0x10;
                status = 0;
                do {
                  ctx[status + 99] = 0;
                  clearCount = clearCount + -1;
                  status = status + 1;
                } while (clearCount != 0);
                scratch2 = 0;
                do {
                  scalarOut[0] = scratch2 + 1;
                  ctx[scratch2 + 0x73] = 0;
                  scratch2 = scalarOut[0];
                } while (scalarOut[0] < 2);
                ctx[0x62] = 0;
                ctx[0x5f] = 0;
                ctx[0x60] = 0;
                ctx[0x61] = 0;
                if ((ctx[GLD_hwConfig0 / 4] & 2) == 0) {
                  *(undefined4 *)(stateBlock + 0x94) = 3;
                }
                else {
                  *(undefined4 *)(stateBlock + 0x94) = 1;
                }
                gld_fillCapsBlock(ctx,stateBlock,pixelFormat);
                _memcpy(ctx + GLD_stateCopy / 4,stateBlock + 0x24,0x3c);
                gld_initContextHardwareState(ctx,pixelFormat);
                *contextOut = (int)ctx;
                return 0;
              }
            }
          }
        }
      }
    }
    _IOServiceClose(ctx[GLD_connect / 4]);
    _free(ctx);
  }
  else {
    _free(ctx);
  }
  return 0x271f;
}

/* _gldDestroyContext @ 0x6dd0 (216 bytes) */
int _gldDestroyContext(ctx)
  int ctx;
{
  undefined4 returnCode;
  int *listNode;
  int *prevNode;
  
  returnCode = 0x2714;
  if (ctx != 0) {
    FUN_00007020(ctx);
    gldContextFreeResources(ctx);
    _IOServiceClose(*(undefined4 *)(ctx + GLD_connect));
    if (DAT_001f65e0 != (int *)0x0) {
      listNode = DAT_001f65e0;
      if (ctx == *DAT_001f65e0) {
        DAT_001f65e0 = (int *)DAT_001f65e0[1];
      }
      else {
        do {
          prevNode = listNode;
          listNode = (int *)prevNode[1];
          if (listNode == (int *)0x0) goto LAB_00006e50;
        } while (ctx != *listNode);
        prevNode[1] = listNode[1];
      }
    }
LAB_00006e50:
    if (*(int *)(ctx + GLD_softwareBuffer) != 0) {
      _free(*(int *)(ctx + GLD_softwareBuffer));
    }
    if (*(int *)(ctx + GLD_fenceBitmap) != 0) {
      _free(*(int *)(ctx + GLD_fenceBitmap));
    }
    _free(ctx);
    returnCode = 0;
  }
  return returnCode;
}

/* _gldCreateShared @ 0x6ec0 (128 bytes) */
int _gldCreateShared(sharedOut)
  int *sharedOut;
{
  undefined4 returnCode;
  int shared;
  undefined1 mutexAttr [28];
  
  returnCode = 0x271e;
  if (sharedOut != (int *)0x0) {
    *sharedOut = 0;
    shared = _malloc(0x34);
    returnCode = 0x2720;
    if (shared != 0) {
      _pthread_mutexattr_init(mutexAttr);
      _pthread_mutexattr_settype(mutexAttr,2);
      _pthread_mutex_init(shared,mutexAttr);
      FUN_00024fb0(shared);
      *sharedOut = shared;
      returnCode = 0;
    }
  }
  return returnCode;
}


/* issue: auto-generated aliases bridging data.s/code.s references (written
 * without a leading underscore, matching the raw stock-binary symbol name)
 * against the real compiled C symbols (gcc adds one underscore automatically).
 * Needed because ld64 (required for this PPC binary's size - stock ld breaks on
 * large PPC links) does not silently reconcile this the way stock ld did. */
asm(".globl FUN_00002ae0");
asm(".set FUN_00002ae0, _glAccum_impl");
