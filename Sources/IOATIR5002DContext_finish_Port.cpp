/*
 * IOATIR5002DContext_finish_Port.cpp
 *
 * IOATIR5002DContext::finish (real addr 0xbdc0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0xbdc0 */
IOReturn IOATIR5002DContext::finish(UInt32 mode) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  code *pcVar1;
  SInt32 *piVar2;
  SInt32 iVar3;
  SInt32 currentStamp;
  SInt32 waited;
  SInt32 *accelWords;
  code *waitRoutine;
  
  if (mode == 1) {
    accelWords = M<SInt32 *>(self + kIOATIR5002DContext_accelerator);
    currentStamp = accelWords[0x14];
    waitRoutine = M<code *>(*accelWords + 0x55c);
  }
  else {
    if (mode == 0) {
      waited = VCALL(*M<SInt32 *>(self + kIOATIR5002DContext_accelerator), 0x55c)
                        (M<SInt32 *>(self + kIOATIR5002DContext_accelerator),M<UInt32>(self + kIOATIR5002DContext_lastSubmitStamp));
      if (waited == -1) {
        return 0xe00002d6;
      }
      M<SInt32>(M<SInt32>(self + kIOATIR5002DContext_accelerator) + 0x7a4) = waited + M<SInt32>(M<SInt32>(self + kIOATIR5002DContext_accelerator) + 0x7a4);
      return 0;
    }
    if (mode != 2) {
      return 0xe00002c2;
    }
    accelWords = M<SInt32 *>(self + kIOATIR5002DContext_accelerator);
    currentStamp = accelWords[0x14];
    waitRoutine = M<code *>(*accelWords + 0x558);
  }
  waited = (*waitRoutine)(accelWords,currentStamp + -1);
  if (waited == -1) {
    return 0xe00002d6;
  }
  M<SInt32>(M<SInt32>(self + kIOATIR5002DContext_accelerator) + 0x7a0) = waited + M<SInt32>(M<SInt32>(self + kIOATIR5002DContext_accelerator) + 0x7a0);
  return 0;
}
