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
  int hwProgramOrInstSlot;
  int tempSlotRecord;
  int instCountValue;
  undefined4 newInstArray;
  int *symbolList;
  int src0Operand;
  int src1Operand;
  int hwProgram;
  int instSlot;
  int hwProgram2;
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
    hwProgramOrInstSlot = **(int **)(*(int *)(((unsigned char *)0x0000118c) + ctx) * 4 + *shader);
    instCount = *(int *)(hwProgramOrInstSlot + 0x18);
    if (0x100 < instCount + 2U) {
      *(undefined1 *)(shader + 4) = 0;
      instCount = *(int *)(hwProgramOrInstSlot + 0x18);
      if (*(uint *)(hwProgramOrInstSlot + 0x20) < instCount + 2U) {
        newInstArray = (**(code **)(ctx + 0xc))(*(uint *)(hwProgramOrInstSlot + 0x20) * 0x10 + 0x100);
        (**(code **)(((unsigned char *)0x00001344) + ctx))
                  (newInstArray,*(undefined4 *)(hwProgramOrInstSlot + 0x1c),*(int *)(hwProgramOrInstSlot + 0x20) << 4);
        (**(code **)(ctx + 0x18))(*(undefined4 *)(hwProgramOrInstSlot + 0x1c));
        *(undefined4 *)(hwProgramOrInstSlot + 0x1c) = newInstArray;
        instCount = *(int *)(hwProgramOrInstSlot + 0x18);
        *(int *)(hwProgramOrInstSlot + 0x20) = *(int *)(hwProgramOrInstSlot + 0x20) + 0x10;
      }
    }
    hwProgramOrInstSlot = instCount * 0x10 + *(int *)(hwProgramOrInstSlot + 0x1c);
    tempSlot = extvsAllocTempSlot(ctx,shader);
    operandAKind = 3;
    operandAFlag = 0;
    operandASelW = 1;
    operandASelX = 1;
    operandASelY = 1;
    operandASelZ = 1;
    operandAIndex = tempSlot;
    extvsEncodeSourceOperand(ctx,shader,&operandAKind,hwProgramOrInstSlot,2,0,0);
    extvsEncodeSourceSwizzle(shader,symbolList,src0Operand,hwProgramOrInstSlot + 4,0);
    swizzleWord = *(uint *)(hwProgramOrInstSlot + 4);
    *(uint *)(hwProgramOrInstSlot + 4) =
         (swizzleWord & 0x4000000) << 1 |
         (swizzleWord & 0x2000000) << 1 |
         swizzleWord >> 2 & 0x2000000 |
         (swizzleWord & 0x70000) << 3 | (swizzleWord & 0xe000) << 3 | swizzleWord >> 6 & 0xe000 | swizzleWord & 0xe0001fff |
         0x1000000;
    extvsEncodeSourceSwizzle(shader,symbolList,src1Operand,hwProgramOrInstSlot + 8,0);
    swizzleWord = *(uint *)(hwProgramOrInstSlot + 8);
    swizzleWord = (swizzleWord & 0x2000000) << 2 |
            swizzleWord >> 1 & 0x4000000 |
            swizzleWord >> 1 & 0x2000000 |
            (swizzleWord & 0xe000) << 6 | swizzleWord >> 3 & 0x70000 | swizzleWord >> 3 & 0xe000 | swizzleWord & 0xe0001fff
            | 0x1000000;
    *(uint *)(hwProgramOrInstSlot + 0xc) = swizzleWord;
    *(uint *)(hwProgramOrInstSlot + 8) = swizzleWord;
    extvsEncodeSourceOperand(ctx,shader,iStack00000020 + 4,hwProgramOrInstSlot + 0x10,4,0,0);
    extvsEncodeSourceSwizzle(shader,symbolList,src0Operand,hwProgramOrInstSlot + 0x14,0);
    swizzleWord = *(uint *)(hwProgramOrInstSlot + 0x14);
    *(uint *)(hwProgramOrInstSlot + 0x14) =
         (swizzleWord & 0x2000000) << 2 |
         swizzleWord >> 1 & 0x4000000 |
         swizzleWord >> 1 & 0x2000000 |
         (swizzleWord & 0xe000) << 6 | swizzleWord >> 3 & 0x70000 | swizzleWord >> 3 & 0xe000 | swizzleWord & 0xe0001fff |
         0x1400000;
    extvsEncodeSourceSwizzle(shader,symbolList,src1Operand,hwProgramOrInstSlot + 0x18,0);
    swizzleWord = *(uint *)(hwProgramOrInstSlot + 0x18);
    *(uint *)(hwProgramOrInstSlot + 0x18) =
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
    extvsEncodeSourceSwizzle(shader,symbolList,&operandBKind,hwProgramOrInstSlot + 0x1c,0);
    emittedInstCount = 2;
  }
  else {
    hwProgram2 = **(int **)(*(int *)(((unsigned char *)0x0000118c) + ctx) * 4 + *shader);
    instCountValue = *(int *)(hwProgram2 + 0x18);
    if (0x100 < instCountValue + 3U) {
      *(undefined1 *)(shader + 4) = 0;
      instCountValue = *(int *)(hwProgram2 + 0x18);
      if (*(uint *)(hwProgram2 + 0x20) < instCountValue + 3U) {
        newInstArray = (**(code **)(ctx + 0xc))(*(uint *)(hwProgram2 + 0x20) * 0x10 + 0x100);
        (**(code **)(((unsigned char *)0x00001344) + ctx))
                  (newInstArray,*(undefined4 *)(hwProgram2 + 0x1c),*(int *)(hwProgram2 + 0x20) << 4);
        (**(code **)(ctx + 0x18))(*(undefined4 *)(hwProgram2 + 0x1c));
        *(undefined4 *)(hwProgram2 + 0x1c) = newInstArray;
        instCountValue = *(int *)(hwProgram2 + 0x18);
        *(int *)(hwProgram2 + 0x20) = *(int *)(hwProgram2 + 0x20) + 0x10;
      }
    }
    instSlot = instCountValue * 0x10 + *(int *)(hwProgram2 + 0x1c);
    tempIndex = extvsAllocTempSlot(ctx,shader);
    operandBPtr = &operandBKind;
    hwProgram = **(int **)(*(int *)(((unsigned char *)0x0000118c) + ctx) * 4 + *shader);
    tempSlotRecord = tempIndex * 0x28 + *(int *)(hwProgram + 0x4c);
    savedSlotFlag = *(undefined1 *)(tempSlotRecord + 0x10);
    *(undefined1 *)(tempSlotRecord + 0x10) = 1;
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
  int instCount2;
  int src0Operand2;
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
      instCount2 = *(int *)(hwProgram2 + 0x18);
      if (0x100 < instCount2 + 4U) {
        *(undefined1 *)(shader + 4) = 0;
        instCount2 = *(int *)(hwProgram2 + 0x18);
        if (*(uint *)(hwProgram2 + 0x20) < instCount2 + 4U) {
          newInstArray = (**(code **)(ctx + 0xc))(*(uint *)(hwProgram2 + 0x20) * 0x10 + 0x100);
          (**(code **)(((unsigned char *)0x00001344) + ctx))
                    (newInstArray,*(undefined4 *)(hwProgram2 + 0x1c),*(int *)(hwProgram2 + 0x20) << 4);
          (**(code **)(ctx + 0x18))(*(undefined4 *)(hwProgram2 + 0x1c));
          *(undefined4 *)(hwProgram2 + 0x1c) = newInstArray;
          instCount2 = *(int *)(hwProgram2 + 0x18);
          *(int *)(hwProgram2 + 0x20) = *(int *)(hwProgram2 + 0x20) + 0x10;
        }
      }
      instArrayBase = *(int *)(hwProgram2 + 0x1c);
      instCount2 = instCount2 * 0x10;
      dstOperand = instRecord + 4;
      slotAddr = instCount2 + instArrayBase;
      extvsEncodeSourceOperand(ctx,shader,dstOperand,slotAddr,1,0,0);
      *(uint *)(instCount2 + instArrayBase) = *(uint *)(instCount2 + instArrayBase) & 0xff1fffff;
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
  src0Operand2 = instRecord + 0x20;
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
  extvsEncodeSourceSwizzle(shader,symbolList,src0Operand2,instSlot + 0x14,0);
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
  extvsEncodeSourceSwizzle(shader,symbolList,src0Operand2,instSlot + 0x24,1);
  extvsEncodeSourceSwizzle(shader,symbolList,&operandBKind,instSlot + 0x28,0);
  *(undefined4 *)(instSlot + 0x2c) = *(undefined4 *)(instSlot + 0x28);
  extvsEncodeSourceOperand(ctx,shader,dstOperand,instSlot + 0x30,1,0,0);
  *(uint *)(instSlot + 0x30) = *(uint *)(instSlot + 0x30) & 0xff4fffff;
  extvsEncodeSourceSwizzle(shader,symbolList,src0Operand2,instSlot + 0x34,2);
  extvsEncodeSourceSwizzle(shader,symbolList,&operandBKind,instSlot + 0x38,0);
  *(undefined4 *)(instSlot + 0x3c) = *(undefined4 *)(instSlot + 0x38);
  extvsEncodeSourceOperand(ctx,shader,dstOperand,instSlot + 0x40,1,0,0);
  *(uint *)(instSlot + 0x40) = *(uint *)(instSlot + 0x40) & 0xff8fffff;
  extvsEncodeSourceSwizzle(shader,symbolList,src0Operand2,instSlot + 0x44,3);
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
  uint swizzleWord;
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
  swizzleWord = *(uint *)(instSlot + 4) & 0xfe001fff | 0x1248000;
  *(uint *)(instSlot + 0xc) = swizzleWord;
  *(uint *)(instSlot + 8) = swizzleWord;
  return 1;
}

