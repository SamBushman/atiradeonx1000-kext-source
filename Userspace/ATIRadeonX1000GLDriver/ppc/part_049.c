#include "decls.h"

/* FUN_00186510 @ 0x186510 (1400 bytes) */
int FUN_00186510(inst, param_2, param_3, param_4)
  int inst;
  undefined4 *param_2;
  undefined4 *param_3;
  int param_4;
{
  bool bVar1;
  byte bVar2;
  undefined4 uVar3;
  char *loopIndex5;
  int loopIndex2;
  int loopIndex3;
  uint uVar7;
  int loopIndex4;
  int *piVar9;
  int *loopIndex6;
  undefined1 *puVar11;
  int loopIndex;
  int local_78;
  uint local_74;
  uint local_70;
  int local_6c;
  uint local_68;
  undefined4 local_64;
  int local_60;
  undefined4 uStack_5c;
  int local_58 [4];
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c [3];
  
  loopIndex2 = IRInst__getOperandRecord(inst,1);
  local_60 = *(int *)(loopIndex2 + 0x10);
  loopIndex2 = IRInst__getOperandRecord(inst,2);
  local_78 = *(int *)(loopIndex2 + 0x10);
  if (local_60 == local_78) {
    return 1;
  }
  loopIndex2 = IRInst__getOperandRecord(inst,0);
  loopIndex4 = 0;
  local_64 = *(undefined4 *)(loopIndex2 + 0x10);
  do {
    loopIndex2 = 0;
    loopIndex5 = &DAT_001b0228 + loopIndex4 * 4;
    loopIndex = 4;
    while ((*(char *)((int)&local_64 + loopIndex2) != '\0' ||
           ((*(char *)((int)&local_78 + loopIndex2) == *(char *)((int)&local_60 + loopIndex2) &&
            (*(char *)((int)&local_78 + loopIndex2) == *loopIndex5))))) {
      loopIndex2 = loopIndex2 + 1;
      loopIndex5 = loopIndex5 + 1;
      loopIndex = loopIndex + -1;
      if (loopIndex == 0) {
        return 1;
      }
    }
    bVar1 = loopIndex4 != 4;
    loopIndex4 = loopIndex4 + 1;
  } while (bVar1);
  loopIndex2 = FUN_000f31e8(inst,1);
  if ((loopIndex2 == 0) && (loopIndex2 = FUN_000f31e8(inst,2), loopIndex2 == 0)) {
    *(int *)(*(int *)(param_4 + 0x6c4) + 0x204) = *(int *)(*(int *)(param_4 + 0x6c4) + 0x204) + 1;
    return 0;
  }
  piVar9 = (int *)*param_2;
  loopIndex4 = 1;
  loopIndex6 = (int *)*param_3;
  loopIndex2 = FUN_000f31e8(inst,1);
  if (loopIndex2 != 0) {
    loopIndex4 = 2;
    local_60 = local_78;
    piVar9 = loopIndex6;
  }
  loopIndex = *(int *)(param_4 + 0x6c4);
  loopIndex2 = IRInst__getOperandRecord(inst,0);
  local_74 = *(uint *)(loopIndex2 + 0x10);
  loopIndex2 = IRInst__getOperandRecord(piVar9,0);
  local_70 = *(uint *)(loopIndex2 + 0x10);
  local_6c = DAT_001b0224;
  if ((piVar9[5] & 0x200U) != 0) {
    *(int *)(*(int *)(param_4 + 0x6c4) + 0x204) = *(int *)(*(int *)(param_4 + 0x6c4) + 0x204) + 1;
    loopIndex2 = IRInst__getOperandRecord(piVar9,piVar9[0x21]);
    loopIndex3 = 0;
    local_6c = *(int *)(loopIndex2 + 0x10);
    loopIndex2 = 4;
    do {
      if ((*(byte *)((int)&local_60 + loopIndex3) != 4) &&
         (*(char *)((int)&local_6c + (uint)*(byte *)((int)&local_60 + loopIndex3)) != '\x04')) {
        bVar1 = false;
        goto LAB_00186708;
      }
      loopIndex3 = loopIndex3 + 1;
      loopIndex2 = loopIndex2 + -1;
    } while (loopIndex2 != 0);
  }
  bVar1 = true;
LAB_00186708:
  local_68 = DAT_001b0220;
  if (bVar1) {
    loopIndex2 = FUN_0011379c(param_4,piVar9);
    if (loopIndex2 == 0) {
      loopIndex2 = OpcodeTraits__flagBit8(*(undefined4 *)(piVar9[0x22] + 8),param_4);
      if (loopIndex2 == 0) goto LAB_00186a60;
      loopIndex2 = IRInst__hasSingleUse(piVar9,loopIndex);
      uVar3 = DAT_001b0220;
      if (loopIndex2 == 0) {
        loopIndex2 = 0;
        loopIndex3 = 4;
        do {
          if (((*(char *)((int)&local_74 + loopIndex2) == '\0') &&
              (*(char *)((int)&local_70 + loopIndex2) != '\0')) &&
             ((*(char *)((int)&local_70 + loopIndex2) != '\x01' ||
              (*(char *)((int)&local_6c + loopIndex2) != '\x04')))) goto LAB_00186a60;
          loopIndex2 = loopIndex2 + 1;
          loopIndex3 = loopIndex3 + -1;
        } while (loopIndex3 != 0);
        uVar7 = (local_74 << 0x18 | (local_74 >> 8 & 0xff) << 0x10 | (local_74 >> 0x10 & 0xff) << 8
                | local_74 >> 0x18) &
                (local_70 << 0x18 | (local_70 >> 8 & 0xff) << 0x10 | (local_70 >> 0x10 & 0xff) << 8
                | local_70 >> 0x18);
        local_68 = uVar7 << 0x18 | (uVar7 & 0xff00) << 8 | uVar7 >> 8 & 0xff00 | uVar7 >> 0x18;
      }
      else {
        local_68 = local_74;
      }
      piVar9[0x27] = local_68;
      FUN_000f3908(&local_40,local_68);
      FUN_000f3340(local_3c,uVar3,local_40);
    }
    else {
      loopIndex2 = IRInst__hasSingleUse(piVar9,loopIndex);
      if (loopIndex2 == 0) {
        loopIndex2 = 0;
        loopIndex3 = 4;
        do {
          if ((*(char *)((int)&local_74 + loopIndex2) == '\0') &&
             ((*(char *)((int)&local_70 + loopIndex2) != '\x01' ||
              (*(char *)((int)&local_6c + loopIndex2) != '\x04')))) goto LAB_00186a60;
          loopIndex2 = loopIndex2 + 1;
          loopIndex3 = loopIndex3 + -1;
        } while (loopIndex3 != 0);
        uVar7 = (local_74 << 0x18 | (local_74 >> 8 & 0xff) << 0x10 | (local_74 >> 0x10 & 0xff) << 8
                | local_74 >> 0x18) &
                (local_70 << 0x18 | (local_70 >> 8 & 0xff) << 0x10 | (local_70 >> 0x10 & 0xff) << 8
                | local_70 >> 0x18);
        local_68 = uVar7 << 0x18 | (uVar7 & 0xff00) << 8 | uVar7 >> 8 & 0xff00 | uVar7 >> 0x18;
      }
      else {
        local_68 = local_74;
      }
      loopIndex2 = FUN_000f2e18(local_68);
      if (loopIndex2 == 0) goto LAB_00186a60;
      loopIndex3 = 1;
      piVar9[0x27] = local_68;
      loopIndex2 = IRInst__hasSingleUse(piVar9,loopIndex);
      if (loopIndex2 == 0) {
        for (; loopIndex2 = (**(code **)(*piVar9 + 0x14))(piVar9), loopIndex3 <= loopIndex2; loopIndex3 = loopIndex3 + 1) {
          loopIndex2 = IRInst__getOperandRecord(piVar9,loopIndex3);
          (&uStack_5c)[loopIndex3] = *(undefined4 *)(loopIndex2 + 0x10);
        }
      }
      else {
        loopIndex6 = local_58;
        for (; loopIndex2 = (**(code **)(*piVar9 + 0x14))(piVar9), loopIndex3 <= loopIndex2; loopIndex3 = loopIndex3 + 1) {
          *loopIndex6 = DAT_001b0224;
          loopIndex6 = loopIndex6 + 1;
        }
      }
      loopIndex2 = IRInst__getOperandRecord(inst,loopIndex4);
      loopIndex = 0;
      local_64 = *(undefined4 *)(loopIndex2 + 0x10);
      do {
        if (*(char *)((int)&local_74 + loopIndex) == '\0') {
          loopIndex2 = 1;
          puVar11 = (undefined1 *)((int)local_58 + loopIndex);
          while( true ) {
            loopIndex3 = (**(code **)(*piVar9 + 0x14))(piVar9);
            if (loopIndex3 < loopIndex2) break;
            bVar2 = *(byte *)((int)&local_64 + loopIndex);
            loopIndex3 = IRInst__getOperandRecord(piVar9,loopIndex2);
            *puVar11 = *(undefined1 *)((uint)bVar2 + loopIndex3 + 0x10);
            loopIndex2 = loopIndex2 + 1;
            puVar11 = puVar11 + 4;
          }
        }
        bVar1 = loopIndex != 3;
        loopIndex = loopIndex + 1;
      } while (bVar1);
      loopIndex6 = local_58;
      for (loopIndex2 = 1; loopIndex = (**(code **)(*piVar9 + 0x14))(piVar9), uVar3 = DAT_001b0220,
          loopIndex2 <= loopIndex; loopIndex2 = loopIndex2 + 1) {
        loopIndex = *loopIndex6;
        if (loopIndex2 == 0) {
          piVar9[0x27] = loopIndex;
        }
        else {
          loopIndex3 = IRInst__getOperandRecord(piVar9,loopIndex2);
          *(int *)(loopIndex3 + 0x10) = loopIndex;
        }
        loopIndex6 = loopIndex6 + 1;
      }
      FUN_000f3908(&local_48,local_74);
      FUN_000f3340(&local_44,uVar3,local_48);
      local_3c[0] = local_44;
    }
    if (loopIndex4 == 0) {
      uVar3 = 1;
      *(undefined4 *)(inst + 0x9c) = local_3c[0];
    }
    else {
      loopIndex2 = IRInst__getOperandRecord(inst,loopIndex4);
      uVar3 = 1;
      *(undefined4 *)(loopIndex2 + 0x10) = local_3c[0];
    }
  }
  else {
LAB_00186a60:
    uVar3 = 0;
    *(int *)(loopIndex + 0x204) = *(int *)(loopIndex + 0x204) + 1;
  }
  return uVar3;
}

/* FUN_00186a88 @ 0x186a88 (2816 bytes) */
int FUN_00186a88(inst, param_2, inst2, param_4, param_5, param_6, param_7)
  int *inst;
  int param_2;
  int *inst2;
  int param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  undefined4 sourceDef;
  bool bVar1;
  uint uVar2;
  uint uVar3;
  int loopIndex;
  int loopIndex2;
  int *loopIndex4;
  int loopRemaining;
  void *inst3;
  undefined4 uVar9;
  undefined4 uVar10;
  int *piVar11;
  int *loopIndex3;
  undefined4 uVar13;
  undefined4 uVar14;
  int *local_a8;
  int *local_a4 [10];
  int local_7c [4];
  int local_6c;
  float local_68;
  
  local_a4[9] = (int *)0x3f800000;
  local_a4[5] = (int *)0x3f000000;
  local_a4[6] = (int *)0x3f800000;
  local_a4[7] = (int *)0x3f800000;
  local_a4[8] = (int *)0x3f800000;
  local_a4[2] = (int *)0x3f000000;
  local_a4[3] = (int *)0x3f000000;
  local_a4[4] = (int *)0x3f000000;
  if (inst == (int *)0x0) {
    return 0;
  }
  loopRemaining = param_4;
  uVar10 = param_5;
  uVar9 = param_6;
  IRInst__getOperandSource(inst,param_2);
  loopIndex = (**(code **)(*inst + 0x14))(inst);
  if (loopIndex < param_2) {
    return 0;
  }
  loopIndex = (**(code **)(*inst + 0x5c))(inst);
  if (loopIndex != 0) {
    return 0;
  }
  loopIndex = (**(code **)(*inst + 0x28))(inst);
  if (loopIndex != 0) {
    return 0;
  }
  if ((inst[5] & 2U) != 0) {
    return 0;
  }
  loopIndex = (**(code **)(*inst + 100))(inst);
  if (loopIndex != 0) {
    for (loopIndex = 1; loopIndex2 = (**(code **)(*inst + 0x14))(inst), loopIndex <= loopIndex2;
        loopIndex = loopIndex + 1) {
      if ((((inst[loopIndex * 6 + 0x28] & 1U) != 0) || ((inst[loopIndex * 6 + 0x28] & 2U) != 0)) ||
         (loopIndex2 = FUN_000f31e8(inst,loopIndex), loopIndex2 == 0)) goto LAB_001874d4;
    }
    if ((inst[0x48] == 0) && (inst[0x49] == 0)) {
      if (((inst[0x20] != 0) &&
          ((loopIndex = RegKind__flagBit0(inst[0x26]), loopIndex != 0 && ((inst[5] & 2U) == 0)))) &&
         (loopIndex = (**(code **)(*inst + 0x50))(inst), loopIndex == 0)) {
        loopIndex = 4;
        piVar11 = inst;
        do {
          if ((uint)(*(byte *)(piVar11 + 0x27) - 2) < 2) goto LAB_001874d4;
          piVar11 = (int *)((int)piVar11 + 1);
          loopIndex = loopIndex + -1;
        } while (loopIndex != 0);
      }
      IRInst__getOperandRecord(inst,0);
      loopIndex = FUN_00105dbc(inst,0);
      if (((loopIndex == 0) && ((inst[5] & 2U) == 0)) && ((inst[5] & 0x200U) == 0)) {
        return 0;
      }
    }
  }
LAB_001874d4:
  if (*(int *)(inst[0x22] + 8) == 0x8e) {
    return 0;
  }
  loopIndex = (**(code **)(*inst2 + 0x5c))(inst2);
  if (loopIndex != 0) {
    return 0;
  }
  if (inst2[0x48] != 0) {
    return 0;
  }
  loopIndex = ((int (*)())FUN_001897fc)(inst,param_2);
  if (loopIndex != 0) {
    return 0;
  }
  uVar2 = inst2[5];
  piVar11 = (int *)0x0;
  if ((uVar2 & 0x200) != 0) {
    loopIndex2 = inst2[1];
    DList__unlink(inst2);
    local_a8 = (int *)IRInst__clone(inst2,*(undefined4 *)(param_4 + 8),1);
    loopIndex = FUN_00162dfc(&local_a8,1,param_4);
    if (loopIndex == 0) {
      Block__insertInstAfter(*(undefined4 *)(loopIndex2 + 0x158),loopIndex2,inst2);
      return 0;
    }
    Block__insertInstAfter(*(undefined4 *)(loopIndex2 + 0x158),loopIndex2,local_a8);
    Block__insertInstAfter(*(undefined4 *)(loopIndex2 + 0x158),local_a8,inst2);
    uVar2 = local_a8[5];
    piVar11 = inst2;
    inst2 = local_a8;
  }
  if ((uVar2 & 0x200) != 0) {
    return 0;
  }
  if (0 < inst2[0x21]) {
    loopIndex = 1;
    do {
      loopIndex4 = (int *)IRInst__getOperandSource(inst2,loopIndex);
      loopIndex2 = (**(code **)(*loopIndex4 + 0x60))(loopIndex4);
      if (loopIndex2 != 0) {
        return 0;
      }
      loopIndex = loopIndex + 1;
    } while (loopIndex <= inst2[0x21]);
  }
  loopIndex2 = IRInst__getOperandRecord(inst2,0);
  loopIndex = inst2[0x22];
  uVar13 = *(undefined4 *)(loopIndex2 + 0x10);
  if (*(int *)(loopIndex + 8) == 0x12) {
    local_a8 = (int *)IRInst__getOperandSource(inst2,1);
    loopIndex = FUN_001267b8(local_a8[0x26]);
    if (loopIndex == 0) {
      if (local_a8[0x26] == 0x33) {
        loopIndex = IRInst__getOperandRecord(inst2,1);
        loopIndex2 = 0;
        local_a4[0] = *(int **)(loopIndex + 0x10);
        loopIndex = 4;
        loopIndex4 = local_7c;
        do {
          uVar2 = (uint)*(byte *)(loopIndex2 + (int)local_a4);
          if (uVar2 != 4) {
            *loopIndex4 = local_a8[uVar2 * 6 + 8];
          }
          loopIndex2 = loopIndex2 + 1;
          loopIndex4 = loopIndex4 + 1;
          loopIndex = loopIndex + -1;
        } while (loopIndex != 0);
        uVar14 = *(undefined4 *)(param_4 + 0x3ac);
        local_a8 = (int *)FUN_000f5f94(uVar14,local_7c,local_a4,loopRemaining,uVar10,uVar9,loopIndex4);
        if (local_a8 == (int *)0x0) {
          local_a8 = (int *)FUN_000f57f0(uVar14,local_7c,local_a4,loopRemaining);
        }
        loopIndex4 = local_a4[0];
        if (local_a8 == (int *)0x0) {
          return 0;
        }
        loopRemaining = IRInst__getOperandRecord(inst2,1);
        *(int **)(loopRemaining + 0x10) = loopIndex4;
        uVar10 = *(undefined4 *)(param_4 + 8);
        IRInst__setOperandSource(inst2,1,local_a8,0,uVar10);
      }
      else {
        local_a8 = (int *)0x0;
      }
    }
    if (local_a8 == (int *)0x0) {
      return 0;
    }
    loopRemaining = (**(code **)(*local_a8 + 0x5c))(local_a8);
    if (loopRemaining != 0) {
      return 0;
    }
    if ((inst2[0x2e] & 2U) != 0) {
      return 0;
    }
    if (inst2[0x49] != 0) {
      return 0;
    }
    loopIndex4 = &local_6c;
    loopRemaining = FUN_000f5cf0(inst2,2,uVar13,loopIndex4);
    if ((loopRemaining == 0) || (bVar1 = true, local_6c != 2)) {
      bVar1 = false;
    }
    if (bVar1) {
      if ((local_68 == 1.0) || (local_68 == -1.0)) {
        uVar2 = (uint)(local_68 == -1.0);
        if (uVar2 == (inst2[0x2e] & 1U)) {
          return 0;
        }
        inst3 = IRInst__create(0x9c,*(undefined4 *)(param_4 + 8));
        uVar10 = *(undefined4 *)((int)inst3 + 0x14c);
        loopRemaining = IRInst__getOperandRecord(inst3,0);
        *(undefined4 *)(loopRemaining + 0xc) = 0x31;
        *(undefined4 *)(loopRemaining + 8) = uVar10;
        uVar10 = *(undefined4 *)(param_4 + 8);
        loopIndex4 = local_a8;
        goto LAB_00187498;
      }
      if ((((local_68 == 0.5) || (local_68 == -0.5)) &&
          (loopRemaining = FUN_00184cd8(inst,param_2,param_4), loopRemaining != 0)) &&
         ((inst2[0x2e] & 1U) == (uint)(local_68 == 0.5))) {
        inst3 = IRInst__create(0x99,*(undefined4 *)(param_4 + 8));
        uVar10 = *(undefined4 *)((int)inst3 + 0x14c);
        loopRemaining = IRInst__getOperandRecord(inst3,0);
        *(undefined4 *)(loopRemaining + 0xc) = 0x31;
        *(undefined4 *)(loopRemaining + 8) = uVar10;
        sourceDef = IRInst__getOperandSource(inst2,1);
        IRInst__setOperandSource(inst3,1,sourceDef,0,*(undefined4 *)(param_4 + 8));
        loopRemaining = FUN_00185da4(param_2,(uint)(local_68 == -0.5),inst,inst3,inst2,param_4,param_5
                             ,param_6,param_7,piVar11);
        if (loopRemaining != 0) {
          inst[0x49] = inst[0x49] + -1;
          return loopRemaining;
        }
        return 0;
      }
    }
    local_a4[1] = (int *)IRInst__getOperandSource(inst2,2);
    loopRemaining = FUN_001267b8(local_a4[1][0x26]);
    if (loopRemaining == 0) {
      if (local_a4[1][0x26] == 0x33) {
        loopRemaining = IRInst__getOperandRecord(inst2,2);
        loopIndex = 0;
        local_a4[0] = *(int **)(loopRemaining + 0x10);
        loopRemaining = 4;
        loopIndex3 = local_7c;
        do {
          uVar2 = (uint)*(byte *)(loopIndex + (int)local_a4);
          if (uVar2 != 4) {
            *loopIndex3 = local_a4[1][uVar2 * 6 + 8];
          }
          loopIndex = loopIndex + 1;
          loopIndex3 = loopIndex3 + 1;
          loopRemaining = loopRemaining + -1;
        } while (loopRemaining != 0);
        uVar13 = *(undefined4 *)(param_4 + 0x3ac);
        local_a4[1] = (int *)FUN_000f5f94(uVar13,local_7c,local_a4,loopIndex4,uVar10,uVar9,loopIndex3);
        if (local_a4[1] == (int *)0x0) {
          local_a4[1] = (int *)FUN_000f57f0(uVar13,local_7c,local_a4,loopIndex4);
        }
        loopIndex4 = local_a4[0];
        if (local_a4[1] == (int *)0x0) {
          return 0;
        }
        loopRemaining = IRInst__getOperandRecord(inst2,2);
        *(int **)(loopRemaining + 0x10) = loopIndex4;
        IRInst__setOperandSource(inst2,2,local_a4[1],0,*(undefined4 *)(param_4 + 8));
      }
      else {
        local_a4[1] = (int *)0x0;
      }
    }
    if (((local_a4[1] == (int *)0x0) || ((inst2[0x34] & 2U) != 0)) ||
       ((loopRemaining = (**(code **)(*local_a4[1] + 0x5c))(local_a4[1]), loopRemaining != 0 ||
        (loopRemaining = ((int (*)())FUN_00186510)(inst2,&local_a8,local_a4 + 1,*(undefined4 *)(param_4 + 8)),
        loopRemaining == 0)))) {
      return 0;
    }
    if ((inst2[0x2e] & 1U) == (inst2[0x34] & 1U)) {
      uVar9 = *(undefined4 *)(param_4 + 8);
      uVar10 = 0x9b;
    }
    else {
      uVar9 = *(undefined4 *)(param_4 + 8);
      uVar10 = 0x9a;
    }
    inst3 = IRInst__create(uVar10,uVar9);
    uVar10 = *(undefined4 *)((int)inst3 + 0x14c);
    loopRemaining = IRInst__getOperandRecord(inst3,0);
    *(undefined4 *)(loopRemaining + 0xc) = 0x31;
    *(undefined4 *)(loopRemaining + 8) = uVar10;
    IRInst__setOperandSource(inst3,1,local_a8,0,*(undefined4 *)(param_4 + 8));
    IRInst__setOperandSource(inst3,2,local_a4[1],0,*(undefined4 *)(param_4 + 8));
    uVar2 = inst2[0x2e] & 1;
  }
  else {
    if (*(int *)(loopIndex + 8) == 0x31) {
      loopRemaining = IRInst__getOperandSource(inst2,1);
      uVar10 = 0;
      if (loopRemaining != 0) {
        loopRemaining = IRInst__getOperandSource(inst2,1);
        uVar10 = *(undefined4 *)(loopRemaining + 0x98);
      }
      loopRemaining = FUN_001267b8(uVar10);
      if ((loopRemaining != 0) && ((inst2[0x2e] & 2U) == 0)) {
        loopIndex4 = (int *)IRInst__getOperandSource(inst2,1);
        loopRemaining = (**(code **)(*loopIndex4 + 0x5c))(loopIndex4);
        if ((loopRemaining == 0) && (inst2[0x49] == 1)) {
          if ((inst2[0x2e] & 1U) == 0) {
            if ((inst2[0x34] & 1U) == 0) goto LAB_001872f8;
LAB_001872f0:
            uVar2 = 1;
          }
          else {
            if ((inst2[0x34] & 1U) == 0) goto LAB_001872f0;
LAB_001872f8:
            uVar2 = 0;
          }
          inst3 = IRInst__create(0x9b,*(undefined4 *)(param_4 + 8));
          uVar10 = *(undefined4 *)((int)inst3 + 0x14c);
          loopRemaining = IRInst__getOperandRecord(inst3,0);
          *(undefined4 *)(loopRemaining + 0xc) = 0x31;
          *(undefined4 *)(loopRemaining + 8) = uVar10;
          sourceDef = IRInst__getOperandSource(inst2,1);
          IRInst__setOperandSource(inst3,1,sourceDef,0,*(undefined4 *)(param_4 + 8));
          sourceDef = IRInst__getOperandSource(inst2,1);
          IRInst__setOperandSource(inst3,2,sourceDef,0,*(undefined4 *)(param_4 + 8));
          goto LAB_0018754c;
        }
      }
      loopIndex = inst2[0x22];
    }
    if (*(int *)(loopIndex + 8) != 0x14) {
      return 0;
    }
    loopRemaining = IRInst__getOperandSource(inst2,1);
    if (loopRemaining == 0) {
      uVar10 = 0;
    }
    else {
      loopRemaining = IRInst__getOperandSource(inst2,1);
      uVar10 = *(undefined4 *)(loopRemaining + 0x98);
    }
    loopRemaining = FUN_001267b8(uVar10);
    if (loopRemaining == 0) {
      return 0;
    }
    if ((inst2[0x2e] & 2U) != 0) {
      return 0;
    }
    loopIndex4 = (int *)IRInst__getOperandSource(inst2,1);
    loopRemaining = (**(code **)(*loopIndex4 + 0x5c))(loopIndex4);
    if (loopRemaining != 0) {
      return 0;
    }
    loopRemaining = FUN_000f5c0c(inst2,2,uVar13,local_a4 + 6);
    if (loopRemaining == 0) {
      return 0;
    }
    loopRemaining = FUN_000f5c0c(inst2,3,uVar13,local_a4 + 2);
    if (loopRemaining == 0) {
      return 0;
    }
    if (inst2[0x49] != 1) {
      return 0;
    }
    uVar2 = inst2[0x3a] & 1;
    if ((inst2[0x2e] & 1U) == 0) {
      if ((inst2[0x34] & 1U) == 0) goto LAB_0018744c;
LAB_00187444:
      uVar3 = 1;
    }
    else {
      if ((inst2[0x34] & 1U) == 0) goto LAB_00187444;
LAB_0018744c:
      uVar3 = 0;
    }
    if (uVar3 == uVar2) {
      return 0;
    }
    inst3 = IRInst__create(0x99,*(undefined4 *)(param_4 + 8));
    uVar10 = *(undefined4 *)((int)inst3 + 0x14c);
    loopRemaining = IRInst__getOperandRecord(inst3,0);
    *(undefined4 *)(loopRemaining + 0xc) = 0x31;
    *(undefined4 *)(loopRemaining + 8) = uVar10;
    loopIndex4 = (int *)IRInst__getOperandSource(inst2,1);
    uVar10 = *(undefined4 *)(param_4 + 8);
LAB_00187498:
    IRInst__setOperandSource(inst3,1,loopIndex4,0,uVar10);
  }
LAB_0018754c:
  loopRemaining = FUN_00185da4(param_2,uVar2,inst,inst3,inst2,param_4,param_5,param_6,param_7,piVar11)
  ;
  return loopRemaining;
}

/* Inst__r300Peephole_1875a8 @ 0x1875a8 (1328 bytes) */
int Inst__r300Peephole_1875a8(inst, param_2, inst2, param_4)
  int *inst;
  int param_2;
  int inst2;
  int param_4;
{
  int *operandVReg3;
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int callResult;
  int *piVar5;
  int *operandVReg;
  int *operandVReg2;
  uint uVar8;
  uint uVar9;
  undefined4 uVar10;
  int iVar11;
  undefined4 uVar12;
  int iVar13;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  int local_5c [5];
  
  if ((((((inst != (int *)0x0) && (*(int *)(*(int *)(inst2 + 0x88) + 8) == 0x12)) &&
        (*(int *)(inst[0x22] + 8) == 0x12)) &&
       (((callResult = IRInst__hasSingleUse(inst2,param_4), callResult != 0 && (*(int *)(inst2 + 0x120) == 0)) &&
        ((*(int *)(inst2 + 0x124) == 0 && ((inst[0x48] == 0 && (inst[0x49] == 0)))))))) &&
      ((inst[5] & 0x200U) == 0)) &&
     (((*(uint *)(inst2 + 0x14) & 0x200) == 0 && ((*(uint *)(inst2 + 0x14) & 0x40000) == 0)))) {
    callResult = IRInst__getOperandRecord(inst,0);
    iVar13 = *(int *)(callResult + 0x10);
    callResult = IRInst__getOperandRecord(inst2,0);
    if (iVar13 != *(int *)(callResult + 0x10)) {
      callResult = IRInst__getOperandRecord(inst2,0);
      callResult = FUN_000f3824(*(undefined4 *)(callResult + 0x10));
      if (callResult == 0) goto LAB_00187a90;
    }
    callResult = FUN_000f31e8(inst,param_2);
    if (callResult == 0) {
      callResult = (**(code **)(*inst + 0x60))(inst);
      if (callResult != 0) {
        return 0;
      }
      callResult = IRInst__getOperandRecord(inst,param_2);
      uVar12 = *(undefined4 *)(callResult + 0x10);
      callResult = IRInst__getOperandRecord(inst,0);
      uVar10 = *(undefined4 *)(callResult + 0x10);
      *(undefined4 *)(inst2 + 0x9c) = uVar10;
      callResult = IRInst__getOperandRecord(inst2,1);
      FUN_000f2bdc(&local_68,*(undefined4 *)(callResult + 0x10),uVar12);
      callResult = IRInst__getOperandRecord(inst2,1);
      *(undefined4 *)(callResult + 0x10) = local_68;
      callResult = IRInst__getOperandRecord(inst2,2);
      FUN_000f2bdc(&local_64,*(undefined4 *)(callResult + 0x10),uVar12);
      callResult = IRInst__getOperandRecord(inst2,2);
      uVar12 = DAT_001b0220;
      *(undefined4 *)(callResult + 0x10) = local_64;
      FUN_000f3908(&local_60,uVar10);
      FUN_000f3340(local_5c,uVar12,local_60);
      if (param_2 == 0) {
        inst[0x27] = local_5c[0];
      }
      else {
        callResult = IRInst__getOperandRecord(inst,param_2);
        *(int *)(callResult + 0x10) = local_5c[0];
      }
    }
    operandVReg3 = (int *)IRInst__getOperandSource(inst2,1);
    IRInst__getOperandRecord(inst2,1);
    operandVReg = (int *)IRInst__getOperandSource(inst2,2);
    uVar1 = *(uint *)(inst2 + 0xd0) & 1;
    uVar8 = *(uint *)(inst2 + 0xd0) >> 1 & 1;
    callResult = IRInst__getOperandRecord(inst2,2);
    uVar12 = *(undefined4 *)(callResult + 0x10);
    iVar13 = (param_2 == 1) + 1;
    operandVReg2 = (int *)IRInst__getOperandSource(inst,iVar13);
    uVar2 = inst[iVar13 * 6 + 0x28] & 1;
    uVar9 = (uint)inst[iVar13 * 6 + 0x28] >> 1 & 1;
    callResult = IRInst__getOperandRecord(inst,iVar13);
    uVar10 = *(undefined4 *)(callResult + 0x10);
    callResult = (**(code **)(*operandVReg3 + 0x5c))(operandVReg3);
    if (callResult != 0) {
      return 0;
    }
    callResult = (**(code **)(*operandVReg + 0x5c))(operandVReg);
    if (callResult != 0) {
      return 0;
    }
    callResult = (**(code **)(*operandVReg2 + 0x5c))(operandVReg2);
    if (callResult != 0) {
      return 0;
    }
    callResult = (**(code **)(*operandVReg2 + 0x48))(operandVReg2);
    if ((((callResult != 0) && (callResult = (**(code **)(*operandVReg3 + 0x48))(operandVReg3), callResult == 0)) &&
        (callResult = (**(code **)(*operandVReg + 0x48))(operandVReg), callResult == 0)) &&
       ((inst[param_2 * 6 + 0x28] & 2U) == 0)) {
      iVar11 = inst2 + 0xbc;
      IRInst__setOperandSource(inst2,2,operandVReg2,0,*(undefined4 *)(param_4 + 8));
      IROperand__setModifierBits(iVar11,1,uVar2);
      IROperand__setModifierBits(iVar11,2,uVar9);
      piVar5 = inst + iVar13 * 6 + 0x23;
      callResult = IRInst__getOperandRecord(inst2,2);
      *(undefined4 *)(callResult + 0x10) = uVar10;
      IRInst__setOperandSource(inst,iVar13,operandVReg,0,*(undefined4 *)(param_4 + 8));
      IROperand__setModifierBits(piVar5,1,uVar1);
      IROperand__setModifierBits(piVar5,2,uVar8);
      callResult = IRInst__getOperandRecord(inst,iVar13);
      uVar3 = inst[param_2 * 6 + 0x28];
      *(undefined4 *)(callResult + 0x10) = uVar12;
      if ((uVar3 & 1) != 0) {
        IROperand__setModifierBits(iVar11,1,*(uint *)(inst2 + 0xd0) & 1 ^ 1);
        IROperand__setModifierBits(piVar5,1,inst[iVar13 * 6 + 0x28] & 1U ^ 1);
      }
      callResult = ((int (*)())FUN_00186a88)(inst,param_2,inst2,param_4,1,1,0);
      if (callResult != 0) {
        return 1;
      }
      IRInst__setOperandSource(inst2,2,operandVReg,0,*(undefined4 *)(param_4 + 8));
      IROperand__setModifierBits(iVar11,1,uVar1);
      IROperand__setModifierBits(iVar11,2,uVar8);
      callResult = IRInst__getOperandRecord(inst2,2);
      *(undefined4 *)(callResult + 0x10) = uVar12;
      IRInst__setOperandSource(inst,iVar13,operandVReg2,0,*(undefined4 *)(param_4 + 8));
      IROperand__setModifierBits(piVar5,1,uVar2);
      IROperand__setModifierBits(piVar5,2,uVar9);
      callResult = IRInst__getOperandRecord(inst,iVar13);
      *(undefined4 *)(callResult + 0x10) = uVar10;
    }
  }
LAB_00187a90:
  callResult = ((int (*)())FUN_00186a88)(inst,param_2,inst2,param_4,1,1,0);
  if (callResult == 0) {
    return 0;
  }
  return 1;
}

