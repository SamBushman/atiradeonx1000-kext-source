/*
 * IOATIR500GLContext_remove_texture_from_stream_Port.cpp
 *
 * IOATIR500GLContext::remove_texture_from_stream (real addr 0x71b0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x71b0 */
void IOATIR500GLContext::remove_texture_from_stream(VendorTextureBuffer *real_param_1) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *param_1 = reinterpret_cast<UInt8 *>(real_param_1);

  UInt8 VVar1;
  UInt32 uVar2;
  SInt32 iVar3;
  SInt32 *piVar4;
  
  do {
    uVar2 = M<UInt32>(M<SInt32>(self + 200) + 0x50);
    M<UInt32>(M<SInt32>(param_1 + 0x14) + 8) = uVar2;
    VVar1 = param_1[0x20];
    if (VVar1 == 0x6) {
      iVar3 = M<SInt32>(param_1 + 0x54);
      M<UInt32>(M<SInt32>(iVar3 + 0x14) + 8) = uVar2;
      M<SInt16>(iVar3 + 0xe) = M<SInt16>(iVar3 + 0xe) + -1;
      return;
    }
    if (VVar1 == 0x0) {
      piVar4 = M<SInt32 *>(param_1 + 0x50);
      if (piVar4 == (SInt32 *)0x0) {
        return;
      }
      VCALL(*piVar4, 0x5b4)(piVar4,uVar2,3);
      VCALL(*piVar4, 0x5bc)(piVar4,3);
      return;
    }
    if (VVar1 != 0x1) {
      if (VVar1 != 0x8) {
        return;
      }
      if (M<SInt32>(param_1 + 0x48) == 0) {
        M<SInt16>(param_1 + 0xe) = M<SInt16>(param_1 + 0xe) + -1;
      }
      M<UInt32>(param_1 + 0x5c) = uVar2;
      return;
    }
    param_1 = M<UInt8 *>(param_1 + 0x50);
  } while (param_1 != (UInt8 *)0x0);
  return;
}
