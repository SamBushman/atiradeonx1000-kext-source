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
  unsigned int maskedValue;
  unsigned int newValue;
  unsigned int otherPanel;
  unsigned int modeValue;
  int panelRecord;
  int otherRecord;
  int accel;
  int vtable5dcResult;
  int registers;
  int id;
  
  fullScreenValue = self[0x158];
  panelRecord = M<int>(self + kIOATIR500Surface_panel) * 0x78 + M<int>(self + kIOATIR500Surface_accelerator);
  M<unsigned int>(self + kATIR500Surface_panelSide) = (unsigned int)M<UInt8>(panelRecord + 0x164);
  M<UInt8>(panelRecord + 0x164) = fullScreenValue;
  if ((M<unsigned int>(self + kIOATIR500Surface_modeBits) & 0x10) != 0) {
    self[M<int>(self + kIOATIR500Surface_panel) + 0xdb6] = 0x1;
  }
  accel = M<int>(self + kIOATIR500Surface_accelerator);
  if (M<char>(accel + 0x9b0) == '\0') goto finishSetup;
  id = M<int>(self + kIOATIR500Surface_panel);
  if (M<int>(id * 0x18 + accel + kIOATIR500Accelerator_swdsPanel0Flag) == 0) {
    if ((M<int>(accel + kIOATIR500Accelerator_scanoutOverlapsVram) == 0) ||
       (otherPanel = (unsigned int)(id == 0), M<int>(otherPanel * 0x18 + accel + kIOATIR500Accelerator_swdsPanel0Flag) == 0))
    goto finishSetup;
  }
  else {
    M<UInt8>(id * 0x78 + accel + 0x9f4) = fullScreenValue;
    accel = M<int>(self + kIOATIR500Surface_accelerator);
    if (M<int>(accel + kIOATIR500Accelerator_scanoutOverlapsVram) == 0) goto finishSetup;
    otherPanel = (unsigned int)(M<int>(self + kIOATIR500Surface_panel) == 0);
    if (M<int>(otherPanel * 0x18 + accel + kIOATIR500Accelerator_swdsPanel0Flag) == 0) {
      M<UInt8>(otherPanel * 0x78 + accel + 0x164) = fullScreenValue;
      goto finishSetup;
    }
  }
  otherRecord = otherPanel * 0x78 + accel;
  M<UInt8>(otherRecord + 0x9f4) = fullScreenValue;
  M<UInt8>(otherRecord + 0x164) = fullScreenValue;
finishSetup:
  vtable5dcResult = VCALL(M<int>(self), 0x5dc)(self);
  if (vtable5dcResult == 0) {
    accel = M<int>(self + kIOATIR500Surface_accelerator);
    registers = M<int>(accel + kIOATIR500Accelerator_mmioBase);
    maskedValue = loadWordByteReversed(&M<UInt8>(registers + 0x6104)) & 0xffcfffff;
    id = M<int>(self + kIOATIR500Surface_panel);
    modeValue = (unsigned int)M<UInt8>(id * 0x78 + accel + 0x164);
    newValue = maskedValue | (modeValue & 1) << 0x15 | (unsigned int)(1 < modeValue) << 0x14;
    storeWordByteReversed(&M<UInt8>(registers + (id == 0 ? 0x6104 : 0x6904)), newValue);
    enforceInOrderExecutionIO();
    if (M<int>(accel + kIOATIR500Accelerator_scanoutOverlapsVram) != 0) {
      storeWordByteReversed(&M<UInt8>(registers + (id == 0 ? 0x6904 : 0x6104)), newValue);
      enforceInOrderExecutionIO();
    }
  }
  /* #178: explicit base-class call (stock tail-calls 0x13900 directly); a cast-and-call is virtual under -fapple-kext and would re-enter this function (vtable +0x5a4). Same bug class as #155/#177. */
  IOATIR500Surface::setupFullScreen();
  return;
}
