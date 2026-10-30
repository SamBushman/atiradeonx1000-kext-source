#include "decls.h"

/* vpStateSelectForDraw @ 0x76c60 (480 bytes) */
int vpStateSelectForDraw(ctx)
  int ctx;
{
  bool noState;
  int stateKey;
  int currentStateBlock;
  int *slotEntry;
  int iVar5;
  int *shader;
  int slotIndex;
  
  currentStateBlock = *(int *)(((unsigned char *)0x0000148c) + ctx);
  shader = *(int **)(((unsigned char *)0x00001168) + ctx);
  if ((*(uint *)(ctx + 0x44) & 0x100000) == 0) {
                    
                    
    (**(code **)(((unsigned char *)0x000012a4) + ctx))(ctx,shader,1);
    return;
  }
  slotIndex = *(int *)(((unsigned char *)0x0000118c) + ctx);
  slotEntry = *(int **)(slotIndex * 4 + *shader);
  iVar5 = *slotEntry;
  stateKey = vpStateComputeKey(ctx,iVar5);
  if (((*(char *)(shader[1] + slotIndex) == '\0') && (stateKey == *(int *)(iVar5 + 0x38))) &&
     (*(int *)(iVar5 + 4) == shader[0x15])) {
    if ((*(byte *)(ctx + 0x2d) & 4) == 0) {
      noState = iVar5 == 0;
      if ((*(byte *)(ctx + 0x2d) & 3) != 0) {
        vpStateUpdateFogConstants(ctx,iVar5 + 0x13c,shader);
      }
      goto LAB_00076dc0;
    }
    noState = iVar5 == 0;
  }
  else {
    iVar5 = vpStateCacheLookup(slotEntry,stateKey);
    noState = iVar5 == 0;
    if ((noState) || (*(char *)(shader[1] + *(int *)(((unsigned char *)0x0000118c) + ctx)) != '\0')) {
      FUN_000546d0(ctx,shader);
    }
    else {
      *slotEntry = iVar5;
      shader[0x15] = *(int *)(iVar5 + 4);
      *(undefined4 *)(((unsigned char *)0x00001174) + ctx) = *(undefined4 *)(iVar5 + 4);
    }
    *(byte *)(ctx + 0x2d) = *(byte *)(ctx + 0x2d) | 3;
  }
  vpStateApplyParameters(ctx,shader);
  (**(code **)(((unsigned char *)0x000012a4) + ctx))(ctx,shader,0);
LAB_00076dc0:
  (**(code **)(((unsigned char *)0x000012b4) + ctx))(ctx);
  if ((!noState) && (currentStateBlock != iVar5 + 0x13c)) {
                    
                    
    (**(code **)((int)((unsigned char *)0x00001294) + ctx))
              (ctx,iVar5 + 0x13c,*(undefined4 *)(iVar5 + 0x130));
    return;
  }
  return;
}

/* noop_76e60 @ 0x76e60 (4 bytes) */
int noop_76e60()
{
  return;
}

/* vpStateFree @ 0x76e70 (356 bytes) */
int vpStateFree(ctx, state)
  int ctx;
  int state;
{
  int constantsBase;
  
  constantsBase = state + 0x13c;
  if ((constantsBase != 0) && (*(int *)(state + 0x150) != 0)) {
    (**(code **)(((unsigned char *)0x000012ac) + ctx))(ctx,constantsBase);
  }
  if (*(int *)(state + 8) != 0) {
    (**(code **)(ctx + 0x18))(*(int *)(state + 8));
  }
  if (*(int *)(state + 0x10) != 0) {
    (**(code **)(ctx + 0x18))(*(int *)(state + 0x10));
  }
  if (*(int *)(state + 0x3c) != 0) {
    (**(code **)(ctx + 0x18))(*(int *)(state + 0x3c));
  }
  if (*(int *)(state + 0x44) != 0) {
    (**(code **)(ctx + 0x18))(*(int *)(state + 0x44));
  }
  if (*(int *)(state + 0x114) != 0) {
    (**(code **)(ctx + 0x18))(*(int *)(state + 0x114));
  }
  if (*(int *)(state + 0x11c) != 0) {
    (**(code **)(ctx + 0x18))(*(int *)(state + 0x11c));
  }
  if (*(int *)(((unsigned char *)0x000013d8) + state) != 0) {
    (**(code **)(ctx + 0x18))(*(int *)(((unsigned char *)0x000013d8) + state));
  }
  if (*(int *)(state + 0x124) != 0) {
    (**(code **)(ctx + 0x18))(*(int *)(state + 0x124));
  }
  if (constantsBase == *(int *)(((unsigned char *)0x0000148c) + ctx)) {
    *(undefined4 *)(((unsigned char *)0x0000148c) + ctx) = 0;
  }
                    
                    
  (**(code **)(ctx + 0x18))(state);
  return;
}

/* ctxTempListCreate @ 0x76fe0 (76 bytes) */
int ctxTempListCreate(param_1)
  int param_1;
{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(param_1 + 0xc))(0xc);
  *(undefined4 *)(((unsigned char *)0x000011b4) + param_1) = uVar1;
                    
                    
  (**(code **)(((unsigned char *)0x000011b0) + param_1))(param_1);
  return;
}

/* ctxTempListFree @ 0x77030 (84 bytes) */
int ctxTempListFree(param_1)
  int param_1;
{
  if (*(int *)(((unsigned char *)0x000011b4) + param_1) != 0) {
    (**(code **)(param_1 + 0x18))(*(int *)(((unsigned char *)0x000011b4) + param_1));
    *(undefined4 *)(((unsigned char *)0x000011b4) + param_1) = 0;
  }
  return;
}

/* vpStateCacheCreate @ 0x77090 (600 bytes) */
int vpStateCacheCreate(ctx, shaderTable, firstSlot)
  int ctx;
  int *shaderTable;
  uint firstSlot;
{
  int remaining;
  undefined4 *clearCursor;
  int *flagCursor;
  undefined4 *newState;
  undefined4 allocatedPtr;
  int allocatedBlock;
  uint endSlot;
  int slotOffset;
  undefined4 *bucketHead;
  
  if (firstSlot == 0xffffffff) {
    firstSlot = 0;
    endSlot = *(uint *)(*(int *)(((unsigned char *)0x0000116c) + ctx) + 0x10);
  }
  else {
    endSlot = firstSlot + 1;
  }
  slotOffset = firstSlot << 2;
  do {
    bucketHead = *(undefined4 **)(*shaderTable + slotOffset);
    newState = (undefined4 *)(**(code **)(ctx + 0xc))(((unsigned char *)0x000013dcU));
    *newState = 0;
    newState[1] = 0;
    allocatedPtr = (**(code **)(ctx + 0xc))(0x800);
    newState[2] = allocatedPtr;
    newState[3] = 0x200;
    allocatedBlock = (**(code **)(ctx + 0x10))(0x16,0x28);
    newState[4] = allocatedBlock;
    newState[5] = 0x16;
    *(undefined1 *)(allocatedBlock + 0x10) = 1;
    *(undefined1 *)(newState + 6) = 0;
    *(undefined1 *)((int)newState + 0x19) = 0;
    remaining = 8;
    clearCursor = newState;
    do {
      *(undefined1 *)((int)clearCursor + 0x1a) = 0;
      clearCursor = (undefined4 *)((int)clearCursor + 1);
      remaining = remaining + -1;
    } while (remaining != 0);
    remaining = 8;
    clearCursor = newState;
    do {
      *(undefined1 *)((int)clearCursor + 0x22) = 0;
      clearCursor = (undefined4 *)((int)clearCursor + 1);
      remaining = remaining + -1;
    } while (remaining != 0);
    *(undefined1 *)((int)newState + 0x2e) = 0;
    *(undefined1 *)((int)newState + 0x2a) = 0;
    *(undefined1 *)((int)newState + 0x2b) = 0;
    *(undefined1 *)(newState + 0xb) = 0;
    remaining = 4;
    *(undefined1 *)((int)newState + 0x2d) = 0;
    clearCursor = newState;
    do {
      *(undefined1 *)((int)clearCursor + 0x2f) = 0;
      clearCursor = (undefined4 *)((int)clearCursor + 1);
      remaining = remaining + -1;
    } while (remaining != 0);
    remaining = 8;
    flagCursor = shaderTable;
    do {
      *(undefined1 *)((int)flagCursor + 0x71) = 0;
      flagCursor = (int *)((int)flagCursor + 1);
      remaining = remaining + -1;
    } while (remaining != 0);
    *(undefined1 *)((int)newState + 0x37) = 0;
    *(undefined1 *)((int)newState + 0x33) = 0;
    *(undefined1 *)(newState + 0xd) = 0;
    *(undefined1 *)((int)newState + 0x35) = 0;
    *(undefined1 *)((int)newState + 0x36) = 0;
    newState[0xe] = 0;
    allocatedPtr = (**(code **)(ctx + 0x10))(0x20,0x28);
    newState[0xf] = allocatedPtr;
    newState[0x10] = 0x20;
    allocatedPtr = (**(code **)(ctx + 0x10))(0x100,0x28);
    newState[0x13] = 0;
    newState[0x45] = 0;
    newState[0x11] = allocatedPtr;
    newState[0x46] = 0;
    newState[0x12] = 0x100;
    newState[0x47] = 0;
    newState[0x48] = 0;
    newState[0x49] = 0;
    newState[0x4a] = 0;
    newState[0x4c] = 0;
    *(undefined1 *)(newState + 0x4d) = 0;
    newState[0x4e] = 0;
    if (bucketHead == (undefined4 *)0x0) {
      bucketHead = (undefined4 *)(**(code **)(ctx + 0xc))(0x88);
      remaining = 0x20;
      clearCursor = bucketHead;
      do {
        clearCursor = clearCursor + 1;
        *clearCursor = 0;
        remaining = remaining + -1;
      } while (remaining != 0);
      bucketHead[0x21] = 0;
      *(undefined4 **)(*shaderTable + slotOffset) = bucketHead;
    }
    firstSlot = firstSlot + 1;
    *bucketHead = newState;
    slotOffset = slotOffset + 4;
  } while (firstSlot < endSlot);
  return;
}

/* vpStateCacheFreeAll @ 0x772f4 (300 bytes) */
int vpStateCacheFreeAll(ctx, cacheTablePtr, freeAll)
  int ctx;
  int *cacheTablePtr;
  int freeAll;
{
  int loopCounter;
  int *slotPtr;
  bool moreSlots;
  uint endIndex;
  int *slotCursor;
  int cacheTable;
  int variant;
  uint firstIndex;
  int loopIndex;
  int byteOffset;
  int *bucket;
  
  cacheTable = *cacheTablePtr;
  if (cacheTable != 0) {
    if (freeAll == 0) {
      firstIndex = *(uint *)(((unsigned char *)0x0000118c) + ctx);
      endIndex = firstIndex + 1;
    }
    else {
      firstIndex = 0;
      endIndex = *(uint *)(*(int *)(((unsigned char *)0x0000116c) + ctx) + 0x10);
    }
    if (firstIndex < endIndex) {
      byteOffset = firstIndex << 2;
      loopIndex = 0;
      while( true ) {
        bucket = *(int **)(cacheTable + byteOffset);
        if (bucket != (int *)0x0) {
          if (*(char *)(*bucket + 0x134) == '\0') {
            ((int (*)())vpStateFree)(ctx,*bucket);
            *bucket = 0;
          }
          if (freeAll != 0) {
            loopCounter = 0;
            slotCursor = bucket;
            do {
              slotPtr = slotCursor + 1;
              slotCursor = slotCursor + 1;
              variant = *slotPtr;
              while (variant != 0) {
                *slotCursor = *(int *)(variant + 0x138);
                ((int (*)())vpStateFree)(ctx,variant);
                variant = *slotCursor;
              }
              moreSlots = loopCounter != 0x1f;
              loopCounter = loopCounter + 1;
            } while (moreSlots);
            (**(code **)(ctx + 0x18))(bucket);
            *(undefined4 *)(*cacheTablePtr + byteOffset) = 0;
          }
        }
        loopIndex = loopIndex + 1;
        byteOffset = byteOffset + 4;
        if (loopIndex == endIndex - firstIndex) break;
        cacheTable = *cacheTablePtr;
      }
    }
  }
  return;
}

/* vpStateSetConstantVector @ 0x77430 (132 bytes) */
int vpStateSetConstantVector(ctx, shader, constantEntry)
  int ctx;
  int *shader;
  int constantEntry;
{
  int highestSlot;
  int slotBase;
  undefined4 *values;
  int programState;
  int slotIndex;
  
  programState = **(int **)(*(int *)(((unsigned char *)0x0000118c) + ctx) * 4 + *shader);
  if (constantEntry != 0) {
    values = *(undefined4 **)(constantEntry + 0x38);
    slotIndex = *(int *)(constantEntry + 4);
    highestSlot = *(int *)(((unsigned char *)0x0000137c) + programState);
    slotBase = slotIndex * 0x10 + programState;
    *(undefined4 *)(slotBase + 0x154) = *values;
    *(undefined4 *)(slotBase + 0x158) = values[1];
    *(undefined4 *)(slotBase + 0x15c) = values[2];
    *(undefined4 *)(slotBase + 0x160) = values[3];
    if (highestSlot < slotIndex) {
      *(int *)(((unsigned char *)0x0000137c) + programState) = slotIndex;
    }
  }
  *(uint *)(ctx + 0x38) = *(uint *)(ctx + 0x38) | 0x1000;
  *(byte *)(ctx + 0x2d) = *(byte *)(ctx + 0x2d) | 1;
  *(undefined1 *)(ctx + 0x29) = 1;
  return;
}

/* recordAllocCreate @ 0x774c0 (156 bytes) */
int recordAllocCreate(param_1, param_2)
  code *param_1;
  undefined4 param_2;
{
  int iVar1;
  
  iVar1 = (*param_1)(0x359a4,param_2);
  if (iVar1 != 0) {
    _memset(iVar1,0,0x359a4);
    *(int *)(iVar1 + 0x34) = iVar1;
    *(undefined4 *)(iVar1 + 0x12458) = param_2;
    *(code **)(iVar1 + 0x12454) = param_1;
    *(undefined4 *)(iVar1 + 0x359a0) = 0xdeaddead;
    _memset(iVar1 + 0x38,0,0x1241c);
    *(undefined4 *)(iVar1 + 0x3c) = param_2;
    *(code **)(iVar1 + 0x38) = param_1;
  }
  return iVar1;
}

/* recordCollectDependencies @ 0x77560 (228 bytes) */
int recordCollectDependencies(alloc, recordIndex, depth, unusedArg4, unusedArg5, param_6, param_7)
  int alloc;
  int recordIndex;
  uint depth;
  undefined4 unusedArg4;
  undefined4 unusedArg5;
  undefined4 param_6;
  undefined4 param_7;
{
  int callerSlotBase;
  bool moreSlots;
  int slotBase;
  int liveCount;
  uint sourceMaskBit;
  uint sourceSlot;
  int *sourceListHead;
  undefined4 *depNode;
  
  slotBase = recordIndex * 4 + alloc;
  if (*(uint *)(slotBase + 0x10454) < depth) {
    *(uint *)(slotBase + 0x10454) = depth;
  }
  if ((*(uint *)(slotBase + 0x3348c) & 0x10000) == 0) {
    liveCount = *(int *)(alloc + 0x26870);
    *(uint *)(slotBase + 0x3348c) = *(uint *)(slotBase + 0x3348c) | 0x10000;
    sourceSlot = 0;
    sourceListHead = (int *)(recordIndex * 0xc + alloc + 0x450);
    *(int *)(alloc + 0x26870) = liveCount + 1;
    *(int *)(0x00024870 + liveCount * 4 + alloc) = recordIndex;
    callerSlotBase = slotBase;
    do {
      sourceMaskBit = 1 << (sourceSlot & 0x3f) & *(uint *)(slotBase + 0x6450);
      if (sourceMaskBit != 0) {
        for (depNode = (undefined4 *)*sourceListHead; depNode != (undefined4 *)0x0;
            depNode = (undefined4 *)depNode[4]) {
          ((int (*)())recordCollectDependencies)(alloc,*depNode,depth + 1,unusedArg4,unusedArg5,callerSlotBase,sourceMaskBit);
        }
      }
      moreSlots = sourceSlot != 2;
      sourceListHead = sourceListHead + 1;
      sourceSlot = sourceSlot + 1;
    } while (moreSlots);
  }
  return;
}

/* depListRemove @ 0x77650 (76 bytes) */
int depListRemove(listHead, node)
  int *listHead;
  int node;
{
  int iVar1;
  int iVar2;
  
  iVar2 = *listHead;
  if (iVar2 == 0) {
    return;
  }
  if (node != 0) {
    if (iVar2 == node) {
      *listHead = *(int *)(iVar2 + 0x10);
      return;
    }
    do {
      iVar1 = *(int *)(iVar2 + 0x10);
      if (node == iVar1) {
        *(undefined4 *)(iVar2 + 0x10) = *(undefined4 *)(node + 0x10);
        return;
      }
      iVar2 = iVar1;
    } while (iVar1 != 0);
    return;
  }
  return;
}

/* recordClearBindingTables @ 0x776b0 (176 bytes) */
int recordClearBindingTables(alloc)
  int alloc;
{
  bool moreWords;
  undefined4 *clearPtr;
  int remaining;
  
  *(undefined4 *)(alloc + 0x30c20) = 0;
  if ((**(uint **)(alloc + 0x34) & 0x40) == 0) {
    *(undefined4 *)(alloc + 0x30c24) = 0;
    clearPtr = (undefined4 *)(alloc + 0x30c28);
    remaining = 0;
    do {
      moreWords = remaining != 1;
      *clearPtr = 0;
      remaining = remaining + 1;
      clearPtr = clearPtr + 1;
    } while (moreWords);
    clearPtr = (undefined4 *)(alloc + 0x30c30);
    remaining = 6;
    do {
      *clearPtr = 0;
      clearPtr = clearPtr + 1;
      remaining = remaining + -1;
    } while (remaining != 0);
    *(undefined4 *)(((unsigned char *)0x00030c4c) + alloc) = 0;
    *(undefined4 *)(((unsigned char *)0x00030c48) + alloc) = 0;
  }
  else {
    clearPtr = (undefined4 *)(alloc + 0x31450);
    remaining = 0xf;
    do {
      *clearPtr = 0;
      clearPtr = clearPtr + 1;
      remaining = remaining + -1;
    } while (remaining != 0);
  }
  clearPtr = (undefined4 *)(alloc + 0x30ba0);
  remaining = 0x20;
  do {
    *clearPtr = 0;
    clearPtr = clearPtr + 1;
    remaining = remaining + -1;
  } while (remaining != 0);
  return;
}

/* arrayRemoveAt @ 0x77760 (72 bytes) */
int arrayRemoveAt(param_1, param_2, param_3)
  uint param_1;
  uint *param_2;
  int param_3;
{
  uint uVar1;
  undefined4 *puVar2;
  
  uVar1 = *param_2 - 1;
  if (param_1 < uVar1) {
    puVar2 = (undefined4 *)(param_3 + param_1 * 4);
    do {
      param_1 = param_1 + 1;
      *puVar2 = puVar2[1];
      puVar2 = puVar2 + 1;
      uVar1 = *param_2 - 1;
    } while (param_1 < uVar1);
  }
  *param_2 = uVar1;
  return;
}

/* recordDestFileIs0Or45 @ 0x777b0 (56 bytes) */
int recordDestFileIs0Or45(param_1, param_2)
  uint *param_1;
  int param_2;
{
  uint uVar1;
  
  uVar1 = *param_1 & 0xf00;
  if ((uVar1 != 0) && (((uVar1 != 0x400 && (uVar1 != 0x500)) || (param_2 == 0)))) {
    return 0;
  }
  return 1;
}

/* recordDestFileIs3Or1 @ 0x77800 (64 bytes) */
int recordDestFileIs3Or1(param_1, param_2)
  uint *param_1;
  int param_2;
{
  if ((*param_1 & 0xf00) == 0x300) {
    if (param_2 == 0) {
      return 1;
    }
  }
  else if (((*param_1 & 0xf00) == 0x100) && (param_2 != 0)) {
    return 1;
  }
  return 0;
}

/* recordGetWriteMask @ 0x77850 (12 bytes) */
int recordGetWriteMask(param_1)
  uint *param_1;
{
  return *param_1 >> 0x14 & 0xf;
}

/* recordIsSchedulable @ 0x77860 (792 bytes) */
int recordIsSchedulable(alloc, records, liveIndex, modeFlag)
  int alloc;
  int records;
  int liveIndex;
  int modeFlag;
{
  uint recordWriteMask;
  uint laneIndex;
  uint oldUsage;
  uint recordIndex;
  uint writeMask;
  int flagResult;
  bool moreLanes;
  uint fileBit;
  int recordOffset;
  uint recordWord;
  uint otherWriteMask;
  int *listNode;
  int *listHeadCursor;
  uint *recordPtr;
  uint *usageMaskPtr;
  uint otherIndex;
  
  recordOffset = *(int *)(0x00024870 + liveIndex * 4 + alloc) * 0x10;
  recordPtr = (uint *)(recordOffset + records);
  if (modeFlag == 0) {
    switch(*(uint *)(records + recordOffset) >> 8 & 0xf) {
    case 0:
      usageMaskPtr = (uint *)(alloc + 0x30ba0 + (*recordPtr >> 0xb & 0x1fc));
      break;
    default:
      goto switchD_000778cc_caseD_1;
    case 3:
      usageMaskPtr = (uint *)(alloc + 0x30c20 + (*recordPtr >> 0xb & 0x1fc));
      break;
    case 4:
      usageMaskPtr = (uint *)(alloc + 0x30c24 + (*recordPtr >> 0xb & 0x1fc));
      break;
    case 5:
      usageMaskPtr = (uint *)(alloc + 0x30c28 + (*recordPtr >> 0xb & 0x1fc));
      break;
    case 6:
      usageMaskPtr = (uint *)(alloc + 0x30c30 + (*recordPtr >> 0xb & 0x1fc));
      break;
    case 7:
      usageMaskPtr = (uint *)(((unsigned char *)0x00030c48) + (*recordPtr >> 0xb & 0x1fc) + alloc);
      break;
    case 8:
      usageMaskPtr = (uint *)(((unsigned char *)0x00030c4c) + (*recordPtr >> 0xb & 0x1fc) + alloc);
    }
  }
  else {
    recordWord = *(uint *)(records + recordOffset);
    fileBit = recordWord >> 8 & 0xf;
    if (fileBit < 6) {
      fileBit = 1 << fileBit;
      if ((fileBit & 0x31) != 0) {
        usageMaskPtr = (uint *)(alloc + 0x30ba0 + (recordWord >> 0xb & 0x1fc));
        goto LAB_000779d4;
      }
      if ((fileBit & 2) != 0) {
        usageMaskPtr = (uint *)(alloc + 0x30c20 + (recordWord >> 0xb & 0x1fc));
        goto LAB_000779d4;
      }
      if ((fileBit & 0xc) != 0) {
        usageMaskPtr = (uint *)(alloc + 0x31450 + (recordWord >> 0xb & 0x1fc));
        goto LAB_000779d4;
      }
    }
switchD_000778cc_caseD_1:
    usageMaskPtr = (uint *)0x0;
  }
LAB_000779d4:
  flagResult = ((int (*)())recordDestFileIs0Or45)(recordPtr,modeFlag);
  if ((flagResult == 0) && (flagResult = ((int (*)())recordDestFileIs3Or1)(recordPtr,modeFlag), flagResult == 0)) {
    writeMask = ((int (*)())recordGetWriteMask)(recordPtr);
    oldUsage = *usageMaskPtr;
    *usageMaskPtr = writeMask | oldUsage;
    if ((oldUsage & writeMask & 0xff) != 0) {
      return 0;
    }
  }
  laneIndex = 0;
  recordIndex = *(uint *)(0x00024870 + liveIndex * 4 + alloc);
  listHeadCursor = (int *)(recordIndex * 0xc + alloc + 0x450);
  do {
    if ((*(uint *)(recordIndex * 4 + alloc + 0x6450) & 1 << (laneIndex & 0x3f)) != 0) {
      for (listNode = (int *)*listHeadCursor; listNode != (int *)0x0; listNode = (int *)listNode[4]) {
        if ((*(uint *)(*listNode * 4 + alloc + 0x3348c) & 0x40000) == 0) {
          return 0;
        }
      }
    }
    moreLanes = laneIndex != 2;
    listHeadCursor = listHeadCursor + 1;
    laneIndex = laneIndex + 1;
  } while (moreLanes);
  flagResult = ((int (*)())recordDestFileIs0Or45)(recordPtr,modeFlag);
  if ((flagResult != 0) && (usageMaskPtr = *(uint **)(recordIndex * 4 + alloc + 0xe450), usageMaskPtr != (uint *)0x0)) {
    recordWriteMask = ((int (*)())recordGetWriteMask)(recordPtr);
    do {
      otherIndex = *usageMaskPtr;
      otherWriteMask = ((int (*)())recordGetWriteMask)(records + otherIndex * 0x10);
      if ((((recordWriteMask & otherWriteMask) != 0) && (otherIndex < recordIndex)) &&
         ((*(uint *)(otherIndex * 4 + alloc + 0x3348c) & 0x40000) == 0)) {
        return 0;
      }
      usageMaskPtr = (uint *)usageMaskPtr[4];
    } while (usageMaskPtr != (uint *)0x0);
  }
  return 1;
}

/* regBindingSet @ 0x77ba0 (140 bytes) */
int regBindingSet(ctx, valueId, reg, componentMask, strict)
  int ctx;
  int valueId;
  int reg;
  uint componentMask;
  int strict;
{
  byte bVar1;
  int *piVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  
  iVar5 = 4;
  uVar4 = 0;
  piVar2 = (int *)(reg * 0x10 + ctx + 0x2d87c);
  do {
    uVar3 = 1 << (uVar4 & 0x3f);
    if ((uVar3 & componentMask) != 0) {
      bVar1 = *(byte *)(reg + ctx + 0x3087c);
      if (((int)(char)bVar1 >> (uVar4 & 0x3f) & 1U) == 0) {
        *piVar2 = valueId;
        *(byte *)(reg + ctx + 0x3087c) = (byte)uVar3 | bVar1;
      }
      else if ((valueId != *piVar2) && (strict != 0)) {
        return 6;
      }
    }
    uVar4 = uVar4 + 1;
    piVar2 = piVar2 + 1;
    iVar5 = iVar5 + -1;
    if (iVar5 == 0) {
      return 0;
    }
  } while( true );
}

/* regBindingSetFixedRegister @ 0x77c40 (124 bytes) */
int regBindingSetFixedRegister(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int param_2;
  uint param_3;
  int param_4;
  undefined4 param_5;
{
  byte bVar1;
  uint uVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  
  uVar4 = 0;
  iVar5 = 4;
  piVar3 = (int *)(param_1 + 0x30b8c);
  do {
    uVar2 = 1 << (uVar4 & 0x3f);
    if ((uVar2 & param_3) != 0) {
      bVar1 = *(byte *)(param_1 + 0x30b9c);
      if (((int)(char)bVar1 >> (uVar4 & 0x3f) & 1U) == 0) {
        *piVar3 = param_2;
        *(byte *)(param_1 + 0x30b9c) = (byte)uVar2 | bVar1;
      }
      else if ((param_2 != *piVar3) && (param_4 != 0)) {
        return 6;
      }
    }
    uVar4 = uVar4 + 1;
    piVar3 = piVar3 + 1;
    iVar5 = iVar5 + -1;
    if (iVar5 == 0) {
      return 0;
    }
  } while( true );
}

/* recordSourceFileIs1 @ 0x77cd0 (24 bytes) */
int recordSourceFileIs1(param_1)
  uint *param_1;
{
  return (*param_1 & 0xf) == 1;
}

/* recordDestFileIs0 @ 0x77cf0 (20 bytes) */
int recordDestFileIs0(param_1)
  uint *param_1;
{
  return (*param_1 & 0xf00) == 0;
}

/* recordCombinedWriteMask @ 0x77d10 (120 bytes) */
int recordCombinedWriteMask(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  uint uVar2;
  
  uVar2 = ((int (*)())recordGetWriteMask)(param_1 + 0x1286c + param_2 * 0x10);
  for (iVar1 = *(int *)(param_2 * 4 + param_1 + 0xc450); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x10))
  {
    uVar2 = uVar2 | *(uint *)(iVar1 + 4);
  }
  return uVar2;
}

/* recordRegisterIsAssignable @ 0x77d90 (1176 bytes) */
int recordRegisterIsAssignable(ctx, program, reg, usedValueMask, recordIndex, componentMask)
  int ctx;
  int program;
  int reg;
  uint usedValueMask;
  uint recordIndex;
  uint componentMask;
{
  uint *listNode;
  uint laneBitG;
  uint *earliestWriterPtr;
  uint *useNode;
  uint loopCounterG;
  uint componentBit;
  uint loopCounterF;
  uint componentIndex;
  uint loopCounterE;
  int remaining;
  int loopCounter;
  bool moreComponentsB;
  int loopIndex;
  int loopIndex2;
  bool moreComponents;
  bool conflict;
  int regOffset;
  uint *valueIdPtr;
  undefined4 *headCursor;
  int valueId;
  uint laneBit;
  uint writerWriteMask;
  uint loopCounterD;
  uint uVar10;
  int *valueIdCursor;
  uint boundMask;
  uint writerRecord;
  int candidateValueId;
  uint *earliestPtr;
  int *seenSlot;
  int remainingB;
  int seenCountdown;
  int seenValueIds [4];
  uint earliestWriter [7];
  
  regOffset = reg * 0x10;
  remainingB = 4;
  valueIdPtr = (uint *)(regOffset + ctx + 0x2d87c);
  loopCounterF = 0;
  do {
    if (((componentMask & 1 << (loopCounterF & 0x3f)) == 0) ||
       ((((int)*(char *)(reg + ctx + 0x3087c) >> (loopCounterF & 0x3f) & 1U) != 0 &&
        (recordIndex == *valueIdPtr)))) {
      conflict = false;
    }
    else {
      conflict = true;
    }
    loopCounterF = loopCounterF + 1;
    remainingB = remainingB + -1;
    if (remainingB == 0) {
      if (!conflict) {
        return 0;
      }
      break;
    }
    valueIdPtr = valueIdPtr + 1;
  } while (!conflict);
  boundMask = (uint)*(char *)(reg + ctx + 0x3087c);
  if ((boundMask & usedValueMask) == 0) {
    return 0;
  }
  loopCounterE = 0;
  conflict = false;
  remainingB = 4;
  headCursor = (undefined4 *)(regOffset + ctx + 0x2a87c);
  do {
    componentBit = 1 << (loopCounterE & 0x3f);
    if (((((componentBit & boundMask) != 0) && (valueIdPtr = (uint *)*headCursor, valueIdPtr != (uint *)0x0)) &&
        (recordIndex == *valueIdPtr)) && (valueIdPtr[1] == 0)) {
      boundMask = boundMask & ~componentBit;
      conflict = true;
    }
    loopCounterE = loopCounterE + 1;
    headCursor = headCursor + 1;
    remainingB = remainingB + -1;
  } while (remainingB != 0);
  if ((boundMask != 0) && (conflict)) {
    loopIndex = 0;
    componentIndex = 0;
    conflict = false;
    valueIdCursor = (int *)(regOffset + ctx + 0x2d87c);
    do {
      if ((1 << (componentIndex & 0x3f) & boundMask) != 0) {
        if (conflict) {
          candidateValueId = *valueIdCursor;
          loopCounter = 0;
          seenCountdown = loopIndex;
          do {
            seenSlot = seenValueIds + loopCounter;
            seenCountdown = seenCountdown + -1;
            if (seenCountdown == 0) {
              if (*seenSlot != candidateValueId) goto LAB_00077f68;
              break;
            }
            loopCounter = loopCounter + 1;
          } while (*seenSlot != candidateValueId);
        }
        else {
          candidateValueId = *valueIdCursor;
LAB_00077f68:
          seenValueIds[loopIndex] = candidateValueId;
          conflict = 0 < loopIndex + 1;
          loopIndex = loopIndex + 1;
        }
      }
      moreComponents = componentIndex != 3;
      valueIdCursor = valueIdCursor + 1;
      componentIndex = componentIndex + 1;
    } while (moreComponents);
    if (conflict) {
      loopIndex2 = 0;
      uVar10 = 0;
      valueIdCursor = seenValueIds;
      do {
        valueId = *valueIdCursor;
        valueIdCursor = valueIdCursor + 1;
        if (valueId != -1) {
          for (useNode = *(uint **)(valueId * 4 + ctx + 0xc450); useNode != (uint *)0x0;
              useNode = (uint *)useNode[4]) {
            writerRecord = *useNode;
            if ((*(uint *)(writerRecord * 4 + ctx + 0x3348c) & 0x40000) == 0) {
              writerWriteMask = ((int (*)())recordGetWriteMask)(writerRecord * 0x10 + program);
              loopCounterD = 0;
              earliestPtr = earliestWriter;
              remaining = 4;
              do {
                laneBit = 1 << (loopCounterD & 0x3f);
                if ((writerWriteMask & laneBit & ~boundMask) != 0) {
                  if ((laneBit & uVar10) == 0) {
                    *earliestPtr = writerRecord;
                    uVar10 = uVar10 | laneBit;
                  }
                  else if (writerRecord < *earliestPtr) {
                    *earliestPtr = writerRecord;
                  }
                }
                loopCounterD = loopCounterD + 1;
                earliestPtr = earliestPtr + 1;
                remaining = remaining + -1;
              } while (remaining != 0);
            }
          }
        }
        loopIndex2 = loopIndex2 + 1;
      } while (loopIndex2 != loopIndex);
      if (uVar10 != 0) {
        loopCounterG = 0;
        earliestWriterPtr = earliestWriter;
        remainingB = 4;
        do {
          laneBitG = 1 << (loopCounterG & 0x3f);
          if (((laneBitG & uVar10) != 0) && (recordIndex == *earliestWriterPtr)) {
            uVar10 = uVar10 & ~laneBitG;
          }
          loopCounterG = loopCounterG + 1;
          earliestWriterPtr = earliestWriterPtr + 1;
          remainingB = remainingB + -1;
        } while (remainingB != 0);
      }
      goto LAB_000780d4;
    }
  }
  uVar10 = 0;
LAB_000780d4:
  if (((usedValueMask & boundMask) == 0) && ((uVar10 & usedValueMask) != 0)) {
    return 1;
  }
  boundMask = usedValueMask & (uVar10 | boundMask);
  if (boundMask != 0) {
    componentIndex = 0;
    valueIdPtr = (uint *)(regOffset + ctx + 0x2d87c);
    do {
      componentBit = 1 << (componentIndex & 0x3f);
      if ((componentBit & boundMask) != 0) {
        if ((componentMask & componentBit) == 0) {
          listNode = *(uint **)(recordIndex * 4 + ctx + 0xc450);
          if (listNode != (uint *)0x0) {
            do {
              if (*listNode == *valueIdPtr) {
                boundMask = boundMask & ~componentBit;
              }
              listNode = (uint *)listNode[4];
            } while (listNode != (uint *)0x0);
          }
        }
        else if (recordIndex == *valueIdPtr) {
          boundMask = boundMask & ~componentBit;
        }
      }
      moreComponentsB = componentIndex != 3;
      valueIdPtr = valueIdPtr + 1;
      componentIndex = componentIndex + 1;
    } while (moreComponentsB);
    if (boundMask != 0) {
      componentIndex = 0;
      valueIdCursor = (int *)(regOffset + ctx + 0x2d87c);
      do {
        componentBit = 1 << (componentIndex & 0x3f);
        if ((((componentBit & boundMask) != 0) && ((componentBit & componentMask) == 0)) &&
           (seenSlot = *(int **)(recordIndex * 4 + ctx + 0xe450), seenSlot != (int *)0x0)) {
          do {
            if (*seenSlot == *valueIdCursor) {
              boundMask = boundMask & ~componentBit;
            }
            seenSlot = (int *)seenSlot[4];
          } while (seenSlot != (int *)0x0);
        }
        moreComponentsB = componentIndex != 3;
        valueIdCursor = valueIdCursor + 1;
        componentIndex = componentIndex + 1;
      } while (moreComponentsB);
      if (boundMask != 0) {
        return 1;
      }
    }
  }
  return 0;
}

/* recordFindFreeTempRegister @ 0x78250 (132 bytes) */
int recordFindFreeTempRegister(ctx, program, usedValueMask, recordIndex, componentMask)
  undefined4 ctx;
  undefined4 program;
  undefined4 usedValueMask;
  undefined4 recordIndex;
  undefined4 componentMask;
{
  bool bVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  do {
    iVar2 = ((int (*)())recordRegisterIsAssignable)(ctx,program,iVar3 + 0x200,usedValueMask,recordIndex,componentMask);
    if (iVar2 == 0) {
      return iVar3 + 0x200;
    }
    bVar1 = iVar3 != 3;
    iVar3 = iVar3 + 1;
  } while (bVar1);
  return -1;
}

/* recordSourceFileIs0 @ 0x782e0 (20 bytes) */
int recordSourceFileIs0(param_1)
  uint *param_1;
{
  return (*param_1 & 0xf) == 0;
}

/* recordOpcodeSourceMask @ 0x78300 (200 bytes) */
int recordOpcodeSourceMask(param_1, param_2)
  int param_1;
  int param_2;
{
  char cVar1;
  
  cVar1 = *(char *)(param_1 + 3);
  switch(cVar1) {
  case '\0':
  case '@':
    return 0;
  case '\x01':
  case '\x02':
  case '\x03':
  case '\x05':
  case '\a':
  case '\b':
  case '\t':
  case '\n':
switchD_00078334_caseD_1:
    return 3;
  case '\x04':
  case '\v':
  case '\f':
  case -0x80:
switchD_00078334_caseD_4:
    return 7;
  case '\x06':
  case '\r':
  case '\x0e':
  case 'A':
  case 'B':
  case 'F':
  case 'G':
  case 'H':
  case 'I':
  case 'K':
  case 'L':
  case 'P':
  case 'Q':
    goto switchD_00078334_caseD_6;
  default:
    if (param_2 != 0) {
      switch(cVar1) {
      case 'C':
        return 4;
      case 'D':
      case 'M':
      case 'N':
      case -0x7f:
        goto switchD_00078334_caseD_4;
      case 'E':
      case 'O':
        return 5;
      default:
        goto switchD_000785b4_caseD_46;
      case 'J':
        goto switchD_00078334_caseD_1;
      }
    }
    if ((7 < (byte)(cVar1 + 0xbdU)) || ((1 << ((int)(char)(cVar1 + -0x43) & 0x3fU) & 0x87U) == 0)) {
switchD_000785b4_caseD_46:
      return 0xffffffff;
    }
switchD_00078334_caseD_6:
    return 1;
  }
}

/* recordMarkDependentsDirty @ 0x78700 (84 bytes) */
int recordMarkDependentsDirty(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  iVar1 = param_2 * 4;
  iVar2 = param_1 + 0x3348c;
  piVar3 = *(int **)(iVar1 + param_1 + 0xc450);
  *(uint *)(iVar2 + iVar1) = *(uint *)(iVar2 + iVar1) | 0x2000;
  if (piVar3 != (int *)0x0) {
    do {
      *(uint *)(iVar2 + *piVar3 * 4) = *(uint *)(iVar2 + *piVar3 * 4) | 0x2000;
      piVar3 = (int *)piVar3[4];
    } while (piVar3 != (int *)0x0);
    return;
  }
  return;
}

/* recordAssignDestinationRegister @ 0x78760 (448 bytes) */
int recordAssignDestinationRegister(ctx, program, recordIndex, keepFlag, chosenReg)
  int ctx;
  int program;
  int recordIndex;
  char *keepFlag;
  int *chosenReg;
{
  char cVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  uint *puVar7;
  
  puVar7 = (uint *)(recordIndex * 0x10 + program);
  uVar2 = ((int (*)())recordCombinedWriteMask)(ctx,recordIndex);
  uVar3 = ((int (*)())recordGetWriteMask)(puVar7);
  uVar5 = *(uint *)(recordIndex * 0x10 + program);
  if ((uVar5 & 0xf00) == 0x400) {
    iVar4 = ((int (*)())recordRegisterIsAssignable)(ctx,program,
                         (char)(DAT_001aa758)[uVar5 >> 8 & 0xf] * 0x100 + (uVar5 >> 0xd & 0x7f),
                         uVar2,recordIndex,uVar3);
    if (iVar4 == 0) {
      *keepFlag = '\0';
      return true;
    }
  }
  else {
    piVar6 = *(int **)(recordIndex * 4 + ctx + 0xa450);
    if (piVar6 != (int *)0x0) {
      cVar1 = *(char *)(*piVar6 * 4 + ctx + 0x3148d);
      while( true ) {
        if ('\0' < cVar1) {
          ((int (*)())recordMarkDependentsDirty)(ctx,recordIndex);
          return false;
        }
        piVar6 = (int *)piVar6[4];
        if (piVar6 == (int *)0x0) break;
        cVar1 = *(char *)(*piVar6 * 4 + ctx + 0x3148d);
      }
    }
  }
  iVar4 = ((int (*)())recordFindFreeTempRegister)(ctx,program,uVar2,recordIndex,uVar3);
  *chosenReg = iVar4;
  if (iVar4 == -1) {
    ((int (*)())recordMarkDependentsDirty)(ctx,recordIndex);
    *keepFlag = '\0';
  }
  else {
    uVar5 = *puVar7;
    *keepFlag = '\x01' - ((char)(DAT_001aa758)[uVar5 >> 8 & 0xf] * 0x100 + (uVar5 >> 0xd & 0x7f) ==
                        iVar4);
  }
  return iVar4 != -1;
}

/* recordMarkPairEmitted @ 0x78950 (64 bytes) */
int recordMarkPairEmitted(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = param_1 + 0x3348c;
  iVar1 = *(int *)(param_1 + 0x35494) * 4;
  iVar2 = *(int *)(param_1 + 0x35498) * 4;
  *(uint *)(iVar3 + iVar1) = *(uint *)(iVar3 + iVar1) | 0x100;
  *(uint *)(iVar3 + iVar2) = *(uint *)(iVar3 + iVar2) | 0x100;
  *(int *)(param_1 + 0x3548c) = *(int *)(param_1 + 0x3548c) + 1;
  return;
}

/* recordFlagsPending20 @ 0x78990 (56 bytes) */
int recordFlagsPending20(param_1, param_2)
  int param_1;
  int param_2;
{
  uint uVar1;
  
  uVar1 = *(uint *)(param_2 * 4 + param_1 + 0x3348c);
  if ((((uVar1 & 0x100) == 0) && ((uVar1 & 0x1000) == 0)) && ((uVar1 & 0x20) != 0)) {
    return 1;
  }
  return 0;
}

/* recordFlagsPending2 @ 0x789d0 (56 bytes) */
int recordFlagsPending2(param_1, param_2)
  int param_1;
  int param_2;
{
  uint uVar1;
  
  uVar1 = *(uint *)(param_2 * 4 + param_1 + 0x3348c);
  if ((((uVar1 & 0x100) == 0) && ((uVar1 & 2) != 0)) && ((uVar1 & 0x2000) == 0)) {
    return 1;
  }
  return 0;
}

/* recordCountSourceRegisterFiles @ 0x78a10 (356 bytes) */
int recordCountSourceRegisterFiles(ctx, outCounts, record)
  int ctx;
  char *outCounts;
  uint *record;
{
  bool lastSource;
  bool isNewKey;
  uint seenKey;
  uint *seenCursor;
  uint sourceMask;
  uint *seenSlot;
  uint fileAndIndex;
  uint loopIndex;
  uint remaining;
  uint seenKeys [7];
  
  sourceMask = ((int (*)())recordOpcodeSourceMask)(record,**(uint **)(ctx + 0x34) >> 6 & 1);
  loopIndex = 0;
  outCounts[0] = '\0';
  outCounts[1] = '\0';
  outCounts[2] = '\0';
  outCounts[3] = '\0';
  seenSlot = seenKeys;
  do {
    record = record + 1;
    if ((sourceMask & 1 << (loopIndex & 0x3f)) == 0) {
      *seenSlot = 0x501;
    }
    else {
      fileAndIndex = (char)(DAT_001aa760)[*record & 0xf] * 0x100 + (*record >> 5 & 0xff);
      *seenSlot = fileAndIndex;
      if (loopIndex != 0) {
        isNewKey = true;
        seenCursor = seenKeys;
        remaining = loopIndex;
        do {
          seenKey = *seenCursor;
          seenCursor = seenCursor + 1;
          if (fileAndIndex == seenKey) {
            isNewKey = false;
          }
          remaining = remaining - 1;
        } while (remaining != 0);
        if (!isNewKey) goto LAB_00078b54;
      }
      fileAndIndex = fileAndIndex >> 8;
      if (fileAndIndex == 1) {
        outCounts[3] = outCounts[3] + '\x01';
      }
      else if (fileAndIndex == 0) {
        *outCounts = *outCounts + '\x01';
      }
      else if (fileAndIndex == 2) {
        outCounts[1] = outCounts[1] + '\x01';
      }
      else if (fileAndIndex == 4) {
        outCounts[2] = outCounts[2] + '\x01';
      }
    }
LAB_00078b54:
    lastSource = loopIndex == 2;
    seenSlot = seenSlot + 1;
    loopIndex = loopIndex + 1;
    if (lastSource) {
      return;
    }
  } while( true );
}

/* recordRetargetDestination @ 0x78b80 (560 bytes) */
int recordRetargetDestination(ctx, recordIndex, newRegId)
  int ctx;
  int recordIndex;
  uint newRegId;
{
  bool moreSources;
  bool referencesRecord;
  int consumerIndex;
  int *readerNode;
  uint oldSourceWord;
  uint uVar5;
  uint newFile;
  int programBase;
  uint newFileIndex;
  int *consumerNode;
  int *sourceWordAddrCursor;
  int consumerRecord;
  uint sourceIndex;
  undefined4 *listCursor;
  int sourceWordAddrs [9];
  
  programBase = ctx + 0x1286c;
  uVar5 = *(uint *)(programBase + recordIndex * 0x10);
  newFileIndex = (uint)(char)(DAT_001aa764)[newRegId >> 8];
  if ((char)(DAT_001aa758)[uVar5 >> 8 & 0xf] * 0x100 + (uVar5 >> 0xd & 0x7f) != newRegId) {
    *(uint *)(programBase + recordIndex * 0x10) =
         (newRegId & 0x7f) << 0xd | (newFileIndex & 0xf) << 8 | uVar5 & 0xfff010ff;
    consumerNode = *(int **)(recordIndex * 4 + ctx + 0xa450);
    if (consumerNode != (int *)0x0) {
      do {
        consumerIndex = *consumerNode;
        sourceIndex = 0;
        sourceWordAddrCursor = sourceWordAddrs;
        consumerRecord = consumerIndex * 0x10 + programBase;
        uVar5 = *(uint *)(consumerIndex * 4 + ctx + 0x6450);
        sourceWordAddrs[0] = consumerRecord + 4;
        sourceWordAddrs[1] = consumerRecord + 8;
        sourceWordAddrs[2] = consumerRecord + 0xc;
        listCursor = (undefined4 *)(consumerIndex * 0xc + ctx + 0x450);
        do {
          if (((uVar5 & 1 << (sourceIndex & 0x3f)) != 0) &&
             (readerNode = (int *)*listCursor, readerNode != (int *)0x0)) {
            referencesRecord = false;
            do {
              if (recordIndex == *readerNode) {
                referencesRecord = true;
              }
              readerNode = (int *)readerNode[4];
            } while (readerNode != (int *)0x0);
            if (referencesRecord) {
              newFile = newFileIndex;
              if ((**(uint **)(ctx + 0x34) & 0x40) != 0) {
                if (newFileIndex == 4) {
                  newFile = 3;
                }
                else if (newFileIndex == 5) {
                  newFile = 1;
                }
                else {
                  newFile = 0;
                }
              }
              oldSourceWord = *(uint *)*sourceWordAddrCursor;
              if (((newRegId & 0xff) != (oldSourceWord >> 5 & 0xff)) || (newFile != (oldSourceWord & 0xf))) {
                *(uint *)*sourceWordAddrCursor = (newRegId & 0xff) << 5 | newFile & 0xf | oldSourceWord & 0xffffe010;
                ((int (*)())recordCountSourceRegisterFiles)(ctx,ctx + 0x3148c + consumerIndex * 4,consumerRecord);
              }
            }
          }
          moreSources = sourceIndex != 2;
          sourceWordAddrCursor = sourceWordAddrCursor + 1;
          listCursor = listCursor + 1;
          sourceIndex = sourceIndex + 1;
        } while (moreSources);
        consumerNode = (int *)consumerNode[4];
      } while (consumerNode != (int *)0x0);
    }
    for (listCursor = *(undefined4 **)(recordIndex * 4 + ctx + 0xc450); listCursor != (undefined4 *)0x0;
        listCursor = (undefined4 *)listCursor[4]) {
      ((int (*)())recordRetargetDestination)(ctx,*listCursor,newRegId);
    }
  }
  return;
}

/* regBindingClear @ 0x78db0 (68 bytes) */
int regBindingClear(ctx, reg, compIndex)
  int ctx;
  int reg;
  uint compIndex;
{
  byte bVar1;
  int iVar2;
  
  bVar1 = *(byte *)(reg + ctx + 0x3087c);
  iVar2 = (reg * 4 + compIndex) * 4 + ctx;
  *(undefined4 *)(iVar2 + 0x2d87c) = 0;
  *(undefined4 *)(iVar2 + 0x2a87c) = 0;
  *(byte *)(reg + ctx + 0x3087c) =
       ((byte)(-2 << (compIndex & 0x1f)) | (byte)(0xfffffffe >> 0x20 - (compIndex & 0x1f))) & bVar1;
  return;
}

/* chunkArenaAlloc @ 0x78e00 (228 bytes) */
int chunkArenaAlloc(arena, size)
  undefined4 *arena;
  uint size;
{
  int cursor;
  uint chunkCount;
  undefined4 newChunk;
  uint chunkIndex;
  uint bytesLeft;
  int chunkCountOld;
  
  bytesLeft = arena[0x105];
  if (bytesLeft < size) {
    chunkCount = arena[0x102];
    chunkIndex = arena[0x104];
    if (chunkCount <= chunkIndex) {
      if (0xfe < chunkCount) {
        return 0;
      }
      newChunk = (*(code *)*arena)(0x1000);
      chunkCountOld = arena[0x102];
      arena[chunkCount + 2] = newChunk;
      if (arena[chunkCountOld + 2] == 0) {
        return 0;
      }
      chunkIndex = arena[0x104];
      arena[0x102] = chunkCountOld + 1;
    }
    bytesLeft = 0x1000;
    arena[0x105] = 0x1000;
    arena[0x104] = chunkIndex + 1;
    arena[0x103] = arena[chunkIndex + 2];
  }
  cursor = arena[0x103];
  arena[0x105] = bytesLeft - size;
  arena[0x103] = size + cursor;
  return (size + cursor) - size;
}

/* recordSourceFileIs2 @ 0x78ef0 (24 bytes) */
int recordSourceFileIs2(param_1)
  uint *param_1;
{
  return (*param_1 & 0xf) == 2;
}

/* recordGetWriteEnable @ 0x78f10 (92 bytes) */
int recordGetWriteEnable(param_1, param_2)
  uint *param_1;
  int param_2;
{
  if (param_2 == 1) {
    return *param_1 >> 0x15 & 1;
  }
  if (param_2 == 0) {
    return *param_1 >> 0x14 & 1;
  }
  if (param_2 == 2) {
    return *param_1 >> 0x16 & 1;
  }
  if (param_2 != 3) {
    return 0;
  }
  return *param_1 >> 0x17 & 1;
}

/* recordRetireBindings @ 0x78f80 (2340 bytes) */
int recordRetireBindings(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  uint param_2;
  undefined4 *param_3;
  int param_4;
  undefined4 param_5;
{
  uint componentIndexC;
  uint loopCounterC;
  uint componentIndexB;
  uint componentBitB;
  uint componentIndex;
  uint componentBit;
  int loopCounterB;
  int remaining;
  int loopCounter;
  bool moreComponentsB;
  bool lastComponent;
  bool lastSource;
  bool moreSources;
  bool moreComponents;
  bool bVar1;
  bool bVar2;
  char cVar3;
  int *piVar4;
  uint uVar5;
  uint *puVar6;
  uint *puVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  uint *puVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  undefined4 *puVar17;
  int *piVar18;
  uint uVar19;
  uint sourceIndex;
  int *piVar21;
  int iVar22;
  int iVar23;
  int iStack00000024;
  undefined4 uStack00000028;
  int local_78 [4];
  uint local_68 [4];
  uint *local_58;
  
  piVar21 = (int *)(param_2 * 0xc + param_1 + 0x450);
  sourceIndex = 0;
  uVar19 = *(uint *)(param_2 * 4 + param_1 + 0x6450);
  puVar17 = param_3;
  iStack00000024 = param_4;
  uStack00000028 = param_5;
  do {
    if ((uVar19 & 1 << (sourceIndex & 0x3f)) != 0) {
      for (iVar22 = *piVar21; iVar22 != 0; iVar22 = *(int *)(iVar22 + 0x10)) {
        iVar11 = ((int (*)())recordSourceFileIs2)(*puVar17);
        if (iVar11 == 0) {
          componentIndexC = 0;
          do {
            if ((1 << (componentIndexC & 0x3f) & *(uint *)(iVar22 + 4)) != 0) {
              puVar6 = *(uint **)((((char)(DAT_001aa760)[*(uint *)*puVar17 & 0xf] * 0x100 +
                                   (*(uint *)*puVar17 >> 5 & 0xff)) * 4 + componentIndexC) * 4 + param_1 +
                                 0x2a87c);
              while( true ) {
                if (puVar6 == (uint *)0x0) {
                  return 6;
                }
                if (param_2 == (*puVar6 & 0xfff)) break;
                puVar6 = (uint *)puVar6[1];
              }
              *puVar6 = *puVar6 | 0x4000;
            }
            moreComponents = componentIndexC != 3;
            componentIndexC = componentIndexC + 1;
          } while (moreComponents);
        }
        else {
          componentIndexC = 0;
          piVar18 = (int *)(param_1 + 0x30b7c);
          do {
            if ((1 << (componentIndexC & 0x3f) & *(uint *)(iVar22 + 4)) != 0) {
              puVar6 = (uint *)*piVar18;
              while( true ) {
                if (puVar6 == (uint *)0x0) {
                  return 6;
                }
                if (param_2 == (*puVar6 & 0xfff)) break;
                puVar6 = (uint *)puVar6[1];
              }
              *puVar6 = *puVar6 | 0x4000;
            }
            moreComponents = componentIndexC != 3;
            piVar18 = piVar18 + 1;
            componentIndexC = componentIndexC + 1;
          } while (moreComponents);
        }
      }
    }
    moreSources = sourceIndex != 2;
    piVar21 = piVar21 + 1;
    puVar17 = puVar17 + 1;
    sourceIndex = sourceIndex + 1;
  } while (moreSources);
  sourceIndex = 0;
  piVar21 = (int *)(param_2 * 0xc + param_1 + 0x450);
  local_58 = local_68;
LAB_00079150:
  if ((uVar19 & 1 << (sourceIndex & 0x3f)) != 0) {
    puVar6 = (uint *)*param_3;
    iVar22 = *piVar21;
    iVar11 = (char)(DAT_001aa760)[*puVar6 & 0xf] * 0x100 + (*puVar6 >> 5 & 0xff);
    if (iVar22 != 0) {
      bVar1 = false;
LAB_000791c0:
      iVar12 = ((int (*)())recordSourceFileIs2)(puVar6);
      if (iVar12 == 0) {
        puVar6 = (uint *)(param_1 + iVar11 * 0x10 + 0x2a87c);
        componentIndexC = 0;
LAB_000792a0:
        componentBitB = 1 << (componentIndexC & 0x3f);
        if ((componentBitB & *(uint *)(iVar22 + 4)) != 0) {
          puVar7 = (uint *)*puVar6;
          uVar8 = 0;
          if (puVar7 != (uint *)0x0) {
            do {
              if ((*puVar7 & 0x4000) == 0) goto LAB_00079318;
              puVar7 = (uint *)puVar7[1];
              *puVar6 = (uint)puVar7;
            } while (puVar7 != (uint *)0x0);
            goto LAB_00079324;
          }
          goto LAB_00079328;
        }
        goto LAB_00079340;
      }
      puVar6 = (uint *)(param_1 + 0x30b7c);
      componentIndexC = 0;
LAB_000791e0:
      componentBitB = 1 << (componentIndexC & 0x3f);
      if ((componentBitB & *(uint *)(iVar22 + 4)) != 0) {
        puVar7 = (uint *)*puVar6;
        uVar8 = 0;
        if (puVar7 != (uint *)0x0) {
          do {
            if ((*puVar7 & 0x4000) == 0) goto LAB_00079258;
            puVar7 = (uint *)puVar7[1];
            *puVar6 = (uint)puVar7;
          } while (puVar7 != (uint *)0x0);
          goto LAB_00079264;
        }
        goto LAB_00079268;
      }
      goto LAB_00079280;
    }
    bVar1 = false;
    goto LAB_00079378;
  }
  goto LAB_000798a8;
LAB_00079318:
  while (puVar13 = puVar7, puVar7 = (uint *)puVar13[1], puVar7 != (uint *)0x0) {
    if ((*puVar7 & 0x4000) != 0) {
      puVar13[1] = puVar7[1];
      puVar7 = puVar13;
    }
  }
LAB_00079324:
  uVar8 = *puVar6;
LAB_00079328:
  if (uVar8 == 0) {
    bVar1 = true;
    *(byte *)(iVar11 + param_1 + 0x3087c) = *(byte *)(iVar11 + param_1 + 0x3087c) & ~(byte)componentBitB;
  }
LAB_00079340:
  lastComponent = componentIndexC == 3;
  puVar6 = puVar6 + 1;
  componentIndexC = componentIndexC + 1;
  if (lastComponent) goto LAB_00079350;
  goto LAB_000792a0;
LAB_00079258:
  while (puVar13 = puVar7, puVar7 = (uint *)puVar13[1], puVar7 != (uint *)0x0) {
    if ((*puVar7 & 0x4000) != 0) {
      puVar13[1] = puVar7[1];
      puVar7 = puVar13;
    }
  }
LAB_00079264:
  uVar8 = *puVar6;
LAB_00079268:
  if (uVar8 == 0) {
    *(byte *)(param_1 + 0x30b9c) = *(byte *)(param_1 + 0x30b9c) & ~(byte)componentBitB;
  }
LAB_00079280:
  lastComponent = componentIndexC == 3;
  puVar6 = puVar6 + 1;
  componentIndexC = componentIndexC + 1;
  if (lastComponent) goto LAB_00079350;
  goto LAB_000791e0;
LAB_00079350:
  iVar22 = *(int *)(iVar22 + 0x10);
  if (iVar22 == 0) goto LAB_0007936c;
  puVar6 = (uint *)*param_3;
  goto LAB_000791c0;
LAB_0007936c:
  if (*piVar21 == 0) {
LAB_00079378:
    uVar16 = *(uint *)*param_3;
    if ((uVar16 & 0xf) == 1) {
      puVar17 = (undefined4 *)(iVar11 * 0x10 + param_1 + 0x2a87c);
      componentIndexB = 0;
      do {
        componentBit = 1 << (componentIndexB & 0x3f);
        if (((1 << (uVar16 >> 0xd & 7) | 1 << (uVar16 >> 0x10 & 7) | 1 << (uVar16 >> 0x13 & 7) |
             1 << (uVar16 >> 0x16 & 7)) & componentBit) != 0) {
          puVar6 = (uint *)*puVar17;
          bVar2 = puVar6 == (uint *)0x0;
          if (!bVar2) {
            uVar5 = *puVar6;
            while (puVar7 = puVar6, uVar5 == param_2) {
              puVar6 = (uint *)puVar6[1];
              bVar2 = puVar6 == (uint *)0x0;
              if (bVar2) goto LAB_00079448;
              uVar5 = *puVar6;
            }
            while (puVar13 = puVar7, puVar7 = (uint *)puVar13[1], puVar7 != (uint *)0x0) {
              if (param_2 == *puVar7) {
                puVar13[1] = puVar7[1];
                puVar7 = puVar13;
              }
            }
          }
LAB_00079448:
          *puVar17 = puVar6;
          if (bVar2) {
            *(byte *)(iVar11 + param_1 + 0x3087c) =
                 *(byte *)(iVar11 + param_1 + 0x3087c) & ~(byte)componentBit;
          }
        }
        moreComponentsB = componentIndexB != 3;
        puVar17 = puVar17 + 1;
        componentIndexB = componentIndexB + 1;
      } while (moreComponentsB);
    }
  }
  if (bVar1) {
    iVar22 = 0;
    componentIndexB = 0;
    bVar1 = false;
    piVar18 = (int *)(iVar11 * 0x10 + param_1 + 0x2d87c);
    uVar16 = (uint)*(char *)(iVar11 + param_1 + 0x3087c);
    do {
      if ((uVar16 & 1 << (componentIndexB & 0x3f)) != 0) {
        if (bVar1) {
          iVar12 = *piVar18;
          loopCounter = 0;
          iVar23 = iVar22;
          do {
            piVar4 = local_78 + loopCounter;
            iVar23 = iVar23 + -1;
            if (iVar23 == 0) {
              if (*piVar4 != iVar12) goto LAB_00079508;
              break;
            }
            loopCounter = loopCounter + 1;
          } while (*piVar4 != iVar12);
        }
        else {
          iVar12 = *piVar18;
LAB_00079508:
          local_78[iVar22] = iVar12;
          bVar1 = 0 < iVar22 + 1;
          iVar22 = iVar22 + 1;
        }
      }
      moreComponentsB = componentIndexB != 3;
      piVar18 = piVar18 + 1;
      componentIndexB = componentIndexB + 1;
    } while (moreComponentsB);
    if (bVar1) {
      iVar12 = 0;
      uVar14 = 0;
      piVar18 = local_78;
      do {
        iVar9 = *piVar18;
        piVar18 = piVar18 + 1;
        if (iVar9 != -1) {
          for (puVar6 = *(uint **)(iVar9 * 4 + param_1 + 0xc450); puVar6 != (uint *)0x0;
              puVar6 = (uint *)puVar6[4]) {
            uVar8 = *puVar6;
            if ((*(uint *)(uVar8 * 4 + param_1 + 0x3348c) & 0x40000) == 0) {
              uVar5 = puVar6[1];
              loopCounterC = 0;
              puVar7 = local_68;
              remaining = 4;
              do {
                uVar10 = 1 << (loopCounterC & 0x3f);
                if ((uVar5 & uVar10 & ~uVar16) != 0) {
                  if ((uVar10 & uVar14) == 0) {
                    *puVar7 = uVar8;
                    uVar14 = uVar14 | uVar10;
                  }
                  else if (uVar8 < *puVar7) {
                    *puVar7 = uVar8;
                  }
                }
                loopCounterC = loopCounterC + 1;
                puVar7 = puVar7 + 1;
                remaining = remaining + -1;
              } while (remaining != 0);
            }
          }
        }
        iVar12 = iVar12 + 1;
      } while (iVar12 != iVar22);
      if (uVar14 != 0) {
        componentIndexC = 0;
        do {
          if ((1 << (componentIndexC & 0x3f) & uVar14) != 0) {
            componentIndex = 0;
            puVar6 = local_58;
            do {
              if ((((componentIndexC != componentIndex) && ((1 << (componentIndex & 0x3f) & uVar14) != 0)) &&
                  (uVar5 = local_58[componentIndexC], uVar5 < *puVar6)) &&
                 (iVar12 = ((int (*)())recordGetWriteEnable)(iStack00000024 + uVar5 * 0x10,componentIndex), iVar12 != 0)) {
                *puVar6 = uVar5;
              }
              moreComponentsB = componentIndex != 3;
              puVar6 = puVar6 + 1;
              componentIndex = componentIndex + 1;
            } while (moreComponentsB);
          }
          moreComponentsB = componentIndexC != 3;
          componentIndexC = componentIndexC + 1;
        } while (moreComponentsB);
        componentIndexC = 0;
        puVar6 = local_68;
        do {
          componentBit = 1 << (componentIndexC & 0x3f);
          if (((componentBit & uVar14) != 0) &&
             (iVar12 = ((int (*)())regBindingSet)(param_1,*puVar6,iVar11,componentBit,1), iVar12 != 0)) {
            return iVar12;
          }
          moreComponentsB = componentIndexC != 3;
          puVar6 = puVar6 + 1;
          componentIndexC = componentIndexC + 1;
        } while (moreComponentsB);
      }
    }
    cVar3 = *(char *)(iVar11 + param_1 + 0x3087c);
    if (bVar1) {
      loopCounterB = 0;
      uVar16 = 0;
      piVar18 = local_78;
      do {
        iVar9 = *piVar18;
        piVar18 = piVar18 + 1;
        if (iVar9 != -1) {
          for (puVar6 = *(uint **)(iVar9 * 4 + param_1 + 0xe450); puVar6 != (uint *)0x0;
              puVar6 = (uint *)puVar6[4]) {
            uVar14 = *puVar6;
            if ((*(uint *)(uVar14 * 4 + param_1 + 0x3348c) & 0x40000) == 0) {
              uVar8 = puVar6[1];
              uVar5 = 0;
              puVar7 = local_68;
              remaining = 4;
              do {
                uVar15 = 1 << (uVar5 & 0x3f);
                if ((uVar8 & uVar15 & ~(int)cVar3) != 0) {
                  if ((uVar15 & uVar16) == 0) {
                    *puVar7 = uVar14;
                    uVar16 = uVar16 | uVar15;
                  }
                  else if (uVar14 < *puVar7) {
                    *puVar7 = uVar14;
                  }
                }
                uVar5 = uVar5 + 1;
                puVar7 = puVar7 + 1;
                remaining = remaining + -1;
              } while (remaining != 0);
            }
          }
        }
        loopCounterB = loopCounterB + 1;
      } while (loopCounterB != iVar22);
      if (uVar16 != 0) {
        componentIndexB = 0;
        do {
          if ((1 << (componentIndexB & 0x3f) & uVar16) != 0) {
            componentIndex = 0;
            puVar6 = local_68;
            do {
              if (((componentIndexB != componentIndex) && ((1 << (componentIndex & 0x3f) & uVar16) != 0)) &&
                 ((uVar5 = local_68[componentIndexB], uVar5 < *puVar6 &&
                  (iVar22 = ((int (*)())recordGetWriteEnable)(uVar5 * 0x10 + iStack00000024,componentIndex), iVar22 != 0)))) {
                *puVar6 = uVar5;
              }
              moreComponents = componentIndex != 3;
              puVar6 = puVar6 + 1;
              componentIndex = componentIndex + 1;
            } while (moreComponents);
          }
          moreComponents = componentIndexB != 3;
          componentIndexB = componentIndexB + 1;
        } while (moreComponents);
        componentIndexB = 0;
        puVar6 = local_68;
        do {
          componentBit = 1 << (componentIndexB & 0x3f);
          if (((componentBit & uVar16) != 0) &&
             (iVar22 = ((int (*)())regBindingSet)(param_1,*puVar6,iVar11,componentBit,1), iVar22 != 0)) {
            return iVar22;
          }
          moreComponents = componentIndexB != 3;
          puVar6 = puVar6 + 1;
          componentIndexB = componentIndexB + 1;
        } while (moreComponents);
      }
    }
  }
LAB_000798a8:
  lastSource = sourceIndex == 2;
  param_3 = param_3 + 1;
  piVar21 = piVar21 + 1;
  sourceIndex = sourceIndex + 1;
  if (lastSource) {
    return 0;
  }
  goto LAB_00079150;
}

/* recordSetWriteMask @ 0x798f0 (28 bytes) */
int recordSetWriteMask(param_1, param_2)
  uint *param_1;
  uint param_2;
{
  *param_1 = (param_2 & 8) << 0x14 |
             (param_2 & 4) << 0x14 |
             (param_2 & 2) << 0x14 | (param_2 & 1) << 0x14 | *param_1 & 0xff0fffff;
  return;
}

/* depListAddEdge @ 0x79910 (248 bytes) */
int depListAddEdge(unusedArg1, listHead, recordIndex, componentMask, nodeField2, nodeField3, arena)
  undefined4 unusedArg1;
  int *listHead;
  int recordIndex;
  uint componentMask;
  int nodeField2;
  int nodeField3;
  undefined4 arena;
{
  int *newNode;
  int nextNode;
  int *node;
  int *lastNode;
  
  node = (int *)*listHead;
  if ((int *)*listHead == (int *)0x0) {
    newNode = (int *)((int (*)())chunkArenaAlloc)(arena,0x14);
    *listHead = (int)newNode;
    if (newNode != (int *)0x0) {
      newNode[3] = nodeField3;
      *newNode = recordIndex;
      newNode[1] = componentMask;
      newNode[4] = 0;
      newNode[2] = nodeField2;
      return 0;
    }
  }
  else {
    do {
      lastNode = node;
      if (recordIndex == *lastNode) {
        lastNode[1] = componentMask | lastNode[1];
        return 0;
      }
      node = (int *)lastNode[4];
    } while ((int *)lastNode[4] != (int *)0x0);
    newNode = (int *)((int (*)())chunkArenaAlloc)(arena,0x14);
    lastNode[4] = (int)newNode;
    if (newNode != (int *)0x0) {
      *newNode = recordIndex;
      newNode[1] = componentMask;
      newNode[4] = 0;
      nextNode = lastNode[4];
      *(int *)(nextNode + 0xc) = nodeField3;
      *(int *)(nextNode + 8) = nodeField2;
      return 0;
    }
  }
  return 7;
}

/* recordGetSourceSelect @ 0x79a20 (92 bytes) */
int recordGetSourceSelect(param_1, param_2)
  uint *param_1;
  int param_2;
{
  if (param_2 == 1) {
    return *(ushort *)param_1 & 7;
  }
  if (param_2 == 0) {
    return *param_1 >> 0xd & 7;
  }
  if (param_2 == 2) {
    return *param_1 >> 0x13 & 7;
  }
  if (param_2 != 3) {
    return 0;
  }
  return *param_1 >> 0x16 & 7;
}

/* recordSetSourceSelect @ 0x79a90 (100 bytes) */
int recordSetSourceSelect(param_1, param_2, param_3)
  uint *param_1;
  int param_2;
  uint param_3;
{
  if (param_2 == 1) {
    *param_1 = (param_3 & 7) << 0x10 | *param_1 & 0xfff8ffff;
    return;
  }
  if (param_2 == 0) {
    *param_1 = (param_3 & 7) << 0xd | *param_1 & 0xffff1fff;
    return;
  }
  if (param_2 == 2) {
    *param_1 = (param_3 & 7) << 0x13 | *param_1 & 0xffc7ffff;
    return;
  }
  if (param_2 != 3) {
    return;
  }
  *param_1 = (param_3 & 7) << 0x16 | *param_1 & 0xfe3fffff;
  return;
}

/* recordAddTransitiveDependencies @ 0x79b00 (200 bytes) */
int recordAddTransitiveDependencies(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  undefined4 param_4;
{
  int iVar1;
  undefined4 *puVar2;
  
  if ((param_3 != param_2) && (((unsigned char *)0x00030c50)[param_3 + param_1] == 0)) {
    ((unsigned char *)0x00030c50)[param_3 + param_1] = 1;
    iVar1 = ((int (*)())depListAddEdge)(param_1,param_1 + 0xe450 + param_2 * 4,param_3,param_4,0,0,param_1 + 0x38);
    if (iVar1 != 0) {
      return iVar1;
    }
    for (puVar2 = *(undefined4 **)(param_3 * 4 + param_1 + 0xc450); puVar2 != (undefined4 *)0x0;
        puVar2 = (undefined4 *)puVar2[4]) {
      iVar1 = ((int (*)())recordAddTransitiveDependencies)(param_1,param_2,*puVar2,puVar2[1]);
      if (iVar1 != 0) {
        return iVar1;
      }
    }
  }
  return 0;
}

/* recordLinkSourceToDefinition @ 0x79bd0 (532 bytes) */
int recordLinkSourceToDefinition(alloc, records, recordsCopy, dependent, recordIndex, sourceSlot, componentSel)
  int alloc;
  int records;
  int recordsCopy;
  int dependent;
  int recordIndex;
  int sourceSlot;
  undefined4 componentSel;
{
  bool linked;
  int sourceByteOffset;
  bool fileMatches;
  uint sourceFile;
  uint sourceSelect;
  int writesComponent;
  uint defFile;
  uint *sourcePtr;
  int defIndex;
  int loopIndex;
  uint *defRecord;
  
  sourceByteOffset = (recordIndex * 4 + sourceSlot) * 4;
  sourcePtr = (uint *)(sourceByteOffset + records + 4);
  sourceSelect = ((int (*)())recordGetSourceSelect)(sourcePtr,componentSel);
  if ((1 < sourceSelect - 4) && (defIndex = recordIndex + -1, -1 < defIndex)) {
    defRecord = (uint *)(records + defIndex * 0x10);
    loopIndex = 0;
    do {
      sourceFile = *sourcePtr & 0xf;
      defFile = *defRecord >> 8 & 0xf;
      if (sourceFile == 1) {
        fileMatches = defFile == 5;
LAB_00079cd0:
        if (((!fileMatches) || ((*defRecord >> 0xd & 0x7f) != (*sourcePtr >> 5 & 0xff))) ||
           (writesComponent = ((int (*)())recordGetWriteEnable)(defRecord,sourceSelect), writesComponent == 0)) goto LAB_00079dc0;
        if ((char)*defRecord == 'A') {
          if (((**(uint **)(alloc + 0x34) & 0x280) == 0) || (sourceSelect != 3)) {
LAB_00079d90:
            ((int (*)())depListAddEdge)(alloc,dependent + 0x418 + (recordIndex * 3 + sourceSlot) * 4,defIndex - loopIndex,
                         1 << (sourceSelect & 0x3f),0,0,dependent);
            linked = true;
          }
          else {
            ((int (*)())recordSetSourceSelect)(sourcePtr,componentSel,5);
            if (recordsCopy == 0) goto LAB_00079dc8;
LAB_00079d78:
            linked = true;
            *(uint *)(sourceByteOffset + recordsCopy + 4) = *sourcePtr;
          }
        }
        else {
          if (((char)*defRecord != 'D') || ((sourceSelect != 0 && (sourceSelect != 3)))) goto LAB_00079d90;
          ((int (*)())recordSetSourceSelect)(sourcePtr,componentSel,5);
          if ((recordsCopy != 0) && ((**(uint **)(alloc + 0x34) & 0x200) != 0)) goto LAB_00079d78;
LAB_00079dc8:
          linked = true;
        }
      }
      else {
        if (sourceFile == 0) {
          fileMatches = defFile == 0;
          goto LAB_00079cd0;
        }
        if (sourceFile == 3) {
          fileMatches = defFile == 4;
          goto LAB_00079cd0;
        }
LAB_00079dc0:
        linked = false;
      }
      if (defIndex == loopIndex) {
        return;
      }
      loopIndex = loopIndex + 1;
      defRecord = defRecord + -4;
    } while (!linked);
  }
  return;
}

/* recordSourcesAreDistinctTemps @ 0x79e10 (88 bytes) */
int recordSourcesAreDistinctTemps(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  if ((((*(uint *)(param_1 + 4) & 0xf) == 0) && ((*(uint *)(param_1 + 8) & 0xf) == 0)) &&
     ((*(uint *)(param_1 + 0xc) & 0xf) == 0)) {
    uVar1 = *(uint *)(param_1 + 4) & 0x1fe0;
    uVar2 = *(uint *)(param_1 + 8) & 0x1fe0;
    if (((uVar1 != uVar2) && (uVar3 = *(uint *)(param_1 + 0xc) & 0x1fe0, uVar2 != uVar3)) &&
       (uVar1 != uVar3)) {
      return 1;
    }
  }
  return 0;
}

/* recordFindScheduleConflict @ 0x79e70 (488 bytes) */
int recordFindScheduleConflict(alloc, param_2)
  int alloc;
  int param_2;
{
  bool bVar1;
  bool overlaps;
  bool conflictFound;
  uint recordWord0;
  byte bVar5;
  undefined4 in_r5;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  uint uVar6;
  undefined4 resultCode;
  uint queueCount;
  uint *record;
  int programBase;
  int *dependencyNode;
  int laterRecordIndex;
  uint loopIndex;
  int *laterQueueCursor;
  int iVar15;
  uint laterQueueIndex;
  undefined8 uVar17;
  
  programBase = alloc + 0x1286c;
  queueCount = *(uint *)(alloc + 0x2a878);
  if (queueCount != 0) {
    bVar1 = param_2 != 0;
    loopIndex = 0;
    resultCode = 6;
    conflictFound = false;
    do {
      iVar15 = *(int *)(loopIndex * 4 + alloc + 0x28878);
      record = (uint *)(programBase + iVar15 * 0x10);
      if ((((bVar1) && ((**(uint **)(alloc + 0x34) & 0x40) != 0)) &&
          (bVar5 = (char)*record + 0xbc, bVar5 < 0xb)) &&
         (uVar6 = 1 << ((int)(char)bVar5 & 0x3fU) & 0x601, uVar6 != 0)) {
        uVar17 = ((int (*)())recordSourcesAreDistinctTemps)(record,param_2,in_r5,in_r6,in_r7,in_r8,uVar6);
        param_2 = (int)uVar17;
        if ((int)((ulonglong)uVar17 >> 0x20) != 0) {
          conflictFound = true;
          resultCode = 8;
        }
      }
      dependencyNode = *(int **)(iVar15 * 4 + alloc + 0xa450);
      if (dependencyNode != (int *)0x0) {
        uVar6 = loopIndex + 1;
        do {
          if (uVar6 < queueCount) {
            recordWord0 = *record;
            iVar15 = *dependencyNode;
            laterQueueCursor = (int *)(alloc + uVar6 * 4 + 0x28878);
            laterQueueIndex = uVar6;
            do {
              laterRecordIndex = *laterQueueCursor;
              if ((*(uint *)(programBase + laterRecordIndex * 0x10) & 0xfef00) == (recordWord0 & 0xfef00)) {
                uVar17 = ((int (*)())recordGetWriteMask)(programBase + laterRecordIndex * 0x10);
                param_2 = (int)uVar17;
                overlaps = true;
                if (((uint)((ulonglong)uVar17 >> 0x20) & dependencyNode[1]) == 0) goto LAB_00079fc0;
              }
              else {
LAB_00079fc0:
                overlaps = false;
              }
              laterQueueIndex = laterQueueIndex + 1;
              if (queueCount == laterQueueIndex) {
                if (overlaps) {
LAB_00079ffc:
                  if (laterRecordIndex != iVar15) {
                    conflictFound = true;
                    resultCode = 9;
                  }
                }
                break;
              }
              if (overlaps) goto LAB_00079ffc;
              laterQueueCursor = laterQueueCursor + 1;
            } while (laterRecordIndex != iVar15);
          }
          dependencyNode = (int *)dependencyNode[4];
        } while (dependencyNode != (int *)0x0);
      }
      loopIndex = loopIndex + 1;
    } while (loopIndex < queueCount);
    if (conflictFound) {
      return resultCode;
    }
  }
  return 0;
}

/* chunkArenaResetCursor @ 0x7a060 (16 bytes) */
int chunkArenaResetCursor(param_1)
  int param_1;
{
  *(undefined4 *)(param_1 + 0x410) = 0;
  *(undefined4 *)(param_1 + 0x414) = 0;
  return;
}

/* chunkArenaFree @ 0x7a070 (156 bytes) */
int chunkArenaFree(param_1)
  int param_1;
{
  uint uVar1;
  uint loopIndex;
  int iVar3;
  
  if (*(int *)(param_1 + 0x408) != 0) {
    loopIndex = 0;
    iVar3 = param_1;
    do {
      loopIndex = loopIndex + 1;
      (**(code **)(param_1 + 4))(*(undefined4 *)(iVar3 + 8));
      uVar1 = *(uint *)(param_1 + 0x408);
      *(undefined4 *)(iVar3 + 8) = 0;
      iVar3 = iVar3 + 4;
    } while (loopIndex < uVar1);
  }
  *(undefined4 *)(param_1 + 0x40c) = 0;
  *(undefined4 *)(param_1 + 0x408) = 0;
  return ((int (*)())chunkArenaResetCursor)(param_1);
}

/* recordAllocFree @ 0x7a110 (100 bytes) */
int recordAllocFree(param_1)
  int param_1;
{
  if (param_1 != 0) {
    ((int (*)())chunkArenaFree)(param_1 + 0x12454);
    ((int (*)())chunkArenaFree)(param_1 + 0x38);
                    
                    
    (**(code **)(param_1 + 0x12458))(param_1);
    return;
  }
  return;
}

/* recordRemapComponents @ 0x7a1a0 (756 bytes) */
int recordRemapComponents(alloc, recordIndex, swizzle)
  int alloc;
  int recordIndex;
  uint swizzle;
{
  uint loopCounterC;
  uint loopCounterB;
  uint sourceIndex;
  uint loopCounter;
  int remaining;
  bool moreComponents;
  bool moreSources;
  bool found;
  int recordSlot;
  uint sourceSelects;
  uint uVar4;
  int *readerNode;
  uint uVar6;
  int *consumerNode;
  uint componentIndex;
  uint selectShift;
  undefined4 *listHeadCursor;
  uint sourceIndexB;
  uint *sourceWordCursor;
  uint uVar13;
  uint remappedMask;
  uint *recordWordCursor;
  int consumerIndex;
  int remainingB;
  
  recordSlot = recordIndex * 4;
  recordWordCursor = (uint *)(alloc + 0x1286c + recordIndex * 0x10);
  remappedMask = 0;
  uVar13 = *(uint *)(recordSlot + alloc + 0x6450);
  uVar6 = ((int (*)())recordGetWriteMask)(recordWordCursor);
  loopCounter = 0;
  remaining = 4;
  do {
    if ((uVar6 & 1 << (loopCounter & 0x3f)) != 0) {
      remappedMask = remappedMask | 1 << (swizzle >> ((loopCounter & 0xf) << 2) & 0xf);
    }
    loopCounter = loopCounter + 1;
    remaining = remaining + -1;
  } while (remaining != 0);
  if (uVar6 != remappedMask) {
    componentIndex = 0;
    uVar4 = 0xd;
    do {
      if ((uVar6 & 1 << (componentIndex & 0x3f)) != 0) {
        sourceIndexB = 0;
        selectShift = (swizzle >> ((componentIndex & 0xf) << 2) & 0xf) * 3 + 0xd;
        sourceWordCursor = recordWordCursor;
        do {
          if ((uVar13 & 1 << (sourceIndexB & 0x3f)) != 0) {
            sourceSelects = sourceWordCursor[1];
            sourceWordCursor[1] = (sourceSelects & ~(7 << (uVar4 & 0x3f)) |
                         (sourceSelects >> (selectShift & 0x3f) & 7) << (uVar4 & 0x3f)) & ~(7 << (selectShift & 0x3f)) |
                         (sourceSelects >> (uVar4 & 0x3f) & 7) << (selectShift & 0x3f);
          }
          moreSources = sourceIndexB != 2;
          sourceWordCursor = sourceWordCursor + 1;
          sourceIndexB = sourceIndexB + 1;
        } while (moreSources);
      }
      moreComponents = componentIndex != 3;
      uVar4 = uVar4 + 3;
      componentIndex = componentIndex + 1;
    } while (moreComponents);
    *recordWordCursor = *recordWordCursor & 0xff0fffff | remappedMask << 0x14;
    for (consumerNode = *(int **)(recordSlot + alloc + 0xa450); consumerNode != (int *)0x0;
        consumerNode = (int *)consumerNode[4]) {
      consumerIndex = *consumerNode;
      uVar6 = 0;
      loopCounterB = 0;
      remainingB = 4;
      uVar4 = *(uint *)(consumerIndex * 4 + alloc + 0x6450);
      recordWordCursor = (uint *)(alloc + consumerIndex * 0x10 + 0x12870);
      do {
        if ((consumerNode[1] & 1 << (loopCounterB & 0x3f)) != 0) {
          uVar6 = uVar6 | 1 << (swizzle >> ((loopCounterB & 0xf) << 2) & 0xf);
        }
        loopCounterB = loopCounterB + 1;
        remainingB = remainingB + -1;
      } while (remainingB != 0);
      consumerNode[1] = uVar6;
      sourceIndex = 0;
      listHeadCursor = (undefined4 *)(consumerIndex * 0xc + alloc + 0x450);
      do {
        if (((uVar4 & 1 << (sourceIndex & 0x3f)) != 0) && (readerNode = (int *)*listHeadCursor, readerNode != (int *)0x0)
           ) {
          found = false;
          do {
            if (recordIndex == *readerNode) {
              uVar13 = 0;
              loopCounterC = 0;
              remaining = 4;
              do {
                if ((readerNode[1] & 1 << (loopCounterC & 0x3f)) != 0) {
                  uVar13 = uVar13 | 1 << (swizzle >> ((loopCounterC & 0xf) << 2) & 0xf);
                }
                loopCounterC = loopCounterC + 1;
                remaining = remaining + -1;
              } while (remaining != 0);
              readerNode[1] = uVar13;
              found = true;
            }
            readerNode = (int *)readerNode[4];
          } while (readerNode != (int *)0x0);
          if (found) {
            *recordWordCursor = (swizzle >> (*recordWordCursor >> 0x1b & 0xc) & 3) << 0x1d | *recordWordCursor & 0x9fffffff;
          }
        }
        moreSources = sourceIndex != 2;
        recordWordCursor = recordWordCursor + 1;
        listHeadCursor = listHeadCursor + 1;
        sourceIndex = sourceIndex + 1;
      } while (moreSources);
    }
    for (listHeadCursor = *(undefined4 **)(recordSlot + alloc + 0xc450); listHeadCursor != (undefined4 *)0x0;
        listHeadCursor = (undefined4 *)listHeadCursor[4]) {
      ((int (*)())recordRemapComponents)(alloc,*listHeadCursor,swizzle);
    }
  }
  return;
}

/* recordPlanDestination @ 0x7a4a0 (1544 bytes) */
int recordPlanDestination(ctx, program, laterPass, tempRegLimit, recordIndex, keepFlagOut, chosenRegOut)
  int ctx;
  int program;
  int laterPass;
  uint tempRegLimit;
  int recordIndex;
  undefined1 *keepFlagOut;
  uint *chosenRegOut;
{
  int *useListNode;
  int *fixedValueIdCursor;
  int otherRecordIndex;
  int slotBase;
  uint candidateReg;
  uint recordWord0;
  uint otherWriteMask;
  uint loopCounterC;
  uint loopCounterB;
  uint componentIndexB;
  uint componentBit;
  uint componentIndex;
  uint loopCounter;
  int remaining;
  bool lastComponent;
  bool moreComponents;
  bool matched;
  char regFileBase;
  undefined *chosenSwizzle;
  int remainingBits;
  int callResult;
  uint combinedWriteMask;
  uint writeMask;
  int *listNode;
  undefined4 result;
  undefined4 destWriteMask;
  uint fixedMask;
  undefined4 *fixedHeadCursor;
  uint swizzleShiftBits;
  uint writeMaskSwizzled;
  uint combinedSwizzledMask;
  uint *record;
  int *fixedNode;
  undefined *swizzleWord;
  
  *keepFlagOut = 0;
  *chosenRegOut = 0xffffffff;
  record = (uint *)(recordIndex * 0x10 + program);
  callResult = ((int (*)())recordDestFileIs0Or45)(record,laterPass);
  if (callResult == 0) {
    callResult = ((int (*)())recordDestFileIs3Or1)(record,laterPass);
    if (callResult != 0) {
      swizzleWord = ((unsigned char *)0x00003210U);
      combinedWriteMask = ((int (*)())recordCombinedWriteMask)(ctx,recordIndex);
      writeMask = ((int (*)())recordGetWriteMask)(record);
      loopCounterC = 0;
      componentIndexB = 0;
      slotBase = recordIndex * 4 + ctx;
      fixedMask = (uint)*(char *)(ctx + 0x30b9c);
LAB_0007a7b0:
      if (((combinedWriteMask & fixedMask & 1 << (componentIndexB & 0x3f)) == 0) || (4 < loopCounterC)) goto LAB_0007aa50;
      if (loopCounterC != 4) {
        if ((1 << (loopCounterC & 0x3f) & ~(combinedWriteMask | fixedMask)) == 0) {
          remainingBits = 5 - loopCounterC;
          do {
            loopCounterC = loopCounterC + 1;
            remainingBits = remainingBits + -1;
            if (remainingBits == 0) goto LAB_0007aa50;
            if (loopCounterC == 4) goto LAB_0007a7e8;
          } while ((1 << (loopCounterC & 0x3f) & ~(combinedWriteMask | fixedMask)) == 0);
        }
        swizzleShiftBits = loopCounterC << (componentIndexB << 2 & 0x3c);
        loopCounterC = loopCounterC + 1;
        swizzleWord = (undefined *)((uint)swizzleWord & ~(0xf << (componentIndexB << 2 & 0x3c)) | swizzleShiftBits);
        goto LAB_0007aa50;
      }
LAB_0007a7e8:
      combinedSwizzledMask = 0;
      loopCounterB = 0;
      remaining = 4;
      do {
        if ((combinedWriteMask & 1 << (loopCounterB & 0x3f)) != 0) {
          combinedSwizzledMask = combinedSwizzledMask | 1 << ((uint)swizzleWord >> ((loopCounterB & 0xf) << 2) & 0xf);
        }
        loopCounterB = loopCounterB + 1;
        remaining = remaining + -1;
      } while (remaining != 0);
      writeMaskSwizzled = 0;
      loopCounter = 0;
      remaining = 4;
      do {
        if ((writeMask & 1 << (loopCounter & 0x3f)) != 0) {
          writeMaskSwizzled = writeMaskSwizzled | 1 << ((uint)swizzleWord >> ((loopCounter & 0xf) << 2) & 0xf);
        }
        loopCounter = loopCounter + 1;
        remaining = remaining + -1;
      } while (remaining != 0);
      fixedMask = fixedMask & combinedSwizzledMask;
      if (fixedMask == 0) {
LAB_0007aa5c:
        chosenSwizzle = swizzleWord;
      }
      else {
        fixedHeadCursor = (undefined4 *)(ctx + 0x30b7c);
        loopCounter = 0;
        remaining = 4;
        do {
          componentBit = 1 << (loopCounter & 0x3f);
          if (((((componentBit & fixedMask) != 0) && (fixedNode = (int *)*fixedHeadCursor, fixedNode != (int *)0x0)) &&
              (recordIndex == *fixedNode)) && (fixedNode[1] == 0)) {
            fixedMask = fixedMask & ~componentBit;
          }
          loopCounter = loopCounter + 1;
          fixedHeadCursor = fixedHeadCursor + 1;
          remaining = remaining + -1;
        } while (remaining != 0);
        if (fixedMask == 0) goto LAB_0007aa5c;
        fixedValueIdCursor = (int *)(ctx + 0x30b8c);
        componentIndex = 0;
        do {
          componentBit = 1 << (componentIndex & 0x3f);
          if ((componentBit & fixedMask) != 0) {
            if ((componentBit & writeMaskSwizzled) == 0) {
              listNode = *(int **)(slotBase + 0xc450);
              if (listNode != (int *)0x0) {
                do {
                  if (((componentBit & listNode[1]) == 0) || (matched = true, *listNode != *fixedValueIdCursor)) {
                    matched = false;
                  }
                  listNode = (int *)listNode[4];
                  if (listNode == (int *)0x0) {
                    if (!matched) goto LAB_0007a948;
                    break;
                  }
                } while (!matched);
                goto LAB_0007a944;
              }
            }
            else if (recordIndex == *fixedValueIdCursor) {
LAB_0007a944:
              fixedMask = fixedMask & ~componentBit;
            }
          }
LAB_0007a948:
          moreComponents = componentIndex != 3;
          fixedValueIdCursor = fixedValueIdCursor + 1;
          componentIndex = componentIndex + 1;
        } while (moreComponents);
        if (fixedMask == 0) goto LAB_0007aa5c;
        fixedValueIdCursor = (int *)(ctx + 0x30b8c);
        componentIndex = 0;
        do {
          componentBit = 1 << (componentIndex & 0x3f);
          if ((((componentBit & fixedMask) != 0) && ((componentBit & writeMaskSwizzled) == 0)) &&
             (listNode = *(int **)(slotBase + 0xe450), listNode != (int *)0x0)) {
            do {
              if (((componentBit & listNode[1]) == 0) || (matched = true, *listNode != *fixedValueIdCursor)) {
                matched = false;
              }
              listNode = (int *)listNode[4];
              if (listNode == (int *)0x0) {
                if (!matched) goto LAB_0007a9d4;
                break;
              }
            } while (!matched);
            fixedMask = fixedMask & ~componentBit;
          }
LAB_0007a9d4:
          moreComponents = componentIndex != 3;
          fixedValueIdCursor = fixedValueIdCursor + 1;
          componentIndex = componentIndex + 1;
        } while (moreComponents);
        chosenSwizzle = (undefined *)0xffffffff;
        if (fixedMask == 0) goto LAB_0007aa5c;
      }
      *chosenRegOut = (uint)chosenSwizzle;
      if (chosenSwizzle != (undefined *)0xffffffff) {
        if (chosenSwizzle == ((unsigned char *)0x00003210U)) goto LAB_0007a680;
        goto LAB_0007aa80;
      }
      goto LAB_0007aa90;
    }
LAB_0007a680:
    result = 1;
  }
  else {
    if (((*(uint *)(recordIndex * 4 + ctx + 0x3348c) & 0x1000) != 0) &&
       (callResult = ((int (*)())recordAssignDestinationRegister)(ctx,program,recordIndex,keepFlagOut,chosenRegOut), callResult != 0)) {
      return 1;
    }
    otherWriteMask = ((int (*)())recordGetWriteMask)(record);
    for (useListNode = *(int **)(recordIndex * 4 + ctx + 0xe450); useListNode != (int *)0x0;
        useListNode = (int *)useListNode[4]) {
      otherRecordIndex = *useListNode;
      writeMask = ((int (*)())recordGetWriteMask)(program + otherRecordIndex * 0x10);
      if (((otherWriteMask & writeMask) != 0) &&
         (otherRecordIndex = otherRecordIndex * 4 + ctx, (*(uint *)(otherRecordIndex + 0x3348c) & 0x40000) != 0)) {
        for (listNode = *(int **)(otherRecordIndex + 0xa450); listNode != (int *)0x0; listNode = (int *)listNode[4]) {
          if (((recordIndex != *listNode) && ((otherWriteMask & writeMask & listNode[1]) != 0)) &&
             ((*(uint *)(*listNode * 4 + ctx + 0x3348c) & 0x40000) == 0)) goto LAB_0007aa90;
        }
      }
    }
    result = ((int (*)())recordCombinedWriteMask)(ctx,recordIndex);
    callResult = ((int (*)())recordDestFileIs0)(record);
    if (callResult == 0) {
      recordWord0 = *record;
LAB_0007a634:
      regFileBase = (DAT_001aa758)[recordWord0 >> 8 & 0xf];
      destWriteMask = ((int (*)())recordGetWriteMask)(record);
      callResult = ((int (*)())recordRegisterIsAssignable)(ctx,program,regFileBase * 0x100 + (recordWord0 >> 0xd & 0x7f),result,recordIndex,
                           destWriteMask);
      if (callResult == 0) goto LAB_0007a680;
    }
    else {
      recordWord0 = *record;
      if ((recordWord0 >> 0xd & 0x7f) < tempRegLimit) goto LAB_0007a634;
    }
    callResult = ((int (*)())recordDestFileIs0)(record);
    if (callResult == 0) {
      if (((*record & 0xf00) != 0x400) || (matched = true, laterPass == 0)) {
        matched = false;
      }
      if (matched) {
        destWriteMask = ((int (*)())recordGetWriteMask)(record);
        candidateReg = ((int (*)())recordFindFreeTempRegister)(ctx,program,result,recordIndex,destWriteMask);
        *chosenRegOut = candidateReg;
      }
    }
    else {
      destWriteMask = ((int (*)())recordGetWriteMask)(record);
      if (tempRegLimit != 0) {
        loopCounter = 0;
        do {
          callResult = ((int (*)())recordRegisterIsAssignable)(ctx,program,loopCounter,result,recordIndex,destWriteMask);
          if (callResult == 0) goto LAB_0007a6e4;
          loopCounter = loopCounter + 1;
        } while (tempRegLimit != loopCounter);
      }
      loopCounter = 0xffffffff;
LAB_0007a6e4:
      *chosenRegOut = loopCounter;
    }
    if ((int)*chosenRegOut < 0) {
LAB_0007aa90:
      result = 0;
    }
    else {
LAB_0007aa80:
      result = 1;
      *keepFlagOut = 1;
    }
  }
  return result;
LAB_0007aa50:
  lastComponent = componentIndexB == 3;
  componentIndexB = componentIndexB + 1;
  if (lastComponent) goto LAB_0007aa5c;
  goto LAB_0007a7b0;
}

/* recordPickNextToEmit @ 0x7aae0 (1460 bytes) */
int recordPickNextToEmit(ctx, registerCount, readyCycle, keepFlag, chosenReg, program, param_7, laterPass)
  int ctx;
  int registerCount;
  uint readyCycle;
  undefined1 *keepFlag;
  undefined4 *chosenReg;
  int program;
  undefined4 param_7;
  undefined4 laterPass;
{
  char *chosenAffinity;
  int otherIndex;
  int score;
  uint *chosenRecordPtr;
  int affinityBase;
  int unitAllowed;
  int bestScore;
  int fitOk;
  int assignOk;
  int pairState;
  uint sourceIndexB;
  int loopCounterB;
  int loopCounter;
  int sourceIndex;
  bool moreSources;
  uint loopIndex;
  uint loopIndex2;
  bool allOwned;
  byte chosenUnitByte;
  int remainingRegisters;
  int registerCountArg;
  uint *candidateRecord;
  undefined4 *userHeadCursor;
  int candidateFits;
  int iVar8;
  undefined4 a2;
  int a4;
  byte *a5;
  int *userNode;
  int candidateSlot;
  undefined4 chosenRegValue;
  int otherAllowed;
  char *slotCursor;
  uint sourceMask;
  uint chosenUnit;
  int candidateIndex;
  uint *otherRecord;
  int *queueCursor;
  uint otherUnit;
  uint uStack00000020;
  undefined1 *puStack00000024;
  undefined4 *puStack00000028;
  byte candidateKeepFlag;
  undefined1 keepFlagTmp [3];
  undefined4 candidateRegValue;
  undefined4 chosenRegTmp [2];
  int chosenRecord;
  int haveChoice;
  uint chosenKeepFlag;
  int queueBase;
  undefined4 *local_58;
  
  *keepFlag = 0;
  candidateKeepFlag = 0;
  candidateRegValue = 0;
  if (registerCount == 0) {
    loopCounterB = 0;
  }
  else {
    loopCounterB = 0;
    slotCursor = (char *)(ctx + 0x3087c);
    remainingRegisters = registerCount;
    do {
      if (*slotCursor == '\0') {
        loopCounterB = loopCounterB + 1;
      }
      slotCursor = slotCursor + 1;
      remainingRegisters = remainingRegisters + -1;
    } while (remainingRegisters != 0);
  }
  pairState = *(int *)(ctx + 0x35490);
  uStack00000020 = readyCycle;
  puStack00000024 = keepFlag;
  puStack00000028 = chosenReg;
  if (pairState == 2) {
    chosenRecord = *(int *)(ctx + 0x35494);
    *(undefined4 *)(ctx + 0x35490) = 3;
    assignOk = ((int (*)())recordAssignDestinationRegister)(ctx,program,chosenRecord,keepFlag,chosenReg);
    if (assignOk != 0) {
      ((int (*)())recordMarkPairEmitted)(ctx);
      return chosenRecord;
    }
  }
  else if (pairState == 3) {
    *(undefined4 *)(ctx + 0x35490) = 0;
  }
  else if (pairState == 1) {
    chosenRecord = *(int *)(ctx + 0x35498);
    keepFlagTmp[0] = 0;
    fitOk = ((int (*)())recordPlanDestination)(ctx,program,laterPass,registerCount,chosenRecord,keepFlagTmp,chosenRegTmp);
    *(undefined4 *)(ctx + 0x35490) = 3;
    if (fitOk != 0) {
      *puStack00000024 = keepFlagTmp[0];
      *puStack00000028 = chosenRegTmp[0];
      ((int (*)())recordMarkPairEmitted)(ctx);
      return chosenRecord;
    }
  }
  chosenRecord = 0;
  if (*(int *)(ctx + 0x28874) != 0) {
    queueBase = ctx + 0x20000;
    local_58 = &candidateRegValue;
    bestScore = -1;
    queueCursor = (int *)(ctx + 0x26874);
    chosenKeepFlag = 0;
    haveChoice = 0;
    loopIndex = 0;
    chosenRegValue = 0;
    do {
      sourceIndex = 0;
      candidateKeepFlag = 0;
      a4 = *queueCursor;
      do {
        moreSources = sourceIndex != 2;
        sourceIndex = sourceIndex + 1;
      } while (moreSources);
      a5 = &candidateKeepFlag;
      a2 = laterPass;
      registerCountArg = registerCount;
      candidateFits = ((int (*)())recordPlanDestination)(ctx,program,laterPass,registerCount,a4,a5,local_58);
      if (candidateFits != 0) {
        score = 100;
        if (uStack00000020 <= (uint)queueCursor[-0x1001]) {
          score = 0;
        }
        candidateIndex = *queueCursor;
        candidateSlot = candidateIndex * 4 + ctx;
        score = *(int *)(candidateSlot + 0x10454) * 2 + score;
        if (*(int *)(candidateSlot + 0x8450) != 0) {
          score = score + 0x20;
        }
        sourceMask = *(uint *)(candidateSlot + 0x6450);
        loopCounter = 0;
        sourceIndexB = 0;
        candidateRecord = (uint *)(program + candidateIndex * 0x10);
        do {
          candidateRecord = candidateRecord + 1;
          if (((sourceMask & 1 << (sourceIndexB & 0x3f)) != 0) && (iVar8 = ((int (*)())recordSourceFileIs0)(candidateRecord), iVar8 != 0))
          {
            allOwned = true;
            iVar8 = 4;
            userHeadCursor = (undefined4 *)
                     (((char)(DAT_001aa760)[*candidateRecord & 0xf] * 0x100 + (*candidateRecord >> 5 & 0xff)) * 0x10
                      + ctx + 0x2a87c);
            do {
              userNode = (int *)*userHeadCursor;
              if ((userNode != (int *)0x0) && ((candidateIndex != *userNode || (userNode[1] != 0)))) {
                allOwned = false;
              }
              iVar8 = iVar8 + -1;
              if (iVar8 == 0) {
                if (allOwned) {
                  loopCounter = loopCounter + 1;
                }
                break;
              }
              userHeadCursor = userHeadCursor + 1;
            } while (allOwned);
          }
          moreSources = sourceIndexB != 2;
          sourceIndexB = sourceIndexB + 1;
        } while (moreSources);
        score = loopCounter * (registerCount - loopCounterB) * 2 + score;
        if ((bestScore < score) || (loopIndex == 0)) {
          chosenKeepFlag = (uint)candidateKeepFlag;
          haveChoice = 1;
          chosenRegValue = candidateRegValue;
          bestScore = score;
          chosenRecord = candidateIndex;
        }
      }
      loopIndex = loopIndex + 1;
      queueCursor = queueCursor + 1;
    } while (loopIndex < *(uint *)(ctx + 0x28874));
    if (haveChoice != 0) {
      *puStack00000024 = (char)chosenKeepFlag;
      *puStack00000028 = chosenRegValue;
      chosenRecordPtr = (uint *)(program + chosenRecord * 0x10);
      chosenUnitByte = (byte)*chosenRecordPtr >> 6;
      chosenUnit = chosenUnitByte & 1;
      unitAllowed = (*(code *)(PTR_FUN_001e9150)[chosenUnit])
                        (ctx,chosenRecord,a2,registerCountArg,a4,a5,&PTR_FUN_001e9150);
      if (unitAllowed == 0) {
        return chosenRecord;
      }
      if (*(int *)(ctx + 0x28874) == 0) {
        return chosenRecord;
      }
      affinityBase = ctx + 0x3148c;
      loopIndex2 = 0;
      queueCursor = (int *)(queueBase + 0x6874);
      chosenAffinity = (char *)(affinityBase + chosenRecord * 4);
      do {
        otherIndex = *queueCursor;
        otherRecord = (uint *)(program + otherIndex * 0x10);
        otherUnit = (byte)((byte)*otherRecord >> 6) & 1;
        otherAllowed = (*(code *)(PTR_FUN_001e9150)[otherUnit])
                           (ctx,otherIndex,a2,registerCountArg,a4,a5,&PTR_FUN_001e9150);
        if ((otherAllowed != 0) && (chosenUnit != otherUnit)) {
          otherAllowed = affinityBase + otherIndex * 4;
          if ((*chosenRecordPtr & 0x40) == 0) {
            otherRecord = chosenRecordPtr;
          }
          if (((((int)*chosenAffinity + (int)*(char *)(affinityBase + otherIndex * 4) < 3) &&
               ((int)chosenAffinity[1] + (int)*(char *)(otherAllowed + 1) < 2)) &&
              ((int)chosenAffinity[2] + (int)*(char *)(otherAllowed + 2) < 2)) &&
             (((int)chosenAffinity[3] + (int)*(char *)(otherAllowed + 3) < 2 && ((*otherRecord & 0xf00) != 0x400))))
          {
            if ((chosenUnitByte & 1) == 0) {
              *(int *)(ctx + 0x35494) = otherIndex;
              *(int *)(ctx + 0x35498) = chosenRecord;
            }
            else {
              *(int *)(ctx + 0x35498) = otherIndex;
              *(int *)(ctx + 0x35494) = chosenRecord;
            }
            if (*(int *)(ctx + 0x35494) == chosenRecord) {
              assignOk = ((int (*)())recordAssignDestinationRegister)(ctx,program,chosenRecord,keepFlagTmp,chosenRegTmp);
              if (assignOk != 0) {
                *(undefined4 *)(ctx + 0x35490) = 1;
                *puStack00000024 = keepFlagTmp[0];
                *puStack00000028 = chosenRegTmp[0];
                return chosenRecord;
              }
              *(undefined4 *)(ctx + 0x35490) = 0;
              return chosenRecord;
            }
            *(undefined4 *)(ctx + 0x35490) = 2;
            return chosenRecord;
          }
        }
        loopIndex2 = loopIndex2 + 1;
        queueCursor = queueCursor + 1;
        if (*(uint *)(ctx + 0x28874) <= loopIndex2) {
          return chosenRecord;
        }
      } while( true );
    }
  }
  return -1;
}

/* recordProgramAllocateAndEmit @ 0x7b0d0 (5660 bytes) */
int recordProgramAllocateAndEmit(alloc, unusedArg2, scratchArg3, scratchArg4, scratchArg5, scratchArg6, unusedArg7, unusedArg8)
  int alloc;
  undefined4 unusedArg2;
  code *scratchArg3;
  code *scratchArg4;
  int *scratchArg5;
  code *scratchArg6;
  undefined4 unusedArg7;
  undefined4 unusedArg8;
{
  undefined4 *retiredMoveCursor;
  uint opcodeRewriteIndex;
  uint retiredScanIndex;
  uint componentsSeen;
  uint componentCounter;
  bool moreComponents;
  bool haveChainHead;
  bool moreWords;
  bool moreSlots;
  bool moreComponentsB;
  int retiredIndexOffset;
  int retiredCountSnapshot;
  int componentsLeft;
  int calleeStatus;
  int recordIsFixed;
  int srcRegisterIndex;
  int flagOffset;
  int loopIndex;
  int opcodeInfoOffsetB;
  int retiredCount;
  int emittedCount;
  int recordFlagsBase;
  uint outWord3B;
  uint sourceLoop;
  uint componentBit;
  uint outWord0;
  uint partnerSourceUsedMask;
  uint sourceOperandIndex;
  uint secondRecordWord0;
  uint sourceUsedMask;
  uint writeMaskB;
  unsigned char *liveListPtrB;
  unsigned char *sourceWordPtr;
  unsigned char *registerSlot;
  unsigned char *chainCursor;
  unsigned char *chainNext;
  unsigned char *partnerRecordPtr;
  unsigned char *liveIndexByteB;
  unsigned char *scanPosition;
  unsigned char *liveIndexByte;
  unsigned char *liveListPtr;
  unsigned char *chainNodeLast;
  unsigned char *chainNode;
  unsigned char *recordCursorB;
  unsigned char *recordCursor;
  int status;
  int nodeRecordIndex;
  int recordOffset4;
  int retiredRecord;
  int allocPlus30000;
  code *word3Ptr;
  uint *depNode;
  undefined4 *dependencyNodeB;
  undefined4 *bindingEntryPtr;
  unsigned char *emitRecord;
  int recordFlagOffset;
  int *dependencyNode;
  uint *recordPtr;
  uint outRecordCount;
  uint componentIndex;
  uint sourceSelectMask;
  code *combinedRecord;
  code *recordA;
  int *bindingListSlot;
  int outRecordPtrB;
  undefined4 outWord3;
  undefined4 bindingChainLink;
  undefined4 componentMask;
  undefined4 bindingValue;
  byte sourceFileIs1B;
  byte hasFile1SourceFirstB;
  byte hasFile1SourceSecond;
  int *newChainNode;
  bool destIsFile8;
  bool moreSourceSlots;
  uint opcodeFlagBit;
  uint opcodeBits;
  uint destModeBits;
  uint srcBit14;
  uint srcFileBit4;
  uint srcFileBits;
  uint srcIndexBits;
  uint lastFile1SourceSlot;
  uint recordFlagsOld;
  uint configFlagsB;
  uint sourceSlot;
  uint recordWord0;
  uint writeMask;
  uint opcodeSourceMask;
  uint configBit6;
  uint lastFile8Slot;
  uint dependentRecordIndex;
  uint srcIndexField;
  uint configFlags;
  int config;
  int retiredSlotPtr;
  uint *maxRegisterOut;
  uint *outRecordPtr;
  bool hasLiveRecords;
  unsigned char opcodeByte;
  uint srcTopBits;
  uint loopCounterE;
  uint word3Before;
  uint word3BeforeB;
  uint outWord1B;
  undefined4 *newBindingNode;
  int *bindingChainHead;
  byte sourceFileIs1;
  byte hasFile1SourceFirst;
  undefined4 extraout_r4;
  undefined4 extraout_r4_00;
  undefined4 extraout_r4_01;
  undefined4 extraout_r4_02;
  undefined4 outWord2;
  int opcodeInfoOffset;
  int *dependencyListHead;
  code *configBit6Arg;
  uint *bestRecordSlot;
  uint outWord2B;
  undefined4 outWord1;
  uint *configPtr;
  int allocPlus38;
  code *records;
  uint recordFlagsBefore;
  uint *recordSlotPtr;
  int *dependencyListCursor;
  char emitToSecondList;
  undefined4 uVar26;
  int iVar27;
  int recordCount;
  uint srcBit13;
  bool bVar31;
  int iVar30;
  int *lastChainNode;
  uint componentLoopB;
  uint componentLoop;
  uint *configPtrB;
  int *chainSource;
  code *lastChainNodeB;
  int secondListOffset;
  unsigned char *recordPtrB;
  undefined4 *bestRecordCursor;
  unsigned char *partnerRecord;
  undefined8 statusAndValue;
  char pickedNeedsRetarget [4];
  undefined4 pickedRegister;
  char recordAFileCount0;
  char recordAFileCount1;
  char recordAFileCount2;
  char recordAFileCount3;
  char recordBFileCount0;
  char recordBFileCount1;
  char recordBFileCount2;
  char recordBFileCount3;
  undefined1 local_a8 [12];
  uint local_9c [5];
  uint liveCountSnapshot;
  int partnerIndex;
  int combinedPairCount;
  uint emitLoopIndex;
  uint destRegisterCount;
  uint lastOutputSlot;
  int secondListCount;
  code *local_6c;
  uint local_68;
  uint local_64;
  unsigned char *local_60;
  
  allocPlus38 = alloc + 0x38;
  local_64 = 0xe;
  configPtr = *(uint **)(alloc + 0x34);
  configFlags = *configPtr;
  configBit6 = configFlags >> 6 & 1;
  if (configBit6 == 0) {
    local_64 = 0xc;
  }
  recordCount = *(int *)(alloc + 0x2286c);
  records = (code *)(alloc + 0x1286c);
  if (((configBit6 != 0) && ((configFlags & 0x400) != 0)) && (recordCount != 0)) {
    dependencyListCursor = (int *)(alloc + 0xc450);
    loopIndex = 0;
    flagOffset = 0;
    do {
      recordPtrB = records + loopIndex * 0x10;
      scratchArg3 = recordPtrB;
      ((int (*)())recordCountSourceRegisterFiles)(alloc,flagOffset + alloc + 0x3148c,recordPtrB);
      if (((byte)recordPtrB[3] & 0x40) == 0) {
        recordFlagsBase = alloc + 0x3348c;
        recordFlagsBefore = *(uint *)(flagOffset + recordFlagsBase);
        *(uint *)(flagOffset + recordFlagsBase) = recordFlagsBefore | 0x10;
        opcodeSourceMask = ((int (*)())recordOpcodeSourceMask)(recordPtrB,1);
        if ((opcodeSourceMask & 4) == 0) {
          *(uint *)(flagOffset + recordFlagsBase) = recordFlagsBefore | 0x30;
        }
      }
      else {
        recordFlagsBase = alloc + 0x3348c;
        recordFlagsBefore = *(uint *)(flagOffset + recordFlagsBase);
        *(uint *)(flagOffset + recordFlagsBase) = recordFlagsBefore | 1;
        writeMask = ((int (*)())recordGetWriteMask)(recordPtrB);
        if ((((((writeMask - 1 & writeMask) == 0) &&
              (opcodeInfoOffset = ((byte)recordPtrB[3] & 0xffffffbf) * 0x14,
              *(int *)(&DAT_001aa5f0 + opcodeInfoOffset) != 0)) &&
             (((DAT_001aa600)[opcodeInfoOffset] == '\0' || ((configFlags >> 0xd & 1) != 0)))) &&
            (((*(uint *)(records + loopIndex * 0x10) & 0xf00) != 0x200 &&
             ((*(uint *)(records + loopIndex * 0x10) & 0xf00) != 0x300)))) &&
           ((*(int *)(&DAT_001aa5f4 + opcodeInfoOffset) == 1 ||
            ((*(int *)(&DAT_001aa5f4 + opcodeInfoOffset) == 2 &&
             (scratchArg6 = recordPtrB + 4,
             (*(uint *)(scratchArg6 + *(int *)(&DAT_001aa5f8 + opcodeInfoOffset) * 4) & 0x60001fff) ==
             (*(uint *)(scratchArg6 + *(int *)(&DAT_001aa5fc + opcodeInfoOffset) * 4) & 0x60001fff))))))) {
          *(uint *)(flagOffset + recordFlagsBase) = recordFlagsBefore | 3;
          dependencyListHead = (int *)*dependencyListCursor;
          *(uint *)(flagOffset + recordFlagsBase) = recordFlagsBefore | 0x1003;
          for (; dependencyListHead != (int *)0x0; dependencyListHead = (int *)dependencyListHead[4]) {
            *(uint *)(recordFlagsBase + *dependencyListHead * 4) = *(uint *)(recordFlagsBase + *dependencyListHead * 4) | 0x1000;
          }
        }
      }
      loopIndex = loopIndex + 1;
      flagOffset = flagOffset + 4;
      dependencyListCursor = dependencyListCursor + 1;
    } while (recordCount != loopIndex);
    configFlags = *configPtr;
  }
  configBit6Arg = (code *)(configFlags >> 6 & 1);
  recordCursor = records;
  if ((configFlags & 2) != 0) {
    for (; recordCount != 0; recordCount = recordCount + -1) {
      if (recordCursor[3] == (code *)0x4) {
        recordCursor[3] = (code *)0x80;
      }
      else if ((configBit6Arg != (code *)0x0) && (recordCursor[3] == (code *)0xb)) {
        recordCursor[3] = (code *)0x81;
      }
      recordCursor = recordCursor + 0x10;
    }
  }
  chainNode = *(code **)(alloc + 0x10450);
  if (*(code **)(alloc + 0x10450) != (code *)0x0) {
    do {
      chainNext = chainNode + 0x10;
      lastChainNodeB = chainNode;
      chainNode = *(code **)chainNext;
    } while (*(code **)chainNext != (code *)0x0);
    while( true ) {
      chainNodeLast = lastChainNodeB;
      scratchArg3 = (code *)0x0;
      ((int (*)())recordCollectDependencies)(alloc,*(undefined4 *)chainNodeLast,0,scratchArg4,scratchArg5,scratchArg6,configBit6Arg);
      configBit6Arg = *(code **)(alloc + 0x10450);
      if ((configBit6Arg == (code *)0x0) || (chainNodeLast == configBit6Arg)) break;
      lastChainNodeB = configBit6Arg;
      for (chainCursor = *(code **)(configBit6Arg + 0x10); chainNodeLast != chainCursor;
          chainCursor = *(code **)(chainCursor + 0x10)) {
        if (chainCursor == (code *)0x0) goto LAB_0007b378;
        lastChainNodeB = chainCursor;
      }
    }
  }
LAB_0007b378:
  liveCountSnapshot = *(uint *)(alloc + 0x26870);
  hasLiveRecords = liveCountSnapshot != 0;
  if (hasLiveRecords) {
    liveListPtr = 0x00024870 + alloc;
    loopCounterE = 0;
    do {
      recordCount = *(int *)liveListPtr;
      for (dependencyNode = *(int **)(recordCount * 4 + allocPlus38 + 0xa418); dependencyNode != (int *)0x0;
          dependencyNode = (int *)dependencyNode[4]) {
        if ((*(uint *)(*dependencyNode * 4 + alloc + 0x3348c) & 0x10000) == 0) {
          ((int (*)())depListRemove)(alloc + 0xa450 + recordCount * 4,dependencyNode);
          recordCount = *(int *)liveListPtr;
        }
      }
      for (dependencyNode = *(int **)(recordCount * 4 + allocPlus38 + 0xc418); dependencyNode != (int *)0x0;
          dependencyNode = (int *)dependencyNode[4]) {
        if ((*(uint *)(*dependencyNode * 4 + alloc + 0x3348c) & 0x10000) == 0) {
          ((int (*)())depListRemove)(alloc + 0xc450 + recordCount * 4,dependencyNode);
          recordCount = *(int *)liveListPtr;
        }
      }
      for (dependencyNode = *(int **)(recordCount * 4 + allocPlus38 + 0xe418); dependencyNode != (int *)0x0;
          dependencyNode = (int *)dependencyNode[4]) {
        if ((*(uint *)(*dependencyNode * 4 + alloc + 0x3348c) & 0x10000) == 0) {
          ((int (*)())depListRemove)(alloc + 0xe450 + *(int *)liveListPtr * 4,dependencyNode);
        }
      }
      loopCounterE = loopCounterE + 1;
      liveListPtr = liveListPtr + 4;
    } while (loopCounterE < *(uint *)(alloc + 0x26870));
  }
  if ((((**(uint **)(alloc + 0x34) & 0x40) != 0) && (hasLiveRecords)) &&
     (recordCount = liveCountSnapshot - 1, recordCount != 0)) {
    loopIndex = 0;
    recordPtrB = records + recordCount * 0x10;
    recordSlotPtr = (uint *)(recordCount * 4 + alloc + 0x6450);
    do {
      configBit6Arg = (code *)(recordCount - loopIndex);
      local_6c = configBit6Arg;
      if ((recordSlotPtr[0xb40f] & 0x10000) != 0) {
        recordWord0 = *(uint *)recordPtrB;
        local_68 = *recordSlotPtr;
        if ((recordWord0 & 0xf00) == 0x500) {
          configBit6Arg = (code *)(recordWord0 >> 0xd & 0x7f);
          registerSlot = configBit6Arg + (char)(DAT_001aa758)[recordWord0 >> 8 & 0xf] * 0x100;
          if ((recordWord0 & 0x100000) != 0) {
            scratchArg3 = (code *)0x0;
            ((int (*)())regBindingClear)(alloc,registerSlot,0);
            recordWord0 = *(uint *)recordPtrB;
          }
          if ((recordWord0 & 0x200000) != 0) {
            scratchArg3 = (code *)((int)((unsigned char *)0x0) + 1);
            ((int (*)())regBindingClear)(alloc,registerSlot,1);
            recordWord0 = *(uint *)recordPtrB;
          }
          if ((recordWord0 & 0x400000) != 0) {
            scratchArg3 = (code *)((int)((unsigned char *)0x0) + 2);
            ((int (*)())regBindingClear)(alloc,registerSlot,2);
            recordWord0 = *(uint *)recordPtrB;
          }
          if ((recordWord0 & 0x800000) != 0) {
            scratchArg3 = (code *)((int)((unsigned char *)0x0) + 3);
            ((int (*)())regBindingClear)(alloc,registerSlot,3);
          }
        }
        sourceSlot = 0;
        sourceWordPtr = recordPtrB;
        do {
          sourceWordPtr = sourceWordPtr + 4;
          if ((local_68 & 1 << (sourceSlot & 0x3f)) != 0) {
            scratchArg6 = *(code **)sourceWordPtr;
            scratchArg5 = (int *)((uint)scratchArg6 & 0xf);
            if (scratchArg5 == (int *)((int)((unsigned char *)0x0) + 1U)) {
              componentLoop = 0;
              srcIndexField = (uint)scratchArg6 >> 0xd;
              configBit6Arg = (code *)(1 << ((uint)scratchArg6 >> 0x10 & 7));
              sourceSelectMask = 1 << ((uint)scratchArg6 >> 0x16 & 7) | 1 << ((uint)scratchArg6 >> 0x13 & 7) |
                       (uint)configBit6Arg;
              srcRegisterIndex = DAT_001aa761 * 0x100 + ((uint)scratchArg6 >> 5 & 0xff);
              local_60 = (code *)(srcRegisterIndex + alloc + 0x30870);
              bindingEntryPtr = (undefined4 *)(srcRegisterIndex * 0x10 + alloc + 0x2a87c);
              do {
                componentBit = 1 << (componentLoop & 0x3f);
                if (((sourceSelectMask | 1 << (srcIndexField & 7)) & componentBit) != 0) {
                  bindingValue = *bindingEntryPtr;
                  newBindingNode = (undefined4 *)((int (*)())chunkArenaAlloc)(alloc + 0x12454,8);
                  if (newBindingNode != (undefined4 *)0x0) {
                    newBindingNode[1] = bindingValue;
                    *newBindingNode = local_6c;
                    *bindingEntryPtr = newBindingNode;
                    bindingEntryPtr[0xc00] = 0xffffffff;
                    local_60[0xc] = (code *)((byte)componentBit | (byte)local_60[0xc]);
                    configBit6Arg = local_60;
                  }
                }
                moreComponentsB = componentLoop != 3;
                bindingEntryPtr = bindingEntryPtr + 1;
                componentLoop = componentLoop + 1;
              } while (moreComponentsB);
            }
          }
          moreSlots = sourceSlot != 2;
          sourceSlot = sourceSlot + 1;
        } while (moreSlots);
      }
      loopIndex = loopIndex + 1;
      recordPtrB = recordPtrB + -0x10;
      recordSlotPtr = recordSlotPtr + -1;
    } while (loopIndex != recordCount);
  }
  liveIndexByte = (code *)0x0;
  ((int (*)())recordClearBindingTables)(alloc);
  liveListPtrB = 0x00024870 + alloc;
  uVar26 = extraout_r4;
  while (liveIndexByte < *(code **)(alloc + 0x26870)) {
    scratchArg4 = (code *)(**(uint **)(alloc + 0x34) >> 6 & 1);
    scratchArg3 = liveIndexByte;
    statusAndValue = ((int (*)())recordIsSchedulable)(alloc,records,liveIndexByte,scratchArg4);
    uVar26 = (undefined4)statusAndValue;
    if ((int)((ulonglong)statusAndValue >> 0x20) == 0) {
      liveIndexByte = liveIndexByte + 1;
      liveListPtrB = liveListPtrB + 4;
    }
    else {
      retiredRecord = *(int *)liveListPtrB;
      scratchArg3 = 0x00024870 + alloc;
      configBit6Arg = (code *)(*(int *)(alloc + 0x28874) + 1);
      retiredSlotPtr = *(int *)(alloc + 0x28874) * 4 + alloc;
      *(code **)(alloc + 0x28874) = configBit6Arg;
      *(int *)(retiredSlotPtr + 0x26874) = retiredRecord;
      *(undefined4 *)(retiredSlotPtr + 0x22870) = 0;
      recordCount = retiredRecord * 4 + alloc;
      ((int (*)())arrayRemoveAt)(liveIndexByte,alloc + 0x26870,scratchArg3);
      *(uint *)(recordCount + 0x3348c) = *(uint *)(recordCount + 0x3348c) & 0xfffeffff | 0x20000;
      uVar26 = extraout_r4_00;
    }
  }
  while (*(uint *)(alloc + 0x2a878) < liveCountSnapshot) {
    if (*(int *)(alloc + 0x28874) == 0) {
      return 2;
    }
    scratchArg6 = records;
    recordCount = ((int (*)())recordPickNextToEmit)(alloc,local_64,9,pickedNeedsRetarget,&pickedRegister,records,*configPtr,*configPtr >> 6 & 1);
    if (recordCount < 0) {
      configFlagsB = **(uint **)(alloc + 0x34);
      bVar31 = true;
      while ((configFlagsB = configFlagsB >> 6 & 1, configFlagsB != 0 && (local_64 < 0x20))) {
        if (local_64 == 0x12) {
          local_64 = 0x18;
        }
        else if (local_64 == 0x18) {
          local_64 = 0x20;
        }
        else if (local_64 == 0xe) {
          local_64 = 0x12;
        }
        scratchArg6 = records;
        recordCount = ((int (*)())recordPickNextToEmit)(alloc,local_64,9,pickedNeedsRetarget,&pickedRegister,records,*configPtr,configFlagsB);
        bVar31 = recordCount < 0;
        if (!bVar31) goto LAB_0007b894;
        configFlagsB = **(uint **)(alloc + 0x34);
      }
      if (bVar31) {
        return 3;
      }
    }
LAB_0007b894:
    loopIndex = 0;
    scratchArg3 = (code *)local_a8;
    recordPtrB = records + recordCount * 0x10;
    recordPtr = (uint *)(alloc + 0x1286c + recordCount * 0x10);
    do {
      recordPtrB = recordPtrB + 4;
      moreWords = loopIndex != 8;
      *(code **)(scratchArg3 + loopIndex) = recordPtrB;
      loopIndex = loopIndex + 4;
    } while (moreWords);
    if (pickedNeedsRetarget[0] == '\0') {
      configPtrB = *(uint **)(alloc + 0x34);
    }
    else {
      configPtrB = *(uint **)(alloc + 0x34);
      configBit6 = *configPtrB >> 6 & 1;
      iVar27 = ((int (*)())recordDestFileIs0Or45)(recordPtr,configBit6);
      if (iVar27 == 0) {
        iVar27 = ((int (*)())recordDestFileIs3Or1)(recordPtr,configBit6);
        if (iVar27 != 0) {
          ((int (*)())recordRemapComponents)(alloc,recordCount,pickedRegister);
          configPtrB = *(uint **)(alloc + 0x34);
        }
      }
      else {
        ((int (*)())recordRetargetDestination)(alloc,recordCount,pickedRegister);
        configPtrB = *(uint **)(alloc + 0x34);
      }
    }
    scratchArg5 = (int *)(*configPtrB >> 6 & 1);
    scratchArg4 = records;
    status = ((int (*)())recordRetireBindings)(alloc,recordCount,scratchArg3,records,scratchArg5);
    if (status != 0) {
      return status;
    }
    iVar27 = ((int (*)())recordDestFileIs0Or45)(recordPtr,**(uint **)(alloc + 0x34) >> 6 & 1);
    if (iVar27 == 0) {
      recordOffset4 = recordCount * 4;
      recordIsFixed = ((int (*)())recordDestFileIs3Or1)(recordPtr,*configPtr >> 6 & 1);
      if (recordIsFixed != 0) {
        scratchArg3 = (code *)((int (*)())recordGetWriteMask)(recordPtr);
        scratchArg4 = (code *)((int)((unsigned char *)0x0) + 1);
        calleeStatus = ((int (*)())regBindingSetFixedRegister)(alloc,recordCount,scratchArg3,1,scratchArg5);
        if (calleeStatus != 0) {
          return calleeStatus;
        }
        for (dependencyNodeB = *(undefined4 **)(recordOffset4 + allocPlus38 + 0xc418); dependencyNodeB != (undefined4 *)0x0;
            dependencyNodeB = (undefined4 *)dependencyNodeB[4]) {
          scratchArg3 = (code *)dependencyNodeB[1];
          scratchArg4 = (code *)((int)((unsigned char *)0x0) + 1);
          calleeStatus = ((int (*)())regBindingSetFixedRegister)(alloc,*dependencyNodeB,scratchArg3,1,scratchArg5);
          if (calleeStatus != 0) {
            return calleeStatus;
          }
        }
        for (dependencyNodeB = *(undefined4 **)(recordOffset4 + allocPlus38 + 0xe418); dependencyNodeB != (undefined4 *)0x0;
            dependencyNodeB = (undefined4 *)dependencyNodeB[4]) {
          scratchArg3 = (code *)dependencyNodeB[1];
          scratchArg4 = (code *)((int)((unsigned char *)0x0) + 1);
          ((int (*)())regBindingSetFixedRegister)(alloc,*dependencyNodeB,scratchArg3,1,scratchArg5);
        }
        bindingListSlot = (int *)(alloc + 0x30b7c);
        componentCounter = 0;
        dependencyNode = *(int **)(recordOffset4 + allocPlus38 + 0xa418);
        do {
          if (dependencyNode != (int *)0x0) {
            haveChainHead = false;
            chainSource = dependencyNode;
            do {
              if ((1 << (componentCounter & 0x3f) & chainSource[1]) != 0) {
                if (haveChainHead) {
                  bindingChainHead = (int *)*bindingListSlot;
                  do {
                    lastChainNode = bindingChainHead;
                    if (*lastChainNode == *chainSource) goto LAB_0007bdf0;
                    bindingChainHead = (int *)lastChainNode[1];
                  } while ((int *)lastChainNode[1] != (int *)0x0);
                  newChainNode = (int *)((int (*)())chunkArenaAlloc)(alloc + 0x12454,8);
                  lastChainNode[1] = (int)newChainNode;
                  if (newChainNode == (int *)0x0) {
                    return 7;
                  }
                  nodeRecordIndex = *chainSource;
                  newChainNode[1] = 0;
                  *newChainNode = nodeRecordIndex;
                }
                else {
                  if (*bindingListSlot != 0) {
                    return 6;
                  }
                  newChainNode = (int *)((int (*)())chunkArenaAlloc)(alloc + 0x12454,8);
                  *bindingListSlot = (int)newChainNode;
                  if (newChainNode == (int *)0x0) {
                    return 7;
                  }
                  *newChainNode = *chainSource;
                  *(undefined4 *)(*bindingListSlot + 4) = 0;
                  haveChainHead = true;
                }
              }
LAB_0007bdf0:
              chainSource = (int *)chainSource[4];
            } while (chainSource != (int *)0x0);
          }
          moreComponents = componentCounter != 3;
          bindingListSlot = bindingListSlot + 1;
          componentCounter = componentCounter + 1;
        } while (moreComponents);
      }
    }
    else {
      scratchArg3 = (code *)((char)(DAT_001aa758)[*recordPtr >> 8 & 0xf] * 0x100 +
                        (*recordPtr >> 0xd & 0x7f));
      componentMask = ((int (*)())recordGetWriteMask)(recordPtr);
      scratchArg5 = (int *)((int)((unsigned char *)0x0) + 1);
      status = ((int (*)())regBindingSet)(alloc,recordCount,scratchArg3,componentMask,1);
      if (status != 0) {
        return status;
      }
      recordOffset4 = recordCount * 4;
      componentsSeen = 0;
      for (depNode = *(uint **)(recordOffset4 + allocPlus38 + 0xc418); depNode != (uint *)0x0;
          depNode = (uint *)depNode[4]) {
        dependentRecordIndex = *depNode;
        if ((*(uint *)(dependentRecordIndex * 4 + alloc + 0x3348c) & 0x40000) == 0) {
          writeMaskB = ((int (*)())recordGetWriteMask)(alloc + 0x1286c + dependentRecordIndex * 0x10);
          componentIndex = 0;
          bestRecordSlot = (uint *)(local_a8 + 0xc);
          componentsLeft = 4;
          do {
            componentBit = 1 << (componentIndex & 0x3f);
            if ((writeMaskB & componentBit) != 0) {
              if ((componentBit & componentsSeen) == 0) {
                *bestRecordSlot = dependentRecordIndex;
                componentsSeen = componentsSeen | componentBit;
              }
              else if (dependentRecordIndex < *bestRecordSlot) {
                *bestRecordSlot = dependentRecordIndex;
              }
            }
            componentIndex = componentIndex + 1;
            bestRecordSlot = bestRecordSlot + 1;
            componentsLeft = componentsLeft + -1;
          } while (componentsLeft != 0);
        }
      }
      componentLoopB = 0;
      bestRecordCursor = (undefined4 *)(local_a8 + 0xc);
      do {
        scratchArg4 = (code *)(1 << (componentLoopB & 0x3f));
        if ((componentsSeen & (uint)scratchArg4) != 0) {
          scratchArg5 = (int *)0x0;
          scratchArg3 = (code *)((char)(DAT_001aa758)[*recordPtr >> 8 & 0xf] * 0x100 +
                            (*recordPtr >> 0xd & 0x7f));
          calleeStatus = ((int (*)())regBindingSet)(alloc,*bestRecordCursor,scratchArg3,scratchArg4,0);
          if (calleeStatus != 0) {
            return calleeStatus;
          }
        }
        moreComponents = componentLoopB != 3;
        bestRecordCursor = bestRecordCursor + 1;
        componentLoopB = componentLoopB + 1;
      } while (moreComponents);
      for (dependencyNodeB = *(undefined4 **)(recordOffset4 + allocPlus38 + 0xe418); dependencyNodeB != (undefined4 *)0x0;
          dependencyNodeB = (undefined4 *)dependencyNodeB[4]) {
        scratchArg5 = (int *)0x0;
        scratchArg4 = (code *)dependencyNodeB[1];
        scratchArg3 = (code *)((char)(DAT_001aa758)[*recordPtr >> 8 & 0xf] * 0x100 +
                          (*recordPtr >> 0xd & 0x7f));
        ((int (*)())regBindingSet)(alloc,*dependencyNodeB,scratchArg3,scratchArg4,0);
      }
      componentCounter = 0;
      dependencyNode = *(int **)(recordOffset4 + allocPlus38 + 0xa418);
      bindingListSlot = (int *)(((char)(DAT_001aa758)[*recordPtr >> 8 & 0xf] * 0x100 +
                        (*recordPtr >> 0xd & 0x7f)) * 0x10 + alloc + 0x2a87c);
      do {
        if (dependencyNode != (int *)0x0) {
          haveChainHead = false;
          chainSource = dependencyNode;
          do {
            if ((1 << (componentCounter & 0x3f) & chainSource[1]) != 0) {
              if (haveChainHead) {
                bindingChainHead = (int *)*bindingListSlot;
                do {
                  lastChainNode = bindingChainHead;
                  if (*lastChainNode == *chainSource) goto LAB_0007bc50;
                  bindingChainHead = (int *)lastChainNode[1];
                } while ((int *)lastChainNode[1] != (int *)0x0);
                newChainNode = (int *)((int (*)())chunkArenaAlloc)(alloc + 0x12454,8);
                lastChainNode[1] = (int)newChainNode;
                if (newChainNode == (int *)0x0) {
                  return 7;
                }
                nodeRecordIndex = *chainSource;
                newChainNode[1] = 0;
                *newChainNode = nodeRecordIndex;
              }
              else {
                if (*bindingListSlot != 0) {
                  return 6;
                }
                newChainNode = (int *)((int (*)())chunkArenaAlloc)(alloc + 0x12454,8);
                *bindingListSlot = (int)newChainNode;
                if (newChainNode == (int *)0x0) {
                  return 7;
                }
                *newChainNode = *chainSource;
                *(undefined4 *)(*bindingListSlot + 4) = 0;
                haveChainHead = true;
              }
            }
LAB_0007bc50:
            chainSource = (int *)chainSource[4];
          } while (chainSource != (int *)0x0);
        }
        moreComponents = componentCounter != 3;
        bindingListSlot = bindingListSlot + 1;
        componentCounter = componentCounter + 1;
      } while (moreComponents);
    }
    iVar27 = recordCount * 4 + alloc;
    emittedCount = *(int *)(alloc + 0x2a878);
    retiredCountSnapshot = *(int *)(alloc + 0x28874);
    configBit6Arg = (code *)(iVar27 + 0x30000);
    recordFlagsOld = *(uint *)(iVar27 + 0x3348c);
    *(int *)(alloc + 0x2a878) = emittedCount + 1;
    *(int *)(emittedCount * 4 + alloc + 0x28878) = recordCount;
    *(uint *)(iVar27 + 0x3348c) = recordFlagsOld & 0xfffdffff | 0x40000;
    scanPosition = (code *)0x0;
    if (retiredCountSnapshot != 0) {
      scratchArg5 = (int *)(alloc + 0x26874);
      scratchArg3 = (code *)0x0;
      loopIndex = 1;
      retiredIndexOffset = 0x22874;
      do {
        if ((recordCount == *scratchArg5) && (scratchArg3 < (code *)(*(int *)(alloc + 0x28874) + -1))) {
          retiredMoveCursor = (undefined4 *)(alloc + retiredIndexOffset);
          scratchArg4 = (code *)((int)scratchArg3 * 4);
          scratchArg6 = scratchArg3;
          do {
            retiredCount = *(int *)(alloc + 0x28874);
            scratchArg6 = scratchArg6 + 1;
            configBit6Arg = scratchArg4 + loopIndex * -4;
            bindingChainLink = retiredMoveCursor[0x1001];
            *(undefined4 *)((int)retiredMoveCursor + (int)configBit6Arg) = *retiredMoveCursor;
            retiredMoveCursor[0x1000] = bindingChainLink;
            retiredMoveCursor = retiredMoveCursor + 1;
          } while (scratchArg6 < (code *)(retiredCount + -1));
        }
        scanPosition = *(code **)(alloc + 0x28874);
        scratchArg3 = scratchArg3 + 1;
        loopIndex = loopIndex + 1;
        retiredIndexOffset = retiredIndexOffset + 4;
        scratchArg5 = scratchArg5 + 1;
      } while (scratchArg3 < scanPosition);
    }
    *(code **)(alloc + 0x28874) = scanPosition + -1;
    if ((*(int *)(alloc + 0x35490) != 3) && (scanPosition + -1 != (code *)0x0)) {
      configBit6Arg = (code *)(alloc + 0x22870);
      retiredScanIndex = 0;
      do {
        if (*(int *)configBit6Arg != 0) {
          *(int *)configBit6Arg = *(int *)configBit6Arg + -1;
        }
        retiredScanIndex = retiredScanIndex + 1;
        configBit6Arg = configBit6Arg + 4;
      } while (retiredScanIndex < *(uint *)(alloc + 0x28874));
    }
    liveIndexByteB = (code *)0x0;
    ((int (*)())recordClearBindingTables)(alloc);
    liveListPtrB = 0x00024870 + alloc;
    uVar26 = extraout_r4_01;
    while (liveIndexByteB < *(code **)(alloc + 0x26870)) {
      scratchArg4 = (code *)(**(uint **)(alloc + 0x34) >> 6 & 1);
      scratchArg3 = liveIndexByteB;
      statusAndValue = ((int (*)())recordIsSchedulable)(alloc,records,liveIndexByteB,scratchArg4);
      uVar26 = (undefined4)statusAndValue;
      if ((int)((ulonglong)statusAndValue >> 0x20) == 0) {
        liveIndexByteB = liveIndexByteB + 1;
        liveListPtrB = liveListPtrB + 4;
      }
      else {
        retiredRecord = *(int *)liveListPtrB;
        scratchArg3 = 0x00024870 + alloc;
        configBit6Arg = (code *)(*(int *)(alloc + 0x28874) + 1);
        retiredSlotPtr = *(int *)(alloc + 0x28874) * 4 + alloc;
        *(code **)(alloc + 0x28874) = configBit6Arg;
        *(int *)(retiredSlotPtr + 0x26874) = retiredRecord;
        *(undefined4 *)(retiredSlotPtr + 0x22870) = 9;
        recordCount = retiredRecord * 4 + alloc;
        ((int (*)())arrayRemoveAt)(liveIndexByteB,alloc + 0x26870,scratchArg3);
        *(uint *)(recordCount + 0x3348c) = *(uint *)(recordCount + 0x3348c) & 0xfffeffff | 0x20000;
        uVar26 = extraout_r4_02;
      }
    }
    if ((*configPtr & 0x10) != 0) {
      statusAndValue = ((int (*)())recordFindScheduleConflict)(alloc,0);
      recordCount = (int)((ulonglong)statusAndValue >> 0x20);
      uVar26 = (undefined4)statusAndValue;
      if (recordCount != 0) {
        return recordCount;
      }
    }
  }
  configFlagsB = **(uint **)(alloc + 0x34);
  if (hasLiveRecords) {
    opcodeRewriteIndex = 0;
    recordCursorB = records;
    do {
      statusAndValue = ((int (*)())recordSourcesAreDistinctTemps)(recordCursorB,uVar26,scratchArg3,scratchArg4,scratchArg5,scratchArg6,configBit6Arg);
      uVar26 = (undefined4)statusAndValue;
      if ((int)((ulonglong)statusAndValue >> 0x20) != 0) {
        if (recordCursorB[3] == (code *)0x4) {
          recordCursorB[3] = (code *)0x80;
        }
        else if (((configFlagsB >> 6 & 1) != 0) && (recordCursorB[3] == (code *)0xb)) {
          recordCursorB[3] = (code *)0x81;
        }
      }
      opcodeRewriteIndex = opcodeRewriteIndex + 1;
      recordCursorB = recordCursorB + 0x10;
    } while (liveCountSnapshot != opcodeRewriteIndex);
  }
  if (((*configPtr & 0x20) != 0) && (recordCount = ((int (*)())recordFindScheduleConflict)(alloc,1), recordCount != 0)) {
    return recordCount;
  }
  config = *(int *)(alloc + 0x34);
  if (*(int *)(alloc + 0x2a878) == 0) {
    outRecordCount = 0;
    lastFile1SourceSlot = 0;
    lastFile8Slot = 0;
    secondListCount = 0;
    lastOutputSlot = 0;
    destRegisterCount = 0;
    combinedPairCount = 0;
  }
  else {
    lastFile1SourceSlot = 0;
    emitLoopIndex = 0;
    secondListCount = 0;
    lastFile8Slot = 0;
    outRecordCount = 0;
    lastOutputSlot = 0;
    destRegisterCount = 0;
    combinedPairCount = 0;
    allocPlus30000 = alloc + 0x30000;
    do {
      recordFlagOffset = *(int *)(allocPlus30000 + -0x7788) * 4;
      outRecordPtr = (uint *)(outRecordCount * 0x10 + *(int *)(config + 0x18));
      emitRecord = records + *(int *)(allocPlus30000 + -0x7788) * 0x10;
      if ((*(uint *)(recordFlagOffset + alloc + 0x3348c) & 0x100) == 0) {
LAB_0007c4b0:
        hasFile1SourceFirst = 0;
        sourceUsedMask = *(uint *)(recordFlagOffset + allocPlus38 + 0x6418);
        sourceLoop = 0;
        emitToSecondList = *(char *)(recordFlagOffset + allocPlus38 + 0x841b);
        recordA = emitRecord;
        do {
          recordA = recordA + 4;
          if ((sourceUsedMask & 1 << (sourceLoop & 0x3f)) != 0) {
            sourceFileIs1 = ((int (*)())recordSourceFileIs1)(recordA);
            hasFile1SourceFirst = sourceFileIs1 | hasFile1SourceFirst;
          }
          moreSourceSlots = sourceLoop != 2;
          sourceLoop = sourceLoop + 1;
        } while (moreSourceSlots);
      }
      else {
        partnerIndex = *(int *)(allocPlus30000 + -0x7784);
        combinedRecord = records + partnerIndex * 0x10;
        partnerRecord = emitRecord;
        if (((byte)emitRecord[3] & 0x40) == 0) {
          combinedRecord = emitRecord;
          partnerRecord = records + partnerIndex * 0x10;
        }
        opcodeByte = partnerRecord[3];
        secondRecordWord0 = *(uint *)partnerRecord;
        *(undefined4 *)(combinedRecord + 0xc) = 0;
        word3Ptr = combinedRecord + 0xc;
        secondRecordWord0 = secondRecordWord0 >> 0x14 & 0xf;
        ((int (*)())recordCountSourceRegisterFiles)(alloc,&recordAFileCount0,combinedRecord);
        ((int (*)())recordCountSourceRegisterFiles)(alloc,&recordBFileCount0,partnerRecord);
        if ((((2 < (int)recordAFileCount0 + (int)recordBFileCount0) || (1 < (int)recordAFileCount1 + (int)recordBFileCount1)) ||
            (1 < (int)recordAFileCount2 + (int)recordBFileCount2)) ||
           ((1 < (int)recordAFileCount3 + (int)recordBFileCount3 || ((*(uint *)combinedRecord & 0xf00) == 0x400))))
        goto LAB_0007c4b0;
        word3Before = *(uint *)(combinedRecord + 0xc);
        destModeBits = (*(uint *)partnerRecord & 0x6000) << 6;
        *(uint *)(combinedRecord + 0xc) = destModeBits | word3Before & 0xffe7ffff;
        opcodeBits = ((byte)partnerRecord[3] & 0xf) << 0x15;
        *(uint *)(combinedRecord + 0xc) = opcodeBits | destModeBits | word3Before & 0xfe07ffff;
        opcodeFlagBit = (byte)partnerRecord[3] >> 2 & 4;
        *(uint *)(combinedRecord + 0xc) = opcodeFlagBit | opcodeBits | destModeBits | word3Before & 0xfe07fffb;
        if (secondRecordWord0 == 2) {
          *(uint *)(combinedRecord + 0xc) = opcodeFlagBit | opcodeBits | destModeBits | word3Before & 0xe607fffb | 0x8000000;
        }
        else if (secondRecordWord0 < 3) {
          if (secondRecordWord0 == 1) {
            *(uint *)word3Ptr = opcodeFlagBit | opcodeBits | destModeBits | word3Before & 0xe607fffb;
          }
        }
        else if (secondRecordWord0 == 4) {
          *(uint *)(combinedRecord + 0xc) = opcodeFlagBit | opcodeBits | destModeBits | word3Before & 0xe607fffb | 0x10000000;
        }
        else if (secondRecordWord0 == 8) {
          *(uint *)word3Ptr = opcodeFlagBit | opcodeBits | destModeBits | word3Before & 0xe607fffb | 0x18000000;
        }
        opcodeInfoOffsetB = ((byte)opcodeByte & 0x1f) * 0x14;
        sourceOperandIndex = *(uint *)(&DAT_001aa5f8 + opcodeInfoOffsetB);
        if (sourceOperandIndex < 3) {
          word3BeforeB = *(uint *)word3Ptr;
          srcFileBits = *(uint *)(partnerRecord + (sourceOperandIndex + 1) * 4) & 3;
          *(uint *)word3Ptr = srcFileBits | word3BeforeB & 0xfffffffc;
          srcFileBit4 = *(uint *)(partnerRecord + (sourceOperandIndex + 1) * 4) & 0x10;
          *(uint *)word3Ptr = srcFileBit4 | srcFileBits | word3BeforeB & 0xffffffec;
          srcIndexBits = *(uint *)(partnerRecord + (sourceOperandIndex + 1) * 4) & 0x1fe0;
          *(uint *)word3Ptr = srcIndexBits | srcFileBit4 | srcFileBits | word3BeforeB & 0xffffe00c;
          srcTopBits = *(uint *)(partnerRecord + (sourceOperandIndex + 1) * 4) & 0x60000000;
          *(uint *)word3Ptr = srcTopBits | srcIndexBits | srcFileBit4 | srcFileBits | word3BeforeB & 0x9fffe00c;
          srcBit13 = *(uint *)(partnerRecord + (sourceOperandIndex + 1) * 4) >> 3 & 0x2000000;
          *(uint *)word3Ptr = srcBit13 | srcTopBits | srcIndexBits | srcFileBit4 | srcFileBits | word3BeforeB & 0x9dffe00c;
          *(uint *)word3Ptr =
               *(uint *)(partnerRecord + (sourceOperandIndex + 1) * 4) >> 9 & 0xe000 |
               srcBit13 | srcTopBits | srcIndexBits | srcFileBit4 | srcFileBits | word3BeforeB & 0x9dff000c;
        }
        sourceOperandIndex = *(uint *)(&DAT_001aa5fc + opcodeInfoOffsetB);
        if (sourceOperandIndex < 3) {
          word3BeforeB = *(uint *)word3Ptr;
          srcFileBits = *(uint *)(partnerRecord + (sourceOperandIndex + 1) * 4) & 3;
          *(uint *)word3Ptr = srcFileBits | word3BeforeB & 0xfffffffc;
          srcFileBit4 = *(uint *)(partnerRecord + (sourceOperandIndex + 1) * 4) & 0x10;
          *(uint *)word3Ptr = srcFileBit4 | srcFileBits | word3BeforeB & 0xffffffec;
          srcIndexBits = *(uint *)(partnerRecord + (sourceOperandIndex + 1) * 4) & 0x1fe0;
          *(uint *)word3Ptr = srcIndexBits | srcFileBit4 | srcFileBits | word3BeforeB & 0xffffe00c;
          srcTopBits = *(uint *)(partnerRecord + (sourceOperandIndex + 1) * 4) & 0x60000000;
          *(uint *)word3Ptr = srcTopBits | srcIndexBits | srcFileBit4 | srcFileBits | word3BeforeB & 0x9fffe00c;
          srcBit14 = *(uint *)(partnerRecord + (sourceOperandIndex + 1) * 4) >> 2 & 0x4000000;
          *(uint *)word3Ptr = srcBit14 | srcTopBits | srcIndexBits | srcFileBit4 | srcFileBits | word3BeforeB & 0x9bffe00c;
          *(uint *)word3Ptr =
               *(uint *)(partnerRecord + (sourceOperandIndex + 1) * 4) >> 6 & 0x70000 |
               srcBit14 | srcTopBits | srcIndexBits | srcFileBit4 | srcFileBits | word3BeforeB & 0x9bf8e00c;
        }
        *(uint *)combinedRecord = *(uint *)combinedRecord | 0x10000000;
        if ((*(int *)(recordFlagOffset + allocPlus38 + 0x8418) != 0) ||
           (emitToSecondList = '\0', *(int *)(partnerIndex * 4 + allocPlus38 + 0x8418) != 0)) {
          emitToSecondList = '\x01';
        }
        hasFile1SourceFirstB = 0;
        sourceLoop = 0;
        sourceUsedMask = *(uint *)(recordFlagOffset + allocPlus38 + 0x6418);
        do {
          emitRecord = emitRecord + 4;
          if ((sourceUsedMask & 1 << (sourceLoop & 0x3f)) != 0) {
            sourceFileIs1 = ((int (*)())recordSourceFileIs1)(emitRecord);
            hasFile1SourceFirstB = sourceFileIs1 | hasFile1SourceFirstB;
          }
          moreSourceSlots = sourceLoop != 2;
          sourceLoop = sourceLoop + 1;
        } while (moreSourceSlots);
        if (hasFile1SourceFirstB == 0) {
          sourceLoop = 0;
          partnerRecordPtr = records + partnerIndex * 0x10;
          partnerSourceUsedMask = *(uint *)(partnerIndex * 4 + allocPlus38 + 0x6418);
          hasFile1SourceSecond = 0;
          do {
            partnerRecordPtr = partnerRecordPtr + 4;
            if ((partnerSourceUsedMask & 1 << (sourceLoop & 0x3f)) != 0) {
              sourceFileIs1B = ((int (*)())recordSourceFileIs1)(partnerRecordPtr);
              hasFile1SourceSecond = sourceFileIs1B | hasFile1SourceSecond;
            }
            moreSourceSlots = sourceLoop != 2;
            sourceLoop = sourceLoop + 1;
          } while (moreSourceSlots);
          hasFile1SourceFirst = 0;
          if (hasFile1SourceSecond != 0) goto LAB_0007c484;
        }
        else {
LAB_0007c484:
          hasFile1SourceFirst = 1;
        }
        allocPlus30000 = allocPlus30000 + 4;
        combinedPairCount = combinedPairCount + 1;
        emitLoopIndex = emitLoopIndex + 1;
        emitRecord = combinedRecord;
      }
      if ((emitToSecondList != '\0') && (recordFlagOffset = *(int *)(config + 0x20), lastOutputSlot = outRecordCount, recordFlagOffset != 0)) {
        outWord1 = *(undefined4 *)(emitRecord + 4);
        outWord2 = *(undefined4 *)(emitRecord + 8);
        outWord3 = *(undefined4 *)(emitRecord + 0xc);
        secondListOffset = secondListCount * 0x10;
        secondListCount = secondListCount + 1;
        outRecordPtrB = recordFlagOffset + secondListOffset;
        *(undefined4 *)(recordFlagOffset + secondListOffset) = *(undefined4 *)emitRecord;
        *(undefined4 *)(outRecordPtrB + 0xc) = outWord3;
        *(undefined4 *)(outRecordPtrB + 4) = outWord1;
        *(undefined4 *)(outRecordPtrB + 8) = outWord2;
      }
      outWord0 = *(uint *)emitRecord;
      if (((outWord0 & 0xf00) != 0x800) || (destIsFile8 = true, (**(uint **)(alloc + 0x34) >> 6 & 1) != 0)
         ) {
        destIsFile8 = false;
      }
      if (destIsFile8) {
        lastFile8Slot = outRecordCount;
      }
      if (hasFile1SourceFirst != 0) {
        lastFile1SourceSlot = outRecordCount;
      }
      iVar30 = ((int (*)())recordDestFileIs0)(emitRecord);
      if ((iVar30 != 0) && (sourceLoop = (outWord0 >> 0xd & 0x7f) + 1, destRegisterCount < sourceLoop)) {
        destRegisterCount = sourceLoop;
      }
      if (outRecordCount == 0x400) {
        return 10;
      }
      outWord3B = *(uint *)(emitRecord + 0xc);
      outWord1B = *(uint *)(emitRecord + 4);
      outRecordCount = outRecordCount + 1;
      allocPlus30000 = allocPlus30000 + 4;
      outWord2B = *(uint *)(emitRecord + 8);
      *outRecordPtr = outWord0;
      outRecordPtr[3] = outWord3B;
      outRecordPtr[1] = outWord1B;
      outRecordPtr[2] = outWord2B;
      emitLoopIndex = emitLoopIndex + 1;
    } while (emitLoopIndex < *(uint *)(alloc + 0x2a878));
  }
  **(uint **)(config + 0x1c) = outRecordCount;
  maxRegisterOut = *(uint **)(config + 0x28);
  if (maxRegisterOut != (uint *)0x0) {
    if ((**(uint **)(alloc + 0x34) & 0x40) == 0) {
      if (lastOutputSlot < lastFile8Slot) {
        lastOutputSlot = lastFile8Slot;
      }
      *maxRegisterOut = lastOutputSlot;
    }
    else {
      *maxRegisterOut = lastOutputSlot;
    }
  }
  if (*(uint **)(config + 0x2c) != (uint *)0x0) {
    **(uint **)(config + 0x2c) = lastFile1SourceSlot;
  }
  if (*(uint **)(config + 0x30) != (uint *)0x0) {
    **(uint **)(config + 0x30) = destRegisterCount;
  }
  if (*(int *)(config + 0x20) != 0) {
    **(int **)(config + 0x24) = secondListCount;
  }
  *(int *)(alloc + 0x3548c) = combinedPairCount;
  return 0;
}

/* recordProgramBuildDependencies @ 0x7c760 (4940 bytes) */
int recordProgramBuildDependencies(alloc)
  uint *alloc;
{
  int remainingC;
  int loopCounterC;
  int sourceIndexB;
  uint srcFileBit4C;
  uint *dependencyHeadPtr;
  uint *outRecordSrc;
  uint *recordB;
  uint *configFlagsPtr;
  uint *clearPtr;
  uint slotLoopB;
  uint configBit6B;
  uint srcFileDefault;
  uint srcBitsShifted;
  uint outputWordOldB;
  dword *scanFlag;
  int outputOffset;
  uint *records;
  uint *inputRecords;
  int status;
  int recordWordOffset;
  int opcodeInfoOffset;
  int loopCount800;
  int loopCount4;
  dword *arenaB;
  uint usedSourcesMask;
  uint sourceSlot;
  uint srcWord2Old;
  uint srcWord1Old;
  uint swizzleBitsA;
  uint usedBits;
  uint srcOperandIndexB;
  uint srcOperandIndexA;
  uint outputIndexPlus1;
  uint *configFlagsPtrB;
  uint *srcWordPtr0;
  uint *usedMaskAccum;
  uint *recordPtrC;
  dword *recordWriteMask;
  dword *outRecordCopyPtr;
  dword *listPosB;
  uint srcSpecialBit;
  uint srcFileField;
  uint srcFileBitsC;
  uint inputModeBits;
  uint arenaCursor;
  uint listIndex;
  uint sourceMask;
  uint srcWordShifted;
  uint srcWord0;
  uint dependencyUsed;
  uint configBit6;
  uint writeMask;
  uint configFlagsValue;
  uint *perRecordWordPtr;
  uint *record;
  uint *inputWord3Ptr;
  bool moreSourcesB;
  bool moreSources;
  bool moreComponentsB;
  bool moreComponents;
  bool recordHasNoSpecialWrite;
  bool sourceIsRegisterFile;
  bool hasRecords;
  bool noOutputRecords;
  bool moreEntries;
  bool moreWords;
  bool moreComponentsC;
  undefined1 *lastRecordIndex;
  uint srcIndexBitsC;
  uint srcTopBitsC;
  lc_str lVar7;
  uint outputWordOld;
  uint *clearPtr3;
  uint inputCount;
  uint inputWord3;
  int componentsLeftC;
  dword *recordIndex;
  dword *lastRecordIndexValue;
  uint *extraout_r4;
  uint *extraout_r4_00;
  uint *extraout_r4_01;
  uint *extraout_r4_02;
  uint *extraout_r4_03;
  uint *extraout_r4_04;
  uint *extraout_r4_05;
  uint *extraout_r4_06;
  uint *extraout_r4_07;
  uint *extraout_r4_08;
  uint *extraout_r4_09;
  uint *extraout_r4_10;
  uint *extraout_r4_11;
  uint *extraout_r4_12;
  uint *extraout_r4_13;
  uint *extraout_r4_14;
  uint *extraout_r4_15;
  dword *pdVar15;
  dword *in_r6;
  uint *puVar16;
  uint inputWord1;
  dword *arena;
  int loopIndex;
  dword *pdVar20;
  uint *tablePtr;
  char opcodeByte;
  int dependencyOffset;
  dword *recordFlagPtr;
  dword *outRecordPtr;
  uint inputWord2;
  uint *puVar27;
  uint uVar28;
  dword dVar29;
  undefined1 *puVar30;
  int *piVar31;
  int *piVar32;
  int componentIndex;
  uint *puVar34;
  byte in_xer_so = 0;
  int remainingB;
  int iVar36;
  undefined8 uVar37;
  uint local_b8;
  uint *local_b4;
  dylib local_b0;
  int *local_a0;
  dword *local_9c;
  undefined1 *local_98;
  int local_94;
  int local_90;
  uint local_8c;
  int local_88;
  uint *local_84;
  uint *local_80;
  uint *local_7c;
  dword *local_78;
  dword *local_74;
  int *local_70;
  int *local_6c;
  int *local_68;
  uint *local_64;
  int local_60;
  uint **local_5c;
  
  if (0x800 < alloc[2]) {
    return 10;
  }
  if (alloc[2] == 0) {
    return 1;
  }
  alloc[0xd] = (uint)alloc;
  local_64 = alloc + 0xc000;
  ((int (*)())chunkArenaResetCursor)(alloc + 0x4915);
  loopIndex = 0;
  local_64[-0x15e2] = 0;
  local_64[-0x1de3] = 0;
  tablePtr = local_64 + 0x21f;
  clearPtr = local_64 + -0x15e4;
  do {
    *(undefined1 *)tablePtr = 0;
    clearPtr3 = clearPtr + 3;
    remainingB = 4;
    do {
      *clearPtr3 = 0;
      clearPtr3[0xc00] = 0;
      clearPtr3 = clearPtr3 + 1;
      remainingB = remainingB + -1;
    } while (remainingB != 0);
    moreEntries = loopIndex != 0x2ff;
    clearPtr = clearPtr + 4;
    tablePtr = (uint *)((int)tablePtr + 1);
    loopIndex = loopIndex + 1;
  } while (moreEntries);
  loopCount4 = 4;
  *(undefined1 *)(local_64 + 0x2e7) = 0;
  clearPtr = local_64 + 0x2df;
  do {
    *clearPtr = 0;
    clearPtr[4] = 0;
    clearPtr = clearPtr + 1;
    loopCount4 = loopCount4 + -1;
  } while (loopCount4 != 0);
  pdVar15 = (dword *)0x2000;
  alloc[0x9a1c] = 0;
  _memset(local_64 + 0x523,0,0x2000);
  loopCount800 = 0x800;
  clearPtr = local_64 + 0xd23;
  do {
    *clearPtr = 0;
    clearPtr = clearPtr + 1;
    loopCount800 = loopCount800 + -1;
  } while (loopCount800 != 0);
  arena = alloc + 0xe;
  local_64[0x1523] = 0;
  ((int (*)())chunkArenaResetCursor)(arena);
  tablePtr = alloc + 0x3914;
  loopIndex = 0;
  pdVar20 = (dword *)0x0;
  clearPtr = alloc + 0x112;
  do {
    clearPtr3 = clearPtr + 2;
    sourceIndexB = 0;
    do {
      moreEntries = sourceIndexB != 2;
      *clearPtr3 = 0;
      sourceIndexB = sourceIndexB + 1;
      clearPtr3 = clearPtr3 + 1;
    } while (moreEntries);
    moreEntries = loopIndex != 0x7ff;
    tablePtr[-0x1000] = 0;
    tablePtr[-0x800] = 0;
    *tablePtr = 0;
    tablePtr[-0x2000] = 0;
    tablePtr[-0x1800] = 0;
    tablePtr[0x801] = 0;
    alloc[0x4114] = 0;
    clearPtr = clearPtr + 3;
    tablePtr = tablePtr + 1;
    loopIndex = loopIndex + 1;
  } while (moreEntries);
  if ((*alloc & 0x40) == 0) {
    alloc[0x8a1b] = alloc[2];
    pdVar15 = (dword *)(alloc[2] << 4);
    _memcpy(alloc + 0x4a1b,alloc[1],pdVar15);
    puVar27 = extraout_r4_00;
  }
  else {
    inputCount = alloc[2];
    alloc[0x8a1b] = inputCount;
    alloc[0x8a1b] = 0;
    puVar27 = extraout_r4;
    if (inputCount != 0) {
      pdVar15 = alloc + 0x4a1b;
      inputRecords = (uint *)alloc[1];
      pdVar20 = pdVar15;
      while( true ) {
        puVar27 = inputRecords + 4;
        inputWord1 = inputRecords[1];
        inputWord2 = inputRecords[2];
        inputWord3 = inputRecords[3];
        *pdVar20 = *inputRecords;
        pdVar20[1] = inputWord1;
        pdVar20[2] = inputWord2;
        pdVar20[3] = inputWord3;
        outputIndexPlus1 = alloc[0x8a1b] + 1;
        alloc[0x8a1b] = outputIndexPlus1;
        if ((*inputRecords & 0x10000000) != 0) {
          inputWord3Ptr = inputRecords + 3;
          in_r6 = pdVar15 + outputIndexPlus1 * 4;
          opcodeInfoOffset = (inputRecords[3] >> 0x15 & 0xf) * 0x14;
          if (0x7ff < outputIndexPlus1) {
            return 10;
          }
          pdVar20[3] = 0x124800;
          *pdVar20 = *pdVar20 & 0xefffffff;
          pdVar15[outputIndexPlus1 * 4] = 0;
          in_r6[3] = 0x124800;
          in_r6[1] = 0x124800;
          in_r6[2] = 0x124800;
          *(byte *)((int)in_r6 + 3) = (byte)(inputRecords[3] >> 0x15) & 0xf | 0x40;
          outputWordOldB = pdVar15[outputIndexPlus1 * 4];
          pdVar15[outputIndexPlus1 * 4] = outputWordOldB & 0xfffff0ff | 0x400;
          outputWordOldB = (inputRecords[3] >> 0x13 & 3) << 0xd | outputWordOldB & 0xff0010ff | 0x400;
          pdVar15[outputIndexPlus1 * 4] = outputWordOldB;
          inputModeBits = inputRecords[3] >> 0x1b & 3;
          if (inputModeBits == 1) {
            pdVar15[outputIndexPlus1 * 4] = outputWordOldB | 0x200000;
          }
          else if (inputModeBits < 2) {
            if (inputModeBits == 0) {
              pdVar15[outputIndexPlus1 * 4] = outputWordOldB | 0x100000;
            }
          }
          else if (inputModeBits == 2) {
            pdVar15[outputIndexPlus1 * 4] = outputWordOldB | 0x400000;
          }
          else if (inputModeBits == 3) {
            pdVar15[outputIndexPlus1 * 4] = outputWordOldB | 0x800000;
          }
          *in_r6 = *in_r6 & 0xefffffff;
          srcOperandIndexA = *(uint *)(&DAT_001aa5f8 + opcodeInfoOffset);
          if (srcOperandIndexA < 3) {
            outputWordOld = in_r6[srcOperandIndexA + 1];
            srcFileBitsC = *inputWord3Ptr & 3;
            in_r6[srcOperandIndexA + 1] = srcFileBitsC | outputWordOld & 0xfffffff0;
            srcFileBit4C = *inputWord3Ptr & 0x10;
            in_r6[srcOperandIndexA + 1] = srcFileBit4C | srcFileBitsC | outputWordOld & 0xffffffe0;
            srcIndexBitsC = *inputWord3Ptr & 0x1fe0;
            in_r6[srcOperandIndexA + 1] = srcIndexBitsC | srcFileBit4C | srcFileBitsC | outputWordOld & 0xffffe000;
            srcTopBitsC = *inputWord3Ptr & 0x60000000;
            in_r6[srcOperandIndexA + 1] = srcTopBitsC | srcIndexBitsC | srcFileBit4C | srcFileBitsC | outputWordOld & 0x9fffe000;
            srcBitsShifted = (*inputWord3Ptr & 0x2000000) << 3;
            in_r6[srcOperandIndexA + 1] = srcBitsShifted | srcTopBitsC | srcIndexBitsC | srcFileBit4C | srcFileBitsC | outputWordOld & 0x8fffe000;
            in_r6[srcOperandIndexA + 1] =
                 (*inputWord3Ptr & 0xe000) << 9 |
                 srcBitsShifted | srcTopBitsC | srcIndexBitsC | srcFileBit4C | srcFileBitsC | outputWordOld & 0x8e3fe000;
          }
          srcOperandIndexB = *(uint *)(&DAT_001aa5fc + opcodeInfoOffset);
          if (srcOperandIndexB < 3) {
            outputWordOld = in_r6[srcOperandIndexB + 1];
            srcFileBitsC = *inputWord3Ptr & 3;
            in_r6[srcOperandIndexB + 1] = srcFileBitsC | outputWordOld & 0xfffffff0;
            srcFileBit4C = *inputWord3Ptr & 0x10;
            in_r6[srcOperandIndexB + 1] = srcFileBit4C | srcFileBitsC | outputWordOld & 0xffffffe0;
            srcIndexBitsC = *inputWord3Ptr & 0x1fe0;
            in_r6[srcOperandIndexB + 1] = srcIndexBitsC | srcFileBit4C | srcFileBitsC | outputWordOld & 0xffffe000;
            srcTopBitsC = *inputWord3Ptr & 0x60000000;
            in_r6[srcOperandIndexB + 1] = srcTopBitsC | srcIndexBitsC | srcFileBit4C | srcFileBitsC | outputWordOld & 0x9fffe000;
            srcBitsShifted = (*inputWord3Ptr & 0x4000000) << 2;
            in_r6[srcOperandIndexB + 1] = srcBitsShifted | srcTopBitsC | srcIndexBitsC | srcFileBit4C | srcFileBitsC | outputWordOld & 0x8fffe000;
            in_r6[srcOperandIndexB + 1] =
                 (*(ushort *)inputWord3Ptr & 7) << 0x16 |
                 srcBitsShifted | srcTopBitsC | srcIndexBitsC | srcFileBit4C | srcFileBitsC | outputWordOld & 0x8e3fe000;
          }
          alloc[0x8a1b] = alloc[0x8a1b] + 1;
        }
        inputCount = inputCount - 1;
        if (inputCount == 0) break;
        pdVar20 = pdVar15 + alloc[0x8a1b] * 4;
        inputRecords = puVar27;
        if (0x7ff < alloc[0x8a1b]) {
          return 10;
        }
      }
    }
  }
  local_78 = (dword *)alloc[0x8a1b];
  records = alloc + 0x4a1b;
  local_74 = (dword *)alloc[6];
  local_70 = (int *)alloc[10];
  local_6c = (int *)alloc[8];
  local_68 = (int *)alloc[9];
  if ((undefined4 *)alloc[7] != (undefined4 *)0x0) {
    *(undefined4 *)alloc[7] = local_78;
  }
  local_60 = (uint)(byte)(((int)local_70 < 0) << 3 | (0 < (int)local_70) << 2 |
                          (local_70 == (int *)0x0) << 1 | in_xer_so & 1) << 0x1c;
  piVar32 = local_6c;
  if (local_70 != (int *)0x0) {
    *local_70 = (int)((int)local_78 + -1);
    piVar32 = local_70;
  }
  lastRecordIndexValue = (dword *)((int)local_78 + -1);
  local_98 = (undefined1 *)lastRecordIndexValue;
  if (-1 < (int)lastRecordIndexValue) {
    recordWordOffset = (int)lastRecordIndexValue * 4;
    dependencyOffset = (int)lastRecordIndexValue * 0xc;
    record = records + (int)lastRecordIndexValue * 4;
    local_94 = 0;
    outRecordPtr = local_74 + (int)lastRecordIndexValue * 4;
    local_5c = &local_b4;
    noOutputRecords = local_74 == (dword *)0x0;
    recordFlagPtr = arena + (int)(local_78 + 0x641) + 1;
    loopCounterC = 0;
    recordIndex = lastRecordIndexValue;
    lastRecordIndex = (undefined1 *)lastRecordIndexValue;
    do {
      lastRecordIndex = lastRecordIndex + -1;
      if (noOutputRecords) {
LAB_0007cc7c:
        configFlagsPtr = (uint *)alloc[0xd];
      }
      else {
        configFlagsPtr = (uint *)alloc[0xd];
        if ((*configFlagsPtr & 0x200) == 0) {
          remainingC = 4;
          outRecordCopyPtr = outRecordPtr;
          recordB = record;
          do {
            configFlagsValue = *recordB;
            recordB = recordB + 1;
            *outRecordCopyPtr = configFlagsValue;
            outRecordCopyPtr = outRecordCopyPtr + 1;
            remainingC = remainingC + -1;
          } while (remainingC != 0);
          goto LAB_0007cc7c;
        }
      }
      iVar36 = 0;
      recordPtrC = records + recordWordOffset;
      do {
        recordPtrC = recordPtrC + 1;
        moreWords = iVar36 != 8;
        *(uint **)(iVar36 + (int)local_5c) = recordPtrC;
        iVar36 = iVar36 + 4;
      } while (moreWords);
      local_b0.current_version = (dword)(records + recordWordOffset);
      recordWriteMask = (dword *)((int (*)())recordGetWriteMask)(record);
      if (recordWriteMask == (dword *)0x0) {
LAB_0007ceb8:
        local_90 = 0;
      }
      else {
        if ((*configFlagsPtr & 0x40) == 0) {
          pdVar20 = (dword *)*record;
          if (((uint)pdVar20 >> 8 & 0xf) - 4 < 5) {
            for (piVar32 = (int *)alloc[0x4114]; piVar32 != (int *)0x0;
                piVar32 = (int *)piVar32[4]) {
              local_b8 = records[*piVar32 * 4];
              if (((uint)pdVar20 & 0xfef00) == (local_b8 & 0xfef00)) {
                writeMask = ((int (*)())recordGetWriteMask)(&local_b8);
                recordWriteMask = (dword *)((uint)recordWriteMask & ~writeMask);
                ((int (*)())recordSetWriteMask)(record,recordWriteMask);
                pdVar20 = (dword *)*record;
              }
            }
            if ((((uint)pdVar20 & 0xf00) == 0x400) && (recordFlagPtr[0x800] = 1, local_94 == 0)) {
              if ((bool)((byte)((uint)local_60 >> 0x1d) & 1)) {
                local_94 = 1;
              }
              else {
                *local_70 = (int)recordIndex;
                local_94 = 1;
              }
            }
            pdVar15 = recordIndex;
            in_r6 = recordWriteMask;
            iVar36 = ((int (*)())depListAddEdge)(alloc,alloc + 0x4114,recordIndex,recordWriteMask,0,0,arena);
            if (iVar36 != 0) {
              return iVar36;
            }
LAB_0007ceb4:
            configFlagsPtr = (uint *)alloc[0xd];
          }
          goto LAB_0007ceb8;
        }
        pdVar20 = (dword *)*record;
        if (1 < ((uint)pdVar20 >> 8 & 0xf) - 2) goto LAB_0007ceb8;
        for (piVar32 = (int *)alloc[0x4114]; piVar32 != (int *)0x0; piVar32 = (int *)piVar32[4]) {
          local_b8 = records[*piVar32 * 4];
          if (((uint)pdVar20 & 0xfe000) == (local_b8 & 0xfe000)) {
            writeMask = ((int (*)())recordGetWriteMask)(&local_b8);
            recordWriteMask = (dword *)((uint)recordWriteMask & ~writeMask);
            ((int (*)())recordSetWriteMask)(record,recordWriteMask);
            pdVar20 = (dword *)*record;
          }
        }
        if (((uint)pdVar20 & 0xfe000) == 0) {
          recordFlagPtr[0x800] = 1;
        }
        if ((local_94 == 0) && ((*record & 0xfe000) == 0)) {
          if ((bool)((byte)((uint)local_60 >> 0x1d) & 1)) {
            local_94 = 1;
          }
          else {
            *local_70 = (int)recordIndex;
            local_94 = 1;
          }
        }
        pdVar15 = recordIndex;
        in_r6 = recordWriteMask;
        iVar36 = ((int (*)())depListAddEdge)(alloc,alloc + 0x4114,recordIndex,recordWriteMask,0,0,arena);
        if (iVar36 != 0) {
          return iVar36;
        }
        if ((*record & 0xf00) != 0x300) goto LAB_0007ceb4;
        configFlagsPtr = (uint *)alloc[0xd];
        local_90 = 1;
      }
      configBit6 = *configFlagsPtr >> 6 & 1;
      iVar36 = ((int (*)())recordDestFileIs0Or45)(record,configBit6);
      if (((iVar36 != 0) || (iVar36 = ((int (*)())recordDestFileIs3Or1)(record,configBit6), iVar36 != 0)) &&
         (piVar32 = (*(int * *)(recordFlagPtr + (0x1000))), piVar32 != (int *)0x0)) {
        pdVar20 = (dword *)((int)((unsigned char *)0x0) + 1);
        do {
          dependencyUsed = arena[*piVar32 + 0x2106];
          if (dependencyUsed != 0) {
            recordFlagPtr[0x800] = 1;
          }
          piVar32 = (int *)piVar32[4];
        } while ((piVar32 != (int *)0x0) && (dependencyUsed == 0));
        configFlagsPtr = (uint *)alloc[0xd];
      }
      configBit6 = *configFlagsPtr >> 6 & 1;
      iVar36 = ((int (*)())recordDestFileIs0Or45)(record,configBit6);
      if ((iVar36 != 0) || (iVar36 = ((int (*)())recordDestFileIs3Or1)(record,configBit6), iVar36 != 0)) {
        usedMaskAccum = (uint *)0x0;
        for (configBit6 = recordFlagPtr[0x1000]; configBit6 != 0; configBit6 = *(uint *)(configBit6 + 0x10)) {
          usedMaskAccum = (uint *)((uint)usedMaskAccum | *(uint *)(configBit6 + 4));
        }
        if (recordWriteMask != usedMaskAccum) {
          ((int (*)())recordSetWriteMask)(record,(uint)recordWriteMask & (uint)usedMaskAccum);
          configFlagsPtr = (uint *)alloc[0xd];
        }
      }
      srcWordPtr0 = local_b4;
      opcodeByte = (char)*record;
      if (((opcodeByte == 'A') && ((*configFlagsPtr & 0x80) != 0)) && (configBit6 = recordFlagPtr[0x1000], configBit6 != 0))
      {
        usedBits = 0;
        do {
          puVar34 = (uint *)(configBit6 + 4);
          configBit6 = *(uint *)(configBit6 + 0x10);
          usedBits = usedBits | *puVar34;
        } while (configBit6 != 0);
        if ((usedBits & 7) == 2) {
          *(undefined1 *)((int)record + 3) = 6;
          pdVar15 = (dword *)((int (*)())recordGetSourceSelect)(local_b4,3);
          ((int (*)())recordSetSourceSelect)(srcWordPtr0,1,pdVar15);
          if (!noOutputRecords) {
            iVar36 = 4;
            outRecordCopyPtr = local_74 + recordWordOffset;
            outRecordSrc = (uint *)local_b0.current_version;
            do {
              configFlagsValue = *outRecordSrc;
              outRecordSrc = outRecordSrc + 1;
              *outRecordCopyPtr = configFlagsValue;
              outRecordCopyPtr = outRecordCopyPtr + 1;
              iVar36 = iVar36 + -1;
            } while (iVar36 != 0);
          }
          configFlagsPtr = (uint *)alloc[0xd];
          opcodeByte = (char)*record;
        }
      }
      if ((opcodeByte == 'D') &&
         (iVar36 = ((int (*)())recordDestFileIs0Or45)(record,*configFlagsPtr >> 6 & 1), puVar16 = local_b4, iVar36 != 0)) {
        pdVar20 = (dword *)(*record & 0xff7fffff);
        *record = *record & 0xff6fffff;
        configFlagsPtr = (uint *)alloc[0xd];
        if ((((*configFlagsPtr >> 6 & 1) != 0) &&
            ((iVar36 = ((int (*)())recordSourceFileIs0)(local_b4), lVar7.offset = local_b0.name.offset, iVar36 != 0 &&
             (iVar36 = ((int (*)())recordSourceFileIs0)(local_b0.name.offset), dVar29 = local_b0.timestamp, iVar36 != 0)
             ))) && (iVar36 = ((int (*)())recordSourceFileIs0)(local_b0.timestamp), iVar36 != 0)) {
          srcWord0 = *puVar16;
          if (((srcWord0 & 0x1fe0) == (*(uint *)lVar7.offset & 0x1fe0)) &&
             ((srcWord0 & 0x1fe0) == (*(uint *)dVar29 & 0x1fe0))) {
            swizzleBitsA = *(uint *)lVar7.offset >> 9 & 0xe000;
            *puVar16 = swizzleBitsA | srcWord0 & 0xffff1fff;
            *puVar16 = *(uint *)dVar29 >> 6 & 0x70000 | swizzleBitsA | srcWord0 & 0xfff81fff;
            srcWord1Old = *(uint *)lVar7.offset;
            srcWord0 = (srcWord0 & 0x1c00000) >> 9;
            *(uint *)lVar7.offset = srcWord0 | srcWord1Old & 0xffff1fff;
            *(uint *)lVar7.offset = *(uint *)dVar29 >> 6 & 0x70000 | srcWord0 | srcWord1Old & 0xfff81fff;
            srcWord2Old = *(uint *)dVar29;
            srcWordShifted = *puVar16 >> 9 & 0xe000;
            *(uint *)dVar29 = srcWordShifted | srcWord2Old & 0xffff1fff;
            *(uint *)dVar29 = *(uint *)lVar7.offset >> 6 & 0x70000 | srcWordShifted | srcWord2Old & 0xfff81fff;
            configFlagsPtr = (uint *)alloc[0xd];
          }
        }
      }
      if ((!noOutputRecords) && ((*configFlagsPtr & 0x200) != 0)) {
        remainingC = 4;
        outRecordCopyPtr = local_74 + recordWordOffset;
        outRecordSrc = (uint *)local_b0.current_version;
        do {
          configFlagsValue = *outRecordSrc;
          outRecordSrc = outRecordSrc + 1;
          *outRecordCopyPtr = configFlagsValue;
          outRecordCopyPtr = outRecordCopyPtr + 1;
          remainingC = remainingC + -1;
        } while (remainingC != 0);
        configFlagsPtr = (uint *)alloc[0xd];
      }
      sourceSlot = 0;
      local_a0 = (int *)0x0;
      uVar37 = ((int (*)())recordOpcodeSourceMask)(record,*configFlagsPtr >> 6 & 1);
      sourceMask = (uint)((ulonglong)uVar37 >> 0x20);
      puVar27 = (uint *)uVar37;
      *recordFlagPtr = sourceMask;
      local_9c = arena + (int)recordIndex * 3 + 0x106;
      local_7c = local_b4;
      local_80 = (uint *)local_b0.name.offset;
      local_84 = (uint *)local_b0.timestamp;
      iVar36 = dependencyOffset;
      local_b0.compatibility_version = (dword)&local_b0;
      do {
        if ((sourceMask & 1 << (sourceSlot & 0x3f)) == 0) {
          srcFileDefault = 5;
          if ((*(uint *)alloc[0xd] & 0x40) == 0) {
            srcFileDefault = 9;
          }
          **(uint **)((int)local_a0 + (int)local_5c) =
               srcFileDefault | **(uint **)((int)local_a0 + (int)local_5c) & 0xfffffff0;
          goto LAB_0007da08;
        }
        configFlagsPtrB = (uint *)alloc[0xd];
        uVar28 = **(uint **)((int)local_a0 + (int)local_5c);
        configBit6B = *configFlagsPtrB >> 6;
        srcFileField = uVar28 & 0xf;
        if ((srcFileField == 0) || (((srcFileField == 3 || (srcFileField == 1)) && ((configBit6B & 1) != 0)))) {
          sourceIsRegisterFile = true;
        }
        else {
          sourceIsRegisterFile = false;
        }
        if (!sourceIsRegisterFile) {
          uVar37 = ((int (*)())recordSourceFileIs2)(*(uint **)((int)local_a0 + (int)local_5c));
          puVar27 = (uint *)uVar37;
          if ((int)((ulonglong)uVar37 >> 0x20) != 0) {
            srcSpecialBit = uVar28 >> 4 & 1;
            if ((configBit6B & 1) != 0) {
              srcSpecialBit = uVar28 >> 0x1e & 2 | uVar28 >> 4 & 1;
            }
            if ((srcSpecialBit == 1) && (local_8c = uVar28 >> 0x1d & 3, -1 < (int)lastRecordIndex)) {
              puVar30 = (undefined1 *)0x0;
              local_88 = (int)alloc + iVar36 + 0x450;
              puVar34 = record;
              do {
                puVar34 = puVar34 + -4;
                local_b8 = *puVar34;
                uVar37 = ((int (*)())recordDestFileIs3Or1)(&local_b8,*configFlagsPtrB >> 6 & 1);
                puVar27 = (uint *)uVar37;
                if ((int)((ulonglong)uVar37 >> 0x20) == 0) {
LAB_0007d968:
                  sourceIsRegisterFile = false;
                }
                else {
                  uVar37 = ((int (*)())recordGetWriteEnable)(&local_b8,local_8c);
                  puVar27 = (uint *)uVar37;
                  if ((int)((ulonglong)uVar37 >> 0x20) == 0) goto LAB_0007d968;
                  pdVar15 = (dword *)(lastRecordIndex + -(int)puVar30);
                  in_r6 = (dword *)(1 << (local_8c & 0x3f));
                  ((int (*)())depListAddEdge)(alloc,local_88,pdVar15,in_r6,0,0,arena);
                  sourceIsRegisterFile = true;
                  puVar27 = extraout_r4_13;
                }
                if ((puVar30 == lastRecordIndex) || (puVar30 = puVar30 + 1, sourceIsRegisterFile)) break;
                configFlagsPtrB = (uint *)alloc[0xd];
              } while( true );
            }
          }
          goto switchD_0007d27c_caseD_0;
        }
        switch((char)*record) {
        case '\x01':
          componentIndex = 0;
          dVar29 = ((lc_str *)local_b0.compatibility_version)->offset;
          do {
            uVar37 = ((int (*)())recordGetSourceSelect)(dVar29,componentIndex);
            puVar27 = (uint *)uVar37;
            if ((int)((ulonglong)uVar37 >> 0x20) != 4) {
              pdVar15 = local_74;
              in_r6 = arena;
              ((int (*)())recordLinkSourceToDefinition)(alloc,records,local_74,arena,recordIndex,sourceSlot,componentIndex);
              puVar27 = extraout_r4_08;
            }
            moreComponents = componentIndex != 3;
            componentIndex = componentIndex + 1;
          } while (moreComponents);
          break;
        case '\x02':
          componentIndex = 0;
          recordHasNoSpecialWrite = local_90 == 0;
          do {
            if (recordHasNoSpecialWrite) {
              uVar37 = ((int (*)())recordGetWriteEnable)(record,componentIndex);
              puVar27 = (uint *)uVar37;
              if ((int)((ulonglong)uVar37 >> 0x20) != 0) {
                uVar37 = ((int (*)())recordGetSourceSelect)(((lc_str *)local_b0.compatibility_version)->offset,componentIndex);
                puVar27 = (uint *)uVar37;
                if ((int)((ulonglong)uVar37 >> 0x20) != 4) {
                  pdVar15 = local_74;
                  in_r6 = arena;
                  ((int (*)())recordLinkSourceToDefinition)(alloc,records,local_74,arena,recordIndex,sourceSlot,componentIndex);
                  puVar27 = extraout_r4_10;
                }
              }
            }
            else if (componentIndex == 0) {
              uVar37 = ((int (*)())recordGetWriteMask)(record);
              puVar27 = (uint *)uVar37;
              if ((int)((ulonglong)uVar37 >> 0x20) != 0) {
                uVar37 = ((int (*)())recordGetSourceSelect)(((lc_str *)local_b0.compatibility_version)->offset,0);
                puVar27 = (uint *)uVar37;
                if ((int)((ulonglong)uVar37 >> 0x20) != 4) {
                  pdVar15 = local_74;
                  in_r6 = arena;
                  ((int (*)())recordLinkSourceToDefinition)(alloc,records,local_74,arena,recordIndex,sourceSlot,0);
                  puVar27 = extraout_r4_09;
                }
              }
            }
            moreComponentsC = componentIndex != 3;
            componentIndex = componentIndex + 1;
          } while (moreComponentsC);
          break;
        case '\x03':
        case '\x04':
        case '\x06':
        case '\a':
        case '\b':
        case '\t':
        case '\n':
        case '\v':
        case '\f':
        case '\r':
        case '\x0e':
        case -0x80:
        case -0x7f:
          componentIndex = 0;
          recordHasNoSpecialWrite = local_90 == 0;
          do {
            if (recordHasNoSpecialWrite) {
              uVar37 = ((int (*)())recordGetWriteEnable)(record,componentIndex);
              puVar27 = (uint *)uVar37;
              if ((int)((ulonglong)uVar37 >> 0x20) != 0) {
                pdVar15 = local_74;
                in_r6 = arena;
                ((int (*)())recordLinkSourceToDefinition)(alloc,records,local_74,arena,recordIndex,sourceSlot,componentIndex);
                puVar27 = extraout_r4_12;
              }
            }
            else if (componentIndex == 0) {
              uVar37 = ((int (*)())recordGetWriteMask)(record);
              puVar27 = (uint *)uVar37;
              if ((int)((ulonglong)uVar37 >> 0x20) != 0) {
                pdVar15 = local_74;
                in_r6 = arena;
                ((int (*)())recordLinkSourceToDefinition)(alloc,records,local_74,arena,recordIndex,sourceSlot,0);
                puVar27 = extraout_r4_11;
              }
            }
            moreComponentsC = componentIndex != 3;
            componentIndex = componentIndex + 1;
          } while (moreComponentsC);
          break;
        case '\x05':
          componentIndex = 1;
          do {
            if (sourceSlot == 0) {
              if (componentIndex - 1U < 2) {
LAB_0007d6c4:
                uVar37 = ((int (*)())recordGetWriteEnable)(record,componentIndex);
                puVar27 = (uint *)uVar37;
                if ((int)((ulonglong)uVar37 >> 0x20) != 0) {
                  pdVar15 = local_74;
                  in_r6 = arena;
                  ((int (*)())recordLinkSourceToDefinition)(alloc,records,local_74,arena,recordIndex,sourceSlot,componentIndex);
                  puVar27 = extraout_r4_07;
                }
              }
            }
            else if ((sourceSlot == 1) && ((componentIndex == 1 || (componentIndex == 3)))) goto LAB_0007d6c4;
            moreComponents = componentIndex != 3;
            componentIndex = componentIndex + 1;
          } while (moreComponents);
          break;
        case 'A':
        case 'B':
        case 'F':
        case 'H':
        case 'K':
        case 'L':
        case 'P':
        case 'Q':
          goto switchD_0007d27c_caseD_41;
        case 'C':
        case 'G':
        case 'I':
          if ((configBit6B & 1) != 0) goto switchD_0007d27c_caseD_41;
          pdVar15 = local_74;
          in_r6 = arena;
          ((int (*)())recordLinkSourceToDefinition)(alloc,records,local_74,arena,recordIndex,sourceSlot,0);
          puVar27 = extraout_r4_04;
          break;
        case 'D':
          componentIndex = 0;
          if ((configBit6B & 1) == 0) {
            do {
              pdVar15 = local_74;
              in_r6 = arena;
              ((int (*)())recordLinkSourceToDefinition)(alloc,records,local_74,arena,recordIndex,sourceSlot,componentIndex);
              componentsLeftC = 4 - componentIndex;
              if (4 < componentIndex + 1) {
                componentsLeftC = 1;
              }
              do {
                componentIndex = componentIndex + 1;
                componentsLeftC = componentsLeftC + -1;
                puVar27 = extraout_r4_01;
                if (componentsLeftC == 0) goto switchD_0007d27c_caseD_0;
              } while (componentIndex == 2);
            } while( true );
          }
          if ((((*local_7c & 0xf) == 0) && ((*local_80 & 0xf) == 0)) &&
             (((*local_84 & 0xf) == 0 &&
              ((configBit6B = *local_7c & 0x1fe0, configBit6B == (*local_80 & 0x1fe0) &&
               (componentIndex = 0, configBit6B == (*local_84 & 0x1fe0))))))) {
            do {
              pdVar15 = local_74;
              in_r6 = arena;
              ((int (*)())recordLinkSourceToDefinition)(alloc,records,local_74,arena,recordIndex,sourceSlot,componentIndex);
              componentsLeftC = 4 - componentIndex;
              if (4 < componentIndex + 1) {
                componentsLeftC = 1;
              }
              do {
                componentIndex = componentIndex + 1;
                componentsLeftC = componentsLeftC + -1;
                puVar27 = extraout_r4_02;
                if (componentsLeftC == 0) goto switchD_0007d27c_caseD_0;
              } while (componentIndex == 2);
            } while( true );
          }
          goto switchD_0007d27c_caseD_41;
        case 'E':
        case 'M':
        case 'N':
        case 'O':
          componentIndex = 0;
          if ((configBit6B & 1) == 0) {
            do {
              pdVar15 = local_74;
              in_r6 = arena;
              ((int (*)())recordLinkSourceToDefinition)(alloc,records,local_74,arena,recordIndex,sourceSlot,componentIndex);
              componentsLeftC = 3 - componentIndex;
              if (3 < componentIndex + 1) {
                componentsLeftC = 1;
              }
              do {
                componentIndex = componentIndex + 1;
                componentsLeftC = componentsLeftC + -1;
                puVar27 = extraout_r4_03;
                if (componentsLeftC == 0) goto switchD_0007d27c_caseD_0;
              } while (((componentIndex == 1) && ((char)*record != '\r')) && ((char)*record != '\x0e'));
            } while( true );
          }
switchD_0007d27c_caseD_41:
          pdVar15 = local_74;
          in_r6 = arena;
          ((int (*)())recordLinkSourceToDefinition)(alloc,records,local_74,arena,recordIndex,sourceSlot,3);
          puVar27 = extraout_r4_06;
          break;
        case 'J':
          if ((configBit6B & 1) != 0) goto switchD_0007d27c_caseD_41;
          componentIndex = 0;
          do {
            pdVar15 = local_74;
            in_r6 = arena;
            ((int (*)())recordLinkSourceToDefinition)(alloc,records,local_74,arena,recordIndex,sourceSlot,componentIndex);
            moreComponentsB = componentIndex != 1;
            componentIndex = componentIndex + 1;
            puVar27 = extraout_r4_05;
          } while (moreComponentsB);
        }
switchD_0007d27c_caseD_0:
        for (piVar32 = (int *)*local_9c; piVar32 != (int *)0x0;
            piVar32 = *(int **)((int)piVar32 + 0x10)) {
          in_r6 = *(dword **)((int)piVar32 + 4);
          pdVar15 = recordIndex;
          uVar37 = ((int (*)())depListAddEdge)(alloc,alloc + *piVar32 + 0x2914,recordIndex,in_r6,
                                *(int *)((int)piVar32 + 8),0,arena);
          componentIndex = (int)((ulonglong)uVar37 >> 0x20);
          puVar27 = (uint *)uVar37;
          if (componentIndex != 0) {
            return componentIndex;
          }
        }
LAB_0007da08:
        moreSources = sourceSlot != 2;
        iVar36 = iVar36 + 4;
        sourceSlot = sourceSlot + 1;
        local_9c = local_9c + 1;
        piVar32 = local_a0 + 1;
        lastRecordIndexValue = &((dylib *)(local_b0.compatibility_version + -0x10))->compatibility_version;
        local_b0.compatibility_version = (dword)lastRecordIndexValue;
        local_a0 = piVar32;
      } while (moreSources);
      loopCounterC = loopCounterC + 1;
      recordIndex = (dword *)((int)recordIndex + -1);
      dependencyOffset = dependencyOffset + -0xc;
      record = record + -4;
      recordFlagPtr = recordFlagPtr + 0xffffffff;
      recordWordOffset = recordWordOffset + -4;
      outRecordPtr = outRecordPtr + -4;
    } while (loopCounterC != (int)local_98 + 1);
  }
  hasRecords = 0 < (int)local_78;
  if (hasRecords) {
    tablePtr = alloc + 0x2914;
    listIndex = 0;
    dependencyHeadPtr = alloc + 0x3114;
    do {
      for (piVar31 = (int *)*tablePtr; piVar31 != (int *)0x0; piVar31 = (int *)piVar31[4]) {
        slotLoopB = 0;
        lastRecordIndexValue = arena + *piVar31 * 3;
        usedSourcesMask = arena[*piVar31 + 0x1906];
        perRecordWordPtr = lastRecordIndexValue + 0x106;
        do {
          if (((usedSourcesMask & 1 << (slotLoopB & 0x3f)) != 0) &&
             (pdVar15 = (dword *)*perRecordWordPtr, pdVar15 != (dword *)0x0)) {
            lastRecordIndexValue = (dword *)0x0;
            listPosB = pdVar15;
            do {
              if (listIndex == *listPosB) {
                lastRecordIndexValue = (dword *)((int)((unsigned char *)0x0) + 1);
              }
              listPosB = (*(dword * *)(listPosB + (4)));
              scanFlag = lastRecordIndexValue;
            } while (listPosB != (dword *)0x0);
            while (scanFlag != (dword *)0x0) {
              if (listIndex != *pdVar15) {
                in_r6 = (*(dword * *)(pdVar15 + (1)));
                piVar32 = (int *)0x0;
                lastRecordIndexValue = arena;
                status = ((int (*)())depListAddEdge)(alloc,dependencyHeadPtr,*pdVar15,in_r6,0,0,arena);
                if (status != 0) {
                  return status;
                }
              }
              pdVar15 = (*(dword * *)(pdVar15 + (4)));
              scanFlag = pdVar15;
            }
          }
          moreSourcesB = slotLoopB != 2;
          perRecordWordPtr = perRecordWordPtr + 1;
          slotLoopB = slotLoopB + 1;
        } while (moreSourcesB);
      }
      listIndex = listIndex + 1;
      dependencyHeadPtr = dependencyHeadPtr + 1;
      tablePtr = tablePtr + 1;
    } while ((dword *)listIndex != local_78);
    tablePtr = alloc + 0x3114;
    loopIndex = 0;
    do {
      pdVar15 = (unsigned int *)0x800;
      _memset(local_64 + 0x314,0,0x800);
      puVar27 = extraout_r4_14;
      for (piVar31 = (int *)*tablePtr; piVar31 != (int *)0x0; piVar31 = (int *)piVar31[4]) {
        pdVar15 = (dword *)*piVar31;
        in_r6 = (dword *)piVar31[1];
        ((int (*)())recordAddTransitiveDependencies)(alloc,loopIndex,pdVar15,in_r6);
        puVar27 = extraout_r4_15;
      }
      loopIndex = loopIndex + 1;
      tablePtr = tablePtr + 1;
    } while ((dword *)loopIndex != local_78);
  }
  piVar31 = local_68;
  if (((local_68 != (int *)0x0) && (piVar32 = local_6c, local_6c != (int *)0x0)) &&
     (*local_68 = 0, hasRecords)) {
    puVar27 = alloc + 0x2114;
    pdVar20 = (dword *)0x0;
    pdVar15 = local_74;
    do {
      if (*puVar27 != 0) {
        loopIndex = 0;
        remainingB = 4;
        arenaB = pdVar15;
        do {
          arenaCursor = *arenaB;
          arenaB = arenaB + 1;
          outputOffset = *local_68 * 4 + loopIndex;
          loopIndex = loopIndex + 1;
          local_6c[outputOffset] = arenaCursor;
          remainingB = remainingB + -1;
        } while (remainingB != 0);
        *local_68 = *local_68 + 1;
        piVar31 = local_6c;
        piVar32 = local_68;
      }
      pdVar20 = (dword *)((int)pdVar20 + 1);
      puVar27 = puVar27 + 1;
      pdVar15 = pdVar15 + 4;
      lastRecordIndexValue = local_78;
    } while (pdVar20 != local_78);
  }
  if ((*alloc & 0x100) == 0) {
    status = ((int (*)())recordProgramAllocateAndEmit)(alloc,puVar27,pdVar15,in_r6,piVar31,piVar32,lastRecordIndexValue,pdVar20);
    return status;
  }
  return 0;
}

/* ctxTempListPush @ 0x7dcd0 (88 bytes) */
int ctxTempListPush(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = *(int *)(((unsigned char *)0x000011b4) + param_1);
  puVar1 = (undefined4 *)(**(code **)(param_1 + 0xc))(8,param_2);
  *puVar1 = param_2;
  puVar1[1] = *(undefined4 *)(iVar2 + 8);
  *(undefined4 **)(iVar2 + 8) = puVar1;
  return;
}

/* ctxTempListRemove @ 0x7dd30 (160 bytes) */
int ctxTempListRemove(param_1, param_2)
  int param_1;
  int param_2;
{
  undefined4 uVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  
  iVar4 = *(int *)(((unsigned char *)0x000011b4) + param_1);
  if ((iVar4 == 0) || (piVar2 = *(int **)(iVar4 + 8), piVar2 == (int *)0x0)) {
LAB_0007ddc0:
    uVar1 = 0;
  }
  else {
    if (*piVar2 == param_2) {
      *(int *)(iVar4 + 8) = piVar2[1];
    }
    else {
      do {
        piVar3 = piVar2;
        piVar2 = (int *)piVar3[1];
        if (piVar2 == (int *)0x0) goto LAB_0007ddc0;
      } while (param_2 != *piVar2);
      piVar3[1] = piVar2[1];
    }
    (**(code **)(param_1 + 0x18))(piVar2);
    uVar1 = 1;
  }
  return uVar1;
}

/* evsFoldConstantMoves @ 0x7dde0 (3504 bytes) */
int evsFoldConstantMoves(compiler, shaderProgram)
  undefined4 compiler;
  int shaderProgram;
{
  byte laneWLoaded;
  byte laneZLoaded;
  byte laneYLoaded;
  byte laneXLoaded;
  byte laneW;
  byte laneZ;
  byte laneY;
  byte laneX;
  bool laterHasX;
  undefined4 candidateSrc2SelectorW;
  undefined4 candidateSrc2SelectorZ;
  undefined4 candidateSrc2SelectorY;
  undefined4 candidateSrc2SelectorX;
  undefined4 candidateSrc1SelectorW;
  undefined4 candidateSrc1SelectorZ;
  undefined4 candidateSrc1SelectorY;
  undefined4 candidateSrc1SelectorX;
  undefined4 candidateSrc0SelectorW;
  undefined4 candidateSrc0SelectorZ;
  undefined4 candidateSrc0SelectorY;
  undefined4 candidateSrc0SelectorX;
  undefined4 writerSrc2SelectorW;
  undefined4 writerSrc2SelectorY;
  undefined4 writerSrc1SelectorW;
  undefined4 writerSrc1SelectorY;
  undefined4 writerSrc0SelectorW;
  undefined4 writerSrc0SelectorY;
  bool wIsOne;
  bool yIsOne;
  bool xIsOne;
  bool bVar1;
  float constantX;
  float constantW;
  float constantY;
  float constantZ;
  bool allLanesPass;
  byte passW;
  float *constantValue;
  undefined4 uVar9;
  byte crBitsByte;
  int instructions;
  byte passX;
  byte passY;
  int laterRecord;
  uint instructionIndex;
  uint instructionCount;
  undefined4 *selectorBase;
  uint uVar18;
  undefined4 uVar19;
  undefined4 uVar20;
  int *laterSlotCursor;
  undefined4 uVar22;
  int symbol;
  undefined4 selectorEnumerant;
  uint writeEnableX;
  uint writeEnableY;
  uint writeEnableZ;
  byte passZ;
  uint writeEnableW;
  uint uVar30;
  int currentInstruction;
  int movRecord;
  byte in_xer_so = 0;
  bool bVar33;
  bool bVar34;
  bool bVar35;
  bool bVar36;
  bool bVar37;
  bool yIsZero;
  bool wIsZero;
  char readsX;
  char readsY;
  char readsZ;
  char acStack_85 [13];
  int iStack_78;
  undefined4 uStack_70;
  undefined4 uStack_60;
  
  instructionCount = *(uint *)(shaderProgram + 0x14);
  if (instructionCount != 0) {
    instructionIndex = 0;
    selectorEnumerant = 0x87df;
LAB_0007de3c:
    instructions = *(int *)(shaderProgram + 0x18);
    currentInstruction = instructionIndex * 0x74 + instructions;
    if ((((((*(int *)(instructionIndex * 0x74 + instructions) == 0x8799) && (*(int *)(currentInstruction + 0x20) == 2)) &&
          (*(int *)(currentInstruction + 0x28) == 0x87d5)) &&
         ((*(int *)(currentInstruction + 0x2c) == 0x87d6 && (*(int *)(currentInstruction + 0x30) == 0x87d7)))) &&
        (*(int *)(currentInstruction + 0x34) == 0x87d8)) &&
       ((symbol = *(int *)(currentInstruction + 0x24) * 0x54 + *(int *)(shaderProgram + 0x20),
        *(int *)(symbol + 0x28) == 0x87c3 && (*(int *)(symbol + 0x24) == 0x87bf)))) {
      constantValue = *(float **)(symbol + 0x38);
      constantX = *constantValue;
      constantW = constantValue[3];
      constantY = constantValue[1];
      constantZ = constantValue[2];
      uStack_60 = 0;
      xIsOne = constantX == 1.0;
      yIsOne = constantY == 1.0;
      wIsOne = constantW == 1.0;
      uVar30 = (uint)(byte)((constantX == 0.0) << 2 | (constantX != 0.0) << 1 | in_xer_so & 1);
      iStack_78 = uVar30 << 0x1c;
      bVar36 = constantZ == 1.0;
      bVar37 = constantZ == 0.0;
      yIsZero = constantY == 0.0;
      wIsZero = constantW == 0.0;
      if (((((!(bool)((byte)((uVar30 << 0xc) >> 8) >> 5 & 1)) ||
            (((xIsOne || (constantX == -1.0)) || (yIsZero)))) ||
           (((yIsOne || (constantY == -1.0)) || (bVar37)))) ||
          (((bVar36 || (constantZ == -1.0)) || ((wIsZero || ((wIsOne || (constantW == -1.0)))))))) &&
         (uVar30 = instructionIndex + 1, uVar30 < instructionCount)) {
        movRecord = uVar30 * 0x74;
        allLanesPass = false;
        uVar18 = uVar30;
        symbol = movRecord;
        do {
          laterRecord = symbol + instructions;
          if (((*(int *)(symbol + instructions) == 0x879b) && (*(int *)(laterRecord + 4) == 2)) &&
             (*(int *)(laterRecord + 8) == *(int *)(currentInstruction + 8))) {
            laterHasX = *(int *)(laterRecord + 0xc) != 0;
            crBitsByte = (byte)((uint)iStack_78 >> 0x18);
            if (((laterHasX) || (!(bool)(crBitsByte >> 5 & 1))) || ((xIsOne || (passX = 0, constantX == -1.0)))
               ) {
              passX = 1;
            }
            if (((*(int *)(laterRecord + 0x10) != 0) || (yIsZero)) ||
               ((yIsOne || (passY = 0, constantY == -1.0)))) {
              passY = 1;
            }
            if ((((*(int *)(laterRecord + 0x14) != 0) || (bVar37)) || (bVar36)) ||
               (passZ = 0, constantZ == -1.0)) {
              passZ = 1;
            }
            if (((*(int *)(laterRecord + 0x18) != 0) || (wIsZero)) ||
               ((wIsOne || (passW = 0, constantW == -1.0)))) {
              passW = 1;
            }
            allLanesPass = (bool)(passW & passZ & passY & passX);
            if (allLanesPass) {
              if (!laterHasX) {
                *(undefined4 *)(laterRecord + 0xc) = 1;
                if ((bool)(crBitsByte >> 5 & 1)) {
                  if (xIsOne) {
                    *(undefined4 *)(laterRecord + 0x28) = 0x87de;
                  }
                  else {
                    *(undefined4 *)(laterRecord + 0x28) = selectorEnumerant;
                  }
                }
                else {
                  *(undefined4 *)(laterRecord + 0x28) = 0x87dd;
                }
              }
              if (*(int *)(laterRecord + 0x10) == 0) {
                *(undefined4 *)(laterRecord + 0x10) = 1;
                if (yIsZero) {
                  *(undefined4 *)(laterRecord + 0x2c) = 0x87dd;
                }
                else if (yIsOne) {
                  *(undefined4 *)(laterRecord + 0x2c) = 0x87de;
                }
                else {
                  *(undefined4 *)(laterRecord + 0x2c) = selectorEnumerant;
                }
              }
              if (*(int *)(laterRecord + 0x14) == 0) {
                *(undefined4 *)(laterRecord + 0x14) = 1;
                if (bVar37) {
                  *(undefined4 *)(laterRecord + 0x30) = 0x87dd;
                }
                else if (bVar36) {
                  *(undefined4 *)(laterRecord + 0x30) = 0x87de;
                }
                else {
                  *(undefined4 *)(laterRecord + 0x30) = selectorEnumerant;
                }
              }
              if (*(int *)(laterRecord + 0x18) == 0) {
                *(undefined4 *)(laterRecord + 0x18) = 1;
                if (wIsZero) {
                  *(undefined4 *)(laterRecord + 0x34) = 0x87dd;
                  bVar1 = true;
                  instructionCount = *(uint *)(shaderProgram + 0x14);
                }
                else if (wIsOne) {
                  *(undefined4 *)(laterRecord + 0x34) = 0x87de;
                  bVar1 = true;
                  instructionCount = *(uint *)(shaderProgram + 0x14);
                }
                else {
                  *(undefined4 *)(laterRecord + 0x34) = selectorEnumerant;
                  bVar1 = true;
                  instructionCount = *(uint *)(shaderProgram + 0x14);
                }
                goto LAB_0007e2bc;
              }
              instructionCount = *(uint *)(shaderProgram + 0x14);
            }
            bVar1 = true;
          }
          else {
            bVar1 = false;
          }
LAB_0007e2bc:
          uVar18 = uVar18 + 1;
          if ((instructionCount <= uVar18) || (symbol = symbol + 0x74, bVar1)) goto LAB_0007e2d4;
          instructions = *(int *)(shaderProgram + 0x18);
        } while( true );
      }
    }
    goto LAB_0007e2e0;
  }
LAB_0007e330:
  instructionIndex = 0;
  do {
    bVar33 = false;
    for (uVar30 = instructionCount; 1 < uVar30; uVar30 = uVar30 - 1) {
      currentInstruction = uVar30 * 0x74;
      instructions = *(int *)(shaderProgram + 0x18) + currentInstruction;
      if (((((*(int *)(instructions + -0x74) == 0x879b) || (*(int *)(instructions + -0x74) == 0x8799)) &&
           (*(int *)(instructions + -0x54) == 2)) &&
          ((*(char *)(instructions + -0x3c) == '\0' &&
           ((*(char *)(shaderProgram + 0x7b) == '\0' ||
            (*(int *)(*(int *)(instructions + -0x6c) * 0x54 + *(int *)(shaderProgram + 0x20) + 0x28) != 0x87c4))
           )))) && ((*(int *)(instructions + -0x4c) == 0x87d5 &&
                    (((*(int *)(instructions + -0x48) == 0x87d6 && (*(int *)(instructions + -0x44) == 0x87d7))
                     && (*(int *)(instructions + -0x40) == 0x87d8)))))) {
        if (uVar30 < instructionCount) {
          symbol = instructionCount - uVar30;
          laterSlotCursor = (int *)(instructions + 0x20);
          laneX = 0;
          laneY = 0;
          laneZ = 0;
          laneW = 0;
          bVar34 = true;
          do {
            if (((*laterSlotCursor == 2) && (laterSlotCursor[1] == *(int *)(instructions + -0x50))) ||
               (((laterSlotCursor[7] == 2 && (laterSlotCursor[8] == *(int *)(instructions + -0x50))) ||
                ((laterSlotCursor[0xe] == 2 && (laterSlotCursor[0xf] == *(int *)(instructions + -0x50))))))) {
              bVar35 = true;
              bVar34 = false;
            }
            else {
              if ((laterSlotCursor[-7] == 2) && (laterSlotCursor[-6] == *(int *)(instructions + -0x50))) {
                laneX = laneX | *(byte *)((int)laterSlotCursor + -0x11);
                laneY = laneY | *(byte *)((int)laterSlotCursor + -0xd);
                laneZ = laneZ | *(byte *)((int)laterSlotCursor + -9);
                laneW = laneW | *(byte *)((int)laterSlotCursor + -5);
                if ((laneX != 0) && ((laneY != 0 && (laneZ != 0)))) {
                  bVar35 = laneW != 0;
                  goto LAB_0007e530;
                }
              }
              bVar35 = false;
            }
LAB_0007e530:
            symbol = symbol + -1;
          } while ((symbol != 0) && (laterSlotCursor = laterSlotCursor + 0x1d, !bVar35));
          if (!bVar34) goto LAB_0007e760;
        }
        uVar18 = uVar30 - 1;
        if (uVar18 != 0) {
          writeEnableW = 0;
          writeEnableZ = 0;
          writeEnableY = 0;
          writeEnableX = 0;
          bVar34 = false;
          do {
            symbol = *(int *)(shaderProgram + 0x18) + uVar18 * 0x74;
            bVar35 = *(int *)(symbol + -0x54) == 2;
            if ((((bVar35) && (*(int *)(symbol + -0x50) == *(int *)(instructions + -0x50))) ||
                ((bVar36 = *(int *)(symbol + -0x38) == 2, bVar36 &&
                 (*(int *)(symbol + -0x34) == *(int *)(instructions + -0x50))))) ||
               ((bVar37 = *(int *)(symbol + -0x1c) == 2, bVar37 &&
                (*(int *)(symbol + -0x18) == *(int *)(instructions + -0x50))))) {
              instructionIndex = uVar18 - 1;
              bVar35 = true;
              bVar34 = true;
            }
            else if ((((bVar35) && (*(int *)(symbol + -0x50) == *(int *)(instructions + -0x6c))) ||
                     ((bVar36 && (*(int *)(symbol + -0x34) == *(int *)(instructions + -0x6c))))) ||
                    ((bVar37 && (*(int *)(symbol + -0x18) == *(int *)(instructions + -0x6c))))) {
              bVar35 = true;
              bVar34 = false;
            }
            else {
              bVar35 = false;
            }
            uVar18 = uVar18 - 1;
            if (((*(int *)(symbol + -0x74) != 0x879c) && (*(int *)(symbol + -0x70) == 2)) &&
               (*(int *)(symbol + -0x6c) == *(int *)(instructions + -0x50))) {
              writeEnableX = writeEnableX | *(byte *)(symbol + -0x65);
              writeEnableY = writeEnableY | *(byte *)(symbol + -0x61);
              writeEnableW = writeEnableW | *(byte *)(symbol + -0x59);
              writeEnableZ = writeEnableZ | *(byte *)(symbol + -0x5d);
              if (((*(uint *)(instructions + -0x68) <= writeEnableX) && (*(uint *)(instructions + -100) <= writeEnableY)) &&
                 ((*(uint *)(instructions + -0x60) <= writeEnableZ && (*(uint *)(instructions + -0x5c) <= writeEnableW)))) {
                bVar35 = true;
                bVar34 = true;
                instructionIndex = uVar18;
              }
            }
          } while ((uVar18 != 0) && (!bVar35));
          if (bVar34) {
            extvsInstReadsTempComponents(shaderProgram + 0x1c,instructions + -0x74,*(undefined4 *)(instructions + -0x50),&readsX,
                         &readsY,&readsZ,acStack_85);
            if (((((readsX == '\0') || (writeEnableX != 0)) && ((readsY == '\0' || (writeEnableY != 0))))
                && ((readsZ == '\0' || (writeEnableZ != 0)))) &&
               ((acStack_85[0] == '\0' || (writeEnableW != 0)))) {
              if (instructionIndex < uVar30) {
                symbol = uVar30 - instructionIndex;
                movRecord = instructionIndex * 0x74;
                do {
                  laterRecord = movRecord + *(int *)(shaderProgram + 0x18);
                  if (((*(int *)(movRecord + *(int *)(shaderProgram + 0x18)) != 0x879c) &&
                      (*(int *)(laterRecord + 4) == 2)) &&
                     (*(int *)(laterRecord + 8) == *(int *)(instructions + -0x50))) {
                    selectorEnumerant = *(undefined4 *)(instructions + -0x6c);
                    *(undefined4 *)(laterRecord + 4) = *(undefined4 *)(instructions + -0x70);
                    *(undefined4 *)(laterRecord + 8) = selectorEnumerant;
                    instructionCount = *(uint *)(instructions + -0x5c);
                    writeEnableX = *(uint *)(instructions + -100);
                    uVar18 = *(uint *)(instructions + -0x60);
                    *(uint *)(laterRecord + 0xc) = *(uint *)(laterRecord + 0xc) & *(uint *)(instructions + -0x68);
                    *(uint *)(laterRecord + 0x10) = *(uint *)(laterRecord + 0x10) & writeEnableX;
                    *(uint *)(laterRecord + 0x14) = *(uint *)(laterRecord + 0x14) & uVar18;
                    *(uint *)(laterRecord + 0x18) = *(uint *)(laterRecord + 0x18) & instructionCount;
                  }
                  movRecord = movRecord + 0x74;
                  symbol = symbol + -1;
                } while (symbol != 0);
              }
              instructionCount = *(uint *)(shaderProgram + 0x14);
              uVar18 = uVar30;
              if (uVar30 < instructionCount) {
                do {
                  uVar18 = uVar18 + 1;
                  instructions = currentInstruction + *(int *)(shaderProgram + 0x18);
                  currentInstruction = currentInstruction + 0x74;
                  _memcpy(instructions + -0x74,instructions,0x74);
                  instructionCount = *(uint *)(shaderProgram + 0x14);
                } while (uVar18 < instructionCount);
              }
              instructionCount = instructionCount - 1;
              bVar33 = true;
              *(uint *)(shaderProgram + 0x14) = instructionCount;
            }
            else {
              instructionCount = *(uint *)(shaderProgram + 0x14);
            }
          }
        }
      }
LAB_0007e760: ;
    }
    if (instructionCount != 0) {
      uVar30 = 0;
      do {
        currentInstruction = *(int *)(shaderProgram + 0x18);
        symbol = uVar30 * 0x74;
        instructions = *(int *)(currentInstruction + symbol);
        movRecord = currentInstruction + symbol;
        if ((((instructions == 0x879b) || (instructions == 0x8799)) || (instructions == 0x879a)) &&
           ((((*(char *)(movRecord + 0x38) == '\0' && (*(int *)(movRecord + 4) == 2)) &&
             ((*(char *)(shaderProgram + 0x7b) == '\0' ||
              (*(int *)(*(int *)(movRecord + 8) * 0x54 + *(int *)(shaderProgram + 0x20) + 0x28) != 0x87c4))))
            && ((((*(int *)(movRecord + 0xc) != 0 && (*(int *)(movRecord + 0x10) != 0)) &&
                 (*(int *)(movRecord + 0x14) != 0)) && (*(int *)(movRecord + 0x18) != 0)))))) {
          writeEnableX = uVar30 + 1;
          uVar18 = writeEnableX;
          instructionIndex = instructionCount;
          if (writeEnableX < instructionCount) {
            bVar34 = true;
            do {
              instructions = currentInstruction + uVar18 * 0x74;
              if (*(int *)(instructions + 4) == 2) {
                instructions = *(int *)(instructions + 8);
                bVar35 = instructions == *(int *)(movRecord + 8);
                if (bVar35) {
                  instructionIndex = uVar18 + 1;
                }
                if (*(int *)(movRecord + 0x24) == instructions) {
                  bVar35 = true;
                  bVar34 = false;
                }
              }
              else {
                bVar35 = false;
              }
              uVar18 = uVar18 + 1;
            } while ((uVar18 < instructionCount) && (!bVar35));
            if (!bVar34) goto LAB_00080860;
          }
          bVar34 = true;
          instructions = currentInstruction + uVar18 * 0x74;
          laneWLoaded = *(byte *)(instructions + -0x59);
          laneXLoaded = *(byte *)(instructions + -0x65);
          laneYLoaded = *(byte *)(instructions + -0x61);
          laneZLoaded = *(byte *)(instructions + -0x5d);
          if (instructionIndex < instructionCount) {
            instructions = instructionIndex * 0x74;
            uVar18 = instructionIndex;
            while( true ) {
              currentInstruction = instructions + currentInstruction;
              if ((((*(int *)(currentInstruction + 0x20) == 2) &&
                   (laterRecord = *(int *)(movRecord + 8), *(int *)(currentInstruction + 0x24) == laterRecord)) ||
                  ((*(int *)(currentInstruction + 0x3c) == 2 &&
                   (laterRecord = *(int *)(movRecord + 8), *(int *)(currentInstruction + 0x40) == laterRecord)))) ||
                 ((*(int *)(currentInstruction + 0x58) == 2 &&
                  (laterRecord = *(int *)(movRecord + 8), *(int *)(currentInstruction + 0x5c) == laterRecord)))) {
                extvsInstReadsTempComponents(shaderProgram + 0x1c,currentInstruction,laterRecord,&readsX,&readsY,&readsZ,
                             acStack_85);
                if (((readsX == '\0') || (laneXLoaded != 0)) &&
                   ((((readsY == '\0' || (laneYLoaded != 0)) && ((readsZ == '\0' || (laneZLoaded != 0)))
                     ) && ((acStack_85[0] == '\0' || (laneWLoaded != 0)))))) {
                  instructionCount = *(uint *)(shaderProgram + 0x14);
                }
                else {
                  instructionCount = *(uint *)(shaderProgram + 0x14);
                  bVar34 = false;
                }
              }
              if ((*(int *)(currentInstruction + 4) == 2) && (*(int *)(currentInstruction + 8) == *(int *)(movRecord + 8))) {
                laneWLoaded = laneWLoaded | *(byte *)(currentInstruction + 0x1b);
                laneXLoaded = laneXLoaded | *(byte *)(currentInstruction + 0xf);
                laneYLoaded = laneYLoaded | *(byte *)(currentInstruction + 0x13);
                laneZLoaded = laneZLoaded | *(byte *)(currentInstruction + 0x17);
              }
              uVar18 = uVar18 + 1;
              instructions = instructions + 0x74;
              if (instructionCount <= uVar18) break;
              currentInstruction = *(int *)(shaderProgram + 0x18);
            }
            if (!bVar34) goto LAB_00080860;
          }
          if (writeEnableX < instructionIndex) {
            currentInstruction = writeEnableX * 0x74;
            instructions = instructionIndex - writeEnableX;
            do {
              laterRecord = currentInstruction + *(int *)(shaderProgram + 0x18);
              if ((*(int *)(laterRecord + 0x20) == 2) &&
                 (*(int *)(laterRecord + 0x24) == *(int *)(movRecord + 8))) {
                selectorEnumerant = *(undefined4 *)(laterRecord + 0x28);
                selectorBase = (undefined4 *)(movRecord + 0x28);
                *(undefined4 *)(laterRecord + 0x24) = *(undefined4 *)(movRecord + 0x24);
                switch(selectorEnumerant) {
                case 0x87d5:
                  selectorEnumerant = *selectorBase;
                  break;
                case 0x87d6:
                  selectorEnumerant = *(undefined4 *)(movRecord + 0x2c);
                  break;
                case 0x87d7:
                  selectorEnumerant = *(undefined4 *)(movRecord + 0x30);
                  break;
                case 0x87d8:
                  selectorEnumerant = *(undefined4 *)(movRecord + 0x34);
                  break;
                case 0x87d9:
                  selectorEnumerant = *selectorBase;
                  switch(selectorEnumerant) {
                  case 0x87d5:
code_r0x0007ed7c:
                    selectorEnumerant = 0x87d9;
                    break;
                  case 0x87d6:
code_r0x0007ed70:
                    selectorEnumerant = 0x87da;
                    break;
                  case 0x87d7:
code_r0x0007eddc:
                    selectorEnumerant = 0x87db;
                    break;
                  case 0x87d8:
code_r0x0007edd0:
                    selectorEnumerant = 0x87dc;
                    break;
                  case 0x87d9:
code_r0x0007edc4:
                    selectorEnumerant = 0x87d5;
                    break;
                  case 0x87da:
code_r0x0007edb8:
                    selectorEnumerant = 0x87d6;
                    break;
                  case 0x87db:
code_r0x0007edac:
                    selectorEnumerant = 0x87d7;
                    break;
                  case 0x87dc:
code_r0x0007eda0:
                    selectorEnumerant = 0x87d8;
                    break;
                  case 0x87de:
code_r0x0007ed94:
                    selectorEnumerant = 0x87df;
                    break;
                  case 0x87df:
code_r0x0007ed88:
                    selectorEnumerant = 0x87de;
                  }
                  break;
                case 0x87da:
                  selectorEnumerant = *(undefined4 *)(movRecord + 0x2c);
                  switch(selectorEnumerant) {
                  case 0x87d5:
                    goto code_r0x0007ed7c;
                  case 0x87d6:
                    goto code_r0x0007ed70;
                  case 0x87d7:
                    goto code_r0x0007eddc;
                  case 0x87d8:
                    goto code_r0x0007edd0;
                  case 0x87d9:
                    goto code_r0x0007edc4;
                  case 0x87da:
                    goto code_r0x0007edb8;
                  case 0x87db:
                    goto code_r0x0007edac;
                  case 0x87dc:
                    goto code_r0x0007eda0;
                  case 0x87de:
                    goto code_r0x0007ed94;
                  case 0x87df:
                    goto code_r0x0007ed88;
                  }
                  break;
                case 0x87db:
                  selectorEnumerant = *(undefined4 *)(movRecord + 0x30);
                  switch(selectorEnumerant) {
                  case 0x87d5:
                    goto code_r0x0007ed7c;
                  case 0x87d6:
                    goto code_r0x0007ed70;
                  case 0x87d7:
                    goto code_r0x0007eddc;
                  case 0x87d8:
                    goto code_r0x0007edd0;
                  case 0x87d9:
                    goto code_r0x0007edc4;
                  case 0x87da:
                    goto code_r0x0007edb8;
                  case 0x87db:
                    goto code_r0x0007edac;
                  case 0x87dc:
                    goto code_r0x0007eda0;
                  case 0x87de:
                    goto code_r0x0007ed94;
                  case 0x87df:
                    goto code_r0x0007ed88;
                  }
                  break;
                case 0x87dc:
                  selectorEnumerant = *(undefined4 *)(movRecord + 0x34);
                  switch(selectorEnumerant) {
                  case 0x87d5:
                    goto code_r0x0007ed7c;
                  case 0x87d6:
                    goto code_r0x0007ed70;
                  case 0x87d7:
                    goto code_r0x0007eddc;
                  case 0x87d8:
                    goto code_r0x0007edd0;
                  case 0x87d9:
                    goto code_r0x0007edc4;
                  case 0x87da:
                    goto code_r0x0007edb8;
                  case 0x87db:
                    goto code_r0x0007edac;
                  case 0x87dc:
                    goto code_r0x0007eda0;
                  case 0x87de:
                    goto code_r0x0007ed94;
                  case 0x87df:
                    goto code_r0x0007ed88;
                  }
                }
                writerSrc0SelectorY = *(undefined4 *)(laterRecord + 0x2c);
                *(undefined4 *)(laterRecord + 0x28) = selectorEnumerant;
                switch(writerSrc0SelectorY) {
                case 0x87d5:
                  writerSrc0SelectorY = *selectorBase;
                  break;
                case 0x87d6:
                  writerSrc0SelectorY = *(undefined4 *)(movRecord + 0x2c);
                  break;
                case 0x87d7:
                  writerSrc0SelectorY = *(undefined4 *)(movRecord + 0x30);
                  break;
                case 0x87d8:
                  writerSrc0SelectorY = *(undefined4 *)(movRecord + 0x34);
                  break;
                case 0x87d9:
                  writerSrc0SelectorY = *selectorBase;
                  switch(writerSrc0SelectorY) {
                  case 0x87d5:
code_r0x0007efd4:
                    writerSrc0SelectorY = 0x87d9;
                    break;
                  case 0x87d6:
code_r0x0007efc8:
                    writerSrc0SelectorY = 0x87da;
                    break;
                  case 0x87d7:
code_r0x0007f034:
                    writerSrc0SelectorY = 0x87db;
                    break;
                  case 0x87d8:
code_r0x0007f028:
                    writerSrc0SelectorY = 0x87dc;
                    break;
                  case 0x87d9:
code_r0x0007f01c:
                    writerSrc0SelectorY = 0x87d5;
                    break;
                  case 0x87da:
code_r0x0007f010:
                    writerSrc0SelectorY = 0x87d6;
                    break;
                  case 0x87db:
code_r0x0007f004:
                    writerSrc0SelectorY = 0x87d7;
                    break;
                  case 0x87dc:
code_r0x0007eff8:
                    writerSrc0SelectorY = 0x87d8;
                    break;
                  case 0x87de:
code_r0x0007efec:
                    writerSrc0SelectorY = 0x87df;
                    break;
                  case 0x87df:
code_r0x0007efe0:
                    writerSrc0SelectorY = 0x87de;
                  }
                  break;
                case 0x87da:
                  writerSrc0SelectorY = *(undefined4 *)(movRecord + 0x2c);
                  switch(writerSrc0SelectorY) {
                  case 0x87d5:
                    goto code_r0x0007efd4;
                  case 0x87d6:
                    goto code_r0x0007efc8;
                  case 0x87d7:
                    goto code_r0x0007f034;
                  case 0x87d8:
                    goto code_r0x0007f028;
                  case 0x87d9:
                    goto code_r0x0007f01c;
                  case 0x87da:
                    goto code_r0x0007f010;
                  case 0x87db:
                    goto code_r0x0007f004;
                  case 0x87dc:
                    goto code_r0x0007eff8;
                  case 0x87de:
                    goto code_r0x0007efec;
                  case 0x87df:
                    goto code_r0x0007efe0;
                  }
                  break;
                case 0x87db:
                  writerSrc0SelectorY = *(undefined4 *)(movRecord + 0x30);
                  switch(writerSrc0SelectorY) {
                  case 0x87d5:
                    goto code_r0x0007efd4;
                  case 0x87d6:
                    goto code_r0x0007efc8;
                  case 0x87d7:
                    goto code_r0x0007f034;
                  case 0x87d8:
                    goto code_r0x0007f028;
                  case 0x87d9:
                    goto code_r0x0007f01c;
                  case 0x87da:
                    goto code_r0x0007f010;
                  case 0x87db:
                    goto code_r0x0007f004;
                  case 0x87dc:
                    goto code_r0x0007eff8;
                  case 0x87de:
                    goto code_r0x0007efec;
                  case 0x87df:
                    goto code_r0x0007efe0;
                  }
                  break;
                case 0x87dc:
                  writerSrc0SelectorY = *(undefined4 *)(movRecord + 0x34);
                  switch(writerSrc0SelectorY) {
                  case 0x87d5:
                    goto code_r0x0007efd4;
                  case 0x87d6:
                    goto code_r0x0007efc8;
                  case 0x87d7:
                    goto code_r0x0007f034;
                  case 0x87d8:
                    goto code_r0x0007f028;
                  case 0x87d9:
                    goto code_r0x0007f01c;
                  case 0x87da:
                    goto code_r0x0007f010;
                  case 0x87db:
                    goto code_r0x0007f004;
                  case 0x87dc:
                    goto code_r0x0007eff8;
                  case 0x87de:
                    goto code_r0x0007efec;
                  case 0x87df:
                    goto code_r0x0007efe0;
                  }
                }
                selectorEnumerant = *(undefined4 *)(laterRecord + 0x30);
                *(undefined4 *)(laterRecord + 0x2c) = writerSrc0SelectorY;
                switch(selectorEnumerant) {
                case 0x87d5:
                  selectorEnumerant = *selectorBase;
                  break;
                case 0x87d6:
                  selectorEnumerant = *(undefined4 *)(movRecord + 0x2c);
                  break;
                case 0x87d7:
                  selectorEnumerant = *(undefined4 *)(movRecord + 0x30);
                  break;
                case 0x87d8:
                  selectorEnumerant = *(undefined4 *)(movRecord + 0x34);
                  break;
                case 0x87d9:
                  selectorEnumerant = *selectorBase;
                  switch(selectorEnumerant) {
                  case 0x87d5:
code_r0x0007f22c:
                    selectorEnumerant = 0x87d9;
                    break;
                  case 0x87d6:
code_r0x0007f220:
                    selectorEnumerant = 0x87da;
                    break;
                  case 0x87d7:
code_r0x0007f28c:
                    selectorEnumerant = 0x87db;
                    break;
                  case 0x87d8:
code_r0x0007f280:
                    selectorEnumerant = 0x87dc;
                    break;
                  case 0x87d9:
code_r0x0007f274:
                    selectorEnumerant = 0x87d5;
                    break;
                  case 0x87da:
code_r0x0007f268:
                    selectorEnumerant = 0x87d6;
                    break;
                  case 0x87db:
code_r0x0007f25c:
                    selectorEnumerant = 0x87d7;
                    break;
                  case 0x87dc:
code_r0x0007f250:
                    selectorEnumerant = 0x87d8;
                    break;
                  case 0x87de:
code_r0x0007f244:
                    selectorEnumerant = 0x87df;
                    break;
                  case 0x87df:
code_r0x0007f238:
                    selectorEnumerant = 0x87de;
                  }
                  break;
                case 0x87da:
                  selectorEnumerant = *(undefined4 *)(movRecord + 0x2c);
                  switch(selectorEnumerant) {
                  case 0x87d5:
                    goto code_r0x0007f22c;
                  case 0x87d6:
                    goto code_r0x0007f220;
                  case 0x87d7:
                    goto code_r0x0007f28c;
                  case 0x87d8:
                    goto code_r0x0007f280;
                  case 0x87d9:
                    goto code_r0x0007f274;
                  case 0x87da:
                    goto code_r0x0007f268;
                  case 0x87db:
                    goto code_r0x0007f25c;
                  case 0x87dc:
                    goto code_r0x0007f250;
                  case 0x87de:
                    goto code_r0x0007f244;
                  case 0x87df:
                    goto code_r0x0007f238;
                  }
                  break;
                case 0x87db:
                  selectorEnumerant = *(undefined4 *)(movRecord + 0x30);
                  switch(selectorEnumerant) {
                  case 0x87d5:
                    goto code_r0x0007f22c;
                  case 0x87d6:
                    goto code_r0x0007f220;
                  case 0x87d7:
                    goto code_r0x0007f28c;
                  case 0x87d8:
                    goto code_r0x0007f280;
                  case 0x87d9:
                    goto code_r0x0007f274;
                  case 0x87da:
                    goto code_r0x0007f268;
                  case 0x87db:
                    goto code_r0x0007f25c;
                  case 0x87dc:
                    goto code_r0x0007f250;
                  case 0x87de:
                    goto code_r0x0007f244;
                  case 0x87df:
                    goto code_r0x0007f238;
                  }
                  break;
                case 0x87dc:
                  selectorEnumerant = *(undefined4 *)(movRecord + 0x34);
                  switch(selectorEnumerant) {
                  case 0x87d5:
                    goto code_r0x0007f22c;
                  case 0x87d6:
                    goto code_r0x0007f220;
                  case 0x87d7:
                    goto code_r0x0007f28c;
                  case 0x87d8:
                    goto code_r0x0007f280;
                  case 0x87d9:
                    goto code_r0x0007f274;
                  case 0x87da:
                    goto code_r0x0007f268;
                  case 0x87db:
                    goto code_r0x0007f25c;
                  case 0x87dc:
                    goto code_r0x0007f250;
                  case 0x87de:
                    goto code_r0x0007f244;
                  case 0x87df:
                    goto code_r0x0007f238;
                  }
                }
                writerSrc0SelectorW = *(undefined4 *)(laterRecord + 0x34);
                *(undefined4 *)(laterRecord + 0x30) = selectorEnumerant;
                switch(writerSrc0SelectorW) {
                case 0x87d5:
                  writerSrc0SelectorW = *selectorBase;
                  break;
                case 0x87d6:
                  writerSrc0SelectorW = *(undefined4 *)(movRecord + 0x2c);
                  break;
                case 0x87d7:
                  writerSrc0SelectorW = *(undefined4 *)(movRecord + 0x30);
                  break;
                case 0x87d8:
                  writerSrc0SelectorW = *(undefined4 *)(movRecord + 0x34);
                  break;
                case 0x87d9:
                  writerSrc0SelectorW = *selectorBase;
                  switch(writerSrc0SelectorW) {
                  case 0x87d5:
code_r0x0007f484:
                    writerSrc0SelectorW = 0x87d9;
                    break;
                  case 0x87d6:
code_r0x0007f478:
                    writerSrc0SelectorW = 0x87da;
                    break;
                  case 0x87d7:
code_r0x0007f4e4:
                    writerSrc0SelectorW = 0x87db;
                    break;
                  case 0x87d8:
code_r0x0007f4d8:
                    writerSrc0SelectorW = 0x87dc;
                    break;
                  case 0x87d9:
code_r0x0007f4cc:
                    writerSrc0SelectorW = 0x87d5;
                    break;
                  case 0x87da:
code_r0x0007f4c0:
                    writerSrc0SelectorW = 0x87d6;
                    break;
                  case 0x87db:
code_r0x0007f4b4:
                    writerSrc0SelectorW = 0x87d7;
                    break;
                  case 0x87dc:
code_r0x0007f4a8:
                    writerSrc0SelectorW = 0x87d8;
                    break;
                  case 0x87de:
code_r0x0007f49c:
                    writerSrc0SelectorW = 0x87df;
                    break;
                  case 0x87df:
code_r0x0007f490:
                    writerSrc0SelectorW = 0x87de;
                  }
                  break;
                case 0x87da:
                  writerSrc0SelectorW = *(undefined4 *)(movRecord + 0x2c);
                  switch(writerSrc0SelectorW) {
                  case 0x87d5:
                    goto code_r0x0007f484;
                  case 0x87d6:
                    goto code_r0x0007f478;
                  case 0x87d7:
                    goto code_r0x0007f4e4;
                  case 0x87d8:
                    goto code_r0x0007f4d8;
                  case 0x87d9:
                    goto code_r0x0007f4cc;
                  case 0x87da:
                    goto code_r0x0007f4c0;
                  case 0x87db:
                    goto code_r0x0007f4b4;
                  case 0x87dc:
                    goto code_r0x0007f4a8;
                  case 0x87de:
                    goto code_r0x0007f49c;
                  case 0x87df:
                    goto code_r0x0007f490;
                  }
                  break;
                case 0x87db:
                  writerSrc0SelectorW = *(undefined4 *)(movRecord + 0x30);
                  switch(writerSrc0SelectorW) {
                  case 0x87d5:
                    goto code_r0x0007f484;
                  case 0x87d6:
                    goto code_r0x0007f478;
                  case 0x87d7:
                    goto code_r0x0007f4e4;
                  case 0x87d8:
                    goto code_r0x0007f4d8;
                  case 0x87d9:
                    goto code_r0x0007f4cc;
                  case 0x87da:
                    goto code_r0x0007f4c0;
                  case 0x87db:
                    goto code_r0x0007f4b4;
                  case 0x87dc:
                    goto code_r0x0007f4a8;
                  case 0x87de:
                    goto code_r0x0007f49c;
                  case 0x87df:
                    goto code_r0x0007f490;
                  }
                  break;
                case 0x87dc:
                  writerSrc0SelectorW = *(undefined4 *)(movRecord + 0x34);
                  switch(writerSrc0SelectorW) {
                  case 0x87d5:
                    goto code_r0x0007f484;
                  case 0x87d6:
                    goto code_r0x0007f478;
                  case 0x87d7:
                    goto code_r0x0007f4e4;
                  case 0x87d8:
                    goto code_r0x0007f4d8;
                  case 0x87d9:
                    goto code_r0x0007f4cc;
                  case 0x87da:
                    goto code_r0x0007f4c0;
                  case 0x87db:
                    goto code_r0x0007f4b4;
                  case 0x87dc:
                    goto code_r0x0007f4a8;
                  case 0x87de:
                    goto code_r0x0007f49c;
                  case 0x87df:
                    goto code_r0x0007f490;
                  }
                }
                *(undefined4 *)(laterRecord + 0x34) = writerSrc0SelectorW;
              }
              if ((*(int *)(laterRecord + 0x3c) == 2) &&
                 (*(int *)(laterRecord + 0x40) == *(int *)(movRecord + 8))) {
                selectorEnumerant = *(undefined4 *)(laterRecord + 0x44);
                selectorBase = (undefined4 *)(movRecord + 0x28);
                *(undefined4 *)(laterRecord + 0x40) = *(undefined4 *)(movRecord + 0x24);
                switch(selectorEnumerant) {
                case 0x87d5:
                  selectorEnumerant = *selectorBase;
                  break;
                case 0x87d6:
                  selectorEnumerant = *(undefined4 *)(movRecord + 0x2c);
                  break;
                case 0x87d7:
                  selectorEnumerant = *(undefined4 *)(movRecord + 0x30);
                  break;
                case 0x87d8:
                  selectorEnumerant = *(undefined4 *)(movRecord + 0x34);
                  break;
                case 0x87d9:
                  selectorEnumerant = *selectorBase;
                  switch(selectorEnumerant) {
                  case 0x87d5:
code_r0x0007f708:
                    selectorEnumerant = 0x87d9;
                    break;
                  case 0x87d6:
code_r0x0007f6fc:
                    selectorEnumerant = 0x87da;
                    break;
                  case 0x87d7:
code_r0x0007f768:
                    selectorEnumerant = 0x87db;
                    break;
                  case 0x87d8:
code_r0x0007f75c:
                    selectorEnumerant = 0x87dc;
                    break;
                  case 0x87d9:
code_r0x0007f750:
                    selectorEnumerant = 0x87d5;
                    break;
                  case 0x87da:
code_r0x0007f744:
                    selectorEnumerant = 0x87d6;
                    break;
                  case 0x87db:
code_r0x0007f738:
                    selectorEnumerant = 0x87d7;
                    break;
                  case 0x87dc:
code_r0x0007f72c:
                    selectorEnumerant = 0x87d8;
                    break;
                  case 0x87de:
code_r0x0007f720:
                    selectorEnumerant = 0x87df;
                    break;
                  case 0x87df:
code_r0x0007f714:
                    selectorEnumerant = 0x87de;
                  }
                  break;
                case 0x87da:
                  selectorEnumerant = *(undefined4 *)(movRecord + 0x2c);
                  switch(selectorEnumerant) {
                  case 0x87d5:
                    goto code_r0x0007f708;
                  case 0x87d6:
                    goto code_r0x0007f6fc;
                  case 0x87d7:
                    goto code_r0x0007f768;
                  case 0x87d8:
                    goto code_r0x0007f75c;
                  case 0x87d9:
                    goto code_r0x0007f750;
                  case 0x87da:
                    goto code_r0x0007f744;
                  case 0x87db:
                    goto code_r0x0007f738;
                  case 0x87dc:
                    goto code_r0x0007f72c;
                  case 0x87de:
                    goto code_r0x0007f720;
                  case 0x87df:
                    goto code_r0x0007f714;
                  }
                  break;
                case 0x87db:
                  selectorEnumerant = *(undefined4 *)(movRecord + 0x30);
                  switch(selectorEnumerant) {
                  case 0x87d5:
                    goto code_r0x0007f708;
                  case 0x87d6:
                    goto code_r0x0007f6fc;
                  case 0x87d7:
                    goto code_r0x0007f768;
                  case 0x87d8:
                    goto code_r0x0007f75c;
                  case 0x87d9:
                    goto code_r0x0007f750;
                  case 0x87da:
                    goto code_r0x0007f744;
                  case 0x87db:
                    goto code_r0x0007f738;
                  case 0x87dc:
                    goto code_r0x0007f72c;
                  case 0x87de:
                    goto code_r0x0007f720;
                  case 0x87df:
                    goto code_r0x0007f714;
                  }
                  break;
                case 0x87dc:
                  selectorEnumerant = *(undefined4 *)(movRecord + 0x34);
                  switch(selectorEnumerant) {
                  case 0x87d5:
                    goto code_r0x0007f708;
                  case 0x87d6:
                    goto code_r0x0007f6fc;
                  case 0x87d7:
                    goto code_r0x0007f768;
                  case 0x87d8:
                    goto code_r0x0007f75c;
                  case 0x87d9:
                    goto code_r0x0007f750;
                  case 0x87da:
                    goto code_r0x0007f744;
                  case 0x87db:
                    goto code_r0x0007f738;
                  case 0x87dc:
                    goto code_r0x0007f72c;
                  case 0x87de:
                    goto code_r0x0007f720;
                  case 0x87df:
                    goto code_r0x0007f714;
                  }
                }
                writerSrc1SelectorY = *(undefined4 *)(laterRecord + 0x48);
                *(undefined4 *)(laterRecord + 0x44) = selectorEnumerant;
                switch(writerSrc1SelectorY) {
                case 0x87d5:
                  writerSrc1SelectorY = *selectorBase;
                  break;
                case 0x87d6:
                  writerSrc1SelectorY = *(undefined4 *)(movRecord + 0x2c);
                  break;
                case 0x87d7:
                  writerSrc1SelectorY = *(undefined4 *)(movRecord + 0x30);
                  break;
                case 0x87d8:
                  writerSrc1SelectorY = *(undefined4 *)(movRecord + 0x34);
                  break;
                case 0x87d9:
                  writerSrc1SelectorY = *selectorBase;
                  switch(writerSrc1SelectorY) {
                  case 0x87d5:
code_r0x0007f960:
                    writerSrc1SelectorY = 0x87d9;
                    break;
                  case 0x87d6:
code_r0x0007f954:
                    writerSrc1SelectorY = 0x87da;
                    break;
                  case 0x87d7:
code_r0x0007f9c0:
                    writerSrc1SelectorY = 0x87db;
                    break;
                  case 0x87d8:
code_r0x0007f9b4:
                    writerSrc1SelectorY = 0x87dc;
                    break;
                  case 0x87d9:
code_r0x0007f9a8:
                    writerSrc1SelectorY = 0x87d5;
                    break;
                  case 0x87da:
code_r0x0007f99c:
                    writerSrc1SelectorY = 0x87d6;
                    break;
                  case 0x87db:
code_r0x0007f990:
                    writerSrc1SelectorY = 0x87d7;
                    break;
                  case 0x87dc:
code_r0x0007f984:
                    writerSrc1SelectorY = 0x87d8;
                    break;
                  case 0x87de:
code_r0x0007f978:
                    writerSrc1SelectorY = 0x87df;
                    break;
                  case 0x87df:
code_r0x0007f96c:
                    writerSrc1SelectorY = 0x87de;
                  }
                  break;
                case 0x87da:
                  writerSrc1SelectorY = *(undefined4 *)(movRecord + 0x2c);
                  switch(writerSrc1SelectorY) {
                  case 0x87d5:
                    goto code_r0x0007f960;
                  case 0x87d6:
                    goto code_r0x0007f954;
                  case 0x87d7:
                    goto code_r0x0007f9c0;
                  case 0x87d8:
                    goto code_r0x0007f9b4;
                  case 0x87d9:
                    goto code_r0x0007f9a8;
                  case 0x87da:
                    goto code_r0x0007f99c;
                  case 0x87db:
                    goto code_r0x0007f990;
                  case 0x87dc:
                    goto code_r0x0007f984;
                  case 0x87de:
                    goto code_r0x0007f978;
                  case 0x87df:
                    goto code_r0x0007f96c;
                  }
                  break;
                case 0x87db:
                  writerSrc1SelectorY = *(undefined4 *)(movRecord + 0x30);
                  switch(writerSrc1SelectorY) {
                  case 0x87d5:
                    goto code_r0x0007f960;
                  case 0x87d6:
                    goto code_r0x0007f954;
                  case 0x87d7:
                    goto code_r0x0007f9c0;
                  case 0x87d8:
                    goto code_r0x0007f9b4;
                  case 0x87d9:
                    goto code_r0x0007f9a8;
                  case 0x87da:
                    goto code_r0x0007f99c;
                  case 0x87db:
                    goto code_r0x0007f990;
                  case 0x87dc:
                    goto code_r0x0007f984;
                  case 0x87de:
                    goto code_r0x0007f978;
                  case 0x87df:
                    goto code_r0x0007f96c;
                  }
                  break;
                case 0x87dc:
                  writerSrc1SelectorY = *(undefined4 *)(movRecord + 0x34);
                  switch(writerSrc1SelectorY) {
                  case 0x87d5:
                    goto code_r0x0007f960;
                  case 0x87d6:
                    goto code_r0x0007f954;
                  case 0x87d7:
                    goto code_r0x0007f9c0;
                  case 0x87d8:
                    goto code_r0x0007f9b4;
                  case 0x87d9:
                    goto code_r0x0007f9a8;
                  case 0x87da:
                    goto code_r0x0007f99c;
                  case 0x87db:
                    goto code_r0x0007f990;
                  case 0x87dc:
                    goto code_r0x0007f984;
                  case 0x87de:
                    goto code_r0x0007f978;
                  case 0x87df:
                    goto code_r0x0007f96c;
                  }
                }
                selectorEnumerant = *(undefined4 *)(laterRecord + 0x4c);
                *(undefined4 *)(laterRecord + 0x48) = writerSrc1SelectorY;
                switch(selectorEnumerant) {
                case 0x87d5:
                  selectorEnumerant = *selectorBase;
                  break;
                case 0x87d6:
                  selectorEnumerant = *(undefined4 *)(movRecord + 0x2c);
                  break;
                case 0x87d7:
                  selectorEnumerant = *(undefined4 *)(movRecord + 0x30);
                  break;
                case 0x87d8:
                  selectorEnumerant = *(undefined4 *)(movRecord + 0x34);
                  break;
                case 0x87d9:
                  selectorEnumerant = *selectorBase;
                  switch(selectorEnumerant) {
                  case 0x87d5:
code_r0x0007fbb8:
                    selectorEnumerant = 0x87d9;
                    break;
                  case 0x87d6:
code_r0x0007fbac:
                    selectorEnumerant = 0x87da;
                    break;
                  case 0x87d7:
code_r0x0007fc18:
                    selectorEnumerant = 0x87db;
                    break;
                  case 0x87d8:
code_r0x0007fc0c:
                    selectorEnumerant = 0x87dc;
                    break;
                  case 0x87d9:
code_r0x0007fc00:
                    selectorEnumerant = 0x87d5;
                    break;
                  case 0x87da:
code_r0x0007fbf4:
                    selectorEnumerant = 0x87d6;
                    break;
                  case 0x87db:
code_r0x0007fbe8:
                    selectorEnumerant = 0x87d7;
                    break;
                  case 0x87dc:
code_r0x0007fbdc:
                    selectorEnumerant = 0x87d8;
                    break;
                  case 0x87de:
code_r0x0007fbd0:
                    selectorEnumerant = 0x87df;
                    break;
                  case 0x87df:
code_r0x0007fbc4:
                    selectorEnumerant = 0x87de;
                  }
                  break;
                case 0x87da:
                  selectorEnumerant = *(undefined4 *)(movRecord + 0x2c);
                  switch(selectorEnumerant) {
                  case 0x87d5:
                    goto code_r0x0007fbb8;
                  case 0x87d6:
                    goto code_r0x0007fbac;
                  case 0x87d7:
                    goto code_r0x0007fc18;
                  case 0x87d8:
                    goto code_r0x0007fc0c;
                  case 0x87d9:
                    goto code_r0x0007fc00;
                  case 0x87da:
                    goto code_r0x0007fbf4;
                  case 0x87db:
                    goto code_r0x0007fbe8;
                  case 0x87dc:
                    goto code_r0x0007fbdc;
                  case 0x87de:
                    goto code_r0x0007fbd0;
                  case 0x87df:
                    goto code_r0x0007fbc4;
                  }
                  break;
                case 0x87db:
                  selectorEnumerant = *(undefined4 *)(movRecord + 0x30);
                  switch(selectorEnumerant) {
                  case 0x87d5:
                    goto code_r0x0007fbb8;
                  case 0x87d6:
                    goto code_r0x0007fbac;
                  case 0x87d7:
                    goto code_r0x0007fc18;
                  case 0x87d8:
                    goto code_r0x0007fc0c;
                  case 0x87d9:
                    goto code_r0x0007fc00;
                  case 0x87da:
                    goto code_r0x0007fbf4;
                  case 0x87db:
                    goto code_r0x0007fbe8;
                  case 0x87dc:
                    goto code_r0x0007fbdc;
                  case 0x87de:
                    goto code_r0x0007fbd0;
                  case 0x87df:
                    goto code_r0x0007fbc4;
                  }
                  break;
                case 0x87dc:
                  selectorEnumerant = *(undefined4 *)(movRecord + 0x34);
                  switch(selectorEnumerant) {
                  case 0x87d5:
                    goto code_r0x0007fbb8;
                  case 0x87d6:
                    goto code_r0x0007fbac;
                  case 0x87d7:
                    goto code_r0x0007fc18;
                  case 0x87d8:
                    goto code_r0x0007fc0c;
                  case 0x87d9:
                    goto code_r0x0007fc00;
                  case 0x87da:
                    goto code_r0x0007fbf4;
                  case 0x87db:
                    goto code_r0x0007fbe8;
                  case 0x87dc:
                    goto code_r0x0007fbdc;
                  case 0x87de:
                    goto code_r0x0007fbd0;
                  case 0x87df:
                    goto code_r0x0007fbc4;
                  }
                }
                writerSrc1SelectorW = *(undefined4 *)(laterRecord + 0x50);
                *(undefined4 *)(laterRecord + 0x4c) = selectorEnumerant;
                switch(writerSrc1SelectorW) {
                case 0x87d5:
                  writerSrc1SelectorW = *selectorBase;
                  break;
                case 0x87d6:
                  writerSrc1SelectorW = *(undefined4 *)(movRecord + 0x2c);
                  break;
                case 0x87d7:
                  writerSrc1SelectorW = *(undefined4 *)(movRecord + 0x30);
                  break;
                case 0x87d8:
                  writerSrc1SelectorW = *(undefined4 *)(movRecord + 0x34);
                  break;
                case 0x87d9:
                  writerSrc1SelectorW = *selectorBase;
                  switch(writerSrc1SelectorW) {
                  case 0x87d5:
code_r0x0007fe10:
                    writerSrc1SelectorW = 0x87d9;
                    break;
                  case 0x87d6:
code_r0x0007fe04:
                    writerSrc1SelectorW = 0x87da;
                    break;
                  case 0x87d7:
code_r0x0007fe70:
                    writerSrc1SelectorW = 0x87db;
                    break;
                  case 0x87d8:
code_r0x0007fe64:
                    writerSrc1SelectorW = 0x87dc;
                    break;
                  case 0x87d9:
code_r0x0007fe58:
                    writerSrc1SelectorW = 0x87d5;
                    break;
                  case 0x87da:
code_r0x0007fe4c:
                    writerSrc1SelectorW = 0x87d6;
                    break;
                  case 0x87db:
code_r0x0007fe40:
                    writerSrc1SelectorW = 0x87d7;
                    break;
                  case 0x87dc:
code_r0x0007fe34:
                    writerSrc1SelectorW = 0x87d8;
                    break;
                  case 0x87de:
code_r0x0007fe28:
                    writerSrc1SelectorW = 0x87df;
                    break;
                  case 0x87df:
code_r0x0007fe1c:
                    writerSrc1SelectorW = 0x87de;
                  }
                  break;
                case 0x87da:
                  writerSrc1SelectorW = *(undefined4 *)(movRecord + 0x2c);
                  switch(writerSrc1SelectorW) {
                  case 0x87d5:
                    goto code_r0x0007fe10;
                  case 0x87d6:
                    goto code_r0x0007fe04;
                  case 0x87d7:
                    goto code_r0x0007fe70;
                  case 0x87d8:
                    goto code_r0x0007fe64;
                  case 0x87d9:
                    goto code_r0x0007fe58;
                  case 0x87da:
                    goto code_r0x0007fe4c;
                  case 0x87db:
                    goto code_r0x0007fe40;
                  case 0x87dc:
                    goto code_r0x0007fe34;
                  case 0x87de:
                    goto code_r0x0007fe28;
                  case 0x87df:
                    goto code_r0x0007fe1c;
                  }
                  break;
                case 0x87db:
                  writerSrc1SelectorW = *(undefined4 *)(movRecord + 0x30);
                  switch(writerSrc1SelectorW) {
                  case 0x87d5:
                    goto code_r0x0007fe10;
                  case 0x87d6:
                    goto code_r0x0007fe04;
                  case 0x87d7:
                    goto code_r0x0007fe70;
                  case 0x87d8:
                    goto code_r0x0007fe64;
                  case 0x87d9:
                    goto code_r0x0007fe58;
                  case 0x87da:
                    goto code_r0x0007fe4c;
                  case 0x87db:
                    goto code_r0x0007fe40;
                  case 0x87dc:
                    goto code_r0x0007fe34;
                  case 0x87de:
                    goto code_r0x0007fe28;
                  case 0x87df:
                    goto code_r0x0007fe1c;
                  }
                  break;
                case 0x87dc:
                  writerSrc1SelectorW = *(undefined4 *)(movRecord + 0x34);
                  switch(writerSrc1SelectorW) {
                  case 0x87d5:
                    goto code_r0x0007fe10;
                  case 0x87d6:
                    goto code_r0x0007fe04;
                  case 0x87d7:
                    goto code_r0x0007fe70;
                  case 0x87d8:
                    goto code_r0x0007fe64;
                  case 0x87d9:
                    goto code_r0x0007fe58;
                  case 0x87da:
                    goto code_r0x0007fe4c;
                  case 0x87db:
                    goto code_r0x0007fe40;
                  case 0x87dc:
                    goto code_r0x0007fe34;
                  case 0x87de:
                    goto code_r0x0007fe28;
                  case 0x87df:
                    goto code_r0x0007fe1c;
                  }
                }
                *(undefined4 *)(laterRecord + 0x50) = writerSrc1SelectorW;
              }
              if ((*(int *)(laterRecord + 0x58) == 2) &&
                 (*(int *)(laterRecord + 0x5c) == *(int *)(movRecord + 8))) {
                selectorEnumerant = *(undefined4 *)(laterRecord + 0x60);
                selectorBase = (undefined4 *)(movRecord + 0x28);
                *(undefined4 *)(laterRecord + 0x5c) = *(undefined4 *)(movRecord + 0x24);
                switch(selectorEnumerant) {
                case 0x87d5:
                  selectorEnumerant = *selectorBase;
                  break;
                case 0x87d6:
                  selectorEnumerant = *(undefined4 *)(movRecord + 0x2c);
                  break;
                case 0x87d7:
                  selectorEnumerant = *(undefined4 *)(movRecord + 0x30);
                  break;
                case 0x87d8:
                  selectorEnumerant = *(undefined4 *)(movRecord + 0x34);
                  break;
                case 0x87d9:
                  selectorEnumerant = *selectorBase;
                  switch(selectorEnumerant) {
                  case 0x87d5:
code_r0x00080094:
                    selectorEnumerant = 0x87d9;
                    break;
                  case 0x87d6:
code_r0x00080088:
                    selectorEnumerant = 0x87da;
                    break;
                  case 0x87d7:
code_r0x000800f4:
                    selectorEnumerant = 0x87db;
                    break;
                  case 0x87d8:
code_r0x000800e8:
                    selectorEnumerant = 0x87dc;
                    break;
                  case 0x87d9:
code_r0x000800dc:
                    selectorEnumerant = 0x87d5;
                    break;
                  case 0x87da:
code_r0x000800d0:
                    selectorEnumerant = 0x87d6;
                    break;
                  case 0x87db:
code_r0x000800c4:
                    selectorEnumerant = 0x87d7;
                    break;
                  case 0x87dc:
code_r0x000800b8:
                    selectorEnumerant = 0x87d8;
                    break;
                  case 0x87de:
code_r0x000800ac:
                    selectorEnumerant = 0x87df;
                    break;
                  case 0x87df:
code_r0x000800a0:
                    selectorEnumerant = 0x87de;
                  }
                  break;
                case 0x87da:
                  selectorEnumerant = *(undefined4 *)(movRecord + 0x2c);
                  switch(selectorEnumerant) {
                  case 0x87d5:
                    goto code_r0x00080094;
                  case 0x87d6:
                    goto code_r0x00080088;
                  case 0x87d7:
                    goto code_r0x000800f4;
                  case 0x87d8:
                    goto code_r0x000800e8;
                  case 0x87d9:
                    goto code_r0x000800dc;
                  case 0x87da:
                    goto code_r0x000800d0;
                  case 0x87db:
                    goto code_r0x000800c4;
                  case 0x87dc:
                    goto code_r0x000800b8;
                  case 0x87de:
                    goto code_r0x000800ac;
                  case 0x87df:
                    goto code_r0x000800a0;
                  }
                  break;
                case 0x87db:
                  selectorEnumerant = *(undefined4 *)(movRecord + 0x30);
                  switch(selectorEnumerant) {
                  case 0x87d5:
                    goto code_r0x00080094;
                  case 0x87d6:
                    goto code_r0x00080088;
                  case 0x87d7:
                    goto code_r0x000800f4;
                  case 0x87d8:
                    goto code_r0x000800e8;
                  case 0x87d9:
                    goto code_r0x000800dc;
                  case 0x87da:
                    goto code_r0x000800d0;
                  case 0x87db:
                    goto code_r0x000800c4;
                  case 0x87dc:
                    goto code_r0x000800b8;
                  case 0x87de:
                    goto code_r0x000800ac;
                  case 0x87df:
                    goto code_r0x000800a0;
                  }
                  break;
                case 0x87dc:
                  selectorEnumerant = *(undefined4 *)(movRecord + 0x34);
                  switch(selectorEnumerant) {
                  case 0x87d5:
                    goto code_r0x00080094;
                  case 0x87d6:
                    goto code_r0x00080088;
                  case 0x87d7:
                    goto code_r0x000800f4;
                  case 0x87d8:
                    goto code_r0x000800e8;
                  case 0x87d9:
                    goto code_r0x000800dc;
                  case 0x87da:
                    goto code_r0x000800d0;
                  case 0x87db:
                    goto code_r0x000800c4;
                  case 0x87dc:
                    goto code_r0x000800b8;
                  case 0x87de:
                    goto code_r0x000800ac;
                  case 0x87df:
                    goto code_r0x000800a0;
                  }
                }
                writerSrc2SelectorY = *(undefined4 *)(laterRecord + 100);
                *(undefined4 *)(laterRecord + 0x60) = selectorEnumerant;
                switch(writerSrc2SelectorY) {
                case 0x87d5:
                  writerSrc2SelectorY = *selectorBase;
                  break;
                case 0x87d6:
                  writerSrc2SelectorY = *(undefined4 *)(movRecord + 0x2c);
                  break;
                case 0x87d7:
                  writerSrc2SelectorY = *(undefined4 *)(movRecord + 0x30);
                  break;
                case 0x87d8:
                  writerSrc2SelectorY = *(undefined4 *)(movRecord + 0x34);
                  break;
                case 0x87d9:
                  writerSrc2SelectorY = *selectorBase;
                  switch(writerSrc2SelectorY) {
                  case 0x87d5:
code_r0x000802ec:
                    writerSrc2SelectorY = 0x87d9;
                    break;
                  case 0x87d6:
code_r0x000802e0:
                    writerSrc2SelectorY = 0x87da;
                    break;
                  case 0x87d7:
code_r0x0008034c:
                    writerSrc2SelectorY = 0x87db;
                    break;
                  case 0x87d8:
code_r0x00080340:
                    writerSrc2SelectorY = 0x87dc;
                    break;
                  case 0x87d9:
code_r0x00080334:
                    writerSrc2SelectorY = 0x87d5;
                    break;
                  case 0x87da:
code_r0x00080328:
                    writerSrc2SelectorY = 0x87d6;
                    break;
                  case 0x87db:
code_r0x0008031c:
                    writerSrc2SelectorY = 0x87d7;
                    break;
                  case 0x87dc:
code_r0x00080310:
                    writerSrc2SelectorY = 0x87d8;
                    break;
                  case 0x87de:
code_r0x00080304:
                    writerSrc2SelectorY = 0x87df;
                    break;
                  case 0x87df:
code_r0x000802f8:
                    writerSrc2SelectorY = 0x87de;
                  }
                  break;
                case 0x87da:
                  writerSrc2SelectorY = *(undefined4 *)(movRecord + 0x2c);
                  switch(writerSrc2SelectorY) {
                  case 0x87d5:
                    goto code_r0x000802ec;
                  case 0x87d6:
                    goto code_r0x000802e0;
                  case 0x87d7:
                    goto code_r0x0008034c;
                  case 0x87d8:
                    goto code_r0x00080340;
                  case 0x87d9:
                    goto code_r0x00080334;
                  case 0x87da:
                    goto code_r0x00080328;
                  case 0x87db:
                    goto code_r0x0008031c;
                  case 0x87dc:
                    goto code_r0x00080310;
                  case 0x87de:
                    goto code_r0x00080304;
                  case 0x87df:
                    goto code_r0x000802f8;
                  }
                  break;
                case 0x87db:
                  writerSrc2SelectorY = *(undefined4 *)(movRecord + 0x30);
                  switch(writerSrc2SelectorY) {
                  case 0x87d5:
                    goto code_r0x000802ec;
                  case 0x87d6:
                    goto code_r0x000802e0;
                  case 0x87d7:
                    goto code_r0x0008034c;
                  case 0x87d8:
                    goto code_r0x00080340;
                  case 0x87d9:
                    goto code_r0x00080334;
                  case 0x87da:
                    goto code_r0x00080328;
                  case 0x87db:
                    goto code_r0x0008031c;
                  case 0x87dc:
                    goto code_r0x00080310;
                  case 0x87de:
                    goto code_r0x00080304;
                  case 0x87df:
                    goto code_r0x000802f8;
                  }
                  break;
                case 0x87dc:
                  writerSrc2SelectorY = *(undefined4 *)(movRecord + 0x34);
                  switch(writerSrc2SelectorY) {
                  case 0x87d5:
                    goto code_r0x000802ec;
                  case 0x87d6:
                    goto code_r0x000802e0;
                  case 0x87d7:
                    goto code_r0x0008034c;
                  case 0x87d8:
                    goto code_r0x00080340;
                  case 0x87d9:
                    goto code_r0x00080334;
                  case 0x87da:
                    goto code_r0x00080328;
                  case 0x87db:
                    goto code_r0x0008031c;
                  case 0x87dc:
                    goto code_r0x00080310;
                  case 0x87de:
                    goto code_r0x00080304;
                  case 0x87df:
                    goto code_r0x000802f8;
                  }
                }
                selectorEnumerant = *(undefined4 *)(laterRecord + 0x68);
                *(undefined4 *)(laterRecord + 100) = writerSrc2SelectorY;
                switch(selectorEnumerant) {
                case 0x87d5:
                  selectorEnumerant = *selectorBase;
                  break;
                case 0x87d6:
                  selectorEnumerant = *(undefined4 *)(movRecord + 0x2c);
                  break;
                case 0x87d7:
                  selectorEnumerant = *(undefined4 *)(movRecord + 0x30);
                  break;
                case 0x87d8:
                  selectorEnumerant = *(undefined4 *)(movRecord + 0x34);
                  break;
                case 0x87d9:
                  selectorEnumerant = *selectorBase;
                  switch(selectorEnumerant) {
                  case 0x87d5:
code_r0x00080544:
                    selectorEnumerant = 0x87d9;
                    break;
                  case 0x87d6:
code_r0x00080538:
                    selectorEnumerant = 0x87da;
                    break;
                  case 0x87d7:
code_r0x000805a4:
                    selectorEnumerant = 0x87db;
                    break;
                  case 0x87d8:
code_r0x00080598:
                    selectorEnumerant = 0x87dc;
                    break;
                  case 0x87d9:
code_r0x0008058c:
                    selectorEnumerant = 0x87d5;
                    break;
                  case 0x87da:
code_r0x00080580:
                    selectorEnumerant = 0x87d6;
                    break;
                  case 0x87db:
code_r0x00080574:
                    selectorEnumerant = 0x87d7;
                    break;
                  case 0x87dc:
code_r0x00080568:
                    selectorEnumerant = 0x87d8;
                    break;
                  case 0x87de:
code_r0x0008055c:
                    selectorEnumerant = 0x87df;
                    break;
                  case 0x87df:
code_r0x00080550:
                    selectorEnumerant = 0x87de;
                  }
                  break;
                case 0x87da:
                  selectorEnumerant = *(undefined4 *)(movRecord + 0x2c);
                  switch(selectorEnumerant) {
                  case 0x87d5:
                    goto code_r0x00080544;
                  case 0x87d6:
                    goto code_r0x00080538;
                  case 0x87d7:
                    goto code_r0x000805a4;
                  case 0x87d8:
                    goto code_r0x00080598;
                  case 0x87d9:
                    goto code_r0x0008058c;
                  case 0x87da:
                    goto code_r0x00080580;
                  case 0x87db:
                    goto code_r0x00080574;
                  case 0x87dc:
                    goto code_r0x00080568;
                  case 0x87de:
                    goto code_r0x0008055c;
                  case 0x87df:
                    goto code_r0x00080550;
                  }
                  break;
                case 0x87db:
                  selectorEnumerant = *(undefined4 *)(movRecord + 0x30);
                  switch(selectorEnumerant) {
                  case 0x87d5:
                    goto code_r0x00080544;
                  case 0x87d6:
                    goto code_r0x00080538;
                  case 0x87d7:
                    goto code_r0x000805a4;
                  case 0x87d8:
                    goto code_r0x00080598;
                  case 0x87d9:
                    goto code_r0x0008058c;
                  case 0x87da:
                    goto code_r0x00080580;
                  case 0x87db:
                    goto code_r0x00080574;
                  case 0x87dc:
                    goto code_r0x00080568;
                  case 0x87de:
                    goto code_r0x0008055c;
                  case 0x87df:
                    goto code_r0x00080550;
                  }
                  break;
                case 0x87dc:
                  selectorEnumerant = *(undefined4 *)(movRecord + 0x34);
                  switch(selectorEnumerant) {
                  case 0x87d5:
                    goto code_r0x00080544;
                  case 0x87d6:
                    goto code_r0x00080538;
                  case 0x87d7:
                    goto code_r0x000805a4;
                  case 0x87d8:
                    goto code_r0x00080598;
                  case 0x87d9:
                    goto code_r0x0008058c;
                  case 0x87da:
                    goto code_r0x00080580;
                  case 0x87db:
                    goto code_r0x00080574;
                  case 0x87dc:
                    goto code_r0x00080568;
                  case 0x87de:
                    goto code_r0x0008055c;
                  case 0x87df:
                    goto code_r0x00080550;
                  }
                }
                writerSrc2SelectorW = *(undefined4 *)(laterRecord + 0x6c);
                *(undefined4 *)(laterRecord + 0x68) = selectorEnumerant;
                switch(writerSrc2SelectorW) {
                case 0x87d5:
                  writerSrc2SelectorW = *selectorBase;
                  break;
                case 0x87d6:
                  writerSrc2SelectorW = *(undefined4 *)(movRecord + 0x2c);
                  break;
                case 0x87d7:
                  writerSrc2SelectorW = *(undefined4 *)(movRecord + 0x30);
                  break;
                case 0x87d8:
                  writerSrc2SelectorW = *(undefined4 *)(movRecord + 0x34);
                  break;
                case 0x87d9:
                  writerSrc2SelectorW = *selectorBase;
                  switch(writerSrc2SelectorW) {
                  case 0x87d5:
code_r0x0008079c:
                    writerSrc2SelectorW = 0x87d9;
                    break;
                  case 0x87d6:
code_r0x00080790:
                    writerSrc2SelectorW = 0x87da;
                    break;
                  case 0x87d7:
code_r0x000807fc:
                    writerSrc2SelectorW = 0x87db;
                    break;
                  case 0x87d8:
code_r0x000807f0:
                    writerSrc2SelectorW = 0x87dc;
                    break;
                  case 0x87d9:
code_r0x000807e4:
                    writerSrc2SelectorW = 0x87d5;
                    break;
                  case 0x87da:
code_r0x000807d8:
                    writerSrc2SelectorW = 0x87d6;
                    break;
                  case 0x87db:
code_r0x000807cc:
                    writerSrc2SelectorW = 0x87d7;
                    break;
                  case 0x87dc:
code_r0x000807c0:
                    writerSrc2SelectorW = 0x87d8;
                    break;
                  case 0x87de:
code_r0x000807b4:
                    writerSrc2SelectorW = 0x87df;
                    break;
                  case 0x87df:
code_r0x000807a8:
                    writerSrc2SelectorW = 0x87de;
                  }
                  break;
                case 0x87da:
                  writerSrc2SelectorW = *(undefined4 *)(movRecord + 0x2c);
                  switch(writerSrc2SelectorW) {
                  case 0x87d5:
                    goto code_r0x0008079c;
                  case 0x87d6:
                    goto code_r0x00080790;
                  case 0x87d7:
                    goto code_r0x000807fc;
                  case 0x87d8:
                    goto code_r0x000807f0;
                  case 0x87d9:
                    goto code_r0x000807e4;
                  case 0x87da:
                    goto code_r0x000807d8;
                  case 0x87db:
                    goto code_r0x000807cc;
                  case 0x87dc:
                    goto code_r0x000807c0;
                  case 0x87de:
                    goto code_r0x000807b4;
                  case 0x87df:
                    goto code_r0x000807a8;
                  }
                  break;
                case 0x87db:
                  writerSrc2SelectorW = *(undefined4 *)(movRecord + 0x30);
                  switch(writerSrc2SelectorW) {
                  case 0x87d5:
                    goto code_r0x0008079c;
                  case 0x87d6:
                    goto code_r0x00080790;
                  case 0x87d7:
                    goto code_r0x000807fc;
                  case 0x87d8:
                    goto code_r0x000807f0;
                  case 0x87d9:
                    goto code_r0x000807e4;
                  case 0x87da:
                    goto code_r0x000807d8;
                  case 0x87db:
                    goto code_r0x000807cc;
                  case 0x87dc:
                    goto code_r0x000807c0;
                  case 0x87de:
                    goto code_r0x000807b4;
                  case 0x87df:
                    goto code_r0x000807a8;
                  }
                  break;
                case 0x87dc:
                  writerSrc2SelectorW = *(undefined4 *)(movRecord + 0x34);
                  switch(writerSrc2SelectorW) {
                  case 0x87d5:
                    goto code_r0x0008079c;
                  case 0x87d6:
                    goto code_r0x00080790;
                  case 0x87d7:
                    goto code_r0x000807fc;
                  case 0x87d8:
                    goto code_r0x000807f0;
                  case 0x87d9:
                    goto code_r0x000807e4;
                  case 0x87da:
                    goto code_r0x000807d8;
                  case 0x87db:
                    goto code_r0x000807cc;
                  case 0x87dc:
                    goto code_r0x000807c0;
                  case 0x87de:
                    goto code_r0x000807b4;
                  case 0x87df:
                    goto code_r0x000807a8;
                  }
                }
                *(undefined4 *)(laterRecord + 0x6c) = writerSrc2SelectorW;
              }
              instructions = instructions + -1;
              currentInstruction = currentInstruction + 0x74;
            } while (instructions != 0);
            instructionCount = *(uint *)(shaderProgram + 0x14);
          }
          instructionCount = instructionCount - 1;
          *(uint *)(shaderProgram + 0x14) = instructionCount;
          uVar18 = uVar30;
          if (uVar30 < instructionCount) {
            do {
              uVar18 = uVar18 + 1;
              instructions = symbol + *(int *)(shaderProgram + 0x18);
              symbol = symbol + 0x74;
              _memcpy(instructions,instructions + 0x74,0x74);
              instructionCount = *(uint *)(shaderProgram + 0x14);
            } while (uVar18 < instructionCount);
          }
          bVar33 = true;
        }
LAB_00080860:
        uVar30 = uVar30 + 1;
      } while (uVar30 < instructionCount);
    }
  } while (bVar33);
  instructionIndex = 0;
  if (instructionCount != 0) {
    instructions = instructionCount * 0x74;
    instructionIndex = 0;
    do {
      uVar30 = instructionCount - instructionIndex;
      currentInstruction = instructions + *(int *)(shaderProgram + 0x18);
      if (((*(int *)(currentInstruction + -0x74) == 0x879d) && (*(int *)(currentInstruction + -0x70) == 2)) &&
         (symbol = extvsOperandDataType(shaderProgram + 0x1c,currentInstruction + -0x54), symbol == 0x87bf)) {
        uVar18 = *(uint *)(shaderProgram + 0x14);
        if (uVar30 < uVar18) {
          symbol = uVar18 - uVar30;
          bVar34 = true;
          bVar33 = false;
          laterSlotCursor = (int *)(instructions + *(int *)(shaderProgram + 0x18) + 4);
          do {
            if ((*laterSlotCursor != 2) || (laterSlotCursor[1] != *(int *)(currentInstruction + -0x6c))) {
              if (bVar33) {
                if ((((laterSlotCursor[7] == 2) && (laterSlotCursor[8] == *(int *)(currentInstruction + -0x6c))) ||
                    ((laterSlotCursor[0xe] == 2 && (laterSlotCursor[0xf] == *(int *)(currentInstruction + -0x6c))))) ||
                   ((laterSlotCursor[0x15] == 2 && (laterSlotCursor[0x16] == *(int *)(currentInstruction + -0x6c)))))
                goto code_r0x00080a40;
                bVar35 = false;
              }
              else {
                if (((*laterSlotCursor == 2) && (*(int *)(currentInstruction + -0x54) == 2)) &&
                   (laterSlotCursor[1] == *(int *)(currentInstruction + -0x50))) {
                  movRecord = *(int *)(currentInstruction + -0x34);
                  if (movRecord == 0) {
                    movRecord = laterSlotCursor[2];
                  }
                  else if (movRecord == 1) {
                    movRecord = laterSlotCursor[3];
                  }
                  else if (movRecord == 2) {
                    movRecord = laterSlotCursor[4];
                  }
                  else {
                    if (movRecord != 3) goto code_r0x000809ec;
                    movRecord = laterSlotCursor[5];
                  }
                  if (movRecord != 0) {
                    bVar35 = false;
                    bVar33 = true;
                    goto code_r0x00080a54;
                  }
                }
code_r0x000809ec:
                bVar35 = false;
                bVar33 = false;
              }
            }
            else if (((laterSlotCursor[2] == 0) || (laterSlotCursor[3] == 0)) ||
                    ((laterSlotCursor[4] == 0 || (bVar35 = true, laterSlotCursor[5] == 0)))) {
code_r0x00080a40:
              bVar35 = true;
              bVar34 = false;
            }
code_r0x00080a54:
            symbol = symbol + -1;
          } while ((symbol != 0) && (laterSlotCursor = laterSlotCursor + 0x1d, !bVar35));
          if (!bVar34) goto code_r0x00082600;
        }
        symbol = *(int *)(currentInstruction + -0x34);
        if (symbol == 1) {
          selectorEnumerant = *(undefined4 *)(currentInstruction + -0x48);
        }
        else if (symbol == 0) {
          selectorEnumerant = *(undefined4 *)(currentInstruction + -0x4c);
        }
        else if (symbol == 2) {
          selectorEnumerant = *(undefined4 *)(currentInstruction + -0x44);
        }
        else {
          selectorEnumerant = *(undefined4 *)(currentInstruction + -0x40);
        }
        symbol = instructions;
        writeEnableX = uVar30;
        if (uVar30 < uVar18) {
          do {
            movRecord = symbol + *(int *)(shaderProgram + 0x18);
            if ((*(int *)(movRecord + 0x20) != 2) ||
               (*(int *)(movRecord + 0x24) != *(int *)(currentInstruction + -0x6c))) goto code_r0x000813a8;
            *(undefined4 *)(movRecord + 0x24) = *(undefined4 *)(currentInstruction + -0x50);
            candidateSrc0SelectorX = *(undefined4 *)(movRecord + 0x28);
            switch(*(undefined4 *)(movRecord + 0x28)) {
            case 0x87d5:
            case 0x87d6:
            case 0x87d7:
            case 0x87d8:
              break;
            case 0x87d9:
              switch(selectorEnumerant) {
              case 0x87d5:
code_r0x00080cac:
                candidateSrc0SelectorX = 0x87d9;
                break;
              case 0x87d6:
code_r0x00080ca0:
                candidateSrc0SelectorX = 0x87da;
                break;
              case 0x87d7:
code_r0x00080d0c:
                candidateSrc0SelectorX = 0x87db;
                break;
              case 0x87d8:
code_r0x00080d00:
                candidateSrc0SelectorX = 0x87dc;
                break;
              case 0x87d9:
code_r0x00080cf4:
                candidateSrc0SelectorX = 0x87d5;
                break;
              case 0x87da:
code_r0x00080ce8:
                candidateSrc0SelectorX = 0x87d6;
                break;
              case 0x87db:
code_r0x00080cdc:
                candidateSrc0SelectorX = 0x87d7;
                break;
              case 0x87dc:
code_r0x00080cd0:
                candidateSrc0SelectorX = 0x87d8;
                break;
              default:
                goto code_r0x00080c98;
              case 0x87de:
code_r0x00080cc4:
                candidateSrc0SelectorX = 0x87df;
                break;
              case 0x87df:
code_r0x00080cb8:
                candidateSrc0SelectorX = 0x87de;
              }
              goto code_r0x00080d14;
            case 0x87da:
              switch(selectorEnumerant) {
              case 0x87d5:
                goto code_r0x00080cac;
              case 0x87d6:
                goto code_r0x00080ca0;
              case 0x87d7:
                goto code_r0x00080d0c;
              case 0x87d8:
                goto code_r0x00080d00;
              case 0x87d9:
                goto code_r0x00080cf4;
              case 0x87da:
                goto code_r0x00080ce8;
              case 0x87db:
                goto code_r0x00080cdc;
              case 0x87dc:
                goto code_r0x00080cd0;
              case 0x87de:
                goto code_r0x00080cc4;
              case 0x87df:
                goto code_r0x00080cb8;
              }
              break;
            case 0x87db:
              switch(selectorEnumerant) {
              case 0x87d5:
                goto code_r0x00080cac;
              case 0x87d6:
                goto code_r0x00080ca0;
              case 0x87d7:
                goto code_r0x00080d0c;
              case 0x87d8:
                goto code_r0x00080d00;
              case 0x87d9:
                goto code_r0x00080cf4;
              case 0x87da:
                goto code_r0x00080ce8;
              case 0x87db:
                goto code_r0x00080cdc;
              case 0x87dc:
                goto code_r0x00080cd0;
              case 0x87de:
                goto code_r0x00080cc4;
              case 0x87df:
                goto code_r0x00080cb8;
              }
              break;
            case 0x87dc:
              switch(selectorEnumerant) {
              case 0x87d5:
                goto code_r0x00080cac;
              case 0x87d6:
                goto code_r0x00080ca0;
              case 0x87d7:
                goto code_r0x00080d0c;
              case 0x87d8:
                goto code_r0x00080d00;
              case 0x87d9:
                goto code_r0x00080cf4;
              case 0x87da:
                goto code_r0x00080ce8;
              case 0x87db:
                goto code_r0x00080cdc;
              case 0x87dc:
                goto code_r0x00080cd0;
              case 0x87de:
                goto code_r0x00080cc4;
              case 0x87df:
                goto code_r0x00080cb8;
              }
              break;
            default:
              goto code_r0x00080d14;
            }
code_r0x00080c98:
            candidateSrc0SelectorX = selectorEnumerant;
code_r0x00080d14:
            *(undefined4 *)(movRecord + 0x28) = candidateSrc0SelectorX;
            candidateSrc0SelectorY = *(undefined4 *)(movRecord + 0x2c);
            switch(*(undefined4 *)(movRecord + 0x2c)) {
            case 0x87d5:
            case 0x87d6:
            case 0x87d7:
            case 0x87d8:
              break;
            case 0x87d9:
              switch(selectorEnumerant) {
              case 0x87d5:
code_r0x00080edc:
                candidateSrc0SelectorY = 0x87d9;
                break;
              case 0x87d6:
code_r0x00080ed0:
                candidateSrc0SelectorY = 0x87da;
                break;
              case 0x87d7:
code_r0x00080f3c:
                candidateSrc0SelectorY = 0x87db;
                break;
              case 0x87d8:
code_r0x00080f30:
                candidateSrc0SelectorY = 0x87dc;
                break;
              case 0x87d9:
code_r0x00080f24:
                candidateSrc0SelectorY = 0x87d5;
                break;
              case 0x87da:
code_r0x00080f18:
                candidateSrc0SelectorY = 0x87d6;
                break;
              case 0x87db:
code_r0x00080f0c:
                candidateSrc0SelectorY = 0x87d7;
                break;
              case 0x87dc:
code_r0x00080f00:
                candidateSrc0SelectorY = 0x87d8;
                break;
              default:
                goto code_r0x00080ec8;
              case 0x87de:
code_r0x00080ef4:
                candidateSrc0SelectorY = 0x87df;
                break;
              case 0x87df:
code_r0x00080ee8:
                candidateSrc0SelectorY = 0x87de;
              }
              goto code_r0x00080f44;
            case 0x87da:
              switch(selectorEnumerant) {
              case 0x87d5:
                goto code_r0x00080edc;
              case 0x87d6:
                goto code_r0x00080ed0;
              case 0x87d7:
                goto code_r0x00080f3c;
              case 0x87d8:
                goto code_r0x00080f30;
              case 0x87d9:
                goto code_r0x00080f24;
              case 0x87da:
                goto code_r0x00080f18;
              case 0x87db:
                goto code_r0x00080f0c;
              case 0x87dc:
                goto code_r0x00080f00;
              case 0x87de:
                goto code_r0x00080ef4;
              case 0x87df:
                goto code_r0x00080ee8;
              }
              break;
            case 0x87db:
              switch(selectorEnumerant) {
              case 0x87d5:
                goto code_r0x00080edc;
              case 0x87d6:
                goto code_r0x00080ed0;
              case 0x87d7:
                goto code_r0x00080f3c;
              case 0x87d8:
                goto code_r0x00080f30;
              case 0x87d9:
                goto code_r0x00080f24;
              case 0x87da:
                goto code_r0x00080f18;
              case 0x87db:
                goto code_r0x00080f0c;
              case 0x87dc:
                goto code_r0x00080f00;
              case 0x87de:
                goto code_r0x00080ef4;
              case 0x87df:
                goto code_r0x00080ee8;
              }
              break;
            case 0x87dc:
              switch(selectorEnumerant) {
              case 0x87d5:
                goto code_r0x00080edc;
              case 0x87d6:
                goto code_r0x00080ed0;
              case 0x87d7:
                goto code_r0x00080f3c;
              case 0x87d8:
                goto code_r0x00080f30;
              case 0x87d9:
                goto code_r0x00080f24;
              case 0x87da:
                goto code_r0x00080f18;
              case 0x87db:
                goto code_r0x00080f0c;
              case 0x87dc:
                goto code_r0x00080f00;
              case 0x87de:
                goto code_r0x00080ef4;
              case 0x87df:
                goto code_r0x00080ee8;
              }
              break;
            default:
              goto code_r0x00080f44;
            }
code_r0x00080ec8:
            candidateSrc0SelectorY = selectorEnumerant;
code_r0x00080f44:
            *(undefined4 *)(movRecord + 0x2c) = candidateSrc0SelectorY;
            candidateSrc0SelectorZ = *(undefined4 *)(movRecord + 0x30);
            switch(*(undefined4 *)(movRecord + 0x30)) {
            case 0x87d5:
            case 0x87d6:
            case 0x87d7:
            case 0x87d8:
              break;
            case 0x87d9:
              switch(selectorEnumerant) {
              case 0x87d5:
code_r0x0008110c:
                candidateSrc0SelectorZ = 0x87d9;
                break;
              case 0x87d6:
code_r0x00081100:
                candidateSrc0SelectorZ = 0x87da;
                break;
              case 0x87d7:
code_r0x0008116c:
                candidateSrc0SelectorZ = 0x87db;
                break;
              case 0x87d8:
code_r0x00081160:
                candidateSrc0SelectorZ = 0x87dc;
                break;
              case 0x87d9:
code_r0x00081154:
                candidateSrc0SelectorZ = 0x87d5;
                break;
              case 0x87da:
code_r0x00081148:
                candidateSrc0SelectorZ = 0x87d6;
                break;
              case 0x87db:
code_r0x0008113c:
                candidateSrc0SelectorZ = 0x87d7;
                break;
              case 0x87dc:
code_r0x00081130:
                candidateSrc0SelectorZ = 0x87d8;
                break;
              default:
                goto code_r0x000810f8;
              case 0x87de:
code_r0x00081124:
                candidateSrc0SelectorZ = 0x87df;
                break;
              case 0x87df:
code_r0x00081118:
                candidateSrc0SelectorZ = 0x87de;
              }
              goto code_r0x00081174;
            case 0x87da:
              switch(selectorEnumerant) {
              case 0x87d5:
                goto code_r0x0008110c;
              case 0x87d6:
                goto code_r0x00081100;
              case 0x87d7:
                goto code_r0x0008116c;
              case 0x87d8:
                goto code_r0x00081160;
              case 0x87d9:
                goto code_r0x00081154;
              case 0x87da:
                goto code_r0x00081148;
              case 0x87db:
                goto code_r0x0008113c;
              case 0x87dc:
                goto code_r0x00081130;
              case 0x87de:
                goto code_r0x00081124;
              case 0x87df:
                goto code_r0x00081118;
              }
              break;
            case 0x87db:
              switch(selectorEnumerant) {
              case 0x87d5:
                goto code_r0x0008110c;
              case 0x87d6:
                goto code_r0x00081100;
              case 0x87d7:
                goto code_r0x0008116c;
              case 0x87d8:
                goto code_r0x00081160;
              case 0x87d9:
                goto code_r0x00081154;
              case 0x87da:
                goto code_r0x00081148;
              case 0x87db:
                goto code_r0x0008113c;
              case 0x87dc:
                goto code_r0x00081130;
              case 0x87de:
                goto code_r0x00081124;
              case 0x87df:
                goto code_r0x00081118;
              }
              break;
            case 0x87dc:
              switch(selectorEnumerant) {
              case 0x87d5:
                goto code_r0x0008110c;
              case 0x87d6:
                goto code_r0x00081100;
              case 0x87d7:
                goto code_r0x0008116c;
              case 0x87d8:
                goto code_r0x00081160;
              case 0x87d9:
                goto code_r0x00081154;
              case 0x87da:
                goto code_r0x00081148;
              case 0x87db:
                goto code_r0x0008113c;
              case 0x87dc:
                goto code_r0x00081130;
              case 0x87de:
                goto code_r0x00081124;
              case 0x87df:
                goto code_r0x00081118;
              }
              break;
            default:
              goto code_r0x00081174;
            }
code_r0x000810f8:
            candidateSrc0SelectorZ = selectorEnumerant;
code_r0x00081174:
            *(undefined4 *)(movRecord + 0x30) = candidateSrc0SelectorZ;
            candidateSrc0SelectorW = *(undefined4 *)(movRecord + 0x34);
            switch(*(undefined4 *)(movRecord + 0x34)) {
            case 0x87d5:
            case 0x87d6:
            case 0x87d7:
            case 0x87d8:
              break;
            case 0x87d9:
              switch(selectorEnumerant) {
              case 0x87d5:
code_r0x0008133c:
                candidateSrc0SelectorW = 0x87d9;
                break;
              case 0x87d6:
code_r0x00081330:
                candidateSrc0SelectorW = 0x87da;
                break;
              case 0x87d7:
code_r0x0008139c:
                candidateSrc0SelectorW = 0x87db;
                break;
              case 0x87d8:
code_r0x00081390:
                candidateSrc0SelectorW = 0x87dc;
                break;
              case 0x87d9:
code_r0x00081384:
                candidateSrc0SelectorW = 0x87d5;
                break;
              case 0x87da:
code_r0x00081378:
                candidateSrc0SelectorW = 0x87d6;
                break;
              case 0x87db:
code_r0x0008136c:
                candidateSrc0SelectorW = 0x87d7;
                break;
              case 0x87dc:
code_r0x00081360:
                candidateSrc0SelectorW = 0x87d8;
                break;
              default:
                goto code_r0x00081328;
              case 0x87de:
code_r0x00081354:
                candidateSrc0SelectorW = 0x87df;
                break;
              case 0x87df:
code_r0x00081348:
                candidateSrc0SelectorW = 0x87de;
              }
              goto code_r0x000813a4;
            case 0x87da:
              switch(selectorEnumerant) {
              case 0x87d5:
                goto code_r0x0008133c;
              case 0x87d6:
                goto code_r0x00081330;
              case 0x87d7:
                goto code_r0x0008139c;
              case 0x87d8:
                goto code_r0x00081390;
              case 0x87d9:
                goto code_r0x00081384;
              case 0x87da:
                goto code_r0x00081378;
              case 0x87db:
                goto code_r0x0008136c;
              case 0x87dc:
                goto code_r0x00081360;
              case 0x87de:
                goto code_r0x00081354;
              case 0x87df:
                goto code_r0x00081348;
              }
              break;
            case 0x87db:
              switch(selectorEnumerant) {
              case 0x87d5:
                goto code_r0x0008133c;
              case 0x87d6:
                goto code_r0x00081330;
              case 0x87d7:
                goto code_r0x0008139c;
              case 0x87d8:
                goto code_r0x00081390;
              case 0x87d9:
                goto code_r0x00081384;
              case 0x87da:
                goto code_r0x00081378;
              case 0x87db:
                goto code_r0x0008136c;
              case 0x87dc:
                goto code_r0x00081360;
              case 0x87de:
                goto code_r0x00081354;
              case 0x87df:
                goto code_r0x00081348;
              }
              break;
            case 0x87dc:
              switch(selectorEnumerant) {
              case 0x87d5:
                goto code_r0x0008133c;
              case 0x87d6:
                goto code_r0x00081330;
              case 0x87d7:
                goto code_r0x0008139c;
              case 0x87d8:
                goto code_r0x00081390;
              case 0x87d9:
                goto code_r0x00081384;
              case 0x87da:
                goto code_r0x00081378;
              case 0x87db:
                goto code_r0x0008136c;
              case 0x87dc:
                goto code_r0x00081360;
              case 0x87de:
                goto code_r0x00081354;
              case 0x87df:
                goto code_r0x00081348;
              }
              break;
            default:
              goto code_r0x000813a4;
            }
code_r0x00081328:
            candidateSrc0SelectorW = selectorEnumerant;
code_r0x000813a4:
            *(undefined4 *)(movRecord + 0x34) = candidateSrc0SelectorW;
code_r0x000813a8:
            if ((*(int *)(movRecord + 0x3c) != 2) ||
               (*(int *)(movRecord + 0x40) != *(int *)(currentInstruction + -0x6c))) goto code_r0x00081c90;
            *(undefined4 *)(movRecord + 0x40) = *(undefined4 *)(currentInstruction + -0x50);
            candidateSrc1SelectorX = *(undefined4 *)(movRecord + 0x44);
            switch(*(undefined4 *)(movRecord + 0x44)) {
            case 0x87d5:
            case 0x87d6:
            case 0x87d7:
            case 0x87d8:
              break;
            case 0x87d9:
              switch(selectorEnumerant) {
              case 0x87d5:
code_r0x00081594:
                candidateSrc1SelectorX = 0x87d9;
                break;
              case 0x87d6:
code_r0x00081588:
                candidateSrc1SelectorX = 0x87da;
                break;
              case 0x87d7:
code_r0x000815f4:
                candidateSrc1SelectorX = 0x87db;
                break;
              case 0x87d8:
code_r0x000815e8:
                candidateSrc1SelectorX = 0x87dc;
                break;
              case 0x87d9:
code_r0x000815dc:
                candidateSrc1SelectorX = 0x87d5;
                break;
              case 0x87da:
code_r0x000815d0:
                candidateSrc1SelectorX = 0x87d6;
                break;
              case 0x87db:
code_r0x000815c4:
                candidateSrc1SelectorX = 0x87d7;
                break;
              case 0x87dc:
code_r0x000815b8:
                candidateSrc1SelectorX = 0x87d8;
                break;
              default:
                goto code_r0x00081580;
              case 0x87de:
code_r0x000815ac:
                candidateSrc1SelectorX = 0x87df;
                break;
              case 0x87df:
code_r0x000815a0:
                candidateSrc1SelectorX = 0x87de;
              }
              goto code_r0x000815fc;
            case 0x87da:
              switch(selectorEnumerant) {
              case 0x87d5:
                goto code_r0x00081594;
              case 0x87d6:
                goto code_r0x00081588;
              case 0x87d7:
                goto code_r0x000815f4;
              case 0x87d8:
                goto code_r0x000815e8;
              case 0x87d9:
                goto code_r0x000815dc;
              case 0x87da:
                goto code_r0x000815d0;
              case 0x87db:
                goto code_r0x000815c4;
              case 0x87dc:
                goto code_r0x000815b8;
              case 0x87de:
                goto code_r0x000815ac;
              case 0x87df:
                goto code_r0x000815a0;
              }
              break;
            case 0x87db:
              switch(selectorEnumerant) {
              case 0x87d5:
                goto code_r0x00081594;
              case 0x87d6:
                goto code_r0x00081588;
              case 0x87d7:
                goto code_r0x000815f4;
              case 0x87d8:
                goto code_r0x000815e8;
              case 0x87d9:
                goto code_r0x000815dc;
              case 0x87da:
                goto code_r0x000815d0;
              case 0x87db:
                goto code_r0x000815c4;
              case 0x87dc:
                goto code_r0x000815b8;
              case 0x87de:
                goto code_r0x000815ac;
              case 0x87df:
                goto code_r0x000815a0;
              }
              break;
            case 0x87dc:
              switch(selectorEnumerant) {
              case 0x87d5:
                goto code_r0x00081594;
              case 0x87d6:
                goto code_r0x00081588;
              case 0x87d7:
                goto code_r0x000815f4;
              case 0x87d8:
                goto code_r0x000815e8;
              case 0x87d9:
                goto code_r0x000815dc;
              case 0x87da:
                goto code_r0x000815d0;
              case 0x87db:
                goto code_r0x000815c4;
              case 0x87dc:
                goto code_r0x000815b8;
              case 0x87de:
                goto code_r0x000815ac;
              case 0x87df:
                goto code_r0x000815a0;
              }
              break;
            default:
              goto code_r0x000815fc;
            }
code_r0x00081580:
            candidateSrc1SelectorX = selectorEnumerant;
code_r0x000815fc:
            *(undefined4 *)(movRecord + 0x44) = candidateSrc1SelectorX;
            candidateSrc1SelectorY = *(undefined4 *)(movRecord + 0x48);
            switch(*(undefined4 *)(movRecord + 0x48)) {
            case 0x87d5:
            case 0x87d6:
            case 0x87d7:
            case 0x87d8:
              break;
            case 0x87d9:
              switch(selectorEnumerant) {
              case 0x87d5:
code_r0x000817c4:
                candidateSrc1SelectorY = 0x87d9;
                break;
              case 0x87d6:
code_r0x000817b8:
                candidateSrc1SelectorY = 0x87da;
                break;
              case 0x87d7:
code_r0x00081824:
                candidateSrc1SelectorY = 0x87db;
                break;
              case 0x87d8:
code_r0x00081818:
                candidateSrc1SelectorY = 0x87dc;
                break;
              case 0x87d9:
code_r0x0008180c:
                candidateSrc1SelectorY = 0x87d5;
                break;
              case 0x87da:
code_r0x00081800:
                candidateSrc1SelectorY = 0x87d6;
                break;
              case 0x87db:
code_r0x000817f4:
                candidateSrc1SelectorY = 0x87d7;
                break;
              case 0x87dc:
code_r0x000817e8:
                candidateSrc1SelectorY = 0x87d8;
                break;
              default:
                goto code_r0x000817b0;
              case 0x87de:
code_r0x000817dc:
                candidateSrc1SelectorY = 0x87df;
                break;
              case 0x87df:
code_r0x000817d0:
                candidateSrc1SelectorY = 0x87de;
              }
              goto code_r0x0008182c;
            case 0x87da:
              switch(selectorEnumerant) {
              case 0x87d5:
                goto code_r0x000817c4;
              case 0x87d6:
                goto code_r0x000817b8;
              case 0x87d7:
                goto code_r0x00081824;
              case 0x87d8:
                goto code_r0x00081818;
              case 0x87d9:
                goto code_r0x0008180c;
              case 0x87da:
                goto code_r0x00081800;
              case 0x87db:
                goto code_r0x000817f4;
              case 0x87dc:
                goto code_r0x000817e8;
              case 0x87de:
                goto code_r0x000817dc;
              case 0x87df:
                goto code_r0x000817d0;
              }
              break;
            case 0x87db:
              switch(selectorEnumerant) {
              case 0x87d5:
                goto code_r0x000817c4;
              case 0x87d6:
                goto code_r0x000817b8;
              case 0x87d7:
                goto code_r0x00081824;
              case 0x87d8:
                goto code_r0x00081818;
              case 0x87d9:
                goto code_r0x0008180c;
              case 0x87da:
                goto code_r0x00081800;
              case 0x87db:
                goto code_r0x000817f4;
              case 0x87dc:
                goto code_r0x000817e8;
              case 0x87de:
                goto code_r0x000817dc;
              case 0x87df:
                goto code_r0x000817d0;
              }
              break;
            case 0x87dc:
              switch(selectorEnumerant) {
              case 0x87d5:
                goto code_r0x000817c4;
              case 0x87d6:
                goto code_r0x000817b8;
              case 0x87d7:
                goto code_r0x00081824;
              case 0x87d8:
                goto code_r0x00081818;
              case 0x87d9:
                goto code_r0x0008180c;
              case 0x87da:
                goto code_r0x00081800;
              case 0x87db:
                goto code_r0x000817f4;
              case 0x87dc:
                goto code_r0x000817e8;
              case 0x87de:
                goto code_r0x000817dc;
              case 0x87df:
                goto code_r0x000817d0;
              }
              break;
            default:
              goto code_r0x0008182c;
            }
code_r0x000817b0:
            candidateSrc1SelectorY = selectorEnumerant;
code_r0x0008182c:
            *(undefined4 *)(movRecord + 0x48) = candidateSrc1SelectorY;
            candidateSrc1SelectorZ = *(undefined4 *)(movRecord + 0x4c);
            switch(*(undefined4 *)(movRecord + 0x4c)) {
            case 0x87d5:
            case 0x87d6:
            case 0x87d7:
            case 0x87d8:
              break;
            case 0x87d9:
              switch(selectorEnumerant) {
              case 0x87d5:
code_r0x000819f4:
                candidateSrc1SelectorZ = 0x87d9;
                break;
              case 0x87d6:
code_r0x000819e8:
                candidateSrc1SelectorZ = 0x87da;
                break;
              case 0x87d7:
code_r0x00081a54:
                candidateSrc1SelectorZ = 0x87db;
                break;
              case 0x87d8:
code_r0x00081a48:
                candidateSrc1SelectorZ = 0x87dc;
                break;
              case 0x87d9:
code_r0x00081a3c:
                candidateSrc1SelectorZ = 0x87d5;
                break;
              case 0x87da:
code_r0x00081a30:
                candidateSrc1SelectorZ = 0x87d6;
                break;
              case 0x87db:
code_r0x00081a24:
                candidateSrc1SelectorZ = 0x87d7;
                break;
              case 0x87dc:
code_r0x00081a18:
                candidateSrc1SelectorZ = 0x87d8;
                break;
              default:
                goto code_r0x000819e0;
              case 0x87de:
code_r0x00081a0c:
                candidateSrc1SelectorZ = 0x87df;
                break;
              case 0x87df:
code_r0x00081a00:
                candidateSrc1SelectorZ = 0x87de;
              }
              goto code_r0x00081a5c;
            case 0x87da:
              switch(selectorEnumerant) {
              case 0x87d5:
                goto code_r0x000819f4;
              case 0x87d6:
                goto code_r0x000819e8;
              case 0x87d7:
                goto code_r0x00081a54;
              case 0x87d8:
                goto code_r0x00081a48;
              case 0x87d9:
                goto code_r0x00081a3c;
              case 0x87da:
                goto code_r0x00081a30;
              case 0x87db:
                goto code_r0x00081a24;
              case 0x87dc:
                goto code_r0x00081a18;
              case 0x87de:
                goto code_r0x00081a0c;
              case 0x87df:
                goto code_r0x00081a00;
              }
              break;
            case 0x87db:
              switch(selectorEnumerant) {
              case 0x87d5:
                goto code_r0x000819f4;
              case 0x87d6:
                goto code_r0x000819e8;
              case 0x87d7:
                goto code_r0x00081a54;
              case 0x87d8:
                goto code_r0x00081a48;
              case 0x87d9:
                goto code_r0x00081a3c;
              case 0x87da:
                goto code_r0x00081a30;
              case 0x87db:
                goto code_r0x00081a24;
              case 0x87dc:
                goto code_r0x00081a18;
              case 0x87de:
                goto code_r0x00081a0c;
              case 0x87df:
                goto code_r0x00081a00;
              }
              break;
            case 0x87dc:
              switch(selectorEnumerant) {
              case 0x87d5:
                goto code_r0x000819f4;
              case 0x87d6:
                goto code_r0x000819e8;
              case 0x87d7:
                goto code_r0x00081a54;
              case 0x87d8:
                goto code_r0x00081a48;
              case 0x87d9:
                goto code_r0x00081a3c;
              case 0x87da:
                goto code_r0x00081a30;
              case 0x87db:
                goto code_r0x00081a24;
              case 0x87dc:
                goto code_r0x00081a18;
              case 0x87de:
                goto code_r0x00081a0c;
              case 0x87df:
                goto code_r0x00081a00;
              }
              break;
            default:
              goto code_r0x00081a5c;
            }
code_r0x000819e0:
            candidateSrc1SelectorZ = selectorEnumerant;
code_r0x00081a5c:
            *(undefined4 *)(movRecord + 0x4c) = candidateSrc1SelectorZ;
            candidateSrc1SelectorW = *(undefined4 *)(movRecord + 0x50);
            switch(*(undefined4 *)(movRecord + 0x50)) {
            case 0x87d5:
            case 0x87d6:
            case 0x87d7:
            case 0x87d8:
              break;
            case 0x87d9:
              switch(selectorEnumerant) {
              case 0x87d5:
code_r0x00081c24:
                candidateSrc1SelectorW = 0x87d9;
                break;
              case 0x87d6:
code_r0x00081c18:
                candidateSrc1SelectorW = 0x87da;
                break;
              case 0x87d7:
code_r0x00081c84:
                candidateSrc1SelectorW = 0x87db;
                break;
              case 0x87d8:
code_r0x00081c78:
                candidateSrc1SelectorW = 0x87dc;
                break;
              case 0x87d9:
code_r0x00081c6c:
                candidateSrc1SelectorW = 0x87d5;
                break;
              case 0x87da:
code_r0x00081c60:
                candidateSrc1SelectorW = 0x87d6;
                break;
              case 0x87db:
code_r0x00081c54:
                candidateSrc1SelectorW = 0x87d7;
                break;
              case 0x87dc:
code_r0x00081c48:
                candidateSrc1SelectorW = 0x87d8;
                break;
              default:
                goto code_r0x00081c10;
              case 0x87de:
code_r0x00081c3c:
                candidateSrc1SelectorW = 0x87df;
                break;
              case 0x87df:
code_r0x00081c30:
                candidateSrc1SelectorW = 0x87de;
              }
              goto code_r0x00081c8c;
            case 0x87da:
              switch(selectorEnumerant) {
              case 0x87d5:
                goto code_r0x00081c24;
              case 0x87d6:
                goto code_r0x00081c18;
              case 0x87d7:
                goto code_r0x00081c84;
              case 0x87d8:
                goto code_r0x00081c78;
              case 0x87d9:
                goto code_r0x00081c6c;
              case 0x87da:
                goto code_r0x00081c60;
              case 0x87db:
                goto code_r0x00081c54;
              case 0x87dc:
                goto code_r0x00081c48;
              case 0x87de:
                goto code_r0x00081c3c;
              case 0x87df:
                goto code_r0x00081c30;
              }
              break;
            case 0x87db:
              switch(selectorEnumerant) {
              case 0x87d5:
                goto code_r0x00081c24;
              case 0x87d6:
                goto code_r0x00081c18;
              case 0x87d7:
                goto code_r0x00081c84;
              case 0x87d8:
                goto code_r0x00081c78;
              case 0x87d9:
                goto code_r0x00081c6c;
              case 0x87da:
                goto code_r0x00081c60;
              case 0x87db:
                goto code_r0x00081c54;
              case 0x87dc:
                goto code_r0x00081c48;
              case 0x87de:
                goto code_r0x00081c3c;
              case 0x87df:
                goto code_r0x00081c30;
              }
              break;
            case 0x87dc:
              switch(selectorEnumerant) {
              case 0x87d5:
                goto code_r0x00081c24;
              case 0x87d6:
                goto code_r0x00081c18;
              case 0x87d7:
                goto code_r0x00081c84;
              case 0x87d8:
                goto code_r0x00081c78;
              case 0x87d9:
                goto code_r0x00081c6c;
              case 0x87da:
                goto code_r0x00081c60;
              case 0x87db:
                goto code_r0x00081c54;
              case 0x87dc:
                goto code_r0x00081c48;
              case 0x87de:
                goto code_r0x00081c3c;
              case 0x87df:
                goto code_r0x00081c30;
              }
              break;
            default:
              goto code_r0x00081c8c;
            }
code_r0x00081c10:
            candidateSrc1SelectorW = selectorEnumerant;
code_r0x00081c8c:
            *(undefined4 *)(movRecord + 0x50) = candidateSrc1SelectorW;
code_r0x00081c90:
            if ((*(int *)(movRecord + 0x58) != 2) ||
               (*(int *)(movRecord + 0x5c) != *(int *)(currentInstruction + -0x6c))) goto code_r0x00082578;
            *(undefined4 *)(movRecord + 0x5c) = *(undefined4 *)(currentInstruction + -0x50);
            candidateSrc2SelectorX = *(undefined4 *)(movRecord + 0x60);
            switch(*(undefined4 *)(movRecord + 0x60)) {
            case 0x87d5:
            case 0x87d6:
            case 0x87d7:
            case 0x87d8:
              break;
            case 0x87d9:
              switch(selectorEnumerant) {
              case 0x87d5:
code_r0x00081e7c:
                candidateSrc2SelectorX = 0x87d9;
                break;
              case 0x87d6:
code_r0x00081e70:
                candidateSrc2SelectorX = 0x87da;
                break;
              case 0x87d7:
code_r0x00081edc:
                candidateSrc2SelectorX = 0x87db;
                break;
              case 0x87d8:
code_r0x00081ed0:
                candidateSrc2SelectorX = 0x87dc;
                break;
              case 0x87d9:
code_r0x00081ec4:
                candidateSrc2SelectorX = 0x87d5;
                break;
              case 0x87da:
code_r0x00081eb8:
                candidateSrc2SelectorX = 0x87d6;
                break;
              case 0x87db:
code_r0x00081eac:
                candidateSrc2SelectorX = 0x87d7;
                break;
              case 0x87dc:
code_r0x00081ea0:
                candidateSrc2SelectorX = 0x87d8;
                break;
              default:
                goto code_r0x00081e68;
              case 0x87de:
code_r0x00081e94:
                candidateSrc2SelectorX = 0x87df;
                break;
              case 0x87df:
code_r0x00081e88:
                candidateSrc2SelectorX = 0x87de;
              }
              goto code_r0x00081ee4;
            case 0x87da:
              switch(selectorEnumerant) {
              case 0x87d5:
                goto code_r0x00081e7c;
              case 0x87d6:
                goto code_r0x00081e70;
              case 0x87d7:
                goto code_r0x00081edc;
              case 0x87d8:
                goto code_r0x00081ed0;
              case 0x87d9:
                goto code_r0x00081ec4;
              case 0x87da:
                goto code_r0x00081eb8;
              case 0x87db:
                goto code_r0x00081eac;
              case 0x87dc:
                goto code_r0x00081ea0;
              case 0x87de:
                goto code_r0x00081e94;
              case 0x87df:
                goto code_r0x00081e88;
              }
              break;
            case 0x87db:
              switch(selectorEnumerant) {
              case 0x87d5:
                goto code_r0x00081e7c;
              case 0x87d6:
                goto code_r0x00081e70;
              case 0x87d7:
                goto code_r0x00081edc;
              case 0x87d8:
                goto code_r0x00081ed0;
              case 0x87d9:
                goto code_r0x00081ec4;
              case 0x87da:
                goto code_r0x00081eb8;
              case 0x87db:
                goto code_r0x00081eac;
              case 0x87dc:
                goto code_r0x00081ea0;
              case 0x87de:
                goto code_r0x00081e94;
              case 0x87df:
                goto code_r0x00081e88;
              }
              break;
            case 0x87dc:
              switch(selectorEnumerant) {
              case 0x87d5:
                goto code_r0x00081e7c;
              case 0x87d6:
                goto code_r0x00081e70;
              case 0x87d7:
                goto code_r0x00081edc;
              case 0x87d8:
                goto code_r0x00081ed0;
              case 0x87d9:
                goto code_r0x00081ec4;
              case 0x87da:
                goto code_r0x00081eb8;
              case 0x87db:
                goto code_r0x00081eac;
              case 0x87dc:
                goto code_r0x00081ea0;
              case 0x87de:
                goto code_r0x00081e94;
              case 0x87df:
                goto code_r0x00081e88;
              }
              break;
            default:
              goto code_r0x00081ee4;
            }
code_r0x00081e68:
            candidateSrc2SelectorX = selectorEnumerant;
code_r0x00081ee4:
            *(undefined4 *)(movRecord + 0x60) = candidateSrc2SelectorX;
            candidateSrc2SelectorY = *(undefined4 *)(movRecord + 100);
            switch(*(undefined4 *)(movRecord + 100)) {
            case 0x87d5:
            case 0x87d6:
            case 0x87d7:
            case 0x87d8:
              break;
            case 0x87d9:
              switch(selectorEnumerant) {
              case 0x87d5:
code_r0x000820ac:
                candidateSrc2SelectorY = 0x87d9;
                break;
              case 0x87d6:
code_r0x000820a0:
                candidateSrc2SelectorY = 0x87da;
                break;
              case 0x87d7:
code_r0x0008210c:
                candidateSrc2SelectorY = 0x87db;
                break;
              case 0x87d8:
code_r0x00082100:
                candidateSrc2SelectorY = 0x87dc;
                break;
              case 0x87d9:
code_r0x000820f4:
                candidateSrc2SelectorY = 0x87d5;
                break;
              case 0x87da:
code_r0x000820e8:
                candidateSrc2SelectorY = 0x87d6;
                break;
              case 0x87db:
code_r0x000820dc:
                candidateSrc2SelectorY = 0x87d7;
                break;
              case 0x87dc:
code_r0x000820d0:
                candidateSrc2SelectorY = 0x87d8;
                break;
              default:
                goto code_r0x00082098;
              case 0x87de:
code_r0x000820c4:
                candidateSrc2SelectorY = 0x87df;
                break;
              case 0x87df:
code_r0x000820b8:
                candidateSrc2SelectorY = 0x87de;
              }
              goto code_r0x00082114;
            case 0x87da:
              switch(selectorEnumerant) {
              case 0x87d5:
                goto code_r0x000820ac;
              case 0x87d6:
                goto code_r0x000820a0;
              case 0x87d7:
                goto code_r0x0008210c;
              case 0x87d8:
                goto code_r0x00082100;
              case 0x87d9:
                goto code_r0x000820f4;
              case 0x87da:
                goto code_r0x000820e8;
              case 0x87db:
                goto code_r0x000820dc;
              case 0x87dc:
                goto code_r0x000820d0;
              case 0x87de:
                goto code_r0x000820c4;
              case 0x87df:
                goto code_r0x000820b8;
              }
              break;
            case 0x87db:
              switch(selectorEnumerant) {
              case 0x87d5:
                goto code_r0x000820ac;
              case 0x87d6:
                goto code_r0x000820a0;
              case 0x87d7:
                goto code_r0x0008210c;
              case 0x87d8:
                goto code_r0x00082100;
              case 0x87d9:
                goto code_r0x000820f4;
              case 0x87da:
                goto code_r0x000820e8;
              case 0x87db:
                goto code_r0x000820dc;
              case 0x87dc:
                goto code_r0x000820d0;
              case 0x87de:
                goto code_r0x000820c4;
              case 0x87df:
                goto code_r0x000820b8;
              }
              break;
            case 0x87dc:
              switch(selectorEnumerant) {
              case 0x87d5:
                goto code_r0x000820ac;
              case 0x87d6:
                goto code_r0x000820a0;
              case 0x87d7:
                goto code_r0x0008210c;
              case 0x87d8:
                goto code_r0x00082100;
              case 0x87d9:
                goto code_r0x000820f4;
              case 0x87da:
                goto code_r0x000820e8;
              case 0x87db:
                goto code_r0x000820dc;
              case 0x87dc:
                goto code_r0x000820d0;
              case 0x87de:
                goto code_r0x000820c4;
              case 0x87df:
                goto code_r0x000820b8;
              }
              break;
            default:
              goto code_r0x00082114;
            }
code_r0x00082098:
            candidateSrc2SelectorY = selectorEnumerant;
code_r0x00082114:
            *(undefined4 *)(movRecord + 100) = candidateSrc2SelectorY;
            candidateSrc2SelectorZ = *(undefined4 *)(movRecord + 0x68);
            switch(*(undefined4 *)(movRecord + 0x68)) {
            case 0x87d5:
            case 0x87d6:
            case 0x87d7:
            case 0x87d8:
              break;
            case 0x87d9:
              switch(selectorEnumerant) {
              case 0x87d5:
code_r0x000822dc:
                candidateSrc2SelectorZ = 0x87d9;
                break;
              case 0x87d6:
code_r0x000822d0:
                candidateSrc2SelectorZ = 0x87da;
                break;
              case 0x87d7:
code_r0x0008233c:
                candidateSrc2SelectorZ = 0x87db;
                break;
              case 0x87d8:
code_r0x00082330:
                candidateSrc2SelectorZ = 0x87dc;
                break;
              case 0x87d9:
code_r0x00082324:
                candidateSrc2SelectorZ = 0x87d5;
                break;
              case 0x87da:
code_r0x00082318:
                candidateSrc2SelectorZ = 0x87d6;
                break;
              case 0x87db:
code_r0x0008230c:
                candidateSrc2SelectorZ = 0x87d7;
                break;
              case 0x87dc:
code_r0x00082300:
                candidateSrc2SelectorZ = 0x87d8;
                break;
              default:
                goto code_r0x000822c8;
              case 0x87de:
code_r0x000822f4:
                candidateSrc2SelectorZ = 0x87df;
                break;
              case 0x87df:
code_r0x000822e8:
                candidateSrc2SelectorZ = 0x87de;
              }
              goto code_r0x00082344;
            case 0x87da:
              switch(selectorEnumerant) {
              case 0x87d5:
                goto code_r0x000822dc;
              case 0x87d6:
                goto code_r0x000822d0;
              case 0x87d7:
                goto code_r0x0008233c;
              case 0x87d8:
                goto code_r0x00082330;
              case 0x87d9:
                goto code_r0x00082324;
              case 0x87da:
                goto code_r0x00082318;
              case 0x87db:
                goto code_r0x0008230c;
              case 0x87dc:
                goto code_r0x00082300;
              case 0x87de:
                goto code_r0x000822f4;
              case 0x87df:
                goto code_r0x000822e8;
              }
              break;
            case 0x87db:
              switch(selectorEnumerant) {
              case 0x87d5:
                goto code_r0x000822dc;
              case 0x87d6:
                goto code_r0x000822d0;
              case 0x87d7:
                goto code_r0x0008233c;
              case 0x87d8:
                goto code_r0x00082330;
              case 0x87d9:
                goto code_r0x00082324;
              case 0x87da:
                goto code_r0x00082318;
              case 0x87db:
                goto code_r0x0008230c;
              case 0x87dc:
                goto code_r0x00082300;
              case 0x87de:
                goto code_r0x000822f4;
              case 0x87df:
                goto code_r0x000822e8;
              }
              break;
            case 0x87dc:
              switch(selectorEnumerant) {
              case 0x87d5:
                goto code_r0x000822dc;
              case 0x87d6:
                goto code_r0x000822d0;
              case 0x87d7:
                goto code_r0x0008233c;
              case 0x87d8:
                goto code_r0x00082330;
              case 0x87d9:
                goto code_r0x00082324;
              case 0x87da:
                goto code_r0x00082318;
              case 0x87db:
                goto code_r0x0008230c;
              case 0x87dc:
                goto code_r0x00082300;
              case 0x87de:
                goto code_r0x000822f4;
              case 0x87df:
                goto code_r0x000822e8;
              }
              break;
            default:
              goto code_r0x00082344;
            }
code_r0x000822c8:
            candidateSrc2SelectorZ = selectorEnumerant;
code_r0x00082344:
            *(undefined4 *)(movRecord + 0x68) = candidateSrc2SelectorZ;
            candidateSrc2SelectorW = *(undefined4 *)(movRecord + 0x6c);
            switch(*(undefined4 *)(movRecord + 0x6c)) {
            case 0x87d5:
            case 0x87d6:
            case 0x87d7:
            case 0x87d8:
              break;
            case 0x87d9:
              switch(selectorEnumerant) {
              case 0x87d5:
code_r0x0008250c:
                candidateSrc2SelectorW = 0x87d9;
                break;
              case 0x87d6:
code_r0x00082500:
                candidateSrc2SelectorW = 0x87da;
                break;
              case 0x87d7:
code_r0x0008256c:
                candidateSrc2SelectorW = 0x87db;
                break;
              case 0x87d8:
code_r0x00082560:
                candidateSrc2SelectorW = 0x87dc;
                break;
              case 0x87d9:
code_r0x00082554:
                candidateSrc2SelectorW = 0x87d5;
                break;
              case 0x87da:
code_r0x00082548:
                candidateSrc2SelectorW = 0x87d6;
                break;
              case 0x87db:
code_r0x0008253c:
                candidateSrc2SelectorW = 0x87d7;
                break;
              case 0x87dc:
code_r0x00082530:
                candidateSrc2SelectorW = 0x87d8;
                break;
              default:
                goto code_r0x000824f8;
              case 0x87de:
code_r0x00082524:
                candidateSrc2SelectorW = 0x87df;
                break;
              case 0x87df:
code_r0x00082518:
                candidateSrc2SelectorW = 0x87de;
              }
              goto code_r0x00082574;
            case 0x87da:
              switch(selectorEnumerant) {
              case 0x87d5:
                goto code_r0x0008250c;
              case 0x87d6:
                goto code_r0x00082500;
              case 0x87d7:
                goto code_r0x0008256c;
              case 0x87d8:
                goto code_r0x00082560;
              case 0x87d9:
                goto code_r0x00082554;
              case 0x87da:
                goto code_r0x00082548;
              case 0x87db:
                goto code_r0x0008253c;
              case 0x87dc:
                goto code_r0x00082530;
              case 0x87de:
                goto code_r0x00082524;
              case 0x87df:
                goto code_r0x00082518;
              }
              break;
            case 0x87db:
              switch(selectorEnumerant) {
              case 0x87d5:
                goto code_r0x0008250c;
              case 0x87d6:
                goto code_r0x00082500;
              case 0x87d7:
                goto code_r0x0008256c;
              case 0x87d8:
                goto code_r0x00082560;
              case 0x87d9:
                goto code_r0x00082554;
              case 0x87da:
                goto code_r0x00082548;
              case 0x87db:
                goto code_r0x0008253c;
              case 0x87dc:
                goto code_r0x00082530;
              case 0x87de:
                goto code_r0x00082524;
              case 0x87df:
                goto code_r0x00082518;
              }
              break;
            case 0x87dc:
              switch(selectorEnumerant) {
              case 0x87d5:
                goto code_r0x0008250c;
              case 0x87d6:
                goto code_r0x00082500;
              case 0x87d7:
                goto code_r0x0008256c;
              case 0x87d8:
                goto code_r0x00082560;
              case 0x87d9:
                goto code_r0x00082554;
              case 0x87da:
                goto code_r0x00082548;
              case 0x87db:
                goto code_r0x0008253c;
              case 0x87dc:
                goto code_r0x00082530;
              case 0x87de:
                goto code_r0x00082524;
              case 0x87df:
                goto code_r0x00082518;
              }
              break;
            default:
              goto code_r0x00082574;
            }
code_r0x000824f8:
            candidateSrc2SelectorW = selectorEnumerant;
code_r0x00082574:
            *(undefined4 *)(movRecord + 0x6c) = candidateSrc2SelectorW;
code_r0x00082578:
            if ((*(int *)(movRecord + 4) != 2) ||
               (bVar33 = true, *(int *)(movRecord + 8) != *(int *)(currentInstruction + -0x6c))) {
              bVar33 = false;
            }
            uVar18 = *(uint *)(shaderProgram + 0x14);
          } while ((writeEnableX + 1 < uVar18) && (symbol = symbol + 0x74, writeEnableX = writeEnableX + 1, !bVar33));
          currentInstruction = instructions;
          if (uVar30 < uVar18) {
            do {
              uVar30 = uVar30 + 1;
              symbol = currentInstruction + *(int *)(shaderProgram + 0x18);
              _memcpy(symbol + -0x74,symbol,0x74);
              uVar18 = *(uint *)(shaderProgram + 0x14);
              currentInstruction = currentInstruction + 0x74;
            } while (uVar30 < uVar18);
          }
        }
        *(uint *)(shaderProgram + 0x14) = uVar18 - 1;
      }
code_r0x00082600:
      instructionIndex = instructionIndex + 1;
      instructions = instructions + -0x74;
    } while (instructionCount != instructionIndex);
    instructionIndex = *(uint *)(shaderProgram + 0x14);
  }
  do {
    while( true ) {
      instructionCount = instructionIndex;
      if (instructionCount < 2) {
        return;
      }
      currentInstruction = instructionCount * 0x74;
      instructions = currentInstruction + *(int *)(shaderProgram + 0x18);
      if (((*(int *)(instructions + -0x74) == 0x879c) && (*(int *)(instructions + -0x54) == 2)) &&
         (symbol = extvsOperandDataType(shaderProgram + 0x1c,instructions + -0x54), symbol == 0x87be)) break;
code_r0x00082770:
      instructionIndex = instructionCount - 1;
    }
    if (instructionCount < *(uint *)(shaderProgram + 0x14)) {
      symbol = *(uint *)(shaderProgram + 0x14) - instructionCount;
      bVar33 = true;
      laterSlotCursor = (int *)(currentInstruction + *(int *)(shaderProgram + 0x18) + 0x20);
      do {
        if ((((*laterSlotCursor == 2) && (laterSlotCursor[1] == *(int *)(instructions + -0x50))) ||
            ((laterSlotCursor[7] == 2 && (laterSlotCursor[8] == *(int *)(instructions + -0x50))))) ||
           ((laterSlotCursor[0xe] == 2 && (laterSlotCursor[0xf] == *(int *)(instructions + -0x50))))) {
          bVar34 = true;
          bVar33 = false;
        }
        else if ((laterSlotCursor[-7] != 2) || (bVar34 = true, laterSlotCursor[-6] != *(int *)(instructions + -0x50))) {
          bVar34 = false;
        }
        symbol = symbol + -1;
      } while ((symbol != 0) && (laterSlotCursor = laterSlotCursor + 0x1d, !bVar34));
      if (!bVar33) goto code_r0x00082770;
    }
    instructionIndex = instructionCount - 1;
    if (instructionIndex != 0) {
      symbol = instructionIndex * 0x74;
      bVar33 = false;
      uVar30 = instructionIndex;
      do {
        movRecord = symbol + *(int *)(shaderProgram + 0x18);
        if ((*(int *)(movRecord + -0x70) == 2) &&
           (*(int *)(movRecord + -0x6c) == *(int *)(instructions + -0x50))) {
          if (*(int *)(movRecord + -0x74) - 0x879bU < 2) {
code_r0x0008286c:
            bVar34 = true;
          }
          else {
            uVar22 = *(undefined4 *)(instructions + -100);
            bVar34 = true;
            bVar33 = true;
            uVar19 = *(undefined4 *)(instructions + -0x60);
            selectorEnumerant = *(undefined4 *)(instructions + -0x5c);
            uVar9 = *(undefined4 *)(instructions + -0x70);
            uVar20 = *(undefined4 *)(instructions + -0x6c);
            *(undefined4 *)(movRecord + -0x68) = *(undefined4 *)(instructions + -0x68);
            *(undefined4 *)(movRecord + -100) = uVar22;
            *(undefined4 *)(movRecord + -0x5c) = selectorEnumerant;
            *(undefined4 *)(movRecord + -0x60) = uVar19;
            *(undefined4 *)(movRecord + -0x70) = uVar9;
            *(undefined4 *)(movRecord + -0x6c) = uVar20;
          }
        }
        else {
          if ((((*(int *)(movRecord + -0x54) == 2) &&
               (*(int *)(movRecord + -0x50) == *(int *)(instructions + -0x50))) ||
              ((*(int *)(movRecord + -0x38) == 2 &&
               (*(int *)(movRecord + -0x34) == *(int *)(instructions + -0x50))))) ||
             ((*(int *)(movRecord + -0x1c) == 2 &&
              (*(int *)(movRecord + -0x18) == *(int *)(instructions + -0x50))))) goto code_r0x0008286c;
          bVar34 = false;
        }
        uVar30 = uVar30 - 1;
      } while ((uVar30 != 0) && (symbol = symbol + -0x74, !bVar34));
      if (bVar33) {
        uVar30 = *(uint *)(shaderProgram + 0x14);
        if (instructionCount < uVar30) {
          do {
            instructionCount = instructionCount + 1;
            instructions = currentInstruction + *(int *)(shaderProgram + 0x18);
            currentInstruction = currentInstruction + 0x74;
            _memcpy(instructions + -0x74,instructions,0x74);
            uVar30 = *(uint *)(shaderProgram + 0x14);
          } while (instructionCount < uVar30);
        }
        *(uint *)(shaderProgram + 0x14) = uVar30 - 1;
      }
    }
  } while( true );
LAB_0007e2d4:
  if (allLanesPass) {
    if (uVar30 < instructionCount) {
      do {
        uVar30 = uVar30 + 1;
        instructions = movRecord + *(int *)(shaderProgram + 0x18);
        movRecord = movRecord + 0x74;
        uStack_70 = selectorEnumerant;
        _memcpy(instructions + -0x74,instructions,0x74);
        instructionCount = *(uint *)(shaderProgram + 0x14);
        selectorEnumerant = uStack_70;
      } while (uVar30 < instructionCount);
    }
    instructionCount = instructionCount - 1;
    *(uint *)(shaderProgram + 0x14) = instructionCount;
  }
LAB_0007e2e0:
  instructionIndex = instructionIndex + 1;
  if (instructionCount <= instructionIndex) goto LAB_0007e330;
  goto LAB_0007de3c;
}

/* gldAllocAndUploadConstants @ 0x82900 (812 bytes) */
int gldAllocAndUploadConstants(glContext, program)
  int glContext;
  int program;
{
  uint reg1b94Value;
  undefined4 *packet;
  uint copyCounter;
  uint reg1b90Old;
  uint availableCount;
  int packetWords;
  int cmdPos;
  int programField38;
  undefined4 *srcWord3Ptr;
  uint availableConsts;
  int limitRaw;
  code *streamSetCurrent;
  undefined4 *dstWords;
  undefined4 in_r5;
  undefined4 in_r6;
  uint oldBase;
  undefined4 oldOffset;
  uint newOffset;
  code *streamAlloc;
  int constBlock;
  uint ctxFlags;
  int allocMode;
  uint newBase;
  undefined4 *srcConsts;
  uint constCount;
  
  constBlock = *(int *)(program + 0x54);
  constCount = *(uint *)(constBlock + 0x3cc);
  srcConsts = *(undefined4 **)(constBlock + 0x3c8);
  if ((constCount == 0) || (srcConsts == (undefined4 *)0x0)) {
    return;
  }
  ctxFlags = *(uint *)(glContext + 0x8c);
  if ((ctxFlags & 0x40000) == 0) {
LAB_00082b00:
    oldBase = *(uint *)(glContext + 0x3cc);
    reg1b90Old = *(uint *)(glContext + 0x1b90);
    oldOffset = *(undefined4 *)(glContext + 0x3d0);
    streamAlloc = *(code **)(glContext + 0x2758);
    *(uint *)(glContext + 0x1b90) = oldBase & 0x3ff | reg1b90Old & 0xfffffc00;
    *(uint *)(glContext + 0x1b90) =
         (oldBase + constCount + -1) * 0x100000 & 0x3ff00000 |
         (oldBase + *(int *)(program + 0x34)) * 0x400 & 0xffc00 | oldBase & 0x3ff | reg1b90Old & 0xc0000000;
    programField38 = *(int *)(program + 0x38);
    *(char *)(glContext + 0x1b8f) = (char)oldOffset;
    oldBase = oldBase + programField38;
    reg1b94Value = oldBase & 0x3ff | *(uint *)(glContext + 0x1b94) & 0xfffffc00;
    *(uint *)(glContext + 0x1b94) = reg1b94Value;
    *(char *)(glContext + 0x1b8d) = (char)*(undefined4 *)(program + 0x48);
    packet = (undefined4 *)(*streamAlloc)(glContext,4,in_r5,in_r6,oldOffset,streamAlloc,oldBase,reg1b94Value);
    *(undefined4 **)(0x00002748 + glContext + 4) = packet;
    *packet = 0x208b4;
    packet[1] = *(undefined4 *)(glContext + 0x1b90);
    packet[2] = *(undefined4 *)(glContext + 0x1b8c);
    packet[3] = *(undefined4 *)(glContext + 0x1b94);
    streamSetCurrent = *(code **)(glContext + 0x275c);
    cmdPos = *(int *)(0x00002748 + glContext + 4) + 0x10;
    *(int *)(0x00002748 + glContext + 4) = cmdPos;
    (*streamSetCurrent)(glContext,cmdPos,in_r5,in_r6,oldOffset,streamAlloc,cmdPos);
    packet = (undefined4 *)(**(code **)(glContext + 0x2758))(glContext,2);
    *(undefined4 **)(0x00002748 + glContext + 4) = packet;
    *packet = 0x8b7;
    packet[1] = *(undefined4 *)(glContext + 0x1b98);
    cmdPos = *(int *)(0x00002748 + glContext + 4);
    streamSetCurrent = *(code **)(glContext + 0x275c);
    *(int *)(0x00002748 + glContext + 4) = cmdPos + 8;
    (*streamSetCurrent)(glContext,cmdPos + 8,in_r5,in_r6,oldOffset,streamAlloc,packet);
    FUN_00050ef0(glContext,*(undefined4 *)(program + 0x3c),*(undefined4 *)(program + 0x40),
                 *(undefined4 *)(program + 0x44));
    return;
  }
  allocMode = *(int *)(glContext + 0xd8);
  newBase = 0;
  newOffset = 0;
  availableConsts = 0;
  availableCount = 0;
  do {
    if (allocMode == 1) goto LAB_000829a0;
    if (allocMode == 0) {
      availableCount = (uint)(*(ushort *)(((unsigned char *)0x000013be) + glContext) >> 1);
      newBase = *(uint *)(constBlock + 0x3e4) >> 1;
      availableConsts = newBase - 2;
      newOffset = availableCount;
      goto LAB_000829e0;
    }
    if (allocMode != 2) goto LAB_000829e0;
    while( true ) {
      availableConsts = *(uint *)(constBlock + 0x3e4);
      availableCount = (uint)*(ushort *)(((unsigned char *)0x000013be) + glContext);
      newBase = 0;
      ctxFlags = ctxFlags | 0x18000;
      *(uint *)(glContext + 0x8c) = ctxFlags;
      newOffset = 0;
LAB_000829e0:
      while( true ) {
        if ((constCount <= availableConsts) && (*(uint *)(program + 0x48) <= availableCount)) {
          *(uint *)(glContext + 0x3d0) = newOffset;
          *(uint *)(glContext + 0x3cc) = newBase;
          packetWords = constCount * 4 + 5;
          dstWords = (undefined4 *)(**(code **)(glContext + 0x2758))(glContext,packetWords);
          *(undefined4 **)(0x00002748 + glContext + 4) = dstWords;
          dstWords[3] = newBase;
          *dstWords = 0x8a1;
          dstWords[1] = 0;
          dstWords[4] = (constCount * 4 + -1) * 0x10000 | 0x8882;
          dstWords[2] = 0x880;
          dstWords = dstWords + 5;
          copyCounter = constCount;
          do {
            *dstWords = *srcConsts;
            dstWords[1] = srcConsts[1];
            dstWords[2] = srcConsts[2];
            srcWord3Ptr = srcConsts + 3;
            srcConsts = srcConsts + 4;
            dstWords[3] = *srcWord3Ptr;
            dstWords = dstWords + 4;
            copyCounter = copyCounter - 1;
          } while (copyCounter != 0);
          streamSetCurrent = *(code **)(glContext + 0x275c);
          packetWords = packetWords * 4 + *(int *)(0x00002748 + glContext + 4);
          *(int *)(0x00002748 + glContext + 4) = packetWords;
          (*streamSetCurrent)(glContext,packetWords);
          if (*(int *)(glContext + 0xd8) == 0) {
            *(uint *)(glContext + 0x8c) = *(uint *)(glContext + 0x8c) & 0xfffbffff;
          }
          goto LAB_00082b00;
        }
        if (allocMode != 0) break;
        allocMode = 1;
        *(undefined4 *)(glContext + 0xd8) = 1;
LAB_000829a0:
        limitRaw = *(int *)(constBlock + 0x3e4);
        availableCount = (uint)*(ushort *)(((unsigned char *)0x000013be) + glContext);
        ctxFlags = ctxFlags | 0x10000;
        newBase = 0;
        *(uint *)(glContext + 0x8c) = ctxFlags;
        availableConsts = limitRaw - 2;
        newOffset = 0;
      }
      if (allocMode != 1) break;
      allocMode = 2;
      *(undefined4 *)(glContext + 0xd8) = 2;
    }
  } while( true );
}

/* gldEmitProgramConstants @ 0x82c50 (760 bytes) */
int gldEmitProgramConstants(ctx, program, unusedArg3, unusedArg4, unusedArg5, unusedArg6, unusedArg7, unusedArg8)
  int ctx;
  int program;
  undefined4 unusedArg3;
  undefined4 unusedArg4;
  undefined4 unusedArg5;
  undefined4 unusedArg6;
  undefined4 unusedArg7;
  undefined4 unusedArg8;
{
  int constRegBase;
  int packetWords;
  undefined4 *srcWord3Ptr;
  code *UNRECOVERED_JUMPTABLE;
  undefined4 *packet;
  int cmdPos;
  int constRegOffset;
  undefined4 *dstWords;
  uint loopIndex;
  int stateBlock;
  undefined4 *srcConstants;
  double fparam_1;
  double in_f2;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  double in_stack_ffffffa8;
  double in_stack_ffffffb0;
  double in_stack_ffffffb8;
  double in_stack_ffffffc0;
  double in_stack_ffffffc8;
  
  stateBlock = *(int *)(*(int *)(ctx + 4) + 0x10);
  packet = (undefined4 *)
           (**(code **)(ctx + 0x2758))
                     (ctx,2,unusedArg3,unusedArg4,unusedArg5,unusedArg6,unusedArg7,unusedArg8);
  *(undefined4 **)(0x00002748 + ctx + 4) = packet;
  packet[1] = 0;
  *packet = 0x8a1;
  cmdPos = *(int *)(0x00002748 + ctx + 4);
  UNRECOVERED_JUMPTABLE = *(code **)(ctx + 0x275c);
  *(int *)(0x00002748 + ctx + 4) = cmdPos + 8;
  (*UNRECOVERED_JUMPTABLE)(ctx,cmdPos + 8);
  if (*(char *)(program + 0x58) == '\0') {
    if (*(int *)(program + 0x48) == 0) {
      return;
    }
    srcConstants = *(undefined4 **)(program + 0x4c);
    ((void (*)())programFillStateConstants)(ctx,program,unusedArg3,unusedArg4,unusedArg5,unusedArg6,unusedArg7,unusedArg8,fparam_1,in_f2,
                 in_f3,in_f4,in_f5,in_f6,in_f7,in_f8,in_stack_ffffffa8,in_stack_ffffffb0,
                 in_stack_ffffffb8,in_stack_ffffffc0,in_stack_ffffffc8);
    packetWords = *(int *)(program + 0x48) * 4 + 3;
    packet = (undefined4 *)(**(code **)(ctx + 0x2758))(ctx,packetWords);
    *(undefined4 **)(0x00002748 + ctx + 4) = packet;
    dstWords = packet + 3;
    *packet = 0x880;
    packet[1] = *(int *)(ctx + 0x2448) + *(int *)(ctx + 0x3d0);
    packet[2] = *(int *)(program + 0x48) * 0x40000 - 0x10000U | 0x8882;
    if (*(int *)(program + 0x48) != 0) {
      loopIndex = 0;
      do {
        loopIndex = loopIndex + 1;
        *dstWords = *srcConstants;
        dstWords[1] = srcConstants[1];
        dstWords[2] = srcConstants[2];
        srcWord3Ptr = srcConstants + 3;
        srcConstants = srcConstants + 4;
        dstWords[3] = *srcWord3Ptr;
        dstWords = dstWords + 4;
      } while (loopIndex < *(uint *)(program + 0x48));
    }
    UNRECOVERED_JUMPTABLE = *(code **)(ctx + 0x275c);
    *(int *)(0x00002748 + ctx + 4) = packetWords * 4 + *(int *)(0x00002748 + ctx + 4);
  }
  else {
    packet = (undefined4 *)(**(code **)(ctx + 0x2758))(ctx,0x13);
    *(undefined4 **)(0x00002748 + ctx + 4) = packet;
    *packet = 0x880;
    constRegBase = *(int *)(ctx + 0x2448);
    constRegOffset = *(int *)(ctx + 0x3d0);
    packet[2] = 0xf8882;
    packet[1] = constRegBase + constRegOffset;
    if ((*(uint *)(((unsigned char *)0x000013c0) + ctx) & 4) == 0) {
      packet[3] = *(undefined4 *)(stateBlock + 0x2460);
      packet[4] = *(undefined4 *)(stateBlock + 0x2470);
      packet[5] = *(undefined4 *)(stateBlock + 0x2480);
      packet[6] = *(undefined4 *)(stateBlock + 0x2490);
      packet[7] = *(undefined4 *)(stateBlock + 0x2464);
      packet[8] = *(undefined4 *)(stateBlock + 0x2474);
      packet[9] = *(undefined4 *)(stateBlock + 0x2484);
      packet[10] = *(undefined4 *)(stateBlock + 0x2494);
      packet[0xb] = *(undefined4 *)(stateBlock + 0x2468);
      packet[0xc] = *(undefined4 *)(stateBlock + 0x2478);
      packet[0xd] = *(undefined4 *)(stateBlock + 0x2488);
      packet[0xe] = *(undefined4 *)(stateBlock + 0x2498);
      packet[0xf] = *(undefined4 *)(stateBlock + 0x246c);
      packet[0x10] = *(undefined4 *)(stateBlock + 0x247c);
      packet[0x11] = *(undefined4 *)(stateBlock + 0x248c);
      packet[0x12] = *(undefined4 *)(stateBlock + 0x249c);
    }
    else {
      packet[3] = *(undefined4 *)(stateBlock + 0x2460);
      packet[4] = *(undefined4 *)(stateBlock + 0x2464);
      packet[5] = *(undefined4 *)(stateBlock + 0x2468);
      packet[6] = *(undefined4 *)(stateBlock + 0x246c);
      packet[7] = *(undefined4 *)(stateBlock + 0x2470);
      packet[8] = *(undefined4 *)(stateBlock + 0x2474);
      packet[9] = *(undefined4 *)(stateBlock + 0x2478);
      packet[10] = *(undefined4 *)(stateBlock + 0x247c);
      packet[0xb] = *(undefined4 *)(stateBlock + 0x2480);
      packet[0xc] = *(undefined4 *)(stateBlock + 0x2484);
      packet[0xd] = *(undefined4 *)(stateBlock + 0x2488);
      packet[0xe] = *(undefined4 *)(stateBlock + 0x248c);
      packet[0xf] = *(undefined4 *)(stateBlock + 0x2490);
      packet[0x10] = *(undefined4 *)(stateBlock + 0x2494);
      packet[0x11] = *(undefined4 *)(stateBlock + 0x2498);
      packet[0x12] = *(undefined4 *)(stateBlock + 0x249c);
    }
    UNRECOVERED_JUMPTABLE = *(code **)(ctx + 0x275c);
    *(int *)(0x00002748 + ctx + 4) = *(int *)(0x00002748 + ctx + 4) + 0x4c;
  }
                    
                    
  (*UNRECOVERED_JUMPTABLE)(ctx,*(int *)(0x00002748 + ctx + 4));
  return;
}

/* interpolatorMapInit @ 0x82f60 (416 bytes) */
int interpolatorMapInit(ctx, builder, param_3, param_4)
  int ctx;
  int builder;
  undefined4 param_3;
  uint *param_4;
{
  bool hasPosition;
  uint outputMask;
  uint nextSlot;
  
  _memset(builder + 0x68,0xffffffff,0x3c);
  hasPosition = (*(uint *)(ctx + 0x1b9c) & 1) != 0;
  if (hasPosition) {
    *(undefined4 *)(builder + 0x68) = 0;
  }
  nextSlot = (uint)hasPosition;
  outputMask = *(uint *)(ctx + 0x1b9c);
  if ((outputMask & 0x10000) != 0) {
    *(uint *)(builder + 0x6c) = nextSlot;
    nextSlot = nextSlot + 1;
    outputMask = *(uint *)(ctx + 0x1b9c);
  }
  if ((outputMask & 2) != 0) {
    *(uint *)(builder + 0x74) = nextSlot;
    nextSlot = nextSlot + 1;
    outputMask = *(uint *)(ctx + 0x1b9c);
  }
  if ((outputMask & 4) != 0) {
    *(uint *)(builder + 0x7c) = nextSlot;
    if (((*(uint *)(ctx + 0x44) & 0x1000000) != 0) && (*(char *)(ctx + 0x121) == '\0')) {
      *(uint *)(builder + 0x70) = nextSlot;
    }
    outputMask = *(uint *)(ctx + 0x1b9c);
    nextSlot = nextSlot + 1;
  }
  if ((outputMask & 8) != 0) {
    *(uint *)(builder + 0x78) = nextSlot;
    nextSlot = nextSlot + 1;
    outputMask = *(uint *)(ctx + 0x1b9c);
  }
  if ((outputMask & 0x10) != 0) {
    *(uint *)(builder + 0x80) = nextSlot;
    nextSlot = nextSlot + 1;
  }
  outputMask = *(uint *)(ctx + 0x1ba0);
  if ((outputMask & 7) != 0) {
    *(uint *)(builder + 0x84) = nextSlot;
    nextSlot = nextSlot + 1;
    outputMask = *(uint *)(ctx + 0x1ba0);
  }
  if ((outputMask & 0x38) != 0) {
    *(uint *)(builder + 0x88) = nextSlot;
    nextSlot = nextSlot + 1;
    outputMask = *(uint *)(ctx + 0x1ba0);
  }
  if ((outputMask & 0x1c0) != 0) {
    *(uint *)(builder + 0x8c) = nextSlot;
    nextSlot = nextSlot + 1;
    outputMask = *(uint *)(ctx + 0x1ba0);
  }
  if ((outputMask & 0xe00) != 0) {
    *(uint *)(builder + 0x90) = nextSlot;
    nextSlot = nextSlot + 1;
    outputMask = *(uint *)(ctx + 0x1ba0);
  }
  if ((outputMask & 0x7000) != 0) {
    *(uint *)(builder + 0x94) = nextSlot;
    nextSlot = nextSlot + 1;
    outputMask = *(uint *)(ctx + 0x1ba0);
  }
  if ((outputMask & 0x38000) != 0) {
    *(uint *)(builder + 0x98) = nextSlot;
    nextSlot = nextSlot + 1;
    outputMask = *(uint *)(ctx + 0x1ba0);
  }
  if ((outputMask & 0x1c0000) != 0) {
    *(uint *)(builder + 0x9c) = nextSlot;
    nextSlot = nextSlot + 1;
    outputMask = *(uint *)(ctx + 0x1ba0);
  }
  if ((outputMask & 0xe00000) != 0) {
    *(uint *)(builder + 0xa0) = nextSlot;
    nextSlot = nextSlot + 1;
  }
  (**(code **)(((unsigned char *)0x00001334) + ctx))(ctx,0);
  *param_4 = nextSlot;
  return;
}


/* issue: auto-generated aliases bridging data.s/code.s references (written
 * without a leading underscore, matching the raw stock-binary symbol name)
 * against the real compiled C symbols (gcc adds one underscore automatically).
 * Needed because ld64 (required for this PPC binary's size - stock ld breaks on
 * large PPC links) does not silently reconcile this the way stock ld did. */
asm(".globl FUN_00076c60");
asm(".set FUN_00076c60, _vpStateSelectForDraw");
asm(".globl FUN_00076fe0");
asm(".set FUN_00076fe0, _ctxTempListCreate");
asm(".globl FUN_00077030");
asm(".set FUN_00077030, _ctxTempListFree");
asm(".globl vpStateCacheCreate");
asm(".set vpStateCacheCreate, _vpStateCacheCreate");
asm(".globl vpStateCacheFreeAll");
asm(".set vpStateCacheFreeAll, _vpStateCacheFreeAll");
asm(".globl vpStateSetConstantVector");
asm(".set vpStateSetConstantVector, _vpStateSetConstantVector");
asm(".globl FUN_00078990");
asm(".set FUN_00078990, _recordFlagsPending20");
asm(".globl FUN_000789d0");
asm(".set FUN_000789d0, _recordFlagsPending2");
asm(".globl evsFoldConstantMoves");
asm(".set evsFoldConstantMoves, _evsFoldConstantMoves");
asm(".globl FUN_00082900");
asm(".set FUN_00082900, _gldAllocAndUploadConstants");
asm(".globl FUN_00082c50");
asm(".set FUN_00082c50, _gldEmitProgramConstants");
asm(".globl interpolatorMapInit");
asm(".set interpolatorMapInit, _interpolatorMapInit");
