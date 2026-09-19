#include "decls.h"

/* FUN_000f31f8 @ 0xf31f8 (96 bytes) */
int FUN_000f31f8(param_1, param_2, param_3)
  undefined1 *param_1;
  undefined4 param_2;
  uint param_3;
{
  undefined1 uVar1;
  
  uVar1 = 1;
  if (param_3 >> 0x18 != 0) {
    uVar1 = (undefined1)((uint)param_2 >> 0x18);
  }
  *param_1 = uVar1;
  uVar1 = 1;
  if ((param_3 >> 0x10 & 0xff) != 0) {
    uVar1 = (undefined1)((uint)param_2 >> 0x10);
  }
  param_1[1] = uVar1;
  uVar1 = 1;
  if ((param_3 >> 8 & 0xff) != 0) {
    uVar1 = (undefined1)((uint)param_2 >> 8);
  }
  param_1[2] = uVar1;
  uVar1 = 1;
  if ((param_3 & 0xff) != 0) {
    uVar1 = (undefined1)param_2;
  }
  param_1[3] = uVar1;
  return;
}

/* FUN_000f3258 @ 0xf3258 (116 bytes) */
int FUN_000f3258(param_1, param_2)
  undefined4 *param_1;
  uint param_2;
{
  *param_1 = DAT_001aa838;
  if (param_2 >> 0x18 < 4) {
    *(undefined1 *)param_1 = 0;
  }
  if ((param_2 >> 0x10 & 0xff) < 4) {
    *(undefined1 *)((int)param_1 + 1) = 0;
  }
  if ((param_2 >> 8 & 0xff) < 4) {
    *(undefined1 *)((int)param_1 + 2) = 0;
  }
  if (3 < (param_2 & 0xff)) {
    return;
  }
  *(undefined1 *)((int)param_1 + 3) = 0;
  return;
}

/* FUN_000f32cc @ 0xf32cc (116 bytes) */
int FUN_000f32cc(param_1, param_2)
  undefined4 *param_1;
  uint param_2;
{
  uint uVar1;
  
  *param_1 = DAT_001aa838;
  if (param_2 >> 0x18 < 4) {
    *(undefined1 *)((int)param_1 + (param_2 >> 0x18)) = 0;
  }
  uVar1 = param_2 >> 0x10 & 0xff;
  if (uVar1 < 4) {
    *(undefined1 *)((int)param_1 + uVar1) = 0;
  }
  uVar1 = param_2 >> 8 & 0xff;
  if (uVar1 < 4) {
    *(undefined1 *)((int)param_1 + uVar1) = 0;
  }
  if (3 < (param_2 & 0xff)) {
    return;
  }
  *(undefined1 *)((int)param_1 + (param_2 & 0xff)) = 0;
  return;
}

/* FUN_000f3340 @ 0xf3340 (88 bytes) */
int FUN_000f3340(param_1, param_2, param_3)
  uint *param_1;
  uint param_2;
  uint param_3;
{
  if (param_3 >> 0x18 == 0) {
    param_2 = param_2 & 0xffffff | 0x4000000;
  }
  if ((param_3 >> 0x10 & 0xff) == 0) {
    param_2 = param_2 & 0xff00ffff | 0x40000;
  }
  if ((param_3 >> 8 & 0xff) == 0) {
    param_2 = param_2 & 0xffff00ff | 0x400;
  }
  if ((param_3 & 0xff) == 0) {
    param_2 = param_2 & 0xffffff00 | 4;
  }
  *param_1 = param_2;
  return;
}

/* FUN_000f3398 @ 0xf3398 (96 bytes) */
int FUN_000f3398(param_1, param_2)
  undefined4 *param_1;
  uint param_2;
{
  uint uVar1;
  
  *param_1 = 0;
  if (param_2 >> 0x18 < 4) {
    *(undefined1 *)((int)param_1 + (param_2 >> 0x18)) = 1;
  }
  uVar1 = param_2 >> 0x10 & 0xff;
  if (uVar1 < 4) {
    *(undefined1 *)((int)param_1 + uVar1) = 1;
  }
  uVar1 = param_2 >> 8 & 0xff;
  if (uVar1 < 4) {
    *(undefined1 *)((int)param_1 + uVar1) = 1;
  }
  if (3 < (param_2 & 0xff)) {
    return;
  }
  *(undefined1 *)((int)param_1 + (param_2 & 0xff)) = 1;
  return;
}

