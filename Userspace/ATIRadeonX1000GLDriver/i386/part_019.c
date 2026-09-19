#include "decls.h"

/* FUN_000d969e @ 0xd969e (102 bytes) */
int FUN_000d969e(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  undefined4 param_4;
{
  undefined4 uVar1;
  
  *(undefined4 *)(param_1 + 0x3c) = param_4;
  *(int *)(param_1 + 0x30) = param_2;
  *(int *)(param_1 + 0x34) = param_3;
  *(int *)(param_1 + 0x2c) = param_2;
  if (*(int *)(param_1 + 8) != 0) {
    uVar1 = FUN_000e3b36(*(int *)(param_1 + 8),param_4,*(undefined4 *)(param_2 + 0x4c),
                         *(undefined4 *)(param_3 + 0x4c),*(undefined4 *)(param_2 + 0x54),
                         *(undefined4 *)(param_3 + 0x54),param_1);
    return uVar1;
  }
  return 2;
}

/* FUN_000d9704 @ 0xd9704 (22 bytes) */
int FUN_000d9704(param_1)
  int param_1;
{
  if (*(int *)(param_1 + 8) != 0) {
    return *(undefined4 *)(*(int *)(param_1 + 8) + 0x5c);
  }
  return 2;
}

/* FUN_000d971a @ 0xd971a (33 bytes) */
int FUN_000d971a(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  *(undefined4 *)(param_1 + 0x18) = *param_2;
  *(undefined4 *)(param_1 + 0x1c) = param_2[1];
  *(undefined4 *)(param_1 + 0x20) = param_2[2];
  return;
}

/* FUN_000d973c @ 0xd973c (57 bytes) */
int FUN_000d973c(param_1, param_2)
  undefined4 *param_1;
  int param_2;
{
  if (param_1[2] != 0) {
    FUN_000e32d2(param_1[2],param_2);
    (*(code *)*param_1)(param_1[1],param_1[2]);
  }
  return;
}

/* FUN_000d9776 @ 0xd9776 (661 bytes) */
int FUN_000d9776(param_1, param_2)
  undefined4 *param_1;
  undefined4 *param_2;
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  
  iVar4 = (*(code *)param_2[0xc])(param_2[0xb],0x3f8);
  uVar5 = param_2[0xd];
  *param_1 = uVar5;
  uVar1 = param_2[0xb];
  param_1[1] = uVar1;
  param_1[3] = *param_2;
  param_1[5] = param_2[1];
  param_1[4] = param_2[0x14];
  if (iVar4 == 0) {
    param_1[2] = 0;
    return;
  }
  FUN_000e2d5a(iVar4,uVar1,param_2[0xc],uVar5,0,0,param_2[0xf],param_2[0x10],param_2[0x11],
               param_2[0x12],param_2[0x13],param_2[0xe]);
  param_1[2] = iVar4;
  if (*(int *)(iVar4 + 0x5c) != 0) {
    return;
  }
  iVar4 = _setjmp(*(int **)(iVar4 + 4));
  if (iVar4 != 0) {
    return;
  }
  if (param_1[3] == -1) {
    param_1[10] = param_2[2];
  }
  else {
    uVar5 = FUN_000cb1a2(param_1[3]);
    param_1[10] = uVar5;
  }
  iVar4 = param_2[4];
  iVar2 = param_2[3];
  iVar3 = param_1[10];
  if (iVar3 == 2) {
    FUN_000e2ebc(param_1[2],2);
    if (iVar4 - 1U < 0x20c) {
      *(int *)(*(int *)(*(int *)(param_1[2] + 0x58) + 8) + 0x40) = iVar4;
    }
    else {
      *(undefined4 *)(*(int *)(*(int *)(param_1[2] + 0x58) + 8) + 0x40) = 0x20c;
    }
    if (iVar2 - 1U < 0x100) goto LAB_000d9929;
  }
  else {
    if (iVar3 == 3) {
      FUN_000e2ebc(param_1[2],4);
      if (iVar4 - 1U < 0x200) {
        *(int *)(*(int *)(*(int *)(param_1[2] + 0x58) + 8) + 0x40) = iVar4;
      }
      else {
        *(undefined4 *)(*(int *)(*(int *)(param_1[2] + 0x58) + 8) + 0x40) = 0x200;
      }
      if (0x3ff < iVar2 - 1U) {
        *(undefined4 *)(*(int *)(*(int *)(param_1[2] + 0x58) + 4) + 0x40) = 0x400;
        return;
      }
LAB_000d9929:
      *(int *)(*(int *)(*(int *)(param_1[2] + 0x58) + 4) + 0x40) = iVar2;
      return;
    }
    if (iVar3 != 1) {
      *(undefined4 *)(param_1[2] + 0x5c) = 0xe;
      FUN_000e2ebc(param_1[2],1);
      return;
    }
    FUN_000e2ebc(param_1[2],1);
    if (iVar4 - 1U < 0x60) {
      *(int *)(*(int *)(*(int *)(param_1[2] + 0x58) + 8) + 0x40) = iVar4;
    }
    else {
      *(undefined4 *)(*(int *)(*(int *)(param_1[2] + 0x58) + 8) + 0x40) = 0x60;
    }
    if (iVar2 - 1U < 0x100) {
      *(int *)(*(int *)(*(int *)(param_1[2] + 0x58) + 4) + 0x40) = iVar4;
      return;
    }
  }
  *(undefined4 *)(*(int *)(*(int *)(param_1[2] + 0x58) + 4) + 0x40) = 0x100;
  return;
}

/* FUN_000d9a14 @ 0xd9a14 (238 bytes) */
int FUN_000d9a14(param_1)
  uint param_1;
{
  uint uVar1;
  longdouble lVar2;
  
  uVar1 = param_1 >> 3 & 0xf;
  param_1 = param_1 & 7;
  if (uVar1 != 0) {
    lVar2 = (longdouble)_pow(0,0x40000000,(double)uVar1 - DOUBLE_001cf3c8);
    return (longdouble)((float)lVar2 * ((float)param_1 * FLOAT_001c5c28 + FLOAT_001c5ba4));
  }
  if (param_1 == 0) {
    return (longdouble)FLOAT_001c5c68;
  }
  return (longdouble)((float)param_1 * FLOAT_001c5c28 * FLOAT_001c5c6c);
}

/* FUN_000d9b04 @ 0xd9b04 (81 bytes) */
int FUN_000d9b04(param_1)
  undefined4 *param_1;
{
  *param_1 = 0;
  param_1[0x84] = 0;
  param_1[0x85] = 0;
  *(undefined1 *)(param_1 + 0x86) = 0;
  param_1[0x87] = 0;
  _memset(param_1 + 4,0,0x200);
  return;
}

/* FUN_000d9b56 @ 0xd9b56 (81 bytes) */
int FUN_000d9b56(param_1)
  undefined4 *param_1;
{
  *param_1 = 0;
  param_1[0x84] = 0;
  param_1[0x85] = 0;
  *(undefined1 *)(param_1 + 0x86) = 0;
  param_1[0x87] = 0;
  _memset(param_1 + 4,0,0x200);
  return;
}

/* FUN_000d9ba8 @ 0xd9ba8 (12 bytes) */
int FUN_000d9ba8(param_1)
  int param_1;
{
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 4;
  return;
}

/* FUN_000d9bb4 @ 0xd9bb4 (24 bytes) */
int FUN_000d9bb4(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  
  iVar1 = 0;
  if (-1 < param_2) {
    iVar1 = param_2;
  }
  *(int *)(param_1 + 0x21c) = iVar1;
  return;
}

