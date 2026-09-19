/*
 * ATIR500GLContext_WriteTextureOffset_Port.cpp
 *
 * ATIR500GLContext::WriteTextureOffset (real addr 0x28420, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x28420 */
UInt32 ATIR500GLContext::WriteTextureOffset(UInt32 param_1, UInt32*param_2, UInt32 param_3, VendorTextureBuffer *real_param_4) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *param_4 = reinterpret_cast<UInt8 *>(real_param_4);

  UInt8 bVar1;
  UInt32 uVar2;
  SInt32 iVar3;
  UInt32 uVar4;
  
  while (param_4[0x20] == 0x1) {
    param_4 = M<UInt8 *>(param_4 + 0x50);
    if (param_4 == (UInt8 *)0x0) {
      return 0;
    }
  }
  bVar1 = M<UInt8>(M<SInt32>(param_4 + 0x14) + 0x15);
  uVar2 = this->GetTextureOffset((VendorTextureBuffer *)(param_4),false);
  uVar4 = bVar1 & 0x1f | uVar2 & 0xffffffe0;
  param_2[param_3] = param_1 + 0x1150;
  iVar3 = param_3 + 2;
  param_2[param_3 + 1] = uVar4;
  uVar2 = M<UInt32>(param_4 + 0x68);
  if ((uVar2 & 0xc0000000) == 0) {
    param_2[iVar3] = 0x80000000;
    return 3;
  }
  if (param_1 < 8) {
    param_2[iVar3] = param_1 + 0x1158;
    param_2[param_3 + 3] = uVar4 + (uVar2 & 0x3fffff) * 0x20;
    return 4;
  }
  param_2[iVar3] = 0xc0001000;
  return 4;
}
