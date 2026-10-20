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

  UInt8 savedValue;
  UInt32 maskedValue;
  UInt32 newValue;
  UInt32 otherPanel;
  UInt32 modeValue;
  SInt32 otherRecord;
  SInt32 accel;
  SInt32 vtable5dcResult;
  SInt32 registers;
  SInt32 id;
  
  savedValue = self[0xdbb];
  M<UInt8>(M<SInt32>(self + kIOATIR500Surface_panel) * 0x78 + M<SInt32>(self + kIOATIR500Surface_accelerator) + 0x164) = savedValue;
  id = M<SInt32>(self + kIOATIR500Surface_panel);
  accel = M<SInt32>(self + kIOATIR500Surface_accelerator);
  self[id + 0xdb6] = 0x0;
  if (M<char>(accel + 0x9b0) != '\0') {
    if (M<SInt32>(id * 0x18 + accel + kIOATIR500Accelerator_swdsPanel0Flag) == 0) {
      if ((M<SInt32>(accel + kIOATIR500Accelerator_scanoutOverlapsVram) != 0) &&
         (M<SInt32>((UInt32)(id == 0) * 0x18 + accel + kIOATIR500Accelerator_swdsPanel0Flag) != 0)) {
        otherRecord = (UInt32)(id == 0) * 0x78 + accel;
        M<UInt8>(otherRecord + 0x9f4) = savedValue;
        M<UInt8>(otherRecord + 0x164) = savedValue;
      }
    }
    else {
      M<UInt8>(id * 0x78 + accel + 0x9f4) = savedValue;
      accel = M<SInt32>(self + kIOATIR500Surface_accelerator);
      if (M<SInt32>(accel + kIOATIR500Accelerator_scanoutOverlapsVram) != 0) {
        otherPanel = (UInt32)(M<SInt32>(self + kIOATIR500Surface_panel) == 0);
        if (M<SInt32>(otherPanel * 0x18 + accel + kIOATIR500Accelerator_swdsPanel0Flag) == 0) {
          M<UInt8>(otherPanel * 0x78 + accel + 0x164) = savedValue;
        }
        else {
          otherRecord = otherPanel * 0x78 + accel;
          M<UInt8>(otherRecord + 0x164) = savedValue;
          M<UInt8>(otherRecord + 0x9f4) = savedValue;
        }
      }
    }
  }
  vtable5dcResult = VCALL(M<SInt32>(self), 0x5dc)(self);
  if (vtable5dcResult == 0) {
    accel = M<SInt32>(self + kIOATIR500Surface_accelerator);
    registers = M<SInt32>(accel + kIOATIR500Accelerator_mmioBase);
    maskedValue = loadWordByteReversed(&M<UInt8>(registers + 0x6104)) & 0xffcfffff;
    id = M<SInt32>(self + kIOATIR500Surface_panel);
    modeValue = (UInt32)M<UInt8>(id * 0x78 + accel + 0x164);
    newValue = maskedValue | (modeValue & 1) << 0x15 | (UInt32)(1 < modeValue) << 0x14;
    storeWordByteReversed(&M<UInt8>(registers + (id == 0 ? 0x6104 : 0x6904)), newValue);
    enforceInOrderExecutionIO();
    if (M<SInt32>(accel + kIOATIR500Accelerator_scanoutOverlapsVram) != 0) {
      storeWordByteReversed(&M<UInt8>(registers + (id == 0 ? 0x6904 : 0x6104)), newValue);
      enforceInOrderExecutionIO();
    }
  }
  IOATIR500Surface::resetFullScreen();
  return;
}
