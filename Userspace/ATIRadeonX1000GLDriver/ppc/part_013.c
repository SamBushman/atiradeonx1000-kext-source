#include "decls.h"

/* FUN_000cff30 @ 0xcff30 (252 bytes) */
int FUN_000cff30(param_1, param_2, param_3, param_4, param_5)
  int *param_1;
  undefined4 param_2;
  char *param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  int iVar1;
  size_t sVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  char acStack_98 [120];
  
  *param_3 = '\0';
  iVar1 = *param_1;
  if ((*(int **)(iVar1 + 0x654) == (int *)0x0) || (iVar4 = **(int **)(iVar1 + 0x654), iVar4 < 1)) {
    iVar3 = param_1[1];
  }
  else {
    iVar3 = param_1[1];
    iVar5 = 0;
    while( true ) {
      if (*(int *)(iVar5 * 0x1c + *(int *)(iVar1 + 0x654) + 0x14) + 1 == iVar3) {
        FUN_000cfd24(param_1);
        iVar3 = param_1[1];
      }
      iVar5 = iVar5 + 1;
      if (iVar4 == iVar5) break;
      iVar1 = *param_1;
    }
  }
  FUN_001a32d0(acStack_98,"%3d:",iVar3);
  _strcat(param_3,acStack_98);
  param_1[1] = param_1[1] + 1;
  sVar2 = _strlen(param_3);
  FUN_000cf2ec(param_1,param_2,param_3 + sVar2,param_4,param_5);
  return;
}

/* FUN_000d002c @ 0xd002c (728 bytes) */
int FUN_000d002c(param_1, param_2)
  int *param_1;
  int param_2;
{
  char *pcVar1;
  int iVar2;
  undefined4 uVar3;
  size_t sVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int local_d8;
  int local_d4;
  char acStack_d0 [22];
  undefined1 auStack_ba [22];
  undefined1 auStack_a4 [22];
  char acStack_8e [22];
  char acStack_78 [48];
  
  iVar7 = *(int *)(param_2 + 0x650);
  iVar5 = *(int *)(param_2 + 0x65c);
  *param_1 = param_2;
  FUN_000ce050(param_1,";*****************************************");
  FUN_000ce050(param_1,";              VS Disassembly             ");
  FUN_000ce050(param_1,";*****************************************");
  if (iVar5 != 0) {
    iVar6 = 0;
    do {
      iVar2 = ((int (*)())FUN_000cff30)(param_1,iVar7,auStack_ba,&local_d8,&local_d4);
      if (iVar2 == 0) {
        if (local_d8 == 0) {
          uVar3 = FUN_000cea6c(param_1,iVar7,acStack_78);
          uVar3 = FUN_000ce148(param_1,uVar3,acStack_d0);
          uVar3 = FUN_000ce148(param_1,uVar3,acStack_8e);
          iVar7 = FUN_000ce148(param_1,uVar3,auStack_a4);
          if (local_d4 == 1) {
            sVar4 = _strlen(acStack_78);
            pcVar1 = acStack_78 + sVar4;
            pcVar1[0] = ',';
            pcVar1[1] = '\0';
            FUN_000ce050(param_1,"%s %-10s%-15s",auStack_ba,acStack_78,acStack_d0);
          }
          else if (local_d4 == 0) {
            FUN_000ce050(param_1,"%s %-10s",auStack_ba,acStack_78);
          }
          else if (local_d4 == 2) {
            sVar4 = _strlen(acStack_78);
            pcVar1 = acStack_78 + sVar4;
            pcVar1[0] = ',';
            pcVar1[1] = '\0';
            sVar4 = _strlen(acStack_d0);
            pcVar1 = acStack_d0 + sVar4;
            pcVar1[0] = ',';
            pcVar1[1] = '\0';
            FUN_000ce050(param_1,"%s %-10s%-15s%-15s",auStack_ba,acStack_78,acStack_d0,acStack_8e);
          }
          else {
            sVar4 = _strlen(acStack_78);
            pcVar1 = acStack_78 + sVar4;
            pcVar1[0] = ',';
            pcVar1[1] = '\0';
            sVar4 = _strlen(acStack_d0);
            pcVar1 = acStack_d0 + sVar4;
            pcVar1[0] = ',';
            pcVar1[1] = '\0';
            sVar4 = _strlen(acStack_8e);
            pcVar1 = acStack_8e + sVar4;
            pcVar1[0] = ',';
            pcVar1[1] = '\0';
            FUN_000ce050(param_1,"%s %-10s%-15s%-15s%s",auStack_ba,acStack_78,acStack_d0,acStack_8e,
                         auStack_a4);
          }
        }
        else {
          uVar3 = FUN_000cea6c(param_1,iVar7,acStack_78);
          uVar3 = FUN_000ce148(param_1,uVar3,acStack_d0);
          uVar3 = FUN_000ce148(param_1,uVar3,acStack_8e);
          sVar4 = _strlen(acStack_78);
          pcVar1 = acStack_78 + sVar4;
          pcVar1[0] = ',';
          pcVar1[1] = '\0';
          sVar4 = _strlen(acStack_d0);
          pcVar1 = acStack_d0 + sVar4;
          pcVar1[0] = ',';
          pcVar1[1] = '\0';
          FUN_000ce050(param_1,"%s %-10s%-15s%-15s",auStack_ba,acStack_78,acStack_d0,acStack_8e);
          iVar7 = FUN_000ced58(param_1,uVar3,auStack_ba,acStack_78,acStack_d0);
          FUN_000ce050(param_1,"%s %-10s%-15s",auStack_ba,acStack_78,acStack_d0);
        }
      }
      else {
        iVar7 = iVar7 + 0x10;
        FUN_000ce050(param_1,"%s",auStack_ba);
      }
      iVar6 = iVar6 + 1;
    } while (iVar5 != iVar6);
  }
  FUN_000ce050(param_1,"");
  param_1[1] = 0;
  return 1;
}

/* FUN_000d0304 @ 0xd0304 (84 bytes) */
int FUN_000d0304(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined1 auStack_38 [8];
  undefined4 local_30;
  undefined4 local_2c;
  
  FUN_000ce038(auStack_38);
  local_30 = param_3;
  local_2c = param_1;
  FUN_000ce88c(auStack_38,param_2);
  return 0;
}

/* FUN_000d035c @ 0xd035c (84 bytes) */
int FUN_000d035c(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  undefined1 auStack_38 [8];
  undefined4 local_30;
  undefined4 local_2c;
  
  FUN_000ce038(auStack_38);
  local_30 = param_4;
  local_2c = param_1;
  ((int (*)())FUN_000d002c)(auStack_38,param_2);
  return 0;
}

/* FUN_000d03b4 @ 0xd03b4 (152 bytes) */
int FUN_000d03b4(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  undefined4 uStack00000020;
  undefined4 uStack00000024;
  undefined4 uStack00000028;
  undefined4 uStack0000002c;
  undefined4 uStack00000030;
  undefined4 uStack00000034;
  undefined1 auStack_124 [280];
  
  if (DAT_001fa61c != (undefined4 *)0x0) {
    uStack00000020 = param_3;
    uStack00000024 = param_4;
    uStack00000028 = param_5;
    uStack0000002c = param_6;
    uStack00000030 = param_7;
    uStack00000034 = param_8;
    FUN_001a34d4(auStack_124,param_2,&STACKARG(0x20));
    (*(code *)*DAT_001fa61c)(DAT_001fa618,"",auStack_124,&STACKARG(0x20));
  }
  return;
}

/* FUN_000d0450 @ 0xd0450 (56 bytes) */
int FUN_000d0450(param_1, param_2)
  undefined4 param_1;
  uint param_2;
{
  if ((param_2 & 0x8000) != 0) {
    FUN_001a32d0(param_1,"c%02u",param_2 & 0xffff7fff);
    return;
  }
  FUN_001a32d0(param_1,"r%02u",param_2);
  return;
}

