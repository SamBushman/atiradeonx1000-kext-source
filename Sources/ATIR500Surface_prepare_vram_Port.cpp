/*
 * ATIR500Surface_prepare_vram_Port.cpp
 *
 * ATIR500Surface::prepare_vram (real addr 0x3dc50, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x3dc50 */
UInt32 ATIR500Surface::prepare_vram(ATIR500SurfaceBuffer *buffer) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *bufferBytes = reinterpret_cast<UInt8 *>(buffer);

  UInt8 prepareCount;
  UInt8 tilingByte1;
  UInt32 nextSlot;
  SInt32 formatCode;
  SInt32 *accel;
  UInt32 stamp;
  SInt32 scratchCmd;
  SInt32 endIndex;
  UInt32 slotIndex;
  UInt32 formatBits;
  UInt32 tailIndex;
  SInt32 accelBase;
  SInt32 slotOffset;
  SInt32 endMarkerOffset;
  UInt32 busyMask;
  UInt32 sizeBits;
  UInt32 packetWords;
  SInt32 gpuBase;
  SInt32 markerIndex;
  UInt8 *accelBytes;
  UInt32 *packet;
  
  prepareCount = bufferBytes[0x3c];
  bufferBytes[0x3c] = ((char)prepareCount + 1U);
  if (1 < (UInt8)((char)prepareCount + 1U)) {
    return 1;
  }
  accelBase = M<SInt32>(self + kIOATIR500Surface_accelerator);
  if (M<UInt8>(accelBase + 0x990) == 0) {
LAB_0003dcc0:
    bufferBytes[0x3c] = 0x0;
    return 0;
  }
  busyMask = M<UInt32>(accelBase + kIOATIR500Accelerator_vramPreparedMask);
  slotIndex = 0;
  if ((busyMask & 1) == 0) {
    slotIndex = 0;
  }
  else {
    do {
      nextSlot = slotIndex + 1;
      slotIndex = nextSlot & 0xff;
      if (slotIndex == M<UInt8>(accelBase + 0x990)) goto LAB_0003dcc0;
    } while ((busyMask & 1 << (nextSlot & 0x3f)) != 0);
  }
  M<UInt32>(accelBase + kIOATIR500Accelerator_vramPreparedMask) = 1 << (slotIndex & 0x3f) | busyMask;
  bufferBytes[0x37] = SUB41m(slotIndex,0);
  accel = M<SInt32 *>(self + kIOATIR500Surface_accelerator);
  if (M<char>(accel + 0x20) == '\0') {
    return 1;
  }
  scratchCmd = accel[0x8e];
  slotOffset = slotIndex * 4;
  gpuBase = M<SInt32>(bufferBytes + 8);
  packet = (UInt32 *)(scratchCmd + 0x120);
  if ((M<UInt32>(bufferBytes + 0x3c) >> 0x14 & 0xf) < 2) {
    switch(bufferBytes[0x38]) {
    default:
      goto switchD_0003dd5c_caseD_0;
    case 0x1:
      formatCode = 1;
      break;
    case 0x2:
      formatCode = 2;
      break;
    case 0x3:
      formatCode = 3;
      break;
    case 0x4:
      formatCode = 6;
      break;
    case 0x5:
      formatCode = 7;
    }
    formatBits = formatCode << 0x10;
    sizeBits = (UInt32)(M<UInt16>(bufferBytes + 0x18) >> 3);
  }
  else {
switchD_0003dd5c_caseD_0:
    sizeBits = 0;
    formatBits = 0;
  }
  tilingByte1 = bufferBytes[0x39];
  VCALL(*accel, 0x54c)(accel,accel[0x8d]);
  *packet = slotOffset + 0x2c1;
  M<SInt32>(scratchCmd + 0x124) = gpuBase;
  M<SInt32>(scratchCmd + 0x128) = slotOffset + 0x2c2;
  M<SInt32>(scratchCmd + 300) = gpuBase + M<SInt32>(bufferBytes + 0x10) + -1;
  M<SInt32>(scratchCmd + 0x130) = slotOffset + 0x2c3;
  M<UInt32>(scratchCmd + 0x134) = formatBits | sizeBits | ((UInt8)tilingByte1 & 3) << 0x14 | ((UInt8)tilingByte1 & 3) << 0x16;
  if ((M<UInt32>(bufferBytes + 0x3c) & 0x800) == 0) {
    M<UInt32>(scratchCmd + 0x138) = 0xd0b;
    M<UInt32>(scratchCmd + 0x13c) = 5;
    M<UInt32>(scratchCmd + 0x140) = 0x1393;
    M<UInt32>(scratchCmd + 0x144) = 10;
    endIndex = 10;
    endMarkerOffset = 0x28;
    markerIndex = 0xb;
    tailIndex = 0xc;
  }
  else {
    endIndex = this->decompress_and_flush_depth_buffer((ATIR500SurfaceBuffer *)(bufferBytes),6,(UInt32 *)(packet));
    endMarkerOffset = endIndex << 2;
    markerIndex = endIndex + 1;
    tailIndex = endIndex + 2;
  }
  M<UInt32>((SInt32)packet + endMarkerOffset) = 0x5c8;
  packet[markerIndex] = 0x70000;
  packetWords = tailIndex;
  if ((tailIndex & 7) != 0) {
    packetWords = endIndex + 3;
    packet[tailIndex] = 0x80000000;
  }
  accelBytes = M<UInt8 *>(self + kIOATIR500Surface_accelerator);
  stamp = ((ATIRadeonX1000 *)(accelBytes))->submit_buffer((UInt32 *)(packet), M<SInt32>(accelBytes + kIOATIR500Accelerator_scratchBufferGartOffset) + 0x120, packetWords);
  M<UInt32>(accelBytes + kIOATIR500Accelerator_scratchCommandBuffer_0x10) = stamp;
  accel = M<SInt32 *>(self + kIOATIR500Surface_accelerator);
  VCALL(*accel, 0x54c)(accel,accel[0x8d]);
  return 1;
}
