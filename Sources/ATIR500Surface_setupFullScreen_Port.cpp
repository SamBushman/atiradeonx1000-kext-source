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

  UInt8 fullScreenValue;
  UInt8 bVar2;
  UInt8 bVar3;
  UInt8 bVar4;
  unsigned int maskedValue;
  unsigned int newValue;
  unsigned int uVar7;
  int iVar8;
  int iVar9;
  int registers;
  int id;
  
  fullScreenValue = self[0x158];
  iVar8 = M<int>(self + 0xc14) * 0x78 + M<int>(self + 0xd50);
  M<unsigned int>(self + 0xdb8) = (unsigned int)M<UInt8>(iVar8 + 0x164);
  M<UInt8>(iVar8 + 0x164) = fullScreenValue;
  if ((M<unsigned int>(self + 0xbe8) & 0x10) != 0) {
    self[M<int>(self + 0xc14) + 0xdb6] = 0x1;
  }
  iVar8 = M<int>(self + 0xd50);
  if (M<char>(iVar8 + 0x9b0) == '\0') goto LAB_0003d310;
  id = M<int>(self + 0xc14);
  if (M<int>(id * 0x18 + iVar8 + 0xb10) == 0) {
    if ((M<int>(iVar8 + 0x894) == 0) ||
       (uVar7 = (unsigned int)(id == 0), M<int>(uVar7 * 0x18 + iVar8 + 0xb10) == 0))
    goto LAB_0003d310;
  }
  else {
    M<UInt8>(id * 0x78 + iVar8 + 0x9f4) = fullScreenValue;
    iVar8 = M<int>(self + 0xd50);
    if (M<int>(iVar8 + 0x894) == 0) goto LAB_0003d310;
    uVar7 = (unsigned int)(M<int>(self + 0xc14) == 0);
    if (M<int>(uVar7 * 0x18 + iVar8 + 0xb10) == 0) {
      M<UInt8>(uVar7 * 0x78 + iVar8 + 0x164) = fullScreenValue;
      goto LAB_0003d310;
    }
  }
  iVar8 = uVar7 * 0x78 + iVar8;
  M<UInt8>(iVar8 + 0x9f4) = fullScreenValue;
  M<UInt8>(iVar8 + 0x164) = fullScreenValue;
LAB_0003d310:
  iVar8 = VCALL(M<int>(self), 0x5dc)(self);
  if (iVar8 == 0) {
    iVar8 = M<int>(self + 0xd50);
    registers = M<int>(iVar8 + 0x860);
    maskedValue = loadWordByteReversed(&M<UInt8>(registers + 0x6104)) & 0xffcfffff;
    id = M<int>(self + 0xc14);
    uVar7 = (unsigned int)M<UInt8>(id * 0x78 + iVar8 + 0x164);
    newValue = maskedValue | (uVar7 & 1) << 0x15 | (unsigned int)(1 < uVar7) << 0x14;
    storeWordByteReversed(&M<UInt8>(registers + (id == 0 ? 0x6104 : 0x6904)), newValue);
    enforceInOrderExecutionIO();
    if (M<int>(iVar8 + 0x894) != 0) {
      storeWordByteReversed(&M<UInt8>(registers + (id == 0 ? 0x6904 : 0x6104)), newValue);
      enforceInOrderExecutionIO();
    }
  }
  /* #178: explicit base-class call (stock tail-calls 0x13900 directly); a cast-and-call is virtual under -fapple-kext and would re-enter this function (vtable +0x5a4). Same bug class as #155/#177. */
  IOATIR500Surface::setupFullScreen();
  return;
}
