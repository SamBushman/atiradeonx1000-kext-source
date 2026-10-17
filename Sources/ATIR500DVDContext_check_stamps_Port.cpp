/*
 * ATIR500DVDContext_check_stamps_Port.cpp
 *
 * ATIR500DVDContext::check_stamps (real addr 0x341a0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x341a0 */
IOReturn ATIR500DVDContext::check_stamps(UInt32 checkMain, UInt32 checkIDCT, UInt32*outBothDone) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  UInt32 bothDone;
  SInt32 idctDone;
  SInt32 mainDone;
  
  mainDone = 1;
  if (checkMain != 0) {
    /* r4 (the first stamp) is left untouched by the shipped code, so it is forwarded to the accelerator's check (vtable +0x5f4); the decompile dropped it */
    mainDone = VCALL(*M<SInt32 *>(self + 0x8c), 0x5f4)(M<SInt32 *>(self + 0x8c),checkMain);
  }
  idctDone = 1;
  if (checkIDCT != 0) {
    idctDone = VCALL(*M<SInt32 *>(self + 0x8c), 0x554)(M<SInt32 *>(self + 0x8c),checkIDCT);
  }
  if ((mainDone == 0) || (bothDone = 1, idctDone == 0)) {
    bothDone = 0;
  }
  *outBothDone = bothDone;
  return 0;
}
