#include "decls.h"

/* FUN_000010a0 @ 0x10a0 (32 bytes) */
int FUN_000010a0()
{
                    
                    
  (*DAT_0000f0c8)();
  return;
}

/* FUN_000010e8 @ 0x10e8 (120 bytes) */
int FUN_000010e8(param_1)
  undefined4 *param_1;
{
  int iVar1;
  undefined4 *puStack00000018;
  
  puStack00000018 = param_1;
  iVar1 = (*(code *)param_1[1])(((unsigned char *)0x000010c0),param_1,param_1);
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
  code *local_24 [9];
  
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
  int iVar1;
  
  iVar1 = _strcmp(param_1,param_2);
  return iVar1;
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
         (iVar1 = (**(code **)((int)local_20 + 0x10))(((unsigned char *)0x00001bbc)), iVar1 == 0))
      goto LAB_00001638;
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

/* FUN_00001754 @ 0x1754 (268 bytes) */
int FUN_00001754(param_1, param_2)
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
    if ((*(ushort *)(*(int *)(PTR_0000f124 + 8) + 4) < 4) || (iVar4 == 0)) {
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

/* FUN_00001b5c @ 0x1b5c (32 bytes) */
int FUN_00001b5c()
{
  ((int (*)())FUN_000018a0)();
  return;
}

/* FUN_00001c78 @ 0x1c78 (32 bytes) */
int FUN_00001c78()
{
  __keymgr_set_and_unlock_processwide_ptr();
  return;
}

/* FUN_00001cd8 @ 0x1cd8 (672 bytes) */
int FUN_00001cd8(param_1, param_2)
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
  iVar4 = ((int (*)())FUN_00001464)();
  if (iVar4 == 0) {
    local_18 = 0xffffffff;
  }
  else if ((*(char *)(iVar4 + 2) == '\0') && (*(char *)(iVar4 + 3) != '\x01')) {
    if (*(byte *)(iVar4 + 3) < 0x10) {
      pcVar1 = *(code **)(iVar4 + 8);
      iVar4 = __keymgr_set_and_unlock_processwide_ptr(0xe,iVar4);
      if ((*(ushort *)(*(int *)(PTR_0000f124 + 8) + 4) < 4) || (iVar4 == 0)) {
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
          local_18 = (*pcVar1)(((unsigned char *)0x00001a24),puVar5,uStack0000001c);
        }
      }
      else {
        local_18 = 0xffffffff;
      }
    }
    else if (puStack00000018[1] == 0) {
      pcVar1 = *(code **)(iVar4 + 0x10);
      iVar4 = __keymgr_set_and_unlock_processwide_ptr(0xe,iVar4);
      if ((*(ushort *)(*(int *)(PTR_0000f124 + 8) + 4) < 4) || (iVar4 == 0)) {
        local_18 = (*pcVar1)(*puStack00000018);
      }
      else {
        local_18 = 0xffffffff;
      }
    }
    else {
      pcVar1 = *(code **)(iVar4 + 8);
      iVar4 = __keymgr_set_and_unlock_processwide_ptr(0xe,iVar4);
      if ((*(ushort *)(*(int *)(PTR_0000f124 + 8) + 4) < 4) || (iVar4 == 0)) {
        local_18 = (*pcVar1)(*puStack00000018,puStack00000018[2],uStack0000001c);
      }
      else {
        local_18 = 0xffffffff;
      }
    }
  }
  else {
    local_18 = ((int (*)())FUN_00001754)(iVar4,puStack00000018);
  }
  return local_18;
}

/* FUN_00001f78 @ 0x1f78 (32 bytes) */
int FUN_00001f78(param_1)
  size_t param_1;
{
  void *pvVar1;
  
  pvVar1 = _malloc(param_1);
  return pvVar1;
}

/* FUN_00002058 @ 0x2058 (32 bytes) */
int FUN_00002058()
{
  ((int (*)())FUN_00001cd8)();
  return;
}

/* FUN_000020d4 @ 0x20d4 (32 bytes) */
int FUN_000020d4()
{
  ((int (*)())FUN_00001cd8)();
  return;
}

/* _AVACreateRenderer @ 0x2100 (556 bytes) */
undefined8 _AVACreateRenderer(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 *param_2;
  undefined4 *param_3;
{
  undefined *puVar1;
  undefined *puVar2;
  undefined8 uVar3;
  undefined4 *puVar4;
  void *pvVar5;
  uint uVar6;
  
  uVar3 = 0xfffffffffffffff9;
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
          puVar2 = PTR_DAT_0000f190;
          puVar1 = PTR_LAB_0000f168;
          uVar6 = uVar6 + 1;
        } while ((int)uVar6 < 0x20);
        puVar4[0xc] = 0;
        puVar4[4] = puVar2;
        puVar4[5] = puVar1;
        puVar1 = PTR_FUN_0000f15c;
        puVar4[6] = PTR_LAB_0000f180;
        puVar4[7] = puVar1;
        puVar1 = PTR_FUN_0000f130;
        puVar4[8] = PTR_LAB_0000f198;
        puVar4[9] = puVar1;
        puVar1 = PTR_FUN_0000f188;
        puVar4[10] = PTR_LAB_0000f178;
        puVar4[0xb] = puVar1;
        puVar1 = PTR_LAB_0000f174;
        puVar4[0xd] = PTR_LAB_0000f144;
        puVar4[0xe] = puVar1;
        puVar1 = PTR_FUN_0000f158;
        puVar4[0xf] = PTR_FUN_0000f138;
        puVar4[0x10] = puVar1;
        puVar1 = PTR_LAB_0000f170;
        puVar4[0x11] = PTR_LAB_0000f14c;
        puVar4[0x12] = puVar1;
        puVar1 = PTR_LAB_0000f17c;
        puVar4[0x13] = PTR_LAB_0000f134;
        puVar4[0x14] = puVar1;
        puVar4[0x15] = PTR_DAT_0000f18c;
        puVar4[0x16] = ((unsigned char *)0x00002340);
        *param_1 = puVar4;
        return 0;
      }
    }
    uVar3 = 0xfffffffffffffffd;
  }
  return uVar3;
}

/* _AVACreateRendererDisplayExt @ 0x23b0 (160 bytes) */
undefined8 _AVACreateRendererDisplayExt(param_1)
  undefined4 *param_1;
{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined8 uVar4;
  undefined4 *puVar5;
  
  puVar5 = _calloc(1,0x1c);
  puVar2 = PTR_DAT_0000f160;
  uVar4 = 0xfffffffffffffffd;
  if (puVar5 != (undefined4 *)0x0) {
    puVar5[1] = 0;
    *puVar5 = 0x1020000;
    puVar1 = PTR_FUN_0000f12c;
    uVar4 = 0;
    puVar5[2] = puVar2;
    puVar3 = PTR_DAT_0000f154;
    puVar5[3] = puVar1;
    puVar2 = PTR_DAT_0000f148;
    puVar5[4] = puVar3;
    puVar1 = PTR_DAT_0000f184;
    puVar5[5] = puVar2;
    *(undefined4 **)puVar1 = puVar5;
    *param_1 = puVar5;
  }
  return uVar4;
}

/* _AVACreateRendererDVDExt @ 0x2450 (164 bytes) */
undefined8 _AVACreateRendererDVDExt(param_1)
  undefined4 *param_1;
{
  undefined *puVar1;
  undefined *puVar2;
  undefined8 uVar3;
  undefined4 *puVar4;
  
  puVar4 = _calloc(1,0x20);
  puVar2 = PTR_FUN_0000f194;
  puVar1 = PTR_LAB_0000f16c;
  uVar3 = 0xfffffffffffffffd;
  if (puVar4 != (undefined4 *)0x0) {
    *puVar4 = 0x1020000;
    uVar3 = 0;
    puVar4[2] = puVar2;
    puVar4[4] = puVar1;
    puVar1 = PTR_LAB_0000f164;
    puVar4[3] = PTR_LAB_0000f140;
    puVar4[6] = puVar1;
    puVar4[5] = PTR_LAB_0000f150;
    *param_1 = puVar4;
    *(undefined4 **)PTR_DAT_0000f13c = puVar4;
  }
  return uVar3;
}

/* _AVAGetRendererInfo @ 0x2500 (108 bytes) */
undefined8 _AVAGetRendererInfo(param_1)
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
  uint *puVar1;
  int iVar2;
  undefined *puVar3;
  int *piVar4;
  longlong lVar5;
  
  puVar3 = PTR_0000f1a0;
  piVar4 = *(int **)(param_1 + 0x34);
  if (*(int **)(param_1 + 0x38) <= piVar4 + 8) {
    puVar1 = *(uint **)(param_1 + 0x30);
    *puVar1 = (int)piVar4 - (int)puVar1 >> 2 | *puVar1;
    *(undefined4 **)(param_1 + 0x30) = *(undefined4 **)(param_1 + 0x34);
    **(undefined4 **)(param_1 + 0x34) = 0x1000000;
    _IOConnectMapMemory(*(undefined4 *)(param_1 + 0x14),1,*(undefined4 *)puVar3,param_1 + 0x40,
                        param_1 + 0x44,1);
    iVar2 = *(int *)(param_1 + 0x40);
    *(int *)(param_1 + 0x34) = iVar2 + 0x20;
    *(int *)(param_1 + 0x30) = iVar2 + 0x1c;
    *(int *)(param_1 + 0x38) = iVar2 + 0x20 + *(int *)(iVar2 + 0x10) * 4;
    *(undefined4 *)(iVar2 + 0x1c) = 0;
    piVar4 = *(int **)(param_1 + 0x34);
  }
  puVar1 = *(uint **)(param_1 + 0x30);
  *(int **)(param_1 + 0x34) = piVar4 + 8;
  lVar5 = 7;
  *puVar1 = (int)piVar4 - (int)puVar1 >> 2 | *puVar1;
  *(int **)(param_1 + 0x30) = piVar4;
  *piVar4 = param_2 * 0x1000000 + 0x2b000000;
  do {
    piVar4 = piVar4 + 1;
    *piVar4 = -0x80000000;
    puVar3 = PTR_0000f1a0;
    lVar5 = lVar5 + -1;
  } while (lVar5 != 0);
  puVar1 = *(uint **)(param_1 + 0x30);
  *puVar1 = *(int *)(param_1 + 0x34) - (int)puVar1 >> 2 | *puVar1;
  *(undefined4 **)(param_1 + 0x30) = *(undefined4 **)(param_1 + 0x34);
  **(undefined4 **)(param_1 + 0x34) = 0x1000000;
  _IOConnectMapMemory(*(undefined4 *)(param_1 + 0x14),1,*(undefined4 *)puVar3,param_1 + 0x40,
                      param_1 + 0x44,1);
  iVar2 = *(int *)(param_1 + 0x40);
  *(int *)(param_1 + 0x34) = iVar2 + 0x20;
  *(int *)(param_1 + 0x30) = iVar2 + 0x1c;
  *(int *)(param_1 + 0x38) = iVar2 + 0x20 + *(int *)(iVar2 + 0x10) * 4;
  *(undefined4 *)(iVar2 + 0x1c) = 0;
  return;
}

/* FUN_00002d00 @ 0x2d00 (120 bytes) */
undefined8 FUN_00002d00(param_1, param_2, param_3)
  int param_1;
  undefined8 param_2;
  undefined *param_3;
{
  int iVar1;
  undefined4 local_28;
  undefined4 local_24;
  
  if (param_3 < ((unsigned char *)0x00002710)) {
    iVar1 = (int)param_3 * 8 + param_1 + 0x55c;
    local_28 = *(undefined4 *)(iVar1 + 0x56c);
    local_24 = *(undefined4 *)(iVar1 + 0x570);
    iVar1 = _io_connect_method_scalarI_structureI
                      (*(undefined4 *)(param_1 + 0x14),0x13,&local_28,2,0,0);
    if (iVar1 == 0) {
      return 0;
    }
  }
  return 0xfffffffffffffff9;
}

