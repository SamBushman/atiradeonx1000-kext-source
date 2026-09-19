#include "decls.h"

/* FUN_00001770 @ 0x1770 (32 bytes) */
int FUN_00001770()
{
                    
                    
  (*DAT_001e8744)();
  return;
}

/* FUN_000017b8 @ 0x17b8 (120 bytes) */
int FUN_000017b8(param_1)
  undefined4 *param_1;
{
  int iVar1;
  undefined4 *puStack00000018;
  
  puStack00000018 = param_1;
  iVar1 = (*(code *)param_1[1])(((unsigned char *)0x00001790),param_1,param_1);
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
  
  ((int (*)())FUN_00001770)("__dyld_image_count",&local_34);
  ((int (*)())FUN_00001770)("__dyld_get_image_name",&local_30);
  ((int (*)())FUN_00001770)("__dyld_get_image_header",&local_2c);
  ((int (*)())FUN_00001770)("__dyld_NSLookupSymbolInImage",&local_28);
  ((int (*)())FUN_00001770)("__dyld_NSAddressOfSymbol",local_24);
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

/* FUN_00001af4 @ 0x1af4 (32 bytes) */
int FUN_00001af4(param_1, param_2)
  char *param_1;
  char *param_2;
{
  _strcmp(param_1,param_2);
  return;
}

/* FUN_00001b34 @ 0x1b34 (528 bytes) */
int FUN_00001b34()
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
      uVar2 = ((int (*)())FUN_000018fc)();
      *(undefined4 *)((int)local_20 + 0x10) = uVar2;
      if ((*(int *)((int)local_20 + 0x10) != 0) &&
         (iVar1 = (**(code **)((int)local_20 + 0x10))(((unsigned char *)0x0000228c)), iVar1 == 0))
      goto LAB_00001d08;
    }
    else {
      uVar2 = _dlsym(iVar1,"__cxa_atexit");
      *(undefined4 *)((int)local_20 + 8) = uVar2;
      uVar2 = _dlsym(iVar1,"__cxa_finalize");
      *(undefined4 *)((int)local_20 + 0xc) = uVar2;
      if (((*(int *)((int)local_20 + 8) != 0) && (*(int *)((int)local_20 + 0xc) != 0)) &&
         (iVar3 = ((int (*)())FUN_00001830)(*(undefined4 *)((int)local_20 + 8),
                               *(undefined4 *)((int)local_20 + 0xc)), iVar3 != -1)) {
        if (iVar3 == 0) {
          *(undefined1 *)((int)local_20 + 3) = 2;
        }
        else {
          uVar2 = _dlsym(iVar1,"atexit");
          *(undefined4 *)((int)local_20 + 0x10) = uVar2;
          if (*(int *)((int)local_20 + 0x10) == 0) goto LAB_00001d14;
          *(undefined1 *)((int)local_20 + 3) = 0x10;
        }
        goto LAB_00001d08;
      }
    }
LAB_00001d14:
    __keymgr_set_and_unlock_processwide_ptr(0xe,local_20);
    local_18 = (void *)0x0;
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

/* FUN_00001f70 @ 0x1f70 (292 bytes) */
int FUN_00001f70(param_1, param_2)
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

/* FUN_00002094 @ 0x2094 (32 bytes) */
int FUN_00002094()
{
  __keymgr_get_and_lock_processwide_ptr();
  return;
}

/* FUN_0000222c @ 0x222c (32 bytes) */
int FUN_0000222c()
{
  ((int (*)())FUN_00001f70)();
  return;
}

/* FUN_00002348 @ 0x2348 (32 bytes) */
int FUN_00002348()
{
  __keymgr_set_and_unlock_processwide_ptr();
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
  undefined4 *puVar4;
  undefined4 uVar5;
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
          local_18 = (*pcVar1)(((unsigned char *)0x000020f4),puVar4,uStack0000001c);
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
        local_18 = (*pcVar1)(*puStack00000018,puStack00000018[2],uStack0000001c);
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
          uStack_18 = (*pcVar1)(((unsigned char *)0x000020f4),puVar4,uStack0000001c);
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
          uStack_18 = (*pcVar1)(((unsigned char *)0x000020f4),puVar4,uStack0000001c);
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

/* _gldSetInteger @ 0x5630 (1116 bytes) */
int _gldSetInteger(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  uint *param_3;
{
  uint uVar1;
  int iVar2;
  undefined *puVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  bool bVar6;
  uint local_28;
  uint local_24;
  uint local_20;
  uint local_1c;
  
  if (param_3 == (uint *)0x0) {
    return ((unsigned char *)0x0000271e);
  }
  iVar2 = FUN_00017100();
  if (iVar2 != 0) {
    return (undefined *)0x0;
  }
  if (param_2 == 0x124) {
    local_28 = *param_3;
    iVar2 = _io_connect_method_scalarI_structureI(*(undefined4 *)(param_1 + 4),0xc,&local_28,1,0,0);
    puVar3 = ((unsigned char *)0x00002719);
joined_r0x000058fc:
    if (iVar2 != 0) {
      return puVar3;
    }
  }
  else {
    if (param_2 < 0x125) {
      if (param_2 == 0xcb) {
        local_28 = (uint)*(byte *)(param_1 + 0x142);
        local_24 = *param_3;
        *(char *)(param_1 + 0x146) = (char)local_24;
        _io_connect_method_scalarI_structureI(*(undefined4 *)(param_1 + 4),2,&local_28,2,0,0);
        return (undefined *)0x0;
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
              return (undefined *)0x0;
            }
            _io_connect_method_scalarI_structureI(*(undefined4 *)(param_1 + 4),1,&local_28,4,0,0);
            return (undefined *)0x0;
          }
LAB_00005a78:
          return ((unsigned char *)0x00002718);
        }
        if (param_2 == 0xc9) {
          bVar6 = *param_3 != 0;
          if (bVar6 == (bool)*(char *)(param_1 + 0x144)) {
            return (undefined *)0x0;
          }
          *(bool *)(param_1 + 0x144) = bVar6;
          if (bVar6) {
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
          return (undefined *)0x0;
        }
      }
      else {
        if (param_2 == 0xde) {
          local_28 = *param_3;
          local_24 = (uint)*(byte *)(param_1 + 0x146);
          *(char *)(param_1 + 0x142) = (char)local_28;
          _io_connect_method_scalarI_structureI(*(undefined4 *)(param_1 + 4),2,&local_28,2,0,0);
          return (undefined *)0x0;
        }
        if (param_2 == 0xec) {
          return (undefined *)0x0;
        }
      }
LAB_00005690:
      puVar3 = (undefined *)FUN_00017310(param_1,param_2,param_3);
      return puVar3;
    }
    if (param_2 == 0x29a) {
      *(char *)(param_1 + 0x21) = '\x01' - (*param_3 == 0);
      return (undefined *)0x0;
    }
    if (param_2 < 0x29b) {
      if (param_2 == 0x12a) {
        *(undefined1 *)(param_1 + 0x145) = 1;
        *(uint *)(param_1 + 0x134) = *param_3;
        *(uint *)(param_1 + 0x138) = param_3[1];
        *(uint *)(param_1 + 0x13c) = param_3[2];
        return (undefined *)0x0;
      }
      if (param_2 != 0x132) goto LAB_00005690;
      uVar4 = *(undefined4 *)(param_1 + 4);
      uVar5 = 0x10;
      local_28 = (uint)(*param_3 != 0);
      *(bool *)(param_1 + 0x147) = *param_3 != 0;
    }
    else {
      if (param_2 == 0x29d) {
        iVar2 = *(int *)(*(int *)(param_1 + 0x18) + 0x194);
        if (iVar2 == 0) {
          return (undefined *)0x0;
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
          puVar3 = ((unsigned char *)0x00002712);
          goto joined_r0x000058fc;
        }
        if (param_2 != 0x29c) goto LAB_00005690;
        uVar1 = param_3[1];
        if (0xf < *param_3) goto LAB_00005a78;
        if (uVar1 == 0x806f) {
          iVar2 = 1;
        }
        else if (uVar1 < 0x8070) {
          if (uVar1 == 0xde0) {
            iVar2 = 4;
          }
          else {
            if (uVar1 != 0xde1) {
LAB_00005960:
              return ((unsigned char *)0x0000271a);
            }
            iVar2 = 3;
          }
        }
        else if (uVar1 == 0x84f5) {
          iVar2 = 2;
        }
        else {
          if (uVar1 != 0x8513) goto LAB_00005960;
          iVar2 = 0;
        }
        iVar2 = *(int *)(*(int *)(param_1 + 0x18) + (*param_3 * 5 + iVar2) * 4);
        if (iVar2 == 0) {
          return (undefined *)0x0;
        }
        local_28 = *(uint *)(iVar2 + 0x34);
      }
      if (local_28 == 0) {
        return (undefined *)0x0;
      }
      uVar4 = *(undefined4 *)(param_1 + 4);
      uVar5 = 0xf;
    }
    _io_connect_method_scalarI_structureI(uVar4,uVar5,&local_28,1,0,0);
  }
  return (undefined *)0x0;
}

