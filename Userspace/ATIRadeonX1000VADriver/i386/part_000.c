#include "decls.h"

/* FUN_00000ca2 @ 0xca2 (17 bytes) */
int FUN_00000ca2(param_1)
  undefined4 *param_1;
{
  *param_1 = 1;
  return;
}

/* FUN_00000cb3 @ 0xcb3 (68 bytes) */
int FUN_00000cb3(param_1)
  undefined4 *param_1;
{
  int iVar1;
  
  iVar1 = (*(code *)param_1[1])(0xca2,param_1,param_1);
  if (iVar1 != 0) {
    *param_1 = 0xffffffff;
  }
  return;
}

/* FUN_00000cf7 @ 0xcf7 (117 bytes) */
int FUN_00000cf7(param_1, param_2)
  code *param_1;
  code *param_2;
{
  int iVar1;
  int local_20;
  int local_14;
  code *local_10;
  
  local_14 = 0;
  local_10 = param_1;
  iVar1 = (*param_1)(0xcb3,&local_14,&local_14);
  if (iVar1 == 0) {
    (*param_2)(&local_14);
    if (local_14 == 0) {
      (*param_2)(&local_14);
      local_14 = 0;
    }
    local_20 = local_14;
  }
  else {
    local_20 = -1;
  }
  return local_20;
}

/* FUN_00000d6c @ 0xd6c (365 bytes) */
int FUN_00000d6c()
{
  int iVar1;
  undefined4 uVar2;
  void *local_1c;
  void *local_18;
  int local_14;
  int local_10;
  
  iVar1 = __keymgr_get_and_lock_processwide_ptr_2(0xe,&local_1c);
  if (iVar1 != 0) {
    return (void *)0x0;
  }
  local_18 = local_1c;
  if ((local_1c == (void *)0x0) && (local_18 = _calloc(0x14,1), local_18 == (void *)0x0)) {
    return (void *)0x0;
  }
  if (*(char *)((int)local_18 + 3) != '\0') {
    return local_18;
  }
  local_14 = _dlopen("/usr/lib/libSystem.B.dylib",0x10);
  if (local_14 != 0) {
    uVar2 = _dlsym(local_14,"__cxa_atexit");
    *(undefined4 *)((int)local_18 + 8) = uVar2;
    uVar2 = _dlsym(local_14,"__cxa_finalize");
    *(undefined4 *)((int)local_18 + 0xc) = uVar2;
    if (((*(int *)((int)local_18 + 8) != 0) && (*(int *)((int)local_18 + 0xc) != 0)) &&
       (local_10 = ((int (*)())FUN_00000cf7)(*(undefined4 *)((int)local_18 + 8),
                                *(undefined4 *)((int)local_18 + 0xc)), local_10 != -1)) {
      if (local_10 == 0) {
        *(undefined1 *)((int)local_18 + 3) = 2;
      }
      else {
        uVar2 = _dlsym(local_14,"atexit");
        *(undefined4 *)((int)local_18 + 0x10) = uVar2;
        if (*(int *)((int)local_18 + 0x10) == 0) goto LAB_00000eb6;
        *(undefined1 *)((int)local_18 + 3) = 0x10;
      }
      return local_18;
    }
  }
LAB_00000eb6:
  __keymgr_set_and_unlock_processwide_ptr(0xe,local_18);
  return (void *)0x0;
}

/* FUN_00000ed9 @ 0xed9 (153 bytes) */
int FUN_00000ed9(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  undefined4 *puVar1;
  int iVar2;
  undefined4 local_24;
  undefined4 local_20;
  
  puVar1 = _malloc(0x10);
  if (puVar1 == (undefined4 *)0x0) {
    __keymgr_set_and_unlock_processwide_ptr(0xe,param_1);
    local_24 = 0xffffffff;
  }
  else {
    puVar1[1] = *param_2;
    puVar1[2] = param_2[1];
    puVar1[3] = param_2[2];
    *puVar1 = *(undefined4 *)(param_1 + 4);
    *(undefined4 **)(param_1 + 4) = puVar1;
    iVar2 = __keymgr_set_and_unlock_processwide_ptr(0xe,param_1);
    if (iVar2 == 0) {
      local_20 = 0;
    }
    else {
      local_20 = 0xffffffff;
    }
    local_24 = local_20;
  }
  return local_24;
}

/* FUN_00000f72 @ 0xf72 (188 bytes) */
int FUN_00000f72(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  undefined4 *puVar1;
  uint uVar2;
  byte local_20;
  
  while( true ) {
    puVar1 = *(undefined4 **)(param_1 + 4);
    if (puVar1 == (undefined4 *)0x0) {
      return param_1;
    }
    if (puVar1 == param_2) break;
    *(undefined4 *)(param_1 + 4) = *puVar1;
    __keymgr_set_and_unlock_processwide_ptr(0xe,param_1);
    if ((uint)puVar1[2] < 6) {
      local_20 = (byte)puVar1[2];
      uVar2 = 1 << (local_20 & 0x1f);
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
    param_1 = __keymgr_get_and_lock_processwide_ptr(0xe);
    if (param_1 == 0) {
      return 0;
    }
  }
  return param_1;
}

/* FUN_0000102e @ 0x102e (209 bytes) */
int FUN_0000102e(param_1)
  undefined4 *param_1;
{
  int local_18;
  undefined4 local_14;
  undefined1 local_d;
  
  local_14 = 0;
  local_d = 0;
  local_18 = __keymgr_get_and_lock_processwide_ptr(0xe);
  if (local_18 != 0) {
    local_d = *(undefined1 *)(local_18 + 2);
    *(undefined1 *)(local_18 + 2) = 1;
    local_14 = *(undefined4 *)(local_18 + 4);
    __keymgr_set_and_unlock_processwide_ptr(0xe,local_18);
  }
  if (param_1[1] == 0) {
    (*(code *)*param_1)();
  }
  else {
    (*(code *)*param_1)(param_1[2]);
  }
  if (local_18 != 0) {
    local_18 = __keymgr_get_and_lock_processwide_ptr(0xe);
  }
  if (local_18 != 0) {
    local_18 = ((int (*)())FUN_00000f72)(local_18,local_14);
  }
  if (local_18 != 0) {
    *(undefined1 *)(local_18 + 2) = local_d;
    __keymgr_set_and_unlock_processwide_ptr(0xe,local_18);
  }
  return;
}

/* FUN_000010ff @ 0x10ff (406 bytes) */
int FUN_000010ff(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  code *pcVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_30;
  
  iVar2 = ((int (*)())FUN_00000d6c)();
  if (iVar2 == 0) {
    local_30 = 0xffffffff;
  }
  else if ((*(char *)(iVar2 + 2) == '\0') && (*(char *)(iVar2 + 3) != '\x01')) {
    if (*(byte *)(iVar2 + 3) < 0x10) {
      pcVar1 = *(code **)(iVar2 + 8);
      iVar2 = __keymgr_set_and_unlock_processwide_ptr(0xe,iVar2);
      if (iVar2 == 0) {
        puVar3 = _malloc(0xc);
        if (puVar3 == (undefined4 *)0x0) {
          local_30 = 0xffffffff;
        }
        else {
          *puVar3 = *param_1;
          puVar3[1] = param_1[1];
          puVar3[2] = param_1[2];
          local_30 = (*pcVar1)(FUN_0000102e,puVar3,param_2);
        }
      }
      else {
        local_30 = 0xffffffff;
      }
    }
    else if (param_1[1] == 0) {
      pcVar1 = *(code **)(iVar2 + 0x10);
      iVar2 = __keymgr_set_and_unlock_processwide_ptr(0xe,iVar2);
      if (iVar2 == 0) {
        local_30 = (*pcVar1)(*param_1);
      }
      else {
        local_30 = 0xffffffff;
      }
    }
    else {
      pcVar1 = *(code **)(iVar2 + 8);
      iVar2 = __keymgr_set_and_unlock_processwide_ptr(0xe,iVar2);
      if (iVar2 == 0) {
        local_30 = (*pcVar1)(*param_1,param_1[2],param_2);
      }
      else {
        local_30 = 0xffffffff;
      }
    }
  }
  else {
    local_30 = ((int (*)())FUN_00000ed9)(iVar2,param_1);
  }
  return local_30;
}

/* FUN_00001295 @ 0x1295 (45 bytes) */
int FUN_00001295(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  local_18 = param_1;
  local_14 = 1;
  local_10 = param_2;
  ((int (*)())FUN_000010ff)(&local_18,param_3);
  return;
}

/* FUN_000012c2 @ 0x12c2 (54 bytes) */
int FUN_000012c2(param_1)
  undefined4 param_1;
{
  undefined4 local_18;
  undefined4 local_14;
  
  local_18 = param_1;
  local_14 = 0;
  ((int (*)())FUN_000010ff)(&local_18,PTR_0000e06e);
  return;
}

/* _AVACreateRenderer @ 0x12f8 (439 bytes) */
int _AVACreateRenderer(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 *param_2;
  undefined4 *param_3;
{
  undefined4 uVar1;
  undefined4 *puVar2;
  void *pvVar3;
  int iVar4;
  
  if (param_1 == (undefined4 *)0x0) {
    uVar1 = 0xfffffff9;
  }
  else {
    puVar2 = _calloc(1,100);
    if (puVar2 != (undefined4 *)0x0) {
      pvVar3 = _calloc(1,0x14);
      puVar2[3] = pvVar3;
      if (pvVar3 != (void *)0x0) {
        *puVar2 = 0x1020000;
        puVar2[1] = 1;
        *param_3 = 0x1020000;
        param_3[1] = 1;
        param_3[2] = param_3[2] | 0x57;
        param_3[3] = 2;
        param_3[4] = 4;
        param_3[5] = 2;
        _strlcpy((char *)(param_3 + 6),"ATIVADriver ",0x100);
        *(undefined4 *)(puVar2[3] + 8) = *param_2;
        *(undefined4 *)(puVar2[3] + 0xc) = param_2[2];
        *(undefined4 *)(puVar2[3] + 0x10) = param_2[3];
        *(undefined4 *)puVar2[3] = param_2[1];
        *(undefined4 *)(puVar2[3] + 4) = 0;
        iVar4 = 0;
        do {
          if ((*(uint *)puVar2[3] & 1 << ((byte)iVar4 & 0x1f)) != 0) {
            ((uint *)puVar2[3])[1] = iVar4 + 1;
          }
          iVar4 = iVar4 + 1;
        } while (iVar4 < 0x20);
        puVar2[4] = PTR_FUN_0000e0d6;
        puVar2[5] = PTR_LAB_00001c60_4_0000e0ae;
        puVar2[6] = PTR_FUN_0000e0c6;
        puVar2[7] = PTR_LAB_0000e0a2;
        puVar2[8] = PTR_LAB_00001e81_1_0000e0de;
        puVar2[9] = PTR_FUN_0000e076;
        puVar2[10] = PTR_LAB_00001ef7_1_0000e0be;
        puVar2[0xb] = PTR_FUN_0000e0ce;
        puVar2[0xc] = 0;
        puVar2[0xd] = PTR_FUN_0000e08a;
        puVar2[0xe] = PTR_FUN_0000e0ba;
        puVar2[0xf] = PTR_FUN_0000e07e;
        puVar2[0x10] = PTR_LAB_00002790_4_0000e09e;
        puVar2[0x11] = PTR_LAB_00002906_4_0000e092;
        puVar2[0x12] = PTR_FUN_0000e0b6;
        puVar2[0x13] = PTR_FUN_0000e07a;
        puVar2[0x14] = PTR_FUN_0000e0c2;
        puVar2[0x15] = PTR_FUN_0000e0d2;
        puVar2[0x16] = FUN_000014af;
        *param_1 = puVar2;
        return 0;
      }
    }
    uVar1 = 0xfffffffd;
  }
  return uVar1;
}

/* FUN_000014af @ 0x14af (92 bytes) */
int FUN_000014af(param_1)
  void *param_1;
{
  if (param_1 != (void *)0x0) {
    _free(*(void **)PTR_DAT_0000e082);
    _free(*(void **)PTR_DAT_0000e0ca);
    _free(*(void **)((int)param_1 + 0xc));
    _free(param_1);
    return 0;
  }
  return 0xfffffff9;
}

/* _AVACreateRendererDisplayExt @ 0x150b (119 bytes) */
int _AVACreateRendererDisplayExt(param_1)
  undefined4 *param_1;
{
  undefined4 *puVar1;
  
  puVar1 = _calloc(1,0x1c);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0x1020000;
    puVar1[1] = 0;
    puVar1[2] = PTR_FUN_0000e0a6;
    puVar1[3] = PTR_FUN_0000e072;
    puVar1[4] = PTR_FUN_0000e09a;
    puVar1[5] = PTR_LAB_0000e08e;
    *(undefined4 **)PTR_DAT_0000e0ca = puVar1;
    *param_1 = puVar1;
    return 0;
  }
  return 0xfffffffd;
}

/* _AVACreateRendererDVDExt @ 0x1582 (121 bytes) */
int _AVACreateRendererDVDExt(param_1)
  undefined4 *param_1;
{
  undefined4 *puVar1;
  
  puVar1 = _calloc(1,0x20);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0x1020000;
    puVar1[2] = PTR_LAB_0000401e_4_0000e0da;
    puVar1[3] = PTR_LAB_0000e086;
    puVar1[4] = PTR_FUN_0000e0b2;
    puVar1[5] = PTR_FUN_0000e096;
    puVar1[6] = PTR_FUN_0000e0aa;
    *param_1 = puVar1;
    *(undefined4 **)PTR_DAT_0000e082 = puVar1;
    return 0;
  }
  return 0xfffffffd;
}

/* _AVAGetRendererInfo @ 0x15fb (83 bytes) */
int _AVAGetRendererInfo(param_1)
  undefined4 *param_1;
{
  *param_1 = 0x1020000;
  param_1[2] = param_1[2] | 0x57;
  param_1[3] = 2;
  param_1[4] = 4;
  param_1[5] = 2;
  _strlcpy((char *)(param_1 + 6),"ATIVADriver ",0x100);
  return 0;
}

/* FUN_00001650 @ 0x1650 (1084 bytes) */
int FUN_00001650(param_1, param_2, param_3)
  uint param_1;
  undefined4 *param_2;
  uint *param_3;
{
  uint uVar1;
  uint *puVar2;
  int iVar3;
  void *pvVar4;
  uint *puVar5;
  int iVar6;
  uint local_2c;
  uint local_28;
  undefined4 local_24;
  undefined4 local_20 [4];
  
  if ((param_1 == 0) || (param_2 == (undefined4 *)0x0)) {
    return 0xfffffff9;
  }
  if (*param_3 < 6) {
    uVar1 = _CGDisplayIDToOpenGLDisplayMask(param_3[2]);
    if (((uVar1 & **(uint **)(param_1 + 0xc)) == 0) || ((uVar1 & ~**(uint **)(param_1 + 0xc)) != 0))
    {
      return 0xfffffffb;
    }
    puVar2 = _calloc(1,0x153dc);
    if (puVar2 != (uint *)0x0) {
      iVar3 = *(int *)(*(int *)(param_1 + 0xc) + 4);
      if ((iVar3 == 0) || ((uVar1 & 1) != 0)) {
        iVar6 = 0;
      }
      else {
        iVar6 = 0;
        do {
          iVar6 = iVar6 + 1;
          if (iVar6 == iVar3) break;
        } while ((uVar1 & 1 << ((byte)iVar6 & 0x1f)) == 0);
      }
      uVar1 = *(uint *)(*(int *)(*(int *)(param_1 + 0xc) + 8) + iVar6 * 4);
      puVar2[4] = uVar1;
      *puVar2 = param_3[2];
      puVar2[1] = param_3[3];
      puVar2[2] = param_3[4];
      puVar2[3] = param_3[5];
      puVar2[0x15] = *param_3;
      puVar2[0x16] = param_3[1];
      puVar2[0x14] = param_1;
      puVar2[6] = 0x4024;
      puVar2[5] = 0;
      iVar3 = _IOServiceOpen(uVar1,*(undefined4 *)PTR_0000e0e6,3,puVar2 + 5);
      if (iVar3 == 0) {
        local_20[0] = 2;
        iVar3 = _io_connect_method_scalarI_scalarO(puVar2[5],1,0,0,puVar2 + 8,local_20);
        if (iVar3 == 0) {
          puVar2[0x10] = 0;
          iVar3 = _IOConnectMapMemory(puVar2[5],1,*(undefined4 *)PTR_0000e0e6,puVar2 + 0x10,
                                      puVar2 + 0x11,1);
          if (iVar3 == 0) {
            puVar5 = puVar2 + 0x157;
            _memset(puVar5,0,0x14e80);
            puVar2[0x514a] = 0;
            iVar3 = _IOConnectMapMemory(puVar2[5],4,*(undefined4 *)PTR_0000e0e6,puVar2 + 0x514a,
                                        puVar2 + 0x514b,1);
            if (iVar3 == 0) {
              puVar2[0x514c] = 0;
              iVar3 = _IOConnectMapMemory(puVar2[5],5,*(undefined4 *)PTR_0000e0e6,puVar2 + 0x514c,
                                          puVar2 + 0x514d,1);
              if (iVar3 == 0) {
                puVar2[0x12] = 0;
                iVar3 = _IOConnectMapMemory(puVar2[5],2,*(undefined4 *)PTR_0000e0e6,puVar2 + 0x12,
                                            puVar2 + 0x13,1);
                if ((iVar3 == 0) &&
                   (iVar3 = (**(code **)(*(int *)(param_1 + 0xc) + 0x10))
                                      (puVar2[1],puVar2[2],puVar2[3],puVar2[6] & 0x803f,*puVar2),
                   iVar3 == 0)) {
                  local_2c = puVar2[3];
                  local_28 = puVar2[6] & 0xffff4000;
                  local_24 = 1;
                  iVar3 = _io_connect_method_scalarI_structureI(puVar2[5],0,&local_2c,3,0,0);
                  if (iVar3 == 0) {
                    if ((*(uint *)PTR_0000e0e2 & 8) == 0) {
                      puVar2[0x51] = (-(uint)((*(uint *)PTR_0000e0e2 & 0x10) == 0) & 0xffffffa0) +
                                     0x80;
                    }
                    else {
                      puVar2[0x51] = 0x40;
                    }
                    pvVar4 = _malloc(16000);
                    puVar2[0x549a] = (uint)pvVar4;
                    if (pvVar4 != (void *)0x0) {
                      puVar2[0x549c] = (int)pvVar4 + 4000;
                      puVar2[0x549e] = (int)pvVar4 + 8000;
                      puVar2[0x54a0] = (int)pvVar4 + 12000;
                      puVar2[0x2a1] = 0;
                      puVar2[0x4b] = 0;
                      puVar2[0x4c] = 0x3f800000;
                      puVar2[0x4d] = 0;
                      puVar2[0x4e] = 0x3f800000;
                      puVar2[0x47] = 0;
                      puVar2[0x48] = 0;
                      puVar2[0x2a6] = 0;
                      iVar3 = 5;
                      do {
                        *(undefined1 *)(puVar5 + 0x14b) = 0;
                        *(undefined1 *)((int)puVar5 + 0x531) = 0;
                        *(undefined1 *)((int)puVar5 + 0x536) = 0;
                        puVar5 = (uint *)((int)puVar5 + 1);
                        iVar3 = iVar3 + -1;
                      } while (iVar3 != 0);
                      ((int (*)())FUN_000048e7)(puVar2);
                      *param_2 = puVar2;
                      return 0;
                    }
                  }
                }
              }
            }
          }
        }
        _IOServiceClose(puVar2[5]);
      }
      _free(puVar2);
      return 0xffffffff;
    }
  }
  return 0xfffffffd;
}

