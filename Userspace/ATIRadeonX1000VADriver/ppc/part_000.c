#include "decls.h"

/* FUN_00001070 @ 0x1070 (48 bytes) */
int FUN_00001070()
{
                    
                    
  (*DAT_0000f0c4)();
  return;
}

/* FUN_000010a0 @ 0x10a0 (32 bytes) */
int FUN_000010a0()
{
                    
                    
  (*DAT_0000f0c8)();
  return;
}

/* FUN_000010c0 @ 0x10c0 (40 bytes) */
int FUN_000010c0(param_1)
  undefined4 *param_1;
{
  *param_1 = 1;
  return;
}

/* FUN_000010e8 @ 0x10e8 (120 bytes) */
int FUN_000010e8(param_1)
  undefined4 *param_1;
{
  int iVar1;
  undefined4 *puStack00000018;
  
  puStack00000018 = param_1;
  iVar1 = (*(code *)param_1[1])(FUN_000010c0,param_1,param_1);
  if (iVar1 != 0) {
    *param_1 = 0xffffffff;
  }
  return;
}

/* FUN_00001160 @ 0x1160 (204 bytes) */
int FUN_00001160(param_1, param_2)
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
  iVar1 = (*param_1)(FUN_000010e8,&local_28,&local_28);
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

/* FUN_0000122c @ 0x122c (504 bytes) */
int FUN_0000122c()
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
  
  ((int (*)())FUN_000010a0)("__dyld_image_count",&local_34);
  ((int (*)())FUN_000010a0)("__dyld_get_image_name",&local_30);
  ((int (*)())FUN_000010a0)("__dyld_get_image_header",&local_2c);
  ((int (*)())FUN_000010a0)("__dyld_NSLookupSymbolInImage",&local_28);
  ((int (*)())FUN_000010a0)("__dyld_NSAddressOfSymbol",local_24);
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

/* FUN_00001424 @ 0x1424 (32 bytes) */
int FUN_00001424(param_1, param_2)
  char *param_1;
  char *param_2;
{
  _strcmp(param_1,param_2);
  return;
}

/* FUN_00001444 @ 0x1444 (32 bytes) */
int FUN_00001444()
{
                    
                    
  (*DAT_0000f0c8)();
  return;
}

/* FUN_00001464 @ 0x1464 (528 bytes) */
int FUN_00001464()
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
      uVar2 = ((int (*)())FUN_0000122c)();
      *(undefined4 *)((int)local_20 + 0x10) = uVar2;
      if ((*(int *)((int)local_20 + 0x10) != 0) &&
         (iVar1 = (**(code **)((int)local_20 + 0x10))(FUN_00001bbc), iVar1 == 0)) goto LAB_00001638;
    }
    else {
      uVar2 = _dlsym(iVar1,"__cxa_atexit");
      *(undefined4 *)((int)local_20 + 8) = uVar2;
      uVar2 = _dlsym(iVar1,"__cxa_finalize");
      *(undefined4 *)((int)local_20 + 0xc) = uVar2;
      if (((*(int *)((int)local_20 + 8) != 0) && (*(int *)((int)local_20 + 0xc) != 0)) &&
         (iVar3 = ((int (*)())FUN_00001160)(*(undefined4 *)((int)local_20 + 8),
                               *(undefined4 *)((int)local_20 + 0xc)), iVar3 != -1)) {
        if (iVar3 == 0) {
          *(undefined1 *)((int)local_20 + 3) = 2;
        }
        else {
          uVar2 = _dlsym(iVar1,"atexit");
          *(undefined4 *)((int)local_20 + 0x10) = uVar2;
          if (*(int *)((int)local_20 + 0x10) == 0) goto LAB_00001644;
          *(undefined1 *)((int)local_20 + 3) = 0x10;
        }
        goto LAB_00001638;
      }
    }
LAB_00001644:
    __keymgr_set_and_unlock_processwide_ptr(0xe,local_20);
    local_18 = (void *)0x0;
  }
  else {
LAB_00001638:
    local_18 = local_20;
  }
  return local_18;
}

/* FUN_00001674 @ 0x1674 (32 bytes) */
int FUN_00001674()
{
  __keymgr_set_and_unlock_processwide_ptr();
  return;
}

/* FUN_00001694 @ 0x1694 (32 bytes) */
int FUN_00001694(param_1, param_2)
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
  iVar1 = (*param_1)(FUN_000010e8,&iStack_28,&iStack_28);
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

/* FUN_000016b4 @ 0x16b4 (32 bytes) */
int FUN_000016b4()
{
                    
                    
  (*(code *)PTR_FUN_0000f0e0)();
  return;
}

/* FUN_000016d4 @ 0x16d4 (32 bytes) */
int FUN_000016d4()
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
  
  ((int (*)())FUN_000010a0)("__dyld_image_count",&pcStack_34);
  ((int (*)())FUN_000010a0)("__dyld_get_image_name",&pcStack_30);
  ((int (*)())FUN_000010a0)("__dyld_get_image_header",&pcStack_2c);
  ((int (*)())FUN_000010a0)("__dyld_NSLookupSymbolInImage",&pcStack_28);
  ((int (*)())FUN_000010a0)("__dyld_NSAddressOfSymbol",apcStack_24);
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

/* FUN_000016f4 @ 0x16f4 (32 bytes) */
int FUN_000016f4()
{
                    
                    
  (*(code *)PTR_FUN_0000f0cc)();
  return;
}

/* FUN_00001714 @ 0x1714 (32 bytes) */
int FUN_00001714()
{
                    
                    
  (*(code *)PTR_FUN_0000f0e4)();
  return;
}

/* FUN_00001734 @ 0x1734 (32 bytes) */
int FUN_00001734()
{
                    
                    
  (*(code *)PTR_FUN_0000f0d4)();
  return;
}

/* FUN_00001754 @ 0x1754 (268 bytes) */
int FUN_00001754(param_1, param_2)
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
    if ((*(ushort *)(*(int *)(PTR_0000f124 + 8) + 4) < 4) || (iVar3 == 0)) {
      local_18 = 0;
    }
    else {
      local_18 = 0xffffffff;
    }
    local_14 = local_18;
  }
  return local_14;
}

/* FUN_00001860 @ 0x1860 (32 bytes) */
int FUN_00001860()
{
  __keymgr_set_and_unlock_processwide_ptr();
  return;
}

/* FUN_00001880 @ 0x1880 (32 bytes) */
int FUN_00001880()
{
                    
                    
  (*(code *)PTR_FUN_0000f0d0)();
  return;
}

/* FUN_000018a0 @ 0x18a0 (292 bytes) */
int FUN_000018a0(param_1, param_2)
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

/* FUN_000019c4 @ 0x19c4 (32 bytes) */
int FUN_000019c4()
{
  __keymgr_get_and_lock_processwide_ptr();
  return;
}