/* _gldGetInteger @ 0x5aa0 (616 bytes) */
int _gldGetInteger(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  uint *param_3;
{
  int iVar1;
  undefined *puVar2;
  uint uVar3;
  undefined4 local_28;
  uint local_24;
  uint local_20;
  uint local_1c;
  
  if (param_3 == (uint *)0x0) {
    return ((unsigned char *)0x0000271e);
  }
  if (param_2 == 0xde) {
    *param_3 = (uint)*(byte *)(param_1 + 0x142);
    return (undefined *)0x0;
  }
  if (param_2 < 0xdf) {
    if (param_2 == 0xc9) {
      *param_3 = (uint)*(byte *)(param_1 + 0x144);
      return (undefined *)0x0;
    }
    if (param_2 == 0xcb) {
      *param_3 = (uint)*(byte *)(param_1 + 0x146);
      return (undefined *)0x0;
    }
    if (param_2 == 200) {
      *param_3 = *(uint *)(param_1 + 0x124);
      param_3[1] = *(uint *)(param_1 + 0x128);
      param_3[2] = *(uint *)(param_1 + 300);
      param_3[3] = *(uint *)(param_1 + 0x130);
      return (undefined *)0x0;
    }
LAB_00005b20:
    return ((unsigned char *)0x0000271a);
  }
  if (param_2 == 0x132) {
    *param_3 = (uint)*(byte *)(param_1 + 0x147);
    return (undefined *)0x0;
  }
  if (param_2 < 0x133) {
    if (param_2 == 0x126) {
      uVar3 = *param_3;
      if (((*(byte *)(uVar3 + 0x39) & 7) != 0) && (iVar1 = FUN_00032100(param_1,uVar3), iVar1 == 0))
      {
        *param_3 = 0;
        return (undefined *)0x0;
      }
      *param_3 = *(uint *)(*(int *)(uVar3 + 0x34) + 4);
      return (undefined *)0x0;
    }
    goto LAB_00005b20;
  }
  if (param_2 == 0x29a) {
    *param_3 = (uint)*(byte *)(param_1 + 0x21);
    return (undefined *)0x0;
  }
  if (param_2 != 0x3e3) goto LAB_00005b20;
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
      param_3[1] = (uint)((unsigned char *)0x00001403);
      break;
    case 0xc:
      *param_3 = 0x1908;
      param_3[1] = (uint)((unsigned char *)0x0000140b);
      break;
    case 0xd:
      *param_3 = 0x1908;
      param_3[1] = (uint)((unsigned char *)0x00001406);
    }
    puVar2 = (undefined *)0x0;
    param_3[2] = local_20;
    param_3[3] = local_1c;
  }
  else {
switchD_00005c44_caseD_5:
    puVar2 = ((unsigned char *)0x00002722);
  }
  return puVar2;
}

/* _gldCreateBuffer @ 0x5d50 (96 bytes) */
int _gldCreateBuffer(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 *param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  undefined4 *puVar1;
  
  puVar1 = _malloc(0x24);
  _memset(puVar1,0,0x24);
  *param_2 = puVar1;
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
        _gldFlush();
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
        _gldFlush();
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
        _gldFlush();
      }
      uVar1 = FUN_0001a0d0(param_1,*(undefined4 *)(iVar2 + 8));
      return uVar1;
    }
    if (*(char *)(iVar2 + 0x16) == '\a') {
      if (0x1ffff < *(int *)(iVar2 + 0x10)) {
        _gldFlush();
      }
      uVar1 = FUN_0001a0d0(param_1,*(undefined4 *)(iVar2 + 0xc));
      return uVar1;
    }
  }
  return 1;
}

