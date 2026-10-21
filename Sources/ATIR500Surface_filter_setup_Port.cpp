/*
 * ATIR500Surface_filter_setup_Port.cpp
 *
 * ATIR500Surface::filter_setup (real addr 0x398f0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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
#include "../Headers/ATIR500SurfaceOverlayTables.h"



/* real addr 0x398f0 */
void ATIR500Surface::filter_setup(UInt32 scale, OverlayRegisters *regs) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *regsBytes = reinterpret_cast<UInt8 *>(regs);

  UInt8 setByte09;
  UInt8 setByte1b;
  UInt8 setByte0a;
  UInt8 setByte18;
  UInt8 setByte0b;
  UInt8 setByte19;
  UInt8 setByte0c;
  UInt8 setByte1a;
  UInt8 setByte0d;
  UInt8 setByte0e;
  UInt8 setByte0f;
  UInt8 setByte10;
  UInt8 setByte11;
  UInt8 setByte12;
  UInt8 setByte13;
  UInt8 setByte14;
  UInt8 setByte15;
  UInt8 setByte16;
  UInt8 setByte17;
  int setOffset;
  float ratio;
  
  ratio = (double)(4096.0 / (float)(UInt32)(scale));
  if (0.25 <= ratio) {
    if (1.0 < ratio) {
      ratio = 1.0;
    }
  }
  else {
    ratio = 0.25;
  }
  setOffset = (int)((ratio - 0.25) * 100.0) * 0x20;
  setByte09 = ((const UInt8 *)kFilterSetupArrayOfSets)[0x9 + setOffset];
  setByte0a = ((const UInt8 *)kFilterSetupArrayOfSets)[0xa + setOffset];
  setByte0b = ((const UInt8 *)kFilterSetupArrayOfSets)[0xb + setOffset];
  setByte0c = ((const UInt8 *)kFilterSetupArrayOfSets)[0xc + setOffset];
  setByte0d = ((const UInt8 *)kFilterSetupArrayOfSets)[0xd + setOffset];
  setByte0e = ((const UInt8 *)kFilterSetupArrayOfSets)[0xe + setOffset];
  setByte0f = ((const UInt8 *)kFilterSetupArrayOfSets)[0xf + setOffset];
  setByte10 = ((const UInt8 *)kFilterSetupArrayOfSets)[0x10 + setOffset];
  setByte11 = ((const UInt8 *)kFilterSetupArrayOfSets)[0x11 + setOffset];
  setByte12 = ((const UInt8 *)kFilterSetupArrayOfSets)[0x12 + setOffset];
  setByte13 = ((const UInt8 *)kFilterSetupArrayOfSets)[0x13 + setOffset];
  setByte14 = ((const UInt8 *)kFilterSetupArrayOfSets)[0x14 + setOffset];
  setByte15 = ((const UInt8 *)kFilterSetupArrayOfSets)[0x15 + setOffset];
  setByte16 = ((const UInt8 *)kFilterSetupArrayOfSets)[0x16 + setOffset];
  setByte17 = ((const UInt8 *)kFilterSetupArrayOfSets)[0x17 + setOffset];
  M<unsigned int>(regsBytes + 0x114) = (UInt8)((const UInt8 *)kFilterSetupArrayOfSets)[0x8 + setOffset] & 0xf;
  M<unsigned int>(regsBytes + 0x118) = setByte09 & 0x7f;
  M<unsigned int>(regsBytes + 0x11c) = setByte0a & 0x7f;
  M<unsigned int>(regsBytes + 0x120) = setByte0b & 0xf;
  M<unsigned int>(regsBytes + 0x124) = setByte0c & 0xf;
  M<unsigned int>(regsBytes + 0x128) = setByte0d & 0x7f;
  M<unsigned int>(regsBytes + 300) = setByte0e & 0x7f;
  M<unsigned int>(regsBytes + 0x130) = setByte0f & 0xf;
  M<unsigned int>(regsBytes + 0x134) = setByte10 & 0xf;
  M<unsigned int>(regsBytes + 0x138) = setByte11 & 0x7f;
  M<unsigned int>(regsBytes + 0x13c) = setByte12 & 0x7f;
  M<unsigned int>(regsBytes + 0x140) = setByte13 & 0xf;
  M<unsigned int>(regsBytes + 0x144) = setByte14 & 0xf;
  M<unsigned int>(regsBytes + 0x148) = setByte15 & 0x7f;
  setByte1b = ((const UInt8 *)kFilterSetupArrayOfSets)[0x1b + setOffset];
  setByte18 = ((const UInt8 *)kFilterSetupArrayOfSets)[0x18 + setOffset];
  setByte19 = ((const UInt8 *)kFilterSetupArrayOfSets)[0x19 + setOffset];
  setByte1a = ((const UInt8 *)kFilterSetupArrayOfSets)[0x1a + setOffset];
  M<unsigned int>(regsBytes + 0x14c) = setByte16 & 0x7f;
  M<unsigned int>(regsBytes + 0x150) = setByte17 & 0xf;
  M<unsigned int>(regsBytes + 0x160) = setByte1b & 0xf;
  M<unsigned int>(regsBytes + 0x154) = setByte18 & 0xf;
  M<unsigned int>(regsBytes + 0x158) = setByte19 & 0x7f;
  M<unsigned int>(regsBytes + 0x15c) = setByte1a & 0x7f;
  return;
}