/* FUN_000019e4 @ 0x19e4 (32 bytes) */
int FUN_000019e4()
{
                    
                    
  (*(code *)PTR_FUN_0000f0d8)();
  return;
}

/* FUN_00001a04 @ 0x1a04 (32 bytes) */
int FUN_00001a04()
{
                    
                    
  (*(code *)PTR_FUN_0000f0dc)();
  return;
}

/* FUN_00001a24 @ 0x1a24 (312 bytes) */
int FUN_00001a24(param_1)
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
    local_20 = ((int (*)())FUN_000018a0)(local_20,local_24);
  }
  if (local_20 != 0) {
    *(undefined1 *)(local_20 + 2) = local_28;
    __keymgr_set_and_unlock_processwide_ptr(0xe,local_20);
  }
  return;
}

/* FUN_00001b5c @ 0x1b5c (32 bytes) */
int FUN_00001b5c()
{
  ((int (*)())FUN_000018a0)();
  return;
}

/* FUN_00001b7c @ 0x1b7c (32 bytes) */
int FUN_00001b7c()
{
                    
                    
  (*(code *)PTR_FUN_0000f0dc)();
  return;
}

/* FUN_00001b9c @ 0x1b9c (32 bytes) */
int FUN_00001b9c()
{
                    
                    
  (*(code *)PTR_FUN_0000f0d4)();
  return;
}

/* FUN_00001bbc @ 0x1bbc (188 bytes) */
int FUN_00001bbc()
{
  undefined1 uVar1;
  short *psVar2;
  int iVar3;
  
  psVar2 = (short *)__keymgr_get_and_lock_processwide_ptr(0xe);
  if (((psVar2 != (short *)0x0) && (*psVar2 == 0)) && (*(char *)((int)psVar2 + 3) == '\x01')) {
    uVar1 = *(undefined1 *)(psVar2 + 1);
    *(undefined1 *)(psVar2 + 1) = 1;
    iVar3 = ((int (*)())FUN_000018a0)(psVar2,0);
    if (iVar3 != 0) {
      *(undefined1 *)(iVar3 + 2) = uVar1;
      __keymgr_set_and_unlock_processwide_ptr(0xe,iVar3);
    }
  }
  return;
}

/* FUN_00001c78 @ 0x1c78 (32 bytes) */
int FUN_00001c78()
{
  __keymgr_set_and_unlock_processwide_ptr();
  return;
}

/* FUN_00001c98 @ 0x1c98 (32 bytes) */
int FUN_00001c98(param_1, param_2)
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

/* FUN_00001cb8 @ 0x1cb8 (32 bytes) */
int FUN_00001cb8()
{
                    
                    
  (*(code *)PTR_FUN_0000f0d4)();
  return;
}

/* FUN_00001cd8 @ 0x1cd8 (672 bytes) */
int FUN_00001cd8(param_1, param_2)
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
  iVar3 = ((int (*)())FUN_00001464)();
  if (iVar3 == 0) {
    local_18 = 0xffffffff;
  }
  else if ((*(char *)(iVar3 + 2) == '\0') && (*(char *)(iVar3 + 3) != '\x01')) {
    if (*(byte *)(iVar3 + 3) < 0x10) {
      pcVar1 = *(code **)(iVar3 + 8);
      iVar3 = __keymgr_set_and_unlock_processwide_ptr(0xe,iVar3);
      if ((*(ushort *)(*(int *)(PTR_0000f124 + 8) + 4) < 4) || (iVar3 == 0)) {
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
          local_18 = (*pcVar1)(FUN_00001a24,puVar4,uStack0000001c);
        }
      }
      else {
        local_18 = 0xffffffff;
      }
    }
    else if (puStack00000018[1] == 0) {
      pcVar1 = *(code **)(iVar3 + 0x10);
      iVar3 = __keymgr_set_and_unlock_processwide_ptr(0xe,iVar3);
      if ((*(ushort *)(*(int *)(PTR_0000f124 + 8) + 4) < 4) || (iVar3 == 0)) {
        local_18 = (*pcVar1)(*puStack00000018);
      }
      else {
        local_18 = 0xffffffff;
      }
    }
    else {
      pcVar1 = *(code **)(iVar3 + 8);
      iVar3 = __keymgr_set_and_unlock_processwide_ptr(0xe,iVar3);
      if ((*(ushort *)(*(int *)(PTR_0000f124 + 8) + 4) < 4) || (iVar3 == 0)) {
        local_18 = (*pcVar1)(*puStack00000018,puStack00000018[2],uStack0000001c);
      }
      else {
        local_18 = 0xffffffff;
      }
    }
  }
  else {
    local_18 = ((int (*)())FUN_00001754)(iVar3,puStack00000018);
  }
  return local_18;
}

/* FUN_00001f78 @ 0x1f78 (32 bytes) */
int FUN_00001f78(param_1)
  size_t param_1;
{
  _malloc(param_1);
  return;
}

/* FUN_00001f98 @ 0x1f98 (32 bytes) */
int FUN_00001f98()
{
                    
                    
  (*(code *)PTR_FUN_0000f0dc)();
  return;
}

/* FUN_00001fb8 @ 0x1fb8 (32 bytes) */
int FUN_00001fb8(param_1, param_2)
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
    if ((*(ushort *)(*(int *)(PTR_0000f124 + 8) + 4) < 4) || (iVar3 == 0)) {
      uStack_18 = 0;
    }
    else {
      uStack_18 = 0xffffffff;
    }
    uStack_14 = uStack_18;
  }
  return uStack_14;
}

/* FUN_00001fd8 @ 0x1fd8 (32 bytes) */
int FUN_00001fd8()
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
      uVar2 = ((int (*)())FUN_0000122c)();
      *(undefined4 *)((int)pvStack_20 + 0x10) = uVar2;
      if ((*(int *)((int)pvStack_20 + 0x10) != 0) &&
         (iVar1 = (**(code **)((int)pvStack_20 + 0x10))(FUN_00001bbc), iVar1 == 0))
      goto LAB_00001638;
    }
    else {
      uVar2 = _dlsym(iVar1,"__cxa_atexit");
      *(undefined4 *)((int)pvStack_20 + 8) = uVar2;
      uVar2 = _dlsym(iVar1,"__cxa_finalize");
      *(undefined4 *)((int)pvStack_20 + 0xc) = uVar2;
      if (((*(int *)((int)pvStack_20 + 8) != 0) && (*(int *)((int)pvStack_20 + 0xc) != 0)) &&
         (iVar3 = ((int (*)())FUN_00001160)(*(undefined4 *)((int)pvStack_20 + 8),
                               *(undefined4 *)((int)pvStack_20 + 0xc)), iVar3 != -1)) {
        if (iVar3 == 0) {
          *(undefined1 *)((int)pvStack_20 + 3) = 2;
        }
        else {
          uVar2 = _dlsym(iVar1,"atexit");
          *(undefined4 *)((int)pvStack_20 + 0x10) = uVar2;
          if (*(int *)((int)pvStack_20 + 0x10) == 0) goto LAB_00001644;
          *(undefined1 *)((int)pvStack_20 + 3) = 0x10;
        }
        goto LAB_00001638;
      }
    }
