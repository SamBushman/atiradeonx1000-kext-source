/*
 * ATIR500Memory_reserve_Port.cpp
 *
 * ATIR500Memory::reserve (real addr 0x19270, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x19270 */
UInt32 ATIR500Memory::reserve(GLKMemoryElement *elem, UInt32 offset, UInt32 size) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *elemBytes = reinterpret_cast<UInt8 *>(elem);

  UInt32 reserveEnd;
  SInt32 *nextNode;
  SInt32 *node;
  SInt32 addOk;
  UInt32 *prevNode;
  UInt32 *spareNode;
  SInt32 spareHead;
  
  if ((M<SInt32>(self + kATIR500Memory_spareNodeStack) != 0) || (addOk = this->add_to_stack(), addOk != 0)) {
    reserveEnd = offset + size;
    nextNode = *(SInt32 **)*M<UInt32 *>(self + 8);
joined_r0x000192c4:
    if (nextNode != (SInt32 *)0x0) {
      while (node = nextNode, node[3] < 0) {
        nextNode = (SInt32 *)*node;
        if (offset < (UInt32)node[2]) goto joined_r0x000192c4;
        if (reserveEnd <= (UInt32)nextNode[2]) {
          M<UInt32>(elemBytes + 8) = offset;
          prevNode = (UInt32 *)node[1];
          M<UInt32>(elemBytes + 0xc) = 0;
          if (offset != node[2]) {
            if (nextNode[2] == reserveEnd) {
              M<SInt32 *>(elemBytes) = nextNode;
              M<SInt32 *>(elemBytes + 4) = node;
              *node = (SInt32)elemBytes;
              nextNode[1] = (SInt32)elemBytes;
              return 1;
            }
            spareNode = M<UInt32 *>(self + kATIR500Memory_spareNodeStack);
            M<UInt32>(self + kATIR500Memory_spareNodeStack) = *spareNode;
            *spareNode = (UInt32)(nextNode);
            nextNode[1] = (SInt32)spareNode;
            M<UInt32 *>(elemBytes) = spareNode;
            spareNode[1] = (UInt32)(elemBytes);
            spareNode[3] = 0x80000000;
            spareNode[2] = reserveEnd;
            *node = (SInt32)elemBytes;
            M<SInt32 *>(elemBytes + 4) = node;
            return 1;
          }
          if (reserveEnd == nextNode[2]) {
            M<SInt32 *>(elemBytes) = nextNode;
            M<UInt32 *>(elemBytes + 4) = prevNode;
            *prevNode = (UInt32)(elemBytes);
            nextNode[1] = (SInt32)elemBytes;
            spareHead = M<SInt32>(self + kATIR500Memory_spareNodeStack);
            node[3] = 0;
            node[1] = 0;
            node[2] = 0;
            *node = spareHead;
            M<SInt32 *>(self + kATIR500Memory_spareNodeStack) = node;
            return 1;
          }
          M<SInt32 *>(elemBytes) = node;
          M<UInt32 *>(elemBytes + 4) = prevNode;
          node[2] = reserveEnd;
          *prevNode = (UInt32)(elemBytes);
          node[1] = (SInt32)elemBytes;
          return 1;
        }
      }
      nextNode = (SInt32 *)*node;
      goto joined_r0x000192c4;
    }
  }
  return 0;
}
