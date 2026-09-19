/*
 * convertIOGLBufferToBufIdx_Port.cpp
 *
 * convertIOGLBufferToBufIdx (real addr 0x26ce0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x26ce0 */
UInt32 convertIOGLBufferToBufIdx(UInt32 param_1, UInt32 *param_2) {

  switch(param_1) {
  case 0:
    *param_2 = 1;
    return 1;
  case 1:
    *param_2 = 0;
    return 1;
  case 2:
    *param_2 = 4;
    return 1;
  case 3:
    *param_2 = 5;
    return 1;
  case 4:
    *param_2 = 6;
    return 1;
  default:
    *param_2 = 1;
    return 0;
  case 7:
    *param_2 = 2;
    return 1;
  case 8:
    *param_2 = 3;
    return 1;
  }
}