/* FUN_00001a8c @ 0x1a8c (121 bytes) */
int FUN_00001a8c(param_1, param_2, param_3)
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
    if (param_3 != '\0') {
      _free((void *)*param_2);
    }
    _free((void *)param_2[10]);
    param_2[10] = 0;
  }
  return;
}

/* FUN_00001b05 @ 0x1b05 (352 bytes) */
int FUN_00001b05(param_1, param_2)
  int param_1;
  int param_2;
{
  uint *puVar1;
  int iVar2;
  int *piVar3;
  int local_28;
  int local_24;
  
  piVar3 = *(int **)(param_1 + 0x34);
  if (*(int **)(param_1 + 0x38) <= piVar3 + 8) {
    puVar1 = *(uint **)(param_1 + 0x30);
    *puVar1 = *puVar1 | (int)piVar3 - (int)puVar1 >> 2;
    *(undefined4 **)(param_1 + 0x30) = *(undefined4 **)(param_1 + 0x34);
    **(undefined4 **)(param_1 + 0x34) = 0x1000000;
    _IOConnectMapMemory(*(undefined4 *)(param_1 + 0x14),1,*(undefined4 *)PTR_0000e0e6,param_1 + 0x40
                        ,param_1 + 0x44,1);
    iVar2 = *(int *)(param_1 + 0x40);
    *(int *)(param_1 + 0x30) = iVar2 + 0x1c;
    *(int *)(param_1 + 0x34) = iVar2 + 0x20;
    *(int *)(param_1 + 0x38) = iVar2 + 0x20 + *(int *)(iVar2 + 0x10) * 4;
    *(undefined4 *)(iVar2 + 0x1c) = 0;
    piVar3 = *(int **)(param_1 + 0x34);
  }
  local_24 = param_1 + 0x40;
  local_28 = param_1 + 0x44;
  *(int **)(param_1 + 0x34) = piVar3 + 8;
  puVar1 = *(uint **)(param_1 + 0x30);
  *puVar1 = *puVar1 | (int)piVar3 - (int)puVar1 >> 2;
  *(int **)(param_1 + 0x30) = piVar3;
  *piVar3 = (uint)param_2 * 0x1000000 + 0x2b000000;
  iVar2 = 7;
  do {
    piVar3 = piVar3 + 1;
    *piVar3 = -0x80000000;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  puVar1 = *(uint **)(param_1 + 0x30);
  *puVar1 = *puVar1 | *(int *)(param_1 + 0x34) - (int)puVar1 >> 2;
  *(undefined4 **)(param_1 + 0x30) = *(undefined4 **)(param_1 + 0x34);
  **(undefined4 **)(param_1 + 0x34) = 0x1000000;
  _IOConnectMapMemory(*(undefined4 *)(param_1 + 0x14),1,*(undefined4 *)PTR_0000e0e6,local_24,
                      local_28,1);
  iVar2 = *(int *)(param_1 + 0x40);
  *(int *)(param_1 + 0x30) = iVar2 + 0x1c;
  *(int *)(param_1 + 0x34) = iVar2 + 0x20;
  *(int *)(param_1 + 0x38) = iVar2 + 0x20 + *(int *)(iVar2 + 0x10) * 4;
  *(undefined4 *)(iVar2 + 0x1c) = 0;
  return;
}

/* FUN_00001c65 @ 0x1c65 (301 bytes) */
int FUN_00001c65(param_1)
  void *param_1;
{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar1 = (int)param_1 + 0x55c;
  if (param_1 == (void *)0x0) {
    return 0xfffffff9;
  }
  iVar2 = 0x19;
  do {
    _free(*(void **)(iVar1 + 0x13ea8));
    iVar1 = iVar1 + 0xc;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  _free(*(void **)((int)param_1 + 0x15268));
  if (*(int *)((int)param_1 + 0x54) != 0) {
    uVar3 = 0;
    iVar1 = 0;
    do {
      ((int (*)())FUN_00001a8c)(param_1,(int)param_1 + iVar1 + 0x814,1);
      uVar3 = uVar3 + 1;
      iVar1 = iVar1 + 100;
    } while (uVar3 < *(uint *)((int)param_1 + 0x54));
  }
  ((int (*)())FUN_00001b05)(param_1,0);
  ((int (*)())FUN_00001a8c)(param_1,(int)param_1 + 0x15160,1);
  ((int (*)())FUN_00001b05)(param_1,1);
  ((int (*)())FUN_00001a8c)(param_1,(int)param_1 + 0x15368,1);
  _IOServiceClose(*(undefined4 *)((int)param_1 + 0x14));
  _free(param_1);
  return 0;
}

/* FUN_00001d92 @ 0x1d92 (127 bytes) */
int FUN_00001d92(param_1, param_2)
  int param_1;
  uint param_2;
{
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  int local_10 [2];
  
  local_14 = 1;
  if (param_2 < 10000) {
    local_1c = *(undefined4 *)(param_1 + 0xa9c + param_2 * 8);
    local_18 = *(undefined4 *)(param_1 + 0xaa0 + param_2 * 8);
    _io_connect_method_scalarI_scalarO
              (*(undefined4 *)(param_1 + 0x14),0x14,&local_1c,2,local_10,&local_14);
    if (local_10[0] != 1) {
      return 0;
    }
  }
  return 1;
}

/* FUN_00001e11 @ 0x1e11 (114 bytes) */
int FUN_00001e11(param_1, param_2)
  int param_1;
  uint param_2;
{
  int iVar1;
  undefined4 local_14;
  undefined4 local_10;
  
  if (param_2 < 10000) {
    local_14 = *(undefined4 *)(param_1 + 0xa9c + param_2 * 8);
    local_10 = *(undefined4 *)(param_1 + 0xaa0 + param_2 * 8);
    iVar1 = _io_connect_method_scalarI_structureI
                      (*(undefined4 *)(param_1 + 0x14),0x13,&local_14,2,0,0);
    if (iVar1 == 0) {
      return 0;
    }
  }
  return 0xfffffff9;
}

/* FUN_00001e83 @ 0x1e83 (63 bytes) */
int FUN_00001e83(param_1, param_2, param_3)
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

/* FUN_00001ec2 @ 0x1ec2 (55 bytes) */
int FUN_00001ec2(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  if (param_2 == 4) {
    *(int *)(param_1 + 0x120) = param_3;
    if (param_3 == 4) {
      FUN_0000a6c6(param_1);
    }
    return 0;
  }
  return 0xfffffff9;
}

/* FUN_00001ef9 @ 0x1ef9 (63 bytes) */
int FUN_00001ef9(param_1, param_2, param_3)
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

/* FUN_00001f38 @ 0x1f38 (1350 bytes) */
int FUN_00001f38(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  float *param_3;
{
  uint uVar1;
  int iVar2;
  float fVar3;
  double dVar4;
  undefined4 *local_148;
  undefined4 *local_144;
  undefined4 local_140;
  undefined1 local_134 [256];
  undefined4 local_34;
  uint local_30;
  undefined4 local_2c;
  undefined4 local_28;
  uint local_24;
  undefined4 local_20 [4];
  
  switch(param_2) {
  case 4:
    *(float *)(param_1 + 0x120) = *param_3;
    uVar1 = *(uint *)(param_1 + 0x11c) | 1;
    *(uint *)(param_1 + 0x11c) = uVar1;
    local_140 = 0;
    break;
  default:
    local_140 = 0xfffffffb;
    uVar1 = *(uint *)(param_1 + 0x11c);
    break;
  case 0x17:
    fVar3 = *param_3;
    *(float *)(param_1 + 300) = fVar3;
    dVar4 = (double)fVar3;
    if ((dVar4 < DOUBLE_0000b350) && (!NAN(dVar4) && !NAN(DOUBLE_0000b350))) {
      *(undefined4 *)(param_1 + 300) = 0xc0490fdb;
    }
    if (DOUBLE_0000b358 < (double)*(float *)(param_1 + 300)) {
      *(undefined4 *)(param_1 + 300) = 0x40490fdb;
      local_140 = 0;
      uVar1 = *(uint *)(param_1 + 0x11c);
    }
    else {
LAB_00002261:
      local_140 = 0;
      uVar1 = *(uint *)(param_1 + 0x11c);
    }
    break;
  case 0x18:
    fVar3 = *param_3;
    *(float *)(param_1 + 0x130) = fVar3;
    if (fVar3 < 0.0) {
      *(undefined4 *)(param_1 + 0x130) = 0;
    }
    if (*(float *)(param_1 + 0x130) <= FLOAT_0000b360) goto LAB_00002261;
    *(float *)(param_1 + 0x130) = FLOAT_0000b360;
    local_140 = 0;
    uVar1 = *(uint *)(param_1 + 0x11c);
    break;
  case 0x19:
    fVar3 = *param_3;
    *(float *)(param_1 + 0x134) = fVar3;
    if ((fVar3 < FLOAT_0000b364) && (!NAN(fVar3) && !NAN(FLOAT_0000b364))) {
      *(undefined4 *)(param_1 + 0x134) = 0xbf800000;
    }
    if (*(float *)(param_1 + 0x134) <= FLOAT_0000b368) goto LAB_00002261;
    *(float *)(param_1 + 0x134) = FLOAT_0000b368;
    local_140 = 0;
    uVar1 = *(uint *)(param_1 + 0x11c);
    break;
  case 0x1a:
    fVar3 = *param_3;
    *(float *)(param_1 + 0x138) = fVar3;
    if ((fVar3 < FLOAT_0000b36c) && (!NAN(fVar3) && !NAN(FLOAT_0000b36c))) {
      *(undefined4 *)(param_1 + 0x138) = 0x3e800000;
    }
    if (*(float *)(param_1 + 0x138) <= FLOAT_0000b370) goto LAB_00002261;
    *(float *)(param_1 + 0x138) = FLOAT_0000b370;
    local_140 = 0;
    uVar1 = *(uint *)(param_1 + 0x11c);
    break;
  case 0x1b:
    ((int (*)())FUN_00003898)(param_1,(int)*(char *)param_3,(int)*(char *)(param_1 + 0x114),param_1 + 0x10c,
                 *(undefined4 *)(param_1 + 0x118));
    local_140 = 0;
    uVar1 = *(uint *)(param_1 + 0x11c);
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
    *(short *)(param_1 + 0x12a) = SUB42(fVar3,0);
    local_140 = 0;
    uVar1 = *(uint *)(param_1 + 0x11c);
  }
  if (((*(float *)(param_1 + 0x134) != 0.0) || (NAN(*(float *)(param_1 + 0x134)))) ||
     (FLOAT_0000b368 != *(float *)(param_1 + 0x138))) {
    uVar1 = uVar1 | 2;
    *(uint *)(param_1 + 0x11c) = uVar1;
  }
  else {
    uVar1 = uVar1 & 0xfffffffd;
    *(uint *)(param_1 + 0x11c) = uVar1;
  }
  if (((*(float *)(param_1 + 300) != 0.0) || (NAN(*(float *)(param_1 + 300)))) ||
     ((FLOAT_0000b368 != *(float *)(param_1 + 0x138) ||
      (FLOAT_0000b368 != *(float *)(param_1 + 0x130))))) {
    uVar1 = uVar1 | 4;
    *(uint *)(param_1 + 0x11c) = uVar1;
  }
  else {
    uVar1 = uVar1 & 0xfffffffb;
    *(uint *)(param_1 + 0x11c) = uVar1;
  }
  if ((uVar1 & 1) == 0) {
    if ((uVar1 & 2) == 0) {
      if ((uVar1 & 4) == 0) goto LAB_00002158;
      local_24 = *(uint *)(param_1 + 0xa84);
      goto LAB_0000213f;
    }
    local_24 = *(uint *)(param_1 + 0xa84);
LAB_0000205c:
    local_24 = local_24 | 0x80000;
    *(uint *)(param_1 + 0xa84) = local_24;
  }
  else {
    local_20[0] = 0;
    local_34 = 1;
    iVar2 = _io_connect_method_scalarI_scalarO
                      (*(undefined4 *)(param_1 + 0x14),0x11,&local_34,1,0,local_20);
    if (iVar2 != 0) {
      return 0xfffffffb;
    }
    local_24 = *(uint *)(param_1 + 0xa84) | 0x8000;
    *(uint *)(param_1 + 0xa84) = local_24;
    uVar1 = *(uint *)(param_1 + 0x11c);
LAB_0000213f:
    if (((uVar1 & 2) != 0) || ((uVar1 & 4) != 0)) goto LAB_0000205c;
  }
  local_144 = &local_34;
  local_148 = local_20;
  local_20[0] = 0;
  local_34 = 0;
  local_30 = *(undefined4 *)(param_1 + 0x578);
  local_2c = *(undefined4 *)(param_1 + 0x57c);
  local_28 = 0;
  iVar2 = _io_connect_method_scalarI_scalarO
                    (*(undefined4 *)(param_1 + 0x14),0x15,local_144,5,0,local_148);
  if (iVar2 == 0) {
    local_34 = *(undefined4 *)(param_1 + 0xc);
    local_30 = *(uint *)(param_1 + 0x18) & 0xffff4000;
    local_2c = 1;
    iVar2 = _io_connect_method_scalarI_structureI(*(undefined4 *)(param_1 + 0x14),0,local_144,3,0,0)
    ;
    if (iVar2 == 0) {
      local_20[0] = 0x100;
      iVar2 = _io_connect_method_scalarI_structureO
                        (*(undefined4 *)(param_1 + 0x14),4,local_144,1,local_134,local_148);
      if (iVar2 == 0) {
LAB_00002158:
        if (*(int *)(param_1 + 0x120) == 4) {
          FUN_0000a6c6(param_1);
        }
        return local_140;
      }
    }
  }
  return 0xfffffffb;
}

/* FUN_000024e2 @ 0x24e2 (691 bytes) */
int FUN_000024e2(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int param_1;
  uint *param_2;
  undefined4 param_3;
  uint param_4;
  uint param_5;
  uint param_6;
  uint param_7;
{
  uint uVar1;
  void *pvVar2;
  int iVar3;
  undefined4 uVar4;
  void *pvVar5;
  uint uVar6;
  undefined4 local_24;
  uint local_20;
  int local_1c;
  undefined4 local_10;
  
  if (param_2 == (uint *)0x0) {
    return 0xfffffff9;
  }
  pvVar2 = _calloc(1,0x34);
  if (pvVar2 == (void *)0x0) {
    return 0xfffffffd;
  }
  if (param_6 == 0x61723135) {
    *(undefined4 *)((int)pvVar2 + 0x2c) = 0xb;
    *(undefined4 *)((int)pvVar2 + 0x30) = 0;
    *(undefined4 *)((int)pvVar2 + 0x24) = 2;
    *(undefined4 *)((int)pvVar2 + 0x28) = 1;
    goto LAB_0000256a;
  }
  if (param_6 < 0x61723136) {
    if (param_6 != 0x20) {
      if (param_6 == 0x32767579) {
        *(undefined4 *)((int)pvVar2 + 0x2c) = 0x14;
        *(undefined4 *)((int)pvVar2 + 0x30) = 0;
        *(undefined4 *)((int)pvVar2 + 0x24) = 2;
        *(undefined4 *)((int)pvVar2 + 0x28) = 1;
      }
      else {
        if (param_6 != 8) {
          return 0xfffffff9;
        }
        *(undefined4 *)((int)pvVar2 + 0x2c) = 0;
        *(undefined4 *)((int)pvVar2 + 0x30) = 0;
        *(undefined4 *)((int)pvVar2 + 0x24) = 1;
        *(undefined4 *)((int)pvVar2 + 0x28) = 0;
      }
      goto LAB_0000256a;
    }
  }
  else {
    if (param_6 == 0x72676261) {
      *(undefined4 *)((int)pvVar2 + 0x2c) = 0xc;
      *(undefined4 *)((int)pvVar2 + 0x30) = 0;
      *(undefined4 *)((int)pvVar2 + 0x24) = 4;
      *(undefined4 *)((int)pvVar2 + 0x28) = 2;
      goto LAB_0000256a;
    }
    if (param_6 == 0x79757673) {
      *(undefined4 *)((int)pvVar2 + 0x2c) = 0x15;
      *(undefined4 *)((int)pvVar2 + 0x30) = 0;
      *(undefined4 *)((int)pvVar2 + 0x24) = 2;
      *(undefined4 *)((int)pvVar2 + 0x28) = 1;
      goto LAB_0000256a;
    }
    if (param_6 != 0x61726762) {
      return 0xfffffff9;
    }
  }
  *(undefined4 *)((int)pvVar2 + 0x2c) = 0xc;
  *(undefined4 *)((int)pvVar2 + 0x30) = 2;
  *(undefined4 *)((int)pvVar2 + 0x24) = 4;
  *(undefined4 *)((int)pvVar2 + 0x28) = 2;
LAB_0000256a:
  *param_2 = 0;
  param_2[4] = param_4;
  param_2[5] = param_5;
  if (param_7 == 0) {
    param_2[6] = param_4 * *(int *)((int)pvVar2 + 0x24) + 0xff & 0xffffff00;
  }
  else {
    param_2[6] = param_4 * *(int *)((int)pvVar2 + 0x24);
  }
  param_2[1] = param_6;
  *(undefined4 *)((int)pvVar2 + 4) = *(undefined4 *)(param_1 + 0xc);
  *(uint *)((int)pvVar2 + 0x18) = param_2[6] / *(uint *)((int)pvVar2 + 0x24);
  *(undefined2 *)((int)pvVar2 + 8) = 0;
  *(undefined2 *)((int)pvVar2 + 10) = 0;
  uVar1 = param_2[4];
  *(short *)((int)pvVar2 + 0xc) = (short)uVar1;
  uVar6 = param_2[5];
  *(short *)((int)pvVar2 + 0xe) = (short)uVar6;
  *(uint *)((int)pvVar2 + 0x10) = uVar1;
  *(uint *)((int)pvVar2 + 0x14) = uVar6;
  if (param_7 == 0) {
    pvVar5 = _malloc(uVar6 * param_2[6] + 0x100);
    *param_2 = (uint)pvVar5;
    if (pvVar5 == (void *)0x0) {
      _free(pvVar2);
      return 0xfffffffd;
    }
    uVar6 = param_2[5];
  }
  else {
    *param_2 = param_7;
  }
  local_24 = 0;
  if (param_7 == 0) {
    local_20 = *param_2 + 0xff & 0xffffff00;
  }
  else {
    local_20 = *param_2;
  }
  local_1c = uVar6 * param_2[6];
  local_10 = 1;
  iVar3 = _io_connect_method_scalarI_scalarO
                    (*(undefined4 *)(param_1 + 0x14),8,&local_24,3,pvVar2,&local_10);
  if (iVar3 == 0) {
    if ((*(byte *)(param_1 + 0x20) & 0x82) != 0) {
      param_2[9] = 1;
    }
    param_2[10] = (uint)pvVar2;
    uVar4 = 0;
  }
  else {
    _free(pvVar2);
    _free((void *)*param_2);
    uVar4 = 0xfffffffd;
  }
  return uVar4;
}

/* FUN_00002795 @ 0x2795 (374 bytes) */
int FUN_00002795(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  int param_3;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  
  iVar3 = param_1 + 0x55c;
  iVar8 = *(int *)(param_1 + 0x54);
  if (iVar8 != param_3) {
    return 0xfffffff9;
  }
  if (iVar8 != 0) {
    local_10 = 0;
    iVar7 = 0;
    iVar5 = param_1 + 0x814;
    local_14 = iVar3;
    do {
      puVar1 = (undefined4 *)param_2[local_10];
      iVar4 = ((int (*)())FUN_000024e2)(param_1,iVar5 + iVar7,*(undefined4 *)(local_14 + 0x4ac),*puVar1,puVar1[1]
                           ,puVar1[3],0);
      if (iVar4 != 0) {
        if (local_10 < 1) {
          return 0xfffffffd;
        }
        iVar8 = 0;
        do {
          ((int (*)())FUN_00001a8c)(param_1,iVar5,1);
          iVar8 = iVar8 + 1;
          iVar5 = iVar5 + 100;
        } while (iVar8 != local_10);
        return 0xfffffffd;
      }
      local_10 = local_10 + 1;
      local_14 = local_14 + 4;
      iVar7 = iVar7 + 100;
    } while (local_10 != iVar8);
    local_1c = 0;
    local_18 = iVar3;
    do {
      *(undefined4 *)(iVar3 + 0x178) = *(undefined4 *)*param_2;
      *(undefined4 *)(iVar3 + 0x17c) = *(undefined4 *)(*param_2 + 4);
      uVar2 = *(undefined4 *)(local_18 + 0x2d0);
      *(undefined4 *)(iVar3 + 0x180) = uVar2;
      *(undefined4 *)(iVar3 + 0x184) = *(undefined4 *)(*param_2 + 0xc);
      uVar6 = *(int *)(local_18 + 0x2b8) + 0xffU & 0xffffff00;
      *(uint *)(iVar3 + 400) = uVar6;
      *(undefined1 *)(iVar3 + 0x194) = 1;
      *(undefined4 *)(*param_2 + 8) = uVar2;
      *(uint *)(*param_2 + 0x18) = uVar6;
      local_1c = local_1c + 1;
      param_2 = param_2 + 1;
      iVar3 = iVar3 + 0x40;
      local_18 = local_18 + 100;
    } while (local_1c != local_10);
  }
  return 0;
}

/* FUN_0000290b @ 0x290b (105 bytes) */
int FUN_0000290b(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  uint uVar3;
  bool bVar4;
  
  iVar2 = param_1 + 0x55c;
  if (*(int *)(param_1 + 0x54) != 0) {
    uVar3 = 1;
    do {
      iVar1 = param_2 + uVar3 * 4;
      **(undefined4 **)(iVar1 + -4) = *(undefined4 *)(iVar2 + 0x38);
      *(undefined4 *)(*(int *)(iVar1 + -4) + 4) = *(undefined4 *)(iVar2 + 0x3c);
      *(undefined4 *)(*(int *)(iVar1 + -4) + 8) = *(undefined4 *)(iVar2 + 0x40);
      *(undefined4 *)(*(int *)(iVar1 + -4) + 0xc) = *(undefined4 *)(iVar2 + 0x44);
      *(undefined1 *)(*(int *)(iVar1 + -4) + 0x1c) = *(undefined1 *)(iVar2 + 0x54);
      iVar2 = iVar2 + 0x40;
      bVar4 = uVar3 < *(uint *)(param_1 + 0x54);
      uVar3 = uVar3 + 1;
    } while (bVar4);
  }
  return 0;
}

/* FUN_00002974 @ 0x2974 (132 bytes) */
int FUN_00002974(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  uint uVar3;
  bool bVar4;
  
  iVar2 = param_1 + 0x55c;
  if (*(int *)(param_1 + 0x54) != 0) {
    uVar3 = 1;
    do {
      iVar1 = param_2 + uVar3 * 4;
      **(undefined4 **)(iVar1 + -4) = *(undefined4 *)(iVar2 + 0x178);
      *(undefined4 *)(*(int *)(iVar1 + -4) + 4) = *(undefined4 *)(iVar2 + 0x17c);
      *(undefined4 *)(*(int *)(iVar1 + -4) + 8) = *(undefined4 *)(iVar2 + 0x180);
      *(undefined4 *)(*(int *)(iVar1 + -4) + 0xc) = *(undefined4 *)(iVar2 + 0x184);
      *(undefined4 *)(*(int *)(iVar1 + -4) + 0x18) = *(undefined4 *)(iVar2 + 400);
      *(undefined1 *)(*(int *)(iVar1 + -4) + 0x1c) = *(undefined1 *)(iVar2 + 0x194);
      iVar2 = iVar2 + 0x40;
      bVar4 = uVar3 < *(uint *)(param_1 + 0x54);
      uVar3 = uVar3 + 1;
    } while (bVar4);
  }
  return 0;
}

/* FUN_000029f8 @ 0x29f8 (114 bytes) */
int FUN_000029f8(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 *param_4;
{
  *(undefined4 *)(param_1 + 0xa9c + *(int *)(param_1 + 0xa98) * 8) = 0;
  *(undefined4 *)(param_1 + 0xaa0 + *(int *)(param_1 + 0xa98) * 8) = 0;
  *param_4 = *(undefined4 *)(param_1 + 0xa98);
  param_4[1] = 0;
  *(uint *)(param_1 + 0xa98) = (*(int *)(param_1 + 0xa98) + 1U) % 10000;
  return 0;
}

/* FUN_00002a6a @ 0x2a6a (811 bytes) */
int FUN_00002a6a(param_1, param_2, param_3)
  int param_1;
  byte *param_2;
  undefined4 *param_3;
{
  uint *puVar1;
  int iVar2;
  int iVar3;
  uint *puVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int local_2c;
  int local_28;
  byte *local_24;
  undefined4 local_10;
  
  puVar1 = (uint *)(param_1 + 0x55c);
  *(undefined1 *)((char)param_2[6] + 0x531 + (int)puVar1) = 0;
  *(undefined1 *)((char)param_2[6] + 0x536 + (int)puVar1) = 0;
  if (*param_2 == 1) {
    *(undefined1 *)((char)param_2[6] + 0x52c + (int)puVar1) = 0;
  }
  if ((*(char *)((char)param_2[7] + 0x52c + (int)puVar1) != '\0') ||
     (*(char *)((char)param_2[8] + 0x52c + (int)puVar1) != '\0')) {
    *(undefined1 *)((char)param_2[6] + 0x52c + (int)puVar1) = 1;
    return 0xffffffff;
  }
  *(undefined1 *)((char)param_2[6] + 0x52c + (int)puVar1) = 0;
  *(undefined4 *)(param_1 + 0xa9c + *(int *)(param_1 + 0xa98) * 8) = 0;
  *(undefined4 *)(param_1 + 0xaa0 + *(int *)(param_1 + 0xa98) * 8) = 0;
  *(int *)(param_1 + 0x568) = (int)(char)param_2[6];
  *(int *)(param_1 + 0x56c) = (int)(char)param_2[7];
  *(int *)(param_1 + 0x570) = (int)(char)param_2[8];
  local_2c = *(int *)(param_2 + 0xc);
  local_10 = *(undefined4 *)(param_2 + 0x10);
  local_24 = param_2;
  local_28 = 0;
  do {
    *puVar1 = (uint)local_24[2];
    *(uint *)(param_1 + 0x560) = (uint)*local_24;
    *(byte *)(param_1 + 0x564) = local_24[4];
    if (local_28 == 0) {
      *(undefined1 *)(param_1 + 0x574) = 0;
      if (*puVar1 == 3) goto LAB_00002d2b;
LAB_00002b5b:
      uVar7 = (uint)(*(int *)(param_1 + 0x580) * *(int *)(param_1 + 0x584)) >> 1;
      if (*(int *)(param_1 + 0x560) == 1) goto LAB_00002d3f;
LAB_00002b74:
      puVar4 = puVar1;
      do {
        puVar4[0x4fa9] = 0;
        puVar4[0x4fa8] = *(int *)(param_1 + 0x143f8) - 1;
        puVar4 = puVar4 + 3;
      } while ((uint *)(param_1 + 0x688) != puVar4);
      if (uVar7 != 0) {
        uVar5 = 0;
        do {
          while (*(char *)(local_2c + 0x14) == '\0') {
            FUN_00007179(param_1,local_2c,&local_10,uVar5,0);
            local_2c = local_2c + 0x1c;
            uVar5 = uVar5 + 1;
            if (uVar7 <= uVar5) goto LAB_00002c2d;
          }
          FUN_00007179(param_1,local_2c,&local_10,uVar5,1);
          FUN_000073bf(param_1,local_2c,uVar5);
          local_2c = local_2c + 0x1c;
          uVar5 = uVar5 + 1;
        } while (uVar5 < uVar7);
      }
LAB_00002c2d:
      iVar6 = 0;
      iVar8 = 0;
      iVar3 = 0x19;
      puVar4 = puVar1;
      do {
        if (puVar4[0x4fa9] != 0) {
          iVar6 = iVar6 + 1;
          iVar8 = iVar8 + puVar4[0x4fa9];
        }
        iVar2 = (*(int *)(param_1 + 0x143f8) - puVar4[0x4fa8]) + -1;
        if (iVar2 != 0) {
          iVar6 = iVar6 + 1;
          iVar8 = iVar8 + iVar2;
        }
        puVar4 = puVar4 + 3;
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
      ((int (*)())FUN_000065ca)(param_1,(iVar6 * 0x80 + iVar8) * 2 + 1000);
    }
    else {
      *(undefined1 *)(param_1 + 0x574) = 1;
      if (*puVar1 != 3) goto LAB_00002b5b;
LAB_00002d2b:
      uVar7 = *(int *)(param_1 + 0x580) * *(int *)(param_1 + 0x584);
      if (*(int *)(param_1 + 0x560) != 1) goto LAB_00002b74;
LAB_00002d3f:
      if (uVar7 != 0) {
        uVar5 = 0;
        do {
          FUN_00007179(param_1,local_2c,&local_10,uVar5,0);
          local_2c = local_2c + 0x1c;
          uVar5 = uVar5 + 1;
        } while (uVar5 < uVar7);
      }
    }
    ((int (*)())FUN_00006c3c)(param_1);
    if (*puVar1 == 3) break;
    local_28 = local_28 + 1;
    local_24 = local_24 + 1;
  } while (local_28 != 2);
  *param_3 = *(undefined4 *)(param_1 + 0xa98);
  param_3[1] = 0;
  *(uint *)(param_1 + 0xa98) = (*(int *)(param_1 + 0xa98) + 1U) % 10000;
  return 0;
}

/* FUN_00002d95 @ 0x2d95 (671 bytes) */
int FUN_00002d95(param_1, param_2)
  int param_1;
  int param_2;
{
  uint *puVar1;
  int *piVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  int local_34;
  int local_30;
  
  uVar4 = (uint)param_2;
  piVar3 = *(int **)(param_1 + 0x34);
  if (*(int **)(param_1 + 0x38) <= piVar3 + 8) {
    puVar1 = *(uint **)(param_1 + 0x30);
    *puVar1 = *puVar1 | (int)piVar3 - (int)puVar1 >> 2;
    *(undefined4 **)(param_1 + 0x30) = *(undefined4 **)(param_1 + 0x34);
    **(undefined4 **)(param_1 + 0x34) = 0x1000000;
    _IOConnectMapMemory(*(undefined4 *)(param_1 + 0x14),1,*(undefined4 *)PTR_0000e0e6,param_1 + 0x40
                        ,param_1 + 0x44,1);
    iVar5 = *(int *)(param_1 + 0x40);
    *(int *)(param_1 + 0x30) = iVar5 + 0x1c;
    *(int *)(param_1 + 0x34) = iVar5 + 0x20;
    *(int *)(param_1 + 0x38) = iVar5 + 0x20 + *(int *)(iVar5 + 0x10) * 4;
    *(undefined4 *)(iVar5 + 0x1c) = 0;
    piVar3 = *(int **)(param_1 + 0x34);
  }
  local_30 = param_1 + 0x40;
  local_34 = param_1 + 0x44;
  *(int **)(param_1 + 0x34) = piVar3 + 8;
  puVar1 = *(uint **)(param_1 + 0x30);
  *puVar1 = *puVar1 | (int)piVar3 - (int)puVar1 >> 2;
  *(int **)(param_1 + 0x30) = piVar3;
  *piVar3 = uVar4 * 0x1000000 + 0x19000000;
  piVar2 = piVar3 + 1;
  switch(uVar4) {
  case 0:
    *piVar2 = *(int *)**(undefined4 **)(param_1 + 0x15188);
    piVar2 = (int *)(**(int **)(param_1 + 0x15188) + 0x10);
    *piVar2 = *piVar2 + 1;
    piVar2 = piVar3 + 2;
    break;
  case 1:
    *piVar2 = *(int *)**(undefined4 **)(param_1 + 0x15390);
    piVar2 = (int *)(**(int **)(param_1 + 0x15390) + 0x10);
    *piVar2 = *piVar2 + 1;
    piVar2 = piVar3 + 2;
    break;
  case 2:
    *piVar2 = *(int *)**(undefined4 **)(param_1 + 0x170);
    piVar2 = (int *)(**(int **)(param_1 + 0x170) + 0x10);
    *piVar2 = *piVar2 + 1;
    piVar2 = piVar3 + 2;
    break;
  case 3:
    *piVar2 = *(int *)**(undefined4 **)(param_1 + 0x1d8);
    piVar2 = (int *)(**(int **)(param_1 + 0x1d8) + 0x10);
    *piVar2 = *piVar2 + 1;
    piVar2 = piVar3 + 2;
    break;
  case 4:
  case 5:
  case 6:
  case 7:
  case 8:
  case 9:
  case 10:
  case 0xb:
    iVar5 = param_1 + (uVar4 * 5 + -0x14) * 0x14;
    *piVar2 = *(int *)**(undefined4 **)(iVar5 + 0x240);
    piVar2 = (int *)(**(int **)(iVar5 + 0x240) + 0x10);
    *piVar2 = *piVar2 + 1;
    piVar2 = piVar3 + 2;
    break;
  case 0xc:
  case 0xd:
  case 0xe:
  case 0xf:
  case 0x10:
    iVar5 = param_1 + 0x55c + (uVar4 * 5 + -0x3c) * 0x14;
    *piVar2 = *(int *)**(undefined4 **)(iVar5 + 0x2e0);
    piVar2 = (int *)(**(int **)(iVar5 + 0x2e0) + 0x10);
    *piVar2 = *piVar2 + 1;
    piVar2 = piVar3 + 2;
    break;
  case 0x11:
    *piVar2 = *(int *)**(undefined4 **)(param_1 + 0xa44);
    piVar2 = (int *)(**(int **)(param_1 + 0xa44) + 0x10);
    *piVar2 = *piVar2 + 1;
    piVar2 = piVar3 + 2;
  }
  iVar5 = 6;
  do {
    *piVar2 = -0x80000000;
    piVar2 = piVar2 + 1;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  puVar1 = *(uint **)(param_1 + 0x30);
  *puVar1 = *puVar1 | *(int *)(param_1 + 0x34) - (int)puVar1 >> 2;
  *(undefined4 **)(param_1 + 0x30) = *(undefined4 **)(param_1 + 0x34);
  **(undefined4 **)(param_1 + 0x34) = 0x1000000;
  _IOConnectMapMemory(*(undefined4 *)(param_1 + 0x14),1,*(undefined4 *)PTR_0000e0e6,local_30,
                      local_34,1);
  iVar5 = *(int *)(param_1 + 0x40);
  *(int *)(param_1 + 0x30) = iVar5 + 0x1c;
  *(int *)(param_1 + 0x34) = iVar5 + 0x20;
  *(int *)(param_1 + 0x38) = iVar5 + 0x20 + *(int *)(iVar5 + 0x10) * 4;
  *(undefined4 *)(iVar5 + 0x1c) = 0;
  return;
}

/* FUN_0000307c @ 0x307c (730 bytes) */
int FUN_0000307c(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  undefined4 *param_3;
  undefined4 *param_4;
{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  if (((param_3[6] == 0) || (param_2 < '\0')) ||
     (uVar1 = (uint)param_2, *(uint *)(param_1 + 0x54) <= uVar1)) {
    return 0xfffffff9;
  }
  iVar3 = param_3[3];
  if (((iVar3 != 0x79757673) && (iVar3 != 0x32767579)) &&
     ((iVar3 != 0x61726762 && ((iVar3 != 0x72676261 && (iVar3 != 0x61723135)))))) {
    return 0xfffffffb;
  }
  if ((*(int *)(param_1 + 0x120) == 0) || (*(char *)(uVar1 + param_1 + 0xa92) == '\0')) {
    uVar2 = *(uint *)(param_1 + 0x11c);
    if ((uVar2 & 2) != 0) {
      FUN_00008bca(param_1,uVar1,0);
      uVar2 = *(uint *)(param_1 + 0x11c);
    }
    if ((uVar2 & 4) != 0) {
      FUN_000087a1(param_1,uVar1,0);
    }
  }
  else {
    uVar2 = *(uint *)(param_1 + 0x11c);
    if ((uVar2 & 2) != 0) {
      FUN_00008bca(param_1,uVar1,1);
      uVar2 = *(uint *)(param_1 + 0x11c);
    }
    if ((uVar2 & 4) != 0) {
      FUN_000087a1(param_1,uVar1,1);
    }
  }
  *(undefined4 *)(param_1 + 0xa9c + *(int *)(param_1 + 0xa98) * 8) = 0;
  *(undefined4 *)(param_1 + 0xaa0 + *(int *)(param_1 + 0xa98) * 8) = 0;
  iVar3 = ((int (*)())FUN_000024e2)(param_1,param_1 + 0xa1c,*(undefined4 *)(param_1 + 0xa80),*param_3,param_3[1],
                       param_3[3],param_3[6]);
  if (iVar3 != 0) {
    return 0xfffffffd;
  }
  ((int (*)())FUN_00002d95)(param_1,0x11);
  uVar2 = param_3[3];
  if (uVar2 != 0x61726762) {
    if (uVar2 < 0x61726763) {
      if (uVar2 == 0x32767579) {
LAB_000032eb:
        FUN_00009337(param_1,uVar1,param_3);
        goto LAB_000031f3;
      }
      if (uVar2 != 0x61723135) goto LAB_000031f3;
    }
    else if (uVar2 != 0x72676261) {
      if (uVar2 != 0x79757673) goto LAB_000031f3;
      goto LAB_000032eb;
    }
  }
  FUN_00008eee(param_1,uVar1,param_3);
LAB_000031f3:
  ((int (*)())FUN_00001e11)(param_1,*(undefined4 *)(param_1 + 0xa98),0);
  FUN_00008314(param_1,param_3[6],param_3[1] * param_3[2]);
  ((int (*)())FUN_00001b05)(param_1,0x11);
  ((int (*)())FUN_00001a8c)(param_1,param_1 + 0xa1c,0);
  *param_4 = *(undefined4 *)(param_1 + 0xa98);
  param_4[1] = 0;
  *(uint *)(param_1 + 0xa98) = (*(int *)(param_1 + 0xa98) + 1U) % 10000;
  return 0;
}

/* FUN_00003356 @ 0x3356 (206 bytes) */
int FUN_00003356(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  undefined4 *param_4;
{
  uint uVar1;
  
  *(undefined4 *)(param_1 + 0xa9c + *(int *)(param_1 + 0xa98) * 8) = 0;
  *(undefined4 *)(param_1 + 0xaa0 + *(int *)(param_1 + 0xa98) * 8) = 0;
  uVar1 = (int)param_3 + 0xcU & 0xff;
  ((int (*)())FUN_00002d95)(param_1,uVar1);
  FUN_0000830f(param_1,(int)param_2,(int)param_3);
  ((int (*)())FUN_00001b05)(param_1,uVar1);
  *param_4 = *(undefined4 *)(param_1 + 0xa98);
  param_4[1] = 0;
  *(uint *)(param_1 + 0xa98) = (*(int *)(param_1 + 0xa98) + 1U) % 10000;
  return 0;
}

/* FUN_00003424 @ 0x3424 (1140 bytes) */
int FUN_00003424(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  uint param_3;
{
  uint uVar1;
  uint uVar2;
  void *pvVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint *local_90;
  uint local_84;
  int local_70;
  int local_6c;
  uint local_5c;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  undefined4 local_34;
  uint local_30;
  undefined4 local_2c;
  undefined4 local_28;
  uint local_24;
  undefined4 local_20 [4];
  
  iVar7 = param_1 + 0x55c;
  uVar1 = *(uint *)(param_1 + 0x54);
  if ((uVar1 != param_3) || (uVar1 == 0)) {
    return 0xfffffff9;
  }
  if (uVar1 < 6) {
    uVar2 = *(int *)*param_2 + 0xf;
    local_5c = uVar2 & 0xfffffff0;
    *(uint *)(param_1 + 0x578) = local_5c;
    uVar5 = *(int *)(*param_2 + 4) + 0xf;
    *(uint *)(param_1 + 0x57c) = uVar5 & 0xfffffff0;
    if ((char)local_5c != '\0') {
      local_5c = (uVar2 & 0xffffff00) + 0x100;
    }
    *(uint *)(param_1 + 0x588) = local_5c;
    *(uint *)(param_1 + 0x580) = uVar2 >> 4;
    *(uint *)(param_1 + 0x584) = uVar5 >> 4;
    *(undefined2 *)(param_1 + 0x126) = 0;
    *(short *)(param_1 + 0x12a) = (short)*(undefined4 *)(param_1 + 0x578);
    *(undefined2 *)(param_1 + 0x124) = 0;
    *(short *)(param_1 + 0x128) = (short)*(undefined4 *)(param_1 + 0x57c);
    *(int *)(param_1 + 0x143f8) = *(int *)(param_1 + 0x580) * *(int *)(param_1 + 0x584);
    local_40 = 0;
    local_44 = iVar7;
    do {
      pvVar3 = _malloc(*(int *)(param_1 + 0x143f8) << 2);
      *(void **)(local_44 + 0x13ea8) = pvVar3;
      if (pvVar3 == (void *)0x0) {
        if (0 < local_40) {
          iVar6 = 0;
          do {
            _free(*(void **)(iVar7 + 0x13ea8));
            iVar6 = iVar6 + 1;
            iVar7 = iVar7 + 0xc;
          } while (iVar6 != local_40);
          return 0xfffffffd;
        }
        goto LAB_00003549;
      }
      local_40 = local_40 + 1;
      local_44 = local_44 + 0xc;
    } while (local_40 != 0x19);
    uVar2 = *(uint *)(param_1 + 0xa84);
    local_84 = 0;
    do {
      uVar2 = uVar2 | 1 << ((char)local_84 + 10U & 0x1f);
      local_84 = local_84 + 1;
    } while (uVar1 != local_84);
    *(uint *)(param_1 + 0xa84) = uVar2;
    if ((uVar1 < 5) && ((int)uVar1 < 5)) {
      iVar6 = uVar1 + 10;
      do {
        uVar2 = uVar2 & ~(1 << ((byte)iVar6 & 0x1f));
        iVar6 = iVar6 + 1;
      } while (iVar6 != 0xf);
      *(uint *)(param_1 + 0xa84) = uVar2;
    }
    local_24 = *(uint *)(param_1 + 0xa84) | 0x20000;
    *(uint *)(param_1 + 0xa84) = local_24;
    local_20[0] = 0;
    local_34 = 0;
    local_30 = *(undefined4 *)(param_1 + 0x578);
    local_2c = *(undefined4 *)(param_1 + 0x57c);
    local_28 = 0;
    iVar6 = _io_connect_method_scalarI_scalarO
                      (*(undefined4 *)(param_1 + 0x14),0x15,&local_34,5,0,local_20);
    if (iVar6 == 0) {
      local_34 = *(undefined4 *)(param_1 + 0xc);
      local_30 = *(uint *)(param_1 + 0x18) & 0xffff4000;
      local_2c = 1;
      iVar6 = _io_connect_method_scalarI_structureI
                        (*(undefined4 *)(param_1 + 0x14),0,&local_34,3,0,0);
      if (iVar6 == 0) {
        *(undefined4 *)(param_1 + 0x28) = *(undefined4 *)(param_1 + 0x578);
        *(undefined4 *)(param_1 + 0x2c) = *(undefined4 *)(param_1 + 0x57c);
        iVar6 = ((int (*)())FUN_000024e2)(param_1,param_1 + 0x15160,*(undefined4 *)(param_1 + 0x151c4),
                             *(uint *)(param_1 + 0x578) >> 4,
                             (*(uint *)(param_1 + 0x57c) >> 4) * 8 * *(int *)(param_1 + 0x54),0x20,0
                            );
        if (iVar6 == 0) {
          *(undefined4 *)(param_1 + 0x58c) = *(undefined4 *)(param_1 + 0x15178);
          uVar2 = *(int *)(param_1 + 0x15160) + 0xffU & 0xffffff00;
          local_50 = 0;
          uVar5 = *(uint *)(param_1 + 0x57c) >> 4;
          local_6c = param_1 + 0x1520c;
          local_70 = param_1 + 0x151bc;
          do {
            local_90 = (uint *)(local_70 + 0xc);
            local_4c = 4;
            do {
              *local_90 = uVar2;
              uVar2 = uVar2 + (uVar5 * *(int *)(param_1 + 0x15178) & 0xfffffffc);
              local_90 = local_90 + 1;
              local_4c = local_4c + -1;
            } while (local_4c != 0);
            local_90 = (uint *)(local_6c + 0xc);
            local_48 = 4;
            do {
              *local_90 = uVar2;
              uVar2 = uVar2 + (uVar5 * *(int *)(param_1 + 0x15178) & 0xfffffffc);
              local_90 = local_90 + 1;
              local_48 = local_48 + -1;
            } while (local_48 != 0);
            local_50 = local_50 + 1;
            local_70 = local_70 + 0x10;
            local_6c = local_6c + 0x10;
          } while (local_50 != 5);
          ((int (*)())FUN_00002d95)(param_1,0);
          iVar6 = ((int (*)())FUN_000024e2)(param_1,param_1 + 0x15368,*(undefined4 *)(param_1 + 0x153cc),
                               *(uint *)(param_1 + 0x578) >> 4,
                               (*(uint *)(param_1 + 0x57c) >> 4) * 0x18,0x20,0);
          if (iVar6 == 0) {
            ((int (*)())FUN_00002d95)(param_1,1);
            ((int (*)())FUN_000059fd)(param_1);
            ((int (*)())FUN_00004ca9)(param_1);
            DAT_0000d0fc = *(undefined4 *)(param_1 + 0x578);
            DAT_0000d0f8 = *(undefined4 *)(param_1 + 0x57c);
            uVar2 = 0;
            do {
              *(undefined4 *)(iVar7 + 0x38) = *(undefined4 *)(param_1 + 0x578);
              *(undefined4 *)(iVar7 + 0x3c) = *(undefined4 *)(param_1 + 0x57c);
              *(undefined4 *)(iVar7 + 0x40) = *(undefined4 *)(param_1 + 0x588);
              *(undefined4 *)(iVar7 + 0x44) = 0x59563132;
              *(undefined1 *)(iVar7 + 0x54) = 1;
              uVar2 = uVar2 + 1;
              iVar7 = iVar7 + 0x40;
            } while (uVar1 != uVar2);
            return 0;
          }
        }
        goto LAB_00003549;
      }
    }
    uVar4 = 0xfffffffb;
  }
  else {
LAB_00003549:
    uVar4 = 0xfffffffd;
  }
  return uVar4;
}

/* FUN_00003898 @ 0x3898 (724 bytes) */
int FUN_00003898(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int param_2;
  int param_3;
  undefined4 *param_4;
  int param_5;
{
  int iVar1;
  uint *puVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  int local_24;
  int local_20;
  
  iVar1 = param_1 + 0x55c;
  iVar5 = (int)param_2;
  if (*(char *)(iVar5 + 0x52c + iVar1) != '\0') {
    return;
  }
  if (*(char *)(iVar5 + 0x536 + iVar1) == '\0') {
    if (*(int *)(param_1 + 0x120) != 0) {
      if (*(char *)(iVar5 + 0x531 + iVar1) == '\x01') {
        if (*(int *)(param_1 + 0x120) == 4) {
          FUN_0000aee8(param_1,param_1 + 0x1431c + iVar5 * 0x14,param_1 + 0x14380 + iVar5 * 0x18,1);
        }
        local_20 = iVar5 * 0x14;
        local_24 = iVar5 * 0x18;
        FUN_0000aee8(param_1,param_1 + 0x1431c + local_20,param_1 + 0x14380 + local_24,2);
        *(undefined1 *)(iVar5 + 0x536 + iVar1) = 1;
        goto LAB_000038d9;
      }
      goto LAB_000039dc;
    }
  }
  else {
LAB_000038d9:
    if (*(int *)(param_1 + 0x120) != 0) {
LAB_000039dc:
      if (*(char *)(iVar5 + 0x536 + iVar1) != '\0') {
        uVar4 = *(uint *)(param_1 + 0x11c);
        if ((uVar4 & 2) != 0) {
          FUN_00008bca(param_1,iVar5,1);
          uVar4 = *(uint *)(param_1 + 0x11c);
        }
        if ((uVar4 & 4) != 0) {
          FUN_000087a1(param_1,iVar5,1);
        }
        FUN_0000a0e4(param_1,iVar5,1);
        *(int *)(param_1 + 0x118) = param_5;
        goto joined_r0x00003a25;
      }
    }
  }
  uVar4 = *(uint *)(param_1 + 0x11c);
  if ((uVar4 & 2) != 0) {
    FUN_00008bca(param_1,iVar5,0);
    uVar4 = *(uint *)(param_1 + 0x11c);
  }
  if ((uVar4 & 4) != 0) {
    FUN_000087a1(param_1,iVar5,0);
  }
  FUN_0000a0e4(param_1,iVar5,0);
  *(int *)(param_1 + 0x118) = param_5;
joined_r0x00003a25:
  if (param_5 != 0) {
    *(int *)(param_1 + 0x114) = (int)param_3;
    uVar3 = param_4[1];
    *(undefined4 *)(param_1 + 0x10c) = *param_4;
    *(undefined4 *)(param_1 + 0x110) = uVar3;
    FUN_000096b1(param_1);
  }
  puVar2 = *(uint **)(param_1 + 0x30);
  *puVar2 = *puVar2 | *(int *)(param_1 + 0x34) - (int)puVar2 >> 2;
  *(undefined4 **)(param_1 + 0x30) = *(undefined4 **)(param_1 + 0x34);
  **(undefined4 **)(param_1 + 0x34) = 0x2000000;
  _IOConnectMapMemory(*(undefined4 *)(param_1 + 0x14),1,*(undefined4 *)PTR_0000e0e6,param_1 + 0x40,
                      param_1 + 0x44,1);
  iVar1 = *(int *)(param_1 + 0x40);
  *(int *)(param_1 + 0x30) = iVar1 + 0x1c;
  *(int *)(param_1 + 0x34) = iVar1 + 0x20;
  *(int *)(param_1 + 0x38) = iVar1 + 0x20 + *(int *)(iVar1 + 0x10) * 4;
  *(undefined4 *)(iVar1 + 0x1c) = 0;
  if ((*(byte *)(*(int *)(param_1 + 0x40) + 0x14) & 2) != 0) {
    (**(code **)(*(int *)(*(int *)(param_1 + 0x50) + 0xc) + 0xc))
              (*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8),
               *(undefined4 *)(param_1 + 0xc));
  }
  return;
}

/* FUN_00003b6c @ 0x3b6c (5 bytes) */
int FUN_00003b6c()
{
  return;
}

/* FUN_00003b71 @ 0x3b71 (5 bytes) */
int FUN_00003b71()
{
  return;
}

/* FUN_00003b76 @ 0x3b76 (228 bytes) */
int FUN_00003b76(param_1, param_2, param_3, param_4)
  int param_1;
  char *param_2;
  undefined4 *param_3;
  undefined4 *param_4;
{
  int iVar1;
  
  *(undefined4 *)(param_1 + 0xa9c + *(int *)(param_1 + 0xa98) * 8) = 0;
  *(undefined4 *)(param_1 + 0xaa0 + *(int *)(param_1 + 0xa98) * 8) = 0;
  iVar1 = param_1 + 0x55c + *param_2 * 0x14;
  *(undefined4 *)(iVar1 + 0x13dc0) = *(undefined4 *)param_2;
  *(undefined4 *)(iVar1 + 0x13dc4) = *(undefined4 *)(param_2 + 4);
  *(undefined4 *)(iVar1 + 0x13dc8) = *(undefined4 *)(param_2 + 8);
  *(undefined4 *)(iVar1 + 0x13dcc) = *(undefined4 *)(param_2 + 0xc);
  *(undefined4 *)(iVar1 + 0x13dd0) = *(undefined4 *)(param_2 + 0x10);
  iVar1 = param_1 + 0x1437c + *param_2 * 0x18;
  *(undefined4 *)(iVar1 + 4) = *param_3;
  *(undefined4 *)(iVar1 + 8) = param_3[1];
  *(undefined4 *)(iVar1 + 0xc) = param_3[2];
  *(undefined4 *)(iVar1 + 0x10) = param_3[3];
  *(undefined4 *)(iVar1 + 0x14) = param_3[4];
  *(undefined4 *)(iVar1 + 0x18) = param_3[5];
  *(undefined1 *)(*param_2 + 0x531 + param_1 + 0x55c) = 1;
  *param_4 = *(undefined4 *)(param_1 + 0xa98);
  param_4[1] = 0;
  *(uint *)(param_1 + 0xa98) = (*(int *)(param_1 + 0xa98) + 1U) % 10000;
  return 0;
}

/* FUN_00003c5a @ 0x3c5a (969 bytes) */
int FUN_00003c5a(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  uint *puVar3;
  int iVar4;
  undefined4 *puVar5;
  int local_28;
  int local_24;
  uint local_20;
  
  if (*(int *)(param_1 + 0x54) != 0) {
    local_20 = 0;
    iVar1 = param_1 + 0x44;
    iVar2 = param_1 + 0x40;
    do {
      puVar5 = *(undefined4 **)(param_1 + 0x34);
      if (*(undefined4 **)(param_1 + 0x38) <= puVar5 + 0x10) {
        puVar3 = *(uint **)(param_1 + 0x30);
        *puVar3 = *puVar3 | (int)puVar5 - (int)puVar3 >> 2;
        *(undefined4 **)(param_1 + 0x30) = *(undefined4 **)(param_1 + 0x34);
        **(undefined4 **)(param_1 + 0x34) = 0x1000000;
        _IOConnectMapMemory(*(undefined4 *)(param_1 + 0x14),1,*(undefined4 *)PTR_0000e0e6,iVar2,
                            iVar1,1);
        iVar4 = *(int *)(param_1 + 0x40);
        *(int *)(param_1 + 0x30) = iVar4 + 0x1c;
        *(int *)(param_1 + 0x34) = iVar4 + 0x20;
        *(int *)(param_1 + 0x38) = iVar4 + 0x20 + *(int *)(iVar4 + 0x10) * 4;
        *(undefined4 *)(iVar4 + 0x1c) = 0;
        puVar5 = *(undefined4 **)(param_1 + 0x34);
      }
      *(undefined4 **)(param_1 + 0x34) = puVar5 + 0x10;
      puVar3 = *(uint **)(param_1 + 0x30);
      *puVar3 = *puVar3 | (int)puVar5 - (int)puVar3 >> 2;
      *(undefined4 **)(param_1 + 0x30) = puVar5;
      *puVar5 = 0x5000000;
      puVar5[1] = local_20;
      puVar5[2] = 0;
      puVar5[3] = 0;
      puVar5 = *(undefined4 **)(param_1 + 0x34);
      if (*(undefined4 **)(param_1 + 0x38) <= puVar5 + 0x10) {
        puVar3 = *(uint **)(param_1 + 0x30);
        *puVar3 = *puVar3 | (int)puVar5 - (int)puVar3 >> 2;
        *(undefined4 **)(param_1 + 0x30) = *(undefined4 **)(param_1 + 0x34);
        **(undefined4 **)(param_1 + 0x34) = 0x1000000;
        _IOConnectMapMemory(*(undefined4 *)(param_1 + 0x14),1,*(undefined4 *)PTR_0000e0e6,iVar2,
                            iVar1,1);
        iVar4 = *(int *)(param_1 + 0x40);
        *(int *)(param_1 + 0x30) = iVar4 + 0x1c;
        *(int *)(param_1 + 0x34) = iVar4 + 0x20;
        *(int *)(param_1 + 0x38) = iVar4 + 0x20 + *(int *)(iVar4 + 0x10) * 4;
        *(undefined4 *)(iVar4 + 0x1c) = 0;
        puVar5 = *(undefined4 **)(param_1 + 0x34);
      }
      *(undefined4 **)(param_1 + 0x34) = puVar5 + 0x10;
      puVar3 = *(uint **)(param_1 + 0x30);
      *puVar3 = *puVar3 | (int)puVar5 - (int)puVar3 >> 2;
      *(undefined4 **)(param_1 + 0x30) = puVar5;
      *puVar5 = 0x6000000;
      puVar5[1] = local_20;
      puVar5[2] = 0;
      puVar5[3] = 0x80;
      if ((*(byte *)(param_1 + 0x11c) & 1) != 0) {
        puVar5 = *(undefined4 **)(param_1 + 0x34);
        if (*(undefined4 **)(param_1 + 0x38) <= puVar5 + 0x10) {
          puVar3 = *(uint **)(param_1 + 0x30);
          *puVar3 = *puVar3 | (int)puVar5 - (int)puVar3 >> 2;
          *(undefined4 **)(param_1 + 0x30) = *(undefined4 **)(param_1 + 0x34);
          **(undefined4 **)(param_1 + 0x34) = 0x1000000;
          _IOConnectMapMemory(*(undefined4 *)(param_1 + 0x14),1,*(undefined4 *)PTR_0000e0e6,iVar2,
                              iVar1,1);
          iVar4 = *(int *)(param_1 + 0x40);
          *(int *)(param_1 + 0x30) = iVar4 + 0x1c;
          *(int *)(param_1 + 0x34) = iVar4 + 0x20;
          *(int *)(param_1 + 0x38) = iVar4 + 0x20 + *(int *)(iVar4 + 0x10) * 4;
          *(undefined4 *)(iVar4 + 0x1c) = 0;
          puVar5 = *(undefined4 **)(param_1 + 0x34);
        }
        *(undefined4 **)(param_1 + 0x34) = puVar5 + 0x10;
        puVar3 = *(uint **)(param_1 + 0x30);
        *puVar3 = *puVar3 | (int)puVar5 - (int)puVar3 >> 2;
        *(undefined4 **)(param_1 + 0x30) = puVar5;
        *puVar5 = 0x5000000;
        puVar5[1] = local_20;
        puVar5[2] = 1;
        puVar5[3] = 0;
        puVar5 = *(undefined4 **)(param_1 + 0x34);
        if (*(undefined4 **)(param_1 + 0x38) <= puVar5 + 0x10) {
          puVar3 = *(uint **)(param_1 + 0x30);
          *puVar3 = *puVar3 | (int)puVar5 - (int)puVar3 >> 2;
          *(undefined4 **)(param_1 + 0x30) = *(undefined4 **)(param_1 + 0x34);
          **(undefined4 **)(param_1 + 0x34) = 0x1000000;
          _IOConnectMapMemory(*(undefined4 *)(param_1 + 0x14),1,*(undefined4 *)PTR_0000e0e6,iVar2,
                              iVar1,1);
          iVar4 = *(int *)(param_1 + 0x40);
          *(int *)(param_1 + 0x30) = iVar4 + 0x1c;
          *(int *)(param_1 + 0x34) = iVar4 + 0x20;
          *(int *)(param_1 + 0x38) = iVar4 + 0x20 + *(int *)(iVar4 + 0x10) * 4;
          *(undefined4 *)(iVar4 + 0x1c) = 0;
          puVar5 = *(undefined4 **)(param_1 + 0x34);
        }
        *(undefined4 **)(param_1 + 0x34) = puVar5 + 0x10;
        puVar3 = *(uint **)(param_1 + 0x30);
        *puVar3 = *puVar3 | (int)puVar5 - (int)puVar3 >> 2;
        *(undefined4 **)(param_1 + 0x30) = puVar5;
        *puVar5 = 0x6000000;
        puVar5[1] = local_20;
        puVar5[2] = 1;
        puVar5[3] = 0x80;
      }
      local_20 = local_20 + 1;
    } while (local_20 < *(uint *)(param_1 + 0x54));
  }
  local_24 = param_1 + 0x40;
  local_28 = param_1 + 0x44;
  puVar3 = *(uint **)(param_1 + 0x30);
  *puVar3 = *puVar3 | *(int *)(param_1 + 0x34) - (int)puVar3 >> 2;
  *(undefined4 **)(param_1 + 0x30) = *(undefined4 **)(param_1 + 0x34);
  **(undefined4 **)(param_1 + 0x34) = 0x1000000;
  _IOConnectMapMemory(*(undefined4 *)(param_1 + 0x14),1,*(undefined4 *)PTR_0000e0e6,local_24,
                      local_28,1);
  iVar1 = *(int *)(param_1 + 0x40);
  *(int *)(param_1 + 0x30) = iVar1 + 0x1c;
  *(int *)(param_1 + 0x34) = iVar1 + 0x20;
  *(int *)(param_1 + 0x38) = iVar1 + 0x20 + *(int *)(iVar1 + 0x10) * 4;
  *(undefined4 *)(iVar1 + 0x1c) = 0;
  ((int (*)())FUN_00003898)(param_1,0,(int)(char)*(undefined4 *)(param_1 + 0x114),param_1 + 0x10c,0);
  return;
}

/* FUN_00004023 @ 0x4023 (619 bytes) */
int FUN_00004023(param_1, param_2)
  int param_1;
  uint *param_2;
{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint local_40;
  undefined4 local_34;
  uint local_30;
  undefined4 local_2c;
  undefined4 local_28;
  uint local_24;
  undefined4 local_20 [4];
  
  uVar1 = *param_2;
  *(uint *)(param_1 + 0x5c) = uVar1;
  if (uVar1 < 9) {
    *(undefined4 *)(param_1 + 0x60) = 0x2d0;
    if ((*(int *)(param_1 + 0x57c) == 0x240) || (*(int *)(param_1 + 0x57c) == 0x120)) {
      *(undefined4 *)(param_1 + 100) = 0x240;
    }
    else {
      *(undefined4 *)(param_1 + 100) = 0x1e0;
    }
    uVar1 = *(uint *)(param_1 + 0x60);
    if ((char)uVar1 != '\0') {
      uVar1 = (uVar1 & 0xffffff00) + 0x100;
    }
    *(uint *)(param_1 + 0x68) = uVar1;
    if (*(int *)(param_1 + 0x5c) != 0) {
      uVar5 = 0;
      uVar1 = *(uint *)(param_1 + 0x5c);
      iVar4 = param_1;
      do {
        *(uint *)(iVar4 + 0x6c) = param_2[0x15];
        *(uint *)(iVar4 + 0xbc) = param_2[1];
        uVar5 = uVar5 + 1;
        param_2 = param_2 + 1;
        iVar4 = iVar4 + 4;
      } while (uVar5 < uVar1);
    }
    uVar1 = 0;
    if (*(int *)(param_1 + 0x5c) != 0) {
      local_40 = 0;
      iVar6 = 0;
      iVar4 = param_1;
      do {
        iVar2 = ((int (*)())FUN_000024e2)(param_1,iVar6 + param_1 + 0x218,*(undefined4 *)(iVar4 + 0x538),0xc0,
                             *(undefined4 *)(param_1 + 100),8,*(undefined4 *)(iVar4 + 0x6c));
        if (iVar2 != 0) goto LAB_00004178;
        local_40 = local_40 + 1;
        uVar1 = *(uint *)(param_1 + 0x5c);
        iVar4 = iVar4 + 4;
        iVar6 = iVar6 + 100;
      } while (local_40 < uVar1);
    }
    iVar4 = ((int (*)())FUN_000024e2)(param_1,param_1 + 0x1b0,*(undefined4 *)(param_1 + 0x214),0x20,uVar1,0x20,0)
    ;
    if (iVar4 == 0) {
      ((int (*)())FUN_00002d95)(param_1,3);
      local_24 = *(uint *)(param_1 + 0xa84) | 0x10000;
      *(uint *)(param_1 + 0xa84) = local_24;
      local_20[0] = 0;
      local_34 = 0;
      local_30 = *(undefined4 *)(param_1 + 0x578);
      local_2c = *(undefined4 *)(param_1 + 0x57c);
      local_28 = 0;
      iVar4 = _io_connect_method_scalarI_scalarO
                        (*(undefined4 *)(param_1 + 0x14),0x15,&local_34,5,0,local_20);
      if (iVar4 == 0) {
        local_34 = *(undefined4 *)(param_1 + 0xc);
        local_30 = *(uint *)(param_1 + 0x18) & 0xffff4000;
        local_2c = 1;
        iVar4 = _io_connect_method_scalarI_structureI
                          (*(undefined4 *)(param_1 + 0x14),0,&local_34,3,0,0);
        if (iVar4 == 0) {
          return 0;
        }
      }
      uVar3 = 0xfffffffb;
    }
    else {
LAB_00004178:
      uVar3 = 0xfffffffd;
    }
  }
  else {
    _puts("Number of subpicture bitmap exceed the maximum set.");
    uVar3 = 0xfffffffd;
  }
  return uVar3;
}

/* FUN_0000428e @ 0x428e (136 bytes) */
int FUN_0000428e(param_1)
  int param_1;
{
  int iVar1;
  undefined4 local_10;
  
  ((int (*)())FUN_00001b05)(param_1,3);
  ((int (*)())FUN_00001a8c)(param_1,param_1 + 0x1b0,1);
  if (*(int *)(param_1 + 0x5c) == 0) {
    return 0;
  }
  local_10 = 0;
  iVar1 = 0;
  do {
    ((int (*)())FUN_00001a8c)(param_1,param_1 + 0x218 + iVar1,0);
    local_10 = local_10 + 1;
    iVar1 = iVar1 + 100;
  } while (local_10 < *(uint *)(param_1 + 0x5c));
  return 0;
}

/* FUN_00004316 @ 0x4316 (113 bytes) */
int FUN_00004316(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_18;
  int local_14;
  undefined4 local_10 [3];
  
  local_14 = (int)param_2;
  local_10[0] = 0;
  local_18 = 0x92;
  iVar1 = _io_connect_method_scalarI_scalarO
                    (*(undefined4 *)(param_1 + 0x14),0x10,&local_18,2,0,local_10);
  if (iVar1 != -0x11) {
    uVar2 = 0xfffffff9;
    if (iVar1 != -0x32) {
      uVar2 = 0;
    }
    return uVar2;
  }
  return 0xfffffffb;
}

/* FUN_00004387 @ 0x4387 (969 bytes) */
int FUN_00004387(param_1, param_2)
  int param_1;
  char *param_2;
{
  uint *puVar1;
  int iVar2;
  int iVar3;
  byte bVar4;
  short sVar5;
  undefined4 uVar6;
  short sVar7;
  uint uVar8;
  char cVar9;
  int iVar10;
  uint *puVar11;
  undefined4 *puVar12;
  int local_64;
  uint uStack_3c;
  short local_38;
  short local_36;
  int local_34;
  uint local_30;
  uint local_2c [7];
  
  cVar9 = *param_2;
  if (*(int *)(param_1 + 0x558) != (int)cVar9) {
    puVar12 = *(undefined4 **)(param_1 + 0x34);
    if (*(undefined4 **)(param_1 + 0x38) <= puVar12 + 0x10) {
      puVar1 = *(uint **)(param_1 + 0x30);
      *puVar1 = *puVar1 | (int)puVar12 - (int)puVar1 >> 2;
      *(undefined4 **)(param_1 + 0x30) = *(undefined4 **)(param_1 + 0x34);
      **(undefined4 **)(param_1 + 0x34) = 0x1000000;
      _IOConnectMapMemory(*(undefined4 *)(param_1 + 0x14),1,*(undefined4 *)PTR_0000e0e6,
                          param_1 + 0x40,param_1 + 0x44,1);
      iVar2 = *(int *)(param_1 + 0x40);
      *(int *)(param_1 + 0x30) = iVar2 + 0x1c;
      *(int *)(param_1 + 0x34) = iVar2 + 0x20;
      *(int *)(param_1 + 0x38) = iVar2 + 0x20 + *(int *)(iVar2 + 0x10) * 4;
      *(undefined4 *)(iVar2 + 0x1c) = 0;
      puVar12 = *(undefined4 **)(param_1 + 0x34);
    }
    local_64 = param_1 + 0x44;
    *(undefined4 **)(param_1 + 0x34) = puVar12 + 0x10;
    puVar1 = *(uint **)(param_1 + 0x30);
    *puVar1 = *puVar1 | (int)puVar12 - (int)puVar1 >> 2;
    *(undefined4 **)(param_1 + 0x30) = puVar12;
    *puVar12 = 0xd000000;
    puVar12[1] = 2;
    puVar12[2] = 1;
    puVar1 = *(uint **)(param_1 + 0x30);
    *puVar1 = *puVar1 | *(int *)(param_1 + 0x34) - (int)puVar1 >> 2;
    *(undefined4 **)(param_1 + 0x30) = *(undefined4 **)(param_1 + 0x34);
    **(undefined4 **)(param_1 + 0x34) = 0x1000000;
    _IOConnectMapMemory(*(undefined4 *)(param_1 + 0x14),1,*(undefined4 *)PTR_0000e0e6,param_1 + 0x40
                        ,local_64,1);
    iVar2 = *(int *)(param_1 + 0x40);
    *(int *)(param_1 + 0x30) = iVar2 + 0x1c;
    *(int *)(param_1 + 0x34) = iVar2 + 0x20;
    *(int *)(param_1 + 0x38) = iVar2 + 0x20 + *(int *)(iVar2 + 0x10) * 4;
    *(undefined4 *)(iVar2 + 0x1c) = 0;
    cVar9 = *param_2;
  }
  *(int *)(param_1 + 0x558) = (int)cVar9;
  uVar6 = *(undefined4 *)(param_2 + 0x16);
  *(undefined4 *)(param_1 + 0x10c) = *(undefined4 *)(param_2 + 0x12);
  *(undefined4 *)(param_1 + 0x110) = uVar6;
  local_30 = *(uint *)(param_2 + 0x24);
  iVar2 = *(int *)(param_2 + 2);
  iVar3 = *(int *)(param_2 + 6);
  sVar7 = (short)((uint)iVar2 >> 0x10);
  sVar5 = (short)((uint)iVar3 >> 0x10);
  local_38 = (short)iVar2;
  local_36 = (short)iVar3;
  if (((((int)local_36 == (int)local_38 || (int)local_36 - (int)local_38 < 0) ||
       ((int)sVar5 == (int)sVar7 || (int)sVar5 - (int)sVar7 < 0)) || (local_36 < 0)) ||
     (((local_38 < 0 || (iVar3 < 0)) || (iVar2 < 0)))) {
    uVar6 = 0xfffffff9;
  }
  else {
    local_34 = 0x10;
    iVar2 = *(int *)(param_2 + 0x28);
    do {
      iVar3 = iVar2 + (local_30 >> ((byte)local_34 & 0x1f) & 0xf) * 4;
      bVar4 = (byte)(local_30 >> ((byte)local_34 - 0x10 & 0x1f)) & 0xf;
      if (bVar4 == 0xf) {
        iVar10 = 0xff;
      }
      else {
        iVar10 = (uint)bVar4 * 0xf;
      }
      *(uint *)((int)&uStack_3c + local_34) =
           iVar10 << 0x18 | (uint)*(byte *)(iVar3 + 1) << 0x10 | (uint)*(byte *)(iVar3 + 2) << 8 |
           (uint)*(byte *)(iVar3 + 3);
      local_34 = local_34 + 4;
    } while (local_34 != 0x20);
    DAT_0000d100 = (DAT_0000d100 + 1) % *(uint *)(param_1 + 0x5c);
    uVar8 = 0;
    puVar1 = (uint *)((*(int *)(param_1 + 0x1b0) + 0xffU & 0xffffff00) + DAT_0000d100 * 0x80);
    do {
      puVar11 = puVar1;
      *puVar11 = local_2c[(int)uVar8 >> 2];
      puVar11[1] = local_2c[uVar8 & 3];
      uVar8 = uVar8 + 1;
      puVar1 = puVar11 + 2;
    } while (uVar8 != 0x10);
    FUN_0000a69c(param_1,puVar11 + -0x1e,0x80);
    FUN_0000a69c(param_1,*(undefined4 *)(param_1 + 0x6c + *param_2 * 4),
                 *(int *)(param_1 + 100) * 0xc0);
    ((int (*)())FUN_00002d95)(param_1,*param_2 + '\x04');
    FUN_0000af53(param_1,CONCAT22(sVar7,local_38),CONCAT22(sVar5,local_36),*param_2 + 4,DAT_0000d100
                );
    ((int (*)())FUN_00001b05)(param_1,*param_2 + '\x04');
    uVar6 = 0;
  }
  return uVar6;
}

/* FUN_00004750 @ 0x4750 (407 bytes) */
int FUN_00004750(param_1, param_2)
  int param_1;
  int param_2;
{
  uint *puVar1;
  int iVar2;
  undefined4 *puVar3;
  int local_24;
  int local_20;
  
  if ((int)param_2 == *(int *)(param_1 + 0x558)) {
    puVar3 = *(undefined4 **)(param_1 + 0x34);
    if (*(undefined4 **)(param_1 + 0x38) <= puVar3 + 0x10) {
      puVar1 = *(uint **)(param_1 + 0x30);
      *puVar1 = *puVar1 | (int)puVar3 - (int)puVar1 >> 2;
      *(undefined4 **)(param_1 + 0x30) = *(undefined4 **)(param_1 + 0x34);
      **(undefined4 **)(param_1 + 0x34) = 0x1000000;
      _IOConnectMapMemory(*(undefined4 *)(param_1 + 0x14),1,*(undefined4 *)PTR_0000e0e6,
                          param_1 + 0x40,param_1 + 0x44,1);
      iVar2 = *(int *)(param_1 + 0x40);
      *(int *)(param_1 + 0x30) = iVar2 + 0x1c;
      *(int *)(param_1 + 0x34) = iVar2 + 0x20;
      *(int *)(param_1 + 0x38) = iVar2 + 0x20 + *(int *)(iVar2 + 0x10) * 4;
      *(undefined4 *)(iVar2 + 0x1c) = 0;
      puVar3 = *(undefined4 **)(param_1 + 0x34);
    }
    local_20 = param_1 + 0x40;
    local_24 = param_1 + 0x44;
    *(undefined4 **)(param_1 + 0x34) = puVar3 + 0x10;
    puVar1 = *(uint **)(param_1 + 0x30);
    *puVar1 = *puVar1 | (int)puVar3 - (int)puVar1 >> 2;
    *(undefined4 **)(param_1 + 0x30) = puVar3;
    *puVar3 = 0xd000000;
    puVar3[1] = 2;
    puVar3[2] = 1;
    puVar3[3] = *(undefined4 *)(param_1 + 0x60);
    puVar3[4] = *(undefined4 *)(param_1 + 100);
    puVar3[5] = *(undefined4 *)(param_1 + 0x68);
    puVar1 = *(uint **)(param_1 + 0x30);
    *puVar1 = *puVar1 | *(int *)(param_1 + 0x34) - (int)puVar1 >> 2;
    *(undefined4 **)(param_1 + 0x30) = *(undefined4 **)(param_1 + 0x34);
    **(undefined4 **)(param_1 + 0x34) = 0x1000000;
    _IOConnectMapMemory(*(undefined4 *)(param_1 + 0x14),1,*(undefined4 *)PTR_0000e0e6,local_20,
                        local_24,1);
    iVar2 = *(int *)(param_1 + 0x40);
    *(int *)(param_1 + 0x30) = iVar2 + 0x1c;
    *(int *)(param_1 + 0x34) = iVar2 + 0x20;
    *(int *)(param_1 + 0x38) = iVar2 + 0x20 + *(int *)(iVar2 + 0x10) * 4;
    *(undefined4 *)(iVar2 + 0x1c) = 0;
  }
  if ((*(byte *)(*(int *)(param_1 + 0x40) + 0x14) & 2) != 0) {
    (**(code **)(*(int *)(*(int *)(param_1 + 0x50) + 0xc) + 0xc))
              (*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8),
               *(undefined4 *)(param_1 + 0xc));
  }
  return 0;
}

/* FUN_000048e7 @ 0x48e7 (954 bytes) */
int FUN_000048e7(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0x48);
  iVar2 = *(int *)(param_1 + 0x40);
  *(int *)(param_1 + 0x30) = iVar2 + 0x1c;
  *(int *)(param_1 + 0x34) = iVar2 + 0x20;
  *(int *)(param_1 + 0x38) = iVar2 + 0x20 + *(int *)(iVar2 + 0x10) * 4;
  *(undefined4 *)(iVar2 + 0x1c) = 0;
  iVar2 = *(int *)(param_1 + 0x14528);
  *(int *)(param_1 + 0x150f0) = iVar2 + 0x20;
  *(int *)(param_1 + 0x150f8) = iVar2 + 0x20;
  *(int *)(param_1 + 0x150f4) = iVar2 + 0x1c + *(int *)(iVar2 + 0x10) * 4;
  iVar2 = *(int *)(param_1 + 0x14530);
  *(int *)(param_1 + 0x15114) = iVar2 + 0x20;
  *(int *)(param_1 + 0x1511c) = iVar2 + 0x20;
  *(int *)(param_1 + 0x15118) = iVar2 + 0x1c + *(int *)(iVar2 + 0x10) * 4;
  *(uint *)(iVar1 + 0x1c) = *(uint *)(iVar1 + 0x1c) | 1;
  *(undefined4 *)(iVar1 + 0x20) = 0x10a4;
  *(undefined4 *)(iVar1 + 0x24) = 0;
  *(undefined4 *)(iVar1 + 0x28) = 0x10a3;
  *(undefined4 *)(iVar1 + 0x2c) = 5;
  *(undefined4 *)(iVar1 + 0x30) = 0x10a2;
  *(undefined4 *)(iVar1 + 0x34) = 0;
  *(undefined4 *)(iVar1 + 0x38) = 0x850;
  *(undefined4 *)(iVar1 + 0x3c) = 0x100;
  *(undefined4 *)(iVar1 + 0x40) = 0x8a1;
  *(undefined4 *)(iVar1 + 0x44) = 0;
  *(undefined4 *)(iVar1 + 0x48) = 0x820;
  *(undefined4 *)(iVar1 + 0x4c) = 0x300856;
  *(undefined4 *)(iVar1 + 0x50) = 0x887;
  *(undefined4 *)(iVar1 + 0x54) = 0x10000;
  *(undefined4 *)(iVar1 + 0x58) = 0x82c;
  *(undefined4 *)(iVar1 + 0x5c) = 0x300;
  *(undefined4 *)(iVar1 + 0x60) = 0x84d;
  *(undefined4 *)(iVar1 + 100) = 0xffff;
  *(undefined4 *)(iVar1 + 0x68) = 0x84e;
  *(undefined4 *)(iVar1 + 0x6c) = 0;
  *(undefined4 *)(iVar1 + 0x70) = 0x877;
  *(undefined4 *)(iVar1 + 0x74) = 0;
  *(undefined4 *)(iVar1 + 0x78) = 0x888;
  *(undefined4 *)(iVar1 + 0x7c) = 0x3f800000;
  *(undefined4 *)(iVar1 + 0x80) = 0x889;
  *(undefined4 *)(iVar1 + 0x84) = 0x3f800000;
  *(undefined4 *)(iVar1 + 0x88) = 0x88a;
  *(undefined4 *)(iVar1 + 0x8c) = 0x3f800000;
  *(undefined4 *)(iVar1 + 0x90) = 0x88b;
  *(undefined4 *)(iVar1 + 0x94) = 0x3f800000;
  *(undefined4 *)(iVar1 + 0x98) = 0x1002;
  *(undefined4 *)(iVar1 + 0x9c) = 0;
  *(undefined4 *)(iVar1 + 0xa0) = 0x1008;
  *(undefined4 *)(iVar1 + 0xa4) = 0;
  *(undefined4 *)(iVar1 + 0xa8) = 0x1004;
  *(undefined4 *)(iVar1 + 0xac) = 0x78888888;
  *(undefined4 *)(iVar1 + 0xb0) = 0x1005;
  *(undefined4 *)(iVar1 + 0xb4) = 0x8888888;
  *(undefined4 *)(iVar1 + 0xb8) = 0x10a8;
  *(undefined4 *)(iVar1 + 0xbc) = 0;
  *(undefined4 *)(iVar1 + 0xc0) = 0x10ae;
  *(undefined4 *)(iVar1 + 0xc4) = 0;
  *(undefined4 *)(iVar1 + 200) = 0x12f5;
  *(undefined4 *)(iVar1 + 0xcc) = 0;
  *(undefined4 *)(iVar1 + 0xd0) = 0x1394;
  *(undefined4 *)(iVar1 + 0xd4) = 0;
  *(undefined4 *)(iVar1 + 0xd8) = 0x12f0;
  *(undefined4 *)(iVar1 + 0xdc) = 0;
  *(undefined4 *)(iVar1 + 0xe0) = 0x13c0;
  *(undefined4 *)(iVar1 + 0xe4) = 0;
  *(undefined4 *)(iVar1 + 0xe8) = 0x13c7;
  *(undefined4 *)(iVar1 + 0xec) = 0;
  *(undefined4 *)(iVar1 + 0xf0) = 0x1381;
  *(undefined4 *)(iVar1 + 0xf4) = 0;
  *(undefined4 *)(iVar1 + 0xf8) = 0x1383;
  *(undefined4 *)(iVar1 + 0xfc) = 0xf;
  *(undefined4 *)(iVar1 + 0x100) = 0x1386;
  *(undefined4 *)(iVar1 + 0x104) = 0;
  *(undefined4 *)(iVar1 + 0x108) = 0x10e9;
  *(undefined4 *)(iVar1 + 0x10c) = 0;
  *(undefined4 *)(iVar1 + 0x110) = 0x10ea;
  *(undefined4 *)(iVar1 + 0x114) = 0xa5294a5;
  *(undefined4 *)(iVar1 + 0x118) = 0x10f8;
  *(undefined4 *)(iVar1 + 0x11c) = 0;
  *(undefined4 *)(iVar1 + 0x120) = 0x10f9;
  *(undefined4 *)(iVar1 + 0x124) = 0x3ffffff;
  *(undefined4 *)(iVar1 + 0x128) = 0x10ec;
  *(undefined4 *)(iVar1 + 300) = 0;
  *(undefined4 *)(iVar1 + 0x130) = 0x10ed;
  *(undefined4 *)(iVar1 + 0x134) = 0x3ffffff;
  *(undefined4 *)(iVar1 + 0x138) = 0x10ee;
  *(undefined4 *)(iVar1 + 0x13c) = 0;
  *(undefined4 *)(iVar1 + 0x140) = 0x10ef;
  *(undefined4 *)(iVar1 + 0x144) = 0x3ffffff;
  *(undefined4 *)(iVar1 + 0x148) = 0x10f0;
  *(undefined4 *)(iVar1 + 0x14c) = 0;
  *(undefined4 *)(iVar1 + 0x150) = 0x10f1;
  *(undefined4 *)(iVar1 + 0x154) = 0x3ffffff;
  *(undefined4 *)(iVar1 + 0x158) = 0x10f2;
  *(undefined4 *)(iVar1 + 0x15c) = 0;
  *(undefined4 *)(iVar1 + 0x160) = 0x10f3;
  *(undefined4 *)(iVar1 + 0x164) = 0x3ffffff;
  *(undefined4 *)(iVar1 + 0x168) = 0x10f4;
  *(undefined4 *)(iVar1 + 0x16c) = 0xffff;
  *(undefined4 *)(iVar1 + 0x170) = 0x10fa;
  *(undefined4 *)(iVar1 + 0x174) = 0xffffff;
  *(undefined4 *)(iVar1 + 0x178) = 0x10fb;
  *(undefined4 *)(iVar1 + 0x17c) = 0;
  *(undefined4 *)(iVar1 + 0x14) = 0x58;
  return;
}

/* FUN_00004ca4 @ 0x4ca4 (5 bytes) */
int FUN_00004ca4()
{
  return;
}

/* FUN_00004ca9 @ 0x4ca9 (610 bytes) */
int FUN_00004ca9(param_1)
  int param_1;
{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  bool bVar7;
  uint local_30;
  int local_24;
  uint local_20;
  uint local_1c;
  uint local_18;
  
  puVar2 = (uint *)(*(int *)(param_1 + 0x15368) + 0xffU & 0xffffff00);
  uVar4 = *(uint *)(param_1 + 0x578);
  uVar5 = *(uint *)(param_1 + 0x57c);
  if (uVar5 == 0) {
    local_24 = 0;
    iVar1 = 0;
    *(undefined4 *)(param_1 + 0x153d0) = 0;
    bVar7 = true;
  }
  else {
    local_30 = 0;
    local_24 = 0;
    do {
      while (uVar4 == 0) {
        local_30 = local_30 + 0x10;
        if (uVar5 <= local_30) goto LAB_00004d45;
      }
      uVar6 = local_30 << 0x10;
      local_30 = local_30 + 0x10;
      uVar3 = 0;
      do {
        *puVar2 = uVar3 | uVar6;
        puVar2[1] = uVar3 | local_30 * 0x10000;
        uVar3 = uVar3 + 0x10;
        puVar2[2] = uVar3 | local_30 * 0x10000;
        puVar2[3] = uVar3 | uVar6;
        puVar2 = puVar2 + 4;
        local_24 = local_24 + 1;
      } while (uVar3 < uVar4);
    } while (local_30 < uVar5);
LAB_00004d45:
    iVar1 = local_24 << 2;
    *(int *)(param_1 + 0x153d0) = iVar1;
    bVar7 = uVar5 == 0;
  }
  if (!bVar7) {
    local_20 = 0;
    do {
      while (uVar4 == 0) {
        local_20 = local_20 + 8;
        if (uVar5 <= local_20) goto LAB_00004f00;
      }
      uVar6 = local_20 << 0x10;
      local_20 = local_20 + 8;
      uVar3 = 0;
      do {
        *puVar2 = uVar3 | uVar6;
        puVar2[1] = uVar3 | local_20 * 0x10000;
        uVar3 = uVar3 + 0x10;
        puVar2[2] = uVar3 | local_20 * 0x10000;
        puVar2[3] = uVar3 | uVar6;
        puVar2 = puVar2 + 4;
        local_24 = local_24 + 1;
      } while (uVar3 < uVar4);
    } while (local_20 < uVar5);
LAB_00004f00:
    iVar1 = local_24 << 2;
  }
  uVar4 = uVar4 >> 1;
  *(int *)(param_1 + 0x153d4) = iVar1;
  uVar5 = uVar5 >> 1;
  if (uVar5 != 0) {
    local_18 = 0;
    do {
      while (uVar4 == 0) {
        local_18 = local_18 + 8;
        if (uVar5 <= local_18) goto LAB_00004dda;
      }
      uVar6 = local_18 << 0x10;
      local_18 = local_18 + 8;
      uVar3 = 0;
      do {
        *puVar2 = uVar3 | uVar6;
        puVar2[1] = uVar3 | local_18 * 0x10000;
        uVar3 = uVar3 + 8;
        puVar2[2] = uVar3 | local_18 * 0x10000;
        puVar2[3] = uVar3 | uVar6;
        puVar2 = puVar2 + 4;
        local_24 = local_24 + 1;
      } while (uVar3 < uVar4);
    } while (local_18 < uVar5);
LAB_00004dda:
    iVar1 = local_24 << 2;
  }
  *(int *)(param_1 + 87000) = iVar1;
  if (uVar5 != 0) {
    local_1c = 0;
    do {
      while (uVar4 == 0) {
        local_1c = local_1c + 4;
        if (uVar5 <= local_1c) goto LAB_00004e4c;
      }
      uVar6 = local_1c << 0x10;
      local_1c = local_1c + 4;
      uVar3 = 0;
      do {
        *puVar2 = uVar3 | uVar6;
        puVar2[1] = uVar3 | local_1c * 0x10000;
        uVar3 = uVar3 + 8;
        puVar2[2] = uVar3 | local_1c * 0x10000;
        puVar2[3] = uVar3 | uVar6;
        puVar2 = puVar2 + 4;
      } while (uVar3 < uVar4);
    } while (local_1c < uVar5);
  }
LAB_00004e4c:
  FUN_0000a69c(param_1,*(int *)(param_1 + 0x15368) + 0xffU & 0xffffff00,
               *(int *)(param_1 + 0x1537c) * *(int *)(param_1 + 0x15380));
  return;
}

/* FUN_00004f0b @ 0x4f0b (272 bytes) */
int FUN_00004f0b(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  uint uVar2;
  bool bVar3;
  uint local_48;
  uint local_44;
  undefined4 local_40;
  int local_3c;
  int local_38;
  uint local_34;
  uint local_30;
  uint local_24;
  undefined4 local_10;
  
  local_10 = 0;
  if (param_2 == 0) {
    local_38 = *(int *)(param_1 + 0x150f8) - *(int *)(param_1 + 0x150f0);
  }
  else {
    local_38 = *(int *)(param_1 + 0x1511c) - *(int *)(param_1 + 0x15114);
  }
  local_38 = local_38 >> 2;
  if (local_38 != 0) {
    bVar3 = *(int *)(param_1 + 0x55c) == 3;
    if (bVar3) {
      uVar2 = *(uint *)(param_1 + 0x57c);
    }
    else {
      uVar2 = *(uint *)(param_1 + 0x57c) >> 1;
    }
    local_48 = (uint)!bVar3;
    local_44 = (uint)(*(int *)(param_1 + 0x55c) == 2);
    local_3c = param_2;
    local_40 = *(undefined4 *)(param_1 + 0x568);
    local_34 = -(uint)(param_2 == 0) & 0x20 | (*(byte *)(param_1 + 0x564) & 3) << 3 | 0x10080;
    local_30 = ~-(uint)(param_2 == 0) & 0x8000;
    local_24 = uVar2 << 0x10 | *(uint *)(param_1 + 0x578);
    iVar1 = _io_connect_method_structureI_structureO
                      (*(undefined4 *)(param_1 + 0x14),0x12,&local_48,0x38,0,&local_10);
    if (iVar1 != 0) {
      return 0;
    }
  }
  return 1;
}

/* FUN_0000501b @ 0x501b (292 bytes) */
int FUN_0000501b(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  undefined1 uVar2;
  
  uVar2 = ((int (*)())FUN_00004f0b)(param_1,param_2);
  if (param_2 == 0) {
    _IOConnectMapMemory(*(undefined4 *)(param_1 + 0x14),4,*(undefined4 *)PTR_0000e0e6,
                        param_1 + 0x14528,param_1 + 0x1452c,1);
    iVar1 = *(int *)(param_1 + 0x14528);
    *(int *)(param_1 + 0x150f0) = iVar1 + 0x20;
    *(int *)(param_1 + 0x150f8) = iVar1 + 0x20;
    *(int *)(param_1 + 0x150f4) = iVar1 + 0x1c + *(int *)(iVar1 + 0x10) * 4;
    *(undefined4 *)(param_1 + 0xa9c + *(int *)(param_1 + 0xa98) * 8) = *(undefined4 *)(iVar1 + 0x18)
    ;
    return uVar2;
  }
  _IOConnectMapMemory(*(undefined4 *)(param_1 + 0x14),5,*(undefined4 *)PTR_0000e0e6,
                      param_1 + 0x14530,param_1 + 0x14534,1);
  iVar1 = *(int *)(param_1 + 0x14530);
  *(int *)(param_1 + 0x15114) = iVar1 + 0x20;
  *(int *)(param_1 + 0x1511c) = iVar1 + 0x20;
  *(int *)(param_1 + 0x15118) = iVar1 + 0x1c + *(int *)(iVar1 + 0x10) * 4;
  return uVar2;
}

/* FUN_0000513f @ 0x513f (2238 bytes) */
int FUN_0000513f(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 *param_2;
  int param_3;
  int param_4;
{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  uint uVar6;
  undefined4 *puVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  int local_14;
  
  iVar4 = *(int *)(param_1 + 0x580);
  if (param_4 == '\0') {
    uVar6 = *(uint *)(param_1 + 0x584);
    uVar1 = *(uint *)(param_1 + 0x58c);
  }
  else {
    uVar6 = *(uint *)(param_1 + 0x584) >> 1;
    uVar1 = *(uint *)(param_1 + 0x58c);
  }
  if (param_3 == 1) {
    local_14 = param_1 + 0x15288;
    iVar2 = *(int *)(param_1 + 0x578);
    uVar8 = *(uint *)(param_1 + 0x57c);
    iVar3 = *(int *)(param_1 + 0x588);
    puVar5 = (undefined4 *)FUN_0000833e(param_2);
    *puVar5 = 0x850;
    puVar5[1] = 0x100;
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
    puVar5[0xe] = 0x101d;
    puVar5[0xf] = 0x28ffe040;
    puVar5[0x10] = 0x10c8;
    puVar5[0x11] = 0x50;
    puVar5[0x12] = 0x10c0;
    puVar5[0x13] = 0x40002;
    puVar5[0x14] = 0x10c1;
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
    uVar6 = (uVar6 - 1) * 0x800 | iVar4 - 1U | 0x80000000;
    puVar5[0x4a] = 0x1120;
    puVar5[0x4b] = uVar6;
    puVar5[0x4c] = 0x1121;
    puVar5[0x4d] = uVar6;
    puVar5[0x4e] = 0x1122;
    puVar5[0x4f] = uVar6;
    puVar5[0x50] = 0x1123;
    puVar5[0x51] = uVar6;
    uVar10 = iVar2 - 1;
    uVar6 = (uVar8 - 1) * 0x800 | uVar10 | 0x80000000;
    puVar5[0x52] = 0x1124;
    puVar5[0x53] = uVar6;
    puVar5[0x54] = 0x1127;
    puVar5[0x55] = uVar6;
    puVar5[0x56] = 0x112a;
    puVar5[0x57] = uVar6;
    uVar6 = ((uVar8 >> 1) - 1) * 0x800 | uVar10 | 0x80000000;
    puVar5[0x58] = 0x1125;
    puVar5[0x59] = uVar6;
    puVar5[0x5a] = 0x1126;
    puVar5[0x5b] = uVar6;
    puVar5[0x5c] = 0x1128;
    puVar5[0x5d] = uVar6;
    puVar5[0x5e] = 0x1129;
    puVar5[0x5f] = uVar6;
    puVar5[0x60] = 0x112b;
    puVar5[0x61] = uVar6;
    puVar5[0x62] = 0x112c;
    puVar5[99] = uVar6;
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
    iVar4 = (uVar1 >> 2) - 1;
    puVar5[0x7f] = iVar4;
    puVar5[0x80] = 0x1141;
    puVar5[0x81] = iVar4;
    puVar5[0x82] = 0x1142;
    puVar5[0x83] = iVar4;
    puVar5[0x84] = 0x1143;
    puVar5[0x85] = iVar4;
    puVar5[0x86] = 0x114a;
    puVar5[0x87] = iVar3 + -1;
    puVar5[0x88] = 0x114b;
    iVar4 = iVar3 * 2 + -1;
    puVar5[0x89] = iVar4;
    puVar5[0x8a] = 0x114c;
    puVar5[0x8b] = iVar4;
    puVar5[0x8c] = 0x1180;
    puVar5[0x8d] = 0;
    puVar5[0x8e] = 0x11ad;
    puVar5[0x8f] = 0;
    puVar5[0x90] = 0x1189;
    puVar5[0x91] = 0;
    puVar5[0x92] = 0x1181;
    puVar5[0x93] = 5;
    puVar5[0x94] = 0x11a9;
    puVar5[0x95] = 0xaa00;
    puVar5[0x96] = 0x11aa;
    puVar5[0x97] = 0xf;
    puVar5[0x98] = 0x11ab;
    puVar5[0x99] = 0xf;
    puVar5[0x9a] = 0x11ac;
    puVar7 = puVar5 + 0x9c;
    puVar5[0x9b] = 0xf;
  }
  else {
    local_14 = param_1 + 0x152f8;
    uVar8 = *(uint *)(param_1 + 0x578);
    uVar10 = *(uint *)(param_1 + 0x57c);
    uVar9 = *(uint *)(param_1 + 0x588) >> 1;
    uVar6 = (uVar6 - 1) * 0x800 | iVar4 - 1U | 0x80000000;
    *param_2 = 0x1120;
    param_2[1] = uVar6;
    param_2[2] = 0x1121;
    param_2[3] = uVar6;
    param_2[4] = 0x1122;
    param_2[5] = uVar6;
    param_2[6] = 0x1123;
    param_2[7] = uVar6;
    uVar8 = (uVar8 >> 1) - 1;
    uVar6 = ((uVar10 >> 1) - 1) * 0x800 | uVar8 | 0x80000000;
    param_2[8] = 0x1124;
    param_2[9] = uVar6;
    param_2[10] = 0x1127;
    param_2[0xb] = uVar6;
    param_2[0xc] = 0x112a;
    param_2[0xd] = uVar6;
    uVar6 = ((uVar10 >> 2) - 1) * 0x800 | uVar8 | 0x80000000;
    param_2[0xe] = 0x1125;
    param_2[0xf] = uVar6;
    param_2[0x10] = 0x1126;
    param_2[0x11] = uVar6;
    param_2[0x12] = 0x1128;
    param_2[0x13] = uVar6;
    param_2[0x14] = 0x1129;
    param_2[0x15] = uVar6;
    param_2[0x16] = 0x112b;
    param_2[0x17] = uVar6;
    param_2[0x18] = 0x112c;
    param_2[0x19] = uVar6;
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
    iVar4 = (uVar1 >> 2) - 1;
    param_2[0x35] = iVar4;
    param_2[0x36] = 0x1141;
    param_2[0x37] = iVar4;
    param_2[0x38] = 0x1142;
    param_2[0x39] = iVar4;
    param_2[0x3a] = 0x1143;
    param_2[0x3b] = iVar4;
    param_2[0x3c] = 0x114a;
    param_2[0x3d] = uVar9 - 1;
    param_2[0x3e] = 0x114b;
    iVar4 = uVar9 * 2 + -1;
    param_2[0x3f] = iVar4;
    param_2[0x40] = 0x114c;
    param_2[0x41] = iVar4;
    param_2[0x42] = 0x11a9;
    puVar7 = param_2 + 0x44;
    param_2[0x43] = 0x1b00;
  }
  iVar4 = FUN_0000853d(puVar7,0x10000,0x1c,local_14);
  return iVar4 - (int)param_2 >> 2;
}

/* FUN_000059fd @ 0x59fd (1141 bytes) */
int FUN_000059fd(param_1)
  int param_1;
{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  
  uVar1 = *(uint *)(param_1 + 0x578);
  uVar2 = (*(uint *)(param_1 + 0x57c) >> 1) + 0xf & 0xfffffff0;
  *(undefined4 *)(param_1 + 0x15288) = 0x3b808081;
  *(undefined4 *)(param_1 + 0x1528c) = 0x3b808081;
  *(undefined4 *)(param_1 + 0x15290) = 0x3b808081;
  *(undefined4 *)(param_1 + 0x15294) = 0x3b808081;
  if ((int)uVar1 < 0) {
    fVar9 = (float)uVar1;
    fVar8 = FLOAT_0000b374 / (fVar9 + fVar9);
    *(float *)(param_1 + 0x15298) = fVar8;
  }
  else {
    fVar9 = (float)(int)uVar1;
    fVar8 = FLOAT_0000b374 / (fVar9 + fVar9);
    *(float *)(param_1 + 0x15298) = fVar8;
  }
  fVar10 = (float)*(uint *)(param_1 + 0x57c);
  *(float *)(param_1 + 0x1529c) = FLOAT_0000b374 / (fVar10 + fVar10);
  fVar5 = FLOAT_0000b368;
  *(float *)(param_1 + 0x152a0) = FLOAT_0000b368;
  *(float *)(param_1 + 0x152a4) = fVar5;
  fVar7 = FLOAT_0000b378;
  fVar6 = FLOAT_0000b37c / (fVar9 * FLOAT_0000b378);
  *(float *)(param_1 + 0x152a8) = fVar6;
  *(float *)(param_1 + 0x152ac) = FLOAT_0000b37c / (fVar10 * fVar7);
  *(undefined4 *)(param_1 + 0x152b0) = 0;
  *(undefined4 *)(param_1 + 0x152b4) = 0;
  *(float *)(param_1 + 0x152b8) = fVar8;
  if ((int)uVar2 < 0) {
    fVar8 = (float)(uVar2 >> 1) + (float)(uVar2 >> 1);
  }
  else {
    fVar8 = (float)(int)uVar2;
  }
  *(float *)(param_1 + 0x152bc) = FLOAT_0000b374 / (fVar8 + fVar8);
  *(undefined4 *)(param_1 + 0x152c0) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x152c4) = 0x3f800000;
  *(float *)(param_1 + 0x152c8) = fVar6;
  *(float *)(param_1 + 0x152cc) = FLOAT_0000b37c / (fVar7 * fVar8);
  *(undefined4 *)(param_1 + 0x152d0) = 0;
  *(undefined4 *)(param_1 + 0x152d4) = 0;
  *(float *)(param_1 + 0x152d8) = fVar5 / fVar9;
  *(float *)(param_1 + 0x152dc) = fVar5 / fVar10;
  *(undefined4 *)(param_1 + 0x152e0) = 0;
  *(undefined4 *)(param_1 + 0x152e4) = 0;
  *(float *)(param_1 + 0x152e8) = fVar5 / fVar9;
  fVar5 = FLOAT_0000b380 / fVar10;
  *(float *)(param_1 + 0x1534c) = fVar5;
  *(float *)(param_1 + 0x152ec) = fVar5;
  *(undefined4 *)(param_1 + 0x152f0) = 0;
  *(undefined4 *)(param_1 + 0x152f4) = 0;
  *(undefined4 *)(param_1 + 0x152f8) = 0x3b808081;
  *(undefined4 *)(param_1 + 0x152fc) = 0x3b808081;
  *(undefined4 *)(param_1 + 0x15300) = 0x3b808081;
  *(undefined4 *)(param_1 + 0x15304) = 0x3b808081;
  fVar6 = FLOAT_0000b374 / fVar9;
  *(float *)(param_1 + 0x15308) = fVar6;
  *(float *)(param_1 + 0x1530c) = FLOAT_0000b374 / fVar10;
  *(undefined4 *)(param_1 + 0x15310) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x15314) = 0x3f800000;
  fVar5 = FLOAT_0000b370;
  fVar7 = FLOAT_0000b37c / (fVar9 * FLOAT_0000b370);
  *(float *)(param_1 + 0x15318) = fVar7;
  *(float *)(param_1 + 0x1531c) = FLOAT_0000b37c / (fVar10 * fVar5);
  *(undefined4 *)(param_1 + 0x15320) = 0;
  *(undefined4 *)(param_1 + 0x15324) = 0;
  *(float *)(param_1 + 0x15328) = fVar6;
  *(float *)(param_1 + 0x1532c) = FLOAT_0000b374 / fVar8;
  *(undefined4 *)(param_1 + 0x15330) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x15334) = 0x3f800000;
  *(float *)(param_1 + 0x15338) = fVar7;
  *(float *)(param_1 + 0x1533c) = FLOAT_0000b37c / (fVar8 * fVar5);
  *(undefined4 *)(param_1 + 0x15340) = 0;
  *(undefined4 *)(param_1 + 0x15344) = 0;
  fVar9 = FLOAT_0000b380 / fVar9;
  *(float *)(param_1 + 0x15348) = fVar9;
  *(undefined4 *)(param_1 + 0x15350) = 0;
  *(undefined4 *)(param_1 + 0x15354) = 0;
  *(float *)(param_1 + 0x15358) = fVar9;
  *(float *)(param_1 + 0x1535c) = fVar5 / fVar10;
  *(undefined4 *)(param_1 + 0x15360) = 0;
  *(undefined4 *)(param_1 + 0x15364) = 0;
  uVar3 = ((int (*)())FUN_0000513f)(param_1,*(undefined4 *)(param_1 + 0x15268),1,0);
  *(undefined4 *)(param_1 + 0x1526c) = uVar3;
  uVar3 = ((int (*)())FUN_0000513f)(param_1,*(undefined4 *)(param_1 + 0x15270),2,0);
  *(undefined4 *)(param_1 + 0x15274) = uVar3;
  uVar3 = *(undefined4 *)(param_1 + 0x57c);
  *(uint *)(param_1 + 0x57c) = uVar2 * 2;
  uVar4 = ((int (*)())FUN_0000513f)(param_1,*(undefined4 *)(param_1 + 0x15278),1,1);
  *(undefined4 *)(param_1 + 0x1527c) = uVar4;
  uVar4 = ((int (*)())FUN_0000513f)(param_1,*(undefined4 *)(param_1 + 0x15280),2,1);
  *(undefined4 *)(param_1 + 0x15284) = uVar4;
  *(undefined4 *)(param_1 + 0x57c) = uVar3;
  return;
}

/* FUN_00005e72 @ 0x5e72 (464 bytes) */
int FUN_00005e72(param_1, param_2, param_3)
  int param_1;
  undefined4 *param_2;
  int param_3;
{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  if (param_3 != 1) {
    *param_2 = 0x1040;
    puVar1 = param_2 + 2;
    param_2[1] = 0;
    uVar4 = *(uint *)(param_1 + 0x588) >> 1;
    if (*(int *)(param_1 + 0x55c) == 3) {
      _memcpy(puVar1,*(void **)(param_1 + 0x15270),*(int *)(param_1 + 0x15274) << 2);
      iVar3 = *(int *)(param_1 + 0x15274);
    }
    else {
      _memcpy(puVar1,*(void **)(param_1 + 0x15280),*(int *)(param_1 + 0x15284) << 2);
      iVar3 = *(int *)(param_1 + 0x15284);
    }
    puVar1 = puVar1 + iVar3;
    *puVar1 = 0x1144;
    iVar3 = uVar4 - 1;
    puVar1[1] = iVar3;
    puVar1[2] = 0x1147;
    puVar1[3] = iVar3;
    puVar1[4] = 0x1145;
    iVar3 = uVar4 * 2 + -1;
    puVar1[5] = iVar3;
    puVar1[6] = 0x1146;
    puVar1[7] = iVar3;
    puVar1[8] = 0x1148;
    puVar1[9] = iVar3;
    puVar1[10] = 0x1149;
    puVar1[0xb] = iVar3;
    puVar1 = puVar1 + 0xc;
    iVar3 = 0x1e;
    do {
      *puVar1 = 0x80000000;
      puVar1 = puVar1 + 1;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    return;
  }
  iVar3 = *(int *)(param_1 + 0x588);
  if (*(int *)(param_1 + 0x55c) == 3) {
    _memcpy(param_2,*(void **)(param_1 + 0x15268),*(int *)(param_1 + 0x1526c) << 2);
    iVar2 = *(int *)(param_1 + 0x1526c);
  }
  else {
    _memcpy(param_2,*(void **)(param_1 + 0x15278),*(int *)(param_1 + 0x1527c) << 2);
    iVar2 = *(int *)(param_1 + 0x1527c);
  }
  param_2 = param_2 + iVar2;
  *param_2 = 0x1144;
  iVar2 = iVar3 + -1;
  param_2[1] = iVar2;
  param_2[2] = 0x1147;
  param_2[3] = iVar2;
  param_2[4] = 0x1145;
  iVar3 = iVar3 * 2 + -1;
  param_2[5] = iVar3;
  param_2[6] = 0x1146;
  param_2[7] = iVar3;
  param_2[8] = 0x1148;
  param_2[9] = iVar3;
  param_2[10] = 0x1149;
  param_2[0xb] = iVar3;
  param_2 = param_2 + 0xc;
  iVar3 = 0x1e;
  do {
    *param_2 = 0x80000000;
    param_2 = param_2 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return;
}

/* FUN_00006042 @ 0x6042 (640 bytes) */
int FUN_00006042(param_1, param_2, param_3)
  undefined4 param_1;
  int *param_2;
  int param_3;
{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined *local_3e8;
  uint local_3dc [243];
  
  iVar2 = (param_2[1] - *param_2) + 1;
  local_3e8 = &DAT_0000b500;
  _memcpy(local_3dc,&DAT_0000b500 + *param_2 * 0x18,iVar2 * 0x18);
  iVar3 = (param_2[7] - param_2[6]) + 1;
  _memcpy(local_3dc + iVar2 * 6,&DAT_0000b420 + param_2[6] * 0x18,iVar3 * 0x18);
  local_3dc[iVar2 * 6] = local_3dc[iVar2 * 6] | 0x400;
  iVar3 = iVar3 + iVar2;
  iVar2 = iVar3 * 3 + -3;
  local_3dc[iVar2 * 2] = local_3dc[iVar2 * 2] | 4;
  local_3dc[iVar2 * 2 + 1] = local_3dc[iVar2 * 2 + 1] | 0x2000000;
  iVar2 = (param_2[5] - param_2[4]) + 1;
  _memcpy(local_3dc + iVar3 * 6,&DAT_0000b500 + param_2[4] * 0x18,iVar2 * 0x18);
  local_3dc[iVar3 * 6] = local_3dc[iVar3 * 6] | 4;
  iVar2 = iVar2 + iVar3;
  iVar3 = (param_2[0xb] - param_2[10]) + 1;
  _memcpy(local_3dc + iVar2 * 6,&DAT_0000b420 + param_2[10] * 0x18,iVar3 * 0x18);
  local_3dc[iVar2 * 6] = local_3dc[iVar2 * 6] | 0x400;
  iVar3 = iVar3 + iVar2;
  iVar2 = iVar3 * 3 + -3;
  local_3dc[iVar2 * 2] = local_3dc[iVar2 * 2] | 4;
  local_3dc[iVar2 * 2 + 1] = local_3dc[iVar2 * 2 + 1] | 0x2000000;
  if (param_3 == 2) {
    local_3e8 = &DAT_0000b3a0;
  }
  iVar4 = (param_2[9] - param_2[8]) + 1;
  _memcpy(local_3dc + iVar3 * 6,local_3e8 + param_2[8] * 0x18,iVar4 * 0x18);
  local_3dc[iVar3 * 6] = local_3dc[iVar3 * 6] | 4;
  iVar4 = iVar4 + iVar3;
  iVar2 = iVar4 + -1;
  local_3dc[iVar2 * 6] = local_3dc[iVar2 * 6] | 0x100;
  puVar1 = (undefined4 *)FUN_0000853d(param_1,0,(iVar4 * 3 & 0x1fffffffU) << 1,local_3dc);
  *puVar1 = 0x118e;
  puVar1[1] = 0;
  puVar1[2] = 0x118c;
  iVar2 = iVar2 * 0x10000;
  puVar1[3] = iVar2;
  puVar1[4] = 0x118d;
  puVar1[5] = iVar2;
  return puVar1 + 6;
}

/* FUN_000062c2 @ 0x62c2 (632 bytes) */
int FUN_000062c2(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  uint param_2;
  int param_3;
  undefined4 *param_4;
  int param_5;
  int param_6;
{
  undefined *puVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  uint local_24;
  uint local_20;
  
  if (param_5 == '\0') {
    if (*(int *)(param_1 + 0x55c) == 3) {
      puVar1 = &UNK_0000bc60 + param_2 * 0x34;
    }
    else {
      puVar1 = &UNK_0000b740 + param_2 * 0x34;
    }
  }
  else if (*(int *)(param_1 + 0x55c) == 3) {
    puVar1 = &UNK_0000c5e0 + param_2 * 0x34;
  }
  else {
    puVar1 = &UNK_0000c0c0 + param_2 * 0x34;
  }
  if (param_6 == 1) {
    iVar4 = *(int *)(param_1 + 0x55c);
    if ((iVar4 == 3) && (param_2 < 3)) {
      local_24 = *(uint *)(param_1 + 0x588);
    }
    else {
      local_24 = *(int *)(param_1 + 0x588) * 2;
    }
    puVar5 = *(undefined4 **)(param_1 + 0x15148);
  }
  else {
    iVar4 = *(int *)(param_1 + 0x55c);
    if ((iVar4 == 3) && (param_2 < 3)) {
      local_24 = *(uint *)(param_1 + 0x588) >> 1;
    }
    else {
      local_24 = *(uint *)(param_1 + 0x588);
    }
    puVar5 = *(undefined4 **)(param_1 + 0x15150);
  }
  if (iVar4 == 3) {
    if ((((param_2 - 5 < 2) || (param_2 == 9)) || (param_2 == 10)) ||
       (((param_2 == 0xf || (param_2 == 0x10)) || ((param_2 == 0x11 || (param_2 == 0x12)))))) {
      local_20 = 1;
    }
    else {
      local_20 = 0;
    }
  }
  else {
    local_20 = (uint)(iVar4 == 2);
  }
  *puVar5 = 0x1393;
  puVar5[1] = 10;
  puVar5[2] = 0x5c8;
  puVar5[3] = 0x20000;
  puVar5[4] = 0x1040;
  puVar5[5] = 0;
  puVar3 = (undefined4 *)((int (*)())FUN_00006042)(puVar5 + 6,puVar1,param_6);
  *puVar3 = 0x1041;
  puVar3[1] = *(undefined4 *)(puVar1 + 0x30);
  puVar3[2] = (param_3 + 5) * 0x10000 | 0xc0003a00;
  puVar3[3] = 0xc0000;
  *(int *)(param_1 + 0x1515c) = (int)puVar3 + (0x10 - (int)puVar5) >> 2;
  puVar3[4] = local_20;
  puVar3[5] = local_24;
  puVar3[6] = param_3 << 0x12 | 0x81d;
  puVar5 = puVar3 + 8;
  puVar3[7] = param_3;
  if (param_3 != 0) {
    iVar4 = 0;
    do {
      uVar2 = *param_4;
      param_4 = param_4 + 1;
      *puVar5 = uVar2;
      iVar4 = iVar4 + 1;
      puVar5 = puVar5 + 1;
    } while (param_3 != iVar4);
  }
  *puVar5 = 0xdeadbeef;
  puVar5[1] = 0x1393;
  puVar5[2] = 10;
  if (param_6 == 1) {
    *(undefined4 **)(param_1 + 0x15148) = puVar5 + 3;
    return;
  }
  *(undefined4 **)(param_1 + 0x15150) = puVar5 + 3;
  return;
}

/* FUN_0000653a @ 0x653a (144 bytes) */
int FUN_0000653a(param_1, param_2, param_3)
  int *param_1;
  undefined4 param_2;
  int param_3;
{
  undefined4 *puVar1;
  
  if (param_3 == 3) {
    if (param_1[5] != 0) {
      puVar1 = (undefined4 *)param_1[8];
      param_1[8] = (int)(puVar1 + 1);
      *puVar1 = param_2;
      return 1;
    }
  }
  else if (param_3 == 4) {
    if (param_1[10] != 0) {
      puVar1 = (undefined4 *)param_1[0xd];
      param_1[0xd] = (int)(puVar1 + 1);
      *puVar1 = param_2;
      return 1;
    }
  }
  else if ((param_3 == 1) && (*param_1 != 0)) {
    puVar1 = (undefined4 *)param_1[3];
    if ((undefined4 *)param_1[4] < puVar1) {
      *param_1 = 0;
      param_1[5] = 0;
      param_1[10] = 0;
      return 0;
    }
    param_1[1] = param_1[1] + 1;
    param_1[3] = (int)(puVar1 + 1);
    *puVar1 = param_2;
    return 1;
  }
  return 0;
}

/* FUN_000065ca @ 0x65ca (1452 bytes) */
int FUN_000065ca(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  uint *puVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  int local_24;
  int local_20;
  
  piVar4 = (int *)(param_1 + 0x55c);
  puVar6 = *(undefined4 **)(param_1 + 0x34);
  if (*(undefined4 **)(param_1 + 0x38) <= puVar6 + 0xe) {
    puVar2 = *(uint **)(param_1 + 0x30);
    *puVar2 = *puVar2 | (int)puVar6 - (int)puVar2 >> 2;
    *(undefined4 **)(param_1 + 0x30) = *(undefined4 **)(param_1 + 0x34);
    **(undefined4 **)(param_1 + 0x34) = 0x1000000;
    _IOConnectMapMemory(*(undefined4 *)(param_1 + 0x14),1,*(undefined4 *)PTR_0000e0e6,param_1 + 0x40
                        ,param_1 + 0x44,1);
    iVar5 = *(int *)(param_1 + 0x40);
    *(int *)(param_1 + 0x30) = iVar5 + 0x1c;
    *(int *)(param_1 + 0x34) = iVar5 + 0x20;
    *(int *)(param_1 + 0x38) = iVar5 + 0x20 + *(int *)(iVar5 + 0x10) * 4;
    *(undefined4 *)(iVar5 + 0x1c) = 0;
    puVar6 = *(undefined4 **)(param_1 + 0x34);
  }
  *(undefined4 **)(param_1 + 0x34) = puVar6 + 0xe;
  puVar2 = *(uint **)(param_1 + 0x30);
  *puVar2 = *puVar2 | (int)puVar6 - (int)puVar2 >> 2;
  *(undefined4 **)(param_1 + 0x30) = puVar6;
  *puVar6 = 0x12000000;
  puVar6[1] = 0;
  if (*(char *)(param_1 + 0x574) == '\0') {
    puVar6[2] = 0;
    iVar5 = *piVar4;
  }
  else {
    puVar6[2] = 1;
    iVar5 = *piVar4;
  }
  if (iVar5 == 2) {
    puVar6[3] = 1;
    iVar5 = *piVar4;
  }
  else {
    puVar6[3] = 0;
    iVar5 = *piVar4;
  }
  if (iVar5 == 3) {
    puVar6[4] = 0;
  }
  else {
    puVar6[4] = 1;
  }
  puVar6[5] = 1;
  puVar6[6] = 0x80000000;
  puVar6[7] = 0x80000000;
  puVar6[8] = *(undefined4 *)(param_1 + 0x153d4);
  puVar6[9] = *(undefined4 *)(param_1 + 0x568);
  puVar6[10] = *(undefined4 *)(param_1 + 0x56c);
  puVar6[0xb] = *(undefined4 *)(param_1 + 0x570);
  if (*(int *)(param_1 + 0x560) == 3) {
    puVar6[0xc] = 1;
  }
  else {
    puVar6[0xc] = 0;
  }
  puVar6[0xd] = 1;
  puVar7 = *(undefined4 **)(param_1 + 0x34);
  if (*(undefined4 **)(param_1 + 0x38) <= puVar7 + 2) {
    puVar2 = *(uint **)(param_1 + 0x30);
    *puVar2 = *puVar2 | (int)puVar7 - (int)puVar2 >> 2;
    *(undefined4 **)(param_1 + 0x30) = *(undefined4 **)(param_1 + 0x34);
    **(undefined4 **)(param_1 + 0x34) = 0x1000000;
    _IOConnectMapMemory(*(undefined4 *)(param_1 + 0x14),1,*(undefined4 *)PTR_0000e0e6,param_1 + 0x40
                        ,param_1 + 0x44,1);
    iVar5 = *(int *)(param_1 + 0x40);
    *(int *)(param_1 + 0x30) = iVar5 + 0x1c;
    *(int *)(param_1 + 0x34) = iVar5 + 0x20;
    *(int *)(param_1 + 0x38) = iVar5 + 0x20 + *(int *)(iVar5 + 0x10) * 4;
    *(undefined4 *)(iVar5 + 0x1c) = 0;
    puVar7 = *(undefined4 **)(param_1 + 0x34);
  }
  *(undefined4 **)(param_1 + 0x34) = puVar7 + 2;
  *puVar7 = 0x80000000;
  puVar7[1] = 0x80000000;
  iVar5 = *(int *)(param_1 + 0x34);
  if (*(uint *)(param_1 + 0x38) <= (uint)(iVar5 + param_2 * 4)) {
    puVar2 = *(uint **)(param_1 + 0x30);
    *puVar2 = *puVar2 | iVar5 - (int)puVar2 >> 2;
    *(undefined4 **)(param_1 + 0x30) = *(undefined4 **)(param_1 + 0x34);
    **(undefined4 **)(param_1 + 0x34) = 0x1000000;
    _IOConnectMapMemory(*(undefined4 *)(param_1 + 0x14),1,*(undefined4 *)PTR_0000e0e6,param_1 + 0x40
                        ,param_1 + 0x44,1);
    iVar5 = *(int *)(param_1 + 0x40);
    *(int *)(param_1 + 0x30) = iVar5 + 0x1c;
    *(int *)(param_1 + 0x34) = iVar5 + 0x20;
    *(int *)(param_1 + 0x38) = iVar5 + 0x20 + *(int *)(iVar5 + 0x10) * 4;
    *(undefined4 *)(iVar5 + 0x1c) = 0;
    iVar5 = *(int *)(param_1 + 0x34);
  }
  iVar1 = param_2 * 4 + iVar5;
  *(int *)(param_1 + 0x34) = iVar1;
  *(int *)(param_1 + 0x15138) = iVar5;
  *(int *)(param_1 + 0x1513c) = iVar1 + -4;
  *(int *)(param_1 + 0x15140) = iVar5;
  *(int *)(param_1 + 0x15144) = iVar5;
  iVar5 = ((int (*)())FUN_00005e72)(param_1,iVar5,1);
  *(int *)(param_1 + 0x15148) = iVar5;
  puVar6[6] = iVar5 - *(int *)(param_1 + 0x15138) >> 2;
  iVar5 = *(int *)(param_1 + 0x1513c) - *(int *)(param_1 + 0x15148);
  iVar5 = ((iVar5 >> 2) - (iVar5 >> 0x1f) >> 1) * 4 + *(int *)(param_1 + 0x15138);
  *(int *)(param_1 + 0x1514c) = iVar5;
  iVar5 = ((int (*)())FUN_00005e72)(param_1,iVar5,2);
  *(int *)(param_1 + 0x15150) = iVar5;
  puVar6[7] = iVar5 - *(int *)(param_1 + 0x15138) >> 2;
  local_20 = 0;
  local_24 = 0;
  do {
    while( true ) {
      piVar4 = (int *)(local_24 + param_1 + 0x143fc);
      iVar5 = (*(int *)(param_1 + 0x143f8) - *piVar4) + -1;
      if (iVar5 != 0) break;
      if (piVar4[1] == 0) goto LAB_000067bb;
LAB_000068b6:
      piVar3 = *(int **)(param_1 + 0x15148);
      *(int **)(param_1 + 0x15148) = piVar3 + 2;
      ((int (*)())FUN_000062c2)(param_1,local_20,piVar4[1],piVar4[2],0,1);
      *piVar3 = (*(int *)(param_1 + 0x15148) - (int)piVar3 >> 2) + -2;
      piVar3[1] = *(int *)(param_1 + 0x1515c);
      piVar3 = *(int **)(param_1 + 0x15150);
      *(int **)(param_1 + 0x15150) = piVar3 + 2;
      ((int (*)())FUN_000062c2)(param_1,local_20,piVar4[1],piVar4[2],0,2);
      *piVar3 = (*(int *)(param_1 + 0x15150) - (int)piVar3 >> 2) + -2;
      piVar3[1] = *(int *)(param_1 + 0x1515c);
      local_20 = local_20 + 1;
      local_24 = local_24 + 0xc;
      if (local_20 == 0x19) goto LAB_00006981;
    }
    piVar3 = *(int **)(param_1 + 0x15148);
    *(int **)(param_1 + 0x15148) = piVar3 + 2;
    ((int (*)())FUN_000062c2)(param_1,local_20,iVar5,piVar4[2] + 4 + *piVar4 * 4,1,1);
    *piVar3 = (*(int *)(param_1 + 0x15148) - (int)piVar3 >> 2) + -2;
    piVar3[1] = *(int *)(param_1 + 0x1515c);
    piVar3 = *(int **)(param_1 + 0x15150);
    *(int **)(param_1 + 0x15150) = piVar3 + 2;
    ((int (*)())FUN_000062c2)(param_1,local_20,iVar5,piVar4[2] + 4 + *piVar4 * 4,1,2);
    *piVar3 = (*(int *)(param_1 + 0x15150) - (int)piVar3 >> 2) + -2;
    piVar3[1] = *(int *)(param_1 + 0x1515c);
    if (piVar4[1] != 0) goto LAB_000068b6;
LAB_000067bb:
    local_20 = local_20 + 1;
    local_24 = local_24 + 0xc;
  } while (local_20 != 0x19);
LAB_00006981:
  puVar6 = *(undefined4 **)(param_1 + 0x15148);
  *(undefined4 **)(param_1 + 0x15148) = puVar6 + 1;
  *puVar6 = 0;
  puVar6 = *(undefined4 **)(param_1 + 0x15150);
  *(undefined4 **)(param_1 + 0x15150) = puVar6 + 1;
  *puVar6 = 0;
  return;
}

/* FUN_00006b76 @ 0x6b76 (198 bytes) */
int FUN_00006b76(param_1)
  int param_1;
{
  uint uVar1;
  uint *puVar2;
  
  puVar2 = *(uint **)(param_1 + 0x10);
  for (uVar1 = *(int *)(param_1 + 0x14) - (int)puVar2 >> 2; 0x4001 < uVar1; uVar1 = uVar1 - 0x4001)
  {
    *puVar2 = 0xffff1000;
    puVar2 = (uint *)(&DAT_00010004 + *(int *)(param_1 + 0x10));
    *(uint **)(param_1 + 0x10) = puVar2;
  }
  if (uVar1 != 0) {
    if (uVar1 < 2) {
      *(uint **)(param_1 + 0x10) = puVar2 + 1;
      *puVar2 = 0x80000000;
    }
    else {
      *(uint **)(param_1 + 0x10) = puVar2 + 1;
      *puVar2 = (uVar1 - 2) * 0x10000 | 0xc0001000;
    }
  }
  puVar2 = *(uint **)(param_1 + 0x18);
  for (uVar1 = (*(int *)(param_1 + 4) - (int)puVar2 >> 2) + 1; 0x4001 < uVar1;
      uVar1 = uVar1 - 0x4001) {
    *puVar2 = 0xffff1000;
    puVar2 = (uint *)(&DAT_00010004 + *(int *)(param_1 + 0x18));
    *(uint **)(param_1 + 0x18) = puVar2;
  }
  if (uVar1 != 0) {
    if (uVar1 < 2) {
      *(uint **)(param_1 + 0x18) = puVar2 + 1;
      *puVar2 = 0x80000000;
      return;
    }
    *(uint **)(param_1 + 0x18) = puVar2 + 1;
    *puVar2 = (uVar1 - 2) * 0x10000 | 0xc0001000;
  }
  return;
}

/* FUN_00006c3c @ 0x6c3c (1048 bytes) */
int FUN_00006c3c(param_1)
  int param_1;
{
  int iVar1;
  uint *puVar2;
  char cVar3;
  int *piVar4;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  int local_30;
  int local_2c;
  int local_20;
  
  piVar4 = (int *)(param_1 + 0x55c);
  iVar1 = *(int *)(param_1 + 0x568);
  if (*(int *)(param_1 + 0x560) == 1) {
    if (*(int *)(param_1 + 0x150f8) == *(int *)(param_1 + 0x150f0)) {
      return;
    }
    cVar3 = ((int (*)())FUN_0000501b)(param_1,0);
    if (cVar3 != '\0') {
      return;
    }
    *(undefined1 *)(*(int *)(param_1 + 0x568) + 0x52c + (int)piVar4) = 1;
    return;
  }
  if ((((*(int *)(param_1 + 0x55c) == 3) || (*(char *)(param_1 + 0x574) != '\0')) &&
      (*(int *)(param_1 + 0x150f8) != *(int *)(param_1 + 0x150f0))) &&
     (cVar3 = ((int (*)())FUN_0000501b)(param_1,0), cVar3 == '\0')) {
    *(undefined1 *)(*(int *)(param_1 + 0x568) + 0x52c + (int)piVar4) = 1;
  }
  if (*(int *)(param_1 + 0x1511c) == *(int *)(param_1 + 0x15114)) {
    puVar5 = *(undefined4 **)(param_1 + 0x34);
    if (*(undefined4 **)(param_1 + 0x38) <= puVar5 + 4) {
LAB_00006d45:
      local_2c = param_1 + 0x40;
      local_30 = param_1 + 0x44;
      puVar2 = *(uint **)(param_1 + 0x30);
      *puVar2 = *puVar2 | (int)puVar5 - (int)puVar2 >> 2;
      *(undefined4 **)(param_1 + 0x30) = *(undefined4 **)(param_1 + 0x34);
      **(undefined4 **)(param_1 + 0x34) = 0x1000000;
      _IOConnectMapMemory(*(undefined4 *)(param_1 + 0x14),1,*(undefined4 *)PTR_0000e0e6,local_2c,
                          local_30,1);
      iVar7 = *(int *)(param_1 + 0x40);
      *(int *)(param_1 + 0x30) = iVar7 + 0x1c;
      *(int *)(param_1 + 0x34) = iVar7 + 0x20;
      *(int *)(param_1 + 0x38) = iVar7 + 0x20 + *(int *)(iVar7 + 0x10) * 4;
      *(undefined4 *)(iVar7 + 0x1c) = 0;
      puVar5 = *(undefined4 **)(param_1 + 0x34);
    }
  }
  else {
    cVar3 = ((int (*)())FUN_0000501b)(param_1,1);
    if (cVar3 == '\0') {
      *(undefined1 *)(*(int *)(param_1 + 0x568) + 0x52c + (int)piVar4) = 1;
      *(undefined4 *)(*(int *)(param_1 + 0x15138) + -0xc) = 0;
      goto LAB_00006e8a;
    }
    iVar7 = *(int *)(param_1 + 0x15138);
    *(undefined4 *)(iVar7 + -8) = 0x5c8;
    *(undefined4 *)(iVar7 + -4) = 0x8000000;
    puVar5 = *(undefined4 **)(param_1 + 0x34);
    if (*(undefined4 **)(param_1 + 0x38) <= puVar5 + 2) {
      puVar2 = *(uint **)(param_1 + 0x30);
      *puVar2 = *puVar2 | (int)puVar5 - (int)puVar2 >> 2;
      *(undefined4 **)(param_1 + 0x30) = *(undefined4 **)(param_1 + 0x34);
      **(undefined4 **)(param_1 + 0x34) = 0x1000000;
      _IOConnectMapMemory(*(undefined4 *)(param_1 + 0x14),1,*(undefined4 *)PTR_0000e0e6,
                          param_1 + 0x40,param_1 + 0x44,1);
      iVar7 = *(int *)(param_1 + 0x40);
      *(int *)(param_1 + 0x30) = iVar7 + 0x1c;
      *(int *)(param_1 + 0x34) = iVar7 + 0x20;
      *(int *)(param_1 + 0x38) = iVar7 + 0x20 + *(int *)(iVar7 + 0x10) * 4;
      *(undefined4 *)(iVar7 + 0x1c) = 0;
      puVar5 = *(undefined4 **)(param_1 + 0x34);
    }
    *(undefined4 **)(param_1 + 0x34) = puVar5 + 2;
    *puVar5 = 0x7eb;
    puVar5[1] = 0x4000;
    puVar5 = *(undefined4 **)(param_1 + 0x34);
    if (*(undefined4 **)(param_1 + 0x38) <= puVar5 + 4) goto LAB_00006d45;
  }
  *(undefined4 **)(param_1 + 0x34) = puVar5 + 4;
  *puVar5 = 0x1393;
  puVar5[1] = 10;
  puVar5[2] = 0x5c8;
  puVar5[3] = 0x20000;
  ((int (*)())FUN_00006b76)(param_1 + 0x15138);
  iVar7 = (*(uint *)(param_1 + 0x57c) >> 4) * *(int *)(param_1 + 0x15178);
  local_20 = 0;
  do {
    iVar6 = iVar1 * 4 + local_20;
    FUN_0000a69c(param_1,*(undefined4 *)(param_1 + 0x151c8 + iVar6 * 4),iVar7);
    FUN_0000a69c(param_1,*(undefined4 *)(param_1 + 0x15218 + iVar6 * 4),iVar7);
    local_20 = local_20 + 1;
  } while (local_20 != 4);
LAB_00006e8a:
  local_2c = param_1 + 0x40;
  local_30 = param_1 + 0x44;
  puVar2 = *(uint **)(param_1 + 0x30);
  *puVar2 = *puVar2 | *(int *)(param_1 + 0x34) - (int)puVar2 >> 2;
  *(undefined4 **)(param_1 + 0x30) = *(undefined4 **)(param_1 + 0x34);
  **(undefined4 **)(param_1 + 0x34) = 0x1000000;
  _IOConnectMapMemory(*(undefined4 *)(param_1 + 0x14),1,*(undefined4 *)PTR_0000e0e6,local_2c,
                      local_30,1);
  iVar1 = *(int *)(param_1 + 0x40);
  *(int *)(param_1 + 0x30) = iVar1 + 0x1c;
  *(int *)(param_1 + 0x34) = iVar1 + 0x20;
  *(int *)(param_1 + 0x38) = iVar1 + 0x20 + *(int *)(iVar1 + 0x10) * 4;
  *(undefined4 *)(iVar1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0xaa0 + *(int *)(param_1 + 0xa98) * 8) =
       *(undefined4 *)(*(int *)(param_1 + 0x40) + 0x18);
  if (((*piVar4 != 3) && (*(char *)(param_1 + 0x574) == '\0')) &&
     (*(int *)(param_1 + 0x150f8) != *(int *)(param_1 + 0x150f0))) {
    ((int (*)())FUN_0000501b)(param_1,0);
  }
  return;
}

/* FUN_00007054 @ 0x7054 (293 bytes) */
int FUN_00007054(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  undefined4 local_18;
  
  if (param_3 == 0) {
    local_18 = param_1 + 0x150f0;
  }
  else {
    local_18 = param_1 + 0x15114;
  }
  param_2 = param_2 * 4;
  uVar5 = *(int *)(local_18 + 8) + param_2;
  if (*(uint *)(local_18 + 4) < uVar5) {
    if (param_3 == 0) {
      ((int (*)())FUN_0000501b)(param_1,0);
      uVar5 = param_2 + *(int *)(local_18 + 8);
    }
    else {
      iVar3 = param_1 + 0x55c;
      iVar6 = 0;
      iVar7 = 0;
      iVar2 = 0x19;
      iVar4 = iVar3;
      do {
        if (*(int *)(iVar4 + 0x13ea4) != 0) {
          iVar6 = iVar6 + 1;
          iVar7 = iVar7 + *(int *)(iVar4 + 0x13ea4);
        }
        iVar1 = (*(int *)(param_1 + 0x143f8) - *(int *)(iVar4 + 0x13ea0)) + -1;
        if (iVar1 != 0) {
          iVar6 = iVar6 + 1;
          iVar7 = iVar7 + iVar1;
        }
        iVar4 = iVar4 + 0xc;
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
      ((int (*)())FUN_000065ca)(param_1,(iVar7 + iVar6 * 0x80) * 2 + 1000);
      ((int (*)())FUN_00006c3c)(param_1);
      do {
        *(undefined4 *)(iVar3 + 0x13ea4) = 0;
        *(int *)(iVar3 + 0x13ea0) = *(int *)(param_1 + 0x143f8) + -1;
        iVar3 = iVar3 + 0xc;
      } while (iVar3 != param_1 + 0x688);
      uVar5 = param_2 + *(int *)(local_18 + 8);
    }
  }
  *(uint *)(local_18 + 8) = uVar5;
  return;
}