/* FUN_00187ad8 @ 0x187ad8 (1996 bytes) */
int FUN_00187ad8(inst, param_2)
  undefined4 inst;
  int param_2;
{
  int sourceDef;
  int operandRecord2;
  int *operandVReg;
  bool bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int *callResult;
  int iVar6;
  uint loopIndex4;
  int *piVar8;
  int *operandVReg3;
  int *operandVReg2;
  int *piVar11;
  undefined4 operandRecord;
  int iVar13;
  int iVar14;
  undefined4 *puVar15;
  int iVar16;
  int iVar17;
  uint uVar18;
  uint loopIndex2;
  int iVar20;
  undefined4 uVar21;
  uint loopIndex3;
  int loopIndex;
  uint *puVar24;
  code *pcVar25;
  int iVar26;
  int iVar27;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_80;
  int local_78;
  undefined4 local_74;
  undefined4 local_70;
  int local_6c;
  uint local_68;
  uint local_64;
  undefined4 local_60;
  undefined4 *local_5c;
  
  callResult = (int *)FUN_001922c4(0,0,inst,param_2);
  iVar2 = *(int *)(callResult[0x22] + 8);
  if (((iVar2 != 0x24) && (iVar2 != 0x25)) && (iVar2 != 0x26)) {
    return;
  }
  iVar2 = ((undefined4 (*)())FUN_00139838)(callResult,2,(double)FLOAT_001aa0e8);
  iVar6 = ((undefined4 (*)())FUN_00139838)(callResult,2,(double)FLOAT_001aa0d4);
  if ((iVar6 == 0) || (iVar6 = ((undefined4 (*)())FUN_00139838)(callResult,3,(double)FLOAT_001aa0e8), iVar6 == 0)) {
    iVar6 = ((undefined4 (*)())FUN_00139838)(callResult,3,(double)FLOAT_001aa0d4);
    if (iVar6 == 0) {
      return;
    }
    if (iVar2 == 0) {
      return;
    }
  }
  if ((callResult[5] & 0x200U) != 0) {
    return;
  }
  puVar24 = (uint *)callResult[4];
  uVar3 = puVar24[1];
  uVar18 = uVar3 - 1;
  if (-1 < (int)uVar18) {
    iVar6 = uVar18 * 4;
    loopIndex2 = 0;
    piVar11 = (int *)0x0;
    loopIndex3 = uVar18;
    do {
      if (loopIndex3 < *puVar24) {
        loopIndex4 = puVar24[1];
        if (loopIndex4 <= loopIndex3) {
          _memset(loopIndex4 * 4 + puVar24[2],0,(loopIndex3 - loopIndex4) * 4 + 4);
          puVar24[1] = loopIndex3 + 1;
        }
        piVar8 = (int *)(iVar6 + puVar24[2]);
      }
      else {
        piVar8 = (int *)Vector__elementRefGrow(puVar24,loopIndex3);
      }
      iVar26 = *piVar8;
      iVar4 = *(int *)(iVar26 + 0x88);
      piVar8 = piVar11;
      if (*(int *)(iVar4 + 8) != 0x13) {
        if (*(int *)(iVar4 + 8) == 0x14) {
          operandVReg3 = (int *)IRInst__getOperandSource(iVar26,1);
          if ((callResult == operandVReg3) || (operandVReg3 = (int *)IRInst__getOperandSource(iVar26,2), callResult == operandVReg3))
          goto LAB_00187ce4;
          iVar4 = *(int *)(iVar26 + 0x88);
        }
        if (*(int *)(iVar4 + 8) == 0x12) {
          operandVReg3 = (int *)IRInst__getOperandSource(iVar26,1);
          operandVReg2 = (int *)IRInst__getOperandSource(iVar26,2);
          piVar8 = operandVReg2;
          if (((callResult != operandVReg3) && (piVar8 = operandVReg3, callResult != operandVReg2)) ||
             ((piVar11 != (int *)0x0 && (piVar11 != piVar8)))) goto LAB_00187cfc;
        }
      }
LAB_00187ce4:
      loopIndex2 = loopIndex2 + 1;
      loopIndex3 = loopIndex3 - 1;
      iVar6 = iVar6 + -4;
      if (loopIndex2 == uVar3) goto LAB_00187cfc;
      puVar24 = (uint *)callResult[4];
      piVar11 = piVar8;
    } while( true );
  }
LAB_00187d00:
  iVar6 = *(int *)(param_2 + 0x478);
  if (-1 < (int)uVar18) {
    iVar4 = uVar18 * 4;
    loopIndex3 = 0;
    do {
      if (uVar18 < *puVar24) {
        loopIndex2 = puVar24[1];
        if (loopIndex2 <= uVar18) {
          _memset(loopIndex2 * 4 + puVar24[2],0,(uVar18 - loopIndex2) * 4 + 4);
          puVar24[1] = uVar18 + 1;
        }
        piVar11 = (int *)(iVar4 + puVar24[2]);
      }
      else {
        piVar11 = (int *)Vector__elementRefGrow(puVar24,uVar18);
      }
      iVar26 = *piVar11;
      if (*(int *)(*(int *)(iVar26 + 0x88) + 8) == 0x13) {
        operandVReg = (int *)IRInst__getOperandSource(iVar26,1);
        if (callResult == operandVReg) {
          uVar21 = 1;
          loopIndex = 2;
        }
        else {
          operandVReg = (int *)IRInst__getOperandSource(iVar26,2);
          if (callResult != operandVReg) {
            if ((*(uint *)(iVar26 + 0x14) & 0x200) != 0) {
              IRInst__getOperandSource(iVar26,*(undefined4 *)(iVar26 + 0x84));
            }
            goto LAB_00188244;
          }
          uVar21 = 2;
          loopIndex = 1;
        }
        local_5c = &local_94;
        iVar20 = 0;
        *(int *)(param_2 + 500) = *(int *)(param_2 + 500) + 1;
        Vector__removeAt(callResult[4],uVar18);
        callResult[0x58] = callResult[0x58] + -1;
        local_80 = 0;
        local_94 = 0;
        local_90 = 0;
        operandRecord = IRInst__getOperandRecord(iVar26,0);
        FUN_00104730(local_5c,operandRecord);
        local_60 = IRInst__getOperandSource(iVar26,loopIndex);
        IRInst__setOperandSource(iVar26,loopIndex,0,1,*(undefined4 *)(param_2 + 8));
        operandRecord2 = IRInst__getOperandRecord(iVar26,loopIndex);
        local_78 = *(int *)(operandRecord2 + 0x10);
        operandRecord2 = IRInst__getOperandRecord(iVar26,uVar21);
        local_98 = *(undefined4 *)(operandRecord2 + 0x10);
        loopIndex2 = *(uint *)(loopIndex * 0x18 + iVar26 + 0xa0);
        local_68 = loopIndex2 & 1;
        local_64 = loopIndex2 >> 1 & 1;
        local_6c = callResult[1];
        local_70 = *(undefined4 *)(iVar26 + 8);
        local_74 = *(undefined4 *)(iVar26 + 0x158);
        iVar13 = callResult[0x56];
        loopIndex = *(int *)(iVar26 + 0x10);
        DList__unlink(callResult);
        DList__unlink(iVar26);
        iVar16 = *(int *)(iVar26 + 0x14c);
        iVar27 = *(int *)(iVar26 + 0x120);
        iVar17 = *(int *)(iVar26 + 0x124);
        if ((*(uint *)(iVar26 + 0x14) & 0x200) != 0) {
          iVar20 = IRInst__getOperandSource(iVar26,*(undefined4 *)(iVar26 + 0x84));
          uVar21 = *(undefined4 *)(param_2 + 8);
          sourceDef = IRInst__getOperandSource(iVar26,*(undefined4 *)(iVar26 + 0x84));
          puVar24 = *(uint **)(sourceDef + 0x10);
          loopIndex2 = puVar24[1];
          if (0 < (int)loopIndex2) {
            loopIndex4 = 0;
            do {
              if (loopIndex4 < *puVar24) {
                if (loopIndex2 <= loopIndex4) {
                  _memset(loopIndex2 * 4 + puVar24[2],0,(loopIndex4 - loopIndex2) * 4 + 4);
                  puVar24[1] = loopIndex4 + 1;
                }
                piVar11 = (int *)(loopIndex4 * 4 + puVar24[2]);
              }
              else {
                piVar11 = (int *)Vector__elementRefGrow(puVar24,loopIndex4);
              }
              if (iVar26 == *piVar11) {
                Vector__removeAt(puVar24,loopIndex4);
                sourceDef = IRInst__getOperandSource(iVar26,*(undefined4 *)(iVar26 + 0x84));
                *(int *)(sourceDef + 0x160) = *(int *)(sourceDef + 0x160) + -1;
                break;
              }
              loopIndex2 = puVar24[1];
              loopIndex4 = loopIndex4 + 1;
            } while ((int)loopIndex4 < (int)loopIndex2);
          }
          IRInst__setOperandSource(iVar26,*(undefined4 *)(iVar26 + 0x84),0,1,uVar21);
          *(int *)(iVar26 + 0x84) = *(int *)(iVar26 + 0x84) + -1;
          *(uint *)(iVar26 + 0x14) = *(uint *)(iVar26 + 0x14) & 0xfffffdff;
        }
        iVar14 = *(int *)(iVar26 + 0x160) - iVar6;
        if (iVar14 < 0) {
          iVar14 = 0;
        }
        piVar11 = (int *)FUN_00103ebc(callResult,iVar26,*(undefined4 *)(param_2 + 8),1);
        iVar26 = (iVar2 == 0) + 2;
        FUN_001062c0(piVar11,0,local_5c,*(undefined4 *)(param_2 + 8));
        piVar11[0x53] = iVar16;
        Block__insertInstAfter(iVar13,local_6c,callResult);
        Block__insertInstBefore(local_74,local_70,piVar11);
        piVar11[0x48] = iVar27;
        piVar11[0x49] = iVar17;
        if (iVar20 != 0) {
          IRInst__setExtraOperandSource(piVar11,iVar20,1,*(undefined4 *)(param_2 + 8));
        }
        piVar11[4] = loopIndex;
        IRInst__setOperandSource(piVar11,iVar26,local_60,1,*(undefined4 *)(param_2 + 8));
        piVar11[0x58] = iVar6 + iVar14;
        if (iVar26 == 0) {
          piVar11[0x27] = local_78;
        }
        else {
          loopIndex = IRInst__getOperandRecord(piVar11,iVar26);
          *(int *)(loopIndex + 0x10) = local_78;
        }
        IROperand__setModifierBits(piVar11 + iVar26 * 6 + 0x23,2,local_64);
        IROperand__setModifierBits(piVar11 + iVar26 * 6 + 0x23,1,local_68);
        loopIndex = IRInst__getOperandSource(piVar11,1);
        if (iVar6 < *(int *)(loopIndex + 0x160)) {
          *(int *)(loopIndex + 0x160) = *(int *)(loopIndex + 0x160) + 1;
        }
        else {
          *(int *)(loopIndex + 0x160) = iVar6 + 1;
        }
        puVar24 = *(uint **)(loopIndex + 0x10);
        loopIndex2 = puVar24[1];
        if (loopIndex2 < *puVar24) {
          _memset(loopIndex2 * 4 + puVar24[2],0,4);
          puVar15 = (undefined4 *)(loopIndex2 * 4 + puVar24[2]);
          puVar24[1] = loopIndex2 + 1;
        }
        else {
          puVar15 = (undefined4 *)Vector__elementRefGrow(puVar24,loopIndex2);
        }
        *puVar15 = piVar11;
        loopIndex = 0;
        do {
          loopIndex2 = (uint)*(byte *)((int)&local_98 + loopIndex);
          operandRecord2 = IRInst__getOperandRecord(piVar11,0);
          if (*(char *)(loopIndex + operandRecord2 + 0x10) == '\x01') {
            loopIndex2 = 4;
          }
          for (iVar13 = 1; iVar20 = (**(code **)(*piVar11 + 0x14))(piVar11), iVar13 <= iVar20;
              iVar13 = iVar13 + 1) {
            if (iVar26 != iVar13) {
              if (loopIndex2 == 4) {
                (**(code **)(*piVar11 + 0x88))(piVar11,iVar13,loopIndex,4);
              }
              else {
                pcVar25 = *(code **)(*piVar11 + 0x88);
                iVar20 = IRInst__getOperandRecord(callResult,iVar13);
                (*pcVar25)(piVar11,iVar13,loopIndex,*(undefined1 *)(loopIndex2 + iVar20 + 0x10));
              }
            }
          }
          bVar1 = loopIndex != 3;
          loopIndex = loopIndex + 1;
        } while (bVar1);
      }
LAB_00188244:
      loopIndex3 = loopIndex3 + 1;
      uVar18 = uVar18 - 1;
      iVar4 = iVar4 + -4;
      if (loopIndex3 == uVar3) goto code_r0x00188258;
      puVar24 = (uint *)callResult[4];
    } while( true );
  }
LAB_0018825c:
  if (puVar24[1] == 0) {
    (**(code **)(*callResult + 0xc))(callResult,1,*(undefined4 *)(param_2 + 8));
  }
  return;
LAB_00187cfc:
  puVar24 = (uint *)callResult[4];
  goto LAB_00187d00;
code_r0x00188258:
  puVar24 = (uint *)callResult[4];
  goto LAB_0018825c;
}

/* Inst__r300Peephole_1882a4 @ 0x1882a4 (408 bytes) */
int Inst__r300Peephole_1882a4(inst, compiler)
  int *inst;
  int compiler;
{
  int operandRecord;
  bool bVar1;
  float fVar2;
  int loopIndex;
  int *a0;
  int iVar4;
  uint uVar5;
  uint uVar6;
  
  loopIndex = (**(code **)(*inst + 0x68))(inst,compiler);
  if (loopIndex != 0) {
    a0 = (int *)IRInst__getOperandSource(inst,1);
    loopIndex = (**(code **)(*a0 + 0x40))(a0);
    if (loopIndex != 0) {
      uVar5 = 0xffffffff;
      fVar2 = 0.0;
      loopIndex = 0;
      do {
        operandRecord = IRInst__getOperandRecord(inst,0);
        if (*(char *)(loopIndex + operandRecord + 0x10) != '\x01') {
          operandRecord = IRInst__getOperandRecord(inst,1);
          uVar6 = (uint)*(byte *)(loopIndex + operandRecord + 0x10);
          if (((int)*(char *)(a0 + 0x57) >> (uVar6 & 0x3f) & 1U) == 0) {
            return;
          }
          iVar4 = ((undefined4 (*)())FUN_0010aafc)((double)GH_U2F((unsigned int)(a0[uVar6 * 6 + 8])));
          if (iVar4 == 0) {
            return;
          }
          if (uVar5 == 0xffffffff) {
            fVar2 = GH_U2F((unsigned int)(a0[uVar6 * 6 + 8]));
            uVar5 = uVar6;
          }
          else if (GH_U2F((unsigned int)(a0[uVar6 * 6 + 8])) != fVar2) {
            return;
          }
        }
        bVar1 = loopIndex != 3;
        loopIndex = loopIndex + 1;
      } while (bVar1);
      loopIndex = ((int (*)())FUN_0010ab40)((double)GH_U2F((unsigned int)(a0[uVar5 * 6 + 8])));
      iVar4 = (**(code **)(**(int **)(compiler + COMP_target) + 0xfc))(*(int **)(compiler + COMP_target),loopIndex,0);
      if (iVar4 != 0) {
        ((void (*)())FUN_000f79c4)(inst,*(undefined4 *)(compiler + COMP_currentProgram),1,1.0,1.0,1.0,1.0);
        inst[0x49] = loopIndex;
        loopIndex = IRInst__getOperandRecord(inst,1);
        *(undefined4 *)(loopIndex + 0x10) = 0x10203;
      }
    }
  }
  return;
}

/* KhanPs__peepholeCombine @ 0x18843c (1328 bytes) */
int KhanPs__peepholeCombine(this, inst, consumerSrcIndex, inst2, program, passThroughR8, passThroughR9)
  undefined4 this;
  int inst;
  int consumerSrcIndex;
  int *inst2;
  undefined4 *program;
  undefined4 passThroughR8;
  undefined4 passThroughR9;
{
  int callResult;
  int *curInst;
  int *inst3;
  undefined4 *programAlias4;
  undefined4 *programAlias5;
  undefined4 changedFlag;
  undefined4 foldStatus [7];
  
  changedFlag = 0;
  foldStatus[0] = 0;
  programAlias5 = program;
  callResult = Compiler__isOptionEnabled(program[2],0x1b);
  if (callResult == 0) {
LAB_00188508:
    callResult = Compiler__isOptionEnabled(program[2],0x1c);
    if (callResult != 0) {
      callResult = Inst__collapseAlgebraic_00154dc0(inst2,program);
      if (callResult != 0) {
        inst2 = (int *)FUN_00146610(inst,consumerSrcIndex,inst2);
        if (inst2 == (int *)0x0) goto LAB_00188950;
      }
      callResult = Inst__collapseAlgebraic_00162cc0(inst2,program);
      if (callResult != 0) {
        inst2 = (int *)FUN_00146610(inst,consumerSrcIndex,inst2);
        if (inst2 == (int *)0x0) goto LAB_00188950;
      }
      callResult = (**(code **)(*inst2 + 0x14))(inst2);
      if ((consumerSrcIndex <= callResult) && (callResult = Inst__collapseAlgebraic_00158264(inst,consumerSrcIndex,inst2,program), callResult != 0))
      {
        inst2 = (int *)FUN_00146610(inst,consumerSrcIndex,inst2);
        if (inst2 == (int *)0x0) goto LAB_00188950;
        changedFlag = 1;
      }
      callResult = Inst__collapseAlgebraic_00155a60(inst2,program);
      if (callResult != 0) {
        inst2 = (int *)FUN_00146610(inst,consumerSrcIndex,inst2);
      }
      callResult = Inst__collapseAlgebraic_0014bdbc(inst2,program);
      if (callResult != 0) {
        inst2 = (int *)FUN_00146610(inst,consumerSrcIndex,inst2);
      }
      callResult = Inst__collapseAlgebraic_0014caec(inst2,program);
      if (callResult != 0) {
        inst2 = (int *)FUN_00146610(inst,consumerSrcIndex,inst2);
      }
      callResult = Inst__collapseAlgebraic_0014d8f8(inst2,program);
      if (callResult != 0) {
        inst2 = (int *)FUN_00146610(inst,consumerSrcIndex,inst2);
      }
      callResult = Inst__collapseAlgebraic_00150d38(inst2,program);
      if (callResult != 0) {
        inst2 = (int *)FUN_00146610(inst,consumerSrcIndex,inst2);
      }
      callResult = Inst__collapseAlgebraic_0014cec8(inst2,program);
      if (callResult != 0) {
        inst2 = (int *)FUN_00146610(inst,consumerSrcIndex,inst2);
      }
      callResult = Inst__collapseAlgebraic_0015df44(inst2,program);
      if (callResult != 0) {
        inst2 = (int *)FUN_00146610(inst,consumerSrcIndex,inst2);
      }
      callResult = Inst__collapseAlgebraic_0015e494(inst2,program);
      if (callResult != 0) {
        inst2 = (int *)FUN_00146610(inst,consumerSrcIndex,inst2);
      }
      callResult = Compiler__isOptionEnabled(program[2],0x3c);
      if ((callResult != 0) && (callResult = Inst__tryDp3CommutativityPushoff(inst,consumerSrcIndex,inst2,program), callResult != 0)) {
        inst2 = (int *)FUN_00146610(inst,consumerSrcIndex,inst2);
      }
      callResult = Inst__collapseAlgebraic_0014d274(inst2,program);
      if (callResult != 0) {
        inst2 = (int *)FUN_00146610(inst,consumerSrcIndex,inst2);
      }
      callResult = Inst__collapseAlgebraic_00158c3c(inst2,program);
      if (callResult != 0) {
        changedFlag = 1;
      }
    }
    callResult = FUN_0015546c(inst,consumerSrcIndex,inst2,(uint)program);
    if (callResult != 0) {
      changedFlag = 1;
      inst2 = (int *)FUN_00146610(inst,consumerSrcIndex,inst2);
    }
    inst3 = inst2;
    programAlias4 = program;
    callResult = FUN_00155654(inst,consumerSrcIndex,inst2,program);
    curInst = inst2;
    if (callResult != 0) {
      changedFlag = 1;
      curInst = (int *)FUN_00146610(inst,consumerSrcIndex,inst2);
      inst3 = inst2;
    }
    callResult = Compiler__isOptionEnabled(program[2],0x1d);
    if ((((callResult != 0) &&
         (callResult = Inst__tryCollapseSimilar(curInst,program,inst3,programAlias4,programAlias5,passThroughR8,passThroughR9), callResult != 0)) &&
        (callResult = (**(code **)(*curInst + 100))(curInst), callResult != 0)) &&
       ((inst != 0 && (callResult = Inst__foldProducerIntoConsumer(inst,consumerSrcIndex,curInst,program,foldStatus), callResult != 0)
        ))) {
      curInst = (int *)FUN_00146610(inst,consumerSrcIndex,curInst);
      if (curInst == (int *)0x0) goto LAB_00188950;
    }
    callResult = Compiler__isOptionEnabled(program[2],0x39);
    if (callResult != 0) {
      ((int (*)())Inst__r300Peephole_1882a4)(curInst,program[2]);
    }
    callResult = FUN_00159b58(curInst,1,program);
    if (callResult != 0) {
      curInst = (int *)FUN_00146610(inst,consumerSrcIndex,curInst);
    }
    callResult = Compiler__isOptionEnabled(program[2],0x39);
    if ((callResult != 0) && (callResult = ((int (*)())Inst__r300Peephole_1875a8)(inst,consumerSrcIndex,curInst,program), callResult != 0)) {
      changedFlag = 1;
      curInst = (int *)FUN_00146610(inst,consumerSrcIndex,curInst);
    }
    callResult = Compiler__isOptionEnabled(program[2],0x3b);
    if ((callResult != 0) && ((curInst[5] & 1U) != 0)) {
      Inst__tryDp3Add(curInst,program,program[2]);
    }
  }
  else {
    changedFlag = (**(code **)(*inst2 + 100))(inst2);
    callResult = Inst__tryCopyPropagate(inst2,program,foldStatus);
    if (callResult == 0) {
LAB_001884c8:
      if (inst != 0) {
        programAlias5 = foldStatus;
        callResult = Inst__foldProducerIntoConsumer(inst,consumerSrcIndex,inst2,program,programAlias5);
        if (callResult != 0) {
          inst2 = (int *)FUN_00146610(inst,consumerSrcIndex,inst2);
          if (inst2 == (int *)0x0) goto LAB_00188950;
        }
      }
      goto LAB_00188508;
    }
    inst2 = (int *)FUN_00146610(inst,consumerSrcIndex,inst2);
    if (inst2 != (int *)0x0) goto LAB_001884c8;
LAB_00188950:
    changedFlag = 1;
  }
  return changedFlag;
}

/* Inst__movAndShiftUseVector @ 0x18896c (1208 bytes) */
int Inst__movAndShiftUseVector(inst, param_2)
  int *inst;
  int param_2;
{
  undefined4 sourceDef2;
  int *sourceDef3;
  int operandRecord2;
  int useCount;
  int operandRecord3;
  int sourceDef;
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  uint uVar4;
  undefined4 *puVar5;
  int *operandVReg;
  int operandRecord;
  int iVar8;
  uint uVar9;
  undefined4 uVar10;
  uint loopIndex;
  uint *puVar12;
  int *piVar13;
  undefined4 local_58;
  undefined4 local_54;
  int local_48;
  undefined4 local_44;
  int local_38 [5];
  
  if (*(int *)(inst[0x22] + 8) != 0x31) {
    return;
  }
  sourceDef = IRInst__getOperandSource(inst,1);
  uVar2 = 0;
  if (sourceDef != 0) {
    sourceDef = IRInst__getOperandSource(inst,1);
    uVar2 = *(undefined4 *)(sourceDef + 0x98);
  }
  iVar1 = FUN_001267b8(uVar2);
  if (iVar1 == 0) {
    return;
  }
  sourceDef3 = (int *)IRInst__getOperandSource(inst,1);
  iVar1 = (**(code **)(*sourceDef3 + 0x5c))(sourceDef3);
  if (iVar1 != 0) {
    return;
  }
  if ((inst[5] & 0x200U) != 0) {
    return;
  }
  if (inst[0x48] != 0) {
    return;
  }
  sourceDef3 = (int *)IRInst__getOperandSource(inst,1);
  iVar1 = (**(code **)(*sourceDef3 + 0x48))(sourceDef3);
  if (iVar1 != 0) {
    return;
  }
  if (inst[0x49] == 0) {
    return;
  }
  if (((inst[0x2e] & 1U) == 0) && ((inst[0x2e] & 2U) == 0)) {
    operandRecord3 = IRInst__getOperandRecord(inst,1);
    iVar1 = FUN_000f3190(*(undefined4 *)(operandRecord3 + 0x10));
    if (iVar1 != 0) goto LAB_00188a5c;
  }
  iVar1 = FUN_00184bf0(inst);
  if (iVar1 == 0) {
    return;
  }
LAB_00188a5c:
  sourceDef2 = IRInst__getOperandSource(inst,1);
  iVar1 = FUN_00184ef0(sourceDef2,inst[0x49],param_2);
  if (iVar1 != 0) {
    *(int *)(param_2 + 0x160) = *(int *)(param_2 + 0x160) + 1;
    sourceDef2 = IRInst__getOperandSource(inst,1);
    puVar12 = (uint *)inst[4];
    uVar9 = puVar12[1] - 1;
    if (-1 < (int)uVar9) {
      do {
        if (uVar9 < *puVar12) {
          uVar4 = puVar12[1];
          if (uVar4 <= uVar9) {
            _memset(uVar4 * 4 + puVar12[2],0,(uVar9 - uVar4) * 4 + 4);
            puVar12[1] = uVar9 + 1;
          }
          puVar5 = (undefined4 *)(uVar9 * 4 + puVar12[2]);
        }
        else {
          puVar5 = (undefined4 *)Vector__elementRefGrow(puVar12,uVar9);
        }
        piVar13 = (int *)*puVar5;
        piVar3 = piVar13 + 0x20;
        for (iVar1 = 0; iVar8 = (**(code **)(*piVar13 + 0x14))(piVar13), iVar1 <= iVar8;
            iVar1 = iVar1 + 1) {
          operandVReg = (int *)IRInst__getOperandSource(piVar13,iVar1);
          if (inst == operandVReg) {
            uVar9 = uVar9 - 1;
            operandRecord2 = IRInst__getOperandRecord(operandVReg,1);
            uVar10 = *(undefined4 *)(operandRecord2 + 0x10);
            operandRecord2 = IRInst__getOperandRecord(piVar13,iVar1);
            FUN_000f2bdc(local_38,uVar10,*(undefined4 *)(operandRecord2 + 0x10));
            iVar8 = local_38[0];
            if ((*(int *)(piVar13[0x22] + 8) != 0x8e) ||
               (((operandRecord = FUN_000f3190(local_38[0]), operandRecord != 0 && ((inst[0x2e] & 1U) == 0)) &&
                ((inst[0x2e] & 2U) == 0)))) {
              IRInst__setOperandSource(piVar13,iVar1,sourceDef2,1,*(undefined4 *)(param_2 + 8));
              if (iVar1 == 0) {
                piVar13[0x27] = iVar8;
              }
              else {
                operandRecord = IRInst__getOperandRecord(piVar13,iVar1);
                *(int *)(operandRecord + 0x10) = iVar8;
              }
              IROperand__setModifierBits(piVar3 + 3,2,(uint)inst[0x2e] >> 1 & 1);
              if ((inst[0x2e] & 1U) != 0) {
                IROperand__setModifierBits(piVar3 + 3,1,piVar3[8] & 1U ^ 1);
              }
            }
          }
          piVar3 = piVar3 + 6;
        }
        if (((piVar13[5] & 0x200U) != 0) &&
           (piVar3 = (int *)IRInst__getOperandSource(piVar13,piVar13[0x21]), inst == piVar3)) {
          iVar1 = FUN_000f31e8(piVar3,1);
          if (iVar1 != 0) {
            local_44 = 0;
            local_58 = 0;
            local_54 = 0;
            FUN_00104d3c(piVar13,&local_58);
            uVar10 = *(undefined4 *)(param_2 + 8);
            sourceDef = IRInst__getOperandSource(piVar13,piVar13[0x21]);
            puVar12 = *(uint **)(sourceDef + 0x10);
            uVar4 = puVar12[1];
            if (0 < (int)uVar4) {
              loopIndex = 0;
              do {
                if (loopIndex < *puVar12) {
                  if (uVar4 <= loopIndex) {
                    _memset(uVar4 * 4 + puVar12[2],0,(loopIndex - uVar4) * 4 + 4);
                    puVar12[1] = loopIndex + 1;
                  }
                  piVar3 = (int *)(loopIndex * 4 + puVar12[2]);
                }
                else {
                  piVar3 = (int *)Vector__elementRefGrow(puVar12,loopIndex);
                }
                if (piVar13 == (int *)*piVar3) {
                  Vector__removeAt(puVar12,loopIndex);
                  sourceDef = IRInst__getOperandSource(piVar13,piVar13[0x21]);
                  *(int *)(sourceDef + 0x160) = *(int *)(sourceDef + 0x160) + -1;
                  break;
                }
                uVar4 = puVar12[1];
                loopIndex = loopIndex + 1;
              } while ((int)loopIndex < (int)uVar4);
            }
            IRInst__setOperandSource(piVar13,piVar13[0x21],0,1,uVar10);
            piVar13[0x21] = piVar13[0x21] + -1;
            piVar13[5] = piVar13[5] & 0xfffffdff;
            IRInst__setExtraOperandSource(piVar13,sourceDef2,1,*(undefined4 *)(param_2 + 8));
            iVar1 = local_48;
            if (piVar13[0x21] == 0) {
              piVar13[0x27] = local_48;
            }
            else {
              iVar8 = IRInst__getOperandRecord(piVar13,piVar13[0x21]);
              *(int *)(iVar8 + 0x10) = iVar1;
            }
          }
          uVar9 = uVar9 - 1;
        }
        if ((int)uVar9 < 0) break;
        puVar12 = (uint *)inst[4];
      } while( true );
    }
    useCount = IRInst__useCount(inst,param_2);
    if (useCount == 0) {
      DList__unlink(inst);
      (**(code **)(*inst + 0xc))(inst,1,*(undefined4 *)(param_2 + 8));
    }
  }
  return;
}

/* KhanPs__vslot27_optimizeInstruction @ 0x188e24 (256 bytes) */
int KhanPs__vslot27_optimizeInstruction(this, inst, program)
  undefined4 this;
  int inst;
  int program;
{
  int callResult;
  
  if ((*(uint *)(inst + 0x14) & 1) != 0) {
    ((int (*)())FUN_00187ad8)(inst,program);
    callResult = Compiler__isOptionEnabled(*(undefined4 *)(program + 8),0x36);
    if ((callResult == 0) || (Inst__splitAndMerge(inst,program), (*(uint *)(inst + 0x14) & 1) != 0)) {
      callResult = Compiler__isOptionEnabled(*(undefined4 *)(program + 8),0x15);
      if (callResult != 0) {
        Inst__reassociate_150b94(inst,program);
        Inst__reassociate_14e6e4(inst,program);
      }
      callResult = Compiler__isOptionEnabled(*(undefined4 *)(program + 8),0x16);
      if ((callResult != 0) && (callResult = IRInst__hasSingleUse(inst,program), callResult == 0)) {
        Inst__takeOutCommonFactor(inst,program);
      }
      callResult = Compiler__isOptionEnabled(*(undefined4 *)(program + 8),0x14);
      if (callResult != 0) {
        ((int (*)())Inst__movAndShiftUseVector)(inst,program);
        return;
      }
    }
  }
  return;
}

/* KhanVs__vslot29_swapIfArmsWhenNotFlattenable @ 0x188f24 (200 bytes) */
int KhanVs__vslot29_swapIfArmsWhenNotFlattenable(this, program)
  undefined4 this;
  int program;
{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined1 auStack_28 [24];
  
  piVar3 = *(int **)(program + 900);
  iVar1 = piVar3[2];
  while (iVar1 != 0) {
    iVar1 = (**(code **)(*piVar3 + 0x24))(piVar3);
    if (iVar1 != 0) {
      iVar2 = piVar3[0x4d];
      iVar1 = DList__count(iVar2 + 0x90);
      if ((((iVar1 < 3) && (iVar1 = Block__successorCount(iVar2), iVar1 == 1)) &&
          (iVar1 = Block__getSuccessor(iVar2,0), iVar1 == piVar3[0x4f])) &&
         (iVar1 = IfHeader__canFlatten(piVar3,auStack_28), iVar1 == 0)) {
        piVar3 = (int *)IfHeader__swapArms(program,piVar3);
      }
    }
    piVar3 = (int *)piVar3[2];
    iVar1 = piVar3[2];
  }
  return;
}

