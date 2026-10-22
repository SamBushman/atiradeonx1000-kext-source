#include "decls.h"

/* FUN_001a1398 @ 0x1a1398 (312 bytes) */
int FUN_001a1398(param_1)
  int *param_1;
{
  int *piVar1;
  int iVar2;
  uint uVar3;
  short sVar4;
  int iVar5;
  
  do {
    iVar2 = *(int *)(param_1[4] + 0x28);
    uVar3 = *(uint *)(iVar2 + 4);
    if (uVar3 == 0) {
      sVar4 = -1;
LAB_001a1430:
      *(undefined4 *)(param_1[0x18] * 0x48 + param_1[0x2a]) = 5;
      *(undefined1 *)(param_1[0x18] * 0x48 + param_1[0x2a] + 0x12) = 0xff;
      *(undefined1 *)(param_1[0x18] * 0x48 + param_1[0x2a] + 0x10) = 1;
      *(undefined1 *)(param_1[0x18] * 0x48 + param_1[0x2a] + 0xe) = 2;
      *(short *)(param_1[0x18] * 0x48 + param_1[0x2a] + 0xc) = sVar4 - (short)param_1[0x1d];
                    
                    
      (**(code **)(*param_1 + 0x15c))(param_1);
      return;
    }
    piVar1 = (int *)0x0;
    if (uVar3 - 1 < uVar3) {
      piVar1 = (int *)((uVar3 - 1) * 4 + *(int *)(iVar2 + 8));
    }
    iVar5 = *piVar1;
    FUN_00194208(iVar2,uVar3 - 1);
    if ((*(char *)(iVar5 + 0xe) == '\x03') || (*(char *)(iVar5 + 0xe) == '\x01')) {
      sVar4 = *(short *)(iVar5 + 0xc);
      *(short *)(iVar5 + 0xc) = (short)param_1[0x18] - (short)param_1[0x1d];
      goto LAB_001a1430;
    }
    *(short *)(iVar5 + 0xc) = (short)param_1[0x18] - (short)param_1[0x1d];
  } while( true );
}

/* FUN_001a14d0 @ 0x1a14d0 (188 bytes) */
int FUN_001a14d0(param_1, param_2, param_3)
  int *param_1;
  int param_2;
  undefined4 param_3;
{
  bool bVar1;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  int iVar2;
  
  iVar2 = param_1[0x18];
  (**(code **)(*param_1 + 0x34))
            (param_1,param_3,*(undefined4 *)(param_2 + 0xdc),in_r6,in_r7,in_r8,
             *(code **)(*param_1 + 0x34));
  if ((*(int *)(param_2 + 0xdc) == 0) || (bVar1 = true, iVar2 != param_1[0x18])) {
    bVar1 = false;
  }
  ((int (*)())FUN_001a1398)(param_1);
  if (*(int *)(*(int *)(param_2 + 300) + 0x134) != 0) {
    *(undefined1 *)(param_1[0x18] * 0x48 + param_1[0x2a] + -0x3a) = 4;
  }
  if (bVar1) {
    *(undefined1 *)(param_1[0x18] * 0x48 + param_1[0x2a] + -0x44) = 1;
  }
  return;
}

/* FUN_001a158c @ 0x1a158c (704 bytes) */
int FUN_001a158c(param_1, param_2, param_3, param_4)
  int *param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  byte bVar1;
  int *loopIndex;
  int iVar3;
  int iVar4;
  uint loopIndex2;
  int a4;
  int iVar6;
  int iVar7;
  int loopRemaining;
  int iVar9;
  undefined8 uVar10;
  
  iVar4 = *(int *)(param_1[4] + 0x24);
  loopIndex = (int *)0x0;
  loopIndex2 = *(uint *)(iVar4 + 4);
  if (loopIndex2 - 1 < loopIndex2) {
    loopIndex = (int *)((loopIndex2 - 1) * 4 + *(int *)(iVar4 + 8));
  }
  iVar9 = *loopIndex;
  FUN_00194208(iVar4,loopIndex2 - 1);
  iVar4 = param_1[0x18];
  uVar10 = FUN_000e07dc(param_4,0x4b);
  if ((int)((ulonglong)uVar10 >> 0x20) == 0) {
    iVar4 = param_1[0x2a];
  }
  else {
    iVar3 = (iVar4 + -1) * 0x48;
    iVar4 = param_1[0x2a];
    iVar7 = iVar4 + iVar3;
    if ((((*(int *)(iVar4 + iVar3) == 5) && (*(char *)(iVar7 + 0xe) == '\0')) &&
        ((*(uint *)(iVar7 + 0x10) & 0xff00ff00) == 0x1000000)) &&
       (*(char *)(iVar4 + iVar9 * 0x48 + 0xf) == '\0')) {
      bVar1 = *(byte *)(iVar7 + 0x13);
      param_1[0x18] = param_1[0x18] + -1;
      param_1[0x2f] = param_1[0x2f] + 1;
      iVar3 = bVar1 + 1;
      *(int *)(param_1[4] + 0x1c) = *(int *)(param_1[4] + 0x1c) + 1;
      iVar4 = param_1[0x2a];
      goto LAB_001a168c;
    }
  }
  iVar3 = 1;
  param_1[0x2f] = 0;
LAB_001a168c:
  a4 = iVar9 * 0x48;
  *(short *)(iVar4 + a4 + 0xc) = (short)param_1[0x18] - (short)param_1[0x1d];
  loopRemaining = param_1[0x2f];
  iVar6 = param_1[0x2e];
  iVar7 = iVar6 * 4;
  param_1[iVar6 + 0x30] = iVar9;
  if (0 < loopRemaining) {
    iVar4 = param_1[0x2a];
    loopIndex = param_1 + iVar6 + 0x30;
    loopIndex2 = (uint)*(byte *)(iVar4 + a4 + 0x13);
    while( true ) {
      if (*(char *)(*loopIndex * 0x48 + iVar4 + 0xf) == '\0') {
        loopIndex2 = loopIndex2 + 1;
      }
      iVar9 = loopIndex[1];
      iVar6 = iVar4 + iVar9 * 0x48;
      if (*(char *)(iVar6 + 0xf) == '\x01') {
        loopIndex2 = loopIndex2 + 1;
      }
      *(char *)(iVar6 + 0x13) = (char)loopIndex2;
      if (loopIndex2 != 0) {
        *(undefined1 *)(iVar9 * 0x48 + param_1[0x2a] + 0x15) = 1;
      }
      loopIndex = loopIndex + 1;
      loopRemaining = loopRemaining + -1;
      if (loopRemaining == 0) break;
      iVar4 = param_1[0x2a];
    }
    iVar6 = param_1[0x2e];
  }
  param_1[0x2e] = iVar6 + -1;
  *(undefined4 *)(param_1[0x18] * 0x48 + param_1[0x2a]) = 5;
  *(undefined1 *)(param_1[0x18] * 0x48 + param_1[0x2a] + 0xe) = 0;
  *(undefined1 *)(param_1[0x18] * 0x48 + param_1[0x2a] + 0x12) = 0;
  *(undefined1 *)(param_1[0x18] * 0x48 + param_1[0x2a] + 0x10) = 1;
  *(undefined1 *)(param_1[0x18] * 0x48 + param_1[0x2a] + 0x14) = 1;
  *(char *)(param_1[0x18] * 0x48 + param_1[0x2a] + 0x13) = (char)iVar3;
  (**(code **)(*param_1 + 0x15c))
            (param_1,(int)uVar10,iVar3,iVar7,a4,iVar4,*(code **)(*param_1 + 0x15c),0);
  if (*(int *)(param_2 + 0xdc) != 0) {
    *(undefined1 *)(param_1[0x18] * 0x48 + param_1[0x2a] + -0x44) = 1;
  }
                    
                    
  (**(code **)(*param_1 + 0x34))(param_1,param_3,0);
  return;
}

