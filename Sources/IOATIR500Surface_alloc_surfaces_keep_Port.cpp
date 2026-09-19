/*
 * IOATIR500Surface_alloc_surfaces_keep_Port.cpp
 *
 * IOATIR500Surface::alloc_surfaces_keep (real addr 0x124b0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x124b0 */
UInt32 IOATIR500Surface::alloc_surfaces_keep(IOATIR500Surface *real_param_1, VendorTextureBuffer**param_2, SInt32 param_3, UInt32 param_4) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *param_1 = reinterpret_cast<UInt8 *>(real_param_1);

  bool bVar1;
  UInt32 uVar2;
  UInt32 uVar3;
  UInt32 uVar4;
  UInt32 uVar5;
  
  uVar5 = 0;
  uVar4 = 1;
  uVar2 = M<UInt32>(self + 0xbf8);
  while( true ) {
    if ((param_4 & uVar2 & 1 << (uVar5 & 0x3f)) != 0) {
      uVar3 = VCALL(M<SInt32>(self), 0x5f8)(self,param_1,param_2,param_3,uVar5);
      uVar4 = uVar4 & uVar3;
    }
    bVar1 = uVar5 == 0x16;
    uVar5 = uVar5 + 1;
    if (bVar1) break;
    if (uVar4 == 0) {
      return 2;
    }
  }
  if (uVar4 == 0) {
    return 2;
  }
  return 0;
}
