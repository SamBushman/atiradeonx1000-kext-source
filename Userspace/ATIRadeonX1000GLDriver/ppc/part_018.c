#include "decls.h"

/* ilPopFreeRegister @ 0xc73c0 (144 bytes) */
int ilPopFreeRegister(programRecord)
  int programRecord;
{
  int iVar1;
  uint loopIndex2;
  int loopIndex;
  uint uVar4;
  uint uVar5;
  int remaining;
  
  loopIndex = 0;
  remaining = 8;
  iVar1 = programRecord;
  do {
    uVar4 = *(uint *)(iVar1 + 0xc);
    if (uVar4 != 0) {
      loopIndex2 = 0;
      if ((uVar4 & 1) == 0) {
        do {
          loopIndex2 = loopIndex2 + 1;
          uVar5 = 1 << (loopIndex2 & 0x3f);
        } while ((uVar4 & uVar5) == 0);
        uVar5 = ~uVar5;
      }
      else {
        uVar5 = 0xfffffffe;
      }
      iVar1 = loopIndex * 4 + programRecord;
      *(uint *)(iVar1 + 0xc) = uVar5 & *(uint *)(iVar1 + 0xc);
      return loopIndex2 + loopIndex * 0x20;
    }
    loopIndex = loopIndex + 1;
    iVar1 = iVar1 + 4;
    remaining = remaining + -1;
  } while (remaining != 0);
  return -1;
}

/* ilEmitProjectiveDivide @ 0xc7460 (468 bytes) */
int ilEmitProjectiveDivide(programRecord, coordinateOperand, coordinateExtraWord, unitIndex, outCursor)
  int programRecord;
  uint *coordinateOperand;
  uint *coordinateExtraWord;
  uint unitIndex;
  undefined4 *outCursor;
{
  ushort coordinateTokenHalf;
  uint scratchRegisterBits;
  uint divisorComponent;
  undefined *replicatedSwizzle;
  
  if ((1 << (unitIndex & 0x3f) & *(uint *)(programRecord + 0x70)) == 0) {
    return outCursor;
  }
  *outCursor = 0x51;
  scratchRegisterBits = *(uint *)(programRecord + 0x184);
  outCursor[2] = 0x40;
  outCursor[1] = scratchRegisterBits & 0xffff | 0x440000;
  outCursor[3] = (*(ushort *)coordinateOperand & 0x3f) << 0x10 | (uint)(ushort)*coordinateOperand | 0x400000;
  if ((*coordinateOperand & 0x400000) == 0) {
    replicatedSwizzle = ((unsigned char *)0x00005555);
    goto LAB_000c7584;
  }
  divisorComponent = 1;
  scratchRegisterBits = *coordinateExtraWord >> 0x15 & 7;
  if (scratchRegisterBits != 1) {
    if (scratchRegisterBits < 2) {
      divisorComponent = 5;
      if (scratchRegisterBits != 0) {
LAB_000c7520:
        divisorComponent = 0;
      }
    }
    else {
      divisorComponent = 2;
      if (scratchRegisterBits != 2) {
        if (scratchRegisterBits != 3) goto LAB_000c7520;
        divisorComponent = 3;
      }
    }
  }
  replicatedSwizzle = (undefined *)(divisorComponent << 0xc | divisorComponent << 8 | divisorComponent << 4 | divisorComponent);
LAB_000c7584:
  outCursor[4] = replicatedSwizzle;
  outCursor[5] = 0x49;
  scratchRegisterBits = *(uint *)(programRecord + 0x184);
  outCursor[7] = 0x110;
  outCursor[6] = scratchRegisterBits & 0xffff | 0x440000;
  scratchRegisterBits = *(uint *)(programRecord + 0x184);
  outCursor[9] = ((unsigned char *)0x00003333);
  outCursor[8] = scratchRegisterBits & 0xffff | 0x440000;
  coordinateTokenHalf = *(ushort *)coordinateOperand;
  scratchRegisterBits = *coordinateOperand;
  outCursor[0xb] = 0x2222;
  outCursor[10] = (uint)(ushort)scratchRegisterBits | (coordinateTokenHalf & 0x3f) << 0x10 | 0x400000;
  return outCursor + 0xc;
}

/* ilEmitShadowCompare @ 0xc7650 (680 bytes) */
int ilEmitShadowCompare(programRecord, param_2, coordinateOperand, coordinateExtraWordPtr, unitIndex, copyExtraWord, outCursor, param_8)
  int programRecord;
  undefined4 param_2;
  uint *coordinateOperand;
  uint *coordinateExtraWordPtr;
  uint unitIndex;
  int copyExtraWord;
  uint *outCursor;
  undefined4 param_8;
{
  uint programRecordWord184;
  uint programRecordWord180;
  ushort uVar1;
  int unitByteOffset;
  int iVar3;
  undefined *puVar4;
  uint compareSelectWord;
  uint *tokenPtr;
  uint uVar7;
  
  if ((1 << (unitIndex & 0x3f) & *(uint *)(programRecord + 0x70)) != 0) {
    *outCursor = 0x5b;
    unitByteOffset = unitIndex * 4;
    programRecordWord180 = *(uint *)(programRecord + 0x180);
    outCursor[2] = 0x10;
    outCursor[1] = programRecordWord180 & 0xffff | 0x440000;
    compareSelectWord = 0xd;
    programRecordWord184 = *(uint *)(programRecord + 0x184);
    outCursor[4] = 0x2222;
    outCursor[3] = programRecordWord184 & 0xffff | 0x440000;
    uVar1 = *(ushort *)coordinateOperand;
    uVar7 = *coordinateOperand;
    outCursor[6] = 0x2222;
    outCursor[5] = (uint)(ushort)uVar7 | (uVar1 & 0x3f) << 0x10 | 0x400000;
    switch(*(undefined4 *)(unitByteOffset + programRecord + 0x138)) {
    case 0x200:
    case 0x202:
    case 0x207:
      compareSelectWord = 0x1000d;
      break;
    case 0x201:
      compareSelectWord = 0x5000d;
      break;
    case 0x203:
      compareSelectWord = 0x4000d;
      break;
    case 0x204:
      compareSelectWord = 0x3000d;
      break;
    case 0x205:
      compareSelectWord = 0xd;
      break;
    case 0x206:
      compareSelectWord = 0x2000d;
    }
    outCursor[7] = compareSelectWord;
    if (copyExtraWord == 0) {
      uVar7 = *coordinateOperand;
    }
    else {
      uVar7 = *coordinateOperand | 0x400000;
      *coordinateOperand = uVar7;
    }
    outCursor[8] = uVar7;
    tokenPtr = outCursor + 9;
    if (copyExtraWord != 0) {
      tokenPtr = outCursor + 10;
      outCursor[9] = *coordinateExtraWordPtr;
    }
    *tokenPtr = *(uint *)(programRecord + 0x180) & 0xffff | 0x440000;
    iVar3 = *(int *)(unitByteOffset + programRecord + 0x138);
    if ((iVar3 == 0x200) || (iVar3 != 0x207)) {
      puVar4 = (undefined *)0x2222;
    }
    else {
      puVar4 = ((unsigned char *)0x00004444);
    }
    tokenPtr[1] = (uint)puVar4;
    outCursor = tokenPtr + 6;
    uVar7 = *coordinateOperand;
    tokenPtr[3] = (uint)((unsigned char *)0x00005555);
    tokenPtr[2] = (ushort)uVar7 | 0x440000;
    uVar7 = *(uint *)(unitByteOffset + programRecord + 0xb8);
    tokenPtr[5] = 0x2222;
    tokenPtr[4] = uVar7 & 0xffff | 0x410000;
  }
  return outCursor;
}

/* FUN_000c7930 @ 0xc7930 (2004 bytes) */
int FUN_000c7930(param_1, param_2, scanTokenWord, param_4, param_5, param_6, opcodeTimes4)
  undefined4 *param_1;
  int param_2;
  undefined4 scanTokenWord;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  uint opcodeTimes4;
{
  uint loopIndex;
  int remaining4;
  int remaining3;
  int remaining2;
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int remaining;
  
  if (*(int *)(param_2 + 0x22fc) != 0) {
    remaining = 4;
    iVar2 = param_2;
    do {
      if (*(int *)(iVar2 + 0x21f0) != 0) {
        *param_1 = 0x47;
        uVar1 = *(uint *)(iVar2 + 0x21e0);
        param_1[2] = 0x115;
        param_1[1] = uVar1 & 0xffff | 0x440000;
        opcodeTimes4 = *(uint *)(iVar2 + 0x21e0) & 0xffff | 0x40000;
        param_1[3] = opcodeTimes4;
        param_1 = param_1 + 4;
      }
      iVar2 = iVar2 + 4;
      remaining = remaining + -1;
    } while (remaining != 0);
    iVar2 = *(int *)(param_2 + 0x22fc);
    if (iVar2 == 2) {
      *param_1 = 0x49;
      uVar1 = *(uint *)(param_2 + 0x2300);
      param_1[2] = 1;
      param_1[1] = uVar1 & 0xffff | 0x440000;
      uVar1 = *(uint *)(param_2 + 0x2304);
      param_1[4] = 0x2222;
      param_1[3] = uVar1 & 0xffff | opcodeTimes4 & 0xffc00000 | 0x10000 | 0x400000;
      uVar4 = 0;
      param_1[5] = *(uint *)(param_2 + 0x68) & 0xffff | 0x510000;
      if (*(int *)(param_2 + 0x230c) == 0) {
        uVar4 = 0x100000;
      }
      param_1[6] = uVar4;
      param_1[7] = 0x2d;
      uVar1 = *(uint *)(param_2 + 0x2300);
      param_1[9] = 0x101;
      param_1[8] = uVar1 & 0xffff | 0x440000;
      uVar1 = *(uint *)(param_2 + 0x2300);
      param_1[0xb] = 0x8888;
      param_1[10] = uVar1 & 0xffff | 0x440000;
      param_1 = param_1 + 0xc;
    }
    else if (iVar2 == 3) {
      *param_1 = 0x49;
      uVar1 = *(uint *)(param_2 + 0x2300);
      param_1[2] = 1;
      param_1[1] = uVar1 & 0xffff | 0x440000;
      uVar1 = *(uint *)(param_2 + 0x2304);
      param_1[4] = ((unsigned char *)0x00003333);
      param_1[3] = uVar1 & 0xffff | opcodeTimes4 & 0xffc00000 | 0x10000 | 0x400000;
      uVar4 = 0;
      param_1[5] = *(uint *)(param_2 + 0x68) & 0xffff | 0x510000;
      if (*(int *)(param_2 + 0x230c) == 0) {
        uVar4 = 0x100000;
      }
      param_1[6] = uVar4;
      param_1[7] = 0x49;
      param_1[8] = *(uint *)(param_2 + 0x2300) & 0xffff | 0x40000;
      uVar1 = *(uint *)(param_2 + 0x2300);
      param_1[0xb] = 0x2d;
      uVar1 = uVar1 & 0xffff | 0x40000;
      param_1[10] = uVar1;
      param_1[9] = uVar1;
      uVar1 = *(uint *)(param_2 + 0x2300);
      param_1[0xd] = 0x101;
      param_1[0xc] = uVar1 & 0xffff | 0x440000;
      uVar1 = *(uint *)(param_2 + 0x2300);
      param_1[0xf] = 0x8888;
      param_1[0xe] = uVar1 & 0xffff | 0x440000;
      param_1 = param_1 + 0x10;
    }
    else if (iVar2 == 1) {
      *param_1 = 0x40;
      uVar1 = *(uint *)(param_2 + 0x2300);
      param_1[2] = 0x101;
      uVar4 = 0;
      param_1[1] = uVar1 & 0xffff | 0x440000;
      param_1[3] = *(uint *)(param_2 + 0x68) & 0xffff | 0x510000;
      if (*(int *)(param_2 + 0x230c) == 0) {
        uVar4 = 0x100000;
      }
      param_1[4] = uVar4;
      uVar1 = *(uint *)(param_2 + 0x2304);
      param_1[6] = 0;
      param_1[5] = uVar1 & 0xffff | 0x410000;
      uVar1 = *(uint *)(param_2 + 0x2304);
      param_1[8] = ((unsigned char *)0x00001111);
      param_1[7] = uVar1 & 0xffff | 0x410000;
      param_1 = param_1 + 9;
    }
    remaining2 = 4;
    iVar2 = param_2;
    do {
      if (*(int *)(iVar2 + 0x21f0) != 0) {
        *param_1 = 0x3f;
        uVar1 = *(uint *)(param_2 + 0x21e0);
        param_1[2] = 0x15;
        param_1[1] = uVar1 & 0xffff | 0x440000;
        uVar1 = *(uint *)(param_2 + 0x2300);
        param_1[4] = 0;
        param_1[3] = uVar1 & 0xffff | 0x440000;
        param_1[5] = *(uint *)(param_2 + 0x21e0) & 0xffff | 0x40000;
        param_1[6] = *(uint *)(param_2 + 0x2308) & 0xffff | 0x10000;
        param_1 = param_1 + 7;
      }
      iVar2 = iVar2 + 4;
      remaining2 = remaining2 + -1;
    } while (remaining2 != 0);
  }
  if (*(int *)(param_2 + 0x21d0) != 0) {
    remaining3 = 4;
    iVar2 = param_2;
    do {
      if (*(int *)(iVar2 + 0x21f0) != 0) {
        *param_1 = 0x49;
        uVar1 = *(uint *)(iVar2 + 0x21e0);
        param_1[2] = 0x40;
        param_1[1] = uVar1 & 0xffff | 0x440000;
        param_1[3] = *(uint *)(iVar2 + 0x21e0) & 0xffff | 0x40000;
        uVar1 = *(uint *)(param_2 + 0x21dc);
        param_1[5] = 0;
        param_1[4] = uVar1 & 0xffff | 0x440000;
        param_1 = param_1 + 6;
      }
      iVar2 = iVar2 + 4;
      remaining3 = remaining3 + -1;
    } while (remaining3 != 0);
  }
  loopIndex = 0;
  remaining4 = 4;
  iVar2 = param_2;
  do {
    if (*(int *)(iVar2 + 0x21f0) != 0) {
      *param_1 = 0x47;
      param_1[1] = loopIndex & 0xffff | 0x170000;
      param_1[2] = *(uint *)(iVar2 + 0x21e0) & 0xffff | 0x40000;
      param_1 = param_1 + 3;
    }
    loopIndex = loopIndex + 1;
    iVar2 = iVar2 + 4;
    remaining4 = remaining4 + -1;
  } while (remaining4 != 0);
  if (((*(int *)(param_2 + 0x220c) != 0) && (*(int *)(param_2 + 0x2204) != 0)) &&
     (*(int *)(param_2 + 0x2234) == 0)) {
    if (*(int *)(param_2 + 0x2210) == 0xffff) {
      *param_1 = 0x47;
      param_1[1] = 0x530000;
      param_1[2] = 0x40;
    }
    else {
      *param_1 = 0x47;
      uVar1 = *(uint *)(param_2 + 0x2210);
      param_1[2] = 1;
      param_1[1] = uVar1 & 0xffff | 0x510000;
    }
    uVar1 = *(uint *)(param_2 + 0x2208);
    param_1[4] = 0;
    param_1[3] = uVar1 & 0xffff | 0x440000;
    param_1 = param_1 + 5;
  }
  /* issue #64 live-repro (3rd crash, past the earlier two fixes): puVar3 - the value this function
   * actually returns (part_018.c:386) - was only ever assigned as a side effect of this
   * OR-condition's third clause, via the comma operator. C's short-circuit evaluation means that
   * side effect never runs when either of the first two clauses is already true, leaving puVar3
   * uninitialized in that case (it has no earlier assignment anywhere in the function). Live-
   * verified on real hardware via a raw memory watchpoint: with *(param_2+0x22fc)==3 (this
   * function's own case), the returned puVar3 was garbage, corrupting a since-freed heap block's
   * `free_list_t.previous` field the moment the caller wrote through it (ilRewriteForTextureState
   * part_018.c:3651, `*puVar45 = ppppppuVar15;`) - confirmed via Apple's real scalable_malloc.c
   * checksum formula against the live-read corrupted bytes. puVar3 is meant to track the current
   * write pointer (== param_1) at this checkpoint regardless of which clause is true; made the
   * assignment unconditional so the case that skipped it can no longer leave it unset. */
  puVar3 = param_1;
  if (((*(int *)(param_2 + 0x2218) != 0) || (*(int *)(param_2 + 0x2220) != 0)) ||
     (*(int *)(param_2 + 0x2234) == 0)) {
    if ((*(int *)(param_2 + 0x2214) == 0) && (*(int *)(param_2 + 0x221c) != 0)) {
      *param_1 = 0x47;
      param_1[2] = 0x10000;
      param_1[1] = 0x120000;
      param_1 = param_1 + 3;
    }
    puVar3 = param_1;
    if (*(int *)(param_2 + 0x2234) == 0) {
      *param_1 = 0x47;
      param_1[1] = 0xe0000;
      param_1[2] = *(uint *)(param_2 + 0x2200) & 0xffff | 0x40000;
      puVar3 = param_1 + 3;
      if (*(int *)(param_2 + 0x2310) != 0) {
        param_1[3] = 0x47;
        param_1[4] = *(uint *)(param_2 + 0x2314) & 0xffff | 0x110000;
        param_1[5] = *(uint *)(param_2 + 0x2200) & 0xffff | 0x40000;
        puVar3 = param_1 + 6;
      }
    }
  }
  return puVar3;
}

/* ilEmitPrologue @ 0xc8110 (1252 bytes) */
int ilEmitPrologue(outCursor, programRecord, passThroughR5, passThroughR6, passThroughR7, passThroughR8, passThroughR9, passThroughR10)
  uint *outCursor;
  int programRecord;
  undefined4 passThroughR5;
  undefined4 passThroughR6;
  undefined4 passThroughR7;
  undefined4 passThroughR8;
  undefined4 passThroughR9;
  undefined4 passThroughR10;
{
  int remaining2;
  uint programRecordWord74;
  uint programRecordWord54;
  uint programRecordWord60;
  uint programRecordWord8;
  uint loopIndex;
  bool bVar1;
  uint programRecordWord70;
  undefined4 registerNumber;
  uint *puVar4;
  int loopIndex3;
  uint loopIndex4;
  uint uVar7;
  uint loopIndex2;
  int iVar9;
  uint uVar10;
  int remaining;
  undefined8 allocationResult;
  undefined4 operandToken0;
  undefined4 operandToken1;
  undefined4 operandToken2;
  
  registerNumber = ilNextCounterValue(programRecord);
  *(undefined4 *)(programRecord + 0x21e0) = registerNumber;
  registerNumber = ilNextCounterValue(programRecord);
  *(undefined4 *)(programRecord + 0x21e4) = registerNumber;
  registerNumber = ilNextCounterValue(programRecord);
  *(undefined4 *)(programRecord + 0x21e8) = registerNumber;
  registerNumber = ilNextCounterValue(programRecord);
  *(undefined4 *)(programRecord + 0x21ec) = registerNumber;
  if (*(int *)(programRecord + 0x2324) != 0) {
    registerNumber = ilNextCounterValue(programRecord);
    *(undefined4 *)(programRecord + 9000) = registerNumber;
  }
  registerNumber = ilNextCounterValue(programRecord);
  *(undefined4 *)(programRecord + 0x2200) = registerNumber;
  allocationResult = ilNextCounterValue(programRecord);
  *(int *)(programRecord + 0x2208) = (int)((ulonglong)allocationResult >> 0x20);
  if (*(int *)(programRecord + 100) != 0) {
    registerNumber = ilAllocLowestFreeBit8(programRecord,(int)allocationResult,passThroughR5,passThroughR6,passThroughR7,passThroughR8,passThroughR9,passThroughR10);
    *(undefined4 *)(programRecord + 0x68) = registerNumber;
  }
  if (*(int *)(programRecord + 0x22fc) != 0) {
    registerNumber = ilNextCounterValue(programRecord);
    *(undefined4 *)(programRecord + 0x2300) = registerNumber;
    registerNumber = ((int (*)())ilPopFreeRegister)(programRecord);
    *(undefined4 *)(programRecord + 0x2304) = registerNumber;
    registerNumber = ((int (*)())ilPopFreeRegister)(programRecord);
    *(undefined4 *)(programRecord + 0x2308) = registerNumber;
    *outCursor = 0x1ff0016;
    outCursor[1] = *(uint *)(programRecord + 0x68) & 0xffff | 0x110000;
    outCursor = outCursor + 2;
  }
  if (*(int *)(programRecord + 0x21d0) != 0) {
    registerNumber = ilNextCounterValue(programRecord);
    *(undefined4 *)(programRecord + 0x21dc) = registerNumber;
    *outCursor = 0x1ff0016;
    outCursor[1] = *(uint *)(programRecord + 0x21d4) & 0xffff | 0x110000;
    outCursor[2] = *(int *)(programRecord + 0x21d4) << 0x10 | 0xb000019;
    outCursor = outCursor + 3;
  }
  if (*(int *)(programRecord + 0x4c) != 0) {
    registerNumber = ilNextCounterValue(programRecord);
    *(undefined4 *)(programRecord + 0x54) = registerNumber;
    registerNumber = ((int (*)())ilPopFreeRegister)(programRecord);
    *(undefined4 *)(programRecord + 0x58) = registerNumber;
    allocationResult = ((int (*)())ilPopFreeRegister)(programRecord);
    *(int *)(programRecord + 0x5c) = (int)((ulonglong)allocationResult >> 0x20);
    registerNumber = ilAllocLowestFreeBit8(programRecord,(int)allocationResult,passThroughR5,passThroughR6,passThroughR7,passThroughR8,passThroughR9,passThroughR10);
    *(undefined4 *)(programRecord + 0x60) = registerNumber;
    *outCursor = 0x1ff0016;
    programRecordWord60 = *(uint *)(programRecord + 0x60);
    outCursor[2] = 0x51;
    outCursor[1] = programRecordWord60 & 0xffff | 0x110000;
    programRecordWord54 = *(uint *)(programRecord + 0x54);
    outCursor[4] = 0x40;
    outCursor[3] = programRecordWord54 & 0xffff | 0x440000;
    registerNumber = *(undefined4 *)(programRecord + 0x60);
    outCursor[6] = 0x49;
    operandToken0 = CONCAT22(0x11,(short)registerNumber);
    outCursor[5] = operandToken0;
    programRecordWord54 = *(uint *)(programRecord + 0x54);
    outCursor[8] = 0x15;
    outCursor[7] = programRecordWord54 & 0xffff | 0x440000;
    registerNumber = *(undefined4 *)(programRecord + 0x54);
    outCursor[10] = (uint)((unsigned char *)0x00003333);
    operandToken0 = CONCAT22(4,(short)registerNumber);
    outCursor[9] = operandToken0 | 0x400000;
    registerNumber = *(undefined4 *)(programRecord + 0x60);
    outCursor[0xc] = 0x40;
    operandToken1 = CONCAT22(0x11,(short)registerNumber);
    outCursor[0xb] = operandToken1;
    programRecordWord54 = *(uint *)(programRecord + 0x54);
    outCursor[0xe] = 0x15;
    outCursor[0xd] = programRecordWord54 & 0xffff | 0x440000;
    operandToken0 = CONCAT22(4,(short)*(undefined4 *)(programRecord + 0x54));
    outCursor[0xf] = operandToken0;
    operandToken1 = CONCAT22(1,(short)*(undefined4 *)(programRecord + 0x58));
    outCursor[0x10] = operandToken1;
    operandToken2 = CONCAT22(1,(short)*(undefined4 *)(programRecord + 0x5c));
    outCursor[0x11] = operandToken2;
    outCursor = outCursor + 0x12;
  }
  if (*(int *)(programRecord + 0x2234) != 0) {
    programRecordWord70 = *(uint *)(programRecord + 0x70);
    programRecordWord74 = *(uint *)(programRecord + 0x74);
    uVar7 = 0;
    loopIndex2 = 0;
    iVar9 = programRecord;
    do {
      uVar10 = 1 << (loopIndex2 & 0x3f);
      if (((programRecordWord70 | programRecordWord74) & uVar10) != 0) {
        registerNumber = ((int (*)())ilPopFreeRegister)(programRecord);
        *(undefined4 *)(iVar9 + 0xb8) = registerNumber;
        if (uVar7 == 0) {
          uVar7 = 1;
        }
      }
      if ((uVar10 & *(uint *)(programRecord + 0x74)) != 0) {
        registerNumber = ilNextCounterValue(programRecord);
        *(undefined4 *)(programRecord + 0x184) = registerNumber;
        if (uVar7 < 2) {
          uVar7 = 2;
        }
      }
      bVar1 = loopIndex2 != 0xf;
      iVar9 = iVar9 + 4;
      loopIndex2 = loopIndex2 + 1;
    } while (bVar1);
    if (uVar7 != 0) {
      loopIndex = 0;
      iVar9 = programRecord;
      do {
        loopIndex = loopIndex + 1;
        registerNumber = ilNextCounterValue(programRecord);
        *(undefined4 *)(iVar9 + 0x17c) = registerNumber;
        iVar9 = iVar9 + 4;
      } while (loopIndex != uVar7);
    }
  }
  if (*(int *)(programRecord + 0x21d0) != 0) {
    *outCursor = (*(uint *)(programRecord + 0x21d4) & 0x3fff) << 0x10 | 0x5d;
    outCursor[1] = *(uint *)(programRecord + 0x21dc) & 0xffff | 0x40000;
    operandToken0 = CONCAT22(0x11,(short)*(undefined4 *)(programRecord + 0x21d8));
    outCursor[2] = operandToken0;
    outCursor = outCursor + 3;
  }
  loopIndex3 = 0;
  remaining = 0x10;
  iVar9 = programRecord;
  do {
    *(int *)(iVar9 + 0x232c) = loopIndex3;
    loopIndex3 = loopIndex3 + 1;
    iVar9 = iVar9 + 4;
    remaining = remaining + -1;
  } while (remaining != 0);
  programRecordWord8 = *(uint *)(programRecord + 8);
  puVar4 = (uint *)(programRecord + 0x232c);
  loopIndex4 = 0;
  remaining2 = 0x10;
  do {
    if ((1 << (loopIndex4 & 0x3f) & programRecordWord8) == 0) {
      *puVar4 = loopIndex4;
      puVar4 = puVar4 + 1;
    }
    loopIndex4 = loopIndex4 + 1;
    remaining2 = remaining2 + -1;
  } while (remaining2 != 0);
  return outCursor;
}

/* FUN_000c8600 @ 0xc8600 (316 bytes) */
int FUN_000c8600(param_1, param_2, param_3, destinationExtraWord, param_5)
  uint param_1;
  int param_2;
  int *param_3;
  uint destinationExtraWord;
  int param_5;
{
  int iVar1;
  
  if ((int)param_1 < *param_3) {
    iVar1 = param_3[1];
  }
  else {
    iVar1 = param_3[1];
    if (iVar1 < (int)param_1) goto LAB_000c8650;
    *param_3 = param_1 + 1;
  }
  if (((int)param_1 <= iVar1) && (*param_3 <= (int)param_1)) {
    param_3[1] = param_1 - 1;
  }
LAB_000c8650:
  if (param_2 == 0x17) {
    param_3[param_1 + 0x87c] = 1;
    if (((((destinationExtraWord & 3) != 1) && ((destinationExtraWord & 0xc) != 4)) && ((destinationExtraWord & 0x30) != 0x10)) &&
       (((destinationExtraWord & 0xc0) != 0x40 && (param_5 != 0)))) {
      return;
    }
    param_3[0x889] = 1;
    return;
  }
  if (param_2 == 0x18) {
    param_3[0x88a] = 1;
    param_3[0x889] = 1;
    return;
  }
  if (param_2 == 0x12) {
    param_3[param_1 + 0x885] = 1;
    return;
  }
  if (param_2 == 0x13) {
    param_3[param_1 + 0x887] = 1;
    return;
  }
  if (param_2 != 0x10) {
    if (param_2 != 0x11) {
      return;
    }
    if (param_3[0x8c7] < (int)param_1) {
      param_3[0x8c7] = param_1;
    }
    param_3[2] = 1 << (param_1 & 0x3f) | param_3[2];
    return;
  }
  param_3[0x883] = 1;
  return;
}

/* ilRemapSourceOperandRegister @ 0xc8760 (104 bytes) */
int ilRemapSourceOperandRegister(operandWords, operandExtraWord, programRecord)
  uint *operandWords;
  undefined4 operandExtraWord;
  int programRecord;
{
  uint operandWord;
  
  operandWord = *operandWords;
  if ((undefined *)(operandWord & 0x3f0000) == ((unsigned char *)0x00160000U)) {
    *operandWords = operandWord & 0xffc0ffff | 0x40000;
    *(short *)((int)operandWords + 2) = (short)*(undefined4 *)(programRecord + 0x54);
    operandWord = *operandWords;
  }
  if ((operandWord & 0x3f0000) != 0xf0000) {
    return;
  }
  *(short *)((int)operandWords + 2) =
       (short)*(undefined4 *)((uint)(ushort)*operandWords * 4 + programRecord + 0x232c);
  return;
}

/* ilMarkOperandRegisterUsed @ 0xc87d0 (296 bytes) */
int ilMarkOperandRegisterUsed(operandWords, operandExtraWordPtr, programRecord)
  uint *operandWords;
  undefined4 operandExtraWordPtr;
  int programRecord;
{
  int remaining2;
  int remaining;
  uint operandWord;
  int iVar2;
  uint registerType;
  uint registerIndex;
  int iVar5;
  
  operandWord = *operandWords;
  registerIndex = (uint)(ushort)*operandWords;
  registerType = operandWord >> 0x10 & 0x3f;
  iVar2 = (int)registerIndex >> 5;
  if (registerType != 1) {
    if (registerType == 2) {
      if ((operandWord & 0x1800000) == 0) {
        iVar2 = iVar2 * 4 + programRecord;
        *(uint *)(iVar2 + 0x2c) =
             (-2 << (registerIndex & 0x1f) | 0xfffffffeU >> 0x20 - (registerIndex & 0x1f)) & *(uint *)(iVar2 + 0x2c)
        ;
        operandWord = *operandWords;
        goto LAB_000c88e4;
      }
      remaining = 8;
      iVar2 = programRecord;
      do {
        *(undefined4 *)(iVar2 + 0x2c) = 0;
        iVar2 = iVar2 + 4;
        remaining = remaining + -1;
      } while (remaining != 0);
    }
    else {
      if (registerType == 3) {
        if (registerIndex != 0) {
          *(undefined4 *)(programRecord + 0x21c8) = 5;
          operandWord = *operandWords;
        }
        goto LAB_000c88e4;
      }
      if (registerType != 0x15) goto LAB_000c88e4;
      *(undefined4 *)(programRecord + 0x21c8) = 5;
    }
  }
  else {
    if ((operandWord & 0x1800000) == 0) {
      iVar5 = iVar2 * 4 + programRecord;
      *(uint *)(iVar5 + 0xc) = *(uint *)(iVar5 + 0xc) & ~(1 << (registerIndex + iVar2 * -0x20 & 0x3f));
      operandWord = *operandWords;
      goto LAB_000c88e4;
    }
    remaining2 = 8;
    iVar2 = programRecord;
    do {
      *(undefined4 *)(iVar2 + 0xc) = 0;
      iVar2 = iVar2 + 4;
      remaining2 = remaining2 + -1;
    } while (remaining2 != 0);
  }
  operandWord = *operandWords;
LAB_000c88e4:
  if ((operandWord & 0x1800000) == 0) {
    return;
  }
  if (registerType == 1) {
    *(undefined4 *)(0x0000222c + programRecord + 4) = 1;
    return;
  }
  *(undefined4 *)(programRecord + 0x21c8) = 4;
  return;
}

/* ilMarkInstructionRegistersUsed @ 0xc8910 (400 bytes) */
int ilMarkInstructionRegistersUsed(tokens, hasDestination, sourceCount, programRecord)
  uint *tokens;
  int hasDestination;
  int sourceCount;
  uint programRecord;
{
  uint destinationExtraWord;
  uint *nextCursor;
  uint opcodeWord;
  uint *cursor;
  uint destinationWord;
  uint sourceWord0;
  uint sourceWord1;
  uint sourceWord2;
  uint sourceExtraWord0;
  uint sourceExtraWord1;
  uint sourceExtraWord2 [6];
  
  cursor = tokens + 1;
  opcodeWord = *tokens;
  if (hasDestination != 0) {
    destinationWord = tokens[1];
    cursor = tokens + 2;
    destinationExtraWord = programRecord;
    if ((destinationWord & 0x400000) != 0) {
      destinationExtraWord = tokens[2];
      cursor = tokens + 3;
    }
    ((int (*)())FUN_000c8600)(destinationWord & 0xffff,destinationWord >> 0x10 & 0x3f,programRecord,destinationExtraWord,destinationWord >> 0x16 & 1);
    if (((opcodeWord & 0xffff) == 0x48) && ((destinationWord & 0xffff) != 0)) {
      *(undefined4 *)(programRecord + 0x21c8) = 5;
    }
    if ((destinationWord & 0x1800000) != 0) {
      cursor = cursor + 1;
      *(undefined4 *)(programRecord + 0x21c8) = 4;
    }
  }
  if (0 < sourceCount) {
    sourceWord0 = *cursor;
    nextCursor = cursor + 1;
    if ((sourceWord0 & 0x400000) != 0) {
      sourceExtraWord0 = cursor[1];
      nextCursor = cursor + 2;
    }
    cursor = nextCursor;
    if ((sourceWord0 & 0x1800000) != 0) {
      cursor = cursor + 1;
    }
    ((int (*)())ilMarkOperandRegisterUsed)(&sourceWord0,&sourceExtraWord0,programRecord);
  }
  if (1 < sourceCount) {
    sourceWord1 = *cursor;
    nextCursor = cursor + 1;
    if ((sourceWord1 & 0x400000) != 0) {
      sourceExtraWord1 = cursor[1];
      nextCursor = cursor + 2;
    }
    cursor = nextCursor;
    if ((sourceWord1 & 0x1800000) != 0) {
      cursor = cursor + 1;
    }
    ((int (*)())ilMarkOperandRegisterUsed)(&sourceWord1,&sourceExtraWord1,programRecord);
  }
  nextCursor = cursor;
  if (2 < sourceCount) {
    sourceWord2 = *cursor;
    nextCursor = cursor + 1;
    if ((sourceWord2 & 0x400000) != 0) {
      sourceExtraWord2[0] = cursor[1];
      nextCursor = cursor + 2;
    }
    if ((sourceWord2 & 0x1800000) != 0) {
      nextCursor = nextCursor + 1;
    }
    ((int (*)())ilMarkOperandRegisterUsed)(&sourceWord2,sourceExtraWord2,programRecord);
  }
  return nextCursor;
}

/* ilCopyInstructionRemapped @ 0xc8aa0 (780 bytes) */
int ilCopyInstructionRemapped(dstCursorPtr, srcCursorPtr, hasDestination, sourceCount, programRecord)
  undefined4 *dstCursorPtr;
  undefined4 *srcCursorPtr;
  int hasDestination;
  int sourceCount;
  int programRecord;
{
  uint *nextSrcCursor;
  uint uVar2;
  int remapSlot;
  uint *dstCursor;
  undefined4 *dstStart;
  undefined4 *srcStart;
  uint *srcCursor;
  uint destinationWord;
  uint sourceWord0;
  uint sourceWord1;
  uint sourceWord2;
  uint sourceExtraWord0;
  uint sourceExtraWord1;
  uint sourceExtraWord2 [8];
  
  srcStart = (undefined4 *)*srcCursorPtr;
  dstStart = (undefined4 *)*dstCursorPtr;
  dstCursor = dstStart + 1;
  srcCursor = srcStart + 1;
  *dstStart = *srcStart;
  if (hasDestination != 0) {
    destinationWord = srcStart[1];
    srcCursor = srcStart + 2;
    uVar2 = destinationWord & 0x3f0000;
    if (uVar2 == 0x170000) {
      remapSlot = (destinationWord & 0xffff) * 4 + programRecord;
      *(undefined4 *)(remapSlot + 0x21f0) = 1;
      destinationWord = *(uint *)(remapSlot + 0x21e0) & 0xffff | destinationWord & 0xffc00000 | 0x40000;
    }
    else if (uVar2 == 0x100000) {
      destinationWord = *(uint *)(programRecord + 0x2208) & 0xffff | destinationWord & 0xffc00000 | 0x40000;
    }
    else if (uVar2 == 0xe0000) {
      if (*(int *)(programRecord + 0x2234) == 0) {
        destinationWord = *(uint *)(programRecord + 0x2200) & 0xffff | destinationWord & 0xffc00000 | 0x40000;
      }
    }
    else if (uVar2 == 0xd0000) {
      if ((*(int *)(programRecord + 0x2234) == 0) && (*(int *)(programRecord + 0x2324) != 0)) {
        destinationWord = *(uint *)(programRecord + 9000) & 0xffff | destinationWord & 0xffc00000 | 0x40000;
      }
    }
    else if (uVar2 == 0xf0000) {
      destinationWord = *(uint *)((destinationWord & 0xffff) * 4 + programRecord + 0x232c) & 0xffff | destinationWord & 0xffff0000;
    }
    *(uint *)(programRecord + 0x2318) = destinationWord;
    *dstCursor = destinationWord;
    dstCursor = dstStart + 2;
    if ((destinationWord & 0x400000) != 0) {
      uVar2 = *srcCursor;
      dstCursor = dstStart + 3;
      srcCursor = srcStart + 3;
      dstStart[2] = uVar2;
    }
  }
  if (0 < sourceCount) {
    sourceWord0 = *srcCursor;
    nextSrcCursor = srcCursor + 1;
    if ((sourceWord0 & 0x400000) != 0) {
      sourceExtraWord0 = srcCursor[1];
      nextSrcCursor = srcCursor + 2;
    }
    srcCursor = nextSrcCursor;
    ((int (*)())ilRemapSourceOperandRegister)(&sourceWord0,&sourceExtraWord0,programRecord);
    *dstCursor = sourceWord0;
    nextSrcCursor = dstCursor + 1;
    if ((sourceWord0 & 0x400000) != 0) {
      dstCursor[1] = sourceExtraWord0;
      nextSrcCursor = dstCursor + 2;
    }
    dstCursor = nextSrcCursor;
    if ((sourceWord0 & 0x1800000) != 0) {
      uVar2 = *srcCursor;
      srcCursor = srcCursor + 1;
      *dstCursor = uVar2;
      dstCursor = dstCursor + 1;
    }
  }
  if (1 < sourceCount) {
    sourceWord1 = *srcCursor;
    nextSrcCursor = srcCursor + 1;
    if ((sourceWord1 & 0x400000) != 0) {
      sourceExtraWord1 = srcCursor[1];
      nextSrcCursor = srcCursor + 2;
    }
    srcCursor = nextSrcCursor;
    ((int (*)())ilRemapSourceOperandRegister)(&sourceWord1,&sourceExtraWord1,programRecord);
    *dstCursor = sourceWord1;
    nextSrcCursor = dstCursor + 1;
    if ((sourceWord1 & 0x400000) != 0) {
      dstCursor[1] = sourceExtraWord1;
      nextSrcCursor = dstCursor + 2;
    }
    dstCursor = nextSrcCursor;
    if ((sourceWord1 & 0x1800000) != 0) {
      uVar2 = *srcCursor;
      srcCursor = srcCursor + 1;
      *dstCursor = uVar2;
      dstCursor = dstCursor + 1;
    }
  }
  if (2 < sourceCount) {
    sourceWord2 = *srcCursor;
    nextSrcCursor = srcCursor + 1;
    if ((sourceWord2 & 0x400000) != 0) {
      sourceExtraWord2[0] = srcCursor[1];
      nextSrcCursor = srcCursor + 2;
    }
    srcCursor = nextSrcCursor;
    ((int (*)())ilRemapSourceOperandRegister)(&sourceWord2,sourceExtraWord2,programRecord);
    *dstCursor = sourceWord2;
    nextSrcCursor = dstCursor + 1;
    if ((sourceWord2 & 0x400000) != 0) {
      dstCursor[1] = sourceExtraWord2[0];
      nextSrcCursor = dstCursor + 2;
    }
    dstCursor = nextSrcCursor;
    if ((sourceWord2 & 0x1800000) != 0) {
      uVar2 = *srcCursor;
      srcCursor = srcCursor + 1;
      *dstCursor = uVar2;
      dstCursor = dstCursor + 1;
    }
  }
  *dstCursorPtr = dstCursor;
  *srcCursorPtr = srcCursor;
  return srcCursor;
}

/* ilPushDclRecord @ 0xc8de0 (76 bytes) */
int ilPushDclRecord(listHeadPtr, record)
  int *listHeadPtr;
  undefined4 record;
{
  int iVar1;
  int allocation;
  
  allocation = _malloc(0x28);
  iVar1 = *listHeadPtr;
  *listHeadPtr = allocation;
  *(int *)(allocation + 0x24) = iVar1;
  return _memcpy(allocation,record,0x24);
}

/* ilStoreFloat4Constant @ 0xc8e30 (28 bytes) */
void ilStoreFloat4Constant(int programRecord,int constantIndex,double fpPassThrough1,double fpPassThrough2,double fpPassThrough3,double fpPassThrough4)
{
  int iVar1;
  
  iVar1 = constantIndex * 0x10 + programRecord;
  *(float *)(iVar1 + 0x98) = (float)fpPassThrough4;
  *(float *)(iVar1 + 0x8c) = (float)fpPassThrough1;
  *(float *)(iVar1 + 0x90) = (float)fpPassThrough2;
  *(float *)(iVar1 + 0x94) = (float)fpPassThrough3;
  return;
}

/* ilAssembleProgram @ 0xc8e50 (7396 bytes) */
int ilAssembleProgram(ctx, programHeader, programBody)
  int ctx;
  undefined4 *programHeader;
  uint *******programBody;
{
  uint loopIndex2;
  uint loopIndex;
  uint *cursor4;
  uint *cursor2;
  uint *cursor;
  uint ctxWord44;
  undefined1 *outputEntryBase;
  undefined4 *prologueDst;
  undefined4 *maskCopyDst;
  char outputKindArg;
  char outputKind;
  char *outputKindCursor;
  int scratchBlock;
  undefined4 maskWord;
  bool extraPrologue;
  int opcodeTimes4;
  int mapEntryCount;
  int recordOffset;
  int compilerHandle;
  int countdown;
  int defRecord;
  int dclRecord;
  int selectorSlot;
  uint texUnit;
  uint tokenUpper;
  uint inputKind;
  uint copyWordCount;
  uint dclRegisterIndex;
  uint sizeBytes2;
  uint *******nextDstCursorC;
  uint *******projectiveFlag;
  uint *******nextDstCursorB;
  uint ******texSourceExtraPtr;
  uint ******texOptionalWord;
  uint ******remainingEntries;
  uint ******defIndex;
  uint ******copyWord1;
  uint *******outputMapCursor;
  uint *******outputTypeCursor;
  uint ******texExtraWord;
  uint ******texTokenWord;
  uint ******mapIndex;
  uint ******outputCount;
  uint ******outputKindFlags;
  uint ******defValue;
  uint ******maxInputRegister;
  uint ******copyWord;
  int scratchAllocation;
  int inputMaskBase;
  int ilWordCount;
  uint *hwWordSource;
  uint *inputMaskCursor;
  bool hasOptionalWord;
  byte *pbVar2;
  bool hasSecondWord;
  bool prologuePending;
  byte *pbVar5;
  undefined *puVar6;
  uint texModeBits;
  uint *******nextDstCursor;
  undefined4 hasDestination;
  uint ******tokenWord;
  int zeroFillOffset;
  int *flagCursor;
  undefined4 maskWordHigh;
  char *outputEntryCursor;
  uint ******ppppppuVar15;
  undefined4 *maskCursorA;
  int maskWordIndex;
  uint *******scanTokenWord;
  uint *puVar19;
  uint *******pppppppuVar20;
  uint uVar21;
  uint sizeBytes3;
  char outputNumber;
  uint ******copyWord2;
  uint *******pppppppuVar25;
  uint *puVar26;
  undefined4 *cursor3;
  uint ******copyWord3;
  uint ******calleeSavedR14;
  uint ******calleeSavedR15;
  uint *puVar29;
  uint calleeSavedR20;
  uint *******dstCursorCarry;
  uint calleeSavedR21;
  uint *ilTokens;
  uint scanTokenCopy;
  uint uVar33;
  uint unitBit;
  int recordRegister;
  int extraWords;
  undefined1 *maskSource;
  int zeroFillCount;
  int texExtraWords;
  uint *******dstCursor;
  uint *srcCursor;
  uint ******local_2bb0;
  uint local_2bac [2];
  uint *******local_2ba4;
  uint local_2ba0 [2];
  uint ******local_2b98;
  uint ******local_2b94;
  uint ******local_2b8c [3];
  undefined1 auStack_2b80 [12];
  uint ******local_2b74;
  uint ******local_2b70;
  uint ******local_2b68;
  uint local_2b64;
  uint local_2b60;
  uint local_2b5c;
  undefined4 local_2b58 [4];
  undefined4 local_2b48;
  undefined4 local_2b44;
  undefined4 local_2b40;
  undefined4 local_2b3c;
  undefined4 local_2b38 [4];
  undefined4 local_2b28;
  undefined4 local_2b24;
  undefined4 local_2b20;
  undefined4 local_2b1c;
  /* Same undersized-buffer defect as auStack_c148 below (issue #64), same function, a sibling call
   * site: declared 76 bytes but memset to 0xbc=188 (0x2b18-0xbc=0x2a5c, exactly this buffer's own
   * sibling declared right after it - confirming the real size). Enlarged to match. */
  undefined1 auStack_2b18 [0xbc];
  uint *local_2acc;
  int local_2ac8;
  undefined4 local_2ac0 [8];
  undefined4 local_2aa0 [16];
  int local_2a60;
  /* Same undersized-buffer defect as auStack_9d1c below (issue #64), same function, a sibling call
   * site: declared 72 bytes but memset to 0x674=1652. Enlarged to match. */
  undefined1 auStack_2a5c [0x674];
  undefined4 local_2a14;
  undefined4 local_2a10;
  uint local_2a08;
  uint local_2a04;
  int local_29fc;
  int local_29f8;
  uint ******local_2958;
  undefined1 uStack_2954;
  char local_2953 [3];
  byte abStack_2950 [764];
  uint ******local_2654;
  char local_2650 [576];
  undefined4 local_2410;
  uint *local_240c;
  int *local_2408;
  uint ******local_2400;
  uint ******local_23fc;
  uint ******local_23ec;
  uint ******scanState;
  undefined4 local_23e4;
  uint usedTexcoordMask;
  undefined4 local_23dc [4];
  undefined4 local_23cc;
  undefined4 local_23c8;
  undefined4 local_23c4;
  undefined4 local_23c0;
  undefined4 local_23bc [4];
  undefined4 local_23ac;
  undefined4 local_23a8;
  undefined4 local_23a4;
  undefined4 local_23a0;
  int local_239c;
  uint ******local_2398;
  undefined4 local_2384;
  uint local_2378;
  uint local_2374;
  int aiStack_22f0 [32];
  uint local_2270;
  uint local_2260 [6];
  undefined1 auStack_2248 [8];
  float local_2240 [1024];
  uint local_1240 [8];
  int aiStack_1220 [1024];
  uint *******local_220;
  int local_218;
  int local_1f8 [5];
  uint local_1e4;
  int local_1dc;
  uint local_1d8;
  int local_1d4;
  int local_1d0;
  int local_1cc;
  int local_1c8;
  undefined4 local_1c4;
  undefined4 local_1c0;
  undefined4 local_1bc;
  undefined4 local_1b8;
  uint *******local_1b4;
  undefined4 local_1b0 [16];
  undefined4 local_170 [16];
  uint auStack_130 [17];
  int local_ec;
  uint local_d8;
  uint local_d4;
  undefined4 local_cc;
  int local_c8;
  uint local_c4;
  undefined4 local_7c;
  longlong local_78;
  uint ******local_70;
  uint *local_6c;
  uint ******local_60;
  
  zeroFillCount = 8;
  zeroFillOffset = 0;
  do {
    *(undefined4 *)((int)local_2b38 + zeroFillOffset) = 0xffffffff;
    *(undefined4 *)((int)local_2b58 + zeroFillOffset) = 0xffffffff;
    zeroFillOffset = zeroFillOffset + 4;
    zeroFillCount = zeroFillCount + -1;
  } while (zeroFillCount != 0);
  scanTokenWord = programBody;
  scratchBlock = _malloc(0x400);
  ctxWord44 = *(uint *)(ctx + 0x44);
  local_218 = 0;
  if ((ctxWord44 & 0x2000) == 0) {
    local_1e4 = ctxWord44 >> 0x18 & 1;
    local_1d8 = 0xffff;
  }
  else {
    local_1e4 = ctxWord44 >> 0xb & 1;
    if (local_1e4 == 0) {
      local_1d8 = 0xffff;
    }
    else {
      local_1d8 = (uint)(byte)((unsigned char *)0x000011d1)[ctx];
    }
  }
  ilTokens = (uint *)*programHeader;
  local_d8 = ctxWord44 >> 10 & 1;
  countdown = 8;
  local_23e4 = 0xffff;
  local_d4 = (uint)(byte)((unsigned char *)0x000011d2)[ctx];
  local_c4 = (uint)(programHeader[6] == 0);
  local_23c0 = local_2b1c;
  ilWordCount = programHeader[1];
  local_23c4 = local_2b20;
  local_23c8 = local_2b24;
  local_1b4 = (uint *******)0x0;
  local_ec = 0;
  local_cc = 0;
  local_7c = 0;
  local_23cc = local_2b28;
  local_23dc[3] = local_2b38[3];
  scanState = (uint ******)0x0;
  local_239c = 0;
  local_2384 = 0;
  local_23dc[2] = local_2b38[2];
  local_23dc[1] = local_2b38[1];
  local_23dc[0] = local_2b38[0];
  local_23a0 = local_2b3c;
  local_2270 = 0;
  local_1b8 = 0;
  usedTexcoordMask = 0;
  local_220 = (uint *******)0x0;
  local_1f8[0] = 0;
  local_23a8 = local_2b44;
  local_23a4 = local_2b40;
  local_1f8[1] = 0;
  local_1f8[2] = 0;
  local_1f8[3] = 0;
  local_1d4 = 0;
  local_23bc[3] = local_2b58[3];
  local_23ac = local_2b48;
  local_1d0 = 0;
  local_1cc = 0;
  local_1c8 = 0;
  local_1dc = 0;
  local_23bc[1] = local_2b58[1];
  local_1c4 = 0;
  local_1c0 = 0;
  local_1bc = 0;
  local_23bc[2] = local_2b58[2];
  cursor4 = local_2260;
  local_6c = cursor4;
  local_23bc[0] = local_2b58[0];
  do {
    *cursor4 = 0;
    cursor4[0x408] = 0;
    cursor4 = cursor4 + 1;
    countdown = countdown + -1;
  } while (countdown != 0);
  maskCursorA = local_1b0;
  countdown = 0x10;
  do {
    *maskCursorA = 0;
    maskCursorA[0x10] = 0;
    maskCursorA = maskCursorA + 1;
    countdown = countdown + -1;
  } while (countdown != 0);
  extraWords = 0;
  texExtraWords = 0;
  uVar21 = 0;
  puVar29 = ilTokens;
switchD_000c90cc_caseD_15:
  srcCursor = puVar29 + 2;
  puVar26 = srcCursor;
switchD_000c90cc_caseD_18:
  puVar29 = puVar26;
  if (puVar29 < ilTokens + ilWordCount) goto code_r0x000c90a4;
  if (local_220 != (uint *******)0x0) {
    puVar29 = (uint *)0x0;
    uVar33 = 0;
    goto LAB_000ca6bc;
  }
  extraWords = (extraWords + ilWordCount) * 4;
  local_2398 = scanState;
  if (local_239c != 0) {
    extraWords = extraWords + 0x48;
  }
  uVar33 = extraWords + texExtraWords * 4;
  extraPrologue = local_218 != 0;
  if (extraPrologue) {
    uVar33 = uVar33 + 0x14;
  }
  sizeBytes2 = uVar33;
  if ((local_1f8[0] != 0) && (sizeBytes2 = uVar33 + 0xc, extraPrologue)) {
    sizeBytes2 = uVar33 + 0x24;
  }
  uVar33 = sizeBytes2;
  if ((local_1f8[1] != 0) && (uVar33 = sizeBytes2 + 0xc, extraPrologue)) {
    uVar33 = sizeBytes2 + 0x24;
  }
  sizeBytes2 = uVar33;
  if ((local_1f8[2] != 0) && (sizeBytes2 = uVar33 + 0xc, extraPrologue)) {
    sizeBytes2 = uVar33 + 0x24;
  }
  sizeBytes3 = sizeBytes2;
  if ((local_1f8[3] != 0) && (sizeBytes3 = sizeBytes2 + 0xc, extraPrologue)) {
    sizeBytes3 = sizeBytes2 + 0x24;
  }
  if (((local_1dc != 0) && (local_1e4 != 0)) && (local_1b4 == (uint *******)0x0)) {
    sizeBytes3 = sizeBytes3 + 0x14;
  }
  if (local_ec == 1) {
    sizeBytes3 = sizeBytes3 + 0x24;
  }
  else if (local_ec == 2) {
    sizeBytes3 = sizeBytes3 + 0x30;
  }
  else if (local_ec == 3) {
    sizeBytes3 = sizeBytes3 + 0x40;
  }
  else if (local_ec == 0) goto LAB_000c99d4;
  sizeBytes3 = sizeBytes3 + 8;
  flagCursor = local_1f8;
  countdown = 4;
  do {
    if (*flagCursor != 0) {
      sizeBytes3 = sizeBytes3 + 0x2c;
    }
    flagCursor = flagCursor + 1;
    countdown = countdown + -1;
  } while (countdown != 0);
LAB_000c99d4:
  if (((local_1d0 != 0) || (local_1c8 != 0)) || (uVar33 = sizeBytes3, local_1b4 == (uint *******)0x0)) {
    if ((local_1d4 == 0) && (local_1cc != 0)) {
      sizeBytes3 = sizeBytes3 + 0xc;
    }
    uVar33 = sizeBytes3;
    if ((local_1b4 == (uint *******)0x0) && (uVar33 = sizeBytes3 + 0xc, local_d8 != 0)) {
      uVar33 = sizeBytes3 + 0x18;
    }
  }
  prologuePending = true;
  pppppppuVar20 = local_1b4;
  pppppppuVar25 = local_220;
  puVar29 = (uint *)_malloc(uVar33 + 0x10);
  *puVar29 = *ilTokens;
  srcCursor = ilTokens + 2;
  puVar29[1] = ilTokens[1];
  puVar26 = srcCursor;
  dstCursorCarry = (uint *******)(puVar29 + 2);
  goto switchD_000c9ab8_caseD_18;
code_r0x000c90a4:
  scanTokenWord = (uint *******)*puVar29;
  puVar26 = puVar29;
  switch((uint)scanTokenWord & 0xffff) {
  default:
    goto switchD_000c90cc_caseD_0;
  case 1:
  case 2:
  case 4:
  case 5:
  case 0xb:
  case 0xe:
  case 0x12:
  case 0x1e:
  case 0x25:
  case 0x26:
  case 0x2c:
  case 0x2d:
  case 0x2e:
  case 0x30:
  case 0x31:
  case 0x33:
  case 0x38:
  case 0x39:
  case 0x3a:
  case 0x3b:
  case 0x3c:
  case 0x3d:
  case 0x47:
  case 0x48:
  case 0x4a:
  case 0x4c:
  case 0x4d:
  case 0x50:
  case 0x51:
  case 0x54:
  case 0x55:
  case 0x57:
  case 0x58:
  case 0x59:
  case 0x5a:
  case 0x5c:
  case 0x62:
  case 99:
    hasDestination = 1;
    break;
  case 3:
  case 0xc:
  case 0x13:
  case 0x1f:
  case 0x20:
  case 0x22:
  case 0x23:
  case 0x41:
  case 0x44:
  case 0x45:
  case 0x46:
  case 0x49:
  case 0x4e:
  case 0x52:
  case 0x56:
  case 0x5b:
    hasDestination = 1;
    goto LAB_000c9340;
  case 6:
  case 0x10:
  case 0x27:
  case 0x28:
  case 0x29:
  case 0x2a:
  case 0x2b:
  case 0x4b:
  case 0x53:
    srcCursor = puVar29 + 1;
    puVar26 = srcCursor;
    goto switchD_000c90cc_caseD_18;
  case 7:
  case 0x11:
  case 0x34:
    hasDestination = 0;
LAB_000c9340:
    scanTokenWord = (uint *******)((int)((unsigned char *)0x0) + 2);
    srcCursor = (uint *)((int (*)())ilMarkInstructionRegistersUsed)(puVar29,hasDestination,2,&scanState);
    puVar26 = srcCursor;
    goto switchD_000c90cc_caseD_18;
  case 8:
  case 0x32:
    srcCursor = puVar29 + 2;
    puVar26 = srcCursor;
    goto switchD_000c90cc_caseD_18;
  case 9:
  case 0x1d:
    srcCursor = puVar29 + 3;
    puVar26 = srcCursor;
    goto switchD_000c90cc_caseD_18;
  case 10:
  case 0xd:
  case 0x21:
  case 0x2f:
  case 0x3f:
  case 0x40:
  case 100:
    scanTokenWord = (uint *******)((int)((unsigned char *)0x0) + 3);
    srcCursor = (uint *)((int (*)())ilMarkInstructionRegistersUsed)(puVar29,1,3,&scanState);
    puVar26 = srcCursor;
    goto switchD_000c90cc_caseD_18;
  case 0xf:
    srcCursor = puVar29 + *(ushort *)((int)puVar29 + 6) + 2;
    puVar26 = srcCursor;
    goto switchD_000c90cc_caseD_18;
  case 0x14:
    srcCursor = puVar29 + 3;
    puVar26 = srcCursor;
    goto switchD_000c90cc_caseD_18;
  case 0x15:
    goto switchD_000c90cc_caseD_15;
  case 0x16:
    srcCursor = puVar29 + 1;
    scanTokenWord = &scanState;
    uVar33 = puVar29[1];
    puVar6 = (undefined *)(uVar33 & 0x3f0000);
    ((int (*)())FUN_000c8600)(uVar33 & 0xffff,uVar33 >> 0x10 & 0x3f,scanTokenWord,0,0);
    if (puVar6 == ((unsigned char *)0x00160000U)) {
      local_239c = 1;
    }
    else if (puVar6 == (undefined *)0x110000) {
      usedTexcoordMask = 1 << (uVar33 & 0x3f) | usedTexcoordMask;
    }
    else if (puVar6 == (undefined *)0xf0000) {
      uVar21 = uVar21 | 1 << (uVar33 & 0x3f);
    }
    else if (puVar6 == (undefined *)0x100000) {
      local_2384 = 1;
    }
    goto LAB_000c9564;
  case 0x18:
    goto switchD_000c90cc_caseD_18;
  case 0x19:
    scanTokenCopy = (uint)scanTokenWord >> 0x1b & 3;
    uVar33 = (uint)scanTokenWord >> 0x10 & 0xff;
    if ((scanTokenCopy == 2) || ((scanTokenCopy == 0 && (auStack_130[uVar33] == 2)))) {
      local_2270 = 1 << ((uint)scanTokenWord >> 0x10 & 0x3f) | local_2270;
    }
    scanTokenWord = (uint *******)((uint)scanTokenWord >> 0x18 & 7);
    ilRecordInputSemantic(&scanState,uVar33,scanTokenWord);
    srcCursor = srcCursor + 1;
    puVar26 = srcCursor;
    goto switchD_000c90cc_caseD_18;
  case 0x1a:
    srcCursor = puVar29 + 1;
    if ((int)scanTokenWord < 0) {
      srcCursor = puVar29 + 2;
    }
LAB_000c9564:
    srcCursor = srcCursor + 1;
    puVar26 = srcCursor;
    goto switchD_000c90cc_caseD_18;
  case 0x1c:
    srcCursor = puVar29 + 1;
    scanTokenCopy = puVar29[1];
    uVar33 = scanTokenCopy >> 0x10 & 0x3f;
    if (uVar33 == 1) {
      scanTokenWord = &local_2b68;
      local_2b68 = (uint ******)puVar29[2];
      local_2b64 = puVar29[3];
      local_2b60 = puVar29[4];
      srcCursor = puVar29 + 6;
      local_2b5c = puVar29[5];
      ilRecordDefinedConstantPrimary(&scanState,scanTokenCopy & 0xffff,scanTokenWord);
      puVar26 = srcCursor;
    }
    else {
      puVar26 = srcCursor;
      if (uVar33 == 2) {
        scanTokenWord = &local_2b68;
        local_2b68 = (uint ******)puVar29[2];
        local_2b64 = puVar29[3];
        local_2b60 = puVar29[4];
        srcCursor = puVar29 + 6;
        local_2b5c = puVar29[5];
        ilRecordDefinedConstantSecondary(&scanState,scanTokenCopy & 0xffff,scanTokenWord);
        puVar26 = srcCursor;
      }
    }
    goto switchD_000c90cc_caseD_18;
  case 0x24:
    scanTokenWord = (uint *******)((int)((unsigned char *)0x0) + 2);
    extraWords = extraWords + 5;
    srcCursor = (uint *)((int (*)())ilMarkInstructionRegistersUsed)(puVar29,1,2,&scanState);
    puVar26 = srcCursor;
    goto switchD_000c90cc_caseD_18;
  case 0x35:
    scanTokenWord = &scanState;
    srcCursor = puVar29 + 2;
    local_2b8c[0] = (uint ******)puVar29[1];
    ((int (*)())ilMarkOperandRegisterUsed)(local_2b8c,auStack_2b80,scanTokenWord);
    puVar26 = srcCursor;
    goto switchD_000c90cc_caseD_18;
  case 0x37:
    scanTokenWord = (uint *******)((int)((unsigned char *)0x0) + 1);
    srcCursor = (uint *)((int (*)())ilMarkInstructionRegistersUsed)(puVar29,0,1,&scanState);
    local_1bc = 1;
    puVar26 = srcCursor;
    goto switchD_000c90cc_caseD_18;
  case 0x3e:
    hasDestination = 0;
    break;
  case 0x5d:
    srcCursor = puVar29 + 2;
    local_c8 = local_c8 + 1;
    uVar33 = puVar29[1];
    scanTokenCopy = *puVar29;
    if ((((scanTokenCopy & 0xc000000) == 0x4000000) ||
        (((scanTokenCopy & 0xc000000) == 0x8000000 &&
         ((1 << (*(byte *)((int)puVar29 + 1) & 0x3f) & local_2374) != 0)))) &&
       (local_2378 << (*(byte *)((int)puVar29 + 1) & 0x3f) != 0)) {
      texExtraWords = texExtraWords + 0x1b;
      local_2374 = 1 << (*(byte *)((int)puVar29 + 1) & 0x3f) | local_2374;
      scanTokenCopy = *puVar29;
    }
    if ((int)scanTokenCopy < 0) {
      srcCursor = puVar29 + 3;
      scanTokenCopy = *puVar29;
    }
    if ((scanTokenCopy & 0x40000000) != 0) {
      srcCursor = srcCursor + 1;
    }
    if ((uVar33 & 0x400000) != 0) {
      calleeSavedR21 = *srcCursor;
      srcCursor = srcCursor + 1;
    }
    scanTokenWord = &scanState;
    ((int (*)())FUN_000c8600)(uVar33 & 0xffff,uVar33 >> 0x10 & 0x3f,scanTokenWord,calleeSavedR21,uVar33 >> 0x16 & 1);
    if ((1 << (*(byte *)((int)puVar29 + 1) & 0x3f) & local_2378) != 0) {
      texExtraWords = texExtraWords + 4;
    }
    local_2b74 = (uint ******)*srcCursor;
    puVar29 = srcCursor + 1;
    if (((uint)local_2b74 & 0x400000) != 0) {
      local_2bb0 = (uint ******)srcCursor[1];
      puVar29 = srcCursor + 2;
    }
    srcCursor = puVar29;
    ((int (*)())ilMarkOperandRegisterUsed)(&local_2b74,&local_2bb0,scanTokenWord);
    puVar26 = srcCursor;
    goto switchD_000c90cc_caseD_18;
  case 0x5e:
    srcCursor = puVar29 + 2;
    local_c8 = local_c8 + 1;
    uVar33 = puVar29[1];
    scanTokenCopy = *puVar29;
    if ((((scanTokenCopy & 0xc000000) == 0x4000000) ||
        (((scanTokenCopy & 0xc000000) == 0x8000000 &&
         ((1 << (*(byte *)((int)puVar29 + 1) & 0x3f) & local_2374) != 0)))) &&
       (local_2378 << (*(byte *)((int)puVar29 + 1) & 0x3f) != 0)) {
      texExtraWords = texExtraWords + 0x1b;
      local_2374 = 1 << (*(byte *)((int)puVar29 + 1) & 0x3f) | local_2374;
      scanTokenCopy = *puVar29;
    }
    if ((int)scanTokenCopy < 0) {
      srcCursor = puVar29 + 3;
      scanTokenCopy = *puVar29;
    }
    if ((scanTokenCopy & 0x40000000) != 0) {
      srcCursor = srcCursor + 1;
    }
    if ((uVar33 & 0x400000) != 0) {
      calleeSavedR20 = *srcCursor;
      srcCursor = srcCursor + 1;
    }
    scanTokenWord = &scanState;
    ((int (*)())FUN_000c8600)(uVar33 & 0xffff,uVar33 >> 0x10 & 0x3f,scanTokenWord,calleeSavedR20,uVar33 >> 0x16 & 1);
    if ((1 << (*(byte *)((int)puVar29 + 1) & 0x3f) & local_2378) != 0) {
      texExtraWords = texExtraWords + 4;
    }
    local_2bb0 = (uint ******)*srcCursor;
    puVar29 = srcCursor + 1;
    if (((uint)local_2bb0 & 0x400000) != 0) {
      local_2ba4 = (uint *******)srcCursor[1];
      puVar29 = srcCursor + 2;
    }
    local_2bac[0] = *puVar29;
    srcCursor = puVar29 + 1;
    if ((local_2bac[0] & 0x400000) != 0) {
      local_2ba0[0] = puVar29[1];
      srcCursor = puVar29 + 2;
    }
    ((int (*)())ilMarkOperandRegisterUsed)(&local_2bb0,&local_2ba4,scanTokenWord);
    ((int (*)())ilMarkOperandRegisterUsed)(local_2bac,local_2ba0,scanTokenWord);
    puVar26 = srcCursor;
    goto switchD_000c90cc_caseD_18;
  }
  scanTokenWord = (uint *******)((int)((unsigned char *)0x0) + 1);
  srcCursor = (uint *)((int (*)())ilMarkInstructionRegistersUsed)(puVar29,hasDestination,1,&scanState);
  puVar26 = srcCursor;
  goto switchD_000c90cc_caseD_18;
switchD_000c9ab8_caseD_18:
  dstCursor = dstCursorCarry;
  puVar19 = puVar26;
  dstCursorCarry = dstCursor;
  if (ilTokens + ilWordCount <= puVar19) {
    uVar33 = uVar33 >> 2;
    usedTexcoordMask = uVar21 | usedTexcoordMask;
LAB_000ca6bc:
    if (local_220 != (uint *******)0x0) {
      return local_220;
    }
    programBody[0x1587] = (uint ******)0x0;
    inputMaskBase = 0;
    programBody[0x1589] = (uint ******)0x0;
    programBody[0x1502] = (uint ******)0x0;
    scanTokenWord = programBody + 0x1000;
    maskSource = auStack_2248;
    pppppppuVar20 = programBody + 0x1004;
    inputMaskCursor = local_6c;
    do {
      dstCursorCarry = pppppppuVar20 + 1;
      puVar26 = (uint *)(maskSource + 8);
      pppppppuVar25 = scanTokenWord + 1;
      countdown = 0x20;
      loopIndex = 0;
      do {
        if ((1 << (loopIndex & 0x3f) & *inputMaskCursor) == 0) {
          *(undefined1 *)dstCursorCarry = 0;
        }
        else {
          *pppppppuVar25 = (uint ******)*puVar26;
          pppppppuVar25[1] = (uint ******)puVar26[1];
          pppppppuVar25[2] = (uint ******)puVar26[2];
          copyWord = (uint ******)puVar26[3];
          *(undefined1 *)(pppppppuVar25 + 4) = 1;
          pppppppuVar25[3] = copyWord;
          if (programBody[0x1502] < (uint ******)(inputMaskBase + loopIndex)) {
            programBody[0x1502] = (uint ******)(inputMaskBase + loopIndex);
          }
        }
        loopIndex = loopIndex + 1;
        dstCursorCarry = dstCursorCarry + 5;
        puVar26 = puVar26 + 4;
        pppppppuVar25 = pppppppuVar25 + 5;
        countdown = countdown + -1;
      } while (countdown != 0);
      prologuePending = inputMaskBase != 0xe0;
      pppppppuVar20 = pppppppuVar20 + 0xa0;
      maskSource = maskSource + 0x200;
      scanTokenWord = scanTokenWord + 0xa0;
      inputMaskCursor = inputMaskCursor + 1;
      inputMaskBase = inputMaskBase + 0x20;
    } while (prologuePending);
    if ((int)programBody[0x1587] < (int)programBody[0x1502]) {
      programBody[0x1587] = programBody[0x1502];
    }
    _memset(auStack_2b18,0,0xbc);
    _memset(auStack_2a5c,0,0x674);
    scratchAllocation = (**(code **)(ctx + 0xc))(*(undefined4 *)(ctx + 0x1870));
    local_2ac8 = uVar33 << 2;
    cursor3 = local_23dc;
    maskCopyDst = local_2ac0;
    countdown = 8;
    local_2a60 = scratchAllocation;
    do {
      maskWord = *cursor3;
      maskWordHigh = cursor3[8];
      cursor3 = cursor3 + 1;
      *maskCopyDst = maskWord;
      maskCopyDst[8] = maskWordHigh;
      maskCopyDst = maskCopyDst + 1;
      countdown = countdown + -1;
    } while (countdown != 0);
    local_2410 = 0x400;
    local_2acc = puVar29;
    local_240c = (uint *)_malloc(0x40000);
    local_2408 = (int *)_malloc(0x40000);
    local_2a10 = 0x40;
    local_29f8 = _malloc(0x900);
    local_2a14 = 0x40;
    local_29fc = _malloc(0x900);
    outputNumber = '\0';
    outputEntryCursor = local_2953;
    countdown = 0x40;
    do {
      *outputEntryCursor = outputNumber;
      outputEntryCursor = outputEntryCursor + 0xc;
      outputNumber = outputNumber + '\x01';
      countdown = countdown + -1;
    } while (countdown != 0);
    compilerHandle = *(int *)(ctx + 0x186c);
    if (compilerHandle == 0) {
      FUN_000c6ff0(ctx,1);
      compilerHandle = *(int *)(ctx + 0x186c);
    }
    compilerHandle = ((int (*)())FUN_000cd1b0)(compilerHandle,auStack_2b18,auStack_2a5c);
    if (compilerHandle != 0) {
      return (uint *******)((int)((unsigned char *)0x0) + 2);
    }
    programBody[0x1000] = local_2400;
    if (local_2400 != (uint ******)0x0) {
      hwWordSource = local_240c;
      scanTokenWord = programBody;
      if (local_2400 == (uint ******)0x0) {
        local_2400 = (uint ******)0x1;
      }
      do {
        copyWord = (uint ******)*hwWordSource;
        copyWord1 = (uint ******)hwWordSource[1];
        copyWord2 = (uint ******)hwWordSource[2];
        copyWord3 = (uint ******)hwWordSource[3];
        hwWordSource = hwWordSource + 4;
        *scanTokenWord = copyWord;
        scanTokenWord[1] = copyWord1;
        scanTokenWord[2] = copyWord2;
        scanTokenWord[3] = copyWord3;
        scanTokenWord = scanTokenWord + 4;
        local_2400 = (uint ******)((int)local_2400 - 1);
      } while (local_2400 != (uint ******)0x0);
    }
    maxInputRegister = programBody[0x1502];
    if (maxInputRegister < local_23ec) {
      programBody[0x1502] = local_23ec;
      programBody[0x1501] = (uint ******)((int)local_23ec + 1);
      maxInputRegister = local_23ec;
    }
    else {
      programBody[0x1501] = (uint ******)((int)maxInputRegister + 1);
    }
    if ((uint ******)0xff < maxInputRegister) {
      programBody[0x1502] = (uint ******)0xff;
    }
    if ((uint ******)0x100 < programBody[0x1501]) {
      programBody[0x1501] = (uint ******)0x100;
    }
    if (local_2a04 == 0) goto LAB_000caa4c;
    uVar33 = 0;
    recordOffset = 0;
    uVar21 = local_2a04;
    do {
      dclRecord = recordOffset + local_29f8;
      if (*(int *)(dclRecord + 8) == 0x16) {
        dclRegisterIndex = *(uint *)(dclRecord + 0x10);
        recordRegister = *(int *)(recordOffset + local_29f8);
        maskWordIndex = ((int)dclRegisterIndex >> 5) + (uint)((int)dclRegisterIndex < 0 && (dclRegisterIndex & 0x1f) != 0);
        if ((1 << (dclRegisterIndex + maskWordIndex * -0x20 & 0x3f) & local_2260[maskWordIndex]) == 0) goto LAB_000caa2c;
        selectorSlot = ilSelectorOneToThreeOrZero(*(undefined4 *)(dclRecord + 4));
        dclRecord = ilSelectorOneToThreeOrZero(*(undefined4 *)(dclRecord + 0xc));
        local_78 = (longlong)(int)local_2240[dclRegisterIndex * 4 + dclRecord];
        aiStack_1220[recordRegister * 4 + selectorSlot] = (int)local_2240[dclRegisterIndex * 4 + dclRecord];
      }
      else if (*(int *)(dclRecord + 8) == 0x18) {
LAB_000caa2c:
        ((int (*)())ilPushDclRecord)(programBody + 0x1589,dclRecord);
        uVar21 = local_2a04;
      }
      uVar33 = uVar33 + 1;
      recordOffset = recordOffset + 0x24;
      if (uVar21 <= uVar33) {
LAB_000caa4c:
        if (local_2a08 != 0) {
          loopIndex2 = 0;
          recordOffset = 0;
          uVar21 = local_2a08;
          do {
            defRecord = recordOffset + local_29fc;
            if (*(int *)(defRecord + 8) == 1) {
              defIndex = *(uint *******)(recordOffset + local_29fc);
              selectorSlot = ilSelectorOneToThreeOrZero(*(undefined4 *)(defRecord + 4));
              defValue = *(uint *******)(defRecord + 0x14);
              *(undefined1 *)(programBody + (int)(((unsigned char *)0x00001005) + (int)defIndex * 5)) = 1;
              programBody[(int)(((unsigned char *)0x00001001) + (int)defIndex * 5 + selectorSlot)] = defValue;
              uVar21 = local_2a08;
              if (programBody[0x1502] < defIndex) {
                programBody[0x1502] = defIndex;
              }
            }
            loopIndex2 = loopIndex2 + 1;
            recordOffset = recordOffset + 0x24;
          } while (loopIndex2 < uVar21);
        }
        outputKindFlags = (uint ******)0x0;
        *(undefined1 *)(programBody + 0x1507) = 0;
        programBody[0x1506] = (uint ******)0x0;
        programBody[0x151d] = (uint ******)0x0;
        programBody[0x151e] = (uint ******)0x0;
        programBody[0x1503] = local_2958;
        programBody[0x1504] = local_2654;
        programBody[0x1505] = local_23fc;
        programBody[0x1588] = (uint ******)0x0;
        if (local_2654 == (uint ******)0x0) {
          outputKindFlags = programBody[0x151d];
        }
        else {
          outputKindCursor = local_2650;
          if (local_2654 == (uint ******)0x0) {
            local_2654 = (uint ******)0x1;
          }
          do {
            outputKind = *outputKindCursor;
            if (outputKind == '\x01') {
              outputKindFlags = (uint ******)((uint)outputKindFlags | 0x10000);
              programBody[0x151d] = outputKindFlags;
            }
            else if (outputKind == '\0') {
              outputKindFlags = (uint ******)((uint)outputKindFlags | 1);
              *(undefined1 *)(programBody + 0x1507) = 1;
              programBody[0x151d] = outputKindFlags;
            }
            else if (outputKind == '\x02') {
              outputKindArg = outputKindCursor[1];
              if (outputKindArg == '\x01') {
                outputKindFlags = (uint ******)((uint)outputKindFlags | 4);
                programBody[0x151d] = outputKindFlags;
              }
              else if (outputKindArg == '\0') {
                outputKindFlags = (uint ******)((uint)outputKindFlags | 2);
                programBody[0x151d] = outputKindFlags;
              }
              else if (outputKindArg == '\x02') {
                outputKindFlags = (uint ******)((uint)outputKindFlags | 8);
                programBody[0x151d] = outputKindFlags;
              }
              else if (outputKindArg == '\x03') {
                outputKindFlags = (uint ******)((uint)outputKindFlags | 0x10);
                programBody[0x151d] = outputKindFlags;
              }
            }
            else if (outputKind == '\x05') {
              programBody[0x151e] =
                   (uint ******)(4 << ((uint)(byte)outputKindCursor[1] * 3 & 0x3f) | (uint)programBody[0x151e]);
              programBody[0x1588] =
                   (uint ******)(4 << ((uint)(byte)outputKindCursor[1] * 3 & 0x3f) | (uint)programBody[0x1588]);
            }
            outputKindCursor = outputKindCursor + 0xc;
            local_2654 = (uint ******)((int)local_2654 - 1);
          } while (local_2654 != (uint ******)0x0);
        }
        if (((uint)outputKindFlags & 0x18) != 0) {
          programBody[0x151d] = (uint ******)((uint)outputKindFlags | 0x1c);
        }
        outputTypeCursor = programBody + 0x1571;
        countdown = 0x16;
        do {
          *outputTypeCursor = (uint ******)0x16;
          outputTypeCursor = outputTypeCursor + 1;
          countdown = countdown + -1;
        } while (countdown != 0);
        outputCount = programBody[0x1503];
        if (outputCount != (uint ******)0x0) {
          outputEntryBase = &uStack_2954;
          remainingEntries = outputCount;
          if (outputCount == (uint ******)0x0) {
            remainingEntries = (uint ******)0x1;
          }
          do {
            pbVar2 = outputEntryBase + 1;
            pbVar5 = outputEntryBase + (int)(abStack_2950 + -(int)&uStack_2954);
            outputEntryBase = outputEntryBase + 0xc;
            programBody[(int)(((unsigned char *)0x00001571) + *pbVar2)] = (uint ******)(uint)*pbVar5;
            remainingEntries = (uint ******)((int)remainingEntries + -1);
          } while (remainingEntries != (uint ******)0x0);
        }
        if (outputCount < (uint ******)0x2) {
          if (outputCount == (uint ******)0x0) {
            programBody[0x1571] = (uint ******)0x0;
            programBody[0x1572] = (uint ******)0x1;
          }
          else if (programBody[0x1571] == (uint ******)0x0) {
            programBody[0x1572] = (uint ******)0x1;
          }
          else {
            programBody[0x1572] = (uint ******)0x0;
          }
        }
        mapEntryCount = *local_2408;
        programBody[0x1520] = (uint ******)0x0;
        programBody[0x151f] = (uint ******)(uint)(mapEntryCount != 0);
        if (((uint ******)(uint)(mapEntryCount != 0) != (uint ******)0x0) &&
           (mapEntryCount = *local_2408, 0 < mapEntryCount)) {
          outputMapCursor = programBody + 0x1531;
          mapIndex = (uint ******)0x0;
          do {
            outputMapCursor[0x20] = (uint ******)0x0;
            *outputMapCursor = (uint ******)0x0;
            outputMapCursor[0x10] = (uint ******)0x0;
            if (local_2408[(int)mapIndex * 7 + 3] == 0x3e) {
              programBody[0x1520] =
                   (uint ******)(2 << (((uint)mapIndex & 0x1f) << 1) | (uint)programBody[0x1520]);
              *(char *)((int)programBody + (int)mapIndex * 4 + 0x5547) =
                   (char)aiStack_1220[local_2408[(int)mapIndex * 7 + 4] * 4 + 1];
              *(char *)((int)programBody + (int)mapIndex * 4 + 0x5546) =
                   (char)aiStack_1220[local_2408[(int)mapIndex * 7 + 4] * 4 + 2];
              *(short *)((int)programBody + (int)mapIndex * 4 + 0x54c6) =
                   (short)local_2408[(int)mapIndex * 7 + 5];
              *(short *)(programBody + (int)(((unsigned char *)0x00001531) + (int)mapIndex)) =
                   (short)aiStack_1220[local_2408[(int)mapIndex * 7 + 4] * 4];
              *(short *)((int)programBody + (int)mapIndex * 4 + 0x5506) =
                   (short)local_2408[(int)mapIndex * 7 + 7];
              *(short *)(programBody + (int)(((unsigned char *)0x00001541) + (int)mapIndex)) =
                   (short)local_2408[(int)mapIndex * 7 + 5] + 1;
              programBody[(int)(((unsigned char *)0x00001561) + local_2408[(int)mapIndex * 7 + 4])] = mapIndex;
            }
            mapIndex = (uint ******)((int)mapIndex + 1);
            outputMapCursor = outputMapCursor + 1;
            mapEntryCount = mapEntryCount + -1;
          } while (mapEntryCount != 0);
        }
        if (local_240c != (uint *)0x0) {
          _free(local_240c);
        }
        if (scratchBlock != 0) {
          _free(scratchBlock);
        }
        if (local_2408 != (int *)0x0) {
          _free(local_2408);
        }
        if (puVar29 != (uint *)0x0) {
          _free(puVar29);
        }
        if (scratchAllocation != 0) {
          _free(scratchAllocation);
        }
        if (local_29f8 != 0) {
          _free(local_29f8);
        }
        if (local_29fc != 0) {
          _free(local_29fc);
        }
        return (uint *******)0x0;
      }
    } while( true );
  }
  tokenWord = (uint ******)*puVar19;
  scanTokenCopy = (uint)tokenWord & 0xffff;
  if (100 < scanTokenCopy) {
switchD_000c90cc_caseD_0:
                    
    _exit(0);
  }
  opcodeTimes4 = scanTokenCopy * 4;
  puVar26 = puVar19;
  switch(scanTokenCopy) {
  case 0:
  case 0x17:
  case 0x1b:
  case 0x36:
  case 0x42:
  case 0x43:
  case 0x4f:
  case 0x5f:
  case 0x60:
  case 0x61:
    goto switchD_000c90cc_caseD_0;
  default:
    if (prologuePending) {
      prologuePending = false;
      dstCursor = (uint *******)
                   ((int (*)())ilEmitPrologue)(dstCursor,&scanState,scanTokenWord,puVar19,puVar19,pppppppuVar20,
                                opcodeTimes4,pppppppuVar25);
    }
    scanTokenWord = (uint *******)((int)((unsigned char *)0x0) + 1);
    srcCursor = (uint *)((int (*)())ilCopyInstructionRemapped)(&dstCursor,&srcCursor,1,1,&scanState);
    puVar26 = srcCursor;
    dstCursorCarry = dstCursor;
    goto switchD_000c9ab8_caseD_18;
  case 3:
  case 0xc:
  case 0x13:
  case 0x1f:
  case 0x20:
  case 0x22:
  case 0x23:
  case 0x24:
  case 0x41:
  case 0x44:
  case 0x45:
  case 0x46:
  case 0x49:
  case 0x4e:
  case 0x52:
  case 0x56:
  case 0x5b:
    if (prologuePending) {
      prologuePending = false;
      dstCursor = (uint *******)
                   ((int (*)())ilEmitPrologue)(dstCursor,&scanState,scanTokenWord,puVar19,puVar19,pppppppuVar20,
                                opcodeTimes4,pppppppuVar25);
    }
    scanTokenWord = (uint *******)((int)((unsigned char *)0x0) + 1);
    srcCursor = (uint *)((int (*)())ilCopyInstructionRemapped)(&dstCursor,&srcCursor,1,2,&scanState);
    puVar26 = srcCursor;
    dstCursorCarry = dstCursor;
    goto switchD_000c9ab8_caseD_18;
  case 6:
  case 0x10:
  case 0x27:
  case 0x29:
  case 0x2a:
  case 0x2b:
  case 0x4b:
  case 0x53:
    srcCursor = puVar19 + 1;
    *dstCursor = tokenWord;
    puVar26 = srcCursor;
    dstCursorCarry = dstCursor + 1;
    goto switchD_000c9ab8_caseD_18;
  case 7:
  case 0x11:
  case 0x34:
    scanTokenWord = (uint *******)0x0;
    srcCursor = (uint *)((int (*)())ilCopyInstructionRemapped)(&dstCursor,&srcCursor,0,2,&scanState);
    puVar26 = srcCursor;
    dstCursorCarry = dstCursor;
    goto switchD_000c9ab8_caseD_18;
  case 8:
  case 0x15:
  case 0x16:
  case 0x32:
    *dstCursor = tokenWord;
    srcCursor = puVar19 + 2;
    dstCursor[1] = (uint ******)puVar19[1];
    puVar26 = srcCursor;
    dstCursorCarry = dstCursor + 2;
    goto switchD_000c9ab8_caseD_18;
  case 9:
  case 0x14:
  case 0x1d:
    *dstCursor = tokenWord;
    dstCursor[1] = (uint ******)puVar19[1];
    srcCursor = puVar19 + 3;
    dstCursor[2] = (uint ******)puVar19[2];
    puVar26 = srcCursor;
    pppppppuVar25 = dstCursor + 3;
    dstCursorCarry = dstCursor + 3;
    goto switchD_000c9ab8_caseD_18;
  case 10:
  case 0xd:
  case 0x21:
  case 0x2f:
  case 0x3f:
  case 0x40:
  case 100:
    if (prologuePending) {
      prologuePending = false;
      dstCursor = (uint *******)
                   ((int (*)())ilEmitPrologue)(dstCursor,&scanState,scanTokenWord,puVar19,puVar19,pppppppuVar20,
                                opcodeTimes4,pppppppuVar25);
    }
    scanTokenWord = (uint *******)((int)((unsigned char *)0x0) + 1);
    srcCursor = (uint *)((int (*)())ilCopyInstructionRemapped)(&dstCursor,&srcCursor,1,3,&scanState);
    puVar26 = srcCursor;
    dstCursorCarry = dstCursor;
    goto switchD_000c9ab8_caseD_18;
  case 0xf:
    srcCursor = puVar19 + 2;
    *dstCursor = tokenWord;
    dstCursor[1] = (uint ******)puVar19[1];
    dstCursorCarry = dstCursor + 2;
    for (copyWordCount = (uint)*(ushort *)((int)puVar19 + 6); puVar26 = srcCursor, copyWordCount != 0;
        copyWordCount = copyWordCount - 1) {
      copyWord = (uint ******)*srcCursor;
      srcCursor = srcCursor + 1;
      *dstCursorCarry = copyWord;
      dstCursorCarry = dstCursorCarry + 1;
    }
  case 0x18:
    goto switchD_000c9ab8_caseD_18;
  case 0x19:
    srcCursor = puVar19 + 1;
    if (((uint)tokenWord & 0x18000000) == 0) {
      inputKind = *(uint *)((int)auStack_130 + ((uint)tokenWord >> 0xe & 0x3fc));
      if (inputKind != 2) {
        inputKind = 1;
      }
      tokenWord = (uint ******)((inputKind & 3) << 0x1b | (uint)tokenWord & 0xe7ffffff);
    }
    *dstCursor = tokenWord;
    puVar26 = srcCursor;
    dstCursorCarry = dstCursor + 1;
    goto switchD_000c9ab8_caseD_18;
  case 0x1a:
    srcCursor = puVar19 + 1;
    *dstCursor = tokenWord;
    nextDstCursorB = dstCursor + 1;
    if ((int)tokenWord < 0) {
      copyWord = (uint ******)*srcCursor;
      srcCursor = puVar19 + 2;
      dstCursor[1] = copyWord;
      nextDstCursorB = dstCursor + 2;
    }
    dstCursor = nextDstCursorB;
    copyWord = (uint ******)*srcCursor;
    srcCursor = srcCursor + 1;
    *dstCursor = copyWord;
    puVar26 = srcCursor;
    pppppppuVar25 = dstCursorCarry;
    dstCursorCarry = dstCursor + 1;
    goto switchD_000c9ab8_caseD_18;
  case 0x1c:
    srcCursor = puVar19 + 1;
    scanTokenWord = dstCursor + 1;
    *dstCursor = tokenWord;
    puVar26 = srcCursor;
    dstCursorCarry = scanTokenWord;
    if ((puVar19[1] >> 0x10 & 0x3f) - 1 < 2) {
      dstCursor[1] = (uint ******)puVar19[1];
      pppppppuVar20 = dstCursor + 6;
      dstCursor[2] = (uint ******)puVar19[2];
      dstCursor[3] = (uint ******)puVar19[3];
      dstCursor[4] = (uint ******)puVar19[4];
      srcCursor = puVar19 + 6;
      dstCursor[5] = (uint ******)puVar19[5];
      puVar26 = srcCursor;
      pppppppuVar25 = dstCursor + 5;
      dstCursorCarry = pppppppuVar20;
    }
    goto switchD_000c9ab8_caseD_18;
  case 0x28:
    srcCursor = puVar19 + 1;
    prologueDst = (undefined4 *)
              ((int (*)())FUN_000c7930)(dstCursor,&scanState,scanTokenWord,puVar19,srcCursor,pppppppuVar20,
                           opcodeTimes4);
    *prologueDst = tokenWord;
    puVar26 = srcCursor;
    dstCursorCarry = (uint *******)(prologueDst + 1);
    goto switchD_000c9ab8_caseD_18;
  case 0x35:
    scanTokenWord = &scanState;
    *dstCursor = tokenWord;
    srcCursor = puVar19 + 2;
    local_2b8c[0] = (uint ******)puVar19[1];
    dstCursor = dstCursor + 1;
    ((int (*)())ilRemapSourceOperandRegister)(local_2b8c,auStack_2b80,scanTokenWord);
    *dstCursor = local_2b8c[0];
    puVar26 = srcCursor;
    dstCursorCarry = dstCursor + 1;
    goto switchD_000c9ab8_caseD_18;
  case 0x37:
  case 0x3e:
    scanTokenWord = (uint *******)0x0;
    break;
  case 0x3b:
    scanTokenWord = (uint *******)((int)((unsigned char *)0x0) + 1);
    break;
  case 0x5d:
    if (prologuePending) {
      prologuePending = false;
      dstCursor = (uint *******)
                   ((int (*)())ilEmitPrologue)(dstCursor,&scanState,scanTokenWord,puVar19,puVar19,pppppppuVar20,
                                opcodeTimes4,pppppppuVar25);
      puVar19 = srcCursor;
    }
    texTokenWord = (uint ******)*puVar19;
    cursor = puVar19 + 1;
    tokenUpper = (uint)texTokenWord >> 0x10;
    texUnit = tokenUpper & 0xff;
    hasSecondWord = ((uint)texTokenWord & 0x80000000) != 0;
    if (hasSecondWord) {
      cursor = puVar19 + 2;
      ppppppuVar15 = (uint ******)puVar19[1];
    }
    else {
      ppppppuVar15 = (uint ******)0x0;
    }
    hasOptionalWord = ((uint)texTokenWord >> 0x1e & 1) != 0;
    if (hasOptionalWord) {
      texOptionalWord = (uint ******)*cursor;
      cursor = cursor + 1;
    }
    else {
      texOptionalWord = (uint ******)0x0;
    }
    local_2ba4 = (uint *******)*cursor;
    puVar19 = cursor + 1;
    if (((uint)local_2ba4 & 0x400000) != 0) {
      puVar19 = cursor + 2;
      calleeSavedR15 = (uint ******)cursor[1];
    }
    local_2b74 = (uint ******)*puVar19;
    srcCursor = puVar19 + 1;
    if (((uint)local_2b74 & 0x400000) != 0) {
      local_2b98 = (uint ******)puVar19[1];
      srcCursor = puVar19 + 2;
    }
    texModeBits = (uint)texTokenWord & 0xc000000;
    if (texModeBits == 0x4000000) {
LAB_000ca0e4:
      if (local_2378 << (tokenUpper & 0x3f) == 0) {
        local_70 = (uint ******)&local_2b74;
        projectiveFlag = (uint *******)0x0;
        unitBit = 1 << (tokenUpper & 0x3f);
        texSourceExtraPtr = (uint ******)&local_2b98;
      }
      else {
        local_60 = (uint ******)&local_2b98;
        local_70 = (uint ******)&local_2b74;
        dstCursor = (uint *******)((int (*)())ilEmitProjectiveDivide)(&scanState,local_70,local_60,texUnit,dstCursor);
        texSourceExtraPtr = local_60;
        if (((uint)local_2ba4 & 0x400000) == 0) {
          projectiveFlag = (uint *******)0x0;
          unitBit = 1 << (tokenUpper & 0x3f);
        }
        else {
          local_2ba4 = (uint *******)((uint)local_2ba4 & 0xffbfffff);
          projectiveFlag = (uint *******)((int)((unsigned char *)0x0) + 1);
          unitBit = 1 << (tokenUpper & 0x3f);
          local_2bb0 = calleeSavedR15;
        }
      }
    }
    else if (texModeBits == 0x8000000) {
      unitBit = 1 << (tokenUpper & 0x3f);
      if ((unitBit & local_2374) != 0) goto LAB_000ca0e4;
      local_70 = (uint ******)&local_2b74;
      projectiveFlag = (uint *******)0x0;
      texSourceExtraPtr = (uint ******)&local_2b98;
    }
    else {
      projectiveFlag = (uint *******)0x0;
      unitBit = 1 << (tokenUpper & 0x3f);
      local_70 = (uint ******)&local_2b74;
      texSourceExtraPtr = (uint ******)&local_2b98;
    }
    scanTokenWord = &scanState;
    ((int (*)())ilRemapSourceOperandRegister)(local_70,texSourceExtraPtr,&scanState);
    *dstCursor = texTokenWord;
    nextDstCursorB = dstCursor + 1;
    if (hasSecondWord) {
      dstCursor[1] = ppppppuVar15;
      nextDstCursorB = dstCursor + 2;
    }
    dstCursor = nextDstCursorB;
    if (hasOptionalWord) {
      *dstCursor = texOptionalWord;
      dstCursor = dstCursor + 1;
    }
    *dstCursor = (uint ******)local_2ba4;
    nextDstCursorB = dstCursor + 1;
    if (((uint)local_2ba4 & 0x400000) != 0) {
      dstCursor[1] = calleeSavedR15;
      nextDstCursorB = dstCursor + 2;
    }
    dstCursor = nextDstCursorB;
    *dstCursor = local_2b74;
    pppppppuVar25 = (uint *******)((uint)local_2b74 & 0x400000);
    nextDstCursor = dstCursor + 1;
    if (pppppppuVar25 != (uint *******)0x0) {
      dstCursor[1] = local_2b98;
      nextDstCursor = dstCursor + 2;
    }
    dstCursor = nextDstCursor;
    if (((texModeBits == 0x4000000) || ((texModeBits == 0x8000000 && ((unitBit & local_2374) != 0)))) &&
       (local_2378 << (tokenUpper & 0x3f) != 0)) {
      scanTokenWord = (uint *******)&local_2ba4;
      dstCursor = (uint *******)
                   ((int (*)())ilEmitShadowCompare)(&scanState,local_70,scanTokenWord,&local_2bb0,texUnit,projectiveFlag,
                                dstCursor,pppppppuVar25);
      pppppppuVar20 = projectiveFlag;
    }
    unitBit = unitBit & local_2378;
    texExtraWord = calleeSavedR15;
    goto joined_r0x000ca538;
  case 0x5e:
    if (prologuePending) {
      prologuePending = false;
      dstCursor = (uint *******)
                   ((int (*)())ilEmitPrologue)(dstCursor,&scanState,scanTokenWord,puVar19,puVar19,pppppppuVar20,
                                opcodeTimes4,pppppppuVar25);
      puVar19 = srcCursor;
    }
    texTokenWord = (uint ******)*puVar19;
    cursor2 = puVar19 + 1;
    tokenUpper = (uint)texTokenWord >> 0x10;
    texUnit = tokenUpper & 0xff;
    hasSecondWord = ((uint)texTokenWord & 0x80000000) != 0;
    if (hasSecondWord) {
      cursor2 = puVar19 + 2;
      ppppppuVar15 = (uint ******)puVar19[1];
    }
    else {
      ppppppuVar15 = (uint ******)0x0;
    }
    hasOptionalWord = ((uint)texTokenWord & 0x40000000) != 0;
    if (hasOptionalWord) {
      texOptionalWord = (uint ******)*cursor2;
      cursor2 = cursor2 + 1;
    }
    else {
      texOptionalWord = (uint ******)0x0;
    }
    local_2ba4 = (uint *******)*cursor2;
    puVar19 = cursor2 + 1;
    if (((uint)local_2ba4 & 0x400000) != 0) {
      puVar19 = cursor2 + 2;
      calleeSavedR14 = (uint ******)cursor2[1];
    }
    local_2b98 = (uint ******)*puVar19;
    puVar26 = puVar19 + 1;
    if (((uint)local_2b98 & 0x400000) != 0) {
      local_2b74 = (uint ******)puVar19[1];
      puVar26 = puVar19 + 2;
    }
    local_2b94 = (uint ******)*puVar26;
    srcCursor = puVar26 + 1;
    if (((uint)local_2b94 & 0x400000) != 0) {
      local_2b70 = (uint ******)puVar26[1];
      srcCursor = puVar26 + 2;
    }
    texModeBits = (uint)texTokenWord & 0xc000000;
    if (texModeBits == 0x4000000) {
LAB_000ca3b8:
      if (local_2378 << (tokenUpper & 0x3f) != 0) {
        scanTokenWord = &local_2b74;
        dstCursor = (uint *******)
                     ((int (*)())ilEmitProjectiveDivide)(&scanState,&local_2b98,scanTokenWord,texUnit,dstCursor);
        if (((uint)local_2ba4 & 0x400000) != 0) {
          local_2ba4 = (uint *******)((uint)local_2ba4 & 0xffbfffff);
          pppppppuVar20 = (uint *******)((int)((unsigned char *)0x0) + 1);
          unitBit = 1 << (tokenUpper & 0x3f);
          local_2bb0 = calleeSavedR14;
          goto LAB_000ca414;
        }
      }
LAB_000ca3ec:
      pppppppuVar20 = (uint *******)0x0;
      unitBit = 1 << (tokenUpper & 0x3f);
    }
    else {
      if (texModeBits != 0x8000000) goto LAB_000ca3ec;
      pppppppuVar20 = (uint *******)0x0;
      unitBit = 1 << (tokenUpper & 0x3f);
      if ((unitBit & local_2374) != 0) goto LAB_000ca3b8;
    }
LAB_000ca414:
    *dstCursor = texTokenWord;
    nextDstCursorB = dstCursor + 1;
    if (hasSecondWord) {
      dstCursor[1] = ppppppuVar15;
      nextDstCursorB = dstCursor + 2;
    }
    dstCursor = nextDstCursorB;
    if (hasOptionalWord) {
      *dstCursor = texOptionalWord;
      dstCursor = dstCursor + 1;
    }
    *dstCursor = (uint ******)local_2ba4;
    nextDstCursorB = dstCursor + 1;
    if (((uint)local_2ba4 & 0x400000) != 0) {
      dstCursor[1] = calleeSavedR14;
      nextDstCursorB = dstCursor + 2;
    }
    dstCursor = nextDstCursorB;
    *dstCursor = local_2b98;
    pppppppuVar25 = (uint *******)((uint)local_2b98 & 0x400000);
    nextDstCursorC = dstCursor + 1;
    if (pppppppuVar25 != (uint *******)0x0) {
      dstCursor[1] = local_2b74;
      nextDstCursorC = dstCursor + 2;
    }
    dstCursor = nextDstCursorC;
    *dstCursor = local_2b94;
    nextDstCursorC = dstCursor + 1;
    if (((uint)local_2b94 & 0x400000) != 0) {
      dstCursor[1] = local_2b70;
      nextDstCursorC = dstCursor + 2;
    }
    dstCursor = nextDstCursorC;
    if (((texModeBits == 0x4000000) || ((texModeBits == 0x8000000 && ((unitBit & local_2374) != 0)))) &&
       (pppppppuVar25 = (uint *******)(local_2378 << (tokenUpper & 0x3f)),
       pppppppuVar25 != (uint *******)0x0)) {
      scanTokenWord = (uint *******)&local_2ba4;
      dstCursor = (uint *******)
                   ((int (*)())ilEmitShadowCompare)(&scanState,&local_2b98,scanTokenWord,&local_2bb0,texUnit,
                                pppppppuVar20,dstCursor,pppppppuVar25);
    }
    unitBit = unitBit & local_2378;
    texExtraWord = calleeSavedR14;
joined_r0x000ca538:
    puVar26 = srcCursor;
    dstCursorCarry = dstCursor;
    if (unitBit != 0) {
      pppppppuVar20 = dstCursor + 1;
      *dstCursor = (uint ******)0x47;
      pppppppuVar25 = local_2ba4;
      if (((uint)local_2ba4 & 0x400000) == 0) {
        pppppppuVar25 = (uint *******)((uint)local_2ba4 | 0x400000);
        texExtraWord = (uint ******)0x55;
      }
      if (aiStack_22f0[texUnit] == 0x1906) {
        if (((uint)texExtraWord & 3) == 1) {
          texExtraWord = (uint ******)((uint)texExtraWord & 0xfffffffc | 2);
        }
        if (((uint)texExtraWord & 0xc) == 4) {
          texExtraWord = (uint ******)((uint)texExtraWord & 0xfffffff3 | 8);
        }
        if (((uint)texExtraWord & 0x30) == 0x10) {
          texExtraWord = (uint ******)((uint)texExtraWord & 0xffffffcf | 0x20);
        }
      }
      else if ((aiStack_22f0[texUnit] == 0x1909) && (((uint)texExtraWord & 0xc0) == 0x40)) {
        texExtraWord = (uint ******)((uint)texExtraWord & 0xffffff3f | 0xc0);
      }
      *pppppppuVar20 = (uint ******)pppppppuVar25;
      dstCursor[2] = texExtraWord;
      dstCursor[3] = (uint ******)((uint)pppppppuVar25 & 0x3fffff);
      dstCursorCarry = dstCursor + 4;
    }
    goto switchD_000c9ab8_caseD_18;
  }
  srcCursor = (uint *)((int (*)())ilCopyInstructionRemapped)(&dstCursor,&srcCursor,scanTokenWord,1,&scanState);
  puVar26 = srcCursor;
  dstCursorCarry = dstCursor;
  goto switchD_000c9ab8_caseD_18;
}

/* ilRewriteForTextureState @ 0xcae90 (7760 bytes) */
int ilRewriteForTextureState(ctx, param_2, compileRecord, ilSource, param_5)
  int ctx;
  int *param_2;
  uint *******compileRecord;
  undefined4 *ilSource;
  undefined4 *param_5;
{
  bool bVar1;
  int *piVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  char cVar6;
  byte bVar7;
  undefined *puVar8;
  uint uVar9;
  float fVar10;
  uint *******pppppppuVar11;
  uint uVar12;
  int iVar13;
  uint ******ppppppuVar14;
  uint ******ppppppuVar15;
  int iVar16;
  uint ******ppppppuVar17;
  int *piVar18;
  uint *******pppppppuVar19;
  int iVar20;
  uint uVar21;
  uint *puVar22;
  uint *puVar23;
  int iVar24;
  uint *******staleArgR8;
  byte *pbVar25;
  int shadowExtraWords;
  uint uVar27;
  uint *******pppppppuVar28;
  undefined4 uVar29;
  int iVar30;
  char *pcVar31;
  int *piVar32;
  undefined4 uVar33;
  uint ******calleeSavedR14;
  uint ******calleeSavedR15;
  uint *puVar34;
  uint uVar35;
  uint calleeSavedR19;
  uint *******pppppppuVar36;
  undefined1 *puVar37;
  uint calleeSavedR20;
  undefined1 *puVar38;
  uint ******ppppppuVar39;
  uint *ilTokens;
  float *pfVar41;
  uint uVar42;
  int iVar43;
  int *piVar44;
  undefined4 *puVar45;
  int ilWordCount;
  int extraOutputWords;
  uint *readCursor;
  uint *******writeCursor;
  uint *******local_c1f0;
  uint local_c1ec [2];
  uint ******local_c1e4;
  uint local_c1e0 [2];
  uint ******local_c1d8;
  uint ******local_c1d4;
  uint ******local_c1cc;
  uint ******local_c1c8;
  uint ******local_c1c0 [3];
  undefined1 auStack_c1b4 [12];
  uint ******local_c1a8;
  uint local_c1a4;
  uint local_c1a0;
  uint local_c19c;
  uint local_c198 [4];
  undefined4 local_c188 [4];
  undefined4 local_c178;
  undefined4 local_c174;
  undefined4 local_c170;
  undefined4 local_c16c;
  uint local_c168 [4];
  undefined4 local_c158;
  undefined4 local_c154;
  undefined4 local_c150;
  undefined4 local_c14c;
  /* Follow-up to the previous fix's own bug (issue #64 live-repro): enlarging auStack_c148 was
   * correct, but leaving local_c100/local_c0fc/local_c0f8/local_c0f0/local_c0d0/local_c090 as
   * separate, non-overlapping locals was NOT harmless - confirmed live on real hardware. Stock's
   * real code does do pointer arithmetic from this buffer into them: FUN_000cd1b0 (called with
   * auStack_c148) tail-calls into scSetCallbackTables/FUN_000e2524, which read *(auStack_c148+0x4c)
   * expecting local_c0fc's value; a loop just below also writes local_c0f0[8..15], expecting
   * those words to land in local_c0d0. With the locals declared separately, the compiler placed
   * them elsewhere on the stack, so auStack_c148+0x4c stayed at its memset'd 0 instead of the
   * real pointer - a null deref several calls downstream, in FUN_00193c00's live differential
   * GLDriver test harness. Root-caused via a live watchpoint comparing stock vs. rebuilt (stock:
   * r3=0x40d470 at the same call; rebuilt: 0). Properly merged this time into one byte-accurate
   * 0xbc-byte buffer; each offset below is confirmed directly from its own name's hex value
   * (0xc148-0xc0fc=0x4c, 0xc148-0xc090=0xb8, etc), and the whole run is contiguous and exactly
   * 0xbc bytes (0xb8+4), matching the buffer's own real, memset'd size. */
  undefined1 auStack_c148 [0xbc];
#define local_c100 (*(uint **)(auStack_c148 + 0x48))
#define local_c0fc (*(uint **)(auStack_c148 + 0x4c))
#define local_c0f8 (*(int *)(auStack_c148 + 0x50))
#define local_c0f0 ((uint *)(auStack_c148 + 0x58))
#define local_c0d0 ((uint *)(auStack_c148 + 0x78))
#define local_c090 (*(int *)(auStack_c148 + 0xb8))
  /* issue #64 live-repro: ilMarkInstructionRegistersUsed/FUN_000c8600 (reached via the command-stream token-1/0x47
   * opcode handlers below) treat their 3rd/4th argument - &local_c08c, passed directly or via an
   * alias (pppppppuVar19/local_88) at every call site in this function - as the base of a large
   * per-context attribute-state array, indexing it at compileRecord[2] up to compileRecord[0x88a] (~8.7KB).
   * Declared as a single word, this overflowed onto whatever real stock places after it on the
   * stack. Live-verified on real hardware via a raw memory watchpoint at the real stock address:
   * FUN_000c8600's `compileRecord[ctx+0x87c] = 1;` (opcode 0x47, ctx==0) is a real, deterministic
   * write stock performs that the rebuild's undersized local_c08c can't - traced back through
   * ilRewriteForTextureState's own size-computation cascade (part_018.c:2758-2820) to the calloc(44) crash this
   * issue's title tracks: the write's real destination is 12 bytes past a stack region our size
   * computation reads back as a "flag" (local_9e9c[0]) to decide the command buffer's malloc size,
   * so leaving it unwritten undersizes that malloc by exactly the corruption this issue chases.
   * Given its own real size, without touching any other local's declaration. */
  unsigned char local_c08c_buf [0x2400];
#define local_c08c (*(uint *******)(local_c08c_buf))
  undefined4 local_c088;
  uint local_c084;
  /* issue #64 live-repro: the command-stream interpreter's source-side copy loop further down
   * ("puVar23 = local_c080; ... do{uVar21=*puVar23; uVar35=puVar23[8]; puVar23=puVar23+1; ...}
   * while(extraOutputWords!=0)" with extraOutputWords starting at 8) reads puVar23[0] and puVar23[8] across 8
   * iterations, reaching as far as local_c080+0x3c - 16 contiguous words (0x40 bytes), not just
   * local_c080's own declared 4. local_c070/c06c/c068/c064/c060/c050/c04c/c048/c044 are exactly
   * those remaining words by their own hex offsets. This is the read-side counterpart of the
   * auStack_c148/local_c0fc fix from earlier this session (the write side, local_c0f0/local_c0d0,
   * was already sized correctly there). Left separate, the rebuild copied whatever real stack
   * words happened to follow local_c080's own 4 into the destination command buffer instead of
   * the real header/argument words - live-verified: the command-stream interpreter three calls
   * later reads a garbage opcode (>100) from the corrupted buffer and hits its own documented
   * out-of-range safety net (_exit(0), confirmed present in stock too). Merged into one 0x40-byte
   * buffer. */
  unsigned char local_c080_buf [0x40];
#define local_c080 ((uint *)(local_c080_buf + 0x00))
#define local_c070 (*(undefined4 *)(local_c080_buf + 0x10))
#define local_c06c (*(undefined4 *)(local_c080_buf + 0x14))
#define local_c068 (*(undefined4 *)(local_c080_buf + 0x18))
#define local_c064 (*(undefined4 *)(local_c080_buf + 0x1c))
#define local_c060 ((uint *)(local_c080_buf + 0x20))
#define local_c050 (*(undefined4 *)(local_c080_buf + 0x30))
#define local_c04c (*(undefined4 *)(local_c080_buf + 0x34))
#define local_c048 (*(undefined4 *)(local_c080_buf + 0x38))
#define local_c044 (*(undefined4 *)(local_c080_buf + 0x3c))
  int local_c040;
  uint ******local_c03c;
  int local_c034;
  int local_c030;
  uint local_c02c;
  int local_c028;
  int local_c024;
  int local_c020;
  uint depthTextureUnitMask;
  uint shadowCompareUnitMask;
  undefined4 local_bfd4;
  uint depthTextureMode [16];
  uint local_bf54 [16];
  uint local_bf14;
  uint local_bf04 [6];
  undefined1 auStack_beec [4104];
  uint local_aee4 [6];
  undefined1 auStack_aecc [4104];
  int local_9ec4;
  int local_9ebc;
  uint ******local_9eb8;
  undefined4 local_9eb4;
  int local_9e9c [5];
  int local_9e88;
  int local_9e80;
  int local_9e78;
  int local_9e74;
  int local_9e70;
  int local_9e6c;
  undefined4 local_9e68;
  int local_9e64;
  int local_9e60;
  undefined4 local_9e5c;
  uint *******local_9e58;
  int local_9e54 [16];
  int local_9e14 [16];
  uint local_9dd4 [17];
  uint ******local_9d90;
  int local_9d88;
  int local_9d84;
  undefined4 local_9d80;
  int local_9d7c;
  undefined4 local_9d70;
  int local_9d6c;
  undefined4 local_9d20;
  /* Declared too small (72 bytes) vs. its own memset (0x9c88 = 40072 bytes) - this is the real
   * root cause of the shader/GLSL token-stream parser crash tracked on issue #64: this buffer is
   * the token stream's own backing storage (its address eventually becomes the base ILReader__fetchToken
   * walks via ctx+0x74), and at 72 declared bytes the memset was overflowing ~40KB into
   * whatever the compiler placed after it on the stack - onto this same giant function's own many
   * other locals, corrupting them, AND leaving the "real" 40KB buffer's tail entirely unzeroed
   * (reading uninitialized stack garbage there once the token stream's real content ran out,
   * instead of the clean zero/terminator byte stock's properly-sized buffer provides). Enlarged to
   * the real size. */
  undefined1 auStack_9d1c [0x9c88];
  undefined4 local_9cd4;
  uint local_9cc8;
  int local_9cbc;
  uint local_9c84 [27];
  int local_9c18;
  char local_9c14 [1348];
  undefined1 auStack_96d0 [37816];
  int iStack_318;
  uint *******local_88;
  uint ******local_84;
  int *local_80;
  uint ******local_70;
  
  ilWordCount = 8;
  iVar13 = 0;
  do {
    *(undefined4 *)((int)local_c168 + iVar13) = 0xffffffff;
    *(undefined4 *)((int)local_c188 + iVar13) = 0;
    iVar13 = iVar13 + 4;
    ilWordCount = ilWordCount + -1;
  } while (ilWordCount != 0);
  bVar3 = ctx == 0;
  local_c168[0] = local_c168[0] & 0xffff0000;
  pppppppuVar19 = compileRecord;
  iVar13 = _malloc(0x400);
  local_9d20 = 0;
  shadowCompareUnitMask = 0;
  local_9d70 = 0;
  local_9d6c = 0;
  if (bVar3) {
    depthTextureUnitMask = 0;
  }
  else {
    staleArgR8 = (uint *******)0x0;
    extraOutputWords = 0x10;
    shadowCompareUnitMask = 0;
    depthTextureUnitMask = 0;
    puVar34 = depthTextureMode;
    pppppppuVar19 = (uint *******)((int)((unsigned char *)0x0) + 1);
    ilWordCount = ctx;
    do {
      shadowExtraWords = *(int *)(((unsigned char *)0x000013f8) + ilWordCount);
      if ((shadowExtraWords != 0) && (*(short *)(shadowExtraWords + 0x38) == 0x1902)) {
        uVar21 = 1 << ((uint)staleArgR8 & 0x3f);
        depthTextureUnitMask = uVar21 | depthTextureUnitMask;
        *puVar34 = (uint)*(ushort *)(shadowExtraWords + 0x58);
        puVar34[0x10] = (uint)*(ushort *)(shadowExtraWords + 0x5c);
        if (*(short *)(shadowExtraWords + 0x5a) != 0) {
          shadowCompareUnitMask = uVar21 | shadowCompareUnitMask;
        }
      }
      staleArgR8 = (uint *******)((int)staleArgR8 + 1);
      ilWordCount = ilWordCount + 4;
      puVar34 = puVar34 + 1;
      extraOutputWords = extraOutputWords + -1;
    } while (extraOutputWords != 0);
  }
  if (*(char *)(compileRecord + 0x46) == '\0') {
    local_9ebc = 0;
  }
  else {
    local_9eb8 = compileRecord[0x2b];
    local_9ebc = 1;
    if (bVar3) {
      local_9eb4 = 0;
    }
    else {
      local_9eb4 = *(undefined4 *)(ctx + 0x276c);
    }
  }
  ilWordCount = 0;
  puVar34 = local_9dd4;
  extraOutputWords = 0x10;
  do {
    *puVar34 = 0;
    if ((!bVar3) && (*(int *)(((unsigned char *)0x000013f8) + ilWordCount * 4 + *param_2) != 0)) {
      *puVar34 = (uint)*(byte *)(*(int *)(((unsigned char *)0x000013f8) + ilWordCount * 4 + *param_2) + 0x30);
    }
    ilWordCount = ilWordCount + 1;
    puVar34 = puVar34 + 1;
    extraOutputWords = extraOutputWords + -1;
  } while (extraOutputWords != 0);
  local_9e58 = (uint *******)((int)((unsigned char *)0x0) + 1);
  local_9e88 = 0;
  local_9d90 = compileRecord[0x45];
  if ((bVar3) || (*(short *)(((unsigned char *)0x00002e06) + *(int *)(*(int *)(ctx + 4) + 0x10)) != -0x7baf)) {
    local_9d80 = 0;
  }
  else {
    local_9d80 = 1;
  }
  ilTokens = (uint *)*ilSource;
  local_c08c = (uint ******)0x0;
  local_c028 = 0;
  local_c088 = 0xffff;
  local_c064 = local_c14c;
  local_c068 = local_c150;
  local_c06c = local_c154;
  local_c070 = local_c158;
  local_c080[3] = local_c168[3];
  local_c080[2] = local_c168[2];
  local_c080[1] = local_c168[1];
  local_c080[0] = local_c168[0];
  local_c044 = local_c16c;
  local_c048 = local_c170;
  ilWordCount = ilSource[1];
  local_c04c = local_c174;
  local_c050 = local_c178;
  local_c040 = 0;
  local_c060[3] = local_c188[3];
  local_c060[2] = local_c188[2];
  local_c084 = 0;
  local_9e5c = 0;
  local_bf14 = 0;
  local_9ec4 = 0;
  local_9e9c[0] = 0;
  local_9e9c[1] = 0;
  local_9e9c[2] = 0;
  local_9e9c[3] = 0;
  local_9e78 = 0;
  local_9e74 = 0;
  local_9e70 = 0;
  local_9e6c = 0;
  local_9e80 = 0;
  local_9e68 = 0;
  local_9e64 = 0;
  local_9e60 = 0;
  local_c060[1] = local_c188[1];
  local_c060[0] = local_c188[0];
  puVar34 = local_bf04;
  extraOutputWords = 8;
  do {
    *puVar34 = 0;
    puVar34[0x408] = 0;
    puVar34 = puVar34 + 1;
    extraOutputWords = extraOutputWords + -1;
  } while (extraOutputWords != 0);
  local_80 = local_9e54;
  extraOutputWords = 0x10;
  piVar18 = local_80;
  do {
    *piVar18 = 0;
    piVar18[0x10] = 0;
    piVar18 = piVar18 + 1;
    extraOutputWords = extraOutputWords + -1;
  } while (extraOutputWords != 0);
  extraOutputWords = 0;
  shadowExtraWords = 0;
  uVar21 = 0;
  puVar34 = ilTokens;
switchD_000cb23c_caseD_15:
  readCursor = puVar34 + 2;
  puVar23 = readCursor;
switchD_000cb23c_caseD_18:
  puVar34 = puVar23;
  if (puVar34 < ilTokens + ilWordCount) goto code_r0x000cb214;
  if (local_9ec4 != 0) {
    puVar34 = (uint *)0x0;
    uVar35 = 0;
    goto LAB_000cc88c;
  }
  extraOutputWords = (ilWordCount + extraOutputWords) * 4;
  local_c03c = local_c08c;
  if (local_c040 != 0) {
    extraOutputWords = extraOutputWords + 0x48;
  }
  uVar35 = extraOutputWords + shadowExtraWords * 4;
  bVar5 = local_9ebc != 0;
  if (bVar5) {
    uVar35 = uVar35 + 0x14;
  }
  uVar12 = uVar35;
  if ((local_9e9c[0] != 0) && (uVar12 = uVar35 + 0xc, bVar5)) {
    uVar12 = uVar35 + 0x24;
  }
  uVar35 = uVar12;
  if ((local_9e9c[1] != 0) && (uVar35 = uVar12 + 0xc, bVar5)) {
    uVar35 = uVar12 + 0x24;
  }
  uVar12 = uVar35;
  if ((local_9e9c[2] != 0) && (uVar12 = uVar35 + 0xc, bVar5)) {
    uVar12 = uVar35 + 0x24;
  }
  uVar27 = uVar12;
  if ((local_9e9c[3] != 0) && (uVar27 = uVar12 + 0xc, bVar5)) {
    uVar27 = uVar12 + 0x24;
  }
  if (((local_9e80 != 0) && (local_9e88 != 0)) && (local_9e58 == (uint *******)0x0)) {
    uVar27 = uVar27 + 0x14;
  }
  if (local_9d90 == (uint ******)0x1) {
    uVar27 = uVar27 + 0x24;
  }
  else if (local_9d90 == (uint ******)0x2) {
    uVar27 = uVar27 + 0x30;
  }
  else if (local_9d90 == (uint ******)0x3) {
    uVar27 = uVar27 + 0x40;
  }
  else if (local_9d90 == (uint ******)0x0) goto LAB_000cbb64;
  uVar27 = uVar27 + 8;
  piVar18 = local_9e9c;
  extraOutputWords = 4;
  do {
    if (*piVar18 != 0) {
      uVar27 = uVar27 + 0x2c;
    }
    piVar18 = piVar18 + 1;
    extraOutputWords = extraOutputWords + -1;
  } while (extraOutputWords != 0);
LAB_000cbb64:
  if (((local_9e74 != 0) || (local_9e6c != 0)) || (uVar35 = uVar27, local_9e58 == (uint *******)0x0)
     ) {
    if ((local_9e78 == 0) && (local_9e70 != 0)) {
      uVar27 = uVar27 + 0xc;
    }
    uVar35 = uVar27;
    if ((local_9e58 == (uint *******)0x0) && (uVar35 = uVar27 + 0xc, local_9d7c != 0)) {
      uVar35 = uVar27 + 0x18;
    }
  }
  bVar5 = true;
  pppppppuVar28 = local_9e58;
  puVar34 = (uint *)_malloc(uVar35 + 0x10);
  *puVar34 = *ilTokens;
  readCursor = ilTokens + 2;
  puVar34[1] = ilTokens[1];
  puVar23 = readCursor;
  pppppppuVar36 = (uint *******)(puVar34 + 2);
  goto switchD_000cbc48_caseD_18;
code_r0x000cb214:
  pppppppuVar19 = (uint *******)*puVar34;
  puVar23 = puVar34;
  switch((uint)pppppppuVar19 & 0xffff) {
  default:
    goto switchD_000cb23c_caseD_0;
  case 1:
  case 2:
  case 4:
  case 5:
  case 0xb:
  case 0xe:
  case 0x12:
  case 0x1e:
  case 0x25:
  case 0x26:
  case 0x2c:
  case 0x2d:
  case 0x2e:
  case 0x30:
  case 0x31:
  case 0x33:
  case 0x38:
  case 0x39:
  case 0x3a:
  case 0x3b:
  case 0x3c:
  case 0x3d:
  case 0x47:
  case 0x48:
  case 0x4a:
  case 0x4c:
  case 0x4d:
  case 0x50:
  case 0x51:
  case 0x54:
  case 0x55:
  case 0x57:
  case 0x58:
  case 0x59:
  case 0x5a:
  case 0x5c:
  case 0x62:
  case 99:
    uVar29 = 1;
    break;
  case 3:
  case 0xc:
  case 0x13:
  case 0x1f:
  case 0x20:
  case 0x22:
  case 0x23:
  case 0x41:
  case 0x44:
  case 0x45:
  case 0x46:
  case 0x49:
  case 0x4e:
  case 0x52:
  case 0x56:
  case 0x5b:
    uVar29 = 1;
    goto LAB_000cb4b0;
  case 6:
  case 0x10:
  case 0x27:
  case 0x29:
  case 0x2a:
  case 0x2b:
  case 0x4b:
  case 0x53:
    readCursor = puVar34 + 1;
    puVar23 = readCursor;
    goto switchD_000cb23c_caseD_18;
  /* issue #64 live-repro (crash #3, use-after-free): opcode 0x28 was lumped in with the
   * trivial single-word opcodes above in THIS sizing pass, contributing nothing extra to
   * extraOutputWords (the buffer's extra-output-words budget). But the WRITE pass's real case 0x28
   * (below, `puVar45 = FUN_000c7930(...); *puVar45 = ppppppuVar15;`) calls FUN_000c7930,
   * which - depending on live per-context state read from local_c08c/param_2 - can emit far
   * more than one output word: tallying every conditional block in FUN_000c7930 (part_018.c),
   * its worst case is 110 words (60 from the first *(param_2+0x22fc)!=0 block's three
   * sub-loops, 24 from the *(param_2+0x21d0)!=0 loop, 12 from the unconditional third loop,
   * 5 from the 0x220c/0x2204/0x2234 block, 9 from the final 0x2218/0x2220/0x2234 block),
   * plus the caller's own extra `*puVar45 = ppppppuVar15` word already covered by this
   * opcode's baseline 1-word allowance. Live-verified on real hardware: with a watchpoint on
   * the corrupted freed heap block, `info locals` inside ilRewriteForTextureState at the exact fault
   * showed puVar45 (the write's destination pointer, i.e. FUN_000c7930's real return value)
   * equal to the corrupted address, and ppppppuVar15 (the value written) equal to 0x28 - the
   * opcode number itself, confirming this exact call site. Splitting 0x28 out and adding its
   * real worst-case bonus here (matching the existing extraOutputWords/shadowExtraWords bonus pattern used by
   * cases 0x24/0x5d/0x5e above) so the command buffer is sized for what this opcode can
   * actually emit. */
  case 0x28:
    extraOutputWords = extraOutputWords + 110;
    readCursor = puVar34 + 1;
    puVar23 = readCursor;
    goto switchD_000cb23c_caseD_18;
  case 7:
  case 0x11:
  case 0x34:
    uVar29 = 0;
LAB_000cb4b0:
    pppppppuVar19 = (uint *******)((int)((unsigned char *)0x0) + 2);
    readCursor = (uint *)((int (*)())ilMarkInstructionRegistersUsed)(puVar34,uVar29,2,&local_c08c);
    puVar23 = readCursor;
    goto switchD_000cb23c_caseD_18;
  case 8:
  case 0x32:
    readCursor = puVar34 + 2;
    puVar23 = readCursor;
    goto switchD_000cb23c_caseD_18;
  case 9:
  case 0x1d:
    readCursor = puVar34 + 3;
    puVar23 = readCursor;
    goto switchD_000cb23c_caseD_18;
  case 10:
  case 0xd:
  case 0x21:
  case 0x2f:
  case 0x3f:
  case 0x40:
  case 100:
    pppppppuVar19 = (uint *******)((int)((unsigned char *)0x0) + 3);
    readCursor = (uint *)((int (*)())ilMarkInstructionRegistersUsed)(puVar34,1,3,&local_c08c);
    puVar23 = readCursor;
    goto switchD_000cb23c_caseD_18;
  case 0xf:
    readCursor = puVar34 + *(ushort *)((int)puVar34 + 6) + 2;
    puVar23 = readCursor;
    goto switchD_000cb23c_caseD_18;
  case 0x14:
    readCursor = puVar34 + 3;
    puVar23 = readCursor;
    goto switchD_000cb23c_caseD_18;
  case 0x15:
    goto switchD_000cb23c_caseD_15;
  case 0x16:
    readCursor = puVar34 + 1;
    pppppppuVar19 = &local_c08c;
    uVar35 = puVar34[1];
    puVar8 = (undefined *)(uVar35 & 0x3f0000);
    ((int (*)())FUN_000c8600)(uVar35 & 0xffff,uVar35 >> 0x10 & 0x3f,pppppppuVar19,0,0);
    if (puVar8 == ((unsigned char *)0x00160000U)) {
      local_c040 = 1;
    }
    else if (puVar8 == (undefined *)0x110000) {
      local_c084 = 1 << (uVar35 & 0x3f) | local_c084;
    }
    else if (puVar8 == (undefined *)0xf0000) {
      uVar21 = uVar21 | 1 << (uVar35 & 0x3f);
    }
    else if (puVar8 == (undefined *)0x100000) {
      local_c028 = 1;
    }
    goto LAB_000cb6d4;
  case 0x18:
    goto switchD_000cb23c_caseD_18;
  case 0x19:
    uVar12 = (uint)pppppppuVar19 >> 0x1b & 3;
    uVar35 = (uint)pppppppuVar19 >> 0x10 & 0xff;
    if ((uVar12 == 2) || ((uVar12 == 0 && (local_9dd4[uVar35] == 2)))) {
      local_bf14 = 1 << ((uint)pppppppuVar19 >> 0x10 & 0x3f) | local_bf14;
    }
    pppppppuVar19 = (uint *******)((uint)pppppppuVar19 >> 0x18 & 7);
    ilRecordInputSemantic(&local_c08c,uVar35,pppppppuVar19);
    readCursor = readCursor + 1;
    puVar23 = readCursor;
    goto switchD_000cb23c_caseD_18;
  case 0x1a:
    readCursor = puVar34 + 1;
    if ((int)pppppppuVar19 < 0) {
      readCursor = puVar34 + 2;
    }
LAB_000cb6d4:
    readCursor = readCursor + 1;
    puVar23 = readCursor;
    goto switchD_000cb23c_caseD_18;
  case 0x1c:
    readCursor = puVar34 + 1;
    uVar12 = puVar34[1];
    uVar35 = uVar12 >> 0x10 & 0x3f;
    if (uVar35 == 1) {
      pppppppuVar19 = &local_c1a8;
      local_c1a8 = (uint ******)puVar34[2];
      local_c1a4 = puVar34[3];
      local_c1a0 = puVar34[4];
      readCursor = puVar34 + 6;
      local_c19c = puVar34[5];
      ilRecordDefinedConstantPrimary(&local_c08c,uVar12 & 0xffff,pppppppuVar19);
      puVar23 = readCursor;
    }
    else {
      puVar23 = readCursor;
      if (uVar35 == 2) {
        pppppppuVar19 = &local_c1a8;
        local_c1a8 = (uint ******)puVar34[2];
        local_c1a4 = puVar34[3];
        local_c1a0 = puVar34[4];
        readCursor = puVar34 + 6;
        local_c19c = puVar34[5];
        ilRecordDefinedConstantSecondary(&local_c08c,uVar12 & 0xffff,pppppppuVar19);
        puVar23 = readCursor;
      }
    }
    goto switchD_000cb23c_caseD_18;
  case 0x24:
    pppppppuVar19 = (uint *******)((int)((unsigned char *)0x0) + 2);
    extraOutputWords = extraOutputWords + 5;
    readCursor = (uint *)((int (*)())ilMarkInstructionRegistersUsed)(puVar34,1,2,&local_c08c);
    puVar23 = readCursor;
    goto switchD_000cb23c_caseD_18;
  case 0x35:
    pppppppuVar19 = &local_c08c;
    readCursor = puVar34 + 2;
    local_c1c0[0] = (uint ******)puVar34[1];
    ((int (*)())ilMarkOperandRegisterUsed)(local_c1c0,auStack_c1b4,pppppppuVar19);
    puVar23 = readCursor;
    goto switchD_000cb23c_caseD_18;
  case 0x37:
    pppppppuVar19 = (uint *******)((int)((unsigned char *)0x0) + 1);
    readCursor = (uint *)((int (*)())ilMarkInstructionRegistersUsed)(puVar34,0,1,&local_c08c);
    local_9e60 = 1;
    puVar23 = readCursor;
    goto switchD_000cb23c_caseD_18;
  case 0x3e:
    uVar29 = 0;
    break;
  case 0x5d:
    readCursor = puVar34 + 2;
    local_9d6c = local_9d6c + 1;
    uVar35 = puVar34[1];
    uVar12 = *puVar34;
    if ((((uVar12 & 0xc000000) == 0x4000000) ||
        (((uVar12 & 0xc000000) == 0x8000000 &&
         ((1 << (*(byte *)((int)puVar34 + 1) & 0x3f) & shadowCompareUnitMask) != 0)))) &&
       (depthTextureUnitMask << (*(byte *)((int)puVar34 + 1) & 0x3f) != 0)) {
      shadowExtraWords = shadowExtraWords + 0x1b;
      shadowCompareUnitMask = 1 << (*(byte *)((int)puVar34 + 1) & 0x3f) | shadowCompareUnitMask;
      uVar12 = *puVar34;
    }
    if ((int)uVar12 < 0) {
      readCursor = puVar34 + 3;
      uVar12 = *puVar34;
    }
    if ((uVar12 & 0x40000000) != 0) {
      readCursor = readCursor + 1;
    }
    if ((uVar35 & 0x400000) != 0) {
      calleeSavedR20 = *readCursor;
      readCursor = readCursor + 1;
    }
    local_88 = &local_c08c;
    ((int (*)())FUN_000c8600)(uVar35 & 0xffff,uVar35 >> 0x10 & 0x3f,local_88,calleeSavedR20,uVar35 >> 0x16 & 1);
    if ((1 << (*(byte *)((int)puVar34 + 1) & 0x3f) & depthTextureUnitMask) != 0) {
      shadowExtraWords = shadowExtraWords + 4;
    }
    local_c1e4 = (uint ******)*readCursor;
    puVar34 = readCursor + 1;
    if (((uint)local_c1e4 & 0x400000) != 0) {
      local_c1f0 = (uint *******)readCursor[1];
      puVar34 = readCursor + 2;
    }
    readCursor = puVar34;
    pppppppuVar19 = local_88;
    ((int (*)())ilMarkOperandRegisterUsed)(&local_c1e4,&local_c1f0,local_88);
    puVar23 = readCursor;
    goto switchD_000cb23c_caseD_18;
  case 0x5e:
    readCursor = puVar34 + 2;
    local_9d6c = local_9d6c + 1;
    uVar35 = puVar34[1];
    uVar12 = *puVar34;
    if ((((uVar12 & 0xc000000) == 0x4000000) ||
        (((uVar12 & 0xc000000) == 0x8000000 &&
         ((1 << (*(byte *)((int)puVar34 + 1) & 0x3f) & shadowCompareUnitMask) != 0)))) &&
       (depthTextureUnitMask << (*(byte *)((int)puVar34 + 1) & 0x3f) != 0)) {
      shadowExtraWords = shadowExtraWords + 0x1b;
      shadowCompareUnitMask = 1 << (*(byte *)((int)puVar34 + 1) & 0x3f) | shadowCompareUnitMask;
      uVar12 = *puVar34;
    }
    if ((int)uVar12 < 0) {
      readCursor = puVar34 + 3;
      uVar12 = *puVar34;
    }
    if ((uVar12 & 0x40000000) != 0) {
      readCursor = readCursor + 1;
    }
    if ((uVar35 & 0x400000) != 0) {
      calleeSavedR19 = *readCursor;
      readCursor = readCursor + 1;
    }
    local_88 = &local_c08c;
    ((int (*)())FUN_000c8600)(uVar35 & 0xffff,uVar35 >> 0x10 & 0x3f,local_88,calleeSavedR19,uVar35 >> 0x16 & 1);
    if ((1 << (*(byte *)((int)puVar34 + 1) & 0x3f) & depthTextureUnitMask) != 0) {
      shadowExtraWords = shadowExtraWords + 4;
    }
    local_c1f0 = (uint *******)*readCursor;
    puVar34 = readCursor + 1;
    if (((uint)local_c1f0 & 0x400000) != 0) {
      local_c1e4 = (uint ******)readCursor[1];
      puVar34 = readCursor + 2;
    }
    local_c1ec[0] = *puVar34;
    readCursor = puVar34 + 1;
    if ((local_c1ec[0] & 0x400000) != 0) {
      local_c1e0[0] = puVar34[1];
      readCursor = puVar34 + 2;
    }
    ((int (*)())ilMarkOperandRegisterUsed)(&local_c1f0,&local_c1e4,local_88);
    pppppppuVar19 = local_88;
    ((int (*)())ilMarkOperandRegisterUsed)(local_c1ec,local_c1e0,local_88);
    puVar23 = readCursor;
    goto switchD_000cb23c_caseD_18;
  }
  pppppppuVar19 = (uint *******)((int)((unsigned char *)0x0) + 1);
  readCursor = (uint *)((int (*)())ilMarkInstructionRegistersUsed)(puVar34,uVar29,1,&local_c08c);
  puVar23 = readCursor;
  goto switchD_000cb23c_caseD_18;
switchD_000cbc48_caseD_18:
  writeCursor = pppppppuVar36;
  puVar22 = puVar23;
  pppppppuVar36 = writeCursor;
  if (ilTokens + ilWordCount <= puVar22) {
    uVar35 = uVar35 >> 2;
    local_c084 = uVar21 | local_c084;
LAB_000cc88c:
    if (local_9ec4 != 0) {
      _free(puVar34);
      return local_9ec4;
    }
    if ((local_c040 == 0) || (local_c02c == 0x11)) {
      *(undefined1 *)(param_2 + 0x7a6) = 0;
      *(undefined1 *)((int)param_2 + 0x1e2f) = 0;
    }
    else {
      *(undefined1 *)(param_2 + 0x7a6) = 1;
      *(undefined1 *)((int)param_2 + 0x1e2f) = 1;
      param_2[0x7a4] = local_c02c + 2;
      compileRecord[0x2e] = (uint ******)(local_c034 + param_2[0x7c7]);
      compileRecord[0x2f] = (uint ******)(local_c030 + param_2[0x7c7]);
    }
    if ((local_c028 == 0) || (local_c024 == 0x11)) {
      *(undefined1 *)((int)param_2 + 0x1e2e) = 0;
    }
    else {
      param_2[0x7a3] = local_c024 + 2;
      *(undefined1 *)((int)param_2 + 0x1e2e) = 1;
    }
    if (local_9d90 == (uint ******)0x0) {
      *(undefined1 *)(param_2 + 0x7a8) = 0;
    }
    else {
      param_2[0x7a3] = local_c020;
      compileRecord[0x38] = (uint ******)(local_9d88 + param_2[0x7c7]);
      compileRecord[0x39] = (uint ******)(local_9d84 + param_2[0x7c7]);
      *(undefined1 *)(param_2 + 0x7a8) = 1;
    }
    if (local_9e64 == 0) {
      *(undefined1 *)((int)param_2 + 0x1efd) = 0;
    }
    else {
      *(undefined1 *)((int)param_2 + 0x1efd) = 1;
    }
    if (local_9e60 == 0) {
      *(undefined1 *)(param_2 + 0x7c1) = 0;
    }
    else {
      *(undefined1 *)(param_2 + 0x7c1) = 1;
    }
    ilWordCount = 8;
    uVar21 = 0;
    pppppppuVar28 = compileRecord + 0x2c;
    pppppppuVar19 = compileRecord;
    do {
      if ((1 << (uVar21 & 0x3f) & local_c084) == 0) {
        *(undefined1 *)(pppppppuVar19 + 0x2c) = 0;
      }
      else if ((local_c040 == 0) || (local_c02c != uVar21)) {
        *(undefined1 *)(pppppppuVar19 + 0x2c) = 1;
      }
      else {
        *(undefined1 *)pppppppuVar28 = 0;
      }
      uVar21 = uVar21 + 1;
      pppppppuVar28 = (uint *******)((int)pppppppuVar28 + 1);
      pppppppuVar19 = (uint *******)((int)pppppppuVar19 + 1);
      ilWordCount = ilWordCount + -1;
    } while (ilWordCount != 0);
    param_2[0x7a9] = 0;
    compileRecord[0x36] = (uint ******)0x0;
    uVar21 = 0;
    ilWordCount = 0x10;
    *(undefined4 *)(((unsigned char *)0x000010e0) + (int)*compileRecord) = local_bfd4;
    piVar18 = local_80;
    piVar44 = param_2;
    piVar32 = param_2;
    do {
      uVar12 = 1 << (uVar21 & 0x3f);
      if ((uVar12 & local_bf14) == 0) {
        *(undefined1 *)(piVar32 + 0x582) = 0;
      }
      else {
        *(undefined1 *)(piVar32 + 0x582) = 1;
      }
      if ((uVar12 & depthTextureUnitMask) == 0) {
        *(undefined1 *)(piVar32 + 0x586) = 0;
      }
      else {
        *(undefined1 *)(piVar32 + 0x586) = 1;
        param_2[0x7a9] = 1;
        piVar44[0x7aa] = piVar18[-0x860] + param_2[0x7c7];
      }
      uVar21 = uVar21 + 1;
      piVar44[0x572] = *piVar18;
      piVar44 = piVar44 + 1;
      piVar2 = piVar18 + 0x10;
      piVar18 = piVar18 + 1;
      *(char *)(piVar32 + 0x56e) = (char)*piVar2;
      fVar10 = FLOAT_001aa0e8;
      piVar32 = (int *)((int)piVar32 + 1);
      ilWordCount = ilWordCount + -1;
    } while (ilWordCount != 0);
    ilWordCount = 0;
    piVar18 = param_2;
    piVar44 = param_2;
    do {
      if (((!bVar3) && (*(char *)(piVar44 + 0x586) != '\0')) &&
         (extraOutputWords = *(int *)(((unsigned char *)0x000013f8) + ilWordCount * 4 + *param_2), extraOutputWords != 0)) {
        ((void (*)())ilStoreFloat4Constant)(*compileRecord,(int)compileRecord[0x36] + (piVar18[0x7aa] - param_2[0x7c7]),
                     (double)(fVar10 / *(float *)(extraOutputWords + 0x44)),
                     (double)(fVar10 / *(float *)(extraOutputWords + 0x48)),(double)*(float *)(extraOutputWords + 0x50),
                     (double)FLOAT_001aa0e8);
      }
      bVar5 = ilWordCount != 0xf;
      piVar18 = piVar18 + 1;
      piVar44 = (int *)((int)piVar44 + 1);
      ilWordCount = ilWordCount + 1;
    } while (bVar5);
    local_88 = &local_c08c;
    ilWordCount = 0;
    ilTokens = local_aee4;
    puVar38 = auStack_beec;
    puVar37 = auStack_aecc;
    do {
      puVar45 = (undefined4 *)(puVar37 + 8);
      pfVar41 = (float *)(puVar38 + 8);
      uVar21 = 0;
      extraOutputWords = ilWordCount << 2;
      do {
        uVar12 = 1 << (uVar21 & 0x3f);
        if ((uVar12 & ilTokens[-0x408]) != 0) {
          ((void (*)())ilStoreFloat4Constant)(*compileRecord,ilWordCount + uVar21,(double)*pfVar41,(double)pfVar41[1],
                       (double)pfVar41[2],(double)pfVar41[3]);
        }
        if ((uVar12 & *ilTokens) != 0) {
          uVar33 = puVar45[1];
          uVar29 = *puVar45;
          shadowExtraWords = extraOutputWords + (int)*compileRecord;
          ((unsigned char *)0x000036c9)[shadowExtraWords] = (char)puVar45[2];
          ((unsigned char *)0x000036cb)[shadowExtraWords] = (char)uVar29;
          ((unsigned char *)0x000036ca)[shadowExtraWords] = (char)uVar33;
        }
        bVar3 = uVar21 != 0x1f;
        extraOutputWords = extraOutputWords + 4;
        puVar45 = puVar45 + 4;
        pfVar41 = pfVar41 + 4;
        uVar21 = uVar21 + 1;
      } while (bVar3);
      bVar3 = ilWordCount != 0xe0;
      puVar37 = puVar37 + 0x200;
      puVar38 = puVar38 + 0x200;
      ilTokens = ilTokens + 1;
      ilWordCount = ilWordCount + 0x20;
    } while (bVar3);
    *(uint *)(((unsigned char *)0x00003748) + (int)*compileRecord) = local_aee4[0];
    _memset(auStack_c148,0,0xbc);
    _memset(auStack_9d1c,0,0x9c88);
    ilWordCount = _malloc(param_5[1]);
    if (ilWordCount == 0) {
      return -1;
    }
    _memset(ilWordCount,0,param_5[1]);
    local_c0f8 = uVar35 << 2;
    puVar23 = local_c080;
    ilTokens = local_c0f0;
    extraOutputWords = 8;
    local_c090 = ilWordCount;
    do {
      uVar21 = *puVar23;
      uVar35 = puVar23[8];
      puVar23 = puVar23 + 1;
      *ilTokens = uVar21;
      ilTokens[8] = uVar35;
      ilTokens = ilTokens + 1;
      extraOutputWords = extraOutputWords + -1;
    } while (extraOutputWords != 0);
    local_c100 = local_c198;
    local_9cd4 = 0x40;
    local_c198[0] = local_c198[0] & 0x403fffff | 0x62000000;
    local_c0fc = puVar34;
    local_9cbc = _malloc(0x900);
    /* issue #64 live-repro (crash #6, past the extraOutputWords-mask fix): local_9cc8 - the record count
     * later used as this loop's bound (`uVar21 = local_9cc8; ... while (uVar35 < uVar21)`,
     * below) - is read in several places but WRITTEN nowhere in this entire function; the only
     * thing ever done with its companion buffer is this _malloc(0x900) (64 records of 0x24
     * bytes each) with no populating writes anywhere in this 4600-line function either. A
     * freshly malloc'd, never-populated record list has zero valid entries, so the natural,
     * safe count is 0 - but nothing sets it, leaving it as raw uninitialized stack garbage.
     * Live-verified on real hardware: local_9cc8 read back as 3221123400 (0xC000FE48), driving
     * the consumption loop far past the (empty) buffer into unrelated memory, reading a garbage
     * piVar18[0] (e.g. 4249536) used as an array index and crashing on the resulting wild
     * write. Initialized to 0 to match the buffer's real (empty) population state.
     *
     * The exact same defect class recurs at local_9c18 just below (used the identical way -
     * `if (local_9c18 != 0) { pcVar31 = local_9c14; do { ... } while (--local_9c18 != 0); }`
     * over its own never-populated buffer local_9c14) - also never written anywhere in this
     * function. Live-verified: it crashed next, reading through pcVar31 at address 0xc0000000.
     * Fixed the same way, for the same reason. */
    local_9cc8 = 0;
    local_9c18 = 0;
    extraOutputWords = ((int (*)())FUN_000cd1b0)(*param_5,auStack_c148,auStack_9d1c);
    if (extraOutputWords != 0) {
      return 2;
    }
    extraOutputWords = 0;
    puVar37 = auStack_96d0;
    do {
      _memcpy((int)compileRecord[3] + extraOutputWords,puVar37,0x48);
      ppppppuVar15 = compileRecord[3];
      if ((*(int *)(extraOutputWords + (int)ppppppuVar15) == 1) &&
         (*(char *)((int)ppppppuVar15 + extraOutputWords + 8) == '\x0f')) {
        *(char *)((int)ppppppuVar15 + extraOutputWords + 8) = (char)local_c024;
      }
      extraOutputWords = extraOutputWords + 0x48;
      puVar37 = puVar37 + 0x48;
    } while (extraOutputWords != 0x9360);
    iVar20 = 0;
    extraOutputWords = 0;
    shadowExtraWords = 0;
    iVar43 = 0x1a20;
    piVar18 = param_2 + 0x594;
    do {
      uVar21 = *(uint *)((int)local_9c84 + extraOutputWords) | *(uint *)((int)local_88 + extraOutputWords + 0x188);
      *(uint *)(((unsigned char *)0x000010b8) + (int)(*compileRecord + iVar20)) = uVar21;
      if (uVar21 != 0) {
        iVar24 = param_2[0x7c7];
        pbVar25 = (byte *)(piVar18 + 2);
        piVar44 = (int *)((int)param_2 + iVar43);
        iVar30 = shadowExtraWords;
        do {
          bVar7 = (byte)uVar21;
          uVar21 = uVar21 >> 1;
          iVar16 = iVar30 + iVar24;
          *pbVar25 = bVar7 & 1;
          iVar30 = iVar30 + 1;
          pbVar25 = pbVar25 + 1;
          *piVar44 = iVar16;
          piVar44 = piVar44 + 1;
        } while (uVar21 != 0);
      }
      bVar3 = iVar20 != 7;
      extraOutputWords = extraOutputWords + 4;
      shadowExtraWords = shadowExtraWords + 0x20;
      piVar18 = piVar18 + 8;
      iVar43 = iVar43 + 0x80;
      iVar20 = iVar20 + 1;
    } while (bVar3);
    if (*(int *)(((unsigned char *)0x000010b8) + (int)*compileRecord) == 0) {
      *(undefined4 *)(((unsigned char *)0x000010d8) + (int)*compileRecord) = 0;
    }
    for (; iStack_318 != 0; iStack_318 = iStack_318 + -1) {
    }
    if (local_9cc8 != 0) {
      uVar35 = 0;
      uVar21 = local_9cc8;
      do {
        piVar18 = (int *)(uVar35 * 0x24 + local_9cbc);
        switch(piVar18[2]) {
        case 1:
          extraOutputWords = piVar18[1];
          ppppppuVar15 = *compileRecord;
          shadowExtraWords = *piVar18;
          /* issue #64 live-repro (crash #5, past the local_2c-cluster fix): this if-chain
           * checks extraOutputWords (piVar18[1]) against exactly {1,0,2,3}, each mapping to one of 4
           * consecutive byte offsets (0x24,0x23,0x25,0x26 respectively - i.e. really just
           * `0x23 + extraOutputWords` for extraOutputWords in that 2-bit range), but leaves ppppppuVar17 NULL for
           * any other value - a classic decompiled-masked-switch defect (Ghidra shows the
           * post-mask compares but drops the `& 3` itself; this project already carries
           * Tools/userspace/switch_ranges.py for the general form of this class). Live-verified
           * on real hardware: piVar18[1] held 128 (0x80) in a real run - not garbage, since
           * piVar18[2]==1 correctly selected this case and piVar18[0]==3 was a sane shadowExtraWords -
           * and its low 2 bits (128 & 3 == 0) are exactly the "extraOutputWords==0" case per the pattern
           * above, so the field is genuinely wider than 2 bits and this chain must mask it
           * before comparing. Rewritten to mask first; behavior for the four originally-
           * handled raw values (0-3, already within the mask's range) is unchanged. */
          extraOutputWords = extraOutputWords & 3;
          if (extraOutputWords == 1) {
            ppppppuVar17 = ppppppuVar15 + shadowExtraWords * 4 + 0x24;
          }
          else if (extraOutputWords == 0) {
            ppppppuVar17 = ppppppuVar15 + shadowExtraWords * 4 + 0x23;
          }
          else if (extraOutputWords == 2) {
            ppppppuVar17 = ppppppuVar15 + shadowExtraWords * 4 + 0x25;
          }
          else {
            ppppppuVar17 = ppppppuVar15 + shadowExtraWords * 4 + 0x26;
          }
          *ppppppuVar17 = (uint *****)piVar18[5];
          uVar21 = local_9cc8;
          break;
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 0xb:
        case 0xc:
        case 0xd:
          ((int (*)())ilPushDclRecord)(compileRecord + 0x48,piVar18);
          uVar21 = local_9cc8;
        }
        uVar35 = uVar35 + 1;
      } while (uVar35 < uVar21);
    }
    if (local_9c18 != 0) {
      extraOutputWords = 0;
      pcVar31 = local_9c14;
      if (local_9c18 == 0) {
        local_9c18 = 1;
      }
      do {
        cVar6 = *pcVar31;
        pcVar31 = pcVar31 + 0xc;
        if (cVar6 != '\x02') {
          extraOutputWords = extraOutputWords + 1;
        }
        if (cVar6 == '\x04') {
          *(undefined1 *)((int)param_2 + 0x1e2e) = 1;
          param_2[0x7a3] = local_c024 + 2;
        }
        local_9c18 = local_9c18 + -1;
      } while (local_9c18 != 0);
      shadowExtraWords = 1;
      if (8 < extraOutputWords) goto LAB_000ccf90;
    }
    shadowExtraWords = 0;
LAB_000ccf90:
    iVar20 = 0x10;
    extraOutputWords = 0;
    do {
      compileRecord[1][extraOutputWords * 4 + 0x42] = (uint *****)0x0;
      compileRecord[1][extraOutputWords * 4 + 0x43] = (uint *****)0x1;
      compileRecord[1][extraOutputWords * 4 + 0x44] = (uint *****)0x2;
      compileRecord[1][extraOutputWords * 4 + 0x45] = (uint *****)0x3;
      iVar20 = iVar20 + -1;
      extraOutputWords = extraOutputWords + 1;
    } while (iVar20 != 0);
    _free(local_9cbc);
    _free(ilWordCount);
    if (iVar13 != 0) {
      _free(iVar13);
    }
    if (puVar34 != (uint *)0x0) {
      _free(puVar34);
    }
    return shadowExtraWords;
  }
  ppppppuVar15 = (uint ******)*puVar22;
  uVar12 = (uint)ppppppuVar15 & 0xffff;
  if (100 < uVar12) {
switchD_000cb23c_caseD_0:
                    
    _exit(0);
  }
  puVar23 = puVar22;
  switch(uVar12) {
  case 0:
  case 0x17:
  case 0x1b:
  case 0x36:
  case 0x42:
  case 0x43:
  case 0x4f:
  case 0x5f:
  case 0x60:
  case 0x61:
    goto switchD_000cb23c_caseD_0;
  default:
    local_88 = &local_c08c;
    if (bVar5) {
      bVar5 = false;
      writeCursor = (uint *******)
                   ((int (*)())ilEmitPrologue)(writeCursor,local_88,pppppppuVar19,puVar22,puVar22,staleArgR8,local_88,
                                pppppppuVar28);
    }
    pppppppuVar19 = (uint *******)((int)((unsigned char *)0x0) + 1);
    readCursor = (uint *)((int (*)())ilCopyInstructionRemapped)(&writeCursor,&readCursor,1,1,local_88);
    puVar23 = readCursor;
    pppppppuVar36 = writeCursor;
    goto switchD_000cbc48_caseD_18;
  case 3:
  case 0xc:
  case 0x13:
  case 0x1f:
  case 0x20:
  case 0x22:
  case 0x23:
  case 0x24:
  case 0x41:
  case 0x44:
  case 0x45:
  case 0x46:
  case 0x49:
  case 0x4e:
  case 0x52:
  case 0x56:
  case 0x5b:
    local_88 = &local_c08c;
    if (bVar5) {
      bVar5 = false;
      writeCursor = (uint *******)
                   ((int (*)())ilEmitPrologue)(writeCursor,local_88,pppppppuVar19,puVar22,puVar22,staleArgR8,local_88,
                                pppppppuVar28);
    }
    pppppppuVar19 = (uint *******)((int)((unsigned char *)0x0) + 1);
    readCursor = (uint *)((int (*)())ilCopyInstructionRemapped)(&writeCursor,&readCursor,1,2,local_88);
    puVar23 = readCursor;
    pppppppuVar36 = writeCursor;
    goto switchD_000cbc48_caseD_18;
  case 6:
  case 0x10:
  case 0x27:
  case 0x29:
  case 0x2a:
  case 0x2b:
  case 0x4b:
  case 0x53:
    readCursor = puVar22 + 1;
    *writeCursor = ppppppuVar15;
    puVar23 = readCursor;
    pppppppuVar36 = writeCursor + 1;
    goto switchD_000cbc48_caseD_18;
  case 7:
  case 0x11:
  case 0x34:
    pppppppuVar19 = (uint *******)0x0;
    readCursor = (uint *)((int (*)())ilCopyInstructionRemapped)(&writeCursor,&readCursor,0,2,&local_c08c);
    puVar23 = readCursor;
    pppppppuVar36 = writeCursor;
    goto switchD_000cbc48_caseD_18;
  case 8:
  case 0x15:
  case 0x16:
  case 0x32:
    *writeCursor = ppppppuVar15;
    readCursor = puVar22 + 2;
    writeCursor[1] = (uint ******)puVar22[1];
    puVar23 = readCursor;
    pppppppuVar36 = writeCursor + 2;
    goto switchD_000cbc48_caseD_18;
  case 9:
  case 0x14:
  case 0x1d:
    *writeCursor = ppppppuVar15;
    writeCursor[1] = (uint ******)puVar22[1];
    readCursor = puVar22 + 3;
    writeCursor[2] = (uint ******)puVar22[2];
    puVar23 = readCursor;
    pppppppuVar28 = writeCursor + 3;
    pppppppuVar36 = writeCursor + 3;
    goto switchD_000cbc48_caseD_18;
  case 10:
  case 0xd:
  case 0x21:
  case 0x2f:
  case 0x3f:
  case 0x40:
  case 100:
    local_88 = &local_c08c;
    if (bVar5) {
      bVar5 = false;
      writeCursor = (uint *******)
                   ((int (*)())ilEmitPrologue)(writeCursor,local_88,pppppppuVar19,puVar22,puVar22,staleArgR8,local_88,
                                pppppppuVar28);
    }
    pppppppuVar19 = (uint *******)((int)((unsigned char *)0x0) + 1);
    readCursor = (uint *)((int (*)())ilCopyInstructionRemapped)(&writeCursor,&readCursor,1,3,local_88);
    puVar23 = readCursor;
    pppppppuVar36 = writeCursor;
    goto switchD_000cbc48_caseD_18;
  case 0xf:
    readCursor = puVar22 + 2;
    *writeCursor = ppppppuVar15;
    writeCursor[1] = (uint ******)puVar22[1];
    pppppppuVar36 = writeCursor + 2;
    for (uVar12 = (uint)*(ushort *)((int)puVar22 + 6); puVar23 = readCursor, uVar12 != 0;
        uVar12 = uVar12 - 1) {
      ppppppuVar15 = (uint ******)*readCursor;
      readCursor = readCursor + 1;
      *pppppppuVar36 = ppppppuVar15;
      pppppppuVar36 = pppppppuVar36 + 1;
    }
  case 0x18:
    goto switchD_000cbc48_caseD_18;
  case 0x19:
    readCursor = puVar22 + 1;
    if (((uint)ppppppuVar15 & 0x18000000) == 0) {
      uVar12 = *(uint *)((int)local_9dd4 + ((uint)ppppppuVar15 >> 0xe & 0x3fc));
      if (uVar12 != 2) {
        uVar12 = 1;
      }
      ppppppuVar15 = (uint ******)((uVar12 & 3) << 0x1b | (uint)ppppppuVar15 & 0xe7ffffff);
    }
    *writeCursor = ppppppuVar15;
    puVar23 = readCursor;
    pppppppuVar36 = writeCursor + 1;
    goto switchD_000cbc48_caseD_18;
  case 0x1a:
    readCursor = puVar22 + 1;
    *writeCursor = ppppppuVar15;
    pppppppuVar28 = writeCursor + 1;
    if ((int)ppppppuVar15 < 0) {
      ppppppuVar15 = (uint ******)*readCursor;
      readCursor = puVar22 + 2;
      writeCursor[1] = ppppppuVar15;
      pppppppuVar28 = writeCursor + 2;
    }
    writeCursor = pppppppuVar28;
    ppppppuVar15 = (uint ******)*readCursor;
    readCursor = readCursor + 1;
    *writeCursor = ppppppuVar15;
    puVar23 = readCursor;
    pppppppuVar28 = pppppppuVar36;
    pppppppuVar36 = writeCursor + 1;
    goto switchD_000cbc48_caseD_18;
  case 0x1c:
    readCursor = puVar22 + 1;
    pppppppuVar19 = writeCursor + 1;
    *writeCursor = ppppppuVar15;
    puVar23 = readCursor;
    pppppppuVar36 = pppppppuVar19;
    if ((puVar22[1] >> 0x10 & 0x3f) - 1 < 2) {
      writeCursor[1] = (uint ******)puVar22[1];
      staleArgR8 = writeCursor + 6;
      writeCursor[2] = (uint ******)puVar22[2];
      writeCursor[3] = (uint ******)puVar22[3];
      writeCursor[4] = (uint ******)puVar22[4];
      readCursor = puVar22 + 6;
      writeCursor[5] = (uint ******)puVar22[5];
      puVar23 = readCursor;
      pppppppuVar28 = writeCursor + 5;
      pppppppuVar36 = staleArgR8;
    }
    goto switchD_000cbc48_caseD_18;
  case 0x28:
    readCursor = puVar22 + 1;
    puVar45 = (undefined4 *)
              ((int (*)())FUN_000c7930)(writeCursor,&local_c08c,pppppppuVar19,puVar22,readCursor,staleArgR8,uVar12 * 4)
    ;
    *puVar45 = ppppppuVar15;
    puVar23 = readCursor;
    pppppppuVar36 = (uint *******)(puVar45 + 1);
    goto switchD_000cbc48_caseD_18;
  case 0x35:
    pppppppuVar19 = &local_c08c;
    *writeCursor = ppppppuVar15;
    readCursor = puVar22 + 2;
    local_c1c0[0] = (uint ******)puVar22[1];
    writeCursor = writeCursor + 1;
    ((int (*)())ilRemapSourceOperandRegister)(local_c1c0,auStack_c1b4,pppppppuVar19);
    *writeCursor = local_c1c0[0];
    puVar23 = readCursor;
    pppppppuVar36 = writeCursor + 1;
    goto switchD_000cbc48_caseD_18;
  case 0x37:
  case 0x3e:
    pppppppuVar19 = (uint *******)0x0;
    break;
  case 0x3b:
    pppppppuVar19 = (uint *******)((int)((unsigned char *)0x0) + 1);
    break;
  case 0x5d:
    local_88 = &local_c08c;
    if (bVar5) {
      bVar5 = false;
      writeCursor = (uint *******)
                   ((int (*)())ilEmitPrologue)(writeCursor,local_88,pppppppuVar19,puVar22,puVar22,staleArgR8,local_88,
                                pppppppuVar28);
      puVar22 = readCursor;
    }
    ppppppuVar15 = (uint ******)*puVar22;
    puVar23 = puVar22 + 1;
    uVar12 = (uint)ppppppuVar15 >> 0x10;
    uVar27 = uVar12 & 0xff;
    bVar4 = ((uint)ppppppuVar15 & 0x80000000) != 0;
    if (bVar4) {
      puVar23 = puVar22 + 2;
      ppppppuVar17 = (uint ******)puVar22[1];
    }
    else {
      ppppppuVar17 = (uint ******)0x0;
    }
    bVar1 = ((uint)ppppppuVar15 >> 0x1e & 1) != 0;
    if (bVar1) {
      ppppppuVar39 = (uint ******)*puVar23;
      puVar23 = puVar23 + 1;
    }
    else {
      ppppppuVar39 = (uint ******)0x0;
    }
    local_c1f0 = (uint *******)*puVar23;
    puVar22 = puVar23 + 1;
    if (((uint)local_c1f0 & 0x400000) != 0) {
      puVar22 = puVar23 + 2;
      calleeSavedR15 = (uint ******)puVar23[1];
    }
    local_c1cc = (uint ******)*puVar22;
    readCursor = puVar22 + 1;
    if (((uint)local_c1cc & 0x400000) != 0) {
      local_c1d8 = (uint ******)puVar22[1];
      readCursor = puVar22 + 2;
    }
    uVar9 = (uint)ppppppuVar15 & 0xc000000;
    if (uVar9 == 0x4000000) {
LAB_000cc2a4:
      if (depthTextureUnitMask << (uVar12 & 0x3f) == 0) {
        local_84 = (uint ******)&local_c1cc;
        pppppppuVar36 = (uint *******)0x0;
        uVar42 = 1 << (uVar12 & 0x3f);
        ppppppuVar14 = (uint ******)&local_c1d8;
      }
      else {
        local_84 = (uint ******)&local_c1cc;
        local_70 = (uint ******)&local_c1d8;
        writeCursor = (uint *******)((int (*)())ilEmitProjectiveDivide)(local_88,local_84,local_70,uVar27,writeCursor);
        ppppppuVar14 = local_70;
        if (((uint)local_c1f0 & 0x400000) == 0) {
          pppppppuVar36 = (uint *******)0x0;
          uVar42 = 1 << (uVar12 & 0x3f);
        }
        else {
          local_c1f0 = (uint *******)((uint)local_c1f0 & 0xffbfffff);
          pppppppuVar36 = (uint *******)((int)((unsigned char *)0x0) + 1);
          uVar42 = 1 << (uVar12 & 0x3f);
          local_c1e4 = calleeSavedR15;
        }
      }
    }
    else if (uVar9 == 0x8000000) {
      uVar42 = 1 << (uVar12 & 0x3f);
      if ((uVar42 & shadowCompareUnitMask) != 0) goto LAB_000cc2a4;
      local_84 = (uint ******)&local_c1cc;
      pppppppuVar36 = (uint *******)0x0;
      ppppppuVar14 = (uint ******)&local_c1d8;
    }
    else {
      pppppppuVar36 = (uint *******)0x0;
      uVar42 = 1 << (uVar12 & 0x3f);
      local_84 = (uint ******)&local_c1cc;
      ppppppuVar14 = (uint ******)&local_c1d8;
    }
    pppppppuVar19 = local_88;
    ((int (*)())ilRemapSourceOperandRegister)(local_84,ppppppuVar14,local_88);
    *writeCursor = ppppppuVar15;
    pppppppuVar28 = writeCursor + 1;
    if (bVar4) {
      writeCursor[1] = ppppppuVar17;
      pppppppuVar28 = writeCursor + 2;
    }
    writeCursor = pppppppuVar28;
    if (bVar1) {
      *writeCursor = ppppppuVar39;
      writeCursor = writeCursor + 1;
    }
    *writeCursor = (uint ******)local_c1f0;
    pppppppuVar28 = writeCursor + 1;
    if (((uint)local_c1f0 & 0x400000) != 0) {
      writeCursor[1] = calleeSavedR15;
      pppppppuVar28 = writeCursor + 2;
    }
    writeCursor = pppppppuVar28;
    *writeCursor = local_c1cc;
    pppppppuVar28 = (uint *******)((uint)local_c1cc & 0x400000);
    pppppppuVar11 = writeCursor + 1;
    if (pppppppuVar28 != (uint *******)0x0) {
      writeCursor[1] = local_c1d8;
      pppppppuVar11 = writeCursor + 2;
    }
    writeCursor = pppppppuVar11;
    if (((uVar9 == 0x4000000) || ((uVar9 == 0x8000000 && ((uVar42 & shadowCompareUnitMask) != 0)))) &&
       (depthTextureUnitMask << (uVar12 & 0x3f) != 0)) {
      pppppppuVar19 = (uint *******)&local_c1f0;
      writeCursor = (uint *******)
                   ((int (*)())ilEmitShadowCompare)(local_88,local_84,pppppppuVar19,&local_c1e4,uVar27,pppppppuVar36,
                                writeCursor,pppppppuVar28);
      staleArgR8 = pppppppuVar36;
    }
    uVar42 = uVar42 & depthTextureUnitMask;
    ppppppuVar15 = calleeSavedR15;
    goto joined_r0x000cc708;
  case 0x5e:
    if (bVar5) {
      bVar5 = false;
      writeCursor = (uint *******)
                   ((int (*)())ilEmitPrologue)(writeCursor,&local_c08c,pppppppuVar19,puVar22,puVar22,staleArgR8,
                                uVar12 * 4,pppppppuVar28);
      puVar22 = readCursor;
    }
    ppppppuVar15 = (uint ******)*puVar22;
    puVar23 = puVar22 + 1;
    uVar12 = (uint)ppppppuVar15 >> 0x10;
    uVar27 = uVar12 & 0xff;
    bVar4 = ((uint)ppppppuVar15 & 0x80000000) != 0;
    if (bVar4) {
      puVar23 = puVar22 + 2;
      ppppppuVar17 = (uint ******)puVar22[1];
    }
    else {
      ppppppuVar17 = (uint ******)0x0;
    }
    bVar1 = ((uint)ppppppuVar15 & 0x40000000) != 0;
    if (bVar1) {
      ppppppuVar39 = (uint ******)*puVar23;
      puVar23 = puVar23 + 1;
    }
    else {
      ppppppuVar39 = (uint ******)0x0;
    }
    local_c1f0 = (uint *******)*puVar23;
    puVar22 = puVar23 + 1;
    if (((uint)local_c1f0 & 0x400000) != 0) {
      puVar22 = puVar23 + 2;
      calleeSavedR14 = (uint ******)puVar23[1];
    }
    local_c1d8 = (uint ******)*puVar22;
    puVar23 = puVar22 + 1;
    if (((uint)local_c1d8 & 0x400000) != 0) {
      local_c1cc = (uint ******)puVar22[1];
      puVar23 = puVar22 + 2;
    }
    local_c1d4 = (uint ******)*puVar23;
    readCursor = puVar23 + 1;
    if (((uint)local_c1d4 & 0x400000) != 0) {
      local_c1c8 = (uint ******)puVar23[1];
      readCursor = puVar23 + 2;
    }
    uVar9 = (uint)ppppppuVar15 & 0xc000000;
    if (uVar9 == 0x4000000) {
LAB_000cc588:
      if (depthTextureUnitMask << (uVar12 & 0x3f) != 0) {
        pppppppuVar19 = &local_c1cc;
        writeCursor = (uint *******)
                     ((int (*)())ilEmitProjectiveDivide)(&local_c08c,&local_c1d8,pppppppuVar19,uVar27,writeCursor);
        if (((uint)local_c1f0 & 0x400000) != 0) {
          local_c1f0 = (uint *******)((uint)local_c1f0 & 0xffbfffff);
          staleArgR8 = (uint *******)((int)((unsigned char *)0x0) + 1);
          uVar42 = 1 << (uVar12 & 0x3f);
          local_c1e4 = calleeSavedR14;
          goto LAB_000cc5e4;
        }
      }
LAB_000cc5bc:
      staleArgR8 = (uint *******)0x0;
      uVar42 = 1 << (uVar12 & 0x3f);
    }
    else {
      if (uVar9 != 0x8000000) goto LAB_000cc5bc;
      staleArgR8 = (uint *******)0x0;
      uVar42 = 1 << (uVar12 & 0x3f);
      if ((uVar42 & shadowCompareUnitMask) != 0) goto LAB_000cc588;
    }
LAB_000cc5e4:
    *writeCursor = ppppppuVar15;
    pppppppuVar28 = writeCursor + 1;
    if (bVar4) {
      writeCursor[1] = ppppppuVar17;
      pppppppuVar28 = writeCursor + 2;
    }
    writeCursor = pppppppuVar28;
    if (bVar1) {
      *writeCursor = ppppppuVar39;
      writeCursor = writeCursor + 1;
    }
    *writeCursor = (uint ******)local_c1f0;
    pppppppuVar28 = writeCursor + 1;
    if (((uint)local_c1f0 & 0x400000) != 0) {
      writeCursor[1] = calleeSavedR14;
      pppppppuVar28 = writeCursor + 2;
    }
    writeCursor = pppppppuVar28;
    *writeCursor = local_c1d8;
    pppppppuVar28 = (uint *******)((uint)local_c1d8 & 0x400000);
    pppppppuVar36 = writeCursor + 1;
    if (pppppppuVar28 != (uint *******)0x0) {
      writeCursor[1] = local_c1cc;
      pppppppuVar36 = writeCursor + 2;
    }
    writeCursor = pppppppuVar36;
    *writeCursor = local_c1d4;
    pppppppuVar36 = writeCursor + 1;
    if (((uint)local_c1d4 & 0x400000) != 0) {
      writeCursor[1] = local_c1c8;
      pppppppuVar36 = writeCursor + 2;
    }
    writeCursor = pppppppuVar36;
    if (((uVar9 == 0x4000000) || ((uVar9 == 0x8000000 && ((uVar42 & shadowCompareUnitMask) != 0)))) &&
       (depthTextureUnitMask << (uVar12 & 0x3f) != 0)) {
      pppppppuVar19 = (uint *******)&local_c1f0;
      writeCursor = (uint *******)
                   ((int (*)())ilEmitShadowCompare)(&local_c08c,&local_c1d8,pppppppuVar19,&local_c1e4,uVar27,staleArgR8,
                                writeCursor,pppppppuVar28);
    }
    uVar42 = uVar42 & depthTextureUnitMask;
    ppppppuVar15 = calleeSavedR14;
joined_r0x000cc708:
    puVar23 = readCursor;
    pppppppuVar36 = writeCursor;
    if (uVar42 != 0) {
      staleArgR8 = writeCursor + 1;
      *writeCursor = (uint ******)0x47;
      pppppppuVar28 = local_c1f0;
      if (((uint)local_c1f0 & 0x400000) == 0) {
        pppppppuVar28 = (uint *******)((uint)local_c1f0 | 0x400000);
        ppppppuVar15 = (uint ******)0x55;
      }
      if (depthTextureMode[uVar27] == 0x1906) {
        if (((uint)ppppppuVar15 & 3) == 1) {
          ppppppuVar15 = (uint ******)((uint)ppppppuVar15 & 0xfffffffc | 2);
        }
        if (((uint)ppppppuVar15 & 0xc) == 4) {
          ppppppuVar15 = (uint ******)((uint)ppppppuVar15 & 0xfffffff3 | 8);
        }
        if (((uint)ppppppuVar15 & 0x30) == 0x10) {
          ppppppuVar15 = (uint ******)((uint)ppppppuVar15 & 0xffffffcf | 0x20);
        }
      }
      else if ((depthTextureMode[uVar27] == 0x1909) && (((uint)ppppppuVar15 & 0xc0) == 0x40)) {
        ppppppuVar15 = (uint ******)((uint)ppppppuVar15 & 0xffffff3f | 0xc0);
      }
      *staleArgR8 = (uint ******)pppppppuVar28;
      writeCursor[2] = ppppppuVar15;
      writeCursor[3] = (uint ******)((uint)pppppppuVar28 & 0x3fffff);
      pppppppuVar36 = writeCursor + 4;
    }
    goto switchD_000cbc48_caseD_18;
  }
  readCursor = (uint *)((int (*)())ilCopyInstructionRemapped)(&writeCursor,&readCursor,pppppppuVar19,1,&local_c08c);
  puVar23 = readCursor;
  pppppppuVar36 = writeCursor;
  goto switchD_000cbc48_caseD_18;
}
#undef local_c08c
#undef local_c080
#undef local_c070
#undef local_c06c
#undef local_c068
#undef local_c064
#undef local_c060
#undef local_c050
#undef local_c04c
#undef local_c048
#undef local_c044

/* FUN_000cd05c @ 0xcd05c (176 bytes) */
int FUN_000cd05c(param_1, param_2, param_3)
  int param_1;
  int param_2;
  uint param_3;
{
  int a1;
  int iVar1;
  
  if ((((((param_1 == 0) || (*(code **)(param_1 + 0x30) == (code *)0x0)) ||
        (*(int *)(param_1 + 0x34) == 0)) ||
       ((*(int *)(param_1 + 0x38) == 0 || (*(int *)(param_1 + 0x40) == 0)))) ||
      ((*(int *)(param_1 + 0x44) == 0 ||
       ((*(int *)(param_1 + 0x48) == 0 || (*(int *)(param_1 + 0x4c) == 0)))))) ||
     ((param_2 == 0 ||
      (a1 = (**(code **)(param_1 + 0x30))(*(undefined4 *)(param_1 + 0x2c),0x44,param_3), a1 == 0))))
  {
    a1 = 0;
  }
  else {
    FUN_000da0c0(a1,param_1);
    iVar1 = FUN_000da420(a1);
    if (iVar1 != 0) {
      scDestroyCompilerObject(a1,1);
      (**(code **)(param_1 + 0x34))(*(undefined4 *)(param_1 + 0x2c),a1,param_3);
      a1 = 0;
    }
  }
  return a1;
}

/* scDestroy @ 0xcd154 (92 bytes) */
int scDestroy(param_1)
  undefined4 *param_1;
{
  undefined4 uVar1;
  code *pcVar2;
  
  uVar1 = 3;
  if (param_1 != (undefined4 *)0x0) {
    pcVar2 = (code *)*param_1;
    uVar1 = param_1[1];
    scDestroyCompilerObject(param_1,1);
    (*pcVar2)(uVar1,param_1);
    uVar1 = 0;
  }
  return uVar1;
}

/* FUN_000cd1b0 @ 0xcd1b0 (20 bytes) */
int FUN_000cd1b0(compilerHandle, param_2, param_3)
  int compilerHandle;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined4 uVar1;
  
  if (compilerHandle != 0) {
    uVar1 = scSetCallbackTables(compilerHandle,param_2,param_3);
    return uVar1;
  }
  return 3;
}

/* FUN_000cd1c4 @ 0xcd1c4 (92 bytes) */
int FUN_000cd1c4(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
{
  int iStack00000018Word314;
  int iVar1;
  int iVar2;
  int iStack00000018;
  int iStack0000001c;
  undefined4 uStack00000020;
  undefined4 uStack00000024;
  undefined4 uStack00000028;
  
  if (param_1 == 0) {
    return 3;
  }
  iStack00000018 = *(int *)(param_1 + 8);
  *(int *)(param_1 + 0x3c) = param_4;
  *(int *)(param_1 + 0x30) = param_2;
  *(int *)(param_1 + 0x34) = param_3;
  *(int *)(param_1 + 0x2c) = param_2;
  if (iStack00000018 != 0) {
    uStack00000028 = *(undefined4 *)(param_2 + 0x54);
    uStack00000024 = *(undefined4 *)(param_3 + 0x4c);
    uStack00000020 = *(undefined4 *)(param_2 + 0x4c);
    *(int *)(iStack00000018 + 0x398) = param_1;
    iStack0000001c = param_4;
    FUN_000e0ca8(iStack00000018);
    do {
      iVar1 = _setjmp(*(int **)(iStack00000018 + 4));
      if (iVar1 == 0) {
        Compiler__resetState(iStack00000018);
        FUN_000e0cd0(iStack00000018,uStack00000028);
        iVar1 = FUN_00193b3c(uStack00000020,uStack00000024,iStack00000018);
        *(int *)(iStack00000018 + 0x524) = iStack0000001c;
        *(undefined4 *)(iStack0000001c + 0xf8) = 0;
        *(undefined4 *)(iStack0000001c + 0xfc) =
             *(undefined4 *)(*(int *)(iStack00000018 + 0x398) + 0x28);
        FUN_000e2094(iStack00000018,iVar1);
        if (iVar1 != 0) {
          FUN_00193be8(iVar1);
          Arena__free(*(undefined4 *)(iVar1 + -4),iVar1 + -4);
        }
      }
      *(undefined4 *)(iStack00000018 + 0x4d8) = 0;
      *(undefined4 *)(iStack00000018 + 0x484) = 0;
      *(undefined4 *)(iStack00000018 + 0x4d4) = 0;
      *(undefined4 *)(iStack00000018 + 0x488) = 0;
      iStack00000018Word314 = *(int *)(iStack00000018 + 0x314);
      FUN_000e0e28(iStack00000018);
      Compiler__releaseChipAndPools(iStack00000018,0);
    } while ((iStack00000018Word314 != 0) && (iVar2 = FUN_000e161c(iStack00000018,iStack00000018Word314), iVar2 != 0));
    return iStack00000018Word314;
  }
  return 2;
}

/* scCheckHandle @ 0xcd1d8 (20 bytes) */
int scCheckHandle(param_1)
  int param_1;
{
  if (param_1 == 0) {
    return 3;
  }
  return 0;
}

/* scDisassembleIL @ 0xcd1ec (40 bytes) */
int scDisassembleIL(sinkArg, tokenStart, tokenCount, param_4)
  undefined4 sinkArg;
  undefined4 tokenStart;
  undefined4 tokenCount;
  undefined4 param_4;
{
  unsigned int ghidra_home[8] = { sinkArg, tokenStart, tokenCount, param_4, 0, 0, 0, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  
  (*(unsigned int *)((unsigned char *)ghidra_home + 12)) = param_4;
  return ((int (*)())scDisassembleILImpl)(sinkArg,tokenStart,tokenCount,&(*(unsigned int *)((unsigned char *)ghidra_home + 12)));
}

/* scDumpSrcShader @ 0xcd214 (40 bytes) */
int scDumpSrcShader(sinkContext, shaderState, sinkRecord, argR6, argR7Text, argR8Text, argR9Text, argR10Text)
  undefined4 sinkContext;
  undefined4 shaderState;
  undefined4 sinkRecord;
  undefined4 argR6;
  undefined4 argR7Text;
  undefined4 argR8Text;
  undefined4 argR9Text;
  undefined4 argR10Text;
{
  unsigned int ghidra_home[8] = { sinkContext, shaderState, sinkRecord, argR6, argR7Text, argR8Text, argR9Text, argR10Text };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  
  (*(unsigned int *)((unsigned char *)ghidra_home + 8)) = sinkRecord;
  return ((int (*)())scDumpSrcShaderImpl)(sinkContext,shaderState,&(*(unsigned int *)((unsigned char *)ghidra_home + 8)),argR6,argR7Text,argR8Text,argR9Text,argR10Text);
}

/* scDumpShader @ 0xcd23c (40 bytes) */
int scDumpShader(sinkArg, shaderState, optionsArg, argR6, sinkFn, argR8, argR9)
  undefined4 sinkArg;
  undefined4 shaderState;
  undefined4 optionsArg;
  undefined4 argR6;
  undefined4 sinkFn;
  undefined4 argR8;
  undefined4 argR9;
{
  unsigned int ghidra_home[8] = { sinkArg, shaderState, optionsArg, argR6, sinkFn, argR8, argR9, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  
  (*(unsigned int *)((unsigned char *)ghidra_home + 16)) = sinkFn;
  return ((int (*)())scDumpShaderImpl)(sinkArg,shaderState,optionsArg,argR6,&(*(unsigned int *)((unsigned char *)ghidra_home + 16)),argR8,argR9);
}

/* scDumpShaderToString @ 0xcd264 (40 bytes) */
int scDumpShaderToString(sinkArg, shaderState, sinkFn, argR6, argR7, argR8, argR9)
  undefined4 sinkArg;
  undefined4 shaderState;
  undefined4 sinkFn;
  undefined4 argR6;
  undefined4 argR7;
  undefined4 argR8;
  undefined4 argR9;
{
  unsigned int ghidra_home[8] = { sinkArg, shaderState, sinkFn, argR6, argR7, argR8, argR9, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  
  (*(unsigned int *)((unsigned char *)ghidra_home + 8)) = sinkFn;
  return ((int (*)())scDumpShaderToStringImpl)(sinkArg,shaderState,&(*(unsigned int *)((unsigned char *)ghidra_home + 8)),argR6,argR7,argR8,argR9);
}

/* FUN_000cd290 @ 0xcd290 (88 bytes) */
int FUN_000cd290(param_1)
  undefined4 param_1;
{
  switch(param_1) {
  case 0x1a:
  case 0x1b:
  case 0x1c:
  case 0x2c:
  case 0x2d:
  case 0x2e:
  case 0x34:
  case 0x35:
  case 0x36:
  case 0x37:
  case 0x39:
    return 1;
  case 0x1d:
  case 0x38:
  case 0x3a:
  case 0x3b:
    return 2;
  default:
    return 0;
  case 0x3c:
  case 0x3d:
  case 0x3e:
  case 0x3f:
    return 3;
  }
}

/* scDisassembleILImpl @ 0xcd388 (28 bytes) */
int scDisassembleILImpl(sinkArg, tokenStart, tokenCount, sinkRecord)
  undefined4 sinkArg;
  int tokenStart;
  int tokenCount;
  int sinkRecord;
{
  if (sinkRecord == 0) {
    return;
  }
  if (tokenStart == 0) {
    return;
  }
  if (tokenCount == 0) {
    return;
  }
  return ildisDisassembleTokens(sinkArg,tokenStart,tokenCount,sinkRecord);
}

/* scLogToSink @ 0xcd3a4 (96 bytes) */
int scLogToSink(sinkContext, sinkRecord, argR5, argR6, argR7, argR8, argR9, argR10)
  undefined4 sinkContext;
  undefined4 *sinkRecord;
  undefined4 argR5;
  undefined4 argR6;
  undefined4 argR7;
  undefined4 argR8;
  undefined4 argR9;
  undefined4 argR10;
{
  unsigned int ghidra_home[8] = { sinkContext, sinkRecord, argR5, argR6, argR7, argR8, argR9, argR10 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  
  (*(unsigned int *)((unsigned char *)ghidra_home + 12)) = argR6;
  (*(unsigned int *)((unsigned char *)ghidra_home + 16)) = argR7;
  (*(unsigned int *)((unsigned char *)ghidra_home + 20)) = argR8;
  (*(unsigned int *)((unsigned char *)ghidra_home + 24)) = argR9;
  (*(unsigned int *)((unsigned char *)ghidra_home + 28)) = argR10;
  return (*(code *)*sinkRecord)(sinkContext,"",argR5,&(*(unsigned int *)((unsigned char *)ghidra_home + 12)),argR7,argR8,argR9,argR10);
}

/* scDumpSrcShaderImpl @ 0xcd404 (1952 bytes) */
int scDumpSrcShaderImpl(sinkContext, shaderState, sinkRecord, argR6, argR7Text, argR8Text, argR9Text, argR10Text)
  undefined4 sinkContext;
  int *shaderState;
  int sinkRecord;
  undefined4 argR6;
  char *argR7Text;
  undefined1 *argR8Text;
  undefined1 *argR9Text;
  undefined1 *argR10Text;
{
  undefined4 floatTextResult;
  uint constIndex;
  int constEntryOffset;
  uint nextConstIndex;
  char componentText0 [128];
  undefined1 componentText1 [128];
  undefined1 componentText2 [128];
  undefined1 componentText3 [144];
  
  if (shaderState == (int *)0x0) {
    return;
  }
  if (sinkRecord == 0) {
    return;
  }
  ((int (*)())scLogToSink)(sinkContext,sinkRecord,"; ------------- SC_SRCSHADER Dump ------------------\r\n",argR6,
               argR7Text,argR8Text,argR9Text,argR10Text);
  ((int (*)())scLogToSink)(sinkContext,sinkRecord,"SC_SHADERSTATE: u32NumIntVSConst = %d\r\n",shaderState[3],argR7Text,
               argR8Text,argR9Text,argR10Text);
  ((int (*)())scLogToSink)(sinkContext,sinkRecord,"SC_SHADERSTATE: u32NumIntPSConst = %d\r\n",shaderState[4],argR7Text,
               argR8Text,argR9Text,argR10Text);
  constIndex = shaderState[5];
  ((int (*)())scLogToSink)(sinkContext,sinkRecord,"SC_SHADERSTATE: u32NumIntGSConst = %d\r\n",constIndex,argR7Text,argR8Text,
               argR9Text,argR10Text);
  if (((shaderState[3] != 0) && (*shaderState != 0)) &&
     (((int (*)())scLogToSink)(sinkContext,sinkRecord,"\r\nSC_SHADERSTATE: *** Integer VS Constants",constIndex,argR7Text,
                   argR8Text,argR9Text,argR10Text), shaderState[3] != 0)) {
    nextConstIndex = 0;
    do {
      constIndex = nextConstIndex;
      constEntryOffset = constIndex * 0x10 + *shaderState;
      argR7Text = *(char **)(constIndex * 0x10 + *shaderState);
      argR8Text = *(undefined1 **)(constEntryOffset + 4);
      argR9Text = *(undefined1 **)(constEntryOffset + 8);
      nextConstIndex = constIndex + 1;
      ((int (*)())scLogToSink)(sinkContext,sinkRecord,
                   "SC_SHADERSTATE: i%d = Count(%d), LoopStart(%d), LoopStep(%d)\r\n",constIndex,argR7Text,
                   argR8Text,argR9Text,argR10Text);
    } while (nextConstIndex < (uint)shaderState[3]);
  }
  if ((shaderState[4] != 0) &&
     (((int (*)())scLogToSink)(sinkContext,sinkRecord,"\r\nSC_SHADERSTATE: *** Integer PS Constants",constIndex,argR7Text,
                   argR8Text,argR9Text,argR10Text), shaderState[4] != 0)) {
    nextConstIndex = 0;
    do {
      constIndex = nextConstIndex;
      constEntryOffset = constIndex * 0x10 + shaderState[1];
      argR7Text = *(char **)(constIndex * 0x10 + shaderState[1]);
      argR8Text = *(undefined1 **)(constEntryOffset + 4);
      argR9Text = *(undefined1 **)(constEntryOffset + 8);
      nextConstIndex = constIndex + 1;
      ((int (*)())scLogToSink)(sinkContext,sinkRecord,
                   "SC_SHADERSTATE: i%d = Count(%d), LoopStart(%d), LoopStep(%d)\r\n",constIndex,argR7Text,
                   argR8Text,argR9Text,argR10Text);
    } while (nextConstIndex < (uint)shaderState[4]);
  }
  if ((shaderState[5] != 0) &&
     (((int (*)())scLogToSink)(sinkContext,sinkRecord,"\r\nSC_SHADERSTATE: *** Integer GS Constants",constIndex,argR7Text,
                   argR8Text,argR9Text,argR10Text), shaderState[5] != 0)) {
    constIndex = 0;
    do {
      constEntryOffset = constIndex * 0x10 + shaderState[2];
      argR7Text = *(char **)(constIndex * 0x10 + shaderState[2]);
      argR8Text = *(undefined1 **)(constEntryOffset + 4);
      argR9Text = *(undefined1 **)(constEntryOffset + 8);
      nextConstIndex = constIndex + 1;
      ((int (*)())scLogToSink)(sinkContext,sinkRecord,
                   "SC_SHADERSTATE: i%d = Count(%d), LoopStart(%d), LoopStep(%d)\r\n",constIndex,argR7Text,
                   argR8Text,argR9Text,argR10Text);
      constIndex = nextConstIndex;
    } while (nextConstIndex < (uint)shaderState[5]);
  }
  ((int (*)())scLogToSink)(sinkContext,sinkRecord,"SC_SHADERSTATE: u32NumBoolVSConst = %d\r\n",shaderState[9],argR7Text,
               argR8Text,argR9Text,argR10Text);
  ((int (*)())scLogToSink)(sinkContext,sinkRecord,"SC_SHADERSTATE: u32NumBoolPSConst = %d\r\n",shaderState[10],argR7Text,
               argR8Text,argR9Text,argR10Text);
  constIndex = shaderState[0xb];
  ((int (*)())scLogToSink)(sinkContext,sinkRecord,"SC_SHADERSTATE: u32NumBoolGSConst = %d\r\n",constIndex,argR7Text,argR8Text,
               argR9Text,argR10Text);
  if (shaderState[9] == 0) goto LAB_000cd7d0;
  if (shaderState[6] != 0) {
    ((int (*)())scLogToSink)(sinkContext,sinkRecord,"\r\nSC_SHADERSTATE: *** Bool VS Constants",constIndex,argR7Text,argR8Text,
                 argR9Text,argR10Text);
    if (shaderState[9] == 0) goto LAB_000cd7d0;
    nextConstIndex = 0;
    do {
      argR9Text = (undefined1 *)shaderState[6];
      if (*(int *)(argR9Text + nextConstIndex * 4) == 0) {
        argR7Text = "FALSE";
      }
      else {
        argR7Text = "TRUE";
      }
      constIndex = nextConstIndex;
      ((int (*)())scLogToSink)(sinkContext,sinkRecord,"SC_SHADERSTATE: b%d = %s\r\n",nextConstIndex,argR7Text,argR8Text,argR9Text,
                   argR10Text);
      nextConstIndex = nextConstIndex + 1;
    } while (nextConstIndex < (uint)shaderState[9]);
    if (shaderState[9] == 0) goto LAB_000cd7d0;
  }
  if (shaderState[7] != 0) {
    ((int (*)())scLogToSink)(sinkContext,sinkRecord,"\r\nSC_SHADERSTATE: *** Bool PS Constants",constIndex,argR7Text,argR8Text,
                 argR9Text,argR10Text);
    if (shaderState[10] != 0) {
      nextConstIndex = 0;
      do {
        argR9Text = (undefined1 *)shaderState[7];
        if (*(int *)(argR9Text + nextConstIndex * 4) == 0) {
          argR7Text = "FALSE";
        }
        else {
          argR7Text = "TRUE";
        }
        constIndex = nextConstIndex;
        ((int (*)())scLogToSink)(sinkContext,sinkRecord,"SC_SHADERSTATE: b%d = %s\r\n",nextConstIndex,argR7Text,argR8Text,argR9Text,
                     argR10Text);
        nextConstIndex = nextConstIndex + 1;
      } while (nextConstIndex < (uint)shaderState[10]);
    }
    if (shaderState[9] == 0) goto LAB_000cd7d0;
  }
  if ((shaderState[8] != 0) &&
     (((int (*)())scLogToSink)(sinkContext,sinkRecord,"\r\nSC_SHADERSTATE: *** Bool GS Constants",constIndex,argR7Text,argR8Text
                   ,argR9Text,argR10Text), shaderState[0xb] != 0)) {
    constIndex = 0;
    do {
      argR9Text = (undefined1 *)shaderState[8];
      if (*(int *)(argR9Text + constIndex * 4) == 0) {
        argR7Text = "FALSE";
      }
      else {
        argR7Text = "TRUE";
      }
      ((int (*)())scLogToSink)(sinkContext,sinkRecord,"SC_SHADERSTATE: b%d = %s\r\n",constIndex,argR7Text,argR8Text,argR9Text,
                   argR10Text);
      constIndex = constIndex + 1;
    } while (constIndex < (uint)shaderState[0xb]);
  }
LAB_000cd7d0:
  ((int (*)())scLogToSink)(sinkContext,sinkRecord,"SC_SHADERSTATE: u32NumFloatVSConst = %d\r\n",shaderState[0xf],argR7Text,
               argR8Text,argR9Text,argR10Text);
  ((int (*)())scLogToSink)(sinkContext,sinkRecord,"SC_SHADERSTATE: u32NumFloatPSConst = %d\r\n",shaderState[0x10],argR7Text,
               argR8Text,argR9Text,argR10Text);
  constIndex = shaderState[0x11];
  ((int (*)())scLogToSink)(sinkContext,sinkRecord,"SC_SHADERSTATE: u32NumFloatGSConst = %d\r\n",constIndex,argR7Text,argR8Text,
               argR9Text,argR10Text);
  if (((shaderState[0xf] != 0) && (shaderState[0xc] != 0)) &&
     (floatTextResult = ((int (*)())scLogToSink)(sinkContext,sinkRecord,"\r\nSC_SHADERSTATE: *** Float VS Constants",constIndex,
                           argR7Text,argR8Text,argR9Text,argR10Text), shaderState[0xf] != 0)) {
    nextConstIndex = 0;
    do {
      constIndex = nextConstIndex;
      constEntryOffset = constIndex * 0x10;
      floatTextResult = ((char * (*)())FUN_000cdc3c)(floatTextResult,10,componentText0,(double)*(float *)(shaderState[0xc] + constEntryOffset));
      floatTextResult = ((char * (*)())FUN_000cdc3c)(floatTextResult,10,componentText1,(double)*(float *)(shaderState[0xc] + constEntryOffset + 4));
      floatTextResult = ((char * (*)())FUN_000cdc3c)(floatTextResult,10,componentText2,(double)*(float *)(shaderState[0xc] + constEntryOffset + 8));
      ((char * (*)())FUN_000cdc3c)(floatTextResult,10,componentText3,(double)*(float *)(shaderState[0xc] + constEntryOffset + 0xc));
      argR7Text = componentText0;
      nextConstIndex = constIndex + 1;
      argR8Text = componentText1;
      argR9Text = componentText2;
      argR10Text = componentText3;
      floatTextResult = ((int (*)())scLogToSink)(sinkContext,sinkRecord,"SC_SHADERSTATE: c%d = (%s,%s,%s,%s)\r\n",constIndex,argR7Text,
                           componentText1,componentText2,componentText3);
    } while (nextConstIndex < (uint)shaderState[0xf]);
  }
  if (((shaderState[0x10] != 0) && (shaderState[0xd] != 0)) &&
     (floatTextResult = ((int (*)())scLogToSink)(sinkContext,sinkRecord,"\r\nSC_SHADERSTATE: *** Float PS Constants",constIndex,
                           argR7Text,argR8Text,argR9Text,argR10Text), shaderState[0x10] != 0)) {
    nextConstIndex = 0;
    do {
      constIndex = nextConstIndex;
      constEntryOffset = constIndex * 0x10;
      floatTextResult = ((char * (*)())FUN_000cdc3c)(floatTextResult,10,componentText0,(double)*(float *)(shaderState[0xd] + constEntryOffset));
      floatTextResult = ((char * (*)())FUN_000cdc3c)(floatTextResult,10,componentText1,(double)*(float *)(shaderState[0xd] + constEntryOffset + 4));
      floatTextResult = ((char * (*)())FUN_000cdc3c)(floatTextResult,10,componentText2,(double)*(float *)(shaderState[0xd] + constEntryOffset + 8));
      ((char * (*)())FUN_000cdc3c)(floatTextResult,10,componentText3,(double)*(float *)(shaderState[0xd] + constEntryOffset + 0xc));
      argR7Text = componentText0;
      nextConstIndex = constIndex + 1;
      argR8Text = componentText1;
      argR9Text = componentText2;
      argR10Text = componentText3;
      floatTextResult = ((int (*)())scLogToSink)(sinkContext,sinkRecord,"SC_SHADERSTATE: c%d = (%s,%s,%s,%s)\r\n",constIndex,argR7Text,
                           componentText1,componentText2,componentText3);
    } while (nextConstIndex < (uint)shaderState[0x10]);
  }
  if (((shaderState[0x11] != 0) && (shaderState[0xe] != 0)) &&
     (floatTextResult = ((int (*)())scLogToSink)(sinkContext,sinkRecord,"\r\nSC_SHADERSTATE: *** Float GS Constants",constIndex,
                           argR7Text,argR8Text,argR9Text,argR10Text), shaderState[0x11] != 0)) {
    constIndex = 0;
    do {
      constEntryOffset = constIndex * 0x10;
      floatTextResult = ((char * (*)())FUN_000cdc3c)(floatTextResult,10,componentText0,(double)*(float *)(shaderState[0xe] + constEntryOffset));
      floatTextResult = ((char * (*)())FUN_000cdc3c)(floatTextResult,10,componentText1,(double)*(float *)(shaderState[0xe] + constEntryOffset + 4));
      floatTextResult = ((char * (*)())FUN_000cdc3c)(floatTextResult,10,componentText2,(double)*(float *)(shaderState[0xe] + constEntryOffset + 8));
      ((char * (*)())FUN_000cdc3c)(floatTextResult,10,componentText3,(double)*(float *)(shaderState[0xe] + constEntryOffset + 0xc));
      argR7Text = componentText0;
      nextConstIndex = constIndex + 1;
      argR8Text = componentText1;
      argR9Text = componentText2;
      argR10Text = componentText3;
      floatTextResult = ((int (*)())scLogToSink)(sinkContext,sinkRecord,"SC_SHADERSTATE: c%d = (%s,%s,%s,%s)\r\n",constIndex,argR7Text,
                           componentText1,componentText2,componentText3);
      constIndex = nextConstIndex;
    } while (nextConstIndex < (uint)shaderState[0x11]);
  }
  ((int (*)())scLogToSink)(sinkContext,sinkRecord,"u32Copts = 0x%08X",shaderState[0x15],argR7Text,argR8Text,argR9Text,argR10Text);
  ((int (*)())scLogToSink)(sinkContext,sinkRecord,"fConstantsAvailable = %d",shaderState[0x16],shaderState[0x17],shaderState[0x18],
               shaderState[0x19],shaderState[0x1a]);
  ((int (*)())scLogToSink)(sinkContext,sinkRecord,"iConstantsAvailable = %d",shaderState[0x1e],shaderState[0x1f],shaderState[0x20],
               shaderState[0x21],shaderState[0x22]);
  ((int (*)())scLogToSink)(sinkContext,sinkRecord,"bConstantsAvailable = %d",shaderState[0x26],shaderState[0x27],shaderState[0x28],
               shaderState[0x29],shaderState[0x2a]);
  return;
}

/* scDumpShaderImpl @ 0xcdba4 (64 bytes) */
int scDumpShaderImpl(sinkArg, shaderState, optionsArg, argR6, sinkFn, argR8, argR9)
  undefined4 sinkArg;
  int shaderState;
  undefined4 optionsArg;
  undefined4 argR6;
  int sinkFn;
  undefined4 argR8;
  undefined4 argR9;
{
  if (shaderState == 0) {
    return;
  }
  if (sinkFn == 0) {
    return;
  }
  if (2 < *(int *)(shaderState + 0xfc) - 1U) {
    return;
  }
  if (*(int *)(shaderState + 0xf8) == 0) {
    ((int (*)())vsDisassembleVertexProgram)(sinkArg,shaderState,optionsArg,sinkFn,sinkFn,argR8,shaderState);
    return;
  }
  if (*(int *)(shaderState + 0xf8) != 1) {
    return;
  }
  return scDumpPixelProgram(sinkArg,shaderState,optionsArg,sinkFn,sinkFn,argR8,shaderState);
}

/* scDumpShaderToStringImpl @ 0xcdbe4 (60 bytes) */
int scDumpShaderToStringImpl(sinkArg, shaderState, sinkFn, argR6, argR7, argR8, argR9)
  undefined4 sinkArg;
  int shaderState;
  int sinkFn;
  undefined4 argR6;
  undefined4 argR7;
  undefined4 argR8;
  undefined4 argR9;
{
  if (shaderState == 0) {
    return;
  }
  if (sinkFn == 0) {
    return;
  }
  if (2 < *(int *)(shaderState + 0xfc) - 1U) {
    return;
  }
  if (*(int *)(shaderState + 0xf8) == 0) {
    ((int (*)())vsDisassembleToString)(sinkArg,shaderState,sinkFn,argR6,argR7,argR8,shaderState);
    return;
  }
  if (*(int *)(shaderState + 0xf8) != 1) {
    return;
  }
  return scDumpPixelProgramToStringStub();
}

/* noop_cdc20 @ 0xcdc20 (4 bytes) */
int noop_cdc20()
{
  return;
}

/* scShaderStateFlag @ 0xcdc24 (24 bytes) */
int scShaderStateFlag(param_1)
  int param_1;
{
  if (*(int *)(param_1 + 0x4c) == 0) {
    return 1;
  }
  return *(undefined1 *)(*(int *)(param_1 + 0x4c) + 5);
}

/* FUN_000cdc3c @ 0xcdc3c (996 bytes) */
char * FUN_000cdc3c(undefined4 unusedArg,int significantDigits,char *outText,double value)
{
  char *exponentCursor;
  uint trimmedEnd;
  uint digitIndex;
  uint exponentMagnitude;
  uint signOffset;
  bool isNegative;
  double i2dMagic;
  double twoPow31;
  int outPosition;
  uint powerOfTen;
  char digitChar;
  char *digits;
  int scratchIndex;
  char *copyCursor;
  uint exponentDigitCount;
  uint loopIndex2;
  uint digitExponent;
  double logValue;
  double powValue;
  double digitExponentAsDouble;
  uint decimalPointOrRemainder;
  int ecvtSign [3];
  undefined4 i2dHi1;
  uint i2dLo1;
  longlong fctiwzScratch1;
  longlong fctiwzScratch2;
  undefined4 i2dHi2;
  uint i2dLo2;
  longlong fctiwzScratch3;
  longlong fctiwzScratch4;
  longlong fctiwzScratch5;
  longlong fctiwzScratch6;
  
  ecvtSign[0] = 0;
  decimalPointOrRemainder = 0;
  digits = _ecvt(value,significantDigits,(int *)&decimalPointOrRemainder,ecvtSign);
  isNegative = ecvtSign[0] != 0;
  if (isNegative) {
    *outText = '-';
  }
  signOffset = (uint)isNegative;
  if (((int)decimalPointOrRemainder < 1 - significantDigits) || (significantDigits < (int)decimalPointOrRemainder)) {
    outText[isNegative] = *digits;
    outText[signOffset + 1] = '.';
    scratchIndex = signOffset + 2;
    digitChar = digits[1];
    if (digitChar != '\0') {
      copyCursor = outText + scratchIndex;
      outPosition = 1;
      do {
        *copyCursor = digitChar;
        outPosition = outPosition + 1;
        digitChar = digits[outPosition];
        scratchIndex = scratchIndex + 1;
        copyCursor = copyCursor + 1;
      } while (digitChar != '\0');
    }
    exponentMagnitude = decimalPointOrRemainder - 1;
    outText[scratchIndex] = 'e';
    outPosition = scratchIndex + 1;
    if ((int)exponentMagnitude < 0) {
      exponentMagnitude = -exponentMagnitude;
      outText[outPosition] = '-';
      outPosition = scratchIndex + 2;
    }
    i2dLo1 = exponentMagnitude ^ 0x80000000;
    i2dHi1 = 0x43300000;
    decimalPointOrRemainder = exponentMagnitude;
    logValue = _log((double)(float)((double)CONCAT44(0x43300000,i2dLo1) - DOUBLE_001aa1e0));
    powValue = _log(DOUBLE_001aa238);
    twoPow31 = DOUBLE_001aa1e8;
    i2dMagic = DOUBLE_001aa1e0;
    logValue = logValue / powValue;
    if (DOUBLE_001aa1e8 <= logValue) {
      fctiwzScratch2 = (longlong)(int)(logValue - DOUBLE_001aa1e8);
      exponentDigitCount = (int)(logValue - DOUBLE_001aa1e8) + 0x80000000;
    }
    else {
      exponentDigitCount = (uint)(int)logValue;
      fctiwzScratch1 = (longlong)(int)exponentDigitCount;
    }
    loopIndex2 = 0;
    exponentCursor = outText + outPosition;
    digitExponent = exponentDigitCount;
    do {
      i2dLo2 = digitExponent ^ 0x80000000;
      i2dHi2 = 0x43300000;
      digitExponentAsDouble = (double)CONCAT44(0x43300000,i2dLo2) - i2dMagic;
      powValue = _pow(DOUBLE_001aa238,digitExponentAsDouble);
      logValue = DOUBLE_001aa238;
      if (twoPow31 <= powValue) {
        scratchIndex = (int)(powValue - twoPow31);
        fctiwzScratch4 = (longlong)scratchIndex;
        powerOfTen = scratchIndex + 0x80000000;
      }
      else {
        powerOfTen = (uint)(int)powValue;
        fctiwzScratch3 = (longlong)(int)powerOfTen;
      }
      digitChar = (char)(exponentMagnitude / powerOfTen);
      *exponentCursor = digitChar + '0';
      logValue = _pow(logValue,digitExponentAsDouble);
      if (DOUBLE_001aa1e8 <= logValue) {
        fctiwzScratch6 = (longlong)(int)(logValue - DOUBLE_001aa1e8);
        scratchIndex = (int)(logValue - DOUBLE_001aa1e8) + -0x80000000;
      }
      else {
        scratchIndex = (int)logValue;
        fctiwzScratch5 = (longlong)scratchIndex;
      }
      loopIndex2 = loopIndex2 + 1;
      exponentCursor = exponentCursor + 1;
      digitExponent = digitExponent - 1;
      exponentMagnitude = decimalPointOrRemainder - digitChar * scratchIndex;
      decimalPointOrRemainder = exponentMagnitude;
    } while (loopIndex2 <= exponentDigitCount);
    outText[loopIndex2 + outPosition] = '\0';
  }
  else {
    exponentDigitCount = signOffset;
    if ((int)decimalPointOrRemainder < 1) {
      outText[isNegative] = '0';
      exponentDigitCount = signOffset + 2;
      outText[signOffset + 1] = '.';
      if ((int)decimalPointOrRemainder < 0) {
        scratchIndex = -decimalPointOrRemainder;
        copyCursor = outText + exponentDigitCount;
        if (0 < (int)(decimalPointOrRemainder + 1)) {
          scratchIndex = 1;
        }
        do {
          *copyCursor = '0';
          exponentDigitCount = exponentDigitCount + 1;
          copyCursor = copyCursor + 1;
          scratchIndex = scratchIndex + -1;
        } while (scratchIndex != 0);
      }
      decimalPointOrRemainder = 0xffffffff;
    }
    if (*digits != '\0') {
      digitIndex = 0;
      copyCursor = digits;
      do {
        if (digitIndex == decimalPointOrRemainder) {
          decimalPointOrRemainder = 0xffffffff;
          outText[exponentDigitCount] = '.';
          exponentDigitCount = exponentDigitCount + 1;
        }
        digitIndex = digitIndex + 1;
        outText[exponentDigitCount] = *copyCursor;
        exponentDigitCount = exponentDigitCount + 1;
        copyCursor = digits + digitIndex;
      } while (digits[digitIndex] != '\0');
    }
    outText[exponentDigitCount] = '\0';
    if (decimalPointOrRemainder == 0xffffffff) {
      digitChar = *outText;
      trimmedEnd = exponentDigitCount;
      if (digitChar != '\0') {
        scratchIndex = 0;
        do {
          if (digitChar != '0') {
            if (digitChar == '.') {
              trimmedEnd = exponentDigitCount;
              if (scratchIndex + 2U < exponentDigitCount) {
                trimmedEnd = scratchIndex + 2U;
              }
            }
            else {
              trimmedEnd = scratchIndex + 1;
            }
          }
          scratchIndex = scratchIndex + 1;
          digitChar = outText[scratchIndex];
        } while (digitChar != '\0');
      }
      outText[trimmedEnd] = '\0';
    }
  }
  return outText;
}

/* vsdisClearSinkRecord @ 0xce020 (24 bytes) */
int vsdisClearSinkRecord(emptyRecord)
  undefined4 *emptyRecord;
{
  emptyRecord[3] = 0;
  *emptyRecord = 0;
  emptyRecord[1] = 0;
  emptyRecord[2] = 0;
  return;
}

/* vsdisClearSinkRecord2 @ 0xce038 (24 bytes) */
int vsdisClearSinkRecord2(emptyRecord)
  undefined4 *emptyRecord;
{
  emptyRecord[3] = 0;
  *emptyRecord = 0;
  emptyRecord[1] = 0;
  emptyRecord[2] = 0;
  return;
}

/* FUN_000ce050 @ 0xce050 (248 bytes) */
int FUN_000ce050(disasmCtx, format, fmtArg1, fmtArg2, fmtArg3, fmtArg4, fmtArg5, fmtArg6)
  int disasmCtx;
  undefined4 format;
  undefined4 fmtArg1;
  undefined4 fmtArg2;
  undefined4 fmtArg3;
  undefined4 fmtArg4;
  undefined4 fmtArg5;
  undefined4 fmtArg6;
{
  unsigned int ghidra_home[8] = { disasmCtx, format, fmtArg1, fmtArg2, fmtArg3, fmtArg4, fmtArg5, fmtArg6 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  char trimChar;
  char *trimCursor;
  undefined1 lineBuffer [152];
  
  if (*(int *)(disasmCtx + 8) != 0) {
    (*(unsigned int *)((unsigned char *)ghidra_home + 8)) = fmtArg1;
    (*(unsigned int *)((unsigned char *)ghidra_home + 12)) = fmtArg2;
    (*(unsigned int *)((unsigned char *)ghidra_home + 16)) = fmtArg3;
    (*(unsigned int *)((unsigned char *)ghidra_home + 20)) = fmtArg4;
    (*(unsigned int *)((unsigned char *)ghidra_home + 24)) = fmtArg5;
    (*(unsigned int *)((unsigned char *)ghidra_home + 28)) = fmtArg6;
    printf_LDBLStub_1a34d4(lineBuffer,format,&(*(unsigned int *)((unsigned char *)ghidra_home + 8)),fmtArg2,fmtArg3,fmtArg4,fmtArg5,fmtArg6);
    trimCursor = (char *)_strchr(lineBuffer,0x3f);
    if (trimCursor != (char *)0x0) {
      for (; (((trimChar = *trimCursor, trimChar == '?' || (trimChar == ' ')) || (trimChar == ',')) ||
             (trimChar == '\t')); trimCursor = trimCursor + -1) {
      }
      trimCursor[1] = '\0';
    }
    printf_LDBLStub_1a32d0(lineBuffer,"%s\n",lineBuffer,fmtArg2,fmtArg3,fmtArg4,fmtArg5,fmtArg6);
    (*(code *)**(undefined4 **)(disasmCtx + 8))
              (*(undefined4 *)(disasmCtx + 0xc),"",lineBuffer,&(*(unsigned int *)((unsigned char *)ghidra_home + 8)));
  }
  return;
}

/* FUN_000ce148 @ 0xce148 (464 bytes) */
int FUN_000ce148(disasmCtx, sourceWordPtr, outText)
  undefined4 disasmCtx;
  uint *sourceWordPtr;
  undefined1 *outText;
{
  uint swizzleShift;
  uint componentIndex;
  bool moreComponents;
  uint negateBits;
  uint registerType;
  uint swizzleBits;
  int length;
  undefined4 argR6;
  undefined4 argR7;
  undefined4 argR8;
  uint sourceWord;
  undefined4 argR10;
  uint anyNegate;
  uint relIndexComponent;
  uint relativeBits;
  uint registerIndex;
  undefined1 indexText [32];
  
  sourceWord = *sourceWordPtr;
  negateBits = sourceWord & 0x1e000000;
  relativeBits = sourceWord & 0x80000010;
  registerType = sourceWord & 0xf;
  swizzleBits = sourceWord & 0x1ffe000;
  *outText = 0;
  relIndexComponent = sourceWord >> 0x1d;
  registerIndex = sourceWord >> 5;
  if (negateBits == 0x1e000000) {
    anyNegate = 0;
    length = _strlen(outText);
    *(undefined2 *)(outText + length) = 0x2d00;
  }
  else {
    anyNegate = -negateBits >> 0x1f;
  }
  if (registerType == 1) {
    length = _strlen(outText);
    *(undefined2 *)(outText + length) = 0x7600;
  }
  else if (registerType == 0) {
    length = _strlen(outText);
    *(undefined2 *)(outText + length) = 0x7200;
  }
  else if (registerType == 2) {
    length = _strlen(outText);
    *(undefined2 *)(outText + length) = 0x6300;
  }
  else if (registerType == 3) {
    length = _strlen(outText);
    *(undefined2 *)(outText + length) = 0x7400;
  }
  else {
    length = _strlen(outText);
    *(undefined2 *)(outText + length) = 0x3f00;
  }
  printf_LDBLStub_1a32d0(indexText,"%d",registerIndex & 0xff,argR6,argR7,argR8,sourceWord,argR10);
  if (relativeBits == 0) {
    _strcat(outText,indexText);
  }
  else {
    if (relativeBits == 0x10) {
      length = _strlen(outText);
      *(undefined4 *)(outText + length) = 0x5b613000;
    }
    else {
      length = _strlen(outText);
      *(undefined4 *)(outText + length) = 0x5b693000;
    }
    switch(relIndexComponent & 3) {
    case 0:
      _strcat(outText,".x");
      break;
    case 1:
      _strcat(outText,".y");
      break;
    case 2:
      _strcat(outText,".z");
      break;
    case 3:
      _strcat(outText,".w");
      break;
    default:
      _strcat(outText,".?");
    }
    length = _strlen(outText);
    *(undefined2 *)(outText + length) = 0x2b00;
    _strcat(outText,indexText);
    length = _strlen(outText);
    *(undefined2 *)(outText + length) = 0x5d00;
  }
  if ((swizzleBits != 0xd10000) || (anyNegate != 0)) {
    componentIndex = 0;
    length = _strlen(outText);
    *(undefined2 *)(outText + length) = 0x2e00;
    swizzleShift = 0xd;
    do {
      if (((negateBits & 0x2000000 << (componentIndex & 0x3f)) != 0) && (anyNegate != 0)) {
        length = _strlen(outText);
        *(undefined2 *)(outText + length) = 0x2d00;
      }
      switch((swizzleBits & 7 << (swizzleShift & 0x3f)) >> (swizzleShift & 0x3f)) {
      case 0:
        length = _strlen(outText);
        *(undefined2 *)(outText + length) = 0x7800;
        break;
      case 1:
        length = _strlen(outText);
        *(undefined2 *)(outText + length) = 0x7900;
        break;
      case 2:
        length = _strlen(outText);
        *(undefined2 *)(outText + length) = 0x7a00;
        break;
      case 3:
        length = _strlen(outText);
        *(undefined2 *)(outText + length) = 0x7700;
        break;
      case 4:
        length = _strlen(outText);
        *(undefined2 *)(outText + length) = 0x3000;
        break;
      case 5:
        length = _strlen(outText);
        *(undefined2 *)(outText + length) = 0x3100;
        break;
      default:
        length = _strlen(outText);
        *(undefined2 *)(outText + length) = 0x3f00;
      }
      moreComponents = componentIndex != 3;
      swizzleShift = swizzleShift + 3;
      componentIndex = componentIndex + 1;
    } while (moreComponents);
  }
  return sourceWordPtr + 1;
}

/* vsdisPrintInputDx @ 0xce4e4 (48 bytes) */
int vsdisPrintInputDx(disasmCtx, inputMapEntry, argR5, argR6, argR7, argR8, argR9)
  undefined4 disasmCtx;
  uint *inputMapEntry;
  undefined4 argR5;
  undefined4 argR6;
  undefined4 argR7;
  undefined4 argR8;
  undefined4 argR9;
{
  if ((*inputMapEntry & 1) == 0) {
    return;
  }
  return ((int (*)())FUN_000ce050)(disasmCtx,";    v%d = dx v%d",(uint)*(byte *)(inputMapEntry + 1),
               (uint)*(byte *)((int)inputMapEntry + 1),argR7,argR8,argR9,0xce4ec);
}

/* vsdisPrintOutputMapping @ 0xce514 (864 bytes) */
int vsdisPrintOutputMapping(disasmCtx, outputMapEntry, argR5, argR6, argR7, argR8, argR9, argR10Value)
  undefined4 disasmCtx;
  char *outputMapEntry;
  undefined4 argR5;
  undefined4 argR6;
  undefined4 argR7;
  undefined4 argR8;
  undefined4 argR9;
  uint argR10Value;
{
  char *entryByteCursor;
  int loopIndex;
  bool sourcesDiffer;
  byte componentSource;
  char *nameCopyCursor;
  undefined4 oneArg;
  int iVar5;
  char *entryCursor;
  char *semanticName;
  char *componentCursorA;
  uint componentBit;
  undefined1 *componentTextCursor;
  uint componentMask;
  int componentsRemaining;
  char componentLetters [12];
  uint componentSources [5];
  char semanticNameText [4];
  char semanticNameText4;
  char acStack_1f3 [3];
  char semanticNameText8;
  char acStack_1ef [3];
  char semanticNameText12;
  undefined1 destinationText [128];
  undefined1 componentText0 [64];
  undefined1 componentText1 [64];
  undefined1 componentText2 [64];
  char componentText3 [76];
  
  if ((*(uint *)outputMapEntry & 1) != 0) {
    nameCopyCursor = acStack_1ef;
    switch(*outputMapEntry) {
    case '\0':
      *(unsigned int *)semanticNameText = (unsigned int)(*(unsigned int *)((unsigned char *)&(s_IL_pos_001a62cc) + 0));
      (*(unsigned short *)((unsigned char *)&(acStack_1f3) + 0)) = (*(unsigned short *)((unsigned char *)&(s_IL_pos_001a62cc) + 5));
      semanticNameText4 = s_IL_pos_001a62cc[4];
      semanticName = "IL_pos";
      break;
    case '\x01':
      argR10Value = (uint)(byte)s_IL_pointsize_001a62d4[0xc];
      *(unsigned int *)semanticNameText = (unsigned int)(*(unsigned int *)((unsigned char *)&(s_IL_pointsize_001a62d4) + 0));
      semanticNameText4 = (*(unsigned int *)((unsigned char *)&(s_IL_pointsize_001a62d4) + 4));
      semanticNameText8 = (*(unsigned int *)((unsigned char *)&(s_IL_pointsize_001a62d4) + 8));
      semanticNameText12 = s_IL_pointsize_001a62d4[0xc];
      semanticName = (char *)(*(unsigned int *)((unsigned char *)&(s_IL_pointsize_001a62d4) + 0));
      break;
    case '\x02':
      *(unsigned int *)semanticNameText = (unsigned int)(*(unsigned int *)((unsigned char *)&(s_IL_color_001a62e4) + 0));
      semanticNameText4 = (*(unsigned int *)((unsigned char *)&(s_IL_color_001a62e4) + 4));
      semanticNameText8 = s_IL_color_001a62e4[8];
      semanticNameText8 = CONCAT13(semanticNameText8,nameCopyCursor);
      semanticName = "IL_color";
      break;
    case '\x03':
      argR10Value = (uint)(byte)s_IL_backcolor_001a62f0[0xc];
      *(unsigned int *)semanticNameText = (unsigned int)(*(unsigned int *)((unsigned char *)&(s_IL_backcolor_001a62f0) + 0));
      semanticNameText4 = (*(unsigned int *)((unsigned char *)&(s_IL_backcolor_001a62f0) + 4));
      semanticNameText8 = (*(unsigned int *)((unsigned char *)&(s_IL_backcolor_001a62f0) + 8));
      semanticNameText12 = s_IL_backcolor_001a62f0[0xc];
      semanticName = (char *)(*(unsigned int *)((unsigned char *)&(s_IL_backcolor_001a62f0) + 0));
      break;
    case '\x04':
      *(unsigned int *)semanticNameText = (unsigned int)(*(unsigned int *)((unsigned char *)&(s_IL_fog_001a6300) + 0));
      (*(unsigned short *)((unsigned char *)&(acStack_1f3) + 0)) = (*(unsigned short *)((unsigned char *)&(s_IL_fog_001a6300) + 5));
      semanticNameText4 = s_IL_fog_001a6300[4];
      semanticName = "IL_fog";
      break;
    case '\x05':
      argR10Value = (uint)(ushort)(*(unsigned short *)((unsigned char *)&(s_IL_generic_001a6308) + 9));
      *(unsigned int *)semanticNameText = (unsigned int)(*(unsigned int *)((unsigned char *)&(s_IL_generic_001a6308) + 0));
      semanticNameText4 = (*(unsigned int *)((unsigned char *)&(s_IL_generic_001a6308) + 4));
      (*(unsigned short *)((unsigned char *)&(acStack_1ef) + 0)) = (*(unsigned short *)((unsigned char *)&(s_IL_generic_001a6308) + 9));
      semanticNameText8 = s_IL_generic_001a6308[8];
      semanticName = (char *)(*(unsigned int *)((unsigned char *)&(s_IL_generic_001a6308) + 0));
      break;
    default:
      argR10Value = (uint)(ushort)(*(unsigned short *)((unsigned char *)&(s_IL_unknown_001a6314) + 9));
      *(unsigned int *)semanticNameText = (unsigned int)(*(unsigned int *)((unsigned char *)&(s_IL_unknown_001a6314) + 0));
      semanticNameText4 = (*(unsigned int *)((unsigned char *)&(s_IL_unknown_001a6314) + 4));
      (*(unsigned short *)((unsigned char *)&(acStack_1ef) + 0)) = (*(unsigned short *)((unsigned char *)&(s_IL_unknown_001a6314) + 9));
      semanticNameText8 = s_IL_unknown_001a6314[8];
      semanticName = (char *)(*(unsigned int *)((unsigned char *)&(s_IL_unknown_001a6314) + 0));
    }
    printf_LDBLStub_1a32d0(componentLetters + 4,"%d",(uint)(byte)outputMapEntry[1],argR6,argR7,argR8,semanticName,argR10Value);
    builtin_strncpy(componentLetters,"xyzw",4);
    componentMask = *(uint *)outputMapEntry >> 4;
    loopIndex = 0;
    sourcesDiffer = false;
    componentBit = 0;
    oneArg = 1;
    componentCursorA = componentLetters;
    componentsRemaining = 4;
    entryByteCursor = outputMapEntry;
    do {
      if ((componentMask & 0xf & 1 << (componentBit & 0x3f)) != 0) {
        componentSource = entryByteCursor[4];
        *(uint *)(componentCursorA + 0x10) = (uint)componentSource;
        if ((loopIndex != 0) && ((uint)componentSource != *(uint *)(componentCursorA + 0xc))) {
          sourcesDiffer = true;
        }
        loopIndex = loopIndex + 1;
        componentCursorA = componentCursorA + 4;
      }
      componentBit = componentBit + 1;
      entryByteCursor = entryByteCursor + 1;
      componentsRemaining = componentsRemaining + -1;
    } while (componentsRemaining != 0);
    if (sourcesDiffer) {
      componentMask = 0;
      componentTextCursor = componentText0;
      entryCursor = outputMapEntry;
      do {
        if ((*(uint *)outputMapEntry >> 4 & 0xf & 1 << (componentMask & 0x3f)) == 0) {
          componentText0[componentMask * 0x40] = 0;
        }
        else {
          printf_LDBLStub_1a32d0(componentTextCursor,"o%d.%c ",(uint)(byte)entryCursor[4],(int)componentLetters[(byte)entryCursor[8]],oneArg
                       ,loopIndex,entryByteCursor,componentCursorA);
        }
        sourcesDiffer = componentMask != 3;
        componentTextCursor = componentTextCursor + 0x40;
        entryCursor = entryCursor + 1;
        componentMask = componentMask + 1;
      } while (sourcesDiffer);
      entryCursor = componentText3;
      printf_LDBLStub_1a32d0(destinationText,"%s%s%s%s",componentText0,componentText1,componentText2,entryCursor,entryByteCursor,componentCursorA);
    }
    else {
      iVar5 = 0x5f;
      if ((componentMask & 1) != 0) {
        iVar5 = (int)componentLetters[(byte)outputMapEntry[8]];
      }
      componentsRemaining = 0x5f;
      if ((componentMask & 2) != 0) {
        componentsRemaining = (int)componentLetters[(byte)outputMapEntry[9]];
      }
      entryCursor = (*(GhidraMachOSection *)0x00000054).sectname + 0xb;
      if ((componentMask & 4) != 0) {
        entryCursor = (char *)(int)componentLetters[(byte)outputMapEntry[10]];
      }
      entryByteCursor = (*(GhidraMachOSection *)0x00000054).sectname + 0xb;
      if ((componentMask & 8) != 0) {
        entryByteCursor = (char *)(int)componentLetters[(byte)outputMapEntry[0xb]];
      }
      printf_LDBLStub_1a32d0(destinationText,"o%d.%c%c%c%c",(uint)(byte)outputMapEntry[4],iVar5,componentsRemaining,entryCursor,entryByteCursor,
                   componentCursorA);
    }
    ((int (*)())FUN_000ce050)(disasmCtx,";    %s = %s%s",destinationText,semanticNameText,componentLetters + 4,entryCursor,entryByteCursor,componentCursorA);
  }
  return;
}

/* vsdisPrintShaderData @ 0xce88c (480 bytes) */
int vsdisPrintShaderData(disasmCtx, shaderState, mapIndexArg, argR6, argR7, argR8, argR9, argR10)
  undefined4 disasmCtx;
  int shaderState;
  int mapIndexArg;
  undefined4 argR6;
  undefined4 argR7;
  undefined4 argR8;
  undefined4 argR9;
  undefined4 argR10;
{
  bool moreEntries;
  undefined4 lastSrcInst;
  int mapEntryPtr;
  int mapIndex;
  
  ((int (*)())FUN_000ce050)(disasmCtx,"",mapIndexArg,argR6,argR7,argR8,argR9,argR10);
  ((int (*)())FUN_000ce050)(disasmCtx,";*****************************************",mapIndexArg,argR6,argR7,argR8,
               argR9,argR10);
  ((int (*)())FUN_000ce050)(disasmCtx,";                 VS Data",mapIndexArg,argR6,argR7,argR8,argR9,argR10);
  ((int (*)())FUN_000ce050)(disasmCtx,";*****************************************",mapIndexArg,argR6,argR7,argR8,
               argR9,argR10);
  ((int (*)())FUN_000ce050)(disasmCtx,"; Input Semantic Mappings",mapIndexArg,argR6,argR7,argR8,argR9,argR10);
  if (*(int *)(shaderState + 0x104) == 0) {
    ((int (*)())FUN_000ce050)(disasmCtx,";    No input mappings",mapIndexArg,argR6,argR7,argR8,argR9,argR10);
  }
  else {
    mapIndex = 0;
    mapEntryPtr = shaderState + 0x108;
    do {
      mapIndexArg = mapIndex;
      ((int (*)())vsdisPrintInputDx)(disasmCtx,mapEntryPtr,mapIndex,argR6,argR7,argR8,argR9);
      moreEntries = mapIndex != 0x3f;
      mapIndex = mapIndex + 1;
      mapEntryPtr = mapEntryPtr + 0xc;
    } while (moreEntries);
  }
  ((int (*)())FUN_000ce050)(disasmCtx,"",mapIndexArg,argR6,argR7,argR8,argR9,argR10);
  ((int (*)())FUN_000ce050)(disasmCtx,"; Output Semantic Mappings",mapIndexArg,argR6,argR7,argR8,argR9,argR10)
  ;
  if (*(int *)(shaderState + 0x408) == 0) {
    ((int (*)())FUN_000ce050)(disasmCtx,";    No output mappings",mapIndexArg,argR6,argR7,argR8,argR9,argR10);
  }
  else {
    mapIndex = 0;
    mapEntryPtr = shaderState + 0x40c;
    do {
      mapIndexArg = mapIndex;
      ((int (*)())vsdisPrintOutputMapping)(disasmCtx,mapEntryPtr,mapIndex,argR6,argR7,argR8,argR9,argR10);
      moreEntries = mapIndex != 0x2f;
      mapIndex = mapIndex + 1;
      mapEntryPtr = mapEntryPtr + 0xc;
    } while (moreEntries);
  }
  ((int (*)())FUN_000ce050)(disasmCtx,"",mapIndexArg,argR6,argR7,argR8,argR9,argR10);
  ((int (*)())FUN_000ce050)(disasmCtx,"; Num Insts = %d",*(undefined4 *)(shaderState + 0x65c),argR6,argR7,argR8,
               argR9,argR10);
  ((int (*)())FUN_000ce050)(disasmCtx,"; Max Temp = %d",*(int *)(shaderState + 0x660) + -1,argR6,argR7,argR8,
               argR9,argR10);
  ((int (*)())FUN_000ce050)(disasmCtx,"; Max AltTemp = %d",*(int *)(shaderState + 0x664) + -1,argR6,argR7,argR8,
               argR9,argR10);
  ((int (*)())FUN_000ce050)(disasmCtx,"; Max Constants = %d",*(int *)(shaderState + 0x670) + -1,argR6,argR7,argR8
               ,argR9,argR10);
  ((int (*)())FUN_000ce050)(disasmCtx,"; Last Pos Inst = %d",*(undefined4 *)(shaderState + 0x668),argR6,argR7,
               argR8,argR9,argR10);
  lastSrcInst = *(undefined4 *)(shaderState + 0x66c);
  ((int (*)())FUN_000ce050)(disasmCtx,"; Last Src Inst = %d",lastSrcInst,argR6,argR7,argR8,argR9,argR10);
  if (*(int *)(shaderState + 0x658) != 0) {
    ((int (*)())FUN_000ce050)(disasmCtx,"; Shader uses relative addressing",lastSrcInst,argR6,argR7,argR8,argR9,
                 argR10);
  }
  return 1;
}

/* FUN_000cea6c @ 0xcea6c (408 bytes) */
int FUN_000cea6c(disasmCtx, destWordPtr, outText, argR6, argR7, argR8, argR9, argR10)
  undefined4 disasmCtx;
  uint *destWordPtr;
  char *outText;
  undefined4 argR6;
  undefined4 argR7;
  undefined4 argR8;
  undefined4 argR9;
  undefined4 argR10;
{
  undefined2 oxTail;
  uint saturateBit;
  int length;
  char *registerTypeCode;
  char *passThroughArg;
  uint destWord;
  undefined1 indexText [28];
  
  oxTail = (*(unsigned short *)((unsigned char *)&(s_ox_001a64a8) + 1));
  destWord = *destWordPtr;
  registerTypeCode = (char *)(destWord >> 8 & 0xf);
  if ((uint)registerTypeCode < 6) {
    passThroughArg = (char *)(0);
    switch((int)registerTypeCode) {
    case 0x0:
      outText[0] = 'r';
      outText[1] = '\0';
      break;
    case 0x1:
      outText[0] = 'a';
      outText[1] = '\0';
      break;
    case 0x2:
      outText[0] = 'o';
      outText[1] = '\0';
      break;
    case 0x3:
      passThroughArg = "ox";
      *outText = s_ox_001a64a8[0];
      *(undefined2 *)(outText + 1) = oxTail;
      break;
    case 4:
      outText[0] = 't';
      outText[1] = '\0';
      break;
    case 5:
      outText[0] = 'v';
      outText[1] = '\0';
    }
  }
  else {
    outText[0] = '?';
    outText[1] = '\0';
    passThroughArg = registerTypeCode;
  }
  printf_LDBLStub_1a32d0(indexText,"%d",destWord >> 0xd & 0x7f,argR6,argR7,argR8,passThroughArg,argR10);
  if ((destWord & 0x80001000) == 0) {
    _strcat(outText,indexText);
  }
  else {
    if ((destWord & 0x80001000) == 0x80000000) {
      length = _strlen(outText);
      builtin_strncpy(outText + length,"[a0",4);
    }
    else {
      length = _strlen(outText);
      builtin_strncpy(outText + length,"[i0",4);
    }
    switch(destWord >> 0x1d & 3) {
    case 0:
      _strcat(outText,".x");
      break;
    case 1:
      _strcat(outText,".y");
      break;
    case 2:
      _strcat(outText,".z");
      break;
    case 3:
      _strcat(outText,".w");
      break;
    default:
      _strcat(outText,".?");
    }
    length = _strlen(outText);
    (outText + length)[0] = '+';
    (outText + length)[1] = '\0';
    _strcat(outText,indexText);
    length = _strlen(outText);
    (outText + length)[0] = ']';
    (outText + length)[1] = '\0';
  }
  if ((destWord & 0x40) == 0) {
    saturateBit = destWord & 0x1000000;
  }
  else {
    saturateBit = destWord & 0x2000000;
  }
  if (saturateBit != 0) {
    _strcat(outText,"_sat");
  }
  if ((destWord & 0xf00000) != 0xf00000) {
    length = _strlen(outText);
    (outText + length)[0] = '.';
    (outText + length)[1] = '\0';
    if ((destWord & 0x100000) != 0) {
      length = _strlen(outText);
      (outText + length)[0] = 'x';
      (outText + length)[1] = '\0';
    }
    if ((destWord & 0x200000) != 0) {
      length = _strlen(outText);
      (outText + length)[0] = 'y';
      (outText + length)[1] = '\0';
    }
    if ((destWord & 0x400000) != 0) {
      length = _strlen(outText);
      (outText + length)[0] = 'z';
      (outText + length)[1] = '\0';
    }
    if ((destWord & 0x800000) != 0) {
      length = _strlen(outText);
      (outText + length)[0] = 'w';
      (outText + length)[1] = '\0';
    }
  }
  return destWordPtr + 1;
}

/* FUN_000ced58 @ 0xced58 (1288 bytes) */
int FUN_000ced58(disasmCtx, instructionWordPtr, mnemonicText, operandText0, operandText1)
  undefined4 disasmCtx;
  uint *instructionWordPtr;
  char *mnemonicText;
  undefined2 *operandText0;
  undefined2 *operandText1;
{
  uint componentIndex;
  int length;
  int prefixLow;
  bool moreComponents;
  undefined4 prefixHigh;
  uint opcodeIndex;
  int length2;
  undefined2 *operandText0Copy;
  undefined2 *operandText1Copy;
  undefined4 argR8;
  undefined4 argR10;
  uint opcodeOffset;
  uint previousWord;
  uint negateBits;
  uint registerType;
  uint instructionWord;
  undefined1 indexText [5];
  undefined1 indexTextTail [23];
  
  prefixHigh = (*(unsigned int *)((unsigned char *)&(s_Du_001a64b4) + 4));
  prefixLow = (*(unsigned int *)((unsigned char *)&(s_Du_001a64b4) + 0));
  instructionWord = *instructionWordPtr;
  previousWord = instructionWordPtr[-3];
  negateBits = instructionWord & 0x18000000;
  opcodeIndex = instructionWord >> 0x15 & 0xf | (instructionWord & 4) << 2 | 0x40;
  registerType = instructionWord & 0xf;
  opcodeOffset = opcodeIndex - 0x40;
  *(undefined4 *)mnemonicText = (*(unsigned int *)((unsigned char *)&(s_Du_001a64b4) + 0));
  *(undefined4 *)(mnemonicText + 4) = prefixHigh;
  operandText0Copy = operandText0;
  operandText1Copy = operandText1;
  if (opcodeOffset < 0x1d) {
    prefixLow = 0;
    switch(opcodeIndex) {
    case 0x40:
      _strcat(mnemonicText,"NOPme     ");
      break;
    case 0x41:
      _strcat(mnemonicText,"EXPP      ");
      break;
    case 0x42:
      _strcat(mnemonicText,"LOGP      ");
      break;
    case 0x43:
      _strcat(mnemonicText,"EXPPE     ");
      break;
    case 0x44:
      _strcat(mnemonicText,"LIT       ");
      break;
    case 0x45:
      _strcat(mnemonicText,"POW       ");
      break;
    case 0x46:
      _strcat(mnemonicText,"RCP       ");
      break;
    case 0x47:
      _strcat(mnemonicText,"RCPFF     ");
      break;
    case 0x48:
      _strcat(mnemonicText,"RSQ       ");
      break;
    case 0x49:
      _strcat(mnemonicText,"RSQFF     ");
      break;
    case 0x4a:
      _strcat(mnemonicText,"MULme     ");
      break;
    case 0x4b:
      _strcat(mnemonicText,"EXP       ");
      break;
    case 0x4c:
      _strcat(mnemonicText,"LOG       ");
      break;
    case 0x4d:
      _strcat(mnemonicText,"POWB      ");
      break;
    case 0x4e:
      _strcat(mnemonicText,"POWB1     ");
      break;
    case 0x4f:
      _strcat(mnemonicText,"POW01     ");
      break;
    case 0x50:
      _strcat(mnemonicText,"SIN       ");
      break;
    case 0x51:
      _strcat(mnemonicText,"COS       ");
      break;
    case 0x52:
      _strcat(mnemonicText,"LOGIE3    ");
      break;
    case 0x53:
      _strcat(mnemonicText,"RCPIE3    ");
      break;
    case 0x54:
      _strcat(mnemonicText,"RSQIE3    ");
      break;
    case 0x55:
      _strcat(mnemonicText,"Prd_EQ    ");
      break;
    case 0x56:
      _strcat(mnemonicText,"Prd_GT    ");
      break;
    case 0x57:
      _strcat(mnemonicText,"Prd_GTE   ");
      break;
    case 0x58:
      _strcat(mnemonicText,"Prd_NEQ   ");
      break;
    case 0x59:
      _strcat(mnemonicText,"Prd_CLR   ");
      break;
    case 0x5a:
      _strcat(mnemonicText,"Prd_INV   ");
      break;
    case 0x5b:
      _strcat(mnemonicText,"Prd_POP   ");
      break;
    case 0x5c:
      _strcat(mnemonicText,"Prd_RSTOR ");
    }
  }
  else {
    _strcat(mnemonicText,"ERROR     ");
  }
  *operandText0 = 0x7400;
  printf_LDBLStub_1a32d0(indexText,"%d",instructionWord >> 0x13 & 3,operandText0Copy,operandText1Copy,argR8,prefixLow,argR10);
  if ((previousWord & 0x2000000) != 0) {
    _strcat(operandText0,"_sat");
  }
  _strcat(operandText0,indexText);
  length2 = _strlen(operandText0);
  *(undefined2 *)(length2 + (int)operandText0) = 0x2e00;
  if (negateBits == 0) {
    length2 = _strlen(operandText0);
    *(undefined2 *)(length2 + (int)operandText0) = 0x7800;
  }
  else if (negateBits == 0x8000000) {
    length2 = _strlen(operandText0);
    *(undefined2 *)(length2 + (int)operandText0) = 0x7900;
  }
  else if (negateBits == 0x10000000) {
    length2 = _strlen(operandText0);
    *(undefined2 *)(length2 + (int)operandText0) = 0x7a00;
  }
  else if (negateBits == 0x18000000) {
    length2 = _strlen(operandText0);
    *(undefined2 *)(length2 + (int)operandText0) = 0x7700;
  }
  length2 = _strlen(operandText0);
  *(undefined2 *)(length2 + (int)operandText0) = 0x2c00;
  if (registerType == 1) {
    *operandText1 = 0x7600;
  }
  else if (registerType == 0) {
    *operandText1 = 0x7200;
  }
  else if (registerType == 2) {
    *operandText1 = 0x6300;
  }
  else if (registerType == 3) {
    *operandText1 = 0x7400;
  }
  else {
    *operandText1 = 0x3f00;
  }
  printf_LDBLStub_1a32d0(indexTextTail,"%d",instructionWord >> 5 & 0xff,operandText0Copy,operandText1Copy,argR8,prefixLow,argR10);
  _strcat(operandText1,indexTextTail);
  negateBits = instructionWord & 0x6000000;
  if (((instructionWord & 0x7e000) != 0x10000) || (negateBits != 0)) {
    componentIndex = 0;
    length = _strlen(operandText1);
    *(undefined2 *)(length + (int)operandText1) = 0x2e00;
    opcodeIndex = 0xd;
    do {
      if (((negateBits & 0x2000000 << (componentIndex & 0x3f)) != 0) && (negateBits != 0)) {
        length = _strlen(operandText1);
        *(undefined2 *)(length + (int)operandText1) = 0x2d00;
      }
      switch((instructionWord & 0x7e000 & 7 << (opcodeIndex & 0x3f)) >> (opcodeIndex & 0x3f)) {
      case 0:
        length = _strlen(operandText1);
        *(undefined2 *)(length + (int)operandText1) = 0x7800;
        break;
      case 1:
        length = _strlen(operandText1);
        *(undefined2 *)(length + (int)operandText1) = 0x7900;
        break;
      case 2:
        length = _strlen(operandText1);
        *(undefined2 *)(length + (int)operandText1) = 0x7a00;
        break;
      case 3:
        length = _strlen(operandText1);
        *(undefined2 *)(length + (int)operandText1) = 0x7700;
        break;
      case 4:
        length = _strlen(operandText1);
        *(undefined2 *)(length + (int)operandText1) = 0x3000;
        break;
      case 5:
        length = _strlen(operandText1);
        *(undefined2 *)(length + (int)operandText1) = 0x3100;
        break;
      default:
        length = _strlen(operandText1);
        *(undefined2 *)(length + (int)operandText1) = 0x3f00;
      }
      moreComponents = componentIndex != 1;
      opcodeIndex = opcodeIndex + 3;
      componentIndex = componentIndex + 1;
    } while (moreComponents);
  }
  return instructionWordPtr + 1;
}

/* FUN_000cf2ec @ 0xcf2ec (1952 bytes) */
int FUN_000cf2ec(disasmCtx, instructionWordPtr, mnemonicText, flagOut, sourceCountOut)
  undefined4 disasmCtx;
  uint *instructionWordPtr;
  undefined4 *mnemonicText;
  undefined4 *flagOut;
  undefined4 *sourceCountOut;
{
  uint instructionWord;
  undefined4 returnCode;
  
  instructionWord = *instructionWordPtr;
  *flagOut = 0;
  if ((instructionWord & 0x10000000) != 0) {
    *flagOut = 1;
  }
  if ((instructionWord & 0x4000000) == 0) {
    *mnemonicText = 0x20202000;
  }
  else if ((instructionWord & 0x8000000) == 0) {
    *mnemonicText = 0x21702000;
  }
  else {
    *mnemonicText = 0x20702000;
  }
  switch(instructionWord & 0xff) {
  case 0:
    _strcat(mnemonicText,"NOPve     ");
    returnCode = 0;
    *sourceCountOut = 0;
    break;
  case 1:
    _strcat(mnemonicText,"DP4       ");
    returnCode = 0;
    *sourceCountOut = 2;
    break;
  case 2:
    _strcat(mnemonicText,"MULve     ");
    returnCode = 0;
    *sourceCountOut = 2;
    break;
  case 3:
    _strcat(mnemonicText,"ADD       ");
    returnCode = 0;
    *sourceCountOut = 2;
    break;
  case 4:
    _strcat(mnemonicText,"MAD       ");
    returnCode = 0;
    *sourceCountOut = 3;
    break;
  case 5:
    _strcat(mnemonicText,"DST       ");
    returnCode = 0;
    *sourceCountOut = 2;
    break;
  case 6:
    _strcat(mnemonicText,"FRC       ");
    returnCode = 0;
    *sourceCountOut = 1;
    break;
  case 7:
    _strcat(mnemonicText,"MAX       ");
    returnCode = 0;
    *sourceCountOut = 2;
    break;
  case 8:
    _strcat(mnemonicText,"MIN       ");
    returnCode = 0;
    *sourceCountOut = 2;
    break;
  case 9:
    _strcat(mnemonicText,"SGE       ");
    returnCode = 0;
    *sourceCountOut = 2;
    break;
  case 10:
    _strcat(mnemonicText,"SLT       ");
    returnCode = 0;
    *sourceCountOut = 2;
    break;
  case 0xb:
    _strcat(mnemonicText,"M2xADD    ");
    returnCode = 0;
    *sourceCountOut = 2;
    break;
  case 0xc:
    _strcat(mnemonicText,"MULCLAMP  ");
    returnCode = 0;
    *sourceCountOut = 2;
    break;
  case 0xd:
    _strcat(mnemonicText,"F2F_FLR   ");
    returnCode = 0;
    *sourceCountOut = 1;
    break;
  case 0xe:
    _strcat(mnemonicText,"F2F_RND   ");
    returnCode = 0;
    *sourceCountOut = 1;
    break;
  case 0xf:
    _strcat(mnemonicText,"PrdEQ_PSH ");
    returnCode = 0;
    *sourceCountOut = 2;
    break;
  case 0x10:
    _strcat(mnemonicText,"PrdGT_PSH");
    returnCode = 0;
    *sourceCountOut = 2;
    break;
  case 0x11:
    _strcat(mnemonicText,"PrdGTE_PSH");
    returnCode = 0;
    *sourceCountOut = 2;
    break;
  case 0x12:
    _strcat(mnemonicText,"PrdNEQ_PSH");
    returnCode = 0;
    *sourceCountOut = 2;
    break;
  case 0x13:
    _strcat(mnemonicText,"CND_WR_EQ ");
    returnCode = 0;
    *sourceCountOut = 3;
    break;
  case 0x14:
    _strcat(mnemonicText,"CND_WR_GT");
    returnCode = 0;
    *sourceCountOut = 2;
    break;
  case 0x15:
    _strcat(mnemonicText,"CND_WR_GTE");
    returnCode = 0;
    *sourceCountOut = 2;
    break;
  case 0x16:
    _strcat(mnemonicText,"CND_WR_NEQ");
    returnCode = 0;
    *sourceCountOut = 3;
    break;
  case 0x17:
    _strcat(mnemonicText,"CND_MUX_EQ");
    returnCode = 0;
    *sourceCountOut = 3;
    break;
  case 0x18:
    _strcat(mnemonicText,"CND_MUX_GT");
    returnCode = 0;
    *sourceCountOut = 3;
    break;
  case 0x19:
    _strcat(mnemonicText,"CND_MUX_GTE");
    returnCode = 0;
    *sourceCountOut = 3;
    break;
  case 0x1a:
    _strcat(mnemonicText,"SGT       ");
    returnCode = 0;
    *sourceCountOut = 2;
    break;
  case 0x1b:
    _strcat(mnemonicText,"SEQ       ");
    returnCode = 0;
    *sourceCountOut = 2;
    break;
  case 0x1c:
    _strcat(mnemonicText,"SNE       ");
    returnCode = 0;
    *sourceCountOut = 2;
    break;
  default:
    _strcat(mnemonicText,"ERROR     ");
    returnCode = 1;
    break;
  case 0x40:
    _strcat(mnemonicText,"NOPme     ");
    returnCode = 0;
    *sourceCountOut = 0;
    break;
  case 0x41:
    _strcat(mnemonicText,"EXPP      ");
    returnCode = 0;
    *sourceCountOut = 1;
    break;
  case 0x42:
    _strcat(mnemonicText,"LOGP      ");
    returnCode = 0;
    *sourceCountOut = 1;
    break;
  case 0x43:
    _strcat(mnemonicText,"EXPPE     ");
    returnCode = 0;
    *sourceCountOut = 1;
    break;
  case 0x44:
    _strcat(mnemonicText,"LIT       ");
    returnCode = 0;
    *sourceCountOut = 3;
    break;
  case 0x45:
    _strcat(mnemonicText,"POW       ");
    returnCode = 0;
    *sourceCountOut = 2;
    break;
  case 0x46:
    _strcat(mnemonicText,"RCP       ");
    returnCode = 0;
    *sourceCountOut = 1;
    break;
  case 0x47:
    _strcat(mnemonicText,"RCPFF     ");
    returnCode = 0;
    *sourceCountOut = 1;
    break;
  case 0x48:
    _strcat(mnemonicText,"RSQ       ");
    returnCode = 0;
    *sourceCountOut = 1;
    break;
  case 0x49:
    _strcat(mnemonicText,"RSQFF     ");
    returnCode = 0;
    *sourceCountOut = 1;
    break;
  case 0x4a:
    _strcat(mnemonicText,"MULme     ");
    returnCode = 0;
    *sourceCountOut = 2;
    break;
  case 0x4b:
    _strcat(mnemonicText,"EXP       ");
    returnCode = 0;
    *sourceCountOut = 1;
    break;
  case 0x4c:
    _strcat(mnemonicText,"LOG       ");
    returnCode = 0;
    *sourceCountOut = 1;
    break;
  case 0x4d:
    _strcat(mnemonicText,"POWB      ");
    returnCode = 0;
    *sourceCountOut = 1;
    break;
  case 0x4e:
    _strcat(mnemonicText,"POWB1     ");
    returnCode = 0;
    *sourceCountOut = 1;
    break;
  case 0x4f:
    _strcat(mnemonicText,"POW01     ");
    returnCode = 0;
    *sourceCountOut = 1;
    break;
  case 0x50:
    _strcat(mnemonicText,"SIN       ");
    returnCode = 0;
    *sourceCountOut = 1;
    break;
  case 0x51:
    _strcat(mnemonicText,"COS       ");
    returnCode = 0;
    *sourceCountOut = 1;
    break;
  case 0x55:
    _strcat(mnemonicText,"Prd_EQ    ");
    returnCode = 0;
    *sourceCountOut = 1;
    break;
  case 0x58:
    _strcat(mnemonicText,"Prd_NEQ   ");
    returnCode = 0;
    *sourceCountOut = 1;
    break;
  case 0x59:
    _strcat(mnemonicText,"Prd_CLR   ");
    returnCode = 0;
    *sourceCountOut = 0;
    break;
  case 0x5a:
    _strcat(mnemonicText,"Prd_INV   ");
    returnCode = 0;
    *sourceCountOut = 1;
    break;
  case 0x5b:
    _strcat(mnemonicText,"Prd_POP   ");
    returnCode = 0;
    *sourceCountOut = 1;
    break;
  case 0x5c:
    _strcat(mnemonicText,"Prd_RSTOR ");
    returnCode = 0;
    *sourceCountOut = 1;
    break;
  case 0x80:
    _strcat(mnemonicText,"MADmac    ");
    returnCode = 0;
    *sourceCountOut = 3;
    break;
  case 0x81:
    _strcat(mnemonicText,"M2xADDmac ");
    returnCode = 0;
    *sourceCountOut = 2;
  }
  return returnCode;
}

/* vsdisFlowOpcodeName @ 0xcfc94 (144 bytes) */
int vsdisFlowOpcodeName(disasmCtx, flowOpcode)
  undefined4 disasmCtx;
  uint flowOpcode;
{
  if (flowOpcode == 0x3e) {
    return "loop   ";
  }
  if (flowOpcode < 0x3f) {
    if (flowOpcode == 0x35) {
      return "ifnz  ";
    }
    if (flowOpcode < 0x36) {
      if (flowOpcode == 8) {
        return "call   ";
      }
      if (flowOpcode == 9) {
        return "callnz ";
      }
    }
  }
  else if (flowOpcode == 0x53) {
    return "ret    ";
  }
  return "unknown";
}

/* vsdisPrintFlowInstruction @ 0xcfd24 (524 bytes) */
int vsdisPrintFlowInstruction(disasmCtx, labelEntry, argR5, argR6, argR7, argR8, argR9, argR10)
  undefined4 disasmCtx;
  int *labelEntry;
  undefined4 argR5;
  undefined4 argR6;
  undefined4 argR7;
  int argR8;
  undefined4 argR9;
  undefined4 argR10;
{
  char *flowFormat;
  undefined4 flowOpName;
  char *compareText;
  char *formatString;
  int formatValueB;
  char *formatValueA;
  int formatValueC;
  int formatValueD;
  uint flowOp;
  
  flowOp = labelEntry[2];
  if (flowOp == 0x35) {
    formatValueD = labelEntry[3];
    if (*labelEntry == 0) {
      compareText = "!=";
    }
    else {
      compareText = "==";
    }
    formatValueB = labelEntry[6];
    formatString = "          CF- IF  B%d %s 0, if = %d, else = %d, endif = %d";
    formatValueA = (char *)(labelEntry[4] + 1);
    formatValueC = labelEntry[5] + 1;
LAB_000cfef0:
    ((int (*)())FUN_000ce050)(disasmCtx,formatString,formatValueD,compareText,formatValueA,formatValueC,formatValueB,argR10);
    return;
  }
  if (flowOp < 0x36) {
    if (flowOp == 0x27) {
      return;
    }
    if (flowOp < 0x28) {
      if (flowOp == 8) {
        formatValueC = labelEntry[6];
        formatValueB = labelEntry[4];
        formatValueD = labelEntry[5];
        flowFormat = "          CF- CALL at %d, subroutine from %d to %d";
        goto LAB_000cfe3c;
      }
      if (flowOp == 9) {
        formatValueD = labelEntry[4];
        compareText = (char *)labelEntry[3];
        if (*labelEntry == 0) {
          formatValueA = "!=";
        }
        else {
          formatValueA = "==";
        }
        formatValueB = labelEntry[6];
        formatValueC = labelEntry[5];
        formatString = "          CF- CALL at %d if B%d %s 0, subroutine from %d to %d";
        goto LAB_000cfef0;
      }
    }
    else if (flowOp == 0x29) {
      return;
    }
  }
  else {
    if (flowOp == 0x3e) {
      if (labelEntry[1] == 0) {
        formatValueC = labelEntry[6];
        formatValueB = labelEntry[3];
        flowFormat = "          CF- Loop I%d first in loop = %d last in loop = %d";
        formatValueD = labelEntry[4] + 1;
      }
      else {
        formatValueC = labelEntry[6];
        formatValueB = labelEntry[3];
        flowFormat = "          CF- Rep  I%d first in loop = %d last in loop = %d";
        formatValueD = labelEntry[4] + 1;
      }
      goto LAB_000cfe3c;
    }
    if (flowOp == 0x53) {
      return;
    }
  }
  formatValueD = *labelEntry;
  flowOpName = ((int (*)())vsdisFlowOpcodeName)(disasmCtx,flowOp);
  argR8 = labelEntry[3];
  ((int (*)())FUN_000ce050)(disasmCtx,"\nNot = %d, op=%s(%d), reg =%d",formatValueD,flowOpName,flowOp,argR8,argR9,argR10);
  formatValueD = labelEntry[4];
  ((int (*)())FUN_000ce050)(disasmCtx," ifinst = %d begInst= %d callinst = %d",formatValueD,formatValueD,formatValueD,argR8,argR9,
               argR10);
  ((int (*)())FUN_000ce050)(disasmCtx," else=%d, labelinst=%d",labelEntry[5],labelEntry[5],formatValueD,argR8,argR9,argR10)
  ;
  formatValueB = labelEntry[6];
  flowFormat = " endif= %d , endinst = %d, retinst = %d";
  formatValueD = formatValueB;
  formatValueC = formatValueB;
LAB_000cfe3c:
  ((int (*)())FUN_000ce050)(disasmCtx,flowFormat,formatValueB,formatValueD,formatValueC,argR8,argR9,argR10);
  return;
}

/* vsDisassembleLine @ 0xcff30 (252 bytes) */
int vsDisassembleLine(disassembler, instructionWords, lineBuffer, argR6, argR7, argR8, argR9, argR10)
  int *disassembler;
  undefined4 instructionWords;
  undefined1 *lineBuffer;
  undefined4 argR6;
  undefined4 argR7;
  undefined4 argR8;
  undefined4 argR9;
  undefined4 argR10;
{
  int length;
  int labelEntry;
  int disasmState;
  undefined4 argR6Saved;
  int *currentInstNumber;
  undefined4 argR7Saved;
  int *labelTableOrLine;
  int labelCount;
  int loopIndex;
  undefined1 lineNumberText [120];
  
  *lineBuffer = 0;
  disasmState = *disassembler;
  labelTableOrLine = *(int **)(disasmState + 0x654);
  argR6Saved = argR6;
  argR7Saved = argR7;
  if ((labelTableOrLine == (int *)0x0) || (labelCount = *labelTableOrLine, labelCount < 1)) {
    currentInstNumber = (int *)disassembler[1];
  }
  else {
    currentInstNumber = (int *)disassembler[1];
    loopIndex = 0;
    while( true ) {
      labelEntry = loopIndex * 0x1c + *(int *)(disasmState + 0x654);
      labelTableOrLine = (int *)(*(int *)(labelEntry + 0x14) + 1);
      if (labelTableOrLine == currentInstNumber) {
        ((int (*)())vsdisPrintFlowInstruction)(disassembler,labelEntry + 4,currentInstNumber,argR6Saved,argR7Saved,argR8,labelTableOrLine,argR10);
        currentInstNumber = (int *)disassembler[1];
      }
      loopIndex = loopIndex + 1;
      if (labelCount == loopIndex) break;
      disasmState = *disassembler;
    }
  }
  printf_LDBLStub_1a32d0(lineNumberText,"%3d:",currentInstNumber,argR6Saved,argR7Saved,argR8,labelTableOrLine,argR10);
  _strcat(lineBuffer,lineNumberText);
  disassembler[1] = disassembler[1] + 1;
  length = _strlen(lineBuffer);
  argR6Saved = ((int (*)())FUN_000cf2ec)(disassembler,instructionWords,lineBuffer + length,argR6,argR7);
  return argR6Saved;
}

/* vsDisassemble @ 0xd002c (728 bytes) */
int vsDisassemble(disassembler, program, mnemonicTextPtr, operandText0Ptr, operandText1Ptr, operandText2Ptr, operandText3Ptr, argR10)
  int *disassembler;
  int program;
  undefined1 *mnemonicTextPtr;
  int *operandText0Ptr;
  int *operandText1Ptr;
  undefined2 *operandText2Ptr;
  undefined1 *operandText3Ptr;
  undefined4 argR10;
{
  int length2;
  int length;
  int decodeResult;
  undefined4 nextWordPtr;
  int instructionCount;
  int loopIndex;
  int instructionPtr;
  int isMathEngineOp;
  int sourceCount;
  int operandText1 [5];
  undefined1 mnemonicText [22];
  undefined1 operandText3 [22];
  undefined2 operandText2 [11];
  int operandText0 [12];
  
  instructionPtr = *(int *)(program + 0x650);
  instructionCount = *(int *)(program + 0x65c);
  *disassembler = program;
  ((int (*)())FUN_000ce050)(disassembler,";*****************************************",mnemonicTextPtr,operandText0Ptr,operandText1Ptr,operandText2Ptr,
               operandText3Ptr,argR10);
  ((int (*)())FUN_000ce050)(disassembler,";              VS Disassembly             ",mnemonicTextPtr,operandText0Ptr,operandText1Ptr,operandText2Ptr,
               operandText3Ptr,argR10);
  ((int (*)())FUN_000ce050)(disassembler,";*****************************************",mnemonicTextPtr,operandText0Ptr,operandText1Ptr,operandText2Ptr,
               operandText3Ptr,argR10);
  if (instructionCount != 0) {
    loopIndex = 0;
    do {
      operandText0Ptr = &isMathEngineOp;
      operandText1Ptr = &sourceCount;
      decodeResult = ((int (*)())vsDisassembleLine)(disassembler,instructionPtr,mnemonicText,operandText0Ptr,&sourceCount,operandText2Ptr,operandText3Ptr,argR10);
      mnemonicTextPtr = mnemonicText;
      if (decodeResult == 0) {
        if (isMathEngineOp == 0) {
          nextWordPtr = ((int (*)())FUN_000cea6c)(disassembler,instructionPtr,operandText0,operandText0Ptr,operandText1Ptr,operandText2Ptr,operandText3Ptr,argR10);
          nextWordPtr = ((int (*)())FUN_000ce148)(disassembler,nextWordPtr,operandText1);
          nextWordPtr = ((int (*)())FUN_000ce148)(disassembler,nextWordPtr,operandText2);
          instructionPtr = ((int (*)())FUN_000ce148)(disassembler,nextWordPtr,operandText3);
          if (sourceCount == 1) {
            length = _strlen(operandText0);
            *(undefined2 *)((int)operandText0 + length) = 0x2c00;
            operandText0Ptr = operandText0;
            operandText1Ptr = operandText1;
            ((int (*)())FUN_000ce050)(disassembler,"%s %-10s%-15s",mnemonicText,operandText0,operandText1,operandText2Ptr,operandText3Ptr,
                         argR10);
          }
          else if (sourceCount == 0) {
            operandText0Ptr = operandText0;
            ((int (*)())FUN_000ce050)(disassembler,"%s %-10s",mnemonicText,operandText0,operandText1Ptr,operandText2Ptr,operandText3Ptr,argR10);
          }
          else if (sourceCount == 2) {
            length = _strlen(operandText0);
            *(undefined2 *)((int)operandText0 + length) = 0x2c00;
            length = _strlen(operandText1);
            *(undefined2 *)((int)operandText1 + length) = 0x2c00;
            operandText0Ptr = operandText0;
            operandText1Ptr = operandText1;
            operandText2Ptr = operandText2;
            ((int (*)())FUN_000ce050)(disassembler,"%s %-10s%-15s%-15s",mnemonicText,operandText0,operandText1,operandText2,
                         operandText3Ptr,argR10);
          }
          else {
            length = _strlen(operandText0);
            *(undefined2 *)((int)operandText0 + length) = 0x2c00;
            length = _strlen(operandText1);
            *(undefined2 *)((int)operandText1 + length) = 0x2c00;
            length = _strlen(operandText2);
            *(undefined2 *)((int)operandText2 + length) = 0x2c00;
            operandText0Ptr = operandText0;
            operandText1Ptr = operandText1;
            operandText2Ptr = operandText2;
            operandText3Ptr = operandText3;
            ((int (*)())FUN_000ce050)(disassembler,"%s %-10s%-15s%-15s%s",mnemonicText,operandText0,operandText1,operandText2,
                         operandText3,argR10);
          }
        }
        else {
          nextWordPtr = ((int (*)())FUN_000cea6c)(disassembler,instructionPtr,operandText0,operandText0Ptr,operandText1Ptr,operandText2Ptr,operandText3Ptr,argR10);
          nextWordPtr = ((int (*)())FUN_000ce148)(disassembler,nextWordPtr,operandText1);
          nextWordPtr = ((int (*)())FUN_000ce148)(disassembler,nextWordPtr,operandText2);
          length2 = _strlen(operandText0);
          *(undefined2 *)((int)operandText0 + length2) = 0x2c00;
          length2 = _strlen(operandText1);
          *(undefined2 *)((int)operandText1 + length2) = 0x2c00;
          operandText2Ptr = operandText2;
          ((int (*)())FUN_000ce050)(disassembler,"%s %-10s%-15s%-15s",mnemonicText,operandText0,operandText1,operandText2,
                       operandText3Ptr,argR10);
          instructionPtr = ((int (*)())FUN_000ced58)(disassembler,nextWordPtr,mnemonicText,operandText0,operandText1);
          operandText0Ptr = operandText0;
          operandText1Ptr = operandText1;
          ((int (*)())FUN_000ce050)(disassembler,"%s %-10s%-15s",mnemonicText,operandText0,operandText1,operandText2Ptr,operandText3Ptr,
                       argR10);
        }
      }
      else {
        instructionPtr = instructionPtr + 0x10;
        ((int (*)())FUN_000ce050)(disassembler,"%s",mnemonicText,operandText0Ptr,operandText1Ptr,operandText2Ptr,operandText3Ptr,argR10);
      }
      loopIndex = loopIndex + 1;
    } while (instructionCount != loopIndex);
  }
  ((int (*)())FUN_000ce050)(disassembler,"",mnemonicTextPtr,operandText0Ptr,operandText1Ptr,operandText2Ptr,operandText3Ptr,argR10);
  disassembler[1] = 0;
  return 1;
}

/* vsDisassembleToString @ 0xd0304 (60 bytes) */
int vsDisassembleToString(sinkArg, shaderState, sinkFn, argR6, argR7, argR8, argR9)
  undefined4 sinkArg;
  undefined4 shaderState;
  undefined4 sinkFn;
  undefined4 argR6;
  undefined4 argR7;
  undefined4 argR8;
  undefined4 argR9;
{
  undefined4 sinkFnCopy;
  undefined4 argR10;
  undefined1 sinkRecordHeader [8];
  undefined4 sinkRecordFn;
  undefined4 sinkRecordArg;
  
  sinkFnCopy = sinkFn;
  ((int (*)())vsdisClearSinkRecord2)(sinkRecordHeader);
  sinkRecordFn = sinkFn;
  sinkRecordArg = sinkArg;
  ((int (*)())vsdisPrintShaderData)(sinkRecordHeader,shaderState,sinkFnCopy,argR6,argR7,argR8,argR9,argR10);
  return 0;
}

/* vsDisassembleVertexProgram @ 0xd035c (60 bytes) */
int vsDisassembleVertexProgram(sinkArg, shaderState, optionsArg, sinkFn, argR7, argR8, argR9)
  undefined4 sinkArg;
  undefined4 shaderState;
  undefined4 optionsArg;
  undefined4 sinkFn;
  undefined4 argR7;
  undefined4 argR8;
  undefined4 argR9;
{
  undefined4 sinkFnCopy;
  undefined4 argR10;
  undefined1 sinkRecordHeader [8];
  undefined4 sinkRecordFn;
  undefined4 sinkRecordArg;
  
  sinkFnCopy = sinkFn;
  ((int (*)())vsdisClearSinkRecord2)(sinkRecordHeader);
  sinkRecordFn = sinkFn;
  sinkRecordArg = sinkArg;
  ((int (*)())vsDisassemble)(sinkRecordHeader,shaderState,optionsArg,sinkFnCopy,argR7,argR8,argR9,argR10);
  return 0;
}

/* psnReportError @ 0xd03b4 (152 bytes) */
int psnReportError(severity, format, fmtArg1, fmtArg2, fmtArg3, fmtArg4, fmtArg5, fmtArg6)
  undefined4 severity;
  undefined4 format;
  undefined4 fmtArg1;
  undefined4 fmtArg2;
  undefined4 fmtArg3;
  undefined4 fmtArg4;
  undefined4 fmtArg5;
  undefined4 fmtArg6;
{
  unsigned int ghidra_home[8] = { severity, format, fmtArg1, fmtArg2, fmtArg3, fmtArg4, fmtArg5, fmtArg6 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  undefined1 lineBuffer [280];
  
  if (DAT_001fa61c != (undefined4 *)0x0) {
    (*(unsigned int *)((unsigned char *)ghidra_home + 8)) = fmtArg1;
    (*(unsigned int *)((unsigned char *)ghidra_home + 12)) = fmtArg2;
    (*(unsigned int *)((unsigned char *)ghidra_home + 16)) = fmtArg3;
    (*(unsigned int *)((unsigned char *)ghidra_home + 20)) = fmtArg4;
    (*(unsigned int *)((unsigned char *)ghidra_home + 24)) = fmtArg5;
    (*(unsigned int *)((unsigned char *)ghidra_home + 28)) = fmtArg6;
    printf_LDBLStub_1a34d4(lineBuffer,format,&(*(unsigned int *)((unsigned char *)ghidra_home + 8)),fmtArg2,fmtArg3,fmtArg4,fmtArg5,fmtArg6);
    (*(code *)*DAT_001fa61c)(DAT_001fa618,"",lineBuffer,&(*(unsigned int *)((unsigned char *)ghidra_home + 8)));
  }
  return;
}

/* psnFormatRegister @ 0xd0450 (56 bytes) */
int psnFormatRegister(outBuffer, registerWord, unusedArg5, argR6, argR7, argR8, argR9)
  undefined4 outBuffer;
  uint registerWord;
  undefined4 unusedArg5;
  undefined4 argR6;
  undefined4 argR7;
  undefined4 argR8;
  undefined4 argR9;
{
  if ((registerWord & 0x8000) != 0) {
    printf_LDBLStub_1a32d0(outBuffer,"c%02u",registerWord & 0xffff7fff,argR6,argR7,argR8,argR9,0xd0458);
    return;
  }
  return printf_LDBLStub_1a32d0(outBuffer,"r%02u",registerWord,argR6,argR7,argR8,argR9,0xd0458);
}

/* psnFormatRgbSource @ 0xd0488 (552 bytes) */
int psnFormatRgbSource(outBuffer, source0Register, source1Register, source2Register, alpha0Register, alpha1Register, alpha2Register, selectCode, modifier)
  char *outBuffer;
  undefined4 source0Register;
  undefined4 source1Register;
  undefined4 source2Register;
  undefined4 alpha0Register;
  undefined4 alpha1Register;
  undefined4 alpha2Register;
  uint selectCode;
  int modifier;
{
  int length;
  char negPrefixTerm;
  char absPrefixTerm;
  char nabPrefixTerm;
  char unknownPrefixTerm;
  char *textEnd;
  undefined4 addrCopy;
  int padArgZero;
  undefined *swizzleJumpAddr;
  uint sourceSelectCopy;
  char operandText [6];
  undefined1 operandTextSecond [22];
  
  unknownPrefixTerm = s______001a6f98[4];
  nabPrefixTerm = s_nab__001a6f90[4];
  absPrefixTerm = s_abs__001a6f88[4];
  negPrefixTerm = s_neg__001a6f80[4];
  if (modifier == 1) {
    *(undefined4 *)outBuffer = (*(unsigned int *)((unsigned char *)&(s_neg__001a6f80) + 0));
    outBuffer[4] = negPrefixTerm;
  }
  else if (modifier == 0) {
    *outBuffer = '\0';
  }
  else if (modifier == 2) {
    *(undefined4 *)outBuffer = (*(unsigned int *)((unsigned char *)&(s_abs__001a6f88) + 0));
    outBuffer[4] = absPrefixTerm;
  }
  else if (modifier == 3) {
    *(undefined4 *)outBuffer = (*(unsigned int *)((unsigned char *)&(s_nab__001a6f90) + 0));
    outBuffer[4] = nabPrefixTerm;
  }
  else {
    *(undefined4 *)outBuffer = (*(unsigned int *)((unsigned char *)&(s______001a6f98) + 0));
    outBuffer[4] = unknownPrefixTerm;
  }
  sourceSelectCopy = selectCode;
  if (selectCode < 0x20) {
    padArgZero = 0;
    switch(selectCode) {
    default:
      ((int (*)())psnFormatRegister)(operandText,source0Register,source1Register,source2Register,alpha0Register,alpha1Register,padArgZero);
      break;
    case 4:
    case 5:
    case 6:
    case 7:
    case 0x18:
    case 0x1b:
      ((int (*)())psnFormatRegister)(operandText,source1Register,source1Register,source2Register,alpha0Register,alpha1Register,padArgZero);
      break;
    case 8:
    case 9:
    case 10:
    case 0xb:
    case 0x19:
    case 0x1c:
      ((int (*)())psnFormatRegister)(operandText,source2Register,source1Register,source2Register,alpha0Register,alpha1Register,padArgZero);
      break;
    case 0xc:
      ((int (*)())psnFormatRegister)(operandText,alpha0Register,source1Register,source2Register,alpha0Register,alpha1Register,padArgZero);
      break;
    case 0xd:
      ((int (*)())psnFormatRegister)(operandText,alpha1Register,source1Register,source2Register,alpha0Register,alpha1Register,padArgZero);
      break;
    case 0xe:
      ((int (*)())psnFormatRegister)(operandText,alpha2Register,source1Register,source2Register,alpha0Register,alpha1Register,padArgZero);
      break;
    case 0xf:
    case 0x10:
    case 0x11:
    case 0x12:
    case 0x13:
      operandText[0] = s_srcp_001a6fa0[0];
      operandText[1] = s_srcp_001a6fa0[1];
      operandText[2] = s_srcp_001a6fa0[2];
      operandText[3] = s_srcp_001a6fa0[3];
      operandText[4] = s_srcp_001a6fa0[4];
      break;
    case 0x14:
      builtin_strncpy(operandText,"0.0",4);
      break;
    case 0x15:
      builtin_strncpy(operandText,"1.0",4);
      break;
    case 0x16:
      builtin_strncpy(operandText,"0.5",4);
      break;
    case 0x1d:
      ((int (*)())psnFormatRegister)(operandText,alpha0Register,source1Register,source2Register,alpha0Register,alpha1Register,padArgZero);
      ((int (*)())psnFormatRegister)(operandTextSecond,source0Register,source1Register,source2Register,alpha0Register,alpha1Register,padArgZero);
      break;
    case 0x1e:
      addrCopy = source1Register;
      ((int (*)())psnFormatRegister)(operandText,alpha1Register,source1Register,source2Register,alpha0Register,alpha1Register,padArgZero);
      ((int (*)())psnFormatRegister)(operandTextSecond,source1Register,addrCopy,source2Register,alpha0Register,alpha1Register,padArgZero);
      break;
    case 0x1f:
      addrCopy = source2Register;
      ((int (*)())psnFormatRegister)(operandText,alpha2Register,source1Register,source2Register,alpha0Register,alpha1Register,padArgZero);
      ((int (*)())psnFormatRegister)(operandTextSecond,source2Register,source1Register,addrCopy,alpha0Register,alpha1Register,padArgZero);
      source2Register = addrCopy;
    }
  }
  else {
    builtin_strncpy(operandText,"???",4);
  }
  length = _strlen(outBuffer);
  textEnd = outBuffer + length;
  if (selectCode < 0x20) {
    swizzleJumpAddr = ((unsigned char *)0x000d0730) + *(int *)(((unsigned char *)0x000d0730) + selectCode * 4);
                    
    switch(selectCode) {
    default:
      printf_LDBLStub_1a32d0(textEnd,"%s.rgb",operandText,source2Register,alpha0Register,alpha1Register,swizzleJumpAddr,sourceSelectCopy);
      break;
    case 1:
    case 5:
    case 9:
    case 0x10:
      printf_LDBLStub_1a32d0(textEnd,"%s.rrr",operandText,source2Register,alpha0Register,alpha1Register,swizzleJumpAddr,sourceSelectCopy);
      break;
    case 2:
    case 6:
    case 10:
    case 0x11:
      printf_LDBLStub_1a32d0(textEnd,"%s.ggg",operandText,source2Register,alpha0Register,alpha1Register,swizzleJumpAddr,sourceSelectCopy);
      break;
    case 3:
    case 7:
    case 0xb:
    case 0x12:
      printf_LDBLStub_1a32d0(textEnd,"%s.bbb",operandText,source2Register,alpha0Register,alpha1Register,swizzleJumpAddr,sourceSelectCopy);
      break;
    case 0xc:
    case 0xd:
    case 0xe:
    case 0x13:
      printf_LDBLStub_1a32d0(textEnd,"%s.aaa",operandText,source2Register,alpha0Register,alpha1Register,swizzleJumpAddr,sourceSelectCopy);
      break;
    case 0x14:
    case 0x15:
    case 0x16:
      goto override_jmp_000d072c_case_5;
    case 0x17:
    case 0x18:
    case 0x19:
      printf_LDBLStub_1a32d0(textEnd,"%s.gbr",operandText,source2Register,alpha0Register,alpha1Register,swizzleJumpAddr,sourceSelectCopy);
      break;
    case 0x1a:
    case 0x1b:
    case 0x1c:
      printf_LDBLStub_1a32d0(textEnd,"%s.brg",operandText,source2Register,alpha0Register,alpha1Register,swizzleJumpAddr,sourceSelectCopy);
      break;
    case 0x1d:
      printf_LDBLStub_1a32d0(textEnd,"%s.a:%s.bg",operandText,operandTextSecond,alpha0Register,alpha1Register,swizzleJumpAddr,sourceSelectCopy);
    }
  }
  else {
override_jmp_000d072c_case_5:
    _strcpy(textEnd,operandText);
  }
  length = _strlen(outBuffer);
  if (modifier != 0) {
    (outBuffer + length)[0] = ')';
    (outBuffer + length)[1] = '\0';
  }
  return;
}

/* psnFormatAlphaSource @ 0xd0888 (464 bytes) */
int psnFormatAlphaSource(outBuffer, source0Register, source1Register, source2Register, alpha0Register, alpha1Register, alpha2Register, selectCode, modifier)
  char *outBuffer;
  undefined4 source0Register;
  undefined4 source1Register;
  undefined4 source2Register;
  undefined4 alpha0Register;
  undefined4 alpha1Register;
  undefined4 alpha2Register;
  uint selectCode;
  int modifier;
{
  int length;
  char negPrefixTerm;
  char absPrefixTerm;
  char nabPrefixTerm;
  char unknownPrefixTerm;
  char *textEnd;
  int padArgZero;
  undefined *componentJumpAddr;
  uint sourceSelectCopy;
  char operandText [24];
  
  unknownPrefixTerm = s______001a6f98[4];
  nabPrefixTerm = s_nab__001a6f90[4];
  absPrefixTerm = s_abs__001a6f88[4];
  negPrefixTerm = s_neg__001a6f80[4];
  if (modifier == 1) {
    *(undefined4 *)outBuffer = (*(unsigned int *)((unsigned char *)&(s_neg__001a6f80) + 0));
    outBuffer[4] = negPrefixTerm;
  }
  else if (modifier == 0) {
    *outBuffer = '\0';
  }
  else if (modifier == 2) {
    *(undefined4 *)outBuffer = (*(unsigned int *)((unsigned char *)&(s_abs__001a6f88) + 0));
    outBuffer[4] = absPrefixTerm;
  }
  else if (modifier == 3) {
    *(undefined4 *)outBuffer = (*(unsigned int *)((unsigned char *)&(s_nab__001a6f90) + 0));
    outBuffer[4] = nabPrefixTerm;
  }
  else {
    *(undefined4 *)outBuffer = (*(unsigned int *)((unsigned char *)&(s______001a6f98) + 0));
    outBuffer[4] = unknownPrefixTerm;
  }
  sourceSelectCopy = selectCode;
  if (selectCode < 0x13) {
    padArgZero = 0;
    switch(selectCode) {
    case 0:
    case 1:
    case 2:
      ((int (*)())psnFormatRegister)(operandText,source0Register,source1Register,source2Register,alpha0Register,alpha1Register,padArgZero);
      break;
    case 3:
    case 4:
    case 5:
      ((int (*)())psnFormatRegister)(operandText,source1Register,source1Register,source2Register,alpha0Register,alpha1Register,padArgZero);
      break;
    case 6:
    case 7:
    case 8:
      ((int (*)())psnFormatRegister)(operandText,source2Register,source1Register,source2Register,alpha0Register,alpha1Register,padArgZero);
      break;
    case 9:
      ((int (*)())psnFormatRegister)(operandText,alpha0Register,source1Register,source2Register,alpha0Register,alpha1Register,padArgZero);
      break;
    case 10:
      ((int (*)())psnFormatRegister)(operandText,alpha1Register,source1Register,source2Register,alpha0Register,alpha1Register,padArgZero);
      break;
    case 0xb:
      ((int (*)())psnFormatRegister)(operandText,alpha2Register,source1Register,source2Register,alpha0Register,alpha1Register,padArgZero);
      break;
    default:
      operandText[0] = s_srcp_001a6fa0[0];
      operandText[1] = s_srcp_001a6fa0[1];
      operandText[2] = s_srcp_001a6fa0[2];
      operandText[3] = s_srcp_001a6fa0[3];
      operandText[4] = s_srcp_001a6fa0[4];
      break;
    case 0x10:
      builtin_strncpy(operandText,"0.0",4);
      break;
    case 0x11:
      builtin_strncpy(operandText,"1.0",4);
      break;
    case 0x12:
      builtin_strncpy(operandText,"0.5",4);
    }
  }
  else {
    builtin_strncpy(operandText,"???",4);
  }
  length = _strlen(outBuffer);
  textEnd = outBuffer + length;
  if (selectCode < 0x10) {
    componentJumpAddr = ((unsigned char *)0x000d0aa4) + *(int *)(((unsigned char *)0x000d0aa4) + selectCode * 4);
                    
    switch(selectCode) {
    default:
      printf_LDBLStub_1a32d0(textEnd,"%s.r",operandText,source2Register,alpha0Register,alpha1Register,componentJumpAddr,sourceSelectCopy);
      break;
    case 1:
    case 4:
    case 7:
      printf_LDBLStub_1a32d0(textEnd,"%s.g",operandText,source2Register,alpha0Register,alpha1Register,componentJumpAddr,sourceSelectCopy);
      break;
    case 2:
    case 5:
    case 8:
      printf_LDBLStub_1a32d0(textEnd,"%s.b",operandText,source2Register,alpha0Register,alpha1Register,componentJumpAddr,sourceSelectCopy);
      break;
    case 9:
      printf_LDBLStub_1a32d0(textEnd,"%s.a",operandText,source2Register,alpha0Register,alpha1Register,componentJumpAddr,sourceSelectCopy);
    }
  }
  else {
    _strcpy(textEnd,operandText);
  }
  length = _strlen(outBuffer);
  if (modifier != 0) {
    (outBuffer + length)[0] = ')';
    (outBuffer + length)[1] = '\0';
  }
  return;
}

/* psnNormalizeProgram @ 0xd0b68 (1344 bytes) */
int psnNormalizeProgram(psn, level, dumpIdArg, argR6, argR7, argR8, argR9Scratch, argR10)
  int psn;
  uint level;
  undefined4 dumpIdArg;
  undefined4 argR6;
  undefined4 argR7;
  undefined4 argR8;
  uint argR9Scratch;
  undefined4 argR10;
{
  bool hasWaitFlags;
  uint fixupRecordIndex;
  uint pendingTexIndex;
  uint recordKind2;
  uint nextPendingTexIndex;
  uint cfOpSelect;
  uint cfWordMask;
  uint loopIndex2;
  bool needsFlowControl;
  byte texFlagsByte;
  bool r300Compatible;
  uint recordKind;
  uint cfOpA;
  int pendingTexRecord;
  int *rsScanCursor;
  uint cfOpB;
  uint texCustomEnables;
  uint waitFlagsOr;
  uint loopIndex;
  uint recordCount;
  uint usInstructionNumber;
  undefined1 *prevRecordFlagPtr;
  uint scanRecordIndex;
  uint cfDepth;
  uint *recordCursor;
  
  if (level <= (*(byte *)(psn + 0xf) & 0xf)) {
    return;
  }
  recordCount = *(uint *)(psn + 8);
  if ((*(int *)(psn + 0x48) == 1) && (recordCount != 0)) {
    rsScanCursor = (int *)(psn + 0x90);
    loopIndex = 1;
    do {
      loopIndex = loopIndex + 1;
      if (*rsScanCursor != 1) goto LAB_000d0bfc;
      rsScanCursor = rsScanCursor + 0x12;
    } while (loopIndex <= recordCount);
LAB_000d0bd8:
    waitFlagsOr = 0;
    texCustomEnables = 0;
    r300Compatible = true;
  }
  else {
    loopIndex = 1;
LAB_000d0bfc:
    if (recordCount < loopIndex) goto LAB_000d0bd8;
    waitFlagsOr = 0;
    r300Compatible = true;
    recordCursor = (uint *)(psn + loopIndex * 0x48);
    cfDepth = 0;
    usInstructionNumber = 0;
    needsFlowControl = false;
    texCustomEnables = 0;
    scanRecordIndex = loopIndex;
    do {
      recordKind = *recordCursor;
      if (recordKind < 5) {
        if (recordKind < 3) {
          if (recordKind != 2) goto LAB_000d0c50;
          argR9Scratch = (uint)*(byte *)((int)recordCursor + 0x1b);
          waitFlagsOr = waitFlagsOr | *(byte *)(recordCursor + 1) | argR9Scratch;
          if (*(char *)((int)recordCursor + 0x1a) != '\0') {
            texCustomEnables = texCustomEnables | -(uint)(recordCursor[7] & 0xffff00) >> 0x1f;
          }
        }
        else {
          waitFlagsOr = waitFlagsOr | *(byte *)(recordCursor + 1);
        }
      }
      else if (recordKind == 5) {
        waitFlagsOr = waitFlagsOr | *(byte *)(recordCursor + 1);
        if (r300Compatible) {
          if ((*(char *)((int)recordCursor + 0xe) != '\0') || (*(char *)((int)recordCursor + 0x11) != '\0')) {
            needsFlowControl = true;
          }
          cfWordMask = recordCursor[4] & 0xff00ff00;
          if ((cfWordMask != 0) &&
             ((*(ushort *)(recordCursor + 3) < usInstructionNumber || (*(char *)((int)recordCursor + 0x19) != '\0')))) {
            needsFlowControl = true;
          }
          cfOpA = (uint)*(byte *)(recordCursor + 5);
          cfOpB = (uint)*(byte *)((int)recordCursor + 0x15);
          argR9Scratch = cfOpA;
          if ((cfWordMask != 0) && (argR9Scratch = cfOpB, cfWordMask == 0x100ff00)) {
            cfOpA = cfOpB;
          }
          cfOpSelect = argR9Scratch;
          if ((cfOpA == 1) || (cfOpSelect = cfOpA, cfOpA != 0)) {
            if (cfOpSelect == 2) goto LAB_000d0d60;
            if (cfOpSelect == 1) {
              cfDepth = cfDepth - *(byte *)((int)recordCursor + 0x13);
            }
          }
          else if (argR9Scratch == 2) {
LAB_000d0d60:
            cfDepth = cfDepth + 1;
          }
          r300Compatible = !needsFlowControl;
          if (4 < cfDepth) {
            needsFlowControl = true;
            r300Compatible = false;
          }
        }
      }
      else {
LAB_000d0c50:
        ((int (*)())psnReportError)(0,"Bad Instruction Type!",dumpIdArg,argR6,argR7,argR8,argR9Scratch,argR10);
      }
      scanRecordIndex = scanRecordIndex + 1;
      usInstructionNumber = usInstructionNumber + 1;
      recordCursor = recordCursor + 0x12;
    } while (scanRecordIndex <= recordCount);
    if (usInstructionNumber != 0) goto LAB_000d0be8;
  }
  usInstructionNumber = 1;
LAB_000d0be8:
  if ((*(short *)(psn + 0x20) == 0) && (*(short *)(psn + 0x12) == 0)) {
    *(short *)(psn + 0x12) = (short)usInstructionNumber + -1;
  }
  if (!r300Compatible) {
    *(undefined2 *)(psn + 0x28) = 1;
  }
  if ((*(short *)(psn + 0x28) != 0) && (*(short *)(psn + 0x22) == 0)) {
    *(undefined2 *)(psn + 0x22) = 1;
  }
  if (loopIndex <= recordCount) {
    hasWaitFlags = waitFlagsOr != 0;
    recordCursor = (uint *)(psn + loopIndex * 0x48);
    prevRecordFlagPtr = (undefined1 *)((int)recordCursor + -3);
    loopIndex2 = 0;
    pendingTexIndex = 100000;
    fixupRecordIndex = loopIndex;
    do {
      recordKind2 = *recordCursor;
      nextPendingTexIndex = pendingTexIndex;
      if (recordKind2 < 5) {
        if (recordKind2 < 3) {
          if (recordKind2 == 2) {
            if (texCustomEnables == 0) {
              *(undefined1 *)((int)recordCursor + 0x1e) = 1;
              *(undefined1 *)((int)recordCursor + 0x1d) = 7;
              recordCursor[5] = recordCursor[5] & 0xffff | 0x1b1b0000;
            }
            texFlagsByte = *(byte *)((int)recordCursor + 0x1f);
            argR9Scratch = (uint)texFlagsByte;
            if (argR9Scratch != 0) {
              if ((texFlagsByte & 2) != 0) {
                recordCursor[5] = recordCursor[5] >> 2 & 0x300000 | recordCursor[5] & 0xffcfffff;
              }
              if ((texFlagsByte & 4) != 0) {
                recordCursor[5] = recordCursor[5] >> 4 & 0xc0000 | recordCursor[5] & 0xfff3ffff;
              }
              if ((texFlagsByte & 8) != 0) {
                recordCursor[5] = recordCursor[5] >> 6 & 0x30000 | recordCursor[5] & 0xfffcffff;
              }
            }
            nextPendingTexIndex = fixupRecordIndex;
            if (((!hasWaitFlags) && (*(char *)(recordCursor + 8) != '\0')) && (pendingTexIndex != 100000)) {
              pendingTexRecord = psn + pendingTexIndex * 0x48;
              *(undefined1 *)(pendingTexRecord + 4) = 1;
              *(undefined1 *)(pendingTexRecord + 0x1b) = 1;
              *(undefined1 *)(recordCursor + 1) = 1;
            }
          }
        }
        else {
          if (((*(char *)((int)recordCursor + 0x15) == '\0') &&
              (argR9Scratch = recordCursor[8] & 0xff00ff, argR9Scratch == 0)) &&
             (loopIndex2 != *(ushort *)(psn + 0x12))) {
            *recordCursor = 4;
          }
          if ((hasWaitFlags) || (pendingTexIndex == 100000)) {
LAB_000d1004:
            nextPendingTexIndex = 100000;
          }
          else {
            pendingTexRecord = psn + pendingTexIndex * 0x48;
            *(undefined1 *)(pendingTexRecord + 4) = 1;
            *(undefined1 *)(pendingTexRecord + 0x1b) = 1;
            *(undefined1 *)(recordCursor + 1) = 1;
            nextPendingTexIndex = 100000;
          }
        }
      }
      else if (recordKind2 == 5) {
        if ((!hasWaitFlags) && (pendingTexIndex != 100000)) {
          pendingTexRecord = psn + pendingTexIndex * 0x48;
          *(undefined1 *)(pendingTexRecord + 4) = 1;
          *(undefined1 *)(pendingTexRecord + 0x1b) = 1;
          *(undefined1 *)(recordCursor + 1) = 1;
        }
        if ((byte)(*(byte *)((int)recordCursor + 0x12) & 0xf0) ==
            (byte)(*(byte *)((int)recordCursor + 0x12) << 4)) goto LAB_000d1004;
        if (loopIndex2 == 0) {
          ((int (*)())psnReportError)(0,"FC ALU result test is first US instruction",dumpIdArg,argR6,argR7,
                       argR8,argR9Scratch,argR10);
          nextPendingTexIndex = 100000;
        }
        else if (*(int *)(prevRecordFlagPtr + -0x45) - 3U < 2) {
          *prevRecordFlagPtr = 1;
          nextPendingTexIndex = 100000;
        }
        else {
          ((int (*)())psnReportError)(0,"FC ALU result test follows non-ALU instruction",dumpIdArg,argR6,argR7,
                       argR8,argR9Scratch,argR10);
          nextPendingTexIndex = 100000;
        }
      }
      fixupRecordIndex = fixupRecordIndex + 1;
      loopIndex2 = loopIndex2 + 1;
      recordCursor = recordCursor + 0x12;
      prevRecordFlagPtr = prevRecordFlagPtr + 0x48;
      pendingTexIndex = nextPendingTexIndex;
    } while (fixupRecordIndex <= recordCount);
    if (((loopIndex2 != 0) &&
        (pendingTexRecord = (*(ushort *)(psn + 0x12) + loopIndex) * 0x48, *(int *)(psn + pendingTexRecord) == 3)) &&
       (waitFlagsOr == 0)) {
      *(undefined1 *)(psn + pendingTexRecord + 4) = 1;
    }
  }
  if (((texCustomEnables != 0) || (waitFlagsOr != 0)) || (*(short *)(psn + 0x20) != 0)) {
    level = level | level << 4;
  }
  *(char *)(psn + 0xf) = (char)level;
  return;
}

/* psnSwizzleIsAlphaSourceForm @ 0xd10a8 (52 bytes) */
int psnSwizzleIsAlphaSourceForm(param_1)
  uint param_1;
{
  if ((((param_1 & 0xe000) != 0x6000) && ((param_1 & 0x1c00) != 0xc00)) &&
     ((param_1 & 0x380) != 0x180)) {
    return 0;
  }
  return 1;
}

/* FUN_000d10dc @ 0xd10dc (712 bytes) */
double FUN_000d10dc(undefined4 outText,uint registerWord,undefined4 argR5,undefined4 argR6,undefined4 argR7,undefined4 argR8,undefined4 argR9,undefined4 argR10,double floatArg1)
{
  bool moreDigits;
  double i2dMagic;
  double ten;
  int zeroFillIndex;
  uint digitValue;
  int digitIndex;
  uint decimalExponent;
  int zeroFillRemaining;
  double immediateValue;
  double exponentEstimate;
  double scaledMantissa;
  char numberText [10];
  undefined1 expMarker;
  undefined1 expSign;
  char expTensDigit;
  undefined1 expOnesDigit;
  undefined1 numberTextEnd;
  undefined4 i2dHi1;
  uint i2dLo1;
  longlong fctiwzScratch1;
  undefined4 i2dHi4;
  uint i2dLo4;
  undefined4 i2dHi2;
  uint i2dLo2;
  longlong fctiwzScratch2;
  undefined4 i2dHi3;
  uint i2dLo3;
  longlong fctiwzScratch3;
  float valueAsFloat;
  
  if ((registerWord & 0x8000) == 0) {
    if ((registerWord & 0x4000) == 0) {
      if ((registerWord & 0x2000) == 0) {
        printf_LDBLStub_1a32d0(outText,"r%02u",registerWord,argR6,argR7,argR8,argR9,argR10);
      }
      else {
        immediateValue = (double)((double (*)())FUN_000da78c)(registerWord & 0xffffdfff,floatArg1);
        ten = DOUBLE_001aa238;
        i2dMagic = DOUBLE_001aa1e0;
        if (immediateValue == (double)FLOAT_001aa0d4) {
          numberText[0] = ' ';
          numberText[2] = 0x2e;
          zeroFillRemaining = 7;
          numberText[1] = '0';
          zeroFillIndex = 3;
          digitIndex = 0x30;
          do {
            numberText[zeroFillIndex] = '0';
            zeroFillIndex = zeroFillIndex + 1;
            zeroFillRemaining = zeroFillRemaining + -1;
          } while (zeroFillRemaining != 0);
          expSign = 0x2b;
          expOnesDigit = 0x30;
          expTensDigit = '0';
        }
        else {
          if (immediateValue < (double)FLOAT_001aa0d4) {
            immediateValue = -immediateValue;
            numberText[0] = '-';
          }
          else {
            numberText[0] = '+';
          }
          valueAsFloat = (float)immediateValue;
          i2dHi1 = 0x43300000;
          i2dLo1 = ((uint)(int)valueAsFloat >> 0x17 & 0xff) - 0x7f ^ 0x80000000;
          exponentEstimate = _pow(DOUBLE_001aa2a0,(double)CONCAT44(0x43300000,i2dLo1) - DOUBLE_001aa1e0);
          exponentEstimate = _log(exponentEstimate);
          scaledMantissa = _log(ten);
          exponentEstimate = _floor(exponentEstimate / scaledMantissa);
          i2dHi4 = 0x43300000;
          decimalExponent = (uint)(int)exponentEstimate;
          fctiwzScratch1 = (longlong)(int)decimalExponent;
          i2dLo4 = decimalExponent ^ 0x80000000;
          scaledMantissa = _pow(ten,(double)CONCAT44(0x43300000,i2dLo4) - i2dMagic);
          exponentEstimate = DOUBLE_001aa298;
          scaledMantissa = immediateValue / scaledMantissa + DOUBLE_001aa298;
          if (ten <= scaledMantissa) {
            decimalExponent = decimalExponent + 1;
            i2dHi2 = 0x43300000;
            i2dLo2 = decimalExponent ^ 0x80000000;
            scaledMantissa = _pow(ten,(double)CONCAT44(0x43300000,i2dLo2) - i2dMagic);
            scaledMantissa = immediateValue / scaledMantissa + exponentEstimate;
          }
          immediateValue = _floor(scaledMantissa);
          digitValue = (uint)(int)immediateValue;
          fctiwzScratch2 = (longlong)(int)digitValue;
          numberText[2] = 0x2e;
          digitIndex = 3;
          numberText[1] = (char)digitValue + '0';
          do {
            i2dLo3 = digitValue ^ 0x80000000;
            i2dHi3 = 0x43300000;
            scaledMantissa = (scaledMantissa - ((double)CONCAT44(0x43300000,i2dLo3) - i2dMagic)) * ten;
            immediateValue = _floor(scaledMantissa);
            moreDigits = digitIndex != 9;
            digitValue = (uint)(int)immediateValue;
            fctiwzScratch3 = (longlong)(int)digitValue;
            numberText[digitIndex] = (char)digitValue + '0';
            digitIndex = digitIndex + 1;
          } while (moreDigits);
          if ((int)decimalExponent < 0) {
            decimalExponent = -decimalExponent;
            expSign = 0x2d;
          }
          else {
            expSign = 0x2b;
          }
          expTensDigit = (char)((int)decimalExponent / 10) + '0';
          digitIndex = (int)decimalExponent % 10 + 0x30;
          expOnesDigit = (undefined1)digitIndex;
        }
        expMarker = 0x45;
        numberTextEnd = 0;
        printf_LDBLStub_1a32d0(outText,"(%s)",numberText,argR6,argR7,argR8,digitIndex,argR10);
      }
    }
    else {
      printf_LDBLStub_1a32d0(outText,"r[AL+%02u]",registerWord & 0xffffbfff,argR6,argR7,argR8,argR9,argR10
                  );
    }
  }
  else {
    printf_LDBLStub_1a32d0(outText,"c%02u",registerWord & 0xffff7fff,argR6,argR7,argR8,argR9,argR10);
  }
  return;
}

/* FUN_000d13a4 @ 0xd13a4 (640 bytes) */
int FUN_000d13a4(outText, rgbAddrA, rgbAddrB, rgbAddrC, alphaAddrA, alphaAddrB, alphaAddrC, sourceSelect, sourceModifier, swizzleWord, rgbOpcode)
  char *outText;
  undefined4 rgbAddrA;
  undefined4 rgbAddrB;
  undefined4 rgbAddrC;
  undefined4 alphaAddrA;
  undefined4 alphaAddrB;
  char *alphaAddrC;
  int sourceSelect;
  int sourceModifier;
  uint swizzleWord;
  int rgbOpcode;
{
  int length;
  int length2;
  uint swizzleLow16;
  uint swizzleKind;
  char negPrefixTerm;
  char absPrefixTerm;
  char nabPrefixTerm;
  char unknownPrefixTerm;
  int auxCheckResult;
  int sourceSelectCopy;
  undefined4 rgbAddrBSaved;
  undefined4 rgbAddrCSaved;
  undefined4 alphaAddrASaved;
  undefined4 alphaAddrBSaved;
  char *modifierPrefix;
  double floatArg1;
  double floatArg1Saved;
  char operandText [44];
  
  unknownPrefixTerm = s______001a6f98[4];
  nabPrefixTerm = s_nab__001a6f90[4];
  absPrefixTerm = s_abs__001a6f88[4];
  negPrefixTerm = s_neg__001a6f80[4];
  if (sourceModifier == 1) {
    modifierPrefix = "neg(";
    *(undefined4 *)outText = (*(unsigned int *)((unsigned char *)&(s_neg__001a6f80) + 0));
    outText[4] = negPrefixTerm;
  }
  else if (sourceModifier == 0) {
    *outText = '\0';
    modifierPrefix = alphaAddrC;
  }
  else if (sourceModifier == 2) {
    *(undefined4 *)outText = (*(unsigned int *)((unsigned char *)&(s_abs__001a6f88) + 0));
    outText[4] = absPrefixTerm;
    modifierPrefix = "abs(";
  }
  else if (sourceModifier == 3) {
    *(undefined4 *)outText = (*(unsigned int *)((unsigned char *)&(s_nab__001a6f90) + 0));
    outText[4] = nabPrefixTerm;
    modifierPrefix = "nab(";
  }
  else {
    *(undefined4 *)outText = (*(unsigned int *)((unsigned char *)&(s______001a6f98) + 0));
    outText[4] = unknownPrefixTerm;
    modifierPrefix = "???(";
  }
  rgbAddrCSaved = rgbAddrC;
  sourceSelectCopy = sourceSelect;
  if (rgbOpcode - 0xbU < 2) {
LAB_000d14bc:
    ((double (*)())FUN_000d10dc)(operandText,rgbAddrA,rgbAddrB,rgbAddrCSaved,alphaAddrA,alphaAddrB,modifierPrefix,sourceSelectCopy,floatArg1);
  }
  else {
    rgbAddrBSaved = rgbAddrB;
    alphaAddrASaved = alphaAddrA;
    alphaAddrBSaved = alphaAddrB;
    auxCheckResult = ((int (*)())psnSwizzleIsAlphaSourceForm)(swizzleWord & 0xffff);
    if (auxCheckResult == 0) {
      if (sourceSelect == 1) {
        ((double (*)())FUN_000d10dc)(operandText,rgbAddrB,rgbAddrBSaved,rgbAddrCSaved,alphaAddrASaved,alphaAddrBSaved,modifierPrefix,sourceSelectCopy,floatArg1Saved);
        goto LAB_000d1518;
      }
      rgbAddrB = rgbAddrBSaved;
      alphaAddrA = alphaAddrASaved;
      alphaAddrB = alphaAddrBSaved;
      floatArg1 = floatArg1Saved;
      if (sourceSelect == 0) goto LAB_000d14bc;
      if (sourceSelect == 2) {
        ((double (*)())FUN_000d10dc)(operandText,rgbAddrC,rgbAddrBSaved,rgbAddrCSaved,alphaAddrASaved,alphaAddrBSaved,modifierPrefix,sourceSelectCopy,floatArg1Saved);
        goto LAB_000d1518;
      }
    }
    else {
      if (sourceSelect == 1) {
        ((double (*)())FUN_000d10dc)(operandText,alphaAddrB,rgbAddrBSaved,rgbAddrCSaved,alphaAddrASaved,alphaAddrBSaved,modifierPrefix,sourceSelectCopy,floatArg1Saved);
        goto LAB_000d1518;
      }
      if (sourceSelect == 0) {
        ((double (*)())FUN_000d10dc)(operandText,alphaAddrA,rgbAddrBSaved,rgbAddrCSaved,alphaAddrASaved,alphaAddrBSaved,modifierPrefix,sourceSelectCopy,floatArg1Saved);
        goto LAB_000d1518;
      }
      if (sourceSelect == 2) {
        ((double (*)())FUN_000d10dc)(operandText,alphaAddrC,rgbAddrBSaved,rgbAddrCSaved,alphaAddrASaved,alphaAddrBSaved,modifierPrefix,sourceSelectCopy,floatArg1Saved);
        goto LAB_000d1518;
      }
    }
    if (sourceSelect == 3) {
      operandText[0] = s_srcp_001a6fa0[0];
      operandText[1] = s_srcp_001a6fa0[1];
      operandText[2] = s_srcp_001a6fa0[2];
      operandText[3] = s_srcp_001a6fa0[3];
      operandText[4] = s_srcp_001a6fa0[4];
    }
    else {
      builtin_strncpy(operandText,"???",4);
    }
  }
LAB_000d1518:
  length2 = _strlen(outText);
  swizzleLow16 = swizzleWord & 0xffff;
  swizzleKind = swizzleWord & 0xff80;
  if (((swizzleKind == 0x9200) || (swizzleKind == 0xdb00)) || (swizzleKind == 0xb680)) {
    _strcpy(outText + length2,(swizzleLow16 >> 0xb & 0x1c) + 0x1dc259);
  }
  else {
    printf_LDBLStub_1a32d0(outText + length2,"%s.%s%s%s",operandText,(swizzleLow16 >> 0xb & 0x1c) + 0x1dc259,
                 (swizzleLow16 >> 8 & 0x1c) + 0x1dc259,(swizzleLow16 >> 5 & 0x1c) + 0x1dc259,swizzleLow16,sourceSelectCopy);
  }
  length = _strlen(outText);
  if (sourceModifier != 0) {
    (outText + length)[0] = ')';
    (outText + length)[1] = '\0';
  }
  return;
}

/* FUN_000d1624 @ 0xd1624 (536 bytes) */
int FUN_000d1624(outText, rgbAddrA, rgbAddrB, rgbAddrC, alphaAddrA, alphaAddrB, alphaAddrC, sourceSelect, sourceModifier, componentCode, alphaOpcode)
  char *outText;
  undefined4 rgbAddrA;
  undefined4 rgbAddrB;
  undefined4 rgbAddrC;
  undefined4 alphaAddrA;
  undefined4 alphaAddrB;
  char *alphaAddrC;
  int sourceSelect;
  int sourceModifier;
  int componentCode;
  int alphaOpcode;
{
  char negPrefixTerm;
  char absPrefixTerm;
  char nabPrefixTerm;
  char unknownPrefixTerm;
  int length;
  char *modifierPrefix;
  double floatArg1;
  char operandText [40];
  
  unknownPrefixTerm = s______001a6f98[4];
  nabPrefixTerm = s_nab__001a6f90[4];
  absPrefixTerm = s_abs__001a6f88[4];
  negPrefixTerm = s_neg__001a6f80[4];
  if (sourceModifier == 1) {
    modifierPrefix = "neg(";
    *(undefined4 *)outText = (*(unsigned int *)((unsigned char *)&(s_neg__001a6f80) + 0));
    outText[4] = negPrefixTerm;
  }
  else if (sourceModifier == 0) {
    *outText = '\0';
    modifierPrefix = alphaAddrC;
  }
  else if (sourceModifier == 2) {
    *(undefined4 *)outText = (*(unsigned int *)((unsigned char *)&(s_abs__001a6f88) + 0));
    outText[4] = absPrefixTerm;
    modifierPrefix = "abs(";
  }
  else if (sourceModifier == 3) {
    *(undefined4 *)outText = (*(unsigned int *)((unsigned char *)&(s_nab__001a6f90) + 0));
    outText[4] = nabPrefixTerm;
    modifierPrefix = "nab(";
  }
  else {
    *(undefined4 *)outText = (*(unsigned int *)((unsigned char *)&(s______001a6f98) + 0));
    outText[4] = unknownPrefixTerm;
    modifierPrefix = "???(";
  }
  if (1 < alphaOpcode - 0xeU) {
    if (componentCode != 3) {
      if (sourceSelect != 1) {
        if (sourceSelect == 0) {
          ((double (*)())FUN_000d10dc)(operandText,rgbAddrA,alphaAddrC,rgbAddrC,alphaAddrA,alphaAddrB,modifierPrefix,0,floatArg1);
          goto LAB_000d1780;
        }
        rgbAddrB = rgbAddrC;
        if (sourceSelect != 2) goto LAB_000d176c;
      }
      ((double (*)())FUN_000d10dc)(operandText,rgbAddrB,alphaAddrC,rgbAddrC,alphaAddrA,alphaAddrB,modifierPrefix,sourceSelect,floatArg1);
      goto LAB_000d1780;
    }
    if (sourceSelect == 1) {
      ((double (*)())FUN_000d10dc)(operandText,alphaAddrB,alphaAddrC,rgbAddrC,alphaAddrA,alphaAddrB,modifierPrefix,1,floatArg1);
      goto LAB_000d1780;
    }
    if (sourceSelect != 0) {
      if (sourceSelect == 2) {
        ((double (*)())FUN_000d10dc)(operandText,alphaAddrC,alphaAddrC,rgbAddrC,alphaAddrA,alphaAddrB,modifierPrefix,2,floatArg1);
        goto LAB_000d1780;
      }
LAB_000d176c:
      if (sourceSelect == 3) {
        modifierPrefix = "srcp";
        operandText[0] = s_srcp_001a6fa0[0];
        operandText[1] = s_srcp_001a6fa0[1];
        operandText[2] = s_srcp_001a6fa0[2];
        operandText[3] = s_srcp_001a6fa0[3];
        operandText[4] = s_srcp_001a6fa0[4];
      }
      else {
        builtin_strncpy(operandText,"???",4);
      }
      goto LAB_000d1780;
    }
  }
  ((double (*)())FUN_000d10dc)(operandText,alphaAddrA,alphaAddrC,rgbAddrC,alphaAddrA,alphaAddrB,modifierPrefix,sourceSelect,floatArg1);
LAB_000d1780:
  length = _strlen(outText);
  if (componentCode - 4U < 3) {
    _strcpy(outText + length,componentCode * 4 + 0x1dc259);
  }
  else {
    printf_LDBLStub_1a32d0(outText + length,"%s.%s",operandText,componentCode * 4 + 0x1dc259,alphaAddrA,alphaAddrB,modifierPrefix,
                 sourceSelect);
  }
  length = _strlen(outText);
  if (sourceModifier != 0) {
    (outText + length)[0] = ')';
    (outText + length)[1] = '\0';
  }
  return;
}

/* FUN_000d183c @ 0xd183c (13160 bytes) */
int FUN_000d183c(pixelShader, dumpLabel, dumpId, argR6, argR7, argR8, argR9, argR10)
  uint *pixelShader;
  uint dumpLabel;
  uint *dumpId;
  char *argR6;
  uint argR7;
  uint *argR8;
  char *argR9;
  byte *argR10;
{
  undefined4 cfNameLength;
  uint psnRecordIndex;
  bool rgbSelectBNotSrcp;
  bool rgbOperandBUsed;
  bool rgbSrcpNeededFlag;
  bool depthWriteFlag2;
  bool rgbSelectCNotSrcp;
  bool rgbOperandCUsed;
  bool texEnableG;
  uint rgbOutputWriteMask;
  char cfAddressByte;
  char rsColorSource;
  char rgbPreOpKind;
  int cfOpTableIndex;
  int rgbDestMaskOffset;
  int instructionNumberArg;
  byte *rgbOpcodePtr;
  byte *predicateControlPtr;
  byte *dySwizzleTextZ;
  char *dySwizzleTextX;
  char *dySwizzleTextW;
  char *dxSwizzleTextX;
  char *dySwizzleTextY;
  char *dxSwizzleTextW;
  char *srcSwizzleTextX;
  char *dxSwizzleTextY;
  char *srcSwizzleTextZ;
  int rsRecordNumber2;
  int rgbThirdOperandUsed;
  uint *semWaitTextPtr;
  uint *alphaOpcodePtr;
  uint *alphaOutIndexArg;
  uint psnRecordKind;
  uint alphaOperandUseMask;
  bool alphaOutputEnableFlag2;
  bool alphaSrcpNeededFlag;
  bool rgbSelectANotSrcp;
  bool rgbOperandAUsed;
  bool texSwizzleEnabled;
  bool texEnableR;
  bool alphaOutputEnableFlag;
  bool alphaSrcpNeededFmt1;
  uint rgbSelectCRaw;
  uint recordKind2;
  uint rsColorWriteMask;
  uint psnRecordCount;
  uint *srcSwizzleTextPtr;
  uint *registerTextPtr;
  uint *rsNextRecordCopy2;
  uint *alphaAddrAFmt1;
  byte predicateModeByteAlpha2;
  byte alphaOutputScaleByte2;
  byte alphaOpcodeByte2;
  byte predicateModeByte2;
  byte rgbOutputScaleByte2;
  byte rgbOpcodeByte2;
  byte rgbTempWriteMask2;
  byte srcpNeedBit;
  byte predicateModeByteAlpha;
  byte predicateModeByte;
  byte texDySwizzleByte;
  byte texDxSwizzleByte;
  byte texOpcodeByte;
  byte texSrcSwizzleByte2;
  byte texSrcSwizzleByte;
  byte texEnableBits;
  byte alphaOutputScaleByte;
  byte alphaOpcodeByte;
  byte rgbOutputScaleByte;
  byte rgbOpcodeByte;
  uint *operandText1Ptr;
  uint *alphaUseBitB;
  uint *operandText5PtrFmt1;
  uint *rgbOutIndexArg;
  uint *operandText5Ptr;
  uint *rgbDestMaskTextPtr;
  uint *aluIndexArg;
  uint *operandText0Ptr;
  uint *operandText4Ptr2;
  uint *neutralLineArg0;
  uint *psnLineArg1;
  uint *alphaSrcpTextPtr;
  uint alphaSelectCBaseArg;
  uint rgbOpcodeBit;
  uint dySwizzleWOffset;
  uint dxSwizzleWOffset;
  uint texComponentEnableBits;
  uint neutralRecordCountArg;
  uint psnLineArg0;
  uint rgbOperandUseMask;
  uint usListStaleZero;
  uint nominalCycleCount;
  uint *alphaAddrA;
  uint *texUnit2;
  uint *texOpcode;
  uint *rgbAddrC;
  uint *rgbAddrB;
  uint *instructionRecord2;
  uint *rsNextRecord2;
  uint *instructionRecord;
  uint *rsNextRecord;
  uint *rsRecord2;
  uint *rsRecord;
  uint *rsScanRecord2;
  uint *rsScanRecord;
  ushort rgbAuxB;
  ushort rgbAuxA;
  uint rgbAddrA;
  uint alphaSelectA;
  uint alphaAuxB;
  uint alphaSelectB2;
  uint texSrcReg;
  uint alphaAuxC;
  uint texDestReg;
  uint alphaSelectB;
  uint alphaSelectC;
  char rgbOutIndex;
  char alphaTempEnable;
  char alphaPreOp;
  bool texEnableA;
  bool depthWriteFlag;
  byte rgbTempWriteMask;
  byte texWriteMask;
  char depthWrite;
  char alphaOutIndex;
  ushort texSrcReg2;
  ushort texDestReg2;
  char levelLetter;
  int auxCheckResult;
  undefined4 operandAuxWord;
  int cfNameCompare;
  uint *dumpIdArg;
  char *maskTextX;
  uint rgbSelectCRawFmt1;
  char *maskTextY;
  uint *aluNumberArg;
  uint rgbOutputMaskText;
  uint dumpLabelArg;
  char *maskTextZ;
  uint *srcpTextAPtr;
  char *maskTextW;
  bool statsLoopMore;
  uint rgbSrcpNeeded;
  byte *dxSwizzleTextZ;
  uint levelNumber;
  uint recordKind;
  uint alphaOpcodeBit;
  uint rgbSelectB;
  uint rgbSelectARaw;
  int statsIndex;
  uint *rgbAddrCFmt1;
  uint *rgbAddrBFmt1;
  uint texUnit;
  uint *rsNextRecordCopy;
  uint rgbAddrA2;
  uint rsRecordNumber;
  undefined **cfOpNameCursor;
  bool texEnableB;
  undefined *cfOpNameEntry;
  uint *statByteCursor;
  double printfResultScratch;
  uint dumpLabelSlot;
  uint *dumpIdSlot;
  undefined2 operandAuxHigh;
  uint *staleStackArg_fffffd2c;
  undefined4 predicateText;
  uint semWaitText;
  char semWaitText4 [4];
  char semWaitText8 [2];
  uint srcpTextA;
  char srcpTextATail [6];
  undefined2 srcpTextB;
  undefined1 srcpTextBPad;
  uint semGrabText;
  char semGrabText4 [4];
  char semGrabText8 [2];
  uint aluWaitText;
  char aluWaitText4 [4];
  char aluWaitText8 [2];
  uint ignUncText;
  char ignUncText4 [4];
  char ignUncText8;
  uint registerText [3];
  uint dxSwizzleTextA [3];
  undefined1 writeMaskText [15];
  uint srcSwizzleText [3];
  uint operandText0 [8];
  uint operandText1 [8];
  uint operandText2 [8];
  uint operandText3 [8];
  uint operandText4 [8];
  uint operandText5 [8];
  uint operandText6 [8];
  uint cfWordText [25];
  int cfIndex;
  int texIndex;
  uint *aluIndex;
  uint cfCompareCode;
  int texNumber;
  uint rgbSelectABase;
  uint rgbSelectBBase;
  uint rgbSelectCBase;
  uint alphaSelectABase;
  uint alphaSelectBBase;
  uint alphaSelectCBase;
  byte *rgbOpcodePtr2;
  uint *alphaOpcodePtr2;
  uint alphaModC;
  uint alphaModB;
  uint alphaModA;
  uint rgbModC;
  uint rgbModB;
  uint rgbModA;
  byte *alphaSelectC2;
  uint previousIsAlu;
  uint *aluNumber;
  uint recordCount;
  uint *alphaAuxD;
  uint alphaUseMaskNeutral;
  uint alphaModC2;
  uint alphaModB2;
  uint alphaModA2;
  uint rgbModC2;
  uint rgbModB2;
  uint rgbModA2;
  uint recordCount2;
  uint texFlagsByte;
  uint cfPrevAluDest;
  int instructionNumber;
  ushort rgbAuxC;
  uint *operandText2Ptr;
  uint *operandText3Ptr;
  uint *operandText4Ptr;
  int blankLineFormatOffset;
  
  dumpLabelSlot = dumpLabel;
  dumpIdSlot = dumpId;
  ((int (*)())psnNormalizeProgram)(pixelShader,1,dumpId,argR6,argR7,argR8,argR9,argR10);
  if ((*(byte *)((int)pixelShader + 0xf) & 0x10) == 0) {
    recordCount = pixelShader[2];
    dumpLabelArg = dumpLabelSlot;
    dumpIdArg = dumpIdSlot;
    ((int (*)())psnReportError)(0,"======== Begin Loki NSF pixel shader dump: %s: %d ========\n",dumpLabelSlot,
                 dumpIdSlot,argR7,argR8,argR9,argR10);
    if (*(short *)(pixelShader + 5) == 0) {
      ((int (*)())psnReportError)(0," Shader stats not valid\n \n",dumpLabelArg,dumpIdArg,argR7,argR8,argR9,argR10);
    }
    else {
      statsIndex = 0;
      ((int (*)())psnReportError)(0," Shader stats:\n",dumpLabelArg,dumpIdArg,argR7,argR8,argR9,argR10);
      ((int (*)())psnReportError)(0,"     Levels:                 %2d\n",(uint)*(ushort *)((int)pixelShader + 0x16),
                   dumpIdArg,argR7,argR8,argR9,argR10);
      ((int (*)())psnReportError)(0,"     RS Instructions:        %2d\n",(uint)*(ushort *)(pixelShader + 6),dumpIdArg,
                   argR7,argR8,argR9,argR10);
      ((int (*)())psnReportError)(0,"     TEX Instructions:      %3d\n",(uint)*(ushort *)((int)pixelShader + 0x1a),
                   dumpIdArg,argR7,argR8,argR9,argR10);
      ((int (*)())psnReportError)(0,"     ALU Instructions:      %3d\n",(uint)*(ushort *)(pixelShader + 7),dumpIdArg,
                   argR7,argR8,argR9,argR10);
      ((int (*)())psnReportError)(0,"     ALU Instruction slots: %3d\n",(uint)*(ushort *)((int)pixelShader + 0x1e),
                   dumpIdArg,argR7,argR8,argR9,argR10);
      ((int (*)())psnReportError)(0,"     Pix Size:               %2d\n",(uint)*(ushort *)((int)pixelShader + 0x22),
                   dumpIdArg,argR7,argR8,argR9,argR10);
      ((int (*)())psnReportError)(0,"     Highest Const:          %2d\n",(uint)*(ushort *)(pixelShader + 9),dumpIdArg,
                   argR7,argR8,argR9,argR10);
      nominalCycleCount = (uint)*(ushort *)((int)pixelShader + 0x26);
      ((int (*)())psnReportError)(0,"     Nominal cycle count:    %2d\n",nominalCycleCount,dumpIdArg,argR7,argR8,argR9,
                   argR10);
      ((int (*)())psnReportError)(0,"     Tex lookup counts:     ",nominalCycleCount,dumpIdArg,argR7,argR8,argR9,argR10);
      statByteCursor = pixelShader;
      do {
        dumpLabelArg = (uint)*(byte *)((int)statByteCursor + 0x2a);
        ((int (*)())psnReportError)(0," %2d",dumpLabelArg,dumpIdArg,argR7,argR8,argR9,argR10);
        statsLoopMore = statsIndex != 0xf;
        statByteCursor = (uint *)((int)statByteCursor + 1);
        statsIndex = statsIndex + 1;
      } while (statsLoopMore);
      ((int (*)())psnReportError)(0,"\n \n",dumpLabelArg,dumpIdArg,argR7,argR8,argR9,argR10);
    }
    ((int (*)())psnReportError)(0," RS Instructions:\n \n",dumpLabelArg,dumpIdArg,argR7,argR8,argR9,argR10);
    if ((pixelShader[0x12] == 1) && (recordCount != 0)) {
      rsScanRecord = pixelShader + 0x24;
      rsRecordNumber = 1;
      rsNextRecord = rsScanRecord;
      rsRecord = pixelShader + 0x12;
      do {
        rsNextRecordCopy = rsNextRecord;
        dumpLabelArg = rsRecordNumber - 1;
        ((int (*)())psnReportError)(0,"   rs %02d:",dumpLabelArg,dumpIdArg,argR7,argR8,argR9,argR10);
        if (*(char *)((int)rsRecord + 0xb) == '\0') {
          if (*(char *)((int)rsRecord + 9) != '\0') {
            ((int (*)())psnReportError)(0,"                         ",dumpLabelArg,dumpIdArg,argR7,argR8,argR9,
                         argR10);
            goto LAB_000d3b80;
          }
LAB_000d3be0:
          ((int (*)())psnReportError)(0,"\n",dumpLabelArg,dumpIdArg,argR7,argR8,argR9,argR10);
        }
        else {
          dumpLabelArg = (uint)*(ushort *)((int)rsRecord + 6);
          argR7 = (uint)*(byte *)((int)rsRecord + 10);
          dumpIdArg = (uint *)((*(byte *)((int)rsRecord + 0xf) & 0xf ^ 0xf) * 5 + 0x1dc279);
          ((int (*)())psnReportError)(0,"  r%02d.%s = col%02ld",dumpLabelArg,dumpIdArg,argR7,argR8,argR9,argR10);
          if (*(char *)((int)rsRecord + 0xd) == '\0') {
            if (*(char *)((int)rsRecord + 0xb) == '\x02') {
              ((int (*)())psnReportError)(0," fbuf  ",dumpLabelArg,dumpIdArg,argR7,argR8,argR9,argR10);
            }
            else if (*(char *)((int)rsRecord + 0xb) == '\x03') {
              ((int (*)())psnReportError)(0," back  ",dumpLabelArg,dumpIdArg,argR7,argR8,argR9,argR10);
            }
            else {
              if (*(char *)((int)rsRecord + 9) == '\0') goto LAB_000d3be0;
              ((int (*)())psnReportError)(0,"       ",dumpLabelArg,dumpIdArg,argR7,argR8,argR9,argR10);
            }
          }
          else {
            ((int (*)())psnReportError)(0," biased",dumpLabelArg,dumpIdArg,argR7,argR8,argR9,argR10);
          }
LAB_000d3b80:
          if (*(char *)((int)rsRecord + 9) == '\0') goto LAB_000d3be0;
          dumpLabelArg = (uint)*(ushort *)(rsRecord + 1);
          argR7 = (uint)*(byte *)(rsRecord + 2);
          dumpIdArg = (uint *)((*(byte *)((int)rsRecord + 0xe) & 0xf ^ 0xf) * 5 + 0x1dc279);
          ((int (*)())psnReportError)(0,"   r%02d.%s = txc%02ld",dumpLabelArg,dumpIdArg,argR7,argR8,argR9,argR10);
          if (*(char *)(rsRecord + 3) == '\0') goto LAB_000d3be0;
          ((int (*)())psnReportError)(0," adjusted\n",dumpLabelArg,dumpIdArg,argR7,argR8,argR9,argR10);
        }
        rsRecordNumber = rsRecordNumber + 1;
        if (*rsScanRecord != 1) break;
        rsScanRecord = rsScanRecord + 0x12;
        rsNextRecord = rsNextRecordCopy + 0x12;
        rsRecord = rsNextRecordCopy;
      } while (rsRecordNumber <= recordCount);
    }
    else {
      rsRecordNumber = 1;
    }
    ((int (*)())psnReportError)(0," \n US Program:\n",dumpLabelArg,dumpIdArg,argR7,argR8,argR9,argR10);
    if (rsRecordNumber <= recordCount) {
      levelNumber = 0;
      instructionRecord = pixelShader + rsRecordNumber * 0x12;
      previousIsAlu = 1;
      aluNumber = (uint *)0x0;
      texNumber = 0;
      usListStaleZero = 0;
      do {
        recordKind = *instructionRecord;
        if (((recordKind == 2) && ((previousIsAlu != 0 || (*(char *)(instructionRecord + 8) != '\0')))) ||
           (levelNumber == 0)) {
          if (levelNumber < 0x34) {
            (*(unsigned short *)((unsigned char *)&(predicateText) + 1)) = (ushort)(*(unsigned int *)((unsigned char *)&(predicateText) + 0)) & 0xff;
          }
          else {
            (*(unsigned short *)((unsigned char *)&(predicateText) + 1)) = (ushort)(byte)((char)(levelNumber / 0x34) + 0x2f) << 8;
          }
          levelLetter = (char)(levelNumber % 0x34);
          if (levelNumber % 0x34 < 0x1a) {
            levelLetter = levelLetter + 'A';
          }
          else {
            levelLetter = levelLetter + 'G';
          }
          (*(unsigned int *)((unsigned char *)&(predicateText) + 0)) = CONCAT12(levelLetter,(*(unsigned short *)((unsigned char *)&(predicateText) + 1)));
          ((int (*)())psnReportError)(0," \n   Level %s:\n",&predicateText,dumpIdArg,usListStaleZero,argR8,argR9,argR10);
          levelNumber = levelNumber + 1;
          recordKind = *instructionRecord;
        }
        previousIsAlu = (uint)(recordKind - 3 < 2);
        if (recordKind == 2) {
          ((int (*)())psnReportError)(0,"     tex %02d    :  ",texNumber,dumpIdArg,usListStaleZero,argR8,argR9,argR10);
          texSrcReg = (uint)*(ushort *)((int)instructionRecord + 0xe);
          texDestReg = (uint)*(ushort *)(instructionRecord + 3);
          texUnit = (uint)*(byte *)((int)instructionRecord + 0x19);
          if ((*(byte *)((int)instructionRecord + 0x1a) < 5) &&
             ((1 << ((int)(char)*(byte *)((int)instructionRecord + 0x1a) & 0x3fU) & 0x1aU) != 0)) {
            ((int (*)())psnReportError)(0,"r%02d.rgba = ",texDestReg,dumpIdArg,usListStaleZero,argR8,argR9,argR10);
          }
          texOpcode = (uint *)(uint)*(byte *)((int)instructionRecord + 0x1a);
          dumpIdArg = (uint *)(*(byte *)((int)instructionRecord + 0x1f) & 0xf ^ 0xf);
          if (((unsigned char *)0x4) < texOpcode) {
            ((int (*)())psnReportError)(0,"???()\n",texDestReg,dumpIdArg,usListStaleZero,argR8,texOpcode,argR10);
            argR9 = (char *)texOpcode;
          }
          else {
            argR9 = (char *)(0);
            switch((int)texOpcode) {
            case 0x0:
              ((int (*)())psnReportError)(0,"NOP\n",texDestReg,dumpIdArg,usListStaleZero,argR8,argR9,argR10);
              break;
            case 0x1:
              dumpIdArg = (uint *)((int)dumpIdArg * 5 + 0x1dc279);
              ((int (*)())psnReportError)(0,"lookup(r%02d.%s, tex%02d)\n",texSrcReg,dumpIdArg,texUnit,argR8,argR9,
                           argR10);
              break;
            case 0x2:
              dumpIdArg = (uint *)((int)dumpIdArg * 5 + 0x1dc279);
              ((int (*)())psnReportError)(0,"kill(r%02d.%s)\n",texSrcReg,dumpIdArg,usListStaleZero,argR8,argR9,argR10);
              break;
            case 0x3:
              dumpIdArg = (uint *)((int)dumpIdArg * 5 + 0x1dc279);
              ((int (*)())psnReportError)(0,"lookup_proj(r%02d.%s, tex%02d)\n",texSrcReg,dumpIdArg,texUnit,argR8,
                           argR9,argR10);
              break;
            case 0x4:
              dumpIdArg = (uint *)((int)dumpIdArg * 5 + 0x1dc279);
              ((int (*)())psnReportError)(0,"lookup_lodbias(r%02d.%s, tex%02d)\n",texSrcReg,dumpIdArg,texUnit,argR8,
                           argR9,argR10);
            }
          }
          texNumber = texNumber + 1;
        }
        else if ((1 < recordKind) && (recordKind < 5)) {
          rgbOpcodePtr2 = (byte *)((int)instructionRecord + 0x31);
          switch(*(undefined1 *)((int)instructionRecord + 0x31)) {
          case 0:
          case 3:
          case 7:
          case 8:
            alphaOperandUseMask = 0;
            alphaSrcpNeededFmt1 = true;
            rgbOperandUseMask = 3;
            rgbThirdOperandUsed = 1;
            break;
          case 1:
          case 4:
          case 5:
            alphaOperandUseMask = 0;
            alphaSrcpNeededFmt1 = true;
            rgbOperandUseMask = 1;
            rgbThirdOperandUsed = 0;
            break;
          case 2:
            alphaOperandUseMask = 3;
            alphaSrcpNeededFmt1 = true;
            rgbOperandUseMask = 1;
            rgbThirdOperandUsed = 0;
            break;
          default:
            alphaOperandUseMask = 0;
            alphaSrcpNeededFmt1 = false;
            rgbOperandUseMask = 0;
            rgbThirdOperandUsed = 0;
            break;
          case 9:
            alphaOperandUseMask = 0;
            alphaSrcpNeededFmt1 = true;
            rgbOperandUseMask = 0;
            rgbThirdOperandUsed = 0;
          }
          alphaOpcodePtr2 = instructionRecord + 0x10;
          if (*(byte *)(instructionRecord + 0x10) < 0xc) {
            alphaOpcodeBit = 1 << ((int)(char)*(byte *)(instructionRecord + 0x10) & 0x3fU);
            if ((alphaOpcodeBit & 0x61) == 0) {
              if ((alphaOpcodeBit & 0xc) == 0) {
                if ((alphaOpcodeBit & 0xf80) != 0) {
                  alphaOperandUseMask = alphaOperandUseMask | 1;
                }
              }
              else {
                alphaOperandUseMask = 3;
              }
            }
            else {
              alphaOperandUseMask = 7;
            }
          }
          alphaSelectC2 = (byte *)(uint)*(byte *)((int)instructionRecord + 0x3b);
          rgbAddrA2 = (uint)*(ushort *)((int)instructionRecord + 0xe);
          rgbAddrBFmt1 = (uint *)(uint)*(ushort *)(instructionRecord + 4);
          rgbAddrCFmt1 = (uint *)(uint)*(ushort *)((int)instructionRecord + 0x12);
          alphaAddrAFmt1 = (uint *)(uint)*(ushort *)((int)instructionRecord + 0x1a);
          argR8 = (uint *)(uint)*(ushort *)(instructionRecord + 7);
          argR9 = (char *)(uint)*(ushort *)((int)instructionRecord + 0x1e);
          rgbSelectARaw = (uint)*(byte *)((int)instructionRecord + 0x2a);
          rgbSelectB = (uint)*(byte *)((int)instructionRecord + 0x2b);
          rgbSelectCRawFmt1 = (uint)*(byte *)(instructionRecord + 0xb);
          alphaSelectA = (uint)*(byte *)((int)instructionRecord + 0x39);
          alphaSelectB2 = (uint)*(byte *)((int)instructionRecord + 0x3a);
          rgbModA = (uint)*(byte *)((int)instructionRecord + 0x2d);
          rgbModB = (uint)*(byte *)((int)instructionRecord + 0x2e);
          rgbModC = (uint)*(byte *)((int)instructionRecord + 0x2f);
          alphaModA = (uint)*(byte *)(instructionRecord + 0xf);
          alphaModB = (uint)*(byte *)((int)instructionRecord + 0x3d);
          alphaModC = (uint)*(byte *)((int)instructionRecord + 0x3e);
          if (alphaSrcpNeededFmt1) {
            rgbSrcpNeeded = (uint)(rgbSelectARaw - 0xf < 4);
          }
          else {
            rgbSrcpNeeded = 0;
          }
          alphaSrcpNeededFmt1 = alphaSrcpNeededFmt1 && rgbSelectARaw == 0x13;
          rgbOperandUseMask = rgbOperandUseMask & 1;
          if (rgbOperandUseMask != 0) {
            rgbSrcpNeeded = rgbSrcpNeeded | rgbSelectB - 0xf < 4;
            alphaSrcpNeededFmt1 = alphaSrcpNeededFmt1 || rgbSelectB == 0x13;
          }
          if (rgbThirdOperandUsed != 0) {
            rgbOperandUseMask = -(rgbSelectCRawFmt1 ^ 0x13);
            rgbSrcpNeeded = rgbSrcpNeeded | rgbSelectCRawFmt1 - 0xf < 4;
            alphaSrcpNeededFmt1 = (bool)(alphaSrcpNeededFmt1 | (rgbSelectCRawFmt1 ^ 0x13) == 0);
          }
          if ((alphaOperandUseMask & 1) != 0) {
            rgbOperandUseMask = -(alphaSelectA ^ 0xf);
            rgbSrcpNeeded = rgbSrcpNeeded | alphaSelectA - 0xc < 3;
            alphaSrcpNeededFmt1 = (bool)(alphaSrcpNeededFmt1 | (alphaSelectA ^ 0xf) == 0);
          }
          if ((alphaOperandUseMask & 2) != 0) {
            rgbOperandUseMask = -(alphaSelectB2 ^ 0xf);
            rgbSrcpNeeded = rgbSrcpNeeded | alphaSelectB2 - 0xc < 3;
            alphaSrcpNeededFmt1 = (bool)(alphaSrcpNeededFmt1 | (alphaSelectB2 ^ 0xf) == 0);
          }
          if ((alphaOperandUseMask & 4) != 0) {
            rgbOperandUseMask = -((uint)alphaSelectC2 ^ 0xf);
            rgbSrcpNeeded = rgbSrcpNeeded | alphaSelectC2 + -0xc < (byte *)((int)((unsigned char *)0x0) + 3);
            alphaSrcpNeededFmt1 = (bool)(alphaSrcpNeededFmt1 | ((uint)alphaSelectC2 ^ 0xf) == 0);
          }
          srcpTextAPtr = dumpIdArg;
          if (rgbSrcpNeeded != 0) {
            aluNumberArg = aluNumber;
            ((int (*)())psnReportError)(0,"     alu %02d pre:  srcp.rgb = ",aluNumber,dumpIdArg,rgbOperandUseMask,alphaOperandUseMask,rgbSrcpNeeded,
                         rgbThirdOperandUsed);
            rgbPreOpKind = *(char *)(instructionRecord + 0xc);
            if (rgbPreOpKind == '\x01') {
              srcpTextAPtr = &srcpTextA;
              ((int (*)())psnFormatRegister)(srcpTextAPtr,rgbAddrA2,aluNumberArg,dumpIdArg,rgbOperandUseMask,alphaOperandUseMask,rgbSrcpNeeded);
              ((int (*)())psnFormatRegister)(&srcpTextB,rgbAddrBFmt1,aluNumberArg,dumpIdArg,rgbOperandUseMask,alphaOperandUseMask,rgbSrcpNeeded);
              ((int (*)())psnReportError)(0,"%s.rgb-%s.rgb\n",&srcpTextB,srcpTextAPtr,rgbOperandUseMask,alphaOperandUseMask,rgbSrcpNeeded,rgbThirdOperandUsed);
            }
            else if (rgbPreOpKind == '\0') {
              ((int (*)())psnFormatRegister)(&srcpTextA,rgbAddrA2,aluNumberArg,dumpIdArg,rgbOperandUseMask,alphaOperandUseMask,rgbSrcpNeeded);
              ((int (*)())psnReportError)(0,"1.0-2.0*%s.rgb\n",&srcpTextA,dumpIdArg,rgbOperandUseMask,alphaOperandUseMask,rgbSrcpNeeded,rgbThirdOperandUsed);
              srcpTextAPtr = dumpIdArg;
            }
            else if (rgbPreOpKind == '\x02') {
              srcpTextAPtr = &srcpTextA;
              ((int (*)())psnFormatRegister)(srcpTextAPtr,rgbAddrA2,aluNumberArg,dumpIdArg,rgbOperandUseMask,alphaOperandUseMask,rgbSrcpNeeded);
              ((int (*)())psnFormatRegister)(&srcpTextB,rgbAddrBFmt1,aluNumberArg,dumpIdArg,rgbOperandUseMask,alphaOperandUseMask,rgbSrcpNeeded);
              ((int (*)())psnReportError)(0,"%s.rgb+%s.rgb\n",&srcpTextB,srcpTextAPtr,rgbOperandUseMask,alphaOperandUseMask,rgbSrcpNeeded,rgbThirdOperandUsed);
            }
            else if (rgbPreOpKind == '\x03') {
              ((int (*)())psnFormatRegister)(&srcpTextA,rgbAddrA2,aluNumberArg,dumpIdArg,rgbOperandUseMask,alphaOperandUseMask,rgbSrcpNeeded);
              ((int (*)())psnReportError)(0,"1.0-%s.rgb\n",&srcpTextA,dumpIdArg,rgbOperandUseMask,alphaOperandUseMask,rgbSrcpNeeded,rgbThirdOperandUsed);
              srcpTextAPtr = dumpIdArg;
            }
            else {
              ((int (*)())psnReportError)(0,"???\n",aluNumberArg,dumpIdArg,rgbOperandUseMask,alphaOperandUseMask,rgbSrcpNeeded,rgbThirdOperandUsed);
              srcpTextAPtr = dumpIdArg;
            }
          }
          alphaSrcpTextPtr = srcpTextAPtr;
          if (alphaSrcpNeededFmt1) {
            aluNumberArg = aluNumber;
            ((int (*)())psnReportError)(0,"     alu %02d pre:  srcp.a   = ",aluNumber,srcpTextAPtr,rgbOperandUseMask,alphaOperandUseMask,rgbSrcpNeeded,
                         rgbThirdOperandUsed);
            alphaPreOp = *(char *)((int)instructionRecord + 0x3f);
            if (alphaPreOp == '\x01') {
              alphaSrcpTextPtr = &srcpTextA;
              ((int (*)())psnFormatRegister)(alphaSrcpTextPtr,alphaAddrAFmt1,aluNumberArg,srcpTextAPtr,rgbOperandUseMask,alphaOperandUseMask,rgbSrcpNeeded);
              ((int (*)())psnFormatRegister)(&srcpTextB,argR8,aluNumberArg,srcpTextAPtr,rgbOperandUseMask,alphaOperandUseMask,rgbSrcpNeeded);
              ((int (*)())psnReportError)(0,"%s.a-%s.a\n",&srcpTextB,alphaSrcpTextPtr,rgbOperandUseMask,alphaOperandUseMask,rgbSrcpNeeded,rgbThirdOperandUsed);
            }
            else if (alphaPreOp == '\0') {
              ((int (*)())psnFormatRegister)(&srcpTextA,alphaAddrAFmt1,aluNumberArg,srcpTextAPtr,rgbOperandUseMask,alphaOperandUseMask,rgbSrcpNeeded);
              ((int (*)())psnReportError)(0,"1.0-2.0*%s.a\n",&srcpTextA,srcpTextAPtr,rgbOperandUseMask,alphaOperandUseMask,rgbSrcpNeeded,rgbThirdOperandUsed);
              alphaSrcpTextPtr = srcpTextAPtr;
            }
            else if (alphaPreOp == '\x02') {
              alphaSrcpTextPtr = &srcpTextA;
              ((int (*)())psnFormatRegister)(alphaSrcpTextPtr,alphaAddrAFmt1,aluNumberArg,srcpTextAPtr,rgbOperandUseMask,alphaOperandUseMask,rgbSrcpNeeded);
              ((int (*)())psnFormatRegister)(&srcpTextB,argR8,aluNumberArg,srcpTextAPtr,rgbOperandUseMask,alphaOperandUseMask,rgbSrcpNeeded);
              ((int (*)())psnReportError)(0,"%s.a+%s.a\n",&srcpTextB,alphaSrcpTextPtr,rgbOperandUseMask,alphaOperandUseMask,rgbSrcpNeeded,rgbThirdOperandUsed);
            }
            else if (alphaPreOp == '\x03') {
              ((int (*)())psnFormatRegister)(&srcpTextA,alphaAddrAFmt1,aluNumberArg,srcpTextAPtr,rgbOperandUseMask,alphaOperandUseMask,rgbSrcpNeeded);
              ((int (*)())psnReportError)(0,"1.0-%s.a\n",&srcpTextA,srcpTextAPtr,rgbOperandUseMask,alphaOperandUseMask,rgbSrcpNeeded,rgbThirdOperandUsed);
              alphaSrcpTextPtr = srcpTextAPtr;
            }
            else {
              ((int (*)())psnReportError)(0,"???\n",aluNumberArg,srcpTextAPtr,rgbOperandUseMask,alphaOperandUseMask,rgbSrcpNeeded,rgbThirdOperandUsed);
              alphaSrcpTextPtr = srcpTextAPtr;
            }
          }
          rgbOutIndexArg = aluNumber;
          ((int (*)())psnReportError)(0,"     alu %02d rgb:  ",aluNumber,alphaSrcpTextPtr,rgbOperandUseMask,alphaOperandUseMask,rgbSrcpNeeded,rgbThirdOperandUsed);
          rgbOutputMaskText = (uint)*(byte *)((int)instructionRecord + 0x15);
          rgbTempWriteMask = *(byte *)(instructionRecord + 5);
          if (rgbOutputMaskText == 0) {
            ((int (*)())psnReportError)(0,"           ",rgbOutIndexArg,0,rgbOperandUseMask,alphaOperandUseMask,rgbSrcpNeeded,rgbThirdOperandUsed);
          }
          else {
            rgbOutIndexArg = (uint *)(uint)*(byte *)((int)instructionRecord + 0x16);
            rgbOutputMaskText = rgbOutputMaskText * 4 + 0x1dc239;
            ((int (*)())psnReportError)(0,"out%d.%s = ",rgbOutIndexArg,rgbOutputMaskText,rgbOperandUseMask,alphaOperandUseMask,rgbSrcpNeeded,rgbThirdOperandUsed);
          }
          if (rgbTempWriteMask == 0) {
            ((int (*)())psnReportError)(0,"          ",rgbOutIndexArg,rgbOutputMaskText,rgbOperandUseMask,alphaOperandUseMask,rgbSrcpNeeded,rgbThirdOperandUsed);
          }
          else {
            rgbOutIndexArg = (uint *)(uint)*(ushort *)(instructionRecord + 3);
            rgbOutputMaskText = (uint)rgbTempWriteMask * 4 + 0x1dc239;
            ((int (*)())psnReportError)(0,"r%02d.%s = ",rgbOutIndexArg,rgbOutputMaskText,rgbOperandUseMask,alphaOperandUseMask,rgbSrcpNeeded,rgbThirdOperandUsed);
          }
          if (*(char *)((int)instructionRecord + 0x33) != '\0') {
            ((int (*)())psnReportError)(0,"clamped ",rgbOutIndexArg,rgbOutputMaskText,rgbOperandUseMask,alphaOperandUseMask,rgbSrcpNeeded,rgbThirdOperandUsed);
          }
          operandText2Ptr = operandText2;
          operandText3Ptr = operandText3;
          ((int (*)())psnFormatRgbSource)(operandText2Ptr,rgbAddrA2,rgbAddrBFmt1,rgbAddrCFmt1,alphaAddrAFmt1,argR8,argR9,rgbSelectARaw,rgbModA);
          operandText4Ptr = operandText4;
          operandText5PtrFmt1 = operandText5;
          ((int (*)())psnFormatRgbSource)(operandText3Ptr,rgbAddrA2,rgbAddrBFmt1,rgbAddrCFmt1,alphaAddrAFmt1,argR8,argR9,rgbSelectB,rgbModB);
          ((int (*)())psnFormatRgbSource)(operandText4Ptr,rgbAddrA2,rgbAddrBFmt1,rgbAddrCFmt1,alphaAddrAFmt1,argR8,argR9,rgbSelectCRawFmt1,rgbModC);
          dumpIdArg = operandText6;
          ((int (*)())psnFormatAlphaSource)(operandText5PtrFmt1,rgbAddrA2,rgbAddrBFmt1,rgbAddrCFmt1,alphaAddrAFmt1,argR8,argR9,alphaSelectA,alphaModA);
          operandText0Ptr = operandText0;
          ((int (*)())psnFormatAlphaSource)(dumpIdArg,rgbAddrA2,rgbAddrBFmt1,rgbAddrCFmt1,alphaAddrAFmt1,argR8,argR9,alphaSelectB2,alphaModB);
          argR10 = alphaSelectC2;
          ((int (*)())psnFormatAlphaSource)(operandText0Ptr,rgbAddrA2,rgbAddrBFmt1,rgbAddrCFmt1,alphaAddrAFmt1,argR8,argR9,alphaSelectC2,alphaModC);
          rgbOpcodeByte = *rgbOpcodePtr2;
          if (rgbOpcodeByte < 0xb) {
            argR9 = (char *)(0);
            switch(rgbOpcodeByte) {
            case 0:
              rgbAddrBFmt1 = operandText2Ptr;
              rgbAddrCFmt1 = operandText3Ptr;
              alphaAddrAFmt1 = operandText4Ptr;
              ((int (*)())psnReportError)(0,"mad(%s, %s, %s)",operandText2Ptr,operandText3Ptr,operandText4Ptr,argR8,argR9,argR10);
              break;
            case 1:
              rgbAddrBFmt1 = operandText2Ptr;
              rgbAddrCFmt1 = operandText3Ptr;
              ((int (*)())psnReportError)(0,"dp3(%s, %s)",operandText2Ptr,operandText3Ptr,alphaAddrAFmt1,argR8,argR9,argR10);
              break;
            case 2:
              rgbAddrBFmt1 = operandText2Ptr;
              rgbAddrCFmt1 = operandText5PtrFmt1;
              alphaAddrAFmt1 = operandText3Ptr;
              argR8 = dumpIdArg;
              ((int (*)())psnReportError)(0,"dp4(%s:%s, %s:%s)",operandText2Ptr,operandText5PtrFmt1,operandText3Ptr,dumpIdArg,argR9,argR10);
              break;
            case 3:
              rgbAddrBFmt1 = operandText2Ptr;
              rgbAddrCFmt1 = operandText3Ptr;
              alphaAddrAFmt1 = operandText4Ptr;
              ((int (*)())psnReportError)(0,"d2a(%s, %s, %s)",operandText2Ptr,operandText3Ptr,operandText4Ptr,argR8,argR9,argR10);
              break;
            case 4:
              rgbAddrBFmt1 = operandText2Ptr;
              rgbAddrCFmt1 = operandText3Ptr;
              ((int (*)())psnReportError)(0,"min(%s, %s)",operandText2Ptr,operandText3Ptr,alphaAddrAFmt1,argR8,argR9,argR10);
              break;
            case 5:
              rgbAddrBFmt1 = operandText2Ptr;
              rgbAddrCFmt1 = operandText3Ptr;
              ((int (*)())psnReportError)(0,"max(%s, %s)",operandText2Ptr,operandText3Ptr,alphaAddrAFmt1,argR8,argR9,argR10);
              break;
            case 6:
              goto switchD_000d4578_caseD_6;
            case 7:
              rgbAddrBFmt1 = operandText2Ptr;
              rgbAddrCFmt1 = operandText3Ptr;
              alphaAddrAFmt1 = operandText4Ptr;
              ((int (*)())psnReportError)(0,"cnd(%s, %s, %s)",operandText2Ptr,operandText3Ptr,operandText4Ptr,argR8,argR9,argR10);
              break;
            case 8:
              rgbAddrBFmt1 = operandText2Ptr;
              rgbAddrCFmt1 = operandText3Ptr;
              alphaAddrAFmt1 = operandText4Ptr;
              ((int (*)())psnReportError)(0,"cmp(%s, %s, %s)",operandText2Ptr,operandText3Ptr,operandText4Ptr,argR8,argR9,argR10);
              break;
            case 9:
              rgbAddrBFmt1 = operandText2Ptr;
              ((int (*)())psnReportError)(0,"frc(%s)",operandText2Ptr,rgbAddrCFmt1,alphaAddrAFmt1,argR8,argR9,argR10);
              break;
            case 10:
              ((int (*)())psnReportError)(0,"sop()",rgbAddrBFmt1,rgbAddrCFmt1,alphaAddrAFmt1,argR8,argR9,argR10);
            }
          }
          else {
switchD_000d4578_caseD_6:
            ((int (*)())psnReportError)(0,"???()",rgbAddrBFmt1,rgbAddrCFmt1,alphaAddrAFmt1,argR8,argR9,argR10);
          }
          rgbOutputScaleByte = *(byte *)((int)instructionRecord + 0x32);
          if (rgbOutputScaleByte < 7) {
            argR9 = (char *)(0);
            switch(rgbOutputScaleByte) {
            case 0:
              ((int (*)())psnReportError)(0,"\n",rgbAddrBFmt1,rgbAddrCFmt1,alphaAddrAFmt1,argR8,argR9,argR10);
              break;
            case 1:
              ((int (*)())psnReportError)(0,"*2\n",rgbAddrBFmt1,rgbAddrCFmt1,alphaAddrAFmt1,argR8,argR9,argR10);
              break;
            case 2:
              ((int (*)())psnReportError)(0,"*4\n",rgbAddrBFmt1,rgbAddrCFmt1,alphaAddrAFmt1,argR8,argR9,argR10);
              break;
            case 3:
              ((int (*)())psnReportError)(0,"*8\n",rgbAddrBFmt1,rgbAddrCFmt1,alphaAddrAFmt1,argR8,argR9,argR10);
              break;
            case 4:
              ((int (*)())psnReportError)(0,"/2\n",rgbAddrBFmt1,rgbAddrCFmt1,alphaAddrAFmt1,argR8,argR9,argR10);
              break;
            case 5:
              ((int (*)())psnReportError)(0,"/4\n",rgbAddrBFmt1,rgbAddrCFmt1,alphaAddrAFmt1,argR8,argR9,argR10);
              break;
            case 6:
              ((int (*)())psnReportError)(0,"/8\n",rgbAddrBFmt1,rgbAddrCFmt1,alphaAddrAFmt1,argR8,argR9,argR10);
            }
          }
          else {
            ((int (*)())psnReportError)(0,"*???\n",rgbAddrBFmt1,rgbAddrCFmt1,alphaAddrAFmt1,argR8,argR9,argR10);
          }
          alphaOutIndexArg = aluNumber;
          ((int (*)())psnReportError)(0,"          alpha:  ",aluNumber,rgbAddrCFmt1,alphaAddrAFmt1,argR8,argR9,argR10);
          alphaTempEnable = *(char *)(instructionRecord + 8);
          alphaOutputEnableFlag = *(char *)((int)instructionRecord + 0x21) != '\0';
          depthWrite = *(char *)((int)instructionRecord + 0x23);
          if (alphaOutputEnableFlag) {
            alphaOutIndexArg = (uint *)(uint)*(byte *)((int)instructionRecord + 0x22);
            ((int (*)())psnReportError)(0,"out%d.a   = ",alphaOutIndexArg,rgbAddrCFmt1,alphaAddrAFmt1,argR8,argR9,argR10);
          }
          depthWriteFlag = depthWrite != '\0';
          if (depthWriteFlag) {
            ((int (*)())psnReportError)(0,"depth    = ",alphaOutIndexArg,rgbAddrCFmt1,alphaAddrAFmt1,argR8,argR9,argR10);
          }
          if ((!alphaOutputEnableFlag) && (!depthWriteFlag)) {
            ((int (*)())psnReportError)(0,"           ",alphaOutIndexArg,rgbAddrCFmt1,alphaAddrAFmt1,argR8,argR9,argR10);
          }
          if (alphaTempEnable == '\0') {
            ((int (*)())psnReportError)(0,"          ",alphaOutIndexArg,rgbAddrCFmt1,alphaAddrAFmt1,argR8,argR9,argR10);
          }
          else {
            alphaOutIndexArg = (uint *)(uint)*(ushort *)(instructionRecord + 6);
            ((int (*)())psnReportError)(0,"r%02d.a   = ",alphaOutIndexArg,rgbAddrCFmt1,alphaAddrAFmt1,argR8,argR9,argR10);
          }
          if (*(char *)((int)instructionRecord + 0x42) != '\0') {
            ((int (*)())psnReportError)(0,"clamped ",alphaOutIndexArg,rgbAddrCFmt1,alphaAddrAFmt1,argR8,argR9,argR10);
          }
          alphaOpcodeByte = *(byte *)alphaOpcodePtr2;
          if (alphaOpcodeByte < 0xc) {
            argR9 = (char *)(0);
            switch(alphaOpcodeByte) {
            case 0:
              ((int (*)())psnReportError)(0,"mad(%s, %s, %s)",operandText5PtrFmt1,dumpIdArg,operandText0Ptr,argR8,argR9,argR10);
              break;
            case 1:
              ((int (*)())psnReportError)(0,"dp()",alphaOutIndexArg,rgbAddrCFmt1,alphaAddrAFmt1,argR8,argR9,argR10);
              operandText5PtrFmt1 = alphaOutIndexArg;
              dumpIdArg = rgbAddrCFmt1;
              operandText0Ptr = alphaAddrAFmt1;
              break;
            case 2:
              ((int (*)())psnReportError)(0,"min(%s, %s)",operandText5PtrFmt1,dumpIdArg,alphaAddrAFmt1,argR8,argR9,argR10);
              operandText0Ptr = alphaAddrAFmt1;
              break;
            case 3:
              ((int (*)())psnReportError)(0,"max(%s, %s)",operandText5PtrFmt1,dumpIdArg,alphaAddrAFmt1,argR8,argR9,argR10);
              operandText0Ptr = alphaAddrAFmt1;
              break;
            case 4:
              goto switchD_000d489c_caseD_4;
            case 5:
              ((int (*)())psnReportError)(0,"cnd(%s, %s, %s)",operandText5PtrFmt1,dumpIdArg,operandText0Ptr,argR8,argR9,argR10);
              break;
            case 6:
              ((int (*)())psnReportError)(0,"cmp(%s, %s, %s)",operandText5PtrFmt1,dumpIdArg,operandText0Ptr,argR8,argR9,argR10);
              break;
            case 7:
              ((int (*)())psnReportError)(0,"frc(%s)",operandText5PtrFmt1,rgbAddrCFmt1,alphaAddrAFmt1,argR8,argR9,argR10);
              dumpIdArg = rgbAddrCFmt1;
              operandText0Ptr = alphaAddrAFmt1;
              break;
            case 8:
              ((int (*)())psnReportError)(0,"ex2(%s)",operandText5PtrFmt1,rgbAddrCFmt1,alphaAddrAFmt1,argR8,argR9,argR10);
              dumpIdArg = rgbAddrCFmt1;
              operandText0Ptr = alphaAddrAFmt1;
              break;
            case 9:
              ((int (*)())psnReportError)(0,"ln2(%s)",operandText5PtrFmt1,rgbAddrCFmt1,alphaAddrAFmt1,argR8,argR9,argR10);
              dumpIdArg = rgbAddrCFmt1;
              operandText0Ptr = alphaAddrAFmt1;
              break;
            case 10:
              ((int (*)())psnReportError)(0,"rcp(%s)",operandText5PtrFmt1,rgbAddrCFmt1,alphaAddrAFmt1,argR8,argR9,argR10);
              dumpIdArg = rgbAddrCFmt1;
              operandText0Ptr = alphaAddrAFmt1;
              break;
            case 0xb:
              ((int (*)())psnReportError)(0,"rsq(%s)",operandText5PtrFmt1,rgbAddrCFmt1,alphaAddrAFmt1,argR8,argR9,argR10);
              dumpIdArg = rgbAddrCFmt1;
              operandText0Ptr = alphaAddrAFmt1;
            }
          }
          else {
switchD_000d489c_caseD_4:
            ((int (*)())psnReportError)(0,"???()",alphaOutIndexArg,rgbAddrCFmt1,alphaAddrAFmt1,argR8,argR9,argR10);
            operandText5PtrFmt1 = alphaOutIndexArg;
            dumpIdArg = rgbAddrCFmt1;
            operandText0Ptr = alphaAddrAFmt1;
          }
          alphaOutputScaleByte = *(byte *)((int)instructionRecord + 0x41);
          if (alphaOutputScaleByte < 7) {
            argR9 = (char *)(0);
            switch(alphaOutputScaleByte) {
            case 0:
              ((int (*)())psnReportError)(0,"\n",operandText5PtrFmt1,dumpIdArg,operandText0Ptr,argR8,argR9,argR10);
              break;
            case 1:
              ((int (*)())psnReportError)(0,"*2\n",operandText5PtrFmt1,dumpIdArg,operandText0Ptr,argR8,argR9,argR10);
              break;
            case 2:
              ((int (*)())psnReportError)(0,"*4\n",operandText5PtrFmt1,dumpIdArg,operandText0Ptr,argR8,argR9,argR10);
              break;
            case 3:
              ((int (*)())psnReportError)(0,"*8\n",operandText5PtrFmt1,dumpIdArg,operandText0Ptr,argR8,argR9,argR10);
              break;
            case 4:
              ((int (*)())psnReportError)(0,"/2\n",operandText5PtrFmt1,dumpIdArg,operandText0Ptr,argR8,argR9,argR10);
              break;
            case 5:
              ((int (*)())psnReportError)(0,"/4\n",operandText5PtrFmt1,dumpIdArg,operandText0Ptr,argR8,argR9,argR10);
              break;
            case 6:
              ((int (*)())psnReportError)(0,"/8\n",operandText5PtrFmt1,dumpIdArg,operandText0Ptr,argR8,argR9,argR10);
            }
          }
          else {
            ((int (*)())psnReportError)(0,"*???\n",operandText5PtrFmt1,dumpIdArg,operandText0Ptr,argR8,argR9,argR10);
          }
          if (*(char *)(instructionRecord + 0xd) != '\0') {
            ((int (*)())psnReportError)(0,"     alu %02d post-NOP\n",aluNumber,dumpIdArg,operandText0Ptr,argR8,argR9,
                         argR10);
          }
          aluNumber = (uint *)((int)aluNumber + 1);
        }
        rsRecordNumber = rsRecordNumber + 1;
        instructionRecord = instructionRecord + 0x12;
        argR7 = recordCount;
        usListStaleZero = recordCount;
      } while (rsRecordNumber <= recordCount);
    }
    psnRecordIndex = 0;
    ((int (*)())psnReportError)(0,"======== End   Loki NSF pixel shader dump: %s: %d ========\n",dumpLabelSlot,
                 dumpIdSlot,argR7,argR8,argR9,argR10);
    psnRecordCount = pixelShader[2];
    psnLineArg0 = dumpLabelSlot;
    psnLineArg1 = dumpIdSlot;
    ((int (*)())psnReportError)(0,"+++ BEGIN_PSN                       # \"%s\" %d\n",dumpLabelSlot,
                 dumpIdSlot,argR7,argR8,argR9,argR10);
    do {
      psnRecordKind = *pixelShader;
      if (psnRecordKind < 5) {
        switch(psnRecordKind) {
        case 0:
          psnLineArg0 = pixelShader[1];
          psnLineArg1 = (uint *)pixelShader[2];
          argR7 = (uint)*(byte *)(pixelShader + 3);
          argR8 = (uint *)(uint)*(byte *)((int)pixelShader + 0xd);
          argR9 = (char *)(uint)*(ushort *)(pixelShader + 5);
          argR10 = (byte *)(uint)*(ushort *)((int)pixelShader + 0x16);
          ((int (*)())psnReportError)(0,
                       "+++ R300PSN_INST_HEADER : %08x %08x %02x %02x %04x %04x %04x %04x %04x %04x %04x\n"
                       ,psnLineArg0,psnLineArg1,argR7,argR8,argR9,argR10);
          break;
        case 1:
          psnLineArg0 = (uint)*(ushort *)(pixelShader + 1);
          psnLineArg1 = (uint *)(uint)*(ushort *)((int)pixelShader + 6);
          argR7 = (uint)*(byte *)(pixelShader + 2);
          argR8 = (uint *)(uint)*(byte *)((int)pixelShader + 9);
          argR9 = (char *)(uint)*(byte *)((int)pixelShader + 10);
          argR10 = (byte *)(uint)*(byte *)((int)pixelShader + 0xb);
          ((int (*)())psnReportError)(0,
                       "+++ R300PSN_INST_RS     : %04x %04x %02x %02x %02x %02x %02x %02x %02x %02x\n"
                       ,psnLineArg0,psnLineArg1,argR7,argR8,argR9,argR10);
          break;
        case 2:
          psnLineArg0 = (uint)*(ushort *)(pixelShader + 3);
          psnLineArg1 = (uint *)(uint)*(ushort *)((int)pixelShader + 0xe);
          argR7 = (uint)*(byte *)((int)pixelShader + 0x19);
          argR8 = (uint *)(uint)*(byte *)((int)pixelShader + 0x1a);
          argR9 = (char *)(uint)*(byte *)((int)pixelShader + 0x1f);
          argR10 = (byte *)(uint)*(byte *)(pixelShader + 8);
          ((int (*)())psnReportError)(0,"+++ R300PSN_INST_TEX    : %04x %04x %02x %02x %02x %02x\n",psnLineArg0,psnLineArg1,
                       argR7,argR8,argR9,argR10);
          break;
        default:
          ((int (*)())psnReportError)(0,"+++ R300PSN_INST_ALU    : \n",psnLineArg0,psnLineArg1,argR7,argR8,
                       0,argR10);
          ((int (*)())psnReportError)(0,"+++ RGB_ADDR            : %04x %04x %04x %04x %02x %02x %02x\n",
                       (uint)*(ushort *)(pixelShader + 3),(uint)*(ushort *)((int)pixelShader + 0xe),
                       (uint)*(ushort *)(pixelShader + 4),(uint)*(ushort *)((int)pixelShader + 0x12),
                       (uint)*(byte *)(pixelShader + 5),(uint)*(byte *)((int)pixelShader + 0x15));
          ((int (*)())psnReportError)(0,"+++ ALPHA_ADDR          : %04x %04x %04x %04x %02x %02x %02x %02x\n",
                       (uint)*(ushort *)(pixelShader + 6),(uint)*(ushort *)((int)pixelShader + 0x1a),
                       (uint)*(ushort *)(pixelShader + 7),(uint)*(ushort *)((int)pixelShader + 0x1e),
                       (uint)*(byte *)(pixelShader + 8),(uint)*(byte *)((int)pixelShader + 0x21));
          ((int (*)())psnReportError)(0,
                       "+++ RGB_INST            : %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x\n"
                       ,(uint)*(byte *)((int)pixelShader + 0x2a),(uint)*(byte *)((int)pixelShader + 0x2d),
                       (uint)*(byte *)((int)pixelShader + 0x2b),(uint)*(byte *)((int)pixelShader + 0x2e),
                       (uint)*(byte *)(pixelShader + 0xb),(uint)*(byte *)((int)pixelShader + 0x2f));
          psnLineArg0 = (uint)*(byte *)((int)pixelShader + 0x39);
          psnLineArg1 = (uint *)(uint)*(byte *)(pixelShader + 0xf);
          argR7 = (uint)*(byte *)((int)pixelShader + 0x3a);
          argR8 = (uint *)(uint)*(byte *)((int)pixelShader + 0x3d);
          argR9 = (char *)(uint)*(byte *)((int)pixelShader + 0x3b);
          argR10 = (byte *)(uint)*(byte *)((int)pixelShader + 0x3e);
          ((int (*)())psnReportError)(0,
                       "+++ ALPHA_INST          : %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x\n"
                       ,psnLineArg0,psnLineArg1,argR7,argR8,argR9,argR10);
        }
      }
      psnRecordIndex = psnRecordIndex + 1;
      pixelShader = pixelShader + 0x12;
    } while (psnRecordIndex <= psnRecordCount);
    ((int (*)())psnReportError)(0,"+++ END_PSN                         # \"%s\" %d\n",dumpLabelSlot,
                 dumpIdSlot,argR7,argR8,argR9,argR10);
  }
  else {
    neutralRecordCountArg = pixelShader[2];
    neutralLineArg0 = dumpIdSlot;
    recordCount2 = neutralRecordCountArg;
    ((int (*)())psnReportError)(0,"======== Begin r520 neutral format pixel shader: %d =============\n",
                 dumpIdSlot,argR6,neutralRecordCountArg,argR8,argR9,argR10);
    if (*(short *)(pixelShader + 5) == 0) {
      ((int (*)())psnReportError)(0," Shader stats not valid\n \n",neutralLineArg0,argR6,neutralRecordCountArg,argR8,argR9,argR10);
    }
    else {
      ((int (*)())psnReportError)(0," Shader stats:\n",neutralLineArg0,argR6,neutralRecordCountArg,argR8,argR9,argR10);
      ((int (*)())psnReportError)(0,"     RS Instructions:        %2d\n",(uint)*(ushort *)(pixelShader + 6),argR6,
                   neutralRecordCountArg,argR8,argR9,argR10);
      ((int (*)())psnReportError)(0,"     TEX Instructions:      %3d\n",(uint)*(ushort *)((int)pixelShader + 0x1a),
                   argR6,neutralRecordCountArg,argR8,argR9,argR10);
      ((int (*)())psnReportError)(0,"     ALU Instructions:      %3d\n",(uint)*(ushort *)(pixelShader + 7),argR6,
                   neutralRecordCountArg,argR8,argR9,argR10);
      ((int (*)())psnReportError)(0,"     ALU Instruction slots: %3d\n",(uint)*(ushort *)((int)pixelShader + 0x1e),
                   argR6,neutralRecordCountArg,argR8,argR9,argR10);
      if (*(byte *)((int)pixelShader + 0xe) != 0) {
        ((int (*)())psnReportError)(0,"     UMRT_EN:               %3d\n",(uint)*(byte *)((int)pixelShader + 0xe),
                     argR6,neutralRecordCountArg,argR8,argR9,argR10);
      }
      ((int (*)())psnReportError)(0,"     CF Instructions:       %3d\n",(uint)*(ushort *)(pixelShader + 8),argR6,
                   neutralRecordCountArg,argR8,argR9,argR10);
      ((int (*)())psnReportError)(0,"     Pix Size:               %2d\n",(uint)*(ushort *)((int)pixelShader + 0x22),
                   argR6,neutralRecordCountArg,argR8,argR9,argR10);
      ((int (*)())psnReportError)(0,"     Highest Const:          %2d\n",(uint)*(ushort *)(pixelShader + 9),argR6,
                   neutralRecordCountArg,argR8,argR9,argR10);
      ((int (*)())psnReportError)(0,"     Start Addr:            %3d\n",(uint)*(ushort *)(pixelShader + 4),argR6,
                   neutralRecordCountArg,argR8,argR9,argR10);
      neutralLineArg0 = (uint *)(uint)*(ushort *)((int)pixelShader + 0x12);
      ((int (*)())psnReportError)(0,"     End Addr:              %3d\n",neutralLineArg0,argR6,neutralRecordCountArg,argR8,argR9,
                   argR10);
      ((int (*)())psnReportError)(0," \n",neutralLineArg0,argR6,neutralRecordCountArg,argR8,argR9,argR10);
    }
    ((int (*)())psnReportError)(0," RS Instructions:\n \n",neutralLineArg0,argR6,neutralRecordCountArg,argR8,argR9,argR10);
    if ((pixelShader[0x12] == 1) && (0 < (int)recordCount2)) {
      rsScanRecord2 = pixelShader + 0x24;
      rsRecordNumber2 = 1;
      rsNextRecord2 = rsScanRecord2;
      rsRecord2 = pixelShader + 0x12;
      do {
        rsNextRecordCopy2 = rsNextRecord2;
        neutralLineArg0 = (uint *)(rsRecordNumber2 + -1);
        ((int (*)())psnReportError)(0,"   rs %02d:",neutralLineArg0,argR6,neutralRecordCountArg,argR8,argR9,argR10);
        rsColorSource = *(char *)((int)rsRecord2 + 0xb);
        if (rsColorSource == '\0') {
          if (*(char *)((int)rsRecord2 + 9) != '\0') {
            ((int (*)())psnReportError)(0,"                         ",neutralLineArg0,argR6,neutralRecordCountArg,argR8,argR9,
                         argR10);
            goto LAB_000d1afc;
          }
LAB_000d1b5c:
          ((int (*)())psnReportError)(0,"\n",neutralLineArg0,argR6,neutralRecordCountArg,argR8,argR9,argR10);
        }
        else {
          rsColorWriteMask = *(byte *)((int)rsRecord2 + 0xf) & 0xf ^ 0xf;
          if (rsColorSource == '\x01') {
            neutralLineArg0 = (uint *)(uint)*(ushort *)((int)rsRecord2 + 6);
            neutralRecordCountArg = (uint)*(byte *)((int)rsRecord2 + 10);
            argR6 = (char *)(rsColorWriteMask * 5 + 0x1dc279);
            ((int (*)())psnReportError)(0,"  r%02d.%s = col%02ld",neutralLineArg0,argR6,neutralRecordCountArg,argR8,argR9,argR10);
            if (*(char *)((int)rsRecord2 + 0xd) == '\0') {
              rsColorSource = *(char *)((int)rsRecord2 + 0xb);
            }
            else {
              ((int (*)())psnReportError)(0," biased",neutralLineArg0,argR6,neutralRecordCountArg,argR8,argR9,argR10);
              rsColorSource = *(char *)((int)rsRecord2 + 0xb);
            }
          }
          if (rsColorSource == '\x02') {
            neutralLineArg0 = (uint *)(uint)*(ushort *)((int)rsRecord2 + 6);
            argR6 = (char *)(rsColorWriteMask * 5 + 0x1dc279);
            ((int (*)())psnReportError)(0,"  r%02d.%s = fbuf",neutralLineArg0,argR6,neutralRecordCountArg,argR8,argR9,argR10);
          }
          else if (rsColorSource == '\x03') {
            neutralLineArg0 = (uint *)(uint)*(ushort *)((int)rsRecord2 + 6);
            argR6 = (char *)(rsColorWriteMask * 5 + 0x1dc279);
            ((int (*)())psnReportError)(0,"  r%02d.%s = back",neutralLineArg0,argR6,neutralRecordCountArg,argR8,argR9,argR10);
          }
          else {
            if (*(char *)((int)rsRecord2 + 9) == '\0') goto LAB_000d1b5c;
            ((int (*)())psnReportError)(0,"       ",neutralLineArg0,argR6,neutralRecordCountArg,argR8,argR9,argR10);
          }
LAB_000d1afc:
          if (*(char *)((int)rsRecord2 + 9) == '\0') goto LAB_000d1b5c;
          neutralLineArg0 = (uint *)(uint)*(ushort *)(rsRecord2 + 1);
          neutralRecordCountArg = (uint)*(byte *)(rsRecord2 + 2);
          argR6 = (char *)((*(byte *)((int)rsRecord2 + 0xe) & 0xf ^ 0xf) * 5 + 0x1dc279);
          ((int (*)())psnReportError)(0,"   r%02d.%s = txc%02ld",neutralLineArg0,argR6,neutralRecordCountArg,argR8,argR9,argR10);
          if (*(char *)(rsRecord2 + 3) == '\0') goto LAB_000d1b5c;
          ((int (*)())psnReportError)(0," adjusted\n",neutralLineArg0,argR6,neutralRecordCountArg,argR8,argR9,argR10);
        }
        rsRecordNumber2 = rsRecordNumber2 + 1;
        if (*rsScanRecord2 != 1) break;
        rsScanRecord2 = rsScanRecord2 + 0x12;
        rsNextRecord2 = rsNextRecordCopy2 + 0x12;
        rsRecord2 = rsNextRecordCopy2;
      } while (rsRecordNumber2 <= (int)recordCount2);
    }
    else {
      rsRecordNumber2 = 1;
    }
    blankLineFormatOffset = 0x1a1848;
    ((int (*)())psnReportError)(0," \n US Program:\n",neutralLineArg0,argR6,neutralRecordCountArg,argR8,argR9,argR10);
    ((int (*)())psnReportError)(0,blankLineFormatOffset + 0x5b00,neutralLineArg0,argR6,neutralRecordCountArg,argR8,argR9,argR10);
    if (rsRecordNumber2 <= (int)recordCount2) {
      texFlagsByte = 0;
      instructionRecord2 = pixelShader + rsRecordNumber2 * 0x12;
      instructionNumber = 0;
      aluIndex = (uint *)0x0;
      texIndex = 0;
      cfIndex = 0;
      cfPrevAluDest = 0;
      cfCompareCode = 0;
      do {
        if (*(char *)(instructionRecord2 + 7) == '\0') {
          ignUncText = ignUncText & 0xffffff;
        }
        else {
          argR9 = " ign_unc";
          (*(unsigned char *)((unsigned char *)&(ignUncText) + 0)) = s_ign_unc_001a734c[0];
          (*(unsigned char *)((unsigned char *)&(ignUncText) + 1)) = s_ign_unc_001a734c[1];
          (*(unsigned char *)((unsigned char *)&(ignUncText) + 2)) = s_ign_unc_001a734c[2];
          (*(unsigned char *)((unsigned char *)&(ignUncText) + 3)) = s_ign_unc_001a734c[3];
          ignUncText4[0] = s_ign_unc_001a734c[4];
          ignUncText4[1] = s_ign_unc_001a734c[5];
          ignUncText4[2] = s_ign_unc_001a734c[6];
          ignUncText4[3] = s_ign_unc_001a734c[7];
          ignUncText8 = s_ign_unc_001a734c[8];
        }
        if (*(char *)(instructionRecord2 + 1) == '\0') {
          semWaitText = semWaitText & 0xffffff;
        }
        else {
          argR9 = " sem_wait";
          (*(unsigned char *)((unsigned char *)&(semWaitText) + 0)) = s_sem_wait_001a7358[0];
          (*(unsigned char *)((unsigned char *)&(semWaitText) + 1)) = s_sem_wait_001a7358[1];
          (*(unsigned char *)((unsigned char *)&(semWaitText) + 2)) = s_sem_wait_001a7358[2];
          (*(unsigned char *)((unsigned char *)&(semWaitText) + 3)) = s_sem_wait_001a7358[3];
          semWaitText4[0] = s_sem_wait_001a7358[4];
          semWaitText4[1] = s_sem_wait_001a7358[5];
          semWaitText4[2] = s_sem_wait_001a7358[6];
          semWaitText4[3] = s_sem_wait_001a7358[7];
          semWaitText8[0] = s_sem_wait_001a7358[8];
          semWaitText8[1] = s_sem_wait_001a7358[9];
        }
        if (*(char *)((int)instructionRecord2 + 0xb) == '\0') {
          aluWaitText = aluWaitText & 0xffffff;
        }
        else {
          argR9 = " alu_wait";
          (*(unsigned char *)((unsigned char *)&(aluWaitText) + 0)) = s_alu_wait_001a7364[0];
          (*(unsigned char *)((unsigned char *)&(aluWaitText) + 1)) = s_alu_wait_001a7364[1];
          (*(unsigned char *)((unsigned char *)&(aluWaitText) + 2)) = s_alu_wait_001a7364[2];
          (*(unsigned char *)((unsigned char *)&(aluWaitText) + 3)) = s_alu_wait_001a7364[3];
          aluWaitText4[0] = s_alu_wait_001a7364[4];
          aluWaitText4[1] = s_alu_wait_001a7364[5];
          aluWaitText4[2] = s_alu_wait_001a7364[6];
          aluWaitText4[3] = s_alu_wait_001a7364[7];
          aluWaitText8[0] = s_alu_wait_001a7364[8];
          aluWaitText8[1] = s_alu_wait_001a7364[9];
        }
        recordKind2 = *instructionRecord2;
        if (recordKind2 == 2) {
          ((int (*)())psnReportError)(0,"  %d tex %02d    :  ",instructionNumber,texIndex,neutralRecordCountArg,argR8,argR9,argR10);
          texEnableBits = *(byte *)((int)instructionRecord2 + 0x1d);
          texSrcReg2 = *(ushort *)((int)instructionRecord2 + 0xe);
          neutralLineArg0 = (uint *)(uint)texSrcReg2;
          texDestReg2 = *(ushort *)(instructionRecord2 + 3);
          texComponentEnableBits = (*(byte *)((int)instructionRecord2 + 0x1e) & 0x1f) << 3 | (uint)texEnableBits;
          texUnit2 = (uint *)(uint)*(byte *)((int)instructionRecord2 + 0x19);
          texEnableR = (texEnableBits & 1) != 0;
          texWriteMask = *(byte *)(instructionRecord2 + 5);
          if (texEnableR) {
            maskTextX = (char *)((texWriteMask >> 4 & 0xc) + 0x1dc259);
          }
          else {
            maskTextX = "_";
          }
          texEnableG = (texEnableBits & 2) != 0;
          if (texEnableG) {
            maskTextY = (char *)((texWriteMask >> 2 & 0xc) + 0x1dc259);
          }
          else {
            maskTextY = "_";
          }
          texEnableB = (texEnableBits & 4) != 0;
          if (texEnableB) {
            maskTextZ = (char *)((texWriteMask & 0xc) + 0x1dc259);
          }
          else {
            maskTextZ = "_";
          }
          texEnableA = (texComponentEnableBits >> 3 & 1) != 0;
          if (texEnableA) {
            maskTextW = (char *)((texWriteMask & 3) * 4 + 0x1dc259);
          }
          else {
            maskTextW = "_";
          }
          printf_LDBLStub_1a32d0(writeMaskText,"%s%s%s%s",maskTextX,maskTextY,maskTextZ,maskTextW,texComponentEnableBits,argR10);
          if ((*(byte *)((int)instructionRecord2 + 0x1a) < 7) &&
             ((1 << ((int)(char)*(byte *)((int)instructionRecord2 + 0x1a) & 0x3fU) & 0x7aU) != 0)) {
            ((int (*)())psnReportError)(0,"r%02d.%s = ",(uint)texDestReg2,writeMaskText,maskTextZ,maskTextW,texComponentEnableBits,argR10);
          }
          if (*(byte *)((int)instructionRecord2 + 0x1a) == 2) {
            texSrcSwizzleByte = *(byte *)((int)instructionRecord2 + 0x15);
            argR9 = (char *)(uint)texSrcSwizzleByte;
            if (texEnableR) {
              srcSwizzleTextX = (char *)((texSrcSwizzleByte >> 4 & 0xc) + 0x1dc259);
            }
            else {
              srcSwizzleTextX = "-";
            }
            if (texEnableG) {
              argR6 = (char *)((texSrcSwizzleByte >> 2 & 0xc) + 0x1dc259);
            }
            else {
              argR6 = "-";
            }
            if (texEnableB) {
              srcSwizzleTextZ = (char *)((texSrcSwizzleByte & 0xc) + 0x1dc259);
            }
            else {
              srcSwizzleTextZ = "-";
            }
            if (texEnableA) {
              argR8 = (uint *)(((uint)argR9 & 3) * 4 + 0x1dc259);
            }
            else {
              argR8 = (uint *)"-";
            }
          }
          else {
            texFlagsByte = (uint)*(byte *)((int)instructionRecord2 + 0x1f);
            texSrcSwizzleByte2 = *(byte *)((int)instructionRecord2 + 0x15);
            argR9 = (char *)(uint)texSrcSwizzleByte2;
            if ((*(byte *)((int)instructionRecord2 + 0x1f) & 1) == 0) {
              argR10 = (byte *)(texSrcSwizzleByte2 & 0xc);
              argR9 = (char *)(((uint)argR9 & 3) * 4);
              argR8 = (uint *)((int)argR9 + 0x1dc259);
              srcSwizzleTextX = (char *)((texSrcSwizzleByte2 >> 4 & 0xc) + 0x1dc259);
              argR6 = (char *)((texSrcSwizzleByte2 >> 2 & 0xc) + 0x1dc259);
              srcSwizzleTextZ = (char *)(argR10 + 0x1dc259);
            }
            else {
              srcSwizzleTextX = "-";
              argR6 = srcSwizzleTextX;
              srcSwizzleTextZ = srcSwizzleTextX;
              argR8 = (uint *)srcSwizzleTextX;
            }
          }
          srcSwizzleTextPtr = srcSwizzleText;
          printf_LDBLStub_1a32d0(srcSwizzleTextPtr,"%s%s%s%s",srcSwizzleTextX,argR6,srcSwizzleTextZ,argR8,argR9,argR10);
          if ((texSrcReg2 & 0x4000) == 0) {
            printf_LDBLStub_1a32d0(registerText,"r%02d",neutralLineArg0,argR6,srcSwizzleTextZ,argR8,argR9,argR10);
          }
          else {
            neutralLineArg0 = (uint *)((uint)neutralLineArg0 & 0xbfff);
            printf_LDBLStub_1a32d0(registerText,"r[AL+%02d]",neutralLineArg0,argR6,srcSwizzleTextZ,argR8,argR9,argR10);
          }
          registerTextPtr = registerText;
          if (*(char *)((int)instructionRecord2 + 0x1b) == '\0') {
            semGrabText = semGrabText & 0xffffff;
          }
          else {
            argR9 = " sem_grab";
            (*(unsigned char *)((unsigned char *)&(semGrabText) + 0)) = s_sem_grab_001a73ac[0];
            (*(unsigned char *)((unsigned char *)&(semGrabText) + 1)) = s_sem_grab_001a73ac[1];
            (*(unsigned char *)((unsigned char *)&(semGrabText) + 2)) = s_sem_grab_001a73ac[2];
            (*(unsigned char *)((unsigned char *)&(semGrabText) + 3)) = s_sem_grab_001a73ac[3];
            semGrabText4[0] = s_sem_grab_001a73ac[4];
            semGrabText4[1] = s_sem_grab_001a73ac[5];
            semGrabText4[2] = s_sem_grab_001a73ac[6];
            semGrabText4[3] = s_sem_grab_001a73ac[7];
            semGrabText8[0] = s_sem_grab_001a73ac[8];
            semGrabText8[1] = s_sem_grab_001a73ac[9];
          }
          texOpcodeByte = *(byte *)((int)instructionRecord2 + 0x1a);
          if (texOpcodeByte < 8) {
            argR9 = (char *)(0);
            switch(texOpcodeByte) {
            case 0:
              ((int (*)())psnReportError)(0,"NOP\n",neutralLineArg0,argR6,srcSwizzleTextZ,argR8,argR9,argR10);
              break;
            case 1:
              argR8 = &semWaitText;
              argR9 = (char *)&semGrabText;
              ((int (*)())psnReportError)(0,"lookup(%s.%s, tex%02d)%s%s%s%s",registerTextPtr,srcSwizzleTextPtr,texUnit2,argR8,
                           argR9,&aluWaitText);
              neutralLineArg0 = registerTextPtr;
              argR6 = (char *)srcSwizzleTextPtr;
              srcSwizzleTextZ = (char *)texUnit2;
              break;
            case 2:
              srcSwizzleTextZ = (char *)&semWaitText;
              argR8 = &semGrabText;
              argR9 = (char *)&aluWaitText;
              ((int (*)())psnReportError)(0,"kill(%s.%s)%s%s%s",registerTextPtr,srcSwizzleTextPtr,srcSwizzleTextZ,argR8,argR9,argR10);
              neutralLineArg0 = registerTextPtr;
              argR6 = (char *)srcSwizzleTextPtr;
              break;
            case 3:
              argR8 = &semWaitText;
              argR9 = (char *)&semGrabText;
              ((int (*)())psnReportError)(0,"lookup_proj(%s.%s, tex%02d)%s%s%s%s",registerTextPtr,srcSwizzleTextPtr,texUnit2,argR8,
                           argR9,&aluWaitText);
              neutralLineArg0 = registerTextPtr;
              argR6 = (char *)srcSwizzleTextPtr;
              srcSwizzleTextZ = (char *)texUnit2;
              break;
            case 4:
              argR8 = &semWaitText;
              argR9 = (char *)&semGrabText;
              ((int (*)())psnReportError)(0,"lookup_lodbias(%s.%s, tex%02d)%s%s%s%s",registerTextPtr,srcSwizzleTextPtr,texUnit2,
                           argR8,argR9,&aluWaitText);
              neutralLineArg0 = registerTextPtr;
              argR6 = (char *)srcSwizzleTextPtr;
              srcSwizzleTextZ = (char *)texUnit2;
              break;
            case 5:
              argR8 = &semWaitText;
              argR9 = (char *)&semGrabText;
              ((int (*)())psnReportError)(0,"lookup_lod(%s.%s, tex%02d)%s%s%s%s",registerTextPtr,srcSwizzleTextPtr,texUnit2,argR8,
                           argR9,&aluWaitText);
              neutralLineArg0 = registerTextPtr;
              argR6 = (char *)srcSwizzleTextPtr;
              srcSwizzleTextZ = (char *)texUnit2;
              break;
            case 6:
              texDxSwizzleByte = *(byte *)((int)instructionRecord2 + 0x16);
              dxSwizzleWOffset = (uint)texDxSwizzleByte;
              texSwizzleEnabled = (texFlagsByte & 1) == 0;
              if (texSwizzleEnabled) {
                argR10 = (byte *)(texDxSwizzleByte & 0xc);
                dxSwizzleWOffset = (dxSwizzleWOffset & 3) * 4;
                dxSwizzleTextW = (char *)(dxSwizzleWOffset + 0x1dc259);
                dxSwizzleTextX = (char *)((texDxSwizzleByte >> 4 & 0xc) + 0x1dc259);
                dxSwizzleTextY = (char *)((texDxSwizzleByte >> 2 & 0xc) + 0x1dc259);
                dxSwizzleTextZ = argR10 + 0x1dc259;
              }
              else {
                dxSwizzleTextX = "-";
                dxSwizzleTextY = dxSwizzleTextX;
                dxSwizzleTextZ = (byte *)dxSwizzleTextX;
                dxSwizzleTextW = dxSwizzleTextX;
              }
              argR8 = dxSwizzleTextA;
              printf_LDBLStub_1a32d0(argR8,"%s%s%s%s",dxSwizzleTextX,dxSwizzleTextY,dxSwizzleTextZ,dxSwizzleTextW,dxSwizzleWOffset,argR10);
              texDySwizzleByte = *(byte *)((int)instructionRecord2 + 0x16);
              dySwizzleWOffset = (uint)texDySwizzleByte;
              srcSwizzleTextZ = (char *)(uint)*(ushort *)(instructionRecord2 + 4);
              if (texSwizzleEnabled) {
                argR10 = (byte *)(texDySwizzleByte & 0xc);
                dySwizzleWOffset = (dySwizzleWOffset & 3) * 4;
                dySwizzleTextW = (char *)(dySwizzleWOffset + 0x1dc259);
                dySwizzleTextX = (char *)((texDySwizzleByte >> 4 & 0xc) + 0x1dc259);
                dySwizzleTextY = (char *)((texDySwizzleByte >> 2 & 0xc) + 0x1dc259);
                dySwizzleTextZ = argR10 + 0x1dc259;
              }
              else {
                dySwizzleTextX = "-";
                dySwizzleTextY = dySwizzleTextX;
                dySwizzleTextZ = (byte *)dySwizzleTextX;
                dySwizzleTextW = dySwizzleTextX;
              }
              printf_LDBLStub_1a32d0(operandText0,"%s%s%s%s",dySwizzleTextX,dySwizzleTextY,dySwizzleTextZ,dySwizzleTextW,dySwizzleWOffset,argR10);
              argR9 = (char *)(uint)*(ushort *)((int)instructionRecord2 + 0x12);
              staleStackArg_fffffd2c = &semWaitText;
              ((int (*)())psnReportError)(0,"lookup_dxdy(%s.%s, r%02d.%s, r%02d.%s,  tex%02d)%s%s%s%s",registerTextPtr,
                           srcSwizzleTextPtr,srcSwizzleTextZ,argR8,argR9,operandText0);
              neutralLineArg0 = registerTextPtr;
              argR6 = (char *)srcSwizzleTextPtr;
              break;
            case 7:
              argR8 = &semWaitText;
              argR9 = (char *)&semGrabText;
              ((int (*)())psnReportError)(0,"lookup_uncached(%s.%s, tex%02d)%s%s%s%s",registerTextPtr,srcSwizzleTextPtr,texUnit2,
                           argR8,argR9,&aluWaitText);
              neutralLineArg0 = registerTextPtr;
              argR6 = (char *)srcSwizzleTextPtr;
              srcSwizzleTextZ = (char *)texUnit2;
            }
          }
          else {
            neutralLineArg0 = &semWaitText;
            argR6 = (char *)&semGrabText;
            srcSwizzleTextZ = (char *)&aluWaitText;
            argR8 = &ignUncText;
            ((int (*)())psnReportError)(0,"UNKNOWN_OP%s%s%s%s",neutralLineArg0,argR6,srcSwizzleTextZ,argR8,argR9,argR10);
          }
          predicateControlPtr = (byte *)((int)instructionRecord2 + 5);
          if (*(char *)((int)instructionRecord2 + 5) != '\0') {
            if (*(char *)((int)instructionRecord2 + 6) == '\0') {
              (*(unsigned int *)((unsigned char *)&(predicateText) + 0)) = CONCAT21(0x7000,(*(unsigned char *)((unsigned char *)&(predicateText) + 2)));
            }
            else {
              argR9 = "!p";
              (*(unsigned int *)((unsigned char *)&(predicateText) + 0)) = CONCAT12(s__p_001a74dc[0],(*(unsigned short *)((unsigned char *)&(s__p_001a74dc) + 1)));
            }
            predicateModeByte = *predicateControlPtr;
            if (predicateModeByte < 6) {
              argR9 = (char *)(0);
              switch(predicateModeByte) {
              case 1:
                neutralLineArg0 = &predicateText;
                ((int (*)())psnReportError)(0," %s.rgb",neutralLineArg0,argR6,srcSwizzleTextZ,argR8,argR9,predicateControlPtr);
                break;
              case 2:
                neutralLineArg0 = &predicateText;
                ((int (*)())psnReportError)(0," %s.rrr",neutralLineArg0,argR6,srcSwizzleTextZ,argR8,argR9,predicateControlPtr);
                break;
              case 3:
                neutralLineArg0 = &predicateText;
                ((int (*)())psnReportError)(0," %s.ggg",neutralLineArg0,argR6,srcSwizzleTextZ,argR8,argR9,predicateControlPtr);
                break;
              case 4:
                neutralLineArg0 = &predicateText;
                ((int (*)())psnReportError)(0," %s.bbb",neutralLineArg0,argR6,srcSwizzleTextZ,argR8,argR9,predicateControlPtr);
                break;
              case 5:
                neutralLineArg0 = &predicateText;
                ((int (*)())psnReportError)(0," %s.aaa",neutralLineArg0,argR6,srcSwizzleTextZ,argR8,argR9,predicateControlPtr);
              }
            }
          }
          argR10 = (byte *)((int)instructionRecord2 + 7);
          if (*(char *)((int)instructionRecord2 + 7) != '\0') {
            if (*(char *)(instructionRecord2 + 2) == '\0') {
              (*(unsigned int *)((unsigned char *)&(predicateText) + 0)) = CONCAT21(0x7000,(*(unsigned char *)((unsigned char *)&(predicateText) + 2)));
            }
            else {
              argR9 = "!p";
              (*(unsigned int *)((unsigned char *)&(predicateText) + 0)) = CONCAT12(s__p_001a74dc[0],(*(unsigned short *)((unsigned char *)&(s__p_001a74dc) + 1)));
            }
            predicateModeByteAlpha = *argR10;
            if (predicateModeByteAlpha < 6) {
              argR9 = (char *)(0);
              switch(predicateModeByteAlpha) {
              case 0:
                break;
              default:
                neutralLineArg0 = &predicateText;
                ((int (*)())psnReportError)(0," %s.a",neutralLineArg0,argR6,srcSwizzleTextZ,argR8,argR9,argR10);
                break;
              case 2:
                neutralLineArg0 = &predicateText;
                ((int (*)())psnReportError)(0," %s.r",neutralLineArg0,argR6,srcSwizzleTextZ,argR8,argR9,argR10);
                break;
              case 3:
                neutralLineArg0 = &predicateText;
                ((int (*)())psnReportError)(0," %s.g",neutralLineArg0,argR6,srcSwizzleTextZ,argR8,argR9,argR10);
                break;
              case 4:
                neutralLineArg0 = &predicateText;
                ((int (*)())psnReportError)(0," %s.b",neutralLineArg0,argR6,srcSwizzleTextZ,argR8,argR9,argR10);
              }
            }
          }
          if (*(char *)((int)instructionRecord2 + 9) != '\0') {
            ((int (*)())psnReportError)(0," write_inactive",neutralLineArg0,argR6,srcSwizzleTextZ,argR8,argR9,argR10);
          }
          ((int (*)())psnReportError)(0,"\n",neutralLineArg0,argR6,srcSwizzleTextZ,argR8,argR9,argR10);
          recordKind2 = *instructionRecord2;
          texIndex = texIndex + 1;
        }
        operandAuxHigh = (undefined2)((uint)staleStackArg_fffffd2c >> 0x10);
        if ((recordKind2 == 3) || (recordKind2 == 4)) {
          rgbOpcodePtr = (byte *)((int)instructionRecord2 + 0x31);
          cfPrevAluDest = (uint)*(byte *)((int)instructionRecord2 + 0x43);
          cfCompareCode = (uint)*(byte *)(instructionRecord2 + 0x11);
          switch(*(undefined1 *)((int)instructionRecord2 + 0x31)) {
          case 0:
          case 3:
          case 7:
          case 8:
            rgbOperandAUsed = true;
            rgbOperandBUsed = true;
            rgbOperandCUsed = true;
            alphaUseMaskNeutral = 0;
            break;
          case 1:
          case 4:
          case 5:
          case 0xb:
          case 0xc:
            rgbOperandAUsed = true;
            rgbOperandBUsed = true;
            rgbOperandCUsed = false;
            alphaUseMaskNeutral = 0;
            break;
          case 2:
            rgbOperandAUsed = true;
            alphaUseMaskNeutral = 3;
            rgbOperandBUsed = true;
            rgbOperandCUsed = false;
            break;
          default:
            rgbOperandAUsed = false;
            rgbOperandBUsed = false;
            rgbOperandCUsed = false;
            alphaUseMaskNeutral = 0;
            break;
          case 9:
            rgbOperandAUsed = true;
            rgbOperandBUsed = false;
            rgbOperandCUsed = false;
            alphaUseMaskNeutral = 0;
          }
          alphaOpcodePtr = instructionRecord2 + 0x10;
          if (*(byte *)(instructionRecord2 + 0x10) < 0x10) {
            rgbOpcodeBit = 1 << ((int)(char)*(byte *)(instructionRecord2 + 0x10) & 0x3fU);
            if ((rgbOpcodeBit & 0x61) == 0) {
              if ((rgbOpcodeBit & 0xc00c) == 0) {
                if ((rgbOpcodeBit & 0x3f80) != 0) {
                  alphaUseMaskNeutral = alphaUseMaskNeutral | 1;
                }
              }
              else {
                alphaUseMaskNeutral = 3;
              }
            }
            else {
              alphaUseMaskNeutral = 7;
            }
          }
          rgbSelectABase = *(byte *)((int)instructionRecord2 + 0x2a) & 0xffffff7f;
          rgbSelectCRaw = (uint)*(byte *)(instructionRecord2 + 0xb);
          rgbSelectBBase = *(byte *)((int)instructionRecord2 + 0x2b) & 0xffffff7f;
          alphaSelectB = (uint)*(byte *)((int)instructionRecord2 + 0x3a);
          alphaSelectC = (uint)*(byte *)((int)instructionRecord2 + 0x3b);
          rgbSelectCBase = *(byte *)(instructionRecord2 + 0xb) & 0xffffff7f;
          alphaSelectABase = *(byte *)((int)instructionRecord2 + 0x39) & 0xffffff7f;
          alphaSelectBBase = *(byte *)((int)instructionRecord2 + 0x3a) & 0xffffff7f;
          alphaSelectCBase = *(byte *)((int)instructionRecord2 + 0x3b) & 0xffffff7f;
          rgbAuxC = *(ushort *)(instructionRecord2 + 10);
          rgbAddrA = (uint)*(ushort *)((int)instructionRecord2 + 0xe);
          rgbAddrB = (uint *)(uint)*(ushort *)(instructionRecord2 + 4);
          rgbAddrC = (uint *)(uint)*(ushort *)((int)instructionRecord2 + 0x12);
          alphaAddrA = (uint *)(uint)*(ushort *)((int)instructionRecord2 + 0x1a);
          argR8 = (uint *)(uint)*(ushort *)(instructionRecord2 + 7);
          argR9 = (char *)(uint)*(ushort *)((int)instructionRecord2 + 0x1e);
          rgbAuxA = *(ushort *)(instructionRecord2 + 9);
          rgbAuxB = *(ushort *)((int)instructionRecord2 + 0x26);
          alphaAuxD = (uint *)(uint)*(byte *)(instructionRecord2 + 0xe);
          alphaAuxB = (uint)*(byte *)((int)instructionRecord2 + 0x36);
          alphaAuxC = (uint)*(byte *)((int)instructionRecord2 + 0x37);
          rgbModA2 = (uint)*(byte *)((int)instructionRecord2 + 0x2d);
          rgbModB2 = (uint)*(byte *)((int)instructionRecord2 + 0x2e);
          rgbModC2 = (uint)*(byte *)((int)instructionRecord2 + 0x2f);
          alphaModA2 = (uint)*(byte *)(instructionRecord2 + 0xf);
          alphaModB2 = (uint)*(byte *)((int)instructionRecord2 + 0x3d);
          alphaModC2 = (uint)*(byte *)((int)instructionRecord2 + 0x3e);
          if (rgbOperandAUsed) {
            rgbSelectANotSrcp = rgbSelectABase != 3;
            if (rgbSelectANotSrcp) {
LAB_000d2654:
              rgbSrcpNeededFlag = false;
            }
            else {
              auxCheckResult = ((int (*)())psnSwizzleIsAlphaSourceForm)((uint)rgbAuxA);
              rgbSrcpNeededFlag = true;
              if (auxCheckResult != 0) goto LAB_000d2654;
            }
            if (!rgbSelectANotSrcp) {
              alphaSrcpNeededFlag = true;
              auxCheckResult = ((int (*)())psnSwizzleIsAlphaSourceForm)((uint)rgbAuxA);
              if (auxCheckResult != 0) goto LAB_000d2674;
            }
            alphaSrcpNeededFlag = false;
          }
          else {
            alphaSrcpNeededFlag = false;
            rgbSrcpNeededFlag = false;
          }
LAB_000d2674:
          if (rgbOperandBUsed) {
            rgbSelectBNotSrcp = rgbSelectBBase != 3;
            if (rgbSelectBNotSrcp) {
LAB_000d269c:
              srcpNeedBit = 0;
            }
            else {
              auxCheckResult = ((int (*)())psnSwizzleIsAlphaSourceForm)((uint)rgbAuxB);
              srcpNeedBit = 1;
              if (auxCheckResult != 0) goto LAB_000d269c;
            }
            rgbSrcpNeededFlag = (bool)(rgbSrcpNeededFlag | srcpNeedBit);
            if (rgbSelectBNotSrcp) {
LAB_000d26bc:
              srcpNeedBit = 0;
            }
            else {
              auxCheckResult = ((int (*)())psnSwizzleIsAlphaSourceForm)((uint)rgbAuxB);
              srcpNeedBit = 1;
              if (auxCheckResult == 0) goto LAB_000d26bc;
            }
            alphaSrcpNeededFlag = (bool)(alphaSrcpNeededFlag | srcpNeedBit);
          }
          if (rgbOperandCUsed) {
            rgbSelectCNotSrcp = rgbSelectCBase != 3;
            if (rgbSelectCNotSrcp) {
LAB_000d26ec:
              srcpNeedBit = 0;
            }
            else {
              auxCheckResult = ((int (*)())psnSwizzleIsAlphaSourceForm)((uint)rgbAuxC);
              srcpNeedBit = 1;
              if (auxCheckResult != 0) goto LAB_000d26ec;
            }
            rgbSrcpNeededFlag = (bool)(rgbSrcpNeededFlag | srcpNeedBit);
            if (rgbSelectCNotSrcp) {
LAB_000d270c:
              srcpNeedBit = 0;
            }
            else {
              auxCheckResult = ((int (*)())psnSwizzleIsAlphaSourceForm)((uint)rgbAuxC);
              srcpNeedBit = 1;
              if (auxCheckResult == 0) goto LAB_000d270c;
            }
            alphaSrcpNeededFlag = (bool)(alphaSrcpNeededFlag | srcpNeedBit);
          }
          if ((alphaUseMaskNeutral & 1) != 0) {
            if ((alphaSelectABase != 3) || (srcpNeedBit = 1, alphaAuxB == 3)) {
              srcpNeedBit = 0;
            }
            rgbSrcpNeededFlag = (bool)(rgbSrcpNeededFlag | srcpNeedBit);
            if ((alphaSelectABase != 3) || (srcpNeedBit = 1, alphaAuxB != 3)) {
              srcpNeedBit = 0;
            }
            alphaSrcpNeededFlag = (bool)(alphaSrcpNeededFlag | srcpNeedBit);
          }
          alphaUseBitB = (uint *)(alphaUseMaskNeutral & 2);
          if (alphaUseBitB != (uint *)0x0) {
            if ((alphaSelectBBase != 3) || (srcpNeedBit = 1, alphaAuxC == 3)) {
              srcpNeedBit = 0;
            }
            rgbSrcpNeededFlag = (bool)(rgbSrcpNeededFlag | srcpNeedBit);
            if ((alphaSelectBBase != 3) || (srcpNeedBit = 1, alphaAuxC != 3)) {
              srcpNeedBit = 0;
            }
            alphaSrcpNeededFlag = (bool)(alphaSrcpNeededFlag | srcpNeedBit);
          }
          if ((alphaUseMaskNeutral & 4) != 0) {
            if ((alphaSelectCBase != 3) ||
               (srcpNeedBit = 1, alphaUseBitB = alphaAuxD, alphaAuxD == (uint *)((int)((unsigned char *)0x0) + 3))) {
              srcpNeedBit = 0;
            }
            rgbSrcpNeededFlag = (bool)(rgbSrcpNeededFlag | srcpNeedBit);
            if ((alphaSelectCBase != 3) || (srcpNeedBit = 1, alphaAuxD != (uint *)((int)((unsigned char *)0x0) + 3))) {
              srcpNeedBit = 0;
            }
            alphaSrcpNeededFlag = (bool)(alphaSrcpNeededFlag | srcpNeedBit);
          }
          if (rgbSrcpNeededFlag) {
            instructionNumberArg = instructionNumber;
            aluIndexArg = aluIndex;
            printfResultScratch = (double)((int (*)())psnReportError)(0,"  %d alu %02d pre:  srcp.rgb = ",instructionNumber,aluIndex,
                                          alphaUseBitB,alphaSelectC,rgbSelectCRaw,alphaSelectB);
            rgbPreOpKind = *(char *)(instructionRecord2 + 0xc);
            if (rgbPreOpKind == '\x01') {
              printfResultScratch = (double)((double (*)())FUN_000d10dc)(&srcpTextB,rgbAddrA,instructionNumberArg,aluIndexArg,alphaUseBitB,alphaSelectC,rgbSelectCRaw,
                                            alphaSelectB,printfResultScratch);
              ((double (*)())FUN_000d10dc)(&srcpTextA,rgbAddrB,instructionNumberArg,aluIndexArg,alphaUseBitB,alphaSelectC,rgbSelectCRaw,alphaSelectB,printfResultScratch);
              ((int (*)())psnReportError)(0,"%s.rgb-%s.rgb\n",&srcpTextA,&srcpTextB,alphaUseBitB,alphaSelectC,rgbSelectCRaw,alphaSelectB);
            }
            else if (rgbPreOpKind == '\0') {
              ((double (*)())FUN_000d10dc)(&srcpTextB,rgbAddrA,instructionNumberArg,aluIndexArg,alphaUseBitB,alphaSelectC,rgbSelectCRaw,alphaSelectB,printfResultScratch);
              ((int (*)())psnReportError)(0,"1.0-2.0*%s.rgb\n",&srcpTextB,aluIndexArg,alphaUseBitB,alphaSelectC,rgbSelectCRaw,alphaSelectB);
            }
            else if (rgbPreOpKind == '\x02') {
              printfResultScratch = (double)((double (*)())FUN_000d10dc)(&srcpTextB,rgbAddrA,instructionNumberArg,aluIndexArg,alphaUseBitB,alphaSelectC,rgbSelectCRaw,
                                            alphaSelectB,printfResultScratch);
              ((double (*)())FUN_000d10dc)(&srcpTextA,rgbAddrB,instructionNumberArg,aluIndexArg,alphaUseBitB,alphaSelectC,rgbSelectCRaw,alphaSelectB,printfResultScratch);
              ((int (*)())psnReportError)(0,"%s.rgb+%s.rgb\n",&srcpTextA,&srcpTextB,alphaUseBitB,alphaSelectC,rgbSelectCRaw,alphaSelectB);
            }
            else if (rgbPreOpKind == '\x03') {
              ((double (*)())FUN_000d10dc)(&srcpTextB,rgbAddrA,instructionNumberArg,aluIndexArg,alphaUseBitB,alphaSelectC,rgbSelectCRaw,alphaSelectB,printfResultScratch);
              ((int (*)())psnReportError)(0,"1.0-%s.rgb\n",&srcpTextB,aluIndexArg,alphaUseBitB,alphaSelectC,rgbSelectCRaw,alphaSelectB);
            }
            else {
              ((int (*)())psnReportError)(0,"???\n",instructionNumberArg,aluIndexArg,alphaUseBitB,alphaSelectC,rgbSelectCRaw,alphaSelectB);
            }
          }
          if (alphaSrcpNeededFlag) {
            instructionNumberArg = instructionNumber;
            aluIndexArg = aluIndex;
            printfResultScratch = (double)((int (*)())psnReportError)(0,"  %d alu %02d pre:  srcp.a   = ",instructionNumber,aluIndex,
                                          alphaUseBitB,alphaSelectC,rgbSelectCRaw,alphaSelectB);
            alphaPreOp = *(char *)((int)instructionRecord2 + 0x3f);
            if (alphaPreOp == '\x01') {
              printfResultScratch = (double)((double (*)())FUN_000d10dc)(&srcpTextB,alphaAddrA,instructionNumberArg,aluIndexArg,alphaUseBitB,alphaSelectC,rgbSelectCRaw,
                                            alphaSelectB,printfResultScratch);
              ((double (*)())FUN_000d10dc)(&srcpTextA,argR8,instructionNumberArg,aluIndexArg,alphaUseBitB,alphaSelectC,rgbSelectCRaw,alphaSelectB,printfResultScratch);
              ((int (*)())psnReportError)(0,"%s.a-%s.a\n",&srcpTextA,&srcpTextB,alphaUseBitB,alphaSelectC,rgbSelectCRaw,alphaSelectB);
            }
            else if (alphaPreOp == '\0') {
              ((double (*)())FUN_000d10dc)(&srcpTextB,alphaAddrA,instructionNumberArg,aluIndexArg,alphaUseBitB,alphaSelectC,rgbSelectCRaw,alphaSelectB,printfResultScratch);
              ((int (*)())psnReportError)(0,"1.0-2.0*%s.a\n",&srcpTextB,aluIndexArg,alphaUseBitB,alphaSelectC,rgbSelectCRaw,alphaSelectB);
            }
            else if (alphaPreOp == '\x02') {
              printfResultScratch = (double)((double (*)())FUN_000d10dc)(&srcpTextB,alphaAddrA,instructionNumberArg,aluIndexArg,alphaUseBitB,alphaSelectC,rgbSelectCRaw,
                                            alphaSelectB,printfResultScratch);
              ((double (*)())FUN_000d10dc)(&srcpTextA,argR8,instructionNumberArg,aluIndexArg,alphaUseBitB,alphaSelectC,rgbSelectCRaw,alphaSelectB,printfResultScratch);
              ((int (*)())psnReportError)(0,"%s.a+%s.a\n",&srcpTextA,&srcpTextB,alphaUseBitB,alphaSelectC,rgbSelectCRaw,alphaSelectB);
            }
            else if (alphaPreOp == '\x03') {
              ((double (*)())FUN_000d10dc)(&srcpTextB,alphaAddrA,instructionNumberArg,aluIndexArg,alphaUseBitB,alphaSelectC,rgbSelectCRaw,alphaSelectB,printfResultScratch);
              ((int (*)())psnReportError)(0,"1.0-%s.a\n",&srcpTextB,aluIndexArg,alphaUseBitB,alphaSelectC,rgbSelectCRaw,alphaSelectB);
            }
            else {
              ((int (*)())psnReportError)(0,"???\n",instructionNumberArg,aluIndexArg,alphaUseBitB,alphaSelectC,rgbSelectCRaw,alphaSelectB);
            }
          }
          rgbDestMaskTextPtr = aluIndex;
          ((int (*)())psnReportError)(0,"  %d alu %02d rgb:  ",instructionNumber,aluIndex,alphaUseBitB,alphaSelectC,rgbSelectCRaw,alphaSelectB);
          rgbOutputWriteMask = (uint)*(byte *)((int)instructionRecord2 + 0x15);
          rgbTempWriteMask2 = *(byte *)(instructionRecord2 + 5);
          if (rgbOutputWriteMask == 0) {
LAB_000d2b24:
            ((int (*)())psnReportError)(0,"           ",rgbOutputWriteMask,rgbDestMaskTextPtr,alphaUseBitB,alphaSelectC,rgbSelectCRaw,alphaSelectB);
          }
          else if (*instructionRecord2 == 3) {
            rgbDestMaskOffset = rgbOutputWriteMask * 4;
            rgbOutputWriteMask = (uint)*(byte *)((int)instructionRecord2 + 0x16);
            rgbDestMaskTextPtr = (uint *)(rgbDestMaskOffset + 0x1dc239);
            ((int (*)())psnReportError)(0,"out%d.%s = ",rgbOutputWriteMask,rgbDestMaskTextPtr,alphaUseBitB,alphaSelectC,rgbSelectCRaw,alphaSelectB);
          }
          else {
            if (*instructionRecord2 != 4) goto LAB_000d2b24;
            rgbOutputWriteMask = rgbOutputWriteMask * 4 + 0x1dc239;
            ((int (*)())psnReportError)(0,"pred.%s = ",rgbOutputWriteMask,rgbDestMaskTextPtr,alphaUseBitB,alphaSelectC,rgbSelectCRaw,alphaSelectB);
            rgbOutIndex = *(char *)((int)instructionRecord2 + 0x16);
            if (rgbOutIndex == '\x01') {
              ((int (*)())psnReportError)(0,"(<) ",rgbOutputWriteMask,rgbDestMaskTextPtr,alphaUseBitB,alphaSelectC,rgbSelectCRaw,alphaSelectB);
            }
            else if (rgbOutIndex == '\0') {
              ((int (*)())psnReportError)(0,"(==) ",rgbOutputWriteMask,rgbDestMaskTextPtr,alphaUseBitB,alphaSelectC,rgbSelectCRaw,alphaSelectB);
            }
            else if (rgbOutIndex == '\x02') {
              ((int (*)())psnReportError)(0,"(>=) ",rgbOutputWriteMask,rgbDestMaskTextPtr,alphaUseBitB,alphaSelectC,rgbSelectCRaw,alphaSelectB);
            }
            else if (rgbOutIndex == '\x03') {
              ((int (*)())psnReportError)(0,"(!=) ",rgbOutputWriteMask,rgbDestMaskTextPtr,alphaUseBitB,alphaSelectC,rgbSelectCRaw,alphaSelectB);
            }
          }
          if (rgbTempWriteMask2 == 0) {
            ((int (*)())psnReportError)(0,"          ",rgbOutputWriteMask,rgbDestMaskTextPtr,alphaUseBitB,alphaSelectC,rgbSelectCRaw,alphaSelectB);
          }
          else {
            rgbOutputWriteMask = (uint)*(ushort *)(instructionRecord2 + 3);
            rgbDestMaskTextPtr = (uint *)((uint)rgbTempWriteMask2 * 4 + 0x1dc239);
            ((int (*)())psnReportError)(0,"r%02d.%s = ",rgbOutputWriteMask,rgbDestMaskTextPtr,alphaUseBitB,alphaSelectC,rgbSelectCRaw,alphaSelectB);
          }
          if (*(char *)((int)instructionRecord2 + 0x33) != '\0') {
            ((int (*)())psnReportError)(0,"clamped ",rgbOutputWriteMask,rgbDestMaskTextPtr,alphaUseBitB,alphaSelectC,rgbSelectCRaw,alphaSelectB);
          }
          operandText1Ptr = operandText1;
          operandAuxWord = CONCAT22(operandAuxHigh,rgbAuxA);
          ((int (*)())FUN_000d13a4)(operandText1Ptr,rgbAddrA,rgbAddrB,rgbAddrC,alphaAddrA,argR8,argR9,rgbSelectABase,rgbModA2,
                       operandAuxWord,(uint)*rgbOpcodePtr);
          operandAuxWord = CONCAT22((short)((uint)operandAuxWord >> 0x10),rgbAuxB);
          argR6 = (char *)operandText6;
          ((int (*)())FUN_000d13a4)(argR6,rgbAddrA,rgbAddrB,rgbAddrC,alphaAddrA,argR8,argR9,rgbSelectBBase,rgbModB2,
                       operandAuxWord,(uint)*rgbOpcodePtr);
          operandText5Ptr = operandText5;
          ((int (*)())FUN_000d13a4)(operandText5Ptr,rgbAddrA,rgbAddrB,rgbAddrC,alphaAddrA,argR8,argR9,rgbSelectCBase,rgbModC2,
                       CONCAT22((short)((uint)operandAuxWord >> 0x10),rgbAuxC),(uint)*rgbOpcodePtr);
          operandText4Ptr = operandText4;
          ((int (*)())FUN_000d1624)(operandText4Ptr,rgbAddrA,rgbAddrB,rgbAddrC,alphaAddrA,argR8,argR9,alphaSelectABase,alphaModA2,
                       alphaAuxB,(uint)*(byte *)alphaOpcodePtr);
          operandText3Ptr = operandText3;
          ((int (*)())FUN_000d1624)(operandText3Ptr,rgbAddrA,rgbAddrB,rgbAddrC,alphaAddrA,argR8,argR9,alphaSelectBBase,alphaModB2,
                       alphaAuxC,(uint)*(byte *)alphaOpcodePtr);
          operandText2Ptr = operandText2;
          alphaSelectCBaseArg = alphaSelectCBase;
          staleStackArg_fffffd2c = alphaAuxD;
          ((int (*)())FUN_000d1624)(operandText2Ptr,rgbAddrA,rgbAddrB,rgbAddrC,alphaAddrA,argR8,argR9,alphaSelectCBase,alphaModC2,
                       alphaAuxD,(uint)*(byte *)alphaOpcodePtr);
          rgbOpcodeByte2 = *rgbOpcodePtr;
          if (rgbOpcodeByte2 < 0xd) {
            argR9 = (char *)(0);
            switch(rgbOpcodeByte2) {
            case 0:
              ((int (*)())psnReportError)(0,"mad(%s, %s, %s)",operandText1Ptr,argR6,operandText5Ptr,argR8,argR9,alphaSelectCBaseArg);
              break;
            case 1:
              ((int (*)())psnReportError)(0,"dp3(%s, %s)",operandText1Ptr,argR6,alphaAddrA,argR8,argR9,alphaSelectCBaseArg);
              operandText5Ptr = alphaAddrA;
              break;
            case 2:
              operandText4Ptr2 = operandText4Ptr;
              operandText5Ptr = (uint *)argR6;
              argR8 = operandText3Ptr;
              ((int (*)())psnReportError)(0,"dp4(%s:%s, %s:%s)",operandText1Ptr,operandText4Ptr,argR6,operandText3Ptr,argR9,alphaSelectCBaseArg);
              argR6 = (char *)operandText4Ptr2;
              break;
            case 3:
              ((int (*)())psnReportError)(0,"d2a(%s, %s, %s)",operandText1Ptr,argR6,operandText5Ptr,argR8,argR9,alphaSelectCBaseArg);
              break;
            case 4:
              ((int (*)())psnReportError)(0,"min(%s, %s)",operandText1Ptr,argR6,alphaAddrA,argR8,argR9,alphaSelectCBaseArg);
              operandText5Ptr = alphaAddrA;
              break;
            case 5:
              ((int (*)())psnReportError)(0,"max(%s, %s)",operandText1Ptr,argR6,alphaAddrA,argR8,argR9,alphaSelectCBaseArg);
              operandText5Ptr = alphaAddrA;
              break;
            case 6:
              goto switchD_000d2d30_caseD_6;
            case 7:
              ((int (*)())psnReportError)(0,"cnd(%s, %s, %s)",operandText1Ptr,argR6,operandText5Ptr,argR8,argR9,alphaSelectCBaseArg);
              break;
            case 8:
              ((int (*)())psnReportError)(0,"cmp(%s, %s, %s)",operandText1Ptr,argR6,operandText5Ptr,argR8,argR9,alphaSelectCBaseArg);
              break;
            case 9:
              ((int (*)())psnReportError)(0,"frc(%s)",operandText1Ptr,rgbAddrC,alphaAddrA,argR8,argR9,alphaSelectCBaseArg);
              argR6 = (char *)rgbAddrC;
              operandText5Ptr = alphaAddrA;
              break;
            case 10:
              ((int (*)())psnReportError)(0,"sop()",rgbAddrB,rgbAddrC,alphaAddrA,argR8,argR9,alphaSelectCBaseArg);
              operandText1Ptr = rgbAddrB;
              argR6 = (char *)rgbAddrC;
              operandText5Ptr = alphaAddrA;
              break;
            case 0xb:
              ((int (*)())psnReportError)(0,"mdh(%s, %s)",operandText1Ptr,argR6,alphaAddrA,argR8,argR9,alphaSelectCBaseArg);
              operandText5Ptr = alphaAddrA;
              break;
            case 0xc:
              ((int (*)())psnReportError)(0,"mdv(%s, %s)",operandText1Ptr,argR6,alphaAddrA,argR8,argR9,alphaSelectCBaseArg);
              operandText5Ptr = alphaAddrA;
            }
          }
          else {
switchD_000d2d30_caseD_6:
            ((int (*)())psnReportError)(0,"???()",rgbAddrB,rgbAddrC,alphaAddrA,argR8,argR9,alphaSelectCBaseArg);
            operandText1Ptr = rgbAddrB;
            argR6 = (char *)rgbAddrC;
            operandText5Ptr = alphaAddrA;
          }
          rgbOutputScaleByte2 = *(byte *)((int)instructionRecord2 + 0x32);
          if (rgbOutputScaleByte2 < 7) {
            argR9 = (char *)(0);
            switch(rgbOutputScaleByte2) {
            case 1:
              ((int (*)())psnReportError)(0,"*2",operandText1Ptr,argR6,operandText5Ptr,argR8,argR9,alphaSelectCBaseArg);
              break;
            case 2:
              ((int (*)())psnReportError)(0,"*4",operandText1Ptr,argR6,operandText5Ptr,argR8,argR9,alphaSelectCBaseArg);
              break;
            case 3:
              ((int (*)())psnReportError)(0,"*8",operandText1Ptr,argR6,operandText5Ptr,argR8,argR9,alphaSelectCBaseArg);
              break;
            case 4:
              ((int (*)())psnReportError)(0,"/2",operandText1Ptr,argR6,operandText5Ptr,argR8,argR9,alphaSelectCBaseArg);
              break;
            case 5:
              ((int (*)())psnReportError)(0,"/4",operandText1Ptr,argR6,operandText5Ptr,argR8,argR9,alphaSelectCBaseArg);
              break;
            case 6:
              ((int (*)())psnReportError)(0,"/8",operandText1Ptr,argR6,operandText5Ptr,argR8,argR9,alphaSelectCBaseArg);
            }
          }
          else {
            ((int (*)())psnReportError)(0,"*???",operandText1Ptr,argR6,operandText5Ptr,argR8,argR9,alphaSelectCBaseArg);
          }
          if (((*(unsigned char *)((unsigned char *)&(semWaitText) + 0)) != '\0') || ((*(unsigned char *)((unsigned char *)&(aluWaitText) + 0)) != '\0')) {
            operandText1Ptr = &semWaitText;
            argR6 = (char *)&aluWaitText;
            ((int (*)())psnReportError)(0,"%s%s",operandText1Ptr,argR6,operandText5Ptr,argR8,argR9,alphaSelectCBaseArg);
          }
          argR10 = (byte *)((int)instructionRecord2 + 5);
          if (*(char *)((int)instructionRecord2 + 5) != '\0') {
            if (*(char *)((int)instructionRecord2 + 6) == '\0') {
              (*(unsigned int *)((unsigned char *)&(predicateText) + 0)) = CONCAT21(0x7000,(*(unsigned char *)((unsigned char *)&(predicateText) + 2)));
            }
            else {
              argR9 = "!p";
              (*(unsigned int *)((unsigned char *)&(predicateText) + 0)) = CONCAT12(s__p_001a74dc[0],(*(unsigned short *)((unsigned char *)&(s__p_001a74dc) + 1)));
            }
            predicateModeByte2 = *argR10;
            if (predicateModeByte2 < 6) {
              argR9 = (char *)(0);
              switch(predicateModeByte2) {
              case 1:
                operandText1Ptr = &predicateText;
                ((int (*)())psnReportError)(0," %s.rgb",operandText1Ptr,argR6,operandText5Ptr,argR8,argR9,argR10);
                break;
              case 2:
                operandText1Ptr = &predicateText;
                ((int (*)())psnReportError)(0," %s.rrr",operandText1Ptr,argR6,operandText5Ptr,argR8,argR9,argR10);
                break;
              case 3:
                operandText1Ptr = &predicateText;
                ((int (*)())psnReportError)(0," %s.ggg",operandText1Ptr,argR6,operandText5Ptr,argR8,argR9,argR10);
                break;
              case 4:
                operandText1Ptr = &predicateText;
                ((int (*)())psnReportError)(0," %s.bbb",operandText1Ptr,argR6,operandText5Ptr,argR8,argR9,argR10);
                break;
              case 5:
                operandText1Ptr = &predicateText;
                ((int (*)())psnReportError)(0," %s.aaa",operandText1Ptr,argR6,operandText5Ptr,argR8,argR9,argR10);
              }
            }
          }
          ((int (*)())psnReportError)(0,"\n",operandText1Ptr,argR6,operandText5Ptr,argR8,argR9,argR10);
          neutralLineArg0 = aluIndex;
          ((int (*)())psnReportError)(0,"         alpha:  ",aluIndex,argR6,operandText5Ptr,argR8,argR9,argR10);
          alphaTempEnable = *(char *)(instructionRecord2 + 8);
          alphaOutputEnableFlag2 = *(char *)((int)instructionRecord2 + 0x21) != '\0';
          depthWrite = *(char *)((int)instructionRecord2 + 0x23);
          if (alphaOutputEnableFlag2) {
            if (*instructionRecord2 == 3) {
              neutralLineArg0 = (uint *)(uint)*(byte *)((int)instructionRecord2 + 0x22);
              ((int (*)())psnReportError)(0,"out%d.a   = ",neutralLineArg0,argR6,operandText5Ptr,argR8,argR9,argR10);
            }
            else if (*instructionRecord2 == 4) {
              ((int (*)())psnReportError)(0,"pred.a   = ",neutralLineArg0,argR6,operandText5Ptr,argR8,argR9,argR10);
              alphaOutIndex = *(char *)((int)instructionRecord2 + 0x22);
              if (alphaOutIndex == '\x01') {
                ((int (*)())psnReportError)(0,"(<) ",neutralLineArg0,argR6,operandText5Ptr,argR8,argR9,argR10);
              }
              else if (alphaOutIndex == '\0') {
                ((int (*)())psnReportError)(0,"(==) ",neutralLineArg0,argR6,operandText5Ptr,argR8,argR9,argR10);
              }
              else if (alphaOutIndex == '\x02') {
                ((int (*)())psnReportError)(0,"(>=) ",neutralLineArg0,argR6,operandText5Ptr,argR8,argR9,argR10);
              }
              else if (alphaOutIndex == '\x03') {
                ((int (*)())psnReportError)(0,"(!=) ",neutralLineArg0,argR6,operandText5Ptr,argR8,argR9,argR10);
              }
            }
          }
          depthWriteFlag2 = depthWrite != '\0';
          if (depthWriteFlag2) {
            ((int (*)())psnReportError)(0,"depth    = ",neutralLineArg0,argR6,operandText5Ptr,argR8,argR9,argR10);
          }
          if ((!alphaOutputEnableFlag2) && (!depthWriteFlag2)) {
            ((int (*)())psnReportError)(0,"           ",neutralLineArg0,argR6,operandText5Ptr,argR8,argR9,argR10);
          }
          if (alphaTempEnable == '\0') {
            ((int (*)())psnReportError)(0,"          ",neutralLineArg0,argR6,operandText5Ptr,argR8,argR9,argR10);
          }
          else {
            neutralLineArg0 = (uint *)(uint)*(ushort *)(instructionRecord2 + 6);
            ((int (*)())psnReportError)(0,"r%02d.a   = ",neutralLineArg0,argR6,operandText5Ptr,argR8,argR9,argR10);
          }
          if (*(char *)((int)instructionRecord2 + 0x42) != '\0') {
            ((int (*)())psnReportError)(0,"clamped ",neutralLineArg0,argR6,operandText5Ptr,argR8,argR9,argR10);
          }
          alphaOpcodeByte2 = *(byte *)alphaOpcodePtr;
          if (alphaOpcodeByte2 < 0x10) {
            argR9 = (char *)(0);
            switch(alphaOpcodeByte2) {
            case 0:
              neutralLineArg0 = operandText4Ptr;
              argR6 = (char *)operandText3Ptr;
              operandText5Ptr = operandText2Ptr;
              ((int (*)())psnReportError)(0,"mad(%s, %s, %s)",operandText4Ptr,operandText3Ptr,operandText2Ptr,argR8,argR9,argR10);
              break;
            case 1:
              ((int (*)())psnReportError)(0,"dp()",neutralLineArg0,argR6,operandText5Ptr,argR8,argR9,argR10);
              break;
            case 2:
              neutralLineArg0 = operandText4Ptr;
              argR6 = (char *)operandText3Ptr;
              ((int (*)())psnReportError)(0,"min(%s, %s)",operandText4Ptr,operandText3Ptr,operandText5Ptr,argR8,argR9,argR10);
              break;
            case 3:
              neutralLineArg0 = operandText4Ptr;
              argR6 = (char *)operandText3Ptr;
              ((int (*)())psnReportError)(0,"max(%s, %s)",operandText4Ptr,operandText3Ptr,operandText5Ptr,argR8,argR9,argR10);
              break;
            case 4:
              goto switchD_000d324c_caseD_4;
            case 5:
              neutralLineArg0 = operandText4Ptr;
              argR6 = (char *)operandText3Ptr;
              operandText5Ptr = operandText2Ptr;
              ((int (*)())psnReportError)(0,"cnd(%s, %s, %s)",operandText4Ptr,operandText3Ptr,operandText2Ptr,argR8,argR9,argR10);
              break;
            case 6:
              neutralLineArg0 = operandText4Ptr;
              argR6 = (char *)operandText3Ptr;
              operandText5Ptr = operandText2Ptr;
              ((int (*)())psnReportError)(0,"cmp(%s, %s, %s)",operandText4Ptr,operandText3Ptr,operandText2Ptr,argR8,argR9,argR10);
              break;
            case 7:
              neutralLineArg0 = operandText4Ptr;
              ((int (*)())psnReportError)(0,"frc(%s)",operandText4Ptr,argR6,operandText5Ptr,argR8,argR9,argR10);
              break;
            case 8:
              neutralLineArg0 = operandText4Ptr;
              ((int (*)())psnReportError)(0,"ex2(%s)",operandText4Ptr,argR6,operandText5Ptr,argR8,argR9,argR10);
              break;
            case 9:
              neutralLineArg0 = operandText4Ptr;
              ((int (*)())psnReportError)(0,"ln2(%s)",operandText4Ptr,argR6,operandText5Ptr,argR8,argR9,argR10);
              break;
            case 10:
              neutralLineArg0 = operandText4Ptr;
              ((int (*)())psnReportError)(0,"rcp(%s)",operandText4Ptr,argR6,operandText5Ptr,argR8,argR9,argR10);
              break;
            case 0xb:
              neutralLineArg0 = operandText4Ptr;
              ((int (*)())psnReportError)(0,"rsq(%s)",operandText4Ptr,argR6,operandText5Ptr,argR8,argR9,argR10);
              break;
            case 0xc:
              neutralLineArg0 = operandText4Ptr;
              ((int (*)())psnReportError)(0,"sin(%s)",operandText4Ptr,argR6,operandText5Ptr,argR8,argR9,argR10);
              break;
            case 0xd:
              neutralLineArg0 = operandText4Ptr;
              ((int (*)())psnReportError)(0,"cos(%s)",operandText4Ptr,argR6,operandText5Ptr,argR8,argR9,argR10);
              break;
            case 0xe:
              neutralLineArg0 = operandText4Ptr;
              argR6 = (char *)operandText3Ptr;
              ((int (*)())psnReportError)(0,"mdh(%s, %s)",operandText4Ptr,operandText3Ptr,operandText5Ptr,argR8,argR9,argR10);
              break;
            case 0xf:
              neutralLineArg0 = operandText4Ptr;
              argR6 = (char *)operandText3Ptr;
              ((int (*)())psnReportError)(0,"mdv(%s, %s)",operandText4Ptr,operandText3Ptr,operandText5Ptr,argR8,argR9,argR10);
            }
          }
          else {
switchD_000d324c_caseD_4:
            ((int (*)())psnReportError)(0,"???()",neutralLineArg0,argR6,operandText5Ptr,argR8,argR9,argR10);
          }
          alphaOutputScaleByte2 = *(byte *)((int)instructionRecord2 + 0x41);
          if (alphaOutputScaleByte2 < 7) {
            argR9 = (char *)(0);
            switch(alphaOutputScaleByte2) {
            case 0:
              ((int (*)())psnReportError)(0," ",neutralLineArg0,argR6,operandText5Ptr,argR8,argR9,argR10);
              break;
            case 1:
              ((int (*)())psnReportError)(0,"*2",neutralLineArg0,argR6,operandText5Ptr,argR8,argR9,argR10);
              break;
            case 2:
              ((int (*)())psnReportError)(0,"*4",neutralLineArg0,argR6,operandText5Ptr,argR8,argR9,argR10);
              break;
            case 3:
              ((int (*)())psnReportError)(0,"*8",neutralLineArg0,argR6,operandText5Ptr,argR8,argR9,argR10);
              break;
            case 4:
              ((int (*)())psnReportError)(0,"/2",neutralLineArg0,argR6,operandText5Ptr,argR8,argR9,argR10);
              break;
            case 5:
              ((int (*)())psnReportError)(0,"/4",neutralLineArg0,argR6,operandText5Ptr,argR8,argR9,argR10);
              break;
            case 6:
              ((int (*)())psnReportError)(0,"/8",neutralLineArg0,argR6,operandText5Ptr,argR8,argR9,argR10);
            }
          }
          else {
            ((int (*)())psnReportError)(0,"*???",neutralLineArg0,argR6,operandText5Ptr,argR8,argR9,argR10);
          }
          if (*(char *)((int)instructionRecord2 + 10) == '\0') {
            argR10 = (byte *)((int)instructionRecord2 + 7);
            if (*(char *)((int)instructionRecord2 + 7) != '\0') {
              if (*(char *)(instructionRecord2 + 2) == '\0') {
                (*(unsigned int *)((unsigned char *)&(predicateText) + 0)) = CONCAT21(0x7000,(*(unsigned char *)((unsigned char *)&(predicateText) + 2)));
              }
              else {
                argR9 = "!p";
                (*(unsigned int *)((unsigned char *)&(predicateText) + 0)) = CONCAT12(s__p_001a74dc[0],(*(unsigned short *)((unsigned char *)&(s__p_001a74dc) + 1)));
              }
              predicateModeByteAlpha2 = *argR10;
              if (predicateModeByteAlpha2 < 6) {
                argR9 = (char *)(0);
                switch(predicateModeByteAlpha2) {
                case 0:
                  break;
                default:
                  neutralLineArg0 = &predicateText;
                  ((int (*)())psnReportError)(0," %s.a",neutralLineArg0,argR6,operandText5Ptr,argR8,argR9,argR10);
                  break;
                case 2:
                  neutralLineArg0 = &predicateText;
                  ((int (*)())psnReportError)(0," %s.r",neutralLineArg0,argR6,operandText5Ptr,argR8,argR9,argR10);
                  break;
                case 3:
                  neutralLineArg0 = &predicateText;
                  ((int (*)())psnReportError)(0," %s.g",neutralLineArg0,argR6,operandText5Ptr,argR8,argR9,argR10);
                  break;
                case 4:
                  neutralLineArg0 = &predicateText;
                  ((int (*)())psnReportError)(0," %s.b",neutralLineArg0,argR6,operandText5Ptr,argR8,argR9,argR10);
                }
              }
            }
            if (*(char *)((int)instructionRecord2 + 9) != '\0') {
              ((int (*)())psnReportError)(0," write_inactive",neutralLineArg0,argR6,operandText5Ptr,argR8,argR9,argR10);
            }
            ((int (*)())psnReportError)(0," \n",neutralLineArg0,argR6,operandText5Ptr,argR8,argR9,argR10);
          }
          else {
            ((int (*)())psnReportError)(0," last\n",neutralLineArg0,argR6,operandText5Ptr,argR8,argR9,argR10);
          }
          if (*(char *)(instructionRecord2 + 0xd) != '\0') {
            neutralLineArg0 = aluIndex;
            ((int (*)())psnReportError)(0,"   alu %02d post-NOP\n",aluIndex,argR6,operandText5Ptr,argR8,argR9,argR10
                        );
          }
          recordKind2 = *instructionRecord2;
          aluIndex = (uint *)((int)aluIndex + 1);
        }
        if (recordKind2 == 5) {
          if (cfCompareCode == 1) {
            argR9 = "lt";
            srcpTextB = CONCAT12(s_lt_001a77dc[0],(*(unsigned short *)((unsigned char *)&(s_lt_001a77dc) + 1)));
          }
          else if (cfCompareCode == 0) {
            argR9 = "eq";
            srcpTextB = CONCAT12(s_eq_001a77d8[0],(*(unsigned short *)((unsigned char *)&(s_eq_001a77d8) + 1)));
          }
          else if (cfCompareCode == 2) {
            argR9 = "ge";
            srcpTextB = CONCAT12(s_ge_001a77e0[0],(*(unsigned short *)((unsigned char *)&(s_ge_001a77e0) + 1)));
          }
          else if (cfCompareCode == 3) {
            argR9 = "ne";
            srcpTextB = CONCAT12(s_ne_001a77e4[0],(*(unsigned short *)((unsigned char *)&(s_ne_001a77e4) + 1)));
          }
          else {
            srcpTextB = CONCAT21(0x2000,srcpTextBPad);
          }
          if (cfPrevAluDest == 0) {
            srcpTextA = 0x72656400;
          }
          else if (cfPrevAluDest == 1) {
            argR9 = "alpha";
            (*(unsigned char *)((unsigned char *)&(srcpTextA) + 0)) = s_alpha_001a77e8[0];
            (*(unsigned char *)((unsigned char *)&(srcpTextA) + 1)) = s_alpha_001a77e8[1];
            (*(unsigned char *)((unsigned char *)&(srcpTextA) + 2)) = s_alpha_001a77e8[2];
            (*(unsigned char *)((unsigned char *)&(srcpTextA) + 3)) = s_alpha_001a77e8[3];
            srcpTextATail[0] = s_alpha_001a77e8[4];
            srcpTextATail[1] = s_alpha_001a77e8[5];
          }
          else {
            srcpTextA = CONCAT22(0x2000,(*(unsigned short *)((unsigned char *)&(srcpTextA) + 2)));
          }
          argR6 = (char *)cfWordText;
          ((int (*)())psnReportError)(0,"  %d cf  %02d    :  ",instructionNumber,cfIndex,cfCompareCode,argR8,argR9,argR10);
          staleStackArg_fffffd2c = (uint *)0x0;
          argR10 = (byte *)((uint)*(byte *)((int)instructionRecord2 + 0x15) * 10 + 0x1dc1bc);
          argR9 = (char *)((uint)*(byte *)(instructionRecord2 + 5) * 10 + 0x1dc1bc);
          printf_LDBLStub_1a32d0(argR6,"0x%02x %1d %s %s %s %s %1d %1d %d",
                       (uint)*(byte *)((int)instructionRecord2 + 0x12),(uint)*(byte *)(instructionRecord2 + 4),
                       (uint)*(byte *)((int)instructionRecord2 + 0xe) * 10 + 0x1dc1e9,
                       (uint)*(byte *)((int)instructionRecord2 + 0x11) * 5 + 0x1dc1da,argR9,argR10);
          if (PTR_s_0x55_0_JUMP_NONE_NONE_NONE_001dc2d0 == (undefined *)0x0) {
            cfOpTableIndex = 0;
          }
          else {
            cfOpNameCursor = &PTR_s_0xaa_0_JUMP_NONE_NONE_NONE_001dc2d8;
            cfOpTableIndex = 0;
            cfOpNameEntry = PTR_s_0x55_0_JUMP_NONE_NONE_NONE_001dc2d0;
            do {
              cfNameLength = _strlen(cfOpNameEntry);
              cfNameCompare = _strncmp(cfOpNameEntry,argR6,cfNameLength);
              if (cfNameCompare == 0) break;
              cfOpNameEntry = *cfOpNameCursor;
              cfOpTableIndex = cfOpTableIndex + 2;
              cfOpNameCursor = cfOpNameCursor + 2;
            } while (cfOpNameEntry != (undefined *)0x0);
          }
          neutralLineArg0 = (uint *)(PTR_s_IF_b_001dc2cc)[cfOpTableIndex];
          semWaitTextPtr = &semWaitText;
          argR8 = &aluWaitText;
          ((int (*)())psnReportError)(0,"%s(%s)%s%s",neutralLineArg0,argR6,semWaitTextPtr,argR8,argR9,argR10);
          cfAddressByte = *(char *)((int)instructionRecord2 + 0x12);
          if ((cfAddressByte == -0x10) || (cfAddressByte == '\x0f')) {
            neutralLineArg0 = &srcpTextA;
            argR6 = (char *)&srcpTextB;
            ((int (*)())psnReportError)(0,"( prev_alu: %s %s )\n",neutralLineArg0,argR6,semWaitTextPtr,argR8,argR9,argR10);
          }
          else if ((cfAddressByte == -0x56) || (cfAddressByte == 'U')) {
            neutralLineArg0 = (uint *)(uint)*(byte *)((int)instructionRecord2 + 0x17);
            ((int (*)())psnReportError)(0,"( bool_addr: %d )\n",neutralLineArg0,argR6,semWaitTextPtr,argR8,argR9,argR10);
          }
          else {
            ((int (*)())psnReportError)(0,"\n",neutralLineArg0,argR6,semWaitTextPtr,argR8,argR9,argR10);
          }
          cfIndex = cfIndex + 1;
        }
        rsRecordNumber2 = rsRecordNumber2 + 1;
        instructionRecord2 = instructionRecord2 + 0x12;
        instructionNumber = instructionNumber + 1;
        neutralRecordCountArg = recordCount2;
      } while (rsRecordNumber2 <= (int)recordCount2);
    }
    ((int (*)())psnReportError)(0,blankLineFormatOffset + 0x5b00,neutralLineArg0,argR6,neutralRecordCountArg,argR8,argR9,argR10);
    ((int (*)())psnReportError)(0,"======== End r520 neutral format pixel shader =============\n",neutralLineArg0,argR6,
                 neutralRecordCountArg,argR8,argR9,argR10);
  }
  return;
}

/* psnClearSinkRecord @ 0xd4de8 (16 bytes) */
int psnClearSinkRecord(param_1)
  undefined4 *param_1;
{
  param_1[1] = 0;
  *param_1 = 0;
  return;
}

/* psnClearSinkRecord2 @ 0xd4df8 (16 bytes) */
int psnClearSinkRecord2(param_1)
  undefined4 *param_1;
{
  param_1[1] = 0;
  *param_1 = 0;
  return;
}

