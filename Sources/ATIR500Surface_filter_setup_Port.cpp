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

  UInt8 bVar1;
  UInt8 bVar2;
  UInt8 bVar3;
  UInt8 bVar4;
  UInt8 bVar5;
  UInt8 bVar6;
  UInt8 bVar7;
  UInt8 bVar8;
  UInt8 bVar9;
  UInt8 bVar10;
  UInt8 bVar11;
  UInt8 bVar12;
  UInt8 bVar13;
  UInt8 bVar14;
  UInt8 bVar15;
  int setOffset;
  double ratio;
  
  ratio = (double)(4096.0 / (float)((double)CONCAT44d(0x43300000,scale) - 4503599627370496.0));
  if (0.25 <= ratio) {
    if (1.0 < ratio) {
      ratio = 1.0;
    }
  }
  else {
    ratio = 0.25;
  }
  setOffset = (int)((ratio - 0.25) * 100.0) * 0x20;
  bVar1 = ((const UInt8 *)kFilterSetupArrayOfSets)[0x9 + setOffset];
  bVar2 = ((const UInt8 *)kFilterSetupArrayOfSets)[0xa + setOffset];
  bVar3 = ((const UInt8 *)kFilterSetupArrayOfSets)[0xb + setOffset];
  bVar4 = ((const UInt8 *)kFilterSetupArrayOfSets)[0xc + setOffset];
  bVar5 = ((const UInt8 *)kFilterSetupArrayOfSets)[0xd + setOffset];
  bVar6 = ((const UInt8 *)kFilterSetupArrayOfSets)[0xe + setOffset];
  bVar7 = ((const UInt8 *)kFilterSetupArrayOfSets)[0xf + setOffset];
  bVar8 = ((const UInt8 *)kFilterSetupArrayOfSets)[0x10 + setOffset];
  bVar9 = ((const UInt8 *)kFilterSetupArrayOfSets)[0x11 + setOffset];
  bVar10 = ((const UInt8 *)kFilterSetupArrayOfSets)[0x12 + setOffset];
  bVar11 = ((const UInt8 *)kFilterSetupArrayOfSets)[0x13 + setOffset];
  bVar12 = ((const UInt8 *)kFilterSetupArrayOfSets)[0x14 + setOffset];
  bVar13 = ((const UInt8 *)kFilterSetupArrayOfSets)[0x15 + setOffset];
  bVar14 = ((const UInt8 *)kFilterSetupArrayOfSets)[0x16 + setOffset];
  bVar15 = ((const UInt8 *)kFilterSetupArrayOfSets)[0x17 + setOffset];
  M<unsigned int>(regsBytes + 0x114) = (UInt8)((const UInt8 *)kFilterSetupArrayOfSets)[0x8 + setOffset] & 0xf;
  M<unsigned int>(regsBytes + 0x118) = bVar1 & 0x7f;
  M<unsigned int>(regsBytes + 0x11c) = bVar2 & 0x7f;
  M<unsigned int>(regsBytes + 0x120) = bVar3 & 0xf;
  M<unsigned int>(regsBytes + 0x124) = bVar4 & 0xf;
  M<unsigned int>(regsBytes + 0x128) = bVar5 & 0x7f;
  M<unsigned int>(regsBytes + 300) = bVar6 & 0x7f;
  M<unsigned int>(regsBytes + 0x130) = bVar7 & 0xf;
  M<unsigned int>(regsBytes + 0x134) = bVar8 & 0xf;
  M<unsigned int>(regsBytes + 0x138) = bVar9 & 0x7f;
  M<unsigned int>(regsBytes + 0x13c) = bVar10 & 0x7f;
  M<unsigned int>(regsBytes + 0x140) = bVar11 & 0xf;
  M<unsigned int>(regsBytes + 0x144) = bVar12 & 0xf;
  M<unsigned int>(regsBytes + 0x148) = bVar13 & 0x7f;
  bVar1 = ((const UInt8 *)kFilterSetupArrayOfSets)[0x1b + setOffset];
  bVar2 = ((const UInt8 *)kFilterSetupArrayOfSets)[0x18 + setOffset];
  bVar3 = ((const UInt8 *)kFilterSetupArrayOfSets)[0x19 + setOffset];
  bVar4 = ((const UInt8 *)kFilterSetupArrayOfSets)[0x1a + setOffset];
  M<unsigned int>(regsBytes + 0x14c) = bVar14 & 0x7f;
  M<unsigned int>(regsBytes + 0x150) = bVar15 & 0xf;
  M<unsigned int>(regsBytes + 0x160) = bVar1 & 0xf;
  M<unsigned int>(regsBytes + 0x154) = bVar2 & 0xf;
  M<unsigned int>(regsBytes + 0x158) = bVar3 & 0x7f;
  M<unsigned int>(regsBytes + 0x15c) = bVar4 & 0x7f;
  return;
}