LAB_00001644:
    __keymgr_set_and_unlock_processwide_ptr(0xe,pvStack_20);
    pvStack_18 = (void *)0x0;
  }
  else {
LAB_00001638:
    pvStack_18 = pvStack_20;
  }
  return pvStack_18;
}

/* FUN_00001ff8 @ 0x1ff8 (96 bytes) */
int FUN_00001ff8(param_1, param_2, param_3)
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
  uVar1 = ((int (*)())FUN_00001cd8)(&local_28,param_3);
  return uVar1;
}

/* FUN_00002058 @ 0x2058 (32 bytes) */
int FUN_00002058()
{
  ((int (*)())FUN_00001cd8)();
  return;
}

/* FUN_00002078 @ 0x2078 (92 bytes) */
int FUN_00002078(param_1)
  undefined4 param_1;
{
  undefined4 uVar1;
  undefined4 uStack00000018;
  undefined4 local_28;
  undefined4 local_24;
  
  local_24 = 0;
  uStack00000018 = param_1;
  local_28 = param_1;
  uVar1 = ((int (*)())FUN_00001cd8)(&local_28,PTR_0000f128);
  return uVar1;
}

/* FUN_000020d4 @ 0x20d4 (32 bytes) */
int FUN_000020d4()
{
  ((int (*)())FUN_00001cd8)();
  return;
}