/* FUN_000f33f8 @ 0xf33f8 (120 bytes) */
int FUN_000f33f8(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  undefined4 uStack0000001c;
  
  pcVar2 = (char *)&STACKARG(0x1c);
  iVar4 = 4;
  uStack0000001c = param_2;
  iVar3 = 0;
  pcVar1 = pcVar2;
  do {
    if (*pcVar1 != '\x04') {
      iVar4 = 4;
      do {
        if (*pcVar2 == '\x04') {
          *pcVar2 = *(char *)((int)&STACKARG(0x1c) + iVar3);
        }
        pcVar2 = pcVar2 + 1;
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
      *param_1 = uStack0000001c;
      return;
    }
    iVar3 = iVar3 + 1;
    pcVar1 = pcVar1 + 1;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  *param_1 = param_2;
  return;
}

/* FUN_000f3470 @ 0xf3470 (340 bytes) */
int FUN_000f3470(param_1, param_2)
  uint *param_1;
  uint param_2;
{
  bool bVar1;
  bool bVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  byte *pbVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  byte bStack0000001c;
  char cStack0000001d;
  char cStack0000001e;
  char cStack0000001f;
  
  (*(unsigned char *)(*(unsigned int *)__builtin_frame_address(0) + 0x1c)) = param_2;
  uVar3 = (*(unsigned char *)(*(unsigned int *)__builtin_frame_address(0) + 0x1c));
  bStack0000001c = (byte)(param_2 >> 0x18);
  uVar4 = (uint)bStack0000001c;
  if (uVar4 == 4) {
    bVar2 = true;
    iVar8 = 1;
    do {
      uVar7 = (uint)((unsigned int *)STACKARG(0x1c))[iVar8];
      iVar9 = iVar8;
      if ((uVar7 != 4) && (iVar9 = iVar8 + 1, uVar4 = uVar7, iVar9 < 4)) {
        iVar5 = 4 - iVar9;
        pbVar6 = (byte *)(&STACKARG(0x1d) + iVar8);
        do {
          if ((*pbVar6 != 4) && (uVar7 != *pbVar6)) {
            bVar2 = false;
          }
          iVar9 = iVar9 + 1;
          pbVar6 = pbVar6 + 1;
          iVar5 = iVar5 + -1;
        } while (iVar5 != 0);
      }
      iVar8 = iVar9 + 1;
    } while (iVar8 < 4);
  }
  else {
    bVar1 = false;
    iVar8 = 4;
    bVar2 = true;
    pbVar6 = &STACKARG(0x1c);
    do {
      if (*pbVar6 == 4) {
        bVar1 = true;
      }
      else if (uVar4 != *pbVar6) {
        bVar2 = false;
      }
      pbVar6 = pbVar6 + 1;
      iVar8 = iVar8 + -1;
    } while (iVar8 != 0);
    if (!bVar1) goto LAB_000f35b4;
  }
  if (bVar2) {
    *param_1 = (DAT_001aa818)[uVar4];
    return;
  }
  bVar1 = bStack0000001c == 4;
  (*(unsigned char *)(*(unsigned int *)__builtin_frame_address(0) + 0x1c)) = uVar3;
  if (bVar1) {
    (*(unsigned char *)(*(unsigned int *)__builtin_frame_address(0) + 0x1c)) = param_2 & 0xffffff;
  }
  if (cStack0000001d == '\x04') {
    (*(char *)(*(unsigned int *)__builtin_frame_address(0) + 0x1d)) = CONCAT12(1,(*(char *)(*(unsigned int *)__builtin_frame_address(0) + 0x1e)));
  }
  if (cStack0000001e == '\x04') {
    (*(char *)(*(unsigned int *)__builtin_frame_address(0) + 0x1e)) = CONCAT11(2,cStack0000001f);
  }
  uVar3 = (*(unsigned char *)(*(unsigned int *)__builtin_frame_address(0) + 0x1c));
  if (cStack0000001f == '\x04') {
    (*(unsigned char *)(*(unsigned int *)__builtin_frame_address(0) + 0x1c)) = CONCAT31((*(unsigned char *)(*(unsigned int *)__builtin_frame_address(0) + 0x1c)),3);
    uVar3 = (*(unsigned char *)(*(unsigned int *)__builtin_frame_address(0) + 0x1c));
  }
LAB_000f35b4:
  (*(unsigned char *)(*(unsigned int *)__builtin_frame_address(0) + 0x1c)) = uVar3;
  *param_1 = (*(unsigned char *)(*(unsigned int *)__builtin_frame_address(0) + 0x1c));
  return;
}

/* FUN_000f35c4 @ 0xf35c4 (168 bytes) */
int FUN_000f35c4(param_1)
  int *param_1;
{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 local_38 [9];
  
  iVar4 = 0;
  iVar2 = FUN_001054ec(param_1,0);
  local_38[0] = *(undefined4 *)(iVar2 + 0x10);
  do {
    iVar2 = 1;
    if (*(char *)((int)local_38 + iVar4) == '\x01') {
      for (; iVar3 = (**(code **)(*param_1 + 0x14))(param_1), iVar2 <= iVar3; iVar2 = iVar2 + 1) {
        (**(code **)(*param_1 + 0x88))(param_1,iVar2,iVar4,4);
      }
    }
    bVar1 = iVar4 != 3;
    iVar4 = iVar4 + 1;
  } while (bVar1);
  return;
}

/* FUN_000f366c @ 0xf366c (76 bytes) */
int FUN_000f366c(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  byte *pbVar1;
  int iVar2;
  undefined4 uStack0000001c;
  
  uStack0000001c = param_2;
  iVar2 = 4;
  *param_1 = DAT_001aa838;
  pbVar1 = (byte *)&STACKARG(0x1c);
  do {
    if (*pbVar1 != 4) {
      *(undefined1 *)((int)param_1 + (uint)*pbVar1) = 0;
    }
    pbVar1 = pbVar1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}

/* FUN_000f36b8 @ 0xf36b8 (84 bytes) */
int FUN_000f36b8(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  char *pcVar1;
  int iVar2;
  undefined4 uStack0000001c;
  
  uStack0000001c = param_2;
  pcVar1 = (char *)&STACKARG(0x1c);
  iVar2 = 4;
  *param_1 = DAT_001aa838;
  do {
    if (*pcVar1 != '\x04') {
      *(undefined1 *)param_1 = 0;
    }
    pcVar1 = pcVar1 + 1;
    param_1 = (undefined4 *)((int)param_1 + 1);
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}

/* FUN_000f370c @ 0xf370c (88 bytes) */
int FUN_000f370c(param_1, param_2)
  char *param_1;
  undefined4 param_2;
{
  char *pcVar1;
  char cVar2;
  int iVar3;
  undefined4 uStack0000001c;
  
  uStack0000001c = param_2;
  cVar2 = '\0';
  pcVar1 = (char *)&STACKARG(0x1c);
  iVar3 = 4;
  *(undefined4 *)param_1 = DAT_001aa83c;
  do {
    if (*pcVar1 == '\0') {
      *param_1 = cVar2;
    }
    cVar2 = cVar2 + '\x01';
    pcVar1 = pcVar1 + 1;
    param_1 = param_1 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return;
}

/* FUN_000f3764 @ 0xf3764 (84 bytes) */
int FUN_000f3764(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  char *pcVar1;
  int iVar2;
  undefined4 uStack0000001c;
  
  uStack0000001c = param_2;
  pcVar1 = (char *)&STACKARG(0x1c);
  iVar2 = 4;
  *param_1 = DAT_001aa838;
  do {
    if (*pcVar1 != '\0') {
      *(undefined1 *)param_1 = 0;
    }
    pcVar1 = pcVar1 + 1;
    param_1 = (undefined4 *)((int)param_1 + 1);
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}

/* FUN_000f37b8 @ 0xf37b8 (108 bytes) */
int FUN_000f37b8(param_1)
  int param_1;
{
  if (param_1 == DAT_001aa85c) {
    return 0;
  }
  if (param_1 == DAT_001aa858) {
    return 1;
  }
  if (param_1 == DAT_001aa854) {
    return 2;
  }
  if (param_1 == DAT_001aa850) {
    return 3;
  }
  return 0xffffffff;
}

/* FUN_000f3824 @ 0xf3824 (96 bytes) */
int FUN_000f3824(param_1)
  int param_1;
{
  if ((((param_1 != DAT_001aa85c) && (param_1 != DAT_001aa858)) && (param_1 != DAT_001aa854)) &&
     (param_1 != DAT_001aa850)) {
    return 0;
  }
  return 1;
}

/* FUN_000f3884 @ 0xf3884 (8 bytes) */
int FUN_000f3884(param_1)
  int param_1;
{
  ((int (*)())FUN_000f3824)(*(undefined4 *)(param_1 + 0x9c));
  return;
}

/* FUN_000f388c @ 0xf388c (124 bytes) */
int FUN_000f388c(param_1, param_2, param_3)
  undefined4 *param_1;
  uint param_2;
  int param_3;
{
  uint uVar1;
  
  *param_1 = 0;
  if ((0 < param_3) && (param_2 >> 0x18 < 4)) {
    *(undefined1 *)((int)param_1 + (param_2 >> 0x18)) = 1;
  }
  if ((1 < param_3) && (uVar1 = param_2 >> 0x10 & 0xff, uVar1 < 4)) {
    *(undefined1 *)((int)param_1 + uVar1) = 1;
  }
  if ((2 < param_3) && (uVar1 = param_2 >> 8 & 0xff, uVar1 < 4)) {
    *(undefined1 *)((int)param_1 + uVar1) = 1;
  }
  if (param_3 < 4) {
    return;
  }
  if (3 < (param_2 & 0xff)) {
    return;
  }
  *(undefined1 *)((int)param_1 + (param_2 & 0xff)) = 1;
  return;
}

/* FUN_000f3908 @ 0xf3908 (96 bytes) */
int FUN_000f3908(param_1, param_2)
  byte *param_1;
  uint param_2;
{
  param_1[0] = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[3] = (byte)(-((param_2 ^ 1) & 0xff) >> 0x1f);
  *param_1 = (byte)(-(param_2 >> 0x18 ^ 1) >> 0x1f);
  param_1[1] = (byte)(-(param_2 >> 0x10 & 0xff ^ 1) >> 0x1f);
  param_1[2] = (byte)(-(param_2 >> 8 & 0xff ^ 1) >> 0x1f);
  return;
}

/* FUN_000f3968 @ 0xf3968 (104 bytes) */
int FUN_000f3968(param_1, param_2, param_3)
  undefined4 *param_1;
  uint param_2;
  undefined4 param_3;
{
  undefined1 uVar1;
  
  uVar1 = 0;
  *param_1 = 0;
  if (param_2 >> 0x18 == 1) {
    uVar1 = (undefined1)((uint)param_3 >> 0x18);
  }
  *(undefined1 *)param_1 = uVar1;
  uVar1 = 0;
  if ((param_2 >> 0x10 & 0xff) == 1) {
    uVar1 = (undefined1)((uint)param_3 >> 0x10);
  }
  *(undefined1 *)((int)param_1 + 1) = uVar1;
  uVar1 = 0;
  if ((param_2 >> 8 & 0xff) == 1) {
    uVar1 = (undefined1)((uint)param_3 >> 8);
  }
  *(undefined1 *)((int)param_1 + 2) = uVar1;
  uVar1 = 0;
  if ((param_2 & 0xff) == 1) {
    uVar1 = (undefined1)param_3;
  }
  *(undefined1 *)((int)param_1 + 3) = uVar1;
  return;
}

/* FUN_000f39d0 @ 0xf39d0 (96 bytes) */
int FUN_000f39d0(param_1, param_2)
  undefined4 *param_1;
  uint param_2;
{
  *param_1 = 0;
  if (param_2 >> 0x18 < 4) {
    *(undefined1 *)param_1 = 1;
  }
  if ((param_2 >> 0x10 & 0xff) < 4) {
    *(undefined1 *)((int)param_1 + 1) = 1;
  }
  if ((param_2 >> 8 & 0xff) < 4) {
    *(undefined1 *)((int)param_1 + 2) = 1;
  }
  if (3 < (param_2 & 0xff)) {
    return;
  }
  *(undefined1 *)((int)param_1 + 3) = 1;
  return;
}

/* FUN_000f3a30 @ 0xf3a30 (96 bytes) */
int FUN_000f3a30(param_1)
  undefined4 param_1;
{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = 0;
  iVar4 = 0;
  do {
    iVar2 = FUN_001054ec(param_1,0);
    if (*(char *)(iVar4 + iVar2 + 0x10) != '\x01') {
      iVar3 = iVar3 + 1;
    }
    bVar1 = iVar4 != 3;
    iVar4 = iVar4 + 1;
  } while (bVar1);
  return iVar3;
}

/* FUN_000f3a90 @ 0xf3a90 (80 bytes) */
int FUN_000f3a90(param_1)
  undefined4 param_1;
{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = FUN_001054ec(param_1,0);
  uVar1 = *(uint *)(iVar2 + 0x10);
  if (((uVar1 >> 0x18 == 0) || ((uVar1 >> 0x10 & 0xff) == 0)) ||
     (uVar3 = 0, (uVar1 >> 8 & 0xff) == 0)) {
    uVar3 = 1;
  }
  return uVar3;
}

/* FUN_000f3ae0 @ 0xf3ae0 (48 bytes) */
int FUN_000f3ae0(param_1)
  undefined4 param_1;
{
  int iVar1;
  
  iVar1 = FUN_001054ec(param_1,0);
  return *(char *)(iVar1 + 0x13) == '\0';
}

/* FUN_000f3b10 @ 0xf3b10 (88 bytes) */
int FUN_000f3b10()
{
  int iVar1;
  int iVar2;
  undefined4 local_28 [10];
  
  iVar2 = FUN_001054ec();
  iVar1 = 0;
  local_28[0] = *(undefined4 *)(iVar2 + 0x10);
  iVar2 = 4;
  do {
    if (*(byte *)((int)local_28 + iVar1) < 3) {
      return 1;
    }
    iVar1 = iVar1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return 0;
}

/* FUN_000f3b68 @ 0xf3b68 (88 bytes) */
int FUN_000f3b68()
{
  int iVar1;
  int iVar2;
  undefined4 local_28 [10];
  
  iVar2 = FUN_001054ec();
  iVar1 = 0;
  local_28[0] = *(undefined4 *)(iVar2 + 0x10);
  iVar2 = 4;
  do {
    if (*(char *)((int)local_28 + iVar1) == '\x03') {
      return 1;
    }
    iVar1 = iVar1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return 0;
}

/* FUN_000f3c30 @ 0xf3c30 (972 bytes) */
int FUN_000f3c30(param_1, param_2, param_3, param_4, param_5)
  byte *param_1;
  int *param_2;
  int param_3;
  int param_4;
  undefined4 param_5;
{
  bool bVar1;
  uint uVar2;
  byte *pbVar3;
  int iVar4;
  undefined4 uVar5;
  char *pcVar6;
  int iVar7;
  char cStack00000028;
  char cStack00000029;
  char cStack0000002a;
  char cStack0000002b;
  undefined4 local_38;
  undefined4 local_34 [7];
  
  (*(char *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)) = param_5;
  (**(code **)(*param_2 + 0x14))(param_2);
  *(undefined4 *)param_1 = DAT_001aa844;
  if (0 < param_3) {
    iVar4 = FUN_00105594(param_2,param_3);
    if (iVar4 == 0) {
      iVar4 = *(int *)(param_2[param_3 * 6 + 0x23] + 4);
    }
    else {
      iVar4 = *(int *)(iVar4 + 0x98);
    }
    if ((iVar4 == 0x3b) || (iVar4 == 0x42)) goto switchD_000f3cf4_caseD_b;
  }
  uVar5 = FUN_001134bc(param_2[0x22],param_2,param_4);
  switch(uVar5) {
  case 0:
    break;
  case 1:
    if (param_3 == 2) goto switchD_000f3cf4_caseD_b;
    if (param_3 != 3) {
      if (param_3 != 1) {
        return param_1;
      }
      param_1[3] = 1;
      return param_1;
    }
    goto LAB_000f3fe8;
  case 2:
switchD_000f3cf4_caseD_2:
    param_1[3] = 1;
    *param_1 = 1;
    param_1[1] = 1;
    return param_1;
  case 3:
    if (param_3 != 3) {
      param_1[1] = 1;
      *param_1 = 1;
      return param_1;
    }
LAB_000f3fe8:
    param_1[2] = 1;
    return param_1;
  case 4:
    goto switchD_000f3cf4_caseD_4;
  default:
    goto switchD_000f3cf4_caseD_5;
  case 6:
    if (param_3 == 1) {
      iVar4 = 0;
      pbVar3 = param_1;
      do {
        iVar7 = FUN_001054ec(param_2,0);
        local_38 = *(undefined4 *)(iVar7 + 0x10);
        if (*(char *)((int)local_34 + iVar4 + -4) != '\x01') {
          *pbVar3 = *pbVar3 | 1;
        }
        bVar1 = iVar4 != 3;
        pbVar3 = pbVar3 + 1;
        iVar4 = iVar4 + 1;
      } while (bVar1);
      return param_1;
    }
    goto switchD_000f3cf4_caseD_5;
  case 7:
    if (2 < param_3) {
LAB_000f3ff4:
      param_1[3] = 1;
      return param_1;
    }
switchD_000f3cf4_caseD_4:
    param_1[2] = 1;
    *param_1 = 1;
    param_1[1] = 1;
    return param_1;
  case 9:
    iVar4 = 0;
    if (-1 < param_2[0x4d]) {
      iVar4 = *(int *)(param_2[0x4d] * 0xc + *(int *)(param_4 + 0x78) + 4);
    }
    uVar2 = (DAT_001dc58c)[iVar4 * 2];
    if ((uVar2 & 1) != 0) {
      *param_1 = 1;
    }
    if ((uVar2 & 2) != 0) {
      param_1[1] = 1;
    }
    if ((uVar2 & 4) != 0) {
      param_1[2] = 1;
    }
    if ((uVar2 & 8) != 0) {
      param_1[3] = 1;
    }
    iVar4 = *(int *)(param_2[0x22] + 8);
    if ((((iVar4 == 0x101) || (iVar4 == 0x100)) || (iVar4 == 0x102)) || (iVar4 == 0x6e))
    goto LAB_000f3ff4;
    if (((iVar4 == 0x75) || (iVar4 == 0x76)) || (iVar4 == 0xae)) goto switchD_000f3cf4_caseD_2;
    if (((iVar4 != 0x9e) && (iVar4 != 0x9f)) && ((iVar4 != 0xa0 && (iVar4 != 0xa1)))) {
      return param_1;
    }
    break;
  case 0xb:
    goto switchD_000f3cf4_caseD_b;
  case 0xc:
    iVar4 = FUN_001054ec(param_2,param_3);
    iVar7 = 0;
    pcVar6 = &STACKARG(0x28);
    local_34[0] = *(undefined4 *)(iVar4 + 0x10);
    iVar4 = 4;
    pbVar3 = param_1;
    do {
      if ((*pcVar6 == '\0') && (*(char *)((int)local_34 + iVar7) != '\x04')) {
        *pbVar3 = *pbVar3 | 1;
      }
      iVar7 = iVar7 + 1;
      pcVar6 = pcVar6 + 1;
      pbVar3 = pbVar3 + 1;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    return param_1;
  case 0xd:
    if (param_3 != 2) goto switchD_000f3cf4_caseD_5;
switchD_000f3cf4_caseD_b:
    *param_1 = 1;
    return param_1;
  case 0xe:
    if (param_3 != 1) {
      if (param_3 != 2) {
        if (param_3 != 3) {
          return param_1;
        }
        goto switchD_000f3cf4_caseD_5;
      }
      goto switchD_000f3cf4_caseD_b;
    }
    break;
  case 0xf:
    if (*(int *)(param_2[0x22] + 8) == 0xb4) {
      if (param_3 == 2) goto LAB_000f3fe8;
      if (param_3 < 3) {
        if (param_3 != 1) {
          return param_1;
        }
        *param_1 = 1;
        param_1[1] = 1;
        return param_1;
      }
      if (param_3 == 3) goto LAB_000f3ff4;
      if (param_3 != 4) {
        return param_1;
      }
    }
switchD_000f3cf4_caseD_5:
    param_1[3] = 1;
    *param_1 = 1;
    param_1[1] = 1;
    param_1[2] = 1;
    return param_1;
  }
  *param_1 = cStack00000028 == '\0';
  param_1[1] = cStack00000029 == '\0';
  param_1[2] = cStack0000002a == '\0';
  param_1[3] = cStack0000002b == '\0';
  return param_1;
}

/* FUN_000f403c @ 0xf403c (1404 bytes) */
int FUN_000f403c(param_1, param_2, param_3, param_4, param_5)
  undefined4 *param_1;
  int *param_2;
  int param_3;
  undefined4 param_4;
  int param_5;
{
  bool bVar1;
  byte *pbVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  int iVar7;
  undefined4 local_58;
  undefined4 local_54 [3];
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24 [3];
  
  (**(code **)(*param_2 + 0x14))(param_2);
  iVar4 = FUN_001054ec(param_2,param_3);
  local_58 = *(uint *)(iVar4 + 0x10);
  *param_1 = DAT_001aa844;
  uVar5 = FUN_001134bc(param_2[0x22],param_2,param_5);
  switch(uVar5) {
  case 0:
    iVar4 = FUN_001054ec(param_2,0);
    ((int (*)())FUN_000f31f8)(&local_44,*(undefined4 *)(iVar4 + 0x10),param_4);
    iVar4 = 0;
    local_54[0] = local_44;
    iVar7 = 4;
    do {
      if (*(char *)((int)local_54 + iVar4) != '\x01') {
        uVar3 = (uint)*(byte *)((int)local_54 + iVar4 + -4);
        *(byte *)((int)param_1 + uVar3) = *(byte *)((int)param_1 + uVar3) | 1;
      }
      iVar4 = iVar4 + 1;
      iVar7 = iVar7 + -1;
    } while (iVar7 != 0);
    break;
  case 1:
    if (param_3 == 2) goto switchD_000f40d0_caseD_b;
    if (param_3 != 3) {
      if (param_3 != 1) {
        return param_1;
      }
      *(undefined1 *)((int)param_1 + (local_58 & 0xff)) = 1;
      return param_1;
    }
    goto LAB_000f4584;
  case 2:
switchD_000f40d0_caseD_2:
    *(undefined1 *)((int)param_1 + (uint)(*(unsigned char *)((unsigned char *)&(local_58) + 0))) = 1;
    *(undefined1 *)((int)param_1 + (uint)(*(unsigned char *)((unsigned char *)&(local_58) + 1))) = 1;
    *(undefined1 *)((int)param_1 + (local_58 & 0xff)) = 1;
    return param_1;
  case 3:
    if (param_3 - 1U < 2) {
      ((int (*)())FUN_000f388c)(&local_40,local_58,2);
      *param_1 = local_40;
      return param_1;
    }
    if (param_3 != 3) {
      return param_1;
    }
    goto LAB_000f4584;
  case 4:
    ((int (*)())FUN_000f388c)(&local_3c,local_58,3);
    *param_1 = local_3c;
    break;
  case 5:
    ((int (*)())FUN_000f388c)(&local_38,local_58,4);
    *param_1 = local_38;
    break;
  case 6:
    if (param_3 == 1) {
      iVar4 = 0;
      do {
        iVar7 = FUN_001054ec(param_2,0);
        if (*(char *)(iVar4 + iVar7 + 0x10) != '\x01') {
          uVar3 = (uint)*(byte *)((int)local_54 + iVar4 + -4);
          *(byte *)((int)param_1 + uVar3) = *(byte *)((int)param_1 + uVar3) | 1;
        }
        bVar1 = iVar4 != 3;
        iVar4 = iVar4 + 1;
      } while (bVar1);
    }
    else {
      ((int (*)())FUN_000f388c)(&local_34,local_58,4);
      *param_1 = local_34;
    }
    break;
  case 7:
    if (param_3 < 3) {
      ((int (*)())FUN_000f388c)(&local_30,local_58,3);
      *param_1 = local_30;
      return param_1;
    }
    goto LAB_000f4594;
  case 8:
    ((int (*)())FUN_000f388c)(&local_2c,local_58,4);
    *param_1 = local_2c;
    break;
  case 9:
    if (param_2[0x4d] < 0) {
      iVar4 = 0;
      uVar3 = 0xfffffff6;
    }
    else {
      iVar4 = *(int *)(param_2[0x4d] * 0xc + *(int *)(param_5 + 0x78) + 4);
      uVar3 = iVar4 - 10;
    }
    uVar6 = (DAT_001dc58c)[iVar4 * 2];
    if ((uVar3 < 2) && ((char)local_58 == '\x04')) {
      uVar6 = uVar6 & 7;
    }
    if ((uVar6 & 1) != 0) {
      *(undefined1 *)((int)param_1 + (uint)(*(unsigned char *)((unsigned char *)&(local_58) + 0))) = 1;
    }
    if ((uVar6 & 2) != 0) {
      *(undefined1 *)((int)param_1 + (uint)(*(unsigned char *)((unsigned char *)&(local_58) + 1))) = 1;
    }
    if ((uVar6 & 4) != 0) {
      *(undefined1 *)((int)param_1 + (uint)(*(unsigned char *)((unsigned char *)&(local_58) + 2))) = 1;
    }
    if ((uVar6 & 8) != 0) {
      *(undefined1 *)((int)param_1 + (local_58 & 0xff)) = 1;
    }
    iVar4 = *(int *)(param_2[0x22] + 8);
    if (iVar4 < 0xa2) {
      if (0x9d < iVar4) {
        iVar4 = FUN_001054ec(param_2,0);
        ((int (*)())FUN_000f31f8)(&local_28,*(undefined4 *)(iVar4 + 0x10),param_4);
        local_54[0] = local_28;
        *param_1 = 0;
        iVar4 = 0;
        iVar7 = 4;
        do {
          pbVar2 = (byte *)((int)local_54 + iVar4);
          uVar3 = (uint)*(byte *)((int)local_54 + iVar4 + -4);
          iVar4 = iVar4 + 1;
          *(byte *)((int)param_1 + uVar3) =
               (byte)(-(*pbVar2 ^ 1) >> 0x1f) | *(byte *)((int)param_1 + uVar3);
          iVar7 = iVar7 + -1;
        } while (iVar7 != 0);
        return param_1;
      }
      if (iVar4 != 0x6e) {
        if (iVar4 < 0x6e) {
          return param_1;
        }
        if (1 < iVar4 - 0x75U) {
          return param_1;
        }
        goto switchD_000f40d0_caseD_2;
      }
    }
    else {
      if (iVar4 == 0xae) goto switchD_000f40d0_caseD_2;
      if (iVar4 < 0xae) {
        return param_1;
      }
      if (2 < iVar4 - 0x100U) {
        return param_1;
      }
    }
LAB_000f4594:
    *(undefined1 *)((int)param_1 + (local_58 & 0xff)) = 1;
    break;
  default:
switchD_000f40d0_caseD_a:
    *(undefined1 *)((int)param_1 + 3) = 1;
    *(undefined1 *)param_1 = 1;
    *(undefined1 *)((int)param_1 + 1) = 1;
    *(undefined1 *)((int)param_1 + 2) = 1;
    break;
  case 0xb:
    goto switchD_000f40d0_caseD_b;
  case 0xc:
    iVar4 = FUN_001054ec(param_2,0);
    ((int (*)())FUN_000f31f8)(local_24,*(undefined4 *)(iVar4 + 0x10),param_4);
    local_54[0] = local_24[0];
    *param_1 = 0;
    iVar4 = 0;
    iVar7 = 4;
    do {
      if ((*(char *)((int)local_54 + iVar4) == '\0') &&
         (uVar3 = (uint)*(byte *)((int)local_54 + iVar4 + -4), uVar3 != 4)) {
        *(byte *)((int)param_1 + uVar3) = *(byte *)((int)param_1 + uVar3) | 1;
      }
      iVar4 = iVar4 + 1;
      iVar7 = iVar7 + -1;
    } while (iVar7 != 0);
    break;
  case 0xd:
    if (param_3 != 2) {
LAB_000f45a4:
      *(undefined1 *)((int)param_1 + (uint)(*(unsigned char *)((unsigned char *)&(local_58) + 0))) = 1;
      *(undefined1 *)((int)param_1 + (uint)(*(unsigned char *)((unsigned char *)&(local_58) + 1))) = 1;
      *(undefined1 *)((int)param_1 + (uint)(*(unsigned char *)((unsigned char *)&(local_58) + 2))) = 1;
      *(undefined1 *)((int)param_1 + (local_58 & 0xff)) = 1;
      return param_1;
    }
    goto switchD_000f40d0_caseD_b;
  case 0xe:
    if (param_3 == 1) {
      iVar4 = FUN_001054ec(param_2,0);
      ((int (*)())FUN_000f31f8)(&local_48,*(undefined4 *)(iVar4 + 0x10),param_4);
      iVar4 = 0;
      local_54[0] = local_48;
      iVar7 = 4;
      do {
        if (*(char *)((int)local_54 + iVar4) != '\x01') {
          *(undefined1 *)((int)param_1 + (uint)*(byte *)((int)local_54 + iVar4 + -4)) = 1;
        }
        iVar4 = iVar4 + 1;
        iVar7 = iVar7 + -1;
      } while (iVar7 != 0);
      return param_1;
    }
    if (param_3 != 2) {
      if (param_3 != 3) {
        return param_1;
      }
      goto LAB_000f45a4;
    }
switchD_000f40d0_caseD_b:
    *(undefined1 *)((int)param_1 + (uint)(*(unsigned char *)((unsigned char *)&(local_58) + 0))) = 1;
    break;
  case 0xf:
    if (*(int *)(param_2[0x22] + 8) != 0xb4) goto switchD_000f40d0_caseD_a;
    if (param_3 != 2) {
      if (param_3 < 3) {
        if (param_3 != 1) {
          return param_1;
        }
        *(undefined1 *)((int)param_1 + (uint)(*(unsigned char *)((unsigned char *)&(local_58) + 0))) = 1;
        *(undefined1 *)((int)param_1 + (uint)(*(unsigned char *)((unsigned char *)&(local_58) + 1))) = 1;
        return param_1;
      }
      if (param_3 != 3) {
        if (param_3 != 4) {
          return param_1;
        }
        goto LAB_000f45a4;
      }
      goto LAB_000f4594;
    }
LAB_000f4584:
    *(undefined1 *)((int)param_1 + (uint)(*(unsigned char *)((unsigned char *)&(local_58) + 2))) = 1;
  }
  return param_1;
}

/* FUN_000f45f8 @ 0xf45f8 (160 bytes) */
int FUN_000f45f8(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined4 local_28 [4];
  undefined4 local_18 [2];
  
  ((int (*)())FUN_000f403c)(local_18,param_1,param_2,DAT_001aa840,param_4);
  iVar3 = 0;
  local_28[0] = local_18[0];
  while ((*(char *)((int)local_28 + iVar3) == '\0' ||
         (iVar2 = FUN_001054ec(param_3,0), *(char *)(iVar3 + iVar2 + 0x10) != '\x01'))) {
    bVar1 = iVar3 == 3;
    iVar3 = iVar3 + 1;
    if (bVar1) {
      return 1;
    }
  }
  return 0;
}

/* FUN_000f4698 @ 0xf4698 (148 bytes) */
int FUN_000f4698(param_1, param_2, param_3)
  int param_1;
  int param_2;
  undefined4 param_3;
{
  int iVar1;
  undefined4 local_18;
  undefined4 local_14;
  
  iVar1 = FUN_001054ec(param_1,0);
  ((int (*)())FUN_000f3c30)(&local_18,param_1,param_2,param_3,*(undefined4 *)(iVar1 + 0x10));
  iVar1 = FUN_001054ec(param_1,param_2);
  ((int (*)())FUN_000f3340)(&local_14,*(undefined4 *)(iVar1 + 0x10),local_18);
  if (param_2 == 0) {
    *(undefined4 *)(param_1 + 0x9c) = local_14;
  }
  else {
    iVar1 = FUN_001054ec(param_1,param_2);
    *(undefined4 *)(iVar1 + 0x10) = local_14;
  }
  return;
}

/* FUN_000f472c @ 0xf472c (124 bytes) */
int FUN_000f472c(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  int iVar1;
  int iVar2;
  undefined4 local_28 [8];
  
  iVar2 = FUN_001054ec(param_2,0);
  iVar1 = 0;
  local_28[0] = *(undefined4 *)(iVar2 + 0x10);
  iVar2 = 4;
  do {
    if (*(char *)((int)local_28 + iVar1) == '\x01') {
      *(undefined1 *)((int)local_28 + iVar1) = 0;
    }
    else {
      *(undefined1 *)((int)local_28 + iVar1) = 1;
    }
    iVar1 = iVar1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  *(undefined4 *)(param_1 + 0x9c) = local_28[0];
  return;
}

/* FUN_000f47a8 @ 0xf47a8 (180 bytes) */
int FUN_000f47a8(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  int iVar1;
  int iVar2;
  undefined4 local_28;
  undefined4 local_24 [6];
  
  iVar1 = FUN_001054ec(param_2,0);
  local_28 = *(undefined4 *)(iVar1 + 0x10);
  iVar2 = FUN_001054ec(param_3,0);
  iVar1 = 0;
  local_24[0] = *(undefined4 *)(iVar2 + 0x10);
  iVar2 = 4;
  do {
    if ((*(char *)((int)local_24 + iVar1 + -4) != '\x01') &&
       (*(char *)((int)local_24 + iVar1) != '\x01')) break;
    iVar1 = iVar1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  iVar1 = 0;
  iVar2 = 4;
  do {
    if (*(char *)((int)local_24 + iVar1) != '\x01') {
      *(char *)((int)local_24 + iVar1 + -4) = *(char *)((int)local_24 + iVar1);
    }
    iVar1 = iVar1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  *(undefined4 *)(param_1 + 0x9c) = local_28;
  return;
}

/* FUN_000f485c @ 0xf485c (144 bytes) */
int FUN_000f485c(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  bool bVar1;
  byte bVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined4 local_38 [9];
  
  uVar3 = FUN_00105594();
  iVar4 = FUN_001054ec(param_1,param_2);
  iVar5 = 0;
  local_38[0] = *(undefined4 *)(iVar4 + 0x10);
  while ((bVar2 = *(byte *)((int)local_38 + iVar5), bVar2 == 4 ||
         (iVar4 = FUN_001054ec(uVar3,0), *(char *)((uint)bVar2 + iVar4 + 0x10) == '\x01'))) {
    bVar1 = iVar5 == 3;
    iVar5 = iVar5 + 1;
    if (bVar1) {
      return 1;
    }
  }
  return 0;
}

/* FUN_000f48ec @ 0xf48ec (144 bytes) */
int FUN_000f48ec(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  bool bVar1;
  byte bVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined4 local_38 [9];
  
  uVar3 = FUN_00105594();
  iVar4 = FUN_001054ec(param_1,param_2);
  iVar5 = 0;
  local_38[0] = *(undefined4 *)(iVar4 + 0x10);
  while ((bVar2 = *(byte *)((int)local_38 + iVar5), bVar2 == 4 ||
         (iVar4 = FUN_001054ec(uVar3,0), *(char *)((uint)bVar2 + iVar4 + 0x10) != '\x01'))) {
    bVar1 = iVar5 == 3;
    iVar5 = iVar5 + 1;
    if (bVar1) {
      return 1;
    }
  }
  return 0;
}

/* FUN_000f497c @ 0xf497c (168 bytes) */
int FUN_000f497c(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  int iVar1;
  uint local_28;
  uint local_24;
  uint local_20 [5];
  
  iVar1 = FUN_001054ec(param_1,0);
  ((int (*)())FUN_000f3908)(&local_28,*(undefined4 *)(iVar1 + 0x10));
  iVar1 = FUN_001055cc(param_2);
  if (iVar1 == 0) {
    iVar1 = FUN_001054ec(param_2,0);
    ((int (*)())FUN_000f3968)(local_20,*(undefined4 *)(iVar1 + 0x10),DAT_001aa840);
    local_24 = local_20[0];
  }
  else {
    iVar1 = FUN_001054ec(param_2,0);
    ((int (*)())FUN_000f3908)(&local_24,*(undefined4 *)(iVar1 + 0x10));
  }
  return (local_28 & local_24) != 0;
}

/* FUN_000f4a24 @ 0xf4a24 (56 bytes) */
int FUN_000f4a24(param_1, param_2)
  undefined4 *param_1;
  undefined4 *param_2;
{
  param_2[0x12] = 2;
  *param_2 = 2;
  param_2[6] = 2;
  param_2[0xc] = 2;
  param_2[1] = *param_1;
  param_2[7] = param_1[1];
  param_2[0xd] = param_1[2];
  param_2[0x13] = param_1[3];
  return;
}

/* FUN_000f4a5c @ 0xf4a5c (20 bytes) */
int FUN_000f4a5c(param_1)
  int param_1;
{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x30);
  *(int *)(param_1 + 0x30) = iVar1 + -1;
  return iVar1;
}

/* FUN_000f4a84 @ 0xf4a84 (324 bytes) */
int FUN_000f4a84(param_1, param_2, param_3)
  int *param_1;
  int param_2;
  int param_3;
{
  int iVar1;
  int iVar2;
  
  if (param_2 == 2) {
    iVar1 = *(int *)(*param_1 + 0x398);
    if (param_1[0xb] == 0) {
      iVar2 = *(int *)(iVar1 + 0x2c);
    }
    else {
      iVar2 = *(int *)(iVar1 + 0x30);
    }
    iVar1 = FUN_000d9b58(iVar1,iVar2 + 0x58,param_1[0xe]);
    if (-1 < iVar1) {
      param_1[0xe] = param_1[0xe] + 1;
    }
    goto LAB_000f4b94;
  }
  if (param_2 < 3) {
    if (param_2 != 1) {
LAB_000f4ac4:
      iVar1 = -1;
      goto LAB_000f4b94;
    }
  }
  else if (param_2 != 3) {
    if (param_2 == 4) {
      iVar1 = *(int *)(*param_1 + 0x398);
      if (param_1[0xb] == 0) {
        iVar2 = *(int *)(iVar1 + 0x2c);
      }
      else {
        iVar2 = *(int *)(iVar1 + 0x30);
      }
      iVar1 = FUN_000d9b58(iVar1,iVar2 + 0x98,param_1[0x10]);
      if (-1 < iVar1) {
        param_1[0x10] = param_1[0x10] + 1;
      }
      goto LAB_000f4b94;
    }
    goto LAB_000f4ac4;
  }
  iVar1 = *(int *)(*param_1 + 0x398);
  if (param_1[0xb] == 0) {
    iVar2 = *(int *)(iVar1 + 0x2c);
  }
  else {
    iVar2 = *(int *)(iVar1 + 0x30);
  }
  iVar1 = FUN_000d9b58(iVar1,iVar2 + 0x78,param_1[0xf]);
  if (-1 < iVar1) {
    param_1[0xf] = param_1[0xf] + 1;
  }
LAB_000f4b94:
  if ((param_3 == 0) && (iVar1 < 0)) {
    FUN_000e1534(*param_1,0xd);
  }
  return iVar1;
}

/* FUN_000f4d80 @ 0xf4d80 (92 bytes) */
int FUN_000f4d80(param_1, param_2)
  int param_1;
  int param_2;
{
  uint uVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  
  uVar1 = 0;
  puVar2 = &local_2c;
  iVar3 = 4;
  do {
    if (((int)*(char *)(param_2 + 0x15c) >> (uVar1 & 0x3f) & 1U) == 0) break;
    uVar1 = uVar1 + 1;
    puVar2 = puVar2 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  local_28 = *(undefined4 *)(param_1 + 8);
  local_24 = *(undefined4 *)(param_1 + 0xc);
  local_20 = *(undefined4 *)(param_1 + 0x10);
  local_1c = *(undefined4 *)(param_1 + 0x14);
  FUN_00194720(*puVar2);
  return;
}

/* FUN_000f4ddc @ 0xf4ddc (512 bytes) */
int FUN_000f4ddc(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  char cVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint *puVar5;
  int *piVar6;
  undefined4 uVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  int iVar10;
  uint *puVar11;
  int *piVar12;
  int iVar13;
  uint local_1d8 [4];
  undefined4 local_1c8 [4];
  undefined4 local_1b8 [24];
  int aiStack_158 [75];
  int aiStack_2c [3];
  
  _memcpy(aiStack_158,&DAT_001aa87c,300);
  cVar1 = *(char *)(param_3 + 0x15c);
  puVar9 = local_1b8;
  puVar11 = local_1d8;
  uVar4 = 0;
  iVar13 = 4;
  puVar5 = puVar11;
  puVar8 = puVar9;
  iVar10 = param_3;
  do {
    uVar2 = uVar4 & 0x3f;
    uVar7 = *(undefined4 *)(iVar10 + 0x20);
    *puVar8 = *(undefined4 *)(iVar10 + 0x1c);
    uVar4 = uVar4 + 1;
    puVar8[1] = uVar7;
    iVar10 = iVar10 + 0x18;
    *puVar5 = (int)cVar1 >> uVar2 & 1;
    puVar8 = puVar8 + 6;
    puVar5 = puVar5 + 1;
    iVar13 = iVar13 + -1;
  } while (iVar13 != 0);
  local_1c8[0] = *(undefined4 *)(param_1 + 8);
  local_1c8[1] = *(undefined4 *)(param_1 + 0xc);
  local_1c8[2] = *(undefined4 *)(param_1 + 0x10);
  local_1c8[3] = *(undefined4 *)(param_1 + 0x14);
  if (*(int *)(&DAT_001aa86c + (4 - param_2) * 4) < 0xf) {
    piVar12 = aiStack_158 + *(int *)(&DAT_001aa86c + (4 - param_2) * 4) * 5;
    do {
      iVar13 = 4;
      uVar4 = 0;
      piVar6 = piVar12;
      iVar10 = param_3;
      do {
        iVar3 = piVar6[1];
        if (iVar3 < 0) {
          *(undefined4 *)(iVar10 + 0x1c) = 0;
          *(undefined4 *)(iVar10 + 0x20) = 0;
          *(byte *)(param_3 + 0x15c) = *(byte *)(param_3 + 0x15c) & ~(byte)(1 << (uVar4 & 0x3f));
        }
        else {
          uVar7 = local_1b8[iVar3 * 6];
          *(undefined4 *)(iVar10 + 0x20) = local_1b8[iVar3 * 6 + 1];
          *(undefined4 *)(iVar10 + 0x1c) = uVar7;
          *(byte *)(param_3 + 0x15c) = (byte)(1 << (uVar4 & 0x3f)) | *(byte *)(param_3 + 0x15c);
        }
        uVar4 = uVar4 + 1;
        piVar6 = piVar6 + 1;
        iVar10 = iVar10 + 0x18;
        iVar13 = iVar13 + -1;
      } while (iVar13 != 0);
      iVar10 = *piVar12;
      piVar12 = piVar12 + 5;
      FUN_00194d44(local_1c8[iVar10],param_3);
    } while (piVar12 != aiStack_2c);
  }
  iVar13 = 4;
  uVar4 = 0;
  iVar10 = param_3;
  do {
    uVar7 = puVar9[1];
    *(undefined4 *)(iVar10 + 0x1c) = *puVar9;
    *(undefined4 *)(iVar10 + 0x20) = uVar7;
    uVar2 = *puVar11;
    puVar11 = puVar11 + 1;
    if (uVar2 == 0) {
      *(byte *)(param_3 + 0x15c) = *(byte *)(param_3 + 0x15c) & ~(byte)(1 << (uVar4 & 0x3f));
    }
    else {
      *(byte *)(param_3 + 0x15c) = (byte)(1 << (uVar4 & 0x3f)) | *(byte *)(param_3 + 0x15c);
    }
    uVar4 = uVar4 + 1;
    puVar9 = puVar9 + 6;
    iVar10 = iVar10 + 0x18;
    iVar13 = iVar13 + -1;
  } while (iVar13 != 0);
  return;
}

/* FUN_000f4fdc @ 0xf4fdc (588 bytes) */
int FUN_000f4fdc(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int *param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int *piVar5;
  int iVar6;
  uint uVar7;
  undefined4 *puVar8;
  int iVar9;
  undefined4 uStack00000020;
  undefined4 uStack00000024;
  undefined4 uStack00000028;
  undefined4 uStack0000002c;
  undefined4 uStack00000030;
  undefined4 uStack00000034;
  undefined4 in_stack_00000038;
  undefined4 in_stack_0000003c;
  undefined4 in_stack_00000050;
  undefined4 in_stack_00000054;
  undefined4 in_stack_00000068;
  undefined4 in_stack_0000006c;
  int aiStack_9c [4];
  int local_8c;
  undefined4 local_88 [6];
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_40;
  undefined4 local_3c;
  
  aiStack_9c[1] = param_1[2];
  aiStack_9c[2] = param_1[3];
  local_70 = in_stack_00000038;
  local_6c = in_stack_0000003c;
  local_58 = in_stack_00000050;
  local_54 = in_stack_00000054;
  local_40 = in_stack_00000068;
  iVar9 = 4;
  iVar6 = 0;
  uVar7 = 0;
  local_88[0] = param_3;
  local_88[1] = param_4;
  aiStack_9c[3] = param_1[4];
  local_8c = param_1[5];
  local_3c = in_stack_0000006c;
  do {
    if ((int)uVar7 < param_2) {
      *(byte *)(param_1[10] + 0x15c) = (byte)(1 << (uVar7 & 0x3f)) | *(byte *)(param_1[10] + 0x15c);
      uVar1 = *(undefined4 *)((int)local_88[0] + iVar6);
      iVar2 = iVar6 + 0x10 + param_1[10];
      *(undefined4 *)(iVar2 + 0x10) = *(undefined4 *)((int)local_88[0] + iVar6 + 4);
      *(undefined4 *)(iVar2 + 0xc) = uVar1;
    }
    else {
      *(byte *)(param_1[10] + 0x15c) = *(byte *)(param_1[10] + 0x15c) & ~(byte)(1 << (uVar7 & 0x3f))
      ;
    }
    uVar7 = uVar7 + 1;
    iVar6 = iVar6 + 0x18;
    iVar9 = iVar9 + -1;
  } while (iVar9 != 0);
  uStack00000020 = param_3;
  uStack00000024 = param_4;
  uStack00000028 = param_5;
  uStack0000002c = param_6;
  uStack00000030 = param_7;
  uStack00000034 = param_8;
  puVar3 = (undefined4 *)FUN_00194834(aiStack_9c[param_2],param_1[10]);
  if (puVar3 == (undefined4 *)0x0) {
    uVar1 = *(undefined4 *)(*param_1 + 0x374);
    puVar4 = (undefined4 *)FUN_00193e18(uVar1,0x168);
    *puVar4 = uVar1;
    puVar3 = puVar4 + 1;
    FUN_00109938(puVar3,*param_1);
    if ((*(uint *)(*(int *)(*param_1 + 0x6c4) + 0x30) & 0x10000) == 0) {
      uVar1 = ((int (*)())FUN_000f4a5c)(param_1);
      puVar4[0x26] = uVar1;
      puVar4[0x27] = 0xc;
    }
    else {
      uVar1 = ((int (*)())FUN_000f4a84)(param_1,local_88[0],0);
      puVar4[0x26] = uVar1;
      puVar4[0x27] = 0xc;
    }
    uVar7 = 0;
    iVar9 = 4;
    puVar8 = puVar4 + 5;
    iVar6 = 0;
    do {
      if ((int)uVar7 < param_2) {
        *(byte *)(puVar4 + 0x58) = (byte)(1 << (uVar7 & 0x3f)) | *(byte *)(puVar4 + 0x58);
        uVar1 = *(undefined4 *)((int)local_88[0] + iVar6);
        puVar8[4] = *(undefined4 *)((int)local_88[0] + iVar6 + 4);
        puVar8[3] = uVar1;
      }
      else {
        *(byte *)(puVar4 + 0x58) = *(byte *)(puVar4 + 0x58) & ~(byte)(1 << (uVar7 & 0x3f));
      }
      uVar7 = uVar7 + 1;
      iVar6 = iVar6 + 0x18;
      puVar8 = puVar8 + 6;
      iVar9 = iVar9 + -1;
    } while (iVar9 != 0);
    piVar5 = *(int **)(*(int *)(*param_1 + 0x6c4) + 0x3a0);
    (**(code **)(*piVar5 + 0xc))(piVar5,puVar3);
    ((int (*)())FUN_000f4ddc)(param_1,param_2,puVar3);
  }
  return puVar3;
}

/* FUN_000f5248 @ 0xf5248 (376 bytes) */
int FUN_000f5248(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  undefined4 uStack0000001c;
  undefined4 uStack00000020;
  undefined4 uStack00000024;
  undefined4 uStack00000028;
  undefined4 uStack0000002c;
  undefined4 uStack00000030;
  undefined4 uStack00000034;
  
  uStack0000001c = param_2;
  uStack00000020 = param_3;
  uStack00000024 = param_4;
  uStack00000028 = param_5;
  uStack0000002c = param_6;
  uStack00000030 = param_7;
  uStack00000034 = param_8;
  ((int (*)())FUN_000f4fdc)(param_1,4,param_2,param_3,param_4,param_5,param_6,param_7);
  return;
}

/* FUN_000f53c0 @ 0xf53c0 (396 bytes) */
int FUN_000f53c0(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  undefined4 uStack0000001c;
  undefined4 uStack00000020;
  undefined4 uStack00000024;
  undefined4 uStack00000028;
  undefined4 uStack0000002c;
  undefined4 uStack00000030;
  undefined4 uStack00000034;
  
  uStack0000001c = param_2;
  uStack00000020 = param_3;
  uStack00000024 = param_4;
  uStack00000028 = param_5;
  uStack0000002c = param_6;
  uStack00000030 = param_7;
  uStack00000034 = param_8;
  ((int (*)())FUN_000f4fdc)(param_1,3,param_2,param_3,param_4,param_5,param_6,param_7);
  return;
}

/* FUN_000f554c @ 0xf554c (352 bytes) */
int FUN_000f554c(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  undefined4 uStack0000001c;
  undefined4 uStack00000020;
  undefined4 uStack00000024;
  undefined4 uStack00000028;
  undefined4 uStack0000002c;
  undefined4 uStack00000030;
  undefined4 uStack00000034;
  
  uStack0000001c = param_2;
  uStack00000020 = param_3;
  uStack00000024 = param_4;
  uStack00000028 = param_5;
  uStack0000002c = param_6;
  uStack00000030 = param_7;
  uStack00000034 = param_8;
  ((int (*)())FUN_000f4fdc)(param_1,2,param_2,param_3,param_4,param_5,param_6,param_7);
  return;
}

/* FUN_000f56ac @ 0xf56ac (324 bytes) */
int FUN_000f56ac(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  undefined4 uStack0000001c;
  undefined4 uStack00000020;
  undefined4 uStack00000024;
  undefined4 uStack00000028;
  undefined4 uStack0000002c;
  undefined4 uStack00000030;
  
  uStack0000001c = param_2;
  uStack00000020 = param_3;
  uStack00000024 = param_4;
  uStack00000028 = param_5;
  uStack0000002c = param_6;
  uStack00000030 = param_7;
  ((int (*)())FUN_000f4fdc)(param_1,1,param_2,param_3,param_4,param_5,param_6,param_7);
  return;
}

/* FUN_000f57f0 @ 0xf57f0 (540 bytes) */
int FUN_000f57f0(param_1, param_2, param_3)
  int *param_1;
  int param_2;
  char *param_3;
{
  bool bVar1;
  float fVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  int iVar6;
  char *pcVar7;
  uint uVar8;
  uint *puVar9;
  int iVar10;
  int iVar11;
  undefined4 local_38 [8];
  
  if (param_1[7] != 0) {
    uVar8 = 0;
    do {
      puVar9 = (uint *)param_1[8];
      if (uVar8 < *puVar9) {
        uVar4 = puVar9[1];
        if (uVar4 <= uVar8) {
          _memset((void *)(uVar4 * 4 + puVar9[2]),0,(uVar8 - uVar4) * 4 + 4);
          puVar9[1] = uVar8 + 1;
        }
        piVar5 = (int *)(uVar8 * 4 + puVar9[2]);
      }
      else {
        piVar5 = (int *)FUN_0019423c(puVar9,uVar8);
      }
      iVar10 = *piVar5;
      iVar6 = 0;
      pcVar7 = param_3;
      do {
        if (*pcVar7 != '\x04') {
          uVar4 = 0;
          iVar11 = 4;
          iVar3 = iVar10;
          while (((((int)*(char *)(iVar10 + 0x15c) >> (uVar4 & 0x3f) & 1U) == 0 ||
                  (*(int *)(iVar3 + 0x1c) != 2)) ||
                 (*(float *)(iVar3 + 0x20) != *(float *)(param_2 + iVar6)))) {
            uVar4 = uVar4 + 1;
            iVar3 = iVar3 + 0x18;
            iVar11 = iVar11 + -1;
            if (iVar11 == 0) goto LAB_000f59bc;
          }
        }
        bVar1 = iVar6 != 0xc;
        pcVar7 = pcVar7 + 1;
        iVar6 = iVar6 + 4;
      } while (bVar1);
      iVar6 = 0;
      local_38[0] = *(undefined4 *)param_3;
      pcVar7 = param_3;
      do {
        uVar4 = (uint)*(byte *)((int)local_38 + iVar6);
        if (((uVar4 != 4) && (((int)*(char *)(iVar10 + 0x15c) >> (uVar4 & 0x3f) & 1U) != 0)) &&
           (fVar2 = *(float *)(param_2 + iVar6 * 4),
           *(float *)(uVar4 * 0x18 + iVar10 + 0x20) != fVar2)) {
          iVar11 = 4;
          uVar4 = 0;
          iVar3 = iVar10;
          do {
            if (((((int)*(char *)(iVar10 + 0x15c) >> (uVar4 & 0x3f) & 1U) != 0) &&
                (*(int *)(iVar3 + 0x1c) == 2)) && (*(float *)(iVar3 + 0x20) == fVar2)) {
              *pcVar7 = (char)uVar4;
              break;
            }
            uVar4 = uVar4 + 1;
            iVar3 = iVar3 + 0x18;
            iVar11 = iVar11 + -1;
          } while (iVar11 != 0);
        }
        bVar1 = iVar6 != 3;
        pcVar7 = pcVar7 + 1;
        iVar6 = iVar6 + 1;
      } while (bVar1);
      iVar6 = (**(code **)(**(int **)(*param_1 + 0x30c) + 0x100))
                        (*(int **)(*param_1 + 0x30c),param_3);
      if (iVar6 != 0) {
        *(undefined4 *)(iVar10 + 0x9c) = DAT_001aa860;
        return iVar10;
      }
LAB_000f59bc:
      uVar8 = uVar8 + 1;
    } while (uVar8 < (uint)param_1[7]);
  }
  return 0;
}

/* FUN_000f5a0c @ 0xf5a0c (512 bytes) */
int FUN_000f5a0c(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  undefined4 param_3;
  int param_4;
{
  bool bVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  int *piVar7;
  int iVar8;
  double dVar9;
  
  iVar3 = FUN_0011379c(*(undefined4 *)(param_4 + 8),param_3);
  if (iVar3 == 0) goto LAB_000f5a8c;
  uVar2 = *(uint *)(param_2 * 0x18 + param_1 + 0xa0) & 1;
  FUN_001054ec(param_3,0);
  iVar3 = FUN_00105594(param_1,param_2);
  iVar3 = *(int *)(iVar3 + 0x98);
  if (iVar3 == 0xc) {
LAB_000f5b30:
    iVar3 = FUN_00105594(param_1,param_2);
    piVar7 = *(int **)(*(int *)(param_4 + 8) + 0x30c);
    iVar8 = 0;
    do {
      iVar5 = FUN_001054ec(param_3,0);
      if (*(char *)(iVar8 + iVar5 + 0x10) != '\x01') {
        iVar5 = FUN_001054ec(param_1,param_2);
        uVar6 = (uint)*(byte *)(iVar8 + iVar5 + 0x10);
        if (uVar6 != 4) {
          if (((int)*(char *)(iVar3 + 0x15c) >> (uVar6 & 0x3f) & 1U) == 0) goto LAB_000f5a8c;
          if (uVar2 == 0) {
            dVar9 = (double)*(float *)(uVar6 * 0x18 + iVar3 + 0x20);
          }
          else {
            dVar9 = -(double)*(float *)(uVar6 * 0x18 + iVar3 + 0x20);
          }
          iVar5 = (**(code **)(*piVar7 + 0xf0))(dVar9,piVar7);
          if (iVar5 == 0) goto LAB_000f5a8c;
        }
      }
      bVar1 = iVar8 != 3;
      iVar8 = iVar8 + 1;
    } while (bVar1);
LAB_000f5b28:
    uVar4 = 1;
  }
  else {
    if (iVar3 == 0x33) {
      if (uVar2 == 0) {
        iVar3 = FUN_00105594(param_1,param_2);
        iVar8 = 0;
        piVar7 = *(int **)(*(int *)(param_4 + 8) + 0x30c);
        do {
          iVar5 = FUN_001054ec(param_3,0);
          if (*(char *)(iVar8 + iVar5 + 0x10) != '\x01') {
            iVar5 = FUN_001054ec(param_1,param_2);
            uVar2 = (uint)*(byte *)(iVar8 + iVar5 + 0x10);
            if ((uVar2 != 4) &&
               (iVar5 = (**(code **)(*piVar7 + 0xf0))
                                  ((double)*(float *)(uVar2 * 0x18 + iVar3 + 0x20),piVar7),
               iVar5 == 0)) goto LAB_000f5a8c;
          }
          bVar1 = iVar8 != 3;
          iVar8 = iVar8 + 1;
        } while (bVar1);
        goto LAB_000f5b28;
      }
    }
    else if (iVar3 == 2) goto LAB_000f5b30;
LAB_000f5a8c:
    uVar4 = 0;
  }
  return uVar4;
}

/* FUN_000f5c0c @ 0xf5c0c (228 bytes) */
int FUN_000f5c0c(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  int *param_4;
{
  uint uVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  char *pcVar6;
  undefined4 uStack00000020;
  undefined4 local_38 [9];
  
  uStack00000020 = param_3;
  piVar2 = (int *)FUN_00105594();
  iVar3 = (**(code **)(*piVar2 + 0x48))();
  if (iVar3 == 0) {
LAB_000f5cd8:
    uVar4 = 0;
  }
  else {
    iVar3 = FUN_001054ec(param_1,param_2);
    iVar5 = 0;
    pcVar6 = (char *)&STACKARG(0x20);
    local_38[0] = *(undefined4 *)(iVar3 + 0x10);
    iVar3 = 4;
    do {
      if (((*pcVar6 == '\0') && (uVar1 = (uint)*(byte *)((int)local_38 + iVar5), uVar1 < 4)) &&
         ((((int)*(char *)(piVar2 + 0x57) >> (uVar1 & 0x3f) & 1U) == 0 ||
          (piVar2[uVar1 * 6 + 8] != *param_4)))) goto LAB_000f5cd8;
      iVar5 = iVar5 + 1;
      pcVar6 = pcVar6 + 1;
      param_4 = param_4 + 1;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    uVar4 = 1;
  }
  return uVar4;
}

/* FUN_000f5cf0 @ 0xf5cf0 (412 bytes) */
int FUN_000f5cf0(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  undefined4 param_3;
  int *param_4;
{
  bool bVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  uint uVar6;
  undefined4 uStack00000020;
  undefined4 local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  
  uStack00000020 = param_3;
  piVar2 = (int *)FUN_00105594();
  iVar3 = (**(code **)(*piVar2 + 0x48))();
  if (iVar3 != 0) {
    iVar3 = FUN_001054ec(param_1,param_2);
    bVar1 = false;
    iVar4 = 0;
    pcVar5 = (char *)&STACKARG(0x20);
    local_48 = *(undefined4 *)(iVar3 + 0x10);
    iVar3 = 4;
    do {
      if ((*pcVar5 == '\0') && (uVar6 = (uint)*(byte *)((int)&local_48 + iVar4), uVar6 < 4)) {
        local_40 = piVar2[uVar6 * 6 + 8];
        local_3c = piVar2[uVar6 * 6 + 9];
        local_38 = piVar2[uVar6 * 6 + 10];
        local_44 = piVar2[uVar6 * 6 + 7];
        local_30 = piVar2[uVar6 * 6 + 0xc];
        local_34 = piVar2[uVar6 * 6 + 0xb];
        if (piVar2[uVar6 * 6 + 7] != 2) {
          return 0;
        }
        if (((int)*(char *)(piVar2 + 0x57) >> (uVar6 & 0x3f) & 1U) == 0) {
          return 0;
        }
        if (bVar1) {
          if (*param_4 != 2) {
            return 0;
          }
          if (local_40 != param_4[1]) {
            return 0;
          }
          bVar1 = true;
        }
        else {
          bVar1 = true;
          *param_4 = 2;
          param_4[1] = local_40;
        }
      }
      iVar4 = iVar4 + 1;
      pcVar5 = pcVar5 + 1;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    if (bVar1) {
      if (((*(uint *)(param_2 * 0x18 + param_1 + 0xa0) & 2) != 0) &&
         ((float)param_4[1] < FLOAT_001aa0d4)) {
        param_4[1] = (int)-(float)param_4[1];
      }
      if ((*(uint *)(param_2 * 0x18 + param_1 + 0xa0) & 1) != 0) {
        param_4[1] = (int)-(float)param_4[1];
        return 1;
      }
      return 1;
    }
  }
  return 0;
}

/* FUN_000f5e8c @ 0xf5e8c (264 bytes) */
int FUN_000f5e8c(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  undefined4 local_38;
  int local_34;
  float local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  
  piVar1 = (int *)FUN_00105594();
  iVar2 = (**(code **)(*piVar1 + 0x48))();
  if (iVar2 == 0) {
LAB_000f5f7c:
    uVar3 = 0;
  }
  else {
    iVar2 = FUN_001054ec(param_1,param_2);
    iVar4 = 0;
    local_38 = *(undefined4 *)(iVar2 + 0x10);
    iVar2 = 4;
    do {
      uVar5 = (uint)*(byte *)((int)&local_38 + iVar4);
      if (uVar5 < 4) {
        local_30 = (float)piVar1[uVar5 * 6 + 8];
        local_2c = piVar1[uVar5 * 6 + 9];
        local_28 = piVar1[uVar5 * 6 + 10];
        local_34 = piVar1[uVar5 * 6 + 7];
        local_20 = piVar1[uVar5 * 6 + 0xc];
        local_24 = piVar1[uVar5 * 6 + 0xb];
        if (((piVar1[uVar5 * 6 + 7] != 2) ||
            (((int)*(char *)(piVar1 + 0x57) >> (uVar5 & 0x3f) & 1U) == 0)) ||
           ((float)piVar1[uVar5 * 6 + 8] < FLOAT_001aa0d4)) goto LAB_000f5f7c;
      }
      iVar4 = iVar4 + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    uVar3 = 1;
  }
  return uVar3;
}

/* FUN_000f5f94 @ 0xf5f94 (304 bytes) */
int FUN_000f5f94(param_1, param_2, param_3)
  int param_1;
  int param_2;
  byte *param_3;
{
  uint uVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  byte *pbVar6;
  uint uVar7;
  uint *puVar8;
  int iVar9;
  
  if (*(int *)(param_1 + 0x1c) != 0) {
    uVar7 = 0;
    do {
      puVar8 = *(uint **)(param_1 + 0x20);
      if (uVar7 < *puVar8) {
        uVar1 = puVar8[1];
        if (uVar1 <= uVar7) {
          _memset((void *)(uVar1 * 4 + puVar8[2]),0,(uVar7 - uVar1) * 4 + 4);
          puVar8[1] = uVar7 + 1;
        }
        piVar2 = (int *)(uVar7 * 4 + puVar8[2]);
      }
      else {
        piVar2 = (int *)FUN_0019423c(puVar8,uVar7);
      }
      iVar3 = *piVar2;
      iVar9 = 4;
      iVar5 = 0;
      pbVar6 = param_3;
      while ((uVar1 = (uint)*pbVar6, uVar1 == 4 ||
             (((((int)*(char *)(iVar3 + 0x15c) >> (uVar1 & 0x3f) & 1U) != 0 &&
               (iVar4 = uVar1 * 0x18 + iVar3, *(int *)(iVar4 + 0x1c) == 2)) &&
              (*(float *)(iVar4 + 0x20) == *(float *)(iVar5 + param_2)))))) {
        pbVar6 = pbVar6 + 1;
        iVar5 = iVar5 + 4;
        iVar9 = iVar9 + -1;
        if (iVar9 == 0) {
          *(undefined4 *)(iVar3 + 0x9c) = DAT_001aa860;
          return iVar3;
        }
      }
      uVar7 = uVar7 + 1;
    } while (uVar7 < *(uint *)(param_1 + 0x1c));
  }
  return 0;
}

/* FUN_000f60c4 @ 0xf60c4 (388 bytes) */
int FUN_000f60c4(param_1, param_2)
  int param_1;
  int param_2;
{
  bool bVar1;
  uint uVar2;
  int *piVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  uint *puVar7;
  uint uVar8;
  int iVar9;
  undefined1 auStack_b8 [148];
  
  puVar7 = *(uint **)(param_1 + 0x3c8);
  uVar2 = puVar7[1];
  uVar8 = 0;
  if (uVar2 != 0) {
    do {
      if (uVar8 < *puVar7) {
        if (uVar2 <= uVar8) {
          _memset((void *)(uVar2 * 4 + puVar7[2]),0,(uVar8 - uVar2) * 4 + 4);
          puVar7[1] = uVar8 + 1;
        }
        piVar3 = (int *)(uVar8 * 4 + puVar7[2]);
      }
      else {
        piVar3 = (int *)FUN_0019423c(puVar7,uVar8);
      }
      uVar6 = uVar8 + 1;
      iVar9 = *piVar3;
      if ((((*(uint *)(iVar9 + 0x14) & 1) != 0) && ((*(byte *)(iVar9 + 0x15c) & 1) != 0)) &&
         (*(int *)(iVar9 + 0x98) == 0xc)) {
        uVar2 = 0;
        uVar4 = (**(code **)(**(int **)(param_2 + 0x30c) + 0x158))
                          (*(int **)(param_2 + 0x30c),*(undefined4 *)(iVar9 + 0x94),
                           *(undefined4 *)(iVar9 + 0x1c),0,param_2);
        iVar5 = FUN_001054ec(iVar9,0);
        *(undefined4 *)(iVar5 + 8) = uVar4;
        FUN_000e0e0c(param_2,"(%d)  %d, regnum = %s[%d]: ",*(undefined4 *)(iVar9 + 0x14c),uVar8,"k",
                     *(undefined4 *)(iVar9 + 0x94));
        do {
          if (((int)*(char *)(iVar9 + 0x15c) >> (uVar2 & 0x3f) & 1U) == 0) break;
          FUN_000e0e0c(param_2,"  %s ",auStack_b8);
          bVar1 = uVar2 != 3;
          uVar2 = uVar2 + 1;
        } while (bVar1);
        FUN_000e0e0c(param_2,"\n");
      }
      uVar2 = puVar7[1];
      uVar8 = uVar6;
    } while (uVar6 < uVar2);
  }
  return;
}

/* FUN_000f6248 @ 0xf6248 (532 bytes) */
int FUN_000f6248(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined4 uStack00000020;
  undefined4 uStack00000024;
  undefined4 uStack00000028;
  undefined4 uStack0000002c;
  undefined4 uStack00000030;
  undefined4 uStack00000034;
  undefined4 in_stack_00000038;
  undefined4 in_stack_0000003c;
  undefined4 in_stack_00000050;
  undefined4 in_stack_00000054;
  undefined4 in_stack_00000068;
  undefined4 in_stack_0000006c;
  undefined4 auStack_8c [4];
  undefined4 local_7c;
  undefined4 local_78 [6];
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_30;
  undefined4 local_2c;
  
  auStack_8c[1] = *(undefined4 *)(param_1 + 8);
  auStack_8c[2] = *(undefined4 *)(param_1 + 0xc);
  local_60 = in_stack_00000038;
  local_5c = in_stack_0000003c;
  local_48 = in_stack_00000050;
  local_44 = in_stack_00000054;
  local_30 = in_stack_00000068;
  iVar7 = 4;
  iVar4 = 0;
  uVar5 = 0;
  local_78[0] = param_3;
  local_78[1] = param_4;
  auStack_8c[3] = *(undefined4 *)(param_1 + 0x10);
  local_7c = *(undefined4 *)(param_1 + 0x14);
  local_2c = in_stack_0000006c;
  do {
    if ((int)uVar5 < param_2) {
      *(byte *)(*(int *)(param_1 + 0x28) + 0x15c) =
           (byte)(1 << (uVar5 & 0x3f)) | *(byte *)(*(int *)(param_1 + 0x28) + 0x15c);
      uVar1 = *(undefined4 *)((int)local_78 + iVar4);
      iVar2 = iVar4 + 0x10 + *(int *)(param_1 + 0x28);
      *(undefined4 *)(iVar2 + 0x10) = *(undefined4 *)((int)local_78 + iVar4 + 4);
      *(undefined4 *)(iVar2 + 0xc) = uVar1;
    }
    else {
      *(byte *)(*(int *)(param_1 + 0x28) + 0x15c) =
           *(byte *)(*(int *)(param_1 + 0x28) + 0x15c) & ~(byte)(1 << (uVar5 & 0x3f));
    }
    uVar5 = uVar5 + 1;
    iVar4 = iVar4 + 0x18;
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  uStack00000020 = param_3;
  uStack00000024 = param_4;
  uStack00000028 = param_5;
  uStack0000002c = param_6;
  uStack00000030 = param_7;
  uStack00000034 = param_8;
  iVar4 = FUN_00194834(auStack_8c[param_2],*(undefined4 *)(param_1 + 0x28));
  if (iVar4 == 0) {
    uVar1 = ((int (*)())FUN_000f4a5c)(param_1);
    iVar4 = FUN_001275a0(param_1,0xc,uVar1,0);
    piVar3 = *(int **)(iVar4 + 0x18);
    if (*piVar3 == 0) {
      piVar3 = (int *)FUN_0019423c(piVar3,0);
    }
    else {
      if (piVar3[1] == 0) {
        *(undefined4 *)piVar3[2] = 0;
        piVar3[1] = 1;
      }
      piVar3 = (int *)piVar3[2];
    }
    iVar7 = *piVar3;
    iVar8 = 4;
    uVar5 = 0;
    iVar6 = iVar7 + 0x10;
    iVar2 = 0;
    do {
      if ((int)uVar5 < param_2) {
        *(byte *)(iVar7 + 0x15c) = (byte)(1 << (uVar5 & 0x3f)) | *(byte *)(iVar7 + 0x15c);
        uVar1 = *(undefined4 *)((int)local_78 + iVar2);
        *(undefined4 *)(iVar6 + 0x10) = *(undefined4 *)((int)local_78 + iVar2 + 4);
        *(undefined4 *)(iVar6 + 0xc) = uVar1;
      }
      else {
        *(byte *)(iVar7 + 0x15c) = *(byte *)(iVar7 + 0x15c) & ~(byte)(1 << (uVar5 & 0x3f));
      }
      uVar5 = uVar5 + 1;
      iVar2 = iVar2 + 0x18;
      iVar6 = iVar6 + 0x18;
      iVar8 = iVar8 + -1;
    } while (iVar8 != 0);
    ((int (*)())FUN_000f4ddc)(param_1,param_2);
  }
  else {
    iVar4 = *(int *)(iVar4 + 0x8c);
  }
  return iVar4;
}

/* FUN_000f645c @ 0xf645c (376 bytes) */
int FUN_000f645c(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  undefined4 uStack0000001c;
  undefined4 uStack00000020;
  undefined4 uStack00000024;
  undefined4 uStack00000028;
  undefined4 uStack0000002c;
  undefined4 uStack00000030;
  undefined4 uStack00000034;
  
  uStack0000001c = param_2;
  uStack00000020 = param_3;
  uStack00000024 = param_4;
  uStack00000028 = param_5;
  uStack0000002c = param_6;
  uStack00000030 = param_7;
  uStack00000034 = param_8;
  ((int (*)())FUN_000f6248)(param_1,4,param_2,param_3,param_4,param_5,param_6,param_7);
  return;
}

/* FUN_000f65d4 @ 0xf65d4 (396 bytes) */
int FUN_000f65d4(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  undefined4 uStack0000001c;
  undefined4 uStack00000020;
  undefined4 uStack00000024;
  undefined4 uStack00000028;
  undefined4 uStack0000002c;
  undefined4 uStack00000030;
  undefined4 uStack00000034;
  
  uStack0000001c = param_2;
  uStack00000020 = param_3;
  uStack00000024 = param_4;
  uStack00000028 = param_5;
  uStack0000002c = param_6;
  uStack00000030 = param_7;
  uStack00000034 = param_8;
  ((int (*)())FUN_000f6248)(param_1,3,param_2,param_3,param_4,param_5,param_6,param_7);
  return;
}

/* FUN_000f6760 @ 0xf6760 (352 bytes) */
int FUN_000f6760(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  undefined4 uStack0000001c;
  undefined4 uStack00000020;
  undefined4 uStack00000024;
  undefined4 uStack00000028;
  undefined4 uStack0000002c;
  undefined4 uStack00000030;
  undefined4 uStack00000034;
  
  uStack0000001c = param_2;
  uStack00000020 = param_3;
  uStack00000024 = param_4;
  uStack00000028 = param_5;
  uStack0000002c = param_6;
  uStack00000030 = param_7;
  uStack00000034 = param_8;
  ((int (*)())FUN_000f6248)(param_1,2,param_2,param_3,param_4,param_5,param_6,param_7);
  return;
}

/* FUN_000f68c0 @ 0xf68c0 (324 bytes) */
int FUN_000f68c0(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  undefined4 uStack0000001c;
  undefined4 uStack00000020;
  undefined4 uStack00000024;
  undefined4 uStack00000028;
  undefined4 uStack0000002c;
  undefined4 uStack00000030;
  
  uStack0000001c = param_2;
  uStack00000020 = param_3;
  uStack00000024 = param_4;
  uStack00000028 = param_5;
  uStack0000002c = param_6;
  uStack00000030 = param_7;
  ((int (*)())FUN_000f6248)(param_1,1,param_2,param_3,param_4,param_5,param_6,param_7);
  return;
}

/* FUN_000f6a04 @ 0xf6a04 (752 bytes) */
int FUN_000f6a04(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  int *piVar5;
  undefined4 *puVar6;
  char *pcVar7;
  int iVar8;
  int iVar9;
  undefined4 *puVar10;
  uint uVar11;
  undefined4 uVar12;
  uint uVar13;
  uint *puVar14;
  undefined4 uStack00000020;
  int local_98;
  int local_94 [30];
  
  puVar10 = (undefined4 *)0x0;
  iVar9 = *(int *)(param_1 + 8);
  uStack00000020 = param_3;
  iVar2 = (**(code **)(**(int **)(iVar9 + 0x30c) + 0xe8))
                    (*(int **)(iVar9 + 0x30c),param_2,&local_98,param_3,iVar9);
  if (iVar2 != 0) {
    ((int (*)())FUN_000f4a24)(param_2,local_94);
    iVar2 = *(int *)(param_1 + 0x3ac);
    uVar13 = 0;
    uVar11 = *(uint *)(*(int *)(iVar2 + 0x18) + 4);
    if (0 < (int)uVar11) {
      while( true ) {
        puVar14 = *(uint **)(iVar2 + 0x18);
        if (uVar13 < *puVar14) {
          uVar3 = puVar14[1];
          if (uVar3 <= uVar13) {
            _memset((void *)(uVar3 * 4 + puVar14[2]),0,(uVar13 - uVar3) * 4 + 4);
            puVar14[1] = uVar13 + 1;
          }
          piVar5 = (int *)(uVar13 * 4 + puVar14[2]);
        }
        else {
          piVar5 = (int *)FUN_0019423c(puVar14,uVar13);
        }
        puVar10 = (undefined4 *)*piVar5;
        if (puVar10[0x4b] == local_98) {
          pcVar7 = (char *)&STACKARG(0x20);
          puVar6 = puVar10 + 4;
          iVar8 = 0;
          iVar2 = 4;
          while ((*pcVar7 == '\x04' ||
                 ((puVar6[3] == *(int *)((int)local_94 + iVar8) &&
                  (puVar6[4] == *(int *)((int)local_94 + iVar8 + 4)))))) {
            iVar2 = iVar2 + -1;
            iVar8 = iVar8 + 0x18;
            puVar6 = puVar6 + 6;
            pcVar7 = pcVar7 + 1;
            if (iVar2 == 0) {
              if (puVar10 != (undefined4 *)0x0) {
                return puVar10;
              }
              goto LAB_000f6b68;
            }
          }
        }
        uVar13 = uVar13 + 1;
        if (uVar11 == uVar13) break;
        iVar2 = *(int *)(param_1 + 0x3ac);
      }
    }
LAB_000f6b68:
    if ((*(uint *)(param_1 + 0x30) & 8) == 0) {
      uVar12 = *(undefined4 *)(param_1 + 0x3ac);
      uVar4 = ((int (*)())FUN_000f4a5c)(uVar12);
      iVar2 = FUN_001275a0(uVar12,0x33,uVar4,0);
      piVar5 = *(int **)(iVar2 + 0x18);
      if (*piVar5 == 0) {
        piVar5 = (int *)FUN_0019423c(piVar5,0);
      }
      else {
        if (piVar5[1] == 0) {
          *(undefined4 *)piVar5[2] = 0;
          piVar5[1] = 1;
        }
        piVar5 = (int *)piVar5[2];
      }
      puVar10 = (undefined4 *)*piVar5;
    }
    else {
      uVar4 = *(undefined4 *)(iVar9 + 0x374);
      puVar6 = (undefined4 *)FUN_00193e18(uVar4,0x168);
      *puVar6 = uVar4;
      puVar10 = puVar6 + 1;
      FUN_00109938(puVar10,*(undefined4 *)(param_1 + 8));
      uVar4 = ((int (*)())FUN_000f4a5c)(*(undefined4 *)(param_1 + 0x3ac));
      puVar6[0x26] = uVar4;
      puVar6[0x27] = 0x33;
      (**(code **)(**(int **)(param_1 + 0x3a0) + 0xc))(*(int **)(param_1 + 0x3a0),puVar10);
    }
    puVar10[0x4b] = local_98;
    puVar14 = *(uint **)(*(int *)(param_1 + 0x3ac) + 0x18);
    uVar11 = puVar14[1];
    if (uVar11 < *puVar14) {
      _memset((void *)(uVar11 * 4 + puVar14[2]),0,4);
      piVar5 = (int *)(uVar11 * 4 + puVar14[2]);
      puVar14[1] = uVar11 + 1;
    }
    else {
      piVar5 = (int *)FUN_0019423c(puVar14,uVar11);
    }
    *piVar5 = (int)puVar10;
    iVar9 = 4;
    uVar11 = 0;
    puVar6 = puVar10 + 4;
    iVar2 = 0;
    do {
      puVar1 = (undefined4 *)((int)local_94 + iVar2);
      uVar4 = *(undefined4 *)((int)local_94 + iVar2 + 4);
      iVar2 = iVar2 + 0x18;
      puVar6[3] = *puVar1;
      puVar6[4] = uVar4;
      uVar13 = uVar11 & 0x3f;
      uVar11 = uVar11 + 1;
      puVar6 = puVar6 + 6;
      *(byte *)(puVar10 + 0x57) = (byte)(1 << uVar13) | *(byte *)(puVar10 + 0x57);
      iVar9 = iVar9 + -1;
    } while (iVar9 != 0);
  }
  return puVar10;
}

/* FUN_000f6d14 @ 0xf6d14 (2568 bytes) */
int FUN_000f6d14(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  undefined4 param_1;
  int param_2;
  undefined4 param_3;
  int param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  undefined1 uVar1;
  undefined1 uVar2;
  uint uVar3;
  int iVar4;
  int **ppiVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  int *piVar9;
  uint *puVar10;
  int iVar11;
  uint *puVar12;
  undefined4 uVar13;
  bool bVar14;
  int iVar15;
  undefined4 uStack00000020;
  int iStack00000024;
  undefined4 uStack00000028;
  undefined4 uStack0000002c;
  undefined4 uStack00000030;
  undefined4 uStack00000034;
  int in_stack_0000003c;
  undefined4 in_stack_00000040;
  int in_stack_00000054;
  undefined4 in_stack_00000058;
  int in_stack_0000006c;
  undefined4 in_stack_00000070;
  int local_288;
  undefined1 auStack_284 [4];
  undefined4 local_280;
  undefined4 local_27c;
  undefined4 local_278;
  int *local_274;
  int *local_270 [11];
  undefined4 local_244;
  undefined4 local_240;
  undefined4 local_23c;
  undefined4 local_238;
  undefined4 local_234;
  undefined4 local_230;
  undefined4 local_22c;
  undefined4 local_228;
  undefined4 local_224;
  undefined4 local_220;
  undefined4 local_21c;
  undefined4 local_218;
  undefined4 local_214;
  undefined4 local_210;
  undefined4 local_20c;
  undefined4 local_208;
  undefined4 local_204;
  undefined4 local_200;
  undefined4 local_1fc;
  undefined4 local_1f8;
  undefined4 local_1f4;
  undefined4 local_1f0;
  undefined4 local_1ec;
  undefined4 local_1e8;
  undefined4 local_1e4;
  undefined4 local_1e0;
  undefined4 local_1dc;
  undefined4 local_1d8;
  undefined4 local_1d4;
  undefined4 local_1d0;
  undefined4 local_1cc;
  undefined4 local_1c8;
  undefined4 local_1c4;
  undefined4 local_1c0;
  undefined4 local_1bc;
  undefined4 local_1b8;
  undefined4 local_1b4;
  undefined4 local_1b0;
  undefined4 local_1ac;
  undefined4 local_1a8;
  undefined4 local_1a4;
  undefined4 local_1a0;
  undefined4 local_19c;
  undefined4 local_198;
  undefined4 local_194;
  undefined4 local_190;
  undefined4 local_18c;
  undefined4 local_188;
  undefined4 local_184;
  undefined4 local_180;
  undefined4 local_17c;
  undefined4 local_178;
  undefined4 local_174;
  undefined4 local_170;
  undefined4 local_16c;
  undefined4 local_168;
  undefined4 local_164;
  undefined4 local_160;
  undefined4 local_15c;
  undefined4 local_158;
  undefined4 local_154;
  undefined4 local_150;
  undefined4 local_14c;
  undefined4 local_148;
  undefined4 local_144;
  undefined4 local_140;
  undefined4 local_13c;
  undefined4 local_138;
  undefined4 local_134;
  undefined4 local_130;
  undefined4 local_12c;
  undefined4 local_128;
  undefined4 local_124;
  undefined4 local_120;
  undefined4 local_11c;
  undefined4 local_118;
  undefined4 local_114;
  undefined4 local_110;
  undefined4 local_10c;
  undefined4 local_108;
  undefined4 local_104[0];
  undefined4 local_100;
  undefined4 local_fc;
  undefined4 local_f8;
  undefined4 local_f4;
  undefined4 local_f0;
  undefined4 local_ec;
  undefined4 local_e8;
  undefined4 local_e4;
  undefined4 local_e0;
  undefined4 local_dc;
  undefined4 local_d8;
  undefined4 local_d4;
  undefined4 local_d0;
  undefined4 local_cc;
  undefined4 local_c8;
  undefined4 local_c4;
  undefined4 local_c0;
  undefined4 local_bc;
  undefined4 local_b8[0];
  undefined4 local_b4;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88[0];
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  
  uVar13 = *(undefined4 *)(param_2 + 8);
  uStack00000020 = param_3;
  iStack00000024 = param_4;
  uStack00000028 = param_5;
  uStack0000002c = param_6;
  uStack00000030 = param_7;
  uStack00000034 = param_8;
  if ((((param_4 == 2) && (in_stack_0000003c == 2)) && (in_stack_00000054 == 2)) &&
     (in_stack_0000006c == 2)) {
    iVar15 = 4;
    ppiVar5 = local_270 + 7;
    do {
      *ppiVar5 = (int *)0x7ffffffe;
      ppiVar5 = ppiVar5 + 1;
      iVar15 = iVar15 + -1;
    } while (iVar15 != 0);
    local_270[8] = (int *)in_stack_00000040;
    local_270[9] = (int *)in_stack_00000058;
    local_270[10] = (int *)in_stack_00000070;
    local_270[7] = (int *)param_5;
    iVar15 = ((int (*)())FUN_000f6a04)(param_2,local_270 + 7,DAT_001aa868);
    if (iVar15 != 0) {
      if ((*(uint *)(param_2 + 0x30) & 8) == 0) {
        FUN_001046c8(param_1,uStack00000020,*(undefined4 *)(iVar15 + 0x8c));
      }
      else {
        FUN_00106004(param_1,uStack00000020,iVar15,*(uint *)(param_2 + 0x30) >> 7 & 1,uVar13);
      }
      iVar6 = FUN_001054ec(iVar15,0);
      local_288 = *(int *)(iVar6 + 0x10);
      if (local_288 != DAT_001aa860) {
        iVar6 = 0;
        do {
          iVar7 = FUN_001054ec(param_1,uStack00000020);
          if (*(byte *)(iVar6 + iVar7 + 0x10) < 4) {
            iVar7 = FUN_001054ec(param_1,uStack00000020);
            uVar3 = (uint)*(byte *)(iVar6 + iVar7 + 0x10);
            auStack_284[uVar3 - 4] = 0;
            *(byte *)(iVar15 + uVar3 + 0xc) =
                 (byte)(1 << (uVar3 & 0x3f)) | *(byte *)(iVar15 + uVar3 + 0xc);
          }
          bVar14 = iVar6 != 3;
          iVar6 = iVar6 + 1;
        } while (bVar14);
        *(int *)(iVar15 + 0x9c) = local_288;
      }
      return;
    }
  }
  piVar9 = &STACKARG(0x24);
  local_27c = DAT_001aa868;
  local_270[0] = &STACKARG(0x3c);
  ppiVar5 = &local_274;
  iVar15 = 0;
  local_270[1] = &STACKARG(0x54);
  local_270[2] = &STACKARG(0x6c);
  local_270[6] = (int *)PTR_DAT_001e8b70;
  local_274 = piVar9;
  local_270[3] = (int *)PTR_DAT_001e8b70;
  local_270[4] = (int *)PTR_DAT_001e8b70;
  local_270[5] = (int *)PTR_DAT_001e8b70;
  iVar6 = 0;
LAB_000f6f18:
  do {
    iVar7 = iVar6;
    *(char *)((int)&local_27c + iVar15) = (char)iVar7;
    iVar6 = iVar7 + 1;
    local_270[iVar7 + 3] = piVar9;
LAB_000f6f58:
    iVar4 = 4 - iVar15;
    do {
      iVar11 = iVar15;
      iVar15 = iVar11 + 1;
      ppiVar5 = ppiVar5 + 1;
      iVar4 = iVar4 + -1;
      if (iVar4 == 0) {
        local_278 = DAT_001aa868;
        if (0 < iVar6) {
          do {
            iVar11 = iVar7 + 1;
            iVar4 = 0;
            iVar15 = 0;
            ppiVar5 = local_270 + 4;
            if (iVar7 < 0) {
              iVar11 = 1;
            }
            while (iVar11 = iVar11 + -1, iVar11 != 0) {
              puVar12 = (uint *)ppiVar5[-1];
              puVar10 = (uint *)*ppiVar5;
              uVar3 = *puVar12;
              if (uVar3 == *puVar10) {
                if (uVar3 == 2) {
                  bVar14 = (float)puVar12[1] < (float)puVar10[1];
                }
                else {
                  bVar14 = puVar12[1] < puVar10[1];
                }
              }
              else {
                bVar14 = uVar3 < *puVar10;
              }
              if (bVar14) {
                uVar2 = *(undefined1 *)((int)&local_278 + iVar4);
                uVar1 = *(undefined1 *)((int)&local_278 + iVar15 + 1);
                *ppiVar5 = (int *)puVar12;
                *(undefined1 *)((int)&local_278 + iVar15 + 1) = uVar2;
                ppiVar5[-1] = (int *)puVar10;
                *(undefined1 *)((int)&local_278 + iVar4) = uVar1;
              }
              iVar4 = iVar4 + 1;
              ppiVar5 = ppiVar5 + 1;
              iVar15 = iVar15 + 1;
            }
            bVar14 = 0 < iVar7;
            iVar7 = iVar7 + -1;
          } while (bVar14);
          iVar7 = 0;
          iVar15 = iVar6;
          do {
            auStack_284[*(byte *)((int)&local_278 + iVar7)] = (char)iVar7;
            iVar7 = iVar7 + 1;
            iVar15 = iVar15 + -1;
          } while (iVar15 != 0);
        }
        iVar15 = 0;
        iVar7 = 4;
        do {
          *(undefined1 *)((int)&local_280 + iVar15) =
               auStack_284[*(byte *)((int)&local_27c + iVar15)];
          iVar15 = iVar15 + 1;
          iVar7 = iVar7 + -1;
        } while (iVar7 != 0);
        uVar3 = *(uint *)(param_2 + 0x30);
        if ((uVar3 & 8) == 0) {
          if (iVar6 == 2) {
            local_244 = *local_270[3];
            local_240 = local_270[3][1];
            local_23c = local_270[3][2];
            local_238 = local_270[3][3];
            local_230 = local_270[3][5];
            local_234 = local_270[3][4];
            local_7c = *local_270[4];
            local_78 = local_270[4][1];
            local_74 = local_270[4][2];
            local_70 = local_270[4][3];
            local_68 = local_270[4][5];
            local_6c = local_270[4][4];
            uVar13 = ((int (*)())FUN_000f6760)(*(undefined4 *)(param_2 + 0x3ac));
          }
          else if (iVar6 < 3) {
            if (iVar6 == 1) {
              local_22c = *local_270[3];
              local_228 = local_270[3][1];
              local_224 = local_270[3][2];
              local_220 = local_270[3][3];
              local_218 = local_270[3][5];
              local_21c = local_270[3][4];
              uVar13 = ((int (*)())FUN_000f68c0)(*(undefined4 *)(param_2 + 0x3ac));
            }
            else {
LAB_000f73f0:
              uVar13 = 0;
            }
          }
          else if (iVar6 == 3) {
            local_94 = *local_270[3];
            local_90 = local_270[3][1];
            local_8c = local_270[3][2];
            local_88[0] = local_270[3][3];
            local_80 = local_270[3][5];
            local_84 = local_270[3][4];
            local_a8 = local_270[4][1];
            local_a4 = local_270[4][2];
            local_a0 = local_270[4][3];
            local_ac = *local_270[4];
            local_98 = local_270[4][5];
            local_9c = local_270[4][4];
            local_bc = local_270[5][2];
            local_b8[0] = local_270[5][3];
            local_c4 = *local_270[5];
            local_c0 = local_270[5][1];
            local_b0 = local_270[5][5];
            local_b4 = local_270[5][4];
            uVar13 = ((int (*)())FUN_000f65d4)(*(undefined4 *)(param_2 + 0x3ac));
          }
          else {
            if (iVar6 != 4) goto LAB_000f73f0;
            local_dc = *local_270[3];
            local_d8 = local_270[3][1];
            local_d4 = local_270[3][2];
            local_d0 = local_270[3][3];
            local_c8 = local_270[3][5];
            local_cc = local_270[3][4];
            local_f0 = local_270[4][1];
            local_ec = local_270[4][2];
            local_e8 = local_270[4][3];
            local_f4 = *local_270[4];
            local_e0 = local_270[4][5];
            local_e4 = local_270[4][4];
            local_104[0] = local_270[5][2];
            local_100 = local_270[5][3];
            local_10c = *local_270[5];
            local_108 = local_270[5][1];
            local_f8 = local_270[5][5];
            local_fc = local_270[5][4];
            local_1b4 = *local_270[6];
            local_1b0 = local_270[6][1];
            local_1ac = local_270[6][2];
            local_1a8 = local_270[6][3];
            local_1a0 = local_270[6][5];
            local_1a4 = local_270[6][4];
            uVar13 = ((int (*)())FUN_000f645c)(*(undefined4 *)(param_2 + 0x3ac));
          }
          FUN_001046c8(param_1,uStack00000020,uVar13);
          goto LAB_000f76c8;
        }
        if (iVar6 == 2) {
          local_14c = local_270[3][2];
          local_154 = *local_270[3];
          local_150 = local_270[3][1];
          local_148 = local_270[3][3];
          local_140 = local_270[3][5];
          local_144 = local_270[3][4];
          local_16c = *local_270[4];
          local_168 = local_270[4][1];
          local_164 = local_270[4][2];
          local_160 = local_270[4][3];
          local_158 = local_270[4][5];
          local_15c = local_270[4][4];
          uVar8 = ((int (*)())FUN_000f554c)(*(undefined4 *)(param_2 + 0x3ac));
          uVar3 = *(uint *)(param_2 + 0x30);
        }
        else if (iVar6 < 3) {
          if (iVar6 == 1) {
            local_134 = local_270[3][2];
            local_13c = *local_270[3];
            local_138 = local_270[3][1];
            local_130 = local_270[3][3];
            local_128 = local_270[3][5];
            local_12c = local_270[3][4];
            uVar8 = ((int (*)())FUN_000f56ac)(*(undefined4 *)(param_2 + 0x3ac));
            uVar3 = *(uint *)(param_2 + 0x30);
          }
          else {
LAB_000f70d4:
            uVar8 = 0;
          }
        }
        else if (iVar6 == 3) {
          local_17c = local_270[3][2];
          local_184 = *local_270[3];
          local_180 = local_270[3][1];
          local_178 = local_270[3][3];
          local_170 = local_270[3][5];
          local_174 = local_270[3][4];
          local_198 = local_270[4][1];
          local_19c = *local_270[4];
          local_194 = local_270[4][2];
          local_190 = local_270[4][3];
          local_188 = local_270[4][5];
          local_18c = local_270[4][4];
          local_124 = *local_270[5];
          local_11c = local_270[5][2];
          local_118 = local_270[5][3];
          local_120 = local_270[5][1];
          local_110 = local_270[5][5];
          local_114 = local_270[5][4];
          uVar8 = ((int (*)())FUN_000f53c0)(*(undefined4 *)(param_2 + 0x3ac));
          uVar3 = *(uint *)(param_2 + 0x30);
        }
        else {
          if (iVar6 != 4) goto LAB_000f70d4;
          local_1c4 = local_270[3][2];
          local_1cc = *local_270[3];
          local_1c8 = local_270[3][1];
          local_1c0 = local_270[3][3];
          local_1b8 = local_270[3][5];
          local_1bc = local_270[3][4];
          local_1e0 = local_270[4][1];
          local_1e4 = *local_270[4];
          local_1dc = local_270[4][2];
          local_1d8 = local_270[4][3];
          local_1d0 = local_270[4][5];
          local_1d4 = local_270[4][4];
          local_1fc = *local_270[5];
          local_1f4 = local_270[5][2];
          local_1f0 = local_270[5][3];
          local_1f8 = local_270[5][1];
          local_1e8 = local_270[5][5];
          local_1ec = local_270[5][4];
          local_214 = *local_270[6];
          local_210 = local_270[6][1];
          local_20c = local_270[6][2];
          local_208 = local_270[6][3];
          local_200 = local_270[6][5];
          local_204 = local_270[6][4];
          uVar8 = ((int (*)())FUN_000f5248)(*(undefined4 *)(param_2 + 0x3ac));
          uVar3 = *(uint *)(param_2 + 0x30);
        }
        FUN_00106004(param_1,uStack00000020,uVar8,uVar3 >> 7 & 1,uVar13);
LAB_000f76c8:
        iVar15 = FUN_001054ec(param_1,uStack00000020);
        *(undefined4 *)(iVar15 + 0x10) = local_280;
        return;
      }
    } while (iVar6 < 0);
    if (iVar6 != 0) {
      piVar9 = *ppiVar5;
      iVar4 = 0;
      while ((*local_270[iVar4 + 3] != *piVar9 || (local_270[iVar4 + 3][1] != piVar9[1]))) {
        iVar4 = iVar4 + 1;
        if (iVar6 < iVar4) goto LAB_000f6f58;
        if (iVar4 == iVar6) goto LAB_000f6f18;
      }
      *(char *)((int)&local_27c + iVar11 + 1) = (char)iVar4;
      goto LAB_000f6f58;
    }
    piVar9 = *ppiVar5;
  } while( true );
}

/* FUN_000f771c @ 0xf771c (340 bytes) */
int FUN_000f771c()
{
  ((int (*)())FUN_000f6d14)();
  return;
}

/* FUN_000f7870 @ 0xf7870 (340 bytes) */
int FUN_000f7870()
{
  ((int (*)())FUN_000f6d14)();
  return;
}

/* FUN_000f79c4 @ 0xf79c4 (332 bytes) */
int FUN_000f79c4()
{
  ((int (*)())FUN_000f6d14)();
  return;
}

