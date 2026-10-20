/*
 * IOATIR500Surface_prune_buffers_Port.cpp
 *
 * IOATIR500Surface::prune_buffers (real addr 0x12e80, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x12e80 */
void IOATIR500Surface::prune_buffers() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  bool isLast;
  UInt32 requestedBits;
  UInt32 requiredBits;
  UInt8 *cursor;
  UInt32 stateBits;
  UInt32 bufferIndex;
  SInt32 panelBuffer;
  SInt32 accelerator;
  
  if ((M<UInt32>(self + kIOATIR500Surface_modeBits) & 0x20) == 0) {
    requiredBits = M<UInt32>(self + kIOATIR500Surface_contextReqBits);
    if ((requiredBits & 2) == 0) {
      M<UInt8 *>(self + kIOATIR500Surface_attachmentBuffer5) = self + kIOATIR500Surface_buffer5;
      M<UInt8 *>(self + kIOATIR500Surface_attachmentBuffer4) = self + kIOATIR500Surface_buffer5;
      panelBuffer = M<SInt32>(self + kIOATIR500Surface_panel) * 0x78 + M<SInt32>(self + kIOATIR500Surface_accelerator) + 300;
      M<SInt32>(self + kIOATIR500Surface_attachmentBuffers) = panelBuffer;
      M<SInt32>(self + kIOATIR500Surface_attachmentBuffer1) = panelBuffer;
    }
    else if (M<SInt32>(self + kIOATIR500Surface_attachmentBuffer1) == M<SInt32>(self + kIOATIR500Surface_attachmentBuffers)) {
      M<UInt8 *>(self + kIOATIR500Surface_attachmentBuffer1) = self + kIOATIR500Surface_buffer1;
      M<UInt8 *>(self + kIOATIR500Surface_attachmentBuffer4) = self + kIOATIR500Surface_buffer4;
    }
    goto LAB_00012fec;
  }
  requiredBits = M<UInt32>(self + kIOATIR500Surface_contextReqBits);
  if ((requiredBits & 1) == 0) {
    if ((requiredBits & 2) == 0) {
      stateBits = M<UInt32>(self + kIOATIR500Surface_stateBits);
      if ((stateBits & 2) != 0) {
        requestedBits = M<UInt32>(self + kIOATIR500Surface_reqBits) | 1;
        M<UInt32>(self + kIOATIR500Surface_reqBits) = requestedBits;
        goto LAB_00012f00;
      }
    }
    else {
      stateBits = M<UInt32>(self + kIOATIR500Surface_stateBits);
    }
    requestedBits = M<UInt32>(self + kIOATIR500Surface_reqBits) | 2;
    M<UInt32>(self + kIOATIR500Surface_reqBits) = requestedBits;
  }
  else {
    stateBits = M<UInt32>(self + kIOATIR500Surface_stateBits);
    requestedBits = M<UInt32>(self + kIOATIR500Surface_reqBits) | 1;
    M<UInt32>(self + kIOATIR500Surface_reqBits) = requestedBits;
  }
LAB_00012f00:
  requiredBits = requiredBits | requestedBits;
  M<UInt32>(self + kIOATIR500Surface_contextReqBits) = requiredBits;
  if ((requiredBits & 1) == 0) {
    M<UInt8 *>(self + kIOATIR500Surface_attachmentBuffers) = self + kIOATIR500Surface_buffer1;
  }
  else {
    M<UInt8 *>(self + kIOATIR500Surface_attachmentBuffers) = self + kIOATIR500Surface_buffers;
  }
  if ((requiredBits & 2) == 0) {
    M<UInt8 *>(self + kIOATIR500Surface_attachmentBuffer1) = self + kIOATIR500Surface_buffers;
  }
  else {
    M<UInt8 *>(self + kIOATIR500Surface_attachmentBuffer1) = self + kIOATIR500Surface_buffer1;
  }
  if ((M<UInt32>(self + kIOATIR500Surface_modeBits) & 0x10) != 0) {
    if ((requiredBits & 0x20) == 0) {
      M<UInt8 *>(self + kIOATIR500Surface_attachmentBuffer5) = self + kIOATIR500Surface_buffer4;
    }
    else {
      M<UInt8 *>(self + kIOATIR500Surface_attachmentBuffer5) = self + kIOATIR500Surface_buffer5;
    }
    if ((requiredBits & 0x10) == 0) {
      M<UInt8 *>(self + kIOATIR500Surface_attachmentBuffer4) = self + kIOATIR500Surface_buffer5;
    }
    else {
      M<UInt8 *>(self + kIOATIR500Surface_attachmentBuffer4) = self + kIOATIR500Surface_buffer4;
    }
  }
  M<UInt32>(self + kIOATIR500Surface_stateBits) = stateBits | 0x10000000;
