/*
 * ATIR500Surface_is_flip_allowed_Port.cpp
 *
 * ATIR500Surface::is_flip_allowed (real addr 0x3ae30, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x3ae30 */
SInt32 ATIR500Surface::is_flip_allowed() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  SInt32 panelBlockOffset;
  UInt32 baseResult;
  UInt32 result;
  SInt32 accel;
  
  baseResult = IOATIR500Surface::is_flip_allowed();
  accel = M<SInt32>(self + kIOATIR500Surface_accelerator);
  if (M<char>(accel + 0x9b0) == '\0') goto LAB_0003aec0;
  if (M<SInt32>(M<SInt32>(self + kIOATIR500Surface_panel) * 0x18 + accel + kIOATIR500Accelerator_swdsPanel0Flag) == 0) {
    if (M<SInt32>(accel + kIOATIR500Accelerator_scanoutOverlapsVram) == 0) goto LAB_0003aec0;
    panelBlockOffset = 0xb18;
    if (M<SInt32>(self + kIOATIR500Surface_panel) != 0) {
      panelBlockOffset = 0xb00;
    }
    if (M<SInt32>(accel + panelBlockOffset + 0x10) == 0) goto LAB_0003aec0;
  }
  baseResult = 0;
LAB_0003aec0:
  result = 0;
  if (-1 < M<SInt32>(self + kIOATIR500Surface_modeBits)) {
    result = baseResult;
  }
  return result;
}