/* FUN_001a184c @ 0x1a184c (208 bytes) */
int FUN_001a184c(param_1, param_2, param_3, inst, param_5)
  int param_1;
  int param_2;
  int param_3;
  undefined4 inst;
  undefined4 param_5;
{
  int iVar1;
  int operandRecord;
  undefined1 uVar3;
  int iVar4;
  
  if (param_2 != 0) {
    *(undefined2 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8) + 0xc) =
         (*(unsigned short *)((unsigned char *)&(param_5) + 2));
    iVar4 = *(int *)(param_1 + 0x60);
    iVar1 = *(int *)(param_1 + 0xa8);
    operandRecord = FUN_001054ec(inst,0);
    uVar3 = FUN_00195424(*(undefined4 *)(operandRecord + 0x10));
    *(undefined1 *)(iVar4 * 0x48 + iVar1 + 0x14) = uVar3;
  }
  if (param_3 != 0) {
    *(undefined2 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8) + 0x18) =
         (*(unsigned short *)((unsigned char *)&(param_5) + 2));
    iVar4 = *(int *)(param_1 + 0x60);
    iVar1 = *(int *)(param_1 + 0xa8);
    operandRecord = FUN_001054ec(inst,0);
    *(bool *)(iVar4 * 0x48 + iVar1 + 0x20) = *(char *)(operandRecord + 0x13) == '\0';
  }
  return;
}

/* FUN_001a191c @ 0x1a191c (560 bytes) */
int FUN_001a191c(param_1, param_2, param_3, inst)
  int param_1;
  int param_2;
  int param_3;
  int inst;
{
  int iVar1;
  byte bVar3;
  undefined1 uVar4;
  int operandRecord;
  undefined1 uVar5;
  int iVar6;
  int iVar7;
  
  switch(*(undefined4 *)(inst + 300)) {
  default:
    iVar6 = 2;
    uVar5 = 0;
    break;
  case 1:
    iVar6 = 2;
    uVar5 = 3;
    break;
  case 2:
    iVar6 = 1;
    uVar5 = 1;
    break;
  case 3:
    iVar6 = 2;
    uVar5 = 2;
    break;
  case 4:
    iVar6 = 2;
    uVar5 = 1;
    break;
  case 5:
    iVar6 = 1;
    uVar5 = 2;
  }
  bVar3 = FUN_0019545c(1,0);
  *(undefined4 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8)) = 4;
  if (param_2 != 0) {
    iVar7 = *(int *)(param_1 + 0x60);
    iVar1 = *(int *)(param_1 + 0xa8);
    operandRecord = FUN_001054ec(inst,0);
    uVar4 = FUN_00195424(*(undefined4 *)(operandRecord + 0x10));
    *(undefined1 *)(iVar7 * 0x48 + iVar1 + 0x15) = uVar4;
    if (iVar6 == 1) {
      iVar1 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8);
      *(byte *)(iVar1 + 0x2d) = bVar3 ^ *(byte *)(iVar1 + 0x2d);
    }
    else {
      iVar1 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8);
      *(byte *)(iVar1 + 0x2e) = bVar3 ^ *(byte *)(iVar1 + 0x2e);
    }
    *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8) + 0x16) = uVar5;
  }
  if (param_3 != 0) {
    iVar7 = *(int *)(param_1 + 0x60);
    iVar1 = *(int *)(param_1 + 0xa8);
    operandRecord = FUN_001054ec(inst,0);
    *(bool *)(iVar7 * 0x48 + iVar1 + 0x21) = *(char *)(operandRecord + 0x13) == '\0';
  }
  if (iVar6 == 1) {
    iVar6 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8);
    *(byte *)(iVar6 + 0x3c) = bVar3 ^ *(byte *)(iVar6 + 0x3c);
  }
  else {
    iVar6 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8);
    *(byte *)(iVar6 + 0x3d) = bVar3 ^ *(byte *)(iVar6 + 0x3d);
  }
  *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8) + 0x22) = uVar5;
  return;
}

/* FUN_001a1b64 @ 0x1a1b64 (448 bytes) */
int FUN_001a1b64(param_1, param_2, param_3, inst)
  int param_1;
  int param_2;
  int param_3;
  int inst;
{
  int iVar1;
  byte bVar2;
  undefined1 uVar3;
  int iVar4;
  int iVar5;
  undefined1 uVar6;
  int iVar7;
  
  iVar7 = *(int *)(inst + 0x98);
  iVar5 = *(int *)(inst + 0x94);
  if (iVar7 == 0x2c) {
    *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8) + 0x15) = 7;
    *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8) + 0x21) = 1;
    *(undefined4 *)(*(int *)(param_1 + 0xac) + 0x9374) = 1;
    bVar2 = (*(int *)(inst + 300) == 0) << 1;
    if ((*(uint *)(inst + 0x14) & 0x1000) != 0) {
      bVar2 = bVar2 | 1;
    }
    *(byte *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8) + 0x16) = bVar2;
    *(byte *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8) + 0x22) = bVar2;
  }
  else {
    if (iVar7 == 9) {
      iVar1 = iVar5 + 1;
      iVar4 = *(int *)(*(int *)(param_1 + 0xac) + 0x9374);
      if (iVar1 <= iVar4) {
        iVar1 = iVar4;
      }
      *(int *)(*(int *)(param_1 + 0xac) + 0x9374) = iVar1;
    }
    uVar6 = (undefined1)iVar5;
    if ((param_2 != 0) && (iVar7 != 8)) {
      *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8) + 0x16) = uVar6;
      iVar4 = *(int *)(param_1 + 0x60);
      iVar5 = *(int *)(param_1 + 0xa8);
      iVar1 = FUN_001054ec(inst,0);
      uVar3 = FUN_00195424(*(undefined4 *)(iVar1 + 0x10));
      *(undefined1 *)(iVar4 * 0x48 + iVar5 + 0x15) = uVar3;
    }
    if (param_3 != 0) {
      *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8) + 0x22) = uVar6;
      if (iVar7 == 8) {
        *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8) + 0x23) = 1;
      }
      else {
        iVar1 = *(int *)(param_1 + 0x60);
        iVar5 = *(int *)(param_1 + 0xa8);
        iVar7 = FUN_001054ec(inst,0);
        *(bool *)(iVar1 * 0x48 + iVar5 + 0x21) = *(char *)(iVar7 + 0x13) == '\0';
      }
    }
  }
  return;
}

