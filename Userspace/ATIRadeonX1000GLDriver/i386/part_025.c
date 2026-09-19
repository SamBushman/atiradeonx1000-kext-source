#include "decls.h"

/* FUN_000f5610 @ 0xf5610 (97 bytes) */
int FUN_000f5610(param_1, param_2)
  undefined4 param_1;
  uint param_2;
{
  uint uVar1;
  
  uVar1 = param_2;
  if ((byte)param_2 < 4) {
    uVar1 = (uint)*(byte *)((int)&param_1 + (param_2 & 0xff));
  }
  if ((byte)(param_2 >> 8) < 4) {
    uVar1 = uVar1 & 0xff;
  }
  if ((byte)(param_2 >> 0x10) < 4) {
    uVar1 = uVar1 & 0xff00ffff;
  }
  if ((byte)(param_2 >> 0x18) < 4) {
    uVar1 = uVar1 & 0xffffff;
  }
  return uVar1;
}

/* FUN_000f5672 @ 0xf5672 (59 bytes) */
int FUN_000f5672()
{
  char cVar1;
  char cVar2;
  char cVar3;
  char *pcVar4;
  
  cVar3 = '\x04';
  pcVar4 = &STACKARG(0x4);
  while (((cVar1 = *pcVar4, cVar2 = cVar3, cVar1 == '\x04' || (cVar2 = cVar1, cVar3 == '\x04')) ||
         (cVar2 = cVar3, cVar1 == cVar3))) {
    cVar3 = cVar2;
    pcVar4 = pcVar4 + 1;
    if (&STACKARG(0x8) == pcVar4) {
      return 1;
    }
  }
  return 0;
}

/* FUN_000f56ae @ 0xf56ae (52 bytes) */
int FUN_000f56ae(param_1)
  undefined4 param_1;
{
  int iVar1;
  char *pcVar2;
  
  ((int (*)())FUN_000f5672)(param_1);
  iVar1 = 0;
  pcVar2 = (char *)&param_1;
  do {
    if (*pcVar2 != '\x04') {
      return (uint)*(byte *)((int)&param_1 + iVar1);
    }
    iVar1 = iVar1 + 1;
    pcVar2 = pcVar2 + 1;
  } while (iVar1 != 4);
  return 0xffffffff;
}

/* FUN_000f56e2 @ 0xf56e2 (14 bytes) */
int FUN_000f56e2(param_1)
  uint param_1;
{
  return param_1 < 4;
}

/* FUN_000f56f0 @ 0xf56f0 (110 bytes) */
int FUN_000f56f0(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  char cVar1;
  char cVar2;
  
  if ((((((char)param_1 == '\x04') || ((char)param_2 == '\x04')) || ((char)param_1 == (char)param_2)
       ) && ((((cVar2 = (char)((uint)param_1 >> 8), cVar2 == '\x04' ||
               (cVar1 = (char)((uint)param_2 >> 8), cVar1 == '\x04')) || (cVar2 == cVar1)) &&
             (((cVar2 = (char)((uint)param_1 >> 0x10), cVar2 == '\x04' ||
               (cVar1 = (char)((uint)param_2 >> 0x10), cVar1 == '\x04')) || (cVar2 == cVar1)))))) &&
     (((cVar2 = (char)((uint)param_1 >> 0x18), cVar2 == '\x04' ||
       (cVar1 = (char)((uint)param_2 >> 0x18), cVar1 == '\x04')) || (cVar2 == cVar1)))) {
    return 1;
  }
  return 0;
}

/* FUN_000f575e @ 0xf575e (85 bytes) */
int FUN_000f575e(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  char cVar1;
  
  if ((((((char)param_2 == '\x04') || ((char)param_2 == (char)param_1)) &&
       ((cVar1 = (char)((uint)param_2 >> 8), cVar1 == '\x04' ||
        (cVar1 == (char)((uint)param_1 >> 8))))) &&
      ((cVar1 = (char)((uint)param_2 >> 0x10), cVar1 == '\x04' ||
       (cVar1 == (char)((uint)param_1 >> 0x10))))) &&
     ((cVar1 = (char)((uint)param_2 >> 0x18), cVar1 == '\x04' ||
      (cVar1 == (char)((uint)param_1 >> 0x18))))) {
    return 1;
  }
  return 0;
}

/* FUN_000f57b4 @ 0xf57b4 (53 bytes) */
int FUN_000f57b4(param_1)
  undefined4 param_1;
{
  if (((((char)param_1 == '\0') || ((char)((uint)param_1 >> 8) == '\0')) ||
      ((char)((uint)param_1 >> 0x10) == '\0')) && ((char)((uint)param_1 >> 0x18) == '\0')) {
    return 0;
  }
  return 1;
}

/* FUN_000f57ea @ 0xf57ea (35 bytes) */
int FUN_000f57ea(param_1)
  undefined4 param_1;
{
  char *pcVar1;
  
  pcVar1 = (char *)&param_1;
  do {
    if ((byte)(*pcVar1 - 2U) < 2) {
      *pcVar1 = '\x01';
    }
    pcVar1 = pcVar1 + 1;
  } while (pcVar1 != &STACKARG(0x8));
  return param_1;
}

/* FUN_000f580e @ 0xf580e (83 bytes) */
int FUN_000f580e(param_1)
  undefined4 param_1;
{
  bool bVar1;
  bool bVar2;
  char *pcVar3;
  char *pcVar4;
  
  bVar1 = false;
  bVar2 = false;
  pcVar4 = (char *)&param_1;
  do {
    if (*pcVar4 == '\x02') {
      bVar2 = true;
    }
    else if (*pcVar4 == '\x01') {
      bVar1 = true;
    }
    pcVar4 = pcVar4 + 1;
  } while (pcVar4 != &STACKARG(0x8));
  if ((bVar1) && (bVar2)) {
    pcVar3 = (char *)&param_1;
    do {
      if (*pcVar3 == '\x01') {
        *pcVar3 = '\x03';
      }
      pcVar3 = pcVar3 + 1;
    } while (pcVar4 != pcVar3);
  }
  return param_1;
}

/* FUN_000f5862 @ 0xf5862 (47 bytes) */
int FUN_000f5862(param_1)
  undefined4 param_1;
{
  char *pcVar1;
  char *pcVar2;
  
  pcVar2 = (char *)&param_1;
  pcVar1 = &STACKARG(0x8);
  do {
    if ((1 < (byte)(*pcVar2 - 2U)) && (*pcVar1 == '\x01')) {
      *pcVar2 = '\x01';
    }
    pcVar2 = pcVar2 + 1;
    pcVar1 = pcVar1 + 1;
  } while (pcVar2 != &STACKARG(0x8));
  return param_1;
}

