/*
 * ATIR500Surface_resetFullScreen_Port.cpp
 *
 * ATIR500Surface::resetFullScreen (real addr 0x3cf60, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x3cf60 */
void ATIR500Surface::resetFullScreen() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  UInt8 AVar1;
  UInt8 bVar2;
  UInt8 bVar3;
  UInt8 bVar4;
  UInt32 uVar5;
  UInt32 uVar6;
  UInt32 uVar7;
  SInt32 iVar8;
  SInt32 iVar9;
  SInt32 iVar10;
  SInt32 iVar11;
  
  AVar1 = self[0xdbb];
  M<UInt8>(M<SInt32>(self + 0xc14) * 0x78 + M<SInt32>(self + 0xd50) + 0x164) = AVar1;
  iVar11 = M<SInt32>(self + 0xc14);
  iVar9 = M<SInt32>(self + 0xd50);
  self[iVar11 + 0xdb6] = 0x0;
  if (M<char>(iVar9 + 0x9b0) != '\0') {
    if (M<SInt32>(iVar11 * 0x18 + iVar9 + 0xb10) == 0) {
      if ((M<SInt32>(iVar9 + 0x894) != 0) &&
         (M<SInt32>((UInt32)(iVar11 == 0) * 0x18 + iVar9 + 0xb10) != 0)) {
        iVar9 = (UInt32)(iVar11 == 0) * 0x78 + iVar9;
        M<UInt8>(iVar9 + 0x9f4) = AVar1;
        M<UInt8>(iVar9 + 0x164) = AVar1;
      }
    }
    else {
      M<UInt8>(iVar11 * 0x78 + iVar9 + 0x9f4) = AVar1;
      iVar9 = M<SInt32>(self + 0xd50);
      if (M<SInt32>(iVar9 + 0x894) != 0) {
        uVar7 = (UInt32)(M<SInt32>(self + 0xc14) == 0);
        if (M<SInt32>(uVar7 * 0x18 + iVar9 + 0xb10) == 0) {
          M<UInt8>(uVar7 * 0x78 + iVar9 + 0x164) = AVar1;
        }
        else {
          iVar9 = uVar7 * 0x78 + iVar9;
          M<UInt8>(iVar9 + 0x164) = AVar1;
          M<UInt8>(iVar9 + 0x9f4) = AVar1;
        }
      }
    }
  }
  iVar9 = VCALL(M<SInt32>(self), 0x5dc)(self);
  if (iVar9 == 0) {
    iVar9 = M<SInt32>(self + 0xd50);
    iVar10 = M<SInt32>(iVar9 + 0x860);
    bVar2 = M<UInt8>(iVar10 + 0x6107);
    bVar3 = M<UInt8>(iVar10 + 0x6105);
    bVar4 = M<UInt8>(iVar10 + 0x6104);
    iVar11 = M<SInt32>(self + 0xc14);
    uVar5 = (M<UInt8>(iVar10 + 0x6106) & 0xffcf) << 0x10;
    uVar7 = (UInt32)M<UInt8>(iVar11 * 0x78 + iVar9 + 0x164);
    uVar6 = (uVar7 & 1) << 0x15;
    uVar7 = (UInt32)(1 < uVar7) * 0x100000;
    if (iVar11 == 0) {
      iVar8 = 0x6104;
    }
    else {
      iVar8 = 0x6904;
    }
    M<UInt32>(iVar10 + iVar8) =
         (UInt32)bVar4 << 0x18 | (UInt32)bVar3 << 0x10 | (uVar7 | uVar5 | uVar6) >> 8 | (UInt32)bVar2;
    enforceInOrderExecutionIO();
    if (M<SInt32>(iVar9 + 0x894) != 0) {
      if (iVar11 == 0) {
        iVar9 = 0x6904;
      }
      else {
        iVar9 = 0x6104;
      }
      M<UInt32>(iVar10 + iVar9) =
           (UInt32)bVar4 << 0x18 | (UInt32)bVar3 << 0x10 | (uVar7 | uVar5 | uVar6) >> 8 | (UInt32)bVar2;
      enforceInOrderExecutionIO();
    }
  }
  IOATIR500Surface::resetFullScreen();
  return;
}