/* FUN_001a1d24 @ 0x1a1d24 (2180 bytes) */
int FUN_001a1d24(param_1, inst, param_3, param_4)
  int *param_1;
  int inst;
  undefined4 param_3;
  int param_4;
{
  bool bVar1;
  undefined1 uVar2;
  int *a0;
  int iVar3;
  int *piVar4;
  undefined2 uVar7;
  int iVar5;
  byte bVar8;
  undefined4 uVar6;
  byte bVar10;
  uint uVar9;
  undefined4 unaff_r21;
  undefined4 unaff_r22;
  int *piVar11;
  int loopRemaining;
  int iVar13;
  undefined4 uVar14;
  int iVar15;
  uint local_78 [4];
  uint local_68 [4];
  undefined4 local_58 [4];
  undefined4 local_48;
  undefined4 local_44;
  uint local_40;
  uint local_3c [3];
  
  a0 = (int *)FUN_00105594(inst,1);
  iVar3 = (**(code **)(*a0 + 0x60))(a0);
  if (iVar3 != 0) {
    loopRemaining = FUN_001054ec(a0,1);
    uVar6 = *(undefined4 *)(loopRemaining + 0x10);
    loopRemaining = FUN_001054ec(inst,1);
    unaff_r22 = *(undefined4 *)(loopRemaining + 0x10);
    FUN_000f2bdc(&local_48,uVar6,unaff_r22);
    piVar4 = (int *)FUN_00105594(a0,1);
    FUN_00106004(inst,1,piVar4,0,param_4);
    loopRemaining = FUN_001054ec(a0,1);
    uVar6 = *(undefined4 *)(loopRemaining + 0x10);
    loopRemaining = FUN_001054ec(inst,1);
    *(undefined4 *)(loopRemaining + 0x10) = uVar6;
    unaff_r21 = local_48;
    piVar11 = a0;
  }
  else {
    piVar11 = (int *)0x0;
    piVar4 = a0;
  }
  uVar7 = (**(code **)(*param_1 + 0x158))(param_1,inst,1,param_4);
  *(undefined4 *)(param_1[0x18] * 0x48 + param_1[0x2a]) = 2;
  *(undefined2 *)(param_1[0x18] * 0x48 + param_1[0x2a] + 0xe) = uVar7;
  iVar13 = *(int *)(inst + 0x134);
  loopRemaining = *(int *)(*(int *)(inst + 0x88) + 8);
  if (loopRemaining != 0x77) {
    *(char *)(param_1[0x18] * 0x48 + param_1[0x2a] + 0x19) = (char)iVar13;
    iVar15 = param_1[0x18];
    iVar5 = param_1[0x2a];
    uVar7 = thunk_FUN_00134de8(*(undefined4 *)(param_4 + 0x6c4),inst);
    *(undefined2 *)(iVar15 * 0x48 + iVar5 + 0xc) = uVar7;
  }
  else {
    *(undefined1 *)(param_1[0x18] * 0x48 + param_1[0x2a] + 0x19) = 0;
    *(undefined2 *)(param_1[0x18] * 0x48 + param_1[0x2a] + 0xc) = 0;
    *(undefined4 *)(param_1[0x2b] + 0x9370) = 1;
  }
  iVar5 = (**(code **)(*piVar4 + 0x80))(piVar4);
  if (iVar5 == 0) {
    *(undefined4 *)(iVar13 * 4 + param_1[0x2b] + 0x9378) = 1;
  }
  if (*(int *)(PTR_DAT_001e913c + loopRemaining * 0x38 + 0xc) != -1) {
    *(char *)(param_1[0x18] * 0x48 + param_1[0x2a] + 0x1a) =
         (char)*(int *)(PTR_DAT_001e913c + loopRemaining * 0x38 + 0xc);
  }
  bVar10 = 0xc;
  iVar13 = *(int *)(iVar13 * 0xc + *(int *)(*(int *)(param_4 + 0x6c4) + 0x78) + 4);
  if (iVar13 != 2) {
    if (iVar13 < 3) {
      bVar10 = 0xe;
      if (iVar13 != 1) {
LAB_001a1f84:
        bVar10 = 0;
      }
    }
    else {
      bVar10 = 8;
      if (4 < iVar13) goto LAB_001a1f84;
    }
  }
  bVar1 = *(int *)(inst + 0x138) == 1;
  if (loopRemaining == 0x77) {
    *(undefined1 *)(param_1[0x18] * 0x48 + param_1[0x2a] + 0x1f) = 0;
    iVar13 = FUN_001054ec(inst,1);
    FUN_000f32cc(&local_44,*(undefined4 *)(iVar13 + 0x10));
    *(undefined4 *)(inst + 0x9c) = local_44;
    iVar13 = FUN_001054ec(inst,1);
    *(undefined4 *)(iVar13 + 0x10) = 0x10203;
    goto LAB_001a20d4;
  }
  if ((loopRemaining - 0x75U < 2) || (loopRemaining == 0xae)) {
    *(byte *)(param_1[0x18] * 0x48 + param_1[0x2a] + 0x1f) = bVar10 & 7;
    *(bool *)(param_1[0x18] * 0x48 + param_1[0x2a] + 0x18) = bVar1;
    iVar13 = param_1[0x18] * 0x48 + param_1[0x2a];
    if ((*(uint *)(inst + 0x14) & 0x2000) == 0) goto LAB_001a20b4;
LAB_001a20cc:
    uVar2 = 0;
  }
  else {
    *(byte *)(param_1[0x18] * 0x48 + param_1[0x2a] + 0x1f) = bVar10;
    *(bool *)(param_1[0x18] * 0x48 + param_1[0x2a] + 0x18) = bVar1;
    iVar13 = param_1[0x18] * 0x48 + param_1[0x2a];
    if ((*(uint *)(inst + 0x14) & 0x2000) != 0) goto LAB_001a20cc;
LAB_001a20b4:
    iVar5 = FUN_000e07dc(param_4,0x22);
    uVar2 = 1;
    if (iVar5 == 0) goto LAB_001a20cc;
  }
  *(undefined1 *)(iVar13 + 0x1c) = uVar2;
LAB_001a20d4:
  iVar13 = FUN_001054ec(inst,1);
  FUN_000f3470(&local_40,*(undefined4 *)(iVar13 + 0x10));
  iVar13 = param_1[0x18] * 0x48 + param_1[0x2a];
  *(uint *)(iVar13 + 0x14) = local_40 >> 2 & 0xc00000 | *(uint *)(iVar13 + 0x14) & 0xff3fffff;
  iVar13 = param_1[0x18] * 0x48 + param_1[0x2a];
  *(uint *)(iVar13 + 0x14) = (local_40 & 0x30000) << 4 | *(uint *)(iVar13 + 0x14) & 0xffcfffff;
  iVar13 = param_1[0x18] * 0x48 + param_1[0x2a];
  *(uint *)(iVar13 + 0x14) = (local_40 & 0x300) << 10 | *(uint *)(iVar13 + 0x14) & 0xfff3ffff;
  iVar13 = param_1[0x18] * 0x48 + param_1[0x2a];
  *(uint *)(iVar13 + 0x14) = (local_40 & 3) << 0x10 | *(uint *)(iVar13 + 0x14) & 0xfffcffff;
  FUN_000f3470(local_3c,*(undefined4 *)(inst + 0x140));
  iVar13 = param_1[0x18] * 0x48 + param_1[0x2a];
  *(uint *)(iVar13 + 0x14) = (local_3c[0] & 0x3000000) << 6 | *(uint *)(iVar13 + 0x14) & 0x3fffffff;
  iVar13 = param_1[0x18] * 0x48 + param_1[0x2a];
  *(uint *)(iVar13 + 0x14) = (local_3c[0] & 0x30000) << 0xc | *(uint *)(iVar13 + 0x14) & 0xcfffffff;
  iVar13 = param_1[0x18] * 0x48 + param_1[0x2a];
  *(uint *)(iVar13 + 0x14) = (local_3c[0] & 0x300) << 0x12 | *(uint *)(iVar13 + 0x14) & 0xf3ffffff;
  iVar13 = param_1[0x18] * 0x48 + param_1[0x2a];
  *(uint *)(iVar13 + 0x14) = (local_3c[0] & 3) << 0x18 | *(uint *)(iVar13 + 0x14) & 0xfcffffff;
  *(undefined1 *)(param_1[0x18] * 0x48 + param_1[0x2a] + 0x1d) = 0;
  *(undefined1 *)(param_1[0x18] * 0x48 + param_1[0x2a] + 0x1e) = 0;
  iVar5 = param_1[0x18] * 0x48 + param_1[0x2a];
  bVar10 = *(byte *)(iVar5 + 0x1d);
  iVar13 = FUN_001054ec(inst,0);
  bVar8 = FUN_00195424(*(undefined4 *)(iVar13 + 0x10));
  *(byte *)(iVar5 + 0x1d) = bVar10 | bVar8;
  iVar5 = param_1[0x18] * 0x48 + param_1[0x2a];
  bVar10 = *(byte *)(iVar5 + 0x1e);
  iVar13 = FUN_001054ec(inst,0);
  *(byte *)(iVar5 + 0x1e) = bVar10 | *(char *)(iVar13 + 0x13) == '\0';
  *(undefined2 *)(param_1[0x18] * 0x48 + param_1[0x2a] + 0x10) = 0;
  *(undefined2 *)(param_1[0x18] * 0x48 + param_1[0x2a] + 0x12) = 0;
  param_1[0x2c] = param_1[0x18];
  if (loopRemaining == 0x78) {
    loopRemaining = FUN_001054ec(inst,2);
    uVar9 = *(uint *)(loopRemaining + 0x10);
    loopRemaining = param_1[0x18] * 0x48 + param_1[0x2a];
    *(uint *)(loopRemaining + 0x14) = uVar9 >> 10 & 0xc000 | *(uint *)(loopRemaining + 0x14) & 0xffff3fff;
    loopRemaining = param_1[0x18] * 0x48 + param_1[0x2a];
    *(uint *)(loopRemaining + 0x14) = uVar9 >> 4 & 0x3000 | *(uint *)(loopRemaining + 0x14) & 0xffffcfff;
    loopRemaining = param_1[0x18] * 0x48 + param_1[0x2a];
    *(uint *)(loopRemaining + 0x14) = (uVar9 & 0x300) << 2 | *(uint *)(loopRemaining + 0x14) & 0xfffff3ff;
    loopRemaining = param_1[0x18] * 0x48 + param_1[0x2a];
    *(uint *)(loopRemaining + 0x14) = (uVar9 & 3) << 8 | *(uint *)(loopRemaining + 0x14) & 0xfffffcff;
    iVar13 = param_1[0x18];
    loopRemaining = param_1[0x2a];
    uVar14 = *(undefined4 *)(param_4 + 0x6c4);
    uVar6 = FUN_00105594(inst,2);
    uVar7 = thunk_FUN_00134de8(uVar14,uVar6);
    *(undefined2 *)(iVar13 * 0x48 + loopRemaining + 0x10) = uVar7;
    loopRemaining = FUN_001054ec(inst,3);
    uVar9 = *(uint *)(loopRemaining + 0x10);
    loopRemaining = param_1[0x18] * 0x48 + param_1[0x2a];
    *(uint *)(loopRemaining + 0x14) = uVar9 >> 0x12 & 0xc0 | *(uint *)(loopRemaining + 0x14) & 0xffffff3f;
    loopRemaining = param_1[0x18] * 0x48 + param_1[0x2a];
    *(uint *)(loopRemaining + 0x14) = uVar9 >> 0xc & 0x30 | *(uint *)(loopRemaining + 0x14) & 0xffffffcf;
    loopRemaining = param_1[0x18] * 0x48 + param_1[0x2a];
    *(uint *)(loopRemaining + 0x14) = uVar9 >> 6 & 0xc | *(uint *)(loopRemaining + 0x14) & 0xfffffff3;
    loopRemaining = param_1[0x18] * 0x48 + param_1[0x2a];
    *(uint *)(loopRemaining + 0x14) = uVar9 & 3 | *(uint *)(loopRemaining + 0x14) & 0xfffffffc;
    iVar13 = param_1[0x18];
    loopRemaining = param_1[0x2a];
    uVar14 = *(undefined4 *)(param_4 + 0x6c4);
    uVar6 = FUN_00105594(inst,3);
    uVar7 = thunk_FUN_00134de8(uVar14,uVar6);
    *(undefined2 *)(iVar13 * 0x48 + loopRemaining + 0x12) = uVar7;
  }
  if (iVar3 != 0) {
    iVar3 = 0;
    loopRemaining = 4;
    do {
      *(undefined4 *)(iVar3 + (int)local_78) = 0;
      *(undefined4 *)(iVar3 + (int)local_58) = 0;
      *(undefined4 *)(iVar3 + (int)local_68) = 0;
      iVar3 = iVar3 + 4;
      loopRemaining = loopRemaining + -1;
    } while (loopRemaining != 0);
    (**(code **)(*param_1 + 0xf8))(param_1,1,local_58,local_78,0,unaff_r21);
    (**(code **)(*param_1 + 0x108))(param_1,1,local_78,piVar11,unaff_r22);
    (**(code **)(*param_1 + 0x10c))(param_1,1,local_68,piVar11,unaff_r22);
    FUN_00106004(inst,1,piVar11,0,param_4);
    iVar3 = FUN_001054ec(inst,1);
    *(undefined4 *)(iVar3 + 0x10) = unaff_r22;
    iVar3 = param_1[0x18] * 0x48 + param_1[0x2a];
    *(uint *)(iVar3 + 0x14) = (local_78[1] & 3) << 0x16 | *(uint *)(iVar3 + 0x14) & 0xff3fffff;
    iVar3 = param_1[0x18] * 0x48 + param_1[0x2a];
    *(uint *)(iVar3 + 0x14) = (local_78[1] & 0x18) << 0x11 | *(uint *)(iVar3 + 0x14) & 0xffcfffff;
    iVar3 = param_1[0x18] * 0x48 + param_1[0x2a];
    *(uint *)(iVar3 + 0x14) = (local_78[1] & 0xc0) << 0xc | *(uint *)(iVar3 + 0x14) & 0xfff3ffff;
    iVar3 = param_1[0x18] * 0x48 + param_1[0x2a];
    *(uint *)(iVar3 + 0x14) = (local_68[1] & 0x600) << 7 | *(uint *)(iVar3 + 0x14) & 0xfffcffff;
  }
  return;
}

