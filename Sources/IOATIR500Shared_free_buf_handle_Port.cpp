/*
 * IOATIR500Shared_free_buf_handle_Port.cpp
 *
 * IOATIR500Shared::free_buf_handle (real addr 0x16cf0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x16cf0 */
void IOATIR500Shared::free_buf_handle(void*param_1, UInt32 param_2) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  UInt32 uVar1;
  
  if (M<UInt32>(self + 0x14) <= param_2) {
    return;
  }
  if (M<void *>(M<SInt32>(self + 0x10) + param_2 * 4) != param_1) {
    return;
  }
  if (param_2 < M<UInt32>(self + 0x1c)) {
    M<UInt32>(self + 0x1c) = param_2;
  }
  uVar1 = param_2 >> 3 & 0x1ffffffc;
  M<UInt32>(param_2 * 4 + M<SInt32>(self + 0x10)) = 0;
  M<UInt32>(uVar1 + M<SInt32>(self + 0x18)) =
       (-2 << (param_2 & 0x1f) | 0xfffffffeU >> 0x20 - (param_2 & 0x1f)) &
       M<UInt32>(uVar1 + M<SInt32>(self + 0x18));
  return;
}
