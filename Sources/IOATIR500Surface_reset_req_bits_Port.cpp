/*
 * IOATIR500Surface_reset_req_bits_Port.cpp
 *
 * IOATIR500Surface::reset_req_bits (real addr 0x13c70, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x13c70 */
void IOATIR500Surface::reset_req_bits() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  UInt32 requiredBits;
  SInt32 node;
  UInt32 bufferMask [8];
  
  node = M<SInt32>(self + kIOATIR500Surface_glContextList);
  requiredBits = M<UInt32>(self + kIOATIR500Surface_reqBits) & 0x30000020;
  M<UInt32>(self + kIOATIR500Surface_reqBits) = requiredBits;
  M<UInt32>(self + kIOATIR500Surface_contextReqBits) = requiredBits;
  for (; node != 0; node = M<SInt32>(node + 0x84)) {
    requiredBits = requiredBits | M<UInt32>(node + 0x8c);
    M<UInt32>(self + kIOATIR500Surface_contextReqBits) = requiredBits;
  }
  node = M<SInt32>(self + kIOATIR500Surface_context2DList);
  if (node != 0) {
    requiredBits = M<UInt32>(self + kIOATIR500Surface_contextReqBits);
    do {
      requiredBits = requiredBits | M<UInt32>(node + 0x8c);
      M<UInt32>(self + kIOATIR500Surface_contextReqBits) = requiredBits;
      node = M<SInt32>(node + 0x84);
    } while (node != 0);
  }
  for (node = M<SInt32>(self + kIOATIR500Surface_backingStoreList); node != 0; node = M<SInt32>(node + 0x54)) {
    if (M<UInt32>(node + 0x58) == 0x11) {
      if (((M<UInt32>(self + kIOATIR500Surface_stateBits) & 2) == 0) || (M<SInt32>(self + kIOATIR500Surface_buffer1BackingStore) != 0)) {
        M<UInt32>(self + kIOATIR500Surface_contextReqBits) = M<UInt32>(self + kIOATIR500Surface_contextReqBits) | 2;
      }
      else if (((M<UInt32>(self + kIOATIR500Surface_stateBits) & 1) == 0) || (M<SInt32>(self + kIOATIR500Surface_buffer0BackingStore) != 0)) {
        M<UInt32>(self + kIOATIR500Surface_contextReqBits) = M<UInt32>(self + kIOATIR500Surface_contextReqBits) | 1;
      }
    }
    else {
      this->surface_buffer_idx_mask(M<UInt32>(node + 0x58),(UInt32 *)(bufferMask));
      M<UInt32>(self + kIOATIR500Surface_contextReqBits) = M<UInt32>(self + kIOATIR500Surface_contextReqBits) | bufferMask[0];
    }
  }
  if (M<SInt32>(self + kIOATIR500Surface_boundDVDContext) != 0) {
    M<UInt32>(self + kIOATIR500Surface_contextReqBits) = M<UInt32>(self + kIOATIR500Surface_contextReqBits) | M<UInt32>(M<SInt32>(self + kIOATIR500Surface_boundDVDContext) + 0x88);
  }
  return;
}