/* FUN_000d9bcc @ 0xd9bcc (7 bytes) */
int FUN_000d9bcc()
{
  return 0;
}

/* FUN_000d9bd4 @ 0xd9bd4 (7 bytes) */
int FUN_000d9bd4()
{
  return 0;
}

/* FUN_000d9bdc @ 0xd9bdc (106 bytes) */
int FUN_000d9bdc(param_1, param_2)
  int param_1;
  char *param_2;
{
  char cVar1;
  uint uVar2;
  char *pcVar3;
  char local_210 [512];
  undefined1 *local_10;
  
  local_10 = &STACKARG(0xc);
  _vsnprintf(local_210,0x200,param_2,local_10);
  uVar2 = 0xffffffff;
  pcVar3 = (char *)(param_1 + 0x10);
  do {
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  if (~uVar2 - 1 <= 0x1ff - (~uVar2 - 1)) {
    _strcat((char *)(param_1 + 0x10),local_210);
  }
  return;
}

/* FUN_000d9c46 @ 0xd9c46 (97 bytes) */
int FUN_000d9c46(param_1)
  int param_1;
{
  if (*(int *)(param_1 + 0x210) != 0) {
    ((int (*)())FUN_000d9bdc)(param_1,"\r\n");
    (*(code *)**(undefined4 **)(param_1 + 0x210))
              (*(undefined4 *)(param_1 + 0x214),"",param_1 + 0x10,0);
  }
  *(undefined1 *)(param_1 + 0x10) = 0;
  return;
}

/* FUN_000d9ca8 @ 0xd9ca8 (156 bytes) */
int FUN_000d9ca8(param_1, param_2, param_3)
  int param_1;
  int param_2;
  char *param_3;
{
  char cVar1;
  uint uVar2;
  char *pcVar3;
  int iVar4;
  char local_220 [512];
  undefined1 *local_20;
  
  if (0 < param_2) {
    iVar4 = 0;
    do {
      ((int (*)())FUN_000d9bdc)(param_1,"    ");
      iVar4 = iVar4 + 1;
    } while (param_2 != iVar4);
  }
  local_20 = &STACKARG(0x10);
  _vsnprintf(local_220,0x200,param_3,local_20);
  uVar2 = 0xffffffff;
  pcVar3 = (char *)(param_1 + 0x10);
  do {
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  if (~uVar2 - 1 <= 0x1ff - (~uVar2 - 1)) {
    _strcat((char *)(param_1 + 0x10),local_220);
  }
  return;
}

/* FUN_000d9d44 @ 0xd9d44 (309 bytes) */
int FUN_000d9d44(param_1, param_2, param_3)
  undefined4 param_1;
  uint param_2;
  int param_3;
{
  byte bVar1;
  char *pcVar2;
  byte bVar3;
  
  bVar1 = (byte)(param_2 >> 8);
  bVar3 = bVar1 >> 3 & 1;
  if (((((param_2 >> 3 & 1) == 0) && ((param_2 >> 7 & 1) == 0)) && (bVar3 == 0)) &&
     (-1 < (char)bVar1)) {
    return;
  }
  ((int (*)())FUN_000d9bdc)(param_1,"_neg(");
  if ((param_2 >> 3 & 1) != 0) {
    if (param_3 == '\0') {
      pcVar2 = "x";
    }
    else {
      pcVar2 = "r";
    }
    ((int (*)())FUN_000d9bdc)(param_1,pcVar2);
  }
  if ((param_2 >> 7 & 1) != 0) {
    if (param_3 == '\0') {
      pcVar2 = "y";
    }
    else {
      pcVar2 = "g";
    }
    ((int (*)())FUN_000d9bdc)(param_1,pcVar2);
  }
  if (bVar3 != 0) {
    if (param_3 == '\0') {
      pcVar2 = "z";
    }
    else {
      pcVar2 = "b";
    }
    ((int (*)())FUN_000d9bdc)(param_1,pcVar2);
  }
  if ((char)bVar1 < '\0') {
    if (param_3 == '\0') {
      pcVar2 = "w";
    }
    else {
      pcVar2 = "a";
    }
    ((int (*)())FUN_000d9bdc)(param_1,pcVar2);
  }
  ((int (*)())FUN_000d9bdc)();
  return;
}

/* FUN_000d9e7a @ 0xd9e7a (133 bytes) */
int FUN_000d9e7a(param_1, param_2, param_3)
  int *param_1;
  undefined4 param_2;
  int param_3;
{
  char cVar1;
  
  switch(param_2) {
  case 0:
    cVar1 = (-(param_3 == '\0') & 6U) + 0x72;
    break;
  case 1:
    cVar1 = (-(param_3 == '\0') & 0x12U) + 0x67;
    break;
  case 2:
    cVar1 = (-(param_3 == '\0') & 0x18U) + 0x62;
    break;
  case 3:
    cVar1 = (-(param_3 == '\0') & 0x16U) + 0x61;
    break;
  case 4:
    cVar1 = '0';
    break;
  case 5:
    cVar1 = '1';
    break;
  default:
    *param_1 = *param_1 + 1;
    ((int (*)())FUN_000d9bdc)(param_1,"!!!invalidCompSel!!!");
    cVar1 = '\0';
  }
  return cVar1;
}

/* FUN_000d9f18 @ 0xd9f18 (316 bytes) */
int FUN_000d9f18(param_1, param_2, param_3)
  undefined4 param_1;
  uint param_2;
  int param_3;
{
  int iVar1;
  uint uVar2;
  char *pcVar3;
  char *pcVar4;
  char *pcVar5;
  char *pcVar6;
  undefined1 uVar7;
  bool bVar8;
  char local_21 [4];
  undefined1 local_1d;
  
  local_21[0] = ((int (*)())FUN_000d9e7a)(param_1,param_2 & 7,param_3);
  local_21[1] = ((int (*)())FUN_000d9e7a)(param_1,param_2 >> 4 & 7,param_3);
  local_21[2] = ((int (*)())FUN_000d9e7a)(param_1,param_2 >> 8 & 7,param_3);
  uVar2 = param_2 >> 0xc & 7;
  uVar7 = uVar2 == 0;
  local_21[3] = ((int (*)())FUN_000d9e7a)(param_1,uVar2,param_3);
  local_1d = 0;
  iVar1 = 5;
  pcVar3 = local_21;
  pcVar5 = "rgba";
  do {
    pcVar4 = pcVar3;
    pcVar6 = pcVar5;
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    pcVar6 = pcVar5 + 1;
    pcVar4 = pcVar3 + 1;
    uVar7 = *pcVar3 == *pcVar5;
    pcVar3 = pcVar4;
    pcVar5 = pcVar6;
  } while ((bool)uVar7);
  iVar1 = 0;
  if (!(bool)uVar7) {
    iVar1 = (uint)(byte)pcVar4[-1] - (uint)(byte)pcVar6[-1];
  }
  bVar8 = iVar1 == 0;
  if (!bVar8) {
    iVar1 = 5;
    pcVar3 = local_21;
    pcVar5 = "xyzw";
    do {
      pcVar4 = pcVar3;
      pcVar6 = pcVar5;
      if (iVar1 == 0) break;
      iVar1 = iVar1 + -1;
      pcVar6 = pcVar5 + 1;
      pcVar4 = pcVar3 + 1;
      bVar8 = *pcVar3 == *pcVar5;
      pcVar3 = pcVar4;
      pcVar5 = pcVar6;
    } while (bVar8);
    iVar1 = 0;
    if (!bVar8) {
      iVar1 = (uint)(byte)pcVar4[-1] - (uint)(byte)pcVar6[-1];
    }
    if (iVar1 != 0) {
      if ((((local_21[0] == local_21[1]) && (local_21[0] == local_21[2])) &&
          (local_21[0] == local_21[3])) &&
         (((byte)(local_21[0] + 0x9fU) < 0x1a || ((byte)(local_21[0] + 0xbfU) < 0x1a)))) {
        local_21[1] = '\0';
      }
      ((int (*)())FUN_000d9bdc)(param_1,".");
      ((int (*)())FUN_000d9bdc)(param_1,local_21);
      return;
    }
  }
  return;
}

/* FUN_000da054 @ 0xda054 (183 bytes) */
int FUN_000da054(param_1, param_2)
  int *param_1;
  uint param_2;
{
  if ((param_2 >> 8 & 1) != 0) {
    ((int (*)())FUN_000d9bdc)(param_1,"_sat");
  }
  if ((param_2 >> 8 & 0x1e) != 0) {
    switch(param_2 >> 9 & 0xf) {
    default:
      *param_1 = *param_1 + 1;
      break;
    case 1:
      break;
    case 2:
      break;
    case 3:
      break;
    case 4:
      break;
    case 5:
      break;
    case 6: ;
    }
    ((int (*)())FUN_000d9bdc)();
    return;
  }
  return;
}

/* FUN_000da12a @ 0xda12a (195 bytes) */
int FUN_000da12a(param_1, param_2)
  int *param_1;
  undefined4 param_2;
{
  switch(param_2) {
  case 0:
    ((int (*)())FUN_000d9bdc)();
    return;
  case 1:
    ((int (*)())FUN_000d9bdc)();
    return;
  case 2:
    ((int (*)())FUN_000d9bdc)();
    return;
  case 3:
    ((int (*)())FUN_000d9bdc)();
    return;
  case 4:
    ((int (*)())FUN_000d9bdc)();
    return;
  case 5:
    ((int (*)())FUN_000d9bdc)();
    return;
  case 6:
    ((int (*)())FUN_000d9bdc)();
    return;
  case 7:
    ((int (*)())FUN_000d9bdc)();
    return;
  default:
    *param_1 = *param_1 + 1;
    ((int (*)())FUN_000d9bdc)();
    return;
  }
}

/* FUN_000da20e @ 0xda20e (249 bytes) */
int FUN_000da20e(param_1)
  int param_1;
{
  uint uVar1;
  
  uVar1 = **(uint **)(param_1 + 8);
  *(uint **)(param_1 + 8) = *(uint **)(param_1 + 8) + 1;
  ((int (*)())FUN_000d9bdc)(param_1,"_fmtx(");
  ((int (*)())FUN_000da12a)(param_1,uVar1 >> 0x14 & 7);
  ((int (*)())FUN_000d9bdc)(param_1,")");
  ((int (*)())FUN_000d9bdc)(param_1,"_fmty(");
  ((int (*)())FUN_000da12a)(param_1,uVar1 >> 0x17 & 7);
  ((int (*)())FUN_000d9bdc)(param_1,")");
  ((int (*)())FUN_000d9bdc)(param_1,"_fmtz(");
  ((int (*)())FUN_000da12a)(param_1,uVar1 >> 0x1a & 7);
  ((int (*)())FUN_000d9bdc)(param_1,")");
  ((int (*)())FUN_000d9bdc)(param_1,"_fmtw(");
  ((int (*)())FUN_000da12a)(param_1,uVar1 >> 0x1d);
  ((int (*)())FUN_000d9bdc)(param_1,")");
  return;
}

/* FUN_000da308 @ 0xda308 (119 bytes) */
int FUN_000da308(param_1, param_2, param_3)
  int *param_1;
  int param_2;
  char *param_3;
{
  int iVar1;
  
  iVar1 = 0;
  if (param_3 != (char *)0x0) {
    if (param_2 == 1) {
      return (int)*param_3;
    }
    if (param_2 < 2) {
      if (param_2 == 0) {
        return 0x5f;
      }
    }
    else {
      if (param_2 == 2) {
        return 0x30;
      }
      if (param_2 == 3) {
        return 0x31;
      }
    }
    *param_1 = *param_1 + 1;
    ((int (*)())FUN_000d9bdc)(param_1,"!!!invalidModComp!!!");
    iVar1 = 0x20;
  }
  return iVar1;
}

/* FUN_000da380 @ 0xda380 (437 bytes) */
int FUN_000da380(param_1, param_2, param_3)
  undefined4 param_1;
  uint param_2;
  int param_3;
{
  char *pcVar1;
  int iVar2;
  char acStack_21 [4];
  undefined1 local_1d;
  
  if ((char)param_2 == 'U') {
    return;
  }
  if (param_3 == '\0') {
    acStack_21[1] = ((int (*)())FUN_000da308)(param_1,param_2 & 3,"x");
  }
  else {
    acStack_21[1] = ((int (*)())FUN_000da308)(param_1,param_2 & 3,"r");
    if (param_3 != '\0') {
      acStack_21[2] = ((int (*)())FUN_000da308)(param_1,param_2 >> 2 & 3,"g");
      goto joined_r0x000da4f6;
    }
  }
  acStack_21[2] = ((int (*)())FUN_000da308)(param_1,param_2 >> 2 & 3,"y");
joined_r0x000da4f6:
  if (param_3 == '\0') {
    acStack_21[3] = ((int (*)())FUN_000da308)(param_1,param_2 >> 4 & 3,"z");
    pcVar1 = "w";
  }
  else {
    acStack_21[3] = ((int (*)())FUN_000da308)(param_1,param_2 >> 4 & 3,"b");
    pcVar1 = "a";
  }
  local_1d = ((int (*)())FUN_000da308)(param_1,param_2 >> 6 & 3,pcVar1);
  ((int (*)())FUN_000d9bdc)(param_1,".");
  iVar2 = 1;
  do {
    ((int (*)())FUN_000d9bdc)(param_1,"%c",(int)acStack_21[iVar2]);
    iVar2 = iVar2 + 1;
  } while (iVar2 != 5);
  return;
}

/* FUN_000da536 @ 0xda536 (73 bytes) */
int FUN_000da536(param_1)
  int param_1;
{
  undefined4 uVar1;
  char local_4e [62];
  
  uVar1 = **(undefined4 **)(param_1 + 8);
  *(undefined4 **)(param_1 + 8) = *(undefined4 **)(param_1 + 8) + 1;
  _sprintf(local_4e,"%lu",uVar1);
  ((int (*)())FUN_000d9bdc)(param_1,local_4e);
  return;
}

/* FUN_000da580 @ 0xda580 (317 bytes) */
int FUN_000da580(param_1, param_2)
  int *param_1;
  uint param_2;
{
  ((int (*)())FUN_000d9bdc)(param_1,"_cmpval(");
  switch(param_2 >> 0x16 & 7) {
  case 0:
    ((int (*)())FUN_000d9bdc)(param_1,"0.0");
    ((int (*)())FUN_000d9bdc)();
    return;
  case 1:
    ((int (*)())FUN_000d9bdc)(param_1,"0.5");
    ((int (*)())FUN_000d9bdc)();
    return;
  case 2:
    ((int (*)())FUN_000d9bdc)(param_1,"1.0");
    ((int (*)())FUN_000d9bdc)();
    return;
  case 3:
    ((int (*)())FUN_000d9bdc)(param_1,"-0.5");
    ((int (*)())FUN_000d9bdc)();
    return;
  case 4:
    ((int (*)())FUN_000d9bdc)(param_1,"-1.0");
    ((int (*)())FUN_000d9bdc)();
    return;
  default:
    *param_1 = *param_1 + 1;
    ((int (*)())FUN_000d9bdc)(param_1,"!!!invalidCmpVal!!!");
    ((int (*)())FUN_000d9bdc)();
    return;
  }
}

/* FUN_000da6d4 @ 0xda6d4 (222 bytes) */
int FUN_000da6d4(param_1, param_2)
  int *param_1;
  undefined4 param_2;
{
  ((int (*)())FUN_000d9bdc)(param_1,"_usage(");
  switch(param_2) {
  case 0:
    ((int (*)())FUN_000d9bdc)(param_1,"pos");
    break;
  case 1:
    ((int (*)())FUN_000d9bdc)(param_1,"pointsize");
    break;
  case 2:
    ((int (*)())FUN_000d9bdc)(param_1,"color");
    break;
  case 3:
    ((int (*)())FUN_000d9bdc)(param_1,"backcolor");
    break;
  case 4:
    ((int (*)())FUN_000d9bdc)(param_1,"fog");
    break;
  case 5:
    ((int (*)())FUN_000d9bdc)(param_1,"generic");
    break;
  default:
    *param_1 = *param_1 + 1;
    ((int (*)())FUN_000d9bdc)(param_1,"!!!invalid!!!");
  }
  ((int (*)())FUN_000d9bdc)();
  return;
}

/* FUN_000da7cc @ 0xda7cc (346 bytes) */
int FUN_000da7cc(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  uint param_2;
  uint param_3;
  int param_4;
{
  byte bVar1;
  int iVar2;
  uint uVar3;
  float fVar4;
  float fVar5;
  undefined1 local_11c [268];
  
  bVar1 = (byte)param_4;
  if (param_3 < 2) {
    uVar3 = 0;
  }
  else {
    if (param_3 == 1) {
      uVar3 = 0;
    }
    else {
      iVar2 = 0;
      uVar3 = 0;
      do {
        uVar3 = uVar3 | 1 << ((byte)iVar2 & 0x1f);
        iVar2 = iVar2 + 1;
      } while (param_3 - 1 != iVar2);
      uVar3 = uVar3 << (bVar1 & 0x1f);
    }
    uVar3 = uVar3 & param_2;
  }
  fVar4 = (float)(uVar3 >> (bVar1 & 0x1f));
  if ((param_2 & 1 << ((bVar1 - 1) + (char)param_3 & 0x1f)) != 0) {
    fVar4 = FLOAT_001c5bdc - fVar4;
  }
  if (param_4 == 0) {
    uVar3 = 0;
  }
  else {
    iVar2 = 0;
    uVar3 = 0;
    do {
      uVar3 = uVar3 | 1 << ((byte)iVar2 & 0x1f);
      iVar2 = iVar2 + 1;
    } while (param_4 != iVar2);
    uVar3 = uVar3 & param_2;
    if ((int)uVar3 < 0) {
      fVar5 = (float)uVar3;
      goto LAB_000da894;
    }
  }
  fVar5 = (float)(int)uVar3;
LAB_000da894:
  ((char * (*)())FUN_000cbe42)(fVar4 + (float)(DOUBLE_001cf330 / (double)(uint)(1 << (bVar1 & 0x1f))) * fVar5,10,
               local_11c);
  ((int (*)())FUN_000d9bdc)(param_1,local_11c);
  return;
}

/* FUN_000da926 @ 0xda926 (233 bytes) */
int FUN_000da926(param_1, param_2)
  undefined4 param_1;
  uint param_2;
{
  ((int (*)())FUN_000d9bdc)(param_1,"_xoffset(");
  ((int (*)())FUN_000da7cc)(param_1,param_2 & 0xff,7,1);
  ((int (*)())FUN_000d9bdc)(param_1,")");
  ((int (*)())FUN_000d9bdc)(param_1,"_yoffset(");
  ((int (*)())FUN_000da7cc)(param_1,param_2 >> 8 & 0xff,7,1);
  ((int (*)())FUN_000d9bdc)(param_1,")");
  ((int (*)())FUN_000d9bdc)(param_1,"_zoffset(");
  ((int (*)())FUN_000da7cc)(param_1,param_2 >> 0x10 & 0xff,7,1);
  ((int (*)())FUN_000d9bdc)();
  return;
}

/* FUN_000daa10 @ 0xdaa10 (125 bytes) */
int FUN_000daa10(param_1, param_2, param_3)
  undefined4 param_1;
  uint param_2;
  int param_3;
{
  uint uVar1;
  char local_11b [267];
  
  uVar1 = (1 << (param_3 & 0x1f)) - 1;
  param_2 = uVar1 & param_2;
  if ((param_2 & 1 << (param_3 - 1 & 0x1f)) != 0) {
    param_2 = (uVar1 & ~param_2) + 1;
    ((int (*)())FUN_000d9bdc)(param_1,"-");
  }
  _sprintf(local_11b,"%lu",param_2);
  ((int (*)())FUN_000d9bdc)(param_1,local_11b);
  return;
}

/* FUN_000daa8e @ 0xdaa8e (199 bytes) */
int FUN_000daa8e(param_1, param_2)
  int param_1;
  uint param_2;
{
  uint uVar1;
  
  if ((param_2 & 0x20000000) == 0) {
    return;
  }
  ((int (*)())FUN_000d9bdc)(param_1,"_aoffimmi(");
  uVar1 = **(uint **)(param_1 + 8);
  *(uint **)(param_1 + 8) = *(uint **)(param_1 + 8) + 1;
  ((int (*)())FUN_000daa10)(param_1,uVar1 & 0xf,4);
  ((int (*)())FUN_000d9bdc)(param_1,",");
  ((int (*)())FUN_000daa10)(param_1,uVar1 >> 4 & 0xf,4);
  ((int (*)())FUN_000d9bdc)(param_1,",");
  ((int (*)())FUN_000daa10)(param_1,uVar1 >> 8 & 0xf,4);
  ((int (*)())FUN_000d9bdc)();
  return;
}

/* FUN_000dab56 @ 0xdab56 (90 bytes) */
int FUN_000dab56(param_1, param_2)
  undefined4 param_1;
  uint param_2;
{
  char local_10b [255];
  
  _sprintf(local_10b,"_resource(%d)_sampler(%d)",param_2 >> 0x10 & 0xff,param_2 >> 0x18 & 0x1f);
  ((int (*)())FUN_000d9bdc)(param_1,local_10b);
  return;
}

/* FUN_000dabb0 @ 0xdabb0 (245 bytes) */
int FUN_000dabb0(param_1, param_2)
  int *param_1;
  undefined4 param_2;
{
  ((int (*)())FUN_000d9bdc)(param_1,"_aniso(");
  switch(param_2) {
  case 0:
    ((int (*)())FUN_000d9bdc)(param_1,"unknown");
    break;
  case 1:
    ((int (*)())FUN_000d9bdc)(param_1,"disabled");
    break;
  case 2:
    ((int (*)())FUN_000d9bdc)(param_1,"1");
    break;
  case 3:
    ((int (*)())FUN_000d9bdc)(param_1,"2");
    break;
  case 4:
    ((int (*)())FUN_000d9bdc)(param_1,"4");
    break;
  case 5:
    ((int (*)())FUN_000d9bdc)(param_1,"8");
    break;
  case 6:
    ((int (*)())FUN_000d9bdc)(param_1,"16");
    break;
  default:
    *param_1 = *param_1 + 1;
    ((int (*)())FUN_000d9bdc)(param_1,"!!invalid!!");
  }
  ((int (*)())FUN_000d9bdc)();
  return;
}

/* FUN_000dacc4 @ 0xdacc4 (249 bytes) */
int FUN_000dacc4(param_1, param_2)
  int *param_1;
  int param_2;
{
  ((int (*)())FUN_000d9bdc)(param_1,"_mip(");
  if (param_2 == 1) {
    ((int (*)())FUN_000d9bdc)(param_1,"point");
    ((int (*)())FUN_000d9bdc)();
    return;
  }
  if (param_2 == 0) {
    ((int (*)())FUN_000d9bdc)(param_1,"unknown");
  }
  else {
    if (param_2 == 2) {
      ((int (*)())FUN_000d9bdc)(param_1,"linear");
      ((int (*)())FUN_000d9bdc)();
      return;
    }
    if (param_2 != 3) {
      *param_1 = *param_1 + 1;
      ((int (*)())FUN_000d9bdc)(param_1,"!!invalid!!");
      ((int (*)())FUN_000d9bdc)();
      return;
    }
    ((int (*)())FUN_000d9bdc)(param_1,"base");
  }
  ((int (*)())FUN_000d9bdc)();
  return;
}

/* FUN_000dadbe @ 0xdadbe (124 bytes) */
int FUN_000dadbe(param_1, param_2)
  int *param_1;
  int param_2;
{
  if (param_2 == 1) {
    ((int (*)())FUN_000d9bdc)();
    return;
  }
  if (param_2 == 0) {
    ((int (*)())FUN_000d9bdc)();
    return;
  }
  if (param_2 == 2) {
    ((int (*)())FUN_000d9bdc)();
    return;
  }
  if (param_2 != 3) {
    *param_1 = *param_1 + 1;
    ((int (*)())FUN_000d9bdc)();
    return;
  }
  ((int (*)())FUN_000d9bdc)();
  return;
}

/* FUN_000dae3a @ 0xdae3a (348 bytes) */
int FUN_000dae3a(param_1, param_2)
  undefined4 param_1;
  uint param_2;
{
  ((int (*)())FUN_000d9bdc)(param_1,"_mag(");
  ((int (*)())FUN_000dadbe)(param_1,param_2 & 7);
  ((int (*)())FUN_000d9bdc)(param_1,")");
  ((int (*)())FUN_000d9bdc)(param_1,"_min(");
  ((int (*)())FUN_000dadbe)(param_1,param_2 >> 3 & 7);
  ((int (*)())FUN_000d9bdc)(param_1,")");
  ((int (*)())FUN_000d9bdc)(param_1,"_volmag(");
  ((int (*)())FUN_000dadbe)(param_1,param_2 >> 6 & 7);
  ((int (*)())FUN_000d9bdc)(param_1,")");
  ((int (*)())FUN_000d9bdc)(param_1,"_volmin(");
  ((int (*)())FUN_000dadbe)(param_1,param_2 >> 9 & 7);
  ((int (*)())FUN_000d9bdc)(param_1,")");
  ((int (*)())FUN_000dacc4)(param_1,param_2 >> 0xc & 7);
  ((int (*)())FUN_000dabb0)(param_1,param_2 >> 0xf & 7);
  ((int (*)())FUN_000d9bdc)(param_1,"_lodbias(");
  ((int (*)())FUN_000da7cc)(param_1,param_2 >> 0x12 & 0x7f,3,4);
  ((int (*)())FUN_000d9bdc)();
  return;
}

/* FUN_000daf96 @ 0xdaf96 (233 bytes) */
int FUN_000daf96(param_1, param_2)
  int *param_1;
  uint param_2;
{
  uint uVar1;
  
  ((int (*)())FUN_000d9bdc)(param_1,"_shadowmode(");
  uVar1 = param_2 >> 0x1a & 3;
  if (uVar1 == 1) {
    ((int (*)())FUN_000d9bdc)(param_1,"z");
    ((int (*)())FUN_000d9bdc)();
    return;
  }
  if (uVar1 != 0) {
    if (uVar1 != 2) {
      *param_1 = *param_1 + 1;
      ((int (*)())FUN_000d9bdc)(param_1,"!!invalid!!");
      ((int (*)())FUN_000d9bdc)();
      return;
    }
    ((int (*)())FUN_000d9bdc)(param_1,"unknown");
    ((int (*)())FUN_000d9bdc)();
    return;
  }
  ((int (*)())FUN_000d9bdc)(param_1,"never");
  ((int (*)())FUN_000d9bdc)();
  return;
}

/* FUN_000db080 @ 0xdb080 (124 bytes) */
int FUN_000db080(param_1, param_2)
  int *param_1;
  int param_2;
{
  if (param_2 == 1) {
    ((int (*)())FUN_000d9bdc)();
    return;
  }
  if (param_2 == 0) {
    ((int (*)())FUN_000d9bdc)();
    return;
  }
  if (param_2 == 2) {
    ((int (*)())FUN_000d9bdc)();
    return;
  }
  if (param_2 != 3) {
    *param_1 = *param_1 + 1;
    ((int (*)())FUN_000d9bdc)();
    return;
  }
  ((int (*)())FUN_000d9bdc)();
  return;
}

/* FUN_000db0fc @ 0xdb0fc (359 bytes) */
int FUN_000db0fc(param_1, param_2)
  int param_1;
  uint param_2;
{
  uint uVar1;
  char local_3a [42];
  
  ((int (*)())FUN_000da6d4)(param_1,param_2 >> 0x10 & 0x1f);
  _sprintf(local_3a,"_usageIndex(%d)",param_2 >> 0x15 & 0xff);
  ((int (*)())FUN_000d9bdc)(param_1,local_3a);
  if ((int)param_2 < 0) {
    uVar1 = **(uint **)(param_1 + 8);
    *(uint **)(param_1 + 8) = *(uint **)(param_1 + 8) + 1;
    ((int (*)())FUN_000d9bdc)(param_1,"_x(");
    ((int (*)())FUN_000db080)(param_1,uVar1 & 3);
    ((int (*)())FUN_000d9bdc)(param_1,")");
    ((int (*)())FUN_000d9bdc)(param_1,"_y(");
    ((int (*)())FUN_000db080)(param_1,uVar1 >> 2 & 3);
    ((int (*)())FUN_000d9bdc)(param_1,")");
    ((int (*)())FUN_000d9bdc)(param_1,"_z(");
    ((int (*)())FUN_000db080)(param_1,uVar1 >> 4 & 3);
    ((int (*)())FUN_000d9bdc)(param_1,")");
    ((int (*)())FUN_000d9bdc)(param_1,"_w(");
    ((int (*)())FUN_000db080)(param_1,uVar1 >> 6 & 3);
    ((int (*)())FUN_000d9bdc)(param_1,")");
  }
  return;
}

/* FUN_000db264 @ 0xdb264 (468 bytes) */
int FUN_000db264(param_1, param_2)
  int param_1;
  uint param_2;
{
  uint uVar1;
  char local_3a [42];
  
  ((int (*)())FUN_000da6d4)(param_1,param_2 >> 0x10 & 0x1f);
  _sprintf(local_3a,"_usageIndex(%d)",param_2 >> 0x15 & 0xff);
  ((int (*)())FUN_000d9bdc)(param_1,local_3a);
  if ((int)param_2 < 0) {
    uVar1 = **(uint **)(param_1 + 8);
    *(uint **)(param_1 + 8) = *(uint **)(param_1 + 8) + 1;
    ((int (*)())FUN_000d9bdc)(param_1,"_x(");
    ((int (*)())FUN_000db080)(param_1,uVar1 & 3);
    ((int (*)())FUN_000d9bdc)(param_1,")");
    ((int (*)())FUN_000d9bdc)(param_1,"_y(");
    ((int (*)())FUN_000db080)(param_1,uVar1 >> 2 & 3);
    ((int (*)())FUN_000d9bdc)(param_1,")");
    ((int (*)())FUN_000d9bdc)(param_1,"_z(");
    ((int (*)())FUN_000db080)(param_1,uVar1 >> 4 & 3);
    ((int (*)())FUN_000d9bdc)(param_1,")");
    ((int (*)())FUN_000d9bdc)(param_1,"_w(");
    ((int (*)())FUN_000db080)(param_1,uVar1 >> 6 & 3);
    ((int (*)())FUN_000d9bdc)(param_1,")");
    uVar1 = uVar1 >> 8;
    if ((uVar1 & 1) != 0) {
      ((int (*)())FUN_000d9bdc)(param_1,"_centroid");
    }
    if ((uVar1 & 2) != 0) {
      ((int (*)())FUN_000d9bdc)(param_1,"_constant");
    }
    if ((uVar1 & 4) != 0) {
      ((int (*)())FUN_000d9bdc)(param_1,"_noperspective");
      return;
    }
  }
  return;
}

/* FUN_000db438 @ 0xdb438 (334 bytes) */
int FUN_000db438(param_1, param_2)
  int param_1;
  uint param_2;
{
  uint uVar1;
  char local_30 [32];
  
  _sprintf(local_30,"_elem(%d)",param_2 >> 0x10 & 0x3f);
  ((int (*)())FUN_000d9bdc)(param_1,local_30);
  if ((int)param_2 < 0) {
    uVar1 = **(uint **)(param_1 + 8);
    *(uint **)(param_1 + 8) = *(uint **)(param_1 + 8) + 1;
    ((int (*)())FUN_000d9bdc)(param_1,"_x(");
    ((int (*)())FUN_000db080)(param_1,uVar1 & 3);
    ((int (*)())FUN_000d9bdc)(param_1,")");
    ((int (*)())FUN_000d9bdc)(param_1,"_y(");
    ((int (*)())FUN_000db080)(param_1,uVar1 >> 2 & 3);
    ((int (*)())FUN_000d9bdc)(param_1,")");
    ((int (*)())FUN_000d9bdc)(param_1,"_z(");
    ((int (*)())FUN_000db080)(param_1,uVar1 >> 4 & 3);
    ((int (*)())FUN_000d9bdc)(param_1,")");
    ((int (*)())FUN_000d9bdc)(param_1,"_w(");
    ((int (*)())FUN_000db080)(param_1,uVar1 >> 6 & 3);
    ((int (*)())FUN_000d9bdc)(param_1,")");
  }
  return;
}

/* FUN_000db586 @ 0xdb586 (306 bytes) */
int FUN_000db586(param_1, param_2)
  undefined4 param_1;
  uint param_2;
{
  ((int (*)())FUN_000d9bdc)(param_1,"_x(");
  ((int (*)())FUN_000db080)(param_1,param_2 >> 0x10 & 3);
  ((int (*)())FUN_000d9bdc)(param_1,")");
  ((int (*)())FUN_000d9bdc)(param_1,"_y(");
  ((int (*)())FUN_000db080)(param_1,param_2 >> 0x12 & 3);
  ((int (*)())FUN_000d9bdc)(param_1,")");
  ((int (*)())FUN_000d9bdc)(param_1,"_z(");
  ((int (*)())FUN_000db080)(param_1,param_2 >> 0x14 & 3);
  ((int (*)())FUN_000d9bdc)(param_1,")");
  ((int (*)())FUN_000d9bdc)(param_1,"_w(");
  ((int (*)())FUN_000db080)(param_1,param_2 >> 0x16 & 3);
  ((int (*)())FUN_000d9bdc)(param_1,")");
  if ((param_2 >> 0x18 & 1) != 0) {
    ((int (*)())FUN_000d9bdc)(param_1,"_center");
  }
  if ((param_2 >> 0x18 & 2) == 0) {
    return;
  }
  ((int (*)())FUN_000d9bdc)();
  return;
}

/* FUN_000db6b8 @ 0xdb6b8 (231 bytes) */
int FUN_000db6b8(param_1, param_2)
  int *param_1;
  undefined4 param_2;
{
  switch(param_2) {
  case 0:
    ((int (*)())FUN_000d9bdc)();
    return;
  case 1:
    ((int (*)())FUN_000d9bdc)();
    return;
  case 2:
    ((int (*)())FUN_000d9bdc)();
    return;
  case 3:
    ((int (*)())FUN_000d9bdc)();
    return;
  case 4:
    ((int (*)())FUN_000d9bdc)();
    return;
  case 5:
    ((int (*)())FUN_000d9bdc)();
    return;
  case 6:
    ((int (*)())FUN_000d9bdc)();
    return;
  case 7:
    ((int (*)())FUN_000d9bdc)();
    return;
  case 8:
    ((int (*)())FUN_000d9bdc)();
    return;
  case 9:
    ((int (*)())FUN_000d9bdc)();
    return;
  default:
    *param_1 = *param_1 + 1;
    ((int (*)())FUN_000d9bdc)();
    return;
  }
}

/* FUN_000db7ca @ 0xdb7ca (159 bytes) */
int FUN_000db7ca(param_1, param_2)
  int *param_1;
  uint param_2;
{
  uint uVar1;
  
  ((int (*)())FUN_000db6b8)(param_1,param_2 >> 0x18 & 7);
  uVar1 = param_2 >> 0x1b & 3;
  if (uVar1 == 1) {
    ((int (*)())FUN_000d9bdc)();
    return;
  }
  if (uVar1 != 0) {
    if (uVar1 != 2) {
      *param_1 = *param_1 + 1;
      ((int (*)())FUN_000d9bdc)();
      return;
    }
    ((int (*)())FUN_000d9bdc)();
    return;
  }
  ((int (*)())FUN_000d9bdc)();
  return;
}

/* FUN_000db86a @ 0xdb86a (101 bytes) */
int FUN_000db86a(param_1, param_2)
  int *param_1;
  int param_2;
{
  if (param_2 == 1) {
    ((int (*)())FUN_000d9bdc)();
    return;
  }
  if (param_2 != 0) {
    if (param_2 != 2) {
      *param_1 = *param_1 + 1;
      ((int (*)())FUN_000d9bdc)();
      return;
    }
    ((int (*)())FUN_000d9bdc)();
    return;
  }
  ((int (*)())FUN_000d9bdc)();
  return;
}

/* FUN_000db8d0 @ 0xdb8d0 (207 bytes) */
int FUN_000db8d0(param_1, param_2)
  undefined4 param_1;
  uint param_2;
{
  ((int (*)())FUN_000d9bdc)(param_1,"_x(");
  ((int (*)())FUN_000db86a)(param_1,param_2 >> 0x10 & 3);
  ((int (*)())FUN_000d9bdc)(param_1,")_y(");
  ((int (*)())FUN_000db86a)(param_1,param_2 >> 0x12 & 3);
  ((int (*)())FUN_000d9bdc)(param_1,")_z(");
  ((int (*)())FUN_000db86a)(param_1,param_2 >> 0x14 & 3);
  ((int (*)())FUN_000d9bdc)(param_1,")_w(");
  ((int (*)())FUN_000db86a)(param_1,param_2 >> 0x16 & 3);
  ((int (*)())FUN_000d9bdc)();
  return;
}

/* FUN_000db9a0 @ 0xdb9a0 (257 bytes) */
int FUN_000db9a0(param_1, param_2)
  int *param_1;
  uint param_2;
{
  uint uVar1;
  
  ((int (*)())FUN_000d9bdc)(param_1,"_zeroop(");
  uVar1 = param_2 >> 0x10 & 3;
  if (uVar1 == 1) {
    ((int (*)())FUN_000d9bdc)(param_1,"zero");
    ((int (*)())FUN_000d9bdc)();
    return;
  }
  if (uVar1 == 0) {
    ((int (*)())FUN_000d9bdc)(param_1,"fltmax");
  }
  else {
    if (uVar1 == 2) {
      ((int (*)())FUN_000d9bdc)(param_1,"infinity");
      ((int (*)())FUN_000d9bdc)();
      return;
    }
    if (uVar1 != 3) {
      *param_1 = *param_1 + 1;
      ((int (*)())FUN_000d9bdc)(param_1,"!!!invalid!!!");
      ((int (*)())FUN_000d9bdc)();
      return;
    }
    ((int (*)())FUN_000d9bdc)(param_1,"inf_else_max");
  }
  ((int (*)())FUN_000d9bdc)();
  return;
}

/* FUN_000dbaa2 @ 0xdbaa2 (177 bytes) */
int FUN_000dbaa2(param_1, param_2)
  undefined4 param_1;
  uint param_2;
{
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  if (((*(unsigned short *)((unsigned char *)&(param_2) + 2)) & 0x3fff) == 1) {
    local_20 = 0x6e696c5f;
    local_1c = 0x74735f65;
    local_18 = 0x706972;
    ((int (*)())FUN_000d9bdc)(param_1,&local_20);
    return;
  }
  if ((param_2 & 0x3fff0000) != 0) {
    if (((*(unsigned short *)((unsigned char *)&(param_2) + 2)) & 0x3fff) != 2) {
      ((int (*)())FUN_000d9bdc)(param_1,&local_20);
      return;
    }
    local_20 = 0x6972745f;
    local_1c = 0x6c676e61;
    local_18 = 0x74735f65;
    local_14 = 0x706972;
    ((int (*)())FUN_000d9bdc)(param_1,&local_20);
    return;
  }
  local_20 = 0x696f705f;
  local_1c = 0x6c5f746e;
  local_18 = 0x747369;
  ((int (*)())FUN_000d9bdc)(param_1,&local_20);
  return;
}

/* FUN_000dbb54 @ 0xdbb54 (254 bytes) */
int FUN_000dbb54(param_1, param_2)
  undefined4 param_1;
  uint param_2;
{
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined2 local_14;
  
  switch(param_2 >> 0x10 & 0x3fff) {
  case 0:
    local_20 = 0x696f705f;
    local_1c = CONCAT13((*(unsigned char *)((unsigned char *)&(local_1c) + 3)),0x746e);
    ((int (*)())FUN_000d9bdc)(param_1,&local_20);
    return;
  case 1:
    local_20 = 0x6e696c5f;
    local_1c = CONCAT22((*(unsigned short *)((unsigned char *)&(local_1c) + 2)),0x65);
    ((int (*)())FUN_000d9bdc)(param_1,&local_20);
    return;
  case 2:
    local_20 = 0x6972745f;
    local_1c = 0x6c676e61;
    local_18 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_18) + 2)),0x65);
    ((int (*)())FUN_000d9bdc)(param_1,&local_20);
    return;
  case 3:
    local_20 = 0x6e696c5f;
    local_1c = 0x64615f65;
    local_18 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_18) + 2)),0x6a);
    ((int (*)())FUN_000d9bdc)(param_1,&local_20);
    return;
  case 4:
    local_20 = 0x6972745f;
    local_1c = 0x6c676e61;
    local_18 = 0x64615f65;
    local_14 = 0x6a;
  }
  ((int (*)())FUN_000d9bdc)(param_1,&local_20);
  return;
}

