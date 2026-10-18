/*
 * IOATIR500Accelerator_addOrphanTexture_Port.cpp
 *
 * IOATIR500Accelerator::addOrphanTexture (real addr 0x49c0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x49c0 */
void IOATIR500Accelerator::addOrphanTexture(IOTextureBuffer *buffer) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *bufferBytes = reinterpret_cast<UInt8 *>(buffer);

  SInt32 nextNode;
  SInt32 prevNode;
  
  prevNode = M<SInt32>(bufferBytes + 0x24);
  M<UInt32>(prevNode + 0x28) = M<UInt32>(bufferBytes + 0x28);
  nextNode = M<SInt32>(bufferBytes + 0x28);
  M<UInt8 *>(bufferBytes + 0x28) = self + kIOATIR500Accelerator_orphanTextureList;
  M<SInt32>(nextNode + 0x24) = prevNode;
  M<UInt32>(bufferBytes + 0x24) = M<UInt32>(self + kIOATIR500Accelerator_orphanTextureList_prev);
  M<UInt8 *>(self + kIOATIR500Accelerator_orphanTextureList_prev) = bufferBytes;
  M<UInt8 *>(M<SInt32>(bufferBytes + 0x24) + 0x28) = bufferBytes;
  if (self[0x82] == 0x0) {
    VCALL(*M<SInt32 *>(self + kIOATIR500Accelerator_garbageCollectorTimer), 300)(M<SInt32 *>(self + kIOATIR500Accelerator_garbageCollectorTimer),100);
    self[0x82] = 0x1;
  }
  return;
}
