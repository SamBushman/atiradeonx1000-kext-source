/*
 * IOATIR500Accelerator_freeTransferToAllocGART_Port.cpp
 *
 * IOATIR500Accelerator::freeTransferToAllocGART (real addr 0x3580, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x3580 */
bool IOATIR500Accelerator::freeTransferToAllocGART(VendorTransferBuffer *real_param_1, VendorTransferBuffer *real_param_2, UInt32 param_3, bool param_4) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *param_1 = reinterpret_cast<UInt8 *>(real_param_1);
    UInt8 *param_2 = reinterpret_cast<UInt8 *>(real_param_2);

  SInt32 iVar1;
  UInt32 uVar2;
  UInt32 in_register_0000001c;
  SInt32 iVar3;
  
  if ((M<SInt32>(param_1 + 4) == 0) || (M<SInt16>(param_1 + 0xe) != 0)) {
LAB_00003650:
    uVar2 = 0;
  }
  else {
    if (((UInt32)param_4) == 0) {
      iVar1 = VCALL(M<SInt32>(self), 0x554)(self,param_3);
      if (iVar1 == 0) goto LAB_00003650;
    }
    else {
      iVar3 = M<SInt32>(self + 0x790);
      iVar1 = VCALL(M<SInt32>(self), 0x54c)(self);
      M<SInt32>(self + 0x790) = iVar3 + iVar1;
    }
    VCALL(M<SInt32>(self), 0x5ac)(self,param_1);
    uVar2 = VCALL(M<SInt32>(self), 0x5a8)(self,param_2);
  }
  return uVar2;
}
