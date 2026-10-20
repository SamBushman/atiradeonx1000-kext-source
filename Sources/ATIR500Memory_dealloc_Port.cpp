/*
 * ATIR500Memory_dealloc_Port.cpp
 *
 * ATIR500Memory::dealloc (real addr 0x197d0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x197d0 */
UInt32 ATIR500Memory::dealloc(GLKMemoryElement *elem) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *elemBytes = reinterpret_cast<UInt8 *>(elem);

  UInt32 *spareNode;
  SInt32 refilled;
  SInt32 *nodePrev;
  SInt32 *node;
  SInt32 elemOffset;
  SInt32 oldSpareHead;
  
  elemOffset = M<SInt32>(elemBytes + 8);
  if ((M<SInt32>(self + kATIR500Memory_spareNodeStack) == 0) && (refilled = this->add_to_stack(), refilled == 0)) {
    return 0;
  }
  nodePrev = M<SInt32 *>(elemBytes + 4);
  node = M<SInt32 *>(elemBytes);
  M<UInt32>(elemBytes + 0xc) = 0;
  M<UInt32>(elemBytes + 4) = 0;
  M<UInt32>(elemBytes) = 0;
  M<UInt32>(elemBytes + 8) = 0;
  if ((nodePrev[3] & node[3]) < 0) {
    *nodePrev = *node;
    M<SInt32 *>(*node + 4) = nodePrev;
    oldSpareHead = M<SInt32>(self + kATIR500Memory_spareNodeStack);
    node[3] = 0;
    node[1] = 0;
    node[2] = 0;
    *node = oldSpareHead;
    M<SInt32 *>(self + kATIR500Memory_spareNodeStack) = node;
  }
  else if (nodePrev[3] < 0) {
    node[1] = (SInt32)nodePrev;
    *nodePrev = (SInt32)node;
  }
  else if (node[3] < 0) {
    node[2] = elemOffset;
    node[1] = (SInt32)nodePrev;
    *nodePrev = (SInt32)node;
  }
  else {
    spareNode = M<UInt32 *>(self + kATIR500Memory_spareNodeStack);
    M<UInt32>(self + kATIR500Memory_spareNodeStack) = *spareNode;
    *nodePrev = (SInt32)spareNode;
    node[1] = (SInt32)spareNode;
    spareNode[3] = 0x80000000;
    spareNode[2] = elemOffset;
    *spareNode = (UInt32)(node);
    spareNode[1] = (UInt32)(nodePrev);
  }
  return 1;
}