/* KhanVs__peepholeCombine @ 0x188fec (1280 bytes) */
int KhanVs__peepholeCombine(this, inst, consumerOperandArg, inst2, program, passThroughR8, hwLimitsOrArg)
  undefined4 this;
  int inst;
  int *consumerOperandArg;
  int *inst2;
  int *program;
  undefined4 passThroughR8;
  int hwLimitsOrArg;
{
  int callResult;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int *producerAlias;
  int *programAlias;
  undefined4 changedFlag;
  int foldStatus [8];
  
  changedFlag = 0;
  foldStatus[0] = 0;
  piVar4 = consumerOperandArg;
  producerAlias = inst2;
  programAlias = program;
  callResult = Compiler__isOptionEnabled(program[2],0x1b);
  if (callResult != 0) {
    changedFlag = (**(code **)(*inst2 + 100))(inst2);
    piVar4 = foldStatus;
    callResult = Inst__tryCopyPropagate(inst2,program,piVar4);
    piVar2 = inst2;
    if ((callResult != 0) &&
       (piVar2 = (int *)FUN_00146610(inst,consumerOperandArg,inst2), piVar4 = inst2,
       piVar2 == (int *)0x0)) {
      return 1;
    }
    inst2 = piVar2;
    if (inst != 0) {
      programAlias = foldStatus;
      piVar4 = piVar2;
      producerAlias = program;
      callResult = Inst__foldProducerIntoConsumer(inst,consumerOperandArg,piVar2,program,programAlias);
      if ((callResult != 0) &&
         (inst2 = (int *)FUN_00146610(inst,consumerOperandArg,piVar2), piVar4 = piVar2,
         inst2 == (int *)0x0)) {
        return 1;
      }
    }
  }
  callResult = Compiler__isOptionEnabled(program[2],0x1c);
  if (callResult != 0) {
    hwLimitsOrArg = **(int **)(program[2] + 0x30c);
    callResult = (**(code **)(hwLimitsOrArg + 0x84))(*(int **)(program[2] + 0x30c));
    if (((callResult != 0) && (callResult = Inst__collapseAlgebraic_00154dc0(inst2,program), callResult != 0)) &&
       (inst2 = (int *)FUN_00146610(inst,consumerOperandArg,inst2), inst2 == (int *)0x0)) {
      return 1;
    }
    callResult = Inst__collapseAlgebraic_00162cc0(inst2,program);
    if ((callResult != 0) &&
       (inst2 = (int *)FUN_00146610(inst,consumerOperandArg,inst2), inst2 == (int *)0x0)) {
      return 1;
    }
    callResult = (**(code **)(*inst2 + 0x14))(inst2);
    if (((int)consumerOperandArg <= callResult) &&
       (callResult = Inst__collapseAlgebraic_00158264(inst,consumerOperandArg,inst2,program), callResult != 0)) {
      inst2 = (int *)FUN_00146610(inst,consumerOperandArg,inst2);
      if (inst2 == (int *)0x0) {
        return 1;
      }
      changedFlag = 1;
    }
    callResult = Inst__collapseAlgebraic_00155a60(inst2,program);
    if (callResult != 0) {
      inst2 = (int *)FUN_00146610(inst,consumerOperandArg,inst2);
    }
    callResult = Inst__collapseAlgebraic_0014bdbc(inst2,program);
    if (callResult != 0) {
      inst2 = (int *)FUN_00146610(inst,consumerOperandArg,inst2);
    }
    piVar4 = (int *)0x0;
    producerAlias = (int *)((int)((unsigned char *)0x0) + 1);
    callResult = Inst__collapseAlgebraic_0014b82c(inst2,program,0,1);
    piVar2 = inst2;
    if (callResult != 0) {
      piVar2 = (int *)FUN_00146610(inst,consumerOperandArg,inst2);
      piVar4 = inst2;
    }
    callResult = Inst__collapseAlgebraic_0014b150(piVar2,program);
    piVar3 = piVar2;
    if (callResult != 0) {
      callResult = (**(code **)(*piVar2 + 100))(piVar2);
      if (((callResult != 0) && ((piVar2[5] & 0x200U) == 0)) && (inst != 0)) {
        programAlias = foldStatus;
        producerAlias = program;
        Inst__foldProducerIntoConsumer(inst,consumerOperandArg,piVar2,program,programAlias);
      }
      piVar3 = (int *)FUN_00146610(inst,consumerOperandArg,piVar2);
      if (piVar3 == (int *)0x0) {
        return 1;
      }
      changedFlag = 1;
      piVar4 = piVar2;
    }
    callResult = Inst__collapseAlgebraic_00150d38(piVar3,program);
    piVar2 = piVar3;
    if (callResult != 0) {
      piVar2 = (int *)FUN_00146610(inst,consumerOperandArg,piVar3);
      piVar4 = piVar3;
    }
    callResult = Inst__collapseAlgebraic_0015ceb0(piVar2,program);
    piVar3 = piVar2;
    if (callResult != 0) {
      piVar3 = (int *)FUN_00146610(inst,consumerOperandArg,piVar2);
      piVar4 = piVar2;
    }
    callResult = Inst__collapseAlgebraic_0015bd40(piVar3,program);
    piVar2 = piVar3;
    if (callResult != 0) {
      piVar2 = (int *)FUN_00146610(inst,consumerOperandArg,piVar3);
      piVar4 = piVar3;
    }
    callResult = Inst__collapseAlgebraic_00163994(piVar2,program);
    piVar3 = piVar2;
    if (callResult != 0) {
      piVar3 = (int *)FUN_00146610(inst,consumerOperandArg,piVar2);
      piVar4 = piVar2;
    }
    callResult = Inst__collapseAlgebraic_0015c6d4(piVar3,program);
    piVar2 = piVar3;
    if (callResult != 0) {
      piVar2 = (int *)FUN_00146610(inst,consumerOperandArg,piVar3);
      piVar4 = piVar3;
    }
    callResult = Inst__collapseAlgebraic_0014acb8(piVar2,program);
    piVar3 = piVar2;
    if (callResult != 0) {
      piVar3 = (int *)FUN_00146610(inst,consumerOperandArg,piVar2);
      piVar4 = piVar2;
    }
    callResult = Inst__collapseAlgebraic_0015e494(piVar3,program);
    inst2 = piVar3;
    if (callResult != 0) {
      inst2 = (int *)FUN_00146610(inst,consumerOperandArg,piVar3);
      piVar4 = piVar3;
    }
  }
  callResult = Compiler__isOptionEnabled(program[2],0x1d);
  if ((((callResult != 0) &&
       (callResult = Inst__tryCollapseSimilar(inst2,program,piVar4,producerAlias,programAlias,passThroughR8,hwLimitsOrArg), callResult != 0)) &&
      ((callResult = (**(code **)(*inst2 + 100))(inst2), callResult != 0 &&
       ((inst != 0 &&
        (callResult = Inst__foldProducerIntoConsumer(inst,consumerOperandArg,inst2,program,foldStatus), callResult != 0)))))) &&
     (inst2 = (int *)FUN_00146610(inst,consumerOperandArg,inst2), inst2 == (int *)0x0)) {
    return 1;
  }
  callResult = Compiler__isOptionEnabled(program[2],0x3a);
  if (callResult == 0) {
    return changedFlag;
  }
  if ((program[0x8a] < *(int *)(program[2] + 0x664)) &&
     (callResult = Inst__tryMix(inst,consumerOperandArg,inst2,program), callResult != 0)) {
    changedFlag = 1;
    inst2 = (int *)FUN_00146610(inst,consumerOperandArg,inst2);
  }
  callResult = FUN_0015f44c(inst,consumerOperandArg,inst2,program);
  if (callResult != 0) {
    FUN_00146610(inst,consumerOperandArg,inst2);
    return 1;
  }
  return changedFlag;
}

/* KhanVs__vslot27_optimizeInstruction @ 0x1894ec (116 bytes) */
int KhanVs__vslot27_optimizeInstruction(this, inst, program)
  undefined4 this;
  int inst;
  int program;
{
  int iVar1;
  
  if (((*(uint *)(inst + 0x14) & 1) != 0) &&
     (iVar1 = Compiler__isOptionEnabled(*(undefined4 *)(program + 8),0x15), iVar1 != 0)) {
    Inst__reassociate_150b94(inst,program);
    Inst__reassociate_14e6e4(inst,program);
    return;
  }
  return;
}

/* PackState__reset @ 0x189560 (64 bytes) */
int PackState__reset(state)
  undefined4 *state;
{
  bool bVar1;
  int loopIndex;
  
  loopIndex = 0;
  state[5] = 0;
  *state = 0;
  state[1] = 0;
  state[2] = 0;
  state[3] = 0;
  state[4] = 0;
  do {
    bVar1 = loopIndex != 2;
    state[6] = 0;
    state[9] = 0;
    loopIndex = loopIndex + 1;
    state[0xc] = 0;
    state = state + 1;
  } while (bVar1);
  return;
}

/* PackState__copy @ 0x1895a0 (100 bytes) */
int PackState__copy(dest, source)
  undefined4 *dest;
  undefined4 *source;
{
  undefined4 *puVar1;
  bool bVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int loopIndex;
  
  uVar4 = *source;
  dest[2] = source[2];
  uVar3 = source[3];
  *dest = uVar4;
  loopIndex = 0;
  dest[3] = uVar3;
  uVar4 = source[1];
  dest[4] = source[4];
  uVar3 = source[5];
  dest[1] = uVar4;
  dest[5] = uVar3;
  do {
    bVar2 = loopIndex != 2;
    loopIndex = loopIndex + 1;
    dest[6] = source[6];
    puVar1 = source + 9;
    uVar3 = source[0xc];
    source = source + 1;
    dest[9] = *puVar1;
    dest[0xc] = uVar3;
    dest = dest + 1;
  } while (bVar2);
  return;
}

/* R520SchedModel__vslot2_reset @ 0x189604 (40 bytes) */
int R520SchedModel__vslot2_reset(param_1)
  int param_1;
{
  *(undefined4 *)(param_1 + 0x24) = 0xffffffff;
  *(undefined4 *)(param_1 + 100) = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x1c) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x20) = 0xffffffff;
  return ((int (*)())PackState__reset)(param_1 + 0x28);
}

/* KhanPs__vslot31_isNotTextureFetch @ 0x18962c (52 bytes) */
int KhanPs__vslot31_isNotTextureFetch(this, inst)
  undefined4 this;
  int *inst;
{
  uint uVar1;
  
  uVar1 = (**(code **)(*inst + 0x30))(inst,inst);
  return uVar1 ^ 1;
}

/* KhanPs__vslot65_isEncodableSourceSwizzle @ 0x189660 (152 bytes) */
int KhanPs__vslot65_isEncodableSourceSwizzle(this, param_2, param_3, param_4, param_5)
  int *this;
  undefined4 param_2;
  undefined4 param_3;
  int *param_4;
  int *param_5;
{
  int iVar1;
  undefined4 callResult;
  
  if (((param_5 != (int *)0x0) && (iVar1 = (**(code **)(*param_5 + 0x4c))(param_5), iVar1 != 0)) &&
     (*param_4 == 0x10304)) {
    return 1;
  }
                    
                    
  callResult = (**(code **)(*this + 0x100))(this,param_4);
  return callResult;
}

/* FUN_001896f8 @ 0x1896f8 (108 bytes) */
int FUN_001896f8(param_1)
  uint param_1;
{
  return *(uint *)(&DAT_001b0244 +
                  ((param_1 >> 0x18) * 0x7d + (param_1 >> 0x10 & 0xff) * 0x19 +
                   (param_1 >> 8 & 0xff) * 5 + (param_1 & 0xff)) * 0x10) ==
         ((uint)(byte)DAT_001b2a68 << 0x18 | (uint)(*(unsigned char *)((unsigned char *)&(DAT_001b2a68) + 2)) << 0x10 |
          (uint)(*(unsigned char *)((unsigned char *)&(DAT_001b2a68) + 1)) << 8 | (uint)(*(unsigned char *)((unsigned char *)&(DAT_001b2a68) + 0)));
}

/* FUN_0018976c @ 0x18976c (28 bytes) */
int FUN_0018976c(param_1)
  undefined4 param_1;
{
  undefined4 callResult;
  
  callResult = FUN_000f2d18(param_1,DAT_001b2a64);
  return callResult;
}

/* FUN_00189788 @ 0x189788 (104 bytes) */
int FUN_00189788(param_1)
  undefined4 param_1;
{
  int callResult;
  undefined4 *loopIndex;
  
  loopIndex = &DAT_001b2994;
  do {
    callResult = FUN_000f2d18(*loopIndex,param_1);
    if (callResult != 0) {
      return 1;
    }
    loopIndex = loopIndex + 1;
  } while (loopIndex != (undefined4 *)&UNK_001b29e4);
  return 0;
}

/* KhanPs__vslot66_callHelper189788 @ 0x1897f0 (8 bytes) */
int KhanPs__vslot66_callHelper189788(this, param_2)
  undefined4 this;
  undefined4 *param_2;
{
  return ((int (*)())FUN_00189788)(*param_2);
}

/* FUN_001897fc @ 0x1897fc (68 bytes) */
int FUN_001897fc(inst, param_2)
  undefined4 inst;
  undefined4 param_2;
{
  int operandVReg;
  bool bVar2;
  
  operandVReg = IRInst__getOperandSource(inst,param_2);
  bVar2 = false;
  if (*(int *)(operandVReg + 0x98) == 0x33) {
    bVar2 = *(int *)(operandVReg + 300) != 3;
  }
  return bVar2;
}

/* SchedModel__fitsConstantLimit @ 0x189840 (364 bytes) */
int SchedModel__fitsConstantLimit(schedModel, instA, instB, inlineLimit, otherLimit)
  int schedModel;
  int *instA;
  int *instB;
  int inlineLimit;
  int otherLimit;
{
  int *a0;
  int loopRemaining;
  int loopIndex;
  int loopRemaining2;
  int iVar4;
  int iVar5;
  int *piVar6;
  int *local_58 [12];
  
  iVar4 = 0;
  do {
    loopRemaining2 = 2;
    piVar6 = instA;
    do {
      for (iVar5 = 1; loopRemaining = (**(code **)(*piVar6 + 0x14))(piVar6), iVar5 <= loopRemaining;
          iVar5 = iVar5 + 1) {
        a0 = (int *)IRInst__getOperandSource(piVar6,iVar5);
        loopRemaining = (**(code **)(*a0 + 0x60))(a0);
        if (loopRemaining == 0) {
LAB_001898e0:
          loopRemaining = (**(code **)(*a0 + 0x48))(a0);
          if ((loopRemaining != 0) && (a0[0x4b] == 3)) {
            if (iVar4 < 1) {
LAB_00189934:
              loopRemaining = iVar4 + 1;
              local_58[iVar4] = a0;
              iVar4 = loopRemaining;
              if (inlineLimit + otherLimit < loopRemaining) {
                return 0;
              }
            }
            else if (local_58[0] != a0) {
              loopIndex = 0;
              loopRemaining = iVar4;
              do {
                loopIndex = loopIndex + 1;
                loopRemaining = loopRemaining + -1;
                if (loopRemaining == 0) goto LAB_00189934;
              } while (a0 != local_58[loopIndex]);
            }
          }
        }
        else {
          loopRemaining = IRInst__hasSingleUse(a0,*(undefined4 *)(*(int *)(schedModel + 8) + 0x6c4));
          if (loopRemaining != 0) {
            a0 = (int *)IRInst__getOperandSource(a0,1);
            goto LAB_001898e0;
          }
        }
      }
      loopRemaining2 = loopRemaining2 + -1;
      if (loopRemaining2 == 0) {
        return 1;
      }
      piVar6 = instB;
    } while (loopRemaining2 != 2);
  } while( true );
}

/* SchedModel__assignConstantSelectors @ 0x1899ac (568 bytes) */
int SchedModel__assignConstantSelectors(schedModel, instA, instB, param_4, inlineLimit)
  int schedModel;
  int *instA;
  int *instB;
  undefined4 param_4;
  int inlineLimit;
{
  int *operandVReg;
  bool bVar1;
  int *piVar2;
  int *a0;
  int loopIndex;
  int iVar4;
  int loopIndex2;
  int loopIndex3;
  int iVar7;
  int loopIndex4;
  int *piVar9;
  int *piVar10;
  int *local_68 [13];
  
  loopIndex2 = 0;
  do {
    loopIndex3 = 0;
    piVar10 = instA;
    do {
      iVar7 = 1;
      if (piVar10 != (int *)0x0) {
        for (; iVar4 = (**(code **)(*piVar10 + 0x14))(piVar10), iVar7 <= iVar4; iVar7 = iVar7 + 1) {
          a0 = (int *)IRInst__getOperandSource(piVar10,iVar7);
          loopIndex = (**(code **)(*a0 + 0x60))(a0);
          iVar4 = iVar7;
          piVar9 = piVar10;
          if (loopIndex == 0) {
LAB_00189a60:
            loopIndex = (**(code **)(*a0 + 0x48))(a0);
            if ((loopIndex != 0) && (a0[0x4b] == 3)) {
              if (loopIndex2 < 1) {
                loopIndex = 0;
LAB_00189ab0:
                local_68[loopIndex2] = a0;
                loopIndex2 = loopIndex2 + 1;
              }
              else {
                loopIndex = 0;
                loopIndex4 = loopIndex2;
                piVar2 = local_68[0];
                while (a0 != piVar2) {
                  loopIndex = loopIndex + 1;
                  loopIndex4 = loopIndex4 + -1;
                  if (loopIndex4 == 0) goto LAB_00189ab0;
                  piVar2 = local_68[loopIndex];
                }
              }
              loopIndex4 = 0;
              if (loopIndex < inlineLimit) {
                do {
                  loopIndex = IRInst__getOperandRecord(piVar9,iVar4);
                  if (*(char *)(loopIndex4 + loopIndex + 0x10) != '\x04') {
                    (**(code **)(*piVar9 + 0x88))(piVar9,iVar4,loopIndex4,3);
                  }
                  bVar1 = loopIndex4 != 3;
                  loopIndex4 = loopIndex4 + 1;
                } while (bVar1);
                *(undefined1 *)((int)a0 + 0x9f) = 0;
              }
              else {
                do {
                  loopIndex = IRInst__getOperandRecord(piVar9,iVar4);
                  if (*(char *)(loopIndex4 + loopIndex + 0x10) != '\x04') {
                    (**(code **)(*piVar9 + 0x88))(piVar9,iVar4,loopIndex4,0);
                  }
                  bVar1 = loopIndex4 != 3;
                  loopIndex4 = loopIndex4 + 1;
                } while (bVar1);
                *(undefined1 *)(a0 + 0x27) = 0;
              }
            }
          }
          else {
            iVar4 = IRInst__hasSingleUse(a0,*(undefined4 *)(*(int *)(schedModel + 8) + 0x6c4));
            if (iVar4 != 0) {
              operandVReg = (int *)IRInst__getOperandSource(a0,1);
              iVar4 = 1;
              piVar9 = a0;
              a0 = operandVReg;
              goto LAB_00189a60;
            }
          }
        }
      }
      bVar1 = loopIndex3 == 1;
      loopIndex3 = loopIndex3 + 1;
      if (bVar1) {
        return;
      }
      piVar10 = instB;
    } while (loopIndex3 != 0);
  } while( true );
}

/* R300SchedModel__vslot15 @ 0x189be4 (64 bytes) */
int R300SchedModel__vslot15(this, param_2)
  undefined4 this;
  int param_2;
{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(param_2 + 0x88) + 8);
  if ((iVar1 == 0x1e) || (iVar1 == 0x1d)) {
    return 1;
  }
  if ((iVar1 != 0x1c) && (iVar1 != 0xa3)) {
    return 0;
  }
  return 2;
}

/* FUN_00189c24 @ 0x189c24 (188 bytes) */
int FUN_00189c24(inst)
  int *inst;
{
  int operandRecord;
  int sourceDef;
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  uVar2 = 0;
  (**(code **)(*inst + 0x5c))(inst);
  iVar4 = *(int *)(inst[0x22] + 8);
  sourceDef = IRInst__getOperandSource(inst,1);
  uVar3 = *(uint *)(sourceDef + 0x94);
  iVar1 = (**(code **)(*inst + 0x14))(inst);
  if (1 < iVar1) {
    sourceDef = IRInst__getOperandSource(inst,2);
    uVar2 = *(uint *)(sourceDef + 0x94) & 0xfff;
  }
  operandRecord = IRInst__getOperandRecord(inst,0);
  return uVar2 | iVar4 << 0x19 | -(*(byte *)(operandRecord + 0x13) ^ 1) >> 7 & 0x1000000 |
                 (uVar3 & 0xfff) << 0xc;
}

/* FUN_00189ce0 @ 0x189ce0 (276 bytes) */
int FUN_00189ce0(inst, inst2)
  int *inst;
  int *inst2;
{
  char cVar1;
  int callResult;
  int operandVReg;
  
  callResult = (**(code **)(*inst + 0x5c))(inst,inst2);
  if (callResult != 0) {
    (**(code **)(*inst2 + 0x5c))(inst2);
  }
  if (*(int *)(inst[0x22] + 8) == *(int *)(inst2[0x22] + 8)) {
    callResult = IRInst__getOperandRecord(inst,0);
    cVar1 = *(char *)(callResult + 0x13);
    callResult = IRInst__getOperandRecord(inst2,0);
    if (cVar1 == *(char *)(callResult + 0x13)) {
      callResult = IRInst__getOperandSource(inst,1);
      operandVReg = IRInst__getOperandSource(inst2,1);
      if (callResult == operandVReg) {
        callResult = (**(code **)(*inst + 0x14))(inst);
        if (1 < callResult) {
          callResult = IRInst__getOperandSource(inst,2);
          operandVReg = IRInst__getOperandSource(inst2,2);
          if (callResult != operandVReg) {
            return 0xffffffff;
          }
        }
        return 0;
      }
    }
  }
  return 0xffffffff;
}

/* FUN_00189df4 @ 0x189df4 (480 bytes) */
int FUN_00189df4(inst, param_2, param_3)
  int *inst;
  int *param_2;
  int *param_3;
{
  int operandRecord;
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  iVar2 = (**(code **)(*inst + 0x28))(inst,param_2,param_3);
  if ((iVar2 == 0) && (*(int *)(inst[0x22] + 4) != 1)) {
    iVar4 = *(int *)(inst[0x22] + 8);
    iVar2 = iVar4;
    if ((iVar4 - 0x1cU < 3) || (iVar4 == 0xa3)) {
      if (((iVar4 == 0x1d) || (iVar4 == 0xa3)) ||
         (iVar4 = IRInst__getOperandRecord(inst,0), *(char *)(iVar4 + 0x13) == '\0')) {
        iVar4 = 0x97;
      }
      else {
        iVar4 = -1;
      }
LAB_00189f70:
      if (iVar2 < 0) goto LAB_00189f94;
LAB_00189f84:
      if (*param_2 < 0) {
        *param_2 = iVar2;
        goto LAB_00189f94;
      }
    }
    else {
      if (((((iVar4 != 0x37) && (iVar4 != 0x3a)) &&
           ((iVar4 != 0x3b && ((iVar4 != 0x3e && (iVar4 != 0x3f)))))) && (iVar4 != 0x40)) &&
         ((((iVar4 != 0x41 && (iVar4 != 0x42)) && (iVar4 != 0x43)) &&
          ((iVar4 != 0x4c && (iVar4 != 0x4d)))))) {
        iVar2 = IRInst__getOperandRecord(inst,0);
        uVar1 = *(uint *)(iVar2 + 0x10);
        if ((uVar1 >> 0x18 == 0) ||
           (((uVar1 >> 0x10 & 0xff) == 0 || (iVar2 = -1, (uVar1 >> 8 & 0xff) == 0)))) {
          iVar2 = iVar4;
        }
        if ((uVar1 & 0xff) != 0) {
          iVar4 = -1;
        }
        goto LAB_00189f70;
      }
      operandRecord = IRInst__getOperandRecord(inst,0);
      uVar1 = *(uint *)(operandRecord + 0x10);
      if (((uVar1 >> 0x18 == 0) || ((uVar1 >> 0x10 & 0xff) == 0)) || ((uVar1 >> 8 & 0xff) == 0)) {
        iVar2 = 0x98;
        goto LAB_00189f84;
      }
LAB_00189f94:
      if (iVar4 < 0) goto LAB_00189fb4;
      if (*param_3 < 0) {
        *param_3 = iVar4;
        return 1;
      }
    }
    uVar3 = 0;
  }
  else {
LAB_00189fb4:
    uVar3 = 1;
  }
  return uVar3;
}

/* R300SchedModel__vslot19 @ 0x189fd4 (172 bytes) */
int R300SchedModel__vslot19(this, param_2, param_3, param_4, param_5, param_6, param_7)
  undefined4 this;
  int *param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  int callResult;
  undefined4 uVar2;
  int local_28;
  int local_24 [7];
  
  local_24[0] = -1;
  local_28 = -1;
  if ((param_2[5] & 0x8000U) == 0) {
    callResult = (**(code **)(*param_2 + 0x28))(param_2);
    if (callResult == 0) {
      ((int (*)())FUN_00189df4)(param_2,&local_28,local_24);
      if (local_28 < 0) {
        if (-1 < local_24[0]) {
          return 2;
        }
        goto LAB_0018a060;
      }
      if (local_24[0] < 0) {
        return 1;
      }
    }
    uVar2 = 3;
  }
  else {
LAB_0018a060:
    uVar2 = 0;
  }
  return uVar2;
}

/* R300SchedModel__vslot34 @ 0x18a080 (364 bytes) */
int R300SchedModel__vslot34(this, inst)
  undefined4 this;
  int *inst;
{
  int callResult;
  undefined4 uVar2;
  int *a0;
  int iVar3;
  
  callResult = (**(code **)(*inst + 0x30))(inst,inst);
  if (callResult != 0) {
    callResult = IRInst__getOperandRecord(inst,1);
    uVar2 = ((int (*)())FUN_0018976c)(*(undefined4 *)(callResult + 0x10));
    return uVar2;
  }
  iVar3 = 1;
  callResult = (**(code **)(*inst + 0x5c))(inst);
  if (callResult == 0) {
    for (; callResult = (**(code **)(*inst + 0x14))(inst), iVar3 <= callResult; iVar3 = iVar3 + 1) {
      callResult = IRInst__getOperandRecord(inst,iVar3);
      uVar2 = *(undefined4 *)(callResult + 0x10);
      a0 = (int *)IRInst__getOperandSource(inst,iVar3);
      callResult = (**(code **)(*a0 + 0x5c))(a0);
      if (callResult == 0) {
        callResult = ((int (*)())FUN_001896f8)(uVar2);
      }
      else {
        callResult = ((int (*)())FUN_00189788)(uVar2);
      }
      if (callResult == 0) {
        return 0;
      }
    }
  }
  else {
    callResult = (**(code **)(*inst + 0x14))(inst);
    if (callResult != 1) {
      callResult = IRInst__getOperandRecord(inst,1);
      iVar3 = *(int *)(callResult + 0x10);
      callResult = IRInst__getOperandRecord(inst,2);
      if (iVar3 != *(int *)(callResult + 0x10)) {
        return 0;
      }
    }
  }
  return 1;
}

/* R300SchedModel__vslot26 @ 0x18a1ec (596 bytes) */
int R300SchedModel__vslot26(this, inst, param_3, param_4, param_5)
  undefined4 this;
  int *inst;
  int param_3;
  int param_4;
  int *param_5;
{
  int iVar1;
  int *a0;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  *param_5 = 0;
  iVar1 = IRInst__getOperandRecord(inst,param_3);
  uVar4 = *(uint *)(iVar1 + 0x10);
  iVar1 = (**(code **)(*inst + 0x28))(inst);
  if (iVar1 == 0) {
    iVar1 = (**(code **)(*inst + 0x5c))(inst);
    if (iVar1 != 0) {
      iVar1 = FUN_000f31e8(inst,1);
      if (iVar1 == 0) {
        return;
      }
      iVar1 = (**(code **)(*inst + 0x14))(inst);
      if (iVar1 == 1) {
        return;
      }
      FUN_000f31e8(inst,2);
      return;
    }
    a0 = (int *)IRInst__getOperandSource(inst,param_3);
    iVar1 = (**(code **)(*a0 + 0x5c))(a0);
    if (iVar1 == 0) {
      iVar1 = ((int (*)())FUN_001896f8)(uVar4);
    }
    else {
      iVar1 = ((int (*)())FUN_00189788)(uVar4);
    }
  }
  else {
    if (param_3 != 1) {
      return;
    }
    iVar1 = ((int (*)())FUN_0018976c)(uVar4);
  }
  if (iVar1 == 0) {
    iVar1 = ((uVar4 >> 0x18) * 0x7d + (uVar4 >> 0x10 & 0xff) * 0x19 + (uVar4 >> 8 & 0xff) * 5 +
            (uVar4 & 0xff)) * 4;
    for (iVar2 = *(int *)(&DAT_001b0240 + (iVar1 + *param_5) * 4); iVar2 != 0x4040404;
        iVar2 = *(int *)(&DAT_001b0240 + (iVar1 + iVar2 + 1) * 4)) {
      uVar3 = *(uint *)(&DAT_001b0240 + (iVar1 + *param_5) * 4);
      *(uint *)(*param_5 * 4 + param_4) =
           uVar3 << 0x18 | (uVar3 & 0xff00) << 8 | uVar3 >> 8 & 0xff00 | uVar3 >> 0x18;
      iVar2 = *param_5;
      *param_5 = iVar2 + 1;
    }
    if (uVar4 >> 0x18 != 4) {
      uVar4 = uVar4 & 0xffffff;
    }
    if ((uVar4 >> 0x10 & 0xff) != 4) {
      uVar4 = uVar4 & 0xff00ffff | 0x10000;
    }
    if ((uVar4 >> 8 & 0xff) != 4) {
      uVar4 = uVar4 & 0xffff00ff | 0x200;
    }
    if ((uVar4 & 0xff) != 4) {
      uVar4 = uVar4 & 0xffffff00 | 3;
    }
    iVar1 = IRInst__getOperandRecord(inst,param_3);
    *(uint *)(iVar1 + 0x10) = uVar4;
  }
  return;
}