/* FUN_000f5892 @ 0xf5892 (45 bytes) */
int FUN_000f5892(param_1)
  undefined4 param_1;
{
  char *pcVar1;
  char *pcVar2;
  
  pcVar2 = (char *)&param_1;
  pcVar1 = &STACKARG(0x8);
  do {
    if ((1 < (byte)(*pcVar2 - 2U)) && (*pcVar1 == '\0')) {
      *pcVar2 = '\0';
    }
    pcVar2 = pcVar2 + 1;
    pcVar1 = pcVar1 + 1;
  } while (pcVar2 != &STACKARG(0x8));
  return param_1;
}

/* FUN_000f58c0 @ 0xf58c0 (40 bytes) */
int FUN_000f58c0(param_1)
  undefined4 param_1;
{
  char *pcVar1;
  char *pcVar2;
  
  pcVar2 = (char *)&param_1;
  pcVar1 = &STACKARG(0x8);
  do {
    if (*pcVar2 == '\x04') {
      *pcVar2 = *pcVar1;
    }
    pcVar2 = pcVar2 + 1;
    pcVar1 = pcVar1 + 1;
  } while (pcVar2 != &STACKARG(0x8));
  return param_1;
}

/* FUN_000f58e8 @ 0xf58e8 (48 bytes) */
int FUN_000f58e8(param_1)
  undefined4 param_1;
{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  
  pcVar3 = (char *)&param_1;
  pcVar2 = &STACKARG(0x8);
  do {
    cVar1 = *pcVar3;
    if (((cVar1 == *pcVar2) && (cVar1 != '\x03')) && (cVar1 != '\x02')) {
      *pcVar3 = '\x01';
    }
    pcVar3 = pcVar3 + 1;
    pcVar2 = pcVar2 + 1;
  } while (pcVar3 != &STACKARG(0x8));
  return param_1;
}

/* FUN_000f5918 @ 0xf5918 (56 bytes) */
int FUN_000f5918()
{
  uint uVar1;
  byte *pbVar2;
  uint uVar3;
  uint uVar4;
  
  pbVar2 = &STACKARG(0x4);
  uVar3 = 0xffffffff;
  while (((uVar1 = (uint)*pbVar2, uVar4 = uVar3, *pbVar2 == 4 || (uVar4 = uVar1, (int)uVar3 < 0)) ||
         (uVar1 == uVar3))) {
    pbVar2 = pbVar2 + 1;
    uVar3 = uVar4;
    if (pbVar2 == &STACKARG(0x8)) {
      return uVar4;
    }
  }
  return 0xffffffff;
}

/* FUN_000f5950 @ 0xf5950 (31 bytes) */
int FUN_000f5950()
{
  int iVar1;
  char *pcVar2;
  
  iVar1 = 0;
  pcVar2 = &STACKARG(0x4);
  do {
    if (*pcVar2 != '\x01') {
      return iVar1;
    }
    iVar1 = iVar1 + 1;
    pcVar2 = pcVar2 + 1;
  } while (iVar1 != 4);
  return -1;
}

/* FUN_000f5970 @ 0xf5970 (31 bytes) */
int FUN_000f5970()
{
  int iVar1;
  char *pcVar2;
  
  iVar1 = 0;
  pcVar2 = &STACKARG(0x4);
  do {
    if (*pcVar2 == '\x01') {
      return iVar1;
    }
    iVar1 = iVar1 + 1;
    pcVar2 = pcVar2 + 1;
  } while (iVar1 != 4);
  return -1;
}

/* FUN_000f5990 @ 0xf5990 (25 bytes) */
int FUN_000f5990(param_1, param_2)
  int param_1;
  int param_2;
{
  return *(char *)(param_2 + 0x9c + param_1) != '\x01';
}

/* FUN_000f59aa @ 0xf59aa (53 bytes) */
int FUN_000f59aa(param_1)
  int param_1;
{
  if ((((*(char *)(param_1 + 0x9c) != '\x01') && (*(char *)(param_1 + 0x9d) != '\x01')) &&
      (*(char *)(param_1 + 0x9e) != '\x01')) && (*(char *)(param_1 + 0x9f) != '\x01')) {
    return 0;
  }
  return 1;
}

/* FUN_000f59e0 @ 0xf59e0 (62 bytes) */
int FUN_000f59e0(param_1)
  undefined4 param_1;
{
  char cVar1;
  
  if (((((char)param_1 == '\x04') || ((char)param_1 == '\0')) &&
      ((cVar1 = (char)((uint)param_1 >> 8), cVar1 == '\x04' || (cVar1 == '\x01')))) &&
     (((cVar1 = (char)((uint)param_1 >> 0x10), cVar1 == '\x04' || (cVar1 == '\x02')) &&
      ((byte)((char)((uint)param_1 >> 0x18) - 3U) < 2)))) {
    return 1;
  }
  return 0;
}

/* FUN_000f5a1e @ 0xf5a1e (37 bytes) */
int FUN_000f5a1e(param_1, param_2)
  int param_1;
  int param_2;
{
  undefined1 uVar1;
  
  uVar1 = ((int (*)())FUN_000f59e0)(*(undefined4 *)(param_2 * 0x18 + param_1 + 0x9c));
  return uVar1;
}

/* FUN_000f5a44 @ 0xf5a44 (168 bytes) */
int FUN_000f5a44(param_1, param_2)
  uint param_1;
  undefined4 param_2;
{
  undefined1 uVar1;
  ushort uVar2;
  uint uVar3;
  
  uVar1 = 1;
  if ((char)param_2 != '\0') {
    uVar1 = (undefined1)param_1;
  }
  if ((char)((uint)param_2 >> 8) == '\0') {
    uVar2 = CONCAT11(1,uVar1);
  }
  else {
    uVar2 = CONCAT11((char)(param_1 >> 8),uVar1);
  }
  if ((char)((uint)param_2 >> 0x10) == '\0') {
    uVar3 = uVar2 | 0x10000;
  }
  else {
    uVar3 = (uint)uVar2 | (param_1 >> 0x10 & 0xff) << 0x10;
  }
  if ((char)((uint)param_2 >> 0x18) != '\0') {
    return uVar3 | param_1 & 0xff000000;
  }
  return uVar3 | 0x1000000;
}

/* FUN_000f5aec @ 0xf5aec (80 bytes) */
int FUN_000f5aec(param_1)
  undefined4 param_1;
{
  uint uVar1;
  
  uVar1 = DAT_001c652c;
  if ((byte)param_1 < 4) {
    uVar1 = DAT_001c652c & 0xffffff00;
  }
  if ((byte)((uint)param_1 >> 8) < 4) {
    uVar1 = CONCAT22((short)(uVar1 >> 0x10),(ushort)(byte)uVar1);
  }
  if ((byte)((uint)param_1 >> 0x10) < 4) {
    uVar1 = uVar1 & 0xff00ffff;
  }
  if ((byte)((uint)param_1 >> 0x18) < 4) {
    uVar1 = uVar1 & 0xffffff;
  }
  return uVar1;
}

