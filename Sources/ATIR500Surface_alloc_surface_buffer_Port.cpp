/*
 * ATIR500Surface_alloc_surface_buffer_Port.cpp
 *
 * ATIR500Surface::alloc_surface_buffer (real addr 0x3e230, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x3e230 */
UInt32 ATIR500Surface::alloc_surface_buffer(ATIR500SurfaceBuffer *buffer) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *bufferBytes = reinterpret_cast<UInt8 *>(buffer);

  UInt16 height;
  int alignment;
  UInt32 hzBlockHandle;
  UInt32 chromaPitch;
  UInt32 vramLimit;
  UInt32 alignedPitch;
  UInt32 firstHzBlock;
  unsigned int tilingBits;
  unsigned int pitchPerDegree;
  unsigned int alignedHeight;
  unsigned int minPitch;
  int accel;
  int allocOk;
  int numPipes;
  unsigned int usesHzmem;
  
  tilingBits = M<unsigned int>(bufferBytes + 0x3c);
  usesHzmem = tilingBits >> 0xb & 1;
  if (((M<unsigned int>(self + kIOATIR500Surface_modeBits) & 0x700000) == 0) ||
     ((usesHzmem == 0 && (bufferBytes != (UInt8 *)(self + kIOATIR500Surface_buffer9))))) {
    accel = M<int>(self + kIOATIR500Surface_accelerator);
    if (M<UInt16>(accel + 0xa8) < M<UInt16>(bufferBytes + 0x1c)) {
      return 0;
    }
    if (M<UInt16>(accel + 0xaa) < M<UInt16>(bufferBytes + 0x1e)) {
      return 0;
    }
  }
  else {
    if (((tilingBits & 0xf00000) != 0) &&
       (0x1000 < (unsigned int)M<UInt16>(bufferBytes + 0x1c) / (tilingBits >> 0x14 & 0xf))) {
      return 0;
    }
    if (0x1000 < M<UInt16>(bufferBytes + 0x1e)) {
      return 0;
    }
    accel = M<int>(self + kIOATIR500Surface_accelerator);
  }
  if (M<int>(self + kIOATIR500Surface_boundDVDContext) == 0) {
LAB_0003e330:
    if (M<int>(accel + 0xd0) == 0) {
      allocOk = ((ATIR500Memory *)(M<UInt8 *>(accel + 0x7c)))->alloc((GLKMemoryElement *)((UInt8 *)bufferBytes),
                         M<UInt32>(bufferBytes + 0x10),0x1000,0x10000,M<int>(accel + 0x84c) - 0x10000);
    }
    else {
      allocOk = ((ATIR500Memory *)(M<UInt8 *>(accel + 0x7c)))->alloc((GLKMemoryElement *)((UInt8 *)bufferBytes),
                         M<UInt32>(bufferBytes + 0x10),0x1000,0,M<UInt32>(accel + 0x84c));
    }
    if (allocOk == 0) {
      return 0;
    }
  }
  else {
    vramLimit = M<UInt32>(accel + 0x84c);
    if ((M<unsigned int>(accel + 0x9c) <= vramLimit) ||
       ((1 < (UInt8)((char)bufferBytes[0x3a] - 0x2dU) && (bufferBytes[0x3a] != 0xb))))
    goto LAB_0003e330;
    allocOk = ((ATIR500Memory *)(M<UInt8 *>(accel + 0x7c)))->alloc((GLKMemoryElement *)((UInt8 *)bufferBytes),
                       M<UInt32>(bufferBytes + 0x10),0x1000,vramLimit,M<unsigned int>(accel + 0x9c) - vramLimit);
    if (allocOk == 0) {
      accel = M<int>(self + kIOATIR500Surface_accelerator);
      goto LAB_0003e330;
    }
  }
  if (usesHzmem == 0) {
    if (bufferBytes != (UInt8 *)(self + kIOATIR500Surface_buffer9)) {
      return 1;
    }
    pitchPerDegree = 0;
    numPipes = M<int>(M<int>(self + kIOATIR500Surface_accelerator) + 0xb98);
    if ((M<unsigned int>(bufferBytes + 0x3c) & 0xf00000) != 0) {
      pitchPerDegree = (unsigned int)M<UInt16>(bufferBytes + 0x14) / (M<unsigned int>(bufferBytes + 0x3c) >> 0x14 & 0xf);
    }
    minPitch = 0x20 / M<UInt16>(bufferBytes + 0x16);
    if (0x20 / M<UInt16>(bufferBytes + 0x16) <= pitchPerDegree) {
      minPitch = pitchPerDegree;
    }
    alignment = 0x20;
    if (numPipes != 4) {
      alignment = numPipes << 4;
      alignedPitch = 0;
      if (alignment == 0) goto LAB_0003e544;
    }
    alignedPitch = alignment * ((int)(alignment + minPitch + -1) / alignment);
LAB_0003e544:
    height = M<UInt16>(bufferBytes + 0x1e);
    alignedHeight = (unsigned int)height;
    if ((height & 0x1f) != 0) {
      alignedHeight = (height & 0xffffffe0) + 0x20;
    }
    hzBlockHandle = HZMEM_Alloc((_HZDATA *)((UInt8 *)(M<int>(self + kIOATIR500Surface_accelerator) + 0x870)),M<UInt32>(bufferBytes + 0x28),2,
                        alignedPitch,alignedHeight);
    M<UInt32>(bufferBytes + 0x28) = hzBlockHandle;
    return 1;
  }
  pitchPerDegree = 0;
  numPipes = M<int>(M<int>(self + kIOATIR500Surface_accelerator) + 0xb98);
  if ((M<unsigned int>(bufferBytes + 0x3c) & 0xf00000) != 0) {
    pitchPerDegree = (unsigned int)M<UInt16>(bufferBytes + 0x14) / (M<unsigned int>(bufferBytes + 0x3c) >> 0x14 & 0xf);
  }
  minPitch = 0x20 / M<UInt16>(bufferBytes + 0x16);
  if (0x20 / M<UInt16>(bufferBytes + 0x16) <= pitchPerDegree) {
    minPitch = pitchPerDegree;
  }
  alignment = 0x20;
  if (numPipes == 4) {
LAB_0003e3e8:
    alignedPitch = alignment * ((int)(alignment + minPitch + -1) / alignment);
  }
  else {
    alignment = numPipes << 4;
    alignedPitch = 0;
    if (alignment != 0) goto LAB_0003e3e8;
  }
  height = M<UInt16>(bufferBytes + 0x1e);
  alignedHeight = (unsigned int)height;
  if ((height & 0x1f) != 0) {
    alignedHeight = (height & 0xffffffe0) + 0x20;
  }
  firstHzBlock = HZMEM_Alloc((_HZDATA *)((UInt8 *)(M<int>(self + kIOATIR500Surface_accelerator) + 0x870)),M<UInt32>(bufferBytes + 0x28),0,alignedPitch
                      ,alignedHeight);
  M<UInt32>(bufferBytes + 0x28) = firstHzBlock;
  if (M<UInt16>(bufferBytes + 0x16) == 2) {
    tilingBits = M<unsigned int>(bufferBytes + 0x3c);
    if (1 < (tilingBits >> 0x14 & 0xf)) {
      return 1;
    }
  }
  else {
    tilingBits = M<unsigned int>(bufferBytes + 0x3c);
  }
  pitchPerDegree = 0;
  numPipes = M<int>(M<int>(self + kIOATIR500Surface_accelerator) + 0xb98);
  if ((tilingBits & 0xf00000) != 0) {
    pitchPerDegree = (unsigned int)M<UInt16>(bufferBytes + 0x14) / (tilingBits >> 0x14 & 0xf);
  }
  minPitch = 0x20 / M<UInt16>(bufferBytes + 0x16);
  if (minPitch <= pitchPerDegree) {
    minPitch = pitchPerDegree;
  }
  alignment = 0x20;
  if (numPipes != 4) {
    alignment = numPipes << 4;
    chromaPitch = 0;
    if (alignment == 0) goto LAB_0003e4a4;
  }
  chromaPitch = alignment * ((int)(alignment + minPitch + -1) / alignment);
LAB_0003e4a4:
  height = M<UInt16>(bufferBytes + 0x1e);
  alignedHeight = (unsigned int)height;
  if ((height & 0x1f) != 0) {
    alignedHeight = (height & 0xffffffe0) + 0x20;
  }
  hzBlockHandle = HZMEM_Alloc((_HZDATA *)((UInt8 *)(M<int>(self + kIOATIR500Surface_accelerator) + 0x870)),firstHzBlock,1,chromaPitch,alignedHeight);
  M<UInt32>(bufferBytes + 0x28) = hzBlockHandle;
  return 1;
}