/* R300SchedModel__vslot28 @ 0x18a440 (232 bytes) */
int R300SchedModel__vslot28(this, param_2)
  int *this;
  int param_2;
{
  int operandRecord;
  undefined4 arenaAt378;
  int *operandVReg;
  char cVar1;
  int *piVar2;
  uint uVar3;
  int *piVar4;
  undefined4 *puVar5;
  undefined4 operandVReg2;
  int *callResult;
  int loopIndex2;
  int loopRemaining;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  uint *puVar15;
  undefined4 uVar16;
  uint loopIndex3;
  int loopIndex;
  double dVar19;
  undefined4 local_78;
  int local_74 [3];
  undefined4 local_68;
  undefined4 local_64;
  uint local_60;
  int local_5c;
  int local_58;
  
  iVar14 = *(int *)(param_2 + 900);
  if (*(int *)(iVar14 + 8) != 0) {
    local_5c = 0x18a450;
    local_58 = 0x18a450;
    do {
      arenaAt378 = *(undefined4 *)(this[2] + 0x378);
      puVar5 = (undefined4 *)Arena__alloc(arenaAt378,0x1c);
      puVar15 = puVar5 + 1;
      *puVar5 = arenaAt378;
      puVar5[4] = local_5c + -0x770;
      uVar3 = 1;
      loopIndex = 0x20;
      puVar5[1] = 1;
      puVar5[5] = local_58 + -0x82c;
      puVar5[6] = arenaAt378;
      do {
        uVar3 = uVar3 << 1;
        if (0xf < uVar3) break;
        loopIndex = loopIndex + -1;
      } while (loopIndex != 0);
      *puVar15 = uVar3;
      puVar5[2] = 0;
      uVar16 = Arena__alloc(arenaAt378,*puVar15 << 2);
      puVar5[3] = uVar16;
      _memset(uVar16,0,*puVar15 << 2);
      piVar2 = *(int **)(iVar14 + 0x98);
      for (piVar4 = (int *)(*(int **)(iVar14 + 0x98))[2]; piVar4 != (int *)0x0;
          piVar4 = (int *)piVar4[2]) {
        if ((piVar2[5] & 1U) != 0) {
          if ((*(int *)(piVar2[0x22] + 8) == 0x31) || (*(int *)(piVar2[0x22] + 8) == 0x30)) {
            operandVReg = (int *)IRInst__getOperandSource(piVar2,1);
            loopIndex = (**(code **)(*operandVReg + 0x5c))();
            if ((loopIndex != 0) && ((piVar2[0x2e] & 2U) == 0)) {
              operandVReg = (int *)IRInst__getOperandSource(piVar2,1);
              loopIndex = piVar2[0x49];
              if (*(int *)(operandVReg[0x22] + 8) == 0x99) {
                loopIndex = loopIndex + 1;
              }
              iVar10 = (**(code **)(**(int **)(this[2] + 0x30c) + 0xfc))
                                 (*(int **)(this[2] + 0x30c),loopIndex,0);
              if (iVar10 != 0) {
                loopRemaining = piVar2[1];
                loopIndex2 = 0;
                iVar11 = piVar2[0x25];
                iVar12 = piVar2[0x26];
                operandRecord = IRInst__getOperandRecord(piVar2,0);
                iVar13 = *(int *)(operandRecord + 0x10);
                operandRecord = IRInst__getOperandRecord(piVar2,1);
                loopIndex3 = piVar2[5];
                uVar3 = piVar2[0x2e] & 1;
                uVar16 = *(undefined4 *)(operandRecord + 0x10);
                iVar10 = piVar2[0x48];
                if ((loopIndex3 & 0x200) != 0) {
                  loopIndex2 = IRInst__getOperandSource(piVar2,piVar2[0x21]);
                }
                DList__unlink(piVar2);
                FUN_00108174(piVar2,0x12,*(undefined4 *)(param_2 + 8));
                piVar2[0x27] = iVar13;
                piVar2[0x48] = iVar10;
                piVar2[0x49] = loopIndex;
                piVar2[0x25] = iVar11;
                piVar2[0x26] = iVar12;
                if ((loopIndex3 & 0x40) == 0) {
                  piVar2[5] = piVar2[5] & 0xffffffbf;
                }
                else {
                  piVar2[5] = piVar2[5] | 0x40;
                }
                if ((loopIndex3 & 2) != 0) {
                  FUN_0010469c(piVar2,*(undefined4 *)(this[2] + 0x6c4),iVar12,iVar11);
                }
                if (loopIndex2 != 0) {
                  IRInst__setExtraOperandSource(piVar2,loopIndex2,0,this[2]);
                }
                Block__insertInstAfter(iVar14,loopRemaining,piVar2);
                loopIndex = *(int *)(operandVReg[0x22] + 8);
                if (loopIndex == 0x9a) {
                  operandVReg2 = IRInst__getOperandSource(operandVReg,1);
                  IRInst__setOperandSource(piVar2,1,operandVReg2,0,this[2]);
                  operandVReg2 = IRInst__getOperandSource(operandVReg,2);
                  IRInst__setOperandSource(piVar2,2,operandVReg2,0,this[2]);
                  loopIndex = IRInst__getOperandRecord(piVar2,1);
                  *(undefined4 *)(loopIndex + 0x10) = uVar16;
                  loopIndex = IRInst__getOperandRecord(piVar2,2);
                  *(undefined4 *)(loopIndex + 0x10) = uVar16;
                  IROperand__setModifierBits(piVar2 + 0x29,1,uVar3);
                  IROperand__setModifierBits(piVar2 + 0x2f,1,uVar3 ^ 1);
                }
                else {
                  if (loopIndex < 0x9b) {
                    if (loopIndex != 0x99) goto code_r0x0018a910;
                    operandVReg2 = IRInst__getOperandSource(operandVReg,1);
                    IRInst__setOperandSource(piVar2,1,operandVReg2,0,this[2]);
                    dVar19 = (double)FLOAT_001aa10c;
                    ((void (*)())FUN_000f79c4)(piVar2,param_2,2,dVar19,dVar19,dVar19,dVar19);
                    loopIndex = IRInst__getOperandRecord(piVar2,1);
                    *(undefined4 *)(loopIndex + 0x10) = uVar16;
                    loopIndex3 = uVar3 ^ 1;
                  }
                  else if (loopIndex == 0x9b) {
                    operandVReg2 = IRInst__getOperandSource(operandVReg,1);
                    IRInst__setOperandSource(piVar2,1,operandVReg2,0,this[2]);
                    operandVReg2 = IRInst__getOperandSource(operandVReg,2);
                    IRInst__setOperandSource(piVar2,2,operandVReg2,0,this[2]);
                    loopIndex = IRInst__getOperandRecord(piVar2,1);
                    *(undefined4 *)(loopIndex + 0x10) = uVar16;
                    loopIndex = IRInst__getOperandRecord(piVar2,2);
                    *(undefined4 *)(loopIndex + 0x10) = uVar16;
                    loopIndex3 = uVar3;
                  }
                  else {
                    if (loopIndex != 0x9c) goto code_r0x0018a910;
                    operandVReg2 = IRInst__getOperandSource(operandVReg,1);
                    IRInst__setOperandSource(piVar2,1,operandVReg2,0,this[2]);
                    dVar19 = (double)FLOAT_001aa0e8;
                    ((void (*)())FUN_000f79c4)(piVar2,param_2,2,dVar19,dVar19,dVar19,dVar19);
                    loopIndex = IRInst__getOperandRecord(piVar2,1);
                    *(undefined4 *)(loopIndex + 0x10) = uVar16;
                    loopIndex3 = uVar3 ^ 1;
                  }
                  IROperand__setModifierBits(piVar2 + 0x29,1,loopIndex3);
                  IROperand__setModifierBits(piVar2 + 0x2f,1,uVar3);
                }
code_r0x0018a910:
                (**(code **)(*operandVReg + 0xc))(operandVReg,0,this[2]);
                piVar4 = (int *)piVar2[2];
                goto code_r0x0018aab8;
              }
            }
          }
          for (loopIndex = 1; iVar10 = (**(code **)(*piVar2 + 0x14))(piVar2), loopIndex <= iVar10;
              loopIndex = loopIndex + 1) {
            operandVReg = (int *)IRInst__getOperandSource(piVar2,loopIndex);
            iVar10 = (**(code **)(*operandVReg + 0x5c))();
            if (iVar10 != 0) {
              callResult = (int *)HashTable__find(puVar15,operandVReg);
              if (callResult == (int *)0x0) {
                HashTable__insert(puVar15,operandVReg);
              }
              else if (operandVReg != callResult) {
                iVar10 = IRInst__getOperandRecord(callResult,0);
                local_74[0] = *(int *)(iVar10 + 0x10);
                loopRemaining = IRInst__getOperandRecord(operandVReg,0);
                iVar10 = DAT_001b2a64;
                loopIndex2 = 0;
                local_78 = *(undefined4 *)(loopRemaining + 0x10);
                loopRemaining = 4;
                do {
                  cVar1 = *(char *)((int)local_74 + loopIndex2 + -4);
                  if (cVar1 != '\x01') {
                    *(char *)((int)local_74 + loopIndex2) = cVar1;
                  }
                  loopIndex2 = loopIndex2 + 1;
                  loopRemaining = loopRemaining + -1;
                } while (loopRemaining != 0);
                callResult[0x27] = local_74[0];
                FUN_000f3908(&local_68,local_74[0]);
                FUN_000f3340(&local_64,iVar10,local_68);
                uVar16 = local_64;
                iVar10 = IRInst__getOperandRecord(callResult,1);
                *(undefined4 *)(iVar10 + 0x10) = uVar16;
                iVar10 = (**(code **)(*callResult + 0x14))(callResult);
                if (1 < iVar10) {
                  iVar10 = IRInst__getOperandRecord(callResult,2);
                  *(undefined4 *)(iVar10 + 0x10) = uVar16;
                }
                IRInst__setOperandSource(piVar2,loopIndex,callResult,0,this[2]);
                (**(code **)(*operandVReg + 0xc))(operandVReg,0,this[2]);
              }
            }
          }
          piVar4 = (int *)piVar2[2];
        }
code_r0x0018aab8:
        piVar2 = piVar4;
      }
      if (puVar15 != (uint *)0x0) {
        uVar3 = *puVar15;
        if (uVar3 == 0) {
          loopIndex = puVar5[3];
        }
        else {
          loopIndex = puVar5[3];
          loopIndex3 = 0;
          do {
            iVar10 = *(int *)(loopIndex3 * 4 + loopIndex);
            if (iVar10 != 0) {
              Arena__free(puVar5[6],iVar10);
              uVar3 = *puVar15;
              loopIndex = puVar5[3];
            }
            loopIndex3 = loopIndex3 + 1;
          } while (loopIndex3 < uVar3);
        }
        Arena__free(puVar5[6],loopIndex);
        Arena__free(*puVar5,puVar5);
      }
      piVar2 = *(int **)(iVar14 + 0x98);
      for (piVar4 = (int *)(*(int **)(iVar14 + 0x98))[2]; piVar4 != (int *)0x0;
          piVar4 = (int *)piVar4[2]) {
        if ((piVar2[5] & 1U) != 0) {
          iVar10 = 1;
          loopIndex = Compiler__isOptionEnabled(this[2],0x41);
          if (loopIndex != 0) {
            for (; loopIndex = (**(code **)(*piVar2 + 0x14))(piVar2), iVar10 <= loopIndex;
                iVar10 = iVar10 + 1) {
              operandVReg = (int *)IRInst__getOperandSource(piVar2,iVar10);
              loopIndex = (**(code **)(*operandVReg + 0x80))();
              loopIndex2 = IRInst__getOperandRecord(piVar2,iVar10);
              FUN_000f39d0(&local_60,*(undefined4 *)(loopIndex2 + 0x10));
              uVar3 = local_60;
              loopIndex2 = IRInst__getOperandRecord(piVar2,iVar10);
              loopIndex3 = *(uint *)(loopIndex2 + 0x10);
              if ((((loopIndex != 0) &&
                   (((loopRemaining = IRInst__getOperandRecord(loopIndex,0), loopIndex2 = _UNK_001b2a7c,
                     *(char *)(loopRemaining + 0x12) == '\x01' || (*(int *)(loopIndex + 0xb4) == _UNK_001b2a7c)
                     ) && ((uVar3 >> 8 & 0xff) != 0)))) && ((loopIndex3 >> 8 & 0xff) == 3)) &&
                 (((uVar3 >> 0x18 != 0 && (loopIndex3 >> 0x18 == 0)) ||
                  (((uVar3 >> 0x10 & 0xff) != 0 && ((loopIndex3 >> 0x10 & 0xff) == 1)))))) {
                *(undefined1 *)(loopIndex + 0xe) = 1;
                *(int *)(loopIndex + 0xb4) = loopIndex2;
                *(undefined1 *)(loopIndex + 0x9e) = 0;
                loopIndex = DAT_001b2a64;
                if (iVar10 == 0) {
                  piVar2[0x27] = DAT_001b2a64;
                }
                else {
                  loopIndex2 = IRInst__getOperandRecord(piVar2,iVar10);
                  *(int *)(loopIndex2 + 0x10) = loopIndex;
                }
              }
            }
          }
          if (*(int *)(piVar2[0x22] + 8) == 0x8e) {
            piVar4 = (int *)piVar2[2];
          }
          else {
            (**(code **)(*this + 0x6c))(this,piVar2);
            piVar4 = (int *)piVar2[2];
          }
        }
        piVar2 = piVar4;
      }
      iVar14 = *(int *)(iVar14 + 8);
    } while (*(int *)(iVar14 + 8) != 0);
  }
  return;
}

/* R300SchedModel__vslot16 @ 0x18ad08 (1204 bytes) */
int R300SchedModel__vslot16(this, inst, param_3, param_4)
  int *this;
  int inst;
  int *param_3;
  undefined4 *param_4;
{
  int operandRecord2;
  int iVar1;
  int *a0;
  undefined4 operandRecord;
  undefined4 in_r7;
  undefined4 in_r8;
  code *pcVar3;
  int iVar4;
  
  iVar1 = *(int *)(*(int *)(inst + 0x88) + 8);
  if (iVar1 == 0x1c) {
    a0 = IRInst__create(0x13,this[2]);
    a0[0x25] = a0[0x53];
    a0[0x27] = 0x1010100;
    a0[0x26] = 0;
    *param_4 = 3;
    operandRecord = IRInst__getOperandRecord(inst,1);
    FUN_001062c0(a0,1,operandRecord,this[2]);
    operandRecord = IRInst__getOperandRecord(inst,2);
    FUN_001062c0(a0,2,operandRecord,this[2]);
    a0[3] = 0;
    *(undefined1 *)((int)a0 + 0xf) = 1;
    *param_3 = 2;
    do {
      operandRecord2 = IRInst__getOperandRecord(a0,1);
      *(undefined4 *)(operandRecord2 + 0x10) = 0x4040404;
      iVar4 = *param_3;
      pcVar3 = *(code **)(*a0 + 0x88);
      operandRecord2 = IRInst__getOperandRecord(inst,1);
      (*pcVar3)(a0,1,3,*(undefined1 *)(iVar4 + operandRecord2 + 0x10));
      operandRecord2 = IRInst__getOperandRecord(a0,2);
      *(undefined4 *)(operandRecord2 + 0x10) = 0x4040404;
      iVar4 = *param_3;
      pcVar3 = *(code **)(*a0 + 0x88);
      operandRecord2 = IRInst__getOperandRecord(inst,2);
      (*pcVar3)(a0,2,3,*(undefined1 *)(iVar4 + operandRecord2 + 0x10));
      iVar1 = (**(code **)(*this + 0xc))(this,a0);
      if (iVar1 != 0) {
        return a0;
      }
    } while (((*(uint *)(*(int *)(this[2] + 0x30c) + 8) & 0x400) != 0) &&
            (iVar1 = *param_3, *param_3 = iVar1 + -1, -1 < iVar1 + -1));
  }
  else {
    if (iVar1 != 0x1e) {
      if (iVar1 != 0x1d) {
        return (int *)0x0;
      }
      a0 = IRInst__create(0x1c,this[2]);
      a0[0x25] = a0[0x53];
      a0[0x27] = 0x10101;
      a0[0x26] = 0;
      *param_4 = 1;
      *param_3 = 3;
      operandRecord = IRInst__getOperandRecord(inst,1);
      FUN_001062c0(a0,1,operandRecord,this[2]);
      operandRecord = IRInst__getOperandRecord(inst,2);
      FUN_001062c0(a0,2,operandRecord,this[2]);
      (**(code **)(*a0 + 0x88))(a0,1,3,4);
      (**(code **)(*a0 + 0x88))(a0,2,3,4,in_r7,in_r8,*(code **)(*a0 + 0x88));
      a0[3] = 0;
      *(undefined1 *)(a0 + 3) = 1;
      iVar1 = (**(code **)(*this + 0xc))(this,a0);
      if (iVar1 != 0) {
        return a0;
      }
      iVar1 = *a0;
      goto LAB_0018b190;
    }
    a0 = IRInst__create(0x14,this[2]);
    a0[0x25] = a0[0x53];
    a0[0x27] = 0x1010100;
    a0[0x26] = 0;
    *param_4 = 3;
    operandRecord = IRInst__getOperandRecord(inst,1);
    FUN_001062c0(a0,1,operandRecord,this[2]);
    operandRecord = IRInst__getOperandRecord(inst,2);
    FUN_001062c0(a0,2,operandRecord,this[2]);
    operandRecord = IRInst__getOperandRecord(inst,3);
    FUN_001062c0(a0,3,operandRecord,this[2]);
    a0[3] = 0;
    *(undefined1 *)((int)a0 + 0xf) = 1;
    *param_3 = 1;
    do {
      operandRecord2 = IRInst__getOperandRecord(a0,1);
      *(undefined4 *)(operandRecord2 + 0x10) = 0x4040404;
      iVar4 = *param_3;
      pcVar3 = *(code **)(*a0 + 0x88);
      operandRecord2 = IRInst__getOperandRecord(inst,1);
      (*pcVar3)(a0,1,3,*(undefined1 *)(iVar4 + operandRecord2 + 0x10));
      operandRecord2 = IRInst__getOperandRecord(a0,2);
      *(undefined4 *)(operandRecord2 + 0x10) = 0x4040404;
      iVar4 = *param_3;
      pcVar3 = *(code **)(*a0 + 0x88);
      operandRecord2 = IRInst__getOperandRecord(inst,2);
      (*pcVar3)(a0,2,3,*(undefined1 *)(iVar4 + operandRecord2 + 0x10));
      operandRecord2 = IRInst__getOperandRecord(a0,3);
      *(undefined4 *)(operandRecord2 + 0x10) = 0x4040404;
      pcVar3 = *(code **)(*a0 + 0x88);
      operandRecord2 = IRInst__getOperandRecord(inst,3);
      (*pcVar3)(a0,3,3,*(undefined1 *)(operandRecord2 + 0x12));
      iVar1 = (**(code **)(*this + 0xc))(this,a0);
      if (iVar1 != 0) {
        return a0;
      }
      iVar1 = *param_3;
      *param_3 = iVar1 + -1;
    } while (-1 < iVar1 + -1);
  }
  iVar1 = *a0;
LAB_0018b190:
  (**(code **)(iVar1 + 4))(a0);
  return (int *)0x0;
}

