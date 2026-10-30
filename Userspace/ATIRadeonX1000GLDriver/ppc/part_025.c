#include "decls.h"

/* SelectWord__areCompatible @ 0xf2d18 (144 bytes) */
int SelectWord__areCompatible(selectA, selectB)
  uint selectA;
  uint selectB;
{
  uint laneB;
  uint laneA;
  
  if (((((selectA >> 0x18 == 4) || (selectB >> 0x18 == 4)) || (selectA >> 0x18 == selectB >> 0x18))
      && ((((laneA = selectA >> 0x10 & 0xff, laneA == 4 ||
            (laneB = selectB >> 0x10 & 0xff, laneB == 4)) || (laneA == laneB)) &&
          (((laneA = selectA >> 8 & 0xff, laneA == 4 || (laneB = selectB >> 8 & 0xff, laneB == 4))
           || (laneA == laneB)))))) &&
     ((((selectA & 0xff) == 4 || ((selectB & 0xff) == 4)) || ((selectA & 0xff) == (selectB & 0xff)))
     )) {
    return 1;
  }
  return 0;
}

/* SelectWord__matches @ 0xf2da8 (112 bytes) */
int SelectWord__matches(selectWord, pattern)
  uint selectWord;
  uint pattern;
{
  uint uVar1;
  
  if (((((pattern >> 0x18 == 4) || (pattern >> 0x18 == selectWord >> 0x18)) &&
       ((uVar1 = pattern >> 0x10 & 0xff, uVar1 == 4 || (uVar1 == (selectWord >> 0x10 & 0xff))))) &&
      ((uVar1 = pattern >> 8 & 0xff, uVar1 == 4 || (uVar1 == (selectWord >> 8 & 0xff))))) &&
     (((pattern & 0xff) == 4 || ((pattern & 0xff) == (selectWord & 0xff))))) {
    return 1;
  }
  return 0;
}

/* SelectWord__hasNonzeroLaneBytes @ 0xf2e18 (56 bytes) */
int SelectWord__hasNonzeroLaneBytes(selectWord)
  uint selectWord;
{
  if ((((selectWord >> 0x18 == 0) || ((selectWord >> 0x10 & 0xff) == 0)) || ((selectWord >> 8 & 0xff) == 0))
     && ((selectWord & 0xff) == 0)) {
    return 0;
  }
  return 1;
}

