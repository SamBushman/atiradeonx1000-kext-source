/*
 * IOATIR500Surface_surface_write_lock_int_Port.cpp
 *
 * IOATIR500Surface::surface_write_lock_int (real addr 0x114a0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x114a0 */
void IOATIR500Surface::surface_write_lock_int(UInt32 bufferIndex, UInt32*outAddress, UInt32*outPitch) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  SInt32 *accelerator;
  SInt32 iVar2;
  SInt32 waitTotal;
  
  iVar2 = M<SInt32>(self + bufferIndex * 4 + 0xb70);
  VCALL(M<SInt32>(self), 0x5fc)(self,iVar2);
  *outAddress = M<UInt32>(iVar2 + 8);
  *outPitch = (UInt32)M<UInt16>(iVar2 + 0x18);
  accelerator = M<SInt32 *>(self + 0xd50);
  waitTotal = accelerator[0x1ef];
  iVar2 = VCALL(*accelerator, 0x558)(accelerator,accelerator[0x14] + -1);
  accelerator[0x1ef] = waitTotal + iVar2;
  return;
}
