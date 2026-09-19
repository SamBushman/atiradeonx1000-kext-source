/*
 * IOATIR500Surface_free_buffer_backing_store_Port.cpp
 *
 * IOATIR500Surface::free_buffer_backing_store (real addr 0x12df0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x12df0 */
UInt32 IOATIR500Surface::free_buffer_backing_store(ATIR500SurfaceBuffer *real_param_1) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *param_1 = reinterpret_cast<UInt8 *>(real_param_1);

  UInt8 *pIVar1;
  
  pIVar1 = M<UInt8 *>(param_1 + 0x24);
  if (pIVar1[0x59] == 0x0) {
    if ((M<SInt32>(pIVar1 + 0x10) == 0) || (M<SInt32>(self + 0xd8c) != 0)) {
      this->delete_buffer_backing((IOTextureBuffer *)(pIVar1));
    }
    else {
      M<UInt8 *>(self + 0xd8c) = pIVar1;
    }
    M<UInt32>(param_1 + 0x24) = 0;
  }
  return 1;
}
