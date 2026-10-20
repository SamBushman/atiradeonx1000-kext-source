/*
 * HZMEM_Alloc_Port.cpp
 *
 * HZMEM_Alloc (real addr 0x45350, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
 * Tools/port_fn.py); replaces the earlier hand-written body, which the callee/atomics comparison (Tools/callee_compare.py) showed had
 * dropped or simplified parts of the original.
 */

#include "../Headers/ATIRadeonX1000.h"
#include "../Headers/IOATIR500Accelerator.h"
#include "../Headers/IOATIR500GLContext.h"
#include "../Headers/IOATIR5002DContext.h"
#include "../Headers/IOATIR500DVDContext.h"
#include "../Headers/IOATIR500Surface.h"
#include "../Headers/IOATIR500Shared.h"
#include "../Headers/ATIR500Surface.h"
#include "../Headers/ATIR500GLContext.h"
#include "../Headers/ATIR5002DContext.h"
#include "../Headers/ATIR500DVDContext.h"
#include "../Headers/ATIR500Memory.h"
#include "../Headers/ATIRadeonX1000PPCIntrinsics.h"
#include "../Headers/ATIRadeonX1000Registers.h"
#include "../Headers/GhidraExterns.h"
#include "../Headers/GhidraCompat.h"
#include "../Headers/GhidraLiterals.h"



