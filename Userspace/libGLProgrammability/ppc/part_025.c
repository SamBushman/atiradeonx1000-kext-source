#include "decls.h"

/* __cxxabiv1____terminate @ 0x97c19de8 (32 bytes) */
#if 0   /* compile-failing as plain C: Ghidra text kept verbatim, see ledger status */
int __cxxabiv1____terminate(param_1)
  unsigned char * param_1;
{
  (*param_1)();
                    
  _abort();
}
#endif

/* std__terminate @ 0x97c19e0c (56 bytes) */
int std__terminate()
{
  unsigned char * p_Var1;
  
  p_Var1 = (unsigned char *)__keymgr_get_per_thread_data(4);
  if (p_Var1 != (unsigned char *)0x0) {
    __cxxabiv1____terminate_handler = p_Var1;
  }
                    
  ((int (*)())__cxxabiv1____terminate)(__cxxabiv1____terminate_handler);
}

/* __cxxabiv1____unexpected @ 0x97c19e44 (28 bytes) */
#if 0   /* compile-failing as plain C: Ghidra text kept verbatim, see ledger status */
int __cxxabiv1____unexpected(param_1)
  unsigned char * param_1;
{
  unsigned char * p_Var1;
  int iVar2;
  int iVar3;
  
  (*param_1)();
  ((int (*)())std__terminate)();
  p_Var1 = (unsigned char *)__keymgr_get_per_thread_data(3);
  if (p_Var1 != (unsigned char *)0x0) {
    __unexpected_handler = p_Var1;
  }
  iVar2 = ((int (*)())__cxxabiv1____unexpected)(__unexpected_handler);
  iVar3 = __keymgr_get_per_thread_data(4);
  __keymgr_set_per_thread_data(4,iVar2);
  if (iVar3 == 0) {
    iVar3 = __terminate_handler;
  }
  __terminate_handler = iVar2;
  return iVar3;
}
#endif

/* std__unexpected @ 0x97c19e60 (56 bytes) */
int std__unexpected()
{
  unsigned char * p_Var1;
  undefined4 uVar2;
  int iVar3;
  
  p_Var1 = (unsigned char *)__keymgr_get_per_thread_data(3);
  if (p_Var1 != (unsigned char *)0x0) {
    __cxxabiv1____unexpected_handler = p_Var1;
  }
  uVar2 = ((int (*)())__cxxabiv1____unexpected)(__cxxabiv1____unexpected_handler);
  iVar3 = __keymgr_get_per_thread_data(4);
  __keymgr_set_per_thread_data(4,uVar2);
  if (iVar3 == 0) {
    iVar3 = __cxxabiv1____terminate_handler;
  }
  __cxxabiv1____terminate_handler = uVar2;
  return iVar3;
}

/* std__set_terminate @ 0x97c19e98 (100 bytes) */
int std__set_terminate(param_1)
  unsigned char * param_1;
{
  int iVar1;
  
  iVar1 = __keymgr_get_per_thread_data(4);
  __keymgr_set_per_thread_data(4,param_1);
  if (iVar1 == 0) {
    iVar1 = (int)__cxxabiv1____terminate_handler;
  }
  __cxxabiv1____terminate_handler = param_1;
  return iVar1;
}

/* std__set_unexpected @ 0x97c19f0c (100 bytes) */
int std__set_unexpected(param_1)
  unsigned char * param_1;
{
  int iVar1;
  
  iVar1 = __keymgr_get_per_thread_data(3);
  __keymgr_set_per_thread_data(3,param_1);
  if (iVar1 == 0) {
    iVar1 = (int)__cxxabiv1____unexpected_handler;
  }
  __cxxabiv1____unexpected_handler = param_1;
  return iVar1;
}

/* ___cxa_begin_catch @ 0x97c19f80 (108 bytes) */
int ___cxa_begin_catch(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  piVar3 = (int *)((int (*)())___cxa_get_globals)();
  iVar2 = *(int *)(param_1 + -0x1c);
  iVar1 = *piVar3;
  if (iVar2 < 0) {
    iVar2 = -iVar2;
  }
  *(int *)(param_1 + -0x1c) = iVar2 + 1;
  piVar3[1] = piVar3[1] + -1;
  if (param_1 + -0x30 != iVar1) {
    *(int *)(param_1 + -0x20) = iVar1;
    *piVar3 = param_1 + -0x30;
  }
  return *(undefined4 *)(param_1 + -8);
}

/* ___cxa_end_catch @ 0x97c19fec (144 bytes) */
int ___cxa_end_catch()
{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  piVar1 = (int *)((int (*)())___cxa_get_globals_fast)();
  iVar2 = *piVar1;
  iVar3 = *(int *)(iVar2 + 0x14);
  if (iVar3 < 0) {
    iVar3 = iVar3 + 1;
    if (iVar3 == 0) {
      piVar1[1] = piVar1[1] + 1;
      *piVar1 = *(int *)(iVar2 + 0x10);
    }
  }
  else {
    iVar3 = iVar3 + -1;
    if (iVar3 == 0) {
      *piVar1 = *(int *)(iVar2 + 0x10);
      ((int (*)())__Unwind_DeleteException)((unsigned char *)(iVar2 + 0x30));
      return;
    }
    if (iVar3 < 0) {
                    
      _abort();
    }
  }
  *(int *)(iVar2 + 0x14) = iVar3;
  return;
}

/* std__uncaught_exception @ 0x97c1a07c (44 bytes) */
int std__uncaught_exception()
{
  int iVar1;
  
  iVar1 = ((int (*)())___cxa_get_globals)();
  return *(int *)(iVar1 + 4) != 0;
}

/* get_globals_init_once @ 0x97c1a0a8 (32 bytes) */
int get_globals_init_once()
{
  _use_thread_key = 1;
  return;
}

/* ___cxa_get_globals_fast @ 0x97c1a0c8 (52 bytes) */
int ___cxa_get_globals_fast()
{
  undefined *puVar1;
  
  if (_use_thread_key != 0) {
    puVar1 = (undefined *)__keymgr_get_per_thread_data(0xd);
    return puVar1;
  }
  return &_globals_static;
}

/* ___cxa_get_globals @ 0x97c1a0fc (220 bytes) */
int ___cxa_get_globals()
{
  undefined4 *puVar1;
  int iVar2;
  
  if ((_use_thread_key == 0) ||
     ((_use_thread_key < 0 && (((int (*)())get_globals_init_once)(), _use_thread_key == 0)))) {
    return (undefined4 *)&_globals_static;
  }
  puVar1 = (undefined4 *)__keymgr_get_per_thread_data(0xd);
  if (puVar1 != (undefined4 *)0x0) {
    return puVar1;
  }
  puVar1 = _malloc(8);
  if (puVar1 != (undefined4 *)0x0) {
    if ((*(int *)(PTR_DAT_a7b7c190 + 8) == 0) ||
       (*(ushort *)(*(int *)(PTR_DAT_a7b7c190 + 8) + 4) < 4)) {
      __keymgr_set_per_thread_data(0xd,puVar1);
      goto LAB_97c1a1b4;
    }
    iVar2 = __keymgr_set_per_thread_data(0xd,puVar1);
    if (iVar2 == 0) goto LAB_97c1a1b4;
  }
  ((int (*)())std__terminate)();
LAB_97c1a1b4:
  puVar1[1] = 0;
  *puVar1 = 0;
  return puVar1;
}

/* ___eprintf @ 0x97c1a1d8 (76 bytes) */
int ___eprintf(param_1, param_2, param_3, param_4)
  char *param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  undefined *puVar1;
  
  puVar1 = PTR_DAT_a7b7c0bc;
  _fprintf((FILE *)(PTR_DAT_a7b7c0bc + 0xb0),param_1,param_2,param_3,param_4);
  _fflush((FILE *)(puVar1 + 0xb0));
                    
  _abort();
}

/* FUN_97c1a23c @ 0x97c1a23c (16 bytes) */
int FUN_97c1a23c()
{
  return;
}

/* FUN_97c1a24c @ 0x97c1a24c (12 bytes) */
int FUN_97c1a24c()
{
  return;
}

/* FUN_97c1a258 @ 0x97c1a258 (4 bytes) */
int FUN_97c1a258()
{
  return;
}

/* FUN_97c1a25c @ 0x97c1a25c (24 bytes) */
int FUN_97c1a25c()
{
  return;
}

/* FUN_97c1a28c @ 0x97c1a28c (60 bytes) */
int FUN_97c1a28c()
{
  return;
}

/* _size_of_encoded_value @ 0x97c1a2c8 (120 bytes) */
int _size_of_encoded_value(param_1)
  uint param_1;
{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (param_1 != 0xff) {
    param_1 = param_1 & 7;
    uVar1 = 2;
    if (param_1 != 2) {
      if (param_1 < 3) {
        if (param_1 != 0) {
LAB_97c1a328:
                    
          _abort();
        }
        uVar1 = 4;
      }
      else {
        uVar1 = 4;
        if (param_1 != 3) {
          if (param_1 != 4) goto LAB_97c1a328;
          uVar1 = 8;
        }
      }
    }
  }
  return uVar1;
}