/* FUN_000d0488 @ 0xd0488 (604 bytes) */
int FUN_000d0488(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  char *param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  uint param_8;
{
  char cVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  size_t sVar5;
  int in_stack_00000038;
  char local_38 [6];
  undefined1 auStack_32 [22];
  
  cVar4 = s______001a6f98[4];
  cVar3 = s_nab__001a6f90[4];
  cVar2 = s_abs__001a6f88[4];
  cVar1 = s_neg__001a6f80[4];
  if (in_stack_00000038 == 1) {
    *(undefined4 *)param_1 = (*(unsigned int *)((unsigned char *)&(s_neg__001a6f80) + 0));
    param_1[4] = cVar1;
  }
  else if (in_stack_00000038 == 0) {
    *param_1 = '\0';
  }
  else if (in_stack_00000038 == 2) {
    *(undefined4 *)param_1 = (*(unsigned int *)((unsigned char *)&(s_abs__001a6f88) + 0));
    param_1[4] = cVar2;
  }
  else if (in_stack_00000038 == 3) {
    *(undefined4 *)param_1 = (*(unsigned int *)((unsigned char *)&(s_nab__001a6f90) + 0));
    param_1[4] = cVar3;
  }
  else {
    *(undefined4 *)param_1 = (*(unsigned int *)((unsigned char *)&(s______001a6f98) + 0));
    param_1[4] = cVar4;
  }
  switch(param_8) {
  case 0:
  case 1:
  case 2:
  case 3:
  case 0x17:
  case 0x1a:
    ((int (*)())FUN_000d0450)(local_38,param_2);
    break;
  case 4:
  case 5:
  case 6:
  case 7:
  case 0x18:
  case 0x1b:
    ((int (*)())FUN_000d0450)(local_38,param_3);
    break;
  case 8:
  case 9:
  case 10:
  case 0xb:
  case 0x19:
  case 0x1c:
    ((int (*)())FUN_000d0450)(local_38,param_4);
    break;
  case 0xc:
    ((int (*)())FUN_000d0450)(local_38,param_5);
    break;
  case 0xd:
    ((int (*)())FUN_000d0450)(local_38,param_6);
    break;
  case 0xe:
    ((int (*)())FUN_000d0450)(local_38,param_7);
    break;
  case 0xf:
  case 0x10:
  case 0x11:
  case 0x12:
  case 0x13:
    local_38[0] = s_srcp_001a6fa0[0];
    local_38[1] = s_srcp_001a6fa0[1];
    local_38[2] = s_srcp_001a6fa0[2];
    local_38[3] = s_srcp_001a6fa0[3];
    local_38[4] = s_srcp_001a6fa0[4];
    break;
  case 0x14:
    builtin_strncpy(local_38,"0.0",4);
    break;
  case 0x15:
    builtin_strncpy(local_38,"1.0",4);
    break;
  case 0x16:
    builtin_strncpy(local_38,"0.5",4);
    break;
  case 0x1d:
    ((int (*)())FUN_000d0450)(local_38,param_5);
    ((int (*)())FUN_000d0450)(auStack_32,param_2);
    break;
  case 0x1e:
    ((int (*)())FUN_000d0450)(local_38,param_6);
    ((int (*)())FUN_000d0450)(auStack_32,param_3);
    break;
  case 0x1f:
    ((int (*)())FUN_000d0450)(local_38,param_7);
    ((int (*)())FUN_000d0450)(auStack_32,param_4);
    break;
  default:
    builtin_strncpy(local_38,"???",4);
  }
  sVar5 = _strlen(param_1);
  if (0x1f < param_8) {
    _strcpy(param_1 + sVar5,local_38);
    sVar5 = _strlen(param_1);
    if (in_stack_00000038 != 0) {
      (param_1 + sVar5)[0] = ')';
      (param_1 + sVar5)[1] = '\0';
    }
    return;
  }
                    
                    
  (*(code *)(((unsigned char *)0x000d0730) + *(int *)(((unsigned char *)0x000d0730) + param_8 * 4)))();
  return;
}

/* FUN_000d0888 @ 0xd0888 (516 bytes) */
int FUN_000d0888(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  char *param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  uint param_8;
{
  char cVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  size_t sVar5;
  int in_stack_00000038;
  char local_28 [24];
  
  cVar4 = s______001a6f98[4];
  cVar3 = s_nab__001a6f90[4];
  cVar2 = s_abs__001a6f88[4];
  cVar1 = s_neg__001a6f80[4];
  if (in_stack_00000038 == 1) {
    *(undefined4 *)param_1 = (*(unsigned int *)((unsigned char *)&(s_neg__001a6f80) + 0));
    param_1[4] = cVar1;
  }
  else if (in_stack_00000038 == 0) {
    *param_1 = '\0';
  }
  else if (in_stack_00000038 == 2) {
    *(undefined4 *)param_1 = (*(unsigned int *)((unsigned char *)&(s_abs__001a6f88) + 0));
    param_1[4] = cVar2;
  }
  else if (in_stack_00000038 == 3) {
    *(undefined4 *)param_1 = (*(unsigned int *)((unsigned char *)&(s_nab__001a6f90) + 0));
    param_1[4] = cVar3;
  }
  else {
    *(undefined4 *)param_1 = (*(unsigned int *)((unsigned char *)&(s______001a6f98) + 0));
    param_1[4] = cVar4;
  }
  switch(param_8) {
  case 0:
  case 1:
  case 2:
    ((int (*)())FUN_000d0450)(local_28,param_2);
    break;
  case 3:
  case 4:
  case 5:
    ((int (*)())FUN_000d0450)(local_28,param_3);
    break;
  case 6:
  case 7:
  case 8:
    ((int (*)())FUN_000d0450)(local_28,param_4);
    break;
  case 9:
    ((int (*)())FUN_000d0450)(local_28,param_5);
    break;
  case 10:
    ((int (*)())FUN_000d0450)(local_28,param_6);
    break;
  case 0xb:
    ((int (*)())FUN_000d0450)(local_28,param_7);
    break;
  case 0xc:
  case 0xd:
  case 0xe:
  case 0xf:
    local_28[0] = s_srcp_001a6fa0[0];
    local_28[1] = s_srcp_001a6fa0[1];
    local_28[2] = s_srcp_001a6fa0[2];
    local_28[3] = s_srcp_001a6fa0[3];
    local_28[4] = s_srcp_001a6fa0[4];
    break;
  case 0x10:
    builtin_strncpy(local_28,"0.0",4);
    break;
  case 0x11:
    builtin_strncpy(local_28,"1.0",4);
    break;
  case 0x12:
    builtin_strncpy(local_28,"0.5",4);
    break;
  default:
    builtin_strncpy(local_28,"???",4);
  }
  sVar5 = _strlen(param_1);
  if (0xf < param_8) {
    _strcpy(param_1 + sVar5,local_28);
    sVar5 = _strlen(param_1);
    if (in_stack_00000038 != 0) {
      (param_1 + sVar5)[0] = ')';
      (param_1 + sVar5)[1] = '\0';
    }
    return;
  }
                    
                    
  (*(code *)(((unsigned char *)0x000d0aa4) + *(int *)(((unsigned char *)0x000d0aa4) + param_8 * 4)))();
  return;
}

/* FUN_000d0b68 @ 0xd0b68 (1344 bytes) */
int FUN_000d0b68(param_1, param_2)
  int param_1;
  uint param_2;
{
  bool bVar1;
  byte bVar2;
  bool bVar3;
  uint uVar4;
  char cVar7;
  char cVar8;
  int iVar5;
  int *piVar6;
  char cVar9;
  undefined *puVar10;
  uint uVar11;
  byte bVar12;
  uint uVar13;
  undefined *puVar14;
  undefined *puVar15;
  uint uVar16;
  undefined1 *puVar17;
  undefined *puVar18;
  undefined *puVar19;
  uint *puVar20;
  
  if (param_2 <= (*(byte *)(param_1 + 0xf) & 0xf)) {
    return;
  }
  puVar15 = *(undefined **)(param_1 + 8);
  if ((*(int *)(param_1 + 0x48) == 1) && (puVar15 != (undefined *)0x0)) {
    piVar6 = (int *)(param_1 + 0x90);
    puVar14 = (undefined *)0x1;
    do {
      puVar14 = puVar14 + 1;
      if (*piVar6 != 1) goto LAB_000d0bfc;
      piVar6 = piVar6 + 0x12;
    } while (puVar14 <= puVar15);
LAB_000d0bd8:
    bVar12 = 0;
    uVar11 = 0;
    bVar3 = true;
  }
  else {
    puVar14 = (undefined *)0x1;
LAB_000d0bfc:
    if (puVar15 < puVar14) goto LAB_000d0bd8;
    bVar12 = 0;
    bVar3 = true;
    puVar20 = (uint *)(param_1 + (int)puVar14 * 0x48);
    uVar13 = 0;
    uVar16 = 0;
    bVar1 = false;
    uVar11 = 0;
    puVar18 = puVar14;
    do {
      uVar4 = *puVar20;
      if (uVar4 < 5) {
        if (uVar4 < 3) {
          if (uVar4 != 2) goto LAB_000d0c50;
          bVar12 = bVar12 | *(byte *)(puVar20 + 1) | *(byte *)((int)puVar20 + 0x1b);
          if (*(char *)((int)puVar20 + 0x1a) != '\0') {
            uVar11 = uVar11 | -(puVar20[7] & 0xffff00) >> 0x1f;
          }
        }
        else {
          bVar12 = bVar12 | *(byte *)(puVar20 + 1);
        }
      }
      else if (uVar4 == 5) {
        bVar12 = bVar12 | *(byte *)(puVar20 + 1);
        if (bVar3) {
          if ((*(char *)((int)puVar20 + 0xe) != '\0') || (*(char *)((int)puVar20 + 0x11) != '\0')) {
            bVar1 = true;
          }
          uVar4 = puVar20[4] & 0xff00ff00;
          if ((uVar4 != 0) &&
             ((*(ushort *)(puVar20 + 3) < uVar16 || (*(char *)((int)puVar20 + 0x19) != '\0')))) {
            bVar1 = true;
          }
          cVar7 = *(char *)(puVar20 + 5);
          cVar8 = *(char *)((int)puVar20 + 0x15);
          cVar9 = cVar7;
          if ((uVar4 != 0) && (cVar9 = cVar8, uVar4 == 0x100ff00)) {
            cVar7 = cVar8;
          }
          cVar8 = cVar9;
          if ((cVar7 == '\x01') || (cVar8 = cVar7, cVar7 != '\0')) {
            if (cVar8 == '\x02') goto LAB_000d0d60;
            if (cVar8 == '\x01') {
              uVar13 = uVar13 - *(byte *)((int)puVar20 + 0x13);
            }
          }
          else if (cVar9 == '\x02') {
LAB_000d0d60:
            uVar13 = uVar13 + 1;
          }
          bVar3 = !bVar1;
          if (4 < uVar13) {
            bVar1 = true;
            bVar3 = false;
          }
        }
      }
      else {
LAB_000d0c50:
        ((int (*)())FUN_000d03b4)(0,"Bad Instruction Type!");
      }
      puVar18 = puVar18 + 1;
      uVar16 = uVar16 + 1;
      puVar20 = puVar20 + 0x12;
    } while (puVar18 <= puVar15);
    if (uVar16 != 0) goto LAB_000d0be8;
  }
  uVar16 = 1;
LAB_000d0be8:
  if ((*(short *)(param_1 + 0x20) == 0) && (*(short *)(param_1 + 0x12) == 0)) {
    *(short *)(param_1 + 0x12) = (short)uVar16 + -1;
  }
  if (!bVar3) {
    *(undefined2 *)(param_1 + 0x28) = 1;
  }
  if ((*(short *)(param_1 + 0x28) != 0) && (*(short *)(param_1 + 0x22) == 0)) {
    *(undefined2 *)(param_1 + 0x22) = 1;
  }
  if (puVar14 <= puVar15) {
    bVar1 = bVar12 != 0;
    puVar20 = (uint *)(param_1 + (int)puVar14 * 0x48);
    puVar17 = (undefined1 *)((int)puVar20 + -3);
    uVar13 = 0;
    puVar18 = ((unsigned char *)0x000186a0);
    puVar19 = puVar14;
    do {
      uVar16 = *puVar20;
      puVar10 = puVar18;
      if (uVar16 < 5) {
        if (uVar16 < 3) {
          if (uVar16 == 2) {
            if (uVar11 == 0) {
              *(undefined1 *)((int)puVar20 + 0x1e) = 1;
              *(undefined1 *)((int)puVar20 + 0x1d) = 7;
              puVar20[5] = puVar20[5] & 0xffff | 0x1b1b0000;
            }
            bVar2 = *(byte *)((int)puVar20 + 0x1f);
            if (bVar2 != 0) {
              if ((bVar2 & 2) != 0) {
                puVar20[5] = puVar20[5] >> 2 & 0x300000 | puVar20[5] & 0xffcfffff;
              }
              if ((bVar2 & 4) != 0) {
                puVar20[5] = puVar20[5] >> 4 & 0xc0000 | puVar20[5] & 0xfff3ffff;
              }
              if ((bVar2 & 8) != 0) {
                puVar20[5] = puVar20[5] >> 6 & 0x30000 | puVar20[5] & 0xfffcffff;
              }
            }
            puVar10 = puVar19;
            if (((!bVar1) && (*(char *)(puVar20 + 8) != '\0')) && (puVar18 != ((unsigned char *)0x000186a0))) {
              iVar5 = param_1 + (int)puVar18 * 0x48;
              *(undefined1 *)(iVar5 + 4) = 1;
              *(undefined1 *)(iVar5 + 0x1b) = 1;
              *(undefined1 *)(puVar20 + 1) = 1;
            }
          }
        }
        else {
          if (((*(char *)((int)puVar20 + 0x15) == '\0') && ((puVar20[8] & 0xff00ff) == 0)) &&
             (uVar13 != *(ushort *)(param_1 + 0x12))) {
            *puVar20 = 4;
          }
          if ((bVar1) || (puVar18 == ((unsigned char *)0x000186a0))) {
LAB_000d1004:
            puVar10 = ((unsigned char *)0x000186a0);
          }
          else {
            iVar5 = param_1 + (int)puVar18 * 0x48;
            *(undefined1 *)(iVar5 + 4) = 1;
            *(undefined1 *)(iVar5 + 0x1b) = 1;
            *(undefined1 *)(puVar20 + 1) = 1;
            puVar10 = ((unsigned char *)0x000186a0);
          }
        }
      }
      else if (uVar16 == 5) {
        if ((!bVar1) && (puVar18 != ((unsigned char *)0x000186a0))) {
          iVar5 = param_1 + (int)puVar18 * 0x48;
          *(undefined1 *)(iVar5 + 4) = 1;
          *(undefined1 *)(iVar5 + 0x1b) = 1;
          *(undefined1 *)(puVar20 + 1) = 1;
        }
        if ((byte)(*(byte *)((int)puVar20 + 0x12) & 0xf0) ==
            (byte)(*(byte *)((int)puVar20 + 0x12) << 4)) goto LAB_000d1004;
        if (uVar13 == 0) {
          ((int (*)())FUN_000d03b4)(0,"FC ALU result test is first US instruction");
          puVar10 = ((unsigned char *)0x000186a0);
        }
        else if (*(int *)(puVar17 + -0x45) - 3U < 2) {
          *puVar17 = 1;
          puVar10 = ((unsigned char *)0x000186a0);
        }
        else {
          ((int (*)())FUN_000d03b4)(0,"FC ALU result test follows non-ALU instruction");
          puVar10 = ((unsigned char *)0x000186a0);
        }
      }
      puVar19 = puVar19 + 1;
      uVar13 = uVar13 + 1;
      puVar20 = puVar20 + 0x12;
      puVar17 = puVar17 + 0x48;
      puVar18 = puVar10;
    } while (puVar19 <= puVar15);
    if (((uVar13 != 0) &&
        (*(int *)(param_1 + (int)(puVar14 + *(ushort *)(param_1 + 0x12)) * 0x48) == 3)) &&
       (bVar12 == 0)) {
      *(undefined1 *)(param_1 + (int)(puVar14 + *(ushort *)(param_1 + 0x12)) * 0x48 + 4) = 1;
    }
  }
  if (((uVar11 != 0) || (bVar12 != 0)) || (*(short *)(param_1 + 0x20) != 0)) {
    param_2 = param_2 | param_2 << 4;
  }
  *(char *)(param_1 + 0xf) = (char)param_2;
  return;
}

/* FUN_000d10a8 @ 0xd10a8 (52 bytes) */
int FUN_000d10a8(param_1)
  uint param_1;
{
  if ((((param_1 & 0xe000) != 0x6000) && ((param_1 & 0x1c00) != 0xc00)) &&
     ((param_1 & 0x380) != 0x180)) {
    return 0;
  }
  return 1;
}

/* FUN_000d10dc @ 0xd10dc (712 bytes) */
int FUN_000d10dc(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  bool bVar1;
  char cVar2;
  double dVar3;
  double dVar4;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  uint uVar8;
  int iVar9;
  double dVar10;
  double dVar11;
  double dVar12;
  ulonglong uVar13;
  char local_98 [10];
  undefined1 local_8e;
  undefined1 local_8d;
  char local_8c;
  char local_8b;
  undefined1 local_8a;
  undefined4 local_88;
  uint uStack_84;
  longlong local_80;
  undefined4 local_78;
  uint uStack_74;
  undefined4 local_70;
  uint uStack_6c;
  longlong local_68;
  undefined4 local_60;
  uint uStack_5c;
  longlong local_58;
  float local_50;
  
  uVar13 = FUN_001a3260(param_1,param_2,param_2);
  uVar7 = (undefined4)(uVar13 >> 0x20);
  uVar8 = (uint)uVar13;
  if ((uVar13 & 0x8000) == 0) {
    if ((uVar13 & 0x4000) == 0) {
      if ((uVar13 & 0x2000) == 0) {
        FUN_001a32d0(uVar7,"r%02u");
      }
      else {
        dVar10 = (double)((double (*)())FUN_000da78c)(uVar8 & 0xffffdfff);
        dVar4 = DOUBLE_001aa238;
        dVar3 = DOUBLE_001aa1e0;
        if (dVar10 == (double)FLOAT_001aa0d4) {
          local_98[0] = ' ';
          local_98[2] = 0x2e;
          iVar9 = 7;
          local_98[1] = '0';
          iVar5 = 3;
          do {
            local_98[iVar5] = '0';
            iVar5 = iVar5 + 1;
            iVar9 = iVar9 + -1;
          } while (iVar9 != 0);
          local_8d = 0x2b;
          local_8b = '0';
          local_8c = '0';
        }
        else {
          if (dVar10 < (double)FLOAT_001aa0d4) {
            dVar10 = -dVar10;
            local_98[0] = '-';
          }
          else {
            local_98[0] = '+';
          }
          local_50 = (float)dVar10;
          local_88 = 0x43300000;
          uStack_84 = ((uint)local_50 >> 0x17 & 0xff) - 0x7f ^ 0x80000000;
          _pow(DOUBLE_001aa2a0,(double)CONCAT44(0x43300000,uStack_84) - DOUBLE_001aa1e0);
          dVar11 = (double)_log();
          dVar12 = (double)_log(dVar4);
          dVar11 = (double)_floor(dVar11 / dVar12);
          local_78 = 0x43300000;
          uVar8 = (uint)dVar11;
          local_80 = (longlong)(int)uVar8;
          uStack_74 = uVar8 ^ 0x80000000;
          dVar12 = (double)_pow(dVar4,(double)CONCAT44(0x43300000,uStack_74) - dVar3);
          dVar11 = DOUBLE_001aa298;
          dVar12 = dVar10 / dVar12 + DOUBLE_001aa298;
          if (dVar4 <= dVar12) {
            uVar8 = uVar8 + 1;
            local_70 = 0x43300000;
            uStack_6c = uVar8 ^ 0x80000000;
            dVar12 = (double)_pow(dVar4,(double)CONCAT44(0x43300000,uStack_6c) - dVar3);
            dVar12 = dVar10 / dVar12 + dVar11;
          }
          dVar10 = (double)_floor(dVar12);
          uVar6 = (uint)dVar10;
          local_68 = (longlong)(int)uVar6;
          local_98[2] = 0x2e;
          iVar5 = 3;
          local_98[1] = (char)uVar6 + '0';
          do {
            uStack_5c = uVar6 ^ 0x80000000;
            local_60 = 0x43300000;
            dVar12 = (dVar12 - ((double)CONCAT44(0x43300000,uStack_5c) - dVar3)) * dVar4;
            dVar10 = (double)_floor(dVar12);
            bVar1 = iVar5 != 9;
            uVar6 = (uint)dVar10;
            local_58 = (longlong)(int)uVar6;
            local_98[iVar5] = (char)uVar6 + '0';
            iVar5 = iVar5 + 1;
          } while (bVar1);
          if ((int)uVar8 < 0) {
            uVar8 = -uVar8;
            local_8d = 0x2d;
          }
          else {
            local_8d = 0x2b;
          }
          cVar2 = (char)((int)uVar8 / 10);
          local_8c = cVar2 + '0';
          local_8b = (char)uVar8 + cVar2 * -10 + '0';
        }
        local_8e = 0x45;
        local_8a = 0;
        FUN_001a32d0(param_1,"(%s)",local_98);
      }
    }
    else {
      FUN_001a32d0(uVar7,"r[AL+%02u]",uVar8 & 0xffffbfff);
    }
  }
  else {
    FUN_001a32d0(uVar7,"c%02u",uVar8 & 0xffff7fff);
  }
  return;
}

/* FUN_000d13a4 @ 0xd13a4 (640 bytes) */
int FUN_000d13a4(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  char *param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  int param_8;
{
  ushort uVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  int iVar6;
  size_t sVar7;
  int in_stack_00000038;
  ushort in_stack_0000003e;
  int in_stack_00000040;
  char local_58 [44];
  
  cVar5 = s______001a6f98[4];
  cVar4 = s_nab__001a6f90[4];
  cVar3 = s_abs__001a6f88[4];
  cVar2 = s_neg__001a6f80[4];
  if (in_stack_00000038 == 1) {
    *(undefined4 *)param_1 = (*(unsigned int *)((unsigned char *)&(s_neg__001a6f80) + 0));
    param_1[4] = cVar2;
  }
  else if (in_stack_00000038 == 0) {
    *param_1 = '\0';
  }
  else if (in_stack_00000038 == 2) {
    *(undefined4 *)param_1 = (*(unsigned int *)((unsigned char *)&(s_abs__001a6f88) + 0));
    param_1[4] = cVar3;
  }
  else if (in_stack_00000038 == 3) {
    *(undefined4 *)param_1 = (*(unsigned int *)((unsigned char *)&(s_nab__001a6f90) + 0));
    param_1[4] = cVar4;
  }
  else {
    *(undefined4 *)param_1 = (*(unsigned int *)((unsigned char *)&(s______001a6f98) + 0));
    param_1[4] = cVar5;
  }
  if (in_stack_00000040 - 0xbU < 2) {
LAB_000d14bc:
    ((int (*)())FUN_000d10dc)(local_58,param_2);
  }
  else {
    iVar6 = ((int (*)())FUN_000d10a8)(in_stack_0000003e);
    if (iVar6 == 0) {
      if (param_8 == 1) {
        ((int (*)())FUN_000d10dc)(local_58,param_3);
        goto LAB_000d1518;
      }
      if (param_8 == 0) goto LAB_000d14bc;
      if (param_8 == 2) {
        ((int (*)())FUN_000d10dc)(local_58,param_4);
        goto LAB_000d1518;
      }
    }
    else {
      if (param_8 == 1) {
        ((int (*)())FUN_000d10dc)(local_58,param_6);
        goto LAB_000d1518;
      }
      if (param_8 == 0) {
        ((int (*)())FUN_000d10dc)(local_58,param_5);
        goto LAB_000d1518;
      }
      if (param_8 == 2) {
        ((int (*)())FUN_000d10dc)(local_58,param_7);
        goto LAB_000d1518;
      }
    }
    if (param_8 == 3) {
      local_58[0] = s_srcp_001a6fa0[0];
      local_58[1] = s_srcp_001a6fa0[1];
      local_58[2] = s_srcp_001a6fa0[2];
      local_58[3] = s_srcp_001a6fa0[3];
      local_58[4] = s_srcp_001a6fa0[4];
    }
    else {
      builtin_strncpy(local_58,"???",4);
    }
  }
LAB_000d1518:
  sVar7 = _strlen(param_1);
  uVar1 = in_stack_0000003e & 0xff80;
  if (((uVar1 == 0x9200) || (uVar1 == 0xdb00)) || (uVar1 == 0xb680)) {
    _strcpy(param_1 + sVar7,(char *)((in_stack_0000003e >> 0xb & 0x1c) + 0x1dc259));
  }
  else {
    FUN_001a32d0(param_1 + sVar7,"%s.%s%s%s",local_58,(in_stack_0000003e >> 0xb & 0x1c) + 0x1dc259,
                 (in_stack_0000003e >> 8 & 0x1c) + 0x1dc259,
                 (in_stack_0000003e >> 5 & 0x1c) + 0x1dc259);
  }
  sVar7 = _strlen(param_1);
  if (in_stack_00000038 != 0) {
    (param_1 + sVar7)[0] = ')';
    (param_1 + sVar7)[1] = '\0';
  }
  return;
}

/* FUN_000d1624 @ 0xd1624 (536 bytes) */
int FUN_000d1624(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  char *param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  int param_8;
{
  char cVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  size_t sVar5;
  int in_stack_00000038;
  int in_stack_0000003c;
  int in_stack_00000040;
  char local_38 [40];
  
  cVar4 = s______001a6f98[4];
  cVar3 = s_nab__001a6f90[4];
  cVar2 = s_abs__001a6f88[4];
  cVar1 = s_neg__001a6f80[4];
  if (in_stack_00000038 == 1) {
    *(undefined4 *)param_1 = (*(unsigned int *)((unsigned char *)&(s_neg__001a6f80) + 0));
    param_1[4] = cVar1;
  }
  else if (in_stack_00000038 == 0) {
    *param_1 = '\0';
  }
  else if (in_stack_00000038 == 2) {
    *(undefined4 *)param_1 = (*(unsigned int *)((unsigned char *)&(s_abs__001a6f88) + 0));
    param_1[4] = cVar2;
  }
  else if (in_stack_00000038 == 3) {
    *(undefined4 *)param_1 = (*(unsigned int *)((unsigned char *)&(s_nab__001a6f90) + 0));
    param_1[4] = cVar3;
  }
  else {
    *(undefined4 *)param_1 = (*(unsigned int *)((unsigned char *)&(s______001a6f98) + 0));
    param_1[4] = cVar4;
  }
  if (1 < in_stack_00000040 - 0xeU) {
    if (in_stack_0000003c != 3) {
      if (param_8 != 1) {
        if (param_8 == 0) {
          ((int (*)())FUN_000d10dc)(local_38,param_2);
          goto LAB_000d1780;
        }
        param_3 = param_4;
        if (param_8 != 2) goto LAB_000d176c;
      }
      ((int (*)())FUN_000d10dc)(local_38,param_3);
      goto LAB_000d1780;
    }
    if (param_8 == 1) {
      ((int (*)())FUN_000d10dc)(local_38,param_6);
      goto LAB_000d1780;
    }
    if (param_8 != 0) {
      if (param_8 == 2) {
        ((int (*)())FUN_000d10dc)(local_38,param_7);
        goto LAB_000d1780;
      }
LAB_000d176c:
      if (param_8 == 3) {
        local_38[0] = s_srcp_001a6fa0[0];
        local_38[1] = s_srcp_001a6fa0[1];
        local_38[2] = s_srcp_001a6fa0[2];
        local_38[3] = s_srcp_001a6fa0[3];
        local_38[4] = s_srcp_001a6fa0[4];
      }
      else {
        builtin_strncpy(local_38,"???",4);
      }
      goto LAB_000d1780;
    }
  }
  ((int (*)())FUN_000d10dc)(local_38,param_5);
LAB_000d1780:
  sVar5 = _strlen(param_1);
  if (in_stack_0000003c - 4U < 3) {
    _strcpy(param_1 + sVar5,(char *)(in_stack_0000003c * 4 + 0x1dc259));
  }
  else {
    FUN_001a32d0(param_1 + sVar5,"%s.%s",local_38,in_stack_0000003c * 4 + 0x1dc259);
  }
  sVar5 = _strlen(param_1);
  if (in_stack_00000038 != 0) {
    (param_1 + sVar5)[0] = ')';
    (param_1 + sVar5)[1] = '\0';
  }
  return;
}

/* FUN_000d183c @ 0xd183c (13160 bytes) */
int FUN_000d183c(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  bool bVar1;
  bool bVar2;
  byte bVar3;
  undefined1 uVar4;
  byte bVar5;
  char cVar6;
  char cVar7;
  ushort uVar8;
  undefined2 uVar9;
  undefined2 uVar10;
  undefined2 uVar11;
  undefined2 uVar12;
  undefined2 uVar13;
  undefined2 uVar14;
  undefined2 uVar15;
  undefined2 uVar16;
  bool bVar17;
  int iVar18;
  char cVar20;
  uint uVar19;
  size_t sVar21;
  int iVar22;
  char *pcVar23;
  char *pcVar24;
  char *pcVar25;
  char *pcVar26;
  bool bVar27;
  bool bVar28;
  bool bVar29;
  uint uVar30;
  uint uVar31;
  uint uVar32;
  uint uVar33;
  int iVar34;
  uint uVar35;
  uint uVar36;
  int *piVar37;
  uint *puVar38;
  undefined **ppuVar39;
  int *piVar40;
  bool bVar42;
  int *piVar41;
  undefined4 *puVar43;
  int *piVar44;
  undefined4 uStack0000001c;
  undefined4 uStack00000020;
  undefined1 local_2b8 [4];
  uint local_2b4;
  char local_2b0 [4];
  char local_2ac [2];
  undefined4 local_2aa;
  char local_2a6 [6];
  undefined2 local_2a0;
  undefined1 uStack_29e;
  uint local_296;
  char local_292 [4];
  char local_28e [2];
  uint local_28c;
  char local_288 [4];
  char local_284 [2];
  uint local_282;
  char local_27e [4];
  char local_27a;
  undefined1 auStack_278 [15];
  undefined1 auStack_269 [15];
  undefined1 auStack_25a [15];
  undefined1 auStack_24b [15];
  undefined1 auStack_23c [32];
  undefined1 auStack_21c [32];
  undefined1 auStack_1fc [32];
  undefined1 auStack_1dc [32];
  undefined1 auStack_1bc [32];
  undefined1 auStack_19c [32];
  undefined1 auStack_17c [32];
  char acStack_15c [100];
  int local_f8;
  int local_f4;
  int local_f0;
  uint local_ec;
  int local_e8;
  uint local_e4;
  uint local_e0;
  uint local_dc;
  uint local_d8;
  uint local_d4;
  uint local_d0;
  undefined1 *local_cc;
  uint *local_c8;
  uint local_c4;
  uint local_c0;
  uint local_bc;
  uint local_b8;
  uint local_b4;
  uint local_b0;
  uint local_ac;
  uint local_a8;
  int local_a4;
  uint local_a0;
  uint local_9c;
  uint local_98;
  uint local_94;
  uint local_90;
  uint local_8c;
  uint local_88;
  uint local_84;
  uint local_80;
  int local_7c;
  uint local_78;
  uint local_74;
  int local_70;
  undefined2 local_6c;
  undefined1 *local_68;
  undefined1 *local_64;
  undefined1 *local_60;
  int local_5c;
  
  uStack0000001c = param_2;
  uStack00000020 = param_3;
  ((int (*)())FUN_000d0b68)(param_1,1);
  if ((*(byte *)((int)param_1 + 0xf) & 0x10) == 0) {
    local_a0 = param_1[2];
    ((int (*)())FUN_000d03b4)(0,"======== Begin Loki NSF pixel shader dump: %s: %d ========\n",uStack0000001c,
                 uStack00000020);
    if (*(short *)(param_1 + 5) == 0) {
      ((int (*)())FUN_000d03b4)(0," Shader stats not valid\n \n");
    }
    else {
      iVar34 = 0;
      ((int (*)())FUN_000d03b4)(0," Shader stats:\n");
      ((int (*)())FUN_000d03b4)(0,"     Levels:                 %2d\n",*(undefined2 *)((int)param_1 + 0x16));
      ((int (*)())FUN_000d03b4)(0,"     RS Instructions:        %2d\n",*(undefined2 *)(param_1 + 6));
      ((int (*)())FUN_000d03b4)(0,"     TEX Instructions:      %3d\n",*(undefined2 *)((int)param_1 + 0x1a));
      ((int (*)())FUN_000d03b4)(0,"     ALU Instructions:      %3d\n",*(undefined2 *)(param_1 + 7));
      ((int (*)())FUN_000d03b4)(0,"     ALU Instruction slots: %3d\n",*(undefined2 *)((int)param_1 + 0x1e));
      ((int (*)())FUN_000d03b4)(0,"     Pix Size:               %2d\n",*(undefined2 *)((int)param_1 + 0x22));
      ((int (*)())FUN_000d03b4)(0,"     Highest Const:          %2d\n",*(undefined2 *)(param_1 + 9));
      ((int (*)())FUN_000d03b4)(0,"     Nominal cycle count:    %2d\n",*(undefined2 *)((int)param_1 + 0x26));
      ((int (*)())FUN_000d03b4)(0,"     Tex lookup counts:     ");
      puVar43 = param_1;
      do {
        ((int (*)())FUN_000d03b4)(0," %2d",*(undefined1 *)((int)puVar43 + 0x2a));
        bVar2 = iVar34 != 0xf;
        puVar43 = (undefined4 *)((int)puVar43 + 1);
        iVar34 = iVar34 + 1;
      } while (bVar2);
      ((int (*)())FUN_000d03b4)(0,"\n \n");
    }
    ((int (*)())FUN_000d03b4)(0," RS Instructions:\n \n");
    if ((param_1[0x12] == 1) && (local_a0 != 0)) {
      piVar41 = param_1 + 0x24;
      uVar36 = 1;
      piVar37 = piVar41;
      piVar44 = param_1 + 0x12;
      do {
        piVar40 = piVar37;
        ((int (*)())FUN_000d03b4)(0,"   rs %02d:",uVar36 - 1);
        if (*(char *)((int)piVar44 + 0xb) == '\0') {
          if (*(char *)((int)piVar44 + 9) != '\0') {
            ((int (*)())FUN_000d03b4)(0,"                         ");
            goto LAB_000d3b80;
          }
LAB_000d3be0:
          ((int (*)())FUN_000d03b4)(0,"\n");
        }
        else {
          ((int (*)())FUN_000d03b4)(0,"  r%02d.%s = col%02ld",*(undefined2 *)((int)piVar44 + 6),
                       (*(byte *)((int)piVar44 + 0xf) & 0xf ^ 0xf) * 5 + 0x1dc279,
                       *(undefined1 *)((int)piVar44 + 10));
          if (*(char *)((int)piVar44 + 0xd) == '\0') {
            if (*(char *)((int)piVar44 + 0xb) == '\x02') {
              ((int (*)())FUN_000d03b4)(0," fbuf  ");
            }
            else if (*(char *)((int)piVar44 + 0xb) == '\x03') {
              ((int (*)())FUN_000d03b4)(0," back  ");
            }
            else {
              if (*(char *)((int)piVar44 + 9) == '\0') goto LAB_000d3be0;
              ((int (*)())FUN_000d03b4)(0,"       ");
            }
          }
          else {
            ((int (*)())FUN_000d03b4)(0," biased");
          }
LAB_000d3b80:
          if ((*(char *)((int)piVar44 + 9) == '\0') ||
             (((int (*)())FUN_000d03b4)(0,"   r%02d.%s = txc%02ld",*(undefined2 *)(piVar44 + 1),
                           (*(byte *)((int)piVar44 + 0xe) & 0xf ^ 0xf) * 5 + 0x1dc279,
                           *(undefined1 *)(piVar44 + 2)), *(char *)(piVar44 + 3) == '\0'))
          goto LAB_000d3be0;
          ((int (*)())FUN_000d03b4)(0," adjusted\n");
        }
        uVar36 = uVar36 + 1;
        if (*piVar41 != 1) break;
        piVar41 = piVar41 + 0x12;
        piVar37 = piVar40 + 0x12;
        piVar44 = piVar40;
      } while (uVar36 <= local_a0);
    }
    else {
      uVar36 = 1;
    }
    ((int (*)())FUN_000d03b4)(0," \n US Program:\n");
    if (uVar36 <= local_a0) {
      uVar35 = 0;
      puVar38 = param_1 + uVar36 * 0x12;
      local_a8 = 1;
      local_a4 = 0;
      local_e8 = 0;
      do {
        uVar19 = *puVar38;
        if (((uVar19 == 2) && ((local_a8 != 0 || (*(char *)(puVar38 + 8) != '\0')))) ||
           (uVar35 == 0)) {
          if (uVar35 < 0x34) {
            (*(unsigned short *)((unsigned char *)&(local_2b8) + 1)) = (ushort)(*(unsigned int *)((unsigned char *)&(local_2b8) + 0)) & 0xff;
          }
          else {
            (*(unsigned short *)((unsigned char *)&(local_2b8) + 1)) = (ushort)(byte)((char)(uVar35 / 0x34) + 0x2f) << 8;
          }
          local_2b8[0] = (char)(uVar35 % 0x34);
          if (uVar35 % 0x34 < 0x1a) {
            local_2b8[0] = local_2b8[0] + 'A';
          }
          else {
            local_2b8[0] = local_2b8[0] + 'G';
          }
          ((int (*)())FUN_000d03b4)(0," \n   Level %s:\n",local_2b8);
          uVar35 = uVar35 + 1;
          uVar19 = *puVar38;
        }
        local_a8 = (uint)(uVar19 - 3 < 2);
        if (uVar19 == 2) {
          ((int (*)())FUN_000d03b4)(0,"     tex %02d    :  ",local_e8);
          uVar9 = *(undefined2 *)((int)puVar38 + 0xe);
          uVar4 = *(undefined1 *)((int)puVar38 + 0x19);
          if ((*(byte *)((int)puVar38 + 0x1a) < 5) &&
             ((1 << ((int)(char)*(byte *)((int)puVar38 + 0x1a) & 0x3fU) & 0x1aU) != 0)) {
            ((int (*)())FUN_000d03b4)(0,"r%02d.rgba = ",*(undefined2 *)(puVar38 + 3));
          }
          uVar19 = *(byte *)((int)puVar38 + 0x1f) & 0xf ^ 0xf;
          switch(*(undefined1 *)((int)puVar38 + 0x1a)) {
          case 0:
            ((int (*)())FUN_000d03b4)(0,"NOP\n");
            break;
          case 1:
            ((int (*)())FUN_000d03b4)(0,"lookup(r%02d.%s, tex%02d)\n",uVar9,uVar19 * 5 + 0x1dc279,uVar4);
            break;
          case 2:
            ((int (*)())FUN_000d03b4)(0,"kill(r%02d.%s)\n",uVar9,uVar19 * 5 + 0x1dc279);
            break;
          case 3:
            ((int (*)())FUN_000d03b4)(0,"lookup_proj(r%02d.%s, tex%02d)\n",uVar9,uVar19 * 5 + 0x1dc279,uVar4);
            break;
          case 4:
            ((int (*)())FUN_000d03b4)(0,"lookup_lodbias(r%02d.%s, tex%02d)\n",uVar9,uVar19 * 5 + 0x1dc279,uVar4);
            break;
          default:
            ((int (*)())FUN_000d03b4)(0,"???()\n");
          }
          local_e8 = local_e8 + 1;
        }
        else if ((1 < uVar19) && (uVar19 < 5)) {
          local_cc = (undefined1 *)((int)puVar38 + 0x31);
          switch(*(undefined1 *)((int)puVar38 + 0x31)) {
          case 0:
          case 3:
          case 7:
          case 8:
            bVar1 = false;
            bVar2 = false;
            bVar42 = true;
            bVar29 = true;
            bVar28 = true;
            break;
          case 1:
          case 4:
          case 5:
            bVar1 = false;
            bVar2 = false;
            bVar42 = true;
            bVar29 = true;
            bVar28 = false;
            break;
          case 2:
            bVar1 = true;
            bVar2 = true;
            bVar42 = true;
            bVar29 = true;
            bVar28 = false;
            break;
          default:
            bVar1 = false;
            bVar2 = false;
            bVar42 = false;
            bVar29 = false;
            bVar28 = false;
            break;
          case 9:
            bVar1 = false;
            bVar2 = false;
            bVar42 = true;
            bVar29 = false;
            bVar28 = false;
          }
          bVar17 = false;
          local_c8 = puVar38 + 0x10;
          if (*(byte *)(puVar38 + 0x10) < 0xc) {
            uVar19 = 1 << ((int)(char)*(byte *)(puVar38 + 0x10) & 0x3fU);
            if ((uVar19 & 0x61) == 0) {
              if ((uVar19 & 0xc) == 0) {
                if ((uVar19 & 0xf80) != 0) {
                  bVar17 = false;
                  bVar2 = true;
                }
              }
              else {
                bVar17 = false;
                bVar1 = true;
                bVar2 = true;
              }
            }
            else {
              bVar17 = true;
              bVar1 = true;
              bVar2 = true;
            }
          }
          local_ac = (uint)*(byte *)((int)puVar38 + 0x3b);
          uVar9 = *(undefined2 *)((int)puVar38 + 0xe);
          uVar10 = *(undefined2 *)(puVar38 + 4);
          uVar11 = *(undefined2 *)((int)puVar38 + 0x12);
          uVar12 = *(undefined2 *)((int)puVar38 + 0x1a);
          uVar13 = *(undefined2 *)(puVar38 + 7);
          uVar14 = *(undefined2 *)((int)puVar38 + 0x1e);
          uVar33 = (uint)*(byte *)((int)puVar38 + 0x2a);
          uVar32 = (uint)*(byte *)((int)puVar38 + 0x2b);
          uVar31 = (uint)*(byte *)(puVar38 + 0xb);
          uVar30 = (uint)*(byte *)((int)puVar38 + 0x39);
          uVar19 = (uint)*(byte *)((int)puVar38 + 0x3a);
          local_b0 = (uint)*(byte *)((int)puVar38 + 0x2d);
          local_b4 = (uint)*(byte *)((int)puVar38 + 0x2e);
          local_b8 = (uint)*(byte *)((int)puVar38 + 0x2f);
          local_bc = (uint)*(byte *)(puVar38 + 0xf);
          local_c0 = (uint)*(byte *)((int)puVar38 + 0x3d);
          local_c4 = (uint)*(byte *)((int)puVar38 + 0x3e);
          bVar27 = bVar42 && uVar33 - 0xf < 4;
          bVar42 = bVar42 && uVar33 == 0x13;
          if (bVar29) {
            bVar27 = bVar27 || uVar32 - 0xf < 4;
            bVar42 = bVar42 || uVar32 == 0x13;
          }
          if (bVar28) {
            bVar27 = (bool)(bVar27 | uVar31 - 0xf < 4);
            bVar42 = (bool)(bVar42 | uVar31 == 0x13);
          }
          if (bVar2) {
            bVar27 = (bool)(bVar27 | uVar30 - 0xc < 3);
            bVar42 = (bool)(bVar42 | uVar30 == 0xf);
          }
          if (bVar1) {
            bVar27 = (bool)(bVar27 | uVar19 - 0xc < 3);
            bVar42 = (bool)(bVar42 | uVar19 == 0xf);
          }
          if (bVar17) {
            bVar27 = (bool)(bVar27 | local_ac - 0xc < 3);
            bVar42 = (bool)(bVar42 | local_ac == 0xf);
          }
          if (bVar27) {
            ((int (*)())FUN_000d03b4)(0,"     alu %02d pre:  srcp.rgb = ",local_a4);
            cVar20 = *(char *)(puVar38 + 0xc);
            if (cVar20 == '\x01') {
              ((int (*)())FUN_000d0450)(&local_2aa,uVar9);
              ((int (*)())FUN_000d0450)(&local_2a0,uVar10);
              ((int (*)())FUN_000d03b4)(0,"%s.rgb-%s.rgb\n",&local_2a0,&local_2aa);
            }
            else if (cVar20 == '\0') {
              ((int (*)())FUN_000d0450)(&local_2aa,uVar9);
              ((int (*)())FUN_000d03b4)(0,"1.0-2.0*%s.rgb\n",&local_2aa);
            }
            else if (cVar20 == '\x02') {
              ((int (*)())FUN_000d0450)(&local_2aa,uVar9);
              ((int (*)())FUN_000d0450)(&local_2a0,uVar10);
              ((int (*)())FUN_000d03b4)(0,"%s.rgb+%s.rgb\n",&local_2a0,&local_2aa);
            }
            else if (cVar20 == '\x03') {
              ((int (*)())FUN_000d0450)(&local_2aa,uVar9);
              ((int (*)())FUN_000d03b4)(0,"1.0-%s.rgb\n",&local_2aa);
            }
            else {
              ((int (*)())FUN_000d03b4)(0,"???\n");
            }
          }
          if (bVar42) {
            ((int (*)())FUN_000d03b4)(0,"     alu %02d pre:  srcp.a   = ",local_a4);
            cVar20 = *(char *)((int)puVar38 + 0x3f);
            if (cVar20 == '\x01') {
              ((int (*)())FUN_000d0450)(&local_2aa,uVar12);
              ((int (*)())FUN_000d0450)(&local_2a0,uVar13);
              ((int (*)())FUN_000d03b4)(0,"%s.a-%s.a\n",&local_2a0,&local_2aa);
            }
            else if (cVar20 == '\0') {
              ((int (*)())FUN_000d0450)(&local_2aa,uVar12);
              ((int (*)())FUN_000d03b4)(0,"1.0-2.0*%s.a\n",&local_2aa);
            }
            else if (cVar20 == '\x02') {
              ((int (*)())FUN_000d0450)(&local_2aa,uVar12);
              ((int (*)())FUN_000d0450)(&local_2a0,uVar13);
              ((int (*)())FUN_000d03b4)(0,"%s.a+%s.a\n",&local_2a0,&local_2aa);
            }
            else if (cVar20 == '\x03') {
              ((int (*)())FUN_000d0450)(&local_2aa,uVar12);
              ((int (*)())FUN_000d03b4)(0,"1.0-%s.a\n",&local_2aa);
            }
            else {
              ((int (*)())FUN_000d03b4)(0,"???\n");
            }
          }
          ((int (*)())FUN_000d03b4)(0,"     alu %02d rgb:  ",local_a4);
          bVar3 = *(byte *)(puVar38 + 5);
          if (*(byte *)((int)puVar38 + 0x15) == 0) {
            ((int (*)())FUN_000d03b4)(0,"           ");
          }
          else {
            ((int (*)())FUN_000d03b4)(0,"out%d.%s = ",*(undefined1 *)((int)puVar38 + 0x16),
                         (uint)*(byte *)((int)puVar38 + 0x15) * 4 + 0x1dc239);
          }
          if (bVar3 == 0) {
            ((int (*)())FUN_000d03b4)(0,"          ");
          }
          else {
            ((int (*)())FUN_000d03b4)(0,"r%02d.%s = ",*(undefined2 *)(puVar38 + 3),(uint)bVar3 * 4 + 0x1dc239);
          }
          if (*(char *)((int)puVar38 + 0x33) != '\0') {
            ((int (*)())FUN_000d03b4)(0,"clamped ");
          }
          local_68 = auStack_1fc;
          local_64 = auStack_1dc;
          ((int (*)())FUN_000d0488)(local_68,uVar9,uVar10,uVar11,uVar12,uVar13,uVar14,uVar33);
          local_60 = auStack_1bc;
          ((int (*)())FUN_000d0488)(local_64,uVar9,uVar10,uVar11,uVar12,uVar13,uVar14,uVar32);
          ((int (*)())FUN_000d0488)(local_60,uVar9,uVar10,uVar11,uVar12,uVar13,uVar14,uVar31);
          ((int (*)())FUN_000d0888)(auStack_19c,uVar9,uVar10,uVar11,uVar12,uVar13,uVar14,uVar30);
          ((int (*)())FUN_000d0888)(auStack_17c,uVar9,uVar10,uVar11,uVar12,uVar13,uVar14,uVar19);
          ((int (*)())FUN_000d0888)(auStack_23c,uVar9,uVar10,uVar11,uVar12,uVar13,uVar14,local_ac);
          switch(*local_cc) {
          case 0:
            ((int (*)())FUN_000d03b4)(0,"mad(%s, %s, %s)",local_68,local_64,local_60);
            break;
          case 1:
            ((int (*)())FUN_000d03b4)(0,"dp3(%s, %s)",local_68,local_64);
            break;
          case 2:
            ((int (*)())FUN_000d03b4)(0,"dp4(%s:%s, %s:%s)",local_68,auStack_19c,local_64,auStack_17c);
            break;
          case 3:
            ((int (*)())FUN_000d03b4)(0,"d2a(%s, %s, %s)",local_68,local_64,local_60);
            break;
          case 4:
            ((int (*)())FUN_000d03b4)(0,"min(%s, %s)",local_68,local_64);
            break;
          case 5:
            ((int (*)())FUN_000d03b4)(0,"max(%s, %s)",local_68,local_64);
            break;
          default:
            ((int (*)())FUN_000d03b4)(0,"???()");
            break;
          case 7:
            ((int (*)())FUN_000d03b4)(0,"cnd(%s, %s, %s)",local_68,local_64,local_60);
            break;
          case 8:
            ((int (*)())FUN_000d03b4)(0,"cmp(%s, %s, %s)",local_68,local_64,local_60);
            break;
          case 9:
            ((int (*)())FUN_000d03b4)(0,"frc(%s)",local_68);
            break;
          case 10:
            ((int (*)())FUN_000d03b4)(0,"sop()");
          }
          switch(*(undefined1 *)((int)puVar38 + 0x32)) {
          case 0:
            ((int (*)())FUN_000d03b4)(0,"\n");
            break;
          case 1:
            ((int (*)())FUN_000d03b4)(0,"*2\n");
            break;
          case 2:
            ((int (*)())FUN_000d03b4)(0,"*4\n");
            break;
          case 3:
            ((int (*)())FUN_000d03b4)(0,"*8\n");
            break;
          case 4:
            ((int (*)())FUN_000d03b4)(0,"/2\n");
            break;
          case 5:
            ((int (*)())FUN_000d03b4)(0,"/4\n");
            break;
          case 6:
            ((int (*)())FUN_000d03b4)(0,"/8\n");
            break;
          default:
            ((int (*)())FUN_000d03b4)(0,"*???\n");
          }
          ((int (*)())FUN_000d03b4)(0,"          alpha:  ",local_a4);
          cVar20 = *(char *)(puVar38 + 8);
          bVar2 = *(char *)((int)puVar38 + 0x21) != '\0';
          cVar6 = *(char *)((int)puVar38 + 0x23);
          if (bVar2) {
            ((int (*)())FUN_000d03b4)(0,"out%d.a   = ",*(undefined1 *)((int)puVar38 + 0x22));
          }
          bVar1 = cVar6 != '\0';
          if (bVar1) {
            ((int (*)())FUN_000d03b4)(0,"depth    = ");
          }
          if ((!bVar2) && (!bVar1)) {
            ((int (*)())FUN_000d03b4)(0,"           ");
          }
          if (cVar20 == '\0') {
            ((int (*)())FUN_000d03b4)(0,"          ");
          }
          else {
            ((int (*)())FUN_000d03b4)(0,"r%02d.a   = ",*(undefined2 *)(puVar38 + 6));
          }
          if (*(char *)((int)puVar38 + 0x42) != '\0') {
            ((int (*)())FUN_000d03b4)(0,"clamped ");
          }
          switch(*(undefined1 *)local_c8) {
          case 0:
            ((int (*)())FUN_000d03b4)(0,"mad(%s, %s, %s)",auStack_19c,auStack_17c,auStack_23c);
            break;
          case 1:
            ((int (*)())FUN_000d03b4)(0,"dp()");
            break;
          case 2:
            ((int (*)())FUN_000d03b4)(0,"min(%s, %s)",auStack_19c,auStack_17c);
            break;
          case 3:
            ((int (*)())FUN_000d03b4)(0,"max(%s, %s)",auStack_19c,auStack_17c);
            break;
          default:
            ((int (*)())FUN_000d03b4)(0,"???()");
            break;
          case 5:
            ((int (*)())FUN_000d03b4)(0,"cnd(%s, %s, %s)",auStack_19c,auStack_17c,auStack_23c);
            break;
          case 6:
            ((int (*)())FUN_000d03b4)(0,"cmp(%s, %s, %s)",auStack_19c,auStack_17c,auStack_23c);
            break;
          case 7:
            ((int (*)())FUN_000d03b4)(0,"frc(%s)",auStack_19c);
            break;
          case 8:
            ((int (*)())FUN_000d03b4)(0,"ex2(%s)",auStack_19c);
            break;
          case 9:
            ((int (*)())FUN_000d03b4)(0,"ln2(%s)",auStack_19c);
            break;
          case 10:
            ((int (*)())FUN_000d03b4)(0,"rcp(%s)",auStack_19c);
            break;
          case 0xb:
            ((int (*)())FUN_000d03b4)(0,"rsq(%s)",auStack_19c);
          }
          switch(*(undefined1 *)((int)puVar38 + 0x41)) {
          case 0:
            ((int (*)())FUN_000d03b4)(0,"\n");
            break;
          case 1:
            ((int (*)())FUN_000d03b4)(0,"*2\n");
            break;
          case 2:
            ((int (*)())FUN_000d03b4)(0,"*4\n");
            break;
          case 3:
            ((int (*)())FUN_000d03b4)(0,"*8\n");
            break;
          case 4:
            ((int (*)())FUN_000d03b4)(0,"/2\n");
            break;
          case 5:
            ((int (*)())FUN_000d03b4)(0,"/4\n");
            break;
          case 6:
            ((int (*)())FUN_000d03b4)(0,"/8\n");
            break;
          default:
            ((int (*)())FUN_000d03b4)(0,"*???\n");
          }
          if (*(char *)(puVar38 + 0xd) != '\0') {
            ((int (*)())FUN_000d03b4)(0,"     alu %02d post-NOP\n",local_a4);
          }
          local_a4 = local_a4 + 1;
        }
        uVar36 = uVar36 + 1;
        puVar38 = puVar38 + 0x12;
      } while (uVar36 <= local_a0);
    }
    uVar35 = 0;
    ((int (*)())FUN_000d03b4)(0,"======== End   Loki NSF pixel shader dump: %s: %d ========\n",uStack0000001c,
                 uStack00000020);
    uVar36 = param_1[2];
    ((int (*)())FUN_000d03b4)(0,"+++ BEGIN_PSN                       # \"%s\" %d\n",uStack0000001c,uStack00000020
                );
    do {
      switch(*param_1) {
      case 0:
        ((int (*)())FUN_000d03b4)(0,
                     "+++ R300PSN_INST_HEADER : %08x %08x %02x %02x %04x %04x %04x %04x %04x %04x %04x\n"
                     ,param_1[1],param_1[2],*(undefined1 *)(param_1 + 3),
                     *(undefined1 *)((int)param_1 + 0xd),*(undefined2 *)(param_1 + 5),
                     *(undefined2 *)((int)param_1 + 0x16));
        break;
      case 1:
        ((int (*)())FUN_000d03b4)(0,
                     "+++ R300PSN_INST_RS     : %04x %04x %02x %02x %02x %02x %02x %02x %02x %02x\n"
                     ,*(undefined2 *)(param_1 + 1),*(undefined2 *)((int)param_1 + 6),
                     *(undefined1 *)(param_1 + 2),*(undefined1 *)((int)param_1 + 9),
                     *(undefined1 *)((int)param_1 + 10),*(undefined1 *)((int)param_1 + 0xb));
        break;
      case 2:
        ((int (*)())FUN_000d03b4)(0,"+++ R300PSN_INST_TEX    : %04x %04x %02x %02x %02x %02x\n",
                     *(undefined2 *)(param_1 + 3),*(undefined2 *)((int)param_1 + 0xe),
                     *(undefined1 *)((int)param_1 + 0x19),*(undefined1 *)((int)param_1 + 0x1a),
                     *(undefined1 *)((int)param_1 + 0x1f),*(undefined1 *)(param_1 + 8));
        break;
      case 3:
      case 4:
        ((int (*)())FUN_000d03b4)(0,"+++ R300PSN_INST_ALU    : \n");
        ((int (*)())FUN_000d03b4)(0,"+++ RGB_ADDR            : %04x %04x %04x %04x %02x %02x %02x\n",
                     *(undefined2 *)(param_1 + 3),*(undefined2 *)((int)param_1 + 0xe),
                     *(undefined2 *)(param_1 + 4),*(undefined2 *)((int)param_1 + 0x12),
                     *(undefined1 *)(param_1 + 5),*(undefined1 *)((int)param_1 + 0x15));
        ((int (*)())FUN_000d03b4)(0,"+++ ALPHA_ADDR          : %04x %04x %04x %04x %02x %02x %02x %02x\n",
                     *(undefined2 *)(param_1 + 6),*(undefined2 *)((int)param_1 + 0x1a),
                     *(undefined2 *)(param_1 + 7),*(undefined2 *)((int)param_1 + 0x1e),
                     *(undefined1 *)(param_1 + 8),*(undefined1 *)((int)param_1 + 0x21));
        ((int (*)())FUN_000d03b4)(0,
                     "+++ RGB_INST            : %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x\n"
                     ,*(undefined1 *)((int)param_1 + 0x2a),*(undefined1 *)((int)param_1 + 0x2d),
                     *(undefined1 *)((int)param_1 + 0x2b),*(undefined1 *)((int)param_1 + 0x2e),
                     *(undefined1 *)(param_1 + 0xb),*(undefined1 *)((int)param_1 + 0x2f));
        ((int (*)())FUN_000d03b4)(0,
                     "+++ ALPHA_INST          : %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x\n"
                     ,*(undefined1 *)((int)param_1 + 0x39),*(undefined1 *)(param_1 + 0xf),
                     *(undefined1 *)((int)param_1 + 0x3a),*(undefined1 *)((int)param_1 + 0x3d),
                     *(undefined1 *)((int)param_1 + 0x3b),*(undefined1 *)((int)param_1 + 0x3e));
      }
      uVar35 = uVar35 + 1;
      param_1 = param_1 + 0x12;
    } while (uVar35 <= uVar36);
    ((int (*)())FUN_000d03b4)(0,"+++ END_PSN                         # \"%s\" %d\n",uStack0000001c,uStack00000020
                );
  }
  else {
    local_7c = param_1[2];
    ((int (*)())FUN_000d03b4)(0,"======== Begin r520 neutral format pixel shader: %d =============\n",
                 uStack00000020);
    if (*(short *)(param_1 + 5) == 0) {
      ((int (*)())FUN_000d03b4)(0," Shader stats not valid\n \n");
    }
    else {
      ((int (*)())FUN_000d03b4)(0," Shader stats:\n");
      ((int (*)())FUN_000d03b4)(0,"     RS Instructions:        %2d\n",*(undefined2 *)(param_1 + 6));
      ((int (*)())FUN_000d03b4)(0,"     TEX Instructions:      %3d\n",*(undefined2 *)((int)param_1 + 0x1a));
      ((int (*)())FUN_000d03b4)(0,"     ALU Instructions:      %3d\n",*(undefined2 *)(param_1 + 7));
      ((int (*)())FUN_000d03b4)(0,"     ALU Instruction slots: %3d\n",*(undefined2 *)((int)param_1 + 0x1e));
      if (*(char *)((int)param_1 + 0xe) != '\0') {
        ((int (*)())FUN_000d03b4)(0,"     UMRT_EN:               %3d\n");
      }
      ((int (*)())FUN_000d03b4)(0,"     CF Instructions:       %3d\n",*(undefined2 *)(param_1 + 8));
      ((int (*)())FUN_000d03b4)(0,"     Pix Size:               %2d\n",*(undefined2 *)((int)param_1 + 0x22));
      ((int (*)())FUN_000d03b4)(0,"     Highest Const:          %2d\n",*(undefined2 *)(param_1 + 9));
      ((int (*)())FUN_000d03b4)(0,"     Start Addr:            %3d\n",*(undefined2 *)(param_1 + 4));
      ((int (*)())FUN_000d03b4)(0,"     End Addr:              %3d\n",*(undefined2 *)((int)param_1 + 0x12));
      ((int (*)())FUN_000d03b4)(0," \n");
    }
    ((int (*)())FUN_000d03b4)(0," RS Instructions:\n \n");
    if ((param_1[0x12] == 1) && (0 < local_7c)) {
      piVar41 = param_1 + 0x24;
      iVar34 = 1;
      piVar37 = piVar41;
      piVar44 = param_1 + 0x12;
      do {
        piVar40 = piVar37;
        ((int (*)())FUN_000d03b4)(0,"   rs %02d:",iVar34 + -1);
        cVar20 = *(char *)((int)piVar44 + 0xb);
        if (cVar20 == '\0') {
          if (*(char *)((int)piVar44 + 9) != '\0') {
            ((int (*)())FUN_000d03b4)(0,"                         ");
            goto LAB_000d1afc;
          }
LAB_000d1b5c:
          ((int (*)())FUN_000d03b4)(0,"\n");
        }
        else {
          uVar36 = *(byte *)((int)piVar44 + 0xf) & 0xf ^ 0xf;
          if (cVar20 == '\x01') {
            ((int (*)())FUN_000d03b4)(0,"  r%02d.%s = col%02ld",*(undefined2 *)((int)piVar44 + 6),
                         uVar36 * 5 + 0x1dc279,*(undefined1 *)((int)piVar44 + 10));
            if (*(char *)((int)piVar44 + 0xd) == '\0') {
              cVar20 = *(char *)((int)piVar44 + 0xb);
            }
            else {
              ((int (*)())FUN_000d03b4)(0," biased");
              cVar20 = *(char *)((int)piVar44 + 0xb);
            }
          }
          if (cVar20 == '\x02') {
            ((int (*)())FUN_000d03b4)(0,"  r%02d.%s = fbuf",*(undefined2 *)((int)piVar44 + 6),
                         uVar36 * 5 + 0x1dc279);
          }
          else if (cVar20 == '\x03') {
            ((int (*)())FUN_000d03b4)(0,"  r%02d.%s = back",*(undefined2 *)((int)piVar44 + 6),
                         uVar36 * 5 + 0x1dc279);
          }
          else {
            if (*(char *)((int)piVar44 + 9) == '\0') goto LAB_000d1b5c;
            ((int (*)())FUN_000d03b4)(0,"       ");
          }
LAB_000d1afc:
          if ((*(char *)((int)piVar44 + 9) == '\0') ||
             (((int (*)())FUN_000d03b4)(0,"   r%02d.%s = txc%02ld",*(undefined2 *)(piVar44 + 1),
                           (*(byte *)((int)piVar44 + 0xe) & 0xf ^ 0xf) * 5 + 0x1dc279,
                           *(undefined1 *)(piVar44 + 2)), *(char *)(piVar44 + 3) == '\0'))
          goto LAB_000d1b5c;
          ((int (*)())FUN_000d03b4)(0," adjusted\n");
        }
        iVar34 = iVar34 + 1;
        if (*piVar41 != 1) break;
        piVar41 = piVar41 + 0x12;
        piVar37 = piVar40 + 0x12;
        piVar44 = piVar40;
      } while (iVar34 <= local_7c);
    }
    else {
      iVar34 = 1;
    }
    local_5c = 0x1a1848;
    ((int (*)())FUN_000d03b4)(0," \n US Program:\n");
    ((int (*)())FUN_000d03b4)(0,local_5c + 0x5b00);
    if (iVar34 <= local_7c) {
      local_78 = 0;
      piVar37 = param_1 + iVar34 * 0x12;
      local_70 = 0;
      local_f0 = 0;
      local_f4 = 0;
      local_f8 = 0;
      local_74 = 0;
      local_ec = 0;
      do {
        if (*(char *)(piVar37 + 7) == '\0') {
          local_282 = local_282 & 0xffffff;
        }
        else {
          (*(unsigned char *)((unsigned char *)&(local_282) + 0)) = s_ign_unc_001a734c[0];
          (*(unsigned char *)((unsigned char *)&(local_282) + 1)) = s_ign_unc_001a734c[1];
          (*(unsigned char *)((unsigned char *)&(local_282) + 2)) = s_ign_unc_001a734c[2];
          (*(unsigned char *)((unsigned char *)&(local_282) + 3)) = s_ign_unc_001a734c[3];
          local_27e[0] = s_ign_unc_001a734c[4];
          local_27e[1] = s_ign_unc_001a734c[5];
          local_27e[2] = s_ign_unc_001a734c[6];
          local_27e[3] = s_ign_unc_001a734c[7];
          local_27a = s_ign_unc_001a734c[8];
        }
        if (*(char *)(piVar37 + 1) == '\0') {
          local_2b4 = local_2b4 & 0xffffff;
        }
        else {
          (*(unsigned char *)((unsigned char *)&(local_2b4) + 0)) = s_sem_wait_001a7358[0];
          (*(unsigned char *)((unsigned char *)&(local_2b4) + 1)) = s_sem_wait_001a7358[1];
          (*(unsigned char *)((unsigned char *)&(local_2b4) + 2)) = s_sem_wait_001a7358[2];
          (*(unsigned char *)((unsigned char *)&(local_2b4) + 3)) = s_sem_wait_001a7358[3];
          local_2b0[0] = s_sem_wait_001a7358[4];
          local_2b0[1] = s_sem_wait_001a7358[5];
          local_2b0[2] = s_sem_wait_001a7358[6];
          local_2b0[3] = s_sem_wait_001a7358[7];
          local_2ac[0] = s_sem_wait_001a7358[8];
          local_2ac[1] = s_sem_wait_001a7358[9];
        }
        if (*(char *)((int)piVar37 + 0xb) == '\0') {
          local_28c = local_28c & 0xffffff;
        }
        else {
          (*(unsigned char *)((unsigned char *)&(local_28c) + 0)) = s_alu_wait_001a7364[0];
          (*(unsigned char *)((unsigned char *)&(local_28c) + 1)) = s_alu_wait_001a7364[1];
          (*(unsigned char *)((unsigned char *)&(local_28c) + 2)) = s_alu_wait_001a7364[2];
          (*(unsigned char *)((unsigned char *)&(local_28c) + 3)) = s_alu_wait_001a7364[3];
          local_288[0] = s_alu_wait_001a7364[4];
          local_288[1] = s_alu_wait_001a7364[5];
          local_288[2] = s_alu_wait_001a7364[6];
          local_288[3] = s_alu_wait_001a7364[7];
          local_284[0] = s_alu_wait_001a7364[8];
          local_284[1] = s_alu_wait_001a7364[9];
        }
        iVar18 = *piVar37;
        if (iVar18 == 2) {
          ((int (*)())FUN_000d03b4)(0,"  %d tex %02d    :  ",local_70,local_f4);
          bVar3 = *(byte *)((int)piVar37 + 0x1d);
          uVar8 = *(ushort *)((int)piVar37 + 0xe);
          uVar9 = *(undefined2 *)(piVar37 + 3);
          uVar4 = *(undefined1 *)((int)piVar37 + 0x19);
          bVar2 = (bVar3 & 1) != 0;
          bVar5 = *(byte *)(piVar37 + 5);
          if (bVar2) {
            pcVar23 = (char *)((bVar5 >> 4 & 0xc) + 0x1dc259);
          }
          else {
            pcVar23 = "_";
          }
          bVar1 = (bVar3 & 2) != 0;
          if (bVar1) {
            pcVar24 = (char *)((bVar5 >> 2 & 0xc) + 0x1dc259);
          }
          else {
            pcVar24 = "_";
          }
          bVar42 = (bVar3 & 4) != 0;
          if (bVar42) {
            pcVar25 = (char *)((bVar5 & 0xc) + 0x1dc259);
          }
          else {
            pcVar25 = "_";
          }
          bVar28 = (((*(byte *)((int)piVar37 + 0x1e) & 0x1f) << 3 | (uint)bVar3) >> 3 & 1) != 0;
          if (bVar28) {
            pcVar26 = (char *)((bVar5 & 3) * 4 + 0x1dc259);
          }
          else {
            pcVar26 = "_";
          }
          FUN_001a32d0(auStack_25a,"%s%s%s%s",pcVar23,pcVar24,pcVar25,pcVar26);
          if ((*(byte *)((int)piVar37 + 0x1a) < 7) &&
             ((1 << ((int)(char)*(byte *)((int)piVar37 + 0x1a) & 0x3fU) & 0x7aU) != 0)) {
            ((int (*)())FUN_000d03b4)(0,"r%02d.%s = ",uVar9,auStack_25a);
          }
          if (*(char *)((int)piVar37 + 0x1a) == '\x02') {
            bVar3 = *(byte *)((int)piVar37 + 0x15);
            if (bVar2) {
              pcVar26 = (char *)((bVar3 >> 4 & 0xc) + 0x1dc259);
            }
            else {
              pcVar26 = "-";
            }
            if (bVar1) {
              pcVar23 = (char *)((bVar3 >> 2 & 0xc) + 0x1dc259);
            }
            else {
              pcVar23 = "-";
            }
            if (bVar42) {
              pcVar24 = (char *)((bVar3 & 0xc) + 0x1dc259);
            }
            else {
              pcVar24 = "-";
            }
            if (bVar28) {
              pcVar25 = (char *)((bVar3 & 3) * 4 + 0x1dc259);
            }
            else {
              pcVar25 = "-";
            }
          }
          else {
            local_78 = (uint)*(byte *)((int)piVar37 + 0x1f);
            bVar3 = *(byte *)((int)piVar37 + 0x15);
            if ((*(byte *)((int)piVar37 + 0x1f) & 1) == 0) {
              pcVar25 = (char *)((bVar3 & 3) * 4 + 0x1dc259);
              pcVar26 = (char *)((bVar3 >> 4 & 0xc) + 0x1dc259);
              pcVar23 = (char *)((bVar3 >> 2 & 0xc) + 0x1dc259);
              pcVar24 = (char *)((bVar3 & 0xc) + 0x1dc259);
            }
            else {
              pcVar26 = "-";
              pcVar23 = pcVar26;
              pcVar24 = pcVar26;
              pcVar25 = pcVar26;
            }
          }
          FUN_001a32d0(auStack_24b,"%s%s%s%s",pcVar26,pcVar23,pcVar24,pcVar25);
          if ((uVar8 & 0x4000) == 0) {
            FUN_001a32d0(auStack_278,"r%02d",uVar8);
          }
          else {
            FUN_001a32d0(auStack_278,"r[AL+%02d]");
          }
          if (*(char *)((int)piVar37 + 0x1b) == '\0') {
            local_296 = local_296 & 0xffffff;
          }
          else {
            (*(unsigned char *)((unsigned char *)&(local_296) + 0)) = s_sem_grab_001a73ac[0];
            (*(unsigned char *)((unsigned char *)&(local_296) + 1)) = s_sem_grab_001a73ac[1];
            (*(unsigned char *)((unsigned char *)&(local_296) + 2)) = s_sem_grab_001a73ac[2];
            (*(unsigned char *)((unsigned char *)&(local_296) + 3)) = s_sem_grab_001a73ac[3];
            local_292[0] = s_sem_grab_001a73ac[4];
            local_292[1] = s_sem_grab_001a73ac[5];
            local_292[2] = s_sem_grab_001a73ac[6];
            local_292[3] = s_sem_grab_001a73ac[7];
            local_28e[0] = s_sem_grab_001a73ac[8];
            local_28e[1] = s_sem_grab_001a73ac[9];
          }
          switch(*(char *)((int)piVar37 + 0x1a)) {
          case '\0':
            ((int (*)())FUN_000d03b4)(0,"NOP\n");
            break;
          case '\x01':
            ((int (*)())FUN_000d03b4)(0,"lookup(%s.%s, tex%02d)%s%s%s%s",auStack_278,auStack_24b,uVar4,&local_2b4
                         ,&local_296,&local_28c);
            break;
          case '\x02':
            ((int (*)())FUN_000d03b4)(0,"kill(%s.%s)%s%s%s",auStack_278,auStack_24b,&local_2b4,&local_296,
                         &local_28c);
            break;
          case '\x03':
            ((int (*)())FUN_000d03b4)(0,"lookup_proj(%s.%s, tex%02d)%s%s%s%s",auStack_278,auStack_24b,uVar4,
                         &local_2b4,&local_296,&local_28c);
            break;
          case '\x04':
            ((int (*)())FUN_000d03b4)(0,"lookup_lodbias(%s.%s, tex%02d)%s%s%s%s",auStack_278,auStack_24b,uVar4,
                         &local_2b4,&local_296,&local_28c);
            break;
          case '\x05':
            ((int (*)())FUN_000d03b4)(0,"lookup_lod(%s.%s, tex%02d)%s%s%s%s",auStack_278,auStack_24b,uVar4,
                         &local_2b4,&local_296,&local_28c);
            break;
          case '\x06':
            bVar3 = *(byte *)((int)piVar37 + 0x16);
            bVar2 = (local_78 & 1) == 0;
            if (bVar2) {
              pcVar25 = (char *)((bVar3 & 3) * 4 + 0x1dc259);
              pcVar26 = (char *)((bVar3 >> 4 & 0xc) + 0x1dc259);
              pcVar23 = (char *)((bVar3 >> 2 & 0xc) + 0x1dc259);
              pcVar24 = (char *)((bVar3 & 0xc) + 0x1dc259);
            }
            else {
              pcVar26 = "-";
              pcVar23 = pcVar26;
              pcVar24 = pcVar26;
              pcVar25 = pcVar26;
            }
            FUN_001a32d0(auStack_269,"%s%s%s%s",pcVar26,pcVar23,pcVar24,pcVar25);
            bVar3 = *(byte *)((int)piVar37 + 0x16);
            uVar9 = *(undefined2 *)(piVar37 + 4);
            if (bVar2) {
              pcVar25 = (char *)((bVar3 & 3) * 4 + 0x1dc259);
              pcVar26 = (char *)((bVar3 >> 4 & 0xc) + 0x1dc259);
              pcVar23 = (char *)((bVar3 >> 2 & 0xc) + 0x1dc259);
              pcVar24 = (char *)((bVar3 & 0xc) + 0x1dc259);
            }
            else {
              pcVar26 = "-";
              pcVar23 = pcVar26;
              pcVar24 = pcVar26;
              pcVar25 = pcVar26;
            }
            FUN_001a32d0(auStack_23c,"%s%s%s%s",pcVar26,pcVar23,pcVar24,pcVar25);
            ((int (*)())FUN_000d03b4)(0,"lookup_dxdy(%s.%s, r%02d.%s, r%02d.%s,  tex%02d)%s%s%s%s",auStack_278,
                         auStack_24b,uVar9,auStack_269,*(undefined2 *)((int)piVar37 + 0x12),
                         auStack_23c);
            break;
          case '\a':
            ((int (*)())FUN_000d03b4)(0,"lookup_uncached(%s.%s, tex%02d)%s%s%s%s",auStack_278,auStack_24b,uVar4,
                         &local_2b4,&local_296,&local_28c);
            break;
          default:
            ((int (*)())FUN_000d03b4)(0,"UNKNOWN_OP%s%s%s%s",&local_2b4,&local_296,&local_28c,&local_282);
          }
          if (*(char *)((int)piVar37 + 5) != '\0') {
            if (*(char *)((int)piVar37 + 6) == '\0') {
              (*(unsigned short *)((unsigned char *)&(local_2b8) + 0)) = 0x7000;
            }
            else {
              local_2b8[0] = s__p_001a74dc[0];
              local_2b8[1] = s__p_001a74dc[1];
              local_2b8[2] = s__p_001a74dc[2];
            }
            switch(*(undefined1 *)((int)piVar37 + 5)) {
            case 1:
              ((int (*)())FUN_000d03b4)(0," %s.rgb",local_2b8);
              break;
            case 2:
              ((int (*)())FUN_000d03b4)(0," %s.rrr",local_2b8);
              break;
            case 3:
              ((int (*)())FUN_000d03b4)(0," %s.ggg",local_2b8);
              break;
            case 4:
              ((int (*)())FUN_000d03b4)(0," %s.bbb",local_2b8);
              break;
            case 5:
              ((int (*)())FUN_000d03b4)(0," %s.aaa",local_2b8);
            }
          }
          if (*(char *)((int)piVar37 + 7) != '\0') {
            if (*(char *)(piVar37 + 2) == '\0') {
              (*(unsigned short *)((unsigned char *)&(local_2b8) + 0)) = 0x7000;
            }
            else {
              local_2b8[0] = s__p_001a74dc[0];
              local_2b8[1] = s__p_001a74dc[1];
              local_2b8[2] = s__p_001a74dc[2];
            }
            switch(*(undefined1 *)((int)piVar37 + 7)) {
            case 1:
            case 5:
              ((int (*)())FUN_000d03b4)(0," %s.a",local_2b8);
              break;
            case 2:
              ((int (*)())FUN_000d03b4)(0," %s.r",local_2b8);
              break;
            case 3:
              ((int (*)())FUN_000d03b4)(0," %s.g",local_2b8);
              break;
            case 4:
              ((int (*)())FUN_000d03b4)(0," %s.b",local_2b8);
            }
          }
          if (*(char *)((int)piVar37 + 9) != '\0') {
            ((int (*)())FUN_000d03b4)(0," write_inactive");
          }
          ((int (*)())FUN_000d03b4)(0,"\n");
          iVar18 = *piVar37;
          local_f4 = local_f4 + 1;
        }
        if ((iVar18 == 3) || (iVar18 == 4)) {
          local_74 = (uint)*(byte *)((int)piVar37 + 0x43);
          local_ec = (uint)*(byte *)(piVar37 + 0x11);
          switch(*(undefined1 *)((int)piVar37 + 0x31)) {
          case 0:
          case 3:
          case 7:
          case 8:
            bVar2 = true;
            bVar42 = true;
            bVar1 = true;
            local_98 = 0;
            break;
          case 1:
          case 4:
          case 5:
          case 0xb:
          case 0xc:
            bVar2 = true;
            bVar42 = true;
            bVar1 = false;
            local_98 = 0;
            break;
          case 2:
            bVar2 = true;
            local_98 = 3;
            bVar42 = true;
            bVar1 = false;
            break;
          default:
            bVar2 = false;
            bVar42 = false;
            bVar1 = false;
            local_98 = 0;
            break;
          case 9:
            bVar2 = true;
            bVar42 = false;
            bVar1 = false;
            local_98 = 0;
          }
          if (*(byte *)(piVar37 + 0x10) < 0x10) {
            uVar36 = 1 << ((int)(char)*(byte *)(piVar37 + 0x10) & 0x3fU);
            if ((uVar36 & 0x61) == 0) {
              if ((uVar36 & 0xc00c) == 0) {
                if ((uVar36 & 0x3f80) != 0) {
                  local_98 = local_98 | 1;
                }
              }
              else {
                local_98 = 3;
              }
            }
            else {
              local_98 = 7;
            }
          }
          local_e4 = *(byte *)((int)piVar37 + 0x2a) & 0xffffff7f;
          local_e0 = *(byte *)((int)piVar37 + 0x2b) & 0xffffff7f;
          local_dc = *(byte *)(piVar37 + 0xb) & 0xffffff7f;
          local_d8 = *(byte *)((int)piVar37 + 0x39) & 0xffffff7f;
          local_d4 = *(byte *)((int)piVar37 + 0x3a) & 0xffffff7f;
          local_d0 = *(byte *)((int)piVar37 + 0x3b) & 0xffffff7f;
          local_6c = *(undefined2 *)(piVar37 + 10);
          uVar9 = *(undefined2 *)((int)piVar37 + 0xe);
          uVar10 = *(undefined2 *)(piVar37 + 4);
          uVar11 = *(undefined2 *)((int)piVar37 + 0x12);
          uVar12 = *(undefined2 *)((int)piVar37 + 0x1a);
          uVar13 = *(undefined2 *)(piVar37 + 7);
          uVar14 = *(undefined2 *)((int)piVar37 + 0x1e);
          uVar15 = *(undefined2 *)(piVar37 + 9);
          uVar16 = *(undefined2 *)((int)piVar37 + 0x26);
          local_9c = (uint)*(byte *)(piVar37 + 0xe);
          cVar20 = *(char *)((int)piVar37 + 0x36);
          cVar6 = *(char *)((int)piVar37 + 0x37);
          local_80 = (uint)*(byte *)((int)piVar37 + 0x2d);
          local_84 = (uint)*(byte *)((int)piVar37 + 0x2e);
          local_88 = (uint)*(byte *)((int)piVar37 + 0x2f);
          local_8c = (uint)*(byte *)(piVar37 + 0xf);
          local_90 = (uint)*(byte *)((int)piVar37 + 0x3d);
          local_94 = (uint)*(byte *)((int)piVar37 + 0x3e);
          if (bVar2) {
            bVar2 = local_e4 != 3;
            if (bVar2) {
LAB_000d2654:
              bVar28 = false;
            }
            else {
              iVar18 = ((int (*)())FUN_000d10a8)(uVar15);
              bVar28 = true;
              if (iVar18 != 0) goto LAB_000d2654;
            }
            if (!bVar2) {
              bVar2 = true;
              iVar18 = ((int (*)())FUN_000d10a8)(uVar15);
              if (iVar18 != 0) goto LAB_000d2674;
            }
            bVar2 = false;
          }
          else {
            bVar2 = false;
            bVar28 = false;
          }
LAB_000d2674:
          if (bVar42) {
            bVar42 = local_e0 != 3;
            if (bVar42) {
LAB_000d269c:
              bVar3 = 0;
            }
            else {
              iVar18 = ((int (*)())FUN_000d10a8)(uVar16);
              bVar3 = 1;
              if (iVar18 != 0) goto LAB_000d269c;
            }
            bVar28 = (bool)(bVar28 | bVar3);
            if (bVar42) {
LAB_000d26bc:
              bVar3 = 0;
            }
            else {
              iVar18 = ((int (*)())FUN_000d10a8)(uVar16);
              bVar3 = 1;
              if (iVar18 == 0) goto LAB_000d26bc;
            }
            bVar2 = (bool)(bVar2 | bVar3);
          }
          if (bVar1) {
            bVar1 = local_dc != 3;
            if (bVar1) {
LAB_000d26ec:
              bVar3 = 0;
            }
            else {
              iVar18 = ((int (*)())FUN_000d10a8)(local_6c);
              bVar3 = 1;
              if (iVar18 != 0) goto LAB_000d26ec;
            }
            bVar28 = (bool)(bVar28 | bVar3);
            if (bVar1) {
LAB_000d270c:
              bVar3 = 0;
            }
            else {
              iVar18 = ((int (*)())FUN_000d10a8)(local_6c);
              bVar3 = 1;
              if (iVar18 == 0) goto LAB_000d270c;
            }
            bVar2 = (bool)(bVar2 | bVar3);
          }
          if ((local_98 & 1) != 0) {
            if ((local_d8 != 3) || (bVar3 = 1, cVar20 == '\x03')) {
              bVar3 = 0;
            }
            bVar28 = (bool)(bVar28 | bVar3);
            if ((local_d8 != 3) || (bVar3 = 1, cVar20 != '\x03')) {
              bVar3 = 0;
            }
            bVar2 = (bool)(bVar2 | bVar3);
          }
          if ((local_98 & 2) != 0) {
            if ((local_d4 != 3) || (bVar3 = 1, cVar6 == '\x03')) {
              bVar3 = 0;
            }
            bVar28 = (bool)(bVar28 | bVar3);
            if ((local_d4 != 3) || (bVar3 = 1, cVar6 != '\x03')) {
              bVar3 = 0;
            }
            bVar2 = (bool)(bVar2 | bVar3);
          }
          if ((local_98 & 4) != 0) {
            if ((local_d0 != 3) || (bVar3 = 1, local_9c == 3)) {
              bVar3 = 0;
            }
            bVar28 = (bool)(bVar28 | bVar3);
            if ((local_d0 != 3) || (bVar3 = 1, local_9c != 3)) {
              bVar3 = 0;
            }
            bVar2 = (bool)(bVar2 | bVar3);
          }
          if (bVar28) {
            ((int (*)())FUN_000d03b4)(0,"  %d alu %02d pre:  srcp.rgb = ",local_70,local_f0);
            cVar20 = *(char *)(piVar37 + 0xc);
            if (cVar20 == '\x01') {
              ((int (*)())FUN_000d10dc)(&local_2a0,uVar9);
              ((int (*)())FUN_000d10dc)(&local_2aa,uVar10);
              ((int (*)())FUN_000d03b4)(0,"%s.rgb-%s.rgb\n",&local_2aa,&local_2a0);
            }
            else if (cVar20 == '\0') {
              ((int (*)())FUN_000d10dc)(&local_2a0,uVar9);
              ((int (*)())FUN_000d03b4)(0,"1.0-2.0*%s.rgb\n",&local_2a0);
            }
            else if (cVar20 == '\x02') {
              ((int (*)())FUN_000d10dc)(&local_2a0,uVar9);
              ((int (*)())FUN_000d10dc)(&local_2aa,uVar10);
              ((int (*)())FUN_000d03b4)(0,"%s.rgb+%s.rgb\n",&local_2aa,&local_2a0);
            }
            else if (cVar20 == '\x03') {
              ((int (*)())FUN_000d10dc)(&local_2a0,uVar9);
              ((int (*)())FUN_000d03b4)(0,"1.0-%s.rgb\n",&local_2a0);
            }
            else {
              ((int (*)())FUN_000d03b4)(0,"???\n");
            }
          }
          if (bVar2) {
            ((int (*)())FUN_000d03b4)(0,"  %d alu %02d pre:  srcp.a   = ",local_70,local_f0);
            cVar20 = *(char *)((int)piVar37 + 0x3f);
            if (cVar20 == '\x01') {
              ((int (*)())FUN_000d10dc)(&local_2a0,uVar12);
              ((int (*)())FUN_000d10dc)(&local_2aa,uVar13);
              ((int (*)())FUN_000d03b4)(0,"%s.a-%s.a\n",&local_2aa,&local_2a0);
            }
            else if (cVar20 == '\0') {
              ((int (*)())FUN_000d10dc)(&local_2a0,uVar12);
              ((int (*)())FUN_000d03b4)(0,"1.0-2.0*%s.a\n",&local_2a0);
            }
            else if (cVar20 == '\x02') {
              ((int (*)())FUN_000d10dc)(&local_2a0,uVar12);
              ((int (*)())FUN_000d10dc)(&local_2aa,uVar13);
              ((int (*)())FUN_000d03b4)(0,"%s.a+%s.a\n",&local_2aa,&local_2a0);
            }
            else if (cVar20 == '\x03') {
              ((int (*)())FUN_000d10dc)(&local_2a0,uVar12);
              ((int (*)())FUN_000d03b4)(0,"1.0-%s.a\n",&local_2a0);
            }
            else {
              ((int (*)())FUN_000d03b4)(0,"???\n");
            }
          }
          ((int (*)())FUN_000d03b4)(0,"  %d alu %02d rgb:  ",local_70,local_f0);
          uVar36 = (uint)*(byte *)((int)piVar37 + 0x15);
          bVar3 = *(byte *)(piVar37 + 5);
          if (uVar36 == 0) {
LAB_000d2b24:
            ((int (*)())FUN_000d03b4)(0,"           ");
          }
          else if (*piVar37 == 3) {
            ((int (*)())FUN_000d03b4)(0,"out%d.%s = ",*(undefined1 *)((int)piVar37 + 0x16),uVar36 * 4 + 0x1dc239)
            ;
          }
          else {
            if (*piVar37 != 4) goto LAB_000d2b24;
            ((int (*)())FUN_000d03b4)(0,"pred.%s = ",uVar36 * 4 + 0x1dc239);
            cVar20 = *(char *)((int)piVar37 + 0x16);
            if (cVar20 == '\x01') {
              ((int (*)())FUN_000d03b4)(0,"(<) ");
            }
            else if (cVar20 == '\0') {
              ((int (*)())FUN_000d03b4)(0,"(==) ");
            }
            else if (cVar20 == '\x02') {
              ((int (*)())FUN_000d03b4)(0,"(>=) ");
            }
            else if (cVar20 == '\x03') {
              ((int (*)())FUN_000d03b4)(0,"(!=) ");
            }
          }
          if (bVar3 == 0) {
            ((int (*)())FUN_000d03b4)(0,"          ");
          }
          else {
            ((int (*)())FUN_000d03b4)(0,"r%02d.%s = ",*(undefined2 *)(piVar37 + 3),(uint)bVar3 * 4 + 0x1dc239);
          }
          if (*(char *)((int)piVar37 + 0x33) != '\0') {
            ((int (*)())FUN_000d03b4)(0,"clamped ");
          }
          ((int (*)())FUN_000d13a4)(auStack_21c,uVar9,uVar10,uVar11,uVar12,uVar13,uVar14,local_e4);
          ((int (*)())FUN_000d13a4)(auStack_17c,uVar9,uVar10,uVar11,uVar12,uVar13,uVar14,local_e0);
          ((int (*)())FUN_000d13a4)(auStack_19c,uVar9,uVar10,uVar11,uVar12,uVar13,uVar14,local_dc);
          local_60 = auStack_1bc;
          ((int (*)())FUN_000d1624)(local_60,uVar9,uVar10,uVar11,uVar12,uVar13,uVar14,local_d8);
          local_64 = auStack_1dc;
          ((int (*)())FUN_000d1624)(local_64,uVar9,uVar10,uVar11,uVar12,uVar13,uVar14,local_d4);
          local_68 = auStack_1fc;
          ((int (*)())FUN_000d1624)(local_68,uVar9,uVar10,uVar11,uVar12,uVar13,uVar14,local_d0);
          switch(*(undefined1 *)((int)piVar37 + 0x31)) {
          case 0:
            ((int (*)())FUN_000d03b4)(0,"mad(%s, %s, %s)",auStack_21c,auStack_17c,auStack_19c);
            break;
          case 1:
            ((int (*)())FUN_000d03b4)(0,"dp3(%s, %s)",auStack_21c,auStack_17c);
            break;
          case 2:
            ((int (*)())FUN_000d03b4)(0,"dp4(%s:%s, %s:%s)",auStack_21c,local_60,auStack_17c,local_64);
            break;
          case 3:
            ((int (*)())FUN_000d03b4)(0,"d2a(%s, %s, %s)",auStack_21c,auStack_17c,auStack_19c);
            break;
          case 4:
            ((int (*)())FUN_000d03b4)(0,"min(%s, %s)",auStack_21c,auStack_17c);
            break;
          case 5:
            ((int (*)())FUN_000d03b4)(0,"max(%s, %s)",auStack_21c,auStack_17c);
            break;
          default:
            ((int (*)())FUN_000d03b4)(0,"???()");
            break;
          case 7:
            ((int (*)())FUN_000d03b4)(0,"cnd(%s, %s, %s)",auStack_21c,auStack_17c,auStack_19c);
            break;
          case 8:
            ((int (*)())FUN_000d03b4)(0,"cmp(%s, %s, %s)",auStack_21c,auStack_17c,auStack_19c);
            break;
          case 9:
            ((int (*)())FUN_000d03b4)(0,"frc(%s)",auStack_21c);
            break;
          case 10:
            ((int (*)())FUN_000d03b4)(0,"sop()");
            break;
          case 0xb:
            ((int (*)())FUN_000d03b4)(0,"mdh(%s, %s)",auStack_21c,auStack_17c);
            break;
          case 0xc:
            ((int (*)())FUN_000d03b4)(0,"mdv(%s, %s)",auStack_21c,auStack_17c);
          }
          switch(*(undefined1 *)((int)piVar37 + 0x32)) {
          case 0:
            break;
          case 1:
            ((int (*)())FUN_000d03b4)(0,"*2");
            break;
          case 2:
            ((int (*)())FUN_000d03b4)(0,"*4");
            break;
          case 3:
            ((int (*)())FUN_000d03b4)(0,"*8");
            break;
          case 4:
            ((int (*)())FUN_000d03b4)(0,"/2");
            break;
          case 5:
            ((int (*)())FUN_000d03b4)(0,"/4");
            break;
          case 6:
            ((int (*)())FUN_000d03b4)(0,"/8");
            break;
          default:
            ((int (*)())FUN_000d03b4)(0,"*???");
          }
          if (((*(unsigned char *)((unsigned char *)&(local_2b4) + 0)) != '\0') || ((*(unsigned char *)((unsigned char *)&(local_28c) + 0)) != '\0')) {
            ((int (*)())FUN_000d03b4)(0,"%s%s",&local_2b4,&local_28c);
          }
          if (*(char *)((int)piVar37 + 5) != '\0') {
            if (*(char *)((int)piVar37 + 6) == '\0') {
              (*(unsigned short *)((unsigned char *)&(local_2b8) + 0)) = 0x7000;
            }
            else {
              local_2b8[0] = s__p_001a74dc[0];
              local_2b8[1] = s__p_001a74dc[1];
              local_2b8[2] = s__p_001a74dc[2];
            }
            switch(*(undefined1 *)((int)piVar37 + 5)) {
            case 1:
              ((int (*)())FUN_000d03b4)(0," %s.rgb",local_2b8);
              break;
            case 2:
              ((int (*)())FUN_000d03b4)(0," %s.rrr",local_2b8);
              break;
            case 3:
              ((int (*)())FUN_000d03b4)(0," %s.ggg",local_2b8);
              break;
            case 4:
              ((int (*)())FUN_000d03b4)(0," %s.bbb",local_2b8);
              break;
            case 5:
              ((int (*)())FUN_000d03b4)(0," %s.aaa",local_2b8);
            }
          }
          ((int (*)())FUN_000d03b4)(0,"\n");
          ((int (*)())FUN_000d03b4)(0,"         alpha:  ",local_f0);
          cVar20 = *(char *)(piVar37 + 8);
          bVar2 = *(char *)((int)piVar37 + 0x21) != '\0';
          cVar6 = *(char *)((int)piVar37 + 0x23);
          if (bVar2) {
            if (*piVar37 == 3) {
              ((int (*)())FUN_000d03b4)(0,"out%d.a   = ",*(undefined1 *)((int)piVar37 + 0x22));
            }
            else if (*piVar37 == 4) {
              ((int (*)())FUN_000d03b4)(0,"pred.a   = ");
              cVar7 = *(char *)((int)piVar37 + 0x22);
              if (cVar7 == '\x01') {
                ((int (*)())FUN_000d03b4)(0,"(<) ");
              }
              else if (cVar7 == '\0') {
                ((int (*)())FUN_000d03b4)(0,"(==) ");
              }
              else if (cVar7 == '\x02') {
                ((int (*)())FUN_000d03b4)(0,"(>=) ");
              }
              else if (cVar7 == '\x03') {
                ((int (*)())FUN_000d03b4)(0,"(!=) ");
              }
            }
          }
          bVar1 = cVar6 != '\0';
          if (bVar1) {
            ((int (*)())FUN_000d03b4)(0,"depth    = ");
          }
          if ((!bVar2) && (!bVar1)) {
            ((int (*)())FUN_000d03b4)(0,"           ");
          }
          if (cVar20 == '\0') {
            ((int (*)())FUN_000d03b4)(0,"          ");
          }
          else {
            ((int (*)())FUN_000d03b4)(0,"r%02d.a   = ",*(undefined2 *)(piVar37 + 6));
          }
          if (*(char *)((int)piVar37 + 0x42) != '\0') {
            ((int (*)())FUN_000d03b4)(0,"clamped ");
          }
          switch(*(undefined1 *)(piVar37 + 0x10)) {
          case 0:
            ((int (*)())FUN_000d03b4)(0,"mad(%s, %s, %s)",local_60,local_64,local_68);
            break;
          case 1:
            ((int (*)())FUN_000d03b4)(0,"dp()");
            break;
          case 2:
            ((int (*)())FUN_000d03b4)(0,"min(%s, %s)",local_60,local_64);
            break;
          case 3:
            ((int (*)())FUN_000d03b4)(0,"max(%s, %s)",local_60,local_64);
            break;
          default:
            ((int (*)())FUN_000d03b4)(0,"???()");
            break;
          case 5:
            ((int (*)())FUN_000d03b4)(0,"cnd(%s, %s, %s)",local_60,local_64,local_68);
            break;
          case 6:
            ((int (*)())FUN_000d03b4)(0,"cmp(%s, %s, %s)",local_60,local_64,local_68);
            break;
          case 7:
            ((int (*)())FUN_000d03b4)(0,"frc(%s)",local_60);
            break;
          case 8:
            ((int (*)())FUN_000d03b4)(0,"ex2(%s)",local_60);
            break;
          case 9:
            ((int (*)())FUN_000d03b4)(0,"ln2(%s)",local_60);
            break;
          case 10:
            ((int (*)())FUN_000d03b4)(0,"rcp(%s)",local_60);
            break;
          case 0xb:
            ((int (*)())FUN_000d03b4)(0,"rsq(%s)",local_60);
            break;
          case 0xc:
            ((int (*)())FUN_000d03b4)(0,"sin(%s)",local_60);
            break;
          case 0xd:
            ((int (*)())FUN_000d03b4)(0,"cos(%s)",local_60);
            break;
          case 0xe:
            ((int (*)())FUN_000d03b4)(0,"mdh(%s, %s)",local_60,local_64);
            break;
          case 0xf:
            ((int (*)())FUN_000d03b4)(0,"mdv(%s, %s)",local_60,local_64);
          }
          switch(*(undefined1 *)((int)piVar37 + 0x41)) {
          case 0:
            ((int (*)())FUN_000d03b4)(0," ");
            break;
          case 1:
            ((int (*)())FUN_000d03b4)(0,"*2");
            break;
          case 2:
            ((int (*)())FUN_000d03b4)(0,"*4");
            break;
          case 3:
            ((int (*)())FUN_000d03b4)(0,"*8");
            break;
          case 4:
            ((int (*)())FUN_000d03b4)(0,"/2");
            break;
          case 5:
            ((int (*)())FUN_000d03b4)(0,"/4");
            break;
          case 6:
            ((int (*)())FUN_000d03b4)(0,"/8");
            break;
          default:
            ((int (*)())FUN_000d03b4)(0,"*???");
          }
          if (*(char *)((int)piVar37 + 10) == '\0') {
            if (*(char *)((int)piVar37 + 7) != '\0') {
              if (*(char *)(piVar37 + 2) == '\0') {
                (*(unsigned short *)((unsigned char *)&(local_2b8) + 0)) = 0x7000;
              }
              else {
                local_2b8[0] = s__p_001a74dc[0];
                local_2b8[1] = s__p_001a74dc[1];
                local_2b8[2] = s__p_001a74dc[2];
              }
              switch(*(undefined1 *)((int)piVar37 + 7)) {
              case 1:
              case 5:
                ((int (*)())FUN_000d03b4)(0," %s.a",local_2b8);
                break;
              case 2:
                ((int (*)())FUN_000d03b4)(0," %s.r",local_2b8);
                break;
              case 3:
                ((int (*)())FUN_000d03b4)(0," %s.g",local_2b8);
                break;
              case 4:
                ((int (*)())FUN_000d03b4)(0," %s.b",local_2b8);
              }
            }
            if (*(char *)((int)piVar37 + 9) != '\0') {
              ((int (*)())FUN_000d03b4)(0," write_inactive");
            }
            ((int (*)())FUN_000d03b4)(0," \n");
          }
          else {
            ((int (*)())FUN_000d03b4)(0," last\n");
          }
          if (*(char *)(piVar37 + 0xd) != '\0') {
            ((int (*)())FUN_000d03b4)(0,"   alu %02d post-NOP\n",local_f0);
          }
          iVar18 = *piVar37;
          local_f0 = local_f0 + 1;
        }
        if (iVar18 == 5) {
          if (local_ec == 1) {
            local_2a0 = CONCAT12(s_lt_001a77dc[0],(*(unsigned short *)((unsigned char *)&(s_lt_001a77dc) + 1)));
          }
          else if (local_ec == 0) {
            local_2a0 = CONCAT12(s_eq_001a77d8[0],(*(unsigned short *)((unsigned char *)&(s_eq_001a77d8) + 1)));
          }
          else if (local_ec == 2) {
            local_2a0 = CONCAT12(s_ge_001a77e0[0],(*(unsigned short *)((unsigned char *)&(s_ge_001a77e0) + 1)));
          }
          else if (local_ec == 3) {
            local_2a0 = CONCAT12(s_ne_001a77e4[0],(*(unsigned short *)((unsigned char *)&(s_ne_001a77e4) + 1)));
          }
          else {
            local_2a0 = CONCAT21(0x2000,uStack_29e);
          }
          if (local_74 == 0) {
            (*(unsigned char *)((unsigned char *)&(local_2aa) + 0)) = 'r';
            (*(unsigned char *)((unsigned char *)&(local_2aa) + 1)) = 'e';
            (*(unsigned char *)((unsigned char *)&(local_2aa) + 2)) = 'd';
            (*(unsigned char *)((unsigned char *)&(local_2aa) + 3)) = '\0';
          }
          else if (local_74 == 1) {
            (*(unsigned char *)((unsigned char *)&(local_2aa) + 0)) = s_alpha_001a77e8[0];
            (*(unsigned char *)((unsigned char *)&(local_2aa) + 1)) = s_alpha_001a77e8[1];
            (*(unsigned char *)((unsigned char *)&(local_2aa) + 2)) = s_alpha_001a77e8[2];
            (*(unsigned char *)((unsigned char *)&(local_2aa) + 3)) = s_alpha_001a77e8[3];
            local_2a6[0] = s_alpha_001a77e8[4];
            local_2a6[1] = s_alpha_001a77e8[5];
          }
          else {
            (*(unsigned char *)((unsigned char *)&(local_2aa) + 0)) = ' ';
            (*(unsigned char *)((unsigned char *)&(local_2aa) + 1)) = '\0';
          }
          ((int (*)())FUN_000d03b4)(0,"  %d cf  %02d    :  ",local_70,local_f8);
          FUN_001a32d0(acStack_15c,"0x%02x %1d %s %s %s %s %1d %1d %d",
                       *(undefined1 *)((int)piVar37 + 0x12),*(undefined1 *)(piVar37 + 4),
                       (uint)*(byte *)((int)piVar37 + 0xe) * 10 + 0x1dc1e9,
                       (uint)*(byte *)((int)piVar37 + 0x11) * 5 + 0x1dc1da,
                       (uint)*(byte *)(piVar37 + 5) * 10 + 0x1dc1bc,
                       (uint)*(byte *)((int)piVar37 + 0x15) * 10 + 0x1dc1bc);
          if (PTR_s_0x55_0_JUMP_NONE_NONE_NONE_001dc2d0 == (undefined *)0x0) {
            iVar18 = 0;
          }
          else {
            ppuVar39 = &PTR_s_0xaa_0_JUMP_NONE_NONE_NONE_001dc2d8;
            iVar18 = 0;
            pcVar23 = PTR_s_0x55_0_JUMP_NONE_NONE_NONE_001dc2d0;
            do {
              sVar21 = _strlen(pcVar23);
              iVar22 = _strncmp(pcVar23,acStack_15c,sVar21);
              if (iVar22 == 0) break;
              pcVar23 = *ppuVar39;
              iVar18 = iVar18 + 2;
              ppuVar39 = ppuVar39 + 2;
            } while (pcVar23 != (char *)0x0);
          }
          ((int (*)())FUN_000d03b4)(0,"%s(%s)%s%s",(PTR_s_IF_b_001dc2cc)[iVar18],acStack_15c,&local_2b4,
                       &local_28c);
          cVar20 = *(char *)((int)piVar37 + 0x12);
          if ((cVar20 == -0x10) || (cVar20 == '\x0f')) {
            ((int (*)())FUN_000d03b4)(0,"( prev_alu: %s %s )\n",&local_2aa,&local_2a0);
          }
          else if ((cVar20 == -0x56) || (cVar20 == 'U')) {
            ((int (*)())FUN_000d03b4)(0,"( bool_addr: %d )\n",*(undefined1 *)((int)piVar37 + 0x17));
          }
          else {
            ((int (*)())FUN_000d03b4)(0,"\n");
          }
          local_f8 = local_f8 + 1;
        }
        iVar34 = iVar34 + 1;
        piVar37 = piVar37 + 0x12;
        local_70 = local_70 + 1;
      } while (iVar34 <= local_7c);
    }
    ((int (*)())FUN_000d03b4)(0,local_5c + 0x5b00);
    ((int (*)())FUN_000d03b4)(0,"======== End r520 neutral format pixel shader =============\n");
  }
  return;
}

/* FUN_000d4df8 @ 0xd4df8 (16 bytes) */
int FUN_000d4df8(param_1)
  undefined4 *param_1;
{
  param_1[1] = 0;
  *param_1 = 0;
  return;
}

/* FUN_000d4e08 @ 0xd4e08 (92 bytes) */
int FUN_000d4e08(param_1, param_2)
  undefined4 *param_1;
  int param_2;
{
  DAT_001fa61c = *param_1;
  DAT_001fa618 = param_1[1];
  ((int (*)())FUN_000d183c)(param_2 + 0x64c,"SC Generated Shader",0);
  return 1;
}

/* FUN_000d4e64 @ 0xd4e64 (40 bytes) */
int FUN_000d4e64()
{
  undefined1 auStack_28 [40];
  
  ((int (*)())FUN_000d4df8)(auStack_28);
  return 0;
}

/* FUN_000d4e8c @ 0xd4e8c (84 bytes) */
int FUN_000d4e8c(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  undefined4 local_38;
  undefined4 local_34;
  
  ((int (*)())FUN_000d4df8)(&local_38);
  local_38 = param_4;
  local_34 = param_1;
  ((int (*)())FUN_000d4e08)(&local_38,param_2);
  return 0;
}

/* FUN_000d4ef0 @ 0xd4ef0 (628 bytes) */
int FUN_000d4ef0(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  undefined *param_2;
  uint param_3;
  uint *param_4;
  uint *param_5;
  undefined *param_6;
  undefined4 param_7;
  int param_8;
{
  undefined *puVar1;
  short in_stack_0000003a;
  
  puVar1 = param_2 + -0x84c0;
  if ((undefined *)0xf < puVar1) {
    if (param_2 < (undefined *)0x2) {
      if (param_2 == (undefined *)0x0) {
        *param_4 = *param_4 & 0xffc0ffff | 0x120000;
        *(undefined2 *)((int)param_4 + 2) = 0;
        *param_4 = *param_4 | 0x400000;
        if (param_3 != 0x301) {
          if (param_3 < 0x302) {
            if (param_3 != 0x300) {
              return;
            }
          }
          else if (param_3 != 0x302) {
            if (param_3 != 0x303) {
              return;
            }
            goto LAB_000d5160;
          }
LAB_000d517c:
          *param_5 = *param_5 & 0xfffff888 | 0x444;
          return;
        }
      }
      else {
        if (param_2 != (undefined *)0x1) {
          return;
        }
        *param_4 = *param_4 & 0xffc0ffff | 0x120000;
        *(undefined2 *)((int)param_4 + 2) = 0;
        *param_4 = *param_4 | 0x400000;
        if (param_3 == 0x301) goto LAB_000d517c;
        if (param_3 < 0x302) {
          if (param_3 != 0x300) {
            return;
          }
        }
        else if (param_3 != 0x302) {
          if (param_3 != 0x303) {
            return;
          }
          goto LAB_000d517c;
        }
      }
LAB_000d5160:
      *param_5 = *param_5 & 0xfffff888 | 0x555;
      return;
    }
    if (param_2 == (undefined *)0x8576) {
      *param_4 = *param_4 & 0xffc0ffff | 0x10000;
      *(short *)((int)param_4 + 2) = (short)param_6;
      goto LAB_000d4fe0;
    }
    if ((undefined *)0x8576 < param_2) {
      if (param_2 != (undefined *)0x8577) {
        if (param_2 != (undefined *)0x8578) goto LAB_000d4fe0;
        if (param_8 == 0) {
          *param_4 = *param_4 & 0xffc0ffff | 0x40000;
          *(ushort *)((int)param_4 + 2) = in_stack_0000003a + (ushort)(byte)((unsigned char *)0x000013b2)[param_1]
          ;
          goto LAB_000d4fe0;
        }
      }
      *param_4 = *param_4 & 0xffc0ffff | 0x120000;
      goto LAB_000d4fe0;
    }
    puVar1 = param_6;
    if (param_2 != ((unsigned char *)0x00001702)) goto LAB_000d4fe0;
  }
  *param_4 = *param_4 & 0xffc0ffff | 0x40000;
  *(short *)((int)param_4 + 2) = (short)puVar1;
LAB_000d4fe0:
  if (param_3 == 0x302) {
    *param_4 = *param_4 | 0x400000;
    *param_5 = *param_5 & 0xfffff888 | 0x333;
    return;
  }
  if (param_3 == 0x303) {
    *param_4 = *param_4 | 0x400000;
    *param_5 = *param_5 & 0xfffff888 | 0x10333;
    return;
  }
  if (param_3 == 0x301) {
    *param_4 = *param_4 | 0x400000;
    *param_5 = *param_5 & 0xfffff888 | 0x10210;
    return;
  }
  return;
}

/* FUN_000d51a0 @ 0xd51a0 (460 bytes) */
int FUN_000d51a0(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  undefined *param_2;
  int param_3;
  uint *param_4;
  uint *param_5;
  undefined *param_6;
  undefined4 param_7;
  int param_8;
{
  undefined *puVar1;
  short in_stack_0000003a;
  
  puVar1 = param_2 + -0x84c0;
  if ((undefined *)0xf < puVar1) {
    if (param_2 < (undefined *)0x2) {
      if (param_2 == (undefined *)0x0) {
        *param_4 = *param_4 & 0xffc0ffff | 0x120000;
        *(undefined2 *)((int)param_4 + 2) = 0;
        *param_4 = *param_4 | 0x400000;
        if (param_3 != 0x302) {
          if (param_3 != 0x303) {
            return;
          }
          goto LAB_000d535c;
        }
      }
      else {
        if (param_2 != (undefined *)0x1) {
          return;
        }
        *param_4 = *param_4 & 0xffc0ffff | 0x120000;
        *(undefined2 *)((int)param_4 + 2) = 0;
        *param_4 = *param_4 | 0x400000;
        if (param_3 == 0x302) {
LAB_000d535c:
          *param_5 = *param_5 & 0xffff8fff | 0x5000;
          return;
        }
        if (param_3 != 0x303) {
          return;
        }
      }
      *param_5 = *param_5 & 0xffff8fff | 0x4000;
      return;
    }
    if (param_2 == (undefined *)0x8576) {
      *param_4 = *param_4 & 0xffc0ffff | 0x10000;
      *(short *)((int)param_4 + 2) = (short)param_6;
      goto LAB_000d52a0;
    }
    if ((undefined *)0x8576 < param_2) {
      if (param_2 != (undefined *)0x8577) {
        if (param_2 != (undefined *)0x8578) goto LAB_000d52a0;
        if (param_8 == 0) {
          *param_4 = *param_4 & 0xffc0ffff | 0x40000;
          *(ushort *)((int)param_4 + 2) = in_stack_0000003a + (ushort)(byte)((unsigned char *)0x000013b2)[param_1]
          ;
          goto LAB_000d52a0;
        }
      }
      *param_4 = *param_4 & 0xffc0ffff | 0x120000;
      *(undefined2 *)((int)param_4 + 2) = 0;
      goto LAB_000d52a0;
    }
    puVar1 = param_6;
    if (param_2 != ((unsigned char *)0x00001702)) goto LAB_000d52a0;
  }
  *param_4 = *param_4 & 0xffc0ffff | 0x40000;
  *(short *)((int)param_4 + 2) = (short)puVar1;
LAB_000d52a0:
  if (param_3 == 0x303) {
    *param_4 = *param_4 | 0x400000;
    *param_5 = *param_5 & 0xffff8fff | 0x13000;
    return;
  }
  return;
}

/* FUN_000d5390 @ 0xd5390 (548 bytes) */
int FUN_000d5390(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  uint *param_2;
  int param_3;
  int param_4;
  uint param_5;
{
  bool bVar1;
  void *pvVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  uVar4 = 0x170000;
  if (param_3 == 0) {
    uVar5 = param_4 + (uint)(byte)((unsigned char *)0x000013b2)[param_1] & 0xffff | 0x40000;
  }
  else {
    uVar5 = 0x120000;
  }
  uVar6 = 0;
  do {
    if ((1 << (uVar6 & 0x3f) & param_5) != 0) {
      uVar3 = *param_2;
      uVar4 = uVar6 & 0xffff | uVar4 & 0xffff0000;
      if (param_2[1] <= uVar3) {
        pvVar2 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
        if ((void *)param_2[2] != (void *)0x0) {
          _memcpy(pvVar2,(void *)param_2[2],*param_2 << 2);
          (**(code **)(param_1 + 0x18))(param_2[2]);
        }
        param_2[2] = (uint)pvVar2;
        uVar3 = *param_2;
        param_2[1] = param_2[1] + 0x80;
      }
      *(undefined4 *)(uVar3 * 4 + param_2[2]) = 0xe;
      uVar3 = *param_2 + 1;
      *param_2 = uVar3;
      if (param_2[1] <= uVar3) {
        pvVar2 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
        if ((void *)param_2[2] != (void *)0x0) {
          _memcpy(pvVar2,(void *)param_2[2],*param_2 << 2);
          (**(code **)(param_1 + 0x18))(param_2[2]);
        }
        param_2[2] = (uint)pvVar2;
        uVar3 = *param_2;
        param_2[1] = param_2[1] + 0x80;
      }
      *(uint *)(uVar3 * 4 + param_2[2]) = uVar4;
      uVar3 = *param_2 + 1;
      *param_2 = uVar3;
      if (param_2[1] <= uVar3) {
        pvVar2 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
        if ((void *)param_2[2] != (void *)0x0) {
          _memcpy(pvVar2,(void *)param_2[2],*param_2 << 2);
          (**(code **)(param_1 + 0x18))(param_2[2]);
        }
        param_2[2] = (uint)pvVar2;
        uVar3 = *param_2;
        param_2[1] = param_2[1] + 0x80;
      }
      *(uint *)(uVar3 * 4 + param_2[2]) = uVar5;
      *param_2 = *param_2 + 1;
    }
    bVar1 = uVar6 != 3;
    uVar6 = uVar6 + 1;
  } while (bVar1);
  return;
}

/* FUN_000d55c0 @ 0xd55c0 (832 bytes) */
int FUN_000d55c0(param_1, param_2, param_3, param_4)
  int param_1;
  uint *param_2;
  int param_3;
  int param_4;
{
  byte bVar1;
  void *pvVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = *param_2;
  if (param_2[1] <= uVar3) {
    pvVar2 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
    if ((void *)param_2[2] != (void *)0x0) {
      _memcpy(pvVar2,(void *)param_2[2],*param_2 << 2);
      (**(code **)(param_1 + 0x18))(param_2[2]);
    }
    param_2[2] = (uint)pvVar2;
    uVar3 = *param_2;
    param_2[1] = param_2[1] + 0x80;
  }
  *(undefined4 *)(uVar3 * 4 + param_2[2]) = 3;
  uVar3 = *param_2 + 1;
  *param_2 = uVar3;
  bVar1 = ((unsigned char *)0x000013b2)[param_1];
  if (param_2[1] <= uVar3) {
    pvVar2 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
    if ((void *)param_2[2] != (void *)0x0) {
      _memcpy(pvVar2,(void *)param_2[2],*param_2 << 2);
      (**(code **)(param_1 + 0x18))(param_2[2]);
    }
    param_2[2] = (uint)pvVar2;
    uVar3 = *param_2;
    param_2[1] = param_2[1] + 0x80;
  }
  *(uint *)(uVar3 * 4 + param_2[2]) = (int)param_4 + (uint)bVar1 & 0xffff | 0x40000;
  uVar3 = *param_2 + 1;
  *param_2 = uVar3;
  if (param_3 == 0) {
    uVar4 = (int)param_4 + (uint)(byte)((unsigned char *)0x000013b2)[param_1] & 0xffff | 0x40000;
  }
  else {
    uVar4 = 0x120000;
  }
  if (param_2[1] <= uVar3) {
    pvVar2 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
    if ((void *)param_2[2] != (void *)0x0) {
      _memcpy(pvVar2,(void *)param_2[2],*param_2 << 2);
      (**(code **)(param_1 + 0x18))(param_2[2]);
    }
    param_2[2] = (uint)pvVar2;
    uVar3 = *param_2;
    param_2[1] = param_2[1] + 0x80;
  }
  *(uint *)(uVar3 * 4 + param_2[2]) = uVar4;
  uVar3 = *param_2 + 1;
  *param_2 = uVar3;
  if (param_2[1] <= uVar3) {
    pvVar2 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
    if ((void *)param_2[2] != (void *)0x0) {
      _memcpy(pvVar2,(void *)param_2[2],*param_2 << 2);
      (**(code **)(param_1 + 0x18))(param_2[2]);
    }
    param_2[2] = (uint)pvVar2;
    uVar3 = *param_2;
    param_2[1] = param_2[1] + 0x80;
  }
  *(undefined4 *)(uVar3 * 4 + param_2[2]) = 0x530000;
  uVar3 = *param_2 + 1;
  *param_2 = uVar3;
  if (param_2[1] <= uVar3) {
    pvVar2 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
    if ((void *)param_2[2] != (void *)0x0) {
      _memcpy(pvVar2,(void *)param_2[2],*param_2 << 2);
      (**(code **)(param_1 + 0x18))(param_2[2]);
    }
    param_2[2] = (uint)pvVar2;
    uVar3 = *param_2;
    param_2[1] = param_2[1] + 0x80;
  }
  *(undefined **)(uVar3 * 4 + param_2[2]) = ((unsigned char *)0x00004210);
  *param_2 = *param_2 + 1;
  return;
}

/* FUN_000d5900 @ 0xd5900 (2612 bytes) */
int FUN_000d5900(param_1, param_2)
  int param_1;
  int param_2;
{
  bool bVar1;
  void *pvVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint *puVar8;
  
  puVar8 = (uint *)(param_2 + 4);
  iVar6 = *(int *)(*(int *)(param_1 + 4) + 0x10);
  if (*(uint *)(param_2 + 8) <= *(uint *)(param_2 + 4)) {
    pvVar2 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
    if (*(void **)(param_2 + 0xc) != (void *)0x0) {
      _memcpy(pvVar2,*(void **)(param_2 + 0xc),*(int *)(param_2 + 4) << 2);
      (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
    }
    *(void **)(param_2 + 0xc) = pvVar2;
    *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
  }
  *(undefined4 *)(*puVar8 * 4 + *(int *)(param_2 + 0xc)) = 0x1ff0016;
  uVar3 = *puVar8 + 1;
  *puVar8 = uVar3;
  if (*(uint *)(param_2 + 8) <= uVar3) {
    pvVar2 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
    if (*(void **)(param_2 + 0xc) != (void *)0x0) {
      _memcpy(pvVar2,*(void **)(param_2 + 0xc),*puVar8 << 2);
      (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
    }
    *(void **)(param_2 + 0xc) = pvVar2;
    uVar3 = *puVar8;
    *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
  }
  *(undefined4 *)(uVar3 * 4 + *(int *)(param_2 + 0xc)) = 0x120000;
  uVar3 = *puVar8 + 1;
  *puVar8 = uVar3;
  if (((*(uint *)(param_1 + 0x44) & 0xa00000) != 0) ||
     (((int)*(uint *)(param_1 + 0x44) < 0 && (*(short *)("}J3x})+x|B;x}k" + iVar6) == -0x7e06)))) {
    if (*(uint *)(param_2 + 8) <= uVar3) {
      pvVar2 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
      if (*(void **)(param_2 + 0xc) != (void *)0x0) {
        _memcpy(pvVar2,*(void **)(param_2 + 0xc),*puVar8 << 2);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
      }
      *(void **)(param_2 + 0xc) = pvVar2;
      uVar3 = *puVar8;
      *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
    }
    *(undefined4 *)(uVar3 * 4 + *(int *)(param_2 + 0xc)) = 0x1ff0016;
    uVar3 = *puVar8 + 1;
    *puVar8 = uVar3;
    if (*(uint *)(param_2 + 8) <= uVar3) {
      pvVar2 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
      if (*(void **)(param_2 + 0xc) != (void *)0x0) {
        _memcpy(pvVar2,*(void **)(param_2 + 0xc),*puVar8 << 2);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
      }
      *(void **)(param_2 + 0xc) = pvVar2;
      uVar3 = *puVar8;
      *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
    }
    *(undefined4 *)(uVar3 * 4 + *(int *)(param_2 + 0xc)) = 0x130000;
    uVar3 = *puVar8 + 1;
    *puVar8 = uVar3;
  }
  uVar4 = (uint)(byte)((unsigned char *)0x000013b2)[param_1];
  bVar1 = false;
  if (uVar4 != 0) {
    uVar7 = 0;
    uVar5 = 0x80000;
    iVar6 = param_1;
    do {
      if (((*(uint *)(param_1 + 0x44) & 0x100000) != 0) &&
         (*(char *)(uVar7 + *(int *)(((unsigned char *)0x00001168) + param_1) + 0x71) == '\0')) {
        bVar1 = true;
      }
      if (*(int *)(((unsigned char *)0x000013f8) + iVar6) != 0) {
        if (*(uint *)(param_2 + 8) <= uVar3) {
          pvVar2 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
          if (*(void **)(param_2 + 0xc) != (void *)0x0) {
            _memcpy(pvVar2,*(void **)(param_2 + 0xc),*puVar8 << 2);
            (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
          }
          *(void **)(param_2 + 0xc) = pvVar2;
          uVar3 = *puVar8;
          *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
        }
        *(undefined4 *)(uVar3 * 4 + *(int *)(param_2 + 0xc)) = 0x1ff0016;
        uVar3 = *puVar8 + 1;
        *puVar8 = uVar3;
        if (*(uint *)(param_2 + 8) <= uVar3) {
          pvVar2 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
          if (*(void **)(param_2 + 0xc) != (void *)0x0) {
            _memcpy(pvVar2,*(void **)(param_2 + 0xc),*puVar8 << 2);
            (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
          }
          *(void **)(param_2 + 0xc) = pvVar2;
          uVar3 = *puVar8;
          *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
        }
        *(uint *)(uVar3 * 4 + *(int *)(param_2 + 0xc)) = uVar7 & 0xffff | 0x110000;
        uVar3 = *puVar8 + 1;
        *puVar8 = uVar3;
        if (*(uint *)(param_2 + 8) <= uVar3) {
          pvVar2 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
          if (*(void **)(param_2 + 0xc) != (void *)0x0) {
            _memcpy(pvVar2,*(void **)(param_2 + 0xc),*puVar8 << 2);
            (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
          }
          *(void **)(param_2 + 0xc) = pvVar2;
          uVar3 = *puVar8;
          *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
        }
        *(uint *)(uVar3 * 4 + *(int *)(param_2 + 0xc)) = uVar7 << 0x10 | 0x19;
        uVar3 = *puVar8 + 1;
        *puVar8 = uVar3;
        if (((int)(uint)*(byte *)(param_1 + 0x20) >> (uVar7 & 0x3f) & 1U) == 0) {
          uVar4 = (uint)(byte)((unsigned char *)0x000013b2)[param_1];
        }
        else {
          if (*(uint *)(param_2 + 8) <= uVar3) {
            pvVar2 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
            if (*(void **)(param_2 + 0xc) != (void *)0x0) {
              _memcpy(pvVar2,*(void **)(param_2 + 0xc),*puVar8 << 2);
              (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
            }
            *(void **)(param_2 + 0xc) = pvVar2;
            uVar3 = *puVar8;
            *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
          }
          *(uint *)(uVar3 * 4 + *(int *)(param_2 + 0xc)) = uVar5 | 0x19;
          uVar3 = *puVar8 + 1;
          *puVar8 = uVar3;
          uVar4 = (uint)(byte)((unsigned char *)0x000013b2)[param_1];
        }
      }
      uVar7 = uVar7 + 1;
      uVar5 = uVar5 + 0x10000;
      iVar6 = iVar6 + 4;
    } while ((int)uVar7 < (int)uVar4);
  }
  if (*(char *)(param_1 + 0x121) != '\0') {
    if (*(uint *)(param_2 + 8) <= uVar3) {
      pvVar2 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
      if (*(void **)(param_2 + 0xc) != (void *)0x0) {
        _memcpy(pvVar2,*(void **)(param_2 + 0xc),*puVar8 << 2);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
      }
      *(void **)(param_2 + 0xc) = pvVar2;
      uVar3 = *puVar8;
      *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
    }
    *(undefined4 *)(uVar3 * 4 + *(int *)(param_2 + 0xc)) = 0x1ff0016;
    uVar3 = *puVar8 + 1;
    *puVar8 = uVar3;
    if (*(uint *)(param_2 + 8) <= uVar3) {
      pvVar2 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
      if (*(void **)(param_2 + 0xc) != (void *)0x0) {
        _memcpy(pvVar2,*(void **)(param_2 + 0xc),*puVar8 << 2);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
      }
      *(void **)(param_2 + 0xc) = pvVar2;
      uVar3 = *puVar8;
      *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
    }
    *(undefined4 *)(uVar3 * 4 + *(int *)(param_2 + 0xc)) = 0x100000;
    uVar3 = *puVar8 + 1;
    *puVar8 = uVar3;
  }
  if (bVar1) {
    if (*(uint *)(param_2 + 8) <= uVar3) {
      pvVar2 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
      if (*(void **)(param_2 + 0xc) != (void *)0x0) {
        _memcpy(pvVar2,*(void **)(param_2 + 0xc),*puVar8 << 2);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
      }
      *(void **)(param_2 + 0xc) = pvVar2;
      uVar3 = *puVar8;
      *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
    }
    *(undefined4 *)(uVar3 * 4 + *(int *)(param_2 + 0xc)) = 0x1c;
    uVar3 = *puVar8 + 1;
    *puVar8 = uVar3;
    if (*(uint *)(param_2 + 8) <= uVar3) {
      pvVar2 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
      if (*(void **)(param_2 + 0xc) != (void *)0x0) {
        _memcpy(pvVar2,*(void **)(param_2 + 0xc),*puVar8 << 2);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
      }
      *(void **)(param_2 + 0xc) = pvVar2;
      uVar3 = *puVar8;
      *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
    }
    *(undefined4 *)(uVar3 * 4 + *(int *)(param_2 + 0xc)) = 0x10011;
    uVar3 = *puVar8 + 1;
    *puVar8 = uVar3;
    if (*(uint *)(param_2 + 8) <= uVar3) {
      pvVar2 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
      if (*(void **)(param_2 + 0xc) != (void *)0x0) {
        _memcpy(pvVar2,*(void **)(param_2 + 0xc),*puVar8 << 2);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
      }
      *(void **)(param_2 + 0xc) = pvVar2;
      uVar3 = *puVar8;
      *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
    }
    *(undefined4 *)(uVar3 * 4 + *(int *)(param_2 + 0xc)) = 0;
    uVar3 = *puVar8 + 1;
    *puVar8 = uVar3;
    if (*(uint *)(param_2 + 8) <= uVar3) {
      pvVar2 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
      if (*(void **)(param_2 + 0xc) != (void *)0x0) {
        _memcpy(pvVar2,*(void **)(param_2 + 0xc),*puVar8 << 2);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
      }
      *(void **)(param_2 + 0xc) = pvVar2;
      uVar3 = *puVar8;
      *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
    }
    *(undefined4 *)(uVar3 * 4 + *(int *)(param_2 + 0xc)) = 0;
    uVar3 = *puVar8 + 1;
    *puVar8 = uVar3;
    if (*(uint *)(param_2 + 8) <= uVar3) {
      pvVar2 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
      if (*(void **)(param_2 + 0xc) != (void *)0x0) {
        _memcpy(pvVar2,*(void **)(param_2 + 0xc),*puVar8 << 2);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
      }
      *(void **)(param_2 + 0xc) = pvVar2;
      uVar3 = *puVar8;
      *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
    }
    *(undefined4 *)(uVar3 * 4 + *(int *)(param_2 + 0xc)) = 0;
    uVar3 = *puVar8 + 1;
    *puVar8 = uVar3;
    if (*(uint *)(param_2 + 8) <= uVar3) {
      pvVar2 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
      if (*(void **)(param_2 + 0xc) != (void *)0x0) {
        _memcpy(pvVar2,*(void **)(param_2 + 0xc),*puVar8 << 2);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
      }
      *(void **)(param_2 + 0xc) = pvVar2;
      uVar3 = *puVar8;
      *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
    }
    *(undefined4 *)(uVar3 * 4 + *(int *)(param_2 + 0xc)) = 0x3f800000;
    *puVar8 = *puVar8 + 1;
  }
  return;
}

/* FUN_000d6340 @ 0xd6340 (4540 bytes) */
int FUN_000d6340(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  int param_2;
  undefined4 param_3;
  uint param_4;
  undefined4 param_5;
  undefined4 param_6;
{
  bool bVar1;
  byte bVar2;
  float fVar3;
  ushort uVar4;
  int iVar5;
  int iVar6;
  void *pvVar7;
  undefined *puVar8;
  undefined *puVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  undefined4 uVar13;
  int *piVar14;
  undefined4 uVar15;
  uint uVar16;
  uint *puVar17;
  uint local_98 [2];
  undefined1 auStack_90 [4];
  uint local_8c [2];
  undefined1 auStack_84 [4];
  uint local_80 [2];
  undefined1 auStack_78 [4];
  uint local_74;
  uint local_70;
  undefined1 auStack_6c [4];
  int local_68 [4];
  uint *local_58;
  
  iVar6 = 0;
  local_58 = &local_74;
  do {
    *(undefined4 *)(iVar6 + (int)local_98) = 0;
    *(undefined4 *)(iVar6 + (int)local_8c) = 0;
    bVar1 = iVar6 != 8;
    *(undefined4 *)(iVar6 + (int)local_80) = 0;
    *(undefined4 *)(iVar6 + (int)local_58) = 0;
    iVar6 = iVar6 + 4;
  } while (bVar1);
  iVar6 = param_4 * 0xcc + param_1;
  puVar17 = (uint *)(param_2 + 4);
  uVar13 = 0;
  ((int (*)())FUN_000d4ef0)(param_1,*(undefined2 *)(iVar6 + 0x456),*(undefined2 *)(iVar6 + 0x462),local_98,
               local_8c,param_4,param_3,param_6);
  ((int (*)())FUN_000d4ef0)(param_1,*(undefined2 *)(iVar6 + 0x458),*(undefined2 *)(iVar6 + 0x464),local_98 + 1,
               local_8c + 1,param_4,param_3,param_6);
  ((int (*)())FUN_000d4ef0)(param_1,*(undefined2 *)(iVar6 + 0x45a),*(undefined2 *)(iVar6 + 0x466),auStack_90,
               auStack_84,param_4,param_3,param_6);
  puVar8 = (undefined *)(uint)*(ushort *)(iVar6 + 0x454);
  fVar3 = *(float *)(iVar6 + 0x474);
  if (puVar8 < (undefined *)0x86b0) {
    if (puVar8 < (undefined *)0x86ae) {
      if (puVar8 == ((unsigned char *)0x00002100)) {
        uVar13 = 0x49;
LAB_000d6560:
        iVar11 = 2;
        local_68[0] = 0;
        puVar9 = puVar8 + -0x10000;
        local_68[1] = 1;
      }
      else if (((unsigned char *)0x00002100) < puVar8) {
        if (puVar8 == (undefined *)0x8574) {
          local_68[0] = 0;
          uVar13 = 3;
          local_68[1] = 1;
          if ((local_98[1] & 0x400000) == 0) {
            local_98[1] = local_98[1] | 0x400000;
            local_8c[1] = local_8c[1] & 0xfffff888 | 0x210;
          }
          iVar11 = 2;
          puVar9 = (undefined *)0xffff8574;
          local_8c[1] = local_8c[1] | 0x20000;
        }
        else if (puVar8 == (undefined *)0x8575) {
          local_68[1] = 0;
          iVar11 = 3;
          uVar13 = 0x3f;
          puVar9 = (undefined *)0xffff8575;
          local_68[2] = 1;
          local_68[0] = 2;
        }
        else {
          if (puVar8 != (undefined *)0x84e7) goto LAB_000d6534;
          iVar11 = 2;
          local_68[0] = 0;
          puVar9 = (undefined *)0xffff84e7;
          uVar13 = 0x5b;
          local_68[1] = 1;
        }
      }
      else {
        if (puVar8 == (undefined *)0x104) {
          uVar13 = 3;
          goto LAB_000d6560;
        }
        if (puVar8 != ((unsigned char *)0x00001e01)) goto LAB_000d6534;
        iVar11 = 1;
        local_68[0] = 0;
        puVar9 = (undefined *)0xffff1e01;
        uVar13 = 0x47;
      }
    }
    else {
LAB_000d64e8:
      puVar9 = puVar8 + -0x10000;
      local_68[0] = 0;
      uVar13 = 0x22;
      local_68[1] = 1;
      if ((local_98[0] & 0x400000) == 0) {
        local_98[0] = local_98[0] | 0x400000;
        local_8c[0] = local_8c[0] & 0xfffff888 | 0x210;
      }
      if ((local_98[1] & 0x400000) == 0) {
        local_98[1] = local_98[1] | 0x400000;
        local_8c[1] = local_8c[1] & 0xfffff888 | 0x210;
      }
      iVar11 = 2;
      local_8c[0] = local_8c[0] | 0x20000;
      local_8c[1] = local_8c[1] | 0x20000;
    }
  }
  else if (puVar8 == (undefined *)0x8744) {
    local_68[0] = 0;
    iVar11 = 3;
    uVar13 = 0x40;
    puVar9 = (undefined *)0xffff8744;
    local_68[2] = 1;
    local_68[1] = 2;
  }
  else if (puVar8 < (undefined *)0x8745) {
    if (puVar8 + -0x8740 < (undefined *)0x2) goto LAB_000d64e8;
LAB_000d6534:
    puVar9 = puVar8 + -0x10000;
    iVar11 = 0;
  }
  else if (puVar8 == (undefined *)0x8745) {
    local_68[0] = 0;
    local_68[1] = 2;
    local_68[2] = 1;
    uVar13 = 0x40;
    if ((local_98[1] & 0x400000) == 0) {
      local_98[1] = local_98[1] | 0x400000;
      local_8c[1] = local_8c[1] & 0xfffff888 | 0x210;
    }
    iVar11 = 3;
    puVar9 = (undefined *)0xffff8745;
    local_8c[1] = local_8c[1] | 0x20000;
  }
  else {
    if (puVar8 != (undefined *)0x8746) goto LAB_000d6534;
    local_68[0] = 0;
    local_68[1] = 2;
    local_68[2] = 1;
    uVar13 = 0x40;
    if ((local_98[1] & 0x400000) == 0) {
      local_98[1] = local_98[1] | 0x400000;
      local_8c[1] = local_8c[1] & 0xfffff888 | 0x210;
    }
    iVar11 = 3;
    puVar9 = (undefined *)0xffff8746;
    local_8c[1] = local_8c[1] | 0x888;
  }
  bVar2 = ((unsigned char *)0x000013b2)[param_1];
  uVar15 = 0x115;
  if (puVar9 + 0x7952 < (undefined *)0x2) {
    if (fVar3 == FLOAT_001aa0e8) {
LAB_000d6840:
      uVar15 = 0x515;
    }
    else if (fVar3 == FLOAT_001aa108) {
      uVar15 = 0x715;
    }
    else {
      uVar15 = 0x715;
      local_8c[0] = local_8c[0] | 0x40000;
    }
  }
  else {
    if (((fVar3 == FLOAT_001aa104) || (puVar8 == (undefined *)0x8740)) ||
       (puVar8 == (undefined *)0x8741)) goto LAB_000d6840;
    if (fVar3 == FLOAT_001aa108) {
      uVar15 = 0x315;
    }
  }
  uVar10 = *puVar17;
  if (*(uint *)(param_2 + 8) <= uVar10) {
    pvVar7 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
    if (*(void **)(param_2 + 0xc) != (void *)0x0) {
      _memcpy(pvVar7,*(void **)(param_2 + 0xc),*puVar17 << 2);
      (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
    }
    *(void **)(param_2 + 0xc) = pvVar7;
    uVar10 = *puVar17;
    *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
  }
  *(undefined4 *)(uVar10 * 4 + *(int *)(param_2 + 0xc)) = uVar13;
  uVar10 = *puVar17 + 1;
  *puVar17 = uVar10;
  if (*(uint *)(param_2 + 8) <= uVar10) {
    pvVar7 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
    if (*(void **)(param_2 + 0xc) != (void *)0x0) {
      _memcpy(pvVar7,*(void **)(param_2 + 0xc),*puVar17 << 2);
      (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
    }
    *(void **)(param_2 + 0xc) = pvVar7;
    uVar10 = *puVar17;
    *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
  }
  *(uint *)(uVar10 * 4 + *(int *)(param_2 + 0xc)) =
       (int)(short)param_4 + (uint)bVar2 & 0xffff | 0x440000;
  uVar10 = *puVar17 + 1;
  *puVar17 = uVar10;
  if (*(uint *)(param_2 + 8) <= uVar10) {
    pvVar7 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
    if (*(void **)(param_2 + 0xc) != (void *)0x0) {
      _memcpy(pvVar7,*(void **)(param_2 + 0xc),*puVar17 << 2);
      (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
    }
    *(void **)(param_2 + 0xc) = pvVar7;
    uVar10 = *puVar17;
    *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
  }
  *(undefined4 *)(uVar10 * 4 + *(int *)(param_2 + 0xc)) = uVar15;
  uVar10 = *puVar17 + 1;
  *puVar17 = uVar10;
  if (iVar11 != 0) {
    iVar12 = 0;
    piVar14 = local_68;
    do {
      iVar5 = *piVar14;
      piVar14 = piVar14 + 1;
      uVar16 = local_98[iVar5];
      if (*(uint *)(param_2 + 8) <= uVar10) {
        pvVar7 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
        if (*(void **)(param_2 + 0xc) != (void *)0x0) {
          _memcpy(pvVar7,*(void **)(param_2 + 0xc),*puVar17 << 2);
          (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
        }
        *(void **)(param_2 + 0xc) = pvVar7;
        uVar10 = *puVar17;
        *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
      }
      *(uint *)(uVar10 * 4 + *(int *)(param_2 + 0xc)) = uVar16;
      uVar10 = *puVar17 + 1;
      *puVar17 = uVar10;
      if ((local_98[iVar5] & 0x400000) != 0) {
        uVar16 = local_8c[iVar5];
        if (*(uint *)(param_2 + 8) <= uVar10) {
          pvVar7 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
          if (*(void **)(param_2 + 0xc) != (void *)0x0) {
            _memcpy(pvVar7,*(void **)(param_2 + 0xc),*puVar17 << 2);
            (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
          }
          *(void **)(param_2 + 0xc) = pvVar7;
          uVar10 = *puVar17;
          *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
        }
        *(uint *)(uVar10 * 4 + *(int *)(param_2 + 0xc)) = uVar16;
        uVar10 = *puVar17 + 1;
        *puVar17 = uVar10;
      }
      iVar12 = iVar12 + 1;
    } while (iVar11 != iVar12);
  }
  if ((*(short *)(iVar6 + 0x454) == -0x78bf) || (*(short *)(iVar6 + 0x454) == -0x7951)) {
    if (*(uint *)(param_2 + 8) <= uVar10) {
      pvVar7 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
      if (*(void **)(param_2 + 0xc) != (void *)0x0) {
        _memcpy(pvVar7,*(void **)(param_2 + 0xc),*puVar17 << 2);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
      }
      *(void **)(param_2 + 0xc) = pvVar7;
      uVar10 = *puVar17;
      *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
    }
    *(undefined4 *)(uVar10 * 4 + *(int *)(param_2 + 0xc)) = 0x47;
    uVar10 = *puVar17 + 1;
    *puVar17 = uVar10;
    bVar2 = ((unsigned char *)0x000013b2)[param_1];
    if (*(uint *)(param_2 + 8) <= uVar10) {
      pvVar7 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
      if (*(void **)(param_2 + 0xc) != (void *)0x0) {
        _memcpy(pvVar7,*(void **)(param_2 + 0xc),*puVar17 << 2);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
      }
      *(void **)(param_2 + 0xc) = pvVar7;
      uVar10 = *puVar17;
      *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
    }
    *(uint *)(uVar10 * 4 + *(int *)(param_2 + 0xc)) =
         (param_4 & 0xffff) + (uint)bVar2 & 0xffff | 0x440000;
    uVar10 = *puVar17 + 1;
    *puVar17 = uVar10;
    if (*(uint *)(param_2 + 8) <= uVar10) {
      pvVar7 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
      if (*(void **)(param_2 + 0xc) != (void *)0x0) {
        _memcpy(pvVar7,*(void **)(param_2 + 0xc),*puVar17 << 2);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
      }
      *(void **)(param_2 + 0xc) = pvVar7;
      uVar10 = *puVar17;
      *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
    }
    *(undefined4 *)(uVar10 * 4 + *(int *)(param_2 + 0xc)) = 0x40;
    uVar10 = *puVar17 + 1;
    *puVar17 = uVar10;
    bVar2 = ((unsigned char *)0x000013b2)[param_1];
    if (*(uint *)(param_2 + 8) <= uVar10) {
      pvVar7 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
      if (*(void **)(param_2 + 0xc) != (void *)0x0) {
        _memcpy(pvVar7,*(void **)(param_2 + 0xc),*puVar17 << 2);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
      }
      *(void **)(param_2 + 0xc) = pvVar7;
      uVar10 = *puVar17;
      *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
    }
    *(uint *)(uVar10 * 4 + *(int *)(param_2 + 0xc)) =
         (param_4 & 0xffff) + (uint)bVar2 & 0xffff | 0x440000;
    uVar10 = *puVar17 + 1;
    *puVar17 = uVar10;
    if (*(uint *)(param_2 + 8) <= uVar10) {
      pvVar7 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
      if (*(void **)(param_2 + 0xc) != (void *)0x0) {
        _memcpy(pvVar7,*(void **)(param_2 + 0xc),*puVar17 << 2);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
      }
      *(void **)(param_2 + 0xc) = pvVar7;
      uVar10 = *puVar17;
      *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
    }
    *(undefined4 *)(uVar10 * 4 + *(int *)(param_2 + 0xc)) = 0;
    *puVar17 = *puVar17 + 1;
    return;
  }
  uVar13 = 0;
  ((int (*)())FUN_000d51a0)(param_1,*(undefined2 *)(iVar6 + 0x45c),*(undefined2 *)(iVar6 + 0x468),local_80,
               local_58,param_4,param_3,param_6);
  ((int (*)())FUN_000d51a0)(param_1,*(undefined2 *)(iVar6 + 0x45e),*(undefined2 *)(iVar6 + 0x46a),local_80 + 1,
               &local_70,param_4,param_3,param_6);
  ((int (*)())FUN_000d51a0)(param_1,*(undefined2 *)(iVar6 + 0x460),*(undefined2 *)(iVar6 + 0x46c),auStack_78,
               auStack_6c,param_4,param_3,param_6);
  uVar4 = *(ushort *)(iVar6 + 0x452);
  fVar3 = *(float *)(iVar6 + 0x478);
  if (uVar4 == 0x8574) {
    local_68[0] = 0;
    uVar13 = 3;
    local_68[1] = 1;
    if ((local_80[1] & 0x400000) == 0) {
      local_80[1] = local_80[1] | 0x400000;
      local_70 = local_70 & 0xffff8fff | 0x3000;
    }
    iVar6 = 2;
    local_70 = local_70 | 0x20000;
  }
  else if (uVar4 < 0x8575) {
    if (uVar4 == 0x1e01) {
      iVar6 = 1;
      local_68[0] = 0;
      uVar13 = 0x47;
    }
    else {
      if (uVar4 < 0x1e02) {
        if (uVar4 != 0x104) {
LAB_000d6fbc:
          iVar6 = 0;
          goto LAB_000d7144;
        }
        uVar13 = 3;
      }
      else if (uVar4 == 0x2100) {
        uVar13 = 0x49;
      }
      else {
        if (uVar4 != 0x84e7) goto LAB_000d6fbc;
        uVar13 = 0x5b;
      }
      iVar6 = 2;
      local_68[0] = 0;
      local_68[1] = 1;
    }
  }
  else if (uVar4 == 0x8744) {
    local_68[0] = 0;
    iVar6 = 3;
    uVar13 = 0x40;
    local_68[2] = 1;
    local_68[1] = 2;
  }
  else if (uVar4 < 0x8745) {
    if (uVar4 != 0x8575) goto LAB_000d6fbc;
    local_68[1] = 0;
    iVar6 = 3;
    uVar13 = 0x3f;
    local_68[2] = 1;
    local_68[0] = 2;
  }
  else if (uVar4 == 0x8745) {
    local_68[0] = 0;
    uVar13 = 0x40;
    local_68[2] = 1;
    local_68[1] = 2;
    if ((local_80[1] & 0x400000) == 0) {
      local_80[1] = local_80[1] | 0x400000;
      local_70 = local_70 & 0xffff8fff | 0x3000;
    }
    iVar6 = 3;
    local_70 = local_70 | 0x20000;
  }
  else {
    if (uVar4 != 0x8746) goto LAB_000d6fbc;
    local_68[0] = 0;
    local_68[1] = 2;
    uVar13 = 0x40;
    local_68[2] = 1;
    if ((local_80[1] & 0x400000) == 0) {
      local_80[1] = local_80[1] | 0x400000;
      local_70 = local_70 & 0xffff8fff | 0x3000;
    }
    iVar6 = 3;
    local_70 = local_70 | 0x8000;
  }
LAB_000d7144:
  bVar2 = ((unsigned char *)0x000013b2)[param_1];
  uVar15 = 0x140;
  if (uVar4 == 0x86af) {
    if (fVar3 != FLOAT_001aa0e8) {
      if (fVar3 == FLOAT_001aa108) {
        uVar15 = 0x740;
      }
      else {
        uVar15 = 0x740;
        local_74 = local_74 | 0x40000;
      }
      goto LAB_000d7214;
    }
  }
  else if ((fVar3 != FLOAT_001aa104) && (uVar4 != 0x8741)) {
    if (fVar3 == FLOAT_001aa108) {
      uVar15 = 0x340;
    }
    goto LAB_000d7214;
  }
  uVar15 = 0x540;
LAB_000d7214:
  uVar10 = *puVar17;
  if (*(uint *)(param_2 + 8) <= uVar10) {
    pvVar7 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
    if (*(void **)(param_2 + 0xc) != (void *)0x0) {
      _memcpy(pvVar7,*(void **)(param_2 + 0xc),*puVar17 << 2);
      (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
    }
    *(void **)(param_2 + 0xc) = pvVar7;
    uVar10 = *puVar17;
    *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
  }
  *(undefined4 *)(uVar10 * 4 + *(int *)(param_2 + 0xc)) = uVar13;
  uVar10 = *puVar17 + 1;
  *puVar17 = uVar10;
  if (*(uint *)(param_2 + 8) <= uVar10) {
    pvVar7 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
    if (*(void **)(param_2 + 0xc) != (void *)0x0) {
      _memcpy(pvVar7,*(void **)(param_2 + 0xc),*puVar17 << 2);
      (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
    }
    *(void **)(param_2 + 0xc) = pvVar7;
    uVar10 = *puVar17;
    *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
  }
  *(uint *)(uVar10 * 4 + *(int *)(param_2 + 0xc)) =
       (int)(short)param_4 + (uint)bVar2 & 0xffff | 0x440000;
  uVar10 = *puVar17 + 1;
  *puVar17 = uVar10;
  if (*(uint *)(param_2 + 8) <= uVar10) {
    pvVar7 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
    if (*(void **)(param_2 + 0xc) != (void *)0x0) {
      _memcpy(pvVar7,*(void **)(param_2 + 0xc),*puVar17 << 2);
      (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
    }
    *(void **)(param_2 + 0xc) = pvVar7;
    uVar10 = *puVar17;
    *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
  }
  *(undefined4 *)(uVar10 * 4 + *(int *)(param_2 + 0xc)) = uVar15;
  uVar10 = *puVar17 + 1;
  *puVar17 = uVar10;
  if (iVar6 != 0) {
    iVar11 = 0;
    piVar14 = local_68;
    do {
      iVar12 = *piVar14;
      piVar14 = piVar14 + 1;
      uVar16 = local_80[iVar12];
      if (*(uint *)(param_2 + 8) <= uVar10) {
        pvVar7 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
        if (*(void **)(param_2 + 0xc) != (void *)0x0) {
          _memcpy(pvVar7,*(void **)(param_2 + 0xc),*puVar17 << 2);
          (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
        }
        *(void **)(param_2 + 0xc) = pvVar7;
        uVar10 = *puVar17;
        *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
      }
      *(uint *)(uVar10 * 4 + *(int *)(param_2 + 0xc)) = uVar16;
      uVar10 = *puVar17 + 1;
      *puVar17 = uVar10;
      if ((local_80[iVar12] & 0x400000) != 0) {
        uVar16 = local_58[iVar12];
        if (*(uint *)(param_2 + 8) <= uVar10) {
          pvVar7 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
          if (*(void **)(param_2 + 0xc) != (void *)0x0) {
            _memcpy(pvVar7,*(void **)(param_2 + 0xc),*puVar17 << 2);
            (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
          }
          *(void **)(param_2 + 0xc) = pvVar7;
          uVar10 = *puVar17;
          *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
        }
        *(uint *)(uVar10 * 4 + *(int *)(param_2 + 0xc)) = uVar16;
        uVar10 = *puVar17 + 1;
        *puVar17 = uVar10;
      }
      iVar11 = iVar11 + 1;
    } while (iVar6 != iVar11);
  }
  return;
}

/* FUN_000d7520 @ 0xd7520 (3832 bytes) */
int FUN_000d7520(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  int param_2;
  uint param_3;
  undefined *param_4;
  uint param_5;
  int param_6;
  int param_7;
  int param_8;
{
  uint uVar1;
  void *pvVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined4 uVar6;
  undefined *puVar7;
  undefined *puVar8;
  uint uVar9;
  undefined4 uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint *puVar15;
  
  puVar15 = (uint *)(param_2 + 4);
  uVar13 = 0;
  uVar12 = 0;
  uVar9 = 0;
  puVar8 = (undefined *)0x0;
  puVar7 = (undefined *)0x0;
  uVar5 = 0;
  uVar6 = 0;
  if ((((param_3 == 0x1902) || (param_3 == 0x81a5)) || (param_3 == 0x81a7)) || (param_3 == 0x81a6))
  {
    param_3 = (uint)*(ushort *)(param_6 + 0x58);
  }
  uVar1 = (uint)(byte)((unsigned char *)0x000013b2)[param_1];
  param_5 = param_5 & 0xffff;
  uVar10 = 0;
  uVar4 = param_5 + uVar1 & 0xffff;
  uVar11 = uVar4 | 0x40000;
  if (param_4 == ((unsigned char *)0x00001e01)) {
    if (param_3 != 0x1908) {
      if (param_3 < 0x1909) {
        if (param_3 == 0x1906) {
          uVar10 = 3;
          if (param_7 == 0) {
            uVar13 = uVar1 + param_8 & 0xffff | 0x40000;
          }
          else {
            uVar13 = 0x120000;
          }
          uVar3 = *puVar15;
          uVar13 = uVar13 | 0x400000;
          uVar14 = 2;
          uVar12 = param_5 | 0x440000;
          puVar7 = ((unsigned char *)0x00003444);
          puVar8 = ((unsigned char *)0x00004210);
          goto LAB_000d75e8;
        }
        if (param_3 != 0x1907) goto LAB_000d75e0;
LAB_000d7d84:
        uVar10 = 3;
        if (param_7 == 0) {
          uVar13 = uVar1 + param_8 & 0xffff | 0x40000;
        }
        else {
          uVar13 = 0x120000;
        }
        uVar3 = *puVar15;
        uVar13 = uVar13 | 0x400000;
        uVar14 = 2;
        uVar12 = param_5 | 0x440000;
        puVar8 = ((unsigned char *)0x00003444);
        puVar7 = ((unsigned char *)0x00004210);
        goto LAB_000d75e8;
      }
      if (param_3 != 0x190a) {
        if (param_3 < 0x190a) goto LAB_000d7d84;
        if (param_3 != 0x8049) goto LAB_000d75e0;
      }
    }
    uVar3 = *puVar15;
    uVar14 = 1;
    uVar10 = 0x47;
    uVar13 = param_5 | 0x40000;
    goto LAB_000d75e8;
  }
  if (((unsigned char *)0x00001e01) < param_4) {
    if (param_4 == ((unsigned char *)0x00002100)) {
      if (param_3 == 0x1906) {
        uVar10 = 0x49;
        if (param_7 == 0) {
          uVar12 = uVar1 + param_8 & 0xffff | 0x40000;
        }
        else {
          uVar12 = 0x120000;
        }
        uVar3 = *puVar15;
        uVar13 = param_5 | 0x440000;
        uVar14 = 2;
        puVar8 = ((unsigned char *)0x00003555);
      }
      else if (param_3 == 0x1907) {
        uVar10 = 0x49;
        if (param_7 == 0) {
          uVar12 = uVar1 + param_8 & 0xffff | 0x40000;
        }
        else {
          uVar12 = 0x120000;
        }
        uVar3 = *puVar15;
        uVar13 = param_5 | 0x440000;
        uVar14 = 2;
        puVar8 = ((unsigned char *)0x00005210);
      }
      else {
        uVar10 = 0x49;
        uVar13 = param_5 | 0x40000;
        if (param_7 == 0) {
          uVar3 = *puVar15;
          uVar14 = 2;
          uVar12 = uVar1 + param_8 & 0xffff | 0x40000;
        }
        else {
          uVar3 = *puVar15;
          uVar14 = 2;
          uVar12 = 0x120000;
        }
      }
      goto LAB_000d75e8;
    }
    if (param_4 == ((unsigned char *)0x00002101)) {
      if (param_3 == 0x1907) {
        uVar10 = 3;
        if (param_7 == 0) {
          uVar12 = uVar1 + param_8 & 0xffff | 0x40000;
        }
        else {
          uVar12 = 0x120000;
        }
        uVar3 = *puVar15;
        uVar13 = param_5 | 0x440000;
        uVar12 = uVar12 | 0x400000;
        uVar14 = 2;
        puVar8 = ((unsigned char *)0x00004210);
        puVar7 = ((unsigned char *)0x00003444);
        goto LAB_000d75e8;
      }
      if (param_3 == 0x1908) {
        uVar10 = 0x3f;
        if (param_7 == 0) {
          uVar9 = uVar1 + param_8 & 0xffff | 0x40000;
        }
        else {
          uVar9 = 0x120000;
        }
        uVar3 = *puVar15;
        uVar13 = param_5 | 0x440000;
        uVar12 = param_5 | 0x440000;
        uVar14 = 3;
        puVar8 = ((unsigned char *)0x00004333);
        puVar7 = ((unsigned char *)0x00004210);
        goto LAB_000d75e8;
      }
    }
  }
  else {
    if (param_4 == (undefined *)0x104) {
      uVar10 = 0x40;
      if (param_7 == 0) {
        uVar13 = uVar1 + param_8 & 0xffff | 0x40000;
      }
      else {
        uVar13 = 0x120000;
      }
      uVar12 = param_5 | 0x440000;
      uVar9 = param_5 | 0x440000;
      if (param_3 < 0x190b) {
        if (0x1906 < param_3) {
LAB_000d7ee4:
          puVar7 = (undefined *)0x555;
          uVar5 = 0x210;
          goto LAB_000d7f0c;
        }
        if (param_3 != 0x1906) goto LAB_000d7f0c;
        uVar5 = 0x444;
        puVar7 = (undefined *)0x555;
      }
      else {
        if (param_3 == 0x8049) goto LAB_000d7ee4;
LAB_000d7f0c:
        if (param_3 == 0x8049) {
          uVar3 = *puVar15;
          uVar14 = 3;
          puVar7 = (undefined *)((uint)puVar7 | 0x5000);
          uVar5 = uVar5 | 0x3000;
          goto LAB_000d75e8;
        }
      }
      uVar3 = *puVar15;
      uVar14 = 3;
      puVar7 = (undefined *)((uint)puVar7 | 0x3000);
      uVar5 = uVar5 | 0x4000;
      goto LAB_000d75e8;
    }
    if ((param_4 == (undefined *)0xbe2) && (0x1905 < param_3)) {
      if (param_3 < 0x190b) {
        if (param_7 == 0) {
          uVar9 = uVar1 + param_8 & 0xffff | 0x40000;
        }
        else {
          uVar9 = 0x120000;
        }
        uVar13 = *puVar15;
        if (*(uint *)(param_2 + 8) <= uVar13) {
          pvVar2 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
          if (*(void **)(param_2 + 0xc) != (void *)0x0) {
            _memcpy(pvVar2,*(void **)(param_2 + 0xc),*puVar15 << 2);
            (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
          }
          *(void **)(param_2 + 0xc) = pvVar2;
          uVar13 = *puVar15;
          *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
        }
        *(undefined4 *)(uVar13 * 4 + *(int *)(param_2 + 0xc)) = 0x3f;
        uVar13 = *puVar15 + 1;
        *puVar15 = uVar13;
        if (*(uint *)(param_2 + 8) <= uVar13) {
          pvVar2 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
          if (*(void **)(param_2 + 0xc) != (void *)0x0) {
            _memcpy(pvVar2,*(void **)(param_2 + 0xc),*puVar15 << 2);
            (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
          }
          *(void **)(param_2 + 0xc) = pvVar2;
          uVar13 = *puVar15;
          *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
        }
        *(uint *)(uVar13 * 4 + *(int *)(param_2 + 0xc)) = uVar4 | 0x440000;
        uVar13 = *puVar15 + 1;
        *puVar15 = uVar13;
        if (*(uint *)(param_2 + 8) <= uVar13) {
          pvVar2 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
          if (*(void **)(param_2 + 0xc) != (void *)0x0) {
            _memcpy(pvVar2,*(void **)(param_2 + 0xc),*puVar15 << 2);
            (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
          }
          *(void **)(param_2 + 0xc) = pvVar2;
          uVar13 = *puVar15;
          *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
        }
        *(undefined4 *)(uVar13 * 4 + *(int *)(param_2 + 0xc)) = 0x15;
        uVar13 = *puVar15 + 1;
        *puVar15 = uVar13;
        if (*(uint *)(param_2 + 8) <= uVar13) {
          pvVar2 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
          if (*(void **)(param_2 + 0xc) != (void *)0x0) {
            _memcpy(pvVar2,*(void **)(param_2 + 0xc),*puVar15 << 2);
            (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
          }
          *(void **)(param_2 + 0xc) = pvVar2;
          uVar13 = *puVar15;
          *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
        }
        *(uint *)(uVar13 * 4 + *(int *)(param_2 + 0xc)) = param_5 | 0x40000;
        uVar13 = *puVar15 + 1;
        *puVar15 = uVar13;
        if (*(uint *)(param_2 + 8) <= uVar13) {
          pvVar2 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
          if (*(void **)(param_2 + 0xc) != (void *)0x0) {
            _memcpy(pvVar2,*(void **)(param_2 + 0xc),*puVar15 << 2);
            (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
          }
          *(void **)(param_2 + 0xc) = pvVar2;
          uVar13 = *puVar15;
          *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
        }
        *(uint *)(uVar13 * 4 + *(int *)(param_2 + 0xc)) = param_5 | 0x10000;
        uVar13 = *puVar15 + 1;
        *puVar15 = uVar13;
        if (*(uint *)(param_2 + 8) <= uVar13) {
          pvVar2 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
          if (*(void **)(param_2 + 0xc) != (void *)0x0) {
            _memcpy(pvVar2,*(void **)(param_2 + 0xc),*puVar15 << 2);
            (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
          }
          *(void **)(param_2 + 0xc) = pvVar2;
          uVar13 = *puVar15;
          *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
        }
        uVar10 = 0x49;
        *(uint *)(uVar13 * 4 + *(int *)(param_2 + 0xc)) = uVar9;
        uVar13 = param_5 | 0x40000;
        uVar3 = *puVar15 + 1;
        *puVar15 = uVar3;
        if (param_7 == 0) {
          uVar12 = param_8 + (uint)(byte)((unsigned char *)0x000013b2)[param_1] & 0xffff | 0x40000;
        }
        else {
          uVar12 = 0x120000;
        }
        uVar14 = 2;
        uVar11 = uVar4 | 0x440000;
        uVar6 = 0x40;
        goto LAB_000d75e8;
      }
      if (param_3 == 0x8049) {
        uVar10 = 0x3f;
        uVar13 = param_5 | 0x40000;
        uVar12 = param_5 | 0x10000;
        if (param_7 == 0) {
          uVar3 = *puVar15;
          uVar14 = 0;
          uVar9 = uVar1 + param_8 & 0xffff | 0x40000;
        }
        else {
          uVar3 = *puVar15;
          uVar14 = 0;
          uVar9 = 0x120000;
        }
        goto LAB_000d75e8;
      }
    }
  }
LAB_000d75e0:
  uVar3 = *puVar15;
  uVar14 = 0;
LAB_000d75e8:
  if (*(uint *)(param_2 + 8) <= uVar3) {
    pvVar2 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
    if (*(void **)(param_2 + 0xc) != (void *)0x0) {
      _memcpy(pvVar2,*(void **)(param_2 + 0xc),*puVar15 << 2);
      (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
    }
    *(void **)(param_2 + 0xc) = pvVar2;
    uVar3 = *puVar15;
    *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
  }
  *(undefined4 *)(uVar3 * 4 + *(int *)(param_2 + 0xc)) = uVar10;
  uVar4 = *puVar15 + 1;
  *puVar15 = uVar4;
  if (*(uint *)(param_2 + 8) <= uVar4) {
    pvVar2 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
    if (*(void **)(param_2 + 0xc) != (void *)0x0) {
      _memcpy(pvVar2,*(void **)(param_2 + 0xc),*puVar15 << 2);
      (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
    }
    *(void **)(param_2 + 0xc) = pvVar2;
    uVar4 = *puVar15;
    *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
  }
  *(uint *)(uVar4 * 4 + *(int *)(param_2 + 0xc)) = uVar11;
  uVar4 = *puVar15 + 1;
  *puVar15 = uVar4;
  if ((uVar11 & 0x400000) != 0) {
    if (*(uint *)(param_2 + 8) <= uVar4) {
      pvVar2 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
      if (*(void **)(param_2 + 0xc) != (void *)0x0) {
        _memcpy(pvVar2,*(void **)(param_2 + 0xc),*puVar15 << 2);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
      }
      *(void **)(param_2 + 0xc) = pvVar2;
      uVar4 = *puVar15;
      *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
    }
    *(undefined4 *)(uVar4 * 4 + *(int *)(param_2 + 0xc)) = uVar6;
    uVar4 = *puVar15 + 1;
    *puVar15 = uVar4;
  }
  if (uVar14 != 0) {
    if (*(uint *)(param_2 + 8) <= uVar4) {
      pvVar2 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
      if (*(void **)(param_2 + 0xc) != (void *)0x0) {
        _memcpy(pvVar2,*(void **)(param_2 + 0xc),*puVar15 << 2);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
      }
      *(void **)(param_2 + 0xc) = pvVar2;
      uVar4 = *puVar15;
      *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
    }
    *(uint *)(uVar4 * 4 + *(int *)(param_2 + 0xc)) = uVar13;
    uVar4 = *puVar15 + 1;
    *puVar15 = uVar4;
    if ((uVar13 & 0x400000) != 0) {
      if (*(uint *)(param_2 + 8) <= uVar4) {
        pvVar2 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
        if (*(void **)(param_2 + 0xc) != (void *)0x0) {
          _memcpy(pvVar2,*(void **)(param_2 + 0xc),*puVar15 << 2);
          (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
        }
        *(void **)(param_2 + 0xc) = pvVar2;
        uVar4 = *puVar15;
        *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
      }
      *(undefined **)(uVar4 * 4 + *(int *)(param_2 + 0xc)) = puVar8;
      uVar4 = *puVar15 + 1;
      *puVar15 = uVar4;
    }
  }
  if (1 < uVar14) {
    if (*(uint *)(param_2 + 8) <= uVar4) {
      pvVar2 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
      if (*(void **)(param_2 + 0xc) != (void *)0x0) {
        _memcpy(pvVar2,*(void **)(param_2 + 0xc),*puVar15 << 2);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
      }
      *(void **)(param_2 + 0xc) = pvVar2;
      uVar4 = *puVar15;
      *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
    }
    *(uint *)(uVar4 * 4 + *(int *)(param_2 + 0xc)) = uVar12;
    uVar4 = *puVar15 + 1;
    *puVar15 = uVar4;
    if ((uVar12 & 0x400000) != 0) {
      if (*(uint *)(param_2 + 8) <= uVar4) {
        pvVar2 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
        if (*(void **)(param_2 + 0xc) != (void *)0x0) {
          _memcpy(pvVar2,*(void **)(param_2 + 0xc),*puVar15 << 2);
          (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
        }
        *(void **)(param_2 + 0xc) = pvVar2;
        uVar4 = *puVar15;
        *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
      }
      *(undefined **)(uVar4 * 4 + *(int *)(param_2 + 0xc)) = puVar7;
      uVar4 = *puVar15 + 1;
      *puVar15 = uVar4;
    }
  }
  if (2 < uVar14) {
    if (*(uint *)(param_2 + 8) <= uVar4) {
      pvVar2 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
      if (*(void **)(param_2 + 0xc) != (void *)0x0) {
        _memcpy(pvVar2,*(void **)(param_2 + 0xc),*puVar15 << 2);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
      }
      *(void **)(param_2 + 0xc) = pvVar2;
      uVar4 = *puVar15;
      *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
    }
    *(uint *)(uVar4 * 4 + *(int *)(param_2 + 0xc)) = uVar9;
    uVar13 = *puVar15 + 1;
    *puVar15 = uVar13;
    if ((uVar9 & 0x400000) != 0) {
      if (*(uint *)(param_2 + 8) <= uVar13) {
        pvVar2 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
        if (*(void **)(param_2 + 0xc) != (void *)0x0) {
          _memcpy(pvVar2,*(void **)(param_2 + 0xc),*puVar15 << 2);
          (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
        }
        *(void **)(param_2 + 0xc) = pvVar2;
        uVar13 = *puVar15;
        *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
      }
      *(uint *)(uVar13 * 4 + *(int *)(param_2 + 0xc)) = uVar5;
      *puVar15 = *puVar15 + 1;
    }
  }
  return;
}

/* FUN_000d8450 @ 0xd8450 (5856 bytes) */
int FUN_000d8450(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  bool bVar1;
  uint uVar2;
  void *pvVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  char *pcVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  undefined *puVar13;
  uint *puVar14;
  int iStack00000020;
  char acStack_68 [28];
  
  puVar14 = (uint *)(param_2 + 4);
  uVar4 = (uint)(byte)((unsigned char *)0x000013b2)[param_1];
  if (uVar4 != 0) {
    uVar10 = 0;
    iVar5 = param_1 + 0x450;
    iVar6 = param_1;
    iVar7 = param_1;
    iVar8 = param_1;
    iStack00000020 = param_3;
    do {
      if (*(int *)(((unsigned char *)0x000013f8) + iVar7) != 0) {
        bVar1 = false;
        if ((*(uint *)(param_1 + 0x44) & 0x100000) != 0) {
          bVar1 = *(char *)(uVar10 + *(int *)(((unsigned char *)0x00001168) + param_1) + 0x71) == '\0';
        }
        if (((int)(uint)*(byte *)(param_1 + 0x20) >> (uVar10 & 0x3f) & 1U) == 0) {
          if ((*(short *)(iVar8 + 0x450) != -0x7a90) || (*(short *)(iVar5 + 4) != -0x7885)) {
            uVar4 = *puVar14;
            if (*(uint *)(param_2 + 8) <= uVar4) {
              pvVar3 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
              if (*(void **)(param_2 + 0xc) != (void *)0x0) {
                _memcpy(pvVar3,*(void **)(param_2 + 0xc),*puVar14 << 2);
                (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
              }
              *(void **)(param_2 + 0xc) = pvVar3;
              uVar4 = *puVar14;
              *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
            }
            *(uint *)(uVar4 * 4 + *(int *)(param_2 + 0xc)) = (uVar10 & 0xff) << 0x10 | 0x800005d;
            uVar4 = *puVar14 + 1;
            *puVar14 = uVar4;
            if (*(uint *)(param_2 + 8) <= uVar4) {
              pvVar3 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
              if (*(void **)(param_2 + 0xc) != (void *)0x0) {
                _memcpy(pvVar3,*(void **)(param_2 + 0xc),*puVar14 << 2);
                (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
              }
              *(void **)(param_2 + 0xc) = pvVar3;
              uVar4 = *puVar14;
              *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
            }
            *(uint *)(uVar4 * 4 + *(int *)(param_2 + 0xc)) = uVar10 & 0xffff | 0x40000;
            uVar4 = *puVar14 + 1;
            *puVar14 = uVar4;
            if ((iStack00000020 == 0) || (acStack_68[uVar10] == '\0')) {
              if ((bVar1) &&
                 (((*(uint *)(param_1 + 0x44) & 0x20000000) == 0 ||
                  ((1 << (uVar10 & 0x3f) & *(uint *)(param_1 + 0xec)) == 0)))) {
                uVar11 = 0x10011;
              }
              else {
                uVar11 = uVar10 & 0xffff | 0x110000;
              }
            }
            else {
              uVar11 = uVar10 + (uint)(byte)((unsigned char *)0x000013b2)[param_1] * 2 & 0xffff | 0x40000;
            }
            if (*(uint *)(param_2 + 8) <= uVar4) {
              pvVar3 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
              if (*(void **)(param_2 + 0xc) != (void *)0x0) {
                _memcpy(pvVar3,*(void **)(param_2 + 0xc),*puVar14 << 2);
                (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
              }
              *(void **)(param_2 + 0xc) = pvVar3;
              uVar4 = *puVar14;
              *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
            }
            *(uint *)(uVar4 * 4 + *(int *)(param_2 + 0xc)) = uVar11 | 0x400000;
            uVar4 = *puVar14 + 1;
            *puVar14 = uVar4;
            if (*(uint *)(param_2 + 8) <= uVar4) {
              pvVar3 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
              if (*(void **)(param_2 + 0xc) != (void *)0x0) {
                _memcpy(pvVar3,*(void **)(param_2 + 0xc),*puVar14 << 2);
                (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
              }
              *(void **)(param_2 + 0xc) = pvVar3;
              uVar4 = *puVar14;
              *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
            }
            *(undefined4 *)(uVar4 * 4 + *(int *)(param_2 + 0xc)) = 0x603210;
            *puVar14 = *puVar14 + 1;
            uVar4 = (uint)(byte)((unsigned char *)0x000013b2)[param_1];
          }
        }
        else {
          uVar4 = *puVar14;
          if (*(uint *)(param_2 + 8) <= uVar4) {
            pvVar3 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
            if (*(void **)(param_2 + 0xc) != (void *)0x0) {
              _memcpy(pvVar3,*(void **)(param_2 + 0xc),*puVar14 << 2);
              (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
            }
            *(void **)(param_2 + 0xc) = pvVar3;
            uVar4 = *puVar14;
            *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
          }
          *(undefined4 *)(uVar4 * 4 + *(int *)(param_2 + 0xc)) = 0x49;
          uVar4 = *puVar14 + 1;
          *puVar14 = uVar4;
          if (*(uint *)(param_2 + 8) <= uVar4) {
            pvVar3 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
            if (*(void **)(param_2 + 0xc) != (void *)0x0) {
              _memcpy(pvVar3,*(void **)(param_2 + 0xc),*puVar14 << 2);
              (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
            }
            *(void **)(param_2 + 0xc) = pvVar3;
            uVar4 = *puVar14;
            *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
          }
          uVar11 = uVar10 & 0xffff;
          *(undefined **)(uVar4 * 4 + *(int *)(param_2 + 0xc)) = ((unsigned char *)0x00040020);
          uVar4 = *puVar14 + 1;
          *puVar14 = uVar4;
          if (*(uint *)(param_2 + 8) <= uVar4) {
            pvVar3 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
            if (*(void **)(param_2 + 0xc) != (void *)0x0) {
              _memcpy(pvVar3,*(void **)(param_2 + 0xc),*puVar14 << 2);
              (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
            }
            *(void **)(param_2 + 0xc) = pvVar3;
            uVar4 = *puVar14;
            *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
          }
          uVar2 = uVar11 + 0x14 & 0xffff;
          *(uint *)(uVar4 * 4 + *(int *)(param_2 + 0xc)) = uVar11 | 0x110000;
          uVar4 = *puVar14 + 1;
          *puVar14 = uVar4;
          if (*(uint *)(param_2 + 8) <= uVar4) {
            pvVar3 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
            if (*(void **)(param_2 + 0xc) != (void *)0x0) {
              _memcpy(pvVar3,*(void **)(param_2 + 0xc),*puVar14 << 2);
              (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
            }
            *(void **)(param_2 + 0xc) = pvVar3;
            uVar4 = *puVar14;
            *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
          }
          pcVar9 = (char *)(iVar6 + 0x21);
          *(uint *)(uVar4 * 4 + *(int *)(param_2 + 0xc)) = uVar2 | 0x410000;
          uVar4 = *puVar14 + 1;
          *puVar14 = uVar4;
          if (*(char *)(iVar6 + 0x21) == '\x01') {
            uVar12 = 0x50;
          }
          else {
            uVar12 = 5;
          }
          if (*(uint *)(param_2 + 8) <= uVar4) {
            pvVar3 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
            if (*(void **)(param_2 + 0xc) != (void *)0x0) {
              _memcpy(pvVar3,*(void **)(param_2 + 0xc),*puVar14 << 2);
              (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
            }
            *(void **)(param_2 + 0xc) = pvVar3;
            uVar4 = *puVar14;
            *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
          }
          *(uint *)(uVar4 * 4 + *(int *)(param_2 + 0xc)) = uVar12 | 0x5500;
          uVar4 = *puVar14 + 1;
          *puVar14 = uVar4;
          if (*(uint *)(param_2 + 8) <= uVar4) {
            pvVar3 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
            if (*(void **)(param_2 + 0xc) != (void *)0x0) {
              _memcpy(pvVar3,*(void **)(param_2 + 0xc),*puVar14 << 2);
              (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
            }
            *(void **)(param_2 + 0xc) = pvVar3;
            uVar4 = *puVar14;
            *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
          }
          *(uint *)(uVar4 * 4 + *(int *)(param_2 + 0xc)) = (uVar10 & 0xff) << 0x10 | 0x800005d;
          uVar4 = *puVar14 + 1;
          *puVar14 = uVar4;
          if (*(uint *)(param_2 + 8) <= uVar4) {
            pvVar3 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
            if (*(void **)(param_2 + 0xc) != (void *)0x0) {
              _memcpy(pvVar3,*(void **)(param_2 + 0xc),*puVar14 << 2);
              (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
            }
            *(void **)(param_2 + 0xc) = pvVar3;
            uVar4 = *puVar14;
            *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
          }
          *(undefined **)(uVar4 * 4 + *(int *)(param_2 + 0xc)) = ((unsigned char *)0x00040020);
          uVar4 = *puVar14 + 1;
          *puVar14 = uVar4;
          if (*(uint *)(param_2 + 8) <= uVar4) {
            pvVar3 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
            if (*(void **)(param_2 + 0xc) != (void *)0x0) {
              _memcpy(pvVar3,*(void **)(param_2 + 0xc),*puVar14 << 2);
              (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
            }
            *(void **)(param_2 + 0xc) = pvVar3;
            uVar4 = *puVar14;
            *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
          }
          *(undefined4 *)(uVar4 * 4 + *(int *)(param_2 + 0xc)) = 0x440020;
          uVar4 = *puVar14 + 1;
          *puVar14 = uVar4;
          if (*(uint *)(param_2 + 8) <= uVar4) {
            pvVar3 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
            if (*(void **)(param_2 + 0xc) != (void *)0x0) {
              _memcpy(pvVar3,*(void **)(param_2 + 0xc),*puVar14 << 2);
              (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
            }
            *(void **)(param_2 + 0xc) = pvVar3;
            uVar4 = *puVar14;
            *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
          }
          *(undefined4 *)(uVar4 * 4 + *(int *)(param_2 + 0xc)) = 0x603210;
          uVar4 = *puVar14 + 1;
          *puVar14 = uVar4;
          if (*(uint *)(param_2 + 8) <= uVar4) {
            pvVar3 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
            if (*(void **)(param_2 + 0xc) != (void *)0x0) {
              _memcpy(pvVar3,*(void **)(param_2 + 0xc),*puVar14 << 2);
              (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
            }
            *(void **)(param_2 + 0xc) = pvVar3;
            uVar4 = *puVar14;
            *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
          }
          *(undefined4 *)(uVar4 * 4 + *(int *)(param_2 + 0xc)) = 0x40;
          uVar4 = *puVar14 + 1;
          *puVar14 = uVar4;
          if (*(uint *)(param_2 + 8) <= uVar4) {
            pvVar3 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
            if (*(void **)(param_2 + 0xc) != (void *)0x0) {
              _memcpy(pvVar3,*(void **)(param_2 + 0xc),*puVar14 << 2);
              (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
            }
            *(void **)(param_2 + 0xc) = pvVar3;
            uVar4 = *puVar14;
            *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
          }
          *(undefined **)(uVar4 * 4 + *(int *)(param_2 + 0xc)) = ((unsigned char *)0x00040021);
          uVar4 = *puVar14 + 1;
          *puVar14 = uVar4;
          if (*(uint *)(param_2 + 8) <= uVar4) {
            pvVar3 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
            if (*(void **)(param_2 + 0xc) != (void *)0x0) {
              _memcpy(pvVar3,*(void **)(param_2 + 0xc),*puVar14 << 2);
              (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
            }
            *(void **)(param_2 + 0xc) = pvVar3;
            uVar4 = *puVar14;
            *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
          }
          *(uint *)(uVar4 * 4 + *(int *)(param_2 + 0xc)) = uVar11 | 0x110000;
          uVar4 = *puVar14 + 1;
          *puVar14 = uVar4;
          if (*(uint *)(param_2 + 8) <= uVar4) {
            pvVar3 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
            if (*(void **)(param_2 + 0xc) != (void *)0x0) {
              _memcpy(pvVar3,*(void **)(param_2 + 0xc),*puVar14 << 2);
              (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
            }
            *(void **)(param_2 + 0xc) = pvVar3;
            uVar4 = *puVar14;
            *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
          }
          *(uint *)(uVar4 * 4 + *(int *)(param_2 + 0xc)) = uVar2 | 0x410000;
          uVar4 = *puVar14 + 1;
          *puVar14 = uVar4;
          if (*pcVar9 == '\x01') {
            uVar12 = 0x51;
          }
          else {
            uVar12 = 0x15;
          }
          if (*(uint *)(param_2 + 8) <= uVar4) {
            pvVar3 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
            if (*(void **)(param_2 + 0xc) != (void *)0x0) {
              _memcpy(pvVar3,*(void **)(param_2 + 0xc),*puVar14 << 2);
              (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
            }
            *(void **)(param_2 + 0xc) = pvVar3;
            uVar4 = *puVar14;
            *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
          }
          *(uint *)(uVar4 * 4 + *(int *)(param_2 + 0xc)) = uVar12 | 0x5500;
          uVar4 = *puVar14 + 1;
          *puVar14 = uVar4;
          if (*(uint *)(param_2 + 8) <= uVar4) {
            pvVar3 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
            if (*(void **)(param_2 + 0xc) != (void *)0x0) {
              _memcpy(pvVar3,*(void **)(param_2 + 0xc),*puVar14 << 2);
              (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
            }
            *(void **)(param_2 + 0xc) = pvVar3;
            uVar4 = *puVar14;
            *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
          }
          *(uint *)(uVar4 * 4 + *(int *)(param_2 + 0xc)) = uVar2 | 0x410000;
          uVar4 = *puVar14 + 1;
          *puVar14 = uVar4;
          if (*pcVar9 == '\x01') {
            uVar12 = 0x42;
          }
          else {
            uVar12 = 0x24;
          }
          if (*(uint *)(param_2 + 8) <= uVar4) {
            pvVar3 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
            if (*(void **)(param_2 + 0xc) != (void *)0x0) {
              _memcpy(pvVar3,*(void **)(param_2 + 0xc),*puVar14 << 2);
              (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
            }
            *(void **)(param_2 + 0xc) = pvVar3;
            uVar4 = *puVar14;
            *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
          }
          *(uint *)(uVar4 * 4 + *(int *)(param_2 + 0xc)) = uVar12 | 0x4400;
          uVar4 = *puVar14 + 1;
          *puVar14 = uVar4;
          if (*(uint *)(param_2 + 8) <= uVar4) {
            pvVar3 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
            if (*(void **)(param_2 + 0xc) != (void *)0x0) {
              _memcpy(pvVar3,*(void **)(param_2 + 0xc),*puVar14 << 2);
              (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
            }
            *(void **)(param_2 + 0xc) = pvVar3;
            uVar4 = *puVar14;
            *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
          }
          *(uint *)(uVar4 * 4 + *(int *)(param_2 + 0xc)) =
               ((uVar10 & 0xff) + 8) * 0x10000 & 0xff0000 | 0x800005d;
          uVar4 = *puVar14 + 1;
          *puVar14 = uVar4;
          if (*(uint *)(param_2 + 8) <= uVar4) {
            pvVar3 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
            if (*(void **)(param_2 + 0xc) != (void *)0x0) {
              _memcpy(pvVar3,*(void **)(param_2 + 0xc),*puVar14 << 2);
              (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
            }
            *(void **)(param_2 + 0xc) = pvVar3;
            uVar4 = *puVar14;
            *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
          }
          *(undefined **)(uVar4 * 4 + *(int *)(param_2 + 0xc)) = ((unsigned char *)0x00040021);
          uVar4 = *puVar14 + 1;
          *puVar14 = uVar4;
          if (*(uint *)(param_2 + 8) <= uVar4) {
            pvVar3 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
            if (*(void **)(param_2 + 0xc) != (void *)0x0) {
              _memcpy(pvVar3,*(void **)(param_2 + 0xc),*puVar14 << 2);
              (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
            }
            *(void **)(param_2 + 0xc) = pvVar3;
            uVar4 = *puVar14;
            *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
          }
          *(undefined4 *)(uVar4 * 4 + *(int *)(param_2 + 0xc)) = 0x440021;
          uVar4 = *puVar14 + 1;
          *puVar14 = uVar4;
          if (*(uint *)(param_2 + 8) <= uVar4) {
            pvVar3 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
            if (*(void **)(param_2 + 0xc) != (void *)0x0) {
              _memcpy(pvVar3,*(void **)(param_2 + 0xc),*puVar14 << 2);
              (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
            }
            *(void **)(param_2 + 0xc) = pvVar3;
            uVar4 = *puVar14;
            *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
          }
          *(undefined4 *)(uVar4 * 4 + *(int *)(param_2 + 0xc)) = 0x603210;
          uVar4 = *puVar14 + 1;
          *puVar14 = uVar4;
          if (*(uint *)(param_2 + 8) <= uVar4) {
            pvVar3 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
            if (*(void **)(param_2 + 0xc) != (void *)0x0) {
              _memcpy(pvVar3,*(void **)(param_2 + 0xc),*puVar14 << 2);
              (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
            }
            *(void **)(param_2 + 0xc) = pvVar3;
            uVar4 = *puVar14;
            *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
          }
          *(undefined4 *)(uVar4 * 4 + *(int *)(param_2 + 0xc)) = 0x5b;
          uVar4 = *puVar14 + 1;
          *puVar14 = uVar4;
          if (*(uint *)(param_2 + 8) <= uVar4) {
            pvVar3 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
            if (*(void **)(param_2 + 0xc) != (void *)0x0) {
              _memcpy(pvVar3,*(void **)(param_2 + 0xc),*puVar14 << 2);
              (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
            }
            *(void **)(param_2 + 0xc) = pvVar3;
            uVar4 = *puVar14;
            *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
          }
          *(undefined **)(uVar4 * 4 + *(int *)(param_2 + 0xc)) = ((unsigned char *)0x00040022);
          uVar4 = *puVar14 + 1;
          *puVar14 = uVar4;
          if (*(uint *)(param_2 + 8) <= uVar4) {
            pvVar3 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
            if (*(void **)(param_2 + 0xc) != (void *)0x0) {
              _memcpy(pvVar3,*(void **)(param_2 + 0xc),*puVar14 << 2);
              (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
            }
            *(void **)(param_2 + 0xc) = pvVar3;
            uVar4 = *puVar14;
            *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
          }
          *(uint *)(uVar4 * 4 + *(int *)(param_2 + 0xc)) = uVar11 | 0x510000;
          uVar4 = *puVar14 + 1;
          *puVar14 = uVar4;
          if (*pcVar9 == '\x01') {
            puVar13 = (undefined *)0x0;
          }
          else {
            puVar13 = ((unsigned char *)0x00001111);
          }
          if (*(uint *)(param_2 + 8) <= uVar4) {
            pvVar3 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
            if (*(void **)(param_2 + 0xc) != (void *)0x0) {
              _memcpy(pvVar3,*(void **)(param_2 + 0xc),*puVar14 << 2);
              (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
            }
            *(void **)(param_2 + 0xc) = pvVar3;
            uVar4 = *puVar14;
            *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
          }
          *(undefined **)(uVar4 * 4 + *(int *)(param_2 + 0xc)) = puVar13;
          uVar4 = *puVar14 + 1;
          *puVar14 = uVar4;
          if (*(uint *)(param_2 + 8) <= uVar4) {
            pvVar3 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
            if (*(void **)(param_2 + 0xc) != (void *)0x0) {
              _memcpy(pvVar3,*(void **)(param_2 + 0xc),*puVar14 << 2);
              (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
            }
            *(void **)(param_2 + 0xc) = pvVar3;
            uVar4 = *puVar14;
            *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
          }
          *(uint *)(uVar4 * 4 + *(int *)(param_2 + 0xc)) = uVar2 | 0x410000;
          uVar4 = *puVar14 + 1;
          *puVar14 = uVar4;
          if (*(uint *)(param_2 + 8) <= uVar4) {
            pvVar3 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
            if (*(void **)(param_2 + 0xc) != (void *)0x0) {
              _memcpy(pvVar3,*(void **)(param_2 + 0xc),*puVar14 << 2);
              (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
            }
            *(void **)(param_2 + 0xc) = pvVar3;
            uVar4 = *puVar14;
            *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
          }
          *(undefined **)(uVar4 * 4 + *(int *)(param_2 + 0xc)) = ((unsigned char *)0x00003333);
          uVar4 = *puVar14 + 1;
          *puVar14 = uVar4;
          if (*(uint *)(param_2 + 8) <= uVar4) {
            pvVar3 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
            if (*(void **)(param_2 + 0xc) != (void *)0x0) {
              _memcpy(pvVar3,*(void **)(param_2 + 0xc),*puVar14 << 2);
              (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
            }
            *(void **)(param_2 + 0xc) = pvVar3;
            uVar4 = *puVar14;
            *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
          }
          *(undefined4 *)(uVar4 * 4 + *(int *)(param_2 + 0xc)) = 0x3000d;
          uVar4 = *puVar14 + 1;
          *puVar14 = uVar4;
          if (*(uint *)(param_2 + 8) <= uVar4) {
            pvVar3 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
            if (*(void **)(param_2 + 0xc) != (void *)0x0) {
              _memcpy(pvVar3,*(void **)(param_2 + 0xc),*puVar14 << 2);
              (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
            }
            *(void **)(param_2 + 0xc) = pvVar3;
            uVar4 = *puVar14;
            *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
          }
          *(uint *)(uVar4 * 4 + *(int *)(param_2 + 0xc)) = uVar11 | 0x40000;
          uVar4 = *puVar14 + 1;
          *puVar14 = uVar4;
          if (*(uint *)(param_2 + 8) <= uVar4) {
            pvVar3 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
            if (*(void **)(param_2 + 0xc) != (void *)0x0) {
              _memcpy(pvVar3,*(void **)(param_2 + 0xc),*puVar14 << 2);
              (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
            }
            *(void **)(param_2 + 0xc) = pvVar3;
            uVar4 = *puVar14;
            *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
          }
          *(undefined **)(uVar4 * 4 + *(int *)(param_2 + 0xc)) = ((unsigned char *)0x00040022);
          uVar4 = *puVar14 + 1;
          *puVar14 = uVar4;
          if (*(uint *)(param_2 + 8) <= uVar4) {
            pvVar3 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
            if (*(void **)(param_2 + 0xc) != (void *)0x0) {
              _memcpy(pvVar3,*(void **)(param_2 + 0xc),*puVar14 << 2);
              (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
            }
            *(void **)(param_2 + 0xc) = pvVar3;
            uVar4 = *puVar14;
            *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
          }
          *(undefined **)(uVar4 * 4 + *(int *)(param_2 + 0xc)) = ((unsigned char *)0x00040021);
          uVar4 = *puVar14 + 1;
          *puVar14 = uVar4;
          if (*(uint *)(param_2 + 8) <= uVar4) {
            pvVar3 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
            if (*(void **)(param_2 + 0xc) != (void *)0x0) {
              _memcpy(pvVar3,*(void **)(param_2 + 0xc),*puVar14 << 2);
              (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
            }
            *(void **)(param_2 + 0xc) = pvVar3;
            uVar4 = *puVar14;
            *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
          }
          *(undefined **)(uVar4 * 4 + *(int *)(param_2 + 0xc)) = ((unsigned char *)0x00040020);
          *puVar14 = *puVar14 + 1;
          uVar4 = (uint)(byte)((unsigned char *)0x000013b2)[param_1];
        }
      }
      uVar10 = uVar10 + 1;
      iVar5 = iVar5 + 0xcc;
      iVar7 = iVar7 + 4;
      iVar8 = iVar8 + 0xcc;
      iVar6 = iVar6 + 1;
    } while ((int)uVar10 < (int)uVar4);
  }
  return;
}

/* FUN_000d9b58 @ 0xd9b58 (84 bytes) */
int FUN_000d9b58(param_1, param_2, param_3)
  undefined4 param_1;
  uint *param_2;
  int param_3;
{
  bool bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = 0;
  do {
    uVar2 = *param_2;
    if (uVar2 != 0) {
      iVar4 = 0;
      do {
        if ((uVar2 & 1) != 0) {
          if (param_3 == 0) {
            return iVar4 + iVar3;
          }
          param_3 = param_3 + -1;
        }
        uVar2 = uVar2 >> 1;
        iVar4 = iVar4 + 1;
      } while (uVar2 != 0);
    }
    bVar1 = iVar3 != 0xe0;
    param_2 = param_2 + 1;
    iVar3 = iVar3 + 0x20;
  } while (bVar1);
  return -1;
}

/* FUN_000d9bac @ 0xd9bac (228 bytes) */
undefined4
FUN_000d9bac(double param_1,undefined4 param_2,int param_3,undefined4 param_4,int param_5,
            int param_6,int param_7)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  uint uVar6;
  
  if (param_7 == 0) {
    piVar4 = *(int **)(param_6 + 0x84);
    if (piVar4 != (int *)0x0) {
      uVar2 = *(uint *)(param_6 + 0x78);
      if (uVar2 == 0) {
LAB_000d9c0c:
        if (*(uint *)(param_6 + 0x6c) <= uVar2) {
          return 0;
        }
        iVar3 = uVar2 * 0x14;
        *(uint *)(param_6 + 0x78) = uVar2 + 1;
      }
      else if (*piVar4 == param_3) {
        iVar3 = 0;
      }
      else {
        iVar1 = 0x14;
        uVar6 = uVar2;
        piVar5 = piVar4;
        do {
          iVar3 = iVar1;
          piVar5 = piVar5 + 5;
          uVar6 = uVar6 - 1;
          if (uVar6 == 0) goto LAB_000d9c0c;
          iVar1 = iVar3 + 0x14;
        } while (*piVar5 != param_3);
      }
      *(int *)(iVar3 + (int)piVar4) = param_3;
      *(float *)((int)piVar4 + param_5 * 4 + iVar3 + 4) = (float)param_1;
      return 1;
    }
  }
  else {
    uVar2 = *(uint *)(param_6 + 0x54);
    if (uVar2 < *(uint *)(param_6 + 0x48)) {
      *(uint *)(param_6 + 0x54) = uVar2 + 1;
      iVar3 = uVar2 * 0x24 + *(int *)(param_6 + 0x60);
      *(int *)(uVar2 * 0x24 + *(int *)(param_6 + 0x60)) = param_3;
      *(float *)(iVar3 + 0x14) = (float)param_1;
      *(int *)(iVar3 + 4) = param_5;
      *(undefined4 *)(iVar3 + 8) = 1;
      return 1;
    }
  }
  return 0;
}

/* FUN_000d9c90 @ 0xd9c90 (228 bytes) */
int FUN_000d9c90(param_1, param_2, param_3, param_4, param_5, param_6)
  undefined4 param_1;
  int param_2;
  undefined4 param_3;
  int param_4;
  int param_5;
  int param_6;
{
  int iVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  uint uVar6;
  
  if (param_6 == 0) {
    piVar4 = *(int **)(param_5 + 0x88);
    if (piVar4 != (int *)0x0) {
      uVar2 = *(uint *)(param_5 + 0x7c);
      if (uVar2 == 0) {
LAB_000d9cf0:
        if (*(uint *)(param_5 + 0x70) <= uVar2) {
          return 0;
        }
        iVar3 = uVar2 * 0x14;
        *(uint *)(param_5 + 0x7c) = uVar2 + 1;
      }
      else if (*piVar4 == param_2) {
        iVar3 = 0;
      }
      else {
        iVar1 = 0x14;
        uVar6 = uVar2;
        piVar5 = piVar4;
        do {
          iVar3 = iVar1;
          piVar5 = piVar5 + 5;
          uVar6 = uVar6 - 1;
          if (uVar6 == 0) goto LAB_000d9cf0;
          iVar1 = iVar3 + 0x14;
        } while (*piVar5 != param_2);
      }
      *(int *)(iVar3 + (int)piVar4) = param_2;
      *(undefined4 *)((int)piVar4 + param_4 * 4 + iVar3 + 4) = param_3;
      return 1;
    }
  }
  else {
    uVar2 = *(uint *)(param_5 + 0x58);
    if (uVar2 < *(uint *)(param_5 + 0x4c)) {
      *(uint *)(param_5 + 0x58) = uVar2 + 1;
      iVar3 = uVar2 * 0x24 + *(int *)(param_5 + 100);
      *(int *)(uVar2 * 0x24 + *(int *)(param_5 + 100)) = param_2;
      *(undefined4 *)(iVar3 + 0x14) = param_3;
      *(int *)(iVar3 + 4) = param_4;
      *(undefined4 *)(iVar3 + 8) = 0;
      return 1;
    }
  }
  return 0;
}

/* FUN_000d9d74 @ 0xd9d74 (228 bytes) */
int FUN_000d9d74(param_1, param_2, param_3, param_4, param_5, param_6)
  undefined4 param_1;
  int param_2;
  undefined4 param_3;
  int param_4;
  int param_5;
  int param_6;
{
  int iVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  uint uVar6;
  
  if (param_6 == 0) {
    piVar4 = *(int **)(param_5 + 0x8c);
    if (piVar4 != (int *)0x0) {
      uVar2 = *(uint *)(param_5 + 0x80);
      if (uVar2 == 0) {
LAB_000d9dd4:
        if (*(uint *)(param_5 + 0x74) <= uVar2) {
          return 0;
        }
        iVar3 = uVar2 * 0x14;
        *(uint *)(param_5 + 0x80) = uVar2 + 1;
      }
      else if (*piVar4 == param_2) {
        iVar3 = 0;
      }
      else {
        iVar1 = 0x14;
        uVar6 = uVar2;
        piVar5 = piVar4;
        do {
          iVar3 = iVar1;
          piVar5 = piVar5 + 5;
          uVar6 = uVar6 - 1;
          if (uVar6 == 0) goto LAB_000d9dd4;
          iVar1 = iVar3 + 0x14;
        } while (*piVar5 != param_2);
      }
      *(int *)(iVar3 + (int)piVar4) = param_2;
      *(undefined4 *)((int)piVar4 + param_4 * 4 + iVar3 + 4) = param_3;
      return 1;
    }
  }
  else {
    uVar2 = *(uint *)(param_5 + 0x5c);
    if (uVar2 < *(uint *)(param_5 + 0x50)) {
      *(uint *)(param_5 + 0x5c) = uVar2 + 1;
      iVar3 = uVar2 * 0x24 + *(int *)(param_5 + 0x68);
      *(int *)(uVar2 * 0x24 + *(int *)(param_5 + 0x68)) = param_2;
      *(undefined4 *)(iVar3 + 0x14) = param_3;
      *(int *)(iVar3 + 4) = param_4;
      *(undefined4 *)(iVar3 + 8) = 2;
      return 1;
    }
  }
  return 0;
}

/* FUN_000d9e58 @ 0xd9e58 (64 bytes) */
int FUN_000d9e58(param_1, param_2, param_3, param_4, param_5, param_6)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  int param_6;
{
  uint uVar1;
  int iVar2;
  
  uVar1 = *(uint *)(param_6 + 0x54);
  if (*(uint *)(param_6 + 0x48) <= uVar1) {
    return 0;
  }
  iVar2 = uVar1 * 0x24 + *(int *)(param_6 + 0x60);
  *(uint *)(param_6 + 0x54) = uVar1 + 1;
  *(undefined4 *)(uVar1 * 0x24 + *(int *)(param_6 + 0x60)) = param_2;
  *(undefined4 *)(iVar2 + 0x10) = param_4;
  *(undefined4 *)(iVar2 + 4) = param_5;
  *(undefined4 *)(iVar2 + 8) = param_3;
  return 1;
}

/* FUN_000d9e98 @ 0xd9e98 (156 bytes) */
int FUN_000d9e98(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  int param_7;
  int param_8;
{
  uint uVar1;
  int iVar2;
  undefined4 in_stack_00000038;
  int in_stack_0000003c;
  
  uVar1 = *(uint *)(in_stack_0000003c + 0x58);
  if (*(uint *)(in_stack_0000003c + 0x4c) <= uVar1) {
    return 0;
  }
  *(uint *)(in_stack_0000003c + 0x58) = uVar1 + 1;
  iVar2 = uVar1 * 0x24 + *(int *)(in_stack_0000003c + 100);
  *(undefined4 *)(uVar1 * 0x24 + *(int *)(in_stack_0000003c + 100)) = param_2;
  *(undefined4 *)(iVar2 + 4) = 0;
  if (param_8 == -1) {
    if (param_7 == 0xff) {
      *(undefined4 *)(iVar2 + 8) = 0x15;
    }
    else {
      *(undefined4 *)(iVar2 + 8) = 0x16;
    }
  }
  else if (param_7 == 0xff) {
    *(undefined4 *)(iVar2 + 8) = 0x17;
  }
  else {
    *(undefined4 *)(iVar2 + 8) = 0x18;
  }
  *(int *)(iVar2 + 0x1c) = param_8;
  *(undefined4 *)(iVar2 + 0x10) = param_5;
  *(undefined4 *)(iVar2 + 0xc) = param_6;
  *(undefined4 *)(iVar2 + 0x20) = in_stack_00000038;
  return 1;
}

/* FUN_000d9f3c @ 0xd9f3c (60 bytes) */
int FUN_000d9f3c(param_1, param_2)
  int param_1;
  int param_2;
{
  bool bVar1;
  int iVar2;
  
  if (param_2 == 0) {
    iVar2 = *(int *)(param_1 + 0x2c);
  }
  else {
    iVar2 = *(int *)(param_1 + 0x30);
  }
  bVar1 = true;
  if (*(uint **)(iVar2 + 0x48) != (uint *)0x0) {
    bVar1 = (**(uint **)(iVar2 + 0x48) & 0x200000) == 0;
  }
  return bVar1;
}

/* FUN_000d9f80 @ 0xd9f80 (32 bytes) */
int FUN_000d9f80(param_1, param_2)
  int param_1;
  int param_2;
{
  if (param_2 != 0) {
    return *(undefined4 *)(*(int *)(param_1 + 0x30) + 0x3c);
  }
  return *(undefined4 *)(*(int *)(param_1 + 0x2c) + 0x40);
}

/* FUN_000d9fa0 @ 0xd9fa0 (32 bytes) */
int FUN_000d9fa0(param_1, param_2)
  int param_1;
  int param_2;
{
  if (param_2 != 0) {
    return *(undefined4 *)(*(int *)(param_1 + 0x30) + 0xc);
  }
  return *(undefined4 *)(*(int *)(param_1 + 0x2c) + 0x10);
}

/* FUN_000d9fc0 @ 0xd9fc0 (32 bytes) */
int FUN_000d9fc0(param_1, param_2)
  int param_1;
  int param_2;
{
  if (param_2 != 0) {
    return *(undefined4 *)(*(int *)(param_1 + 0x30) + 0x24);
  }
  return *(undefined4 *)(*(int *)(param_1 + 0x2c) + 0x28);
}

/* FUN_000d9fe0 @ 0xd9fe0 (72 bytes) */
int FUN_000d9fe0(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int param_2;
  int param_3;
  undefined4 param_4;
  undefined4 *param_5;
{
  int iVar1;
  int iVar2;
  
  if (param_2 == 0) {
    iVar2 = *(int *)(*(int *)(param_1 + 0x2c) + 0x34);
  }
  else {
    iVar2 = *(int *)(*(int *)(param_1 + 0x30) + 0x30);
  }
  iVar1 = iVar2 + param_3 * 0x10;
  *param_5 = *(undefined4 *)(iVar2 + param_3 * 0x10);
  param_5[1] = *(undefined4 *)(iVar1 + 4);
  param_5[2] = *(undefined4 *)(iVar1 + 8);
  param_5[3] = *(undefined4 *)(iVar1 + 0xc);
  return;
}

/* FUN_000da028 @ 0xda028 (72 bytes) */
int FUN_000da028(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int param_2;
  int param_3;
  undefined4 param_4;
  undefined4 *param_5;
{
  int iVar1;
  int iVar2;
  
  if (param_2 == 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x2c) + 4);
  }
  else {
    iVar1 = **(int **)(param_1 + 0x30);
  }
  iVar2 = iVar1 + param_3 * 0x10;
  *param_5 = *(undefined4 *)(iVar1 + param_3 * 0x10);
  param_5[1] = *(undefined4 *)(iVar2 + 4);
  param_5[2] = *(undefined4 *)(iVar2 + 8);
  param_5[3] = *(undefined4 *)(iVar2 + 0xc);
  return;
}

/* FUN_000da070 @ 0xda070 (44 bytes) */
int FUN_000da070(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int param_2;
  int param_3;
  undefined4 param_4;
  undefined4 *param_5;
{
  int iVar1;
  
  if (param_2 == 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x2c) + 0x1c);
  }
  else {
    iVar1 = *(int *)(*(int *)(param_1 + 0x30) + 0x18);
  }
  *param_5 = *(undefined4 *)(iVar1 + param_3 * 4);
  return;
}

/* FUN_000da09c @ 0xda09c (36 bytes) */
int FUN_000da09c(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  
  if (param_2 == 0) {
    iVar1 = *(int *)(param_1 + 0x38);
  }
  else {
    iVar1 = *(int *)(param_1 + 0x3c);
  }
  *(int *)(iVar1 + 0x100) = *(int *)(iVar1 + 0x100) + 1;
  return;
}

/* FUN_000da0c0 @ 0xda0c0 (720 bytes) */
int FUN_000da0c0(param_1, param_2)
  undefined4 *param_1;
  undefined4 *param_2;
{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined4 *puStack00000018;
  undefined4 *puStack0000001c;
  
  puStack00000018 = param_1;
  puStack0000001c = param_2;
  iVar1 = (*(code *)param_2[0xc])(param_2[0xb],0x6c8);
  uVar3 = puStack0000001c[0xd];
  *puStack00000018 = uVar3;
  uVar2 = puStack0000001c[0xb];
  puStack00000018[1] = uVar2;
  puStack00000018[3] = *puStack0000001c;
  puStack00000018[5] = puStack0000001c[1];
  puStack00000018[4] = puStack0000001c[0x14];
  if (iVar1 == 0) {
    puStack00000018[2] = 0;
    return;
  }
  FUN_000e1a48(iVar1,uVar2,puStack0000001c[0xc],uVar3,0,0,puStack0000001c[0xf],puStack0000001c[0x10]
              );
  puStack00000018[2] = iVar1;
  if (*(int *)(iVar1 + 0x314) != 0) {
    return;
  }
  iVar1 = _setjmp(*(int **)(iVar1 + 4));
  if (iVar1 != 0) {
    return;
  }
  if (puStack00000018[3] == -1) {
    puStack00000018[10] = puStack0000001c[2];
  }
  else {
    uVar2 = FUN_000cd290();
    puStack00000018[10] = uVar2;
  }
  iVar1 = puStack00000018[10];
  iVar4 = puStack0000001c[3];
  iVar5 = puStack0000001c[4];
  if (iVar1 == 2) {
    FUN_000e1b70(puStack00000018[2],2);
    if (iVar5 - 1U < 0x20c) {
      *(int *)(*(int *)(*(int *)(puStack00000018[2] + 0x310) + 8) + 0x40) = iVar5;
    }
    else {
      *(undefined4 *)(*(int *)(*(int *)(puStack00000018[2] + 0x310) + 8) + 0x40) = 0x20c;
    }
    if (iVar4 - 1U < 0x100) goto LAB_000da340;
  }
  else {
    if (iVar1 == 3) {
      FUN_000e1b70(puStack00000018[2],4);
      if (iVar5 - 1U < 0x200) {
        *(int *)(*(int *)(*(int *)(puStack00000018[2] + 0x310) + 8) + 0x40) = iVar5;
      }
      else {
        *(undefined4 *)(*(int *)(*(int *)(puStack00000018[2] + 0x310) + 8) + 0x40) = 0x200;
      }
      if (0x3ff < iVar4 - 1U) {
        *(undefined4 *)(*(int *)(*(int *)(puStack00000018[2] + 0x310) + 4) + 0x40) = 0x400;
        return;
      }
LAB_000da340:
      *(int *)(*(int *)(*(int *)(puStack00000018[2] + 0x310) + 4) + 0x40) = iVar4;
      return;
    }
    if (iVar1 != 1) {
      *(undefined4 *)(puStack00000018[2] + 0x314) = 0xe;
      FUN_000e1b70(puStack00000018[2],1);
      return;
    }
    FUN_000e1b70(puStack00000018[2],1);
    if (iVar5 - 1U < 0x60) {
      *(int *)(*(int *)(*(int *)(puStack00000018[2] + 0x310) + 8) + 0x40) = iVar5;
    }
    else {
      *(undefined4 *)(*(int *)(*(int *)(puStack00000018[2] + 0x310) + 8) + 0x40) = 0x60;
    }
    if (iVar4 - 1U < 0x100) {
      *(int *)(*(int *)(*(int *)(puStack00000018[2] + 0x310) + 4) + 0x40) = iVar5;
      return;
    }
  }
  *(undefined4 *)(*(int *)(*(int *)(puStack00000018[2] + 0x310) + 4) + 0x40) = 0x100;
  return;
}

/* FUN_000da394 @ 0xda394 (68 bytes) */
int FUN_000da394(param_1, param_2, param_3)
  int param_1;
  int param_2;
  undefined4 param_3;
{
  undefined4 uVar1;
  
  *(undefined4 *)(param_1 + 0x38) = param_3;
  *(undefined4 *)(param_1 + 0x3c) = param_3;
  *(undefined4 *)(param_1 + 0x40) = param_3;
  *(int *)(param_1 + 0x2c) = param_2;
  *(int *)(param_1 + 0x30) = param_2;
  *(int *)(param_1 + 0x34) = param_2;
  if (*(int *)(param_1 + 8) != 0) {
    uVar1 = FUN_000e2524(*(int *)(param_1 + 8),param_3,*(undefined4 *)(param_2 + 0x4c),
                         *(undefined4 *)(param_2 + 0x54));
    return uVar1;
  }
  return 2;
}

/* FUN_000da420 @ 0xda420 (24 bytes) */
int FUN_000da420(param_1)
  int param_1;
{
  if (*(int *)(param_1 + 8) == 0) {
    return 2;
  }
  return *(undefined4 *)(*(int *)(param_1 + 8) + 0x314);
}

/* FUN_000da458 @ 0xda458 (96 bytes) */
int FUN_000da458(param_1)
  undefined4 *param_1;
{
  if (param_1[2] != 0) {
    FUN_000e1fe4();
                    
                    
    (*(code *)*param_1)(param_1[1],param_1[2]);
    return;
  }
  return;
}

/* FUN_000da4b8 @ 0xda4b8 (720 bytes) */
int FUN_000da4b8(param_1, param_2)
  undefined4 *param_1;
  undefined4 *param_2;
{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined4 *puStack00000018;
  undefined4 *puStack0000001c;
  
  puStack00000018 = param_1;
  puStack0000001c = param_2;
  iVar1 = (*(code *)param_2[0xc])(param_2[0xb],0x6c8);
  uVar3 = puStack0000001c[0xd];
  *puStack00000018 = uVar3;
  uVar2 = puStack0000001c[0xb];
  puStack00000018[1] = uVar2;
  puStack00000018[3] = *puStack0000001c;
  puStack00000018[5] = puStack0000001c[1];
  puStack00000018[4] = puStack0000001c[0x14];
  if (iVar1 == 0) {
    puStack00000018[2] = 0;
    return;
  }
  FUN_000e1a48(iVar1,uVar2,puStack0000001c[0xc],uVar3,0,0,puStack0000001c[0xf],puStack0000001c[0x10]
              );
  puStack00000018[2] = iVar1;
  if (*(int *)(iVar1 + 0x314) != 0) {
    return;
  }
  iVar1 = _setjmp(*(int **)(iVar1 + 4));
  if (iVar1 != 0) {
    return;
  }
  if (puStack00000018[3] == -1) {
    puStack00000018[10] = puStack0000001c[2];
  }
  else {
    uVar2 = FUN_000cd290();
    puStack00000018[10] = uVar2;
  }
  iVar1 = puStack00000018[10];
  iVar4 = puStack0000001c[3];
  iVar5 = puStack0000001c[4];
  if (iVar1 == 2) {
    FUN_000e1b70(puStack00000018[2],2);
    if (iVar5 - 1U < 0x20c) {
      *(int *)(*(int *)(*(int *)(puStack00000018[2] + 0x310) + 8) + 0x40) = iVar5;
    }
    else {
      *(undefined4 *)(*(int *)(*(int *)(puStack00000018[2] + 0x310) + 8) + 0x40) = 0x20c;
    }
    if (iVar4 - 1U < 0x100) goto LAB_000da738;
  }
  else {
    if (iVar1 == 3) {
      FUN_000e1b70(puStack00000018[2],4);
      if (iVar5 - 1U < 0x200) {
        *(int *)(*(int *)(*(int *)(puStack00000018[2] + 0x310) + 8) + 0x40) = iVar5;
      }
      else {
        *(undefined4 *)(*(int *)(*(int *)(puStack00000018[2] + 0x310) + 8) + 0x40) = 0x200;
      }
      if (0x3ff < iVar4 - 1U) {
        *(undefined4 *)(*(int *)(*(int *)(puStack00000018[2] + 0x310) + 4) + 0x40) = 0x400;
        return;
      }
LAB_000da738:
      *(int *)(*(int *)(*(int *)(puStack00000018[2] + 0x310) + 4) + 0x40) = iVar4;
      return;
    }
    if (iVar1 != 1) {
      *(undefined4 *)(puStack00000018[2] + 0x314) = 0xe;
      FUN_000e1b70(puStack00000018[2],1);
      return;
    }
    FUN_000e1b70(puStack00000018[2],1);
    if (iVar5 - 1U < 0x60) {
      *(int *)(*(int *)(*(int *)(puStack00000018[2] + 0x310) + 8) + 0x40) = iVar5;
    }
    else {
      *(undefined4 *)(*(int *)(*(int *)(puStack00000018[2] + 0x310) + 8) + 0x40) = 0x60;
    }
    if (iVar4 - 1U < 0x100) {
      *(int *)(*(int *)(*(int *)(puStack00000018[2] + 0x310) + 4) + 0x40) = iVar5;
      return;
    }
  }
  *(undefined4 *)(*(int *)(*(int *)(puStack00000018[2] + 0x310) + 4) + 0x40) = 0x100;
  return;
}

/* FUN_000da78c @ 0xda78c (244 bytes) */
double FUN_000da78c(uint param_1)

{
  uint uVar1;
  uint uVar2;
  double dVar3;
  double dVar4;
  
  dVar3 = DOUBLE_001aa250;
  uVar1 = param_1 & 7;
  uVar2 = param_1 >> 3 & 0xf;
  if (uVar2 == 0) {
    if (uVar1 == 0) {
      dVar3 = (double)FLOAT_001aa1c0;
    }
    else {
      dVar3 = (double)((float)((double)CONCAT44(0x43300000,uVar1) - DOUBLE_001aa250) *
                       FLOAT_001aa170 * FLOAT_001aa1c4);
    }
  }
  else {
    dVar4 = (double)_pow(DOUBLE_001aa2a0,
                         (double)(float)((double)CONCAT44(0x43300000,uVar2) - DOUBLE_001aa250) -
                         DOUBLE_001aa2a8[0]);
    dVar3 = (double)((float)((double)CONCAT44(0x43300000,uVar1) - dVar3) * FLOAT_001aa170 *
                     (float)dVar4 + (float)dVar4);
  }
  return dVar3;
}

/* FUN_000da8a8 @ 0xda8a8 (40 bytes) */
int FUN_000da8a8(param_1)
  undefined4 *param_1;
{
  param_1[0x87] = 0;
  *param_1 = 0;
  param_1[0x84] = 0;
  param_1[0x85] = 0;
  param_1[0x86] = 0;
  _memset(param_1 + 4,0,0x200);
  return;
}

/* FUN_000da8d0 @ 0xda8d0 (16 bytes) */
int FUN_000da8d0(param_1)
  int param_1;
{
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 4;
  return;
}

/* FUN_000da8e0 @ 0xda8e0 (20 bytes) */
int FUN_000da8e0(param_1, param_2)
  int param_1;
  int param_2;
{
  if (param_2 < 0) {
    param_2 = 0;
  }
  *(int *)(param_1 + 0x21c) = param_2;
  return;
}

/* FUN_000da8f4 @ 0xda8f4 (8 bytes) */
int FUN_000da8f4()
{
  return 0;
}

/* FUN_000da8fc @ 0xda8fc (8 bytes) */
int FUN_000da8fc()
{
  return 0;
}

/* FUN_000da904 @ 0xda904 (128 bytes) */
int FUN_000da904(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  size_t sVar1;
  undefined4 uStack00000020;
  undefined4 uStack00000024;
  undefined4 uStack00000028;
  undefined4 uStack0000002c;
  undefined4 uStack00000030;
  undefined4 uStack00000034;
  char acStack_224 [536];
  
  uStack00000020 = param_3;
  uStack00000024 = param_4;
  uStack00000028 = param_5;
  uStack0000002c = param_6;
  uStack00000030 = param_7;
  uStack00000034 = param_8;
  FUN_001a3428(acStack_224,0x200,param_2,&STACKARG(0x20));
  sVar1 = _strlen((char *)(param_1 + 0x10));
  if (sVar1 <= 0x1ff - sVar1) {
    _strcat((char *)(param_1 + 0x10),acStack_224);
  }
  return;
}

/* FUN_000da984 @ 0xda984 (120 bytes) */
int FUN_000da984(param_1)
  int param_1;
{
  if (*(int *)(param_1 + 0x210) != 0) {
    ((int (*)())FUN_000da904)(param_1,"\r\n");
    (*(code *)**(undefined4 **)(param_1 + 0x210))
              (*(undefined4 *)(param_1 + 0x214),"",param_1 + 0x10,0);
  }
  *(undefined1 *)(param_1 + 0x10) = 0;
  return;
}

/* FUN_000da9fc @ 0xda9fc (180 bytes) */
int FUN_000da9fc(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  size_t sVar1;
  int iVar2;
  undefined4 uStack00000024;
  undefined4 uStack00000028;
  undefined4 uStack0000002c;
  undefined4 uStack00000030;
  undefined4 uStack00000034;
  char acStack_234 [540];
  
  uStack00000024 = param_4;
  uStack00000028 = param_5;
  uStack0000002c = param_6;
  uStack00000030 = param_7;
  uStack00000034 = param_8;
  if (0 < param_2) {
    iVar2 = 0;
    do {
      iVar2 = iVar2 + 1;
      ((int (*)())FUN_000da904)(param_1,"    ");
    } while (param_2 != iVar2);
  }
  FUN_001a3428(acStack_234,0x200,param_3,&STACKARG(0x24));
  sVar1 = _strlen((char *)(param_1 + 0x10));
  if (sVar1 <= 0x1ff - sVar1) {
    _strcat((char *)(param_1 + 0x10),acStack_234);
  }
  return;
}

/* FUN_000daab0 @ 0xdaab0 (412 bytes) */
int FUN_000daab0(param_1, param_2, param_3)
  undefined4 param_1;
  uint param_2;
  int param_3;
{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  
  bVar1 = (param_2 >> 3 & 1) != 0;
  uVar3 = param_2 >> 7 & 1;
  uVar2 = param_2 >> 0xb & 1;
  uVar4 = param_2 >> 0xf & 1;
  if ((((!bVar1) && (uVar3 == 0)) && (uVar2 == 0)) && (uVar4 == 0)) {
    return;
  }
  ((int (*)())FUN_000da904)(param_1,"_neg(");
  if (bVar1) {
    if (param_3 == 0) {
      pcVar5 = "x";
    }
    else {
      pcVar5 = "r";
    }
    ((int (*)())FUN_000da904)(param_1,pcVar5);
  }
  if (uVar3 != 0) {
    if (param_3 == 0) {
      pcVar5 = "y";
    }
    else {
      pcVar5 = "g";
    }
    ((int (*)())FUN_000da904)(param_1,pcVar5);
  }
  if (uVar2 != 0) {
    if (param_3 == 0) {
      pcVar5 = "z";
    }
    else {
      pcVar5 = "b";
    }
    ((int (*)())FUN_000da904)(param_1,pcVar5);
  }
  if (uVar4 != 0) {
    if (param_3 == 0) {
      pcVar5 = "w";
    }
    else {
      pcVar5 = "a";
    }
    ((int (*)())FUN_000da904)(param_1,pcVar5);
  }
  ((int (*)())FUN_000da904)(param_1,")");
  return;
}

/* FUN_000dac4c @ 0xdac4c (204 bytes) */
int FUN_000dac4c(param_1, param_2, param_3)
  int *param_1;
  undefined4 param_2;
  int param_3;
{
  undefined4 uVar1;
  
  switch(param_2) {
  case 0:
    uVar1 = 0x78;
    if (param_3 != 0) {
      uVar1 = 0x72;
    }
    break;
  case 1:
    uVar1 = 0x79;
    if (param_3 != 0) {
      uVar1 = 0x67;
    }
    break;
  case 2:
    uVar1 = 0x7a;
    if (param_3 != 0) {
      uVar1 = 0x62;
    }
    break;
  case 3:
    uVar1 = 0x77;
    if (param_3 != 0) {
      uVar1 = 0x61;
    }
    break;
  case 4:
    uVar1 = 0x30;
    break;
  case 5:
    uVar1 = 0x31;
    break;
  default:
    *param_1 = *param_1 + 1;
    ((int (*)())FUN_000da904)(param_1,"!!!invalidCompSel!!!");
    uVar1 = 0;
  }
  return uVar1;
}

/* FUN_000dad30 @ 0xdad30 (300 bytes) */
int FUN_000dad30(param_1, param_2, param_3)
  undefined4 param_1;
  uint param_2;
  undefined4 param_3;
{
  int iVar1;
  int iVar2;
  char local_28;
  char local_27;
  char local_26;
  undefined1 local_25;
  undefined1 local_24;
  
  local_28 = ((int (*)())FUN_000dac4c)(param_1,param_2 & 7);
  local_27 = ((int (*)())FUN_000dac4c)(param_1,param_2 >> 4 & 7,param_3);
  local_26 = ((int (*)())FUN_000dac4c)(param_1,param_2 >> 8 & 7,param_3);
  iVar1 = ((int (*)())FUN_000dac4c)(param_1,param_2 >> 0xc & 7,param_3);
  local_25 = (undefined1)iVar1;
  local_24 = 0;
  iVar2 = _strcmp(&local_28,"rgba");
  if ((iVar2 != 0) && (iVar2 = _strcmp(&local_28,"xyzw"), iVar2 != 0)) {
    if ((((int)local_27 == (int)local_28) &&
        (((int)local_26 == (int)local_27 && (iVar1 == local_26)))) &&
       (((iVar1 - 0x61U & 0xff) < 0x1a || ((iVar1 - 0x41U & 0xff) < 0x1a)))) {
      local_27 = '\0';
    }
    ((int (*)())FUN_000da904)(param_1,".");
    ((int (*)())FUN_000da904)(param_1,&local_28);
  }
  return;
}

/* FUN_000dae5c @ 0xdae5c (260 bytes) */
int FUN_000dae5c(param_1, param_2)
  int *param_1;
  uint param_2;
{
  char *pcVar1;
  
  if ((param_2 & 0x100) != 0) {
    ((int (*)())FUN_000da904)(param_1,"_sat");
  }
  if ((param_2 & 0x1e00) != 0) {
    switch(param_2 >> 9 & 0xf) {
    default:
      pcVar1 = "!!!invalidShift!!!";
      *param_1 = *param_1 + 1;
      break;
    case 1:
      pcVar1 = "_x2";
      break;
    case 2:
      pcVar1 = "_x4";
      break;
    case 3:
      pcVar1 = "_x8";
      break;
    case 4:
      pcVar1 = "_d2";
      break;
    case 5:
      pcVar1 = "_d4";
      break;
    case 6:
      pcVar1 = "_d8";
    }
    ((int (*)())FUN_000da904)(param_1,pcVar1);
    return;
  }
  return;
}

/* FUN_000daf7c @ 0xdaf7c (172 bytes) */
int FUN_000daf7c(param_1, param_2)
  int *param_1;
  undefined4 param_2;
{
  switch(param_2) {
  case 0:
    ((int (*)())FUN_000da904)(param_1,"unknown");
    return;
  case 1:
    ((int (*)())FUN_000da904)(param_1,"snorm");
    return;
  case 2:
    ((int (*)())FUN_000da904)(param_1,"unorm");
    return;
  case 3:
    ((int (*)())FUN_000da904)(param_1,"sint");
    return;
  case 4:
    ((int (*)())FUN_000da904)(param_1,"uint");
    return;
  case 5:
    ((int (*)())FUN_000da904)(param_1,"float");
    return;
  case 6:
    ((int (*)())FUN_000da904)(param_1,"srgb");
    return;
  case 7:
    ((int (*)())FUN_000da904)(param_1,"mixed");
    return;
  default:
    *param_1 = *param_1 + 1;
    ((int (*)())FUN_000da904)(param_1,"!!!invalidElemFormat!!!");
    return;
  }
}

/* FUN_000db048 @ 0xdb048 (224 bytes) */
int FUN_000db048(param_1)
  int param_1;
{
  uint uVar1;
  
  uVar1 = **(uint **)(param_1 + 8);
  *(uint **)(param_1 + 8) = *(uint **)(param_1 + 8) + 1;
  ((int (*)())FUN_000da904)(param_1,"_fmtx(");
  ((int (*)())FUN_000daf7c)(param_1,uVar1 >> 0x14 & 7);
  ((int (*)())FUN_000da904)(param_1,")");
  ((int (*)())FUN_000da904)(param_1,"_fmty(");
  ((int (*)())FUN_000daf7c)(param_1,uVar1 >> 0x17 & 7);
  ((int (*)())FUN_000da904)(param_1,")");
  ((int (*)())FUN_000da904)(param_1,"_fmtz(");
  ((int (*)())FUN_000daf7c)(param_1,uVar1 >> 0x1a & 7);
  ((int (*)())FUN_000da904)(param_1,")");
  ((int (*)())FUN_000da904)(param_1,"_fmtw(");
  ((int (*)())FUN_000daf7c)(param_1,uVar1 >> 0x1d);
  ((int (*)())FUN_000da904)(param_1,")");
  return;
}