/* FUN_00002dc0 @ 0x2dc0 (68 bytes) */
undefined8 FUN_00002dc0(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  undefined8 uVar1;
  
  uVar1 = 0xfffffffffffffff9;
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

/* FUN_00002e50 @ 0x2e50 (1144 bytes) */
undefined8 FUN_00002e50(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  float *param_3;
{
  float fVar1;
  float fVar2;
  float fVar3;
  uint uVar4;
  int iVar5;
  undefined8 uVar6;
  bool bVar7;
  double dVar8;
  undefined4 local_148;
  undefined4 local_144;
  uint local_140;
  undefined4 local_13c;
  undefined4 local_138;
  uint local_134;
  undefined1 auStack_130 [304];
  
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
    uVar6 = 0xfffffffffffffffb;
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
    ((int (*)())FUN_00004740)(param_1,SUB41(*param_3,0),(char)*(undefined4 *)(param_1 + 0x114),param_1 + 0x10c,
                 *(undefined4 *)(param_1 + 0x118));
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
      return 0xfffffffffffffffb;
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
  return 0xfffffffffffffffb;
}

/* FUN_00003350 @ 0x3350 (720 bytes) */
undefined8 FUN_00003350(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int param_1;
  uint *param_2;
  undefined8 param_3;
  uint param_4;
  uint param_5;
  uint param_6;
  uint param_7;
{
  bool bVar1;
  uint uVar2;
  undefined4 uVar4;
  undefined8 uVar3;
  void *pvVar5;
  void *pvVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  undefined4 local_48;
  undefined4 local_44;
  uint local_40;
  int local_3c;
  
  if (param_2 == (uint *)0x0) {
    return 0xfffffffffffffff9;
  }
  pvVar5 = _calloc(1,0x34);
  if (pvVar5 == (void *)0x0) {
    return 0xfffffffffffffffd;
  }
  if (param_6 == 0x61723135) {
    uVar4 = 0xb;
  }
  else if (param_6 < 0x61723136) {
    if (param_6 == 0x20) {
LAB_00003450:
      *(undefined4 *)((int)pvVar5 + 0x24) = 4;
      *(undefined4 *)((int)pvVar5 + 0x28) = 2;
      *(undefined4 *)((int)pvVar5 + 0x2c) = 0xc;
      *(undefined4 *)((int)pvVar5 + 0x30) = 2;
      goto LAB_000034b4;
    }
    if (param_6 != 0x32767579) {
      if (param_6 != 8) {
        return 0xfffffffffffffff9;
      }
      *(undefined4 *)((int)pvVar5 + 0x28) = 0;
      *(undefined4 *)((int)pvVar5 + 0x24) = 1;
      *(undefined4 *)((int)pvVar5 + 0x2c) = 0;
      *(undefined4 *)((int)pvVar5 + 0x30) = 0;
      goto LAB_000034b4;
    }
    uVar4 = 0x14;
  }
  else {
    if (param_6 == 0x72676261) {
      *(undefined4 *)((int)pvVar5 + 0x2c) = 0xc;
      *(undefined4 *)((int)pvVar5 + 0x24) = 4;
      *(undefined4 *)((int)pvVar5 + 0x30) = 0;
      *(undefined4 *)((int)pvVar5 + 0x28) = 2;
      goto LAB_000034b4;
    }
    if (param_6 != 0x79757673) {
      if (param_6 != 0x61726762) {
        return 0xfffffffffffffff9;
      }
      goto LAB_00003450;
    }
    uVar4 = 0x15;
  }
  *(undefined4 *)((int)pvVar5 + 0x2c) = uVar4;
  *(undefined4 *)((int)pvVar5 + 0x24) = 2;
  *(undefined4 *)((int)pvVar5 + 0x30) = 0;
  *(undefined4 *)((int)pvVar5 + 0x28) = 1;
LAB_000034b4:
  bVar1 = param_7 != 0;
  param_2[5] = param_5;
  param_2[4] = param_4;
  *param_2 = 0;
  if (bVar1) {
    uVar9 = *(uint *)((int)pvVar5 + 0x24);
    param_2[6] = param_4 * uVar9;
  }
  else {
    uVar9 = *(uint *)((int)pvVar5 + 0x24);
    param_2[6] = param_4 * uVar9 + 0xff & 0xffffff00;
  }
  param_2[1] = param_6;
  *(undefined4 *)((int)pvVar5 + 4) = *(undefined4 *)(param_1 + 0xc);
  uVar7 = param_2[6];
  *(undefined2 *)((int)pvVar5 + 10) = 0;
  *(undefined2 *)((int)pvVar5 + 8) = 0;
  *(uint *)((int)pvVar5 + 0x18) = uVar7 / uVar9;
  uVar9 = param_2[4];
  *(short *)((int)pvVar5 + 0xc) = (short)uVar9;
  uVar2 = param_2[5];
  *(uint *)((int)pvVar5 + 0x10) = uVar9;
  *(short *)((int)pvVar5 + 0xe) = (short)uVar2;
  *(uint *)((int)pvVar5 + 0x14) = uVar2;
  if (bVar1) {
    *param_2 = param_7;
  }
  else {
    pvVar6 = _malloc(uVar2 * uVar7 + 0x100);
    *param_2 = (uint)pvVar6;
    if (pvVar6 == (void *)0x0) {
      _free(pvVar5);
      return 0xfffffffffffffffd;
    }
    uVar7 = param_2[6];
    uVar2 = param_2[5];
  }
  local_44 = 0;
  if (bVar1) {
    local_40 = *param_2;
  }
  else {
    local_40 = *param_2 + 0xff & 0xffffff00;
  }
  local_3c = uVar2 * uVar7;
  local_48 = 1;
  iVar8 = _io_connect_method_scalarI_scalarO
                    (*(undefined4 *)(param_1 + 0x14),8,&local_44,3,pvVar5,&local_48);
  if (iVar8 == 0) {
    if ((*(uint *)(param_1 + 0x20) & 0x82) != 0) {
      param_2[9] = 1;
    }
    param_2[10] = (uint)pvVar5;
    uVar3 = 0;
  }
  else {
    _free(pvVar5);
    _free((void *)*param_2);
    uVar3 = 0xfffffffffffffffd;
  }
  return uVar3;
}

/* FUN_00003630 @ 0x3630 (356 bytes) */
undefined8 FUN_00003630(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  int param_3;
{
  undefined4 uVar1;
  undefined4 *puVar2;
  uint uVar3;
  undefined8 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  
  iVar8 = param_1 + 0x55c;
  iVar6 = *(int *)(param_1 + 0x54);
  uVar4 = 0xfffffffffffffff9;
  if (iVar6 == param_3) {
    if (iVar6 != 0) {
      iVar9 = 0;
      iVar7 = iVar8;
      do {
        puVar2 = (undefined4 *)param_2[iVar9];
        iVar5 = ((int (*)())FUN_00003350)(param_1,param_1 + 0x814 + iVar9 * 100,*(undefined4 *)(iVar7 + 0x4ac),
                             *puVar2,puVar2[1],puVar2[3],0);
        if (iVar5 != 0) {
          if (0 < iVar9) {
            iVar8 = 0;
            iVar6 = param_1 + 0x814;
            do {
              iVar8 = iVar8 + 1;
              ((int (*)())FUN_00002930)(param_1,iVar6,1);
              iVar6 = iVar6 + 100;
            } while (iVar8 != iVar9);
          }
          return 0xfffffffffffffffd;
        }
        iVar9 = iVar9 + 1;
        iVar7 = iVar7 + 4;
        iVar5 = iVar8;
      } while (iVar9 != iVar6);
      do {
        *(undefined4 *)(iVar5 + 0x178) = *(undefined4 *)*param_2;
        *(undefined4 *)(iVar5 + 0x17c) = *(undefined4 *)(*param_2 + 4);
        uVar1 = *(undefined4 *)(iVar8 + 0x2d0);
        *(undefined4 *)(iVar5 + 0x180) = uVar1;
        *(undefined4 *)(iVar5 + 0x184) = *(undefined4 *)(*param_2 + 0xc);
        iVar6 = *(int *)(iVar8 + 0x2b8);
        *(undefined4 *)(iVar5 + 0x194) = 1;
        iVar8 = iVar8 + 100;
        uVar3 = iVar6 + 0xffU & 0xffffff00;
        *(uint *)(iVar5 + 400) = uVar3;
        iVar5 = iVar5 + 0x40;
        *(undefined4 *)(*param_2 + 8) = uVar1;
        iVar6 = *param_2;
        param_2 = param_2 + 1;
        *(uint *)(iVar6 + 0x18) = uVar3;
        iVar9 = iVar9 + -1;
      } while (iVar9 != 0);
    }
    uVar4 = 0;
  }
  return uVar4;
}

/* FUN_00003cd0 @ 0x3cd0 (672 bytes) */
int FUN_00003cd0(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  int *piVar2;
  uint uVar3;
  undefined *puVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  uint *puVar8;
  char in_RESERVE;
  byte in_cr0;
  longlong lVar9;
  
  puVar4 = PTR_0000f1a0;
  piVar7 = *(int **)(param_1 + 0x34);
  if (*(int **)(param_1 + 0x38) <= piVar7 + 8) {
    puVar8 = *(uint **)(param_1 + 0x30);
    *puVar8 = (int)piVar7 - (int)puVar8 >> 2 | *puVar8;
    *(undefined4 **)(param_1 + 0x30) = *(undefined4 **)(param_1 + 0x34);
    **(undefined4 **)(param_1 + 0x34) = 0x1000000;
    _IOConnectMapMemory(*(undefined4 *)(param_1 + 0x14),1,*(undefined4 *)puVar4,param_1 + 0x40,
                        param_1 + 0x44,1);
    iVar1 = *(int *)(param_1 + 0x40);
    *(int *)(param_1 + 0x34) = iVar1 + 0x20;
    *(int *)(param_1 + 0x30) = iVar1 + 0x1c;
    *(int *)(param_1 + 0x38) = iVar1 + 0x20 + *(int *)(iVar1 + 0x10) * 4;
    *(undefined4 *)(iVar1 + 0x1c) = 0;
    piVar7 = *(int **)(param_1 + 0x34);
  }
  puVar8 = *(uint **)(param_1 + 0x30);
  *(int **)(param_1 + 0x34) = piVar7 + 8;
  piVar6 = piVar7 + 1;
  *puVar8 = (int)piVar7 - (int)puVar8 >> 2 | *puVar8;
  *(int **)(param_1 + 0x30) = piVar7;
  *piVar7 = param_2 * 0x1000000 + 0x19000000;
  piVar5 = piVar6;
  switch(param_2) {
  case 0:
    puVar8 = *(uint **)(param_1 + 0x151b4);
    break;
  case 1:
    puVar8 = *(uint **)(param_1 + 0x153bc);
    break;
  case 2:
    puVar8 = *(uint **)(param_1 + 0x170);
    goto LAB_00003ed8;
  case 3:
    puVar8 = *(uint **)(param_1 + 0x1d8);
    goto LAB_00003ed8;
  case 4:
  case 5:
  case 6:
  case 7:
  case 8:
  case 9:
  case 10:
  case 0xb:
    puVar8 = *(uint **)(param_2 * 100 + param_1 + 0xb0);
    break;
  case 0xc:
  case 0xd:
  case 0xe:
  case 0xf:
  case 0x10:
    puVar8 = *(uint **)(param_2 * 100 + param_1 + 0x38c);
    break;
  case 0x11:
    puVar8 = *(uint **)(param_1 + 0xa44);
LAB_00003ed8:
    piVar2 = (int *)*puVar8;
    piVar5 = piVar7 + 2;
    *piVar6 = *piVar2;
    lVar9 = ZEXT48(piVar2) + 0x10;
    do {
      puVar8 = (uint *)lVar9;
      if (in_RESERVE != '\0') {
        uVar3 = storeWordConditionalIndexed((ulonglong)*puVar8 + 1,0,lVar9);
        *puVar8 = uVar3;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
  default:
    goto switchD_00003e00_default;
  }
  piVar5 = piVar7 + 2;
  piVar7 = (int *)*puVar8;
  *piVar6 = *piVar7;
  lVar9 = ZEXT48(piVar7) + 0x10;
  do {
    puVar8 = (uint *)lVar9;
    if (in_RESERVE != '\0') {
      uVar3 = storeWordConditionalIndexed((ulonglong)*puVar8 + 1,0,lVar9);
      *puVar8 = uVar3;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
switchD_00003e00_default:
  lVar9 = 6;
  do {
    *piVar5 = -0x80000000;
    puVar4 = PTR_0000f1a0;
    piVar5 = piVar5 + 1;
    lVar9 = lVar9 + -1;
  } while (lVar9 != 0);
  puVar8 = *(uint **)(param_1 + 0x30);
  *puVar8 = *(int *)(param_1 + 0x34) - (int)puVar8 >> 2 | *puVar8;
  *(undefined4 **)(param_1 + 0x30) = *(undefined4 **)(param_1 + 0x34);
  **(undefined4 **)(param_1 + 0x34) = 0x1000000;
  _IOConnectMapMemory(*(undefined4 *)(param_1 + 0x14),1,*(undefined4 *)puVar4,param_1 + 0x40,
                      param_1 + 0x44,1);
  iVar1 = *(int *)(param_1 + 0x40);
  *(int *)(param_1 + 0x34) = iVar1 + 0x20;
  *(int *)(param_1 + 0x30) = iVar1 + 0x1c;
  *(int *)(param_1 + 0x38) = iVar1 + 0x20 + *(int *)(iVar1 + 0x10) * 4;
  *(undefined4 *)(iVar1 + 0x1c) = 0;
  return;
}

/* FUN_00004340 @ 0x4340 (988 bytes) */
undefined8 FUN_00004340(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  uint param_3;
{
  bool bVar1;
  undefined4 uVar2;
  uint uVar4;
  longlong lVar3;
  longlong lVar5;
  uint uVar6;
  void *pvVar8;
  undefined8 uVar7;
  int iVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  uint uVar13;
  uint *puVar14;
  undefined4 *puVar15;
  ulonglong uVar16;
  int iVar17;
  ulonglong uVar18;
  undefined4 local_48;
  undefined4 local_44;
  uint local_40;
  undefined4 local_3c;
  undefined4 local_38;
  uint local_34;
  
  iVar17 = param_1 + 0x55c;
  uVar6 = *(uint *)(param_1 + 0x54);
  uVar16 = (ulonglong)uVar6;
  if ((uVar6 != param_3) || (uVar6 == 0)) {
    return 0xfffffffffffffff9;
  }
  if (uVar16 < 6) {
    uVar13 = *(int *)*param_2 + 0xf;
    uVar11 = uVar13 & 0xfffffff0;
    *(uint *)(param_1 + 0x578) = uVar11;
    uVar4 = *(int *)(*param_2 + 4) + 0xf;
    *(uint *)(param_1 + 0x57c) = uVar4 & 0xfffffff0;
    if ((uVar13 & 0xf0) != 0) {
      uVar11 = (uVar13 & 0xffffff00) + 0x100;
    }
    *(uint *)(param_1 + 0x588) = uVar11;
    *(uint *)(param_1 + 0x580) = uVar13 >> 4;
    *(uint *)(param_1 + 0x584) = uVar4 >> 4;
    iVar9 = 0;
    *(undefined2 *)(param_1 + 0x126) = 0;
    puVar15 = (undefined4 *)(param_1 + 0x14430);
    *(undefined2 *)(param_1 + 0x124) = 0;
    *(short *)(param_1 + 0x12a) = (short)*(undefined4 *)(param_1 + 0x578);
    *(short *)(param_1 + 0x128) = (short)*(undefined4 *)(param_1 + 0x57c);
    *(int *)(param_1 + 0x14424) = *(int *)(param_1 + 0x580) * *(int *)(param_1 + 0x584);
    do {
      pvVar8 = _malloc(*(int *)(param_1 + 0x14424) << 2);
      *puVar15 = pvVar8;
      if (pvVar8 == (void *)0x0) {
        if (0 < iVar9) {
          puVar15 = (undefined4 *)(param_1 + 0x14430);
          iVar17 = 0;
          do {
            pvVar8 = (void *)*puVar15;
            iVar17 = iVar17 + 1;
            puVar15 = puVar15 + 3;
            _free(pvVar8);
          } while (iVar17 != iVar9);
        }
        goto LAB_00004448;
      }
      bVar1 = iVar9 != 0x18;
      puVar15 = puVar15 + 3;
      iVar9 = iVar9 + 1;
    } while (bVar1);
    uVar11 = *(uint *)(param_1 + 0xa84);
    iVar9 = 0;
    uVar18 = uVar16;
    do {
      uVar4 = iVar9 + 10;
      iVar9 = iVar9 + 1;
      uVar11 = uVar11 | 1 << (uVar4 & 0x3f);
      uVar18 = uVar18 - 1;
    } while (uVar18 != 0);
    *(uint *)(param_1 + 0xa84) = uVar11;
    if ((uVar6 < 5) && ((int)uVar6 < 5)) {
      lVar5 = uVar16 + 10;
      lVar3 = 0xf - lVar5;
      do {
        uVar6 = (uint)lVar5;
        lVar5 = lVar5 + 1;
        uVar11 = uVar11 & ~(1 << (uVar6 & 0x3f));
        lVar3 = lVar3 + -1;
      } while (lVar3 != 0);
      *(uint *)(param_1 + 0xa84) = uVar11;
    }
    local_40 = *(undefined4 *)(param_1 + 0x578);
    local_3c = *(undefined4 *)(param_1 + 0x57c);
    local_34 = *(uint *)(param_1 + 0xa84) | 0x20000;
    *(uint *)(param_1 + 0xa84) = local_34;
    local_38 = 0;
    local_48 = 0;
    local_44 = 0;
    iVar9 = _io_connect_method_scalarI_scalarO
                      (*(undefined4 *)(param_1 + 0x14),0x15,&local_44,5,0,&local_48);
    if (iVar9 == 0) {
      local_44 = *(undefined4 *)(param_1 + 0xc);
      local_40 = *(uint *)(param_1 + 0x18) & 0xffff4000;
      local_3c = 1;
      iVar9 = _io_connect_method_scalarI_structureI
                        (*(undefined4 *)(param_1 + 0x14),0,&local_44,3,0,0);
      if (iVar9 == 0) {
        *(undefined4 *)(param_1 + 0x28) = *(undefined4 *)(param_1 + 0x578);
        *(undefined4 *)(param_1 + 0x2c) = *(undefined4 *)(param_1 + 0x57c);
        iVar9 = ((int (*)())FUN_00003350)(param_1,param_1 + 0x1518c,*(undefined4 *)(param_1 + 0x151f0),
                             *(uint *)(param_1 + 0x578) >> 4,
                             (longlong)(int)(*(uint *)(param_1 + 0x57c) >> 1 & 0x7ffffff8) *
                             (longlong)*(int *)(param_1 + 0x54),0x20,0);
        if (iVar9 == 0) {
          iVar9 = 0;
          iVar12 = param_1 + 0x151ec;
          iVar10 = param_1 + 0x1523c;
          *(undefined4 *)(param_1 + 0x58c) = *(undefined4 *)(param_1 + 0x151a4);
          uVar6 = *(uint *)(param_1 + 0x57c) >> 4;
          uVar11 = *(int *)(param_1 + 0x1518c) + 0xffU & 0xffffff00;
          do {
            puVar14 = (uint *)(iVar12 + 8);
            lVar3 = 4;
            do {
              *puVar14 = uVar11;
              puVar14 = puVar14 + 1;
              uVar11 = uVar11 + (uVar6 * *(int *)(param_1 + 0x151a4) & 0xfffffffc);
              lVar3 = lVar3 + -1;
            } while (lVar3 != 0);
            puVar14 = (uint *)(iVar10 + 8);
            lVar3 = 4;
            do {
              *puVar14 = uVar11;
              puVar14 = puVar14 + 1;
              uVar11 = uVar11 + (uVar6 * *(int *)(param_1 + 0x151a4) & 0xfffffffc);
              lVar3 = lVar3 + -1;
            } while (lVar3 != 0);
            bVar1 = iVar9 != 4;
            iVar12 = iVar12 + 0x10;
            iVar10 = iVar10 + 0x10;
            iVar9 = iVar9 + 1;
          } while (bVar1);
          ((int (*)())FUN_00003cd0)(param_1,0);
          iVar9 = ((int (*)())FUN_00003350)(param_1,param_1 + 0x15394,*(undefined4 *)(param_1 + 0x153f8),
                               *(uint *)(param_1 + 0x578) >> 4,
                               (ulonglong)(*(uint *)(param_1 + 0x57c) >> 4) * 0x18,0x20,0);
          if (iVar9 == 0) {
            ((int (*)())FUN_00003cd0)(param_1,1);
            ((int (*)())FUN_00006d90)(param_1);
            ((int (*)())FUN_00005d70)(param_1);
            DAT_0000f1a8 = *(undefined4 *)(param_1 + 0x578);
            DAT_0000f1a4 = *(undefined4 *)(param_1 + 0x57c);
            do {
              *(undefined4 *)(iVar17 + 0x38) = *(undefined4 *)(param_1 + 0x578);
              *(undefined4 *)(iVar17 + 0x3c) = *(undefined4 *)(param_1 + 0x57c);
              uVar2 = *(undefined4 *)(param_1 + 0x588);
              *(undefined4 *)(iVar17 + 0x44) = 0x59563132;
              *(undefined4 *)(iVar17 + 0x54) = 1;
              *(undefined4 *)(iVar17 + 0x40) = uVar2;
              iVar17 = iVar17 + 0x40;
              uVar16 = uVar16 - 1;
            } while (uVar16 != 0);
            return 0;
          }
        }
        goto LAB_00004448;
      }
    }
    uVar7 = 0xfffffffffffffffb;
  }
  else {
LAB_00004448:
    uVar7 = 0xfffffffffffffffd;
  }
  return uVar7;
}

/* FUN_00004740 @ 0x4740 (664 bytes) */
int FUN_00004740(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int param_2;
  undefined4 param_3;
  undefined4 *param_4;
  int param_5;
{
  uint uVar1;
  undefined4 uVar2;
  uint *puVar3;
  int iVar4;
  undefined *puVar5;
  int iVar6;
  int iVar7;
  
  iVar6 = param_2 * 4;
  iVar7 = param_1 + 0x55c;
  iVar4 = iVar6 + iVar7;
  if (*(int *)(iVar4 + 0x52c) != 0) {
    return;
  }
  if (*(int *)(iVar4 + 0x554) == 0) {
    if (*(int *)(param_1 + 0x120) != 0) {
      if (*(int *)(iVar4 + 0x540) == 1) {
        if (*(int *)(param_1 + 0x120) == 4) {
          FUN_0000caa0(param_1,param_1 + 0x14348 + param_2 * 0x14,param_1 + 0x143ac + param_2 * 0x18
                       ,1);
        }
        FUN_0000caa0(param_1,param_2 * 0x14 + param_1 + 0x14348,param_2 * 0x18 + param_1 + 0x143ac,2
                    );
        *(undefined4 *)(iVar6 + iVar7 + 0x554) = 1;
        goto LAB_00004810;
      }
      goto LAB_0000481c;
    }
  }
  else {
LAB_00004810:
    if (*(int *)(param_1 + 0x120) != 0) {
LAB_0000481c:
      if (*(int *)(iVar6 + iVar7 + 0x554) != 0) {
        uVar1 = *(uint *)(param_1 + 0x11c);
        if ((uVar1 & 2) != 0) {
          ((int (*)())FUN_0000a110)(param_1,param_2,1);
          uVar1 = *(uint *)(param_1 + 0x11c);
        }
        if ((uVar1 & 4) != 0) {
          ((int (*)())FUN_00009c80)(param_1,param_2,1);
        }
        ((int (*)())FUN_0000b7f0)(param_1,param_2,1);
        goto LAB_000048e0;
      }
    }
  }
  uVar1 = *(uint *)(param_1 + 0x11c);
  if ((uVar1 & 2) != 0) {
    ((int (*)())FUN_0000a110)(param_1,param_2,0);
    uVar1 = *(uint *)(param_1 + 0x11c);
  }
  if ((uVar1 & 4) != 0) {
    ((int (*)())FUN_00009c80)(param_1,param_2,0);
  }
  ((int (*)())FUN_0000b7f0)(param_1,param_2,0);
LAB_000048e0:
  *(int *)(param_1 + 0x118) = param_5;
  if (param_5 != 0) {
    *(undefined4 *)(param_1 + 0x114) = param_3;
    uVar2 = *param_4;
    *(undefined4 *)(param_1 + 0x110) = param_4[1];
    *(undefined4 *)(param_1 + 0x10c) = uVar2;
    ((int (*)())FUN_0000ae80)(param_1);
  }
  puVar3 = *(uint **)(param_1 + 0x30);
  *puVar3 = *(int *)(param_1 + 0x34) - (int)puVar3 >> 2 | *puVar3;
  puVar5 = PTR_0000f1a0;
  *(undefined4 **)(param_1 + 0x30) = *(undefined4 **)(param_1 + 0x34);
  **(undefined4 **)(param_1 + 0x34) = 0x2000000;
  _IOConnectMapMemory(*(undefined4 *)(param_1 + 0x14),1,*(undefined4 *)puVar5,param_1 + 0x40,
                      param_1 + 0x44,1);
  iVar4 = *(int *)(param_1 + 0x40);
  *(int *)(param_1 + 0x34) = iVar4 + 0x20;
  *(int *)(param_1 + 0x30) = iVar4 + 0x1c;
  *(int *)(param_1 + 0x38) = iVar4 + 0x20 + *(int *)(iVar4 + 0x10) * 4;
  *(undefined4 *)(iVar4 + 0x1c) = 0;
  if ((*(uint *)(*(int *)(param_1 + 0x40) + 0x14) & 2) == 0) {
    return;
  }
                    
                    
  (**(code **)(*(int *)(*(int *)(param_1 + 0x50) + 0xc) + 0xc))
            (*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8),
             *(undefined4 *)(param_1 + 0xc));
  return;
}

/* FUN_00004fa0 @ 0x4fa0 (552 bytes) */
undefined8 FUN_00004fa0(param_1, param_2)
  int param_1;
  uint *param_2;
{
  uint uVar1;
  undefined8 uVar2;
  uint uVar3;
  int iVar5;
  longlong lVar4;
  int iVar6;
  ulonglong uVar7;
  int iVar8;
  ulonglong uVar9;
  undefined4 local_48;
  undefined4 local_44;
  uint local_40;
  undefined4 local_3c;
  undefined4 local_38;
  uint local_34;
  
  uVar3 = *param_2;
  *(uint *)(param_1 + 0x5c) = uVar3;
  if (uVar3 < 9) {
    *(undefined4 *)(param_1 + 0x60) = 0x2d0;
    if ((*(int *)(param_1 + 0x57c) == 0x240) || (*(int *)(param_1 + 0x57c) == 0x120)) {
      *(undefined4 *)(param_1 + 100) = 0x240;
    }
    else {
      *(undefined4 *)(param_1 + 100) = 0x1e0;
    }
    uVar3 = *(uint *)(param_1 + 0x60);
    if ((uVar3 & 0xff) != 0) {
      uVar3 = (uVar3 & 0xffffff00) + 0x100;
    }
    uVar1 = *(uint *)(param_1 + 0x5c);
    uVar7 = (ulonglong)uVar1;
    *(uint *)(param_1 + 0x68) = uVar3;
    if (uVar1 != 0) {
      uVar9 = uVar7;
      iVar6 = param_1;
      if (uVar1 == 0) {
        uVar9 = 1;
      }
      do {
        *(uint *)(iVar6 + 0x6c) = param_2[0x15];
        param_2 = param_2 + 1;
        *(uint *)(iVar6 + 0xbc) = *param_2;
        iVar6 = iVar6 + 4;
        uVar9 = uVar9 - 1;
      } while (uVar9 != 0);
    }
    if (uVar1 != 0) {
      uVar9 = 0;
      iVar8 = param_1 + 0x218;
      iVar6 = param_1;
      do {
        iVar5 = ((int (*)())FUN_00003350)(param_1,iVar8,*(undefined4 *)(iVar6 + 0x538),0xc0,
                             *(undefined4 *)(param_1 + 100),8,*(undefined4 *)(iVar6 + 0x6c));
        if (iVar5 != 0) goto LAB_000051c0;
        uVar7 = (ulonglong)*(uint *)(param_1 + 0x5c);
        uVar9 = uVar9 + 1;
        iVar8 = iVar8 + 100;
        iVar6 = iVar6 + 4;
      } while ((uVar9 & 0xffffffff) < uVar7);
    }
    lVar4 = ((int (*)())FUN_00003350)(param_1,param_1 + 0x1b0,*(undefined4 *)(param_1 + 0x214),0x20,uVar7,0x20,0)
    ;
    if (lVar4 == 0) {
      ((int (*)())FUN_00003cd0)(param_1,3);
      local_3c = *(undefined4 *)(param_1 + 0x57c);
      local_40 = *(undefined4 *)(param_1 + 0x578);
      local_34 = *(uint *)(param_1 + 0xa84) | 0x10000;
      *(uint *)(param_1 + 0xa84) = local_34;
      local_38 = 0;
      local_48 = 0;
      local_44 = 0;
      iVar6 = _io_connect_method_scalarI_scalarO
                        (*(undefined4 *)(param_1 + 0x14),0x15,&local_44,5,0,&local_48);
      if (iVar6 == 0) {
        local_44 = *(undefined4 *)(param_1 + 0xc);
        local_40 = *(uint *)(param_1 + 0x18) & 0xffff4000;
        local_3c = 1;
        iVar6 = _io_connect_method_scalarI_structureI
                          (*(undefined4 *)(param_1 + 0x14),0,&local_44,3,0,0);
        if (iVar6 == 0) {
          return 0;
        }
      }
      uVar2 = 0xfffffffffffffffb;
    }
    else {
LAB_000051c0:
      uVar2 = 0xfffffffffffffffd;
    }
  }
  else {
    _puts("Number of subpicture bitmap exceed the maximum set.");
    uVar2 = 0xfffffffffffffffd;
  }
  return uVar2;
}

/* FUN_00005d70 @ 0x5d70 (600 bytes) */
int FUN_00005d70(param_1)
  int param_1;
{
  uint uVar1;
  uint uVar2;
  ulonglong uVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined4 *puVar7;
  ulonglong uVar6;
  uint uVar8;
  ulonglong uVar9;
  uint uVar10;
  ulonglong uVar11;
  ulonglong uVar12;
  undefined4 *puVar13;
  uint uVar15;
  ulonglong uVar14;
  uint uVar18;
  ulonglong uVar16;
  ulonglong uVar17;
  
  uVar1 = *(uint *)(param_1 + 0x57c);
  uVar2 = *(uint *)(param_1 + 0x578);
  puVar13 = (undefined4 *)(*(int *)(param_1 + 0x15394) + 0xffU & 0xffffff00);
  if (uVar1 == 0) {
    uVar11 = 0;
    uVar5 = 0;
  }
  else {
    uVar8 = 0;
    uVar11 = 0;
    do {
      puVar7 = puVar13;
      if (uVar2 != 0) {
        uVar15 = 0;
        uVar10 = (uVar8 + 0x10) * 0x10000;
        uVar4 = uVar8 << 0x10;
        uVar18 = uVar10;
        do {
          *(uint *)((int)puVar13 + uVar15) = uVar4;
          uVar15 = uVar15 + 0x10;
          puVar7[1] = uVar18;
          uVar11 = uVar11 + 1;
          uVar18 = uVar15 | uVar10;
          uVar4 = uVar15 | uVar8 << 0x10;
          puVar7[2] = uVar18;
          puVar7[3] = uVar4;
          puVar7 = puVar7 + 4;
        } while (uVar15 < uVar2);
      }
      puVar13 = puVar7;
      uVar8 = uVar8 + 0x10;
    } while (uVar8 < uVar1);
    uVar5 = (undefined4)((uVar11 & 0xffffffff) << 2);
  }
  *(undefined4 *)(param_1 + 0x153fc) = uVar5;
  if (uVar1 != 0) {
    uVar8 = 0;
    do {
      puVar7 = puVar13;
      if (uVar2 != 0) {
        uVar15 = 0;
        uVar10 = (uVar8 + 8) * 0x10000;
        uVar4 = uVar8 << 0x10;
        uVar18 = uVar10;
        do {
          *(uint *)((int)puVar13 + uVar15) = uVar4;
          uVar15 = uVar15 + 0x10;
          puVar7[1] = uVar18;
          uVar11 = uVar11 + 1;
          uVar18 = uVar15 | uVar10;
          uVar4 = uVar15 | uVar8 << 0x10;
          puVar7[2] = uVar18;
          puVar7[3] = uVar4;
          puVar7 = puVar7 + 4;
        } while (uVar15 < uVar2);
      }
      puVar13 = puVar7;
      uVar8 = uVar8 + 8;
    } while (uVar8 < uVar1);
    uVar5 = (undefined4)((uVar11 & 0xffffffff) << 2);
  }
  uVar3 = (ulonglong)(uVar1 >> 1);
  uVar2 = uVar2 >> 1;
  *(undefined4 *)(param_1 + 0x15400) = uVar5;
  if (uVar3 != 0) {
    uVar9 = 0;
    do {
      if (uVar2 != 0) {
        uVar12 = (uVar9 & 0xffff) << 0x10;
        uVar16 = 0;
        uVar14 = (uVar9 + 8 & 0xffff) << 0x10;
        uVar17 = uVar14;
        uVar6 = uVar12;
        do {
          uVar16 = uVar16 + 8;
          *puVar13 = (int)uVar6;
          puVar13[1] = (int)uVar17;
          uVar6 = uVar16 | uVar12;
          uVar17 = uVar16 | uVar14;
          uVar11 = uVar11 + 1;
          puVar13[3] = (int)uVar6;
          puVar13[2] = (int)uVar17;
          puVar13 = puVar13 + 4;
        } while ((uVar16 & 0xffffffff) < (ulonglong)uVar2);
      }
      uVar9 = uVar9 + 8;
    } while ((uVar9 & 0xffffffff) < uVar3);
    uVar5 = (undefined4)((uVar11 & 0xffffffff) << 2);
  }
  *(undefined4 *)(param_1 + 0x15404) = uVar5;
  if (uVar3 != 0) {
    uVar11 = 0;
    do {
      if (uVar2 != 0) {
        uVar12 = (uVar11 & 0xffff) << 0x10;
        uVar6 = 0;
        uVar14 = (uVar11 + 4 & 0xffff) << 0x10;
        uVar9 = uVar14;
        uVar17 = uVar12;
        do {
          uVar6 = uVar6 + 8;
          *puVar13 = (int)uVar17;
          puVar13[1] = (int)uVar9;
          uVar17 = uVar6 | uVar12;
          uVar9 = uVar6 | uVar14;
          puVar13[3] = (int)uVar17;
          puVar13[2] = (int)uVar9;
          puVar13 = puVar13 + 4;
        } while ((uVar6 & 0xffffffff) < (ulonglong)uVar2);
      }
      uVar11 = uVar11 + 4;
    } while ((uVar11 & 0xffffffff) < uVar3);
  }
  ((int (*)())FUN_0000bf20)(param_1,*(int *)(param_1 + 0x15394) + 0xffU & 0xffffff00,
               (longlong)*(int *)(param_1 + 0x153a8) * (longlong)*(int *)(param_1 + 0x153ac));
  return;
}

/* FUN_00005fd0 @ 0x5fd0 (320 bytes) */
undefined8 FUN_00005fd0(param_1, param_2)
  int param_1;
  int param_2;
{
  bool bVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  int local_48;
  int local_44;
  uint local_40;
  undefined4 local_3c;
  uint local_30;
  
  bVar1 = param_2 != 0;
  local_58 = 0;
  if (bVar1) {
    local_44 = *(int *)(param_1 + 0x15148) - *(int *)(param_1 + 0x15140);
  }
  else {
    local_44 = *(int *)(param_1 + 0x15124) - *(int *)(param_1 + 0x1511c);
  }
  local_44 = local_44 >> 2;
  if (local_44 == 0) {
    return 1;
  }
  if (*(int *)(param_1 + 0x55c) == 3) {
    uVar4 = *(uint *)(param_1 + 0x57c);
    local_54 = 0;
  }
  else {
    local_54 = 1;
    uVar4 = *(uint *)(param_1 + 0x57c) >> 1;
    if (*(int *)(param_1 + 0x55c) == 2) {
      local_50 = 1;
      goto LAB_00006078;
    }
  }
  local_50 = 0;
LAB_00006078:
  local_4c = *(undefined4 *)(param_1 + 0x568);
  if (bVar1) {
    uVar2 = 0;
  }
  else {
    uVar2 = 0x20;
  }
  local_40 = uVar2 | (*(byte *)(param_1 + 0x564) & 3) << 3 | 0x10080;
  if (bVar1) {
    local_3c = 0x8000;
  }
  else {
    local_3c = 0;
  }
  local_30 = uVar4 << 0x10 | *(uint *)(param_1 + 0x578);
  local_48 = param_2;
  iVar3 = _io_connect_method_structureI_structureO
                    (*(undefined4 *)(param_1 + 0x14),0x12,&local_54,0x38,0,&local_58);
  if (iVar3 == 0) {
    return 1;
  }
  return 0;
}

/* FUN_00006120 @ 0x6120 (252 bytes) */
undefined8 FUN_00006120(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  undefined8 uVar3;
  
  uVar3 = ((int (*)())FUN_00005fd0)();
  if (param_2 == 0) {
    _IOConnectMapMemory(*(undefined4 *)(param_1 + 0x14),4,*(undefined4 *)PTR_0000f1a0,
                        param_1 + 0x14554,param_1 + 0x14558,1);
    iVar2 = *(int *)(param_1 + 0x14554);
    iVar1 = iVar2 + 0x20;
    *(int *)(param_1 + 0x1511c) = iVar1;
    *(int *)(param_1 + 0x15124) = iVar1;
    *(int *)(param_1 + 0x15120) = *(int *)(iVar2 + 0x10) * 4 + iVar1 + -4;
    *(undefined4 *)(*(int *)(param_1 + 0xac4) * 8 + param_1 + 0xac8) = *(undefined4 *)(iVar2 + 0x18)
    ;
  }
  else {
    _IOConnectMapMemory(*(undefined4 *)(param_1 + 0x14),5,*(undefined4 *)PTR_0000f1a0,
                        param_1 + 0x1455c,param_1 + 0x14560,1);
    iVar2 = *(int *)(param_1 + 0x1455c) + 0x20;
    *(int *)(param_1 + 0x15140) = iVar2;
    *(int *)(param_1 + 0x15148) = iVar2;
    *(int *)(param_1 + 0x15144) = *(int *)(*(int *)(param_1 + 0x1455c) + 0x10) * 4 + iVar2 + -4;
  }
  return uVar3;
}

/* FUN_00006230 @ 0x6230 (2900 bytes) */
int FUN_00006230(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 *param_2;
  int param_3;
  int param_4;
{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  
  iVar8 = *(int *)(param_1 + 0x580);
  if (param_4 == 0) {
    uVar7 = *(uint *)(param_1 + 0x584);
  }
  else {
    uVar7 = *(uint *)(param_1 + 0x584) >> 1;
  }
  uVar4 = *(uint *)(param_1 + 0x58c) >> 2;
  if (param_3 == 1) {
    iVar1 = *(int *)(param_1 + 0x588);
    iVar2 = *(int *)(param_1 + 0x578);
    uVar3 = *(uint *)(param_1 + 0x57c);
    iVar10 = param_1 + 0x152b4;
    puVar5 = (undefined4 *)((int (*)())FUN_000096a0)(param_2);
    *puVar5 = 0x850;
    puVar5[1] = 0x102;
    puVar5[2] = 0x830;
    puVar5[3] = 2;
    puVar5[4] = 0x831;
    puVar5[5] = 0x1010101;
    puVar5[6] = 0x854;
    puVar5[7] = 0x26060006;
    puVar5[8] = 0x878;
    puVar5[9] = 0xf688f688;
    puVar5[10] = 0x824;
    puVar5[0xb] = 1;
    puVar5[0xc] = 0x825;
    puVar5[0xd] = 2;
    puVar5[0xe] = ((unsigned char *)0x0000101d);
    puVar5[0xf] = 0x28ffe040;
    puVar5[0x10] = ((unsigned char *)0x000010c8);
    puVar5[0x11] = 0x50;
    puVar5[0x12] = ((unsigned char *)0x000010c0);
    puVar5[0x13] = 0x40002;
    puVar5[0x14] = ((unsigned char *)0x000010c1);
    puVar5[0x15] = 0;
    puVar5[0x16] = 0x1100;
    puVar5[0x17] = 0x30000a92;
    puVar5[0x18] = 0x1101;
    puVar5[0x19] = 0x40000a92;
    puVar5[0x1a] = 0x1102;
    puVar5[0x1b] = 0x30000a92;
    puVar5[0x1c] = 0x1103;
    puVar5[0x1d] = 0x40000a92;
    puVar5[0x1e] = 0x110a;
    puVar5[0x1f] = 0x20000a92;
    puVar5[0x20] = 0x110b;
    puVar5[0x21] = 0x20000a92;
    puVar5[0x22] = 0x110c;
    puVar5[0x23] = 0x20000a92;
    puVar5[0x24] = 0x1104;
    puVar5[0x25] = 0x1492;
    puVar5[0x26] = 0x1105;
    puVar5[0x27] = 0x1492;
    puVar5[0x28] = 0x1106;
    puVar5[0x29] = 0x1492;
    puVar5[0x2a] = 0x1107;
    puVar5[0x2b] = 0x10001492;
    puVar5[0x2c] = 0x1108;
    puVar5[0x2d] = 0x10001492;
    puVar5[0x2e] = 0x1109;
    puVar5[0x2f] = 0x10001492;
    puVar5[0x30] = 0x1110;
    puVar5[0x31] = 0;
    puVar5[0x32] = 0x1111;
    puVar5[0x33] = 0;
    puVar5[0x34] = 0x1112;
    puVar5[0x35] = 0;
    puVar5[0x36] = 0x1113;
    puVar5[0x37] = 0;
    puVar5[0x38] = 0x111a;
    puVar5[0x39] = 0;
    puVar5[0x3a] = 0x111b;
    puVar5[0x3b] = 0;
    puVar5[0x3c] = 0x111c;
    puVar5[0x3d] = 0;
    puVar5[0x3e] = 0x1114;
    puVar5[0x3f] = 0x4000;
    puVar5[0x40] = 0x1115;
    puVar5[0x41] = 0x4000;
    puVar5[0x42] = 0x1116;
    puVar5[0x43] = 0x4000;
    puVar5[0x44] = 0x1117;
    puVar5[0x45] = 0x4000;
    puVar5[0x46] = 0x1118;
    puVar5[0x47] = 0x4000;
    puVar5[0x48] = 0x1119;
    puVar5[0x49] = 0x4000;
    uVar7 = (uint)(((ulonglong)uVar7 - 1 & 0xffffffff) << 0xb) | iVar8 - 1U | 0x80000000;
    puVar5[0x4a] = 0x1120;
    puVar5[0x4b] = uVar7;
    puVar5[0x4c] = 0x1121;
    puVar5[0x4d] = uVar7;
    puVar5[0x4e] = 0x1122;
    puVar5[0x4f] = uVar7;
    puVar5[0x50] = 0x1123;
    puVar5[0x51] = uVar7;
    uVar11 = iVar2 - 1;
    uVar7 = (uVar3 - 1) * 0x800 | uVar11 | 0x80000000;
    puVar5[0x52] = 0x1124;
    puVar5[0x53] = uVar7;
    puVar5[0x54] = 0x1127;
    puVar5[0x55] = uVar7;
    puVar5[0x56] = 0x112a;
    puVar5[0x57] = uVar7;
    uVar7 = uVar11 | ((uVar3 >> 1) - 1) * 0x800 | 0x80000000;
    puVar5[0x58] = 0x1125;
    puVar5[0x59] = uVar7;
    puVar5[0x5a] = 0x1126;
    puVar5[0x5b] = uVar7;
    puVar5[0x5c] = 0x1128;
    puVar5[0x5d] = uVar7;
    puVar5[0x5e] = 0x1129;
    puVar5[0x5f] = uVar7;
    puVar5[0x60] = 0x112b;
    puVar5[0x61] = uVar7;
    puVar5[0x62] = 0x112c;
    puVar5[99] = uVar7;
    puVar5[100] = 0x1130;
    puVar5[0x65] = 0x80108be4;
    puVar5[0x66] = 0x1131;
    puVar5[0x67] = 0x88108be4;
    puVar5[0x68] = 0x1132;
    puVar5[0x69] = 0x90108be4;
    puVar5[0x6a] = 0x1133;
    puVar5[0x6b] = 0x98108be4;
    puVar5[0x6c] = 0x1134;
    puVar5[0x6d] = 0xa0104000;
    puVar5[0x6e] = 0x1135;
    puVar5[0x6f] = 0xa8104000;
    puVar5[0x70] = 0x1136;
    puVar5[0x71] = 0xb0104000;
    puVar5[0x72] = 0x1137;
    puVar5[0x73] = 0xb8104000;
    puVar5[0x74] = 0x1138;
    puVar5[0x75] = 0xc0104000;
    puVar5[0x76] = 0x1139;
    puVar5[0x77] = 0xc8104000;
    puVar5[0x78] = 0x113a;
    puVar5[0x79] = 0xd0104036;
    puVar5[0x7a] = 0x113b;
    puVar5[0x7b] = 0xd8104036;
    puVar5[0x7c] = 0x113c;
    puVar5[0x7d] = 0xe0104036;
    puVar5[0x7e] = 0x1140;
    iVar8 = uVar4 - 1;
    puVar5[0x7f] = iVar8;
    puVar5[0x80] = 0x1141;
    puVar5[0x81] = iVar8;
    puVar5[0x82] = 0x1142;
    puVar5[0x83] = iVar8;
    puVar5[0x84] = 0x1143;
    puVar5[0x85] = iVar8;
    puVar5[0x86] = 0x114a;
    puVar5[0x87] = iVar1 + -1;
    puVar5[0x88] = 0x114b;
    iVar8 = iVar1 * 2 + -1;
    puVar5[0x89] = iVar8;
    puVar5[0x8a] = 0x114c;
    puVar5[0x8b] = iVar8;
    puVar5[0x8c] = 0x1180;
    puVar5[0x8d] = 0;
    puVar5[0x8e] = 0x11ad;
    puVar5[0x8f] = 0;
    puVar5[0x90] = 0x1189;
    puVar5[0x91] = 0;
    puVar5[0x92] = 0x1181;
    puVar5[0x93] = 5;
    puVar5[0x94] = 0x11a9;
    puVar5[0x95] = FUN_0000aa00;
    puVar5[0x96] = 0x11aa;
    puVar5[0x97] = 0xf;
    puVar5[0x98] = 0x11ab;
    puVar5[0x99] = 0xf;
    puVar5[0x9a] = 0x11ac;
    puVar6 = puVar5 + 0x9c;
    puVar5[0x9b] = 0xf;
  }
  else {
    uVar3 = *(uint *)(param_1 + 0x57c);
    iVar10 = param_1 + 0x15324;
    uVar11 = *(uint *)(param_1 + 0x588) >> 1;
    uVar7 = (uint)(((ulonglong)uVar7 - 1 & 0xffffffff) << 0xb) | iVar8 - 1U | 0x80000000;
    *param_2 = 0x1120;
    param_2[1] = uVar7;
    param_2[2] = 0x1121;
    param_2[3] = uVar7;
    param_2[4] = 0x1122;
    param_2[5] = uVar7;
    param_2[6] = 0x1123;
    param_2[7] = uVar7;
    uVar9 = (*(uint *)(param_1 + 0x578) >> 1) - 1;
    uVar7 = ((uVar3 >> 1) - 1) * 0x800 | uVar9 | 0x80000000;
    param_2[8] = 0x1124;
    param_2[9] = uVar7;
    param_2[10] = 0x1127;
    param_2[0xb] = uVar7;
    param_2[0xc] = 0x112a;
    param_2[0xd] = uVar7;
    uVar7 = uVar9 | ((uVar3 >> 2) - 1) * 0x800 | 0x80000000;
    param_2[0xe] = 0x1125;
    param_2[0xf] = uVar7;
    param_2[0x10] = 0x1126;
    param_2[0x11] = uVar7;
    param_2[0x12] = 0x1128;
    param_2[0x13] = uVar7;
    param_2[0x14] = 0x1129;
    param_2[0x15] = uVar7;
    param_2[0x16] = 0x112b;
    param_2[0x17] = uVar7;
    param_2[0x18] = 0x112c;
    param_2[0x19] = uVar7;
    param_2[0x1a] = 0x1130;
    param_2[0x1b] = 0x80108064;
    param_2[0x1c] = 0x1131;
    param_2[0x1d] = 0x88108064;
    param_2[0x1e] = 0x1132;
    param_2[0x1f] = 0x90108064;
    param_2[0x20] = 0x1133;
    param_2[0x21] = 0x98108064;
    param_2[0x22] = 0x1134;
    param_2[0x23] = 0xa0060003;
    param_2[0x24] = 0x1135;
    param_2[0x25] = 0xa8060003;
    param_2[0x26] = 0x1136;
    param_2[0x27] = 0xb0060003;
    param_2[0x28] = 0x1137;
    param_2[0x29] = 0xb8060003;
    param_2[0x2a] = 0x1138;
    param_2[0x2b] = 0xc0060003;
    param_2[0x2c] = 0x1139;
    param_2[0x2d] = 0xc8060003;
    param_2[0x2e] = 0x113a;
    param_2[0x2f] = 0xd0060077;
    param_2[0x30] = 0x113b;
    param_2[0x31] = 0xd8060077;
    param_2[0x32] = 0x113c;
    param_2[0x33] = 0xe0060077;
    param_2[0x34] = 0x1140;
    iVar8 = uVar4 - 1;
    param_2[0x35] = iVar8;
    param_2[0x36] = 0x1141;
    param_2[0x37] = iVar8;
    param_2[0x38] = 0x1142;
    param_2[0x39] = iVar8;
    param_2[0x3a] = 0x1143;
    param_2[0x3b] = iVar8;
    param_2[0x3c] = 0x114a;
    param_2[0x3d] = uVar11 - 1;
    param_2[0x3e] = 0x114b;
    iVar8 = uVar11 * 2 + -1;
    param_2[0x3f] = iVar8;
    param_2[0x40] = 0x114c;
    param_2[0x41] = iVar8;
    param_2[0x42] = 0x11a9;
    puVar6 = param_2 + 0x44;
    param_2[0x43] = ((unsigned char *)0x00001b00);
  }
  iVar8 = ((int (*)())FUN_00009980)(puVar6,0x10000,0x1c,iVar10);
  return iVar8 - (int)param_2 >> 2;
}

/* FUN_00006d90 @ 0x6d90 (644 bytes) */
int FUN_00006d90(param_1, param_2)
  int param_1;
  undefined8 param_2;
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  uint uVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  double dVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  undefined8 uVar16;
  undefined4 uVar17;
  undefined4 uVar18;
  
  uVar16 = FUN_0000cfa4(param_1,param_2,1,0);
  fVar6 = FLOAT_0000d458;
  fVar15 = FLOAT_0000d454;
  fVar14 = FLOAT_0000d450;
  fVar13 = FLOAT_0000d44c;
  fVar11 = FLOAT_0000d444;
  fVar10 = FLOAT_0000d43c;
  dVar9 = DOUBLE_0000d418;
  uVar5 = (*(uint *)(param_1 + 0x57c) >> 1) + 0xf & 0xfffffff0;
  *(float *)(param_1 + 0x152cc) = FLOAT_0000d43c;
  *(float *)(param_1 + 0x152d0) = fVar10;
  fVar12 = FLOAT_0000d448;
  *(float *)(param_1 + 0x152b4) = FLOAT_0000d448;
  *(float *)(param_1 + 0x152b8) = fVar12;
  *(undefined4 *)(param_1 + 0x152dc) = 0;
  *(undefined4 *)(param_1 + 0x152e0) = 0;
  *(float *)(param_1 + 0x152bc) = fVar12;
  *(float *)(param_1 + 0x152c0) = fVar12;
  *(float *)(param_1 + 0x152ec) = fVar10;
  *(float *)(param_1 + 0x152f0) = fVar10;
  fVar1 = (float)((double)CONCAT44(0x43300000,*(undefined4 *)(param_1 + 0x578)) - dVar9);
  fVar8 = fVar6 / fVar1;
  fVar3 = fVar15 / (fVar1 * fVar14);
  *(undefined4 *)(param_1 + 0x152fc) = 0;
  fVar4 = fVar15 / (fVar1 * fVar11);
  *(undefined4 *)(param_1 + 0x15300) = 0;
  fVar2 = (float)((double)CONCAT44(0x43300000,*(uint *)(param_1 + 0x57c)) - dVar9);
  *(undefined4 *)(param_1 + 0x1530c) = 0;
  *(undefined4 *)(param_1 + 0x15310) = 0;
  *(float *)(param_1 + 0x15330) = fVar12;
  *(float *)(param_1 + 0x15360) = fVar10;
  *(float *)(param_1 + 0x15384) = fVar8;
  *(float *)(param_1 + 0x152f4) = fVar3;
  *(float *)(param_1 + 0x152d4) = fVar3;
  fVar6 = fVar6 / fVar2;
  fVar7 = fVar13 / (fVar1 + fVar1);
  *(float *)(param_1 + 0x15364) = fVar4;
  fVar3 = (float)((double)CONCAT44(0x43300000,uVar5) - dVar9);
  *(float *)(param_1 + 0x15378) = fVar6;
  *(float *)(param_1 + 0x15318) = fVar6;
  *(float *)(param_1 + 0x152e4) = fVar7;
  *(float *)(param_1 + 0x152c4) = fVar7;
  *(float *)(param_1 + 0x152c8) = fVar13 / (fVar2 + fVar2);
  *(float *)(param_1 + 0x152d8) = fVar15 / (fVar2 * fVar14);
  *(float *)(param_1 + 0x15368) = fVar15 / (fVar3 * fVar11);
  *(float *)(param_1 + 0x15304) = fVar10 / fVar1;
  *(float *)(param_1 + 0x15314) = fVar10 / fVar1;
  *(float *)(param_1 + 0x152e8) = fVar13 / (fVar3 + fVar3);
  *(float *)(param_1 + 0x152f8) = fVar15 / (fVar3 * fVar14);
  *(float *)(param_1 + 0x15358) = fVar13 / fVar3;
  *(float *)(param_1 + 0x15388) = fVar11 / fVar2;
  *(float *)(param_1 + 0x15348) = fVar15 / (fVar2 * fVar11);
  *(undefined4 *)(param_1 + 0x1531c) = 0;
  *(undefined4 *)(param_1 + 0x15320) = 0;
  *(undefined4 *)(param_1 + 0x1534c) = 0;
  *(undefined4 *)(param_1 + 0x15350) = 0;
  *(undefined4 *)(param_1 + 0x1536c) = 0;
  *(undefined4 *)(param_1 + 0x15370) = 0;
  *(undefined4 *)(param_1 + 0x1537c) = 0;
  *(undefined4 *)(param_1 + 0x15380) = 0;
  *(undefined4 *)(param_1 + 0x1538c) = 0;
  *(undefined4 *)(param_1 + 0x15390) = 0;
  *(float *)(param_1 + 0x15324) = fVar12;
  *(float *)(param_1 + 0x15328) = fVar12;
  *(float *)(param_1 + 0x1532c) = fVar12;
  *(float *)(param_1 + 0x1533c) = fVar10;
  *(float *)(param_1 + 0x15340) = fVar10;
  *(float *)(param_1 + 0x1535c) = fVar10;
  *(float *)(param_1 + 0x15354) = fVar13 / fVar1;
  *(float *)(param_1 + 0x15308) = fVar10 / fVar2;
  *(float *)(param_1 + 0x15334) = fVar13 / fVar1;
  *(float *)(param_1 + 0x15344) = fVar4;
  *(float *)(param_1 + 0x15374) = fVar8;
  *(float *)(param_1 + 0x15338) = fVar13 / fVar2;
  uVar17 = ((int (*)())FUN_00006230)(uVar16,*(undefined4 *)(param_1 + 0x15294));
  *(undefined4 *)(param_1 + 0x15298) = uVar17;
  uVar18 = ((int (*)())FUN_00006230)(param_1,*(undefined4 *)(param_1 + 0x1529c),2,0);
  uVar17 = *(undefined4 *)(param_1 + 0x57c);
  *(uint *)(param_1 + 0x57c) = uVar5 << 1;
  *(undefined4 *)(param_1 + 0x152a0) = uVar18;
  uVar18 = ((int (*)())FUN_00006230)(param_1,*(undefined4 *)(param_1 + 0x152a4),1,1);
  *(undefined4 *)(param_1 + 0x152a8) = uVar18;
  uVar18 = ((int (*)())FUN_00006230)(param_1,*(undefined4 *)(param_1 + 0x152ac),2,1);
  *(undefined4 *)(param_1 + 0x57c) = uVar17;
  *(undefined4 *)(param_1 + 0x152b0) = uVar18;
  return;
}

/* FUN_00007020 @ 0x7020 (592 bytes) */
int FUN_00007020(param_1, param_2, param_3)
  int param_1;
  undefined4 *param_2;
  int param_3;
{
  uint uVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  longlong lVar5;
  
  if (param_3 == 1) {
    iVar4 = *(int *)(param_1 + 0x588);
    if (*(int *)(param_1 + 0x55c) == 3) {
      _memcpy(param_2,*(void **)(param_1 + 0x15294),*(int *)(param_1 + 0x15298) << 2);
      iVar3 = *(int *)(param_1 + 0x15298);
    }
    else {
      _memcpy(param_2,*(void **)(param_1 + 0x152a4),*(int *)(param_1 + 0x152a8) << 2);
      iVar3 = *(int *)(param_1 + 0x152a8);
    }
    param_2 = param_2 + iVar3;
    *param_2 = 0x1144;
    iVar3 = iVar4 + -1;
    param_2[1] = iVar3;
    param_2[2] = 0x1147;
    param_2[3] = iVar3;
    param_2[4] = 0x1145;
    iVar4 = iVar4 * 2 + -1;
    param_2[5] = iVar4;
    param_2[6] = 0x1146;
    param_2[7] = iVar4;
    param_2[8] = 0x1148;
    param_2[9] = iVar4;
    param_2[10] = 0x1149;
    param_2[0xb] = iVar4;
    param_2 = param_2 + 0xc;
    lVar5 = 0x1e;
    do {
      *param_2 = 0x80000000;
      param_2 = param_2 + 1;
      lVar5 = lVar5 + -1;
    } while (lVar5 != 0);
  }
  else {
    *param_2 = ((unsigned char *)0x00001040);
    puVar2 = param_2 + 2;
    param_2[1] = 0;
    uVar1 = *(uint *)(param_1 + 0x588) >> 1;
    if (*(int *)(param_1 + 0x55c) == 3) {
      _memcpy(puVar2,*(void **)(param_1 + 0x1529c),*(int *)(param_1 + 0x152a0) << 2);
      iVar4 = *(int *)(param_1 + 0x152a0);
    }
    else {
      _memcpy(puVar2,*(void **)(param_1 + 0x152ac),*(int *)(param_1 + 0x152b0) << 2);
      iVar4 = *(int *)(param_1 + 0x152b0);
    }
    puVar2 = puVar2 + iVar4;
    *puVar2 = 0x1144;
    iVar4 = uVar1 - 1;
    puVar2[1] = iVar4;
    puVar2[2] = 0x1147;
    puVar2[3] = iVar4;
    puVar2[4] = 0x1145;
    iVar4 = uVar1 * 2 + -1;
    puVar2[5] = iVar4;
    puVar2[6] = 0x1146;
    puVar2[7] = iVar4;
    puVar2[8] = 0x1148;
    puVar2[9] = iVar4;
    puVar2[10] = 0x1149;
    puVar2[0xb] = iVar4;
    puVar2 = puVar2 + 0xc;
    lVar5 = 0x1e;
    do {
      *puVar2 = 0x80000000;
      puVar2 = puVar2 + 1;
      lVar5 = lVar5 + -1;
    } while (lVar5 != 0);
  }
  return;
}

/* FUN_00007270 @ 0x7270 (544 bytes) */
int FUN_00007270(param_1, param_2, param_3)
  undefined8 param_1;
  int *param_2;
  int param_3;
{
  undefined4 *puVar1;
  undefined *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint auStack_3f8 [254];
  
  puVar2 = &UNK_0000d5c4;
  iVar5 = (param_2[1] - *param_2) + 1;
  _memcpy(auStack_3f8,&UNK_0000d5c4 + *param_2 * 0x18,iVar5 * 0x18);
  iVar4 = (param_2[7] - param_2[6]) + 1;
  iVar3 = iVar5 + iVar4;
  _memcpy(auStack_3f8 + iVar5 * 6,&UNK_0000d4ec + param_2[6] * 0x18,iVar4 * 0x18);
  iVar4 = iVar3 + -1;
  auStack_3f8[iVar5 * 6] = auStack_3f8[iVar5 * 6] | 0x400;
  auStack_3f8[iVar4 * 6] = auStack_3f8[iVar4 * 6] | 4;
  auStack_3f8[iVar4 * 6 + 1] = auStack_3f8[iVar4 * 6 + 1] | 0x2000000;
  iVar4 = (param_2[5] - param_2[4]) + 1;
  iVar6 = iVar3 + iVar4;
  _memcpy(auStack_3f8 + iVar3 * 6,&UNK_0000d5c4 + param_2[4] * 0x18,iVar4 * 0x18);
  iVar4 = param_2[10];
  iVar5 = param_2[0xb];
  auStack_3f8[iVar3 * 6] = auStack_3f8[iVar3 * 6] | 4;
  iVar5 = (iVar5 - iVar4) + 1;
  iVar3 = iVar6 + iVar5;
  _memcpy(auStack_3f8 + iVar6 * 6,&UNK_0000d4ec + iVar4 * 0x18,iVar5 * 0x18);
  iVar4 = iVar3 + -1;
  auStack_3f8[iVar6 * 6] = auStack_3f8[iVar6 * 6] | 0x400;
  auStack_3f8[iVar4 * 6] = auStack_3f8[iVar4 * 6] | 4;
  auStack_3f8[iVar4 * 6 + 1] = auStack_3f8[iVar4 * 6 + 1] | 0x2000000;
  if (param_3 == 2) {
    puVar2 = &UNK_0000d474;
  }
  iVar5 = (param_2[9] - param_2[8]) + 1;
  iVar6 = iVar3 + iVar5;
  iVar4 = iVar6 + -1;
  _memcpy(auStack_3f8 + iVar3 * 6,puVar2 + param_2[8] * 0x18,iVar5 * 0x18);
  auStack_3f8[iVar3 * 6] = auStack_3f8[iVar3 * 6] | 4;
  auStack_3f8[iVar4 * 6] = auStack_3f8[iVar4 * 6] | 0x100;
  puVar1 = (undefined4 *)((int (*)())FUN_00009980)(param_1,0,(uint)(iVar6 * 0x18) >> 2,auStack_3f8);
  *puVar1 = 0x118e;
  puVar1[1] = 0;
  puVar1[2] = 0x118c;
  puVar1[3] = iVar4 * 0x10000;
  puVar1[4] = 0x118d;
  puVar1[5] = iVar4 * 0x10000;
  return puVar1 + 6;
}

/* FUN_00007490 @ 0x7490 (696 bytes) */
int FUN_00007490(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  uint param_2;
  ulonglong param_3;
  undefined4 *param_4;
  int param_5;
  int param_6;
{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  uint uVar5;
  undefined *puVar6;
  uint uVar7;
  
  if (param_5 == 0) {
    if (*(int *)(param_1 + 0x55c) == 3) {
      puVar6 = &UNK_0000dd00 + param_2 * 0x34;
    }
    else {
      puVar6 = &UNK_0000d7ec + param_2 * 0x34;
    }
  }
  else if (*(int *)(param_1 + 0x55c) == 3) {
    puVar6 = &UNK_0000e658 + param_2 * 0x34;
  }
  else {
    puVar6 = &UNK_0000e144 + param_2 * 0x34;
  }
  if (param_6 != 1) {
    iVar1 = *(int *)(param_1 + 0x55c);
    if ((iVar1 == 3) && (param_2 < 3)) {
      uVar7 = *(uint *)(param_1 + 0x588) >> 1;
    }
    else {
      uVar7 = *(uint *)(param_1 + 0x588);
    }
    puVar4 = *(undefined4 **)(param_1 + 0x1517c);
  }
  else {
    iVar1 = *(int *)(param_1 + 0x55c);
    if ((iVar1 == 3) && (param_2 < 3)) {
      uVar7 = *(uint *)(param_1 + 0x588);
    }
    else {
      uVar7 = *(int *)(param_1 + 0x588) << 1;
    }
    puVar4 = *(undefined4 **)(param_1 + 0x15174);
  }
  if (iVar1 == 3) {
    if ((((param_2 - 5 < 2) || (param_2 == 9)) || (param_2 == 10)) ||
       (((param_2 == 0xf || (param_2 == 0x10)) ||
        ((param_2 == 0x11 || (uVar5 = 0, param_2 == 0x12)))))) {
      uVar5 = 1;
    }
  }
  else {
    uVar5 = (uint)(iVar1 == 2);
  }
  *puVar4 = 0x1393;
  puVar4[1] = 10;
  puVar4[2] = 0x5c8;
  puVar4[3] = 0x20000;
  puVar4[4] = ((unsigned char *)0x00001040);
  puVar4[5] = 0;
  puVar3 = (undefined4 *)((int (*)())FUN_00007270)(puVar4 + 6,puVar6);
  *puVar3 = ((unsigned char *)0x00001041);
  puVar3[1] = *(undefined4 *)(puVar6 + 0x30);
  puVar3[2] = (uint)((param_3 + 5 & 0xffffffff) << 0x10) | 0xc0003a00;
  puVar3[3] = 0xc0000;
  *(int *)(param_1 + 0x15188) = (int)(puVar3 + 4) - (int)puVar4 >> 2;
  puVar3[4] = uVar5;
  puVar3[5] = uVar7;
  puVar3[6] = (uint)((param_3 & 0xffffffff) << 0x12) | 0x81d;
  puVar4 = puVar3 + 8;
  puVar3[7] = (int)param_3;
  if ((int)param_3 != 0) {
    do {
      uVar2 = *param_4;
      param_4 = param_4 + 1;
      *puVar4 = uVar2;
      puVar4 = puVar4 + 1;
      param_3 = param_3 - 1;
    } while (param_3 != 0);
  }
  *puVar4 = 0xdeadbeef;
  puVar4[1] = 0x1393;
  puVar4[2] = 10;
  if (param_6 != 1) {
    *(undefined4 **)(param_1 + 0x1517c) = puVar4 + 3;
  }
  else {
    *(undefined4 **)(param_1 + 0x15174) = puVar4 + 3;
  }
  return;
}

/* FUN_00007850 @ 0x7850 (1416 bytes) */
int FUN_00007850(param_1, param_2)
  int param_1;
  int param_2;
{
  uint *puVar1;
  uint uVar2;
  int *piVar3;
  uint uVar4;
  undefined *puVar5;
  int iVar6;
  longlong lVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  int iVar12;
  longlong lVar13;
  int iVar14;
  
  puVar9 = *(undefined4 **)(param_1 + 0x34);
  if (*(undefined4 **)(param_1 + 0x38) <= puVar9 + 0xe) {
    puVar1 = *(uint **)(param_1 + 0x30);
    *puVar1 = (int)puVar9 - (int)puVar1 >> 2 | *puVar1;
    puVar5 = PTR_0000f1a0;
    *(undefined4 **)(param_1 + 0x30) = *(undefined4 **)(param_1 + 0x34);
    **(undefined4 **)(param_1 + 0x34) = 0x1000000;
    _IOConnectMapMemory(*(undefined4 *)(param_1 + 0x14),1,*(undefined4 *)puVar5,param_1 + 0x40,
                        param_1 + 0x44,1);
    iVar6 = *(int *)(param_1 + 0x40);
    *(int *)(param_1 + 0x34) = iVar6 + 0x20;
    *(int *)(param_1 + 0x30) = iVar6 + 0x1c;
    *(int *)(param_1 + 0x38) = iVar6 + 0x20 + *(int *)(iVar6 + 0x10) * 4;
    *(undefined4 *)(iVar6 + 0x1c) = 0;
    puVar9 = *(undefined4 **)(param_1 + 0x34);
  }
  puVar1 = *(uint **)(param_1 + 0x30);
  *(undefined4 **)(param_1 + 0x34) = puVar9 + 0xe;
  *puVar1 = (int)puVar9 - (int)puVar1 >> 2 | *puVar1;
  *(undefined4 **)(param_1 + 0x30) = puVar9;
  *puVar9 = 0x12000000;
  puVar9[1] = 0;
  if (*(char *)(param_1 + 0x574) == '\0') {
    puVar9[2] = 0;
  }
  else {
    puVar9[2] = 1;
  }
  iVar6 = *(int *)(param_1 + 0x55c);
  if (iVar6 == 2) {
    puVar9[3] = 1;
  }
  else {
    puVar9[3] = 0;
    if (iVar6 == 3) {
      puVar9[4] = 0;
      goto LAB_00007998;
    }
  }
  puVar9[4] = 1;
LAB_00007998:
  puVar9[5] = 1;
  puVar9[6] = -0x80000000;
  puVar9[7] = -0x80000000;
  puVar9[8] = *(undefined4 *)(param_1 + 0x15400);
  puVar9[9] = *(undefined4 *)(param_1 + 0x568);
  puVar9[10] = *(undefined4 *)(param_1 + 0x56c);
  puVar9[0xb] = *(undefined4 *)(param_1 + 0x570);
  if (*(int *)(param_1 + 0x560) == 3) {
    puVar9[0xc] = 1;
  }
  else {
    puVar9[0xc] = 0;
  }
  puVar9[0xd] = 1;
  puVar10 = *(undefined4 **)(param_1 + 0x34);
  puVar8 = *(undefined4 **)(param_1 + 0x38);
  if (puVar8 <= puVar10 + 2) {
    puVar1 = *(uint **)(param_1 + 0x30);
    *puVar1 = (int)puVar10 - (int)puVar1 >> 2 | *puVar1;
    puVar5 = PTR_0000f1a0;
    *(undefined4 **)(param_1 + 0x30) = *(undefined4 **)(param_1 + 0x34);
    **(undefined4 **)(param_1 + 0x34) = 0x1000000;
    _IOConnectMapMemory(*(undefined4 *)(param_1 + 0x14),1,*(undefined4 *)puVar5,param_1 + 0x40,
                        param_1 + 0x44,1);
    iVar6 = *(int *)(param_1 + 0x40);
    *(int *)(param_1 + 0x34) = iVar6 + 0x20;
    *(int *)(param_1 + 0x30) = iVar6 + 0x1c;
    *(int *)(param_1 + 0x38) = iVar6 + 0x20 + *(int *)(iVar6 + 0x10) * 4;
    *(undefined4 *)(iVar6 + 0x1c) = 0;
    puVar10 = *(undefined4 **)(param_1 + 0x34);
    puVar8 = *(undefined4 **)(param_1 + 0x38);
  }
  puVar11 = puVar10 + 2;
  *(undefined4 **)(param_1 + 0x34) = puVar11;
  *puVar10 = 0x80000000;
  puVar10[1] = 0x80000000;
  if (puVar8 <= puVar11 + param_2) {
    puVar1 = *(uint **)(param_1 + 0x30);
    *puVar1 = (int)puVar11 - (int)puVar1 >> 2 | *puVar1;
    puVar5 = PTR_0000f1a0;
    *(undefined4 **)(param_1 + 0x30) = *(undefined4 **)(param_1 + 0x34);
    **(undefined4 **)(param_1 + 0x34) = 0x1000000;
    _IOConnectMapMemory(*(undefined4 *)(param_1 + 0x14),1,*(undefined4 *)puVar5,param_1 + 0x40,
                        param_1 + 0x44,1);
    iVar6 = *(int *)(param_1 + 0x40);
    *(int *)(param_1 + 0x34) = iVar6 + 0x20;
    *(int *)(param_1 + 0x30) = iVar6 + 0x1c;
    *(int *)(param_1 + 0x38) = iVar6 + 0x20 + *(int *)(iVar6 + 0x10) * 4;
    *(undefined4 *)(iVar6 + 0x1c) = 0;
    puVar11 = *(undefined4 **)(param_1 + 0x34);
  }
  *(undefined4 **)(param_1 + 0x34) = puVar11 + param_2;
  *(undefined4 **)(param_1 + 0x15164) = puVar11;
  *(undefined4 **)(param_1 + 0x1516c) = puVar11;
  *(undefined4 **)(param_1 + 0x15170) = puVar11;
  *(undefined4 **)(param_1 + 0x15168) = puVar11 + param_2 + -1;
  iVar6 = ((int (*)())FUN_00007020)(param_1,puVar11,1);
  uVar2 = *(uint *)(param_1 + 0x15164);
  *(int *)(param_1 + 0x15174) = iVar6;
  puVar9[6] = (int)(iVar6 - uVar2) >> 2;
  iVar6 = *(int *)(param_1 + 0x15168) - iVar6;
  uVar4 = iVar6 >> 2;
  lVar7 = (ulonglong)uVar2 +
          ((longlong)(iVar6 >> 3) + (ulonglong)((int)uVar4 < 0 && (uVar4 & 1) != 0) & 0x3fffffff) *
          4;
  *(int *)(param_1 + 0x15178) = (int)lVar7;
  iVar6 = ((int (*)())FUN_00007020)(param_1,lVar7,2);
  *(int *)(param_1 + 0x1517c) = iVar6;
  puVar9[7] = iVar6 - *(int *)(param_1 + 0x15164) >> 2;
  lVar7 = 0;
  iVar12 = param_1 + 0x14428;
  iVar6 = 0;
  do {
    iVar14 = iVar12 + iVar6;
    lVar13 = ((ulonglong)*(uint *)(param_1 + 0x14424) - (ulonglong)*(uint *)(iVar12 + iVar6)) + -1;
    if (lVar13 != 0) {
      piVar3 = *(int **)(param_1 + 0x15174);
      *(int **)(param_1 + 0x15174) = piVar3 + 2;
      ((int (*)())FUN_00007490)(param_1,lVar7,lVar13,
                   ((ulonglong)*(uint *)(iVar12 + iVar6) & 0x3fffffff) * 4 +
                   (ulonglong)*(uint *)(iVar14 + 8) + 4,1,1);
      *piVar3 = (*(int *)(param_1 + 0x15174) - (int)piVar3 >> 2) + -2;
      piVar3[1] = *(int *)(param_1 + 0x15188);
      piVar3 = *(int **)(param_1 + 0x1517c);
      *(int **)(param_1 + 0x1517c) = piVar3 + 2;
      ((int (*)())FUN_00007490)(param_1,lVar7,lVar13,
                   ((ulonglong)*(uint *)(iVar12 + iVar6) & 0x3fffffff) * 4 +
                   (ulonglong)*(uint *)(iVar14 + 8) + 4,1,2);
      *piVar3 = (*(int *)(param_1 + 0x1517c) - (int)piVar3 >> 2) + -2;
      piVar3[1] = *(int *)(param_1 + 0x15188);
    }
    if (*(int *)(iVar14 + 4) != 0) {
      piVar3 = *(int **)(param_1 + 0x15174);
      *(int **)(param_1 + 0x15174) = piVar3 + 2;
      ((int (*)())FUN_00007490)(param_1,lVar7,*(undefined4 *)(iVar14 + 4),*(undefined4 *)(iVar14 + 8),0,1);
      *piVar3 = (*(int *)(param_1 + 0x15174) - (int)piVar3 >> 2) + -2;
      piVar3[1] = *(int *)(param_1 + 0x15188);
      piVar3 = *(int **)(param_1 + 0x1517c);
      *(int **)(param_1 + 0x1517c) = piVar3 + 2;
      ((int (*)())FUN_00007490)(param_1,lVar7,*(undefined4 *)(iVar14 + 4),*(undefined4 *)(iVar14 + 8),0,2);
      *piVar3 = (*(int *)(param_1 + 0x1517c) - (int)piVar3 >> 2) + -2;
      piVar3[1] = *(int *)(param_1 + 0x15188);
    }
    iVar14 = (int)lVar7;
    iVar6 = iVar6 + 0xc;
    lVar7 = lVar7 + 1;
  } while (iVar14 != 0x18);
  puVar9 = *(undefined4 **)(param_1 + 0x15174);
  *(undefined4 **)(param_1 + 0x15174) = puVar9 + 1;
  *puVar9 = 0;
  puVar9 = *(undefined4 **)(param_1 + 0x1517c);
  *(undefined4 **)(param_1 + 0x1517c) = puVar9 + 1;
  *puVar9 = 0;
  return;
}

/* FUN_00007de0 @ 0x7de0 (416 bytes) */
int FUN_00007de0(param_1)
  int param_1;
{
  uint *puVar1;
  int iVar2;
  longlong lVar3;
  uint uVar4;
  undefined4 *puVar5;
  
  puVar5 = *(undefined4 **)(param_1 + 0x10);
  uVar4 = *(int *)(param_1 + 0x14) - (int)puVar5 >> 2;
  if (0x4001 < uVar4) {
    lVar3 = (ulonglong)(uVar4 - 0x4002) / 0x4001 + 1;
    if (uVar4 == 0x4001) {
      lVar3 = 1;
    }
    do {
      *puVar5 = 0xffff1000;
      uVar4 = uVar4 - 0x4001;
      puVar5 = puVar5 + 0x4001;
      lVar3 = lVar3 + -1;
    } while (lVar3 != 0);
    *(undefined4 **)(param_1 + 0x10) = puVar5;
  }
  if (uVar4 != 0) {
    if (uVar4 < 2) {
      puVar5 = *(undefined4 **)(param_1 + 0x10);
      *(undefined4 **)(param_1 + 0x10) = puVar5 + 1;
      *puVar5 = 0x80000000;
    }
    else {
      puVar1 = *(uint **)(param_1 + 0x10);
      *(uint **)(param_1 + 0x10) = puVar1 + 1;
      *puVar1 = (uVar4 - 2) * 0x10000 | 0xc0001000;
    }
  }
  puVar5 = *(undefined4 **)(param_1 + 0x18);
  iVar2 = *(int *)(param_1 + 4) - (int)puVar5 >> 2;
  uVar4 = iVar2 + 1;
  if (0x4001 < uVar4) {
    lVar3 = (ulonglong)(iVar2 - 0x4001) / 0x4001 + 1;
    if (iVar2 == 0x4000) {
      lVar3 = 1;
    }
    do {
      *puVar5 = 0xffff1000;
      uVar4 = uVar4 - 0x4001;
      puVar5 = puVar5 + 0x4001;
      lVar3 = lVar3 + -1;
    } while (lVar3 != 0);
    *(undefined4 **)(param_1 + 0x18) = puVar5;
  }
  if (uVar4 == 0) {
    return;
  }
  if (1 < uVar4) {
    puVar1 = *(uint **)(param_1 + 0x18);
    *(uint **)(param_1 + 0x18) = puVar1 + 1;
    *puVar1 = (uVar4 - 2) * 0x10000 | 0xc0001000;
    return;
  }
  puVar5 = *(undefined4 **)(param_1 + 0x18);
  *(undefined4 **)(param_1 + 0x18) = puVar5 + 1;
  *puVar5 = 0x80000000;
  return;
}

/* FUN_00007f80 @ 0x7f80 (1072 bytes) */
int FUN_00007f80(param_1)
  int param_1;
{
  bool bVar1;
  uint *puVar2;
  int *piVar3;
  undefined *puVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  int *piVar10;
  longlong lVar11;
  int *piVar12;
  
  piVar10 = (int *)(param_1 + 0x55c);
  iVar5 = *(int *)(param_1 + 0x568);
  if (*(int *)(param_1 + 0x560) == 1) {
    if (*(int *)(param_1 + 0x15124) == *(int *)(param_1 + 0x1511c)) {
      return;
    }
    iVar5 = ((int (*)())FUN_00006120)(param_1,0);
    if (iVar5 != 0) {
      return;
    }
    piVar10[*(int *)(param_1 + 0x568) + 0x14b] = 1;
    return;
  }
  if ((((*(int *)(param_1 + 0x55c) == 3) || (*(char *)(param_1 + 0x574) != '\0')) &&
      (*(int *)(param_1 + 0x15124) != *(int *)(param_1 + 0x1511c))) &&
     (iVar6 = ((int (*)())FUN_00006120)(param_1,0), iVar6 == 0)) {
    piVar10[*(int *)(param_1 + 0x568) + 0x14b] = 1;
  }
  if (*(int *)(param_1 + 0x15148) == *(int *)(param_1 + 0x15140)) {
    puVar9 = *(undefined4 **)(param_1 + 0x34);
    puVar7 = *(undefined4 **)(param_1 + 0x38);
  }
  else {
    iVar6 = ((int (*)())FUN_00006120)(param_1,1);
    if (iVar6 == 0) {
      iVar5 = *(int *)(param_1 + 0x15164);
      piVar10[*(int *)(param_1 + 0x568) + 0x14b] = 1;
      *(undefined4 *)(iVar5 + -0xc) = 0;
      goto LAB_000082e0;
    }
    iVar6 = *(int *)(param_1 + 0x15164);
    *(undefined4 *)(iVar6 + -8) = 0x5c8;
    *(undefined4 *)(iVar6 + -4) = 0x8000000;
    puVar4 = PTR_0000f1a0;
    puVar8 = *(undefined4 **)(param_1 + 0x34);
    puVar7 = *(undefined4 **)(param_1 + 0x38);
    if (puVar7 <= puVar8 + 2) {
      puVar2 = *(uint **)(param_1 + 0x30);
      *puVar2 = (int)puVar8 - (int)puVar2 >> 2 | *puVar2;
      *(undefined4 **)(param_1 + 0x30) = *(undefined4 **)(param_1 + 0x34);
      **(undefined4 **)(param_1 + 0x34) = 0x1000000;
      _IOConnectMapMemory(*(undefined4 *)(param_1 + 0x14),1,*(undefined4 *)puVar4,param_1 + 0x40,
                          param_1 + 0x44,1);
      iVar6 = *(int *)(param_1 + 0x40);
      *(int *)(param_1 + 0x34) = iVar6 + 0x20;
      *(int *)(param_1 + 0x30) = iVar6 + 0x1c;
      *(int *)(param_1 + 0x38) = iVar6 + 0x20 + *(int *)(iVar6 + 0x10) * 4;
      *(undefined4 *)(iVar6 + 0x1c) = 0;
      puVar8 = *(undefined4 **)(param_1 + 0x34);
      puVar7 = *(undefined4 **)(param_1 + 0x38);
    }
    puVar9 = puVar8 + 2;
    *(undefined4 **)(param_1 + 0x34) = puVar9;
    *puVar8 = 0x7eb;
    puVar8[1] = 0x4000;
  }
  puVar4 = PTR_0000f1a0;
  if (puVar7 <= puVar9 + 4) {
    puVar2 = *(uint **)(param_1 + 0x30);
    *puVar2 = (int)puVar9 - (int)puVar2 >> 2 | *puVar2;
    *(undefined4 **)(param_1 + 0x30) = *(undefined4 **)(param_1 + 0x34);
    **(undefined4 **)(param_1 + 0x34) = 0x1000000;
    _IOConnectMapMemory(*(undefined4 *)(param_1 + 0x14),1,*(undefined4 *)puVar4,param_1 + 0x40,
                        param_1 + 0x44,1);
    iVar6 = *(int *)(param_1 + 0x40);
    *(int *)(param_1 + 0x34) = iVar6 + 0x20;
    *(int *)(param_1 + 0x30) = iVar6 + 0x1c;
    *(int *)(param_1 + 0x38) = iVar6 + 0x20 + *(int *)(iVar6 + 0x10) * 4;
    *(undefined4 *)(iVar6 + 0x1c) = 0;
    puVar9 = *(undefined4 **)(param_1 + 0x34);
  }
  *(undefined4 **)(param_1 + 0x34) = puVar9 + 4;
  *puVar9 = 0x1393;
  puVar9[1] = 10;
  puVar9[2] = 0x5c8;
  puVar9[3] = 0x20000;
  iVar6 = 0;
  ((int (*)())FUN_00007de0)(param_1 + 0x15164);
  lVar11 = (longlong)(int)(*(uint *)(param_1 + 0x57c) >> 4) * (longlong)*(int *)(param_1 + 0x151a4);
  piVar12 = piVar10 + iVar5 * 4 + 0x5326;
  do {
    ((int (*)())FUN_0000bf20)(param_1,*piVar12,lVar11);
    piVar3 = piVar12 + 0x14;
    piVar12 = piVar12 + 1;
    ((int (*)())FUN_0000bf20)(param_1,*piVar3,lVar11);
    bVar1 = iVar6 != 3;
    iVar6 = iVar6 + 1;
  } while (bVar1);
LAB_000082e0:
  puVar4 = PTR_0000f1a0;
  puVar2 = *(uint **)(param_1 + 0x30);
  *puVar2 = *(int *)(param_1 + 0x34) - (int)puVar2 >> 2 | *puVar2;
  *(undefined4 **)(param_1 + 0x30) = *(undefined4 **)(param_1 + 0x34);
  **(undefined4 **)(param_1 + 0x34) = 0x1000000;
  _IOConnectMapMemory(*(undefined4 *)(param_1 + 0x14),1,*(undefined4 *)puVar4,param_1 + 0x40,
                      param_1 + 0x44,1);
  iVar5 = *(int *)(param_1 + 0x40);
  *(int *)(param_1 + 0x34) = iVar5 + 0x20;
  *(int *)(param_1 + 0x30) = iVar5 + 0x1c;
  *(int *)(param_1 + 0x38) = iVar5 + 0x20 + *(int *)(iVar5 + 0x10) * 4;
  *(undefined4 *)(iVar5 + 0x1c) = 0;
  piVar10[*(int *)(param_1 + 0xac4) * 2 + 0x15c] = *(int *)(*(int *)(param_1 + 0x40) + 0x18);
  if (((*piVar10 != 3) && (*(char *)(param_1 + 0x574) == '\0')) &&
     (*(int *)(param_1 + 0x15124) != *(int *)(param_1 + 0x1511c))) {
    ((int (*)())FUN_00006120)(param_1,0);
    return;
  }
  return;
}

/* FUN_000083e0 @ 0x83e0 (300 bytes) */
int FUN_000083e0(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  uint *puVar1;
  uint uVar2;
  ulonglong uVar3;
  longlong lVar4;
  undefined4 *puVar5;
  longlong lVar6;
  int iVar7;
  longlong lVar8;
  
  if (param_3 != 0) {
    iVar7 = param_1 + 0x15140;
  }
  else {
    iVar7 = param_1 + 0x1511c;
  }
  uVar2 = *(int *)(iVar7 + 8) + param_2 * 4;
  if (*(uint *)(iVar7 + 4) < uVar2) {
    if (param_3 != 0) {
      uVar3 = 0;
      lVar6 = 0;
      lVar4 = 0x19;
      puVar1 = (uint *)(param_1 + 0x1442c);
      do {
        if (*puVar1 != 0) {
          lVar6 = lVar6 + (ulonglong)*puVar1;
          uVar3 = uVar3 + 1;
        }
        lVar8 = ((ulonglong)*(uint *)(param_1 + 0x14424) - (ulonglong)puVar1[-1]) + -1;
        if (lVar8 != 0) {
          uVar3 = uVar3 + 1;
          lVar6 = lVar6 + lVar8;
        }
        lVar4 = lVar4 + -1;
        puVar1 = puVar1 + 3;
      } while (lVar4 != 0);
      ((int (*)())FUN_00007850)(param_1,(lVar6 + (uVar3 & 0x1ffffff) * 0x80 & 0x7fffffff) * 2 + 1000);
      ((int (*)())FUN_00007f80)(param_1);
      puVar5 = (undefined4 *)(param_1 + 0x1442c);
      lVar4 = 0x19;
      do {
        *puVar5 = 0;
        puVar5[-1] = *(int *)(param_1 + 0x14424) + -1;
        puVar5 = puVar5 + 3;
        lVar4 = lVar4 + -1;
      } while (lVar4 != 0);
    }
    else {
      ((int (*)())FUN_00006120)(param_1,0);
    }
    uVar2 = param_2 * 4 + *(int *)(iVar7 + 8);
  }
  *(uint *)(iVar7 + 8) = uVar2;
  return;
}

/* FUN_00008510 @ 0x8510 (372 bytes) */
int FUN_00008510(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int param_2;
  undefined4 *param_3;
  uint param_4;
  undefined8 param_5;
{
  byte *pbVar1;
  int iVar3;
  ulonglong uVar2;
  uint *puVar4;
  uint *puVar5;
  longlong lVar6;
  uint uVar7;
  uint *puVar8;
  longlong lVar9;
  
  lVar9 = 6;
  lVar6 = 0;
  puVar8 = (uint *)*param_3;
  iVar3 = param_2;
  do {
    pbVar1 = (byte *)(iVar3 + 0x16);
    iVar3 = iVar3 + 1;
    lVar6 = lVar6 + (ulonglong)*pbVar1;
    lVar9 = lVar9 + -1;
  } while (lVar9 != 0);
  if ((int)lVar6 == 0) {
    *(undefined1 *)(param_1 + 0x590) = 1;
  }
  else {
    *(undefined1 *)(param_1 + 0x590) = 0;
    puVar4 = (uint *)((int (*)())FUN_000083e0)(param_1,lVar6 + 2,param_5);
    uVar7 = 0x80000000;
    if (*(char *)(param_2 + 0x15) == '\0') {
      uVar7 = 0;
    }
    *puVar4 = -(uint)*(byte *)(param_2 + 0x1b) >> 0x19 & 0x40 |
              (byte)(-(ulonglong)*(byte *)(param_2 + 0x1a) >> 0x18) & 0x80 |
              -(uint)*(byte *)(param_2 + 0x19) >> 0x17 & 0x100 |
              -(uint)*(byte *)(param_2 + 0x18) >> 0x16 & 0x200 |
              -(uint)*(byte *)(param_2 + 0x17) >> 0x15 & 0x400 |
              -(uint)*(byte *)(param_2 + 0x16) >> 0x14 & 0x800 |
              uVar7 | (uint)*(byte *)(param_1 + 0x564) << 0x19;
    puVar5 = puVar4 + 2;
    uVar2 = (ulonglong)param_4 / (ulonglong)*(uint *)(param_1 + 0x580);
    puVar4[1] = (uint)(uVar2 << 0x14) | (param_4 - (int)uVar2 * *(uint *)(param_1 + 0x580)) * 0x10;
    if ((int)(lVar6 + 2) != 2) {
      do {
        *puVar5 = *puVar8;
        puVar8 = puVar8 + 1;
        puVar5 = puVar5 + 1;
        lVar6 = lVar6 + -1;
      } while (lVar6 != 0);
    }
    *param_3 = puVar8;
  }
  return;
}

/* FUN_00008820 @ 0x8820 (3588 bytes) */
int FUN_00008820(param_1, param_2, param_3)
  int param_1;
  short *param_2;
  ulonglong param_3;
{
  short sVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  short sVar5;
  short sVar6;
  int iVar7;
  ulonglong uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  longlong lVar12;
  int iVar13;
  
  iVar9 = param_1 + 0x55c;
  iVar11 = *(int *)(param_1 + 0x568);
  iVar13 = (int)((param_3 & 0xffffffff) / (ulonglong)*(uint *)(param_1 + 0x580));
  lVar12 = param_3 - (longlong)iVar13 * (longlong)(int)*(uint *)(param_1 + 0x580);
  uVar8 = lVar12 + (longlong)iVar13 * (longlong)(int)(*(uint *)(param_1 + 0x58c) >> 2);
  iVar10 = (int)((param_3 & 0x3fffffff) << 2);
  if (*(int *)(param_1 + 0x55c) == 3) {
    switch(*(undefined1 *)(param_2 + 10)) {
    default:
      return;
    case 1:
      iVar13 = (int)((uVar8 & 0xffffffff) << 2);
      iVar9 = iVar11 * 0x10 + iVar9;
      iVar11 = param_1 + 0x14428;
      *(uint *)(*(int *)(iVar9 + 0x14c98) + iVar13) = CONCAT22(param_2[1],*param_2);
      *(uint *)(iVar13 + *(int *)(iVar9 + 0x14ce8)) =
           ((int)param_2[1] - ((int)param_2[1] >> 0x1f) & 0x1fffeU) << 0xf |
           (uint)((int)*param_2 - ((int)*param_2 >> 0x1f)) >> 1 & 0xffff;
      if (*(char *)(param_1 + 0x590) == '\0') {
        iVar11 = *(int *)(param_1 + 0x14428);
        *(int *)(iVar11 * 4 + *(int *)(param_1 + 0x14430)) = iVar10;
        *(int *)(param_1 + 0x14428) = iVar11 + -1;
        return;
      }
      goto LAB_000089ac;
    case 2:
      iVar13 = (int)((uVar8 & 0xffffffff) << 2);
      iVar9 = iVar11 * 0x10 + iVar9;
      iVar11 = param_1 + 0x14434;
      *(uint *)(*(int *)(iVar9 + 0x14c9c) + iVar13) = CONCAT22(param_2[3],param_2[2]);
      *(uint *)(iVar13 + *(int *)(iVar9 + 0x14cec)) =
           ((int)param_2[3] - ((int)param_2[3] >> 0x1f) & 0x1fffeU) << 0xf |
           (uint)((int)param_2[2] - ((int)param_2[2] >> 0x1f)) >> 1 & 0xffff;
      if (*(char *)(param_1 + 0x590) == '\0') {
        iVar11 = *(int *)(param_1 + 0x14434);
        *(int *)(iVar11 * 4 + *(int *)(param_1 + 0x1443c)) = iVar10;
        *(int *)(param_1 + 0x14434) = iVar11 + -1;
        return;
      }
LAB_000089ac:
      iVar9 = *(int *)(iVar11 + 4);
      *(int *)(iVar9 * 4 + *(int *)(iVar11 + 8)) = iVar10;
      *(int *)(iVar11 + 4) = iVar9 + 1;
      return;
    case 3:
      iVar9 = iVar11 * 0x10 + iVar9;
      iVar11 = (int)((uVar8 & 0x3fffffff) << 2);
      *(uint *)(*(int *)(iVar9 + 0x14c98) + iVar11) = CONCAT22(param_2[1],*param_2);
      *(uint *)(iVar11 + *(int *)(iVar9 + 0x14c9c)) = CONCAT22(param_2[3],param_2[2]);
      *(uint *)(iVar11 + *(int *)(iVar9 + 0x14ce8)) =
           ((int)param_2[1] - ((int)param_2[1] >> 0x1f) & 0x1fffeU) << 0xf |
           (uint)((int)*param_2 - ((int)*param_2 >> 0x1f)) >> 1 & 0xffff;
      *(uint *)(iVar11 + *(int *)(iVar9 + 0x14cec)) =
           ((int)param_2[3] - ((int)param_2[3] >> 0x1f) & 0x1fffeU) << 0xf |
           (uint)((int)param_2[2] - ((int)param_2[2] >> 0x1f)) >> 1 & 0xffff;
      if (*(char *)(param_1 + 0x590) != '\0') {
        iVar11 = *(int *)(param_1 + 0x14444);
        *(int *)(iVar11 * 4 + *(int *)(param_1 + 0x14448)) = iVar10;
        *(int *)(param_1 + 0x14444) = iVar11 + 1;
        return;
      }
      iVar11 = *(int *)(param_1 + 0x14440);
      *(int *)(iVar11 * 4 + *(int *)(param_1 + 0x14448)) = iVar10;
      *(int *)(param_1 + 0x14440) = iVar11 + -1;
      return;
    case 5:
      sVar1 = param_2[5];
      iVar9 = iVar11 * 0x10 + iVar9;
      sVar2 = param_2[4];
      iVar11 = (int)((uVar8 & 0x3fffffff) << 2);
      *(uint *)(*(int *)(iVar9 + 0x14c98) + iVar11) = CONCAT22(param_2[1],*param_2);
      *(uint *)(iVar11 + *(int *)(iVar9 + 0x14ca0)) = CONCAT22(sVar1,sVar2);
      sVar1 = param_2[5];
      sVar2 = param_2[4];
      *(uint *)(iVar11 + *(int *)(iVar9 + 0x14ce8)) =
           ((int)param_2[1] - ((int)param_2[1] >> 0x1f) & 0x1fffeU) << 0xf |
           (uint)((int)*param_2 - ((int)*param_2 >> 0x1f)) >> 1 & 0xffff;
      *(uint *)(iVar11 + *(int *)(iVar9 + 0x14cf0)) =
           ((int)sVar1 - ((int)sVar1 >> 0x1f) & 0x1fffeU) << 0xf |
           (uint)((int)sVar2 - ((int)sVar2 >> 0x1f)) >> 1 & 0xffff;
      iVar10 = iVar10 + *(int *)(param_1 + 0x153fc);
      iVar11 = param_1 + 0x14428 + (uint)*(byte *)(param_2 + 8) * 0xc;
      if (*(char *)(param_1 + 0x590) == '\0') {
        iVar9 = *(int *)(iVar11 + 0x24);
        *(int *)(iVar9 * 4 + *(int *)(iVar11 + 0x2c)) = iVar10;
        *(int *)(iVar11 + 0x24) = iVar9 + -1;
      }
      else {
        iVar9 = *(int *)(iVar11 + 0x28);
        *(int *)(iVar9 * 4 + *(int *)(iVar11 + 0x2c)) = iVar10;
        *(int *)(iVar11 + 0x28) = iVar9 + 1;
      }
      iVar11 = param_1 + 0x14428 + (uint)*(byte *)(param_2 + 9) * 0xc;
      iVar9 = iVar11 + 0x3c;
      if (*(char *)(param_1 + 0x590) == '\0') {
        iVar9 = *(int *)(iVar11 + 0x3c);
        *(int *)(iVar9 * 4 + *(int *)(iVar11 + 0x44)) = iVar10;
        *(int *)(iVar11 + 0x3c) = iVar9 + -1;
        return;
      }
      break;
    case 6:
      sVar1 = param_2[7];
      iVar9 = iVar11 * 0x10 + iVar9;
      sVar2 = param_2[6];
      iVar11 = (int)((uVar8 & 0x3fffffff) << 2);
      *(uint *)(*(int *)(iVar9 + 0x14c9c) + iVar11) = CONCAT22(param_2[3],param_2[2]);
      *(uint *)(iVar11 + *(int *)(iVar9 + 0x14ca4)) = CONCAT22(sVar1,sVar2);
      sVar1 = param_2[7];
      sVar2 = param_2[6];
      *(uint *)(iVar11 + *(int *)(iVar9 + 0x14cec)) =
           ((int)param_2[3] - ((int)param_2[3] >> 0x1f) & 0x1fffeU) << 0xf |
           (uint)((int)param_2[2] - ((int)param_2[2] >> 0x1f)) >> 1 & 0xffff;
      *(uint *)(iVar11 + *(int *)(iVar9 + 0x14cf4)) =
           ((int)sVar1 - ((int)sVar1 >> 0x1f) & 0x1fffeU) << 0xf |
           (uint)((int)sVar2 - ((int)sVar2 >> 0x1f)) >> 1 & 0xffff;
      iVar10 = iVar10 + *(int *)(param_1 + 0x153fc);
      iVar11 = param_1 + 0x14428 + (uint)*(byte *)((int)param_2 + 0x11) * 0xc;
      if (*(char *)(param_1 + 0x590) == '\0') {
        iVar9 = *(int *)(iVar11 + 0x54);
        *(int *)(iVar9 * 4 + *(int *)(iVar11 + 0x5c)) = iVar10;
        *(int *)(iVar11 + 0x54) = iVar9 + -1;
      }
      else {
        iVar9 = *(int *)(iVar11 + 0x58);
        *(int *)(iVar9 * 4 + *(int *)(iVar11 + 0x5c)) = iVar10;
        *(int *)(iVar11 + 0x58) = iVar9 + 1;
      }
      iVar11 = param_1 + 0x14428 + (uint)*(byte *)((int)param_2 + 0x13) * 0xc;
      iVar9 = iVar11 + 0x6c;
      if (*(char *)(param_1 + 0x590) == '\0') {
        iVar9 = *(int *)(iVar11 + 0x6c);
        *(int *)(iVar9 * 4 + *(int *)(iVar11 + 0x74)) = iVar10;
        *(int *)(iVar11 + 0x6c) = iVar9 + -1;
        return;
      }
      break;
    case 7:
      sVar4 = param_2[2];
      sVar5 = param_2[6];
      iVar9 = iVar11 * 0x10 + iVar9;
      sVar1 = param_2[3];
      sVar2 = param_2[5];
      sVar3 = param_2[7];
      sVar6 = param_2[4];
      iVar11 = (int)((uVar8 & 0x3fffffff) << 2);
      *(uint *)(*(int *)(iVar9 + 0x14c98) + iVar11) = CONCAT22(param_2[1],*param_2);
      *(uint *)(iVar11 + *(int *)(iVar9 + 0x14c9c)) = CONCAT22(sVar1,sVar4);
      *(uint *)(iVar11 + *(int *)(iVar9 + 0x14ca0)) = CONCAT22(sVar2,sVar6);
      *(uint *)(iVar11 + *(int *)(iVar9 + 0x14ca4)) = CONCAT22(sVar3,sVar5);
      sVar1 = param_2[3];
      sVar2 = param_2[2];
      sVar3 = param_2[5];
      sVar4 = param_2[6];
      sVar5 = param_2[4];
      sVar6 = param_2[7];
      *(uint *)(iVar11 + *(int *)(iVar9 + 0x14ce8)) =
           ((int)param_2[1] - ((int)param_2[1] >> 0x1f) & 0x1fffeU) << 0xf |
           (uint)((int)*param_2 - ((int)*param_2 >> 0x1f)) >> 1 & 0xffff;
      *(uint *)(iVar11 + *(int *)(iVar9 + 0x14cec)) =
           ((int)sVar1 - ((int)sVar1 >> 0x1f) & 0x1fffeU) << 0xf |
           (uint)((int)sVar2 - ((int)sVar2 >> 0x1f)) >> 1 & 0xffff;
      *(uint *)(iVar11 + *(int *)(iVar9 + 0x14cf0)) =
           ((int)sVar3 - ((int)sVar3 >> 0x1f) & 0x1fffeU) << 0xf |
           (uint)((int)sVar5 - ((int)sVar5 >> 0x1f)) >> 1 & 0xffff;
      *(uint *)(iVar11 + *(int *)(iVar9 + 0x14cf4)) =
           ((int)sVar6 - ((int)sVar6 >> 0x1f) & 0x1fffeU) << 0xf |
           (uint)((int)sVar4 - ((int)sVar4 >> 0x1f)) >> 1 & 0xffff;
      iVar10 = iVar10 + *(int *)(param_1 + 0x153fc);
      iVar11 = param_1 + 0x14428 +
               ((uint)*(byte *)((int)param_2 + 0x11) * 2 + (uint)*(byte *)(param_2 + 8)) * 0xc;
      if (*(char *)(param_1 + 0x590) == '\0') {
        iVar9 = *(int *)(iVar11 + 0x84);
        *(int *)(iVar9 * 4 + *(int *)(iVar11 + 0x8c)) = iVar10;
        *(int *)(iVar11 + 0x84) = iVar9 + -1;
      }
      else {
        iVar9 = *(int *)(iVar11 + 0x88);
        *(int *)(iVar9 * 4 + *(int *)(iVar11 + 0x8c)) = iVar10;
        *(int *)(iVar11 + 0x88) = iVar9 + 1;
      }
      iVar11 = param_1 + 0x14428 +
               ((uint)*(byte *)((int)param_2 + 0x13) * 2 + (uint)*(byte *)(param_2 + 9)) * 0xc;
      iVar9 = iVar11 + 0xb4;
      if (*(char *)(param_1 + 0x590) == '\0') {
        iVar9 = *(int *)(iVar11 + 0xb4);
        *(int *)(iVar9 * 4 + *(int *)(iVar11 + 0xbc)) = iVar10;
        *(int *)(iVar11 + 0xb4) = iVar9 + -1;
        return;
      }
    }
    iVar11 = *(int *)(iVar9 + 4);
    *(int *)(iVar11 * 4 + *(int *)(iVar9 + 8)) = iVar10;
    *(int *)(iVar9 + 4) = iVar11 + 1;
    return;
  }
  switch(*(undefined1 *)(param_2 + 10)) {
  default:
    goto switchD_00008894_caseD_0;
  case 1:
    iVar13 = (int)((uVar8 & 0xffffffff) << 2);
    iVar9 = iVar11 * 0x10 + iVar9;
    iVar11 = param_1 + 0x14428;
    *(uint *)(*(int *)(iVar9 + 0x14c98) + iVar13) = CONCAT22(param_2[1],*param_2);
    *(uint *)(iVar13 + *(int *)(iVar9 + 0x14ce8)) =
         ((int)param_2[1] - ((int)param_2[1] >> 0x1f) & 0x1fffeU) << 0xf |
         (uint)((int)*param_2 - ((int)*param_2 >> 0x1f)) >> 1 & 0xffff;
    iVar13 = (uint)*(byte *)(param_2 + 8) * 0xc;
    iVar9 = iVar11 + iVar13;
    if (*(char *)(param_1 + 0x590) == '\0') {
      iVar7 = *(int *)(iVar11 + iVar13);
      *(int *)(iVar7 * 4 + *(int *)(iVar9 + 8)) = iVar10;
      *(int *)(iVar11 + iVar13) = iVar7 + -1;
      return;
    }
    break;
  case 2:
    iVar13 = (int)((uVar8 & 0xffffffff) << 2);
    iVar9 = iVar11 * 0x10 + iVar9;
    *(uint *)(*(int *)(iVar9 + 0x14c9c) + iVar13) = CONCAT22(param_2[3],param_2[2]);
    *(uint *)(iVar13 + *(int *)(iVar9 + 0x14cec)) =
         ((int)param_2[3] - ((int)param_2[3] >> 0x1f) & 0x1fffeU) << 0xf |
         (uint)((int)param_2[2] - ((int)param_2[2] >> 0x1f)) >> 1 & 0xffff;
    iVar11 = param_1 + 0x14428 + (uint)*(byte *)((int)param_2 + 0x11) * 0xc;
    iVar9 = iVar11 + 0x18;
    if (*(char *)(param_1 + 0x590) == '\0') {
      iVar9 = *(int *)(iVar11 + 0x18);
      *(int *)(iVar9 * 4 + *(int *)(iVar11 + 0x20)) = iVar10;
      *(int *)(iVar11 + 0x18) = iVar9 + -1;
      return;
    }
    break;
  case 3:
    iVar9 = iVar11 * 0x10 + iVar9;
    iVar11 = (int)((uVar8 & 0x3fffffff) << 2);
    *(uint *)(*(int *)(iVar9 + 0x14c98) + iVar11) = CONCAT22(param_2[1],*param_2);
    *(uint *)(iVar11 + *(int *)(iVar9 + 0x14c9c)) = CONCAT22(param_2[3],param_2[2]);
    *(uint *)(iVar11 + *(int *)(iVar9 + 0x14ce8)) =
         ((int)param_2[1] - ((int)param_2[1] >> 0x1f) & 0x1fffeU) << 0xf |
         (uint)((int)*param_2 - ((int)*param_2 >> 0x1f)) >> 1 & 0xffff;
    *(uint *)(iVar11 + *(int *)(iVar9 + 0x14cec)) =
         ((int)param_2[3] - ((int)param_2[3] >> 0x1f) & 0x1fffeU) << 0xf |
         (uint)((int)param_2[2] - ((int)param_2[2] >> 0x1f)) >> 1 & 0xffff;
    iVar11 = param_1 + 0x14428 +
             ((uint)*(byte *)((int)param_2 + 0x11) * 2 + (uint)*(byte *)(param_2 + 8)) * 0xc;
    iVar9 = iVar11 + 0x30;
    if (*(char *)(param_1 + 0x590) == '\0') {
      iVar9 = *(int *)(iVar11 + 0x30);
      *(int *)(iVar9 * 4 + *(int *)(iVar11 + 0x38)) = iVar10;
      *(int *)(iVar11 + 0x30) = iVar9 + -1;
      return;
    }
    break;
  case 5:
    sVar1 = param_2[5];
    iVar9 = iVar11 * 0x10 + iVar9;
    sVar2 = param_2[4];
    iVar11 = (int)((uVar8 & 0x3fffffff) << 2);
    *(uint *)(*(int *)(iVar9 + 0x14c98) + iVar11) = CONCAT22(param_2[1],*param_2);
    *(uint *)(iVar11 + *(int *)(iVar9 + 0x14ca0)) = CONCAT22(sVar1,sVar2);
    sVar1 = param_2[5];
    sVar2 = param_2[4];
    *(uint *)(iVar11 + *(int *)(iVar9 + 0x14ce8)) =
         ((int)param_2[1] - ((int)param_2[1] >> 0x1f) & 0x1fffeU) << 0xf |
         (uint)((int)*param_2 - ((int)*param_2 >> 0x1f)) >> 1 & 0xffff;
    *(uint *)(iVar11 + *(int *)(iVar9 + 0x14cf0)) =
         ((int)sVar1 - ((int)sVar1 >> 0x1f) & 0x1fffeU) << 0xf |
         (uint)((int)sVar2 - ((int)sVar2 >> 0x1f)) >> 1 & 0xffff;
    iVar9 = param_1 + 0x14428 + (uint)*(byte *)(param_2 + 8) * 0xc;
    iVar11 = (int)((lVar12 + ((longlong)iVar13 * (longlong)*(int *)(param_1 + 0x580) & 0x7fffffffU)
                             * 2 & 0xffffffff) << 2) + *(int *)(param_1 + 0x153fc);
    if (*(char *)(param_1 + 0x590) == '\0') {
      iVar10 = *(int *)(iVar9 + 0x60);
      *(int *)(iVar10 * 4 + *(int *)(iVar9 + 0x68)) = iVar11;
      *(int *)(iVar9 + 0x60) = iVar10 + -1;
    }
    else {
      iVar10 = *(int *)(iVar9 + 100);
      *(int *)(iVar10 * 4 + *(int *)(iVar9 + 0x68)) = iVar11;
      *(int *)(iVar9 + 100) = iVar10 + 1;
    }
    iVar9 = param_1 + 0x14428 + (uint)*(byte *)(param_2 + 9) * 0xc;
    iVar11 = iVar11 + *(int *)(param_1 + 0x580) * 4;
    iVar10 = iVar9 + 0x78;
    if (*(char *)(param_1 + 0x590) == '\0') {
      iVar10 = *(int *)(iVar9 + 0x78);
      *(int *)(iVar10 * 4 + *(int *)(iVar9 + 0x80)) = iVar11;
      *(int *)(iVar9 + 0x78) = iVar10 + -1;
      return;
    }
    goto LAB_00009624;
  case 6:
    sVar1 = param_2[7];
    iVar9 = iVar11 * 0x10 + iVar9;
    sVar2 = param_2[6];
    iVar11 = (int)((uVar8 & 0x3fffffff) << 2);
    *(uint *)(*(int *)(iVar9 + 0x14c9c) + iVar11) = CONCAT22(param_2[3],param_2[2]);
    *(uint *)(iVar11 + *(int *)(iVar9 + 0x14ca4)) = CONCAT22(sVar1,sVar2);
    sVar1 = param_2[7];
    sVar2 = param_2[6];
    *(uint *)(iVar11 + *(int *)(iVar9 + 0x14cec)) =
         ((int)param_2[3] - ((int)param_2[3] >> 0x1f) & 0x1fffeU) << 0xf |
         (uint)((int)param_2[2] - ((int)param_2[2] >> 0x1f)) >> 1 & 0xffff;
    *(uint *)(iVar11 + *(int *)(iVar9 + 0x14cf4)) =
         ((int)sVar1 - ((int)sVar1 >> 0x1f) & 0x1fffeU) << 0xf |
         (uint)((int)sVar2 - ((int)sVar2 >> 0x1f)) >> 1 & 0xffff;
    iVar9 = param_1 + 0x14428 + (uint)*(byte *)((int)param_2 + 0x11) * 0xc;
    iVar11 = (int)((lVar12 + ((longlong)iVar13 * (longlong)*(int *)(param_1 + 0x580) & 0x7fffffffU)
                             * 2 & 0xffffffff) << 2) + *(int *)(param_1 + 0x153fc);
    if (*(char *)(param_1 + 0x590) == '\0') {
      iVar10 = *(int *)(iVar9 + 0x90);
      *(int *)(iVar10 * 4 + *(int *)(iVar9 + 0x98)) = iVar11;
      *(int *)(iVar9 + 0x90) = iVar10 + -1;
    }
    else {
      iVar10 = *(int *)(iVar9 + 0x94);
      *(int *)(iVar10 * 4 + *(int *)(iVar9 + 0x98)) = iVar11;
      *(int *)(iVar9 + 0x94) = iVar10 + 1;
    }
    iVar9 = param_1 + 0x14428 + (uint)*(byte *)((int)param_2 + 0x13) * 0xc;
    iVar11 = iVar11 + *(int *)(param_1 + 0x580) * 4;
    iVar10 = iVar9 + 0xa8;
    if (*(char *)(param_1 + 0x590) == '\0') {
      iVar10 = *(int *)(iVar9 + 0xa8);
      *(int *)(iVar10 * 4 + *(int *)(iVar9 + 0xb0)) = iVar11;
      *(int *)(iVar9 + 0xa8) = iVar10 + -1;
      return;
    }
    goto LAB_00009624;
  case 7:
    sVar4 = param_2[2];
    sVar5 = param_2[6];
    iVar9 = iVar11 * 0x10 + iVar9;
    sVar1 = param_2[3];
    sVar2 = param_2[5];
    sVar3 = param_2[7];
    sVar6 = param_2[4];
    iVar11 = (int)((uVar8 & 0x3fffffff) << 2);
    *(uint *)(*(int *)(iVar9 + 0x14c98) + iVar11) = CONCAT22(param_2[1],*param_2);
    *(uint *)(iVar11 + *(int *)(iVar9 + 0x14c9c)) = CONCAT22(sVar1,sVar4);
    *(uint *)(iVar11 + *(int *)(iVar9 + 0x14ca0)) = CONCAT22(sVar2,sVar6);
    *(uint *)(iVar11 + *(int *)(iVar9 + 0x14ca4)) = CONCAT22(sVar3,sVar5);
    sVar1 = param_2[3];
    sVar2 = param_2[2];
    sVar3 = param_2[5];
    sVar4 = param_2[6];
    sVar5 = param_2[4];
    sVar6 = param_2[7];
    *(uint *)(iVar11 + *(int *)(iVar9 + 0x14ce8)) =
         ((int)param_2[1] - ((int)param_2[1] >> 0x1f) & 0x1fffeU) << 0xf |
         (uint)((int)*param_2 - ((int)*param_2 >> 0x1f)) >> 1 & 0xffff;
    *(uint *)(iVar11 + *(int *)(iVar9 + 0x14cec)) =
         ((int)sVar1 - ((int)sVar1 >> 0x1f) & 0x1fffeU) << 0xf |
         (uint)((int)sVar2 - ((int)sVar2 >> 0x1f)) >> 1 & 0xffff;
    *(uint *)(iVar11 + *(int *)(iVar9 + 0x14cf0)) =
         ((int)sVar3 - ((int)sVar3 >> 0x1f) & 0x1fffeU) << 0xf |
         (uint)((int)sVar5 - ((int)sVar5 >> 0x1f)) >> 1 & 0xffff;
    *(uint *)(iVar11 + *(int *)(iVar9 + 0x14cf4)) =
         ((int)sVar6 - ((int)sVar6 >> 0x1f) & 0x1fffeU) << 0xf |
         (uint)((int)sVar4 - ((int)sVar4 >> 0x1f)) >> 1 & 0xffff;
    iVar9 = param_1 + 0x14428 +
            ((uint)*(byte *)((int)param_2 + 0x11) * 2 + (uint)*(byte *)(param_2 + 8)) * 0xc;
    iVar11 = (int)((lVar12 + ((longlong)iVar13 * (longlong)*(int *)(param_1 + 0x580) & 0x7fffffffU)
                             * 2 & 0xffffffff) << 2) + *(int *)(param_1 + 0x153fc);
    if (*(char *)(param_1 + 0x590) == '\0') {
      iVar10 = *(int *)(iVar9 + 0xc0);
      *(int *)(iVar10 * 4 + *(int *)(iVar9 + 200)) = iVar11;
      *(int *)(iVar9 + 0xc0) = iVar10 + -1;
    }
    else {
      iVar10 = *(int *)(iVar9 + 0xc4);
      *(int *)(iVar10 * 4 + *(int *)(iVar9 + 200)) = iVar11;
      *(int *)(iVar9 + 0xc4) = iVar10 + 1;
    }
    iVar11 = iVar11 + *(int *)(param_1 + 0x580) * 4;
    iVar9 = param_1 + 0x14428 +
            ((uint)*(byte *)((int)param_2 + 0x13) * 2 + (uint)*(byte *)(param_2 + 9)) * 0xc;
    iVar10 = iVar9 + 0xf0;
    if (*(char *)(param_1 + 0x590) == '\0') {
      iVar10 = *(int *)(iVar9 + 0xf0);
      *(int *)(iVar10 * 4 + *(int *)(iVar9 + 0xf8)) = iVar11;
      *(int *)(iVar9 + 0xf0) = iVar10 + -1;
      return;
    }
LAB_00009624:
    iVar9 = *(int *)(iVar10 + 4);
    *(int *)(iVar9 * 4 + *(int *)(iVar10 + 8)) = iVar11;
    *(int *)(iVar10 + 4) = iVar9 + 1;
    goto switchD_00008894_caseD_0;
  }
  iVar11 = *(int *)(iVar9 + 4);
  *(int *)(iVar11 * 4 + *(int *)(iVar9 + 8)) = iVar10;
  *(int *)(iVar9 + 4) = iVar11 + 1;
switchD_00008894_caseD_0:
  return;
}

/* FUN_00009690 @ 0x9690 (4 bytes) */
int FUN_00009690()
{
  return;
}

/* FUN_000096a0 @ 0x96a0 (96 bytes) */
int FUN_000096a0(param_1)
  undefined4 *param_1;
{
  *param_1 = 0x5c8;
  param_1[1] = 0x10030000;
  param_1[2] = ((unsigned char *)0x00001002);
  param_1[3] = 0;
  param_1[4] = 0x1381;
  param_1[5] = 0;
  param_1[6] = ((unsigned char *)0x00001040);
  param_1[7] = 0;
  return param_1 + 8;
}

/* FUN_00009700 @ 0x9700 (528 bytes) */
int FUN_00009700(param_1, param_2)
  undefined4 *param_1;
  longlong param_2;
{
  uint *puVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  ulonglong uVar8;
  int iVar9;
  longlong lVar10;
  
  iVar9 = (int)param_2;
  *param_1 = 0x850;
  param_1[1] = 0x102;
  param_1[2] = 0x854;
  if (iVar9 == 1) {
    uVar7 = 0x26010001;
  }
  else {
    uVar7 = 0x6010001;
  }
  param_1[3] = uVar7;
  param_1[4] = 0x878;
  piVar3 = param_1 + 6;
  param_1[5] = 0xf688f688;
  if (1 < iVar9) {
    uVar8 = 1;
    piVar2 = piVar3;
    do {
      iVar6 = ((int)uVar8 >> 1) + (uint)((int)uVar8 < 0 && (uVar8 & 1) != 0);
      *piVar2 = iVar6 + 0x855;
      iVar4 = (int)(uVar8 + 2);
      piVar2[1] = (uint)(param_2 == uVar8 + 1) << 0xd | (uint)((uVar8 + 6 & 0xffffffff) << 8) |
                  (uint)(iVar9 == iVar4) << 0x1d | (uint)((uVar8 + 7 & 0xffffffff) << 0x18) |
                  0x10001;
      piVar2[2] = iVar6 + 0x879;
      piVar3 = piVar2 + 4;
      piVar2[3] = -0x9770978;
      uVar8 = uVar8 + 2;
      piVar2 = piVar3;
    } while (iVar4 < iVar9);
  }
  *piVar3 = 0x824;
  piVar3[1] = 1;
  if (0 < iVar9) {
    uVar8 = 0;
    lVar10 = param_2;
    do {
      uVar8 = uVar8 | (uVar8 & 0x1fffffff) << 3 | 2;
      iVar4 = (int)uVar8;
      lVar10 = lVar10 + -1;
    } while (lVar10 != 0);
  }
  else {
    iVar4 = 0;
  }
  piVar3[2] = 0x825;
  piVar3[3] = iVar4;
  piVar3[4] = (int)((unsigned char *)0x000010c0);
  piVar3[5] = iVar9 << 1 | 0x40000;
  piVar3[6] = (int)((unsigned char *)0x000010c1);
  piVar2 = piVar3 + 8;
  piVar3[7] = iVar9 + -1;
  if (0 < iVar9) {
    uVar5 = 0;
    iVar9 = 1;
    do {
      *piVar2 = (int)(((unsigned char *)0x0000101d) + uVar5);
      piVar2[1] = uVar5 << 1 | iVar9 << 6 | 0x28ffe000;
      piVar2[2] = (int)(((unsigned char *)0x000010c8) + uVar5);
      puVar1 = (uint *)(piVar2 + 3);
      piVar2 = piVar2 + 4;
      *puVar1 = uVar5 | uVar5 << 5 | 0x10;
      uVar5 = uVar5 + 1;
      iVar9 = iVar9 + 2;
      param_2 = param_2 + -1;
    } while (param_2 != 0);
    return;
  }
  return;
}

/* FUN_00009930 @ 0x9930 (80 bytes) */
int FUN_00009930(param_1, param_2, param_3, param_4)
  uint *param_1;
  uint param_2;
  uint *param_3;
  longlong param_4;
{
  uint uVar1;
  uint *puVar2;
  
  puVar2 = param_1 + 1;
  *param_1 = ((int)param_4 + -1) * 0x10000 | param_2 | 0x8000;
  if ((int)param_4 != 0) {
    do {
      uVar1 = *param_3;
      param_3 = param_3 + 1;
      *puVar2 = uVar1;
      puVar2 = puVar2 + 1;
      param_4 = param_4 + -1;
    } while (param_4 != 0);
  }
  return puVar2;
}

/* FUN_00009980 @ 0x9980 (48 bytes) */
int FUN_00009980(param_1, param_2, param_3, param_4)
  undefined4 *param_1;
  undefined4 param_2;
  undefined8 param_3;
  undefined8 param_4;
{
  *param_1 = ((unsigned char *)0x00001094);
  param_1[1] = param_2;
  ((int (*)())FUN_00009930)(param_1 + 2,0x1095,param_4,param_3);
  return;
}

/* FUN_000099b0 @ 0x99b0 (264 bytes) */
int FUN_000099b0(param_1, param_2, param_3, param_4, param_5, param_6)
  undefined4 *param_1;
  undefined8 param_2;
  int param_3;
  int param_4;
  ulonglong param_5;
  undefined4 param_6;
{
  int iVar1;
  
  if (param_4 != 0) {
    param_1 = (undefined4 *)((int (*)())FUN_00009980)(param_1,0x10000,(param_5 & 0xfffffff) << 2);
  }
  if ((int)param_2 != 0) {
    param_1 = (undefined4 *)((int (*)())FUN_00009980)(param_1,0,(uint)(param_3 * 0x18) >> 2,param_2);
  }
  *param_1 = 0x1180;
  param_1[1] = 0;
  param_1[2] = 0x11ad;
  param_1[3] = 0;
  param_1[4] = 0x1181;
  param_1[5] = param_6;
  param_1[6] = 0x118c;
  iVar1 = (param_3 + -1) * 0x10000;
  param_1[7] = iVar1;
  param_1[8] = 0x118d;
  param_1[9] = iVar1;
  param_1[10] = 0x118e;
  param_1[0xb] = 0;
  param_1[0xc] = 0x1189;
  param_1[0xd] = 0;
  return param_1 + 0xe;
}

/* FUN_00009ac0 @ 0x9ac0 (424 bytes) */
int FUN_00009ac0(param_1, param_2, param_3, param_4, param_5)
  undefined4 *param_1;
  float *param_2;
  undefined4 *param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  
  *param_1 = 0x82d;
  param_1[1] = 4;
  param_1[2] = 0xc0103500;
  param_1[3] = 0x4083d;
  if (param_2 == (float *)0x0) {
    local_30 = 0.0;
    local_2c = 1.0;
    local_38 = 0.0;
    local_34 = 1.0;
  }
  else {
    local_30 = (float)((double)CONCAT44(0x43300000,param_5) - DOUBLE_0000d418);
    local_38 = (float)((double)CONCAT44(0x43300000,param_4) - DOUBLE_0000d418);
    local_2c = param_2[3] / local_30;
    local_34 = param_2[1] / local_38;
    local_38 = *param_2 / local_38;
    local_30 = param_2[2] / local_30;
  }
  uVar1 = *param_3;
  param_1[4] = uVar1;
  uVar2 = param_3[2];
  param_1[5] = uVar2;
  param_1[6] = local_38;
  param_1[7] = local_30;
  param_1[8] = uVar1;
  uVar1 = param_3[3];
  param_1[9] = uVar1;
  param_1[10] = local_38;
  param_1[0xb] = local_2c;
  uVar3 = param_3[1];
  param_1[0xc] = uVar3;
  param_1[0xd] = uVar1;
  param_1[0xe] = local_34;
  param_1[0xf] = local_2c;
  param_1[0x10] = uVar3;
  param_1[0x11] = uVar2;
  param_1[0x12] = local_34;
  param_1[0x13] = local_30;
  param_1[0x14] = 0x1393;
  param_1[0x15] = 10;
  return param_1 + 0x16;
}

/* FUN_00009c80 @ 0x9c80 (1160 bytes) */
int FUN_00009c80(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  longlong param_3;
{
  uint uVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  undefined *puVar5;
  int iVar6;
  int iVar8;
  undefined8 uVar7;
  undefined4 *puVar9;
  uint uVar10;
  longlong lVar11;
  double dVar12;
  double dVar13;
  double dVar14;
  double dVar15;
  undefined4 local_78;
  float local_74;
  undefined4 local_70;
  float local_6c;
  undefined4 local_68;
  uint uStack_64;
  undefined4 local_60;
  uint uStack_5c;
  
  iVar6 = param_1 + 0x55c;
  iVar8 = FUN_0000cfa8();
  puVar5 = PTR_0000f1a0;
  puVar9 = *(undefined4 **)(iVar8 + 0x34);
  uVar1 = *(uint *)(iVar6 + 0x2c);
  uVar3 = *(uint *)(iVar6 + 0x1c) >> 2;
  uVar4 = *(uint *)(iVar6 + 0x20) >> 1;
  if (*(undefined4 **)(iVar8 + 0x38) <= puVar9 + 0x90) {
    puVar2 = *(uint **)(iVar8 + 0x30);
    *puVar2 = (int)puVar9 - (int)puVar2 >> 2 | *puVar2;
    *(undefined4 **)(iVar8 + 0x30) = *(undefined4 **)(iVar8 + 0x34);
    **(undefined4 **)(iVar8 + 0x34) = 0x1000000;
    _IOConnectMapMemory(*(undefined4 *)(iVar8 + 0x14),1,*(undefined4 *)puVar5,iVar8 + 0x40,
                        iVar8 + 0x44,1);
    iVar6 = *(int *)(param_1 + 0x40);
    *(int *)(param_1 + 0x34) = iVar6 + 0x20;
    *(int *)(param_1 + 0x30) = iVar6 + 0x1c;
    *(int *)(param_1 + 0x38) = iVar6 + 0x20 + *(int *)(iVar6 + 0x10) * 4;
    *(undefined4 *)(iVar6 + 0x1c) = 0;
    puVar9 = *(undefined4 **)(param_1 + 0x34);
  }
  puVar2 = *(uint **)(param_1 + 0x30);
  *(undefined4 **)(param_1 + 0x34) = puVar9 + 0x90;
  *puVar2 = (int)puVar9 - (int)puVar2 >> 2 | *puVar2;
  *(undefined4 **)(param_1 + 0x30) = puVar9;
  *puVar9 = 0x42000000;
  puVar9[1] = param_2;
  puVar9[2] = (uint)(param_3 != 0);
  puVar9 = puVar9 + 3;
  lVar11 = 7;
  do {
    *puVar9 = 0x80000000;
    puVar9 = puVar9 + 1;
    lVar11 = lVar11 + -1;
  } while (lVar11 != 0);
  uVar7 = ((int (*)())FUN_000096a0)();
  puVar9 = (undefined4 *)((int (*)())FUN_00009700)(uVar7,1);
  *puVar9 = ((unsigned char *)0x00001041);
  puVar9[1] = 3;
  puVar9[2] = 0x1100;
  puVar9[3] = 0xa92;
  puVar9[4] = 0x1110;
  puVar9[5] = 0;
  puVar9[6] = 0x1120;
  uVar10 = uVar3 - 1 | (uVar4 - 1) * 0x800 | 0x80000000;
  puVar9[7] = uVar10;
  puVar9[8] = 0x1130;
  puVar9[9] = 0xa60c;
  puVar9[10] = 0x1140;
  iVar6 = (uVar1 >> 2) - 1;
  puVar9[0xb] = iVar6;
  puVar9[0xc] = 0x1101;
  puVar9[0xd] = &DAT_10000a92;
  puVar9[0xe] = 0x1111;
  puVar9[0xf] = 0;
  puVar9[0x10] = 0x1121;
  puVar9[0x11] = uVar10;
  puVar9[0x12] = 0x1131;
  puVar9[0x13] = 0x4340c;
  puVar9[0x14] = 0x1141;
  puVar9[0x15] = iVar6;
  dVar13 = (double)*(float *)(param_1 + 300);
  dVar14 = (double)*(float *)(param_1 + 0x138);
  dVar15 = (double)*(float *)(param_1 + 0x130);
  dVar12 = (double)_cos(dVar13);
  dVar12 = dVar12 * dVar14;
  dVar13 = (double)_sin(dVar13);
  DAT_0000f004 = (float)(dVar12 * dVar15);
  DAT_0000f024 = (float)(dVar15 * dVar14 * -dVar13);
  DAT_0000f028 = -DAT_0000f024;
  DAT_0000f018 = ((DAT_0000f024 + (FLOAT_0000d43c - DAT_0000f004)) * FLOAT_0000d45c) /
                 FLOAT_0000d460;
  DAT_0000f014 = (((FLOAT_0000d43c - DAT_0000f004) - DAT_0000f024) * FLOAT_0000d45c) /
                 FLOAT_0000d460;
  DAT_0000f008 = DAT_0000f004;
  DAT_0000f00c = DAT_0000f004;
  DAT_0000f010 = DAT_0000f004;
  DAT_0000f01c = DAT_0000f014;
  DAT_0000f020 = DAT_0000f018;
  DAT_0000f02c = DAT_0000f024;
  DAT_0000f030 = DAT_0000f028;
  puVar9 = (undefined4 *)((int (*)())FUN_000099b0)(puVar9 + 0x16,&DAT_0000ea9c,4,&DAT_0000f004,3,3);
  *puVar9 = 0x11a9;
  puVar9[1] = ((unsigned char *)0x00001b00);
  puVar9[2] = 0x11aa;
  puVar9[3] = 0xf;
  puVar9[4] = 0x11ab;
  puVar9[5] = 0xf;
  puVar9[6] = 0x11ac;
  puVar9[7] = 0xf;
  uStack_64 = uVar3 ^ 0x80000000;
  uStack_5c = uVar4 ^ 0x80000000;
  local_60 = 0x43300000;
  local_68 = 0x43300000;
  local_70 = 0;
  local_78 = 0;
  local_6c = (float)((double)CONCAT44(0x43300000,uStack_5c) - DOUBLE_0000d420);
  local_74 = (float)((double)CONCAT44(0x43300000,uStack_64) - DOUBLE_0000d420);
  ((int (*)())FUN_00009ac0)(puVar9 + 8,0,&local_78,uVar3,uVar4);
  puVar5 = PTR_0000f1a0;
  puVar2 = *(uint **)(param_1 + 0x30);
  *puVar2 = *(int *)(param_1 + 0x34) - (int)puVar2 >> 2 | *puVar2;
  *(undefined4 **)(param_1 + 0x30) = *(undefined4 **)(param_1 + 0x34);
  **(undefined4 **)(param_1 + 0x34) = 0x1000000;
  _IOConnectMapMemory(*(undefined4 *)(param_1 + 0x14),1,*(undefined4 *)puVar5,iVar8 + 0x40,
                      iVar8 + 0x44,1);
  iVar6 = *(int *)(param_1 + 0x40);
  *(int *)(param_1 + 0x34) = iVar6 + 0x20;
  *(int *)(param_1 + 0x30) = iVar6 + 0x1c;
  *(int *)(param_1 + 0x38) = iVar6 + 0x20 + *(int *)(iVar6 + 0x10) * 4;
  *(undefined4 *)(iVar6 + 0x1c) = 0;
  return;
}

/* FUN_0000a110 @ 0xa110 (964 bytes) */
int FUN_0000a110(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  longlong param_3;
{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  int iVar4;
  uint uVar5;
  undefined *puVar6;
  undefined8 uVar7;
  undefined4 *puVar8;
  longlong lVar9;
  undefined4 local_58;
  float local_54;
  undefined4 local_50;
  float local_4c;
  undefined4 local_48;
  uint uStack_44;
  undefined4 local_40;
  uint uStack_3c;
  
  puVar6 = PTR_0000f1a0;
  puVar8 = *(undefined4 **)(param_1 + 0x34);
  uVar1 = *(uint *)(param_1 + 0x588);
  uVar2 = *(uint *)(param_1 + 0x57c);
  uVar5 = *(uint *)(param_1 + 0x578) >> 2;
  if (*(undefined4 **)(param_1 + 0x38) <= puVar8 + 0x78) {
    puVar3 = *(uint **)(param_1 + 0x30);
    *puVar3 = (int)puVar8 - (int)puVar3 >> 2 | *puVar3;
    *(undefined4 **)(param_1 + 0x30) = *(undefined4 **)(param_1 + 0x34);
    **(undefined4 **)(param_1 + 0x34) = 0x1000000;
    _IOConnectMapMemory(*(undefined4 *)(param_1 + 0x14),1,*(undefined4 *)puVar6,param_1 + 0x40,
                        param_1 + 0x44,1);
    iVar4 = *(int *)(param_1 + 0x40);
    *(int *)(param_1 + 0x34) = iVar4 + 0x20;
    *(int *)(param_1 + 0x30) = iVar4 + 0x1c;
    *(int *)(param_1 + 0x38) = iVar4 + 0x20 + *(int *)(iVar4 + 0x10) * 4;
    *(undefined4 *)(iVar4 + 0x1c) = 0;
    puVar8 = *(undefined4 **)(param_1 + 0x34);
  }
  puVar3 = *(uint **)(param_1 + 0x30);
  *(undefined4 **)(param_1 + 0x34) = puVar8 + 0x78;
  *puVar3 = (int)puVar8 - (int)puVar3 >> 2 | *puVar3;
  *(undefined4 **)(param_1 + 0x30) = puVar8;
  *puVar8 = 0x3f000000;
  puVar8[1] = param_2;
  puVar8[2] = (uint)(param_3 != 0);
  puVar8 = puVar8 + 3;
  lVar9 = 9;
  do {
    *puVar8 = 0x80000000;
    puVar8 = puVar8 + 1;
    lVar9 = lVar9 + -1;
  } while (lVar9 != 0);
  uVar7 = ((int (*)())FUN_000096a0)();
  puVar8 = (undefined4 *)((int (*)())FUN_00009700)(uVar7,1);
  *puVar8 = ((unsigned char *)0x00001041);
  puVar8[1] = 1;
  puVar8[2] = 0x1100;
  puVar8[3] = 0xa92;
  puVar8[4] = 0x1110;
  puVar8[5] = 0;
  puVar8[6] = 0x1120;
  puVar8[7] = uVar5 - 1 | (uVar2 - 1) * 0x800 | 0x80000000;
  puVar8[8] = 0x1130;
  puVar8[9] = 0xa60c;
  puVar8[10] = 0x1140;
  puVar8[0xb] = (uVar1 >> 2) - 1;
  DAT_0000f034 = *(undefined4 *)(param_1 + 0x138);
  DAT_0000f044 = ((FLOAT_0000d43c - *(float *)(param_1 + 0x138)) * FLOAT_0000d45c) / FLOAT_0000d460
                 + *(float *)(param_1 + 0x134);
  DAT_0000f038 = DAT_0000f034;
  DAT_0000f03c = DAT_0000f034;
  DAT_0000f040 = DAT_0000f034;
  DAT_0000f048 = DAT_0000f044;
  DAT_0000f04c = DAT_0000f044;
  DAT_0000f050 = DAT_0000f044;
  puVar8 = (undefined4 *)((int (*)())FUN_000099b0)(puVar8 + 0xc,&DAT_0000eafc,2,&DAT_0000f034,2,2);
  *puVar8 = 0x11a9;
  puVar8[1] = ((unsigned char *)0x00001b00);
  puVar8[2] = 0x11aa;
  puVar8[3] = 0xf;
  puVar8[4] = 0x11ab;
  puVar8[5] = 0xf;
  puVar8[6] = 0x11ac;
  puVar8[7] = 0xf;
  uStack_44 = uVar5 ^ 0x80000000;
  uStack_3c = uVar2 ^ 0x80000000;
  local_40 = 0x43300000;
  local_48 = 0x43300000;
  local_50 = 0;
  local_58 = 0;
  local_4c = (float)((double)CONCAT44(0x43300000,uStack_3c) - DOUBLE_0000d420);
  local_54 = (float)((double)CONCAT44(0x43300000,uStack_44) - DOUBLE_0000d420);
  ((int (*)())FUN_00009ac0)(puVar8 + 8,0,&local_58,uVar5,uVar2);
  puVar6 = PTR_0000f1a0;
  puVar3 = *(uint **)(param_1 + 0x30);
  *puVar3 = *(int *)(param_1 + 0x34) - (int)puVar3 >> 2 | *puVar3;
  *(undefined4 **)(param_1 + 0x30) = *(undefined4 **)(param_1 + 0x34);
  **(undefined4 **)(param_1 + 0x34) = 0x1000000;
  _IOConnectMapMemory(*(undefined4 *)(param_1 + 0x14),1,*(undefined4 *)puVar6,param_1 + 0x40,
                      param_1 + 0x44,1);
  iVar4 = *(int *)(param_1 + 0x40);
  *(int *)(param_1 + 0x34) = iVar4 + 0x20;
  *(int *)(param_1 + 0x30) = iVar4 + 0x1c;
  *(int *)(param_1 + 0x38) = iVar4 + 0x20 + *(int *)(iVar4 + 0x10) * 4;
  *(undefined4 *)(iVar4 + 0x1c) = 0;
  return;
}

/* FUN_0000a4e0 @ 0xa4e0 (1304 bytes) */
int FUN_0000a4e0(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined *puVar6;
  undefined8 uVar7;
  undefined4 *puVar8;
  longlong lVar9;
  undefined4 local_48;
  float local_44;
  undefined4 local_40;
  float local_3c;
  undefined4 local_38;
  undefined4 uStack_34;
  undefined4 local_30;
  undefined4 uStack_2c;
  
  puVar6 = PTR_0000f1a0;
  puVar8 = *(undefined4 **)(param_1 + 0x34);
  if (*(undefined4 **)(param_1 + 0x38) <= puVar8 + 0xb0) {
    puVar1 = *(uint **)(param_1 + 0x30);
    *puVar1 = (int)puVar8 - (int)puVar1 >> 2 | *puVar1;
    *(undefined4 **)(param_1 + 0x30) = *(undefined4 **)(param_1 + 0x34);
    **(undefined4 **)(param_1 + 0x34) = 0x1000000;
    _IOConnectMapMemory(*(undefined4 *)(param_1 + 0x14),1,*(undefined4 *)puVar6,param_1 + 0x40,
                        param_1 + 0x44,1);
    iVar2 = *(int *)(param_1 + 0x40);
    *(int *)(param_1 + 0x34) = iVar2 + 0x20;
    *(int *)(param_1 + 0x30) = iVar2 + 0x1c;
    *(int *)(param_1 + 0x38) = iVar2 + 0x20 + *(int *)(iVar2 + 0x10) * 4;
    *(undefined4 *)(iVar2 + 0x1c) = 0;
    puVar8 = *(undefined4 **)(param_1 + 0x34);
  }
  puVar1 = *(uint **)(param_1 + 0x30);
  *(undefined4 **)(param_1 + 0x34) = puVar8 + 0xb0;
  *puVar1 = (int)puVar8 - (int)puVar1 >> 2 | *puVar1;
  *(undefined4 **)(param_1 + 0x30) = puVar8;
  *puVar8 = 0x44000000;
  puVar8[1] = param_2;
  puVar8[2] = 0x11;
  puVar8[3] = (uint)(*(int *)(param_2 * 4 + param_1 + 0x55c + 0x554) != 0);
  puVar8[4] = *(undefined4 *)(param_1 + 0x11c);
  puVar8 = puVar8 + 5;
  lVar9 = 5;
  do {
    *puVar8 = 0x80000000;
    puVar8 = puVar8 + 1;
    lVar9 = lVar9 + -1;
  } while (lVar9 != 0);
  uVar7 = ((int (*)())FUN_000096a0)();
  puVar8 = (undefined4 *)((int (*)())FUN_00009700)(uVar7,1);
  *puVar8 = 0x1100;
  puVar8[1] = 0xa92;
  puVar8[2] = 0x1110;
  puVar8[3] = 0;
  puVar8[4] = 0x1120;
  uVar3 = *(uint *)(param_1 + 0x57c);
  uVar4 = *(uint *)(param_1 + 0x578);
  puVar8[5] = (uVar3 - 1) * 0x800 | uVar4 - 1 | 0x80000000;
  puVar8[6] = 0x1130;
  puVar8[7] = 0x10120800;
  puVar8[8] = 0x1140;
  uVar5 = *(uint *)(param_1 + 0x588);
  puVar8[9] = uVar5 - 1;
  puVar8[10] = 0x1101;
  puVar8[0xb] = &DAT_10000a92;
  puVar8[0xc] = 0x1111;
  puVar8[0xd] = 0;
  puVar8[0xe] = 0x1121;
  puVar8[0xf] = ((uVar3 >> 1) - 1) * 0x800 | (uVar4 >> 1) - 1 | 0x80000000;
  puVar8[0x10] = 0x1131;
  puVar8[0x11] = 0x18044803;
  puVar8[0x12] = 0x1141;
  puVar8[0x13] = (uVar5 >> 1) - 1;
  puVar8[0x14] = ((unsigned char *)0x00001041);
  puVar8[0x15] = 3;
  puVar8 = (undefined4 *)((int (*)())FUN_000099b0)(puVar8 + 0x16,&DAT_0000eb7c,7,&DAT_0000eb2c,5,3);
  iVar2 = *(int *)(param_3 + 0xc);
  if (((iVar2 == 0x61726762) || (iVar2 == 0x61723135)) || (iVar2 != 0x72676261)) {
    *puVar8 = 0x11a9;
    puVar8[1] = ((unsigned char *)0x00001b00);
  }
  else {
    *puVar8 = 0x11a9;
    puVar8[1] = 0x6c00;
  }
  puVar8[2] = 0x11aa;
  puVar8[3] = 0xf;
  puVar8[4] = 0x11ab;
  puVar8[5] = 0xf;
  puVar8[6] = 0x11ac;
  puVar8[7] = 0xf;
  puVar8[8] = 0x1393;
  puVar8[9] = 10;
  if (iVar2 == 0x61723135) {
    puVar8[10] = 0x138e;
    puVar8[0xb] = *(uint *)(param_3 + 8) >> 1 & 0x3ffe | 0x680000;
  }
  else {
    puVar8[10] = 0x138e;
    puVar8[0xb] = *(uint *)(param_3 + 8) >> 2 & 0x3ffe | 0xd00000;
  }
  uStack_34 = *(undefined4 *)(param_1 + 0x578);
  uStack_2c = *(undefined4 *)(param_1 + 0x57c);
  local_30 = 0x43300000;
  local_38 = 0x43300000;
  local_40 = 0;
  local_48 = 0;
  local_44 = (float)((double)CONCAT44(0x43300000,uStack_34) - DOUBLE_0000d418);
  local_3c = (float)((double)CONCAT44(0x43300000,uStack_2c) - DOUBLE_0000d418);
  puVar8 = (undefined4 *)((int (*)())FUN_00009ac0)(puVar8 + 0xc,0,&local_48);
  *puVar8 = 0x5c8;
  puVar8[1] = 0x10030000;
  puVar6 = PTR_0000f1a0;
  puVar1 = *(uint **)(param_1 + 0x30);
  *puVar1 = *(int *)(param_1 + 0x34) - (int)puVar1 >> 2 | *puVar1;
  *(undefined4 **)(param_1 + 0x30) = *(undefined4 **)(param_1 + 0x34);
  **(undefined4 **)(param_1 + 0x34) = 0x1000000;
  _IOConnectMapMemory(*(undefined4 *)(param_1 + 0x14),1,*(undefined4 *)puVar6,param_1 + 0x40,
                      param_1 + 0x44,1);
  iVar2 = *(int *)(param_1 + 0x40);
  *(int *)(param_1 + 0x34) = iVar2 + 0x20;
  *(int *)(param_1 + 0x30) = iVar2 + 0x1c;
  *(int *)(param_1 + 0x38) = iVar2 + 0x20 + *(int *)(iVar2 + 0x10) * 4;
  *(undefined4 *)(iVar2 + 0x1c) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0xac4) * 8 + param_1 + 0x55c + 0x570) =
       *(undefined4 *)(*(int *)(param_1 + 0x40) + 0x18);
  return;
}

/* FUN_0000aa00 @ 0xaa00 (1152 bytes) */
int FUN_0000aa00(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  undefined *puVar5;
  undefined8 uVar6;
  undefined4 *puVar7;
  int iVar8;
  longlong lVar9;
  undefined4 local_58;
  float local_54;
  undefined4 local_50;
  float local_4c;
  undefined4 local_48;
  uint uStack_44;
  undefined4 local_40;
  uint uStack_3c;
  
  puVar5 = PTR_0000f1a0;
  puVar7 = *(undefined4 **)(param_1 + 0x34);
  uVar1 = *(uint *)(param_1 + 0x588);
  uVar2 = *(uint *)(param_1 + 0x57c);
  uVar4 = *(uint *)(param_1 + 0x578) >> 1;
  if (*(undefined4 **)(param_1 + 0x38) <= puVar7 + 0x88) {
    puVar3 = *(uint **)(param_1 + 0x30);
    *puVar3 = (int)puVar7 - (int)puVar3 >> 2 | *puVar3;
    *(undefined4 **)(param_1 + 0x30) = *(undefined4 **)(param_1 + 0x34);
    **(undefined4 **)(param_1 + 0x34) = 0x1000000;
    _IOConnectMapMemory(*(undefined4 *)(param_1 + 0x14),1,*(undefined4 *)puVar5,param_1 + 0x40,
                        param_1 + 0x44,1);
    iVar8 = *(int *)(param_1 + 0x40);
    *(int *)(param_1 + 0x34) = iVar8 + 0x20;
    *(int *)(param_1 + 0x30) = iVar8 + 0x1c;
    *(int *)(param_1 + 0x38) = iVar8 + 0x20 + *(int *)(iVar8 + 0x10) * 4;
    *(undefined4 *)(iVar8 + 0x1c) = 0;
    puVar7 = *(undefined4 **)(param_1 + 0x34);
  }
  puVar3 = *(uint **)(param_1 + 0x30);
  *(undefined4 **)(param_1 + 0x34) = puVar7 + 0x88;
  *puVar3 = (int)puVar7 - (int)puVar3 >> 2 | *puVar3;
  *(undefined4 **)(param_1 + 0x30) = puVar7;
  *puVar7 = 0x43000000;
  puVar7[1] = param_2;
  puVar7[2] = 0x11;
  puVar7[3] = (uint)(*(int *)(param_2 * 4 + param_1 + 0x55c + 0x554) != 0);
  puVar7[4] = *(undefined4 *)(param_1 + 0x11c);
  puVar7 = puVar7 + 5;
  lVar9 = 6;
  do {
    *puVar7 = 0x80000000;
    puVar7 = puVar7 + 1;
    lVar9 = lVar9 + -1;
  } while (lVar9 != 0);
  uVar6 = ((int (*)())FUN_000096a0)();
  puVar7 = (undefined4 *)((int (*)())FUN_00009700)(uVar6,1);
  *puVar7 = ((unsigned char *)0x00001041);
  puVar7[1] = 3;
  puVar7[2] = 0x1100;
  puVar7[3] = 0xa92;
  puVar7[4] = 0x1110;
  puVar7[5] = 0;
  puVar7[6] = 0x1120;
  puVar7[7] = uVar4 - 1 | (uVar2 - 1) * 0x800 | 0x80000000;
  puVar7[8] = 0x1130;
  puVar7[9] = 0x10060803;
  puVar7[10] = 0x1140;
  iVar8 = (uVar1 >> 1) - 1;
  puVar7[0xb] = iVar8;
  puVar7[0xc] = 0x1101;
  puVar7[0xd] = &DAT_10000a92;
  puVar7[0xe] = 0x1111;
  puVar7[0xf] = 0;
  puVar7[0x10] = 0x1121;
  puVar7[0x11] = uVar4 - 1 |
                 (((int)uVar2 >> 1) + (uint)((int)uVar2 < 0 && (uVar2 & 1) != 0) + -1) * 0x800 |
                 0x80000000;
  puVar7[0x12] = 0x1131;
  puVar7[0x13] = 0x1810c003;
  puVar7[0x14] = 0x1141;
  puVar7[0x15] = iVar8;
  puVar7 = (undefined4 *)((int (*)())FUN_000099b0)(puVar7 + 0x16,&DAT_0000ec24,4,0,0,3);
  *puVar7 = 0x11a9;
  puVar7[1] = ((unsigned char *)0x00001b00);
  puVar7[2] = 0x11aa;
  puVar7[3] = 0xf;
  puVar7[4] = 0x11ab;
  puVar7[5] = 0xf;
  puVar7[6] = 0x11ac;
  puVar7[7] = 0xf;
  puVar7[8] = 0x1393;
  puVar7[9] = 10;
  puVar7[10] = 0x138e;
  puVar7[0xb] = *(uint *)(param_3 + 8) >> 2 & 0x3ffe | 0xd00000;
  uStack_44 = uVar4 ^ 0x80000000;
  uStack_3c = uVar2 ^ 0x80000000;
  local_40 = 0x43300000;
  local_48 = 0x43300000;
  local_50 = 0;
  local_58 = 0;
  local_4c = (float)((double)CONCAT44(0x43300000,uStack_3c) - DOUBLE_0000d420);
  local_54 = (float)((double)CONCAT44(0x43300000,uStack_44) - DOUBLE_0000d420);
  puVar7 = (undefined4 *)((int (*)())FUN_00009ac0)(puVar7 + 0xc,0,&local_58,uVar4,uVar2);
  *puVar7 = 0x5c8;
  puVar7[1] = 0x10030000;
  puVar5 = PTR_0000f1a0;
  puVar3 = *(uint **)(param_1 + 0x30);
  *puVar3 = *(int *)(param_1 + 0x34) - (int)puVar3 >> 2 | *puVar3;
  *(undefined4 **)(param_1 + 0x30) = *(undefined4 **)(param_1 + 0x34);
  **(undefined4 **)(param_1 + 0x34) = 0x1000000;
  _IOConnectMapMemory(*(undefined4 *)(param_1 + 0x14),1,*(undefined4 *)puVar5,param_1 + 0x40,
                      param_1 + 0x44,1);
  iVar8 = *(int *)(param_1 + 0x40);
  *(int *)(param_1 + 0x34) = iVar8 + 0x20;
  *(int *)(param_1 + 0x30) = iVar8 + 0x1c;
  *(int *)(param_1 + 0x38) = iVar8 + 0x20 + *(int *)(iVar8 + 0x10) * 4;
  *(undefined4 *)(iVar8 + 0x1c) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0xac4) * 8 + param_1 + 0x55c + 0x570) =
       *(undefined4 *)(*(int *)(param_1 + 0x40) + 0x18);
  return;
}

/* FUN_0000ae80 @ 0xae80 (2380 bytes) */
int FUN_0000ae80(param_1)
  int param_1;
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  short sVar7;
  short sVar8;
  short sVar9;
  short sVar10;
  uint *puVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  undefined *puVar20;
  int iVar21;
  int iVar23;
  int iVar24;
  undefined8 uVar22;
  undefined4 *puVar25;
  short sVar26;
  short sVar27;
  longlong lVar28;
  float local_1e8;
  float local_1e4;
  float local_1e0;
  float local_1dc;
  float local_1d8;
  float local_1d4;
  float local_1d0;
  float local_1cc;
  undefined4 local_1c8;
  uint uStack_1c4;
  undefined4 local_1c0;
  int iStack_1bc;
  undefined4 local_1b8;
  undefined4 uStack_1b4;
  undefined4 local_1b0;
  uint uStack_1ac;
  undefined4 local_198;
  uint uStack_194;
  undefined4 local_190;
  int iStack_18c;
  undefined4 local_188;
  undefined4 uStack_184;
  undefined4 local_180;
  uint uStack_17c;
  undefined4 local_168;
  uint uStack_164;
  undefined4 local_160;
  uint uStack_15c;
  undefined4 local_158;
  int iStack_154;
  undefined4 local_150;
  undefined4 uStack_14c;
  undefined4 local_148;
  uint uStack_144;
  undefined4 local_140;
  uint uStack_13c;
  undefined4 local_138;
  int iStack_134;
  undefined4 local_130;
  undefined4 uStack_12c;
  undefined4 local_128;
  uint uStack_124;
  undefined4 local_120;
  uint uStack_11c;
  undefined4 local_118;
  uint uStack_114;
  undefined4 local_110;
  uint uStack_10c;
  undefined4 local_108;
  uint uStack_104;
  undefined4 local_100;
  uint uStack_fc;
  undefined4 local_f8;
  uint uStack_f4;
  undefined4 local_f0;
  uint uStack_ec;
  undefined4 local_e8;
  uint uStack_e4;
  undefined4 local_e0;
  uint uStack_dc;
  undefined4 local_d8;
  uint uStack_d4;
  undefined4 local_c8;
  int iStack_c4;
  undefined4 local_c0;
  uint uStack_bc;
  undefined4 local_b8;
  int iStack_b4;
  undefined4 local_b0;
  uint uStack_ac;
  undefined4 local_a8;
  uint uStack_a4;
  undefined4 local_a0;
  uint uStack_9c;
  longlong local_90;
  undefined4 local_88;
  uint uStack_84;
  longlong local_80;
  undefined4 local_78;
  uint uStack_74;
  
  iVar21 = param_1 + 0x55c;
  iVar23 = FUN_0000cf98();
  sVar7 = *(short *)(iVar23 + 0x126);
  if (sVar7 == 0) {
    iVar24 = *(int *)(iVar21 + 0x1c);
    if ((*(short *)(iVar23 + 0x12a) != iVar24) || (*(short *)(param_1 + 0x124) != 0)) {
      iVar23 = *(int *)(iVar21 + 0x20);
      goto LAB_0000b054;
    }
    iVar23 = *(int *)(iVar21 + 0x20);
    if (*(short *)(param_1 + 0x128) != iVar23) goto LAB_0000b054;
    local_1c8 = 0x43300000;
    local_1c0 = 0x43300000;
    local_1b0 = 0x43300000;
    local_198 = 0x43300000;
    local_190 = 0x43300000;
    local_180 = 0x43300000;
    uStack_1ac = (int)*(short *)(param_1 + 0x112) ^ 0x80000000;
    uStack_1c4 = (int)*(short *)(param_1 + 0x10e) ^ 0x80000000;
    uStack_17c = (int)*(short *)(param_1 + 0x110) ^ 0x80000000;
    uStack_194 = (int)*(short *)(param_1 + 0x10c) ^ 0x80000000;
    uStack_164 = (int)*(short *)(param_1 + 0x112) - (int)*(short *)(param_1 + 0x10e) ^ 0x80000000;
    uStack_15c = (int)*(short *)(param_1 + 0x110) - (int)*(short *)(param_1 + 0x10c) ^ 0x80000000;
    uStack_1b4 = *(undefined4 *)(param_1 + 0x60);
    uStack_184 = *(undefined4 *)(param_1 + 100);
    local_1b8 = 0x43300000;
    local_188 = 0x43300000;
    fVar1 = (float)((double)CONCAT44(0x43300000,iVar24) - DOUBLE_0000d418);
    fVar2 = (float)((double)CONCAT44(0x43300000,iVar23) - DOUBLE_0000d418);
    local_1e4 = (float)((double)CONCAT44(0x43300000,uStack_1b4) - DOUBLE_0000d418);
    fVar3 = (float)((double)CONCAT44(0x43300000,uStack_184) - DOUBLE_0000d418);
    local_1e8 = ((float)((double)CONCAT44(0x43300000,uStack_1c4) - DOUBLE_0000d420) * fVar1) /
                local_1e4;
    local_1e4 = ((float)((double)CONCAT44(0x43300000,uStack_1ac) - DOUBLE_0000d420) * fVar1) /
                local_1e4;
    local_1e0 = ((float)((double)CONCAT44(0x43300000,uStack_194) - DOUBLE_0000d420) * fVar2) / fVar3
    ;
    local_160 = 0x43300000;
    local_168 = 0x43300000;
    local_1d0 = 0.0;
    local_1d8 = 0.0;
    local_1cc = (float)((double)CONCAT44(0x43300000,uStack_15c) - DOUBLE_0000d420);
    local_1d4 = (float)((double)CONCAT44(0x43300000,uStack_164) - DOUBLE_0000d420);
    local_1dc = ((float)((double)CONCAT44(0x43300000,uStack_17c) - DOUBLE_0000d420) * fVar2) / fVar3
    ;
    iStack_1bc = iVar24;
    iStack_18c = iVar23;
  }
  else {
    iVar23 = *(int *)(iVar21 + 0x20);
    iVar24 = *(int *)(iVar21 + 0x1c);
LAB_0000b054:
    sVar8 = *(short *)(param_1 + 0x112);
    local_158 = 0x43300000;
    local_140 = 0x43300000;
    uStack_13c = (int)sVar8 ^ 0x80000000;
    uStack_14c = *(undefined4 *)(param_1 + 0x60);
    uStack_114 = (int)sVar7 ^ 0x80000000;
    local_150 = 0x43300000;
    sVar9 = *(short *)(param_1 + 0x10e);
    local_118 = 0x43300000;
    local_148 = 0x43300000;
    local_138 = 0x43300000;
    local_128 = 0x43300000;
    local_120 = 0x43300000;
    uStack_124 = (int)*(short *)(param_1 + 0x10c) ^ 0x80000000;
    uStack_144 = (int)sVar9 ^ 0x80000000;
    uStack_11c = (int)*(short *)(param_1 + 0x110) ^ 0x80000000;
    fVar1 = (float)((double)CONCAT44(0x43300000,iVar24) - DOUBLE_0000d418);
    uStack_12c = *(undefined4 *)(param_1 + 100);
    local_130 = 0x43300000;
    fVar2 = (float)((double)CONCAT44(0x43300000,uStack_14c) - DOUBLE_0000d418);
    fVar12 = (fVar1 * (float)((double)CONCAT44(0x43300000,uStack_13c) - DOUBLE_0000d420)) / fVar2;
    fVar3 = (float)((double)CONCAT44(0x43300000,uStack_114) - DOUBLE_0000d420);
    fVar4 = (float)((double)CONCAT44(0x43300000,iVar23) - DOUBLE_0000d418);
    fVar2 = ((float)((double)CONCAT44(0x43300000,uStack_144) - DOUBLE_0000d420) * fVar1) / fVar2;
    fVar1 = (float)((double)CONCAT44(0x43300000,uStack_12c) - DOUBLE_0000d418);
    fVar15 = (fVar4 * (float)((double)CONCAT44(0x43300000,uStack_11c) - DOUBLE_0000d420)) / fVar1;
    fVar1 = ((float)((double)CONCAT44(0x43300000,uStack_124) - DOUBLE_0000d420) * fVar4) / fVar1;
    iStack_154 = iVar24;
    iStack_134 = iVar23;
    if (fVar12 <= fVar3) goto LAB_0000b7d0;
    if (fVar12 <= fVar3) {
      sVar27 = *(short *)(param_1 + 0x12a);
LAB_0000b1e4:
      uStack_104 = (int)sVar27 ^ 0x80000000;
      local_108 = 0x43300000;
      fVar4 = (float)((double)CONCAT44(0x43300000,uStack_104) - DOUBLE_0000d420);
      if (fVar4 <= fVar2) goto LAB_0000b7d0;
      fVar13 = fVar2;
      if (fVar2 - fVar3 < 0.0) {
        fVar13 = fVar3;
      }
      if (-(fVar2 - fVar3) < 0.0) {
        fVar13 = fVar2;
      }
    }
    else {
      sVar27 = *(short *)(param_1 + 0x12a);
      local_110 = 0x43300000;
      uStack_10c = (int)sVar27 ^ 0x80000000;
      if ((float)((double)CONCAT44(0x43300000,uStack_10c) - DOUBLE_0000d420) <= fVar12)
      goto LAB_0000b1e4;
      fVar13 = fVar3;
      fVar4 = fVar12;
      if (fVar3 <= fVar2) {
        fVar13 = fVar2;
      }
    }
    sVar10 = *(short *)(param_1 + 0x124);
    local_100 = 0x43300000;
    uStack_fc = (int)sVar10 ^ 0x80000000;
    fVar3 = (float)((double)CONCAT44(0x43300000,uStack_fc) - DOUBLE_0000d420);
    if (fVar15 <= fVar3) goto LAB_0000b7d0;
    if (fVar15 <= fVar3) {
      sVar26 = *(short *)(param_1 + 0x128);
LAB_0000b2b8:
      uStack_ec = (int)sVar26 ^ 0x80000000;
      local_f0 = 0x43300000;
      fVar5 = (float)((double)CONCAT44(0x43300000,uStack_ec) - DOUBLE_0000d420);
      if (fVar5 <= fVar1) goto LAB_0000b7d0;
      fVar16 = fVar1;
      if (fVar1 - fVar3 < 0.0) {
        fVar16 = fVar3;
      }
      if (-(fVar1 - fVar3) < 0.0) {
        fVar16 = fVar1;
      }
    }
    else {
      sVar26 = *(short *)(param_1 + 0x128);
      local_f8 = 0x43300000;
      uStack_f4 = (int)sVar26 ^ 0x80000000;
      if ((float)((double)CONCAT44(0x43300000,uStack_f4) - DOUBLE_0000d420) <= fVar15)
      goto LAB_0000b2b8;
      fVar16 = fVar3;
      fVar5 = fVar15;
      if (fVar3 <= fVar1) {
        fVar16 = fVar1;
      }
    }
    uStack_bc = (int)sVar27 - (int)sVar7 ^ 0x80000000;
    local_c8 = 0x43300000;
    local_c0 = 0x43300000;
    local_b8 = 0x43300000;
    local_b0 = 0x43300000;
    local_a8 = 0x43300000;
    local_a0 = 0x43300000;
    local_e8 = 0x43300000;
    local_e0 = 0x43300000;
    local_d8 = 0x43300000;
    uStack_ac = (int)sVar26 - (int)sVar10 ^ 0x80000000;
    uStack_a4 = (int)sVar27 + (int)sVar7 ^ 0x80000000;
    uStack_9c = (int)sVar26 + (int)sVar10 ^ 0x80000000;
    uStack_e4 = (int)sVar8 - (int)sVar9 ^ 0x80000000;
    uStack_d4 = (int)*(short *)(param_1 + 0x110) - (int)*(short *)(param_1 + 0x10c) ^ 0x80000000;
    uStack_dc = (int)sVar8 - (int)sVar9 ^ 0x80000000;
    fVar3 = (float)((double)CONCAT44(0x43300000,iVar24) - DOUBLE_0000d418);
    fVar6 = (float)((double)CONCAT44(0x43300000,iVar23) - DOUBLE_0000d418);
    fVar18 = fVar3 / (float)((double)CONCAT44(0x43300000,uStack_bc) - DOUBLE_0000d420);
    local_1d0 = (float)((double)CONCAT44(0x43300000,uStack_d4) - DOUBLE_0000d420);
    fVar19 = fVar6 / (float)((double)CONCAT44(0x43300000,uStack_ac) - DOUBLE_0000d420);
    fVar14 = (float)((double)CONCAT44(0x43300000,uStack_a4) - DOUBLE_0000d420) * FLOAT_0000d464;
    fVar17 = (float)((double)CONCAT44(0x43300000,uStack_9c) - DOUBLE_0000d420) * FLOAT_0000d464;
    local_1d8 = ((fVar13 - fVar2) / (fVar12 - fVar2)) *
                (float)((double)CONCAT44(0x43300000,uStack_e4) - DOUBLE_0000d420);
    local_1d4 = (FLOAT_0000d43c - (fVar12 - fVar4) / (fVar12 - fVar2)) *
                (float)((double)CONCAT44(0x43300000,uStack_dc) - DOUBLE_0000d420);
    local_1cc = (FLOAT_0000d43c - (fVar15 - fVar5) / (fVar15 - fVar1)) * local_1d0;
    local_1d0 = ((fVar16 - fVar1) / (fVar15 - fVar1)) * local_1d0;
    local_78 = 0x43300000;
    local_88 = 0x43300000;
    local_1e4 = fVar18 * (fVar4 - fVar14) + fVar14;
    fVar14 = fVar18 * (fVar13 - fVar14) + fVar14;
    local_1e8 = fVar14;
    if (fVar14 < 0.0) {
      local_1e8 = FLOAT_0000d430;
    }
    uStack_84 = (uint)(fVar19 * (fVar16 - fVar17) + fVar17);
    local_90 = (longlong)(int)uStack_84;
    if (-fVar14 < 0.0) {
      local_1e8 = fVar14;
    }
    uStack_74 = (uint)(fVar19 * (fVar5 - fVar17) + fVar17);
    local_80 = (longlong)(int)uStack_74;
    fVar1 = fVar3;
    if (local_1e4 - fVar3 < 0.0) {
      fVar1 = local_1e4;
    }
    if (-(local_1e4 - fVar3) < 0.0) {
      local_1e4 = fVar1;
    }
    uStack_84 = uStack_84 ^ 0x80000000;
    uStack_74 = uStack_74 ^ 0x80000000;
    fVar1 = (float)((double)CONCAT44(0x43300000,uStack_84) - DOUBLE_0000d420);
    local_1dc = (float)((double)CONCAT44(0x43300000,uStack_74) - DOUBLE_0000d420);
    local_1e0 = fVar1;
    if (fVar1 < 0.0) {
      local_1e0 = FLOAT_0000d430;
    }
    if (-fVar1 < 0.0) {
      local_1e0 = fVar1;
    }
    fVar1 = fVar6;
    if (local_1dc - fVar6 < 0.0) {
      fVar1 = local_1dc;
    }
    iStack_c4 = iVar24;
    iStack_b4 = iVar23;
    if (-(local_1dc - fVar6) < 0.0) {
      local_1dc = fVar1;
    }
  }
  puVar25 = *(undefined4 **)(param_1 + 0x34);
  if (*(undefined4 **)(param_1 + 0x38) <= puVar25 + 0x70) {
    puVar11 = *(uint **)(param_1 + 0x30);
    *puVar11 = (int)puVar25 - (int)puVar11 >> 2 | *puVar11;
    puVar20 = PTR_0000f1a0;
    *(undefined4 **)(param_1 + 0x30) = *(undefined4 **)(param_1 + 0x34);
    **(undefined4 **)(param_1 + 0x34) = 0x1000000;
    _IOConnectMapMemory(*(undefined4 *)(param_1 + 0x14),1,*(undefined4 *)puVar20,param_1 + 0x40,
                        param_1 + 0x44,1);
    iVar21 = *(int *)(param_1 + 0x40);
    *(int *)(param_1 + 0x34) = iVar21 + 0x20;
    *(int *)(param_1 + 0x30) = iVar21 + 0x1c;
    *(int *)(param_1 + 0x38) = iVar21 + 0x20 + *(int *)(iVar21 + 0x10) * 4;
    *(undefined4 *)(iVar21 + 0x1c) = 0;
    puVar25 = *(undefined4 **)(param_1 + 0x34);
  }
  puVar11 = *(uint **)(param_1 + 0x30);
  *(undefined4 **)(param_1 + 0x34) = puVar25 + 0x70;
  *puVar11 = (int)puVar25 - (int)puVar11 >> 2 | *puVar11;
  *(undefined4 **)(param_1 + 0x30) = puVar25;
  *puVar25 = 0xb000000;
  puVar25[1] = 2;
  puVar25[2] = 1;
  puVar25 = puVar25 + 3;
  lVar28 = 10;
  do {
    *puVar25 = 0x80000000;
    puVar25 = puVar25 + 1;
    lVar28 = lVar28 + -1;
  } while (lVar28 != 0);
  uVar22 = ((int (*)())FUN_000096a0)();
  puVar25 = (undefined4 *)((int (*)())FUN_00009700)(uVar22,1);
  *puVar25 = 0x1100;
  puVar25[1] = 0xa92;
  puVar25[2] = 0x1110;
  puVar25[3] = 0;
  puVar25[4] = 0x1120;
  puVar25[5] = ((int)*(short *)(param_1 + 0x112) - (int)*(short *)(param_1 + 0x10e)) - 1U |
               (((int)*(short *)(param_1 + 0x110) - (int)*(short *)(param_1 + 0x10c)) + -1) * 0x800
               | 0x80000000;
  puVar25[6] = 0x1130;
  puVar25[7] = 0xa60c;
  puVar25[8] = 0x1140;
  puVar25[9] = *(int *)(param_1 + 0x68) + -1;
  puVar25[10] = ((unsigned char *)0x00001041);
  puVar25[0xb] = 1;
  puVar25 = (undefined4 *)((int (*)())FUN_000099b0)(puVar25 + 0xc,&DAT_0000ec84,2,0,0,1);
  *puVar25 = 0x11a9;
  puVar25[1] = ((unsigned char *)0x00001b00);
  puVar25[2] = 0x11aa;
  puVar25[3] = 0xf;
  puVar25[4] = 0x11ab;
  puVar25[5] = 0xf;
  puVar25[6] = 0x11ac;
  puVar25[7] = 0xf;
  puVar25[8] = 0x1381;
  puVar25[9] = 0x27260005;
  ((int (*)())FUN_00009ac0)(puVar25 + 10,&local_1d8,&local_1e8,
               (longlong)*(short *)(param_1 + 0x112) - (longlong)*(short *)(param_1 + 0x10e),
               (longlong)*(short *)(param_1 + 0x110) - (longlong)*(short *)(param_1 + 0x10c));
LAB_0000b7d0:
  FUN_0000cfe8();
  return;
}

/* FUN_0000b7f0 @ 0xb7f0 (964 bytes) */
int FUN_0000b7f0(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  longlong param_3;
{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined *puVar5;
  undefined8 uVar6;
  undefined4 *puVar7;
  longlong lVar8;
  float local_78;
  float local_74;
  float local_70;
  float local_6c;
  undefined4 local_68;
  float local_64;
  undefined4 local_60;
  float local_5c;
  undefined4 local_58;
  uint uStack_54;
  undefined4 local_50;
  uint uStack_4c;
  undefined4 local_48;
  uint uStack_44;
  undefined4 local_40;
  uint uStack_3c;
  undefined4 local_38;
  undefined4 uStack_34;
  undefined4 local_30;
  undefined4 uStack_2c;
  
  puVar7 = *(undefined4 **)(param_1 + 0x34);
  if (*(undefined4 **)(param_1 + 0x38) <= puVar7 + 0xb0) {
    puVar1 = *(uint **)(param_1 + 0x30);
    *puVar1 = (int)puVar7 - (int)puVar1 >> 2 | *puVar1;
    puVar5 = PTR_0000f1a0;
    *(undefined4 **)(param_1 + 0x30) = *(undefined4 **)(param_1 + 0x34);
    **(undefined4 **)(param_1 + 0x34) = 0x1000000;
    _IOConnectMapMemory(*(undefined4 *)(param_1 + 0x14),1,*(undefined4 *)puVar5,param_1 + 0x40,
                        param_1 + 0x44,1);
    iVar2 = *(int *)(param_1 + 0x40);
    *(int *)(param_1 + 0x34) = iVar2 + 0x20;
    *(int *)(param_1 + 0x30) = iVar2 + 0x1c;
    *(int *)(param_1 + 0x38) = iVar2 + 0x20 + *(int *)(iVar2 + 0x10) * 4;
    *(undefined4 *)(iVar2 + 0x1c) = 0;
    puVar7 = *(undefined4 **)(param_1 + 0x34);
  }
  puVar1 = *(uint **)(param_1 + 0x30);
  *(undefined4 **)(param_1 + 0x34) = puVar7 + 0xb0;
  *puVar1 = (int)puVar7 - (int)puVar1 >> 2 | *puVar1;
  *(undefined4 **)(param_1 + 0x30) = puVar7;
  *puVar7 = 0xa000000;
  puVar7[1] = param_2;
  puVar7[2] = (uint)(param_3 != 0);
  puVar7[3] = *(undefined4 *)(param_1 + 0x11c);
  puVar7 = puVar7 + 4;
  lVar8 = 0x10;
  do {
    *puVar7 = 0x80000000;
    puVar7 = puVar7 + 1;
    lVar8 = lVar8 + -1;
  } while (lVar8 != 0);
  uVar6 = ((int (*)())FUN_000096a0)();
  puVar7 = (undefined4 *)((int (*)())FUN_00009700)(uVar6,1);
  *puVar7 = 0x1100;
  puVar7[1] = 0x1492;
  puVar7[2] = 0x1110;
  puVar7[3] = 0;
  puVar7[4] = 0x1120;
  uVar3 = *(uint *)(param_1 + 0x57c);
  uVar4 = *(uint *)(param_1 + 0x578);
  puVar7[5] = (uVar3 - 1) * 0x800 | uVar4 - 1 | 0x80000000;
  puVar7[6] = 0x1130;
  puVar7[7] = 0x10120800;
  puVar7[8] = 0x1101;
  puVar7[9] = 0x10001492;
  puVar7[10] = 0x1111;
  puVar7[0xb] = 0;
  puVar7[0xc] = 0x1121;
  puVar7[0xd] = ((uVar3 >> 1) - 1) * 0x800 | (uVar4 >> 1) - 1 | 0x80000000;
  puVar7[0xe] = 0x1131;
  puVar7[0xf] = 0x18044803;
  puVar7[0x10] = ((unsigned char *)0x00001041);
  puVar7[0x11] = 3;
  puVar7 = (undefined4 *)((int (*)())FUN_000099b0)(puVar7 + 0x12,&DAT_0000eb7c,7,&DAT_0000eb2c,5,3);
  *puVar7 = 0x11a9;
  puVar7[1] = ((unsigned char *)0x00001b00);
  puVar7[2] = 0x11aa;
  puVar7[3] = 0xf;
  puVar7[4] = 0x11ab;
  puVar7[5] = 0xf;
  puVar7[6] = 0x11ac;
  puVar7[7] = 0xf;
  uStack_2c = *(undefined4 *)(param_1 + 0x57c);
  uStack_34 = *(undefined4 *)(param_1 + 0x578);
  local_58 = 0x43300000;
  local_50 = 0x43300000;
  local_48 = 0x43300000;
  local_40 = 0x43300000;
  local_30 = 0x43300000;
  local_38 = 0x43300000;
  uStack_54 = (int)*(short *)(param_1 + 0x126) ^ 0x80000000;
  uStack_4c = (int)*(short *)(param_1 + 0x12a) ^ 0x80000000;
  uStack_44 = (int)*(short *)(param_1 + 0x124) ^ 0x80000000;
  uStack_3c = (int)*(short *)(param_1 + 0x128) ^ 0x80000000;
  local_60 = 0;
  local_68 = 0;
  local_5c = (float)((double)CONCAT44(0x43300000,uStack_2c) - DOUBLE_0000d418);
  local_78 = (float)((double)CONCAT44(0x43300000,uStack_54) - DOUBLE_0000d420);
  local_74 = (float)((double)CONCAT44(0x43300000,uStack_4c) - DOUBLE_0000d420);
  local_6c = (float)((double)CONCAT44(0x43300000,uStack_3c) - DOUBLE_0000d420);
  local_70 = (float)((double)CONCAT44(0x43300000,uStack_44) - DOUBLE_0000d420);
  local_64 = (float)((double)CONCAT44(0x43300000,uStack_34) - DOUBLE_0000d418);
  ((int (*)())FUN_00009ac0)(puVar7 + 8,&local_78,&local_68);
  return;
}

/* FUN_0000bf20 @ 0xbf20 (72 bytes) */
int FUN_0000bf20(param_1, param_2, param_3)
  int param_1;
  ulonglong param_2;
  longlong param_3;
{
  longlong lVar1;
  longlong lVar2;
  ulonglong uVar3;
  
  uVar3 = (ulonglong)*(uint *)(param_1 + 0x144);
  lVar1 = 0;
  lVar2 = (param_2 & uVar3 - 1) + (param_3 - uVar3);
  if (0 < lVar2) {
    do {
      dataCacheBlockStore((-uVar3 & param_2) + lVar1);
      lVar1 = uVar3 + lVar1;
    } while ((int)lVar1 < (int)lVar2);
  }
  dataCacheBlockFlush((-uVar3 & param_2) + lVar1);
  return;
}

