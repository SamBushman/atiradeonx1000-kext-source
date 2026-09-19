#include "decls.h"

/* FUN_000f2d18 @ 0xf2d18 (144 bytes) */
int FUN_000f2d18(param_1, param_2)
  uint param_1;
  uint param_2;
{
  uint uVar1;
  uint uVar2;
  
  if (((((param_1 >> 0x18 == 4) || (param_2 >> 0x18 == 4)) || (param_1 >> 0x18 == param_2 >> 0x18))
      && ((((uVar2 = param_1 >> 0x10 & 0xff, uVar2 == 4 ||
            (uVar1 = param_2 >> 0x10 & 0xff, uVar1 == 4)) || (uVar2 == uVar1)) &&
          (((uVar2 = param_1 >> 8 & 0xff, uVar2 == 4 || (uVar1 = param_2 >> 8 & 0xff, uVar1 == 4))
           || (uVar2 == uVar1)))))) &&
     ((((param_1 & 0xff) == 4 || ((param_2 & 0xff) == 4)) || ((param_1 & 0xff) == (param_2 & 0xff)))
     )) {
    return 1;
  }
  return 0;
}

/* FUN_000f2da8 @ 0xf2da8 (112 bytes) */
int FUN_000f2da8(param_1, param_2)
  uint param_1;
  uint param_2;
{
  uint uVar1;
  
  if (((((param_2 >> 0x18 == 4) || (param_2 >> 0x18 == param_1 >> 0x18)) &&
       ((uVar1 = param_2 >> 0x10 & 0xff, uVar1 == 4 || (uVar1 == (param_1 >> 0x10 & 0xff))))) &&
      ((uVar1 = param_2 >> 8 & 0xff, uVar1 == 4 || (uVar1 == (param_1 >> 8 & 0xff))))) &&
     (((param_2 & 0xff) == 4 || ((param_2 & 0xff) == (param_1 & 0xff))))) {
    return 1;
  }
  return 0;
}

/* FUN_000f2e18 @ 0xf2e18 (56 bytes) */
int FUN_000f2e18(param_1)
  uint param_1;
{
  if ((((param_1 >> 0x18 == 0) || ((param_1 >> 0x10 & 0xff) == 0)) || ((param_1 >> 8 & 0xff) == 0))
     && ((param_1 & 0xff) == 0)) {
    return 0;
  }
  return 1;
}

