/*
 * IOATIR500Surface_attach_buffer_backing_store_Port.cpp
 *
 * IOATIR500Surface::attach_buffer_backing_store (real addr 0x12640, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x12640 */
UInt32 IOATIR500Surface::attach_buffer_backing_store(ATIR500SurfaceBuffer *real_param_1, IOMemoryDescriptor*param_2, UInt32 param_3, UInt32 param_4) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *param_1 = reinterpret_cast<UInt8 *>(real_param_1);

  UInt32 uVar1;
  SInt32 iVar2;
  SInt32 *piVar3;
  
  iVar2 = VCALL(*M<SInt32 *>(self + 0xd50), 0x570)(M<SInt32 *>(self + 0xd50),0xc0);
  uVar1 = 0;
  if (iVar2 != 0) {
    M<SInt32>(param_1 + 0x24) = iVar2;
    M<UInt32>(iVar2 + 0x80) = 0;
    M<SInt32>(iVar2 + 0x14) = iVar2 + 0x80;
    M<UInt32>(iVar2 + 0x84) = 0;
    M<UInt32>(M<SInt32>(iVar2 + 0x14) + 8) = 0;
    M<UInt32>(M<SInt32>(iVar2 + 0x14) + 0xc) = 0;
    M<UInt32>(M<SInt32>(iVar2 + 0x14) + 0x10) = 0;
    M<UInt16>(M<SInt32>(iVar2 + 0x14) + 0x1c) = 0;
    M<UInt16>(M<SInt32>(iVar2 + 0x14) + 0x1e) = 0;
    M<UInt16>(M<SInt32>(iVar2 + 0x14) + 0x20) = 0;
    M<UInt16>(M<SInt32>(iVar2 + 0x14) + 0x22) = 0;
    M<UInt16>(M<SInt32>(iVar2 + 0x14) + 0x24) = 0;
    M<UInt16>(M<SInt32>(iVar2 + 0x14) + 0x26) = 0;
    M<UInt16>(M<SInt32>(iVar2 + 0x14) + 0x28) = 0;
    M<UInt16>(M<SInt32>(iVar2 + 0x14) + 0x2a) = 0;
    M<UInt16>(M<SInt32>(iVar2 + 0x14) + 0x2c) = 0;
    M<UInt16>(M<SInt32>(iVar2 + 0x14) + 0x2e) = 0;
    M<UInt16>(M<SInt32>(iVar2 + 0x14) + 0x30) = 0;
    M<UInt16>(M<SInt32>(iVar2 + 0x14) + 0x32) = 0;
    M<UInt8>(M<SInt32>(iVar2 + 0x14) + 0x14) = 1;
    M<UInt8>(M<SInt32>(iVar2 + 0x14) + 0x15) = 0;
    M<UInt8>(M<SInt32>(iVar2 + 0x14) + 0x16) = 0;
    M<UInt8>(M<SInt32>(iVar2 + 0x14) + 0x34) = 0;
    M<UInt8>(M<SInt32>(iVar2 + 0x14) + 0x35) = 0;
    M<UInt8>(M<SInt32>(iVar2 + 0x14) + 0x17) = 0;
    M<UInt16>(M<SInt32>(iVar2 + 0x14) + 0x36) = 0;
    M<UInt8 *>(iVar2 + 8) = (UInt8 *)param_2;
    M<UInt8>(M<SInt32>(iVar2 + 0x14) + 0x16) = 5;
    M<UInt8>(iVar2 + 0x20) = 5;
    M<SInt16>(iVar2 + 0x50) = (SInt16)param_3;
    M<SInt16>(iVar2 + 0x52) = (SInt16)param_4;
    M<UInt8>(iVar2 + 0x58) = 1;
    M<UInt32>(iVar2 + 0x54) = M<UInt32>(self + 0x7c);
    if (((self[0xbf7] == 0x0) || (M<SInt32>(param_1 + 0x24) == 0)) ||
       (piVar3 = M<SInt32 *>(M<SInt32>(param_1 + 0x24) + 8), piVar3 == (SInt32 *)0x0)) {
      uVar1 = 1;
    }
    else {
      VCALL(*piVar3, 0xdc)(piVar3,2,0);
      uVar1 = 1;
    }
  }
  return uVar1;
}