/* FUN_000dbc6a @ 0xdbc6a (64 bytes) */
int FUN_000dbc6a(param_1, param_2)
  undefined4 param_1;
  uint param_2;
{
  char local_20 [20];
  
  _sprintf(local_20,"_stage(%d)",param_2 >> 0x10 & 0xff);
  ((int (*)())FUN_000d9bdc)(param_1,local_20);
  return;
}

/* FUN_000dbcaa @ 0xdbcaa (360 bytes) */
int FUN_000dbcaa(param_1, param_2)
  int param_1;
  uint param_2;
{
  uint uVar1;
  
  ((int (*)())FUN_000dbc6a)(param_1,param_2);
  if ((int)param_2 < 0) {
    uVar1 = **(uint **)(param_1 + 8);
    *(uint **)(param_1 + 8) = *(uint **)(param_1 + 8) + 1;
    ((int (*)())FUN_000d9bdc)(param_1,"_mag(");
    ((int (*)())FUN_000dadbe)(param_1,uVar1 & 7);
    ((int (*)())FUN_000d9bdc)(param_1,")");
    ((int (*)())FUN_000d9bdc)(param_1,"_min(");
    ((int (*)())FUN_000dadbe)(param_1,uVar1 >> 3 & 7);
    ((int (*)())FUN_000d9bdc)(param_1,")");
    ((int (*)())FUN_000dabb0)(param_1,uVar1 >> 0xf & 7);
  }
  if ((param_2 & 0x40000000) == 0) {
    return;
  }
  uVar1 = **(uint **)(param_1 + 8);
  *(uint **)(param_1 + 8) = *(uint **)(param_1 + 8) + 1;
  ((int (*)())FUN_000d9bdc)(param_1,"_xoffset(");
  ((int (*)())FUN_000da7cc)(param_1,uVar1 & 0xff,7,1);
  ((int (*)())FUN_000d9bdc)(param_1,")");
  ((int (*)())FUN_000d9bdc)(param_1,"_yoffset(");
  ((int (*)())FUN_000da7cc)(param_1,uVar1 >> 8 & 0xff,7,1);
  ((int (*)())FUN_000d9bdc)();
  return;
}

