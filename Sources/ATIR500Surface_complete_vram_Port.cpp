/*
 * ATIR500Surface_complete_vram_Port.cpp
 *
 * ATIR500Surface::complete_vram (real addr 0x3c000, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x3c000 */
UInt32 ATIR500Surface::complete_vram(ATIR500SurfaceBuffer *buffer) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *bufferBytes = reinterpret_cast<UInt8 *>(buffer);

  UInt32 bitIndex;
  SInt32 slotOffset;
  UInt32 uVar3;
  UInt8 bufferSlot;
  SInt32 *accel;
  UInt8 *accelBytes;
  SInt32 packet;
  
  uVar3 = 0;
  if (bufferBytes[0x3c] != 0x0) {
    bufferSlot = ((char)bufferBytes[0x3c] + -1);
    bufferBytes[0x3c] = bufferSlot;
    if (bufferSlot == 0x0) {
      bufferSlot = bufferBytes[0x37];
      bufferBytes[0x37] = 0xff;
      bitIndex = (UInt8)bufferSlot & 0x1f;
      M<UInt32>(M<SInt32>(self + kIOATIR500Surface_accelerator) + 0x890) =
           (-2 << bitIndex | 0xfffffffeU >> 0x20 - bitIndex) & M<UInt32>(M<SInt32>(self + kIOATIR500Surface_accelerator) + 0x890);
      accel = M<SInt32 *>(self + kIOATIR500Surface_accelerator);
      if (M<char>(accel + 0x20) != '\0') {
        packet = accel[0x8e];
        slotOffset = (UInt32)(UInt8)bufferSlot * 4;
        VCALL(*accel, 0x54c)(accel,accel[0x8d]);
        M<UInt32>(packet + 0x120) = slotOffset + 0x2c1;
        M<UInt32>(packet + 0x124) = 0;
        M<SInt32>(packet + 0x128) = slotOffset + 0x2c2;
        M<UInt32>(packet + 300) = 0;
        M<SInt32>(packet + 0x130) = slotOffset + 0x2c3;
        M<UInt32>(packet + 0x134) = 0;
        accelBytes = M<UInt8 *>(self + kIOATIR500Surface_accelerator);
        uVar3 = ((ATIRadeonX1000 *)(accelBytes))->submit_buffer((UInt32 *)(packet + 0x120),M<SInt32>(accelBytes + kIOATIR500Accelerator_scratchBufferGartOffset) + 0x120,6);
        M<UInt32>(accelBytes + kIOATIR500Accelerator_scratchCommandBuffer_0x10) = uVar3;
        return 1;
      }
    }
    uVar3 = 1;
  }
  return uVar3;
}
