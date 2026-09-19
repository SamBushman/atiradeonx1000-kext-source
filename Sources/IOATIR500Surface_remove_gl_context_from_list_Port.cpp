/*
 * IOATIR500Surface_remove_gl_context_from_list_Port.cpp
 *
 * IOATIR500Surface::remove_gl_context_from_list (real addr 0x13ec0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x13ec0 */
void IOATIR500Surface::remove_gl_context_from_list(IOATIR500GLContext *real_param_1) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *param_1 = reinterpret_cast<UInt8 *>(real_param_1);

  UInt8 *pIVar1;
  UInt8 *pIVar2;
  
  pIVar1 = M<UInt8 *>(self + 0x88);
  if (M<UInt8 *>(self + 0x88) == param_1) {
    M<UInt32>(self + 0x88) = M<UInt32>(param_1 + 0x84);
  }
  else {
    do {
      pIVar2 = pIVar1;
      pIVar1 = M<UInt8 *>(pIVar2 + 0x84);
      if (pIVar1 == (UInt8 *)0x0) break;
    } while (param_1 != pIVar1);
    M<UInt32>(pIVar2 + 0x84) = M<UInt32>(param_1 + 0x84);
  }
  M<UInt32>(param_1 + 0x84) = 0;
  this->reset_req_bits();
  return;
}