/* _base_of_encoded_value @ 0x97c1a340 (172 bytes) */
int _base_of_encoded_value(param_1, param_2)
  uint param_1;
  unsigned char * param_2;
{
  bool bVar1;
  unsigned char uVar2;
  
  if (param_1 != 0xff) {
    param_1 = param_1 & 0x70;
    if (param_1 == 0x20) {
      uVar2 = ((int (*)())__Unwind_GetTextRelBase)(param_2);
      return uVar2;
    }
    if (param_1 < 0x21) {
      if (param_1 == 0) {
        return 0;
      }
      bVar1 = param_1 == 0x10;
    }
    else {
      if (param_1 == 0x40) {
        uVar2 = ((int (*)())__Unwind_GetRegionStart)(param_2);
        return uVar2;
      }
      if (param_1 < 0x41) {
        if (param_1 == 0x30) {
          uVar2 = ((int (*)())__Unwind_GetDataRelBase)(param_2);
          return uVar2;
        }
        goto LAB_97c1a3d4;
      }
      bVar1 = param_1 == 0x50;
    }
    if (!bVar1) {
LAB_97c1a3d4:
                    
      _abort();
    }
  }
  return 0;
}

/* _read_uleb128 @ 0x97c1a3ec (48 bytes) */
int _read_uleb128(param_1, param_2)
  byte *param_1;
  uint *param_2;
{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = 0;
  uVar4 = 0;
  do {
    bVar1 = *param_1;
    param_1 = param_1 + 1;
    uVar2 = uVar3 & 0x3f;
    uVar3 = uVar3 + 7;
    uVar4 = uVar4 | (bVar1 & 0x7f) << uVar2;
  } while ((bVar1 & 0x80) != 0);
  *param_2 = uVar4;
  return;
}

/* _read_sleb128 @ 0x97c1a41c (76 bytes) */
int _read_sleb128(param_1, param_2)
  byte *param_1;
  uint *param_2;
{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = 0;
  uVar4 = 0;
  do {
    bVar1 = *param_1;
    param_1 = param_1 + 1;
    uVar2 = uVar3 & 0x3f;
    uVar3 = uVar3 + 7;
    uVar4 = uVar4 | (bVar1 & 0x7f) << uVar2;
  } while ((bVar1 & 0x80) != 0);
  if ((uVar3 < 0x20) && ((bVar1 & 0x40) != 0)) {
    uVar4 = uVar4 | -1 << (uVar3 & 0x3f);
  }
  *param_2 = uVar4;
  return;
}

/* _read_encoded_value_with_base @ 0x97c1a468 (312 bytes) */
int _read_encoded_value_with_base(param_1, param_2, param_3, param_4)
  uint param_1;
  uint *param_2;
  uint *param_3;
  uint *param_4;
{
  uint *puVar1;
  uint *local_30;
  uint *local_2c [6];
  
  if (param_1 == 0x50) {
    local_2c[0] = (uint *)((int)param_3 + 3U & 0xfffffffc);
    puVar1 = local_2c[0] + 1;
    goto LAB_97c1a5b4;
  }
  switch(param_1 & 0xf) {
  case 0:
  case 3:
  case 0xb:
    local_2c[0] = (uint *)*param_3;
    puVar1 = param_3 + 1;
    break;
  case 1:
    puVar1 = (uint *)((int (*)())_read_uleb128)(param_3,&local_30);
    local_2c[0] = local_30;
    break;
  case 2:
    local_2c[0] = (uint *)(uint)*(ushort *)param_3;
    goto LAB_97c1a540;
  case 4:
  case 0xc:
    puVar1 = param_3 + 2;
    local_2c[0] = (uint *)((uint)*(byte *)((int)param_3 + 7) |
                          (uint)*(byte *)((int)param_3 + 6) << 8 |
                          (uint)*(byte *)((int)param_3 + 5) << 0x10 |
                          (uint)*(byte *)(param_3 + 1) << 0x18);
    break;
  default:
                    
    _abort();
  case 9:
    puVar1 = (uint *)((int (*)())_read_sleb128)(param_3,local_2c);
    break;
  case 10:
    local_2c[0] = (uint *)(int)(short)*(ushort *)param_3;
LAB_97c1a540:
    puVar1 = (uint *)((int)param_3 + 2);
  }
  if (local_2c[0] != (uint *)0x0) {
    if ((param_1 & 0x70) == 0x10) {
      param_2 = param_3;
    }
    local_2c[0] = (uint *)((int)local_2c[0] + (int)param_2);
    if ((param_1 & 0x80) != 0) {
LAB_97c1a5b4:
      local_2c[0] = (uint *)*local_2c[0];
    }
  }
  *param_4 = (uint)local_2c[0];
  return puVar1;
}

/* __Unwind_GetLanguageSpecificData @ 0x97c1a5d4 (8 bytes) */
int __Unwind_GetLanguageSpecificData(context)
  unsigned char * context;
{
  return *(unsigned char *)(context + 0x1c4);
}

/* __Unwind_GetRegionStart @ 0x97c1a5dc (8 bytes) */
int __Unwind_GetRegionStart(context)
  unsigned char * context;
{
  return *(unsigned char *)(context + 0x1d0);
}

/* __Unwind_FindEnclosingFunction @ 0x97c1a5e4 (56 bytes) */
#if 0   /* compile-failing as plain C: Ghidra text kept verbatim, see ledger status */
int __Unwind_FindEnclosingFunction(pc)
  void *pc;
{
  void *pvVar1;
  void *pvVar2;
  unsigned char adStack_20 [2];
  
  pvVar1 = __Unwind_Find_FDE((void *)((int)pc + -1),adStack_20);
  pvVar2 = (void *)0x0;
  if (pvVar1 != (void *)0x0) {
    pvVar2 = (void *)adStack_20[0].func;
  }
  return pvVar2;
}
#endif

/* __Unwind_GetDataRelBase @ 0x97c1a61c (8 bytes) */
int __Unwind_GetDataRelBase(context)
  unsigned char * context;
{
  return *(unsigned char *)(context + 0x1cc);
}

/* __Unwind_GetTextRelBase @ 0x97c1a624 (8 bytes) */
int __Unwind_GetTextRelBase(context)
  unsigned char * context;
{
  return *(unsigned char *)(context + 0x1c8);
}

