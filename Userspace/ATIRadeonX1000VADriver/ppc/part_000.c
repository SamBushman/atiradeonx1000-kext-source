#include "decls.h"

/* dyld_stub_binding_helper @ 0x1070 (48 bytes) */
int dyld_stub_binding_helper()
{
                    
                    
  (*dyldStubBindingHelperPtr_0000f0c4)();
  return;
}

/* __dyld_func_lookup @ 0x10a0 (32 bytes) */
int __dyld_func_lookup()
{
                    
                    
  (*dyldFuncLookupPtr_0000f0c8)();
  return;
}

/* _cxa_atexit_check_2 @ 0x10c0 (40 bytes) */
int _cxa_atexit_check_2(state)
  undefined4 *state;
{
  *state = 1;
  return;
}

/* _cxa_atexit_check_1 @ 0x10e8 (120 bytes) */
int _cxa_atexit_check_1(state)
  undefined4 *state;
{
  int status;
  undefined4 *stateHome;
  
  stateHome = state;
  status = (*(code *)state[1])(_cxa_atexit_check_2,state,state);
  if (status != 0) {
    *state = 0xffffffff;
  }
  return;
}

/* _check_cxa_atexit @ 0x1160 (204 bytes) */
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
  status = (*cxaAtexitFn)(_cxa_atexit_check_1,&state,&state);
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

/* _find_atexit_10_3 @ 0x122c (504 bytes) */
int _find_atexit_10_3()
{
  undefined4 scratchResult;
  uint imageCount;
  int headerOrSymbol;
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
  scratchResult = ((int (*)())__dyld_func_lookup)("__dyld_NSAddressOfSymbol",addressOfSymbolFn);
  if ((((imageCountFn != (code *)0x0) && (imageNameFn != (code *)0x0)) && (imageHeaderFn != (code *)0x0)) &&
     ((lookupSymbolFn != (code *)0x0 && (addressOfSymbolFn[0] != (code *)0x0)))) {
    imageCount = (*imageCountFn)(scratchResult);
    for (imageIndex = 0; imageIndex < imageCount; imageIndex = imageIndex + 1) {
      scratchResult = (*imageNameFn)(imageIndex);
      headerOrSymbol = _strcmp(scratchResult,"/usr/lib/libSystem.B.dylib");
      if (headerOrSymbol == 0) {
        headerOrSymbol = (*imageHeaderFn)(imageIndex);
        if (headerOrSymbol == 0) {
          return 0;
        }
        headerOrSymbol = (*lookupSymbolFn)(headerOrSymbol,"_atexit",4);
        if (headerOrSymbol != 0) {
          scratchResult = (*addressOfSymbolFn[0])(headerOrSymbol);
          return scratchResult;
        }
        return 0;
      }
    }
  }
  return 0;
}

/* pic_jump_strcmp_1424 @ 0x1424 (32 bytes) */
int pic_jump_strcmp_1424(s1, s2)
  char *s1;
  char *s2;
{
  _strcmp(s1,s2);
  return;
}

/* pic_jump_dyld_func_lookup_1444 @ 0x1444 (32 bytes) */
int pic_jump_dyld_func_lookup_1444()
{
                    
                    
  (*dyldFuncLookupPtr_0000f0c8)();
  return;
}

/* _get_globals @ 0x1464 (528 bytes) */
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
         (libSystemHandle = (**(code **)(globals + 0x10))(_our_atexit), libSystemHandle == 0)) goto setResult;
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
          if (*(int *)(globals + 0x10) == 0) goto callKeymgrSetAndUnlockProcesswidePtr;
          *(undefined1 *)(globals + 3) = 0x10;
        }
        goto setResult;
      }
    }
callKeymgrSetAndUnlockProcesswidePtr:
    __keymgr_set_and_unlock_processwide_ptr(0xe,globals);
    result = 0;
  }
  else {
setResult:
    result = globals;
  }
  return result;
}

/* pic_jump_keymgr_set_and_unlock_processwide_ptr_1674 @ 0x1674 (32 bytes) */
int pic_jump_keymgr_set_and_unlock_processwide_ptr_1674()
{
  __keymgr_set_and_unlock_processwide_ptr();
  return;
}

/* pic_jump_check_cxa_atexit_1694 @ 0x1694 (32 bytes) */
int pic_jump_check_cxa_atexit_1694(cxaAtexitFn, cxaFinalizeFn)
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
  status = (*cxaAtexitFn)(_cxa_atexit_check_1,&state,&state);
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

/* pic_jump_dlsym_16b4 @ 0x16b4 (32 bytes) */
int pic_jump_dlsym_16b4()
{
                    
                    
  (*(code *)lazyPtrTo_dlsym_0000f0e0)();
  return;
}

/* pic_jump_find_atexit_10_3_16d4 @ 0x16d4 (32 bytes) */
int pic_jump_find_atexit_10_3_16d4()
{
  uint imageCount;
  char *imageName;
  int headerOrSymbol;
  undefined4 atexitAddress;
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
  ((int (*)())__dyld_func_lookup)("__dyld_NSAddressOfSymbol",addressOfSymbolFn);
  if ((((imageCountFn != (code *)0x0) && (imageNameFn != (code *)0x0)) && (imageHeaderFn != (code *)0x0))
     && ((lookupSymbolFn != (code *)0x0 && (addressOfSymbolFn[0] != (code *)0x0)))) {
    imageCount = (*imageCountFn)();
    for (imageIndex = 0; imageIndex < imageCount; imageIndex = imageIndex + 1) {
      imageName = (char *)(*imageNameFn)(imageIndex);
      headerOrSymbol = _strcmp(imageName,"/usr/lib/libSystem.B.dylib");
      if (headerOrSymbol == 0) {
        headerOrSymbol = (*imageHeaderFn)(imageIndex);
        if (headerOrSymbol == 0) {
          return 0;
        }
        headerOrSymbol = (*lookupSymbolFn)(headerOrSymbol,"_atexit",4);
        if (headerOrSymbol != 0) {
          atexitAddress = (*addressOfSymbolFn[0])(headerOrSymbol);
          return atexitAddress;
        }
        return 0;
      }
    }
  }
  return 0;
}

/* pic_jump_dlopen_16f4 @ 0x16f4 (32 bytes) */
int pic_jump_dlopen_16f4()
{
                    
                    
  (*(code *)lazyPtrTo_dlopen_0000f0cc)();
  return;
}

/* pic_jump_calloc_1714 @ 0x1714 (32 bytes) */
int pic_jump_calloc_1714()
{
                    
                    
  (*(code *)lazyPtrTo_calloc_0000f0e4)();
  return;
}

/* pic_jump_keymgr_get_and_lock_processwide_ptr_1734 @ 0x1734 (32 bytes) */
int pic_jump_keymgr_get_and_lock_processwide_ptr_1734()
{
                    
                    
  (*(code *)lazyPtrTo_keymgrGetAndLockProcesswidePtr_0000f0d4)();
  return;
}

/* _add_routine @ 0x1754 (268 bytes) */
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
    if ((*(ushort *)(*(int *)(ptrTo_keymgrGlobal_0000f124 + 8) + 4) < 4) || (unlockResult == 0)) {
      status = 0;
    }
    else {
      status = 0xffffffff;
    }
    result = status;
  }
  return result;
}

/* pic_jump_keymgr_set_and_unlock_processwide_ptr_1860 @ 0x1860 (32 bytes) */
int pic_jump_keymgr_set_and_unlock_processwide_ptr_1860()
{
  __keymgr_set_and_unlock_processwide_ptr();
  return;
}

