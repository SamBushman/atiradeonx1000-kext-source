#include "decls.h"

/* extvsEmitSub @ 0x5bbc0 (928 bytes) */
int extvsEmitSub(ctx, shader, instRecord)
  int ctx;
  int *shader;
  int instRecord;
{
  int instSlot;
  int hwProgram;
  uint uVar1;
  int conflict;
  undefined4 uVar3;
  int src1Operand;
  int src0Operand;
  int *symbolList;
  int instCount;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined1 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined1 local_44;
  
  src0Operand = instRecord + 0x20;
  symbolList = shader + 7;
  src1Operand = instRecord + 0x3c;
  conflict = extvsOperandsConflictInBank(symbolList,src0Operand,src1Operand);
  if (conflict == 0) {
    hwProgram = **(int **)(*(int *)(((unsigned char *)0x0000118c) + ctx) * 4 + *shader);
    instCount = *(int *)(hwProgram + 0x18);
    if (0x100 < instCount + 1U) {
      *(undefined1 *)(shader + 4) = 0;
      instCount = *(int *)(hwProgram + 0x18);
      if (*(uint *)(hwProgram + 0x20) < instCount + 1U) {
        uVar3 = (**(code **)(ctx + 0xc))(*(uint *)(hwProgram + 0x20) * 0x10 + 0x100);
        (**(code **)(((unsigned char *)0x00001344) + ctx))
                  (uVar3,*(undefined4 *)(hwProgram + 0x1c),*(int *)(hwProgram + 0x20) << 4);
        (**(code **)(ctx + 0x18))(*(undefined4 *)(hwProgram + 0x1c));
        *(undefined4 *)(hwProgram + 0x1c) = uVar3;
        instCount = *(int *)(hwProgram + 0x18);
        *(int *)(hwProgram + 0x20) = *(int *)(hwProgram + 0x20) + 0x10;
      }
    }
    instSlot = instCount * 0x10 + *(int *)(hwProgram + 0x1c);
    extvsEncodeSourceOperand(ctx,shader,instRecord + 4,instSlot,3,0,0);
    extvsEncodeSourceSwizzle(shader,symbolList,src0Operand,instSlot + 4,0);
    extvsEncodeSourceSwizzle(shader,symbolList,src1Operand,instSlot + 8,0);
    uVar1 = *(uint *)(instSlot + 8);
    uVar3 = 1;
    uVar1 = (uVar1 & 0xf1ffffff ^ 0x10000000) & 0x10000000 |
            (uVar1 & 0xf9ffffff ^ 0x8000000) & 0x8000000 |
            (uVar1 & 0xfdffffff ^ 0x4000000) & 0x4000000 |
            (uVar1 ^ 0x2000000) & 0x2000000 | uVar1 & 0xe1ffffff;
    *(uint *)(instSlot + 0xc) = uVar1;
    *(uint *)(instSlot + 8) = uVar1;
  }
  else {
    hwProgram = **(int **)(*(int *)(((unsigned char *)0x0000118c) + ctx) * 4 + *shader);
    instCount = *(int *)(hwProgram + 0x18);
    if (0x100 < instCount + 2U) {
      *(undefined1 *)(shader + 4) = 0;
      instCount = *(int *)(hwProgram + 0x18);
      if (*(uint *)(hwProgram + 0x20) < instCount + 2U) {
        uVar3 = (**(code **)(ctx + 0xc))(*(uint *)(hwProgram + 0x20) * 0x10 + 0x100);
        (**(code **)(((unsigned char *)0x00001344) + ctx))
                  (uVar3,*(undefined4 *)(hwProgram + 0x1c),*(int *)(hwProgram + 0x20) << 4);
        (**(code **)(ctx + 0x18))(*(undefined4 *)(hwProgram + 0x1c));
        *(undefined4 *)(hwProgram + 0x1c) = uVar3;
        instCount = *(int *)(hwProgram + 0x18);
        *(int *)(hwProgram + 0x20) = *(int *)(hwProgram + 0x20) + 0x10;
      }
    }
    instSlot = instCount * 0x10 + *(int *)(hwProgram + 0x1c);
    uVar3 = extvsAllocTempSlot(ctx,shader);
    local_78 = 3;
    local_60 = 0;
    local_64 = 1;
    local_70 = 1;
    local_6c = 1;
    local_68 = 1;
    local_74 = uVar3;
    extvsEncodeSourceOperand(ctx,shader,&local_78,instSlot,3,0,0);
    extvsEncodeSourceSwizzle(shader,symbolList,src0Operand,instSlot + 4,0);
    uVar1 = *(uint *)(instSlot + 4) & 0xfe001fff | 0x1248000;
    *(uint *)(instSlot + 0xc) = uVar1;
    *(uint *)(instSlot + 8) = uVar1;
    extvsEncodeSourceOperand(ctx,shader,instRecord + 4,instSlot + 0x10,3,0,0);
    local_5c = 3;
    local_44 = 0;
    local_54 = 0x87d5;
    local_50 = 0x87d6;
    local_4c = 0x87d7;
    local_48 = 0x87d8;
    local_58 = uVar3;
    extvsEncodeSourceSwizzle(shader,symbolList,&local_5c,instSlot + 0x14,0);
    extvsEncodeSourceSwizzle(shader,symbolList,src1Operand,instSlot + 0x18,0);
    uVar1 = *(uint *)(instSlot + 0x18);
    uVar3 = 2;
    uVar1 = (uVar1 & 0xf1ffffff ^ 0x10000000) & 0x10000000 |
            (uVar1 & 0xf9ffffff ^ 0x8000000) & 0x8000000 |
            (uVar1 & 0xfdffffff ^ 0x4000000) & 0x4000000 |
            (uVar1 ^ 0x2000000) & 0x2000000 | uVar1 & 0xe1ffffff;
    *(uint *)(instSlot + 0x1c) = uVar1;
    *(uint *)(instSlot + 0x18) = uVar1;
  }
  return uVar3;
}

/* extvsEmitCrs @ 0x5bf60 (1672 bytes) */
int extvsEmitCrs(ctx, shader, instRecord)
  int ctx;
  int *shader;
  int instRecord;
{
  int tempIndex;
  int instCount;
  undefined1 uVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  int *symbolList;
  int src0Operand;
  int src1Operand;
  int hwProgram;
  int instSlot;
  int iVar10;
  int iStack00000020;
  undefined4 local_98;
  int local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined1 local_80;
  undefined4 local_7c;
  int local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined1 local_64;
  undefined4 *local_58;
  
  src0Operand = instRecord + 0x20;
  symbolList = shader + 7;
  src1Operand = instRecord + 0x3c;
  iStack00000020 = instRecord;
  iVar3 = extvsOperandsConflictInBank(symbolList,src0Operand,src1Operand);
  if (iVar3 == 0) {
    iVar3 = **(int **)(*(int *)(((unsigned char *)0x0000118c) + ctx) * 4 + *shader);
    instCount = *(int *)(iVar3 + 0x18);
    if (0x100 < instCount + 2U) {
      *(undefined1 *)(shader + 4) = 0;
      instCount = *(int *)(iVar3 + 0x18);
      if (*(uint *)(iVar3 + 0x20) < instCount + 2U) {
        uVar4 = (**(code **)(ctx + 0xc))(*(uint *)(iVar3 + 0x20) * 0x10 + 0x100);
        (**(code **)(((unsigned char *)0x00001344) + ctx))
                  (uVar4,*(undefined4 *)(iVar3 + 0x1c),*(int *)(iVar3 + 0x20) << 4);
        (**(code **)(ctx + 0x18))(*(undefined4 *)(iVar3 + 0x1c));
        *(undefined4 *)(iVar3 + 0x1c) = uVar4;
        instCount = *(int *)(iVar3 + 0x18);
        *(int *)(iVar3 + 0x20) = *(int *)(iVar3 + 0x20) + 0x10;
      }
    }
    iVar3 = instCount * 0x10 + *(int *)(iVar3 + 0x1c);
    uVar4 = extvsAllocTempSlot(ctx,shader);
    local_98 = 3;
    local_80 = 0;
    local_84 = 1;
    local_90 = 1;
    local_8c = 1;
    local_88 = 1;
    local_94 = uVar4;
    extvsEncodeSourceOperand(ctx,shader,&local_98,iVar3,2,0,0);
    extvsEncodeSourceSwizzle(shader,symbolList,src0Operand,iVar3 + 4,0);
    uVar2 = *(uint *)(iVar3 + 4);
    *(uint *)(iVar3 + 4) =
         (uVar2 & 0x4000000) << 1 |
         (uVar2 & 0x2000000) << 1 |
         uVar2 >> 2 & 0x2000000 |
         (uVar2 & 0x70000) << 3 | (uVar2 & 0xe000) << 3 | uVar2 >> 6 & 0xe000 | uVar2 & 0xe0001fff |
         0x1000000;
    extvsEncodeSourceSwizzle(shader,symbolList,src1Operand,iVar3 + 8,0);
    uVar2 = *(uint *)(iVar3 + 8);
    uVar2 = (uVar2 & 0x2000000) << 2 |
            uVar2 >> 1 & 0x4000000 |
            uVar2 >> 1 & 0x2000000 |
            (uVar2 & 0xe000) << 6 | uVar2 >> 3 & 0x70000 | uVar2 >> 3 & 0xe000 | uVar2 & 0xe0001fff
            | 0x1000000;
    *(uint *)(iVar3 + 0xc) = uVar2;
    *(uint *)(iVar3 + 8) = uVar2;
    extvsEncodeSourceOperand(ctx,shader,iStack00000020 + 4,iVar3 + 0x10,4,0,0);
    extvsEncodeSourceSwizzle(shader,symbolList,src0Operand,iVar3 + 0x14,0);
    uVar2 = *(uint *)(iVar3 + 0x14);
    *(uint *)(iVar3 + 0x14) =
         (uVar2 & 0x2000000) << 2 |
         uVar2 >> 1 & 0x4000000 |
         uVar2 >> 1 & 0x2000000 |
         (uVar2 & 0xe000) << 6 | uVar2 >> 3 & 0x70000 | uVar2 >> 3 & 0xe000 | uVar2 & 0xe0001fff |
         0x1400000;
    extvsEncodeSourceSwizzle(shader,symbolList,src1Operand,iVar3 + 0x18,0);
    uVar2 = *(uint *)(iVar3 + 0x18);
    *(uint *)(iVar3 + 0x18) =
         (uVar2 & 0x4000000) << 1 |
         (uVar2 & 0x2000000) << 1 |
         uVar2 >> 2 & 0x2000000 |
         (uVar2 & 0x70000) << 3 | (uVar2 & 0xe000) << 3 | uVar2 >> 6 & 0xe000 | uVar2 & 0xe0001fff |
         0x1400000;
    local_7c = 3;
    local_74 = 0x87d9;
    local_70 = 0x87da;
    local_6c = 0x87db;
    local_68 = 0x87dc;
    local_64 = 0;
    local_78 = uVar4;
    extvsEncodeSourceSwizzle(shader,symbolList,&local_7c,iVar3 + 0x1c,0);
    uVar4 = 2;
  }
  else {
    iVar10 = **(int **)(*(int *)(((unsigned char *)0x0000118c) + ctx) * 4 + *shader);
    iVar3 = *(int *)(iVar10 + 0x18);
    if (0x100 < iVar3 + 3U) {
      *(undefined1 *)(shader + 4) = 0;
      iVar3 = *(int *)(iVar10 + 0x18);
      if (*(uint *)(iVar10 + 0x20) < iVar3 + 3U) {
        uVar4 = (**(code **)(ctx + 0xc))(*(uint *)(iVar10 + 0x20) * 0x10 + 0x100);
        (**(code **)(((unsigned char *)0x00001344) + ctx))
                  (uVar4,*(undefined4 *)(iVar10 + 0x1c),*(int *)(iVar10 + 0x20) << 4);
        (**(code **)(ctx + 0x18))(*(undefined4 *)(iVar10 + 0x1c));
        *(undefined4 *)(iVar10 + 0x1c) = uVar4;
        iVar3 = *(int *)(iVar10 + 0x18);
        *(int *)(iVar10 + 0x20) = *(int *)(iVar10 + 0x20) + 0x10;
      }
    }
    instSlot = iVar3 * 0x10 + *(int *)(iVar10 + 0x1c);
    tempIndex = extvsAllocTempSlot(ctx,shader);
    local_58 = &local_7c;
    hwProgram = **(int **)(*(int *)(((unsigned char *)0x0000118c) + ctx) * 4 + *shader);
    iVar3 = tempIndex * 0x28 + *(int *)(hwProgram + 0x4c);
    uVar1 = *(undefined1 *)(iVar3 + 0x10);
    *(undefined1 *)(iVar3 + 0x10) = 1;
    uVar4 = extvsAllocTempSlot(ctx,shader);
    *(undefined1 *)(tempIndex * 0x28 + *(int *)(hwProgram + 0x4c) + 0x10) = uVar1;
    local_80 = 0;
    local_98 = 3;
    local_90 = 1;
    local_8c = 1;
    local_88 = 1;
    local_84 = 1;
    local_94 = tempIndex;
    extvsEncodeSourceOperand(ctx,shader,&local_98,instSlot,3,0,0);
    extvsEncodeSourceSwizzle(shader,symbolList,src0Operand,instSlot + 4,0);
    uVar2 = *(uint *)(instSlot + 4) & 0xfe001fff | 0x1248000;
    *(uint *)(instSlot + 0xc) = uVar2;
    *(uint *)(instSlot + 8) = uVar2;
    local_80 = 0;
    local_84 = 1;
    local_98 = 3;
    local_90 = 1;
    local_8c = 1;
    local_88 = 1;
    local_94 = uVar4;
    extvsEncodeSourceOperand(ctx,shader,&local_98,instSlot + 0x10,2,0,0);
    local_74 = 0x87d7;
    local_70 = 0x87d5;
    local_64 = 0;
    local_6c = 0x87d6;
    local_68 = 0x87dd;
    local_7c = 3;
    local_78 = tempIndex;
    extvsEncodeSourceSwizzle(shader,symbolList,local_58,instSlot + 0x14,0);
    extvsEncodeSourceSwizzle(shader,symbolList,src1Operand,instSlot + 0x18,0);
    uVar2 = *(uint *)(instSlot + 0x18);
    uVar2 = (uVar2 & 0x2000000) << 2 |
            uVar2 >> 1 & 0x4000000 |
            uVar2 >> 1 & 0x2000000 |
            (uVar2 & 0xe000) << 6 | uVar2 >> 3 & 0x70000 | uVar2 >> 3 & 0xe000 | uVar2 & 0xe0001fff
            | 0x1000000;
    *(uint *)(instSlot + 0x1c) = uVar2;
    *(uint *)(instSlot + 0x18) = uVar2;
    extvsEncodeSourceOperand(ctx,shader,iStack00000020 + 4,instSlot + 0x20,4,0,0);
    local_74 = 0x87d6;
    local_70 = 0x87d7;
    local_64 = 0;
    local_6c = 0x87d5;
    local_68 = 0x87de;
    local_7c = 3;
    local_78 = tempIndex;
    extvsEncodeSourceSwizzle(shader,symbolList,local_58,instSlot + 0x24,0);
    extvsEncodeSourceSwizzle(shader,symbolList,src1Operand,instSlot + 0x28,0);
    uVar2 = *(uint *)(instSlot + 0x28);
    *(uint *)(instSlot + 0x28) =
         (uVar2 & 0x4000000) << 1 |
         (uVar2 & 0x2000000) << 1 |
         uVar2 >> 2 & 0x2000000 |
         (uVar2 & 0x70000) << 3 | (uVar2 & 0xe000) << 3 | uVar2 >> 6 & 0xe000 | uVar2 & 0xe0001fff |
         0x1400000;
    local_74 = 0x87d9;
    local_70 = 0x87da;
    local_7c = 3;
    local_6c = 0x87db;
    local_68 = 0x87dc;
    local_64 = 0;
    local_78 = uVar4;
    extvsEncodeSourceSwizzle(shader,symbolList,local_58,instSlot + 0x2c,0);
    uVar4 = 3;
  }
  return uVar4;
}

/* extvsEmitMmul @ 0x5c600 (1552 bytes) */
int extvsEmitMmul(ctx, shader, instRecord)
  int ctx;
  int *shader;
  int instRecord;
{
  int instCount;
  int instSlot;
  int hwProgram;
  undefined4 tempIndex;
  uint uVar1;
  int iVar2;
  undefined4 newInstArray;
  int src0Operand;
  int *symbolList;
  int src1Operand;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined4 uStack_88;
  undefined4 uStack_84;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  undefined4 uStack_78;
  undefined4 uStack_74;
  undefined1 uStack_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined1 uStack_54;
  
  if ((*(int *)(instRecord + 4) != *(int *)(instRecord + 0x3c)) ||
     (*(int *)(instRecord + 8) != *(int *)(instRecord + 0x40))) {
    symbolList = shader + 7;
    src0Operand = instRecord + 0x20;
    src1Operand = instRecord + 0x3c;
    iVar2 = extvsOperandsConflictInBank(symbolList,src0Operand,src1Operand);
    if (iVar2 == 0) {
      iVar7 = **(int **)(*(int *)(((unsigned char *)0x0000118c) + ctx) * 4 + *shader);
      iVar2 = *(int *)(iVar7 + 0x18);
      if (0x100 < iVar2 + 4U) {
        *(undefined1 *)(shader + 4) = 0;
        iVar2 = *(int *)(iVar7 + 0x18);
        if (*(uint *)(iVar7 + 0x20) < iVar2 + 4U) {
          newInstArray = (**(code **)(ctx + 0xc))(*(uint *)(iVar7 + 0x20) * 0x10 + 0x100);
          (**(code **)(((unsigned char *)0x00001344) + ctx))
                    (newInstArray,*(undefined4 *)(iVar7 + 0x1c),*(int *)(iVar7 + 0x20) << 4);
          (**(code **)(ctx + 0x18))(*(undefined4 *)(iVar7 + 0x1c));
          *(undefined4 *)(iVar7 + 0x1c) = newInstArray;
          iVar2 = *(int *)(iVar7 + 0x18);
          *(int *)(iVar7 + 0x20) = *(int *)(iVar7 + 0x20) + 0x10;
        }
      }
      iVar8 = *(int *)(iVar7 + 0x1c);
      iVar2 = iVar2 * 0x10;
      iVar7 = instRecord + 4;
      iVar9 = iVar2 + iVar8;
      extvsEncodeSourceOperand(ctx,shader,iVar7,iVar9,1,0,0);
      *(uint *)(iVar2 + iVar8) = *(uint *)(iVar2 + iVar8) & 0xff1fffff;
      extvsEncodeSourceSwizzle(shader,symbolList,src0Operand,iVar9 + 4,0);
      extvsEncodeSourceSwizzle(shader,symbolList,src1Operand,iVar9 + 8,0);
      *(undefined4 *)(iVar9 + 0xc) = *(undefined4 *)(iVar9 + 8);
      extvsEncodeSourceOperand(ctx,shader,iVar7,iVar9 + 0x10,1,0,0);
      *(uint *)(iVar9 + 0x10) = *(uint *)(iVar9 + 0x10) & 0xff2fffff;
      extvsEncodeSourceSwizzle(shader,symbolList,src0Operand,iVar9 + 0x14,1);
      extvsEncodeSourceSwizzle(shader,symbolList,src1Operand,iVar9 + 0x18,0);
      *(undefined4 *)(iVar9 + 0x1c) = *(undefined4 *)(iVar9 + 0x18);
      extvsEncodeSourceOperand(ctx,shader,iVar7,iVar9 + 0x20,1,0,0);
      *(uint *)(iVar9 + 0x20) = *(uint *)(iVar9 + 0x20) & 0xff4fffff;
      extvsEncodeSourceSwizzle(shader,symbolList,src0Operand,iVar9 + 0x24,2);
      extvsEncodeSourceSwizzle(shader,symbolList,src1Operand,iVar9 + 0x28,0);
      *(undefined4 *)(iVar9 + 0x2c) = *(undefined4 *)(iVar9 + 0x28);
      extvsEncodeSourceOperand(ctx,shader,iVar7,iVar9 + 0x30,1,0,0);
      *(uint *)(iVar9 + 0x30) = *(uint *)(iVar9 + 0x30) & 0xff8fffff;
      extvsEncodeSourceSwizzle(shader,symbolList,src0Operand,iVar9 + 0x34,3);
      extvsEncodeSourceSwizzle(shader,symbolList,src1Operand,iVar9 + 0x38,0);
      *(undefined4 *)(iVar9 + 0x3c) = *(undefined4 *)(iVar9 + 0x38);
      return 4;
    }
  }
  symbolList = shader + 7;
  iVar2 = instRecord + 0x20;
  hwProgram = **(int **)(*(int *)(((unsigned char *)0x0000118c) + ctx) * 4 + *shader);
  instCount = *(int *)(hwProgram + 0x18);
  if (0x100 < instCount + 5U) {
    *(undefined1 *)(shader + 4) = 0;
    instCount = *(int *)(hwProgram + 0x18);
    if (*(uint *)(hwProgram + 0x20) < instCount + 5U) {
      newInstArray = (**(code **)(ctx + 0xc))(*(uint *)(hwProgram + 0x20) * 0x10 + 0x100);
      (**(code **)(((unsigned char *)0x00001344) + ctx))
                (newInstArray,*(undefined4 *)(hwProgram + 0x1c),*(int *)(hwProgram + 0x20) << 4);
      (**(code **)(ctx + 0x18))(*(undefined4 *)(hwProgram + 0x1c));
      *(undefined4 *)(hwProgram + 0x1c) = newInstArray;
      instCount = *(int *)(hwProgram + 0x18);
      *(int *)(hwProgram + 0x20) = *(int *)(hwProgram + 0x20) + 0x10;
    }
  }
  iVar7 = instRecord + 4;
  instSlot = instCount * 0x10 + *(int *)(hwProgram + 0x1c);
  tempIndex = extvsAllocTempSlot(ctx,shader);
  uStack_88 = 3;
  uStack_70 = 0;
  uStack_74 = 1;
  uStack_80 = 1;
  uStack_7c = 1;
  uStack_78 = 1;
  uStack_84 = tempIndex;
  extvsEncodeSourceOperand(ctx,shader,&uStack_88,instSlot,3,0,0);
  extvsEncodeSourceSwizzle(shader,symbolList,instRecord + 0x3c,instSlot + 4,0);
  uVar1 = *(uint *)(instSlot + 4) & 0xfe001fff | 0x1248000;
  *(uint *)(instSlot + 0xc) = uVar1;
  *(uint *)(instSlot + 8) = uVar1;
  extvsEncodeSourceOperand(ctx,shader,iVar7,instSlot + 0x10,1,0,0);
  *(uint *)(instSlot + 0x10) = *(uint *)(instSlot + 0x10) & 0xff1fffff;
  extvsEncodeSourceSwizzle(shader,symbolList,iVar2,instSlot + 0x14,0);
  uStack_6c = 3;
  uStack_54 = 0;
  uStack_60 = 0x87d6;
  uStack_64 = 0x87d5;
  uStack_5c = 0x87d7;
  uStack_58 = 0x87d8;
  uStack_68 = tempIndex;
  extvsEncodeSourceSwizzle(shader,symbolList,&uStack_6c,instSlot + 0x18,0);
  *(undefined4 *)(instSlot + 0x1c) = *(undefined4 *)(instSlot + 0x18);
  extvsEncodeSourceOperand(ctx,shader,iVar7,instSlot + 0x20,1,0,0);
  *(uint *)(instSlot + 0x20) = *(uint *)(instSlot + 0x20) & 0xff2fffff;
  extvsEncodeSourceSwizzle(shader,symbolList,iVar2,instSlot + 0x24,1);
  extvsEncodeSourceSwizzle(shader,symbolList,&uStack_6c,instSlot + 0x28,0);
  *(undefined4 *)(instSlot + 0x2c) = *(undefined4 *)(instSlot + 0x28);
  extvsEncodeSourceOperand(ctx,shader,iVar7,instSlot + 0x30,1,0,0);
  *(uint *)(instSlot + 0x30) = *(uint *)(instSlot + 0x30) & 0xff4fffff;
  extvsEncodeSourceSwizzle(shader,symbolList,iVar2,instSlot + 0x34,2);
  extvsEncodeSourceSwizzle(shader,symbolList,&uStack_6c,instSlot + 0x38,0);
  *(undefined4 *)(instSlot + 0x3c) = *(undefined4 *)(instSlot + 0x38);
  extvsEncodeSourceOperand(ctx,shader,iVar7,instSlot + 0x40,1,0,0);
  *(uint *)(instSlot + 0x40) = *(uint *)(instSlot + 0x40) & 0xff8fffff;
  extvsEncodeSourceSwizzle(shader,symbolList,iVar2,instSlot + 0x44,3);
  extvsEncodeSourceSwizzle(shader,symbolList,&uStack_6c,instSlot + 0x48,0);
  *(undefined4 *)(instSlot + 0x4c) = *(undefined4 *)(instSlot + 0x48);
  return 5;
}

/* extvsEmitMov @ 0x5cc20 (320 bytes) */
int extvsEmitMov(ctx, shader, instRecord)
  int ctx;
  int *shader;
  int instRecord;
{
  int instSlot;
  uint uVar1;
  undefined4 newInstArray;
  int instCount;
  int hwProgram;
  
  hwProgram = **(int **)(*(int *)(((unsigned char *)0x0000118c) + ctx) * 4 + *shader);
  instCount = *(int *)(hwProgram + 0x18);
  if (0x100 < instCount + 1U) {
    *(undefined1 *)(shader + 4) = 0;
    instCount = *(int *)(hwProgram + 0x18);
    if (*(uint *)(hwProgram + 0x20) < instCount + 1U) {
      newInstArray = (**(code **)(ctx + 0xc))(*(uint *)(hwProgram + 0x20) * 0x10 + 0x100);
      (**(code **)(((unsigned char *)0x00001344) + ctx))
                (newInstArray,*(undefined4 *)(hwProgram + 0x1c),*(int *)(hwProgram + 0x20) << 4);
      (**(code **)(ctx + 0x18))(*(undefined4 *)(hwProgram + 0x1c));
      *(undefined4 *)(hwProgram + 0x1c) = newInstArray;
      instCount = *(int *)(hwProgram + 0x18);
      *(int *)(hwProgram + 0x20) = *(int *)(hwProgram + 0x20) + 0x10;
    }
  }
  instSlot = instCount * 0x10 + *(int *)(hwProgram + 0x1c);
  extvsEncodeSourceOperand(ctx,shader,instRecord + 4,instSlot,3,0,0);
  extvsEncodeSourceSwizzle(shader,shader + 7,instRecord + 0x20,instSlot + 4,0);
  uVar1 = *(uint *)(instSlot + 4) & 0xfe001fff | 0x1248000;
  *(uint *)(instSlot + 0xc) = uVar1;
  *(uint *)(instSlot + 8) = uVar1;
  return 1;
}

/* extvsEmitSwizzle @ 0x5cd60 (1228 bytes) */
int extvsEmitSwizzle(ctx, shader, instRecord)
  int ctx;
  int *shader;
  int instRecord;
{
  int instSlot;
  uint uVar1;
  uint uVar2;
  undefined4 newInstArray;
  int instCount;
  int hwProgram;
  
  hwProgram = **(int **)(*(int *)(((unsigned char *)0x0000118c) + ctx) * 4 + *shader);
  instCount = *(int *)(hwProgram + 0x18);
  if (0x100 < instCount + 1U) {
    *(undefined1 *)(shader + 4) = 0;
    instCount = *(int *)(hwProgram + 0x18);
    if (*(uint *)(hwProgram + 0x20) < instCount + 1U) {
      newInstArray = (**(code **)(ctx + 0xc))(*(uint *)(hwProgram + 0x20) * 0x10 + 0x100);
      (**(code **)(((unsigned char *)0x00001344) + ctx))
                (newInstArray,*(undefined4 *)(hwProgram + 0x1c),*(int *)(hwProgram + 0x20) << 4);
      (**(code **)(ctx + 0x18))(*(undefined4 *)(hwProgram + 0x1c));
      *(undefined4 *)(hwProgram + 0x1c) = newInstArray;
      instCount = *(int *)(hwProgram + 0x18);
      *(int *)(hwProgram + 0x20) = *(int *)(hwProgram + 0x20) + 0x10;
    }
  }
  instSlot = instCount * 0x10 + *(int *)(hwProgram + 0x1c);
  extvsEncodeSourceOperand(ctx,shader,instRecord + 4,instSlot,3,0,0);
  extvsEncodeSourceSwizzle(shader,shader + 7,instRecord + 0x20,instSlot + 4,0);
  switch(*(undefined4 *)(instRecord + 0x28)) {
  case 0x87d5:
  case 0x87d9:
    uVar1 = *(uint *)(instSlot + 4) & 0xffff1fff;
    *(uint *)(instSlot + 4) = uVar1;
    break;
  case 0x87d6:
  case 0x87da:
    uVar1 = *(uint *)(instSlot + 4) & 0xffff1fff | 0x2000;
    *(uint *)(instSlot + 4) = uVar1;
    break;
  case 0x87d7:
  case 0x87db:
    uVar1 = *(uint *)(instSlot + 4) & 0xffff1fff | 0x4000;
    *(uint *)(instSlot + 4) = uVar1;
    break;
  case 0x87d8:
  case 0x87dc:
    uVar1 = *(uint *)(instSlot + 4) & 0xffff1fff | 0x6000;
    *(uint *)(instSlot + 4) = uVar1;
    break;
  case 0x87dd:
    uVar1 = *(uint *)(instSlot + 4) & 0xffff1fff | 0x8000;
    *(uint *)(instSlot + 4) = uVar1;
    break;
  case 0x87de:
  case 0x87df:
    uVar1 = *(uint *)(instSlot + 4) & 0xffff1fff | 0xa000;
    *(uint *)(instSlot + 4) = uVar1;
    break;
  default:
    goto LAB_0005d2d0;
  }
  uVar2 = *(int *)(instRecord + 0x28) - 0x87d5;
  if (uVar2 < 0xb) {
    uVar2 = 1 << (uVar2 & 0x3f);
    if ((uVar2 & 0x30f) == 0) {
      if ((uVar2 & 0x4f0) == 0) {
        return 0;
      }
      uVar1 = uVar1 | 0x2000000;
      *(uint *)(instSlot + 4) = uVar1;
    }
    else {
      uVar1 = uVar1 & 0xfdffffff;
      *(uint *)(instSlot + 4) = uVar1;
    }
    switch(*(undefined4 *)(instRecord + 0x2c)) {
    case 0x87d5:
    case 0x87d9:
      uVar1 = uVar1 & 0xfff8ffff;
      *(uint *)(instSlot + 4) = uVar1;
      break;
    case 0x87d6:
    case 0x87da:
      uVar1 = uVar1 & 0xfff8ffff | 0x10000;
      *(uint *)(instSlot + 4) = uVar1;
      break;
    case 0x87d7:
    case 0x87db:
      uVar1 = uVar1 & 0xfff8ffff | 0x20000;
      *(uint *)(instSlot + 4) = uVar1;
      break;
    case 0x87d8:
    case 0x87dc:
      uVar1 = uVar1 & 0xfff8ffff | 0x30000;
      *(uint *)(instSlot + 4) = uVar1;
      break;
    case 0x87dd:
      uVar1 = uVar1 & 0xfff8ffff | 0x40000;
      *(uint *)(instSlot + 4) = uVar1;
      break;
    case 0x87de:
    case 0x87df:
      uVar1 = uVar1 & 0xfff8ffff | 0x50000;
      *(uint *)(instSlot + 4) = uVar1;
      break;
    default:
      goto LAB_0005d2d0;
    }
    uVar2 = *(int *)(instRecord + 0x2c) - 0x87d5;
    if (uVar2 < 0xb) {
      uVar2 = 1 << (uVar2 & 0x3f);
      if ((uVar2 & 0x30f) == 0) {
        if ((uVar2 & 0x4f0) == 0) {
          return 0;
        }
        uVar1 = uVar1 | 0x4000000;
        *(uint *)(instSlot + 4) = uVar1;
      }
      else {
        uVar1 = uVar1 & 0xfbffffff;
        *(uint *)(instSlot + 4) = uVar1;
      }
      switch(*(undefined4 *)(instRecord + 0x30)) {
      case 0x87d5:
      case 0x87d9:
        uVar1 = uVar1 & 0xffc7ffff;
        *(uint *)(instSlot + 4) = uVar1;
        break;
      case 0x87d6:
      case 0x87da:
        uVar1 = uVar1 & 0xffc7ffff | 0x80000;
        *(uint *)(instSlot + 4) = uVar1;
        break;
      case 0x87d7:
      case 0x87db:
        uVar1 = uVar1 & 0xffc7ffff | 0x100000;
        *(uint *)(instSlot + 4) = uVar1;
        break;
      case 0x87d8:
      case 0x87dc:
        uVar1 = uVar1 & 0xffc7ffff | 0x180000;
        *(uint *)(instSlot + 4) = uVar1;
        break;
      case 0x87dd:
        uVar1 = uVar1 & 0xffc7ffff | 0x200000;
        *(uint *)(instSlot + 4) = uVar1;
        break;
      case 0x87de:
      case 0x87df:
        uVar1 = uVar1 & 0xffc7ffff | 0x280000;
        *(uint *)(instSlot + 4) = uVar1;
        break;
      default:
        goto LAB_0005d2d0;
      }
      uVar2 = *(int *)(instRecord + 0x30) - 0x87d5;
      if (uVar2 < 0xb) {
        uVar2 = 1 << (uVar2 & 0x3f);
        if ((uVar2 & 0x30f) == 0) {
          if ((uVar2 & 0x4f0) == 0) {
            return 0;
          }
          uVar1 = uVar1 | 0x8000000;
          *(uint *)(instSlot + 4) = uVar1;
        }
        else {
          uVar1 = uVar1 & 0xf7ffffff;
          *(uint *)(instSlot + 4) = uVar1;
        }
        switch(*(undefined4 *)(instRecord + 0x34)) {
        case 0x87d5:
        case 0x87d9:
          uVar1 = uVar1 & 0xfe3fffff;
          *(uint *)(instSlot + 4) = uVar1;
          break;
        case 0x87d6:
        case 0x87da:
          uVar1 = uVar1 & 0xfe3fffff | 0x400000;
          *(uint *)(instSlot + 4) = uVar1;
          break;
        case 0x87d7:
        case 0x87db:
          uVar1 = uVar1 & 0xfe3fffff | 0x800000;
          *(uint *)(instSlot + 4) = uVar1;
          break;
        case 0x87d8:
        case 0x87dc:
          uVar1 = uVar1 & 0xfe3fffff | 0xc00000;
          *(uint *)(instSlot + 4) = uVar1;
          break;
        case 0x87dd:
          uVar1 = uVar1 & 0xfe3fffff | 0x1000000;
          *(uint *)(instSlot + 4) = uVar1;
          break;
        case 0x87de:
        case 0x87df:
          uVar1 = uVar1 & 0xfe3fffff | 0x1400000;
          *(uint *)(instSlot + 4) = uVar1;
          break;
        default:
          goto LAB_0005d2d0;
        }
        uVar2 = *(int *)(instRecord + 0x34) - 0x87d5;
        if (uVar2 < 0xb) {
          uVar2 = 1 << (uVar2 & 0x3f);
          if ((uVar2 & 0x30f) == 0) {
            if ((uVar2 & 0x4f0) == 0) {
              return 0;
            }
            uVar1 = uVar1 | 0x10000000;
            *(uint *)(instSlot + 4) = uVar1;
          }
          else {
            uVar1 = uVar1 & 0xefffffff;
            *(uint *)(instSlot + 4) = uVar1;
          }
          uVar1 = uVar1 & 0xe0001fff | 0x1248000;
          *(uint *)(instSlot + 0xc) = uVar1;
          *(uint *)(instSlot + 8) = uVar1;
          return 1;
        }
      }
    }
  }
LAB_0005d2d0:
  return 0;
}

/* extvsEmitWriteMask @ 0x5d2f0 (372 bytes) */
int extvsEmitWriteMask(ctx, shader, instRecord)
  int ctx;
  int *shader;
  int instRecord;
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined4 newInstArray;
  int iVar6;
  int iVar7;
  int iVar8;
  
  iVar6 = **(int **)(*(int *)(((unsigned char *)0x0000118c) + ctx) * 4 + *shader);
  iVar8 = *(int *)(iVar6 + 0x18);
  if (0x100 < iVar8 + 1U) {
    *(undefined1 *)(shader + 4) = 0;
    iVar8 = *(int *)(iVar6 + 0x18);
    if (*(uint *)(iVar6 + 0x20) < iVar8 + 1U) {
      newInstArray = (**(code **)(ctx + 0xc))(*(uint *)(iVar6 + 0x20) * 0x10 + 0x100);
      (**(code **)(((unsigned char *)0x00001344) + ctx))
                (newInstArray,*(undefined4 *)(iVar6 + 0x1c),*(int *)(iVar6 + 0x20) << 4);
      (**(code **)(ctx + 0x18))(*(undefined4 *)(iVar6 + 0x1c));
      *(undefined4 *)(iVar6 + 0x1c) = newInstArray;
      iVar8 = *(int *)(iVar6 + 0x18);
      *(int *)(iVar6 + 0x20) = *(int *)(iVar6 + 0x20) + 0x10;
    }
  }
  iVar7 = *(int *)(iVar6 + 0x1c);
  iVar8 = iVar8 * 0x10;
  iVar6 = iVar8 + iVar7;
  extvsEncodeSourceOperand(ctx,shader,instRecord + 4,iVar6,3,0,0);
  uVar3 = *(uint *)(iVar8 + iVar7);
  uVar4 = (*(uint *)(instRecord + 0xc) & 1) << 0x14;
  *(uint *)(iVar8 + iVar7) = uVar4 | uVar3 & 0xffefffff;
  uVar1 = (*(uint *)(instRecord + 0x10) & 1) << 0x15;
  *(uint *)(iVar8 + iVar7) = uVar1 | uVar4 | uVar3 & 0xffcfffff;
  uVar2 = (*(uint *)(instRecord + 0x14) & 1) << 0x16;
  *(uint *)(iVar8 + iVar7) = uVar2 | uVar1 | uVar4 | uVar3 & 0xff8fffff;
  *(uint *)(iVar8 + iVar7) =
       (*(uint *)(instRecord + 0x18) & 1) << 0x17 | uVar2 | uVar1 | uVar4 | uVar3 & 0xff0fffff;
  extvsEncodeSourceSwizzle(shader,shader + 7,instRecord + 0x20,iVar6 + 4,0);
  uVar4 = *(uint *)(iVar6 + 4) & 0xfe001fff | 0x1248000;
  *(uint *)(iVar6 + 0xc) = uVar4;
  *(uint *)(iVar6 + 8) = uVar4;
  return 1;
}

/* extvsEmitOp879c @ 0x5d470 (424 bytes) */
int extvsEmitOp879c(ctx, shader, instRecord)
  int ctx;
  int *shader;
  int instRecord;
{
  int instSlot;
  int extvsOperandDataTypeResult;
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  int hwProgram;
  int dstOperand;
  
  hwProgram = **(int **)(*(int *)(((unsigned char *)0x0000118c) + ctx) * 4 + *shader);
  iVar3 = *(int *)(hwProgram + 0x18);
  if (0x100 < iVar3 + 1U) {
    *(undefined1 *)(shader + 4) = 0;
    iVar3 = *(int *)(hwProgram + 0x18);
    if (*(uint *)(hwProgram + 0x20) < iVar3 + 1U) {
      uVar2 = (**(code **)(ctx + 0xc))(*(uint *)(hwProgram + 0x20) * 0x10 + 0x100);
      (**(code **)(((unsigned char *)0x00001344) + ctx))
                (uVar2,*(undefined4 *)(hwProgram + 0x1c),*(int *)(hwProgram + 0x20) << 4);
      (**(code **)(ctx + 0x18))(*(undefined4 *)(hwProgram + 0x1c));
      *(undefined4 *)(hwProgram + 0x1c) = uVar2;
      iVar3 = *(int *)(hwProgram + 0x18);
      *(int *)(hwProgram + 0x20) = *(int *)(hwProgram + 0x20) + 0x10;
    }
  }
  dstOperand = instRecord + 4;
  instSlot = iVar3 * 0x10 + *(int *)(hwProgram + 0x1c);
  extvsOperandDataTypeResult = extvsOperandDataType(shader + 7,dstOperand);
  if (*(uint *)(instRecord + 0x40) < 4) {
    if (extvsOperandDataTypeResult == 0x87bf) {
      extvsEncodeSourceOperand(ctx,shader,dstOperand,instSlot,3,0,0);
    }
    else {
      if (extvsOperandDataTypeResult != 0x87c0) goto LAB_0005d600;
      extvsEncodeSourceOperand(ctx,shader,dstOperand,instSlot,3,0,*(uint *)(instRecord + 0x40));
    }
    extvsEncodeSourceSwizzle(shader,shader + 7,instRecord + 0x20,instSlot + 4,0);
    uVar2 = 1;
    uVar1 = *(uint *)(instSlot + 4) & 0xfe001fff | 0x1248000;
    *(uint *)(instSlot + 0xc) = uVar1;
    *(uint *)(instSlot + 8) = uVar1;
  }
  else {
LAB_0005d600:
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

/* extvsEmitOp879d @ 0x5d620 (568 bytes) */
int extvsEmitOp879d(ctx, shader, instRecord)
  int ctx;
  int *shader;
  int instRecord;
{
  int instSlot;
  int extvsOperandDataTypeResult;
  undefined4 uVar1;
  int iVar2;
  int src0Operand;
  int *symbolList;
  int hwProgram;
  uint uVar6;
  
  hwProgram = **(int **)(*(int *)(((unsigned char *)0x0000118c) + ctx) * 4 + *shader);
  iVar2 = *(int *)(hwProgram + 0x18);
  if (0x100 < iVar2 + 1U) {
    *(undefined1 *)(shader + 4) = 0;
    iVar2 = *(int *)(hwProgram + 0x18);
    if (*(uint *)(hwProgram + 0x20) < iVar2 + 1U) {
      uVar1 = (**(code **)(ctx + 0xc))(*(uint *)(hwProgram + 0x20) * 0x10 + 0x100);
      (**(code **)(((unsigned char *)0x00001344) + ctx))
                (uVar1,*(undefined4 *)(hwProgram + 0x1c),*(int *)(hwProgram + 0x20) << 4);
      (**(code **)(ctx + 0x18))(*(undefined4 *)(hwProgram + 0x1c));
      *(undefined4 *)(hwProgram + 0x1c) = uVar1;
      iVar2 = *(int *)(hwProgram + 0x18);
      *(int *)(hwProgram + 0x20) = *(int *)(hwProgram + 0x20) + 0x10;
    }
  }
  symbolList = shader + 7;
  src0Operand = instRecord + 0x20;
  instSlot = iVar2 * 0x10 + *(int *)(hwProgram + 0x1c);
  extvsOperandDataTypeResult = extvsOperandDataType(symbolList,src0Operand);
  uVar6 = *(uint *)(instRecord + 0x40);
  if (uVar6 < 4) {
    extvsEncodeSourceOperand(ctx,shader,instRecord + 4,instSlot,3,0,0);
    if (extvsOperandDataTypeResult == 0x87bf) {
      extvsEncodeSourceSwizzle(shader,symbolList,src0Operand,instSlot + 4,0);
      if (uVar6 == 1) {
        uVar6 = *(uint *)(instSlot + 4) >> 0x10 & 7;
        uVar6 = uVar6 << 0x16 | uVar6 << 0x13 | uVar6 << 0xd | *(uint *)(instSlot + 4) & 0xfe071fff;
        *(uint *)(instSlot + 4) = uVar6;
      }
      else if (uVar6 == 0) {
        uVar6 = *(uint *)(instSlot + 4) >> 0xd & 7;
        uVar6 = uVar6 << 0x16 | uVar6 << 0x13 | uVar6 << 0x10 | *(uint *)(instSlot + 4) & 0xfe00ffff;
        *(uint *)(instSlot + 4) = uVar6;
      }
      else if (uVar6 == 2) {
        uVar6 = *(uint *)(instSlot + 4) >> 0x13 & 7;
        uVar6 = uVar6 << 0x16 | uVar6 << 0x10 | uVar6 << 0xd | *(uint *)(instSlot + 4) & 0xfe381fff;
        *(uint *)(instSlot + 4) = uVar6;
      }
      else {
        if (uVar6 != 3) goto LAB_0005d81c;
        uVar6 = *(uint *)(instSlot + 4) >> 0x16 & 7;
        uVar6 = uVar6 << 0x13 | uVar6 << 0x10 | uVar6 << 0xd | *(uint *)(instSlot + 4) & 0xffc01fff;
        *(uint *)(instSlot + 4) = uVar6;
      }
    }
    else {
      if (extvsOperandDataTypeResult != 0x87c0) goto LAB_0005d850;
      extvsEncodeSourceSwizzle(shader,symbolList,src0Operand,instSlot + 4,uVar6);
LAB_0005d81c:
      uVar6 = *(uint *)(instSlot + 4);
    }
    uVar1 = 1;
    uVar6 = uVar6 & 0xfe001fff | 0x1248000;
    *(uint *)(instSlot + 0xc) = uVar6;
    *(uint *)(instSlot + 8) = uVar6;
  }
  else {
LAB_0005d850:
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

/* extvsEmitLit @ 0x5d870 (336 bytes) */
int extvsEmitLit(ctx, shader, instRecord)
  int ctx;
  int *shader;
  int instRecord;
{
  int instSlot;
  uint uVar1;
  undefined4 newInstArray;
  int instCount;
  int hwProgram;
  
  hwProgram = **(int **)(*(int *)(((unsigned char *)0x0000118c) + ctx) * 4 + *shader);
  instCount = *(int *)(hwProgram + 0x18);
  if (0x100 < instCount + 1U) {
    *(undefined1 *)(shader + 4) = 0;
    instCount = *(int *)(hwProgram + 0x18);
    if (*(uint *)(hwProgram + 0x20) < instCount + 1U) {
      newInstArray = (**(code **)(ctx + 0xc))(*(uint *)(hwProgram + 0x20) * 0x10 + 0x100);
      (**(code **)(((unsigned char *)0x00001344) + ctx))
                (newInstArray,*(undefined4 *)(hwProgram + 0x1c),*(int *)(hwProgram + 0x20) << 4);
      (**(code **)(ctx + 0x18))(*(undefined4 *)(hwProgram + 0x1c));
      *(undefined4 *)(hwProgram + 0x1c) = newInstArray;
      instCount = *(int *)(hwProgram + 0x18);
      *(int *)(hwProgram + 0x20) = *(int *)(hwProgram + 0x20) + 0x10;
    }
  }
  instSlot = instCount * 0x10 + *(int *)(hwProgram + 0x1c);
  extvsEncodeSourceOperand(ctx,shader,instRecord + 4,instSlot,4,1,0);
  extvsEncodeSourceSwizzle(shader,shader + 7,instRecord + 0x20,instSlot + 4,0);
  uVar1 = *(uint *)(instSlot + 4);
  *(uint *)(instSlot + 0xc) = uVar1;
  *(uint *)(instSlot + 4) = (uVar1 & 0x4000000) << 2 | (uVar1 & 0x70000) << 6 | uVar1 & 0xee3fffff;
  *(uint *)(instSlot + 8) = (uVar1 & 0x2000000) << 3 | (uVar1 & 0xe000) << 9 | uVar1 & 0xee3fffff;
  return 1;
}

/* extvsEmitDst @ 0x5d9c0 (824 bytes) */
int extvsEmitDst(ctx, shader, instRecord)
  int ctx;
  int *shader;
  int instRecord;
{
  int instSlot;
  int hwProgram;
  uint uVar1;
  int conflict;
  undefined4 uVar3;
  int src1Operand;
  int src0Operand;
  int *symbolList;
  int instCount;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined1 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined1 local_44;
  
  src0Operand = instRecord + 0x20;
  symbolList = shader + 7;
  src1Operand = instRecord + 0x3c;
  conflict = extvsOperandsConflictInBank(symbolList,src0Operand,src1Operand);
  if (conflict == 0) {
    hwProgram = **(int **)(*(int *)(((unsigned char *)0x0000118c) + ctx) * 4 + *shader);
    instCount = *(int *)(hwProgram + 0x18);
    if (0x100 < instCount + 1U) {
      *(undefined1 *)(shader + 4) = 0;
      instCount = *(int *)(hwProgram + 0x18);
      if (*(uint *)(hwProgram + 0x20) < instCount + 1U) {
        uVar3 = (**(code **)(ctx + 0xc))(*(uint *)(hwProgram + 0x20) * 0x10 + 0x100);
        (**(code **)(((unsigned char *)0x00001344) + ctx))
                  (uVar3,*(undefined4 *)(hwProgram + 0x1c),*(int *)(hwProgram + 0x20) << 4);
        (**(code **)(ctx + 0x18))(*(undefined4 *)(hwProgram + 0x1c));
        *(undefined4 *)(hwProgram + 0x1c) = uVar3;
        instCount = *(int *)(hwProgram + 0x18);
        *(int *)(hwProgram + 0x20) = *(int *)(hwProgram + 0x20) + 0x10;
      }
    }
    instSlot = instCount * 0x10 + *(int *)(hwProgram + 0x1c);
    extvsEncodeSourceOperand(ctx,shader,instRecord + 4,instSlot,5,0,0);
    extvsEncodeSourceSwizzle(shader,symbolList,src0Operand,instSlot + 4,0);
    extvsEncodeSourceSwizzle(shader,symbolList,src1Operand,instSlot + 8,0);
    uVar3 = 1;
    *(undefined4 *)(instSlot + 0xc) = *(undefined4 *)(instSlot + 8);
  }
  else {
    hwProgram = **(int **)(*(int *)(((unsigned char *)0x0000118c) + ctx) * 4 + *shader);
    instCount = *(int *)(hwProgram + 0x18);
    if (0x100 < instCount + 2U) {
      *(undefined1 *)(shader + 4) = 0;
      instCount = *(int *)(hwProgram + 0x18);
      if (*(uint *)(hwProgram + 0x20) < instCount + 2U) {
        uVar3 = (**(code **)(ctx + 0xc))(*(uint *)(hwProgram + 0x20) * 0x10 + 0x100);
        (**(code **)(((unsigned char *)0x00001344) + ctx))
                  (uVar3,*(undefined4 *)(hwProgram + 0x1c),*(int *)(hwProgram + 0x20) << 4);
        (**(code **)(ctx + 0x18))(*(undefined4 *)(hwProgram + 0x1c));
        *(undefined4 *)(hwProgram + 0x1c) = uVar3;
        instCount = *(int *)(hwProgram + 0x18);
        *(int *)(hwProgram + 0x20) = *(int *)(hwProgram + 0x20) + 0x10;
      }
    }
    instSlot = instCount * 0x10 + *(int *)(hwProgram + 0x1c);
    uVar3 = extvsAllocTempSlot(ctx,shader);
    local_78 = 3;
    local_60 = 0;
    local_64 = 1;
    local_70 = 1;
    local_6c = 1;
    local_68 = 1;
    local_74 = uVar3;
    extvsEncodeSourceOperand(ctx,shader,&local_78,instSlot,3,0,0);
    extvsEncodeSourceSwizzle(shader,symbolList,src0Operand,instSlot + 4,0);
    uVar1 = *(uint *)(instSlot + 4) & 0xfe001fff | 0x1248000;
    *(uint *)(instSlot + 0xc) = uVar1;
    *(uint *)(instSlot + 8) = uVar1;
    extvsEncodeSourceOperand(ctx,shader,instRecord + 4,instSlot + 0x10,5,0,0);
    local_5c = 3;
    local_44 = 0;
    local_54 = 0x87d5;
    local_50 = 0x87d6;
    local_4c = 0x87d7;
    local_48 = 0x87d8;
    local_58 = uVar3;
    extvsEncodeSourceSwizzle(shader,symbolList,&local_5c,instSlot + 0x14,0);
    extvsEncodeSourceSwizzle(shader,symbolList,src1Operand,instSlot + 0x18,0);
    uVar3 = 2;
    *(undefined4 *)(instSlot + 0x1c) = *(undefined4 *)(instSlot + 0x18);
  }
  return uVar3;
}

/* extvsEmitExpp @ 0x5dd00 (324 bytes) */
int extvsEmitExpp(ctx, shader, instRecord)
  int ctx;
  int *shader;
  int instRecord;
{
  int instSlot;
  undefined4 newInstArray;
  uint uVar2;
  int instCount;
  int hwProgram;
  
  hwProgram = **(int **)(*(int *)(((unsigned char *)0x0000118c) + ctx) * 4 + *shader);
  instCount = *(int *)(hwProgram + 0x18);
  if (0x100 < instCount + 1U) {
    *(undefined1 *)(shader + 4) = 0;
    instCount = *(int *)(hwProgram + 0x18);
    if (*(uint *)(hwProgram + 0x20) < instCount + 1U) {
      newInstArray = (**(code **)(ctx + 0xc))(*(uint *)(hwProgram + 0x20) * 0x10 + 0x100);
      (**(code **)(((unsigned char *)0x00001344) + ctx))
                (newInstArray,*(undefined4 *)(hwProgram + 0x1c),*(int *)(hwProgram + 0x20) << 4);
      (**(code **)(ctx + 0x18))(*(undefined4 *)(hwProgram + 0x1c));
      *(undefined4 *)(hwProgram + 0x1c) = newInstArray;
      instCount = *(int *)(hwProgram + 0x18);
      *(int *)(hwProgram + 0x20) = *(int *)(hwProgram + 0x20) + 0x10;
    }
  }
  instSlot = instCount * 0x10 + *(int *)(hwProgram + 0x1c);
  extvsEncodeSourceOperand(ctx,shader,instRecord + 4,instSlot,1,1,0);
  extvsEncodeSourceSwizzle(shader,shader + 7,instRecord + 0x20,instSlot + 4,0);
  uVar2 = *(uint *)(instSlot + 4);
  uVar2 = (uVar2 & 0x2000000) << 3 | (uVar2 & 0xe000) << 9 | uVar2 & 0xee3fffff;
  *(uint *)(instSlot + 0xc) = uVar2;
  *(uint *)(instSlot + 4) = uVar2;
  *(uint *)(instSlot + 8) = uVar2;
  return 1;
}

/* extvsEmitLogp @ 0x5de50 (324 bytes) */
int extvsEmitLogp(ctx, shader, instRecord)
  int ctx;
  int *shader;
  int instRecord;
{
  int instSlot;
  undefined4 newInstArray;
  uint uVar2;
  int instCount;
  int hwProgram;
  
  hwProgram = **(int **)(*(int *)(((unsigned char *)0x0000118c) + ctx) * 4 + *shader);
  instCount = *(int *)(hwProgram + 0x18);
  if (0x100 < instCount + 1U) {
    *(undefined1 *)(shader + 4) = 0;
    instCount = *(int *)(hwProgram + 0x18);
    if (*(uint *)(hwProgram + 0x20) < instCount + 1U) {
      newInstArray = (**(code **)(ctx + 0xc))(*(uint *)(hwProgram + 0x20) * 0x10 + 0x100);
      (**(code **)(((unsigned char *)0x00001344) + ctx))
                (newInstArray,*(undefined4 *)(hwProgram + 0x1c),*(int *)(hwProgram + 0x20) << 4);
      (**(code **)(ctx + 0x18))(*(undefined4 *)(hwProgram + 0x1c));
      *(undefined4 *)(hwProgram + 0x1c) = newInstArray;
      instCount = *(int *)(hwProgram + 0x18);
      *(int *)(hwProgram + 0x20) = *(int *)(hwProgram + 0x20) + 0x10;
    }
  }
  instSlot = instCount * 0x10 + *(int *)(hwProgram + 0x1c);
  extvsEncodeSourceOperand(ctx,shader,instRecord + 4,instSlot,2,1,0);
  extvsEncodeSourceSwizzle(shader,shader + 7,instRecord + 0x20,instSlot + 4,0);
  uVar2 = *(uint *)(instSlot + 4);
  uVar2 = (uVar2 & 0x2000000) << 3 | (uVar2 & 0xe000) << 9 | uVar2 & 0xee3fffff;
  *(uint *)(instSlot + 0xc) = uVar2;
  *(uint *)(instSlot + 4) = uVar2;
  *(uint *)(instSlot + 8) = uVar2;
  return 1;
}

/* extvsEmitMova @ 0x5dfa0 (304 bytes) */
int extvsEmitMova(ctx, shader, instRecord)
  int ctx;
  int *shader;
  int instRecord;
{
  int instSlot;
  undefined4 newInstArray;
  int instCount;
  int hwProgram;
  
  hwProgram = **(int **)(*(int *)(((unsigned char *)0x0000118c) + ctx) * 4 + *shader);
  instCount = *(int *)(hwProgram + 0x18);
  if (0x100 < instCount + 1U) {
    *(undefined1 *)(shader + 4) = 0;
    instCount = *(int *)(hwProgram + 0x18);
    if (*(uint *)(hwProgram + 0x20) < instCount + 1U) {
      newInstArray = (**(code **)(ctx + 0xc))(*(uint *)(hwProgram + 0x20) * 0x10 + 0x100);
      (**(code **)(((unsigned char *)0x00001344) + ctx))
                (newInstArray,*(undefined4 *)(hwProgram + 0x1c),*(int *)(hwProgram + 0x20) << 4);
      (**(code **)(ctx + 0x18))(*(undefined4 *)(hwProgram + 0x1c));
      *(undefined4 *)(hwProgram + 0x1c) = newInstArray;
      instCount = *(int *)(hwProgram + 0x18);
      *(int *)(hwProgram + 0x20) = *(int *)(hwProgram + 0x20) + 0x10;
    }
  }
  instSlot = instCount * 0x10 + *(int *)(hwProgram + 0x1c);
  extvsEncodeSourceOperand(ctx,shader,instRecord + 4,instSlot,0xd,0,0);
  extvsEncodeSourceSwizzle(shader,shader + 7,instRecord + 0x20,instSlot + 4,0);
  *(undefined4 *)(instSlot + 0xc) = *(undefined4 *)(instSlot + 4);
  *(undefined4 *)(instSlot + 8) = *(undefined4 *)(instSlot + 4);
  return 1;
}

/* extvsEmitFogOutput @ 0x5e0d0 (1676 bytes) */
int extvsEmitFogOutput(ctx, shader, instRecord)
  int ctx;
  int *shader;
  uint *instRecord;
{
  short sVar1;
  undefined4 uVar2;
  int hwProgram;
  int *symbolList;
  int iVar5;
  int instCount;
  undefined4 local_a8;
  uint local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  uint local_94;
  undefined1 local_90;
  undefined4 local_8c;
  uint local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined1 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined1 local_58;
  
  iVar5 = *(int *)(*(int *)(ctx + 4) + 0x10);
  hwProgram = **(int **)(*(int *)(((unsigned char *)0x0000118c) + ctx) * 4 + *shader);
  uVar2 = *(undefined4 *)(hwProgram + 0x60);
  local_a4 = extvsAllocTempSlot(ctx,shader);
  *instRecord = (local_a4 & 0x7f) << 0xd | *instRecord & 0xfff010ff | 0x100000;
  sVar1 = *(short *)(((unsigned char *)0x00002e04) + iVar5);
  local_88 = local_a4;
  local_6c = uVar2;
  if (sVar1 == 0x801) {
    iVar5 = **(int **)(*(int *)(((unsigned char *)0x0000118c) + ctx) * 4 + *shader);
    instCount = *(int *)(iVar5 + 0x18);
    if (0x100 < instCount + 3U) {
      *(undefined1 *)(shader + 4) = 0;
      instCount = *(int *)(iVar5 + 0x18);
      if (*(uint *)(iVar5 + 0x20) < instCount + 3U) {
        uVar2 = (**(code **)(ctx + 0xc))(*(uint *)(iVar5 + 0x20) * 0x10 + 0x100);
        (**(code **)(((unsigned char *)0x00001344) + ctx))
                  (uVar2,*(undefined4 *)(iVar5 + 0x1c),*(int *)(iVar5 + 0x20) << 4);
        (**(code **)(ctx + 0x18))(*(undefined4 *)(iVar5 + 0x1c));
        *(undefined4 *)(iVar5 + 0x1c) = uVar2;
        instCount = *(int *)(iVar5 + 0x18);
        *(int *)(iVar5 + 0x20) = *(int *)(iVar5 + 0x20) + 0x10;
      }
    }
    local_9c = 0;
    local_98 = 0;
    local_94 = 0;
    local_90 = 0;
    local_a8 = 3;
    iVar5 = instCount * 0x10 + *(int *)(iVar5 + 0x1c);
    local_a0 = 1;
    symbolList = shader + 7;
    extvsEncodeSourceOperand(ctx,shader,&local_a8,iVar5,2,0,0);
    local_8c = 3;
    local_74 = 0;
    local_78 = 0x87d5;
    local_84 = 0x87d5;
    local_80 = 0x87d5;
    local_7c = 0x87d5;
    extvsEncodeSourceSwizzle(shader,symbolList,&local_8c,iVar5 + 4,0);
    extvsEncodeSourceSwizzle(shader,symbolList,&local_8c,iVar5 + 8,0);
    *(undefined4 *)(iVar5 + 0xc) = *(undefined4 *)(iVar5 + 8);
    extvsEncodeSourceOperand(ctx,shader,&local_a8,iVar5 + 0x10,2,0,0);
    extvsEncodeSourceSwizzle(shader,symbolList,&local_8c,iVar5 + 0x14,0);
    local_58 = 0;
    local_70 = 4;
    local_5c = 0x87d7;
    local_68 = 0x87d7;
    local_64 = 0x87d7;
    local_60 = 0x87d7;
    extvsEncodeSourceSwizzle(shader,symbolList,&local_70,iVar5 + 0x18,0);
    *(undefined4 *)(iVar5 + 0x1c) = *(undefined4 *)(iVar5 + 0x18);
    local_a8 = 1;
    local_a4 = 0x87bd;
    local_a0 = 0;
    local_9c = 0;
    local_98 = 0;
    local_94 = (uint)*(byte *)(hwProgram + 0x42);
    local_90 = 0;
    extvsEncodeSourceOperand(ctx,shader,&local_a8,iVar5 + 0x20,3,1,0);
    extvsEncodeSourceSwizzle(shader,symbolList,&local_8c,iVar5 + 0x24,0);
    uVar2 = 3;
    *(undefined4 *)(iVar5 + 0x2c) = *(undefined4 *)(iVar5 + 0x24);
    *(undefined4 *)(iVar5 + 0x28) = *(undefined4 *)(iVar5 + 0x24);
  }
  else if (sVar1 == 0x2601) {
    iVar5 = **(int **)(*(int *)(((unsigned char *)0x0000118c) + ctx) * 4 + *shader);
    instCount = *(int *)(iVar5 + 0x18);
    if (0x100 < instCount + 1U) {
      *(undefined1 *)(shader + 4) = 0;
      instCount = *(int *)(iVar5 + 0x18);
      if (*(uint *)(iVar5 + 0x20) < instCount + 1U) {
        uVar2 = (**(code **)(ctx + 0xc))(*(uint *)(iVar5 + 0x20) * 0x10 + 0x100);
        (**(code **)(((unsigned char *)0x00001344) + ctx))
                  (uVar2,*(undefined4 *)(iVar5 + 0x1c),*(int *)(iVar5 + 0x20) << 4);
        (**(code **)(ctx + 0x18))(*(undefined4 *)(iVar5 + 0x1c));
        *(undefined4 *)(iVar5 + 0x1c) = uVar2;
        instCount = *(int *)(iVar5 + 0x18);
        *(int *)(iVar5 + 0x20) = *(int *)(iVar5 + 0x20) + 0x10;
      }
    }
    local_a0 = 0;
    local_9c = 0;
    local_a8 = 1;
    local_98 = 0;
    local_a4 = 0x87bd;
    iVar5 = instCount * 0x10 + *(int *)(iVar5 + 0x1c);
    local_94 = (uint)*(byte *)(hwProgram + 0x42);
    local_90 = 0;
    extvsEncodeSourceOperand(ctx,shader,&local_a8,iVar5,1,0,0);
    local_84 = 0x87dd;
    local_78 = 0x87dd;
    local_74 = 0;
    local_80 = 0x87de;
    local_8c = 3;
    local_7c = 0x87d5;
    extvsEncodeSourceSwizzle(shader,shader + 7,&local_8c,iVar5 + 4,0);
    local_5c = 0x87dd;
    local_58 = 0;
    local_68 = 0x87dd;
    local_64 = 0x87d6;
    local_60 = 0x87d7;
    local_70 = 4;
    extvsEncodeSourceSwizzle(shader,shader + 7,&local_70,iVar5 + 8,0);
    uVar2 = 1;
    *(undefined4 *)(iVar5 + 0xc) = *(undefined4 *)(iVar5 + 8);
  }
  else {
    uVar2 = 0;
    if (sVar1 == 0x800) {
      iVar5 = **(int **)(*(int *)(((unsigned char *)0x0000118c) + ctx) * 4 + *shader);
      instCount = *(int *)(iVar5 + 0x18);
      if (0x100 < instCount + 2U) {
        *(undefined1 *)(shader + 4) = 0;
        instCount = *(int *)(iVar5 + 0x18);
        if (*(uint *)(iVar5 + 0x20) < instCount + 2U) {
          uVar2 = (**(code **)(ctx + 0xc))(*(uint *)(iVar5 + 0x20) * 0x10 + 0x100);
          (**(code **)(((unsigned char *)0x00001344) + ctx))
                    (uVar2,*(undefined4 *)(iVar5 + 0x1c),*(int *)(iVar5 + 0x20) << 4);
          (**(code **)(ctx + 0x18))(*(undefined4 *)(iVar5 + 0x1c));
          *(undefined4 *)(iVar5 + 0x1c) = uVar2;
          instCount = *(int *)(iVar5 + 0x18);
          *(int *)(iVar5 + 0x20) = *(int *)(iVar5 + 0x20) + 0x10;
        }
      }
      local_9c = 0;
      local_98 = 0;
      local_94 = 0;
      local_90 = 0;
      local_a8 = 3;
      iVar5 = instCount * 0x10 + *(int *)(iVar5 + 0x1c);
      local_a0 = 1;
      symbolList = shader + 7;
      extvsEncodeSourceOperand(ctx,shader,&local_a8,iVar5,2,0,0);
      local_8c = 3;
      local_74 = 0;
      local_78 = 0x87d5;
      local_84 = 0x87d5;
      local_80 = 0x87d5;
      local_7c = 0x87d5;
      extvsEncodeSourceSwizzle(shader,symbolList,&local_8c,iVar5 + 4,0);
      local_58 = 0;
      local_70 = 4;
      local_5c = 0x87d7;
      local_68 = 0x87d7;
      local_64 = 0x87d7;
      local_60 = 0x87d7;
      extvsEncodeSourceSwizzle(shader,symbolList,&local_70,iVar5 + 8,0);
      *(undefined4 *)(iVar5 + 0xc) = *(undefined4 *)(iVar5 + 8);
      local_a8 = 1;
      local_a4 = 0x87bd;
      local_a0 = 0;
      local_9c = 0;
      local_98 = 0;
      local_94 = (uint)*(byte *)(hwProgram + 0x42);
      local_90 = 0;
      extvsEncodeSourceOperand(ctx,shader,&local_a8,iVar5 + 0x10,3,1,0);
      extvsEncodeSourceSwizzle(shader,symbolList,&local_8c,iVar5 + 0x14,0);
      uVar2 = 2;
      *(undefined4 *)(iVar5 + 0x1c) = *(undefined4 *)(iVar5 + 0x14);
      *(undefined4 *)(iVar5 + 0x18) = *(undefined4 *)(iVar5 + 0x14);
    }
  }
  return uVar2;
}

/* popFirstNonNull32 @ 0x5e770 (108 bytes) */
int popFirstNonNull32(pointerArray)
  int pointerArray;
{
  uint position;
  int iVar2;
  undefined4 *puVar3;
  int entry;
  uint uVar5;
  
  position = 0;
  while( true ) {
    entry = *(int *)(pointerArray + position * 4);
    if ((entry != 0) && (uVar5 = position + 1, uVar5 < 0x20)) {
      iVar2 = 0x20 - uVar5;
      puVar3 = (undefined4 *)(pointerArray + uVar5 * 4);
      do {
        puVar3[-1] = *puVar3;
        puVar3 = puVar3 + 1;
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
    }
    position = position + 1;
    if (0x1f < position) break;
    if (entry != 0) {
      return entry;
    }
  }
  return entry;
}

/* extvsAssignVertexInputs @ 0x5e7f0 (3156 bytes) */
int extvsAssignVertexInputs(ctx, shader)
  int ctx;
  int *shader;
{
  uint instIndex;
  int scalarVariantCount;
  int matrixVariantCount;
  bool bVar1;
  bool bVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int vectorVariantCount;
  int programState;
  undefined4 *puVar12;
  uint uVar13;
  uint uVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  int boundVariants [32];
  int scalarVariants [32];
  int vectorVariants [32];
  int matrixVariants [34];
  
  iVar7 = 0;
  iVar15 = 0x20;
  programState = **(int **)(*(int *)(((unsigned char *)0x0000118c) + ctx) * 4 + *shader);
  *(undefined4 *)(programState + 0x234) = 1;
  do {
    *(undefined4 *)((int)boundVariants + iVar7) = 0;
    *(undefined4 *)(iVar7 + (int)scalarVariants) = 0;
    *(undefined4 *)(iVar7 + (int)vectorVariants) = 0;
    *(undefined4 *)(iVar7 + (int)matrixVariants) = 0;
    iVar7 = iVar7 + 4;
    iVar15 = iVar15 + -1;
  } while (iVar15 != 0);
  if (shader[5] == 0) {
    scalarVariantCount = 0;
    vectorVariantCount = 0;
    matrixVariantCount = 0;
  }
  else {
    iVar7 = 0;
    instIndex = 0;
    scalarVariantCount = 0;
    vectorVariantCount = 0;
    matrixVariantCount = 0;
    do {
      iVar5 = instIndex * 0x74;
      iVar17 = shader[6];
      iVar16 = iVar7;
      if (((*(int *)(iVar5 + iVar17 + 0x20) == 2) &&
          (iVar4 = *(int *)(iVar5 + iVar17 + 0x24) * 0x54 + shader[8],
          *(int *)(iVar4 + 0x28) == 0x87c1)) && (*(char *)(iVar4 + 0x3d) == '\0')) {
        if ((*(char *)(iVar4 + 0x44) == '\0') || (*(int *)(iVar4 + 0x48) == 0x12)) {
          iVar7 = *(int *)(iVar4 + 0x24);
          if (iVar7 == 0x87bf) {
            vectorVariants[vectorVariantCount] = iVar4;
            vectorVariantCount = vectorVariantCount + 1;
          }
          else if (iVar7 == 0x87c0) {
            matrixVariants[matrixVariantCount] = iVar4;
            matrixVariantCount = matrixVariantCount + 1;
          }
          else if (iVar7 == 0x87be) {
            scalarVariants[scalarVariantCount] = iVar4;
            scalarVariantCount = scalarVariantCount + 1;
          }
        }
        else {
          iVar16 = iVar7 + 1;
          boundVariants[iVar7] = iVar4;
          switch(*(undefined4 *)(iVar4 + 0x48)) {
          case 0:
            *(undefined1 *)(programState + 0x2c) = 1;
            break;
          case 1:
            *(undefined1 *)(programState + 0x2d) = 1;
            shader[0xc] = shader[0xc] | 8;
            break;
          case 2:
            iVar7 = *(int *)(iVar4 + 0x4c);
            *(undefined1 *)(iVar7 + programState + 0x2e) = 1;
            *(undefined1 *)((int)shader + iVar7 + 0x34) = 1;
            shader[0xc] = shader[0xc] | 4;
            break;
          case 3:
            *(undefined1 *)(programState + 0x36) = 1;
            shader[0xc] = shader[0xc] | 1;
            break;
          case 4:
            *(undefined1 *)(programState + 0x37) = 1;
            break;
          case 5:
            *(undefined1 *)(programState + 0x38) = 1;
            break;
          case 6:
            *(undefined1 *)(programState + 0x39) = 1;
            break;
          case 7:
            *(undefined1 *)(programState + 0x36) = 1;
            break;
          case 8:
            *(undefined1 *)(programState + 0x3b) = 1;
            break;
          case 9:
            *(undefined1 *)(programState + 0x3c) = 1;
            break;
          case 10:
            *(undefined1 *)(programState + 0x3d) = 1;
            break;
          case 0xb:
            *(undefined1 *)(programState + 0x3a) = 1;
            break;
          case 0xc:
            *(undefined1 *)(programState + 0x40) = 1;
            break;
          case 0xd:
            *(undefined1 *)(programState + 0x41) = 1;
            break;
          case 0xe:
            *(undefined1 *)(programState + 0x37) = 1;
            shader[0xc] = shader[0xc] | 2;
            break;
          case 0xf:
            *(undefined1 *)(programState + 0x3e) = 1;
            shader[0xc] = shader[0xc] | 0x40;
            break;
          case 0x10:
            *(undefined1 *)(programState + 0x3f) = 1;
            shader[0xc] = shader[0xc] | 0x80;
          }
        }
        *(undefined1 *)(iVar4 + 0x3d) = 1;
        iVar17 = shader[6];
        shader[0x16] = shader[0x16] + 1;
      }
      iVar4 = iVar16;
      if (((*(int *)(iVar5 + iVar17 + 0x3c) == 2) &&
          (iVar7 = *(int *)(iVar5 + iVar17 + 0x40) * 0x54 + shader[8],
          *(int *)(iVar7 + 0x28) == 0x87c1)) && (*(char *)(iVar7 + 0x3d) == '\0')) {
        if ((*(char *)(iVar7 + 0x44) == '\0') || (*(int *)(iVar7 + 0x48) == 0x12)) {
          iVar16 = *(int *)(iVar7 + 0x24);
          if (iVar16 == 0x87bf) {
            vectorVariants[vectorVariantCount] = iVar7;
            vectorVariantCount = vectorVariantCount + 1;
          }
          else if (iVar16 == 0x87c0) {
            matrixVariants[matrixVariantCount] = iVar7;
            matrixVariantCount = matrixVariantCount + 1;
          }
          else if (iVar16 == 0x87be) {
            scalarVariants[scalarVariantCount] = iVar7;
            scalarVariantCount = scalarVariantCount + 1;
          }
        }
        else {
          iVar4 = iVar16 + 1;
          boundVariants[iVar16] = iVar7;
          switch(*(undefined4 *)(iVar7 + 0x48)) {
          case 0:
            *(undefined1 *)(programState + 0x2c) = 1;
            break;
          case 1:
            *(undefined1 *)(programState + 0x2d) = 1;
            shader[0xc] = shader[0xc] | 8;
            break;
          case 2:
            iVar16 = *(int *)(iVar7 + 0x4c);
            *(undefined1 *)(iVar16 + programState + 0x2e) = 1;
            *(undefined1 *)((int)shader + iVar16 + 0x34) = 1;
            shader[0xc] = shader[0xc] | 4;
            break;
          case 3:
            *(undefined1 *)(programState + 0x36) = 1;
            shader[0xc] = shader[0xc] | 1;
            break;
          case 4:
            *(undefined1 *)(programState + 0x37) = 1;
            break;
          case 5:
            *(undefined1 *)(programState + 0x38) = 1;
            break;
          case 6:
            *(undefined1 *)(programState + 0x39) = 1;
            break;
          case 7:
            *(undefined1 *)(programState + 0x36) = 1;
            break;
          case 8:
            *(undefined1 *)(programState + 0x3b) = 1;
            break;
          case 9:
            *(undefined1 *)(programState + 0x3c) = 1;
            break;
          case 10:
            *(undefined1 *)(programState + 0x3d) = 1;
            break;
          case 0xb:
            *(undefined1 *)(programState + 0x3a) = 1;
            break;
          case 0xc:
            *(undefined1 *)(programState + 0x40) = 1;
            break;
          case 0xd:
            *(undefined1 *)(programState + 0x41) = 1;
            break;
          case 0xe:
            *(undefined1 *)(programState + 0x37) = 1;
            shader[0xc] = shader[0xc] | 2;
            break;
          case 0xf:
            *(undefined1 *)(programState + 0x3e) = 1;
            shader[0xc] = shader[0xc] | 0x40;
            break;
          case 0x10:
            *(undefined1 *)(programState + 0x3f) = 1;
            shader[0xc] = shader[0xc] | 0x80;
          }
        }
        *(undefined1 *)(iVar7 + 0x3d) = 1;
        iVar17 = shader[6];
        shader[0x16] = shader[0x16] + 1;
      }
      iVar7 = iVar4;
      if (((*(int *)(iVar5 + iVar17 + 0x58) == 2) &&
          (iVar16 = *(int *)(iVar5 + iVar17 + 0x5c) * 0x54 + shader[8],
          *(int *)(iVar16 + 0x28) == 0x87c1)) && (*(char *)(iVar16 + 0x3d) == '\0')) {
        if ((*(char *)(iVar16 + 0x44) == '\0') || (*(int *)(iVar16 + 0x48) == 0x12)) {
          iVar5 = *(int *)(iVar16 + 0x24);
          if (iVar5 == 0x87bf) {
            vectorVariants[vectorVariantCount] = iVar16;
            vectorVariantCount = vectorVariantCount + 1;
          }
          else if (iVar5 == 0x87c0) {
            matrixVariants[matrixVariantCount] = iVar16;
            matrixVariantCount = matrixVariantCount + 1;
          }
          else if (iVar5 == 0x87be) {
            scalarVariants[scalarVariantCount] = iVar16;
            scalarVariantCount = scalarVariantCount + 1;
          }
        }
        else {
          iVar7 = iVar4 + 1;
          boundVariants[iVar4] = iVar16;
          switch(*(undefined4 *)(iVar16 + 0x48)) {
          case 0:
            *(undefined1 *)(programState + 0x2c) = 1;
            break;
          case 1:
            *(undefined1 *)(programState + 0x2d) = 1;
            shader[0xc] = shader[0xc] | 8;
            break;
          case 2:
            iVar5 = *(int *)(iVar16 + 0x4c);
            *(undefined1 *)(iVar5 + programState + 0x2e) = 1;
            *(undefined1 *)((int)shader + iVar5 + 0x34) = 1;
            shader[0xc] = shader[0xc] | 4;
            break;
          case 3:
            *(undefined1 *)(programState + 0x36) = 1;
            shader[0xc] = shader[0xc] | 1;
            break;
          case 4:
            *(undefined1 *)(programState + 0x37) = 1;
            break;
          case 5:
            *(undefined1 *)(programState + 0x38) = 1;
            break;
          case 6:
            *(undefined1 *)(programState + 0x39) = 1;
            break;
          case 7:
            *(undefined1 *)(programState + 0x36) = 1;
            break;
          case 8:
            *(undefined1 *)(programState + 0x3b) = 1;
            break;
          case 9:
            *(undefined1 *)(programState + 0x3c) = 1;
            break;
          case 10:
            *(undefined1 *)(programState + 0x3d) = 1;
            break;
          case 0xb:
            *(undefined1 *)(programState + 0x3a) = 1;
            break;
          case 0xc:
            *(undefined1 *)(programState + 0x40) = 1;
            break;
          case 0xd:
            *(undefined1 *)(programState + 0x41) = 1;
            break;
          case 0xe:
            *(undefined1 *)(programState + 0x37) = 1;
            shader[0xc] = shader[0xc] | 2;
            break;
          case 0xf:
            *(undefined1 *)(programState + 0x3e) = 1;
            shader[0xc] = shader[0xc] | 0x40;
            break;
          case 0x10:
            *(undefined1 *)(programState + 0x3f) = 1;
            shader[0xc] = shader[0xc] | 0x80;
          }
        }
        *(undefined1 *)(iVar16 + 0x3d) = 1;
        shader[0x16] = shader[0x16] + 1;
      }
      instIndex = instIndex + 1;
    } while (instIndex < (uint)shader[5]);
  }
  if (*(char *)(programState + 0x2c) != '\0') {
    iVar7 = 0;
    iVar16 = 0x20;
    do {
      iVar5 = *(int *)((int)boundVariants + iVar7);
      if (((iVar5 == 0) || (*(int *)(iVar5 + 0x48) != 0)) || (*(int *)(iVar5 + 0x4c) != 0)) {
        iVar5 = 0;
      }
      iVar16 = iVar16 + -1;
    } while ((iVar16 != 0) && (iVar7 = iVar7 + 4, iVar5 == 0));
    *(undefined4 *)(iVar5 + 4) = 0;
    *(undefined4 *)(programState + 0x198) = 0;
    *(undefined1 *)(*(int *)(programState + 0x24) + 0x10) = 1;
  }
  bVar1 = vectorVariantCount == 0;
  uVar14 = 2;
  uVar13 = 0;
  DAT_001dba98 = 0xe;
  iVar7 = 0x50;
  puVar12 = &DAT_001dba44;
  do {
    if (!bVar1) {
      vectorVariantCount = vectorVariantCount + -1;
      puVar6 = (undefined4 *)((int (*)())popFirstNonNull32)(vectorVariants);
      uVar3 = *puVar12;
      bVar1 = vectorVariantCount == 0;
      puVar6[1] = uVar14;
      puVar12 = puVar12 + 1;
      uVar14 = uVar14 + 1;
      *puVar6 = uVar3;
      iVar16 = iVar7 + *(int *)(programState + 0x24);
      iVar7 = iVar7 + 0x28;
      *(undefined1 *)(iVar16 + 0x10) = 1;
      *(uint *)(programState + 0x234) = 4 << (uVar13 & 0x3f) | *(uint *)(programState + 0x234);
    }
    bVar2 = uVar13 != 7;
    uVar13 = uVar13 + 1;
  } while (bVar2);
  iVar7 = uVar14 * 0x28;
  uVar13 = 0;
  puVar12 = (undefined4 *)(uVar14 * 4 + 0x1dba3c);
  do {
    if (!bVar1) {
      vectorVariantCount = vectorVariantCount + -1;
      puVar6 = (undefined4 *)((int (*)())popFirstNonNull32)(vectorVariants);
      uVar3 = *puVar12;
      bVar1 = vectorVariantCount == 0;
      puVar6[1] = uVar14;
      puVar12 = puVar12 + 1;
      uVar14 = uVar14 + 1;
      *puVar6 = uVar3;
      iVar16 = iVar7 + *(int *)(programState + 0x24);
      iVar7 = iVar7 + 0x28;
      *(undefined1 *)(iVar16 + 0x10) = 1;
      *(uint *)(programState + 0x234) = 0x400 << (uVar13 & 0x3f) | *(uint *)(programState + 0x234);
    }
    bVar2 = uVar13 != 7;
    uVar13 = uVar13 + 1;
  } while (bVar2);
  uVar13 = uVar14;
  if (*(char *)(uVar14 * 0x28 + *(int *)(programState + 0x24) + 0x10) != '\0') {
    uVar8 = *(uint *)(programState + 0x234);
    uVar13 = uVar14 + 1;
    *(uint *)(programState + 0x234) = uVar8 | 0x40000;
    if (*(char *)(uVar13 * 0x28 + *(int *)(programState + 0x24) + 0x10) != '\0') {
      uVar13 = uVar14 + 2;
      *(uint *)(programState + 0x234) = uVar8 | 0xc0000;
    }
  }
  if (!bVar1) {
    vectorVariantCount = vectorVariantCount + -1;
    puVar12 = (undefined4 *)((int (*)())popFirstNonNull32)(vectorVariants);
    iVar7 = uVar13 * 0x28;
    bVar1 = vectorVariantCount == 0;
    uVar3 = *(undefined4 *)(uVar13 * 4 + 0x1dba3c);
    puVar12[1] = uVar13;
    uVar13 = uVar13 + 1;
    *puVar12 = uVar3;
    *(undefined1 *)(iVar7 + *(int *)(programState + 0x24) + 0x10) = 1;
    *(uint *)(programState + 0x234) = *(uint *)(programState + 0x234) | 0x100000;
  }
  if (((scalarVariantCount != 0) || (!bVar1)) || (matrixVariantCount != 0)) {
    *(undefined1 *)(shader + 4) = 0;
    if (scalarVariantCount != 0) {
      iVar16 = uVar13 * 0x28;
      iVar7 = 0;
      do {
        iVar5 = ((int (*)())popFirstNonNull32)(scalarVariants);
        if (*(uint *)(programState + 0x28) <= uVar13) {
          uVar3 = (**(code **)(ctx + 0x10))(*(uint *)(programState + 0x28) + 0x10,0x28);
          (**(code **)(((unsigned char *)0x00001344) + ctx))
                    (uVar3,*(undefined4 *)(programState + 0x24),*(int *)(programState + 0x28) * 0x28);
          (**(code **)(ctx + 0x18))(*(undefined4 *)(programState + 0x24));
          *(undefined4 *)(programState + 0x24) = uVar3;
          *(int *)(programState + 0x28) = *(int *)(programState + 0x28) + 0x10;
        }
        *(uint *)(iVar5 + 4) = uVar13;
        *(undefined4 *)(iVar5 + 8) = 0;
        iVar7 = iVar7 + 1;
        uVar13 = uVar13 + 1;
        iVar5 = iVar16 + *(int *)(programState + 0x24);
        iVar16 = iVar16 + 0x28;
        *(undefined1 *)(iVar5 + 0x10) = 1;
      } while (scalarVariantCount != iVar7);
    }
    if (!bVar1) {
      iVar9 = uVar13 * 0x28;
      iVar7 = 0;
      do {
        iVar16 = ((int (*)())popFirstNonNull32)(vectorVariants);
        if (*(uint *)(programState + 0x28) <= uVar13) {
          uVar3 = (**(code **)(ctx + 0x10))(*(uint *)(programState + 0x28) + 0x10,0x28);
          (**(code **)(((unsigned char *)0x00001344) + ctx))
                    (uVar3,*(undefined4 *)(programState + 0x24),*(int *)(programState + 0x28) * 0x28);
          (**(code **)(ctx + 0x18))(*(undefined4 *)(programState + 0x24));
          *(undefined4 *)(programState + 0x24) = uVar3;
          *(int *)(programState + 0x28) = *(int *)(programState + 0x28) + 0x10;
        }
        *(uint *)(iVar16 + 4) = uVar13;
        iVar7 = iVar7 + 1;
        uVar13 = uVar13 + 1;
        iVar16 = *(int *)(programState + 0x24) + iVar9;
        iVar9 = iVar9 + 0x28;
        *(undefined1 *)(iVar16 + 0x10) = 1;
      } while (vectorVariantCount != iVar7);
    }
    if (matrixVariantCount != 0) {
      iVar9 = uVar13 * 0x28;
      iVar7 = 0;
      do {
        vectorVariantCount = ((int (*)())popFirstNonNull32)(matrixVariants);
        if (*(uint *)(programState + 0x28) <= uVar13 + 3) {
          uVar3 = (**(code **)(ctx + 0x10))(*(uint *)(programState + 0x28) + 0x10,0x28);
          (**(code **)(((unsigned char *)0x00001344) + ctx))
                    (uVar3,*(undefined4 *)(programState + 0x24),*(int *)(programState + 0x28) * 0x28);
          (**(code **)(ctx + 0x18))(*(undefined4 *)(programState + 0x24));
          *(undefined4 *)(programState + 0x24) = uVar3;
          *(int *)(programState + 0x28) = *(int *)(programState + 0x28) + 0x10;
        }
        iVar5 = 0;
        iVar17 = 4;
        iVar16 = iVar9;
        do {
          iVar4 = uVar13 + iVar5;
          iVar5 = iVar5 + 1;
          *(int *)(vectorVariantCount + 0x10) = iVar4;
          vectorVariantCount = vectorVariantCount + 4;
          iVar4 = iVar16 + *(int *)(programState + 0x24);
          iVar16 = iVar16 + 0x28;
          *(undefined1 *)(iVar4 + 0x10) = 1;
          iVar17 = iVar17 + -1;
        } while (iVar17 != 0);
        iVar7 = iVar7 + 1;
        uVar13 = uVar13 + 4;
        iVar9 = iVar9 + 0xa0;
      } while (iVar7 != matrixVariantCount);
    }
  }
  *(uint *)(programState + 0x2a4) = uVar13;
  return;
}

/* FUN_0005f540 @ 0x5f540 (688 bytes) */
int FUN_0005f540(param_1, param_2)
  int param_1;
  int *param_2;
{
  uint uVar1;
  uint *puVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  uint uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 auStack_2c [3];
  
  iVar11 = **(int **)(*(int *)(((unsigned char *)0x0000118c) + param_1) * 4 + *param_2);
  if (*(char *)(param_2 + 4) != '\0') {
    iVar3 = (**(code **)(param_1 + 0xc))(*(int *)(iVar11 + 0x18) << 4);
    puVar4 = (undefined4 *)
             FUN_000774c0(*(undefined4 *)(param_1 + 0xc),*(undefined4 *)(param_1 + 0x18));
    puVar4[8] = 0;
    puVar4[9] = 0;
    puVar4[3] = 0x20;
    *puVar4 = 0x460;
    puVar4[1] = *(undefined4 *)(iVar11 + 0x1c);
    uVar7 = *(undefined4 *)(iVar11 + 0x18);
    puVar4[7] = &uStack_38;
    puVar4[10] = &uStack_34;
    puVar4[6] = iVar3;
    puVar4[0xb] = &uStack_30;
    puVar4[2] = uVar7;
    puVar4[0xc] = auStack_2c;
    iVar5 = recordProgramBuildDependencies(puVar4);
    FUN_0007a110(puVar4);
    (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar11 + 0x1c));
    *(int *)(iVar11 + 0x1c) = iVar3;
    if (iVar5 == 0) {
      *(uint *)(iVar11 + 0x18) = uStack_38;
      param_2[0x15] = uStack_38;
      *(undefined4 *)(iVar11 + 8) = uStack_34;
      *(undefined4 *)(iVar11 + 0xc) = uStack_30;
      *(undefined4 *)(iVar11 + 0x2ac) = auStack_2c[0];
    }
    else {
      *(undefined4 *)(iVar11 + 0xc) = 0;
      if (uStack_38 != 0) {
        uVar9 = uStack_38;
        iVar3 = uStack_38 * 0x10 + iVar3;
        do {
          if ((((*(uint *)(iVar3 + -0xc) & 7) == 1) || ((*(uint *)(iVar3 + -8) & 7) == 1)) ||
             ((*(uint *)(iVar3 + -4) & 7) == 1)) {
            *(uint *)(iVar11 + 0xc) = uVar9 - 1;
          }
          uVar9 = uVar9 - 1;
        } while ((uVar9 != 0) && (iVar3 = iVar3 + -0x10, *(int *)(iVar11 + 0xc) == 0));
      }
    }
    puVar2 = *(uint **)(iVar11 + 0x1c);
    if (uStack_38 != 0) {
      uVar9 = 0;
      do {
        uVar1 = *puVar2;
        if ((uVar1 & 0x3f) == 4) {
          if ((((puVar2[1] & 7) == 0) && ((puVar2[2] & 7) == 0)) && ((puVar2[3] & 7) == 0)) {
            uVar6 = puVar2[1] >> 5 & 0xff;
            uVar10 = puVar2[2] >> 5 & 0xff;
            if (((uVar6 != uVar10) && (uVar8 = puVar2[3] >> 5 & 0xff, uVar6 != uVar8)) &&
               (uVar10 != uVar8)) {
              *puVar2 = uVar1 & 0xffffffc0 | 0x80;
            }
          }
        }
        else if ((((uVar1 & 0x3f) == 0xb) && ((puVar2[1] & 7) == 0)) &&
                (((puVar2[2] & 7) == 0 && ((puVar2[3] & 7) == 0)))) {
          uVar6 = puVar2[1] >> 5 & 0xff;
          uVar10 = puVar2[2] >> 5 & 0xff;
          if (((uVar6 != uVar10) && (uVar8 = puVar2[3] >> 5 & 0xff, uVar6 != uVar8)) &&
             (uVar10 != uVar8)) {
            *puVar2 = uVar1 & 0xffffffc0 | 0x81;
          }
        }
        uVar9 = uVar9 + 1;
        puVar2 = puVar2 + 4;
      } while (uVar9 < uStack_38);
    }
  }
  return;
}

/* extvsPrepareHardwareProgram @ 0x5f810 (9624 bytes) */
/* 14 of its vtable+0x1344 dispatch calls dropped a
 * genuine 3rd argument (the already-declared symbolIndex) that stock passes (found auditing #70 via
 * ExtendIndirectCalls.java / ground-truth disassembly); a 15th, differently-shaped call at the
 * same vtable slot already had its own real 3rd argument and needed no change. */
int extvsPrepareHardwareProgram(ctx, shader)
  int ctx;
  int *shader;
{
  undefined4 newSlotArray2;
  undefined4 newSlotArray;
  int newSlotOffset;
  int oldSlotCount;
  byte bVar1;
  bool searching;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined1 uVar7;
  int *piVar6;
  int writeEnableSnapshot;
  uint symbolIndex;
  int symbolOffset;
  uint in_r7;
  uint in_r8;
  uint slotByteOffset;
  int iVar10;
  int iVar11;
  int iVar12;
  undefined4 *puVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  int iVar16;
  uint uVar17;
  int iVar18;
  int iVar19;
  undefined4 uVar20;
  uint *hwProgramSlot;
  uint slotIndex;
  uint programState;
  int rowsRemaining;
  undefined4 auStack_d8 [2];
  int iStack_d0;
  int iStack_cc;
  int iStack_c8;
  int iStack_c4;
  int iStack_c0;
  undefined4 uStack_b0;
  undefined4 uStack_ac;
  undefined4 uStack_a8;
  undefined4 uStack_a4;
  
  hwProgramSlot = *(uint **)(*(int *)(((unsigned char *)0x0000118c) + ctx) * 4 + *shader);
  programState = *hwProgramSlot;
  if ((shader[6] == 0) || (shader[5] == 0)) {
    uVar7 = 1;
LAB_00061d90:
    shader[0x19] = 0;
    shader[0xc] = 0;
    shader[0x15] = 0;
    shader[0x16] = 0;
    shader[0x17] = 0;
    shader[0x18] = 0;
  }
  else {
    *(undefined1 *)(shader + 4) = 1;
    ((int (*)())extvsAssignVertexInputs)(ctx,shader);
    writeEnableSnapshot = (**(code **)(ctx + 0xc))(shader[5] << 4);
    if (shader[5] != 0) {
      symbolIndex = 0;
      symbolOffset = 0;
      do {
        iVar10 = shader[6];
        iVar16 = symbolOffset + iVar10;
        if (*(int *)(iVar16 + 4) == 1) {
          uVar5 = *(uint *)(iVar16 + 8);
          if (uVar5 < 0x879d) {
            if (uVar5 < 0x879b) {
              if (uVar5 < 0x6111) {
                if (uVar5 < 0x610f) {
                  if (uVar5 == 0x610e) {
                    *(undefined1 *)((int)shader + 0x79) = 1;
                  }
                }
                else {
                  *(undefined1 *)((int)shader + (uVar5 - 0x60a0)) = 1;
                }
              }
              else if (uVar5 == 0x879a) {
                *(undefined1 *)(shader + 0x1b) = 1;
              }
            }
            else {
              *(undefined1 *)((int)shader + (uVar5 - 0x872e)) = 1;
            }
          }
          else if (uVar5 < 0x87a5) {
            if (*(int *)(iVar16 + 0xc) != 0) {
              *(byte *)((int)shader + (uVar5 - 0x872c)) =
                   *(byte *)((int)shader + (uVar5 - 0x872c)) | 1;
            }
            if (*(int *)(iVar16 + 0x10) != 0) {
              *(byte *)((int)shader + *(int *)(iVar16 + 8) + -0x872c) =
                   *(byte *)((int)shader + *(int *)(iVar16 + 8) + -0x872c) | 2;
            }
            if (*(int *)(iVar16 + 0x14) != 0) {
              *(byte *)((int)shader + *(int *)(iVar16 + 8) + -0x872c) =
                   *(byte *)((int)shader + *(int *)(iVar16 + 8) + -0x872c) | 4;
            }
            if (*(int *)(iVar16 + 0x18) != 0) {
              *(byte *)((int)shader + *(int *)(iVar16 + 8) + -0x872c) =
                   *(byte *)((int)shader + *(int *)(iVar16 + 8) + -0x872c) | 8;
            }
          }
          else if (uVar5 == 0x87bd) {
            *(undefined1 *)((int)shader + 0x7a) = 1;
          }
        }
        iVar10 = symbolOffset + iVar10;
        iVar16 = symbolIndex * 0x10;
        symbolIndex = symbolIndex + 1;
        symbolOffset = symbolOffset + 0x74;
        in_r7 = *(uint *)(iVar10 + 0x18);
        iVar11 = iVar16 + writeEnableSnapshot;
        uVar14 = *(undefined4 *)(iVar10 + 0x10);
        in_r8 = *(uint *)(iVar10 + 0x14);
        *(undefined4 *)(writeEnableSnapshot + iVar16) = *(undefined4 *)(iVar10 + 0xc);
        *(uint *)(iVar11 + 0xc) = in_r7;
        *(undefined4 *)(iVar11 + 4) = uVar14;
        *(uint *)(iVar11 + 8) = in_r8;
      } while (symbolIndex < (uint)shader[5]);
    }
    if ((*(char *)((int)shader + 0x7a) == '\0') ||
       (uVar7 = 1, (*(uint *)(ctx + 0x44) & 0x1000) != 0)) {
      uVar7 = 0;
    }
    *(undefined1 *)(programState + 0x42) = uVar7;
    *(undefined1 *)(programState + 0x43) = *(undefined1 *)((int)shader + 0x79);
    if ((*(char *)((int)shader + 0x6f) != '\0') || (uVar7 = 0, *(char *)(shader + 0x1c) != '\0'))
    {
      uVar7 = 1;
    }
    *(undefined1 *)(programState + 0x44) = uVar7;
    uVar5 = *(uint *)(ctx + 0x44);
    if ((uVar5 & 0x80) == 0) {
      *(undefined1 *)((int)shader + 0x79) = 0;
      uVar5 = *(uint *)(ctx + 0x44);
    }
    if ((uVar5 & 0x40) == 0) {
      *(undefined1 *)(shader + 0x1c) = 0;
      *(undefined1 *)((int)shader + 0x6f) = 0;
    }
    if ((*(char *)((int)shader + 0x7a) != '\0') && ((*(uint *)(ctx + 0x44) & 0x800) != 0)) {
      in_r7 = (uint)(byte)((unsigned char *)0x000011d1)[ctx];
      in_r8 = in_r7 + (int)shader;
      if (*(char *)(in_r8 + 0x71) != '\0') {
        uVar17 = shader[5];
        uVar5 = 0;
        if (uVar17 != 0) {
          do {
            iVar10 = uVar5 * 0x74 + shader[6];
            if ((*(int *)(iVar10 + 4) == 1) && (*(int *)(iVar10 + 8) == in_r7 + 0x879d)) {
              *(undefined4 *)(iVar10 + 0x18) = 0;
              *(undefined4 *)(iVar10 + 0xc) = 0;
              *(undefined4 *)(iVar10 + 0x10) = 0;
              *(undefined4 *)(iVar10 + 0x14) = 0;
              uVar17 = shader[5];
            }
            uVar5 = uVar5 + 1;
          } while (uVar5 < uVar17);
        }
      }
      *(undefined1 *)(in_r8 + 0x71) = 0xf;
    }
    if ((*(char *)(shader + 0x1b) != '\0') && ((*(uint *)(ctx + 0x44) & 0x400) != 0)) {
      bVar1 = ((unsigned char *)0x000011d2)[ctx];
      uVar5 = (uint)bVar1;
      if ((*(char *)((int)shader + bVar1 + 0x71) != '\0') && (uVar17 = shader[5], uVar17 != 0)) {
        in_r8 = 0;
        in_r7 = 0;
        iVar10 = 0;
        symbolOffset = bVar1 + 0x879d;
        do {
          iVar16 = iVar10 + shader[6];
          if ((*(int *)(iVar16 + 4) == 1) && (*(int *)(iVar16 + 8) == symbolOffset)) {
            *(undefined4 *)(iVar16 + 0x18) = 0;
            *(undefined4 *)(iVar16 + 0xc) = 0;
            *(undefined4 *)(iVar16 + 0x10) = 0;
            *(undefined4 *)(iVar16 + 0x14) = 0;
            uVar17 = shader[5];
          }
          in_r8 = in_r8 + 1;
          iVar10 = iVar10 + 0x74;
        } while (in_r8 < uVar17);
        uVar5 = (uint)(byte)((unsigned char *)0x000011d2)[ctx];
      }
      *(undefined1 *)((int)shader + uVar5 + 0x71) = 0xf;
    }
    iVar10 = 1;
    *(undefined4 *)(programState + 0x1e8) = 0;
    if (*(char *)((int)shader + 0x79) != '\0') {
      iVar10 = 2;
      *(undefined4 *)(programState + 0x1fc) = 1;
    }
    uVar5 = shader[0x1b];
    if ((((uVar5 & 0xffffff) != 0) || (*(char *)(shader + 0x1c) != '\0')) ||
       (*(char *)((int)shader + 0x7a) != '\0')) {
      *(int *)(programState + 0x1ec) = iVar10;
      iVar10 = iVar10 + 1;
      uVar5 = shader[0x1b];
    }
    if ((((uVar5 & 0xffff) != 0) || (*(char *)(shader + 0x1c) != '\0')) ||
       (*(char *)((int)shader + 0x7a) != '\0')) {
      *(int *)(programState + 0x1f0) = iVar10;
      iVar10 = iVar10 + 1;
    }
    if ((*(char *)((int)shader + 0x6f) != '\0') || (*(char *)(shader + 0x1c) != '\0')) {
      iVar16 = iVar10 + 1;
      *(int *)(programState + 500) = iVar10;
      iVar10 = iVar10 + 2;
      *(int *)(programState + 0x1f8) = iVar16;
    }
    iVar16 = 8;
    piVar6 = shader;
    uVar5 = programState;
    do {
      if (*(char *)((int)piVar6 + 0x71) != '\0') {
        *(int *)(uVar5 + 0x200) = iVar10;
        iVar10 = iVar10 + 1;
      }
      piVar6 = (int *)((int)piVar6 + 1);
      uVar5 = uVar5 + 4;
      iVar16 = iVar16 + -1;
    } while (iVar16 != 0);
    *(undefined4 *)(programState + 0x22c) = 0;
    *(undefined4 *)(programState + 0x224) = 0;
    if (shader[5] != 0) {
      uVar5 = 0;
      iVar10 = 0;
      do {
        iVar16 = shader[6];
        if (*(int *)(iVar10 + iVar16 + 0x20) == 2) {
          iVar18 = shader[8];
          iVar11 = *(int *)(iVar10 + iVar16 + 0x24) * 0x54;
          symbolOffset = iVar11 + iVar18;
          if ((*(int *)(symbolOffset + 0x28) == 0x87c2) && (*(char *)(symbolOffset + 0x3d) == '\0')) {
            if (*(int *)(symbolOffset + 0x30) == 0) {
              if (*(uint *)(symbolOffset + 0x34) < 2) {
                symbolIndex = programState;
                extvsAllocConstantRegisters(ctx,shader,programState,symbolOffset);
                iVar16 = shader[6];
                goto LAB_0005fdf0;
              }
            }
            else {
              iVar11 = extvsSymbolListGetIndex(shader + 7,*(int *)(symbolOffset + 0x30));
              iVar18 = shader[8];
              iVar11 = iVar11 * 0x54;
            }
            if (*(int *)(iVar18 + iVar11 + 0x34) != 0) {
              uVar17 = 0;
              iVar16 = iVar11;
              do {
                symbolOffset = iVar16 + iVar18;
                uVar17 = uVar17 + 1;
                iVar16 = iVar16 + 0x54;
                symbolIndex = programState;
                extvsAllocConstantRegisters(ctx,shader,programState,symbolOffset);
                iVar18 = shader[8];
              } while (uVar17 < *(uint *)(iVar18 + iVar11 + 0x34));
            }
            iVar16 = shader[6];
          }
        }
LAB_0005fdf0:
        if (*(int *)(iVar10 + iVar16 + 0x3c) == 2) {
          iVar19 = shader[8];
          iVar11 = *(int *)(iVar10 + iVar16 + 0x40) * 0x54;
          iVar18 = iVar11 + iVar19;
          if ((*(int *)(iVar18 + 0x28) == 0x87c2) && (*(char *)(iVar18 + 0x3d) == '\0')) {
            if (*(int *)(iVar18 + 0x30) == 0) {
              if (1 < *(uint *)(iVar18 + 0x34)) goto LAB_00060230;
              shader[0x17] = shader[0x17] + 1;
              if (*(char *)(iVar18 + 0x44) == '\0') {
                *(int *)(programState + 0x224) = *(int *)(programState + 0x224) + 1;
              }
              else {
                *(int *)(programState + 0x22c) = *(int *)(programState + 0x22c) + 1;
              }
              iVar16 = *(int *)(iVar18 + 0x24);
              *(undefined1 *)(iVar18 + 0x3d) = 1;
              if (iVar16 == 0x87bf) {
                in_r8 = 0;
                uVar17 = 0;
                iVar16 = 0;
                searching = true;
                *(int *)(programState + 0x5c) = *(int *)(programState + 0x5c) + 1;
                while (uVar17 < *(uint *)(programState + 0x58)) {
                  if (!searching) goto LAB_0005ffe8;
                  if (*(char *)(iVar16 + *(int *)(programState + 0x54) + 0x10) == '\0') {
                    in_r8 = 1;
                    searching = false;
                  }
                  else {
                    uVar17 = uVar17 + 1;
                    iVar16 = iVar16 + 0x28;
                  }
                }
                if (searching) {
                  *(char *)(shader + 4) = (char)in_r8;
                  iVar16 = *(int *)(programState + 0x58);
                  newSlotArray = (**(code **)(ctx + 0x10))(iVar16 + 0x10,0x28);
                  symbolIndex = *(int *)(programState + 0x58) * 0x28;
                  (**(code **)(((unsigned char *)0x00001344) + ctx))(newSlotArray,*(undefined4 *)(programState + 0x54),symbolIndex);
                  (**(code **)(ctx + 0x18))(*(undefined4 *)(programState + 0x54));
                  *(undefined4 *)(programState + 0x54) = newSlotArray;
                  *(int *)(programState + 0x58) = *(int *)(programState + 0x58) + 0x10;
LAB_00060078:
                  *(int *)(iVar18 + 4) = iVar16;
                  *(undefined1 *)(iVar16 * 0x28 + *(int *)(programState + 0x54) + 0x10) = 1;
                  iVar16 = shader[6];
                  goto LAB_000608e0;
                }
LAB_0005ffe8:
                *(uint *)(iVar18 + 4) = uVar17;
LAB_0005ffec:
                *(undefined1 *)(uVar17 * 0x28 + *(int *)(programState + 0x54) + 0x10) = 1;
                iVar16 = shader[6];
                goto LAB_000608e0;
              }
              if (iVar16 == 0x87c0) {
                uVar17 = 0;
                iVar16 = 0;
                searching = true;
                *(int *)(programState + 0x5c) = *(int *)(programState + 0x5c) + 4;
                while (uVar17 < *(int *)(programState + 0x58) - 3U) {
                  if (!searching) goto LAB_000600f4;
                  if (*(char *)(iVar16 + *(int *)(programState + 0x54) + 0x10) == '\0') {
                    searching = false;
                  }
                  else {
                    uVar17 = uVar17 + 1;
                    iVar16 = iVar16 + 0x28;
                  }
                }
                if (!searching) {
LAB_000600f4:
                  iVar16 = uVar17 * 0x28;
                  iVar11 = iVar16 + *(int *)(programState + 0x54);
                  if (((*(char *)(iVar11 + 0x38) == '\0') && (*(char *)(iVar11 + 0x60) == '\0')) &&
                     (*(char *)(iVar11 + 0x88) == '\0')) {
                    in_r8 = 0;
                    iVar11 = 4;
                    in_r7 = 1;
                    do {
                      iVar19 = uVar17 + in_r8;
                      in_r8 = in_r8 + 1;
                      *(int *)(iVar18 + 0x10) = iVar19;
                      iVar18 = iVar18 + 4;
                      iVar19 = iVar16 + *(int *)(programState + 0x54);
                      iVar16 = iVar16 + 0x28;
                      *(undefined1 *)(iVar19 + 0x10) = 1;
                      iVar11 = iVar11 + -1;
                    } while (iVar11 != 0);
                    goto LAB_000608d4;
                  }
                }
                *(undefined1 *)(shader + 4) = 0;
                iVar19 = *(int *)(programState + 0x58);
                newSlotArray = (**(code **)(ctx + 0x10))(iVar19 + 0x10,0x28);
                symbolIndex = *(int *)(programState + 0x58) * 0x28;
                (**(code **)(((unsigned char *)0x00001344) + ctx))(newSlotArray,*(undefined4 *)(programState + 0x54),symbolIndex);
                (**(code **)(ctx + 0x18))(*(undefined4 *)(programState + 0x54));
                *(undefined4 *)(programState + 0x54) = newSlotArray;
                iVar16 = iVar19 * 0x28;
                iVar12 = 4;
                iVar11 = 0;
                in_r8 = 1;
                *(int *)(programState + 0x58) = *(int *)(programState + 0x58) + 0x10;
                do {
                  iVar3 = iVar11 + iVar19;
                  iVar11 = iVar11 + 1;
                  *(int *)(iVar18 + 0x10) = iVar3;
                  iVar18 = iVar18 + 4;
                  iVar3 = *(int *)(programState + 0x54) + iVar16;
                  iVar16 = iVar16 + 0x28;
                  *(undefined1 *)(iVar3 + 0x10) = 1;
                  iVar12 = iVar12 + -1;
                } while (iVar12 != 0);
              }
              else if (iVar16 == 0x87be) {
                uVar14 = 0;
                uVar17 = 0;
                iVar16 = 0;
                searching = true;
                *(int *)(programState + 0x5c) = *(int *)(programState + 0x5c) + 1;
                while (uVar17 < *(uint *)(programState + 0x58)) {
                  if (!searching) goto LAB_0005ff00;
                  if (*(char *)(iVar16 + *(int *)(programState + 0x54) + 0x10) == '\0') {
                    uVar14 = 1;
                    searching = false;
                  }
                  else {
                    uVar17 = uVar17 + 1;
                    iVar16 = iVar16 + 0x28;
                  }
                }
                if (searching) {
                  *(char *)(shader + 4) = (char)uVar14;
                  iVar16 = *(int *)(programState + 0x58);
                  newSlotArray2 = (**(code **)(ctx + 0x10))(iVar16 + 0x10,0x28);
                  symbolIndex = *(int *)(programState + 0x58) * 0x28;
                  (**(code **)(((unsigned char *)0x00001344) + ctx))(newSlotArray2,*(undefined4 *)(programState + 0x54),symbolIndex);
                  (**(code **)(ctx + 0x18))(*(undefined4 *)(programState + 0x54));
                  *(undefined4 *)(programState + 0x54) = newSlotArray2;
                  *(int *)(programState + 0x58) = *(int *)(programState + 0x58) + 0x10;
                  *(undefined4 *)(iVar18 + 8) = uVar14;
                  goto LAB_00060078;
                }
LAB_0005ff00:
                *(uint *)(iVar18 + 4) = uVar17;
                *(undefined4 *)(iVar18 + 8) = 0;
                goto LAB_0005ffec;
              }
            }
            else {
              iVar11 = extvsSymbolListGetIndex(shader + 7,*(int *)(iVar18 + 0x30));
              iVar19 = shader[8];
              iVar11 = iVar11 * 0x54;
LAB_00060230:
              if (*(int *)(iVar11 + iVar19 + 0x34) != 0) {
                uVar17 = 0;
                iVar16 = iVar11;
                do {
                  iVar18 = iVar19 + iVar16;
                  if (*(int *)(iVar18 + 0x28) == 0x87c2) {
                    shader[0x17] = shader[0x17] + 1;
                    if (*(char *)(iVar18 + 0x44) == '\0') {
                      *(int *)(programState + 0x224) = *(int *)(programState + 0x224) + 1;
                    }
                    else {
                      *(int *)(programState + 0x22c) = *(int *)(programState + 0x22c) + 1;
                    }
                    iVar19 = *(int *)(iVar18 + 0x24);
                    *(undefined1 *)(iVar18 + 0x3d) = 1;
                    if (iVar19 != 0x87bf) {
                      if (iVar19 == 0x87c0) {
                        slotIndex = 0;
                        iVar19 = 0;
                        searching = true;
                        *(int *)(programState + 0x5c) = *(int *)(programState + 0x5c) + 4;
                        while (slotIndex < *(int *)(programState + 0x58) - 3U) {
                          if (!searching) goto LAB_000603e0;
                          if (*(char *)(iVar19 + *(int *)(programState + 0x54) + 0x10) == '\0') {
                            searching = false;
                          }
                          else {
                            slotIndex = slotIndex + 1;
                            iVar19 = iVar19 + 0x28;
                          }
                        }
                        if (!searching) {
LAB_000603e0:
                          slotByteOffset = slotIndex * 0x28;
                          iVar19 = slotByteOffset + *(int *)(programState + 0x54);
                          in_r8 = slotByteOffset;
                          if (((*(char *)(iVar19 + 0x38) == '\0') &&
                              (*(char *)(iVar19 + 0x60) == '\0')) &&
                             (*(char *)(iVar19 + 0x88) == '\0')) {
                            in_r8 = 0;
                            iVar19 = 4;
                            in_r7 = 1;
                            do {
                              iVar12 = slotIndex + in_r8;
                              in_r8 = in_r8 + 1;
                              *(int *)(iVar18 + 0x10) = iVar12;
                              iVar18 = iVar18 + 4;
                              iVar12 = *(int *)(programState + 0x54) + slotByteOffset;
                              slotByteOffset = slotByteOffset + 0x28;
                              *(undefined1 *)(iVar12 + 0x10) = 1;
                              iVar19 = iVar19 + -1;
                            } while (iVar19 != 0);
                            goto LAB_000608b8;
                          }
                        }
                        *(undefined1 *)(shader + 4) = 0;
                        oldSlotCount = *(int *)(programState + 0x58);
                        newSlotArray = (**(code **)(ctx + 0x10))
                                           (oldSlotCount + 0x10,0x28,symbolIndex,symbolOffset,in_r7,in_r8,0);
                        symbolIndex = *(int *)(programState + 0x58) * 0x28;
                        (**(code **)(((unsigned char *)0x00001344) + ctx))
                                  (newSlotArray,*(undefined4 *)(programState + 0x54),symbolIndex);
                        (**(code **)(ctx + 0x18))(*(undefined4 *)(programState + 0x54));
                        *(undefined4 *)(programState + 0x54) = newSlotArray;
                        newSlotOffset = oldSlotCount * 0x28;
                        rowsRemaining = 4;
                        iVar19 = 0;
                        in_r8 = 1;
                        *(int *)(programState + 0x58) = *(int *)(programState + 0x58) + 0x10;
                        do {
                          iVar4 = iVar19 + oldSlotCount;
                          iVar19 = iVar19 + 1;
                          *(int *)(iVar18 + 0x10) = iVar4;
                          iVar18 = iVar18 + 4;
                          iVar4 = *(int *)(programState + 0x54) + newSlotOffset;
                          newSlotOffset = newSlotOffset + 0x28;
                          *(undefined1 *)(iVar4 + 0x10) = 1;
                          rowsRemaining = rowsRemaining + -1;
                        } while (rowsRemaining != 0);
                      }
                      else if (iVar19 == 0x87be) {
                        uVar14 = 0;
                        slotIndex = 0;
                        iVar19 = 0;
                        searching = true;
                        *(int *)(programState + 0x5c) = *(int *)(programState + 0x5c) + 1;
                        while (slotIndex < *(uint *)(programState + 0x58)) {
                          if (!searching) goto LAB_00060590;
                          if (*(char *)(iVar19 + *(int *)(programState + 0x54) + 0x10) == '\0') {
                            uVar14 = 1;
                            searching = false;
                          }
                          else {
                            slotIndex = slotIndex + 1;
                            iVar19 = iVar19 + 0x28;
                          }
                        }
LAB_0006058c:
                        if (!searching) {
LAB_00060590:
                          *(uint *)(iVar18 + 4) = slotIndex;
                          *(undefined4 *)(iVar18 + 8) = 0;
                          *(undefined1 *)(slotIndex * 0x28 + *(int *)(programState + 0x54) + 0x10) = 1;
                          iVar19 = shader[8];
                          goto LAB_000608bc;
                        }
                        *(char *)(shader + 4) = (char)uVar14;
                        iVar19 = *(int *)(programState + 0x58);
                        newSlotArray2 = (**(code **)(ctx + 0x10))(iVar19 + 0x10,0x28);
                        symbolIndex = *(int *)(programState + 0x58) * 0x28;
                        (**(code **)(((unsigned char *)0x00001344) + ctx))
                                  (newSlotArray2,*(undefined4 *)(programState + 0x54),symbolIndex);
                        (**(code **)(ctx + 0x18))(*(undefined4 *)(programState + 0x54));
                        *(undefined4 *)(programState + 0x54) = newSlotArray2;
                        *(int *)(programState + 0x58) = *(int *)(programState + 0x58) + 0x10;
                        *(undefined4 *)(iVar18 + 8) = uVar14;
                        goto LAB_00060720;
                      }
                      goto LAB_000608b8;
                    }
                    in_r8 = 0;
                    slotIndex = 0;
                    iVar19 = 0;
                    searching = true;
                    *(int *)(programState + 0x5c) = *(int *)(programState + 0x5c) + 1;
                    while (slotIndex < *(uint *)(programState + 0x58)) {
                      if (!searching) goto LAB_00060690;
                      if (*(char *)(iVar19 + *(int *)(programState + 0x54) + 0x10) == '\0') {
                        in_r8 = 1;
                        searching = false;
                      }
                      else {
                        slotIndex = slotIndex + 1;
                        iVar19 = iVar19 + 0x28;
                      }
                    }
LAB_0006068c:
                    if (searching) {
                      *(char *)(shader + 4) = (char)in_r8;
                      iVar19 = *(int *)(programState + 0x58);
                      newSlotArray = (**(code **)(ctx + 0x10))(iVar19 + 0x10,0x28);
                      symbolIndex = *(int *)(programState + 0x58) * 0x28;
                      (**(code **)(((unsigned char *)0x00001344) + ctx))(newSlotArray,*(undefined4 *)(programState + 0x54),symbolIndex);
                      (**(code **)(ctx + 0x18))(*(undefined4 *)(programState + 0x54));
                      *(undefined4 *)(programState + 0x54) = newSlotArray;
                      *(int *)(programState + 0x58) = *(int *)(programState + 0x58) + 0x10;
LAB_00060720:
                      *(int *)(iVar18 + 4) = iVar19;
                      *(undefined1 *)(iVar19 * 0x28 + *(int *)(programState + 0x54) + 0x10) = 1;
                      iVar19 = shader[8];
                    }
                    else {
LAB_00060690:
                      *(uint *)(iVar18 + 4) = slotIndex;
                      *(undefined1 *)(slotIndex * 0x28 + *(int *)(programState + 0x54) + 0x10) = 1;
                      iVar19 = shader[8];
                    }
                  }
                  else if (*(int *)(iVar18 + 0x28) == 0x87c3) {
                    shader[0x18] = shader[0x18] + 1;
                    *(undefined1 *)(iVar18 + 0x3d) = 1;
                    iVar19 = *(int *)(iVar18 + 0x24);
                    if (iVar19 == 0x87bf) {
                      in_r8 = 0;
                      slotIndex = 0;
                      iVar19 = 0;
                      searching = true;
                      *(int *)(programState + 0x5c) = *(int *)(programState + 0x5c) + 1;
                      while (slotIndex < *(uint *)(programState + 0x58)) {
                        if (!searching) goto LAB_00060690;
                        if (*(char *)(iVar19 + *(int *)(programState + 0x54) + 0x10) == '\0') {
                          in_r8 = 1;
                          searching = false;
                        }
                        else {
                          slotIndex = slotIndex + 1;
                          iVar19 = iVar19 + 0x28;
                        }
                      }
                      goto LAB_0006068c;
                    }
                    if (iVar19 == 0x87c0) {
                      slotIndex = 0;
                      iVar19 = 0;
                      searching = true;
                      *(int *)(programState + 0x5c) = *(int *)(programState + 0x5c) + 4;
                      while (slotIndex < *(int *)(programState + 0x58) - 3U) {
                        if (!searching) goto LAB_0006079c;
                        if (*(char *)(iVar19 + *(int *)(programState + 0x54) + 0x10) == '\0') {
                          searching = false;
                        }
                        else {
                          slotIndex = slotIndex + 1;
                          iVar19 = iVar19 + 0x28;
                        }
                      }
                      if (!searching) {
LAB_0006079c:
                        slotByteOffset = slotIndex * 0x28;
                        iVar19 = slotByteOffset + *(int *)(programState + 0x54);
                        in_r8 = slotByteOffset;
                        if (((*(char *)(iVar19 + 0x38) == '\0') &&
                            (*(char *)(iVar19 + 0x60) == '\0')) &&
                           (*(char *)(iVar19 + 0x88) == '\0')) {
                          in_r8 = 0;
                          iVar19 = 4;
                          in_r7 = 1;
                          do {
                            iVar12 = in_r8 + slotIndex;
                            in_r8 = in_r8 + 1;
                            *(int *)(iVar18 + 0x10) = iVar12;
                            iVar18 = iVar18 + 4;
                            iVar12 = *(int *)(programState + 0x54) + slotByteOffset;
                            slotByteOffset = slotByteOffset + 0x28;
                            *(undefined1 *)(iVar12 + 0x10) = 1;
                            iVar19 = iVar19 + -1;
                          } while (iVar19 != 0);
                          goto LAB_000608b8;
                        }
                      }
                      *(undefined1 *)(shader + 4) = 0;
                      oldSlotCount = *(int *)(programState + 0x58);
                      newSlotArray = (**(code **)(ctx + 0x10))
                                         (oldSlotCount + 0x10,0x28,symbolIndex,symbolOffset,in_r7,in_r8,0);
                      symbolIndex = *(int *)(programState + 0x58) * 0x28;
                      (**(code **)(((unsigned char *)0x00001344) + ctx))(newSlotArray,*(undefined4 *)(programState + 0x54),symbolIndex);
                      (**(code **)(ctx + 0x18))(*(undefined4 *)(programState + 0x54));
                      *(undefined4 *)(programState + 0x54) = newSlotArray;
                      newSlotOffset = oldSlotCount * 0x28;
                      rowsRemaining = 4;
                      iVar19 = 0;
                      in_r8 = 1;
                      *(int *)(programState + 0x58) = *(int *)(programState + 0x58) + 0x10;
                      do {
                        iVar4 = iVar19 + oldSlotCount;
                        iVar19 = iVar19 + 1;
                        *(int *)(iVar18 + 0x10) = iVar4;
                        iVar18 = iVar18 + 4;
                        iVar4 = *(int *)(programState + 0x54) + newSlotOffset;
                        newSlotOffset = newSlotOffset + 0x28;
                        *(undefined1 *)(iVar4 + 0x10) = 1;
                        rowsRemaining = rowsRemaining + -1;
                      } while (rowsRemaining != 0);
                    }
                    else if (iVar19 == 0x87be) {
                      uVar14 = 0;
                      slotIndex = 0;
                      iVar19 = 0;
                      searching = true;
                      *(int *)(programState + 0x5c) = *(int *)(programState + 0x5c) + 1;
                      while (slotIndex < *(uint *)(programState + 0x58)) {
                        if (!searching) goto LAB_00060590;
                        if (*(char *)(iVar19 + *(int *)(programState + 0x54) + 0x10) == '\0') {
                          uVar14 = 1;
                          searching = false;
                        }
                        else {
                          slotIndex = slotIndex + 1;
                          iVar19 = iVar19 + 0x28;
                        }
                      }
                      goto LAB_0006058c;
                    }
LAB_000608b8:
                    iVar19 = shader[8];
                  }
LAB_000608bc:
                  uVar17 = uVar17 + 1;
                  iVar16 = iVar16 + 0x54;
                } while (uVar17 < *(uint *)(iVar11 + iVar19 + 0x34));
              }
            }
LAB_000608d4:
            iVar16 = shader[6];
          }
        }
LAB_000608e0:
        if (*(int *)(iVar10 + iVar16 + 0x58) == 2) {
          iVar18 = shader[8];
          iVar16 = *(int *)(iVar10 + iVar16 + 0x5c) * 0x54;
          iVar11 = iVar16 + iVar18;
          if ((*(int *)(iVar11 + 0x28) == 0x87c2) && (*(char *)(iVar11 + 0x3d) == '\0')) {
            if (*(int *)(iVar11 + 0x30) == 0) {
              if (*(uint *)(iVar11 + 0x34) < 2) {
                shader[0x17] = shader[0x17] + 1;
                if (*(char *)(iVar11 + 0x44) == '\0') {
                  *(int *)(programState + 0x224) = *(int *)(programState + 0x224) + 1;
                }
                else {
                  *(int *)(programState + 0x22c) = *(int *)(programState + 0x22c) + 1;
                }
                iVar16 = *(int *)(iVar11 + 0x24);
                *(undefined1 *)(iVar11 + 0x3d) = 1;
                if (iVar16 == 0x87bf) {
                  in_r8 = 0;
                  uVar17 = 0;
                  iVar16 = 0;
                  searching = true;
                  *(int *)(programState + 0x5c) = *(int *)(programState + 0x5c) + 1;
                  while (uVar17 < *(uint *)(programState + 0x58)) {
                    if (!searching) goto LAB_00060ad8;
                    if (*(char *)(iVar16 + *(int *)(programState + 0x54) + 0x10) == '\0') {
                      in_r8 = 1;
                      searching = false;
                    }
                    else {
                      uVar17 = uVar17 + 1;
                      iVar16 = iVar16 + 0x28;
                    }
                  }
                  if (searching) {
                    *(char *)(shader + 4) = (char)in_r8;
                    iVar16 = *(int *)(programState + 0x58);
                    newSlotArray = (**(code **)(ctx + 0x10))(iVar16 + 0x10,0x28);
                    symbolIndex = *(int *)(programState + 0x58) * 0x28;
                    (**(code **)(((unsigned char *)0x00001344) + ctx))(newSlotArray,*(undefined4 *)(programState + 0x54),symbolIndex);
                    (**(code **)(ctx + 0x18))(*(undefined4 *)(programState + 0x54));
                    *(undefined4 *)(programState + 0x54) = newSlotArray;
                    *(int *)(programState + 0x58) = *(int *)(programState + 0x58) + 0x10;
LAB_00060b64:
                    *(int *)(iVar11 + 4) = iVar16;
                    *(undefined1 *)(iVar16 * 0x28 + *(int *)(programState + 0x54) + 0x10) = 1;
                  }
                  else {
LAB_00060ad8:
                    *(uint *)(iVar11 + 4) = uVar17;
LAB_00060adc:
                    *(undefined1 *)(uVar17 * 0x28 + *(int *)(programState + 0x54) + 0x10) = 1;
                  }
                }
                else if (iVar16 == 0x87c0) {
                  uVar17 = 0;
                  iVar16 = 0;
                  searching = true;
                  *(int *)(programState + 0x5c) = *(int *)(programState + 0x5c) + 4;
                  while (uVar17 < *(int *)(programState + 0x58) - 3U) {
                    if (!searching) goto LAB_00060bdc;
                    if (*(char *)(iVar16 + *(int *)(programState + 0x54) + 0x10) == '\0') {
                      searching = false;
                    }
                    else {
                      uVar17 = uVar17 + 1;
                      iVar16 = iVar16 + 0x28;
                    }
                  }
                  if (!searching) {
LAB_00060bdc:
                    iVar16 = uVar17 * 0x28;
                    iVar18 = iVar16 + *(int *)(programState + 0x54);
                    if (((*(char *)(iVar18 + 0x38) == '\0') && (*(char *)(iVar18 + 0x60) == '\0'))
                       && (*(char *)(iVar18 + 0x88) == '\0')) {
                      in_r8 = 0;
                      iVar18 = 4;
                      in_r7 = 1;
                      do {
                        iVar19 = in_r8 + uVar17;
                        in_r8 = in_r8 + 1;
                        *(int *)(iVar11 + 0x10) = iVar19;
                        iVar11 = iVar11 + 4;
                        iVar19 = iVar16 + *(int *)(programState + 0x54);
                        iVar16 = iVar16 + 0x28;
                        *(undefined1 *)(iVar19 + 0x10) = 1;
                        iVar18 = iVar18 + -1;
                      } while (iVar18 != 0);
                      goto LAB_000613b0;
                    }
                  }
                  *(undefined1 *)(shader + 4) = 0;
                  iVar19 = *(int *)(programState + 0x58);
                  newSlotArray = (**(code **)(ctx + 0x10))(iVar19 + 0x10,0x28);
                  symbolIndex = *(int *)(programState + 0x58) * 0x28;
                  (**(code **)(((unsigned char *)0x00001344) + ctx))(newSlotArray,*(undefined4 *)(programState + 0x54),symbolIndex);
                  (**(code **)(ctx + 0x18))(*(undefined4 *)(programState + 0x54));
                  *(undefined4 *)(programState + 0x54) = newSlotArray;
                  iVar18 = iVar19 * 0x28;
                  iVar12 = 4;
                  iVar16 = 0;
                  in_r8 = 1;
                  *(int *)(programState + 0x58) = *(int *)(programState + 0x58) + 0x10;
                  do {
                    iVar3 = iVar16 + iVar19;
                    iVar16 = iVar16 + 1;
                    *(int *)(iVar11 + 0x10) = iVar3;
                    iVar11 = iVar11 + 4;
                    iVar3 = iVar18 + *(int *)(programState + 0x54);
                    iVar18 = iVar18 + 0x28;
                    *(undefined1 *)(iVar3 + 0x10) = 1;
                    iVar12 = iVar12 + -1;
                  } while (iVar12 != 0);
                }
                else if (iVar16 == 0x87be) {
                  uVar14 = 0;
                  uVar17 = 0;
                  iVar16 = 0;
                  searching = true;
                  *(int *)(programState + 0x5c) = *(int *)(programState + 0x5c) + 1;
                  while (uVar17 < *(uint *)(programState + 0x58)) {
                    if (!searching) goto LAB_000609f0;
                    if (*(char *)(iVar16 + *(int *)(programState + 0x54) + 0x10) == '\0') {
                      uVar14 = 1;
                      searching = false;
                    }
                    else {
                      uVar17 = uVar17 + 1;
                      iVar16 = iVar16 + 0x28;
                    }
                  }
                  if (searching) {
                    *(char *)(shader + 4) = (char)uVar14;
                    iVar16 = *(int *)(programState + 0x58);
                    newSlotArray2 = (**(code **)(ctx + 0x10))(iVar16 + 0x10,0x28);
                    symbolIndex = *(int *)(programState + 0x58) * 0x28;
                    (**(code **)(((unsigned char *)0x00001344) + ctx))(newSlotArray2,*(undefined4 *)(programState + 0x54),symbolIndex);
                    (**(code **)(ctx + 0x18))(*(undefined4 *)(programState + 0x54));
                    *(undefined4 *)(programState + 0x54) = newSlotArray2;
                    *(int *)(programState + 0x58) = *(int *)(programState + 0x58) + 0x10;
                    *(undefined4 *)(iVar11 + 8) = uVar14;
                    goto LAB_00060b64;
                  }
LAB_000609f0:
                  *(uint *)(iVar11 + 4) = uVar17;
                  *(undefined4 *)(iVar11 + 8) = 0;
                  goto LAB_00060adc;
                }
                goto LAB_000613b0;
              }
            }
            else {
              iVar16 = extvsSymbolListGetIndex(shader + 7,*(int *)(iVar11 + 0x30));
              iVar18 = shader[8];
              iVar16 = iVar16 * 0x54;
            }
            if (*(int *)(iVar18 + iVar16 + 0x34) != 0) {
              uVar17 = 0;
              iVar11 = iVar16;
              do {
                iVar19 = iVar18 + iVar11;
                if (*(int *)(iVar19 + 0x28) == 0x87c2) {
                  shader[0x17] = shader[0x17] + 1;
                  if (*(char *)(iVar19 + 0x44) == '\0') {
                    *(int *)(programState + 0x224) = *(int *)(programState + 0x224) + 1;
                  }
                  else {
                    *(int *)(programState + 0x22c) = *(int *)(programState + 0x22c) + 1;
                  }
                  iVar18 = *(int *)(iVar19 + 0x24);
                  *(undefined1 *)(iVar19 + 0x3d) = 1;
                  if (iVar18 != 0x87bf) {
                    if (iVar18 == 0x87c0) {
                      slotIndex = 0;
                      iVar18 = 0;
                      searching = true;
                      *(int *)(programState + 0x5c) = *(int *)(programState + 0x5c) + 4;
                      while (slotIndex < *(int *)(programState + 0x58) - 3U) {
                        if (!searching) goto LAB_00060ebc;
                        if (*(char *)(iVar18 + *(int *)(programState + 0x54) + 0x10) == '\0') {
                          searching = false;
                        }
                        else {
                          slotIndex = slotIndex + 1;
                          iVar18 = iVar18 + 0x28;
                        }
                      }
                      if (!searching) {
LAB_00060ebc:
                        slotByteOffset = slotIndex * 0x28;
                        iVar18 = slotByteOffset + *(int *)(programState + 0x54);
                        in_r8 = slotByteOffset;
                        if (((*(char *)(iVar18 + 0x38) == '\0') &&
                            (*(char *)(iVar18 + 0x60) == '\0')) &&
                           (*(char *)(iVar18 + 0x88) == '\0')) {
                          in_r8 = 0;
                          iVar18 = 4;
                          in_r7 = 1;
                          do {
                            iVar12 = in_r8 + slotIndex;
                            in_r8 = in_r8 + 1;
                            *(int *)(iVar19 + 0x10) = iVar12;
                            iVar19 = iVar19 + 4;
                            iVar12 = *(int *)(programState + 0x54) + slotByteOffset;
                            slotByteOffset = slotByteOffset + 0x28;
                            *(undefined1 *)(iVar12 + 0x10) = 1;
                            iVar18 = iVar18 + -1;
                          } while (iVar18 != 0);
                          goto LAB_00061394;
                        }
                      }
                      *(undefined1 *)(shader + 4) = 0;
                      oldSlotCount = *(int *)(programState + 0x58);
                      newSlotArray = (**(code **)(ctx + 0x10))
                                         (oldSlotCount + 0x10,0x28,symbolIndex,symbolOffset,in_r7,in_r8,0);
                      symbolIndex = *(int *)(programState + 0x58) * 0x28;
                      (**(code **)(((unsigned char *)0x00001344) + ctx))(newSlotArray,*(undefined4 *)(programState + 0x54),symbolIndex);
                      (**(code **)(ctx + 0x18))(*(undefined4 *)(programState + 0x54));
                      *(undefined4 *)(programState + 0x54) = newSlotArray;
                      newSlotOffset = oldSlotCount * 0x28;
                      rowsRemaining = 4;
                      iVar18 = 0;
                      in_r8 = 1;
                      *(int *)(programState + 0x58) = *(int *)(programState + 0x58) + 0x10;
                      do {
                        iVar4 = oldSlotCount + iVar18;
                        iVar18 = iVar18 + 1;
                        *(int *)(iVar19 + 0x10) = iVar4;
                        iVar19 = iVar19 + 4;
                        iVar4 = newSlotOffset + *(int *)(programState + 0x54);
                        newSlotOffset = newSlotOffset + 0x28;
                        *(undefined1 *)(iVar4 + 0x10) = 1;
                        rowsRemaining = rowsRemaining + -1;
                      } while (rowsRemaining != 0);
                    }
                    else if (iVar18 == 0x87be) {
                      uVar14 = 0;
                      slotIndex = 0;
                      iVar18 = 0;
                      searching = true;
                      *(int *)(programState + 0x5c) = *(int *)(programState + 0x5c) + 1;
                      while (slotIndex < *(uint *)(programState + 0x58)) {
                        if (!searching) goto LAB_0006106c;
                        if (*(char *)(iVar18 + *(int *)(programState + 0x54) + 0x10) == '\0') {
                          uVar14 = 1;
                          searching = false;
                        }
                        else {
                          slotIndex = slotIndex + 1;
                          iVar18 = iVar18 + 0x28;
                        }
                      }
LAB_00061068:
                      if (!searching) {
LAB_0006106c:
                        *(uint *)(iVar19 + 4) = slotIndex;
                        *(undefined4 *)(iVar19 + 8) = 0;
                        *(undefined1 *)(slotIndex * 0x28 + *(int *)(programState + 0x54) + 0x10) = 1;
                        iVar18 = shader[8];
                        goto LAB_00061398;
                      }
                      *(char *)(shader + 4) = (char)uVar14;
                      iVar18 = *(int *)(programState + 0x58);
                      newSlotArray2 = (**(code **)(ctx + 0x10))(iVar18 + 0x10,0x28);
                      symbolIndex = *(int *)(programState + 0x58) * 0x28;
                      (**(code **)(((unsigned char *)0x00001344) + ctx))(newSlotArray2,*(undefined4 *)(programState + 0x54),symbolIndex);
                      (**(code **)(ctx + 0x18))(*(undefined4 *)(programState + 0x54));
                      *(undefined4 *)(programState + 0x54) = newSlotArray2;
                      *(int *)(programState + 0x58) = *(int *)(programState + 0x58) + 0x10;
                      *(undefined4 *)(iVar19 + 8) = uVar14;
                      goto LAB_000611fc;
                    }
                    goto LAB_00061394;
                  }
                  in_r8 = 0;
                  slotIndex = 0;
                  iVar18 = 0;
                  searching = true;
                  *(int *)(programState + 0x5c) = *(int *)(programState + 0x5c) + 1;
                  while (slotIndex < *(uint *)(programState + 0x58)) {
                    if (!searching) goto LAB_0006116c;
                    if (*(char *)(iVar18 + *(int *)(programState + 0x54) + 0x10) == '\0') {
                      in_r8 = 1;
                      searching = false;
                    }
                    else {
                      slotIndex = slotIndex + 1;
                      iVar18 = iVar18 + 0x28;
                    }
                  }
LAB_00061168:
                  if (searching) {
                    *(char *)(shader + 4) = (char)in_r8;
                    iVar18 = *(int *)(programState + 0x58);
                    newSlotArray = (**(code **)(ctx + 0x10))(iVar18 + 0x10,0x28);
                    symbolIndex = *(int *)(programState + 0x58) * 0x28;
                    (**(code **)(((unsigned char *)0x00001344) + ctx))(newSlotArray,*(undefined4 *)(programState + 0x54),symbolIndex);
                    (**(code **)(ctx + 0x18))(*(undefined4 *)(programState + 0x54));
                    *(undefined4 *)(programState + 0x54) = newSlotArray;
                    *(int *)(programState + 0x58) = *(int *)(programState + 0x58) + 0x10;
LAB_000611fc:
                    *(int *)(iVar19 + 4) = iVar18;
                    *(undefined1 *)(iVar18 * 0x28 + *(int *)(programState + 0x54) + 0x10) = 1;
                    iVar18 = shader[8];
                  }
                  else {
LAB_0006116c:
                    *(uint *)(iVar19 + 4) = slotIndex;
                    *(undefined1 *)(slotIndex * 0x28 + *(int *)(programState + 0x54) + 0x10) = 1;
                    iVar18 = shader[8];
                  }
                }
                else if (*(int *)(iVar19 + 0x28) == 0x87c3) {
                  shader[0x18] = shader[0x18] + 1;
                  *(undefined1 *)(iVar19 + 0x3d) = 1;
                  iVar18 = *(int *)(iVar19 + 0x24);
                  if (iVar18 == 0x87bf) {
                    in_r8 = 0;
                    slotIndex = 0;
                    iVar18 = 0;
                    searching = true;
                    *(int *)(programState + 0x5c) = *(int *)(programState + 0x5c) + 1;
                    while (slotIndex < *(uint *)(programState + 0x58)) {
                      if (!searching) goto LAB_0006116c;
                      if (*(char *)(iVar18 + *(int *)(programState + 0x54) + 0x10) == '\0') {
                        in_r8 = 1;
                        searching = false;
                      }
                      else {
                        slotIndex = slotIndex + 1;
                        iVar18 = iVar18 + 0x28;
                      }
                    }
                    goto LAB_00061168;
                  }
                  if (iVar18 == 0x87c0) {
                    slotIndex = 0;
                    iVar18 = 0;
                    searching = true;
                    *(int *)(programState + 0x5c) = *(int *)(programState + 0x5c) + 4;
                    while (slotIndex < *(int *)(programState + 0x58) - 3U) {
                      if (!searching) goto LAB_00061278;
                      if (*(char *)(iVar18 + *(int *)(programState + 0x54) + 0x10) == '\0') {
                        searching = false;
                      }
                      else {
                        slotIndex = slotIndex + 1;
                        iVar18 = iVar18 + 0x28;
                      }
                    }
                    if (!searching) {
LAB_00061278:
                      slotByteOffset = slotIndex * 0x28;
                      iVar18 = slotByteOffset + *(int *)(programState + 0x54);
                      in_r8 = slotByteOffset;
                      if (((*(char *)(iVar18 + 0x38) == '\0') && (*(char *)(iVar18 + 0x60) == '\0'))
                         && (*(char *)(iVar18 + 0x88) == '\0')) {
                        in_r8 = 0;
                        iVar18 = 4;
                        in_r7 = 1;
                        do {
                          iVar12 = in_r8 + slotIndex;
                          in_r8 = in_r8 + 1;
                          *(int *)(iVar19 + 0x10) = iVar12;
                          iVar19 = iVar19 + 4;
                          iVar12 = *(int *)(programState + 0x54) + slotByteOffset;
                          slotByteOffset = slotByteOffset + 0x28;
                          *(undefined1 *)(iVar12 + 0x10) = 1;
                          iVar18 = iVar18 + -1;
                        } while (iVar18 != 0);
                        goto LAB_00061394;
                      }
                    }
                    *(undefined1 *)(shader + 4) = 0;
                    oldSlotCount = *(int *)(programState + 0x58);
                    newSlotArray = (**(code **)(ctx + 0x10))
                                       (oldSlotCount + 0x10,0x28,symbolIndex,symbolOffset,in_r7,in_r8,0);
                    symbolIndex = *(int *)(programState + 0x58) * 0x28;
                    (**(code **)(((unsigned char *)0x00001344) + ctx))(newSlotArray,*(undefined4 *)(programState + 0x54),symbolIndex);
                    (**(code **)(ctx + 0x18))(*(undefined4 *)(programState + 0x54));
                    *(undefined4 *)(programState + 0x54) = newSlotArray;
                    newSlotOffset = oldSlotCount * 0x28;
                    rowsRemaining = 4;
                    iVar18 = 0;
                    in_r8 = 1;
                    *(int *)(programState + 0x58) = *(int *)(programState + 0x58) + 0x10;
                    do {
                      iVar4 = oldSlotCount + iVar18;
                      iVar18 = iVar18 + 1;
                      *(int *)(iVar19 + 0x10) = iVar4;
                      iVar19 = iVar19 + 4;
                      iVar4 = *(int *)(programState + 0x54) + newSlotOffset;
                      newSlotOffset = newSlotOffset + 0x28;
                      *(undefined1 *)(iVar4 + 0x10) = 1;
                      rowsRemaining = rowsRemaining + -1;
                    } while (rowsRemaining != 0);
                  }
                  else if (iVar18 == 0x87be) {
                    uVar14 = 0;
                    slotIndex = 0;
                    iVar18 = 0;
                    searching = true;
                    *(int *)(programState + 0x5c) = *(int *)(programState + 0x5c) + 1;
                    while (slotIndex < *(uint *)(programState + 0x58)) {
                      if (!searching) goto LAB_0006106c;
                      if (*(char *)(iVar18 + *(int *)(programState + 0x54) + 0x10) == '\0') {
                        uVar14 = 1;
                        searching = false;
                      }
                      else {
                        slotIndex = slotIndex + 1;
                        iVar18 = iVar18 + 0x28;
                      }
                    }
                    goto LAB_00061068;
                  }
LAB_00061394:
                  iVar18 = shader[8];
                }
LAB_00061398:
                uVar17 = uVar17 + 1;
                iVar11 = iVar11 + 0x54;
              } while (uVar17 < *(uint *)(iVar16 + iVar18 + 0x34));
            }
          }
        }
LAB_000613b0:
        uVar5 = uVar5 + 1;
        iVar10 = iVar10 + 0x74;
      } while (uVar5 < (uint)shader[5]);
      if (shader[5] != 0) {
        uVar5 = 0;
        iVar10 = 0;
        do {
          iVar16 = shader[6];
          if (*(int *)(iVar10 + iVar16 + 0x20) == 2) {
            iVar19 = shader[8];
            iVar11 = *(int *)(iVar10 + iVar16 + 0x24) * 0x54;
            iVar18 = iVar11 + iVar19;
            if ((*(int *)(iVar18 + 0x28) == 0x87c3) && (*(char *)(iVar18 + 0x3d) == '\0')) {
              if (*(int *)(iVar18 + 0x30) == 0) {
                if (*(uint *)(iVar18 + 0x34) < 2) {
                  extvsAllocConstantRegisters(ctx,shader,programState,iVar18);
                  iVar16 = shader[6];
                  goto LAB_000614b0;
                }
              }
              else {
                iVar11 = extvsSymbolListGetIndex(shader + 7,*(int *)(iVar18 + 0x30));
                iVar19 = shader[8];
                iVar11 = iVar11 * 0x54;
              }
              if (*(int *)(iVar19 + iVar11 + 0x34) != 0) {
                uVar17 = 0;
                iVar16 = iVar11;
                do {
                  iVar19 = iVar16 + iVar19;
                  uVar17 = uVar17 + 1;
                  iVar16 = iVar16 + 0x54;
                  extvsAllocConstantRegisters(ctx,shader,programState,iVar19);
                  iVar19 = shader[8];
                } while (uVar17 < *(uint *)(iVar19 + iVar11 + 0x34));
              }
              iVar16 = shader[6];
            }
          }
LAB_000614b0:
          if (*(int *)(iVar10 + iVar16 + 0x3c) == 2) {
            iVar19 = shader[8];
            iVar11 = *(int *)(iVar10 + iVar16 + 0x40) * 0x54;
            iVar18 = iVar11 + iVar19;
            if ((*(int *)(iVar18 + 0x28) == 0x87c3) && (*(char *)(iVar18 + 0x3d) == '\0')) {
              if (*(int *)(iVar18 + 0x30) == 0) {
                if (*(uint *)(iVar18 + 0x34) < 2) {
                  extvsAllocConstantRegisters(ctx,shader,programState,iVar18);
                  iVar16 = shader[6];
                  goto LAB_00061580;
                }
              }
              else {
                iVar11 = extvsSymbolListGetIndex(shader + 7,*(int *)(iVar18 + 0x30));
                iVar19 = shader[8];
                iVar11 = iVar11 * 0x54;
              }
              if (*(int *)(iVar19 + iVar11 + 0x34) != 0) {
                uVar17 = 0;
                iVar16 = iVar11;
                do {
                  iVar19 = iVar16 + iVar19;
                  uVar17 = uVar17 + 1;
                  iVar16 = iVar16 + 0x54;
                  extvsAllocConstantRegisters(ctx,shader,programState,iVar19);
                  iVar19 = shader[8];
                } while (uVar17 < *(uint *)(iVar19 + iVar11 + 0x34));
              }
              iVar16 = shader[6];
            }
          }
LAB_00061580:
          if (*(int *)(iVar10 + iVar16 + 0x58) == 2) {
            iVar18 = shader[8];
            iVar16 = *(int *)(iVar10 + iVar16 + 0x5c) * 0x54;
            iVar11 = iVar16 + iVar18;
            if ((*(int *)(iVar11 + 0x28) == 0x87c3) && (*(char *)(iVar11 + 0x3d) == '\0')) {
              if (*(int *)(iVar11 + 0x30) == 0) {
                if (*(uint *)(iVar11 + 0x34) < 2) {
                  extvsAllocConstantRegisters(ctx,shader,programState,iVar11);
                  goto LAB_00061650;
                }
              }
              else {
                iVar16 = extvsSymbolListGetIndex(shader + 7,*(int *)(iVar11 + 0x30));
                iVar18 = shader[8];
                iVar16 = iVar16 * 0x54;
              }
              if (*(int *)(iVar18 + iVar16 + 0x34) != 0) {
                uVar17 = 0;
                iVar11 = iVar16;
                do {
                  iVar18 = iVar11 + iVar18;
                  uVar17 = uVar17 + 1;
                  iVar11 = iVar11 + 0x54;
                  extvsAllocConstantRegisters(ctx,shader,programState,iVar18);
                  iVar18 = shader[8];
                } while (uVar17 < *(uint *)(iVar18 + iVar16 + 0x34));
              }
            }
          }
LAB_00061650:
          uVar5 = uVar5 + 1;
          iVar10 = iVar10 + 0x74;
        } while (uVar5 < (uint)shader[5]);
      }
    }
    if ((*(char *)((int)shader + 0x7a) != '\0') && ((*(uint *)(ctx + 0x44) & 0x1000000) != 0))
    {
      uVar5 = *(int *)(programState + 0x5c) + 1;
      *(int *)(programState + 0x60) = *(int *)(programState + 0x5c);
      *(uint *)(programState + 0x5c) = uVar5;
      if (*(uint *)(programState + 0x58) < uVar5) {
        *(undefined1 *)(shader + 4) = 0;
        uVar14 = (**(code **)(ctx + 0x10))(*(int *)(programState + 0x58) + 0x10,0x28);
        (**(code **)(((unsigned char *)0x00001344) + ctx))
                  (uVar14,*(undefined4 *)(programState + 0x54),*(int *)(programState + 0x58) * 0x28);
        (**(code **)(ctx + 0x18))(*(undefined4 *)(programState + 0x54));
        *(undefined4 *)(programState + 0x54) = uVar14;
        *(int *)(programState + 0x58) = *(int *)(programState + 0x58) + 0x10;
      }
    }
    uVar17 = 0;
    *(undefined4 *)(programState + 0x18) = 0;
    uVar5 = 0;
    if (shader[5] != 0) {
      slotIndex = 0;
      iVar10 = 0;
      do {
        if (0x20 < *(int *)(iVar10 + shader[6]) - 0x8782U) {
          shader[0x19] = 0;
          shader[0xc] = 0;
          shader[0x15] = 0;
          shader[0x16] = 0;
          shader[0x17] = 0;
          shader[0x18] = 0;
          return 0;
        }
        extvsAllocTempRegisters(ctx,shader,programState,iVar10 + shader[6] + 4);
        extvsAllocTempRegisters(ctx,shader,programState,iVar10 + shader[6] + 0x20);
        extvsAllocTempRegisters(ctx,shader,programState,iVar10 + shader[6] + 0x3c);
        iVar16 = iVar10 + shader[6] + 0x58;
        extvsAllocTempRegisters(ctx,shader,programState,iVar16);
        if (uVar17 < (uint)shader[0x19]) {
          uVar17 = shader[0x19];
        }
        iVar11 = *(int *)(iVar10 + shader[6]) + -0x8782;
        iVar18 = (*(code *)(PTR_FUN_001db9b8)[iVar11])(ctx,shader,iVar10 + shader[6]);
        if (iVar18 < 0) {
          uVar7 = 0;
          goto LAB_00061d90;
        }
        *(int *)(programState + 0x18) = iVar18 + *(int *)(programState + 0x18);
        uVar5 = *(uint *)(ctx + 0x44);
        if ((uVar5 & 0x800) != 0) {
          iVar18 = iVar10 + shader[6];
          iVar19 = *(int *)(iVar18 + 4);
          if ((iVar19 == 1) && (*(int *)(iVar18 + 8) == 0x87bd)) {
            bVar1 = ((unsigned char *)0x000011d1)[ctx];
            _memcpy(auStack_d8,iVar18,0x74);
            iStack_c8 = 0;
            iStack_c4 = 0;
            iStack_c0 = 0;
            iStack_d0 = bVar1 + 0x879d;
            iStack_cc = iVar19;
            iVar18 = (*(code *)(PTR_FUN_001db9b8)[iVar11])(ctx,shader,auStack_d8);
            iVar12 = *(int *)(programState + 0x18);
            *(int *)(programState + 0x18) = iVar18 + iVar12;
            uStack_a4 = 0x87de;
            auStack_d8[0] = 0x8799;
            iStack_cc = 0;
            uStack_b0 = 0x87dd;
            uStack_ac = 0x87dd;
            uStack_a8 = 0x87dd;
            iStack_c8 = iVar19;
            iStack_c4 = iVar19;
            iStack_c0 = iVar19;
            iVar18 = (*(code *)PTR_FUN_001dba14)
                               (ctx,shader,auStack_d8,iVar16,in_r7,in_r8,iVar12);
            *(int *)(programState + 0x18) = iVar18 + *(int *)(programState + 0x18);
            uVar5 = *(uint *)(ctx + 0x44);
          }
        }
        if ((((uVar5 & 0x400) != 0) && (iVar18 = iVar10 + shader[6], *(int *)(iVar18 + 4) == 1)) &&
           (*(int *)(iVar18 + 8) == 0x879a)) {
          _memcpy(auStack_d8,iVar18,0x74);
          iStack_d0 = (byte)((unsigned char *)0x000011d2)[ctx] + 0x879d;
          iVar16 = (*(code *)(PTR_FUN_001db9b8)[iVar11])
                             (ctx,shader,auStack_d8,iVar16,in_r7,in_r8,
                              (PTR_FUN_001db9b8)[iVar11]);
          *(int *)(programState + 0x18) = iVar16 + *(int *)(programState + 0x18);
        }
        if (*(char *)((int)shader + 0x7b) == '\0') {
          extvsFreeDeadTempSlots(ctx,shader,slotIndex);
        }
        if (((*(char *)((int)shader + 0x7a) != '\0') &&
            ((*(uint *)(ctx + 0x44) & 0x1000000) != 0)) &&
           ((*(int *)(iVar10 + shader[6] + 4) == 1 && (*(int *)(iVar10 + shader[6] + 8) == 0x87bd)
            ))) {
          iVar11 = *(int *)(programState + 0x18);
          iVar16 = ((int (*)())extvsEmitFogOutput)(ctx,shader,iVar11 * 0x10 + *(int *)(programState + 0x1c) + -0x10);
          *(int *)(programState + 0x18) = iVar11 + iVar16;
        }
        uVar5 = shader[5];
        slotIndex = slotIndex + 1;
        iVar10 = iVar10 + 0x74;
      } while (slotIndex < uVar5);
    }
    iVar10 = *(int *)(programState + 0x18);
    shader[0x19] = uVar17;
    shader[0x15] = iVar10;
    if (uVar5 != 0) {
      uVar5 = 0;
      iVar10 = 0;
      do {
        iVar16 = uVar5 * 0x10;
        uVar5 = uVar5 + 1;
        iVar11 = iVar16 + writeEnableSnapshot;
        uVar20 = *(undefined4 *)(iVar11 + 0xc);
        uVar14 = *(undefined4 *)(iVar11 + 4);
        iVar18 = iVar10 + shader[6];
        iVar10 = iVar10 + 0x74;
        uVar15 = *(undefined4 *)(iVar11 + 8);
        *(undefined4 *)(iVar18 + 0xc) = *(undefined4 *)(writeEnableSnapshot + iVar16);
        *(undefined4 *)(iVar18 + 0x18) = uVar20;
        *(undefined4 *)(iVar18 + 0x10) = uVar14;
        *(undefined4 *)(iVar18 + 0x14) = uVar15;
      } while (uVar5 < (uint)shader[5]);
    }
    (**(code **)(ctx + 0x18))(writeEnableSnapshot);
    writeEnableSnapshot = *(int *)(programState + 0x18);
    *(undefined4 *)(programState + 8) = 0;
    if (writeEnableSnapshot != 0) {
      do {
        uVar17 = *(uint *)(writeEnableSnapshot * 0x10 + *(int *)(programState + 0x1c) + -0x10);
        uVar5 = uVar17 & 0xf00;
        if (((uVar5 == 0x200) || (uVar5 == 0x300)) && ((uVar17 & 0xfe000) == 0)) {
          *(int *)(programState + 8) = writeEnableSnapshot + -1;
        }
        writeEnableSnapshot = writeEnableSnapshot + -1;
      } while ((writeEnableSnapshot != 0) && (*(int *)(programState + 8) == 0));
    }
    if (*(int *)(programState + 0x224) != 0) {
      uVar14 = (**(code **)(ctx + 0xc))(*(int *)(programState + 0x224) << 2);
      *(undefined4 *)(programState + 0x220) = uVar14;
      uVar5 = shader[7];
      if (uVar5 != 0) {
        uVar17 = 0;
        writeEnableSnapshot = 0;
        iVar10 = 0;
        do {
          iVar16 = iVar10 + shader[8];
          if (((*(char *)(iVar16 + 0x3d) != '\0') && (*(int *)(iVar16 + 0x28) == 0x87c2)) &&
             (*(char *)(iVar16 + 0x44) == '\0')) {
            iVar16 = writeEnableSnapshot * 4;
            writeEnableSnapshot = writeEnableSnapshot + 1;
            *(uint *)(iVar16 + *(int *)(programState + 0x220)) = uVar17;
            uVar5 = shader[7];
          }
          uVar17 = uVar17 + 1;
          iVar10 = iVar10 + 0x54;
        } while (uVar17 < uVar5);
      }
    }
    if (*(int *)(programState + 0x22c) != 0) {
      uVar14 = (**(code **)(ctx + 0xc))(*(int *)(programState + 0x22c) << 2);
      *(undefined4 *)(programState + 0x228) = uVar14;
      uVar5 = shader[7];
      if (uVar5 != 0) {
        uVar17 = 0;
        writeEnableSnapshot = 0;
        iVar10 = 0;
        do {
          iVar16 = iVar10 + shader[8];
          if (((*(char *)(iVar16 + 0x3d) != '\0') && (*(int *)(iVar16 + 0x28) == 0x87c2)) &&
             (*(char *)(iVar16 + 0x44) != '\0')) {
            iVar11 = writeEnableSnapshot * 4;
            writeEnableSnapshot = writeEnableSnapshot + 1;
            *(uint *)(iVar11 + *(int *)(programState + 0x228)) = uVar17;
            *(uint *)(programState + 0x230) = *(uint *)(programState + 0x230) | *(uint *)(iVar16 + 0x50);
            uVar5 = shader[7];
          }
          uVar17 = uVar17 + 1;
          iVar10 = iVar10 + 0x54;
        } while (uVar17 < uVar5);
      }
    }
    uVar5 = *(uint *)(programState + 0x5c);
    if (uVar5 != 0) {
      if (hwProgramSlot[0x23] < uVar5) {
        uVar5 = (**(code **)(ctx + 0x14))(hwProgramSlot[0x22],uVar5 << 4);
        hwProgramSlot[0x22] = uVar5;
        hwProgramSlot[0x23] = *(uint *)(programState + 0x5c);
      }
      if (shader[0x18] != 0) {
        uVar17 = shader[7];
        uVar5 = 0;
        if (uVar17 != 0) {
          do {
            writeEnableSnapshot = uVar5 * 0x54 + shader[8];
            if ((*(char *)(writeEnableSnapshot + 0x3d) != '\0') && (*(int *)(writeEnableSnapshot + 0x28) == 0x87c3)) {
              puVar13 = *(undefined4 **)(writeEnableSnapshot + 0x38);
              uVar14 = puVar13[3];
              writeEnableSnapshot = *(int *)(writeEnableSnapshot + 4) * 0x10;
              uVar20 = puVar13[1];
              uVar15 = puVar13[2];
              iVar10 = writeEnableSnapshot + hwProgramSlot[0x22];
              *(undefined4 *)(writeEnableSnapshot + hwProgramSlot[0x22]) = *puVar13;
              *(undefined4 *)(iVar10 + 0xc) = uVar14;
              *(undefined4 *)(iVar10 + 4) = uVar20;
              *(undefined4 *)(iVar10 + 8) = uVar15;
              uVar17 = shader[7];
            }
            uVar5 = uVar5 + 1;
          } while (uVar5 < uVar17);
        }
      }
    }
    ((int (*)())extvsBuildStreamDescriptors)(ctx,shader);
    ((int (*)())extvsStateCacheInsert)(ctx,shader);
    *(undefined1 *)(shader[1] + *(int *)(((unsigned char *)0x0000118c) + ctx)) = 0;
    if (*(int *)(programState + 0x2b8) != 0) {
      (**(code **)(ctx + 0x18))(*(int *)(programState + 0x2b8));
      *(undefined4 *)(programState + 0x2b8) = 0;
    }
    uVar7 = *(undefined1 *)(shader + 4);
  }
  return uVar7;
}

/* vpUploadConstantArray @ 0x61dc0 (224 bytes) */
int vpUploadConstantArray(param_1, param_2)
  int param_1;
  int param_2;
{
  code *UNRECOVERED_JUMPTABLE;
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_2 + 0x18);
  if ((iVar2 != 0) && (*(int *)(param_2 + 0x1c) != 0)) {
    puVar1 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,iVar2 * 4 + 3);
    *(undefined4 **)(0x00002748 + param_1 + 4) = puVar1;
    *puVar1 = 0x880;
    *(undefined4 *)(*(int *)(0x00002748 + param_1 + 4) + 4) = *(undefined4 *)(param_2 + 4);
    *(uint *)(*(int *)(0x00002748 + param_1 + 4) + 8) = (iVar2 * 4 + -1) * 0x10000 | 0x8882;
    _memcpy(*(int *)(0x00002748 + param_1 + 4) + 0xc,*(undefined4 *)(param_2 + 0x1c),iVar2 * 0x10)
    ;
    UNRECOVERED_JUMPTABLE = *(code **)(param_1 + 0x275c);
    iVar2 = iVar2 * 0x10 + *(int *)(0x00002748 + param_1 + 4) + 0xc;
    *(int *)(0x00002748 + param_1 + 4) = iVar2;
                    
                    
    (*UNRECOVERED_JUMPTABLE)(param_1,iVar2);
    return;
  }
  return;
}

/* vpUploadConstantsWithFog @ 0x61eb0 (604 bytes) */
int vpUploadConstantsWithFog(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
  int param_5;
{
  short sVar1;
  code *UNRECOVERED_JUMPTABLE;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = *(int *)(param_3 + 0x5c);
  if (iVar4 == 0) {
    return;
  }
  if ((*(char *)(param_2 + 0x7a) == '\0') || ((*(uint *)(param_1 + 0x44) & 0x1000000) == 0)) {
    if (param_5 == 0) {
      return;
    }
  }
  else {
    iVar5 = *(int *)(param_3 + 0x60);
    iVar4 = *(int *)(*(int *)(param_1 + 4) + 0x10);
    sVar1 = *(short *)(((unsigned char *)0x00002e04) + iVar4);
    if (sVar1 == 0x801) {
      iVar2 = param_4 + iVar5 * 0x10;
      *(undefined4 *)(iVar2 + 4) = 0;
      *(float *)(iVar2 + 8) =
           -(*(float *)(((unsigned char *)0x00002df0) + iVar4) * *(float *)(((unsigned char *)0x00002df0) + iVar4));
    }
    else if (sVar1 == 0x2601) {
      iVar2 = param_4 + iVar5 * 0x10;
      *(float *)(iVar2 + 4) = *(float *)(((unsigned char *)0x00002df8) + iVar4) * *(float *)(((unsigned char *)0x00002dfc) + iVar4);
      *(float *)(iVar2 + 8) = -*(float *)(((unsigned char *)0x00002dfc) + iVar4);
    }
    else if (sVar1 == 0x800) {
      iVar2 = param_4 + iVar5 * 0x10;
      *(undefined4 *)(iVar2 + 4) = 0;
      *(float *)(iVar2 + 8) = -*(float *)(((unsigned char *)0x00002df0) + iVar4);
    }
    if (param_5 == 0) {
      puVar3 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,7);
      *(undefined4 **)(0x00002748 + param_1 + 4) = puVar3;
      *puVar3 = 0x880;
      iVar4 = param_4 + iVar5 * 0x10;
      *(int *)(*(int *)(0x00002748 + param_1 + 4) + 4) =
           iVar5 + *(int *)(param_1 + 0x2448) + *(int *)(param_3 + 0x14);
      *(undefined4 *)(*(int *)(0x00002748 + param_1 + 4) + 8) = 0x38882;
      *(undefined4 *)(*(int *)(0x00002748 + param_1 + 4) + 0xc) =
           *(undefined4 *)(param_4 + iVar5 * 0x10);
      *(undefined4 *)(*(int *)(0x00002748 + param_1 + 4) + 0x10) = *(undefined4 *)(iVar4 + 4);
      *(undefined4 *)(*(int *)(0x00002748 + param_1 + 4) + 0x14) = *(undefined4 *)(iVar4 + 8);
      *(undefined4 *)(*(int *)(0x00002748 + param_1 + 4) + 0x18) = *(undefined4 *)(iVar4 + 0xc);
      UNRECOVERED_JUMPTABLE = *(code **)(param_1 + 0x275c);
      iVar4 = *(int *)(0x00002748 + param_1 + 4) + 0x1c;
      *(int *)(0x00002748 + param_1 + 4) = iVar4;
      goto LAB_000620ec;
    }
    iVar4 = *(int *)(param_3 + 0x5c);
  }
  puVar3 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,iVar4 * 4 + 3);
  *(undefined4 **)(0x00002748 + param_1 + 4) = puVar3;
  *puVar3 = 0x880;
  *(int *)(*(int *)(0x00002748 + param_1 + 4) + 4) =
       *(int *)(param_1 + 0x2448) + *(int *)(param_3 + 0x14);
  *(uint *)(*(int *)(0x00002748 + param_1 + 4) + 8) = (iVar4 * 4 + -1) * 0x10000 | 0x8882;
  _memcpy(*(int *)(0x00002748 + param_1 + 4) + 0xc,param_4,iVar4 * 0x10);
  UNRECOVERED_JUMPTABLE = *(code **)(param_1 + 0x275c);
  iVar4 = iVar4 * 0x10 + *(int *)(0x00002748 + param_1 + 4) + 0xc;
  *(int *)(0x00002748 + param_1 + 4) = iVar4;
LAB_000620ec:
                    
                    
  (*UNRECOVERED_JUMPTABLE)(param_1,iVar4);
  return;
}

/* extvsComputeStateKey @ 0x62120 (252 bytes) */
int extvsComputeStateKey(ctx, shader, programState)
  int ctx;
  int shader;
  int programState;
{
  short fogMode;
  uint stateKey;
  uint contextFlags;
  
  contextFlags = *(uint *)(ctx + 0x44);
  stateKey = (uint)*(byte *)(programState + 0x43) & contextFlags >> 7 & 1 |
          ((uint)*(byte *)(programState + 0x44) & contextFlags >> 6 & 1) << 1 |
          (uint)(*(int *)(ctx + 0x148) == 1) << 2;
  if (*(char *)(shader + 0x7a) != '\0') {
    if (*(char *)(shader + 0x6e) != '\0') {
      stateKey = stateKey | contextFlags >> 9 & 8;
    }
    if ((contextFlags & 0x1000000) != 0) {
      fogMode = *(short *)(((unsigned char *)0x00002e04) + *(int *)(*(int *)(ctx + 4) + 0x10));
      if (fogMode == 0x801) {
        stateKey = stateKey | 0x30;
      }
      else if (fogMode == 0x2601) {
        stateKey = stateKey | 0x10;
      }
      else if (fogMode == 0x800) {
        stateKey = stateKey | 0x20;
      }
    }
    if ((contextFlags & 0x800) != 0) {
      stateKey = stateKey | (uint)(byte)((unsigned char *)0x000011d1)[ctx] << 0xf | 0x4000;
    }
  }
  if (*(char *)(shader + 0x6c) == '\0') {
    return stateKey;
  }
  if ((*(uint *)(ctx + 0x44) & 0x400) == 0) {
    return stateKey;
  }
  return stateKey | (uint)(byte)((unsigned char *)0x000011d2)[ctx] << 0x18 | 0x800000;
}

/* extvsStateFree @ 0x62220 (272 bytes) */
int extvsStateFree(param_1, param_2)
  int param_1;
  int param_2;
{
  if (*(int *)(param_2 + 0x1c) != 0) {
    (**(code **)(param_1 + 0x18))(*(int *)(param_2 + 0x1c));
  }
  if (*(int *)(param_2 + 0x24) != 0) {
    (**(code **)(param_1 + 0x18))(*(int *)(param_2 + 0x24));
  }
  if (*(int *)(param_2 + 0x4c) != 0) {
    (**(code **)(param_1 + 0x18))(*(int *)(param_2 + 0x4c));
  }
  if (*(int *)(param_2 + 0x54) != 0) {
    (**(code **)(param_1 + 0x18))(*(int *)(param_2 + 0x54));
  }
  if (*(int *)(param_2 + 0x220) != 0) {
    (**(code **)(param_1 + 0x18))(*(int *)(param_2 + 0x220));
  }
  if (*(int *)(param_2 + 0x228) != 0) {
    (**(code **)(param_1 + 0x18))(*(int *)(param_2 + 0x228));
  }
  if (*(int *)(param_2 + 0x2b8) != 0) {
    (**(code **)(param_1 + 0x18))(*(int *)(param_2 + 0x2b8));
  }
  (**(code **)(param_1 + 0x18))(param_2);
  return FUN_0007dd30(param_1,param_2);
}

/* FUN_00062370 @ 0x62370 (104 bytes) */
int FUN_00062370(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  
  if (param_3 == 0) {
    iVar2 = param_1 + 0x18a0;
    iVar3 = 0x10;
    do {
      pbVar1 = (byte *)(param_2 + 0x71);
      param_2 = param_2 + 1;
      *(uint *)(iVar2 + 8) = -(uint)*pbVar1 >> 0x1f | *(uint *)(iVar2 + 8) & 0xfffffffe;
      iVar2 = iVar2 + 8;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  else {
    iVar2 = param_1 + 0x18a0;
    iVar3 = 0x10;
    do {
      *(uint *)(iVar2 + 8) = *(uint *)(iVar2 + 8) & 0xfffffffe;
      iVar2 = iVar2 + 8;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  return;
}

/* extvsInitLimits @ 0x623e0 (40 bytes) */
int extvsInitLimits(ctx)
  int ctx;
{
  *(undefined4 *)(((unsigned char *)0x000011c4) + ctx) = 0x100;
  *(undefined4 *)(((unsigned char *)0x000011b8) + ctx) = 0x100;
  *(undefined4 *)(((unsigned char *)0x000011bc) + ctx) = 0x10;
  *(undefined4 *)(((unsigned char *)0x000011c8) + ctx) = 0x20;
  *(undefined4 *)(((unsigned char *)0x000011c0) + ctx) = 0x100;
  return;
}

/* FUN_00062410 @ 0x62410 (116 bytes) */
int FUN_00062410(param_1)
  int param_1;
{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)(**(code **)(param_1 + 0xc))(0xc);
  *puVar2 = 0;
  uVar1 = *(undefined4 *)(param_1 + 0x2448);
  puVar2[2] = 0;
  puVar2[1] = uVar1;
  *(undefined4 *)(((unsigned char *)0x000011c8) + param_1) = 0x20;
  *(undefined4 **)(((unsigned char *)0x000011b4) + param_1) = puVar2;
  *(undefined4 *)(((unsigned char *)0x000011c4) + param_1) = 0x100;
  *(undefined4 *)(((unsigned char *)0x000011bc) + param_1) = 0x10;
  *(undefined4 *)(((unsigned char *)0x000011b8) + param_1) = 0x100;
  *(undefined4 *)(((unsigned char *)0x000011c0) + param_1) = 0x100;
  return;
}

/* FUN_00062490 @ 0x62490 (120 bytes) */
int FUN_00062490(param_1)
  int param_1;
{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  
  iVar2 = *(int *)(((unsigned char *)0x000011b4) + param_1);
  puVar1 = *(undefined4 **)(iVar2 + 8);
  while (puVar1 != (undefined4 *)0x0) {
    *(undefined1 *)*puVar1 = 0;
    puVar3 = (undefined4 *)puVar1[1];
    (**(code **)(param_1 + 0x18))(puVar1);
    puVar1 = puVar3;
  }
  *(undefined4 *)(iVar2 + 8) = 0;
  return;
}

/* FUN_00062510 @ 0x62510 (92 bytes) */
int FUN_00062510(param_1)
  int param_1;
{
  if (*(int *)(((unsigned char *)0x000011b4) + param_1) != 0) {
    ((int (*)())FUN_00062490)(param_1);
    (**(code **)(param_1 + 0x18))(*(undefined4 *)(((unsigned char *)0x000011b4) + param_1));
    *(undefined4 *)(((unsigned char *)0x000011b4) + param_1) = 0;
  }
  return;
}

/* extvsStateCacheCreate @ 0x62570 (616 bytes) */
int extvsStateCacheCreate(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  uint param_3;
{
  undefined1 *puVar1;
  int *piVar2;
  undefined4 *puVar3;
  undefined1 *puVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 *puVar7;
  uint uVar8;
  int iVar9;
  
  if (param_3 == 0xffffffff) {
    param_3 = 0;
    uVar8 = *(uint *)(*(int *)(((unsigned char *)0x0000116c) + param_1) + 0x10);
  }
  else {
    uVar8 = param_3 + 1;
  }
  iVar9 = param_3 << 2;
  do {
    puVar4 = (undefined1 *)(**(code **)(param_1 + 0xc))(700);
    *puVar4 = 0;
    *(undefined4 *)(puVar4 + 4) = 0;
    *(undefined4 *)(puVar4 + 8) = 0;
    *(undefined4 *)(puVar4 + 0xc) = 0;
    *(undefined4 *)(puVar4 + 0x10) = 0;
    *(undefined4 *)(puVar4 + 0x14) = 0;
    *(undefined4 *)(puVar4 + 0x18) = 0;
    uVar5 = (**(code **)(param_1 + 0xc))(0x1000);
    *(undefined4 *)(puVar4 + 0x20) = 0x100;
    *(undefined4 *)(puVar4 + 0x1c) = uVar5;
    iVar6 = (**(code **)(param_1 + 0x10))(0x16,0x28);
    *(int *)(puVar4 + 0x24) = iVar6;
    *(undefined4 *)(puVar4 + 0x28) = 0x16;
    *(undefined1 *)(iVar6 + 0x10) = 1;
    puVar4[0x2c] = 0;
    puVar4[0x2d] = 0;
    iVar6 = 8;
    puVar1 = puVar4;
    do {
      puVar1[0x2e] = 0;
      puVar1 = puVar1 + 1;
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
    iVar6 = 8;
    puVar1 = puVar4;
    do {
      puVar1[0x36] = 0;
      puVar1 = puVar1 + 1;
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
    puVar4[0x3e] = 0;
    puVar4[0x3f] = 0;
    puVar4[0x40] = 0;
    puVar4[0x41] = 0;
    iVar6 = 4;
    *(undefined1 *)(param_2 + 0x1b) = 0;
    piVar2 = param_2;
    do {
      *(undefined1 *)((int)piVar2 + 0x6d) = 0;
      piVar2 = (int *)((int)piVar2 + 1);
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
    iVar6 = 8;
    piVar2 = param_2;
    do {
      *(undefined1 *)((int)piVar2 + 0x71) = 0;
      piVar2 = (int *)((int)piVar2 + 1);
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
    *(undefined1 *)((int)param_2 + 0x7a) = 0;
    *(undefined1 *)((int)param_2 + 0x79) = 0;
    puVar4[0x44] = 0;
    puVar4[0x42] = 0;
    puVar4[0x43] = 0;
    *(undefined4 *)(puVar4 + 0x48) = 0;
    uVar5 = (**(code **)(param_1 + 0x10))(0x20,0x28);
    *(undefined4 *)(puVar4 + 0x4c) = uVar5;
    *(undefined4 *)(puVar4 + 0x50) = 0x20;
    uVar5 = (**(code **)(param_1 + 0x10))(0x100,0x28);
    puVar4[0x2b0] = 0;
    *(undefined4 *)(puVar4 + 0x58) = 0x100;
    *(undefined4 *)(puVar4 + 0x54) = uVar5;
    *(undefined4 *)(puVar4 + 0x5c) = 0;
    *(undefined4 *)(puVar4 + 0x74) = 0;
    *(undefined4 *)(puVar4 + 0x220) = 0;
    *(undefined4 *)(puVar4 + 0x224) = 0;
    *(undefined4 *)(puVar4 + 0x228) = 0;
    *(undefined4 *)(puVar4 + 0x22c) = 0;
    *(undefined4 *)(puVar4 + 0x230) = 0;
    *(undefined4 *)(puVar4 + 0x2a4) = 0;
    *(undefined4 *)(puVar4 + 0x2a8) = 0;
    *(undefined4 *)(puVar4 + 0x2ac) = 0;
    *(undefined4 *)(puVar4 + 0x2b4) = 0;
    puVar7 = *(undefined4 **)(*param_2 + iVar9);
    if (puVar7 == (undefined4 *)0x0) {
      puVar7 = (undefined4 *)(**(code **)(param_1 + 0xc))(0x90);
      iVar6 = 0x20;
      puVar3 = puVar7;
      do {
        puVar3 = puVar3 + 1;
        *puVar3 = 0;
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
      puVar7[0x23] = 0;
      puVar7[0x21] = 0;
      puVar7[0x22] = 0;
      *(undefined4 **)(*param_2 + iVar9) = puVar7;
    }
    param_3 = param_3 + 1;
    *puVar7 = puVar4;
    iVar9 = iVar9 + 4;
  } while (param_3 < uVar8);
  return;
}

/* extvsStateCacheFreeAll @ 0x627e4 (328 bytes) */
int extvsStateCacheFreeAll(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  int param_3;
{
  int *piVar1;
  bool bVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int loopIndex;
  int iVar9;
  int *piVar10;
  
  iVar5 = *param_2;
  if (iVar5 != 0) {
    if (param_3 == 0) {
      uVar7 = *(uint *)(((unsigned char *)0x0000118c) + param_1);
      uVar3 = uVar7 + 1;
    }
    else {
      uVar7 = 0;
      uVar3 = *(uint *)(*(int *)(((unsigned char *)0x0000116c) + param_1) + 0x10);
    }
    if (uVar7 < uVar3) {
      iVar9 = uVar7 << 2;
      loopIndex = 0;
      while( true ) {
        piVar10 = *(int **)(iVar5 + iVar9);
        if (piVar10 != (int *)0x0) {
          if (*(char *)(*piVar10 + 0x2b0) == '\0') {
            ((int (*)())extvsStateFree)(param_1,*piVar10);
            *piVar10 = 0;
          }
          if (param_3 != 0) {
            iVar5 = 0;
            piVar4 = piVar10;
            do {
              piVar1 = piVar4 + 1;
              piVar4 = piVar4 + 1;
              iVar6 = *piVar1;
              while (iVar6 != 0) {
                *piVar4 = *(int *)(iVar6 + 0x2b4);
                ((int (*)())extvsStateFree)(param_1,iVar6);
                iVar6 = *piVar4;
              }
              bVar2 = iVar5 != 0x1f;
              iVar5 = iVar5 + 1;
            } while (bVar2);
            if (piVar10[0x22] != 0) {
              (**(code **)(param_1 + 0x18))(piVar10[0x22]);
            }
            (**(code **)(param_1 + 0x18))(piVar10);
            *(undefined4 *)(*param_2 + iVar9) = 0;
          }
        }
        loopIndex = loopIndex + 1;
        iVar9 = iVar9 + 4;
        if (loopIndex == uVar3 - uVar7) break;
        iVar5 = *param_2;
      }
    }
  }
  return;
}

/* FUN_00062940 @ 0x62940 (276 bytes) */
int FUN_00062940(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  int param_3;
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 a5;
  int *a7;
  code *UNRECOVERED_JUMPTABLE;
  int iVar7;
  undefined4 *puVar8;
  
  puVar8 = *(undefined4 **)(param_3 + 0x38);
  a5 = puVar8[2];
  uVar1 = puVar8[3];
  iVar3 = *(int *)(param_3 + 4) * 0x10;
  a7 = *(int **)(*(int *)(((unsigned char *)0x0000118c) + param_1) * 4 + *param_2);
  uVar6 = *puVar8;
  uVar5 = puVar8[1];
  iVar7 = *a7;
  iVar2 = iVar3 + a7[0x22];
  *(undefined4 *)(iVar3 + a7[0x22]) = uVar6;
  *(undefined4 *)(iVar2 + 0xc) = uVar1;
  *(undefined4 *)(iVar2 + 8) = a5;
  *(undefined4 *)(iVar2 + 4) = uVar5;
  puVar4 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,9,param_3,uVar5,uVar6,a5,iVar3,a7);
  *(undefined4 **)(0x00002748 + param_1 + 4) = puVar4;
  *puVar4 = 0x8a1;
  *(undefined4 *)(*(int *)(0x00002748 + param_1 + 4) + 4) = 0;
  *(undefined4 *)(*(int *)(0x00002748 + param_1 + 4) + 8) = 0x880;
  *(int *)(*(int *)(0x00002748 + param_1 + 4) + 0xc) =
       *(int *)(param_1 + 0x2448) + *(int *)(iVar7 + 0x14) + *(int *)(param_3 + 4);
  *(undefined4 *)(*(int *)(0x00002748 + param_1 + 4) + 0x10) = 0x38882;
  uVar1 = *puVar8;
  iVar3 = *(int *)(0x00002748 + param_1 + 4);
  uVar5 = puVar8[1];
  uVar6 = puVar8[2];
  *(undefined4 *)(iVar3 + 0x20) = puVar8[3];
  *(undefined4 *)(iVar3 + 0x14) = uVar1;
  *(undefined4 *)(iVar3 + 0x18) = uVar5;
  *(undefined4 *)(iVar3 + 0x1c) = uVar6;
  UNRECOVERED_JUMPTABLE = *(code **)(param_1 + 0x275c);
  *(int *)(0x00002748 + param_1 + 4) = *(int *)(0x00002748 + param_1 + 4) + 0x24;
                    
                    
  (*UNRECOVERED_JUMPTABLE)(param_1,*(int *)(0x00002748 + param_1 + 4));
  return;
}

/* noop_62a60 @ 0x62a60 (4 bytes) */
int noop_62a60()
{
  return;
}

/* extvsStateCacheInsert @ 0x62a70 (116 bytes) */
int extvsStateCacheInsert(ctx, shader)
  int ctx;
  int *shader;
{
  uint stateKey;
  int *stateTable;
  int state;
  
  stateTable = *(int **)(*(int *)(((unsigned char *)0x0000118c) + ctx) * 4 + *shader);
  state = *stateTable;
  stateKey = ((int (*)())extvsComputeStateKey)(ctx,shader,state);
  *(uint *)(state + 0x48) = stateKey;
  *(int *)(state + 0x2b4) = stateTable[(stateKey & 0x1f) + 1];
  stateTable[(stateKey & 0x1f) + 1] = state;
  *(undefined1 *)(state + 0x2b0) = 1;
  stateTable[0x21] = stateTable[0x21] + 1;
  return;
}

/* extvsBuildStreamDescriptors @ 0x62af0 (5624 bytes) */
int extvsBuildStreamDescriptors(ctx, shader)
  int ctx;
  int *shader;
{
  bool bVar1;
  byte bVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  
  iVar5 = **(int **)(*(int *)(((unsigned char *)0x0000118c) + ctx) * 4 + *shader);
  *(undefined4 *)(iVar5 + 0x29c) = 0;
  *(undefined4 *)(iVar5 + 0x240) = 0;
  *(undefined4 *)(iVar5 + 0x23c) = 1;
  *(undefined4 *)(iVar5 + 0x2a0) = 1;
  *(undefined4 *)(iVar5 + 0x238) = 4;
  *(undefined4 *)(iVar5 + 0x2a8) = 1;
  iVar8 = *(int *)(iVar5 + 0x24);
  *(uint *)(iVar5 + 0x244) = *(uint *)(iVar5 + 0x244) & 0xffff0000 | 3;
  *(uint *)(iVar5 + 0x270) = *(uint *)(iVar5 + 0x270) & 0xffff0000 | 0xf688;
  bVar1 = *(char *)(iVar8 + 0x38) != '\0';
  if (bVar1) {
    *(undefined4 *)(iVar5 + 0x2a0) = 2;
    *(undefined4 *)(iVar5 + 0x238) = 8;
    *(undefined4 *)(iVar5 + 0x244) = 0x1030003;
    *(undefined4 *)(iVar5 + 0x270) = 0xf688f688;
  }
  bVar3 = !bVar1;
  uVar7 = (uint)bVar1;
  bVar1 = bVar3;
  if (*(char *)(iVar8 + 0x60) != '\0') {
    bVar1 = !bVar3;
    *(uint *)(iVar5 + 0x238) =
         (*(uint *)(iVar5 + 0x238) & 0x7f) + 4 & 0x7f | *(uint *)(iVar5 + 0x238) & 0xffffff80;
    if (bVar1) {
      iVar8 = uVar7 * 4 + iVar5;
      *(uint *)(iVar8 + 0x244) = *(uint *)(iVar8 + 0x244) & 0xffff0000 | 0x203;
      *(uint *)(iVar8 + 0x270) = (uint)bVar3 | *(uint *)(iVar8 + 0x270) & 0xffff0000 | 0xf688;
    }
    else {
      iVar8 = uVar7 * 4;
      uVar7 = uVar7 + 1;
      iVar8 = iVar8 + iVar5;
      *(uint *)(iVar8 + 0x244) = *(uint *)(iVar8 + 0x244) & 0xffff | 0x2030000;
      *(uint *)(iVar8 + 0x270) = *(uint *)(iVar8 + 0x270) & 0xffff | 0xf6880000;
    }
    iVar8 = *(int *)(iVar5 + 0x24);
    *(int *)(iVar5 + 0x2a0) = *(int *)(iVar5 + 0x2a0) + 1;
  }
  if (*(char *)(iVar8 + 0x88) != '\0') {
    bVar1 = !bVar1;
    *(uint *)(iVar5 + 0x238) =
         (*(uint *)(iVar5 + 0x238) & 0x7f) + 4 & 0x7f | *(uint *)(iVar5 + 0x238) & 0xffffff80;
    if (bVar1) {
      iVar8 = uVar7 * 4 + iVar5;
      *(uint *)(iVar8 + 0x244) = *(uint *)(iVar8 + 0x244) & 0xffff0000 | 0x303;
      *(uint *)(iVar8 + 0x270) = *(uint *)(iVar8 + 0x270) & 0xffff0000 | 0xf688;
    }
    else {
      iVar8 = uVar7 * 4;
      uVar7 = uVar7 + 1;
      iVar8 = iVar8 + iVar5;
      *(uint *)(iVar8 + 0x244) = *(uint *)(iVar8 + 0x244) & 0xffff | 0x3030000;
      *(uint *)(iVar8 + 0x270) = *(uint *)(iVar8 + 0x270) & 0xffff | 0xf6880000;
    }
    iVar8 = *(int *)(iVar5 + 0x24);
    *(int *)(iVar5 + 0x2a0) = *(int *)(iVar5 + 0x2a0) + 1;
  }
  if (*(char *)(iVar8 + 0xb0) != '\0') {
    bVar1 = !bVar1;
    *(uint *)(iVar5 + 0x238) =
         (*(uint *)(iVar5 + 0x238) & 0x7f) + 4 & 0x7f | *(uint *)(iVar5 + 0x238) & 0xffffff80;
    if (bVar1) {
      iVar8 = uVar7 * 4 + iVar5;
      *(uint *)(iVar8 + 0x244) = *(uint *)(iVar8 + 0x244) & 0xffff0000 | 0x403;
      *(uint *)(iVar8 + 0x270) = *(uint *)(iVar8 + 0x270) & 0xffff0000 | 0xf688;
    }
    else {
      iVar8 = uVar7 * 4;
      uVar7 = uVar7 + 1;
      iVar8 = iVar8 + iVar5;
      *(uint *)(iVar8 + 0x244) = *(uint *)(iVar8 + 0x244) & 0xffff | 0x4030000;
      *(uint *)(iVar8 + 0x270) = *(uint *)(iVar8 + 0x270) & 0xffff | 0xf6880000;
    }
    iVar8 = *(int *)(iVar5 + 0x24);
    *(int *)(iVar5 + 0x2a0) = *(int *)(iVar5 + 0x2a0) + 1;
  }
  if (*(char *)(iVar8 + 0xd8) != '\0') {
    bVar1 = !bVar1;
    *(uint *)(iVar5 + 0x238) =
         (*(uint *)(iVar5 + 0x238) & 0x7f) + 4 & 0x7f | *(uint *)(iVar5 + 0x238) & 0xffffff80;
    if (bVar1) {
      iVar8 = uVar7 * 4 + iVar5;
      *(uint *)(iVar8 + 0x244) = *(uint *)(iVar8 + 0x244) & 0xffff0000 | 0x503;
      *(uint *)(iVar8 + 0x270) = *(uint *)(iVar8 + 0x270) & 0xffff0000 | 0xf688;
    }
    else {
      iVar8 = uVar7 * 4;
      uVar7 = uVar7 + 1;
      iVar8 = iVar8 + iVar5;
      *(uint *)(iVar8 + 0x244) = *(uint *)(iVar8 + 0x244) & 0xffff | 0x5030000;
      *(uint *)(iVar8 + 0x270) = *(uint *)(iVar8 + 0x270) & 0xffff | 0xf6880000;
    }
    iVar8 = *(int *)(iVar5 + 0x24);
    *(int *)(iVar5 + 0x2a0) = *(int *)(iVar5 + 0x2a0) + 1;
  }
  if (*(char *)(iVar8 + 0x100) != '\0') {
    bVar1 = !bVar1;
    *(uint *)(iVar5 + 0x238) =
         (*(uint *)(iVar5 + 0x238) & 0x7f) + 4 & 0x7f | *(uint *)(iVar5 + 0x238) & 0xffffff80;
    if (bVar1) {
      iVar8 = uVar7 * 4 + iVar5;
      *(uint *)(iVar8 + 0x244) = *(uint *)(iVar8 + 0x244) & 0xffff0000 | 0x603;
      *(uint *)(iVar8 + 0x270) = *(uint *)(iVar8 + 0x270) & 0xffff0000 | 0xf688;
    }
    else {
      iVar8 = uVar7 * 4;
      uVar7 = uVar7 + 1;
      iVar8 = iVar8 + iVar5;
      *(uint *)(iVar8 + 0x244) = *(uint *)(iVar8 + 0x244) & 0xffff | 0x6030000;
      *(uint *)(iVar8 + 0x270) = *(uint *)(iVar8 + 0x270) & 0xffff | 0xf6880000;
    }
    iVar8 = *(int *)(iVar5 + 0x24);
    *(int *)(iVar5 + 0x2a0) = *(int *)(iVar5 + 0x2a0) + 1;
  }
  if (*(char *)(iVar8 + 0x128) != '\0') {
    bVar1 = !bVar1;
    *(uint *)(iVar5 + 0x238) =
         (*(uint *)(iVar5 + 0x238) & 0x7f) + 4 & 0x7f | *(uint *)(iVar5 + 0x238) & 0xffffff80;
    if (bVar1) {
      iVar8 = uVar7 * 4 + iVar5;
      *(uint *)(iVar8 + 0x244) = *(uint *)(iVar8 + 0x244) & 0xffff0000 | 0x703;
      *(uint *)(iVar8 + 0x270) = *(uint *)(iVar8 + 0x270) & 0xffff0000 | 0xf688;
    }
    else {
      iVar8 = uVar7 * 4;
      uVar7 = uVar7 + 1;
      iVar8 = iVar8 + iVar5;
      *(uint *)(iVar8 + 0x244) = *(uint *)(iVar8 + 0x244) & 0xffff | 0x7030000;
      *(uint *)(iVar8 + 0x270) = *(uint *)(iVar8 + 0x270) & 0xffff | 0xf6880000;
    }
    iVar8 = *(int *)(iVar5 + 0x24);
    *(int *)(iVar5 + 0x2a0) = *(int *)(iVar5 + 0x2a0) + 1;
  }
  if (*(char *)(iVar8 + 0x150) != '\0') {
    bVar1 = !bVar1;
    *(uint *)(iVar5 + 0x238) =
         (*(uint *)(iVar5 + 0x238) & 0x7f) + 4 & 0x7f | *(uint *)(iVar5 + 0x238) & 0xffffff80;
    if (bVar1) {
      iVar8 = uVar7 * 4 + iVar5;
      *(uint *)(iVar8 + 0x244) = *(uint *)(iVar8 + 0x244) & 0xffff0000 | 0x803;
      *(uint *)(iVar8 + 0x270) = *(uint *)(iVar8 + 0x270) & 0xffff0000 | 0xf688;
    }
    else {
      iVar8 = uVar7 * 4;
      uVar7 = uVar7 + 1;
      iVar8 = iVar8 + iVar5;
      *(uint *)(iVar8 + 0x244) = *(uint *)(iVar8 + 0x244) & 0xffff | 0x8030000;
      *(uint *)(iVar8 + 0x270) = *(uint *)(iVar8 + 0x270) & 0xffff | 0xf6880000;
    }
    iVar8 = *(int *)(iVar5 + 0x24);
    *(int *)(iVar5 + 0x2a0) = *(int *)(iVar5 + 0x2a0) + 1;
  }
  if (*(char *)(iVar8 + 0x178) != '\0') {
    bVar1 = !bVar1;
    *(uint *)(iVar5 + 0x238) =
         (*(uint *)(iVar5 + 0x238) & 0x7f) + 4 & 0x7f | *(uint *)(iVar5 + 0x238) & 0xffffff80;
    if (bVar1) {
      iVar8 = uVar7 * 4 + iVar5;
      *(uint *)(iVar8 + 0x244) = *(uint *)(iVar8 + 0x244) & 0xffff0000 | 0x903;
      *(uint *)(iVar8 + 0x270) = *(uint *)(iVar8 + 0x270) & 0xffff0000 | 0xf688;
    }
    else {
      iVar8 = uVar7 * 4;
      uVar7 = uVar7 + 1;
      iVar8 = iVar8 + iVar5;
      *(uint *)(iVar8 + 0x244) = *(uint *)(iVar8 + 0x244) & 0xffff | 0x9030000;
      *(uint *)(iVar8 + 0x270) = *(uint *)(iVar8 + 0x270) & 0xffff | 0xf6880000;
    }
    iVar8 = *(int *)(iVar5 + 0x24);
    *(int *)(iVar5 + 0x2a0) = *(int *)(iVar5 + 0x2a0) + 1;
  }
  if (*(char *)(iVar8 + 0x1a0) != '\0') {
    bVar1 = !bVar1;
    *(uint *)(iVar5 + 0x238) =
         (*(uint *)(iVar5 + 0x238) & 0x7f) + 4 & 0x7f | *(uint *)(iVar5 + 0x238) & 0xffffff80;
    if (bVar1) {
      iVar8 = uVar7 * 4 + iVar5;
      *(uint *)(iVar8 + 0x244) = *(uint *)(iVar8 + 0x244) & 0xffff0000 | 0xa03;
      *(uint *)(iVar8 + 0x270) = *(uint *)(iVar8 + 0x270) & 0xffff0000 | 0xf688;
    }
    else {
      iVar8 = uVar7 * 4;
      uVar7 = uVar7 + 1;
      iVar8 = iVar8 + iVar5;
      *(uint *)(iVar8 + 0x244) = *(uint *)(iVar8 + 0x244) & 0xffff | 0xa030000;
      *(uint *)(iVar8 + 0x270) = *(uint *)(iVar8 + 0x270) & 0xffff | 0xf6880000;
    }
    iVar8 = *(int *)(iVar5 + 0x24);
    *(int *)(iVar5 + 0x2a0) = *(int *)(iVar5 + 0x2a0) + 1;
  }
  if (*(char *)(iVar8 + 0x1c8) != '\0') {
    bVar1 = !bVar1;
    *(uint *)(iVar5 + 0x238) =
         (*(uint *)(iVar5 + 0x238) & 0x7f) + 4 & 0x7f | *(uint *)(iVar5 + 0x238) & 0xffffff80;
    if (bVar1) {
      iVar8 = uVar7 * 4 + iVar5;
      *(uint *)(iVar8 + 0x244) = *(uint *)(iVar8 + 0x244) & 0xffff0000 | 0xb03;
      *(uint *)(iVar8 + 0x270) = *(uint *)(iVar8 + 0x270) & 0xffff0000 | 0xf688;
    }
    else {
      iVar8 = uVar7 * 4;
      uVar7 = uVar7 + 1;
      iVar8 = iVar8 + iVar5;
      *(uint *)(iVar8 + 0x244) = *(uint *)(iVar8 + 0x244) & 0xffff | 0xb030000;
      *(uint *)(iVar8 + 0x270) = *(uint *)(iVar8 + 0x270) & 0xffff | 0xf6880000;
    }
    iVar8 = *(int *)(iVar5 + 0x24);
    *(int *)(iVar5 + 0x2a0) = *(int *)(iVar5 + 0x2a0) + 1;
  }
  if (*(char *)(iVar8 + 0x1f0) != '\0') {
    bVar1 = !bVar1;
    *(uint *)(iVar5 + 0x238) =
         (*(uint *)(iVar5 + 0x238) & 0x7f) + 4 & 0x7f | *(uint *)(iVar5 + 0x238) & 0xffffff80;
    if (bVar1) {
      iVar8 = uVar7 * 4 + iVar5;
      *(uint *)(iVar8 + 0x244) = *(uint *)(iVar8 + 0x244) & 0xffff0000 | 0xc03;
      *(uint *)(iVar8 + 0x270) = *(uint *)(iVar8 + 0x270) & 0xffff0000 | 0xf688;
    }
    else {
      iVar8 = uVar7 * 4;
      uVar7 = uVar7 + 1;
      iVar8 = iVar8 + iVar5;
      *(uint *)(iVar8 + 0x244) = *(uint *)(iVar8 + 0x244) & 0xffff | 0xc030000;
      *(uint *)(iVar8 + 0x270) = *(uint *)(iVar8 + 0x270) & 0xffff | 0xf6880000;
    }
    iVar8 = *(int *)(iVar5 + 0x24);
    *(int *)(iVar5 + 0x2a0) = *(int *)(iVar5 + 0x2a0) + 1;
  }
  if (*(char *)(iVar8 + 0x218) != '\0') {
    bVar1 = !bVar1;
    *(uint *)(iVar5 + 0x238) =
         (*(uint *)(iVar5 + 0x238) & 0x7f) + 4 & 0x7f | *(uint *)(iVar5 + 0x238) & 0xffffff80;
    if (bVar1) {
      iVar8 = uVar7 * 4 + iVar5;
      *(uint *)(iVar8 + 0x244) = *(uint *)(iVar8 + 0x244) & 0xffff0000 | 0xd03;
      *(uint *)(iVar8 + 0x270) = *(uint *)(iVar8 + 0x270) & 0xffff0000 | 0xf688;
    }
    else {
      iVar8 = uVar7 * 4;
      uVar7 = uVar7 + 1;
      iVar8 = iVar8 + iVar5;
      *(uint *)(iVar8 + 0x244) = *(uint *)(iVar8 + 0x244) & 0xffff | 0xd030000;
      *(uint *)(iVar8 + 0x270) = *(uint *)(iVar8 + 0x270) & 0xffff | 0xf6880000;
    }
    iVar8 = *(int *)(iVar5 + 0x24);
    *(int *)(iVar5 + 0x2a0) = *(int *)(iVar5 + 0x2a0) + 1;
  }
  if (*(char *)(iVar8 + 0x240) != '\0') {
    bVar1 = !bVar1;
    *(uint *)(iVar5 + 0x238) =
         (*(uint *)(iVar5 + 0x238) & 0x7f) + 4 & 0x7f | *(uint *)(iVar5 + 0x238) & 0xffffff80;
    if (bVar1) {
      iVar8 = uVar7 * 4 + iVar5;
      *(uint *)(iVar8 + 0x244) = *(uint *)(iVar8 + 0x244) & 0xffff0000 | 0xe03;
      *(uint *)(iVar8 + 0x270) = *(uint *)(iVar8 + 0x270) & 0xffff0000 | 0xf688;
    }
    else {
      iVar8 = uVar7 * 4;
      uVar7 = uVar7 + 1;
      iVar8 = iVar8 + iVar5;
      *(uint *)(iVar8 + 0x244) = *(uint *)(iVar8 + 0x244) & 0xffff | 0xe030000;
      *(uint *)(iVar8 + 0x270) = *(uint *)(iVar8 + 0x270) & 0xffff | 0xf6880000;
    }
    iVar8 = *(int *)(iVar5 + 0x24);
    *(int *)(iVar5 + 0x2a0) = *(int *)(iVar5 + 0x2a0) + 1;
  }
  if (*(char *)(iVar8 + 0x268) != '\0') {
    bVar1 = !bVar1;
    *(uint *)(iVar5 + 0x238) =
         (*(uint *)(iVar5 + 0x238) & 0x7f) + 4 & 0x7f | *(uint *)(iVar5 + 0x238) & 0xffffff80;
    if (bVar1) {
      iVar8 = uVar7 * 4 + iVar5;
      *(uint *)(iVar8 + 0x244) = *(uint *)(iVar8 + 0x244) & 0xffff0000 | 0xf03;
      *(uint *)(iVar8 + 0x270) = *(uint *)(iVar8 + 0x270) & 0xffff0000 | 0xf688;
    }
    else {
      iVar8 = uVar7 * 4;
      uVar7 = uVar7 + 1;
      iVar8 = iVar8 + iVar5;
      *(uint *)(iVar8 + 0x244) = *(uint *)(iVar8 + 0x244) & 0xffff | 0xf030000;
      *(uint *)(iVar8 + 0x270) = *(uint *)(iVar8 + 0x270) & 0xffff | 0xf6880000;
    }
    iVar8 = *(int *)(iVar5 + 0x24);
    *(int *)(iVar5 + 0x2a0) = *(int *)(iVar5 + 0x2a0) + 1;
  }
  if (*(char *)(iVar8 + 0x290) != '\0') {
    bVar1 = !bVar1;
    *(uint *)(iVar5 + 0x238) =
         (*(uint *)(iVar5 + 0x238) & 0x7f) + 4 & 0x7f | *(uint *)(iVar5 + 0x238) & 0xffffff80;
    if (bVar1) {
      iVar8 = uVar7 * 4 + iVar5;
      *(uint *)(iVar8 + 0x244) = *(uint *)(iVar8 + 0x244) & 0xffff0000 | 0x1003;
      *(uint *)(iVar8 + 0x270) = *(uint *)(iVar8 + 0x270) & 0xffff0000 | 0xf688;
    }
    else {
      iVar8 = uVar7 * 4;
      uVar7 = uVar7 + 1;
      iVar8 = iVar8 + iVar5;
      *(uint *)(iVar8 + 0x244) = *(uint *)(iVar8 + 0x244) & 0xffff | 0x10030000;
      *(uint *)(iVar8 + 0x270) = *(uint *)(iVar8 + 0x270) & 0xffff | 0xf6880000;
    }
    iVar8 = *(int *)(iVar5 + 0x24);
    *(int *)(iVar5 + 0x2a0) = *(int *)(iVar5 + 0x2a0) + 1;
  }
  if (*(char *)(iVar8 + 0x2b8) != '\0') {
    bVar1 = !bVar1;
    *(uint *)(iVar5 + 0x238) =
         (*(uint *)(iVar5 + 0x238) & 0x7f) + 4 & 0x7f | *(uint *)(iVar5 + 0x238) & 0xffffff80;
    if (bVar1) {
      iVar8 = uVar7 * 4 + iVar5;
      *(uint *)(iVar8 + 0x244) = *(uint *)(iVar8 + 0x244) & 0xffff0000 | 0x1103;
      *(uint *)(iVar8 + 0x270) = *(uint *)(iVar8 + 0x270) & 0xffff0000 | 0xf688;
    }
    else {
      iVar8 = uVar7 * 4;
      uVar7 = uVar7 + 1;
      iVar8 = iVar8 + iVar5;
      *(uint *)(iVar8 + 0x244) = *(uint *)(iVar8 + 0x244) & 0xffff | 0x11030000;
      *(uint *)(iVar8 + 0x270) = *(uint *)(iVar8 + 0x270) & 0xffff | 0xf6880000;
    }
    iVar8 = *(int *)(iVar5 + 0x24);
    *(int *)(iVar5 + 0x2a0) = *(int *)(iVar5 + 0x2a0) + 1;
  }
  if (*(char *)(iVar8 + 0x2e0) != '\0') {
    bVar1 = !bVar1;
    *(uint *)(iVar5 + 0x238) =
         (*(uint *)(iVar5 + 0x238) & 0x7f) + 4 & 0x7f | *(uint *)(iVar5 + 0x238) & 0xffffff80;
    if (bVar1) {
      iVar8 = uVar7 * 4 + iVar5;
      *(uint *)(iVar8 + 0x244) = *(uint *)(iVar8 + 0x244) & 0xffff0000 | 0x1203;
      *(uint *)(iVar8 + 0x270) = *(uint *)(iVar8 + 0x270) & 0xffff0000 | 0xf688;
    }
    else {
      iVar8 = uVar7 * 4;
      uVar7 = uVar7 + 1;
      iVar8 = iVar8 + iVar5;
      *(uint *)(iVar8 + 0x244) = *(uint *)(iVar8 + 0x244) & 0xffff | 0x12030000;
      *(uint *)(iVar8 + 0x270) = *(uint *)(iVar8 + 0x270) & 0xffff | 0xf6880000;
    }
    iVar8 = *(int *)(iVar5 + 0x24);
    *(int *)(iVar5 + 0x2a0) = *(int *)(iVar5 + 0x2a0) + 1;
  }
  if (*(char *)(iVar8 + 0x308) != '\0') {
    bVar1 = !bVar1;
    *(uint *)(iVar5 + 0x238) =
         (*(uint *)(iVar5 + 0x238) & 0x7f) + 4 & 0x7f | *(uint *)(iVar5 + 0x238) & 0xffffff80;
    if (bVar1) {
      iVar8 = uVar7 * 4 + iVar5;
      *(uint *)(iVar8 + 0x244) = *(uint *)(iVar8 + 0x244) & 0xffff0000 | 0x1303;
      *(uint *)(iVar8 + 0x270) = *(uint *)(iVar8 + 0x270) & 0xffff0000 | 0xf688;
    }
    else {
      iVar8 = uVar7 * 4;
      uVar7 = uVar7 + 1;
      iVar8 = iVar8 + iVar5;
      *(uint *)(iVar8 + 0x244) = *(uint *)(iVar8 + 0x244) & 0xffff | 0x13030000;
      *(uint *)(iVar8 + 0x270) = *(uint *)(iVar8 + 0x270) & 0xffff | 0xf6880000;
    }
    iVar8 = *(int *)(iVar5 + 0x24);
    *(int *)(iVar5 + 0x2a0) = *(int *)(iVar5 + 0x2a0) + 1;
  }
  if (*(char *)(iVar8 + 0x330) != '\0') {
    bVar1 = !bVar1;
    *(uint *)(iVar5 + 0x238) =
         (*(uint *)(iVar5 + 0x238) & 0x7f) + 4 & 0x7f | *(uint *)(iVar5 + 0x238) & 0xffffff80;
    if (bVar1) {
      iVar8 = uVar7 * 4 + iVar5;
      *(uint *)(iVar8 + 0x244) = *(uint *)(iVar8 + 0x244) & 0xffff0000 | 0x1403;
      *(uint *)(iVar8 + 0x270) = *(uint *)(iVar8 + 0x270) & 0xffff0000 | 0xf688;
    }
    else {
      iVar8 = uVar7 * 4;
      uVar7 = uVar7 + 1;
      iVar8 = iVar8 + iVar5;
      *(uint *)(iVar8 + 0x244) = *(uint *)(iVar8 + 0x244) & 0xffff | 0x14030000;
      *(uint *)(iVar8 + 0x270) = *(uint *)(iVar8 + 0x270) & 0xffff | 0xf6880000;
    }
    iVar8 = *(int *)(iVar5 + 0x24);
    *(int *)(iVar5 + 0x2a0) = *(int *)(iVar5 + 0x2a0) + 1;
  }
  if (*(char *)(iVar8 + 0x358) == '\0') {
    uVar6 = *(uint *)(iVar5 + 0x2a0);
  }
  else {
    bVar1 = !bVar1;
    *(uint *)(iVar5 + 0x238) =
         (*(uint *)(iVar5 + 0x238) & 0x7f) + 4 & 0x7f | *(uint *)(iVar5 + 0x238) & 0xffffff80;
    if (bVar1) {
      iVar8 = uVar7 * 4 + iVar5;
      *(uint *)(iVar8 + 0x244) = *(uint *)(iVar8 + 0x244) & 0xffff0000 | 0x1503;
      *(uint *)(iVar8 + 0x270) = *(uint *)(iVar8 + 0x270) & 0xffff0000 | 0xf688;
    }
    else {
      iVar8 = uVar7 * 4;
      uVar7 = uVar7 + 1;
      iVar8 = iVar8 + iVar5;
      *(uint *)(iVar8 + 0x244) = *(uint *)(iVar8 + 0x244) & 0xffff | 0x15030000;
      *(uint *)(iVar8 + 0x270) = *(uint *)(iVar8 + 0x270) & 0xffff | 0xf6880000;
    }
    uVar6 = *(int *)(iVar5 + 0x2a0) + 1;
    *(uint *)(iVar5 + 0x2a0) = uVar6;
  }
  if (uVar6 < 2) {
    *(uint *)(iVar5 + 0x234) = *(uint *)(iVar5 + 0x234) | 2;
    *(uint *)(iVar5 + 0x238) =
         (*(uint *)(iVar5 + 0x238) & 0x7f) + 4 & 0x7f | *(uint *)(iVar5 + 0x238) & 0xffffff80;
    *(uint *)(iVar5 + 0x244) = *(uint *)(iVar5 + 0x244) & 0x2000ffff | 0x21030000;
    *(uint *)(iVar5 + 0x2a0) = uVar6 + 1;
    *(uint *)(iVar5 + 0x270) = *(uint *)(iVar5 + 0x270) & 0xffff | 0xf6880000;
  }
  else {
    if (bVar1) {
      iVar8 = uVar7 * 4 + iVar5;
      *(uint *)(iVar8 + 0x244) = *(uint *)(iVar8 + 0x244) | 0x2000;
    }
    else {
      iVar8 = uVar7 * 4 + iVar5;
      *(uint *)(iVar8 + 0x240) = *(uint *)(iVar8 + 0x240) | 0x20000000;
    }
    if (0x10 < *(uint *)(iVar5 + 0x2a0)) {
      *(undefined1 *)(shader + 4) = 0;
    }
  }
  uVar7 = shader[0x1b];
  if ((((uVar7 & 0xffffff) == 0) && (*(char *)(shader + 0x1c) == '\0')) &&
     (*(char *)((int)shader + 0x7a) == '\0')) {
    iVar8 = *(int *)(iVar5 + 0x2a8);
  }
  else {
    iVar8 = *(int *)(iVar5 + 0x2a8) + 1;
    *(uint *)(iVar5 + 0x23c) = *(uint *)(iVar5 + 0x23c) | 2;
    *(int *)(iVar5 + 0x2a8) = iVar8;
    uVar7 = shader[0x1b];
  }
  if ((((uVar7 & 0xffff) != 0) || (*(char *)(shader + 0x1c) != '\0')) ||
     (*(char *)((int)shader + 0x7a) != '\0')) {
    iVar8 = iVar8 + 1;
    *(int *)(iVar5 + 0x2a8) = iVar8;
    *(uint *)(iVar5 + 0x23c) = *(uint *)(iVar5 + 0x23c) | 4;
  }
  if ((*(char *)((int)shader + 0x6f) != '\0') || (*(char *)(shader + 0x1c) != '\0')) {
    iVar8 = iVar8 + 2;
    *(int *)(iVar5 + 0x2a8) = iVar8;
    *(uint *)(iVar5 + 0x23c) = *(uint *)(iVar5 + 0x23c) | 0x18;
  }
  if (*(char *)((int)shader + 0x79) != '\0') {
    iVar8 = iVar8 + 1;
    *(int *)(iVar5 + 0x2a8) = iVar8;
    *(uint *)(iVar5 + 0x23c) = *(uint *)(iVar5 + 0x23c) | 0x10000;
  }
  uVar7 = 0;
  iVar9 = 8;
  do {
    bVar2 = *(byte *)((int)shader + 0x71);
    if (bVar2 != 0) {
      iVar4 = 4;
      if ((bVar2 & 8) == 0) {
        iVar4 = 3 - (uint)((bVar2 & 4) == 0);
      }
      uVar6 = iVar4 << (uVar7 & 0x3f);
      iVar8 = iVar8 + 1;
      *(int *)(iVar5 + 0x2a8) = iVar8;
      *(uint *)(iVar5 + 0x240) = uVar6 | *(uint *)(iVar5 + 0x240);
      *(uint *)(iVar5 + 0x29c) = uVar6 | *(uint *)(iVar5 + 0x29c);
    }
    shader = (int *)((int)shader + 1);
    uVar7 = uVar7 + 3;
    iVar9 = iVar9 + -1;
  } while (iVar9 != 0);
  if (iVar8 == 1) {
    *(undefined4 *)(iVar5 + 0x2a8) = 2;
    *(uint *)(iVar5 + 0x240) = *(uint *)(iVar5 + 0x240) & 0xff1fffff | 0x800000;
    *(uint *)(iVar5 + 0x29c) = *(uint *)(iVar5 + 0x29c) & 0xff1fffff | 0x800000;
    return;
  }
  return;
}

/* gldCurrentAttributePacketHeader @ 0x640f0 (220 bytes) */
int gldCurrentAttributePacketHeader(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  int param_3;
{
  uint uVar1;
  
  uVar1 = (param_3 + -1) * 0x10000;
  switch(param_2) {
  default:
    return 0;
  case 2:
    return uVar1 | 0x8c8;
  case 3:
    return uVar1 | 0x8cc;
  case 4:
    return uVar1 | 0x8d0;
  case 5:
    return uVar1 | 0x8d4;
  case 6:
    return uVar1 | 0x8d8;
  case 7:
    return uVar1 | 0x8dc;
  case 8:
    return uVar1 | 0x8e0;
  case 9:
    return uVar1 | 0x8e4;
  case 10:
    return uVar1 | 0x8e8;
  case 0xb:
    return uVar1 | 0x8ec;
  case 0xc:
    return uVar1 | 0x8f0;
  case 0xd:
    return uVar1 | 0x8f4;
  case 0xe:
    return uVar1 | 0x8f8;
  case 0xf:
    return uVar1 | 0x8fc;
  case 0x10:
    return uVar1 | 0x900;
  case 0x11:
    return uVar1 | 0x904;
  case 0x13:
    return uVar1 | 0x90c;
  case 0x14:
    return uVar1 | 0x910;
  case 0x15:
    return uVar1 | 0x914;
  }
}

/* FUN_00064230 @ 0x64230 (1256 bytes) */
int FUN_00064230(param_1, param_2)
  int param_1;
  int *param_2;
{
  byte bVar1;
  uint uVar2;
  int iVar3;
  uint *puVar4;
  uint *puVar5;
  int iVar6;
  bool bVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  
  iVar13 = **(int **)(*(int *)(((unsigned char *)0x0000118c) + param_1) * 4 + *param_2);
  puVar4 = *(uint **)(((unsigned char *)0x00001384) + iVar13);
  iVar3 = *(int *)(iVar13 + 0x150);
  if (puVar4 == (uint *)0x0) {
    puVar4 = (uint *)(**(code **)(param_1 + 0xc))(0x7c);
    *(uint **)(((unsigned char *)0x00001384) + iVar13) = puVar4;
  }
  uVar9 = puVar4[5];
  puVar4[3] = 0;
  puVar4[4] = 0;
  iVar8 = 0;
  puVar4[1] = 4;
  puVar4[2] = 1;
  uVar2 = puVar4[0x10];
  puVar4[5] = uVar9 & 0xffffff00 | 3;
  uVar10 = *(uint *)(((unsigned char *)0x000055e8) + iVar3);
  puVar4[0x10] = uVar2 & 0xfffff000 | 0x688;
  puVar4[5] = (uVar10 & 0x1f) << 8 | uVar9 & 0xffff0000 | 3;
  if (*(int *)(((unsigned char *)0x000055e8) + iVar3) != 0x16) {
    iVar8 = 0xf;
  }
  *puVar4 = 1;
  iVar14 = 0;
  bVar7 = true;
  puVar4[0x1b] = 1;
  puVar4[0x1d] = 1;
  puVar4[0x10] = iVar8 << 0xc | uVar2 & 0xffff0000 | 0x688;
  puVar5 = &DAT_001dbab8;
  iVar12 = 1;
  iVar15 = 0x15;
  iVar8 = iVar13;
  do {
    if (0 < *(int *)(iVar8 + 100)) {
      iVar11 = *(int *)(iVar8 + 0xbc);
      puVar4[1] = (puVar4[1] & 0x7f) + 4 & 0x7f | puVar4[1] & 0xffffff80;
      if (bVar7) {
        iVar6 = 0;
        iVar11 = iVar11 * 4 + iVar3 + 0x24;
        uVar2 = puVar4[iVar14 + 5];
        puVar4[iVar14 + 5] = uVar2 & 0xff00ffff | 0x30000;
        puVar4[iVar14 + 5] =
             (*(uint *)(((unsigned char *)0x000055c4) + iVar11) & 0x1f) << 0x18 | uVar2 & 0xffff | 0x30000;
        puVar4[iVar14 + 0x10] = puVar4[iVar14 + 0x10] & 0xf000ffff | 0x6880000;
        if (*(int *)(((unsigned char *)0x000055c4) + iVar11) != 0x16) {
          iVar6 = 0xf;
        }
        bVar7 = false;
        puVar4[iVar14 + 0x10] = iVar6 << 0x1c | puVar4[iVar14 + 0x10] & 0xfffffff;
        iVar14 = iVar14 + 1;
      }
      else {
        iVar6 = 0;
        iVar11 = iVar11 * 4 + iVar3 + 0x24;
        uVar2 = puVar4[iVar14 + 5];
        puVar4[iVar14 + 5] = uVar2 & 0xffffff00 | 3;
        puVar4[iVar14 + 5] =
             (*(uint *)(((unsigned char *)0x000055c4) + iVar11) & 0x1f) << 8 | uVar2 & 0xffff0000 | 3;
        puVar4[iVar14 + 0x10] = puVar4[iVar14 + 0x10] & 0xfffff000 | 0x688;
        if (*(int *)(((unsigned char *)0x000055c4) + iVar11) != 0x16) {
          iVar6 = 0xf;
        }
        bVar7 = true;
        puVar4[iVar14 + 0x10] = iVar6 << 0xc | puVar4[iVar14 + 0x10] & 0xffff0fff;
      }
      iVar12 = iVar12 + 1;
      uVar2 = puVar4[0x1b] + 1;
      puVar4[0x1b] = uVar2;
      *puVar4 = *puVar4 | *puVar5;
      if (iVar12 == *(int *)(iVar13 + 0x110)) goto LAB_000644c0;
    }
    iVar8 = iVar8 + 4;
    puVar5 = puVar5 + 1;
    iVar15 = iVar15 + -1;
  } while (iVar15 != 0);
  uVar2 = puVar4[0x1b];
LAB_000644c0:
  if (uVar2 < 2) {
    *puVar4 = *puVar4 | 2;
    puVar4[1] = (puVar4[1] & 0x7f) + 4 & 0x7f | puVar4[1] & 0xffffff80;
    puVar4[5] = puVar4[5] & 0x2000ffff | 0x21030000;
    puVar4[0x1b] = uVar2 + 1;
    puVar4[0x10] = puVar4[0x10] & 0xffff | 0xf6880000;
  }
  else {
    if (bVar7) {
      puVar4[iVar14 + 5] = puVar4[iVar14 + 5] | 0x2000;
    }
    else {
      puVar4[iVar14 + 4] = puVar4[iVar14 + 4] | 0x20000000;
    }
    if (0x10 < puVar4[0x1b]) {
      *(undefined1 *)(param_2 + 4) = 0;
    }
  }
  uVar2 = param_2[0x1b];
  if ((((uVar2 & 0xffffff) != 0) || (*(char *)(param_2 + 0x1c) != '\0')) ||
     (((unsigned char *)0x000013c8)[iVar13] != '\0')) {
    puVar4[2] = puVar4[2] | 2;
    puVar4[0x1d] = puVar4[0x1d] + 1;
    uVar2 = param_2[0x1b];
  }
  if ((((uVar2 & 0xffff) != 0) || (*(char *)(param_2 + 0x1c) != '\0')) ||
     (((unsigned char *)0x000013c8)[iVar13] != '\0')) {
    puVar4[2] = puVar4[2] | 4;
    puVar4[0x1d] = puVar4[0x1d] + 1;
  }
  if ((*(char *)((int)param_2 + 0x6f) != '\0') || (*(char *)(param_2 + 0x1c) != '\0')) {
    puVar4[2] = puVar4[2] | 0x18;
    puVar4[0x1d] = puVar4[0x1d] + 2;
  }
  if (*(char *)((int)param_2 + 0x79) != '\0') {
    puVar4[2] = puVar4[2] | 0x10000;
    puVar4[0x1d] = puVar4[0x1d] + 1;
  }
  uVar2 = 0;
  iVar13 = 8;
  do {
    bVar1 = *(byte *)((int)param_2 + 0x71);
    if (bVar1 != 0) {
      iVar8 = 4;
      if ((bVar1 & 8) == 0) {
        iVar8 = 3 - (uint)((bVar1 & 4) == 0);
      }
      uVar9 = iVar8 << (uVar2 & 0x3f);
      puVar4[3] = uVar9 | puVar4[3];
      puVar4[4] = uVar9 | puVar4[4];
      puVar4[0x1d] = puVar4[0x1d] + 1;
    }
    param_2 = (int *)((int)param_2 + 1);
    uVar2 = uVar2 + 3;
    iVar13 = iVar13 + -1;
  } while (iVar13 != 0);
  puVar4[2] = *(uint *)(((unsigned char *)0x00005498) + iVar3);
  uVar9 = *(uint *)(((unsigned char *)0x0000549c) + iVar3);
  puVar4[3] = uVar9;
  uVar2 = *(uint *)(((unsigned char *)0x00005434) + iVar3);
  puVar4[0x1d] = uVar2;
  if (uVar2 == 1) {
    puVar4[0x1d] = 2;
    puVar4[3] = uVar9 & 0xff1fffff | 0x800000;
    puVar4[4] = puVar4[4] & 0xff1fffff | 0x800000;
  }
  return;
}

/* FUN_00064720 @ 0x64720 (304 bytes) */
int FUN_00064720(param_1)
  int param_1;
{
  undefined4 *puVar1;
  byte bVar2;
  int iVar3;
  undefined4 in_r5;
  undefined4 in_r6;
  undefined4 in_r7;
  int a5;
  int iVar4;
  undefined4 a6;
  uint loopIndex;
  code *a7;
  int iVar6;
  
  a5 = **(int **)(*(int *)(((unsigned char *)0x0000118c) + param_1) * 4 + **(int **)(((unsigned char *)0x00001168) + param_1));
  if (*(char *)(*(int **)(((unsigned char *)0x00001168) + param_1) + 4) != '\0') {
    if ((*(uint *)(param_1 + 0x8c) & 0x40000000) == 0) {
      *(undefined4 *)(param_1 + 0x1ca0) = *(undefined4 *)(a5 + 0x234);
      *(undefined4 *)(param_1 + 0x1ca4) = *(undefined4 *)(a5 + 0x238);
      *(undefined4 *)(param_1 + 0x1b9c) = *(undefined4 *)(a5 + 0x23c);
      *(undefined4 *)(param_1 + 0x1ba0) = *(undefined4 *)(a5 + 0x240);
      iVar3 = *(int *)(a5 + 0x2a0);
      if (iVar3 + 1U >> 1 != 0) {
        loopIndex = 0;
        iVar4 = param_1;
        iVar6 = a5;
        do {
          loopIndex = loopIndex + 1;
          *(undefined4 *)(iVar4 + 0x1be4) = *(undefined4 *)(iVar6 + 0x244);
          puVar1 = (undefined4 *)(iVar6 + 0x270);
          iVar6 = iVar6 + 4;
          *(undefined4 *)(iVar4 + 0x1c04) = *puVar1;
          iVar4 = iVar4 + 4;
          iVar3 = *(int *)(a5 + 0x2a0);
        } while (loopIndex < iVar3 + 1U >> 1);
      }
      *(int *)(param_1 + 0x2438) = iVar3;
      a7 = *(code **)(((unsigned char *)0x00001334) + param_1);
      a6 = *(undefined4 *)(a5 + 0x2a0);
      *(undefined4 *)(param_1 + 0x1b78) = 0;
      *(undefined4 *)(param_1 + 0x243c) = a6;
      bVar2 = *(byte *)(a5 + 0x36);
      *(uint *)(param_1 + 0x1930) = *(uint *)(param_1 + 0x1930) | 0x40000;
      *(uint *)(param_1 + 0x1b78) = bVar2 & 3;
      (*a7)(param_1,1,in_r5,in_r6,in_r7,a5,a6,a7);
      *(undefined1 *)(param_1 + 0x2435) = 1;
    }
  }
  return;
}

/* FUN_00064850 @ 0x64850 (436 bytes) */
int FUN_00064850(param_1)
  int param_1;
{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  bool bVar4;
  int *piVar5;
  undefined4 *puVar6;
  int iVar7;
  uint loopIndex;
  undefined4 *puVar9;
  
  piVar5 = *(int **)(((unsigned char *)0x00001168) + param_1);
  puVar6 = *(undefined4 **)
            (((unsigned char *)0x00001384) + **(int **)(*(int *)(((unsigned char *)0x0000118c) + param_1) * 4 + *piVar5));
  if ((*(char *)(piVar5 + 4) != '\0') && ((*(uint *)(param_1 + 0x8c) & 0x40000000) == 0)) {
    if ((*(int *)(param_1 + 0x1b9c) != puVar6[2]) ||
       (bVar4 = false, *(int *)(param_1 + 0x1ba0) != puVar6[3])) {
      bVar4 = true;
    }
    *(undefined4 *)(param_1 + 0x1ca0) = *puVar6;
    *(undefined4 *)(param_1 + 0x1ca4) = puVar6[1];
    *(undefined4 *)(param_1 + 0x1b9c) = puVar6[2];
    *(undefined4 *)(param_1 + 0x1ba0) = puVar6[3];
    iVar2 = puVar6[0x1b];
    if (iVar2 + 1U >> 1 != 0) {
      loopIndex = 0;
      iVar7 = param_1;
      puVar9 = puVar6;
      do {
        loopIndex = loopIndex + 1;
        *(undefined4 *)(iVar7 + 0x1be4) = puVar9[5];
        puVar1 = puVar9 + 0x10;
        puVar9 = puVar9 + 1;
        *(undefined4 *)(iVar7 + 0x1c04) = *puVar1;
        iVar7 = iVar7 + 4;
        iVar2 = puVar6[0x1b];
      } while (loopIndex < iVar2 + 1U >> 1);
    }
    *(int *)(param_1 + 0x2438) = iVar2;
    uVar3 = puVar6[0x1b];
    *(undefined4 *)(param_1 + 0x1b78) = 0;
    *(undefined4 *)(param_1 + 0x243c) = uVar3;
    if ((piVar5[0xc] & 1U) != 0) {
      *(undefined4 *)(param_1 + 0x1b78) = 1;
    }
    iVar2 = *(int *)(((unsigned char *)0x0000148c) + param_1);
    *(uint *)(param_1 + 0x1930) = *(uint *)(param_1 + 0x1930) | 0x40000;
    if (iVar2 != 0) {
      iVar2 = *(int *)(iVar2 + 0x14);
      if (((*(int *)(param_1 + 0x1b50) != *(int *)(iVar2 + 0x5658)) ||
          (iVar7 = *(int *)(param_1 + 0x1ba4), iVar7 != *(int *)(iVar2 + 0x5650))) || (bVar4)) {
        (**(code **)(((unsigned char *)0x00001334) + param_1))(param_1,1);
        *(undefined4 *)(iVar2 + 0x5650) = *(undefined4 *)(param_1 + 0x1ba4);
        *(undefined4 *)(iVar2 + 0x5658) = *(undefined4 *)(param_1 + 0x1b50);
        iVar7 = *(int *)(param_1 + 0x1ba4);
      }
      *(int *)(iVar2 + 0x5650) = iVar7;
      *(undefined4 *)(iVar2 + 0x5658) = *(undefined4 *)(param_1 + 0x1b50);
    }
    *(undefined1 *)(param_1 + 0x2435) = 1;
  }
  return;
}

/* FUN_00064a10 @ 0x64a10 (1304 bytes) */
int FUN_00064a10(param_1, param_2)
  int param_1;
  int *param_2;
{
  code *pcVar1;
  undefined8 *puVar2;
  undefined4 *puVar3;
  undefined8 *puVar4;
  char *in_r5;
  undefined8 *puVar5;
  undefined4 in_r6;
  undefined4 in_r7;
  int in_r8;
  int iVar6;
  int iVar7;
  undefined8 *puVar8;
  int iVar9;
  int iVar10;
  char cVar11;
  int iVar12;
  int iVar13;
  uint uVar14;
  uint uVar15;
  undefined4 *puVar16;
  uint uVar17;
  int *piVar18;
  uint uVar19;
  int *piVar20;
  char *pcVar21;
  undefined8 uVar22;
  undefined8 uVar23;
  undefined8 uVar24;
  undefined8 uVar25;
  undefined8 uVar26;
  undefined8 uVar27;
  undefined8 uVar28;
  
  if (*param_2 != 0) {
    piVar20 = *(int **)(((unsigned char *)0x000011b4) + param_1);
    puVar16 = *(undefined4 **)(*(int *)(((unsigned char *)0x0000118c) + param_1) * 4 + *param_2);
    pcVar21 = (char *)*puVar16;
    uVar17 = *(uint *)(pcVar21 + 0x18);
    uVar19 = *(uint *)(pcVar21 + 0x5c);
    if ((*(char *)(param_2 + 4) != '\0') && ((*(uint *)(param_1 + 0x8c) & 0x40000000) == 0)) {
      if (*pcVar21 != '\0') {
LAB_00064c00:
        if (uVar19 != 0) {
          if (*(int *)(pcVar21 + 0x2b8) == 0) {
            iVar6 = puVar16[0x22];
            iVar9 = param_2[8];
            piVar18 = *(int **)(pcVar21 + 0x220) + *(int *)(pcVar21 + 0x224);
            piVar20 = *(int **)(pcVar21 + 0x220);
            while (piVar20 + 4 <= piVar18) {
              iVar12 = iVar9 + *piVar20 * 0x54;
              iVar10 = iVar9 + piVar20[3] * 0x54;
              iVar7 = iVar9 + piVar20[1] * 0x54;
              iVar13 = iVar9 + piVar20[2] * 0x54;
              puVar5 = *(undefined8 **)(iVar12 + 0x38);
              puVar4 = *(undefined8 **)(iVar7 + 0x38);
              puVar2 = *(undefined8 **)(iVar13 + 0x38);
              puVar8 = *(undefined8 **)(iVar10 + 0x38);
              uVar22 = puVar5[1];
              iVar12 = *(int *)(iVar12 + 4) * 0x10;
              uVar24 = puVar2[1];
              uVar25 = puVar4[1];
              uVar23 = puVar8[1];
              uVar28 = *puVar4;
              in_r8 = *(int *)(iVar7 + 4) * 0x10;
              uVar27 = *puVar2;
              uVar26 = *puVar8;
              iVar7 = *(int *)(iVar13 + 4) * 0x10;
              iVar10 = *(int *)(iVar10 + 4) * 0x10;
              *(undefined8 *)(iVar6 + iVar12) = *puVar5;
              *(undefined8 *)(iVar6 + iVar12 + 8) = uVar22;
              *(undefined8 *)(iVar6 + in_r8) = uVar28;
              *(undefined8 *)(iVar6 + in_r8 + 8) = uVar25;
              *(undefined8 *)(iVar6 + iVar7) = uVar27;
              *(undefined8 *)(iVar6 + iVar7 + 8) = uVar24;
              *(undefined8 *)(iVar6 + iVar10) = uVar26;
              *(undefined8 *)(iVar6 + iVar10 + 8) = uVar23;
              piVar20 = piVar20 + 4;
            }
            for (; piVar20 < piVar18; piVar20 = piVar20 + 1) {
              iVar12 = iVar9 + *piVar20 * 0x54;
              puVar2 = *(undefined8 **)(iVar12 + 0x38);
              uVar22 = puVar2[1];
              iVar12 = *(int *)(iVar12 + 4) * 0x10;
              *(undefined8 *)(iVar6 + iVar12) = *puVar2;
              *(undefined8 *)(iVar6 + iVar12 + 8) = uVar22;
            }
          }
          puVar3 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,2);
          *(undefined4 **)(0x00002748 + param_1 + 4) = puVar3;
          *puVar3 = 0x8a1;
          *(undefined4 *)(*(int *)(0x00002748 + param_1 + 4) + 4) = 0;
          iVar6 = *(int *)(0x00002748 + param_1 + 4);
          pcVar1 = *(code **)(param_1 + 0x275c);
          *(int *)(0x00002748 + param_1 + 4) = iVar6 + 8;
          (*pcVar1)(param_1,iVar6 + 8);
          in_r6 = puVar16[0x22];
          in_r7 = 1;
          in_r5 = pcVar21;
          ((int (*)())vpUploadConstantsWithFog)(param_1,param_2,pcVar21,in_r6,1);
        }
        uVar14 = *(uint *)(param_1 + 0x1b90);
        cVar11 = '\0';
        uVar19 = *(uint *)(pcVar21 + 4) & 0x3ff;
        *(uint *)(param_1 + 0x1b90) = uVar19 | uVar14 & 0xfffffc00;
        uVar17 = (*(int *)(pcVar21 + 4) + *(int *)(pcVar21 + 8)) * 0x400 & 0xffc00;
        *(uint *)(param_1 + 0x1b90) = uVar17 | uVar19 | uVar14 & 0xfff00000;
        *(uint *)(param_1 + 0x1b90) =
             (*(uint *)(pcVar21 + 0x10) & 0x3ff) << 0x14 | uVar17 | uVar19 | uVar14 & 0xc0000000;
        *(uint *)(param_1 + 0x1b94) =
             *(int *)(pcVar21 + 4) + *(int *)(pcVar21 + 0xc) & 0x3ffU |
             *(uint *)(param_1 + 0x1b94) & 0xfffffc00;
        *(char *)(param_1 + 0x1b8f) = (char)*(undefined4 *)(pcVar21 + 0x14);
        if (*(int *)(pcVar21 + 0x5c) != 0) {
          cVar11 = (char)*(int *)(pcVar21 + 0x5c) + -1;
        }
        *(char *)(param_1 + 0x1b8d) = cVar11;
        puVar16 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,4);
        *(undefined4 **)(0x00002748 + param_1 + 4) = puVar16;
        *puVar16 = 0x208b4;
        *(undefined4 *)(*(int *)(0x00002748 + param_1 + 4) + 4) =
             *(undefined4 *)(param_1 + 0x1b90);
        *(undefined4 *)(*(int *)(0x00002748 + param_1 + 4) + 8) =
             *(undefined4 *)(param_1 + 0x1b8c);
        *(undefined4 *)(*(int *)(0x00002748 + param_1 + 4) + 0xc) =
             *(undefined4 *)(param_1 + 0x1b94);
        iVar6 = *(int *)(0x00002748 + param_1 + 4);
        pcVar1 = *(code **)(param_1 + 0x275c);
        *(int *)(0x00002748 + param_1 + 4) = iVar6 + 0x10;
        (*pcVar1)(param_1,iVar6 + 0x10,in_r5,in_r6,in_r7,in_r8,pcVar1);
        puVar16 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,2);
        *(undefined4 **)(0x00002748 + param_1 + 4) = puVar16;
        *puVar16 = 0x8b7;
        iVar9 = *(int *)(0x00002748 + param_1 + 4);
        *(undefined4 *)(iVar9 + 4) = *(undefined4 *)(param_1 + 0x1b98);
        iVar6 = *(int *)(0x00002748 + param_1 + 4);
        pcVar1 = *(code **)(param_1 + 0x275c);
        *(int *)(0x00002748 + param_1 + 4) = iVar6 + 8;
        (*pcVar1)(param_1,iVar6 + 8,in_r5,in_r6,in_r7,in_r8,iVar9);
        FUN_00050ef0(param_1,*(undefined4 *)(pcVar21 + 0x2a4),*(undefined4 *)(pcVar21 + 0x2a8),
                     *(undefined4 *)(pcVar21 + 0x2ac));
        ((int (*)())FUN_00064720)(param_1);
        return;
      }
      uVar15 = 0;
      uVar14 = 0;
      iVar9 = *piVar20;
      iVar6 = *(int *)(param_1 + 0xd8);
      iVar12 = piVar20[1] - *(int *)(param_1 + 0x2448);
LAB_00064a98:
      if (iVar6 == 1) goto LAB_00064ac0;
      if (iVar6 == 0) {
        uVar15 = 0x80 - iVar9;
        uVar14 = 0x80 - iVar12;
        goto LAB_00064af0;
      }
      if (iVar6 != 2) goto LAB_00064af0;
      do {
        uVar15 = 0x100 - iVar9;
        uVar14 = 0x100 - iVar12;
        *(uint *)(param_1 + 0x8c) = *(uint *)(param_1 + 0x8c) | 0x48000;
LAB_00064af0:
        while( true ) {
          if ((uVar17 <= uVar15) && (uVar19 <= uVar14)) {
            *(int *)(pcVar21 + 0x14) = iVar12;
            *(int *)(pcVar21 + 4) = iVar9;
            *(uint *)(pcVar21 + 0x10) = uVar17 + iVar9 + -1;
            *piVar20 = uVar17 + *piVar20;
            piVar20[1] = uVar19 + piVar20[1];
            ((int (*)())vpUploadConstantArray)(param_1,pcVar21);
            *pcVar21 = '\x01';
            FUN_0007dcd0(param_1,pcVar21);
            uVar19 = *(uint *)(pcVar21 + 0x5c);
            goto LAB_00064c00;
          }
          if (iVar6 == 1) break;
          if (iVar6 != 0) {
            if (iVar6 == 2) {
              puVar3 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,2);
              *(undefined4 **)(0x00002748 + param_1 + 4) = puVar3;
              *puVar3 = 0x8a1;
              *(undefined4 *)(*(int *)(0x00002748 + param_1 + 4) + 4) = 0;
              pcVar1 = *(code **)(param_1 + 0x275c);
              iVar6 = *(int *)(0x00002748 + param_1 + 4) + 8;
              *(int *)(0x00002748 + param_1 + 4) = iVar6;
              (*pcVar1)(param_1,iVar6,in_r5,in_r6,in_r7,in_r8,iVar6);
              *piVar20 = 0;
              piVar20[1] = *(int *)(param_1 + 0x2448);
              ((int (*)())FUN_00062490)(param_1);
              iVar6 = *(int *)(param_1 + 0xd8);
              iVar9 = 0;
              iVar12 = 0;
            }
            goto LAB_00064a98;
          }
          iVar6 = 1;
          *(undefined4 *)(param_1 + 0xd8) = 1;
LAB_00064ac0:
          uVar15 = 0xfe - iVar9;
          uVar14 = 0x100 - iVar12;
          *(uint *)(param_1 + 0x8c) = *(uint *)(param_1 + 0x8c) | 0x40000;
        }
        iVar6 = 2;
        *(undefined4 *)(param_1 + 0xd8) = 2;
      } while( true );
    }
  }
  return;
}

/* FUN_00064f40 @ 0x64f40 (708 bytes) */
int FUN_00064f40(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  byte *pbVar1;
  byte bVar2;
  code *pcVar3;
  undefined4 *puVar4;
  uint uVar5;
  undefined4 in_r5;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  int iVar6;
  bool bVar7;
  int *piVar8;
  int *piVar9;
  undefined4 *puVar10;
  int iVar11;
  
  if ((*(uint *)(param_1 + 0x44) & 0x100000) == 0) {
    iVar6 = param_1 + 0x18a0;
    iVar11 = 0x10;
    do {
      *(uint *)(iVar6 + 8) = *(uint *)(iVar6 + 8) & 0xfffffffe;
      iVar6 = iVar6 + 8;
      iVar11 = iVar11 + -1;
    } while (iVar11 != 0);
  }
  else {
    piVar9 = *(int **)(((unsigned char *)0x00001168) + param_1);
    if (((*(byte *)(param_1 + 0x2d) & 8) != 0) && ((*(uint *)(param_1 + 0x8c) & 0x10000) != 0)) {
      puVar10 = *(undefined4 **)(((unsigned char *)0x000011b4) + param_1);
      puVar4 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,2);
      *(undefined4 **)(0x00002748 + param_1 + 4) = puVar4;
      *puVar4 = 0x8a1;
      *(undefined4 *)(*(int *)(0x00002748 + param_1 + 4) + 4) = 0;
      pcVar3 = *(code **)(param_1 + 0x275c);
      iVar6 = *(int *)(0x00002748 + param_1 + 4) + 8;
      *(int *)(0x00002748 + param_1 + 4) = iVar6;
      (*pcVar3)(param_1,iVar6,in_r5,in_r6,in_r7,in_r8,iVar6);
      *puVar10 = 0;
      puVar10[1] = *(undefined4 *)(param_1 + 0x2448);
      ((int (*)())FUN_00062490)(param_1);
      *(uint *)(param_1 + 0x8c) = *(uint *)(param_1 + 0x8c) & 0xfffeffff;
    }
    if (*(char *)(piVar9 + 4) != '\0') {
      iVar11 = *(int *)(((unsigned char *)0x0000118c) + param_1);
      piVar8 = *(int **)(iVar11 * 4 + *piVar9);
      iVar6 = *piVar8;
      uVar5 = ((int (*)())extvsComputeStateKey)(param_1,piVar9,iVar6);
      if ((*(char *)(param_1 + 0x31) == '\0') ||
         (bVar7 = true, *(char *)(piVar9[1] + iVar11) == '\0')) {
        bVar7 = false;
      }
      if (((uVar5 != *(uint *)(iVar6 + 0x48)) || (*(int *)(iVar6 + 0x18) != piVar9[0x15])) ||
         (bVar7)) {
        for (iVar6 = piVar8[(uVar5 & 0x1f) + 1]; iVar6 != 0; iVar6 = *(int *)(iVar6 + 0x2b4)) {
          if (*(uint *)(iVar6 + 0x48) == uVar5) {
            if (!bVar7) {
              *piVar8 = iVar6;
              piVar9[0x15] = *(int *)(iVar6 + 0x18);
              *(undefined4 *)(((unsigned char *)0x00001174) + param_1) = *(undefined4 *)(iVar6 + 0x18);
              goto LAB_00065094;
            }
            break;
          }
        }
        FUN_000546d0(param_1,piVar9);
LAB_00065094:
        *(byte *)(param_1 + 0x2d) = *(byte *)(param_1 + 0x2d) | 3;
      }
      else {
        bVar2 = *(byte *)(param_1 + 0x2d);
        if ((bVar2 & 4) == 0) {
          if ((bVar2 & 3) == 0) {
            return;
          }
          puVar4 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,2);
          *(undefined4 **)(0x00002748 + param_1 + 4) = puVar4;
          *puVar4 = 0x8a1;
          *(uint *)(*(int *)(0x00002748 + param_1 + 4) + 4) = bVar2 & 4;
          iVar11 = *(int *)(0x00002748 + param_1 + 4);
          pcVar3 = *(code **)(param_1 + 0x275c);
          *(int *)(0x00002748 + param_1 + 4) = iVar11 + 8;
          (*pcVar3)(param_1,iVar11 + 8);
          ((int (*)())vpUploadConstantsWithFog)(param_1,piVar9,iVar6,piVar8[0x22],0);
          return;
        }
      }
      ((int (*)())FUN_00064a10)(param_1,piVar9);
      iVar6 = param_1 + 0x18a0;
      iVar11 = 0x10;
      do {
        pbVar1 = (byte *)((int)piVar9 + 0x71);
        piVar9 = (int *)((int)piVar9 + 1);
        *(uint *)(iVar6 + 8) = -(uint)*pbVar1 >> 0x1f | *(uint *)(iVar6 + 8) & 0xfffffffe;
        iVar6 = iVar6 + 8;
        iVar11 = iVar11 + -1;
      } while (iVar11 != 0);
      return;
    }
  }
  return;
}

/* FUN_000651e0 @ 0x651e0 (400 bytes) */
int FUN_000651e0(param_1)
  int param_1;
{
  int iVar1;
  undefined4 *puVar2;
  undefined4 in_r5;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  code *pcVar3;
  int a6;
  char *pcVar4;
  undefined4 *puVar5;
  int *piVar6;
  
  for (puVar5 = *(undefined4 **)(*(int *)(((unsigned char *)0x000011b4) + param_1) + 8); puVar5 != (undefined4 *)0x0
      ; puVar5 = (undefined4 *)puVar5[1]) {
    ((int (*)())vpUploadConstantArray)(param_1,*puVar5);
  }
  piVar6 = *(int **)(((unsigned char *)0x00001168) + param_1);
  puVar5 = *(undefined4 **)(*(int *)(((unsigned char *)0x0000118c) + param_1) * 4 + *piVar6);
  pcVar4 = (char *)*puVar5;
  if ((*(char *)(piVar6 + 4) != '\0') && (*pcVar4 != '\0')) {
    puVar2 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,4);
    *(undefined4 **)(0x00002748 + param_1 + 4) = puVar2;
    *puVar2 = 0x208b4;
    *(undefined4 *)(*(int *)(0x00002748 + param_1 + 4) + 4) = *(undefined4 *)(param_1 + 0x1b90);
    *(undefined4 *)(*(int *)(0x00002748 + param_1 + 4) + 8) = *(undefined4 *)(param_1 + 0x1b8c);
    *(undefined4 *)(*(int *)(0x00002748 + param_1 + 4) + 0xc) = *(undefined4 *)(param_1 + 0x1b94);
    iVar1 = *(int *)(0x00002748 + param_1 + 4);
    pcVar3 = *(code **)(param_1 + 0x275c);
    *(int *)(0x00002748 + param_1 + 4) = iVar1 + 0x10;
    (*pcVar3)(param_1,iVar1 + 0x10,in_r5,in_r6,in_r7,in_r8,pcVar3);
    puVar2 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,2);
    *(undefined4 **)(0x00002748 + param_1 + 4) = puVar2;
    *puVar2 = 0x8b7;
    a6 = *(int *)(0x00002748 + param_1 + 4);
    *(undefined4 *)(a6 + 4) = *(undefined4 *)(param_1 + 0x1b98);
    iVar1 = *(int *)(0x00002748 + param_1 + 4);
    pcVar3 = *(code **)(param_1 + 0x275c);
    *(int *)(0x00002748 + param_1 + 4) = iVar1 + 8;
    (*pcVar3)(param_1,iVar1 + 8,in_r5,in_r6,in_r7,in_r8,a6);
    FUN_00050ef0(param_1,*(undefined4 *)(pcVar4 + 0x2a4),*(undefined4 *)(pcVar4 + 0x2a8),
                 *(undefined4 *)(pcVar4 + 0x2ac));
    ((int (*)())vpUploadConstantsWithFog)(param_1,piVar6,pcVar4,puVar5[0x22],1);
  }
  *(uint *)(param_1 + 0x8c) = *(uint *)(param_1 + 0x8c) & 0xfffeffff;
  return;
}

/* FUN_00065370 @ 0x65370 (636 bytes) */
int FUN_00065370(param_1)
  int param_1;
{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 extraout_r4;
  undefined4 extraout_r4_00;
  undefined4 in_r5;
  uint in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  int iVar4;
  code *a6;
  undefined4 in_r10;
  undefined8 uVar5;
  undefined4 local_38;
  undefined4 local_34 [8];
  
  cVar1 = *(char *)(param_1 + 0x29);
  if (*(char *)(param_1 + 0x1868) == '\0') {
    (**(code **)(((unsigned char *)0x000012e0) + param_1))(param_1);
    return;
  }
  *(undefined1 *)(param_1 + 0x126) = 0;
  (**(code **)(((unsigned char *)0x0000133c) + param_1))(param_1);
  if (cVar1 == '\0') {
    iVar4 = *(int *)(param_1 + 0x13c);
    if (iVar4 == *(int *)(param_1 + 0x140)) {
      iVar2 = *(int *)(param_1 + 0x148);
      if (iVar2 == *(int *)(param_1 + 0x144)) {
        return;
      }
    }
    else {
      iVar2 = *(int *)(param_1 + 0x148);
    }
  }
  else {
    iVar4 = *(int *)(param_1 + 0x13c);
    iVar2 = *(int *)(param_1 + 0x148);
  }
  *(int *)(param_1 + 0x140) = iVar4;
  *(int *)(param_1 + 0x144) = iVar2;
  if (*(char *)(param_1 + 0x124) != '\0') {
LAB_00065500:
    (**(code **)(((unsigned char *)0x000012dc) + param_1))(param_1);
    return;
  }
  if ((*(uint *)(param_1 + 0x44) & 0x100000) != 0) {
    return;
  }
  uVar5 = FUN_0009edd0(param_1,param_1 + 0x1874);
  iVar2 = (int)((ulonglong)uVar5 >> 0x20);
  uVar3 = (undefined4)uVar5;
  if (iVar2 == 0) {
    FUN_0009d080(param_1,uVar3,in_r5,in_r6,in_r7,in_r8);
    uVar3 = FUN_0009bd00(param_1);
    (**(code **)(((unsigned char *)0x000012b4) + param_1))(param_1);
    in_r5 = ffvpBuildProgram(param_1,1,&local_38,local_34,uVar3,in_r8,iVar4,in_r10);
    in_r6 = (uint)*(byte *)(param_1 + 0x131);
    uVar5 = FUN_0009c800(param_1,param_1 + 0x1874,in_r5,in_r6,local_38,local_34[0],uVar3,
                         (uint)*(byte *)(param_1 + 0x126));
    iVar2 = (int)((ulonglong)uVar5 >> 0x20);
    in_r7 = local_38;
    in_r8 = local_34[0];
    if (*(char *)(param_1 + 0x126) != '\0') {
      a6 = *(code **)(((unsigned char *)0x0000133c) + param_1);
      *(uint *)(param_1 + 0x8c) = *(uint *)(param_1 + 0x8c) | 0x40000000;
      *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x1020;
      *(undefined1 *)(param_1 + 0x29) = 1;
      (*a6)(param_1,(int)uVar5,in_r5,in_r6,local_38,local_34[0],a6);
      goto LAB_00065500;
    }
  }
  else if (*(char *)(iVar2 + 0x59) != '\0') goto LAB_0006559c;
  *(int *)(param_1 + 0x14c) = iVar2;
  (**(code **)(((unsigned char *)0x000012c4) + param_1))(param_1,iVar2);
  if (*(int *)(iVar2 + 0x54) + 0x750 == *(int *)(((unsigned char *)0x0000148c) + param_1)) {
    (**(code **)((int)((unsigned char *)0x000012a0) + param_1))(param_1);
    uVar3 = extraout_r4;
  }
  else {
    in_r5 = *(undefined4 *)(iVar2 + 0x3c);
    (**(code **)((int)((unsigned char *)0x00001294) + param_1))(param_1,iVar2,in_r5);
    uVar3 = extraout_r4_00;
  }
  if (*(char *)(*(int *)(iVar2 + 0x54) + 0x752) == '\0') {
    return;
  }
LAB_0006559c:
  *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x1020;
  *(uint *)(param_1 + 0x8c) = *(uint *)(param_1 + 0x8c) | 0x40000000;
  *(undefined1 *)(param_1 + 0x126) = 1;
  *(undefined1 *)(param_1 + 0x29) = 1;
  (**(code **)(((unsigned char *)0x0000133c) + param_1))(param_1,uVar3,in_r5,in_r6,in_r7,in_r8,1);
  (**(code **)(((unsigned char *)0x000012dc) + param_1))(param_1);
  return;
}

/* FUN_00065610 @ 0x65610 (152 bytes) */
int FUN_00065610(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  _memset(param_2 + 0x68,0xffffffff,0x3c);
  *(undefined4 *)(param_2 + 0xa0) = 7;
  *(undefined4 *)(param_2 + 0x90) = 3;
  *(undefined4 *)(param_2 + 0x68) = 0;
  *(undefined4 *)(param_2 + 0x84) = 0;
  *(undefined4 *)(param_2 + 0x8c) = 2;
  *(undefined4 *)(param_2 + 0x88) = 1;
  *(undefined4 *)(param_2 + 0x98) = 5;
  *(undefined4 *)(param_2 + 0x6c) = 0;
  *(undefined4 *)(param_2 + 0x74) = 0;
  *(undefined4 *)(param_2 + 0x7c) = 0;
  *(undefined4 *)(param_2 + 0x70) = 0;
  *(undefined4 *)(param_2 + 0x78) = 1;
  *(undefined4 *)(param_2 + 0x80) = 1;
  *(undefined4 *)(param_2 + 0x94) = 4;
  *(undefined4 *)(param_2 + 0x9c) = 6;
  return;
}

/* FUN_000656b0 @ 0x656b0 (780 bytes) */
int FUN_000656b0(param_1)
  int param_1;
{
  uint loopIndex;
  byte bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 in_r7;
  undefined4 in_r8;
  uint in_r9;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  undefined4 local_74;
  uint local_70 [2];
  undefined4 local_68;
  uint local_64;
  
  _memset(local_70,0,0x30);
  uVar8 = *(uint *)(param_1 + 0x44);
  local_68 = *(undefined4 *)(param_1 + 0x1804);
  local_70[0] = local_70[0] | 8;
  if ((uVar8 & 0xc00) != 0) {
    in_r9 = uVar8 >> 9 & 2;
    local_64 = uVar8 >> 0xb & 1 | in_r9 | (uint)(byte)((unsigned char *)0x000011d3)[param_1] << 2;
  }
  iVar11 = *(int *)(param_1 + 0x14c);
  if ((iVar11 == 0) || (iVar3 = _memcmp(iVar11,local_70,0x30), iVar4 = iVar11, iVar3 != 0)) {
    iVar4 = FUN_0009edd0(param_1,local_70);
    if (iVar4 == 0) {
      uVar10 = *(uint *)(param_1 + 0x1804);
      bVar1 = ((unsigned char *)0x000011d2)[param_1];
      uVar8 = *(uint *)(param_1 + 0x44) >> 10 & 1;
      puVar5 = (undefined4 *)FUN_00092bf0(param_1,1,0);
      *puVar5 = 0;
      ((int (*)())FUN_00065610)(param_1,puVar5);
      if (uVar8 == 0) {
        uVar2 = uVar10 >> 3 & 1;
        uVar12 = uVar10 >> 1 & 1;
        uVar9 = 0;
      }
      else {
        uVar2 = uVar10 >> 3 & 1;
        uVar12 = uVar10 >> 1 & 1;
        in_r9 = (uVar10 & 1) + uVar12;
        uVar9 = (uint)bVar1 + uVar2 * 2 + in_r9 + 2;
      }
      FUN_00092d40(puVar5,uVar8,(uint)bVar1);
      if (uVar12 == 0) {
        iVar4 = 1;
        iVar11 = 2;
      }
      else {
        iVar4 = 2;
        iVar11 = 3;
        puVar5[0x13] = 1;
        FUN_00093130(puVar5);
      }
      puVar5[3] = iVar4;
      uVar6 = 0;
      uVar7 = 0;
      FUN_00092ea0(puVar5,3,0,0);
      if ((uVar10 & 1) != 0) {
        puVar5[4] = iVar11;
        uVar6 = 1;
        uVar7 = 0;
        FUN_00092ea0(puVar5,4,1,0);
        if ((uVar10 & 4) != 0) {
          puVar5[0x14] = iVar11;
          puVar5[0x15] = 3;
          FUN_000931e0(puVar5);
        }
        iVar11 = iVar4 + 2;
      }
      if (uVar2 != 0) {
        puVar5[5] = iVar11;
        FUN_00092ea0(puVar5,3,2,1);
        puVar5[6] = iVar11 + 1;
        puVar5[0x20] = 0;
        uVar6 = 3;
        uVar7 = 1;
        iVar11 = iVar11 + 2;
        FUN_00092ea0(puVar5,4,3,1);
      }
      uVar8 = (uint)(uVar2 != 0);
      if (uVar10 >> 4 != 0) {
        loopIndex = 0;
        iVar4 = param_1;
        do {
          iVar3 = *(int *)(iVar4 + 0x1824);
          puVar5[iVar3 + 0xb] = iVar11;
          iVar11 = iVar11 + 1;
          if (uVar8 == uVar9) {
            uVar8 = uVar8 + 1;
          }
          puVar5[iVar3 + 0x21] = uVar8;
          loopIndex = loopIndex + 1;
          uVar8 = uVar8 + 1;
          iVar4 = iVar4 + 4;
          FUN_00093000(puVar5,iVar3,uVar6,uVar7,in_r7,in_r8,in_r9);
        } while (uVar10 >> 4 != loopIndex);
      }
      FUN_0009a910(puVar5);
      iVar4 = FUN_0009c800(param_1,local_70,puVar5,iVar11,local_74,0,0,1);
      *(undefined4 *)(iVar4 + 0x34) = 0;
      *(int *)(iVar4 + 0x38) = *(int *)(*(int *)(iVar4 + 0x54) + 0x3cc) + -1;
      iVar11 = *(int *)(param_1 + 0x14c);
    }
    else {
      iVar11 = *(int *)(param_1 + 0x14c);
    }
  }
  if (iVar4 != iVar11) {
    *(int *)(param_1 + 0x14c) = iVar4;
    *(uint *)(param_1 + 0x8c) = *(uint *)(param_1 + 0x8c) | 0x40000;
  }
  (**(code **)((int)((unsigned char *)0x00001294) + param_1))
            (param_1,*(int *)(iVar4 + 0x54) + 0x750,*(undefined4 *)(iVar4 + 0x3c));
  return;
}

/* FUN_000659d0 @ 0x659d0 (612 bytes) */
void FUN_000659d0(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint loopIndex;
  int iVar6;
  undefined4 uVar7;
  undefined4 *puVar8;
  int iVar9;
  double in_stack_ffffffa8;
  double in_stack_ffffffb0;
  double in_stack_ffffffb8;
  double in_stack_ffffffc0;
  double in_stack_ffffffc8;
  
  iVar9 = 8;
  iVar2 = *(int *)(param_2 + 0x54);
  iVar6 = iVar2 + 0x750;
  iVar4 = *(int *)(*(int *)(param_1 + 4) + 0x10);
  puVar8 = (undefined4 *)(iVar2 + 0x768);
  iVar3 = iVar6;
  do {
    *(undefined4 *)(((unsigned char *)0x00001018) + iVar3) = 0;
    iVar3 = iVar3 + 4;
    iVar9 = iVar9 + -1;
  } while (iVar9 != 0);
  *(undefined4 *)(iVar2 + 0x1990) = 0xffff;
  if (*(char *)(param_2 + 0x58) == '\0') {
    iVar3 = 0;
    if (*(int *)(param_2 + 0x48) != 0) {
      uVar7 = *(undefined4 *)(param_2 + 0x4c);
      ((void (*)())programFillStateConstants)(param_1,param_2,param_3,param_4,param_5,param_6,iVar4,param_8,fparam_1,fparam_2,
                   fparam_3,fparam_4,fparam_5,fparam_6,fparam_7,fparam_8,in_stack_ffffffa8,
                   in_stack_ffffffb0,in_stack_ffffffb8,in_stack_ffffffc0,in_stack_ffffffc8);
      _memcpy(puVar8,uVar7,*(int *)(param_2 + 0x48) << 4);
      iVar3 = *(int *)(param_2 + 0x48);
      if (0 < iVar3) {
        loopIndex = 0;
        do {
          iVar3 = ((int)loopIndex >> 5) + (uint)((int)loopIndex < 0 && (loopIndex & 0x1f) != 0);
          iVar4 = iVar3 * 4 + iVar6;
          uVar1 = loopIndex + iVar3 * -0x20;
          loopIndex = loopIndex + 1;
          *(uint *)(((unsigned char *)0x00001018) + iVar4) = 1 << (uVar1 & 0x3f) | *(uint *)(((unsigned char *)0x00001018) + iVar4);
          iVar3 = *(int *)(param_2 + 0x48);
        } while ((int)loopIndex < iVar3);
      }
    }
    *(int *)(iVar2 + 0x1788) = iVar3;
  }
  else {
    if ((*(uint *)(((unsigned char *)0x000013c0) + param_1) & 4) == 0) {
      *puVar8 = *(undefined4 *)(iVar4 + 0x2460);
      *(undefined4 *)(iVar2 + 0x76c) = *(undefined4 *)(iVar4 + 0x2470);
      *(undefined4 *)(iVar2 + 0x770) = *(undefined4 *)(iVar4 + 0x2480);
      *(undefined4 *)(iVar2 + 0x774) = *(undefined4 *)(iVar4 + 0x2490);
      *(undefined4 *)(iVar2 + 0x778) = *(undefined4 *)(iVar4 + 0x2464);
      *(undefined4 *)(iVar2 + 0x77c) = *(undefined4 *)(iVar4 + 0x2474);
      *(undefined4 *)(iVar2 + 0x780) = *(undefined4 *)(iVar4 + 0x2484);
      *(undefined4 *)(iVar2 + 0x784) = *(undefined4 *)(iVar4 + 0x2494);
      *(undefined4 *)(iVar2 + 0x788) = *(undefined4 *)(iVar4 + 0x2468);
      *(undefined4 *)(iVar2 + 0x78c) = *(undefined4 *)(iVar4 + 0x2478);
      *(undefined4 *)(iVar2 + 0x790) = *(undefined4 *)(iVar4 + 0x2488);
      *(undefined4 *)(iVar2 + 0x794) = *(undefined4 *)(iVar4 + 0x2498);
      *(undefined4 *)(iVar2 + 0x798) = *(undefined4 *)(iVar4 + 0x246c);
      *(undefined4 *)(iVar2 + 0x79c) = *(undefined4 *)(iVar4 + 0x247c);
      *(undefined4 *)(iVar2 + 0x7a0) = *(undefined4 *)(iVar4 + 0x248c);
      *(undefined4 *)(iVar2 + 0x7a4) = *(undefined4 *)(iVar4 + 0x249c);
    }
    else {
      *puVar8 = *(undefined4 *)(iVar4 + 0x2460);
      *(undefined4 *)(iVar2 + 0x76c) = *(undefined4 *)(iVar4 + 0x2464);
      *(undefined4 *)(iVar2 + 0x770) = *(undefined4 *)(iVar4 + 0x2468);
      *(undefined4 *)(iVar2 + 0x774) = *(undefined4 *)(iVar4 + 0x246c);
      *(undefined4 *)(iVar2 + 0x778) = *(undefined4 *)(iVar4 + 0x2470);
      *(undefined4 *)(iVar2 + 0x77c) = *(undefined4 *)(iVar4 + 0x2474);
      *(undefined4 *)(iVar2 + 0x780) = *(undefined4 *)(iVar4 + 0x2478);
      *(undefined4 *)(iVar2 + 0x784) = *(undefined4 *)(iVar4 + 0x247c);
      *(undefined4 *)(iVar2 + 0x788) = *(undefined4 *)(iVar4 + 0x2480);
      *(undefined4 *)(iVar2 + 0x78c) = *(undefined4 *)(iVar4 + 0x2484);
      *(undefined4 *)(iVar2 + 0x790) = *(undefined4 *)(iVar4 + 0x2488);
      *(undefined4 *)(iVar2 + 0x794) = *(undefined4 *)(iVar4 + 0x248c);
      *(undefined4 *)(iVar2 + 0x798) = *(undefined4 *)(iVar4 + 0x2490);
      *(undefined4 *)(iVar2 + 0x79c) = *(undefined4 *)(iVar4 + 0x2494);
      *(undefined4 *)(iVar2 + 0x7a0) = *(undefined4 *)(iVar4 + 0x2498);
      *(undefined4 *)(iVar2 + 0x7a4) = *(undefined4 *)(iVar4 + 0x249c);
    }
    *(undefined4 *)(iVar2 + 0x1768) = 0xf;
    *(undefined4 *)(iVar2 + 0x1788) = 4;
  }
  if ((*(char *)(iVar2 + 0x751) != '\0') && (iVar6 == *(int *)(((unsigned char *)0x0000148c) + param_1))) {
                    
                    
    (**(code **)((int)((unsigned char *)0x000012a0) + param_1))(param_1,iVar6);
    return;
  }
  return;
}

/* FUN_00065c40 @ 0x65c40 (52 bytes) */
int FUN_00065c40(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  if (((*(uint *)(param_1 + 0x44) & 0x100000) != 0) && (*(char *)(param_1 + 0x124) == '\0')) {
    return;
  }
                    
                    
  (**(code **)((int)((unsigned char *)0x00001298) + param_1))(param_1,*(int *)(param_2 + 0x54) + 0x750);
  return;
}

/* noop_65c80 @ 0x65c80 (4 bytes) */
int noop_65c80()
{
  return;
}

/* arbEmitIlHeader @ 0x65c90 (328 bytes) */
int arbEmitIlHeader(param_1, param_2)
  int param_1;
  int param_2;
{
  undefined4 uVar1;
  uint uVar2;
  uint *puVar3;
  
  puVar3 = (uint *)(param_2 + 0x754);
  if (*(uint *)(param_2 + 0x758) <= *(uint *)(param_2 + 0x754)) {
    uVar1 = (**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 0x758) * 4 + 0x200);
    if (*(int *)(param_2 + 0x75c) != 0) {
      _memcpy(uVar1,*(int *)(param_2 + 0x75c),*(int *)(param_2 + 0x754) << 2);
      (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0x75c));
    }
    *(undefined4 *)(param_2 + 0x75c) = uVar1;
    *(int *)(param_2 + 0x758) = *(int *)(param_2 + 0x758) + 0x80;
  }
  *(undefined4 *)(*puVar3 * 4 + *(int *)(param_2 + 0x75c)) = 1;
  uVar2 = *puVar3 + 1;
  *puVar3 = uVar2;
  if (*(uint *)(param_2 + 0x758) <= uVar2) {
    uVar1 = (**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 0x758) * 4 + 0x200);
    if (*(int *)(param_2 + 0x75c) != 0) {
      _memcpy(uVar1,*(int *)(param_2 + 0x75c),*puVar3 << 2);
      (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0x75c));
    }
    *(undefined4 *)(param_2 + 0x75c) = uVar1;
    uVar2 = *puVar3;
    *(int *)(param_2 + 0x758) = *(int *)(param_2 + 0x758) + 0x80;
  }
  *(undefined4 *)(uVar2 * 4 + *(int *)(param_2 + 0x75c)) = 0x200;
  *puVar3 = *puVar3 + 1;
  return;
}

/* arbEmitIlEnd @ 0x65de0 (192 bytes) */
int arbEmitIlEnd(param_1, param_2)
  int param_1;
  int param_2;
{
  undefined4 uVar1;
  int *piVar2;
  
  piVar2 = (int *)(param_2 + 0x754);
  if (*(uint *)(param_2 + 0x758) <= *(uint *)(param_2 + 0x754)) {
    uVar1 = (**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 0x758) * 4 + 0x200);
    if (*(int *)(param_2 + 0x75c) != 0) {
      _memcpy(uVar1,*(int *)(param_2 + 0x75c),*(int *)(param_2 + 0x754) << 2);
      (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0x75c));
    }
    *(undefined4 *)(param_2 + 0x75c) = uVar1;
    *(int *)(param_2 + 0x758) = *(int *)(param_2 + 0x758) + 0x80;
  }
  *(undefined4 *)(*piVar2 * 4 + *(int *)(param_2 + 0x75c)) = 0x28;
  *piVar2 = *piVar2 + 1;
  return;
}

/* arbEmitIlDp4 @ 0x65ea0 (1912 bytes) */
int arbEmitIlDp4(ctx, dstFile, dstIndex, dstMask, src0File, src0Index, src0Select, src0Negate, src1File, src1Index, src1Select, src1Negate)
  int ctx;
  uint dstFile;
  uint dstIndex;
  int *dstMask;
  uint src0File;
  uint src0Index;
  uint *src0Select;
  uint *src0Negate;
  uint src1File;
  uint src1Index;
  uint *src1Select;
  uint *src1Negate;
{
  uint src1Select3;
  uint src1Negate2;
  uint src1Negate3;
  uint src1Select1;
  uint src1Negate1;
  uint src1Header;
  int dstMask2;
  uint tokenIndex;
  undefined4 newStorage;
  uint src0Negate3;
  uint src0Negate2;
  uint src0Negate1;
  int dstMask1;
  uint src0Select3;
  uint src0SelectX;
  uint src1SelectX;
  uint src0Header;
  uint dstHeader;
  uint dstMaskWord;
  uint src1SwizzleWord;
  int iVar16;
  uint src0SwizzleWord;
  uint *tokenCount;
  
  dstHeader = (dstFile & 0x3f) << 0x10 | dstIndex & 0xffff;
  tokenCount = (uint *)(ctx + ARB_tokenCount);
  src1SwizzleWord = 0;
  src0SwizzleWord = 0;
  dstMaskWord = 0;
  if ((dstFile == 0x12) || (dstFile == 0x13)) {
    dstHeader = dstHeader | 0x400000;
    dstMaskWord = 0x55;
  }
  if (*dstMask == 0) {
    iVar16 = dstMask[3];
    dstMask1 = dstMask[1];
    dstMask2 = dstMask[2];
LAB_00065f90:
    dstHeader = dstHeader | 0x400000;
    dstMaskWord = (uint)(iVar16 != 0) * 0x40 |
             (uint)(dstMask2 != 0) * 0x10 | (uint)(dstMask1 != 0) * 4 | (uint)(*dstMask != 0);
  }
  else {
    dstMask1 = dstMask[1];
    if (dstMask1 == 0) {
      iVar16 = dstMask[3];
      dstMask2 = dstMask[2];
      goto LAB_00065f90;
    }
    dstMask2 = dstMask[2];
    if (dstMask2 == 0) {
      iVar16 = dstMask[3];
      goto LAB_00065f90;
    }
    if (dstMask[3] == 0) {
      iVar16 = 0;
      goto LAB_00065f90;
    }
  }
  src0Header = (src0File & 0x3f) << 0x10 | src0Index & 0xffff;
  if (*src0Negate == 0) {
    src0Negate1 = src0Negate[1];
    if (src0Negate1 != 0) {
      src0Negate3 = src0Negate[3];
      src0Select3 = src0Select[3];
      src0Negate2 = src0Negate[2];
      src0SelectX = *src0Select;
      tokenIndex = src0Select[1];
      src1Header = src0Select[2];
      goto LAB_000660e0;
    }
    src0Negate2 = src0Negate[2];
    if (src0Negate2 != 0) {
      src0Negate3 = src0Negate[3];
      src0Select3 = src0Select[3];
      src0SelectX = *src0Select;
      tokenIndex = src0Select[1];
      src1Header = src0Select[2];
      goto LAB_000660e0;
    }
    src0Negate3 = src0Negate[3];
    if (src0Negate3 != 0) {
      src0Select3 = src0Select[3];
      src0SelectX = *src0Select;
      tokenIndex = src0Select[1];
      src1Header = src0Select[2];
      goto LAB_000660e0;
    }
    src0SelectX = *src0Select;
    if (src0SelectX != 0) {
      src0Select3 = src0Select[3];
      tokenIndex = src0Select[1];
      src1Header = src0Select[2];
      goto LAB_000660e0;
    }
    tokenIndex = src0Select[1];
    if (tokenIndex != 1) {
      src0Select3 = src0Select[3];
      src1Header = src0Select[2];
      goto LAB_000660e0;
    }
    src1Header = src0Select[2];
    if (src1Header != 2) {
      src0Select3 = src0Select[3];
      goto LAB_000660e0;
    }
    src0Select3 = src0Select[3];
    if (src0Select3 != 3) goto LAB_000660e0;
  }
  else {
    src0Negate3 = src0Negate[3];
    src0Select3 = src0Select[3];
    src0Negate1 = src0Negate[1];
    src0Negate2 = src0Negate[2];
    src0SelectX = *src0Select;
    tokenIndex = src0Select[1];
    src1Header = src0Select[2];
LAB_000660e0:
    src0Header = src0Header | 0x400000;
    src0SwizzleWord = (src0Negate3 & 1) << 0xf |
             (src0Select3 & 7) << 0xc |
             (src0Negate2 & 1) << 0xb |
             (src1Header & 7) << 8 |
             (src0Negate1 & 1) << 7 | (tokenIndex & 7) << 4 | (*src0Negate & 1) << 3 | src0SelectX & 7;
  }
  src1Header = (src1File & 0x3f) << 0x10 | src1Index & 0xffff;
  if (*src1Negate == 0) {
    src1Negate1 = src1Negate[1];
    if (src1Negate1 == 0) {
      src1Negate2 = src1Negate[2];
      if (src1Negate2 == 0) {
        src1Negate3 = src1Negate[3];
        if (src1Negate3 == 0) {
          src1SelectX = *src1Select;
          if (src1SelectX == 0) {
            src1Select1 = src1Select[1];
            if (src1Select1 == 1) {
              tokenIndex = src1Select[2];
              if (tokenIndex == 2) {
                src1Select3 = src1Select[3];
                if (src1Select3 == 3) goto LAB_00066234;
              }
              else {
                src1Select3 = src1Select[3];
              }
            }
            else {
              src1Select3 = src1Select[3];
              tokenIndex = src1Select[2];
            }
          }
          else {
            src1Select3 = src1Select[3];
            src1Select1 = src1Select[1];
            tokenIndex = src1Select[2];
          }
        }
        else {
          src1Select3 = src1Select[3];
          src1SelectX = *src1Select;
          src1Select1 = src1Select[1];
          tokenIndex = src1Select[2];
        }
      }
      else {
        src1Negate3 = src1Negate[3];
        src1Select3 = src1Select[3];
        src1SelectX = *src1Select;
        src1Select1 = src1Select[1];
        tokenIndex = src1Select[2];
      }
    }
    else {
      src1Negate3 = src1Negate[3];
      src1Select3 = src1Select[3];
      src1Negate2 = src1Negate[2];
      src1SelectX = *src1Select;
      src1Select1 = src1Select[1];
      tokenIndex = src1Select[2];
    }
  }
  else {
    src1Negate3 = src1Negate[3];
    src1Select3 = src1Select[3];
    src1Negate1 = src1Negate[1];
    src1Negate2 = src1Negate[2];
    src1SelectX = *src1Select;
    src1Select1 = src1Select[1];
    tokenIndex = src1Select[2];
  }
  src1Header = src1Header | 0x400000;
  src1SwizzleWord = (src1Negate3 & 1) << 0xf |
           (src1Select3 & 7) << 0xc |
           (src1Negate2 & 1) << 0xb |
           (tokenIndex & 7) << 8 |
           (src1Negate1 & 1) << 7 | (src1Select1 & 7) << 4 | (*src1Negate & 1) << 3 | src1SelectX & 7;
LAB_00066234:
  tokenIndex = *tokenCount;
  iVar16 = *(int *)(ctx + ARB_allocator);
  if (*(uint *)(ctx + ARB_tokenCapacity) <= tokenIndex) {
    newStorage = (**(code **)(iVar16 + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
    if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
      _memcpy(newStorage,*(int *)(ctx + ARB_tokenBuffer),*tokenCount << 2);
      (**(code **)(iVar16 + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
    }
    *(undefined4 *)(ctx + ARB_tokenBuffer) = newStorage;
    tokenIndex = *tokenCount;
    *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
  }
  *(undefined4 *)(tokenIndex * 4 + *(int *)(ctx + ARB_tokenBuffer)) = 0x23;
  tokenIndex = *tokenCount + 1;
  *tokenCount = tokenIndex;
  iVar16 = *(int *)(ctx + ARB_allocator);
  if (*(uint *)(ctx + ARB_tokenCapacity) <= tokenIndex) {
    newStorage = (**(code **)(iVar16 + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
    if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
      _memcpy(newStorage,*(int *)(ctx + ARB_tokenBuffer),*tokenCount << 2);
      (**(code **)(iVar16 + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
    }
    *(undefined4 *)(ctx + ARB_tokenBuffer) = newStorage;
    tokenIndex = *tokenCount;
    *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
  }
  *(uint *)(tokenIndex * 4 + *(int *)(ctx + ARB_tokenBuffer)) = dstHeader;
  tokenIndex = *tokenCount + 1;
  *tokenCount = tokenIndex;
  if ((dstHeader & 0x400000) != 0) {
    iVar16 = *(int *)(ctx + ARB_allocator);
    if (*(uint *)(ctx + ARB_tokenCapacity) <= tokenIndex) {
      newStorage = (**(code **)(iVar16 + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
      if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
        _memcpy(newStorage,*(int *)(ctx + ARB_tokenBuffer),*tokenCount << 2);
        (**(code **)(iVar16 + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
      }
      *(undefined4 *)(ctx + ARB_tokenBuffer) = newStorage;
      tokenIndex = *tokenCount;
      *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
    }
    *(uint *)(tokenIndex * 4 + *(int *)(ctx + ARB_tokenBuffer)) = dstMaskWord;
    tokenIndex = *tokenCount + 1;
    *tokenCount = tokenIndex;
  }
  iVar16 = *(int *)(ctx + ARB_allocator);
  if (*(uint *)(ctx + ARB_tokenCapacity) <= tokenIndex) {
    newStorage = (**(code **)(iVar16 + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
    if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
      _memcpy(newStorage,*(int *)(ctx + ARB_tokenBuffer),*tokenCount << 2);
      (**(code **)(iVar16 + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
    }
    *(undefined4 *)(ctx + ARB_tokenBuffer) = newStorage;
    tokenIndex = *tokenCount;
    *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
  }
  *(uint *)(tokenIndex * 4 + *(int *)(ctx + ARB_tokenBuffer)) = src0Header;
  dstHeader = *tokenCount + 1;
  *tokenCount = dstHeader;
  if ((src0Header & 0x400000) != 0) {
    iVar16 = *(int *)(ctx + ARB_allocator);
    if (*(uint *)(ctx + ARB_tokenCapacity) <= dstHeader) {
      newStorage = (**(code **)(iVar16 + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
      if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
        _memcpy(newStorage,*(int *)(ctx + ARB_tokenBuffer),*tokenCount << 2);
        (**(code **)(iVar16 + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
      }
      *(undefined4 *)(ctx + ARB_tokenBuffer) = newStorage;
      dstHeader = *tokenCount;
      *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
    }
    *(uint *)(dstHeader * 4 + *(int *)(ctx + ARB_tokenBuffer)) = src0SwizzleWord;
    dstHeader = *tokenCount + 1;
    *tokenCount = dstHeader;
  }
  iVar16 = *(int *)(ctx + ARB_allocator);
  if (*(uint *)(ctx + ARB_tokenCapacity) <= dstHeader) {
    newStorage = (**(code **)(iVar16 + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
    if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
      _memcpy(newStorage,*(int *)(ctx + ARB_tokenBuffer),*tokenCount << 2);
      (**(code **)(iVar16 + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
    }
    *(undefined4 *)(ctx + ARB_tokenBuffer) = newStorage;
    dstHeader = *tokenCount;
    *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
  }
  *(uint *)(dstHeader * 4 + *(int *)(ctx + ARB_tokenBuffer)) = src1Header;
  dstHeader = *tokenCount + 1;
  *tokenCount = dstHeader;
  if ((src1Header & 0x400000) != 0) {
    iVar16 = *(int *)(ctx + ARB_allocator);
    if (*(uint *)(ctx + ARB_tokenCapacity) <= dstHeader) {
      newStorage = (**(code **)(iVar16 + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
      if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
        _memcpy(newStorage,*(int *)(ctx + ARB_tokenBuffer),*tokenCount << 2);
        (**(code **)(iVar16 + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
      }
      *(undefined4 *)(ctx + ARB_tokenBuffer) = newStorage;
      dstHeader = *tokenCount;
      *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
    }
    *(uint *)(dstHeader * 4 + *(int *)(ctx + ARB_tokenBuffer)) = src1SwizzleWord;
    *tokenCount = *tokenCount + 1;
  }
  return;
}

/* arbEmitIlMov @ 0x66640 (1308 bytes) */
int arbEmitIlMov(ctx, dstFile, dstIndex, dstMask, srcFile, srcIndex, srcSelect, srcNegate)
  int ctx;
  uint dstFile;
  uint dstIndex;
  int *dstMask;
  uint srcFile;
  uint srcIndex;
  uint *srcSelect;
  uint *srcNegate;
{
  uint tokenIndex;
  int dstMask2;
  uint srcSelect1;
  undefined4 newStorage;
  uint srcNegate3;
  uint srcNegate2;
  uint srcNegate1;
  int dstMask1;
  uint srcSelect3;
  uint srcSelectX;
  uint srcHeader;
  uint dstHeader;
  uint dstMaskWord;
  int iVar14;
  uint srcSwizzleWord;
  uint *tokenCount;
  
  dstHeader = (dstFile & 0x3f) << 0x10 | dstIndex & 0xffff;
  tokenCount = (uint *)(ctx + ARB_tokenCount);
  srcSwizzleWord = 0;
  dstMaskWord = 0;
  if ((dstFile == 0x12) || (dstFile == 0x13)) {
    dstHeader = dstHeader | 0x400000;
    dstMaskWord = 0x55;
  }
  if (*dstMask == 0) {
    iVar14 = dstMask[3];
    dstMask1 = dstMask[1];
    dstMask2 = dstMask[2];
LAB_00066720:
    dstHeader = dstHeader | 0x400000;
    dstMaskWord = (uint)(iVar14 != 0) * 0x40 |
             (uint)(dstMask2 != 0) * 0x10 | (uint)(dstMask1 != 0) * 4 | (uint)(*dstMask != 0);
  }
  else {
    dstMask1 = dstMask[1];
    if (dstMask1 == 0) {
      iVar14 = dstMask[3];
      dstMask2 = dstMask[2];
      goto LAB_00066720;
    }
    dstMask2 = dstMask[2];
    if (dstMask2 == 0) {
      iVar14 = dstMask[3];
      goto LAB_00066720;
    }
    if (dstMask[3] == 0) {
      iVar14 = 0;
      goto LAB_00066720;
    }
  }
  srcHeader = (srcFile & 0x3f) << 0x10 | srcIndex & 0xffff;
  if (*srcNegate == 0) {
    srcNegate1 = srcNegate[1];
    if (srcNegate1 == 0) {
      srcNegate2 = srcNegate[2];
      if (srcNegate2 == 0) {
        srcNegate3 = srcNegate[3];
        if (srcNegate3 == 0) {
          srcSelectX = *srcSelect;
          if (srcSelectX == 0) {
            srcSelect1 = srcSelect[1];
            if (srcSelect1 == 1) {
              tokenIndex = srcSelect[2];
              if (tokenIndex == 2) {
                srcSelect3 = srcSelect[3];
                if (srcSelect3 == 3) goto LAB_00066894;
              }
              else {
                srcSelect3 = srcSelect[3];
              }
            }
            else {
              srcSelect3 = srcSelect[3];
              tokenIndex = srcSelect[2];
            }
          }
          else {
            srcSelect3 = srcSelect[3];
            srcSelect1 = srcSelect[1];
            tokenIndex = srcSelect[2];
          }
        }
        else {
          srcSelect3 = srcSelect[3];
          srcSelectX = *srcSelect;
          srcSelect1 = srcSelect[1];
          tokenIndex = srcSelect[2];
        }
      }
      else {
        srcNegate3 = srcNegate[3];
        srcSelect3 = srcSelect[3];
        srcSelectX = *srcSelect;
        srcSelect1 = srcSelect[1];
        tokenIndex = srcSelect[2];
      }
    }
    else {
      srcNegate3 = srcNegate[3];
      srcSelect3 = srcSelect[3];
      srcNegate2 = srcNegate[2];
      srcSelectX = *srcSelect;
      srcSelect1 = srcSelect[1];
      tokenIndex = srcSelect[2];
    }
  }
  else {
    srcNegate3 = srcNegate[3];
    srcSelect3 = srcSelect[3];
    srcNegate1 = srcNegate[1];
    srcNegate2 = srcNegate[2];
    srcSelectX = *srcSelect;
    srcSelect1 = srcSelect[1];
    tokenIndex = srcSelect[2];
  }
  srcHeader = srcHeader | 0x400000;
  srcSwizzleWord = (srcNegate3 & 1) << 0xf |
           (srcSelect3 & 7) << 0xc |
           (srcNegate2 & 1) << 0xb |
           (tokenIndex & 7) << 8 | (srcNegate1 & 1) << 7 | (srcSelect1 & 7) << 4 | (*srcNegate & 1) << 3 | srcSelectX & 7
  ;
LAB_00066894:
  tokenIndex = *tokenCount;
  iVar14 = *(int *)(ctx + ARB_allocator);
  if (*(uint *)(ctx + ARB_tokenCapacity) <= tokenIndex) {
    newStorage = (**(code **)(iVar14 + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
    if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
      _memcpy(newStorage,*(int *)(ctx + ARB_tokenBuffer),*tokenCount << 2);
      (**(code **)(iVar14 + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
    }
    *(undefined4 *)(ctx + ARB_tokenBuffer) = newStorage;
    tokenIndex = *tokenCount;
    *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
  }
  *(undefined4 *)(tokenIndex * 4 + *(int *)(ctx + ARB_tokenBuffer)) = 0x47;
  tokenIndex = *tokenCount + 1;
  *tokenCount = tokenIndex;
  iVar14 = *(int *)(ctx + ARB_allocator);
  if (*(uint *)(ctx + ARB_tokenCapacity) <= tokenIndex) {
    newStorage = (**(code **)(iVar14 + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
    if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
      _memcpy(newStorage,*(int *)(ctx + ARB_tokenBuffer),*tokenCount << 2);
      (**(code **)(iVar14 + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
    }
    *(undefined4 *)(ctx + ARB_tokenBuffer) = newStorage;
    tokenIndex = *tokenCount;
    *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
  }
  *(uint *)(tokenIndex * 4 + *(int *)(ctx + ARB_tokenBuffer)) = dstHeader;
  tokenIndex = *tokenCount + 1;
  *tokenCount = tokenIndex;
  if ((dstHeader & 0x400000) != 0) {
    iVar14 = *(int *)(ctx + ARB_allocator);
    if (*(uint *)(ctx + ARB_tokenCapacity) <= tokenIndex) {
      newStorage = (**(code **)(iVar14 + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
      if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
        _memcpy(newStorage,*(int *)(ctx + ARB_tokenBuffer),*tokenCount << 2);
        (**(code **)(iVar14 + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
      }
      *(undefined4 *)(ctx + ARB_tokenBuffer) = newStorage;
      tokenIndex = *tokenCount;
      *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
    }
    *(uint *)(tokenIndex * 4 + *(int *)(ctx + ARB_tokenBuffer)) = dstMaskWord;
    tokenIndex = *tokenCount + 1;
    *tokenCount = tokenIndex;
  }
  iVar14 = *(int *)(ctx + ARB_allocator);
  if (*(uint *)(ctx + ARB_tokenCapacity) <= tokenIndex) {
    newStorage = (**(code **)(iVar14 + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
    if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
      _memcpy(newStorage,*(int *)(ctx + ARB_tokenBuffer),*tokenCount << 2);
      (**(code **)(iVar14 + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
    }
    *(undefined4 *)(ctx + ARB_tokenBuffer) = newStorage;
    tokenIndex = *tokenCount;
    *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
  }
  *(uint *)(tokenIndex * 4 + *(int *)(ctx + ARB_tokenBuffer)) = srcHeader;
  dstHeader = *tokenCount + 1;
  *tokenCount = dstHeader;
  if ((srcHeader & 0x400000) != 0) {
    iVar14 = *(int *)(ctx + ARB_allocator);
    if (*(uint *)(ctx + ARB_tokenCapacity) <= dstHeader) {
      newStorage = (**(code **)(iVar14 + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
      if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
        _memcpy(newStorage,*(int *)(ctx + ARB_tokenBuffer),*tokenCount << 2);
        (**(code **)(iVar14 + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
      }
      *(undefined4 *)(ctx + ARB_tokenBuffer) = newStorage;
      dstHeader = *tokenCount;
      *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
    }
    *(uint *)(dstHeader * 4 + *(int *)(ctx + ARB_tokenBuffer)) = srcSwizzleWord;
    *tokenCount = *tokenCount + 1;
  }
  return;
}

/* arbEmitIlMul @ 0x66b80 (1912 bytes) */
int arbEmitIlMul(ctx, dstFile, dstIndex, dstMask, src0File, src0Index, src0Select, src0Negate, src1File, src1Index, src1Select, src1Negate)
  int ctx;
  uint dstFile;
  uint dstIndex;
  int *dstMask;
  uint src0File;
  uint src0Index;
  uint *src0Select;
  uint *src0Negate;
  uint src1File;
  uint src1Index;
  uint *src1Select;
  uint *src1Negate;
{
  uint src1Select3;
  uint src1Negate2;
  uint src1Negate3;
  uint src1Select1;
  uint src1Negate1;
  uint src1Header;
  int dstMask2;
  uint tokenIndex;
  undefined4 newStorage;
  uint src0Negate3;
  uint src0Negate2;
  uint src0Negate1;
  int dstMask1;
  uint src0Select3;
  uint src0SelectX;
  uint src1SelectX;
  uint src0Header;
  uint dstHeader;
  uint dstMaskWord;
  uint src1SwizzleWord;
  int iVar16;
  uint src0SwizzleWord;
  uint *tokenCount;
  
  dstHeader = (dstFile & 0x3f) << 0x10 | dstIndex & 0xffff;
  tokenCount = (uint *)(ctx + ARB_tokenCount);
  src1SwizzleWord = 0;
  src0SwizzleWord = 0;
  dstMaskWord = 0;
  if ((dstFile == 0x12) || (dstFile == 0x13)) {
    dstHeader = dstHeader | 0x400000;
    dstMaskWord = 0x55;
  }
  if (*dstMask == 0) {
    iVar16 = dstMask[3];
    dstMask1 = dstMask[1];
    dstMask2 = dstMask[2];
LAB_00066c70:
    dstHeader = dstHeader | 0x400000;
    dstMaskWord = (uint)(iVar16 != 0) * 0x40 |
             (uint)(dstMask2 != 0) * 0x10 | (uint)(dstMask1 != 0) * 4 | (uint)(*dstMask != 0);
  }
  else {
    dstMask1 = dstMask[1];
    if (dstMask1 == 0) {
      iVar16 = dstMask[3];
      dstMask2 = dstMask[2];
      goto LAB_00066c70;
    }
    dstMask2 = dstMask[2];
    if (dstMask2 == 0) {
      iVar16 = dstMask[3];
      goto LAB_00066c70;
    }
    if (dstMask[3] == 0) {
      iVar16 = 0;
      goto LAB_00066c70;
    }
  }
  src0Header = (src0File & 0x3f) << 0x10 | src0Index & 0xffff;
  if (*src0Negate == 0) {
    src0Negate1 = src0Negate[1];
    if (src0Negate1 != 0) {
      src0Negate3 = src0Negate[3];
      src0Select3 = src0Select[3];
      src0Negate2 = src0Negate[2];
      src0SelectX = *src0Select;
      tokenIndex = src0Select[1];
      src1Header = src0Select[2];
      goto LAB_00066dc0;
    }
    src0Negate2 = src0Negate[2];
    if (src0Negate2 != 0) {
      src0Negate3 = src0Negate[3];
      src0Select3 = src0Select[3];
      src0SelectX = *src0Select;
      tokenIndex = src0Select[1];
      src1Header = src0Select[2];
      goto LAB_00066dc0;
    }
    src0Negate3 = src0Negate[3];
    if (src0Negate3 != 0) {
      src0Select3 = src0Select[3];
      src0SelectX = *src0Select;
      tokenIndex = src0Select[1];
      src1Header = src0Select[2];
      goto LAB_00066dc0;
    }
    src0SelectX = *src0Select;
    if (src0SelectX != 0) {
      src0Select3 = src0Select[3];
      tokenIndex = src0Select[1];
      src1Header = src0Select[2];
      goto LAB_00066dc0;
    }
    tokenIndex = src0Select[1];
    if (tokenIndex != 1) {
      src0Select3 = src0Select[3];
      src1Header = src0Select[2];
      goto LAB_00066dc0;
    }
    src1Header = src0Select[2];
    if (src1Header != 2) {
      src0Select3 = src0Select[3];
      goto LAB_00066dc0;
    }
    src0Select3 = src0Select[3];
    if (src0Select3 != 3) goto LAB_00066dc0;
  }
  else {
    src0Negate3 = src0Negate[3];
    src0Select3 = src0Select[3];
    src0Negate1 = src0Negate[1];
    src0Negate2 = src0Negate[2];
    src0SelectX = *src0Select;
    tokenIndex = src0Select[1];
    src1Header = src0Select[2];
LAB_00066dc0:
    src0Header = src0Header | 0x400000;
    src0SwizzleWord = (src0Negate3 & 1) << 0xf |
             (src0Select3 & 7) << 0xc |
             (src0Negate2 & 1) << 0xb |
             (src1Header & 7) << 8 |
             (src0Negate1 & 1) << 7 | (tokenIndex & 7) << 4 | (*src0Negate & 1) << 3 | src0SelectX & 7;
  }
  src1Header = (src1File & 0x3f) << 0x10 | src1Index & 0xffff;
  if (*src1Negate == 0) {
    src1Negate1 = src1Negate[1];
    if (src1Negate1 == 0) {
      src1Negate2 = src1Negate[2];
      if (src1Negate2 == 0) {
        src1Negate3 = src1Negate[3];
        if (src1Negate3 == 0) {
          src1SelectX = *src1Select;
          if (src1SelectX == 0) {
            src1Select1 = src1Select[1];
            if (src1Select1 == 1) {
              tokenIndex = src1Select[2];
              if (tokenIndex == 2) {
                src1Select3 = src1Select[3];
                if (src1Select3 == 3) goto LAB_00066f14;
              }
              else {
                src1Select3 = src1Select[3];
              }
            }
            else {
              src1Select3 = src1Select[3];
              tokenIndex = src1Select[2];
            }
          }
          else {
            src1Select3 = src1Select[3];
            src1Select1 = src1Select[1];
            tokenIndex = src1Select[2];
          }
        }
        else {
          src1Select3 = src1Select[3];
          src1SelectX = *src1Select;
          src1Select1 = src1Select[1];
          tokenIndex = src1Select[2];
        }
      }
      else {
        src1Negate3 = src1Negate[3];
        src1Select3 = src1Select[3];
        src1SelectX = *src1Select;
        src1Select1 = src1Select[1];
        tokenIndex = src1Select[2];
      }
    }
    else {
      src1Negate3 = src1Negate[3];
      src1Select3 = src1Select[3];
      src1Negate2 = src1Negate[2];
      src1SelectX = *src1Select;
      src1Select1 = src1Select[1];
      tokenIndex = src1Select[2];
    }
  }
  else {
    src1Negate3 = src1Negate[3];
    src1Select3 = src1Select[3];
    src1Negate1 = src1Negate[1];
    src1Negate2 = src1Negate[2];
    src1SelectX = *src1Select;
    src1Select1 = src1Select[1];
    tokenIndex = src1Select[2];
  }
  src1Header = src1Header | 0x400000;
  src1SwizzleWord = (src1Negate3 & 1) << 0xf |
           (src1Select3 & 7) << 0xc |
           (src1Negate2 & 1) << 0xb |
           (tokenIndex & 7) << 8 |
           (src1Negate1 & 1) << 7 | (src1Select1 & 7) << 4 | (*src1Negate & 1) << 3 | src1SelectX & 7;
LAB_00066f14:
  tokenIndex = *tokenCount;
  iVar16 = *(int *)(ctx + ARB_allocator);
  if (*(uint *)(ctx + ARB_tokenCapacity) <= tokenIndex) {
    newStorage = (**(code **)(iVar16 + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
    if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
      _memcpy(newStorage,*(int *)(ctx + ARB_tokenBuffer),*tokenCount << 2);
      (**(code **)(iVar16 + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
    }
    *(undefined4 *)(ctx + ARB_tokenBuffer) = newStorage;
    tokenIndex = *tokenCount;
    *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
  }
  *(undefined4 *)(tokenIndex * 4 + *(int *)(ctx + ARB_tokenBuffer)) = 0x49;
  tokenIndex = *tokenCount + 1;
  *tokenCount = tokenIndex;
  iVar16 = *(int *)(ctx + ARB_allocator);
  if (*(uint *)(ctx + ARB_tokenCapacity) <= tokenIndex) {
    newStorage = (**(code **)(iVar16 + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
    if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
      _memcpy(newStorage,*(int *)(ctx + ARB_tokenBuffer),*tokenCount << 2);
      (**(code **)(iVar16 + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
    }
    *(undefined4 *)(ctx + ARB_tokenBuffer) = newStorage;
    tokenIndex = *tokenCount;
    *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
  }
  *(uint *)(tokenIndex * 4 + *(int *)(ctx + ARB_tokenBuffer)) = dstHeader;
  tokenIndex = *tokenCount + 1;
  *tokenCount = tokenIndex;
  if ((dstHeader & 0x400000) != 0) {
    iVar16 = *(int *)(ctx + ARB_allocator);
    if (*(uint *)(ctx + ARB_tokenCapacity) <= tokenIndex) {
      newStorage = (**(code **)(iVar16 + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
      if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
        _memcpy(newStorage,*(int *)(ctx + ARB_tokenBuffer),*tokenCount << 2);
        (**(code **)(iVar16 + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
      }
      *(undefined4 *)(ctx + ARB_tokenBuffer) = newStorage;
      tokenIndex = *tokenCount;
      *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
    }
    *(uint *)(tokenIndex * 4 + *(int *)(ctx + ARB_tokenBuffer)) = dstMaskWord;
    tokenIndex = *tokenCount + 1;
    *tokenCount = tokenIndex;
  }
  iVar16 = *(int *)(ctx + ARB_allocator);
  if (*(uint *)(ctx + ARB_tokenCapacity) <= tokenIndex) {
    newStorage = (**(code **)(iVar16 + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
    if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
      _memcpy(newStorage,*(int *)(ctx + ARB_tokenBuffer),*tokenCount << 2);
      (**(code **)(iVar16 + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
    }
    *(undefined4 *)(ctx + ARB_tokenBuffer) = newStorage;
    tokenIndex = *tokenCount;
    *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
  }
  *(uint *)(tokenIndex * 4 + *(int *)(ctx + ARB_tokenBuffer)) = src0Header;
  dstHeader = *tokenCount + 1;
  *tokenCount = dstHeader;
  if ((src0Header & 0x400000) != 0) {
    iVar16 = *(int *)(ctx + ARB_allocator);
    if (*(uint *)(ctx + ARB_tokenCapacity) <= dstHeader) {
      newStorage = (**(code **)(iVar16 + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
      if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
        _memcpy(newStorage,*(int *)(ctx + ARB_tokenBuffer),*tokenCount << 2);
        (**(code **)(iVar16 + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
      }
      *(undefined4 *)(ctx + ARB_tokenBuffer) = newStorage;
      dstHeader = *tokenCount;
      *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
    }
    *(uint *)(dstHeader * 4 + *(int *)(ctx + ARB_tokenBuffer)) = src0SwizzleWord;
    dstHeader = *tokenCount + 1;
    *tokenCount = dstHeader;
  }
  iVar16 = *(int *)(ctx + ARB_allocator);
  if (*(uint *)(ctx + ARB_tokenCapacity) <= dstHeader) {
    newStorage = (**(code **)(iVar16 + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
    if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
      _memcpy(newStorage,*(int *)(ctx + ARB_tokenBuffer),*tokenCount << 2);
      (**(code **)(iVar16 + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
    }
    *(undefined4 *)(ctx + ARB_tokenBuffer) = newStorage;
    dstHeader = *tokenCount;
    *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
  }
  *(uint *)(dstHeader * 4 + *(int *)(ctx + ARB_tokenBuffer)) = src1Header;
  dstHeader = *tokenCount + 1;
  *tokenCount = dstHeader;
  if ((src1Header & 0x400000) != 0) {
    iVar16 = *(int *)(ctx + ARB_allocator);
    if (*(uint *)(ctx + ARB_tokenCapacity) <= dstHeader) {
      newStorage = (**(code **)(iVar16 + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
      if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
        _memcpy(newStorage,*(int *)(ctx + ARB_tokenBuffer),*tokenCount << 2);
        (**(code **)(iVar16 + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
      }
      *(undefined4 *)(ctx + ARB_tokenBuffer) = newStorage;
      dstHeader = *tokenCount;
      *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
    }
    *(uint *)(dstHeader * 4 + *(int *)(ctx + ARB_tokenBuffer)) = src1SwizzleWord;
    *tokenCount = *tokenCount + 1;
  }
  return;
}

/* arbEmitIlAdd @ 0x67320 (1912 bytes) */
int arbEmitIlAdd(ctx, dstFile, dstIndex, dstMask, src0File, src0Index, src0Select, src0Negate, src1File, src1Index, src1Select, src1Negate)
  int ctx;
  uint dstFile;
  uint dstIndex;
  int *dstMask;
  uint src0File;
  uint src0Index;
  uint *src0Select;
  uint *src0Negate;
  uint src1File;
  uint src1Index;
  uint *src1Select;
  uint *src1Negate;
{
  uint src1Select3;
  uint src1Negate2;
  uint src1Negate3;
  uint src1Select1;
  uint src1Negate1;
  uint src1Header;
  int dstMask2;
  uint tokenIndex;
  undefined4 newStorage;
  uint src0Negate3;
  uint src0Negate2;
  uint src0Negate1;
  int dstMask1;
  uint src0Select3;
  uint src0SelectX;
  uint src1SelectX;
  uint src0Header;
  uint dstHeader;
  uint dstMaskWord;
  uint src1SwizzleWord;
  int iVar16;
  uint src0SwizzleWord;
  uint *tokenCount;
  
  dstHeader = (dstFile & 0x3f) << 0x10 | dstIndex & 0xffff;
  tokenCount = (uint *)(ctx + ARB_tokenCount);
  src1SwizzleWord = 0;
  src0SwizzleWord = 0;
  dstMaskWord = 0;
  if ((dstFile == 0x12) || (dstFile == 0x13)) {
    dstHeader = dstHeader | 0x400000;
    dstMaskWord = 0x55;
  }
  if (*dstMask == 0) {
    iVar16 = dstMask[3];
    dstMask1 = dstMask[1];
    dstMask2 = dstMask[2];
LAB_00067410:
    dstHeader = dstHeader | 0x400000;
    dstMaskWord = (uint)(iVar16 != 0) * 0x40 |
             (uint)(dstMask2 != 0) * 0x10 | (uint)(dstMask1 != 0) * 4 | (uint)(*dstMask != 0);
  }
  else {
    dstMask1 = dstMask[1];
    if (dstMask1 == 0) {
      iVar16 = dstMask[3];
      dstMask2 = dstMask[2];
      goto LAB_00067410;
    }
    dstMask2 = dstMask[2];
    if (dstMask2 == 0) {
      iVar16 = dstMask[3];
      goto LAB_00067410;
    }
    if (dstMask[3] == 0) {
      iVar16 = 0;
      goto LAB_00067410;
    }
  }
  src0Header = (src0File & 0x3f) << 0x10 | src0Index & 0xffff;
  if (*src0Negate == 0) {
    src0Negate1 = src0Negate[1];
    if (src0Negate1 != 0) {
      src0Negate3 = src0Negate[3];
      src0Select3 = src0Select[3];
      src0Negate2 = src0Negate[2];
      src0SelectX = *src0Select;
      tokenIndex = src0Select[1];
      src1Header = src0Select[2];
      goto LAB_00067560;
    }
    src0Negate2 = src0Negate[2];
    if (src0Negate2 != 0) {
      src0Negate3 = src0Negate[3];
      src0Select3 = src0Select[3];
      src0SelectX = *src0Select;
      tokenIndex = src0Select[1];
      src1Header = src0Select[2];
      goto LAB_00067560;
    }
    src0Negate3 = src0Negate[3];
    if (src0Negate3 != 0) {
      src0Select3 = src0Select[3];
      src0SelectX = *src0Select;
      tokenIndex = src0Select[1];
      src1Header = src0Select[2];
      goto LAB_00067560;
    }
    src0SelectX = *src0Select;
    if (src0SelectX != 0) {
      src0Select3 = src0Select[3];
      tokenIndex = src0Select[1];
      src1Header = src0Select[2];
      goto LAB_00067560;
    }
    tokenIndex = src0Select[1];
    if (tokenIndex != 1) {
      src0Select3 = src0Select[3];
      src1Header = src0Select[2];
      goto LAB_00067560;
    }
    src1Header = src0Select[2];
    if (src1Header != 2) {
      src0Select3 = src0Select[3];
      goto LAB_00067560;
    }
    src0Select3 = src0Select[3];
    if (src0Select3 != 3) goto LAB_00067560;
  }
  else {
    src0Negate3 = src0Negate[3];
    src0Select3 = src0Select[3];
    src0Negate1 = src0Negate[1];
    src0Negate2 = src0Negate[2];
    src0SelectX = *src0Select;
    tokenIndex = src0Select[1];
    src1Header = src0Select[2];
LAB_00067560:
    src0Header = src0Header | 0x400000;
    src0SwizzleWord = (src0Negate3 & 1) << 0xf |
             (src0Select3 & 7) << 0xc |
             (src0Negate2 & 1) << 0xb |
             (src1Header & 7) << 8 |
             (src0Negate1 & 1) << 7 | (tokenIndex & 7) << 4 | (*src0Negate & 1) << 3 | src0SelectX & 7;
  }
  src1Header = (src1File & 0x3f) << 0x10 | src1Index & 0xffff;
  if (*src1Negate == 0) {
    src1Negate1 = src1Negate[1];
    if (src1Negate1 == 0) {
      src1Negate2 = src1Negate[2];
      if (src1Negate2 == 0) {
        src1Negate3 = src1Negate[3];
        if (src1Negate3 == 0) {
          src1SelectX = *src1Select;
          if (src1SelectX == 0) {
            src1Select1 = src1Select[1];
            if (src1Select1 == 1) {
              tokenIndex = src1Select[2];
              if (tokenIndex == 2) {
                src1Select3 = src1Select[3];
                if (src1Select3 == 3) goto LAB_000676b4;
              }
              else {
                src1Select3 = src1Select[3];
              }
            }
            else {
              src1Select3 = src1Select[3];
              tokenIndex = src1Select[2];
            }
          }
          else {
            src1Select3 = src1Select[3];
            src1Select1 = src1Select[1];
            tokenIndex = src1Select[2];
          }
        }
        else {
          src1Select3 = src1Select[3];
          src1SelectX = *src1Select;
          src1Select1 = src1Select[1];
          tokenIndex = src1Select[2];
        }
      }
      else {
        src1Negate3 = src1Negate[3];
        src1Select3 = src1Select[3];
        src1SelectX = *src1Select;
        src1Select1 = src1Select[1];
        tokenIndex = src1Select[2];
      }
    }
    else {
      src1Negate3 = src1Negate[3];
      src1Select3 = src1Select[3];
      src1Negate2 = src1Negate[2];
      src1SelectX = *src1Select;
      src1Select1 = src1Select[1];
      tokenIndex = src1Select[2];
    }
  }
  else {
    src1Negate3 = src1Negate[3];
    src1Select3 = src1Select[3];
    src1Negate1 = src1Negate[1];
    src1Negate2 = src1Negate[2];
    src1SelectX = *src1Select;
    src1Select1 = src1Select[1];
    tokenIndex = src1Select[2];
  }
  src1Header = src1Header | 0x400000;
  src1SwizzleWord = (src1Negate3 & 1) << 0xf |
           (src1Select3 & 7) << 0xc |
           (src1Negate2 & 1) << 0xb |
           (tokenIndex & 7) << 8 |
           (src1Negate1 & 1) << 7 | (src1Select1 & 7) << 4 | (*src1Negate & 1) << 3 | src1SelectX & 7;
LAB_000676b4:
  tokenIndex = *tokenCount;
  iVar16 = *(int *)(ctx + ARB_allocator);
  if (*(uint *)(ctx + ARB_tokenCapacity) <= tokenIndex) {
    newStorage = (**(code **)(iVar16 + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
    if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
      _memcpy(newStorage,*(int *)(ctx + ARB_tokenBuffer),*tokenCount << 2);
      (**(code **)(iVar16 + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
    }
    *(undefined4 *)(ctx + ARB_tokenBuffer) = newStorage;
    tokenIndex = *tokenCount;
    *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
  }
  *(undefined4 *)(tokenIndex * 4 + *(int *)(ctx + ARB_tokenBuffer)) = 3;
  tokenIndex = *tokenCount + 1;
  *tokenCount = tokenIndex;
  iVar16 = *(int *)(ctx + ARB_allocator);
  if (*(uint *)(ctx + ARB_tokenCapacity) <= tokenIndex) {
    newStorage = (**(code **)(iVar16 + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
    if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
      _memcpy(newStorage,*(int *)(ctx + ARB_tokenBuffer),*tokenCount << 2);
      (**(code **)(iVar16 + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
    }
    *(undefined4 *)(ctx + ARB_tokenBuffer) = newStorage;
    tokenIndex = *tokenCount;
    *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
  }
  *(uint *)(tokenIndex * 4 + *(int *)(ctx + ARB_tokenBuffer)) = dstHeader;
  tokenIndex = *tokenCount + 1;
  *tokenCount = tokenIndex;
  if ((dstHeader & 0x400000) != 0) {
    iVar16 = *(int *)(ctx + ARB_allocator);
    if (*(uint *)(ctx + ARB_tokenCapacity) <= tokenIndex) {
      newStorage = (**(code **)(iVar16 + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
      if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
        _memcpy(newStorage,*(int *)(ctx + ARB_tokenBuffer),*tokenCount << 2);
        (**(code **)(iVar16 + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
      }
      *(undefined4 *)(ctx + ARB_tokenBuffer) = newStorage;
      tokenIndex = *tokenCount;
      *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
    }
    *(uint *)(tokenIndex * 4 + *(int *)(ctx + ARB_tokenBuffer)) = dstMaskWord;
    tokenIndex = *tokenCount + 1;
    *tokenCount = tokenIndex;
  }
  iVar16 = *(int *)(ctx + ARB_allocator);
  if (*(uint *)(ctx + ARB_tokenCapacity) <= tokenIndex) {
    newStorage = (**(code **)(iVar16 + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
    if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
      _memcpy(newStorage,*(int *)(ctx + ARB_tokenBuffer),*tokenCount << 2);
      (**(code **)(iVar16 + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
    }
    *(undefined4 *)(ctx + ARB_tokenBuffer) = newStorage;
    tokenIndex = *tokenCount;
    *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
  }
  *(uint *)(tokenIndex * 4 + *(int *)(ctx + ARB_tokenBuffer)) = src0Header;
  dstHeader = *tokenCount + 1;
  *tokenCount = dstHeader;
  if ((src0Header & 0x400000) != 0) {
    iVar16 = *(int *)(ctx + ARB_allocator);
    if (*(uint *)(ctx + ARB_tokenCapacity) <= dstHeader) {
      newStorage = (**(code **)(iVar16 + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
      if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
        _memcpy(newStorage,*(int *)(ctx + ARB_tokenBuffer),*tokenCount << 2);
        (**(code **)(iVar16 + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
      }
      *(undefined4 *)(ctx + ARB_tokenBuffer) = newStorage;
      dstHeader = *tokenCount;
      *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
    }
    *(uint *)(dstHeader * 4 + *(int *)(ctx + ARB_tokenBuffer)) = src0SwizzleWord;
    dstHeader = *tokenCount + 1;
    *tokenCount = dstHeader;
  }
  iVar16 = *(int *)(ctx + ARB_allocator);
  if (*(uint *)(ctx + ARB_tokenCapacity) <= dstHeader) {
    newStorage = (**(code **)(iVar16 + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
    if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
      _memcpy(newStorage,*(int *)(ctx + ARB_tokenBuffer),*tokenCount << 2);
      (**(code **)(iVar16 + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
    }
    *(undefined4 *)(ctx + ARB_tokenBuffer) = newStorage;
    dstHeader = *tokenCount;
    *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
  }
  *(uint *)(dstHeader * 4 + *(int *)(ctx + ARB_tokenBuffer)) = src1Header;
  dstHeader = *tokenCount + 1;
  *tokenCount = dstHeader;
  if ((src1Header & 0x400000) != 0) {
    iVar16 = *(int *)(ctx + ARB_allocator);
    if (*(uint *)(ctx + ARB_tokenCapacity) <= dstHeader) {
      newStorage = (**(code **)(iVar16 + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
      if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
        _memcpy(newStorage,*(int *)(ctx + ARB_tokenBuffer),*tokenCount << 2);
        (**(code **)(iVar16 + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
      }
      *(undefined4 *)(ctx + ARB_tokenBuffer) = newStorage;
      dstHeader = *tokenCount;
      *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
    }
    *(uint *)(dstHeader * 4 + *(int *)(ctx + ARB_tokenBuffer)) = src1SwizzleWord;
    *tokenCount = *tokenCount + 1;
  }
  return;
}

/* arbEmitIlMad @ 0x67ac0 (2516 bytes) */
int arbEmitIlMad(ctx, dstFile, dstIndex, dstMask, src0File, src0Index, src0Select, src0Negate, src1File, src1Index, src1Select, src1Negate, src2File, src2Index, src2Select, src2Negate)
  int ctx;
  uint dstFile;
  uint dstIndex;
  int *dstMask;
  uint src0File;
  uint src0Index;
  uint *src0Select;
  uint *src0Negate;
  uint src1File;
  uint src1Index;
  uint *src1Select;
  uint *src1Negate;
  uint src2File;
  uint src2Index;
  uint *src2Select;
  uint *src2Negate;
{
  int allocator;
  uint dstToken;
  uint src2NegateY;
  uint src2SelectW;
  uint src1NegateY;
  uint src2NegateZ;
  uint src1SelectW;
  uint src2NegateW;
  uint src1NegateZ;
  uint src2SelectY;
  uint src1NegateW;
  uint src2SelectZ;
  uint src1SelectY;
  uint src0NegateW;
  uint src2Token;
  uint src1SelectZ;
  uint src1Token;
  uint instrCountPtrValue;
  uint src0SelectZ;
  int dstMaskZ;
  uint src0SelectY;
  undefined4 newTokenBuffer;
  uint nextTokenIndex;
  uint src0NegateZ;
  uint src0NegateY;
  int dstMaskY;
  uint src0SelectW;
  uint src0SelectX;
  uint src1SelectX;
  uint src2SelectX;
  uint nextTokenIndex2;
  uint src0Token;
  uint dstMaskWord;
  uint src2Packed;
  uint src1Packed;
  uint src0Packed;
  int dstMaskW;
  uint *instrCountPtr;
  
  dstToken = (dstFile & 0x3f) << 0x10 | dstIndex & 0xffff;
  instrCountPtr = (uint *)(ctx + ARB_tokenCount);
  src2Packed = 0;
  src1Packed = 0;
  src0Packed = 0;
  dstMaskWord = 0;
  if ((dstFile == 0x12) || (dstFile == 0x13)) {
    dstToken = dstToken | 0x400000;
    dstMaskWord = 0x55;
  }
  if (*dstMask == 0) {
    dstMaskW = dstMask[3];
    dstMaskY = dstMask[1];
    dstMaskZ = dstMask[2];
LAB_00067bc0:
    dstToken = dstToken | 0x400000;
    dstMaskWord = (uint)(dstMaskW != 0) * 0x40 |
             (uint)(dstMaskZ != 0) * 0x10 | (uint)(dstMaskY != 0) * 4 | (uint)(*dstMask != 0);
  }
  else {
    dstMaskY = dstMask[1];
    if (dstMaskY == 0) {
      dstMaskW = dstMask[3];
      dstMaskZ = dstMask[2];
      goto LAB_00067bc0;
    }
    dstMaskZ = dstMask[2];
    if (dstMaskZ == 0) {
      dstMaskW = dstMask[3];
      goto LAB_00067bc0;
    }
    if (dstMask[3] == 0) {
      dstMaskW = 0;
      goto LAB_00067bc0;
    }
  }
  src0Token = (src0File & 0x3f) << 0x10 | src0Index & 0xffff;
  if (*src0Negate == 0) {
    src0NegateY = src0Negate[1];
    if (src0NegateY != 0) {
      src0NegateW = src0Negate[3];
      src0SelectW = src0Select[3];
      src0NegateZ = src0Negate[2];
      src0SelectX = *src0Select;
      src0SelectY = src0Select[1];
      src0SelectZ = src0Select[2];
      goto LAB_00067d10;
    }
    src0NegateZ = src0Negate[2];
    if (src0NegateZ != 0) {
      src0NegateW = src0Negate[3];
      src0SelectW = src0Select[3];
      src0SelectX = *src0Select;
      src0SelectY = src0Select[1];
      src0SelectZ = src0Select[2];
      goto LAB_00067d10;
    }
    src0NegateW = src0Negate[3];
    if (src0NegateW != 0) {
      src0SelectW = src0Select[3];
      src0SelectX = *src0Select;
      src0SelectY = src0Select[1];
      src0SelectZ = src0Select[2];
      goto LAB_00067d10;
    }
    src0SelectX = *src0Select;
    if (src0SelectX != 0) {
      src0SelectW = src0Select[3];
      src0SelectY = src0Select[1];
      src0SelectZ = src0Select[2];
      goto LAB_00067d10;
    }
    src0SelectY = src0Select[1];
    if (src0SelectY != 1) {
      src0SelectW = src0Select[3];
      src0SelectZ = src0Select[2];
      goto LAB_00067d10;
    }
    src0SelectZ = src0Select[2];
    if (src0SelectZ != 2) {
      src0SelectW = src0Select[3];
      goto LAB_00067d10;
    }
    src0SelectW = src0Select[3];
    if (src0SelectW != 3) goto LAB_00067d10;
  }
  else {
    src0NegateW = src0Negate[3];
    src0SelectW = src0Select[3];
    src0NegateY = src0Negate[1];
    src0NegateZ = src0Negate[2];
    src0SelectX = *src0Select;
    src0SelectY = src0Select[1];
    src0SelectZ = src0Select[2];
LAB_00067d10:
    src0Token = src0Token | 0x400000;
    src0Packed = (src0NegateW & 1) << 0xf |
             (src0SelectW & 7) << 0xc |
             (src0NegateZ & 1) << 0xb |
             (src0SelectZ & 7) << 8 |
             (src0NegateY & 1) << 7 | (src0SelectY & 7) << 4 | (*src0Negate & 1) << 3 | src0SelectX & 7;
  }
  src1Token = (src1File & 0x3f) << 0x10 | src1Index & 0xffff;
  if (*src1Negate == 0) {
    src1NegateY = src1Negate[1];
    if (src1NegateY != 0) {
      src1NegateW = src1Negate[3];
      src1SelectW = src1Select[3];
      src1NegateZ = src1Negate[2];
      src1SelectX = *src1Select;
      src1SelectY = src1Select[1];
      src1SelectZ = src1Select[2];
      goto LAB_00067e40;
    }
    src1NegateZ = src1Negate[2];
    if (src1NegateZ != 0) {
      src1NegateW = src1Negate[3];
      src1SelectW = src1Select[3];
      src1SelectX = *src1Select;
      src1SelectY = src1Select[1];
      src1SelectZ = src1Select[2];
      goto LAB_00067e40;
    }
    src1NegateW = src1Negate[3];
    if (src1NegateW != 0) {
      src1SelectW = src1Select[3];
      src1SelectX = *src1Select;
      src1SelectY = src1Select[1];
      src1SelectZ = src1Select[2];
      goto LAB_00067e40;
    }
    src1SelectX = *src1Select;
    if (src1SelectX != 0) {
      src1SelectW = src1Select[3];
      src1SelectY = src1Select[1];
      src1SelectZ = src1Select[2];
      goto LAB_00067e40;
    }
    src1SelectY = src1Select[1];
    if (src1SelectY != 1) {
      src1SelectW = src1Select[3];
      src1SelectZ = src1Select[2];
      goto LAB_00067e40;
    }
    src1SelectZ = src1Select[2];
    if (src1SelectZ != 2) {
      src1SelectW = src1Select[3];
      goto LAB_00067e40;
    }
    src1SelectW = src1Select[3];
    if (src1SelectW != 3) goto LAB_00067e40;
  }
  else {
    src1NegateW = src1Negate[3];
    src1SelectW = src1Select[3];
    src1NegateY = src1Negate[1];
    src1NegateZ = src1Negate[2];
    src1SelectX = *src1Select;
    src1SelectY = src1Select[1];
    src1SelectZ = src1Select[2];
LAB_00067e40:
    src1Token = src1Token | 0x400000;
    src1Packed = (src1NegateW & 1) << 0xf |
             (src1SelectW & 7) << 0xc |
             (src1NegateZ & 1) << 0xb |
             (src1SelectZ & 7) << 8 |
             (src1NegateY & 1) << 7 | (src1SelectY & 7) << 4 | (*src1Negate & 1) << 3 | src1SelectX & 7;
  }
  src2Token = (src2File & 0x3f) << 0x10 | src2Index & 0xffff;
  if (*src2Negate == 0) {
    src2NegateY = src2Negate[1];
    if (src2NegateY == 0) {
      src2NegateZ = src2Negate[2];
      if (src2NegateZ == 0) {
        src2NegateW = src2Negate[3];
        if (src2NegateW == 0) {
          src2SelectX = *src2Select;
          if (src2SelectX == 0) {
            src2SelectY = src2Select[1];
            if (src2SelectY == 1) {
              src2SelectZ = src2Select[2];
              if (src2SelectZ == 2) {
                src2SelectW = src2Select[3];
                if (src2SelectW == 3) goto LAB_00067f94;
              }
              else {
                src2SelectW = src2Select[3];
              }
            }
            else {
              src2SelectW = src2Select[3];
              src2SelectZ = src2Select[2];
            }
          }
          else {
            src2SelectW = src2Select[3];
            src2SelectY = src2Select[1];
            src2SelectZ = src2Select[2];
          }
        }
        else {
          src2SelectW = src2Select[3];
          src2SelectX = *src2Select;
          src2SelectY = src2Select[1];
          src2SelectZ = src2Select[2];
        }
      }
      else {
        src2NegateW = src2Negate[3];
        src2SelectW = src2Select[3];
        src2SelectX = *src2Select;
        src2SelectY = src2Select[1];
        src2SelectZ = src2Select[2];
      }
    }
    else {
      src2NegateW = src2Negate[3];
      src2SelectW = src2Select[3];
      src2NegateZ = src2Negate[2];
      src2SelectX = *src2Select;
      src2SelectY = src2Select[1];
      src2SelectZ = src2Select[2];
    }
  }
  else {
    src2NegateW = src2Negate[3];
    src2SelectW = src2Select[3];
    src2NegateY = src2Negate[1];
    src2NegateZ = src2Negate[2];
    src2SelectX = *src2Select;
    src2SelectY = src2Select[1];
    src2SelectZ = src2Select[2];
  }
  src2Token = src2Token | 0x400000;
  src2Packed = (src2NegateW & 1) << 0xf |
           (src2SelectW & 7) << 0xc |
           (src2NegateZ & 1) << 0xb |
           (src2SelectZ & 7) << 8 |
           (src2NegateY & 1) << 7 | (src2SelectY & 7) << 4 | (*src2Negate & 1) << 3 | src2SelectX & 7;
LAB_00067f94:
  instrCountPtrValue = *instrCountPtr;
  allocator = *(int *)(ctx + ARB_allocator);
  if (*(uint *)(ctx + ARB_tokenCapacity) <= instrCountPtrValue) {
    newTokenBuffer = (**(code **)(allocator + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
    if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
      _memcpy(newTokenBuffer,*(int *)(ctx + ARB_tokenBuffer),*instrCountPtr << 2);
      (**(code **)(allocator + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
    }
    *(undefined4 *)(ctx + ARB_tokenBuffer) = newTokenBuffer;
    instrCountPtrValue = *instrCountPtr;
    *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
  }
  *(undefined4 *)(instrCountPtrValue * 4 + *(int *)(ctx + ARB_tokenBuffer)) = 0x40;
  nextTokenIndex = *instrCountPtr + 1;
  *instrCountPtr = nextTokenIndex;
  allocator = *(int *)(ctx + ARB_allocator);
  if (*(uint *)(ctx + ARB_tokenCapacity) <= nextTokenIndex) {
    newTokenBuffer = (**(code **)(allocator + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
    if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
      _memcpy(newTokenBuffer,*(int *)(ctx + ARB_tokenBuffer),*instrCountPtr << 2);
      (**(code **)(allocator + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
    }
    *(undefined4 *)(ctx + ARB_tokenBuffer) = newTokenBuffer;
    nextTokenIndex = *instrCountPtr;
    *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
  }
  *(uint *)(nextTokenIndex * 4 + *(int *)(ctx + ARB_tokenBuffer)) = dstToken;
  nextTokenIndex = *instrCountPtr + 1;
  *instrCountPtr = nextTokenIndex;
  if ((dstToken & 0x400000) != 0) {
    allocator = *(int *)(ctx + ARB_allocator);
    if (*(uint *)(ctx + ARB_tokenCapacity) <= nextTokenIndex) {
      newTokenBuffer = (**(code **)(allocator + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
      if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
        _memcpy(newTokenBuffer,*(int *)(ctx + ARB_tokenBuffer),*instrCountPtr << 2);
        (**(code **)(allocator + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
      }
      *(undefined4 *)(ctx + ARB_tokenBuffer) = newTokenBuffer;
      nextTokenIndex = *instrCountPtr;
      *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
    }
    *(uint *)(nextTokenIndex * 4 + *(int *)(ctx + ARB_tokenBuffer)) = dstMaskWord;
    nextTokenIndex = *instrCountPtr + 1;
    *instrCountPtr = nextTokenIndex;
  }
  allocator = *(int *)(ctx + ARB_allocator);
  if (*(uint *)(ctx + ARB_tokenCapacity) <= nextTokenIndex) {
    newTokenBuffer = (**(code **)(allocator + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
    if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
      _memcpy(newTokenBuffer,*(int *)(ctx + ARB_tokenBuffer),*instrCountPtr << 2);
      (**(code **)(allocator + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
    }
    *(undefined4 *)(ctx + ARB_tokenBuffer) = newTokenBuffer;
    nextTokenIndex = *instrCountPtr;
    *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
  }
  *(uint *)(nextTokenIndex * 4 + *(int *)(ctx + ARB_tokenBuffer)) = src0Token;
  nextTokenIndex2 = *instrCountPtr + 1;
  *instrCountPtr = nextTokenIndex2;
  if ((src0Token & 0x400000) != 0) {
    allocator = *(int *)(ctx + ARB_allocator);
    if (*(uint *)(ctx + ARB_tokenCapacity) <= nextTokenIndex2) {
      newTokenBuffer = (**(code **)(allocator + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
      if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
        _memcpy(newTokenBuffer,*(int *)(ctx + ARB_tokenBuffer),*instrCountPtr << 2);
        (**(code **)(allocator + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
      }
      *(undefined4 *)(ctx + ARB_tokenBuffer) = newTokenBuffer;
      nextTokenIndex2 = *instrCountPtr;
      *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
    }
    *(uint *)(nextTokenIndex2 * 4 + *(int *)(ctx + ARB_tokenBuffer)) = src0Packed;
    nextTokenIndex2 = *instrCountPtr + 1;
    *instrCountPtr = nextTokenIndex2;
  }
  allocator = *(int *)(ctx + ARB_allocator);
  if (*(uint *)(ctx + ARB_tokenCapacity) <= nextTokenIndex2) {
    newTokenBuffer = (**(code **)(allocator + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
    if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
      _memcpy(newTokenBuffer,*(int *)(ctx + ARB_tokenBuffer),*instrCountPtr << 2);
      (**(code **)(allocator + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
    }
    *(undefined4 *)(ctx + ARB_tokenBuffer) = newTokenBuffer;
    nextTokenIndex2 = *instrCountPtr;
    *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
  }
  *(uint *)(nextTokenIndex2 * 4 + *(int *)(ctx + ARB_tokenBuffer)) = src1Token;
  nextTokenIndex2 = *instrCountPtr + 1;
  *instrCountPtr = nextTokenIndex2;
  if ((src1Token & 0x400000) != 0) {
    allocator = *(int *)(ctx + ARB_allocator);
    if (*(uint *)(ctx + ARB_tokenCapacity) <= nextTokenIndex2) {
      newTokenBuffer = (**(code **)(allocator + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
      if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
        _memcpy(newTokenBuffer,*(int *)(ctx + ARB_tokenBuffer),*instrCountPtr << 2);
        (**(code **)(allocator + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
      }
      *(undefined4 *)(ctx + ARB_tokenBuffer) = newTokenBuffer;
      nextTokenIndex2 = *instrCountPtr;
      *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
    }
    *(uint *)(nextTokenIndex2 * 4 + *(int *)(ctx + ARB_tokenBuffer)) = src1Packed;
    nextTokenIndex2 = *instrCountPtr + 1;
    *instrCountPtr = nextTokenIndex2;
  }
  allocator = *(int *)(ctx + ARB_allocator);
  if (*(uint *)(ctx + ARB_tokenCapacity) <= nextTokenIndex2) {
    newTokenBuffer = (**(code **)(allocator + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
    if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
      _memcpy(newTokenBuffer,*(int *)(ctx + ARB_tokenBuffer),*instrCountPtr << 2);
      (**(code **)(allocator + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
    }
    *(undefined4 *)(ctx + ARB_tokenBuffer) = newTokenBuffer;
    nextTokenIndex2 = *instrCountPtr;
    *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
  }
  *(uint *)(nextTokenIndex2 * 4 + *(int *)(ctx + ARB_tokenBuffer)) = src2Token;
  nextTokenIndex2 = *instrCountPtr + 1;
  *instrCountPtr = nextTokenIndex2;
  if ((src2Token & 0x400000) != 0) {
    allocator = *(int *)(ctx + ARB_allocator);
    if (*(uint *)(ctx + ARB_tokenCapacity) <= nextTokenIndex2) {
      newTokenBuffer = (**(code **)(allocator + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
      if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
        _memcpy(newTokenBuffer,*(int *)(ctx + ARB_tokenBuffer),*instrCountPtr << 2);
        (**(code **)(allocator + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
      }
      *(undefined4 *)(ctx + ARB_tokenBuffer) = newTokenBuffer;
      nextTokenIndex2 = *instrCountPtr;
      *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
    }
    *(uint *)(nextTokenIndex2 * 4 + *(int *)(ctx + ARB_tokenBuffer)) = src2Packed;
    *instrCountPtr = *instrCountPtr + 1;
  }
  return;
}

/* arbEmitIlAddMad3Src @ 0x684c0 (3632 bytes) */
int arbEmitIlAddMad3Src(ctx, dstFile, dstIndex, dstMask, src0File, src0Index, src0Words, src0Flags, src1File, src1Index, src1Words, src1Flags, src2File, src2Index, src2Words, src2Flags)
  int ctx;
  uint dstFile;
  uint dstIndex;
  int *dstMask;
  uint src0File;
  uint src0Index;
  uint *src0Words;
  uint *src0Flags;
  uint src1File;
  uint src1Index;
  uint *src1Words;
  uint *src1Flags;
  uint src2File;
  uint src2Index;
  uint *src2Words;
  uint *src2Flags;
{
  int dstMaskW;
  uint nextTokenIndex;
  uint src2Words2;
  uint src1Words1;
  uint src2Words3;
  uint src1Words2;
  uint src2Flags1;
  uint src1Words3;
  uint src2Flags3;
  uint src1Flags1;
  uint src1Flags3;
  uint src0Words1;
  uint src2Flags2;
  uint src2Words1;
  uint src1Flags2;
  uint src0Words2;
  uint src1Token;
  int dstMaskZ;
  uint src2Token;
  undefined4 newBuffer;
  uint src0Flags3;
  uint src0Flags2;
  uint src0Flags1;
  int dstMaskY;
  uint src0Words3;
  uint uVar10;
  uint tempRegIndex;
  uint src0WordsValue;
  uint src1WordsValue;
  uint src2WordsValue;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  int allocator;
  uint *instrCountPtr;
  uint uStack0000001c;
  uint uStack00000020;
  undefined1 auStack_88 [4];
  uint uStack_84;
  uint uStack_58;
  
  instrCountPtr = (uint *)(ctx + ARB_tokenCount);
  uVar17 = 0;
  uVar16 = 0;
  uVar18 = 0;
  uVar15 = 0;
  uStack0000001c = dstFile;
  uStack00000020 = dstIndex;
  (**(code **)(ctx + 0x748))(ctx,0,auStack_88,dstMask,src0File,src0Index,src0Words,src0Flags);
  tempRegIndex = uStack_84 & 0xffff;
  uStack_58 = 3;
  allocator = *(int *)(ctx + ARB_allocator);
  if (*(uint *)(ctx + ARB_tokenCapacity) <= *(uint *)(ctx + ARB_tokenCount)) {
    newBuffer = (**(code **)(allocator + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
    if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
      _memcpy(newBuffer,*(int *)(ctx + ARB_tokenBuffer),*(int *)(ctx + ARB_tokenCount) << 2);
      (**(code **)(allocator + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
    }
    *(undefined4 *)(ctx + ARB_tokenBuffer) = newBuffer;
    *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
  }
  *(uint *)(*instrCountPtr * 4 + *(int *)(ctx + ARB_tokenBuffer)) = uStack_58;
  uVar10 = *instrCountPtr + 1;
  *instrCountPtr = uVar10;
  allocator = *(int *)(ctx + ARB_allocator);
  if (*(uint *)(ctx + ARB_tokenCapacity) <= uVar10) {
    newBuffer = (**(code **)(allocator + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
    if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
      _memcpy(newBuffer,*(int *)(ctx + ARB_tokenBuffer),*instrCountPtr << 2);
      (**(code **)(allocator + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
    }
    *(undefined4 *)(ctx + ARB_tokenBuffer) = newBuffer;
    uVar10 = *instrCountPtr;
    *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
  }
  *(uint *)(uVar10 * 4 + *(int *)(ctx + ARB_tokenBuffer)) = tempRegIndex | 0x40000;
  nextTokenIndex = *instrCountPtr + 1;
  *instrCountPtr = nextTokenIndex;
  allocator = *(int *)(ctx + ARB_allocator);
  if (*(uint *)(ctx + ARB_tokenCapacity) <= nextTokenIndex) {
    newBuffer = (**(code **)(allocator + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
    if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
      _memcpy(newBuffer,*(int *)(ctx + ARB_tokenBuffer),*instrCountPtr << 2);
      (**(code **)(allocator + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
    }
    *(undefined4 *)(ctx + ARB_tokenBuffer) = newBuffer;
    nextTokenIndex = *instrCountPtr;
    *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
  }
  *(uint *)(nextTokenIndex * 4 + *(int *)(ctx + ARB_tokenBuffer)) = (src0File & 0x3f) << 0x10 | src0Index & 0xffff;
  nextTokenIndex = *instrCountPtr + 1;
  *instrCountPtr = nextTokenIndex;
  allocator = *(int *)(ctx + ARB_allocator);
  if (*(uint *)(ctx + ARB_tokenCapacity) <= nextTokenIndex) {
    newBuffer = (**(code **)(allocator + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
    if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
      _memcpy(newBuffer,*(int *)(ctx + ARB_tokenBuffer),*instrCountPtr << 2);
      (**(code **)(allocator + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
    }
    *(undefined4 *)(ctx + ARB_tokenBuffer) = newBuffer;
    nextTokenIndex = *instrCountPtr;
    *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
  }
  *(uint *)(nextTokenIndex * 4 + *(int *)(ctx + ARB_tokenBuffer)) = (src0File & 0x3f) << 0x10 | src0Index & 0xffff;
  nextTokenIndex = *instrCountPtr + 1;
  *instrCountPtr = nextTokenIndex;
  uStack_58 = uStack_58 & 0xffff0000 | 0x40;
  uVar10 = (uStack0000001c & 0x3f) << 0x10 | uStack00000020 & 0xffff;
  if ((uStack0000001c == 0x12) || (uStack0000001c == 0x13)) {
    uVar10 = uVar10 | 0x400000;
    uVar15 = 0x55;
  }
  if (*dstMask == 0) {
    dstMaskW = dstMask[3];
    dstMaskY = dstMask[1];
    dstMaskZ = dstMask[2];
LAB_00068a20:
    uVar10 = uVar10 | 0x400000;
    uVar15 = (uint)(dstMaskW != 0) * 0x40 |
             (uint)(dstMaskZ != 0) * 0x10 | (uint)(dstMaskY != 0) * 4 | (uint)(*dstMask != 0);
  }
  else {
    dstMaskY = dstMask[1];
    if (dstMaskY == 0) {
      dstMaskW = dstMask[3];
      dstMaskZ = dstMask[2];
      goto LAB_00068a20;
    }
    dstMaskZ = dstMask[2];
    if (dstMaskZ == 0) {
      dstMaskW = dstMask[3];
      goto LAB_00068a20;
    }
    if (dstMask[3] == 0) {
      dstMaskW = 0;
      goto LAB_00068a20;
    }
  }
  uVar19 = (src0File & 0x3f) << 0x10 | uStack_84 & 0xffff;
  if (*src0Flags == 0) {
    src0Flags1 = src0Flags[1];
    if (src0Flags1 != 0) {
      src0Flags3 = src0Flags[3];
      src0Words3 = src0Words[3];
      src0Flags2 = src0Flags[2];
      src0WordsValue = *src0Words;
      src0Words1 = src0Words[1];
      src0Words2 = src0Words[2];
      goto LAB_00068b70;
    }
    src0Flags2 = src0Flags[2];
    if (src0Flags2 != 0) {
      src0Flags3 = src0Flags[3];
      src0Words3 = src0Words[3];
      src0WordsValue = *src0Words;
      src0Words1 = src0Words[1];
      src0Words2 = src0Words[2];
      goto LAB_00068b70;
    }
    src0Flags3 = src0Flags[3];
    if (src0Flags3 != 0) {
      src0Words3 = src0Words[3];
      src0WordsValue = *src0Words;
      src0Words1 = src0Words[1];
      src0Words2 = src0Words[2];
      goto LAB_00068b70;
    }
    src0WordsValue = *src0Words;
    if (src0WordsValue != 0) {
      src0Words3 = src0Words[3];
      src0Words1 = src0Words[1];
      src0Words2 = src0Words[2];
      goto LAB_00068b70;
    }
    src0Words1 = src0Words[1];
    if (src0Words1 != 1) {
      src0Words3 = src0Words[3];
      src0Words2 = src0Words[2];
      goto LAB_00068b70;
    }
    src0Words2 = src0Words[2];
    if (src0Words2 != 2) {
      src0Words3 = src0Words[3];
      goto LAB_00068b70;
    }
    src0Words3 = src0Words[3];
    if (src0Words3 != 3) goto LAB_00068b70;
  }
  else {
    src0Flags3 = src0Flags[3];
    src0Words3 = src0Words[3];
    src0Flags1 = src0Flags[1];
    src0Flags2 = src0Flags[2];
    src0WordsValue = *src0Words;
    src0Words1 = src0Words[1];
    src0Words2 = src0Words[2];
LAB_00068b70:
    uVar19 = uVar19 | 0x400000;
    uVar18 = (src0Flags3 & 1) << 0xf |
             (src0Words3 & 7) << 0xc |
             (src0Flags2 & 1) << 0xb |
             (src0Words2 & 7) << 8 |
             (src0Flags1 & 1) << 7 | (src0Words1 & 7) << 4 | (*src0Flags & 1) << 3 | src0WordsValue & 7;
  }
  src1Token = (src1File & 0x3f) << 0x10 | src1Index & 0xffff;
  if (*src1Flags == 0) {
    src1Flags1 = src1Flags[1];
    if (src1Flags1 != 0) {
      src1Words3 = src1Words[3];
      src1Flags3 = src1Flags[3];
      goto LAB_00068c4c;
    }
    src1Flags2 = src1Flags[2];
    if (src1Flags2 != 0) {
      src1Words3 = src1Words[3];
      src1WordsValue = *src1Words;
      src1Words2 = src1Words[2];
      src1Flags3 = src1Flags[3];
      src1Words1 = src1Words[1];
      goto LAB_00068cb0;
    }
    src1Flags3 = src1Flags[3];
    if (src1Flags3 != 0) {
      src1Words3 = src1Words[3];
      src1WordsValue = *src1Words;
      src1Words1 = src1Words[1];
      src1Words2 = src1Words[2];
      goto LAB_00068cb0;
    }
    src1WordsValue = *src1Words;
    if (src1WordsValue != 0) {
      src1Words3 = src1Words[3];
      src1Words1 = src1Words[1];
      src1Words2 = src1Words[2];
      goto LAB_00068cb0;
    }
    src1Words1 = src1Words[1];
    if (src1Words1 != 1) {
      src1Words3 = src1Words[3];
      src1Words2 = src1Words[2];
      goto LAB_00068cb0;
    }
    src1Words2 = src1Words[2];
    if (src1Words2 != 2) {
      src1Words3 = src1Words[3];
      goto LAB_00068cb0;
    }
    src1Words3 = src1Words[3];
    if (src1Words3 != 3) goto LAB_00068cb0;
  }
  else {
    src1Words3 = src1Words[3];
    src1Flags3 = src1Flags[3];
    src1Flags1 = src1Flags[1];
LAB_00068c4c:
    src1Flags2 = src1Flags[2];
    src1WordsValue = *src1Words;
    src1Words1 = src1Words[1];
    src1Words2 = src1Words[2];
LAB_00068cb0:
    src1Token = src1Token | 0x400000;
    uVar16 = (src1Flags3 & 1) << 0xf |
             (src1Words3 & 7) << 0xc |
             (src1Flags2 & 1) << 0xb |
             (src1Words2 & 7) << 8 |
             (src1Flags1 & 1) << 7 | (src1Words1 & 7) << 4 | (*src1Flags & 1) << 3 | src1WordsValue & 7;
  }
  src2Token = (src2File & 0x3f) << 0x10 | src2Index & 0xffff;
  if (*src2Flags == 0) {
    src2Flags1 = src2Flags[1];
    if (src2Flags1 != 0) {
      src2Words3 = src2Words[3];
      src2Flags3 = src2Flags[3];
      goto LAB_00068d8c;
    }
    src2Flags2 = src2Flags[2];
    if (src2Flags2 == 0) {
      src2Flags3 = src2Flags[3];
      if (src2Flags3 == 0) {
        src2WordsValue = *src2Words;
        if (src2WordsValue == 0) {
          src2Words1 = src2Words[1];
          if (src2Words1 == 1) {
            src2Words2 = src2Words[2];
            if (src2Words2 == 2) {
              src2Words3 = src2Words[3];
              if (src2Words3 == 3) goto LAB_00068e14;
            }
            else {
              src2Words3 = src2Words[3];
            }
          }
          else {
            src2Words3 = src2Words[3];
            src2Words2 = src2Words[2];
          }
        }
        else {
          src2Words3 = src2Words[3];
          src2Words1 = src2Words[1];
          src2Words2 = src2Words[2];
        }
      }
      else {
        src2Words3 = src2Words[3];
        src2WordsValue = *src2Words;
        src2Words1 = src2Words[1];
        src2Words2 = src2Words[2];
      }
    }
    else {
      src2Words3 = src2Words[3];
      src2WordsValue = *src2Words;
      src2Words2 = src2Words[2];
      src2Flags3 = src2Flags[3];
      src2Words1 = src2Words[1];
    }
  }
  else {
    src2Words3 = src2Words[3];
    src2Flags3 = src2Flags[3];
    src2Flags1 = src2Flags[1];
LAB_00068d8c:
    src2Flags2 = src2Flags[2];
    src2WordsValue = *src2Words;
    src2Words1 = src2Words[1];
    src2Words2 = src2Words[2];
  }
  src2Token = src2Token | 0x400000;
  uVar17 = (src2Flags3 & 1) << 0xf |
           (src2Words3 & 7) << 0xc |
           (src2Flags2 & 1) << 0xb |
           (src2Words2 & 7) << 8 |
           (src2Flags1 & 1) << 7 | (src2Words1 & 7) << 4 | (*src2Flags & 1) << 3 | src2WordsValue & 7;
LAB_00068e14:
  allocator = *(int *)(ctx + ARB_allocator);
  if (*(uint *)(ctx + ARB_tokenCapacity) <= nextTokenIndex) {
    newBuffer = (**(code **)(allocator + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
    if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
      _memcpy(newBuffer,*(int *)(ctx + ARB_tokenBuffer),*instrCountPtr << 2);
      (**(code **)(allocator + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
    }
    *(undefined4 *)(ctx + ARB_tokenBuffer) = newBuffer;
    nextTokenIndex = *instrCountPtr;
    *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
  }
  *(uint *)(nextTokenIndex * 4 + *(int *)(ctx + ARB_tokenBuffer)) = uStack_58;
  nextTokenIndex = *instrCountPtr + 1;
  *instrCountPtr = nextTokenIndex;
  allocator = *(int *)(ctx + ARB_allocator);
  if (*(uint *)(ctx + ARB_tokenCapacity) <= nextTokenIndex) {
    newBuffer = (**(code **)(allocator + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
    if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
      _memcpy(newBuffer,*(int *)(ctx + ARB_tokenBuffer),*instrCountPtr << 2);
      (**(code **)(allocator + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
    }
    *(undefined4 *)(ctx + ARB_tokenBuffer) = newBuffer;
    nextTokenIndex = *instrCountPtr;
    *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
  }
  *(uint *)(nextTokenIndex * 4 + *(int *)(ctx + ARB_tokenBuffer)) = uVar10;
  nextTokenIndex = *instrCountPtr + 1;
  *instrCountPtr = nextTokenIndex;
  if ((uVar10 & 0x400000) != 0) {
    allocator = *(int *)(ctx + ARB_allocator);
    if (*(uint *)(ctx + ARB_tokenCapacity) <= nextTokenIndex) {
      newBuffer = (**(code **)(allocator + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
      if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
        _memcpy(newBuffer,*(int *)(ctx + ARB_tokenBuffer),*instrCountPtr << 2);
        (**(code **)(allocator + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
      }
      *(undefined4 *)(ctx + ARB_tokenBuffer) = newBuffer;
      nextTokenIndex = *instrCountPtr;
      *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
    }
    *(uint *)(nextTokenIndex * 4 + *(int *)(ctx + ARB_tokenBuffer)) = uVar15;
    nextTokenIndex = *instrCountPtr + 1;
    *instrCountPtr = nextTokenIndex;
  }
  allocator = *(int *)(ctx + ARB_allocator);
  if (*(uint *)(ctx + ARB_tokenCapacity) <= nextTokenIndex) {
    newBuffer = (**(code **)(allocator + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
    if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
      _memcpy(newBuffer,*(int *)(ctx + ARB_tokenBuffer),*instrCountPtr << 2);
      (**(code **)(allocator + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
    }
    *(undefined4 *)(ctx + ARB_tokenBuffer) = newBuffer;
    nextTokenIndex = *instrCountPtr;
    *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
  }
  *(uint *)(nextTokenIndex * 4 + *(int *)(ctx + ARB_tokenBuffer)) = uVar19;
  nextTokenIndex = *instrCountPtr + 1;
  *instrCountPtr = nextTokenIndex;
  if ((uVar19 & 0x400000) != 0) {
    allocator = *(int *)(ctx + ARB_allocator);
    if (*(uint *)(ctx + ARB_tokenCapacity) <= nextTokenIndex) {
      newBuffer = (**(code **)(allocator + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
      if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
        _memcpy(newBuffer,*(int *)(ctx + ARB_tokenBuffer),*instrCountPtr << 2);
        (**(code **)(allocator + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
      }
      *(undefined4 *)(ctx + ARB_tokenBuffer) = newBuffer;
      nextTokenIndex = *instrCountPtr;
      *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
    }
    *(uint *)(nextTokenIndex * 4 + *(int *)(ctx + ARB_tokenBuffer)) = uVar18;
    nextTokenIndex = *instrCountPtr + 1;
    *instrCountPtr = nextTokenIndex;
  }
  allocator = *(int *)(ctx + ARB_allocator);
  if (*(uint *)(ctx + ARB_tokenCapacity) <= nextTokenIndex) {
    newBuffer = (**(code **)(allocator + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
    if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
      _memcpy(newBuffer,*(int *)(ctx + ARB_tokenBuffer),*instrCountPtr << 2);
      (**(code **)(allocator + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
    }
    *(undefined4 *)(ctx + ARB_tokenBuffer) = newBuffer;
    nextTokenIndex = *instrCountPtr;
    *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
  }
  *(uint *)(nextTokenIndex * 4 + *(int *)(ctx + ARB_tokenBuffer)) = src1Token;
  nextTokenIndex = *instrCountPtr + 1;
  *instrCountPtr = nextTokenIndex;
  if ((src1Token & 0x400000) != 0) {
    allocator = *(int *)(ctx + ARB_allocator);
    if (*(uint *)(ctx + ARB_tokenCapacity) <= nextTokenIndex) {
      newBuffer = (**(code **)(allocator + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
      if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
        _memcpy(newBuffer,*(int *)(ctx + ARB_tokenBuffer),*instrCountPtr << 2);
        (**(code **)(allocator + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
      }
      *(undefined4 *)(ctx + ARB_tokenBuffer) = newBuffer;
      nextTokenIndex = *instrCountPtr;
      *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
    }
    *(uint *)(nextTokenIndex * 4 + *(int *)(ctx + ARB_tokenBuffer)) = uVar16;
    nextTokenIndex = *instrCountPtr + 1;
    *instrCountPtr = nextTokenIndex;
  }
  allocator = *(int *)(ctx + ARB_allocator);
  if (*(uint *)(ctx + ARB_tokenCapacity) <= nextTokenIndex) {
    newBuffer = (**(code **)(allocator + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
    if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
      _memcpy(newBuffer,*(int *)(ctx + ARB_tokenBuffer),*instrCountPtr << 2);
      (**(code **)(allocator + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
    }
    *(undefined4 *)(ctx + ARB_tokenBuffer) = newBuffer;
    nextTokenIndex = *instrCountPtr;
    *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
  }
  *(uint *)(nextTokenIndex * 4 + *(int *)(ctx + ARB_tokenBuffer)) = src2Token;
  nextTokenIndex = *instrCountPtr + 1;
  *instrCountPtr = nextTokenIndex;
  if ((src2Token & 0x400000) != 0) {
    allocator = *(int *)(ctx + ARB_allocator);
    if (*(uint *)(ctx + ARB_tokenCapacity) <= nextTokenIndex) {
      newBuffer = (**(code **)(allocator + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
      if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
        _memcpy(newBuffer,*(int *)(ctx + ARB_tokenBuffer),*instrCountPtr << 2);
        (**(code **)(allocator + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
      }
      *(undefined4 *)(ctx + ARB_tokenBuffer) = newBuffer;
      nextTokenIndex = *instrCountPtr;
      *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
    }
    *(uint *)(nextTokenIndex * 4 + *(int *)(ctx + ARB_tokenBuffer)) = uVar17;
    *instrCountPtr = *instrCountPtr + 1;
  }
  return;
}

/* arbEmitIlMulMaxMin2Src @ 0x69330 (4280 bytes) */
int arbEmitIlMulMaxMin2Src(ctx, dstFile, dstIndex, dstMask, src0File, src0Index, src0Words, src0Flags, src1File, src1Index, src1Words, src1Flags, src2File, src2Index, src2Words, src2Flags)
  int ctx;
  uint dstFile;
  uint dstIndex;
  int *dstMask;
  uint src0File;
  uint src0Index;
  uint *src0Words;
  uint *src0Flags;
  uint src1File;
  uint src1Index;
  uint *src1Words;
  uint *src1Flags;
  uint src2File;
  uint src2Index;
  uint *src2Words;
  uint *src2Flags;
{
  int dstMaskW;
  uint nextTokenIndex;
  uint dstToken;
  uint src2Flags2A;
  uint src1Flags2;
  uint src2Flags1A;
  uint src1Flags3;
  uint src2Flags1;
  uint src2WordsValue;
  uint src1Words1;
  uint src2Flags2;
  uint src2FlagsValueA;
  uint instrCountPtrValue;
  uint src1Words2;
  uint src0Words1;
  uint src2FlagsValue;
  uint src2Words3;
  uint src1Flags1;
  uint src2Flags3A;
  uint src1Words3;
  uint src2Flags3;
  uint src0Words2;
  uint src1Token;
  uint uVar2;
  int dstMaskZ;
  undefined4 newBuffer;
  uint tempRegIndex;
  uint src0Flags3;
  uint src0Flags2;
  uint src0Words3;
  int dstMaskY;
  uint src0Flags1;
  uint src0WordsValue;
  uint src1WordsValue;
  uint uVar13;
  uint src0Token;
  uint uVar15;
  uint uVar16;
  uint *instrCountPtr;
  int allocator;
  undefined1 auStack_88 [4];
  uint uStack_84;
  
  instrCountPtr = (uint *)(ctx + ARB_tokenCount);
  uVar15 = 0;
  uVar13 = 0;
  src0Token = (src0File & 0x3f) << 0x10 | src0Index & 0xffff;
  uVar16 = 0;
  (**(code **)(ctx + 0x748))(ctx,0,auStack_88,dstMask,src0File,src0Index,src0Words,src0Flags);
  tempRegIndex = uStack_84 & 0xffff;
  if (*src0Flags == 0) {
    src0Flags1 = src0Flags[1];
    if (src0Flags1 != 0) {
      src0Flags3 = src0Flags[3];
      src0Words3 = src0Words[3];
      src0Flags2 = src0Flags[2];
      src0WordsValue = *src0Words;
      src0Words1 = src0Words[1];
      src0Words2 = src0Words[2];
      goto LAB_000694c0;
    }
    src0Flags2 = src0Flags[2];
    if (src0Flags2 != 0) {
      src0Flags3 = src0Flags[3];
      src0Words3 = src0Words[3];
      src0WordsValue = *src0Words;
      src0Words1 = src0Words[1];
      src0Words2 = src0Words[2];
      goto LAB_000694c0;
    }
    src0Flags3 = src0Flags[3];
    if (src0Flags3 != 0) {
      src0Words3 = src0Words[3];
      src0WordsValue = *src0Words;
      src0Words1 = src0Words[1];
      src0Words2 = src0Words[2];
      goto LAB_000694c0;
    }
    src0WordsValue = *src0Words;
    if (src0WordsValue != 0) {
      src0Words3 = src0Words[3];
      src0Words1 = src0Words[1];
      src0Words2 = src0Words[2];
      goto LAB_000694c0;
    }
    src0Words1 = src0Words[1];
    if (src0Words1 != 1) {
      src0Words3 = src0Words[3];
      src0Words2 = src0Words[2];
      goto LAB_000694c0;
    }
    src0Words2 = src0Words[2];
    if (src0Words2 != 2) {
      src0Words3 = src0Words[3];
      goto LAB_000694c0;
    }
    src0Words3 = src0Words[3];
    if (src0Words3 != 3) goto LAB_000694c0;
  }
  else {
    src0Flags3 = src0Flags[3];
    src0Words3 = src0Words[3];
    src0Flags1 = src0Flags[1];
    src0Flags2 = src0Flags[2];
    src0WordsValue = *src0Words;
    src0Words1 = src0Words[1];
    src0Words2 = src0Words[2];
LAB_000694c0:
    src0Token = src0Token | 0x400000;
    uVar15 = (src0Flags3 & 1) << 0xf |
             (src0Words3 & 7) << 0xc |
             (src0Flags2 & 1) << 0xb |
             (src0Words2 & 7) << 8 |
             (src0Flags1 & 1) << 7 | (src0Words1 & 7) << 4 | (*src0Flags & 1) << 3 | src0WordsValue & 7;
  }
  src1Token = (src1File & 0x3f) << 0x10 | src1Index & 0xffff;
  if (*src1Flags == 0) {
    src1Flags1 = src1Flags[1];
    if (src1Flags1 != 0) {
      src1Flags3 = src1Flags[3];
      src1Words3 = src1Words[3];
      src1Flags2 = src1Flags[2];
      src1WordsValue = *src1Words;
      src1Words1 = src1Words[1];
      src1Words2 = src1Words[2];
      goto LAB_000695f0;
    }
    src1Flags2 = src1Flags[2];
    if (src1Flags2 != 0) {
      src1Flags3 = src1Flags[3];
      src1Words3 = src1Words[3];
      src1WordsValue = *src1Words;
      src1Words1 = src1Words[1];
      src1Words2 = src1Words[2];
      goto LAB_000695f0;
    }
    src1Flags3 = src1Flags[3];
    if (src1Flags3 != 0) {
      src1Words3 = src1Words[3];
      src1WordsValue = *src1Words;
      src1Words1 = src1Words[1];
      src1Words2 = src1Words[2];
      goto LAB_000695f0;
    }
    src1WordsValue = *src1Words;
    if (src1WordsValue != 0) {
      src1Words3 = src1Words[3];
      src1Words1 = src1Words[1];
      src1Words2 = src1Words[2];
      goto LAB_000695f0;
    }
    src1Words1 = src1Words[1];
    if (src1Words1 != 1) {
      src1Words3 = src1Words[3];
      src1Words2 = src1Words[2];
      goto LAB_000695f0;
    }
    src1Words2 = src1Words[2];
    if (src1Words2 != 2) {
      src1Words3 = src1Words[3];
      goto LAB_000695f0;
    }
    src1Words3 = src1Words[3];
    if (src1Words3 != 3) goto LAB_000695f0;
  }
  else {
    src1Flags3 = src1Flags[3];
    src1Words3 = src1Words[3];
    src1Flags1 = src1Flags[1];
    src1Flags2 = src1Flags[2];
    src1WordsValue = *src1Words;
    src1Words1 = src1Words[1];
    src1Words2 = src1Words[2];
LAB_000695f0:
    src1Token = src1Token | 0x400000;
    uVar16 = (src1Flags3 & 1) << 0xf |
             (src1Words3 & 7) << 0xc |
             (src1Flags2 & 1) << 0xb |
             (src1Words2 & 7) << 8 |
             (src1Flags1 & 1) << 7 | (src1Words1 & 7) << 4 | (*src1Flags & 1) << 3 | src1WordsValue & 7;
  }
  instrCountPtrValue = *instrCountPtr;
  allocator = *(int *)(ctx + ARB_allocator);
  if (*(uint *)(ctx + ARB_tokenCapacity) <= instrCountPtrValue) {
    newBuffer = (**(code **)(allocator + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
    if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
      _memcpy(newBuffer,*(int *)(ctx + ARB_tokenBuffer),*instrCountPtr << 2);
      (**(code **)(allocator + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
    }
    *(undefined4 *)(ctx + ARB_tokenBuffer) = newBuffer;
    instrCountPtrValue = *instrCountPtr;
    *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
  }
  *(undefined4 *)(instrCountPtrValue * 4 + *(int *)(ctx + ARB_tokenBuffer)) = 0x49;
  uVar2 = *instrCountPtr + 1;
  *instrCountPtr = uVar2;
  allocator = *(int *)(ctx + ARB_allocator);
  if (*(uint *)(ctx + ARB_tokenCapacity) <= uVar2) {
    newBuffer = (**(code **)(allocator + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
    if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
      _memcpy(newBuffer,*(int *)(ctx + ARB_tokenBuffer),*instrCountPtr << 2);
      (**(code **)(allocator + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
    }
    *(undefined4 *)(ctx + ARB_tokenBuffer) = newBuffer;
    uVar2 = *instrCountPtr;
    *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
  }
  *(uint *)(uVar2 * 4 + *(int *)(ctx + ARB_tokenBuffer)) = tempRegIndex | 0x40000;
  nextTokenIndex = *instrCountPtr + 1;
  *instrCountPtr = nextTokenIndex;
  allocator = *(int *)(ctx + ARB_allocator);
  if (*(uint *)(ctx + ARB_tokenCapacity) <= nextTokenIndex) {
    newBuffer = (**(code **)(allocator + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
    if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
      _memcpy(newBuffer,*(int *)(ctx + ARB_tokenBuffer),*instrCountPtr << 2);
      (**(code **)(allocator + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
    }
    *(undefined4 *)(ctx + ARB_tokenBuffer) = newBuffer;
    nextTokenIndex = *instrCountPtr;
    *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
  }
  *(uint *)(nextTokenIndex * 4 + *(int *)(ctx + ARB_tokenBuffer)) = src0Token;
  nextTokenIndex = *instrCountPtr + 1;
  *instrCountPtr = nextTokenIndex;
  if ((src0Token & 0x400000) != 0) {
    allocator = *(int *)(ctx + ARB_allocator);
    if (*(uint *)(ctx + ARB_tokenCapacity) <= nextTokenIndex) {
      newBuffer = (**(code **)(allocator + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
      if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
        _memcpy(newBuffer,*(int *)(ctx + ARB_tokenBuffer),*instrCountPtr << 2);
        (**(code **)(allocator + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
      }
      *(undefined4 *)(ctx + ARB_tokenBuffer) = newBuffer;
      nextTokenIndex = *instrCountPtr;
      *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
    }
    *(uint *)(nextTokenIndex * 4 + *(int *)(ctx + ARB_tokenBuffer)) = uVar15;
    nextTokenIndex = *instrCountPtr + 1;
    *instrCountPtr = nextTokenIndex;
  }
  allocator = *(int *)(ctx + ARB_allocator);
  if (*(uint *)(ctx + ARB_tokenCapacity) <= nextTokenIndex) {
    newBuffer = (**(code **)(allocator + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
    if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
      _memcpy(newBuffer,*(int *)(ctx + ARB_tokenBuffer),*instrCountPtr << 2);
      (**(code **)(allocator + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
    }
    *(undefined4 *)(ctx + ARB_tokenBuffer) = newBuffer;
    nextTokenIndex = *instrCountPtr;
    *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
  }
  *(uint *)(nextTokenIndex * 4 + *(int *)(ctx + ARB_tokenBuffer)) = src1Token;
  nextTokenIndex = *instrCountPtr + 1;
  *instrCountPtr = nextTokenIndex;
  if ((src1Token & 0x400000) != 0) {
    allocator = *(int *)(ctx + ARB_allocator);
    if (*(uint *)(ctx + ARB_tokenCapacity) <= nextTokenIndex) {
      newBuffer = (**(code **)(allocator + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
      if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
        _memcpy(newBuffer,*(int *)(ctx + ARB_tokenBuffer),*instrCountPtr << 2);
        (**(code **)(allocator + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
      }
      *(undefined4 *)(ctx + ARB_tokenBuffer) = newBuffer;
      nextTokenIndex = *instrCountPtr;
      *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
    }
    *(uint *)(nextTokenIndex * 4 + *(int *)(ctx + ARB_tokenBuffer)) = uVar16;
    nextTokenIndex = *instrCountPtr + 1;
    *instrCountPtr = nextTokenIndex;
  }
  src2WordsValue = *src2Words;
  src2FlagsValueA = *src2Flags;
  src2Flags1A = src2Flags[1];
  src2Flags2A = src2Flags[2];
  allocator = *(int *)(ctx + ARB_allocator);
  uVar15 = uStack_84 & 0xffff;
  uVar16 = uStack_84 & 0xffff;
  src2Flags3A = src2Flags[3];
  if (*(uint *)(ctx + ARB_tokenCapacity) <= nextTokenIndex) {
    newBuffer = (**(code **)(allocator + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
    if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
      _memcpy(newBuffer,*(int *)(ctx + ARB_tokenBuffer),*instrCountPtr << 2);
      (**(code **)(allocator + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
    }
    *(undefined4 *)(ctx + ARB_tokenBuffer) = newBuffer;
    nextTokenIndex = *instrCountPtr;
    *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
  }
  *(undefined4 *)(nextTokenIndex * 4 + *(int *)(ctx + ARB_tokenBuffer)) = 0x41;
  nextTokenIndex = *instrCountPtr + 1;
  *instrCountPtr = nextTokenIndex;
  allocator = *(int *)(ctx + ARB_allocator);
  if (*(uint *)(ctx + ARB_tokenCapacity) <= nextTokenIndex) {
    newBuffer = (**(code **)(allocator + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
    if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
      _memcpy(newBuffer,*(int *)(ctx + ARB_tokenBuffer),*instrCountPtr << 2);
      (**(code **)(allocator + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
    }
    *(undefined4 *)(ctx + ARB_tokenBuffer) = newBuffer;
    nextTokenIndex = *instrCountPtr;
    *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
  }
  *(uint *)(nextTokenIndex * 4 + *(int *)(ctx + ARB_tokenBuffer)) = uVar16 | 0x40000;
  nextTokenIndex = *instrCountPtr + 1;
  *instrCountPtr = nextTokenIndex;
  allocator = *(int *)(ctx + ARB_allocator);
  if (*(uint *)(ctx + ARB_tokenCapacity) <= nextTokenIndex) {
    newBuffer = (**(code **)(allocator + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
    if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
      _memcpy(newBuffer,*(int *)(ctx + ARB_tokenBuffer),*instrCountPtr << 2);
      (**(code **)(allocator + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
    }
    *(undefined4 *)(ctx + ARB_tokenBuffer) = newBuffer;
    nextTokenIndex = *instrCountPtr;
    *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
  }
  *(uint *)(nextTokenIndex * 4 + *(int *)(ctx + ARB_tokenBuffer)) = uVar15 | src0Token & 0xfe400000 | 0x440000;
  nextTokenIndex = *instrCountPtr + 1;
  *instrCountPtr = nextTokenIndex;
  allocator = *(int *)(ctx + ARB_allocator);
  if (*(uint *)(ctx + ARB_tokenCapacity) <= nextTokenIndex) {
    newBuffer = (**(code **)(allocator + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
    if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
      _memcpy(newBuffer,*(int *)(ctx + ARB_tokenBuffer),*instrCountPtr << 2);
      (**(code **)(allocator + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
    }
    *(undefined4 *)(ctx + ARB_tokenBuffer) = newBuffer;
    nextTokenIndex = *instrCountPtr;
    *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
  }
  *(undefined **)(nextTokenIndex * 4 + *(int *)(ctx + ARB_tokenBuffer)) = ((unsigned char *)0x00003333);
  nextTokenIndex = *instrCountPtr + 1;
  *instrCountPtr = nextTokenIndex;
  allocator = *(int *)(ctx + ARB_allocator);
  if (*(uint *)(ctx + ARB_tokenCapacity) <= nextTokenIndex) {
    newBuffer = (**(code **)(allocator + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
    if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
      _memcpy(newBuffer,*(int *)(ctx + ARB_tokenBuffer),*instrCountPtr << 2);
      (**(code **)(allocator + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
    }
    *(undefined4 *)(ctx + ARB_tokenBuffer) = newBuffer;
    nextTokenIndex = *instrCountPtr;
    *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
  }
  *(uint *)(nextTokenIndex * 4 + *(int *)(ctx + ARB_tokenBuffer)) =
       (src2File & 0x3f) << 0x10 | src2Index & 0xffff | src1Token & 0xfe400000 | 0x400000;
  nextTokenIndex = *instrCountPtr + 1;
  *instrCountPtr = nextTokenIndex;
  allocator = *(int *)(ctx + ARB_allocator);
  if (*(uint *)(ctx + ARB_tokenCapacity) <= nextTokenIndex) {
    newBuffer = (**(code **)(allocator + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
    if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
      _memcpy(newBuffer,*(int *)(ctx + ARB_tokenBuffer),*instrCountPtr << 2);
      (**(code **)(allocator + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
    }
    *(undefined4 *)(ctx + ARB_tokenBuffer) = newBuffer;
    nextTokenIndex = *instrCountPtr;
    *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
  }
  *(uint *)(nextTokenIndex * 4 + *(int *)(ctx + ARB_tokenBuffer)) =
       (src2Flags3A & 1) << 0xf |
       (src2WordsValue & 7) << 0xc |
       (src2Flags2A & 1) << 0xb |
       (src2WordsValue & 7) << 8 | (src2Flags1A & 1) << 7 | (src2WordsValue & 7) << 4 | (src2FlagsValueA & 1) << 3 | src2WordsValue & 7;
  nextTokenIndex = *instrCountPtr + 1;
  *instrCountPtr = nextTokenIndex;
  src2Words3 = src2Words[3];
  dstToken = (dstFile & 0x3f) << 0x10 | dstIndex & 0xffff;
  if ((dstFile == 0x12) || (dstFile == 0x13)) {
    dstToken = dstToken | 0x400000;
    uVar13 = 0x55;
  }
  if (*dstMask == 0) {
    dstMaskW = dstMask[3];
    dstMaskY = dstMask[1];
    dstMaskZ = dstMask[2];
  }
  else {
    dstMaskY = dstMask[1];
    if (dstMaskY == 0) {
      dstMaskW = dstMask[3];
      dstMaskZ = dstMask[2];
    }
    else {
      dstMaskZ = dstMask[2];
      if (dstMaskZ == 0) {
        dstMaskW = dstMask[3];
      }
      else {
        if (dstMask[3] != 0) goto LAB_00069f70;
        dstMaskW = 0;
      }
    }
  }
  dstToken = dstToken | 0x400000;
  uVar13 = (uint)(dstMaskW != 0) * 0x40 |
           (uint)(dstMaskZ != 0) * 0x10 | (uint)(dstMaskY != 0) * 4 | (uint)(*dstMask != 0);
LAB_00069f70:
  src2FlagsValue = *src2Flags;
  src2Flags1 = src2Flags[1];
  src2Flags2 = src2Flags[2];
  allocator = *(int *)(ctx + ARB_allocator);
  src2Flags3 = src2Flags[3];
  if (*(uint *)(ctx + ARB_tokenCapacity) <= nextTokenIndex) {
    newBuffer = (**(code **)(allocator + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
    if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
      _memcpy(newBuffer,*(int *)(ctx + ARB_tokenBuffer),*instrCountPtr << 2);
      (**(code **)(allocator + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
    }
    *(undefined4 *)(ctx + ARB_tokenBuffer) = newBuffer;
    nextTokenIndex = *instrCountPtr;
    *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
  }
  *(undefined4 *)(nextTokenIndex * 4 + *(int *)(ctx + ARB_tokenBuffer)) = 0x44;
  nextTokenIndex = *instrCountPtr + 1;
  *instrCountPtr = nextTokenIndex;
  allocator = *(int *)(ctx + ARB_allocator);
  if (*(uint *)(ctx + ARB_tokenCapacity) <= nextTokenIndex) {
    newBuffer = (**(code **)(allocator + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
    if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
      _memcpy(newBuffer,*(int *)(ctx + ARB_tokenBuffer),*instrCountPtr << 2);
      (**(code **)(allocator + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
    }
    *(undefined4 *)(ctx + ARB_tokenBuffer) = newBuffer;
    nextTokenIndex = *instrCountPtr;
    *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
  }
  *(uint *)(nextTokenIndex * 4 + *(int *)(ctx + ARB_tokenBuffer)) = dstToken;
  nextTokenIndex = *instrCountPtr + 1;
  *instrCountPtr = nextTokenIndex;
  if ((dstToken & 0x400000) != 0) {
    allocator = *(int *)(ctx + ARB_allocator);
    if (*(uint *)(ctx + ARB_tokenCapacity) <= nextTokenIndex) {
      newBuffer = (**(code **)(allocator + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
      if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
        _memcpy(newBuffer,*(int *)(ctx + ARB_tokenBuffer),*instrCountPtr << 2);
        (**(code **)(allocator + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
      }
      *(undefined4 *)(ctx + ARB_tokenBuffer) = newBuffer;
      nextTokenIndex = *instrCountPtr;
      *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
    }
    *(uint *)(nextTokenIndex * 4 + *(int *)(ctx + ARB_tokenBuffer)) = uVar13;
    nextTokenIndex = *instrCountPtr + 1;
    *instrCountPtr = nextTokenIndex;
  }
  allocator = *(int *)(ctx + ARB_allocator);
  if (*(uint *)(ctx + ARB_tokenCapacity) <= nextTokenIndex) {
    newBuffer = (**(code **)(allocator + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
    if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
      _memcpy(newBuffer,*(int *)(ctx + ARB_tokenBuffer),*instrCountPtr << 2);
      (**(code **)(allocator + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
    }
    *(undefined4 *)(ctx + ARB_tokenBuffer) = newBuffer;
    nextTokenIndex = *instrCountPtr;
    *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
  }
  *(uint *)(nextTokenIndex * 4 + *(int *)(ctx + ARB_tokenBuffer)) = uStack_84 & 0xffff | 0x440000;
  nextTokenIndex = *instrCountPtr + 1;
  *instrCountPtr = nextTokenIndex;
  allocator = *(int *)(ctx + ARB_allocator);
  if (*(uint *)(ctx + ARB_tokenCapacity) <= nextTokenIndex) {
    newBuffer = (**(code **)(allocator + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
    if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
      _memcpy(newBuffer,*(int *)(ctx + ARB_tokenBuffer),*instrCountPtr << 2);
      (**(code **)(allocator + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
    }
    *(undefined4 *)(ctx + ARB_tokenBuffer) = newBuffer;
    nextTokenIndex = *instrCountPtr;
    *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
  }
  *(undefined **)(nextTokenIndex * 4 + *(int *)(ctx + ARB_tokenBuffer)) = ((unsigned char *)0x00003333);
  nextTokenIndex = *instrCountPtr + 1;
  *instrCountPtr = nextTokenIndex;
  allocator = *(int *)(ctx + ARB_allocator);
  if (*(uint *)(ctx + ARB_tokenCapacity) <= nextTokenIndex) {
    newBuffer = (**(code **)(allocator + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
    if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
      _memcpy(newBuffer,*(int *)(ctx + ARB_tokenBuffer),*instrCountPtr << 2);
      (**(code **)(allocator + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
    }
    *(undefined4 *)(ctx + ARB_tokenBuffer) = newBuffer;
    nextTokenIndex = *instrCountPtr;
    *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
  }
  *(uint *)(nextTokenIndex * 4 + *(int *)(ctx + ARB_tokenBuffer)) =
       (src2File & 0x3f) << 0x10 | src2Index & 0xffff | 0x400000 | 0x400000;
  nextTokenIndex = *instrCountPtr + 1;
  *instrCountPtr = nextTokenIndex;
  allocator = *(int *)(ctx + ARB_allocator);
  if (*(uint *)(ctx + ARB_tokenCapacity) <= nextTokenIndex) {
    newBuffer = (**(code **)(allocator + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
    if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
      _memcpy(newBuffer,*(int *)(ctx + ARB_tokenBuffer),*instrCountPtr << 2);
      (**(code **)(allocator + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
    }
    *(undefined4 *)(ctx + ARB_tokenBuffer) = newBuffer;
    nextTokenIndex = *instrCountPtr;
    *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
  }
  *(uint *)(nextTokenIndex * 4 + *(int *)(ctx + ARB_tokenBuffer)) =
       (src2Flags3 & 1) << 0xf |
       (src2Words3 & 7) << 0xc |
       (src2Flags2 & 1) << 0xb |
       (src2Words3 & 7) << 8 | (src2Flags1 & 1) << 7 | (src2Words3 & 7) << 4 | (src2FlagsValue & 1) << 3 | src2Words3 & 7;
  *instrCountPtr = *instrCountPtr + 1;
  (**(code **)(ctx + 0x74c))(ctx,auStack_88);
  return;
}

/* arbEmitIlMin @ 0x6a400 (1912 bytes) */
int arbEmitIlMin(ctx, dstFile, dstIndex, dstMask, src0File, src0Index, src0Select, src0Negate, src1File, src1Index, src1Select, src1Negate)
  int ctx;
  uint dstFile;
  uint dstIndex;
  int *dstMask;
  uint src0File;
  uint src0Index;
  uint *src0Select;
  uint *src0Negate;
  uint src1File;
  uint src1Index;
  uint *src1Select;
  uint *src1Negate;
{
  uint src1Select3;
  uint src1Negate2;
  uint src1Negate3;
  uint src1Select1;
  uint src1Negate1;
  uint src1Header;
  int dstMask2;
  uint tokenIndex;
  undefined4 newStorage;
  uint src0Negate3;
  uint src0Negate2;
  uint src0Negate1;
  int dstMask1;
  uint src0Select3;
  uint src0SelectX;
  uint src1SelectX;
  uint src0Header;
  uint dstHeader;
  uint dstMaskWord;
  uint src1SwizzleWord;
  int iVar16;
  uint src0SwizzleWord;
  uint *tokenCount;
  
  dstHeader = (dstFile & 0x3f) << 0x10 | dstIndex & 0xffff;
  tokenCount = (uint *)(ctx + ARB_tokenCount);
  src1SwizzleWord = 0;
  src0SwizzleWord = 0;
  dstMaskWord = 0;
  if ((dstFile == 0x12) || (dstFile == 0x13)) {
    dstHeader = dstHeader | 0x400000;
    dstMaskWord = 0x55;
  }
  if (*dstMask == 0) {
    iVar16 = dstMask[3];
    dstMask1 = dstMask[1];
    dstMask2 = dstMask[2];
LAB_0006a4f0:
    dstHeader = dstHeader | 0x400000;
    dstMaskWord = (uint)(iVar16 != 0) * 0x40 |
             (uint)(dstMask2 != 0) * 0x10 | (uint)(dstMask1 != 0) * 4 | (uint)(*dstMask != 0);
  }
  else {
    dstMask1 = dstMask[1];
    if (dstMask1 == 0) {
      iVar16 = dstMask[3];
      dstMask2 = dstMask[2];
      goto LAB_0006a4f0;
    }
    dstMask2 = dstMask[2];
    if (dstMask2 == 0) {
      iVar16 = dstMask[3];
      goto LAB_0006a4f0;
    }
    if (dstMask[3] == 0) {
      iVar16 = 0;
      goto LAB_0006a4f0;
    }
  }
  src0Header = (src0File & 0x3f) << 0x10 | src0Index & 0xffff;
  if (*src0Negate == 0) {
    src0Negate1 = src0Negate[1];
    if (src0Negate1 != 0) {
      src0Negate3 = src0Negate[3];
      src0Select3 = src0Select[3];
      src0Negate2 = src0Negate[2];
      src0SelectX = *src0Select;
      tokenIndex = src0Select[1];
      src1Header = src0Select[2];
      goto LAB_0006a640;
    }
    src0Negate2 = src0Negate[2];
    if (src0Negate2 != 0) {
      src0Negate3 = src0Negate[3];
      src0Select3 = src0Select[3];
      src0SelectX = *src0Select;
      tokenIndex = src0Select[1];
      src1Header = src0Select[2];
      goto LAB_0006a640;
    }
    src0Negate3 = src0Negate[3];
    if (src0Negate3 != 0) {
      src0Select3 = src0Select[3];
      src0SelectX = *src0Select;
      tokenIndex = src0Select[1];
      src1Header = src0Select[2];
      goto LAB_0006a640;
    }
    src0SelectX = *src0Select;
    if (src0SelectX != 0) {
      src0Select3 = src0Select[3];
      tokenIndex = src0Select[1];
      src1Header = src0Select[2];
      goto LAB_0006a640;
    }
    tokenIndex = src0Select[1];
    if (tokenIndex != 1) {
      src0Select3 = src0Select[3];
      src1Header = src0Select[2];
      goto LAB_0006a640;
    }
    src1Header = src0Select[2];
    if (src1Header != 2) {
      src0Select3 = src0Select[3];
      goto LAB_0006a640;
    }
    src0Select3 = src0Select[3];
    if (src0Select3 != 3) goto LAB_0006a640;
  }
  else {
    src0Negate3 = src0Negate[3];
    src0Select3 = src0Select[3];
    src0Negate1 = src0Negate[1];
    src0Negate2 = src0Negate[2];
    src0SelectX = *src0Select;
    tokenIndex = src0Select[1];
    src1Header = src0Select[2];
LAB_0006a640:
    src0Header = src0Header | 0x400000;
    src0SwizzleWord = (src0Negate3 & 1) << 0xf |
             (src0Select3 & 7) << 0xc |
             (src0Negate2 & 1) << 0xb |
             (src1Header & 7) << 8 |
             (src0Negate1 & 1) << 7 | (tokenIndex & 7) << 4 | (*src0Negate & 1) << 3 | src0SelectX & 7;
  }
  src1Header = (src1File & 0x3f) << 0x10 | src1Index & 0xffff;
  if (*src1Negate == 0) {
    src1Negate1 = src1Negate[1];
    if (src1Negate1 == 0) {
      src1Negate2 = src1Negate[2];
      if (src1Negate2 == 0) {
        src1Negate3 = src1Negate[3];
        if (src1Negate3 == 0) {
          src1SelectX = *src1Select;
          if (src1SelectX == 0) {
            src1Select1 = src1Select[1];
            if (src1Select1 == 1) {
              tokenIndex = src1Select[2];
              if (tokenIndex == 2) {
                src1Select3 = src1Select[3];
                if (src1Select3 == 3) goto LAB_0006a794;
              }
              else {
                src1Select3 = src1Select[3];
              }
            }
            else {
              src1Select3 = src1Select[3];
              tokenIndex = src1Select[2];
            }
          }
          else {
            src1Select3 = src1Select[3];
            src1Select1 = src1Select[1];
            tokenIndex = src1Select[2];
          }
        }
        else {
          src1Select3 = src1Select[3];
          src1SelectX = *src1Select;
          src1Select1 = src1Select[1];
          tokenIndex = src1Select[2];
        }
      }
      else {
        src1Negate3 = src1Negate[3];
        src1Select3 = src1Select[3];
        src1SelectX = *src1Select;
        src1Select1 = src1Select[1];
        tokenIndex = src1Select[2];
      }
    }
    else {
      src1Negate3 = src1Negate[3];
      src1Select3 = src1Select[3];
      src1Negate2 = src1Negate[2];
      src1SelectX = *src1Select;
      src1Select1 = src1Select[1];
      tokenIndex = src1Select[2];
    }
  }
  else {
    src1Negate3 = src1Negate[3];
    src1Select3 = src1Select[3];
    src1Negate1 = src1Negate[1];
    src1Negate2 = src1Negate[2];
    src1SelectX = *src1Select;
    src1Select1 = src1Select[1];
    tokenIndex = src1Select[2];
  }
  src1Header = src1Header | 0x400000;
  src1SwizzleWord = (src1Negate3 & 1) << 0xf |
           (src1Select3 & 7) << 0xc |
           (src1Negate2 & 1) << 0xb |
           (tokenIndex & 7) << 8 |
           (src1Negate1 & 1) << 7 | (src1Select1 & 7) << 4 | (*src1Negate & 1) << 3 | src1SelectX & 7;
LAB_0006a794:
  tokenIndex = *tokenCount;
  iVar16 = *(int *)(ctx + ARB_allocator);
  if (*(uint *)(ctx + ARB_tokenCapacity) <= tokenIndex) {
    newStorage = (**(code **)(iVar16 + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
    if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
      _memcpy(newStorage,*(int *)(ctx + ARB_tokenBuffer),*tokenCount << 2);
      (**(code **)(iVar16 + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
    }
    *(undefined4 *)(ctx + ARB_tokenBuffer) = newStorage;
    tokenIndex = *tokenCount;
    *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
  }
  *(undefined4 *)(tokenIndex * 4 + *(int *)(ctx + ARB_tokenBuffer)) = 0x44;
  tokenIndex = *tokenCount + 1;
  *tokenCount = tokenIndex;
  iVar16 = *(int *)(ctx + ARB_allocator);
  if (*(uint *)(ctx + ARB_tokenCapacity) <= tokenIndex) {
    newStorage = (**(code **)(iVar16 + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
    if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
      _memcpy(newStorage,*(int *)(ctx + ARB_tokenBuffer),*tokenCount << 2);
      (**(code **)(iVar16 + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
    }
    *(undefined4 *)(ctx + ARB_tokenBuffer) = newStorage;
    tokenIndex = *tokenCount;
    *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
  }
  *(uint *)(tokenIndex * 4 + *(int *)(ctx + ARB_tokenBuffer)) = dstHeader;
  tokenIndex = *tokenCount + 1;
  *tokenCount = tokenIndex;
  if ((dstHeader & 0x400000) != 0) {
    iVar16 = *(int *)(ctx + ARB_allocator);
    if (*(uint *)(ctx + ARB_tokenCapacity) <= tokenIndex) {
      newStorage = (**(code **)(iVar16 + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
      if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
        _memcpy(newStorage,*(int *)(ctx + ARB_tokenBuffer),*tokenCount << 2);
        (**(code **)(iVar16 + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
      }
      *(undefined4 *)(ctx + ARB_tokenBuffer) = newStorage;
      tokenIndex = *tokenCount;
      *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
    }
    *(uint *)(tokenIndex * 4 + *(int *)(ctx + ARB_tokenBuffer)) = dstMaskWord;
    tokenIndex = *tokenCount + 1;
    *tokenCount = tokenIndex;
  }
  iVar16 = *(int *)(ctx + ARB_allocator);
  if (*(uint *)(ctx + ARB_tokenCapacity) <= tokenIndex) {
    newStorage = (**(code **)(iVar16 + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
    if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
      _memcpy(newStorage,*(int *)(ctx + ARB_tokenBuffer),*tokenCount << 2);
      (**(code **)(iVar16 + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
    }
    *(undefined4 *)(ctx + ARB_tokenBuffer) = newStorage;
    tokenIndex = *tokenCount;
    *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
  }
  *(uint *)(tokenIndex * 4 + *(int *)(ctx + ARB_tokenBuffer)) = src0Header;
  dstHeader = *tokenCount + 1;
  *tokenCount = dstHeader;
  if ((src0Header & 0x400000) != 0) {
    iVar16 = *(int *)(ctx + ARB_allocator);
    if (*(uint *)(ctx + ARB_tokenCapacity) <= dstHeader) {
      newStorage = (**(code **)(iVar16 + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
      if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
        _memcpy(newStorage,*(int *)(ctx + ARB_tokenBuffer),*tokenCount << 2);
        (**(code **)(iVar16 + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
      }
      *(undefined4 *)(ctx + ARB_tokenBuffer) = newStorage;
      dstHeader = *tokenCount;
      *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
    }
    *(uint *)(dstHeader * 4 + *(int *)(ctx + ARB_tokenBuffer)) = src0SwizzleWord;
    dstHeader = *tokenCount + 1;
    *tokenCount = dstHeader;
  }
  iVar16 = *(int *)(ctx + ARB_allocator);
  if (*(uint *)(ctx + ARB_tokenCapacity) <= dstHeader) {
    newStorage = (**(code **)(iVar16 + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
    if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
      _memcpy(newStorage,*(int *)(ctx + ARB_tokenBuffer),*tokenCount << 2);
      (**(code **)(iVar16 + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
    }
    *(undefined4 *)(ctx + ARB_tokenBuffer) = newStorage;
    dstHeader = *tokenCount;
    *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
  }
  *(uint *)(dstHeader * 4 + *(int *)(ctx + ARB_tokenBuffer)) = src1Header;
  dstHeader = *tokenCount + 1;
  *tokenCount = dstHeader;
  if ((src1Header & 0x400000) != 0) {
    iVar16 = *(int *)(ctx + ARB_allocator);
    if (*(uint *)(ctx + ARB_tokenCapacity) <= dstHeader) {
      newStorage = (**(code **)(iVar16 + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
      if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
        _memcpy(newStorage,*(int *)(ctx + ARB_tokenBuffer),*tokenCount << 2);
        (**(code **)(iVar16 + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
      }
      *(undefined4 *)(ctx + ARB_tokenBuffer) = newStorage;
      dstHeader = *tokenCount;
      *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
    }
    *(uint *)(dstHeader * 4 + *(int *)(ctx + ARB_tokenBuffer)) = src1SwizzleWord;
    *tokenCount = *tokenCount + 1;
  }
  return;
}

/* arbEmitIlMax @ 0x6aba0 (1912 bytes) */
int arbEmitIlMax(ctx, dstFile, dstIndex, dstMask, src0File, src0Index, src0Select, src0Negate, src1File, src1Index, src1Select, src1Negate)
  int ctx;
  uint dstFile;
  uint dstIndex;
  int *dstMask;
  uint src0File;
  uint src0Index;
  uint *src0Select;
  uint *src0Negate;
  uint src1File;
  uint src1Index;
  uint *src1Select;
  uint *src1Negate;
{
  uint src1Select3;
  uint src1Negate2;
  uint src1Negate3;
  uint src1Select1;
  uint src1Negate1;
  uint src1Header;
  int dstMask2;
  uint tokenIndex;
  undefined4 newStorage;
  uint src0Negate3;
  uint src0Negate2;
  uint src0Negate1;
  int dstMask1;
  uint src0Select3;
  uint src0SelectX;
  uint src1SelectX;
  uint src0Header;
  uint dstHeader;
  uint dstMaskWord;
  uint src1SwizzleWord;
  int iVar16;
  uint src0SwizzleWord;
  uint *tokenCount;
  
  dstHeader = (dstFile & 0x3f) << 0x10 | dstIndex & 0xffff;
  tokenCount = (uint *)(ctx + ARB_tokenCount);
  src1SwizzleWord = 0;
  src0SwizzleWord = 0;
  dstMaskWord = 0;
  if ((dstFile == 0x12) || (dstFile == 0x13)) {
    dstHeader = dstHeader | 0x400000;
    dstMaskWord = 0x55;
  }
  if (*dstMask == 0) {
    iVar16 = dstMask[3];
    dstMask1 = dstMask[1];
    dstMask2 = dstMask[2];
LAB_0006ac90:
    dstHeader = dstHeader | 0x400000;
    dstMaskWord = (uint)(iVar16 != 0) * 0x40 |
             (uint)(dstMask2 != 0) * 0x10 | (uint)(dstMask1 != 0) * 4 | (uint)(*dstMask != 0);
  }
  else {
    dstMask1 = dstMask[1];
    if (dstMask1 == 0) {
      iVar16 = dstMask[3];
      dstMask2 = dstMask[2];
      goto LAB_0006ac90;
    }
    dstMask2 = dstMask[2];
    if (dstMask2 == 0) {
      iVar16 = dstMask[3];
      goto LAB_0006ac90;
    }
    if (dstMask[3] == 0) {
      iVar16 = 0;
      goto LAB_0006ac90;
    }
  }
  src0Header = (src0File & 0x3f) << 0x10 | src0Index & 0xffff;
  if (*src0Negate == 0) {
    src0Negate1 = src0Negate[1];
    if (src0Negate1 != 0) {
      src0Negate3 = src0Negate[3];
      src0Select3 = src0Select[3];
      src0Negate2 = src0Negate[2];
      src0SelectX = *src0Select;
      tokenIndex = src0Select[1];
      src1Header = src0Select[2];
      goto LAB_0006ade0;
    }
    src0Negate2 = src0Negate[2];
    if (src0Negate2 != 0) {
      src0Negate3 = src0Negate[3];
      src0Select3 = src0Select[3];
      src0SelectX = *src0Select;
      tokenIndex = src0Select[1];
      src1Header = src0Select[2];
      goto LAB_0006ade0;
    }
    src0Negate3 = src0Negate[3];
    if (src0Negate3 != 0) {
      src0Select3 = src0Select[3];
      src0SelectX = *src0Select;
      tokenIndex = src0Select[1];
      src1Header = src0Select[2];
      goto LAB_0006ade0;
    }
    src0SelectX = *src0Select;
    if (src0SelectX != 0) {
      src0Select3 = src0Select[3];
      tokenIndex = src0Select[1];
      src1Header = src0Select[2];
      goto LAB_0006ade0;
    }
    tokenIndex = src0Select[1];
    if (tokenIndex != 1) {
      src0Select3 = src0Select[3];
      src1Header = src0Select[2];
      goto LAB_0006ade0;
    }
    src1Header = src0Select[2];
    if (src1Header != 2) {
      src0Select3 = src0Select[3];
      goto LAB_0006ade0;
    }
    src0Select3 = src0Select[3];
    if (src0Select3 != 3) goto LAB_0006ade0;
  }
  else {
    src0Negate3 = src0Negate[3];
    src0Select3 = src0Select[3];
    src0Negate1 = src0Negate[1];
    src0Negate2 = src0Negate[2];
    src0SelectX = *src0Select;
    tokenIndex = src0Select[1];
    src1Header = src0Select[2];
LAB_0006ade0:
    src0Header = src0Header | 0x400000;
    src0SwizzleWord = (src0Negate3 & 1) << 0xf |
             (src0Select3 & 7) << 0xc |
             (src0Negate2 & 1) << 0xb |
             (src1Header & 7) << 8 |
             (src0Negate1 & 1) << 7 | (tokenIndex & 7) << 4 | (*src0Negate & 1) << 3 | src0SelectX & 7;
  }
  src1Header = (src1File & 0x3f) << 0x10 | src1Index & 0xffff;
  if (*src1Negate == 0) {
    src1Negate1 = src1Negate[1];
    if (src1Negate1 == 0) {
      src1Negate2 = src1Negate[2];
      if (src1Negate2 == 0) {
        src1Negate3 = src1Negate[3];
        if (src1Negate3 == 0) {
          src1SelectX = *src1Select;
          if (src1SelectX == 0) {
            src1Select1 = src1Select[1];
            if (src1Select1 == 1) {
              tokenIndex = src1Select[2];
              if (tokenIndex == 2) {
                src1Select3 = src1Select[3];
                if (src1Select3 == 3) goto LAB_0006af34;
              }
              else {
                src1Select3 = src1Select[3];
              }
            }
            else {
              src1Select3 = src1Select[3];
              tokenIndex = src1Select[2];
            }
          }
          else {
            src1Select3 = src1Select[3];
            src1Select1 = src1Select[1];
            tokenIndex = src1Select[2];
          }
        }
        else {
          src1Select3 = src1Select[3];
          src1SelectX = *src1Select;
          src1Select1 = src1Select[1];
          tokenIndex = src1Select[2];
        }
      }
      else {
        src1Negate3 = src1Negate[3];
        src1Select3 = src1Select[3];
        src1SelectX = *src1Select;
        src1Select1 = src1Select[1];
        tokenIndex = src1Select[2];
      }
    }
    else {
      src1Negate3 = src1Negate[3];
      src1Select3 = src1Select[3];
      src1Negate2 = src1Negate[2];
      src1SelectX = *src1Select;
      src1Select1 = src1Select[1];
      tokenIndex = src1Select[2];
    }
  }
  else {
    src1Negate3 = src1Negate[3];
    src1Select3 = src1Select[3];
    src1Negate1 = src1Negate[1];
    src1Negate2 = src1Negate[2];
    src1SelectX = *src1Select;
    src1Select1 = src1Select[1];
    tokenIndex = src1Select[2];
  }
  src1Header = src1Header | 0x400000;
  src1SwizzleWord = (src1Negate3 & 1) << 0xf |
           (src1Select3 & 7) << 0xc |
           (src1Negate2 & 1) << 0xb |
           (tokenIndex & 7) << 8 |
           (src1Negate1 & 1) << 7 | (src1Select1 & 7) << 4 | (*src1Negate & 1) << 3 | src1SelectX & 7;
LAB_0006af34:
  tokenIndex = *tokenCount;
  iVar16 = *(int *)(ctx + ARB_allocator);
  if (*(uint *)(ctx + ARB_tokenCapacity) <= tokenIndex) {
    newStorage = (**(code **)(iVar16 + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
    if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
      _memcpy(newStorage,*(int *)(ctx + ARB_tokenBuffer),*tokenCount << 2);
      (**(code **)(iVar16 + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
    }
    *(undefined4 *)(ctx + ARB_tokenBuffer) = newStorage;
    tokenIndex = *tokenCount;
    *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
  }
  *(undefined4 *)(tokenIndex * 4 + *(int *)(ctx + ARB_tokenBuffer)) = 0x41;
  tokenIndex = *tokenCount + 1;
  *tokenCount = tokenIndex;
  iVar16 = *(int *)(ctx + ARB_allocator);
  if (*(uint *)(ctx + ARB_tokenCapacity) <= tokenIndex) {
    newStorage = (**(code **)(iVar16 + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
    if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
      _memcpy(newStorage,*(int *)(ctx + ARB_tokenBuffer),*tokenCount << 2);
      (**(code **)(iVar16 + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
    }
    *(undefined4 *)(ctx + ARB_tokenBuffer) = newStorage;
    tokenIndex = *tokenCount;
    *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
  }
  *(uint *)(tokenIndex * 4 + *(int *)(ctx + ARB_tokenBuffer)) = dstHeader;
  tokenIndex = *tokenCount + 1;
  *tokenCount = tokenIndex;
  if ((dstHeader & 0x400000) != 0) {
    iVar16 = *(int *)(ctx + ARB_allocator);
    if (*(uint *)(ctx + ARB_tokenCapacity) <= tokenIndex) {
      newStorage = (**(code **)(iVar16 + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
      if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
        _memcpy(newStorage,*(int *)(ctx + ARB_tokenBuffer),*tokenCount << 2);
        (**(code **)(iVar16 + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
      }
      *(undefined4 *)(ctx + ARB_tokenBuffer) = newStorage;
      tokenIndex = *tokenCount;
      *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
    }
    *(uint *)(tokenIndex * 4 + *(int *)(ctx + ARB_tokenBuffer)) = dstMaskWord;
    tokenIndex = *tokenCount + 1;
    *tokenCount = tokenIndex;
  }
  iVar16 = *(int *)(ctx + ARB_allocator);
  if (*(uint *)(ctx + ARB_tokenCapacity) <= tokenIndex) {
    newStorage = (**(code **)(iVar16 + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
    if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
      _memcpy(newStorage,*(int *)(ctx + ARB_tokenBuffer),*tokenCount << 2);
      (**(code **)(iVar16 + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
    }
    *(undefined4 *)(ctx + ARB_tokenBuffer) = newStorage;
    tokenIndex = *tokenCount;
    *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
  }
  *(uint *)(tokenIndex * 4 + *(int *)(ctx + ARB_tokenBuffer)) = src0Header;
  dstHeader = *tokenCount + 1;
  *tokenCount = dstHeader;
  if ((src0Header & 0x400000) != 0) {
    iVar16 = *(int *)(ctx + ARB_allocator);
    if (*(uint *)(ctx + ARB_tokenCapacity) <= dstHeader) {
      newStorage = (**(code **)(iVar16 + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
      if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
        _memcpy(newStorage,*(int *)(ctx + ARB_tokenBuffer),*tokenCount << 2);
        (**(code **)(iVar16 + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
      }
      *(undefined4 *)(ctx + ARB_tokenBuffer) = newStorage;
      dstHeader = *tokenCount;
      *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
    }
    *(uint *)(dstHeader * 4 + *(int *)(ctx + ARB_tokenBuffer)) = src0SwizzleWord;
    dstHeader = *tokenCount + 1;
    *tokenCount = dstHeader;
  }
  iVar16 = *(int *)(ctx + ARB_allocator);
  if (*(uint *)(ctx + ARB_tokenCapacity) <= dstHeader) {
    newStorage = (**(code **)(iVar16 + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
    if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
      _memcpy(newStorage,*(int *)(ctx + ARB_tokenBuffer),*tokenCount << 2);
      (**(code **)(iVar16 + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
    }
    *(undefined4 *)(ctx + ARB_tokenBuffer) = newStorage;
    dstHeader = *tokenCount;
    *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
  }
  *(uint *)(dstHeader * 4 + *(int *)(ctx + ARB_tokenBuffer)) = src1Header;
  dstHeader = *tokenCount + 1;
  *tokenCount = dstHeader;
  if ((src1Header & 0x400000) != 0) {
    iVar16 = *(int *)(ctx + ARB_allocator);
    if (*(uint *)(ctx + ARB_tokenCapacity) <= dstHeader) {
      newStorage = (**(code **)(iVar16 + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
      if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
        _memcpy(newStorage,*(int *)(ctx + ARB_tokenBuffer),*tokenCount << 2);
        (**(code **)(iVar16 + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
      }
      *(undefined4 *)(ctx + ARB_tokenBuffer) = newStorage;
      dstHeader = *tokenCount;
      *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
    }
    *(uint *)(dstHeader * 4 + *(int *)(ctx + ARB_tokenBuffer)) = src1SwizzleWord;
    *tokenCount = *tokenCount + 1;
  }
  return;
}

/* arbEmitIlSetCompare5 @ 0x6b340 (1920 bytes) */
int arbEmitIlSetCompare5(ctx, dstFile, dstIndex, dstMask, src0File, src0Index, src0Select, src0Negate, src1File, src1Index, src1Select, src1Negate)
  int ctx;
  uint dstFile;
  uint dstIndex;
  int *dstMask;
  uint src0File;
  uint src0Index;
  uint *src0Select;
  uint *src0Negate;
  uint src1File;
  uint src1Index;
  uint *src1Select;
  uint *src1Negate;
{
  uint src1Select3;
  uint src1Negate2;
  uint src1Negate3;
  uint src1Select1;
  uint src1Negate1;
  uint src1Header;
  int dstMask2;
  uint tokenIndex;
  undefined4 newStorage;
  uint src0Negate3;
  uint src0Negate2;
  uint src0Negate1;
  int dstMask1;
  uint src0Select3;
  uint src0SelectX;
  uint src1SelectX;
  uint src0Header;
  uint dstHeader;
  uint dstMaskWord;
  uint src1SwizzleWord;
  int iVar16;
  uint src0SwizzleWord;
  uint *tokenCount;
  
  dstHeader = (dstFile & 0x3f) << 0x10 | dstIndex & 0xffff;
  tokenCount = (uint *)(ctx + ARB_tokenCount);
  src1SwizzleWord = 0;
  src0SwizzleWord = 0;
  dstMaskWord = 0;
  if ((dstFile == 0x12) || (dstFile == 0x13)) {
    dstHeader = dstHeader | 0x400000;
    dstMaskWord = 0x55;
  }
  if (*dstMask == 0) {
    iVar16 = dstMask[3];
    dstMask1 = dstMask[1];
    dstMask2 = dstMask[2];
LAB_0006b430:
    dstHeader = dstHeader | 0x400000;
    dstMaskWord = (uint)(iVar16 != 0) * 0x40 |
             (uint)(dstMask2 != 0) * 0x10 | (uint)(dstMask1 != 0) * 4 | (uint)(*dstMask != 0);
  }
  else {
    dstMask1 = dstMask[1];
    if (dstMask1 == 0) {
      iVar16 = dstMask[3];
      dstMask2 = dstMask[2];
      goto LAB_0006b430;
    }
    dstMask2 = dstMask[2];
    if (dstMask2 == 0) {
      iVar16 = dstMask[3];
      goto LAB_0006b430;
    }
    if (dstMask[3] == 0) {
      iVar16 = 0;
      goto LAB_0006b430;
    }
  }
  src0Header = (src0File & 0x3f) << 0x10 | src0Index & 0xffff;
  if (*src0Negate == 0) {
    src0Negate1 = src0Negate[1];
    if (src0Negate1 != 0) {
      src0Negate3 = src0Negate[3];
      src0Select3 = src0Select[3];
      src0Negate2 = src0Negate[2];
      src0SelectX = *src0Select;
      tokenIndex = src0Select[1];
      src1Header = src0Select[2];
      goto LAB_0006b580;
    }
    src0Negate2 = src0Negate[2];
    if (src0Negate2 != 0) {
      src0Negate3 = src0Negate[3];
      src0Select3 = src0Select[3];
      src0SelectX = *src0Select;
      tokenIndex = src0Select[1];
      src1Header = src0Select[2];
      goto LAB_0006b580;
    }
    src0Negate3 = src0Negate[3];
    if (src0Negate3 != 0) {
      src0Select3 = src0Select[3];
      src0SelectX = *src0Select;
      tokenIndex = src0Select[1];
      src1Header = src0Select[2];
      goto LAB_0006b580;
    }
    src0SelectX = *src0Select;
    if (src0SelectX != 0) {
      src0Select3 = src0Select[3];
      tokenIndex = src0Select[1];
      src1Header = src0Select[2];
      goto LAB_0006b580;
    }
    tokenIndex = src0Select[1];
    if (tokenIndex != 1) {
      src0Select3 = src0Select[3];
      src1Header = src0Select[2];
      goto LAB_0006b580;
    }
    src1Header = src0Select[2];
    if (src1Header != 2) {
      src0Select3 = src0Select[3];
      goto LAB_0006b580;
    }
    src0Select3 = src0Select[3];
    if (src0Select3 != 3) goto LAB_0006b580;
  }
  else {
    src0Negate3 = src0Negate[3];
    src0Select3 = src0Select[3];
    src0Negate1 = src0Negate[1];
    src0Negate2 = src0Negate[2];
    src0SelectX = *src0Select;
    tokenIndex = src0Select[1];
    src1Header = src0Select[2];
LAB_0006b580:
    src0Header = src0Header | 0x400000;
    src0SwizzleWord = (src0Negate3 & 1) << 0xf |
             (src0Select3 & 7) << 0xc |
             (src0Negate2 & 1) << 0xb |
             (src1Header & 7) << 8 |
             (src0Negate1 & 1) << 7 | (tokenIndex & 7) << 4 | (*src0Negate & 1) << 3 | src0SelectX & 7;
  }
  src1Header = (src1File & 0x3f) << 0x10 | src1Index & 0xffff;
  if (*src1Negate == 0) {
    src1Negate1 = src1Negate[1];
    if (src1Negate1 == 0) {
      src1Negate2 = src1Negate[2];
      if (src1Negate2 == 0) {
        src1Negate3 = src1Negate[3];
        if (src1Negate3 == 0) {
          src1SelectX = *src1Select;
          if (src1SelectX == 0) {
            src1Select1 = src1Select[1];
            if (src1Select1 == 1) {
              tokenIndex = src1Select[2];
              if (tokenIndex == 2) {
                src1Select3 = src1Select[3];
                if (src1Select3 == 3) goto LAB_0006b6d4;
              }
              else {
                src1Select3 = src1Select[3];
              }
            }
            else {
              src1Select3 = src1Select[3];
              tokenIndex = src1Select[2];
            }
          }
          else {
            src1Select3 = src1Select[3];
            src1Select1 = src1Select[1];
            tokenIndex = src1Select[2];
          }
        }
        else {
          src1Select3 = src1Select[3];
          src1SelectX = *src1Select;
          src1Select1 = src1Select[1];
          tokenIndex = src1Select[2];
        }
      }
      else {
        src1Negate3 = src1Negate[3];
        src1Select3 = src1Select[3];
        src1SelectX = *src1Select;
        src1Select1 = src1Select[1];
        tokenIndex = src1Select[2];
      }
    }
    else {
      src1Negate3 = src1Negate[3];
      src1Select3 = src1Select[3];
      src1Negate2 = src1Negate[2];
      src1SelectX = *src1Select;
      src1Select1 = src1Select[1];
      tokenIndex = src1Select[2];
    }
  }
  else {
    src1Negate3 = src1Negate[3];
    src1Select3 = src1Select[3];
    src1Negate1 = src1Negate[1];
    src1Negate2 = src1Negate[2];
    src1SelectX = *src1Select;
    src1Select1 = src1Select[1];
    tokenIndex = src1Select[2];
  }
  src1Header = src1Header | 0x400000;
  src1SwizzleWord = (src1Negate3 & 1) << 0xf |
           (src1Select3 & 7) << 0xc |
           (src1Negate2 & 1) << 0xb |
           (tokenIndex & 7) << 8 |
           (src1Negate1 & 1) << 7 | (src1Select1 & 7) << 4 | (*src1Negate & 1) << 3 | src1SelectX & 7;
LAB_0006b6d4:
  tokenIndex = *tokenCount;
  iVar16 = *(int *)(ctx + ARB_allocator);
  if (*(uint *)(ctx + ARB_tokenCapacity) <= tokenIndex) {
    newStorage = (**(code **)(iVar16 + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
    if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
      _memcpy(newStorage,*(int *)(ctx + ARB_tokenBuffer),*tokenCount << 2);
      (**(code **)(iVar16 + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
    }
    *(undefined4 *)(ctx + ARB_tokenBuffer) = newStorage;
    tokenIndex = *tokenCount;
    *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
  }
  *(undefined4 *)(tokenIndex * 4 + *(int *)(ctx + ARB_tokenBuffer)) = 0x50056;
  tokenIndex = *tokenCount + 1;
  *tokenCount = tokenIndex;
  iVar16 = *(int *)(ctx + ARB_allocator);
  if (*(uint *)(ctx + ARB_tokenCapacity) <= tokenIndex) {
    newStorage = (**(code **)(iVar16 + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
    if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
      _memcpy(newStorage,*(int *)(ctx + ARB_tokenBuffer),*tokenCount << 2);
      (**(code **)(iVar16 + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
    }
    *(undefined4 *)(ctx + ARB_tokenBuffer) = newStorage;
    tokenIndex = *tokenCount;
    *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
  }
  *(uint *)(tokenIndex * 4 + *(int *)(ctx + ARB_tokenBuffer)) = dstHeader;
  tokenIndex = *tokenCount + 1;
  *tokenCount = tokenIndex;
  if ((dstHeader & 0x400000) != 0) {
    iVar16 = *(int *)(ctx + ARB_allocator);
    if (*(uint *)(ctx + ARB_tokenCapacity) <= tokenIndex) {
      newStorage = (**(code **)(iVar16 + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
      if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
        _memcpy(newStorage,*(int *)(ctx + ARB_tokenBuffer),*tokenCount << 2);
        (**(code **)(iVar16 + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
      }
      *(undefined4 *)(ctx + ARB_tokenBuffer) = newStorage;
      tokenIndex = *tokenCount;
      *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
    }
    *(uint *)(tokenIndex * 4 + *(int *)(ctx + ARB_tokenBuffer)) = dstMaskWord;
    tokenIndex = *tokenCount + 1;
    *tokenCount = tokenIndex;
  }
  iVar16 = *(int *)(ctx + ARB_allocator);
  if (*(uint *)(ctx + ARB_tokenCapacity) <= tokenIndex) {
    newStorage = (**(code **)(iVar16 + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
    if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
      _memcpy(newStorage,*(int *)(ctx + ARB_tokenBuffer),*tokenCount << 2);
      (**(code **)(iVar16 + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
    }
    *(undefined4 *)(ctx + ARB_tokenBuffer) = newStorage;
    tokenIndex = *tokenCount;
    *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
  }
  *(uint *)(tokenIndex * 4 + *(int *)(ctx + ARB_tokenBuffer)) = src0Header;
  dstHeader = *tokenCount + 1;
  *tokenCount = dstHeader;
  if ((src0Header & 0x400000) != 0) {
    iVar16 = *(int *)(ctx + ARB_allocator);
    if (*(uint *)(ctx + ARB_tokenCapacity) <= dstHeader) {
      newStorage = (**(code **)(iVar16 + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
      if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
        _memcpy(newStorage,*(int *)(ctx + ARB_tokenBuffer),*tokenCount << 2);
        (**(code **)(iVar16 + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
      }
      *(undefined4 *)(ctx + ARB_tokenBuffer) = newStorage;
      dstHeader = *tokenCount;
      *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
    }
    *(uint *)(dstHeader * 4 + *(int *)(ctx + ARB_tokenBuffer)) = src0SwizzleWord;
    dstHeader = *tokenCount + 1;
    *tokenCount = dstHeader;
  }
  iVar16 = *(int *)(ctx + ARB_allocator);
  if (*(uint *)(ctx + ARB_tokenCapacity) <= dstHeader) {
    newStorage = (**(code **)(iVar16 + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
    if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
      _memcpy(newStorage,*(int *)(ctx + ARB_tokenBuffer),*tokenCount << 2);
      (**(code **)(iVar16 + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
    }
    *(undefined4 *)(ctx + ARB_tokenBuffer) = newStorage;
    dstHeader = *tokenCount;
    *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
  }
  *(uint *)(dstHeader * 4 + *(int *)(ctx + ARB_tokenBuffer)) = src1Header;
  dstHeader = *tokenCount + 1;
  *tokenCount = dstHeader;
  if ((src1Header & 0x400000) != 0) {
    iVar16 = *(int *)(ctx + ARB_allocator);
    if (*(uint *)(ctx + ARB_tokenCapacity) <= dstHeader) {
      newStorage = (**(code **)(iVar16 + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
      if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
        _memcpy(newStorage,*(int *)(ctx + ARB_tokenBuffer),*tokenCount << 2);
        (**(code **)(iVar16 + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
      }
      *(undefined4 *)(ctx + ARB_tokenBuffer) = newStorage;
      dstHeader = *tokenCount;
      *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
    }
    *(uint *)(dstHeader * 4 + *(int *)(ctx + ARB_tokenBuffer)) = src1SwizzleWord;
    *tokenCount = *tokenCount + 1;
  }
  return;
}

/* arbEmitIlSetCompare2 @ 0x6bae0 (1920 bytes) */
int arbEmitIlSetCompare2(ctx, dstFile, dstIndex, dstMask, src0File, src0Index, src0Select, src0Negate, src1File, src1Index, src1Select, src1Negate)
  int ctx;
  uint dstFile;
  uint dstIndex;
  int *dstMask;
  uint src0File;
  uint src0Index;
  uint *src0Select;
  uint *src0Negate;
  uint src1File;
  uint src1Index;
  uint *src1Select;
  uint *src1Negate;
{
  uint src1Select3;
  uint src1Negate2;
  uint src1Negate3;
  uint src1Select1;
  uint src1Negate1;
  uint src1Header;
  int dstMask2;
  uint tokenIndex;
  undefined4 newStorage;
  uint src0Negate3;
  uint src0Negate2;
  uint src0Negate1;
  int dstMask1;
  uint src0Select3;
  uint src0SelectX;
  uint src1SelectX;
  uint src0Header;
  uint dstHeader;
  uint dstMaskWord;
  uint src1SwizzleWord;
  int iVar16;
  uint src0SwizzleWord;
  uint *tokenCount;
  
  dstHeader = (dstFile & 0x3f) << 0x10 | dstIndex & 0xffff;
  tokenCount = (uint *)(ctx + ARB_tokenCount);
  src1SwizzleWord = 0;
  src0SwizzleWord = 0;
  dstMaskWord = 0;
  if ((dstFile == 0x12) || (dstFile == 0x13)) {
    dstHeader = dstHeader | 0x400000;
    dstMaskWord = 0x55;
  }
  if (*dstMask == 0) {
    iVar16 = dstMask[3];
    dstMask1 = dstMask[1];
    dstMask2 = dstMask[2];
LAB_0006bbd0:
    dstHeader = dstHeader | 0x400000;
    dstMaskWord = (uint)(iVar16 != 0) * 0x40 |
             (uint)(dstMask2 != 0) * 0x10 | (uint)(dstMask1 != 0) * 4 | (uint)(*dstMask != 0);
  }
  else {
    dstMask1 = dstMask[1];
    if (dstMask1 == 0) {
      iVar16 = dstMask[3];
      dstMask2 = dstMask[2];
      goto LAB_0006bbd0;
    }
    dstMask2 = dstMask[2];
    if (dstMask2 == 0) {
      iVar16 = dstMask[3];
      goto LAB_0006bbd0;
    }
    if (dstMask[3] == 0) {
      iVar16 = 0;
      goto LAB_0006bbd0;
    }
  }
  src0Header = (src0File & 0x3f) << 0x10 | src0Index & 0xffff;
  if (*src0Negate == 0) {
    src0Negate1 = src0Negate[1];
    if (src0Negate1 != 0) {
      src0Negate3 = src0Negate[3];
      src0Select3 = src0Select[3];
      src0Negate2 = src0Negate[2];
      src0SelectX = *src0Select;
      tokenIndex = src0Select[1];
      src1Header = src0Select[2];
      goto LAB_0006bd20;
    }
    src0Negate2 = src0Negate[2];
    if (src0Negate2 != 0) {
      src0Negate3 = src0Negate[3];
      src0Select3 = src0Select[3];
      src0SelectX = *src0Select;
      tokenIndex = src0Select[1];
      src1Header = src0Select[2];
      goto LAB_0006bd20;
    }
    src0Negate3 = src0Negate[3];
    if (src0Negate3 != 0) {
      src0Select3 = src0Select[3];
      src0SelectX = *src0Select;
      tokenIndex = src0Select[1];
      src1Header = src0Select[2];
      goto LAB_0006bd20;
    }
    src0SelectX = *src0Select;
    if (src0SelectX != 0) {
      src0Select3 = src0Select[3];
      tokenIndex = src0Select[1];
      src1Header = src0Select[2];
      goto LAB_0006bd20;
    }
    tokenIndex = src0Select[1];
    if (tokenIndex != 1) {
      src0Select3 = src0Select[3];
      src1Header = src0Select[2];
      goto LAB_0006bd20;
    }
    src1Header = src0Select[2];
    if (src1Header != 2) {
      src0Select3 = src0Select[3];
      goto LAB_0006bd20;
    }
    src0Select3 = src0Select[3];
    if (src0Select3 != 3) goto LAB_0006bd20;
  }
  else {
    src0Negate3 = src0Negate[3];
    src0Select3 = src0Select[3];
    src0Negate1 = src0Negate[1];
    src0Negate2 = src0Negate[2];
    src0SelectX = *src0Select;
    tokenIndex = src0Select[1];
    src1Header = src0Select[2];
LAB_0006bd20:
    src0Header = src0Header | 0x400000;
    src0SwizzleWord = (src0Negate3 & 1) << 0xf |
             (src0Select3 & 7) << 0xc |
             (src0Negate2 & 1) << 0xb |
             (src1Header & 7) << 8 |
             (src0Negate1 & 1) << 7 | (tokenIndex & 7) << 4 | (*src0Negate & 1) << 3 | src0SelectX & 7;
  }
  src1Header = (src1File & 0x3f) << 0x10 | src1Index & 0xffff;
  if (*src1Negate == 0) {
    src1Negate1 = src1Negate[1];
    if (src1Negate1 == 0) {
      src1Negate2 = src1Negate[2];
      if (src1Negate2 == 0) {
        src1Negate3 = src1Negate[3];
        if (src1Negate3 == 0) {
          src1SelectX = *src1Select;
          if (src1SelectX == 0) {
            src1Select1 = src1Select[1];
            if (src1Select1 == 1) {
              tokenIndex = src1Select[2];
              if (tokenIndex == 2) {
                src1Select3 = src1Select[3];
                if (src1Select3 == 3) goto LAB_0006be74;
              }
              else {
                src1Select3 = src1Select[3];
              }
            }
            else {
              src1Select3 = src1Select[3];
              tokenIndex = src1Select[2];
            }
          }
          else {
            src1Select3 = src1Select[3];
            src1Select1 = src1Select[1];
            tokenIndex = src1Select[2];
          }
        }
        else {
          src1Select3 = src1Select[3];
          src1SelectX = *src1Select;
          src1Select1 = src1Select[1];
          tokenIndex = src1Select[2];
        }
      }
      else {
        src1Negate3 = src1Negate[3];
        src1Select3 = src1Select[3];
        src1SelectX = *src1Select;
        src1Select1 = src1Select[1];
        tokenIndex = src1Select[2];
      }
    }
    else {
      src1Negate3 = src1Negate[3];
      src1Select3 = src1Select[3];
      src1Negate2 = src1Negate[2];
      src1SelectX = *src1Select;
      src1Select1 = src1Select[1];
      tokenIndex = src1Select[2];
    }
  }
  else {
    src1Negate3 = src1Negate[3];
    src1Select3 = src1Select[3];
    src1Negate1 = src1Negate[1];
    src1Negate2 = src1Negate[2];
    src1SelectX = *src1Select;
    src1Select1 = src1Select[1];
    tokenIndex = src1Select[2];
  }
  src1Header = src1Header | 0x400000;
  src1SwizzleWord = (src1Negate3 & 1) << 0xf |
           (src1Select3 & 7) << 0xc |
           (src1Negate2 & 1) << 0xb |
           (tokenIndex & 7) << 8 |
           (src1Negate1 & 1) << 7 | (src1Select1 & 7) << 4 | (*src1Negate & 1) << 3 | src1SelectX & 7;
LAB_0006be74:
  tokenIndex = *tokenCount;
  iVar16 = *(int *)(ctx + ARB_allocator);
  if (*(uint *)(ctx + ARB_tokenCapacity) <= tokenIndex) {
    newStorage = (**(code **)(iVar16 + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
    if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
      _memcpy(newStorage,*(int *)(ctx + ARB_tokenBuffer),*tokenCount << 2);
      (**(code **)(iVar16 + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
    }
    *(undefined4 *)(ctx + ARB_tokenBuffer) = newStorage;
    tokenIndex = *tokenCount;
    *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
  }
  *(undefined4 *)(tokenIndex * 4 + *(int *)(ctx + ARB_tokenBuffer)) = 0x20056;
  tokenIndex = *tokenCount + 1;
  *tokenCount = tokenIndex;
  iVar16 = *(int *)(ctx + ARB_allocator);
  if (*(uint *)(ctx + ARB_tokenCapacity) <= tokenIndex) {
    newStorage = (**(code **)(iVar16 + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
    if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
      _memcpy(newStorage,*(int *)(ctx + ARB_tokenBuffer),*tokenCount << 2);
      (**(code **)(iVar16 + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
    }
    *(undefined4 *)(ctx + ARB_tokenBuffer) = newStorage;
    tokenIndex = *tokenCount;
    *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
  }
  *(uint *)(tokenIndex * 4 + *(int *)(ctx + ARB_tokenBuffer)) = dstHeader;
  tokenIndex = *tokenCount + 1;
  *tokenCount = tokenIndex;
  if ((dstHeader & 0x400000) != 0) {
    iVar16 = *(int *)(ctx + ARB_allocator);
    if (*(uint *)(ctx + ARB_tokenCapacity) <= tokenIndex) {
      newStorage = (**(code **)(iVar16 + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
      if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
        _memcpy(newStorage,*(int *)(ctx + ARB_tokenBuffer),*tokenCount << 2);
        (**(code **)(iVar16 + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
      }
      *(undefined4 *)(ctx + ARB_tokenBuffer) = newStorage;
      tokenIndex = *tokenCount;
      *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
    }
    *(uint *)(tokenIndex * 4 + *(int *)(ctx + ARB_tokenBuffer)) = dstMaskWord;
    tokenIndex = *tokenCount + 1;
    *tokenCount = tokenIndex;
  }
  iVar16 = *(int *)(ctx + ARB_allocator);
  if (*(uint *)(ctx + ARB_tokenCapacity) <= tokenIndex) {
    newStorage = (**(code **)(iVar16 + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
    if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
      _memcpy(newStorage,*(int *)(ctx + ARB_tokenBuffer),*tokenCount << 2);
      (**(code **)(iVar16 + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
    }
    *(undefined4 *)(ctx + ARB_tokenBuffer) = newStorage;
    tokenIndex = *tokenCount;
    *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
  }
  *(uint *)(tokenIndex * 4 + *(int *)(ctx + ARB_tokenBuffer)) = src0Header;
  dstHeader = *tokenCount + 1;
  *tokenCount = dstHeader;
  if ((src0Header & 0x400000) != 0) {
    iVar16 = *(int *)(ctx + ARB_allocator);
    if (*(uint *)(ctx + ARB_tokenCapacity) <= dstHeader) {
      newStorage = (**(code **)(iVar16 + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
      if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
        _memcpy(newStorage,*(int *)(ctx + ARB_tokenBuffer),*tokenCount << 2);
        (**(code **)(iVar16 + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
      }
      *(undefined4 *)(ctx + ARB_tokenBuffer) = newStorage;
      dstHeader = *tokenCount;
      *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
    }
    *(uint *)(dstHeader * 4 + *(int *)(ctx + ARB_tokenBuffer)) = src0SwizzleWord;
    dstHeader = *tokenCount + 1;
    *tokenCount = dstHeader;
  }
  iVar16 = *(int *)(ctx + ARB_allocator);
  if (*(uint *)(ctx + ARB_tokenCapacity) <= dstHeader) {
    newStorage = (**(code **)(iVar16 + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
    if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
      _memcpy(newStorage,*(int *)(ctx + ARB_tokenBuffer),*tokenCount << 2);
      (**(code **)(iVar16 + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
    }
    *(undefined4 *)(ctx + ARB_tokenBuffer) = newStorage;
    dstHeader = *tokenCount;
    *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
  }
  *(uint *)(dstHeader * 4 + *(int *)(ctx + ARB_tokenBuffer)) = src1Header;
  dstHeader = *tokenCount + 1;
  *tokenCount = dstHeader;
  if ((src1Header & 0x400000) != 0) {
    iVar16 = *(int *)(ctx + ARB_allocator);
    if (*(uint *)(ctx + ARB_tokenCapacity) <= dstHeader) {
      newStorage = (**(code **)(iVar16 + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
      if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
        _memcpy(newStorage,*(int *)(ctx + ARB_tokenBuffer),*tokenCount << 2);
        (**(code **)(iVar16 + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
      }
      *(undefined4 *)(ctx + ARB_tokenBuffer) = newStorage;
      dstHeader = *tokenCount;
      *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
    }
    *(uint *)(dstHeader * 4 + *(int *)(ctx + ARB_tokenBuffer)) = src1SwizzleWord;
    *tokenCount = *tokenCount + 1;
  }
  return;
}

/* arbEmitIlRnd @ 0x6c280 (1308 bytes) */
int arbEmitIlRnd(param_1, dstFile, dstIndex, dstMask, src0File, src0Index, src0Select, src0Negate)
  int param_1;
  uint dstFile;
  uint dstIndex;
  int *dstMask;
  uint src0File;
  uint src0Index;
  uint *src0Select;
  uint *src0Negate;
{
  int dstMaskW;
  uint dstToken;
  uint src0SelectZ;
  uint uVar1;
  int dstMaskZ;
  uint src0SelectY;
  undefined4 uVar4;
  uint src0NegateW;
  uint src0NegateZ;
  uint src0NegateY;
  int dstMaskY;
  uint src0SelectW;
  uint src0SelectX;
  uint src0Token;
  uint uVar12;
  uint uVar13;
  int iVar14;
  uint uVar15;
  uint *puVar16;
  
  dstToken = (dstFile & 0x3f) << 0x10 | dstIndex & 0xffff;
  puVar16 = (uint *)(param_1 + 0x754);
  uVar15 = 0;
  uVar13 = 0;
  if ((dstFile == 0x12) || (dstFile == 0x13)) {
    dstToken = dstToken | 0x400000;
    uVar13 = 0x55;
  }
  if (*dstMask == 0) {
    dstMaskW = dstMask[3];
    dstMaskY = dstMask[1];
    dstMaskZ = dstMask[2];
LAB_0006c360:
    dstToken = dstToken | 0x400000;
    uVar13 = (uint)(dstMaskW != 0) * 0x40 |
             (uint)(dstMaskZ != 0) * 0x10 | (uint)(dstMaskY != 0) * 4 | (uint)(*dstMask != 0);
  }
  else {
    dstMaskY = dstMask[1];
    if (dstMaskY == 0) {
      dstMaskW = dstMask[3];
      dstMaskZ = dstMask[2];
      goto LAB_0006c360;
    }
    dstMaskZ = dstMask[2];
    if (dstMaskZ == 0) {
      dstMaskW = dstMask[3];
      goto LAB_0006c360;
    }
    if (dstMask[3] == 0) {
      dstMaskW = 0;
      goto LAB_0006c360;
    }
  }
  src0Token = (src0File & 0x3f) << 0x10 | src0Index & 0xffff;
  if (*src0Negate == 0) {
    src0NegateY = src0Negate[1];
    if (src0NegateY == 0) {
      src0NegateZ = src0Negate[2];
      if (src0NegateZ == 0) {
        src0NegateW = src0Negate[3];
        if (src0NegateW == 0) {
          src0SelectX = *src0Select;
          if (src0SelectX == 0) {
            src0SelectY = src0Select[1];
            if (src0SelectY == 1) {
              src0SelectZ = src0Select[2];
              if (src0SelectZ == 2) {
                src0SelectW = src0Select[3];
                if (src0SelectW == 3) goto LAB_0006c4d4;
              }
              else {
                src0SelectW = src0Select[3];
              }
            }
            else {
              src0SelectW = src0Select[3];
              src0SelectZ = src0Select[2];
            }
          }
          else {
            src0SelectW = src0Select[3];
            src0SelectY = src0Select[1];
            src0SelectZ = src0Select[2];
          }
        }
        else {
          src0SelectW = src0Select[3];
          src0SelectX = *src0Select;
          src0SelectY = src0Select[1];
          src0SelectZ = src0Select[2];
        }
      }
      else {
        src0NegateW = src0Negate[3];
        src0SelectW = src0Select[3];
        src0SelectX = *src0Select;
        src0SelectY = src0Select[1];
        src0SelectZ = src0Select[2];
      }
    }
    else {
      src0NegateW = src0Negate[3];
      src0SelectW = src0Select[3];
      src0NegateZ = src0Negate[2];
      src0SelectX = *src0Select;
      src0SelectY = src0Select[1];
      src0SelectZ = src0Select[2];
    }
  }
  else {
    src0NegateW = src0Negate[3];
    src0SelectW = src0Select[3];
    src0NegateY = src0Negate[1];
    src0NegateZ = src0Negate[2];
    src0SelectX = *src0Select;
    src0SelectY = src0Select[1];
    src0SelectZ = src0Select[2];
  }
  src0Token = src0Token | 0x400000;
  uVar15 = (src0NegateW & 1) << 0xf |
           (src0SelectW & 7) << 0xc |
           (src0NegateZ & 1) << 0xb |
           (src0SelectZ & 7) << 8 | (src0NegateY & 1) << 7 | (src0SelectY & 7) << 4 | (*src0Negate & 1) << 3 | src0SelectX & 7
  ;
LAB_0006c4d4:
  uVar1 = *puVar16;
  iVar14 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= uVar1) {
    uVar4 = (**(code **)(iVar14 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(int *)(param_1 + 0x75c) != 0) {
      _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar16 << 2);
      (**(code **)(iVar14 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(undefined4 *)(param_1 + 0x75c) = uVar4;
    uVar1 = *puVar16;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(undefined4 *)(uVar1 * 4 + *(int *)(param_1 + 0x75c)) = 0x54;
  uVar1 = *puVar16 + 1;
  *puVar16 = uVar1;
  iVar14 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= uVar1) {
    uVar4 = (**(code **)(iVar14 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(int *)(param_1 + 0x75c) != 0) {
      _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar16 << 2);
      (**(code **)(iVar14 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(undefined4 *)(param_1 + 0x75c) = uVar4;
    uVar1 = *puVar16;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(uVar1 * 4 + *(int *)(param_1 + 0x75c)) = dstToken;
  uVar1 = *puVar16 + 1;
  *puVar16 = uVar1;
  if ((dstToken & 0x400000) != 0) {
    iVar14 = *(int *)(param_1 + 0x3d4);
    if (*(uint *)(param_1 + 0x758) <= uVar1) {
      uVar4 = (**(code **)(iVar14 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
      if (*(int *)(param_1 + 0x75c) != 0) {
        _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar16 << 2);
        (**(code **)(iVar14 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
      }
      *(undefined4 *)(param_1 + 0x75c) = uVar4;
      uVar1 = *puVar16;
      *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
    }
    *(uint *)(uVar1 * 4 + *(int *)(param_1 + 0x75c)) = uVar13;
    uVar1 = *puVar16 + 1;
    *puVar16 = uVar1;
  }
  iVar14 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= uVar1) {
    uVar4 = (**(code **)(iVar14 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(int *)(param_1 + 0x75c) != 0) {
      _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar16 << 2);
      (**(code **)(iVar14 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(undefined4 *)(param_1 + 0x75c) = uVar4;
    uVar1 = *puVar16;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(uVar1 * 4 + *(int *)(param_1 + 0x75c)) = src0Token;
  uVar12 = *puVar16 + 1;
  *puVar16 = uVar12;
  if ((src0Token & 0x400000) != 0) {
    iVar14 = *(int *)(param_1 + 0x3d4);
    if (*(uint *)(param_1 + 0x758) <= uVar12) {
      uVar4 = (**(code **)(iVar14 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
      if (*(int *)(param_1 + 0x75c) != 0) {
        _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar16 << 2);
        (**(code **)(iVar14 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
      }
      *(undefined4 *)(param_1 + 0x75c) = uVar4;
      uVar12 = *puVar16;
      *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
    }
    *(uint *)(uVar12 * 4 + *(int *)(param_1 + 0x75c)) = uVar15;
    *puVar16 = *puVar16 + 1;
  }
  return;
}


/* issue: auto-generated aliases bridging data.s/code.s references (written
 * without a leading underscore, matching the raw stock-binary symbol name)
 * against the real compiled C symbols (gcc adds one underscore automatically).
 * Needed because ld64 (required for this PPC binary's size - stock ld breaks on
 * large PPC links) does not silently reconcile this the way stock ld did. */
asm(".globl extvsEmitSub");
asm(".set extvsEmitSub, _extvsEmitSub");
asm(".globl extvsEmitCrs");
asm(".set extvsEmitCrs, _extvsEmitCrs");
asm(".globl extvsEmitMmul");
asm(".set extvsEmitMmul, _extvsEmitMmul");
asm(".globl extvsEmitMov");
asm(".set extvsEmitMov, _extvsEmitMov");
asm(".globl extvsEmitSwizzle");
asm(".set extvsEmitSwizzle, _extvsEmitSwizzle");
asm(".globl extvsEmitWriteMask");
asm(".set extvsEmitWriteMask, _extvsEmitWriteMask");
asm(".globl extvsEmitOp879c");
asm(".set extvsEmitOp879c, _extvsEmitOp879c");
asm(".globl extvsEmitOp879d");
asm(".set extvsEmitOp879d, _extvsEmitOp879d");
asm(".globl extvsEmitLit");
asm(".set extvsEmitLit, _extvsEmitLit");
asm(".globl extvsEmitDst");
asm(".set extvsEmitDst, _extvsEmitDst");
asm(".globl extvsEmitExpp");
asm(".set extvsEmitExpp, _extvsEmitExpp");
asm(".globl extvsEmitLogp");
asm(".set extvsEmitLogp, _extvsEmitLogp");
asm(".globl extvsEmitMova");
asm(".set extvsEmitMova, _extvsEmitMova");
asm(".globl FUN_0005f540");
asm(".set FUN_0005f540, _FUN_0005f540");
asm(".globl extvsPrepareHardwareProgram");
asm(".set extvsPrepareHardwareProgram, _extvsPrepareHardwareProgram");
asm(".globl FUN_00062370");
asm(".set FUN_00062370, _FUN_00062370");
asm(".globl FUN_000623e0");
asm(".set FUN_000623e0, _extvsInitLimits");
asm(".globl FUN_00062410");
asm(".set FUN_00062410, _FUN_00062410");
asm(".globl FUN_00062510");
asm(".set FUN_00062510, _FUN_00062510");
asm(".globl extvsStateCacheCreate");
asm(".set extvsStateCacheCreate, _extvsStateCacheCreate");
asm(".globl extvsStateCacheFreeAll");
asm(".set extvsStateCacheFreeAll, _extvsStateCacheFreeAll");
asm(".globl FUN_00062940");
asm(".set FUN_00062940, _FUN_00062940");
asm(".globl extvsBuildStreamDescriptors");
asm(".set extvsBuildStreamDescriptors, _extvsBuildStreamDescriptors");
asm(".globl gldCurrentAttributePacketHeader");
asm(".set gldCurrentAttributePacketHeader, _gldCurrentAttributePacketHeader");
asm(".globl FUN_00064230");
asm(".set FUN_00064230, _FUN_00064230");
asm(".globl FUN_00064850");
asm(".set FUN_00064850, _FUN_00064850");
asm(".globl FUN_00064a10");
asm(".set FUN_00064a10, _FUN_00064a10");
asm(".globl FUN_00064f40");
asm(".set FUN_00064f40, _FUN_00064f40");
asm(".globl FUN_00065610");
asm(".set FUN_00065610, _FUN_00065610");
asm(".globl FUN_000659d0");
asm(".set FUN_000659d0, _FUN_000659d0");
asm(".globl FUN_00065c40");
asm(".set FUN_00065c40, _FUN_00065c40");
asm(".globl noop_65c80");
asm(".set noop_65c80, _noop_65c80");
asm(".globl arbEmitIlHeader");
asm(".set arbEmitIlHeader, _arbEmitIlHeader");
asm(".globl arbEmitIlEnd");
asm(".set arbEmitIlEnd, _arbEmitIlEnd");
asm(".globl arbEmitIlDp4");
asm(".set arbEmitIlDp4, _arbEmitIlDp4");
asm(".globl arbEmitIlMov");
asm(".set arbEmitIlMov, _arbEmitIlMov");
asm(".globl arbEmitIlMul");
asm(".set arbEmitIlMul, _arbEmitIlMul");
asm(".globl arbEmitIlAdd");
asm(".set arbEmitIlAdd, _arbEmitIlAdd");
asm(".globl arbEmitIlMad");
asm(".set arbEmitIlMad, _arbEmitIlMad");
asm(".globl arbEmitIlAddMad3Src");
asm(".set arbEmitIlAddMad3Src, _arbEmitIlAddMad3Src");
asm(".globl arbEmitIlMulMaxMin2Src");
asm(".set arbEmitIlMulMaxMin2Src, _arbEmitIlMulMaxMin2Src");
asm(".globl arbEmitIlMin");
asm(".set arbEmitIlMin, _arbEmitIlMin");
asm(".globl arbEmitIlMax");
asm(".set arbEmitIlMax, _arbEmitIlMax");
asm(".globl arbEmitIlSetCompare5");
asm(".set arbEmitIlSetCompare5, _arbEmitIlSetCompare5");
asm(".globl arbEmitIlSetCompare2");
asm(".set arbEmitIlSetCompare2, _arbEmitIlSetCompare2");
asm(".globl arbEmitIlRnd");
asm(".set arbEmitIlRnd, _arbEmitIlRnd");