/* _extract_cie_info @ 0x97c1a62c (348 bytes) */
int _extract_cie_info(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  int param_3;
{
  char *pcVar1;
  undefined1 uVar2;
  char cVar3;
  size_t sVar4;
  undefined4 uVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  char *pcVar8;
  char *pcVar9;
  int local_30 [5];
  
  pcVar9 = (char *)(param_1 + 9);
  sVar4 = _strlen(pcVar9);
  pcVar8 = pcVar9 + sVar4 + 1;
  puVar7 = (undefined1 *)0x0;
  if ((*(char *)(param_1 + 9) == 'e') && (*(char *)(param_1 + 10) == 'h')) {
    pcVar1 = pcVar9 + sVar4 + 1;
    pcVar8 = pcVar9 + sVar4 + 5;
    pcVar9 = (char *)(param_1 + 0xb);
    *(undefined4 *)(param_3 + 0x3a0) = *(undefined4 *)pcVar1;
  }
  uVar5 = ((int (*)())_read_uleb128)(pcVar8,param_3 + 0x398);
  puVar6 = (undefined1 *)((int (*)())_read_sleb128)(uVar5,param_3 + 0x394);
  uVar2 = *puVar6;
  puVar6 = puVar6 + 1;
  *(undefined1 *)(param_3 + 0x39e) = 0xff;
  *(undefined1 *)(param_3 + 0x39c) = uVar2;
  cVar3 = *pcVar9;
  if (cVar3 == 'z') {
    puVar6 = (undefined1 *)((int (*)())_read_uleb128)(puVar6,local_30);
    *(undefined1 *)(param_3 + 0x39f) = 1;
    pcVar9 = pcVar9 + 1;
    cVar3 = *pcVar9;
    puVar7 = puVar6 + local_30[0];
  }
  do {
    if (cVar3 == '\0') {
      if (puVar7 == (undefined1 *)0x0) {
        puVar7 = puVar6;
      }
      return puVar7;
    }
    if (cVar3 == 'L') {
      *(undefined1 *)(param_3 + 0x39e) = *puVar6;
LAB_97c1a718:
      puVar6 = puVar6 + 1;
    }
    else {
      if (cVar3 == 'R') {
        *(undefined1 *)(param_3 + 0x39d) = *puVar6;
        goto LAB_97c1a718;
      }
      if (cVar3 != 'P') {
        return puVar7;
      }
      uVar2 = *puVar6;
      uVar5 = ((int (*)())_base_of_encoded_value)(uVar2,param_2);
      puVar6 = (undefined1 *)((int (*)())_read_encoded_value_with_base)(uVar2,uVar5,puVar6 + 1,param_3 + 0x390);
    }
    pcVar9 = pcVar9 + 1;
    cVar3 = *pcVar9;
  } while( true );
}

/* _execute_stack_op @ 0x97c1a788 (1212 bytes) */
int _execute_stack_op(param_1, param_2, param_3, param_4)
  ushort *param_1;
  ushort *param_2;
  int param_3;
  undefined4 param_4;
{
  byte bVar1;
  ushort uVar2;
  uint *puVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  ushort *puVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint auStack_14c [67];
  uint *local_40;
  uint *local_3c;
  int local_38;
  uint local_34;
  int local_30 [7];
  
  auStack_14c[3] = param_4;
  uVar8 = 1;
  while (param_1 < param_2) {
    uVar10 = (uint)*(byte *)param_1;
    puVar7 = (ushort *)((int)param_1 + 1);
    uVar9 = uVar8;
    switch(uVar10) {
    case 3:
    case 0xc:
    case 0xd:
      puVar3 = *(uint **)puVar7;
      puVar7 = (ushort *)((int)param_1 + 5);
      break;
    default:
      goto switchD_97c1a7e8_caseD_4;
    case 6:
    case 0x19:
    case 0x1f:
    case 0x20:
    case 0x23:
    case 0x94:
      uVar9 = uVar8 - 1;
      if ((int)uVar9 < 0) goto switchD_97c1a7e8_caseD_4;
      local_40 = (uint *)auStack_14c[uVar8 + 2];
      if (uVar10 == 0x1f) {
LAB_97c1acc8:
        puVar3 = (uint *)-(int)local_40;
      }
      else {
        uVar8 = uVar9;
        if (uVar10 < 0x20) {
          if (uVar10 != 6) {
            if (uVar10 == 0x19) {
              if (-1 < (int)local_40) goto LAB_97c1ae98;
              goto LAB_97c1acc8;
            }
            goto switchD_97c1a7e8_caseD_4;
          }
LAB_97c1ac88:
          puVar3 = (uint *)*local_40;
        }
        else if (uVar10 == 0x23) {
          puVar7 = (ushort *)((int (*)())_read_uleb128)(puVar7,local_30);
          puVar3 = (uint *)((int)local_40 + local_30[0]);
        }
        else if (uVar10 < 0x24) {
          puVar3 = (uint *)~(uint)local_40;
          if (uVar10 != 0x20) goto switchD_97c1a7e8_caseD_4;
        }
        else {
          if (uVar10 != 0x94) goto switchD_97c1a7e8_caseD_4;
          bVar1 = *(byte *)puVar7;
          puVar7 = param_1 + 1;
          if (bVar1 == 2) {
            puVar3 = (uint *)(uint)*(ushort *)local_40;
          }
          else {
            if (2 < bVar1) {
              if (bVar1 == 4) goto LAB_97c1ac88;
              if (bVar1 == 8) {
                bVar1 = *(byte *)((int)local_40 + 7);
                uVar9 = (uint)*(byte *)((int)local_40 + 6) << 8 |
                        (uint)*(byte *)((int)local_40 + 5) << 0x10 |
                        (uint)*(byte *)(local_40 + 1) << 0x18;
                goto LAB_97c1acb4;
              }
              goto switchD_97c1a7e8_caseD_4;
            }
            if (bVar1 != 1) goto switchD_97c1a7e8_caseD_4;
            puVar3 = (uint *)(uint)*(byte *)local_40;
          }
        }
      }
      break;
    case 8:
      puVar3 = (uint *)(uint)*(byte *)puVar7;
      puVar7 = param_1 + 1;
      break;
    case 9:
      bVar1 = *(byte *)puVar7;
      puVar7 = param_1 + 1;
      puVar3 = (uint *)(int)(char)bVar1;
      break;
    case 10:
      puVar3 = (uint *)(uint)*puVar7;
      goto LAB_97c1aa6c;
    case 0xb:
      puVar3 = (uint *)(int)(short)*puVar7;
LAB_97c1aa6c:
      puVar7 = (ushort *)((int)param_1 + 3);
      break;
    case 0xe:
    case 0xf:
      bVar1 = *(byte *)(param_1 + 4);
      uVar9 = (uint)*(byte *)((int)param_1 + 7) << 8 |
              (uint)*(byte *)(param_1 + 3) << 0x10 | (uint)*(byte *)((int)param_1 + 5) << 0x18;
      puVar7 = (ushort *)((int)param_1 + 9);
LAB_97c1acb4:
      local_40 = (uint *)(bVar1 | uVar9);
      goto LAB_97c1ae98;
    case 0x10:
      puVar7 = (ushort *)((int (*)())_read_uleb128)(puVar7,&local_40);
      goto LAB_97c1ae98;
    case 0x11:
      puVar7 = (ushort *)((int (*)())_read_sleb128)(puVar7,&local_3c);
      puVar3 = local_3c;
      break;
    case 0x12:
      iVar4 = uVar8 << 2;
      if (0 < (int)uVar8) goto LAB_97c1ab88;
      goto switchD_97c1a7e8_caseD_4;
    case 0x13:
      uVar8 = uVar8 - 1;
      if (-1 < (int)uVar8) goto switchD_97c1a7e8_caseD_96;
      goto switchD_97c1a7e8_caseD_4;
    case 0x14:
      if (1 < (int)uVar8) {
        local_40 = (uint *)auStack_14c[uVar8 + 1];
        goto LAB_97c1aba8;
      }
      goto switchD_97c1a7e8_caseD_4;
    case 0x15:
      local_34 = (uint)*(byte *)puVar7;
      puVar7 = param_1 + 1;
      if ((int)local_34 < (int)(uVar8 - 1)) {
        iVar4 = (uVar8 - local_34) * 4;
LAB_97c1ab88:
        local_40 = *(uint **)((int)auStack_14c + iVar4 + 8);
LAB_97c1aba8:
        goto LAB_97c1ae98;
      }
      goto switchD_97c1a7e8_caseD_4;
    case 0x17:
      if (2 < (int)uVar8) {
        uVar9 = auStack_14c[uVar8 + 2];
        uVar10 = auStack_14c[uVar8];
        auStack_14c[uVar8 + 2] = auStack_14c[uVar8 + 1];
        auStack_14c[uVar8] = uVar9;
        auStack_14c[uVar8 + 1] = uVar10;
        goto switchD_97c1a7e8_caseD_96;
      }
      goto switchD_97c1a7e8_caseD_4;
    case 0x1a:
    case 0x1b:
    case 0x1c:
    case 0x1d:
    case 0x1e:
    case 0x21:
    case 0x22:
    case 0x29:
    case 0x2a:
    case 0x2b:
    case 0x2c:
    case 0x2d:
    case 0x2e:
      uVar9 = uVar8 - 2;
      if ((int)uVar9 < 0) goto switchD_97c1a7e8_caseD_4;
      uVar6 = auStack_14c[uVar8 + 1];
      uVar8 = auStack_14c[uVar8 + 2];
      switch(uVar10) {
      case 0x1a:
        puVar3 = (uint *)(uVar6 & uVar8);
        break;
      case 0x1b:
        puVar3 = (uint *)((int)uVar6 / (int)uVar8);
        break;
      case 0x1c:
        puVar3 = (uint *)(uVar6 - uVar8);
        break;
      case 0x1d:
        puVar3 = (uint *)(uVar6 - ((int)uVar6 / (int)uVar8) * uVar8);
        break;
      case 0x1e:
        puVar3 = (uint *)(uVar6 * uVar8);
        break;
      default:
        goto switchD_97c1a7e8_caseD_4;
      case 0x21:
        puVar3 = (uint *)(uVar6 | uVar8);
        break;
      case 0x22:
        puVar3 = (uint *)(uVar6 + uVar8);
        break;
      case 0x24:
        puVar3 = (uint *)(uVar6 << (uVar8 & 0x3f));
        break;
      case 0x25:
        puVar3 = (uint *)(uVar6 >> (uVar8 & 0x3f));
        break;
      case 0x26:
        puVar3 = (uint *)((int)uVar6 >> (uVar8 & 0x3f));
        break;
      case 0x27:
        puVar3 = (uint *)(uVar6 ^ uVar8);
        break;
      case 0x29:
        puVar3 = (uint *)(uint)(uVar8 == uVar6);
        break;
      case 0x2a:
        puVar3 = (uint *)0x1;
        if ((int)uVar8 < (int)uVar6) {
LAB_97c1ae34:
          puVar3 = (uint *)0x0;
        }
        break;
      case 0x2b:
        puVar3 = (uint *)0x1;
        if ((int)uVar8 <= (int)uVar6) goto LAB_97c1ae34;
        break;
      case 0x2c:
        puVar3 = (uint *)0x1;
        if ((int)uVar6 < (int)uVar8) goto LAB_97c1ae34;
        break;
      case 0x2d:
        puVar3 = (uint *)0x1;
        if ((int)uVar6 <= (int)uVar8) goto LAB_97c1ae34;
        break;
      case 0x2e:
        local_40 = (uint *)(uint)(uVar8 != uVar6);
        goto LAB_97c1ae4c;
      }
      break;
    case 0x28:
      uVar9 = uVar8 - 1;
      if (-1 < (int)uVar9) {
        uVar2 = *puVar7;
        puVar7 = (ushort *)((int)param_1 + 3);
        local_34 = (int)(short)uVar2;
        iVar4 = uVar8 + 2;
        uVar8 = uVar9;
        if (auStack_14c[iVar4] != 0) {
          puVar7 = (ushort *)((int)puVar7 + (int)(short)uVar2);
        }
        goto switchD_97c1a7e8_caseD_96;
      }
      goto switchD_97c1a7e8_caseD_4;
    case 0x2f:
      uVar2 = *puVar7;
      puVar7 = (ushort *)((int)param_1 + (int)(short)uVar2 + 3U);
      local_34 = (int)(short)uVar2;
      goto switchD_97c1a7e8_caseD_96;
    case 0x30:
    case 0x31:
    case 0x32:
    case 0x33:
    case 0x34:
    case 0x35:
    case 0x36:
    case 0x37:
    case 0x38:
    case 0x39:
    case 0x3a:
    case 0x3b:
    case 0x3c:
    case 0x3d:
    case 0x3e:
    case 0x3f:
    case 0x40:
    case 0x41:
    case 0x42:
    case 0x43:
    case 0x44:
    case 0x45:
    case 0x46:
    case 0x47:
    case 0x48:
    case 0x49:
    case 0x4a:
    case 0x4b:
    case 0x4c:
    case 0x4d:
    case 0x4e:
    case 0x4f:
      puVar3 = (uint *)(uVar10 - 0x30);
      break;
    case 0x50:
    case 0x51:
    case 0x52:
    case 0x53:
    case 0x54:
    case 0x55:
    case 0x56:
    case 0x57:
    case 0x58:
    case 0x59:
    case 0x5a:
    case 0x5b:
    case 0x5c:
    case 0x5d:
    case 0x5e:
    case 0x5f:
    case 0x60:
    case 0x61:
    case 0x62:
    case 99:
    case 100:
    case 0x65:
    case 0x66:
    case 0x67:
    case 0x68:
    case 0x69:
    case 0x6a:
    case 0x6b:
    case 0x6c:
    case 0x6d:
    case 0x6e:
    case 0x6f:
      iVar4 = uVar10 - 0x50;
      goto LAB_97c1aaf4;
    case 0x70:
    case 0x71:
    case 0x72:
    case 0x73:
    case 0x74:
    case 0x75:
    case 0x76:
    case 0x77:
    case 0x78:
    case 0x79:
    case 0x7a:
    case 0x7b:
    case 0x7c:
    case 0x7d:
    case 0x7e:
    case 0x7f:
    case 0x80:
    case 0x81:
    case 0x82:
    case 0x83:
    case 0x84:
    case 0x85:
    case 0x86:
    case 0x87:
    case 0x88:
    case 0x89:
    case 0x8a:
    case 0x8b:
    case 0x8c:
    case 0x8d:
    case 0x8e:
    case 0x8f:
      puVar7 = (ushort *)((int (*)())_read_sleb128)(puVar7,&local_34);
      iVar4 = uVar10 - 0x70;
      goto LAB_97c1ab30;
    case 0x90:
      puVar7 = (ushort *)((int (*)())_read_uleb128)(puVar7,&local_38);
      iVar4 = local_38;
LAB_97c1aaf4:
      local_40 = (uint *)**(uint **)(param_3 + iVar4 * 4);
      goto LAB_97c1aba8;
    case 0x92:
      uVar5 = ((int (*)())_read_uleb128)(puVar7,&local_38);
      puVar7 = (ushort *)((int (*)())_read_sleb128)(uVar5,&local_34);
      iVar4 = local_38;
LAB_97c1ab30:
      local_40 = (uint *)(**(int **)(param_3 + iVar4 * 4) + local_34);
LAB_97c1ae4c:
      uVar8 = uVar9;
      goto LAB_97c1ae98;
    case 0x96:
      goto switchD_97c1a7e8_caseD_96;
    }
    local_40 = puVar3;
    uVar8 = uVar9;
LAB_97c1ae98:
    if (0x3f < uVar8) goto switchD_97c1a7e8_caseD_4;
    auStack_14c[uVar8 + 4] = (uint)local_40;
    uVar8 = uVar8 + 1;
switchD_97c1a7e8_caseD_96:
    param_1 = puVar7;
  }
  if (-1 < (int)(uVar8 - 1)) {
    return auStack_14c[uVar8 + 2];
  }
switchD_97c1a7e8_caseD_4:
                    
  _abort();
}

/* _execute_cfa_program @ 0x97c1aee8 (1084 bytes) */
int _execute_cfa_program(param_1, param_2, param_3, param_4)
  uint *param_1;
  uint *param_2;
  int param_3;
  void *param_4;
{
  byte bVar1;
  undefined1 uVar2;
  int iVar3;
  uint uVar4;
  undefined4 *puVar5;
  byte bVar6;
  undefined4 uVar7;
  uint *puVar8;
  uint uVar9;
  int iVar10;
  undefined4 *puVar11;
  undefined4 *puVar12;
  uint *puVar13;
  undefined4 *puVar14;
  int local_30;
  uint local_2c;
  undefined4 local_28;
  int local_24;
  
  puVar5 = (undefined4 *)&STACKARG(0xffffff90);
  puVar11 = (undefined4 *)0x0;
  *(undefined4 *)((int)param_4 + 0x378) = 0;
  if ((param_1 < param_2) &&
     (uVar9 = *(uint *)((int)param_4 + 0x38c), uVar9 < *(uint *)(param_3 + 0x1c0))) {
    do {
      bVar1 = *(byte *)param_1;
      puVar13 = (uint *)((int)param_1 + 1);
      bVar6 = bVar1 & 0xc0;
      if (bVar6 == 0x40) {
        iVar3 = (bVar1 & 0x3f) * *(int *)((int)param_4 + 0x398);
        goto LAB_97c1b0dc;
      }
      if (bVar6 == 0x80) {
        local_2c = bVar1 & 0x3f;
LAB_97c1b0f4:
        puVar13 = (uint *)((int (*)())_read_uleb128)(puVar13,&local_30);
        iVar10 = *(int *)((int)param_4 + 0x394);
        iVar3 = local_30;
LAB_97c1b10c:
        *(undefined4 *)((int)param_4 + local_2c * 8 + 4) = 1;
        iVar3 = iVar3 * iVar10;
LAB_97c1b3a0:
        *(int *)((int)param_4 + local_2c * 8) = iVar3;
        goto switchD_97c1afc0_caseD_0;
      }
      if (bVar6 == 0xc0) {
        *(undefined4 *)((int)param_4 + (bVar1 & 0x3f) * 8 + 4) = 0;
        local_2c = bVar1 & 0x3f;
        goto switchD_97c1afc0_caseD_0;
      }
      switch(bVar1) {
      case 0:
        break;
      case 1:
        uVar2 = *(undefined1 *)((int)param_4 + 0x39d);
        uVar7 = ((int (*)())_base_of_encoded_value)(uVar2,param_3);
        puVar13 = (uint *)((int (*)())_read_encoded_value_with_base)(uVar2,uVar7,puVar13,(int)param_4 + 0x38c);
        break;
      case 2:
        uVar4 = (uint)*(byte *)puVar13;
        puVar13 = (uint *)((int)param_1 + 2);
        goto LAB_97c1b0c0;
      case 3:
        uVar4 = (uint)*(ushort *)puVar13;
        puVar13 = (uint *)((int)param_1 + 3);
LAB_97c1b0c0:
        iVar3 = *(int *)((int)param_4 + 0x398);
LAB_97c1b0d4:
        iVar3 = uVar4 * iVar3;
LAB_97c1b0dc:
        *(uint *)((int)param_4 + 0x38c) = uVar9 + iVar3;
        break;
      case 4:
        iVar3 = *(int *)((int)param_4 + 0x398);
        uVar4 = *puVar13;
        puVar13 = (uint *)((int)param_1 + 5);
        goto LAB_97c1b0d4;
      case 5:
        puVar13 = (uint *)((int (*)())_read_uleb128)(puVar13,&local_2c);
        goto LAB_97c1b0f4;
      case 6:
        puVar13 = (uint *)((int (*)())_read_uleb128)(puVar13,&local_2c);
        *(undefined4 *)((int)param_4 + local_2c * 8 + 4) = 0;
        break;
      case 7:
      case 8:
        puVar8 = &local_2c;
        goto LAB_97c1b358;
      case 9:
        uVar7 = ((int (*)())_read_uleb128)(puVar13,&local_2c);
        puVar13 = (uint *)((int (*)())_read_uleb128)(uVar7,&local_28);
        *(undefined4 *)((int)param_4 + local_2c * 8 + 4) = 2;
        *(undefined4 *)((int)param_4 + local_2c * 8) = local_28;
        break;
      case 10:
        if (puVar11 == (undefined4 *)0x0) {
          puVar14 = puVar5 + -0xe4;
          *puVar14 = *puVar5;
          puVar5 = puVar5 + -0xd4;
          puVar12 = puVar11;
        }
        else {
          puVar14 = puVar5;
          puVar12 = (undefined4 *)puVar11[0xde];
          puVar5 = puVar11;
        }
        _memcpy(puVar5,param_4,0x37c);
        *(undefined4 **)((int)param_4 + 0x378) = puVar5;
        puVar5 = puVar14;
        puVar11 = puVar12;
        break;
      case 0xb:
        puVar14 = *(undefined4 **)((int)param_4 + 0x378);
        _memcpy(param_4,puVar14,0x37c);
        puVar14[0xde] = puVar11;
        puVar11 = puVar14;
        break;
      case 0xc:
        uVar7 = ((int (*)())_read_uleb128)(puVar13,(int)param_4 + 0x380);
        puVar13 = (uint *)((int (*)())_read_uleb128)(uVar7,&local_30);
        *(int *)((int)param_4 + 0x37c) = local_30;
        *(undefined4 *)((int)param_4 + 0x388) = 1;
        break;
      case 0xd:
        puVar13 = (uint *)((int (*)())_read_uleb128)(puVar13,(int)param_4 + 0x380);
        goto LAB_97c1b2e8;
      case 0xe:
        puVar13 = (uint *)((int (*)())_read_uleb128)(puVar13,&local_30);
        *(int *)((int)param_4 + 0x37c) = local_30;
        break;
      case 0xf:
        iVar3 = ((int (*)())_read_uleb128)(puVar13,&local_30);
        *(int *)((int)param_4 + 900) = iVar3;
        *(undefined4 *)((int)param_4 + 0x388) = 2;
        puVar13 = (uint *)(iVar3 + local_30);
        break;
      case 0x10:
        uVar7 = ((int (*)())_read_uleb128)(puVar13,&local_2c);
        iVar3 = ((int (*)())_read_uleb128)(uVar7,&local_30);
        *(undefined4 *)((int)param_4 + local_2c * 8 + 4) = 3;
        *(int *)((int)param_4 + local_2c * 8) = iVar3;
        puVar13 = (uint *)(iVar3 + local_30);
        break;
      case 0x11:
        uVar7 = ((int (*)())_read_uleb128)(puVar13,&local_2c);
        puVar13 = (uint *)((int (*)())_read_sleb128)(uVar7,&local_24);
        iVar10 = *(int *)((int)param_4 + 0x394);
        iVar3 = local_24;
        goto LAB_97c1b10c;
      case 0x12:
        uVar7 = ((int (*)())_read_uleb128)(puVar13,(int)param_4 + 0x380);
        puVar13 = (uint *)((int (*)())_read_sleb128)(uVar7,(int)param_4 + 0x37c);
LAB_97c1b2e8:
        *(undefined4 *)((int)param_4 + 0x388) = 1;
        break;
      case 0x13:
        puVar13 = (uint *)((int (*)())_read_sleb128)(puVar13,(int)param_4 + 0x37c);
        break;
      default:
                    
        _abort();
      case 0x2d:
        local_2c = 0x10;
        do {
          *(undefined4 *)((int)param_4 + local_2c * 8 + 4) = 1;
          uVar9 = local_2c + 1;
          *(uint *)(local_2c * 8 + (int)param_4) = local_2c * 4 + -0x40;
          local_2c = uVar9;
        } while (uVar9 < 0x20);
        break;
      case 0x2e:
        puVar8 = (uint *)(param_3 + 0x1d4);
LAB_97c1b358:
        puVar13 = (uint *)((int (*)())_read_uleb128)(puVar13,puVar8);
        break;
      case 0x2f:
        uVar7 = ((int (*)())_read_uleb128)(puVar13,&local_2c);
        puVar13 = (uint *)((int (*)())_read_uleb128)(uVar7,&local_30);
        iVar3 = *(int *)((int)param_4 + 0x394);
        *(undefined4 *)((int)param_4 + local_2c * 8 + 4) = 1;
        iVar3 = -(local_30 * iVar3);
        goto LAB_97c1b3a0;
      }
switchD_97c1afc0_caseD_0: ;
    } while ((puVar13 < param_2) &&
            (uVar9 = *(uint *)((int)param_4 + 0x38c), param_1 = puVar13,
            uVar9 < *(uint *)(param_3 + 0x1c0)));
  }
  return;
}

/* _uw_frame_state_for @ 0x97c1b3e4 (328 bytes) */
int _uw_frame_state_for(param_1, param_2)
  int param_1;
  void *param_2;
{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int local_30 [5];
  
  _memset(param_2,0,0x3a4);
  *(undefined4 *)(param_1 + 0x1c4) = 0;
  *(undefined4 *)(param_1 + 0x1d4) = 0;
  piVar4 = __Unwind_Find_FDE((void *)(*(int *)(param_1 + 0x1c0) + -1),
                             (unsigned char *)(param_1 + 0x1c8));
  uVar2 = 5;
  if (piVar4 != (int *)0x0) {
    *(undefined4 *)((int)param_2 + 0x38c) = *(undefined4 *)(param_1 + 0x1d0);
    iVar3 = piVar4[1];
    iVar7 = (int)piVar4 + (4 - iVar3);
    iVar5 = ((int (*)())_extract_cie_info)(iVar7,param_1,param_2);
    uVar2 = 3;
    if (iVar5 != 0) {
      iVar6 = 0;
      ((int (*)())_execute_cfa_program)(iVar5,iVar7 + *(int *)((int)piVar4 + (4 - iVar3)) + 4,param_1,param_2);
      iVar3 = ((int (*)())_size_of_encoded_value)(*(undefined1 *)((int)param_2 + 0x39d));
      iVar3 = (int)piVar4 + iVar3 * 2 + 8;
      if (*(char *)((int)param_2 + 0x39f) != '\0') {
        iVar3 = ((int (*)())_read_uleb128)(iVar3,local_30);
        iVar6 = iVar3 + local_30[0];
      }
      cVar1 = *(char *)((int)param_2 + 0x39e);
      if (cVar1 != -1) {
        uVar2 = ((int (*)())_base_of_encoded_value)(cVar1,param_1);
        iVar3 = ((int (*)())_read_encoded_value_with_base)(cVar1,uVar2,iVar3,param_1 + 0x1c4);
      }
      if (iVar6 == 0) {
        iVar6 = iVar3;
      }
      ((int (*)())_execute_cfa_program)(iVar6,(int)piVar4 + *piVar4 + 4,param_1,param_2);
      uVar2 = 0;
    }
  }
  return uVar2;
}

/* ___frame_state_for @ 0x97c1b52c (236 bytes) */
int ___frame_state_for(param_1, param_2)
  int param_1;
  int param_2;
{
  char cVar1;
  int iVar2;
  undefined1 *puVar3;
  char *pcVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined1 auStack_5a0 [448];
  int local_3e0;
  undefined4 local_3cc;
  undefined4 local_3c0;
  char local_3b9 [885];
  undefined4 local_44;
  undefined2 local_3e;
  int local_38;
  byte local_24;
  undefined4 local_20;
  
  puVar3 = auStack_5a0;
  _memset(puVar3,0,0x1d8);
  local_3e0 = param_1 + 1;
  iVar2 = ((int (*)())_uw_frame_state_for)(puVar3,&local_3c0);
  iVar6 = 0;
  if ((iVar2 == 0) && (local_38 != 2)) {
    iVar6 = 0x4e;
    puVar5 = (undefined4 *)(param_2 + 0x10);
    pcVar4 = (char *)(param_2 + 0x14c);
    do {
      cVar1 = puVar3[0x1e7];
      *pcVar4 = cVar1;
      if ((cVar1 == '\x01') || (cVar1 == '\x02')) {
        *puVar5 = *(undefined4 *)(puVar3 + 0x1e0);
      }
      else {
        *puVar5 = 0;
      }
      pcVar4 = pcVar4 + 1;
      puVar3 = puVar3 + 8;
      puVar5 = puVar5 + 1;
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
    *(undefined2 *)(param_2 + 0x148) = local_3e;
    *(undefined4 *)(param_2 + 8) = local_44;
    *(ushort *)(param_2 + 0x14a) = (ushort)local_24;
    *(undefined4 *)(param_2 + 0xc) = local_3cc;
    *(undefined4 *)(param_2 + 4) = local_20;
    iVar6 = param_2;
  }
  return iVar6;
}

/* _uw_update_context_1 @ 0x97c1b618 (320 bytes) */
int _uw_update_context_1(param_1, param_2)
  int *param_1;
  int *param_2;
{
  int iVar1;
  int iVar2;
  int *piVar3;
  int aiStack_210 [120];
  int local_30;
  int local_2c [5];
  
  _memcpy(aiStack_210,param_1,0x1d8);
  if (param_2[0xe2] == 1) {
    if ((int *)param_1[param_2[0xe0]] == (int *)0x0) {
      iVar2 = param_1[0x6f];
    }
    else {
      iVar2 = *(int *)param_1[param_2[0xe0]];
    }
    iVar2 = iVar2 + param_2[0xdf];
  }
  else {
    if (param_2[0xe2] != 2) {
                    
      _abort();
    }
    iVar2 = ((int (*)())_read_uleb128)(param_2[0xe1],&local_30);
    iVar2 = ((int (*)())_execute_stack_op)(iVar2,iVar2 + local_30,param_1,0);
  }
  param_1[0x6f] = iVar2;
  piVar3 = param_1 + 0x6e;
  do {
    iVar1 = param_2[1];
    if (iVar1 == 1) {
      *param_1 = iVar2 + *param_2;
    }
    else if (iVar1 != 0) {
      if (iVar1 == 2) {
        *param_1 = aiStack_210[*param_2];
      }
      else if (iVar1 == 3) {
        iVar1 = ((int (*)())_read_uleb128)(*param_2,local_2c);
        iVar1 = ((int (*)())_execute_stack_op)(iVar1,iVar1 + local_2c[0],aiStack_210,iVar2);
        *param_1 = iVar1;
      }
    }
    param_1 = param_1 + 1;
    param_2 = param_2 + 2;
  } while ((int)param_1 <= (int)piVar3);
  return;
}

/* _uw_update_context @ 0x97c1b758 (68 bytes) */
int _uw_update_context(param_1, param_2)
  int param_1;
  int param_2;
{
  ((int (*)())_uw_update_context_1)();
  *(undefined4 *)(param_1 + 0x1c0) =
       **(undefined4 **)(param_1 + (uint)*(byte *)(param_2 + 0x39c) * 4);
  return;
}

/* _uw_init_context_1 @ 0x97c1b79c (132 bytes) */
int _uw_init_context_1(param_1, param_2, param_3)
  void *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined4 in_LR;
  undefined1 auStack_3d0 [892];
  int local_54;
  int local_50;
  undefined4 local_48;
  
  _memset(param_1,0,0x1d8);
  *(undefined4 *)((int)param_1 + 0x1c0) = in_LR;
  local_54 = ((int (*)())_uw_frame_state_for)(param_1,auStack_3d0);
  if (local_54 != 0) {
                    
    _abort();
  }
  *(undefined4 *)((int)param_1 + 0x1bc) = param_2;
  local_48 = 1;
  local_50 = local_54;
  ((int (*)())_uw_update_context_1)(param_1,auStack_3d0);
  *(undefined4 *)((int)param_1 + 0x1c0) = param_3;
  return;
}

/* _uw_install_context_1 @ 0x97c1b820 (652 bytes) */
int _uw_install_context_1(param_1, param_2)
  int param_1;
  int param_2;
{
  byte *pbVar1;
  int iVar2;
  void *pvVar3;
  void *pvVar4;
  
  iVar2 = _pthread_once((pthread_once_t *)&_once_regsizes_0,DAT_a7b7c084);
  if ((iVar2 != 0) || (_dwarf_reg_size_table == '\0')) {
    _dwarf_reg_size_table = '\x04';
    DAT_a7b7ea7d = 4;
    DAT_a7b7ea7e = 4;
    DAT_a7b7ea7f = 4;
    DAT_a7b7ea80 = 4;
    DAT_a7b7ea81 = 4;
    DAT_a7b7ea82 = 4;
    DAT_a7b7ea83 = 4;
    DAT_a7b7ea84 = 4;
    DAT_a7b7ea85 = 4;
    DAT_a7b7ea86 = 4;
    DAT_a7b7ea87 = 4;
    DAT_a7b7ea88 = 4;
    DAT_a7b7ea89 = 4;
    DAT_a7b7ea8a = 4;
    DAT_a7b7ea8b = 4;
    DAT_a7b7ea8c = 4;
    DAT_a7b7ea8d = 4;
    DAT_a7b7ea8e = 4;
    DAT_a7b7ea8f = 4;
    DAT_a7b7ea90 = 4;
    DAT_a7b7ea91 = 4;
    DAT_a7b7ea92 = 4;
    DAT_a7b7ea93 = 4;
    DAT_a7b7ea94 = 4;
    DAT_a7b7ea95 = 4;
    DAT_a7b7ea96 = 4;
    DAT_a7b7ea97 = 4;
    DAT_a7b7ea98 = 4;
    DAT_a7b7ea99 = 4;
    DAT_a7b7ea9a = 4;
    DAT_a7b7ea9b = 4;
    DAT_a7b7ea9c = 8;
    DAT_a7b7ea9d = 8;
    DAT_a7b7eabb = 8;
    DAT_a7b7ea9e = 8;
    DAT_a7b7ea9f = 8;
    DAT_a7b7eaa0 = 8;
    DAT_a7b7eaa1 = 8;
    DAT_a7b7eaa2 = 8;
    DAT_a7b7eaa3 = 8;
    DAT_a7b7eaa4 = 8;
    DAT_a7b7eaa5 = 8;
    DAT_a7b7eaa6 = 8;
    DAT_a7b7eaa7 = 8;
    DAT_a7b7eaa8 = 8;
    DAT_a7b7eaa9 = 8;
    DAT_a7b7eaaa = 8;
    DAT_a7b7eaab = 8;
    DAT_a7b7eaac = 8;
    DAT_a7b7eaad = 8;
    DAT_a7b7eaae = 8;
    DAT_a7b7eaaf = 8;
    DAT_a7b7eab0 = 8;
    DAT_a7b7eab1 = 8;
    DAT_a7b7eab2 = 8;
    DAT_a7b7eab3 = 8;
    DAT_a7b7eab4 = 8;
    DAT_a7b7eab5 = 8;
    DAT_a7b7eab6 = 8;
    DAT_a7b7eab7 = 8;
    DAT_a7b7eab8 = 8;
    DAT_a7b7eab9 = 8;
    DAT_a7b7eaba = 8;
    DAT_a7b7eabc = 4;
    DAT_a7b7eabd = 4;
    DAT_a7b7eabe = 4;
    DAT_a7b7eabf = 4;
    DAT_a7b7eac0 = 4;
    DAT_a7b7eac1 = 4;
    DAT_a7b7eac2 = 4;
    DAT_a7b7eac3 = 4;
    DAT_a7b7eac4 = 4;
    DAT_a7b7eac5 = 4;
    DAT_a7b7eac6 = 4;
    DAT_a7b7eac7 = 4;
    DAT_a7b7eac8 = 4;
    DAT_a7b7eac9 = 0x10;
    DAT_a7b7eaca = 0x10;
    DAT_a7b7eacb = 0x10;
    DAT_a7b7eacc = 0x10;
    DAT_a7b7eacd = 0x10;
    DAT_a7b7eace = 0x10;
    DAT_a7b7eacf = 0x10;
    DAT_a7b7ead0 = 0x10;
    DAT_a7b7ead1 = 0x10;
    DAT_a7b7ead2 = 0x10;
    DAT_a7b7ead3 = 0x10;
    DAT_a7b7ead4 = 0x10;
    DAT_a7b7ead5 = 0x10;
    DAT_a7b7ead6 = 0x10;
    DAT_a7b7ead7 = 0x10;
    DAT_a7b7ead8 = 0x10;
    DAT_a7b7ead9 = 0x10;
    DAT_a7b7eada = 0x10;
    DAT_a7b7eadb = 0x10;
    DAT_a7b7eadc = 0x10;
    DAT_a7b7eadd = 0x10;
    DAT_a7b7eade = 0x10;
    DAT_a7b7eadf = 0x10;
    DAT_a7b7eae0 = 0x10;
    DAT_a7b7eae1 = 0x10;
    DAT_a7b7eae9 = 4;
    DAT_a7b7eae8 = 0x10;
    DAT_a7b7eae2 = 0x10;
    DAT_a7b7eae3 = 0x10;
    DAT_a7b7eae4 = 0x10;
    DAT_a7b7eae5 = 0x10;
    DAT_a7b7eae6 = 0x10;
    DAT_a7b7eae7 = 0x10;
  }
  iVar2 = 0;
  pbVar1 = (byte *)&_dwarf_reg_size_table;
  do {
    pvVar4 = *(void **)(iVar2 + param_2);
    pvVar3 = *(void **)(iVar2 + param_1);
    if (((pvVar4 != (void *)0x0) && (pvVar3 != (void *)0x0)) && (pvVar4 != pvVar3)) {
      _memcpy(pvVar3,pvVar4,(uint)*pbVar1);
    }
    pbVar1 = pbVar1 + 1;
    iVar2 = iVar2 + 4;
  } while ((int)pbVar1 < -0x58481516);
  return (*(int *)(param_2 + 0x1bc) - *(int *)(param_1 + 0x1bc)) + *(int *)(param_2 + 0x1d4);
}

/* __Unwind_RaiseException_Phase2 @ 0x97c1baac (192 bytes) */
int __Unwind_RaiseException_Phase2(param_1, param_2)
  undefined4 *param_1;
  int param_2;
{
  uint uVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  undefined1 auStack_3c0 [912];
  code *local_30;
  
  while( true ) {
    iVar3 = ((int (*)())_uw_frame_state_for)(param_2,auStack_3c0);
    iVar4 = 2;
    uVar1 = (uint)(*(int *)(param_2 + 0x1c0) == param_1[4]);
    if ((iVar3 != 0) ||
       ((local_30 != (code *)0x0 &&
        ((iVar4 = (*local_30)(1,uVar1 << 2 | 2,*param_1,param_1[1],param_1,param_2), iVar4 == 7 ||
         (bVar2 = iVar4 != 8, iVar4 = 2, bVar2)))))) break;
    if (uVar1 != 0) {
                    
      _abort();
    }
    ((int (*)())_uw_update_context)(param_2,auStack_3c0);
  }
  return iVar4;
}

/* __Unwind_RaiseException @ 0x97c1bb6c (284 bytes) */
int __Unwind_RaiseException(exception_object)
  unsigned char * exception_object;
{
  undefined4 *puVar1;
  int iVar2;
  unsigned char _Var3;
  int in_stack_00000000;
  undefined4 in_stack_000003e0;
  code *in_stack_00000790;
  
  puVar1 = (undefined4 *)save_world();
  ((int (*)())_uw_init_context_1)(&STACKARG(0x40),&STACKARG(0x960),*(undefined4 *)(in_stack_00000000 + 8));
  _memcpy(&STACKARG(0x220),&STACKARG(0x40),0x1d8);
  do {
    iVar2 = ((int (*)())_uw_frame_state_for)(&STACKARG(0x220),&STACKARG(0x400));
    if (iVar2 == 5) {
      iVar2 = 5;
LAB_97c1bc84:
      _Var3 = eh_rest_world_r10(iVar2);
      return _Var3;
    }
    if (iVar2 != 0) {
LAB_97c1bc5c:
      iVar2 = 3;
      goto LAB_97c1bc84;
    }
    if (in_stack_00000790 != (code *)0x0) {
      iVar2 = (*in_stack_00000790)(1,1,*puVar1,puVar1[1],puVar1,&STACKARG(0x220));
      if (iVar2 == 6) {
        puVar1[3] = 0;
        puVar1[4] = in_stack_000003e0;
        _memcpy(&STACKARG(0x220),&STACKARG(0x40),0x1d8);
        iVar2 = ((int (*)())__Unwind_RaiseException_Phase2)(puVar1,&STACKARG(0x220));
        if (iVar2 == 7) {
          iVar2 = ((int (*)())_uw_install_context_1)(&STACKARG(0x40),&STACKARG(0x220));
        }
        goto LAB_97c1bc84;
      }
      if (iVar2 != 8) goto LAB_97c1bc5c;
    }
    ((int (*)())_uw_update_context)(&STACKARG(0x220),&STACKARG(0x400));
  } while( true );
}

/* __Unwind_ForcedUnwind_Phase2 @ 0x97c1bc88 (260 bytes) */
int __Unwind_ForcedUnwind_Phase2(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  code *pcVar4;
  undefined4 uVar5;
  undefined1 auStack_3d0 [912];
  code *local_40;
  
  pcVar4 = (code *)param_1[3];
  uVar5 = param_1[4];
  while( true ) {
    iVar1 = ((int (*)())_uw_frame_state_for)(param_2,auStack_3d0);
    if ((iVar1 != 0) && (iVar1 != 5)) {
      return 2;
    }
    uVar3 = 10;
    if (iVar1 == 5) {
      uVar3 = 0x1a;
    }
    iVar2 = (*pcVar4)(1,uVar3,*param_1,param_1[1],param_1,param_2,uVar5);
    if (iVar2 != 0) break;
    if (iVar1 == 5) {
      return 5;
    }
    if (local_40 != (code *)0x0) {
      iVar1 = (*local_40)(1,10,*param_1,param_1[1],param_1,param_2);
      if (iVar1 == 7) {
        return 7;
      }
      if (iVar1 != 8) {
        return 2;
      }
    }
    ((int (*)())_uw_update_context)(param_2,auStack_3d0);
  }
  return 2;
}

/* __Unwind_ForcedUnwind @ 0x97c1bd8c (148 bytes) */
int __Unwind_ForcedUnwind(exception_object, stop, stop_parameter)
  unsigned char * exception_object;
  unsigned char stop;
  void *stop_parameter;
{
  int iVar1;
  unsigned char _Var2;
  undefined8 uVar3;
  int in_stack_00000000;
  
  uVar3 = save_world();
  iVar1 = (int)((ulonglong)uVar3 >> 0x20);
  ((int (*)())_uw_init_context_1)(&STACKARG(0x40),&STACKARG(0x5b0),*(undefined4 *)(in_stack_00000000 + 8));
  _memcpy(&STACKARG(0x220),&STACKARG(0x40),0x1d8);
  *(int *)(iVar1 + 0xc) = (int)uVar3;
  *(void **)(iVar1 + 0x10) = stop_parameter;
  iVar1 = ((int (*)())__Unwind_ForcedUnwind_Phase2)(iVar1,&STACKARG(0x220));
  if (iVar1 == 7) {
    ((int (*)())_uw_install_context_1)(&STACKARG(0x40),&STACKARG(0x220));
  }
  _Var2 = eh_rest_world_r10();
  return _Var2;
}

/* __Unwind_Resume @ 0x97c1be20 (152 bytes) */
int __Unwind_Resume(exception_object)
  unsigned char * exception_object;
{
  int iVar1;
  int in_stack_00000000;
  
  iVar1 = save_world();
  ((int (*)())_uw_init_context_1)(&STACKARG(0x40),&STACKARG(0x5b0),*(undefined4 *)(in_stack_00000000 + 8));
  _memcpy(&STACKARG(0x220),&STACKARG(0x40),0x1d8);
  if (*(int *)(iVar1 + 0xc) == 0) {
    iVar1 = ((int (*)())__Unwind_RaiseException_Phase2)(iVar1,&STACKARG(0x220));
  }
  else {
    iVar1 = ((int (*)())__Unwind_ForcedUnwind_Phase2)(iVar1,&STACKARG(0x220));
  }
  if (iVar1 != 7) {
                    
    _abort();
  }
  ((int (*)())_uw_install_context_1)(&STACKARG(0x40),&STACKARG(0x220));
  eh_rest_world_r10();
  return;
}

/* __Unwind_DeleteException @ 0x97c1beb8 (20 bytes) */
#if 0   /* compile-failing as plain C: Ghidra text kept verbatim, see ledger status */
int __Unwind_DeleteException(exception_object)
  unsigned char * exception_object;
{
                    
                    
  (*exception_object->exception_cleanup)(_URC_FOREIGN_EXCEPTION_CAUGHT,exception_object);
  return;
}
#endif

/* __Unwind_GetGR @ 0x97c1becc (16 bytes) */
int __Unwind_GetGR(context, index)
  unsigned char * context;
  int index;
{
  return **(unsigned char **)(context + index * 4);
}

/* __Unwind_SetGR @ 0x97c1bedc (16 bytes) */
int __Unwind_SetGR(context, index, new_value)
  unsigned char * context;
  int index;
  unsigned char new_value;
{
  **(unsigned char **)(context + index * 4) = new_value;
  return;
}

/* __Unwind_GetIP @ 0x97c1beec (8 bytes) */
int __Unwind_GetIP(context)
  unsigned char * context;
{
  return *(unsigned char *)(context + 0x1c0);
}

/* __Unwind_SetIP @ 0x97c1bef4 (8 bytes) */
int __Unwind_SetIP(param_1, new_value)
  unsigned char * param_1;
  unsigned char new_value;
{
  *(unsigned char *)(param_1 + 0x1c0) = new_value;
  return;
}

/* _init_dwarf_reg_size_table @ 0x97c1befc (1192 bytes) */
int _init_dwarf_reg_size_table()
{
  _dwarf_reg_size_table = 4;
  DAT_a7b7ea7d = 4;
  DAT_a7b7ea7e = 4;
  DAT_a7b7ea7f = 4;
  DAT_a7b7ea80 = 4;
  DAT_a7b7ea81 = 4;
  DAT_a7b7ea82 = 4;
  DAT_a7b7ea83 = 4;
  DAT_a7b7ea84 = 4;
  DAT_a7b7ea85 = 4;
  DAT_a7b7ea86 = 4;
  DAT_a7b7ea87 = 4;
  DAT_a7b7ea88 = 4;
  DAT_a7b7ea89 = 4;
  DAT_a7b7ea8a = 4;
  DAT_a7b7ea8b = 4;
  DAT_a7b7ea8c = 4;
  DAT_a7b7ea8d = 4;
  DAT_a7b7ea8e = 4;
  DAT_a7b7ea8f = 4;
  DAT_a7b7ea90 = 4;
  DAT_a7b7ea91 = 4;
  DAT_a7b7ea92 = 4;
  DAT_a7b7ea93 = 4;
  DAT_a7b7ea94 = 4;
  DAT_a7b7ea95 = 4;
  DAT_a7b7ea96 = 4;
  DAT_a7b7ea97 = 4;
  DAT_a7b7ea98 = 4;
  DAT_a7b7ea99 = 4;
  DAT_a7b7ea9a = 4;
  DAT_a7b7ea9b = 4;
  DAT_a7b7ea9c = 8;
  DAT_a7b7ea9d = 8;
  DAT_a7b7ea9e = 8;
  DAT_a7b7ea9f = 8;
  DAT_a7b7eaa0 = 8;
  DAT_a7b7eaa1 = 8;
  DAT_a7b7eaa2 = 8;
  DAT_a7b7eaa3 = 8;
  DAT_a7b7eaa4 = 8;
  DAT_a7b7eaa5 = 8;
  DAT_a7b7eaa6 = 8;
  DAT_a7b7eaa7 = 8;
  DAT_a7b7eaa8 = 8;
  DAT_a7b7eaa9 = 8;
  DAT_a7b7eaaa = 8;
  DAT_a7b7eaab = 8;
  DAT_a7b7eaac = 8;
  DAT_a7b7eaad = 8;
  DAT_a7b7eaae = 8;
  DAT_a7b7eaaf = 8;
  DAT_a7b7eab0 = 8;
  DAT_a7b7eab1 = 8;
  DAT_a7b7eab2 = 8;
  DAT_a7b7eab3 = 8;
  DAT_a7b7eab4 = 8;
  DAT_a7b7eab5 = 8;
  DAT_a7b7eab6 = 8;
  DAT_a7b7eab7 = 8;
  DAT_a7b7eab8 = 8;
  DAT_a7b7eab9 = 8;
  DAT_a7b7eaba = 8;
  DAT_a7b7eabb = 8;
  DAT_a7b7eabc = 4;
  DAT_a7b7eabd = 4;
  DAT_a7b7eabe = 4;
  DAT_a7b7eabf = 4;
  DAT_a7b7eac0 = 4;
  DAT_a7b7eac1 = 4;
  DAT_a7b7eac2 = 4;
  DAT_a7b7eac3 = 4;
  DAT_a7b7eac4 = 4;
  DAT_a7b7eac5 = 4;
  DAT_a7b7eac6 = 4;
  DAT_a7b7eac7 = 4;
  DAT_a7b7eac8 = 4;
  DAT_a7b7eac9 = 0x10;
  DAT_a7b7eaca = 0x10;
  DAT_a7b7eacb = 0x10;
  DAT_a7b7eacc = 0x10;
  DAT_a7b7eacd = 0x10;
  DAT_a7b7eace = 0x10;
  DAT_a7b7eacf = 0x10;
  DAT_a7b7ead0 = 0x10;
  DAT_a7b7ead1 = 0x10;
  DAT_a7b7ead2 = 0x10;
  DAT_a7b7ead3 = 0x10;
  DAT_a7b7ead4 = 0x10;
  DAT_a7b7ead5 = 0x10;
  DAT_a7b7ead6 = 0x10;
  DAT_a7b7ead7 = 0x10;
  DAT_a7b7ead8 = 0x10;
  DAT_a7b7ead9 = 0x10;
  DAT_a7b7eada = 0x10;
  DAT_a7b7eadb = 0x10;
  DAT_a7b7eadc = 0x10;
  DAT_a7b7eadd = 0x10;
  DAT_a7b7eade = 0x10;
  DAT_a7b7eadf = 0x10;
  DAT_a7b7eae0 = 0x10;
  DAT_a7b7eae1 = 0x10;
  DAT_a7b7eae2 = 0x10;
  DAT_a7b7eae3 = 0x10;
  DAT_a7b7eae4 = 0x10;
  DAT_a7b7eae5 = 0x10;
  DAT_a7b7eae6 = 0x10;
  DAT_a7b7eae7 = 0x10;
  DAT_a7b7eae8 = 0x10;
  DAT_a7b7eae9 = 4;
  return;
}

/* _size_of_encoded_value_97c1c3a4 @ 0x97c1c3a4 (120 bytes) */
int _size_of_encoded_value_97c1c3a4(param_1)
  uint param_1;
{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (param_1 != 0xff) {
    param_1 = param_1 & 7;
    uVar1 = 2;
    if (param_1 != 2) {
      if (param_1 < 3) {
        if (param_1 != 0) {
LAB_97c1c404:
                    
          _abort();
        }
        uVar1 = 4;
      }
      else {
        uVar1 = 4;
        if (param_1 != 3) {
          if (param_1 != 4) goto LAB_97c1c404;
          uVar1 = 8;
        }
      }
    }
  }
  return uVar1;
}

/* _read_uleb128_97c1c41c @ 0x97c1c41c (48 bytes) */
int _read_uleb128_97c1c41c(param_1, param_2)
  byte *param_1;
  uint *param_2;
{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = 0;
  uVar4 = 0;
  do {
    bVar1 = *param_1;
    param_1 = param_1 + 1;
    uVar2 = uVar3 & 0x3f;
    uVar3 = uVar3 + 7;
    uVar4 = uVar4 | (bVar1 & 0x7f) << uVar2;
  } while ((bVar1 & 0x80) != 0);
  *param_2 = uVar4;
  return;
}

/* _read_sleb128_97c1c44c @ 0x97c1c44c (76 bytes) */
int _read_sleb128_97c1c44c(param_1, param_2)
  byte *param_1;
  uint *param_2;
{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = 0;
  uVar4 = 0;
  do {
    bVar1 = *param_1;
    param_1 = param_1 + 1;
    uVar2 = uVar3 & 0x3f;
    uVar3 = uVar3 + 7;
    uVar4 = uVar4 | (bVar1 & 0x7f) << uVar2;
  } while ((bVar1 & 0x80) != 0);
  if ((uVar3 < 0x20) && ((bVar1 & 0x40) != 0)) {
    uVar4 = uVar4 | -1 << (uVar3 & 0x3f);
  }
  *param_2 = uVar4;
  return;
}

/* _read_encoded_value_with_base_97c1c498 @ 0x97c1c498 (312 bytes) */
int _read_encoded_value_with_base_97c1c498(param_1, param_2, param_3, param_4)
  uint param_1;
  uint *param_2;
  uint *param_3;
  uint *param_4;
{
  uint *puVar1;
  uint *local_30;
  uint *local_2c [6];
  
  if (param_1 == 0x50) {
    local_2c[0] = (uint *)((int)param_3 + 3U & 0xfffffffc);
    puVar1 = local_2c[0] + 1;
    goto LAB_97c1c5e4;
  }
  switch(param_1 & 0xf) {
  case 0:
  case 3:
  case 0xb:
    local_2c[0] = (uint *)*param_3;
    puVar1 = param_3 + 1;
    break;
  case 1:
    puVar1 = (uint *)((int (*)())_read_uleb128)(param_3,&local_30);
    local_2c[0] = local_30;
    break;
  case 2:
    local_2c[0] = (uint *)(uint)*(ushort *)param_3;
    goto LAB_97c1c570;
  case 4:
  case 0xc:
    puVar1 = param_3 + 2;
    local_2c[0] = (uint *)((uint)*(byte *)((int)param_3 + 7) |
                          (uint)*(byte *)((int)param_3 + 6) << 8 |
                          (uint)*(byte *)((int)param_3 + 5) << 0x10 |
                          (uint)*(byte *)(param_3 + 1) << 0x18);
    break;
  default:
                    
    _abort();
  case 9:
    puVar1 = (uint *)((int (*)())_read_sleb128)(param_3,local_2c);
    break;
  case 10:
    local_2c[0] = (uint *)(int)(short)*(ushort *)param_3;
LAB_97c1c570:
    puVar1 = (uint *)((int)param_3 + 2);
  }
  if (local_2c[0] != (uint *)0x0) {
    if ((param_1 & 0x70) == 0x10) {
      param_2 = param_3;
    }
    local_2c[0] = (uint *)((int)local_2c[0] + (int)param_2);
    if ((param_1 & 0x80) != 0) {
LAB_97c1c5e4:
      local_2c[0] = (uint *)*local_2c[0];
    }
  }
  *param_4 = (uint)local_2c[0];
  return puVar1;
}

/* ___register_frame_info_bases @ 0x97c1c604 (88 bytes) */
int ___register_frame_info_bases(fde, ob, tb, db)
  void *fde;
  void *ob;
  void *tb;
  void *db;
{
  if (*(int *)fde == 0) {
    return;
  }
  *(undefined4 *)ob = 0xffffffff;
  *(void **)((int)ob + 4) = tb;
  *(void **)((int)ob + 8) = db;
  *(void **)((int)ob + 0xc) = fde;
  *(undefined4 *)((int)ob + 0x10) = 0x1fe00000;
  *(undefined4 *)((int)ob + 0x14) = 0;
  *(void **)((int)ob + 0x18) = _unseen_objects;
  _unseen_objects = ob;
  return;
}

/* ___register_frame_info @ 0x97c1c65c (12 bytes) */
int ___register_frame_info(fde, ob)
  void *fde;
  void *ob;
{
  ((int (*)())___register_frame_info_bases)(fde,ob,(void *)0x0,(void *)0x0);
  return;
}

/* ___register_frame @ 0x97c1c668 (88 bytes) */
int ___register_frame(fde)
  void *fde;
{
  void *ob;
  
  if (*(int *)fde != 0) {
    ob = _malloc(0x1c);
    ((int (*)())___register_frame_info)(fde,ob);
    return;
  }
  return;
}

/* ___register_frame_info_table_bases @ 0x97c1c6c0 (68 bytes) */
int ___register_frame_info_table_bases(fde, ob, tb, db)
  void *fde;
  void *ob;
  void *tb;
  void *db;
{
  *(undefined4 *)ob = 0xffffffff;
  *(void **)((int)ob + 4) = tb;
  *(void **)((int)ob + 8) = db;
  *(void **)((int)ob + 0xc) = fde;
  *(undefined4 *)((int)ob + 0x10) = 0x5fe00000;
  *(void **)((int)ob + 0x18) = _unseen_objects;
  _unseen_objects = ob;
  return;
}

/* ___register_frame_table @ 0x97c1c710 (68 bytes) */
int ___register_frame_table(fde)
  void *fde;
{
  void *ob;
  
  ob = _malloc(0x1c);
  ((int (*)())___register_frame_info_table_bases)(fde,ob,(void *)0x0,(void *)0x0);
  return;
}

/* ___deregister_frame_info_bases @ 0x97c1c748 (240 bytes) */
int ___deregister_frame_info_bases(fde)
  void *fde;
{
  void *pvVar1;
  undefined4 *puVar2;
  
  if (*(int *)fde == 0) {
    return (void *)0x0;
  }
  puVar2 = &_unseen_objects;
  for (pvVar1 = _unseen_objects; pvVar1 != (void *)0x0; pvVar1 = *(void **)((int)pvVar1 + 0x18)) {
    if (*(void **)((int)pvVar1 + 0xc) == fde) goto LAB_97c1c810;
    puVar2 = (undefined4 *)((int)pvVar1 + 0x18);
  }
  puVar2 = &_seen_objects;
  pvVar1 = _seen_objects;
  do {
    if (pvVar1 == (void *)0x0) {
                    
      _abort();
    }
    if (*(int *)((int)pvVar1 + 0x10) < 0) {
      if ((void *)**(int **)((int)pvVar1 + 0xc) == fde) {
        *puVar2 = *(undefined4 *)((int)pvVar1 + 0x18);
        _free(*(void **)((int)pvVar1 + 0xc));
        return pvVar1;
      }
    }
    else if (*(void **)((int)pvVar1 + 0xc) == fde) {
LAB_97c1c810:
      *puVar2 = *(undefined4 *)((int)pvVar1 + 0x18);
      return pvVar1;
    }
    puVar2 = (undefined4 *)((int)pvVar1 + 0x18);
    pvVar1 = *(void **)((int)pvVar1 + 0x18);
  } while( true );
}

/* ___deregister_frame @ 0x97c1c83c (72 bytes) */
int ___deregister_frame(fde)
  void *fde;
{
  void *pvVar1;
  
  if (*(int *)fde != 0) {
    pvVar1 = ___deregister_frame_info(fde);
    _free(pvVar1);
    return;
  }
  return;
}

/* _base_from_object @ 0x97c1c884 (120 bytes) */
int _base_from_object(param_1, param_2)
  uint param_1;
  int param_2;
{
  bool bVar1;
  
  if (param_1 == 0xff) {
    return 0;
  }
  param_1 = param_1 & 0x70;
  if (param_1 == 0x20) {
    return *(undefined4 *)(param_2 + 4);
  }
  if (param_1 < 0x21) {
    if (param_1 == 0) {
      return 0;
    }
    bVar1 = param_1 == 0x10;
  }
  else {
    if (param_1 == 0x30) {
      return *(undefined4 *)(param_2 + 8);
    }
    bVar1 = param_1 == 0x50;
  }
  if (bVar1) {
    return 0;
  }
                    
  _abort();
}