/* FUN_001a25a8 @ 0x1a25a8 (692 bytes) */
int FUN_001a25a8(param_1, inst, param_3, param_4)
  int *param_1;
  int inst;
  undefined4 param_3;
  uint param_4;
{
  int inst2;
  undefined4 uVar2;
  int iVar3;
  int operandRecord;
  uint uVar5;
  undefined4 a3;
  int iVar6;
  undefined1 uVar7;
  undefined1 auStack_48 [40];
  
  inst2 = FUN_001043f0(0x12,param_1[3]);
  uVar2 = FUN_00105594(inst,1);
  FUN_00106004(inst2,1,uVar2,0,param_1[3]);
  iVar6 = inst2 + 0xa4;
  iVar3 = FUN_001054ec(inst,1);
  uVar2 = *(undefined4 *)(iVar3 + 0x10);
  iVar3 = FUN_001054ec(inst2,1);
  uVar5 = *(uint *)(inst + 0xb8);
  *(undefined4 *)(iVar3 + 0x10) = uVar2;
  FUN_00103d50(iVar6,2,uVar5 >> 1 & 1);
  iVar3 = inst2 + 0xbc;
  FUN_00103d50(iVar6,1,*(uint *)(inst + 0xb8) & 1);
  uVar2 = FUN_00105594(inst,2);
  a3 = 0;
  FUN_00106004(inst2,2,uVar2,0,param_1[3]);
  operandRecord = FUN_001054ec(inst,2);
  uVar2 = *(undefined4 *)(operandRecord + 0x10);
  operandRecord = FUN_001054ec(inst2,2);
  uVar5 = *(uint *)(inst + 0xd0);
  *(undefined4 *)(operandRecord + 0x10) = uVar2;
  FUN_00103d50(iVar3,2,uVar5 >> 1 & 1);
  uVar7 = 2;
  FUN_00103d50(iVar3,1,*(uint *)(inst + 0xd0) & 1);
  *(undefined4 *)(inst2 + 0x9c) = 0x10101;
  operandRecord = FUN_001054ec(inst2,0);
  *(undefined4 *)(operandRecord + 0xc) = 0;
  *(undefined4 *)(operandRecord + 8) = 0;
  switch(*(undefined4 *)(inst + 300)) {
  case 0:
    uVar7 = 0;
    FUN_00103d50(iVar3,1,*(uint *)(inst + 0xd0) & 1 ^ 1);
    break;
  case 1:
    uVar7 = 3;
    FUN_00103d50(iVar3,1,*(uint *)(inst + 0xd0) & 1 ^ 1);
    break;
  case 2:
    uVar5 = *(uint *)(inst + 0xb8);
    goto LAB_001a2784;
  case 3:
    uVar5 = *(uint *)(inst + 0xd0);
    goto LAB_001a27a4;
  case 4:
    uVar5 = *(uint *)(inst + 0xd0);
    iVar6 = iVar3;
LAB_001a2784:
    uVar7 = 1;
    FUN_00103d50(iVar6,1,uVar5 & 1 ^ 1);
    break;
  case 5:
    uVar5 = *(uint *)(inst + 0xb8);
    iVar3 = iVar6;
LAB_001a27a4:
    uVar7 = 2;
    FUN_00103d50(iVar3,1,uVar5 & 1 ^ 1);
  }
  FUN_001940a8(auStack_48);
  FUN_00193f64(auStack_48,inst2);
  (**(code **)(*param_1 + 0x34))(param_1,auStack_48,param_3,a3);
  *(undefined1 *)(param_1[0x18] * 0x48 + param_1[0x2a] + -5) = 0;
  *(undefined1 *)(param_1[0x18] * 0x48 + param_1[0x2a] + -4) = uVar7;
  *(undefined1 *)(param_1[0x18] * 0x48 + param_1[0x2a] + -0x34) = 0;
  *(undefined1 *)(param_1[0x18] * 0x48 + param_1[0x2a] + -0x33) = 0;
  *(undefined1 *)(param_1[0x18] * 0x48 + param_1[0x2a] + -3) = 1;
  return;
}