/* FUN_000dbe12 @ 0xdbe12 (31 bytes) */
int FUN_000dbe12(param_1, param_2)
  undefined4 param_1;
  uint param_2;
{
  if ((param_2 & 0x10000) == 0) {
    return;
  }
  ((int (*)())FUN_000d9bdc)();
  return;
}

/* FUN_000dbe32 @ 0xdbe32 (31 bytes) */
int FUN_000dbe32(param_1, param_2)
  undefined4 param_1;
  uint param_2;
{
  if ((param_2 & 0x10000) == 0) {
    return;
  }
  ((int (*)())FUN_000d9bdc)();
  return;
}

/* FUN_000dbe52 @ 0xdbe52 (31 bytes) */
int FUN_000dbe52(param_1, param_2)
  undefined4 param_1;
  uint param_2;
{
  if ((param_2 & 0x1000000) == 0) {
    return;
  }
  ((int (*)())FUN_000d9bdc)();
  return;
}

/* FUN_000dbe72 @ 0xdbe72 (31 bytes) */
int FUN_000dbe72(param_1, param_2)
  undefined4 param_1;
  uint param_2;
{
  if ((param_2 & 0x1000000) == 0) {
    return;
  }
  ((int (*)())FUN_000d9bdc)();
  return;
}

/* FUN_000dbe92 @ 0xdbe92 (191 bytes) */
int FUN_000dbe92(param_1, param_2)
  int param_1;
  uint param_2;
{
  uint uVar1;
  
  ((int (*)())FUN_000dbc6a)(param_1,param_2);
  ((int (*)())FUN_000dbe72)(param_1,param_2);
  if ((param_2 >> 0x18 & 2) != 0) {
    ((int (*)())FUN_000d9bdc)(param_1,"_absolute");
  }
  ((int (*)())FUN_000daf96)(param_1,param_2);
  if ((int)param_2 < 0) {
    uVar1 = **(uint **)(param_1 + 8);
    *(uint **)(param_1 + 8) = *(uint **)(param_1 + 8) + 1;
    ((int (*)())FUN_000dae3a)(param_1,uVar1);
    if ((uVar1 & 0x2000000) != 0) {
      ((int (*)())FUN_000d9bdc)(param_1,"_qualitybias");
    }
  }
  if ((param_2 & 0x40000000) == 0) {
    return;
  }
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 4;
  ((int (*)())FUN_000da926)();
  return;
}

