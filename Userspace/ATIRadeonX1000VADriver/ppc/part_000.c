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
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
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
  uVar1 = ((int (*)())FUN_000010a0)("__dyld_NSAddressOfSymbol",local_24);
  if ((((local_34 != (code *)0x0) && (local_30 != (code *)0x0)) && (local_2c != (code *)0x0)) &&
     ((local_28 != (code *)0x0 && (local_24[0] != (code *)0x0)))) {
    uVar2 = (*local_34)(uVar1);
    for (local_38 = 0; local_38 < uVar2; local_38 = local_38 + 1) {
      uVar1 = (*local_30)(local_38);
      iVar3 = _strcmp(uVar1,"/usr/lib/libSystem.B.dylib");
      if (iVar3 == 0) {
        iVar3 = (*local_2c)(local_38);
        if (iVar3 == 0) {
          return 0;
        }
        iVar3 = (*local_28)(iVar3,"_atexit",4);
        if (iVar3 != 0) {
          uVar1 = (*local_24[0])(iVar3);
          return uVar1;
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
  int local_20;
  int local_18;
  
  local_20 = __keymgr_get_and_lock_processwide_ptr(0xe);
  if ((local_20 == 0) && (local_20 = _calloc(0x14,1), local_20 == 0)) {
    return 0;
  }
  if (*(char *)(local_20 + 3) == '\0') {
    iVar1 = _dlopen("/usr/lib/libSystem.B.dylib",0x10);
    if (iVar1 == 0) {
      *(undefined1 *)(local_20 + 3) = 1;
      uVar2 = ((int (*)())FUN_0000122c)();
      *(undefined4 *)(local_20 + 0x10) = uVar2;
      if ((*(int *)(local_20 + 0x10) != 0) &&
         (iVar1 = (**(code **)(local_20 + 0x10))(FUN_00001bbc), iVar1 == 0)) goto LAB_00001638;
    }
    else {
      uVar2 = _dlsym(iVar1,"__cxa_atexit");
      *(undefined4 *)(local_20 + 8) = uVar2;
      uVar2 = _dlsym(iVar1,"__cxa_finalize");
      *(undefined4 *)(local_20 + 0xc) = uVar2;
      if (((*(int *)(local_20 + 8) != 0) && (*(int *)(local_20 + 0xc) != 0)) &&
         (iVar3 = ((int (*)())FUN_00001160)(*(undefined4 *)(local_20 + 8),*(undefined4 *)(local_20 + 0xc)),
         iVar3 != -1)) {
        if (iVar3 == 0) {
          *(undefined1 *)(local_20 + 3) = 2;
        }
        else {
          uVar2 = _dlsym(iVar1,"atexit");
          *(undefined4 *)(local_20 + 0x10) = uVar2;
          if (*(int *)(local_20 + 0x10) == 0) goto LAB_00001644;
          *(undefined1 *)(local_20 + 3) = 0x10;
        }
        goto LAB_00001638;
      }
    }
LAB_00001644:
    __keymgr_set_and_unlock_processwide_ptr(0xe,local_20);
    local_18 = 0;
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
  puVar2 = (undefined4 *)_malloc(0x10);
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
  undefined4 a0;
  undefined4 a1;
  undefined4 in_r5;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
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
    a0 = __keymgr_set_and_unlock_processwide_ptr(0xe,iStack00000018);
    if ((uint)puVar1[2] < 6) {
      uVar2 = 1 << (puVar1[2] & 0x3f);
      if ((uVar2 & 0x15) == 0) {
        if ((uVar2 & 0x2a) != 0) {
          (*(code *)puVar1[1])(puVar1[3],a1,in_r5,in_r6,in_r7,in_r8,(code *)puVar1[1]);
        }
      }
      else {
        (*(code *)puVar1[1])(a0);
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
  undefined4 a0;
  undefined4 extraout_r4;
  undefined4 extraout_r4_00;
  undefined4 a1;
  undefined4 in_r5;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  undefined4 *puStack00000018;
  undefined1 local_28;
  undefined4 local_24;
  int local_20;
  
  local_24 = 0;
  local_28 = 0;
  puStack00000018 = param_1;
  local_20 = __keymgr_get_and_lock_processwide_ptr(0xe);
  a0 = 0;
  a1 = extraout_r4;
  if (local_20 != 0) {
    local_28 = *(undefined1 *)(local_20 + 2);
    *(undefined1 *)(local_20 + 2) = 1;
    local_24 = *(undefined4 *)(local_20 + 4);
    a0 = __keymgr_set_and_unlock_processwide_ptr(0xe,local_20);
    a1 = extraout_r4_00;
  }
  if (param_1[1] == 0) {
    (*(code *)*param_1)(a0);
  }
  else {
    (*(code *)*param_1)(param_1[2],a1,in_r5,in_r6,in_r7,in_r8,(code *)*param_1);
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
int FUN_00001b5c(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  ((int (*)())FUN_000018a0)(param_1,param_2);
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
  undefined4 *a1;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  undefined4 uVar4;
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
        a1 = (undefined4 *)_malloc(0xc);
        if (a1 == (undefined4 *)0x0) {
          local_18 = 0xffffffff;
        }
        else {
          uVar4 = puStack00000018[1];
          uVar2 = puStack00000018[2];
          *a1 = *puStack00000018;
          a1[1] = uVar4;
          a1[2] = uVar2;
          local_18 = (*pcVar1)(FUN_00001a24,a1,uStack0000001c,in_r6,in_r7,in_r8,a1);
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
        local_18 = (*pcVar1)(*puStack00000018,puStack00000018[2],uStack0000001c,in_r6,in_r7,in_r8,
                             *puStack00000018);
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
int FUN_00002058(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  ((int (*)())FUN_00001cd8)(param_1,param_2);
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
int FUN_000020d4(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  ((int (*)())FUN_00001cd8)(param_1,param_2);
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
          fnTableB = PTR_FUN_0000f190;
          fnTableA = PTR_FUN_0000f168;
          bit = bit + 1;
        } while ((int)bit < 0x20);
        renderer[0xc] = 0;
        renderer[4] = fnTableB;
        renderer[5] = fnTableA;
        fnTableA = PTR_FUN_0000f15c;
        renderer[6] = PTR_FUN_0000f180;
        renderer[7] = fnTableA;
        fnTableA = PTR_FUN_0000f130;
        renderer[8] = PTR_FUN_0000f198;
        renderer[9] = fnTableA;
        fnTableA = PTR_FUN_0000f188;
        renderer[10] = PTR_FUN_0000f178;
        renderer[0xb] = fnTableA;
        fnTableA = PTR_FUN_0000f174;
        renderer[0xd] = PTR_FUN_0000f144;
        renderer[0xe] = fnTableA;
        fnTableA = PTR_FUN_0000f158;
        renderer[0xf] = PTR_FUN_0000f138;
        renderer[0x10] = fnTableA;
        fnTableA = PTR_FUN_0000f170;
        renderer[0x11] = PTR_FUN_0000f14c;
        renderer[0x12] = fnTableA;
        fnTableA = PTR_FUN_0000f17c;
        renderer[0x13] = PTR_FUN_0000f134;
        renderer[0x14] = fnTableA;
        renderer[0x15] = PTR_FUN_0000f18c;
        renderer[0x16] = FUN_00002340;
        *outRenderer = renderer;
        return 0;
      }
    }
    status = 0xfffffffd;
  }
  return status;
}

/* FUN_00002340 @ 0x2340 (108 bytes) */
int FUN_00002340(renderer)
  int renderer;
{
  undefined4 status;
  
  status = 0xfffffff9;
  if (renderer != 0) {
    _free(*(undefined4 *)PTR_DAT_0000f13c);
    _free(*(undefined4 *)PTR_DAT_0000f184);
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
  fnTmp2 = PTR_FUN_0000f160;
  status = 0xfffffffd;
  if (ext != (undefined4 *)0x0) {
    ext[1] = 0;
    *ext = 0x1020000;
    fnTmp1 = PTR_FUN_0000f12c;
    status = 0;
    ext[2] = fnTmp2;
    fnTmp3 = PTR_FUN_0000f154;
    ext[3] = fnTmp1;
    fnTmp2 = PTR_FUN_0000f148;
    ext[4] = fnTmp3;
    fnTmp1 = PTR_DAT_0000f184;
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
  fnTmp2 = PTR_FUN_0000f194;
  fnTmp1 = PTR_FUN_0000f16c;
  status = 0xfffffffd;
  if (ext != (undefined4 *)0x0) {
    *ext = 0x1020000;
    status = 0;
    ext[2] = fnTmp2;
    ext[4] = fnTmp1;
    fnTmp1 = PTR_FUN_0000f164;
    ext[3] = PTR_FUN_0000f140;
    ext[6] = fnTmp1;
    ext[5] = PTR_FUN_0000f150;
    *outExt = ext;
    *(undefined4 **)PTR_DAT_0000f13c = ext;
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

/* FUN_00002570 @ 0x2570 (936 bytes) */
int FUN_00002570(renderer, outContext, createInfo)
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
    kernelTask = PTR_0000f1a0;
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
                    if ((*(uint *)PTR_0000f19c & 8) == 0) {
                      if ((*(uint *)PTR_0000f19c & 0x10) == 0) {
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
                      FUN_000058b0(ctx);
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

/* FUN_00002930 @ 0x2930 (132 bytes) */
int FUN_00002930(ctx, mapping, freeBacking)
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

/* FUN_000029c0 @ 0x29c0 (424 bytes) */
int FUN_000029c0(ctx, opcodeIndex)
  int ctx;
  int opcodeIndex;
{
  undefined *kernelTask;
  uint *lastHeader;
  int count;
  int *writePtr;
  
  kernelTask = PTR_0000f1a0;
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
    kernelTask = PTR_0000f1a0;
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

/* FUN_00002b70 @ 0x2b70 (244 bytes) */
int FUN_00002b70(ctx)
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
        ((int (*)())FUN_00002930)(ctx,cursor,1);
        cursor = cursor + 100;
      } while (mappingIndex < *(uint *)(ctx + 0x54));
    }
    ((int (*)())FUN_000029c0)(ctx,0);
    ((int (*)())FUN_00002930)(ctx,ctx + 0x1518c,1);
    ((int (*)())FUN_000029c0)(ctx,1);
    ((int (*)())FUN_00002930)(ctx,ctx + 0x15394,1);
    _IOServiceClose(*(undefined4 *)(ctx + 0x14));
    _free(ctx);
    status = 0;
  }
  return status;
}

/* FUN_00002c70 @ 0x2c70 (132 bytes) */
int FUN_00002c70(ctx, param_2, slot)
  int ctx;
  undefined4 param_2;
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

/* FUN_00002d00 @ 0x2d00 (120 bytes) */
int FUN_00002d00(ctx, param_2, slot)
  int ctx;
  undefined4 param_2;
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

/* FUN_00002d80 @ 0x2d80 (64 bytes) */
int FUN_00002d80(ctx, property, outValue)
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

/* FUN_00002dc0 @ 0x2dc0 (68 bytes) */
int FUN_00002dc0(ctx, property, value)
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
      FUN_0000bfc0(ctx);
      status = 0;
    }
  }
  return status;
}

/* FUN_00002e10 @ 0x2e10 (64 bytes) */
int FUN_00002e10(ctx, property, outValue)
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

/* FUN_00002e50 @ 0x2e50 (1144 bytes) */
int FUN_00002e50(ctx, attribute, value)
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
LAB_00003100:
      brightness = *(float *)(ctx + 0x134);
LAB_00003104:
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
      goto LAB_00003104;
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
      goto LAB_00003104;
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
      goto LAB_00003100;
    }
    hue = *(float *)(ctx + 300);
    brightness = *(float *)(ctx + 0x134);
    status = 0;
    flags = *(uint *)(ctx + 0x11c);
    *(float *)(ctx + 0x138) = 4.0;
    break;
  case 0x1b:
    status = 0;
    FUN_00004740(ctx,(int)GH_F2U((float)(SUB41(*value,0))),(int)(char)*(undefined4 *)(ctx + 0x114),
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
      if ((flags & 4) == 0) goto LAB_00003310;
      controlWord = *(uint *)(ctx + 0xa84);
      goto LAB_00003220;
    }
    controlWord = *(uint *)(ctx + 0xa84);
LAB_00003248:
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
LAB_00003220:
    if (((flags & 2) != 0) || ((flags & 4) != 0)) goto LAB_00003248;
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
LAB_00003310:
        if (*(int *)(ctx + 0x120) == 4) {
          FUN_0000bfc0(ctx);
          return status;
        }
        return status;
      }
    }
  }
  return 0xfffffffb;
}

/* FUN_00003350 @ 0x3350 (720 bytes) */
int FUN_00003350(ctx, surface, unused, width, height, pixelFormat, externalData)
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
LAB_00003450:
      *(undefined4 *)(record + 0x24) = 4;
      *(undefined4 *)(record + 0x28) = 2;
      *(undefined4 *)(record + 0x2c) = 0xc;
      *(undefined4 *)(record + 0x30) = 2;
      goto LAB_000034b4;
    }
    if (pixelFormat != 0x32767579) {
      if (pixelFormat != 8) {
        return 0xfffffff9;
      }
      *(undefined4 *)(record + 0x28) = 0;
      *(undefined4 *)(record + 0x24) = 1;
      *(undefined4 *)(record + 0x2c) = 0;
      *(undefined4 *)(record + 0x30) = 0;
      goto LAB_000034b4;
    }
    formatCode = 0x14;
  }
  else {
    if (pixelFormat == 0x72676261) {
      *(undefined4 *)(record + 0x2c) = 0xc;
      *(undefined4 *)(record + 0x24) = 4;
      *(undefined4 *)(record + 0x30) = 0;
      *(undefined4 *)(record + 0x28) = 2;
      goto LAB_000034b4;
    }
    if (pixelFormat != 0x79757673) {
      if (pixelFormat != 0x61726762) {
        return 0xfffffff9;
      }
      goto LAB_00003450;
    }
    formatCode = 0x15;
  }
  *(undefined4 *)(record + 0x2c) = formatCode;
  *(undefined4 *)(record + 0x24) = 2;
  *(undefined4 *)(record + 0x30) = 0;
  *(undefined4 *)(record + 0x28) = 1;
LAB_000034b4:
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

/* FUN_00003630 @ 0x3630 (356 bytes) */
int FUN_00003630(ctx, surfaceDescs, count)
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
        kr = ((int (*)())FUN_00003350)(ctx,ctx + 0x814 + index * 100,*(undefined4 *)(descCursor + 0x4ac),
                             *desc,desc[1],desc[3],0);
        if (kr != 0) {
          if (0 < index) {
            surfaceCount = 0;
            descBase = ctx + 0x814;
            do {
              surfaceCount = surfaceCount + 1;
              ((int (*)())FUN_00002930)(ctx,descBase,1);
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

/* FUN_000037b0 @ 0x37b0 (124 bytes) */
int FUN_000037b0(ctx, outDescs)
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

/* FUN_00003830 @ 0x3830 (136 bytes) */
int FUN_00003830(ctx, outDescs)
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

/* FUN_000038c0 @ 0x38c0 (100 bytes) */
int FUN_000038c0(ctx, unused1, unused2, outSlot)
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