/* FUN_001a2878 @ 0x1a2878 (284 bytes) */
int FUN_001a2878(param_1, param_2)
  int *param_1;
  undefined4 param_2;
{
  int iVar1;
  int *piVar2;
  undefined4 in_r5;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  int iVar3;
  uint uVar4;
  uint *puVar5;
  
  *(undefined4 *)(param_1[0x18] * 0x48 + param_1[0x2a]) = 5;
  *(undefined1 *)(param_1[0x18] * 0x48 + param_1[0x2a] + 0x12) = 0;
  *(undefined1 *)(param_1[0x18] * 0x48 + param_1[0x2a] + 0xe) = 1;
  *(char *)(param_1[0x18] * 0x48 + param_1[0x2a] + 0x18) = (char)param_2;
  (**(code **)(*param_1 + 0x15c))(param_1,param_2,in_r5,in_r6,in_r7,in_r8,*param_1);
  *(short *)(param_1[0x18] * 0x48 + param_1[0x2a] + -0x3c) = (short)param_1[0x18] + -1;
  iVar1 = param_1[0x18];
  puVar5 = *(uint **)(param_1[4] + 0x28);
  iVar3 = param_1[0x2a];
  uVar4 = puVar5[1];
  if (uVar4 < *puVar5) {
    _memset(uVar4 * 4 + puVar5[2],0,4);
    piVar2 = (int *)(uVar4 * 4 + puVar5[2]);
    puVar5[1] = uVar4 + 1;
  }
  else {
    piVar2 = (int *)FUN_0019423c(puVar5,uVar4);
  }
  *piVar2 = iVar1 * 0x48 + iVar3 + -0x48;
  return;
}

/* FUN_001a2994 @ 0x1a2994 (380 bytes) */
int FUN_001a2994(param_1, param_2, param_3)
  int *param_1;
  int param_2;
  int param_3;
{
  int iVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  uint *puVar5;
  
  *(undefined4 *)(param_1[0x18] * 0x48 + param_1[0x2a]) = 5;
  *(undefined1 *)(param_1[0x18] * 0x48 + param_1[0x2a] + 0x12) = 0xff;
  if (param_3 == 0) {
    *(undefined1 *)(param_1[0x18] * 0x48 + param_1[0x2a] + 0xe) = 5;
  }
  else {
    *(undefined1 *)(param_1[0x18] * 0x48 + param_1[0x2a] + 0xe) = 6;
  }
  if (param_2 < 1) {
    *(undefined1 *)(param_1[0x18] * 0x48 + param_1[0x2a] + 0x15) = 0;
  }
  else {
    *(undefined1 *)(param_1[0x18] * 0x48 + param_1[0x2a] + 0x15) = 1;
  }
  *(char *)(param_1[0x18] * 0x48 + param_1[0x2a] + 0x13) = (char)param_2;
  (**(code **)(*param_1 + 0x15c))(param_1);
  *(short *)(param_1[0x18] * 0x48 + param_1[0x2a] + -0x3c) = (short)param_1[0x18] + -1;
  iVar1 = param_1[0x18];
  puVar5 = *(uint **)(param_1[4] + 0x28);
  iVar3 = param_1[0x2a];
  uVar4 = puVar5[1];
  if (uVar4 < *puVar5) {
    _memset(uVar4 * 4 + puVar5[2],0,4);
    piVar2 = (int *)(uVar4 * 4 + puVar5[2]);
    puVar5[1] = uVar4 + 1;
  }
  else {
    piVar2 = (int *)FUN_0019423c(puVar5,uVar4);
  }
  *piVar2 = iVar1 * 0x48 + iVar3 + -0x48;
  return;
}

/* FUN_001a2b10 @ 0x1a2b10 (248 bytes) */
int FUN_001a2b10(param_1, param_2, inst, param_4, param_5, param_6)
  int param_1;
  int param_2;
  undefined4 inst;
  undefined4 param_4;
  int param_5;
  undefined4 param_6;
{
  int callResult;
  uint uVar2;
  int local_38 [7];
  
  local_38[0] = 0;
  callResult = FUN_001a0fe4(inst,local_38);
  if (local_38[0] == 0) {
    uVar2 = FUN_000e9184(param_6,0);
    ((int (*)())FUN_001a25a8)(param_1,inst,param_5,uVar2);
    ((int (*)())FUN_001a2994)(param_1,param_2 + -1,param_4);
    *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8) + -0x36) = 0xf0;
    *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8) + -0x3d) = 1;
  }
  else if ((callResult != 0) && (((int (*)())FUN_001a2994)(param_1,param_2 + -1,param_4), param_5 != 0)) {
    *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8) + -0x44) = 1;
  }
  return;
}

/* FUN_001a2c08 @ 0x1a2c08 (264 bytes) */
int FUN_001a2c08(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int *param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  int iVar1;
  int *a0;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  
  a0 = (int *)FUN_000e7804(param_2,param_2,param_3,param_4,param_5,param_6,param_7);
  (**(code **)(*a0 + 0x14))(a0);
  FUN_0019401c(a0);
  *(undefined4 *)(param_2 + 0x130) = 0;
  iVar4 = param_1[0x18];
  (**(code **)(*param_1 + 0x34))(param_1,param_3,*(undefined4 *)(param_2 + 0xdc));
  piVar2 = (int *)0x0;
  iVar1 = *(int *)(*(int *)(param_2 + 0x134) + 0xd0);
  if (*(int *)(iVar1 + 4) != 0) {
    piVar2 = *(int **)(iVar1 + 8);
  }
  iVar1 = *piVar2;
  (**(code **)(*param_1 + 0x34))
            (param_1,iVar1 + 0x90,*(undefined4 *)(iVar1 + 0xdc),param_4,param_5,param_6,
             *(code **)(*param_1 + 0x34));
  if (((*(int *)(param_2 + 0xdc) == 0) && (*(int *)(iVar1 + 0xdc) == 0)) ||
     (uVar3 = 1, iVar4 != param_1[0x18])) {
    uVar3 = 0;
  }
  return ((int (*)())FUN_001a2b10)(param_1,*(undefined4 *)(iVar1 + 0x130),a0,
               *(undefined4 *)(*(int *)(iVar1 + 300) + 0x134),uVar3,param_2);
}

/* FUN_001a2d10 @ 0x1a2d10 (160 bytes) */
int FUN_001a2d10(param_1, param_2, param_3)
  int *param_1;
  int param_2;
  undefined4 param_3;
{
  bool bVar1;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  int iVar2;
  
  iVar2 = param_1[0x18];
  (**(code **)(*param_1 + 0x34))
            (param_1,param_3,*(undefined4 *)(param_2 + 0xdc),in_r6,in_r7,in_r8,
             *(code **)(*param_1 + 0x34));
  if ((*(int *)(param_2 + 0xdc) == 0) || (bVar1 = true, iVar2 != param_1[0x18])) {
    bVar1 = false;
  }
  ((int (*)())FUN_001a2994)(param_1,*(undefined4 *)(param_2 + 0x130),
               *(undefined4 *)(*(int *)(param_2 + 300) + 0x134));
  if (bVar1) {
    *(undefined1 *)(param_1[0x18] * 0x48 + param_1[0x2a] + -0x44) = 1;
  }
  return;
}

/* FUN_001a2db0 @ 0x1a2db0 (308 bytes) */
int FUN_001a2db0(param_1, param_2)
  int *param_1;
  int param_2;
{
  int *piVar1;
  int iVar2;
  uint uVar3;
  uint *puVar4;
  
  *(undefined4 *)(param_1[0x18] * 0x48 + param_1[0x2a]) = 5;
  *(undefined1 *)(param_1[0x18] * 0x48 + param_1[0x2a] + 0x12) = 0xf;
  *(undefined1 *)(param_1[0x18] * 0x48 + param_1[0x2a] + 0xe) = 0;
  *(undefined1 *)(param_1[0x18] * 0x48 + param_1[0x2a] + 0x14) = 2;
  if (param_2 != 0) {
    *(undefined1 *)(param_1[0x18] * 0x48 + param_1[0x2a] + 0x15) = 2;
  }
  *(undefined1 *)(param_1[0x18] * 0x48 + param_1[0x2a] + 0xb) = 1;
  iVar2 = param_1[0x18];
  puVar4 = *(uint **)(param_1[4] + 0x24);
  uVar3 = puVar4[1];
  if (uVar3 < *puVar4) {
    _memset(uVar3 * 4 + puVar4[2],0,4);
    piVar1 = (int *)(uVar3 * 4 + puVar4[2]);
    puVar4[1] = uVar3 + 1;
  }
  else {
    piVar1 = (int *)FUN_0019423c(puVar4,uVar3);
  }
  *piVar1 = iVar2;
  (**(code **)(*param_1 + 0x15c))(param_1);
  param_1[0x2e] = param_1[0x2e] + 1;
  return;
}

