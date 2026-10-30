#include "decls.h"

/* SelectWord__areCompatible @ 0xf2d18 (144 bytes) */
int SelectWord__areCompatible(param_1, param_2)
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

/* laneBytes__mapTwoThreeToOne @ 0xf2e50 (72 bytes) */
int laneBytes__mapTwoThreeToOne(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  unsigned int ghidra_home[8] = { param_1, param_2, 0, 0, 0, 0, 0, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  char *pcVar1;
  int loopCounter;
  
  (*(unsigned int *)((unsigned char *)ghidra_home + 4)) = param_2;
  loopCounter = 4;
  pcVar1 = (char *)&(*(unsigned int *)((unsigned char *)ghidra_home + 4));
  do {
    if ((byte)(*pcVar1 - 2U) < 2) {
      *pcVar1 = '\x01';
    }
    pcVar1 = pcVar1 + 1;
    loopCounter = loopCounter + -1;
  } while (loopCounter != 0);
  *param_1 = (*(unsigned int *)((unsigned char *)ghidra_home + 4));
  return param_1;
}

/* laneBytes__mergeOneAndTwo @ 0xf2e98 (144 bytes) */
int laneBytes__mergeOneAndTwo(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  int loopCounter;
  unsigned int ghidra_home[8] = { param_1, param_2, 0, 0, 0, 0, 0, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  bool bVar1;
  bool bVar2;
  char *pcVar3;
  char *pcVar4;
  int iVar5;
  
  pcVar3 = (char *)&(*(unsigned int *)((unsigned char *)ghidra_home + 4));
  loopCounter = 4;
  (*(unsigned int *)((unsigned char *)ghidra_home + 4)) = param_2;
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
    loopCounter = loopCounter + -1;
  } while (loopCounter != 0);
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
  *param_1 = (*(unsigned int *)((unsigned char *)ghidra_home + 4));
  return param_1;
}

/* SelectWord__markLanesWhereSecondIsOne @ 0xf2f28 (92 bytes) */
int SelectWord__markLanesWhereSecondIsOne(result, selectWordA, selectWordB)
  undefined4 *result;
  undefined4 selectWordA;
  undefined4 selectWordB;
{
  unsigned int ghidra_home[8] = { result, selectWordA, selectWordB, 0, 0, 0, 0, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  char *pcVar1;
  char *pcVar2;
  int loopCounter;
  
  (*(unsigned int *)((unsigned char *)ghidra_home + 4)) = selectWordA;
  loopCounter = 4;
  (*(unsigned int *)((unsigned char *)ghidra_home + 8)) = selectWordB;
  pcVar1 = (char *)&(*(unsigned int *)((unsigned char *)ghidra_home + 4));
  pcVar2 = (char *)&(*(unsigned int *)((unsigned char *)ghidra_home + 8));
  do {
    if ((1 < (byte)(*pcVar1 - 2U)) && (*pcVar2 == '\x01')) {
      *pcVar1 = '\x01';
    }
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
    loopCounter = loopCounter + -1;
  } while (loopCounter != 0);
  *result = (*(unsigned int *)((unsigned char *)ghidra_home + 4));
  return result;
}

/* SelectWord__mergeWrittenLanes @ 0xf2f84 (92 bytes) */
int SelectWord__mergeWrittenLanes(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  unsigned int ghidra_home[8] = { param_1, param_2, param_3, 0, 0, 0, 0, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  char *pcVar1;
  char *pcVar2;
  int loopCounter;
  
  (*(unsigned int *)((unsigned char *)ghidra_home + 4)) = param_2;
  loopCounter = 4;
  (*(unsigned int *)((unsigned char *)ghidra_home + 8)) = param_3;
  pcVar1 = (char *)&(*(unsigned int *)((unsigned char *)ghidra_home + 4));
  pcVar2 = (char *)&(*(unsigned int *)((unsigned char *)ghidra_home + 8));
  do {
    if ((1 < (byte)(*pcVar1 - 2U)) && (*pcVar2 == '\0')) {
      *pcVar1 = '\0';
    }
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
    loopCounter = loopCounter + -1;
  } while (loopCounter != 0);
  *param_1 = (*(unsigned int *)((unsigned char *)ghidra_home + 4));
  return param_1;
}

/* SelectWord__fillUnusedLanes @ 0xf2fe0 (76 bytes) */
int SelectWord__fillUnusedLanes(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  unsigned int ghidra_home[8] = { param_1, param_2, param_3, 0, 0, 0, 0, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  char *pcVar1;
  char *pcVar2;
  int loopCounter;
  
  (*(unsigned int *)((unsigned char *)ghidra_home + 4)) = param_2;
  loopCounter = 4;
  (*(unsigned int *)((unsigned char *)ghidra_home + 8)) = param_3;
  pcVar1 = (char *)&(*(unsigned int *)((unsigned char *)ghidra_home + 4));
  pcVar2 = (char *)&(*(unsigned int *)((unsigned char *)ghidra_home + 8));
  do {
    if (*pcVar1 == '\x04') {
      *pcVar1 = *pcVar2;
    }
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
    loopCounter = loopCounter + -1;
  } while (loopCounter != 0);
  *param_1 = (*(unsigned int *)((unsigned char *)ghidra_home + 4));
  return param_1;
}

/* SelectWord__markEqualLanes @ 0xf302c (96 bytes) */
int SelectWord__markEqualLanes(result, selectWordA, selectWordB)
  undefined4 *result;
  undefined4 selectWordA;
  undefined4 selectWordB;
{
  unsigned int ghidra_home[8] = { result, selectWordA, selectWordB, 0, 0, 0, 0, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  int loopCounter;
  
  (*(unsigned int *)((unsigned char *)ghidra_home + 4)) = selectWordA;
  loopCounter = 4;
  (*(unsigned int *)((unsigned char *)ghidra_home + 8)) = selectWordB;
  pcVar3 = (char *)&(*(unsigned int *)((unsigned char *)ghidra_home + 4));
  pcVar2 = (char *)&(*(unsigned int *)((unsigned char *)ghidra_home + 8));
  do {
    cVar1 = *pcVar2;
    if (((cVar1 == *pcVar3) && (cVar1 != '\x03')) && (cVar1 != '\x02')) {
      *pcVar3 = '\x01';
    }
    pcVar3 = pcVar3 + 1;
    pcVar2 = pcVar2 + 1;
    loopCounter = loopCounter + -1;
  } while (loopCounter != 0);
  *result = (*(unsigned int *)((unsigned char *)ghidra_home + 4));
  return result;
}

/* laneBytes__commonSelect @ 0xf308c (72 bytes) */
int laneBytes__commonSelect(param_1)
  undefined4 param_1;
{
  unsigned int ghidra_home[8] = { param_1, 0, 0, 0, 0, 0, 0, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  uint uVar1;
  byte *pbVar2;
  uint uVar3;
  uint uVar4;
  int loopCounter;
  
  (*(unsigned int *)((unsigned char *)ghidra_home + 0)) = param_1;
  loopCounter = 4;
  pbVar2 = (byte *)&(*(unsigned int *)((unsigned char *)ghidra_home + 0));
  uVar3 = 0xffffffff;
  while (((uVar1 = (uint)*pbVar2, uVar4 = uVar3, uVar1 == 4 || (uVar4 = uVar1, (int)uVar3 < 0)) ||
         (uVar1 == uVar3))) {
    pbVar2 = pbVar2 + 1;
    loopCounter = loopCounter + -1;
    uVar3 = uVar4;
    if (loopCounter == 0) {
      return uVar4;
    }
  }
  return 0xffffffff;
}

/* SelectWord__firstWrittenComponent @ 0xf30d4 (52 bytes) */
int SelectWord__firstWrittenComponent(param_1)
  undefined4 param_1;
{
  unsigned int ghidra_home[8] = { param_1, 0, 0, 0, 0, 0, 0, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  char *pcVar1;
  int loopCounter;
  int loopCounterB;
  
  (*(unsigned int *)((unsigned char *)ghidra_home + 0)) = param_1;
  loopCounterB = 4;
  loopCounter = 0;
  pcVar1 = (char *)&(*(unsigned int *)((unsigned char *)ghidra_home + 0));
  do {
    if (*pcVar1 != '\x01') {
      return loopCounter;
    }
    loopCounter = loopCounter + 1;
    pcVar1 = pcVar1 + 1;
    loopCounterB = loopCounterB + -1;
  } while (loopCounterB != 0);
  return -1;
}

/* SelectWord__firstUnwrittenComponent @ 0xf3108 (52 bytes) */
int SelectWord__firstUnwrittenComponent(param_1)
  undefined4 param_1;
{
  unsigned int ghidra_home[8] = { param_1, 0, 0, 0, 0, 0, 0, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  char *pcVar1;
  int loopCounter;
  int loopCounterB;
  
  (*(unsigned int *)((unsigned char *)ghidra_home + 0)) = param_1;
  loopCounterB = 4;
  loopCounter = 0;
  pcVar1 = (char *)&(*(unsigned int *)((unsigned char *)ghidra_home + 0));
  do {
    if (*pcVar1 == '\x01') {
      return loopCounter;
    }
    loopCounter = loopCounter + 1;
    pcVar1 = pcVar1 + 1;
    loopCounterB = loopCounterB + -1;
  } while (loopCounterB != 0);
  return -1;
}

/* FUN_000f313c @ 0xf313c (24 bytes) */
int FUN_000f313c(param_1, param_2)
  int param_1;
  int param_2;
{
  return -(uint)(*(byte *)(param_2 + param_1 + 0x9c) ^ 1) >> 0x1f;
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

/* SelectWord__isIdentity @ 0xf3190 (88 bytes) */
int SelectWord__isIdentity(param_1)
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

/* IRInst__isSourceSelectIdentity @ 0xf31e8 (16 bytes) */
int IRInst__isSourceSelectIdentity(param_1, param_2)
  int param_1;
  int param_2;
{
  undefined4 isIdentity;
  
  isIdentity = ((int (*)())SelectWord__isIdentity)(*(undefined4 *)(param_2 * 0x18 + param_1 + 0x9c));
  return isIdentity;
}

/* SelectWord__selectWhereMasked @ 0xf31f8 (96 bytes) */
int SelectWord__selectWhereMasked(param_1, param_2, param_3)
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

/* SelectWord__clearReadComponents @ 0xf3258 (116 bytes) */
int SelectWord__clearReadComponents(param_1, param_2)
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

/* SelectWord__maskUnused @ 0xf3340 (88 bytes) */
int SelectWord__maskUnused(param_1, param_2, param_3)
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

/* SelectWord__readMask @ 0xf3398 (96 bytes) */
int SelectWord__readMask(param_1, param_2)
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

/* SelectWord__fillUnusedWithFirstUsed @ 0xf33f8 (120 bytes) */
int SelectWord__fillUnusedWithFirstUsed(result, selectWord)
  undefined4 *result;
  undefined4 selectWord;
{
  unsigned int ghidra_home[8] = { result, selectWord, 0, 0, 0, 0, 0, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  char *pcVar1;
  char *pcVar2;
  int loopCounter;
  int loopCounterB;
  
  pcVar2 = (char *)&(*(unsigned int *)((unsigned char *)ghidra_home + 4));
  loopCounterB = 4;
  (*(unsigned int *)((unsigned char *)ghidra_home + 4)) = selectWord;
  loopCounter = 0;
  pcVar1 = pcVar2;
  do {
    if (*pcVar1 != '\x04') {
      loopCounterB = 4;
      do {
        if (*pcVar2 == '\x04') {
          *pcVar2 = *(char *)((int)&(*(unsigned int *)((unsigned char *)ghidra_home + 4)) + loopCounter);
        }
        pcVar2 = pcVar2 + 1;
        loopCounterB = loopCounterB + -1;
      } while (loopCounterB != 0);
      *result = (*(unsigned int *)((unsigned char *)ghidra_home + 4));
      return;
    }
    loopCounter = loopCounter + 1;
    pcVar1 = pcVar1 + 1;
    loopCounterB = loopCounterB + -1;
  } while (loopCounterB != 0);
  *result = selectWord;
  return;
}

/* FUN_000f3470 @ 0xf3470 (340 bytes) */
int FUN_000f3470(param_1, param_2)
  uint *param_1;
  uint param_2;
{
  int loopCounter;
  unsigned int ghidra_home[8] = { param_1, param_2, 0, 0, 0, 0, 0, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  bool bVar1;
  bool bVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  byte *pbVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  
  (*(unsigned int *)((unsigned char *)ghidra_home + 4)) = param_2;
  uVar3 = (*(unsigned char *)((unsigned char *)ghidra_home + 4));
  (*(byte *)((unsigned char *)ghidra_home + 4)) = (byte)(param_2 >> 0x18);
  uVar4 = (uint)(*(byte *)((unsigned char *)ghidra_home + 4));
  if (uVar4 == 4) {
    bVar2 = true;
    iVar8 = 1;
    do {
      uVar7 = (uint)(&(*(unsigned int *)((unsigned char *)ghidra_home + 4)))[iVar8];
      iVar9 = iVar8;
      if ((uVar7 != 4) && (iVar9 = iVar8 + 1, uVar4 = uVar7, iVar9 < 4)) {
        iVar5 = 4 - iVar9;
        pbVar6 = (byte *)(&(*(unsigned int *)((unsigned char *)ghidra_home + 5)) + iVar8);
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
    loopCounter = 4;
    bVar2 = true;
    pbVar6 = &(*(unsigned int *)((unsigned char *)ghidra_home + 4));
    do {
      if (*pbVar6 == 4) {
        bVar1 = true;
      }
      else if (uVar4 != *pbVar6) {
        bVar2 = false;
      }
      pbVar6 = pbVar6 + 1;
      loopCounter = loopCounter + -1;
    } while (loopCounter != 0);
    if (!bVar1) goto LAB_000f35b4;
  }
  if (bVar2) {
    *param_1 = (DAT_001aa818)[uVar4];
    return;
  }
  bVar1 = (*(byte *)((unsigned char *)ghidra_home + 4)) == 4;
  (*(unsigned char *)((unsigned char *)ghidra_home + 4)) = uVar3;
  if (bVar1) {
    (*(unsigned int *)((unsigned char *)ghidra_home + 4)) = param_2 & 0xffffff;
  }
  if ((*(char *)((unsigned char *)ghidra_home + 5)) == '\x04') {
    (*(char *)((unsigned char *)ghidra_home + 5)) = CONCAT12(1,(*(char *)((unsigned char *)ghidra_home + 6)));
  }
  if ((*(char *)((unsigned char *)ghidra_home + 6)) == '\x04') {
    (*(char *)((unsigned char *)ghidra_home + 6)) = CONCAT11(2,(*(char *)((unsigned char *)ghidra_home + 7)));
  }
  uVar3 = (*(unsigned char *)((unsigned char *)ghidra_home + 4));
  if ((*(char *)((unsigned char *)ghidra_home + 7)) == '\x04') {
    (*(unsigned char *)((unsigned char *)ghidra_home + 4)) = CONCAT31((*(unsigned char *)((unsigned char *)ghidra_home + 4)),3);
    uVar3 = (*(unsigned char *)((unsigned char *)ghidra_home + 4));
  }
LAB_000f35b4:
  (*(unsigned char *)((unsigned char *)ghidra_home + 4)) = uVar3;
  *param_1 = (*(unsigned char *)((unsigned char *)ghidra_home + 4));
  return;
}

/* IRInst__clearSourceSelectsOfUnwrittenComponents @ 0xf35c4 (168 bytes) */
int IRInst__clearSourceSelectsOfUnwrittenComponents(inst)
  int *inst;
{
  int operandRecord;
  bool bVar1;
  int iVar2;
  int iVar3;
  int loopCounter;
  undefined4 local_38 [9];
  
  loopCounter = 0;
  operandRecord = IRInst__getOperandRecord(inst,0);
  local_38[0] = *(undefined4 *)(operandRecord + 0x10);
  do {
    iVar2 = 1;
    if (*(char *)((int)local_38 + loopCounter) == '\x01') {
      for (; iVar3 = (**(code **)(*inst + 0x14))(inst), iVar2 <= iVar3; iVar2 = iVar2 + 1) {
        (**(code **)(*inst + 0x88))(inst,iVar2,loopCounter,4);
      }
    }
    bVar1 = loopCounter != 3;
    loopCounter = loopCounter + 1;
  } while (bVar1);
  return;
}

/* FUN_000f366c @ 0xf366c (76 bytes) */
int FUN_000f366c(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  unsigned int ghidra_home[8] = { param_1, param_2, 0, 0, 0, 0, 0, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  byte *pbVar1;
  int loopCounter;
  
  (*(unsigned int *)((unsigned char *)ghidra_home + 4)) = param_2;
  loopCounter = 4;
  *param_1 = DAT_001aa838;
  pbVar1 = (byte *)&(*(unsigned int *)((unsigned char *)ghidra_home + 4));
  do {
    if (*pbVar1 != 4) {
      *(undefined1 *)((int)param_1 + (uint)*pbVar1) = 0;
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
  char *pcVar1;
  int loopCounter;
  
  (*(unsigned int *)((unsigned char *)ghidra_home + 4)) = selectWord;
  pcVar1 = (char *)&(*(unsigned int *)((unsigned char *)ghidra_home + 4));
  loopCounter = 4;
  *result = DAT_001aa838;
  do {
    if (*pcVar1 != '\x04') {
      *(undefined1 *)result = 0;
    }
    pcVar1 = pcVar1 + 1;
    result = (undefined4 *)((int)result + 1);
    loopCounter = loopCounter + -1;
  } while (loopCounter != 0);
  return;
}

/* FUN_000f370c @ 0xf370c (88 bytes) */
int FUN_000f370c(param_1, param_2)
  char *param_1;
  undefined4 param_2;
{
  unsigned int ghidra_home[8] = { param_1, param_2, 0, 0, 0, 0, 0, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  char *pcVar1;
  char cVar2;
  int loopCounter;
  
  (*(unsigned int *)((unsigned char *)ghidra_home + 4)) = param_2;
  cVar2 = '\0';
  pcVar1 = (char *)&(*(unsigned int *)((unsigned char *)ghidra_home + 4));
  loopCounter = 4;
  *(undefined4 *)param_1 = DAT_001aa83c;
  do {
    if (*pcVar1 == '\0') {
      *param_1 = cVar2;
    }
    cVar2 = cVar2 + '\x01';
    pcVar1 = pcVar1 + 1;
    param_1 = param_1 + 1;
    loopCounter = loopCounter + -1;
  } while (loopCounter != 0);
  return;
}

/* laneBytes__clearSetLanes @ 0xf3764 (84 bytes) */
int laneBytes__clearSetLanes(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  unsigned int ghidra_home[8] = { param_1, param_2, 0, 0, 0, 0, 0, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  char *pcVar1;
  int loopCounter;
  
  (*(unsigned int *)((unsigned char *)ghidra_home + 4)) = param_2;
  pcVar1 = (char *)&(*(unsigned int *)((unsigned char *)ghidra_home + 4));
  loopCounter = 4;
  *param_1 = DAT_001aa838;
  do {
    if (*pcVar1 != '\0') {
      *(undefined1 *)param_1 = 0;
    }
    pcVar1 = pcVar1 + 1;
    param_1 = (undefined4 *)((int)param_1 + 1);
    loopCounter = loopCounter + -1;
  } while (loopCounter != 0);
  return;
}

/* SelectWord__splatComponent @ 0xf37b8 (108 bytes) */
int SelectWord__splatComponent(param_1)
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

/* SelectWord__isSingleComponentConstant @ 0xf3824 (96 bytes) */
int SelectWord__isSingleComponentConstant(param_1)
  int param_1;
{
  if ((((param_1 != DAT_001aa85c) && (param_1 != DAT_001aa858)) && (param_1 != DAT_001aa854)) &&
     (param_1 != DAT_001aa850)) {
    return 0;
  }
  return 1;
}

/* IRInst__destIsSingleComponent @ 0xf3884 (8 bytes) */
int IRInst__destIsSingleComponent(param_1)
  int param_1;
{
  undefined4 uVar1;
  
  uVar1 = ((int (*)())SelectWord__isSingleComponentConstant)(*(undefined4 *)(param_1 + 0x9c));
  return uVar1;
}

/* laneMask__fromSelectBytes @ 0xf388c (124 bytes) */
int laneMask__fromSelectBytes(param_1, param_2, param_3)
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

/* WriteMask__fromSelectWord @ 0xf3908 (96 bytes) */
int WriteMask__fromSelectWord(param_1, param_2)
  byte *param_1;
  uint param_2;
{
  param_1[0] = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[3] = (byte)(-(uint)((param_2 ^ 1) & 0xff) >> 0x1f);
  *param_1 = (byte)(-(uint)(param_2 >> 0x18 ^ 1) >> 0x1f);
  param_1[1] = (byte)(-(uint)(param_2 >> 0x10 & 0xff ^ 1) >> 0x1f);
  param_1[2] = (byte)(-(uint)(param_2 >> 8 & 0xff ^ 1) >> 0x1f);
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

/* IRInst__countWrittenComponents @ 0xf3a30 (96 bytes) */
int IRInst__countWrittenComponents(inst)
  undefined4 inst;
{
  bool bVar1;
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
    bVar1 = loopCounterB != 3;
    loopCounterB = loopCounterB + 1;
  } while (bVar1);
  return loopCounter;
}

/* FUN_000f3a90 @ 0xf3a90 (80 bytes) */
int FUN_000f3a90(inst)
  undefined4 inst;
{
  uint uVar1;
  int operandRecord;
  undefined4 uVar3;
  
  operandRecord = IRInst__getOperandRecord(inst,0);
  uVar1 = *(uint *)(operandRecord + 0x10);
  if (((uVar1 >> 0x18 == 0) || ((uVar1 >> 0x10 & 0xff) == 0)) ||
     (uVar3 = 0, (uVar1 >> 8 & 0xff) == 0)) {
    uVar3 = 1;
  }
  return uVar3;
}

/* FUN_000f3ae0 @ 0xf3ae0 (48 bytes) */
int FUN_000f3ae0(inst)
  undefined4 inst;
{
  int operandRecord;
  
  operandRecord = IRInst__getOperandRecord(inst,0);
  return *(char *)(operandRecord + 0x13) == '\0';
}

/* FUN_000f3b10 @ 0xf3b10 (88 bytes) */
int FUN_000f3b10(inst, operandIndex)
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

/* FUN_000f3b68 @ 0xf3b68 (88 bytes) */
int FUN_000f3b68(inst, operandIndex)
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

/* FUN_000f3bc0 @ 0xf3bc0 (112 bytes) */
int FUN_000f3bc0(inst, operandIndex)
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
  int loopCounterB;
  int operandRecord;
  int loopCounter;
  unsigned int ghidra_home[8] = { laneMask, inst, operandIndex, program, destSelectWord, 0, 0, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  bool bVar1;
  uint uVar2;
  byte *pbVar3;
  int iVar4;
  undefined4 uVar5;
  char *pcVar6;
  int operandRecordB;
  undefined4 local_38;
  undefined4 local_34 [7];
  
  (*(unsigned int *)((unsigned char *)ghidra_home + 16)) = destSelectWord;
  (**(code **)(*inst + 0x14))(inst,inst,operandIndex,program,destSelectWord);
  laneMask[0] = 0;
  laneMask[1] = 0;
  laneMask[2] = 0;
  laneMask[3] = 0;
  if (0 < operandIndex) {
    iVar4 = IRInst__getOperandSource(inst,operandIndex);
    if (iVar4 == 0) {
      iVar4 = *(int *)(inst[operandIndex * 6 + 0x23] + 4);
    }
    else {
      iVar4 = *(int *)(iVar4 + 0x98);
    }
    if ((iVar4 == 0x3b) || (iVar4 == 0x42)) goto switchD_000f3cf4_caseD_b;
  }
  uVar5 = OpcodeInfo__getResultMode(inst[0x22],inst,program);
  switch(uVar5) {
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
      pbVar3 = laneMask;
      do {
        operandRecordB = IRInst__getOperandRecord(inst,0);
        local_38 = *(undefined4 *)(operandRecordB + 0x10);
        if (*(char *)((int)local_34 + loopCounter + -4) != '\x01') {
          *pbVar3 = *pbVar3 | 1;
        }
        bVar1 = loopCounter != 3;
        pbVar3 = pbVar3 + 1;
        loopCounter = loopCounter + 1;
      } while (bVar1);
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
    iVar4 = 0;
    if (-1 < inst[0x4d]) {
      iVar4 = *(int *)(inst[0x4d] * 0xc + *(int *)(program + 0x78) + 4);
    }
    uVar2 = (DAT_001dc58c)[iVar4 * 2];
    if ((uVar2 & 1) != 0) {
      *laneMask = 1;
    }
    if ((uVar2 & 2) != 0) {
      laneMask[1] = 1;
    }
    if ((uVar2 & 4) != 0) {
      laneMask[2] = 1;
    }
    if ((uVar2 & 8) != 0) {
      laneMask[3] = 1;
    }
    iVar4 = *(int *)(inst[0x22] + 8);
    if ((((iVar4 == 0x101) || (iVar4 == 0x100)) || (iVar4 == 0x102)) || (iVar4 == 0x6e))
    goto LAB_000f3ff4;
    if (((iVar4 == 0x75) || (iVar4 == 0x76)) || (iVar4 == 0xae)) goto switchD_000f3cf4_caseD_2;
    if (((iVar4 != 0x9e) && (iVar4 != 0x9f)) && ((iVar4 != 0xa0 && (iVar4 != 0xa1)))) {
      return laneMask;
    }
    break;
  case 0xb:
    goto switchD_000f3cf4_caseD_b;
  case 0xc:
    operandRecord = IRInst__getOperandRecord(inst,operandIndex);
    loopCounterB = 0;
    pcVar6 = &(*(unsigned int *)((unsigned char *)ghidra_home + 16));
    local_34[0] = *(undefined4 *)(operandRecord + 0x10);
    loopCounter = 4;
    pbVar3 = laneMask;
    do {
      if ((*pcVar6 == '\0') && (*(char *)((int)local_34 + loopCounterB) != '\x04')) {
        *pbVar3 = *pbVar3 | 1;
      }
      loopCounterB = loopCounterB + 1;
      pcVar6 = pcVar6 + 1;
      pbVar3 = pbVar3 + 1;
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
  
  (**(code **)(*inst + 0x14))(inst,inst,operandIndex,destWriteMask,program);
  operandRecord = IRInst__getOperandRecord(inst,operandIndex);
  sourceSelect = *(uint *)(operandRecord + 0x10);
  *laneMask = 0;
  resultMode = OpcodeInfo__getResultMode(inst[0x22],inst,program);
  switch(resultMode) {
  case 0:
    operandRecord = IRInst__getOperandRecord(inst,0);
    ((int (*)())SelectWord__selectWhereMasked)(&local_44,*(undefined4 *)(operandRecord + 0x10),destWriteMask);
    loopCounter = 0;
    maskedSelect[0] = local_44;
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
      ((int (*)())laneMask__fromSelectBytes)(&local_40,sourceSelect,2);
      *laneMask = local_40;
      return laneMask;
    }
    if (operandIndex != 3) {
      return laneMask;
    }
    goto LAB_000f4584;
  case 4:
    ((int (*)())laneMask__fromSelectBytes)(&local_3c,sourceSelect,3);
    *laneMask = local_3c;
    break;
  case 5:
    ((int (*)())laneMask__fromSelectBytes)(&local_38,sourceSelect,4);
    *laneMask = local_38;
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
      ((int (*)())laneMask__fromSelectBytes)(&local_34,sourceSelect,4);
      *laneMask = local_34;
    }
    break;
  case 7:
    if (operandIndex < 3) {
      ((int (*)())laneMask__fromSelectBytes)(&local_30,sourceSelect,3);
      *laneMask = local_30;
      return laneMask;
    }
    goto LAB_000f4594;
  case 8:
    ((int (*)())laneMask__fromSelectBytes)(&local_2c,sourceSelect,4);
    *laneMask = local_2c;
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
        ((int (*)())SelectWord__selectWhereMasked)(&local_28,*(undefined4 *)(operandRecord + 0x10),destWriteMask);
        maskedSelect[0] = local_28;
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
    ((int (*)())SelectWord__selectWhereMasked)(local_24,*(undefined4 *)(operandRecord + 0x10),destWriteMask);
    maskedSelect[0] = local_24[0];
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
      ((int (*)())SelectWord__selectWhereMasked)(&local_48,*(undefined4 *)(operandRecord + 0x10),destWriteMask);
      loopCounter = 0;
      maskedSelect[0] = local_48;
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
int FUN_000f45f8(param_1, operandIndex, inst, param_4)
  undefined4 param_1;
  undefined4 operandIndex;
  undefined4 inst;
  undefined4 param_4;
{
  bool bVar1;
  int operandRecord;
  int loopCounter;
  undefined4 local_28 [4];
  undefined4 local_18 [2];
  
  ((int (*)())IRInst__computeSourceReadMask)(local_18,param_1,operandIndex,DAT_001aa840,param_4);
  loopCounter = 0;
  local_28[0] = local_18[0];
  while ((*(char *)((int)local_28 + loopCounter) == '\0' ||
         (operandRecord = IRInst__getOperandRecord(inst,0), *(char *)(loopCounter + operandRecord + 0x10) != '\x01'))) {
    bVar1 = loopCounter == 3;
    loopCounter = loopCounter + 1;
    if (bVar1) {
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
  undefined4 local_18;
  undefined4 local_14;
  
  operandRecord = IRInst__getOperandRecord(inst,0);
  ((int (*)())IRInst__computeSourceLaneMask)(&local_18,inst,operandIndex,program,*(undefined4 *)(operandRecord + 0x10));
  operandRecord = IRInst__getOperandRecord(inst,operandIndex);
  ((int (*)())SelectWord__maskUnused)(&local_14,*(undefined4 *)(operandRecord + 0x10),local_18);
  if (operandIndex == 0) {
    *(undefined4 *)(inst + 0x9c) = local_14;
  }
  else {
    operandRecord = IRInst__getOperandRecord(inst,operandIndex);
    *(undefined4 *)(operandRecord + 0x10) = local_14;
  }
  return;
}

/* FUN_000f472c @ 0xf472c (124 bytes) */
int FUN_000f472c(param_1, inst)
  int param_1;
  undefined4 inst;
{
  int operandRecord;
  int loopCounter;
  int loopCounterB;
  undefined4 local_28 [8];
  
  operandRecord = IRInst__getOperandRecord(inst,0);
  loopCounter = 0;
  local_28[0] = *(undefined4 *)(operandRecord + 0x10);
  loopCounterB = 4;
  do {
    if (*(char *)((int)local_28 + loopCounter) == '\x01') {
      *(undefined1 *)((int)local_28 + loopCounter) = 0;
    }
    else {
      *(undefined1 *)((int)local_28 + loopCounter) = 1;
    }
    loopCounter = loopCounter + 1;
    loopCounterB = loopCounterB + -1;
  } while (loopCounterB != 0);
  *(undefined4 *)(param_1 + 0x9c) = local_28[0];
  return;
}

/* FUN_000f47a8 @ 0xf47a8 (180 bytes) */
int FUN_000f47a8(param_1, inst, inst2)
  int param_1;
  undefined4 inst;
  undefined4 inst2;
{
  int operandRecord2;
  int operandRecord;
  int loopCounter;
  int loopCounterB;
  undefined4 local_28;
  undefined4 local_24 [6];
  
  operandRecord = IRInst__getOperandRecord(inst,0);
  local_28 = *(undefined4 *)(operandRecord + 0x10);
  operandRecord2 = IRInst__getOperandRecord(inst2,0);
  loopCounter = 0;
  local_24[0] = *(undefined4 *)(operandRecord2 + 0x10);
  loopCounterB = 4;
  do {
    if ((*(char *)((int)local_24 + loopCounter + -4) != '\x01') &&
       (*(char *)((int)local_24 + loopCounter) != '\x01')) break;
    loopCounter = loopCounter + 1;
    loopCounterB = loopCounterB + -1;
  } while (loopCounterB != 0);
  loopCounter = 0;
  loopCounterB = 4;
  do {
    if (*(char *)((int)local_24 + loopCounter) != '\x01') {
      *(char *)((int)local_24 + loopCounter + -4) = *(char *)((int)local_24 + loopCounter);
    }
    loopCounter = loopCounter + 1;
    loopCounterB = loopCounterB + -1;
  } while (loopCounterB != 0);
  *(undefined4 *)(param_1 + 0x9c) = local_28;
  return;
}

/* FUN_000f485c @ 0xf485c (144 bytes) */
int FUN_000f485c(inst, operandIndex)
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
  undefined4 local_38 [9];
  
  operandVReg = IRInst__getOperandSource(inst,operandIndex);
  operandRecord = IRInst__getOperandRecord(inst,operandIndex);
  loopCounter = 0;
  local_38[0] = *(undefined4 *)(operandRecord + 0x10);
  while ((bVar2 = *(byte *)((int)local_38 + loopCounter), bVar2 == 4 ||
         (operandRecord = IRInst__getOperandRecord(operandVReg,0), *(char *)((uint)bVar2 + operandRecord + 0x10) != '\x01'))) {
    bVar1 = loopCounter == 3;
    loopCounter = loopCounter + 1;
    if (bVar1) {
      return 1;
    }
  }
  return 0;
}

/* FUN_000f497c @ 0xf497c (168 bytes) */
int FUN_000f497c(inst, inst2)
  undefined4 inst;
  undefined4 inst2;
{
  int operandRecord;
  int iVar1;
  uint local_28;
  uint local_24;
  uint local_20 [5];
  
  operandRecord = IRInst__getOperandRecord(inst,0);
  ((int (*)())WriteMask__fromSelectWord)(&local_28,*(undefined4 *)(operandRecord + 0x10));
  iVar1 = IRInst__isProjectionOfOpcode2a(inst2);
  if (iVar1 == 0) {
    operandRecord = IRInst__getOperandRecord(inst2,0);
    ((int (*)())FUN_000f3968)(local_20,*(undefined4 *)(operandRecord + 0x10),DAT_001aa840);
    local_24 = local_20[0];
  }
  else {
    operandRecord = IRInst__getOperandRecord(inst2,0);
    ((int (*)())WriteMask__fromSelectWord)(&local_24,*(undefined4 *)(operandRecord + 0x10));
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

/* isRegKindBelow21 @ 0xf4a70 (20 bytes) */
int isRegKindBelow21(param_1)
  uint param_1;
{
  return param_1 >> 0x10 < 0x15;
}

/* Emitter__allocateConstantSlot @ 0xf4a84 (324 bytes) */
int Emitter__allocateConstantSlot(emitter, slotKind, allowFailure, param_4, param_5, param_6, param_7)
  int *emitter;
  int slotKind;
  int allowFailure;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
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
    emitContext = FUN_000d9b58(emitContext,slotTableBase + 0x58,emitter[0xe],param_4,param_5,param_6,param_7);
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
      emitContext = FUN_000d9b58(emitContext,slotTableBase + 0x98,emitter[0x10],param_4,param_5,param_6,param_7);
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
  emitContext = FUN_000d9b58(emitContext,slotTableBase + 0x78,emitter[0xf],param_4,param_5,param_6,param_7);
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
int BitSet__findFirstSet(param_1, param_2)
  uint *param_1;
  int param_2;
{
  uint uVar1;
  int loopCounter;
  int loopIndex;
  int loopCounterB;
  
  if (0 < param_2) {
    loopIndex = 0;
    loopCounter = 0;
    do {
      uVar1 = *param_1;
      param_1 = param_1 + 1;
      if (uVar1 == 0) {
        loopCounter = loopCounter + 0x20;
      }
      else {
        loopCounterB = 0x20;
        do {
          if ((uVar1 & 1) != 0) {
            return loopCounter;
          }
          uVar1 = uVar1 >> 1;
          loopCounter = loopCounter + 1;
          loopCounterB = loopCounterB + -1;
        } while (loopCounterB != 0);
      }
      loopIndex = loopIndex + 1;
    } while (param_2 != loopIndex);
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
int ConstKey__countPresentOperands(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  uint loopCounterB;
  int loopCounter;
  
  loopCounterB = 0;
  loopCounter = 4;
  do {
    if (((int)*(char *)(param_1 + 0x15c) >> (loopCounterB & 0x3f) & 1U) == 0) {
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
   * Ghidra local-splitting defect class already fixed in FUN_000fd5c8 and ffpsBuildProgram's
   * local_68 cluster. An initial fix just gave local_2c a value (matching the +4-per-slot
   * source pattern the other four follow: local_28=constTables+8, local_24=+0xc, local_20=+0x10,
   * local_1c=+0x14, so local_2c=+4) but that alone was insufficient: live-verified via a real
   * disassembly of this rebuild that gcc placed local_2c at frame offset 84 while
   * local_28/local_24/local_20/local_1c landed at offsets 68/64/60/56 - contiguous with EACH
   * OTHer but 16 bytes away from local_2c - so selectedTable's forward walk from &local_2c by separate
   * declared locals never actually reaches them; it walks off into unrelated stack space,
   * which happened to read back as 0 and crashed three frames down in FUN_00194720
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
  return FUN_00194720(*selectedTable,constRecord);
}

