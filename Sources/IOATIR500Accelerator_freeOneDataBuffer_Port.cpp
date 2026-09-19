/*
 * IOATIR500Accelerator_freeOneDataBuffer_Port.cpp
 *
 * IOATIR500Accelerator::freeOneDataBuffer (real addr 0x32d0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x32d0 */
void IOATIR500Accelerator::freeOneDataBuffer(VendorTextureBuffer *real_param_1) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *param_1 = reinterpret_cast<UInt8 *>(real_param_1);

  SInt32 iVar1;
  SInt32 *piVar2;
  SInt32 iVar3;
  
  if (M<SInt32>(param_1 + 0x48) != 0) {
    VCALL(M<SInt32>(self), 0x524)(self);
    iVar3 = M<SInt32>(param_1 + 0x24);
    M<UInt32>(iVar3 + 0x28) = M<UInt32>(param_1 + 0x28);
    iVar1 = M<SInt32>(param_1 + 0x28);
    M<UInt8 *>(param_1 + 0x28) = param_1;
    M<SInt32>(iVar1 + 0x24) = iVar3;
    M<UInt8 *>(param_1 + 0x24) = param_1;
  }
  if (M<SInt32 *>(param_1 + 0x10) != (SInt32 *)0x0) {
    VCALL(*M<SInt32 *>(param_1 + 0x10), 0x18)(M<SInt32 *>(param_1 + 0x10));
    M<UInt32>(param_1 + 0x10) = 0;
  }
  piVar2 = M<SInt32 *>(param_1 + 8);
  if (piVar2 != (SInt32 *)0x0) {
    if (M<SInt32>(param_1 + 4) != 0) {
      VCALL(M<SInt32>(self), 0x54c)(self,M<UInt32>(param_1 + 0x5c));
      VCALL(M<SInt32>(self), 0x5ac)(self,param_1);
      piVar2 = M<SInt32 *>(param_1 + 8);
    }
    VCALL(*piVar2, 0x18)(piVar2);
  }
  VCALL(M<SInt32>(self), 0x574)(self,param_1,0xc0);
  M<SInt32>(self + 0x750) = M<SInt32>(self + 0x750) + -1;
  return;
}