/* FUN_001a2ee4 @ 0x1a2ee4 (284 bytes) */
int FUN_001a2ee4(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int *param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  int *piVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  
  piVar1 = (int *)FUN_000e7804(param_2,param_2,param_3,param_4,param_5,param_6,param_7);
  (**(code **)(*piVar1 + 0x14))(piVar1);
  FUN_0019401c(piVar1);
  *(undefined4 *)(param_2 + 0x130) = 0;
  iVar4 = param_1[0x18];
  (**(code **)(*param_1 + 0x34))
            (param_1,param_3,*(undefined4 *)(param_2 + 0xdc),param_4,param_5,param_6,
             *(code **)(*param_1 + 0x34));
  if ((*(int *)(param_2 + 0xdc) == 0) || (uVar3 = 1, iVar4 != param_1[0x18])) {
    uVar3 = 0;
  }
  uVar2 = FUN_000e9184(param_2,0);
  ((int (*)())FUN_001a25a8)(param_1,piVar1,uVar3,uVar2);
  iVar5 = *(int *)(param_2 + 0x138);
  iVar4 = FUN_00194034(iVar5 + 0x90);
  if ((iVar4 < 3) && (iVar4 = FUN_000e79e8(iVar5), iVar4 != 0)) {
    piVar1 = (int *)0x0;
    if (*(int *)(*(int *)(iVar5 + 0xd0) + 4) != 0) {
      piVar1 = *(int **)(*(int *)(iVar5 + 0xd0) + 8);
    }
    uVar3 = 0;
    if (*piVar1 == *(int *)(param_2 + 0x13c)) goto LAB_001a2fe8;
  }
  uVar3 = 1;
LAB_001a2fe8:
  return ((int (*)())FUN_001a2db0)(param_1,uVar3);
}

/* FUN_001a3000 @ 0x1a3000 (556 bytes) */
int FUN_001a3000(param_1, param_2)
  int *param_1;
  int *param_2;
{
  int *piVar1;
  undefined4 a1;
  uint uVar2;
  undefined4 in_r5;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  int iVar3;
  int iVar4;
  uint *puVar5;
  longlong callResult;
  undefined8 uVar7;
  
  iVar4 = param_2[0x4e];
  callResult = FUN_00194034(iVar4 + 0x90);
  a1 = (undefined4)callResult;
  if ((callResult < 0x300000000) &&
     (uVar7 = FUN_000e79e8(iVar4), a1 = (undefined4)uVar7, (int)((ulonglong)uVar7 >> 0x20) != 0)) {
    piVar1 = (int *)0x0;
    if (*(int *)(*(int *)(iVar4 + 0xd0) + 4) != 0) {
      piVar1 = *(int **)(*(int *)(iVar4 + 0xd0) + 8);
    }
    if (*piVar1 == param_2[0x4f]) {
      return;
    }
  }
  *(undefined4 *)(param_1[0x18] * 0x48 + param_1[0x2a]) = 5;
  *(undefined1 *)(param_1[0x18] * 0x48 + param_1[0x2a] + 0xe) = 0;
  iVar4 = (**(code **)(*param_2 + 0x40))(param_2,a1,in_r5,in_r6,in_r7,in_r8,*param_2);
  if (iVar4 == 0) {
    *(undefined1 *)(param_1[0x18] * 0x48 + param_1[0x2a] + 0x12) = 0;
    *(undefined1 *)(param_1[0x18] * 0x48 + param_1[0x2a] + 0x15) = 1;
    *(undefined1 *)(param_1[0x18] * 0x48 + param_1[0x2a] + 0x13) = 1;
    *(undefined1 *)(param_1[0x18] * 0x48 + param_1[0x2a] + 0xf) = 1;
  }
  else {
    *(undefined1 *)(param_1[0x18] * 0x48 + param_1[0x2a] + 0x12) = 0xff;
  }
  piVar1 = (int *)0x0;
  iVar4 = *(int *)(param_1[4] + 0x24);
  uVar2 = *(uint *)(iVar4 + 4);
  if (uVar2 - 1 < uVar2) {
    piVar1 = (int *)((uVar2 - 1) * 4 + *(int *)(iVar4 + 8));
  }
  iVar3 = *piVar1;
  FUN_00194208(iVar4,uVar2 - 1);
  *(short *)(iVar3 * 0x48 + param_1[0x2a] + 0xc) = (short)param_1[0x18] - (short)param_1[0x1d];
  iVar4 = param_1[0x18];
  puVar5 = *(uint **)(param_1[4] + 0x24);
  uVar2 = puVar5[1];
  if (uVar2 < *puVar5) {
    _memset(uVar2 * 4 + puVar5[2],0,4);
    piVar1 = (int *)(uVar2 * 4 + puVar5[2]);
    puVar5[1] = uVar2 + 1;
  }
  else {
    piVar1 = (int *)FUN_0019423c(puVar5,uVar2);
  }
  *piVar1 = iVar4;
  if (*(int *)(param_2[0x4f] + 0xdc) != 0) {
    *(undefined1 *)(param_1[0x18] * 0x48 + param_1[0x2a] + 4) = 1;
  }
                    
                    
  (**(code **)(*param_1 + 0x15c))(param_1);
  return;
}

/* FUN_001a322c @ 0x1a322c (32 bytes) */
int FUN_001a322c()
{
  return;
}

/* FUN_001a324c @ 0x1a324c (8 bytes) */
int FUN_001a324c()
{
  return;
}

/* FUN_001a3254 @ 0x1a3254 (4 bytes) */
int FUN_001a3254()
{
  return;
}

/* FUN_001a3258 @ 0x1a3258 (4 bytes) */
int FUN_001a3258()
{
  return;
}

/* FUN_001a325c @ 0x1a325c (4 bytes) */
int FUN_001a325c()
{
  return;
}

/* FUN_001a3260 @ 0x1a3260 (4 bytes) */
int FUN_001a3260()
{
  return;
}

/* FUN_001a3264 @ 0x1a3264 (24 bytes) */
int FUN_001a3264()
{
  return;
}

/* FUN_001a327c @ 0x1a327c (84 bytes) */
int FUN_001a327c()
{
  return;
}

