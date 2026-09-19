/*
 * IOATIR500Accelerator_addOrphanTexture_Port.cpp
 *
 * IOATIR500Accelerator::addOrphanTexture (real addr 0x49c0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x49c0 */
void IOATIR500Accelerator::addOrphanTexture(IOTextureBuffer *real_param_1) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *param_1 = reinterpret_cast<UInt8 *>(real_param_1);

  SInt32 iVar1;
  SInt32 iVar2;
  
  iVar2 = M<SInt32>(param_1 + 0x24);
  M<UInt32>(iVar2 + 0x28) = M<UInt32>(param_1 + 0x28);
  iVar1 = M<SInt32>(param_1 + 0x28);
  M<UInt8 *>(param_1 + 0x28) = self + 0x63c;
  M<SInt32>(iVar1 + 0x24) = iVar2;
  M<UInt32>(param_1 + 0x24) = M<UInt32>(self + 0x660);
  M<UInt8 *>(self + 0x660) = param_1;
  M<UInt8 *>(M<SInt32>(param_1 + 0x24) + 0x28) = param_1;
  if (self[0x82] == 0x0) {
    VCALL(*M<SInt32 *>(self + 0xb8), 300)(M<SInt32 *>(self + 0xb8),100);
    self[0x82] = 0x1;
  }
  return;
}
