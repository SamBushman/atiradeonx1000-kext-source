/*
 * ATIR500Memory_alloc_Port_195f0.cpp
 *
 * ATIR500Memory::alloc (real addr 0x195f0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x195f0 */
UInt32 ATIR500Memory::alloc(GLKMemoryElement *elem, UInt32 size, UInt32 alignment, UInt32 rangeStart, UInt32 rangeSize) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *elemBytes = reinterpret_cast<UInt8 *>(elem);

  UInt32 oldSpareHead;
  SInt32 refilled;
  UInt32 alignMask;
  UInt32 allocEnd;
  UInt32 *puVar5;
  UInt32 allocOffset;
  UInt32 *nextNode;
  UInt32 *freeNode;
  
  if ((M<SInt32>(self + kATIR500Memory_spareNodeStack) != 0) || (refilled = this->add_to_stack(), refilled != 0)) {
    alignMask = 0;
    if (alignment != 0) {
      alignMask = alignment - 1;
    }
    nextNode = *(UInt32 **)*M<UInt32 *>(self + 8);
    while (nextNode != (UInt32 *)0x0) {
      while (freeNode = nextNode, nextNode = (UInt32 *)*freeNode, (SInt32)freeNode[3] < 0) {
        allocOffset = rangeStart;
        if (rangeStart <= (UInt32)freeNode[2]) {
          allocOffset = alignMask + freeNode[2] & ~alignMask;
        }
        allocEnd = size + allocOffset;
        if (allocEnd <= (UInt32)nextNode[2]) {
          if (rangeStart + rangeSize < allocEnd) {
            return 0;
          }
          M<UInt32>(elemBytes + 8) = allocOffset;
          puVar5 = (UInt32 *)freeNode[1];
          M<UInt32>(elemBytes + 0xc) = alignMask & 0xffff;
          if (allocOffset == freeNode[2]) {
            if (allocEnd != nextNode[2]) {
              M<UInt32 *>(elemBytes) = freeNode;
              M<UInt32 *>(elemBytes + 4) = puVar5;
              freeNode[2] = allocEnd;
              *puVar5 = (UInt32)(elemBytes);
              freeNode[1] = (UInt32)(elemBytes);
              return 1;
            }
            M<UInt32 *>(elemBytes) = nextNode;
            M<UInt32 *>(elemBytes + 4) = puVar5;
            *puVar5 = (UInt32)(elemBytes);
            nextNode[1] = (UInt32)(elemBytes);
            oldSpareHead = M<UInt32>(self + kATIR500Memory_spareNodeStack);
            freeNode[3] = 0;
            freeNode[1] = 0;
            freeNode[2] = 0;
            *freeNode = oldSpareHead;
            M<UInt32 *>(self + kATIR500Memory_spareNodeStack) = freeNode;
            return 1;
          }
          if (nextNode[2] == allocEnd) {
            M<UInt32 *>(elemBytes) = nextNode;
            M<UInt32 *>(elemBytes + 4) = freeNode;
            *freeNode = (UInt32)(elemBytes);
            nextNode[1] = (UInt32)(elemBytes);
            return 1;
          }
          puVar5 = M<UInt32 *>(self + kATIR500Memory_spareNodeStack);
          M<UInt32>(self + kATIR500Memory_spareNodeStack) = *puVar5;
          *puVar5 = (UInt32)(nextNode);
          nextNode[1] = (UInt32)(puVar5);
          M<UInt32 *>(elemBytes) = puVar5;
          puVar5[1] = (UInt32)(elemBytes);
          puVar5[3] = 0x80000000;
          puVar5[2] = allocEnd;
          *freeNode = (UInt32)(elemBytes);
          M<UInt32 *>(elemBytes + 4) = freeNode;
          return 1;
        }
      }
    }
  }
  return 0;
}
