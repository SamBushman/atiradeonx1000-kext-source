/*
 * IOATIR500Surface_copy_buffer_to_backing_store_Port.cpp
 *
 * IOATIR500Surface::copy_buffer_to_backing_store (real addr 0x11110, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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

extern "C" UInt32 GH_IOLockLock(...) asm("_IOLockLock");
extern "C" UInt32 GH_IOLockUnlock(...) asm("_IOLockUnlock");


/* real addr 0x11110 */
bool IOATIR500Surface::copy_buffer_to_backing_store(ATIR500SurfaceBuffer *buffer) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *bufferBytes = reinterpret_cast<UInt8 *>(buffer);

  UInt16 levelCount;
  SInt32 *attachedMemory;
  SInt32 iVar3;
  UInt32 uVar4;
  UInt8 *cursor;
  UInt32 index;
  SInt32 iVar7;
  UInt32 nextLevel;
  SInt32 recordsLeft;
  SInt32 memoryState;
  UInt32 levelWidth;
  UInt32 levelHeight [5];
  
  iVar3 = M<SInt32>(bufferBytes + 0x24);
  memoryState = 2;
  if (iVar3 == 0) {
    /* #171: stock 0x11140: r4 = the buffer (incoming, r30), alloc_buffer_backing_store(ATIR500SurfaceBuffer*) */
    iVar3 = VCALL(M<SInt32>(self), 0x5e4)(self,bufferBytes);
    if (iVar3 == 0) {
      return 0;
    }
    iVar3 = M<SInt32>(bufferBytes + 0x24);
  }
  if (((self[0xc09] == 0x0) && (self[0xbf7] != 0x0)) &&
     (attachedMemory = M<SInt32 *>(iVar3 + 8), attachedMemory != (SInt32 *)0x0)) {
    iVar3 = VCALL(*attachedMemory, 0xdc)(attachedMemory,2,&memoryState);
    if ((iVar3 == 0) && (memoryState == 4)) {
      iVar3 = M<SInt32>(bufferBytes + 0x24);
      if (M<SInt32>(iVar3 + 4) != 0) {
        GH_IOLockUnlock(M<UInt32>(M<SInt32>(self + 0xd50) + 0x840));
        attachedMemory = M<SInt32 *>(self + 0xd50);
        iVar7 = attachedMemory[0x1ed];
        iVar3 = VCALL(*attachedMemory, 0x55c)(attachedMemory,M<UInt32>(self + 0x7c));
        attachedMemory[0x1ed] = iVar7 + iVar3;
        GH_IOLockLock(M<UInt32>(M<SInt32>(self + 0xd50) + 0x840));
        VCALL(*M<SInt32 *>(self + 0xd50), 0x5ac)
                  (M<SInt32 *>(self + 0xd50),M<UInt32>(bufferBytes + 0x24));
        M<UInt32>(M<SInt32>(bufferBytes + 0x24) + 4) = 0;
        iVar3 = M<SInt32>(bufferBytes + 0x24);
      }
      if (M<SInt32>(iVar3 + 0x54) == M<SInt32>(self + 0x7c)) {
        M<UInt8>(iVar3 + 0x58) = 0;
        iVar3 = M<SInt32>(bufferBytes + 0x24);
      }
      else {
        M<SInt32>(iVar3 + 0x54) = M<SInt32>(self + 0x7c) + -1;
        iVar3 = M<SInt32>(bufferBytes + 0x24);
      }
    }
    else {
      iVar3 = M<SInt32>(bufferBytes + 0x24);
    }
  }
  if ((M<SInt32>(iVar3 + 0x54) != M<SInt32>(self + 0x7c)) || (M<char>(iVar3 + 0x58) == '\0')) {
    M<SInt32>(M<SInt32>(self + 0xd50) + 0x728) =
         M<SInt32>(M<SInt32>(self + 0xd50) + 0x728) + M<SInt32>(bufferBytes + 0x10);
    uVar4 = (UInt32)M<UInt16>(bufferBytes + 0x20);
    iVar7 = M<SInt32>(self + 0x7c);
    iVar3 = iVar7;
    if (uVar4 != 0) {
      levelCount = M<UInt16>(bufferBytes + 0x22);
      index = 0;
      do {
        if (levelCount != 0) {
          uVar4 = 0;
          do {
            VCALL(M<SInt32>(self), 0x5f0)(self,bufferBytes,index,uVar4,&levelWidth,levelHeight,0);
            nextLevel = uVar4 + 1;
            VCALL(M<SInt32>(self), 0x5e8)
                      (self,0,0,levelWidth,levelHeight[0],index,uVar4,bufferBytes,iVar7,0,0,0,1);
            M<UInt32>(M<SInt32>(M<SInt32>(bufferBytes + 0x24) + 0x14) + 8) =
                 M<UInt32>(self + 0x7c);
            levelCount = M<UInt16>(bufferBytes + 0x22);
            uVar4 = nextLevel;
          } while (nextLevel < levelCount);
          uVar4 = (UInt32)M<UInt16>(bufferBytes + 0x20);
        }
        index = index + 1;
      } while (index < uVar4);
      iVar3 = M<SInt32>(self + 0x7c);
    }
    cursor = self + 0xcc;
    recordsLeft = 0x17;
    M<SInt32>(M<SInt32>(bufferBytes + 0x24) + 0x54) = iVar3;
    do {
      iVar3 = M<SInt32>(cursor);
      cursor = cursor + 0x78;
      if ((iVar3 != 0) && (iVar7 == M<SInt32>(iVar3 + 0x54))) {
        M<UInt32>(iVar3 + 0x54) = M<UInt32>(self + 0x7c);
      }
      recordsLeft = recordsLeft + -1;
    } while (recordsLeft != 0);
  }
  return 1;
}