/* _gldFlushBuffer @ 0x5f70 (164 bytes) */
int _gldFlushBuffer(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  int param_2;
  int param_3;
  undefined4 param_4;
{
  int *piVar1;
  int iVar2;
  
  piVar1 = *(int **)(param_2 + 8);
  if ((piVar1 != (int *)0x0) && (*piVar1 != 0)) {
    if (param_3 != 0) {
      FUN_0000b620(param_1,param_3,param_4);
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
    _gldFlush();
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
        _gldFlush();
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
        _gldFlush();
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
  void *param_2;
{
  ((int (*)())_gldReclaimBuffer)();
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
    piVar2 = _malloc(8);
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
    piVar2 = _malloc(8);
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
  undefined4 *param_1;
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
  uint uVar4;
  undefined *puVar5;
  uint *puVar6;
  int iVar7;
  void *pvVar8;
  undefined4 uVar9;
  int iVar10;
  uint local_48 [6];
  
  if (param_1 == (undefined4 *)0x0) {
    return ((unsigned char *)0x0000271e);
  }
  *param_1 = 0;
  puVar5 = (undefined *)FUN_0001ac30(param_2);
  puVar2 = PTR_DAT_001e88ac;
  if (puVar5 != (undefined *)0x0) {
    return puVar5;
  }
  if (((*(uint *)(param_2 + 0x30) & *(uint *)PTR_DAT_001e88ac) == 0) ||
     ((*(uint *)(param_2 + 0x30) & ~*(uint *)PTR_DAT_001e88ac) != 0)) {
    return ((unsigned char *)0x00002716);
  }
  puVar6 = _malloc(0x2b98);
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
  *puVar6 = local_48[0];
  puVar2 = PTR_DAT_001e88ac;
  puVar6[1] = 0;
  iVar7 = _IOServiceOpen(*(undefined4 *)(local_48[0] * 4 + *(int *)(puVar2 + 8)),
                         *(undefined4 *)PTR_001e88b4,1,puVar6 + 1);
  if (iVar7 == 0) {
    if ((param_4 == 0) ||
       (iVar7 = _IOConnectAddClient(puVar6[1],*(undefined4 *)(param_4 + 4)), iVar7 == 0)) {
      local_48[0] = 3;
      iVar7 = _io_connect_method_scalarI_scalarO(puVar6[1],3,0,0,puVar6 + 9,local_48);
      puVar2 = PTR_001e88b4;
      if (iVar7 == 0) {
        uVar9 = *(undefined4 *)PTR_001e88b4;
        puVar6[0x8e] = 0;
        iVar7 = _IOConnectMapMemory(puVar6[1],0,uVar9,puVar6 + 0x8e,local_48,0x101);
        if (iVar7 == 0) {
          uVar9 = *(undefined4 *)puVar2;
          puVar6[0x79] = 0;
          iVar7 = _IOConnectMapMemory(puVar6[1],1,uVar9,puVar6 + 0x79,puVar6 + 0x7a,1);
          if (iVar7 == 0) {
            uVar9 = *(undefined4 *)puVar2;
            puVar6[0x82] = 0;
            puVar6[0x7f] = 0;
            puVar6[0x80] = 0;
            puVar6[0x7d] = 0;
            puVar6[0x7e] = 0;
            puVar6[0x81] = 0;
            iVar7 = _IOConnectMapMemory(puVar6[1],2,uVar9,puVar6 + 0x82,puVar6 + 0x83,1);
            if (iVar7 == 0) {
              uVar9 = *(undefined4 *)puVar2;
              puVar6[0x86] = 0;
              iVar7 = _IOConnectMapMemory(puVar6[1],4,uVar9,puVar6 + 0x86,puVar6 + 0x87,1);
              if (iVar7 == 0) {
                pvVar8 = _malloc(puVar6[0x87] >> 5);
                puVar6[0x88] = (uint)pvVar8;
                _memset(pvVar8,0,puVar6[0x87] >> 5);
                puVar6[0x8d] = 0;
                puVar6[0x89] = 0;
                puVar6[0x8a] = 0;
                puVar6[0x8b] = 0;
                uVar3 = *(uint *)PTR_001e88b0;
                puVar6[0x8c] = 0;
                if ((uVar3 & 8) == 0) {
                  if ((uVar3 & 0x10) == 0) {
                    *(undefined1 *)(puVar6 + 2) = 0x20;
                  }
                  else {
                    *(undefined1 *)(puVar6 + 2) = 0x80;
                  }
                }
                else {
                  *(undefined1 *)(puVar6 + 2) = 0x40;
                }
                uVar3 = (uint)DAT_001f65e0;
                puVar6[0x8f] = 0;
                DAT_001f65e0 = puVar6 + 0xae4;
                puVar6[0xae4] = (uint)puVar6;
                puVar6[0xae5] = uVar3;
                puVar6[3] = param_3;
                puVar6[4] = param_6;
                puVar6[6] = param_7;
                puVar6[0xd] = 0;
                uVar3 = *(uint *)(param_2 + 8);
                puVar6[0x45] = 0x19;
                puVar6[0x46] = 0x32;
                puVar6[0xf] = 0;
                *(undefined1 *)((int)puVar6 + 0x143) = 1;
                puVar6[5] = param_5;
                puVar6[7] = 0;
                puVar6[0xc] = 0;
                puVar6[0xe] = 0;
                puVar6[0x41] = 0;
                puVar6[0x42] = 0;
                puVar6[0x43] = 0;
                puVar6[0x44] = 0;
                puVar6[0x54] = 0;
                puVar6[0x85] = 0;
                puVar6[0x84] = 0;
                puVar6[0x5e] = 0;
                if ((uVar3 & 0x800) != 0) {
                  puVar6[0xf] = 0x2000;
                }
                uVar4 = *(uint *)(param_2 + 0xc);
                if ((uVar4 & 8) == 0) {
                  if ((uVar3 & 2) == 0) {
                    puVar6[0xf] = puVar6[0xf] | 0x800;
                  }
                }
                else {
                  puVar6[0xf] = puVar6[0xf] | 0x400;
                }
                if ((uVar4 & 2) != 0) {
                  puVar6[0xf] = puVar6[0xf] | 0x10;
                }
                uVar3 = *(uint *)(param_2 + 0x10);
                if ((uVar3 & 0xfffffc) == 0) {
                  if ((uVar3 & 0x3f000000) != 0) {
                    if ((uVar3 & 0x3f00000) == 0) {
                      if ((uVar3 & 0xc000000) != 0) {
                        puVar6[0xf] = puVar6[0xf] | 0xd;
                      }
                    }
                    else {
                      puVar6[0xf] = puVar6[0xf] | 0xc;
                    }
                  }
                }
                else if ((uVar3 & 0x3fc0) == 0) {
                  if ((uVar3 & 0xfc000) == 0) {
                    if ((uVar3 & 0x3f00000) != 0) {
                      puVar6[0xf] = puVar6[0xf] | 0xb;
                    }
                  }
                  else {
                    puVar6[0xf] = puVar6[0xf] | 4;
                  }
                }
                else {
                  puVar6[0xf] = puVar6[0xf] | 3;
                }
                if (*(int *)(param_2 + 0x18) != 1) {
                  puVar6[0xf] = puVar6[0xf] | 0x40;
                }
                if (*(int *)(param_2 + 0x1c) != 1) {
                  puVar6[0xf] = puVar6[0xf] | 0x80;
                }
                if (*(int *)(param_2 + 0x14) == 0x8000) {
                  *(undefined1 *)((int)puVar6 + 0x141) = 1;
                }
                else if (*(int *)(param_2 + 0x14) == 0x800000) {
                  *(undefined1 *)((int)puVar6 + 0x141) = 2;
                }
                else {
                  *(undefined1 *)((int)puVar6 + 0x141) = 0;
                }
                sVar1 = *(short *)(param_2 + 0x22);
                *(undefined1 *)(puVar6 + 0x50) = 0;
                puVar6[0x52] = 0;
                puVar6[0x53] = 0;
                if (sVar1 == 1) {
                  puVar6[0xf] = puVar6[0xf] | 0x100;
                }
                else if (sVar1 == 2) {
                  puVar6[0xf] = puVar6[0xf] | 0x200;
                }
                if (0 < *(short *)(param_2 + 0x24)) {
                  puVar6[0xf] = puVar6[0xf] | 0x1000;
                }
                FUN_00017a40(puVar6 + 0xf,param_2);
                uVar3 = puVar6[0xf];
                puVar6[0xe] = 0x4000;
                if ((uVar3 & 0x40) != 0) {
                  puVar6[0xe] = (uint)((unsigned char *)0x00004100);
                }
                if ((uVar3 & 0x80) == 0) {
                  uVar4 = puVar6[0xe];
                }
                else {
                  uVar4 = puVar6[0xe] | 0x400;
                  puVar6[0xe] = uVar4;
                }
                if (*(char *)((int)puVar6 + 0x141) != '\0') {
                  uVar4 = uVar4 | 0x200;
                  puVar6[0xe] = uVar4;
                }
                *(undefined1 *)((int)puVar6 + 0x146) = 1;
                puVar6[0x55] = uVar3;
                puVar6[0x56] = uVar4;
                puVar6[0x58] = puVar6[0x42];
                puVar6[0x59] = puVar6[0x43];
                puVar6[0x5a] = puVar6[0x44];
                puVar6[0x5b] = puVar6[0x45];
                puVar6[0x5c] = puVar6[0x46];
                *(undefined1 *)((int)puVar6 + 0x21) = 1;
                *(undefined1 *)((int)puVar6 + 0x147) = 0;
                puVar6[0x3e] = 0;
                *(undefined1 *)(puVar6 + 8) = 0;
                puVar6[0x49] = 0;
                puVar6[0x4a] = 0;
                puVar6[0x4b] = 0;
                puVar6[0x4c] = 0;
                *(undefined1 *)(puVar6 + 0x51) = 0;
                *(undefined1 *)((int)puVar6 + 0x142) = 0;
                *(undefined1 *)((int)puVar6 + 0x145) = 0;
                puVar6[0x47] = 0;
                puVar6[0x48] = 0;
                puVar6[0x5d] = 3;
                puVar6[0x57] = puVar6[0x41];
                iVar10 = 0x10;
                iVar7 = 0;
                do {
                  puVar6[iVar7 + 99] = 0;
                  iVar10 = iVar10 + -1;
                  iVar7 = iVar7 + 1;
                } while (iVar10 != 0);
                uVar3 = 0;
                do {
                  local_48[0] = uVar3 + 1;
                  puVar6[uVar3 + 0x73] = 0;
                  uVar3 = local_48[0];
                } while (local_48[0] < 2);
                puVar6[0x62] = 0;
                puVar6[0x5f] = 0;
                puVar6[0x60] = 0;
                puVar6[0x61] = 0;
                if ((puVar6[9] & 2) == 0) {
                  *(undefined4 *)(param_5 + 0x94) = 3;
                }
                else {
                  *(undefined4 *)(param_5 + 0x94) = 1;
                }
                FUN_00017750(puVar6,param_5,param_2);
                _memcpy(puVar6 + 0x10,(void *)(param_5 + 0x24),0x3c);
                FUN_0002c790(puVar6,param_2);
                *param_1 = puVar6;
                return (undefined *)0x0;
              }
            }
          }
        }
      }
    }
    _IOServiceClose(puVar6[1]);
    _free(puVar6);
  }
  else {
    _free(puVar6);
  }
  return ((unsigned char *)0x0000271f);
}

/* _gldDestroyContext @ 0x6dd0 (216 bytes) */
int _gldDestroyContext(param_1)
  void *param_1;
{
  undefined *puVar1;
  int *piVar2;
  int *piVar3;
  
  puVar1 = ((unsigned char *)0x00002714);
  if (param_1 != (void *)0x0) {
    ((int (*)())FUN_00007020)();
    FUN_0002cb40(param_1);
    _IOServiceClose(*(undefined4 *)((int)param_1 + 4));
    if (DAT_001f65e0 != (int *)0x0) {
      piVar2 = DAT_001f65e0;
      if (param_1 == (void *)*DAT_001f65e0) {
        DAT_001f65e0 = (int *)DAT_001f65e0[1];
      }
      else {
        do {
          piVar3 = piVar2;
          piVar2 = (int *)piVar3[1];
          if (piVar2 == (int *)0x0) goto LAB_00006e50;
        } while (param_1 != (void *)*piVar2);
        piVar3[1] = piVar2[1];
      }
    }
LAB_00006e50:
    if (*(void **)((int)param_1 + 0x148) != (void *)0x0) {
      _free(*(void **)((int)param_1 + 0x148));
    }
    if (*(void **)((int)param_1 + 0x220) != (void *)0x0) {
      _free(*(void **)((int)param_1 + 0x220));
    }
    _free(param_1);
    puVar1 = (undefined *)0x0;
  }
  return puVar1;
}

/* _gldCreateShared @ 0x6ec0 (128 bytes) */
int _gldCreateShared(param_1)
  undefined4 *param_1;
{
  undefined *puVar1;
  pthread_mutex_t *ppVar2;
  pthread_mutexattr_t apStack_28 [2];
  
  puVar1 = ((unsigned char *)0x0000271e);
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = 0;
    ppVar2 = _malloc(0x34);
    puVar1 = ((unsigned char *)0x00002720);
    if (ppVar2 != (pthread_mutex_t *)0x0) {
      _pthread_mutexattr_init(apStack_28);
      _pthread_mutexattr_settype(apStack_28,2);
      _pthread_mutex_init(ppVar2,apStack_28);
      FUN_00024fb0(ppVar2);
      *param_1 = ppVar2;
      puVar1 = (undefined *)0x0;
    }
  }
  return puVar1;
}

/* _gldDestroyShared @ 0x6f40 (76 bytes) */
int _gldDestroyShared(param_1)
  pthread_mutex_t *param_1;
{
  undefined *puVar1;
  
  puVar1 = ((unsigned char *)0x00002714);
  if (param_1 != (pthread_mutex_t *)0x0) {
    FUN_00024fc0();
    _pthread_mutex_destroy(param_1);
    _free(param_1);
    puVar1 = (undefined *)0x0;
  }
  return puVar1;
}

/* _gldReclaimContext @ 0x6f90 (128 bytes) */
int _gldReclaimContext(param_1)
  void *param_1;
{
  int iVar1;
  
  FUN_0002cc10();
  iVar1 = _io_connect_method_scalarI_structureI(*(undefined4 *)((int)param_1 + 4),0x11,0,0,0,0);
  if (iVar1 != 0) {
    _free(param_1);
    return;
  }
  *(undefined4 *)((int)param_1 + 0x204) = 0;
  *(undefined4 *)((int)param_1 + 0x1fc) = 0;
  *(undefined4 *)((int)param_1 + 0x200) = 0;
  *(undefined4 *)((int)param_1 + 500) = 0;
  *(undefined4 *)((int)param_1 + 0x1f8) = 0;
  return;
}

/* FUN_00007020 @ 0x7020 (164 bytes) */
int FUN_00007020(param_1)
  int *param_1;
{
  char cVar1;
  undefined *puVar2;
  
  if ((param_1[0x3e] != 0) &&
     (param_1[0x3e] = 0, puVar2 = PTR_DAT_001e88ac, (param_1[0xf] & 0x20U) == 0)) {
    cVar1 = PTR_DAT_001e88ac[*param_1 + 0x98];
    PTR_DAT_001e88ac[*param_1 + 0x98] = cVar1 + -1;
    if ((char)(cVar1 + -1) == '\0') {
      _IOServiceClose(*(undefined4 *)(puVar2 + *param_1 * 4 + 0x18));
      *(undefined4 *)(puVar2 + *param_1 * 4 + 0x18) = 0;
    }
  }
  return;
}

/* _gldAttachDrawable @ 0x70d0 (1804 bytes) */
int _gldAttachDrawable(param_1, param_2, param_3, param_4)
  int *param_1;
  int param_2;
  int *param_3;
  uint param_4;
{
  ushort uVar1;
  code *pcVar2;
  int iVar3;
  void *pvVar4;
  int iVar5;
  int *piVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  size_t sVar10;
  uint uVar11;
  undefined *puVar12;
  undefined4 local_68;
  int local_64 [3];
  uint local_58;
  uint local_54;
  uint local_50;
  uint local_4c;
  uint local_48;
  int local_44;
  int local_40;
  int local_3c;
  
  if (param_1 == (int *)0x0) {
    return ((unsigned char *)0x0000271e);
  }
  uVar11 = param_4 >> 8 & 0xff;
  if ((param_2 == 0x50) || (param_2 == 0x5a)) {
    if (param_3 == (int *)0x0) {
LAB_000077e0:
      return ((unsigned char *)0x00002715);
    }
    param_1[0xf] = param_1[0xf] | 0x20;
    piVar6 = param_3;
    if (param_2 != 0x5a) {
      piVar6 = (int *)0x0;
    }
    FUN_00017160(param_1,param_1 + 0xf,piVar6);
    local_64[0] = param_3[2];
    local_64[1] = 3;
    iVar3 = _io_connect_method_scalarI_scalarO(param_1[1],6,local_64,1,&local_48,local_64 + 1);
    if (iVar3 == 0) {
      uVar7 = param_1[0xf];
      if ((local_48 & 0xf) != (uVar7 & 0xf)) {
        if ((uVar7 & 0x33c0) != 0) {
          if (param_1[0x54] == 0) {
            param_1[0x55] = uVar7;
            return ((unsigned char *)0x00002715);
          }
          goto LAB_000077e0;
        }
        uVar7 = local_48 & 0xf | uVar7 & 0xfffffff0;
        param_1[0xf] = uVar7;
        if (param_1[0x54] == 0) {
          param_1[0x55] = uVar7;
          FUN_00017260(param_1);
          uVar7 = param_1[0xf];
        }
      }
    }
    else {
      uVar7 = param_1[0xf];
    }
    if (param_2 != 0x5a) {
      iVar8 = *param_1;
      iVar3 = *param_3;
      iVar5 = param_3[1];
      pcVar2 = *(code **)(PTR_DAT_001e88ac + 0x14);
      iVar9 = *(int *)(PTR_DAT_001e88ac + 8);
    }
    else {
      iVar8 = *param_1;
      iVar3 = 0;
      iVar5 = 0;
      pcVar2 = *(code **)(PTR_DAT_001e88ac + 0x14);
      iVar9 = *(int *)(PTR_DAT_001e88ac + 8);
    }
    iVar3 = (*pcVar2)(iVar3,iVar5,param_3[2],uVar7 & 0x803f,*(undefined4 *)(iVar8 * 4 + iVar9));
    if (iVar3 == 0) {
      local_58 = param_3[2];
      local_54 = param_1[0xf] & 0xffff3fc0;
      local_50 = uVar11;
      local_4c = param_4 & 0xff;
      iVar3 = _io_connect_method_scalarI_structureI(param_1[1],0,&local_58,4,0,0);
      if ((iVar3 == 0) &&
         ((*(char *)((int)param_1 + 0x145) == '\0' ||
          (iVar3 = _io_connect_method_scalarI_structureI(param_1[1],0xe,param_1 + 0x4d,3,0,0),
          iVar3 == 0)))) {
        local_58 = (uint)*(byte *)((int)param_1 + 0x147);
        _io_connect_method_scalarI_structureI(param_1[1],0x10,&local_58,1,0,0);
        goto LAB_00007320;
      }
      goto LAB_00007790;
    }
  }
  else {
    if (param_2 == 0x36) {
      if (param_3 == (int *)0x0) goto LAB_000077e0;
      uVar7 = param_1[0xf];
      param_1[0xf] = uVar7 & 0xffffffdf;
      if (((uVar7 & 0x400) != 0) || ((uVar7 & 0x10) != 0)) {
        param_1[0xf] = uVar7 & 0xffffffdf | 0x8000;
      }
      FUN_00017160(param_1,param_1 + 0xf,0);
      iVar5 = *param_1;
      iVar3 = iVar5 * 4;
      if (*(int *)(PTR_DAT_001e88ac + iVar3 + 0x18) == 0) {
        iVar3 = _IOServiceOpen(*(undefined4 *)(*(int *)(PTR_DAT_001e88ac + 8) + iVar3),
                               *(undefined4 *)PTR_001e88b4,0,PTR_DAT_001e88ac + iVar3 + 0x18);
        if (iVar3 != 0) goto LAB_00007780;
        iVar5 = *param_1;
      }
      puVar12 = PTR_DAT_001e88ac;
      iVar3 = *(int *)(PTR_DAT_001e88ac + 0xc);
      PTR_DAT_001e88ac[iVar5 + 0x98] = PTR_DAT_001e88ac[iVar5 + 0x98] + '\x01';
      local_58 = (uint)*(byte *)(iVar3 + *param_1);
      local_64[0] = 0;
      local_54 = param_1[0xf] & 0x803f;
      uVar7 = _io_connect_method_scalarI_scalarO
                        (*(undefined4 *)(puVar12 + *param_1 * 4 + 0x18),7,&local_58,2,0,local_64);
      if (uVar7 == 0) {
        local_58 = ~(uint)*(byte *)(*(int *)(puVar12 + 0xc) + *param_1);
        local_54 = param_1[0xf] & 0xffff3fc0;
        local_50 = uVar7;
        local_4c = uVar7;
        iVar3 = _io_connect_method_scalarI_structureI(param_1[1],0,&local_58,4,0,0);
        if (iVar3 == 0) {
LAB_00007320:
          local_68 = 4;
          puVar12 = ((unsigned char *)0x00002715);
          iVar3 = _io_connect_method_scalarI_scalarO(param_1[1],5,0,0,&local_48,&local_68);
          if (iVar3 == 0) {
            local_68 = 3;
            puVar12 = ((unsigned char *)0x00002715);
            iVar3 = _io_connect_method_scalarI_scalarO(param_1[1],3,0,0,param_1 + 9,&local_68);
            if (iVar3 == 0) {
              local_68 = 1;
              _io_connect_method_scalarI_scalarO(param_1[1],4,0,0,local_64 + 2,&local_68);
              if ((local_64[2] & 1U) == 0) {
                puVar12 = ((unsigned char *)0x00002720);
                param_1[0x47] = local_40;
                param_1[0x48] = local_3c;
                param_1[0x41] = local_48;
                param_1[0x42] = local_44;
              }
              else if (param_3 == (int *)param_1[0x3e]) {
                if ((local_48 != param_1[0x41]) ||
                   (puVar12 = (undefined *)0x0, local_44 != param_1[0x42])) {
                  param_1[0x47] = local_40;
                  param_1[0x48] = local_3c;
                  puVar12 = (undefined *)0x3;
                  param_1[0x41] = local_48;
                  param_1[0x42] = local_44;
                }
              }
              else {
                puVar12 = (undefined *)0x2;
                param_1[0x47] = local_40;
                param_1[0x48] = local_3c;
                param_1[0x41] = local_48;
                param_1[0x42] = local_44;
              }
              if (*(char *)((int)param_1 + 0x141) != '\0') {
                iVar3 = 4;
                if (*(char *)((int)param_1 + 0x141) != '\x01') {
                  iVar3 = 8;
                }
                sVar10 = iVar3 * (local_48 + 7 & 0xfffffff8) * local_44;
                if (sVar10 != param_1[0x53]) {
                  if ((void *)param_1[0x52] != (void *)0x0) {
                    _free((void *)param_1[0x52]);
                  }
                  pvVar4 = _malloc(sVar10);
                  param_1[0x53] = sVar10;
                  param_1[0x52] = (int)pvVar4;
                }
              }
              ((int (*)())FUN_00007020)(param_1);
              param_1[0x3e] = (int)param_3;
              param_1[0x3f] = uVar11;
              param_1[0x40] = param_4 & 0xff;
              if (param_1[0x54] != 0) {
                return puVar12;
              }
              param_1[0x55] = param_1[0xf];
              param_1[0x57] = param_1[0x41];
              param_1[0x58] = param_1[0x42];
              param_1[0x59] = param_1[0x43];
              param_1[0x5a] = param_1[0x44];
              param_1[0x5b] = param_1[0x45];
              param_1[0x5c] = param_1[0x46];
              return puVar12;
            }
          }
          goto LAB_000077a0;
        }
      }
LAB_00007790:
      puVar12 = ((unsigned char *)0x00002715);
      goto LAB_000077a0;
    }
    if (param_2 != 0x35) {
      if (param_2 != 0) {
        if (param_2 == 0x5b) {
          if (param_3 != (int *)0x0) {
            param_1[0x55] = param_3[3];
            param_1[0x56] = param_3[2];
            param_1[0x57] = (uint)*(ushort *)(*param_3 + 0x9a);
            uVar1 = *(ushort *)(*param_3 + 0x9c);
            param_1[0x5c] = 0;
            param_1[0x59] = 0;
            param_1[0x5a] = 0;
            param_1[0x5b] = 0;
            param_1[0x58] = (uint)uVar1;
            _memcpy((void *)(param_1[5] + 0x24),param_3 + 4,0x3c);
            *(uint *)param_1[5] = *(uint *)param_1[5] & 0xfffffffd;
            return (undefined *)0x0;
          }
          param_1[0x55] = param_1[0xf];
          param_1[0x56] = param_1[0xe];
          param_1[0x57] = param_1[0x41];
          param_1[0x58] = param_1[0x42];
          param_1[0x59] = param_1[0x43];
          param_1[0x5a] = param_1[0x44];
          param_1[0x5b] = param_1[0x45];
          param_1[0x5c] = param_1[0x46];
          _memcpy((void *)(param_1[5] + 0x24),param_1 + 0x10,0x3c);
          if (*(char *)((int)param_1 + 0x143) != '\0') {
            *(uint *)param_1[5] = *(uint *)param_1[5] | 2;
            return (undefined *)0x0;
          }
          *(uint *)param_1[5] = *(uint *)param_1[5] & 0xfffffffd;
          return (undefined *)0x0;
        }
        puVar12 = ((unsigned char *)0x0000271a);
        goto LAB_000077a0;
      }
      if (param_3 == (int *)0x0) {
        puVar12 = (undefined *)0x1;
        goto LAB_000077a0;
      }
    }
  }
LAB_00007780:
  puVar12 = ((unsigned char *)0x00002715);
LAB_000077a0:
  ((int (*)())FUN_00007020)(param_1);
  local_54 = 0;
  local_58 = 0;
  _io_connect_method_scalarI_structureI(param_1[1],0,&local_58,4,0,0);
  return puVar12;
}

/* _gldGetError @ 0x7830 (20 bytes) */
int _gldGetError(param_1)
  int param_1;
{
  undefined4 uVar1;
  
  uVar1 = *(undefined4 *)(param_1 + 0x178);
  *(undefined4 *)(param_1 + 0x178) = 0;
  return uVar1;
}

/* _gldCreateFence @ 0x7850 (408 bytes) */
int _gldCreateFence(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  undefined *puVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  void *pvVar5;
  uint *puVar6;
  uint uVar7;
  uint *puVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  
  piVar3 = _malloc(8);
  piVar3[1] = 0;
  *piVar3 = 0;
  puVar1 = PTR_001e88b4;
  do {
    uVar10 = *(uint *)(param_1 + 0x21c) >> 8;
    if (uVar10 != 0) {
      puVar6 = *(uint **)(param_1 + 0x220);
      uVar7 = *puVar6;
      if (uVar7 != 0xffffffff) {
        iVar2 = 0;
        iVar4 = 0;
LAB_00007950:
        iVar11 = 0x20;
        uVar10 = 0;
        break;
      }
      iVar2 = 0;
      puVar8 = puVar6;
      while( true ) {
        iVar2 = iVar2 + 1;
        puVar8 = puVar8 + 1;
        uVar10 = uVar10 - 1;
        if (uVar10 == 0) break;
        uVar7 = *puVar8;
        iVar4 = iVar2 * 4;
        if (uVar7 != 0xffffffff) goto LAB_00007950;
      }
    }
    iVar4 = _IOConnectMapMemory(*(undefined4 *)(param_1 + 4),4,*(undefined4 *)puVar1,param_1 + 0x218
                                ,param_1 + 0x21c,1);
    if (iVar4 != 0) {
      _free(piVar3);
      *param_2 = 0;
      return ((unsigned char *)0x00002720);
    }
    pvVar5 = _realloc(*(void **)(param_1 + 0x220),*(uint *)(param_1 + 0x21c) >> 5);
    *(void **)(param_1 + 0x220) = pvVar5;
    uVar10 = *(uint *)(param_1 + 0x21c) >> 6;
    _memset((void *)((int)pvVar5 + uVar10),0,uVar10);
  } while( true );
  while( true ) {
    uVar9 = uVar10 + 1;
    iVar11 = iVar11 + -1;
    uVar10 = uVar9;
    if (iVar11 == 0) break;
    uVar9 = uVar10;
    if ((uVar7 >> (uVar10 & 0x3f) & 1) == 0) goto LAB_0000797c;
  }
  uVar10 = 0x20;
LAB_0000797c:
  iVar2 = uVar9 + iVar2 * 0x20;
  *(uint *)((int)puVar6 + iVar4) = 1 << (uVar10 & 0x3f) | *(uint *)((int)puVar6 + iVar4);
  *piVar3 = iVar2;
  *(undefined4 *)(iVar2 * 8 + *(int *)(param_1 + 0x218)) =
       *(undefined4 *)(*(int *)(param_1 + 0x1e4) + 0x18);
  *(undefined4 *)(*piVar3 * 8 + *(int *)(param_1 + 0x218) + 4) = 0;
  *param_2 = piVar3;
  *(undefined1 *)(piVar3 + 1) = 1;
  return (undefined *)0x0;
}

/* _gldDestroyFence @ 0x79f0 (76 bytes) */
int _gldDestroyFence(param_1, param_2)
  int param_1;
  uint *param_2;
{
  uint uVar1;
  uint uVar2;
  
  uVar2 = *param_2 >> 3 & 0x1ffffffc;
  uVar1 = *param_2 & 0x1f;
  *(uint *)(uVar2 + *(int *)(param_1 + 0x220)) =
       (-2 << uVar1 | 0xfffffffeU >> 0x20 - uVar1) & *(uint *)(uVar2 + *(int *)(param_1 + 0x220));
  _free(param_2);
  return 0;
}

/* _gldTestObject @ 0x7a40 (232 bytes) */
int _gldTestObject(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int *param_3;
{
  uint uVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  
  if (param_2 == 1) {
    uVar1 = FUN_0000abf0(param_1,param_3);
  }
  else if (param_2 == 0) {
    bVar2 = *(byte *)(param_3 + 1);
    if (bVar2 == 0) {
      iVar3 = *param_3;
      iVar4 = *(int *)(param_1 + 0x218);
      if (*(int *)(iVar3 * 8 + iVar4 + 4) != 0) {
        _gldFlush();
        iVar3 = *param_3;
        iVar4 = *(int *)(param_1 + 0x218);
      }
      bVar2 = FUN_0001a0d0(param_1,*(undefined4 *)(iVar3 * 8 + iVar4));
      *(byte *)(param_3 + 1) = bVar2;
    }
    uVar1 = (uint)bVar2;
  }
  else if (param_2 == 2) {
    uVar1 = FUN_0000b980(param_1,param_3);
  }
  else {
    uVar1 = 1;
    if (param_2 == 3) {
      uVar1 = ((int (*)())FUN_00005eb0)(param_1,param_3);
    }
  }
  return uVar1;
}

/* _gldFinishObject @ 0x7b30 (300 bytes) */
int _gldFinishObject(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int *param_3;
{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  
  if (param_2 == 1) {
    FUN_0000aaf0(param_1,param_3);
    puVar1 = (undefined *)0x0;
  }
  else if (param_2 == 0) {
    if (*(char *)(param_3 + 1) == '\0') {
      iVar3 = *param_3;
      iVar2 = *(int *)(param_1 + 0x218);
      if (*(int *)(iVar3 * 8 + iVar2 + 4) != 0) {
        _gldFlush();
        iVar3 = *param_3;
        iVar2 = *(int *)(param_1 + 0x218);
      }
      iVar2 = FUN_0001a0d0(param_1,*(undefined4 *)(iVar3 * 8 + iVar2));
      *(char *)(param_3 + 1) = (char)iVar2;
      if (iVar2 == 0) {
        _io_connect_method_scalarI_structureI
                  (*(undefined4 *)(param_1 + 4),9,*param_3 * 8 + *(int *)(param_1 + 0x218),1,0,0);
        *(undefined1 *)(param_3 + 1) = 1;
        return (undefined *)0x0;
      }
    }
    puVar1 = (undefined *)0x0;
  }
  else if (param_2 == 2) {
    FUN_0000b880(param_1,param_3);
    puVar1 = (undefined *)0x0;
  }
  else {
    puVar1 = ((unsigned char *)0x0000271a);
    if (param_2 == 3) {
      ((int (*)())FUN_00005db0)(param_1,param_3);
      puVar1 = (undefined *)0x0;
    }
  }
  return puVar1;
}

/* _gldCreateFramebuffer @ 0x7c70 (104 bytes) */
int _gldCreateFramebuffer(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 *param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  
  puVar2 = _calloc(1,200);
  *puVar2 = param_3;
  puVar2[1] = param_4;
  iVar3 = 6;
  puVar1 = puVar2;
  do {
    puVar1[0x13] = 0;
    puVar1 = puVar1 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  *param_2 = puVar2;
  return 0;
}

/* _gldReclaimFramebuffer @ 0x7ce0 (4 bytes) */
int _gldReclaimFramebuffer()
{
  return;
}

/* _gldDestroyFramebuffer @ 0x7cf0 (96 bytes) */
int _gldDestroyFramebuffer(param_1, param_2)
  int param_1;
  void *param_2;
{
  if (*(void **)(param_1 + 0x150) == param_2) {
    FUN_0001b4b0();
    *(undefined4 *)(param_1 + 0x150) = 0;
  }
  _free(param_2);
  return 0;
}

/* FUN_00007d50 @ 0x7d50 (368 bytes) */
int FUN_00007d50(param_1)
  int param_1;
{
  bool bVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  char in_RESERVE;
  byte in_cr0;
  int iVar7;
  
  iVar4 = *(int *)(param_1 + 0x150);
  bVar1 = iVar4 != 0;
  piVar6 = *(int **)(*(int *)(param_1 + 0x18) + 0x1a0);
  if (bVar1) {
    iVar7 = 6;
    do {
      if (*(int *)(iVar4 + 0x4c) != 0) {
        piVar5 = (int *)(*(int *)(iVar4 + 0x4c) + 0x10);
        do {
          if (in_RESERVE != '\0') {
            iVar3 = storeWordConditionalIndexed(*piVar5 + -0x10000,0,piVar5);
            *piVar5 = iVar3;
            in_cr0 = 2;
          }
        } while (!(bool)(in_cr0 >> 1 & 1));
      }
      iVar4 = iVar4 + 4;
      iVar7 = iVar7 + -1;
    } while (iVar7 != 0);
  }
  bVar2 = piVar6 == (int *)0x0;
  if ((!bVar2) && (*(int *)(*piVar6 + 0xa0) == 0)) {
    if (*(int *)(piVar6[1] + 0x18) == 0) {
      if (*(int *)(piVar6[1] + 0x1c) == 0) goto LAB_00007e28;
    }
    else {
      iVar4 = FUN_0001b510(param_1,piVar6);
      if (iVar4 != 0) goto LAB_00007e28;
    }
  }
  piVar6 = (int *)0x0;
  bVar2 = true;
LAB_00007e28:
  *(int **)(param_1 + 0x150) = piVar6;
  if (!bVar2) {
    iVar4 = 6;
    do {
      if (piVar6[0x13] != 0) {
        piVar5 = (int *)(piVar6[0x13] + 0x10);
        do {
          if (in_RESERVE != '\0') {
            iVar7 = storeWordConditionalIndexed(*piVar5 + 0x10000,0,piVar5);
            *piVar5 = iVar7;
            in_cr0 = 2;
          }
        } while (!(bool)(in_cr0 >> 1 & 1));
      }
      piVar6 = piVar6 + 1;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
  }
  if ((*(int *)(*(int *)(param_1 + 0x18) + 0x1a0) == 0) && (bVar1)) {
    FUN_0001b4b0(param_1);
    return;
  }
  return;
}

/* FUN_00007ec0 @ 0x7ec0 (256 bytes) */
int FUN_00007ec0(param_1)
  uint param_1;
{
  if (0x7f < param_1) {
    return 0x10000;
  }
  if (0x5f < param_1) {
    return 0x18000;
  }
  if (0x3f < param_1) {
    return 0x1c000;
  }
  if (0x2f < param_1) {
    return 0x1e000;
  }
  if (0x1f < param_1) {
    return 0x1f000;
  }
  if (0x17 < param_1) {
    return 0x1f800;
  }
  if (0xf < param_1) {
    return 0x1fc00;
  }
  if (0xb < param_1) {
    return 0x1fe00;
  }
  if (9 < param_1) {
    return 0x1ff00;
  }
  if (7 < param_1) {
    return 0x1ff80;
  }
  if (5 < param_1) {
    return 0x1ffc0;
  }
  if (param_1 == 5) {
    return 0x1ffe0;
  }
  if (3 < param_1) {
    return 0x1fff0;
  }
  if (param_1 == 3) {
    return 0x1fff8;
  }
  if (1 < param_1) {
    return 0x1fffc;
  }
  return (param_1 == 0) + 0x1fffe;
}

/* FUN_00007fc0 @ 0x7fc0 (112 bytes) */
int FUN_00007fc0(param_1)
  uint param_1;
{
  if (0x100 < param_1) {
    return 0;
  }
  if (0x80 < param_1) {
    return 0x30000000;
  }
  if (0x40 < param_1) {
    return 0xc000000;
  }
  if (0x20 < param_1) {
    return 0x3ff00000;
  }
  if (0x10 < param_1) {
    return 0x3fffc000;
  }
  if (8 < param_1) {
    return 0x3fffffc0;
  }
  if (param_1 != 0) {
    return 0x3ffffffc;
  }
  return 0xbffffffc;
}

/* FUN_00008030 @ 0x8030 (128 bytes) */
int FUN_00008030(param_1)
  uint param_1;
{
  if (0x20 < param_1) {
    return 0;
  }
  if (0x10 < param_1) {
    return 0x8000000;
  }
  if (0xc < param_1) {
    return 0xa800000;
  }
  if (8 < param_1) {
    return 0xaa00000;
  }
  if (4 < param_1) {
    return 0xaa9a928;
  }
  if (2 < param_1) {
    return 0xaa9a9a8;
  }
  if (param_1 == 2) {
    return 0xaada9a8;
  }
  if (param_1 != 0) {
    return 0xaadada8;
  }
  return 0xbffffffc;
}

/* _gldChoosePixelFormat @ 0x80b0 (1980 bytes) */
int _gldChoosePixelFormat(param_1, param_2)
  undefined4 *param_1;
  uint *param_2;
{
  undefined4 *puVar1;
  undefined *puVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  void *pvVar6;
  int iVar7;
  uint *puVar8;
  int *piVar9;
  uint *puVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  void *pvVar16;
  uint uVar17;
  int iVar18;
  uint uVar19;
  uint uVar20;
  uint uVar21;
  uint uVar22;
  uint uVar23;
  int iVar24;
  uint uVar25;
  uint uVar26;
  void *pvVar27;
  undefined4 *puVar28;
  uint uVar29;
  uint uVar30;
  uint uVar31;
  undefined4 local_194;
  uint local_190;
  uint local_18c;
  uint local_188;
  uint local_184;
  uint local_180;
  uint local_17c;
  uint local_178;
  undefined2 local_174;
  undefined2 local_172;
  undefined2 local_170;
  undefined2 local_16e;
  undefined4 local_16c;
  undefined1 local_168;
  undefined1 local_167;
  undefined1 local_166;
  undefined1 local_165;
  uint local_164;
  uint local_88[0];
  uint local_84;
  int local_80;
  int local_7c;
  int local_78;
  int local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 *local_60;
  
  if (param_1 == (undefined4 *)0x0) {
    return ((unsigned char *)0x0000271e);
  }
  *param_1 = 0;
  pcVar5 = _getenv("GL_REJECT_HW");
  if (pcVar5 != (char *)0x0) {
    return (undefined *)0x0;
  }
  uVar31 = 0xfffffc;
  uVar13 = 0;
  uVar19 = 0;
  uVar14 = 0;
  local_64 = 0;
  local_68 = 0;
  local_6c = 0;
  local_70 = 0;
  local_74 = 0;
  local_78 = 0;
  uVar29 = *(uint *)PTR_DAT_001e88ac;
  local_7c = 0;
  uVar15 = 0;
  local_80 = 0;
  uVar20 = 0;
  uVar21 = 0;
  uVar22 = 0;
  uVar23 = 0;
  uVar25 = 0;
  uVar26 = 0;
  uVar17 = 0;
  uVar12 = 0;
  uVar30 = 0x510;
  uVar4 = 0;
  puVar10 = param_2;
  do {
    if (*puVar10 == 0) {
      local_84 = ((int (*)())FUN_00007ec0)();
      local_84 = local_84 & 0x1ffff;
      local_88[0] = ((int (*)())FUN_00007ec0)(uVar19);
      local_88[0] = local_88[0] & 0x1ffff;
      uVar22 = uVar21 + uVar20 + uVar22;
      if ((int)uVar13 < (int)uVar22) {
        uVar13 = uVar22;
      }
      uVar4 = uVar23 + uVar25 + uVar26 + uVar17;
      if ((int)uVar14 < (int)uVar4) {
        uVar14 = uVar4;
      }
      if (((int)uVar13 < 0x21) && ((int)uVar15 < 9)) {
        uVar31 = uVar31 & 0xff0fffff;
      }
      uVar4 = ((int (*)())FUN_00007fc0)(uVar13);
      uVar13 = ((int (*)())FUN_00008030)(uVar15);
      uVar14 = ((int (*)())FUN_00007fc0)(uVar14);
      uVar15 = ((int (*)())FUN_00008030)(uVar17);
      puVar2 = PTR_DAT_001e88ac;
      if (CONCAT22((short)local_78,(short)local_74) == 0) {
        local_6c = 0;
        local_70 = 0;
      }
      if (((uVar30 & 2) == 0) && ((uVar30 & 4) == 0)) {
        uVar30 = uVar30 | 1;
      }
      uVar17 = *(uint *)(PTR_DAT_001e88ac + 4);
      pvVar16 = (void *)0x0;
      if (uVar17 != 0) {
        local_60 = &local_194;
        uVar19 = 0;
        iVar18 = 0;
        do {
          piVar9 = *(int **)(puVar2 + 8);
          iVar11 = piVar9[uVar19];
          pvVar6 = pvVar16;
          if (iVar11 != 0) {
            if (uVar19 == 0) {
LAB_00008798:
              uVar21 = uVar19 + 1;
              uVar20 = 1 << (uVar19 & 0x3f);
              if (uVar21 < uVar17) {
                iVar7 = uVar17 - uVar21;
                piVar9 = piVar9 + uVar21;
                do {
                  if (iVar11 == *piVar9) {
                    uVar20 = uVar20 | 1 << (uVar21 & 0x3f);
                  }
                  uVar21 = uVar21 + 1;
                  piVar9 = piVar9 + 1;
                  iVar7 = iVar7 + -1;
                } while (iVar7 != 0);
              }
              uVar20 = uVar20 & uVar29;
              if (uVar20 != 0) {
                local_165 = 0;
                local_166 = 0;
                local_167 = 0;
                local_190 = 0;
                local_194 = 0;
                local_168 = (undefined1)local_6c;
                local_16c = local_70;
                local_16e = (undefined2)local_74;
                local_170 = (undefined2)local_78;
                local_172 = (undefined2)local_7c;
                local_174 = (undefined2)local_80;
                local_178 = local_84;
                local_17c = local_88[0];
                local_18c = uVar30;
                if ((uVar20 & uVar20 - 1) != 0) {
                  local_18c = uVar30 | 0x200;
                }
                local_188 = uVar12;
                local_184 = uVar31 & uVar4 & uVar13;
                local_180 = uVar14 & 0xbffffffc & uVar15;
                local_164 = uVar20;
                local_190 = FUN_00017720(uVar19);
                local_190 = local_190 | uVar19 << 0x18;
                iVar11 = FUN_0001ae20(local_60,local_68,local_64);
                if (iVar11 != 0) {
                  iVar18 = iVar18 + iVar11;
                  pvVar6 = _malloc(iVar18 * 0x34);
                  if (pvVar6 == (void *)0x0) {
                    if (pvVar16 != (void *)0x0) {
                      _free(pvVar16);
                      return ((unsigned char *)0x00002720);
                    }
                    return ((unsigned char *)0x00002720);
                  }
                  iVar7 = iVar18 - iVar11;
                  if (iVar7 < 1) {
                    iVar7 = 0;
                  }
                  else {
                    iVar24 = 0;
                    pvVar27 = pvVar16;
                    puVar1 = pvVar6;
                    do {
                      iVar24 = iVar24 + 1;
                      _memcpy(puVar1,pvVar27,0x34);
                      *puVar1 = puVar1 + 0xd;
                      pvVar27 = (void *)((int)pvVar27 + 0x34);
                      puVar1 = puVar1 + 0xd;
                    } while (iVar7 != iVar24);
                  }
                  if (iVar7 < iVar18) {
                    iVar24 = 0;
                    puVar28 = local_60 + (iVar11 + (iVar7 - iVar18)) * 0xd;
                    puVar1 = (void *)((int)pvVar6 + iVar7 * 0x34);
                    do {
                      iVar24 = iVar24 + 1;
                      _memcpy(puVar1,puVar28,0x34);
                      *puVar1 = puVar1 + 0xd;
                      puVar28 = puVar28 + 0xd;
                      puVar1 = puVar1 + 0xd;
                    } while (iVar18 - iVar7 != iVar24);
                    iVar7 = iVar7 + iVar24;
                  }
                  *(undefined4 *)((int)pvVar6 + iVar7 * 0x34 + -0x34) = 0;
                  if (pvVar16 != (void *)0x0) {
                    _free(pvVar16);
                  }
                }
              }
            }
            else if (*piVar9 != iVar11) {
              iVar7 = 0;
              uVar20 = uVar19;
              do {
                iVar7 = iVar7 + 1;
                uVar20 = uVar20 - 1;
                if (uVar20 == 0) goto LAB_00008798;
              } while (piVar9[iVar7] != iVar11);
            }
          }
          uVar19 = uVar19 + 1;
          uVar17 = *(uint *)(puVar2 + 4);
          pvVar16 = pvVar6;
        } while (uVar19 < uVar17);
        if ((pvVar6 != (void *)0x0) && (iVar18 < 1)) {
          pvVar16 = (void *)0x0;
          _free(pvVar6);
        }
      }
      *param_1 = pvVar16;
      return (undefined *)0x0;
    }
    puVar8 = puVar10 + 1;
    switch(*puVar10) {
    default:
      goto switchD_00008194_caseD_1;
    case 2:
      uVar3 = *puVar8;
      puVar8 = puVar10 + 2;
      if ((int)uVar3 < 0) {
        return (undefined *)0x0;
      }
      break;
    case 3:
      local_80 = (int)*(short *)((int)puVar10 + 6);
      puVar8 = puVar10 + 2;
      break;
    case 4:
      break;
    case 5:
      uVar12 = uVar12 | 8;
      break;
    case 6:
      uVar12 = uVar12 | 2;
      break;
    case 7:
      uVar3 = *puVar8;
      puVar8 = puVar10 + 2;
      if ((int)uVar3 < 0) {
LAB_000089d8:
        return ((unsigned char *)0x00002718);
      }
      local_7c = (int)(short)uVar3;
      break;
    case 8:
      uVar3 = *puVar8;
      puVar8 = puVar10 + 2;
      if ((int)uVar3 < 0) goto LAB_000089d8;
      if ((int)uVar13 < (int)uVar3) {
        uVar13 = uVar3;
      }
      break;
    case 0xb:
      uVar3 = *puVar8;
      puVar8 = puVar10 + 2;
      if ((int)uVar3 < 0) goto LAB_000089d8;
      if ((int)uVar15 < (int)uVar3) {
        uVar15 = uVar3;
      }
      break;
    case 0xc:
      uVar3 = *puVar8;
      puVar8 = puVar10 + 2;
      if ((int)uVar3 < 0) goto LAB_000089d8;
      if ((int)uVar19 < (int)uVar3) {
        uVar19 = uVar3;
      }
      break;
    case 0xd:
      uVar3 = *puVar8;
      puVar8 = puVar10 + 2;
      if ((int)uVar3 < 0) goto LAB_000089d8;
      if ((int)uVar4 < (int)uVar3) {
        uVar4 = uVar3;
      }
      break;
    case 0xe:
      uVar3 = *puVar8;
      puVar8 = puVar10 + 2;
      if ((int)uVar3 < 0) goto LAB_000089d8;
      if ((int)uVar14 < (int)uVar3) {
        uVar14 = uVar3;
      }
      break;
    case 0x14:
      uVar3 = *puVar8;
      puVar8 = puVar10 + 2;
      if ((int)uVar3 < 0) goto LAB_000089d8;
      if ((int)uVar20 < (int)uVar3) {
        uVar20 = uVar3;
      }
      break;
    case 0x15:
      uVar3 = *puVar8;
      puVar8 = puVar10 + 2;
      if ((int)uVar3 < 0) goto LAB_000089d8;
      if ((int)uVar21 < (int)uVar3) {
        uVar21 = uVar3;
      }
      break;
    case 0x16:
      uVar3 = *puVar8;
      puVar8 = puVar10 + 2;
      if ((int)uVar3 < 0) goto LAB_000089d8;
      if ((int)uVar22 < (int)uVar3) {
        uVar22 = uVar3;
      }
      break;
    case 0x17:
      uVar3 = *puVar8;
      puVar8 = puVar10 + 2;
      if ((int)uVar3 < 0) goto LAB_000089d8;
      if ((int)uVar23 < (int)uVar3) {
        uVar23 = uVar3;
      }
      break;
    case 0x18:
      uVar3 = *puVar8;
      puVar8 = puVar10 + 2;
      if ((int)uVar3 < 0) goto LAB_000089d8;
      if ((int)uVar25 < (int)uVar3) {
        uVar25 = uVar3;
      }
      break;
    case 0x19:
      uVar3 = *puVar8;
      puVar8 = puVar10 + 2;
      if ((int)uVar3 < 0) goto LAB_000089d8;
      if ((int)uVar26 < (int)uVar3) {
        uVar26 = uVar3;
      }
      break;
    case 0x1a:
      uVar3 = *puVar8;
      puVar8 = puVar10 + 2;
      if ((int)uVar3 < 0) goto LAB_000089d8;
      if ((int)uVar17 < (int)uVar3) {
        uVar17 = uVar3;
      }
      break;
    case 0x33:
      local_68 = 1;
      break;
    case 0x34:
      local_64 = 1;
      break;
    case 0x35:
      uVar30 = uVar30 | 4;
      break;
    case 0x36:
      uVar30 = uVar30 | 2;
      break;
    case 0x37:
      uVar3 = *puVar8;
      puVar8 = puVar10 + 2;
      if ((int)uVar3 < 0) goto LAB_000089d8;
      local_78 = (int)(short)uVar3;
      break;
    case 0x38:
      uVar3 = *puVar8;
      puVar8 = puVar10 + 2;
      if ((int)uVar3 < 0) goto LAB_000089d8;
      local_74 = (int)(short)uVar3;
      break;
    case 0x39:
      uVar30 = uVar30 | 0x800;
      break;
    case 0x3a:
      uVar31 = 0x3f000000;
      break;
    case 0x3b:
      local_70 = 2;
      break;
    case 0x3c:
      local_70 = 1;
      break;
    case 0x3d:
      local_6c = 1;
      break;
    case 0x4c:
      uVar30 = uVar30 | 8;
      break;
    case 0x50:
      uVar30 = uVar30 | 1;
      break;
    case 0x54:
      uVar3 = *puVar8;
      puVar8 = puVar10 + 2;
      uVar29 = uVar29 & uVar3;
      break;
    case 0x5a:
      uVar30 = uVar30 | 0x2000;
    }
    puVar10 = puVar8;
  } while ((int)puVar8 - (int)param_2 < 0x94);
switchD_00008194_caseD_1:
  return ((unsigned char *)0x00002710);
}

/* _gldDestroyPixelFormat @ 0x8a10 (52 bytes) */
int _gldDestroyPixelFormat(param_1)
  void *param_1;
{
  undefined *puVar1;
  
  puVar1 = ((unsigned char *)0x0000271e);
  if (param_1 != (void *)0x0) {
    _free(param_1);
    puVar1 = (undefined *)0x0;
  }
  return puVar1;
}

/* _gldGetRendererInfo @ 0x8a50 (500 bytes) */
int _gldGetRendererInfo(param_1, param_2)
  undefined4 *param_1;
  uint param_2;
{
  undefined *puVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  
  if (((*(uint *)PTR_DAT_001e88ac & param_2) == 0) || ((param_2 & ~*(uint *)PTR_DAT_001e88ac) != 0))
  {
    puVar1 = ((unsigned char *)0x00002719);
  }
  else {
    iVar4 = *(int *)(PTR_DAT_001e88ac + 4);
    if ((iVar4 == 0) || ((param_2 & 1) != 0)) {
      iVar6 = 0;
    }
    else {
      uVar2 = 0;
      iVar6 = iVar4;
      do {
        uVar2 = uVar2 + 1;
        iVar6 = iVar6 + -1;
        if (iVar6 == 0) {
          iVar6 = iVar4 << 2;
          goto LAB_00008ad4;
        }
      } while ((param_2 & 1 << (uVar2 & 0x3f)) == 0);
      iVar6 = uVar2 * 4;
    }
LAB_00008ad4:
    piVar3 = *(int **)(PTR_DAT_001e88ac + 8);
    iVar6 = *(int *)((int)piVar3 + iVar6);
    if ((iVar4 == 0) || (iVar6 == *piVar3)) {
      iVar5 = 0;
    }
    else {
      iVar5 = 0;
      do {
        iVar5 = iVar5 + 1;
        iVar4 = iVar4 + -1;
        if (iVar4 == 0) break;
      } while (iVar6 != piVar3[iVar5]);
    }
    iVar4 = _IOServiceOpen(iVar6,*(undefined4 *)PTR_001e88b4,1,&local_34);
    puVar1 = ((unsigned char *)0x0000271f);
    if (iVar4 == 0) {
      local_38 = 3;
      iVar4 = _io_connect_method_scalarI_scalarO(local_34,3,0,0,&local_30,&local_38);
      if (iVar4 == 0) {
        *param_1 = 0;
        uVar2 = FUN_00017720(iVar5);
        *(undefined2 *)(param_1 + 8) = 0;
        *(undefined2 *)((int)param_1 + 0x22) = 0;
        *(undefined2 *)(param_1 + 9) = 0;
        *(undefined2 *)((int)param_1 + 0x26) = 0;
        *(undefined2 *)(param_1 + 10) = 0;
        param_1[0xb] = 0;
        param_1[0xc] = local_28;
        param_1[0xd] = local_2c;
        param_1[3] = 0xd;
        param_1[2] = 0xa513;
        param_1[1] = uVar2 | iVar5 << 0x18;
        param_1[6] = 0x1c01;
        param_1[4] = 0x8400;
        param_1[5] = 0x808000;
        *(undefined1 *)((int)param_1 + 0x2a) = 0;
        param_1[7] = 0x80;
        FUN_0001b150(param_1,local_30);
        _IOServiceClose(local_34);
        puVar1 = (undefined *)0x0;
      }
      else {
        _IOServiceClose(local_34);
        puVar1 = ((unsigned char *)0x0000271f);
      }
    }
  }
  return puVar1;
}

/* _gldInitializeLibrary @ 0x8c60 (156 bytes) */
int _gldInitializeLibrary(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  undefined4 param_2;
  uint param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  undefined *puVar1;
  undefined *puVar2;
  uint uVar3;
  undefined4 *puVar4;
  
  puVar1 = PTR_DAT_001e88ac;
  uVar3 = 0;
  *(undefined4 *)(PTR_DAT_001e88ac + 0xc) = param_2;
  *(undefined4 *)(puVar1 + 8) = param_1;
  *(undefined4 *)(puVar1 + 4) = 0;
  *(uint *)puVar1 = param_3;
  puVar4 = (undefined4 *)(puVar1 + 0x18);
  do {
    *puVar4 = 0;
    puVar1[uVar3 + 0x98] = 0;
    if ((1 << (uVar3 & 0x3f) & param_3) != 0) {
      *(uint *)(puVar1 + 4) = uVar3 + 1;
    }
    puVar2 = PTR_DAT_001e88ac;
    puVar4 = puVar4 + 1;
    uVar3 = uVar3 + 1;
  } while ((int)uVar3 < 0x20);
  *(undefined4 *)(PTR_DAT_001e88ac + 0x14) = param_5;
  *(undefined4 *)(puVar2 + 0x10) = param_4;
  return;
}

/* _gldTerminateLibrary @ 0x8d10 (56 bytes) */
int _gldTerminateLibrary()
{
  undefined *puVar1;
  
  puVar1 = PTR_DAT_001e88ac;
  *(undefined4 *)(PTR_DAT_001e88ac + 0x14) = 0;
  *(undefined4 *)(puVar1 + 8) = 0;
  *(undefined4 *)(puVar1 + 0xc) = 0;
  *(undefined4 *)puVar1 = 0;
  *(undefined4 *)(puVar1 + 4) = 0;
  *(undefined4 *)(puVar1 + 0x10) = 0;
  return;
}

/* _gldIsTextureResident @ 0x8d50 (16 bytes) */
int _gldIsTextureResident(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  return *(int *)(param_2 + 0x34) != 0;
}

/* _gldCreateTexture @ 0x8d60 (164 bytes) */
int _gldCreateTexture(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 *param_2;
  undefined4 param_3;
{
  undefined4 *puVar1;
  
  puVar1 = _calloc(1,0xd8);
  *param_2 = puVar1;
  puVar1[0xc] = param_3;
  puVar1[0xd] = 0;
  *puVar1 = 0;
  puVar1[1] = 3;
  puVar1[2] = 0;
  puVar1[3] = 0;
  puVar1[4] = 0;
  puVar1[5] = 0;
  puVar1[8] = puVar1 + 6;
  puVar1[7] = 0;
  *(undefined1 *)((int)puVar1 + 0x39) = 3;
  *(undefined2 *)((int)puVar1 + 0x2e) = 0;
  *(undefined1 *)(puVar1 + 0xe) = 0;
  *(undefined2 *)(puVar1 + 9) = 0;
  *(undefined2 *)((int)puVar1 + 0x26) = 0;
  *(undefined2 *)(puVar1 + 10) = 0;
  *(undefined2 *)((int)puVar1 + 0x2a) = 0;
  *(undefined2 *)(puVar1 + 0xb) = 0;
  puVar1[6] = puVar1 + 7;
  return 0;
}

