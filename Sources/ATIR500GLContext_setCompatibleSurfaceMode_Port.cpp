/*
 * ATIR500GLContext_setCompatibleSurfaceMode_Port.cpp
 *
 * ATIR500GLContext::setCompatibleSurfaceMode (real addr 0x270a0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x270a0 */
bool ATIR500GLContext::setCompatibleSurfaceMode(SInt32*real_param_1, eIOGLContextModeBits real_param_3, SInt32 real_param_4) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  UInt32 uVar1;
  SInt32 iVar2;
  UInt32 uVar3;
  UInt32 uVar4;
  UInt32 *param_1 = reinterpret_cast<UInt32 *>(real_param_1);
  UInt32 param_3 = (UInt32)real_param_3;
  UInt32 param_4 = (UInt32)real_param_4;
  
  iVar2 = IOATIR500GLContext::setCompatibleSurfaceMode(real_param_1, real_param_3, real_param_4);
  if (iVar2 == 0) {
    uVar4 = *param_1;
    uVar3 = uVar4 & 0xffff7fc0;
    if ((param_4 & 0x40) == 0) {
      uVar3 = param_3 & 0x30000 | uVar4 & 0xfffc7fc0;
    }
    else {
      uVar1 = param_3 & 0x30000;
      if ((uVar4 & 0x30000) != uVar1) {
        if (((uVar4 & 0x30000) != 0) && (uVar1 != 0)) {
          return 0;
        }
        uVar3 = uVar3 | uVar1;
      }
    }
    if ((param_4 & 0x200) == 0) {
      uVar3 = param_3 & 0x7c0000 | uVar3 & 0xff83ffff;
    }
    else {
      uVar1 = param_3 & 0x700000;
      if ((uVar3 & 0x700000) != uVar1) {
        if (((uVar3 & 0x700000) != 0) && (uVar1 != 0)) {
          return 0;
        }
        uVar3 = uVar3 | uVar1;
      }
      uVar1 = param_3 & 0xc0000;
      if ((uVar3 & 0xc0000) != uVar1) {
        if (((uVar3 & 0xc0000) != 0) && (uVar1 != 0)) {
          return 0;
        }
        uVar3 = uVar3 | uVar1;
      }
    }
    if ((uVar3 & 0xfffcffff) == (param_3 & 0xfffcc03f)) {
      *param_1 = uVar3 | uVar4 & 0x803f | param_3 & 0x30000;
      return 1;
    }
  }
  return 1;
}
