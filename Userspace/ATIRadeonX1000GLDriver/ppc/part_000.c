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
int FUN_00001790(param_1)
  undefined4 *param_1;
{
  *param_1 = 1;
  return;
}

/* FUN_000017b8 @ 0x17b8 (120 bytes) */
int FUN_000017b8(param_1)
  undefined4 *param_1;
{
  int iVar1;
  undefined4 *puStack00000018;
  
  puStack00000018 = param_1;
  iVar1 = (*(code *)param_1[1])(FUN_00001790,param_1,param_1);
  if (iVar1 != 0) {
    *param_1 = 0xffffffff;
  }
  return;
}

/* FUN_00001830 @ 0x1830 (204 bytes) */
int FUN_00001830(param_1, param_2)
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
  iVar1 = (*param_1)(FUN_000017b8,&local_28,&local_28);
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

/* FUN_000018fc @ 0x18fc (504 bytes) */
int FUN_000018fc()
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
  
  ((int (*)())FUN_00001770)(0x1a4120,(uint)&local_34);
  ((int (*)())FUN_00001770)(0x1a4138,(uint)&local_30);
  ((int (*)())FUN_00001770)(0x1a4150,(uint)&local_2c);
  ((int (*)())FUN_00001770)(0x1a4168,(uint)&local_28);
  uVar1 = ((int (*)())FUN_00001770)(0x1a4188,(uint)local_24);
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
      uVar2 = ((int (*)())FUN_000018fc)();
      *(undefined4 *)(local_20 + 0x10) = uVar2;
      if ((*(int *)(local_20 + 0x10) != 0) &&
         (iVar1 = (**(code **)(local_20 + 0x10))(FUN_0000228c), iVar1 == 0)) goto LAB_00001d08;
    }
    else {
      uVar2 = _dlsym(iVar1,"__cxa_atexit");
      *(undefined4 *)(local_20 + 8) = uVar2;
      uVar2 = _dlsym(iVar1,"__cxa_finalize");
      *(undefined4 *)(local_20 + 0xc) = uVar2;
      if (((*(int *)(local_20 + 8) != 0) && (*(int *)(local_20 + 0xc) != 0)) &&
         (iVar3 = ((int (*)())FUN_00001830)(*(undefined4 *)(local_20 + 8),*(undefined4 *)(local_20 + 0xc)),
         iVar3 != -1)) {
        if (iVar3 == 0) {
          *(undefined1 *)(local_20 + 3) = 2;
        }
        else {
          uVar2 = _dlsym(iVar1,"atexit");
          *(undefined4 *)(local_20 + 0x10) = uVar2;
          if (*(int *)(local_20 + 0x10) == 0) goto LAB_00001d14;
          *(undefined1 *)(local_20 + 3) = 0x10;
        }
        goto LAB_00001d08;
      }
    }
LAB_00001d14:
    __keymgr_set_and_unlock_processwide_ptr(0xe,local_20);
    local_18 = 0;
  }
  else {
LAB_00001d08:
    local_18 = local_20;
  }
  return local_18;
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
int FUN_00001e24(param_1, param_2)
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
    if ((*(ushort *)(*(int *)(PTR_001e88a4 + 8) + 4) < 4) || (iVar3 == 0)) {
      local_18 = 0;
    }
    else {
      local_18 = 0xffffffff;
    }
    local_14 = local_18;
  }
  return local_14;
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
int FUN_00001f70(param_1, param_2)
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
int FUN_000020f4(param_1)
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
  undefined1 uStack_28;
  undefined4 uStack_24;
  int iStack_20;
  
  uStack_24 = 0;
  uStack_28 = 0;
  puStack00000018 = param_1;
  iStack_20 = __keymgr_get_and_lock_processwide_ptr(0xe);
  a0 = 0;
  a1 = extraout_r4;
  if (iStack_20 != 0) {
    uStack_28 = *(undefined1 *)(iStack_20 + 2);
    *(undefined1 *)(iStack_20 + 2) = 1;
    uStack_24 = *(undefined4 *)(iStack_20 + 4);
    a0 = __keymgr_set_and_unlock_processwide_ptr(0xe,iStack_20);
    a1 = extraout_r4_00;
  }
  if (param_1[1] == 0) {
    (*(code *)*param_1)(a0);
  }
  else {
    (*(code *)*param_1)(param_1[2],a1,in_r5,in_r6,in_r7,in_r8,(code *)*param_1);
  }
  if (iStack_20 != 0) {
    iStack_20 = __keymgr_get_and_lock_processwide_ptr(0xe);
  }
  if (iStack_20 != 0) {
    iStack_20 = ((int (*)())FUN_00001f70)(iStack_20,uStack_24);
  }
  if (iStack_20 != 0) {
    *(undefined1 *)(iStack_20 + 2) = uStack_28;
    __keymgr_set_and_unlock_processwide_ptr(0xe,iStack_20);
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
  undefined1 uVar1;
  short *psVar2;
  int iVar3;
  
  psVar2 = (short *)__keymgr_get_and_lock_processwide_ptr(0xe);
  if (((psVar2 != (short *)0x0) && (*psVar2 == 0)) && (*(char *)((int)psVar2 + 3) == '\x01')) {
    uVar1 = *(undefined1 *)(psVar2 + 1);
    *(undefined1 *)(psVar2 + 1) = 1;
    iVar3 = ((int (*)())FUN_00001f70)(psVar2,0);
    if (iVar3 != 0) {
      *(undefined1 *)(iVar3 + 2) = uVar1;
      __keymgr_set_and_unlock_processwide_ptr(0xe,iVar3);
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
int FUN_000023a8(param_1, param_2)
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
  iVar3 = ((int (*)())FUN_00001b34)();
  if (iVar3 == 0) {
    local_18 = 0xffffffff;
  }
  else if ((*(char *)(iVar3 + 2) == '\0') && (*(char *)(iVar3 + 3) != '\x01')) {
    if (*(byte *)(iVar3 + 3) < 0x10) {
      pcVar1 = *(code **)(iVar3 + 8);
      iVar3 = __keymgr_set_and_unlock_processwide_ptr(0xe,iVar3);
      if ((*(ushort *)(*(int *)(PTR_001e88a4 + 8) + 4) < 4) || (iVar3 == 0)) {
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
          local_18 = (*pcVar1)(FUN_000020f4,a1,uStack0000001c,in_r6,in_r7,in_r8,a1);
        }
      }
      else {
        local_18 = 0xffffffff;
      }
    }
    else if (puStack00000018[1] == 0) {
      pcVar1 = *(code **)(iVar3 + 0x10);
      iVar3 = __keymgr_set_and_unlock_processwide_ptr(0xe,iVar3);
      if ((*(ushort *)(*(int *)(PTR_001e88a4 + 8) + 4) < 4) || (iVar3 == 0)) {
        local_18 = (*pcVar1)(*puStack00000018);
      }
      else {
        local_18 = 0xffffffff;
      }
    }
    else {
      pcVar1 = *(code **)(iVar3 + 8);
      iVar3 = __keymgr_set_and_unlock_processwide_ptr(0xe,iVar3);
      if ((*(ushort *)(*(int *)(PTR_001e88a4 + 8) + 4) < 4) || (iVar3 == 0)) {
        local_18 = (*pcVar1)(*puStack00000018,puStack00000018[2],uStack0000001c,in_r6,in_r7,in_r8,
                             *puStack00000018);
      }
      else {
        local_18 = 0xffffffff;
      }
    }
  }
  else {
    local_18 = ((int (*)())FUN_00001e24)(iVar3,puStack00000018);
  }
  return local_18;
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
int FUN_000026c8(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined4 uVar1;
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
  uVar1 = ((int (*)())FUN_000023a8)(&uStack_28,param_3);
  return uVar1;
}

/* FUN_00002728 @ 0x2728 (32 bytes) */
int FUN_00002728(param_1, param_2)
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
        puVar4 = _malloc(0xc);
        if (puVar4 == (undefined4 *)0x0) {
          uStack_18 = 0xffffffff;
        }
        else {
          uVar5 = puStack00000018[1];
          uVar2 = puStack00000018[2];
          *puVar4 = *puStack00000018;
          puVar4[1] = uVar5;
          puVar4[2] = uVar2;
          uStack_18 = (*pcVar1)(FUN_000020f4,puVar4,uStack0000001c);
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
int FUN_00002748(param_1)
  undefined4 param_1;
{
  undefined4 uVar1;
  undefined4 uStack00000018;
  undefined4 local_28;
  undefined4 local_24;
  
  local_24 = 0;
  uStack00000018 = param_1;
  local_28 = param_1;
  uVar1 = ((int (*)())FUN_000023a8)(&local_28,PTR_001e88a8);
  return uVar1;
}

/* FUN_000027a4 @ 0x27a4 (32 bytes) */
int FUN_000027a4(param_1, param_2)
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
        puVar4 = _malloc(0xc);
        if (puVar4 == (undefined4 *)0x0) {
          uStack_18 = 0xffffffff;
        }
        else {
          uVar5 = puStack00000018[1];
          uVar2 = puStack00000018[2];
          *puVar4 = *puStack00000018;
          puVar4[1] = uVar5;
          puVar4[2] = uVar2;
          uStack_18 = (*pcVar1)(FUN_000020f4,puVar4,uStack0000001c);
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
        iVar14 = 0;
        uVar16 = uVar12;
        puVar7 = puVar6;
        do {
          do {
            *puVar6 = uVar2;
            puVar6 = puVar6 + 1;
            uVar16 = uVar16 - 1;
          } while (uVar16 != 0);
          iVar14 = iVar14 + 1;
          puVar6 = puVar7 + uVar1;
          uVar16 = uVar12;
          puVar7 = puVar6;
        } while (iVar13 != iVar14);
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
        iVar14 = 0;
        uVar16 = uVar12;
        puVar9 = puVar8;
        do {
          do {
            *puVar8 = uVar3;
            puVar8 = puVar8 + 1;
            uVar16 = uVar16 - 1;
          } while (uVar16 != 0);
          iVar14 = iVar14 + 1;
          puVar8 = puVar9 + uVar1;
          uVar16 = uVar12;
          puVar9 = puVar8;
        } while (iVar13 != iVar14);
      }
    }
  }
  return;
}

