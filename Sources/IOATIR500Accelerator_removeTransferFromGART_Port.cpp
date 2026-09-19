/*
 * IOATIR500Accelerator_removeTransferFromGART_Port.cpp
 *
 * IOATIR500Accelerator::removeTransferFromGART (real addr 0x34f0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x34f0 */
void IOATIR500Accelerator::removeTransferFromGART(VendorTransferBuffer *real_param_1) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *param_1 = reinterpret_cast<UInt8 *>(real_param_1);

  SInt32 iVar1;
  SInt32 iVar2;
  
  if (param_1 != (UInt8 *)0x0) {
    if (M<SInt16>(param_1 + 0xc) == 4) {
      iVar1 = M<SInt32>(param_1 + 0x34);
      M<UInt32>(iVar1 + 0x38) = M<UInt32>(param_1 + 0x38);
      iVar2 = M<SInt32>(param_1 + 0x38);
      M<UInt8 *>(param_1 + 0x38) = param_1;
      M<SInt32>(iVar2 + 0x34) = iVar1;
      M<UInt8 *>(param_1 + 0x34) = param_1;
    }
    VCALL(M<SInt32>(self), 0x5a4)
              (self,M<UInt32>(param_1 + 8),M<UInt32>(param_1 + 4));
    M<UInt32>(param_1 + 4) = 0;
  }
  return;
}
