/*
 * IOATIR500Accelerator_allocVendorTextureBuffer_Port.cpp
 *
 * IOATIR500Accelerator::allocVendorTextureBuffer (real addr 0x4dc0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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

extern "C" UInt32 GH_IOMalloc(...) asm("_IOMalloc");


/* real addr 0x4dc0 */
VendorTextureBuffer *IOATIR500Accelerator::allocVendorTextureBuffer(UInt32 param_1) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  UInt32 *puVar1;
  
  puVar1 = (UInt32 *)GH_IOMalloc(param_1);
  M<UInt32>(self + 0x808) = param_1 + M<SInt32>(self + 0x808);
  M<UInt16>(puVar1 + 3) = 4;
  *puVar1 = 0;
  puVar1[1] = 0;
  puVar1[2] = 0;
  M<UInt16>((SInt32)puVar1 + 0xe) = 0;
  puVar1[4] = 0;
  puVar1[5] = 0;
  puVar1[6] = 0;
  puVar1[7] = 0;
  M<UInt16>((SInt32)puVar1 + 0x22) = 0;
  puVar1[0xb] = 0;
  puVar1[0xc] = 0;
  puVar1[0xf] = 0;
  puVar1[0x10] = 0;
  puVar1[0x11] = 0;
  puVar1[0x12] = 0;
  puVar1[0x13] = 0;
  puVar1[0x14] = 0;
  puVar1[0x15] = 0;
  puVar1[0x16] = 0;
  puVar1[0x18] = 0;
  puVar1[0x19] = 0;
  M<UInt16>(puVar1 + 0x1c) = 0;
  M<UInt16>((SInt32)puVar1 + 0x72) = 0;
  puVar1[9] = (UInt32)(puVar1);
  puVar1[10] = (UInt32)(puVar1);
  puVar1[0xd] = (UInt32)(puVar1);
  puVar1[0xe] = (UInt32)(puVar1);
  puVar1[0x1b] = 0xffffffff;
  puVar1[0x1a] = 0;
  puVar1[0x1d] = 0;
  M<UInt16>(puVar1 + 0x1e) = 0;
  M<UInt16>((SInt32)puVar1 + 0x7a) = 0;
  puVar1[0x1f] = 0;
  return (VendorTextureBuffer *)puVar1;   /* r3 still holds the IOMalloc result at the blr */
}
