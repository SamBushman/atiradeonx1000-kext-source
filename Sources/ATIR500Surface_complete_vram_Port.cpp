/*
 * ATIR500Surface_complete_vram_Port.cpp
 *
 * ATIR500Surface::complete_vram (real addr 0x3c000, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x3c000 */
UInt32 ATIR500Surface::complete_vram(ATIR500SurfaceBuffer *real_param_1) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *param_1 = reinterpret_cast<UInt8 *>(real_param_1);

  UInt32 uVar1;
  SInt32 iVar2;
  UInt32 uVar3;
  UInt8 AVar4;
  SInt32 *piVar5;
  UInt8 *this_00;
  SInt32 iVar6;
  
  uVar3 = 0;
  if (param_1[0x3c] != 0x0) {
    AVar4 = ((char)param_1[0x3c] + -1);
    param_1[0x3c] = AVar4;
    if (AVar4 == 0x0) {
      AVar4 = param_1[0x37];
      param_1[0x37] = 0xff;
      uVar1 = (UInt8)AVar4 & 0x1f;
      M<UInt32>(M<SInt32>(self + 0xd50) + 0x890) =
           (-2 << uVar1 | 0xfffffffeU >> 0x20 - uVar1) & M<UInt32>(M<SInt32>(self + 0xd50) + 0x890);
      piVar5 = M<SInt32 *>(self + 0xd50);
      if (M<char>(piVar5 + 0x20) != '\0') {
        iVar6 = piVar5[0x8e];
        iVar2 = (UInt32)(UInt8)AVar4 * 4;
        VCALL(*piVar5, 0x54c)(piVar5,piVar5[0x8d]);
        M<UInt32>(iVar6 + 0x120) = iVar2 + 0x2c1;
        M<UInt32>(iVar6 + 0x124) = 0;
        M<SInt32>(iVar6 + 0x128) = iVar2 + 0x2c2;
        M<UInt32>(iVar6 + 300) = 0;
        M<SInt32>(iVar6 + 0x130) = iVar2 + 0x2c3;
        M<UInt32>(iVar6 + 0x134) = 0;
        this_00 = M<UInt8 *>(self + 0xd50);
        uVar3 = ((ATIRadeonX1000 *)(this_00))->submit_buffer((UInt32 *)(iVar6 + 0x120),M<SInt32>(this_00 + 0x228) + 0x120,6);
        M<UInt32>(this_00 + 0x234) = uVar3;
        return 1;
      }
    }
    uVar3 = 1;
  }
  return uVar3;
}