/* FUN_000dbf52 @ 0xdbf52 (124 bytes) */
int FUN_000dbf52(param_1, param_2)
  int param_1;
  uint param_2;
{
  undefined4 uVar1;
  
  ((int (*)())FUN_000dbc6a)(param_1,param_2);
  ((int (*)())FUN_000dbe72)(param_1,param_2);
  ((int (*)())FUN_000daf96)(param_1,param_2);
  if ((int)param_2 < 0) {
    uVar1 = **(undefined4 **)(param_1 + 8);
    *(undefined4 **)(param_1 + 8) = *(undefined4 **)(param_1 + 8) + 1;
    ((int (*)())FUN_000dae3a)(param_1,uVar1);
  }
  if ((param_2 >> 0x18 & 0x40) == 0) {
    return;
  }
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 4;
  ((int (*)())FUN_000da926)();
  return;
}

/* FUN_000dbfce @ 0xdbfce (317 bytes) */
int FUN_000dbfce(param_1, param_2)
  int *param_1;
  uint param_2;
{
  ((int (*)())FUN_000d9bdc)(param_1,"_matrix(");
  switch(param_2 >> 0x10 & 7) {
  case 0:
    ((int (*)())FUN_000d9bdc)(param_1,"4x4");
    ((int (*)())FUN_000d9bdc)();
    return;
  case 1:
    ((int (*)())FUN_000d9bdc)(param_1,"4x3");
    ((int (*)())FUN_000d9bdc)();
    return;
  case 2:
    ((int (*)())FUN_000d9bdc)(param_1,"3x4");
    ((int (*)())FUN_000d9bdc)();
    return;
  case 3:
    ((int (*)())FUN_000d9bdc)(param_1,"3x3");
    ((int (*)())FUN_000d9bdc)();
    return;
  case 4:
    ((int (*)())FUN_000d9bdc)(param_1,"3x2");
    ((int (*)())FUN_000d9bdc)();
    return;
  default:
    *param_1 = *param_1 + 1;
    ((int (*)())FUN_000d9bdc)(param_1,"!!!invalid!!!");
    ((int (*)())FUN_000d9bdc)();
    return;
  }
}

