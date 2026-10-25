#include "decls.h"

/* extvsEmitSub @ 0x5bbc0 (928 bytes) */
int extvsEmitSub(ctx, shader, instRecord)
  int ctx;
  int *shader;
  int instRecord;
{
  undefined4 tempSlot;
  undefined4 emittedInstCount;
  int instSlot;
  int hwProgram;
  uint swizzleWord;
  int conflict;
  undefined4 newInstArray;
  int src1Operand;
  int src0Operand;
  int *symbolList;
  int instCount;
  undefined4 operandAKind;
  undefined4 operandAIndex;
  undefined4 operandASelX;
  undefined4 operandASelY;
  undefined4 operandASelZ;
  undefined4 operandASelW;
  undefined1 operandAFlag;
  undefined4 operandBKind;
  undefined4 operandBIndex;
  undefined4 operandBSelX;
  undefined4 operandBSelY;
  undefined4 operandBSelZ;
  undefined4 operandBSelW;
  undefined1 operandBFlag;
  
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
    extvsEncodeSourceSwizzle(shader,symbolList,src0Operand,instSlot + 4,0);
    extvsEncodeSourceSwizzle(shader,symbolList,src1Operand,instSlot + 8,0);
    swizzleWord = *(uint *)(instSlot + 8);
    emittedInstCount = 1;
    swizzleWord = (swizzleWord & 0xf1ffffff ^ 0x10000000) & 0x10000000 |
            (swizzleWord & 0xf9ffffff ^ 0x8000000) & 0x8000000 |
            (swizzleWord & 0xfdffffff ^ 0x4000000) & 0x4000000 |
            (swizzleWord ^ 0x2000000) & 0x2000000 | swizzleWord & 0xe1ffffff;
    *(uint *)(instSlot + 0xc) = swizzleWord;
    *(uint *)(instSlot + 8) = swizzleWord;
  }
  else {
    hwProgram = **(int **)(*(int *)(((unsigned char *)0x0000118c) + ctx) * 4 + *shader);
    instCount = *(int *)(hwProgram + 0x18);
    if (0x100 < instCount + 2U) {
      *(undefined1 *)(shader + 4) = 0;
      instCount = *(int *)(hwProgram + 0x18);
      if (*(uint *)(hwProgram + 0x20) < instCount + 2U) {
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
    tempSlot = extvsAllocTempSlot(ctx,shader);
    operandAKind = 3;
    operandAFlag = 0;
    operandASelW = 1;
    operandASelX = 1;
    operandASelY = 1;
    operandASelZ = 1;
    operandAIndex = tempSlot;
    extvsEncodeSourceOperand(ctx,shader,&operandAKind,instSlot,3,0,0);
    extvsEncodeSourceSwizzle(shader,symbolList,src0Operand,instSlot + 4,0);
    swizzleWord = *(uint *)(instSlot + 4) & 0xfe001fff | 0x1248000;
    *(uint *)(instSlot + 0xc) = swizzleWord;
    *(uint *)(instSlot + 8) = swizzleWord;
    extvsEncodeSourceOperand(ctx,shader,instRecord + 4,instSlot + 0x10,3,0,0);
    operandBKind = 3;
    operandBFlag = 0;
    operandBSelX = 0x87d5;
    operandBSelY = 0x87d6;
    operandBSelZ = 0x87d7;
    operandBSelW = 0x87d8;
    operandBIndex = tempSlot;
    extvsEncodeSourceSwizzle(shader,symbolList,&operandBKind,instSlot + 0x14,0);
    extvsEncodeSourceSwizzle(shader,symbolList,src1Operand,instSlot + 0x18,0);
    swizzleWord = *(uint *)(instSlot + 0x18);
    emittedInstCount = 2;
    swizzleWord = (swizzleWord & 0xf1ffffff ^ 0x10000000) & 0x10000000 |
            (swizzleWord & 0xf9ffffff ^ 0x8000000) & 0x8000000 |
            (swizzleWord & 0xfdffffff ^ 0x4000000) & 0x4000000 |
            (swizzleWord ^ 0x2000000) & 0x2000000 | swizzleWord & 0xe1ffffff;
    *(uint *)(instSlot + 0x1c) = swizzleWord;
    *(uint *)(instSlot + 0x18) = swizzleWord;
  }
  return emittedInstCount;
}

/* extvsEmitCrs @ 0x5bf60 (1672 bytes) */
int extvsEmitCrs(ctx, shader, instRecord)
  int ctx;
  int *shader;
  int instRecord;
{
  int bankConflict;
  undefined4 emittedInstCount;
  undefined4 tempSlot;
  int tempIndex;
  int instCount;
  undefined1 savedSlotFlag;
  uint swizzleWord;
  int iVar3;
  undefined4 newInstArray;
  int *symbolList;
  int src0Operand;
  int src1Operand;
  int hwProgram;
  int instSlot;
  int iVar10;
  int iStack00000020;
  undefined4 operandAKind;
  int operandAIndex;
  undefined4 operandASelX;
  undefined4 operandASelY;
  undefined4 operandASelZ;
  undefined4 operandASelW;
  undefined1 operandAFlag;
  undefined4 operandBKind;
  int operandBIndex;
  undefined4 operandBSelX;
  undefined4 operandBSelY;
  undefined4 operandBSelZ;
  undefined4 operandBSelW;
  undefined1 operandBFlag;
  undefined4 *operandBPtr;
  
  src0Operand = instRecord + 0x20;
  symbolList = shader + 7;
  src1Operand = instRecord + 0x3c;
  iStack00000020 = instRecord;
  bankConflict = extvsOperandsConflictInBank(symbolList,src0Operand,src1Operand);
  if (bankConflict == 0) {
    iVar3 = **(int **)(*(int *)(((unsigned char *)0x0000118c) + ctx) * 4 + *shader);
    instCount = *(int *)(iVar3 + 0x18);
    if (0x100 < instCount + 2U) {
      *(undefined1 *)(shader + 4) = 0;
      instCount = *(int *)(iVar3 + 0x18);
      if (*(uint *)(iVar3 + 0x20) < instCount + 2U) {
        newInstArray = (**(code **)(ctx + 0xc))(*(uint *)(iVar3 + 0x20) * 0x10 + 0x100);
        (**(code **)(((unsigned char *)0x00001344) + ctx))
                  (newInstArray,*(undefined4 *)(iVar3 + 0x1c),*(int *)(iVar3 + 0x20) << 4);
        (**(code **)(ctx + 0x18))(*(undefined4 *)(iVar3 + 0x1c));
        *(undefined4 *)(iVar3 + 0x1c) = newInstArray;
        instCount = *(int *)(iVar3 + 0x18);
        *(int *)(iVar3 + 0x20) = *(int *)(iVar3 + 0x20) + 0x10;
      }
    }
    iVar3 = instCount * 0x10 + *(int *)(iVar3 + 0x1c);
    tempSlot = extvsAllocTempSlot(ctx,shader);
    operandAKind = 3;
    operandAFlag = 0;
    operandASelW = 1;
    operandASelX = 1;
    operandASelY = 1;
    operandASelZ = 1;
    operandAIndex = tempSlot;
    extvsEncodeSourceOperand(ctx,shader,&operandAKind,iVar3,2,0,0);
    extvsEncodeSourceSwizzle(shader,symbolList,src0Operand,iVar3 + 4,0);
    swizzleWord = *(uint *)(iVar3 + 4);
    *(uint *)(iVar3 + 4) =
         (swizzleWord & 0x4000000) << 1 |
         (swizzleWord & 0x2000000) << 1 |
         swizzleWord >> 2 & 0x2000000 |
         (swizzleWord & 0x70000) << 3 | (swizzleWord & 0xe000) << 3 | swizzleWord >> 6 & 0xe000 | swizzleWord & 0xe0001fff |
         0x1000000;
    extvsEncodeSourceSwizzle(shader,symbolList,src1Operand,iVar3 + 8,0);
    swizzleWord = *(uint *)(iVar3 + 8);
    swizzleWord = (swizzleWord & 0x2000000) << 2 |
            swizzleWord >> 1 & 0x4000000 |
            swizzleWord >> 1 & 0x2000000 |
            (swizzleWord & 0xe000) << 6 | swizzleWord >> 3 & 0x70000 | swizzleWord >> 3 & 0xe000 | swizzleWord & 0xe0001fff
            | 0x1000000;
    *(uint *)(iVar3 + 0xc) = swizzleWord;
    *(uint *)(iVar3 + 8) = swizzleWord;
    extvsEncodeSourceOperand(ctx,shader,iStack00000020 + 4,iVar3 + 0x10,4,0,0);
    extvsEncodeSourceSwizzle(shader,symbolList,src0Operand,iVar3 + 0x14,0);
    swizzleWord = *(uint *)(iVar3 + 0x14);
    *(uint *)(iVar3 + 0x14) =
         (swizzleWord & 0x2000000) << 2 |
         swizzleWord >> 1 & 0x4000000 |
         swizzleWord >> 1 & 0x2000000 |
         (swizzleWord & 0xe000) << 6 | swizzleWord >> 3 & 0x70000 | swizzleWord >> 3 & 0xe000 | swizzleWord & 0xe0001fff |
         0x1400000;
    extvsEncodeSourceSwizzle(shader,symbolList,src1Operand,iVar3 + 0x18,0);
    swizzleWord = *(uint *)(iVar3 + 0x18);
    *(uint *)(iVar3 + 0x18) =
         (swizzleWord & 0x4000000) << 1 |
         (swizzleWord & 0x2000000) << 1 |
         swizzleWord >> 2 & 0x2000000 |
         (swizzleWord & 0x70000) << 3 | (swizzleWord & 0xe000) << 3 | swizzleWord >> 6 & 0xe000 | swizzleWord & 0xe0001fff |
         0x1400000;
    operandBKind = 3;
    operandBSelX = 0x87d9;
    operandBSelY = 0x87da;
    operandBSelZ = 0x87db;
    operandBSelW = 0x87dc;
    operandBFlag = 0;
    operandBIndex = tempSlot;
    extvsEncodeSourceSwizzle(shader,symbolList,&operandBKind,iVar3 + 0x1c,0);
    emittedInstCount = 2;
  }
  else {
    iVar10 = **(int **)(*(int *)(((unsigned char *)0x0000118c) + ctx) * 4 + *shader);
    iVar3 = *(int *)(iVar10 + 0x18);
    if (0x100 < iVar3 + 3U) {
      *(undefined1 *)(shader + 4) = 0;
      iVar3 = *(int *)(iVar10 + 0x18);
      if (*(uint *)(iVar10 + 0x20) < iVar3 + 3U) {
        newInstArray = (**(code **)(ctx + 0xc))(*(uint *)(iVar10 + 0x20) * 0x10 + 0x100);
        (**(code **)(((unsigned char *)0x00001344) + ctx))
                  (newInstArray,*(undefined4 *)(iVar10 + 0x1c),*(int *)(iVar10 + 0x20) << 4);
        (**(code **)(ctx + 0x18))(*(undefined4 *)(iVar10 + 0x1c));
        *(undefined4 *)(iVar10 + 0x1c) = newInstArray;
        iVar3 = *(int *)(iVar10 + 0x18);
        *(int *)(iVar10 + 0x20) = *(int *)(iVar10 + 0x20) + 0x10;
      }
    }
    instSlot = iVar3 * 0x10 + *(int *)(iVar10 + 0x1c);
    tempIndex = extvsAllocTempSlot(ctx,shader);
    operandBPtr = &operandBKind;
    hwProgram = **(int **)(*(int *)(((unsigned char *)0x0000118c) + ctx) * 4 + *shader);
    iVar3 = tempIndex * 0x28 + *(int *)(hwProgram + 0x4c);
    savedSlotFlag = *(undefined1 *)(iVar3 + 0x10);
    *(undefined1 *)(iVar3 + 0x10) = 1;
    tempSlot = extvsAllocTempSlot(ctx,shader);
    *(undefined1 *)(tempIndex * 0x28 + *(int *)(hwProgram + 0x4c) + 0x10) = savedSlotFlag;
    operandAFlag = 0;
    operandAKind = 3;
    operandASelX = 1;
    operandASelY = 1;
    operandASelZ = 1;
    operandASelW = 1;
    operandAIndex = tempIndex;
    extvsEncodeSourceOperand(ctx,shader,&operandAKind,instSlot,3,0,0);
    extvsEncodeSourceSwizzle(shader,symbolList,src0Operand,instSlot + 4,0);
    swizzleWord = *(uint *)(instSlot + 4) & 0xfe001fff | 0x1248000;
    *(uint *)(instSlot + 0xc) = swizzleWord;
    *(uint *)(instSlot + 8) = swizzleWord;
    operandAFlag = 0;
    operandASelW = 1;
    operandAKind = 3;
    operandASelX = 1;
    operandASelY = 1;
    operandASelZ = 1;
    operandAIndex = tempSlot;
    extvsEncodeSourceOperand(ctx,shader,&operandAKind,instSlot + 0x10,2,0,0);
    operandBSelX = 0x87d7;
    operandBSelY = 0x87d5;
    operandBFlag = 0;
    operandBSelZ = 0x87d6;
    operandBSelW = 0x87dd;
    operandBKind = 3;
    operandBIndex = tempIndex;
    extvsEncodeSourceSwizzle(shader,symbolList,operandBPtr,instSlot + 0x14,0);
    extvsEncodeSourceSwizzle(shader,symbolList,src1Operand,instSlot + 0x18,0);
    swizzleWord = *(uint *)(instSlot + 0x18);
    swizzleWord = (swizzleWord & 0x2000000) << 2 |
            swizzleWord >> 1 & 0x4000000 |
            swizzleWord >> 1 & 0x2000000 |
            (swizzleWord & 0xe000) << 6 | swizzleWord >> 3 & 0x70000 | swizzleWord >> 3 & 0xe000 | swizzleWord & 0xe0001fff
            | 0x1000000;
    *(uint *)(instSlot + 0x1c) = swizzleWord;
    *(uint *)(instSlot + 0x18) = swizzleWord;
    extvsEncodeSourceOperand(ctx,shader,iStack00000020 + 4,instSlot + 0x20,4,0,0);
    operandBSelX = 0x87d6;
    operandBSelY = 0x87d7;
    operandBFlag = 0;
    operandBSelZ = 0x87d5;
    operandBSelW = 0x87de;
    operandBKind = 3;
    operandBIndex = tempIndex;
    extvsEncodeSourceSwizzle(shader,symbolList,operandBPtr,instSlot + 0x24,0);
    extvsEncodeSourceSwizzle(shader,symbolList,src1Operand,instSlot + 0x28,0);
    swizzleWord = *(uint *)(instSlot + 0x28);
    *(uint *)(instSlot + 0x28) =
         (swizzleWord & 0x4000000) << 1 |
         (swizzleWord & 0x2000000) << 1 |
         swizzleWord >> 2 & 0x2000000 |
         (swizzleWord & 0x70000) << 3 | (swizzleWord & 0xe000) << 3 | swizzleWord >> 6 & 0xe000 | swizzleWord & 0xe0001fff |
         0x1400000;
    operandBSelX = 0x87d9;
    operandBSelY = 0x87da;
    operandBKind = 3;
    operandBSelZ = 0x87db;
    operandBSelW = 0x87dc;
    operandBFlag = 0;
    operandBIndex = tempSlot;
    extvsEncodeSourceSwizzle(shader,symbolList,operandBPtr,instSlot + 0x2c,0);
    emittedInstCount = 3;
  }
  return emittedInstCount;
}

/* extvsEmitMmul @ 0x5c600 (1552 bytes) */
int extvsEmitMmul(ctx, shader, instRecord)
  int ctx;
  int *shader;
  int instRecord;
{
  int bankConflict;
  int dstOperand;
  int instCount;
  int instSlot;
  int hwProgram;
  undefined4 tempIndex;
  uint swizzleWord;
  int iVar2;
  undefined4 newInstArray;
  int src0Operand;
  int *symbolList;
  int src1Operand;
  int hwProgram2;
  int instArrayBase;
  int slotAddr;
  undefined4 operandAKind;
  undefined4 operandAIndex;
  undefined4 operandASelX;
  undefined4 operandASelY;
  undefined4 operandASelZ;
  undefined4 operandASelW;
  undefined1 operandAFlag;
  undefined4 operandBKind;
  undefined4 operandBIndex;
  undefined4 operandBSelX;
  undefined4 operandBSelY;
  undefined4 operandBSelZ;
  undefined4 operandBSelW;
  undefined1 operandBFlag;
  
  if ((*(int *)(instRecord + 4) != *(int *)(instRecord + 0x3c)) ||
     (*(int *)(instRecord + 8) != *(int *)(instRecord + 0x40))) {
    symbolList = shader + 7;
    src0Operand = instRecord + 0x20;
    src1Operand = instRecord + 0x3c;
    bankConflict = extvsOperandsConflictInBank(symbolList,src0Operand,src1Operand);
    if (bankConflict == 0) {
      hwProgram2 = **(int **)(*(int *)(((unsigned char *)0x0000118c) + ctx) * 4 + *shader);
      iVar2 = *(int *)(hwProgram2 + 0x18);
      if (0x100 < iVar2 + 4U) {
        *(undefined1 *)(shader + 4) = 0;
        iVar2 = *(int *)(hwProgram2 + 0x18);
        if (*(uint *)(hwProgram2 + 0x20) < iVar2 + 4U) {
          newInstArray = (**(code **)(ctx + 0xc))(*(uint *)(hwProgram2 + 0x20) * 0x10 + 0x100);
          (**(code **)(((unsigned char *)0x00001344) + ctx))
                    (newInstArray,*(undefined4 *)(hwProgram2 + 0x1c),*(int *)(hwProgram2 + 0x20) << 4);
          (**(code **)(ctx + 0x18))(*(undefined4 *)(hwProgram2 + 0x1c));
          *(undefined4 *)(hwProgram2 + 0x1c) = newInstArray;
          iVar2 = *(int *)(hwProgram2 + 0x18);
          *(int *)(hwProgram2 + 0x20) = *(int *)(hwProgram2 + 0x20) + 0x10;
        }
      }
      instArrayBase = *(int *)(hwProgram2 + 0x1c);
      iVar2 = iVar2 * 0x10;
      dstOperand = instRecord + 4;
      slotAddr = iVar2 + instArrayBase;
      extvsEncodeSourceOperand(ctx,shader,dstOperand,slotAddr,1,0,0);
      *(uint *)(iVar2 + instArrayBase) = *(uint *)(iVar2 + instArrayBase) & 0xff1fffff;
      extvsEncodeSourceSwizzle(shader,symbolList,src0Operand,slotAddr + 4,0);
      extvsEncodeSourceSwizzle(shader,symbolList,src1Operand,slotAddr + 8,0);
      *(undefined4 *)(slotAddr + 0xc) = *(undefined4 *)(slotAddr + 8);
      extvsEncodeSourceOperand(ctx,shader,dstOperand,slotAddr + 0x10,1,0,0);
      *(uint *)(slotAddr + 0x10) = *(uint *)(slotAddr + 0x10) & 0xff2fffff;
      extvsEncodeSourceSwizzle(shader,symbolList,src0Operand,slotAddr + 0x14,1);
      extvsEncodeSourceSwizzle(shader,symbolList,src1Operand,slotAddr + 0x18,0);
      *(undefined4 *)(slotAddr + 0x1c) = *(undefined4 *)(slotAddr + 0x18);
      extvsEncodeSourceOperand(ctx,shader,dstOperand,slotAddr + 0x20,1,0,0);
      *(uint *)(slotAddr + 0x20) = *(uint *)(slotAddr + 0x20) & 0xff4fffff;
      extvsEncodeSourceSwizzle(shader,symbolList,src0Operand,slotAddr + 0x24,2);
      extvsEncodeSourceSwizzle(shader,symbolList,src1Operand,slotAddr + 0x28,0);
      *(undefined4 *)(slotAddr + 0x2c) = *(undefined4 *)(slotAddr + 0x28);
      extvsEncodeSourceOperand(ctx,shader,dstOperand,slotAddr + 0x30,1,0,0);
      *(uint *)(slotAddr + 0x30) = *(uint *)(slotAddr + 0x30) & 0xff8fffff;
      extvsEncodeSourceSwizzle(shader,symbolList,src0Operand,slotAddr + 0x34,3);
      extvsEncodeSourceSwizzle(shader,symbolList,src1Operand,slotAddr + 0x38,0);
      *(undefined4 *)(slotAddr + 0x3c) = *(undefined4 *)(slotAddr + 0x38);
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
  dstOperand = instRecord + 4;
  instSlot = instCount * 0x10 + *(int *)(hwProgram + 0x1c);
  tempIndex = extvsAllocTempSlot(ctx,shader);
  operandAKind = 3;
  operandAFlag = 0;
  operandASelW = 1;
  operandASelX = 1;
  operandASelY = 1;
  operandASelZ = 1;
  operandAIndex = tempIndex;
  extvsEncodeSourceOperand(ctx,shader,&operandAKind,instSlot,3,0,0);
  extvsEncodeSourceSwizzle(shader,symbolList,instRecord + 0x3c,instSlot + 4,0);
  swizzleWord = *(uint *)(instSlot + 4) & 0xfe001fff | 0x1248000;
  *(uint *)(instSlot + 0xc) = swizzleWord;
  *(uint *)(instSlot + 8) = swizzleWord;
  extvsEncodeSourceOperand(ctx,shader,dstOperand,instSlot + 0x10,1,0,0);
  *(uint *)(instSlot + 0x10) = *(uint *)(instSlot + 0x10) & 0xff1fffff;
  extvsEncodeSourceSwizzle(shader,symbolList,iVar2,instSlot + 0x14,0);
  operandBKind = 3;
  operandBFlag = 0;
  operandBSelY = 0x87d6;
  operandBSelX = 0x87d5;
  operandBSelZ = 0x87d7;
  operandBSelW = 0x87d8;
  operandBIndex = tempIndex;
  extvsEncodeSourceSwizzle(shader,symbolList,&operandBKind,instSlot + 0x18,0);
  *(undefined4 *)(instSlot + 0x1c) = *(undefined4 *)(instSlot + 0x18);
  extvsEncodeSourceOperand(ctx,shader,dstOperand,instSlot + 0x20,1,0,0);
  *(uint *)(instSlot + 0x20) = *(uint *)(instSlot + 0x20) & 0xff2fffff;
  extvsEncodeSourceSwizzle(shader,symbolList,iVar2,instSlot + 0x24,1);
  extvsEncodeSourceSwizzle(shader,symbolList,&operandBKind,instSlot + 0x28,0);
  *(undefined4 *)(instSlot + 0x2c) = *(undefined4 *)(instSlot + 0x28);
  extvsEncodeSourceOperand(ctx,shader,dstOperand,instSlot + 0x30,1,0,0);
  *(uint *)(instSlot + 0x30) = *(uint *)(instSlot + 0x30) & 0xff4fffff;
  extvsEncodeSourceSwizzle(shader,symbolList,iVar2,instSlot + 0x34,2);
  extvsEncodeSourceSwizzle(shader,symbolList,&operandBKind,instSlot + 0x38,0);
  *(undefined4 *)(instSlot + 0x3c) = *(undefined4 *)(instSlot + 0x38);
  extvsEncodeSourceOperand(ctx,shader,dstOperand,instSlot + 0x40,1,0,0);
  *(uint *)(instSlot + 0x40) = *(uint *)(instSlot + 0x40) & 0xff8fffff;
  extvsEncodeSourceSwizzle(shader,symbolList,iVar2,instSlot + 0x44,3);
  extvsEncodeSourceSwizzle(shader,symbolList,&operandBKind,instSlot + 0x48,0);
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
  undefined4 tempSlot;
  undefined4 emittedInstCount;
  int instSlot;
  int hwProgram;
  uint swizzleWord;
  int conflict;
  undefined4 newInstArray;
  int src1Operand;
  int src0Operand;
  int *symbolList;
  int instCount;
  undefined4 operandAKind;
  undefined4 operandAIndex;
  undefined4 operandASelX;
  undefined4 operandASelY;
  undefined4 operandASelZ;
  undefined4 operandASelW;
  undefined1 operandAFlag;
  undefined4 operandBKind;
  undefined4 operandBIndex;
  undefined4 operandBSelX;
  undefined4 operandBSelY;
  undefined4 operandBSelZ;
  undefined4 operandBSelW;
  undefined1 operandBFlag;
  
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
    extvsEncodeSourceOperand(ctx,shader,instRecord + 4,instSlot,5,0,0);
    extvsEncodeSourceSwizzle(shader,symbolList,src0Operand,instSlot + 4,0);
    extvsEncodeSourceSwizzle(shader,symbolList,src1Operand,instSlot + 8,0);
    emittedInstCount = 1;
    *(undefined4 *)(instSlot + 0xc) = *(undefined4 *)(instSlot + 8);
  }
  else {
    hwProgram = **(int **)(*(int *)(((unsigned char *)0x0000118c) + ctx) * 4 + *shader);
    instCount = *(int *)(hwProgram + 0x18);
    if (0x100 < instCount + 2U) {
      *(undefined1 *)(shader + 4) = 0;
      instCount = *(int *)(hwProgram + 0x18);
      if (*(uint *)(hwProgram + 0x20) < instCount + 2U) {
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
    tempSlot = extvsAllocTempSlot(ctx,shader);
    operandAKind = 3;
    operandAFlag = 0;
    operandASelW = 1;
    operandASelX = 1;
    operandASelY = 1;
    operandASelZ = 1;
    operandAIndex = tempSlot;
    extvsEncodeSourceOperand(ctx,shader,&operandAKind,instSlot,3,0,0);
    extvsEncodeSourceSwizzle(shader,symbolList,src0Operand,instSlot + 4,0);
    swizzleWord = *(uint *)(instSlot + 4) & 0xfe001fff | 0x1248000;
    *(uint *)(instSlot + 0xc) = swizzleWord;
    *(uint *)(instSlot + 8) = swizzleWord;
    extvsEncodeSourceOperand(ctx,shader,instRecord + 4,instSlot + 0x10,5,0,0);
    operandBKind = 3;
    operandBFlag = 0;
    operandBSelX = 0x87d5;
    operandBSelY = 0x87d6;
    operandBSelZ = 0x87d7;
    operandBSelW = 0x87d8;
    operandBIndex = tempSlot;
    extvsEncodeSourceSwizzle(shader,symbolList,&operandBKind,instSlot + 0x14,0);
    extvsEncodeSourceSwizzle(shader,symbolList,src1Operand,instSlot + 0x18,0);
    emittedInstCount = 2;
    *(undefined4 *)(instSlot + 0x1c) = *(undefined4 *)(instSlot + 0x18);
  }
  return emittedInstCount;
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
  int instSlot;
  int hwProgramLocal;
  undefined4 emittedInstCount;
  undefined4 newInstArray;
  short fogMode;
  undefined4 fogParamRegister;
  int hwProgram;
  int *symbolList;
  int glStateExt;
  int instCount;
  undefined4 operandAKind;
  uint operandAIndex;
  undefined4 operandASelX;
  undefined4 operandASelY;
  undefined4 operandASelZ;
  uint operandASelW;
  undefined1 operandAFlag;
  undefined4 operandBKind;
  uint operandBIndex;
  undefined4 operandBSelX;
  undefined4 operandBSelY;
  undefined4 operandBSelZ;
  undefined4 operandBSelW;
  undefined1 operandBFlag;
  undefined4 operandCKind;
  undefined4 operandCIndex;
  undefined4 operandCSelX;
  undefined4 operandCSelY;
  undefined4 operandCSelZ;
  undefined4 operandCSelW;
  undefined1 operandCFlag;
  
  glStateExt = *(int *)(*(int *)(ctx + 4) + 0x10);
  hwProgram = **(int **)(*(int *)(((unsigned char *)0x0000118c) + ctx) * 4 + *shader);
  fogParamRegister = *(undefined4 *)(hwProgram + 0x60);
  operandAIndex = extvsAllocTempSlot(ctx,shader);
  *instRecord = (operandAIndex & 0x7f) << 0xd | *instRecord & 0xfff010ff | 0x100000;
  fogMode = *(short *)(((unsigned char *)0x00002e04) + glStateExt);
  operandBIndex = operandAIndex;
  operandCIndex = fogParamRegister;
  if (fogMode == 0x801) {
    hwProgramLocal = **(int **)(*(int *)(((unsigned char *)0x0000118c) + ctx) * 4 + *shader);
    instCount = *(int *)(hwProgramLocal + 0x18);
    if (0x100 < instCount + 3U) {
      *(undefined1 *)(shader + 4) = 0;
      instCount = *(int *)(hwProgramLocal + 0x18);
      if (*(uint *)(hwProgramLocal + 0x20) < instCount + 3U) {
        newInstArray = (**(code **)(ctx + 0xc))(*(uint *)(hwProgramLocal + 0x20) * 0x10 + 0x100);
        (**(code **)(((unsigned char *)0x00001344) + ctx))
                  (newInstArray,*(undefined4 *)(hwProgramLocal + 0x1c),*(int *)(hwProgramLocal + 0x20) << 4);
        (**(code **)(ctx + 0x18))(*(undefined4 *)(hwProgramLocal + 0x1c));
        *(undefined4 *)(hwProgramLocal + 0x1c) = newInstArray;
        instCount = *(int *)(hwProgramLocal + 0x18);
        *(int *)(hwProgramLocal + 0x20) = *(int *)(hwProgramLocal + 0x20) + 0x10;
      }
    }
    operandASelY = 0;
    operandASelZ = 0;
    operandASelW = 0;
    operandAFlag = 0;
    operandAKind = 3;
    instSlot = instCount * 0x10 + *(int *)(hwProgramLocal + 0x1c);
    operandASelX = 1;
    symbolList = shader + 7;
    extvsEncodeSourceOperand(ctx,shader,&operandAKind,instSlot,2,0,0);
    operandBKind = 3;
    operandBFlag = 0;
    operandBSelW = 0x87d5;
    operandBSelX = 0x87d5;
    operandBSelY = 0x87d5;
    operandBSelZ = 0x87d5;
    extvsEncodeSourceSwizzle(shader,symbolList,&operandBKind,instSlot + 4,0);
    extvsEncodeSourceSwizzle(shader,symbolList,&operandBKind,instSlot + 8,0);
    *(undefined4 *)(instSlot + 0xc) = *(undefined4 *)(instSlot + 8);
    extvsEncodeSourceOperand(ctx,shader,&operandAKind,instSlot + 0x10,2,0,0);
    extvsEncodeSourceSwizzle(shader,symbolList,&operandBKind,instSlot + 0x14,0);
    operandCFlag = 0;
    operandCKind = 4;
    operandCSelW = 0x87d7;
    operandCSelX = 0x87d7;
    operandCSelY = 0x87d7;
    operandCSelZ = 0x87d7;
    extvsEncodeSourceSwizzle(shader,symbolList,&operandCKind,instSlot + 0x18,0);
    *(undefined4 *)(instSlot + 0x1c) = *(undefined4 *)(instSlot + 0x18);
    operandAKind = 1;
    operandAIndex = 0x87bd;
    operandASelX = 0;
    operandASelY = 0;
    operandASelZ = 0;
    operandASelW = (uint)*(byte *)(hwProgram + 0x42);
    operandAFlag = 0;
    extvsEncodeSourceOperand(ctx,shader,&operandAKind,instSlot + 0x20,3,1,0);
    extvsEncodeSourceSwizzle(shader,symbolList,&operandBKind,instSlot + 0x24,0);
    emittedInstCount = 3;
    *(undefined4 *)(instSlot + 0x2c) = *(undefined4 *)(instSlot + 0x24);
    *(undefined4 *)(instSlot + 0x28) = *(undefined4 *)(instSlot + 0x24);
  }
  else if (fogMode == 0x2601) {
    hwProgramLocal = **(int **)(*(int *)(((unsigned char *)0x0000118c) + ctx) * 4 + *shader);
    instCount = *(int *)(hwProgramLocal + 0x18);
    if (0x100 < instCount + 1U) {
      *(undefined1 *)(shader + 4) = 0;
      instCount = *(int *)(hwProgramLocal + 0x18);
      if (*(uint *)(hwProgramLocal + 0x20) < instCount + 1U) {
        newInstArray = (**(code **)(ctx + 0xc))(*(uint *)(hwProgramLocal + 0x20) * 0x10 + 0x100);
        (**(code **)(((unsigned char *)0x00001344) + ctx))
                  (newInstArray,*(undefined4 *)(hwProgramLocal + 0x1c),*(int *)(hwProgramLocal + 0x20) << 4);
        (**(code **)(ctx + 0x18))(*(undefined4 *)(hwProgramLocal + 0x1c));
        *(undefined4 *)(hwProgramLocal + 0x1c) = newInstArray;
        instCount = *(int *)(hwProgramLocal + 0x18);
        *(int *)(hwProgramLocal + 0x20) = *(int *)(hwProgramLocal + 0x20) + 0x10;
      }
    }
    operandASelX = 0;
    operandASelY = 0;
    operandAKind = 1;
    operandASelZ = 0;
    operandAIndex = 0x87bd;
    instSlot = instCount * 0x10 + *(int *)(hwProgramLocal + 0x1c);
    operandASelW = (uint)*(byte *)(hwProgram + 0x42);
    operandAFlag = 0;
    extvsEncodeSourceOperand(ctx,shader,&operandAKind,instSlot,1,0,0);
    operandBSelX = 0x87dd;
    operandBSelW = 0x87dd;
    operandBFlag = 0;
    operandBSelY = 0x87de;
    operandBKind = 3;
    operandBSelZ = 0x87d5;
    extvsEncodeSourceSwizzle(shader,shader + 7,&operandBKind,instSlot + 4,0);
    operandCSelW = 0x87dd;
    operandCFlag = 0;
    operandCSelX = 0x87dd;
    operandCSelY = 0x87d6;
    operandCSelZ = 0x87d7;
    operandCKind = 4;
    extvsEncodeSourceSwizzle(shader,shader + 7,&operandCKind,instSlot + 8,0);
    emittedInstCount = 1;
    *(undefined4 *)(instSlot + 0xc) = *(undefined4 *)(instSlot + 8);
  }
  else {
    emittedInstCount = 0;
    if (fogMode == 0x800) {
      hwProgramLocal = **(int **)(*(int *)(((unsigned char *)0x0000118c) + ctx) * 4 + *shader);
      instCount = *(int *)(hwProgramLocal + 0x18);
      if (0x100 < instCount + 2U) {
        *(undefined1 *)(shader + 4) = 0;
        instCount = *(int *)(hwProgramLocal + 0x18);
        if (*(uint *)(hwProgramLocal + 0x20) < instCount + 2U) {
          newInstArray = (**(code **)(ctx + 0xc))(*(uint *)(hwProgramLocal + 0x20) * 0x10 + 0x100);
          (**(code **)(((unsigned char *)0x00001344) + ctx))
                    (newInstArray,*(undefined4 *)(hwProgramLocal + 0x1c),*(int *)(hwProgramLocal + 0x20) << 4);
          (**(code **)(ctx + 0x18))(*(undefined4 *)(hwProgramLocal + 0x1c));
          *(undefined4 *)(hwProgramLocal + 0x1c) = newInstArray;
          instCount = *(int *)(hwProgramLocal + 0x18);
          *(int *)(hwProgramLocal + 0x20) = *(int *)(hwProgramLocal + 0x20) + 0x10;
        }
      }
      operandASelY = 0;
      operandASelZ = 0;
      operandASelW = 0;
      operandAFlag = 0;
      operandAKind = 3;
      instSlot = instCount * 0x10 + *(int *)(hwProgramLocal + 0x1c);
      operandASelX = 1;
      symbolList = shader + 7;
      extvsEncodeSourceOperand(ctx,shader,&operandAKind,instSlot,2,0,0);
      operandBKind = 3;
      operandBFlag = 0;
      operandBSelW = 0x87d5;
      operandBSelX = 0x87d5;
      operandBSelY = 0x87d5;
      operandBSelZ = 0x87d5;
      extvsEncodeSourceSwizzle(shader,symbolList,&operandBKind,instSlot + 4,0);
      operandCFlag = 0;
      operandCKind = 4;
      operandCSelW = 0x87d7;
      operandCSelX = 0x87d7;
      operandCSelY = 0x87d7;
      operandCSelZ = 0x87d7;
      extvsEncodeSourceSwizzle(shader,symbolList,&operandCKind,instSlot + 8,0);
      *(undefined4 *)(instSlot + 0xc) = *(undefined4 *)(instSlot + 8);
      operandAKind = 1;
      operandAIndex = 0x87bd;
      operandASelX = 0;
      operandASelY = 0;
      operandASelZ = 0;
      operandASelW = (uint)*(byte *)(hwProgram + 0x42);
      operandAFlag = 0;
      extvsEncodeSourceOperand(ctx,shader,&operandAKind,instSlot + 0x10,3,1,0);
      extvsEncodeSourceSwizzle(shader,symbolList,&operandBKind,instSlot + 0x14,0);
      emittedInstCount = 2;
      *(undefined4 *)(instSlot + 0x1c) = *(undefined4 *)(instSlot + 0x14);
      *(undefined4 *)(instSlot + 0x18) = *(undefined4 *)(instSlot + 0x14);
    }
  }
  return emittedInstCount;
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

/* extvsRewriteHardwareInstructions @ 0x5f540 (688 bytes) */
int extvsRewriteHardwareInstructions(ctx, shader)
  int ctx;
  int *shader;
{
  uint instIndex;
  uint instWord0;
  uint *instCursor;
  int newInstArray;
  undefined4 *buildJob;
  int buildStatus;
  uint srcIndex0;
  undefined4 oldInstCount;
  uint srcIndex2;
  uint scanIndex;
  uint srcIndex1;
  int hwProgram;
  uint uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 auStack_2c [3];
  
  hwProgram = **(int **)(*(int *)(((unsigned char *)0x0000118c) + ctx) * 4 + *shader);
  if (*(char *)(shader + 4) != '\0') {
    newInstArray = (**(code **)(ctx + 0xc))(*(int *)(hwProgram + 0x18) << 4);
    buildJob = (undefined4 *)
             FUN_000774c0(*(undefined4 *)(ctx + 0xc),*(undefined4 *)(ctx + 0x18));
    buildJob[8] = 0;
    buildJob[9] = 0;
    buildJob[3] = 0x20;
    *buildJob = 0x460;
    buildJob[1] = *(undefined4 *)(hwProgram + 0x1c);
    oldInstCount = *(undefined4 *)(hwProgram + 0x18);
    buildJob[7] = &uStack_38;
    buildJob[10] = &uStack_34;
    buildJob[6] = newInstArray;
    buildJob[0xb] = &uStack_30;
    buildJob[2] = oldInstCount;
    buildJob[0xc] = auStack_2c;
    buildStatus = recordProgramBuildDependencies(buildJob);
    FUN_0007a110(buildJob);
    (**(code **)(ctx + 0x18))(*(undefined4 *)(hwProgram + 0x1c));
    *(int *)(hwProgram + 0x1c) = newInstArray;
    if (buildStatus == 0) {
      *(uint *)(hwProgram + 0x18) = uStack_38;
      shader[0x15] = uStack_38;
      *(undefined4 *)(hwProgram + 8) = uStack_34;
      *(undefined4 *)(hwProgram + 0xc) = uStack_30;
      *(undefined4 *)(hwProgram + 0x2ac) = auStack_2c[0];
    }
    else {
      *(undefined4 *)(hwProgram + 0xc) = 0;
      if (uStack_38 != 0) {
        scanIndex = uStack_38;
        newInstArray = uStack_38 * 0x10 + newInstArray;
        do {
          if ((((*(uint *)(newInstArray + -0xc) & 7) == 1) || ((*(uint *)(newInstArray + -8) & 7) == 1)) ||
             ((*(uint *)(newInstArray + -4) & 7) == 1)) {
            *(uint *)(hwProgram + 0xc) = scanIndex - 1;
          }
          scanIndex = scanIndex - 1;
        } while ((scanIndex != 0) && (newInstArray = newInstArray + -0x10, *(int *)(hwProgram + 0xc) == 0));
      }
    }
    instCursor = *(uint **)(hwProgram + 0x1c);
    if (uStack_38 != 0) {
      instIndex = 0;
      do {
        instWord0 = *instCursor;
        if ((instWord0 & 0x3f) == 4) {
          if ((((instCursor[1] & 7) == 0) && ((instCursor[2] & 7) == 0)) && ((instCursor[3] & 7) == 0)) {
            srcIndex0 = instCursor[1] >> 5 & 0xff;
            srcIndex1 = instCursor[2] >> 5 & 0xff;
            if (((srcIndex0 != srcIndex1) && (srcIndex2 = instCursor[3] >> 5 & 0xff, srcIndex0 != srcIndex2)) &&
               (srcIndex1 != srcIndex2)) {
              *instCursor = instWord0 & 0xffffffc0 | 0x80;
            }
          }
        }
        else if ((((instWord0 & 0x3f) == 0xb) && ((instCursor[1] & 7) == 0)) &&
                (((instCursor[2] & 7) == 0 && ((instCursor[3] & 7) == 0)))) {
          srcIndex0 = instCursor[1] >> 5 & 0xff;
          srcIndex1 = instCursor[2] >> 5 & 0xff;
          if (((srcIndex0 != srcIndex1) && (srcIndex2 = instCursor[3] >> 5 & 0xff, srcIndex0 != srcIndex2)) &&
             (srcIndex1 != srcIndex2)) {
            *instCursor = instWord0 & 0xffffffc0 | 0x81;
          }
        }
        instIndex = instIndex + 1;
        instCursor = instCursor + 4;
      } while (instIndex < uStack_38);
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
int vpUploadConstantsWithFog(glContext, shader, programState, constantBlock, uploadAll)
  int glContext;
  int shader;
  int programState;
  int constantBlock;
  int uploadAll;
{
  int cmdEnd;
  int glStateExt;
  short fogMode;
  code *commitCallback;
  int fogConstant;
  undefined4 *cmdBuffer;
  int constantCount;
  int fogSlot;
  
  constantCount = *(int *)(programState + 0x5c);
  if (constantCount == 0) {
    return;
  }
  if ((*(char *)(shader + 0x7a) == '\0') || ((*(uint *)(glContext + 0x44) & 0x1000000) == 0)) {
    if (uploadAll == 0) {
      return;
    }
  }
  else {
    fogSlot = *(int *)(programState + 0x60);
    glStateExt = *(int *)(*(int *)(glContext + 4) + 0x10);
    fogMode = *(short *)(((unsigned char *)0x00002e04) + glStateExt);
    if (fogMode == 0x801) {
      fogConstant = constantBlock + fogSlot * 0x10;
      *(undefined4 *)(fogConstant + 4) = 0;
      *(float *)(fogConstant + 8) =
           -(*(float *)(((unsigned char *)0x00002df0) + glStateExt) * *(float *)(((unsigned char *)0x00002df0) + glStateExt));
    }
    else if (fogMode == 0x2601) {
      fogConstant = constantBlock + fogSlot * 0x10;
      *(float *)(fogConstant + 4) = *(float *)(((unsigned char *)0x00002df8) + glStateExt) * *(float *)(((unsigned char *)0x00002dfc) + glStateExt);
      *(float *)(fogConstant + 8) = -*(float *)(((unsigned char *)0x00002dfc) + glStateExt);
    }
    else if (fogMode == 0x800) {
      fogConstant = constantBlock + fogSlot * 0x10;
      *(undefined4 *)(fogConstant + 4) = 0;
      *(float *)(fogConstant + 8) = -*(float *)(((unsigned char *)0x00002df0) + glStateExt);
    }
    if (uploadAll == 0) {
      cmdBuffer = (undefined4 *)(**(code **)(glContext + 0x2758))(glContext,7);
      *(undefined4 **)(0x00002748 + glContext + 4) = cmdBuffer;
      *cmdBuffer = 0x880;
      cmdEnd = constantBlock + fogSlot * 0x10;
      *(int *)(*(int *)(0x00002748 + glContext + 4) + 4) =
           fogSlot + *(int *)(glContext + 0x2448) + *(int *)(programState + 0x14);
      *(undefined4 *)(*(int *)(0x00002748 + glContext + 4) + 8) = 0x38882;
      *(undefined4 *)(*(int *)(0x00002748 + glContext + 4) + 0xc) =
           *(undefined4 *)(constantBlock + fogSlot * 0x10);
      *(undefined4 *)(*(int *)(0x00002748 + glContext + 4) + 0x10) = *(undefined4 *)(cmdEnd + 4);
      *(undefined4 *)(*(int *)(0x00002748 + glContext + 4) + 0x14) = *(undefined4 *)(cmdEnd + 8);
      *(undefined4 *)(*(int *)(0x00002748 + glContext + 4) + 0x18) = *(undefined4 *)(cmdEnd + 0xc);
      commitCallback = *(code **)(glContext + 0x275c);
      constantCount = *(int *)(0x00002748 + glContext + 4) + 0x1c;
      *(int *)(0x00002748 + glContext + 4) = constantCount;
      goto LAB_000620ec;
    }
    constantCount = *(int *)(programState + 0x5c);
  }
  cmdBuffer = (undefined4 *)(**(code **)(glContext + 0x2758))(glContext,constantCount * 4 + 3);
  *(undefined4 **)(0x00002748 + glContext + 4) = cmdBuffer;
  *cmdBuffer = 0x880;
  *(int *)(*(int *)(0x00002748 + glContext + 4) + 4) =
       *(int *)(glContext + 0x2448) + *(int *)(programState + 0x14);
  *(uint *)(*(int *)(0x00002748 + glContext + 4) + 8) = (constantCount * 4 + -1) * 0x10000 | 0x8882;
  _memcpy(*(int *)(0x00002748 + glContext + 4) + 0xc,constantBlock,constantCount * 0x10);
  commitCallback = *(code **)(glContext + 0x275c);
  constantCount = constantCount * 0x10 + *(int *)(0x00002748 + glContext + 4) + 0xc;
  *(int *)(0x00002748 + glContext + 4) = constantCount;
LAB_000620ec:
                    
                    
  (*commitCallback)(glContext,constantCount);
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
int extvsStateCacheCreate(ctx, shader, slotIndex)
  int ctx;
  int *shader;
  uint slotIndex;
{
  int clearCount;
  undefined4 constSlotArray;
  undefined4 tempSlotArray;
  undefined1 *clearBytePtr;
  int *shaderFlagPtr;
  undefined4 *clearPtr;
  undefined1 *programState;
  undefined4 instArray;
  int hwSlotArray;
  undefined4 *slotEntry;
  uint endSlot;
  int slotByteOffset;
  
  if (slotIndex == 0xffffffff) {
    slotIndex = 0;
    endSlot = *(uint *)(*(int *)(((unsigned char *)0x0000116c) + ctx) + 0x10);
  }
  else {
    endSlot = slotIndex + 1;
  }
  slotByteOffset = slotIndex << 2;
  do {
    programState = (undefined1 *)(**(code **)(ctx + 0xc))(700);
    *programState = 0;
    *(undefined4 *)(programState + 4) = 0;
    *(undefined4 *)(programState + 8) = 0;
    *(undefined4 *)(programState + 0xc) = 0;
    *(undefined4 *)(programState + 0x10) = 0;
    *(undefined4 *)(programState + 0x14) = 0;
    *(undefined4 *)(programState + 0x18) = 0;
    instArray = (**(code **)(ctx + 0xc))(0x1000);
    *(undefined4 *)(programState + 0x20) = 0x100;
    *(undefined4 *)(programState + 0x1c) = instArray;
    hwSlotArray = (**(code **)(ctx + 0x10))(0x16,0x28);
    *(int *)(programState + 0x24) = hwSlotArray;
    *(undefined4 *)(programState + 0x28) = 0x16;
    *(undefined1 *)(hwSlotArray + 0x10) = 1;
    programState[0x2c] = 0;
    programState[0x2d] = 0;
    clearCount = 8;
    clearBytePtr = programState;
    do {
      clearBytePtr[0x2e] = 0;
      clearBytePtr = clearBytePtr + 1;
      clearCount = clearCount + -1;
    } while (clearCount != 0);
    clearCount = 8;
    clearBytePtr = programState;
    do {
      clearBytePtr[0x36] = 0;
      clearBytePtr = clearBytePtr + 1;
      clearCount = clearCount + -1;
    } while (clearCount != 0);
    programState[0x3e] = 0;
    programState[0x3f] = 0;
    programState[0x40] = 0;
    programState[0x41] = 0;
    clearCount = 4;
    *(undefined1 *)(shader + 0x1b) = 0;
    shaderFlagPtr = shader;
    do {
      *(undefined1 *)((int)shaderFlagPtr + 0x6d) = 0;
      shaderFlagPtr = (int *)((int)shaderFlagPtr + 1);
      clearCount = clearCount + -1;
    } while (clearCount != 0);
    clearCount = 8;
    shaderFlagPtr = shader;
    do {
      *(undefined1 *)((int)shaderFlagPtr + 0x71) = 0;
      shaderFlagPtr = (int *)((int)shaderFlagPtr + 1);
      clearCount = clearCount + -1;
    } while (clearCount != 0);
    *(undefined1 *)((int)shader + 0x7a) = 0;
    *(undefined1 *)((int)shader + 0x79) = 0;
    programState[0x44] = 0;
    programState[0x42] = 0;
    programState[0x43] = 0;
    *(undefined4 *)(programState + 0x48) = 0;
    tempSlotArray = (**(code **)(ctx + 0x10))(0x20,0x28);
    *(undefined4 *)(programState + 0x4c) = tempSlotArray;
    *(undefined4 *)(programState + 0x50) = 0x20;
    constSlotArray = (**(code **)(ctx + 0x10))(0x100,0x28);
    programState[0x2b0] = 0;
    *(undefined4 *)(programState + 0x58) = 0x100;
    *(undefined4 *)(programState + 0x54) = constSlotArray;
    *(undefined4 *)(programState + 0x5c) = 0;
    *(undefined4 *)(programState + 0x74) = 0;
    *(undefined4 *)(programState + 0x220) = 0;
    *(undefined4 *)(programState + 0x224) = 0;
    *(undefined4 *)(programState + 0x228) = 0;
    *(undefined4 *)(programState + 0x22c) = 0;
    *(undefined4 *)(programState + 0x230) = 0;
    *(undefined4 *)(programState + 0x2a4) = 0;
    *(undefined4 *)(programState + 0x2a8) = 0;
    *(undefined4 *)(programState + 0x2ac) = 0;
    *(undefined4 *)(programState + 0x2b4) = 0;
    slotEntry = *(undefined4 **)(*shader + slotByteOffset);
    if (slotEntry == (undefined4 *)0x0) {
      slotEntry = (undefined4 *)(**(code **)(ctx + 0xc))(0x90);
      clearCount = 0x20;
      clearPtr = slotEntry;
      do {
        clearPtr = clearPtr + 1;
        *clearPtr = 0;
        clearCount = clearCount + -1;
      } while (clearCount != 0);
      slotEntry[0x23] = 0;
      slotEntry[0x21] = 0;
      slotEntry[0x22] = 0;
      *(undefined4 **)(*shader + slotByteOffset) = slotEntry;
    }
    slotIndex = slotIndex + 1;
    *slotEntry = programState;
    slotByteOffset = slotByteOffset + 4;
  } while (slotIndex < endSlot);
  return;
}

/* extvsStateCacheFreeAll @ 0x627e4 (328 bytes) */
int extvsStateCacheFreeAll(ctx, slotTablePtr, freeEverything)
  int ctx;
  int *slotTablePtr;
  int freeEverything;
{
  int chainIndex;
  int *nextChainHead;
  bool moreChains;
  uint endSlot;
  int *chainHead;
  int slotTable;
  int chainEntry;
  uint firstSlot;
  int loopIndex;
  int slotByteOffset;
  int *slotEntry;
  
  slotTable = *slotTablePtr;
  if (slotTable != 0) {
    if (freeEverything == 0) {
      firstSlot = *(uint *)(((unsigned char *)0x0000118c) + ctx);
      endSlot = firstSlot + 1;
    }
    else {
      firstSlot = 0;
      endSlot = *(uint *)(*(int *)(((unsigned char *)0x0000116c) + ctx) + 0x10);
    }
    if (firstSlot < endSlot) {
      slotByteOffset = firstSlot << 2;
      loopIndex = 0;
      while( true ) {
        slotEntry = *(int **)(slotTable + slotByteOffset);
        if (slotEntry != (int *)0x0) {
          if (*(char *)(*slotEntry + 0x2b0) == '\0') {
            ((int (*)())extvsStateFree)(ctx,*slotEntry);
            *slotEntry = 0;
          }
          if (freeEverything != 0) {
            chainIndex = 0;
            chainHead = slotEntry;
            do {
              nextChainHead = chainHead + 1;
              chainHead = chainHead + 1;
              chainEntry = *nextChainHead;
              while (chainEntry != 0) {
                *chainHead = *(int *)(chainEntry + 0x2b4);
                ((int (*)())extvsStateFree)(ctx,chainEntry);
                chainEntry = *chainHead;
              }
              moreChains = chainIndex != 0x1f;
              chainIndex = chainIndex + 1;
            } while (moreChains);
            if (slotEntry[0x22] != 0) {
              (**(code **)(ctx + 0x18))(slotEntry[0x22]);
            }
            (**(code **)(ctx + 0x18))(slotEntry);
            *(undefined4 *)(*slotTablePtr + slotByteOffset) = 0;
          }
        }
        loopIndex = loopIndex + 1;
        slotByteOffset = slotByteOffset + 4;
        if (loopIndex == endSlot - firstSlot) break;
        slotTable = *slotTablePtr;
      }
    }
  }
  return;
}

/* extvsUploadSingleConstant @ 0x62940 (276 bytes) */
int extvsUploadSingleConstant(glContext, shader, symbol)
  int glContext;
  int *shader;
  int symbol;
{
  int cmdBase;
  undefined4 valueW;
  undefined4 valueY;
  undefined4 valueX;
  undefined4 uVar1;
  int constantAddr;
  int slotByteOffset;
  undefined4 *cmdBuffer;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 valueZ;
  int *hwProgramSlot;
  code *commitCallback;
  int programState;
  undefined4 *values;
  
  values = *(undefined4 **)(symbol + 0x38);
  valueZ = values[2];
  valueW = values[3];
  slotByteOffset = *(int *)(symbol + 4) * 0x10;
  hwProgramSlot = *(int **)(*(int *)(((unsigned char *)0x0000118c) + glContext) * 4 + *shader);
  valueX = *values;
  valueY = values[1];
  programState = *hwProgramSlot;
  constantAddr = slotByteOffset + hwProgramSlot[0x22];
  *(undefined4 *)(slotByteOffset + hwProgramSlot[0x22]) = valueX;
  *(undefined4 *)(constantAddr + 0xc) = valueW;
  *(undefined4 *)(constantAddr + 8) = valueZ;
  *(undefined4 *)(constantAddr + 4) = valueY;
  cmdBuffer = (undefined4 *)(**(code **)(glContext + 0x2758))(glContext,9,symbol,valueY,valueX,valueZ,slotByteOffset,hwProgramSlot);
  *(undefined4 **)(0x00002748 + glContext + 4) = cmdBuffer;
  *cmdBuffer = 0x8a1;
  *(undefined4 *)(*(int *)(0x00002748 + glContext + 4) + 4) = 0;
  *(undefined4 *)(*(int *)(0x00002748 + glContext + 4) + 8) = 0x880;
  *(int *)(*(int *)(0x00002748 + glContext + 4) + 0xc) =
       *(int *)(glContext + 0x2448) + *(int *)(programState + 0x14) + *(int *)(symbol + 4);
  *(undefined4 *)(*(int *)(0x00002748 + glContext + 4) + 0x10) = 0x38882;
  uVar1 = *values;
  cmdBase = *(int *)(0x00002748 + glContext + 4);
  uVar5 = values[1];
  uVar6 = values[2];
  *(undefined4 *)(cmdBase + 0x20) = values[3];
  *(undefined4 *)(cmdBase + 0x14) = uVar1;
  *(undefined4 *)(cmdBase + 0x18) = uVar5;
  *(undefined4 *)(cmdBase + 0x1c) = uVar6;
  commitCallback = *(code **)(glContext + 0x275c);
  *(int *)(0x00002748 + glContext + 4) = *(int *)(0x00002748 + glContext + 4) + 0x24;
                    
                    
  (*commitCallback)(glContext,*(int *)(0x00002748 + glContext + 4));
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
  int totalStreamCount;
  int streamWordOffset;
  int streamWordAddr;
  uint fieldValue;
  uint fieldShift;
  uint shaderOutputMask;
  bool streamInLowHalf;
  byte outputFlags;
  bool firstStreamHighHalf;
  int componentCount;
  int programState;
  uint streamCount;
  uint descriptorWordIndex;
  int inputTable;
  int outputsLeft;
  
  programState = **(int **)(*(int *)(((unsigned char *)0x0000118c) + ctx) * 4 + *shader);
  *(undefined4 *)(programState + 0x29c) = 0;
  *(undefined4 *)(programState + 0x240) = 0;
  *(undefined4 *)(programState + 0x23c) = 1;
  *(undefined4 *)(programState + 0x2a0) = 1;
  *(undefined4 *)(programState + 0x238) = 4;
  *(undefined4 *)(programState + 0x2a8) = 1;
  inputTable = *(int *)(programState + 0x24);
  *(uint *)(programState + 0x244) = *(uint *)(programState + 0x244) & 0xffff0000 | 3;
  *(uint *)(programState + 0x270) = *(uint *)(programState + 0x270) & 0xffff0000 | 0xf688;
  streamInLowHalf = *(char *)(inputTable + 0x38) != '\0';
  if (streamInLowHalf) {
    *(undefined4 *)(programState + 0x2a0) = 2;
    *(undefined4 *)(programState + 0x238) = 8;
    *(undefined4 *)(programState + 0x244) = 0x1030003;
    *(undefined4 *)(programState + 0x270) = 0xf688f688;
  }
  firstStreamHighHalf = !streamInLowHalf;
  descriptorWordIndex = (uint)streamInLowHalf;
  streamInLowHalf = firstStreamHighHalf;
  if (*(char *)(inputTable + 0x60) != '\0') {
    streamInLowHalf = !firstStreamHighHalf;
    *(uint *)(programState + 0x238) =
         (*(uint *)(programState + 0x238) & 0x7f) + 4 & 0x7f | *(uint *)(programState + 0x238) & 0xffffff80;
    if (streamInLowHalf) {
      streamWordAddr = descriptorWordIndex * 4 + programState;
      *(uint *)(streamWordAddr + 0x244) = *(uint *)(streamWordAddr + 0x244) & 0xffff0000 | 0x203;
      *(uint *)(streamWordAddr + 0x270) = (uint)firstStreamHighHalf | *(uint *)(streamWordAddr + 0x270) & 0xffff0000 | 0xf688;
    }
    else {
      streamWordOffset = descriptorWordIndex * 4;
      descriptorWordIndex = descriptorWordIndex + 1;
      streamWordOffset = streamWordOffset + programState;
      *(uint *)(streamWordOffset + 0x244) = *(uint *)(streamWordOffset + 0x244) & 0xffff | 0x2030000;
      *(uint *)(streamWordOffset + 0x270) = *(uint *)(streamWordOffset + 0x270) & 0xffff | 0xf6880000;
    }
    inputTable = *(int *)(programState + 0x24);
    *(int *)(programState + 0x2a0) = *(int *)(programState + 0x2a0) + 1;
  }
  if (*(char *)(inputTable + 0x88) != '\0') {
    streamInLowHalf = !streamInLowHalf;
    *(uint *)(programState + 0x238) =
         (*(uint *)(programState + 0x238) & 0x7f) + 4 & 0x7f | *(uint *)(programState + 0x238) & 0xffffff80;
    if (streamInLowHalf) {
      streamWordAddr = descriptorWordIndex * 4 + programState;
      *(uint *)(streamWordAddr + 0x244) = *(uint *)(streamWordAddr + 0x244) & 0xffff0000 | 0x303;
      *(uint *)(streamWordAddr + 0x270) = *(uint *)(streamWordAddr + 0x270) & 0xffff0000 | 0xf688;
    }
    else {
      streamWordOffset = descriptorWordIndex * 4;
      descriptorWordIndex = descriptorWordIndex + 1;
      streamWordOffset = streamWordOffset + programState;
      *(uint *)(streamWordOffset + 0x244) = *(uint *)(streamWordOffset + 0x244) & 0xffff | 0x3030000;
      *(uint *)(streamWordOffset + 0x270) = *(uint *)(streamWordOffset + 0x270) & 0xffff | 0xf6880000;
    }
    inputTable = *(int *)(programState + 0x24);
    *(int *)(programState + 0x2a0) = *(int *)(programState + 0x2a0) + 1;
  }
  if (*(char *)(inputTable + 0xb0) != '\0') {
    streamInLowHalf = !streamInLowHalf;
    *(uint *)(programState + 0x238) =
         (*(uint *)(programState + 0x238) & 0x7f) + 4 & 0x7f | *(uint *)(programState + 0x238) & 0xffffff80;
    if (streamInLowHalf) {
      streamWordAddr = descriptorWordIndex * 4 + programState;
      *(uint *)(streamWordAddr + 0x244) = *(uint *)(streamWordAddr + 0x244) & 0xffff0000 | 0x403;
      *(uint *)(streamWordAddr + 0x270) = *(uint *)(streamWordAddr + 0x270) & 0xffff0000 | 0xf688;
    }
    else {
      streamWordOffset = descriptorWordIndex * 4;
      descriptorWordIndex = descriptorWordIndex + 1;
      streamWordOffset = streamWordOffset + programState;
      *(uint *)(streamWordOffset + 0x244) = *(uint *)(streamWordOffset + 0x244) & 0xffff | 0x4030000;
      *(uint *)(streamWordOffset + 0x270) = *(uint *)(streamWordOffset + 0x270) & 0xffff | 0xf6880000;
    }
    inputTable = *(int *)(programState + 0x24);
    *(int *)(programState + 0x2a0) = *(int *)(programState + 0x2a0) + 1;
  }
  if (*(char *)(inputTable + 0xd8) != '\0') {
    streamInLowHalf = !streamInLowHalf;
    *(uint *)(programState + 0x238) =
         (*(uint *)(programState + 0x238) & 0x7f) + 4 & 0x7f | *(uint *)(programState + 0x238) & 0xffffff80;
    if (streamInLowHalf) {
      streamWordAddr = descriptorWordIndex * 4 + programState;
      *(uint *)(streamWordAddr + 0x244) = *(uint *)(streamWordAddr + 0x244) & 0xffff0000 | 0x503;
      *(uint *)(streamWordAddr + 0x270) = *(uint *)(streamWordAddr + 0x270) & 0xffff0000 | 0xf688;
    }
    else {
      streamWordOffset = descriptorWordIndex * 4;
      descriptorWordIndex = descriptorWordIndex + 1;
      streamWordOffset = streamWordOffset + programState;
      *(uint *)(streamWordOffset + 0x244) = *(uint *)(streamWordOffset + 0x244) & 0xffff | 0x5030000;
      *(uint *)(streamWordOffset + 0x270) = *(uint *)(streamWordOffset + 0x270) & 0xffff | 0xf6880000;
    }
    inputTable = *(int *)(programState + 0x24);
    *(int *)(programState + 0x2a0) = *(int *)(programState + 0x2a0) + 1;
  }
  if (*(char *)(inputTable + 0x100) != '\0') {
    streamInLowHalf = !streamInLowHalf;
    *(uint *)(programState + 0x238) =
         (*(uint *)(programState + 0x238) & 0x7f) + 4 & 0x7f | *(uint *)(programState + 0x238) & 0xffffff80;
    if (streamInLowHalf) {
      streamWordAddr = descriptorWordIndex * 4 + programState;
      *(uint *)(streamWordAddr + 0x244) = *(uint *)(streamWordAddr + 0x244) & 0xffff0000 | 0x603;
      *(uint *)(streamWordAddr + 0x270) = *(uint *)(streamWordAddr + 0x270) & 0xffff0000 | 0xf688;
    }
    else {
      streamWordOffset = descriptorWordIndex * 4;
      descriptorWordIndex = descriptorWordIndex + 1;
      streamWordOffset = streamWordOffset + programState;
      *(uint *)(streamWordOffset + 0x244) = *(uint *)(streamWordOffset + 0x244) & 0xffff | 0x6030000;
      *(uint *)(streamWordOffset + 0x270) = *(uint *)(streamWordOffset + 0x270) & 0xffff | 0xf6880000;
    }
    inputTable = *(int *)(programState + 0x24);
    *(int *)(programState + 0x2a0) = *(int *)(programState + 0x2a0) + 1;
  }
  if (*(char *)(inputTable + 0x128) != '\0') {
    streamInLowHalf = !streamInLowHalf;
    *(uint *)(programState + 0x238) =
         (*(uint *)(programState + 0x238) & 0x7f) + 4 & 0x7f | *(uint *)(programState + 0x238) & 0xffffff80;
    if (streamInLowHalf) {
      streamWordAddr = descriptorWordIndex * 4 + programState;
      *(uint *)(streamWordAddr + 0x244) = *(uint *)(streamWordAddr + 0x244) & 0xffff0000 | 0x703;
      *(uint *)(streamWordAddr + 0x270) = *(uint *)(streamWordAddr + 0x270) & 0xffff0000 | 0xf688;
    }
    else {
      streamWordOffset = descriptorWordIndex * 4;
      descriptorWordIndex = descriptorWordIndex + 1;
      streamWordOffset = streamWordOffset + programState;
      *(uint *)(streamWordOffset + 0x244) = *(uint *)(streamWordOffset + 0x244) & 0xffff | 0x7030000;
      *(uint *)(streamWordOffset + 0x270) = *(uint *)(streamWordOffset + 0x270) & 0xffff | 0xf6880000;
    }
    inputTable = *(int *)(programState + 0x24);
    *(int *)(programState + 0x2a0) = *(int *)(programState + 0x2a0) + 1;
  }
  if (*(char *)(inputTable + 0x150) != '\0') {
    streamInLowHalf = !streamInLowHalf;
    *(uint *)(programState + 0x238) =
         (*(uint *)(programState + 0x238) & 0x7f) + 4 & 0x7f | *(uint *)(programState + 0x238) & 0xffffff80;
    if (streamInLowHalf) {
      streamWordAddr = descriptorWordIndex * 4 + programState;
      *(uint *)(streamWordAddr + 0x244) = *(uint *)(streamWordAddr + 0x244) & 0xffff0000 | 0x803;
      *(uint *)(streamWordAddr + 0x270) = *(uint *)(streamWordAddr + 0x270) & 0xffff0000 | 0xf688;
    }
    else {
      streamWordOffset = descriptorWordIndex * 4;
      descriptorWordIndex = descriptorWordIndex + 1;
      streamWordOffset = streamWordOffset + programState;
      *(uint *)(streamWordOffset + 0x244) = *(uint *)(streamWordOffset + 0x244) & 0xffff | 0x8030000;
      *(uint *)(streamWordOffset + 0x270) = *(uint *)(streamWordOffset + 0x270) & 0xffff | 0xf6880000;
    }
    inputTable = *(int *)(programState + 0x24);
    *(int *)(programState + 0x2a0) = *(int *)(programState + 0x2a0) + 1;
  }
  if (*(char *)(inputTable + 0x178) != '\0') {
    streamInLowHalf = !streamInLowHalf;
    *(uint *)(programState + 0x238) =
         (*(uint *)(programState + 0x238) & 0x7f) + 4 & 0x7f | *(uint *)(programState + 0x238) & 0xffffff80;
    if (streamInLowHalf) {
      streamWordAddr = descriptorWordIndex * 4 + programState;
      *(uint *)(streamWordAddr + 0x244) = *(uint *)(streamWordAddr + 0x244) & 0xffff0000 | 0x903;
      *(uint *)(streamWordAddr + 0x270) = *(uint *)(streamWordAddr + 0x270) & 0xffff0000 | 0xf688;
    }
    else {
      streamWordOffset = descriptorWordIndex * 4;
      descriptorWordIndex = descriptorWordIndex + 1;
      streamWordOffset = streamWordOffset + programState;
      *(uint *)(streamWordOffset + 0x244) = *(uint *)(streamWordOffset + 0x244) & 0xffff | 0x9030000;
      *(uint *)(streamWordOffset + 0x270) = *(uint *)(streamWordOffset + 0x270) & 0xffff | 0xf6880000;
    }
    inputTable = *(int *)(programState + 0x24);
    *(int *)(programState + 0x2a0) = *(int *)(programState + 0x2a0) + 1;
  }
  if (*(char *)(inputTable + 0x1a0) != '\0') {
    streamInLowHalf = !streamInLowHalf;
    *(uint *)(programState + 0x238) =
         (*(uint *)(programState + 0x238) & 0x7f) + 4 & 0x7f | *(uint *)(programState + 0x238) & 0xffffff80;
    if (streamInLowHalf) {
      streamWordAddr = descriptorWordIndex * 4 + programState;
      *(uint *)(streamWordAddr + 0x244) = *(uint *)(streamWordAddr + 0x244) & 0xffff0000 | 0xa03;
      *(uint *)(streamWordAddr + 0x270) = *(uint *)(streamWordAddr + 0x270) & 0xffff0000 | 0xf688;
    }
    else {
      streamWordOffset = descriptorWordIndex * 4;
      descriptorWordIndex = descriptorWordIndex + 1;
      streamWordOffset = streamWordOffset + programState;
      *(uint *)(streamWordOffset + 0x244) = *(uint *)(streamWordOffset + 0x244) & 0xffff | 0xa030000;
      *(uint *)(streamWordOffset + 0x270) = *(uint *)(streamWordOffset + 0x270) & 0xffff | 0xf6880000;
    }
    inputTable = *(int *)(programState + 0x24);
    *(int *)(programState + 0x2a0) = *(int *)(programState + 0x2a0) + 1;
  }
  if (*(char *)(inputTable + 0x1c8) != '\0') {
    streamInLowHalf = !streamInLowHalf;
    *(uint *)(programState + 0x238) =
         (*(uint *)(programState + 0x238) & 0x7f) + 4 & 0x7f | *(uint *)(programState + 0x238) & 0xffffff80;
    if (streamInLowHalf) {
      streamWordAddr = descriptorWordIndex * 4 + programState;
      *(uint *)(streamWordAddr + 0x244) = *(uint *)(streamWordAddr + 0x244) & 0xffff0000 | 0xb03;
      *(uint *)(streamWordAddr + 0x270) = *(uint *)(streamWordAddr + 0x270) & 0xffff0000 | 0xf688;
    }
    else {
      streamWordOffset = descriptorWordIndex * 4;
      descriptorWordIndex = descriptorWordIndex + 1;
      streamWordOffset = streamWordOffset + programState;
      *(uint *)(streamWordOffset + 0x244) = *(uint *)(streamWordOffset + 0x244) & 0xffff | 0xb030000;
      *(uint *)(streamWordOffset + 0x270) = *(uint *)(streamWordOffset + 0x270) & 0xffff | 0xf6880000;
    }
    inputTable = *(int *)(programState + 0x24);
    *(int *)(programState + 0x2a0) = *(int *)(programState + 0x2a0) + 1;
  }
  if (*(char *)(inputTable + 0x1f0) != '\0') {
    streamInLowHalf = !streamInLowHalf;
    *(uint *)(programState + 0x238) =
         (*(uint *)(programState + 0x238) & 0x7f) + 4 & 0x7f | *(uint *)(programState + 0x238) & 0xffffff80;
    if (streamInLowHalf) {
      streamWordAddr = descriptorWordIndex * 4 + programState;
      *(uint *)(streamWordAddr + 0x244) = *(uint *)(streamWordAddr + 0x244) & 0xffff0000 | 0xc03;
      *(uint *)(streamWordAddr + 0x270) = *(uint *)(streamWordAddr + 0x270) & 0xffff0000 | 0xf688;
    }
    else {
      streamWordOffset = descriptorWordIndex * 4;
      descriptorWordIndex = descriptorWordIndex + 1;
      streamWordOffset = streamWordOffset + programState;
      *(uint *)(streamWordOffset + 0x244) = *(uint *)(streamWordOffset + 0x244) & 0xffff | 0xc030000;
      *(uint *)(streamWordOffset + 0x270) = *(uint *)(streamWordOffset + 0x270) & 0xffff | 0xf6880000;
    }
    inputTable = *(int *)(programState + 0x24);
    *(int *)(programState + 0x2a0) = *(int *)(programState + 0x2a0) + 1;
  }
  if (*(char *)(inputTable + 0x218) != '\0') {
    streamInLowHalf = !streamInLowHalf;
    *(uint *)(programState + 0x238) =
         (*(uint *)(programState + 0x238) & 0x7f) + 4 & 0x7f | *(uint *)(programState + 0x238) & 0xffffff80;
    if (streamInLowHalf) {
      streamWordAddr = descriptorWordIndex * 4 + programState;
      *(uint *)(streamWordAddr + 0x244) = *(uint *)(streamWordAddr + 0x244) & 0xffff0000 | 0xd03;
      *(uint *)(streamWordAddr + 0x270) = *(uint *)(streamWordAddr + 0x270) & 0xffff0000 | 0xf688;
    }
    else {
      streamWordOffset = descriptorWordIndex * 4;
      descriptorWordIndex = descriptorWordIndex + 1;
      streamWordOffset = streamWordOffset + programState;
      *(uint *)(streamWordOffset + 0x244) = *(uint *)(streamWordOffset + 0x244) & 0xffff | 0xd030000;
      *(uint *)(streamWordOffset + 0x270) = *(uint *)(streamWordOffset + 0x270) & 0xffff | 0xf6880000;
    }
    inputTable = *(int *)(programState + 0x24);
    *(int *)(programState + 0x2a0) = *(int *)(programState + 0x2a0) + 1;
  }
  if (*(char *)(inputTable + 0x240) != '\0') {
    streamInLowHalf = !streamInLowHalf;
    *(uint *)(programState + 0x238) =
         (*(uint *)(programState + 0x238) & 0x7f) + 4 & 0x7f | *(uint *)(programState + 0x238) & 0xffffff80;
    if (streamInLowHalf) {
      streamWordAddr = descriptorWordIndex * 4 + programState;
      *(uint *)(streamWordAddr + 0x244) = *(uint *)(streamWordAddr + 0x244) & 0xffff0000 | 0xe03;
      *(uint *)(streamWordAddr + 0x270) = *(uint *)(streamWordAddr + 0x270) & 0xffff0000 | 0xf688;
    }
    else {
      streamWordOffset = descriptorWordIndex * 4;
      descriptorWordIndex = descriptorWordIndex + 1;
      streamWordOffset = streamWordOffset + programState;
      *(uint *)(streamWordOffset + 0x244) = *(uint *)(streamWordOffset + 0x244) & 0xffff | 0xe030000;
      *(uint *)(streamWordOffset + 0x270) = *(uint *)(streamWordOffset + 0x270) & 0xffff | 0xf6880000;
    }
    inputTable = *(int *)(programState + 0x24);
    *(int *)(programState + 0x2a0) = *(int *)(programState + 0x2a0) + 1;
  }
  if (*(char *)(inputTable + 0x268) != '\0') {
    streamInLowHalf = !streamInLowHalf;
    *(uint *)(programState + 0x238) =
         (*(uint *)(programState + 0x238) & 0x7f) + 4 & 0x7f | *(uint *)(programState + 0x238) & 0xffffff80;
    if (streamInLowHalf) {
      streamWordAddr = descriptorWordIndex * 4 + programState;
      *(uint *)(streamWordAddr + 0x244) = *(uint *)(streamWordAddr + 0x244) & 0xffff0000 | 0xf03;
      *(uint *)(streamWordAddr + 0x270) = *(uint *)(streamWordAddr + 0x270) & 0xffff0000 | 0xf688;
    }
    else {
      streamWordOffset = descriptorWordIndex * 4;
      descriptorWordIndex = descriptorWordIndex + 1;
      streamWordOffset = streamWordOffset + programState;
      *(uint *)(streamWordOffset + 0x244) = *(uint *)(streamWordOffset + 0x244) & 0xffff | 0xf030000;
      *(uint *)(streamWordOffset + 0x270) = *(uint *)(streamWordOffset + 0x270) & 0xffff | 0xf6880000;
    }
    inputTable = *(int *)(programState + 0x24);
    *(int *)(programState + 0x2a0) = *(int *)(programState + 0x2a0) + 1;
  }
  if (*(char *)(inputTable + 0x290) != '\0') {
    streamInLowHalf = !streamInLowHalf;
    *(uint *)(programState + 0x238) =
         (*(uint *)(programState + 0x238) & 0x7f) + 4 & 0x7f | *(uint *)(programState + 0x238) & 0xffffff80;
    if (streamInLowHalf) {
      streamWordAddr = descriptorWordIndex * 4 + programState;
      *(uint *)(streamWordAddr + 0x244) = *(uint *)(streamWordAddr + 0x244) & 0xffff0000 | 0x1003;
      *(uint *)(streamWordAddr + 0x270) = *(uint *)(streamWordAddr + 0x270) & 0xffff0000 | 0xf688;
    }
    else {
      streamWordOffset = descriptorWordIndex * 4;
      descriptorWordIndex = descriptorWordIndex + 1;
      streamWordOffset = streamWordOffset + programState;
      *(uint *)(streamWordOffset + 0x244) = *(uint *)(streamWordOffset + 0x244) & 0xffff | 0x10030000;
      *(uint *)(streamWordOffset + 0x270) = *(uint *)(streamWordOffset + 0x270) & 0xffff | 0xf6880000;
    }
    inputTable = *(int *)(programState + 0x24);
    *(int *)(programState + 0x2a0) = *(int *)(programState + 0x2a0) + 1;
  }
  if (*(char *)(inputTable + 0x2b8) != '\0') {
    streamInLowHalf = !streamInLowHalf;
    *(uint *)(programState + 0x238) =
         (*(uint *)(programState + 0x238) & 0x7f) + 4 & 0x7f | *(uint *)(programState + 0x238) & 0xffffff80;
    if (streamInLowHalf) {
      streamWordAddr = descriptorWordIndex * 4 + programState;
      *(uint *)(streamWordAddr + 0x244) = *(uint *)(streamWordAddr + 0x244) & 0xffff0000 | 0x1103;
      *(uint *)(streamWordAddr + 0x270) = *(uint *)(streamWordAddr + 0x270) & 0xffff0000 | 0xf688;
    }
    else {
      streamWordOffset = descriptorWordIndex * 4;
      descriptorWordIndex = descriptorWordIndex + 1;
      streamWordOffset = streamWordOffset + programState;
      *(uint *)(streamWordOffset + 0x244) = *(uint *)(streamWordOffset + 0x244) & 0xffff | 0x11030000;
      *(uint *)(streamWordOffset + 0x270) = *(uint *)(streamWordOffset + 0x270) & 0xffff | 0xf6880000;
    }
    inputTable = *(int *)(programState + 0x24);
    *(int *)(programState + 0x2a0) = *(int *)(programState + 0x2a0) + 1;
  }
  if (*(char *)(inputTable + 0x2e0) != '\0') {
    streamInLowHalf = !streamInLowHalf;
    *(uint *)(programState + 0x238) =
         (*(uint *)(programState + 0x238) & 0x7f) + 4 & 0x7f | *(uint *)(programState + 0x238) & 0xffffff80;
    if (streamInLowHalf) {
      streamWordAddr = descriptorWordIndex * 4 + programState;
      *(uint *)(streamWordAddr + 0x244) = *(uint *)(streamWordAddr + 0x244) & 0xffff0000 | 0x1203;
      *(uint *)(streamWordAddr + 0x270) = *(uint *)(streamWordAddr + 0x270) & 0xffff0000 | 0xf688;
    }
    else {
      streamWordOffset = descriptorWordIndex * 4;
      descriptorWordIndex = descriptorWordIndex + 1;
      streamWordOffset = streamWordOffset + programState;
      *(uint *)(streamWordOffset + 0x244) = *(uint *)(streamWordOffset + 0x244) & 0xffff | 0x12030000;
      *(uint *)(streamWordOffset + 0x270) = *(uint *)(streamWordOffset + 0x270) & 0xffff | 0xf6880000;
    }
    inputTable = *(int *)(programState + 0x24);
    *(int *)(programState + 0x2a0) = *(int *)(programState + 0x2a0) + 1;
  }
  if (*(char *)(inputTable + 0x308) != '\0') {
    streamInLowHalf = !streamInLowHalf;
    *(uint *)(programState + 0x238) =
         (*(uint *)(programState + 0x238) & 0x7f) + 4 & 0x7f | *(uint *)(programState + 0x238) & 0xffffff80;
    if (streamInLowHalf) {
      streamWordAddr = descriptorWordIndex * 4 + programState;
      *(uint *)(streamWordAddr + 0x244) = *(uint *)(streamWordAddr + 0x244) & 0xffff0000 | 0x1303;
      *(uint *)(streamWordAddr + 0x270) = *(uint *)(streamWordAddr + 0x270) & 0xffff0000 | 0xf688;
    }
    else {
      streamWordOffset = descriptorWordIndex * 4;
      descriptorWordIndex = descriptorWordIndex + 1;
      streamWordOffset = streamWordOffset + programState;
      *(uint *)(streamWordOffset + 0x244) = *(uint *)(streamWordOffset + 0x244) & 0xffff | 0x13030000;
      *(uint *)(streamWordOffset + 0x270) = *(uint *)(streamWordOffset + 0x270) & 0xffff | 0xf6880000;
    }
    inputTable = *(int *)(programState + 0x24);
    *(int *)(programState + 0x2a0) = *(int *)(programState + 0x2a0) + 1;
  }
  if (*(char *)(inputTable + 0x330) != '\0') {
    streamInLowHalf = !streamInLowHalf;
    *(uint *)(programState + 0x238) =
         (*(uint *)(programState + 0x238) & 0x7f) + 4 & 0x7f | *(uint *)(programState + 0x238) & 0xffffff80;
    if (streamInLowHalf) {
      streamWordAddr = descriptorWordIndex * 4 + programState;
      *(uint *)(streamWordAddr + 0x244) = *(uint *)(streamWordAddr + 0x244) & 0xffff0000 | 0x1403;
      *(uint *)(streamWordAddr + 0x270) = *(uint *)(streamWordAddr + 0x270) & 0xffff0000 | 0xf688;
    }
    else {
      streamWordOffset = descriptorWordIndex * 4;
      descriptorWordIndex = descriptorWordIndex + 1;
      streamWordOffset = streamWordOffset + programState;
      *(uint *)(streamWordOffset + 0x244) = *(uint *)(streamWordOffset + 0x244) & 0xffff | 0x14030000;
      *(uint *)(streamWordOffset + 0x270) = *(uint *)(streamWordOffset + 0x270) & 0xffff | 0xf6880000;
    }
    inputTable = *(int *)(programState + 0x24);
    *(int *)(programState + 0x2a0) = *(int *)(programState + 0x2a0) + 1;
  }
  if (*(char *)(inputTable + 0x358) == '\0') {
    streamCount = *(uint *)(programState + 0x2a0);
  }
  else {
    streamInLowHalf = !streamInLowHalf;
    *(uint *)(programState + 0x238) =
         (*(uint *)(programState + 0x238) & 0x7f) + 4 & 0x7f | *(uint *)(programState + 0x238) & 0xffffff80;
    if (streamInLowHalf) {
      streamWordAddr = descriptorWordIndex * 4 + programState;
      *(uint *)(streamWordAddr + 0x244) = *(uint *)(streamWordAddr + 0x244) & 0xffff0000 | 0x1503;
      *(uint *)(streamWordAddr + 0x270) = *(uint *)(streamWordAddr + 0x270) & 0xffff0000 | 0xf688;
    }
    else {
      streamWordOffset = descriptorWordIndex * 4;
      descriptorWordIndex = descriptorWordIndex + 1;
      streamWordOffset = streamWordOffset + programState;
      *(uint *)(streamWordOffset + 0x244) = *(uint *)(streamWordOffset + 0x244) & 0xffff | 0x15030000;
      *(uint *)(streamWordOffset + 0x270) = *(uint *)(streamWordOffset + 0x270) & 0xffff | 0xf6880000;
    }
    streamCount = *(int *)(programState + 0x2a0) + 1;
    *(uint *)(programState + 0x2a0) = streamCount;
  }
  if (streamCount < 2) {
    *(uint *)(programState + 0x234) = *(uint *)(programState + 0x234) | 2;
    *(uint *)(programState + 0x238) =
         (*(uint *)(programState + 0x238) & 0x7f) + 4 & 0x7f | *(uint *)(programState + 0x238) & 0xffffff80;
    *(uint *)(programState + 0x244) = *(uint *)(programState + 0x244) & 0x2000ffff | 0x21030000;
    *(uint *)(programState + 0x2a0) = streamCount + 1;
    *(uint *)(programState + 0x270) = *(uint *)(programState + 0x270) & 0xffff | 0xf6880000;
  }
  else {
    if (streamInLowHalf) {
      streamWordAddr = descriptorWordIndex * 4 + programState;
      *(uint *)(streamWordAddr + 0x244) = *(uint *)(streamWordAddr + 0x244) | 0x2000;
    }
    else {
      streamWordAddr = descriptorWordIndex * 4 + programState;
      *(uint *)(streamWordAddr + 0x240) = *(uint *)(streamWordAddr + 0x240) | 0x20000000;
    }
    if (0x10 < *(uint *)(programState + 0x2a0)) {
      *(undefined1 *)(shader + 4) = 0;
    }
  }
  shaderOutputMask = shader[0x1b];
  if ((((shaderOutputMask & 0xffffff) == 0) && (*(char *)(shader + 0x1c) == '\0')) &&
     (*(char *)((int)shader + 0x7a) == '\0')) {
    totalStreamCount = *(int *)(programState + 0x2a8);
  }
  else {
    totalStreamCount = *(int *)(programState + 0x2a8) + 1;
    *(uint *)(programState + 0x23c) = *(uint *)(programState + 0x23c) | 2;
    *(int *)(programState + 0x2a8) = totalStreamCount;
    shaderOutputMask = shader[0x1b];
  }
  if ((((shaderOutputMask & 0xffff) != 0) || (*(char *)(shader + 0x1c) != '\0')) ||
     (*(char *)((int)shader + 0x7a) != '\0')) {
    totalStreamCount = totalStreamCount + 1;
    *(int *)(programState + 0x2a8) = totalStreamCount;
    *(uint *)(programState + 0x23c) = *(uint *)(programState + 0x23c) | 4;
  }
  if ((*(char *)((int)shader + 0x6f) != '\0') || (*(char *)(shader + 0x1c) != '\0')) {
    totalStreamCount = totalStreamCount + 2;
    *(int *)(programState + 0x2a8) = totalStreamCount;
    *(uint *)(programState + 0x23c) = *(uint *)(programState + 0x23c) | 0x18;
  }
  if (*(char *)((int)shader + 0x79) != '\0') {
    totalStreamCount = totalStreamCount + 1;
    *(int *)(programState + 0x2a8) = totalStreamCount;
    *(uint *)(programState + 0x23c) = *(uint *)(programState + 0x23c) | 0x10000;
  }
  fieldShift = 0;
  outputsLeft = 8;
  do {
    outputFlags = *(byte *)((int)shader + 0x71);
    if (outputFlags != 0) {
      componentCount = 4;
      if ((outputFlags & 8) == 0) {
        componentCount = 3 - (uint)((outputFlags & 4) == 0);
      }
      fieldValue = componentCount << (fieldShift & 0x3f);
      totalStreamCount = totalStreamCount + 1;
      *(int *)(programState + 0x2a8) = totalStreamCount;
      *(uint *)(programState + 0x240) = fieldValue | *(uint *)(programState + 0x240);
      *(uint *)(programState + 0x29c) = fieldValue | *(uint *)(programState + 0x29c);
    }
    shader = (int *)((int)shader + 1);
    fieldShift = fieldShift + 3;
    outputsLeft = outputsLeft + -1;
  } while (outputsLeft != 0);
  if (totalStreamCount == 1) {
    *(undefined4 *)(programState + 0x2a8) = 2;
    *(uint *)(programState + 0x240) = *(uint *)(programState + 0x240) & 0xff1fffff | 0x800000;
    *(uint *)(programState + 0x29c) = *(uint *)(programState + 0x29c) & 0xff1fffff | 0x800000;
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
int FUN_00064230(ctx, shader)
  int ctx;
  int *shader;
{
  int outputsLeft;
  uint fieldValue;
  uint savedWord5;
  uint fieldShift;
  uint shaderOutputMask;
  uint streamTotal;
  uint descWord;
  uint savedWord10;
  int inputRecordCursor;
  byte outputFlags;
  uint uVar2;
  int inputBlock;
  uint *streamBlock;
  uint *streamFlagTable;
  int componentMask;
  bool nextStreamHighHalf;
  int iVar8;
  uint uVar9;
  uint inputTypeWord;
  int iVar11;
  int streamCount;
  int programState;
  int descriptorWordIndex;
  int inputsLeft;
  
  programState = **(int **)(*(int *)(((unsigned char *)0x0000118c) + ctx) * 4 + *shader);
  streamBlock = *(uint **)(((unsigned char *)0x00001384) + programState);
  inputBlock = *(int *)(programState + 0x150);
  if (streamBlock == (uint *)0x0) {
    streamBlock = (uint *)(**(code **)(ctx + 0xc))(0x7c);
    *(uint **)(((unsigned char *)0x00001384) + programState) = streamBlock;
  }
  savedWord5 = streamBlock[5];
  streamBlock[3] = 0;
  streamBlock[4] = 0;
  iVar8 = 0;
  streamBlock[1] = 4;
  streamBlock[2] = 1;
  savedWord10 = streamBlock[0x10];
  streamBlock[5] = savedWord5 & 0xffffff00 | 3;
  inputTypeWord = *(uint *)(((unsigned char *)0x000055e8) + inputBlock);
  streamBlock[0x10] = savedWord10 & 0xfffff000 | 0x688;
  streamBlock[5] = (inputTypeWord & 0x1f) << 8 | savedWord5 & 0xffff0000 | 3;
  if (*(int *)(((unsigned char *)0x000055e8) + inputBlock) != 0x16) {
    iVar8 = 0xf;
  }
  *streamBlock = 1;
  descriptorWordIndex = 0;
  nextStreamHighHalf = true;
  streamBlock[0x1b] = 1;
  streamBlock[0x1d] = 1;
  streamBlock[0x10] = iVar8 << 0xc | savedWord10 & 0xffff0000 | 0x688;
  streamFlagTable = &DAT_001dbab8;
  streamCount = 1;
  inputsLeft = 0x15;
  inputRecordCursor = programState;
  do {
    if (0 < *(int *)(inputRecordCursor + 100)) {
      iVar11 = *(int *)(inputRecordCursor + 0xbc);
      streamBlock[1] = (streamBlock[1] & 0x7f) + 4 & 0x7f | streamBlock[1] & 0xffffff80;
      if (nextStreamHighHalf) {
        componentMask = 0;
        iVar11 = iVar11 * 4 + inputBlock + 0x24;
        descWord = streamBlock[descriptorWordIndex + 5];
        streamBlock[descriptorWordIndex + 5] = descWord & 0xff00ffff | 0x30000;
        streamBlock[descriptorWordIndex + 5] =
             (*(uint *)(((unsigned char *)0x000055c4) + iVar11) & 0x1f) << 0x18 | descWord & 0xffff | 0x30000;
        streamBlock[descriptorWordIndex + 0x10] = streamBlock[descriptorWordIndex + 0x10] & 0xf000ffff | 0x6880000;
        if (*(int *)(((unsigned char *)0x000055c4) + iVar11) != 0x16) {
          componentMask = 0xf;
        }
        nextStreamHighHalf = false;
        streamBlock[descriptorWordIndex + 0x10] = componentMask << 0x1c | streamBlock[descriptorWordIndex + 0x10] & 0xfffffff;
        descriptorWordIndex = descriptorWordIndex + 1;
      }
      else {
        componentMask = 0;
        iVar11 = iVar11 * 4 + inputBlock + 0x24;
        descWord = streamBlock[descriptorWordIndex + 5];
        streamBlock[descriptorWordIndex + 5] = descWord & 0xffffff00 | 3;
        streamBlock[descriptorWordIndex + 5] =
             (*(uint *)(((unsigned char *)0x000055c4) + iVar11) & 0x1f) << 8 | descWord & 0xffff0000 | 3;
        streamBlock[descriptorWordIndex + 0x10] = streamBlock[descriptorWordIndex + 0x10] & 0xfffff000 | 0x688;
        if (*(int *)(((unsigned char *)0x000055c4) + iVar11) != 0x16) {
          componentMask = 0xf;
        }
        nextStreamHighHalf = true;
        streamBlock[descriptorWordIndex + 0x10] = componentMask << 0xc | streamBlock[descriptorWordIndex + 0x10] & 0xffff0fff;
      }
      streamCount = streamCount + 1;
      streamTotal = streamBlock[0x1b] + 1;
      streamBlock[0x1b] = streamTotal;
      *streamBlock = *streamBlock | *streamFlagTable;
      if (streamCount == *(int *)(programState + 0x110)) goto LAB_000644c0;
    }
    inputRecordCursor = inputRecordCursor + 4;
    streamFlagTable = streamFlagTable + 1;
    inputsLeft = inputsLeft + -1;
  } while (inputsLeft != 0);
  streamTotal = streamBlock[0x1b];
LAB_000644c0:
  if (streamTotal < 2) {
    *streamBlock = *streamBlock | 2;
    streamBlock[1] = (streamBlock[1] & 0x7f) + 4 & 0x7f | streamBlock[1] & 0xffffff80;
    streamBlock[5] = streamBlock[5] & 0x2000ffff | 0x21030000;
    streamBlock[0x1b] = streamTotal + 1;
    streamBlock[0x10] = streamBlock[0x10] & 0xffff | 0xf6880000;
  }
  else {
    if (nextStreamHighHalf) {
      streamBlock[descriptorWordIndex + 5] = streamBlock[descriptorWordIndex + 5] | 0x2000;
    }
    else {
      streamBlock[descriptorWordIndex + 4] = streamBlock[descriptorWordIndex + 4] | 0x20000000;
    }
    if (0x10 < streamBlock[0x1b]) {
      *(undefined1 *)(shader + 4) = 0;
    }
  }
  shaderOutputMask = shader[0x1b];
  if ((((shaderOutputMask & 0xffffff) != 0) || (*(char *)(shader + 0x1c) != '\0')) ||
     (((unsigned char *)0x000013c8)[programState] != '\0')) {
    streamBlock[2] = streamBlock[2] | 2;
    streamBlock[0x1d] = streamBlock[0x1d] + 1;
    shaderOutputMask = shader[0x1b];
  }
  if ((((shaderOutputMask & 0xffff) != 0) || (*(char *)(shader + 0x1c) != '\0')) ||
     (((unsigned char *)0x000013c8)[programState] != '\0')) {
    streamBlock[2] = streamBlock[2] | 4;
    streamBlock[0x1d] = streamBlock[0x1d] + 1;
  }
  if ((*(char *)((int)shader + 0x6f) != '\0') || (*(char *)(shader + 0x1c) != '\0')) {
    streamBlock[2] = streamBlock[2] | 0x18;
    streamBlock[0x1d] = streamBlock[0x1d] + 2;
  }
  if (*(char *)((int)shader + 0x79) != '\0') {
    streamBlock[2] = streamBlock[2] | 0x10000;
    streamBlock[0x1d] = streamBlock[0x1d] + 1;
  }
  fieldShift = 0;
  outputsLeft = 8;
  do {
    outputFlags = *(byte *)((int)shader + 0x71);
    if (outputFlags != 0) {
      iVar8 = 4;
      if ((outputFlags & 8) == 0) {
        iVar8 = 3 - (uint)((outputFlags & 4) == 0);
      }
      fieldValue = iVar8 << (fieldShift & 0x3f);
      streamBlock[3] = fieldValue | streamBlock[3];
      streamBlock[4] = fieldValue | streamBlock[4];
      streamBlock[0x1d] = streamBlock[0x1d] + 1;
    }
    shader = (int *)((int)shader + 1);
    fieldShift = fieldShift + 3;
    outputsLeft = outputsLeft + -1;
  } while (outputsLeft != 0);
  streamBlock[2] = *(uint *)(((unsigned char *)0x00005498) + inputBlock);
  uVar9 = *(uint *)(((unsigned char *)0x0000549c) + inputBlock);
  streamBlock[3] = uVar9;
  uVar2 = *(uint *)(((unsigned char *)0x00005434) + inputBlock);
  streamBlock[0x1d] = uVar2;
  if (uVar2 == 1) {
    streamBlock[0x1d] = 2;
    streamBlock[3] = uVar9 & 0xff1fffff | 0x800000;
    streamBlock[4] = streamBlock[4] & 0xff1fffff | 0x800000;
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

/* extvsApplyStreamDescriptors @ 0x64850 (436 bytes) */
int extvsApplyStreamDescriptors(glContext)
  int glContext;
{
  int boundProgram;
  undefined4 *streamWord16Ptr;
  int streamCount;
  undefined4 streamCountCopy;
  bool streamFormatChanged;
  int *shader;
  undefined4 *streamBlock;
  int ctxCursor;
  uint loopIndex;
  undefined4 *streamBlockCursor;
  
  shader = *(int **)(((unsigned char *)0x00001168) + glContext);
  streamBlock = *(undefined4 **)
            (((unsigned char *)0x00001384) + **(int **)(*(int *)(((unsigned char *)0x0000118c) + glContext) * 4 + *shader));
  if ((*(char *)(shader + 4) != '\0') && ((*(uint *)(glContext + 0x8c) & 0x40000000) == 0)) {
    if ((*(int *)(glContext + 0x1b9c) != streamBlock[2]) ||
       (streamFormatChanged = false, *(int *)(glContext + 0x1ba0) != streamBlock[3])) {
      streamFormatChanged = true;
    }
    *(undefined4 *)(glContext + 0x1ca0) = *streamBlock;
    *(undefined4 *)(glContext + 0x1ca4) = streamBlock[1];
    *(undefined4 *)(glContext + 0x1b9c) = streamBlock[2];
    *(undefined4 *)(glContext + 0x1ba0) = streamBlock[3];
    streamCount = streamBlock[0x1b];
    if (streamCount + 1U >> 1 != 0) {
      loopIndex = 0;
      ctxCursor = glContext;
      streamBlockCursor = streamBlock;
      do {
        loopIndex = loopIndex + 1;
        *(undefined4 *)(ctxCursor + 0x1be4) = streamBlockCursor[5];
        streamWord16Ptr = streamBlockCursor + 0x10;
        streamBlockCursor = streamBlockCursor + 1;
        *(undefined4 *)(ctxCursor + 0x1c04) = *streamWord16Ptr;
        ctxCursor = ctxCursor + 4;
        streamCount = streamBlock[0x1b];
      } while (loopIndex < streamCount + 1U >> 1);
    }
    *(int *)(glContext + 0x2438) = streamCount;
    streamCountCopy = streamBlock[0x1b];
    *(undefined4 *)(glContext + 0x1b78) = 0;
    *(undefined4 *)(glContext + 0x243c) = streamCountCopy;
    if ((shader[0xc] & 1U) != 0) {
      *(undefined4 *)(glContext + 0x1b78) = 1;
    }
    boundProgram = *(int *)(((unsigned char *)0x0000148c) + glContext);
    *(uint *)(glContext + 0x1930) = *(uint *)(glContext + 0x1930) | 0x40000;
    if (boundProgram != 0) {
      boundProgram = *(int *)(boundProgram + 0x14);
      if (((*(int *)(glContext + 0x1b50) != *(int *)(boundProgram + 0x5658)) ||
          (ctxCursor = *(int *)(glContext + 0x1ba4), ctxCursor != *(int *)(boundProgram + 0x5650))) || (streamFormatChanged)) {
        (**(code **)(((unsigned char *)0x00001334) + glContext))(glContext,1);
        *(undefined4 *)(boundProgram + 0x5650) = *(undefined4 *)(glContext + 0x1ba4);
        *(undefined4 *)(boundProgram + 0x5658) = *(undefined4 *)(glContext + 0x1b50);
        ctxCursor = *(int *)(glContext + 0x1ba4);
      }
      *(int *)(boundProgram + 0x5650) = ctxCursor;
      *(undefined4 *)(boundProgram + 0x5658) = *(undefined4 *)(glContext + 0x1b50);
    }
    *(undefined1 *)(glContext + 0x2435) = 1;
  }
  return;
}

/* extvsUploadProgramConstants @ 0x64a10 (1304 bytes) */
int extvsUploadProgramConstants(glContext, shader)
  int glContext;
  int *shader;
{
  int cmdEndB;
  int cmdEnd;
  uint freeHeight;
  uint regionHeight;
  uint regionWidth;
  undefined8 valueSingleHigh;
  undefined8 *valueSingle;
  int entrySingle;
  int entryB;
  int entryA;
  int allocX;
  int cacheMode;
  undefined4 *cmdBuffer;
  int *constIndexCursor;
  code *commitCallback;
  undefined8 *valueC;
  undefined4 *cmdBufferB;
  undefined8 *valueB;
  char *in_r5;
  undefined8 *valueA;
  undefined4 in_r6;
  undefined4 in_r7;
  int in_r8;
  int constantBlock;
  int iVar7;
  undefined8 *valueD;
  int symbolList;
  int entryD;
  char cVar11;
  int allocY;
  int entryC;
  uint uVar14;
  uint freeWidth;
  undefined4 *hwProgramSlot;
  uint uVar17;
  int *constIndexEnd;
  uint uVar19;
  int *constAlloc;
  char *programState;
  undefined8 valueAHigh;
  undefined8 valueDHigh;
  undefined8 valueCHigh;
  undefined8 valueBHigh;
  undefined8 valueDLow;
  undefined8 valueCLow;
  undefined8 valueBLow;
  
  if (*shader != 0) {
    constAlloc = *(int **)(((unsigned char *)0x000011b4) + glContext);
    hwProgramSlot = *(undefined4 **)(*(int *)(((unsigned char *)0x0000118c) + glContext) * 4 + *shader);
    programState = (char *)*hwProgramSlot;
    regionWidth = *(uint *)(programState + 0x18);
    regionHeight = *(uint *)(programState + 0x5c);
    if ((*(char *)(shader + 4) != '\0') && ((*(uint *)(glContext + 0x8c) & 0x40000000) == 0)) {
      if (*programState != '\0') {
LAB_00064c00:
        if (regionHeight != 0) {
          if (*(int *)(programState + 0x2b8) == 0) {
            constantBlock = hwProgramSlot[0x22];
            symbolList = shader[8];
            constIndexEnd = *(int **)(programState + 0x220) + *(int *)(programState + 0x224);
            constIndexCursor = *(int **)(programState + 0x220);
            while (constIndexCursor + 4 <= constIndexEnd) {
              entryA = symbolList + *constIndexCursor * 0x54;
              entryD = symbolList + constIndexCursor[3] * 0x54;
              entryB = symbolList + constIndexCursor[1] * 0x54;
              entryC = symbolList + constIndexCursor[2] * 0x54;
              valueA = *(undefined8 **)(entryA + 0x38);
              valueB = *(undefined8 **)(entryB + 0x38);
              valueC = *(undefined8 **)(entryC + 0x38);
              valueD = *(undefined8 **)(entryD + 0x38);
              valueAHigh = valueA[1];
              entryA = *(int *)(entryA + 4) * 0x10;
              valueCHigh = valueC[1];
              valueBHigh = valueB[1];
              valueDHigh = valueD[1];
              valueBLow = *valueB;
              in_r8 = *(int *)(entryB + 4) * 0x10;
              valueCLow = *valueC;
              valueDLow = *valueD;
              iVar7 = *(int *)(entryC + 4) * 0x10;
              entryD = *(int *)(entryD + 4) * 0x10;
              *(undefined8 *)(constantBlock + entryA) = *valueA;
              *(undefined8 *)(constantBlock + entryA + 8) = valueAHigh;
              *(undefined8 *)(constantBlock + in_r8) = valueBLow;
              *(undefined8 *)(constantBlock + in_r8 + 8) = valueBHigh;
              *(undefined8 *)(constantBlock + iVar7) = valueCLow;
              *(undefined8 *)(constantBlock + iVar7 + 8) = valueCHigh;
              *(undefined8 *)(constantBlock + entryD) = valueDLow;
              *(undefined8 *)(constantBlock + entryD + 8) = valueDHigh;
              constIndexCursor = constIndexCursor + 4;
            }
            for (; constIndexCursor < constIndexEnd; constIndexCursor = constIndexCursor + 1) {
              entrySingle = symbolList + *constIndexCursor * 0x54;
              valueSingle = *(undefined8 **)(entrySingle + 0x38);
              valueSingleHigh = valueSingle[1];
              entrySingle = *(int *)(entrySingle + 4) * 0x10;
              *(undefined8 *)(constantBlock + entrySingle) = *valueSingle;
              *(undefined8 *)(constantBlock + entrySingle + 8) = valueSingleHigh;
            }
          }
          cmdBufferB = (undefined4 *)(**(code **)(glContext + 0x2758))(glContext,2);
          *(undefined4 **)(0x00002748 + glContext + 4) = cmdBufferB;
          *cmdBufferB = 0x8a1;
          *(undefined4 *)(*(int *)(0x00002748 + glContext + 4) + 4) = 0;
          cmdEnd = *(int *)(0x00002748 + glContext + 4);
          commitCallback = *(code **)(glContext + 0x275c);
          *(int *)(0x00002748 + glContext + 4) = cmdEnd + 8;
          (*commitCallback)(glContext,cmdEnd + 8);
          in_r6 = hwProgramSlot[0x22];
          in_r7 = 1;
          in_r5 = programState;
          ((int (*)())vpUploadConstantsWithFog)(glContext,shader,programState,in_r6,1);
        }
        uVar14 = *(uint *)(glContext + 0x1b90);
        cVar11 = '\0';
        uVar19 = *(uint *)(programState + 4) & 0x3ff;
        *(uint *)(glContext + 0x1b90) = uVar19 | uVar14 & 0xfffffc00;
        uVar17 = (*(int *)(programState + 4) + *(int *)(programState + 8)) * 0x400 & 0xffc00;
        *(uint *)(glContext + 0x1b90) = uVar17 | uVar19 | uVar14 & 0xfff00000;
        *(uint *)(glContext + 0x1b90) =
             (*(uint *)(programState + 0x10) & 0x3ff) << 0x14 | uVar17 | uVar19 | uVar14 & 0xc0000000;
        *(uint *)(glContext + 0x1b94) =
             *(int *)(programState + 4) + *(int *)(programState + 0xc) & 0x3ffU |
             *(uint *)(glContext + 0x1b94) & 0xfffffc00;
        *(char *)(glContext + 0x1b8f) = (char)*(undefined4 *)(programState + 0x14);
        if (*(int *)(programState + 0x5c) != 0) {
          cVar11 = (char)*(int *)(programState + 0x5c) + -1;
        }
        *(char *)(glContext + 0x1b8d) = cVar11;
        cmdBuffer = (undefined4 *)(**(code **)(glContext + 0x2758))(glContext,4);
        *(undefined4 **)(0x00002748 + glContext + 4) = cmdBuffer;
        *cmdBuffer = 0x208b4;
        *(undefined4 *)(*(int *)(0x00002748 + glContext + 4) + 4) =
             *(undefined4 *)(glContext + 0x1b90);
        *(undefined4 *)(*(int *)(0x00002748 + glContext + 4) + 8) =
             *(undefined4 *)(glContext + 0x1b8c);
        *(undefined4 *)(*(int *)(0x00002748 + glContext + 4) + 0xc) =
             *(undefined4 *)(glContext + 0x1b94);
        cmdEnd = *(int *)(0x00002748 + glContext + 4);
        commitCallback = *(code **)(glContext + 0x275c);
        *(int *)(0x00002748 + glContext + 4) = cmdEnd + 0x10;
        (*commitCallback)(glContext,cmdEnd + 0x10,in_r5,in_r6,in_r7,in_r8,commitCallback);
        cmdBuffer = (undefined4 *)(**(code **)(glContext + 0x2758))(glContext,2);
        *(undefined4 **)(0x00002748 + glContext + 4) = cmdBuffer;
        *cmdBuffer = 0x8b7;
        cmdEndB = *(int *)(0x00002748 + glContext + 4);
        *(undefined4 *)(cmdEndB + 4) = *(undefined4 *)(glContext + 0x1b98);
        cmdEnd = *(int *)(0x00002748 + glContext + 4);
        commitCallback = *(code **)(glContext + 0x275c);
        *(int *)(0x00002748 + glContext + 4) = cmdEnd + 8;
        (*commitCallback)(glContext,cmdEnd + 8,in_r5,in_r6,in_r7,in_r8,cmdEndB);
        FUN_00050ef0(glContext,*(undefined4 *)(programState + 0x2a4),*(undefined4 *)(programState + 0x2a8),
                     *(undefined4 *)(programState + 0x2ac));
        ((int (*)())FUN_00064720)(glContext);
        return;
      }
      freeWidth = 0;
      freeHeight = 0;
      allocX = *constAlloc;
      cacheMode = *(int *)(glContext + 0xd8);
      allocY = constAlloc[1] - *(int *)(glContext + 0x2448);
LAB_00064a98:
      if (cacheMode == 1) goto LAB_00064ac0;
      if (cacheMode == 0) {
        freeWidth = 0x80 - allocX;
        freeHeight = 0x80 - allocY;
        goto LAB_00064af0;
      }
      if (cacheMode != 2) goto LAB_00064af0;
      do {
        freeWidth = 0x100 - allocX;
        freeHeight = 0x100 - allocY;
        *(uint *)(glContext + 0x8c) = *(uint *)(glContext + 0x8c) | 0x48000;
LAB_00064af0:
        while( true ) {
          if ((regionWidth <= freeWidth) && (regionHeight <= freeHeight)) {
            *(int *)(programState + 0x14) = allocY;
            *(int *)(programState + 4) = allocX;
            *(uint *)(programState + 0x10) = regionWidth + allocX + -1;
            *constAlloc = regionWidth + *constAlloc;
            constAlloc[1] = regionHeight + constAlloc[1];
            ((int (*)())vpUploadConstantArray)(glContext,programState);
            *programState = '\x01';
            FUN_0007dcd0(glContext,programState);
            regionHeight = *(uint *)(programState + 0x5c);
            goto LAB_00064c00;
          }
          if (cacheMode == 1) break;
          if (cacheMode != 0) {
            if (cacheMode == 2) {
              cmdBufferB = (undefined4 *)(**(code **)(glContext + 0x2758))(glContext,2);
              *(undefined4 **)(0x00002748 + glContext + 4) = cmdBufferB;
              *cmdBufferB = 0x8a1;
              *(undefined4 *)(*(int *)(0x00002748 + glContext + 4) + 4) = 0;
              commitCallback = *(code **)(glContext + 0x275c);
              cmdEnd = *(int *)(0x00002748 + glContext + 4) + 8;
              *(int *)(0x00002748 + glContext + 4) = cmdEnd;
              (*commitCallback)(glContext,cmdEnd,in_r5,in_r6,in_r7,in_r8,cmdEnd);
              *constAlloc = 0;
              constAlloc[1] = *(int *)(glContext + 0x2448);
              ((int (*)())FUN_00062490)(glContext);
              cacheMode = *(int *)(glContext + 0xd8);
              allocX = 0;
              allocY = 0;
            }
            goto LAB_00064a98;
          }
          cacheMode = 1;
          *(undefined4 *)(glContext + 0xd8) = 1;
LAB_00064ac0:
          freeWidth = 0xfe - allocX;
          freeHeight = 0x100 - allocY;
          *(uint *)(glContext + 0x8c) = *(uint *)(glContext + 0x8c) | 0x40000;
        }
        cacheMode = 2;
        *(undefined4 *)(glContext + 0xd8) = 2;
      } while( true );
    }
  }
  return;
}

/* extvsValidateProgramState @ 0x64f40 (708 bytes) */
int extvsValidateProgramState(glContext, param_2)
  int glContext;
  undefined4 param_2;
{
  int cmdEndSaved;
  int cmdEnd;
  int outputsLeft;
  int outputFlagCursor;
  int chainEntry;
  byte *outputFlagByte;
  byte ctxDirtyBits;
  code *commitCallback;
  undefined4 *cmdBuffer;
  uint stateKey;
  undefined4 in_r5;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  int currentVariant;
  bool forceRebuild;
  int *variantTable;
  int *shader;
  undefined4 *constantAlloc;
  int slotTableIndex;
  
  if ((*(uint *)(glContext + 0x44) & 0x100000) == 0) {
    outputFlagCursor = glContext + 0x18a0;
    outputsLeft = 0x10;
    do {
      *(uint *)(outputFlagCursor + 8) = *(uint *)(outputFlagCursor + 8) & 0xfffffffe;
      outputFlagCursor = outputFlagCursor + 8;
      outputsLeft = outputsLeft + -1;
    } while (outputsLeft != 0);
  }
  else {
    shader = *(int **)(((unsigned char *)0x00001168) + glContext);
    if (((*(byte *)(glContext + 0x2d) & 8) != 0) && ((*(uint *)(glContext + 0x8c) & 0x10000) != 0)) {
      constantAlloc = *(undefined4 **)(((unsigned char *)0x000011b4) + glContext);
      cmdBuffer = (undefined4 *)(**(code **)(glContext + 0x2758))(glContext,2);
      *(undefined4 **)(0x00002748 + glContext + 4) = cmdBuffer;
      *cmdBuffer = 0x8a1;
      *(undefined4 *)(*(int *)(0x00002748 + glContext + 4) + 4) = 0;
      commitCallback = *(code **)(glContext + 0x275c);
      cmdEndSaved = *(int *)(0x00002748 + glContext + 4) + 8;
      *(int *)(0x00002748 + glContext + 4) = cmdEndSaved;
      (*commitCallback)(glContext,cmdEndSaved,in_r5,in_r6,in_r7,in_r8,cmdEndSaved);
      *constantAlloc = 0;
      constantAlloc[1] = *(undefined4 *)(glContext + 0x2448);
      ((int (*)())FUN_00062490)(glContext);
      *(uint *)(glContext + 0x8c) = *(uint *)(glContext + 0x8c) & 0xfffeffff;
    }
    if (*(char *)(shader + 4) != '\0') {
      slotTableIndex = *(int *)(((unsigned char *)0x0000118c) + glContext);
      variantTable = *(int **)(slotTableIndex * 4 + *shader);
      currentVariant = *variantTable;
      stateKey = ((int (*)())extvsComputeStateKey)(glContext,shader,currentVariant);
      if ((*(char *)(glContext + 0x31) == '\0') ||
         (forceRebuild = true, *(char *)(shader[1] + slotTableIndex) == '\0')) {
        forceRebuild = false;
      }
      if (((stateKey != *(uint *)(currentVariant + 0x48)) || (*(int *)(currentVariant + 0x18) != shader[0x15])) ||
         (forceRebuild)) {
        for (chainEntry = variantTable[(stateKey & 0x1f) + 1]; chainEntry != 0; chainEntry = *(int *)(chainEntry + 0x2b4)) {
          if (*(uint *)(chainEntry + 0x48) == stateKey) {
            if (!forceRebuild) {
              *variantTable = chainEntry;
              shader[0x15] = *(int *)(chainEntry + 0x18);
              *(undefined4 *)(((unsigned char *)0x00001174) + glContext) = *(undefined4 *)(chainEntry + 0x18);
              goto LAB_00065094;
            }
            break;
          }
        }
        FUN_000546d0(glContext,shader);
LAB_00065094:
        *(byte *)(glContext + 0x2d) = *(byte *)(glContext + 0x2d) | 3;
      }
      else {
        ctxDirtyBits = *(byte *)(glContext + 0x2d);
        if ((ctxDirtyBits & 4) == 0) {
          if ((ctxDirtyBits & 3) == 0) {
            return;
          }
          cmdBuffer = (undefined4 *)(**(code **)(glContext + 0x2758))(glContext,2);
          *(undefined4 **)(0x00002748 + glContext + 4) = cmdBuffer;
          *cmdBuffer = 0x8a1;
          *(uint *)(*(int *)(0x00002748 + glContext + 4) + 4) = ctxDirtyBits & 4;
          cmdEnd = *(int *)(0x00002748 + glContext + 4);
          commitCallback = *(code **)(glContext + 0x275c);
          *(int *)(0x00002748 + glContext + 4) = cmdEnd + 8;
          (*commitCallback)(glContext,cmdEnd + 8);
          ((int (*)())vpUploadConstantsWithFog)(glContext,shader,currentVariant,variantTable[0x22],0);
          return;
        }
      }
      ((int (*)())extvsUploadProgramConstants)(glContext,shader);
      outputFlagCursor = glContext + 0x18a0;
      outputsLeft = 0x10;
      do {
        outputFlagByte = (byte *)((int)shader + 0x71);
        shader = (int *)((int)shader + 1);
        *(uint *)(outputFlagCursor + 8) = -(uint)*outputFlagByte >> 0x1f | *(uint *)(outputFlagCursor + 8) & 0xfffffffe;
        outputFlagCursor = outputFlagCursor + 8;
        outputsLeft = outputsLeft + -1;
      } while (outputsLeft != 0);
      return;
    }
  }
  return;
}

/* extvsFlushConstantUploads @ 0x651e0 (400 bytes) */
int extvsFlushConstantUploads(glContext)
  int glContext;
{
  undefined4 *hwProgramSlot;
  int cmdEnd;
  undefined4 *cmdBuffer;
  undefined4 in_r5;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  code *commitCallback;
  int a6;
  char *programState;
  undefined4 *uploadNode;
  int *shader;
  
  for (uploadNode = *(undefined4 **)(*(int *)(((unsigned char *)0x000011b4) + glContext) + 8); uploadNode != (undefined4 *)0x0
      ; uploadNode = (undefined4 *)uploadNode[1]) {
    ((int (*)())vpUploadConstantArray)(glContext,*uploadNode);
  }
  shader = *(int **)(((unsigned char *)0x00001168) + glContext);
  hwProgramSlot = *(undefined4 **)(*(int *)(((unsigned char *)0x0000118c) + glContext) * 4 + *shader);
  programState = (char *)*hwProgramSlot;
  if ((*(char *)(shader + 4) != '\0') && (*programState != '\0')) {
    cmdBuffer = (undefined4 *)(**(code **)(glContext + 0x2758))(glContext,4);
    *(undefined4 **)(0x00002748 + glContext + 4) = cmdBuffer;
    *cmdBuffer = 0x208b4;
    *(undefined4 *)(*(int *)(0x00002748 + glContext + 4) + 4) = *(undefined4 *)(glContext + 0x1b90);
    *(undefined4 *)(*(int *)(0x00002748 + glContext + 4) + 8) = *(undefined4 *)(glContext + 0x1b8c);
    *(undefined4 *)(*(int *)(0x00002748 + glContext + 4) + 0xc) = *(undefined4 *)(glContext + 0x1b94);
    cmdEnd = *(int *)(0x00002748 + glContext + 4);
    commitCallback = *(code **)(glContext + 0x275c);
    *(int *)(0x00002748 + glContext + 4) = cmdEnd + 0x10;
    (*commitCallback)(glContext,cmdEnd + 0x10,in_r5,in_r6,in_r7,in_r8,commitCallback);
    cmdBuffer = (undefined4 *)(**(code **)(glContext + 0x2758))(glContext,2);
    *(undefined4 **)(0x00002748 + glContext + 4) = cmdBuffer;
    *cmdBuffer = 0x8b7;
    a6 = *(int *)(0x00002748 + glContext + 4);
    *(undefined4 *)(a6 + 4) = *(undefined4 *)(glContext + 0x1b98);
    cmdEnd = *(int *)(0x00002748 + glContext + 4);
    commitCallback = *(code **)(glContext + 0x275c);
    *(int *)(0x00002748 + glContext + 4) = cmdEnd + 8;
    (*commitCallback)(glContext,cmdEnd + 8,in_r5,in_r6,in_r7,in_r8,a6);
    FUN_00050ef0(glContext,*(undefined4 *)(programState + 0x2a4),*(undefined4 *)(programState + 0x2a8),
                 *(undefined4 *)(programState + 0x2ac));
    ((int (*)())vpUploadConstantsWithFog)(glContext,shader,programState,hwProgramSlot[0x22],1);
  }
  *(uint *)(glContext + 0x8c) = *(uint *)(glContext + 0x8c) & 0xfffeffff;
  return;
}

/* ffvpSelectLitProgramVariant @ 0x65370 (636 bytes) */
int ffvpSelectLitProgramVariant(glContext)
  int glContext;
{
  undefined4 paramList;
  int variant;
  char stateDirty;
  int lightKeyB;
  undefined4 uVar3;
  undefined4 extraout_r4;
  undefined4 extraout_r4_00;
  undefined4 in_r5;
  uint in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  int lightKeyA;
  code *a6;
  undefined4 in_r10;
  undefined8 lookupResult;
  undefined4 local_38;
  undefined4 local_34 [8];
  
  stateDirty = *(char *)(glContext + 0x29);
  if (*(char *)(glContext + 0x1868) == '\0') {
    (**(code **)(((unsigned char *)0x000012e0) + glContext))(glContext);
    return;
  }
  *(undefined1 *)(glContext + 0x126) = 0;
  (**(code **)(((unsigned char *)0x0000133c) + glContext))(glContext);
  if (stateDirty == '\0') {
    lightKeyA = *(int *)(glContext + 0x13c);
    if (lightKeyA == *(int *)(glContext + 0x140)) {
      lightKeyB = *(int *)(glContext + 0x148);
      if (lightKeyB == *(int *)(glContext + 0x144)) {
        return;
      }
    }
    else {
      lightKeyB = *(int *)(glContext + 0x148);
    }
  }
  else {
    lightKeyA = *(int *)(glContext + 0x13c);
    lightKeyB = *(int *)(glContext + 0x148);
  }
  *(int *)(glContext + 0x140) = lightKeyA;
  *(int *)(glContext + 0x144) = lightKeyB;
  if (*(char *)(glContext + 0x124) != '\0') {
LAB_00065500:
    (**(code **)(((unsigned char *)0x000012dc) + glContext))(glContext);
    return;
  }
  if ((*(uint *)(glContext + 0x44) & 0x100000) != 0) {
    return;
  }
  lookupResult = fpVariantCacheLookup(glContext,glContext + 0x1874);
  variant = (int)((ulonglong)lookupResult >> 0x20);
  uVar3 = (undefined4)lookupResult;
  if (variant == 0) {
    ffvpUpdateLightModelFlags(glContext,uVar3,in_r5,in_r6,in_r7,in_r8);
    paramList = paramListCreate(glContext);
    (**(code **)(((unsigned char *)0x000012b4) + glContext))(glContext);
    in_r5 = ffvpBuildProgram(glContext,1,&local_38,local_34,paramList,in_r8,lightKeyA,in_r10);
    in_r6 = (uint)*(byte *)(glContext + 0x131);
    lookupResult = fpVariantCacheInsert(glContext,glContext + 0x1874,in_r5,in_r6,local_38,local_34[0],paramList,
                         (uint)*(byte *)(glContext + 0x126));
    variant = (int)((ulonglong)lookupResult >> 0x20);
    in_r7 = local_38;
    in_r8 = local_34[0];
    if (*(char *)(glContext + 0x126) != '\0') {
      a6 = *(code **)(((unsigned char *)0x0000133c) + glContext);
      *(uint *)(glContext + 0x8c) = *(uint *)(glContext + 0x8c) | 0x40000000;
      *(uint *)(glContext + 0x38) = *(uint *)(glContext + 0x38) | 0x1020;
      *(undefined1 *)(glContext + 0x29) = 1;
      (*a6)(glContext,(int)lookupResult,in_r5,in_r6,local_38,local_34[0],a6);
      goto LAB_00065500;
    }
  }
  else if (*(char *)(variant + 0x59) != '\0') goto LAB_0006559c;
  *(int *)(glContext + 0x14c) = variant;
  (**(code **)(((unsigned char *)0x000012c4) + glContext))(glContext,variant);
  if (*(int *)(variant + 0x54) + 0x750 == *(int *)(((unsigned char *)0x0000148c) + glContext)) {
    (**(code **)((int)((unsigned char *)0x000012a0) + glContext))(glContext);
    uVar3 = extraout_r4;
  }
  else {
    in_r5 = *(undefined4 *)(variant + 0x3c);
    (**(code **)((int)((unsigned char *)0x00001294) + glContext))(glContext,variant,in_r5);
    uVar3 = extraout_r4_00;
  }
  if (*(char *)(*(int *)(variant + 0x54) + 0x752) == '\0') {
    return;
  }
LAB_0006559c:
  *(uint *)(glContext + 0x38) = *(uint *)(glContext + 0x38) | 0x1020;
  *(uint *)(glContext + 0x8c) = *(uint *)(glContext + 0x8c) | 0x40000000;
  *(undefined1 *)(glContext + 0x126) = 1;
  *(undefined1 *)(glContext + 0x29) = 1;
  (**(code **)(((unsigned char *)0x0000133c) + glContext))(glContext,uVar3,in_r5,in_r6,in_r7,in_r8,1);
  (**(code **)(((unsigned char *)0x000012dc) + glContext))(glContext);
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

/* ffvpSelectPassThroughVariant @ 0x656b0 (780 bytes) */
int ffvpSelectPassThroughVariant(glContext)
  int glContext;
{
  int nextOutputReg;
  int unitCursor;
  int colorOutReg;
  int texUnit;
  uint nextTexReg;
  uint positionPassThrough;
  uint loopIndex;
  byte bVar1;
  uint backColorOut;
  int iVar3;
  int variant;
  undefined4 *builder;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 in_r7;
  undefined4 in_r8;
  uint in_r9;
  uint ctxFlags;
  uint uVar9;
  uint outputMask;
  int currentVariant;
  uint pointSizeOut;
  undefined4 local_74;
  uint variantKey [2];
  undefined4 variantKeyOutputMask;
  uint variantKeyFlags;
  
  _memset(variantKey,0,0x30);
  ctxFlags = *(uint *)(glContext + 0x44);
  variantKeyOutputMask = *(undefined4 *)(glContext + 0x1804);
  variantKey[0] = variantKey[0] | 8;
  if ((ctxFlags & 0xc00) != 0) {
    in_r9 = ctxFlags >> 9 & 2;
    variantKeyFlags = ctxFlags >> 0xb & 1 | in_r9 | (uint)(byte)((unsigned char *)0x000011d3)[glContext] << 2;
  }
  currentVariant = *(int *)(glContext + 0x14c);
  if ((currentVariant == 0) || (iVar3 = _memcmp(currentVariant,variantKey,0x30), variant = currentVariant, iVar3 != 0)) {
    variant = fpVariantCacheLookup(glContext,variantKey);
    if (variant == 0) {
      outputMask = *(uint *)(glContext + 0x1804);
      bVar1 = ((unsigned char *)0x000011d2)[glContext];
      positionPassThrough = *(uint *)(glContext + 0x44) >> 10 & 1;
      builder = (undefined4 *)ffvpCreateBuilder(glContext,1,0);
      *builder = 0;
      ((int (*)())FUN_00065610)(glContext,builder);
      if (positionPassThrough == 0) {
        backColorOut = outputMask >> 3 & 1;
        pointSizeOut = outputMask >> 1 & 1;
        uVar9 = 0;
      }
      else {
        backColorOut = outputMask >> 3 & 1;
        pointSizeOut = outputMask >> 1 & 1;
        in_r9 = (outputMask & 1) + pointSizeOut;
        uVar9 = (uint)bVar1 + backColorOut * 2 + in_r9 + 2;
      }
      ffvpEmitPositionPassThrough(builder,positionPassThrough,(uint)bVar1);
      if (pointSizeOut == 0) {
        colorOutReg = 1;
        nextOutputReg = 2;
      }
      else {
        colorOutReg = 2;
        nextOutputReg = 3;
        builder[0x13] = 1;
        ffvpEmitPointSizePassThrough(builder);
      }
      builder[3] = colorOutReg;
      uVar6 = 0;
      uVar7 = 0;
      ffvpEmitColorPassThrough(builder,3,0,0);
      if ((outputMask & 1) != 0) {
        builder[4] = nextOutputReg;
        uVar6 = 1;
        uVar7 = 0;
        ffvpEmitColorPassThrough(builder,4,1,0);
        if ((outputMask & 4) != 0) {
          builder[0x14] = nextOutputReg;
          builder[0x15] = 3;
          ffvpEmitFogPassThrough(builder);
        }
        nextOutputReg = colorOutReg + 2;
      }
      if (backColorOut != 0) {
        builder[5] = nextOutputReg;
        ffvpEmitColorPassThrough(builder,3,2,1);
        builder[6] = nextOutputReg + 1;
        builder[0x20] = 0;
        uVar6 = 3;
        uVar7 = 1;
        nextOutputReg = nextOutputReg + 2;
        ffvpEmitColorPassThrough(builder,4,3,1);
      }
      nextTexReg = (uint)(backColorOut != 0);
      if (outputMask >> 4 != 0) {
        loopIndex = 0;
        unitCursor = glContext;
        do {
          texUnit = *(int *)(unitCursor + 0x1824);
          builder[texUnit + 0xb] = nextOutputReg;
          nextOutputReg = nextOutputReg + 1;
          if (nextTexReg == uVar9) {
            nextTexReg = nextTexReg + 1;
          }
          builder[texUnit + 0x21] = nextTexReg;
          loopIndex = loopIndex + 1;
          nextTexReg = nextTexReg + 1;
          unitCursor = unitCursor + 4;
          ffvpEmitTexCoordPassThrough(builder,texUnit,uVar6,uVar7,in_r7,in_r8,in_r9);
        } while (outputMask >> 4 != loopIndex);
      }
      ffvpFinishProgram(builder);
      variant = fpVariantCacheInsert(glContext,variantKey,builder,nextOutputReg,local_74,0,0,1);
      *(undefined4 *)(variant + 0x34) = 0;
      *(int *)(variant + 0x38) = *(int *)(*(int *)(variant + 0x54) + 0x3cc) + -1;
      currentVariant = *(int *)(glContext + 0x14c);
    }
    else {
      currentVariant = *(int *)(glContext + 0x14c);
    }
  }
  if (variant != currentVariant) {
    *(int *)(glContext + 0x14c) = variant;
    *(uint *)(glContext + 0x8c) = *(uint *)(glContext + 0x8c) | 0x40000;
  }
  (**(code **)((int)((unsigned char *)0x00001294) + glContext))
            (glContext,*(int *)(variant + 0x54) + 0x750,*(undefined4 *)(variant + 0x3c));
  return;
}

/* vpFillConstantBank @ 0x659d0 (612 bytes) */
void vpFillConstantBank(int glContext,int variant,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  int maskWordPtr;
  int maskWordIndex;
  int constantCount;
  uint maskBit;
  int programData;
  int clearPtr;
  int glStateExt;
  uint loopIndex;
  int constantBank;
  undefined4 constantData;
  undefined4 *constantOut;
  int clearWordsLeft;
  double in_stack_ffffffa8;
  double in_stack_ffffffb0;
  double in_stack_ffffffb8;
  double in_stack_ffffffc0;
  double in_stack_ffffffc8;
  
  clearWordsLeft = 8;
  programData = *(int *)(variant + 0x54);
  constantBank = programData + 0x750;
  glStateExt = *(int *)(*(int *)(glContext + 4) + 0x10);
  constantOut = (undefined4 *)(programData + 0x768);
  clearPtr = constantBank;
  do {
    *(undefined4 *)(((unsigned char *)0x00001018) + clearPtr) = 0;
    clearPtr = clearPtr + 4;
    clearWordsLeft = clearWordsLeft + -1;
  } while (clearWordsLeft != 0);
  *(undefined4 *)(programData + 0x1990) = 0xffff;
  if (*(char *)(variant + 0x58) == '\0') {
    constantCount = 0;
    if (*(int *)(variant + 0x48) != 0) {
      constantData = *(undefined4 *)(variant + 0x4c);
      ((void (*)())programFillStateConstants)(glContext,variant,param_3,param_4,param_5,param_6,glStateExt,param_8,fparam_1,fparam_2,
                   fparam_3,fparam_4,fparam_5,fparam_6,fparam_7,fparam_8,in_stack_ffffffa8,
                   in_stack_ffffffb0,in_stack_ffffffb8,in_stack_ffffffc0,in_stack_ffffffc8);
      _memcpy(constantOut,constantData,*(int *)(variant + 0x48) << 4);
      constantCount = *(int *)(variant + 0x48);
      if (0 < constantCount) {
        loopIndex = 0;
        do {
          maskWordIndex = ((int)loopIndex >> 5) + (uint)((int)loopIndex < 0 && (loopIndex & 0x1f) != 0);
          maskWordPtr = maskWordIndex * 4 + constantBank;
          maskBit = loopIndex + maskWordIndex * -0x20;
          loopIndex = loopIndex + 1;
          *(uint *)(((unsigned char *)0x00001018) + maskWordPtr) = 1 << (maskBit & 0x3f) | *(uint *)(((unsigned char *)0x00001018) + maskWordPtr);
          constantCount = *(int *)(variant + 0x48);
        } while ((int)loopIndex < constantCount);
      }
    }
    *(int *)(programData + 0x1788) = constantCount;
  }
  else {
    if ((*(uint *)(((unsigned char *)0x000013c0) + glContext) & 4) == 0) {
      *constantOut = *(undefined4 *)(glStateExt + 0x2460);
      *(undefined4 *)(programData + 0x76c) = *(undefined4 *)(glStateExt + 0x2470);
      *(undefined4 *)(programData + 0x770) = *(undefined4 *)(glStateExt + 0x2480);
      *(undefined4 *)(programData + 0x774) = *(undefined4 *)(glStateExt + 0x2490);
      *(undefined4 *)(programData + 0x778) = *(undefined4 *)(glStateExt + 0x2464);
      *(undefined4 *)(programData + 0x77c) = *(undefined4 *)(glStateExt + 0x2474);
      *(undefined4 *)(programData + 0x780) = *(undefined4 *)(glStateExt + 0x2484);
      *(undefined4 *)(programData + 0x784) = *(undefined4 *)(glStateExt + 0x2494);
      *(undefined4 *)(programData + 0x788) = *(undefined4 *)(glStateExt + 0x2468);
      *(undefined4 *)(programData + 0x78c) = *(undefined4 *)(glStateExt + 0x2478);
      *(undefined4 *)(programData + 0x790) = *(undefined4 *)(glStateExt + 0x2488);
      *(undefined4 *)(programData + 0x794) = *(undefined4 *)(glStateExt + 0x2498);
      *(undefined4 *)(programData + 0x798) = *(undefined4 *)(glStateExt + 0x246c);
      *(undefined4 *)(programData + 0x79c) = *(undefined4 *)(glStateExt + 0x247c);
      *(undefined4 *)(programData + 0x7a0) = *(undefined4 *)(glStateExt + 0x248c);
      *(undefined4 *)(programData + 0x7a4) = *(undefined4 *)(glStateExt + 0x249c);
    }
    else {
      *constantOut = *(undefined4 *)(glStateExt + 0x2460);
      *(undefined4 *)(programData + 0x76c) = *(undefined4 *)(glStateExt + 0x2464);
      *(undefined4 *)(programData + 0x770) = *(undefined4 *)(glStateExt + 0x2468);
      *(undefined4 *)(programData + 0x774) = *(undefined4 *)(glStateExt + 0x246c);
      *(undefined4 *)(programData + 0x778) = *(undefined4 *)(glStateExt + 0x2470);
      *(undefined4 *)(programData + 0x77c) = *(undefined4 *)(glStateExt + 0x2474);
      *(undefined4 *)(programData + 0x780) = *(undefined4 *)(glStateExt + 0x2478);
      *(undefined4 *)(programData + 0x784) = *(undefined4 *)(glStateExt + 0x247c);
      *(undefined4 *)(programData + 0x788) = *(undefined4 *)(glStateExt + 0x2480);
      *(undefined4 *)(programData + 0x78c) = *(undefined4 *)(glStateExt + 0x2484);
      *(undefined4 *)(programData + 0x790) = *(undefined4 *)(glStateExt + 0x2488);
      *(undefined4 *)(programData + 0x794) = *(undefined4 *)(glStateExt + 0x248c);
      *(undefined4 *)(programData + 0x798) = *(undefined4 *)(glStateExt + 0x2490);
      *(undefined4 *)(programData + 0x79c) = *(undefined4 *)(glStateExt + 0x2494);
      *(undefined4 *)(programData + 0x7a0) = *(undefined4 *)(glStateExt + 0x2498);
      *(undefined4 *)(programData + 0x7a4) = *(undefined4 *)(glStateExt + 0x249c);
    }
    *(undefined4 *)(programData + 0x1768) = 0xf;
    *(undefined4 *)(programData + 0x1788) = 4;
  }
  if ((*(char *)(programData + 0x751) != '\0') && (constantBank == *(int *)(((unsigned char *)0x0000148c) + glContext))) {
                    
                    
    (**(code **)((int)((unsigned char *)0x000012a0) + glContext))(glContext,constantBank);
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
asm(".set FUN_0005f540, _extvsRewriteHardwareInstructions");
asm(".globl extvsPrepareHardwareProgram");
asm(".set extvsPrepareHardwareProgram, _extvsPrepareHardwareProgram");
asm(".globl FUN_00062370");
asm(".set FUN_00062370, _FUN_00062370");
asm(".globl extvsInitLimits");
asm(".set extvsInitLimits, _extvsInitLimits");
asm(".globl FUN_00062410");
asm(".set FUN_00062410, _FUN_00062410");
asm(".globl FUN_00062510");
asm(".set FUN_00062510, _FUN_00062510");
asm(".globl extvsStateCacheCreate");
asm(".set extvsStateCacheCreate, _extvsStateCacheCreate");
asm(".globl extvsStateCacheFreeAll");
asm(".set extvsStateCacheFreeAll, _extvsStateCacheFreeAll");
asm(".globl FUN_00062940");
asm(".set FUN_00062940, _extvsUploadSingleConstant");
asm(".globl extvsBuildStreamDescriptors");
asm(".set extvsBuildStreamDescriptors, _extvsBuildStreamDescriptors");
asm(".globl gldCurrentAttributePacketHeader");
asm(".set gldCurrentAttributePacketHeader, _gldCurrentAttributePacketHeader");
asm(".globl FUN_00064230");
asm(".set FUN_00064230, _FUN_00064230");
asm(".globl FUN_00064850");
asm(".set FUN_00064850, _extvsApplyStreamDescriptors");
asm(".globl FUN_00064a10");
asm(".set FUN_00064a10, _extvsUploadProgramConstants");
asm(".globl FUN_00064f40");
asm(".set FUN_00064f40, _extvsValidateProgramState");
asm(".globl FUN_00065610");
asm(".set FUN_00065610, _FUN_00065610");
asm(".globl FUN_000659d0");
asm(".set FUN_000659d0, _vpFillConstantBank");
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