/* extvsEmitSwizzle @ 0x5cd60 (1228 bytes) */
int extvsEmitSwizzle(ctx, shader, instRecord)
  int ctx;
  int *shader;
  int instRecord;
{
  uint selectMask3;
  uint selectMask2;
  uint selectMask1;
  int instSlot;
  uint swizzleWord;
  uint selectMask0;
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
    swizzleWord = *(uint *)(instSlot + 4) & 0xffff1fff;
    *(uint *)(instSlot + 4) = swizzleWord;
    break;
  case 0x87d6:
  case 0x87da:
    swizzleWord = *(uint *)(instSlot + 4) & 0xffff1fff | 0x2000;
    *(uint *)(instSlot + 4) = swizzleWord;
    break;
  case 0x87d7:
  case 0x87db:
    swizzleWord = *(uint *)(instSlot + 4) & 0xffff1fff | 0x4000;
    *(uint *)(instSlot + 4) = swizzleWord;
    break;
  case 0x87d8:
  case 0x87dc:
    swizzleWord = *(uint *)(instSlot + 4) & 0xffff1fff | 0x6000;
    *(uint *)(instSlot + 4) = swizzleWord;
    break;
  case 0x87dd:
    swizzleWord = *(uint *)(instSlot + 4) & 0xffff1fff | 0x8000;
    *(uint *)(instSlot + 4) = swizzleWord;
    break;
  case 0x87de:
  case 0x87df:
    swizzleWord = *(uint *)(instSlot + 4) & 0xffff1fff | 0xa000;
    *(uint *)(instSlot + 4) = swizzleWord;
    break;
  default:
    goto LAB_0005d2d0;
  }
  selectMask0 = *(int *)(instRecord + 0x28) - 0x87d5;
  if (selectMask0 < 0xb) {
    selectMask0 = 1 << (selectMask0 & 0x3f);
    if ((selectMask0 & 0x30f) == 0) {
      if ((selectMask0 & 0x4f0) == 0) {
        return 0;
      }
      swizzleWord = swizzleWord | 0x2000000;
      *(uint *)(instSlot + 4) = swizzleWord;
    }
    else {
      swizzleWord = swizzleWord & 0xfdffffff;
      *(uint *)(instSlot + 4) = swizzleWord;
    }
    switch(*(undefined4 *)(instRecord + 0x2c)) {
    case 0x87d5:
    case 0x87d9:
      swizzleWord = swizzleWord & 0xfff8ffff;
      *(uint *)(instSlot + 4) = swizzleWord;
      break;
    case 0x87d6:
    case 0x87da:
      swizzleWord = swizzleWord & 0xfff8ffff | 0x10000;
      *(uint *)(instSlot + 4) = swizzleWord;
      break;
    case 0x87d7:
    case 0x87db:
      swizzleWord = swizzleWord & 0xfff8ffff | 0x20000;
      *(uint *)(instSlot + 4) = swizzleWord;
      break;
    case 0x87d8:
    case 0x87dc:
      swizzleWord = swizzleWord & 0xfff8ffff | 0x30000;
      *(uint *)(instSlot + 4) = swizzleWord;
      break;
    case 0x87dd:
      swizzleWord = swizzleWord & 0xfff8ffff | 0x40000;
      *(uint *)(instSlot + 4) = swizzleWord;
      break;
    case 0x87de:
    case 0x87df:
      swizzleWord = swizzleWord & 0xfff8ffff | 0x50000;
      *(uint *)(instSlot + 4) = swizzleWord;
      break;
    default:
      goto LAB_0005d2d0;
    }
    selectMask1 = *(int *)(instRecord + 0x2c) - 0x87d5;
    if (selectMask1 < 0xb) {
      selectMask1 = 1 << (selectMask1 & 0x3f);
      if ((selectMask1 & 0x30f) == 0) {
        if ((selectMask1 & 0x4f0) == 0) {
          return 0;
        }
        swizzleWord = swizzleWord | 0x4000000;
        *(uint *)(instSlot + 4) = swizzleWord;
      }
      else {
        swizzleWord = swizzleWord & 0xfbffffff;
        *(uint *)(instSlot + 4) = swizzleWord;
      }
      switch(*(undefined4 *)(instRecord + 0x30)) {
      case 0x87d5:
      case 0x87d9:
        swizzleWord = swizzleWord & 0xffc7ffff;
        *(uint *)(instSlot + 4) = swizzleWord;
        break;
      case 0x87d6:
      case 0x87da:
        swizzleWord = swizzleWord & 0xffc7ffff | 0x80000;
        *(uint *)(instSlot + 4) = swizzleWord;
        break;
      case 0x87d7:
      case 0x87db:
        swizzleWord = swizzleWord & 0xffc7ffff | 0x100000;
        *(uint *)(instSlot + 4) = swizzleWord;
        break;
      case 0x87d8:
      case 0x87dc:
        swizzleWord = swizzleWord & 0xffc7ffff | 0x180000;
        *(uint *)(instSlot + 4) = swizzleWord;
        break;
      case 0x87dd:
        swizzleWord = swizzleWord & 0xffc7ffff | 0x200000;
        *(uint *)(instSlot + 4) = swizzleWord;
        break;
      case 0x87de:
      case 0x87df:
        swizzleWord = swizzleWord & 0xffc7ffff | 0x280000;
        *(uint *)(instSlot + 4) = swizzleWord;
        break;
      default:
        goto LAB_0005d2d0;
      }
      selectMask2 = *(int *)(instRecord + 0x30) - 0x87d5;
      if (selectMask2 < 0xb) {
        selectMask2 = 1 << (selectMask2 & 0x3f);
        if ((selectMask2 & 0x30f) == 0) {
          if ((selectMask2 & 0x4f0) == 0) {
            return 0;
          }
          swizzleWord = swizzleWord | 0x8000000;
          *(uint *)(instSlot + 4) = swizzleWord;
        }
        else {
          swizzleWord = swizzleWord & 0xf7ffffff;
          *(uint *)(instSlot + 4) = swizzleWord;
        }
        switch(*(undefined4 *)(instRecord + 0x34)) {
        case 0x87d5:
        case 0x87d9:
          swizzleWord = swizzleWord & 0xfe3fffff;
          *(uint *)(instSlot + 4) = swizzleWord;
          break;
        case 0x87d6:
        case 0x87da:
          swizzleWord = swizzleWord & 0xfe3fffff | 0x400000;
          *(uint *)(instSlot + 4) = swizzleWord;
          break;
        case 0x87d7:
        case 0x87db:
          swizzleWord = swizzleWord & 0xfe3fffff | 0x800000;
          *(uint *)(instSlot + 4) = swizzleWord;
          break;
        case 0x87d8:
        case 0x87dc:
          swizzleWord = swizzleWord & 0xfe3fffff | 0xc00000;
          *(uint *)(instSlot + 4) = swizzleWord;
          break;
        case 0x87dd:
          swizzleWord = swizzleWord & 0xfe3fffff | 0x1000000;
          *(uint *)(instSlot + 4) = swizzleWord;
          break;
        case 0x87de:
        case 0x87df:
          swizzleWord = swizzleWord & 0xfe3fffff | 0x1400000;
          *(uint *)(instSlot + 4) = swizzleWord;
          break;
        default:
          goto LAB_0005d2d0;
        }
        selectMask3 = *(int *)(instRecord + 0x34) - 0x87d5;
        if (selectMask3 < 0xb) {
          selectMask3 = 1 << (selectMask3 & 0x3f);
          if ((selectMask3 & 0x30f) == 0) {
            if ((selectMask3 & 0x4f0) == 0) {
              return 0;
            }
            swizzleWord = swizzleWord | 0x10000000;
            *(uint *)(instSlot + 4) = swizzleWord;
          }
          else {
            swizzleWord = swizzleWord & 0xefffffff;
            *(uint *)(instSlot + 4) = swizzleWord;
          }
          swizzleWord = swizzleWord & 0xe0001fff | 0x1248000;
          *(uint *)(instSlot + 0xc) = swizzleWord;
          *(uint *)(instSlot + 8) = swizzleWord;
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
  uint maskBitY;
  uint maskBitZ;
  uint oldSlotWord;
  uint maskBitX;
  uint swizzleWord;
  undefined4 newInstArray;
  int hwProgram;
  int instSlot;
  int instArray;
  int instCountOrOffset;
  
  hwProgram = **(int **)(*(int *)(((unsigned char *)0x0000118c) + ctx) * 4 + *shader);
  instCountOrOffset = *(int *)(hwProgram + 0x18);
  if (0x100 < instCountOrOffset + 1U) {
    *(undefined1 *)(shader + 4) = 0;
    instCountOrOffset = *(int *)(hwProgram + 0x18);
    if (*(uint *)(hwProgram + 0x20) < instCountOrOffset + 1U) {
      newInstArray = (**(code **)(ctx + 0xc))(*(uint *)(hwProgram + 0x20) * 0x10 + 0x100);
      (**(code **)(((unsigned char *)0x00001344) + ctx))
                (newInstArray,*(undefined4 *)(hwProgram + 0x1c),*(int *)(hwProgram + 0x20) << 4);
      (**(code **)(ctx + 0x18))(*(undefined4 *)(hwProgram + 0x1c));
      *(undefined4 *)(hwProgram + 0x1c) = newInstArray;
      instCountOrOffset = *(int *)(hwProgram + 0x18);
      *(int *)(hwProgram + 0x20) = *(int *)(hwProgram + 0x20) + 0x10;
    }
  }
  instArray = *(int *)(hwProgram + 0x1c);
  instCountOrOffset = instCountOrOffset * 0x10;
  instSlot = instCountOrOffset + instArray;
  extvsEncodeSourceOperand(ctx,shader,instRecord + 4,instSlot,3,0,0);
  oldSlotWord = *(uint *)(instCountOrOffset + instArray);
  maskBitX = (*(uint *)(instRecord + 0xc) & 1) << 0x14;
  *(uint *)(instCountOrOffset + instArray) = maskBitX | oldSlotWord & 0xffefffff;
  maskBitY = (*(uint *)(instRecord + 0x10) & 1) << 0x15;
  *(uint *)(instCountOrOffset + instArray) = maskBitY | maskBitX | oldSlotWord & 0xffcfffff;
  maskBitZ = (*(uint *)(instRecord + 0x14) & 1) << 0x16;
  *(uint *)(instCountOrOffset + instArray) = maskBitZ | maskBitY | maskBitX | oldSlotWord & 0xff8fffff;
  *(uint *)(instCountOrOffset + instArray) =
       (*(uint *)(instRecord + 0x18) & 1) << 0x17 | maskBitZ | maskBitY | maskBitX | oldSlotWord & 0xff0fffff;
  extvsEncodeSourceSwizzle(shader,shader + 7,instRecord + 0x20,instSlot + 4,0);
  swizzleWord = *(uint *)(instSlot + 4) & 0xfe001fff | 0x1248000;
  *(uint *)(instSlot + 0xc) = swizzleWord;
  *(uint *)(instSlot + 8) = swizzleWord;
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
  uint swizzleWord;
  undefined4 result;
  undefined4 newInstArray;
  int instCount;
  int hwProgram;
  int dstOperand;
  
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
  dstOperand = instRecord + 4;
  instSlot = instCount * 0x10 + *(int *)(hwProgram + 0x1c);
  extvsOperandDataTypeResult = extvsOperandDataType(shader + 7,dstOperand);
  if (*(uint *)(instRecord + 0x40) < 4) {
    if (extvsOperandDataTypeResult == 0x87bf) {
      extvsEncodeSourceOperand(ctx,shader,dstOperand,instSlot,3,0,0);
    }
    else {
      if (extvsOperandDataTypeResult != 0x87c0) goto setResult;
      extvsEncodeSourceOperand(ctx,shader,dstOperand,instSlot,3,0,*(uint *)(instRecord + 0x40));
    }
    extvsEncodeSourceSwizzle(shader,shader + 7,instRecord + 0x20,instSlot + 4,0);
    result = 1;
    swizzleWord = *(uint *)(instSlot + 4) & 0xfe001fff | 0x1248000;
    *(uint *)(instSlot + 0xc) = swizzleWord;
    *(uint *)(instSlot + 8) = swizzleWord;
  }
  else {
setResult:
    result = 0xffffffff;
  }
  return result;
}

/* extvsEmitOp879d @ 0x5d620 (568 bytes) */
int extvsEmitOp879d(ctx, shader, instRecord)
  int ctx;
  int *shader;
  int instRecord;
{
  int instSlot;
  int extvsOperandDataTypeResult;
  undefined4 newInstArray;
  undefined4 result;
  int instCount;
  int src0Operand;
  int *symbolList;
  int hwProgram;
  uint componentSelect;
  uint swizzleWord;
  
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
  symbolList = shader + 7;
  src0Operand = instRecord + 0x20;
  instSlot = instCount * 0x10 + *(int *)(hwProgram + 0x1c);
  extvsOperandDataTypeResult = extvsOperandDataType(symbolList,src0Operand);
  componentSelect = *(uint *)(instRecord + 0x40);
  if (componentSelect < 4) {
    extvsEncodeSourceOperand(ctx,shader,instRecord + 4,instSlot,3,0,0);
    if (extvsOperandDataTypeResult == 0x87bf) {
      extvsEncodeSourceSwizzle(shader,symbolList,src0Operand,instSlot + 4,0);
      if (componentSelect == 1) {
        swizzleWord = *(uint *)(instSlot + 4) >> 0x10 & 7;
        swizzleWord = swizzleWord << 0x16 | swizzleWord << 0x13 | swizzleWord << 0xd | *(uint *)(instSlot + 4) & 0xfe071fff;
        *(uint *)(instSlot + 4) = swizzleWord;
      }
      else if (componentSelect == 0) {
        swizzleWord = *(uint *)(instSlot + 4) >> 0xd & 7;
        swizzleWord = swizzleWord << 0x16 | swizzleWord << 0x13 | swizzleWord << 0x10 | *(uint *)(instSlot + 4) & 0xfe00ffff;
        *(uint *)(instSlot + 4) = swizzleWord;
      }
      else if (componentSelect == 2) {
        swizzleWord = *(uint *)(instSlot + 4) >> 0x13 & 7;
        swizzleWord = swizzleWord << 0x16 | swizzleWord << 0x10 | swizzleWord << 0xd | *(uint *)(instSlot + 4) & 0xfe381fff;
        *(uint *)(instSlot + 4) = swizzleWord;
      }
      else {
        if (componentSelect != 3) goto setSwizzleWord;
        swizzleWord = *(uint *)(instSlot + 4) >> 0x16 & 7;
        swizzleWord = swizzleWord << 0x13 | swizzleWord << 0x10 | swizzleWord << 0xd | *(uint *)(instSlot + 4) & 0xffc01fff;
        *(uint *)(instSlot + 4) = swizzleWord;
      }
    }
    else {
      if (extvsOperandDataTypeResult != 0x87c0) goto setResult;
      extvsEncodeSourceSwizzle(shader,symbolList,src0Operand,instSlot + 4,componentSelect);
setSwizzleWord:
      swizzleWord = *(uint *)(instSlot + 4);
    }
    result = 1;
    swizzleWord = swizzleWord & 0xfe001fff | 0x1248000;
    *(uint *)(instSlot + 0xc) = swizzleWord;
    *(uint *)(instSlot + 8) = swizzleWord;
  }
  else {
setResult:
    result = 0xffffffff;
  }
  return result;
}

/* extvsEmitLit @ 0x5d870 (336 bytes) */
int extvsEmitLit(ctx, shader, instRecord)
  int ctx;
  int *shader;
  int instRecord;
{
  int instSlot;
  uint swizzleWord;
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
  swizzleWord = *(uint *)(instSlot + 4);
  *(uint *)(instSlot + 0xc) = swizzleWord;
  *(uint *)(instSlot + 4) = (swizzleWord & 0x4000000) << 2 | (swizzleWord & 0x70000) << 6 | swizzleWord & 0xee3fffff;
  *(uint *)(instSlot + 8) = (swizzleWord & 0x2000000) << 3 | (swizzleWord & 0xe000) << 9 | swizzleWord & 0xee3fffff;
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
  uint swizzleWord;
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
  swizzleWord = *(uint *)(instSlot + 4);
  swizzleWord = (swizzleWord & 0x2000000) << 3 | (swizzleWord & 0xe000) << 9 | swizzleWord & 0xee3fffff;
  *(uint *)(instSlot + 0xc) = swizzleWord;
  *(uint *)(instSlot + 4) = swizzleWord;
  *(uint *)(instSlot + 8) = swizzleWord;
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
  uint swizzleWord;
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
  swizzleWord = *(uint *)(instSlot + 4);
  swizzleWord = (swizzleWord & 0x2000000) << 3 | (swizzleWord & 0xe000) << 9 | swizzleWord & 0xee3fffff;
  *(uint *)(instSlot + 0xc) = swizzleWord;
  *(uint *)(instSlot + 4) = swizzleWord;
  *(uint *)(instSlot + 8) = swizzleWord;
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
  int entriesLeft;
  undefined4 *shiftCursor;
  int entry;
  uint nextPosition;
  
  position = 0;
  while( true ) {
    entry = *(int *)(pointerArray + position * 4);
    if ((entry != 0) && (nextPosition = position + 1, nextPosition < 0x20)) {
      entriesLeft = 0x20 - nextPosition;
      shiftCursor = (undefined4 *)(pointerArray + nextPosition * 4);
      do {
        shiftCursor[-1] = *shiftCursor;
        shiftCursor = shiftCursor + 1;
        entriesLeft = entriesLeft + -1;
      } while (entriesLeft != 0);
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
  bool noVectorsLeft;
  bool moreUnits;
  undefined4 hwInputCode;
  undefined4 newSlotArray;
  int symbolRecordOrBoundCount;
  int slotAddr3;
  int slotNumber;
  int instrByteOffset;
  int matrixRow;
  int slotAddr;
  int scalarRecord;
  int boundCandidate;
  int inputIndex;
  int symbolDataType;
  undefined4 *variantRecord2;
  int boundCountOrDataType;
  int variantIndex;
  int slotByteOffset;
  int scanOffset;
  uint inputMask;
  int slotByteOffset2;
  int vectorVariantCount;
  int programState;
  undefined4 *hwInputCursor;
  undefined4 *variantRecord3;
  uint unitIndex;
  uint nextSlot;
  uint nextInputSlot;
  int clearCountdown;
  int boundCountCopyOrRecord;
  int variantRecord;
  int slotByteOffset3;
  int slotAddr2;
  int scanCountdown;
  int instrRecordsOrRowsLeft;
  int boundVariants [32];
  int scalarVariants [32];
  int vectorVariants [32];
  int matrixVariants [34];
  
  scanOffset = 0;
  clearCountdown = 0x20;
  programState = **(int **)(*(int *)(((unsigned char *)0x0000118c) + ctx) * 4 + *shader);
  *(undefined4 *)(programState + 0x234) = 1;
  do {
    *(undefined4 *)((int)boundVariants + scanOffset) = 0;
    *(undefined4 *)(scanOffset + (int)scalarVariants) = 0;
    *(undefined4 *)(scanOffset + (int)vectorVariants) = 0;
    *(undefined4 *)(scanOffset + (int)matrixVariants) = 0;
    scanOffset = scanOffset + 4;
    clearCountdown = clearCountdown + -1;
  } while (clearCountdown != 0);
  if (shader[5] == 0) {
    scalarVariantCount = 0;
    vectorVariantCount = 0;
    matrixVariantCount = 0;
  }
  else {
    boundCountOrDataType = 0;
    instIndex = 0;
    scalarVariantCount = 0;
    vectorVariantCount = 0;
    matrixVariantCount = 0;
    do {
      instrByteOffset = instIndex * 0x74;
      instrRecordsOrRowsLeft = shader[6];
      boundCountCopyOrRecord = boundCountOrDataType;
      if (((*(int *)(instrByteOffset + instrRecordsOrRowsLeft + 0x20) == 2) &&
          (symbolRecordOrBoundCount = *(int *)(instrByteOffset + instrRecordsOrRowsLeft + 0x24) * 0x54 + shader[8],
          *(int *)(symbolRecordOrBoundCount + 0x28) == 0x87c1)) && (*(char *)(symbolRecordOrBoundCount + 0x3d) == '\0')) {
        if ((*(char *)(symbolRecordOrBoundCount + 0x44) == '\0') || (*(int *)(symbolRecordOrBoundCount + 0x48) == 0x12)) {
          boundCountOrDataType = *(int *)(symbolRecordOrBoundCount + 0x24);
          if (boundCountOrDataType == 0x87bf) {
            vectorVariants[vectorVariantCount] = symbolRecordOrBoundCount;
            vectorVariantCount = vectorVariantCount + 1;
          }
          else if (boundCountOrDataType == 0x87c0) {
            matrixVariants[matrixVariantCount] = symbolRecordOrBoundCount;
            matrixVariantCount = matrixVariantCount + 1;
          }
          else if (boundCountOrDataType == 0x87be) {
            scalarVariants[scalarVariantCount] = symbolRecordOrBoundCount;
            scalarVariantCount = scalarVariantCount + 1;
          }
        }
        else {
          boundCountCopyOrRecord = boundCountOrDataType + 1;
          boundVariants[boundCountOrDataType] = symbolRecordOrBoundCount;
          switch(*(undefined4 *)(symbolRecordOrBoundCount + 0x48)) {
          case 0:
            *(undefined1 *)(programState + 0x2c) = 1;
            break;
          case 1:
            *(undefined1 *)(programState + 0x2d) = 1;
            shader[0xc] = shader[0xc] | 8;
            break;
          case 2:
            boundCountOrDataType = *(int *)(symbolRecordOrBoundCount + 0x4c);
            *(undefined1 *)(boundCountOrDataType + programState + 0x2e) = 1;
            *(undefined1 *)((int)shader + boundCountOrDataType + 0x34) = 1;
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
        *(undefined1 *)(symbolRecordOrBoundCount + 0x3d) = 1;
        instrRecordsOrRowsLeft = shader[6];
        shader[0x16] = shader[0x16] + 1;
      }
      symbolRecordOrBoundCount = boundCountCopyOrRecord;
      if (((*(int *)(instrByteOffset + instrRecordsOrRowsLeft + 0x3c) == 2) &&
          (boundCountOrDataType = *(int *)(instrByteOffset + instrRecordsOrRowsLeft + 0x40) * 0x54 + shader[8],
          *(int *)(boundCountOrDataType + 0x28) == 0x87c1)) && (*(char *)(boundCountOrDataType + 0x3d) == '\0')) {
        if ((*(char *)(boundCountOrDataType + 0x44) == '\0') || (*(int *)(boundCountOrDataType + 0x48) == 0x12)) {
          boundCountCopyOrRecord = *(int *)(boundCountOrDataType + 0x24);
          if (boundCountCopyOrRecord == 0x87bf) {
            vectorVariants[vectorVariantCount] = boundCountOrDataType;
            vectorVariantCount = vectorVariantCount + 1;
          }
          else if (boundCountCopyOrRecord == 0x87c0) {
            matrixVariants[matrixVariantCount] = boundCountOrDataType;
            matrixVariantCount = matrixVariantCount + 1;
          }
          else if (boundCountCopyOrRecord == 0x87be) {
            scalarVariants[scalarVariantCount] = boundCountOrDataType;
            scalarVariantCount = scalarVariantCount + 1;
          }
        }
        else {
          symbolRecordOrBoundCount = boundCountCopyOrRecord + 1;
          boundVariants[boundCountCopyOrRecord] = boundCountOrDataType;
          switch(*(undefined4 *)(boundCountOrDataType + 0x48)) {
          case 0:
            *(undefined1 *)(programState + 0x2c) = 1;
            break;
          case 1:
            *(undefined1 *)(programState + 0x2d) = 1;
            shader[0xc] = shader[0xc] | 8;
            break;
          case 2:
            boundCountCopyOrRecord = *(int *)(boundCountOrDataType + 0x4c);
            *(undefined1 *)(boundCountCopyOrRecord + programState + 0x2e) = 1;
            *(undefined1 *)((int)shader + boundCountCopyOrRecord + 0x34) = 1;
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
        *(undefined1 *)(boundCountOrDataType + 0x3d) = 1;
        instrRecordsOrRowsLeft = shader[6];
        shader[0x16] = shader[0x16] + 1;
      }
      boundCountOrDataType = symbolRecordOrBoundCount;
      if (((*(int *)(instrByteOffset + instrRecordsOrRowsLeft + 0x58) == 2) &&
          (boundCountCopyOrRecord = *(int *)(instrByteOffset + instrRecordsOrRowsLeft + 0x5c) * 0x54 + shader[8],
          *(int *)(boundCountCopyOrRecord + 0x28) == 0x87c1)) && (*(char *)(boundCountCopyOrRecord + 0x3d) == '\0')) {
        if ((*(char *)(boundCountCopyOrRecord + 0x44) == '\0') || (*(int *)(boundCountCopyOrRecord + 0x48) == 0x12)) {
          symbolDataType = *(int *)(boundCountCopyOrRecord + 0x24);
          if (symbolDataType == 0x87bf) {
            vectorVariants[vectorVariantCount] = boundCountCopyOrRecord;
            vectorVariantCount = vectorVariantCount + 1;
          }
          else if (symbolDataType == 0x87c0) {
            matrixVariants[matrixVariantCount] = boundCountCopyOrRecord;
            matrixVariantCount = matrixVariantCount + 1;
          }
          else if (symbolDataType == 0x87be) {
            scalarVariants[scalarVariantCount] = boundCountCopyOrRecord;
            scalarVariantCount = scalarVariantCount + 1;
          }
        }
        else {
          boundCountOrDataType = symbolRecordOrBoundCount + 1;
          boundVariants[symbolRecordOrBoundCount] = boundCountCopyOrRecord;
          switch(*(undefined4 *)(boundCountCopyOrRecord + 0x48)) {
          case 0:
            *(undefined1 *)(programState + 0x2c) = 1;
            break;
          case 1:
            *(undefined1 *)(programState + 0x2d) = 1;
            shader[0xc] = shader[0xc] | 8;
            break;
          case 2:
            inputIndex = *(int *)(boundCountCopyOrRecord + 0x4c);
            *(undefined1 *)(inputIndex + programState + 0x2e) = 1;
            *(undefined1 *)((int)shader + inputIndex + 0x34) = 1;
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
        *(undefined1 *)(boundCountCopyOrRecord + 0x3d) = 1;
        shader[0x16] = shader[0x16] + 1;
      }
      instIndex = instIndex + 1;
    } while (instIndex < (uint)shader[5]);
  }
  if (*(char *)(programState + 0x2c) != '\0') {
    scanOffset = 0;
    scanCountdown = 0x20;
    do {
      boundCandidate = *(int *)((int)boundVariants + scanOffset);
      if (((boundCandidate == 0) || (*(int *)(boundCandidate + 0x48) != 0)) || (*(int *)(boundCandidate + 0x4c) != 0)) {
        boundCandidate = 0;
      }
      scanCountdown = scanCountdown + -1;
    } while ((scanCountdown != 0) && (scanOffset = scanOffset + 4, boundCandidate == 0));
    *(undefined4 *)(boundCandidate + 4) = 0;
    *(undefined4 *)(programState + 0x198) = 0;
    *(undefined1 *)(*(int *)(programState + 0x24) + 0x10) = 1;
  }
  noVectorsLeft = vectorVariantCount == 0;
  nextInputSlot = 2;
  unitIndex = 0;
  DAT_001dba98 = 0xe;
  slotByteOffset = 0x50;
  hwInputCursor = &DAT_001dba44;
  do {
    if (!noVectorsLeft) {
      vectorVariantCount = vectorVariantCount + -1;
      variantRecord2 = (undefined4 *)((int (*)())popFirstNonNull32)(vectorVariants);
      hwInputCode = *hwInputCursor;
      noVectorsLeft = vectorVariantCount == 0;
      variantRecord2[1] = nextInputSlot;
      hwInputCursor = hwInputCursor + 1;
      nextInputSlot = nextInputSlot + 1;
      *variantRecord2 = hwInputCode;
      slotAddr2 = slotByteOffset + *(int *)(programState + 0x24);
      slotByteOffset = slotByteOffset + 0x28;
      *(undefined1 *)(slotAddr2 + 0x10) = 1;
      *(uint *)(programState + 0x234) = 4 << (unitIndex & 0x3f) | *(uint *)(programState + 0x234);
    }
    moreUnits = unitIndex != 7;
    unitIndex = unitIndex + 1;
  } while (moreUnits);
  slotByteOffset = nextInputSlot * 0x28;
  unitIndex = 0;
  hwInputCursor = (undefined4 *)(nextInputSlot * 4 + 0x1dba3c);
  do {
    if (!noVectorsLeft) {
      vectorVariantCount = vectorVariantCount + -1;
      variantRecord2 = (undefined4 *)((int (*)())popFirstNonNull32)(vectorVariants);
      hwInputCode = *hwInputCursor;
      noVectorsLeft = vectorVariantCount == 0;
      variantRecord2[1] = nextInputSlot;
      hwInputCursor = hwInputCursor + 1;
      nextInputSlot = nextInputSlot + 1;
      *variantRecord2 = hwInputCode;
      slotAddr2 = slotByteOffset + *(int *)(programState + 0x24);
      slotByteOffset = slotByteOffset + 0x28;
      *(undefined1 *)(slotAddr2 + 0x10) = 1;
      *(uint *)(programState + 0x234) = 0x400 << (unitIndex & 0x3f) | *(uint *)(programState + 0x234);
    }
    moreUnits = unitIndex != 7;
    unitIndex = unitIndex + 1;
  } while (moreUnits);
  nextSlot = nextInputSlot;
  if (*(char *)(nextInputSlot * 0x28 + *(int *)(programState + 0x24) + 0x10) != '\0') {
    inputMask = *(uint *)(programState + 0x234);
    nextSlot = nextInputSlot + 1;
    *(uint *)(programState + 0x234) = inputMask | 0x40000;
    if (*(char *)(nextSlot * 0x28 + *(int *)(programState + 0x24) + 0x10) != '\0') {
      nextSlot = nextInputSlot + 2;
      *(uint *)(programState + 0x234) = inputMask | 0xc0000;
    }
  }
  if (!noVectorsLeft) {
    vectorVariantCount = vectorVariantCount + -1;
    variantRecord3 = (undefined4 *)((int (*)())popFirstNonNull32)(vectorVariants);
    slotByteOffset = nextSlot * 0x28;
    noVectorsLeft = vectorVariantCount == 0;
    hwInputCode = *(undefined4 *)(nextSlot * 4 + 0x1dba3c);
    variantRecord3[1] = nextSlot;
    nextSlot = nextSlot + 1;
    *variantRecord3 = hwInputCode;
    *(undefined1 *)(slotByteOffset + *(int *)(programState + 0x24) + 0x10) = 1;
    *(uint *)(programState + 0x234) = *(uint *)(programState + 0x234) | 0x100000;
  }
  if (((scalarVariantCount != 0) || (!noVectorsLeft)) || (matrixVariantCount != 0)) {
    *(undefined1 *)(shader + 4) = 0;
    if (scalarVariantCount != 0) {
      slotByteOffset3 = nextSlot * 0x28;
      variantIndex = 0;
      do {
        scalarRecord = ((int (*)())popFirstNonNull32)(scalarVariants);
        if (*(uint *)(programState + 0x28) <= nextSlot) {
          newSlotArray = (**(code **)(ctx + 0x10))(*(uint *)(programState + 0x28) + 0x10,0x28);
          (**(code **)(((unsigned char *)0x00001344) + ctx))
                    (newSlotArray,*(undefined4 *)(programState + 0x24),*(int *)(programState + 0x28) * 0x28);
          (**(code **)(ctx + 0x18))(*(undefined4 *)(programState + 0x24));
          *(undefined4 *)(programState + 0x24) = newSlotArray;
          *(int *)(programState + 0x28) = *(int *)(programState + 0x28) + 0x10;
        }
        *(uint *)(scalarRecord + 4) = nextSlot;
        *(undefined4 *)(scalarRecord + 8) = 0;
        variantIndex = variantIndex + 1;
        nextSlot = nextSlot + 1;
        slotAddr = slotByteOffset3 + *(int *)(programState + 0x24);
        slotByteOffset3 = slotByteOffset3 + 0x28;
        *(undefined1 *)(slotAddr + 0x10) = 1;
      } while (scalarVariantCount != variantIndex);
    }
    if (!noVectorsLeft) {
      slotByteOffset2 = nextSlot * 0x28;
      variantIndex = 0;
      do {
        variantRecord = ((int (*)())popFirstNonNull32)(vectorVariants);
        if (*(uint *)(programState + 0x28) <= nextSlot) {
          newSlotArray = (**(code **)(ctx + 0x10))(*(uint *)(programState + 0x28) + 0x10,0x28);
          (**(code **)(((unsigned char *)0x00001344) + ctx))
                    (newSlotArray,*(undefined4 *)(programState + 0x24),*(int *)(programState + 0x28) * 0x28);
          (**(code **)(ctx + 0x18))(*(undefined4 *)(programState + 0x24));
          *(undefined4 *)(programState + 0x24) = newSlotArray;
          *(int *)(programState + 0x28) = *(int *)(programState + 0x28) + 0x10;
        }
        *(uint *)(variantRecord + 4) = nextSlot;
        variantIndex = variantIndex + 1;
        nextSlot = nextSlot + 1;
        slotAddr2 = *(int *)(programState + 0x24) + slotByteOffset2;
        slotByteOffset2 = slotByteOffset2 + 0x28;
        *(undefined1 *)(slotAddr2 + 0x10) = 1;
      } while (vectorVariantCount != variantIndex);
    }
    if (matrixVariantCount != 0) {
      slotByteOffset2 = nextSlot * 0x28;
      variantIndex = 0;
      do {
        vectorVariantCount = ((int (*)())popFirstNonNull32)(matrixVariants);
        if (*(uint *)(programState + 0x28) <= nextSlot + 3) {
          newSlotArray = (**(code **)(ctx + 0x10))(*(uint *)(programState + 0x28) + 0x10,0x28);
          (**(code **)(((unsigned char *)0x00001344) + ctx))
                    (newSlotArray,*(undefined4 *)(programState + 0x24),*(int *)(programState + 0x28) * 0x28);
          (**(code **)(ctx + 0x18))(*(undefined4 *)(programState + 0x24));
          *(undefined4 *)(programState + 0x24) = newSlotArray;
          *(int *)(programState + 0x28) = *(int *)(programState + 0x28) + 0x10;
        }
        matrixRow = 0;
        instrRecordsOrRowsLeft = 4;
        slotByteOffset3 = slotByteOffset2;
        do {
          slotNumber = nextSlot + matrixRow;
          matrixRow = matrixRow + 1;
          *(int *)(vectorVariantCount + 0x10) = slotNumber;
          vectorVariantCount = vectorVariantCount + 4;
          slotAddr3 = slotByteOffset3 + *(int *)(programState + 0x24);
          slotByteOffset3 = slotByteOffset3 + 0x28;
          *(undefined1 *)(slotAddr3 + 0x10) = 1;
          instrRecordsOrRowsLeft = instrRecordsOrRowsLeft + -1;
        } while (instrRecordsOrRowsLeft != 0);
        variantIndex = variantIndex + 1;
        nextSlot = nextSlot + 4;
        slotByteOffset2 = slotByteOffset2 + 0xa0;
      } while (variantIndex != matrixVariantCount);
    }
  }
  *(uint *)(programState + 0x2a4) = nextSlot;
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
  uint rewriteInstHeader;
  undefined4 rewriteInstWord1;
  undefined4 rewriteInstWord2;
  undefined4 rewriteInstWords [3];
  
  hwProgram = **(int **)(*(int *)(((unsigned char *)0x0000118c) + ctx) * 4 + *shader);
  if (*(char *)(shader + 4) != '\0') {
    newInstArray = (**(code **)(ctx + 0xc))(*(int *)(hwProgram + 0x18) << 4);
    buildJob = (undefined4 *)
             recordAllocCreate(*(undefined4 *)(ctx + 0xc),*(undefined4 *)(ctx + 0x18));
    buildJob[8] = 0;
    buildJob[9] = 0;
    buildJob[3] = 0x20;
    *buildJob = 0x460;
    buildJob[1] = *(undefined4 *)(hwProgram + 0x1c);
    oldInstCount = *(undefined4 *)(hwProgram + 0x18);
    buildJob[7] = &rewriteInstHeader;
    buildJob[10] = &rewriteInstWord1;
    buildJob[6] = newInstArray;
    buildJob[0xb] = &rewriteInstWord2;
    buildJob[2] = oldInstCount;
    buildJob[0xc] = rewriteInstWords;
    buildStatus = recordProgramBuildDependencies(buildJob);
    recordAllocFree(buildJob);
    (**(code **)(ctx + 0x18))(*(undefined4 *)(hwProgram + 0x1c));
    *(int *)(hwProgram + 0x1c) = newInstArray;
    if (buildStatus == 0) {
      *(uint *)(hwProgram + 0x18) = rewriteInstHeader;
      shader[0x15] = rewriteInstHeader;
      *(undefined4 *)(hwProgram + 8) = rewriteInstWord1;
      *(undefined4 *)(hwProgram + 0xc) = rewriteInstWord2;
      *(undefined4 *)(hwProgram + 0x2ac) = rewriteInstWords[0];
    }
    else {
      *(undefined4 *)(hwProgram + 0xc) = 0;
      if (rewriteInstHeader != 0) {
        scanIndex = rewriteInstHeader;
        newInstArray = rewriteInstHeader * 0x10 + newInstArray;
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
    if (rewriteInstHeader != 0) {
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
      } while (instIndex < rewriteInstHeader);
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
  uint symbolCount2;
  uint hwInstrWord;
  uint maxTempsUsed;
  undefined4 constWord1;
  undefined4 constWord2;
  undefined4 constWord3;
  undefined4 newIndexList;
  undefined4 newSlotArray3;
  undefined4 foundFlag;
  uint symbolCount;
  uint hwOpClass;
  uint instrIndex;
  uint slotHighWater;
  uint stateCursor;
  uint outputFlags;
  uint copyUnit;
  uint glContextWord44;
  uint dstRegisterId;
  int dstOperandKind;
  int slotFieldPtr2;
  int symbolDataType3;
  int symbolDataType2;
  int slotWriteOffset2;
  int slotFieldPtr;
  int slotWriteOffset;
  int symbolDataType;
  int dependentOffset2;
  int instrRecords2;
  int instrRecord2;
  int opIndex;
  int dependentOffset;
  int symbolByteOffset2;
  int hwInstrCount;
  int symbolByteOffset;
  int nextRegisterNumber;
  int instrByteOffset;
  int instrRecord;
  int instrRecords;
  int slotNumber4;
  int slotNumber3;
  byte fogCopyUnit;
  uint slotScanIndex2;
  uint slotScanIndex;
  int rowIndex4;
  int rowsLeft4;
  int slotScanOffset3;
  int slotCount3;
  int slotEntry6;
  int symbolRecords2;
  int slotCount2;
  int rowIndex3;
  int slotScanOffset2;
  int rowsLeft3;
  int slotEntry5;
  int symbolRecords;
  int rowIndex2;
  int slotCount;
  int slotScanOffset;
  int unitsLeft;
  int slotEntry4;
  int rowsLeft2;
  int rowIndex;
  int rowsLeft;
  int slotEntry3;
  int slotEntry2;
  int slotEntry;
  undefined4 newSlotArray2;
  undefined4 newSlotArray;
  int newSlotOffset;
  int oldSlotCount;
  byte positionCopyUnit;
  bool searching;
  int slotNumber;
  int slotNumber2;
  uint slotHighWater2;
  undefined1 success;
  int *unitFlagCursor;
  int writeEnableSnapshot;
  uint symbolIndex;
  int symbolOffset;
  uint in_r7;
  uint in_r8;
  uint slotByteOffset;
  int outputIndexScaled;
  int recordOffsetOrCount;
  int hwInstrCountCopy;
  undefined4 *constVector;
  undefined4 maskWord1;
  undefined4 maskWord2;
  int recordOrOffsetScratch;
  uint instrCount;
  int symbolRecordOrCallResult;
  int symbolRecordsBase;
  undefined4 maskWord3;
  uint *hwProgramSlot;
  uint slotIndex;
  uint programState;
  int rowsRemaining;
  undefined4 tempInstr [2];
  int tempInstrDstId;
  int tempInstrDstMaskX;
  int tempInstrDstMaskY;
  int tempInstrDstMaskZ;
  int tempInstrDstMaskW;
  undefined4 tempInstrSrc0SwizzleX;
  undefined4 tempInstrSrc0SwizzleY;
  undefined4 tempInstrSrc0SwizzleZ;
  undefined4 tempInstrSrc0SwizzleW;
  
  hwProgramSlot = *(uint **)(*(int *)(((unsigned char *)0x0000118c) + ctx) * 4 + *shader);
  programState = *hwProgramSlot;
  if ((shader[6] == 0) || (shader[5] == 0)) {
    success = 1;
loopStoreShader:
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
        instrRecords = shader[6];
        recordOrOffsetScratch = symbolOffset + instrRecords;
        if (*(int *)(recordOrOffsetScratch + 4) == 1) {
          dstRegisterId = *(uint *)(recordOrOffsetScratch + 8);
          if (dstRegisterId < 0x879d) {
            if (dstRegisterId < 0x879b) {
              if (dstRegisterId < 0x6111) {
                if (dstRegisterId < 0x610f) {
                  if (dstRegisterId == 0x610e) {
                    *(undefined1 *)((int)shader + 0x79) = 1;
                  }
                }
                else {
                  *(undefined1 *)((int)shader + (dstRegisterId - 0x60a0)) = 1;
                }
              }
              else if (dstRegisterId == 0x879a) {
                *(undefined1 *)(shader + 0x1b) = 1;
              }
            }
            else {
              *(undefined1 *)((int)shader + (dstRegisterId - 0x872e)) = 1;
            }
          }
          else if (dstRegisterId < 0x87a5) {
            if (*(int *)(recordOrOffsetScratch + 0xc) != 0) {
              *(byte *)((int)shader + (dstRegisterId - 0x872c)) =
                   *(byte *)((int)shader + (dstRegisterId - 0x872c)) | 1;
            }
            if (*(int *)(recordOrOffsetScratch + 0x10) != 0) {
              *(byte *)((int)shader + *(int *)(recordOrOffsetScratch + 8) + -0x872c) =
                   *(byte *)((int)shader + *(int *)(recordOrOffsetScratch + 8) + -0x872c) | 2;
            }
            if (*(int *)(recordOrOffsetScratch + 0x14) != 0) {
              *(byte *)((int)shader + *(int *)(recordOrOffsetScratch + 8) + -0x872c) =
                   *(byte *)((int)shader + *(int *)(recordOrOffsetScratch + 8) + -0x872c) | 4;
            }
            if (*(int *)(recordOrOffsetScratch + 0x18) != 0) {
              *(byte *)((int)shader + *(int *)(recordOrOffsetScratch + 8) + -0x872c) =
                   *(byte *)((int)shader + *(int *)(recordOrOffsetScratch + 8) + -0x872c) | 8;
            }
          }
          else if (dstRegisterId == 0x87bd) {
            *(undefined1 *)((int)shader + 0x7a) = 1;
          }
        }
        instrRecords = symbolOffset + instrRecords;
        recordOrOffsetScratch = symbolIndex * 0x10;
        symbolIndex = symbolIndex + 1;
        symbolOffset = symbolOffset + 0x74;
        in_r7 = *(uint *)(instrRecords + 0x18);
        recordOffsetOrCount = recordOrOffsetScratch + writeEnableSnapshot;
        maskWord1 = *(undefined4 *)(instrRecords + 0x10);
        in_r8 = *(uint *)(instrRecords + 0x14);
        *(undefined4 *)(writeEnableSnapshot + recordOrOffsetScratch) = *(undefined4 *)(instrRecords + 0xc);
        *(uint *)(recordOffsetOrCount + 0xc) = in_r7;
        *(undefined4 *)(recordOffsetOrCount + 4) = maskWord1;
        *(uint *)(recordOffsetOrCount + 8) = in_r8;
      } while (symbolIndex < (uint)shader[5]);
    }
    if ((*(char *)((int)shader + 0x7a) == '\0') ||
       (success = 1, (*(uint *)(ctx + 0x44) & 0x1000) != 0)) {
      success = 0;
    }
    *(undefined1 *)(programState + 0x42) = success;
    *(undefined1 *)(programState + 0x43) = *(undefined1 *)((int)shader + 0x79);
    if ((*(char *)((int)shader + 0x6f) != '\0') || (success = 0, *(char *)(shader + 0x1c) != '\0'))
    {
      success = 1;
    }
    *(undefined1 *)(programState + 0x44) = success;
    glContextWord44 = *(uint *)(ctx + 0x44);
    if ((glContextWord44 & 0x80) == 0) {
      *(undefined1 *)((int)shader + 0x79) = 0;
      glContextWord44 = *(uint *)(ctx + 0x44);
    }
    if ((glContextWord44 & 0x40) == 0) {
      *(undefined1 *)(shader + 0x1c) = 0;
      *(undefined1 *)((int)shader + 0x6f) = 0;
    }
    if ((*(char *)((int)shader + 0x7a) != '\0') && ((*(uint *)(ctx + 0x44) & 0x800) != 0)) {
      in_r7 = (uint)(byte)((unsigned char *)0x000011d1)[ctx];
      in_r8 = in_r7 + (int)shader;
      if (*(char *)(in_r8 + 0x71) != '\0') {
        instrCount = shader[5];
        slotScanIndex = 0;
        if (instrCount != 0) {
          do {
            instrRecord = slotScanIndex * 0x74 + shader[6];
            if ((*(int *)(instrRecord + 4) == 1) && (*(int *)(instrRecord + 8) == in_r7 + 0x879d)) {
              *(undefined4 *)(instrRecord + 0x18) = 0;
              *(undefined4 *)(instrRecord + 0xc) = 0;
              *(undefined4 *)(instrRecord + 0x10) = 0;
              *(undefined4 *)(instrRecord + 0x14) = 0;
              instrCount = shader[5];
            }
            slotScanIndex = slotScanIndex + 1;
          } while (slotScanIndex < instrCount);
        }
      }
      *(undefined1 *)(in_r8 + 0x71) = 0xf;
    }
    if ((*(char *)(shader + 0x1b) != '\0') && ((*(uint *)(ctx + 0x44) & 0x400) != 0)) {
      positionCopyUnit = ((unsigned char *)0x000011d2)[ctx];
      copyUnit = (uint)positionCopyUnit;
      if ((*(char *)((int)shader + positionCopyUnit + 0x71) != '\0') && (instrCount = shader[5], instrCount != 0)) {
        in_r8 = 0;
        in_r7 = 0;
        instrByteOffset = 0;
        symbolOffset = positionCopyUnit + 0x879d;
        do {
          instrRecord2 = instrByteOffset + shader[6];
          if ((*(int *)(instrRecord2 + 4) == 1) && (*(int *)(instrRecord2 + 8) == symbolOffset)) {
            *(undefined4 *)(instrRecord2 + 0x18) = 0;
            *(undefined4 *)(instrRecord2 + 0xc) = 0;
            *(undefined4 *)(instrRecord2 + 0x10) = 0;
            *(undefined4 *)(instrRecord2 + 0x14) = 0;
            instrCount = shader[5];
          }
          in_r8 = in_r8 + 1;
          instrByteOffset = instrByteOffset + 0x74;
        } while (in_r8 < instrCount);
        copyUnit = (uint)(byte)((unsigned char *)0x000011d2)[ctx];
      }
      *(undefined1 *)((int)shader + copyUnit + 0x71) = 0xf;
    }
    nextRegisterNumber = 1;
    *(undefined4 *)(programState + 0x1e8) = 0;
    if (*(char *)((int)shader + 0x79) != '\0') {
      nextRegisterNumber = 2;
      *(undefined4 *)(programState + 0x1fc) = 1;
    }
    outputFlags = shader[0x1b];
    if ((((outputFlags & 0xffffff) != 0) || (*(char *)(shader + 0x1c) != '\0')) ||
       (*(char *)((int)shader + 0x7a) != '\0')) {
      *(int *)(programState + 0x1ec) = nextRegisterNumber;
      nextRegisterNumber = nextRegisterNumber + 1;
      outputFlags = shader[0x1b];
    }
    if ((((outputFlags & 0xffff) != 0) || (*(char *)(shader + 0x1c) != '\0')) ||
       (*(char *)((int)shader + 0x7a) != '\0')) {
      *(int *)(programState + 0x1f0) = nextRegisterNumber;
      nextRegisterNumber = nextRegisterNumber + 1;
    }
    if ((*(char *)((int)shader + 0x6f) != '\0') || (*(char *)(shader + 0x1c) != '\0')) {
      recordOrOffsetScratch = nextRegisterNumber + 1;
      *(int *)(programState + 500) = nextRegisterNumber;
      nextRegisterNumber = nextRegisterNumber + 2;
      *(int *)(programState + 0x1f8) = recordOrOffsetScratch;
    }
    unitsLeft = 8;
    unitFlagCursor = shader;
    stateCursor = programState;
    do {
      if (*(char *)((int)unitFlagCursor + 0x71) != '\0') {
        *(int *)(stateCursor + 0x200) = nextRegisterNumber;
        nextRegisterNumber = nextRegisterNumber + 1;
      }
      unitFlagCursor = (int *)((int)unitFlagCursor + 1);
      stateCursor = stateCursor + 4;
      unitsLeft = unitsLeft + -1;
    } while (unitsLeft != 0);
    *(undefined4 *)(programState + 0x22c) = 0;
    *(undefined4 *)(programState + 0x224) = 0;
    if (shader[5] != 0) {
      slotScanIndex = 0;
      instrByteOffset = 0;
      do {
        instrRecords2 = shader[6];
        if (*(int *)(instrByteOffset + instrRecords2 + 0x20) == 2) {
          symbolRecords = shader[8];
          symbolByteOffset2 = *(int *)(instrByteOffset + instrRecords2 + 0x24) * 0x54;
          symbolOffset = symbolByteOffset2 + symbolRecords;
          if ((*(int *)(symbolOffset + 0x28) == 0x87c2) && (*(char *)(symbolOffset + 0x3d) == '\0')) {
            if (*(int *)(symbolOffset + 0x30) == 0) {
              if (*(uint *)(symbolOffset + 0x34) < 2) {
                symbolIndex = programState;
                extvsAllocConstantRegisters(ctx,shader,programState,symbolOffset);
                instrRecords2 = shader[6];
                goto checkInstrByteOffset;
              }
            }
            else {
              symbolByteOffset2 = extvsSymbolListGetIndex(shader + 7,*(int *)(symbolOffset + 0x30));
              symbolRecords = shader[8];
              symbolByteOffset2 = symbolByteOffset2 * 0x54;
            }
            if (*(int *)(symbolRecords + symbolByteOffset2 + 0x34) != 0) {
              slotScanIndex2 = 0;
              dependentOffset2 = symbolByteOffset2;
              do {
                symbolOffset = dependentOffset2 + symbolRecords;
                slotScanIndex2 = slotScanIndex2 + 1;
                dependentOffset2 = dependentOffset2 + 0x54;
                symbolIndex = programState;
                extvsAllocConstantRegisters(ctx,shader,programState,symbolOffset);
                symbolRecords = shader[8];
              } while (slotScanIndex2 < *(uint *)(symbolRecords + symbolByteOffset2 + 0x34));
            }
            instrRecords2 = shader[6];
          }
        }
checkInstrByteOffset:
        if (*(int *)(instrByteOffset + instrRecords2 + 0x3c) == 2) {
          symbolRecords2 = shader[8];
          symbolByteOffset2 = *(int *)(instrByteOffset + instrRecords2 + 0x40) * 0x54;
          slotFieldPtr = symbolByteOffset2 + symbolRecords2;
          if ((*(int *)(slotFieldPtr + 0x28) == 0x87c2) && (*(char *)(slotFieldPtr + 0x3d) == '\0')) {
            if (*(int *)(slotFieldPtr + 0x30) == 0) {
              if (1 < *(uint *)(slotFieldPtr + 0x34)) goto checkSymbolByteOffset2;
              shader[0x17] = shader[0x17] + 1;
              if (*(char *)(slotFieldPtr + 0x44) == '\0') {
                *(int *)(programState + 0x224) = *(int *)(programState + 0x224) + 1;
              }
              else {
                *(int *)(programState + 0x22c) = *(int *)(programState + 0x22c) + 1;
              }
              symbolDataType = *(int *)(slotFieldPtr + 0x24);
              *(undefined1 *)(slotFieldPtr + 0x3d) = 1;
              if (symbolDataType == 0x87bf) {
                in_r8 = 0;
                slotScanIndex2 = 0;
                slotScanOffset = 0;
                searching = true;
                *(int *)(programState + 0x5c) = *(int *)(programState + 0x5c) + 1;
                while (slotScanIndex2 < *(uint *)(programState + 0x58)) {
                  if (!searching) goto storeSlotFieldPtr;
                  if (*(char *)(slotScanOffset + *(int *)(programState + 0x54) + 0x10) == '\0') {
                    in_r8 = 1;
                    searching = false;
                  }
                  else {
                    slotScanIndex2 = slotScanIndex2 + 1;
                    slotScanOffset = slotScanOffset + 0x28;
                  }
                }
                if (searching) {
                  *(char *)(shader + 4) = (char)in_r8;
                  slotCount = *(int *)(programState + 0x58);
                  newSlotArray = (**(code **)(ctx + 0x10))(slotCount + 0x10,0x28);
                  symbolIndex = *(int *)(programState + 0x58) * 0x28;
                  (**(code **)(((unsigned char *)0x00001344) + ctx))(newSlotArray,*(undefined4 *)(programState + 0x54),symbolIndex);
                  (**(code **)(ctx + 0x18))(*(undefined4 *)(programState + 0x54));
                  *(undefined4 *)(programState + 0x54) = newSlotArray;
                  *(int *)(programState + 0x58) = *(int *)(programState + 0x58) + 0x10;
loopStoreSlotFieldPtr:
                  *(int *)(slotFieldPtr + 4) = slotCount;
                  *(undefined1 *)(slotCount * 0x28 + *(int *)(programState + 0x54) + 0x10) = 1;
                  instrRecords2 = shader[6];
                  goto checkInstrByteOffset2;
                }
storeSlotFieldPtr:
                *(uint *)(slotFieldPtr + 4) = slotScanIndex2;
loopStoreSlotScanIndex2:
                *(undefined1 *)(slotScanIndex2 * 0x28 + *(int *)(programState + 0x54) + 0x10) = 1;
                instrRecords2 = shader[6];
                goto checkInstrByteOffset2;
              }
              if (symbolDataType == 0x87c0) {
                slotScanIndex2 = 0;
                slotScanOffset = 0;
                searching = true;
                *(int *)(programState + 0x5c) = *(int *)(programState + 0x5c) + 4;
                while (slotScanIndex2 < *(int *)(programState + 0x58) - 3U) {
                  if (!searching) goto setSlotWriteOffset;
                  if (*(char *)(slotScanOffset + *(int *)(programState + 0x54) + 0x10) == '\0') {
                    searching = false;
                  }
                  else {
                    slotScanIndex2 = slotScanIndex2 + 1;
                    slotScanOffset = slotScanOffset + 0x28;
                  }
                }
                if (!searching) {
setSlotWriteOffset:
                  slotWriteOffset = slotScanIndex2 * 0x28;
                  slotEntry3 = slotWriteOffset + *(int *)(programState + 0x54);
                  if (((*(char *)(slotEntry3 + 0x38) == '\0') && (*(char *)(slotEntry3 + 0x60) == '\0')) &&
                     (*(char *)(slotEntry3 + 0x88) == '\0')) {
                    in_r8 = 0;
                    rowsLeft = 4;
                    in_r7 = 1;
                    do {
                      slotNumber4 = slotScanIndex2 + in_r8;
                      in_r8 = in_r8 + 1;
                      *(int *)(slotFieldPtr + 0x10) = slotNumber4;
                      slotFieldPtr = slotFieldPtr + 4;
                      slotEntry6 = slotWriteOffset + *(int *)(programState + 0x54);
                      slotWriteOffset = slotWriteOffset + 0x28;
                      *(undefined1 *)(slotEntry6 + 0x10) = 1;
                      rowsLeft = rowsLeft + -1;
                    } while (rowsLeft != 0);
                    goto setInstrRecords2;
                  }
                }
                *(undefined1 *)(shader + 4) = 0;
                slotCount3 = *(int *)(programState + 0x58);
                newSlotArray = (**(code **)(ctx + 0x10))(slotCount3 + 0x10,0x28);
                symbolIndex = *(int *)(programState + 0x58) * 0x28;
                (**(code **)(((unsigned char *)0x00001344) + ctx))(newSlotArray,*(undefined4 *)(programState + 0x54),symbolIndex);
                (**(code **)(ctx + 0x18))(*(undefined4 *)(programState + 0x54));
                *(undefined4 *)(programState + 0x54) = newSlotArray;
                slotWriteOffset = slotCount3 * 0x28;
                rowsLeft2 = 4;
                rowIndex = 0;
                in_r8 = 1;
                *(int *)(programState + 0x58) = *(int *)(programState + 0x58) + 0x10;
                do {
                  slotNumber = rowIndex + slotCount3;
                  rowIndex = rowIndex + 1;
                  *(int *)(slotFieldPtr + 0x10) = slotNumber;
                  slotFieldPtr = slotFieldPtr + 4;
                  slotEntry = *(int *)(programState + 0x54) + slotWriteOffset;
                  slotWriteOffset = slotWriteOffset + 0x28;
                  *(undefined1 *)(slotEntry + 0x10) = 1;
                  rowsLeft2 = rowsLeft2 + -1;
                } while (rowsLeft2 != 0);
              }
              else if (symbolDataType == 0x87be) {
                foundFlag = 0;
                slotScanIndex2 = 0;
                slotScanOffset = 0;
                searching = true;
                *(int *)(programState + 0x5c) = *(int *)(programState + 0x5c) + 1;
                while (slotScanIndex2 < *(uint *)(programState + 0x58)) {
                  if (!searching) goto storeSlotFieldPtr2;
                  if (*(char *)(slotScanOffset + *(int *)(programState + 0x54) + 0x10) == '\0') {
                    foundFlag = 1;
                    searching = false;
                  }
                  else {
                    slotScanIndex2 = slotScanIndex2 + 1;
                    slotScanOffset = slotScanOffset + 0x28;
                  }
                }
                if (searching) {
                  *(char *)(shader + 4) = (char)foundFlag;
                  slotCount = *(int *)(programState + 0x58);
                  newSlotArray2 = (**(code **)(ctx + 0x10))(slotCount + 0x10,0x28);
                  symbolIndex = *(int *)(programState + 0x58) * 0x28;
                  (**(code **)(((unsigned char *)0x00001344) + ctx))(newSlotArray2,*(undefined4 *)(programState + 0x54),symbolIndex);
                  (**(code **)(ctx + 0x18))(*(undefined4 *)(programState + 0x54));
                  *(undefined4 *)(programState + 0x54) = newSlotArray2;
                  *(int *)(programState + 0x58) = *(int *)(programState + 0x58) + 0x10;
                  *(undefined4 *)(slotFieldPtr + 8) = foundFlag;
                  goto loopStoreSlotFieldPtr;
                }
storeSlotFieldPtr2:
                *(uint *)(slotFieldPtr + 4) = slotScanIndex2;
                *(undefined4 *)(slotFieldPtr + 8) = 0;
                goto loopStoreSlotScanIndex2;
              }
            }
            else {
              symbolByteOffset2 = extvsSymbolListGetIndex(shader + 7,*(int *)(slotFieldPtr + 0x30));
              symbolRecords2 = shader[8];
              symbolByteOffset2 = symbolByteOffset2 * 0x54;
checkSymbolByteOffset2:
              if (*(int *)(symbolByteOffset2 + symbolRecords2 + 0x34) != 0) {
                slotScanIndex2 = 0;
                dependentOffset2 = symbolByteOffset2;
                do {
                  slotFieldPtr = symbolRecords2 + dependentOffset2;
                  if (*(int *)(slotFieldPtr + 0x28) == 0x87c2) {
                    shader[0x17] = shader[0x17] + 1;
                    if (*(char *)(slotFieldPtr + 0x44) == '\0') {
                      *(int *)(programState + 0x224) = *(int *)(programState + 0x224) + 1;
                    }
                    else {
                      *(int *)(programState + 0x22c) = *(int *)(programState + 0x22c) + 1;
                    }
                    symbolDataType3 = *(int *)(slotFieldPtr + 0x24);
                    *(undefined1 *)(slotFieldPtr + 0x3d) = 1;
                    if (symbolDataType3 != 0x87bf) {
                      if (symbolDataType3 == 0x87c0) {
                        slotIndex = 0;
                        slotScanOffset3 = 0;
                        searching = true;
                        *(int *)(programState + 0x5c) = *(int *)(programState + 0x5c) + 4;
                        while (slotIndex < *(int *)(programState + 0x58) - 3U) {
                          if (!searching) goto setSlotByteOffset;
                          if (*(char *)(slotScanOffset3 + *(int *)(programState + 0x54) + 0x10) == '\0') {
                            searching = false;
                          }
                          else {
                            slotIndex = slotIndex + 1;
                            slotScanOffset3 = slotScanOffset3 + 0x28;
                          }
                        }
                        if (!searching) {
setSlotByteOffset:
                          slotByteOffset = slotIndex * 0x28;
                          slotEntry6 = slotByteOffset + *(int *)(programState + 0x54);
                          in_r8 = slotByteOffset;
                          if (((*(char *)(slotEntry6 + 0x38) == '\0') &&
                              (*(char *)(slotEntry6 + 0x60) == '\0')) &&
                             (*(char *)(slotEntry6 + 0x88) == '\0')) {
                            in_r8 = 0;
                            rowsLeft4 = 4;
                            in_r7 = 1;
                            do {
                              slotNumber3 = slotIndex + in_r8;
                              in_r8 = in_r8 + 1;
                              *(int *)(slotFieldPtr + 0x10) = slotNumber3;
                              slotFieldPtr = slotFieldPtr + 4;
                              slotEntry4 = *(int *)(programState + 0x54) + slotByteOffset;
                              slotByteOffset = slotByteOffset + 0x28;
                              *(undefined1 *)(slotEntry4 + 0x10) = 1;
                              rowsLeft4 = rowsLeft4 + -1;
                            } while (rowsLeft4 != 0);
                            goto setSymbolRecords2;
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
                        rowIndex4 = 0;
                        in_r8 = 1;
                        *(int *)(programState + 0x58) = *(int *)(programState + 0x58) + 0x10;
                        do {
                          slotNumber2 = rowIndex4 + oldSlotCount;
                          rowIndex4 = rowIndex4 + 1;
                          *(int *)(slotFieldPtr + 0x10) = slotNumber2;
                          slotFieldPtr = slotFieldPtr + 4;
                          slotEntry2 = *(int *)(programState + 0x54) + newSlotOffset;
                          newSlotOffset = newSlotOffset + 0x28;
                          *(undefined1 *)(slotEntry2 + 0x10) = 1;
                          rowsRemaining = rowsRemaining + -1;
                        } while (rowsRemaining != 0);
                      }
                      else if (symbolDataType3 == 0x87be) {
                        foundFlag = 0;
                        slotIndex = 0;
                        slotScanOffset3 = 0;
                        searching = true;
                        *(int *)(programState + 0x5c) = *(int *)(programState + 0x5c) + 1;
                        while (slotIndex < *(uint *)(programState + 0x58)) {
                          if (!searching) goto loopStoreSlotFieldPtr2;
                          if (*(char *)(slotScanOffset3 + *(int *)(programState + 0x54) + 0x10) == '\0') {
                            foundFlag = 1;
                            searching = false;
                          }
                          else {
                            slotIndex = slotIndex + 1;
                            slotScanOffset3 = slotScanOffset3 + 0x28;
                          }
                        }
loopCheckSearching:
                        if (!searching) {
loopStoreSlotFieldPtr2:
                          *(uint *)(slotFieldPtr + 4) = slotIndex;
                          *(undefined4 *)(slotFieldPtr + 8) = 0;
                          *(undefined1 *)(slotIndex * 0x28 + *(int *)(programState + 0x54) + 0x10) = 1;
                          symbolRecords2 = shader[8];
                          goto setSlotScanIndex2;
                        }
                        *(char *)(shader + 4) = (char)foundFlag;
                        slotCount3 = *(int *)(programState + 0x58);
                        newSlotArray2 = (**(code **)(ctx + 0x10))(slotCount3 + 0x10,0x28);
                        symbolIndex = *(int *)(programState + 0x58) * 0x28;
                        (**(code **)(((unsigned char *)0x00001344) + ctx))
                                  (newSlotArray2,*(undefined4 *)(programState + 0x54),symbolIndex);
                        (**(code **)(ctx + 0x18))(*(undefined4 *)(programState + 0x54));
                        *(undefined4 *)(programState + 0x54) = newSlotArray2;
                        *(int *)(programState + 0x58) = *(int *)(programState + 0x58) + 0x10;
                        *(undefined4 *)(slotFieldPtr + 8) = foundFlag;
                        goto storeSlotFieldPtr3;
                      }
                      goto setSymbolRecords2;
                    }
                    in_r8 = 0;
                    slotIndex = 0;
                    slotScanOffset3 = 0;
                    searching = true;
                    *(int *)(programState + 0x5c) = *(int *)(programState + 0x5c) + 1;
                    while (slotIndex < *(uint *)(programState + 0x58)) {
                      if (!searching) goto loopStoreSlotFieldPtr3;
                      if (*(char *)(slotScanOffset3 + *(int *)(programState + 0x54) + 0x10) == '\0') {
                        in_r8 = 1;
                        searching = false;
                      }
                      else {
                        slotIndex = slotIndex + 1;
                        slotScanOffset3 = slotScanOffset3 + 0x28;
                      }
                    }
loopCheckSearching2:
                    if (searching) {
                      *(char *)(shader + 4) = (char)in_r8;
                      slotCount3 = *(int *)(programState + 0x58);
                      newSlotArray = (**(code **)(ctx + 0x10))(slotCount3 + 0x10,0x28);
                      symbolIndex = *(int *)(programState + 0x58) * 0x28;
                      (**(code **)(((unsigned char *)0x00001344) + ctx))(newSlotArray,*(undefined4 *)(programState + 0x54),symbolIndex);
                      (**(code **)(ctx + 0x18))(*(undefined4 *)(programState + 0x54));
                      *(undefined4 *)(programState + 0x54) = newSlotArray;
                      *(int *)(programState + 0x58) = *(int *)(programState + 0x58) + 0x10;
storeSlotFieldPtr3:
                      *(int *)(slotFieldPtr + 4) = slotCount3;
                      *(undefined1 *)(slotCount3 * 0x28 + *(int *)(programState + 0x54) + 0x10) = 1;
                      symbolRecords2 = shader[8];
                    }
                    else {
loopStoreSlotFieldPtr3:
                      *(uint *)(slotFieldPtr + 4) = slotIndex;
                      *(undefined1 *)(slotIndex * 0x28 + *(int *)(programState + 0x54) + 0x10) = 1;
                      symbolRecords2 = shader[8];
                    }
                  }
                  else if (*(int *)(slotFieldPtr + 0x28) == 0x87c3) {
                    shader[0x18] = shader[0x18] + 1;
                    *(undefined1 *)(slotFieldPtr + 0x3d) = 1;
                    symbolDataType3 = *(int *)(slotFieldPtr + 0x24);
                    if (symbolDataType3 == 0x87bf) {
                      in_r8 = 0;
                      slotIndex = 0;
                      slotScanOffset3 = 0;
                      searching = true;
                      *(int *)(programState + 0x5c) = *(int *)(programState + 0x5c) + 1;
                      while (slotIndex < *(uint *)(programState + 0x58)) {
                        if (!searching) goto loopStoreSlotFieldPtr3;
                        if (*(char *)(slotScanOffset3 + *(int *)(programState + 0x54) + 0x10) == '\0') {
                          in_r8 = 1;
                          searching = false;
                        }
                        else {
                          slotIndex = slotIndex + 1;
                          slotScanOffset3 = slotScanOffset3 + 0x28;
                        }
                      }
                      goto loopCheckSearching2;
                    }
                    if (symbolDataType3 == 0x87c0) {
                      slotIndex = 0;
                      slotScanOffset3 = 0;
                      searching = true;
                      *(int *)(programState + 0x5c) = *(int *)(programState + 0x5c) + 4;
                      while (slotIndex < *(int *)(programState + 0x58) - 3U) {
                        if (!searching) goto setSlotByteOffset2;
                        if (*(char *)(slotScanOffset3 + *(int *)(programState + 0x54) + 0x10) == '\0') {
                          searching = false;
                        }
                        else {
                          slotIndex = slotIndex + 1;
                          slotScanOffset3 = slotScanOffset3 + 0x28;
                        }
                      }
                      if (!searching) {
setSlotByteOffset2:
                        slotByteOffset = slotIndex * 0x28;
                        slotEntry6 = slotByteOffset + *(int *)(programState + 0x54);
                        in_r8 = slotByteOffset;
                        if (((*(char *)(slotEntry6 + 0x38) == '\0') &&
                            (*(char *)(slotEntry6 + 0x60) == '\0')) &&
                           (*(char *)(slotEntry6 + 0x88) == '\0')) {
                          in_r8 = 0;
                          rowsLeft4 = 4;
                          in_r7 = 1;
                          do {
                            slotNumber3 = in_r8 + slotIndex;
                            in_r8 = in_r8 + 1;
                            *(int *)(slotFieldPtr + 0x10) = slotNumber3;
                            slotFieldPtr = slotFieldPtr + 4;
                            slotEntry4 = *(int *)(programState + 0x54) + slotByteOffset;
                            slotByteOffset = slotByteOffset + 0x28;
                            *(undefined1 *)(slotEntry4 + 0x10) = 1;
                            rowsLeft4 = rowsLeft4 + -1;
                          } while (rowsLeft4 != 0);
                          goto setSymbolRecords2;
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
                      rowIndex4 = 0;
                      in_r8 = 1;
                      *(int *)(programState + 0x58) = *(int *)(programState + 0x58) + 0x10;
                      do {
                        slotNumber2 = rowIndex4 + oldSlotCount;
                        rowIndex4 = rowIndex4 + 1;
                        *(int *)(slotFieldPtr + 0x10) = slotNumber2;
                        slotFieldPtr = slotFieldPtr + 4;
                        slotEntry2 = *(int *)(programState + 0x54) + newSlotOffset;
                        newSlotOffset = newSlotOffset + 0x28;
                        *(undefined1 *)(slotEntry2 + 0x10) = 1;
                        rowsRemaining = rowsRemaining + -1;
                      } while (rowsRemaining != 0);
                    }
                    else if (symbolDataType3 == 0x87be) {
                      foundFlag = 0;
                      slotIndex = 0;
                      slotScanOffset3 = 0;
                      searching = true;
                      *(int *)(programState + 0x5c) = *(int *)(programState + 0x5c) + 1;
                      while (slotIndex < *(uint *)(programState + 0x58)) {
                        if (!searching) goto loopStoreSlotFieldPtr2;
                        if (*(char *)(slotScanOffset3 + *(int *)(programState + 0x54) + 0x10) == '\0') {
                          foundFlag = 1;
                          searching = false;
                        }
                        else {
                          slotIndex = slotIndex + 1;
                          slotScanOffset3 = slotScanOffset3 + 0x28;
                        }
                      }
                      goto loopCheckSearching;
                    }
setSymbolRecords2:
                    symbolRecords2 = shader[8];
                  }
setSlotScanIndex2:
                  slotScanIndex2 = slotScanIndex2 + 1;
                  dependentOffset2 = dependentOffset2 + 0x54;
                } while (slotScanIndex2 < *(uint *)(symbolByteOffset2 + symbolRecords2 + 0x34));
              }
            }
setInstrRecords2:
            instrRecords2 = shader[6];
          }
        }
checkInstrByteOffset2:
        if (*(int *)(instrByteOffset + instrRecords2 + 0x58) == 2) {
          symbolRecords = shader[8];
          instrRecords2 = *(int *)(instrByteOffset + instrRecords2 + 0x5c) * 0x54;
          recordOffsetOrCount = instrRecords2 + symbolRecords;
          if ((*(int *)(recordOffsetOrCount + 0x28) == 0x87c2) && (*(char *)(recordOffsetOrCount + 0x3d) == '\0')) {
            if (*(int *)(recordOffsetOrCount + 0x30) == 0) {
              if (*(uint *)(recordOffsetOrCount + 0x34) < 2) {
                shader[0x17] = shader[0x17] + 1;
                if (*(char *)(recordOffsetOrCount + 0x44) == '\0') {
                  *(int *)(programState + 0x224) = *(int *)(programState + 0x224) + 1;
                }
                else {
                  *(int *)(programState + 0x22c) = *(int *)(programState + 0x22c) + 1;
                }
                symbolDataType = *(int *)(recordOffsetOrCount + 0x24);
                *(undefined1 *)(recordOffsetOrCount + 0x3d) = 1;
                if (symbolDataType == 0x87bf) {
                  in_r8 = 0;
                  slotScanIndex2 = 0;
                  slotScanOffset = 0;
                  searching = true;
                  *(int *)(programState + 0x5c) = *(int *)(programState + 0x5c) + 1;
                  while (slotScanIndex2 < *(uint *)(programState + 0x58)) {
                    if (!searching) goto storeRecordOffsetOrCount;
                    if (*(char *)(slotScanOffset + *(int *)(programState + 0x54) + 0x10) == '\0') {
                      in_r8 = 1;
                      searching = false;
                    }
                    else {
                      slotScanIndex2 = slotScanIndex2 + 1;
                      slotScanOffset = slotScanOffset + 0x28;
                    }
                  }
                  if (searching) {
                    *(char *)(shader + 4) = (char)in_r8;
                    slotCount = *(int *)(programState + 0x58);
                    newSlotArray = (**(code **)(ctx + 0x10))(slotCount + 0x10,0x28);
                    symbolIndex = *(int *)(programState + 0x58) * 0x28;
                    (**(code **)(((unsigned char *)0x00001344) + ctx))(newSlotArray,*(undefined4 *)(programState + 0x54),symbolIndex);
                    (**(code **)(ctx + 0x18))(*(undefined4 *)(programState + 0x54));
                    *(undefined4 *)(programState + 0x54) = newSlotArray;
                    *(int *)(programState + 0x58) = *(int *)(programState + 0x58) + 0x10;
loopStoreRecordOffsetOrCount:
                    *(int *)(recordOffsetOrCount + 4) = slotCount;
                    *(undefined1 *)(slotCount * 0x28 + *(int *)(programState + 0x54) + 0x10) = 1;
                  }
                  else {
storeRecordOffsetOrCount:
                    *(uint *)(recordOffsetOrCount + 4) = slotScanIndex2;
loopStoreSlotScanIndex22:
                    *(undefined1 *)(slotScanIndex2 * 0x28 + *(int *)(programState + 0x54) + 0x10) = 1;
                  }
                }
                else if (symbolDataType == 0x87c0) {
                  slotScanIndex2 = 0;
                  slotScanOffset = 0;
                  searching = true;
                  *(int *)(programState + 0x5c) = *(int *)(programState + 0x5c) + 4;
                  while (slotScanIndex2 < *(int *)(programState + 0x58) - 3U) {
                    if (!searching) goto setSlotWriteOffset2;
                    if (*(char *)(slotScanOffset + *(int *)(programState + 0x54) + 0x10) == '\0') {
                      searching = false;
                    }
                    else {
                      slotScanIndex2 = slotScanIndex2 + 1;
                      slotScanOffset = slotScanOffset + 0x28;
                    }
                  }
                  if (!searching) {
setSlotWriteOffset2:
                    slotWriteOffset = slotScanIndex2 * 0x28;
                    slotEntry5 = slotWriteOffset + *(int *)(programState + 0x54);
                    if (((*(char *)(slotEntry5 + 0x38) == '\0') && (*(char *)(slotEntry5 + 0x60) == '\0'))
                       && (*(char *)(slotEntry5 + 0x88) == '\0')) {
                      in_r8 = 0;
                      rowsLeft3 = 4;
                      in_r7 = 1;
                      do {
                        slotNumber4 = in_r8 + slotScanIndex2;
                        in_r8 = in_r8 + 1;
                        *(int *)(recordOffsetOrCount + 0x10) = slotNumber4;
                        recordOffsetOrCount = recordOffsetOrCount + 4;
                        slotEntry6 = slotWriteOffset + *(int *)(programState + 0x54);
                        slotWriteOffset = slotWriteOffset + 0x28;
                        *(undefined1 *)(slotEntry6 + 0x10) = 1;
                        rowsLeft3 = rowsLeft3 + -1;
                      } while (rowsLeft3 != 0);
                      goto setSlotScanIndex;
                    }
                  }
                  *(undefined1 *)(shader + 4) = 0;
                  slotCount3 = *(int *)(programState + 0x58);
                  newSlotArray = (**(code **)(ctx + 0x10))(slotCount3 + 0x10,0x28);
                  symbolIndex = *(int *)(programState + 0x58) * 0x28;
                  (**(code **)(((unsigned char *)0x00001344) + ctx))(newSlotArray,*(undefined4 *)(programState + 0x54),symbolIndex);
                  (**(code **)(ctx + 0x18))(*(undefined4 *)(programState + 0x54));
                  *(undefined4 *)(programState + 0x54) = newSlotArray;
                  slotWriteOffset2 = slotCount3 * 0x28;
                  rowsLeft2 = 4;
                  rowIndex2 = 0;
                  in_r8 = 1;
                  *(int *)(programState + 0x58) = *(int *)(programState + 0x58) + 0x10;
                  do {
                    slotNumber = rowIndex2 + slotCount3;
                    rowIndex2 = rowIndex2 + 1;
                    *(int *)(recordOffsetOrCount + 0x10) = slotNumber;
                    recordOffsetOrCount = recordOffsetOrCount + 4;
                    slotEntry = slotWriteOffset2 + *(int *)(programState + 0x54);
                    slotWriteOffset2 = slotWriteOffset2 + 0x28;
                    *(undefined1 *)(slotEntry + 0x10) = 1;
                    rowsLeft2 = rowsLeft2 + -1;
                  } while (rowsLeft2 != 0);
                }
                else if (symbolDataType == 0x87be) {
                  foundFlag = 0;
                  slotScanIndex2 = 0;
                  slotScanOffset = 0;
                  searching = true;
                  *(int *)(programState + 0x5c) = *(int *)(programState + 0x5c) + 1;
                  while (slotScanIndex2 < *(uint *)(programState + 0x58)) {
                    if (!searching) goto storeRecordOffsetOrCount2;
                    if (*(char *)(slotScanOffset + *(int *)(programState + 0x54) + 0x10) == '\0') {
                      foundFlag = 1;
                      searching = false;
                    }
                    else {
                      slotScanIndex2 = slotScanIndex2 + 1;
                      slotScanOffset = slotScanOffset + 0x28;
                    }
                  }
                  if (searching) {
                    *(char *)(shader + 4) = (char)foundFlag;
                    slotCount = *(int *)(programState + 0x58);
                    newSlotArray2 = (**(code **)(ctx + 0x10))(slotCount + 0x10,0x28);
                    symbolIndex = *(int *)(programState + 0x58) * 0x28;
                    (**(code **)(((unsigned char *)0x00001344) + ctx))(newSlotArray2,*(undefined4 *)(programState + 0x54),symbolIndex);
                    (**(code **)(ctx + 0x18))(*(undefined4 *)(programState + 0x54));
                    *(undefined4 *)(programState + 0x54) = newSlotArray2;
                    *(int *)(programState + 0x58) = *(int *)(programState + 0x58) + 0x10;
                    *(undefined4 *)(recordOffsetOrCount + 8) = foundFlag;
                    goto loopStoreRecordOffsetOrCount;
                  }
storeRecordOffsetOrCount2:
                  *(uint *)(recordOffsetOrCount + 4) = slotScanIndex2;
                  *(undefined4 *)(recordOffsetOrCount + 8) = 0;
                  goto loopStoreSlotScanIndex22;
                }
                goto setSlotScanIndex;
              }
            }
            else {
              instrRecords2 = extvsSymbolListGetIndex(shader + 7,*(int *)(recordOffsetOrCount + 0x30));
              symbolRecords = shader[8];
              instrRecords2 = instrRecords2 * 0x54;
            }
            if (*(int *)(symbolRecords + instrRecords2 + 0x34) != 0) {
              slotScanIndex2 = 0;
              dependentOffset = instrRecords2;
              do {
                slotFieldPtr2 = symbolRecords + dependentOffset;
                if (*(int *)(slotFieldPtr2 + 0x28) == 0x87c2) {
                  shader[0x17] = shader[0x17] + 1;
                  if (*(char *)(slotFieldPtr2 + 0x44) == '\0') {
                    *(int *)(programState + 0x224) = *(int *)(programState + 0x224) + 1;
                  }
                  else {
                    *(int *)(programState + 0x22c) = *(int *)(programState + 0x22c) + 1;
                  }
                  symbolDataType2 = *(int *)(slotFieldPtr2 + 0x24);
                  *(undefined1 *)(slotFieldPtr2 + 0x3d) = 1;
                  if (symbolDataType2 != 0x87bf) {
                    if (symbolDataType2 == 0x87c0) {
                      slotIndex = 0;
                      slotScanOffset2 = 0;
                      searching = true;
                      *(int *)(programState + 0x5c) = *(int *)(programState + 0x5c) + 4;
                      while (slotIndex < *(int *)(programState + 0x58) - 3U) {
                        if (!searching) goto setSlotByteOffset3;
                        if (*(char *)(slotScanOffset2 + *(int *)(programState + 0x54) + 0x10) == '\0') {
                          searching = false;
                        }
                        else {
                          slotIndex = slotIndex + 1;
                          slotScanOffset2 = slotScanOffset2 + 0x28;
                        }
                      }
                      if (!searching) {
setSlotByteOffset3:
                        slotByteOffset = slotIndex * 0x28;
                        slotEntry5 = slotByteOffset + *(int *)(programState + 0x54);
                        in_r8 = slotByteOffset;
                        if (((*(char *)(slotEntry5 + 0x38) == '\0') &&
                            (*(char *)(slotEntry5 + 0x60) == '\0')) &&
                           (*(char *)(slotEntry5 + 0x88) == '\0')) {
                          in_r8 = 0;
                          rowsLeft3 = 4;
                          in_r7 = 1;
                          do {
                            slotNumber3 = in_r8 + slotIndex;
                            in_r8 = in_r8 + 1;
                            *(int *)(slotFieldPtr2 + 0x10) = slotNumber3;
                            slotFieldPtr2 = slotFieldPtr2 + 4;
                            slotEntry4 = *(int *)(programState + 0x54) + slotByteOffset;
                            slotByteOffset = slotByteOffset + 0x28;
                            *(undefined1 *)(slotEntry4 + 0x10) = 1;
                            rowsLeft3 = rowsLeft3 + -1;
                          } while (rowsLeft3 != 0);
                          goto setSymbolRecords;
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
                      rowIndex3 = 0;
                      in_r8 = 1;
                      *(int *)(programState + 0x58) = *(int *)(programState + 0x58) + 0x10;
                      do {
                        slotNumber2 = oldSlotCount + rowIndex3;
                        rowIndex3 = rowIndex3 + 1;
                        *(int *)(slotFieldPtr2 + 0x10) = slotNumber2;
                        slotFieldPtr2 = slotFieldPtr2 + 4;
                        slotEntry2 = newSlotOffset + *(int *)(programState + 0x54);
                        newSlotOffset = newSlotOffset + 0x28;
                        *(undefined1 *)(slotEntry2 + 0x10) = 1;
                        rowsRemaining = rowsRemaining + -1;
                      } while (rowsRemaining != 0);
                    }
                    else if (symbolDataType2 == 0x87be) {
                      foundFlag = 0;
                      slotIndex = 0;
                      slotScanOffset2 = 0;
                      searching = true;
                      *(int *)(programState + 0x5c) = *(int *)(programState + 0x5c) + 1;
                      while (slotIndex < *(uint *)(programState + 0x58)) {
                        if (!searching) goto loopStoreSlotFieldPtr21;
                        if (*(char *)(slotScanOffset2 + *(int *)(programState + 0x54) + 0x10) == '\0') {
                          foundFlag = 1;
                          searching = false;
                        }
                        else {
                          slotIndex = slotIndex + 1;
                          slotScanOffset2 = slotScanOffset2 + 0x28;
                        }
                      }
loopCheckSearching3:
                      if (!searching) {
loopStoreSlotFieldPtr21:
                        *(uint *)(slotFieldPtr2 + 4) = slotIndex;
                        *(undefined4 *)(slotFieldPtr2 + 8) = 0;
                        *(undefined1 *)(slotIndex * 0x28 + *(int *)(programState + 0x54) + 0x10) = 1;
                        symbolRecords = shader[8];
                        goto setSlotScanIndex22;
                      }
                      *(char *)(shader + 4) = (char)foundFlag;
                      slotCount2 = *(int *)(programState + 0x58);
                      newSlotArray2 = (**(code **)(ctx + 0x10))(slotCount2 + 0x10,0x28);
                      symbolIndex = *(int *)(programState + 0x58) * 0x28;
                      (**(code **)(((unsigned char *)0x00001344) + ctx))(newSlotArray2,*(undefined4 *)(programState + 0x54),symbolIndex);
                      (**(code **)(ctx + 0x18))(*(undefined4 *)(programState + 0x54));
                      *(undefined4 *)(programState + 0x54) = newSlotArray2;
                      *(int *)(programState + 0x58) = *(int *)(programState + 0x58) + 0x10;
                      *(undefined4 *)(slotFieldPtr2 + 8) = foundFlag;
                      goto storeSlotFieldPtr21;
                    }
                    goto setSymbolRecords;
                  }
                  in_r8 = 0;
                  slotIndex = 0;
                  slotScanOffset2 = 0;
                  searching = true;
                  *(int *)(programState + 0x5c) = *(int *)(programState + 0x5c) + 1;
                  while (slotIndex < *(uint *)(programState + 0x58)) {
                    if (!searching) goto loopStoreSlotFieldPtr22;
                    if (*(char *)(slotScanOffset2 + *(int *)(programState + 0x54) + 0x10) == '\0') {
                      in_r8 = 1;
                      searching = false;
                    }
                    else {
                      slotIndex = slotIndex + 1;
                      slotScanOffset2 = slotScanOffset2 + 0x28;
                    }
                  }
loopCheckSearching4:
                  if (searching) {
                    *(char *)(shader + 4) = (char)in_r8;
                    slotCount2 = *(int *)(programState + 0x58);
                    newSlotArray = (**(code **)(ctx + 0x10))(slotCount2 + 0x10,0x28);
                    symbolIndex = *(int *)(programState + 0x58) * 0x28;
                    (**(code **)(((unsigned char *)0x00001344) + ctx))(newSlotArray,*(undefined4 *)(programState + 0x54),symbolIndex);
                    (**(code **)(ctx + 0x18))(*(undefined4 *)(programState + 0x54));
                    *(undefined4 *)(programState + 0x54) = newSlotArray;
                    *(int *)(programState + 0x58) = *(int *)(programState + 0x58) + 0x10;
storeSlotFieldPtr21:
                    *(int *)(slotFieldPtr2 + 4) = slotCount2;
                    *(undefined1 *)(slotCount2 * 0x28 + *(int *)(programState + 0x54) + 0x10) = 1;
                    symbolRecords = shader[8];
                  }
                  else {
loopStoreSlotFieldPtr22:
                    *(uint *)(slotFieldPtr2 + 4) = slotIndex;
                    *(undefined1 *)(slotIndex * 0x28 + *(int *)(programState + 0x54) + 0x10) = 1;
                    symbolRecords = shader[8];
                  }
                }
                else if (*(int *)(slotFieldPtr2 + 0x28) == 0x87c3) {
                  shader[0x18] = shader[0x18] + 1;
                  *(undefined1 *)(slotFieldPtr2 + 0x3d) = 1;
                  symbolDataType2 = *(int *)(slotFieldPtr2 + 0x24);
                  if (symbolDataType2 == 0x87bf) {
                    in_r8 = 0;
                    slotIndex = 0;
                    slotScanOffset2 = 0;
                    searching = true;
                    *(int *)(programState + 0x5c) = *(int *)(programState + 0x5c) + 1;
                    while (slotIndex < *(uint *)(programState + 0x58)) {
                      if (!searching) goto loopStoreSlotFieldPtr22;
                      if (*(char *)(slotScanOffset2 + *(int *)(programState + 0x54) + 0x10) == '\0') {
                        in_r8 = 1;
                        searching = false;
                      }
                      else {
                        slotIndex = slotIndex + 1;
                        slotScanOffset2 = slotScanOffset2 + 0x28;
                      }
                    }
                    goto loopCheckSearching4;
                  }
                  if (symbolDataType2 == 0x87c0) {
                    slotIndex = 0;
                    slotScanOffset2 = 0;
                    searching = true;
                    *(int *)(programState + 0x5c) = *(int *)(programState + 0x5c) + 4;
                    while (slotIndex < *(int *)(programState + 0x58) - 3U) {
                      if (!searching) goto setSlotByteOffset4;
                      if (*(char *)(slotScanOffset2 + *(int *)(programState + 0x54) + 0x10) == '\0') {
                        searching = false;
                      }
                      else {
                        slotIndex = slotIndex + 1;
                        slotScanOffset2 = slotScanOffset2 + 0x28;
                      }
                    }
                    if (!searching) {
setSlotByteOffset4:
                      slotByteOffset = slotIndex * 0x28;
                      slotEntry5 = slotByteOffset + *(int *)(programState + 0x54);
                      in_r8 = slotByteOffset;
                      if (((*(char *)(slotEntry5 + 0x38) == '\0') && (*(char *)(slotEntry5 + 0x60) == '\0'))
                         && (*(char *)(slotEntry5 + 0x88) == '\0')) {
                        in_r8 = 0;
                        rowsLeft3 = 4;
                        in_r7 = 1;
                        do {
                          slotNumber3 = in_r8 + slotIndex;
                          in_r8 = in_r8 + 1;
                          *(int *)(slotFieldPtr2 + 0x10) = slotNumber3;
                          slotFieldPtr2 = slotFieldPtr2 + 4;
                          slotEntry4 = *(int *)(programState + 0x54) + slotByteOffset;
                          slotByteOffset = slotByteOffset + 0x28;
                          *(undefined1 *)(slotEntry4 + 0x10) = 1;
                          rowsLeft3 = rowsLeft3 + -1;
                        } while (rowsLeft3 != 0);
                        goto setSymbolRecords;
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
                    rowIndex3 = 0;
                    in_r8 = 1;
                    *(int *)(programState + 0x58) = *(int *)(programState + 0x58) + 0x10;
                    do {
                      slotNumber2 = oldSlotCount + rowIndex3;
                      rowIndex3 = rowIndex3 + 1;
                      *(int *)(slotFieldPtr2 + 0x10) = slotNumber2;
                      slotFieldPtr2 = slotFieldPtr2 + 4;
                      slotEntry2 = *(int *)(programState + 0x54) + newSlotOffset;
                      newSlotOffset = newSlotOffset + 0x28;
                      *(undefined1 *)(slotEntry2 + 0x10) = 1;
                      rowsRemaining = rowsRemaining + -1;
                    } while (rowsRemaining != 0);
                  }
                  else if (symbolDataType2 == 0x87be) {
                    foundFlag = 0;
                    slotIndex = 0;
                    slotScanOffset2 = 0;
                    searching = true;
                    *(int *)(programState + 0x5c) = *(int *)(programState + 0x5c) + 1;
                    while (slotIndex < *(uint *)(programState + 0x58)) {
                      if (!searching) goto loopStoreSlotFieldPtr21;
                      if (*(char *)(slotScanOffset2 + *(int *)(programState + 0x54) + 0x10) == '\0') {
                        foundFlag = 1;
                        searching = false;
                      }
                      else {
                        slotIndex = slotIndex + 1;
                        slotScanOffset2 = slotScanOffset2 + 0x28;
                      }
                    }
                    goto loopCheckSearching3;
                  }
setSymbolRecords:
                  symbolRecords = shader[8];
                }
setSlotScanIndex22:
                slotScanIndex2 = slotScanIndex2 + 1;
                dependentOffset = dependentOffset + 0x54;
              } while (slotScanIndex2 < *(uint *)(instrRecords2 + symbolRecords + 0x34));
            }
          }
        }
setSlotScanIndex:
        slotScanIndex = slotScanIndex + 1;
        instrByteOffset = instrByteOffset + 0x74;
      } while (slotScanIndex < (uint)shader[5]);
      if (shader[5] != 0) {
        slotScanIndex = 0;
        instrByteOffset = 0;
        do {
          instrRecords2 = shader[6];
          if (*(int *)(instrByteOffset + instrRecords2 + 0x20) == 2) {
            symbolRecordsBase = shader[8];
            symbolByteOffset2 = *(int *)(instrByteOffset + instrRecords2 + 0x24) * 0x54;
            symbolRecordOrCallResult = symbolByteOffset2 + symbolRecordsBase;
            if ((*(int *)(symbolRecordOrCallResult + 0x28) == 0x87c3) && (*(char *)(symbolRecordOrCallResult + 0x3d) == '\0')) {
              if (*(int *)(symbolRecordOrCallResult + 0x30) == 0) {
                if (*(uint *)(symbolRecordOrCallResult + 0x34) < 2) {
                  extvsAllocConstantRegisters(ctx,shader,programState,symbolRecordOrCallResult);
                  instrRecords2 = shader[6];
                  goto checkInstrByteOffset3;
                }
              }
              else {
                symbolByteOffset2 = extvsSymbolListGetIndex(shader + 7,*(int *)(symbolRecordOrCallResult + 0x30));
                symbolRecordsBase = shader[8];
                symbolByteOffset2 = symbolByteOffset2 * 0x54;
              }
              if (*(int *)(symbolRecordsBase + symbolByteOffset2 + 0x34) != 0) {
                slotScanIndex2 = 0;
                dependentOffset2 = symbolByteOffset2;
                do {
                  symbolRecordsBase = dependentOffset2 + symbolRecordsBase;
                  slotScanIndex2 = slotScanIndex2 + 1;
                  dependentOffset2 = dependentOffset2 + 0x54;
                  extvsAllocConstantRegisters(ctx,shader,programState,symbolRecordsBase);
                  symbolRecordsBase = shader[8];
                } while (slotScanIndex2 < *(uint *)(symbolRecordsBase + symbolByteOffset2 + 0x34));
              }
              instrRecords2 = shader[6];
            }
          }
checkInstrByteOffset3:
          if (*(int *)(instrByteOffset + instrRecords2 + 0x3c) == 2) {
            symbolRecordsBase = shader[8];
            symbolByteOffset2 = *(int *)(instrByteOffset + instrRecords2 + 0x40) * 0x54;
            symbolRecordOrCallResult = symbolByteOffset2 + symbolRecordsBase;
            if ((*(int *)(symbolRecordOrCallResult + 0x28) == 0x87c3) && (*(char *)(symbolRecordOrCallResult + 0x3d) == '\0')) {
              if (*(int *)(symbolRecordOrCallResult + 0x30) == 0) {
                if (*(uint *)(symbolRecordOrCallResult + 0x34) < 2) {
                  extvsAllocConstantRegisters(ctx,shader,programState,symbolRecordOrCallResult);
                  instrRecords2 = shader[6];
                  goto checkInstrByteOffset4;
                }
              }
              else {
                symbolByteOffset2 = extvsSymbolListGetIndex(shader + 7,*(int *)(symbolRecordOrCallResult + 0x30));
                symbolRecordsBase = shader[8];
                symbolByteOffset2 = symbolByteOffset2 * 0x54;
              }
              if (*(int *)(symbolRecordsBase + symbolByteOffset2 + 0x34) != 0) {
                slotScanIndex2 = 0;
                dependentOffset2 = symbolByteOffset2;
                do {
                  symbolRecordsBase = dependentOffset2 + symbolRecordsBase;
                  slotScanIndex2 = slotScanIndex2 + 1;
                  dependentOffset2 = dependentOffset2 + 0x54;
                  extvsAllocConstantRegisters(ctx,shader,programState,symbolRecordsBase);
                  symbolRecordsBase = shader[8];
                } while (slotScanIndex2 < *(uint *)(symbolRecordsBase + symbolByteOffset2 + 0x34));
              }
              instrRecords2 = shader[6];
            }
          }
checkInstrByteOffset4:
          if (*(int *)(instrByteOffset + instrRecords2 + 0x58) == 2) {
            symbolRecordOrCallResult = shader[8];
            instrRecords2 = *(int *)(instrByteOffset + instrRecords2 + 0x5c) * 0x54;
            recordOffsetOrCount = instrRecords2 + symbolRecordOrCallResult;
            if ((*(int *)(recordOffsetOrCount + 0x28) == 0x87c3) && (*(char *)(recordOffsetOrCount + 0x3d) == '\0')) {
              if (*(int *)(recordOffsetOrCount + 0x30) == 0) {
                if (*(uint *)(recordOffsetOrCount + 0x34) < 2) {
                  extvsAllocConstantRegisters(ctx,shader,programState,recordOffsetOrCount);
                  goto setSlotScanIndex2X;
                }
              }
              else {
                instrRecords2 = extvsSymbolListGetIndex(shader + 7,*(int *)(recordOffsetOrCount + 0x30));
                symbolRecordOrCallResult = shader[8];
                instrRecords2 = instrRecords2 * 0x54;
              }
              if (*(int *)(symbolRecordOrCallResult + instrRecords2 + 0x34) != 0) {
                slotScanIndex2 = 0;
                dependentOffset = instrRecords2;
                do {
                  symbolRecordOrCallResult = dependentOffset + symbolRecordOrCallResult;
                  slotScanIndex2 = slotScanIndex2 + 1;
                  dependentOffset = dependentOffset + 0x54;
                  extvsAllocConstantRegisters(ctx,shader,programState,symbolRecordOrCallResult);
                  symbolRecordOrCallResult = shader[8];
                } while (slotScanIndex2 < *(uint *)(symbolRecordOrCallResult + instrRecords2 + 0x34));
              }
            }
          }
setSlotScanIndex2X:
          slotScanIndex = slotScanIndex + 1;
          instrByteOffset = instrByteOffset + 0x74;
        } while (slotScanIndex < (uint)shader[5]);
      }
    }
    if ((*(char *)((int)shader + 0x7a) != '\0') && ((*(uint *)(ctx + 0x44) & 0x1000000) != 0))
    {
      slotHighWater = *(int *)(programState + 0x5c) + 1;
      *(int *)(programState + 0x60) = *(int *)(programState + 0x5c);
      *(uint *)(programState + 0x5c) = slotHighWater;
      if (*(uint *)(programState + 0x58) < slotHighWater) {
        *(undefined1 *)(shader + 4) = 0;
        newSlotArray3 = (**(code **)(ctx + 0x10))(*(int *)(programState + 0x58) + 0x10,0x28);
        (**(code **)(((unsigned char *)0x00001344) + ctx))
                  (newSlotArray3,*(undefined4 *)(programState + 0x54),*(int *)(programState + 0x58) * 0x28);
        (**(code **)(ctx + 0x18))(*(undefined4 *)(programState + 0x54));
        *(undefined4 *)(programState + 0x54) = newSlotArray3;
        *(int *)(programState + 0x58) = *(int *)(programState + 0x58) + 0x10;
      }
    }
    maxTempsUsed = 0;
    *(undefined4 *)(programState + 0x18) = 0;
    instrIndex = 0;
    if (shader[5] != 0) {
      slotIndex = 0;
      instrByteOffset = 0;
      do {
        if (0x20 < *(int *)(instrByteOffset + shader[6]) - 0x8782U) {
          shader[0x19] = 0;
          shader[0xc] = 0;
          shader[0x15] = 0;
          shader[0x16] = 0;
          shader[0x17] = 0;
          shader[0x18] = 0;
          return 0;
        }
        extvsAllocTempRegisters(ctx,shader,programState,instrByteOffset + shader[6] + 4);
        extvsAllocTempRegisters(ctx,shader,programState,instrByteOffset + shader[6] + 0x20);
        extvsAllocTempRegisters(ctx,shader,programState,instrByteOffset + shader[6] + 0x3c);
        recordOrOffsetScratch = instrByteOffset + shader[6] + 0x58;
        extvsAllocTempRegisters(ctx,shader,programState,recordOrOffsetScratch);
        if (maxTempsUsed < (uint)shader[0x19]) {
          maxTempsUsed = shader[0x19];
        }
        opIndex = *(int *)(instrByteOffset + shader[6]) + -0x8782;
        symbolRecordOrCallResult = (*(code *)(ptrTo_extvsEmitIndex_001db9b8)[opIndex])(ctx,shader,instrByteOffset + shader[6]);
        if (symbolRecordOrCallResult < 0) {
          success = 0;
          goto loopStoreShader;
        }
        *(int *)(programState + 0x18) = symbolRecordOrCallResult + *(int *)(programState + 0x18);
        glContextWord44 = *(uint *)(ctx + 0x44);
        if ((glContextWord44 & 0x800) != 0) {
          symbolRecordOrCallResult = instrByteOffset + shader[6];
          dstOperandKind = *(int *)(symbolRecordOrCallResult + 4);
          if ((dstOperandKind == 1) && (*(int *)(symbolRecordOrCallResult + 8) == 0x87bd)) {
            fogCopyUnit = ((unsigned char *)0x000011d1)[ctx];
            _memcpy(tempInstr,symbolRecordOrCallResult,0x74);
            tempInstrDstMaskY = 0;
            tempInstrDstMaskZ = 0;
            tempInstrDstMaskW = 0;
            tempInstrDstId = fogCopyUnit + 0x879d;
            tempInstrDstMaskX = dstOperandKind;
            symbolRecordOrCallResult = (*(code *)(ptrTo_extvsEmitIndex_001db9b8)[opIndex])(ctx,shader,tempInstr);
            hwInstrCountCopy = *(int *)(programState + 0x18);
            *(int *)(programState + 0x18) = symbolRecordOrCallResult + hwInstrCountCopy;
            tempInstrSrc0SwizzleW = 0x87de;
            tempInstr[0] = 0x8799;
            tempInstrDstMaskX = 0;
            tempInstrSrc0SwizzleX = 0x87dd;
            tempInstrSrc0SwizzleY = 0x87dd;
            tempInstrSrc0SwizzleZ = 0x87dd;
            tempInstrDstMaskY = dstOperandKind;
            tempInstrDstMaskZ = dstOperandKind;
            tempInstrDstMaskW = dstOperandKind;
            symbolRecordOrCallResult = (*(code *)ptrTo_extvsEmitMov_001dba14)
                               (ctx,shader,tempInstr,recordOrOffsetScratch,in_r7,in_r8,hwInstrCountCopy);
            *(int *)(programState + 0x18) = symbolRecordOrCallResult + *(int *)(programState + 0x18);
            glContextWord44 = *(uint *)(ctx + 0x44);
          }
        }
        if ((((glContextWord44 & 0x400) != 0) && (symbolRecordOrCallResult = instrByteOffset + shader[6], *(int *)(symbolRecordOrCallResult + 4) == 1)) &&
           (*(int *)(symbolRecordOrCallResult + 8) == 0x879a)) {
          _memcpy(tempInstr,symbolRecordOrCallResult,0x74);
          tempInstrDstId = (byte)((unsigned char *)0x000011d2)[ctx] + 0x879d;
          recordOrOffsetScratch = (*(code *)(ptrTo_extvsEmitIndex_001db9b8)[opIndex])
                             (ctx,shader,tempInstr,recordOrOffsetScratch,in_r7,in_r8,
                              (ptrTo_extvsEmitIndex_001db9b8)[opIndex]);
          *(int *)(programState + 0x18) = recordOrOffsetScratch + *(int *)(programState + 0x18);
        }
        if (*(char *)((int)shader + 0x7b) == '\0') {
          extvsFreeDeadTempSlots(ctx,shader,slotIndex);
        }
        if (((*(char *)((int)shader + 0x7a) != '\0') &&
            ((*(uint *)(ctx + 0x44) & 0x1000000) != 0)) &&
           ((*(int *)(instrByteOffset + shader[6] + 4) == 1 && (*(int *)(instrByteOffset + shader[6] + 8) == 0x87bd)
            ))) {
          recordOffsetOrCount = *(int *)(programState + 0x18);
          recordOrOffsetScratch = ((int (*)())extvsEmitFogOutput)(ctx,shader,recordOffsetOrCount * 0x10 + *(int *)(programState + 0x1c) + -0x10);
          *(int *)(programState + 0x18) = recordOffsetOrCount + recordOrOffsetScratch;
        }
        instrIndex = shader[5];
        slotIndex = slotIndex + 1;
        instrByteOffset = instrByteOffset + 0x74;
      } while (slotIndex < instrIndex);
    }
    hwInstrCount = *(int *)(programState + 0x18);
    shader[0x19] = maxTempsUsed;
    shader[0x15] = hwInstrCount;
    if (instrIndex != 0) {
      slotScanIndex = 0;
      instrByteOffset = 0;
      do {
        recordOrOffsetScratch = slotScanIndex * 0x10;
        slotScanIndex = slotScanIndex + 1;
        recordOffsetOrCount = recordOrOffsetScratch + writeEnableSnapshot;
        maskWord3 = *(undefined4 *)(recordOffsetOrCount + 0xc);
        maskWord1 = *(undefined4 *)(recordOffsetOrCount + 4);
        symbolRecordOrCallResult = instrByteOffset + shader[6];
        instrByteOffset = instrByteOffset + 0x74;
        maskWord2 = *(undefined4 *)(recordOffsetOrCount + 8);
        *(undefined4 *)(symbolRecordOrCallResult + 0xc) = *(undefined4 *)(writeEnableSnapshot + recordOrOffsetScratch);
        *(undefined4 *)(symbolRecordOrCallResult + 0x18) = maskWord3;
        *(undefined4 *)(symbolRecordOrCallResult + 0x10) = maskWord1;
        *(undefined4 *)(symbolRecordOrCallResult + 0x14) = maskWord2;
      } while (slotScanIndex < (uint)shader[5]);
    }
    (**(code **)(ctx + 0x18))(writeEnableSnapshot);
    writeEnableSnapshot = *(int *)(programState + 0x18);
    *(undefined4 *)(programState + 8) = 0;
    if (writeEnableSnapshot != 0) {
      do {
        hwInstrWord = *(uint *)(writeEnableSnapshot * 0x10 + *(int *)(programState + 0x1c) + -0x10);
        hwOpClass = hwInstrWord & 0xf00;
        if (((hwOpClass == 0x200) || (hwOpClass == 0x300)) && ((hwInstrWord & 0xfe000) == 0)) {
          *(int *)(programState + 8) = writeEnableSnapshot + -1;
        }
        writeEnableSnapshot = writeEnableSnapshot + -1;
      } while ((writeEnableSnapshot != 0) && (*(int *)(programState + 8) == 0));
    }
    if (*(int *)(programState + 0x224) != 0) {
      newIndexList = (**(code **)(ctx + 0xc))(*(int *)(programState + 0x224) << 2);
      *(undefined4 *)(programState + 0x220) = newIndexList;
      symbolCount = shader[7];
      if (symbolCount != 0) {
        slotScanIndex2 = 0;
        writeEnableSnapshot = 0;
        symbolByteOffset = 0;
        do {
          recordOrOffsetScratch = symbolByteOffset + shader[8];
          if (((*(char *)(recordOrOffsetScratch + 0x3d) != '\0') && (*(int *)(recordOrOffsetScratch + 0x28) == 0x87c2)) &&
             (*(char *)(recordOrOffsetScratch + 0x44) == '\0')) {
            recordOrOffsetScratch = writeEnableSnapshot * 4;
            writeEnableSnapshot = writeEnableSnapshot + 1;
            *(uint *)(recordOrOffsetScratch + *(int *)(programState + 0x220)) = slotScanIndex2;
            symbolCount = shader[7];
          }
          slotScanIndex2 = slotScanIndex2 + 1;
          symbolByteOffset = symbolByteOffset + 0x54;
        } while (slotScanIndex2 < symbolCount);
      }
    }
    if (*(int *)(programState + 0x22c) != 0) {
      newIndexList = (**(code **)(ctx + 0xc))(*(int *)(programState + 0x22c) << 2);
      *(undefined4 *)(programState + 0x228) = newIndexList;
      symbolCount = shader[7];
      if (symbolCount != 0) {
        slotScanIndex2 = 0;
        writeEnableSnapshot = 0;
        symbolByteOffset = 0;
        do {
          recordOrOffsetScratch = symbolByteOffset + shader[8];
          if (((*(char *)(recordOrOffsetScratch + 0x3d) != '\0') && (*(int *)(recordOrOffsetScratch + 0x28) == 0x87c2)) &&
             (*(char *)(recordOrOffsetScratch + 0x44) != '\0')) {
            recordOffsetOrCount = writeEnableSnapshot * 4;
            writeEnableSnapshot = writeEnableSnapshot + 1;
            *(uint *)(recordOffsetOrCount + *(int *)(programState + 0x228)) = slotScanIndex2;
            *(uint *)(programState + 0x230) = *(uint *)(programState + 0x230) | *(uint *)(recordOrOffsetScratch + 0x50);
            symbolCount = shader[7];
          }
          slotScanIndex2 = slotScanIndex2 + 1;
          symbolByteOffset = symbolByteOffset + 0x54;
        } while (slotScanIndex2 < symbolCount);
      }
    }
    slotHighWater2 = *(uint *)(programState + 0x5c);
    if (slotHighWater2 != 0) {
      if (hwProgramSlot[0x23] < slotHighWater2) {
        slotHighWater2 = (**(code **)(ctx + 0x14))(hwProgramSlot[0x22],slotHighWater2 << 4);
        hwProgramSlot[0x22] = slotHighWater2;
        hwProgramSlot[0x23] = *(uint *)(programState + 0x5c);
      }
      if (shader[0x18] != 0) {
        symbolCount2 = shader[7];
        slotScanIndex = 0;
        if (symbolCount2 != 0) {
          do {
            writeEnableSnapshot = slotScanIndex * 0x54 + shader[8];
            if ((*(char *)(writeEnableSnapshot + 0x3d) != '\0') && (*(int *)(writeEnableSnapshot + 0x28) == 0x87c3)) {
              constVector = *(undefined4 **)(writeEnableSnapshot + 0x38);
              constWord3 = constVector[3];
              writeEnableSnapshot = *(int *)(writeEnableSnapshot + 4) * 0x10;
              constWord1 = constVector[1];
              constWord2 = constVector[2];
              outputIndexScaled = writeEnableSnapshot + hwProgramSlot[0x22];
              *(undefined4 *)(writeEnableSnapshot + hwProgramSlot[0x22]) = *constVector;
              *(undefined4 *)(outputIndexScaled + 0xc) = constWord3;
              *(undefined4 *)(outputIndexScaled + 4) = constWord1;
              *(undefined4 *)(outputIndexScaled + 8) = constWord2;
              symbolCount2 = shader[7];
            }
            slotScanIndex = slotScanIndex + 1;
          } while (slotScanIndex < symbolCount2);
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
    success = *(undefined1 *)(shader + 4);
  }
  return success;
}

/* vpUploadConstantArray @ 0x61dc0 (224 bytes) */
int vpUploadConstantArray(glContext, programState)
  int glContext;
  int programState;
{
  code *UNRECOVERED_JUMPTABLE;
  undefined4 *packet;
  int packetPos;
  
  packetPos = *(int *)(programState + 0x18);
  if ((packetPos != 0) && (*(int *)(programState + 0x1c) != 0)) {
    packet = (undefined4 *)(**(code **)(glContext + 0x2758))(glContext,packetPos * 4 + 3);
    *(undefined4 **)(0x00002748 + glContext + 4) = packet;
    *packet = 0x880;
    *(undefined4 *)(*(int *)(0x00002748 + glContext + 4) + 4) = *(undefined4 *)(programState + 4);
    *(uint *)(*(int *)(0x00002748 + glContext + 4) + 8) = (packetPos * 4 + -1) * 0x10000 | 0x8882;
    _memcpy(*(int *)(0x00002748 + glContext + 4) + 0xc,*(undefined4 *)(programState + 0x1c),packetPos * 0x10)
    ;
    UNRECOVERED_JUMPTABLE = *(code **)(glContext + 0x275c);
    packetPos = packetPos * 0x10 + *(int *)(0x00002748 + glContext + 4) + 0xc;
    *(int *)(0x00002748 + glContext + 4) = packetPos;
                    
                    
    (*UNRECOVERED_JUMPTABLE)(glContext,packetPos);
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
int extvsStateFree(ctx, chainEntry)
  int ctx;
  int chainEntry;
{
  if (*(int *)(chainEntry + 0x1c) != 0) {
    (**(code **)(ctx + 0x18))(*(int *)(chainEntry + 0x1c));
  }
  if (*(int *)(chainEntry + 0x24) != 0) {
    (**(code **)(ctx + 0x18))(*(int *)(chainEntry + 0x24));
  }
  if (*(int *)(chainEntry + 0x4c) != 0) {
    (**(code **)(ctx + 0x18))(*(int *)(chainEntry + 0x4c));
  }
  if (*(int *)(chainEntry + 0x54) != 0) {
    (**(code **)(ctx + 0x18))(*(int *)(chainEntry + 0x54));
  }
  if (*(int *)(chainEntry + 0x220) != 0) {
    (**(code **)(ctx + 0x18))(*(int *)(chainEntry + 0x220));
  }
  if (*(int *)(chainEntry + 0x228) != 0) {
    (**(code **)(ctx + 0x18))(*(int *)(chainEntry + 0x228));
  }
  if (*(int *)(chainEntry + 0x2b8) != 0) {
    (**(code **)(ctx + 0x18))(*(int *)(chainEntry + 0x2b8));
  }
  (**(code **)(ctx + 0x18))(chainEntry);
  return ctxTempListRemove(ctx,chainEntry);
}

/* gldLoadUnitFlagBits @ 0x62370 (104 bytes) */
int gldLoadUnitFlagBits(glContext, programEntry, useUnitFlags)
  int glContext;
  int programEntry;
  int useUnitFlags;
{
  byte *unitFlagPtr;
  int wordCursor;
  int wordsLeft;
  
  if (useUnitFlags == 0) {
    wordCursor = glContext + 0x18a0;
    wordsLeft = 0x10;
    do {
      unitFlagPtr = (byte *)(programEntry + 0x71);
      programEntry = programEntry + 1;
      *(uint *)(wordCursor + 8) = -(uint)*unitFlagPtr >> 0x1f | *(uint *)(wordCursor + 8) & 0xfffffffe;
      wordCursor = wordCursor + 8;
      wordsLeft = wordsLeft + -1;
    } while (wordsLeft != 0);
  }
  else {
    wordCursor = glContext + 0x18a0;
    wordsLeft = 0x10;
    do {
      *(uint *)(wordCursor + 8) = *(uint *)(wordCursor + 8) & 0xfffffffe;
      wordCursor = wordCursor + 8;
      wordsLeft = wordsLeft + -1;
    } while (wordsLeft != 0);
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

/* gldAllocListNode @ 0x62410 (116 bytes) */
int gldAllocListNode(glContext)
  int glContext;
{
  undefined4 nodeData;
  undefined4 *newNode;
  
  newNode = (undefined4 *)(**(code **)(glContext + 0xc))(0xc);
  *newNode = 0;
  nodeData = *(undefined4 *)(glContext + 0x2448);
  newNode[2] = 0;
  newNode[1] = nodeData;
  *(undefined4 *)(((unsigned char *)0x000011c8) + glContext) = 0x20;
  *(undefined4 **)(((unsigned char *)0x000011b4) + glContext) = newNode;
  *(undefined4 *)(((unsigned char *)0x000011c4) + glContext) = 0x100;
  *(undefined4 *)(((unsigned char *)0x000011bc) + glContext) = 0x10;
  *(undefined4 *)(((unsigned char *)0x000011b8) + glContext) = 0x100;
  *(undefined4 *)(((unsigned char *)0x000011c0) + glContext) = 0x100;
  return;
}

/* gldFreeListNodes @ 0x62490 (120 bytes) */
int gldFreeListNodes(glContext)
  int glContext;
{
  undefined4 *listNode;
  int listObject;
  undefined4 *nextNode;
  
  listObject = *(int *)(((unsigned char *)0x000011b4) + glContext);
  listNode = *(undefined4 **)(listObject + 8);
  while (listNode != (undefined4 *)0x0) {
    *(undefined1 *)*listNode = 0;
    nextNode = (undefined4 *)listNode[1];
    (**(code **)(glContext + 0x18))(listNode);
    listNode = nextNode;
  }
  *(undefined4 *)(listObject + 8) = 0;
  return;
}

/* gldDestroyListObject @ 0x62510 (92 bytes) */
int gldDestroyListObject(glContext)
  int glContext;
{
  if (*(int *)(((unsigned char *)0x000011b4) + glContext) != 0) {
    ((int (*)())gldFreeListNodes)(glContext);
    (**(code **)(glContext + 0x18))(*(undefined4 *)(((unsigned char *)0x000011b4) + glContext));
    *(undefined4 *)(((unsigned char *)0x000011b4) + glContext) = 0;
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
  undefined4 valueXOrCmdWord;
  int constantAddr;
  int slotByteOffset;
  undefined4 *cmdBuffer;
  undefined4 valueYOrCmdWord;
  undefined4 valueZOrCmdWord;
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
  valueXOrCmdWord = *values;
  cmdBase = *(int *)(0x00002748 + glContext + 4);
  valueYOrCmdWord = values[1];
  valueZOrCmdWord = values[2];
  *(undefined4 *)(cmdBase + 0x20) = values[3];
  *(undefined4 *)(cmdBase + 0x14) = valueXOrCmdWord;
  *(undefined4 *)(cmdBase + 0x18) = valueYOrCmdWord;
  *(undefined4 *)(cmdBase + 0x1c) = valueZOrCmdWord;
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
int gldCurrentAttributePacketHeader(unusedArg1, attributeIndex, dwordCount)
  undefined4 unusedArg1;
  undefined4 attributeIndex;
  int dwordCount;
{
  uint countField;
  
  countField = (dwordCount + -1) * 0x10000;
  switch(attributeIndex) {
  default:
    return 0;
  case 2:
    return countField | 0x8c8;
  case 3:
    return countField | 0x8cc;
  case 4:
    return countField | 0x8d0;
  case 5:
    return countField | 0x8d4;
  case 6:
    return countField | 0x8d8;
  case 7:
    return countField | 0x8dc;
  case 8:
    return countField | 0x8e0;
  case 9:
    return countField | 0x8e4;
  case 10:
    return countField | 0x8e8;
  case 0xb:
    return countField | 0x8ec;
  case 0xc:
    return countField | 0x8f0;
  case 0xd:
    return countField | 0x8f4;
  case 0xe:
    return countField | 0x8f8;
  case 0xf:
    return countField | 0x8fc;
  case 0x10:
    return countField | 0x900;
  case 0x11:
    return countField | 0x904;
  case 0x13:
    return countField | 0x90c;
  case 0x14:
    return countField | 0x910;
  case 0x15:
    return countField | 0x914;
  }
}

/* extvsBuildStreamBlock @ 0x64230 (1256 bytes) */
int extvsBuildStreamBlock(ctx, shader)
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
  uint tclStateWord;
  int inputBlock;
  uint *streamBlock;
  uint *streamFlagTable;
  int componentMask;
  bool nextStreamHighHalf;
  int componentMaskOrOutputCount;
  uint fogParamWord;
  uint inputTypeWord;
  int inputIndexOrAddr;
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
  componentMaskOrOutputCount = 0;
  streamBlock[1] = 4;
  streamBlock[2] = 1;
  savedWord10 = streamBlock[0x10];
  streamBlock[5] = savedWord5 & 0xffffff00 | 3;
  inputTypeWord = *(uint *)(((unsigned char *)0x000055e8) + inputBlock);
  streamBlock[0x10] = savedWord10 & 0xfffff000 | 0x688;
  streamBlock[5] = (inputTypeWord & 0x1f) << 8 | savedWord5 & 0xffff0000 | 3;
  if (*(int *)(((unsigned char *)0x000055e8) + inputBlock) != 0x16) {
    componentMaskOrOutputCount = 0xf;
  }
  *streamBlock = 1;
  descriptorWordIndex = 0;
  nextStreamHighHalf = true;
  streamBlock[0x1b] = 1;
  streamBlock[0x1d] = 1;
  streamBlock[0x10] = componentMaskOrOutputCount << 0xc | savedWord10 & 0xffff0000 | 0x688;
  streamFlagTable = &DAT_001dbab8;
  streamCount = 1;
  inputsLeft = 0x15;
  inputRecordCursor = programState;
  do {
    if (0 < *(int *)(inputRecordCursor + 100)) {
      inputIndexOrAddr = *(int *)(inputRecordCursor + 0xbc);
      streamBlock[1] = (streamBlock[1] & 0x7f) + 4 & 0x7f | streamBlock[1] & 0xffffff80;
      if (nextStreamHighHalf) {
        componentMask = 0;
        inputIndexOrAddr = inputIndexOrAddr * 4 + inputBlock + 0x24;
        descWord = streamBlock[descriptorWordIndex + 5];
        streamBlock[descriptorWordIndex + 5] = descWord & 0xff00ffff | 0x30000;
        streamBlock[descriptorWordIndex + 5] =
             (*(uint *)(((unsigned char *)0x000055c4) + inputIndexOrAddr) & 0x1f) << 0x18 | descWord & 0xffff | 0x30000;
        streamBlock[descriptorWordIndex + 0x10] = streamBlock[descriptorWordIndex + 0x10] & 0xf000ffff | 0x6880000;
        if (*(int *)(((unsigned char *)0x000055c4) + inputIndexOrAddr) != 0x16) {
          componentMask = 0xf;
        }
        nextStreamHighHalf = false;
        streamBlock[descriptorWordIndex + 0x10] = componentMask << 0x1c | streamBlock[descriptorWordIndex + 0x10] & 0xfffffff;
        descriptorWordIndex = descriptorWordIndex + 1;
      }
      else {
        componentMask = 0;
        inputIndexOrAddr = inputIndexOrAddr * 4 + inputBlock + 0x24;
        descWord = streamBlock[descriptorWordIndex + 5];
        streamBlock[descriptorWordIndex + 5] = descWord & 0xffffff00 | 3;
        streamBlock[descriptorWordIndex + 5] =
             (*(uint *)(((unsigned char *)0x000055c4) + inputIndexOrAddr) & 0x1f) << 8 | descWord & 0xffff0000 | 3;
        streamBlock[descriptorWordIndex + 0x10] = streamBlock[descriptorWordIndex + 0x10] & 0xfffff000 | 0x688;
        if (*(int *)(((unsigned char *)0x000055c4) + inputIndexOrAddr) != 0x16) {
          componentMask = 0xf;
        }
        nextStreamHighHalf = true;
        streamBlock[descriptorWordIndex + 0x10] = componentMask << 0xc | streamBlock[descriptorWordIndex + 0x10] & 0xffff0fff;
      }
      streamCount = streamCount + 1;
      streamTotal = streamBlock[0x1b] + 1;
      streamBlock[0x1b] = streamTotal;
      *streamBlock = *streamBlock | *streamFlagTable;
      if (streamCount == *(int *)(programState + 0x110)) goto checkStreamTotal;
    }
    inputRecordCursor = inputRecordCursor + 4;
    streamFlagTable = streamFlagTable + 1;
    inputsLeft = inputsLeft + -1;
  } while (inputsLeft != 0);
  streamTotal = streamBlock[0x1b];
checkStreamTotal:
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
      componentMaskOrOutputCount = 4;
      if ((outputFlags & 8) == 0) {
        componentMaskOrOutputCount = 3 - (uint)((outputFlags & 4) == 0);
      }
      fieldValue = componentMaskOrOutputCount << (fieldShift & 0x3f);
      streamBlock[3] = fieldValue | streamBlock[3];
      streamBlock[4] = fieldValue | streamBlock[4];
      streamBlock[0x1d] = streamBlock[0x1d] + 1;
    }
    shader = (int *)((int)shader + 1);
    fieldShift = fieldShift + 3;
    outputsLeft = outputsLeft + -1;
  } while (outputsLeft != 0);
  streamBlock[2] = *(uint *)(((unsigned char *)0x00005498) + inputBlock);
  fogParamWord = *(uint *)(((unsigned char *)0x0000549c) + inputBlock);
  streamBlock[3] = fogParamWord;
  tclStateWord = *(uint *)(((unsigned char *)0x00005434) + inputBlock);
  streamBlock[0x1d] = tclStateWord;
  if (tclStateWord == 1) {
    streamBlock[0x1d] = 2;
    streamBlock[3] = fogParamWord & 0xff1fffff | 0x800000;
    streamBlock[4] = streamBlock[4] & 0xff1fffff | 0x800000;
  }
  return;
}

/* gldCopyRouteRegisters @ 0x64720 (304 bytes) */
int gldCopyRouteRegisters(glContext)
  int glContext;
{
  undefined4 *constWordPtr;
  byte unitFlagByte;
  int routeCount;
  undefined4 in_r5;
  undefined4 in_r6;
  undefined4 in_r7;
  int programState;
  int routeDst;
  undefined4 a6;
  uint loopIndex;
  code *a7;
  int routeSrc;
  
  programState = **(int **)(*(int *)(((unsigned char *)0x0000118c) + glContext) * 4 + **(int **)(((unsigned char *)0x00001168) + glContext));
  if (*(char *)(*(int **)(((unsigned char *)0x00001168) + glContext) + 4) != '\0') {
    if ((*(uint *)(glContext + 0x8c) & 0x40000000) == 0) {
      *(undefined4 *)(glContext + 0x1ca0) = *(undefined4 *)(programState + 0x234);
      *(undefined4 *)(glContext + 0x1ca4) = *(undefined4 *)(programState + 0x238);
      *(undefined4 *)(glContext + 0x1b9c) = *(undefined4 *)(programState + 0x23c);
      *(undefined4 *)(glContext + 0x1ba0) = *(undefined4 *)(programState + 0x240);
      routeCount = *(int *)(programState + 0x2a0);
      if (routeCount + 1U >> 1 != 0) {
        loopIndex = 0;
        routeDst = glContext;
        routeSrc = programState;
        do {
          loopIndex = loopIndex + 1;
          *(undefined4 *)(routeDst + 0x1be4) = *(undefined4 *)(routeSrc + 0x244);
          constWordPtr = (undefined4 *)(routeSrc + 0x270);
          routeSrc = routeSrc + 4;
          *(undefined4 *)(routeDst + 0x1c04) = *constWordPtr;
          routeDst = routeDst + 4;
          routeCount = *(int *)(programState + 0x2a0);
        } while (loopIndex < routeCount + 1U >> 1);
      }
      *(int *)(glContext + 0x2438) = routeCount;
      a7 = *(code **)(((unsigned char *)0x00001334) + glContext);
      a6 = *(undefined4 *)(programState + 0x2a0);
      *(undefined4 *)(glContext + 0x1b78) = 0;
      *(undefined4 *)(glContext + 0x243c) = a6;
      unitFlagByte = *(byte *)(programState + 0x36);
      *(uint *)(glContext + 0x1930) = *(uint *)(glContext + 0x1930) | 0x40000;
      *(uint *)(glContext + 0x1b78) = unitFlagByte & 3;
      (*a7)(glContext,1,in_r5,in_r6,in_r7,programState,a6,a7);
      *(undefined1 *)(glContext + 0x2435) = 1;
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
  int entryCOffset;
  undefined8 *valueD;
  int symbolList;
  int entryD;
  char topSlot;
  int allocY;
  int entryC;
  uint oldWord1b90;
  uint freeWidth;
  undefined4 *hwProgramSlot;
  uint constEndField;
  int *constIndexEnd;
  uint constStartField;
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
loopCheckRegionHeight:
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
              entryCOffset = *(int *)(entryC + 4) * 0x10;
              entryD = *(int *)(entryD + 4) * 0x10;
              *(undefined8 *)(constantBlock + entryA) = *valueA;
              *(undefined8 *)(constantBlock + entryA + 8) = valueAHigh;
              *(undefined8 *)(constantBlock + in_r8) = valueBLow;
              *(undefined8 *)(constantBlock + in_r8 + 8) = valueBHigh;
              *(undefined8 *)(constantBlock + entryCOffset) = valueCLow;
              *(undefined8 *)(constantBlock + entryCOffset + 8) = valueCHigh;
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
        oldWord1b90 = *(uint *)(glContext + 0x1b90);
        topSlot = '\0';
        constStartField = *(uint *)(programState + 4) & 0x3ff;
        *(uint *)(glContext + 0x1b90) = constStartField | oldWord1b90 & 0xfffffc00;
        constEndField = (*(int *)(programState + 4) + *(int *)(programState + 8)) * 0x400 & 0xffc00;
        *(uint *)(glContext + 0x1b90) = constEndField | constStartField | oldWord1b90 & 0xfff00000;
        *(uint *)(glContext + 0x1b90) =
             (*(uint *)(programState + 0x10) & 0x3ff) << 0x14 | constEndField | constStartField | oldWord1b90 & 0xc0000000;
        *(uint *)(glContext + 0x1b94) =
             *(int *)(programState + 4) + *(int *)(programState + 0xc) & 0x3ffU |
             *(uint *)(glContext + 0x1b94) & 0xfffffc00;
        *(char *)(glContext + 0x1b8f) = (char)*(undefined4 *)(programState + 0x14);
        if (*(int *)(programState + 0x5c) != 0) {
          topSlot = (char)*(int *)(programState + 0x5c) + -1;
        }
        *(char *)(glContext + 0x1b8d) = topSlot;
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
        gldSetVertexPacketLimits(glContext,*(undefined4 *)(programState + 0x2a4),*(undefined4 *)(programState + 0x2a8),
                     *(undefined4 *)(programState + 0x2ac));
        ((int (*)())gldCopyRouteRegisters)(glContext);
        return;
      }
      freeWidth = 0;
      freeHeight = 0;
      allocX = *constAlloc;
      cacheMode = *(int *)(glContext + 0xd8);
      allocY = constAlloc[1] - *(int *)(glContext + 0x2448);
loopCheckCacheMode:
      if (cacheMode == 1) goto setFreeWidth;
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
            ctxTempListPush(glContext,programState);
            regionHeight = *(uint *)(programState + 0x5c);
            goto loopCheckRegionHeight;
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
              ((int (*)())gldFreeListNodes)(glContext);
              cacheMode = *(int *)(glContext + 0xd8);
              allocX = 0;
              allocY = 0;
            }
            goto loopCheckCacheMode;
          }
          cacheMode = 1;
          *(undefined4 *)(glContext + 0xd8) = 1;
setFreeWidth:
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
int extvsValidateProgramState(glContext, arg2)
  int glContext;
  undefined4 arg2;
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
      ((int (*)())gldFreeListNodes)(glContext);
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
              goto storeGlContext;
            }
            break;
          }
        }
        extvsMakeShaderCurrent(glContext,shader);
storeGlContext:
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
    gldSetVertexPacketLimits(glContext,*(undefined4 *)(programState + 0x2a4),*(undefined4 *)(programState + 0x2a8),
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
  undefined4 staleArgR4;
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
  undefined4 variantKeyHeader;
  undefined4 variantKeyWords [8];
  
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
  staleArgR4 = (undefined4)lookupResult;
  if (variant == 0) {
    ffvpUpdateLightModelFlags(glContext,staleArgR4,in_r5,in_r6,in_r7,in_r8);
    paramList = paramListCreate(glContext);
    (**(code **)(((unsigned char *)0x000012b4) + glContext))(glContext);
    in_r5 = ffvpBuildProgram(glContext,1,&variantKeyHeader,variantKeyWords,paramList,in_r8,lightKeyA,in_r10);
    in_r6 = (uint)*(byte *)(glContext + 0x131);
    lookupResult = fpVariantCacheInsert(glContext,glContext + 0x1874,in_r5,in_r6,variantKeyHeader,variantKeyWords[0],paramList,
                         (uint)*(byte *)(glContext + 0x126));
    variant = (int)((ulonglong)lookupResult >> 0x20);
    in_r7 = variantKeyHeader;
    in_r8 = variantKeyWords[0];
    if (*(char *)(glContext + 0x126) != '\0') {
      a6 = *(code **)(((unsigned char *)0x0000133c) + glContext);
      *(uint *)(glContext + 0x8c) = *(uint *)(glContext + 0x8c) | 0x40000000;
      *(uint *)(glContext + 0x38) = *(uint *)(glContext + 0x38) | 0x1020;
      *(undefined1 *)(glContext + 0x29) = 1;
      (*a6)(glContext,(int)lookupResult,in_r5,in_r6,variantKeyHeader,variantKeyWords[0],a6);
      goto LAB_00065500;
    }
  }
  else if (*(char *)(variant + 0x59) != '\0') goto storeGlContext;
  *(int *)(glContext + 0x14c) = variant;
  (**(code **)(((unsigned char *)0x000012c4) + glContext))(glContext,variant);
  if (*(int *)(variant + 0x54) + 0x750 == *(int *)(((unsigned char *)0x0000148c) + glContext)) {
    (**(code **)((int)((unsigned char *)0x000012a0) + glContext))(glContext);
    staleArgR4 = extraout_r4;
  }
  else {
    in_r5 = *(undefined4 *)(variant + 0x3c);
    (**(code **)((int)((unsigned char *)0x00001294) + glContext))(glContext,variant,in_r5);
    staleArgR4 = extraout_r4_00;
  }
  if (*(char *)(*(int *)(variant + 0x54) + 0x752) == '\0') {
    return;
  }
storeGlContext:
  *(uint *)(glContext + 0x38) = *(uint *)(glContext + 0x38) | 0x1020;
  *(uint *)(glContext + 0x8c) = *(uint *)(glContext + 0x8c) | 0x40000000;
  *(undefined1 *)(glContext + 0x126) = 1;
  *(undefined1 *)(glContext + 0x29) = 1;
  (**(code **)(((unsigned char *)0x0000133c) + glContext))(glContext,staleArgR4,in_r5,in_r6,in_r7,in_r8,1);
  (**(code **)(((unsigned char *)0x000012dc) + glContext))(glContext);
  return;
}

/* ffvpInitBuilderOutputSlots @ 0x65610 (152 bytes) */
int ffvpInitBuilderOutputSlots(glContext, builder)
  undefined4 glContext;
  int builder;
{
  _memset(builder + 0x68,0xffffffff,0x3c);
  *(undefined4 *)(builder + 0xa0) = 7;
  *(undefined4 *)(builder + 0x90) = 3;
  *(undefined4 *)(builder + 0x68) = 0;
  *(undefined4 *)(builder + 0x84) = 0;
  *(undefined4 *)(builder + 0x8c) = 2;
  *(undefined4 *)(builder + 0x88) = 1;
  *(undefined4 *)(builder + 0x98) = 5;
  *(undefined4 *)(builder + 0x6c) = 0;
  *(undefined4 *)(builder + 0x74) = 0;
  *(undefined4 *)(builder + 0x7c) = 0;
  *(undefined4 *)(builder + 0x70) = 0;
  *(undefined4 *)(builder + 0x78) = 1;
  *(undefined4 *)(builder + 0x80) = 1;
  *(undefined4 *)(builder + 0x94) = 4;
  *(undefined4 *)(builder + 0x9c) = 6;
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
  byte positionOutReg;
  uint backColorOut;
  int keyCompare;
  int variant;
  undefined4 *builder;
  undefined4 texCoordMode;
  undefined4 texCoordFlag;
  undefined4 in_r7;
  undefined4 in_r8;
  uint in_r9;
  uint ctxFlags;
  uint nextOutputReg2;
  uint outputMask;
  int currentVariant;
  uint pointSizeOut;
  undefined4 variantKeyWord;
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
  if ((currentVariant == 0) || (keyCompare = _memcmp(currentVariant,variantKey,0x30), variant = currentVariant, keyCompare != 0)) {
    variant = fpVariantCacheLookup(glContext,variantKey);
    if (variant == 0) {
      outputMask = *(uint *)(glContext + 0x1804);
      positionOutReg = ((unsigned char *)0x000011d2)[glContext];
      positionPassThrough = *(uint *)(glContext + 0x44) >> 10 & 1;
      builder = (undefined4 *)ffvpCreateBuilder(glContext,1,0);
      *builder = 0;
      ((int (*)())ffvpInitBuilderOutputSlots)(glContext,builder);
      if (positionPassThrough == 0) {
        backColorOut = outputMask >> 3 & 1;
        pointSizeOut = outputMask >> 1 & 1;
        nextOutputReg2 = 0;
      }
      else {
        backColorOut = outputMask >> 3 & 1;
        pointSizeOut = outputMask >> 1 & 1;
        in_r9 = (outputMask & 1) + pointSizeOut;
        nextOutputReg2 = (uint)positionOutReg + backColorOut * 2 + in_r9 + 2;
      }
      ffvpEmitPositionPassThrough(builder,positionPassThrough,(uint)positionOutReg);
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
      texCoordMode = 0;
      texCoordFlag = 0;
      ffvpEmitColorPassThrough(builder,3,0,0);
      if ((outputMask & 1) != 0) {
        builder[4] = nextOutputReg;
        texCoordMode = 1;
        texCoordFlag = 0;
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
        texCoordMode = 3;
        texCoordFlag = 1;
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
          if (nextTexReg == nextOutputReg2) {
            nextTexReg = nextTexReg + 1;
          }
          builder[texUnit + 0x21] = nextTexReg;
          loopIndex = loopIndex + 1;
          nextTexReg = nextTexReg + 1;
          unitCursor = unitCursor + 4;
          ffvpEmitTexCoordPassThrough(builder,texUnit,texCoordMode,texCoordFlag,in_r7,in_r8,in_r9);
        } while (outputMask >> 4 != loopIndex);
      }
      ffvpFinishProgram(builder);
      variant = fpVariantCacheInsert(glContext,variantKey,builder,nextOutputReg,variantKeyWord,0,0,1);
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
void vpFillConstantBank(int glContext,int variant,undefined4 unusedArg3,undefined4 unusedArg4,undefined4 unusedArg5,undefined4 unusedArg6,undefined4 unusedArg7,undefined4 unusedArg8,double fprF1,double fprF2,double fprF3,double fprF4,double fprF5,double fprF6,double fprF7,double fprF8,double fprF9,double fprF10,double fprF11,double fprF12,double fprF13)
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
      ((void (*)())programFillStateConstants)(glContext,variant,unusedArg3,unusedArg4,unusedArg5,unusedArg6,glStateExt,unusedArg8,fprF1,fprF2,
                   fprF3,fprF4,fprF5,fprF6,fprF7,fprF8,in_stack_ffffffa8,
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

/* ffvpUploadVariantConstants @ 0x65c40 (52 bytes) */
int ffvpUploadVariantConstants(glContext, variant, unusedArg3, unusedArg4, unusedArg5, unusedArg6, unusedArg7)
  int glContext;
  int variant;
  undefined4 unusedArg3;
  undefined4 unusedArg4;
  undefined4 unusedArg5;
  undefined4 unusedArg6;
  undefined4 unusedArg7;
{
  if (((*(uint *)(glContext + 0x44) & 0x100000) != 0) && (*(char *)(glContext + 0x124) == '\0')) {
    return;
  }
                    
                    
  (**(code **)((int)((unsigned char *)0x00001298) + glContext))(glContext,*(int *)(variant + 0x54) + 0x750);
  return;
}

/* noop_65c80 @ 0x65c80 (4 bytes) */
int noop_65c80()
{
  return;
}

/* arbEmitIlHeader @ 0x65c90 (328 bytes) */
int arbEmitIlHeader(callbacks, ctx)
  int callbacks;
  int ctx;
{
  undefined4 newBuffer;
  uint tokenIndex;
  uint *tokenCountPtr;
  
  tokenCountPtr = (uint *)(ctx + 0x754);
  if (*(uint *)(ctx + 0x758) <= *(uint *)(ctx + 0x754)) {
    newBuffer = (**(code **)(callbacks + 0xc))(*(uint *)(ctx + 0x758) * 4 + 0x200);
    if (*(int *)(ctx + 0x75c) != 0) {
      _memcpy(newBuffer,*(int *)(ctx + 0x75c),*(int *)(ctx + 0x754) << 2);
      (**(code **)(callbacks + 0x18))(*(undefined4 *)(ctx + 0x75c));
    }
    *(undefined4 *)(ctx + 0x75c) = newBuffer;
    *(int *)(ctx + 0x758) = *(int *)(ctx + 0x758) + 0x80;
  }
  *(undefined4 *)(*tokenCountPtr * 4 + *(int *)(ctx + 0x75c)) = 1;
  tokenIndex = *tokenCountPtr + 1;
  *tokenCountPtr = tokenIndex;
  if (*(uint *)(ctx + 0x758) <= tokenIndex) {
    newBuffer = (**(code **)(callbacks + 0xc))(*(uint *)(ctx + 0x758) * 4 + 0x200);
    if (*(int *)(ctx + 0x75c) != 0) {
      _memcpy(newBuffer,*(int *)(ctx + 0x75c),*tokenCountPtr << 2);
      (**(code **)(callbacks + 0x18))(*(undefined4 *)(ctx + 0x75c));
    }
    *(undefined4 *)(ctx + 0x75c) = newBuffer;
    tokenIndex = *tokenCountPtr;
    *(int *)(ctx + 0x758) = *(int *)(ctx + 0x758) + 0x80;
  }
  *(undefined4 *)(tokenIndex * 4 + *(int *)(ctx + 0x75c)) = 0x200;
  *tokenCountPtr = *tokenCountPtr + 1;
  return;
}

/* arbEmitIlEnd @ 0x65de0 (192 bytes) */
int arbEmitIlEnd(callbacks, ctx)
  int callbacks;
  int ctx;
{
  undefined4 newBuffer;
  int *tokenCountPtr;
  
  tokenCountPtr = (int *)(ctx + 0x754);
  if (*(uint *)(ctx + 0x758) <= *(uint *)(ctx + 0x754)) {
    newBuffer = (**(code **)(callbacks + 0xc))(*(uint *)(ctx + 0x758) * 4 + 0x200);
    if (*(int *)(ctx + 0x75c) != 0) {
      _memcpy(newBuffer,*(int *)(ctx + 0x75c),*(int *)(ctx + 0x754) << 2);
      (**(code **)(callbacks + 0x18))(*(undefined4 *)(ctx + 0x75c));
    }
    *(undefined4 *)(ctx + 0x75c) = newBuffer;
    *(int *)(ctx + 0x758) = *(int *)(ctx + 0x758) + 0x80;
  }
  *(undefined4 *)(*tokenCountPtr * 4 + *(int *)(ctx + 0x75c)) = 0x28;
  *tokenCountPtr = *tokenCountPtr + 1;
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
  int dstMask3;
  int allocator;
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
    dstMask3 = dstMask[3];
    dstMask1 = dstMask[1];
    dstMask2 = dstMask[2];
loopSetDstHeader:
    dstHeader = dstHeader | 0x400000;
    dstMaskWord = (uint)(dstMask3 != 0) * 0x40 |
             (uint)(dstMask2 != 0) * 0x10 | (uint)(dstMask1 != 0) * 4 | (uint)(*dstMask != 0);
  }
  else {
    dstMask1 = dstMask[1];
    if (dstMask1 == 0) {
      dstMask3 = dstMask[3];
      dstMask2 = dstMask[2];
      goto loopSetDstHeader;
    }
    dstMask2 = dstMask[2];
    if (dstMask2 == 0) {
      dstMask3 = dstMask[3];
      goto loopSetDstHeader;
    }
    if (dstMask[3] == 0) {
      dstMask3 = 0;
      goto loopSetDstHeader;
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
      goto setSrc0Header;
    }
    src0Negate2 = src0Negate[2];
    if (src0Negate2 != 0) {
      src0Negate3 = src0Negate[3];
      src0Select3 = src0Select[3];
      src0SelectX = *src0Select;
      tokenIndex = src0Select[1];
      src1Header = src0Select[2];
      goto setSrc0Header;
    }
    src0Negate3 = src0Negate[3];
    if (src0Negate3 != 0) {
      src0Select3 = src0Select[3];
      src0SelectX = *src0Select;
      tokenIndex = src0Select[1];
      src1Header = src0Select[2];
      goto setSrc0Header;
    }
    src0SelectX = *src0Select;
    if (src0SelectX != 0) {
      src0Select3 = src0Select[3];
      tokenIndex = src0Select[1];
      src1Header = src0Select[2];
      goto setSrc0Header;
    }
    tokenIndex = src0Select[1];
    if (tokenIndex != 1) {
      src0Select3 = src0Select[3];
      src1Header = src0Select[2];
      goto setSrc0Header;
    }
    src1Header = src0Select[2];
    if (src1Header != 2) {
      src0Select3 = src0Select[3];
      goto setSrc0Header;
    }
    src0Select3 = src0Select[3];
    if (src0Select3 != 3) goto setSrc0Header;
  }
  else {
    src0Negate3 = src0Negate[3];
    src0Select3 = src0Select[3];
    src0Negate1 = src0Negate[1];
    src0Negate2 = src0Negate[2];
    src0SelectX = *src0Select;
    tokenIndex = src0Select[1];
    src1Header = src0Select[2];
setSrc0Header:
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
                if (src1Select3 == 3) goto setTokenIndex;
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
setTokenIndex:
  tokenIndex = *tokenCount;
  allocator = *(int *)(ctx + ARB_allocator);
  if (*(uint *)(ctx + ARB_tokenCapacity) <= tokenIndex) {
    newStorage = (**(code **)(allocator + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
    if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
      _memcpy(newStorage,*(int *)(ctx + ARB_tokenBuffer),*tokenCount << 2);
      (**(code **)(allocator + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
    }
    *(undefined4 *)(ctx + ARB_tokenBuffer) = newStorage;
    tokenIndex = *tokenCount;
    *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
  }
  *(undefined4 *)(tokenIndex * 4 + *(int *)(ctx + ARB_tokenBuffer)) = 0x23;
  tokenIndex = *tokenCount + 1;
  *tokenCount = tokenIndex;
  allocator = *(int *)(ctx + ARB_allocator);
  if (*(uint *)(ctx + ARB_tokenCapacity) <= tokenIndex) {
    newStorage = (**(code **)(allocator + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
    if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
      _memcpy(newStorage,*(int *)(ctx + ARB_tokenBuffer),*tokenCount << 2);
      (**(code **)(allocator + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
    }
    *(undefined4 *)(ctx + ARB_tokenBuffer) = newStorage;
    tokenIndex = *tokenCount;
    *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
  }
  *(uint *)(tokenIndex * 4 + *(int *)(ctx + ARB_tokenBuffer)) = dstHeader;
  tokenIndex = *tokenCount + 1;
  *tokenCount = tokenIndex;
  if ((dstHeader & 0x400000) != 0) {
    allocator = *(int *)(ctx + ARB_allocator);
    if (*(uint *)(ctx + ARB_tokenCapacity) <= tokenIndex) {
      newStorage = (**(code **)(allocator + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
      if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
        _memcpy(newStorage,*(int *)(ctx + ARB_tokenBuffer),*tokenCount << 2);
        (**(code **)(allocator + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
      }
      *(undefined4 *)(ctx + ARB_tokenBuffer) = newStorage;
      tokenIndex = *tokenCount;
      *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
    }
    *(uint *)(tokenIndex * 4 + *(int *)(ctx + ARB_tokenBuffer)) = dstMaskWord;
    tokenIndex = *tokenCount + 1;
    *tokenCount = tokenIndex;
  }
  allocator = *(int *)(ctx + ARB_allocator);
  if (*(uint *)(ctx + ARB_tokenCapacity) <= tokenIndex) {
    newStorage = (**(code **)(allocator + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
    if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
      _memcpy(newStorage,*(int *)(ctx + ARB_tokenBuffer),*tokenCount << 2);
      (**(code **)(allocator + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
    }
    *(undefined4 *)(ctx + ARB_tokenBuffer) = newStorage;
    tokenIndex = *tokenCount;
    *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
  }
  *(uint *)(tokenIndex * 4 + *(int *)(ctx + ARB_tokenBuffer)) = src0Header;
  dstHeader = *tokenCount + 1;
  *tokenCount = dstHeader;
  if ((src0Header & 0x400000) != 0) {
    allocator = *(int *)(ctx + ARB_allocator);
    if (*(uint *)(ctx + ARB_tokenCapacity) <= dstHeader) {
      newStorage = (**(code **)(allocator + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
      if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
        _memcpy(newStorage,*(int *)(ctx + ARB_tokenBuffer),*tokenCount << 2);
        (**(code **)(allocator + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
      }
      *(undefined4 *)(ctx + ARB_tokenBuffer) = newStorage;
      dstHeader = *tokenCount;
      *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
    }
    *(uint *)(dstHeader * 4 + *(int *)(ctx + ARB_tokenBuffer)) = src0SwizzleWord;
    dstHeader = *tokenCount + 1;
    *tokenCount = dstHeader;
  }
  allocator = *(int *)(ctx + ARB_allocator);
  if (*(uint *)(ctx + ARB_tokenCapacity) <= dstHeader) {
    newStorage = (**(code **)(allocator + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
    if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
      _memcpy(newStorage,*(int *)(ctx + ARB_tokenBuffer),*tokenCount << 2);
      (**(code **)(allocator + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
    }
    *(undefined4 *)(ctx + ARB_tokenBuffer) = newStorage;
    dstHeader = *tokenCount;
    *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
  }
  *(uint *)(dstHeader * 4 + *(int *)(ctx + ARB_tokenBuffer)) = src1Header;
  dstHeader = *tokenCount + 1;
  *tokenCount = dstHeader;
  if ((src1Header & 0x400000) != 0) {
    allocator = *(int *)(ctx + ARB_allocator);
    if (*(uint *)(ctx + ARB_tokenCapacity) <= dstHeader) {
      newStorage = (**(code **)(allocator + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
      if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
        _memcpy(newStorage,*(int *)(ctx + ARB_tokenBuffer),*tokenCount << 2);
        (**(code **)(allocator + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
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
  int dstMask3;
  int allocator;
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
    dstMask3 = dstMask[3];
    dstMask1 = dstMask[1];
    dstMask2 = dstMask[2];
loopSetDstHeader:
    dstHeader = dstHeader | 0x400000;
    dstMaskWord = (uint)(dstMask3 != 0) * 0x40 |
             (uint)(dstMask2 != 0) * 0x10 | (uint)(dstMask1 != 0) * 4 | (uint)(*dstMask != 0);
  }
  else {
    dstMask1 = dstMask[1];
    if (dstMask1 == 0) {
      dstMask3 = dstMask[3];
      dstMask2 = dstMask[2];
      goto loopSetDstHeader;
    }
    dstMask2 = dstMask[2];
    if (dstMask2 == 0) {
      dstMask3 = dstMask[3];
      goto loopSetDstHeader;
    }
    if (dstMask[3] == 0) {
      dstMask3 = 0;
      goto loopSetDstHeader;
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
                if (srcSelect3 == 3) goto setTokenIndex;
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
setTokenIndex:
  tokenIndex = *tokenCount;
  allocator = *(int *)(ctx + ARB_allocator);
  if (*(uint *)(ctx + ARB_tokenCapacity) <= tokenIndex) {
    newStorage = (**(code **)(allocator + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
    if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
      _memcpy(newStorage,*(int *)(ctx + ARB_tokenBuffer),*tokenCount << 2);
      (**(code **)(allocator + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
    }
    *(undefined4 *)(ctx + ARB_tokenBuffer) = newStorage;
    tokenIndex = *tokenCount;
    *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
  }
  *(undefined4 *)(tokenIndex * 4 + *(int *)(ctx + ARB_tokenBuffer)) = 0x47;
  tokenIndex = *tokenCount + 1;
  *tokenCount = tokenIndex;
  allocator = *(int *)(ctx + ARB_allocator);
  if (*(uint *)(ctx + ARB_tokenCapacity) <= tokenIndex) {
    newStorage = (**(code **)(allocator + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
    if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
      _memcpy(newStorage,*(int *)(ctx + ARB_tokenBuffer),*tokenCount << 2);
      (**(code **)(allocator + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
    }
    *(undefined4 *)(ctx + ARB_tokenBuffer) = newStorage;
    tokenIndex = *tokenCount;
    *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
  }
  *(uint *)(tokenIndex * 4 + *(int *)(ctx + ARB_tokenBuffer)) = dstHeader;
  tokenIndex = *tokenCount + 1;
  *tokenCount = tokenIndex;
  if ((dstHeader & 0x400000) != 0) {
    allocator = *(int *)(ctx + ARB_allocator);
    if (*(uint *)(ctx + ARB_tokenCapacity) <= tokenIndex) {
      newStorage = (**(code **)(allocator + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
      if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
        _memcpy(newStorage,*(int *)(ctx + ARB_tokenBuffer),*tokenCount << 2);
        (**(code **)(allocator + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
      }
      *(undefined4 *)(ctx + ARB_tokenBuffer) = newStorage;
      tokenIndex = *tokenCount;
      *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
    }
    *(uint *)(tokenIndex * 4 + *(int *)(ctx + ARB_tokenBuffer)) = dstMaskWord;
    tokenIndex = *tokenCount + 1;
    *tokenCount = tokenIndex;
  }
  allocator = *(int *)(ctx + ARB_allocator);
  if (*(uint *)(ctx + ARB_tokenCapacity) <= tokenIndex) {
    newStorage = (**(code **)(allocator + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
    if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
      _memcpy(newStorage,*(int *)(ctx + ARB_tokenBuffer),*tokenCount << 2);
      (**(code **)(allocator + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
    }
    *(undefined4 *)(ctx + ARB_tokenBuffer) = newStorage;
    tokenIndex = *tokenCount;
    *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
  }
  *(uint *)(tokenIndex * 4 + *(int *)(ctx + ARB_tokenBuffer)) = srcHeader;
  dstHeader = *tokenCount + 1;
  *tokenCount = dstHeader;
  if ((srcHeader & 0x400000) != 0) {
    allocator = *(int *)(ctx + ARB_allocator);
    if (*(uint *)(ctx + ARB_tokenCapacity) <= dstHeader) {
      newStorage = (**(code **)(allocator + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
      if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
        _memcpy(newStorage,*(int *)(ctx + ARB_tokenBuffer),*tokenCount << 2);
        (**(code **)(allocator + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
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
  int dstMask3;
  int allocator;
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
    dstMask3 = dstMask[3];
    dstMask1 = dstMask[1];
    dstMask2 = dstMask[2];
loopSetDstHeader:
    dstHeader = dstHeader | 0x400000;
    dstMaskWord = (uint)(dstMask3 != 0) * 0x40 |
             (uint)(dstMask2 != 0) * 0x10 | (uint)(dstMask1 != 0) * 4 | (uint)(*dstMask != 0);
  }
  else {
    dstMask1 = dstMask[1];
    if (dstMask1 == 0) {
      dstMask3 = dstMask[3];
      dstMask2 = dstMask[2];
      goto loopSetDstHeader;
    }
    dstMask2 = dstMask[2];
    if (dstMask2 == 0) {
      dstMask3 = dstMask[3];
      goto loopSetDstHeader;
    }
    if (dstMask[3] == 0) {
      dstMask3 = 0;
      goto loopSetDstHeader;
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
      goto setSrc0Header;
    }
    src0Negate2 = src0Negate[2];
    if (src0Negate2 != 0) {
      src0Negate3 = src0Negate[3];
      src0Select3 = src0Select[3];
      src0SelectX = *src0Select;
      tokenIndex = src0Select[1];
      src1Header = src0Select[2];
      goto setSrc0Header;
    }
    src0Negate3 = src0Negate[3];
    if (src0Negate3 != 0) {
      src0Select3 = src0Select[3];
      src0SelectX = *src0Select;
      tokenIndex = src0Select[1];
      src1Header = src0Select[2];
      goto setSrc0Header;
    }
    src0SelectX = *src0Select;
    if (src0SelectX != 0) {
      src0Select3 = src0Select[3];
      tokenIndex = src0Select[1];
      src1Header = src0Select[2];
      goto setSrc0Header;
    }
    tokenIndex = src0Select[1];
    if (tokenIndex != 1) {
      src0Select3 = src0Select[3];
      src1Header = src0Select[2];
      goto setSrc0Header;
    }
    src1Header = src0Select[2];
    if (src1Header != 2) {
      src0Select3 = src0Select[3];
      goto setSrc0Header;
    }
    src0Select3 = src0Select[3];
    if (src0Select3 != 3) goto setSrc0Header;
  }
  else {
    src0Negate3 = src0Negate[3];
    src0Select3 = src0Select[3];
    src0Negate1 = src0Negate[1];
    src0Negate2 = src0Negate[2];
    src0SelectX = *src0Select;
    tokenIndex = src0Select[1];
    src1Header = src0Select[2];
setSrc0Header:
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
                if (src1Select3 == 3) goto setTokenIndex;
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
setTokenIndex:
  tokenIndex = *tokenCount;
  allocator = *(int *)(ctx + ARB_allocator);
  if (*(uint *)(ctx + ARB_tokenCapacity) <= tokenIndex) {
    newStorage = (**(code **)(allocator + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
    if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
      _memcpy(newStorage,*(int *)(ctx + ARB_tokenBuffer),*tokenCount << 2);
      (**(code **)(allocator + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
    }
    *(undefined4 *)(ctx + ARB_tokenBuffer) = newStorage;
    tokenIndex = *tokenCount;
    *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
  }
  *(undefined4 *)(tokenIndex * 4 + *(int *)(ctx + ARB_tokenBuffer)) = 0x49;
  tokenIndex = *tokenCount + 1;
  *tokenCount = tokenIndex;
  allocator = *(int *)(ctx + ARB_allocator);
  if (*(uint *)(ctx + ARB_tokenCapacity) <= tokenIndex) {
    newStorage = (**(code **)(allocator + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
    if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
      _memcpy(newStorage,*(int *)(ctx + ARB_tokenBuffer),*tokenCount << 2);
      (**(code **)(allocator + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
    }
    *(undefined4 *)(ctx + ARB_tokenBuffer) = newStorage;
    tokenIndex = *tokenCount;
    *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
  }
  *(uint *)(tokenIndex * 4 + *(int *)(ctx + ARB_tokenBuffer)) = dstHeader;
  tokenIndex = *tokenCount + 1;
  *tokenCount = tokenIndex;
  if ((dstHeader & 0x400000) != 0) {
    allocator = *(int *)(ctx + ARB_allocator);
    if (*(uint *)(ctx + ARB_tokenCapacity) <= tokenIndex) {
      newStorage = (**(code **)(allocator + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
      if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
        _memcpy(newStorage,*(int *)(ctx + ARB_tokenBuffer),*tokenCount << 2);
        (**(code **)(allocator + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
      }
      *(undefined4 *)(ctx + ARB_tokenBuffer) = newStorage;
      tokenIndex = *tokenCount;
      *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
    }
    *(uint *)(tokenIndex * 4 + *(int *)(ctx + ARB_tokenBuffer)) = dstMaskWord;
    tokenIndex = *tokenCount + 1;
    *tokenCount = tokenIndex;
  }
  allocator = *(int *)(ctx + ARB_allocator);
  if (*(uint *)(ctx + ARB_tokenCapacity) <= tokenIndex) {
    newStorage = (**(code **)(allocator + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
    if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
      _memcpy(newStorage,*(int *)(ctx + ARB_tokenBuffer),*tokenCount << 2);
      (**(code **)(allocator + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
    }
    *(undefined4 *)(ctx + ARB_tokenBuffer) = newStorage;
    tokenIndex = *tokenCount;
    *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
  }
  *(uint *)(tokenIndex * 4 + *(int *)(ctx + ARB_tokenBuffer)) = src0Header;
  dstHeader = *tokenCount + 1;
  *tokenCount = dstHeader;
  if ((src0Header & 0x400000) != 0) {
    allocator = *(int *)(ctx + ARB_allocator);
    if (*(uint *)(ctx + ARB_tokenCapacity) <= dstHeader) {
      newStorage = (**(code **)(allocator + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
      if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
        _memcpy(newStorage,*(int *)(ctx + ARB_tokenBuffer),*tokenCount << 2);
        (**(code **)(allocator + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
      }
      *(undefined4 *)(ctx + ARB_tokenBuffer) = newStorage;
      dstHeader = *tokenCount;
      *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
    }
    *(uint *)(dstHeader * 4 + *(int *)(ctx + ARB_tokenBuffer)) = src0SwizzleWord;
    dstHeader = *tokenCount + 1;
    *tokenCount = dstHeader;
  }
  allocator = *(int *)(ctx + ARB_allocator);
  if (*(uint *)(ctx + ARB_tokenCapacity) <= dstHeader) {
    newStorage = (**(code **)(allocator + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
    if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
      _memcpy(newStorage,*(int *)(ctx + ARB_tokenBuffer),*tokenCount << 2);
      (**(code **)(allocator + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
    }
    *(undefined4 *)(ctx + ARB_tokenBuffer) = newStorage;
    dstHeader = *tokenCount;
    *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
  }
  *(uint *)(dstHeader * 4 + *(int *)(ctx + ARB_tokenBuffer)) = src1Header;
  dstHeader = *tokenCount + 1;
  *tokenCount = dstHeader;
  if ((src1Header & 0x400000) != 0) {
    allocator = *(int *)(ctx + ARB_allocator);
    if (*(uint *)(ctx + ARB_tokenCapacity) <= dstHeader) {
      newStorage = (**(code **)(allocator + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
      if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
        _memcpy(newStorage,*(int *)(ctx + ARB_tokenBuffer),*tokenCount << 2);
        (**(code **)(allocator + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
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
  int dstMask3;
  int allocator;
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
    dstMask3 = dstMask[3];
    dstMask1 = dstMask[1];
    dstMask2 = dstMask[2];
loopSetDstHeader:
    dstHeader = dstHeader | 0x400000;
    dstMaskWord = (uint)(dstMask3 != 0) * 0x40 |
             (uint)(dstMask2 != 0) * 0x10 | (uint)(dstMask1 != 0) * 4 | (uint)(*dstMask != 0);
  }
  else {
    dstMask1 = dstMask[1];
    if (dstMask1 == 0) {
      dstMask3 = dstMask[3];
      dstMask2 = dstMask[2];
      goto loopSetDstHeader;
    }
    dstMask2 = dstMask[2];
    if (dstMask2 == 0) {
      dstMask3 = dstMask[3];
      goto loopSetDstHeader;
    }
    if (dstMask[3] == 0) {
      dstMask3 = 0;
      goto loopSetDstHeader;
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
      goto setSrc0Header;
    }
    src0Negate2 = src0Negate[2];
    if (src0Negate2 != 0) {
      src0Negate3 = src0Negate[3];
      src0Select3 = src0Select[3];
      src0SelectX = *src0Select;
      tokenIndex = src0Select[1];
      src1Header = src0Select[2];
      goto setSrc0Header;
    }
    src0Negate3 = src0Negate[3];
    if (src0Negate3 != 0) {
      src0Select3 = src0Select[3];
      src0SelectX = *src0Select;
      tokenIndex = src0Select[1];
      src1Header = src0Select[2];
      goto setSrc0Header;
    }
    src0SelectX = *src0Select;
    if (src0SelectX != 0) {
      src0Select3 = src0Select[3];
      tokenIndex = src0Select[1];
      src1Header = src0Select[2];
      goto setSrc0Header;
    }
    tokenIndex = src0Select[1];
    if (tokenIndex != 1) {
      src0Select3 = src0Select[3];
      src1Header = src0Select[2];
      goto setSrc0Header;
    }
    src1Header = src0Select[2];
    if (src1Header != 2) {
      src0Select3 = src0Select[3];
      goto setSrc0Header;
    }
    src0Select3 = src0Select[3];
    if (src0Select3 != 3) goto setSrc0Header;
  }
  else {
    src0Negate3 = src0Negate[3];
    src0Select3 = src0Select[3];
    src0Negate1 = src0Negate[1];
    src0Negate2 = src0Negate[2];
    src0SelectX = *src0Select;
    tokenIndex = src0Select[1];
    src1Header = src0Select[2];
setSrc0Header:
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
                if (src1Select3 == 3) goto setTokenIndex;
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
setTokenIndex:
  tokenIndex = *tokenCount;
  allocator = *(int *)(ctx + ARB_allocator);
  if (*(uint *)(ctx + ARB_tokenCapacity) <= tokenIndex) {
    newStorage = (**(code **)(allocator + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
    if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
      _memcpy(newStorage,*(int *)(ctx + ARB_tokenBuffer),*tokenCount << 2);
      (**(code **)(allocator + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
    }
    *(undefined4 *)(ctx + ARB_tokenBuffer) = newStorage;
    tokenIndex = *tokenCount;
    *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
  }
  *(undefined4 *)(tokenIndex * 4 + *(int *)(ctx + ARB_tokenBuffer)) = 3;
  tokenIndex = *tokenCount + 1;
  *tokenCount = tokenIndex;
  allocator = *(int *)(ctx + ARB_allocator);
  if (*(uint *)(ctx + ARB_tokenCapacity) <= tokenIndex) {
    newStorage = (**(code **)(allocator + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
    if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
      _memcpy(newStorage,*(int *)(ctx + ARB_tokenBuffer),*tokenCount << 2);
      (**(code **)(allocator + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
    }
    *(undefined4 *)(ctx + ARB_tokenBuffer) = newStorage;
    tokenIndex = *tokenCount;
    *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
  }
  *(uint *)(tokenIndex * 4 + *(int *)(ctx + ARB_tokenBuffer)) = dstHeader;
  tokenIndex = *tokenCount + 1;
  *tokenCount = tokenIndex;
  if ((dstHeader & 0x400000) != 0) {
    allocator = *(int *)(ctx + ARB_allocator);
    if (*(uint *)(ctx + ARB_tokenCapacity) <= tokenIndex) {
      newStorage = (**(code **)(allocator + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
      if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
        _memcpy(newStorage,*(int *)(ctx + ARB_tokenBuffer),*tokenCount << 2);
        (**(code **)(allocator + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
      }
      *(undefined4 *)(ctx + ARB_tokenBuffer) = newStorage;
      tokenIndex = *tokenCount;
      *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
    }
    *(uint *)(tokenIndex * 4 + *(int *)(ctx + ARB_tokenBuffer)) = dstMaskWord;
    tokenIndex = *tokenCount + 1;
    *tokenCount = tokenIndex;
  }
  allocator = *(int *)(ctx + ARB_allocator);
  if (*(uint *)(ctx + ARB_tokenCapacity) <= tokenIndex) {
    newStorage = (**(code **)(allocator + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
    if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
      _memcpy(newStorage,*(int *)(ctx + ARB_tokenBuffer),*tokenCount << 2);
      (**(code **)(allocator + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
    }
    *(undefined4 *)(ctx + ARB_tokenBuffer) = newStorage;
    tokenIndex = *tokenCount;
    *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
  }
  *(uint *)(tokenIndex * 4 + *(int *)(ctx + ARB_tokenBuffer)) = src0Header;
  dstHeader = *tokenCount + 1;
  *tokenCount = dstHeader;
  if ((src0Header & 0x400000) != 0) {
    allocator = *(int *)(ctx + ARB_allocator);
    if (*(uint *)(ctx + ARB_tokenCapacity) <= dstHeader) {
      newStorage = (**(code **)(allocator + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
      if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
        _memcpy(newStorage,*(int *)(ctx + ARB_tokenBuffer),*tokenCount << 2);
        (**(code **)(allocator + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
      }
      *(undefined4 *)(ctx + ARB_tokenBuffer) = newStorage;
      dstHeader = *tokenCount;
      *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
    }
    *(uint *)(dstHeader * 4 + *(int *)(ctx + ARB_tokenBuffer)) = src0SwizzleWord;
    dstHeader = *tokenCount + 1;
    *tokenCount = dstHeader;
  }
  allocator = *(int *)(ctx + ARB_allocator);
  if (*(uint *)(ctx + ARB_tokenCapacity) <= dstHeader) {
    newStorage = (**(code **)(allocator + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
    if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
      _memcpy(newStorage,*(int *)(ctx + ARB_tokenBuffer),*tokenCount << 2);
      (**(code **)(allocator + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
    }
    *(undefined4 *)(ctx + ARB_tokenBuffer) = newStorage;
    dstHeader = *tokenCount;
    *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
  }
  *(uint *)(dstHeader * 4 + *(int *)(ctx + ARB_tokenBuffer)) = src1Header;
  dstHeader = *tokenCount + 1;
  *tokenCount = dstHeader;
  if ((src1Header & 0x400000) != 0) {
    allocator = *(int *)(ctx + ARB_allocator);
    if (*(uint *)(ctx + ARB_tokenCapacity) <= dstHeader) {
      newStorage = (**(code **)(allocator + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
      if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
        _memcpy(newStorage,*(int *)(ctx + ARB_tokenBuffer),*tokenCount << 2);
        (**(code **)(allocator + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
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
loopSetDstToken:
    dstToken = dstToken | 0x400000;
    dstMaskWord = (uint)(dstMaskW != 0) * 0x40 |
             (uint)(dstMaskZ != 0) * 0x10 | (uint)(dstMaskY != 0) * 4 | (uint)(*dstMask != 0);
  }
  else {
    dstMaskY = dstMask[1];
    if (dstMaskY == 0) {
      dstMaskW = dstMask[3];
      dstMaskZ = dstMask[2];
      goto loopSetDstToken;
    }
    dstMaskZ = dstMask[2];
    if (dstMaskZ == 0) {
      dstMaskW = dstMask[3];
      goto loopSetDstToken;
    }
    if (dstMask[3] == 0) {
      dstMaskW = 0;
      goto loopSetDstToken;
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
      goto setSrc0Token;
    }
    src0NegateZ = src0Negate[2];
    if (src0NegateZ != 0) {
      src0NegateW = src0Negate[3];
      src0SelectW = src0Select[3];
      src0SelectX = *src0Select;
      src0SelectY = src0Select[1];
      src0SelectZ = src0Select[2];
      goto setSrc0Token;
    }
    src0NegateW = src0Negate[3];
    if (src0NegateW != 0) {
      src0SelectW = src0Select[3];
      src0SelectX = *src0Select;
      src0SelectY = src0Select[1];
      src0SelectZ = src0Select[2];
      goto setSrc0Token;
    }
    src0SelectX = *src0Select;
    if (src0SelectX != 0) {
      src0SelectW = src0Select[3];
      src0SelectY = src0Select[1];
      src0SelectZ = src0Select[2];
      goto setSrc0Token;
    }
    src0SelectY = src0Select[1];
    if (src0SelectY != 1) {
      src0SelectW = src0Select[3];
      src0SelectZ = src0Select[2];
      goto setSrc0Token;
    }
    src0SelectZ = src0Select[2];
    if (src0SelectZ != 2) {
      src0SelectW = src0Select[3];
      goto setSrc0Token;
    }
    src0SelectW = src0Select[3];
    if (src0SelectW != 3) goto setSrc0Token;
  }
  else {
    src0NegateW = src0Negate[3];
    src0SelectW = src0Select[3];
    src0NegateY = src0Negate[1];
    src0NegateZ = src0Negate[2];
    src0SelectX = *src0Select;
    src0SelectY = src0Select[1];
    src0SelectZ = src0Select[2];
setSrc0Token:
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
      goto setSrc1Token;
    }
    src1NegateZ = src1Negate[2];
    if (src1NegateZ != 0) {
      src1NegateW = src1Negate[3];
      src1SelectW = src1Select[3];
      src1SelectX = *src1Select;
      src1SelectY = src1Select[1];
      src1SelectZ = src1Select[2];
      goto setSrc1Token;
    }
    src1NegateW = src1Negate[3];
    if (src1NegateW != 0) {
      src1SelectW = src1Select[3];
      src1SelectX = *src1Select;
      src1SelectY = src1Select[1];
      src1SelectZ = src1Select[2];
      goto setSrc1Token;
    }
    src1SelectX = *src1Select;
    if (src1SelectX != 0) {
      src1SelectW = src1Select[3];
      src1SelectY = src1Select[1];
      src1SelectZ = src1Select[2];
      goto setSrc1Token;
    }
    src1SelectY = src1Select[1];
    if (src1SelectY != 1) {
      src1SelectW = src1Select[3];
      src1SelectZ = src1Select[2];
      goto setSrc1Token;
    }
    src1SelectZ = src1Select[2];
    if (src1SelectZ != 2) {
      src1SelectW = src1Select[3];
      goto setSrc1Token;
    }
    src1SelectW = src1Select[3];
    if (src1SelectW != 3) goto setSrc1Token;
  }
  else {
    src1NegateW = src1Negate[3];
    src1SelectW = src1Select[3];
    src1NegateY = src1Negate[1];
    src1NegateZ = src1Negate[2];
    src1SelectX = *src1Select;
    src1SelectY = src1Select[1];
    src1SelectZ = src1Select[2];
setSrc1Token:
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
                if (src2SelectW == 3) goto setInstrCountPtrValue;
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
setInstrCountPtrValue:
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
  uint dstToken;
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
  uint tokenCount;
  uint tempRegIndex;
  uint src0WordsValue;
  uint src1WordsValue;
  uint src2WordsValue;
  uint dstMaskToken;
  uint src1SwizzleToken;
  uint src2SwizzleToken;
  uint src0SwizzleToken;
  uint src0Token;
  int allocator;
  uint *instrCountPtr;
  uint uStack0000001c;
  uint uStack00000020;
  undefined1 tempOperandHeader [4];
  uint tempOperandRegister;
  uint opcodeToken;
  
  instrCountPtr = (uint *)(ctx + ARB_tokenCount);
  src2SwizzleToken = 0;
  src1SwizzleToken = 0;
  src0SwizzleToken = 0;
  dstMaskToken = 0;
  uStack0000001c = dstFile;
  uStack00000020 = dstIndex;
  (**(code **)(ctx + 0x748))(ctx,0,tempOperandHeader,dstMask,src0File,src0Index,src0Words,src0Flags);
  tempRegIndex = tempOperandRegister & 0xffff;
  opcodeToken = 3;
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
  *(uint *)(*instrCountPtr * 4 + *(int *)(ctx + ARB_tokenBuffer)) = opcodeToken;
  tokenCount = *instrCountPtr + 1;
  *instrCountPtr = tokenCount;
  allocator = *(int *)(ctx + ARB_allocator);
  if (*(uint *)(ctx + ARB_tokenCapacity) <= tokenCount) {
    newBuffer = (**(code **)(allocator + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
    if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
      _memcpy(newBuffer,*(int *)(ctx + ARB_tokenBuffer),*instrCountPtr << 2);
      (**(code **)(allocator + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
    }
    *(undefined4 *)(ctx + ARB_tokenBuffer) = newBuffer;
    tokenCount = *instrCountPtr;
    *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
  }
  *(uint *)(tokenCount * 4 + *(int *)(ctx + ARB_tokenBuffer)) = tempRegIndex | 0x40000;
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
  opcodeToken = opcodeToken & 0xffff0000 | 0x40;
  dstToken = (uStack0000001c & 0x3f) << 0x10 | uStack00000020 & 0xffff;
  if ((uStack0000001c == 0x12) || (uStack0000001c == 0x13)) {
    dstToken = dstToken | 0x400000;
    dstMaskToken = 0x55;
  }
  if (*dstMask == 0) {
    dstMaskW = dstMask[3];
    dstMaskY = dstMask[1];
    dstMaskZ = dstMask[2];
loopSetDstToken:
    dstToken = dstToken | 0x400000;
    dstMaskToken = (uint)(dstMaskW != 0) * 0x40 |
             (uint)(dstMaskZ != 0) * 0x10 | (uint)(dstMaskY != 0) * 4 | (uint)(*dstMask != 0);
  }
  else {
    dstMaskY = dstMask[1];
    if (dstMaskY == 0) {
      dstMaskW = dstMask[3];
      dstMaskZ = dstMask[2];
      goto loopSetDstToken;
    }
    dstMaskZ = dstMask[2];
    if (dstMaskZ == 0) {
      dstMaskW = dstMask[3];
      goto loopSetDstToken;
    }
    if (dstMask[3] == 0) {
      dstMaskW = 0;
      goto loopSetDstToken;
    }
  }
  src0Token = (src0File & 0x3f) << 0x10 | tempOperandRegister & 0xffff;
  if (*src0Flags == 0) {
    src0Flags1 = src0Flags[1];
    if (src0Flags1 != 0) {
      src0Flags3 = src0Flags[3];
      src0Words3 = src0Words[3];
      src0Flags2 = src0Flags[2];
      src0WordsValue = *src0Words;
      src0Words1 = src0Words[1];
      src0Words2 = src0Words[2];
      goto setSrc0Token;
    }
    src0Flags2 = src0Flags[2];
    if (src0Flags2 != 0) {
      src0Flags3 = src0Flags[3];
      src0Words3 = src0Words[3];
      src0WordsValue = *src0Words;
      src0Words1 = src0Words[1];
      src0Words2 = src0Words[2];
      goto setSrc0Token;
    }
    src0Flags3 = src0Flags[3];
    if (src0Flags3 != 0) {
      src0Words3 = src0Words[3];
      src0WordsValue = *src0Words;
      src0Words1 = src0Words[1];
      src0Words2 = src0Words[2];
      goto setSrc0Token;
    }
    src0WordsValue = *src0Words;
    if (src0WordsValue != 0) {
      src0Words3 = src0Words[3];
      src0Words1 = src0Words[1];
      src0Words2 = src0Words[2];
      goto setSrc0Token;
    }
    src0Words1 = src0Words[1];
    if (src0Words1 != 1) {
      src0Words3 = src0Words[3];
      src0Words2 = src0Words[2];
      goto setSrc0Token;
    }
    src0Words2 = src0Words[2];
    if (src0Words2 != 2) {
      src0Words3 = src0Words[3];
      goto setSrc0Token;
    }
    src0Words3 = src0Words[3];
    if (src0Words3 != 3) goto setSrc0Token;
  }
  else {
    src0Flags3 = src0Flags[3];
    src0Words3 = src0Words[3];
    src0Flags1 = src0Flags[1];
    src0Flags2 = src0Flags[2];
    src0WordsValue = *src0Words;
    src0Words1 = src0Words[1];
    src0Words2 = src0Words[2];
setSrc0Token:
    src0Token = src0Token | 0x400000;
    src0SwizzleToken = (src0Flags3 & 1) << 0xf |
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
      goto setSrc1Flags2;
    }
    src1Flags2 = src1Flags[2];
    if (src1Flags2 != 0) {
      src1Words3 = src1Words[3];
      src1WordsValue = *src1Words;
      src1Words2 = src1Words[2];
      src1Flags3 = src1Flags[3];
      src1Words1 = src1Words[1];
      goto setSrc1Token;
    }
    src1Flags3 = src1Flags[3];
    if (src1Flags3 != 0) {
      src1Words3 = src1Words[3];
      src1WordsValue = *src1Words;
      src1Words1 = src1Words[1];
      src1Words2 = src1Words[2];
      goto setSrc1Token;
    }
    src1WordsValue = *src1Words;
    if (src1WordsValue != 0) {
      src1Words3 = src1Words[3];
      src1Words1 = src1Words[1];
      src1Words2 = src1Words[2];
      goto setSrc1Token;
    }
    src1Words1 = src1Words[1];
    if (src1Words1 != 1) {
      src1Words3 = src1Words[3];
      src1Words2 = src1Words[2];
      goto setSrc1Token;
    }
    src1Words2 = src1Words[2];
    if (src1Words2 != 2) {
      src1Words3 = src1Words[3];
      goto setSrc1Token;
    }
    src1Words3 = src1Words[3];
    if (src1Words3 != 3) goto setSrc1Token;
  }
  else {
    src1Words3 = src1Words[3];
    src1Flags3 = src1Flags[3];
    src1Flags1 = src1Flags[1];
setSrc1Flags2:
    src1Flags2 = src1Flags[2];
    src1WordsValue = *src1Words;
    src1Words1 = src1Words[1];
    src1Words2 = src1Words[2];
setSrc1Token:
    src1Token = src1Token | 0x400000;
    src1SwizzleToken = (src1Flags3 & 1) << 0xf |
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
      goto setSrc2Flags2;
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
              if (src2Words3 == 3) goto setAllocator;
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
setSrc2Flags2:
    src2Flags2 = src2Flags[2];
    src2WordsValue = *src2Words;
    src2Words1 = src2Words[1];
    src2Words2 = src2Words[2];
  }
  src2Token = src2Token | 0x400000;
  src2SwizzleToken = (src2Flags3 & 1) << 0xf |
           (src2Words3 & 7) << 0xc |
           (src2Flags2 & 1) << 0xb |
           (src2Words2 & 7) << 8 |
           (src2Flags1 & 1) << 7 | (src2Words1 & 7) << 4 | (*src2Flags & 1) << 3 | src2WordsValue & 7;
setAllocator:
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
  *(uint *)(nextTokenIndex * 4 + *(int *)(ctx + ARB_tokenBuffer)) = opcodeToken;
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
    *(uint *)(nextTokenIndex * 4 + *(int *)(ctx + ARB_tokenBuffer)) = dstMaskToken;
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
    *(uint *)(nextTokenIndex * 4 + *(int *)(ctx + ARB_tokenBuffer)) = src0SwizzleToken;
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
    *(uint *)(nextTokenIndex * 4 + *(int *)(ctx + ARB_tokenBuffer)) = src1SwizzleToken;
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
    *(uint *)(nextTokenIndex * 4 + *(int *)(ctx + ARB_tokenBuffer)) = src2SwizzleToken;
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
  uint tempRegToken1;
  uint tempRegToken0;
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
  uint tokenCount;
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
  uint dstMaskToken;
  uint src0Token;
  uint src0SwizzleToken;
  uint src1SwizzleToken;
  uint *instrCountPtr;
  int allocator;
  undefined1 tempOperandHeader [4];
  uint tempOperandRegister;
  
  instrCountPtr = (uint *)(ctx + ARB_tokenCount);
  src0SwizzleToken = 0;
  dstMaskToken = 0;
  src0Token = (src0File & 0x3f) << 0x10 | src0Index & 0xffff;
  src1SwizzleToken = 0;
  (**(code **)(ctx + 0x748))(ctx,0,tempOperandHeader,dstMask,src0File,src0Index,src0Words,src0Flags);
  tempRegIndex = tempOperandRegister & 0xffff;
  if (*src0Flags == 0) {
    src0Flags1 = src0Flags[1];
    if (src0Flags1 != 0) {
      src0Flags3 = src0Flags[3];
      src0Words3 = src0Words[3];
      src0Flags2 = src0Flags[2];
      src0WordsValue = *src0Words;
      src0Words1 = src0Words[1];
      src0Words2 = src0Words[2];
      goto setSrc0Token;
    }
    src0Flags2 = src0Flags[2];
    if (src0Flags2 != 0) {
      src0Flags3 = src0Flags[3];
      src0Words3 = src0Words[3];
      src0WordsValue = *src0Words;
      src0Words1 = src0Words[1];
      src0Words2 = src0Words[2];
      goto setSrc0Token;
    }
    src0Flags3 = src0Flags[3];
    if (src0Flags3 != 0) {
      src0Words3 = src0Words[3];
      src0WordsValue = *src0Words;
      src0Words1 = src0Words[1];
      src0Words2 = src0Words[2];
      goto setSrc0Token;
    }
    src0WordsValue = *src0Words;
    if (src0WordsValue != 0) {
      src0Words3 = src0Words[3];
      src0Words1 = src0Words[1];
      src0Words2 = src0Words[2];
      goto setSrc0Token;
    }
    src0Words1 = src0Words[1];
    if (src0Words1 != 1) {
      src0Words3 = src0Words[3];
      src0Words2 = src0Words[2];
      goto setSrc0Token;
    }
    src0Words2 = src0Words[2];
    if (src0Words2 != 2) {
      src0Words3 = src0Words[3];
      goto setSrc0Token;
    }
    src0Words3 = src0Words[3];
    if (src0Words3 != 3) goto setSrc0Token;
  }
  else {
    src0Flags3 = src0Flags[3];
    src0Words3 = src0Words[3];
    src0Flags1 = src0Flags[1];
    src0Flags2 = src0Flags[2];
    src0WordsValue = *src0Words;
    src0Words1 = src0Words[1];
    src0Words2 = src0Words[2];
setSrc0Token:
    src0Token = src0Token | 0x400000;
    src0SwizzleToken = (src0Flags3 & 1) << 0xf |
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
      goto setSrc1Token;
    }
    src1Flags2 = src1Flags[2];
    if (src1Flags2 != 0) {
      src1Flags3 = src1Flags[3];
      src1Words3 = src1Words[3];
      src1WordsValue = *src1Words;
      src1Words1 = src1Words[1];
      src1Words2 = src1Words[2];
      goto setSrc1Token;
    }
    src1Flags3 = src1Flags[3];
    if (src1Flags3 != 0) {
      src1Words3 = src1Words[3];
      src1WordsValue = *src1Words;
      src1Words1 = src1Words[1];
      src1Words2 = src1Words[2];
      goto setSrc1Token;
    }
    src1WordsValue = *src1Words;
    if (src1WordsValue != 0) {
      src1Words3 = src1Words[3];
      src1Words1 = src1Words[1];
      src1Words2 = src1Words[2];
      goto setSrc1Token;
    }
    src1Words1 = src1Words[1];
    if (src1Words1 != 1) {
      src1Words3 = src1Words[3];
      src1Words2 = src1Words[2];
      goto setSrc1Token;
    }
    src1Words2 = src1Words[2];
    if (src1Words2 != 2) {
      src1Words3 = src1Words[3];
      goto setSrc1Token;
    }
    src1Words3 = src1Words[3];
    if (src1Words3 != 3) goto setSrc1Token;
  }
  else {
    src1Flags3 = src1Flags[3];
    src1Words3 = src1Words[3];
    src1Flags1 = src1Flags[1];
    src1Flags2 = src1Flags[2];
    src1WordsValue = *src1Words;
    src1Words1 = src1Words[1];
    src1Words2 = src1Words[2];
setSrc1Token:
    src1Token = src1Token | 0x400000;
    src1SwizzleToken = (src1Flags3 & 1) << 0xf |
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
  tokenCount = *instrCountPtr + 1;
  *instrCountPtr = tokenCount;
  allocator = *(int *)(ctx + ARB_allocator);
  if (*(uint *)(ctx + ARB_tokenCapacity) <= tokenCount) {
    newBuffer = (**(code **)(allocator + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
    if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
      _memcpy(newBuffer,*(int *)(ctx + ARB_tokenBuffer),*instrCountPtr << 2);
      (**(code **)(allocator + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
    }
    *(undefined4 *)(ctx + ARB_tokenBuffer) = newBuffer;
    tokenCount = *instrCountPtr;
    *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
  }
  *(uint *)(tokenCount * 4 + *(int *)(ctx + ARB_tokenBuffer)) = tempRegIndex | 0x40000;
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
    *(uint *)(nextTokenIndex * 4 + *(int *)(ctx + ARB_tokenBuffer)) = src0SwizzleToken;
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
    *(uint *)(nextTokenIndex * 4 + *(int *)(ctx + ARB_tokenBuffer)) = src1SwizzleToken;
    nextTokenIndex = *instrCountPtr + 1;
    *instrCountPtr = nextTokenIndex;
  }
  src2WordsValue = *src2Words;
  src2FlagsValueA = *src2Flags;
  src2Flags1A = src2Flags[1];
  src2Flags2A = src2Flags[2];
  allocator = *(int *)(ctx + ARB_allocator);
  tempRegToken0 = tempOperandRegister & 0xffff;
  tempRegToken1 = tempOperandRegister & 0xffff;
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
  *(uint *)(nextTokenIndex * 4 + *(int *)(ctx + ARB_tokenBuffer)) = tempRegToken1 | 0x40000;
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
  *(uint *)(nextTokenIndex * 4 + *(int *)(ctx + ARB_tokenBuffer)) = tempRegToken0 | src0Token & 0xfe400000 | 0x440000;
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
    dstMaskToken = 0x55;
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
        if (dstMask[3] != 0) goto setSrc2FlagsValue;
        dstMaskW = 0;
      }
    }
  }
  dstToken = dstToken | 0x400000;
  dstMaskToken = (uint)(dstMaskW != 0) * 0x40 |
           (uint)(dstMaskZ != 0) * 0x10 | (uint)(dstMaskY != 0) * 4 | (uint)(*dstMask != 0);
setSrc2FlagsValue:
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
    *(uint *)(nextTokenIndex * 4 + *(int *)(ctx + ARB_tokenBuffer)) = dstMaskToken;
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
  *(uint *)(nextTokenIndex * 4 + *(int *)(ctx + ARB_tokenBuffer)) = tempOperandRegister & 0xffff | 0x440000;
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
  (**(code **)(ctx + 0x74c))(ctx,tempOperandHeader);
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
  int dstMask3;
  int allocator;
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
    dstMask3 = dstMask[3];
    dstMask1 = dstMask[1];
    dstMask2 = dstMask[2];
loopSetDstHeader:
    dstHeader = dstHeader | 0x400000;
    dstMaskWord = (uint)(dstMask3 != 0) * 0x40 |
             (uint)(dstMask2 != 0) * 0x10 | (uint)(dstMask1 != 0) * 4 | (uint)(*dstMask != 0);
  }
  else {
    dstMask1 = dstMask[1];
    if (dstMask1 == 0) {
      dstMask3 = dstMask[3];
      dstMask2 = dstMask[2];
      goto loopSetDstHeader;
    }
    dstMask2 = dstMask[2];
    if (dstMask2 == 0) {
      dstMask3 = dstMask[3];
      goto loopSetDstHeader;
    }
    if (dstMask[3] == 0) {
      dstMask3 = 0;
      goto loopSetDstHeader;
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
      goto setSrc0Header;
    }
    src0Negate2 = src0Negate[2];
    if (src0Negate2 != 0) {
      src0Negate3 = src0Negate[3];
      src0Select3 = src0Select[3];
      src0SelectX = *src0Select;
      tokenIndex = src0Select[1];
      src1Header = src0Select[2];
      goto setSrc0Header;
    }
    src0Negate3 = src0Negate[3];
    if (src0Negate3 != 0) {
      src0Select3 = src0Select[3];
      src0SelectX = *src0Select;
      tokenIndex = src0Select[1];
      src1Header = src0Select[2];
      goto setSrc0Header;
    }
    src0SelectX = *src0Select;
    if (src0SelectX != 0) {
      src0Select3 = src0Select[3];
      tokenIndex = src0Select[1];
      src1Header = src0Select[2];
      goto setSrc0Header;
    }
    tokenIndex = src0Select[1];
    if (tokenIndex != 1) {
      src0Select3 = src0Select[3];
      src1Header = src0Select[2];
      goto setSrc0Header;
    }
    src1Header = src0Select[2];
    if (src1Header != 2) {
      src0Select3 = src0Select[3];
      goto setSrc0Header;
    }
    src0Select3 = src0Select[3];
    if (src0Select3 != 3) goto setSrc0Header;
  }
  else {
    src0Negate3 = src0Negate[3];
    src0Select3 = src0Select[3];
    src0Negate1 = src0Negate[1];
    src0Negate2 = src0Negate[2];
    src0SelectX = *src0Select;
    tokenIndex = src0Select[1];
    src1Header = src0Select[2];
setSrc0Header:
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
                if (src1Select3 == 3) goto setTokenIndex;
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
setTokenIndex:
  tokenIndex = *tokenCount;
  allocator = *(int *)(ctx + ARB_allocator);
  if (*(uint *)(ctx + ARB_tokenCapacity) <= tokenIndex) {
    newStorage = (**(code **)(allocator + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
    if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
      _memcpy(newStorage,*(int *)(ctx + ARB_tokenBuffer),*tokenCount << 2);
      (**(code **)(allocator + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
    }
    *(undefined4 *)(ctx + ARB_tokenBuffer) = newStorage;
    tokenIndex = *tokenCount;
    *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
  }
  *(undefined4 *)(tokenIndex * 4 + *(int *)(ctx + ARB_tokenBuffer)) = 0x44;
  tokenIndex = *tokenCount + 1;
  *tokenCount = tokenIndex;
  allocator = *(int *)(ctx + ARB_allocator);
  if (*(uint *)(ctx + ARB_tokenCapacity) <= tokenIndex) {
    newStorage = (**(code **)(allocator + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
    if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
      _memcpy(newStorage,*(int *)(ctx + ARB_tokenBuffer),*tokenCount << 2);
      (**(code **)(allocator + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
    }
    *(undefined4 *)(ctx + ARB_tokenBuffer) = newStorage;
    tokenIndex = *tokenCount;
    *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
  }
  *(uint *)(tokenIndex * 4 + *(int *)(ctx + ARB_tokenBuffer)) = dstHeader;
  tokenIndex = *tokenCount + 1;
  *tokenCount = tokenIndex;
  if ((dstHeader & 0x400000) != 0) {
    allocator = *(int *)(ctx + ARB_allocator);
    if (*(uint *)(ctx + ARB_tokenCapacity) <= tokenIndex) {
      newStorage = (**(code **)(allocator + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
      if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
        _memcpy(newStorage,*(int *)(ctx + ARB_tokenBuffer),*tokenCount << 2);
        (**(code **)(allocator + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
      }
      *(undefined4 *)(ctx + ARB_tokenBuffer) = newStorage;
      tokenIndex = *tokenCount;
      *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
    }
    *(uint *)(tokenIndex * 4 + *(int *)(ctx + ARB_tokenBuffer)) = dstMaskWord;
    tokenIndex = *tokenCount + 1;
    *tokenCount = tokenIndex;
  }
  allocator = *(int *)(ctx + ARB_allocator);
  if (*(uint *)(ctx + ARB_tokenCapacity) <= tokenIndex) {
    newStorage = (**(code **)(allocator + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
    if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
      _memcpy(newStorage,*(int *)(ctx + ARB_tokenBuffer),*tokenCount << 2);
      (**(code **)(allocator + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
    }
    *(undefined4 *)(ctx + ARB_tokenBuffer) = newStorage;
    tokenIndex = *tokenCount;
    *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
  }
  *(uint *)(tokenIndex * 4 + *(int *)(ctx + ARB_tokenBuffer)) = src0Header;
  dstHeader = *tokenCount + 1;
  *tokenCount = dstHeader;
  if ((src0Header & 0x400000) != 0) {
    allocator = *(int *)(ctx + ARB_allocator);
    if (*(uint *)(ctx + ARB_tokenCapacity) <= dstHeader) {
      newStorage = (**(code **)(allocator + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
      if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
        _memcpy(newStorage,*(int *)(ctx + ARB_tokenBuffer),*tokenCount << 2);
        (**(code **)(allocator + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
      }
      *(undefined4 *)(ctx + ARB_tokenBuffer) = newStorage;
      dstHeader = *tokenCount;
      *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
    }
    *(uint *)(dstHeader * 4 + *(int *)(ctx + ARB_tokenBuffer)) = src0SwizzleWord;
    dstHeader = *tokenCount + 1;
    *tokenCount = dstHeader;
  }
  allocator = *(int *)(ctx + ARB_allocator);
  if (*(uint *)(ctx + ARB_tokenCapacity) <= dstHeader) {
    newStorage = (**(code **)(allocator + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
    if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
      _memcpy(newStorage,*(int *)(ctx + ARB_tokenBuffer),*tokenCount << 2);
      (**(code **)(allocator + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
    }
    *(undefined4 *)(ctx + ARB_tokenBuffer) = newStorage;
    dstHeader = *tokenCount;
    *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
  }
  *(uint *)(dstHeader * 4 + *(int *)(ctx + ARB_tokenBuffer)) = src1Header;
  dstHeader = *tokenCount + 1;
  *tokenCount = dstHeader;
  if ((src1Header & 0x400000) != 0) {
    allocator = *(int *)(ctx + ARB_allocator);
    if (*(uint *)(ctx + ARB_tokenCapacity) <= dstHeader) {
      newStorage = (**(code **)(allocator + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
      if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
        _memcpy(newStorage,*(int *)(ctx + ARB_tokenBuffer),*tokenCount << 2);
        (**(code **)(allocator + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
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
  int dstMask3;
  int allocator;
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
    dstMask3 = dstMask[3];
    dstMask1 = dstMask[1];
    dstMask2 = dstMask[2];
loopSetDstHeader:
    dstHeader = dstHeader | 0x400000;
    dstMaskWord = (uint)(dstMask3 != 0) * 0x40 |
             (uint)(dstMask2 != 0) * 0x10 | (uint)(dstMask1 != 0) * 4 | (uint)(*dstMask != 0);
  }
  else {
    dstMask1 = dstMask[1];
    if (dstMask1 == 0) {
      dstMask3 = dstMask[3];
      dstMask2 = dstMask[2];
      goto loopSetDstHeader;
    }
    dstMask2 = dstMask[2];
    if (dstMask2 == 0) {
      dstMask3 = dstMask[3];
      goto loopSetDstHeader;
    }
    if (dstMask[3] == 0) {
      dstMask3 = 0;
      goto loopSetDstHeader;
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
      goto setSrc0Header;
    }
    src0Negate2 = src0Negate[2];
    if (src0Negate2 != 0) {
      src0Negate3 = src0Negate[3];
      src0Select3 = src0Select[3];
      src0SelectX = *src0Select;
      tokenIndex = src0Select[1];
      src1Header = src0Select[2];
      goto setSrc0Header;
    }
    src0Negate3 = src0Negate[3];
    if (src0Negate3 != 0) {
      src0Select3 = src0Select[3];
      src0SelectX = *src0Select;
      tokenIndex = src0Select[1];
      src1Header = src0Select[2];
      goto setSrc0Header;
    }
    src0SelectX = *src0Select;
    if (src0SelectX != 0) {
      src0Select3 = src0Select[3];
      tokenIndex = src0Select[1];
      src1Header = src0Select[2];
      goto setSrc0Header;
    }
    tokenIndex = src0Select[1];
    if (tokenIndex != 1) {
      src0Select3 = src0Select[3];
      src1Header = src0Select[2];
      goto setSrc0Header;
    }
    src1Header = src0Select[2];
    if (src1Header != 2) {
      src0Select3 = src0Select[3];
      goto setSrc0Header;
    }
    src0Select3 = src0Select[3];
    if (src0Select3 != 3) goto setSrc0Header;
  }
  else {
    src0Negate3 = src0Negate[3];
    src0Select3 = src0Select[3];
    src0Negate1 = src0Negate[1];
    src0Negate2 = src0Negate[2];
    src0SelectX = *src0Select;
    tokenIndex = src0Select[1];
    src1Header = src0Select[2];
setSrc0Header:
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
                if (src1Select3 == 3) goto setTokenIndex;
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
setTokenIndex:
  tokenIndex = *tokenCount;
  allocator = *(int *)(ctx + ARB_allocator);
  if (*(uint *)(ctx + ARB_tokenCapacity) <= tokenIndex) {
    newStorage = (**(code **)(allocator + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
    if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
      _memcpy(newStorage,*(int *)(ctx + ARB_tokenBuffer),*tokenCount << 2);
      (**(code **)(allocator + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
    }
    *(undefined4 *)(ctx + ARB_tokenBuffer) = newStorage;
    tokenIndex = *tokenCount;
    *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
  }
  *(undefined4 *)(tokenIndex * 4 + *(int *)(ctx + ARB_tokenBuffer)) = 0x41;
  tokenIndex = *tokenCount + 1;
  *tokenCount = tokenIndex;
  allocator = *(int *)(ctx + ARB_allocator);
  if (*(uint *)(ctx + ARB_tokenCapacity) <= tokenIndex) {
    newStorage = (**(code **)(allocator + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
    if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
      _memcpy(newStorage,*(int *)(ctx + ARB_tokenBuffer),*tokenCount << 2);
      (**(code **)(allocator + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
    }
    *(undefined4 *)(ctx + ARB_tokenBuffer) = newStorage;
    tokenIndex = *tokenCount;
    *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
  }
  *(uint *)(tokenIndex * 4 + *(int *)(ctx + ARB_tokenBuffer)) = dstHeader;
  tokenIndex = *tokenCount + 1;
  *tokenCount = tokenIndex;
  if ((dstHeader & 0x400000) != 0) {
    allocator = *(int *)(ctx + ARB_allocator);
    if (*(uint *)(ctx + ARB_tokenCapacity) <= tokenIndex) {
      newStorage = (**(code **)(allocator + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
      if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
        _memcpy(newStorage,*(int *)(ctx + ARB_tokenBuffer),*tokenCount << 2);
        (**(code **)(allocator + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
      }
      *(undefined4 *)(ctx + ARB_tokenBuffer) = newStorage;
      tokenIndex = *tokenCount;
      *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
    }
    *(uint *)(tokenIndex * 4 + *(int *)(ctx + ARB_tokenBuffer)) = dstMaskWord;
    tokenIndex = *tokenCount + 1;
    *tokenCount = tokenIndex;
  }
  allocator = *(int *)(ctx + ARB_allocator);
  if (*(uint *)(ctx + ARB_tokenCapacity) <= tokenIndex) {
    newStorage = (**(code **)(allocator + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
    if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
      _memcpy(newStorage,*(int *)(ctx + ARB_tokenBuffer),*tokenCount << 2);
      (**(code **)(allocator + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
    }
    *(undefined4 *)(ctx + ARB_tokenBuffer) = newStorage;
    tokenIndex = *tokenCount;
    *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
  }
  *(uint *)(tokenIndex * 4 + *(int *)(ctx + ARB_tokenBuffer)) = src0Header;
  dstHeader = *tokenCount + 1;
  *tokenCount = dstHeader;
  if ((src0Header & 0x400000) != 0) {
    allocator = *(int *)(ctx + ARB_allocator);
    if (*(uint *)(ctx + ARB_tokenCapacity) <= dstHeader) {
      newStorage = (**(code **)(allocator + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
      if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
        _memcpy(newStorage,*(int *)(ctx + ARB_tokenBuffer),*tokenCount << 2);
        (**(code **)(allocator + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
      }
      *(undefined4 *)(ctx + ARB_tokenBuffer) = newStorage;
      dstHeader = *tokenCount;
      *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
    }
    *(uint *)(dstHeader * 4 + *(int *)(ctx + ARB_tokenBuffer)) = src0SwizzleWord;
    dstHeader = *tokenCount + 1;
    *tokenCount = dstHeader;
  }
  allocator = *(int *)(ctx + ARB_allocator);
  if (*(uint *)(ctx + ARB_tokenCapacity) <= dstHeader) {
    newStorage = (**(code **)(allocator + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
    if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
      _memcpy(newStorage,*(int *)(ctx + ARB_tokenBuffer),*tokenCount << 2);
      (**(code **)(allocator + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
    }
    *(undefined4 *)(ctx + ARB_tokenBuffer) = newStorage;
    dstHeader = *tokenCount;
    *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
  }
  *(uint *)(dstHeader * 4 + *(int *)(ctx + ARB_tokenBuffer)) = src1Header;
  dstHeader = *tokenCount + 1;
  *tokenCount = dstHeader;
  if ((src1Header & 0x400000) != 0) {
    allocator = *(int *)(ctx + ARB_allocator);
    if (*(uint *)(ctx + ARB_tokenCapacity) <= dstHeader) {
      newStorage = (**(code **)(allocator + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
      if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
        _memcpy(newStorage,*(int *)(ctx + ARB_tokenBuffer),*tokenCount << 2);
        (**(code **)(allocator + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
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
  int dstMask3;
  int allocator;
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
    dstMask3 = dstMask[3];
    dstMask1 = dstMask[1];
    dstMask2 = dstMask[2];
loopSetDstHeader:
    dstHeader = dstHeader | 0x400000;
    dstMaskWord = (uint)(dstMask3 != 0) * 0x40 |
             (uint)(dstMask2 != 0) * 0x10 | (uint)(dstMask1 != 0) * 4 | (uint)(*dstMask != 0);
  }
  else {
    dstMask1 = dstMask[1];
    if (dstMask1 == 0) {
      dstMask3 = dstMask[3];
      dstMask2 = dstMask[2];
      goto loopSetDstHeader;
    }
    dstMask2 = dstMask[2];
    if (dstMask2 == 0) {
      dstMask3 = dstMask[3];
      goto loopSetDstHeader;
    }
    if (dstMask[3] == 0) {
      dstMask3 = 0;
      goto loopSetDstHeader;
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
      goto setSrc0Header;
    }
    src0Negate2 = src0Negate[2];
    if (src0Negate2 != 0) {
      src0Negate3 = src0Negate[3];
      src0Select3 = src0Select[3];
      src0SelectX = *src0Select;
      tokenIndex = src0Select[1];
      src1Header = src0Select[2];
      goto setSrc0Header;
    }
    src0Negate3 = src0Negate[3];
    if (src0Negate3 != 0) {
      src0Select3 = src0Select[3];
      src0SelectX = *src0Select;
      tokenIndex = src0Select[1];
      src1Header = src0Select[2];
      goto setSrc0Header;
    }
    src0SelectX = *src0Select;
    if (src0SelectX != 0) {
      src0Select3 = src0Select[3];
      tokenIndex = src0Select[1];
      src1Header = src0Select[2];
      goto setSrc0Header;
    }
    tokenIndex = src0Select[1];
    if (tokenIndex != 1) {
      src0Select3 = src0Select[3];
      src1Header = src0Select[2];
      goto setSrc0Header;
    }
    src1Header = src0Select[2];
    if (src1Header != 2) {
      src0Select3 = src0Select[3];
      goto setSrc0Header;
    }
    src0Select3 = src0Select[3];
    if (src0Select3 != 3) goto setSrc0Header;
  }
  else {
    src0Negate3 = src0Negate[3];
    src0Select3 = src0Select[3];
    src0Negate1 = src0Negate[1];
    src0Negate2 = src0Negate[2];
    src0SelectX = *src0Select;
    tokenIndex = src0Select[1];
    src1Header = src0Select[2];
setSrc0Header:
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
                if (src1Select3 == 3) goto setTokenIndex;
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
setTokenIndex:
  tokenIndex = *tokenCount;
  allocator = *(int *)(ctx + ARB_allocator);
  if (*(uint *)(ctx + ARB_tokenCapacity) <= tokenIndex) {
    newStorage = (**(code **)(allocator + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
    if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
      _memcpy(newStorage,*(int *)(ctx + ARB_tokenBuffer),*tokenCount << 2);
      (**(code **)(allocator + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
    }
    *(undefined4 *)(ctx + ARB_tokenBuffer) = newStorage;
    tokenIndex = *tokenCount;
    *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
  }
  *(undefined4 *)(tokenIndex * 4 + *(int *)(ctx + ARB_tokenBuffer)) = 0x50056;
  tokenIndex = *tokenCount + 1;
  *tokenCount = tokenIndex;
  allocator = *(int *)(ctx + ARB_allocator);
  if (*(uint *)(ctx + ARB_tokenCapacity) <= tokenIndex) {
    newStorage = (**(code **)(allocator + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
    if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
      _memcpy(newStorage,*(int *)(ctx + ARB_tokenBuffer),*tokenCount << 2);
      (**(code **)(allocator + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
    }
    *(undefined4 *)(ctx + ARB_tokenBuffer) = newStorage;
    tokenIndex = *tokenCount;
    *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
  }
  *(uint *)(tokenIndex * 4 + *(int *)(ctx + ARB_tokenBuffer)) = dstHeader;
  tokenIndex = *tokenCount + 1;
  *tokenCount = tokenIndex;
  if ((dstHeader & 0x400000) != 0) {
    allocator = *(int *)(ctx + ARB_allocator);
    if (*(uint *)(ctx + ARB_tokenCapacity) <= tokenIndex) {
      newStorage = (**(code **)(allocator + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
      if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
        _memcpy(newStorage,*(int *)(ctx + ARB_tokenBuffer),*tokenCount << 2);
        (**(code **)(allocator + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
      }
      *(undefined4 *)(ctx + ARB_tokenBuffer) = newStorage;
      tokenIndex = *tokenCount;
      *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
    }
    *(uint *)(tokenIndex * 4 + *(int *)(ctx + ARB_tokenBuffer)) = dstMaskWord;
    tokenIndex = *tokenCount + 1;
    *tokenCount = tokenIndex;
  }
  allocator = *(int *)(ctx + ARB_allocator);
  if (*(uint *)(ctx + ARB_tokenCapacity) <= tokenIndex) {
    newStorage = (**(code **)(allocator + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
    if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
      _memcpy(newStorage,*(int *)(ctx + ARB_tokenBuffer),*tokenCount << 2);
      (**(code **)(allocator + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
    }
    *(undefined4 *)(ctx + ARB_tokenBuffer) = newStorage;
    tokenIndex = *tokenCount;
    *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
  }
  *(uint *)(tokenIndex * 4 + *(int *)(ctx + ARB_tokenBuffer)) = src0Header;
  dstHeader = *tokenCount + 1;
  *tokenCount = dstHeader;
  if ((src0Header & 0x400000) != 0) {
    allocator = *(int *)(ctx + ARB_allocator);
    if (*(uint *)(ctx + ARB_tokenCapacity) <= dstHeader) {
      newStorage = (**(code **)(allocator + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
      if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
        _memcpy(newStorage,*(int *)(ctx + ARB_tokenBuffer),*tokenCount << 2);
        (**(code **)(allocator + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
      }
      *(undefined4 *)(ctx + ARB_tokenBuffer) = newStorage;
      dstHeader = *tokenCount;
      *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
    }
    *(uint *)(dstHeader * 4 + *(int *)(ctx + ARB_tokenBuffer)) = src0SwizzleWord;
    dstHeader = *tokenCount + 1;
    *tokenCount = dstHeader;
  }
  allocator = *(int *)(ctx + ARB_allocator);
  if (*(uint *)(ctx + ARB_tokenCapacity) <= dstHeader) {
    newStorage = (**(code **)(allocator + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
    if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
      _memcpy(newStorage,*(int *)(ctx + ARB_tokenBuffer),*tokenCount << 2);
      (**(code **)(allocator + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
    }
    *(undefined4 *)(ctx + ARB_tokenBuffer) = newStorage;
    dstHeader = *tokenCount;
    *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
  }
  *(uint *)(dstHeader * 4 + *(int *)(ctx + ARB_tokenBuffer)) = src1Header;
  dstHeader = *tokenCount + 1;
  *tokenCount = dstHeader;
  if ((src1Header & 0x400000) != 0) {
    allocator = *(int *)(ctx + ARB_allocator);
    if (*(uint *)(ctx + ARB_tokenCapacity) <= dstHeader) {
      newStorage = (**(code **)(allocator + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
      if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
        _memcpy(newStorage,*(int *)(ctx + ARB_tokenBuffer),*tokenCount << 2);
        (**(code **)(allocator + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
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
  int dstMask3;
  int allocator;
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
    dstMask3 = dstMask[3];
    dstMask1 = dstMask[1];
    dstMask2 = dstMask[2];
loopSetDstHeader:
    dstHeader = dstHeader | 0x400000;
    dstMaskWord = (uint)(dstMask3 != 0) * 0x40 |
             (uint)(dstMask2 != 0) * 0x10 | (uint)(dstMask1 != 0) * 4 | (uint)(*dstMask != 0);
  }
  else {
    dstMask1 = dstMask[1];
    if (dstMask1 == 0) {
      dstMask3 = dstMask[3];
      dstMask2 = dstMask[2];
      goto loopSetDstHeader;
    }
    dstMask2 = dstMask[2];
    if (dstMask2 == 0) {
      dstMask3 = dstMask[3];
      goto loopSetDstHeader;
    }
    if (dstMask[3] == 0) {
      dstMask3 = 0;
      goto loopSetDstHeader;
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
      goto setSrc0Header;
    }
    src0Negate2 = src0Negate[2];
    if (src0Negate2 != 0) {
      src0Negate3 = src0Negate[3];
      src0Select3 = src0Select[3];
      src0SelectX = *src0Select;
      tokenIndex = src0Select[1];
      src1Header = src0Select[2];
      goto setSrc0Header;
    }
    src0Negate3 = src0Negate[3];
    if (src0Negate3 != 0) {
      src0Select3 = src0Select[3];
      src0SelectX = *src0Select;
      tokenIndex = src0Select[1];
      src1Header = src0Select[2];
      goto setSrc0Header;
    }
    src0SelectX = *src0Select;
    if (src0SelectX != 0) {
      src0Select3 = src0Select[3];
      tokenIndex = src0Select[1];
      src1Header = src0Select[2];
      goto setSrc0Header;
    }
    tokenIndex = src0Select[1];
    if (tokenIndex != 1) {
      src0Select3 = src0Select[3];
      src1Header = src0Select[2];
      goto setSrc0Header;
    }
    src1Header = src0Select[2];
    if (src1Header != 2) {
      src0Select3 = src0Select[3];
      goto setSrc0Header;
    }
    src0Select3 = src0Select[3];
    if (src0Select3 != 3) goto setSrc0Header;
  }
  else {
    src0Negate3 = src0Negate[3];
    src0Select3 = src0Select[3];
    src0Negate1 = src0Negate[1];
    src0Negate2 = src0Negate[2];
    src0SelectX = *src0Select;
    tokenIndex = src0Select[1];
    src1Header = src0Select[2];
setSrc0Header:
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
                if (src1Select3 == 3) goto setTokenIndex;
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
setTokenIndex:
  tokenIndex = *tokenCount;
  allocator = *(int *)(ctx + ARB_allocator);
  if (*(uint *)(ctx + ARB_tokenCapacity) <= tokenIndex) {
    newStorage = (**(code **)(allocator + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
    if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
      _memcpy(newStorage,*(int *)(ctx + ARB_tokenBuffer),*tokenCount << 2);
      (**(code **)(allocator + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
    }
    *(undefined4 *)(ctx + ARB_tokenBuffer) = newStorage;
    tokenIndex = *tokenCount;
    *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
  }
  *(undefined4 *)(tokenIndex * 4 + *(int *)(ctx + ARB_tokenBuffer)) = 0x20056;
  tokenIndex = *tokenCount + 1;
  *tokenCount = tokenIndex;
  allocator = *(int *)(ctx + ARB_allocator);
  if (*(uint *)(ctx + ARB_tokenCapacity) <= tokenIndex) {
    newStorage = (**(code **)(allocator + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
    if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
      _memcpy(newStorage,*(int *)(ctx + ARB_tokenBuffer),*tokenCount << 2);
      (**(code **)(allocator + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
    }
    *(undefined4 *)(ctx + ARB_tokenBuffer) = newStorage;
    tokenIndex = *tokenCount;
    *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
  }
  *(uint *)(tokenIndex * 4 + *(int *)(ctx + ARB_tokenBuffer)) = dstHeader;
  tokenIndex = *tokenCount + 1;
  *tokenCount = tokenIndex;
  if ((dstHeader & 0x400000) != 0) {
    allocator = *(int *)(ctx + ARB_allocator);
    if (*(uint *)(ctx + ARB_tokenCapacity) <= tokenIndex) {
      newStorage = (**(code **)(allocator + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
      if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
        _memcpy(newStorage,*(int *)(ctx + ARB_tokenBuffer),*tokenCount << 2);
        (**(code **)(allocator + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
      }
      *(undefined4 *)(ctx + ARB_tokenBuffer) = newStorage;
      tokenIndex = *tokenCount;
      *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
    }
    *(uint *)(tokenIndex * 4 + *(int *)(ctx + ARB_tokenBuffer)) = dstMaskWord;
    tokenIndex = *tokenCount + 1;
    *tokenCount = tokenIndex;
  }
  allocator = *(int *)(ctx + ARB_allocator);
  if (*(uint *)(ctx + ARB_tokenCapacity) <= tokenIndex) {
    newStorage = (**(code **)(allocator + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
    if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
      _memcpy(newStorage,*(int *)(ctx + ARB_tokenBuffer),*tokenCount << 2);
      (**(code **)(allocator + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
    }
    *(undefined4 *)(ctx + ARB_tokenBuffer) = newStorage;
    tokenIndex = *tokenCount;
    *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
  }
  *(uint *)(tokenIndex * 4 + *(int *)(ctx + ARB_tokenBuffer)) = src0Header;
  dstHeader = *tokenCount + 1;
  *tokenCount = dstHeader;
  if ((src0Header & 0x400000) != 0) {
    allocator = *(int *)(ctx + ARB_allocator);
    if (*(uint *)(ctx + ARB_tokenCapacity) <= dstHeader) {
      newStorage = (**(code **)(allocator + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
      if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
        _memcpy(newStorage,*(int *)(ctx + ARB_tokenBuffer),*tokenCount << 2);
        (**(code **)(allocator + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
      }
      *(undefined4 *)(ctx + ARB_tokenBuffer) = newStorage;
      dstHeader = *tokenCount;
      *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
    }
    *(uint *)(dstHeader * 4 + *(int *)(ctx + ARB_tokenBuffer)) = src0SwizzleWord;
    dstHeader = *tokenCount + 1;
    *tokenCount = dstHeader;
  }
  allocator = *(int *)(ctx + ARB_allocator);
  if (*(uint *)(ctx + ARB_tokenCapacity) <= dstHeader) {
    newStorage = (**(code **)(allocator + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
    if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
      _memcpy(newStorage,*(int *)(ctx + ARB_tokenBuffer),*tokenCount << 2);
      (**(code **)(allocator + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
    }
    *(undefined4 *)(ctx + ARB_tokenBuffer) = newStorage;
    dstHeader = *tokenCount;
    *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
  }
  *(uint *)(dstHeader * 4 + *(int *)(ctx + ARB_tokenBuffer)) = src1Header;
  dstHeader = *tokenCount + 1;
  *tokenCount = dstHeader;
  if ((src1Header & 0x400000) != 0) {
    allocator = *(int *)(ctx + ARB_allocator);
    if (*(uint *)(ctx + ARB_tokenCapacity) <= dstHeader) {
      newStorage = (**(code **)(allocator + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
      if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
        _memcpy(newStorage,*(int *)(ctx + ARB_tokenBuffer),*tokenCount << 2);
        (**(code **)(allocator + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
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
int arbEmitIlRnd(emitter, dstFile, dstIndex, dstMask, src0File, src0Index, src0Select, src0Negate)
  int emitter;
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
  uint tokenCount;
  int dstMaskZ;
  uint src0SelectY;
  undefined4 newTokenArray;
  uint src0NegateW;
  uint src0NegateZ;
  uint src0NegateY;
  int dstMaskY;
  uint src0SelectW;
  uint src0SelectX;
  uint src0Token;
  uint tokenCount2;
  uint dstMaskToken;
  int allocator;
  uint src0SwizzleToken;
  uint *tokenCountPtr;
  
  dstToken = (dstFile & 0x3f) << 0x10 | dstIndex & 0xffff;
  tokenCountPtr = (uint *)(emitter + 0x754);
  src0SwizzleToken = 0;
  dstMaskToken = 0;
  if ((dstFile == 0x12) || (dstFile == 0x13)) {
    dstToken = dstToken | 0x400000;
    dstMaskToken = 0x55;
  }
  if (*dstMask == 0) {
    dstMaskW = dstMask[3];
    dstMaskY = dstMask[1];
    dstMaskZ = dstMask[2];
loopSetDstToken:
    dstToken = dstToken | 0x400000;
    dstMaskToken = (uint)(dstMaskW != 0) * 0x40 |
             (uint)(dstMaskZ != 0) * 0x10 | (uint)(dstMaskY != 0) * 4 | (uint)(*dstMask != 0);
  }
  else {
    dstMaskY = dstMask[1];
    if (dstMaskY == 0) {
      dstMaskW = dstMask[3];
      dstMaskZ = dstMask[2];
      goto loopSetDstToken;
    }
    dstMaskZ = dstMask[2];
    if (dstMaskZ == 0) {
      dstMaskW = dstMask[3];
      goto loopSetDstToken;
    }
    if (dstMask[3] == 0) {
      dstMaskW = 0;
      goto loopSetDstToken;
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
                if (src0SelectW == 3) goto setTokenCount;
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
  src0SwizzleToken = (src0NegateW & 1) << 0xf |
           (src0SelectW & 7) << 0xc |
           (src0NegateZ & 1) << 0xb |
           (src0SelectZ & 7) << 8 | (src0NegateY & 1) << 7 | (src0SelectY & 7) << 4 | (*src0Negate & 1) << 3 | src0SelectX & 7
  ;
setTokenCount:
  tokenCount = *tokenCountPtr;
  allocator = *(int *)(emitter + 0x3d4);
  if (*(uint *)(emitter + 0x758) <= tokenCount) {
    newTokenArray = (**(code **)(allocator + 0xc))(*(uint *)(emitter + 0x758) * 4 + 0x200);
    if (*(int *)(emitter + 0x75c) != 0) {
      _memcpy(newTokenArray,*(int *)(emitter + 0x75c),*tokenCountPtr << 2);
      (**(code **)(allocator + 0x18))(*(undefined4 *)(emitter + 0x75c));
    }
    *(undefined4 *)(emitter + 0x75c) = newTokenArray;
    tokenCount = *tokenCountPtr;
    *(int *)(emitter + 0x758) = *(int *)(emitter + 0x758) + 0x80;
  }
  *(undefined4 *)(tokenCount * 4 + *(int *)(emitter + 0x75c)) = 0x54;
  tokenCount = *tokenCountPtr + 1;
  *tokenCountPtr = tokenCount;
  allocator = *(int *)(emitter + 0x3d4);
  if (*(uint *)(emitter + 0x758) <= tokenCount) {
    newTokenArray = (**(code **)(allocator + 0xc))(*(uint *)(emitter + 0x758) * 4 + 0x200);
    if (*(int *)(emitter + 0x75c) != 0) {
      _memcpy(newTokenArray,*(int *)(emitter + 0x75c),*tokenCountPtr << 2);
      (**(code **)(allocator + 0x18))(*(undefined4 *)(emitter + 0x75c));
    }
    *(undefined4 *)(emitter + 0x75c) = newTokenArray;
    tokenCount = *tokenCountPtr;
    *(int *)(emitter + 0x758) = *(int *)(emitter + 0x758) + 0x80;
  }
  *(uint *)(tokenCount * 4 + *(int *)(emitter + 0x75c)) = dstToken;
  tokenCount = *tokenCountPtr + 1;
  *tokenCountPtr = tokenCount;
  if ((dstToken & 0x400000) != 0) {
    allocator = *(int *)(emitter + 0x3d4);
    if (*(uint *)(emitter + 0x758) <= tokenCount) {
      newTokenArray = (**(code **)(allocator + 0xc))(*(uint *)(emitter + 0x758) * 4 + 0x200);
      if (*(int *)(emitter + 0x75c) != 0) {
        _memcpy(newTokenArray,*(int *)(emitter + 0x75c),*tokenCountPtr << 2);
        (**(code **)(allocator + 0x18))(*(undefined4 *)(emitter + 0x75c));
      }
      *(undefined4 *)(emitter + 0x75c) = newTokenArray;
      tokenCount = *tokenCountPtr;
      *(int *)(emitter + 0x758) = *(int *)(emitter + 0x758) + 0x80;
    }
    *(uint *)(tokenCount * 4 + *(int *)(emitter + 0x75c)) = dstMaskToken;
    tokenCount = *tokenCountPtr + 1;
    *tokenCountPtr = tokenCount;
  }
  allocator = *(int *)(emitter + 0x3d4);
  if (*(uint *)(emitter + 0x758) <= tokenCount) {
    newTokenArray = (**(code **)(allocator + 0xc))(*(uint *)(emitter + 0x758) * 4 + 0x200);
    if (*(int *)(emitter + 0x75c) != 0) {
      _memcpy(newTokenArray,*(int *)(emitter + 0x75c),*tokenCountPtr << 2);
      (**(code **)(allocator + 0x18))(*(undefined4 *)(emitter + 0x75c));
    }
    *(undefined4 *)(emitter + 0x75c) = newTokenArray;
    tokenCount = *tokenCountPtr;
    *(int *)(emitter + 0x758) = *(int *)(emitter + 0x758) + 0x80;
  }
  *(uint *)(tokenCount * 4 + *(int *)(emitter + 0x75c)) = src0Token;
  tokenCount2 = *tokenCountPtr + 1;
  *tokenCountPtr = tokenCount2;
  if ((src0Token & 0x400000) != 0) {
    allocator = *(int *)(emitter + 0x3d4);
    if (*(uint *)(emitter + 0x758) <= tokenCount2) {
      newTokenArray = (**(code **)(allocator + 0xc))(*(uint *)(emitter + 0x758) * 4 + 0x200);
      if (*(int *)(emitter + 0x75c) != 0) {
        _memcpy(newTokenArray,*(int *)(emitter + 0x75c),*tokenCountPtr << 2);
        (**(code **)(allocator + 0x18))(*(undefined4 *)(emitter + 0x75c));
      }
      *(undefined4 *)(emitter + 0x75c) = newTokenArray;
      tokenCount2 = *tokenCountPtr;
      *(int *)(emitter + 0x758) = *(int *)(emitter + 0x758) + 0x80;
    }
    *(uint *)(tokenCount2 * 4 + *(int *)(emitter + 0x75c)) = src0SwizzleToken;
    *tokenCountPtr = *tokenCountPtr + 1;
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
asm(".globl extvsRewriteHardwareInstructions");
asm(".set extvsRewriteHardwareInstructions, _FUN_0005f540");
asm(".globl extvsPrepareHardwareProgram");
asm(".set extvsPrepareHardwareProgram, _extvsPrepareHardwareProgram");
asm(".globl gldLoadUnitFlagBits");
asm(".set gldLoadUnitFlagBits, _gldLoadUnitFlagBits");
asm(".globl extvsInitLimits");
asm(".set extvsInitLimits, _extvsInitLimits");
asm(".globl gldAllocListNode");
asm(".set gldAllocListNode, _gldAllocListNode");
asm(".globl gldDestroyListObject");
asm(".set gldDestroyListObject, _gldDestroyListObject");
asm(".globl extvsStateCacheCreate");
asm(".set extvsStateCacheCreate, _extvsStateCacheCreate");
asm(".globl extvsStateCacheFreeAll");
asm(".set extvsStateCacheFreeAll, _extvsStateCacheFreeAll");
asm(".globl extvsUploadSingleConstant");
asm(".set extvsUploadSingleConstant, _FUN_00062940");
asm(".globl extvsBuildStreamDescriptors");
asm(".set extvsBuildStreamDescriptors, _extvsBuildStreamDescriptors");
asm(".globl gldCurrentAttributePacketHeader");
asm(".set gldCurrentAttributePacketHeader, _gldCurrentAttributePacketHeader");
asm(".globl extvsBuildStreamBlock");
asm(".set extvsBuildStreamBlock, _extvsBuildStreamBlock");
asm(".globl extvsApplyStreamDescriptors");
asm(".set extvsApplyStreamDescriptors, _extvsApplyStreamDescriptors");
asm(".globl extvsUploadProgramConstants");
asm(".set extvsUploadProgramConstants, _extvsUploadProgramConstants");
asm(".globl extvsValidateProgramState");
asm(".set extvsValidateProgramState, _extvsValidateProgramState");
asm(".globl ffvpInitBuilderOutputSlots");
asm(".set ffvpInitBuilderOutputSlots, _ffvpInitBuilderOutputSlots");
asm(".globl vpFillConstantBank");
asm(".set vpFillConstantBank, _vpFillConstantBank");
asm(".globl ffvpUploadVariantConstants");
asm(".set ffvpUploadVariantConstants, _ffvpUploadVariantConstants");
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