/* FUN_000f2e50 @ 0xf2e50 (72 bytes) */
int FUN_000f2e50(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  char *pcVar1;
  int iVar2;
  undefined4 uStack0000001c;
  
  uStack0000001c = param_2;
  iVar2 = 4;
  pcVar1 = (char *)&STACKARG(0x1c);
  do {
    if ((byte)(*pcVar1 - 2U) < 2) {
      *pcVar1 = '\x01';
    }
    pcVar1 = pcVar1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  *param_1 = uStack0000001c;
  return param_1;
}

/* FUN_000f2e98 @ 0xf2e98 (144 bytes) */
int FUN_000f2e98(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  bool bVar1;
  bool bVar2;
  char *pcVar3;
  char *pcVar4;
  int iVar5;
  undefined4 uStack0000001c;
  
  pcVar3 = (char *)&STACKARG(0x1c);
  iVar5 = 4;
  uStack0000001c = param_2;
  bVar1 = false;
  bVar2 = false;
  pcVar4 = pcVar3;
  do {
    if (*pcVar4 == '\x02') {
      bVar2 = true;
    }
    else if (*pcVar4 == '\x01') {
      bVar1 = true;
    }
    pcVar4 = pcVar4 + 1;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  if ((bVar1) && (bVar2)) {
    iVar5 = (int)pcVar4 - (int)pcVar3;
    do {
      if (*pcVar3 == '\x01') {
        *pcVar3 = '\x03';
      }
      pcVar3 = pcVar3 + 1;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
  }
  *param_1 = uStack0000001c;
  return param_1;
}

/* FUN_000f2f28 @ 0xf2f28 (92 bytes) */
int FUN_000f2f28(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined4 uStack0000001c;
  undefined4 uStack00000020;
  
  uStack0000001c = param_2;
  iVar3 = 4;
  uStack00000020 = param_3;
  pcVar1 = (char *)&STACKARG(0x1c);
  pcVar2 = (char *)&STACKARG(0x20);
  do {
    if ((1 < (byte)(*pcVar1 - 2U)) && (*pcVar2 == '\x01')) {
      *pcVar1 = '\x01';
    }
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  *param_1 = uStack0000001c;
  return param_1;
}

/* FUN_000f2f84 @ 0xf2f84 (92 bytes) */
int FUN_000f2f84(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined4 uStack0000001c;
  undefined4 uStack00000020;
  
  uStack0000001c = param_2;
  iVar3 = 4;
  uStack00000020 = param_3;
  pcVar1 = (char *)&STACKARG(0x1c);
  pcVar2 = (char *)&STACKARG(0x20);
  do {
    if ((1 < (byte)(*pcVar1 - 2U)) && (*pcVar2 == '\0')) {
      *pcVar1 = '\0';
    }
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  *param_1 = uStack0000001c;
  return param_1;
}

/* FUN_000f2fe0 @ 0xf2fe0 (76 bytes) */
int FUN_000f2fe0(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined4 uStack0000001c;
  undefined4 uStack00000020;
  
  uStack0000001c = param_2;
  iVar3 = 4;
  uStack00000020 = param_3;
  pcVar1 = (char *)&STACKARG(0x1c);
  pcVar2 = (char *)&STACKARG(0x20);
  do {
    if (*pcVar1 == '\x04') {
      *pcVar1 = *pcVar2;
    }
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  *param_1 = uStack0000001c;
  return param_1;
}

/* FUN_000f302c @ 0xf302c (96 bytes) */
int FUN_000f302c(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  int iVar4;
  undefined4 uStack0000001c;
  undefined4 uStack00000020;
  
  uStack0000001c = param_2;
  iVar4 = 4;
  uStack00000020 = param_3;
  pcVar3 = (char *)&STACKARG(0x1c);
  pcVar2 = (char *)&STACKARG(0x20);
  do {
    cVar1 = *pcVar2;
    if (((cVar1 == *pcVar3) && (cVar1 != '\x03')) && (cVar1 != '\x02')) {
      *pcVar3 = '\x01';
    }
    pcVar3 = pcVar3 + 1;
    pcVar2 = pcVar2 + 1;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  *param_1 = uStack0000001c;
  return param_1;
}

/* FUN_000f308c @ 0xf308c (72 bytes) */
int FUN_000f308c(param_1)
  undefined4 param_1;
{
  uint uVar1;
  byte *pbVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  undefined4 uStack00000018;
  
  uStack00000018 = param_1;
  iVar5 = 4;
  pbVar2 = (byte *)&STACKARG(0x18);
  uVar3 = 0xffffffff;
  while (((uVar1 = (uint)*pbVar2, uVar4 = uVar3, uVar1 == 4 || (uVar4 = uVar1, (int)uVar3 < 0)) ||
         (uVar1 == uVar3))) {
    pbVar2 = pbVar2 + 1;
    iVar5 = iVar5 + -1;
    uVar3 = uVar4;
    if (iVar5 == 0) {
      return uVar4;
    }
  }
  return 0xffffffff;
}

/* FUN_000f30d4 @ 0xf30d4 (52 bytes) */
int FUN_000f30d4(param_1)
  undefined4 param_1;
{
  char *pcVar1;
  int iVar2;
  int iVar3;
  undefined4 uStack00000018;
  
  uStack00000018 = param_1;
  iVar3 = 4;
  iVar2 = 0;
  pcVar1 = (char *)&STACKARG(0x18);
  do {
    if (*pcVar1 != '\x01') {
      return iVar2;
    }
    iVar2 = iVar2 + 1;
    pcVar1 = pcVar1 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return -1;
}

/* FUN_000f3108 @ 0xf3108 (52 bytes) */
int FUN_000f3108(param_1)
  undefined4 param_1;
{
  char *pcVar1;
  int iVar2;
  int iVar3;
  undefined4 uStack00000018;
  
  uStack00000018 = param_1;
  iVar3 = 4;
  iVar2 = 0;
  pcVar1 = (char *)&STACKARG(0x18);
  do {
    if (*pcVar1 == '\x01') {
      return iVar2;
    }
    iVar2 = iVar2 + 1;
    pcVar1 = pcVar1 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return -1;
}

/* FUN_000f313c @ 0xf313c (24 bytes) */
int FUN_000f313c(param_1, param_2)
  int param_1;
  int param_2;
{
  return -(*(byte *)(param_2 + param_1 + 0x9c) ^ 1) >> 0x1f;
}

/* FUN_000f3154 @ 0xf3154 (60 bytes) */
int FUN_000f3154(param_1)
  int param_1;
{
  if ((((*(char *)(param_1 + 0x9c) != '\x01') && (*(char *)(param_1 + 0x9d) != '\x01')) &&
      (*(char *)(param_1 + 0x9e) != '\x01')) && (*(char *)(param_1 + 0x9f) != '\x01')) {
    return 0;
  }
  return 1;
}

/* FUN_000f3190 @ 0xf3190 (88 bytes) */
int FUN_000f3190(param_1)
  uint param_1;
{
  uint uVar1;
  
  if ((((param_1 >> 0x18 == 4) || (param_1 >> 0x18 == 0)) &&
      ((uVar1 = param_1 >> 0x10 & 0xff, uVar1 == 4 || (uVar1 == 1)))) &&
     (((uVar1 = param_1 >> 8 & 0xff, uVar1 == 4 || (uVar1 == 2)) && ((param_1 - 3 & 0xff) < 2)))) {
    return 1;
  }
  return 0;
}

/* FUN_000f31e8 @ 0xf31e8 (16 bytes) */
int FUN_000f31e8(param_1, param_2)
  int param_1;
  int param_2;
{
  ((int (*)())FUN_000f3190)(*(undefined4 *)(param_2 * 0x18 + param_1 + 0x9c));
  return;
}

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
      uVar7 = (uint)(&STACKARG(0x1c))[iVar8];
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

/* FUN_000f3bc4 @ 0xf3bc4 (108 bytes) */
int FUN_000f3bc4()
{
  int iVar1;
  bool bVar2;
  byte in_cr7;
  
  if ((bool)(in_cr7 >> 1 & 1)) {
    iVar1 = FUN_001054ec();
    bVar2 = *(int *)(iVar1 + 0x10) == _UNK_001aa84c;
  }
  else {
    iVar1 = FUN_001054ec();
    bVar2 = *(int *)(iVar1 + 0x10) == _UNK_001aa848;
  }
  return 1 - (uint)bVar2;
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

/* FUN_000f4a70 @ 0xf4a70 (20 bytes) */
int FUN_000f4a70(param_1)
  uint param_1;
{
  return param_1 >> 0x10 < 0x15;
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

/* FUN_000f4bc8 @ 0xf4bc8 (32 bytes) */
bool FUN_000f4bc8(float param_1,float param_2)

{
  return param_2 < param_1;
}

/* FUN_000f4be8 @ 0xf4be8 (92 bytes) */
int FUN_000f4be8(param_1, param_2)
  uint *param_1;
  int param_2;
{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (0 < param_2) {
    iVar3 = 0;
    iVar2 = 0;
    do {
      uVar1 = *param_1;
      param_1 = param_1 + 1;
      if (uVar1 == 0) {
        iVar2 = iVar2 + 0x20;
      }
      else {
        iVar4 = 0x20;
        do {
          if ((uVar1 & 1) != 0) {
            return iVar2;
          }
          uVar1 = uVar1 >> 1;
          iVar2 = iVar2 + 1;
          iVar4 = iVar4 + -1;
        } while (iVar4 != 0);
      }
      iVar3 = iVar3 + 1;
    } while (param_2 != iVar3);
  }
  return -1;
}

/* FUN_000f4c44 @ 0xf4c44 (4 bytes) */
int FUN_000f4c44()
{
  return;
}

/* FUN_000f4c48 @ 0xf4c48 (268 bytes) */
int FUN_000f4c48(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  bool bVar5;
  int iVar6;
  
  iVar4 = 0;
  uVar2 = 3;
  iVar6 = 4;
  do {
    if (((int)*(char *)(param_1 + 0x15c) >> (uVar2 & 0x3f) & 1U) == 0) {
      if (((int)*(char *)(param_2 + 0x15c) >> (uVar2 & 0x3f) & 1U) != 0) {
        return 1;
      }
    }
    else {
      if (((int)*(char *)(param_2 + 0x15c) >> (uVar2 & 0x3f) & 1U) == 0) {
        return 0xffffffff;
      }
      iVar4 = iVar4 + 1;
    }
    uVar2 = uVar2 - 1;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  if (0 < iVar4) {
    iVar6 = 0;
    do {
      iVar1 = iVar6 * 0x18 + 0x10;
      iVar3 = param_2 + iVar1;
      iVar1 = param_1 + iVar1;
      uVar2 = *(uint *)(iVar1 + 0xc);
      if (uVar2 != *(uint *)(iVar3 + 0xc)) {
        bVar5 = uVar2 < *(uint *)(iVar3 + 0xc);
LAB_000f4d20:
        if (!bVar5) {
          return 1;
        }
        return 0xffffffff;
      }
      if (*(uint *)(iVar1 + 0x10) != *(uint *)(iVar3 + 0x10)) {
        if (uVar2 == 2) {
          bVar5 = *(float *)(iVar1 + 0x10) < *(float *)(iVar3 + 0x10);
        }
        else {
          bVar5 = *(uint *)(iVar1 + 0x10) < *(uint *)(iVar3 + 0x10);
        }
        goto LAB_000f4d20;
      }
      iVar4 = iVar4 + -1;
      iVar6 = iVar6 + 1;
    } while (iVar4 != 0);
  }
  return 0;
}

/* FUN_000f4d54 @ 0xf4d54 (44 bytes) */
int FUN_000f4d54(param_1)
  int param_1;
{
  uint uVar1;
  int iVar2;
  
  uVar1 = 0;
  iVar2 = 4;
  do {
    if (((int)*(char *)(param_1 + 0x15c) >> (uVar1 & 0x3f) & 1U) == 0) {
      return;
    }
    uVar1 = uVar1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
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