/* FUN_00002ae0 @ 0x2ae0 (88 bytes) */
void FUN_00002ae0(int param_1,undefined4 param_2,double fparam_1)
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
  void *pvVar22;
  int iVar23;
  undefined1 *puVar24;
  undefined2 *puVar25;
  int iVar26;
  ushort uVar27;
  int iVar28;
  uint uVar29;
  char *pcVar30;
  uint uVar31;
  byte *pbVar32;
  ushort *puVar33;
  int iVar34;
  byte *pbVar35;
  int iVar36;
  char *pcVar37;
  short *psVar38;
  ushort uVar41;
  short *psVar39;
  int iVar40;
  ushort *puVar42;
  uint *puVar43;
  uint uVar44;
  uint uVar45;
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
  
  iVar28 = *(int *)(param_1 + 0x148);
  if (iVar28 == 0) {
    return;
  }
  switch(param_2) {
  case 0x100:
    if ((*(uint *)(param_1 + 0x154) & 3) == 0) {
      iVar28 = *(int *)(param_1 + 0x10);
      if (((unsigned char *)0x00003190)[iVar28] == '\0') {
        iVar19 = *(int *)(param_1 + 0x15c);
        iVar26 = *(int *)(param_1 + 0x160);
        iVar23 = 0;
        uVar29 = 0;
        uVar20 = iVar19 + 7U & 0xfffffff8;
        iVar28 = iVar26;
      }
      else {
        iVar23 = *(int *)(((unsigned char *)0x00003180) + iVar28);
        iVar26 = *(int *)(param_1 + 0x160);
        uVar20 = iVar23 + *(int *)(((unsigned char *)0x00003188) + iVar28);
        uVar29 = iVar26 - (*(int *)(((unsigned char *)0x0000318c) + iVar28) + *(int *)(((unsigned char *)0x00003184) + iVar28));
        iVar28 = *(int *)(((unsigned char *)0x0000318c) + iVar28) + uVar29;
        if (iVar23 < 0) {
          iVar23 = 0;
        }
        if ((int)uVar29 < 0) {
          uVar29 = 0;
        }
        iVar19 = *(int *)(param_1 + 0x15c);
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
      pvVar22 = _malloc((iVar19 + 7U & 0xfffffff8) * iVar26 * 4);
      FUN_00029290(param_1,0,0,*(int *)(param_1 + 0x15c) + 7U & 0xfffffff8,
                   *(undefined4 *)(param_1 + 0x160),0x80e1,0x8367,pvVar22,2,0);
      uVar31 = uVar29 + iVar28;
      if (fparam_1 < (double)FLOAT_001aa0d4) {
        *(undefined1 *)(param_1 + 0x140) = 1;
      }
      uVar45 = *(int *)(param_1 + 0x15c) + 7U & 0xfffffff8;
      iVar23 = iVar23 + uVar45 * ((*(int *)(param_1 + 0x160) - uVar29) + -1);
      if (*(char *)(param_1 + 0x141) == '\x01') {
        sStack_252 = (short)(int)(fparam_1 * (double)FLOAT_001aa0d8);
        iVar28 = (int)sStack_252;
        if (uVar29 < uVar31) {
          iVar19 = 0;
          do {
            puVar43 = (uint *)((int)pvVar22 + iVar23 * 4);
            pcVar37 = (char *)(iVar23 * 4 + *(int *)(param_1 + 0x148));
            pcVar30 = pcVar37 + uVar20 * 4;
            for (; pcVar37 < pcVar30; pcVar37 = pcVar37 + 4) {
              uVar13 = *puVar43;
              puVar43 = puVar43 + 1;
              *pcVar37 = (char)((int)(iVar28 * (uVar13 >> 9 & 0x7f80 | uVar13 >> 0x11 & 0x7f)) >>
                               0x17) + *pcVar37;
              pcVar37[3] = (char)((int)(iVar28 * (uVar13 >> 0x11 & 0x7f80 | uVar13 >> 0x19)) >> 0x17
                                 ) + pcVar37[3];
              pcVar37[1] = (char)((int)(iVar28 * (uVar13 >> 1 & 0x7f80 | uVar13 >> 9 & 0x7f)) >>
                                 0x17) + pcVar37[1];
              pcVar37[2] = (char)((int)(iVar28 * ((uVar13 & 0xff) << 7 | uVar13 >> 1 & 0x7f)) >>
                                 0x17) + pcVar37[2];
            }
            iVar19 = iVar19 + 1;
            iVar23 = iVar23 - uVar45;
          } while (uVar31 - uVar29 != iVar19);
        }
      }
      else {
        sStack_24a = (short)(int)(fparam_1 * (double)FLOAT_001aa0d8);
        iVar28 = (int)sStack_24a;
        if (uVar29 < uVar31) {
          iVar19 = 0;
          do {
            puVar43 = (uint *)((int)pvVar22 + iVar23 * 4);
            psVar38 = (short *)(iVar23 * 8 + *(int *)(param_1 + 0x148));
            psVar39 = psVar38 + uVar20 * 4;
            for (; psVar38 < psVar39; psVar38 = psVar38 + 4) {
              uVar13 = *puVar43;
              puVar43 = puVar43 + 1;
              *psVar38 = (short)((int)(iVar28 * (uVar13 >> 9 & 0x7f80 | uVar13 >> 0x11 & 0x7f)) >>
                                0xf) + *psVar38;
              psVar38[3] = (short)((int)(iVar28 * (uVar13 >> 0x11 & 0x7f80 | uVar13 >> 0x19)) >> 0xf
                                  ) + psVar38[3];
              psVar38[1] = (short)((int)(iVar28 * (uVar13 >> 1 & 0x7f80 | uVar13 >> 9 & 0x7f)) >>
                                  0xf) + psVar38[1];
              psVar38[2] = (short)((int)(iVar28 * ((uVar13 & 0xff) << 7 | uVar13 >> 1 & 0x7f)) >>
                                  0xf) + psVar38[2];
            }
            iVar19 = iVar19 + 1;
            iVar23 = iVar23 - uVar45;
          } while (uVar31 - uVar29 != iVar19);
        }
      }
    }
    else {
      iVar28 = *(int *)(param_1 + 0x10);
      if (((unsigned char *)0x00003190)[iVar28] == '\0') {
        iVar19 = *(int *)(param_1 + 0x15c);
        iVar26 = *(int *)(param_1 + 0x160);
        iVar23 = 0;
        uVar29 = 0;
        uVar20 = iVar19 + 7U & 0xfffffff8;
        iVar28 = iVar26;
      }
      else {
        iVar23 = *(int *)(((unsigned char *)0x00003180) + iVar28);
        iVar26 = *(int *)(param_1 + 0x160);
        uVar20 = iVar23 + *(int *)(((unsigned char *)0x00003188) + iVar28);
        uVar29 = iVar26 - (*(int *)(((unsigned char *)0x0000318c) + iVar28) + *(int *)(((unsigned char *)0x00003184) + iVar28));
        iVar28 = *(int *)(((unsigned char *)0x0000318c) + iVar28) + uVar29;
        if (iVar23 < 0) {
          iVar23 = 0;
        }
        if ((int)uVar29 < 0) {
          uVar29 = 0;
        }
        iVar19 = *(int *)(param_1 + 0x15c);
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
      pvVar22 = _malloc((iVar19 + 7U & 0xfffffff8) * iVar26 * 2);
      FUN_00029290(param_1,0,0,*(int *)(param_1 + 0x15c) + 7U & 0xfffffff8,
                   *(undefined4 *)(param_1 + 0x160),0x80e1,0x8366,pvVar22,2,0);
      uVar31 = uVar29 + iVar28;
      if (fparam_1 < (double)FLOAT_001aa0d4) {
        *(undefined1 *)(param_1 + 0x140) = 1;
      }
      uVar45 = *(int *)(param_1 + 0x15c) + 7U & 0xfffffff8;
      iVar23 = iVar23 + uVar45 * ((*(int *)(param_1 + 0x160) - uVar29) + -1);
      if (*(char *)(param_1 + 0x141) == '\x01') {
        sStack_262 = (short)(int)(fparam_1 * (double)FLOAT_001aa0d8);
        iVar28 = (int)sStack_262;
        if (uVar29 < uVar31) {
          iVar19 = 0;
          do {
            puVar42 = (ushort *)((int)pvVar22 + iVar23 * 2);
            pcVar37 = (char *)(iVar23 * 4 + *(int *)(param_1 + 0x148));
            pcVar30 = pcVar37 + uVar20 * 4;
            for (; pcVar37 < pcVar30; pcVar37 = pcVar37 + 4) {
              uVar27 = *puVar42;
              puVar42 = puVar42 + 1;
              uVar13 = (uint)uVar27 << 5;
              pcVar37[1] = (char)((int)(iVar28 * (uVar13 & 0x7c00 | uVar27 & 0x3e0 |
                                                 uVar27 >> 5 & 0x1f)) >> 0x17) + pcVar37[1];
              pcVar37[3] = (char)((int)(iVar28 * (-(uint)(uVar27 >> 0xf) & 0x7fff)) >> 0x17) +
                           pcVar37[3];
              *pcVar37 = (char)((int)(iVar28 * (uVar27 & 0x7c00 | uVar27 >> 5 & 0x3e0 |
                                               uVar27 >> 10 & 0x1f)) >> 0x17) + *pcVar37;
              pcVar37[2] = (char)((int)(iVar28 * ((uVar27 & 0x1f) << 10 | uVar13 & 0x3e0 |
                                                 uVar27 & 0x1f)) >> 0x17) + pcVar37[2];
            }
            iVar19 = iVar19 + 1;
            iVar23 = iVar23 - uVar45;
          } while (uVar31 - uVar29 != iVar19);
        }
      }
      else {
        sStack_25a = (short)(int)(fparam_1 * (double)FLOAT_001aa0d8);
        iVar28 = (int)sStack_25a;
        if (uVar29 < uVar31) {
          iVar19 = 0;
          do {
            puVar42 = (ushort *)((int)pvVar22 + iVar23 * 2);
            psVar38 = (short *)(iVar23 * 8 + *(int *)(param_1 + 0x148));
            psVar39 = psVar38 + uVar20 * 4;
            for (; psVar38 < psVar39; psVar38 = psVar38 + 4) {
              uVar27 = *puVar42;
              puVar42 = puVar42 + 1;
              uVar13 = (uint)uVar27 << 5;
              psVar38[1] = (short)((int)(iVar28 * (uVar13 & 0x7c00 | uVar27 & 0x3e0 |
                                                  uVar27 >> 5 & 0x1f)) >> 0xf) + psVar38[1];
              psVar38[3] = (short)((int)(iVar28 * (-(uint)(uVar27 >> 0xf) & 0x7fff)) >> 0xf) +
                           psVar38[3];
              *psVar38 = (short)((int)(iVar28 * (uVar27 & 0x7c00 | uVar27 >> 5 & 0x3e0 |
                                                uVar27 >> 10 & 0x1f)) >> 0xf) + *psVar38;
              psVar38[2] = (short)((int)(iVar28 * ((uVar27 & 0x1f) << 10 | uVar13 & 0x3e0 |
                                                  uVar27 & 0x1f)) >> 0xf) + psVar38[2];
            }
            iVar19 = iVar19 + 1;
            iVar23 = iVar23 - uVar45;
          } while (uVar31 - uVar29 != iVar19);
        }
      }
    }
    goto code_r0x00003264;
  case 0x101:
    if ((*(uint *)(param_1 + 0x154) & 3) == 0) {
      iVar28 = *(int *)(param_1 + 0x10);
      if (((unsigned char *)0x00003190)[iVar28] == '\0') {
        iVar19 = *(int *)(param_1 + 0x15c);
        iVar26 = *(int *)(param_1 + 0x160);
        iVar23 = 0;
        uVar29 = 0;
        uVar20 = iVar19 + 7U & 0xfffffff8;
        iVar28 = iVar26;
      }
      else {
        iVar23 = *(int *)(((unsigned char *)0x00003180) + iVar28);
        iVar26 = *(int *)(param_1 + 0x160);
        uVar20 = iVar23 + *(int *)(((unsigned char *)0x00003188) + iVar28);
        uVar29 = iVar26 - (*(int *)(((unsigned char *)0x0000318c) + iVar28) + *(int *)(((unsigned char *)0x00003184) + iVar28));
        iVar28 = *(int *)(((unsigned char *)0x0000318c) + iVar28) + uVar29;
        if (iVar23 < 0) {
          iVar23 = 0;
        }
        if ((int)uVar29 < 0) {
          uVar29 = 0;
        }
        iVar19 = *(int *)(param_1 + 0x15c);
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
      pvVar22 = _malloc((iVar19 + 7U & 0xfffffff8) * iVar26 * 4);
      FUN_00029290(param_1,0,0,*(int *)(param_1 + 0x15c) + 7U & 0xfffffff8,
                   *(undefined4 *)(param_1 + 0x160),0x80e1,0x8367,pvVar22,2,0);
      uVar31 = uVar29 + iVar28;
      if (fparam_1 < (double)FLOAT_001aa0d4) {
        *(undefined1 *)(param_1 + 0x140) = 1;
      }
      uVar45 = *(int *)(param_1 + 0x15c) + 7U & 0xfffffff8;
      iVar23 = iVar23 + uVar45 * ((*(int *)(param_1 + 0x160) - uVar29) + -1);
      if (*(char *)(param_1 + 0x141) == '\x01') {
        if (fparam_1 == (double)FLOAT_001aa0e8) {
          if (uVar29 < uVar31) {
            iVar28 = 0;
            do {
              puVar43 = (uint *)((int)pvVar22 + iVar23 * 4);
              pbVar35 = (byte *)(iVar23 * 4 + *(int *)(param_1 + 0x148));
              pbVar32 = pbVar35 + uVar20 * 4;
              for (; pbVar35 < pbVar32; pbVar35 = pbVar35 + 4) {
                uVar13 = *puVar43;
                puVar43 = puVar43 + 1;
                *pbVar35 = (byte)(uVar13 >> 0x11) & 0x7f;
                pbVar35[3] = (byte)(uVar13 >> 0x19);
                pbVar35[1] = (byte)(uVar13 >> 9) & 0x7f;
                pbVar35[2] = (byte)(uVar13 >> 1) & 0x7f;
              }
              iVar28 = iVar28 + 1;
              iVar23 = iVar23 - uVar45;
            } while (uVar31 - uVar29 != iVar28);
          }
        }
        else {
          sStack_232 = (short)(int)(fparam_1 * (double)FLOAT_001aa0d8);
          iVar28 = (int)sStack_232;
          if (uVar29 < uVar31) {
            iVar19 = 0;
            do {
              puVar43 = (uint *)((int)pvVar22 + iVar23 * 4);
              puVar24 = (undefined1 *)(iVar23 * 4 + *(int *)(param_1 + 0x148));
              puVar47 = puVar24 + uVar20 * 4;
              for (; puVar24 < puVar47; puVar24 = puVar24 + 4) {
                uVar13 = *puVar43;
                puVar43 = puVar43 + 1;
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
              iVar23 = iVar23 - uVar45;
            } while (uVar31 - uVar29 != iVar19);
          }
        }
      }
      else if (fparam_1 == (double)FLOAT_001aa0e8) {
        if (uVar29 < uVar31) {
          iVar28 = 0;
          do {
            puVar43 = (uint *)((int)pvVar22 + iVar23 * 4);
            puVar42 = (ushort *)(iVar23 * 8 + *(int *)(param_1 + 0x148));
            puVar33 = puVar42 + uVar20 * 4;
            for (; puVar42 < puVar33; puVar42 = puVar42 + 4) {
              uVar13 = *puVar43;
              puVar43 = puVar43 + 1;
              uVar10 = (ushort)(uVar13 >> 0x10);
              uVar21 = uVar10 >> 1;
              uVar27 = (ushort)(uVar13 >> 9);
              uVar41 = (ushort)(uVar13 >> 1);
              puVar42[3] = uVar21 & 0x7f80 | uVar10 >> 9;
              *puVar42 = uVar27 & 0x7f80 | uVar21 & 0x7f;
              puVar42[1] = uVar41 & 0x7f80 | uVar27 & 0x7f;
              puVar42[2] = (ushort)(uVar13 << 7) & 0x7f80 | uVar41 & 0x7f;
            }
            iVar28 = iVar28 + 1;
            iVar23 = iVar23 - uVar45;
          } while (uVar31 - uVar29 != iVar28);
        }
      }
      else {
        sStack_22a = (short)(int)(fparam_1 * (double)FLOAT_001aa0d8);
        iVar28 = (int)sStack_22a;
        if (uVar29 < uVar31) {
          iVar19 = 0;
          do {
            puVar43 = (uint *)((int)pvVar22 + iVar23 * 4);
            puVar25 = (undefined2 *)(iVar23 * 8 + *(int *)(param_1 + 0x148));
            puVar49 = puVar25 + uVar20 * 4;
            for (; puVar25 < puVar49; puVar25 = puVar25 + 4) {
              uVar13 = *puVar43;
              puVar43 = puVar43 + 1;
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
            iVar23 = iVar23 - uVar45;
          } while (uVar31 - uVar29 != iVar19);
        }
      }
    }
    else {
      iVar28 = *(int *)(param_1 + 0x10);
      if (((unsigned char *)0x00003190)[iVar28] == '\0') {
        iVar19 = *(int *)(param_1 + 0x15c);
        iVar26 = *(int *)(param_1 + 0x160);
        iVar23 = 0;
        uVar29 = 0;
        uVar20 = iVar19 + 7U & 0xfffffff8;
        iVar28 = iVar26;
      }
      else {
        iVar23 = *(int *)(((unsigned char *)0x00003180) + iVar28);
        iVar26 = *(int *)(param_1 + 0x160);
        uVar20 = iVar23 + *(int *)(((unsigned char *)0x00003188) + iVar28);
        uVar29 = iVar26 - (*(int *)(((unsigned char *)0x0000318c) + iVar28) + *(int *)(((unsigned char *)0x00003184) + iVar28));
        iVar28 = *(int *)(((unsigned char *)0x0000318c) + iVar28) + uVar29;
        if (iVar23 < 0) {
          iVar23 = 0;
        }
        if ((int)uVar29 < 0) {
          uVar29 = 0;
        }
        iVar19 = *(int *)(param_1 + 0x15c);
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
      pvVar22 = _malloc((iVar19 + 7U & 0xfffffff8) * iVar26 * 2);
      FUN_00029290(param_1,0,0,*(int *)(param_1 + 0x15c) + 7U & 0xfffffff8,
                   *(undefined4 *)(param_1 + 0x160),0x80e1,0x8366,pvVar22,2,0);
      uVar31 = uVar29 + iVar28;
      if (fparam_1 < (double)FLOAT_001aa0d4) {
        *(undefined1 *)(param_1 + 0x140) = 1;
      }
      uVar45 = *(int *)(param_1 + 0x15c) + 7U & 0xfffffff8;
      iVar23 = iVar23 + uVar45 * ((*(int *)(param_1 + 0x160) - uVar29) + -1);
      if (*(char *)(param_1 + 0x141) == '\x01') {
        if (fparam_1 == (double)FLOAT_001aa0e8) {
          if (uVar29 < uVar31) {
            iVar28 = 0;
            do {
              puVar42 = (ushort *)((int)pvVar22 + iVar23 * 2);
              pbVar35 = (byte *)(iVar23 * 4 + *(int *)(param_1 + 0x148));
              pbVar32 = pbVar35 + uVar20 * 4;
              for (; pbVar35 < pbVar32; pbVar35 = pbVar35 + 4) {
                uVar27 = *puVar42;
                puVar42 = puVar42 + 1;
                bVar3 = (byte)(uVar27 >> 8);
                bVar4 = (byte)(uVar27 >> 3);
                pbVar35[2] = ((byte)uVar27 & 0x1f) << 2 | bVar4 & 3;
                pbVar35[3] = (char)bVar3 >> 7 & 0x7f;
                *pbVar35 = bVar3 & 0x7c | bVar3 >> 5 & 3;
                pbVar35[1] = bVar4 & 0x7c | bVar3 & 3;
              }
              iVar28 = iVar28 + 1;
              iVar23 = iVar23 - uVar45;
            } while (uVar31 - uVar29 != iVar28);
          }
        }
        else {
          sStack_242 = (short)(int)(fparam_1 * (double)FLOAT_001aa0d8);
          iVar28 = (int)sStack_242;
          if (uVar29 < uVar31) {
            iVar19 = 0;
            do {
              puVar42 = (ushort *)((int)pvVar22 + iVar23 * 2);
              puVar24 = (undefined1 *)(iVar23 * 4 + *(int *)(param_1 + 0x148));
              puVar47 = puVar24 + uVar20 * 4;
              for (; puVar24 < puVar47; puVar24 = puVar24 + 4) {
                uVar27 = *puVar42;
                puVar42 = puVar42 + 1;
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
              iVar23 = iVar23 - uVar45;
            } while (uVar31 - uVar29 != iVar19);
          }
        }
      }
      else if (fparam_1 == (double)FLOAT_001aa0e8) {
        if (uVar29 < uVar31) {
          iVar28 = 0;
          do {
            puVar42 = (ushort *)((int)pvVar22 + iVar23 * 2);
            puVar33 = (ushort *)(iVar23 * 8 + *(int *)(param_1 + 0x148));
            puVar48 = puVar33 + uVar20 * 4;
            for (; puVar33 < puVar48; puVar33 = puVar33 + 4) {
              uVar27 = *puVar42;
              puVar42 = puVar42 + 1;
              puVar33[1] = uVar27 << 5 & 0x7c00 | uVar27 & 0x3e0 | uVar27 >> 5 & 0x1f;
              puVar33[2] = (uVar27 & 0x1f) << 10 | uVar27 << 5 & 0x3e0 | uVar27 & 0x1f;
              *puVar33 = uVar27 & 0x7c00 | uVar27 >> 5 & 0x3e0 | uVar27 >> 10 & 0x1f;
              puVar33[3] = (short)uVar27 >> 0xf & 0x7fff;
            }
            iVar28 = iVar28 + 1;
            iVar23 = iVar23 - uVar45;
          } while (uVar31 - uVar29 != iVar28);
        }
      }
      else {
        sStack_23a = (short)(int)(fparam_1 * (double)FLOAT_001aa0d8);
        iVar28 = (int)sStack_23a;
        if (uVar29 < uVar31) {
          iVar19 = 0;
          do {
            puVar42 = (ushort *)((int)pvVar22 + iVar23 * 2);
            puVar25 = (undefined2 *)(iVar23 * 8 + *(int *)(param_1 + 0x148));
            puVar49 = puVar25 + uVar20 * 4;
            for (; puVar25 < puVar49; puVar25 = puVar25 + 4) {
              uVar27 = *puVar42;
              puVar42 = puVar42 + 1;
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
            iVar23 = iVar23 - uVar45;
          } while (uVar31 - uVar29 != iVar19);
        }
      }
    }
code_r0x00003264:
                    
                    
    (*(code *)PTR_FUN_001e8754)(pvVar22);
    return;
  case 0x102:
    if ((*(uint *)(param_1 + 0x154) & 3) == 0) {
      iVar28 = *(int *)(param_1 + 0x10);
      if (*(int *)((*(unsigned char *)0x00002e40) + iVar28) != 0) {
        if (((unsigned char *)0x00003190)[iVar28] == '\0') {
          iVar19 = *(int *)(param_1 + 0x15c);
          iVar26 = *(int *)(param_1 + 0x160);
          iVar23 = 0;
          uVar29 = 0;
          uVar20 = iVar19 + 7U & 0xfffffff8;
          iVar28 = iVar26;
        }
        else {
          iVar23 = *(int *)(((unsigned char *)0x00003180) + iVar28);
          iVar26 = *(int *)(param_1 + 0x160);
          uVar20 = iVar23 + *(int *)(((unsigned char *)0x00003188) + iVar28);
          uVar29 = iVar26 - (*(int *)(((unsigned char *)0x0000318c) + iVar28) + *(int *)(((unsigned char *)0x00003184) + iVar28));
          iVar28 = *(int *)(((unsigned char *)0x0000318c) + iVar28) + uVar29;
          if (iVar23 < 0) {
            iVar23 = 0;
          }
          if ((int)uVar29 < 0) {
            uVar29 = 0;
          }
          iVar19 = *(int *)(param_1 + 0x15c);
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
          pvVar22 = _malloc((iVar19 + 7U & 0xfffffff8) * iVar26 * 4);
          iVar26 = *(int *)(param_1 + 0x160);
          uVar45 = uVar29 + iVar28;
          iVar19 = *(int *)(param_1 + 0x15c);
          uVar31 = iVar19 + 7U & 0xfffffff8;
          cVar14 = *(char *)(param_1 + 0x140);
          iVar34 = iVar23 + uVar31 * ((iVar26 - uVar29) + -1);
          if (*(char *)(param_1 + 0x141) == '\x01') {
            if (fparam_1 == (double)FLOAT_001aa0e8) {
              if (uVar29 < uVar45) {
                iVar36 = *(int *)(param_1 + 0x148);
                iVar40 = 0;
                do {
                  pbVar35 = (byte *)(iVar34 * 4 + iVar36);
                  puVar43 = (uint *)((int)pvVar22 + iVar34 * 4);
                  pbVar32 = pbVar35 + uVar20 * 4;
                  if (cVar14 == '\0') {
                    for (; pbVar35 < pbVar32; pbVar35 = pbVar35 + 4) {
                      *puVar43 = (uint)pbVar35[3] << 0x19 | (*pbVar35 & 0x7f) << 0x11 |
                                 (pbVar35[1] & 0x7f) << 9 | (pbVar35[2] & 0x7f) << 1;
                      puVar43 = puVar43 + 1;
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
                      *puVar43 = iVar15 << 0x19 | (uVar13 & 0x7f) << 0x11 | (uVar44 & 0x7f) << 9 |
                                 (uVar46 & 0x7f) << 1;
                      puVar43 = puVar43 + 1;
                    }
                  }
                  iVar40 = iVar40 + 1;
                  iVar34 = iVar34 - uVar31;
                } while (iVar40 != uVar45 - uVar29);
              }
            }
            else {
              fVar1 = (float)(fparam_1 * (double)FLOAT_001aa0dc);
              if (uVar29 < uVar45) {
                iVar40 = *(int *)(param_1 + 0x148);
                iVar36 = 0;
                do {
                  dVar51 = DOUBLE_001aa1e0;
                  pcVar30 = (char *)(iVar34 * 4 + iVar40);
                  puVar43 = (uint *)((int)pvVar22 + iVar34 * 4);
                  pcVar37 = pcVar30 + uVar20 * 4;
                  if (pcVar30 < pcVar37) {
                    dVar52 = (double)FLOAT_001aa0d4;
                    dVar53 = (double)FLOAT_001aa0f0;
                    do {
                      dVar50 = (double)(fVar1 * (float)((double)CONCAT44(0x43300000,
                                                                         (int)*pcVar30 ^ 0x80000000)
                                                       - dVar51));
                      fVar2 = FLOAT_001aa0d4;
                      if (dVar52 <= dVar50) {
                        fVar2 = (float)(dVar50 * dVar53);
                      }
                      dVar55 = (double)FLOAT_001aa0d4;
                      dVar50 = (double)(fVar1 * (float)((double)CONCAT44(0x43300000,
                                                                         (int)pcVar30[1] ^
                                                                         0x80000000) - dVar51));
                      if (dVar55 <= dVar50) {
                        dVar55 = (double)(float)(dVar50 * dVar53);
                      }
                      dVar54 = (double)FLOAT_001aa0d4;
                      dVar50 = (double)(fVar1 * (float)((double)CONCAT44(0x43300000,
                                                                         (int)pcVar30[2] ^
                                                                         0x80000000) - dVar51));
                      if (dVar54 <= dVar50) {
                        dVar54 = (double)(float)(dVar50 * dVar53);
                      }
                      dVar56 = (double)FLOAT_001aa0d4;
                      dVar50 = (double)(fVar1 * (float)((double)CONCAT44(0x43300000,
                                                                         (int)pcVar30[3] ^
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
                      pcVar30 = pcVar30 + 4;
                      *puVar43 = iVar15 << 0x18 | iVar16 << 0x10 | iVar17 << 8 | uVar13;
                      puVar43 = puVar43 + 1;
                    } while (pcVar30 < pcVar37);
                  }
                  iVar36 = iVar36 + 1;
                  iVar34 = iVar34 - uVar31;
                } while (iVar36 != uVar45 - uVar29);
              }
            }
          }
          else if (fparam_1 == (double)FLOAT_001aa0e8) {
            if (uVar29 < uVar45) {
              iVar36 = *(int *)(param_1 + 0x148);
              iVar40 = 0;
              do {
                psVar38 = (short *)(iVar34 * 8 + iVar36);
                puVar43 = (uint *)((int)pvVar22 + iVar34 * 4);
                psVar39 = psVar38 + uVar20 * 4;
                if (cVar14 == '\0') {
                  for (; psVar38 < psVar39; psVar38 = psVar38 + 4) {
                    *puVar43 = ((int)psVar38[3] & 0x7f80U) << 0x11 | ((int)*psVar38 & 0x7f80U) << 9
                               | ((int)psVar38[1] & 0x7f80U) << 1 |
                               (uint)(int)psVar38[2] >> 7 & 0xff;
                    puVar43 = puVar43 + 1;
                  }
                }
                else {
                  for (; psVar38 < psVar39; psVar38 = psVar38 + 4) {
                    uVar13 = 0;
                    if (-1 < *psVar38) {
                      uVar13 = (int)*psVar38;
                    }
                    uVar44 = 0;
                    if (-1 < psVar38[1]) {
                      uVar44 = (int)psVar38[1];
                    }
                    uVar46 = 0;
                    if (-1 < psVar38[2]) {
                      uVar46 = (int)psVar38[2] >> 7;
                    }
                    uVar18 = 0;
                    if (-1 < psVar38[3]) {
                      uVar18 = (int)psVar38[3];
                    }
                    *puVar43 = (uVar18 & 0x7f80) << 0x11 | (uVar13 & 0x7f80) << 9 |
                               (uVar44 & 0x7f80) << 1 | uVar46 & 0xff;
                    puVar43 = puVar43 + 1;
                  }
                }
                iVar40 = iVar40 + 1;
                iVar34 = iVar34 - uVar31;
              } while (iVar40 != uVar45 - uVar29);
            }
          }
          else {
            fVar1 = (float)(fparam_1 * (double)FLOAT_001aa0e4);
            if (uVar29 < uVar45) {
              iVar40 = *(int *)(param_1 + 0x148);
              iVar36 = 0;
              do {
                dVar51 = DOUBLE_001aa1e0;
                psVar39 = (short *)(iVar34 * 8 + iVar40);
                puVar43 = (uint *)((int)pvVar22 + iVar34 * 4);
                psVar38 = psVar39 + uVar20 * 4;
                if (psVar39 < psVar38) {
                  dVar52 = (double)FLOAT_001aa0d4;
                  dVar53 = (double)FLOAT_001aa0f0;
                  do {
                    dVar50 = (double)(fVar1 * (float)((double)CONCAT44(0x43300000,
                                                                       (int)*psVar39 ^ 0x80000000) -
                                                     dVar51));
                    fVar2 = FLOAT_001aa0d4;
                    if (dVar52 <= dVar50) {
                      fVar2 = (float)(dVar50 * dVar53);
                    }
                    dVar55 = (double)FLOAT_001aa0d4;
                    dVar50 = (double)(fVar1 * (float)((double)CONCAT44(0x43300000,
                                                                       (int)psVar39[1] ^ 0x80000000)
                                                     - dVar51));
                    if (dVar55 <= dVar50) {
                      dVar55 = (double)(float)(dVar50 * dVar53);
                    }
                    dVar54 = (double)FLOAT_001aa0d4;
                    dVar50 = (double)(fVar1 * (float)((double)CONCAT44(0x43300000,
                                                                       (int)psVar39[2] ^ 0x80000000)
                                                     - dVar51));
                    if (dVar54 <= dVar50) {
                      dVar54 = (double)(float)(dVar50 * dVar53);
                    }
                    dVar56 = (double)FLOAT_001aa0d4;
                    dVar50 = (double)(fVar1 * (float)((double)CONCAT44(0x43300000,
                                                                       (int)psVar39[3] ^ 0x80000000)
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
                    psVar39 = psVar39 + 4;
                    *puVar43 = iVar15 << 0x18 | iVar16 << 0x10 | iVar17 << 8 | uVar13;
                    puVar43 = puVar43 + 1;
                  } while (psVar39 < psVar38);
                }
                iVar36 = iVar36 + 1;
                iVar34 = iVar34 - uVar31;
              } while (iVar36 != uVar45 - uVar29);
            }
          }
          FUN_000198b0(param_1,iVar23,uVar29,uVar20,iVar28,0x8367,
                       (void *)((int)pvVar22 +
                               (((iVar26 - uVar29) - iVar28) * (iVar19 + 7U & 0xfffffff8) + iVar23)
                               * 4));
          goto code_r0x00003264;
        }
      }
    }
    else {
      iVar28 = *(int *)(param_1 + 0x10);
      if (*(int *)((*(unsigned char *)0x00002e40) + iVar28) != 0) {
        if (((unsigned char *)0x00003190)[iVar28] == '\0') {
          iVar19 = *(int *)(param_1 + 0x15c);
          iVar26 = *(int *)(param_1 + 0x160);
          uVar29 = 0;
          uVar31 = 0;
          uVar20 = iVar19 + 7U & 0xfffffff8;
          iVar28 = iVar26;
        }
        else {
          uVar29 = *(uint *)(((unsigned char *)0x00003180) + iVar28);
          iVar26 = *(int *)(param_1 + 0x160);
          uVar20 = uVar29 + *(int *)(((unsigned char *)0x00003188) + iVar28);
          uVar31 = iVar26 - (*(int *)(((unsigned char *)0x0000318c) + iVar28) + *(int *)(((unsigned char *)0x00003184) + iVar28));
          iVar28 = *(int *)(((unsigned char *)0x0000318c) + iVar28) + uVar31;
          if ((int)uVar29 < 0) {
            uVar29 = 0;
          }
          if ((int)uVar31 < 0) {
            uVar31 = 0;
          }
          iVar19 = *(int *)(param_1 + 0x15c);
          uVar45 = iVar19 + 7U & 0xfffffff8;
          if ((int)uVar45 < (int)uVar20) {
            uVar20 = uVar45;
          }
          iVar23 = iVar26;
          if (iVar28 <= iVar26) {
            iVar23 = iVar28;
          }
          uVar20 = uVar20 - uVar29;
          iVar28 = iVar23 - uVar31;
        }
        if ((uVar20 != 0) && (iVar28 != 0)) {
          pvVar22 = _malloc((iVar19 + 7U & 0xfffffff8) * iVar26 * 2);
          fVar1 = FLOAT_001aa0e0;
          iVar26 = *(int *)(param_1 + 0x160);
          uVar44 = uVar29 + uVar20;
          iVar19 = *(int *)(param_1 + 0x15c);
          cVar14 = *(char *)(param_1 + 0x140);
          uVar45 = iVar19 + 7U & 0xfffffff8;
          uVar13 = uVar31 + iVar28;
          iVar23 = uVar29 + uVar45 * ((iVar26 - uVar31) + -1);
          if (*(char *)(param_1 + 0x141) == '\x01') {
            if (fparam_1 == (double)FLOAT_001aa0e8) {
              if (uVar31 < uVar13) {
                iVar34 = *(int *)(param_1 + 0x148);
                iVar36 = 0;
                do {
                  pbVar35 = (byte *)(iVar23 * 4 + iVar34);
                  puVar42 = (ushort *)((int)pvVar22 + iVar23 * 2);
                  pbVar32 = pbVar35 + uVar20 * 4;
                  if (cVar14 == '\0') {
                    for (; pbVar35 < pbVar32; pbVar35 = pbVar35 + 4) {
                      *puVar42 = ((short)(char)pbVar35[3] & 0x40U) << 9 | (*pbVar35 & 0x7c) << 8 |
                                 (pbVar35[1] & 0x7c) << 3 | pbVar35[2] >> 2 & 0x1f;
                      puVar42 = puVar42 + 1;
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
                      *puVar42 = (ushort)(iVar16 << 9) & 0x8000 | (ushort)(iVar40 << 8) & 0x7c00 |
                                 (ushort)(iVar15 << 3) & 0x3e0 | uVar27 & 0x1f;
                      puVar42 = puVar42 + 1;
                    }
                  }
                  iVar36 = iVar36 + 1;
                  iVar23 = iVar23 - uVar45;
                } while (uVar13 - uVar31 != iVar36);
              }
            }
            else {
              fVar2 = (float)(fparam_1 * (double)FLOAT_001aa0dc);
              if (uVar31 < uVar13) {
                iVar34 = *(int *)(param_1 + 0x148);
                iVar36 = 0;
                do {
                  dVar51 = DOUBLE_001aa1e0;
                  fVar12 = FLOAT_001aa0ec;
                  fVar11 = FLOAT_001aa0d4;
                  pcVar37 = (char *)(iVar23 * 4 + iVar34);
                  puVar42 = (ushort *)((int)pvVar22 + iVar23 * 2);
                  iVar40 = uVar44 - uVar29;
                  if (uVar29 < uVar44) {
                    do {
                      fVar5 = fVar2 * (float)((double)CONCAT44(0x43300000,(int)*pcVar37 ^ 0x80000000
                                                              ) - dVar51);
                      fVar9 = FLOAT_001aa0d4;
                      if (fVar11 <= fVar5) {
                        fVar9 = fVar5 * fVar12;
                      }
                      fVar5 = fVar2 * (float)((double)CONCAT44(0x43300000,
                                                               (int)pcVar37[1] ^ 0x80000000) -
                                             dVar51);
                      fVar7 = FLOAT_001aa0d4;
                      if (FLOAT_001aa0d4 <= fVar5) {
                        fVar7 = fVar5 * fVar12;
                      }
                      fVar5 = fVar2 * (float)((double)CONCAT44(0x43300000,
                                                               (int)pcVar37[2] ^ 0x80000000) -
                                             dVar51);
                      fVar8 = FLOAT_001aa0d4;
                      if (FLOAT_001aa0d4 <= fVar5) {
                        fVar8 = fVar5 * fVar12;
                      }
                      fVar5 = fVar2 * (float)((double)CONCAT44(0x43300000,
                                                               (int)pcVar37[3] ^ 0x80000000) -
                                             dVar51);
                      fVar6 = FLOAT_001aa0d4;
                      if (FLOAT_001aa0d4 <= fVar5) {
                        fVar6 = fVar5 * fVar1;
                      }
                      pcVar37 = pcVar37 + 4;
                      *puVar42 = (ushort)(int)fVar8 |
                                 (ushort)((int)fVar6 << 0xf) | (ushort)((int)fVar9 << 10) |
                                 (ushort)((int)fVar7 << 5);
                      puVar42 = puVar42 + 1;
                      iVar40 = iVar40 + -1;
                    } while (iVar40 != 0);
                  }
                  iVar36 = iVar36 + 1;
                  iVar23 = iVar23 - uVar45;
                } while (uVar13 - uVar31 != iVar36);
              }
            }
          }
          else if (fparam_1 == (double)FLOAT_001aa0e8) {
            if (uVar31 < uVar13) {
              iVar34 = *(int *)(param_1 + 0x148);
              iVar36 = 0;
              do {
                puVar42 = (ushort *)(iVar23 * 8 + iVar34);
                puVar33 = (ushort *)((int)pvVar22 + iVar23 * 2);
                puVar48 = puVar42 + uVar20 * 4;
                if (cVar14 == '\0') {
                  for (; puVar42 < puVar48; puVar42 = puVar42 + 4) {
                    *puVar33 = (puVar42[3] & 0x4000) << 1 | *puVar42 & 0x7c00 |
                               (ushort)((uint)(int)(short)puVar42[1] >> 5) & 0x3e0 |
                               (ushort)((uint)(int)(short)puVar42[2] >> 10) & 0x1f;
                    puVar33 = puVar33 + 1;
                  }
                }
                else {
                  for (; puVar42 < puVar48; puVar42 = puVar42 + 4) {
                    uVar27 = 0;
                    if (-1 < (short)*puVar42) {
                      uVar27 = *puVar42 & 0x7c00;
                    }
                    uVar41 = 0;
                    if (-1 < (short)puVar42[1]) {
                      uVar41 = (short)puVar42[1] >> 5;
                    }
                    uVar21 = 0;
                    if (-1 < (short)puVar42[2]) {
                      uVar21 = (short)puVar42[2] >> 10;
                    }
                    iVar40 = 0;
                    if (-1 < (short)puVar42[3]) {
                      iVar40 = (int)(short)puVar42[3];
                    }
                    *puVar33 = uVar27 | (ushort)(iVar40 << 1) & 0x8000 | uVar41 & 0x3e0 |
                               uVar21 & 0x1f;
                    puVar33 = puVar33 + 1;
                  }
                }
                iVar36 = iVar36 + 1;
                iVar23 = iVar23 - uVar45;
              } while (uVar13 - uVar31 != iVar36);
            }
          }
          else {
            fVar2 = (float)(fparam_1 * (double)FLOAT_001aa0e4);
            if (uVar31 < uVar13) {
              iVar34 = *(int *)(param_1 + 0x148);
              iVar36 = 0;
              do {
                dVar51 = DOUBLE_001aa1e0;
                fVar12 = FLOAT_001aa0ec;
                fVar11 = FLOAT_001aa0d4;
                psVar38 = (short *)(iVar23 * 8 + iVar34);
                puVar42 = (ushort *)((int)pvVar22 + iVar23 * 2);
                iVar40 = uVar44 - uVar29;
                if (uVar29 < uVar44) {
                  do {
                    fVar5 = fVar2 * (float)((double)CONCAT44(0x43300000,(int)*psVar38 ^ 0x80000000)
                                           - dVar51);
                    fVar9 = FLOAT_001aa0d4;
                    if (fVar11 <= fVar5) {
                      fVar9 = fVar5 * fVar12;
                    }
                    fVar5 = fVar2 * (float)((double)CONCAT44(0x43300000,(int)psVar38[1] ^ 0x80000000
                                                            ) - dVar51);
                    fVar7 = FLOAT_001aa0d4;
                    if (FLOAT_001aa0d4 <= fVar5) {
                      fVar7 = fVar5 * fVar12;
                    }
                    fVar5 = fVar2 * (float)((double)CONCAT44(0x43300000,(int)psVar38[2] ^ 0x80000000
                                                            ) - dVar51);
                    fVar8 = FLOAT_001aa0d4;
                    if (FLOAT_001aa0d4 <= fVar5) {
                      fVar8 = fVar5 * fVar12;
                    }
                    fVar5 = fVar2 * (float)((double)CONCAT44(0x43300000,(int)psVar38[3] ^ 0x80000000
                                                            ) - dVar51);
                    fVar6 = FLOAT_001aa0d4;
                    if (FLOAT_001aa0d4 <= fVar5) {
                      fVar6 = fVar5 * fVar1;
                    }
                    psVar38 = psVar38 + 4;
                    *puVar42 = (ushort)(int)fVar8 |
                               (ushort)((int)fVar6 << 0xf) | (ushort)((int)fVar9 << 10) |
                               (ushort)((int)fVar7 << 5);
                    puVar42 = puVar42 + 1;
                    iVar40 = iVar40 + -1;
                  } while (iVar40 != 0);
                }
                iVar36 = iVar36 + 1;
                iVar23 = iVar23 - uVar45;
              } while (uVar13 - uVar31 != iVar36);
            }
          }
          FUN_000198b0(param_1,uVar29,uVar31,uVar20,iVar28,0x8366,
                       (void *)((int)pvVar22 +
                               (((iVar26 - uVar31) - iVar28) * (iVar19 + 7U & 0xfffffff8) + uVar29)
                               * 2));
          goto code_r0x00003264;
        }
      }
    }
    break;
  case 0x103:
    iVar19 = *(int *)(param_1 + 0x10);
    if (((unsigned char *)0x00003190)[iVar19] == '\0') {
      iVar23 = *(int *)(param_1 + 0x15c);
      iVar19 = *(int *)(param_1 + 0x160);
      iVar34 = 0;
      iVar36 = 0;
      uVar20 = iVar23 + 7U & 0xfffffff8;
      iVar26 = iVar19;
    }
    else {
      iVar34 = *(int *)(((unsigned char *)0x00003180) + iVar19);
      iVar26 = *(int *)(param_1 + 0x160);
      uVar20 = iVar34 + *(int *)(((unsigned char *)0x00003188) + iVar19);
      iVar36 = iVar26 - (*(int *)(((unsigned char *)0x0000318c) + iVar19) + *(int *)(((unsigned char *)0x00003184) + iVar19));
      iVar40 = *(int *)(((unsigned char *)0x0000318c) + iVar19) + iVar36;
      if (iVar34 < 0) {
        iVar34 = 0;
      }
      if (iVar36 < 0) {
        iVar36 = 0;
      }
      iVar23 = *(int *)(param_1 + 0x15c);
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
    if (fparam_1 < dVar51) {
      *(undefined1 *)(param_1 + 0x140) = 1;
    }
    uVar29 = iVar23 + 7U & 0xfffffff8;
    iVar34 = iVar34 + uVar29 * ((iVar26 - iVar36) + -1);
    if (fparam_1 != dVar51) {
      fVar1 = (float)((double)FLOAT_001aa0e8 / fparam_1);
      if ((((fVar1 == FLOAT_001aa0f8) || (fVar1 == FLOAT_001aa0fc)) || (fVar1 == FLOAT_001aa100)) ||
         ((fVar1 == FLOAT_001aa104 || (fVar1 == FLOAT_001aa108)))) {
        iVar26 = (int)((double)FLOAT_001aa0e8 / fparam_1);
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
        if (*(char *)(param_1 + 0x141) == '\x01') {
          if (iVar19 <= iVar36) {
            return;
          }
          iVar26 = 0;
          while( true ) {
            pcVar37 = (char *)(iVar34 * 4 + iVar28);
            pcVar30 = pcVar37 + iVar40;
            for (; pcVar37 < pcVar30; pcVar37 = pcVar37 + 4) {
              *pcVar37 = (char)((int)*pcVar37 >> iVar23);
              pcVar37[1] = (char)((int)pcVar37[1] >> iVar23);
              pcVar37[2] = (char)((int)pcVar37[2] >> iVar23);
              pcVar37[3] = (char)((int)pcVar37[3] >> iVar23);
            }
            iVar26 = iVar26 + 1;
            iVar34 = iVar34 - uVar29;
            if (iVar26 == iVar19 - iVar36) break;
            iVar28 = *(int *)(param_1 + 0x148);
          }
          return;
        }
        if (iVar19 <= iVar36) {
          return;
        }
        iVar26 = 0;
        while( true ) {
          psVar38 = (short *)(iVar34 * 8 + iVar28);
          psVar39 = psVar38 + uVar20 * 4;
          for (; psVar38 < psVar39; psVar38 = psVar38 + 4) {
            *psVar38 = (short)((int)*psVar38 >> iVar23);
            psVar38[1] = (short)((int)psVar38[1] >> iVar23);
            psVar38[2] = (short)((int)psVar38[2] >> iVar23);
            psVar38[3] = (short)((int)psVar38[3] >> iVar23);
          }
          iVar26 = iVar26 + 1;
          iVar34 = iVar34 - uVar29;
          if (iVar26 == iVar19 - iVar36) break;
          iVar28 = *(int *)(param_1 + 0x148);
        }
        return;
      }
    }
    if ((((fparam_1 != (double)FLOAT_001aa0f8) && (fparam_1 != (double)FLOAT_001aa0fc)) &&
        (fparam_1 != (double)FLOAT_001aa100)) &&
       ((fparam_1 != (double)FLOAT_001aa104 && (fparam_1 != (double)FLOAT_001aa108)))) {
      if (*(char *)(param_1 + 0x141) == '\x01') {
        if (iVar19 <= iVar36) {
          return;
        }
        iVar26 = 0;
        while( true ) {
          dVar51 = DOUBLE_001aa1e0;
          pcVar37 = (char *)(iVar34 * 4 + iVar28);
          pcVar30 = pcVar37 + iVar40;
          for (; pcVar37 < pcVar30; pcVar37 = pcVar37 + 4) {
            *pcVar37 = (char)(int)(fparam_1 *
                                  (double)(float)((double)CONCAT44(0x43300000,
                                                                   (int)*pcVar37 ^ 0x80000000) -
                                                 dVar51));
            pcVar37[1] = (char)(int)(fparam_1 *
                                    (double)(float)((double)CONCAT44(0x43300000,
                                                                     (int)pcVar37[1] ^ 0x80000000) -
                                                   dVar51));
            pcVar37[2] = (char)(int)(fparam_1 *
                                    (double)(float)((double)CONCAT44(0x43300000,
                                                                     (int)pcVar37[2] ^ 0x80000000) -
                                                   dVar51));
            pcVar37[3] = (char)(int)(fparam_1 *
                                    (double)(float)((double)CONCAT44(0x43300000,
                                                                     (int)pcVar37[3] ^ 0x80000000) -
                                                   dVar51));
          }
          iVar26 = iVar26 + 1;
          iVar34 = iVar34 - uVar29;
          if (iVar26 == iVar19 - iVar36) break;
          iVar28 = *(int *)(param_1 + 0x148);
        }
        return;
      }
      if (iVar19 <= iVar36) {
        return;
      }
      iVar26 = 0;
      while( true ) {
        dVar51 = DOUBLE_001aa1e0;
        psVar38 = (short *)(iVar34 * 8 + iVar28);
        psVar39 = psVar38 + uVar20 * 4;
        for (; psVar38 < psVar39; psVar38 = psVar38 + 4) {
          *psVar38 = (short)(int)(fparam_1 *
                                 (double)(float)((double)CONCAT44(0x43300000,
                                                                  (int)*psVar38 ^ 0x80000000) -
                                                dVar51));
          psVar38[1] = (short)(int)(fparam_1 *
                                   (double)(float)((double)CONCAT44(0x43300000,
                                                                    (int)psVar38[1] ^ 0x80000000) -
                                                  dVar51));
          psVar38[2] = (short)(int)(fparam_1 *
                                   (double)(float)((double)CONCAT44(0x43300000,
                                                                    (int)psVar38[2] ^ 0x80000000) -
                                                  dVar51));
          psVar38[3] = (short)(int)(fparam_1 *
                                   (double)(float)((double)CONCAT44(0x43300000,
                                                                    (int)psVar38[3] ^ 0x80000000) -
                                                  dVar51));
        }
        iVar26 = iVar26 + 1;
        iVar34 = iVar34 - uVar29;
        if (iVar26 == iVar19 - iVar36) break;
        iVar28 = *(int *)(param_1 + 0x148);
      }
      return;
    }
    iVar26 = (int)fparam_1;
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
    if (*(char *)(param_1 + 0x141) == '\x01') {
      if (iVar36 < iVar19) {
        iVar26 = 0;
        while( true ) {
          pcVar37 = (char *)(iVar34 * 4 + iVar28);
          pcVar30 = pcVar37 + iVar40;
          for (; pcVar37 < pcVar30; pcVar37 = pcVar37 + 4) {
            *pcVar37 = *pcVar37 << iVar23;
            pcVar37[1] = pcVar37[1] << iVar23;
            pcVar37[2] = pcVar37[2] << iVar23;
            pcVar37[3] = pcVar37[3] << iVar23;
          }
          iVar26 = iVar26 + 1;
          iVar34 = iVar34 - uVar29;
          if (iVar26 == iVar19 - iVar36) break;
          iVar28 = *(int *)(param_1 + 0x148);
        }
      }
    }
    else if (iVar36 < iVar19) {
      iVar26 = 0;
      while( true ) {
        psVar38 = (short *)(iVar34 * 8 + iVar28);
        psVar39 = psVar38 + uVar20 * 4;
        for (; psVar38 < psVar39; psVar38 = psVar38 + 4) {
          *psVar38 = (short)((int)*psVar38 << iVar23);
          psVar38[1] = (short)((int)psVar38[1] << iVar23);
          psVar38[2] = (short)((int)psVar38[2] << iVar23);
          psVar38[3] = (short)((int)psVar38[3] << iVar23);
        }
        iVar26 = iVar26 + 1;
        iVar34 = iVar34 - uVar29;
        if (iVar26 == iVar19 - iVar36) break;
        iVar28 = *(int *)(param_1 + 0x148);
      }
    }
    break;
  case 0x104:
    iVar19 = *(int *)(param_1 + 0x10);
    if (((unsigned char *)0x00003190)[iVar19] == '\0') {
      iVar23 = *(int *)(param_1 + 0x15c);
      iVar19 = *(int *)(param_1 + 0x160);
      iVar34 = 0;
      iVar36 = 0;
      uVar20 = iVar23 + 7U & 0xfffffff8;
      iVar26 = iVar19;
    }
    else {
      iVar34 = *(int *)(((unsigned char *)0x00003180) + iVar19);
      iVar26 = *(int *)(param_1 + 0x160);
      uVar20 = iVar34 + *(int *)(((unsigned char *)0x00003188) + iVar19);
      iVar36 = iVar26 - (*(int *)(((unsigned char *)0x0000318c) + iVar19) + *(int *)(((unsigned char *)0x00003184) + iVar19));
      iVar40 = *(int *)(((unsigned char *)0x0000318c) + iVar19) + iVar36;
      if (iVar34 < 0) {
        iVar34 = 0;
      }
      if (iVar36 < 0) {
        iVar36 = 0;
      }
      iVar23 = *(int *)(param_1 + 0x15c);
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
      if (fparam_1 < (double)FLOAT_001aa0d4) {
        *(undefined1 *)(param_1 + 0x140) = 1;
      }
      uVar29 = iVar23 + 7U & 0xfffffff8;
      iVar34 = iVar34 + uVar29 * ((iVar26 - iVar36) + -1);
      if (*(char *)(param_1 + 0x141) == '\x01') {
        cVar14 = (char)(int)(fparam_1 * (double)FLOAT_001aa0f4);
        if (iVar36 < iVar19) {
          iVar26 = 0;
          while( true ) {
            pcVar37 = (char *)(iVar34 * 4 + iVar28);
            pcVar30 = pcVar37 + uVar20 * 4;
            for (; pcVar37 < pcVar30; pcVar37 = pcVar37 + 4) {
              *pcVar37 = cVar14 + *pcVar37;
              pcVar37[1] = cVar14 + pcVar37[1];
              pcVar37[2] = cVar14 + pcVar37[2];
              pcVar37[3] = cVar14 + pcVar37[3];
            }
            iVar26 = iVar26 + 1;
            iVar34 = iVar34 - uVar29;
            if (iVar26 == iVar19 - iVar36) break;
            iVar28 = *(int *)(param_1 + 0x148);
          }
        }
      }
      else {
        sStack_da = (short)(int)(fparam_1 * (double)FLOAT_001aa0d8);
        if (iVar36 < iVar19) {
          iVar26 = 0;
          while( true ) {
            psVar38 = (short *)(iVar34 * 8 + iVar28);
            psVar39 = psVar38 + uVar20 * 4;
            for (; psVar38 < psVar39; psVar38 = psVar38 + 4) {
              *psVar38 = sStack_da + *psVar38;
              psVar38[1] = sStack_da + psVar38[1];
              psVar38[2] = sStack_da + psVar38[2];
              psVar38[3] = sStack_da + psVar38[3];
            }
            iVar26 = iVar26 + 1;
            iVar34 = iVar34 - uVar29;
            if (iVar26 == iVar19 - iVar36) break;
            iVar28 = *(int *)(param_1 + 0x148);
          }
        }
      }
    }
  }
  return;
}

/* _gldSetInteger @ 0x5630 (1116 bytes) */
int _gldSetInteger(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  uint *param_3;
{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  bool bVar5;
  uint local_28;
  uint local_24;
  uint local_20;
  uint local_1c;
  
  if (param_3 == (uint *)0x0) {
    return 0x271e;
  }
  iVar2 = FUN_00017100(param_1,param_2,param_3);
  if (iVar2 != 0) {
    return 0;
  }
  if (param_2 == 0x124) {
    local_28 = *param_3;
    iVar2 = _io_connect_method_scalarI_structureI(*(undefined4 *)(param_1 + 4),0xc,&local_28,1,0,0);
    uVar3 = 0x2719;
joined_r0x000058fc:
    if (iVar2 != 0) {
      return uVar3;
    }
  }
  else {
    if (param_2 < 0x125) {
      if (param_2 == 0xcb) {
        local_28 = (uint)*(byte *)(param_1 + 0x142);
        local_24 = *param_3;
        *(char *)(param_1 + 0x146) = (char)local_24;
        _io_connect_method_scalarI_structureI(*(undefined4 *)(param_1 + 4),2,&local_28,2,0,0);
        return 0;
      }
      if (param_2 < 0xcc) {
        if (param_2 == 200) {
          if ((-1 < (int)param_3[2]) && (-1 < (int)param_3[3])) {
            local_28 = *param_3;
            *(uint *)(param_1 + 0x124) = local_28;
            local_24 = param_3[1];
            *(uint *)(param_1 + 0x128) = local_24;
            local_20 = param_3[2];
            *(uint *)(param_1 + 300) = local_20;
            local_1c = param_3[3];
            *(uint *)(param_1 + 0x130) = local_1c;
            if (*(char *)(param_1 + 0x144) == '\0') {
              return 0;
            }
            _io_connect_method_scalarI_structureI(*(undefined4 *)(param_1 + 4),1,&local_28,4,0,0);
            return 0;
          }
          return 0x2718;
        }
        if (param_2 == 0xc9) {
          bVar5 = *param_3 != 0;
          if (bVar5 == (bool)*(char *)(param_1 + 0x144)) {
            return 0;
          }
          *(bool *)(param_1 + 0x144) = bVar5;
          if (bVar5) {
            local_28 = *(uint *)(param_1 + 0x124);
            local_24 = *(undefined4 *)(param_1 + 0x128);
            local_20 = *(undefined4 *)(param_1 + 300);
            local_1c = *(undefined4 *)(param_1 + 0x130);
          }
          else {
            local_28 = 0;
            local_24 = 0;
            local_20 = 0;
            local_1c = 0;
          }
          _io_connect_method_scalarI_structureI(*(undefined4 *)(param_1 + 4),1,&local_28,4,0,0);
          return 0;
        }
      }
      else {
        if (param_2 == 0xde) {
          local_28 = *param_3;
          local_24 = (uint)*(byte *)(param_1 + 0x146);
          *(char *)(param_1 + 0x142) = (char)local_28;
          _io_connect_method_scalarI_structureI(*(undefined4 *)(param_1 + 4),2,&local_28,2,0,0);
          return 0;
        }
        if (param_2 == 0xec) {
          return 0;
        }
      }
LAB_00005690:
      uVar3 = FUN_00017310(param_1,param_2,param_3);
      return uVar3;
    }
    if (param_2 == 0x29a) {
      *(char *)(param_1 + 0x21) = '\x01' - (*param_3 == 0);
      return 0;
    }
    if (param_2 < 0x29b) {
      if (param_2 == 0x12a) {
        *(undefined1 *)(param_1 + 0x145) = 1;
        *(uint *)(param_1 + 0x134) = *param_3;
        *(uint *)(param_1 + 0x138) = param_3[1];
        *(uint *)(param_1 + 0x13c) = param_3[2];
        return 0;
      }
      if (param_2 != 0x132) goto LAB_00005690;
      uVar3 = *(undefined4 *)(param_1 + 4);
      uVar4 = 0x10;
      local_28 = (uint)(*param_3 != 0);
      *(bool *)(param_1 + 0x147) = *param_3 != 0;
    }
    else {
      if (param_2 == 0x29d) {
        iVar2 = *(int *)(*(int *)(param_1 + 0x18) + 0x194);
        if (iVar2 == 0) {
          return 0;
        }
        local_28 = *(uint *)(iVar2 + 0x228);
      }
      else {
        if (param_2 == 0x1f96) {
          local_28 = *param_3;
          local_24 = param_3[1];
          if (local_28 == 0) {
            *(uint *)(param_1 + 0x3c) = *(uint *)(param_1 + 0x3c) & 0xffffffef;
            *(undefined1 *)(*(int *)(param_1 + 0x14) + 0x26) = 0;
          }
          else {
            *(uint *)(param_1 + 0x3c) = *(uint *)(param_1 + 0x3c) | 0x10;
            *(undefined1 *)(*(int *)(param_1 + 0x14) + 0x26) = 1;
          }
          iVar2 = _io_connect_method_scalarI_structureI
                            (*(undefined4 *)(param_1 + 4),0x13,&local_28,2,0,0);
          uVar3 = 0x2712;
          goto joined_r0x000058fc;
        }
        if (param_2 != 0x29c) goto LAB_00005690;
        uVar1 = param_3[1];
        if (0xf < *param_3) {
          return 0x2718;
        }
        if (uVar1 == 0x806f) {
          iVar2 = 1;
        }
        else if (uVar1 < 0x8070) {
          if (uVar1 == 0xde0) {
            iVar2 = 4;
          }
          else {
            if (uVar1 != 0xde1) {
              return 0x271a;
            }
            iVar2 = 3;
          }
        }
        else if (uVar1 == 0x84f5) {
          iVar2 = 2;
        }
        else {
          if (uVar1 != 0x8513) {
            return 0x271a;
          }
          iVar2 = 0;
        }
        iVar2 = *(int *)(*(int *)(param_1 + 0x18) + (*param_3 * 5 + iVar2) * 4);
        if (iVar2 == 0) {
          return 0;
        }
        local_28 = *(uint *)(iVar2 + 0x34);
      }
      if (local_28 == 0) {
        return 0;
      }
      uVar3 = *(undefined4 *)(param_1 + 4);
      uVar4 = 0xf;
    }
    _io_connect_method_scalarI_structureI(uVar3,uVar4,&local_28,1,0,0);
  }
  return 0;
}

/* _gldGetInteger @ 0x5aa0 (616 bytes) */
int _gldGetInteger(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  uint param_2;
  uint *param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 local_28;
  uint local_24;
  uint local_20;
  uint local_1c;
  
  if (param_3 == (uint *)0x0) {
    return 0x271e;
  }
  if (param_2 == 0xde) {
    *param_3 = (uint)*(byte *)(param_1 + 0x142);
    return 0;
  }
  if (param_2 < 0xdf) {
    if (param_2 == 0xc9) {
      *param_3 = (uint)*(byte *)(param_1 + 0x144);
      return 0;
    }
    if (param_2 != 0xcb) {
      if (param_2 != 200) {
        return 0x271a;
      }
      *param_3 = *(uint *)(param_1 + 0x124);
      param_3[1] = *(uint *)(param_1 + 0x128);
      param_3[2] = *(uint *)(param_1 + 300);
      param_3[3] = *(uint *)(param_1 + 0x130);
      return 0;
    }
    *param_3 = (uint)*(byte *)(param_1 + 0x146);
    return 0;
  }
  if (param_2 == 0x132) {
    *param_3 = (uint)*(byte *)(param_1 + 0x147);
    return 0;
  }
  if (param_2 < 0x133) {
    if (param_2 != 0x126) {
      return 0x271a;
    }
    uVar3 = *param_3;
    if (((*(byte *)(uVar3 + 0x39) & 7) != 0) &&
       (iVar1 = FUN_00032100(param_1,uVar3,param_3,param_4,param_5,param_6), iVar1 == 0)) {
      *param_3 = 0;
      return 0;
    }
    *param_3 = *(uint *)(*(int *)(uVar3 + 0x34) + 4);
    return 0;
  }
  if (param_2 == 0x29a) {
    *param_3 = (uint)*(byte *)(param_1 + 0x21);
    return 0;
  }
  if (param_2 != 0x3e3) {
    return 0x271a;
  }
  local_28 = 3;
  iVar1 = _io_connect_method_scalarI_scalarO
                    (*(undefined4 *)(param_1 + 4),6,param_3,1,&local_24,&local_28);
  if (iVar1 == 0) {
    switch(local_24 & 0xf) {
    case 3:
      *param_3 = 0x1908;
      param_3[1] = 0x8366;
      break;
    case 4:
      *param_3 = 0x1908;
      param_3[1] = 0x8367;
      break;
    default:
      goto switchD_00005c44_caseD_5;
    case 6:
    case 7:
    case 8:
    case 9:
      *param_3 = 0x85b9;
      param_3[1] = 0x85bb;
      break;
    case 10:
      *param_3 = 0x80e1;
      param_3[1] = 0x8367;
      break;
    case 0xb:
      *param_3 = 0x1908;
      param_3[1] = (uint)((unsigned char *)0x00001403U);
      break;
    case 0xc:
      *param_3 = 0x1908;
      param_3[1] = (uint)((unsigned char *)0x0000140bU);
      break;
    case 0xd:
      *param_3 = 0x1908;
      param_3[1] = (uint)((unsigned char *)0x00001406U);
    }
    uVar2 = 0;
    param_3[2] = local_20;
    param_3[3] = local_1c;
  }
  else {
switchD_00005c44_caseD_5:
    uVar2 = 0x2722;
  }
  return uVar2;
}

/* _gldCreateBuffer @ 0x5d50 (96 bytes) */
int _gldCreateBuffer(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  int *param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_malloc(0x24);
  _memset(puVar1,0,0x24);
  *param_2 = (int)puVar1;
  *puVar1 = param_3;
  puVar1[1] = param_4;
  puVar1[2] = 0;
  return 0;
}

/* FUN_00005db0 @ 0x5db0 (244 bytes) */
int FUN_00005db0(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  if ((*(int **)(param_2 + 8) != (int *)0x0) && (iVar3 = **(int **)(param_2 + 8), iVar3 != 0)) {
    if (*(char *)(iVar3 + 0x16) == '\x06') {
      if (0x1ffff < *(int *)(iVar3 + 0x10)) {
        _gldFlush(param_1);
      }
      iVar1 = FUN_0001a0d0(param_1,*(undefined4 *)(iVar3 + 8));
      if (iVar1 == 0) {
        uVar2 = *(undefined4 *)(param_1 + 4);
        iVar3 = iVar3 + 8;
LAB_00005e6c:
        _io_connect_method_scalarI_structureI(uVar2,9,iVar3,1,0,0);
        return;
      }
    }
    else if (*(char *)(iVar3 + 0x16) == '\a') {
      if (0x1ffff < *(int *)(iVar3 + 0x10)) {
        _gldFlush(param_1);
      }
      iVar1 = FUN_0001a0d0(param_1,*(undefined4 *)(iVar3 + 0xc));
      if (iVar1 == 0) {
        uVar2 = *(undefined4 *)(param_1 + 4);
        iVar3 = iVar3 + 0xc;
        goto LAB_00005e6c;
      }
    }
  }
  return;
}

/* FUN_00005eb0 @ 0x5eb0 (184 bytes) */
int FUN_00005eb0(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  undefined4 uVar1;
  int iVar2;
  
  if ((*(int **)(param_2 + 8) != (int *)0x0) && (iVar2 = **(int **)(param_2 + 8), iVar2 != 0)) {
    if (*(char *)(iVar2 + 0x16) == '\x06') {
      if (0x1ffff < *(int *)(iVar2 + 0x10)) {
        _gldFlush(param_1);
      }
      uVar1 = FUN_0001a0d0(param_1,*(undefined4 *)(iVar2 + 8));
      return uVar1;
    }
    if (*(char *)(iVar2 + 0x16) == '\a') {
      if (0x1ffff < *(int *)(iVar2 + 0x10)) {
        _gldFlush(param_1);
      }
      uVar1 = FUN_0001a0d0(param_1,*(undefined4 *)(iVar2 + 0xc));
      return uVar1;
    }
  }
  return 1;
}

/* _gldFlushBuffer @ 0x5f70 (164 bytes) */
int _gldFlushBuffer(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  undefined4 param_1;
  int param_2;
  int param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  int *piVar1;
  int iVar2;
  
  piVar1 = *(int **)(param_2 + 8);
  if ((piVar1 != (int *)0x0) && (*piVar1 != 0)) {
    if (param_3 != 0) {
      FUN_0000b620(param_1,param_3,param_4,param_4,param_5,param_6,param_7,param_8);
      piVar1 = *(int **)(param_2 + 8);
    }
    if (*(char *)(*piVar1 + 0x16) == '\a') {
      *(undefined1 *)(*piVar1 + 0x14) = 1;
      iVar2 = **(int **)(param_2 + 8);
      *(ushort *)(iVar2 + 0x28) = *(ushort *)(iVar2 + 0x28) & ~*(ushort *)(iVar2 + 0x1c);
    }
    **(uint **)(param_2 + 4) = **(uint **)(param_2 + 4) & 0xfffffffc;
  }
  return;
}

/* _gldGetMemoryPluginData @ 0x6020 (60 bytes) */
int _gldGetMemoryPluginData(param_1, param_2, param_3)
  undefined4 param_1;
  int param_2;
  int *param_3;
{
  int *piVar1;
  int iVar2;
  
  piVar1 = *(int **)(param_2 + 8);
  if ((piVar1 != (int *)0x0) && (iVar2 = *piVar1, iVar2 != 0)) {
    *(ushort *)(iVar2 + 0x1c) = *(ushort *)(iVar2 + 0x1c) | *(ushort *)(iVar2 + 0x28);
    piVar1 = *(int **)(param_2 + 8);
  }
  *param_3 = (int)piVar1;
  *(undefined4 *)(param_2 + 8) = 0;
  return;
}

/* _gldSetMemoryPluginData @ 0x6060 (100 bytes) */
int _gldSetMemoryPluginData(param_1, param_2, param_3)
  undefined4 param_1;
  int param_2;
  int *param_3;
{
  int iVar1;
  
  *(int **)(param_2 + 8) = param_3;
  if (param_3 == (int *)0x0) {
    return;
  }
  iVar1 = *param_3;
  if (iVar1 == 0) {
    return;
  }
  *(undefined1 *)(iVar1 + 0x14) = 1;
  if (*(char *)(**(int **)(param_2 + 8) + 0x16) == '\a') {
    *(ushort *)(iVar1 + 0x28) = *(ushort *)(iVar1 + 0x28) & ~*(ushort *)(iVar1 + 0x1c);
  }
  **(uint **)(param_2 + 4) = **(uint **)(param_2 + 4) & 0xfffffffe;
  return;
}

/* _gldFinishMemoryPluginData @ 0x60d0 (212 bytes) */
int _gldFinishMemoryPluginData(param_1, param_2)
  int param_1;
  int *param_2;
{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  if ((param_2 == (int *)0x0) || (iVar3 = *param_2, iVar3 == 0)) {
    return;
  }
  if ((0x1ffff < (int)*(uint *)(iVar3 + 0x10)) || ((*(uint *)(iVar3 + 0x10) & 0xffff) != 0)) {
    _gldFlush(param_1);
  }
  if (*(char *)(iVar3 + 0x16) == '\x06') {
    iVar1 = FUN_0001a0d0(param_1,*(undefined4 *)(iVar3 + 8));
    if (iVar1 != 0) {
      return;
    }
    uVar2 = *(undefined4 *)(param_1 + 4);
    iVar3 = iVar3 + 8;
  }
  else {
    if (*(char *)(iVar3 + 0x16) != '\a') {
      return;
    }
    iVar1 = FUN_0001a0d0(param_1,*(undefined4 *)(iVar3 + 0xc));
    if (iVar1 != 0) {
      return;
    }
    uVar2 = *(undefined4 *)(param_1 + 4);
    iVar3 = iVar3 + 0xc;
  }
  _io_connect_method_scalarI_structureI(uVar2,9,iVar3,1,0,0);
  return;
}

/* _gldTestMemoryPluginData @ 0x61b0 (156 bytes) */
int _gldTestMemoryPluginData(param_1, param_2)
  undefined4 param_1;
  int *param_2;
{
  undefined4 uVar1;
  int iVar2;
  
  if ((param_2 == (int *)0x0) || (iVar2 = *param_2, iVar2 == 0)) {
LAB_00006230:
    uVar1 = 1;
  }
  else {
    if (*(char *)(iVar2 + 0x16) == '\x06') {
      if (*(int *)(iVar2 + 0x10) < 0x20000) {
        uVar1 = FUN_0001a0d0(param_1,*(undefined4 *)(iVar2 + 8));
        return uVar1;
      }
    }
    else {
      if (*(char *)(iVar2 + 0x16) != '\a') goto LAB_00006230;
      if (*(int *)(iVar2 + 0x10) < 0x20000) {
        uVar1 = FUN_0001a0d0(param_1,*(undefined4 *)(iVar2 + 0xc));
        return uVar1;
      }
    }
    uVar1 = 0;
  }
  return uVar1;
}

/* _gldDestroyMemoryPluginData @ 0x6260 (212 bytes) */
int _gldDestroyMemoryPluginData(param_1, param_2)
  int param_1;
  int *param_2;
{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  char in_RESERVE;
  byte bVar5;
  
  bVar5 = (param_2 == (int *)0x0) << 1;
  if (param_2 != (int *)0x0) {
    iVar4 = *param_2;
    if (iVar4 != 0) {
      if ((0x1ffff < (int)*(uint *)(iVar4 + 0x10)) || ((*(uint *)(iVar4 + 0x10) & 0xffff) != 0)) {
        _gldFlush(param_1);
      }
      ((int (*)())_gldFinishMemoryPluginData)(param_1,param_2);
      piVar2 = (int *)(iVar4 + 0x10);
      do {
        iVar3 = *piVar2;
        if (in_RESERVE != '\0') {
          iVar1 = storeWordConditionalIndexed(iVar3 + -0x10000,0,piVar2);
          *piVar2 = iVar1;
          bVar5 = 2;
        }
      } while (!(bool)(bVar5 >> 1 & 1));
      if (iVar3 == 0x10000) {
        _io_connect_method_scalarI_structureI(*(undefined4 *)(param_1 + 4),0xb,iVar4,1,0,0);
      }
      *param_2 = 0;
    }
    _free(param_2);
    return;
  }
  return;
}

/* _gldReclaimBuffer @ 0x6340 (236 bytes) */
int _gldReclaimBuffer(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  char in_RESERVE;
  byte in_cr0;
  
  piVar2 = *(int **)(param_2 + 8);
  if (piVar2 != (int *)0x0) {
    iVar4 = *piVar2;
    if (iVar4 != 0) {
      if ((0x1ffff < (int)*(uint *)(iVar4 + 0x10)) || ((*(uint *)(iVar4 + 0x10) & 0xffff) != 0)) {
        _gldFlush(param_1);
      }
      ((int (*)())FUN_00005db0)(param_1,param_2);
      piVar2 = (int *)(iVar4 + 0x10);
      do {
        iVar3 = *piVar2;
        if (in_RESERVE != '\0') {
          iVar1 = storeWordConditionalIndexed(iVar3 + -0x10000,0,piVar2);
          *piVar2 = iVar1;
          in_cr0 = 2;
        }
      } while (!(bool)(in_cr0 >> 1 & 1));
      if (iVar3 == 0x10000) {
        _io_connect_method_scalarI_structureI(*(undefined4 *)(param_1 + 4),0xb,iVar4,1,0,0);
      }
      **(undefined4 **)(param_2 + 8) = 0;
      *(undefined4 *)(*(int *)(param_2 + 8) + 4) = 0;
      piVar2 = *(int **)(param_2 + 8);
    }
    _free(piVar2);
    *(undefined4 *)(param_2 + 8) = 0;
  }
  return;
}

/* _gldDestroyBuffer @ 0x6430 (56 bytes) */
int _gldDestroyBuffer(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  ((int (*)())_gldReclaimBuffer)(param_1,param_2);
  _free(param_2);
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
int _gldCreateContext(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int *param_1;
  int param_2;
  uint param_3;
  int param_4;
  uint param_5;
  uint param_6;
  uint param_7;
{
  short sVar1;
  undefined *puVar2;
  uint uVar3;
  int iVar4;
  uint *puVar5;
  uint uVar6;
  uint uVar7;
  undefined4 uVar8;
  uint *puVar9;
  uint *puVar10;
  undefined4 uVar11;
  int iVar12;
  uint local_48 [6];
  
  if (param_1 == (int *)0x0) {
    return 0x271e;
  }
  *param_1 = 0;
  iVar4 = FUN_0001ac30(param_2);
  puVar2 = PTR_DAT_001e88ac;
  if (iVar4 != 0) {
    return iVar4;
  }
  if (((*(uint *)(param_2 + 0x30) & *(uint *)PTR_DAT_001e88ac) == 0) ||
     ((*(uint *)(param_2 + 0x30) & ~*(uint *)PTR_DAT_001e88ac) != 0)) {
    return 0x2716;
  }
  puVar5 = (uint *)_malloc(((unsigned char *)0x00002b98U));
  if (*(int *)(puVar2 + 4) != 0) {
    local_48[0] = 0;
    if ((*(uint *)(param_2 + 0x30) & 1) == 0) {
      do {
        local_48[0] = local_48[0] + 1;
        if (*(uint *)(PTR_DAT_001e88ac + 4) <= local_48[0]) break;
      } while ((1 << (local_48[0] & 0x3f) & *(uint *)(param_2 + 0x30)) == 0);
      goto LAB_00006798;
    }
  }
  local_48[0] = 0;
LAB_00006798:
  *puVar5 = local_48[0];
  puVar2 = PTR_DAT_001e88ac;
  puVar5[1] = 0;
  iVar4 = _IOServiceOpen(*(undefined4 *)(local_48[0] * 4 + *(int *)(puVar2 + 8)),
                         *(undefined4 *)PTR_001e88b4,1,puVar5 + 1);
  if (iVar4 == 0) {
    if ((param_4 == 0) ||
       (iVar4 = _IOConnectAddClient(puVar5[1],*(undefined4 *)(param_4 + 4)), iVar4 == 0)) {
      local_48[0] = 3;
      iVar4 = _io_connect_method_scalarI_scalarO(puVar5[1],3,0,0,puVar5 + 9,local_48);
      puVar2 = PTR_001e88b4;
      if (iVar4 == 0) {
        uVar8 = *(undefined4 *)PTR_001e88b4;
        puVar5[0x8e] = 0;
        iVar4 = _IOConnectMapMemory(puVar5[1],0,uVar8,puVar5 + 0x8e,local_48,0x101);
        if (iVar4 == 0) {
          uVar8 = *(undefined4 *)puVar2;
          puVar5[0x79] = 0;
          iVar4 = _IOConnectMapMemory(puVar5[1],1,uVar8,puVar5 + 0x79,puVar5 + 0x7a,1);
          if (iVar4 == 0) {
            uVar8 = *(undefined4 *)puVar2;
            puVar5[0x82] = 0;
            puVar5[0x7f] = 0;
            puVar5[0x80] = 0;
            puVar5[0x7d] = 0;
            puVar5[0x7e] = 0;
            puVar5[0x81] = 0;
            iVar4 = _IOConnectMapMemory(puVar5[1],2,uVar8,puVar5 + 0x82,puVar5 + 0x83,1);
            if (iVar4 == 0) {
              uVar8 = *(undefined4 *)puVar2;
              puVar9 = puVar5 + 0x86;
              puVar10 = puVar5 + 0x87;
              uVar11 = 1;
              puVar5[0x86] = 0;
              iVar4 = _IOConnectMapMemory(puVar5[1],4,uVar8,puVar9,puVar10,1);
              if (iVar4 == 0) {
                uVar6 = _malloc(puVar5[0x87] >> 5);
                puVar5[0x88] = uVar6;
                uVar7 = puVar5[0x87] >> 5;
                _memset(uVar6,0,uVar7);
                puVar5[0x8d] = 0;
                puVar5[0x89] = 0;
                puVar5[0x8a] = 0;
                puVar5[0x8b] = 0;
                uVar6 = *(uint *)PTR_001e88b0;
                puVar5[0x8c] = 0;
                if ((uVar6 & 8) == 0) {
                  if ((uVar6 & 0x10) == 0) {
                    *(undefined1 *)(puVar5 + 2) = 0x20;
                  }
                  else {
                    *(undefined1 *)(puVar5 + 2) = 0x80;
                  }
                }
                else {
                  *(undefined1 *)(puVar5 + 2) = 0x40;
                }
                uVar6 = (uint)DAT_001f65e0;
                puVar5[0x8f] = 0;
                DAT_001f65e0 = puVar5 + 0xae4;
                puVar5[0xae4] = (uint)puVar5;
                puVar5[0xae5] = uVar6;
                puVar5[3] = param_3;
                puVar5[4] = param_6;
                puVar5[6] = param_7;
                puVar5[0xd] = 0;
                uVar6 = *(uint *)(param_2 + 8);
                puVar5[0x45] = 0x19;
                puVar5[0x46] = 0x32;
                puVar5[0xf] = 0;
                *(undefined1 *)((int)puVar5 + 0x143) = 1;
                puVar5[5] = param_5;
                puVar5[7] = 0;
                puVar5[0xc] = 0;
                puVar5[0xe] = 0;
                puVar5[0x41] = 0;
                puVar5[0x42] = 0;
                puVar5[0x43] = 0;
                puVar5[0x44] = 0;
                puVar5[0x54] = 0;
                puVar5[0x85] = 0;
                puVar5[0x84] = 0;
                puVar5[0x5e] = 0;
                if ((uVar6 & 0x800) != 0) {
                  puVar5[0xf] = 0x2000;
                }
                uVar3 = *(uint *)(param_2 + 0xc);
                if ((uVar3 & 8) == 0) {
                  if ((uVar6 & 2) == 0) {
                    puVar5[0xf] = puVar5[0xf] | 0x800;
                  }
                }
                else {
                  puVar5[0xf] = puVar5[0xf] | 0x400;
                }
                uVar3 = uVar3 & 2;
                if (uVar3 != 0) {
                  puVar5[0xf] = puVar5[0xf] | 0x10;
                }
                uVar6 = *(uint *)(param_2 + 0x10);
                if ((uVar6 & 0xfffffc) == 0) {
                  if ((uVar6 & 0x3f000000) != 0) {
                    uVar3 = uVar6 & 0x3f00000;
                    if (uVar3 == 0) {
                      if ((uVar6 & 0xc000000) != 0) {
                        puVar5[0xf] = puVar5[0xf] | 0xd;
                      }
                    }
                    else {
                      puVar5[0xf] = puVar5[0xf] | 0xc;
                    }
                  }
                }
                else {
                  uVar3 = uVar6 & 0x3fc0;
                  if (uVar3 == 0) {
                    if ((uVar6 & 0xfc000) == 0) {
                      uVar3 = uVar6 & 0x3f00000;
                      if (uVar3 != 0) {
                        puVar5[0xf] = puVar5[0xf] | 0xb;
                      }
                    }
                    else {
                      puVar5[0xf] = puVar5[0xf] | 4;
                    }
                  }
                  else {
                    puVar5[0xf] = puVar5[0xf] | 3;
                  }
                }
                if (*(int *)(param_2 + 0x18) != 1) {
                  puVar5[0xf] = puVar5[0xf] | 0x40;
                }
                if (*(int *)(param_2 + 0x1c) != 1) {
                  puVar5[0xf] = puVar5[0xf] | 0x80;
                }
                if (*(int *)(param_2 + 0x14) == 0x8000) {
                  *(undefined1 *)((int)puVar5 + 0x141) = 1;
                }
                else if (*(int *)(param_2 + 0x14) == 0x800000) {
                  *(undefined1 *)((int)puVar5 + 0x141) = 2;
                }
                else {
                  *(undefined1 *)((int)puVar5 + 0x141) = 0;
                }
                sVar1 = *(short *)(param_2 + 0x22);
                *(undefined1 *)(puVar5 + 0x50) = 0;
                puVar5[0x52] = 0;
                puVar5[0x53] = 0;
                if (sVar1 == 1) {
                  puVar5[0xf] = puVar5[0xf] | 0x100;
                }
                else if (sVar1 == 2) {
                  puVar5[0xf] = puVar5[0xf] | 0x200;
                }
                if (0 < *(short *)(param_2 + 0x24)) {
                  puVar5[0xf] = puVar5[0xf] | 0x1000;
                }
                FUN_00017a40(puVar5 + 0xf,param_2,uVar7,puVar9,puVar10,uVar11,uVar3);
                uVar7 = puVar5[0xf];
                puVar5[0xe] = 0x4000;
                if ((uVar7 & 0x40) != 0) {
                  puVar5[0xe] = (uint)((unsigned char *)0x00004100U);
                }
                if ((uVar7 & 0x80) == 0) {
                  uVar6 = puVar5[0xe];
                }
                else {
                  uVar6 = puVar5[0xe] | 0x400;
                  puVar5[0xe] = uVar6;
                }
                if (*(char *)((int)puVar5 + 0x141) != '\0') {
                  uVar6 = uVar6 | 0x200;
                  puVar5[0xe] = uVar6;
                }
                *(undefined1 *)((int)puVar5 + 0x146) = 1;
                puVar5[0x55] = uVar7;
                puVar5[0x56] = uVar6;
                puVar5[0x58] = puVar5[0x42];
                puVar5[0x59] = puVar5[0x43];
                puVar5[0x5a] = puVar5[0x44];
                puVar5[0x5b] = puVar5[0x45];
                puVar5[0x5c] = puVar5[0x46];
                *(undefined1 *)((int)puVar5 + 0x21) = 1;
                *(undefined1 *)((int)puVar5 + 0x147) = 0;
                puVar5[0x3e] = 0;
                *(undefined1 *)(puVar5 + 8) = 0;
                puVar5[0x49] = 0;
                puVar5[0x4a] = 0;
                puVar5[0x4b] = 0;
                puVar5[0x4c] = 0;
                *(undefined1 *)(puVar5 + 0x51) = 0;
                *(undefined1 *)((int)puVar5 + 0x142) = 0;
                *(undefined1 *)((int)puVar5 + 0x145) = 0;
                puVar5[0x47] = 0;
                puVar5[0x48] = 0;
                puVar5[0x5d] = 3;
                puVar5[0x57] = puVar5[0x41];
                iVar12 = 0x10;
                iVar4 = 0;
                do {
                  puVar5[iVar4 + 99] = 0;
                  iVar12 = iVar12 + -1;
                  iVar4 = iVar4 + 1;
                } while (iVar12 != 0);
                uVar7 = 0;
                do {
                  local_48[0] = uVar7 + 1;
                  puVar5[uVar7 + 0x73] = 0;
                  uVar7 = local_48[0];
                } while (local_48[0] < 2);
                puVar5[0x62] = 0;
                puVar5[0x5f] = 0;
                puVar5[0x60] = 0;
                puVar5[0x61] = 0;
                if ((puVar5[9] & 2) == 0) {
                  *(undefined4 *)(param_5 + 0x94) = 3;
                }
                else {
                  *(undefined4 *)(param_5 + 0x94) = 1;
                }
                FUN_00017750(puVar5,param_5,param_2);
                _memcpy(puVar5 + 0x10,param_5 + 0x24,0x3c);
                FUN_0002c790(puVar5,param_2);
                *param_1 = (int)puVar5;
                return 0;
              }
            }
          }
        }
      }
    }
    _IOServiceClose(puVar5[1]);
    _free(puVar5);
  }
  else {
    _free(puVar5);
  }
  return 0x271f;
}

/* _gldDestroyContext @ 0x6dd0 (216 bytes) */
int _gldDestroyContext(param_1)
  int param_1;
{
  undefined4 uVar1;
  int *piVar2;
  int *piVar3;
  
  uVar1 = 0x2714;
  if (param_1 != 0) {
    FUN_00007020(param_1);
    FUN_0002cb40(param_1);
    _IOServiceClose(*(undefined4 *)(param_1 + 4));
    if (DAT_001f65e0 != (int *)0x0) {
      piVar2 = DAT_001f65e0;
      if (param_1 == *DAT_001f65e0) {
        DAT_001f65e0 = (int *)DAT_001f65e0[1];
      }
      else {
        do {
          piVar3 = piVar2;
          piVar2 = (int *)piVar3[1];
          if (piVar2 == (int *)0x0) goto LAB_00006e50;
        } while (param_1 != *piVar2);
        piVar3[1] = piVar2[1];
      }
    }
LAB_00006e50:
    if (*(int *)(param_1 + 0x148) != 0) {
      _free(*(int *)(param_1 + 0x148));
    }
    if (*(int *)(param_1 + 0x220) != 0) {
      _free(*(int *)(param_1 + 0x220));
    }
    _free(param_1);
    uVar1 = 0;
  }
  return uVar1;
}

/* _gldCreateShared @ 0x6ec0 (128 bytes) */
int _gldCreateShared(param_1)
  int *param_1;
{
  undefined4 uVar1;
  int iVar2;
  undefined1 auStack_28 [28];
  
  uVar1 = 0x271e;
  if (param_1 != (int *)0x0) {
    *param_1 = 0;
    iVar2 = _malloc(0x34);
    uVar1 = 0x2720;
    if (iVar2 != 0) {
      _pthread_mutexattr_init(auStack_28);
      _pthread_mutexattr_settype(auStack_28,2);
      _pthread_mutex_init(iVar2,auStack_28);
      FUN_00024fb0(iVar2);
      *param_1 = iVar2;
      uVar1 = 0;
    }
  }
  return uVar1;
}