/* FUN_000dc120 @ 0xdc120 (230 bytes) */
int FUN_000dc120(param_1, param_2)
  int *param_1;
  uint param_2;
{
  ((int (*)())FUN_000d9bdc)(param_1,"_relop(");
  switch(param_2 >> 0x10 & 7) {
  case 0:
    ((int (*)())FUN_000d9bdc)(param_1,"ne");
    break;
  case 1:
    ((int (*)())FUN_000d9bdc)(param_1,"eq");
    break;
  case 2:
    ((int (*)())FUN_000d9bdc)(param_1,"ge");
    break;
  case 3:
    ((int (*)())FUN_000d9bdc)(param_1,"gt");
    break;
  case 4:
    ((int (*)())FUN_000d9bdc)(param_1,"le");
    break;
  case 5:
    ((int (*)())FUN_000d9bdc)(param_1,"lt");
    break;
  default:
    *param_1 = *param_1 + 1;
    ((int (*)())FUN_000d9bdc)(param_1,"!!!invalid!!!");
  }
  ((int (*)())FUN_000d9bdc)();
  return;
}

/* FUN_000dc220 @ 0xdc220 (184 bytes) */
int FUN_000dc220(param_1)
  int param_1;
{
  uint uVar1;
  char cVar2;
  char local_12b [255];
  undefined2 local_2c;
  undefined1 local_2a;
  
  uVar1 = **(uint **)(param_1 + 8);
  *(uint **)(param_1 + 8) = *(uint **)(param_1 + 8) + 1;
  cVar2 = (char)(uVar1 >> 0x10);
  if (cVar2 == '\x01') {
    local_2c = 0x7370;
    local_2a = 0;
  }
  else if (cVar2 == '\0') {
    local_2c = 0x7376;
    local_2a = 0;
  }
  else if (cVar2 == '\x02') {
    local_2c = 0x7367;
    local_2a = 0;
  }
  _sprintf(local_12b,"il_%s_%d_%d",&local_2c,uVar1 >> 8 & 0xff,uVar1 & 0xff);
  *(bool *)(param_1 + 0x218) = cVar2 == '\x01';
  ((int (*)())FUN_000d9bdc)(param_1,local_12b);
  ((int (*)())FUN_000d9c46)(param_1);
  return;
}

