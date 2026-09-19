/*
 * IOATIR500Surface_reset_req_bits_Port.cpp
 *
 * IOATIR500Surface::reset_req_bits (real addr 0x13c70, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x13c70 */
void IOATIR500Surface::reset_req_bits() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  UInt32 uVar1;
  SInt32 iVar2;
  UInt32 local_28 [8];
  
  iVar2 = M<SInt32>(self + 0x88);
  uVar1 = M<UInt32>(self + 0xc1c) & 0x30000020;
  M<UInt32>(self + 0xc1c) = uVar1;
  M<UInt32>(self + 0xc18) = uVar1;
  for (; iVar2 != 0; iVar2 = M<SInt32>(iVar2 + 0x84)) {
    uVar1 = uVar1 | M<UInt32>(iVar2 + 0x8c);
    M<UInt32>(self + 0xc18) = uVar1;
  }
  iVar2 = M<SInt32>(self + 0x8c);
  if (iVar2 != 0) {
    uVar1 = M<UInt32>(self + 0xc18);
    do {
      uVar1 = uVar1 | M<UInt32>(iVar2 + 0x8c);
      M<UInt32>(self + 0xc18) = uVar1;
      iVar2 = M<SInt32>(iVar2 + 0x84);
    } while (iVar2 != 0);
  }
  for (iVar2 = M<SInt32>(self + 0xbcc); iVar2 != 0; iVar2 = M<SInt32>(iVar2 + 0x54)) {
    if (M<UInt32>(iVar2 + 0x58) == 0x11) {
      if (((M<UInt32>(self + 0xbf8) & 2) == 0) || (M<SInt32>(self + 0x144) != 0)) {
        M<UInt32>(self + 0xc18) = M<UInt32>(self + 0xc18) | 2;
      }
      else if (((M<UInt32>(self + 0xbf8) & 1) == 0) || (M<SInt32>(self + 0xcc) != 0)) {
        M<UInt32>(self + 0xc18) = M<UInt32>(self + 0xc18) | 1;
      }
    }
    else {
      this->surface_buffer_idx_mask(M<UInt32>(iVar2 + 0x58),(UInt32 *)(local_28));
      M<UInt32>(self + 0xc18) = M<UInt32>(self + 0xc18) | local_28[0];
    }
  }
  if (M<SInt32>(self + 0x90) != 0) {
    M<UInt32>(self + 0xc18) = M<UInt32>(self + 0xc18) | M<UInt32>(M<SInt32>(self + 0x90) + 0x88);
  }
  return;
}
