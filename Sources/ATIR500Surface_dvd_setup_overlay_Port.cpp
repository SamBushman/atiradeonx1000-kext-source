/*
 * ATIR500Surface_dvd_setup_overlay_Port.cpp
 *
 * ATIR500Surface::dvd_setup_overlay (real addr 0x3a6e0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x3a6e0 */
void ATIR500Surface::dvd_setup_overlay(int param_1, int param_2, int param_3, int param_4) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  M<SInt16>(self + 0x94) = (SInt16)param_1;
  M<SInt16>(self + 0x96) = (SInt16)param_4;
  M<SInt16>(self + 0x9a) = (SInt16)param_3;
  M<SInt16>(self + 0x98) = (SInt16)param_2;
  M<UInt32>(self + 0xd94) = 1;
  return;
}