/* FUN_000f5b3c @ 0xf5b3c (90 bytes) */
int FUN_000f5b3c(param_1)
  uint param_1;
{
  undefined4 local_8;
  
  local_8 = DAT_001c652c;
  if ((byte)param_1 < 4) {
    *(undefined1 *)((int)&local_8 + (param_1 & 0xff)) = 0;
  }
  if ((byte)(param_1 >> 8) < 4) {
    *(undefined1 *)((int)&local_8 + (param_1 >> 8 & 0xff)) = 0;
  }
  if ((byte)(param_1 >> 0x10) < 4) {
    *(undefined1 *)((int)&local_8 + (param_1 >> 0x10 & 0xff)) = 0;
  }
  if ((byte)(param_1 >> 0x18) < 4) {
    *(undefined1 *)((int)&local_8 + (param_1 >> 0x18)) = 0;
  }
  return local_8;
}

/* FUN_000f5b96 @ 0xf5b96 (70 bytes) */
int FUN_000f5b96(param_1, param_2)
  int param_1;
  int param_2;
{
  if (param_2 == '\0') {
    param_1 = 4;
  }
  return param_1;
}

/* FUN_000f5bdc @ 0xf5bdc (83 bytes) */
int FUN_000f5bdc(param_1)
  uint param_1;
{
  undefined4 local_8;
  
  local_8 = 0;
  if ((byte)param_1 < 4) {
    *(undefined1 *)((int)&local_8 + (param_1 & 0xff)) = 1;
  }
  if ((byte)(param_1 >> 8) < 4) {
    *(undefined1 *)((int)&local_8 + (param_1 >> 8 & 0xff)) = 1;
  }
  if ((byte)(param_1 >> 0x10) < 4) {
    *(undefined1 *)((int)&local_8 + (param_1 >> 0x10 & 0xff)) = 1;
  }
  if ((byte)(param_1 >> 0x18) < 4) {
    *(undefined1 *)((int)&local_8 + (param_1 >> 0x18)) = 1;
  }
  return local_8;
}

/* FUN_000f5c30 @ 0xf5c30 (63 bytes) */
int FUN_000f5c30(param_1)
  undefined4 param_1;
{
  char cVar1;
  char *pcVar2;
  int iVar3;
  
  iVar3 = 0;
  pcVar2 = (char *)&param_1;
  do {
    if (*pcVar2 != '\x04') {
      pcVar2 = (char *)&param_1;
      cVar1 = (char)param_1;
      while( true ) {
        if (cVar1 == '\x04') {
          *pcVar2 = *(char *)((int)&param_1 + iVar3);
        }
        pcVar2 = pcVar2 + 1;
        if (&STACKARG(0x8) == pcVar2) break;
        cVar1 = *pcVar2;
      }
      return param_1;
    }
    iVar3 = iVar3 + 1;
    pcVar2 = pcVar2 + 1;
  } while (iVar3 != 4);
  return param_1;
}

/* FUN_000f5c70 @ 0xf5c70 (263 bytes) */
int FUN_000f5c70(param_1)
  uint param_1;
{
  bool bVar1;
  uint uVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  int iVar6;
  int iVar7;
  byte *pbVar8;
  bool bVar9;
  byte bVar10;
  uint uVar11;
  
  uVar2 = param_1;
  uVar11 = param_1 & 0xff;
  if ((byte)param_1 == 4) {
    bVar9 = true;
    iVar6 = 1;
    do {
      iVar7 = iVar6;
      if (*(byte *)((int)&param_1 + iVar6) != 4) {
        uVar11 = (uint)*(byte *)((int)&param_1 + iVar6);
        iVar7 = iVar6 + 1;
        if (iVar7 < 4) {
          pbVar8 = (byte *)((int)&param_1 + iVar6 + 1);
          do {
            if ((*pbVar8 != 4) && (uVar11 != *pbVar8)) {
              bVar9 = false;
            }
            iVar7 = iVar7 + 1;
            pbVar8 = pbVar8 + 1;
          } while (iVar7 != 4);
        }
      }
      iVar6 = iVar7 + 1;
    } while (iVar6 < 4);
  }
  else {
    bVar1 = false;
    bVar9 = true;
    pbVar8 = (byte *)&param_1;
    do {
      if (*pbVar8 == 4) {
        bVar1 = true;
      }
      else if (uVar11 != *pbVar8) {
        bVar9 = false;
      }
      pbVar8 = pbVar8 + 1;
    } while (pbVar8 != &STACKARG(0x8));
    if (!bVar1) {
      return param_1;
    }
  }
  if (!bVar9) {
    bVar10 = 0;
    if ((byte)param_1 != 4) {
      bVar10 = (byte)param_1;
    }
    cVar3 = '\x01';
    if ((*(unsigned char *)((unsigned char *)&(param_1) + 1)) != '\x04') {
      cVar3 = (*(unsigned char *)((unsigned char *)&(param_1) + 1));
    }
    (*(unsigned char *)((unsigned char *)&(param_1) + 2)) = SUB41(uVar2,2);
    cVar4 = '\x02';
    if ((*(unsigned char *)((unsigned char *)&(param_1) + 2)) != '\x04') {
      cVar4 = (*(unsigned char *)((unsigned char *)&(param_1) + 2));
    }
    (*(unsigned char *)((unsigned char *)&(param_1) + 3)) = SUB41(uVar2,3);
    cVar5 = '\x03';
    if ((*(unsigned char *)((unsigned char *)&(param_1) + 3)) != '\x04') {
      cVar5 = (*(unsigned char *)((unsigned char *)&(param_1) + 3));
    }
    param_1 = CONCAT13(cVar5,CONCAT12(cVar4,CONCAT11(cVar3,bVar10)));
    return param_1;
  }
  return (DAT_001c650c)[uVar11];
}

