/*
 * IOATIR500Accelerator_init_command_buffer_header_Port.cpp
 *
 * IOATIR500Accelerator::init_command_buffer_header (real addr 0x2350, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x2350 */
void IOATIR500Accelerator::init_command_buffer_header(VendorCommandBufferHeader *header, UInt32 size) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *headerBytes = reinterpret_cast<UInt8 *>(header);

  SInt32 byteOffset;
  SInt32 wordsLeft;
  
  wordsLeft = 8;
  byteOffset = 0;
  do {
    M<UInt32>(headerBytes + byteOffset) = 0;
    byteOffset = byteOffset + 4;
    wordsLeft = wordsLeft + -1;
  } while (wordsLeft != 0);
  VCALL(M<SInt32>(self), 0x564)(self,headerBytes + 0x20);
  M<UInt32>(headerBytes + 0x10) = size - 0x20 >> 2;
  M<SInt32>(headerBytes + 0x18) = M<SInt32>(self + kIOATIR500Accelerator_submitStamp) + -1;
  return;
}
