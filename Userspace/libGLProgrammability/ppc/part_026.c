#include "decls.h"

/* _get_cie_encoding @ 0x97c1c8fc (200 bytes) */
int _get_cie_encoding(param_1)
  int param_1;
{
  char cVar1;
  size_t sVar2;
  undefined4 uVar3;
  int iVar4;
  byte *pbVar5;
  byte bVar6;
  char *pcVar7;
  undefined1 auStack_20 [4];
  undefined1 auStack_1c [4];
  undefined1 auStack_18 [12];
  
  bVar6 = 0;
  if (*(char *)(param_1 + 9) == 'z') {
    sVar2 = _strlen((char *)(param_1 + 9));
    uVar3 = _read_uleb128_97c1c41c((char *)(param_1 + 9) + sVar2 + 1,auStack_20);
    iVar4 = _read_sleb128_97c1c44c(uVar3,auStack_1c);
    pbVar5 = (byte *)_read_uleb128_97c1c41c(iVar4 + 1,auStack_20);
    for (pcVar7 = (char *)(param_1 + 10); cVar1 = *pcVar7, cVar1 != 'R'; pcVar7 = pcVar7 + 1) {
      if (cVar1 == 'P') {
        pbVar5 = (byte *)_read_encoded_value_with_base_97c1c498(*pbVar5 & 0x7f,0,pbVar5 + 1,auStack_18);
      }
      else {
        pbVar5 = pbVar5 + 1;
        if (cVar1 != 'L') {
          return 0;
        }
      }
    }
    bVar6 = *pbVar5;
  }
  return bVar6;
}

/* _fde_single_encoding_compare @ 0x97c1c9ec (152 bytes) */
int _fde_single_encoding_compare(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  undefined4 uVar1;
  uint local_30;
  uint local_2c [5];
  
  uVar1 = _base_from_object(*(uint *)(param_1 + 0x10) >> 0x15 & 0xff,param_1);
  _read_encoded_value_with_base_97c1c498
            (*(uint *)(param_1 + 0x10) >> 0x15 & 0xff,uVar1,param_2 + 8,&local_30);
  _read_encoded_value_with_base_97c1c498(*(uint *)(param_1 + 0x10) >> 0x15 & 0xff,uVar1,param_3 + 8,local_2c)
  ;
  uVar1 = 1;
  if (local_30 <= local_2c[0]) {
    if (local_30 < local_2c[0]) {
      uVar1 = 0xffffffff;
    }
    else {
      uVar1 = 0;
    }
  }
  return uVar1;
}

/* _fde_mixed_encoding_compare @ 0x97c1ca84 (188 bytes) */
int _fde_mixed_encoding_compare(param_1, param_2, param_3)
  undefined4 param_1;
  int param_2;
  int param_3;
{
  undefined1 uVar2;
  undefined4 uVar1;
  uint local_30;
  uint local_2c [5];
  
  uVar2 = ((int (*)())_get_cie_encoding)((param_2 - *(int *)(param_2 + 4)) + 4);
  uVar1 = _base_from_object(uVar2,param_1);
  _read_encoded_value_with_base_97c1c498(uVar2,uVar1,param_2 + 8,&local_30);
  uVar2 = ((int (*)())_get_cie_encoding)((param_3 - *(int *)(param_3 + 4)) + 4);
  uVar1 = _base_from_object(uVar2,param_1);
  _read_encoded_value_with_base_97c1c498(uVar2,uVar1,param_3 + 8,local_2c);
  uVar1 = 1;
  if (local_30 <= local_2c[0]) {
    if (local_30 < local_2c[0]) {
      uVar1 = 0xffffffff;
    }
    else {
      uVar1 = 0;
    }
  }
  return uVar1;
}

/* _frame_heapsort @ 0x97c1cb40 (568 bytes) */
int _frame_heapsort(param_1, param_2, param_3)
  undefined4 param_1;
  code *param_2;
  int param_3;
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  undefined4 *puVar7;
  int iVar8;
  uint uVar9;
  
  uVar5 = *(uint *)(param_3 + 4);
  puVar7 = (undefined4 *)(param_3 + 8);
  uVar9 = uVar5;
joined_r0x97c1cb68:
  if (uVar9 == 0) {
    do {
      do {
        if (uVar5 < 2) {
          return;
        }
        uVar5 = uVar5 - 1;
        uVar1 = *puVar7;
        *puVar7 = puVar7[uVar5];
        puVar7[uVar5] = uVar1;
      } while (uVar5 < 2);
      iVar6 = 0;
      uVar9 = 0;
      do {
        uVar4 = iVar6 + 2;
        if (uVar4 < uVar5) {
          iVar8 = uVar9 * 8;
          iVar2 = (*param_2)(param_1,puVar7[uVar9 * 2 + 2],puVar7[uVar9 * 2 + 1]);
          if (iVar2 < 1) {
            iVar2 = uVar9 << 2;
            goto LAB_97c1cd10;
          }
          iVar2 = uVar9 * 4;
          iVar3 = (*param_2)(param_1,puVar7[uVar9 * 2 + 2],puVar7[uVar9]);
          if (iVar3 < 1) goto LAB_97c1cd10;
          uVar1 = puVar7[uVar9];
          puVar7[uVar9] = puVar7[uVar9 * 2 + 2];
          puVar7[uVar9 * 2 + 2] = uVar1;
        }
        else {
          iVar2 = uVar9 << 2;
          iVar8 = uVar9 << 3;
LAB_97c1cd10:
          iVar3 = (*param_2)(param_1,*(undefined4 *)((int)puVar7 + iVar8 + 4),
                             *(undefined4 *)(iVar2 + (int)puVar7));
          if (iVar3 < 1) break;
          uVar1 = *(undefined4 *)(iVar2 + (int)puVar7);
          uVar4 = iVar6 + 1;
          *(undefined4 *)(iVar2 + (int)puVar7) = *(undefined4 *)((int)puVar7 + iVar8 + 4);
          *(undefined4 *)((int)puVar7 + iVar8 + 4) = uVar1;
        }
        iVar6 = uVar4 * 2;
        uVar9 = uVar4;
      } while (iVar6 + 1U < uVar5);
    } while( true );
  }
  uVar9 = uVar9 - 1;
  uVar4 = uVar9;
joined_r0x97c1cb84:
  do {
    iVar6 = uVar4 * 2;
    if (uVar5 <= iVar6 + 1U) goto joined_r0x97c1cb68;
    if (iVar6 + 2U < uVar5) {
      iVar8 = uVar4 * 8;
      iVar2 = (*param_2)(param_1,puVar7[uVar4 * 2 + 2],puVar7[uVar4 * 2 + 1]);
      if (iVar2 < 1) {
        iVar2 = uVar4 << 2;
      }
      else {
        iVar2 = uVar4 * 4;
        iVar3 = (*param_2)(param_1,puVar7[uVar4 * 2 + 2],puVar7[uVar4]);
        if (0 < iVar3) {
          uVar1 = puVar7[uVar4];
          puVar7[uVar4] = puVar7[uVar4 * 2 + 2];
          puVar7[uVar4 * 2 + 2] = uVar1;
          uVar4 = iVar6 + 2U;
          goto joined_r0x97c1cb84;
        }
      }
    }
    else {
      iVar2 = uVar4 << 2;
      iVar8 = uVar4 << 3;
    }
    iVar3 = (*param_2)(param_1,*(undefined4 *)((int)puVar7 + iVar8 + 4),
                       *(undefined4 *)(iVar2 + (int)puVar7));
    if (iVar3 < 1) goto joined_r0x97c1cb68;
    uVar1 = *(undefined4 *)(iVar2 + (int)puVar7);
    uVar4 = iVar6 + 1;
    *(undefined4 *)(iVar2 + (int)puVar7) = *(undefined4 *)((int)puVar7 + iVar8 + 4);
    *(undefined4 *)((int)puVar7 + iVar8 + 4) = uVar1;
  } while( true );
}

/* _classify_object_over_fdes @ 0x97c1cd78 (308 bytes) */
int _classify_object_over_fdes(param_1, param_2)
  uint *param_1;
  int *param_2;
{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int *piVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  uint local_40 [7];
  
  iVar8 = 0;
  iVar7 = 0;
  uVar9 = 0;
  uVar6 = 0;
  piVar5 = (int *)param_1[5];
  do {
    if ((param_2 == piVar5) || (*param_2 == 0)) {
      return iVar7;
    }
    if (param_2[1] != 0) {
      uVar4 = uVar9 & 0xff;
      iVar2 = (int)param_2 + (4 - param_2[1]);
      if (iVar2 != iVar8) {
        uVar9 = ((int (*)())_get_cie_encoding)(iVar2);
        uVar4 = uVar9 & 0xff;
        uVar6 = _base_from_object(uVar4,param_1);
        uVar1 = param_1[4];
        uVar3 = uVar1 >> 0x15 & 0xff;
        iVar8 = iVar2;
        if (uVar3 == 0xff) {
          uVar1 = (uVar9 & 0xff) << 0x15 | uVar1 & 0xe01fffff;
        }
        else {
          if (uVar3 == uVar9) goto LAB_97c1ce18;
          uVar1 = uVar1 | 0x20000000;
        }
        param_1[4] = uVar1;
      }
LAB_97c1ce18:
      _read_encoded_value_with_base_97c1c498(uVar4,uVar6,param_2 + 2,local_40);
      uVar4 = _size_of_encoded_value_97c1c3a4(uVar4);
      if (uVar4 < 4) {
        uVar4 = (1 << ((uVar4 & 7) << 3)) - 1;
      }
      else {
        uVar4 = 0xffffffff;
      }
      if (((local_40[0] & uVar4) != 0) && (iVar7 = iVar7 + 1, local_40[0] < *param_1)) {
        *param_1 = local_40[0];
      }
      piVar5 = (int *)param_1[5];
    }
    param_2 = (int *)((int)param_2 + *param_2 + 4);
  } while( true );
}