/* pic_jump_malloc_1880 @ 0x1880 (32 bytes) */
int pic_jump_malloc_1880()
{
                    
                    
  (*(code *)lazyPtrTo_malloc_0000f0d0)();
  return;
}

/* _run_routines @ 0x18a0 (292 bytes) */
int _run_routines(globals, stopNode)
  int globals;
  undefined4 *stopNode;
{
  undefined4 *node;
  uint kindMask;
  undefined4 unlockResult;
  undefined4 a1;
  undefined4 passThroughR5;
  undefined4 passThroughR6;
  undefined4 passThroughR7;
  undefined4 passThroughR8;
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
          (*(code *)node[1])(node[3],a1,passThroughR5,passThroughR6,passThroughR7,passThroughR8,(code *)node[1]);
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

/* pic_jump_keymgr_get_and_lock_processwide_ptr_19c4 @ 0x19c4 (32 bytes) */
int pic_jump_keymgr_get_and_lock_processwide_ptr_19c4()
{
  __keymgr_get_and_lock_processwide_ptr();
  return;
}

/* pic_jump_free_19e4 @ 0x19e4 (32 bytes) */
int pic_jump_free_19e4()
{
                    
                    
  (*(code *)lazyPtrTo_free_0000f0d8)();
  return;
}

/* pic_jump_keymgr_set_and_unlock_processwide_ptr_1a04 @ 0x1a04 (32 bytes) */
int pic_jump_keymgr_set_and_unlock_processwide_ptr_1a04()
{
                    
                    
  (*(code *)lazyPtrTo_keymgrSetAndUnlockProcesswidePtr_0000f0dc)();
  return;
}

/* _cxa_atexit_wrapper @ 0x1a24 (312 bytes) */
int _cxa_atexit_wrapper(entry)
  undefined4 *entry;
{
  undefined4 a0;
  undefined4 r4AfterLock;
  undefined4 r4AfterUnlock;
  undefined4 a1;
  undefined4 passThroughR5;
  undefined4 passThroughR6;
  undefined4 passThroughR7;
  undefined4 passThroughR8;
  undefined4 *entryHome;
  undefined1 savedRunning;
  undefined4 savedList;
  int globals;
  
  savedList = 0;
  savedRunning = 0;
  entryHome = entry;
  globals = __keymgr_get_and_lock_processwide_ptr(0xe);
  a0 = 0;
  a1 = r4AfterLock;
  if (globals != 0) {
    savedRunning = *(undefined1 *)(globals + 2);
    *(undefined1 *)(globals + 2) = 1;
    savedList = *(undefined4 *)(globals + 4);
    a0 = __keymgr_set_and_unlock_processwide_ptr(0xe,globals);
    a1 = r4AfterUnlock;
  }
  if (entry[1] == 0) {
    (*(code *)*entry)(a0);
  }
  else {
    (*(code *)*entry)(entry[2],a1,passThroughR5,passThroughR6,passThroughR7,passThroughR8,(code *)*entry);
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

/* pic_jump_run_routines_1b5c @ 0x1b5c (32 bytes) */
int pic_jump_run_routines_1b5c(globals, stopNode)
  undefined4 globals;
  undefined4 stopNode;
{
  ((int (*)())_run_routines)(globals,stopNode);
  return;
}

/* pic_jump_keymgr_set_and_unlock_processwide_ptr_1b7c @ 0x1b7c (32 bytes) */
int pic_jump_keymgr_set_and_unlock_processwide_ptr_1b7c()
{
                    
                    
  (*(code *)lazyPtrTo_keymgrSetAndUnlockProcesswidePtr_0000f0dc)();
  return;
}

/* pic_jump_keymgr_get_and_lock_processwide_ptr_1b9c @ 0x1b9c (32 bytes) */
int pic_jump_keymgr_get_and_lock_processwide_ptr_1b9c()
{
                    
                    
  (*(code *)lazyPtrTo_keymgrGetAndLockProcesswidePtr_0000f0d4)();
  return;
}

/* _our_atexit @ 0x1bbc (188 bytes) */
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

/* pic_jump_keymgr_set_and_unlock_processwide_ptr_1c78 @ 0x1c78 (32 bytes) */
int pic_jump_keymgr_set_and_unlock_processwide_ptr_1c78()
{
  __keymgr_set_and_unlock_processwide_ptr();
  return;
}

/* pic_jump_run_routines_1c98 @ 0x1c98 (32 bytes) */
int pic_jump_run_routines_1c98(globals, stopNode)
  int globals;
  undefined4 *stopNode;
{
  undefined4 *node;
  uint kindMask;
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
    __keymgr_set_and_unlock_processwide_ptr(0xe,globalsHome);
    if ((uint)node[2] < 6) {
      kindMask = 1 << (node[2] & 0x3f);
      if ((kindMask & 0x15) == 0) {
        if ((kindMask & 0x2a) != 0) {
          (*(code *)node[1])(node[3]);
        }
      }
      else {
        (*(code *)node[1])();
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

/* pic_jump_keymgr_get_and_lock_processwide_ptr_1cb8 @ 0x1cb8 (32 bytes) */
int pic_jump_keymgr_get_and_lock_processwide_ptr_1cb8()
{
                    
                    
  (*(code *)lazyPtrTo_keymgrGetAndLockProcesswidePtr_0000f0d4)();
  return;
}

/* _atexit_common @ 0x1cd8 (672 bytes) */
int _atexit_common(atexit_entry, dsoHandle)
  undefined4 *atexit_entry;
  undefined4 dsoHandle;
{
  code *registerFn;
  undefined4 word2;
  int atexit_globals;
  undefined4 *entryCopy;
  undefined4 passThroughR6;
  undefined4 passThroughR7;
  undefined4 passThroughR8;
  undefined4 word1;
  undefined4 *entryHome;
  undefined4 dsoHandleHome;
  undefined4 result;
  
  entryHome = atexit_entry;
  dsoHandleHome = dsoHandle;
  atexit_globals = ((int (*)())_get_globals)();
  if (atexit_globals == 0) {
    result = 0xffffffff;
  }
  else if ((*(char *)(atexit_globals + 2) == '\0') && (*(char *)(atexit_globals + 3) != '\x01')) {
    if (*(byte *)(atexit_globals + 3) < 0x10) {
      registerFn = *(code **)(atexit_globals + 8);
      atexit_globals = __keymgr_set_and_unlock_processwide_ptr(0xe,atexit_globals);
      if ((*(ushort *)(*(int *)(ptrTo_keymgrGlobal_0000f124 + 8) + 4) < 4) || (atexit_globals == 0)) {
        entryCopy = (undefined4 *)_malloc(0xc);
        if (entryCopy == (undefined4 *)0x0) {
          result = 0xffffffff;
        }
        else {
          word1 = entryHome[1];
          word2 = entryHome[2];
          *entryCopy = *entryHome;
          entryCopy[1] = word1;
          entryCopy[2] = word2;
          result = (*registerFn)(_cxa_atexit_wrapper,entryCopy,dsoHandleHome,passThroughR6,passThroughR7,passThroughR8,entryCopy);
        }
      }
      else {
        result = 0xffffffff;
      }
    }
    else if (entryHome[1] == 0) {
      registerFn = *(code **)(atexit_globals + 0x10);
      atexit_globals = __keymgr_set_and_unlock_processwide_ptr(0xe,atexit_globals);
      if ((*(ushort *)(*(int *)(ptrTo_keymgrGlobal_0000f124 + 8) + 4) < 4) || (atexit_globals == 0)) {
        result = (*registerFn)(*entryHome);
      }
      else {
        result = 0xffffffff;
      }
    }
    else {
      registerFn = *(code **)(atexit_globals + 8);
      atexit_globals = __keymgr_set_and_unlock_processwide_ptr(0xe,atexit_globals);
      if ((*(ushort *)(*(int *)(ptrTo_keymgrGlobal_0000f124 + 8) + 4) < 4) || (atexit_globals == 0)) {
        result = (*registerFn)(*entryHome,entryHome[2],dsoHandleHome,passThroughR6,passThroughR7,passThroughR8,
                             *entryHome);
      }
      else {
        result = 0xffffffff;
      }
    }
  }
  else {
    result = ((int (*)())_add_routine)(atexit_globals,entryHome);
  }
  return result;
}

/* pic_jump_malloc_1f78 @ 0x1f78 (32 bytes) */
int pic_jump_malloc_1f78(size)
  size_t size;
{
  _malloc(size);
  return;
}

/* pic_jump_keymgr_set_and_unlock_processwide_ptr_1f98 @ 0x1f98 (32 bytes) */
int pic_jump_keymgr_set_and_unlock_processwide_ptr_1f98()
{
                    
                    
  (*(code *)lazyPtrTo_keymgrSetAndUnlockProcesswidePtr_0000f0dc)();
  return;
}

/* pic_jump_add_routine_1fb8 @ 0x1fb8 (32 bytes) */
int pic_jump_add_routine_1fb8(globals, entry)
  int globals;
  undefined4 *entry;
{
  undefined4 word2;
  undefined4 *node;
  int unlockResult;
  undefined4 word1;
  int globalsHome;
  undefined4 *entryHome;
  undefined4 status;
  undefined4 result;
  
  globalsHome = globals;
  entryHome = entry;
  node = _malloc(0x10);
  if (node == (undefined4 *)0x0) {
    __keymgr_set_and_unlock_processwide_ptr(0xe,globalsHome);
    result = 0xffffffff;
  }
  else {
    word1 = entryHome[1];
    word2 = entryHome[2];
    node[1] = *entryHome;
    node[2] = word1;
    node[3] = word2;
    *node = *(undefined4 *)(globalsHome + 4);
    *(undefined4 **)(globalsHome + 4) = node;
    unlockResult = __keymgr_set_and_unlock_processwide_ptr(0xe,globalsHome);
    if ((*(ushort *)(*(int *)(ptrTo_keymgrGlobal_0000f124 + 8) + 4) < 4) || (unlockResult == 0)) {
      status = 0;
    }
    else {
      status = 0xffffffff;
    }
    result = status;
  }
  return result;
}

/* pic_jump_get_globals_1fd8 @ 0x1fd8 (32 bytes) */
int pic_jump_get_globals_1fd8()
{
  int libSystemHandle;
  undefined4 symbolAddress;
  int checkResult;
  void *globals;
  void *result;
  
  globals = (void *)__keymgr_get_and_lock_processwide_ptr(0xe);
  if ((globals == (void *)0x0) && (globals = _calloc(0x14,1), globals == (void *)0x0)) {
    return (void *)0x0;
  }
  if (*(char *)((int)globals + 3) == '\0') {
    libSystemHandle = _dlopen("/usr/lib/libSystem.B.dylib",0x10);
    if (libSystemHandle == 0) {
      *(undefined1 *)((int)globals + 3) = 1;
      symbolAddress = ((int (*)())_find_atexit_10_3)();
      *(undefined4 *)((int)globals + 0x10) = symbolAddress;
      if ((*(int *)((int)globals + 0x10) != 0) &&
         (libSystemHandle = (**(code **)((int)globals + 0x10))(_our_atexit), libSystemHandle == 0))
      goto setResult;
    }
    else {
      symbolAddress = _dlsym(libSystemHandle,"__cxa_atexit");
      *(undefined4 *)((int)globals + 8) = symbolAddress;
      symbolAddress = _dlsym(libSystemHandle,"__cxa_finalize");
      *(undefined4 *)((int)globals + 0xc) = symbolAddress;
      if (((*(int *)((int)globals + 8) != 0) && (*(int *)((int)globals + 0xc) != 0)) &&
         (checkResult = ((int (*)())_check_cxa_atexit)(*(undefined4 *)((int)globals + 8),
                               *(undefined4 *)((int)globals + 0xc)), checkResult != -1)) {
        if (checkResult == 0) {
          *(undefined1 *)((int)globals + 3) = 2;
        }
        else {
          symbolAddress = _dlsym(libSystemHandle,"atexit");
          *(undefined4 *)((int)globals + 0x10) = symbolAddress;
          if (*(int *)((int)globals + 0x10) == 0) goto callKeymgrSetAndUnlockProcesswidePtr;
          *(undefined1 *)((int)globals + 3) = 0x10;
        }
        goto setResult;
      }
    }
callKeymgrSetAndUnlockProcesswidePtr:
    __keymgr_set_and_unlock_processwide_ptr(0xe,globals);
    result = (void *)0x0;
  }
  else {
setResult:
    result = globals;
  }
  return result;
}

/* ___cxa_atexit @ 0x1ff8 (96 bytes) */
int ___cxa_atexit(function, argument, dsoHandle)
  undefined4 function;
  undefined4 argument;
  undefined4 dsoHandle;
{
  undefined4 result;
  undefined4 functionHome;
  undefined4 argumentHome;
  undefined4 dsoHandleHome;
  undefined4 entryFunction;
  undefined4 entryKind;
  undefined4 entryArgument;
  
  entryKind = 1;
  functionHome = function;
  argumentHome = argument;
  dsoHandleHome = dsoHandle;
  entryFunction = function;
  entryArgument = argument;
  result = ((int (*)())_atexit_common)(&entryFunction,dsoHandle);
  return result;
}

/* pic_jump_atexit_common_2058 @ 0x2058 (32 bytes) */
int pic_jump_atexit_common_2058(atexitEntry, dsoHandle)
  undefined4 atexitEntry;
  undefined4 dsoHandle;
{
  ((int (*)())_atexit_common)(atexitEntry,dsoHandle);
  return;
}

/* _atexit @ 0x2078 (92 bytes) */
int _atexit(atexit_function)
  undefined4 atexit_function;
{
  undefined4 result;
  undefined4 atexitFunctionHome;
  undefined4 entryFunction;
  undefined4 entryKind;
  
  entryKind = 0;
  atexitFunctionHome = atexit_function;
  entryFunction = atexit_function;
  result = ((int (*)())_atexit_common)(&entryFunction,atexitDsoHandle_0000f128);
  return result;
}

/* pic_jump_atexit_common_20d4 @ 0x20d4 (32 bytes) */
int pic_jump_atexit_common_20d4(atexitEntry, dsoHandle)
  undefined4 atexitEntry;
  undefined4 dsoHandle;
{
  ((int (*)())_atexit_common)(atexitEntry,dsoHandle);
  return;
}

/* _AVACreateRenderer @ 0x2100 (556 bytes) */
int _AVACreateRenderer(outRenderer, driverInfo, rendererInfo)
  undefined4 *outRenderer;
  undefined4 *driverInfo;
  undefined4 *rendererInfo;
{
  undefined *fnTableA;
  undefined *fnTableB;
  undefined4 status;
  undefined4 *renderer;
  int infoBlock;
  uint bit;
  
  status = 0xfffffff9;
  if (outRenderer != (undefined4 *)0x0) {
    renderer = (undefined4 *)_calloc(1,100);
    if (renderer != (undefined4 *)0x0) {
      infoBlock = _calloc(1,0x14);
      renderer[3] = infoBlock;
      if (infoBlock != 0) {
        *renderer = 0x1020000;
        renderer[1] = 1;
        *rendererInfo = 0x1020000;
        rendererInfo[1] = 1;
        rendererInfo[5] = 2;
        rendererInfo[3] = 2;
        rendererInfo[4] = 4;
        rendererInfo[2] = rendererInfo[2] | 0x57;
        _strlcpy(rendererInfo + 6,"ATIVADriver ",0x100);
        bit = 0;
        *(undefined4 *)(renderer[3] + 8) = *driverInfo;
        *(undefined4 *)(renderer[3] + 0xc) = driverInfo[2];
        *(undefined4 *)(renderer[3] + 0x10) = driverInfo[3];
        *(undefined4 *)renderer[3] = driverInfo[1];
        *(undefined4 *)(renderer[3] + 4) = 0;
        do {
          if ((1 << (bit & 0x3f) & *(uint *)renderer[3]) != 0) {
            ((uint *)renderer[3])[1] = bit + 1;
          }
          fnTableB = ptrTo_ava_create_context_0000f190;
          fnTableA = ptrTo_ava_destroy_context_0000f168;
          bit = bit + 1;
        } while ((int)bit < 0x20);
        renderer[0xc] = 0;
        renderer[4] = fnTableB;
        renderer[5] = fnTableA;
        fnTableA = ptrTo_ava_wait_for_stamps_0000f15c;
        renderer[6] = ptrTo_ava_check_stamps_0000f180;
        renderer[7] = fnTableA;
        fnTableA = ptrTo_ava_set_property_0000f130;
        renderer[8] = ptrTo_ava_get_property_0000f198;
        renderer[9] = fnTableA;
        fnTableA = ptrTo_ava_set_attribute_0000f188;
        renderer[10] = ptrTo_ava_get_attribute_0000f178;
        renderer[0xb] = fnTableA;
        fnTableA = ptrTo_ava_queue_display_0000f174;
        renderer[0xd] = ptrTo_ava_decode_picture_0000f144;
        renderer[0xe] = fnTableA;
        fnTableA = ptrTo_ava_declare_surface_images_0000f158;
        renderer[0xf] = ptrTo_ava_setup_decode_0000f138;
        renderer[0x10] = fnTableA;
        fnTableA = ptrTo_ava_get_image_descs_0000f170;
        renderer[0x11] = ptrTo_ava_get_surface_descs_0000f14c;
        renderer[0x12] = fnTableA;
        fnTableA = ptrTo_ava_slot20_enqueue_0000f17c;
        renderer[0x13] = ptrTo_ava_new_handle_0000f134;
        renderer[0x14] = fnTableA;
        renderer[0x15] = ptrTo_ava_get_frame_0000f18c;
        renderer[0x16] = ava_destroy_renderer;
        *outRenderer = renderer;
        return 0;
      }
    }
    status = 0xfffffffd;
  }
  return status;
}

/* ava_destroy_renderer @ 0x2340 (108 bytes) */
int ava_destroy_renderer(renderer)
  int renderer;
{
  undefined4 status;
  
  status = 0xfffffff9;
  if (renderer != 0) {
    _free(*(undefined4 *)ptrTo_dvdExtGlobal_0000f13c);
    _free(*(undefined4 *)ptrTo_displayExtGlobal_0000f184);
    _free(*(undefined4 *)(renderer + 0xc));
    _free(renderer);
    status = 0;
  }
  return status;
}

/* _AVACreateRendererDisplayExt @ 0x23b0 (160 bytes) */
int _AVACreateRendererDisplayExt(outExt)
  undefined4 *outExt;
{
  undefined *fnTmp1;
  undefined *fnTmp2;
  undefined *fnTmp3;
  undefined4 status;
  undefined4 *ext;
  
  ext = (undefined4 *)_calloc(1,0x1c);
  fnTmp2 = ptrTo_ava_display_refresh_0000f160;
  status = 0xfffffffd;
  if (ext != (undefined4 *)0x0) {
    ext[1] = 0;
    *ext = 0x1020000;
    fnTmp1 = ptrTo_ava_render_slot_0000f12c;
    status = 0;
    ext[2] = fnTmp2;
    fnTmp3 = ptrTo_ava_noop_49f0_0000f154;
    ext[3] = fnTmp1;
    fnTmp2 = ptrTo_ava_noop_4a00_0000f148;
    ext[4] = fnTmp3;
    fnTmp1 = ptrTo_displayExtGlobal_0000f184;
    ext[5] = fnTmp2;
    *(undefined4 **)fnTmp1 = ext;
    *outExt = ext;
  }
  return status;
}

/* _AVACreateRendererDVDExt @ 0x2450 (164 bytes) */
int _AVACreateRendererDVDExt(outExt)
  undefined4 *outExt;
{
  undefined *fnTmp1;
  undefined *fnTmp2;
  undefined4 status;
  undefined4 *ext;
  
  ext = (undefined4 *)_calloc(1,0x20);
  fnTmp2 = ptrTo_ava_setup_subpicture_0000f194;
  fnTmp1 = ptrTo_ava_dvd_ext_emit_packet_0d_0000f16c;
  status = 0xfffffffd;
  if (ext != (undefined4 *)0x0) {
    *ext = 0x1020000;
    status = 0;
    ext[2] = fnTmp2;
    ext[4] = fnTmp1;
    fnTmp1 = ptrTo_ava_set_macrovision_0000f164;
    ext[3] = ptrTo_ava_display_subpicture_0000f140;
    ext[6] = fnTmp1;
    ext[5] = ptrTo_ava_release_subpicture_0000f150;
    *outExt = ext;
    *(undefined4 **)ptrTo_dvdExtGlobal_0000f13c = ext;
  }
  return status;
}

/* _AVAGetRendererInfo @ 0x2500 (108 bytes) */
int _AVAGetRendererInfo(rendererInfo)
  undefined4 *rendererInfo;
{
  rendererInfo[5] = 2;
  *rendererInfo = 0x1020000;
  rendererInfo[3] = 2;
  rendererInfo[4] = 4;
  rendererInfo[2] = rendererInfo[2] | 0x57;
  _strlcpy(rendererInfo + 6,"ATIVADriver ",0x100);
  return 0;
}

/* ava_create_context @ 0x2570 (936 bytes) */
int ava_create_context(renderer, outContext, createInfo)
  uint renderer;
  undefined4 *outContext;
  uint *createInfo;
{
  undefined *kernelTask;
  int status;
  uint displayIndex;
  uint displayMask;
  uint *ctx;
  uint *trackTable;
  undefined4 outCount;
  uint scalarIn0;
  uint scalarIn1;
  undefined4 scalarIn2;
  
  if ((renderer == 0) || (outContext == (undefined4 *)0x0)) {
    return 0xfffffff9;
  }
  if (*createInfo < 6) {
    displayMask = _CGDisplayIDToOpenGLDisplayMask(createInfo[2]);
    if (((displayMask & **(uint **)(renderer + 0xc)) == 0) || ((displayMask & ~**(uint **)(renderer + 0xc)) != 0))
    {
      return 0xfffffffb;
    }
    ctx = (uint *)_calloc(1,0x15408);
    kernelTask = ptrTo_machTaskSelf_0000f1a0;
    if (ctx != (uint *)0x0) {
      status = *(int *)(*(int *)(renderer + 0xc) + 4);
      if ((status == 0) || ((displayMask & 1) != 0)) {
        displayIndex = 0;
      }
      else {
        displayIndex = 0;
        do {
          displayIndex = displayIndex + 1;
          status = status + -1;
          if (status == 0) break;
        } while ((1 << (displayIndex & 0x3f) & displayMask) == 0);
      }
      displayMask = *(uint *)(displayIndex * 4 + *(int *)(*(int *)(renderer + 0xc) + 8));
      ctx[4] = displayMask;
      *ctx = createInfo[2];
      ctx[1] = createInfo[3];
      ctx[2] = createInfo[4];
      ctx[3] = createInfo[5];
      ctx[0x15] = *createInfo;
      displayIndex = createInfo[1];
      ctx[6] = 0x4024;
      ctx[5] = 0;
      ctx[0x14] = renderer;
      ctx[0x16] = displayIndex;
      status = _IOServiceOpen(displayMask,*(undefined4 *)kernelTask,3,ctx + 5);
      if (status == 0) {
        outCount = 2;
        status = _io_connect_method_scalarI_scalarO(ctx[5],1,0,0,ctx + 8,&outCount);
        if (status == 0) {
          ctx[0x10] = 0;
          status = _IOConnectMapMemory(ctx[5],1,*(undefined4 *)kernelTask,ctx + 0x10,ctx + 0x11,
                                      1);
          if (status == 0) {
            trackTable = ctx + 0x157;
            _memset(trackTable,0,0x14eac);
            ctx[0x5155] = 0;
            status = _IOConnectMapMemory(ctx[5],4,*(undefined4 *)kernelTask,ctx + 0x5155,
                                        ctx + 0x5156,1);
            if (status == 0) {
              ctx[0x5157] = 0;
              status = _IOConnectMapMemory(ctx[5],5,*(undefined4 *)kernelTask,ctx + 0x5157,
                                          ctx + 0x5158,1);
              if (status == 0) {
                ctx[0x12] = 0;
                status = _IOConnectMapMemory(ctx[5],2,*(undefined4 *)kernelTask,ctx + 0x12,
                                            ctx + 0x13,1);
                if ((status == 0) &&
                   (status = (**(code **)(*(int *)(renderer + 0xc) + 0x10))
                                      (ctx[1],ctx[2],ctx[3],ctx[6] & 0x803f,*ctx),
                   status == 0)) {
                  scalarIn0 = ctx[3];
                  scalarIn2 = 1;
                  scalarIn1 = ctx[6] & 0xffff4000;
                  status = _io_connect_method_scalarI_structureI(ctx[5],0,&scalarIn0,3,0,0);
                  if (status == 0) {
                    if ((*(uint *)ptrTo_cpuCapabilities_0000f19c & 8) == 0) {
                      if ((*(uint *)ptrTo_cpuCapabilities_0000f19c & 0x10) == 0) {
                        ctx[0x51] = 0x20;
                      }
                      else {
                        ctx[0x51] = 0x80;
                      }
                    }
                    else {
                      ctx[0x51] = 0x40;
                    }
                    displayMask = _malloc(16000);
                    ctx[0x54a5] = displayMask;
                    if (displayMask != 0) {
                      ctx[0x54a7] = displayMask + 4000;
                      ctx[0x2a1] = 0;
                      ctx[0x54ab] = (int)&UINT_00002ee0 + displayMask;
                      ctx[0x54a9] = displayMask + 8000;
                      ctx[0x4d] = 0;
                      ctx[0x4e] = 0x3f800000;
                      ctx[0x4b] = 0;
                      status = 5;
                      ctx[0x4c] = 0x3f800000;
                      ctx[0x47] = 0;
                      ctx[0x48] = 0;
                      ctx[0x2b1] = 0;
                      do {
                        trackTable[0x14b] = 0;
                        trackTable[0x150] = 0;
                        trackTable[0x155] = 0;
                        trackTable = trackTable + 1;
                        status = status + -1;
                      } while (status != 0);
                      ava_init_context_state(ctx);
                      *outContext = ctx;
                      return 0;
                    }
                  }
                }
              }
            }
          }
        }
        _IOServiceClose(ctx[5]);
      }
      _free(ctx);
      return 0xffffffff;
    }
  }
  return 0xfffffffd;
}

/* ava_delete_image @ 0x2930 (132 bytes) */
int ava_delete_image(ctx, mapping, freeBacking)
  int ctx;
  undefined4 *mapping;
  int freeBacking;
{
  int handle;
  
  if ((int *)mapping[10] != (int *)0x0) {
    handle = *(int *)mapping[10];
    if (handle != 0) {
      _io_connect_method_scalarI_structureI(*(undefined4 *)(ctx + 0x14),9,handle,1,0,0);
    }
    if (freeBacking != 0) {
      _free(*mapping);
    }
    _free(mapping[10]);
    mapping[10] = 0;
  }
  return;
}

/* ava_release_image @ 0x29c0 (424 bytes) */
int ava_release_image(ctx, opcodeIndex)
  int ctx;
  int opcodeIndex;
{
  undefined *kernelTask;
  uint *lastHeader;
  int count;
  int *writePtr;
  
  kernelTask = ptrTo_machTaskSelf_0000f1a0;
  writePtr = *(int **)(ctx + 0x34);
  if (*(int **)(ctx + 0x38) <= writePtr + 8) {
    lastHeader = *(uint **)(ctx + 0x30);
    *lastHeader = (int)writePtr - (int)lastHeader >> 2 | *lastHeader;
    *(undefined4 **)(ctx + 0x30) = *(undefined4 **)(ctx + 0x34);
    **(undefined4 **)(ctx + 0x34) = 0x1000000;
    _IOConnectMapMemory(*(undefined4 *)(ctx + 0x14),1,*(undefined4 *)kernelTask,ctx + 0x40,
                        ctx + 0x44,1);
    count = *(int *)(ctx + 0x40);
    *(int *)(ctx + 0x34) = count + 0x20;
    *(int *)(ctx + 0x30) = count + 0x1c;
    *(int *)(ctx + 0x38) = count + 0x20 + *(int *)(count + 0x10) * 4;
    *(undefined4 *)(count + 0x1c) = 0;
    writePtr = *(int **)(ctx + 0x34);
  }
  lastHeader = *(uint **)(ctx + 0x30);
  *(int **)(ctx + 0x34) = writePtr + 8;
  count = 7;
  *lastHeader = (int)writePtr - (int)lastHeader >> 2 | *lastHeader;
  *(int **)(ctx + 0x30) = writePtr;
  *writePtr = opcodeIndex * 0x1000000 + 0x2b000000;
  do {
    writePtr = writePtr + 1;
    *writePtr = -0x80000000;
    kernelTask = ptrTo_machTaskSelf_0000f1a0;
    count = count + -1;
  } while (count != 0);
  lastHeader = *(uint **)(ctx + 0x30);
  *lastHeader = *(int *)(ctx + 0x34) - (int)lastHeader >> 2 | *lastHeader;
  *(undefined4 **)(ctx + 0x30) = *(undefined4 **)(ctx + 0x34);
  **(undefined4 **)(ctx + 0x34) = 0x1000000;
  _IOConnectMapMemory(*(undefined4 *)(ctx + 0x14),1,*(undefined4 *)kernelTask,ctx + 0x40,
                      ctx + 0x44,1);
  count = *(int *)(ctx + 0x40);
  *(int *)(ctx + 0x34) = count + 0x20;
  *(int *)(ctx + 0x30) = count + 0x1c;
  *(int *)(ctx + 0x38) = count + 0x20 + *(int *)(count + 0x10) * 4;
  *(undefined4 *)(count + 0x1c) = 0;
  return;
}

/* ava_destroy_context @ 0x2b70 (244 bytes) */
int ava_destroy_context(ctx)
  int ctx;
{
  bool more;
  undefined4 status;
  int cursor;
  uint mappingIndex;
  undefined4 *tableEntry;
  
  status = 0xfffffff9;
  if (ctx != 0) {
    cursor = 0;
    tableEntry = (undefined4 *)(ctx + 0x14430);
    do {
      status = *tableEntry;
      tableEntry = tableEntry + 3;
      _free(status);
      more = cursor != 0x18;
      cursor = cursor + 1;
    } while (more);
    _free(*(undefined4 *)(ctx + 0x15294));
    if (*(int *)(ctx + 0x54) != 0) {
      cursor = ctx + 0x814;
      mappingIndex = 0;
      do {
        mappingIndex = mappingIndex + 1;
        ((int (*)())ava_delete_image)(ctx,cursor,1);
        cursor = cursor + 100;
      } while (mappingIndex < *(uint *)(ctx + 0x54));
    }
    ((int (*)())ava_release_image)(ctx,0);
    ((int (*)())ava_delete_image)(ctx,ctx + 0x1518c,1);
    ((int (*)())ava_release_image)(ctx,1);
    ((int (*)())ava_delete_image)(ctx,ctx + 0x15394,1);
    _IOServiceClose(*(undefined4 *)(ctx + 0x14));
    _free(ctx);
    status = 0;
  }
  return status;
}

/* ava_check_stamps @ 0x2c70 (132 bytes) */
int ava_check_stamps(ctx, unused1, slot)
  int ctx;
  undefined4 unused1;
  uint slot;
{
  int entry;
  int scalarOut [3];
  undefined4 scalarIn1;
  
  scalarOut[1] = 1;
  if (slot < 10000) {
    entry = slot * 8 + ctx + 0x55c;
    scalarOut[2] = *(undefined4 *)(entry + 0x56c);
    scalarIn1 = *(undefined4 *)(entry + 0x570);
    _io_connect_method_scalarI_scalarO
              (*(undefined4 *)(ctx + 0x14),0x14,scalarOut + 2,2,scalarOut,scalarOut + 1);
    if (scalarOut[0] != 1) {
      return 0;
    }
  }
  return 1;
}

/* ava_wait_for_stamps @ 0x2d00 (120 bytes) */
int ava_wait_for_stamps(ctx, unused1, slot)
  int ctx;
  undefined4 unused1;
  uint slot;
{
  int entry;
  undefined4 scalarIn0;
  undefined4 scalarIn1;
  
  if (slot < 10000) {
    entry = slot * 8 + ctx + 0x55c;
    scalarIn0 = *(undefined4 *)(entry + 0x56c);
    scalarIn1 = *(undefined4 *)(entry + 0x570);
    entry = _io_connect_method_scalarI_structureI
                      (*(undefined4 *)(ctx + 0x14),0x13,&scalarIn0,2,0,0);
    if (entry == 0) {
      return 0;
    }
  }
  return 0xfffffff9;
}

/* ava_get_property @ 0x2d80 (64 bytes) */
int ava_get_property(ctx, property, outValue)
  int ctx;
  int property;
  undefined4 *outValue;
{
  if (property == 3) {
    *outValue = 4;
    return 0;
  }
  if (property != 4) {
    *outValue = 0;
    return 0xfffffff9;
  }
  *outValue = *(undefined4 *)(ctx + 0x120);
  return 0;
}

/* ava_set_property @ 0x2dc0 (68 bytes) */
int ava_set_property(ctx, property, value)
  int ctx;
  int property;
  int value;
{
  undefined4 status;
  
  status = 0xfffffff9;
  if (property == 4) {
    *(int *)(ctx + 0x120) = value;
    status = 0;
    if (value == 4) {
      ava_emit_deint_enable_packet(ctx);
      status = 0;
    }
  }
  return status;
}

/* ava_get_attribute @ 0x2e10 (64 bytes) */
int ava_get_attribute(ctx, property, outValue)
  int ctx;
  int property;
  undefined4 *outValue;
{
  if (property == 3) {
    *outValue = 4;
    return 0;
  }
  if (property != 4) {
    *outValue = 0;
    return 0xfffffff9;
  }
  *outValue = *(undefined4 *)(ctx + 0x120);
  return 0;
}

/* ava_set_attribute @ 0x2e50 (1144 bytes) */
int ava_set_attribute(ctx, attribute, value)
  int ctx;
  undefined4 attribute;
  float *value;
{
  float hue;
  float brightness;
  float newValue;
  uint flags;
  int kr;
  undefined4 status;
  undefined4 outCount;
  undefined4 scalarIn0;
  uint scalarIn1;
  undefined4 scalarIn2;
  undefined4 scalarIn3;
  uint controlWord;
  undefined1 attributeBlock [284];
  
  switch(attribute) {
  case 4:
    hue = *(float *)(ctx + 300);
    status = 0;
    brightness = *(float *)(ctx + 0x134);
    flags = *(uint *)(ctx + 0x11c) | 1;
    *(float *)(ctx + 0x120) = *value;
    *(uint *)(ctx + 0x11c) = flags;
    break;
  default:
    hue = *(float *)(ctx + 300);
    brightness = *(float *)(ctx + 0x134);
    status = 0xfffffffb;
    flags = *(uint *)(ctx + 0x11c);
    break;
  case 0x17:
    newValue = *value;
    *(float *)(ctx + 300) = newValue;
    if (newValue < -3.1415927) {
      *(float *)(ctx + 300) = -3.1415927;
    }
    hue = *(float *)(ctx + 300);
    if (hue <= 3.1415927) {
loopSetBrightness:
      brightness = *(float *)(ctx + 0x134);
loopSetFlags:
      flags = *(uint *)(ctx + 0x11c);
      status = 0;
    }
    else {
      brightness = *(float *)(ctx + 0x134);
      status = 0;
      hue = 3.1415927;
      flags = *(uint *)(ctx + 0x11c);
      *(float *)(ctx + 300) = 3.1415927;
    }
    break;
  case 0x18:
    newValue = *value;
    *(float *)(ctx + 0x130) = newValue;
    if (newValue < 0.0) {
      *(float *)(ctx + 0x130) = 0.0;
    }
    if (*(float *)(ctx + 0x130) <= 3.0) {
      hue = *(float *)(ctx + 300);
      brightness = *(float *)(ctx + 0x134);
      goto loopSetFlags;
    }
    hue = *(float *)(ctx + 300);
    brightness = *(float *)(ctx + 0x134);
    status = 0;
    flags = *(uint *)(ctx + 0x11c);
    *(float *)(ctx + 0x130) = 3.0;
    break;
  case 0x19:
    newValue = *value;
    *(float *)(ctx + 0x134) = newValue;
    if (newValue < -1.0) {
      *(float *)(ctx + 0x134) = -1.0;
    }
    brightness = 1.0;
    if (*(float *)(ctx + 0x134) <= 1.0) {
      hue = *(float *)(ctx + 300);
      brightness = *(float *)(ctx + 0x134);
      goto loopSetFlags;
    }
    hue = *(float *)(ctx + 300);
    flags = *(uint *)(ctx + 0x11c);
    status = 0;
    *(float *)(ctx + 0x134) = 1.0;
    break;
  case 0x1a:
    newValue = *value;
    *(float *)(ctx + 0x138) = newValue;
    if (newValue < 0.25) {
      *(float *)(ctx + 0x138) = 0.25;
    }
    if (*(float *)(ctx + 0x138) <= 4.0) {
      hue = *(float *)(ctx + 300);
      goto loopSetBrightness;
    }
    hue = *(float *)(ctx + 300);
    brightness = *(float *)(ctx + 0x134);
    status = 0;
    flags = *(uint *)(ctx + 0x11c);
    *(float *)(ctx + 0x138) = 4.0;
    break;
  case 0x1b:
    status = 0;
    ava_render_slot(ctx,(int)GH_F2U((float)(SUB41(*value,0))),(int)(char)*(undefined4 *)(ctx + 0x114),
                 ctx + 0x10c,*(undefined4 *)(ctx + 0x118));
    hue = *(float *)(ctx + 300);
    brightness = *(float *)(ctx + 0x134);
    flags = *(uint *)(ctx + 0x11c);
    break;
  case 0x1c:
    *(short *)(ctx + 0x124) = SUB42(*value,0);
    newValue = value[1];
    if ((uint)GH_F2U((float)(*(float *)(ctx + 0x57c))) < (uint)GH_F2U((float)(value[1]))) {
      newValue = *(float *)(ctx + 0x57c);
    }
    *(short *)(ctx + 0x128) = SUB42(newValue,0);
    *(short *)(ctx + 0x126) = SUB42(value[2],0);
    newValue = value[3];
    if ((uint)GH_F2U((float)(*(float *)(ctx + 0x578))) < (uint)GH_F2U((float)(value[3]))) {
      newValue = *(float *)(ctx + 0x578);
    }
    hue = *(float *)(ctx + 300);
    brightness = *(float *)(ctx + 0x134);
    status = 0;
    flags = *(uint *)(ctx + 0x11c);
    *(short *)(ctx + 0x12a) = SUB42(newValue,0);
  }
  if ((brightness == 0.0) && (*(float *)(ctx + 0x138) == 1.0)) {
    flags = flags & 0xfffffffd;
    *(uint *)(ctx + 0x11c) = flags;
  }
  else {
    flags = flags | 2;
    *(uint *)(ctx + 0x11c) = flags;
  }
  if (((hue == 0.0) && (*(float *)(ctx + 0x138) == 1.0)) &&
     (*(float *)(ctx + 0x130) == 1.0)) {
    flags = flags & 0xfffffffb;
    *(uint *)(ctx + 0x11c) = flags;
  }
  else {
    flags = flags | 4;
    *(uint *)(ctx + 0x11c) = flags;
  }
  if ((flags & 1) == 0) {
    if ((flags & 2) == 0) {
      if ((flags & 4) == 0) goto checkCtx;
      controlWord = *(uint *)(ctx + 0xa84);
      goto checkFlags;
    }
    controlWord = *(uint *)(ctx + 0xa84);
loopSetControlWord:
    controlWord = controlWord | 0x80000;
    *(uint *)(ctx + 0xa84) = controlWord;
  }
  else {
    outCount = 0;
    scalarIn0 = 1;
    kr = _io_connect_method_scalarI_scalarO
                      (*(undefined4 *)(ctx + 0x14),0x11,&scalarIn0,1,0,&outCount);
    if (kr != 0) {
      return 0xfffffffb;
    }
    controlWord = *(uint *)(ctx + 0xa84) | 0x8000;
    *(uint *)(ctx + 0xa84) = controlWord;
    flags = *(uint *)(ctx + 0x11c);
checkFlags:
    if (((flags & 2) != 0) || ((flags & 4) != 0)) goto loopSetControlWord;
  }
  scalarIn2 = *(undefined4 *)(ctx + 0x57c);
  scalarIn1 = *(undefined4 *)(ctx + 0x578);
  scalarIn3 = 0;
  outCount = 0;
  scalarIn0 = 0;
  kr = _io_connect_method_scalarI_scalarO
                    (*(undefined4 *)(ctx + 0x14),0x15,&scalarIn0,5,0,&outCount);
  if (kr == 0) {
    scalarIn0 = *(undefined4 *)(ctx + 0xc);
    scalarIn1 = *(uint *)(ctx + 0x18) & 0xffff4000;
    scalarIn2 = 1;
    kr = _io_connect_method_scalarI_structureI
                      (*(undefined4 *)(ctx + 0x14),0,&scalarIn0,3,0,0);
    if (kr == 0) {
      outCount = 0x100;
      kr = _io_connect_method_scalarI_structureO
                        (*(undefined4 *)(ctx + 0x14),4,&scalarIn0,1,attributeBlock,&outCount);
      if (kr == 0) {
checkCtx:
        if (*(int *)(ctx + 0x120) == 4) {
          ava_emit_deint_enable_packet(ctx);
          return status;
        }
        return status;
      }
    }
  }
  return 0xfffffffb;
}

/* ava_declare_image @ 0x3350 (720 bytes) */
int ava_declare_image(ctx, surface, unused, width, height, pixelFormat, externalData)
  int ctx;
  uint *surface;
  undefined4 unused;
  uint width;
  uint height;
  uint pixelFormat;
  uint externalData;
{
  bool hasExternalData;
  undefined4 formatCode;
  uint widthCopy;
  uint record;
  uint pitch;
  int kr;
  uint bytesPerPixel;
  undefined4 outCount;
  undefined4 scalarIn0;
  uint scalarIn1;
  int scalarIn2;
  
  if (surface == (uint *)0x0) {
    return 0xfffffff9;
  }
  record = _calloc(1,0x34);
  if (record == 0) {
    return 0xfffffffd;
  }
  if (pixelFormat == 0x61723135) {
    formatCode = 0xb;
  }
  else if (pixelFormat < 0x61723136) {
    if (pixelFormat == 0x20) {
loopStoreRecord:
      *(undefined4 *)(record + 0x24) = 4;
      *(undefined4 *)(record + 0x28) = 2;
      *(undefined4 *)(record + 0x2c) = 0xc;
      *(undefined4 *)(record + 0x30) = 2;
      goto setHasExternalData;
    }
    if (pixelFormat != 0x32767579) {
      if (pixelFormat != 8) {
        return 0xfffffff9;
      }
      *(undefined4 *)(record + 0x28) = 0;
      *(undefined4 *)(record + 0x24) = 1;
      *(undefined4 *)(record + 0x2c) = 0;
      *(undefined4 *)(record + 0x30) = 0;
      goto setHasExternalData;
    }
    formatCode = 0x14;
  }
  else {
    if (pixelFormat == 0x72676261) {
      *(undefined4 *)(record + 0x2c) = 0xc;
      *(undefined4 *)(record + 0x24) = 4;
      *(undefined4 *)(record + 0x30) = 0;
      *(undefined4 *)(record + 0x28) = 2;
      goto setHasExternalData;
    }
    if (pixelFormat != 0x79757673) {
      if (pixelFormat != 0x61726762) {
        return 0xfffffff9;
      }
      goto loopStoreRecord;
    }
    formatCode = 0x15;
  }
  *(undefined4 *)(record + 0x2c) = formatCode;
  *(undefined4 *)(record + 0x24) = 2;
  *(undefined4 *)(record + 0x30) = 0;
  *(undefined4 *)(record + 0x28) = 1;
setHasExternalData:
  hasExternalData = externalData != 0;
  surface[5] = height;
  surface[4] = width;
  *surface = 0;
  if (hasExternalData) {
    bytesPerPixel = *(uint *)(record + 0x24);
    surface[6] = width * bytesPerPixel;
  }
  else {
    bytesPerPixel = *(uint *)(record + 0x24);
    surface[6] = width * bytesPerPixel + 0xff & 0xffffff00;
  }
  surface[1] = pixelFormat;
  *(undefined4 *)(record + 4) = *(undefined4 *)(ctx + 0xc);
  pitch = surface[6];
  *(undefined2 *)(record + 10) = 0;
  *(undefined2 *)(record + 8) = 0;
  *(uint *)(record + 0x18) = pitch / bytesPerPixel;
  widthCopy = surface[4];
  *(short *)(record + 0xc) = (short)widthCopy;
  bytesPerPixel = surface[5];
  *(uint *)(record + 0x10) = widthCopy;
  *(short *)(record + 0xe) = (short)bytesPerPixel;
  *(uint *)(record + 0x14) = bytesPerPixel;
  if (hasExternalData) {
    *surface = externalData;
  }
  else {
    bytesPerPixel = _malloc(bytesPerPixel * pitch + 0x100);
    *surface = bytesPerPixel;
    if (bytesPerPixel == 0) {
      _free(record);
      return 0xfffffffd;
    }
    pitch = surface[6];
    bytesPerPixel = surface[5];
  }
  scalarIn0 = 0;
  if (hasExternalData) {
    scalarIn1 = *surface;
  }
  else {
    scalarIn1 = *surface + 0xff & 0xffffff00;
  }
  scalarIn2 = bytesPerPixel * pitch;
  outCount = 1;
  kr = _io_connect_method_scalarI_scalarO
                    (*(undefined4 *)(ctx + 0x14),8,&scalarIn0,3,record,&outCount);
  if (kr == 0) {
    if ((*(uint *)(ctx + 0x20) & 0x82) != 0) {
      surface[9] = 1;
    }
    surface[10] = record;
    formatCode = 0;
  }
  else {
    _free(record);
    _free(*surface);
    formatCode = 0xfffffffd;
  }
  return formatCode;
}

/* ava_declare_surface_images @ 0x3630 (356 bytes) */
int ava_declare_surface_images(ctx, surfaceDescs, count)
  int ctx;
  int *surfaceDescs;
  int count;
{
  uint alignedPitch;
  undefined4 *desc;
  undefined4 status;
  int kr;
  int descBase;
  int surfaceCount;
  int descCursor;
  int index;
  
  descBase = ctx + 0x55c;
  surfaceCount = *(int *)(ctx + 0x54);
  status = 0xfffffff9;
  if (surfaceCount == count) {
    if (surfaceCount != 0) {
      index = 0;
      descCursor = descBase;
      do {
        desc = (undefined4 *)surfaceDescs[index];
        kr = ((int (*)())ava_declare_image)(ctx,ctx + 0x814 + index * 100,*(undefined4 *)(descCursor + 0x4ac),
                             *desc,desc[1],desc[3],0);
        if (kr != 0) {
          if (0 < index) {
            surfaceCount = 0;
            descBase = ctx + 0x814;
            do {
              surfaceCount = surfaceCount + 1;
              ((int (*)())ava_delete_image)(ctx,descBase,1);
              descBase = descBase + 100;
            } while (surfaceCount != index);
          }
          return 0xfffffffd;
        }
        index = index + 1;
        descCursor = descCursor + 4;
        kr = descBase;
      } while (index != surfaceCount);
      do {
        *(undefined4 *)(kr + 0x178) = *(undefined4 *)*surfaceDescs;
        *(undefined4 *)(kr + 0x17c) = *(undefined4 *)(*surfaceDescs + 4);
        status = *(undefined4 *)(descBase + 0x2d0);
        *(undefined4 *)(kr + 0x180) = status;
        *(undefined4 *)(kr + 0x184) = *(undefined4 *)(*surfaceDescs + 0xc);
        surfaceCount = *(int *)(descBase + 0x2b8);
        *(undefined4 *)(kr + 0x194) = 1;
        descBase = descBase + 100;
        alignedPitch = surfaceCount + 0xffU & 0xffffff00;
        *(uint *)(kr + 400) = alignedPitch;
        kr = kr + 0x40;
        *(undefined4 *)(*surfaceDescs + 8) = status;
        surfaceCount = *surfaceDescs;
        surfaceDescs = surfaceDescs + 1;
        *(uint *)(surfaceCount + 0x18) = alignedPitch;
        index = index + -1;
      } while (index != 0);
    }
    status = 0;
  }
  return status;
}

/* ava_get_surface_descs @ 0x37b0 (124 bytes) */
int ava_get_surface_descs(ctx, outDescs)
  int ctx;
  int *outDescs;
{
  undefined4 *src0;
  uint index;
  undefined4 word7;
  undefined4 word3;
  int dest;
  undefined4 word2;
  int entry;
  undefined4 word1;
  
  entry = ctx + 0x55c;
  if (*(int *)(ctx + 0x54) != 0) {
    index = 0;
    do {
      src0 = (undefined4 *)(entry + 0x38);
      index = index + 1;
      word1 = *(undefined4 *)(entry + 0x3c);
      word2 = *(undefined4 *)(entry + 0x40);
      word3 = *(undefined4 *)(entry + 0x44);
      word7 = *(undefined4 *)(entry + 0x54);
      entry = entry + 0x40;
      *(undefined4 *)*outDescs = *src0;
      *(undefined4 *)(*outDescs + 4) = word1;
      *(undefined4 *)(*outDescs + 8) = word2;
      *(undefined4 *)(*outDescs + 0xc) = word3;
      dest = *outDescs;
      outDescs = outDescs + 1;
      *(undefined4 *)(dest + 0x1c) = word7;
    } while (index < *(uint *)(ctx + 0x54));
  }
  return 0;
}

/* ava_get_image_descs @ 0x3830 (136 bytes) */
int ava_get_image_descs(ctx, outDescs)
  int ctx;
  int *outDescs;
{
  undefined4 *src0;
  int dest;
  undefined4 word7;
  undefined4 word6;
  undefined4 word3;
  undefined4 word2;
  int entry;
  undefined4 word1;
  uint index;
  
  entry = ctx + 0x55c;
  if (*(int *)(ctx + 0x54) != 0) {
    index = 0;
    do {
      src0 = (undefined4 *)(entry + 0x178);
      index = index + 1;
      word1 = *(undefined4 *)(entry + 0x17c);
      word2 = *(undefined4 *)(entry + 0x180);
      word3 = *(undefined4 *)(entry + 0x184);
      word6 = *(undefined4 *)(entry + 400);
      word7 = *(undefined4 *)(entry + 0x194);
      entry = entry + 0x40;
      *(undefined4 *)*outDescs = *src0;
      *(undefined4 *)(*outDescs + 4) = word1;
      *(undefined4 *)(*outDescs + 8) = word2;
      *(undefined4 *)(*outDescs + 0xc) = word3;
      *(undefined4 *)(*outDescs + 0x18) = word6;
      dest = *outDescs;
      outDescs = outDescs + 1;
      *(undefined4 *)(dest + 0x1c) = word7;
    } while (index < *(uint *)(ctx + 0x54));
  }
  return 0;
}

/* ava_new_handle @ 0x38c0 (100 bytes) */
int ava_new_handle(ctx, unused1, unused2, outSlot)
  int ctx;
  undefined4 unused1;
  undefined4 unused2;
  undefined4 *outSlot;
{
  undefined4 slotIndex;
  
  *(undefined4 *)(*(int *)(ctx + 0xac4) * 8 + ctx + 0x55c + 0x56c) = 0;
  *(undefined4 *)(*(int *)(ctx + 0xac4) * 8 + ctx + 0x55c + 0x570) = 0;
  slotIndex = *(undefined4 *)(ctx + 0xac4);
  *outSlot = 0;
  outSlot[1] = slotIndex;
  *(uint *)(ctx + 0xac4) = (*(int *)(ctx + 0xac4) + 1U) % 10000;
  return 0;
}