/* real addr 0x45350 */
UInt32 HZMEM_Alloc(_HZDATA *hizData, UInt32 surfaceHzField, UInt32 blockKind, UInt32 tileDim, UInt32 size) {
    UInt8 *hizDataBytes = reinterpret_cast<UInt8 *>(hizData);

  SInt32 kindOffset;
  UInt8 *fillPtr;
  UInt32 blockSlot;
  SInt32 *pool;
  UInt32 poolLimit;
  SInt32 searchLeft;
  UInt32 tileDimUnit;
  UInt32 tileCount;
  UInt32 blocksNeeded;
  UInt32 sizeUnit;
  UInt32 blockSize;
  SInt32 remainder;
  SInt32 slotsLeft;
  SInt32 scanLeft;
  SInt32 usageMap;
  SInt32 startBlock;
  SInt32 startOffset;
  SInt32 scanIndex;
  SInt32 mapBlocks;
  SInt32 fillCount;
  SInt32 prevIndex;
  SInt32 mapCursor;
  SInt32 *slotCursor;
  SInt32 *kindPool;
  UInt32 freeRun;
  UInt32 fillLeft;
  UInt32 runBlocks;
  
  if (hizDataBytes == (UInt8 *)0x0) {
    return 0xffffffff;
  }
  kindOffset = blockKind * 4;
  pool = M<SInt32 *>(hizDataBytes + kindOffset + 0x10);
  if (pool == (SInt32 *)0x0) {
    return 0xffffffff;
  }
  if (2 < blockKind) {
    return 0xffffffff;
  }
  tileDimUnit = M<UInt32>(hizDataBytes + 4);
  if (tileDim != (tileDim / tileDimUnit) * tileDimUnit) {
    return 0xffffffff;
  }
  sizeUnit = M<UInt32>(hizDataBytes + 8);
  if (size != (size / sizeUnit) * sizeUnit) {
    return 0xffffffff;
  }
  if ((tileDimUnit == 0) || (sizeUnit == 0)) {
    tileCount = 0;
  }
  else {
    tileCount = (tileDim / tileDimUnit) * (size / sizeUnit);
  }
  blockSize = pool[1];
  poolLimit = pool[2];
  remainder = tileCount - (tileCount / blockSize) * blockSize;
  if (remainder != 0) {
    tileCount = blockSize + (tileCount - remainder);
  }
  if (blockSize == 0) {
    blocksNeeded = 0;
  }
  else {
    blocksNeeded = tileCount / blockSize;
  }
  if ((UInt32)pool[4] < 0x100) {
    slotCursor = pool + 5;
    blockSlot = 0;
    slotsLeft = 0x100;
    do {
      if (*slotCursor == 0) {
        scanLeft = *pool;
        runBlocks = blocksNeeded;
        if (scanLeft == 0) goto LAB_000454ac;
        freeRun = 0;
        startBlock = 0;
        scanIndex = 0;
        goto LAB_00045460;
      }
      blockSlot = blockSlot + 1;
      slotCursor = slotCursor + 4;
      slotsLeft = slotsLeft + -1;
    } while (slotsLeft != 0);
  }
  goto LAB_00045438;
code_r0x00045488:
  scanIndex = scanIndex + 1;
  scanLeft = scanLeft + -1;
  if (scanLeft == 0) goto LAB_000454ac;
LAB_00045460:
  freeRun = freeRun + 1;
  if (M<char>(scanIndex + pool[3]) == '\x01') {
    startBlock = scanIndex + 1;
    freeRun = 0;
  }
  if (freeRun != blocksNeeded) goto code_r0x00045488;
  if (blocksNeeded != 0) {
    fillPtr = (UInt8 *)(startBlock + pool[3]);
    fillLeft = blocksNeeded;
    do {
      *fillPtr = 1;
      fillPtr = fillPtr + 1;
      fillLeft = fillLeft - 1;
    } while (fillLeft != 0);
  }
  if (startBlock != -1) {
    startOffset = blockSize * startBlock;
LAB_00045584:
    pool[blockSlot * 4 + 6] = startOffset;
    pool[blockSlot * 4 + 8] = blocksNeeded * blockSize;
    pool[blockSlot * 4 + 7] = blockSize * runBlocks;
    pool[blockSlot * 4 + 5] = 1;
    M<SInt32>(M<SInt32>(hizDataBytes + kindOffset + 0x10) + 0x10) =
         M<SInt32>(M<SInt32>(hizDataBytes + kindOffset + 0x10) + 0x10) + 1;
    goto LAB_0004543c;
  }
LAB_000454ac:
  kindPool = M<SInt32 *>(hizDataBytes + kindOffset + 0x10);
  if (((kindPool == (SInt32 *)0x0) || (usageMap = kindPool[3], usageMap == 0)) || (mapBlocks = *kindPool, mapBlocks < 1))
  {
    startOffset = 0;
    goto LAB_00045584;
  }
  startBlock = mapBlocks + -1;
  if (M<char>(usageMap + startBlock) != '\0') goto LAB_00045438;
  prevIndex = mapBlocks + -2;
  if ((prevIndex < 0) || (M<char>(usageMap + prevIndex) == '\x01')) {
    runBlocks = 1;
  }
  else {
    runBlocks = 2;
    if (2 < blocksNeeded) {
      mapCursor = usageMap + prevIndex;
      searchLeft = startBlock;
      do {
        startBlock = startBlock + -1;
        searchLeft = searchLeft + -1;
        if ((searchLeft == 0) || (M<char>(mapCursor + -1) == '\x01')) break;
        runBlocks = runBlocks + 1;
        mapCursor = mapCursor + -1;
      } while (runBlocks != blocksNeeded);
    }
  }
  if ((startBlock != -1) && (blockSize * (startBlock + blocksNeeded) <= poolLimit)) {
    if (startBlock < mapBlocks) {
      fillCount = mapBlocks - startBlock;
      fillPtr = (UInt8 *)(startBlock + usageMap);
      do {
        *fillPtr = 1;
        fillPtr = fillPtr + 1;
        fillCount = fillCount + -1;
      } while (fillCount != 0);
    }
    startOffset = blockSize * startBlock;
    goto LAB_00045584;
  }
LAB_00045438:
  blockSlot = 0xffffffff;
LAB_0004543c:
  if (blockKind == 1) {
    return surfaceHzField & 0x3ff | (blockSlot & 0x3ff) << 10 | surfaceHzField & 0x3ff00000;
  }
  if (blockKind != 0) {
    if (blockKind != 2) {
      return 0xffffffff;
    }
    return surfaceHzField & 0xfffff | (blockSlot & 0x3ff) << 0x14;
  }
  return blockSlot & 0x3ff | surfaceHzField & 0xffc00 | surfaceHzField & 0x3ff00000;
}