/* FUN_001a32d0 @ 0x1a32d0 (172 bytes) */
int FUN_001a32d0(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  undefined4 uVar1;
  
  if (DAT_001fc1d4 == (code *)0x0) {
    DAT_001fc1d4 = (code *)((int (*)())FUN_001a3580)("sprintf");
  }
                    
                    
  uVar1 = (*DAT_001fc1d4)(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
  return uVar1;
}

/* FUN_001a337c @ 0x1a337c (172 bytes) */
int FUN_001a337c(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  if (DAT_001fc1d8 == (code *)0x0) {
    DAT_001fc1d8 = (code *)((int (*)())FUN_001a3580)("printf");
  }
                    
                    
  (*DAT_001fc1d8)(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
  return;
}

/* FUN_001a3428 @ 0x1a3428 (172 bytes) */
int FUN_001a3428(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  if (DAT_001fc1dc == (code *)0x0) {
    DAT_001fc1dc = (code *)((int (*)())FUN_001a3580)("vsnprintf");
  }
                    
                    
  (*DAT_001fc1dc)(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
  return;
}

/* FUN_001a34d4 @ 0x1a34d4 (172 bytes) */
int FUN_001a34d4(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  if (DAT_001fc1e0 == (code *)0x0) {
    DAT_001fc1e0 = (code *)((int (*)())FUN_001a3580)("vsprintf");
  }
                    
                    
  (*DAT_001fc1e0)(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
  return;
}

/* FUN_001a3580 @ 0x1a3580 (164 bytes) */
int FUN_001a3580(param_1)
  undefined4 param_1;
{
  int length;
  int iVar1;
  int callResult;
  undefined4 callResult2;
  /* issue #76 (same defect class as issue #64's stack-split fixes elsewhere in this corpus):
   * local_58/acStack_54/acStack_50 are three separate locals at consecutive stock frame offsets
   * (-0x58, -0x54, -0x50 - no gaps), meant to be ONE 72-byte buffer: code builds a symbol name
   * by strcpy'ing into local_58+1 (needing far more than local_58's own declared 4 bytes) and
   * then appends a literal string constant across all three via raw word-sized stores
   * (`*(undefined4*)(local_58+iVar1)`, `acStack_50[iVar1]`, `*(undefined4*)(acStack_54+iVar1)`).
   * -O0 doesn't lay separately-declared locals out contiguously, so this crashed writing/reading
   * through whatever unrelated stack content followed the undersized local_58 on its own.
   * Merged into one real buffer with offset-preserving aliases, per the established pattern. */
  char acStack_58_combined[72];
#define local_58 (acStack_58_combined + 0)
#define acStack_54 (acStack_58_combined + 4)
#define acStack_50 (acStack_58_combined + 8)

  local_58[0] = '_';
  _strcpy(local_58 + 1,param_1);
  length = _strlen(local_58);
  *(undefined4 *)(local_58 + length) = (*(unsigned int *)((unsigned char *)&(s__LDBL128_001aa0b4) + 0));
  acStack_50[length] = s__LDBL128_001aa0b4[8];
  *(undefined4 *)(acStack_54 + length) = (*(unsigned int *)((unsigned char *)&(s__LDBL128_001aa0b4) + 4));
  callResult = _NSIsSymbolNameDefinedWithHint(local_58,"libSystem.");
  if (callResult == 0) {
    local_58[length] = '\0';
  }
  callResult2 = _NSLookupAndBindSymbolWithHint(local_58,"libSystem.");
  callResult2 = _NSAddressOfSymbol(callResult2);
  return callResult2;
}

/* FUN_001cd7bc @ 0x1cd7bc (28 bytes) */
int FUN_001cd7bc()
{
  return "pseudo";
}

/* MachineAssembler__dtor_1cd7ec @ 0x1cd7ec (36 bytes) */
int MachineAssembler__dtor_1cd7ec(this)
  undefined4 *this;
{
  *this = &PTR_FUN_001e9a40;
  return;
}

/* DListNode__dtor @ 0x1cd810 (36 bytes) */
int DListNode__dtor(param_1)
  undefined4 *param_1;
{
  *param_1 = PTR_DAT_001e8b48 + 8;
  return;
}

/* DListNode__deleting_dtor @ 0x1cd834 (56 bytes) */
int DListNode__deleting_dtor(param_1)
  undefined4 *param_1;
{
  *param_1 = PTR_DAT_001e8b48 + 8;
  if (param_1 == (undefined4 *)0x0) {
    return;
  }
  return FUN_00193cc0(param_1[-1],param_1 + -1);
}

/* IRPseudo__dtor @ 0x1cd86c (68 bytes) */
int IRPseudo__dtor(param_1)
  undefined4 *param_1;
{
  undefined *puVar1;
  undefined *puVar2;
  
  puVar2 = PTR_DAT_001e8b4c;
  *param_1 = PTR_DAT_001e8b50 + 8;
  puVar1 = PTR_DAT_001e8b48;
  *param_1 = puVar2 + 8;
  *param_1 = puVar1 + 8;
  return;
}

/* IRPseudo__deleting_dtor @ 0x1cd8b0 (88 bytes) */
int IRPseudo__deleting_dtor(param_1)
  undefined4 *param_1;
{
  undefined *puVar1;
  undefined *puVar2;
  
  puVar2 = PTR_DAT_001e8b4c;
  *param_1 = PTR_DAT_001e8b50 + 8;
  puVar1 = PTR_DAT_001e8b48;
  *param_1 = puVar2 + 8;
  *param_1 = puVar1 + 8;
  if (param_1 == (undefined4 *)0x0) {
    return;
  }
  return FUN_00193cc0(param_1[-1],param_1 + -1);
}

/* IRInst__dtor_1cd908 @ 0x1cd908 (104 bytes) */
int IRInst__dtor_1cd908(this)
  undefined4 *this;
{
  undefined *puVar1;
  
  puVar1 = PTR_DAT_001e8b50 + 8;
  *this = &PTR_FUN_001e9998;
  *this = puVar1;
  puVar1 = PTR_DAT_001e8b48 + 8;
  *this = PTR_DAT_001e8b4c + 8;
  *this = puVar1;
  if (this == (undefined4 *)0x0) {
    return;
  }
  return FUN_00193cc0(this[-1],this + -1);
}

/* IRInst__dtor_1cd970 @ 0x1cd970 (84 bytes) */
int IRInst__dtor_1cd970(this)
  undefined4 *this;
{
  undefined *puVar1;
  
  puVar1 = PTR_DAT_001e8b50 + 8;
  *this = &PTR_FUN_001e97a0;
  *this = puVar1;
  puVar1 = PTR_DAT_001e8b48 + 8;
  *this = PTR_DAT_001e8b4c + 8;
  *this = puVar1;
  return;
}

/* IRInst__dtor_1cd9c4 @ 0x1cd9c4 (104 bytes) */
int IRInst__dtor_1cd9c4(this)
  undefined4 *this;
{
  undefined *puVar1;
  
  puVar1 = PTR_DAT_001e8b50 + 8;
  *this = &PTR_FUN_001e97a0;
  *this = puVar1;
  puVar1 = PTR_DAT_001e8b48 + 8;
  *this = PTR_DAT_001e8b4c + 8;
  *this = puVar1;
  if (this == (undefined4 *)0x0) {
    return;
  }
  return FUN_00193cc0(this[-1],this + -1);
}

/* IRInst__dtor_1cda2c @ 0x1cda2c (84 bytes) */
int IRInst__dtor_1cda2c(this)
  undefined4 *this;
{
  undefined *puVar1;
  
  puVar1 = PTR_DAT_001e8b50 + 8;
  *this = &PTR_FUN_001e9848;
  *this = puVar1;
  puVar1 = PTR_DAT_001e8b48 + 8;
  *this = PTR_DAT_001e8b4c + 8;
  *this = puVar1;
  return;
}

/* IRInst__dtor_1cda80 @ 0x1cda80 (104 bytes) */
int IRInst__dtor_1cda80(this)
  undefined4 *this;
{
  undefined *puVar1;
  
  puVar1 = PTR_DAT_001e8b50 + 8;
  *this = &PTR_FUN_001e9848;
  *this = puVar1;
  puVar1 = PTR_DAT_001e8b48 + 8;
  *this = PTR_DAT_001e8b4c + 8;
  *this = puVar1;
  if (this == (undefined4 *)0x0) {
    return;
  }
  return FUN_00193cc0(this[-1],this + -1);
}

/* IRInst__dtor_1cdae8 @ 0x1cdae8 (84 bytes) */
int IRInst__dtor_1cdae8(this)
  undefined4 *this;
{
  undefined *puVar1;
  
  puVar1 = PTR_DAT_001e8b50 + 8;
  *this = &PTR_FUN_001e98f0;
  *this = puVar1;
  puVar1 = PTR_DAT_001e8b48 + 8;
  *this = PTR_DAT_001e8b4c + 8;
  *this = puVar1;
  return;
}

/* IRInst__dtor_1cdb3c @ 0x1cdb3c (104 bytes) */
int IRInst__dtor_1cdb3c(this)
  undefined4 *this;
{
  undefined *puVar1;
  
  puVar1 = PTR_DAT_001e8b50 + 8;
  *this = &PTR_FUN_001e98f0;
  *this = puVar1;
  puVar1 = PTR_DAT_001e8b48 + 8;
  *this = PTR_DAT_001e8b4c + 8;
  *this = puVar1;
  if (this == (undefined4 *)0x0) {
    return;
  }
  return FUN_00193cc0(this[-1],this + -1);
}

/* IRInst__dtor_1cdba4 @ 0x1cdba4 (84 bytes) */
int IRInst__dtor_1cdba4(this)
  undefined4 *this;
{
  undefined *puVar1;
  
  puVar1 = PTR_DAT_001e8b50 + 8;
  *this = &PTR_FUN_001e9998;
  *this = puVar1;
  puVar1 = PTR_DAT_001e8b48 + 8;
  *this = PTR_DAT_001e8b4c + 8;
  *this = puVar1;
  return;
}

/* FUN_001cdc64 @ 0x1cdc64 (28 bytes) */
int FUN_001cdc64()
{
  return "SIMPLE";
}

/* FUN_001cdc88 @ 0x1cdc88 (28 bytes) */
int FUN_001cdc88()
{
  return "ENTRY";
}

/* FUN_001cdcac @ 0x1cdcac (28 bytes) */
int FUN_001cdcac()
{
  return "ANY";
}

/* FUN_001cdcd0 @ 0x1cdcd0 (28 bytes) */
int FUN_001cdcd0()
{
  return "EXIT";
}

/* FUN_001cdcfc @ 0x1cdcfc (28 bytes) */
int FUN_001cdcfc()
{
  return "LOOP_FOOTER";
}

/* FUN_001cdd20 @ 0x1cdd20 (28 bytes) */
int FUN_001cdd20()
{
  return "POST_LOOP_FOOTER";
}

/* FUN_001cdd44 @ 0x1cdd44 (28 bytes) */
int FUN_001cdd44()
{
  return "IF_HEADER";
}

/* FUN_001cdd60 @ 0x1cdd60 (28 bytes) */
int FUN_001cdd60()
{
  return "IF_HEADER_S";
}

/* FUN_001cdd84 @ 0x1cdd84 (28 bytes) */
int FUN_001cdd84()
{
  return "IF_FOOTER";
}

/* FUN_001cdda8 @ 0x1cdda8 (28 bytes) */
int FUN_001cdda8()
{
  return "IF_FOOTER_S";
}

/* FUN_001cddcc @ 0x1cddcc (28 bytes) */
int FUN_001cddcc()
{
  return "BREAK";
}

/* FUN_001cddf0 @ 0x1cddf0 (28 bytes) */
int FUN_001cddf0()
{
  return "CONTINUE";
}

/* FUN_001cde18 @ 0x1cde18 (28 bytes) */
int FUN_001cde18()
{
  return "FUNC_END";
}

/* EntryBlock__deleting_dtor @ 0x1cde34 (104 bytes) */
int EntryBlock__deleting_dtor(this)
  undefined4 *this;
{
  *this = &PTR_FUN_001e9f28;
  Block__dtor_ea270(this);
  if (this != (undefined4 *)0x0) {
    FUN_00193cc0(this[-1],this + -1);
    return;
  }
  return;
}

/* AnyBlock__dtor @ 0x1cde9c (36 bytes) */
int AnyBlock__dtor(param_1)
  undefined4 *param_1;
{
  *param_1 = PTR_DAT_001e8b58 + 8;
  return Block__dtor_ea270(param_1);
}

/* AnyBlock__deleting_dtor @ 0x1cdec0 (104 bytes) */
int AnyBlock__deleting_dtor(param_1)
  undefined4 *param_1;
{
  *param_1 = PTR_DAT_001e8b58 + 8;
  Block__dtor_ea270(param_1);
  if (param_1 != (undefined4 *)0x0) {
    FUN_00193cc0(param_1[-1],param_1 + -1);
    return;
  }
  return;
}

/* FuncEndBlock__dtor @ 0x1cdf28 (36 bytes) */
int FuncEndBlock__dtor(this2)
  undefined4 *this2;
{
  *this2 = &PTR_FUN_001e9b60;
  return Block__dtor_ea270(this2);
}


/* issue: auto-generated aliases bridging data.s/code.s references (written
 * without a leading underscore, matching the raw stock-binary symbol name)
 * against the real compiled C symbols (gcc adds one underscore automatically).
 * Needed because ld64 (required for this PPC binary's size - stock ld breaks on
 * large PPC links) does not silently reconcile this the way stock ld did. */
asm(".globl FUN_001a14d0");
asm(".set FUN_001a14d0, _FUN_001a14d0");
asm(".globl FUN_001a158c");
asm(".set FUN_001a158c, _FUN_001a158c");
asm(".globl FUN_001a184c");
asm(".set FUN_001a184c, _FUN_001a184c");
asm(".globl FUN_001a191c");
asm(".set FUN_001a191c, _FUN_001a191c");
asm(".globl FUN_001a1b64");
asm(".set FUN_001a1b64, _FUN_001a1b64");
asm(".globl FUN_001a1d24");
asm(".set FUN_001a1d24, _FUN_001a1d24");
asm(".globl FUN_001a2878");
asm(".set FUN_001a2878, _FUN_001a2878");
asm(".globl FUN_001a2c08");
asm(".set FUN_001a2c08, _FUN_001a2c08");
asm(".globl FUN_001a2d10");
asm(".set FUN_001a2d10, _FUN_001a2d10");
asm(".globl FUN_001a2ee4");
asm(".set FUN_001a2ee4, _FUN_001a2ee4");
asm(".globl FUN_001a3000");
asm(".set FUN_001a3000, _FUN_001a3000");
asm(".globl FUN_001cd7bc");
asm(".set FUN_001cd7bc, _FUN_001cd7bc");
asm(".globl FUN_001cd7ec");
asm(".set FUN_001cd7ec, _MachineAssembler__dtor_1cd7ec");
asm(".globl FUN_001cd810");
asm(".set FUN_001cd810, _DListNode__dtor");
asm(".globl FUN_001cd834");
asm(".set FUN_001cd834, _DListNode__deleting_dtor");
asm(".globl FUN_001cd86c");
asm(".set FUN_001cd86c, _IRPseudo__dtor");
asm(".globl FUN_001cd8b0");
asm(".set FUN_001cd8b0, _IRPseudo__deleting_dtor");
asm(".globl FUN_001cd908");
asm(".set FUN_001cd908, _IRInst__dtor_1cd908");
asm(".globl FUN_001cd970");
asm(".set FUN_001cd970, _IRInst__dtor_1cd970");
asm(".globl FUN_001cd9c4");
asm(".set FUN_001cd9c4, _IRInst__dtor_1cd9c4");
asm(".globl FUN_001cda2c");
asm(".set FUN_001cda2c, _IRInst__dtor_1cda2c");
asm(".globl FUN_001cda80");
asm(".set FUN_001cda80, _IRInst__dtor_1cda80");
asm(".globl FUN_001cdae8");
asm(".set FUN_001cdae8, _IRInst__dtor_1cdae8");
asm(".globl FUN_001cdb3c");
asm(".set FUN_001cdb3c, _IRInst__dtor_1cdb3c");
asm(".globl FUN_001cdba4");
asm(".set FUN_001cdba4, _IRInst__dtor_1cdba4");
asm(".globl FUN_001cdc64");
asm(".set FUN_001cdc64, _FUN_001cdc64");
asm(".globl FUN_001cdc88");
asm(".set FUN_001cdc88, _FUN_001cdc88");
asm(".globl FUN_001cdcac");
asm(".set FUN_001cdcac, _FUN_001cdcac");
asm(".globl FUN_001cdcd0");
asm(".set FUN_001cdcd0, _FUN_001cdcd0");
asm(".globl FUN_001cdcfc");
asm(".set FUN_001cdcfc, _FUN_001cdcfc");
asm(".globl FUN_001cdd20");
asm(".set FUN_001cdd20, _FUN_001cdd20");
asm(".globl FUN_001cdd44");
asm(".set FUN_001cdd44, _FUN_001cdd44");
asm(".globl FUN_001cdd60");
asm(".set FUN_001cdd60, _FUN_001cdd60");
asm(".globl FUN_001cdd84");
asm(".set FUN_001cdd84, _FUN_001cdd84");
asm(".globl FUN_001cdda8");
asm(".set FUN_001cdda8, _FUN_001cdda8");
asm(".globl FUN_001cddcc");
asm(".set FUN_001cddcc, _FUN_001cddcc");
asm(".globl FUN_001cddf0");
asm(".set FUN_001cddf0, _FUN_001cddf0");
asm(".globl FUN_001cde18");
asm(".set FUN_001cde18, _FUN_001cde18");
asm(".globl FUN_001cde34");
asm(".set FUN_001cde34, _EntryBlock__deleting_dtor");
asm(".globl FUN_001cde9c");
asm(".set FUN_001cde9c, _AnyBlock__dtor");
asm(".globl FUN_001cdec0");
asm(".set FUN_001cdec0, _AnyBlock__deleting_dtor");
asm(".globl FUN_001cdf28");
asm(".set FUN_001cdf28, _FuncEndBlock__dtor");