/* _add_fdes @ 0x97c1ceac (332 bytes) */
int _add_fdes(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  int *param_3;
{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  int *piVar6;
  int iVar7;
  uint uVar8;
  uint local_40 [7];
  
  iVar7 = 0;
  uVar8 = *(uint *)(param_1 + 0x10) >> 0x15 & 0xff;
  uVar4 = _base_from_object(uVar8,param_1);
  piVar6 = *(int **)(param_1 + 0x14);
  uVar5 = uVar8;
  for (; (param_3 != piVar6 && (*param_3 != 0)); param_3 = (int *)((int)param_3 + *param_3 + 4)) {
    if (param_3[1] != 0) {
      if (((*(uint *)(param_1 + 0x10) & 0x20000000) != 0) &&
         (iVar2 = (int)param_3 + (4 - param_3[1]), iVar2 != iVar7)) {
        uVar5 = ((int (*)())_get_cie_encoding)(iVar2);
        uVar8 = uVar5 & 0xff;
        uVar4 = _base_from_object(uVar8,param_1);
        iVar7 = iVar2;
      }
      if (uVar5 == 0) {
        uVar1 = param_3[2];
      }
      else {
        _read_encoded_value_with_base_97c1c498(uVar8,uVar4,param_3 + 2,local_40);
        uVar1 = _size_of_encoded_value_97c1c3a4(uVar8);
        if (uVar1 < 4) {
          uVar1 = (1 << ((uVar1 & 7) << 3)) - 1;
        }
        else {
          uVar1 = 0xffffffff;
        }
        uVar1 = local_40[0] & uVar1;
      }
      if ((uVar1 != 0) && (iVar2 = *param_2, iVar2 != 0)) {
        iVar3 = *(int *)(iVar2 + 4);
        *(int *)(iVar2 + 4) = iVar3 + 1;
        *(int **)(iVar3 * 4 + iVar2 + 8) = param_3;
      }
      piVar6 = *(int **)(param_1 + 0x14);
    }
  }
  return;
}

/* _linear_search_fdes @ 0x97c1cff8 (352 bytes) */
int _linear_search_fdes(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  int param_3;
{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  int *piVar6;
  int iVar7;
  uint uVar8;
  uint local_40;
  uint local_3c [6];
  
  iVar7 = 0;
  uVar8 = *(uint *)(param_1 + 0x10) >> 0x15 & 0xff;
  uVar2 = _base_from_object(uVar8,param_1);
  piVar6 = *(int **)(param_1 + 0x14);
  uVar3 = uVar8;
  do {
    if ((param_2 == piVar6) || (*param_2 == 0)) {
      return (int *)0x0;
    }
    if (param_2[1] != 0) {
      if (((*(uint *)(param_1 + 0x10) & 0x20000000) != 0) &&
         (iVar1 = (int)param_2 + (4 - param_2[1]), iVar1 != iVar7)) {
        uVar3 = ((int (*)())_get_cie_encoding)(iVar1);
        uVar8 = uVar3 & 0xff;
        uVar2 = _base_from_object(uVar8,param_1);
        iVar7 = iVar1;
      }
      if (uVar3 == 0) {
        local_40 = param_2[2];
        local_3c[0] = param_2[3];
        uVar5 = local_40;
      }
      else {
        uVar4 = _read_encoded_value_with_base_97c1c498(uVar8,uVar2,param_2 + 2,&local_40);
        _read_encoded_value_with_base_97c1c498(uVar3 & 0xf,0,uVar4,local_3c);
        uVar5 = _size_of_encoded_value_97c1c3a4(uVar8);
        if (uVar5 < 4) {
          uVar5 = (1 << ((uVar5 & 7) << 3)) - 1;
        }
        else {
          uVar5 = 0xffffffff;
        }
        uVar5 = local_40 & uVar5;
      }
      if ((uVar5 != 0) && (param_3 - local_40 < local_3c[0])) {
        return param_2;
      }
      piVar6 = *(int **)(param_1 + 0x14);
    }
    param_2 = (int *)((int)param_2 + *param_2 + 4);
  } while( true );
}

/* _search_object @ 0x97c1d158 (624 bytes) */
int _search_object(param_1, param_2)
  uint *param_1;
  uint param_2;
{
  uint uVar1;
  byte bVar4;
  undefined4 uVar2;
  undefined4 uVar3;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  int *piVar10;
  int iVar11;
  uint local_40;
  int local_3c;
  uint local_38;
  int local_34 [3];
  
  uVar1 = param_1[4];
  if (-1 < (int)uVar1) {
    ((int (*)())_init_object)();
    if (param_2 < *param_1) {
      return 0;
    }
    uVar1 = param_1[4];
  }
  if ((int)uVar1 < 0) {
    if ((uVar1 & 0x20000000) == 0) {
      uVar5 = uVar1 >> 0x15 & 0xff;
      if (uVar5 == 0) {
        uVar5 = 0;
        uVar1 = *(uint *)(param_1[3] + 4);
        if (uVar1 != 0) {
          do {
            uVar7 = uVar5 + uVar1 >> 1;
            iVar11 = *(int *)(uVar7 * 4 + param_1[3] + 8);
            if ((*(uint *)(iVar11 + 8) <= param_2) &&
               (uVar5 = uVar7 + 1, uVar7 = uVar1,
               param_2 < *(uint *)(iVar11 + 8) + *(int *)(iVar11 + 0xc))) {
              return iVar11;
            }
            uVar1 = uVar7;
          } while (uVar5 < uVar7);
        }
      }
      else {
        uVar6 = param_1[3];
        uVar2 = _base_from_object(uVar5,param_1);
        uVar7 = *(uint *)(uVar6 + 4);
        uVar8 = 0;
        if (uVar7 != 0) {
          do {
            uVar9 = uVar8 + uVar7 >> 1;
            iVar11 = *(int *)(uVar9 * 4 + uVar6 + 8);
            uVar3 = _read_encoded_value_with_base_97c1c498(uVar5,uVar2,iVar11 + 8,&local_38);
            _read_encoded_value_with_base_97c1c498(uVar1 >> 0x15 & 0xf,0,uVar3,local_34);
            if ((local_38 <= param_2) &&
               (uVar8 = uVar9 + 1, uVar9 = uVar7, param_2 < local_38 + local_34[0])) {
              return iVar11;
            }
            uVar7 = uVar9;
          } while (uVar8 < uVar9);
        }
      }
    }
    else {
      uVar5 = param_1[3];
      uVar7 = 0;
      uVar1 = *(uint *)(uVar5 + 4);
      if (uVar1 != 0) {
        do {
          uVar6 = uVar7 + uVar1 >> 1;
          iVar11 = *(int *)(uVar6 * 4 + uVar5 + 8);
          bVar4 = ((int (*)())_get_cie_encoding)((iVar11 - *(int *)(iVar11 + 4)) + 4);
          uVar2 = _base_from_object(bVar4,param_1);
          uVar2 = _read_encoded_value_with_base_97c1c498(bVar4,uVar2,iVar11 + 8,&local_40);
          _read_encoded_value_with_base_97c1c498(bVar4 & 0xf,0,uVar2,&local_3c);
          if ((local_40 <= param_2) &&
             (uVar7 = uVar6 + 1, uVar6 = uVar1, param_2 < local_40 + local_3c)) {
            return iVar11;
          }
          uVar1 = uVar6;
        } while (uVar7 < uVar6);
      }
    }
  }
  else {
    if ((uVar1 & 0x40000000) == 0) {
      iVar11 = ((int (*)())_linear_search_fdes)(param_1,param_1[3],param_2);
      return iVar11;
    }
    piVar10 = (int *)param_1[3];
    iVar11 = *piVar10;
    while (iVar11 != 0) {
      iVar11 = ((int (*)())_linear_search_fdes)(param_1,iVar11,param_2);
      if (iVar11 != 0) {
        return iVar11;
      }
      piVar10 = piVar10 + 1;
      iVar11 = *piVar10;
    }
  }
  return 0;
}

/* __Unwind_Find_registered_FDE @ 0x97c1d3c8 (356 bytes) */
int __Unwind_Find_registered_FDE(param_1, param_2)
  uint param_1;
  uint *param_2;
{
  uint *puVar1;
  bool bVar2;
  uint *puVar3;
  uint uVar4;
  undefined4 uVar5;
  uint *puVar6;
  int iVar7;
  uint *puVar8;
  
  iVar7 = 0;
  for (puVar8 = _seen_objects; puVar8 != (uint *)0x0; puVar8 = (uint *)puVar8[6]) {
    if (*puVar8 <= param_1) {
      iVar7 = ((int (*)())_search_object)(puVar8,param_1);
      if (iVar7 != 0) goto LAB_97c1d4c0;
      break;
    }
  }
  puVar8 = _unseen_objects;
  if (_unseen_objects == (uint *)0x0) {
    bVar2 = iVar7 == 0;
  }
  else {
    do {
      _unseen_objects = (uint *)puVar8[6];
      iVar7 = ((int (*)())_search_object)(puVar8,param_1);
      puVar6 = (uint *)&_seen_objects;
      puVar3 = _seen_objects;
      if (_seen_objects != (uint *)0x0) {
        do {
          if (*puVar3 < *puVar8) goto LAB_97c1d498;
          puVar1 = puVar3 + 6;
          puVar6 = puVar3 + 6;
          puVar3 = (uint *)*puVar1;
        } while ((uint *)*puVar1 != (uint *)0x0);
        puVar3 = (uint *)0x0;
      }
LAB_97c1d498:
      puVar8[6] = (uint)puVar3;
      *puVar6 = (uint)puVar8;
      if (iVar7 != 0) goto LAB_97c1d4c0;
      puVar8 = _unseen_objects;
    } while (_unseen_objects != (uint *)0x0);
    bVar2 = true;
  }
  puVar8 = _unseen_objects;
  if (!bVar2) {
LAB_97c1d4c0:
    *param_2 = puVar8[1];
    param_2[1] = puVar8[2];
    uVar4 = puVar8[4] >> 0x15 & 0xff;
    if ((puVar8[4] & 0x20000000) != 0) {
      uVar4 = ((int (*)())_get_cie_encoding)((iVar7 - *(int *)(iVar7 + 4)) + 4);
    }
    uVar5 = _base_from_object(uVar4 & 0xff,puVar8);
    _read_encoded_value_with_base_97c1c498(uVar4 & 0xff,uVar5,iVar7 + 8,param_2 + 2);
  }
  return iVar7;
}

/* _live_image_destructor @ 0x97c1d52c (196 bytes) */
int _live_image_destructor(param_1)
  int param_1;
{
  undefined4 *puVar1;
  
  if (*(int *)(param_1 + 0x1c) != 0) {
    puVar1 = (undefined4 *)__keymgr_get_and_lock_processwide_ptr(0x12e);
    if (puVar1 != (undefined4 *)0x0) {
      _seen_objects = *puVar1;
      _unseen_objects = puVar1[1];
      ___deregister_frame_info_bases(*(void **)(param_1 + 0x18));
      *puVar1 = _seen_objects;
      puVar1[1] = _unseen_objects;
    }
    __keymgr_set_and_unlock_processwide_ptr(0x12e,puVar1);
    _free(*(void **)(param_1 + 0x1c));
    *(undefined4 *)(param_1 + 0x1c) = 0;
    if ((*(uint *)(param_1 + 0x14) & 2) != 0) {
      _free(*(void **)(param_1 + 0x18));
    }
    *(undefined4 *)(param_1 + 0x18) = 0;
  }
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  return;
}

/* __Unwind_Find_FDE @ 0x97c1d5f0 (224 bytes) */
int __Unwind_Find_FDE(pc, param_2)
  void *pc;
  unsigned char *param_2;
{
  bool bVar1;
  undefined4 *puVar2;
  void *pvVar3;
  
  puVar2 = (undefined4 *)__keymgr_get_and_lock_processwide_ptr(0x12e);
  bVar1 = puVar2 == (undefined4 *)0x0;
  if (bVar1) {
    puVar2 = _calloc(1,0x10);
    bVar1 = puVar2 == (undefined4 *)0x0;
    if (!bVar1) goto LAB_97c1d644;
  }
  else {
LAB_97c1d644:
    _seen_objects = *puVar2;
    _unseen_objects = puVar2[1];
    pvVar3 = (void *)((int (*)())__Unwind_Find_registered_FDE)(pc,param_2);
    if (pvVar3 != (void *)0x0) goto LAB_97c1d688;
  }
  pvVar3 = (void *)((int (*)())_examine_objects)(pc,param_2,bVar1);
LAB_97c1d688:
  if (!bVar1) {
    *puVar2 = _seen_objects;
    puVar2[1] = _unseen_objects;
  }
  __keymgr_set_and_unlock_processwide_ptr(0x12e,puVar2);
  return pvVar3;
}

/* _init_object @ 0x97c1d6d0 (732 bytes) */
int _init_object(param_1)
  int param_1;
{
  undefined4 *puVar1;
  bool bVar2;
  undefined4 *puVar3;
  void *pvVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  undefined4 *puVar10;
  code *pcVar11;
  undefined4 *puVar12;
  undefined4 uVar13;
  uint uVar14;
  undefined4 *puVar15;
  int *piVar16;
  size_t sVar17;
  undefined4 *puVar18;
  undefined4 *local_50;
  void *local_4c;
  
  uVar6 = *(uint *)(param_1 + 0x10);
  uVar8 = uVar6 & 0x1fffff;
  if (uVar8 == 0) {
    if ((uVar6 & 0x40000000) == 0) {
      uVar8 = ((int (*)())_classify_object_over_fdes)(param_1,*(undefined4 *)(param_1 + 0xc));
      uVar6 = *(uint *)(param_1 + 0x10);
      bVar2 = uVar8 == 0;
    }
    else {
      piVar16 = *(int **)(param_1 + 0xc);
      iVar5 = *piVar16;
      bVar2 = true;
      uVar14 = 0;
      if (iVar5 != 0) {
        do {
          iVar7 = ((int (*)())_classify_object_over_fdes)(param_1,iVar5);
          piVar16 = piVar16 + 1;
          iVar5 = *piVar16;
          uVar14 = uVar14 + iVar7;
        } while (iVar5 != 0);
        uVar6 = *(uint *)(param_1 + 0x10);
        bVar2 = uVar14 == 0;
        uVar8 = uVar14;
      }
    }
    *(uint *)(param_1 + 0x10) = uVar8 & 0x1fffff | uVar6 & 0xffe00000;
    if ((uVar8 & 0x1fffff) != uVar8) {
      *(uint *)(param_1 + 0x10) = uVar6 & 0xffe00000;
    }
    if (bVar2) {
      return;
    }
  }
  sVar17 = uVar8 * 4 + 8;
  local_50 = _malloc(sVar17);
  if (local_50 != (undefined4 *)0x0) {
    local_50[1] = 0;
    local_4c = _malloc(sVar17);
    if (local_4c != (void *)0x0) {
      *(undefined4 *)((int)local_4c + 4) = 0;
    }
    if ((*(uint *)(param_1 + 0x10) & 0x40000000) == 0) {
      ((int (*)())_add_fdes)(param_1,&local_50,*(undefined4 *)(param_1 + 0xc));
    }
    else {
      piVar16 = *(int **)(param_1 + 0xc);
      iVar5 = *piVar16;
      while (iVar5 != 0) {
        ((int (*)())_add_fdes)(param_1,&local_50,iVar5);
        piVar16 = piVar16 + 1;
        iVar5 = *piVar16;
      }
    }
    if ((local_50 != (undefined4 *)0x0) && (local_50[1] != uVar8)) {
LAB_97c1d890:
                    
      _abort();
    }
    pcVar11 = DAT_a7b7c094;
    if (((*(uint *)(param_1 + 0x10) & 0x20000000) == 0) &&
       (pcVar11 = DAT_a7b7c08c, (*(uint *)(param_1 + 0x10) >> 0x15 & 0xff) == 0)) {
      pcVar11 = DAT_a7b7c090;
    }
    if (local_4c == (void *)0x0) {
      ((int (*)())_frame_heapsort)(param_1,pcVar11,local_50);
    }
    else {
      ((int (*)())_fde_split)(param_1,pcVar11,local_50);
      if (local_50[1] + *(int *)((int)local_4c + 4) != uVar8) goto LAB_97c1d890;
      ((int (*)())_frame_heapsort)(param_1,pcVar11);
      pvVar4 = local_4c;
      puVar3 = local_50;
      iVar5 = *(int *)((int)local_4c + 4);
      if (iVar5 != 0) {
        iVar7 = local_50[1];
        puVar12 = local_50 + iVar5;
        bVar2 = iVar7 == 0;
        puVar10 = (undefined4 *)((int)local_4c + iVar5 * 4 + 8);
        do {
          puVar12 = puVar12 + -1;
          iVar5 = iVar5 + -1;
          puVar15 = puVar12 + iVar7 + 2;
          puVar18 = puVar3 + iVar7;
          puVar10 = puVar10 + -1;
          uVar13 = *puVar10;
          while ((!bVar2 && (iVar9 = (*pcVar11)(param_1,puVar18[1],uVar13), 0 < iVar9))) {
            puVar1 = puVar18 + 1;
            iVar7 = iVar7 + -1;
            bVar2 = iVar7 == 0;
            puVar18 = puVar18 + -1;
            *puVar15 = *puVar1;
            puVar15 = puVar15 + -1;
          }
          puVar3[iVar7 + iVar5 + 2] = uVar13;
        } while (iVar5 != 0);
        puVar3[1] = puVar3[1] + *(int *)((int)pvVar4 + 4);
      }
      _free(local_4c);
    }
    *local_50 = *(undefined4 *)(param_1 + 0xc);
    *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) | 0x80000000;
    *(undefined4 **)(param_1 + 0xc) = local_50;
  }
  return;
}

/* _examine_objects @ 0x97c1d9ac (556 bytes) */
int _examine_objects(param_1, param_2, param_3)
  undefined4 param_1;
  uint *param_2;
  uint param_3;
{
  uint *puVar1;
  uint *puVar2;
  int iVar3;
  char *pcVar4;
  uint uVar5;
  undefined4 uVar6;
  uint *puVar7;
  uint *puVar8;
  int iVar9;
  uint local_60 [8];
  uint32_t local_40 [7];
  
  iVar3 = __keymgr_get_and_lock_processwide_ptr(0x12d);
  uVar6 = DAT_a7b7c088;
  iVar9 = 0;
  do {
    if (iVar3 == 0) {
LAB_97c1dbb0:
      __keymgr_unlock_processwide_ptr(0x12d);
      return iVar9;
    }
    if ((*(uint *)(iVar3 + 0x14) & 1) == 0) {
      pcVar4 = _getsectdatafromheader(*(mach_header **)(iVar3 + 4),"__DATA","__eh_frame",local_40);
      if (pcVar4 == (char *)0x0) {
        pcVar4 = _getsectdatafromheader(*(mach_header **)(iVar3 + 4),"__TEXT","__eh_frame",local_40)
        ;
        if (pcVar4 != (char *)0x0) {
          *(uint *)(iVar3 + 0x14) = *(uint *)(iVar3 + 0x14) | 4;
          goto LAB_97c1da58;
        }
      }
      else {
LAB_97c1da58:
        if (local_40[0] != 0) {
          puVar8 = (uint *)0x0;
          pcVar4 = pcVar4 + *(int *)(iVar3 + 8);
          if (param_3 == 0) {
            puVar8 = _calloc(1,0x1c);
          }
          param_3 = param_3 | puVar8 == (uint *)0x0;
          if (param_3 != 0) {
            puVar8 = local_60;
          }
          puVar8[3] = (uint)pcVar4;
          *puVar8 = 0xffffffff;
          puVar8[4] = 0x1fe00000;
          puVar8[1] = 0;
          puVar8[2] = 0;
          puVar8[5] = (uint)(pcVar4 + local_40[0]);
          *(char **)(iVar3 + 0x18) = pcVar4;
          iVar9 = ((int (*)())_search_object)(puVar8,param_1);
          if (param_3 == 0) {
            *(undefined4 *)(iVar3 + 0xc) = uVar6;
            puVar7 = (uint *)&_seen_objects;
            *(uint **)(iVar3 + 0x1c) = puVar8;
            *(uint *)(iVar3 + 0x14) = *(uint *)(iVar3 + 0x14) | 9;
            puVar2 = _seen_objects;
            if (_seen_objects != (uint *)0x0) {
              do {
                if (*puVar2 < *puVar8) goto LAB_97c1db30;
                puVar1 = puVar2 + 6;
                puVar7 = puVar2 + 6;
                puVar2 = (uint *)*puVar1;
              } while ((uint *)*puVar1 != (uint *)0x0);
              puVar2 = (uint *)0x0;
            }
LAB_97c1db30:
            puVar8[6] = (uint)puVar2;
            *puVar7 = (uint)puVar8;
          }
          if (iVar9 == 0) goto LAB_97c1dba4;
          *param_2 = puVar8[1];
          param_2[1] = puVar8[2];
          uVar5 = puVar8[4] >> 0x15 & 0xff;
          if ((puVar8[4] & 0x20000000) != 0) {
            uVar5 = ((int (*)())_get_cie_encoding)((iVar9 - *(int *)(iVar9 + 4)) + 4);
          }
          uVar6 = _base_from_object(uVar5 & 0xff,puVar8);
          _read_encoded_value_with_base_97c1c498(uVar5 & 0xff,uVar6,iVar9 + 8,param_2 + 2);
          goto LAB_97c1dbb0;
        }
      }
      *(uint *)(iVar3 + 0x14) = *(uint *)(iVar3 + 0x14) | 1;
    }
LAB_97c1dba4:
    iVar3 = *(int *)(iVar3 + 0x10);
  } while( true );
}

/* _fde_split @ 0x97c1dbd8 (296 bytes) */
int _fde_split(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  code *param_2;
  int param_3;
  int param_4;
{
  int iVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  int *piVar6;
  uint uVar7;
  uint uVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  undefined4 *puVar12;
  int iVar13;
  
  uVar8 = 0;
  uVar7 = *(uint *)(param_3 + 4);
  if (uVar7 != 0) {
    puVar12 = (undefined4 *)(param_4 + 8);
    puVar11 = (undefined4 *)(param_3 + 8);
    puVar10 = &_marker_0;
    iVar13 = param_3;
    do {
      while ((puVar10 != &_marker_0 && (iVar2 = (*param_2)(param_1,*puVar11,*puVar10), iVar2 < 0)))
      {
        puVar9 = *(undefined4 **)((int)puVar10 + (param_4 - param_3));
        *(undefined4 *)((int)puVar10 + (param_4 - param_3)) = 0;
        puVar10 = puVar9;
      }
      uVar8 = uVar8 + 1;
      *puVar12 = puVar10;
      puVar10 = (undefined4 *)(iVar13 + 8);
      puVar11 = puVar11 + 1;
      puVar12 = puVar12 + 1;
      iVar13 = iVar13 + 4;
    } while (uVar8 < uVar7);
  }
  iVar2 = 0;
  iVar13 = 0;
  if (uVar7 != 0) {
    piVar3 = (int *)(param_3 + 8);
    piVar4 = (int *)(param_4 + 8);
    piVar5 = piVar4;
    piVar6 = piVar3;
    do {
      iVar1 = *piVar4;
      piVar4 = piVar4 + 1;
      if (iVar1 == 0) {
        iVar2 = iVar2 + 1;
        *piVar5 = *piVar3;
        piVar5 = piVar5 + 1;
      }
      else {
        iVar13 = iVar13 + 1;
        *piVar6 = *piVar3;
        piVar6 = piVar6 + 1;
      }
      piVar3 = piVar3 + 1;
      uVar7 = uVar7 - 1;
    } while (uVar7 != 0);
  }
  *(int *)(param_3 + 4) = iVar13;
  *(int *)(param_4 + 4) = iVar2;
  return;
}

/* save_world @ 0x97c1dd00 (252 bytes) */
int save_world()
{
  int in_r11;
  int iVar1;
  
  iVar1 = *(int *)PTR_DAT_a7b7c100;
  *(BADSPACEBASE **)(&STACKARG(0x0) + in_r11) = ((unsigned int)__builtin_frame_address(0));
  if (iVar1 == 0) {
    return;
  }
  return;
}

/* eh_rest_world_r10 @ 0x97c1de10 (264 bytes) */
int eh_rest_world_r10()
{
  int in_stack_00000000;
  
                    
                    
  (**(code **)(in_stack_00000000 + 8))
            (*(undefined4 *)(in_stack_00000000 + -0x1b0),*(undefined4 *)(in_stack_00000000 + -0x1ac)
             ,*(undefined4 *)(in_stack_00000000 + -0x1a8),
             *(undefined4 *)(in_stack_00000000 + -0x1a4));
  return;
}

/* std__string__string_97c30ae0 @ 0x97c30ae0 (4 bytes) */
int std__string__string_97c30ae0(this, param_1, param_2)
  unsigned char *this;
  char *param_1;
  unsigned char *param_2;
{
  std__string__string(this,param_1,param_2);
  return;
}

/* std__string__string_97c30ae4 @ 0x97c30ae4 (100 bytes) */
int std__string__string_97c30ae4(this, param_1, param_2)
  unsigned char *this;
  char *param_1;
  unsigned char *param_2;
{
  undefined4 uVar1;
  string *psVar2;
  char *pcVar3;
  
  if (param_1 == (char *)0x0) {
    pcVar3 = (char *)0xffffffff;
    psVar2 = this;
  }
  else {
    psVar2 = (unsigned char *)_strlen(param_1);
    pcVar3 = param_1 + (int)psVar2;
  }
  pcVar3 = std__string___S_construct_char_const__(psVar2,pcVar3,param_2,0);
  uVar1 = *(undefined4 *)param_2;
  *(char **)(this + 4) = pcVar3;
  *(undefined4 *)this = uVar1;
  return;
}

/* std__string__string_97c30b48 @ 0x97c30b48 (4 bytes) */
int std__string__string_97c30b48(this, param_1)
  unsigned char *this;
  unsigned char *param_1;
{
  std__string__string(this,param_1);
  return;
}

/* std__string__string_97c30b4c @ 0x97c30b4c (148 bytes) */
int std__string__string_97c30b4c(this, param_1)
  unsigned char *this;
  unsigned char *param_1;
{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  char in_RESERVE;
  byte in_cr0;
  int local_40 [4];
  int local_30;
  
  iVar4 = *(int *)(param_1 + 4);
  local_40[0] = GetGlobalPoolAllocator();
  local_30 = *(int *)param_1;
  if ((*(int *)(iVar4 + -4) < 0) || (local_40[0] != local_30)) {
    iVar4 = std__string___Rep___M_clone((unsigned char *)(iVar4 + -0xc),(ulong)local_40);
  }
  else {
    piVar2 = (int *)(iVar4 + -4);
    do {
      if (in_RESERVE != '\0') {
        iVar1 = storeWordConditionalIndexed(*piVar2 + 1,0,piVar2);
        *piVar2 = iVar1;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
  }
  uVar3 = *(undefined4 *)param_1;
  *(int *)(this + 4) = iVar4;
  *(undefined4 *)this = uVar3;
  return;
}

/* std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol______insert_unique @ 0x97c30be0 (388 bytes) */
pair * std::
       _Rb_tree<std::string,std::pair<std::string_const,TSymbol*>,std::_Select1st<std::pair<std::string_const,TSymbol*>>,std::less<std::string>,pool_allocator<std::pair<std::string_const,TSymbol*>>>
       ::insert_unique(unsigned char *param_1)

{
  int iVar1;
  _Rb_tree_node_base *in_r4;
  int in_r5;
  uint *puVar2;
  void *pvVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  int local_60 [4];
  int local_50 [4];
  uint local_40;
  uint local_3c;
  uint local_38;
  uint local_34;
  
  iVar4 = *(int *)(in_r4 + 4);
  iVar1 = 1;
  iVar5 = iVar4;
  if (*(int *)(iVar4 + 4) != 0) {
    pvVar3 = *(void **)(in_r5 + 4);
    iVar6 = *(int *)(iVar4 + 4);
    do {
      iVar5 = iVar6;
      uVar7 = *(uint *)((int)pvVar3 + -0xc);
      local_40 = uVar7;
      uVar8 = *(uint *)(*(int *)(iVar5 + 0x14) + -0xc);
      local_3c = uVar8;
      puVar2 = &local_3c;
      if (uVar7 <= uVar8) {
        puVar2 = &local_40;
      }
      iVar1 = _memcmp(pvVar3,*(void **)(iVar5 + 0x14),*puVar2);
      if (iVar1 == 0) {
        iVar1 = uVar7 - uVar8;
      }
      iVar1 = -(iVar1 >> 0x1f);
      if (iVar1 == 0) {
        iVar6 = *(int *)(iVar5 + 0xc);
      }
      else {
        iVar6 = *(int *)(iVar5 + 8);
      }
    } while (iVar6 != 0);
  }
  if (iVar1 != 0) {
    local_60[0] = *(int *)(iVar4 + 8);
    if (iVar5 == local_60[0]) {
      std::
      _Rb_tree<std::string,std::pair<std::string_const,TSymbol*>,std::_Select1st<std::pair<std::string_const,TSymbol*>>,std::less<std::string>,pool_allocator<std::pair<std::string_const,TSymbol*>>>
      ::_M_insert((unsigned char *)local_50,in_r4,(unsigned char *)0x0);
      goto LAB_97c30d34;
    }
    ((int (*)())std___Rb_tree_base_iterator___M_decrement)();
  }
  puVar2 = &local_34;
  uVar7 = *(uint *)(*(int *)(iVar5 + 0x14) + -0xc);
  local_38 = uVar7;
  uVar8 = *(uint *)((int)*(void **)(in_r5 + 4) + -0xc);
  local_34 = uVar8;
  if (uVar7 <= uVar8) {
    puVar2 = &local_38;
  }
  iVar1 = _memcmp(*(void **)(iVar5 + 0x14),*(void **)(in_r5 + 4),*puVar2);
  if (iVar1 == 0) {
    iVar1 = uVar7 - uVar8;
  }
  if (-1 < iVar1) {
    *(int *)param_1 = iVar5;
    *(undefined4 *)(param_1 + 4) = 0;
    return param_1;
  }
  std::
  _Rb_tree<std::string,std::pair<std::string_const,TSymbol*>,std::_Select1st<std::pair<std::string_const,TSymbol*>>,std::less<std::string>,pool_allocator<std::pair<std::string_const,TSymbol*>>>
  ::_M_insert((unsigned char *)local_60,in_r4,(unsigned char *)0x0);
  local_50[0] = local_60[0];
LAB_97c30d34:
  *(int *)param_1 = local_50[0];
  *(undefined4 *)(param_1 + 4) = 1;
  return param_1;
}

/* std__string___Rep___M_destroy_97c30d64 @ 0x97c30d64 (12 bytes) */
int std__string___Rep___M_destroy_97c30d64(param_1)
  unsigned char *param_1;
{
  return;
}

/* std__string___S_construct_char_const___97c30d70 @ 0x97c30d70 (196 bytes) */
int std__string___S_construct_char_const___97c30d70(param_1, param_2, param_3)
  void *param_1;
  void *param_2;
  unsigned char *param_3;
{
  int iVar1;
  int *piVar2;
  int iVar3;
  ulong *puVar4;
  ulong uVar5;
  ulong *puVar6;
  char in_RESERVE;
  byte in_cr0;
  
  if ((param_1 == param_2) &&
     (iVar3 = GetGlobalPoolAllocator(), iVar1 = (*(int *)0xa7b7b71c), *(int *)param_3 == iVar3)) {
    piVar2 = (int *)((*(int *)0xa7b7b71c) + 8);
    do {
      if (in_RESERVE != '\0') {
        iVar3 = storeWordConditionalIndexed(*piVar2 + 1,0,piVar2);
        *piVar2 = iVar3;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    return (char *)(iVar1 + 0xc);
  }
  if (param_1 == (void *)0x0) {
    std____throw_logic_error("attempt to create string with null pointer");
  }
  uVar5 = (int)param_2 - (int)param_1;
  puVar4 = (ulong *)std__string___Rep___S_create(uVar5,param_3);
  puVar6 = puVar4 + 3;
  _memcpy(puVar6,param_1,uVar5);
  *puVar4 = uVar5;
  *(char *)((int)puVar6 + uVar5) = '\0';
  return (char *)puVar6;
}

/* std__string___Rep___M_clone_97c30e34 @ 0x97c30e34 (148 bytes) */
int std__string___Rep___M_clone_97c30e34(this, param_1, param_2)
  unsigned char *this;
  unsigned char *param_1;
  ulong param_2;
{
  uint uVar1;
  undefined4 *puVar2;
  undefined4 uVar4;
  uint uVar3;
  
  uVar1 = *(int *)this + param_2;
  uVar3 = uVar1;
  if (((*(uint *)(this + 4) < uVar1) && (0xfe3 < uVar1)) &&
     (uVar3 = *(uint *)(this + 4) << 1, uVar3 < uVar1)) {
    uVar3 = uVar1;
  }
  puVar2 = (undefined4 *)std__string___Rep___S_create(uVar3,param_1);
  uVar4 = 0;
  if (*(size_t *)this != 0) {
    _memcpy(puVar2 + 3,this + 0xc,*(size_t *)this);
    uVar4 = *(undefined4 *)this;
  }
  *puVar2 = uVar4;
  return puVar2 + 3;
}

/* std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol_______M_insert @ 0x97c30ec8 (356 bytes) */
_Rb_tree_node_base *
std::
_Rb_tree<std::string,std::pair<std::string_const,TSymbol*>,std::_Select1st<std::pair<std::string_const,TSymbol*>>,std::less<std::string>,pool_allocator<std::pair<std::string_const,TSymbol*>>>
::_M_insert(unsigned char *param_1,unsigned char *param_2,unsigned char *param_3)

{
  int iVar1;
  _Rb_tree_node_base *p_Var2;
  uint *puVar3;
  int in_r6;
  string *in_r7;
  uint uVar4;
  uint uVar5;
  uint local_30;
  uint local_2c [4];
  
  if ((in_r6 == *(int *)(param_2 + 4)) || (param_3 != (unsigned char *)0x0)) {
LAB_97c30f44:
    p_Var2 = (unsigned char *)TPoolAllocator__allocate(*(ulong *)param_2);
    if ((unsigned char *)(p_Var2 + 0x10) != (unsigned char *)0x0) {
      std__string__string((unsigned char *)(p_Var2 + 0x10),in_r7);
      *(undefined4 *)(p_Var2 + 0x18) = *(undefined4 *)(in_r7 + 8);
    }
    *(_Rb_tree_node_base **)(in_r6 + 8) = p_Var2;
    iVar1 = *(int *)(param_2 + 4);
    if (in_r6 != iVar1) {
      if (in_r6 == *(int *)(iVar1 + 8)) {
        *(_Rb_tree_node_base **)(iVar1 + 8) = p_Var2;
      }
      goto LAB_97c30fe4;
    }
    *(_Rb_tree_node_base **)(in_r6 + 4) = p_Var2;
    iVar1 = *(int *)(param_2 + 4);
  }
  else {
    puVar3 = local_2c;
    uVar5 = *(uint *)(*(int *)(in_r7 + 4) + -0xc);
    local_30 = uVar5;
    uVar4 = *(uint *)((int)*(void **)(in_r6 + 0x14) + -0xc);
    local_2c[0] = uVar4;
    if (uVar5 <= uVar4) {
      puVar3 = &local_30;
    }
    iVar1 = _memcmp(*(void **)(in_r7 + 4),*(void **)(in_r6 + 0x14),*puVar3);
    if (iVar1 == 0) {
      iVar1 = uVar5 - uVar4;
    }
    if (iVar1 < 0) goto LAB_97c30f44;
    p_Var2 = (unsigned char *)TPoolAllocator__allocate(*(ulong *)param_2);
    if ((unsigned char *)(p_Var2 + 0x10) != (unsigned char *)0x0) {
      std__string__string((unsigned char *)(p_Var2 + 0x10),in_r7);
      *(undefined4 *)(p_Var2 + 0x18) = *(undefined4 *)(in_r7 + 8);
    }
    *(_Rb_tree_node_base **)(in_r6 + 0xc) = p_Var2;
    iVar1 = *(int *)(param_2 + 4);
    if (in_r6 != *(int *)(iVar1 + 0xc)) goto LAB_97c30fe4;
  }
  *(_Rb_tree_node_base **)(iVar1 + 0xc) = p_Var2;
LAB_97c30fe4:
  *(int *)(p_Var2 + 4) = in_r6;
  *(undefined4 *)(p_Var2 + 0xc) = 0;
  *(undefined4 *)(p_Var2 + 8) = 0;
  ((int (*)())std___Rb_tree_rebalance)(p_Var2,(_Rb_tree_node_base **)(*(int *)(param_2 + 4) + 4));
  *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 1;
  *(_Rb_tree_node_base **)param_1 = p_Var2;
  return param_1;
}

/* std__string___Rep___S_create_97c3102c @ 0x97c3102c (172 bytes) */
int std__string___Rep___S_create_97c3102c(param_1, param_2)
  ulong param_1;
  unsigned char *param_2;
{
  uint uVar1;
  undefined4 *puVar2;
  
  if (0x3ffffffc < param_1) {
    std____throw_length_error("basic_string::_S_create");
  }
  uVar1 = param_1 + 0x1d;
  if (uVar1 < 0x1001) {
    if (param_1 + 0xd < 0x81) goto LAB_97c310a4;
    uVar1 = 0x80 - (uVar1 & 0x7f) & 0x7f;
  }
  else {
    uVar1 = 0x1000 - (uVar1 & 0xfff) & 0xfff;
  }
  param_1 = param_1 + uVar1;
LAB_97c310a4:
  puVar2 = (undefined4 *)TPoolAllocator__allocate(*(ulong *)param_2);
  *puVar2 = 0;
  puVar2[1] = param_1;
  puVar2[2] = 0;
  return;
}

/* std___Rb_tree_base_iterator___M_decrement @ 0x97c310d8 (144 bytes) */
int std___Rb_tree_base_iterator___M_decrement(this)
  unsigned char *this;
{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  piVar3 = *(int **)this;
  if ((*piVar3 == 0) && (*(int **)(piVar3[1] + 4) == piVar3)) {
    *(int *)this = piVar3[3];
    return;
  }
  iVar2 = piVar3[2];
  if (iVar2 == 0) {
    iVar2 = piVar3[1];
    if (piVar3 == *(int **)(iVar2 + 8)) {
      do {
        *(int *)this = iVar2;
        iVar2 = *(int *)(iVar2 + 4);
      } while (*(int *)this == *(int *)(iVar2 + 8));
    }
    *(int *)this = iVar2;
    return;
  }
  for (iVar1 = *(int *)(iVar2 + 0xc); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0xc)) {
    iVar2 = iVar1;
  }
  *(int *)this = iVar2;
  return;
}

/* std___Rb_tree_rebalance @ 0x97c31168 (328 bytes) */
int std___Rb_tree_rebalance(param_1, param_2)
  unsigned char *param_1;
  _Rb_tree_node_base **param_2;
{
  int iVar1;
  _Rb_tree_node_base *p_Var2;
  _Rb_tree_node_base *p_Var3;
  _Rb_tree_node_base *p_Var4;
  
  *(undefined4 *)param_1 = 0;
  p_Var2 = *param_2;
  if (param_1 != p_Var2) {
    p_Var3 = *(_Rb_tree_node_base **)(param_1 + 4);
    iVar1 = *(int *)p_Var3;
    while (iVar1 == 0) {
      p_Var4 = *(_Rb_tree_node_base **)(p_Var3 + 4);
      p_Var2 = *(_Rb_tree_node_base **)(p_Var4 + 8);
      if (p_Var3 == p_Var2) {
        p_Var2 = *(_Rb_tree_node_base **)(p_Var4 + 0xc);
        if ((p_Var2 == (unsigned char *)0x0) || (*(int *)p_Var2 != 0)) {
          p_Var4 = param_1;
          p_Var2 = p_Var3;
          if (param_1 == *(_Rb_tree_node_base **)(p_Var3 + 0xc)) {
            ((int (*)())std___Rb_tree_rotate_left)(p_Var3,param_2);
            p_Var2 = *(_Rb_tree_node_base **)(p_Var3 + 4);
            p_Var4 = p_Var3;
          }
          p_Var3 = *(_Rb_tree_node_base **)(p_Var2 + 4);
          *(undefined4 *)p_Var2 = 1;
          *(undefined4 *)p_Var3 = 0;
          ((int (*)())std___Rb_tree_rotate_right)(p_Var3,param_2);
        }
        else {
LAB_97c31228:
          *(undefined4 *)p_Var3 = 1;
          *(undefined4 *)p_Var2 = 1;
          *(undefined4 *)p_Var4 = 0;
        }
      }
      else {
        if ((p_Var2 != (unsigned char *)0x0) && (*(int *)p_Var2 == 0)) goto LAB_97c31228;
        p_Var4 = param_1;
        p_Var2 = p_Var3;
        if (param_1 == *(_Rb_tree_node_base **)(p_Var3 + 8)) {
          ((int (*)())std___Rb_tree_rotate_right)(p_Var3,param_2);
          p_Var2 = *(_Rb_tree_node_base **)(p_Var3 + 4);
          p_Var4 = p_Var3;
        }
        p_Var3 = *(_Rb_tree_node_base **)(p_Var2 + 4);
        *(undefined4 *)p_Var2 = 1;
        *(undefined4 *)p_Var3 = 0;
        ((int (*)())std___Rb_tree_rotate_left)(p_Var3,param_2);
      }
      p_Var2 = *param_2;
      if (p_Var4 == p_Var2) break;
      p_Var3 = *(_Rb_tree_node_base **)(p_Var4 + 4);
      param_1 = p_Var4;
      iVar1 = *(int *)p_Var3;
    }
  }
  *(undefined4 *)p_Var2 = 1;
  return;
}

/* TType__getTypeName @ 0x97c312b0 (8 bytes) */
int TType__getTypeName(this)
  unsigned char *this;
{
  return *(undefined4 *)(this + 0x10);
}

/* TType___TType @ 0x97c312b8 (36 bytes) */
int TType___TType(this)
  unsigned char *this;
{
  *(undefined ***)this = &PTR__TType_a7b7cf48;
  return;
}

/* TType___TType_97c312dc @ 0x97c312dc (36 bytes) */
int TType___TType_97c312dc(this)
  unsigned char *this;
{
  *(undefined ***)this = &PTR__TType_a7b7cf48;
  return;
}

/* TType__isArray @ 0x97c31300 (12 bytes) */
int TType__isArray(this)
  unsigned char *this;
{
  return *(uint *)(this + 0x24) >> 9 & 1;
}

/* TType__getInstanceSize @ 0x97c3130c (40 bytes) */
int TType__getInstanceSize(this)
  unsigned char *this;
{
  uint uVar1;
  int iVar2;
  
  uVar1 = *(uint *)(this + 0x24);
  if ((uVar1 & 0x400) != 0) {
    iVar2 = (int)(uVar1 << 0xd | uVar1 >> 0x13) >> 0x18;
    return iVar2 * iVar2;
  }
  return (int)(uVar1 << 0xd | uVar1 >> 0x13) >> 0x18;
}

/* TType__isMatrix @ 0x97c31334 (12 bytes) */
int TType__isMatrix(this)
  unsigned char *this;
{
  return *(uint *)(this + 0x24) >> 10 & 1;
}

/* TType__isVector @ 0x97c31340 (40 bytes) */
int TType__isVector(this)
  unsigned char *this;
{
  uint uVar1;
  
  uVar1 = *(uint *)(this + 0x24);
  if ((int)(uVar1 << 0xd | uVar1 >> 0x13) >> 0x18 < 2) {
    return 0;
  }
  if ((uVar1 & 0x400) != 0) {
    return 0;
  }
  return 1;
}

/* TType__setType @ 0x97c31368 (32 bytes) */
int TType__setType(this, param_2, param_3, param_4, param_5, param_6)
  unsigned char *this;
  uint param_2;
  uint param_3;
  uint param_4;
  uint param_5;
  undefined4 param_6;
{
  *(undefined4 *)(this + 4) = param_6;
  *(uint *)(this + 0x24) =
       (param_5 & 1) << 9 |
       (param_4 & 1) << 10 |
       (param_3 & 0xff) << 0xb | (param_2 & 0x3f) << 0x13 | *(uint *)(this + 0x24) & 0xfe0001ff;
  return;
}

/* TType__setType_97c31388 @ 0x97c31388 (40 bytes) */
int TType__setType_97c31388(this, param_2, param_3, param_4, param_5)
  unsigned char *this;
  uint param_2;
  uint param_3;
  uint param_4;
  int param_5;
{
  *(uint *)(this + 0x24) =
       (param_4 & 1) << 10 |
       (param_3 & 0xff) << 0xb | (param_2 & 0x3f) << 0x13 | *(uint *)(this + 0x24) & 0xfe0003ff;
  if (param_5 == 0) {
    return;
  }
  *(undefined4 *)(this + 8) = *(undefined4 *)(param_5 + 8);
  return;
}

/* TType__setTypeName @ 0x97c313b0 (132 bytes) */
int TType__setTypeName(this, param_1)
  unsigned char *this;
  unsigned char *param_1;
{
  string *psVar1;
  ulong uVar2;
  string *this_00;
  char *pcVar3;
  undefined4 local_20 [4];
  
  *(undefined1 *)(*(int *)(param_1 + 4) + *(int *)(*(int *)(param_1 + 4) + -0xc)) = *DAT_a7b7b718;
  pcVar3 = *(char **)(param_1 + 4);
  uVar2 = GetGlobalPoolAllocator();
  this_00 = (unsigned char *)TPoolAllocator__allocate(uVar2);
  psVar1 = (unsigned char *)0x0;
  if (this_00 != (unsigned char *)0x0) {
    local_20[0] = GetGlobalPoolAllocator();
    std__string__string(this_00,pcVar3,(unsigned char *)local_20);
    psVar1 = this_00;
  }
  *(string **)(this + 0x10) = psVar1;
  return;
}

/* TType__setFieldName @ 0x97c31434 (132 bytes) */
int TType__setFieldName(this, param_1)
  unsigned char *this;
  unsigned char *param_1;
{
  string *psVar1;
  ulong uVar2;
  string *this_00;
  char *pcVar3;
  undefined4 local_20 [4];
  
  *(undefined1 *)(*(int *)(param_1 + 4) + *(int *)(*(int *)(param_1 + 4) + -0xc)) = *DAT_a7b7b718;
  pcVar3 = *(char **)(param_1 + 4);
  uVar2 = GetGlobalPoolAllocator();
  this_00 = (unsigned char *)TPoolAllocator__allocate(uVar2);
  psVar1 = (unsigned char *)0x0;
  if (this_00 != (unsigned char *)0x0) {
    local_20[0] = GetGlobalPoolAllocator();
    std__string__string(this_00,pcVar3,(unsigned char *)local_20);
    psVar1 = this_00;
  }
  *(string **)(this + 0xc) = psVar1;
  return;
}

/* TType__getFieldName @ 0x97c314b8 (8 bytes) */
int TType__getFieldName(this)
  unsigned char *this;
{
  return *(undefined4 *)(this + 0xc);
}

/* TType__getBasicType @ 0x97c314c0 (12 bytes) */
int TType__getBasicType(this)
  unsigned char *this;
{
  return *(uint *)(this + 0x24) >> 0x13 & 0x3f;
}

/* TType__getQualifier @ 0x97c314cc (12 bytes) */
int TType__getQualifier(this)
  unsigned char *this;
{
  return *(uint *)(this + 0x24) >> 0x19;
}

/* TType__changeQualifier @ 0x97c314d8 (16 bytes) */
int TType__changeQualifier(this, param_2)
  unsigned char *this;
  int param_2;
{
  *(uint *)(this + 0x24) = param_2 << 0x19 | *(uint *)(this + 0x24) & 0x1ffffff;
  return;
}

/* TType__getNominalSize @ 0x97c314e8 (16 bytes) */
int TType__getNominalSize(this)
  unsigned char *this;
{
  return (int)(*(uint *)(this + 0x24) << 0xd | *(uint *)(this + 0x24) >> 0x13) >> 0x18;
}

/* std___Rb_tree_rotate_left @ 0x97c314f8 (92 bytes) */
int std___Rb_tree_rotate_left(param_1, param_2)
  unsigned char *param_1;
  _Rb_tree_node_base **param_2;
{
  int iVar1;
  _Rb_tree_node_base *p_Var2;
  
  p_Var2 = *(_Rb_tree_node_base **)(param_1 + 0xc);
  iVar1 = *(int *)(p_Var2 + 8);
  *(int *)(param_1 + 0xc) = iVar1;
  if (iVar1 != 0) {
    *(_Rb_tree_node_base **)(iVar1 + 4) = param_1;
  }
  *(undefined4 *)(p_Var2 + 4) = *(undefined4 *)(param_1 + 4);
  if (param_1 == *param_2) {
    *param_2 = p_Var2;
  }
  else {
    iVar1 = *(int *)(param_1 + 4);
    if (param_1 == *(_Rb_tree_node_base **)(iVar1 + 8)) {
      *(_Rb_tree_node_base **)(iVar1 + 8) = p_Var2;
    }
    else {
      *(_Rb_tree_node_base **)(iVar1 + 0xc) = p_Var2;
    }
  }
  *(_Rb_tree_node_base **)(param_1 + 4) = p_Var2;
  *(_Rb_tree_node_base **)(p_Var2 + 8) = param_1;
  return;
}

/* std___Rb_tree_rotate_right @ 0x97c31554 (92 bytes) */
int std___Rb_tree_rotate_right(param_1, param_2)
  unsigned char *param_1;
  _Rb_tree_node_base **param_2;
{
  int iVar1;
  _Rb_tree_node_base *p_Var2;
  
  p_Var2 = *(_Rb_tree_node_base **)(param_1 + 8);
  iVar1 = *(int *)(p_Var2 + 0xc);
  *(int *)(param_1 + 8) = iVar1;
  if (iVar1 != 0) {
    *(_Rb_tree_node_base **)(iVar1 + 4) = param_1;
  }
  *(undefined4 *)(p_Var2 + 4) = *(undefined4 *)(param_1 + 4);
  if (param_1 == *param_2) {
    *param_2 = p_Var2;
  }
  else {
    iVar1 = *(int *)(param_1 + 4);
    if (param_1 == *(_Rb_tree_node_base **)(iVar1 + 0xc)) {
      *(_Rb_tree_node_base **)(iVar1 + 0xc) = p_Var2;
    }
    else {
      *(_Rb_tree_node_base **)(iVar1 + 8) = p_Var2;
    }
  }
  *(_Rb_tree_node_base **)(param_1 + 4) = p_Var2;
  *(_Rb_tree_node_base **)(p_Var2 + 0xc) = param_1;
  return;
}

/* std__string__assign_97c315b0 @ 0x97c315b0 (200 bytes) */
int std__string__assign_97c315b0(this, param_1)
  unsigned char *this;
  unsigned char *param_1;
{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  char in_RESERVE;
  byte in_cr0;
  int local_30 [4];
  int local_20;
  
  iVar4 = *(int *)(param_1 + 4);
  if ((unsigned char *)(*(int *)(this + 4) + -0xc) != (unsigned char *)(iVar4 + -0xc)) {
    local_20 = *(int *)param_1;
    local_30[0] = *(int *)this;
    if ((*(int *)(iVar4 + -4) < 0) || (local_30[0] != local_20)) {
      iVar4 = std__string___Rep___M_clone((unsigned char *)(iVar4 + -0xc),(ulong)local_30);
    }
    else {
      piVar2 = (int *)(iVar4 + -4);
      do {
        if (in_RESERVE != '\0') {
          iVar5 = storeWordConditionalIndexed(*piVar2 + 1,0,piVar2);
          *piVar2 = iVar5;
          in_cr0 = 2;
        }
      } while (!(bool)(in_cr0 >> 1 & 1));
    }
    iVar5 = *(int *)(this + 4);
    piVar2 = (int *)(iVar5 + -4);
    do {
      iVar3 = *piVar2;
      if (in_RESERVE != '\0') {
        iVar1 = storeWordConditionalIndexed(iVar3 + -1,0,piVar2);
        *piVar2 = iVar1;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if (iVar3 < 1) {
      std__string___Rep___M_destroy((unsigned char *)(iVar5 + -0xc));
    }
    *(int *)(this + 4) = iVar4;
  }
  return this;
}

/* std__vector_TIntermNode__pool_allocator_TIntermNode______M_insert_aux @ 0x97c31678 (252 bytes) */
int std__vector_TIntermNode__pool_allocator_TIntermNode______M_insert_aux(vector<TIntermNode*,pool_allocator<TIntermNode*>> *this,undefined4 *param_2,
          undefined4 *param_3)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  void *pvVar5;
  void *pvVar6;
  undefined4 uVar7;
  size_t sVar8;
  
  puVar3 = *(undefined4 **)(this + 8);
  if (puVar3 == *(undefined4 **)(this + 0xc)) {
    iVar4 = 1;
    iVar2 = (int)puVar3 - *(int *)(this + 4) >> 2;
    if (iVar2 != 0) {
      iVar4 = iVar2 << 1;
    }
    pvVar5 = (void *)TPoolAllocator__allocate(*(ulong *)this);
    sVar8 = (int)param_2 - (int)*(void **)(this + 4);
    _memmove(pvVar5,*(void **)(this + 4),sVar8);
    if ((int)pvVar5 + sVar8 != 0) {
      *(undefined4 *)((int)pvVar5 + sVar8) = *param_3;
    }
    iVar2 = *(int *)(this + 8);
    pvVar6 = (void *)((int)pvVar5 + sVar8 + 4);
    _memmove(pvVar6,param_2,iVar2 - (int)param_2);
    *(void **)(this + 0xc) = (void *)((int)pvVar5 + iVar4 * 4);
    *(int *)(this + 8) = (int)pvVar6 + (iVar2 - (int)param_2);
    *(void **)(this + 4) = pvVar5;
  }
  else {
    iVar4 = 0;
    if (puVar3 != (undefined4 *)0x0) {
      *puVar3 = puVar3[-1];
      iVar4 = *(int *)(this + 8);
    }
    *(int *)(this + 8) = iVar4 + 4;
    uVar1 = (iVar4 + -4) - (int)param_2 & 0xfffffffc;
    uVar7 = *param_3;
    _memmove((void *)(iVar4 - uVar1),param_2,uVar1);
    *param_2 = uVar7;
  }
  return;
}

/* std__vector_TIntermNode__pool_allocator_TIntermNode_____erase @ 0x97c31774 (96 bytes) */
int std__vector_TIntermNode__pool_allocator_TIntermNode_____erase(param_1, param_2, param_3)
  undefined4 *param_1;
  int param_2;
  void *param_3;
{
  void *pvVar1;
  void *pvVar2;
  
  pvVar2 = *(void **)(param_2 + 8);
  pvVar1 = (void *)((int)param_3 + 4);
  if (pvVar1 != pvVar2) {
    _memmove(param_3,pvVar1,(int)pvVar2 - (int)pvVar1);
    pvVar2 = *(void **)(param_2 + 8);
  }
  *(int *)(param_2 + 8) = (int)pvVar2 + -4;
  *param_1 = param_3;
  return param_1;
}

/* std__vector_TIntermNode__pool_allocator_TIntermNode_____insert @ 0x97c317d4 (152 bytes) */
int std__vector_TIntermNode__pool_allocator_TIntermNode_____insert(param_1, param_2, param_3, param_4)
  int *param_1;
  int param_2;
  undefined4 *param_3;
  undefined4 *param_4;
{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  
  puVar2 = *(undefined4 **)(param_2 + 8);
  iVar3 = *(int *)(param_2 + 4);
  iVar1 = (int)param_3 - iVar3;
  if ((puVar2 == *(undefined4 **)(param_2 + 0xc)) || (param_3 != puVar2)) {
    ((int (*)())std__vector_TIntermNode__pool_allocator_TIntermNode______M_insert_aux)(param_2,param_3,param_4);
    iVar3 = *(int *)(param_2 + 4);
  }
  else {
    if (param_3 != (undefined4 *)0x0) {
      *param_3 = *param_4;
      iVar3 = *(int *)(param_2 + 4);
      puVar2 = *(undefined4 **)(param_2 + 8);
    }
    *(undefined4 **)(param_2 + 8) = puVar2 + 1;
  }
  *param_1 = iVar3 + (iVar1 >> 2) * 4;
  return param_1;
}

/* std__vector_TIntermNode__pool_allocator_TIntermNode______M_range_insert___gnu_cxx____normal_iterator_TIntermNode___std__vector_TIntermNode__pool_allocator_TIntermNode_____ @ 0x97c3186c (424 bytes) */
void std::vector<TIntermNode*,pool_allocator<TIntermNode*>>::
     _M_range_insert<__gnu_cxx::__normal_iterator<TIntermNode**,std::vector<TIntermNode*,pool_allocator<TIntermNode*>>>>
               (ulong *param_1,void *param_2,void *param_3,void *param_4)

{
  void *pvVar1;
  size_t sVar2;
  size_t sVar3;
  uint uVar4;
  void *pvVar5;
  uint uVar6;
  void *pvVar8;
  ulong uVar9;
  uint local_40;
  uint local_3c [5];
  uint *puVar7;
  
  if (param_3 != param_4) {
    sVar3 = (int)param_4 - (int)param_3;
    pvVar5 = (void *)param_1[2];
    local_3c[0] = (int)sVar3 >> 2;
    if ((uint)((int)(param_1[3] - (int)pvVar5) >> 2) < local_3c[0]) {
      puVar7 = local_3c;
      uVar4 = (int)((int)pvVar5 - param_1[1]) >> 2;
      local_40 = uVar4;
      if (local_3c[0] <= uVar4) {
        puVar7 = &local_40;
      }
      uVar6 = *puVar7;
      pvVar5 = (void *)TPoolAllocator__allocate(*param_1);
      sVar2 = (int)param_2 - (int)param_1[1];
      pvVar1 = (void *)((int)pvVar5 + sVar2);
      _memmove(pvVar5,(void *)param_1[1],sVar2);
      pvVar8 = (void *)((int)pvVar1 + sVar3);
      _memmove(pvVar1,param_3,sVar3);
      uVar9 = param_1[2];
      _memmove(pvVar8,param_2,uVar9 - (int)param_2);
      param_1[3] = (ulong)((int)pvVar5 + (uVar4 + uVar6) * 4);
      param_1[2] = (int)pvVar8 + (uVar9 - (int)param_2);
      param_1[1] = (ulong)pvVar5;
    }
    else {
      uVar4 = (int)pvVar5 - (int)param_2 >> 2;
      if (local_3c[0] < uVar4) {
        pvVar1 = (void *)((int)pvVar5 + local_3c[0] * -4);
        _memmove(pvVar5,pvVar1,(int)pvVar5 - (int)pvVar1);
        param_1[2] = param_1[2] + local_3c[0] * 4;
        uVar4 = (int)pvVar5 + (local_3c[0] * -4 - (int)param_2) & 0xfffffffc;
        _memmove((void *)((int)pvVar5 - uVar4),param_2,uVar4);
      }
      else {
        pvVar8 = (void *)((int)param_3 + uVar4 * 4);
        _memmove(pvVar5,pvVar8,(int)param_4 - (int)pvVar8);
        pvVar1 = (void *)(param_1[2] + (local_3c[0] - uVar4) * 4);
        param_1[2] = (ulong)pvVar1;
        _memmove(pvVar1,param_2,(int)pvVar5 - (int)param_2);
        sVar3 = (int)pvVar8 - (int)param_3;
        param_1[2] = param_1[2] + uVar4 * 4;
      }
      _memmove(param_2,param_3,sVar3);
    }
  }
  return;
}

/* std___Rb_tree_std__string_std__pair_std__string_const_std__string__std___Select1st_std__pair_std__string_const_std__string___std__less_std__string__pool_allocator_std__pair_std__string_const_std__string_____operator_ @ 0x97c31a14 (280 bytes) */
_Rb_tree<std::string,std::pair<std::string_const,std::string>,std::_Select1st<std::pair<std::string_const,std::string>>,std::less<std::string>,pool_allocator<std::pair<std::string_const,std::string>>>
* 
std::
_Rb_tree<std::string,std::pair<std::string_const,std::string>,std::_Select1st<std::pair<std::string_const,std::string>>,std::less<std::string>,pool_allocator<std::pair<std::string_const,std::string>>>
::operator=(_Rb_tree<std::string,std::pair<std::string_const,std::string>,std::_Select1st<std::pair<std::string_const,std::string>>,std::less<std::string>,pool_allocator<std::pair<std::string_const,std::string>>>
            *this,unsigned char *param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (this != (_Rb_tree<std::string,std::pair<std::string_const,std::string>,std::_Select1st<std::pair<std::string_const,std::string>>,std::less<std::string>,pool_allocator<std::pair<std::string_const,std::string>>>
               *)param_1) {
    if (*(int *)(this + 8) != 0) {
      std::
      _Rb_tree<std::string,std::pair<std::string_const,std::string>,std::_Select1st<std::pair<std::string_const,std::string>>,std::less<std::string>,pool_allocator<std::pair<std::string_const,std::string>>>
      ::_M_erase((unsigned char *)this);
      *(int *)(*(int *)(this + 4) + 8) = *(int *)(this + 4);
      *(undefined4 *)(*(int *)(this + 4) + 4) = 0;
      *(int *)(*(int *)(this + 4) + 0xc) = *(int *)(this + 4);
      *(undefined4 *)(this + 8) = 0;
    }
    *(undefined4 *)(this + 8) = 0;
    if (*(_Rb_tree_node **)(*(int *)(param_1 + 4) + 4) == (unsigned char *)0x0) {
      *(undefined4 *)(*(int *)(this + 4) + 4) = 0;
      *(int *)(*(int *)(this + 4) + 8) = *(int *)(this + 4);
      *(int *)(*(int *)(this + 4) + 0xc) = *(int *)(this + 4);
    }
    else {
      uVar3 = std::
              _Rb_tree<std::string,std::pair<std::string_const,std::string>,std::_Select1st<std::pair<std::string_const,std::string>>,std::less<std::string>,pool_allocator<std::pair<std::string_const,std::string>>>
              ::_M_copy((unsigned char *)this,*(_Rb_tree_node **)(*(int *)(param_1 + 4) + 4));
      *(undefined4 *)(*(int *)(this + 4) + 4) = uVar3;
      iVar2 = *(int *)(*(int *)(this + 4) + 4);
      for (iVar1 = *(int *)(iVar2 + 8); iVar1 != 0; iVar1 = *(int *)(iVar1 + 8)) {
        iVar2 = iVar1;
      }
      *(int *)(*(int *)(this + 4) + 8) = iVar2;
      iVar2 = *(int *)(*(int *)(this + 4) + 4);
      for (iVar1 = *(int *)(iVar2 + 0xc); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0xc)) {
        iVar2 = iVar1;
      }
      *(int *)(*(int *)(this + 4) + 0xc) = iVar2;
      *(undefined4 *)(this + 8) = *(undefined4 *)(param_1 + 8);
    }
  }
  return this;
}

/* std___Rb_tree_std__string_std__pair_std__string_const_std__string__std___Select1st_std__pair_std__string_const_std__string___std__less_std__string__pool_allocator_std__pair_std__string_const_std__string______M_copy @ 0x97c31b2c (280 bytes) */
undefined4 * 
std::
_Rb_tree<std::string,std::pair<std::string_const,std::string>,std::_Select1st<std::pair<std::string_const,std::string>>,std::less<std::string>,pool_allocator<std::pair<std::string_const,std::string>>>
::_M_copy(_Rb_tree<std::string,std::pair<std::string_const,std::string>,std::_Select1st<std::pair<std::string_const,std::string>>,std::less<std::string>,pool_allocator<std::pair<std::string_const,std::string>>>
          *this,unsigned char *param_1,unsigned char *param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  _Rb_tree_node *p_Var5;
  undefined4 *puVar6;
  
  puVar3 = (undefined4 *)TPoolAllocator__allocate(*(ulong *)this);
  if ((unsigned char *)(puVar3 + 4) != (unsigned char *)0x0) {
    std__string__string((unsigned char *)(puVar3 + 4),(unsigned char *)(param_1 + 0x10));
    std__string__string((unsigned char *)(puVar3 + 6),(unsigned char *)(param_1 + 0x18));
  }
  uVar2 = *(undefined4 *)param_1;
  puVar3[3] = 0;
  p_Var5 = *(_Rb_tree_node **)(param_1 + 0xc);
  *puVar3 = uVar2;
  puVar3[1] = param_2;
  puVar3[2] = 0;
  if (p_Var5 != (unsigned char *)0x0) {
    uVar2 = std::
            _Rb_tree<std::string,std::pair<std::string_const,std::string>,std::_Select1st<std::pair<std::string_const,std::string>>,std::less<std::string>,pool_allocator<std::pair<std::string_const,std::string>>>
            ::_M_copy((unsigned char *)this,p_Var5);
    puVar3[3] = uVar2;
  }
  puVar1 = puVar3;
  for (puVar6 = *(undefined4 **)(param_1 + 8); puVar6 != (undefined4 *)0x0;
      puVar6 = (undefined4 *)puVar6[2]) {
    puVar4 = (undefined4 *)TPoolAllocator__allocate(*(ulong *)this);
    if ((unsigned char *)(puVar4 + 4) != (unsigned char *)0x0) {
      std__string__string((unsigned char *)(puVar4 + 4),(unsigned char *)(puVar6 + 4));
      std__string__string((unsigned char *)(puVar4 + 6),(unsigned char *)(puVar6 + 6));
    }
    puVar4[3] = 0;
    p_Var5 = (unsigned char *)puVar6[3];
    uVar2 = *puVar6;
    puVar4[2] = 0;
    *puVar4 = uVar2;
    puVar4[1] = puVar1;
    puVar1[2] = puVar4;
    if (p_Var5 != (unsigned char *)0x0) {
      uVar2 = std::
              _Rb_tree<std::string,std::pair<std::string_const,std::string>,std::_Select1st<std::pair<std::string_const,std::string>>,std::less<std::string>,pool_allocator<std::pair<std::string_const,std::string>>>
              ::_M_copy((unsigned char *)this,p_Var5);
      puVar4[3] = uVar2;
    }
    puVar1 = puVar4;
  }
  return puVar3;
}

/* TType__setStructSize @ 0x97c31c44 (284 bytes) */
int TType__setStructSize(this, param_1)
  unsigned char *this;
  unsigned char *param_1;
{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  iVar2 = 0;
  piVar3 = *(int **)(param_1 + 4);
  do {
    if (piVar3 == *(int **)(param_1 + 8)) {
      *(int *)(this + 0x18) = iVar2;
      return iVar2;
    }
    iVar1 = (**(code **)(*(int *)*piVar3 + 0x38))();
    if (iVar1 == 0) {
      iVar1 = (**(code **)(*(int *)*piVar3 + 0x34))();
      if ((iVar1 != 0) || (iVar1 = (**(code **)(*(int *)*piVar3 + 0x3c))(), iVar1 != 0)) {
        iVar1 = (**(code **)(*(int *)*piVar3 + 0x30))();
        goto LAB_97c31d28;
      }
      if (*(int *)(*piVar3 + 8) != 0) {
        iVar1 = ((int (*)())TType__setStructSize)((unsigned char *)this);
        goto LAB_97c31d28;
      }
      iVar2 = iVar2 + 1;
    }
    else {
      if (((int *)*piVar3)[2] == 0) {
        iVar1 = (**(code **)(*(int *)*piVar3 + 0x30))();
      }
      else {
        iVar1 = ((int (*)())TType__setStructSize)((unsigned char *)this);
      }
      iVar1 = iVar1 * *(int *)(*piVar3 + 4);
LAB_97c31d28:
      iVar2 = iVar2 + iVar1;
    }
    piVar3 = piVar3 + 2;
  } while( true );
}

/* TIntermNode__getLine @ 0x97c31d60 (8 bytes) */
int TIntermNode__getLine(this)
  unsigned char *this;
{
  return *(undefined4 *)(this + 4);
}

/* TIntermNode__setLine @ 0x97c31d68 (8 bytes) */
int TIntermNode__setLine(this, param_1)
  unsigned char *this;
  int param_1;
{
  *(int *)(this + 4) = param_1;
  return;
}

/* TIntermNode__getAsConstantUnion @ 0x97c31d70 (8 bytes) */
int TIntermNode__getAsConstantUnion()
{
  return 0;
}

/* TIntermNode__getAsAggregate @ 0x97c31d78 (8 bytes) */
int TIntermNode__getAsAggregate()
{
  return 0;
}

/* TIntermNode__getAsBinaryNode @ 0x97c31d80 (8 bytes) */
int TIntermNode__getAsBinaryNode()
{
  return 0;
}

/* TIntermNode__getAsSelectionNode @ 0x97c31d88 (8 bytes) */
int TIntermNode__getAsSelectionNode()
{
  return 0;
}

