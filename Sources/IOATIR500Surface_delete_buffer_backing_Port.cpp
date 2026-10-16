/*
 * IOATIR500Surface_delete_buffer_backing_Port.cpp
 *
 * IOATIR500Surface::delete_buffer_backing (real addr 0x12c30, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x12c30 */
void IOATIR500Surface::delete_buffer_backing(IOTextureBuffer *buffer) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *bufferBytes = reinterpret_cast<UInt8 *>(buffer);

  SInt32 iVar1;
  SInt32 iVar2;
  
  if (M<SInt32>(bufferBytes + 4) != 0) {
    iVar1 = VCALL(*M<SInt32 *>(self + 0xd50), 0x554)
                      (M<SInt32 *>(self + 0xd50),M<UInt32>(M<SInt32>(bufferBytes + 0x14) + 8));
    if (iVar1 == 0) {
      ((IOATIR500Accelerator *)(M<UInt8 *>(self + 0xd50)))->addOrphanTexture((IOTextureBuffer *)(bufferBytes));
      if (bufferBytes[0x20] != 0x0) {
        return;
      }
      iVar1 = M<SInt32>(bufferBytes + 0x24);
      M<UInt32>(iVar1 + 0x28) = M<UInt32>(bufferBytes + 0x28);
      iVar2 = M<SInt32>(bufferBytes + 0x28);
      M<UInt8 *>(bufferBytes + 0x28) = bufferBytes;
      M<SInt32>(iVar2 + 0x24) = iVar1;
      M<UInt8 *>(bufferBytes + 0x24) = bufferBytes;
      return;
    }
    if (M<SInt32>(bufferBytes + 4) != 0) {
      VCALL(*M<SInt32 *>(self + 0xd50), 0x5ac)(M<SInt32 *>(self + 0xd50),bufferBytes);
    }
  }
  VCALL(*M<SInt32 *>(bufferBytes + 8), 0x18)(M<SInt32 *>(bufferBytes + 8));
  VCALL(*M<SInt32 *>(self + 0xd50), 0x574)(M<SInt32 *>(self + 0xd50),bufferBytes,0xc0);
  return;
}
