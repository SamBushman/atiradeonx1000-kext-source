/*
 * ATIRadeonX1000_submit_empty_buffer_Port.cpp
 *
 * ATIRadeonX1000::submit_empty_buffer (real addr 0x1bca0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x1bca0 */
void ATIRadeonX1000::submit_empty_buffer() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  SInt32 mmioBase;
  UInt32 pcieIndirectValue;
  SInt32 triesLeft;
  
  if (self[0x80] == 0x0) {
    return;
  }
  pcieIndirectValue = M<UInt32>(self + kIOATIR500Accelerator_pcieIndirectRegValue);
  M<UInt32>(self + kIOATIR500Accelerator_transferMappedFlag) = 0;
  mmioBase = M<SInt32>(self + kIOATIR500Accelerator_mmioBase);
  triesLeft = 0x2711;
  do {
    M<UInt32>(mmioBase + 0x30) = 0x10000000;
    enforceInOrderExecutionIO();
    M<UInt32>(mmioBase + 0x34) =
         pcieIndirectValue << 0x18 | (pcieIndirectValue & 0xff00 | 0x100) << 8 | (pcieIndirectValue & 0xff0000) >> 8 | pcieIndirectValue >> 0x18;
    enforceInOrderExecutionIO();
    M<UInt32>(mmioBase + 0x30) = 0x10000000;
    enforceInOrderExecutionIO();
    M<UInt32>(mmioBase + 0x34) =
         pcieIndirectValue << 0x18 | (pcieIndirectValue & 0xff00) << 8 | pcieIndirectValue >> 8 & 0xff00 | pcieIndirectValue >> 0x18;
    enforceInOrderExecutionIO();
    M<UInt32>(mmioBase + 0x30) = 0x22000000;
    enforceInOrderExecutionIO();
    if (loadWordByteReversed(&M<UInt8>(mmioBase + 0x34)) == 0) {      /* one byte-reversed read, as the shipped code (Ghidra showed four byte loads) */
      return;
    }
    triesLeft = triesLeft + -1;
  } while (triesLeft != 0);
  return;
}
