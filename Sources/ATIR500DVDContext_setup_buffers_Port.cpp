/*
 * ATIR500DVDContext_setup_buffers_Port.cpp
 *
 * ATIR500DVDContext::setup_buffers (real addr 0x34260, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x34260 */
IOReturn ATIR500DVDContext::setup_buffers(UInt32 param_1, UInt32 param_2, UInt32 param_3, UInt32 param_4, UInt32 param_5) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  if ((M<SInt32>(self + 0xf8) != 0) && (M<char>(M<SInt32>(self + 0x8c) + 0x80) != '\0')) {
    M<UInt8>(M<SInt32>(self + 0xf8) + 0xbed) = 1;
    M<UInt8>(M<SInt32>(self + 0xf8) + 0xbee) = 1;
    M<SInt16>(M<SInt32>(self + 0xf8) + 0x94) = (SInt16)param_1;
    M<SInt16>(M<SInt32>(self + 0xf8) + 0x9a) = (SInt16)param_3;
    M<SInt16>(M<SInt32>(self + 0xf8) + 0x96) = (SInt16)param_4;
    M<SInt16>(M<SInt32>(self + 0xf8) + 0x98) = (SInt16)param_2;
    M<UInt32>(self + 0x88) = param_5 & 0xfffffc00 | 0x20000002;
    return 0;
  }
  return 0xe00002d8;
}
