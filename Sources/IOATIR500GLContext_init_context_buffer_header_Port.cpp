/*
 * IOATIR500GLContext_init_context_buffer_header_Port.cpp
 *
 * IOATIR500GLContext::init_context_buffer_header (real addr 0x7490, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x7490 */
void IOATIR500GLContext::init_context_buffer_header(VendorContextBufferHeader *header, UInt32 size) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *headerBytes = reinterpret_cast<UInt8 *>(header);

  SInt32 offset;
  SInt32 wordsLeft;
  
  offset = 0;
  wordsLeft = 8;
  do {
    M<UInt32>(headerBytes + offset) = 0;
    offset = offset + 4;
    wordsLeft = wordsLeft + -1;
  } while (wordsLeft != 0);
  M<UInt32>(headerBytes + 0x1c) = 1;
  M<UInt32>(headerBytes + 0x10) = (size - 0x20 >> 2) - 0x91;
  return;
}
