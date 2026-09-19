/*
 * IOATIR500Surface_set_scaling_Port.cpp
 *
 * IOATIR500Surface::set_scaling (real addr 0x11640, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x11640 */
IOReturn IOATIR500Surface::set_scaling(UInt32 param_1, IOAccelSurfaceScaling *real_param_2) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *param_2 = reinterpret_cast<UInt8 *>(real_param_2);

  bool bVar1;
  UInt16 uVar2;
  UInt16 uVar3;
  UInt32 uVar4;
  SInt32 iVar5;
  UInt32 local_28;
  UInt32 local_24;
  UInt32 local_20;
  UInt32 local_1c;
  
  bVar1 = (param_1 >> 1 & 1) == 0;
  if ((bVar1) || (param_2 != (UInt8 *)0x0)) {
    self[0xbee] = ((UInt8)param_1 & 1);
    self[0xbf1] = ((UInt8)param_1 & 0xf0);
    self[0xbed] = SUB41m(-(M<UInt32>(self + 0xbec) & 0xffff00) >> 0x1f,0);
    if (bVar1) {
      self[0xbec] = 0x0;
      uVar2 = M<UInt16>(M<SInt32>(self + 0xd60) + 8);
      M<UInt16>(self + 0xbd4) = uVar2;
      uVar3 = M<UInt16>(M<SInt32>(self + 0xd60) + 10);
      M<UInt16>(self + 0xbdc) = 0;
      M<UInt16>(self + 0xbde) = 0;
      M<UInt16>(self + 0xbe0) = uVar2;
      M<UInt16>(self + 0xbe2) = uVar3;
      M<UInt16>(self + 0xbd6) = uVar3;
    }
    else if ((M<UInt32>(self + 0xbe8) & 0x20) != 0) {
      self[0xbec] = 0x1;
      M<UInt16>(self + 0xbd4) = M<UInt16>(param_2 + 4);
      M<UInt16>(self + 0xbd6) = M<UInt16>(param_2 + 6);
      M<UInt16>(self + 0xbdc) = M<UInt16>(param_2);
      M<UInt16>(self + 0xbde) = M<UInt16>(param_2 + 2);
      M<UInt16>(self + 0xbe0) = M<UInt16>(param_2 + 8);
      M<UInt16>(self + 0xbe2) = M<UInt16>(param_2 + 10);
    }
    M<UInt16>(self + 0xbda) = M<UInt16>(self + 0xbd6);
    M<UInt16>(self + 0xbd8) = M<UInt16>(self + 0xbd4);
    VCALL(M<SInt32>(self), 0x5c8)(self);
    this->update_contexts();
    M<UInt32>(self + 0xbf8) = M<UInt32>(self + 0xbf8) & 0xdfffffff;
    iVar5 = VCALL(M<SInt32>(self), 0x5b0)
                      (self,(SInt32)M<SInt16>(self + 0xbd4),(SInt32)M<SInt16>(self + 0xbd6));
    if (iVar5 != 0) {
      local_1c = 0;
      local_28 = 0;
      local_24 = 0;
      local_20 = 0;
      iVar5 = VCALL(*M<SInt32 *>(self + 0xd50), 0x540)
                        (M<SInt32 *>(self + 0xd50),&local_28,
                         M<UInt32>(M<SInt32>(self + 0xb70) + 0x10),0x1000);
      if (iVar5 != 0) {
        VCALL(*M<SInt32 *>(self + 0xd50), 0x544)(M<SInt32 *>(self + 0xd50),&local_28);
        return 0;
      }
    }
    uVar4 = 0xe00002be;
    M<UInt32>(self + 0xbf8) = M<UInt32>(self + 0xbf8) | 0x20000000;
  }
  else {
    uVar4 = 0xe00002c2;
  }
  return uVar4;
}
