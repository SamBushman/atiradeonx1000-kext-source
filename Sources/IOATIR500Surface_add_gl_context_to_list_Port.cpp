/*
 * IOATIR500Surface_add_gl_context_to_list_Port.cpp
 *
 * IOATIR500Surface::add_gl_context_to_list (real addr 0x10b80, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x10b80 */
void IOATIR500Surface::add_gl_context_to_list(IOATIR500GLContext *context) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *contextBytes = reinterpret_cast<UInt8 *>(context);

  M<UInt32>(contextBytes + 0x84) = M<UInt32>(self + kIOATIR500Surface_glContextList);
  M<UInt8 *>(self + kIOATIR500Surface_glContextList) = contextBytes;
  M<UInt32>(self + kIOATIR500Surface_contextReqBits) = M<UInt32>(self + kIOATIR500Surface_contextReqBits) | M<UInt32>(contextBytes + 0x8c);
  return;
}
