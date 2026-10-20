/*
 * ATIR500Surface_getFramebufferIndex_Port.cpp
 *
 * ATIR500Surface::getFramebufferIndex (real addr 0x3a7a0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x3a7a0 */
UInt32 ATIR500Surface::getFramebufferIndex() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  bool notLast;
  SInt32 index;
  SInt32 result;
  
  result = 0;
  index = 0;
  do {
    if (((M<SInt32>(self + kIOATIR500Surface_regionRecordSize0) != 0) && (M<SInt16>(M<SInt32>(self + kIOATIR500Surface_regionRecords) + 8) != 0)) &&
       (M<SInt16>(M<SInt32>(self + kIOATIR500Surface_regionRecords) + 10) != 0)) {
      result = index;
    }
    notLast = index != 1;
    self = self + 8;
    index = index + 1;
  } while (notLast);
  return result;
}
