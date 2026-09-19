/*
 * IOATIR500Surface_move_buffer_to_backing_store_Port.cpp
 *
 * IOATIR500Surface::move_buffer_to_backing_store (real addr 0x11420, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x11420 */
bool IOATIR500Surface::move_buffer_to_backing_store(ATIR500SurfaceBuffer *real_param_1) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *param_1 = reinterpret_cast<UInt8 *>(real_param_1);

  UInt32 uVar1;
  
  uVar1 = this->copy_buffer_to_backing_store((ATIR500SurfaceBuffer *)(param_1));
  VCALL(M<SInt32>(self), 0x5cc)(self,((SInt32)param_1 - (SInt32)(self + 0xa8) >> 3) * -0x11111111);
  return uVar1;
}