/* FUN_000f5d78 @ 0xf5d78 (122 bytes) */
int FUN_000f5d78(param_1)
  int *param_1;
{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 local_10;
  
  iVar1 = FUN_0010b0f4(param_1,0);
  local_10 = *(undefined4 *)(iVar1 + 0x10);
  iVar1 = 0;
  do {
    if (*(char *)((int)&local_10 + iVar1) == '\x01') {
      for (iVar3 = 1; iVar2 = (**(code **)(*param_1 + 0x14))(param_1), iVar3 <= iVar2;
          iVar3 = iVar3 + 1) {
        (**(code **)(*param_1 + 0x88))(param_1,iVar3,iVar1,4);
      }
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 != 4);
  return;
}

/* FUN_000f5df2 @ 0xf5df2 (58 bytes) */
int FUN_000f5df2()
{
  byte *pbVar1;
  undefined4 local_c;
  
  local_c = DAT_001c652c;
  pbVar1 = &STACKARG(0x4);
  do {
    if (*pbVar1 != 4) {
      *(undefined1 *)((int)&local_c + (uint)*pbVar1) = 0;
    }
    pbVar1 = pbVar1 + 1;
  } while (&STACKARG(0x8) != pbVar1);
  return local_c;
}

/* FUN_000f5e2c @ 0xf5e2c (58 bytes) */
int FUN_000f5e2c()
{
  int iVar1;
  char *pcVar2;
  undefined4 local_c;
  
  local_c = DAT_001c652c;
  iVar1 = 0;
  pcVar2 = &STACKARG(0x4);
  do {
    if (*pcVar2 != '\x04') {
      *(undefined1 *)((int)&local_c + iVar1) = 0;
    }
    iVar1 = iVar1 + 1;
    pcVar2 = pcVar2 + 1;
  } while (iVar1 != 4);
  return local_c;
}

/* FUN_000f5e66 @ 0xf5e66 (57 bytes) */
int FUN_000f5e66()
{
  int iVar1;
  char *pcVar2;
  undefined4 local_c;
  
  local_c = DAT_001c6530;
  iVar1 = 0;
  pcVar2 = &STACKARG(0x4);
  do {
    if (*pcVar2 == '\0') {
      *(char *)((int)&local_c + iVar1) = (char)iVar1;
    }
    iVar1 = iVar1 + 1;
    pcVar2 = pcVar2 + 1;
  } while (iVar1 != 4);
  return local_c;
}

/* FUN_000f5ea0 @ 0xf5ea0 (62 bytes) */
int FUN_000f5ea0()
{
  int iVar1;
  char *pcVar2;
  undefined1 uStack_d;
  undefined4 local_c;
  
  local_c = DAT_001c652c;
  iVar1 = 1;
  pcVar2 = &STACKARG(0x4);
  do {
    if (*pcVar2 != '\0') {
      (&uStack_d)[iVar1] = 0;
    }
    iVar1 = iVar1 + 1;
    pcVar2 = pcVar2 + 1;
  } while (iVar1 != 5);
  return local_c;
}

/* FUN_000f5ede @ 0xf5ede (74 bytes) */
int FUN_000f5ede(param_1)
  int param_1;
{
  if (param_1 == DAT_001c6550) {
    return 0;
  }
  if (param_1 != DAT_001c654c) {
    if (param_1 == DAT_001c6548) {
      return 2;
    }
    return (uint)(param_1 == DAT_001c6544) * 4 + -1;
  }
  return 1;
}

/* FUN_000f5f28 @ 0xf5f28 (54 bytes) */
int FUN_000f5f28(param_1)
  int param_1;
{
  if ((((param_1 != DAT_001c6550) && (param_1 != DAT_001c654c)) && (param_1 != DAT_001c6548)) &&
     (param_1 != DAT_001c6544)) {
    return 0;
  }
  return 1;
}

/* FUN_000f5f5e @ 0xf5f5e (28 bytes) */
int FUN_000f5f5e(param_1)
  int param_1;
{
  undefined1 uVar1;
  
  uVar1 = ((int (*)())FUN_000f5f28)(*(undefined4 *)(param_1 + 0x9c));
  return uVar1;
}

/* FUN_000f5f7a @ 0xf5f7a (111 bytes) */
int FUN_000f5f7a(param_1, param_2)
  uint param_1;
  int param_2;
{
  undefined4 local_8;
  
  local_8 = 0;
  if ((0 < param_2) && ((byte)param_1 < 4)) {
    *(undefined1 *)((int)&local_8 + (param_1 & 0xff)) = 1;
  }
  if ((1 < param_2) && ((byte)(param_1 >> 8) < 4)) {
    *(undefined1 *)((int)&local_8 + (param_1 >> 8 & 0xff)) = 1;
  }
  if ((2 < param_2) && ((byte)(param_1 >> 0x10) < 4)) {
    *(undefined1 *)((int)&local_8 + (param_1 >> 0x10 & 0xff)) = 1;
  }
  if ((3 < param_2) && ((byte)(param_1 >> 0x18) < 4)) {
    *(undefined1 *)((int)&local_8 + (param_1 >> 0x18)) = 1;
  }
  return local_8;
}

/* FUN_000f5fea @ 0xf5fea (72 bytes) */
int FUN_000f5fea(param_1)
  undefined4 param_1;
{
  return CONCAT13((char)((uint)param_1 >> 0x18) != '\x01',
                  CONCAT12((char)((uint)param_1 >> 0x10) != '\x01',
                           CONCAT11((char)((uint)param_1 >> 8) != '\x01',(char)param_1 != '\x01')));
}

/* FUN_000f6032 @ 0xf6032 (124 bytes) */
int FUN_000f6032(param_1, param_2)
  undefined4 param_1;
  uint param_2;
{
  undefined1 uVar1;
  undefined1 uVar3;
  uint uVar2;
  
  uVar1 = 0;
  if ((char)param_1 == '\x01') {
    uVar1 = (undefined1)param_2;
  }
  if ((char)((uint)param_1 >> 8) == '\x01') {
    uVar3 = (undefined1)(param_2 >> 8);
  }
  else {
    uVar3 = 0;
  }
  if ((char)((uint)param_1 >> 0x10) == '\x01') {
    uVar2 = param_2 >> 0x10;
  }
  else {
    uVar2 = 0;
  }
  uVar2 = (uVar2 & 0xff) << 0x10;
  if ((char)((uint)param_1 >> 0x18) != '\x01') {
    return CONCAT11(uVar3,uVar1) | uVar2;
  }
  return CONCAT11(uVar3,uVar1) | uVar2 | param_2 & 0xff000000;
}

/* FUN_000f60ae @ 0xf60ae (69 bytes) */
int FUN_000f60ae(param_1)
  undefined4 param_1;
{
  bool bVar1;
  uint uVar2;
  
  bVar1 = (byte)param_1 < 4;
  uVar2 = (uint)bVar1;
  if ((byte)((uint)param_1 >> 8) < 4) {
    uVar2 = (uint)CONCAT11(1,bVar1);
  }
  if ((byte)((uint)param_1 >> 0x10) < 4) {
    uVar2 = uVar2 | 0x10000;
  }
  if ((byte)((uint)param_1 >> 0x18) < 4) {
    uVar2 = uVar2 | 0x1000000;
  }
  return uVar2;
}

/* FUN_000f60f4 @ 0xf60f4 (59 bytes) */
int FUN_000f60f4(param_1)
  undefined4 param_1;
{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  iVar2 = 0;
  do {
    iVar1 = FUN_0010b0f4(param_1,0);
    if (*(char *)(iVar2 + 0x10 + iVar1) != '\x01') {
      iVar3 = iVar3 + 1;
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 != 4);
  return iVar3;
}

/* FUN_000f6130 @ 0xf6130 (59 bytes) */
int FUN_000f6130(param_1)
  undefined4 param_1;
{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = FUN_0010b0f4(param_1,0);
  uVar1 = *(undefined4 *)(iVar2 + 0x10);
  if ((((char)uVar1 != '\0') && ((char)((uint)uVar1 >> 8) != '\0')) &&
     ((char)((uint)uVar1 >> 0x10) != '\0')) {
    return 0;
  }
  return 1;
}

/* FUN_000f616c @ 0xf616c (37 bytes) */
int FUN_000f616c(param_1)
  undefined4 param_1;
{
  int iVar1;
  
  iVar1 = FUN_0010b0f4(param_1,0);
  return *(char *)(iVar1 + 0x13) == '\0';
}

/* FUN_000f6192 @ 0xf6192 (64 bytes) */
int FUN_000f6192(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  int iVar1;
  byte bStack_11;
  undefined4 local_10;
  
  iVar1 = FUN_0010b0f4(param_1,param_2);
  local_10 = *(undefined4 *)(iVar1 + 0x10);
  iVar1 = 1;
  do {
    if ((&bStack_11)[iVar1] < 3) {
      return 1;
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 != 5);
  return 0;
}

/* FUN_000f61d2 @ 0xf61d2 (64 bytes) */
int FUN_000f61d2(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  int iVar1;
  char cStack_11;
  undefined4 local_10;
  
  iVar1 = FUN_0010b0f4(param_1,param_2);
  local_10 = *(undefined4 *)(iVar1 + 0x10);
  iVar1 = 1;
  do {
    if ((&cStack_11)[iVar1] == '\x03') {
      return 1;
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 != 5);
  return 0;
}

/* FUN_000f6212 @ 0xf6212 (92 bytes) */
int FUN_000f6212(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  int iVar1;
  
  if (param_2 == 0) {
    iVar1 = FUN_0010b0f4(param_1,0);
    return *(int *)(iVar1 + 0x10) != DAT_001c6540;
  }
  iVar1 = FUN_0010b0f4(param_1,param_2);
  return *(int *)(iVar1 + 0x10) != DAT_001c653c;
}

/* FUN_000f626e @ 0xf626e (186 bytes) */
int FUN_000f626e(param_1, param_2, param_3, param_4)
  int *param_1;
  int param_2;
  int param_3;
  int param_4;
{
  byte *pbVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  char *pcVar5;
  undefined4 uStack_28;
  undefined4 local_24;
  undefined4 uStack_20;
  
  (**(code **)(*param_1 + 0x14))(param_1);
  local_24 = DAT_001c6538;
  if (0 < param_2) {
    iVar2 = FUN_0010b180(param_1,param_2);
    if (iVar2 == 0) {
      iVar2 = *(int *)(param_1[param_2 * 6 + 0x23] + 4);
    }
    else {
      iVar2 = *(int *)(iVar2 + 0x98);
    }
    if ((iVar2 == 0x3b) || (iVar2 == 0x42)) {
      return (undefined *)0x1;
    }
  }
  uVar3 = FUN_00119314(param_1[0x22],param_1,param_3);
  switch(uVar3) {
  case 0:
    break;
  case 1:
    if (param_2 == 2) {
      return (undefined *)0x1;
    }
    if (param_2 != 3) {
      if (param_2 == 1) {
        local_24 = (undefined *)CONCAT13(1,(uint3)local_24);
        return local_24;
      }
      return local_24;
    }
    goto code_r0x000f65a9;
  case 2:
    return (undefined *)0x1000101;
  case 3:
    if (param_2 != 3) {
      return (undefined *)0x101;
    }
code_r0x000f65a9:
    (*(unsigned int *)((unsigned char *)&(local_24) + 0)) = CONCAT12(1,(undefined2)local_24);
    local_24 = (undefined *)(uint)(uint3)local_24;
    return local_24;
  case 4:
code_r0x000f6392:
    local_24 = ((unsigned char *)0x00010101);
    return local_24;
  case 5:
  case 8:
  case 10:
    return (undefined *)0x1010101;
  case 6:
    if (param_2 != 1) {
      return (undefined *)0x1010101;
    }
    iVar2 = 1;
    do {
      iVar4 = FUN_0010b0f4(param_1,0);
      uStack_20 = *(undefined4 *)(iVar4 + 0x10);
      if (*(char *)((int)&local_24 + iVar2 + 3) != '\x01') {
        pbVar1 = (byte *)((int)&uStack_28 + iVar2 + 3);
        *pbVar1 = *pbVar1 | 1;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 != 5);
    return local_24;
  case 7:
    if (param_2 < 3) goto code_r0x000f6392;
    goto code_r0x000f62ed;
  case 9:
    if (param_1[0x4d] < 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = *(int *)(*(int *)(param_3 + 0x78) + 4 + param_1[0x4d] * 0xc);
    }
    if ((*(uint *)(iVar2 * 8 + 0x1ef324) & 1) != 0) {
      (*(unsigned char *)((unsigned char *)&(local_24) + 0)) = 1;
    }
    local_24 = (undefined *)(uint)(byte)local_24;
    iVar2 = param_1[0x22];
    if ((((*(int *)(iVar2 + 8) == 0x101) || (*(int *)(iVar2 + 8) == 0x100)) ||
        (*(int *)(iVar2 + 8) == 0x102)) || (*(int *)(iVar2 + 8) == 0x6e)) goto code_r0x000f62ed;
    if (*(int *)(iVar2 + 8) == 0x75) {
      return (undefined *)0x1000101;
    }
    if (*(int *)(iVar2 + 8) == 0x76) {
      return (undefined *)0x1000101;
    }
    if (*(int *)(iVar2 + 8) == 0xae) {
      return (undefined *)0x1000101;
    }
    if (((*(int *)(iVar2 + 8) != 0x9e) && (*(int *)(iVar2 + 8) != 0x9f)) &&
       ((*(int *)(iVar2 + 8) != 0xa0 && (*(int *)(iVar2 + 8) != 0xa1)))) {
      return local_24;
    }
    break;
  case 0xb:
    return (undefined *)0x1;
  case 0xc:
    iVar2 = FUN_0010b0f4(param_1,param_2);
    uStack_28 = *(undefined4 *)(iVar2 + 0x10);
    iVar2 = 1;
    pcVar5 = &param_4;
    pbVar1 = (byte *)&local_24;
    do {
      if ((*pcVar5 == '\0') && (pbVar1[-4] != 4)) {
        *pbVar1 = *pbVar1 | 1;
      }
      iVar2 = iVar2 + 1;
      pcVar5 = pcVar5 + 1;
      pbVar1 = pbVar1 + 1;
    } while (iVar2 != 5);
    return local_24;
  case 0xd:
    if (param_2 == 2) {
      return (undefined *)0x1;
    }
    return (undefined *)0x1010101;
  case 0xe:
    if (param_2 != 1) {
      if (param_2 == 2) {
        return (undefined *)0x1;
      }
      if (param_2 == 3) {
        return (undefined *)0x1010101;
      }
      return local_24;
    }
    break;
  case 0xf:
    if (*(int *)(param_1[0x22] + 8) == 0xb4) {
      if (param_2 == 2) goto code_r0x000f65a9;
      if (param_2 < 3) {
        if (param_2 == 1) {
          return (undefined *)0x101;
        }
        return local_24;
      }
      if (param_2 == 3) goto code_r0x000f62ed;
      if (param_2 != 4) {
        return local_24;
      }
    }
  default:
    local_24 = ((unsigned char *)0x00010101);
code_r0x000f62ed:
    local_24 = (undefined *)CONCAT13(1,(uint3)local_24);
    return local_24;
  }
  local_24 = (undefined *)(uint)(param_4 == '\0');
  return local_24;
}

/* FUN_000f65d0 @ 0xf65d0 (123 bytes) */
int FUN_000f65d0(param_1, param_2, param_3, param_4)
  int *param_1;
  int param_2;
  undefined4 param_3;
  int param_4;
{
  byte *pbVar1;
  byte bVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  char cStack_29;
  undefined4 uStack_28;
  undefined4 local_24;
  undefined4 local_20;
  
  (**(code **)(*param_1 + 0x14))(param_1);
  iVar3 = FUN_0010b0f4(param_1,param_2);
  local_20 = *(uint *)(iVar3 + 0x10);
  local_24 = DAT_001c6538;
  uVar4 = FUN_00119314(param_1[0x22],param_1,param_4);
  switch(uVar4) {
  case 0:
    iVar3 = FUN_0010b0f4(param_1,0);
    uStack_28 = ((int (*)())FUN_000f5a44)(*(undefined4 *)(iVar3 + 0x10),param_3);
    iVar3 = 1;
    do {
      if ((&cStack_29)[iVar3] != '\x01') {
        pbVar1 = (byte *)((int)&local_24 + (uint)*(byte *)((int)&local_24 + iVar3 + 3));
        *pbVar1 = *pbVar1 | 1;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 != 5);
    break;
  case 1:
    if (param_2 == 2) goto code_r0x000f66a3;
    if (param_2 != 3) {
      if (param_2 != 1) {
        return local_24;
      }
      goto code_r0x000f6800;
    }
    goto code_r0x000f67e9;
  case 2:
code_r0x000f6766:
    *(undefined1 *)((int)&local_24 + (local_20 & 0xff)) = 1;
    *(undefined1 *)((int)&local_24 + (local_20 >> 8 & 0xff)) = 1;
    *(undefined1 *)((int)&local_24 + (local_20 >> 0x18)) = 1;
    break;
  case 3:
    if (param_2 - 1U < 2) {
      uVar4 = ((int (*)())FUN_000f5f7a)(local_20,2);
      return uVar4;
    }
    if (param_2 != 3) {
      return local_24;
    }
    goto code_r0x000f67e9;
  case 4:
code_r0x000f66ae:
    uVar4 = ((int (*)())FUN_000f5f7a)(local_20,3);
    return uVar4;
  case 5:
  case 8:
    goto code_r0x000f668b;
  case 6:
    if (param_2 == 1) {
      iVar3 = 0;
      do {
        iVar5 = FUN_0010b0f4(param_1,0);
        if (*(char *)(iVar3 + 0x10 + iVar5) != '\x01') {
          pbVar1 = (byte *)((int)&local_24 + (uint)*(byte *)((int)&local_20 + iVar3));
          *pbVar1 = *pbVar1 | 1;
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 != 4);
      return local_24;
    }
    goto code_r0x000f668b;
  case 7:
    if (param_2 < 3) goto code_r0x000f66ae;
    goto code_r0x000f6800;
  case 9:
    if (param_1[0x4d] < 0) {
      iVar3 = 0;
      uVar6 = 0xfffffff6;
    }
    else {
      iVar3 = *(int *)(*(int *)(param_4 + 0x78) + 4 + param_1[0x4d] * 0xc);
      uVar6 = iVar3 - 10;
    }
    uVar7 = *(uint *)(iVar3 * 8 + 0x1ef324);
    if (uVar6 < 2) {
      if ((*(unsigned char *)((unsigned char *)&(local_20) + 3)) == '\x04') {
        uVar7 = uVar7 & 7;
      }
    }
    if ((uVar7 & 1) != 0) {
      *(undefined1 *)((int)&local_24 + (local_20 & 0xff)) = 1;
    }
    if ((uVar7 & 2) != 0) {
      *(undefined1 *)((int)&local_24 + (local_20 >> 8 & 0xff)) = 1;
    }
    if ((uVar7 & 4) != 0) {
      *(undefined1 *)((int)&local_24 + (local_20 >> 0x10 & 0xff)) = 1;
    }
    if ((uVar7 & 8) != 0) {
      *(undefined1 *)((int)&local_24 + (local_20 >> 0x18)) = 1;
    }
    iVar3 = *(int *)(param_1[0x22] + 8);
    if (iVar3 < 0xa2) {
      if (0x9d < iVar3) {
        iVar3 = FUN_0010b0f4(param_1,0);
        uStack_28 = ((int (*)())FUN_000f5a44)(*(undefined4 *)(iVar3 + 0x10),param_3);
        local_24 = 0;
        iVar3 = 1;
        do {
          pbVar1 = (byte *)((int)&local_24 + (uint)*(byte *)((int)&local_24 + iVar3 + 3));
          *pbVar1 = *pbVar1 | (&cStack_29)[iVar3] != '\x01';
          iVar3 = iVar3 + 1;
        } while (iVar3 != 5);
        return local_24;
      }
      if (iVar3 != 0x6e) {
        if (iVar3 < 0x6e) {
          return local_24;
        }
        if (1 < iVar3 - 0x75U) {
          return local_24;
        }
        goto code_r0x000f6766;
      }
    }
    else {
      if (iVar3 == 0xae) goto code_r0x000f6766;
      if (iVar3 < 0xae) {
        return local_24;
      }
      if (2 < iVar3 - 0x100U) {
        return local_24;
      }
    }
    goto code_r0x000f6800;
  default:
LAB_000f6670:
    local_24 = 0x1010101;
    break;
  case 0xb:
    goto code_r0x000f66a3;
  case 0xc:
    iVar3 = FUN_0010b0f4(param_1,0);
    uStack_28 = ((int (*)())FUN_000f5a44)(*(undefined4 *)(iVar3 + 0x10),param_3);
    local_24 = 0;
    iVar3 = 1;
    do {
      if (((&cStack_29)[iVar3] == '\0') &&
         (bVar2 = *(byte *)((int)&local_24 + iVar3 + 3), bVar2 != 4)) {
        pbVar1 = (byte *)((int)&local_24 + (uint)bVar2);
        *pbVar1 = *pbVar1 | 1;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 != 5);
    break;
  case 0xd:
    if (param_2 != 2) {
      *(undefined1 *)((int)&local_24 + (local_20 & 0xff)) = 1;
      *(undefined1 *)((int)&local_24 + (local_20 >> 8 & 0xff)) = 1;
      *(undefined1 *)((int)&local_24 + (local_20 >> 0x10 & 0xff)) = 1;
      *(undefined1 *)((int)&local_24 + (local_20 >> 0x18)) = 1;
      return local_24;
    }
    goto code_r0x000f66a3;
  case 0xe:
    if (param_2 == 1) {
      iVar3 = FUN_0010b0f4(param_1,0);
      uStack_28 = ((int (*)())FUN_000f5a44)(*(undefined4 *)(iVar3 + 0x10),param_3);
      iVar3 = 1;
      do {
        if ((&cStack_29)[iVar3] != '\x01') {
          *(undefined1 *)((int)&local_24 + (uint)*(byte *)((int)&local_24 + iVar3 + 3)) = 1;
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 != 5);
      return local_24;
    }
    if (param_2 == 2) goto code_r0x000f66a3;
    if (param_2 != 3) {
      return local_24;
    }
code_r0x000f6948:
    *(undefined1 *)((int)&local_24 + (local_20 & 0xff)) = 1;
    *(undefined1 *)((int)&local_24 + (local_20 >> 8 & 0xff)) = 1;
    *(undefined1 *)((int)&local_24 + (local_20 >> 0x10 & 0xff)) = 1;
code_r0x000f6800:
    *(undefined1 *)((int)&local_24 + (local_20 >> 0x18)) = 1;
    break;
  case 0xf:
    if (*(int *)(param_1[0x22] + 8) != 0xb4) goto LAB_000f6670;
    if (param_2 != 2) {
      if (param_2 < 3) {
        if (param_2 != 1) {
          return local_24;
        }
        *(undefined1 *)((int)&local_24 + (local_20 & 0xff)) = 1;
        *(undefined1 *)((int)&local_24 + (local_20 >> 8 & 0xff)) = 1;
        return local_24;
      }
      if (param_2 != 3) {
        if (param_2 != 4) {
          return local_24;
        }
        goto code_r0x000f6948;
      }
      goto code_r0x000f6800;
    }
code_r0x000f67e9:
    *(undefined1 *)((int)&local_24 + (local_20 >> 0x10 & 0xff)) = 1;
  }
  return local_24;
code_r0x000f668b:
  uVar4 = ((int (*)())FUN_000f5f7a)(local_20,4);
  return uVar4;
code_r0x000f66a3:
  *(undefined1 *)((int)&local_24 + (local_20 & 0xff)) = 1;
  return local_24;
}

/* FUN_000f6a7e @ 0xf6a7e (114 bytes) */
int FUN_000f6a7e(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  int iVar1;
  int iVar2;
  undefined4 local_20 [4];
  
  local_20[0] = ((int (*)())FUN_000f65d0)(param_1,param_2,DAT_001c6534,param_4);
  iVar2 = 0;
  while ((*(char *)((int)local_20 + iVar2) == '\0' ||
         (iVar1 = FUN_0010b0f4(param_3,0), *(char *)(iVar2 + 0x10 + iVar1) != '\x01'))) {
    iVar2 = iVar2 + 1;
    if (iVar2 == 4) {
      return 1;
    }
  }
  return 0;
}

/* FUN_000f6af0 @ 0xf6af0 (135 bytes) */
int FUN_000f6af0(param_1, param_2, param_3)
  int param_1;
  int param_2;
  undefined4 param_3;
{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_0010b0f4(param_1,0);
  uVar2 = ((int (*)())FUN_000f626e)(param_1,param_2,param_3,*(undefined4 *)(iVar1 + 0x10));
  iVar1 = FUN_0010b0f4(param_1,param_2);
  uVar2 = ((int (*)())FUN_000f5b96)(*(undefined4 *)(iVar1 + 0x10),uVar2);
  if (param_2 == 0) {
    *(undefined4 *)(param_1 + 0x9c) = uVar2;
    return;
  }
  iVar1 = FUN_0010b0f4(param_1,param_2);
  *(undefined4 *)(iVar1 + 0x10) = uVar2;
  return;
}

/* FUN_000f6b78 @ 0xf6b78 (72 bytes) */
int FUN_000f6b78(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  int iVar1;
  char cStack_11;
  undefined4 local_10;
  
  iVar1 = FUN_0010b0f4(param_2,0);
  local_10 = *(undefined4 *)(iVar1 + 0x10);
  iVar1 = 1;
  do {
    (&cStack_11)[iVar1] = (&cStack_11)[iVar1] != '\x01';
    iVar1 = iVar1 + 1;
  } while (iVar1 != 5);
  *(undefined4 *)(param_1 + 0x9c) = local_10;
  return;
}

/* FUN_000f6bc0 @ 0xf6bc0 (134 bytes) */
int FUN_000f6bc0(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  int iVar1;
  char cStack_15;
  undefined4 local_14;
  undefined4 local_10 [2];
  
  iVar1 = FUN_0010b0f4(param_2,0);
  local_10[0] = *(undefined4 *)(iVar1 + 0x10);
  iVar1 = FUN_0010b0f4(param_3,0);
  local_14 = *(undefined4 *)(iVar1 + 0x10);
  iVar1 = 1;
  do {
    if ((*(char *)((int)local_10 + iVar1 + -1) != '\x01') && ((&cStack_15)[iVar1] != '\x01')) break;
    iVar1 = iVar1 + 1;
  } while (iVar1 != 5);
  iVar1 = 1;
  do {
    if ((&cStack_15)[iVar1] != '\x01') {
      *(char *)((int)local_10 + iVar1 + -1) = (&cStack_15)[iVar1];
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 != 5);
  *(undefined4 *)(param_1 + 0x9c) = local_10[0];
  return;
}

/* FUN_000f6c46 @ 0xf6c46 (123 bytes) */
int FUN_000f6c46(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  byte bVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined4 local_10;
  
  uVar2 = FUN_0010b180(param_1,param_2);
  iVar3 = FUN_0010b0f4(param_1,param_2);
  local_10 = *(undefined4 *)(iVar3 + 0x10);
  iVar3 = 0;
  while ((bVar1 = *(byte *)((int)&local_10 + iVar3), bVar1 == 4 ||
         (iVar4 = FUN_0010b0f4(uVar2,0), *(char *)(bVar1 + 0x10 + iVar4) == '\x01'))) {
    iVar3 = iVar3 + 1;
    if (iVar3 == 4) {
      return 1;
    }
  }
  return 0;
}

/* FUN_000f6cc2 @ 0xf6cc2 (127 bytes) */
int FUN_000f6cc2(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  byte bVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  byte bStack_11;
  undefined4 local_10;
  
  uVar2 = FUN_0010b180(param_1,param_2);
  iVar3 = FUN_0010b0f4(param_1,param_2);
  local_10 = *(undefined4 *)(iVar3 + 0x10);
  iVar3 = 1;
  while ((bVar1 = (&bStack_11)[iVar3], bVar1 == 4 ||
         (iVar4 = FUN_0010b0f4(uVar2,0), *(char *)(bVar1 + 0x10 + iVar4) != '\x01'))) {
    iVar3 = iVar3 + 1;
    if (iVar3 == 5) {
      return 1;
    }
  }
  return 0;
}

/* FUN_000f6d42 @ 0xf6d42 (157 bytes) */
int FUN_000f6d42(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  iVar2 = FUN_0010b0f4(param_1,0);
  uVar3 = ((int (*)())FUN_000f5fea)(*(undefined4 *)(iVar2 + 0x10));
  cVar1 = FUN_0010b1aa(param_2);
  if (cVar1 != '\0') {
    iVar2 = FUN_0010b0f4(param_2,0);
    uVar4 = ((int (*)())FUN_000f5fea)(*(undefined4 *)(iVar2 + 0x10));
    return (uVar3 & uVar4) != 0;
  }
  iVar2 = FUN_0010b0f4(param_2,0);
  uVar4 = ((int (*)())FUN_000f6032)(*(undefined4 *)(iVar2 + 0x10),DAT_001c6534);
  return (uVar3 & uVar4) != 0;
}

/* FUN_000f6de0 @ 0xf6de0 (61 bytes) */
int FUN_000f6de0(param_1, param_2)
  undefined4 *param_1;
  undefined4 *param_2;
{
  *param_2 = 2;
  param_2[6] = 2;
  param_2[0xc] = 2;
  param_2[0x12] = 2;
  param_2[1] = *param_1;
  param_2[7] = param_1[1];
  param_2[0xd] = param_1[2];
  param_2[0x13] = param_1[3];
  return;
}

/* FUN_000f6e1e @ 0xf6e1e (17 bytes) */
int FUN_000f6e1e(param_1)
  int param_1;
{
  *(int *)(param_1 + 0x30) = *(int *)(param_1 + 0x30) + -1;
  return;
}

/* FUN_000f6e30 @ 0xf6e30 (15 bytes) */
int FUN_000f6e30(param_1)
  int param_1;
{
  return param_1 < 0x15;
}

/* FUN_000f6e40 @ 0xf6e40 (282 bytes) */
int FUN_000f6e40(param_1, param_2, param_3)
  int *param_1;
  int param_2;
  int param_3;
{
  int iVar1;
  int iVar2;
  
  if (param_2 == 2) {
    iVar2 = *(int *)(*param_1 + 0xdc);
    if ((char)param_1[0xb] == '\0') {
      iVar1 = *(int *)(iVar2 + 0x2c);
    }
    else {
      iVar1 = *(int *)(iVar2 + 0x30);
    }
    iVar2 = FUN_000d8e16(iVar2,iVar1 + 0x58,param_1[0xe]);
    if (-1 < iVar2) {
      param_1[0xe] = param_1[0xe] + 1;
    }
    goto LAB_000f6e6f;
  }
  if (param_2 < 3) {
    if (param_2 == 1) goto LAB_000f6e8b;
  }
  else {
    if (param_2 == 3) {
LAB_000f6e8b:
      iVar2 = *(int *)(*param_1 + 0xdc);
      if ((char)param_1[0xb] == '\0') {
        iVar1 = *(int *)(iVar2 + 0x2c);
      }
      else {
        iVar1 = *(int *)(iVar2 + 0x30);
      }
      iVar2 = FUN_000d8e16(iVar2,iVar1 + 0x78,param_1[0xf]);
      if (-1 < iVar2) {
        param_1[0xf] = param_1[0xf] + 1;
      }
      goto LAB_000f6e6f;
    }
    if (param_2 == 4) {
      iVar2 = *(int *)(*param_1 + 0xdc);
      if ((char)param_1[0xb] == '\0') {
        iVar1 = *(int *)(iVar2 + 0x2c);
      }
      else {
        iVar1 = *(int *)(iVar2 + 0x30);
      }
      iVar2 = FUN_000d8e16(iVar2,iVar1 + 0x98,param_1[0x10]);
      if (-1 < iVar2) {
        param_1[0x10] = param_1[0x10] + 1;
      }
      goto LAB_000f6e6f;
    }
  }
  iVar2 = -1;
LAB_000f6e6f:
  if ((param_3 == '\0') && (iVar2 < 0)) {
    FUN_000e27ca(*param_1,0xd);
    return iVar2;
  }
  return iVar2;
}

/* FUN_000f6f5a @ 0xf6f5a (19 bytes) */
bool FUN_000f6f5a(float param_1,float param_2)

{
  return param_2 < param_1;
}

/* FUN_000f6f6e @ 0xf6f6e (71 bytes) */
int FUN_000f6f6e(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  if (0 < param_2) {
    iVar1 = 0;
    iVar4 = 0;
    do {
      uVar3 = *(uint *)(param_1 + iVar4 * 4);
      if (uVar3 == 0) {
        iVar1 = iVar1 + 0x20;
      }
      else {
        iVar2 = 0;
        do {
          if ((uVar3 & 1) != 0) {
            return iVar1;
          }
          uVar3 = uVar3 >> 1;
          iVar1 = iVar1 + 1;
          iVar2 = iVar2 + 1;
        } while (iVar2 != 0x20);
      }
      iVar4 = iVar4 + 1;
    } while (param_2 != iVar4);
  }
  return -1;
}

