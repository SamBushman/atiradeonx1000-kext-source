/*
 * ATIR500Surface_setupFullScreen_Port.cpp
 *
 * ATIR500Surface::setupFullScreen (real addr 0x3d200, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x3d200 */
void ATIR500Surface::setupFullScreen() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  UInt8 AVar1;
  UInt8 bVar2;
  UInt8 bVar3;
  UInt8 bVar4;
  unsigned int uVar5;
  unsigned int uVar6;
  unsigned int uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  
  AVar1 = self[0x158];
  iVar8 = M<int>(self + 0xc14) * 0x78 + M<int>(self + 0xd50);
  M<unsigned int>(self + 0xdb8) = (unsigned int)M<UInt8>(iVar8 + 0x164);
  M<UInt8>(iVar8 + 0x164) = AVar1;
  if ((M<unsigned int>(self + 0xbe8) & 0x10) != 0) {
    self[M<int>(self + 0xc14) + 0xdb6] = 0x1;
  }
  iVar8 = M<int>(self + 0xd50);
  if (M<char>(iVar8 + 0x9b0) == '\0') goto LAB_0003d310;
  iVar11 = M<int>(self + 0xc14);
  if (M<int>(iVar11 * 0x18 + iVar8 + 0xb10) == 0) {
    if ((M<int>(iVar8 + 0x894) == 0) ||
       (uVar7 = (unsigned int)(iVar11 == 0), M<int>(uVar7 * 0x18 + iVar8 + 0xb10) == 0))
    goto LAB_0003d310;
  }
  else {
    M<UInt8>(iVar11 * 0x78 + iVar8 + 0x9f4) = AVar1;
    iVar8 = M<int>(self + 0xd50);
    if (M<int>(iVar8 + 0x894) == 0) goto LAB_0003d310;
    uVar7 = (unsigned int)(M<int>(self + 0xc14) == 0);
    if (M<int>(uVar7 * 0x18 + iVar8 + 0xb10) == 0) {
      M<UInt8>(uVar7 * 0x78 + iVar8 + 0x164) = AVar1;
      goto LAB_0003d310;
    }
  }
  iVar8 = uVar7 * 0x78 + iVar8;
  M<UInt8>(iVar8 + 0x9f4) = AVar1;
  M<UInt8>(iVar8 + 0x164) = AVar1;
LAB_0003d310:
  iVar8 = VCALL(M<int>(self), 0x5dc)(self);
  if (iVar8 == 0) {
    iVar8 = M<int>(self + 0xd50);
    iVar10 = M<int>(iVar8 + 0x860);
    bVar2 = M<UInt8>(iVar10 + 0x6107);
    bVar3 = M<UInt8>(iVar10 + 0x6105);
    bVar4 = M<UInt8>(iVar10 + 0x6104);
    iVar11 = M<int>(self + 0xc14);
    uVar5 = (M<UInt8>(iVar10 + 0x6106) & 0xffcf) << 0x10;
    uVar7 = (unsigned int)M<UInt8>(iVar11 * 0x78 + iVar8 + 0x164);
    uVar6 = (uVar7 & 1) << 0x15;
    uVar7 = (unsigned int)(1 < uVar7) * 0x100000;
    if (iVar11 == 0) {
      iVar9 = 0x6104;
    }
    else {
      iVar9 = 0x6904;
    }
    M<unsigned int>(iVar10 + iVar9) =
         (unsigned int)bVar4 << 0x18 | (unsigned int)bVar3 << 0x10 | (uVar7 | uVar5 | uVar6) >> 8 | (unsigned int)bVar2;
    enforceInOrderExecutionIO();
    if (M<int>(iVar8 + 0x894) != 0) {
      if (iVar11 == 0) {
        iVar8 = 0x6904;
      }
      else {
        iVar8 = 0x6104;
      }
      M<unsigned int>(iVar10 + iVar8) =
           (unsigned int)bVar4 << 0x18 | (unsigned int)bVar3 << 0x10 | (uVar7 | uVar5 | uVar6) >> 8 | (unsigned int)bVar2;
      enforceInOrderExecutionIO();
    }
  }
  ((IOATIR500Surface *)(self))->setupFullScreen();
  return;
}
