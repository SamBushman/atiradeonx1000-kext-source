/*
 * IOATIR500Surface_alloc_surfaces_pageq_Port.cpp
 *
 * IOATIR500Surface::alloc_surfaces_pageq (real addr 0x12110, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x12110 */
UInt32 IOATIR500Surface::alloc_surfaces_pageq(UInt32 mask, UInt32 keepMask, bool unused) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *selfBytes = reinterpret_cast<UInt8 *>(this);

  int *prevLink;
  bool notLast;
  bool movedAny;
  UInt32 result;
  UInt32 in_register_00000014;
  int listHead;
  unsigned int allAllocated;
  unsigned int pending;
  unsigned int index;
  UInt32 cursor;
  unsigned int bufferBit;
  unsigned int allocOk;
  int surfaceCursor;
  int bufferIndex;
  
  this->invalidate_contexts();
  pending = mask & M<unsigned int>(self + kIOATIR500Surface_stateBits);
  if (pending == 0) {
everythingResident:
    result = 0;
  }
  else {
    index = 0;
    allAllocated = 1;
    do {
      bufferBit = 1 << (index & 0x3f);
      if ((pending & bufferBit) != 0) {
        allocOk = VCALL(M<int>(self), 0x5f4)
                          (self,index,(((UInt32)keepMask) & bufferBit) == 0);
        allAllocated = allAllocated & allocOk;
      }
      index = index + 1;
      if ((pending >> (index & 0x3f) == 0) || (index == 0x17)) {
        if (allAllocated != 0) goto everythingResident;
        break;
      }
    } while (allAllocated != 0);
    listHead = M<int>(M<int>(self + kIOATIR500Surface_accelerator) + 0x5c);
    surfaceCursor = listHead;
    if (listHead != 0) {
      do {
        if (M<int>(surfaceCursor + 0xbd0) != 0) {
          if (surfaceCursor != 0) {
            return 1;
          }
          break;
        }
        prevLink = (int *)(surfaceCursor + 0x9c);
        surfaceCursor = *prevLink;
      } while (listHead != *prevLink);
    }
    movedAny = false;
    bufferIndex = 0;
    cursor = (UInt32)self;
    do {
      if (M<int>(cursor + 0xb0) != 0) {
        this->move_buffer_to_backing_store((ATIR500SurfaceBuffer *)((UInt8 *)(bufferIndex * 0x78 + self + kIOATIR500Surface_buffers)));
        movedAny = true;
      }
      notLast = bufferIndex != 0x16;
      cursor = cursor + 0x78;
      bufferIndex = bufferIndex + 1;
    } while (notLast);
    if (movedAny) {
      pending = mask & M<unsigned int>(self + kIOATIR500Surface_stateBits);
      if (pending == 0) goto everythingResident;
      index = 0;
      allAllocated = 1;
      do {
        bufferBit = 1 << (index & 0x3f);
        if ((pending & bufferBit) != 0) {
          allocOk = VCALL(M<int>(self), 0x5f4)
                            (self,index,(bufferBit & ((UInt32)keepMask)) == 0);
          allAllocated = allAllocated & allocOk;
        }
        index = index + 1;
        if ((pending >> (index & 0x3f) == 0) || (index == 0x17)) {
          if (allAllocated != 0) goto everythingResident;
          break;
        }
      } while (allAllocated != 0);
    }
    result = 2;
  }
  return result;
}
