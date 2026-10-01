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
void ATIR500Surface::filter_setup(UInt32 param_1, OverlayRegisters *real_param_2) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *param_2 = reinterpret_cast<UInt8 *>(real_param_2);

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
  int iVar16;
  double dVar17;
  
  dVar17 = (double)(4096.0 / (float)((double)CONCAT44d(0x43300000,param_1) - 4503599627370496.0));
  if (0.25 <= dVar17) {
    if (1.0 < dVar17) {
      dVar17 = 1.0;
    }
  }
  else {
    dVar17 = 0.25;
  }
  iVar16 = (int)((dVar17 - 0.25) * 100.0) * 0x20;
  bVar1 = ((const UInt8 *)kFilterSetupArrayOfSets)[0x9 + iVar16];
  bVar2 = ((const UInt8 *)kFilterSetupArrayOfSets)[0xa + iVar16];
  bVar3 = ((const UInt8 *)kFilterSetupArrayOfSets)[0xb + iVar16];
  bVar4 = ((const UInt8 *)kFilterSetupArrayOfSets)[0xc + iVar16];
  bVar5 = ((const UInt8 *)kFilterSetupArrayOfSets)[0xd + iVar16];
  bVar6 = ((const UInt8 *)kFilterSetupArrayOfSets)[0xe + iVar16];
  bVar7 = ((const UInt8 *)kFilterSetupArrayOfSets)[0xf + iVar16];
  bVar8 = ((const UInt8 *)kFilterSetupArrayOfSets)[0x10 + iVar16];
  bVar9 = ((const UInt8 *)kFilterSetupArrayOfSets)[0x11 + iVar16];
  bVar10 = ((const UInt8 *)kFilterSetupArrayOfSets)[0x12 + iVar16];
  bVar11 = ((const UInt8 *)kFilterSetupArrayOfSets)[0x13 + iVar16];
  bVar12 = ((const UInt8 *)kFilterSetupArrayOfSets)[0x14 + iVar16];
  bVar13 = ((const UInt8 *)kFilterSetupArrayOfSets)[0x15 + iVar16];
  bVar14 = ((const UInt8 *)kFilterSetupArrayOfSets)[0x16 + iVar16];
  bVar15 = ((const UInt8 *)kFilterSetupArrayOfSets)[0x17 + iVar16];
  M<unsigned int>(param_2 + 0x114) = (UInt8)((const UInt8 *)kFilterSetupArrayOfSets)[0x8 + iVar16] & 0xf;
  M<unsigned int>(param_2 + 0x118) = bVar1 & 0x7f;
  M<unsigned int>(param_2 + 0x11c) = bVar2 & 0x7f;
  M<unsigned int>(param_2 + 0x120) = bVar3 & 0xf;
  M<unsigned int>(param_2 + 0x124) = bVar4 & 0xf;
  M<unsigned int>(param_2 + 0x128) = bVar5 & 0x7f;
  M<unsigned int>(param_2 + 300) = bVar6 & 0x7f;
  M<unsigned int>(param_2 + 0x130) = bVar7 & 0xf;
  M<unsigned int>(param_2 + 0x134) = bVar8 & 0xf;
  M<unsigned int>(param_2 + 0x138) = bVar9 & 0x7f;
  M<unsigned int>(param_2 + 0x13c) = bVar10 & 0x7f;
  M<unsigned int>(param_2 + 0x140) = bVar11 & 0xf;
  M<unsigned int>(param_2 + 0x144) = bVar12 & 0xf;
  M<unsigned int>(param_2 + 0x148) = bVar13 & 0x7f;
  bVar1 = ((const UInt8 *)kFilterSetupArrayOfSets)[0x1b + iVar16];
  bVar2 = ((const UInt8 *)kFilterSetupArrayOfSets)[0x18 + iVar16];
  bVar3 = ((const UInt8 *)kFilterSetupArrayOfSets)[0x19 + iVar16];
  bVar4 = ((const UInt8 *)kFilterSetupArrayOfSets)[0x1a + iVar16];
  M<unsigned int>(param_2 + 0x14c) = bVar14 & 0x7f;
  M<unsigned int>(param_2 + 0x150) = bVar15 & 0xf;
  M<unsigned int>(param_2 + 0x160) = bVar1 & 0xf;
  M<unsigned int>(param_2 + 0x154) = bVar2 & 0xf;
  M<unsigned int>(param_2 + 0x158) = bVar3 & 0x7f;
  M<unsigned int>(param_2 + 0x15c) = bVar4 & 0x7f;
  return;
}