/* FUN_0018b1bc @ 0x18b1bc (1176 bytes) */
int FUN_0018b1bc(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  int param_2;
  int param_3;
  int param_4;
  int param_5;
{
  bool bVar1;
  bool bVar2;
  undefined4 *loopIndex5;
  undefined1 *loopIndex6;
  uint loopIndex8;
  int *piVar6;
  int loopIndex3;
  uint uVar8;
  int *a0;
  undefined4 in_r8;
  int loopIndex4;
  int loopIndex;
  uint uVar11;
  uint uVar12;
  uint loopIndex7;
  int loopIndex2;
  uint *puVar15;
  
  bVar1 = param_3 <= param_4;
  if (bVar1) {
    loopIndex5 = (undefined4 *)(param_3 * 4 + param_2 + 0x48);
    loopIndex4 = param_3;
    do {
      loopIndex4 = loopIndex4 + 1;
      *loopIndex5 = 0;
      loopIndex5 = loopIndex5 + 1;
    } while (loopIndex4 <= param_4);
  }
  puVar15 = *(uint **)(param_2 + 0x40);
  loopIndex7 = 0;
  uVar11 = puVar15[1];
  loopIndex4 = param_5;
  if (0 < (int)uVar11) {
    while( true ) {
      if (loopIndex7 < *puVar15) {
        loopIndex8 = puVar15[1];
        if (loopIndex8 <= loopIndex7) {
          _memset(loopIndex8 * 4 + puVar15[2],0,(loopIndex7 - loopIndex8) * 4 + 4);
          puVar15[1] = loopIndex7 + 1;
        }
        piVar6 = (int *)(loopIndex7 * 4 + puVar15[2]);
      }
      else {
        piVar6 = (int *)Vector__elementRefGrow(puVar15,loopIndex7);
      }
      loopIndex7 = loopIndex7 + 1;
      loopIndex2 = *piVar6;
      if (*(int *)(loopIndex2 + 8) == 0) {
        if (bVar1) {
          loopIndex6 = (undefined1 *)(param_3 + loopIndex2 + 0x18);
          loopIndex = param_3;
          do {
            loopIndex = loopIndex + 1;
            *loopIndex6 = 0;
            loopIndex6 = loopIndex6 + 1;
          } while (loopIndex <= param_4);
        }
        *(undefined1 *)(param_5 + loopIndex2 + 0x18) = 1;
        loopIndex = param_5 * 4 + param_2;
        *(int *)(loopIndex + 0x48) = *(int *)(loopIndex + 0x48) + 1;
        loopIndex = *(int *)(loopIndex2 + 4);
        piVar6 = *(int **)(loopIndex + 0x38);
        if ((piVar6[5] & 0x200U) != 0) {
          IRInst__getOperandSource(piVar6,piVar6[0x21]);
        }
        (**(code **)(*piVar6 + 0x28))(piVar6);
        loopIndex3 = (**(code **)(*piVar6 + 0x5c))(piVar6);
        if (loopIndex3 == 0) {
          a0 = (int *)IRInst__getOperandSource(piVar6,*(undefined4 *)(loopIndex2 + 0x10));
          loopIndex = (**(code **)(*a0 + 0x60))(a0);
          if (loopIndex == 0) {
            loopIndex = 0;
            do {
              loopIndex3 = IRInst__getOperandRecord(piVar6,*(undefined4 *)(loopIndex2 + 0x10));
              loopIndex8 = (uint)*(byte *)(loopIndex + loopIndex3 + 0x10);
              if ((param_3 <= (int)loopIndex8) && ((int)loopIndex8 <= param_4)) {
                (**(code **)(*piVar6 + 0x88))(piVar6,*(undefined4 *)(loopIndex2 + 0x10),loopIndex,param_5);
              }
              bVar2 = loopIndex != 3;
              loopIndex = loopIndex + 1;
            } while (bVar2);
          }
        }
        else {
          loopIndex2 = (**(code **)(*piVar6 + 0x14))(piVar6);
          if (1 < loopIndex2) {
            IRInst__getOperandSource(piVar6,1);
            IRInst__getOperandSource(piVar6,2);
          }
          if (bVar1) {
            loopIndex6 = (undefined1 *)((int)piVar6 + param_3 + 0xc);
            loopIndex2 = param_3;
            do {
              loopIndex6[0x90] = 1;
              loopIndex3 = *piVar6;
              *loopIndex6 = 0;
              (**(code **)(loopIndex3 + 0x88))(piVar6,1,loopIndex2,4);
              loopIndex3 = (**(code **)(*piVar6 + 0x14))(piVar6);
              if (loopIndex3 == 2) {
                (**(code **)(*piVar6 + 0x88))(piVar6,2,loopIndex2,4);
              }
              loopIndex2 = loopIndex2 + 1;
              loopIndex6 = loopIndex6 + 1;
            } while (loopIndex2 <= param_4);
          }
          loopIndex3 = param_5 + (int)piVar6;
          *(undefined1 *)(loopIndex3 + 0x9c) = 0;
          loopIndex2 = *piVar6;
          *(undefined1 *)(loopIndex3 + 0xc) = 1;
          (**(code **)(loopIndex2 + 0x88))(piVar6,1,param_5,param_5,loopIndex4,in_r8,loopIndex3);
          loopIndex2 = (**(code **)(*piVar6 + 0x14))(piVar6);
          if (loopIndex2 == 2) {
            (**(code **)(*piVar6 + 0x88))(piVar6,2,param_5,param_5);
          }
          if (bVar1) {
            loopIndex5 = (undefined4 *)(param_3 * 4 + loopIndex + 0x48);
            loopIndex2 = param_3;
            do {
              loopIndex2 = loopIndex2 + 1;
              *loopIndex5 = 0;
              loopIndex5 = loopIndex5 + 1;
            } while (loopIndex2 <= param_4);
          }
          puVar15 = *(uint **)(loopIndex + 0x40);
          loopIndex8 = 0;
          uVar12 = puVar15[1];
          if (0 < (int)uVar12) {
            while( true ) {
              if (loopIndex8 < *puVar15) {
                uVar8 = puVar15[1];
                if (uVar8 <= loopIndex8) {
                  _memset(uVar8 * 4 + puVar15[2],0,(loopIndex8 - uVar8) * 4 + 4);
                  puVar15[1] = loopIndex8 + 1;
                }
                piVar6 = (int *)(loopIndex8 * 4 + puVar15[2]);
              }
              else {
                piVar6 = (int *)Vector__elementRefGrow(puVar15,loopIndex8);
              }
              loopIndex8 = loopIndex8 + 1;
              loopIndex2 = *piVar6;
              if (*(int *)(loopIndex2 + 8) == 0) {
                if (bVar1) {
                  loopIndex6 = (undefined1 *)(param_3 + loopIndex2 + 0x18);
                  loopIndex3 = param_3;
                  do {
                    loopIndex3 = loopIndex3 + 1;
                    *loopIndex6 = 0;
                    loopIndex6 = loopIndex6 + 1;
                  } while (loopIndex3 <= param_4);
                }
                *(undefined1 *)(param_5 + loopIndex2 + 0x18) = 1;
                loopIndex2 = param_5 * 4 + loopIndex;
                *(int *)(loopIndex2 + 0x48) = *(int *)(loopIndex2 + 0x48) + 1;
              }
              if (uVar12 == loopIndex8) break;
              puVar15 = *(uint **)(loopIndex + 0x40);
            }
          }
        }
      }
      if (uVar11 == loopIndex7) break;
      puVar15 = *(uint **)(param_2 + 0x40);
    }
  }
  return;
}

/* R300SchedModel__vslot11 @ 0x18b654 (888 bytes) */
int R300SchedModel__vslot11(this, param_2, param_3)
  int *this;
  int param_2;
  int param_3;
{
  int operandRecord;
  bool bVar1;
  undefined1 uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined4 in_r7;
  undefined4 in_r8;
  byte *pbVar6;
  int loopIndex;
  int *a0;
  int loopRemaining;
  undefined4 local_48;
  
  pbVar6 = *(byte **)(param_2 + 0x60);
  local_48 = 0x1010101;
  if (pbVar6 != (byte *)0x0) {
    uVar3 = 0x1010101 -
            ((uint)pbVar6[3] << 0x18 | (uint)pbVar6[2] << 0x10 | (uint)pbVar6[1] << 8 |
            (uint)*pbVar6);
    local_48 = uVar3 * 0x1000000 | (uVar3 & 0xff00) << 8 | uVar3 >> 8 & 0xff00 | uVar3 >> 0x18;
    iVar4 = *(int *)(*(int *)(param_2 + 0x60) + 4);
    if (-1 < iVar4) {
      loopRemaining = 4;
      loopIndex = 0;
      in_r8 = 0;
      do {
        iVar5 = *(int *)(iVar4 * 4 + *(int *)(param_3 + loopIndex * 4));
        if ((iVar5 != 0) && (*(int *)(loopIndex * 4 + iVar5 + 0x48) != 0)) {
          *(undefined1 *)((int)&local_48 + loopIndex) = 0;
        }
        loopIndex = loopIndex + 1;
        loopRemaining = loopRemaining + -1;
      } while (loopRemaining != 0);
    }
  }
  if (local_48 == 0) {
    return 0;
  }
  a0 = *(int **)(param_2 + 0x38);
  FUN_000f3a30(a0);
  operandRecord = IRInst__getOperandRecord(a0,0);
  if (*(char *)(operandRecord + 0x13) == '\0') {
    if (local_48 == 0x1010101) {
      loopIndex = this[0x1a];
      this[0x1a] = loopIndex + 1;
      if (2 < loopIndex + 1) {
        this[0x1a] = 0;
      }
    }
    else {
      loopIndex = 0;
      while (*(char *)((int)&local_48 + loopIndex) == '\0') {
        bVar1 = loopIndex == 2;
        loopIndex = loopIndex + 1;
        if (bVar1) {
          return 0;
        }
      }
    }
    if (loopIndex == -1) {
      return 0;
    }
    iVar4 = 3;
  }
  else {
    if ((char)local_48 == '\0') {
      return 0;
    }
    operandRecord = IRInst__getOperandRecord(a0,0);
    loopIndex = 3;
    iVar4 = FUN_000f30d4(*(undefined4 *)(operandRecord + 0x10));
  }
  *(undefined1 *)((int)a0 + iVar4 + 0x9c) = 1;
  *(undefined1 *)((int)a0 + iVar4 + 0xc) = 0;
  iVar5 = 1;
  *(undefined1 *)((int)a0 + loopIndex + 0x9c) = 0;
  loopRemaining = a0[0x22];
  *(undefined1 *)((int)a0 + loopIndex + 0xc) = 1;
  if (*(int *)(PTR_DAT_001e913c + *(int *)(loopRemaining + 8) * 0x38 + 0x34) == 0) {
    for (; loopRemaining = (**(code **)(*a0 + 0x14))(a0), iVar5 <= loopRemaining; iVar5 = iVar5 + 1) {
      loopRemaining = IRInst__getOperandRecord(a0,iVar5);
      uVar2 = *(undefined1 *)(iVar4 + loopRemaining + 0x10);
      (**(code **)(*a0 + 0x88))(a0,iVar5,iVar4,4,in_r7,in_r8,iVar4 + loopRemaining);
      (**(code **)(*a0 + 0x88))(a0,iVar5,loopIndex,uVar2);
    }
  }
  loopRemaining = (**(code **)(*this + 0xc))(this,*(undefined4 *)(param_2 + 0x38));
  if (loopRemaining == 0) {
    *(undefined1 *)((int)a0 + iVar4 + 0x9c) = 0;
    *(undefined1 *)((int)a0 + iVar4 + 0xc) = 1;
    iVar5 = 1;
    *(undefined1 *)((int)a0 + loopIndex + 0x9c) = 1;
    loopRemaining = a0[0x22];
    *(undefined1 *)((int)a0 + loopIndex + 0xc) = 0;
    if (*(int *)(PTR_DAT_001e913c + *(int *)(loopRemaining + 8) * 0x38 + 0x34) == 0) {
      for (; loopRemaining = (**(code **)(*a0 + 0x14))(a0), iVar5 <= loopRemaining; iVar5 = iVar5 + 1) {
        loopRemaining = IRInst__getOperandRecord(a0,iVar5);
        uVar2 = *(undefined1 *)(loopIndex + loopRemaining + 0x10);
        (**(code **)(*a0 + 0x88))(a0,iVar5,loopIndex,4,in_r7,in_r8,loopIndex + loopRemaining);
        (**(code **)(*a0 + 0x88))(a0,iVar5,iVar4,uVar2);
      }
    }
    return 0;
  }
  *(uint *)(param_2 + 0x58) = (loopIndex == 3) + 1;
  if (*(int *)(param_2 + 0x60) != 0) {
    *(undefined1 *)(*(int *)(param_2 + 0x60) + loopIndex) = 1;
  }
  ((int (*)())FUN_0018b1bc)(this,param_2,iVar4,iVar4,loopIndex);
  return 1;
}

/* R300SchedModel__vslot14 @ 0x18b9cc (712 bytes) */
int R300SchedModel__vslot14(this, param_2)
  int this;
  int param_2;
{
  int operandRecord2;
  undefined1 uVar1;
  uint uVar2;
  undefined1 *loopIndex2;
  int iVar4;
  int operandRecord;
  undefined4 in_r7;
  undefined4 in_r8;
  int loopIndex;
  int a2;
  int iVar7;
  int iVar8;
  int *a0;
  
  a0 = *(int **)(param_2 + 0x38);
  if ((a0[0x20] == 0) || (iVar4 = RegKind__flagBit0(a0[0x26]), iVar4 == 0)) {
    uVar2 = a0[5];
  }
  else {
    uVar2 = a0[5];
    if ((uVar2 & 2) == 0) {
      (**(code **)(*a0 + 0x50))(a0);
      uVar2 = a0[5];
    }
  }
  if (((uVar2 & 2) == 0) && (iVar4 = (**(code **)(*a0 + 0x5c))(a0), iVar4 == 0)) {
    (**(code **)(*a0 + 0x28))(a0);
  }
  iVar7 = *(int *)(PTR_DAT_001e913c + *(int *)(a0[0x22] + 8) * 0x38 + 0x34);
  iVar4 = IRInst__getOperandRecord(a0,0);
  if (*(char *)(iVar4 + 0x13) == '\0') {
    if ((iVar7 == 0) && (iVar4 = FUN_000f3a30(a0), 1 < iVar4)) {
      operandRecord2 = IRInst__getOperandRecord(a0,0);
      a2 = 3;
      iVar8 = FUN_000f3108(*(undefined4 *)(operandRecord2 + 0x10));
      iVar4 = 3;
    }
    else {
      iVar8 = *(int *)(this + 0x68);
      *(int *)(this + 0x68) = iVar8 + 1;
      if (iVar8 + 1 < 3) {
        a2 = 3;
        iVar4 = 3;
      }
      else {
        a2 = 3;
        *(undefined4 *)(this + 0x68) = 0;
        iVar4 = 3;
      }
    }
  }
  else if (iVar7 == 5) {
    a2 = 0;
    iVar8 = 3;
    iVar4 = 2;
  }
  else {
    operandRecord2 = IRInst__getOperandRecord(a0,0);
    iVar8 = 3;
    a2 = FUN_000f30d4(*(undefined4 *)(operandRecord2 + 0x10));
    iVar4 = a2;
  }
  loopIndex2 = (undefined1 *)((int)a0 + a2 + 0xc);
  loopIndex = a2;
  do {
    loopIndex = loopIndex + 1;
    loopIndex2[0x90] = 1;
    *loopIndex2 = 0;
    loopIndex2 = loopIndex2 + 1;
  } while (loopIndex <= iVar4);
  *(undefined1 *)((int)a0 + iVar8 + 0xc) = 1;
  *(undefined1 *)((int)a0 + iVar8 + 0x9c) = 0;
  *(uint *)(param_2 + 0x58) = (iVar8 == 3) + 1;
  if (((iVar7 - 1U < 2) || (iVar7 == 5)) || (loopIndex = 1, a2 != iVar4)) {
    *(undefined4 *)(param_2 + 0x5c) = 0;
  }
  else {
    for (; operandRecord = (**(code **)(*a0 + 0x14))(a0), loopIndex <= operandRecord; loopIndex = loopIndex + 1) {
      operandRecord = IRInst__getOperandRecord(a0,loopIndex);
      uVar1 = *(undefined1 *)(a2 + operandRecord + 0x10);
      (**(code **)(*a0 + 0x88))(a0,loopIndex,a2,4,in_r7,in_r8,a2 + operandRecord);
      (**(code **)(*a0 + 0x88))(a0,loopIndex,iVar8,uVar1);
    }
    if ((iVar7 == 0) && (iVar7 = FUN_000f3a30(a0), 1 < iVar7)) {
      *(undefined4 *)(param_2 + 0x5c) = 0;
    }
  }
  return ((int (*)())FUN_0018b1bc)(this,param_2,a2,iVar4,iVar8);
}

/* FUN_0018bc94 @ 0x18bc94 (1332 bytes) */
int FUN_0018bc94(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int *param_3;
  int *param_4;
{
  bool bVar1;
  int *loopIndex5;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int *loopIndex6;
  int loopIndex2;
  int *loopIndex7;
  int *loopIndex8;
  int iVar10;
  int *loopIndex3;
  int loopIndex;
  int *piVar13;
  int *loopIndex4;
  int *piVar15;
  int local_68 [10];
  
  if (param_2 < 3) {
    loopIndex2 = param_2 * 4 + param_1;
    if (*(int *)(loopIndex2 + 0x30) == 0) {
      loopIndex2 = ((int (*)())FUN_0018bc94)(param_1,param_2 + 1,param_3,param_4);
      if (loopIndex2 != 0) goto LAB_0018c1b0;
    }
    else {
      loopIndex3 = param_3 + 3;
      loopIndex7 = param_4 + 3;
      loopIndex6 = param_4;
      loopIndex8 = param_3;
      do {
        loopIndex4 = (int *)*loopIndex8;
        if ((((loopIndex4 == (int *)0x0) || (loopIndex4 == *(int **)(loopIndex2 + 0x18))) ||
            ((((*(int **)(loopIndex2 + 0x18) != (int *)0x0 &&
               ((loopIndex4[0x20] != 0 && (iVar3 = RegKind__flagBit0(loopIndex4[0x26]), iVar3 != 0)))) &&
              ((loopIndex4[5] & 2U) == 0)) &&
             ((((((iVar3 = (**(code **)(*loopIndex4 + 0x50))(loopIndex4), iVar3 == 0 &&
                  (loopIndex4 = *(int **)(loopIndex2 + 0x18), loopIndex4[0x20] != 0)) &&
                 (iVar3 = RegKind__flagBit0(loopIndex4[0x26]), iVar3 != 0)) &&
                (((loopIndex4[5] & 2U) == 0 &&
                 (iVar3 = (**(code **)(*loopIndex4 + 0x50))(loopIndex4), iVar3 == 0)))) &&
               ((*(uint *)(*loopIndex8 + 0x14) & 0x40) != 0)) &&
              (((*(uint *)(*(int *)(loopIndex2 + 0x18) + 0x14) & 0x40) != 0 &&
               (*(int *)(*loopIndex8 + 0x94) == *(int *)(*(int *)(loopIndex2 + 0x18) + 0x94))))))))) &&
           (((loopIndex4 = (int *)*loopIndex3, loopIndex4 == (int *)0x0 ||
             (loopIndex4 == *(int **)(loopIndex2 + 0x24))) ||
            (((((*(int **)(loopIndex2 + 0x24) != (int *)0x0 && (loopIndex4[0x20] != 0)) &&
               (iVar3 = RegKind__flagBit0(loopIndex4[0x26]), iVar3 != 0)) &&
              ((((loopIndex4[5] & 2U) == 0 &&
                (iVar3 = (**(code **)(*loopIndex4 + 0x50))(loopIndex4), iVar3 == 0)) &&
               (loopIndex4 = *(int **)(loopIndex2 + 0x24), loopIndex4[0x20] != 0)))) &&
             (((iVar3 = RegKind__flagBit0(loopIndex4[0x26]), iVar3 != 0 && ((loopIndex4[5] & 2U) == 0)) &&
              ((iVar3 = (**(code **)(*loopIndex4 + 0x50))(loopIndex4), iVar3 == 0 &&
               ((((*(uint *)(*loopIndex3 + 0x14) & 0x40) != 0 &&
                 ((*(uint *)(*(int *)(loopIndex2 + 0x24) + 0x14) & 0x40) != 0)) &&
                (*(int *)(*loopIndex3 + 0x94) == *(int *)(*(int *)(loopIndex2 + 0x24) + 0x94))))))))))))) {
          *loopIndex8 = *(int *)(loopIndex2 + 0x18);
          *loopIndex3 = *(int *)(loopIndex2 + 0x24);
          *loopIndex6 = *loopIndex6 + 1;
          *loopIndex7 = *loopIndex7 + 1;
          iVar3 = ((int (*)())FUN_0018bc94)(param_1,param_2 + 1,param_3,param_4);
          if (iVar3 != 0) goto LAB_0018c1b0;
          *loopIndex6 = *loopIndex6 + -1;
          iVar3 = *loopIndex7 + -1;
          *loopIndex7 = iVar3;
          if (*loopIndex6 == 0) {
            *loopIndex8 = 0;
            iVar3 = *loopIndex7;
          }
          if (iVar3 == 0) {
            *loopIndex3 = 0;
          }
        }
        loopIndex8 = loopIndex8 + 1;
        loopIndex3 = loopIndex3 + 1;
        loopIndex7 = loopIndex7 + 1;
        loopIndex6 = loopIndex6 + 1;
      } while (param_3 + 3 != loopIndex8);
    }
LAB_0018bf4c:
    uVar4 = 0;
  }
  else {
    loopIndex7 = param_4 + 3;
    loopIndex4 = local_68;
    loopIndex6 = loopIndex7;
    loopIndex8 = param_4;
    loopIndex3 = loopIndex4;
    do {
      loopIndex2 = *loopIndex8;
      loopIndex8 = loopIndex8 + 1;
      *loopIndex3 = loopIndex2;
      loopIndex2 = *loopIndex6;
      loopIndex6 = loopIndex6 + 1;
      loopIndex3[3] = loopIndex2;
      loopIndex3 = loopIndex3 + 1;
    } while (loopIndex3 != local_68 + 3);
    loopIndex2 = 0;
    iVar3 = param_1 + 0x10;
    do {
      piVar13 = (int *)(iVar3 + 8);
      iVar10 = 0;
      loopIndex6 = param_4;
      loopIndex8 = param_3;
      do {
        if ((*(int *)(param_1 + 0x30) == 0) && (*piVar13 != 0)) {
          loopIndex = 0;
          loopIndex5 = loopIndex8;
          do {
            if (((int *)*loopIndex5 != (int *)0x0) &&
               ((piVar15 = (int *)*piVar13, (int *)*loopIndex5 == piVar15 ||
                ((((piVar15 != (int *)0x0 && (piVar15[0x20] != 0)) &&
                  (iVar5 = RegKind__flagBit0(piVar15[0x26]), iVar5 != 0)) &&
                 ((((((piVar15[5] & 2U) == 0 &&
                     (iVar5 = (**(code **)(*piVar15 + 0x50))(piVar15), iVar5 == 0)) &&
                    ((piVar15 = (int *)*loopIndex5, piVar15[0x20] != 0 &&
                     ((iVar5 = RegKind__flagBit0(piVar15[0x26]), iVar5 != 0 && ((piVar15[5] & 2U) == 0)))
                     ))) && (iVar5 = (**(code **)(*piVar15 + 0x50))(piVar15), iVar5 == 0)) &&
                  ((((*(uint *)(*piVar13 + 0x14) & 0x40) != 0 &&
                    ((*(uint *)(*loopIndex5 + 0x14) & 0x40) != 0)) &&
                   (*(int *)(*piVar13 + 0x94) == *(int *)(*loopIndex5 + 0x94))))))))))) {
              loopIndex6[loopIndex] = loopIndex6[loopIndex] + 1;
              goto LAB_0018c0d4;
            }
            bVar1 = loopIndex != 2;
            loopIndex5 = loopIndex5 + 1;
            loopIndex = loopIndex + 1;
          } while (bVar1);
          loopIndex = 0;
          loopIndex5 = loopIndex8;
          while (*loopIndex5 != 0) {
            bVar1 = loopIndex == 2;
            loopIndex5 = loopIndex5 + 1;
            loopIndex = loopIndex + 1;
            if (bVar1) {
              loopIndex6 = param_3 + 3;
              do {
                iVar3 = *loopIndex4;
                *param_4 = iVar3;
                loopIndex2 = loopIndex4[3];
                *loopIndex7 = loopIndex2;
                if (iVar3 == 0) {
                  *param_3 = 0;
                }
                if (loopIndex2 == 0) {
                  *loopIndex6 = 0;
                }
                loopIndex4 = loopIndex4 + 1;
                param_4 = param_4 + 1;
                loopIndex7 = loopIndex7 + 1;
                loopIndex6 = loopIndex6 + 1;
                param_3 = param_3 + 1;
              } while (loopIndex3 != loopIndex4);
              goto LAB_0018bf4c;
            }
          }
          loopIndex8[loopIndex] = *piVar13;
          loopIndex6[loopIndex] = loopIndex6[loopIndex] + 1;
        }
LAB_0018c0d4:
        bVar1 = iVar10 != 0xc;
        piVar13 = piVar13 + 3;
        loopIndex6 = loopIndex6 + 3;
        loopIndex8 = loopIndex8 + 3;
        iVar10 = iVar10 + 0xc;
      } while (bVar1);
      bVar1 = loopIndex2 != 2;
      iVar3 = iVar3 + 4;
      param_1 = param_1 + 4;
      loopIndex2 = loopIndex2 + 1;
    } while (bVar1);
LAB_0018c1b0:
    uVar4 = 1;
  }
  return uVar4;
}

/* FUN_0018c1c8 @ 0x18c1c8 (1440 bytes) */
int FUN_0018c1c8(param_1, param_2)
  int *param_1;
  int *param_2;
{
  int *loopIndex;
  int callResult;
  int *loopIndex2;
  int *loopIndex3;
  int *piVar5;
  int *loopRemaining;
  int *piVar7;
  int local_58 [3];
  int local_4c [9];
  
  piVar5 = param_2 + 3;
  loopIndex3 = local_58;
  loopIndex = piVar5;
  loopIndex2 = param_2;
  do {
    *loopIndex3 = 0;
    loopIndex3[3] = 0;
    loopIndex3 = loopIndex3 + 1;
    *loopIndex2 = 0;
    *loopIndex = 0;
    loopIndex2 = loopIndex2 + 1;
    loopIndex = loopIndex + 1;
  } while (loopIndex3 != local_4c);
  if (*param_1 != 0) {
    *param_2 = *param_1;
    local_58[0] = local_58[0] + 1;
  }
  if (param_1[1] != 0) {
    *piVar5 = param_1[1];
    local_4c[0] = local_4c[0] + 1;
  }
  loopIndex = param_1;
  loopIndex2 = param_1;
  do {
    loopIndex3 = param_1;
    loopRemaining = param_1;
    if ((param_1[2] == 0) || (param_1[3] == 0)) {
LAB_0018c498:
      do {
        if ((param_1[4] == 0) || (param_1[5] == 0)) {
LAB_0018c6a0:
          callResult = ((int (*)())FUN_0018bc94)(param_1,0,param_2,local_58);
          if (callResult != 0) {
            return 1;
          }
          local_4c[0] = local_4c[0] + -1;
          if (local_4c[0] == 0) {
            *piVar5 = 0;
          }
          local_4c[1] = local_4c[1] + -1;
          if (local_4c[1] == 0) {
            param_2[4] = 0;
          }
        }
        else {
          piVar7 = (int *)*piVar5;
          if ((((piVar7 == (int *)0x0) || (piVar7 == (int *)loopRemaining[5])) ||
              ((((((int *)loopRemaining[5] != (int *)0x0 && (piVar7[0x20] != 0)) &&
                 (callResult = RegKind__flagBit0(piVar7[0x26]), callResult != 0)) &&
                (((piVar7[5] & 2U) == 0 &&
                 (callResult = (**(code **)(*piVar7 + 0x50))(piVar7), callResult == 0)))) &&
               ((piVar7 = (int *)loopRemaining[5], piVar7[0x20] != 0 &&
                (((callResult = RegKind__flagBit0(piVar7[0x26]), callResult != 0 && ((piVar7[5] & 2U) == 0)) &&
                 ((callResult = (**(code **)(*piVar7 + 0x50))(piVar7), callResult == 0 &&
                  ((((*(uint *)(*piVar5 + 0x14) & 0x40) != 0 &&
                    ((*(uint *)(loopRemaining[5] + 0x14) & 0x40) != 0)) &&
                   (*(int *)(*piVar5 + 0x94) == *(int *)(loopRemaining[5] + 0x94))))))))))))) &&
             (((piVar7 = (int *)param_2[4], piVar7 == (int *)0x0 || (piVar7 == (int *)loopIndex3[4])) ||
              (((int *)loopIndex3[4] != (int *)0x0 &&
               ((((piVar7[0x20] != 0 && (callResult = RegKind__flagBit0(piVar7[0x26]), callResult != 0)) &&
                 (((piVar7[5] & 2U) == 0 &&
                  (((callResult = (**(code **)(*piVar7 + 0x50))(piVar7), callResult == 0 &&
                    (piVar7 = (int *)loopIndex3[4], piVar7[0x20] != 0)) &&
                   (callResult = RegKind__flagBit0(piVar7[0x26]), callResult != 0)))))) &&
                ((((piVar7[5] & 2U) == 0 &&
                  (callResult = (**(code **)(*piVar7 + 0x50))(piVar7), callResult == 0)) &&
                 (((*(uint *)(param_2[4] + 0x14) & 0x40) != 0 &&
                  (((*(uint *)(loopIndex3[4] + 0x14) & 0x40) != 0 &&
                   (*(int *)(param_2[4] + 0x94) == *(int *)(loopIndex3[4] + 0x94))))))))))))))) {
            *piVar5 = loopRemaining[5];
            local_4c[1] = local_4c[1] + 1;
            local_4c[0] = local_4c[0] + 1;
            param_2[4] = loopIndex3[4];
            goto LAB_0018c6a0;
          }
        }
        loopRemaining = loopRemaining + -1;
        loopIndex3 = loopIndex3 + 1;
      } while (param_1 + -2 != loopRemaining);
      local_58[0] = local_58[0] + -1;
      if (local_58[0] == 0) {
        *param_2 = 0;
      }
      local_58[1] = local_58[1] + -1;
      if (local_58[1] == 0) {
        param_2[1] = 0;
      }
    }
    else {
      piVar7 = (int *)*param_2;
      if ((((piVar7 == (int *)0x0) || (piVar7 == (int *)loopIndex2[3])) ||
          (((((((int *)loopIndex2[3] != (int *)0x0 && (piVar7[0x20] != 0)) &&
              (callResult = RegKind__flagBit0(piVar7[0x26]), callResult != 0)) &&
             (((piVar7[5] & 2U) == 0 && (callResult = (**(code **)(*piVar7 + 0x50))(piVar7), callResult == 0))
             )) && (piVar7 = (int *)loopIndex2[3], piVar7[0x20] != 0)) &&
           ((((callResult = RegKind__flagBit0(piVar7[0x26]), callResult != 0 && ((piVar7[5] & 2U) == 0)) &&
             (callResult = (**(code **)(*piVar7 + 0x50))(piVar7), callResult == 0)) &&
            ((((*(uint *)(*param_2 + 0x14) & 0x40) != 0 &&
              ((*(uint *)(loopIndex2[3] + 0x14) & 0x40) != 0)) &&
             (*(int *)(*param_2 + 0x94) == *(int *)(loopIndex2[3] + 0x94))))))))) &&
         (((piVar7 = (int *)param_2[1], piVar7 == (int *)0x0 || (piVar7 == (int *)loopIndex[2])) ||
          (((((int *)loopIndex[2] != (int *)0x0 &&
             ((piVar7[0x20] != 0 && (callResult = RegKind__flagBit0(piVar7[0x26]), callResult != 0)))) &&
            ((piVar7[5] & 2U) == 0)) &&
           (((((callResult = (**(code **)(*piVar7 + 0x50))(piVar7), callResult == 0 &&
               (piVar7 = (int *)loopIndex[2], piVar7[0x20] != 0)) &&
              (callResult = RegKind__flagBit0(piVar7[0x26]), callResult != 0)) &&
             (((piVar7[5] & 2U) == 0 && (callResult = (**(code **)(*piVar7 + 0x50))(piVar7), callResult == 0))
             )) && (((*(uint *)(param_2[1] + 0x14) & 0x40) != 0 &&
                    (((*(uint *)(loopIndex[2] + 0x14) & 0x40) != 0 &&
                     (*(int *)(param_2[1] + 0x94) == *(int *)(loopIndex[2] + 0x94))))))))))))) {
        *param_2 = loopIndex2[3];
        local_58[0] = local_58[0] + 1;
        local_58[1] = local_58[1] + 1;
        param_2[1] = loopIndex[2];
        goto LAB_0018c498;
      }
    }
    loopIndex2 = loopIndex2 + -1;
    loopIndex = loopIndex + 1;
    if (param_1 + -2 == loopIndex2) {
      return 0;
    }
  } while( true );
}

/* PackState__countFreeSlots @ 0x18c768 (140 bytes) */
int PackState__countFreeSlots(state, freeCounts)
  undefined4 state;
  int *freeCounts;
{
  int callResult;
  int *loopIndex;
  int local_38 [3];
  int local_2c [9];
  
  callResult = ((int (*)())FUN_0018c1c8)(state,local_38);
  freeCounts[1] = 0;
  *freeCounts = 0;
  if (callResult != 0) {
    loopIndex = local_38;
    do {
      if (*loopIndex == 0) {
        *freeCounts = *freeCounts + 1;
      }
      if (loopIndex[3] == 0) {
        freeCounts[1] = freeCounts[1] + 1;
      }
      loopIndex = loopIndex + 1;
    } while (loopIndex != local_2c);
  }
  return callResult;
}

/* FUN_0018c7f4 @ 0x18c7f4 (396 bytes) */
int FUN_0018c7f4(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  int param_3;
{
  bool bVar1;
  int iVar2;
  int *piVar3;
  int loopIndex;
  int *loopIndex2;
  
  loopIndex2 = (int *)(param_3 * 0xc + param_1 + 0x18);
  loopIndex = 0;
  while (((int *)*loopIndex2 == (int *)0x0 ||
         ((param_2 != (int *)*loopIndex2 &&
          (((((param_2 == (int *)0x0 || (param_2[0x20] == 0)) ||
             (iVar2 = RegKind__flagBit0(param_2[0x26]), iVar2 == 0)) ||
            (((((param_2[5] & 2U) != 0 ||
               (iVar2 = (**(code **)(*param_2 + 0x50))(param_2), iVar2 != 0)) ||
              ((piVar3 = (int *)*loopIndex2, piVar3[0x20] == 0 ||
               ((iVar2 = RegKind__flagBit0(piVar3[0x26]), iVar2 == 0 || ((piVar3[5] & 2U) != 0)))))) ||
             (iVar2 = (**(code **)(*piVar3 + 0x50))(piVar3), iVar2 != 0)))) ||
           ((((param_2[5] & 0x40U) == 0 || ((*(uint *)(*loopIndex2 + 0x14) & 0x40) == 0)) ||
            (param_2[0x25] != *(int *)(*loopIndex2 + 0x94)))))))))) {
    bVar1 = loopIndex == 2;
    loopIndex2 = loopIndex2 + 1;
    loopIndex = loopIndex + 1;
    if (bVar1) {
      loopIndex = 0;
      loopIndex2 = (int *)(param_3 * 0xc + param_1 + 0x18);
      do {
        if (*loopIndex2 == 0) {
          *(int **)((param_3 * 3 + loopIndex) * 4 + param_1 + 0x18) = param_2;
          return 1;
        }
        bVar1 = loopIndex != 2;
        loopIndex2 = loopIndex2 + 1;
        loopIndex = loopIndex + 1;
      } while (bVar1);
      return 0;
    }
  }
  return 1;
}

/* FUN_0018c980 @ 0x18c980 (1112 bytes) */
int FUN_0018c980(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  int *param_3;
{
  bool bVar1;
  int loopIndex;
  undefined4 uVar3;
  int loopIndex2;
  int iVar5;
  int iVar6;
  int *loopIndex3;
  int *piVar8;
  
  loopIndex2 = 0;
  iVar6 = param_1;
  while (*(int *)(iVar6 + 0x30) != 0) {
    loopIndex3 = *(int **)(iVar6 + 0x18);
    if (((param_2 == loopIndex3) ||
        ((((((loopIndex3 != (int *)0x0 && (param_2 != (int *)0x0)) && (loopIndex3[0x20] != 0)) &&
           ((loopIndex = RegKind__flagBit0(loopIndex3[0x26]), loopIndex != 0 && ((loopIndex3[5] & 2U) == 0)))) &&
          ((((loopIndex = (**(code **)(*loopIndex3 + 0x50))(loopIndex3), loopIndex == 0 &&
             ((param_2[0x20] != 0 && (loopIndex = RegKind__flagBit0(param_2[0x26]), loopIndex != 0)))) &&
            ((param_2[5] & 2U) == 0)) &&
           (((loopIndex = (**(code **)(*param_2 + 0x50))(param_2), loopIndex == 0 &&
             ((*(uint *)(*(int *)(iVar6 + 0x18) + 0x14) & 0x40) != 0)) &&
            ((param_2[5] & 0x40U) != 0)))))) &&
         (*(int *)(*(int *)(iVar6 + 0x18) + 0x94) == param_2[0x25])))) &&
       ((loopIndex3 = *(int **)(iVar6 + 0x24), param_3 == loopIndex3 ||
        (((((loopIndex3 != (int *)0x0 && (param_3 != (int *)0x0)) &&
           ((loopIndex3[0x20] != 0 &&
            ((loopIndex = RegKind__flagBit0(loopIndex3[0x26]), loopIndex != 0 && ((loopIndex3[5] & 2U) == 0)))))) &&
          (loopIndex = (**(code **)(*loopIndex3 + 0x50))(loopIndex3), loopIndex == 0)) &&
         (((((param_3[0x20] != 0 && (loopIndex = RegKind__flagBit0(param_3[0x26]), loopIndex != 0)) &&
            ((param_3[5] & 2U) == 0)) &&
           ((loopIndex = (**(code **)(*param_3 + 0x50))(param_3), loopIndex == 0 &&
            ((*(uint *)(*(int *)(iVar6 + 0x24) + 0x14) & 0x40) != 0)))) &&
          (((param_3[5] & 0x40U) != 0 && (*(int *)(*(int *)(iVar6 + 0x24) + 0x94) == param_3[0x25]))
          )))))))) goto LAB_0018cdb8;
    bVar1 = loopIndex2 == 2;
    iVar6 = iVar6 + 4;
    loopIndex2 = loopIndex2 + 1;
    if (bVar1) goto LAB_0018cdb8;
  }
  loopIndex = loopIndex2 + 1;
  iVar6 = loopIndex2 * 4 + param_1;
  iVar5 = *(int *)(iVar6 + 0x18);
  loopIndex2 = *(int *)(iVar6 + 0x24);
  *(undefined4 *)(iVar6 + 0x30) = 1;
  *(int **)(iVar6 + 0x18) = param_2;
  *(int **)(iVar6 + 0x24) = param_3;
  if (loopIndex < 3) {
    loopIndex3 = (int *)(loopIndex * 4 + param_1 + 0x18);
    do {
      piVar8 = (int *)*loopIndex3;
      if ((piVar8 != (int *)0x0) &&
         ((param_2 == piVar8 ||
          ((((param_2 != (int *)0x0 && (piVar8[0x20] != 0)) &&
            (iVar6 = RegKind__flagBit0(piVar8[0x26]), iVar6 != 0)) &&
           (((((piVar8[5] & 2U) == 0 && (iVar6 = (**(code **)(*piVar8 + 0x50))(piVar8), iVar6 == 0))
             && ((param_2[0x20] != 0 &&
                 ((iVar6 = RegKind__flagBit0(param_2[0x26]), iVar6 != 0 && ((param_2[5] & 2U) == 0))))))
            && ((iVar6 = (**(code **)(*param_2 + 0x50))(param_2), iVar6 == 0 &&
                ((((*(uint *)(*loopIndex3 + 0x14) & 0x40) != 0 && ((param_2[5] & 0x40U) != 0)) &&
                 (*(int *)(*loopIndex3 + 0x94) == param_2[0x25])))))))))))) {
        *loopIndex3 = 0;
      }
      piVar8 = (int *)loopIndex3[3];
      if ((piVar8 != (int *)0x0) &&
         ((param_3 == piVar8 ||
          ((((param_3 != (int *)0x0 && (piVar8[0x20] != 0)) &&
            ((iVar6 = RegKind__flagBit0(piVar8[0x26]), iVar6 != 0 &&
             (((piVar8[5] & 2U) == 0 && (iVar6 = (**(code **)(*piVar8 + 0x50))(piVar8), iVar6 == 0))
             )))) && (((param_3[0x20] != 0 &&
                       ((((iVar6 = RegKind__flagBit0(param_3[0x26]), iVar6 != 0 &&
                          ((param_3[5] & 2U) == 0)) &&
                         (iVar6 = (**(code **)(*param_3 + 0x50))(param_3), iVar6 == 0)) &&
                        (((*(uint *)(loopIndex3[3] + 0x14) & 0x40) != 0 && ((param_3[5] & 0x40U) != 0)))
                        ))) && (*(int *)(loopIndex3[3] + 0x94) == param_3[0x25])))))))) {
        loopIndex3[3] = 0;
      }
      bVar1 = loopIndex != 2;
      loopIndex3 = loopIndex3 + 1;
      loopIndex = loopIndex + 1;
    } while (bVar1);
  }
  if (((iVar5 == 0) || (iVar6 = ((int (*)())FUN_0018c7f4)(param_1,iVar5,0), iVar6 != 0)) &&
     ((loopIndex2 == 0 || (iVar6 = ((int (*)())FUN_0018c7f4)(param_1,loopIndex2,1), iVar6 != 0)))) {
LAB_0018cdb8:
    uVar3 = 1;
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}

/* FUN_0018cdd8 @ 0x18cdd8 (1456 bytes) */
int FUN_0018cdd8(param_1, param_2, param_3, param_4)
  int param_1;
  int *param_2;
  int *param_3;
  int param_4;
{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int *piVar6;
  
  iVar5 = param_4 * 8;
  iVar3 = iVar5 + param_1;
  piVar6 = *(int **)(iVar3 + 8);
  if ((piVar6 == (int *)0x0) || (piVar4 = *(int **)(iVar3 + 0xc), piVar4 == (int *)0x0)) {
    iVar3 = param_4 * 4;
    piVar6 = *(int **)(iVar3 + param_1);
    if ((((piVar6 == (int *)0x0) || (piVar6 == param_2)) ||
        (((((((param_2 != (int *)0x0 && (piVar6[0x20] != 0)) &&
             (iVar1 = RegKind__flagBit0(piVar6[0x26]), iVar1 != 0)) &&
            ((((piVar6[5] & 2U) == 0 && (iVar1 = (**(code **)(*piVar6 + 0x50))(piVar6), iVar1 == 0))
             && (param_2[0x20] != 0)))) &&
           ((iVar1 = RegKind__flagBit0(param_2[0x26]), iVar1 != 0 && ((param_2[5] & 2U) == 0)))) &&
          ((iVar1 = (**(code **)(*param_2 + 0x50))(param_2), iVar1 == 0 &&
           ((((*(uint *)(*(int *)(iVar3 + param_1) + 0x14) & 0x40) != 0 &&
             ((param_2[5] & 0x40U) != 0)) &&
            (*(int *)(*(int *)(iVar3 + param_1) + 0x94) == param_2[0x25])))))) ||
         ((piVar6 = *(int **)(iVar3 + param_1), param_3 == piVar6 ||
          ((((piVar6 != (int *)0x0 && (param_3 != (int *)0x0)) &&
            (((piVar6[0x20] != 0 &&
              ((iVar1 = RegKind__flagBit0(piVar6[0x26]), iVar1 != 0 && ((piVar6[5] & 2U) == 0)))) &&
             (iVar1 = (**(code **)(*piVar6 + 0x50))(piVar6), iVar1 == 0)))) &&
           (((((param_3[0x20] != 0 && (iVar1 = RegKind__flagBit0(param_3[0x26]), iVar1 != 0)) &&
              ((param_3[5] & 2U) == 0)) &&
             ((iVar1 = (**(code **)(*param_3 + 0x50))(param_3), iVar1 == 0 &&
              ((*(uint *)(*(int *)(iVar3 + param_1) + 0x14) & 0x40) != 0)))) &&
            (((param_3[5] & 0x40U) != 0 &&
             (*(int *)(*(int *)(iVar3 + param_1) + 0x94) == param_3[0x25])))))))))))) &&
       ((iVar3 = ((int (*)())FUN_0018c7f4)(param_1,param_2,param_4), iVar3 != 0 &&
        (iVar3 = ((int (*)())FUN_0018c7f4)(param_1,param_3,param_4), iVar3 != 0)))) {
      *(int **)(iVar5 + param_1 + 0xc) = param_3;
      *(int **)(iVar5 + param_1 + 8) = param_2;
      return 1;
    }
LAB_0018d170:
    uVar2 = 0;
  }
  else {
    if (piVar6 == param_2) {
LAB_0018cee8:
      if ((param_3 != piVar4) &&
         ((((piVar4 == (int *)0x0 || (param_3 == (int *)0x0)) ||
           ((piVar4[0x20] == 0 ||
            ((iVar1 = RegKind__flagBit0(piVar4[0x26]), iVar1 == 0 || ((piVar4[5] & 2U) != 0)))))) ||
          (((iVar1 = (**(code **)(*piVar4 + 0x50))(piVar4), iVar1 != 0 ||
            ((((param_3[0x20] == 0 || (iVar1 = RegKind__flagBit0(param_3[0x26]), iVar1 == 0)) ||
              ((param_3[5] & 2U) != 0)) ||
             ((iVar1 = (**(code **)(*param_3 + 0x50))(param_3), iVar1 != 0 ||
              ((*(uint *)(*(int *)(iVar3 + 0xc) + 0x14) & 0x40) == 0)))))) ||
           (((param_3[5] & 0x40U) == 0 || (*(int *)(*(int *)(iVar3 + 0xc) + 0x94) != param_3[0x25]))
           )))))) goto LAB_0018cfbc;
    }
    else {
      if (((((param_2 != (int *)0x0) && (piVar6[0x20] != 0)) &&
           (iVar1 = RegKind__flagBit0(piVar6[0x26]), iVar1 != 0)) &&
          ((((piVar6[5] & 2U) == 0 && (iVar1 = (**(code **)(*piVar6 + 0x50))(piVar6), iVar1 == 0))
           && ((param_2[0x20] != 0 &&
               ((iVar1 = RegKind__flagBit0(param_2[0x26]), iVar1 != 0 && ((param_2[5] & 2U) == 0))))))))
         && ((iVar1 = (**(code **)(*param_2 + 0x50))(param_2), iVar1 == 0 &&
             ((((*(uint *)(*(int *)(iVar3 + 8) + 0x14) & 0x40) != 0 && ((param_2[5] & 0x40U) != 0))
              && (*(int *)(*(int *)(iVar3 + 8) + 0x94) == param_2[0x25])))))) {
        piVar4 = *(int **)(iVar3 + 0xc);
        goto LAB_0018cee8;
      }
LAB_0018cfbc:
      iVar5 = iVar5 + param_1;
      piVar6 = *(int **)(iVar5 + 8);
      if (((param_3 != piVar6) &&
          (((((piVar6 == (int *)0x0 || (param_3 == (int *)0x0)) ||
             ((piVar6[0x20] == 0 ||
              (((iVar3 = RegKind__flagBit0(piVar6[0x26]), iVar3 == 0 || ((piVar6[5] & 2U) != 0)) ||
               (iVar3 = (**(code **)(*piVar6 + 0x50))(piVar6), iVar3 != 0)))))) ||
            ((param_3[0x20] == 0 || (iVar3 = RegKind__flagBit0(param_3[0x26]), iVar3 == 0)))) ||
           (((param_3[5] & 2U) != 0 ||
            (((iVar3 = (**(code **)(*param_3 + 0x50))(param_3), iVar3 != 0 ||
              ((*(uint *)(*(int *)(iVar5 + 8) + 0x14) & 0x40) == 0)) ||
             (((param_3[5] & 0x40U) == 0 || (*(int *)(*(int *)(iVar5 + 8) + 0x94) != param_3[0x25]))
             )))))))) ||
         ((piVar6 = *(int **)(iVar5 + 0xc), param_2 != piVar6 &&
          (((((piVar6 == (int *)0x0 || (param_2 == (int *)0x0)) || (piVar6[0x20] == 0)) ||
            ((iVar3 = RegKind__flagBit0(piVar6[0x26]), iVar3 == 0 || ((piVar6[5] & 2U) != 0)))) ||
           ((((iVar3 = (**(code **)(*piVar6 + 0x50))(piVar6), iVar3 != 0 ||
              ((param_2[0x20] == 0 || (iVar3 = RegKind__flagBit0(param_2[0x26]), iVar3 == 0)))) ||
             ((param_2[5] & 2U) != 0)) ||
            ((((iVar3 = (**(code **)(*param_2 + 0x50))(param_2), iVar3 != 0 ||
               ((*(uint *)(*(int *)(iVar5 + 0xc) + 0x14) & 0x40) == 0)) ||
              ((param_2[5] & 0x40U) == 0)) ||
             (*(int *)(*(int *)(iVar5 + 0xc) + 0x94) != param_2[0x25])))))))))) goto LAB_0018d170;
    }
    uVar2 = 1;
  }
  return uVar2;
}

/* FUN_0018d388 @ 0x18d388 (300 bytes) */
int FUN_0018d388(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  int param_3;
{
  int iVar1;
  int callResult;
  int *piVar3;
  
  iVar1 = param_3 * 4;
  piVar3 = *(int **)(iVar1 + param_1);
  if (piVar3 == (int *)0x0) {
    callResult = ((int (*)())FUN_0018c7f4)(param_1,param_2,param_3);
    if (callResult != 0) {
      *(int **)(iVar1 + param_1) = param_2;
      return 1;
    }
  }
  else if ((piVar3 == param_2) ||
          (((((param_2 != (int *)0x0 && (piVar3[0x20] != 0)) &&
             (callResult = RegKind__flagBit0(piVar3[0x26]), callResult != 0)) &&
            (((((piVar3[5] & 2U) == 0 && (callResult = (**(code **)(*piVar3 + 0x50))(piVar3), callResult == 0)
               ) && ((param_2[0x20] != 0 &&
                     ((callResult = RegKind__flagBit0(param_2[0x26]), callResult != 0 && ((param_2[5] & 2U) == 0)))
                     ))) && (callResult = (**(code **)(*param_2 + 0x50))(param_2), callResult == 0)))) &&
           ((((*(uint *)(*(int *)(iVar1 + param_1) + 0x14) & 0x40) != 0 &&
             ((param_2[5] & 0x40U) != 0)) &&
            (*(int *)(*(int *)(iVar1 + param_1) + 0x94) == param_2[0x25])))))) {
    return 1;
  }
  return 0;
}

/* FUN_0018d4b4 @ 0x18d4b4 (1428 bytes) */
int FUN_0018d4b4(inst, param_2, param_3, param_4, compiler)
  int *inst;
  int *param_2;
  int *param_3;
  int *param_4;
  int compiler;
{
  bool bVar1;
  int iVar2;
  int *piVar3;
  undefined4 operandVReg;
  int *operandVReg2;
  int iVar6;
  int *a0;
  int *a3;
  int a4;
  undefined4 in_r8;
  int iVar7;
  uint uVar8;
  int *piVar9;
  undefined8 operandVReg3;
  int local_68;
  float local_64;
  uint local_48;
  uint local_44;
  uint local_40 [5];
  
  iVar2 = *(int *)(inst[0x22] + 8);
  if ((((iVar2 == 0x9e) || (iVar2 == 0xa0)) || (iVar2 == 0x9f)) ||
     (iVar7 = 1, piVar3 = param_3, a3 = param_4, a4 = compiler, iVar2 == 0xa1)) {
    piVar3 = (int *)IRInst__getOperandSource(inst,1);
    iVar2 = (**(code **)(*piVar3 + 0x5c))(piVar3);
    if (iVar2 != 0) {
      return 0;
    }
    iVar2 = IRInst__getOperandRecord(inst,0);
    if (((*(char *)(iVar2 + 0x10) == '\0') ||
        (iVar2 = IRInst__getOperandRecord(inst,0), *(char *)(iVar2 + 0x11) == '\0')) ||
       (iVar2 = IRInst__getOperandRecord(inst,0), *(char *)(iVar2 + 0x12) == '\0')) {
      operandVReg = IRInst__getOperandSource(inst,1);
      iVar2 = ((int (*)())FUN_0018d388)(param_4,operandVReg,0);
      if (iVar2 == 0) {
        return 0;
      }
    }
    iVar2 = IRInst__getOperandRecord(inst,0);
    if (*(char *)(iVar2 + 0x13) == '\0') {
      operandVReg = IRInst__getOperandSource(inst,1);
      iVar2 = ((int (*)())FUN_0018d388)(param_4,operandVReg,1);
      if (iVar2 == 0) {
        return 0;
      }
    }
  }
  else {
    for (; iVar2 = (**(code **)(*inst + 0x14))(inst), iVar7 <= iVar2; iVar7 = iVar7 + 1) {
      operandVReg2 = (int *)IRInst__getOperandSource(inst,iVar7);
      iVar2 = (**(code **)(*operandVReg2 + 0x60))(operandVReg2);
      if (iVar2 != 0) {
        operandVReg2 = (int *)IRInst__getOperandSource(operandVReg2,1);
        (**(code **)(*operandVReg2 + 0x60))(operandVReg2);
      }
      iVar6 = (**(code **)(*operandVReg2 + 0x5c))(operandVReg2);
      if (iVar6 != 0) {
        if (((operandVReg2[0x56] != 0) && (inst[0x56] != 0)) && (inst[0x56] != operandVReg2[0x56])) {
          DList__unlink(operandVReg2);
          piVar3 = operandVReg2;
          Block__insertInstAfter(inst[0x56],inst[1],operandVReg2);
        }
        iVar6 = *(int *)(operandVReg2[0x22] + 8);
        if (iVar2 == 0) {
          iVar2 = IRInst__getOperandRecord(inst,iVar7);
          FUN_000f3398(&local_44,*(undefined4 *)(iVar2 + 0x10));
          uVar8 = local_44;
        }
        else {
          operandVReg = IRInst__getOperandSource(inst,iVar7);
          iVar2 = IRInst__getOperandRecord(operandVReg,1);
          FUN_000f3398(&local_48,*(undefined4 *)(iVar2 + 0x10));
          uVar8 = local_48;
        }
        if ((uVar8 & 0xffffff00) != 0) {
          if ((-1 < *param_2) && (iVar6 != *param_2)) {
            return 0;
          }
          *param_2 = iVar6;
          iVar2 = (**(code **)(*operandVReg2 + 0x14))(operandVReg2);
          if (iVar2 == 1) {
            operandVReg = IRInst__getOperandSource(operandVReg2,1);
            piVar3 = (int *)0x0;
            iVar2 = ((int (*)())FUN_0018d388)(param_4,operandVReg,0);
          }
          else {
            operandVReg = IRInst__getOperandSource(operandVReg2,1);
            piVar3 = (int *)IRInst__getOperandSource(operandVReg2,2);
            a3 = (int *)0x0;
            iVar2 = ((int (*)())FUN_0018cdd8)(param_4,operandVReg,piVar3,0);
          }
          if (iVar2 == 0) {
            return 0;
          }
        }
        if ((uVar8 & 0xff) != 0) {
          if ((-1 < *param_3) && (iVar6 != *param_3)) {
            return 0;
          }
          *param_3 = iVar6;
          iVar2 = (**(code **)(*operandVReg2 + 0x14))(operandVReg2);
          if (iVar2 == 1) {
            operandVReg = IRInst__getOperandSource(operandVReg2,1);
            piVar3 = (int *)((int)((unsigned char *)0x0) + 1);
            iVar2 = ((int (*)())FUN_0018d388)(param_4,operandVReg,1);
          }
          else {
            operandVReg = IRInst__getOperandSource(operandVReg2,1);
            piVar3 = (int *)IRInst__getOperandSource(operandVReg2,2);
            a3 = (int *)((int)((unsigned char *)0x0) + 1);
            iVar2 = ((int (*)())FUN_0018cdd8)(param_4,operandVReg,piVar3,1);
          }
          if (iVar2 == 0) {
            return 0;
          }
        }
      }
    }
    for (iVar2 = 1; iVar7 = (**(code **)(*inst + 0x14))(inst), iVar2 <= iVar7;
        iVar2 = iVar2 + 1) {
      operandVReg2 = (int *)IRInst__getOperandSource(inst,iVar2);
      iVar7 = (**(code **)(*operandVReg2 + 0x60))(operandVReg2);
      if (iVar7 == 0) {
        bVar1 = false;
        piVar9 = inst;
        a0 = operandVReg2;
        iVar7 = iVar2;
LAB_0018d948:
        iVar6 = (**(code **)(*a0 + 0x5c))(a0);
        if ((iVar6 == 0) && ((bVar1 || (a0[0x26] != 0x33)))) {
          iVar7 = IRInst__getOperandRecord(piVar9,iVar7);
          FUN_000f3398(local_40,*(undefined4 *)(iVar7 + 0x10));
          if ((local_40[0] & 0xffffff00) == 0) {
            if ((local_40[0] & 0xff) == 0) goto LAB_0018da08;
            piVar3 = (int *)((int)((unsigned char *)0x0) + 1);
            iVar7 = ((int (*)())FUN_0018c7f4)(param_4,a0,1);
          }
          else if ((local_40[0] & 0xff) == 0) {
            piVar3 = (int *)0x0;
            iVar7 = ((int (*)())FUN_0018c7f4)(param_4,a0,0);
          }
          else {
            iVar7 = ((int (*)())FUN_0018c980)(param_4,a0,a0);
            piVar3 = a0;
          }
          if (iVar7 == 0) {
            return 0;
          }
        }
      }
      else {
        operandVReg3 = IRInst__getOperandSource(operandVReg2,1);
        a0 = (int *)((ulonglong)operandVReg3 >> 0x20);
        (**(code **)(*a0 + 0x60))(a0,(int)operandVReg3,piVar3,a3,a4,in_r8,*(code **)(*a0 + 0x60));
        piVar9 = operandVReg2;
        if (a0[0x26] != 0x33) {
LAB_0018d93c:
          bVar1 = false;
          iVar7 = 1;
          goto LAB_0018d948;
        }
        iVar7 = IRInst__getOperandRecord(operandVReg2,0);
        piVar3 = *(int **)(iVar7 + 0x10);
        a3 = &local_68;
        iVar7 = FUN_000f5cf0(operandVReg2,1,piVar3,a3);
        if (((iVar7 == 0) || (local_68 != 2)) ||
           (iVar7 = (**(code **)(**(int **)(compiler + COMP_target) + 0xf0))((double)local_64), iVar7 == 0)
           ) {
          iVar7 = IRInst__hasSingleUse(operandVReg2,*(undefined4 *)(compiler + COMP_currentProgram));
          if (iVar7 == 0) {
            bVar1 = true;
            iVar7 = 1;
            goto LAB_0018d948;
          }
          goto LAB_0018d93c;
        }
      }
LAB_0018da08: ;
    }
  }
  return 1;
}

/* FUN_0018da48 @ 0x18da48 (116 bytes) */
int FUN_0018da48(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  int callResult;
  undefined4 uVar2;
  undefined4 local_68;
  undefined4 local_64;
  undefined1 auStack_60 [8];
  undefined1 auStack_58 [72];
  
  local_64 = 0xffffffff;
  local_68 = 0xffffffff;
  ((int (*)())PackState__reset)(auStack_58);
  callResult = ((int (*)())FUN_0018d4b4)(param_1,&local_68,&local_64,auStack_58,param_2);
  uVar2 = 0;
  if (callResult != 0) {
    uVar2 = ((int (*)())PackState__countFreeSlots)(auStack_58,auStack_60);
  }
  return uVar2;
}

/* R300SchedModel__vslot13 @ 0x18dabc (1680 bytes) */
int R300SchedModel__vslot13(this, param_2)
  int *this;
  int param_2;
{
  int operandRecord3;
  int operandRecord2;
  int sourceDef;
  bool bVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  int *piVar7;
  int loopIndex;
  int *a0;
  int operandRecord;
  undefined4 *puVar10;
  uint uVar11;
  uint loopIndex2;
  int iVar13;
  int iVar14;
  uint loopIndex3;
  int iVar16;
  undefined4 uVar17;
  undefined4 uVar18;
  uint *puVar19;
  /* issue #64 (auto): growable-vector header (capacity/count/data-pointer/arena) used with Vector__elementRefGrow - local_78/local_74/local_70/local_6c are its four words by their own hex offsets. Vector__elementRefGrow unconditionally reads all four on every call (even its "no grow needed" path reallocs+copies+frees), so they must be one contiguous buffer; left as four separate locals, an -O0 rebuild does not place them contiguously. Merged into one 0x10-byte buffer (part of the issue #64 live-differential sweep). */
  unsigned char local_78_buf [0x10];
  #define local_78 (*(uint *)(local_78_buf + 0x00))
  #define local_74 (*(uint *)(local_78_buf + 0x04))
  #define local_70 (*(int *)(local_78_buf + 0x08))
  #define local_6c (*(undefined4 *)(local_78_buf + 0x0c))
  /* issue #64 (auto): growable-vector header (capacity/count/data-pointer/arena) used with Vector__elementRefGrow - local_68/local_64/local_60/local_5c are its four words by their own hex offsets. Vector__elementRefGrow unconditionally reads all four on every call (even its "no grow needed" path reallocs+copies+frees), so they must be one contiguous buffer; left as four separate locals, an -O0 rebuild does not place them contiguously. Merged into one 0x10-byte buffer (part of the issue #64 live-differential sweep). */
  unsigned char local_68_buf [0x10];
  #define local_68 (*(uint *)(local_68_buf + 0x00))
  #define local_64 (*(uint *)(local_68_buf + 0x04))
  #define local_60 (*(int *)(local_68_buf + 0x08))
  #define local_5c (*(undefined4 *)(local_68_buf + 0x0c))
  /* issue #64 (auto): growable-vector header (capacity/count/data-pointer/arena) used with Vector__elementRefGrow - local_58/local_54/local_50/local_4c are its four words by their own hex offsets. Vector__elementRefGrow unconditionally reads all four on every call (even its "no grow needed" path reallocs+copies+frees), so they must be one contiguous buffer; left as four separate locals, an -O0 rebuild does not place them contiguously. Merged into one 0x10-byte buffer (part of the issue #64 live-differential sweep). */
  unsigned char local_58_buf [0x10];
  #define local_58 (*(uint *)(local_58_buf + 0x00))
  #define local_54 (*(uint *)(local_58_buf + 0x04))
  #define local_50 (*(int *)(local_58_buf + 0x08))
  #define local_4c (*(undefined4 *)(local_58_buf + 0x0c))
  
  iVar14 = *(int *)(param_2 + 0x38);
  iVar3 = (**(code **)(*this + 0x30))(this,iVar14);
  if ((iVar3 == 0) ||
     ((iVar3 = *(int *)(PTR_DAT_001e913c + *(int *)(*(int *)(iVar14 + 0x88) + 8) * 0x38 + 0x34),
      *(int *)(param_2 + 0x60) != 0 && (iVar4 = FUN_000f3a30(iVar14), iVar4 != 1)))) {
    uVar5 = 0;
  }
  else {
    operandRecord3 = IRInst__getOperandRecord(iVar14,0);
    if (*(char *)(operandRecord3 + 0x13) == '\0') {
      if (iVar3 == 0) {
        operandRecord2 = IRInst__getOperandRecord(iVar14,0);
        iVar4 = 3;
        uVar5 = FUN_000f3108(*(undefined4 *)(operandRecord2 + 0x10));
        iVar3 = 3;
      }
      else if (iVar3 - 1U < 2) {
        iVar4 = 3;
        uVar5 = 0;
        iVar3 = 3;
      }
      else {
        iVar4 = 3;
        uVar5 = 0xffffffff;
        iVar3 = 3;
      }
    }
    else if ((iVar3 == 5) && (*(int *)(param_2 + 0x60) == 0)) {
      iVar4 = 0;
      uVar5 = 3;
      iVar3 = 2;
    }
    else {
      operandRecord2 = IRInst__getOperandRecord(iVar14,0);
      uVar5 = 3;
      iVar4 = FUN_000f30d4(*(undefined4 *)(operandRecord2 + 0x10));
      iVar3 = iVar4;
    }
    local_6c = *(undefined4 *)(this[2] + 0x378);
    local_74 = 0;
    local_78 = 2;
    local_70 = Arena__alloc(local_6c,8);
    local_5c = *(undefined4 *)(this[2] + 0x378);
    local_64 = 0;
    local_68 = 2;
    local_60 = Arena__alloc(local_5c,8);
    local_4c = *(undefined4 *)(this[2] + 0x378);
    local_54 = 0;
    local_58 = 2;
    local_50 = Arena__alloc(local_4c,8);
    puVar19 = *(uint **)(param_2 + 0x40);
    uVar11 = puVar19[1];
    if (0 < (int)uVar11) {
      loopIndex3 = 0;
      loopIndex2 = 1;
      iVar13 = 0;
      do {
        if (loopIndex3 < *puVar19) {
          uVar6 = puVar19[1];
          if (uVar6 <= loopIndex3) {
            _memset(uVar6 * 4 + puVar19[2],0,(loopIndex3 - uVar6) * 4 + 4);
            puVar19[1] = loopIndex2;
          }
          piVar7 = (int *)(iVar13 + puVar19[2]);
        }
        else {
          piVar7 = (int *)Vector__elementRefGrow(puVar19,loopIndex3);
        }
        iVar16 = *piVar7;
        if (*(int *)(iVar16 + 8) == 0) {
          puVar19 = *(uint **)(param_2 + 0x40);
          if (loopIndex3 < *puVar19) {
            uVar6 = puVar19[1];
            if (uVar6 <= loopIndex3) {
              _memset(uVar6 * 4 + puVar19[2],0,(loopIndex3 - uVar6) * 4 + 4);
              puVar19[1] = loopIndex2;
            }
            piVar7 = (int *)(iVar13 + puVar19[2]);
          }
          else {
            piVar7 = (int *)Vector__elementRefGrow(puVar19,loopIndex3);
          }
          piVar7 = *(int **)(*(int *)(*piVar7 + 4) + 0x38);
          if ((((piVar7[5] & 0x200U) == 0) ||
              (loopIndex = IRInst__getOperandSource(piVar7,piVar7[0x21]), iVar14 != loopIndex)) &&
             ((loopIndex = (**(code **)(*piVar7 + 0x28))(piVar7), loopIndex == 0 ||
              ((*(uint *)(*(int *)(this[2] + 0x30c) + 8) & 0x800) != 0)))) {
            loopIndex = (**(code **)(*piVar7 + 0x5c))(piVar7);
            if (loopIndex != 0) {
              iVar16 = (**(code **)(*piVar7 + 0x14))(piVar7);
              if (1 < iVar16) {
                sourceDef = IRInst__getOperandSource(piVar7,1);
                loopIndex = IRInst__getOperandSource(piVar7,2);
                if (sourceDef != loopIndex) goto LAB_0018dda4;
              }
              goto LAB_0018e058;
            }
            loopIndex = *(int *)(piVar7[0x22] + 8);
            if ((((loopIndex == 0x9e) || (loopIndex == 0xa0)) || (loopIndex == 0x9f)) || (loopIndex == 0xa1))
            goto LAB_0018dda4;
            loopIndex = *(int *)(iVar16 + 0x10);
            if ((loopIndex < 1) || (*(int *)(iVar16 + 0x14) != 0)) {
              a0 = (int *)IRInst__getOperandSource(piVar7,loopIndex);
              loopIndex = (**(code **)(*a0 + 0x5c))(a0);
              if (loopIndex != 0) {
                loopIndex = *(int *)(iVar16 + 0x10);
                goto LAB_0018de84;
              }
            }
            else {
LAB_0018de84:
              loopIndex = IRInst__getOperandRecord(piVar7,loopIndex);
              uVar18 = *(undefined4 *)(loopIndex + 0x10);
              bVar2 = false;
              loopIndex = 0;
              do {
                operandRecord = IRInst__getOperandRecord(piVar7,*(undefined4 *)(iVar16 + 0x10));
                uVar6 = (uint)*(byte *)(loopIndex + operandRecord + 0x10);
                if ((iVar4 <= (int)uVar6) && ((int)uVar6 <= iVar3)) {
                  (**(code **)(*piVar7 + 0x88))(piVar7,*(undefined4 *)(iVar16 + 0x10),loopIndex,uVar5);
                  bVar2 = true;
                }
                uVar6 = local_74;
                bVar1 = loopIndex != 3;
                loopIndex = loopIndex + 1;
              } while (bVar1);
              if (bVar2) {
                if (local_74 < local_78) {
                  loopIndex = local_74 * 4;
                  _memset(loopIndex + local_70,0,4);
                  local_74 = uVar6 + 1;
                  puVar10 = (undefined4 *)(loopIndex + local_70);
                }
                else {
                  puVar10 = (undefined4 *)Vector__elementRefGrow(&local_78,local_74);
                }
                uVar6 = local_64;
                *puVar10 = piVar7;
                uVar17 = *(undefined4 *)(iVar16 + 0x10);
                if (local_64 < local_68) {
                  iVar16 = local_64 * 4;
                  _memset(iVar16 + local_60,0,4);
                  local_64 = uVar6 + 1;
                  puVar10 = (undefined4 *)(iVar16 + local_60);
                }
                else {
                  puVar10 = (undefined4 *)Vector__elementRefGrow(&local_68,local_64);
                }
                uVar6 = local_54;
                *puVar10 = uVar17;
                if (local_54 < local_58) {
                  iVar16 = local_54 * 4;
                  _memset(iVar16 + local_50,0,4);
                  local_54 = uVar6 + 1;
                  puVar10 = (undefined4 *)(iVar16 + local_50);
                }
                else {
                  puVar10 = (undefined4 *)Vector__elementRefGrow(&local_58,local_54);
                }
                *puVar10 = uVar18;
              }
            }
            iVar16 = (**(code **)(*piVar7 + 0x5c))(piVar7);
            if (((iVar16 != 0) || (iVar16 = (**(code **)(*piVar7 + 0x60))(piVar7), iVar16 != 0)) ||
               ((iVar16 = (**(code **)(*this + 0x88))(this,piVar7), iVar16 != 0 &&
                (iVar16 = ((int (*)())FUN_0018da48)(piVar7,this[2]), iVar16 != 0)))) goto LAB_0018e058;
          }
LAB_0018dda4:
          uVar5 = 0;
          goto LAB_0018e110;
        }
LAB_0018e058:
        loopIndex3 = loopIndex3 + 1;
        loopIndex2 = loopIndex2 + 1;
        iVar13 = iVar13 + 4;
        if (uVar11 == loopIndex3) break;
        puVar19 = *(uint **)(param_2 + 0x40);
      } while( true );
    }
    uVar5 = 1;
LAB_0018e110:
    while (local_74 != 0) {
      uVar11 = local_74 - 1;
      piVar7 = (int *)0x0;
      if (uVar11 < local_74) {
        piVar7 = (int *)(uVar11 * 4 + local_70);
      }
      iVar3 = *piVar7;
      Vector__removeAt(&local_78,uVar11);
      piVar7 = (int *)0x0;
      uVar11 = local_64 - 1;
      if (uVar11 < local_64) {
        piVar7 = (int *)(uVar11 * 4 + local_60);
      }
      iVar14 = *piVar7;
      Vector__removeAt(&local_68,uVar11);
      puVar10 = (undefined4 *)0x0;
      uVar11 = local_54 - 1;
      if (uVar11 < local_54) {
        puVar10 = (undefined4 *)(uVar11 * 4 + local_50);
      }
      uVar18 = *puVar10;
      Vector__removeAt(&local_58,uVar11);
      if (iVar14 == 0) {
        *(undefined4 *)(iVar3 + 0x9c) = uVar18;
      }
      else {
        operandRecord2 = IRInst__getOperandRecord(iVar3,iVar14);
        *(undefined4 *)(operandRecord2 + 0x10) = uVar18;
      }
    }
    Arena__free(local_4c,local_50);
    Arena__free(local_5c,local_60);
    Arena__free(local_6c,local_70);
  }
  return uVar5;
}
#undef local_78
#undef local_74
#undef local_70
#undef local_6c
#undef local_68
#undef local_64
#undef local_60
#undef local_5c
#undef local_58
#undef local_54
#undef local_50
#undef local_4c

/* R300SchedModel__vslot27 @ 0x18e1a8 (1724 bytes) */
int R300SchedModel__vslot27(this, inst)
  int *this;
  int *inst;
{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  float fVar4;
  int loopIndex4;
  int *piVar6;
  int loopIndex5;
  int iVar8;
  undefined4 *puVar9;
  int *inst2;
  int *piVar11;
  int loopIndex;
  undefined4 uVar13;
  int loopIndex2;
  int iVar15;
  undefined4 uVar16;
  int iVar17;
  uint *loopIndex6;
  undefined4 uVar19;
  int loopIndex3;
  uint loopIndex7;
  double dVar22;
  int local_98;
  /* issue #64 (auto): growable-vector header (capacity/count/data-pointer/arena) used with Vector__elementRefGrow - local_94/local_90/local_8c/local_88 are its four words by their own hex offsets. Vector__elementRefGrow unconditionally reads all four on every call (even its "no grow needed" path reallocs+copies+frees), so they must be one contiguous buffer; left as four separate locals, an -O0 rebuild does not place them contiguously. Merged into one 0x10-byte buffer (part of the issue #64 live-differential sweep). */
  unsigned char local_94_buf [0x10];
  #define local_94 (*(uint *)(local_94_buf + 0x00))
  #define local_90 (*(uint *)(local_94_buf + 0x04))
  #define local_8c (*(int *)(local_94_buf + 0x08))
  #define local_88 (*(undefined4 *)(local_94_buf + 0x0c))
  uint local_84 [7];
  undefined4 local_68;
  undefined4 local_64;
  int local_60;
  undefined4 local_5c [3];
  
  iVar15 = inst[0x56];
  iVar17 = *(int *)(this[2] + 0x6c4);
  loopIndex4 = Compiler__isOptionEnabled(this[2],0x40);
  if (((loopIndex4 == 0) || (*(int *)(inst[0x22] + 8) != 0x77)) || ((inst[5] & 0x2000000U) != 0)) {
    piVar6 = (int *)0x0;
  }
  else {
    local_88 = *(undefined4 *)(this[2] + 0x378);
    local_90 = 0;
    local_94 = 2;
    local_8c = Arena__alloc(local_88,8);
    local_84[3] = *(undefined4 *)(this[2] + 0x378);
    local_84[1] = 0;
    local_84[0] = 2;
    local_84[2] = Arena__alloc(local_84[3],8);
    loopIndex2 = *(int *)(iVar17 + 0x474) + 1;
    *(int *)(iVar17 + 0x474) = loopIndex2;
    loopIndex4 = IRInst__getOperandSource(inst,1);
    *(int *)(loopIndex4 + 0x150) = loopIndex2;
    if (local_90 < local_94) {
      loopIndex5 = local_90 * 4;
      loopIndex7 = local_90 + 1;
      _memset(loopIndex5 + local_8c,0,4);
      piVar6 = (int *)(loopIndex5 + local_8c);
      local_90 = loopIndex7;
    }
    else {
      piVar6 = (int *)Vector__elementRefGrow(&local_94,local_90);
    }
    *piVar6 = loopIndex4;
    bVar2 = false;
    bVar3 = false;
    do {
      loopIndex7 = local_90 - 1;
      piVar6 = (int *)0x0;
      if (loopIndex7 < local_90) {
        piVar6 = (int *)(loopIndex7 * 4 + local_8c);
      }
      loopIndex3 = *piVar6;
      Vector__removeAt(&local_94,loopIndex7);
      loopIndex5 = OpcodeTraits__flagBit12(*(undefined4 *)(*(int *)(loopIndex3 + 0x88) + 8),this[2]);
      if (loopIndex5 != 0) goto LAB_0018e6f8;
      loopIndex5 = OpcodeTraits__flagBit13(*(undefined4 *)(*(int *)(loopIndex3 + 0x88) + 8),this[2]);
      if (loopIndex5 != 0) {
        loopIndex5 = *(int *)(*(int *)(loopIndex3 + 0x88) + 8);
        if (((loopIndex5 == 0x24) || (loopIndex5 == 0x25)) || (loopIndex = 1, loopIndex5 == 0x26)) {
          loopIndex = 2;
        }
        if (loopIndex <= *(int *)(loopIndex3 + 0x84)) {
          loopIndex5 = loopIndex * 0x18;
          loopIndex6 = (uint *)(loopIndex5 + loopIndex3 + 0xa0);
          do {
            piVar6 = (int *)IRInst__getOperandSource(loopIndex3,loopIndex);
            if (loopIndex2 != piVar6[0x54]) {
              piVar6[0x54] = loopIndex2;
              iVar8 = OpcodeTraits__flagBit12(*(undefined4 *)(piVar6[0x22] + 8),this[2]);
              if (iVar8 != 0) {
LAB_0018e6e0:
                bVar2 = true;
                break;
              }
              if ((*loopIndex6 & 1) != 0) {
                iVar8 = (**(code **)(*piVar6 + 0x48))(piVar6);
                if (iVar8 == 0) {
                  iVar8 = IRInst__hasSingleUse(piVar6,iVar17);
                  if (iVar8 == 0) goto LAB_0018e6e0;
                  iVar8 = *(int *)(piVar6[0x22] + 8);
                  if (iVar8 == 0x31) {
LAB_0018e4e0:
                    IROperand__setModifierBits(piVar6 + 0x29,1,piVar6[0x2e] & 1U ^ 1);
                  }
                  else if (iVar8 == 0x12) {
                    IROperand__setModifierBits(piVar6 + 0x29,1,piVar6[0x2e] & 1U ^ 1);
                    IROperand__setModifierBits(piVar6 + 0x2f,1,piVar6[0x34] & 1U ^ 1);
                  }
                  else {
                    if (iVar8 == 0x13) goto LAB_0018e4e0;
                    if (iVar8 == 0x14) {
                      IROperand__setModifierBits(piVar6 + 0x29,1,piVar6[0x2e] & 1U ^ 1);
                    }
                    else {
                      if (((iVar8 != 0x24) && (iVar8 != 0x25)) && (iVar8 != 0x26))
                      goto LAB_0018e6e0;
                      iVar8 = ((undefined4 (*)())FUN_00139838)(piVar6,2,(double)FLOAT_001aa0d4);
                      if (iVar8 == 0) {
                        IROperand__setModifierBits(piVar6 + 0x2f,1,piVar6[0x34] & 1U ^ 1);
                      }
                      iVar8 = ((undefined4 (*)())FUN_00139838)(piVar6,3,(double)FLOAT_001aa0d4);
                      if (iVar8 != 0) goto LAB_0018e5a0;
                    }
                    IROperand__setModifierBits(piVar6 + 0x35,1,piVar6[0x3a] & 1U ^ 1);
                  }
LAB_0018e5a0:
                  uVar13 = 0;
                }
                else {
                  iVar8 = ((undefined4 (*)())FUN_00139838)(loopIndex3,loopIndex,(double)FLOAT_001aa0d4);
                  fVar4 = FLOAT_001aa0d4;
                  if (iVar8 != 0) goto LAB_0018e5a0;
                  loopIndex7 = 0;
                  piVar11 = piVar6;
                  do {
                    iVar8 = IRInst__getOperandRecord(piVar6,0);
                    if ((*(char *)(loopIndex7 + iVar8 + 0x10) != '\x01') &&
                       (((((int)*(char *)(piVar6 + 0x57) >> (loopIndex7 & 0x3f) & 1U) == 0 ||
                         (piVar11[7] != 2)) || (GH_U2F((unsigned int)(piVar11[8])) == fVar4)))) goto LAB_0018e6e0;
                    bVar1 = loopIndex7 != 3;
                    piVar11 = piVar11 + 6;
                    loopIndex7 = loopIndex7 + 1;
                  } while (bVar1);
                  if (bVar2) goto LAB_0018e6e0;
                  uVar13 = 1;
                }
                IROperand__setModifierBits(loopIndex5 + loopIndex3 + 0x8c,1,uVar13);
              }
              iVar8 = OpcodeTraits__flagBit13(*(undefined4 *)(piVar6[0x22] + 8),this[2]);
              if (iVar8 == 0) {
                if (*(int *)(piVar6[0x22] + 8) == 0x31) {
                  iVar8 = IRInst__getOperandSource(piVar6,1);
                  iVar8 = OpcodeTraits__flagBit12(*(undefined4 *)(*(int *)(iVar8 + 0x88) + 8),this[2]);
                  if (iVar8 == 0) {
                    iVar8 = IRInst__getOperandSource(piVar6,1);
                    iVar8 = OpcodeTraits__flagBit13(*(undefined4 *)(*(int *)(iVar8 + 0x88) + 8),this[2]);
                    if (iVar8 == 0) goto LAB_0018e6c4;
                  }
                  loopIndex7 = local_84[1];
                  if (local_84[1] < local_84[0]) {
                    iVar8 = local_84[1] * 4;
                    _memset(iVar8 + local_84[2],0,4);
                    local_84[1] = loopIndex7 + 1;
                    puVar9 = (undefined4 *)(iVar8 + local_84[2]);
                  }
                  else {
                    puVar9 = (undefined4 *)Vector__elementRefGrow(local_84,local_84[1]);
                  }
                  *puVar9 = piVar6;
                  bVar3 = true;
                }
              }
              else {
                if (local_90 < local_94) {
                  iVar8 = local_90 * 4;
                  loopIndex7 = local_90 + 1;
                  _memset(iVar8 + local_8c,0,4);
                  puVar9 = (undefined4 *)(iVar8 + local_8c);
                  local_90 = loopIndex7;
                }
                else {
                  puVar9 = (undefined4 *)Vector__elementRefGrow(&local_94,local_90);
                }
                *puVar9 = piVar6;
              }
            }
LAB_0018e6c4:
            loopIndex = loopIndex + 1;
            loopIndex5 = loopIndex5 + 0x18;
            loopIndex6 = loopIndex6 + 6;
          } while (loopIndex <= *(int *)(loopIndex3 + 0x84));
        }
      }
    } while (local_90 != 0);
    if (bVar2) {
LAB_0018e6f8:
      *(int *)(iVar17 + 0x238) = *(int *)(iVar17 + 0x238) + 1;
      piVar6 = (int *)IRInst__create(0x31,this[2]);
      piVar6[0x26] = 0;
      piVar6[0x25] = piVar6[0x53];
      IRInst__setOperandSource(piVar6,1,loopIndex4,0,this[2]);
      IRInst__setOperandSource(inst,1,piVar6,0,this[2]);
      uVar13 = DAT_001b2a68;
      piVar6[0x27] = DAT_001b2a80;
      loopIndex4 = IRInst__getOperandRecord(piVar6,1);
      *(undefined4 *)(loopIndex4 + 0x10) = uVar13;
      loopIndex4 = 0;
      do {
        loopIndex2 = IRInst__getOperandRecord(inst,1);
        loopIndex7 = (uint)*(byte *)(loopIndex4 + loopIndex2 + 0x10);
        if (loopIndex7 != 4) {
          (**(code **)(*piVar6 + 0x88))(piVar6,1,loopIndex7,loopIndex7);
          *(undefined1 *)((int)piVar6 + loopIndex7 + 0x9c) = 0;
        }
        bVar2 = loopIndex4 != 3;
        loopIndex4 = loopIndex4 + 1;
      } while (bVar2);
      Block__insertInstBefore(iVar15,inst,piVar6);
      piVar6[5] = piVar6[5] | 0x80000000;
    }
    else {
      if (bVar3) {
        while (local_84[1] != 0) {
          loopIndex7 = local_84[1] - 1;
          piVar6 = (int *)0x0;
          if (loopIndex7 < local_84[1]) {
            piVar6 = (int *)(loopIndex7 * 4 + local_84[2]);
          }
          loopIndex4 = *piVar6;
          Vector__removeAt(local_84,loopIndex7);
          *(uint *)(loopIndex4 + 0x14) = *(uint *)(loopIndex4 + 0x14) | 0x80000000;
        }
      }
      piVar6 = (int *)0x0;
    }
    Arena__free(local_84[3],local_84[2]);
    Arena__free(local_88,local_8c);
  }
  uVar13 = 0;
  loopIndex4 = (**(code **)(*inst + 0x28))(inst);
  if (loopIndex4 != 0) {
    bVar2 = piVar6 == (int *)0x0;
    for (loopIndex4 = 1; loopIndex2 = (**(code **)(*inst + 0x14))(inst), loopIndex4 <= loopIndex2;
        loopIndex4 = loopIndex4 + 1) {
      piVar11 = (int *)IRInst__getOperandSource(inst,loopIndex4);
      loopIndex2 = (**(code **)(*piVar11 + 0x60))();
      if (loopIndex2 == 0) {
code_r0x0018e934:
        piVar11 = (int *)IRInst__getOperandSource(inst,loopIndex4);
        loopIndex2 = (**(code **)(*piVar11 + 0x48))();
        if (loopIndex2 == 0) {
          piVar11 = (int *)IRInst__getOperandSource(inst,loopIndex4);
          loopIndex2 = (**(code **)(*piVar11 + 0x60))();
          if ((loopIndex2 == 0) &&
             ((((inst[loopIndex4 * 6 + 0x28] & 2U) == 0 && ((inst[loopIndex4 * 6 + 0x28] & 1U) == 0)) ||
              (loopIndex2 = FUN_00148d8c(inst,iVar17), loopIndex2 != 0)))) goto code_r0x0018eb5c;
        }
        loopIndex5 = 0;
        *(int *)(iVar17 + 0x238) = *(int *)(iVar17 + 0x238) + 1;
        inst2 = (int *)IRInst__create(0x31,this[2]);
        inst2[0x26] = 0;
        inst2[0x25] = inst2[0x53];
        uVar13 = IRInst__getOperandSource(inst,loopIndex4);
        IRInst__setOperandSource(inst2,1,uVar13,0,this[2]);
        IROperand__setModifierBits(inst2 + 0x29,2,(uint)inst[loopIndex4 * 6 + 0x28] >> 1 & 1);
        IROperand__setModifierBits(inst2 + 0x29,1,inst[loopIndex4 * 6 + 0x28] & 1);
        loopIndex2 = IRInst__getOperandRecord(inst,loopIndex4);
        uVar13 = *(undefined4 *)(loopIndex2 + 0x10);
        loopIndex2 = IRInst__getOperandRecord(inst2,1);
        local_94 = DAT_001b2a64;
        *(undefined4 *)(loopIndex2 + 0x10) = uVar13;
        piVar11 = inst2;
        do {
          loopIndex2 = IRInst__getOperandRecord(inst,loopIndex4);
          if (*(char *)(loopIndex5 + loopIndex2 + 0x10) == '\x04') {
            *(undefined1 *)(piVar11 + 0x27) = 1;
            *(undefined1 *)((int)&local_94 + loopIndex5) = 4;
          }
          bVar3 = loopIndex5 != 3;
          piVar11 = (int *)((int)piVar11 + 1);
          loopIndex5 = loopIndex5 + 1;
        } while (bVar3);
        Block__insertInstBefore(iVar15,inst,inst2);
        IRInst__setOperandSource(inst,loopIndex4,inst2,0,this[2]);
        IROperand__setModifierBits(inst + loopIndex4 * 6 + 0x23,2,0);
        IROperand__setModifierBits(inst + loopIndex4 * 6 + 0x23,1,0);
        loopIndex7 = local_94;
        loopIndex2 = IRInst__getOperandRecord(inst,loopIndex4);
        *(uint *)(loopIndex2 + 0x10) = loopIndex7;
        if (bVar2) {
          bVar2 = inst2 == (int *)0x0;
          uVar13 = 1;
          piVar6 = inst2;
        }
        else {
          uVar13 = 1;
        }
      }
      else {
        uVar16 = IRInst__getOperandSource(inst,loopIndex4);
        uVar16 = IRInst__getOperandSource(uVar16,1);
        loopIndex2 = IRInst__hasSingleUse(uVar16,*(undefined4 *)(this[2] + 0x6c4));
        if (loopIndex2 == 0) goto code_r0x0018e934;
        uVar16 = IRInst__getOperandSource(inst,loopIndex4);
        loopIndex2 = FUN_0010c47c(uVar16,this[2]);
        if (loopIndex2 == 0) goto code_r0x0018e934;
        uVar16 = IRInst__getOperandSource(inst,loopIndex4);
        uVar16 = FUN_0010cb48(uVar16,this[2]);
        IRInst__setOperandSource(inst,loopIndex4,uVar16,0,this[2]);
      }
code_r0x0018eb5c: ;
    }
    if (!bVar2) {
      inst = piVar6;
    }
  }
  piVar6 = inst;
  if (((*(int *)(inst[0x22] + 8) == 0x9e) || (*(int *)(inst[0x22] + 8) == 0xa0)) &&
     ((loopIndex4 = FUN_000f31e8(inst,1), loopIndex4 == 0 ||
      (((inst[0x2e] & 1U) != 0 || ((inst[0x2e] & 2U) != 0)))))) {
    *(int *)(iVar17 + 0x238) = *(int *)(iVar17 + 0x238) + 1;
    piVar6 = (int *)IRInst__create(0x31,this[2]);
    piVar6[0x26] = 0;
    piVar6[0x25] = piVar6[0x53];
    loopIndex4 = IRInst__getOperandRecord(inst,0);
    uVar13 = *(undefined4 *)(loopIndex4 + 0x10);
    loopIndex4 = IRInst__getOperandRecord(piVar6,0);
    *(undefined4 *)(loopIndex4 + 0x10) = uVar13;
    uVar13 = IRInst__getOperandSource(inst,1);
    IRInst__setOperandSource(piVar6,1,uVar13,0,this[2]);
    IROperand__setModifierBits(piVar6 + 0x29,2,(uint)inst[0x2e] >> 1 & 1);
    IROperand__setModifierBits(piVar6 + 0x29,1,inst[0x2e] & 1);
    loopIndex4 = IRInst__getOperandRecord(inst,1);
    uVar13 = *(undefined4 *)(loopIndex4 + 0x10);
    loopIndex4 = IRInst__getOperandRecord(piVar6,1);
    *(undefined4 *)(loopIndex4 + 0x10) = uVar13;
    Block__insertInstBefore(iVar15,inst,piVar6);
    IRInst__setOperandSource(inst,1,piVar6,0,this[2]);
    IROperand__setModifierBits(inst + 0x29,2,0);
    IROperand__setModifierBits(inst + 0x29,1,0);
    loopIndex7 = DAT_001b2a64;
    loopIndex4 = IRInst__getOperandRecord(inst,1);
    loopIndex2 = 0;
    *(uint *)(loopIndex4 + 0x10) = loopIndex7;
    do {
      loopIndex4 = IRInst__getOperandRecord(inst,0);
      if (*(char *)(loopIndex2 + loopIndex4 + 0x10) == '\x01') {
        (**(code **)(*inst + 0x88))(inst,1,loopIndex2,4);
      }
      bVar2 = loopIndex2 != 3;
      loopIndex2 = loopIndex2 + 1;
    } while (bVar2);
    uVar13 = 1;
  }
  loopIndex2 = 1;
  loopIndex4 = (**(code **)(*this + 0x88))(this,piVar6);
  if (loopIndex4 == 0) {
    for (; loopIndex4 = (**(code **)(*piVar6 + 0x14))(piVar6), loopIndex2 <= loopIndex4; loopIndex2 = loopIndex2 + 1) {
      local_98 = 0;
      (**(code **)(*this + 0x68))(this,piVar6,loopIndex2,local_84,&local_98,this[2]);
      if (local_98 != 0) {
        if ((*(int *)(piVar6[0x22] + 8) == 0x31) || (*(int *)(piVar6[0x22] + 8) == 0x30)) {
          *(int *)(iVar17 + 0x238) = *(int *)(iVar17 + 0x238) + 1;
          loopIndex4 = IRInst__create(0x31,this[2]);
          FUN_00103f84(loopIndex4,piVar6);
          loopIndex7 = local_84[0];
          loopIndex5 = IRInst__getOperandRecord(loopIndex4,1);
          *(uint *)(loopIndex5 + 0x10) = loopIndex7;
          FUN_000f3258(&local_68,local_84[0]);
          *(undefined4 *)(loopIndex4 + 0x9c) = local_68;
          Block__insertInstBefore(iVar15,piVar6,loopIndex4);
          loopIndex5 = local_98 + -1;
          if (1 < loopIndex5) {
            loopIndex3 = 1;
            loopIndex6 = local_84;
            do {
              loopIndex6 = loopIndex6 + 1;
              loopIndex5 = IRInst__create(0x31,this[2]);
              FUN_00103f84(loopIndex5,piVar6);
              loopIndex7 = *loopIndex6;
              loopIndex = IRInst__getOperandRecord(loopIndex5,1);
              *(uint *)(loopIndex + 0x10) = loopIndex7;
              FUN_000f3258(&local_64,*loopIndex6);
              *(undefined4 *)(loopIndex5 + 0x9c) = local_64;
              Block__insertInstBefore(iVar15,piVar6,loopIndex5);
              if ((piVar6[5] & 2U) == 0) {
                IRInst__setExtraOperandSource(loopIndex5,loopIndex4,0,this[2]);
                loopIndex4 = loopIndex5;
              }
              loopIndex3 = loopIndex3 + 1;
              *(int *)(iVar17 + 0x238) = *(int *)(iVar17 + 0x238) + 1;
              loopIndex5 = local_98 + -1;
            } while (loopIndex3 < loopIndex5);
          }
          loopIndex7 = local_84[loopIndex5];
          loopIndex5 = IRInst__getOperandRecord(piVar6,1);
          *(uint *)(loopIndex5 + 0x10) = loopIndex7;
          FUN_000f3258(&local_60,(&local_88)[local_98]);
          piVar6[0x27] = local_60;
          if ((piVar6[5] & 2U) == 0) {
            IRInst__setExtraOperandSource(piVar6,loopIndex4,0,this[2]);
          }
        }
        else {
          piVar11 = (int *)IRInst__getOperandSource(piVar6,loopIndex2);
          loopIndex4 = 0;
          if (0 < local_98) {
            loopIndex3 = 0;
            loopIndex6 = local_84;
            loopIndex5 = loopIndex4;
            do {
              *(int *)(iVar17 + 0x238) = *(int *)(iVar17 + 0x238) + 1;
              loopIndex4 = IRInst__create(0x31,this[2]);
              *(undefined4 *)(loopIndex4 + 0x98) = 0;
              *(undefined4 *)(loopIndex4 + 0x94) = *(undefined4 *)(loopIndex4 + 0x14c);
              IRInst__setOperandSource(loopIndex4,1,piVar11,0,this[2]);
              loopIndex7 = *loopIndex6;
              loopIndex = IRInst__getOperandRecord(loopIndex4,1);
              *(uint *)(loopIndex + 0x10) = loopIndex7;
              FUN_000f3258(local_5c,*loopIndex6);
              *(undefined4 *)(loopIndex4 + 0x9c) = local_5c[0];
              if (loopIndex5 == 0) {
                if ((((piVar11[0x20] != 0) && (loopIndex5 = RegKind__flagBit0(piVar11[0x26]), loopIndex5 != 0)) &&
                    ((piVar11[5] & 2U) == 0)) &&
                   (loopIndex5 = (**(code **)(*piVar11 + 0x50))(piVar11), loopIndex5 == 0)) {
                  loopIndex = 4;
                  bVar2 = false;
                  loopIndex7 = 0;
                  loopIndex5 = loopIndex4;
                  do {
                    if (loopIndex7 == *(byte *)(loopIndex7 + (int)local_84)) {
                      *(undefined1 *)(loopIndex5 + 0x9c) = 1;
                      bVar2 = true;
                    }
                    loopIndex7 = loopIndex7 + 1;
                    loopIndex5 = loopIndex5 + 1;
                    loopIndex = loopIndex + -1;
                  } while (loopIndex != 0);
                  if (bVar2) {
                    IRInst__setExtraOperandSource(loopIndex4,piVar11,0,this[2]);
                  }
                }
              }
              else {
                IRInst__setExtraOperandSource(loopIndex4,loopIndex5,0,this[2]);
              }
              loopIndex5 = IRInst__getOperandRecord(loopIndex4,0);
              if (*(int *)(loopIndex5 + 0x10) == DAT_001b2a80) {
                loopIndex4 = IRInst__getOperandSource(loopIndex4,*(undefined4 *)(loopIndex4 + 0x84));
              }
              else {
                Block__insertInstBefore(iVar15,piVar6,loopIndex4);
              }
              loopIndex3 = loopIndex3 + 1;
              loopIndex6 = loopIndex6 + 1;
              loopIndex5 = loopIndex4;
            } while (loopIndex3 < local_98);
          }
          IRInst__setOperandSource(piVar6,loopIndex2,loopIndex4,0,this[2]);
        }
      }
    }
    uVar13 = 1;
  }
  iVar17 = 1;
  loopIndex4 = ((int (*)())FUN_0018da48)(piVar6,this[2]);
  if (loopIndex4 == 0) {
    for (; loopIndex4 = (**(code **)(*piVar6 + 0x14))(piVar6), iVar17 <= loopIndex4; iVar17 = iVar17 + 1) {
      piVar11 = (int *)IRInst__getOperandSource(piVar6,iVar17);
      loopIndex4 = (**(code **)(*piVar11 + 0x60))();
      if (loopIndex4 != 0) {
        piVar11 = (int *)IRInst__getOperandSource(piVar11,1);
      }
      loopIndex4 = (**(code **)(*piVar11 + 0x5c))(piVar11);
      if (loopIndex4 != 0) {
        uVar13 = IRInst__getOperandSource(piVar11,1);
        loopIndex4 = IRInst__getOperandRecord(piVar11,0);
        loopIndex2 = *(int *)(loopIndex4 + 0x10);
        loopIndex4 = IRInst__getOperandRecord(piVar11,1);
        uVar19 = *(undefined4 *)(loopIndex4 + 0x10);
        uVar16 = 0;
        loopIndex4 = (**(code **)(*piVar11 + 0x14))(piVar11);
        if (1 < loopIndex4) {
          uVar16 = IRInst__getOperandSource(piVar11,2);
          loopIndex4 = IRInst__getOperandRecord(piVar11,2);
          iVar15 = *(int *)(loopIndex4 + 0x10);
        }
        loopIndex4 = piVar11[1];
        loopIndex5 = *(int *)(piVar11[0x22] + 8);
        DList__unlink(piVar11);
        if (loopIndex5 != 0x99) {
          FUN_00108174(piVar11,0x12,this[2]);
        }
        else {
          FUN_00108304(piVar11,0x14,this[2]);
        }
        loopIndex = piVar11[0x53];
        loopIndex3 = IRInst__getOperandRecord(piVar11,0);
        *(undefined4 *)(loopIndex3 + 0xc) = 0;
        *(int *)(loopIndex3 + 8) = loopIndex;
        piVar11[0x27] = loopIndex2;
        IRInst__setOperandSource(piVar11,1,uVar13,0,this[2]);
        loopIndex2 = IRInst__getOperandRecord(piVar11,1);
        *(undefined4 *)(loopIndex2 + 0x10) = uVar19;
        if (loopIndex5 != 0x99) {
          if (loopIndex5 == 0x9c) {
            dVar22 = (double)FLOAT_001aa0e8;
            ((void (*)())FUN_000f79c4)(piVar11,*(undefined4 *)(this[2] + 0x6c4),2,dVar22,dVar22,dVar22,dVar22);
            IROperand__setModifierBits(piVar11 + 0x29,1,1);
          }
          else {
            IRInst__setOperandSource(piVar11,2,uVar16,0,this[2]);
            loopIndex2 = IRInst__getOperandRecord(piVar11,2);
            *(int *)(loopIndex2 + 0x10) = iVar15;
            IROperand__setModifierBits(piVar11 + 0x2f,1,(uint)(loopIndex5 == 0x9a));
          }
        }
        else {
          IROperand__setModifierBits(piVar11 + 0x29,1,1);
          dVar22 = (double)FLOAT_001aa0e8;
          ((void (*)())FUN_000f79c4)(piVar11,*(undefined4 *)(this[2] + 0x6c4),2,dVar22,dVar22,dVar22,dVar22);
          dVar22 = (double)FLOAT_001aa10c;
          ((void (*)())FUN_000f79c4)(piVar11,*(undefined4 *)(this[2] + 0x6c4),3,dVar22,dVar22,dVar22,dVar22);
          piVar11[0x49] = 1;
        }
        Block__insertInstAfter(*(undefined4 *)(loopIndex4 + 0x158),loopIndex4,piVar11);
        loopIndex4 = ((int (*)())FUN_0018da48)(piVar6,this[2]);
        if (loopIndex4 != 0) break;
      }
    }
    uVar13 = 1;
  }
  return uVar13;
}
#undef local_94
#undef local_90
#undef local_8c
#undef local_88

/* R520SchedModel__vslot4_addInstruction @ 0x18f42c (304 bytes) */
int R520SchedModel__vslot4_addInstruction(schedModel, inst)
  int schedModel;
  int *inst;
{
  int callResult;
  undefined4 uVar2;
  undefined4 local_38;
  undefined4 local_34;
  
  if ((inst[5] & 0x8000U) == 0) {
    callResult = (**(code **)(*inst + 0x28))(inst);
    if (callResult == 0) {
      ((int (*)())FUN_00189df4)(inst,schedModel + 0x18,schedModel + 0x20);
      ((int (*)())FUN_0018d4b4)(inst,schedModel + 0x1c,schedModel + 0x24,schedModel + 0x28,*(undefined4 *)(schedModel + 8)
                  );
      ((int (*)())PackState__countFreeSlots)(schedModel + 0x28,&local_38);
      uVar2 = 0;
      if (*(int *)(schedModel + 100) != 0) {
        ((int (*)())SchedModel__fitsConstantLimit)(schedModel,*(int *)(schedModel + 100),inst,local_38,local_34);
        uVar2 = *(undefined4 *)(schedModel + 100);
      }
      ((int (*)())SchedModel__assignConstantSelectors)(schedModel,uVar2,inst,local_38,local_34);
      if (*(int *)(schedModel + 100) == 0) {
        *(int **)(schedModel + 100) = inst;
      }
      if (*(int *)(schedModel + 0x18) < 0) {
        if (*(int *)(schedModel + 0x20) < 0) {
          *(undefined4 *)(schedModel + 4) = 0;
        }
        else {
          *(undefined4 *)(schedModel + 4) = 2;
        }
      }
      else if (*(int *)(schedModel + 0x20) < 0) {
        *(undefined4 *)(schedModel + 4) = 1;
      }
      else {
        *(undefined4 *)(schedModel + 4) = 3;
      }
    }
    else {
      *(undefined4 *)(schedModel + 4) = 4;
    }
  }
  return;
}

/* R520SchedModel__vslot3_canAddInstruction @ 0x18f55c (280 bytes) */
int R520SchedModel__vslot3_canAddInstruction(schedModel, inst)
  int schedModel;
  int *inst;
{
  int callResult;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined1 auStack_60 [80];
  
  if ((inst[5] & 0x8000U) == 0) {
    callResult = (**(code **)(*inst + 0x28))(inst);
    if (callResult != 0) {
      return *(int *)(schedModel + 4) == 0;
    }
    local_78 = *(undefined4 *)(schedModel + 0x18);
    local_74 = *(undefined4 *)(schedModel + 0x1c);
    local_70 = *(undefined4 *)(schedModel + 0x20);
    local_6c = *(undefined4 *)(schedModel + 0x24);
    ((int (*)())PackState__copy)(auStack_60,schedModel + 0x28);
    callResult = ((int (*)())FUN_00189df4)(inst,&local_78,&local_70);
    if ((((callResult == 0) ||
         (callResult = ((int (*)())FUN_0018d4b4)(inst,&local_74,&local_6c,auStack_60,*(undefined4 *)(schedModel + 8)),
         callResult == 0)) || (callResult = ((int (*)())PackState__countFreeSlots)(auStack_60,&local_68), callResult == 0)) ||
       ((*(int *)(schedModel + 100) != 0 &&
        (callResult = ((int (*)())SchedModel__fitsConstantLimit)(schedModel,*(int *)(schedModel + 100),inst,local_68,local_64), callResult == 0
        )))) {
      return false;
    }
  }
  return true;
}

/* R300SchedModel__vslot12 @ 0x18f674 (432 bytes) */
int R300SchedModel__vslot12(this, inst)
  int this;
  int *inst;
{
  uint uVar1;
  int callResult;
  int operandRecord;
  
  if (((((((inst[0x20] != 0) && (callResult = RegKind__flagBit0(inst[0x26]), callResult != 0)) &&
         ((inst[5] & 2U) == 0)) &&
        ((callResult = (**(code **)(*inst + 0x50))(inst), callResult == 0 &&
         (uVar1 = inst[5], (uVar1 & 0x20) == 0)))) &&
       (((uVar1 & 0x40) == 0 &&
        (((uVar1 & 2) == 0 && (callResult = (**(code **)(*inst + 0x5c))(inst), callResult == 0)))))) &&
      (callResult = (**(code **)(*inst + 0x28))(inst), callResult == 0)) &&
     ((((callResult = *(int *)(inst[0x22] + 8), callResult != 0x9e && (callResult != 0xa0)) && (callResult != 0x9f))
      && (((callResult != 0xa1 && (callResult = *(int *)(PTR_DAT_001e913c + callResult * 0x38 + 0x34), callResult != 3))
          && (callResult != 8)))))) {
    operandRecord = IRInst__getOperandRecord(inst,0);
    if (*(char *)(operandRecord + 0x13) == '\0') {
      if ((callResult != 5) &&
         ((callResult != 0 ||
          ((callResult = FUN_000f3a30(inst), callResult != 4 &&
           ((callResult < 2 || ((*(uint *)(*(int *)(*(int *)(this + 8) + 0x30c) + 8) & 0x400) != 0))))
          )))) {
        return 1;
      }
    }
    else if ((*(char *)(operandRecord + 0x13) == '\x01') && (1 < callResult - 1U)) {
      if (callResult == 5) {
        return 1;
      }
      callResult = FUN_000f3a30(inst);
      if (callResult < 2) {
        return 1;
      }
    }
  }
  return 0;
}

/* R300VSchedModel__vslot2_reset @ 0x18f824 (44 bytes) */
int R300VSchedModel__vslot2_reset(param_1)
  int param_1;
{
  *(undefined4 *)(param_1 + 0x34) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x28) = 4;
  *(undefined4 *)(param_1 + 0x18) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x1c) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x20) = 4;
  *(undefined4 *)(param_1 + 0x24) = 4;
  *(undefined4 *)(param_1 + 0x2c) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x30) = 0xffffffff;
  return;
}

/* FUN_0018f850 @ 0x18f850 (200 bytes) */
int FUN_0018f850(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  int *param_2;
  int *param_3;
  int param_4;
{
  bool bVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = param_2[1];
  if (*param_2 == iVar2) {
    iVar3 = *param_3;
    bVar1 = iVar3 != param_3[1];
    if ((bVar1) && (iVar2 != 0)) {
      return 0;
    }
    if (iVar2 == param_2[2]) {
      if (iVar2 == 0) {
        if ((((param_4 == 0) && (bVar1)) && (iVar3 != param_3[2])) && (param_3[1] != param_3[2])) {
          return 0;
        }
      }
      else {
        if (bVar1) {
          return 0;
        }
        if (iVar3 != param_3[2]) {
          return 0;
        }
      }
    }
  }
  else {
    iVar3 = param_2[2];
    if (*param_2 == iVar3) {
      if (*param_3 == param_3[2]) {
        return 1;
      }
    }
    else {
      if (iVar2 != iVar3) {
        return 1;
      }
      iVar3 = iVar2;
      if (param_3[1] == param_3[2]) {
        return 1;
      }
    }
    if (iVar3 != 0) {
      return 0;
    }
  }
  return 1;
}

/* R300VSchedModel__vslot13 @ 0x18f918 (108 bytes) */
int R300VSchedModel__vslot13(this, param_2)
  int *this;
  int param_2;
{
  int callResult;
  undefined4 uVar2;
  
  callResult = (**(code **)(*this + 0x30))(this,*(undefined4 *)(param_2 + 0x38));
  if ((callResult == 0) ||
     ((*(int *)(param_2 + 0x60) != 0 && (*(int *)(*(int *)(param_2 + 0x60) + 8) != 0)))) {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}

/* R300VSchedModel__vslot28 @ 0x18f984 (596 bytes) */
int R300VSchedModel__vslot28(this, param_2, param_3, param_4, param_5, param_6, param_7)
  int *this;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  int *operandVReg;
  bool bVar1;
  int iVar2;
  int loopIndex;
  int *piVar4;
  int *piVar5;
  int operandRecord;
  uint uVar7;
  uint uVar8;
  int iVar9;
  
  iVar9 = *(int *)(param_2 + 900);
  iVar2 = *(int *)(iVar9 + 8);
  do {
    if (iVar2 == 0) {
      return;
    }
    iVar2 = *(int *)(iVar9 + 0x98);
    for (loopIndex = *(int *)(*(int *)(iVar9 + 0x98) + 8); loopIndex != 0; loopIndex = *(int *)(loopIndex + 8)) {
      if ((*(uint *)(iVar2 + 0x14) & 1) != 0) {
        loopIndex = *(int *)(iVar2 + 0x88);
        if (*(int *)(loopIndex + 8) != 0x8e) {
          (**(code **)(*this + 0x6c))(this,iVar2);
          loopIndex = *(int *)(iVar2 + 0x88);
        }
        if ((*(int *)(loopIndex + 8) == 0x31) || (*(int *)(loopIndex + 8) == 0x30)) {
          operandVReg = (int *)IRInst__getOperandSource(iVar2,1);
          loopIndex = (**(code **)(*operandVReg + 0x50))(operandVReg);
          if (loopIndex != 0) {
            loopIndex = *(int *)(iVar2 + 8);
            *(undefined4 *)(iVar2 + 0x9c) = 0x1010101;
            goto LAB_0018fa5c;
          }
        }
        loopIndex = *(int *)(iVar2 + 8);
      }
LAB_0018fa5c:
      iVar2 = loopIndex;
    }
    piVar5 = *(int **)(iVar9 + 0xa0);
    for (piVar4 = (int *)(*(int **)(iVar9 + 0xa0))[1]; piVar4 != (int *)0x0;
        piVar4 = (int *)piVar4[1]) {
      if ((piVar5[5] & 1U) != 0) {
        iVar2 = piVar5[0x22];
        if ((*(int *)(iVar2 + 8) == 0x31) || (*(int *)(iVar2 + 8) == 0x13)) {
          iVar2 = (**(code **)(*this + 0x30))(this,piVar5);
          if (iVar2 == 0) {
            iVar2 = piVar5[0x22];
          }
          else {
            uVar8 = 0xffffffff;
            uVar7 = 0xffffffff;
            loopIndex = 0;
            iVar2 = (**(code **)(*piVar5 + 0x14))(piVar5);
            do {
              operandRecord = IRInst__getOperandRecord(piVar5,0);
              if (*(char *)(loopIndex + operandRecord + 0x10) != '\x01') {
                operandRecord = IRInst__getOperandRecord(piVar5,1);
                uVar8 = (uint)*(byte *)(loopIndex + operandRecord + 0x10);
                if (iVar2 == 2) {
                  operandRecord = IRInst__getOperandRecord(piVar5,2);
                  uVar7 = (uint)*(byte *)(loopIndex + operandRecord + 0x10);
                }
              }
              bVar1 = loopIndex != 3;
              loopIndex = loopIndex + 1;
            } while (bVar1);
            FUN_0010bb9c(piVar5,uVar8,uVar7,0,0,this[2]);
            iVar2 = piVar5[0x22];
          }
        }
        iVar2 = OpcodeTraits__flagBit2(*(undefined4 *)(iVar2 + 8),this[2]);
        if ((iVar2 == 0) || (piVar5[0x26] != 0)) {
          piVar4 = (int *)piVar5[1];
        }
        else {
          piVar4 = (int *)piVar5[1];
          piVar5[0x26] = 1;
        }
      }
      piVar5 = piVar4;
    }
    iVar9 = *(int *)(iVar9 + 8);
    iVar2 = *(int *)(iVar9 + 8);
  } while( true );
}

/* R300VSchedModel__vslot14 @ 0x18fbd8 (348 bytes) */
int R300VSchedModel__vslot14(this, param_2)
  int *this;
  int param_2;
{
  bool bVar1;
  int iVar2;
  int operandRecord;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  int loopIndex;
  int *piVar8;
  
  (**(code **)(*this + 0x34))(this,param_2);
  piVar8 = *(int **)(param_2 + 0x38);
  iVar2 = *(int *)(piVar8[0x22] + 8);
  if ((iVar2 == 0x66) || (iVar2 == 0x36)) {
    FUN_0010bc78(piVar8,this[2]);
    piVar8[0x26] = 0;
  }
  else if ((iVar2 == 0x31) || (*(int *)(piVar8[0x22] + 8) == 0x13)) {
    uVar6 = 0xffffffff;
    uVar5 = 0xffffffff;
    loopIndex = 0;
    iVar2 = (**(code **)(*piVar8 + 0x14))(piVar8);
    do {
      operandRecord = IRInst__getOperandRecord(piVar8,0);
      if (*(char *)(loopIndex + operandRecord + 0x10) != '\x01') {
        operandRecord = IRInst__getOperandRecord(piVar8,1);
        uVar6 = (uint)*(byte *)(loopIndex + operandRecord + 0x10);
        if (iVar2 == 2) {
          operandRecord = IRInst__getOperandRecord(piVar8,2);
          uVar5 = (uint)*(byte *)(loopIndex + operandRecord + 0x10);
        }
      }
      bVar1 = loopIndex != 3;
      loopIndex = loopIndex + 1;
    } while (bVar1);
    FUN_0010bb9c(piVar8,uVar6,uVar5,0,0,this[2]);
    piVar8[0x26] = 1;
  }
  uVar4 = (**(code **)(*this + 0x4c))(this,piVar8);
  *(undefined4 *)(param_2 + 0x58) = uVar4;
  return;
}

/* R300VSchedModel__vslot17 @ 0x18fd34 (972 bytes) */
int R300VSchedModel__vslot17(this, param_2)
  int *this;
  int param_2;
{
  bool bVar1;
  bool bVar2;
  undefined1 uVar3;
  uint uVar4;
  int iVar5;
  int loopIndex2;
  int iVar7;
  uint uVar8;
  int *piVar9;
  int *operandVReg;
  int operandRecord;
  undefined4 uVar12;
  int iVar13;
  uint loopIndex3;
  int loopIndex;
  uint *puVar16;
  int *piVar17;
  
  piVar17 = *(int **)(param_2 + 0x38);
  if (((((*(int *)(param_2 + 0x60) == 0) && (piVar17[0x20] != 0)) &&
       (iVar5 = RegKind__flagBit0(piVar17[0x26]), iVar5 != 0)) &&
      (((piVar17[5] & 2U) == 0 && (iVar5 = (**(code **)(*piVar17 + 0x50))(piVar17), iVar5 == 0))))
     && ((uVar4 = piVar17[5], (uVar4 & 0x20) == 0 && (((uVar4 & 0x40) == 0 && ((uVar4 & 2) == 0)))))
     ) {
    iVar5 = *(int *)(PTR_DAT_001e9140 + *(int *)(piVar17[0x22] + 8) * 0x38 + 0x34);
    if ((iVar5 == 0) ||
       ((((iVar5 == 5 || (iVar5 == 1)) || (iVar5 == 2)) || ((iVar5 == 3 || (iVar5 == 8)))))) {
      bVar2 = false;
      loopIndex = 0;
      iVar13 = -1;
      do {
        loopIndex2 = IRInst__getOperandRecord(piVar17,0);
        iVar7 = iVar13;
        if ((*(char *)(loopIndex + loopIndex2 + 0x10) == '\0') && (iVar7 = loopIndex, -1 < iVar13)) {
          iVar7 = OpcodeTraits__flagBit2(*(undefined4 *)(piVar17[0x22] + 8),this[2]);
          if (iVar7 == 0) {
            return;
          }
          bVar2 = true;
          iVar7 = iVar13;
        }
        bVar1 = loopIndex != 3;
        loopIndex = loopIndex + 1;
        iVar13 = iVar7;
      } while (bVar1);
      iVar13 = this[0xe];
      this[0xe] = iVar13 + 1;
      if (3 < iVar13 + 1) {
        this[0xe] = 0;
      }
      if ((iVar13 != iVar7) || (bVar2)) {
        loopIndex2 = 4;
        loopIndex = param_2;
        do {
          *(undefined4 *)(loopIndex + 0x48) = 0;
          loopIndex = loopIndex + 4;
          loopIndex2 = loopIndex2 + -1;
        } while (loopIndex2 != 0);
        puVar16 = *(uint **)(param_2 + 0x40);
        loopIndex3 = 0;
        uVar4 = puVar16[1];
        if (0 < (int)uVar4) {
          while( true ) {
            if (loopIndex3 < *puVar16) {
              uVar8 = puVar16[1];
              if (uVar8 <= loopIndex3) {
                _memset(uVar8 * 4 + puVar16[2],0,(loopIndex3 - uVar8) * 4 + 4);
                puVar16[1] = loopIndex3 + 1;
              }
              piVar9 = (int *)(loopIndex3 * 4 + puVar16[2]);
            }
            else {
              piVar9 = (int *)Vector__elementRefGrow(puVar16,loopIndex3);
            }
            loopIndex3 = loopIndex3 + 1;
            loopIndex = *piVar9;
            if (*(int *)(loopIndex + 8) == 0) {
              *(undefined4 *)(loopIndex + 0x18) = 0;
              *(undefined1 *)(iVar13 + loopIndex + 0x18) = 1;
              loopIndex2 = iVar13 * 4 + param_2;
              *(int *)(loopIndex2 + 0x48) = *(int *)(loopIndex2 + 0x48) + 1;
              piVar9 = *(int **)(*(int *)(loopIndex + 4) + 0x38);
              for (loopIndex = 1; loopIndex2 = (**(code **)(*piVar9 + 0x14))(piVar9), loopIndex <= loopIndex2;
                  loopIndex = loopIndex + 1) {
                operandVReg = (int *)IRInst__getOperandSource(piVar9,loopIndex);
                if (piVar17 == operandVReg) {
                  loopIndex2 = 0;
                  do {
                    operandRecord = IRInst__getOperandRecord(piVar9,loopIndex);
                    if (*(char *)(loopIndex2 + operandRecord + 0x10) != '\x04') {
                      (**(code **)(*piVar9 + 0x88))(piVar9,loopIndex,loopIndex2,iVar13);
                    }
                    bVar2 = loopIndex2 != 3;
                    loopIndex2 = loopIndex2 + 1;
                  } while (bVar2);
                }
              }
            }
            if (uVar4 == loopIndex3) break;
            puVar16 = *(uint **)(param_2 + 0x40);
          }
        }
        piVar17[0x27] = DAT_001b2a84;
        *(undefined1 *)((int)piVar17 + iVar13 + 0x9c) = 0;
        piVar17[3] = 0;
        *(undefined1 *)((int)piVar17 + iVar13 + 0xc) = 1;
        if (iVar5 == 0) {
          for (iVar5 = 1; iVar13 = (**(code **)(*piVar17 + 0x14))(piVar17), iVar5 <= iVar13;
              iVar5 = iVar5 + 1) {
            iVar13 = IRInst__getOperandRecord(piVar17,iVar5);
            loopIndex = 0;
            uVar3 = *(undefined1 *)(iVar7 + iVar13 + 0x10);
            do {
              (**(code **)(*piVar17 + 0x88))(piVar17,iVar5,loopIndex,uVar3);
              bVar2 = loopIndex != 3;
              loopIndex = loopIndex + 1;
            } while (bVar2);
          }
        }
        uVar12 = (**(code **)(*this + 0x4c))(this,piVar17);
        *(undefined4 *)(param_2 + 0x58) = uVar12;
      }
    }
  }
  return;
}

/* FUN_00190100 @ 0x190100 (728 bytes) */
int FUN_00190100(param_1, inst, param_3, param_4, param_5)
  undefined4 param_1;
  undefined4 inst;
  undefined4 param_3;
  undefined4 *param_4;
  int *param_5;
{
  int *a0;
  int callResult;
  undefined4 uVar2;
  int iVar3;
  
  a0 = (int *)IRInst__getOperandSource(inst,param_3);
  callResult = (**(code **)(*a0 + 0x60))(a0);
  if (callResult != 0) {
    a0 = (int *)IRInst__getOperandSource(a0,1);
  }
  switch(a0[0x26]) {
  case 0:
    if ((a0[5] & 0x40U) == 0) {
      *param_5 = a0[0x25] + 0x80;
    }
    else {
      *param_5 = a0[0x25];
    }
    uVar2 = 1;
    *param_4 = 0;
    break;
  case 1:
    if ((a0[5] & 0x40U) == 0) {
      *param_5 = a0[0x25] + 0x80;
    }
    else {
      *param_5 = a0[0x25];
    }
    uVar2 = 1;
    *param_4 = 3;
    break;
  case 2:
    uVar2 = 1;
    *param_5 = a0[0x25];
    *param_4 = 2;
    break;
  default:
    uVar2 = 0;
    break;
  case 0xc:
    uVar2 = 1;
    *param_5 = a0[0x25] + 0x700;
    *param_4 = 2;
    break;
  case 0x26:
    callResult = IRInst__getOperandSource(a0,1);
    *param_5 = *(int *)(callResult + 0x14c) << 10;
    callResult = IRInst__getOperandRecord(a0,1);
    callResult = FUN_000f2d18(*(undefined4 *)(callResult + 0x10),0);
    if (callResult == 0) {
      callResult = IRInst__getOperandRecord(a0,1);
      callResult = FUN_000f2d18(*(undefined4 *)(callResult + 0x10),0x1010101);
      if (callResult == 0) {
        callResult = IRInst__getOperandRecord(a0,1);
        callResult = FUN_000f2d18(*(undefined4 *)(callResult + 0x10),0x2020202);
        if (callResult == 0) {
          callResult = IRInst__getOperandRecord(a0,1);
          callResult = FUN_000f2d18(*(undefined4 *)(callResult + 0x10),0x3030303);
          if (callResult != 0) {
            iVar3 = *param_5;
            callResult = FUN_00105c5c(a0,0);
            *param_5 = iVar3 + callResult + 0x400;
          }
        }
        else {
          iVar3 = *param_5;
          callResult = FUN_00105c5c(a0,0);
          *param_5 = iVar3 + callResult + 0x300;
        }
      }
      else {
        iVar3 = *param_5;
        callResult = FUN_00105c5c(a0,0);
        *param_5 = iVar3 + callResult + 0x200;
      }
    }
    else {
      iVar3 = *param_5;
      callResult = FUN_00105c5c(a0,0);
      *param_5 = iVar3 + callResult + 0x100;
    }
    uVar2 = 1;
    *param_4 = 2;
    break;
  case 0x28:
    callResult = FUN_00105c5c(inst,param_3);
    uVar2 = 1;
    *param_5 = callResult + 0x500;
    *param_4 = 2;
    break;
  case 0x29:
    callResult = FUN_00105c5c(inst,param_3);
    uVar2 = 1;
    *param_5 = callResult + 0x600;
    *param_4 = 1;
    break;
  case 0x37:
    uVar2 = 1;
    *param_5 = a0[0x25];
    *param_4 = 1;
  }
  return uVar2;
}

/* R300VSchedModel__vslot4_addInstruction @ 0x1904b8 (528 bytes) */
int R300VSchedModel__vslot4_addInstruction(param_1, param_2)
  int *param_1;
  int *param_2;
{
  int callResult;
  undefined4 uVar2;
  int *piVar3;
  int *piVar4;
  
  callResult = (**(code **)(*param_1 + 0x4c))(param_1,param_2);
  if (callResult == 0) {
    return;
  }
  if (callResult == 3) {
    param_1[7] = *(int *)(param_2[0x22] + 8);
    param_1[6] = *(int *)(param_2[0x22] + 8);
    callResult = (**(code **)(*param_2 + 0x14))(param_2);
    if (callResult < 1) {
      return;
    }
    ((int (*)())FUN_00190100)(param_1,param_2,1,param_1 + 8,param_1 + 0xb);
    callResult = (**(code **)(*param_2 + 0x14))(param_2);
    if (callResult < 2) {
      return;
    }
    ((int (*)())FUN_00190100)(param_1,param_2,2,param_1 + 9,param_1 + 0xc);
    callResult = (**(code **)(*param_2 + 0x14))(param_2);
    if (callResult < 3) {
      return;
    }
    uVar2 = 3;
  }
  else {
    if (callResult != 2) {
      param_1[6] = *(int *)(param_2[0x22] + 8);
      if (param_2[0x26] == 1) {
        param_1[7] = *(int *)(param_2[0x22] + 8);
      }
      callResult = (**(code **)(*param_2 + 0x14))(param_2);
      if (callResult < 1) {
        return;
      }
      ((int (*)())FUN_00190100)(param_1,param_2,1,param_1 + 8,param_1 + 0xb);
      callResult = (**(code **)(*param_2 + 0x14))(param_2);
      if (callResult < 2) {
        return;
      }
      uVar2 = 2;
      piVar3 = param_1 + 9;
      piVar4 = param_1 + 0xc;
      goto LAB_0019060c;
    }
    param_1[7] = *(int *)(param_2[0x22] + 8);
    if (param_2[0x26] != 1) {
      param_1[6] = *(int *)(param_2[0x22] + 8);
    }
    callResult = (**(code **)(*param_2 + 0x14))(param_2);
    if (callResult < 1) {
      return;
    }
    uVar2 = 1;
  }
  piVar3 = param_1 + 10;
  piVar4 = param_1 + 0xd;
LAB_0019060c:
  ((int (*)())FUN_00190100)(param_1,param_2,uVar2,piVar3,piVar4);
  return;
}

/* R300VSchedModel__vslot3_canAddInstruction @ 0x1906c8 (712 bytes) */
int R300VSchedModel__vslot3_canAddInstruction(param_1, param_2)
  int *param_1;
  int *param_2;
{
  int callResult;
  undefined4 uVar2;
  undefined4 in_r5;
  undefined4 in_r6;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24 [5];
  
  local_38 = param_1[8];
  local_34 = param_1[9];
  local_30 = param_1[10];
  local_2c = param_1[0xb];
  local_28 = param_1[0xc];
  local_24[0] = param_1[0xd];
  callResult = (**(code **)(*param_1 + 0x4c))
                    (param_1,param_2,in_r5,in_r6,*param_1,local_24[0],local_30,local_28);
  if (callResult == 0) {
LAB_0019092c:
    uVar2 = 1;
  }
  else {
    if (callResult == 3) {
      if ((param_1[7] < 0) && (param_1[6] < 0)) {
        callResult = (**(code **)(*param_2 + 0x14))(param_2);
        if (0 < callResult) {
          ((int (*)())FUN_00190100)(param_1,param_2,1,&local_38,&local_2c);
          callResult = (**(code **)(*param_2 + 0x14))(param_2);
          if (1 < callResult) {
            ((int (*)())FUN_00190100)(param_1,param_2,2,&local_34,&local_28);
            callResult = (**(code **)(*param_2 + 0x14))(param_2);
            if (2 < callResult) {
              ((int (*)())FUN_00190100)(param_1,param_2,3,&local_30,local_24);
            }
          }
          callResult = ((int (*)())FUN_0018f850)(param_1,&local_38,&local_2c,
                               (uint)(*(int *)(param_2[0x22] + 8) == 0x14));
          goto joined_r0x00190928;
        }
        goto LAB_0019092c;
      }
    }
    else if (callResult == 2) {
      if ((param_1[7] < 0) && ((param_1[6] < 0 || (param_2[0x26] == 1)))) {
        callResult = (**(code **)(*param_2 + 0x14))(param_2);
        if (0 < callResult) {
          ((int (*)())FUN_00190100)(param_1,param_2,1,&local_30,local_24);
          callResult = ((int (*)())FUN_0018f850)(param_1,&local_38,&local_2c,0);
joined_r0x00190928:
          if (callResult == 0) goto LAB_00190854;
        }
        goto LAB_0019092c;
      }
    }
    else if ((param_1[6] < 0) && ((param_1[7] < 0 || (param_2[0x26] != 1)))) {
      callResult = (**(code **)(*param_2 + 0x14))(param_2);
      if (0 < callResult) {
        ((int (*)())FUN_00190100)(param_1,param_2,1,&local_38,&local_2c);
        callResult = (**(code **)(*param_2 + 0x14))(param_2);
        if (1 < callResult) {
          ((int (*)())FUN_00190100)(param_1,param_2,2,&local_34,&local_28);
        }
        callResult = ((int (*)())FUN_0018f850)(param_1,&local_38,&local_2c,0);
        goto joined_r0x00190928;
      }
      goto LAB_0019092c;
    }
LAB_00190854:
    uVar2 = 0;
  }
  return uVar2;
}

/* R300VSchedModel__vslot27 @ 0x190990 (1256 bytes) */
int R300VSchedModel__vslot27(this, inst)
  int this;
  int *inst;
{
  void *operandVReg;
  int *piVar1;
  int iVar2;
  uint callResult2;
  undefined4 uVar4;
  void *callResult;
  void *inst2;
  void *inst3;
  int iVar8;
  int iVar9;
  int iVar10;
  undefined4 in_r5;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  int iVar11;
  int iVar12;
  undefined4 uVar13;
  int iVar14;
  int loopIndex;
  int iVar16;
  int local_a8;
  int local_a4;
  int local_a0;
  int local_9c;
  uint local_98;
  uint local_94;
  uint local_84;
  uint local_80;
  uint local_7c;
  uint local_6c;
  undefined4 local_68;
  undefined4 local_64;
  int local_60;
  undefined4 local_5c;
  uint local_58;
  undefined4 local_54;
  uint local_50;
  undefined4 local_4c [6];
  
  uVar13 = 0;
  iVar11 = *(int *)(this + 8);
  iVar14 = inst[0x56];
  iVar12 = *(int *)(iVar11 + 0x6c4);
  (**(code **)(**(int **)(iVar11 + 0x30c) + 0x80))
            (*(int **)(iVar11 + 0x30c),inst,in_r5,in_r6,in_r7,in_r8,iVar11);
  piVar1 = *(int **)(*(int *)(this + 8) + 0x30c);
  iVar11 = (**(code **)(*piVar1 + 0x88))(piVar1);
  if (iVar11 == 0) {
    piVar1 = inst + 0x26;
    for (iVar11 = 1; iVar2 = (**(code **)(*inst + 0x14))(inst), iVar11 <= iVar2;
        iVar11 = iVar11 + 1) {
      if ((piVar1[8] & 2U) != 0) {
        iVar2 = OpcodeTraits__flagBit10(*(undefined4 *)(inst[0x22] + 8),*(undefined4 *)(this + 8));
        if (iVar2 == 0) {
          uVar4 = IRInst__getOperandSource(inst,iVar11);
          callResult = IRInst__create(0x17,*(undefined4 *)(this + 8));
          *(undefined4 *)((int)callResult + 0x98) = 0;
          *(undefined4 *)((int)callResult + 0x94) = *(undefined4 *)((int)callResult + 0x14c);
          iVar2 = IRInst__getOperandRecord(inst,iVar11);
          FUN_000f3398(&local_68,*(undefined4 *)(iVar2 + 0x10));
          uVar13 = local_68;
          FUN_000f31f8(&local_64,0,local_68);
          *(undefined4 *)((int)callResult + 0xc) = uVar13;
          *(undefined4 *)((int)callResult + 0x9c) = local_64;
          IROperand__setModifierBits((int)callResult + 0xa4,1,0);
          IROperand__setModifierBits((int)callResult + 0xbc,1,1);
          IRInst__setOperandSource(callResult,1,uVar4,0,*(undefined4 *)(this + 8));
          IRInst__setOperandSource(callResult,2,uVar4,0,*(undefined4 *)(this + 8));
          iVar2 = FUN_00165604(iVar14,callResult);
          if (*(int *)(iVar2 + 0x158) == 0) {
            *(int *)(iVar12 + 0x238) = *(int *)(iVar12 + 0x238) + 1;
            Block__insertInstBefore(iVar14,inst,iVar2);
          }
          IRInst__setOperandSource(inst,iVar11,iVar2,0,*(undefined4 *)(this + 8));
        }
        uVar13 = 1;
        IROperand__setModifierBits(piVar1 + 3,2,0);
      }
      piVar1 = piVar1 + 6;
    }
  }
  piVar1 = *(int **)(*(int *)(this + 8) + 0x30c);
  callResult2 = (**(code **)(*piVar1 + 0x84))(piVar1);
  if ((callResult2 == 0) && (*(int *)(inst[0x22] + 8) == 0x25)) {
    local_98 = callResult2;
    local_94 = callResult2;
    local_84 = callResult2;
    local_80 = callResult2;
    local_7c = callResult2;
    local_6c = callResult2;
    uVar4 = IRInst__getOperandRecord(inst,2);
    FUN_00104730(&local_80,uVar4);
    uVar4 = IRInst__getOperandRecord(inst,3);
    FUN_00104730(&local_98,uVar4);
    callResult = IRInst__create(0x29,*(undefined4 *)(this + 8));
    *(undefined4 *)((int)callResult + 0x98) = 0;
    *(undefined4 *)((int)callResult + 0x94) = *(undefined4 *)((int)callResult + 0x14c);
    iVar11 = IRInst__getOperandRecord(inst,1);
    FUN_000f3398(&local_60,*(undefined4 *)(iVar11 + 0x10));
    FUN_000f31f8(&local_5c,0,local_60);
    *(undefined4 *)((int)callResult + 0x9c) = local_5c;
    *(int *)((int)callResult + 0xc) = local_60;
    FUN_00105e54(callResult,1,inst,1);
    ((void (*)())FUN_000f79c4)(callResult,iVar12,2,0.0,0.0,0.0,0.0);
    *(int *)((int)callResult + 0x160) = *(int *)(iVar12 + 0x478) + 2;
    Block__insertInstBefore(iVar14,inst,callResult);
    inst2 = IRInst__create(0x12,*(undefined4 *)(this + 8));
    *(undefined4 *)((int)inst2 + 0x98) = 0;
    *(undefined4 *)((int)inst2 + 0x94) = *(undefined4 *)((int)inst2 + 0x14c);
    iVar11 = IRInst__getOperandRecord(callResult,0);
    uVar4 = *(undefined4 *)(iVar11 + 0x10);
    *(int *)((int)inst2 + 0xc) = local_60;
    *(undefined4 *)((int)inst2 + 0x9c) = uVar4;
    IRInst__setOperandSource(inst2,1,callResult,0,*(undefined4 *)(this + 8));
    IROperand__setModifierBits((int)inst2 + 0xa4,1,1);
    ((void (*)())FUN_000f79c4)(inst2,iVar12,2,1.0,1.0,1.0,1.0);
    *(int *)((int)inst2 + 0x160) = *(int *)(iVar12 + 0x478) + 1;
    Block__insertInstBefore(iVar14,inst,inst2);
    inst3 = IRInst__create(0x13,*(undefined4 *)(this + 8));
    *(undefined4 *)((int)inst3 + 0x98) = 0;
    *(undefined4 *)((int)inst3 + 0x94) = *(undefined4 *)((int)inst3 + 0x14c);
    iVar11 = IRInst__getOperandRecord(callResult,0);
    uVar4 = *(undefined4 *)(iVar11 + 0x10);
    *(int *)((int)inst3 + 0xc) = local_60;
    *(undefined4 *)((int)inst3 + 0x9c) = uVar4;
    IRInst__setOperandSource(inst3,1,callResult,0,*(undefined4 *)(this + 8));
    uVar4 = IRInst__getOperandRecord(inst3,2);
    FUN_00104730(uVar4,&local_80);
    *(int *)((int)inst3 + 0x160) = *(int *)(iVar12 + 0x478) + 1;
    Block__insertInstBefore(iVar14,inst,inst3);
    iVar11 = inst[0x58] - *(int *)(iVar12 + 0x478);
    if (iVar11 < 0) {
      iVar11 = 0;
    }
    DList__unlink(inst);
    FUN_00108304(inst,0x14,*(undefined4 *)(iVar12 + 8));
    inst[0x26] = 0;
    inst[0x25] = inst[0x53];
    iVar2 = IRInst__getOperandRecord(callResult,0);
    iVar2 = *(int *)(iVar2 + 0x10);
    inst[3] = local_60;
    inst[0x27] = iVar2;
    IRInst__setOperandSource(inst,1,inst2,0,*(undefined4 *)(this + 8));
    uVar4 = IRInst__getOperandRecord(inst,2);
    FUN_00104730(uVar4,&local_98);
    IRInst__setOperandSource(inst,3,inst3,0,*(undefined4 *)(this + 8));
    inst[0x58] = iVar11 + *(int *)(iVar12 + 0x478);
    Block__insertInstAfter(iVar14,inst3,inst);
  }
  loopIndex = 1;
  iVar11 = -1;
  iVar2 = -1;
  do {
    iVar10 = (**(code **)(*inst + 0x14))(inst);
    if (iVar10 < loopIndex) {
      return uVar13;
    }
    uVar4 = IRInst__getOperandSource(inst,loopIndex);
    iVar8 = ((int (*)())FUN_00190100)(this,inst,loopIndex,&local_a8,&local_a4);
    iVar10 = iVar11;
    iVar16 = iVar2;
    if (iVar8 != 0) {
      if (local_a8 == 2) {
        iVar16 = local_a4;
        if ((iVar2 < 0) || (iVar2 == local_a4)) goto code_r0x0019125c;
        callResult = IRInst__create(0x31,*(undefined4 *)(this + 8));
        *(undefined4 *)((int)callResult + 0x98) = 0;
        *(undefined4 *)((int)callResult + 0x94) = *(undefined4 *)((int)callResult + 0x14c);
        IRInst__setOperandSource(callResult,1,uVar4,0,*(undefined4 *)(this + 8));
        local_98 = 0;
        for (iVar16 = 1; iVar8 = (**(code **)(*inst + 0x14))(inst), iVar16 <= iVar8;
            iVar16 = iVar16 + 1) {
          iVar8 = ((int (*)())FUN_00190100)(this,inst,iVar16,&local_a0,&local_9c);
          if (((iVar8 != 0) && (local_a0 == local_a8)) && (local_9c == local_a4)) {
            iVar8 = IRInst__getOperandRecord(inst,iVar16);
            FUN_000f3398(&local_58,*(undefined4 *)(iVar8 + 0x10));
            local_98 = local_58 | local_98;
            IRInst__setOperandSource(inst,iVar16,callResult,0,*(undefined4 *)(this + 8));
          }
        }
        iVar8 = 1;
        FUN_000f31f8(&local_54,0,local_98);
        *(undefined4 *)((int)callResult + 0x9c) = local_54;
        *(uint *)((int)callResult + 0xc) = local_98;
        iVar16 = FUN_00165604(iVar14,callResult);
        if (*(int *)(iVar16 + 0x158) == 0) {
          uVar13 = 1;
          *(int *)(iVar12 + 0x238) = *(int *)(iVar12 + 0x238) + 1;
          Block__insertInstBefore(iVar14,inst,iVar16);
        }
        else {
          for (; iVar9 = (**(code **)(*inst + 0x14))(inst), iVar8 <= iVar9; iVar8 = iVar8 + 1)
          {
            operandVReg = (void *)IRInst__getOperandSource(inst,iVar8);
            if (callResult == operandVReg) {
              IRInst__setOperandSource(inst,iVar8,iVar16,0,*(undefined4 *)(this + 8));
            }
          }
          uVar13 = 1;
        }
      }
      iVar16 = iVar2;
      if (((local_a8 == 1) && (iVar10 = local_a4, -1 < iVar11)) && (iVar11 != local_a4)) {
        callResult = IRInst__create(0x31,*(undefined4 *)(this + 8));
        *(undefined4 *)((int)callResult + 0x98) = 0;
        *(undefined4 *)((int)callResult + 0x94) = *(undefined4 *)((int)callResult + 0x14c);
        IRInst__setOperandSource(callResult,1,uVar4,0,*(undefined4 *)(this + 8));
        local_98 = 0;
        for (iVar10 = 1; iVar16 = (**(code **)(*inst + 0x14))(inst), iVar10 <= iVar16;
            iVar10 = iVar10 + 1) {
          local_a0 = 4;
          iVar16 = ((int (*)())FUN_00190100)(this,inst,iVar10,&local_a0,&local_9c);
          if (((iVar16 != 0) && (local_a0 == local_a8)) && (local_9c == local_a4)) {
            iVar16 = IRInst__getOperandRecord(inst,iVar10);
            FUN_000f3398(&local_50,*(undefined4 *)(iVar16 + 0x10));
            local_98 = local_50 | local_98;
            IRInst__setOperandSource(inst,iVar10,callResult,0,*(undefined4 *)(this + 8));
          }
        }
        iVar16 = 1;
        FUN_000f31f8(local_4c,0,local_98);
        *(undefined4 *)((int)callResult + 0x9c) = local_4c[0];
        *(uint *)((int)callResult + 0xc) = local_98;
        iVar10 = FUN_00165604(iVar14,callResult);
        if (*(int *)(iVar10 + 0x158) == 0) {
          uVar13 = 1;
          *(int *)(iVar12 + 0x238) = *(int *)(iVar12 + 0x238) + 1;
          Block__insertInstBefore(iVar14,inst,iVar10);
          iVar10 = iVar11;
          iVar16 = iVar2;
        }
        else {
          for (; iVar8 = (**(code **)(*inst + 0x14))(inst), iVar16 <= iVar8;
              iVar16 = iVar16 + 1) {
            operandVReg = (void *)IRInst__getOperandSource(inst,iVar16);
            if (callResult == operandVReg) {
              IRInst__setOperandSource(inst,iVar16,iVar10,0,*(undefined4 *)(this + 8));
            }
          }
          uVar13 = 1;
          iVar10 = iVar11;
          iVar16 = iVar2;
        }
      }
    }
code_r0x0019125c:
    loopIndex = loopIndex + 1;
    iVar11 = iVar10;
    iVar2 = iVar16;
  } while( true );
}

/* R300VSchedModel__vslot19 @ 0x191298 (724 bytes) */
int R300VSchedModel__vslot19(this, inst)
  int this;
  int *inst;
{
  int schedulerAllocRegEnabled;
  int iVar1;
  int iVar2;
  int *callResult;
  int *callResult2;
  int *operandVReg;
  
  if ((inst[5] & 0x8000U) != 0) {
    return 0;
  }
  iVar1 = OpcodeTraits__flagBit2(*(undefined4 *)(inst[0x22] + 8),*(undefined4 *)(this + 8));
  if (iVar1 == 0) {
    iVar1 = (**(code **)(*inst + 0x14))(inst);
    if ((iVar1 < 3) && (*(int *)(inst[0x22] + 8) != 0x32)) {
      return 1;
    }
  }
  else {
    iVar1 = FUN_000f3a30(inst);
    if (((iVar1 < 2) && (iVar1 = *(int *)(inst[0x22] + 8), iVar1 != 0xa5)) &&
       (((*(uint *)(*(int *)(*(int *)(this + 8) + 0x30c) + 8) & 0x10000) != 0 ||
        ((iVar1 != 0x4c && (iVar1 != 0x4d)))))) {
      for (iVar1 = 0; iVar2 = (**(code **)(*inst + 0x14))(inst), iVar1 <= iVar2;
          iVar1 = iVar1 + 1) {
        iVar2 = FUN_00105dbc(inst,iVar1);
        if (iVar2 != 0) {
          return 3;
        }
      }
      iVar1 = (**(code **)(*inst + 0x14))(inst);
      if (1 < iVar1) {
        callResult = (int *)IRInst__getOperandSource(inst,1);
        callResult2 = (int *)IRInst__getOperandSource(inst,2);
        iVar1 = (**(code **)(*inst + 0x14))(inst);
        if (2 < iVar1) {
          operandVReg = (int *)IRInst__getOperandSource(inst,3);
          if (callResult2 != operandVReg) {
            return 3;
          }
          iVar1 = IRInst__getOperandRecord(inst,3);
          iVar2 = *(int *)(iVar1 + 0x10);
          iVar1 = IRInst__getOperandRecord(inst,2);
          if (iVar2 != *(int *)(iVar1 + 0x10)) {
            return 3;
          }
          if ((inst[0x3a] & 1U) != (inst[0x34] & 1U)) {
            return 3;
          }
        }
        if (callResult != callResult2) {
          if (callResult[0x20] == 0) {
            return 3;
          }
          iVar1 = RegKind__flagBit0(callResult[0x26]);
          if (iVar1 == 0) {
            return 3;
          }
          if ((callResult[5] & 2U) != 0) {
            return 3;
          }
          iVar1 = (**(code **)(*callResult + 0x50))(callResult);
          if (iVar1 != 0) {
            return 3;
          }
          if (callResult2[0x20] == 0) {
            return 3;
          }
          iVar1 = RegKind__flagBit0(callResult2[0x26]);
          if (iVar1 == 0) {
            return 3;
          }
          if ((callResult2[5] & 2U) != 0) {
            return 3;
          }
          iVar1 = (**(code **)(*callResult2 + 0x50))(callResult2);
          if (iVar1 != 0) {
            return 3;
          }
          if (callResult[0x26] != callResult2[0x26]) {
            return 3;
          }
          if (((callResult[5] & 0x40U) != 0) && ((callResult2[5] & 0x40U) != 0)) {
            if (callResult[0x25] != callResult2[0x25]) {
              return 3;
            }
            return 2;
          }
          schedulerAllocRegEnabled = Compiler__isOptionEnabled(*(undefined4 *)(this + 8),0x25);
          if (schedulerAllocRegEnabled == 0) {
            return 3;
          }
          if ((callResult[5] & 0x20U) != 0) {
            return 3;
          }
          if ((callResult2[5] & 0x20U) != 0) {
            return 3;
          }
          return 2;
        }
      }
      return 2;
    }
  }
  return 3;
}


/* issue: auto-generated aliases bridging data.s/code.s references (written
 * without a leading underscore, matching the raw stock-binary symbol name)
 * against the real compiled C symbols (gcc adds one underscore automatically).
 * Needed because ld64 (required for this PPC binary's size - stock ld breaks on
 * large PPC links) does not silently reconcile this the way stock ld did. */
asm(".globl FUN_0018843c");
asm(".set FUN_0018843c, _KhanPs__peepholeCombine");
asm(".globl FUN_00188e24");
asm(".set FUN_00188e24, _KhanPs__vslot27_optimizeInstruction");
asm(".globl FUN_00188f24");
asm(".set FUN_00188f24, _KhanVs__vslot29_swapIfArmsWhenNotFlattenable");
asm(".globl FUN_00188fec");
asm(".set FUN_00188fec, _KhanVs__peepholeCombine");
asm(".globl FUN_001894ec");
asm(".set FUN_001894ec, _KhanVs__vslot27_optimizeInstruction");
asm(".globl FUN_00189604");
asm(".set FUN_00189604, _R520SchedModel__vslot2_reset");
asm(".globl FUN_0018962c");
asm(".set FUN_0018962c, _KhanPs__vslot31_isNotTextureFetch");
asm(".globl FUN_00189660");
asm(".set FUN_00189660, _KhanPs__vslot65_isEncodableSourceSwizzle");
asm(".globl FUN_001896f8");
asm(".set FUN_001896f8, _FUN_001896f8");
asm(".globl FUN_001897f0");
asm(".set FUN_001897f0, _KhanPs__vslot66_callHelper189788");
asm(".globl FUN_00189be4");
asm(".set FUN_00189be4, _R300SchedModel__vslot15");
asm(".globl FUN_00189fd4");
asm(".set FUN_00189fd4, _R300SchedModel__vslot19");
asm(".globl FUN_0018a080");
asm(".set FUN_0018a080, _R300SchedModel__vslot34");
asm(".globl FUN_0018a1ec");
asm(".set FUN_0018a1ec, _R300SchedModel__vslot26");
asm(".globl FUN_0018a440");
asm(".set FUN_0018a440, _R300SchedModel__vslot28");
asm(".globl FUN_0018ad08");
asm(".set FUN_0018ad08, _R300SchedModel__vslot16");
asm(".globl FUN_0018b654");
asm(".set FUN_0018b654, _R300SchedModel__vslot11");
asm(".globl FUN_0018b9cc");
asm(".set FUN_0018b9cc, _R300SchedModel__vslot14");
asm(".globl FUN_0018dabc");
asm(".set FUN_0018dabc, _R300SchedModel__vslot13");
asm(".globl FUN_0018e1a8");
asm(".set FUN_0018e1a8, _R300SchedModel__vslot27");
asm(".globl FUN_0018f42c");
asm(".set FUN_0018f42c, _R520SchedModel__vslot4_addInstruction");
asm(".globl FUN_0018f55c");
asm(".set FUN_0018f55c, _R520SchedModel__vslot3_canAddInstruction");
asm(".globl FUN_0018f674");
asm(".set FUN_0018f674, _R300SchedModel__vslot12");
asm(".globl FUN_0018f824");
asm(".set FUN_0018f824, _R300VSchedModel__vslot2_reset");
asm(".globl FUN_0018f918");
asm(".set FUN_0018f918, _R300VSchedModel__vslot13");
asm(".globl FUN_0018f984");
asm(".set FUN_0018f984, _R300VSchedModel__vslot28");
asm(".globl FUN_0018fbd8");
asm(".set FUN_0018fbd8, _R300VSchedModel__vslot14");
asm(".globl FUN_0018fd34");
asm(".set FUN_0018fd34, _R300VSchedModel__vslot17");
asm(".globl FUN_001904b8");
asm(".set FUN_001904b8, _R300VSchedModel__vslot4_addInstruction");
asm(".globl FUN_001906c8");
asm(".set FUN_001906c8, _R300VSchedModel__vslot3_canAddInstruction");
asm(".globl FUN_00190990");
asm(".set FUN_00190990, _R300VSchedModel__vslot27");
asm(".globl FUN_00191298");
asm(".set FUN_00191298, _R300VSchedModel__vslot19");
