#include "decls.h"

/* FUN_00001740 @ 0x1740 (48 bytes) */
int FUN_00001740()
{
                    
                    
  (*DAT_001e8740)();
  return;
}

/* FUN_00001770 @ 0x1770 (32 bytes) */
int FUN_00001770(param_1, param_2)
  uint param_1;
  uint param_2;
{
                    
                    
  (*DAT_001e8744)(param_1,param_2);
  return;
}

/* FUN_00001790 @ 0x1790 (40 bytes) */
int FUN_00001790(state)
  undefined4 *state;
{
  *state = 1;
  return;
}

/* FUN_000017b8 @ 0x17b8 (120 bytes) */
int FUN_000017b8(state)
  undefined4 *state;
{
  int status;
  undefined4 *stateHome;
  
  stateHome = state;
  status = (*(code *)state[1])(FUN_00001790,state,state);
  if (status != 0) {
    *state = 0xffffffff;
  }
  return;
}

/* FUN_00001830 @ 0x1830 (204 bytes) */
int FUN_00001830(cxaAtexitFn, cxaFinalizeFn)
  code *cxaAtexitFn;
  code *cxaFinalizeFn;
{
  int status;
  code *cxaAtexitFnHome;
  code *cxaFinalizeFnHome;
  /* issue #75 (follow-up): state (flag/arg, at Ghidra-derived stack offset -0x28) and
   * cxaAtexitFnCopy (the real __cxa_atexit pointer, at offset -0x24, i.e. exactly 4 bytes higher)
   * were declared as two SEPARATE C locals, but FUN_000017b8 reaches cxaAtexitFnCopy purely via raw
   * pointer arithmetic on the address of state (`cxaAtexitFn[1]`, i.e. `&state + 4`) - an
   * assumption baked in from the STOCK binary's original gcc-4.0.1 stack layout, which this
   * rebuild's gcc-7 has no reason to honor. Confirmed live: gdb showed &state = 0xbffe70cc
   * but &cxaAtexitFnCopy = 0xbffe70bc (16 bytes away, not 4) - so `cxaAtexitFn[1]` inside FUN_000017b8 was
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
  status = (*cxaAtexitFn)(FUN_000017b8,&local_2818.flag,&local_2818.flag);
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

/* FUN_000018fc @ 0x18fc (504 bytes) */
int FUN_000018fc()
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
  
  ((int (*)())FUN_00001770)((int)"__dyld_image_count",(uint)&imageCountFn);
  ((int (*)())FUN_00001770)((int)"__dyld_get_image_name",(uint)&imageNameFn);
  ((int (*)())FUN_00001770)((int)"__dyld_get_image_header",(uint)&imageHeaderFn);
  ((int (*)())FUN_00001770)((int)"__dyld_NSLookupSymbolInImage",(uint)&lookupSymbolFn);
  uVar1 = ((int (*)())FUN_00001770)((int)"__dyld_NSAddressOfSymbol",(uint)addressOfSymbolFn);
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

/* FUN_00001b34 @ 0x1b34 (528 bytes) */
int FUN_00001b34()
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
      symbolAddress = ((int (*)())FUN_000018fc)();
      *(undefined4 *)(atexit_globals + 0x10) = symbolAddress;
      if ((*(int *)(atexit_globals + 0x10) != 0) &&
         (libSystemHandle = (**(code **)(atexit_globals + 0x10))(FUN_0000228c), libSystemHandle == 0)) goto LAB_00001d08;
    }
    else {
      symbolAddress = _dlsym(libSystemHandle,"__cxa_atexit");
      *(undefined4 *)(atexit_globals + 8) = symbolAddress;
      symbolAddress = _dlsym(libSystemHandle,"__cxa_finalize");
      *(undefined4 *)(atexit_globals + 0xc) = symbolAddress;
      if (((*(int *)(atexit_globals + 8) != 0) && (*(int *)(atexit_globals + 0xc) != 0)) &&
         (checkResult = ((int (*)())FUN_00001830)(*(undefined4 *)(atexit_globals + 8),*(undefined4 *)(atexit_globals + 0xc)),
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
  iVar1 = (*param_1)(FUN_000017b8,&iStack_28,&iStack_28);
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

/* FUN_00001d84 @ 0x1d84 (32 bytes) */
int FUN_00001d84()
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
  
  ((int (*)())FUN_00001770)("__dyld_image_count",&pcStack_34);
  ((int (*)())FUN_00001770)("__dyld_get_image_name",&pcStack_30);
  ((int (*)())FUN_00001770)("__dyld_get_image_header",&pcStack_2c);
  ((int (*)())FUN_00001770)("__dyld_NSLookupSymbolInImage",&pcStack_28);
  ((int (*)())FUN_00001770)("__dyld_NSAddressOfSymbol",apcStack_24);
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

/* FUN_00001dc4 @ 0x1dc4 (32 bytes) */
int FUN_00001dc4()
{
  _dlopen();
  return;
}

/* FUN_00001de4 @ 0x1de4 (32 bytes) */
int FUN_00001de4(param_1, param_2)
  size_t param_1;
  size_t param_2;
{
  _calloc(param_1,param_2);
  return;
}

/* FUN_00001e04 @ 0x1e04 (32 bytes) */
int FUN_00001e04()
{
  __keymgr_get_and_lock_processwide_ptr();
  return;
}

/* FUN_00001e24 @ 0x1e24 (268 bytes) */
int FUN_00001e24(atexit_globals, routine)
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

/* FUN_00001f50 @ 0x1f50 (32 bytes) */
int FUN_00001f50(param_1)
  size_t param_1;
{
  _malloc(param_1);
  return;
}

/* FUN_00001f70 @ 0x1f70 (292 bytes) */
int FUN_00001f70(atexit_globals, stopNode)
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

/* FUN_000020b4 @ 0x20b4 (32 bytes) */
int FUN_000020b4(param_1)
  void *param_1;
{
  _free(param_1);
  return;
}

/* FUN_000020d4 @ 0x20d4 (32 bytes) */
int FUN_000020d4()
{
  __keymgr_set_and_unlock_processwide_ptr();
  return;
}

/* FUN_000020f4 @ 0x20f4 (312 bytes) */
int FUN_000020f4(atexit_entry)
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
    atexit_globals = ((int (*)())FUN_00001f70)(atexit_globals,savedList);
  }
  if (atexit_globals != 0) {
    *(undefined1 *)(atexit_globals + 2) = savedRunning;
    __keymgr_set_and_unlock_processwide_ptr(0xe,atexit_globals);
  }
  return;
}

/* FUN_0000222c @ 0x222c (32 bytes) */
int FUN_0000222c(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  ((int (*)())FUN_00001f70)(param_1,param_2);
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

/* FUN_0000228c @ 0x228c (188 bytes) */
int FUN_0000228c()
{
  undefined1 savedRunning;
  short *atexit_globals;
  int relocked;
  
  atexit_globals = (short *)__keymgr_get_and_lock_processwide_ptr(0xe);
  if (((atexit_globals != (short *)0x0) && (*atexit_globals == 0)) && (*(char *)((int)atexit_globals + 3) == '\x01')) {
    savedRunning = *(undefined1 *)(atexit_globals + 1);
    *(undefined1 *)(atexit_globals + 1) = 1;
    relocked = ((int (*)())FUN_00001f70)(atexit_globals,0);
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

/* FUN_000023a8 @ 0x23a8 (672 bytes) */
int FUN_000023a8(atexit_entry, dsoHandle)
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
  atexit_globals = ((int (*)())FUN_00001b34)();
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
          result = (*registerFn)(FUN_000020f4,entryCopy,dsoHandleHome,in_r6,in_r7,in_r8,entryCopy);
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
    result = ((int (*)())FUN_00001e24)(atexit_globals,entryHome);
  }
  return result;
}

/* FUN_00002648 @ 0x2648 (32 bytes) */
int FUN_00002648(param_1)
  size_t param_1;
{
  _malloc(param_1);
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
      uVar2 = ((int (*)())FUN_000018fc)();
      *(undefined4 *)((int)pvStack_20 + 0x10) = uVar2;
      if ((*(int *)((int)pvStack_20 + 0x10) != 0) &&
         (iVar1 = (**(code **)((int)pvStack_20 + 0x10))(FUN_0000228c), iVar1 == 0))
      goto LAB_00001d08;
    }
    else {
      uVar2 = _dlsym(iVar1,"__cxa_atexit");
      *(undefined4 *)((int)pvStack_20 + 8) = uVar2;
      uVar2 = _dlsym(iVar1,"__cxa_finalize");
      *(undefined4 *)((int)pvStack_20 + 0xc) = uVar2;
      if (((*(int *)((int)pvStack_20 + 8) != 0) && (*(int *)((int)pvStack_20 + 0xc) != 0)) &&
         (iVar3 = ((int (*)())FUN_00001830)(*(undefined4 *)((int)pvStack_20 + 8),
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

/* FUN_000026c8 @ 0x26c8 (96 bytes) */
int FUN_000026c8(atexit_function, argument, dsoHandle)
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
  result = ((int (*)())FUN_000023a8)(&entryFunction,dsoHandle);
  return result;
}

/* FUN_00002728 @ 0x2728 (32 bytes) */
int FUN_00002728(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
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
  iVar3 = ((int (*)())FUN_00001b34)();
  if (iVar3 == 0) {
    uStack_18 = 0xffffffff;
  }
  else if ((*(char *)(iVar3 + 2) == '\0') && (*(char *)(iVar3 + 3) != '\x01')) {
    if (*(byte *)(iVar3 + 3) < 0x10) {
      pcVar1 = *(code **)(iVar3 + 8);
      iVar3 = __keymgr_set_and_unlock_processwide_ptr(0xe,iVar3);
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
          uStack_18 = (*pcVar1)(FUN_000020f4,allocation,uStack0000001c);
        }
      }
      else {
        uStack_18 = 0xffffffff;
      }
    }
    else if (puStack00000018[1] == 0) {
      pcVar1 = *(code **)(iVar3 + 0x10);
      iVar3 = __keymgr_set_and_unlock_processwide_ptr(0xe,iVar3);
      if ((*(ushort *)(*(int *)(PTR_001e88a4 + 8) + 4) < 4) || (iVar3 == 0)) {
        uStack_18 = (*pcVar1)(*puStack00000018);
      }
      else {
        uStack_18 = 0xffffffff;
      }
    }
    else {
      pcVar1 = *(code **)(iVar3 + 8);
      iVar3 = __keymgr_set_and_unlock_processwide_ptr(0xe,iVar3);
      if ((*(ushort *)(*(int *)(PTR_001e88a4 + 8) + 4) < 4) || (iVar3 == 0)) {
        uStack_18 = (*pcVar1)(*puStack00000018,puStack00000018[2],uStack0000001c);
      }
      else {
        uStack_18 = 0xffffffff;
      }
    }
  }
  else {
    uStack_18 = ((int (*)())FUN_00001e24)(iVar3,puStack00000018);
  }
  return uStack_18;
}

/* FUN_00002748 @ 0x2748 (92 bytes) */
int FUN_00002748(atexit_function)
  undefined4 atexit_function;
{
  undefined4 result;
  undefined4 uStack00000018;
  undefined4 entryFunction;
  undefined4 entryKind;
  
  entryKind = 0;
  uStack00000018 = atexit_function;
  entryFunction = atexit_function;
  result = ((int (*)())FUN_000023a8)(&entryFunction,PTR_001e88a8);
  return result;
}

/* FUN_000027a4 @ 0x27a4 (32 bytes) */
int FUN_000027a4(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
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
  iVar3 = ((int (*)())FUN_00001b34)();
  if (iVar3 == 0) {
    uStack_18 = 0xffffffff;
  }
  else if ((*(char *)(iVar3 + 2) == '\0') && (*(char *)(iVar3 + 3) != '\x01')) {
    if (*(byte *)(iVar3 + 3) < 0x10) {
      pcVar1 = *(code **)(iVar3 + 8);
      iVar3 = __keymgr_set_and_unlock_processwide_ptr(0xe,iVar3);
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
          uStack_18 = (*pcVar1)(FUN_000020f4,allocation,uStack0000001c);
        }
      }
      else {
        uStack_18 = 0xffffffff;
      }
    }
    else if (puStack00000018[1] == 0) {
      pcVar1 = *(code **)(iVar3 + 0x10);
      iVar3 = __keymgr_set_and_unlock_processwide_ptr(0xe,iVar3);
      if ((*(ushort *)(*(int *)(PTR_001e88a4 + 8) + 4) < 4) || (iVar3 == 0)) {
        uStack_18 = (*pcVar1)(*puStack00000018);
      }
      else {
        uStack_18 = 0xffffffff;
      }
    }
    else {
      pcVar1 = *(code **)(iVar3 + 8);
      iVar3 = __keymgr_set_and_unlock_processwide_ptr(0xe,iVar3);
      if ((*(ushort *)(*(int *)(PTR_001e88a4 + 8) + 4) < 4) || (iVar3 == 0)) {
        uStack_18 = (*pcVar1)(*puStack00000018,puStack00000018[2],uStack0000001c);
      }
      else {
        uStack_18 = 0xffffffff;
      }
    }
  }
  else {
    uStack_18 = ((int (*)())FUN_00001e24)(iVar3,puStack00000018);
  }
  return uStack_18;
}

/* FUN_000027d0 @ 0x27d0 (776 bytes) */
int FUN_000027d0(param_1, param_2)
  int param_1;
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
  int iVar11;
  uint uVar12;
  int iVar13;
  int iVar14;
  int iVar15;
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
    iVar15 = *(int *)(param_1 + 0x15c);
    iVar11 = *(int *)(param_1 + 0x160);
    iVar14 = 0;
    iVar5 = 0;
    *(undefined1 *)(param_1 + 0x140) = uVar4;
    uVar12 = iVar15 + 7U & 0xfffffff8;
    iVar13 = iVar11;
  }
  else {
    iVar11 = *(int *)(param_1 + 0x160);
    *(undefined1 *)(param_1 + 0x140) = 1;
    iVar14 = *(int *)(((unsigned char *)0x00003180) + param_2);
    uVar12 = iVar14 + *(int *)(((unsigned char *)0x00003188) + param_2);
    iVar5 = iVar11 - (*(int *)(((unsigned char *)0x0000318c) + param_2) + *(int *)(((unsigned char *)0x00003184) + param_2));
    iVar13 = *(int *)(((unsigned char *)0x0000318c) + param_2) + iVar5;
    if (iVar14 < 0) {
      iVar14 = 0;
    }
    if (iVar5 < 0) {
      iVar5 = 0;
    }
    iVar15 = *(int *)(param_1 + 0x15c);
    uVar1 = iVar15 + 7U & 0xfffffff8;
    if ((int)uVar1 < (int)uVar12) {
      uVar12 = uVar1;
    }
    iVar10 = iVar11;
    if (iVar13 <= iVar11) {
      iVar10 = iVar13;
    }
    uVar12 = uVar12 - iVar14;
    iVar13 = iVar10 - iVar5;
  }
  if ((0 < (int)uVar12) && (0 < iVar13)) {
    uVar1 = iVar15 + 7U & 0xfffffff8;
    iVar14 = iVar14 + uVar1 * (iVar11 - (iVar5 + iVar13));
    if (*(char *)(param_1 + 0x141) == '\x01') {
      puVar6 = (undefined4 *)(iVar14 * 4 + *(int *)(param_1 + 0x148));
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
    else if (*(char *)(param_1 + 0x141) == '\x02') {
      puVar8 = (undefined8 *)(iVar14 * 8 + *(int *)(param_1 + 0x148));
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

/* FUN_00002ae0 @ 0x2ae0 (88 bytes) */
void FUN_00002ae0(int glContext,undefined4 op,double value)
{
  float fVar1;
  float fVar2;
  byte bVar3;
  byte bVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  ushort uVar10;
  float fVar11;
  float fVar12;
  uint uVar13;
  char cVar14;
  ushort uVar21;
  int iVar15;
  int iVar16;
  int iVar17;
  uint uVar18;
  int iVar19;
  uint uVar20;
  void *readbackPixels;
  int iVar23;
  undefined1 *puVar24;
  undefined2 *puVar25;
  int iVar26;
  ushort uVar27;
  int iVar28;
  uint uVar29;
  char *accumByteEnd;
  uint uVar31;
  byte *pbVar32;
  ushort *puVar33;
  int iVar34;
  byte *pbVar35;
  int iVar36;
  char *accumByteCursor;
  short *accumShortCursor;
  ushort uVar41;
  short *accumShortEnd;
  int iVar40;
  ushort *readbackHalfCursor;
  uint *readbackWordCursor;
  uint uVar44;
  uint paddedRowPixels;
  uint uVar46;
  undefined1 *puVar47;
  ushort *puVar48;
  undefined2 *puVar49;
  double dVar50;
  double dVar51;
  double dVar52;
  double dVar53;
  double dVar54;
  double dVar55;
  double dVar56;
  short sStack_262;
  short sStack_25a;
  short sStack_252;
  short sStack_24a;
  short sStack_242;
  short sStack_23a;
  short sStack_232;
  short sStack_22a;
  short sStack_da;
  
  iVar28 = *(int *)(glContext + 0x148);
  if (iVar28 == 0) {
    return;
  }
  switch(op) {
  case 0x100:
    if ((*(uint *)(glContext + 0x154) & 3) == 0) {
      iVar28 = *(int *)(glContext + 0x10);
      if (((unsigned char *)0x00003190)[iVar28] == '\0') {
        iVar19 = *(int *)(glContext + 0x15c);
        iVar26 = *(int *)(glContext + 0x160);
        iVar23 = 0;
        uVar29 = 0;
        uVar20 = iVar19 + 7U & 0xfffffff8;
        iVar28 = iVar26;
      }
      else {
        iVar23 = *(int *)(((unsigned char *)0x00003180) + iVar28);
        iVar26 = *(int *)(glContext + 0x160);
        uVar20 = iVar23 + *(int *)(((unsigned char *)0x00003188) + iVar28);
        uVar29 = iVar26 - (*(int *)(((unsigned char *)0x0000318c) + iVar28) + *(int *)(((unsigned char *)0x00003184) + iVar28));
        iVar28 = *(int *)(((unsigned char *)0x0000318c) + iVar28) + uVar29;
        if (iVar23 < 0) {
          iVar23 = 0;
        }
        if ((int)uVar29 < 0) {
          uVar29 = 0;
        }
        iVar19 = *(int *)(glContext + 0x15c);
        uVar31 = iVar19 + 7U & 0xfffffff8;
        if ((int)uVar31 < (int)uVar20) {
          uVar20 = uVar31;
        }
        iVar34 = iVar26;
        if (iVar28 <= iVar26) {
          iVar34 = iVar28;
        }
        uVar20 = uVar20 - iVar23;
        iVar28 = iVar34 - uVar29;
      }
      if (uVar20 == 0) {
        return;
      }
      if (iVar28 == 0) {
        return;
      }
      readbackPixels = _malloc((iVar19 + 7U & 0xfffffff8) * iVar26 * 4);
      FUN_00029290(glContext,0,0,*(int *)(glContext + 0x15c) + 7U & 0xfffffff8,
                   *(undefined4 *)(glContext + 0x160),0x80e1,0x8367,readbackPixels,2,0);
      uVar31 = uVar29 + iVar28;
      if (value < (double)FLOAT_001aa0d4) {
        *(undefined1 *)(glContext + 0x140) = 1;
      }
      paddedRowPixels = *(int *)(glContext + 0x15c) + 7U & 0xfffffff8;
      iVar23 = iVar23 + paddedRowPixels * ((*(int *)(glContext + 0x160) - uVar29) + -1);
      if (*(char *)(glContext + 0x141) == '\x01') {
        sStack_252 = (short)(int)(value * (double)FLOAT_001aa0d8);
        iVar28 = (int)sStack_252;
        if (uVar29 < uVar31) {
          iVar19 = 0;
          do {
            readbackWordCursor = (uint *)((int)readbackPixels + iVar23 * 4);
            accumByteCursor = (char *)(iVar23 * 4 + *(int *)(glContext + 0x148));
            accumByteEnd = accumByteCursor + uVar20 * 4;
            for (; accumByteCursor < accumByteEnd; accumByteCursor = accumByteCursor + 4) {
              uVar13 = *readbackWordCursor;
              readbackWordCursor = readbackWordCursor + 1;
              *accumByteCursor = (char)((int)(iVar28 * (uVar13 >> 9 & 0x7f80 | uVar13 >> 0x11 & 0x7f)) >>
                               0x17) + *accumByteCursor;
              accumByteCursor[3] = (char)((int)(iVar28 * (uVar13 >> 0x11 & 0x7f80 | uVar13 >> 0x19)) >> 0x17
                                 ) + accumByteCursor[3];
              accumByteCursor[1] = (char)((int)(iVar28 * (uVar13 >> 1 & 0x7f80 | uVar13 >> 9 & 0x7f)) >>
                                 0x17) + accumByteCursor[1];
              accumByteCursor[2] = (char)((int)(iVar28 * ((uVar13 & 0xff) << 7 | uVar13 >> 1 & 0x7f)) >>
                                 0x17) + accumByteCursor[2];
            }
            iVar19 = iVar19 + 1;
            iVar23 = iVar23 - paddedRowPixels;
          } while (uVar31 - uVar29 != iVar19);
        }
      }
      else {
        sStack_24a = (short)(int)(value * (double)FLOAT_001aa0d8);
        iVar28 = (int)sStack_24a;
        if (uVar29 < uVar31) {
          iVar19 = 0;
          do {
            readbackWordCursor = (uint *)((int)readbackPixels + iVar23 * 4);
            accumShortCursor = (short *)(iVar23 * 8 + *(int *)(glContext + 0x148));
            accumShortEnd = accumShortCursor + uVar20 * 4;
            for (; accumShortCursor < accumShortEnd; accumShortCursor = accumShortCursor + 4) {
              uVar13 = *readbackWordCursor;
              readbackWordCursor = readbackWordCursor + 1;
              *accumShortCursor = (short)((int)(iVar28 * (uVar13 >> 9 & 0x7f80 | uVar13 >> 0x11 & 0x7f)) >>
                                0xf) + *accumShortCursor;
              accumShortCursor[3] = (short)((int)(iVar28 * (uVar13 >> 0x11 & 0x7f80 | uVar13 >> 0x19)) >> 0xf
                                  ) + accumShortCursor[3];
              accumShortCursor[1] = (short)((int)(iVar28 * (uVar13 >> 1 & 0x7f80 | uVar13 >> 9 & 0x7f)) >>
                                  0xf) + accumShortCursor[1];
              accumShortCursor[2] = (short)((int)(iVar28 * ((uVar13 & 0xff) << 7 | uVar13 >> 1 & 0x7f)) >>
                                  0xf) + accumShortCursor[2];
            }
            iVar19 = iVar19 + 1;
            iVar23 = iVar23 - paddedRowPixels;
          } while (uVar31 - uVar29 != iVar19);
        }
      }
    }
    else {
      iVar28 = *(int *)(glContext + 0x10);
      if (((unsigned char *)0x00003190)[iVar28] == '\0') {
        iVar19 = *(int *)(glContext + 0x15c);
        iVar26 = *(int *)(glContext + 0x160);
        iVar23 = 0;
        uVar29 = 0;
        uVar20 = iVar19 + 7U & 0xfffffff8;
        iVar28 = iVar26;
      }
      else {
        iVar23 = *(int *)(((unsigned char *)0x00003180) + iVar28);
        iVar26 = *(int *)(glContext + 0x160);
        uVar20 = iVar23 + *(int *)(((unsigned char *)0x00003188) + iVar28);
        uVar29 = iVar26 - (*(int *)(((unsigned char *)0x0000318c) + iVar28) + *(int *)(((unsigned char *)0x00003184) + iVar28));
        iVar28 = *(int *)(((unsigned char *)0x0000318c) + iVar28) + uVar29;
        if (iVar23 < 0) {
          iVar23 = 0;
        }
        if ((int)uVar29 < 0) {
          uVar29 = 0;
        }
        iVar19 = *(int *)(glContext + 0x15c);
        uVar31 = iVar19 + 7U & 0xfffffff8;
        if ((int)uVar31 < (int)uVar20) {
          uVar20 = uVar31;
        }
        iVar34 = iVar26;
        if (iVar28 <= iVar26) {
          iVar34 = iVar28;
        }
        uVar20 = uVar20 - iVar23;
        iVar28 = iVar34 - uVar29;
      }
      if (uVar20 == 0) {
        return;
      }
      if (iVar28 == 0) {
        return;
      }
      readbackPixels = _malloc((iVar19 + 7U & 0xfffffff8) * iVar26 * 2);
      FUN_00029290(glContext,0,0,*(int *)(glContext + 0x15c) + 7U & 0xfffffff8,
                   *(undefined4 *)(glContext + 0x160),0x80e1,0x8366,readbackPixels,2,0);
      uVar31 = uVar29 + iVar28;
      if (value < (double)FLOAT_001aa0d4) {
        *(undefined1 *)(glContext + 0x140) = 1;
      }
      paddedRowPixels = *(int *)(glContext + 0x15c) + 7U & 0xfffffff8;
      iVar23 = iVar23 + paddedRowPixels * ((*(int *)(glContext + 0x160) - uVar29) + -1);
      if (*(char *)(glContext + 0x141) == '\x01') {
        sStack_262 = (short)(int)(value * (double)FLOAT_001aa0d8);
        iVar28 = (int)sStack_262;
        if (uVar29 < uVar31) {
          iVar19 = 0;
          do {
            readbackHalfCursor = (ushort *)((int)readbackPixels + iVar23 * 2);
            accumByteCursor = (char *)(iVar23 * 4 + *(int *)(glContext + 0x148));
            accumByteEnd = accumByteCursor + uVar20 * 4;
            for (; accumByteCursor < accumByteEnd; accumByteCursor = accumByteCursor + 4) {
              uVar27 = *readbackHalfCursor;
              readbackHalfCursor = readbackHalfCursor + 1;
              uVar13 = (uint)uVar27 << 5;
              accumByteCursor[1] = (char)((int)(iVar28 * (uVar13 & 0x7c00 | uVar27 & 0x3e0 |
                                                 uVar27 >> 5 & 0x1f)) >> 0x17) + accumByteCursor[1];
              accumByteCursor[3] = (char)((int)(iVar28 * (-(uint)(uVar27 >> 0xf) & 0x7fff)) >> 0x17) +
                           accumByteCursor[3];
              *accumByteCursor = (char)((int)(iVar28 * (uVar27 & 0x7c00 | uVar27 >> 5 & 0x3e0 |
                                               uVar27 >> 10 & 0x1f)) >> 0x17) + *accumByteCursor;
              accumByteCursor[2] = (char)((int)(iVar28 * ((uVar27 & 0x1f) << 10 | uVar13 & 0x3e0 |
                                                 uVar27 & 0x1f)) >> 0x17) + accumByteCursor[2];
            }
            iVar19 = iVar19 + 1;
            iVar23 = iVar23 - paddedRowPixels;
          } while (uVar31 - uVar29 != iVar19);
        }
      }
      else {
        sStack_25a = (short)(int)(value * (double)FLOAT_001aa0d8);
        iVar28 = (int)sStack_25a;
        if (uVar29 < uVar31) {
          iVar19 = 0;
          do {
            readbackHalfCursor = (ushort *)((int)readbackPixels + iVar23 * 2);
            accumShortCursor = (short *)(iVar23 * 8 + *(int *)(glContext + 0x148));
            accumShortEnd = accumShortCursor + uVar20 * 4;
            for (; accumShortCursor < accumShortEnd; accumShortCursor = accumShortCursor + 4) {
              uVar27 = *readbackHalfCursor;
              readbackHalfCursor = readbackHalfCursor + 1;
              uVar13 = (uint)uVar27 << 5;
              accumShortCursor[1] = (short)((int)(iVar28 * (uVar13 & 0x7c00 | uVar27 & 0x3e0 |
                                                  uVar27 >> 5 & 0x1f)) >> 0xf) + accumShortCursor[1];
              accumShortCursor[3] = (short)((int)(iVar28 * (-(uint)(uVar27 >> 0xf) & 0x7fff)) >> 0xf) +
                           accumShortCursor[3];
              *accumShortCursor = (short)((int)(iVar28 * (uVar27 & 0x7c00 | uVar27 >> 5 & 0x3e0 |
                                                uVar27 >> 10 & 0x1f)) >> 0xf) + *accumShortCursor;
              accumShortCursor[2] = (short)((int)(iVar28 * ((uVar27 & 0x1f) << 10 | uVar13 & 0x3e0 |
                                                  uVar27 & 0x1f)) >> 0xf) + accumShortCursor[2];
            }
            iVar19 = iVar19 + 1;
            iVar23 = iVar23 - paddedRowPixels;
          } while (uVar31 - uVar29 != iVar19);
        }
      }
    }
    goto code_r0x00003264;
  case 0x101:
    if ((*(uint *)(glContext + 0x154) & 3) == 0) {
      iVar28 = *(int *)(glContext + 0x10);
      if (((unsigned char *)0x00003190)[iVar28] == '\0') {
        iVar19 = *(int *)(glContext + 0x15c);
        iVar26 = *(int *)(glContext + 0x160);
        iVar23 = 0;
        uVar29 = 0;
        uVar20 = iVar19 + 7U & 0xfffffff8;
        iVar28 = iVar26;
      }
      else {
        iVar23 = *(int *)(((unsigned char *)0x00003180) + iVar28);
        iVar26 = *(int *)(glContext + 0x160);
        uVar20 = iVar23 + *(int *)(((unsigned char *)0x00003188) + iVar28);
        uVar29 = iVar26 - (*(int *)(((unsigned char *)0x0000318c) + iVar28) + *(int *)(((unsigned char *)0x00003184) + iVar28));
        iVar28 = *(int *)(((unsigned char *)0x0000318c) + iVar28) + uVar29;
        if (iVar23 < 0) {
          iVar23 = 0;
        }
        if ((int)uVar29 < 0) {
          uVar29 = 0;
        }
        iVar19 = *(int *)(glContext + 0x15c);
        uVar31 = iVar19 + 7U & 0xfffffff8;
        if ((int)uVar31 < (int)uVar20) {
          uVar20 = uVar31;
        }
        iVar34 = iVar26;
        if (iVar28 <= iVar26) {
          iVar34 = iVar28;
        }
        uVar20 = uVar20 - iVar23;
        iVar28 = iVar34 - uVar29;
      }
      if (uVar20 == 0) {
        return;
      }
      if (iVar28 == 0) {
        return;
      }
      readbackPixels = _malloc((iVar19 + 7U & 0xfffffff8) * iVar26 * 4);
      FUN_00029290(glContext,0,0,*(int *)(glContext + 0x15c) + 7U & 0xfffffff8,
                   *(undefined4 *)(glContext + 0x160),0x80e1,0x8367,readbackPixels,2,0);
      uVar31 = uVar29 + iVar28;
      if (value < (double)FLOAT_001aa0d4) {
        *(undefined1 *)(glContext + 0x140) = 1;
      }
      paddedRowPixels = *(int *)(glContext + 0x15c) + 7U & 0xfffffff8;
      iVar23 = iVar23 + paddedRowPixels * ((*(int *)(glContext + 0x160) - uVar29) + -1);
      if (*(char *)(glContext + 0x141) == '\x01') {
        if (value == (double)FLOAT_001aa0e8) {
          if (uVar29 < uVar31) {
            iVar28 = 0;
            do {
              readbackWordCursor = (uint *)((int)readbackPixels + iVar23 * 4);
              pbVar35 = (byte *)(iVar23 * 4 + *(int *)(glContext + 0x148));
              pbVar32 = pbVar35 + uVar20 * 4;
              for (; pbVar35 < pbVar32; pbVar35 = pbVar35 + 4) {
                uVar13 = *readbackWordCursor;
                readbackWordCursor = readbackWordCursor + 1;
                *pbVar35 = (byte)(uVar13 >> 0x11) & 0x7f;
                pbVar35[3] = (byte)(uVar13 >> 0x19);
                pbVar35[1] = (byte)(uVar13 >> 9) & 0x7f;
                pbVar35[2] = (byte)(uVar13 >> 1) & 0x7f;
              }
              iVar28 = iVar28 + 1;
              iVar23 = iVar23 - paddedRowPixels;
            } while (uVar31 - uVar29 != iVar28);
          }
        }
        else {
          sStack_232 = (short)(int)(value * (double)FLOAT_001aa0d8);
          iVar28 = (int)sStack_232;
          if (uVar29 < uVar31) {
            iVar19 = 0;
            do {
              readbackWordCursor = (uint *)((int)readbackPixels + iVar23 * 4);
              puVar24 = (undefined1 *)(iVar23 * 4 + *(int *)(glContext + 0x148));
              puVar47 = puVar24 + uVar20 * 4;
              for (; puVar24 < puVar47; puVar24 = puVar24 + 4) {
                uVar13 = *readbackWordCursor;
                readbackWordCursor = readbackWordCursor + 1;
                *puVar24 = (char)((int)(iVar28 * (uVar13 >> 9 & 0x7f80 | uVar13 >> 0x11 & 0x7f)) >>
                                 0x17);
                puVar24[3] = (char)((int)(iVar28 * (uVar13 >> 0x11 & 0x7f80 | uVar13 >> 0x19)) >>
                                   0x17);
                puVar24[1] = (char)((int)(iVar28 * (uVar13 >> 1 & 0x7f80 | uVar13 >> 9 & 0x7f)) >>
                                   0x17);
                puVar24[2] = (char)((int)(iVar28 * ((uVar13 & 0xff) << 7 | uVar13 >> 1 & 0x7f)) >>
                                   0x17);
              }
              iVar19 = iVar19 + 1;
              iVar23 = iVar23 - paddedRowPixels;
            } while (uVar31 - uVar29 != iVar19);
          }
        }
      }
      else if (value == (double)FLOAT_001aa0e8) {
        if (uVar29 < uVar31) {
          iVar28 = 0;
          do {
            readbackWordCursor = (uint *)((int)readbackPixels + iVar23 * 4);
            readbackHalfCursor = (ushort *)(iVar23 * 8 + *(int *)(glContext + 0x148));
            puVar33 = readbackHalfCursor + uVar20 * 4;
            for (; readbackHalfCursor < puVar33; readbackHalfCursor = readbackHalfCursor + 4) {
              uVar13 = *readbackWordCursor;
              readbackWordCursor = readbackWordCursor + 1;
              uVar10 = (ushort)(uVar13 >> 0x10);
              uVar21 = uVar10 >> 1;
              uVar27 = (ushort)(uVar13 >> 9);
              uVar41 = (ushort)(uVar13 >> 1);
              readbackHalfCursor[3] = uVar21 & 0x7f80 | uVar10 >> 9;
              *readbackHalfCursor = uVar27 & 0x7f80 | uVar21 & 0x7f;
              readbackHalfCursor[1] = uVar41 & 0x7f80 | uVar27 & 0x7f;
              readbackHalfCursor[2] = (ushort)(uVar13 << 7) & 0x7f80 | uVar41 & 0x7f;
            }
            iVar28 = iVar28 + 1;
            iVar23 = iVar23 - paddedRowPixels;
          } while (uVar31 - uVar29 != iVar28);
        }
      }
      else {
        sStack_22a = (short)(int)(value * (double)FLOAT_001aa0d8);
        iVar28 = (int)sStack_22a;
        if (uVar29 < uVar31) {
          iVar19 = 0;
          do {
            readbackWordCursor = (uint *)((int)readbackPixels + iVar23 * 4);
            puVar25 = (undefined2 *)(iVar23 * 8 + *(int *)(glContext + 0x148));
            puVar49 = puVar25 + uVar20 * 4;
            for (; puVar25 < puVar49; puVar25 = puVar25 + 4) {
              uVar13 = *readbackWordCursor;
              readbackWordCursor = readbackWordCursor + 1;
              *puVar25 = (short)((int)(iVar28 * (uVar13 >> 9 & 0x7f80 | uVar13 >> 0x11 & 0x7f)) >>
                                0xf);
              puVar25[3] = (short)((int)(iVar28 * (uVar13 >> 0x11 & 0x7f80 | uVar13 >> 0x19)) >> 0xf
                                  );
              puVar25[1] = (short)((int)(iVar28 * (uVar13 >> 1 & 0x7f80 | uVar13 >> 9 & 0x7f)) >>
                                  0xf);
              puVar25[2] = (short)((int)(iVar28 * ((uVar13 & 0xff) << 7 | uVar13 >> 1 & 0x7f)) >>
                                  0xf);
            }
            iVar19 = iVar19 + 1;
            iVar23 = iVar23 - paddedRowPixels;
          } while (uVar31 - uVar29 != iVar19);
        }
      }
    }
    else {
      iVar28 = *(int *)(glContext + 0x10);
      if (((unsigned char *)0x00003190)[iVar28] == '\0') {
        iVar19 = *(int *)(glContext + 0x15c);
        iVar26 = *(int *)(glContext + 0x160);
        iVar23 = 0;
        uVar29 = 0;
        uVar20 = iVar19 + 7U & 0xfffffff8;
        iVar28 = iVar26;
      }
      else {
        iVar23 = *(int *)(((unsigned char *)0x00003180) + iVar28);
        iVar26 = *(int *)(glContext + 0x160);
        uVar20 = iVar23 + *(int *)(((unsigned char *)0x00003188) + iVar28);
        uVar29 = iVar26 - (*(int *)(((unsigned char *)0x0000318c) + iVar28) + *(int *)(((unsigned char *)0x00003184) + iVar28));
        iVar28 = *(int *)(((unsigned char *)0x0000318c) + iVar28) + uVar29;
        if (iVar23 < 0) {
          iVar23 = 0;
        }
        if ((int)uVar29 < 0) {
          uVar29 = 0;
        }
        iVar19 = *(int *)(glContext + 0x15c);
        uVar31 = iVar19 + 7U & 0xfffffff8;
        if ((int)uVar31 < (int)uVar20) {
          uVar20 = uVar31;
        }
        iVar34 = iVar26;
        if (iVar28 <= iVar26) {
          iVar34 = iVar28;
        }
        uVar20 = uVar20 - iVar23;
        iVar28 = iVar34 - uVar29;
      }
      if (uVar20 == 0) {
        return;
      }
      if (iVar28 == 0) {
        return;
      }
      readbackPixels = _malloc((iVar19 + 7U & 0xfffffff8) * iVar26 * 2);
      FUN_00029290(glContext,0,0,*(int *)(glContext + 0x15c) + 7U & 0xfffffff8,
                   *(undefined4 *)(glContext + 0x160),0x80e1,0x8366,readbackPixels,2,0);
      uVar31 = uVar29 + iVar28;
      if (value < (double)FLOAT_001aa0d4) {
        *(undefined1 *)(glContext + 0x140) = 1;
      }
      paddedRowPixels = *(int *)(glContext + 0x15c) + 7U & 0xfffffff8;
      iVar23 = iVar23 + paddedRowPixels * ((*(int *)(glContext + 0x160) - uVar29) + -1);
      if (*(char *)(glContext + 0x141) == '\x01') {
        if (value == (double)FLOAT_001aa0e8) {
          if (uVar29 < uVar31) {
            iVar28 = 0;
            do {
              readbackHalfCursor = (ushort *)((int)readbackPixels + iVar23 * 2);
              pbVar35 = (byte *)(iVar23 * 4 + *(int *)(glContext + 0x148));
              pbVar32 = pbVar35 + uVar20 * 4;
              for (; pbVar35 < pbVar32; pbVar35 = pbVar35 + 4) {
                uVar27 = *readbackHalfCursor;
                readbackHalfCursor = readbackHalfCursor + 1;
                bVar3 = (byte)(uVar27 >> 8);
                bVar4 = (byte)(uVar27 >> 3);
                pbVar35[2] = ((byte)uVar27 & 0x1f) << 2 | bVar4 & 3;
                pbVar35[3] = (char)bVar3 >> 7 & 0x7f;
                *pbVar35 = bVar3 & 0x7c | bVar3 >> 5 & 3;
                pbVar35[1] = bVar4 & 0x7c | bVar3 & 3;
              }
              iVar28 = iVar28 + 1;
              iVar23 = iVar23 - paddedRowPixels;
            } while (uVar31 - uVar29 != iVar28);
          }
        }
        else {
          sStack_242 = (short)(int)(value * (double)FLOAT_001aa0d8);
          iVar28 = (int)sStack_242;
          if (uVar29 < uVar31) {
            iVar19 = 0;
            do {
              readbackHalfCursor = (ushort *)((int)readbackPixels + iVar23 * 2);
              puVar24 = (undefined1 *)(iVar23 * 4 + *(int *)(glContext + 0x148));
              puVar47 = puVar24 + uVar20 * 4;
              for (; puVar24 < puVar47; puVar24 = puVar24 + 4) {
                uVar27 = *readbackHalfCursor;
                readbackHalfCursor = readbackHalfCursor + 1;
                uVar13 = (uint)uVar27 << 5;
                puVar24[1] = (char)((int)(iVar28 * (uVar13 & 0x7c00 | uVar27 & 0x3e0 |
                                                   uVar27 >> 5 & 0x1f)) >> 0x17);
                puVar24[3] = (char)((int)(iVar28 * (-(uint)(uVar27 >> 0xf) & 0x7fff)) >> 0x17);
                *puVar24 = (char)((int)(iVar28 * (uVar27 & 0x7c00 | uVar27 >> 5 & 0x3e0 |
                                                 uVar27 >> 10 & 0x1f)) >> 0x17);
                puVar24[2] = (char)((int)(iVar28 * ((uVar27 & 0x1f) << 10 | uVar13 & 0x3e0 |
                                                   uVar27 & 0x1f)) >> 0x17);
              }
              iVar19 = iVar19 + 1;
              iVar23 = iVar23 - paddedRowPixels;
            } while (uVar31 - uVar29 != iVar19);
          }
        }
      }
      else if (value == (double)FLOAT_001aa0e8) {
        if (uVar29 < uVar31) {
          iVar28 = 0;
          do {
            readbackHalfCursor = (ushort *)((int)readbackPixels + iVar23 * 2);
            puVar33 = (ushort *)(iVar23 * 8 + *(int *)(glContext + 0x148));
            puVar48 = puVar33 + uVar20 * 4;
            for (; puVar33 < puVar48; puVar33 = puVar33 + 4) {
              uVar27 = *readbackHalfCursor;
              readbackHalfCursor = readbackHalfCursor + 1;
              puVar33[1] = uVar27 << 5 & 0x7c00 | uVar27 & 0x3e0 | uVar27 >> 5 & 0x1f;
              puVar33[2] = (uVar27 & 0x1f) << 10 | uVar27 << 5 & 0x3e0 | uVar27 & 0x1f;
              *puVar33 = uVar27 & 0x7c00 | uVar27 >> 5 & 0x3e0 | uVar27 >> 10 & 0x1f;
              puVar33[3] = (short)uVar27 >> 0xf & 0x7fff;
            }
            iVar28 = iVar28 + 1;
            iVar23 = iVar23 - paddedRowPixels;
          } while (uVar31 - uVar29 != iVar28);
        }
      }
      else {
        sStack_23a = (short)(int)(value * (double)FLOAT_001aa0d8);
        iVar28 = (int)sStack_23a;
        if (uVar29 < uVar31) {
          iVar19 = 0;
          do {
            readbackHalfCursor = (ushort *)((int)readbackPixels + iVar23 * 2);
            puVar25 = (undefined2 *)(iVar23 * 8 + *(int *)(glContext + 0x148));
            puVar49 = puVar25 + uVar20 * 4;
            for (; puVar25 < puVar49; puVar25 = puVar25 + 4) {
              uVar27 = *readbackHalfCursor;
              readbackHalfCursor = readbackHalfCursor + 1;
              uVar13 = (uint)uVar27 << 5;
              puVar25[1] = (short)((int)(iVar28 * (uVar13 & 0x7c00 | uVar27 & 0x3e0 |
                                                  uVar27 >> 5 & 0x1f)) >> 0xf);
              puVar25[3] = (short)((int)(iVar28 * (-(uint)(uVar27 >> 0xf) & 0x7fff)) >> 0xf);
              *puVar25 = (short)((int)(iVar28 * (uVar27 & 0x7c00 | uVar27 >> 5 & 0x3e0 |
                                                uVar27 >> 10 & 0x1f)) >> 0xf);
              puVar25[2] = (short)((int)(iVar28 * ((uVar27 & 0x1f) << 10 | uVar13 & 0x3e0 |
                                                  uVar27 & 0x1f)) >> 0xf);
            }
            iVar19 = iVar19 + 1;
            iVar23 = iVar23 - paddedRowPixels;
          } while (uVar31 - uVar29 != iVar19);
        }
      }
    }
code_r0x00003264:
                    
                    
    (*(code *)PTR_FUN_001e8754)(readbackPixels);
    return;
  case 0x102:
    if ((*(uint *)(glContext + 0x154) & 3) == 0) {
      iVar28 = *(int *)(glContext + 0x10);
      if (*(int *)(((unsigned char *)0x00002e40U) + iVar28) != 0) {
        if (((unsigned char *)0x00003190)[iVar28] == '\0') {
          iVar19 = *(int *)(glContext + 0x15c);
          iVar26 = *(int *)(glContext + 0x160);
          iVar23 = 0;
          uVar29 = 0;
          uVar20 = iVar19 + 7U & 0xfffffff8;
          iVar28 = iVar26;
        }
        else {
          iVar23 = *(int *)(((unsigned char *)0x00003180) + iVar28);
          iVar26 = *(int *)(glContext + 0x160);
          uVar20 = iVar23 + *(int *)(((unsigned char *)0x00003188) + iVar28);
          uVar29 = iVar26 - (*(int *)(((unsigned char *)0x0000318c) + iVar28) + *(int *)(((unsigned char *)0x00003184) + iVar28));
          iVar28 = *(int *)(((unsigned char *)0x0000318c) + iVar28) + uVar29;
          if (iVar23 < 0) {
            iVar23 = 0;
          }
          if ((int)uVar29 < 0) {
            uVar29 = 0;
          }
          iVar19 = *(int *)(glContext + 0x15c);
          uVar31 = iVar19 + 7U & 0xfffffff8;
          if ((int)uVar31 < (int)uVar20) {
            uVar20 = uVar31;
          }
          iVar34 = iVar26;
          if (iVar28 <= iVar26) {
            iVar34 = iVar28;
          }
          uVar20 = uVar20 - iVar23;
          iVar28 = iVar34 - uVar29;
        }
        if ((uVar20 != 0) && (iVar28 != 0)) {
          readbackPixels = _malloc((iVar19 + 7U & 0xfffffff8) * iVar26 * 4);
          iVar26 = *(int *)(glContext + 0x160);
          paddedRowPixels = uVar29 + iVar28;
          iVar19 = *(int *)(glContext + 0x15c);
          uVar31 = iVar19 + 7U & 0xfffffff8;
          cVar14 = *(char *)(glContext + 0x140);
          iVar34 = iVar23 + uVar31 * ((iVar26 - uVar29) + -1);
          if (*(char *)(glContext + 0x141) == '\x01') {
            if (value == (double)FLOAT_001aa0e8) {
              if (uVar29 < paddedRowPixels) {
                iVar36 = *(int *)(glContext + 0x148);
                iVar40 = 0;
                do {
                  pbVar35 = (byte *)(iVar34 * 4 + iVar36);
                  readbackWordCursor = (uint *)((int)readbackPixels + iVar34 * 4);
                  pbVar32 = pbVar35 + uVar20 * 4;
                  if (cVar14 == '\0') {
                    for (; pbVar35 < pbVar32; pbVar35 = pbVar35 + 4) {
                      *readbackWordCursor = (uint)pbVar35[3] << 0x19 | (*pbVar35 & 0x7f) << 0x11 |
                                 (pbVar35[1] & 0x7f) << 9 | (pbVar35[2] & 0x7f) << 1;
                      readbackWordCursor = readbackWordCursor + 1;
                    }
                  }
                  else {
                    for (; pbVar35 < pbVar32; pbVar35 = pbVar35 + 4) {
                      uVar13 = 0;
                      if (-1 < (char)*pbVar35) {
                        uVar13 = (int)(char)*pbVar35;
                      }
                      uVar44 = 0;
                      if (-1 < (char)pbVar35[1]) {
                        uVar44 = (int)(char)pbVar35[1];
                      }
                      uVar46 = 0;
                      if (-1 < (char)pbVar35[2]) {
                        uVar46 = (int)(char)pbVar35[2];
                      }
                      iVar15 = 0;
                      if (-1 < (char)pbVar35[3]) {
                        iVar15 = (int)(char)pbVar35[3];
                      }
                      *readbackWordCursor = iVar15 << 0x19 | (uVar13 & 0x7f) << 0x11 | (uVar44 & 0x7f) << 9 |
                                 (uVar46 & 0x7f) << 1;
                      readbackWordCursor = readbackWordCursor + 1;
                    }
                  }
                  iVar40 = iVar40 + 1;
                  iVar34 = iVar34 - uVar31;
                } while (iVar40 != paddedRowPixels - uVar29);
              }
            }
            else {
              fVar1 = (float)(value * (double)FLOAT_001aa0dc);
              if (uVar29 < paddedRowPixels) {
                iVar40 = *(int *)(glContext + 0x148);
                iVar36 = 0;
                do {
                  dVar51 = DOUBLE_001aa1e0;
                  accumByteEnd = (char *)(iVar34 * 4 + iVar40);
                  readbackWordCursor = (uint *)((int)readbackPixels + iVar34 * 4);
                  accumByteCursor = accumByteEnd + uVar20 * 4;
                  if (accumByteEnd < accumByteCursor) {
                    dVar52 = (double)FLOAT_001aa0d4;
                    dVar53 = (double)FLOAT_001aa0f0;
                    do {
                      dVar50 = (double)(fVar1 * (float)((double)CONCAT44(0x43300000,
                                                                         (int)*accumByteEnd ^ 0x80000000)
                                                       - dVar51));
                      fVar2 = FLOAT_001aa0d4;
                      if (dVar52 <= dVar50) {
                        fVar2 = (float)(dVar50 * dVar53);
                      }
                      dVar55 = (double)FLOAT_001aa0d4;
                      dVar50 = (double)(fVar1 * (float)((double)CONCAT44(0x43300000,
                                                                         (int)accumByteEnd[1] ^
                                                                         0x80000000) - dVar51));
                      if (dVar55 <= dVar50) {
                        dVar55 = (double)(float)(dVar50 * dVar53);
                      }
                      dVar54 = (double)FLOAT_001aa0d4;
                      dVar50 = (double)(fVar1 * (float)((double)CONCAT44(0x43300000,
                                                                         (int)accumByteEnd[2] ^
                                                                         0x80000000) - dVar51));
                      if (dVar54 <= dVar50) {
                        dVar54 = (double)(float)(dVar50 * dVar53);
                      }
                      dVar56 = (double)FLOAT_001aa0d4;
                      dVar50 = (double)(fVar1 * (float)((double)CONCAT44(0x43300000,
                                                                         (int)accumByteEnd[3] ^
                                                                         0x80000000) - dVar51));
                      if (dVar56 <= dVar50) {
                        dVar56 = (double)(float)(dVar50 * dVar53);
                      }
                      if (DOUBLE_001aa1e8 <= dVar56) {
                        iVar15 = (int)(dVar56 - DOUBLE_001aa1e8) + -0x80000000;
                      }
                      else {
                        iVar15 = (int)dVar56;
                      }
                      if (DOUBLE_001aa1e8 <= (double)fVar2) {
                        iVar16 = (int)((double)fVar2 - DOUBLE_001aa1e8) + -0x80000000;
                      }
                      else {
                        iVar16 = (int)fVar2;
                      }
                      if (DOUBLE_001aa1e8 <= dVar55) {
                        iVar17 = (int)(dVar55 - DOUBLE_001aa1e8) + -0x80000000;
                      }
                      else {
                        iVar17 = (int)dVar55;
                      }
                      if (DOUBLE_001aa1e8 <= dVar54) {
                        uVar13 = (int)(dVar54 - DOUBLE_001aa1e8) + 0x80000000;
                      }
                      else {
                        uVar13 = (uint)(int)dVar54;
                      }
                      accumByteEnd = accumByteEnd + 4;
                      *readbackWordCursor = iVar15 << 0x18 | iVar16 << 0x10 | iVar17 << 8 | uVar13;
                      readbackWordCursor = readbackWordCursor + 1;
                    } while (accumByteEnd < accumByteCursor);
                  }
                  iVar36 = iVar36 + 1;
                  iVar34 = iVar34 - uVar31;
                } while (iVar36 != paddedRowPixels - uVar29);
              }
            }
          }
          else if (value == (double)FLOAT_001aa0e8) {
            if (uVar29 < paddedRowPixels) {
              iVar36 = *(int *)(glContext + 0x148);
              iVar40 = 0;
              do {
                accumShortCursor = (short *)(iVar34 * 8 + iVar36);
                readbackWordCursor = (uint *)((int)readbackPixels + iVar34 * 4);
                accumShortEnd = accumShortCursor + uVar20 * 4;
                if (cVar14 == '\0') {
                  for (; accumShortCursor < accumShortEnd; accumShortCursor = accumShortCursor + 4) {
                    *readbackWordCursor = ((int)accumShortCursor[3] & 0x7f80U) << 0x11 | ((int)*accumShortCursor & 0x7f80U) << 9
                               | ((int)accumShortCursor[1] & 0x7f80U) << 1 |
                               (uint)(int)accumShortCursor[2] >> 7 & 0xff;
                    readbackWordCursor = readbackWordCursor + 1;
                  }
                }
                else {
                  for (; accumShortCursor < accumShortEnd; accumShortCursor = accumShortCursor + 4) {
                    uVar13 = 0;
                    if (-1 < *accumShortCursor) {
                      uVar13 = (int)*accumShortCursor;
                    }
                    uVar44 = 0;
                    if (-1 < accumShortCursor[1]) {
                      uVar44 = (int)accumShortCursor[1];
                    }
                    uVar46 = 0;
                    if (-1 < accumShortCursor[2]) {
                      uVar46 = (int)accumShortCursor[2] >> 7;
                    }
                    uVar18 = 0;
                    if (-1 < accumShortCursor[3]) {
                      uVar18 = (int)accumShortCursor[3];
                    }
                    *readbackWordCursor = (uVar18 & 0x7f80) << 0x11 | (uVar13 & 0x7f80) << 9 |
                               (uVar44 & 0x7f80) << 1 | uVar46 & 0xff;
                    readbackWordCursor = readbackWordCursor + 1;
                  }
                }
                iVar40 = iVar40 + 1;
                iVar34 = iVar34 - uVar31;
              } while (iVar40 != paddedRowPixels - uVar29);
            }
          }
          else {
            fVar1 = (float)(value * (double)FLOAT_001aa0e4);
            if (uVar29 < paddedRowPixels) {
              iVar40 = *(int *)(glContext + 0x148);
              iVar36 = 0;
              do {
                dVar51 = DOUBLE_001aa1e0;
                accumShortEnd = (short *)(iVar34 * 8 + iVar40);
                readbackWordCursor = (uint *)((int)readbackPixels + iVar34 * 4);
                accumShortCursor = accumShortEnd + uVar20 * 4;
                if (accumShortEnd < accumShortCursor) {
                  dVar52 = (double)FLOAT_001aa0d4;
                  dVar53 = (double)FLOAT_001aa0f0;
                  do {
                    dVar50 = (double)(fVar1 * (float)((double)CONCAT44(0x43300000,
                                                                       (int)*accumShortEnd ^ 0x80000000) -
                                                     dVar51));
                    fVar2 = FLOAT_001aa0d4;
                    if (dVar52 <= dVar50) {
                      fVar2 = (float)(dVar50 * dVar53);
                    }
                    dVar55 = (double)FLOAT_001aa0d4;
                    dVar50 = (double)(fVar1 * (float)((double)CONCAT44(0x43300000,
                                                                       (int)accumShortEnd[1] ^ 0x80000000)
                                                     - dVar51));
                    if (dVar55 <= dVar50) {
                      dVar55 = (double)(float)(dVar50 * dVar53);
                    }
                    dVar54 = (double)FLOAT_001aa0d4;
                    dVar50 = (double)(fVar1 * (float)((double)CONCAT44(0x43300000,
                                                                       (int)accumShortEnd[2] ^ 0x80000000)
                                                     - dVar51));
                    if (dVar54 <= dVar50) {
                      dVar54 = (double)(float)(dVar50 * dVar53);
                    }
                    dVar56 = (double)FLOAT_001aa0d4;
                    dVar50 = (double)(fVar1 * (float)((double)CONCAT44(0x43300000,
                                                                       (int)accumShortEnd[3] ^ 0x80000000)
                                                     - dVar51));
                    if (dVar56 <= dVar50) {
                      dVar56 = (double)(float)(dVar50 * dVar53);
                    }
                    if (DOUBLE_001aa1e8 <= dVar56) {
                      iVar15 = (int)(dVar56 - DOUBLE_001aa1e8) + -0x80000000;
                    }
                    else {
                      iVar15 = (int)dVar56;
                    }
                    if (DOUBLE_001aa1e8 <= (double)fVar2) {
                      iVar16 = (int)((double)fVar2 - DOUBLE_001aa1e8) + -0x80000000;
                    }
                    else {
                      iVar16 = (int)fVar2;
                    }
                    if (DOUBLE_001aa1e8 <= dVar55) {
                      iVar17 = (int)(dVar55 - DOUBLE_001aa1e8) + -0x80000000;
                    }
                    else {
                      iVar17 = (int)dVar55;
                    }
                    if (DOUBLE_001aa1e8 <= dVar54) {
                      uVar13 = (int)(dVar54 - DOUBLE_001aa1e8) + 0x80000000;
                    }
                    else {
                      uVar13 = (uint)(int)dVar54;
                    }
                    accumShortEnd = accumShortEnd + 4;
                    *readbackWordCursor = iVar15 << 0x18 | iVar16 << 0x10 | iVar17 << 8 | uVar13;
                    readbackWordCursor = readbackWordCursor + 1;
                  } while (accumShortEnd < accumShortCursor);
                }
                iVar36 = iVar36 + 1;
                iVar34 = iVar34 - uVar31;
              } while (iVar36 != paddedRowPixels - uVar29);
            }
          }
          FUN_000198b0(glContext,iVar23,uVar29,uVar20,iVar28,0x8367,
                       (void *)((int)readbackPixels +
                               (((iVar26 - uVar29) - iVar28) * (iVar19 + 7U & 0xfffffff8) + iVar23)
                               * 4));
          goto code_r0x00003264;
        }
      }
    }
    else {
      iVar28 = *(int *)(glContext + 0x10);
      if (*(int *)(((unsigned char *)0x00002e40U) + iVar28) != 0) {
        if (((unsigned char *)0x00003190)[iVar28] == '\0') {
          iVar19 = *(int *)(glContext + 0x15c);
          iVar26 = *(int *)(glContext + 0x160);
          uVar29 = 0;
          uVar31 = 0;
          uVar20 = iVar19 + 7U & 0xfffffff8;
          iVar28 = iVar26;
        }
        else {
          uVar29 = *(uint *)(((unsigned char *)0x00003180) + iVar28);
          iVar26 = *(int *)(glContext + 0x160);
          uVar20 = uVar29 + *(int *)(((unsigned char *)0x00003188) + iVar28);
          uVar31 = iVar26 - (*(int *)(((unsigned char *)0x0000318c) + iVar28) + *(int *)(((unsigned char *)0x00003184) + iVar28));
          iVar28 = *(int *)(((unsigned char *)0x0000318c) + iVar28) + uVar31;
          if ((int)uVar29 < 0) {
            uVar29 = 0;
          }
          if ((int)uVar31 < 0) {
            uVar31 = 0;
          }
          iVar19 = *(int *)(glContext + 0x15c);
          paddedRowPixels = iVar19 + 7U & 0xfffffff8;
          if ((int)paddedRowPixels < (int)uVar20) {
            uVar20 = paddedRowPixels;
          }
          iVar23 = iVar26;
          if (iVar28 <= iVar26) {
            iVar23 = iVar28;
          }
          uVar20 = uVar20 - uVar29;
          iVar28 = iVar23 - uVar31;
        }
        if ((uVar20 != 0) && (iVar28 != 0)) {
          readbackPixels = _malloc((iVar19 + 7U & 0xfffffff8) * iVar26 * 2);
          fVar1 = FLOAT_001aa0e0;
          iVar26 = *(int *)(glContext + 0x160);
          uVar44 = uVar29 + uVar20;
          iVar19 = *(int *)(glContext + 0x15c);
          cVar14 = *(char *)(glContext + 0x140);
          paddedRowPixels = iVar19 + 7U & 0xfffffff8;
          uVar13 = uVar31 + iVar28;
          iVar23 = uVar29 + paddedRowPixels * ((iVar26 - uVar31) + -1);
          if (*(char *)(glContext + 0x141) == '\x01') {
            if (value == (double)FLOAT_001aa0e8) {
              if (uVar31 < uVar13) {
                iVar34 = *(int *)(glContext + 0x148);
                iVar36 = 0;
                do {
                  pbVar35 = (byte *)(iVar23 * 4 + iVar34);
                  readbackHalfCursor = (ushort *)((int)readbackPixels + iVar23 * 2);
                  pbVar32 = pbVar35 + uVar20 * 4;
                  if (cVar14 == '\0') {
                    for (; pbVar35 < pbVar32; pbVar35 = pbVar35 + 4) {
                      *readbackHalfCursor = ((short)(char)pbVar35[3] & 0x40U) << 9 | (*pbVar35 & 0x7c) << 8 |
                                 (pbVar35[1] & 0x7c) << 3 | pbVar35[2] >> 2 & 0x1f;
                      readbackHalfCursor = readbackHalfCursor + 1;
                    }
                  }
                  else {
                    for (; pbVar35 < pbVar32; pbVar35 = pbVar35 + 4) {
                      iVar40 = 0;
                      if (-1 < (char)*pbVar35) {
                        iVar40 = (int)(char)*pbVar35;
                      }
                      iVar15 = 0;
                      if (-1 < (char)pbVar35[1]) {
                        iVar15 = (int)(char)pbVar35[1];
                      }
                      uVar27 = 0;
                      if (-1 < (char)pbVar35[2]) {
                        uVar27 = (ushort)((int)(char)pbVar35[2] >> 2);
                      }
                      iVar16 = 0;
                      if (-1 < (char)pbVar35[3]) {
                        iVar16 = (int)(char)pbVar35[3];
                      }
                      *readbackHalfCursor = (ushort)(iVar16 << 9) & 0x8000 | (ushort)(iVar40 << 8) & 0x7c00 |
                                 (ushort)(iVar15 << 3) & 0x3e0 | uVar27 & 0x1f;
                      readbackHalfCursor = readbackHalfCursor + 1;
                    }
                  }
                  iVar36 = iVar36 + 1;
                  iVar23 = iVar23 - paddedRowPixels;
                } while (uVar13 - uVar31 != iVar36);
              }
            }
            else {
              fVar2 = (float)(value * (double)FLOAT_001aa0dc);
              if (uVar31 < uVar13) {
                iVar34 = *(int *)(glContext + 0x148);
                iVar36 = 0;
                do {
                  dVar51 = DOUBLE_001aa1e0;
                  fVar12 = FLOAT_001aa0ec;
                  fVar11 = FLOAT_001aa0d4;
                  accumByteCursor = (char *)(iVar23 * 4 + iVar34);
                  readbackHalfCursor = (ushort *)((int)readbackPixels + iVar23 * 2);
                  iVar40 = uVar44 - uVar29;
                  if (uVar29 < uVar44) {
                    do {
                      fVar5 = fVar2 * (float)((double)CONCAT44(0x43300000,(int)*accumByteCursor ^ 0x80000000
                                                              ) - dVar51);
                      fVar9 = FLOAT_001aa0d4;
                      if (fVar11 <= fVar5) {
                        fVar9 = fVar5 * fVar12;
                      }
                      fVar5 = fVar2 * (float)((double)CONCAT44(0x43300000,
                                                               (int)accumByteCursor[1] ^ 0x80000000) -
                                             dVar51);
                      fVar7 = FLOAT_001aa0d4;
                      if (FLOAT_001aa0d4 <= fVar5) {
                        fVar7 = fVar5 * fVar12;
                      }
                      fVar5 = fVar2 * (float)((double)CONCAT44(0x43300000,
                                                               (int)accumByteCursor[2] ^ 0x80000000) -
                                             dVar51);
                      fVar8 = FLOAT_001aa0d4;
                      if (FLOAT_001aa0d4 <= fVar5) {
                        fVar8 = fVar5 * fVar12;
                      }
                      fVar5 = fVar2 * (float)((double)CONCAT44(0x43300000,
                                                               (int)accumByteCursor[3] ^ 0x80000000) -
                                             dVar51);
                      fVar6 = FLOAT_001aa0d4;
                      if (FLOAT_001aa0d4 <= fVar5) {
                        fVar6 = fVar5 * fVar1;
                      }
                      accumByteCursor = accumByteCursor + 4;
                      *readbackHalfCursor = (ushort)(int)fVar8 |
                                 (ushort)((int)fVar6 << 0xf) | (ushort)((int)fVar9 << 10) |
                                 (ushort)((int)fVar7 << 5);
                      readbackHalfCursor = readbackHalfCursor + 1;
                      iVar40 = iVar40 + -1;
                    } while (iVar40 != 0);
                  }
                  iVar36 = iVar36 + 1;
                  iVar23 = iVar23 - paddedRowPixels;
                } while (uVar13 - uVar31 != iVar36);
              }
            }
          }
          else if (value == (double)FLOAT_001aa0e8) {
            if (uVar31 < uVar13) {
              iVar34 = *(int *)(glContext + 0x148);
              iVar36 = 0;
              do {
                readbackHalfCursor = (ushort *)(iVar23 * 8 + iVar34);
                puVar33 = (ushort *)((int)readbackPixels + iVar23 * 2);
                puVar48 = readbackHalfCursor + uVar20 * 4;
                if (cVar14 == '\0') {
                  for (; readbackHalfCursor < puVar48; readbackHalfCursor = readbackHalfCursor + 4) {
                    *puVar33 = (readbackHalfCursor[3] & 0x4000) << 1 | *readbackHalfCursor & 0x7c00 |
                               (ushort)((uint)(int)(short)readbackHalfCursor[1] >> 5) & 0x3e0 |
                               (ushort)((uint)(int)(short)readbackHalfCursor[2] >> 10) & 0x1f;
                    puVar33 = puVar33 + 1;
                  }
                }
                else {
                  for (; readbackHalfCursor < puVar48; readbackHalfCursor = readbackHalfCursor + 4) {
                    uVar27 = 0;
                    if (-1 < (short)*readbackHalfCursor) {
                      uVar27 = *readbackHalfCursor & 0x7c00;
                    }
                    uVar41 = 0;
                    if (-1 < (short)readbackHalfCursor[1]) {
                      uVar41 = (short)readbackHalfCursor[1] >> 5;
                    }
                    uVar21 = 0;
                    if (-1 < (short)readbackHalfCursor[2]) {
                      uVar21 = (short)readbackHalfCursor[2] >> 10;
                    }
                    iVar40 = 0;
                    if (-1 < (short)readbackHalfCursor[3]) {
                      iVar40 = (int)(short)readbackHalfCursor[3];
                    }
                    *puVar33 = uVar27 | (ushort)(iVar40 << 1) & 0x8000 | uVar41 & 0x3e0 |
                               uVar21 & 0x1f;
                    puVar33 = puVar33 + 1;
                  }
                }
                iVar36 = iVar36 + 1;
                iVar23 = iVar23 - paddedRowPixels;
              } while (uVar13 - uVar31 != iVar36);
            }
          }
          else {
            fVar2 = (float)(value * (double)FLOAT_001aa0e4);
            if (uVar31 < uVar13) {
              iVar34 = *(int *)(glContext + 0x148);
              iVar36 = 0;
              do {
                dVar51 = DOUBLE_001aa1e0;
                fVar12 = FLOAT_001aa0ec;
                fVar11 = FLOAT_001aa0d4;
                accumShortCursor = (short *)(iVar23 * 8 + iVar34);
                readbackHalfCursor = (ushort *)((int)readbackPixels + iVar23 * 2);
                iVar40 = uVar44 - uVar29;
                if (uVar29 < uVar44) {
                  do {
                    fVar5 = fVar2 * (float)((double)CONCAT44(0x43300000,(int)*accumShortCursor ^ 0x80000000)
                                           - dVar51);
                    fVar9 = FLOAT_001aa0d4;
                    if (fVar11 <= fVar5) {
                      fVar9 = fVar5 * fVar12;
                    }
                    fVar5 = fVar2 * (float)((double)CONCAT44(0x43300000,(int)accumShortCursor[1] ^ 0x80000000
                                                            ) - dVar51);
                    fVar7 = FLOAT_001aa0d4;
                    if (FLOAT_001aa0d4 <= fVar5) {
                      fVar7 = fVar5 * fVar12;
                    }
                    fVar5 = fVar2 * (float)((double)CONCAT44(0x43300000,(int)accumShortCursor[2] ^ 0x80000000
                                                            ) - dVar51);
                    fVar8 = FLOAT_001aa0d4;
                    if (FLOAT_001aa0d4 <= fVar5) {
                      fVar8 = fVar5 * fVar12;
                    }
                    fVar5 = fVar2 * (float)((double)CONCAT44(0x43300000,(int)accumShortCursor[3] ^ 0x80000000
                                                            ) - dVar51);
                    fVar6 = FLOAT_001aa0d4;
                    if (FLOAT_001aa0d4 <= fVar5) {
                      fVar6 = fVar5 * fVar1;
                    }
                    accumShortCursor = accumShortCursor + 4;
                    *readbackHalfCursor = (ushort)(int)fVar8 |
                               (ushort)((int)fVar6 << 0xf) | (ushort)((int)fVar9 << 10) |
                               (ushort)((int)fVar7 << 5);
                    readbackHalfCursor = readbackHalfCursor + 1;
                    iVar40 = iVar40 + -1;
                  } while (iVar40 != 0);
                }
                iVar36 = iVar36 + 1;
                iVar23 = iVar23 - paddedRowPixels;
              } while (uVar13 - uVar31 != iVar36);
            }
          }
          FUN_000198b0(glContext,uVar29,uVar31,uVar20,iVar28,0x8366,
                       (void *)((int)readbackPixels +
                               (((iVar26 - uVar31) - iVar28) * (iVar19 + 7U & 0xfffffff8) + uVar29)
                               * 2));
          goto code_r0x00003264;
        }
      }
    }
    break;
  case 0x103:
    iVar19 = *(int *)(glContext + 0x10);
    if (((unsigned char *)0x00003190)[iVar19] == '\0') {
      iVar23 = *(int *)(glContext + 0x15c);
      iVar19 = *(int *)(glContext + 0x160);
      iVar34 = 0;
      iVar36 = 0;
      uVar20 = iVar23 + 7U & 0xfffffff8;
      iVar26 = iVar19;
    }
    else {
      iVar34 = *(int *)(((unsigned char *)0x00003180) + iVar19);
      iVar26 = *(int *)(glContext + 0x160);
      uVar20 = iVar34 + *(int *)(((unsigned char *)0x00003188) + iVar19);
      iVar36 = iVar26 - (*(int *)(((unsigned char *)0x0000318c) + iVar19) + *(int *)(((unsigned char *)0x00003184) + iVar19));
      iVar40 = *(int *)(((unsigned char *)0x0000318c) + iVar19) + iVar36;
      if (iVar34 < 0) {
        iVar34 = 0;
      }
      if (iVar36 < 0) {
        iVar36 = 0;
      }
      iVar23 = *(int *)(glContext + 0x15c);
      uVar29 = iVar23 + 7U & 0xfffffff8;
      if ((int)uVar29 < (int)uVar20) {
        uVar20 = uVar29;
      }
      iVar19 = iVar26;
      if (iVar40 <= iVar26) {
        iVar19 = iVar40;
      }
      uVar20 = uVar20 - iVar34;
      iVar19 = iVar19 - iVar36;
    }
    if ((int)uVar20 < 1) {
      return;
    }
    if (iVar19 < 1) {
      return;
    }
    iVar40 = uVar20 * 4;
    iVar19 = iVar36 + iVar19;
    dVar51 = (double)FLOAT_001aa0d4;
    if (value < dVar51) {
      *(undefined1 *)(glContext + 0x140) = 1;
    }
    uVar29 = iVar23 + 7U & 0xfffffff8;
    iVar34 = iVar34 + uVar29 * ((iVar26 - iVar36) + -1);
    if (value != dVar51) {
      fVar1 = (float)((double)FLOAT_001aa0e8 / value);
      if ((((fVar1 == FLOAT_001aa0f8) || (fVar1 == FLOAT_001aa0fc)) || (fVar1 == FLOAT_001aa100)) ||
         ((fVar1 == FLOAT_001aa104 || (fVar1 == FLOAT_001aa108)))) {
        iVar26 = (int)((double)FLOAT_001aa0e8 / value);
        iVar23 = 2;
        if (iVar26 != 4) {
          if (iVar26 < 5) {
            iVar23 = 1;
            if (iVar26 == 2) goto code_r0x00004f90;
          }
          else {
            iVar23 = 3;
            if ((iVar26 == 8) || (iVar23 = 4, iVar26 == 0x10)) goto code_r0x00004f90;
          }
          iVar23 = 5;
        }
code_r0x00004f90:
        if (*(char *)(glContext + 0x141) == '\x01') {
          if (iVar19 <= iVar36) {
            return;
          }
          iVar26 = 0;
          while( true ) {
            accumByteCursor = (char *)(iVar34 * 4 + iVar28);
            accumByteEnd = accumByteCursor + iVar40;
            for (; accumByteCursor < accumByteEnd; accumByteCursor = accumByteCursor + 4) {
              *accumByteCursor = (char)((int)*accumByteCursor >> iVar23);
              accumByteCursor[1] = (char)((int)accumByteCursor[1] >> iVar23);
              accumByteCursor[2] = (char)((int)accumByteCursor[2] >> iVar23);
              accumByteCursor[3] = (char)((int)accumByteCursor[3] >> iVar23);
            }
            iVar26 = iVar26 + 1;
            iVar34 = iVar34 - uVar29;
            if (iVar26 == iVar19 - iVar36) break;
            iVar28 = *(int *)(glContext + 0x148);
          }
          return;
        }
        if (iVar19 <= iVar36) {
          return;
        }
        iVar26 = 0;
        while( true ) {
          accumShortCursor = (short *)(iVar34 * 8 + iVar28);
          accumShortEnd = accumShortCursor + uVar20 * 4;
          for (; accumShortCursor < accumShortEnd; accumShortCursor = accumShortCursor + 4) {
            *accumShortCursor = (short)((int)*accumShortCursor >> iVar23);
            accumShortCursor[1] = (short)((int)accumShortCursor[1] >> iVar23);
            accumShortCursor[2] = (short)((int)accumShortCursor[2] >> iVar23);
            accumShortCursor[3] = (short)((int)accumShortCursor[3] >> iVar23);
          }
          iVar26 = iVar26 + 1;
          iVar34 = iVar34 - uVar29;
          if (iVar26 == iVar19 - iVar36) break;
          iVar28 = *(int *)(glContext + 0x148);
        }
        return;
      }
    }
    if ((((value != (double)FLOAT_001aa0f8) && (value != (double)FLOAT_001aa0fc)) &&
        (value != (double)FLOAT_001aa100)) &&
       ((value != (double)FLOAT_001aa104 && (value != (double)FLOAT_001aa108)))) {
      if (*(char *)(glContext + 0x141) == '\x01') {
        if (iVar19 <= iVar36) {
          return;
        }
        iVar26 = 0;
        while( true ) {
          dVar51 = DOUBLE_001aa1e0;
          accumByteCursor = (char *)(iVar34 * 4 + iVar28);
          accumByteEnd = accumByteCursor + iVar40;
          for (; accumByteCursor < accumByteEnd; accumByteCursor = accumByteCursor + 4) {
            *accumByteCursor = (char)(int)(value *
                                  (double)(float)((double)CONCAT44(0x43300000,
                                                                   (int)*accumByteCursor ^ 0x80000000) -
                                                 dVar51));
            accumByteCursor[1] = (char)(int)(value *
                                    (double)(float)((double)CONCAT44(0x43300000,
                                                                     (int)accumByteCursor[1] ^ 0x80000000) -
                                                   dVar51));
            accumByteCursor[2] = (char)(int)(value *
                                    (double)(float)((double)CONCAT44(0x43300000,
                                                                     (int)accumByteCursor[2] ^ 0x80000000) -
                                                   dVar51));
            accumByteCursor[3] = (char)(int)(value *
                                    (double)(float)((double)CONCAT44(0x43300000,
                                                                     (int)accumByteCursor[3] ^ 0x80000000) -
                                                   dVar51));
          }
          iVar26 = iVar26 + 1;
          iVar34 = iVar34 - uVar29;
          if (iVar26 == iVar19 - iVar36) break;
          iVar28 = *(int *)(glContext + 0x148);
        }
        return;
      }
      if (iVar19 <= iVar36) {
        return;
      }
      iVar26 = 0;
      while( true ) {
        dVar51 = DOUBLE_001aa1e0;
        accumShortCursor = (short *)(iVar34 * 8 + iVar28);
        accumShortEnd = accumShortCursor + uVar20 * 4;
        for (; accumShortCursor < accumShortEnd; accumShortCursor = accumShortCursor + 4) {
          *accumShortCursor = (short)(int)(value *
                                 (double)(float)((double)CONCAT44(0x43300000,
                                                                  (int)*accumShortCursor ^ 0x80000000) -
                                                dVar51));
          accumShortCursor[1] = (short)(int)(value *
                                   (double)(float)((double)CONCAT44(0x43300000,
                                                                    (int)accumShortCursor[1] ^ 0x80000000) -
                                                  dVar51));
          accumShortCursor[2] = (short)(int)(value *
                                   (double)(float)((double)CONCAT44(0x43300000,
                                                                    (int)accumShortCursor[2] ^ 0x80000000) -
                                                  dVar51));
          accumShortCursor[3] = (short)(int)(value *
                                   (double)(float)((double)CONCAT44(0x43300000,
                                                                    (int)accumShortCursor[3] ^ 0x80000000) -
                                                  dVar51));
        }
        iVar26 = iVar26 + 1;
        iVar34 = iVar34 - uVar29;
        if (iVar26 == iVar19 - iVar36) break;
        iVar28 = *(int *)(glContext + 0x148);
      }
      return;
    }
    iVar26 = (int)value;
    iVar23 = 2;
    if (iVar26 != 4) {
      if (iVar26 < 5) {
        iVar23 = 1;
        if (iVar26 != 2) {
code_r0x0000510c:
          iVar23 = 5;
        }
      }
      else {
        iVar23 = 3;
        if ((iVar26 != 8) && (iVar23 = 4, iVar26 != 0x10)) goto code_r0x0000510c;
      }
    }
    if (*(char *)(glContext + 0x141) == '\x01') {
      if (iVar36 < iVar19) {
        iVar26 = 0;
        while( true ) {
          accumByteCursor = (char *)(iVar34 * 4 + iVar28);
          accumByteEnd = accumByteCursor + iVar40;
          for (; accumByteCursor < accumByteEnd; accumByteCursor = accumByteCursor + 4) {
            *accumByteCursor = *accumByteCursor << iVar23;
            accumByteCursor[1] = accumByteCursor[1] << iVar23;
            accumByteCursor[2] = accumByteCursor[2] << iVar23;
            accumByteCursor[3] = accumByteCursor[3] << iVar23;
          }
          iVar26 = iVar26 + 1;
          iVar34 = iVar34 - uVar29;
          if (iVar26 == iVar19 - iVar36) break;
          iVar28 = *(int *)(glContext + 0x148);
        }
      }
    }
    else if (iVar36 < iVar19) {
      iVar26 = 0;
      while( true ) {
        accumShortCursor = (short *)(iVar34 * 8 + iVar28);
        accumShortEnd = accumShortCursor + uVar20 * 4;
        for (; accumShortCursor < accumShortEnd; accumShortCursor = accumShortCursor + 4) {
          *accumShortCursor = (short)((int)*accumShortCursor << iVar23);
          accumShortCursor[1] = (short)((int)accumShortCursor[1] << iVar23);
          accumShortCursor[2] = (short)((int)accumShortCursor[2] << iVar23);
          accumShortCursor[3] = (short)((int)accumShortCursor[3] << iVar23);
        }
        iVar26 = iVar26 + 1;
        iVar34 = iVar34 - uVar29;
        if (iVar26 == iVar19 - iVar36) break;
        iVar28 = *(int *)(glContext + 0x148);
      }
    }
    break;
  case 0x104:
    iVar19 = *(int *)(glContext + 0x10);
    if (((unsigned char *)0x00003190)[iVar19] == '\0') {
      iVar23 = *(int *)(glContext + 0x15c);
      iVar19 = *(int *)(glContext + 0x160);
      iVar34 = 0;
      iVar36 = 0;
      uVar20 = iVar23 + 7U & 0xfffffff8;
      iVar26 = iVar19;
    }
    else {
      iVar34 = *(int *)(((unsigned char *)0x00003180) + iVar19);
      iVar26 = *(int *)(glContext + 0x160);
      uVar20 = iVar34 + *(int *)(((unsigned char *)0x00003188) + iVar19);
      iVar36 = iVar26 - (*(int *)(((unsigned char *)0x0000318c) + iVar19) + *(int *)(((unsigned char *)0x00003184) + iVar19));
      iVar40 = *(int *)(((unsigned char *)0x0000318c) + iVar19) + iVar36;
      if (iVar34 < 0) {
        iVar34 = 0;
      }
      if (iVar36 < 0) {
        iVar36 = 0;
      }
      iVar23 = *(int *)(glContext + 0x15c);
      uVar29 = iVar23 + 7U & 0xfffffff8;
      if ((int)uVar29 < (int)uVar20) {
        uVar20 = uVar29;
      }
      iVar19 = iVar26;
      if (iVar40 <= iVar26) {
        iVar19 = iVar40;
      }
      uVar20 = uVar20 - iVar34;
      iVar19 = iVar19 - iVar36;
    }
    if ((0 < (int)uVar20) && (0 < iVar19)) {
      iVar19 = iVar36 + iVar19;
      if (value < (double)FLOAT_001aa0d4) {
        *(undefined1 *)(glContext + 0x140) = 1;
      }
      uVar29 = iVar23 + 7U & 0xfffffff8;
      iVar34 = iVar34 + uVar29 * ((iVar26 - iVar36) + -1);
      if (*(char *)(glContext + 0x141) == '\x01') {
        cVar14 = (char)(int)(value * (double)FLOAT_001aa0f4);
        if (iVar36 < iVar19) {
          iVar26 = 0;
          while( true ) {
            accumByteCursor = (char *)(iVar34 * 4 + iVar28);
            accumByteEnd = accumByteCursor + uVar20 * 4;
            for (; accumByteCursor < accumByteEnd; accumByteCursor = accumByteCursor + 4) {
              *accumByteCursor = cVar14 + *accumByteCursor;
              accumByteCursor[1] = cVar14 + accumByteCursor[1];
              accumByteCursor[2] = cVar14 + accumByteCursor[2];
              accumByteCursor[3] = cVar14 + accumByteCursor[3];
            }
            iVar26 = iVar26 + 1;
            iVar34 = iVar34 - uVar29;
            if (iVar26 == iVar19 - iVar36) break;
            iVar28 = *(int *)(glContext + 0x148);
          }
        }
      }
      else {
        sStack_da = (short)(int)(value * (double)FLOAT_001aa0d8);
        if (iVar36 < iVar19) {
          iVar26 = 0;
          while( true ) {
            accumShortCursor = (short *)(iVar34 * 8 + iVar28);
            accumShortEnd = accumShortCursor + uVar20 * 4;
            for (; accumShortCursor < accumShortEnd; accumShortCursor = accumShortCursor + 4) {
              *accumShortCursor = sStack_da + *accumShortCursor;
              accumShortCursor[1] = sStack_da + accumShortCursor[1];
              accumShortCursor[2] = sStack_da + accumShortCursor[2];
              accumShortCursor[3] = sStack_da + accumShortCursor[3];
            }
            iVar26 = iVar26 + 1;
            iVar34 = iVar34 - uVar29;
            if (iVar26 == iVar19 - iVar36) break;
            iVar28 = *(int *)(glContext + 0x148);
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
      connectionOrError = FUN_00017310(ctx,pname,values);
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
       (status = FUN_00032100(ctx,texture,values,extraArg3,extraArg4,extraArg5), status == 0)) {
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

/* FUN_00005db0 @ 0x5db0 (244 bytes) */
int FUN_00005db0(ctx, buffer)
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
      retired = FUN_0001a0d0(ctx,*(undefined4 *)(pluginRecord + 8));
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
      retired = FUN_0001a0d0(ctx,*(undefined4 *)(pluginRecord + 0xc));
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
      retired = FUN_0001a0d0(ctx,*(undefined4 *)(pluginRecord + 8));
      return retired;
    }
    if (*(char *)(pluginRecord + 0x16) == '\a') {
      if (0x1ffff < *(int *)(pluginRecord + 0x10)) {
        _gldFlush(ctx);
      }
      retired = FUN_0001a0d0(ctx,*(undefined4 *)(pluginRecord + 0xc));
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
      FUN_0000b620(ctx,flushRegion,flushArg4,flushArg4,flushArg5,flushArg6,flushArg7,flushArg8);
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
    busy = FUN_0001a0d0(ctx,*(undefined4 *)(pluginRecord + 8));
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
    busy = FUN_0001a0d0(ctx,*(undefined4 *)(pluginRecord + 0xc));
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
        isComplete = FUN_0001a0d0(ctx,*(undefined4 *)(pluginRecord + 8));
        return isComplete;
      }
    }
    else {
      if (*(char *)(pluginRecord + 0x16) != '\a') goto LAB_00006230;
      if (*(int *)(pluginRecord + 0x10) < 0x20000) {
        isComplete = FUN_0001a0d0(ctx,*(undefined4 *)(pluginRecord + 0xc));
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
      ((int (*)())FUN_00005db0)(ctx,buffer);
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

/* FUN_00006470 @ 0x6470 (312 bytes) */
int FUN_00006470(param_1, param_2, param_3, param_4, param_5)
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

/* FUN_000065b0 @ 0x65b0 (328 bytes) */
int FUN_000065b0(param_1, param_2, param_3, param_4, param_5, param_6)
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
                FUN_00017750(ctx,stateBlock,pixelFormat);
                _memcpy(ctx + GLD_stateCopy / 4,stateBlock + 0x24,0x3c);
                FUN_0002c790(ctx,pixelFormat);
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
    FUN_0002cb40(ctx);
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
asm(".set FUN_00002ae0, _FUN_00002ae0");