/* _AVACreateRenderer @ 0x2100 (556 bytes) */
int _AVACreateRenderer(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 *param_2;
  undefined4 *param_3;
{
  undefined *puVar1;
  undefined *puVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  void *pvVar5;
  uint uVar6;
  
  uVar3 = 0xfffffff9;
  if (param_1 != (undefined4 *)0x0) {
    puVar4 = _calloc(1,100);
    if (puVar4 != (undefined4 *)0x0) {
      pvVar5 = _calloc(1,0x14);
      puVar4[3] = pvVar5;
      if (pvVar5 != (void *)0x0) {
        *puVar4 = 0x1020000;
        puVar4[1] = 1;
        *param_3 = 0x1020000;
        param_3[1] = 1;
        param_3[5] = 2;
        param_3[3] = 2;
        param_3[4] = 4;
        param_3[2] = param_3[2] | 0x57;
        _strlcpy((char *)(param_3 + 6),"ATIVADriver ",0x100);
        uVar6 = 0;
        *(undefined4 *)(puVar4[3] + 8) = *param_2;
        *(undefined4 *)(puVar4[3] + 0xc) = param_2[2];
        *(undefined4 *)(puVar4[3] + 0x10) = param_2[3];
        *(undefined4 *)puVar4[3] = param_2[1];
        *(undefined4 *)(puVar4[3] + 4) = 0;
        do {
          if ((1 << (uVar6 & 0x3f) & *(uint *)puVar4[3]) != 0) {
            ((uint *)puVar4[3])[1] = uVar6 + 1;
          }
          puVar2 = PTR_FUN_0000f190;
          puVar1 = PTR_FUN_0000f168;
          uVar6 = uVar6 + 1;
        } while ((int)uVar6 < 0x20);
        puVar4[0xc] = 0;
        puVar4[4] = puVar2;
        puVar4[5] = puVar1;
        puVar1 = PTR_FUN_0000f15c;
        puVar4[6] = PTR_FUN_0000f180;
        puVar4[7] = puVar1;
        puVar1 = PTR_FUN_0000f130;
        puVar4[8] = PTR_FUN_0000f198;
        puVar4[9] = puVar1;
        puVar1 = PTR_FUN_0000f188;
        puVar4[10] = PTR_FUN_0000f178;
        puVar4[0xb] = puVar1;
        puVar1 = PTR_FUN_0000f174;
        puVar4[0xd] = PTR_FUN_0000f144;
        puVar4[0xe] = puVar1;
        puVar1 = PTR_FUN_0000f158;
        puVar4[0xf] = PTR_FUN_0000f138;
        puVar4[0x10] = puVar1;
        puVar1 = PTR_FUN_0000f170;
        puVar4[0x11] = PTR_FUN_0000f14c;
        puVar4[0x12] = puVar1;
        puVar1 = PTR_FUN_0000f17c;
        puVar4[0x13] = PTR_FUN_0000f134;
        puVar4[0x14] = puVar1;
        puVar4[0x15] = PTR_FUN_0000f18c;
        puVar4[0x16] = FUN_00002340;
        *param_1 = puVar4;
        return 0;
      }
    }
    uVar3 = 0xfffffffd;
  }
  return uVar3;
}

/* FUN_00002340 @ 0x2340 (108 bytes) */
int FUN_00002340(param_1)
  void *param_1;
{
  undefined4 uVar1;
  
  uVar1 = 0xfffffff9;
  if (param_1 != (void *)0x0) {
    _free(*(void **)PTR_DAT_0000f13c);
    _free(*(void **)PTR_DAT_0000f184);
    _free(*(void **)((int)param_1 + 0xc));
    _free(param_1);
    uVar1 = 0;
  }
  return uVar1;
}

/* _AVACreateRendererDisplayExt @ 0x23b0 (160 bytes) */
int _AVACreateRendererDisplayExt(param_1)
  undefined4 *param_1;
{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  
  puVar5 = _calloc(1,0x1c);
  puVar2 = PTR_FUN_0000f160;
  uVar4 = 0xfffffffd;
  if (puVar5 != (undefined4 *)0x0) {
    puVar5[1] = 0;
    *puVar5 = 0x1020000;
    puVar1 = PTR_FUN_0000f12c;
    uVar4 = 0;
    puVar5[2] = puVar2;
    puVar3 = PTR_FUN_0000f154;
    puVar5[3] = puVar1;
    puVar2 = PTR_FUN_0000f148;
    puVar5[4] = puVar3;
    puVar1 = PTR_DAT_0000f184;
    puVar5[5] = puVar2;
    *(undefined4 **)puVar1 = puVar5;
    *param_1 = puVar5;
  }
  return uVar4;
}

/* _AVACreateRendererDVDExt @ 0x2450 (164 bytes) */
int _AVACreateRendererDVDExt(param_1)
  undefined4 *param_1;
{
  undefined *puVar1;
  undefined *puVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  
  puVar4 = _calloc(1,0x20);
  puVar2 = PTR_FUN_0000f194;
  puVar1 = PTR_FUN_0000f16c;
  uVar3 = 0xfffffffd;
  if (puVar4 != (undefined4 *)0x0) {
    *puVar4 = 0x1020000;
    uVar3 = 0;
    puVar4[2] = puVar2;
    puVar4[4] = puVar1;
    puVar1 = PTR_FUN_0000f164;
    puVar4[3] = PTR_FUN_0000f140;
    puVar4[6] = puVar1;
    puVar4[5] = PTR_FUN_0000f150;
    *param_1 = puVar4;
    *(undefined4 **)PTR_DAT_0000f13c = puVar4;
  }
  return uVar3;
}

/* _AVAGetRendererInfo @ 0x2500 (108 bytes) */
int _AVAGetRendererInfo(param_1)
  undefined4 *param_1;
{
  param_1[5] = 2;
  *param_1 = 0x1020000;
  param_1[3] = 2;
  param_1[4] = 4;
  param_1[2] = param_1[2] | 0x57;
  _strlcpy((char *)(param_1 + 6),"ATIVADriver ",0x100);
  return 0;
}

/* FUN_00002570 @ 0x2570 (936 bytes) */
int FUN_00002570(param_1, param_2, param_3)
  uint param_1;
  undefined4 *param_2;
  uint *param_3;
{
  undefined *puVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar5;
  void *pvVar6;
  uint *puVar7;
  undefined4 local_38;
  uint local_34;
  uint local_30;
  undefined4 local_2c;
  
  if ((param_1 == 0) || (param_2 == (undefined4 *)0x0)) {
    return 0xfffffff9;
  }
  if (*param_3 < 6) {
    uVar4 = _CGDisplayIDToOpenGLDisplayMask(param_3[2]);
    if (((uVar4 & **(uint **)(param_1 + 0xc)) == 0) || ((uVar4 & ~**(uint **)(param_1 + 0xc)) != 0))
    {
      return 0xfffffffb;
    }
    puVar5 = _calloc(1,0x15408);
    puVar1 = PTR_0000f1a0;
    if (puVar5 != (uint *)0x0) {
      iVar2 = *(int *)(*(int *)(param_1 + 0xc) + 4);
      if ((iVar2 == 0) || ((uVar4 & 1) != 0)) {
        uVar3 = 0;
      }
      else {
        uVar3 = 0;
        do {
          uVar3 = uVar3 + 1;
          iVar2 = iVar2 + -1;
          if (iVar2 == 0) break;
        } while ((1 << (uVar3 & 0x3f) & uVar4) == 0);
      }
      uVar4 = *(uint *)(uVar3 * 4 + *(int *)(*(int *)(param_1 + 0xc) + 8));
      puVar5[4] = uVar4;
      *puVar5 = param_3[2];
      puVar5[1] = param_3[3];
      puVar5[2] = param_3[4];
      puVar5[3] = param_3[5];
      puVar5[0x15] = *param_3;
      uVar3 = param_3[1];
      puVar5[6] = 0x4024;
      puVar5[5] = 0;
      puVar5[0x14] = param_1;
      puVar5[0x16] = uVar3;
      iVar2 = _IOServiceOpen(uVar4,*(undefined4 *)puVar1,3,puVar5 + 5);
      if (iVar2 == 0) {
        local_38 = 2;
        iVar2 = _io_connect_method_scalarI_scalarO(puVar5[5],1,0,0,puVar5 + 8,&local_38);
        if (iVar2 == 0) {
          puVar5[0x10] = 0;
          iVar2 = _IOConnectMapMemory(puVar5[5],1,*(undefined4 *)puVar1,puVar5 + 0x10,puVar5 + 0x11,
                                      1);
          if (iVar2 == 0) {
            puVar7 = puVar5 + 0x157;
            _memset(puVar7,0,0x14eac);
            puVar5[0x5155] = 0;
            iVar2 = _IOConnectMapMemory(puVar5[5],4,*(undefined4 *)puVar1,puVar5 + 0x5155,
                                        puVar5 + 0x5156,1);
            if (iVar2 == 0) {
              puVar5[0x5157] = 0;
              iVar2 = _IOConnectMapMemory(puVar5[5],5,*(undefined4 *)puVar1,puVar5 + 0x5157,
                                          puVar5 + 0x5158,1);
              if (iVar2 == 0) {
                puVar5[0x12] = 0;
                iVar2 = _IOConnectMapMemory(puVar5[5],2,*(undefined4 *)puVar1,puVar5 + 0x12,
                                            puVar5 + 0x13,1);
                if ((iVar2 == 0) &&
                   (iVar2 = (**(code **)(*(int *)(param_1 + 0xc) + 0x10))
                                      (puVar5[1],puVar5[2],puVar5[3],puVar5[6] & 0x803f,*puVar5),
                   iVar2 == 0)) {
                  local_34 = puVar5[3];
                  local_2c = 1;
                  local_30 = puVar5[6] & 0xffff4000;
                  iVar2 = _io_connect_method_scalarI_structureI(puVar5[5],0,&local_34,3,0,0);
                  if (iVar2 == 0) {
                    if ((*(uint *)PTR_0000f19c & 8) == 0) {
                      if ((*(uint *)PTR_0000f19c & 0x10) == 0) {
                        puVar5[0x51] = 0x20;
                      }
                      else {
                        puVar5[0x51] = 0x80;
                      }
                    }
                    else {
                      puVar5[0x51] = 0x40;
                    }
                    pvVar6 = _malloc(16000);
                    puVar5[0x54a5] = (uint)pvVar6;
                    if (pvVar6 != (void *)0x0) {
                      puVar5[0x54a7] = (int)pvVar6 + 4000;
                      puVar5[0x2a1] = 0;
                      puVar5[0x54ab] = (int)&UINT_00002ee0 + (int)pvVar6;
                      puVar5[0x54a9] = (int)pvVar6 + 8000;
                      puVar5[0x4d] = 0;
                      puVar5[0x4e] = 0x3f800000;
                      puVar5[0x4b] = 0;
                      iVar2 = 5;
                      puVar5[0x4c] = 0x3f800000;
                      puVar5[0x47] = 0;
                      puVar5[0x48] = 0;
                      puVar5[0x2b1] = 0;
                      do {
                        puVar7[0x14b] = 0;
                        puVar7[0x150] = 0;
                        puVar7[0x155] = 0;
                        puVar7 = puVar7 + 1;
                        iVar2 = iVar2 + -1;
                      } while (iVar2 != 0);
                      FUN_000058b0(puVar5);
                      *param_2 = puVar5;
                      return 0;
                    }
                  }
                }
              }
            }
          }
        }
        _IOServiceClose(puVar5[5]);
      }
      _free(puVar5);
      return 0xffffffff;
    }
  }
  return 0xfffffffd;
}

/* FUN_00002930 @ 0x2930 (132 bytes) */
int FUN_00002930(param_1, param_2, param_3)
  int param_1;
  undefined4 *param_2;
  int param_3;
{
  int iVar1;
  
  if ((int *)param_2[10] != (int *)0x0) {
    iVar1 = *(int *)param_2[10];
    if (iVar1 != 0) {
      _io_connect_method_scalarI_structureI(*(undefined4 *)(param_1 + 0x14),9,iVar1,1,0,0);
    }
    if (param_3 != 0) {
      _free((void *)*param_2);
    }
    _free((void *)param_2[10]);
    param_2[10] = 0;
  }
  return;
}

/* FUN_000029c0 @ 0x29c0 (424 bytes) */
int FUN_000029c0(param_1, param_2)
  int param_1;
  int param_2;
{
  undefined *puVar1;
  uint *puVar2;
  int iVar3;
  int *piVar4;
  
  puVar1 = PTR_0000f1a0;
  piVar4 = *(int **)(param_1 + 0x34);
  if (*(int **)(param_1 + 0x38) <= piVar4 + 8) {
    puVar2 = *(uint **)(param_1 + 0x30);
    *puVar2 = (int)piVar4 - (int)puVar2 >> 2 | *puVar2;
    *(undefined4 **)(param_1 + 0x30) = *(undefined4 **)(param_1 + 0x34);
    **(undefined4 **)(param_1 + 0x34) = 0x1000000;
    _IOConnectMapMemory(*(undefined4 *)(param_1 + 0x14),1,*(undefined4 *)puVar1,param_1 + 0x40,
                        param_1 + 0x44,1);
    iVar3 = *(int *)(param_1 + 0x40);
    *(int *)(param_1 + 0x34) = iVar3 + 0x20;
    *(int *)(param_1 + 0x30) = iVar3 + 0x1c;
    *(int *)(param_1 + 0x38) = iVar3 + 0x20 + *(int *)(iVar3 + 0x10) * 4;
    *(undefined4 *)(iVar3 + 0x1c) = 0;
    piVar4 = *(int **)(param_1 + 0x34);
  }
  puVar2 = *(uint **)(param_1 + 0x30);
  *(int **)(param_1 + 0x34) = piVar4 + 8;
  iVar3 = 7;
  *puVar2 = (int)piVar4 - (int)puVar2 >> 2 | *puVar2;
  *(int **)(param_1 + 0x30) = piVar4;
  *piVar4 = param_2 * 0x1000000 + 0x2b000000;
  do {
    piVar4 = piVar4 + 1;
    *piVar4 = -0x80000000;
    puVar1 = PTR_0000f1a0;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  puVar2 = *(uint **)(param_1 + 0x30);
  *puVar2 = *(int *)(param_1 + 0x34) - (int)puVar2 >> 2 | *puVar2;
  *(undefined4 **)(param_1 + 0x30) = *(undefined4 **)(param_1 + 0x34);
  **(undefined4 **)(param_1 + 0x34) = 0x1000000;
  _IOConnectMapMemory(*(undefined4 *)(param_1 + 0x14),1,*(undefined4 *)puVar1,param_1 + 0x40,
                      param_1 + 0x44,1);
  iVar3 = *(int *)(param_1 + 0x40);
  *(int *)(param_1 + 0x34) = iVar3 + 0x20;
  *(int *)(param_1 + 0x30) = iVar3 + 0x1c;
  *(int *)(param_1 + 0x38) = iVar3 + 0x20 + *(int *)(iVar3 + 0x10) * 4;
  *(undefined4 *)(iVar3 + 0x1c) = 0;
  return;
}

/* FUN_00002b70 @ 0x2b70 (244 bytes) */
int FUN_00002b70(param_1)
  void *param_1;
{
  bool bVar1;
  undefined4 uVar2;
  void *pvVar3;
  int iVar4;
  uint uVar5;
  undefined4 *puVar6;
  
  uVar2 = 0xfffffff9;
  if (param_1 != (void *)0x0) {
    iVar4 = 0;
    puVar6 = (undefined4 *)((int)param_1 + 0x14430);
    do {
      pvVar3 = (void *)*puVar6;
      puVar6 = puVar6 + 3;
      _free(pvVar3);
      bVar1 = iVar4 != 0x18;
      iVar4 = iVar4 + 1;
    } while (bVar1);
    _free(*(void **)((int)param_1 + 0x15294));
    if (*(int *)((int)param_1 + 0x54) != 0) {
      iVar4 = (int)param_1 + 0x814;
      uVar5 = 0;
      do {
        uVar5 = uVar5 + 1;
        ((int (*)())FUN_00002930)(param_1,iVar4,1);
        iVar4 = iVar4 + 100;
      } while (uVar5 < *(uint *)((int)param_1 + 0x54));
    }
    ((int (*)())FUN_000029c0)(param_1,0);
    ((int (*)())FUN_00002930)(param_1,(int)param_1 + 0x1518c,1);
    ((int (*)())FUN_000029c0)(param_1,1);
    ((int (*)())FUN_00002930)(param_1,(int)param_1 + 0x15394,1);
    _IOServiceClose(*(undefined4 *)((int)param_1 + 0x14));
    _free(param_1);
    uVar2 = 0;
  }
  return uVar2;
}

/* FUN_00002c70 @ 0x2c70 (132 bytes) */
int FUN_00002c70(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  uint param_3;
{
  int iVar1;
  int local_28 [3];
  undefined4 local_1c;
  
  local_28[1] = 1;
  if (param_3 < 10000) {
    iVar1 = param_3 * 8 + param_1 + 0x55c;
    local_28[2] = *(undefined4 *)(iVar1 + 0x56c);
    local_1c = *(undefined4 *)(iVar1 + 0x570);
    _io_connect_method_scalarI_scalarO
              (*(undefined4 *)(param_1 + 0x14),0x14,local_28 + 2,2,local_28,local_28 + 1);
    if (local_28[0] != 1) {
      return 0;
    }
  }
  return 1;
}

/* FUN_00002d00 @ 0x2d00 (120 bytes) */
int FUN_00002d00(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  uint param_3;
{
  int iVar1;
  undefined4 local_28;
  undefined4 local_24;
  
  if (param_3 < 10000) {
    iVar1 = param_3 * 8 + param_1 + 0x55c;
    local_28 = *(undefined4 *)(iVar1 + 0x56c);
    local_24 = *(undefined4 *)(iVar1 + 0x570);
    iVar1 = _io_connect_method_scalarI_structureI
                      (*(undefined4 *)(param_1 + 0x14),0x13,&local_28,2,0,0);
    if (iVar1 == 0) {
      return 0;
    }
  }
  return 0xfffffff9;
}

/* FUN_00002d80 @ 0x2d80 (64 bytes) */
int FUN_00002d80(param_1, param_2, param_3)
  int param_1;
  int param_2;
  undefined4 *param_3;
{
  if (param_2 == 3) {
    *param_3 = 4;
    return 0;
  }
  if (param_2 != 4) {
    *param_3 = 0;
    return 0xfffffff9;
  }
  *param_3 = *(undefined4 *)(param_1 + 0x120);
  return 0;
}

/* FUN_00002dc0 @ 0x2dc0 (68 bytes) */
int FUN_00002dc0(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  undefined4 uVar1;
  
  uVar1 = 0xfffffff9;
  if (param_2 == 4) {
    *(int *)(param_1 + 0x120) = param_3;
    uVar1 = 0;
    if (param_3 == 4) {
      FUN_0000bfc0();
      uVar1 = 0;
    }
  }
  return uVar1;
}

/* FUN_00002e10 @ 0x2e10 (64 bytes) */
int FUN_00002e10(param_1, param_2, param_3)
  int param_1;
  int param_2;
  undefined4 *param_3;
{
  if (param_2 == 3) {
    *param_3 = 4;
    return 0;
  }
  if (param_2 != 4) {
    *param_3 = 0;
    return 0xfffffff9;
  }
  *param_3 = *(undefined4 *)(param_1 + 0x120);
  return 0;
}

/* FUN_00002e50 @ 0x2e50 (1144 bytes) */
int FUN_00002e50(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  float *param_3;
{
  float fVar1;
  float fVar2;
  float fVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  bool bVar7;
  double dVar8;
  undefined4 local_148;
  undefined4 local_144;
  uint local_140;
  undefined4 local_13c;
  undefined4 local_138;
  uint local_134;
  undefined1 auStack_130 [284];
  
  fVar2 = FLOAT_0000d440;
  fVar1 = FLOAT_0000d438;
  fVar3 = FLOAT_0000d430;
  switch(param_2) {
  case 4:
    dVar8 = (double)*(float *)(param_1 + 300);
    uVar6 = 0;
    fVar1 = *(float *)(param_1 + 0x134);
    uVar4 = *(uint *)(param_1 + 0x11c) | 1;
    *(float *)(param_1 + 0x120) = *param_3;
    *(uint *)(param_1 + 0x11c) = uVar4;
    break;
  default:
    dVar8 = (double)*(float *)(param_1 + 300);
    fVar1 = *(float *)(param_1 + 0x134);
    uVar6 = 0xfffffffb;
    uVar4 = *(uint *)(param_1 + 0x11c);
    break;
  case 0x17:
    bVar7 = (double)*param_3 < DOUBLE_0000d408;
    *(float *)(param_1 + 300) = *param_3;
    if (bVar7) {
      *(float *)(param_1 + 300) = FLOAT_0000d428;
    }
    dVar8 = (double)*(float *)(param_1 + 300);
    if (dVar8 <= DOUBLE_0000d410) {
LAB_00003100:
      fVar1 = *(float *)(param_1 + 0x134);
LAB_00003104:
      uVar4 = *(uint *)(param_1 + 0x11c);
      uVar6 = 0;
    }
    else {
      fVar1 = *(float *)(param_1 + 0x134);
      uVar6 = 0;
      dVar8 = (double)FLOAT_0000d42c;
      uVar4 = *(uint *)(param_1 + 0x11c);
      *(float *)(param_1 + 300) = FLOAT_0000d42c;
    }
    break;
  case 0x18:
    fVar1 = *param_3;
    *(float *)(param_1 + 0x130) = fVar1;
    if (fVar1 < fVar3) {
      *(float *)(param_1 + 0x130) = fVar3;
    }
    if (*(float *)(param_1 + 0x130) <= FLOAT_0000d434) {
      dVar8 = (double)*(float *)(param_1 + 300);
      fVar1 = *(float *)(param_1 + 0x134);
      goto LAB_00003104;
    }
    dVar8 = (double)*(float *)(param_1 + 300);
    fVar1 = *(float *)(param_1 + 0x134);
    uVar6 = 0;
    uVar4 = *(uint *)(param_1 + 0x11c);
    *(float *)(param_1 + 0x130) = FLOAT_0000d434;
    break;
  case 0x19:
    fVar3 = *param_3;
    *(float *)(param_1 + 0x134) = fVar3;
    if (fVar3 < fVar1) {
      *(float *)(param_1 + 0x134) = fVar1;
    }
    fVar1 = FLOAT_0000d43c;
    if (*(float *)(param_1 + 0x134) <= FLOAT_0000d43c) {
      dVar8 = (double)*(float *)(param_1 + 300);
      fVar1 = *(float *)(param_1 + 0x134);
      goto LAB_00003104;
    }
    dVar8 = (double)*(float *)(param_1 + 300);
    uVar4 = *(uint *)(param_1 + 0x11c);
    uVar6 = 0;
    *(float *)(param_1 + 0x134) = FLOAT_0000d43c;
    break;
  case 0x1a:
    fVar3 = *param_3;
    *(float *)(param_1 + 0x138) = fVar3;
    if (fVar3 < fVar2) {
      *(float *)(param_1 + 0x138) = fVar2;
    }
    if (*(float *)(param_1 + 0x138) <= FLOAT_0000d444) {
      dVar8 = (double)*(float *)(param_1 + 300);
      goto LAB_00003100;
    }
    dVar8 = (double)*(float *)(param_1 + 300);
    fVar1 = *(float *)(param_1 + 0x134);
    uVar6 = 0;
    uVar4 = *(uint *)(param_1 + 0x11c);
    *(float *)(param_1 + 0x138) = FLOAT_0000d444;
    break;
  case 0x1b:
    uVar6 = 0;
    FUN_00004740(param_1,(int)SUB41(*param_3,0),(int)(char)*(undefined4 *)(param_1 + 0x114),
                 param_1 + 0x10c,*(undefined4 *)(param_1 + 0x118));
    dVar8 = (double)*(float *)(param_1 + 300);
    fVar1 = *(float *)(param_1 + 0x134);
    uVar4 = *(uint *)(param_1 + 0x11c);
    break;
  case 0x1c:
    *(short *)(param_1 + 0x124) = SUB42(*param_3,0);
    fVar3 = param_3[1];
    if ((uint)*(float *)(param_1 + 0x57c) < (uint)param_3[1]) {
      fVar3 = *(float *)(param_1 + 0x57c);
    }
    *(short *)(param_1 + 0x128) = SUB42(fVar3,0);
    *(short *)(param_1 + 0x126) = SUB42(param_3[2],0);
    fVar3 = param_3[3];
    if ((uint)*(float *)(param_1 + 0x578) < (uint)param_3[3]) {
      fVar3 = *(float *)(param_1 + 0x578);
    }
    dVar8 = (double)*(float *)(param_1 + 300);
    fVar1 = *(float *)(param_1 + 0x134);
    uVar6 = 0;
    uVar4 = *(uint *)(param_1 + 0x11c);
    *(short *)(param_1 + 0x12a) = SUB42(fVar3,0);
  }
  if ((fVar1 == FLOAT_0000d430) && (*(float *)(param_1 + 0x138) == FLOAT_0000d43c)) {
    uVar4 = uVar4 & 0xfffffffd;
    *(uint *)(param_1 + 0x11c) = uVar4;
  }
  else {
    uVar4 = uVar4 | 2;
    *(uint *)(param_1 + 0x11c) = uVar4;
  }
  if (((dVar8 == (double)FLOAT_0000d430) && (*(float *)(param_1 + 0x138) == FLOAT_0000d43c)) &&
     (*(float *)(param_1 + 0x130) == FLOAT_0000d43c)) {
    uVar4 = uVar4 & 0xfffffffb;
    *(uint *)(param_1 + 0x11c) = uVar4;
  }
  else {
    uVar4 = uVar4 | 4;
    *(uint *)(param_1 + 0x11c) = uVar4;
  }
  if ((uVar4 & 1) == 0) {
    if ((uVar4 & 2) == 0) {
      if ((uVar4 & 4) == 0) goto LAB_00003310;
      local_134 = *(uint *)(param_1 + 0xa84);
      goto LAB_00003220;
    }
    local_134 = *(uint *)(param_1 + 0xa84);
LAB_00003248:
    local_134 = local_134 | 0x80000;
    *(uint *)(param_1 + 0xa84) = local_134;
  }
  else {
    local_148 = 0;
    local_144 = 1;
    iVar5 = _io_connect_method_scalarI_scalarO
                      (*(undefined4 *)(param_1 + 0x14),0x11,&local_144,1,0,&local_148);
    if (iVar5 != 0) {
      return 0xfffffffb;
    }
    local_134 = *(uint *)(param_1 + 0xa84) | 0x8000;
    *(uint *)(param_1 + 0xa84) = local_134;
    uVar4 = *(uint *)(param_1 + 0x11c);
LAB_00003220:
    if (((uVar4 & 2) != 0) || ((uVar4 & 4) != 0)) goto LAB_00003248;
  }
  local_13c = *(undefined4 *)(param_1 + 0x57c);
  local_140 = *(undefined4 *)(param_1 + 0x578);
  local_138 = 0;
  local_148 = 0;
  local_144 = 0;
  iVar5 = _io_connect_method_scalarI_scalarO
                    (*(undefined4 *)(param_1 + 0x14),0x15,&local_144,5,0,&local_148);
  if (iVar5 == 0) {
    local_144 = *(undefined4 *)(param_1 + 0xc);
    local_140 = *(uint *)(param_1 + 0x18) & 0xffff4000;
    local_13c = 1;
    iVar5 = _io_connect_method_scalarI_structureI
                      (*(undefined4 *)(param_1 + 0x14),0,&local_144,3,0,0);
    if (iVar5 == 0) {
      local_148 = 0x100;
      iVar5 = _io_connect_method_scalarI_structureO
                        (*(undefined4 *)(param_1 + 0x14),4,&local_144,1,auStack_130,&local_148);
      if (iVar5 == 0) {
LAB_00003310:
        if (*(int *)(param_1 + 0x120) == 4) {
          FUN_0000bfc0(param_1);
          return uVar6;
        }
        return uVar6;
      }
    }
  }
  return 0xfffffffb;
}

/* FUN_00003350 @ 0x3350 (720 bytes) */
int FUN_00003350(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int param_1;
  uint *param_2;
  undefined4 param_3;
  uint param_4;
  uint param_5;
  uint param_6;
  uint param_7;
{
  bool bVar1;
  undefined4 uVar2;
  uint uVar3;
  void *pvVar4;
  uint uVar5;
  void *pvVar6;
  int iVar7;
  uint uVar8;
  undefined4 local_48;
  undefined4 local_44;
  uint local_40;
  int local_3c;
  
  if (param_2 == (uint *)0x0) {
    return 0xfffffff9;
  }
  pvVar4 = _calloc(1,0x34);
  if (pvVar4 == (void *)0x0) {
    return 0xfffffffd;
  }
  if (param_6 == 0x61723135) {
    uVar2 = 0xb;
  }
  else if (param_6 < 0x61723136) {
    if (param_6 == 0x20) {
LAB_00003450:
      *(undefined4 *)((int)pvVar4 + 0x24) = 4;
      *(undefined4 *)((int)pvVar4 + 0x28) = 2;
      *(undefined4 *)((int)pvVar4 + 0x2c) = 0xc;
      *(undefined4 *)((int)pvVar4 + 0x30) = 2;
      goto LAB_000034b4;
    }
    if (param_6 != 0x32767579) {
      if (param_6 != 8) {
        return 0xfffffff9;
      }
      *(undefined4 *)((int)pvVar4 + 0x28) = 0;
      *(undefined4 *)((int)pvVar4 + 0x24) = 1;
      *(undefined4 *)((int)pvVar4 + 0x2c) = 0;
      *(undefined4 *)((int)pvVar4 + 0x30) = 0;
      goto LAB_000034b4;
    }
    uVar2 = 0x14;
  }
  else {
    if (param_6 == 0x72676261) {
      *(undefined4 *)((int)pvVar4 + 0x2c) = 0xc;
      *(undefined4 *)((int)pvVar4 + 0x24) = 4;
      *(undefined4 *)((int)pvVar4 + 0x30) = 0;
      *(undefined4 *)((int)pvVar4 + 0x28) = 2;
      goto LAB_000034b4;
    }
    if (param_6 != 0x79757673) {
      if (param_6 != 0x61726762) {
        return 0xfffffff9;
      }
      goto LAB_00003450;
    }
    uVar2 = 0x15;
  }
  *(undefined4 *)((int)pvVar4 + 0x2c) = uVar2;
  *(undefined4 *)((int)pvVar4 + 0x24) = 2;
  *(undefined4 *)((int)pvVar4 + 0x30) = 0;
  *(undefined4 *)((int)pvVar4 + 0x28) = 1;
LAB_000034b4:
  bVar1 = param_7 != 0;
  param_2[5] = param_5;
  param_2[4] = param_4;
  *param_2 = 0;
  if (bVar1) {
    uVar8 = *(uint *)((int)pvVar4 + 0x24);
    param_2[6] = param_4 * uVar8;
  }
  else {
    uVar8 = *(uint *)((int)pvVar4 + 0x24);
    param_2[6] = param_4 * uVar8 + 0xff & 0xffffff00;
  }
  param_2[1] = param_6;
  *(undefined4 *)((int)pvVar4 + 4) = *(undefined4 *)(param_1 + 0xc);
  uVar5 = param_2[6];
  *(undefined2 *)((int)pvVar4 + 10) = 0;
  *(undefined2 *)((int)pvVar4 + 8) = 0;
  *(uint *)((int)pvVar4 + 0x18) = uVar5 / uVar8;
  uVar3 = param_2[4];
  *(short *)((int)pvVar4 + 0xc) = (short)uVar3;
  uVar8 = param_2[5];
  *(uint *)((int)pvVar4 + 0x10) = uVar3;
  *(short *)((int)pvVar4 + 0xe) = (short)uVar8;
  *(uint *)((int)pvVar4 + 0x14) = uVar8;
  if (bVar1) {
    *param_2 = param_7;
  }
  else {
    pvVar6 = _malloc(uVar8 * uVar5 + 0x100);
    *param_2 = (uint)pvVar6;
    if (pvVar6 == (void *)0x0) {
      _free(pvVar4);
      return 0xfffffffd;
    }
    uVar5 = param_2[6];
    uVar8 = param_2[5];
  }
  local_44 = 0;
  if (bVar1) {
    local_40 = *param_2;
  }
  else {
    local_40 = *param_2 + 0xff & 0xffffff00;
  }
  local_3c = uVar8 * uVar5;
  local_48 = 1;
  iVar7 = _io_connect_method_scalarI_scalarO
                    (*(undefined4 *)(param_1 + 0x14),8,&local_44,3,pvVar4,&local_48);
  if (iVar7 == 0) {
    if ((*(uint *)(param_1 + 0x20) & 0x82) != 0) {
      param_2[9] = 1;
    }
    param_2[10] = (uint)pvVar4;
    uVar2 = 0;
  }
  else {
    _free(pvVar4);
    _free((void *)*param_2);
    uVar2 = 0xfffffffd;
  }
  return uVar2;
}

/* FUN_00003630 @ 0x3630 (356 bytes) */
int FUN_00003630(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  int param_3;
{
  uint uVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  iVar5 = param_1 + 0x55c;
  iVar6 = *(int *)(param_1 + 0x54);
  uVar3 = 0xfffffff9;
  if (iVar6 == param_3) {
    if (iVar6 != 0) {
      iVar8 = 0;
      iVar7 = iVar5;
      do {
        puVar2 = (undefined4 *)param_2[iVar8];
        iVar4 = ((int (*)())FUN_00003350)(param_1,param_1 + 0x814 + iVar8 * 100,*(undefined4 *)(iVar7 + 0x4ac),
                             *puVar2,puVar2[1],puVar2[3],0);
        if (iVar4 != 0) {
          if (0 < iVar8) {
            iVar6 = 0;
            iVar5 = param_1 + 0x814;
            do {
              iVar6 = iVar6 + 1;
              ((int (*)())FUN_00002930)(param_1,iVar5,1);
              iVar5 = iVar5 + 100;
            } while (iVar6 != iVar8);
          }
          return 0xfffffffd;
        }
        iVar8 = iVar8 + 1;
        iVar7 = iVar7 + 4;
        iVar4 = iVar5;
      } while (iVar8 != iVar6);
      do {
        *(undefined4 *)(iVar4 + 0x178) = *(undefined4 *)*param_2;
        *(undefined4 *)(iVar4 + 0x17c) = *(undefined4 *)(*param_2 + 4);
        uVar3 = *(undefined4 *)(iVar5 + 0x2d0);
        *(undefined4 *)(iVar4 + 0x180) = uVar3;
        *(undefined4 *)(iVar4 + 0x184) = *(undefined4 *)(*param_2 + 0xc);
        iVar6 = *(int *)(iVar5 + 0x2b8);
        *(undefined4 *)(iVar4 + 0x194) = 1;
        iVar5 = iVar5 + 100;
        uVar1 = iVar6 + 0xffU & 0xffffff00;
        *(uint *)(iVar4 + 400) = uVar1;
        iVar4 = iVar4 + 0x40;
        *(undefined4 *)(*param_2 + 8) = uVar3;
        iVar6 = *param_2;
        param_2 = param_2 + 1;
        *(uint *)(iVar6 + 0x18) = uVar1;
        iVar8 = iVar8 + -1;
      } while (iVar8 != 0);
    }
    uVar3 = 0;
  }
  return uVar3;
}

/* FUN_000037b0 @ 0x37b0 (124 bytes) */
int FUN_000037b0(param_1, param_2)
  int param_1;
  int *param_2;
{
  undefined4 *puVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  undefined4 uVar8;
  
  iVar7 = param_1 + 0x55c;
  if (*(int *)(param_1 + 0x54) != 0) {
    uVar2 = 0;
    do {
      puVar1 = (undefined4 *)(iVar7 + 0x38);
      uVar2 = uVar2 + 1;
      uVar8 = *(undefined4 *)(iVar7 + 0x3c);
      uVar6 = *(undefined4 *)(iVar7 + 0x40);
      uVar4 = *(undefined4 *)(iVar7 + 0x44);
      uVar3 = *(undefined4 *)(iVar7 + 0x54);
      iVar7 = iVar7 + 0x40;
      *(undefined4 *)*param_2 = *puVar1;
      *(undefined4 *)(*param_2 + 4) = uVar8;
      *(undefined4 *)(*param_2 + 8) = uVar6;
      *(undefined4 *)(*param_2 + 0xc) = uVar4;
      iVar5 = *param_2;
      param_2 = param_2 + 1;
      *(undefined4 *)(iVar5 + 0x1c) = uVar3;
    } while (uVar2 < *(uint *)(param_1 + 0x54));
  }
  return 0;
}

/* FUN_00003830 @ 0x3830 (136 bytes) */
int FUN_00003830(param_1, param_2)
  int param_1;
  int *param_2;
{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  undefined4 uVar8;
  uint uVar9;
  
  iVar7 = param_1 + 0x55c;
  if (*(int *)(param_1 + 0x54) != 0) {
    uVar9 = 0;
    do {
      puVar1 = (undefined4 *)(iVar7 + 0x178);
      uVar9 = uVar9 + 1;
      uVar8 = *(undefined4 *)(iVar7 + 0x17c);
      uVar6 = *(undefined4 *)(iVar7 + 0x180);
      uVar5 = *(undefined4 *)(iVar7 + 0x184);
      uVar4 = *(undefined4 *)(iVar7 + 400);
      uVar3 = *(undefined4 *)(iVar7 + 0x194);
      iVar7 = iVar7 + 0x40;
      *(undefined4 *)*param_2 = *puVar1;
      *(undefined4 *)(*param_2 + 4) = uVar8;
      *(undefined4 *)(*param_2 + 8) = uVar6;
      *(undefined4 *)(*param_2 + 0xc) = uVar5;
      *(undefined4 *)(*param_2 + 0x18) = uVar4;
      iVar2 = *param_2;
      param_2 = param_2 + 1;
      *(undefined4 *)(iVar2 + 0x1c) = uVar3;
    } while (uVar9 < *(uint *)(param_1 + 0x54));
  }
  return 0;
}

/* FUN_000038c0 @ 0x38c0 (100 bytes) */
int FUN_000038c0(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 *param_4;
{
  undefined4 uVar1;
  
  *(undefined4 *)(*(int *)(param_1 + 0xac4) * 8 + param_1 + 0x55c + 0x56c) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0xac4) * 8 + param_1 + 0x55c + 0x570) = 0;
  uVar1 = *(undefined4 *)(param_1 + 0xac4);
  *param_4 = 0;
  param_4[1] = uVar1;
  *(uint *)(param_1 + 0xac4) = (*(int *)(param_1 + 0xac4) + 1U) % 10000;
  return 0;
}

