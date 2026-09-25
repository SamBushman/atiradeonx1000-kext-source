#include "decls.h"

/* __Unwind_FindEnclosingFunction @ 0x97c1a5e4 (56 bytes) */
int __Unwind_FindEnclosingFunction(pc)
  void *pc;
{
  void *pvVar1;
  void *pvVar2;
  dwarf_eh_bases adStack_20 [2];
  
  pvVar1 = ((int (*)())__Unwind_Find_FDE)((void *)((int)pc + -1),adStack_20);
  pvVar2 = (void *)0x0;
  if (pvVar1 != (void *)0x0) {
    pvVar2 = (void *)adStack_20[0].func;
  }
  return pvVar2;
}

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
  byte bVar4;
  int iVar5;
  undefined4 uVar6;
  undefined1 *puVar7;
  byte *pbVar8;
  char *pcVar9;
  byte *pbVar10;
  char *pcVar11;
  int local_30 [5];
  
  pcVar11 = (char *)(param_1 + 9);
  iVar5 = _strlen(pcVar11);
  pcVar9 = pcVar11 + iVar5 + 1;
  pbVar8 = (byte *)0x0;
  if ((*(char *)(param_1 + 9) == 'e') && (*(char *)(param_1 + 10) == 'h')) {
    pcVar1 = pcVar11 + iVar5 + 1;
    pcVar9 = pcVar11 + iVar5 + 5;
    pcVar11 = (char *)(param_1 + 0xb);
    *(undefined4 *)(param_3 + 0x3a0) = *(undefined4 *)pcVar1;
  }
  uVar6 = _read_uleb128_97c1a3ec(pcVar9,param_3 + 0x398);
  puVar7 = (undefined1 *)_read_sleb128_97c1a41c(uVar6,param_3 + 0x394);
  uVar2 = *puVar7;
  pbVar10 = puVar7 + 1;
  *(undefined1 *)(param_3 + 0x39e) = 0xff;
  *(undefined1 *)(param_3 + 0x39c) = uVar2;
  cVar3 = *pcVar11;
  if (cVar3 == 'z') {
    pbVar10 = (byte *)_read_uleb128_97c1a3ec(pbVar10,local_30);
    *(undefined1 *)(param_3 + 0x39f) = 1;
    pcVar11 = pcVar11 + 1;
    cVar3 = *pcVar11;
    pbVar8 = pbVar10 + local_30[0];
  }
  do {
    if (cVar3 == '\0') {
      if (pbVar8 == (byte *)0x0) {
        pbVar8 = pbVar10;
      }
      return pbVar8;
    }
    if (cVar3 == 'L') {
      *(byte *)(param_3 + 0x39e) = *pbVar10;
LAB_97c1a718:
      pbVar10 = pbVar10 + 1;
    }
    else {
      if (cVar3 == 'R') {
        *(byte *)(param_3 + 0x39d) = *pbVar10;
        goto LAB_97c1a718;
      }
      if (cVar3 != 'P') {
        return pbVar8;
      }
      bVar4 = *pbVar10;
      uVar6 = _base_of_encoded_value((uint)bVar4,param_2);
      pbVar10 = (byte *)_read_encoded_value_with_base_97c1a468
                                  ((uint)bVar4,uVar6,pbVar10 + 1,param_3 + 0x390);
    }
    pcVar11 = pcVar11 + 1;
    cVar3 = *pcVar11;
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
          puVar7 = (ushort *)_read_uleb128_97c1a3ec(puVar7,local_30);
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
      puVar7 = (ushort *)_read_uleb128_97c1a3ec(puVar7,&local_40);
      goto LAB_97c1ae98;
    case 0x11:
      puVar7 = (ushort *)_read_sleb128_97c1a41c(puVar7,&local_3c);
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
      puVar7 = (ushort *)_read_sleb128_97c1a41c(puVar7,&local_34);
      iVar4 = uVar10 - 0x70;
      goto LAB_97c1ab30;
    case 0x90:
      puVar7 = (ushort *)_read_uleb128_97c1a3ec(puVar7,&local_38);
      iVar4 = local_38;
LAB_97c1aaf4:
      local_40 = (uint *)**(uint **)(param_3 + iVar4 * 4);
      goto LAB_97c1aba8;
    case 0x92:
      uVar5 = _read_uleb128_97c1a3ec(puVar7,&local_38);
      puVar7 = (ushort *)_read_sleb128_97c1a41c(uVar5,&local_34);
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
  int param_4;
{
  byte bVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  byte bVar5;
  undefined4 uVar6;
  uint *puVar7;
  uint uVar8;
  int iVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  uint *puVar12;
  undefined4 *puVar13;
  int local_30;
  uint local_2c;
  undefined4 local_28;
  int local_24;
  
  puVar4 = (undefined4 *)&STACKARG(0xffffff90);
  puVar10 = (undefined4 *)0x0;
  *(undefined4 *)(param_4 + 0x378) = 0;
  if ((param_1 < param_2) &&
     (uVar8 = *(uint *)(param_4 + 0x38c), uVar8 < *(uint *)(param_3 + 0x1c0))) {
    do {
      bVar1 = *(byte *)param_1;
      puVar12 = (uint *)((int)param_1 + 1);
      bVar5 = bVar1 & 0xc0;
      if (bVar5 == 0x40) {
        iVar2 = (bVar1 & 0x3f) * *(int *)(param_4 + 0x398);
        goto LAB_97c1b0dc;
      }
      if (bVar5 == 0x80) {
        local_2c = bVar1 & 0x3f;
LAB_97c1b0f4:
        puVar12 = (uint *)_read_uleb128_97c1a3ec(puVar12,&local_30);
        iVar9 = *(int *)(param_4 + 0x394);
        iVar2 = local_30;
LAB_97c1b10c:
        *(undefined4 *)(local_2c * 8 + param_4 + 4) = 1;
        iVar2 = iVar2 * iVar9;
LAB_97c1b3a0:
        *(int *)(param_4 + local_2c * 8) = iVar2;
        goto switchD_97c1afc0_caseD_0;
      }
      if (bVar5 == 0xc0) {
        *(undefined4 *)((bVar1 & 0x3f) * 8 + param_4 + 4) = 0;
        local_2c = bVar1 & 0x3f;
        goto switchD_97c1afc0_caseD_0;
      }
      switch(bVar1) {
      case 0:
        break;
      case 1:
        bVar1 = *(byte *)(param_4 + 0x39d);
        uVar6 = _base_of_encoded_value((uint)bVar1,param_3);
        puVar12 = (uint *)_read_encoded_value_with_base_97c1a468
                                    ((uint)bVar1,uVar6,puVar12,param_4 + 0x38c);
        break;
      case 2:
        uVar3 = (uint)*(byte *)puVar12;
        puVar12 = (uint *)((int)param_1 + 2);
        goto LAB_97c1b0c0;
      case 3:
        uVar3 = (uint)*(ushort *)puVar12;
        puVar12 = (uint *)((int)param_1 + 3);
LAB_97c1b0c0:
        iVar2 = *(int *)(param_4 + 0x398);
LAB_97c1b0d4:
        iVar2 = uVar3 * iVar2;
LAB_97c1b0dc:
        *(uint *)(param_4 + 0x38c) = uVar8 + iVar2;
        break;
      case 4:
        iVar2 = *(int *)(param_4 + 0x398);
        uVar3 = *puVar12;
        puVar12 = (uint *)((int)param_1 + 5);
        goto LAB_97c1b0d4;
      case 5:
        puVar12 = (uint *)_read_uleb128_97c1a3ec(puVar12,&local_2c);
        goto LAB_97c1b0f4;
      case 6:
        puVar12 = (uint *)_read_uleb128_97c1a3ec(puVar12,&local_2c);
        *(undefined4 *)(local_2c * 8 + param_4 + 4) = 0;
        break;
      case 7:
      case 8:
        puVar7 = &local_2c;
        goto LAB_97c1b358;
      case 9:
        uVar6 = _read_uleb128_97c1a3ec(puVar12,&local_2c);
        puVar12 = (uint *)_read_uleb128_97c1a3ec(uVar6,&local_28);
        *(undefined4 *)(local_2c * 8 + param_4 + 4) = 2;
        *(undefined4 *)(param_4 + local_2c * 8) = local_28;
        break;
      case 10:
        if (puVar10 == (undefined4 *)0x0) {
          puVar13 = puVar4 + -0xe4;
          *puVar13 = *puVar4;
          puVar4 = puVar4 + -0xd4;
          puVar11 = puVar10;
        }
        else {
          puVar13 = puVar4;
          puVar11 = (undefined4 *)puVar10[0xde];
          puVar4 = puVar10;
        }
        _memcpy(puVar4,param_4,0x37c);
        *(undefined4 **)(param_4 + 0x378) = puVar4;
        puVar4 = puVar13;
        puVar10 = puVar11;
        break;
      case 0xb:
        puVar13 = *(undefined4 **)(param_4 + 0x378);
        _memcpy(param_4,puVar13,0x37c);
        puVar13[0xde] = puVar10;
        puVar10 = puVar13;
        break;
      case 0xc:
        uVar6 = _read_uleb128_97c1a3ec(puVar12,param_4 + 0x380);
        puVar12 = (uint *)_read_uleb128_97c1a3ec(uVar6,&local_30);
        *(int *)(param_4 + 0x37c) = local_30;
        *(undefined4 *)(param_4 + 0x388) = 1;
        break;
      case 0xd:
        puVar12 = (uint *)_read_uleb128_97c1a3ec(puVar12,param_4 + 0x380);
        goto LAB_97c1b2e8;
      case 0xe:
        puVar12 = (uint *)_read_uleb128_97c1a3ec(puVar12,&local_30);
        *(int *)(param_4 + 0x37c) = local_30;
        break;
      case 0xf:
        iVar2 = _read_uleb128_97c1a3ec(puVar12,&local_30);
        *(int *)(param_4 + 900) = iVar2;
        *(undefined4 *)(param_4 + 0x388) = 2;
        puVar12 = (uint *)(iVar2 + local_30);
        break;
      case 0x10:
        uVar6 = _read_uleb128_97c1a3ec(puVar12,&local_2c);
        iVar2 = _read_uleb128_97c1a3ec(uVar6,&local_30);
        *(undefined4 *)(local_2c * 8 + param_4 + 4) = 3;
        *(int *)(param_4 + local_2c * 8) = iVar2;
        puVar12 = (uint *)(iVar2 + local_30);
        break;
      case 0x11:
        uVar6 = _read_uleb128_97c1a3ec(puVar12,&local_2c);
        puVar12 = (uint *)_read_sleb128_97c1a41c(uVar6,&local_24);
        iVar9 = *(int *)(param_4 + 0x394);
        iVar2 = local_24;
        goto LAB_97c1b10c;
      case 0x12:
        uVar6 = _read_uleb128_97c1a3ec(puVar12,param_4 + 0x380);
        puVar12 = (uint *)_read_sleb128_97c1a41c(uVar6,param_4 + 0x37c);
LAB_97c1b2e8:
        *(undefined4 *)(param_4 + 0x388) = 1;
        break;
      case 0x13:
        puVar12 = (uint *)_read_sleb128_97c1a41c(puVar12,param_4 + 0x37c);
        break;
      default:
                    
        _abort();
      case 0x2d:
        local_2c = 0x10;
        do {
          *(undefined4 *)(local_2c * 8 + param_4 + 4) = 1;
          uVar8 = local_2c + 1;
          *(uint *)(local_2c * 8 + param_4) = local_2c * 4 + -0x40;
          local_2c = uVar8;
        } while (uVar8 < 0x20);
        break;
      case 0x2e:
        puVar7 = (uint *)(param_3 + 0x1d4);
LAB_97c1b358:
        puVar12 = (uint *)_read_uleb128_97c1a3ec(puVar12,puVar7);
        break;
      case 0x2f:
        uVar6 = _read_uleb128_97c1a3ec(puVar12,&local_2c);
        puVar12 = (uint *)_read_uleb128_97c1a3ec(uVar6,&local_30);
        iVar2 = *(int *)(param_4 + 0x394);
        *(undefined4 *)(local_2c * 8 + param_4 + 4) = 1;
        iVar2 = -(local_30 * iVar2);
        goto LAB_97c1b3a0;
      }
switchD_97c1afc0_caseD_0: ;
    } while ((puVar12 < param_2) &&
            (uVar8 = *(uint *)(param_4 + 0x38c), param_1 = puVar12,
            uVar8 < *(uint *)(param_3 + 0x1c0)));
  }
  return;
}

/* _uw_frame_state_for @ 0x97c1b3e4 (328 bytes) */
int _uw_frame_state_for(param_1, param_2)
  int param_1;
  int param_2;
{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int local_30 [5];
  
  _memset(param_2,0,0x3a4);
  *(undefined4 *)(param_1 + 0x1c4) = 0;
  *(undefined4 *)(param_1 + 0x1d4) = 0;
  piVar3 = ((int (*)())__Unwind_Find_FDE)((void *)(*(int *)(param_1 + 0x1c0) + -1),
                             (dwarf_eh_bases *)(param_1 + 0x1c8));
  uVar1 = 5;
  if (piVar3 != (int *)0x0) {
    *(undefined4 *)(param_2 + 0x38c) = *(undefined4 *)(param_1 + 0x1d0);
    iVar2 = piVar3[1];
    iVar6 = (int)piVar3 + (4 - iVar2);
    iVar4 = ((int (*)())_extract_cie_info)(iVar6,param_1,param_2);
    uVar1 = 3;
    if (iVar4 != 0) {
      iVar5 = 0;
      ((int (*)())_execute_cfa_program)(iVar4,iVar6 + *(int *)((int)piVar3 + (4 - iVar2)) + 4,param_1,param_2);
      iVar2 = _size_of_encoded_value_97c1a2c8((uint)*(byte *)(param_2 + 0x39d));
      iVar2 = (int)piVar3 + iVar2 * 2 + 8;
      if (*(char *)(param_2 + 0x39f) != '\0') {
        iVar2 = _read_uleb128_97c1a3ec(iVar2,local_30);
        iVar5 = iVar2 + local_30[0];
      }
      uVar7 = (uint)*(byte *)(param_2 + 0x39e);
      if (uVar7 != 0xff) {
        uVar1 = _base_of_encoded_value(uVar7,param_1);
        iVar2 = _read_encoded_value_with_base_97c1a468(uVar7,uVar1,iVar2,param_1 + 0x1c4);
      }
      if (iVar5 == 0) {
        iVar5 = iVar2;
      }
      ((int (*)())_execute_cfa_program)(iVar5,(int)piVar3 + *piVar3 + 4,param_1,param_2);
      uVar1 = 0;
    }
  }
  return uVar1;
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
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int aiStack_210 [120];
  int local_30;
  int local_2c [5];
  
  _memcpy(aiStack_210,param_1,0x1d8);
  if (param_2[0xe2] == 1) {
    piVar2 = (int *)param_1[param_2[0xe0]];
    if (piVar2 == (int *)0x0) {
      iVar1 = param_1[0x6f];
    }
    else {
      iVar1 = *piVar2;
    }
    piVar3 = (int *)(iVar1 + param_2[0xdf]);
  }
  else {
    if (param_2[0xe2] != 2) {
                    
      _abort();
    }
    iVar1 = _read_uleb128_97c1a3ec(param_2[0xe1],&local_30);
    piVar2 = (int *)((int (*)())_execute_stack_op)(iVar1,iVar1 + local_30,param_1,0);
    piVar3 = piVar2;
  }
  param_1[0x6f] = (int)piVar3;
  piVar4 = param_1 + 0x6e;
  do {
    iVar1 = param_2[1];
    if (iVar1 == 1) {
      *param_1 = (int)piVar3 + *param_2;
    }
    else if (iVar1 != 0) {
      if (iVar1 == 2) {
        *param_1 = aiStack_210[*param_2];
      }
      else if (iVar1 == 3) {
        iVar1 = _read_uleb128_97c1a3ec(*param_2,local_2c);
        piVar2 = (int *)((int (*)())_execute_stack_op)(iVar1,iVar1 + local_2c[0],aiStack_210,piVar3);
        *param_1 = (int)piVar2;
      }
    }
    param_1 = param_1 + 1;
    param_2 = param_2 + 2;
  } while ((int)param_1 <= (int)piVar4);
  return piVar2;
}

/* _uw_update_context @ 0x97c1b758 (68 bytes) */
int _uw_update_context(param_1, param_2)
  int param_1;
  int param_2;
{
  ((int (*)())_uw_update_context_1)(param_1,param_2);
  *(undefined4 *)(param_1 + 0x1c0) =
       **(undefined4 **)(param_1 + (uint)*(byte *)(param_2 + 0x39c) * 4);
  return;
}

/* _uw_init_context_1 @ 0x97c1b79c (132 bytes) */
int _uw_init_context_1(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined4 in_LR;
  undefined1 auStack_3d0 [892];
  int local_54;
  int local_50;
  undefined4 local_48;
  
  _memset(param_1,0,0x1d8);
  *(undefined4 *)(param_1 + 0x1c0) = in_LR;
  local_54 = ((int (*)())_uw_frame_state_for)(param_1,auStack_3d0);
  if (local_54 != 0) {
                    
    _abort();
  }
  *(undefined4 *)(param_1 + 0x1bc) = param_2;
  local_48 = 1;
  local_50 = local_54;
  ((int (*)())_uw_update_context_1)(param_1,auStack_3d0);
  *(undefined4 *)(param_1 + 0x1c0) = param_3;
  return;
}

/* _uw_install_context_1 @ 0x97c1b820 (652 bytes) */
int _uw_install_context_1(param_1, param_2)
  int param_1;
  int param_2;
{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
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
    iVar4 = *(int *)(iVar2 + param_2);
    iVar3 = *(int *)(iVar2 + param_1);
    if (((iVar4 != 0) && (iVar3 != 0)) && (iVar4 != iVar3)) {
      _memcpy(iVar3,iVar4,(uint)*pbVar1);
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
        ((iVar4 = (*local_30)(1,uVar1 << 2 | 2,*param_1,param_1[1],param_1,param_2,2), iVar4 == 7 ||
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
  _Unwind_Exception *exception_object;
{
  double this_context[0x1d8 / 8], cur_context[0x1d8 / 8];
  double fs[0x3d0 / 8];
  long offset;
  int code;
  __builtin_unwind_init();
  ((int (*)())_uw_init_context_1)(this_context, __builtin_dwarf_cfa(), __builtin_return_address(0));
  _memcpy(cur_context, this_context, 0x1d8);
  while (1) {
    void *pers;
    code = ((int (*)())_uw_frame_state_for)(cur_context, fs);
    if (code == 5) return 5;
    if (code != 0) return 3;
    pers = *(void **)((char *)fs + 0x390);
    if (pers != 0) {
      code = ((int (*)(int, int, unsigned long long, void *, void *))pers)(1, 1, exception_object->exception_class, exception_object, cur_context);
      if (code == 6) break;
      if (code != 8) return 3;
    }
    ((int (*)())_uw_update_context)(cur_context, fs);
  }
  exception_object->private_1 = 0;
  exception_object->private_2 = *(unsigned long *)((char *)cur_context + 0x1c0);
  _memcpy(cur_context, this_context, 0x1d8);
  code = ((int (*)())__Unwind_RaiseException_Phase2)(exception_object, cur_context);
  if (code != 7) return code;
  offset = ((int (*)())_uw_install_context_1)(this_context, cur_context);
  __builtin_eh_return(offset, __builtin_frob_return_addr(*(void **)((char *)cur_context + 0x1c0)));
}

/* __Unwind_ForcedUnwind_Phase2 @ 0x97c1bc88 (260 bytes) */
int __Unwind_ForcedUnwind_Phase2(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  int iVar1;
  int iVar2;
  undefined4 a1;
  code *pcVar3;
  undefined4 a6;
  undefined1 auStack_3d0 [912];
  code *local_40;
  
  pcVar3 = (code *)param_1[3];
  a6 = param_1[4];
  while( true ) {
    iVar1 = ((int (*)())_uw_frame_state_for)(param_2,auStack_3d0);
    if ((iVar1 != 0) && (iVar1 != 5)) {
      return 2;
    }
    a1 = 10;
    if (iVar1 == 5) {
      a1 = 0x1a;
    }
    iVar2 = (*pcVar3)(1,a1,*param_1,param_1[1],param_1,param_2,a6);
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
int __Unwind_ForcedUnwind(exception_object, stop, stop_parameter, param_4, param_5, param_6, param_7)
  _Unwind_Exception *exception_object;
  void *stop;
  void *stop_parameter;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  double this_context[0x1d8 / 8], cur_context[0x1d8 / 8];
  double fs[0x3d0 / 8];
  long offset;
  int code;
  __builtin_unwind_init();
  ((int (*)())_uw_init_context_1)(this_context, __builtin_dwarf_cfa(), __builtin_return_address(0));
  _memcpy(cur_context, this_context, 0x1d8);
  exception_object->private_1 = (unsigned long)stop;
  exception_object->private_2 = (unsigned long)stop_parameter;
  code = ((int (*)())__Unwind_ForcedUnwind_Phase2)(exception_object, cur_context);
  if (code != 7) return code;
  offset = ((int (*)())_uw_install_context_1)(this_context, cur_context);
  __builtin_eh_return(offset, __builtin_frob_return_addr(*(void **)((char *)cur_context + 0x1c0)));
}

/* __Unwind_Resume @ 0x97c1be20 (152 bytes) */
int __Unwind_Resume(exception_object)
  _Unwind_Exception *exception_object;
{
  double this_context[0x1d8 / 8], cur_context[0x1d8 / 8];
  double fs[0x3d0 / 8];
  long offset;
  int code;
  __builtin_unwind_init();
  ((int (*)())_uw_init_context_1)(this_context, __builtin_dwarf_cfa(), __builtin_return_address(0));
  _memcpy(cur_context, this_context, 0x1d8);
  if (exception_object->private_1 == 0)
    code = ((int (*)())__Unwind_RaiseException_Phase2)(exception_object, cur_context);
  else
    code = ((int (*)())__Unwind_ForcedUnwind_Phase2)(exception_object, cur_context);
  if (code != 7) _abort();
  offset = ((int (*)())_uw_install_context_1)(this_context, cur_context);
  __builtin_eh_return(offset, __builtin_frob_return_addr(*(void **)((char *)cur_context + 0x1c0)));
}

/* __Unwind_DeleteException @ 0x97c1beb8 (20 bytes) */
int __Unwind_DeleteException(exception_object)
  _Unwind_Exception *exception_object;
{
                    
                    
  (*exception_object->exception_cleanup)(1,exception_object);
  return;
}

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
  uint uVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if (param_1 != 0xff) {
    uVar1 = param_1 & 7;
    uVar2 = 2;
    if (uVar1 != 2) {
      if (uVar1 < 3) {
        if (uVar1 != 0) {
LAB_97c1c404:
                    
          _abort();
        }
        uVar2 = 4;
      }
      else {
        uVar2 = 4;
        if (uVar1 != 3) {
          if (uVar1 != 4) goto LAB_97c1c404;
          uVar2 = 8;
        }
      }
    }
  }
  return uVar2;
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
  return param_1;
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
  return param_1;
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
    puVar1 = (uint *)((int (*)())_read_uleb128_97c1c41c)(param_3,&local_30);
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
    puVar1 = (uint *)((int (*)())_read_sleb128_97c1c44c)(param_3,local_2c);
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
    ob = (void *)_malloc(0x1c);
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
int ___register_frame_table(fde, param_2)
  void *fde;
  undefined4 param_2;
{
  void *ob;
  
  ob = (void *)_malloc(0x1c);
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
        _free(*(undefined4 *)((int)pvVar1 + 0xc));
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
  undefined4 extraout_r3;
  
  if (*(int *)fde != 0) {
    pvVar1 = ___deregister_frame_info(fde);
    _free(pvVar1);
    return extraout_r3;
  }
  return fde;
}

/* _base_from_object @ 0x97c1c884 (120 bytes) */
int _base_from_object(param_1, param_2)
  uint param_1;
  int param_2;
{
  bool bVar1;
  uint uVar2;
  
  if (param_1 == 0xff) {
    return 0;
  }
  uVar2 = param_1 & 0x70;
  if (uVar2 == 0x20) {
    return *(undefined4 *)(param_2 + 4);
  }
  if (uVar2 < 0x21) {
    if (uVar2 == 0) {
      return 0;
    }
    bVar1 = uVar2 == 0x10;
  }
  else {
    if (uVar2 == 0x30) {
      return *(undefined4 *)(param_2 + 8);
    }
    bVar1 = uVar2 == 0x50;
  }
  if (bVar1) {
    return 0;
  }
                    
  _abort();
}

/* _get_cie_encoding @ 0x97c1c8fc (200 bytes) */
int _get_cie_encoding(param_1)
  int param_1;
{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  byte *pbVar4;
  byte bVar5;
  char *pcVar6;
  undefined1 auStack_20 [4];
  undefined1 auStack_1c [4];
  undefined1 auStack_18 [12];
  
  bVar5 = 0;
  if (*(char *)(param_1 + 9) == 'z') {
    iVar2 = _strlen(param_1 + 9);
    uVar3 = ((int (*)())_read_uleb128_97c1c41c)(param_1 + 9 + iVar2 + 1,auStack_20);
    iVar2 = ((int (*)())_read_sleb128_97c1c44c)(uVar3,auStack_1c);
    pbVar4 = (byte *)((int (*)())_read_uleb128_97c1c41c)(iVar2 + 1,auStack_20);
    for (pcVar6 = (char *)(param_1 + 10); cVar1 = *pcVar6, cVar1 != 'R'; pcVar6 = pcVar6 + 1) {
      if (cVar1 == 'P') {
        pbVar4 = (byte *)((int (*)())_read_encoded_value_with_base_97c1c498)(*pbVar4 & 0x7f,0,pbVar4 + 1,auStack_18);
      }
      else {
        pbVar4 = pbVar4 + 1;
        if (cVar1 != 'L') {
          return 0;
        }
      }
    }
    bVar5 = *pbVar4;
  }
  return bVar5;
}

/* _fde_unencoded_compare @ 0x97c1c9c4 (40 bytes) */
int _fde_unencoded_compare(param_1, param_2, param_3)
  undefined4 param_1;
  int param_2;
  int param_3;
{
  if (*(uint *)(param_3 + 8) < *(uint *)(param_2 + 8)) {
    return 1;
  }
  if (*(uint *)(param_2 + 8) < *(uint *)(param_3 + 8)) {
    return 0xffffffff;
  }
  return 0;
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
  
  uVar1 = ((int (*)())_base_from_object)(*(uint *)(param_1 + 0x10) >> 0x15 & 0xff,param_1);
  ((int (*)())_read_encoded_value_with_base_97c1c498)(*(uint *)(param_1 + 0x10) >> 0x15 & 0xff,uVar1,param_2 + 8,&local_30);
  ((int (*)())_read_encoded_value_with_base_97c1c498)(*(uint *)(param_1 + 0x10) >> 0x15 & 0xff,uVar1,param_3 + 8,local_2c);
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
  uint uVar1;
  undefined4 uVar2;
  uint local_30;
  uint local_2c [5];
  
  uVar1 = ((int (*)())_get_cie_encoding)((param_2 - *(int *)(param_2 + 4)) + 4);
  uVar2 = ((int (*)())_base_from_object)(uVar1 & 0xff,param_1);
  ((int (*)())_read_encoded_value_with_base_97c1c498)(uVar1 & 0xff,uVar2,param_2 + 8,&local_30);
  uVar1 = ((int (*)())_get_cie_encoding)((param_3 - *(int *)(param_3 + 4)) + 4);
  uVar2 = ((int (*)())_base_from_object)(uVar1 & 0xff,param_1);
  ((int (*)())_read_encoded_value_with_base_97c1c498)(uVar1 & 0xff,uVar2,param_3 + 8,local_2c);
  uVar2 = 1;
  if (local_30 <= local_2c[0]) {
    if (local_30 < local_2c[0]) {
      uVar2 = 0xffffffff;
    }
    else {
      uVar2 = 0;
    }
  }
  return uVar2;
}

/* _frame_heapsort @ 0x97c1cb40 (568 bytes) */
int _frame_heapsort(param_1, param_2, param_3)
  undefined4 param_1;
  code *param_2;
  int param_3;
{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  uint uVar5;
  uint uVar6;
  int iVar7;
  undefined4 *puVar8;
  int iVar9;
  uint uVar10;
  
  uVar6 = *(uint *)(param_3 + 4);
  puVar8 = (undefined4 *)(param_3 + 8);
  uVar10 = uVar6;
joined_r0x97c1cb68:
  if (uVar10 == 0) {
    do {
      do {
        if (uVar6 < 2) {
          return;
        }
        uVar6 = uVar6 - 1;
        uVar1 = *puVar8;
        *puVar8 = puVar8[uVar6];
        puVar8[uVar6] = uVar1;
      } while (uVar6 < 2);
      iVar7 = 0;
      uVar10 = 0;
      do {
        uVar5 = iVar7 + 2;
        if (uVar5 < uVar6) {
          iVar9 = uVar10 * 8;
          iVar3 = (*param_2)(param_1,puVar8[uVar10 * 2 + 2],puVar8[uVar10 * 2 + 1],in_r6,in_r7,in_r8
                             ,uVar1);
          if (iVar3 < 1) {
            iVar3 = uVar10 << 2;
            goto LAB_97c1cd10;
          }
          iVar3 = uVar10 * 4;
          iVar4 = (*param_2)(param_1,puVar8[uVar10 * 2 + 2],puVar8[uVar10]);
          if (iVar4 < 1) goto LAB_97c1cd10;
          uVar2 = puVar8[uVar10];
          puVar8[uVar10] = puVar8[uVar10 * 2 + 2];
          puVar8[uVar10 * 2 + 2] = uVar2;
        }
        else {
          iVar3 = uVar10 << 2;
          iVar9 = uVar10 << 3;
LAB_97c1cd10:
          iVar4 = (*param_2)(param_1,*(undefined4 *)((int)puVar8 + iVar9 + 4),
                             *(undefined4 *)(iVar3 + (int)puVar8));
          if (iVar4 < 1) break;
          uVar2 = *(undefined4 *)(iVar3 + (int)puVar8);
          uVar5 = iVar7 + 1;
          *(undefined4 *)(iVar3 + (int)puVar8) = *(undefined4 *)((int)puVar8 + iVar9 + 4);
          *(undefined4 *)((int)puVar8 + iVar9 + 4) = uVar2;
        }
        iVar7 = uVar5 * 2;
        uVar10 = uVar5;
      } while (iVar7 + 1U < uVar6);
    } while( true );
  }
  uVar10 = uVar10 - 1;
  uVar5 = uVar10;
joined_r0x97c1cb84:
  do {
    iVar7 = uVar5 * 2;
    if (uVar6 <= iVar7 + 1U) goto joined_r0x97c1cb68;
    if (iVar7 + 2U < uVar6) {
      iVar9 = uVar5 * 8;
      iVar3 = (*param_2)(param_1,puVar8[uVar5 * 2 + 2],puVar8[uVar5 * 2 + 1]);
      if (iVar3 < 1) {
        iVar3 = uVar5 << 2;
      }
      else {
        iVar3 = uVar5 * 4;
        iVar4 = (*param_2)(param_1,puVar8[uVar5 * 2 + 2],puVar8[uVar5]);
        if (0 < iVar4) {
          uVar1 = puVar8[uVar5];
          puVar8[uVar5] = puVar8[uVar5 * 2 + 2];
          puVar8[uVar5 * 2 + 2] = uVar1;
          uVar5 = iVar7 + 2U;
          goto joined_r0x97c1cb84;
        }
      }
    }
    else {
      iVar3 = uVar5 << 2;
      iVar9 = uVar5 << 3;
    }
    iVar4 = (*param_2)(param_1,*(undefined4 *)((int)puVar8 + iVar9 + 4),
                       *(undefined4 *)(iVar3 + (int)puVar8));
    if (iVar4 < 1) goto joined_r0x97c1cb68;
    uVar1 = *(undefined4 *)(iVar3 + (int)puVar8);
    uVar5 = iVar7 + 1;
    *(undefined4 *)(iVar3 + (int)puVar8) = *(undefined4 *)((int)puVar8 + iVar9 + 4);
    *(undefined4 *)((int)puVar8 + iVar9 + 4) = uVar1;
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
        uVar6 = ((int (*)())_base_from_object)(uVar4,param_1);
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
      ((int (*)())_read_encoded_value_with_base_97c1c498)(uVar4,uVar6,param_2 + 2,local_40);
      uVar4 = ((int (*)())_size_of_encoded_value_97c1c3a4)(uVar4);
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
  uVar4 = ((int (*)())_base_from_object)(uVar8,param_1);
  piVar6 = *(int **)(param_1 + 0x14);
  uVar5 = uVar8;
  for (; (param_3 != piVar6 && (*param_3 != 0)); param_3 = (int *)((int)param_3 + *param_3 + 4)) {
    if (param_3[1] != 0) {
      if (((*(uint *)(param_1 + 0x10) & 0x20000000) != 0) &&
         (iVar2 = (int)param_3 + (4 - param_3[1]), iVar2 != iVar7)) {
        uVar5 = ((int (*)())_get_cie_encoding)(iVar2);
        uVar8 = uVar5 & 0xff;
        uVar4 = ((int (*)())_base_from_object)(uVar8,param_1);
        iVar7 = iVar2;
      }
      if (uVar5 == 0) {
        uVar1 = param_3[2];
      }
      else {
        ((int (*)())_read_encoded_value_with_base_97c1c498)(uVar8,uVar4,param_3 + 2,local_40);
        uVar1 = ((int (*)())_size_of_encoded_value_97c1c3a4)(uVar8);
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
  uVar2 = ((int (*)())_base_from_object)(uVar8,param_1);
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
        uVar2 = ((int (*)())_base_from_object)(uVar8,param_1);
        iVar7 = iVar1;
      }
      if (uVar3 == 0) {
        local_40 = param_2[2];
        local_3c[0] = param_2[3];
        uVar5 = local_40;
      }
      else {
        uVar4 = ((int (*)())_read_encoded_value_with_base_97c1c498)(uVar8,uVar2,param_2 + 2,&local_40);
        ((int (*)())_read_encoded_value_with_base_97c1c498)(uVar3 & 0xf,0,uVar4,local_3c);
        uVar5 = ((int (*)())_size_of_encoded_value_97c1c3a4)(uVar8);
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
  uint uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int *piVar9;
  int iVar10;
  uint local_40;
  int local_3c;
  uint local_38;
  int local_34 [3];
  
  uVar1 = param_1[4];
  if (-1 < (int)uVar1) {
    ((int (*)())_init_object)(param_1);
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
            iVar10 = *(int *)(uVar7 * 4 + param_1[3] + 8);
            if ((*(uint *)(iVar10 + 8) <= param_2) &&
               (uVar5 = uVar7 + 1, uVar7 = uVar1,
               param_2 < *(uint *)(iVar10 + 8) + *(int *)(iVar10 + 0xc))) {
              return iVar10;
            }
            uVar1 = uVar7;
          } while (uVar5 < uVar7);
        }
      }
      else {
        uVar6 = param_1[3];
        uVar3 = ((int (*)())_base_from_object)(uVar5,param_1);
        uVar7 = *(uint *)(uVar6 + 4);
        uVar2 = 0;
        if (uVar7 != 0) {
          do {
            uVar8 = uVar2 + uVar7 >> 1;
            iVar10 = *(int *)(uVar8 * 4 + uVar6 + 8);
            uVar4 = ((int (*)())_read_encoded_value_with_base_97c1c498)(uVar5,uVar3,iVar10 + 8,&local_38);
            ((int (*)())_read_encoded_value_with_base_97c1c498)(uVar1 >> 0x15 & 0xf,0,uVar4,local_34);
            if ((local_38 <= param_2) &&
               (uVar2 = uVar8 + 1, uVar8 = uVar7, param_2 < local_38 + local_34[0])) {
              return iVar10;
            }
            uVar7 = uVar8;
          } while (uVar2 < uVar8);
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
          iVar10 = *(int *)(uVar6 * 4 + uVar5 + 8);
          uVar2 = ((int (*)())_get_cie_encoding)((iVar10 - *(int *)(iVar10 + 4)) + 4);
          uVar3 = ((int (*)())_base_from_object)(uVar2 & 0xff,param_1);
          uVar3 = ((int (*)())_read_encoded_value_with_base_97c1c498)(uVar2 & 0xff,uVar3,iVar10 + 8,&local_40);
          ((int (*)())_read_encoded_value_with_base_97c1c498)(uVar2 & 0xf,0,uVar3,&local_3c);
          if ((local_40 <= param_2) &&
             (uVar7 = uVar6 + 1, uVar6 = uVar1, param_2 < local_40 + local_3c)) {
            return iVar10;
          }
          uVar1 = uVar6;
        } while (uVar7 < uVar6);
      }
    }
  }
  else {
    if ((uVar1 & 0x40000000) == 0) {
      iVar10 = ((int (*)())_linear_search_fdes)(param_1,param_1[3],param_2);
      return iVar10;
    }
    piVar9 = (int *)param_1[3];
    iVar10 = *piVar9;
    while (iVar10 != 0) {
      iVar10 = ((int (*)())_linear_search_fdes)(param_1,iVar10,param_2);
      if (iVar10 != 0) {
        return iVar10;
      }
      piVar9 = piVar9 + 1;
      iVar10 = *piVar9;
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
    uVar5 = ((int (*)())_base_from_object)(uVar4 & 0xff,puVar8);
    ((int (*)())_read_encoded_value_with_base_97c1c498)(uVar4 & 0xff,uVar5,iVar7 + 8,param_2 + 2);
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
      ((int (*)())___deregister_frame_info_bases)(*(void **)(param_1 + 0x18));
      *puVar1 = _seen_objects;
      puVar1[1] = _unseen_objects;
    }
    __keymgr_set_and_unlock_processwide_ptr(0x12e,puVar1);
    _free(*(undefined4 *)(param_1 + 0x1c));
    *(undefined4 *)(param_1 + 0x1c) = 0;
    if ((*(uint *)(param_1 + 0x14) & 2) != 0) {
      _free(*(undefined4 *)(param_1 + 0x18));
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
  dwarf_eh_bases *param_2;
{
  bool bVar1;
  undefined4 *puVar2;
  void *pvVar3;
  
  puVar2 = (undefined4 *)__keymgr_get_and_lock_processwide_ptr(0x12e);
  bVar1 = puVar2 == (undefined4 *)0x0;
  if (bVar1) {
    puVar2 = (undefined4 *)_calloc(1,0x10);
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
  pvVar3 = (void *)((int (*)())_examine_objects)(pc,param_2,(uint)bVar1);
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
  uint param_1;
{
  undefined4 *puVar1;
  bool bVar2;
  undefined4 *puVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  undefined4 extraout_r3;
  undefined4 *puVar8;
  code *pcVar9;
  undefined4 *puVar10;
  int iVar11;
  undefined4 uVar12;
  int iVar13;
  uint uVar14;
  uint uVar15;
  undefined4 *puVar16;
  int *piVar17;
  undefined4 *puVar18;
  undefined4 *local_50;
  int local_4c;
  
  uVar5 = *(uint *)(param_1 + 0x10);
  uVar15 = uVar5 & 0x1fffff;
  if (uVar15 == 0) {
    if ((uVar5 & 0x40000000) == 0) {
      uVar6 = ((int (*)())_classify_object_over_fdes)(param_1,*(undefined4 *)(param_1 + 0xc));
      uVar5 = *(uint *)(param_1 + 0x10);
      bVar2 = uVar6 == 0;
      uVar15 = uVar6;
    }
    else {
      piVar17 = *(int **)(param_1 + 0xc);
      iVar4 = *piVar17;
      bVar2 = true;
      uVar14 = 0;
      uVar6 = param_1;
      if (iVar4 != 0) {
        do {
          uVar6 = ((int (*)())_classify_object_over_fdes)(param_1,iVar4);
          piVar17 = piVar17 + 1;
          iVar4 = *piVar17;
          uVar14 = uVar14 + uVar6;
        } while (iVar4 != 0);
        uVar5 = *(uint *)(param_1 + 0x10);
        bVar2 = uVar14 == 0;
        uVar15 = uVar14;
      }
    }
    *(uint *)(param_1 + 0x10) = uVar15 & 0x1fffff | uVar5 & 0xffe00000;
    if ((uVar15 & 0x1fffff) != uVar15) {
      *(uint *)(param_1 + 0x10) = uVar5 & 0xffe00000;
    }
    if (bVar2) {
      return uVar6;
    }
  }
  iVar4 = uVar15 * 4 + 8;
  local_50 = (undefined4 *)_malloc(iVar4);
  uVar12 = 0;
  if (local_50 != (undefined4 *)0x0) {
    local_50[1] = 0;
    local_4c = _malloc(iVar4);
    if (local_4c != 0) {
      *(undefined4 *)(local_4c + 4) = 0;
    }
    if ((*(uint *)(param_1 + 0x10) & 0x40000000) == 0) {
      ((int (*)())_add_fdes)(param_1,&local_50,*(undefined4 *)(param_1 + 0xc));
    }
    else {
      piVar17 = *(int **)(param_1 + 0xc);
      iVar4 = *piVar17;
      while (iVar4 != 0) {
        ((int (*)())_add_fdes)(param_1,&local_50,iVar4);
        piVar17 = piVar17 + 1;
        iVar4 = *piVar17;
      }
    }
    if ((local_50 != (undefined4 *)0x0) && (local_50[1] != uVar15)) {
LAB_97c1d890:
                    
      _abort();
    }
    pcVar9 = DAT_a7b7c094;
    if (((*(uint *)(param_1 + 0x10) & 0x20000000) == 0) &&
       (pcVar9 = DAT_a7b7c08c, (*(uint *)(param_1 + 0x10) >> 0x15 & 0xff) == 0)) {
      pcVar9 = DAT_a7b7c090;
    }
    if (local_4c == 0) {
      uVar12 = ((int (*)())_frame_heapsort)(param_1,pcVar9,local_50);
    }
    else {
      ((int (*)())_fde_split)(param_1,pcVar9,local_50,local_4c);
      if (local_50[1] + *(int *)(local_4c + 4) != uVar15) goto LAB_97c1d890;
      ((int (*)())_frame_heapsort)(param_1,pcVar9,local_4c);
      iVar4 = local_4c;
      puVar3 = local_50;
      iVar11 = *(int *)(local_4c + 4);
      if (iVar11 != 0) {
        iVar13 = local_50[1];
        puVar10 = local_50 + iVar11;
        bVar2 = iVar13 == 0;
        puVar8 = (undefined4 *)(iVar11 * 4 + local_4c + 8);
        do {
          puVar10 = puVar10 + -1;
          iVar11 = iVar11 + -1;
          puVar16 = puVar10 + iVar13 + 2;
          puVar18 = puVar3 + iVar13;
          puVar8 = puVar8 + -1;
          uVar12 = *puVar8;
          while ((!bVar2 && (iVar7 = (*pcVar9)(param_1,puVar18[1],uVar12), 0 < iVar7))) {
            puVar1 = puVar18 + 1;
            iVar13 = iVar13 + -1;
            bVar2 = iVar13 == 0;
            puVar18 = puVar18 + -1;
            *puVar16 = *puVar1;
            puVar16 = puVar16 + -1;
          }
          puVar3[iVar13 + iVar11 + 2] = uVar12;
        } while (iVar11 != 0);
        puVar3[1] = puVar3[1] + *(int *)(iVar4 + 4);
      }
      _free(local_4c);
      uVar12 = extraout_r3;
    }
    *local_50 = *(undefined4 *)(param_1 + 0xc);
    *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) | 0x80000000;
    *(undefined4 **)(param_1 + 0xc) = local_50;
  }
  return uVar12;
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
  int iVar4;
  undefined4 uVar5;
  uint *puVar6;
  uint *puVar7;
  int iVar8;
  uint uVar9;
  uint local_60 [8];
  int local_40 [7];
  
  iVar3 = __keymgr_get_and_lock_processwide_ptr(0x12d);
  uVar5 = DAT_a7b7c088;
  iVar8 = 0;
  do {
    if (iVar3 == 0) {
LAB_97c1dbb0:
      __keymgr_unlock_processwide_ptr(0x12d);
      return iVar8;
    }
    if ((*(uint *)(iVar3 + 0x14) & 1) == 0) {
      iVar4 = _getsectdatafromheader(*(undefined4 *)(iVar3 + 4),"__DATA","__eh_frame",local_40);
      if (iVar4 == 0) {
        iVar4 = _getsectdatafromheader(*(undefined4 *)(iVar3 + 4),"__TEXT","__eh_frame",local_40);
        if (iVar4 != 0) {
          *(uint *)(iVar3 + 0x14) = *(uint *)(iVar3 + 0x14) | 4;
          goto LAB_97c1da58;
        }
      }
      else {
LAB_97c1da58:
        if (local_40[0] != 0) {
          puVar7 = (uint *)0x0;
          uVar9 = iVar4 + *(int *)(iVar3 + 8);
          if (param_3 == 0) {
            puVar7 = (uint *)_calloc(1,0x1c);
          }
          param_3 = param_3 | puVar7 == (uint *)0x0;
          if (param_3 != 0) {
            puVar7 = local_60;
          }
          puVar7[3] = uVar9;
          *puVar7 = 0xffffffff;
          puVar7[4] = 0x1fe00000;
          puVar7[1] = 0;
          puVar7[2] = 0;
          puVar7[5] = uVar9 + local_40[0];
          *(uint *)(iVar3 + 0x18) = uVar9;
          iVar8 = ((int (*)())_search_object)(puVar7,param_1);
          if (param_3 == 0) {
            *(undefined4 *)(iVar3 + 0xc) = uVar5;
            puVar6 = (uint *)&_seen_objects;
            *(uint **)(iVar3 + 0x1c) = puVar7;
            *(uint *)(iVar3 + 0x14) = *(uint *)(iVar3 + 0x14) | 9;
            puVar2 = _seen_objects;
            if (_seen_objects != (uint *)0x0) {
              do {
                if (*puVar2 < *puVar7) goto LAB_97c1db30;
                puVar1 = puVar2 + 6;
                puVar6 = puVar2 + 6;
                puVar2 = (uint *)*puVar1;
              } while ((uint *)*puVar1 != (uint *)0x0);
              puVar2 = (uint *)0x0;
            }
LAB_97c1db30:
            puVar7[6] = (uint)puVar2;
            *puVar6 = (uint)puVar7;
          }
          if (iVar8 == 0) goto LAB_97c1dba4;
          *param_2 = puVar7[1];
          param_2[1] = puVar7[2];
          uVar9 = puVar7[4] >> 0x15 & 0xff;
          if ((puVar7[4] & 0x20000000) != 0) {
            uVar9 = ((int (*)())_get_cie_encoding)((iVar8 - *(int *)(iVar8 + 4)) + 4);
          }
          uVar5 = ((int (*)())_base_from_object)(uVar9 & 0xff,puVar7);
          ((int (*)())_read_encoded_value_with_base_97c1c498)(uVar9 & 0xff,uVar5,iVar8 + 8,param_2 + 2);
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
  *(unsigned char **)(&STACKARG(0x0) + in_r11) = ((unsigned int)__builtin_frame_address(0));
  if (iVar1 == 0) {
    return;
  }
  return;
}

/* eh_rest_world_r10 @ 0x97c1de10 (264 bytes) */
int eh_rest_world_r10(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  
                    
                    
  (**(code **)((*(int *)(*(unsigned int *)__builtin_frame_address(0) + 0x0)) + 8))
            (*(undefined4 *)((*(int *)(*(unsigned int *)__builtin_frame_address(0) + 0x0)) + -0x1b0),*(undefined4 *)((*(int *)(*(unsigned int *)__builtin_frame_address(0) + 0x0)) + -0x1ac)
             ,*(undefined4 *)((*(int *)(*(unsigned int *)__builtin_frame_address(0) + 0x0)) + -0x1a8),
             *(undefined4 *)((*(int *)(*(unsigned int *)__builtin_frame_address(0) + 0x0)) + -0x1a4),param_8,*(code **)((*(int *)(*(unsigned int *)__builtin_frame_address(0) + 0x0)) + 8),
             param_7,param_8);
  return;
}

/* __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_ @ 0x97c30ae0 (4 bytes) */
int __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_(this, param_2, param_3)
  void *this;
  char *param_2;
  unsigned char * param_3;
{
  ((int (*)())__ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC4EPKcRKS2_)(this,param_2,param_3);
  return;
}

/* __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC4EPKcRKS2_ @ 0x97c30ae4 (100 bytes) */
int __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC4EPKcRKS2_(this, param_2, param_3)
  void *this;
  char *param_2;
  unsigned char * param_3;
{
  undefined4 uVar1;
  size_t sVar2;
  char *pcVar3;
  
  if (param_2 == (char *)0x0) {
    pcVar3 = (char *)0xffffffff;
  }
  else {
    sVar2 = _strlen(param_2);
    pcVar3 = param_2 + sVar2;
  }
  pcVar3 = ((int (*)())__ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE12_S_constructIPKcEEPcT_S8_RKS2_St20forward_iterator_tag)(param_2,pcVar3,param_3,0);
  uVar1 = *(undefined4 *)param_3;
  *(char **)((int)this + 4) = pcVar3;
  *(undefined4 *)this = uVar1;
  return;
}

/* __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_ @ 0x97c30b48 (4 bytes) */
int __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_(this, param_2)
  void *this;
  unsigned char * param_2;
{
  ((int (*)())__ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC4ERKS3_)(this,param_2);
  return;
}

/* __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC4ERKS3_ @ 0x97c30b4c (148 bytes) */
int __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC4ERKS3_(this, param_2)
  void *this;
  unsigned char * param_2;
{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  char in_RESERVE;
  byte in_cr0;
  int local_40 [4];
  int local_30;
  
  iVar4 = *(int *)(param_2 + 4);
  local_40[0] = GetGlobalPoolAllocator();
  local_30 = *(int *)param_2;
  if ((*(int *)(iVar4 + -4) < 0) || (local_40[0] != local_30)) {
    iVar4 = ((int (*)())__ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep8_M_cloneERKS2_m)((void *)(iVar4 + -0xc),(unsigned char *)local_40,0);
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
  uVar3 = *(undefined4 *)param_2;
  *(int *)((int)this + 4) = iVar4;
  *(undefined4 *)this = uVar3;
  return;
}

/* std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol______insert_unique @ 0x97c30be0 (388 bytes) */
int std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol______insert_unique(param_1, param_2, param_3)
  unsigned char * param_1;
  unsigned char * param_2;
  int param_3;
{
  int iVar1;
  uint *puVar2;
  void *pvVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  int local_70 [4];
  int local_60 [4];
  int local_50 [4];
  uint local_40;
  uint local_3c;
  uint local_38;
  uint local_34;
  
  iVar4 = *(int *)(param_2 + 4);
  iVar1 = 1;
  iVar5 = iVar4;
  if (*(int *)(iVar4 + 4) != 0) {
    pvVar3 = *(void **)(param_3 + 4);
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
  local_70[0] = iVar5;
  if (iVar1 != 0) {
    local_60[0] = *(int *)(iVar4 + 8);
    if (iVar5 == local_60[0]) {
      std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol_______M_insert((unsigned char *)local_50,param_2,(unsigned char *)0x0,iVar5,param_3);
      goto LAB_97c30d34;
    }
    std___Rb_tree_base_iterator___M_decrement((unsigned char *)local_70);
  }
  iVar1 = local_70[0];
  puVar2 = &local_34;
  uVar7 = *(uint *)(*(int *)(local_70[0] + 0x14) + -0xc);
  local_38 = uVar7;
  uVar8 = *(uint *)((int)*(void **)(param_3 + 4) + -0xc);
  local_34 = uVar8;
  if (uVar7 <= uVar8) {
    puVar2 = &local_38;
  }
  iVar4 = _memcmp(*(void **)(local_70[0] + 0x14),*(void **)(param_3 + 4),*puVar2);
  if (iVar4 == 0) {
    iVar4 = uVar7 - uVar8;
  }
  if (-1 < iVar4) {
    *(int *)param_1 = iVar1;
    *(undefined4 *)(param_1 + 4) = 0;
    return param_1;
  }
  std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol_______M_insert((unsigned char *)local_60,param_2,(unsigned char *)0x0,iVar5,param_3);
  local_50[0] = local_60[0];
LAB_97c30d34:
  *(int *)param_1 = local_50[0];
  *(undefined4 *)(param_1 + 4) = 1;
  return param_1;
}

/* __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_ @ 0x97c30d64 (12 bytes) */
int __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_(param_1, param_2)
  unsigned char * param_1;
  undefined4 param_2;
{
  return;
}

/* __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE12_S_constructIPKcEEPcT_S8_RKS2_St20forward_iterator_tag @ 0x97c30d70 (196 bytes) */
int __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE12_S_constructIPKcEEPcT_S8_RKS2_St20forward_iterator_tag(param_1, param_2, param_3)
  void *param_1;
  void *param_2;
  unsigned char * param_3;
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
  puVar4 = (ulong *)__ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep9_S_createEmRKS2_
                              (uVar5,param_3);
  puVar6 = puVar4 + 3;
  _memcpy(puVar6,param_1,uVar5);
  *puVar4 = uVar5;
  *(char *)((int)puVar6 + uVar5) = '\0';
  return (char *)puVar6;
}

/* __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep8_M_cloneERKS2_m @ 0x97c30e34 (148 bytes) */
int __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep8_M_cloneERKS2_m(this, param_2, param_3)
  void *this;
  unsigned char * param_2;
  ulong param_3;
{
  uint uVar1;
  undefined4 *puVar2;
  undefined4 uVar4;
  uint uVar3;
  
  uVar1 = *(int *)this + param_3;
  uVar3 = uVar1;
  if (((*(uint *)((int)this + 4) < uVar1) && (0xfe3 < uVar1)) &&
     (uVar3 = *(uint *)((int)this + 4) << 1, uVar3 < uVar1)) {
    uVar3 = uVar1;
  }
  puVar2 = (undefined4 *)
           __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep9_S_createEmRKS2_(uVar3,param_2);
  uVar4 = 0;
  if (*(size_t *)this != 0) {
    _memcpy(puVar2 + 3,(void *)((int)this + 0xc),*(size_t *)this);
    uVar4 = *(undefined4 *)this;
  }
  *puVar2 = uVar4;
  return puVar2 + 3;
}