/* FUN_000dc2d8 @ 0xdc2d8 (737 bytes) */
int FUN_000dc2d8(param_1, param_2)
  int *param_1;
  undefined4 param_2;
{
  switch(param_2) {
  case 0:
    ((int (*)())FUN_000d9bdc)();
    return;
  case 1:
    ((int (*)())FUN_000d9bdc)();
    return;
  case 2:
    ((int (*)())FUN_000d9bdc)();
    return;
  case 3:
    ((int (*)())FUN_000d9bdc)();
    return;
  case 4:
    ((int (*)())FUN_000d9bdc)();
    return;
  case 5:
  case 0x1e:
    ((int (*)())FUN_000d9bdc)();
    return;
  case 6:
    ((int (*)())FUN_000d9bdc)();
    return;
  default:
    *param_1 = *param_1 + 1;
    break;
  case 8:
    ((int (*)())FUN_000d9bdc)();
    return;
  case 9:
    ((int (*)())FUN_000d9bdc)();
    return;
  case 10:
    ((int (*)())FUN_000d9bdc)();
    return;
  case 0xb:
    break;
  case 0xc:
    break;
  case 0xd:
    ((int (*)())FUN_000d9bdc)();
    return;
  case 0xe:
    break;
  case 0xf:
    break;
  case 0x10:
    break;
  case 0x11:
    break;
  case 0x12:
    break;
  case 0x13:
    break;
  case 0x14:
    break;
  case 0x15:
    ((int (*)())FUN_000d9bdc)();
    return;
  case 0x16:
    ((int (*)())FUN_000d9bdc)();
    return;
  case 0x17:
    ((int (*)())FUN_000d9bdc)();
    return;
  case 0x18:
    ((int (*)())FUN_000d9bdc)();
    return;
  case 0x19:
    ((int (*)())FUN_000d9bdc)();
    return;
  case 0x1b:
    ((int (*)())FUN_000d9bdc)();
    return;
  case 0x1c:
    ((int (*)())FUN_000d9bdc)();
    return;
  case 0x1d:
    ((int (*)())FUN_000d9bdc)();
    return;
  case 0x1f:
    ((int (*)())FUN_000d9bdc)();
    return;
  case 0x20:
    ((int (*)())FUN_000d9bdc)();
    return;
  }
  ((int (*)())FUN_000d9bdc)();
  return;
}

