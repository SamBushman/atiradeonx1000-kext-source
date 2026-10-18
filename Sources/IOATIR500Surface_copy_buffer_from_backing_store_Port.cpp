/*
 * IOATIR500Surface_copy_buffer_from_backing_store_Port.cpp
 *
 * IOATIR500Surface::copy_buffer_from_backing_store (real addr 0x12a00, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x12a00 */
UInt32 IOATIR500Surface::copy_buffer_from_backing_store(ATIR500SurfaceBuffer *buffer) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *bufferBytes = reinterpret_cast<UInt8 *>(buffer);

  SInt32 iVar1;
  UInt16 levelCount;
  SInt32 backingStore;
  SInt32 *attachedMemory;
  UInt8 *cursor;
  UInt32 uVar6;
  SInt32 generation;
  UInt32 index;
  UInt32 nextLevel;
  UInt32 levelWidth;
  UInt32 levelHeight [6];
  
  if (M<SInt32>(M<SInt32>(bufferBytes + 0x24) + 0x54) == M<SInt32>(self + kIOATIR500Surface_stamp)) {
    M<SInt32>(M<SInt32>(self + kIOATIR500Surface_accelerator) + 0x724) =
         M<SInt32>(M<SInt32>(self + kIOATIR500Surface_accelerator) + 0x724) + M<SInt32>(bufferBytes + 0x10);
    uVar6 = (UInt32)M<UInt16>(bufferBytes + 0x20);
    generation = M<SInt32>(self + kIOATIR500Surface_stamp);
    iVar1 = M<SInt32>(M<SInt32>(self + kIOATIR500Surface_accelerator) + 0x50);
    if (uVar6 != 0) {
      levelCount = M<UInt16>(bufferBytes + 0x22);
      index = 0;
      do {
        if (levelCount != 0) {
          uVar6 = 0;
          do {
            VCALL(M<SInt32>(self), 0x5f0)(self,bufferBytes,index,uVar6,&levelWidth,levelHeight,0);
            nextLevel = uVar6 + 1;
            VCALL(M<SInt32>(self), 0x5ec)
                      (self,0,0,levelWidth,levelHeight[0],index,uVar6,bufferBytes,iVar1 + -1,0,0,0,1);
            M<UInt32>(M<SInt32>(M<SInt32>(bufferBytes + 0x24) + 0x14) + 8) =
                 M<UInt32>(self + kIOATIR500Surface_stamp);
            levelCount = M<UInt16>(bufferBytes + 0x22);
            uVar6 = nextLevel;
          } while (nextLevel < levelCount);
          uVar6 = (UInt32)M<UInt16>(bufferBytes + 0x20);
        }
        index = index + 1;
      } while (index < uVar6);
    }
    cursor = self + kIOATIR500Surface_buffer0BackingStore;
    iVar1 = 0x17;
    do {
      backingStore = M<SInt32>(cursor);
      cursor = cursor + 0x78;
      if ((backingStore != 0) && (generation == M<SInt32>(backingStore + 0x54))) {
        M<UInt32>(backingStore + 0x54) = M<UInt32>(self + kIOATIR500Surface_stamp);
      }
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  if ((((self[0xc09] == 0x0) && ((M<UInt32>(self + kIOATIR500Surface_lockFlags) & 0xffff0000) == 0)) &&
      (self[0xc08] == 0x0)) &&
     (((self[0xbf7] != 0x0 && (M<SInt32>(bufferBytes + 0x24) != 0)) &&
      (attachedMemory = M<SInt32 *>(M<SInt32>(bufferBytes + 0x24) + 8), attachedMemory != (SInt32 *)0x0)))) {
    VCALL(*attachedMemory, 0xdc)(attachedMemory,3,0);
  }
  return 1;
}