/* laneBytes__mapTwoThreeToOne @ 0xf2e50 (72 bytes) */
int laneBytes__mapTwoThreeToOne(outBytes, laneBytes)
  undefined4 *outBytes;
  undefined4 laneBytes;
{
  unsigned int ghidra_home[8] = { outBytes, laneBytes, 0, 0, 0, 0, 0, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  char *laneCursor;
  int loopCounter;
  
  (*(unsigned int *)((unsigned char *)ghidra_home + 4)) = laneBytes;
  loopCounter = 4;
  laneCursor = (char *)&(*(unsigned int *)((unsigned char *)ghidra_home + 4));
  do {
    if ((byte)(*laneCursor - 2U) < 2) {
      *laneCursor = '\x01';
    }
    laneCursor = laneCursor + 1;
    loopCounter = loopCounter + -1;
  } while (loopCounter != 0);
  *outBytes = (*(unsigned int *)((unsigned char *)ghidra_home + 4));
  return outBytes;
}

/* laneBytes__mergeOneAndTwo @ 0xf2e98 (144 bytes) */
int laneBytes__mergeOneAndTwo(outBytes, laneBytes)
  undefined4 *outBytes;
  undefined4 laneBytes;
{
  int loopCounter;
  unsigned int ghidra_home[8] = { outBytes, laneBytes, 0, 0, 0, 0, 0, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  bool hasOne;
  bool hasTwo;
  char *laneStart;
  char *laneCursor;
  int laneSpan;
  
  laneStart = (char *)&(*(unsigned int *)((unsigned char *)ghidra_home + 4));
  loopCounter = 4;
  (*(unsigned int *)((unsigned char *)ghidra_home + 4)) = laneBytes;
  hasOne = false;
  hasTwo = false;
  laneCursor = laneStart;
  do {
    if (*laneCursor == '\x02') {
      hasTwo = true;
    }
    else if (*laneCursor == '\x01') {
      hasOne = true;
    }
    laneCursor = laneCursor + 1;
    loopCounter = loopCounter + -1;
  } while (loopCounter != 0);
  if ((hasOne) && (hasTwo)) {
    laneSpan = (int)laneCursor - (int)laneStart;
    do {
      if (*laneStart == '\x01') {
        *laneStart = '\x03';
      }
      laneStart = laneStart + 1;
      laneSpan = laneSpan + -1;
    } while (laneSpan != 0);
  }
  *outBytes = (*(unsigned int *)((unsigned char *)ghidra_home + 4));
  return outBytes;
}

/* SelectWord__markLanesWhereSecondIsOne @ 0xf2f28 (92 bytes) */
int SelectWord__markLanesWhereSecondIsOne(result, selectWordA, selectWordB)
  undefined4 *result;
  undefined4 selectWordA;
  undefined4 selectWordB;
{
  unsigned int ghidra_home[8] = { result, selectWordA, selectWordB, 0, 0, 0, 0, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  char *laneACursor;
  char *laneBCursor;
  int loopCounter;
  
  (*(unsigned int *)((unsigned char *)ghidra_home + 4)) = selectWordA;
  loopCounter = 4;
  (*(unsigned int *)((unsigned char *)ghidra_home + 8)) = selectWordB;
  laneACursor = (char *)&(*(unsigned int *)((unsigned char *)ghidra_home + 4));
  laneBCursor = (char *)&(*(unsigned int *)((unsigned char *)ghidra_home + 8));
  do {
    if ((1 < (byte)(*laneACursor - 2U)) && (*laneBCursor == '\x01')) {
      *laneACursor = '\x01';
    }
    laneACursor = laneACursor + 1;
    laneBCursor = laneBCursor + 1;
    loopCounter = loopCounter + -1;
  } while (loopCounter != 0);
  *result = (*(unsigned int *)((unsigned char *)ghidra_home + 4));
  return result;
}

/* SelectWord__mergeWrittenLanes @ 0xf2f84 (92 bytes) */
int SelectWord__mergeWrittenLanes(outWord, stateBytes, writtenBytes)
  undefined4 *outWord;
  undefined4 stateBytes;
  undefined4 writtenBytes;
{
  unsigned int ghidra_home[8] = { outWord, stateBytes, writtenBytes, 0, 0, 0, 0, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  char *stateCursor;
  char *writtenCursor;
  int loopCounter;
  
  (*(unsigned int *)((unsigned char *)ghidra_home + 4)) = stateBytes;
  loopCounter = 4;
  (*(unsigned int *)((unsigned char *)ghidra_home + 8)) = writtenBytes;
  stateCursor = (char *)&(*(unsigned int *)((unsigned char *)ghidra_home + 4));
  writtenCursor = (char *)&(*(unsigned int *)((unsigned char *)ghidra_home + 8));
  do {
    if ((1 < (byte)(*stateCursor - 2U)) && (*writtenCursor == '\0')) {
      *stateCursor = '\0';
    }
    stateCursor = stateCursor + 1;
    writtenCursor = writtenCursor + 1;
    loopCounter = loopCounter + -1;
  } while (loopCounter != 0);
  *outWord = (*(unsigned int *)((unsigned char *)ghidra_home + 4));
  return outWord;
}

/* SelectWord__fillUnusedLanes @ 0xf2fe0 (76 bytes) */
int SelectWord__fillUnusedLanes(outSelect, selectA, selectB)
  undefined4 *outSelect;
  undefined4 selectA;
  undefined4 selectB;
{
  unsigned int ghidra_home[8] = { outSelect, selectA, selectB, 0, 0, 0, 0, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  char *laneACursor;
  char *laneBCursor;
  int loopCounter;
  
  (*(unsigned int *)((unsigned char *)ghidra_home + 4)) = selectA;
  loopCounter = 4;
  (*(unsigned int *)((unsigned char *)ghidra_home + 8)) = selectB;
  laneACursor = (char *)&(*(unsigned int *)((unsigned char *)ghidra_home + 4));
  laneBCursor = (char *)&(*(unsigned int *)((unsigned char *)ghidra_home + 8));
  do {
    if (*laneACursor == '\x04') {
      *laneACursor = *laneBCursor;
    }
    laneACursor = laneACursor + 1;
    laneBCursor = laneBCursor + 1;
    loopCounter = loopCounter + -1;
  } while (loopCounter != 0);
  *outSelect = (*(unsigned int *)((unsigned char *)ghidra_home + 4));
  return outSelect;
}

/* SelectWord__markEqualLanes @ 0xf302c (96 bytes) */
int SelectWord__markEqualLanes(result, selectWordA, selectWordB)
  undefined4 *result;
  undefined4 selectWordA;
  undefined4 selectWordB;
{
  unsigned int ghidra_home[8] = { result, selectWordA, selectWordB, 0, 0, 0, 0, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  char laneB;
  char *laneBCursor;
  char *laneACursor;
  int loopCounter;
  
  (*(unsigned int *)((unsigned char *)ghidra_home + 4)) = selectWordA;
  loopCounter = 4;
  (*(unsigned int *)((unsigned char *)ghidra_home + 8)) = selectWordB;
  laneACursor = (char *)&(*(unsigned int *)((unsigned char *)ghidra_home + 4));
  laneBCursor = (char *)&(*(unsigned int *)((unsigned char *)ghidra_home + 8));
  do {
    laneB = *laneBCursor;
    if (((laneB == *laneACursor) && (laneB != '\x03')) && (laneB != '\x02')) {
      *laneACursor = '\x01';
    }
    laneACursor = laneACursor + 1;
    laneBCursor = laneBCursor + 1;
    loopCounter = loopCounter + -1;
  } while (loopCounter != 0);
  *result = (*(unsigned int *)((unsigned char *)ghidra_home + 4));
  return result;
}

/* laneBytes__commonSelect @ 0xf308c (72 bytes) */
int laneBytes__commonSelect(selectWord)
  undefined4 selectWord;
{
  unsigned int ghidra_home[8] = { selectWord, 0, 0, 0, 0, 0, 0, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  uint laneByte;
  byte *laneCursor;
  uint commonLane;
  uint nextCommonLane;
  int loopCounter;
  
  (*(unsigned int *)((unsigned char *)ghidra_home + 0)) = selectWord;
  loopCounter = 4;
  laneCursor = (byte *)&(*(unsigned int *)((unsigned char *)ghidra_home + 0));
  commonLane = 0xffffffff;
  while (((laneByte = (uint)*laneCursor, nextCommonLane = commonLane, laneByte == 4 || (nextCommonLane = laneByte, (int)commonLane < 0)) ||
         (laneByte == commonLane))) {
    laneCursor = laneCursor + 1;
    loopCounter = loopCounter + -1;
    commonLane = nextCommonLane;
    if (loopCounter == 0) {
      return nextCommonLane;
    }
  }
  return 0xffffffff;
}

/* SelectWord__firstWrittenComponent @ 0xf30d4 (52 bytes) */
int SelectWord__firstWrittenComponent(selectWord)
  undefined4 selectWord;
{
  unsigned int ghidra_home[8] = { selectWord, 0, 0, 0, 0, 0, 0, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  char *laneCursor;
  int loopCounter;
  int loopCounterB;
  
  (*(unsigned int *)((unsigned char *)ghidra_home + 0)) = selectWord;
  loopCounterB = 4;
  loopCounter = 0;
  laneCursor = (char *)&(*(unsigned int *)((unsigned char *)ghidra_home + 0));
  do {
    if (*laneCursor != '\x01') {
      return loopCounter;
    }
    loopCounter = loopCounter + 1;
    laneCursor = laneCursor + 1;
    loopCounterB = loopCounterB + -1;
  } while (loopCounterB != 0);
  return -1;
}

/* SelectWord__firstUnwrittenComponent @ 0xf3108 (52 bytes) */
int SelectWord__firstUnwrittenComponent(selectWord)
  undefined4 selectWord;
{
  unsigned int ghidra_home[8] = { selectWord, 0, 0, 0, 0, 0, 0, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  char *laneCursor;
  int loopCounter;
  int loopCounterB;
  
  (*(unsigned int *)((unsigned char *)ghidra_home + 0)) = selectWord;
  loopCounterB = 4;
  loopCounter = 0;
  laneCursor = (char *)&(*(unsigned int *)((unsigned char *)ghidra_home + 0));
  do {
    if (*laneCursor == '\x01') {
      return loopCounter;
    }
    loopCounter = loopCounter + 1;
    laneCursor = laneCursor + 1;
    loopCounterB = loopCounterB + -1;
  } while (loopCounterB != 0);
  return -1;
}

/* IRInst__isLaneWritten @ 0xf313c (24 bytes) */
int IRInst__isLaneWritten(inst, componentIndex)
  int inst;
  int componentIndex;
{
  return -(uint)(*(byte *)(componentIndex + inst + 0x9c) ^ 1) >> 0x1f;
}

/* IRInst__writesAllLanes @ 0xf3154 (60 bytes) */
int IRInst__writesAllLanes(inst)
  int inst;
{
  if ((((*(char *)(inst + 0x9c) != '\x01') && (*(char *)(inst + 0x9d) != '\x01')) &&
      (*(char *)(inst + 0x9e) != '\x01')) && (*(char *)(inst + 0x9f) != '\x01')) {
    return 0;
  }
  return 1;
}

/* SelectWord__isIdentity @ 0xf3190 (88 bytes) */
int SelectWord__isIdentity(selectWord)
  uint selectWord;
{
  uint laneByte;
  
  if ((((selectWord >> 0x18 == 4) || (selectWord >> 0x18 == 0)) &&
      ((laneByte = selectWord >> 0x10 & 0xff, laneByte == 4 || (laneByte == 1)))) &&
     (((laneByte = selectWord >> 8 & 0xff, laneByte == 4 || (laneByte == 2)) && ((selectWord - 3 & 0xff) < 2)))) {
    return 1;
  }
  return 0;
}

/* IRInst__isSourceSelectIdentity @ 0xf31e8 (16 bytes) */
int IRInst__isSourceSelectIdentity(inst, operandIndex)
  int inst;
  int operandIndex;
{
  undefined4 isIdentity;
  
  isIdentity = ((int (*)())SelectWord__isIdentity)(*(undefined4 *)(operandIndex * 0x18 + inst + 0x9c));
  return isIdentity;
}

/* SelectWord__selectWhereMasked @ 0xf31f8 (96 bytes) */
int SelectWord__selectWhereMasked(outSelect, baseSelect, laneMask)
  undefined1 *outSelect;
  undefined4 baseSelect;
  uint laneMask;
{
  undefined1 laneValue;
  
  laneValue = 1;
  if (laneMask >> 0x18 != 0) {
    laneValue = (undefined1)((uint)baseSelect >> 0x18);
  }
  *outSelect = laneValue;
  laneValue = 1;
  if ((laneMask >> 0x10 & 0xff) != 0) {
    laneValue = (undefined1)((uint)baseSelect >> 0x10);
  }
  outSelect[1] = laneValue;
  laneValue = 1;
  if ((laneMask >> 8 & 0xff) != 0) {
    laneValue = (undefined1)((uint)baseSelect >> 8);
  }
  outSelect[2] = laneValue;
  laneValue = 1;
  if ((laneMask & 0xff) != 0) {
    laneValue = (undefined1)baseSelect;
  }
  outSelect[3] = laneValue;
  return;
}

/* SelectWord__clearReadComponents @ 0xf3258 (116 bytes) */
int SelectWord__clearReadComponents(outMask, param_2)
  undefined4 *outMask;
  uint param_2;
{
  *outMask = DAT_001aa838;
  if (param_2 >> 0x18 < 4) {
    *(undefined1 *)outMask = 0;
  }
  if ((param_2 >> 0x10 & 0xff) < 4) {
    *(undefined1 *)((int)outMask + 1) = 0;
  }
  if ((param_2 >> 8 & 0xff) < 4) {
    *(undefined1 *)((int)outMask + 2) = 0;
  }
  if (3 < (param_2 & 0xff)) {
    return;
  }
  *(undefined1 *)((int)outMask + 3) = 0;
  return;
}

/* FUN_000f32cc @ 0xf32cc (116 bytes) */
int FUN_000f32cc(outMask, selectWord)
  undefined4 *outMask;
  uint selectWord;
{
  uint laneComponent;
  
  *outMask = DAT_001aa838;
  if (selectWord >> 0x18 < 4) {
    *(undefined1 *)((int)outMask + (selectWord >> 0x18)) = 0;
  }
  laneComponent = selectWord >> 0x10 & 0xff;
  if (laneComponent < 4) {
    *(undefined1 *)((int)outMask + laneComponent) = 0;
  }
  laneComponent = selectWord >> 8 & 0xff;
  if (laneComponent < 4) {
    *(undefined1 *)((int)outMask + laneComponent) = 0;
  }
  if (3 < (selectWord & 0xff)) {
    return;
  }
  *(undefined1 *)((int)outMask + (selectWord & 0xff)) = 0;
  return;
}

/* SelectWord__maskUnused @ 0xf3340 (88 bytes) */
int SelectWord__maskUnused(outSelect, baseSelect, maskWord)
  uint *outSelect;
  uint baseSelect;
  uint maskWord;
{
  if (maskWord >> 0x18 == 0) {
    baseSelect = baseSelect & 0xffffff | 0x4000000;
  }
  if ((maskWord >> 0x10 & 0xff) == 0) {
    baseSelect = baseSelect & 0xff00ffff | 0x40000;
  }
  if ((maskWord >> 8 & 0xff) == 0) {
    baseSelect = baseSelect & 0xffff00ff | 0x400;
  }
  if ((maskWord & 0xff) == 0) {
    baseSelect = baseSelect & 0xffffff00 | 4;
  }
  *outSelect = baseSelect;
  return;
}

/* SelectWord__readMask @ 0xf3398 (96 bytes) */
int SelectWord__readMask(outMask, selectWord)
  undefined4 *outMask;
  uint selectWord;
{
  uint laneComponent;
  
  *outMask = 0;
  if (selectWord >> 0x18 < 4) {
    *(undefined1 *)((int)outMask + (selectWord >> 0x18)) = 1;
  }
  laneComponent = selectWord >> 0x10 & 0xff;
  if (laneComponent < 4) {
    *(undefined1 *)((int)outMask + laneComponent) = 1;
  }
  laneComponent = selectWord >> 8 & 0xff;
  if (laneComponent < 4) {
    *(undefined1 *)((int)outMask + laneComponent) = 1;
  }
  if (3 < (selectWord & 0xff)) {
    return;
  }
  *(undefined1 *)((int)outMask + (selectWord & 0xff)) = 1;
  return;
}

/* SelectWord__fillUnusedWithFirstUsed @ 0xf33f8 (120 bytes) */
int SelectWord__fillUnusedWithFirstUsed(result, selectWord)
  undefined4 *result;
  undefined4 selectWord;
{
  unsigned int ghidra_home[8] = { result, selectWord, 0, 0, 0, 0, 0, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  char *scanCursor;
  char *fillCursor;
  int loopCounter;
  int loopCounterB;
  
  fillCursor = (char *)&(*(unsigned int *)((unsigned char *)ghidra_home + 4));
  loopCounterB = 4;
  (*(unsigned int *)((unsigned char *)ghidra_home + 4)) = selectWord;
  loopCounter = 0;
  scanCursor = fillCursor;
  do {
    if (*scanCursor != '\x04') {
      loopCounterB = 4;
      do {
        if (*fillCursor == '\x04') {
          *fillCursor = *(char *)((int)&(*(unsigned int *)((unsigned char *)ghidra_home + 4)) + loopCounter);
        }
        fillCursor = fillCursor + 1;
        loopCounterB = loopCounterB + -1;
      } while (loopCounterB != 0);
      *result = (*(unsigned int *)((unsigned char *)ghidra_home + 4));
      return;
    }
    loopCounter = loopCounter + 1;
    scanCursor = scanCursor + 1;
    loopCounterB = loopCounterB + -1;
  } while (loopCounterB != 0);
  *result = selectWord;
  return;
}

/* SelectWord__canonicalize @ 0xf3470 (340 bytes) */
int SelectWord__canonicalize(outSelect, selectWord)
  uint *outSelect;
  uint selectWord;
{
  byte *laneCursor;
  bool lane0Unused;
  int loopCounter;
  unsigned int ghidra_home[8] = { outSelect, selectWord, 0, 0, 0, 0, 0, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  bool hasUnusedLane;
  bool usedLanesAgree;
  uint lane0Byte;
  uint splatComponent;
  int lanesLeft;
  byte *laterLaneCursor;
  uint laneComponent;
  int laneIndex;
  int nextLane;
  
  (*(unsigned int *)((unsigned char *)ghidra_home + 4)) = selectWord;
  lane0Byte = (*(unsigned char *)((unsigned char *)ghidra_home + 4));
  (*(byte *)((unsigned char *)ghidra_home + 4)) = (byte)(selectWord >> 0x18);
  splatComponent = (uint)(*(byte *)((unsigned char *)ghidra_home + 4));
  if (splatComponent == 4) {
    usedLanesAgree = true;
    laneIndex = 1;
    do {
      laneComponent = (uint)(&(*(unsigned int *)((unsigned char *)ghidra_home + 4)))[laneIndex];
      nextLane = laneIndex;
      if ((laneComponent != 4) && (nextLane = laneIndex + 1, splatComponent = laneComponent, nextLane < 4)) {
        lanesLeft = 4 - nextLane;
        laterLaneCursor = (byte *)(&(*(unsigned int *)((unsigned char *)ghidra_home + 5)) + laneIndex);
        do {
          if ((*laterLaneCursor != 4) && (laneComponent != *laterLaneCursor)) {
            usedLanesAgree = false;
          }
          nextLane = nextLane + 1;
          laterLaneCursor = laterLaneCursor + 1;
          lanesLeft = lanesLeft + -1;
        } while (lanesLeft != 0);
      }
      laneIndex = nextLane + 1;
    } while (laneIndex < 4);
  }
  else {
    hasUnusedLane = false;
    loopCounter = 4;
    usedLanesAgree = true;
    laneCursor = &(*(unsigned int *)((unsigned char *)ghidra_home + 4));
    do {
      if (*laneCursor == 4) {
        hasUnusedLane = true;
      }
      else if (splatComponent != *laneCursor) {
        usedLanesAgree = false;
      }
      laneCursor = laneCursor + 1;
      loopCounter = loopCounter + -1;
    } while (loopCounter != 0);
    if (!hasUnusedLane) goto LAB_000f35b4;
  }
  if (usedLanesAgree) {
    *outSelect = (DAT_001aa818)[splatComponent];
    return;
  }
  lane0Unused = (*(byte *)((unsigned char *)ghidra_home + 4)) == 4;
  (*(unsigned char *)((unsigned char *)ghidra_home + 4)) = lane0Byte;
  if (lane0Unused) {
    (*(unsigned int *)((unsigned char *)ghidra_home + 4)) = selectWord & 0xffffff;
  }
  if ((*(char *)((unsigned char *)ghidra_home + 5)) == '\x04') {
    (*(char *)((unsigned char *)ghidra_home + 5)) = CONCAT12(1,(*(char *)((unsigned char *)ghidra_home + 6)));
  }
  if ((*(char *)((unsigned char *)ghidra_home + 6)) == '\x04') {
    (*(char *)((unsigned char *)ghidra_home + 6)) = CONCAT11(2,(*(char *)((unsigned char *)ghidra_home + 7)));
  }
  lane0Byte = (*(unsigned char *)((unsigned char *)ghidra_home + 4));
  if ((*(char *)((unsigned char *)ghidra_home + 7)) == '\x04') {
    (*(unsigned char *)((unsigned char *)ghidra_home + 4)) = CONCAT31((*(unsigned char *)((unsigned char *)ghidra_home + 4)),3);
    lane0Byte = (*(unsigned char *)((unsigned char *)ghidra_home + 4));
  }
LAB_000f35b4:
  (*(unsigned char *)((unsigned char *)ghidra_home + 4)) = lane0Byte;
  *outSelect = (*(unsigned char *)((unsigned char *)ghidra_home + 4));
  return;
}

/* IRInst__clearSourceSelectsOfUnwrittenComponents @ 0xf35c4 (168 bytes) */
int IRInst__clearSourceSelectsOfUnwrittenComponents(inst)
  int *inst;
{
  int operandRecord;
  bool notLastLane;
  int sourceNumber;
  int sourceCount;
  int loopCounter;
  undefined4 destSelectBytes [9];
  
  loopCounter = 0;
  operandRecord = IRInst__getOperandRecord(inst,0);
  destSelectBytes[0] = *(undefined4 *)(operandRecord + 0x10);
  do {
    sourceNumber = 1;
    if (*(char *)((int)destSelectBytes + loopCounter) == '\x01') {
      for (; sourceCount = (**(code **)(*inst + 0x14))(inst), sourceNumber <= sourceCount; sourceNumber = sourceNumber + 1) {
        (**(code **)(*inst + 0x88))(inst,sourceNumber,loopCounter,4);
      }
    }
    notLastLane = loopCounter != 3;
    loopCounter = loopCounter + 1;
  } while (notLastLane);
  return;
}

/* WriteMask__fromUsedComponents @ 0xf366c (76 bytes) */
int WriteMask__fromUsedComponents(outMask, selectWord)
  undefined4 *outMask;
  undefined4 selectWord;
{
  unsigned int ghidra_home[8] = { outMask, selectWord, 0, 0, 0, 0, 0, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  byte *pbVar1;
  int loopCounter;
  
  (*(unsigned int *)((unsigned char *)ghidra_home + 4)) = selectWord;
  loopCounter = 4;
  *outMask = DAT_001aa838;
  pbVar1 = (byte *)&(*(unsigned int *)((unsigned char *)ghidra_home + 4));
  do {
    if (*pbVar1 != 4) {
      *(undefined1 *)((int)outMask + (uint)*pbVar1) = 0;
    }
    pbVar1 = pbVar1 + 1;
    loopCounter = loopCounter + -1;
  } while (loopCounter != 0);
  return;
}

/* WriteMask__fromUsedLanes @ 0xf36b8 (84 bytes) */
int WriteMask__fromUsedLanes(result, selectWord)
  undefined4 *result;
  undefined4 selectWord;
{
  unsigned int ghidra_home[8] = { result, selectWord, 0, 0, 0, 0, 0, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  char *laneCursor;
  int loopCounter;
  
  (*(unsigned int *)((unsigned char *)ghidra_home + 4)) = selectWord;
  laneCursor = (char *)&(*(unsigned int *)((unsigned char *)ghidra_home + 4));
  loopCounter = 4;
  *result = DAT_001aa838;
  do {
    if (*laneCursor != '\x04') {
      *(undefined1 *)result = 0;
    }
    laneCursor = laneCursor + 1;
    result = (undefined4 *)((int)result + 1);
    loopCounter = loopCounter + -1;
  } while (loopCounter != 0);
  return;
}

/* FUN_000f370c @ 0xf370c (88 bytes) */
int FUN_000f370c(outBytes, laneBytes)
  char *outBytes;
  undefined4 laneBytes;
{
  unsigned int ghidra_home[8] = { outBytes, laneBytes, 0, 0, 0, 0, 0, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  char *laneCursor;
  char laneIndexByte;
  int loopCounter;
  
  (*(unsigned int *)((unsigned char *)ghidra_home + 4)) = laneBytes;
  laneIndexByte = '\0';
  laneCursor = (char *)&(*(unsigned int *)((unsigned char *)ghidra_home + 4));
  loopCounter = 4;
  *(undefined4 *)outBytes = DAT_001aa83c;
  do {
    if (*laneCursor == '\0') {
      *outBytes = laneIndexByte;
    }
    laneIndexByte = laneIndexByte + '\x01';
    laneCursor = laneCursor + 1;
    outBytes = outBytes + 1;
    loopCounter = loopCounter + -1;
  } while (loopCounter != 0);
  return;
}

/* laneBytes__clearSetLanes @ 0xf3764 (84 bytes) */
int laneBytes__clearSetLanes(outMask, laneBytes)
  undefined4 *outMask;
  undefined4 laneBytes;
{
  unsigned int ghidra_home[8] = { outMask, laneBytes, 0, 0, 0, 0, 0, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  char *laneCursor;
  int loopCounter;
  
  (*(unsigned int *)((unsigned char *)ghidra_home + 4)) = laneBytes;
  laneCursor = (char *)&(*(unsigned int *)((unsigned char *)ghidra_home + 4));
  loopCounter = 4;
  *outMask = DAT_001aa838;
  do {
    if (*laneCursor != '\0') {
      *(undefined1 *)outMask = 0;
    }
    laneCursor = laneCursor + 1;
    outMask = (undefined4 *)((int)outMask + 1);
    loopCounter = loopCounter + -1;
  } while (loopCounter != 0);
  return;
}

/* SelectWord__splatComponent @ 0xf37b8 (108 bytes) */
int SelectWord__splatComponent(selectWord)
  int selectWord;
{
  if (selectWord == DAT_001aa85c) {
    return 0;
  }
  if (selectWord == DAT_001aa858) {
    return 1;
  }
  if (selectWord == DAT_001aa854) {
    return 2;
  }
  if (selectWord == DAT_001aa850) {
    return 3;
  }
  return 0xffffffff;
}

/* SelectWord__isSingleComponentConstant @ 0xf3824 (96 bytes) */
int SelectWord__isSingleComponentConstant(selectWord)
  int selectWord;
{
  if ((((selectWord != DAT_001aa85c) && (selectWord != DAT_001aa858)) && (selectWord != DAT_001aa854)) &&
     (selectWord != DAT_001aa850)) {
    return 0;
  }
  return 1;
}

/* IRInst__destIsSingleComponent @ 0xf3884 (8 bytes) */
int IRInst__destIsSingleComponent(inst)
  int inst;
{
  undefined4 result;
  
  result = ((int (*)())SelectWord__isSingleComponentConstant)(*(undefined4 *)(inst + 0x9c));
  return result;
}

/* laneMask__fromSelectBytes @ 0xf388c (124 bytes) */
int laneMask__fromSelectBytes(outLaneMask, selectWord, laneCount)
  undefined4 *outLaneMask;
  uint selectWord;
  int laneCount;
{
  uint laneComponent;
  
  *outLaneMask = 0;
  if ((0 < laneCount) && (selectWord >> 0x18 < 4)) {
    *(undefined1 *)((int)outLaneMask + (selectWord >> 0x18)) = 1;
  }
  if ((1 < laneCount) && (laneComponent = selectWord >> 0x10 & 0xff, laneComponent < 4)) {
    *(undefined1 *)((int)outLaneMask + laneComponent) = 1;
  }
  if ((2 < laneCount) && (laneComponent = selectWord >> 8 & 0xff, laneComponent < 4)) {
    *(undefined1 *)((int)outLaneMask + laneComponent) = 1;
  }
  if (laneCount < 4) {
    return;
  }
  if (3 < (selectWord & 0xff)) {
    return;
  }
  *(undefined1 *)((int)outLaneMask + (selectWord & 0xff)) = 1;
  return;
}

/* WriteMask__fromSelectWord @ 0xf3908 (96 bytes) */
int WriteMask__fromSelectWord(outMask, selectWord)
  byte *outMask;
  uint selectWord;
{
  outMask[0] = 0;
  outMask[1] = 0;
  outMask[2] = 0;
  outMask[3] = 0;
  outMask[3] = (byte)(-(uint)((selectWord ^ 1) & 0xff) >> 0x1f);
  *outMask = (byte)(-(uint)(selectWord >> 0x18 ^ 1) >> 0x1f);
  outMask[1] = (byte)(-(uint)(selectWord >> 0x10 & 0xff ^ 1) >> 0x1f);
  outMask[2] = (byte)(-(uint)(selectWord >> 8 & 0xff ^ 1) >> 0x1f);
  return;
}

/* laneBytes__selectWhereFirstIsOne @ 0xf3968 (104 bytes) */
int laneBytes__selectWhereFirstIsOne(outMask, selectMask, values)
  undefined4 *outMask;
  uint selectMask;
  undefined4 values;
{
  undefined1 laneValue;
  
  laneValue = 0;
  *outMask = 0;
  if (selectMask >> 0x18 == 1) {
    laneValue = (undefined1)((uint)values >> 0x18);
  }
  *(undefined1 *)outMask = laneValue;
  laneValue = 0;
  if ((selectMask >> 0x10 & 0xff) == 1) {
    laneValue = (undefined1)((uint)values >> 0x10);
  }
  *(undefined1 *)((int)outMask + 1) = laneValue;
  laneValue = 0;
  if ((selectMask >> 8 & 0xff) == 1) {
    laneValue = (undefined1)((uint)values >> 8);
  }
  *(undefined1 *)((int)outMask + 2) = laneValue;
  laneValue = 0;
  if ((selectMask & 0xff) == 1) {
    laneValue = (undefined1)values;
  }
  *(undefined1 *)((int)outMask + 3) = laneValue;
  return;
}

/* laneMask__fromUsedLanes @ 0xf39d0 (96 bytes) */
int laneMask__fromUsedLanes(outMask, selectWord)
  undefined4 *outMask;
  uint selectWord;
{
  *outMask = 0;
  if (selectWord >> 0x18 < 4) {
    *(undefined1 *)outMask = 1;
  }
  if ((selectWord >> 0x10 & 0xff) < 4) {
    *(undefined1 *)((int)outMask + 1) = 1;
  }
  if ((selectWord >> 8 & 0xff) < 4) {
    *(undefined1 *)((int)outMask + 2) = 1;
  }
  if (3 < (selectWord & 0xff)) {
    return;
  }
  *(undefined1 *)((int)outMask + 3) = 1;
  return;
}

/* IRInst__countWrittenComponents @ 0xf3a30 (96 bytes) */
int IRInst__countWrittenComponents(inst)
  undefined4 inst;
{
  bool notLastLane;
  int operandRecord;
  int loopCounter;
  int loopCounterB;
  
  loopCounter = 0;
  loopCounterB = 0;
  do {
    operandRecord = IRInst__getOperandRecord(inst,0);
    if (*(char *)(loopCounterB + operandRecord + 0x10) != '\x01') {
      loopCounter = loopCounter + 1;
    }
    notLastLane = loopCounterB != 3;
    loopCounterB = loopCounterB + 1;
  } while (notLastLane);
  return loopCounter;
}

/* FUN_000f3a90 @ 0xf3a90 (80 bytes) */
int FUN_000f3a90(inst)
  undefined4 inst;
{
  uint destSelect;
  int operandRecord;
  undefined4 result;
  
  operandRecord = IRInst__getOperandRecord(inst,0);
  destSelect = *(uint *)(operandRecord + 0x10);
  if (((destSelect >> 0x18 == 0) || ((destSelect >> 0x10 & 0xff) == 0)) ||
     (result = 0, (destSelect >> 8 & 0xff) == 0)) {
    result = 1;
  }
  return result;
}

/* IRInst__destSelectLane3IsX @ 0xf3ae0 (48 bytes) */
int IRInst__destSelectLane3IsX(inst)
  undefined4 inst;
{
  int operandRecord;
  
  operandRecord = IRInst__getOperandRecord(inst,0);
  return *(char *)(operandRecord + 0x13) == '\0';
}

/* IRInst__operandReadsXYZ @ 0xf3b10 (88 bytes) */
int IRInst__operandReadsXYZ(inst, operandIndex)
  undefined4 inst;
  undefined4 operandIndex;
{
  int operandRecord;
  int loopCounter;
  int loopCounterB;
  undefined4 local_28 [10];
  
  operandRecord = IRInst__getOperandRecord(inst,operandIndex);
  loopCounter = 0;
  local_28[0] = *(undefined4 *)(operandRecord + 0x10);
  loopCounterB = 4;
  do {
    if (*(byte *)((int)local_28 + loopCounter) < 3) {
      return 1;
    }
    loopCounter = loopCounter + 1;
    loopCounterB = loopCounterB + -1;
  } while (loopCounterB != 0);
  return 0;
}

/* IRInst__operandReadsW @ 0xf3b68 (88 bytes) */
int IRInst__operandReadsW(inst, operandIndex)
  undefined4 inst;
  undefined4 operandIndex;
{
  int operandRecord;
  int loopCounter;
  int loopCounterB;
  undefined4 local_28 [10];
  
  operandRecord = IRInst__getOperandRecord(inst,operandIndex);
  loopCounter = 0;
  local_28[0] = *(undefined4 *)(operandRecord + 0x10);
  loopCounterB = 4;
  do {
    if (*(char *)((int)local_28 + loopCounter) == '\x03') {
      return 1;
    }
    loopCounter = loopCounter + 1;
    loopCounterB = loopCounterB + -1;
  } while (loopCounterB != 0);
  return 0;
}

/* IRInst__operandSelectIsNotDefault @ 0xf3bc0 (112 bytes) */
int IRInst__operandSelectIsNotDefault(inst, operandIndex)
  undefined4 inst;
  int operandIndex;
{
  int operandRecord;
  bool bVar2;
  
  if (operandIndex == 0) {
    operandRecord = IRInst__getOperandRecord(inst,0);
    bVar2 = *(int *)(operandRecord + 0x10) == _UNK_001aa84c;
  }
  else {
    operandRecord = IRInst__getOperandRecord(inst,operandIndex);
    bVar2 = *(int *)(operandRecord + 0x10) == _UNK_001aa848;
  }
  return 1 - (uint)bVar2;
}

/* IRInst__computeSourceLaneMask @ 0xf3c30 (972 bytes) */
int IRInst__computeSourceLaneMask(laneMask, inst, operandIndex, program, destSelectWord)
  byte *laneMask;
  int *inst;
  int operandIndex;
  int program;
  undefined4 destSelectWord;
{
  int opcodeId;
  int registerClassIndex;
  int loopCounterB;
  int operandRecord;
  int loopCounter;
  unsigned int ghidra_home[8] = { laneMask, inst, operandIndex, program, destSelectWord, 0, 0, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  bool notLastLane;
  uint classComponentMask;
  byte *maskCursor;
  int sourceType;
  undefined4 resultMode;
  char *destMaskCursor;
  int operandRecordB;
  undefined4 operandSelectWord;
  undefined4 operandSelectWordB [7];
  
  (*(unsigned int *)((unsigned char *)ghidra_home + 16)) = destSelectWord;
  (**(code **)(*inst + 0x14))(inst,inst,operandIndex,program,destSelectWord);
  laneMask[0] = 0;
  laneMask[1] = 0;
  laneMask[2] = 0;
  laneMask[3] = 0;
  if (0 < operandIndex) {
    sourceType = IRInst__getOperandSource(inst,operandIndex);
    if (sourceType == 0) {
      sourceType = *(int *)(inst[operandIndex * 6 + 0x23] + 4);
    }
    else {
      sourceType = *(int *)(sourceType + 0x98);
    }
    if ((sourceType == 0x3b) || (sourceType == 0x42)) goto switchD_000f3cf4_caseD_b;
  }
  resultMode = OpcodeInfo__getResultMode(inst[0x22],inst,program);
  switch(resultMode) {
  case 0:
    break;
  case 1:
    if (operandIndex == 2) goto switchD_000f3cf4_caseD_b;
    if (operandIndex != 3) {
      if (operandIndex != 1) {
        return laneMask;
      }
      laneMask[3] = 1;
      return laneMask;
    }
    goto LAB_000f3fe8;
  case 2:
switchD_000f3cf4_caseD_2:
    laneMask[3] = 1;
    *laneMask = 1;
    laneMask[1] = 1;
    return laneMask;
  case 3:
    if (operandIndex != 3) {
      laneMask[1] = 1;
      *laneMask = 1;
      return laneMask;
    }
LAB_000f3fe8:
    laneMask[2] = 1;
    return laneMask;
  case 4:
    goto switchD_000f3cf4_caseD_4;
  default:
    goto switchD_000f3cf4_caseD_5;
  case 6:
    if (operandIndex == 1) {
      loopCounter = 0;
      maskCursor = laneMask;
      do {
        operandRecordB = IRInst__getOperandRecord(inst,0);
        operandSelectWord = *(undefined4 *)(operandRecordB + 0x10);
        if (*(char *)((int)operandSelectWordB + loopCounter + -4) != '\x01') {
          *maskCursor = *maskCursor | 1;
        }
        notLastLane = loopCounter != 3;
        maskCursor = maskCursor + 1;
        loopCounter = loopCounter + 1;
      } while (notLastLane);
      return laneMask;
    }
    goto switchD_000f3cf4_caseD_5;
  case 7:
    if (2 < operandIndex) {
LAB_000f3ff4:
      laneMask[3] = 1;
      return laneMask;
    }
switchD_000f3cf4_caseD_4:
    laneMask[2] = 1;
    *laneMask = 1;
    laneMask[1] = 1;
    return laneMask;
  case 9:
    registerClassIndex = 0;
    if (-1 < inst[0x4d]) {
      registerClassIndex = *(int *)(inst[0x4d] * 0xc + *(int *)(program + 0x78) + 4);
    }
    classComponentMask = (DAT_001dc58c)[registerClassIndex * 2];
    if ((classComponentMask & 1) != 0) {
      *laneMask = 1;
    }
    if ((classComponentMask & 2) != 0) {
      laneMask[1] = 1;
    }
    if ((classComponentMask & 4) != 0) {
      laneMask[2] = 1;
    }
    if ((classComponentMask & 8) != 0) {
      laneMask[3] = 1;
    }
    opcodeId = *(int *)(inst[0x22] + 8);
    if ((((opcodeId == 0x101) || (opcodeId == 0x100)) || (opcodeId == 0x102)) || (opcodeId == 0x6e))
    goto LAB_000f3ff4;
    if (((opcodeId == 0x75) || (opcodeId == 0x76)) || (opcodeId == 0xae)) goto switchD_000f3cf4_caseD_2;
    if (((opcodeId != 0x9e) && (opcodeId != 0x9f)) && ((opcodeId != 0xa0 && (opcodeId != 0xa1)))) {
      return laneMask;
    }
    break;
  case 0xb:
    goto switchD_000f3cf4_caseD_b;
  case 0xc:
    operandRecord = IRInst__getOperandRecord(inst,operandIndex);
    loopCounterB = 0;
    destMaskCursor = &(*(unsigned int *)((unsigned char *)ghidra_home + 16));
    operandSelectWordB[0] = *(undefined4 *)(operandRecord + 0x10);
    loopCounter = 4;
    maskCursor = laneMask;
    do {
      if ((*destMaskCursor == '\0') && (*(char *)((int)operandSelectWordB + loopCounterB) != '\x04')) {
        *maskCursor = *maskCursor | 1;
      }
      loopCounterB = loopCounterB + 1;
      destMaskCursor = destMaskCursor + 1;
      maskCursor = maskCursor + 1;
      loopCounter = loopCounter + -1;
    } while (loopCounter != 0);
    return laneMask;
  case 0xd:
    if (operandIndex != 2) goto switchD_000f3cf4_caseD_5;
switchD_000f3cf4_caseD_b:
    *laneMask = 1;
    return laneMask;
  case 0xe:
    if (operandIndex != 1) {
      if (operandIndex != 2) {
        if (operandIndex != 3) {
          return laneMask;
        }
        goto switchD_000f3cf4_caseD_5;
      }
      goto switchD_000f3cf4_caseD_b;
    }
    break;
  case 0xf:
    if (*(int *)(inst[0x22] + 8) == 0xb4) {
      if (operandIndex == 2) goto LAB_000f3fe8;
      if (operandIndex < 3) {
        if (operandIndex != 1) {
          return laneMask;
        }
        *laneMask = 1;
        laneMask[1] = 1;
        return laneMask;
      }
      if (operandIndex == 3) goto LAB_000f3ff4;
      if (operandIndex != 4) {
        return laneMask;
      }
    }
switchD_000f3cf4_caseD_5:
    laneMask[3] = 1;
    *laneMask = 1;
    laneMask[1] = 1;
    laneMask[2] = 1;
    return laneMask;
  }
  *laneMask = (*(char *)((unsigned char *)ghidra_home + 16)) == '\0';
  laneMask[1] = (*(char *)((unsigned char *)ghidra_home + 17)) == '\0';
  laneMask[2] = (*(char *)((unsigned char *)ghidra_home + 18)) == '\0';
  laneMask[3] = (*(char *)((unsigned char *)ghidra_home + 19)) == '\0';
  return laneMask;
}

/* IRInst__computeSourceReadMask @ 0xf403c (1404 bytes) */
int IRInst__computeSourceReadMask(laneMask, inst, operandIndex, destWriteMask, program)
  undefined4 *laneMask;
  int *inst;
  int operandIndex;
  undefined4 destWriteMask;
  int program;
{
  int opcodeNumber;
  int loopCounter;
  int operandRecord2;
  int operandRecord;
  bool notLastLane;
  byte *selectBytePtr;
  uint laneIndex;
  int opcodeClassIndex;
  undefined4 resultMode;
  uint resultFlags;
  int loopCounterB;
  undefined4 sourceSelect;
  undefined4 maskedSelect [3];
  undefined4 maskedSelectOut4;
  undefined4 maskedSelectOut1;
  undefined4 laneReadMask2;
  undefined4 laneReadMask3A;
  undefined4 laneReadMask4A;
  undefined4 laneReadMask4B;
  undefined4 laneReadMask3B;
  undefined4 laneReadMask4C;
  undefined4 maskedSelectOut2;
  undefined4 maskedSelectOut3 [3];
  
  (**(code **)(*inst + 0x14))(inst,inst,operandIndex,destWriteMask,program);
  operandRecord = IRInst__getOperandRecord(inst,operandIndex);
  sourceSelect = *(uint *)(operandRecord + 0x10);
  *laneMask = 0;
  resultMode = OpcodeInfo__getResultMode(inst[0x22],inst,program);
  switch(resultMode) {
  case 0:
    operandRecord = IRInst__getOperandRecord(inst,0);
    ((int (*)())SelectWord__selectWhereMasked)(&maskedSelectOut1,*(undefined4 *)(operandRecord + 0x10),destWriteMask);
    loopCounter = 0;
    maskedSelect[0] = maskedSelectOut1;
    loopCounterB = 4;
    do {
      if (*(char *)((int)maskedSelect + loopCounter) != '\x01') {
        laneIndex = (uint)*(byte *)((int)maskedSelect + loopCounter + -4);
        *(byte *)((int)laneMask + laneIndex) = *(byte *)((int)laneMask + laneIndex) | 1;
      }
      loopCounter = loopCounter + 1;
      loopCounterB = loopCounterB + -1;
    } while (loopCounterB != 0);
    break;
  case 1:
    if (operandIndex == 2) goto switchD_000f40d0_caseD_b;
    if (operandIndex != 3) {
      if (operandIndex != 1) {
        return laneMask;
      }
      *(undefined1 *)((int)laneMask + (sourceSelect & 0xff)) = 1;
      return laneMask;
    }
    goto LAB_000f4584;
  case 2:
switchD_000f40d0_caseD_2:
    *(undefined1 *)((int)laneMask + (uint)(*(unsigned char *)((unsigned char *)&(sourceSelect) + 0))) = 1;
    *(undefined1 *)((int)laneMask + (uint)(*(unsigned char *)((unsigned char *)&(sourceSelect) + 1))) = 1;
    *(undefined1 *)((int)laneMask + (sourceSelect & 0xff)) = 1;
    return laneMask;
  case 3:
    if (operandIndex - 1U < 2) {
      ((int (*)())laneMask__fromSelectBytes)(&laneReadMask2,sourceSelect,2);
      *laneMask = laneReadMask2;
      return laneMask;
    }
    if (operandIndex != 3) {
      return laneMask;
    }
    goto LAB_000f4584;
  case 4:
    ((int (*)())laneMask__fromSelectBytes)(&laneReadMask3A,sourceSelect,3);
    *laneMask = laneReadMask3A;
    break;
  case 5:
    ((int (*)())laneMask__fromSelectBytes)(&laneReadMask4A,sourceSelect,4);
    *laneMask = laneReadMask4A;
    break;
  case 6:
    if (operandIndex == 1) {
      loopCounter = 0;
      do {
        operandRecord2 = IRInst__getOperandRecord(inst,0);
        if (*(char *)(loopCounter + operandRecord2 + 0x10) != '\x01') {
          laneIndex = (uint)*(byte *)((int)maskedSelect + loopCounter + -4);
          *(byte *)((int)laneMask + laneIndex) = *(byte *)((int)laneMask + laneIndex) | 1;
        }
        notLastLane = loopCounter != 3;
        loopCounter = loopCounter + 1;
      } while (notLastLane);
    }
    else {
      ((int (*)())laneMask__fromSelectBytes)(&laneReadMask4B,sourceSelect,4);
      *laneMask = laneReadMask4B;
    }
    break;
  case 7:
    if (operandIndex < 3) {
      ((int (*)())laneMask__fromSelectBytes)(&laneReadMask3B,sourceSelect,3);
      *laneMask = laneReadMask3B;
      return laneMask;
    }
    goto LAB_000f4594;
  case 8:
    ((int (*)())laneMask__fromSelectBytes)(&laneReadMask4C,sourceSelect,4);
    *laneMask = laneReadMask4C;
    break;
  case 9:
    if (inst[0x4d] < 0) {
      opcodeClassIndex = 0;
      laneIndex = 0xfffffff6;
    }
    else {
      opcodeClassIndex = *(int *)(inst[0x4d] * 0xc + *(int *)(program + 0x78) + 4);
      laneIndex = opcodeClassIndex - 10;
    }
    resultFlags = (DAT_001dc58c)[opcodeClassIndex * 2];
    if ((laneIndex < 2) && ((char)sourceSelect == '\x04')) {
      resultFlags = resultFlags & 7;
    }
    if ((resultFlags & 1) != 0) {
      *(undefined1 *)((int)laneMask + (uint)(*(unsigned char *)((unsigned char *)&(sourceSelect) + 0))) = 1;
    }
    if ((resultFlags & 2) != 0) {
      *(undefined1 *)((int)laneMask + (uint)(*(unsigned char *)((unsigned char *)&(sourceSelect) + 1))) = 1;
    }
    if ((resultFlags & 4) != 0) {
      *(undefined1 *)((int)laneMask + (uint)(*(unsigned char *)((unsigned char *)&(sourceSelect) + 2))) = 1;
    }
    if ((resultFlags & 8) != 0) {
      *(undefined1 *)((int)laneMask + (sourceSelect & 0xff)) = 1;
    }
    opcodeNumber = *(int *)(inst[0x22] + 8);
    if (opcodeNumber < 0xa2) {
      if (0x9d < opcodeNumber) {
        operandRecord = IRInst__getOperandRecord(inst,0);
        ((int (*)())SelectWord__selectWhereMasked)(&maskedSelectOut2,*(undefined4 *)(operandRecord + 0x10),destWriteMask);
        maskedSelect[0] = maskedSelectOut2;
        *laneMask = 0;
        loopCounter = 0;
        loopCounterB = 4;
        do {
          selectBytePtr = (byte *)((int)maskedSelect + loopCounter);
          laneIndex = (uint)*(byte *)((int)maskedSelect + loopCounter + -4);
          loopCounter = loopCounter + 1;
          *(byte *)((int)laneMask + laneIndex) =
               (byte)(-(uint)(*selectBytePtr ^ 1) >> 0x1f) | *(byte *)((int)laneMask + laneIndex);
          loopCounterB = loopCounterB + -1;
        } while (loopCounterB != 0);
        return laneMask;
      }
      if (opcodeNumber != 0x6e) {
        if (opcodeNumber < 0x6e) {
          return laneMask;
        }
        if (1 < opcodeNumber - 0x75U) {
          return laneMask;
        }
        goto switchD_000f40d0_caseD_2;
      }
    }
    else {
      if (opcodeNumber == 0xae) goto switchD_000f40d0_caseD_2;
      if (opcodeNumber < 0xae) {
        return laneMask;
      }
      if (2 < opcodeNumber - 0x100U) {
        return laneMask;
      }
    }
LAB_000f4594:
    *(undefined1 *)((int)laneMask + (sourceSelect & 0xff)) = 1;
    break;
  default:
switchD_000f40d0_caseD_a:
    *(undefined1 *)((int)laneMask + 3) = 1;
    *(undefined1 *)laneMask = 1;
    *(undefined1 *)((int)laneMask + 1) = 1;
    *(undefined1 *)((int)laneMask + 2) = 1;
    break;
  case 0xb:
    goto switchD_000f40d0_caseD_b;
  case 0xc:
    operandRecord = IRInst__getOperandRecord(inst,0);
    ((int (*)())SelectWord__selectWhereMasked)(maskedSelectOut3,*(undefined4 *)(operandRecord + 0x10),destWriteMask);
    maskedSelect[0] = maskedSelectOut3[0];
    *laneMask = 0;
    loopCounter = 0;
    loopCounterB = 4;
    do {
      if ((*(char *)((int)maskedSelect + loopCounter) == '\0') &&
         (laneIndex = (uint)*(byte *)((int)maskedSelect + loopCounter + -4), laneIndex != 4)) {
        *(byte *)((int)laneMask + laneIndex) = *(byte *)((int)laneMask + laneIndex) | 1;
      }
      loopCounter = loopCounter + 1;
      loopCounterB = loopCounterB + -1;
    } while (loopCounterB != 0);
    break;
  case 0xd:
    if (operandIndex != 2) {
LAB_000f45a4:
      *(undefined1 *)((int)laneMask + (uint)(*(unsigned char *)((unsigned char *)&(sourceSelect) + 0))) = 1;
      *(undefined1 *)((int)laneMask + (uint)(*(unsigned char *)((unsigned char *)&(sourceSelect) + 1))) = 1;
      *(undefined1 *)((int)laneMask + (uint)(*(unsigned char *)((unsigned char *)&(sourceSelect) + 2))) = 1;
      *(undefined1 *)((int)laneMask + (sourceSelect & 0xff)) = 1;
      return laneMask;
    }
    goto switchD_000f40d0_caseD_b;
  case 0xe:
    if (operandIndex == 1) {
      operandRecord = IRInst__getOperandRecord(inst,0);
      ((int (*)())SelectWord__selectWhereMasked)(&maskedSelectOut4,*(undefined4 *)(operandRecord + 0x10),destWriteMask);
      loopCounter = 0;
      maskedSelect[0] = maskedSelectOut4;
      loopCounterB = 4;
      do {
        if (*(char *)((int)maskedSelect + loopCounter) != '\x01') {
          *(undefined1 *)((int)laneMask + (uint)*(byte *)((int)maskedSelect + loopCounter + -4)) = 1;
        }
        loopCounter = loopCounter + 1;
        loopCounterB = loopCounterB + -1;
      } while (loopCounterB != 0);
      return laneMask;
    }
    if (operandIndex != 2) {
      if (operandIndex != 3) {
        return laneMask;
      }
      goto LAB_000f45a4;
    }
switchD_000f40d0_caseD_b:
    *(undefined1 *)((int)laneMask + (uint)(*(unsigned char *)((unsigned char *)&(sourceSelect) + 0))) = 1;
    break;
  case 0xf:
    if (*(int *)(inst[0x22] + 8) != 0xb4) goto switchD_000f40d0_caseD_a;
    if (operandIndex != 2) {
      if (operandIndex < 3) {
        if (operandIndex != 1) {
          return laneMask;
        }
        *(undefined1 *)((int)laneMask + (uint)(*(unsigned char *)((unsigned char *)&(sourceSelect) + 0))) = 1;
        *(undefined1 *)((int)laneMask + (uint)(*(unsigned char *)((unsigned char *)&(sourceSelect) + 1))) = 1;
        return laneMask;
      }
      if (operandIndex != 3) {
        if (operandIndex != 4) {
          return laneMask;
        }
        goto LAB_000f45a4;
      }
      goto LAB_000f4594;
    }
LAB_000f4584:
    *(undefined1 *)((int)laneMask + (uint)(*(unsigned char *)((unsigned char *)&(sourceSelect) + 2))) = 1;
  }
  return laneMask;
}

/* FUN_000f45f8 @ 0xf45f8 (160 bytes) */
int FUN_000f45f8(sourceInst, operandIndex, inst, program)
  undefined4 sourceInst;
  undefined4 operandIndex;
  undefined4 inst;
  undefined4 program;
{
  bool lastLane;
  int operandRecord;
  int loopCounter;
  undefined4 readMaskBytes [4];
  undefined4 readMaskOut [2];
  
  ((int (*)())IRInst__computeSourceReadMask)(readMaskOut,sourceInst,operandIndex,DAT_001aa840,program);
  loopCounter = 0;
  readMaskBytes[0] = readMaskOut[0];
  while ((*(char *)((int)readMaskBytes + loopCounter) == '\0' ||
         (operandRecord = IRInst__getOperandRecord(inst,0), *(char *)(loopCounter + operandRecord + 0x10) != '\x01'))) {
    lastLane = loopCounter == 3;
    loopCounter = loopCounter + 1;
    if (lastLane) {
      return 1;
    }
  }
  return 0;
}

/* IRInst__maskUnusedLanesOfOperand @ 0xf4698 (148 bytes) */
int IRInst__maskUnusedLanesOfOperand(inst, operandIndex, program)
  int inst;
  int operandIndex;
  undefined4 program;
{
  int operandRecord;
  undefined4 laneMask;
  undefined4 maskedSelect;
  
  operandRecord = IRInst__getOperandRecord(inst,0);
  ((int (*)())IRInst__computeSourceLaneMask)(&laneMask,inst,operandIndex,program,*(undefined4 *)(operandRecord + 0x10));
  operandRecord = IRInst__getOperandRecord(inst,operandIndex);
  ((int (*)())SelectWord__maskUnused)(&maskedSelect,*(undefined4 *)(operandRecord + 0x10),laneMask);
  if (operandIndex == 0) {
    *(undefined4 *)(inst + 0x9c) = maskedSelect;
  }
  else {
    operandRecord = IRInst__getOperandRecord(inst,operandIndex);
    *(undefined4 *)(operandRecord + 0x10) = maskedSelect;
  }
  return;
}

/* IRInst__storeInvertedDestMask @ 0xf472c (124 bytes) */
int IRInst__storeInvertedDestMask(outMask, inst)
  int outMask;
  undefined4 inst;
{
  int operandRecord;
  int loopCounter;
  int loopCounterB;
  undefined4 invertedMask [8];
  
  operandRecord = IRInst__getOperandRecord(inst,0);
  loopCounter = 0;
  invertedMask[0] = *(undefined4 *)(operandRecord + 0x10);
  loopCounterB = 4;
  do {
    if (*(char *)((int)invertedMask + loopCounter) == '\x01') {
      *(undefined1 *)((int)invertedMask + loopCounter) = 0;
    }
    else {
      *(undefined1 *)((int)invertedMask + loopCounter) = 1;
    }
    loopCounter = loopCounter + 1;
    loopCounterB = loopCounterB + -1;
  } while (loopCounterB != 0);
  *(undefined4 *)(outMask + 0x9c) = invertedMask[0];
  return;
}

/* IRInst__mergeDestMasksIntoFirst @ 0xf47a8 (180 bytes) */
int IRInst__mergeDestMasksIntoFirst(outMask, inst, inst2)
  int outMask;
  undefined4 inst;
  undefined4 inst2;
{
  int operandRecord2;
  int operandRecord;
  int loopCounter;
  int loopCounterB;
  undefined4 instSelect;
  undefined4 inst2Select [6];
  
  operandRecord = IRInst__getOperandRecord(inst,0);
  instSelect = *(undefined4 *)(operandRecord + 0x10);
  operandRecord2 = IRInst__getOperandRecord(inst2,0);
  loopCounter = 0;
  inst2Select[0] = *(undefined4 *)(operandRecord2 + 0x10);
  loopCounterB = 4;
  do {
    if ((*(char *)((int)inst2Select + loopCounter + -4) != '\x01') &&
       (*(char *)((int)inst2Select + loopCounter) != '\x01')) break;
    loopCounter = loopCounter + 1;
    loopCounterB = loopCounterB + -1;
  } while (loopCounterB != 0);
  loopCounter = 0;
  loopCounterB = 4;
  do {
    if (*(char *)((int)inst2Select + loopCounter) != '\x01') {
      *(char *)((int)inst2Select + loopCounter + -4) = *(char *)((int)inst2Select + loopCounter);
    }
    loopCounter = loopCounter + 1;
    loopCounterB = loopCounterB + -1;
  } while (loopCounterB != 0);
  *(undefined4 *)(outMask + 0x9c) = instSelect;
  return;
}

/* IRInst__sourceLanesAllWritten_f485c @ 0xf485c (144 bytes) */
int IRInst__sourceLanesAllWritten_f485c(inst, operandIndex)
  undefined4 inst;
  undefined4 operandIndex;
{
  bool bVar1;
  byte bVar2;
  undefined4 operandVReg;
  int operandRecord;
  int loopCounter;
  undefined4 local_38 [9];
  
  operandVReg = IRInst__getOperandSource(inst,operandIndex);
  operandRecord = IRInst__getOperandRecord(inst,operandIndex);
  loopCounter = 0;
  local_38[0] = *(undefined4 *)(operandRecord + 0x10);
  while ((bVar2 = *(byte *)((int)local_38 + loopCounter), bVar2 == 4 ||
         (operandRecord = IRInst__getOperandRecord(operandVReg,0), *(char *)((uint)bVar2 + operandRecord + 0x10) == '\x01'))) {
    bVar1 = loopCounter == 3;
    loopCounter = loopCounter + 1;
    if (bVar1) {
      return 1;
    }
  }
  return 0;
}

/* IRInst__sourceLanesAllWritten @ 0xf48ec (144 bytes) */
int IRInst__sourceLanesAllWritten(inst, operandIndex)
  undefined4 inst;
  undefined4 operandIndex;
{
  bool bVar1;
  byte bVar2;
  undefined4 operandVReg;
  int operandRecord;
  int loopCounter;
  undefined4 operandSelectBytes [9];
  
  operandVReg = IRInst__getOperandSource(inst,operandIndex);
  operandRecord = IRInst__getOperandRecord(inst,operandIndex);
  loopCounter = 0;
  operandSelectBytes[0] = *(undefined4 *)(operandRecord + 0x10);
  while ((bVar2 = *(byte *)((int)operandSelectBytes + loopCounter), bVar2 == 4 ||
         (operandRecord = IRInst__getOperandRecord(operandVReg,0), *(char *)((uint)bVar2 + operandRecord + 0x10) != '\x01'))) {
    bVar1 = loopCounter == 3;
    loopCounter = loopCounter + 1;
    if (bVar1) {
      return 1;
    }
  }
  return 0;
}

/* IRInst__writeMasksOverlap @ 0xf497c (168 bytes) */
int IRInst__writeMasksOverlap(inst, inst2)
  undefined4 inst;
  undefined4 inst2;
{
  int operandRecord;
  int iVar1;
  uint instWriteMask;
  uint inst2WriteMask;
  uint selectedMask [5];
  
  operandRecord = IRInst__getOperandRecord(inst,0);
  ((int (*)())WriteMask__fromSelectWord)(&instWriteMask,*(undefined4 *)(operandRecord + 0x10));
  iVar1 = IRInst__isProjectionOfOpcode2a(inst2);
  if (iVar1 == 0) {
    operandRecord = IRInst__getOperandRecord(inst2,0);
    ((int (*)())laneBytes__selectWhereFirstIsOne)(selectedMask,*(undefined4 *)(operandRecord + 0x10),DAT_001aa840);
    inst2WriteMask = selectedMask[0];
  }
  else {
    operandRecord = IRInst__getOperandRecord(inst2,0);
    ((int (*)())WriteMask__fromSelectWord)(&inst2WriteMask,*(undefined4 *)(operandRecord + 0x10));
  }
  return (instWriteMask & inst2WriteMask) != 0;
}

/* ConstRecords__fillFloat4 @ 0xf4a24 (56 bytes) */
int ConstRecords__fillFloat4(floatWords, constRecords)
  undefined4 *floatWords;
  undefined4 *constRecords;
{
  constRecords[0x12] = 2;
  *constRecords = 2;
  constRecords[6] = 2;
  constRecords[0xc] = 2;
  constRecords[1] = *floatWords;
  constRecords[7] = floatWords[1];
  constRecords[0xd] = floatWords[2];
  constRecords[0x13] = floatWords[3];
  return;
}

/* RegisterMap__nextTempIndex @ 0xf4a5c (20 bytes) */
int RegisterMap__nextTempIndex(registerMap)
  int registerMap;
{
  int iVar1;
  
  iVar1 = *(int *)(registerMap + 0x30);
  *(int *)(registerMap + 0x30) = iVar1 + -1;
  return iVar1;
}

/* isRegKindBelow21 @ 0xf4a70 (20 bytes) */
int isRegKindBelow21(param_1)
  uint param_1;
{
  return param_1 >> 0x10 < 0x15;
}

/* Emitter__allocateConstantSlot @ 0xf4a84 (324 bytes) */
int Emitter__allocateConstantSlot(emitter, slotKind, allowFailure, unusedArg4, unusedArg5, unusedArg6, unusedArg7)
  int *emitter;
  int slotKind;
  int allowFailure;
  undefined4 unusedArg4;
  undefined4 unusedArg5;
  undefined4 unusedArg6;
  undefined4 unusedArg7;
{
  int emitContext;
  int slotTableBase;
  
  if (slotKind == 2) {
    emitContext = *(int *)(*emitter + 0x398);
    if (emitter[0xb] == 0) {
      slotTableBase = *(int *)(emitContext + 0x2c);
    }
    else {
      slotTableBase = *(int *)(emitContext + 0x30);
    }
    emitContext = BitSet256__findNthSetBit(emitContext,slotTableBase + 0x58,emitter[0xe],unusedArg4,unusedArg5,unusedArg6,unusedArg7);
    if (-1 < emitContext) {
      emitter[0xe] = emitter[0xe] + 1;
    }
    goto LAB_000f4b94;
  }
  if (slotKind < 3) {
    if (slotKind != 1) {
LAB_000f4ac4:
      emitContext = -1;
      goto LAB_000f4b94;
    }
  }
  else if (slotKind != 3) {
    if (slotKind == 4) {
      emitContext = *(int *)(*emitter + 0x398);
      if (emitter[0xb] == 0) {
        slotTableBase = *(int *)(emitContext + 0x2c);
      }
      else {
        slotTableBase = *(int *)(emitContext + 0x30);
      }
      emitContext = BitSet256__findNthSetBit(emitContext,slotTableBase + 0x98,emitter[0x10],unusedArg4,unusedArg5,unusedArg6,unusedArg7);
      if (-1 < emitContext) {
        emitter[0x10] = emitter[0x10] + 1;
      }
      goto LAB_000f4b94;
    }
    goto LAB_000f4ac4;
  }
  emitContext = *(int *)(*emitter + 0x398);
  if (emitter[0xb] == 0) {
    slotTableBase = *(int *)(emitContext + 0x2c);
  }
  else {
    slotTableBase = *(int *)(emitContext + 0x30);
  }
  emitContext = BitSet256__findNthSetBit(emitContext,slotTableBase + 0x78,emitter[0xf],unusedArg4,unusedArg5,unusedArg6,unusedArg7);
  if (-1 < emitContext) {
    emitter[0xf] = emitter[0xf] + 1;
  }
LAB_000f4b94:
  if ((allowFailure == 0) && (emitContext < 0)) {
    Compiler__fail(*emitter,0xd);
  }
  return emitContext;
}

/* floatLess @ 0xf4bc8 (32 bytes) */
int floatLess(param_1_w, param_2_w)
  unsigned int param_1_w;
  unsigned int param_2_w;
{
  float param_1 = GH_U2F(param_1_w);
  float param_2 = GH_U2F(param_2_w);
  return param_2 < param_1;
}

/* BitSet__findFirstSet @ 0xf4be8 (92 bytes) */
int BitSet__findFirstSet(bitWords, wordCount)
  uint *bitWords;
  int wordCount;
{
  uint wordBits;
  int loopCounter;
  int loopIndex;
  int loopCounterB;
  
  if (0 < wordCount) {
    loopIndex = 0;
    loopCounter = 0;
    do {
      wordBits = *bitWords;
      bitWords = bitWords + 1;
      if (wordBits == 0) {
        loopCounter = loopCounter + 0x20;
      }
      else {
        loopCounterB = 0x20;
        do {
          if ((wordBits & 1) != 0) {
            return loopCounter;
          }
          wordBits = wordBits >> 1;
          loopCounter = loopCounter + 1;
          loopCounterB = loopCounterB + -1;
        } while (loopCounterB != 0);
      }
      loopIndex = loopIndex + 1;
    } while (wordCount != loopIndex);
  }
  return -1;
}

/* noop_f4c44 @ 0xf4c44 (4 bytes) */
int noop_f4c44()
{
  return;
}

/* ConstKey__compareOrdered @ 0xf4c48 (268 bytes) */
int ConstKey__compareOrdered(keyA, keyB, passThroughR5, passThroughR6, passThroughR7, passThroughR8)
  int keyA;
  int keyB;
  undefined4 passThroughR5;
  undefined4 passThroughR6;
  undefined4 passThroughR7;
  undefined4 passThroughR8;
{
  uint kindA;
  int operandIndex;
  int operandA;
  uint presenceBit;
  int operandB;
  int presentOperands;
  bool aIsLess;
  int presenceLoopRemaining;
  
  presentOperands = 0;
  presenceBit = 3;
  presenceLoopRemaining = 4;
  do {
    if (((int)*(char *)(keyA + 0x15c) >> (presenceBit & 0x3f) & 1U) == 0) {
      if (((int)*(char *)(keyB + 0x15c) >> (presenceBit & 0x3f) & 1U) != 0) {
        return 1;
      }
    }
    else {
      if (((int)*(char *)(keyB + 0x15c) >> (presenceBit & 0x3f) & 1U) == 0) {
        return 0xffffffff;
      }
      presentOperands = presentOperands + 1;
    }
    presenceBit = presenceBit - 1;
    presenceLoopRemaining = presenceLoopRemaining + -1;
  } while (presenceLoopRemaining != 0);
  if (0 < presentOperands) {
    operandIndex = 0;
    do {
      operandA = operandIndex * 0x18 + 0x10;
      operandB = keyB + operandA;
      operandA = keyA + operandA;
      kindA = *(uint *)(operandA + 0xc);
      if (kindA != *(uint *)(operandB + 0xc)) {
        aIsLess = kindA < *(uint *)(operandB + 0xc);
LAB_000f4d20:
        if (!aIsLess) {
          return 1;
        }
        return 0xffffffff;
      }
      if (*(uint *)(operandA + 0x10) != *(uint *)(operandB + 0x10)) {
        if (kindA == 2) {
          aIsLess = *(float *)(operandA + 0x10) < *(float *)(operandB + 0x10);
        }
        else {
          aIsLess = *(uint *)(operandA + 0x10) < *(uint *)(operandB + 0x10);
        }
        goto LAB_000f4d20;
      }
      presentOperands = presentOperands + -1;
      operandIndex = operandIndex + 1;
    } while (presentOperands != 0);
  }
  return 0;
}

/* ConstKey__countPresentOperands @ 0xf4d54 (44 bytes) */
int ConstKey__countPresentOperands(constInst, unusedArg2, unusedArg3, unusedArg4, unusedArg5, unusedArg6, unusedArg7)
  int constInst;
  undefined4 unusedArg2;
  undefined4 unusedArg3;
  undefined4 unusedArg4;
  undefined4 unusedArg5;
  undefined4 unusedArg6;
  undefined4 unusedArg7;
{
  uint loopCounterB;
  int loopCounter;
  
  loopCounterB = 0;
  loopCounter = 4;
  do {
    if (((int)*(char *)(constInst + 0x15c) >> (loopCounterB & 0x3f) & 1U) == 0) {
      return;
    }
    loopCounterB = loopCounterB + 1;
    loopCounter = loopCounter + -1;
  } while (loopCounter != 0);
  return;
}

/* ConstRecord__findInTable @ 0xf4d80 (92 bytes) */
int ConstRecord__findInTable(constTables, constRecord)
  int constTables;
  int constRecord;
{
  uint loopCounterB;
  undefined4 *selectedTable;
  int loopCounter;
  /* issue #64 live-repro (crash #4, past the case-0x28 fix): local_2c/local_28/local_24/
   * local_20/local_1c were 5 SEPARATELY declared locals that selectedTable's pointer arithmetic
   * (`selectedTable = selectedTable + 1`, below) treats as one contiguous 5-word array - the same
   * Ghidra local-splitting defect class already fixed in Program__translateILStream and ffpsBuildProgram's
   * local_68 cluster. An initial fix just gave local_2c a value (matching the +4-per-slot
   * source pattern the other four follow: local_28=constTables+8, local_24=+0xc, local_20=+0x10,
   * local_1c=+0x14, so local_2c=+4) but that alone was insufficient: live-verified via a real
   * disassembly of this rebuild that gcc placed local_2c at frame offset 84 while
   * local_28/local_24/local_20/local_1c landed at offsets 68/64/60/56 - contiguous with EACH
   * OTHer but 16 bytes away from local_2c - so selectedTable's forward walk from &local_2c by separate
   * declared locals never actually reaches them; it walks off into unrelated stack space,
   * which happened to read back as 0 and crashed three frames down in HashTable__remove
   * (constTables[4]() through a NULL dispatch pointer). Fixed properly this time by giving the
   * cluster real, guaranteed-contiguous storage as an array, per this project's own
   * established fix pattern for this exact defect class. */
  undefined4 local_cluster[5];

  loopCounterB = 0;
  selectedTable = local_cluster;
  loopCounter = 4;
  do {
    if (((int)*(char *)(constRecord + 0x15c) >> (loopCounterB & 0x3f) & 1U) == 0) break;
    loopCounterB = loopCounterB + 1;
    selectedTable = selectedTable + 1;
    loopCounter = loopCounter + -1;
  } while (loopCounter != 0);
  local_cluster[0] = *(undefined4 *)(constTables + 4);
  local_cluster[1] = *(undefined4 *)(constTables + 8);
  local_cluster[2] = *(undefined4 *)(constTables + 0xc);
  local_cluster[3] = *(undefined4 *)(constTables + 0x10);
  local_cluster[4] = *(undefined4 *)(constTables + 0x14);
  return HashTable__remove(*selectedTable,constRecord);
}