LAB_00012fec:
  bufferIndex = 0;
  cursor = self;
  while( true ) {
    if ((1 << (bufferIndex & 0x3f) & requiredBits) == 0) {
      VCALL(M<SInt32>(self), 0x5cc)(self,bufferIndex);
      if (M<SInt32>(cursor + 0xcc) != 0) {
        this->free_buffer_backing_store((ATIR500SurfaceBuffer *)((UInt8 *)(self + bufferIndex * 0x78 + 0xa8)));
      }
      if (M<SInt32>(cursor + 0xb8) != 0) {
        M<UInt16>(cursor + 0xbc) = 0;
        M<UInt16>(cursor + 0xbe) = 0;
        M<UInt16>(cursor + 0xc0) = 0;
        M<UInt16>(cursor + 0xc4) = 0;
        cursor[0xe4] = 0x0;
        cursor[0xdc] = 0x0;
        cursor[0xdd] = 0x0;
        cursor[0xde] = 0x0;
        cursor[0xe0] = 0x0;
        cursor[0xe1] = 0x0;
        cursor[0xdf] = 0xff;
        M<UInt16>(cursor + 0xc6) = 0;
        M<UInt16>(cursor + 200) = 1;
        M<UInt16>(cursor + 0xca) = 1;
        M<UInt32>(cursor + 0xa8) = 0;
        M<UInt32>(cursor + 0xac) = 0;
        M<UInt32>(cursor + 0xb0) = 0;
        M<UInt32>(cursor + 0xb4) = 0;
        M<UInt32>(cursor + 0xb8) = 0;
        M<UInt32>(cursor + 0xcc) = 0;
        M<UInt32>(cursor + 0xd0) = 0xffffffff;
        M<UInt32>(cursor + 0xd4) = 0;
        M<UInt32>(cursor + 0xd8) = 0;
        cursor[0xe3] = 0x6;
        M<UInt32>(self + bufferIndex * 0x78 + 0xe4) =
             M<UInt32>(self + bufferIndex * 0x78 + 0xe4) & 0xff0007ff | 0x111000;
        M<UInt32>(cursor + 0xec) = 0;
        M<UInt32>(cursor + 0xe8) = 0;
      }
    }
    isLast = bufferIndex == 0x16;
    cursor = cursor + 0x78;
    bufferIndex = bufferIndex + 1;
    if (isLast) break;
    requiredBits = M<UInt32>(self + kIOATIR500Surface_contextReqBits);
  }
  VCALL(M<SInt32>(self), 0x5c8)(self);
  if (M<SInt32>(self + kIOATIR500Surface_panel) == 0xffff) {
    accelerator = M<SInt32>(self + kIOATIR500Surface_accelerator);
  }
  else {
    accelerator = M<SInt32>(self + kIOATIR500Surface_accelerator);
    if (self == M<UInt8 *>(M<SInt32>(self + kIOATIR500Surface_panel) * 0x20 + accelerator + 0xe8)) {
      VCALL(M<SInt32>(self), 0x5a4)(self);
      accelerator = M<SInt32>(self + kIOATIR500Surface_accelerator);
    }
  }
  M<UInt32>(accelerator + kIOATIR500Accelerator_unknown_0x78) = 0;
  return;
}
