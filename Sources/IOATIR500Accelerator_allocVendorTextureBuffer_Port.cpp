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
VendorTextureBuffer *IOATIR500Accelerator::allocVendorTextureBuffer(UInt32 size) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  UInt32 *texture;
  
  texture = (UInt32 *)GH_IOMalloc(size);
  M<UInt32>(self + 0x808) = size + M<SInt32>(self + 0x808);
  M<UInt16>(texture + 3) = 4;
  *texture = 0;
  texture[1] = 0;
  texture[2] = 0;
  M<UInt16>((SInt32)texture + 0xe) = 0;
  texture[4] = 0;
  texture[5] = 0;
  texture[6] = 0;
  texture[7] = 0;
  M<UInt16>((SInt32)texture + 0x22) = 0;
  texture[0xb] = 0;
  texture[0xc] = 0;
  texture[0xf] = 0;
  texture[0x10] = 0;
  texture[0x11] = 0;
  texture[0x12] = 0;
  texture[0x13] = 0;
  texture[0x14] = 0;
  texture[0x15] = 0;
  texture[0x16] = 0;
  texture[0x18] = 0;
  texture[0x19] = 0;
  M<UInt16>(texture + 0x1c) = 0;
  M<UInt16>((SInt32)texture + 0x72) = 0;
  texture[9] = (UInt32)(texture);
  texture[10] = (UInt32)(texture);
  texture[0xd] = (UInt32)(texture);
  texture[0xe] = (UInt32)(texture);
  texture[0x1b] = 0xffffffff;
  texture[0x1a] = 0;
  texture[0x1d] = 0;
  M<UInt16>(texture + 0x1e) = 0;
  M<UInt16>((SInt32)texture + 0x7a) = 0;
  texture[0x1f] = 0;
  return (VendorTextureBuffer *)texture;   /* r3 still holds the IOMalloc result at the blr */
}
