/*
 * ATIR500Surface_load_3d_blit_Port.cpp
 *
 * ATIR500Surface::load_3d_blit (real addr 0x3d4c0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* The three real function-local statics of load_3d_blit (mangled `...load_3d_blitEPmP20ATIR500SurfaceBufferE12samplesTable`
   @ 0x4c2f4, `...11mspos0Table` @ 0x4c2d8, `...11mspos1Table` @ 0x4c2bc); real content read from the kext binary.
   NOT the same symbol as the global `_samplesTable` (0x4c268). */
/* Defined (contiguous, stock layout) in ATIR500Surface_ConstRun.cpp; indexed with 4-bit values, i.e. past their 28 bytes, exactly as the stock code does. */
extern const UInt32 kLoad3dSamplesTable[16] asm("__ZZN14ATIR500Surface12load_3d_blitEPmP20ATIR500SurfaceBufferE12samplesTable");
extern const UInt32 kLoad3dMspos0Table[16] asm("__ZZN14ATIR500Surface12load_3d_blitEPmP20ATIR500SurfaceBufferE11mspos0Table");
extern const UInt32 kLoad3dMspos1Table[16] asm("__ZZN14ATIR500Surface12load_3d_blitEPmP20ATIR500SurfaceBufferE11mspos1Table");

/* real addr 0x3d4c0 */
UInt32 *ATIR500Surface::load_3d_blit(UInt32*param_1, ATIR500SurfaceBuffer *real_param_2) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *param_2 = reinterpret_cast<UInt8 *>(real_param_2);

  bool bVar1;
  UInt16 uVar2;
  double dVar3;
  UInt32 uVar4;
  SInt32 iVar5;
  SInt32 iVar6;
  UInt32 uVar7;
  SInt32 iVar8;
  UInt32 uVar9;
  UInt32 uVar10;
  UInt32 uVar11;
  
  uVar4 = M<UInt32>(param_2 + 0x3c) >> 0x14 & 0xf;
  if (uVar4 < 2) {
    uVar11 = 0;
    uVar10 = 0xffffff;
  }
  else {
    uVar7 = (1 << uVar4) - 1;
    uVar11 = (SInt32)kLoad3dSamplesTable[uVar4] << 1 |
             1;
    uVar10 = uVar7 | uVar7 * 0x40000 | uVar7 * 0x1000 | uVar7 * 0x40;
  }
  param_1[7] = uVar10;
  *param_1 = 0x1393;
  param_1[1] = 10;
  param_1[2] = 0x13c6;
  param_1[3] = 3;
  param_1[4] = 0x5c8;
  param_1[8] = 0x11004;
  param_1[5] = 0x20000;
  param_1[6] = 0x10fa;
  param_1[9] = M<UInt32>((UInt8 *)kLoad3dMspos0Table +
                         (M<UInt32>(param_2 + 0x3c) >> 0x12 & 0x3c));
  uVar4 = M<UInt32>(param_2 + 0x3c);
  param_1[0xb] = 0x1008;
  param_1[0xc] = uVar11;
  param_1[0xe] = 0;
  param_1[0xd] = 0x1383;
  param_1[0xf] = 0x1006;
  param_1[10] = M<UInt32>((UInt8 *)kLoad3dMspos1Table +
                          (uVar4 >> 0x12 & 0x3c));
  uVar10 = M<UInt32>(M<SInt32>(self + 0xd50) + 0xb74);
  param_1[0x11] = 0x13c7;
  param_1[0x12] = 0xc;
  param_1[0x14] = 0;
  param_1[0x13] = 0x10e9;
  param_1[0x10] = uVar10;
  param_1[0x15] = 0x13c4;
  param_1[0x16] = -((UInt8)param_2[0x3a] ^ 0x10) >> 0x1e & 2;
  param_1[0x17] = 0x113c8;
  param_1[0x18] = M<UInt32>(param_2 + 8);
  uVar4 = M<UInt32>(param_2 + 0x3c);
  bVar1 = (uVar4 & 0xf00000) != 0;
  if (bVar1) {
    uVar7 = (UInt32)M<UInt16>(param_2 + 0x14) / (uVar4 >> 0x14 & 0xf);
  }
  else {
    uVar7 = 0;
  }
  uVar9 = 0x20 / M<UInt16>(param_2 + 0x16);
  if (uVar7 < uVar9) {
    uVar7 = uVar9;
  }
  param_1[0x19] =
       ((UInt8)param_2[0x38] & 6) << 0x10 |
       ((UInt8)param_2[0x38] & 1) << 0x10 | ((UInt8)param_2[0x39] & 3) << 0x13 | uVar7 & 0x3ffc;
  iVar6 = M<SInt32>(self + 0xd50);
  iVar8 = M<SInt32>(iVar6 + 0xb98);
  if (bVar1) {
    uVar4 = (UInt32)M<UInt16>(param_2 + 0x14) / (uVar4 >> 0x14 & 0xf);
  }
  else {
    uVar4 = 0;
  }
  if (uVar9 <= uVar4) {
    uVar9 = uVar4;
  }
  iVar5 = 0x20;
  if (iVar8 != 4) {
    iVar5 = iVar8 << 4;
    uVar10 = 0;
    if (iVar5 == 0) goto LAB_0003d700;
  }
  uVar10 = iVar5 * ((SInt32)(uVar9 + iVar5 + -1) / iVar5);
LAB_0003d700:
  param_1[0x1a] = 0x13cd;
  param_1[0x1b] = uVar10;
  uVar10 = HZMEM_GetBlockOffset((_HZDATA *)((UInt8 *)(iVar6 + 0x870)),M<UInt32>(param_2 + 0x28),0);
  param_1[0x1c] = 0x13cc;
  param_1[0x1d] = uVar10;
  param_1[0x1e] = 0x13ca;
  param_1[0x1f] = M<UInt32>(param_2 + 0x2c);
  param_1[0x21] = 0;
  param_1[0x23] = 0;
  param_1[0x25] = 0;
  param_1[0x27] = 0;
  param_1[0x20] = 0x1041;
  param_1[0x22] = 0x1180;
  param_1[0x2d] = 0;
  param_1[0x2f] = 0;
  param_1[0x31] = 0;
  param_1[0x3d] = 0;
  param_1[0x40] = 0;
  param_1[0x24] = 0x13c0;
  param_1[0x26] = 0x13c1;
  param_1[0x28] = 0x850;
  param_1[0x29] = 0x102;
  param_1[0x2a] = 0x887;
  param_1[0x2e] = 0x10ae;
  param_1[0x2c] = 0x82c;
  param_1[0x32] = 0x824;
  param_1[0x30] = 0x1002;
  param_1[0x33] = 1;
  param_1[0x34] = 0x825;
  param_1[0x36] = 0x82d;
  param_1[0x38] = 0x854;
  param_1[0x39] = 0x26000001;
  param_1[0x3a] = 0x878;
  param_1[0x35] = 4;
  param_1[0x37] = 3;
  param_1[0x3c] = 0x1094;
  param_1[0x2b] = 0x1c000;
  param_1[0x3b] = 0xfb24fb08;
  param_1[0x3e] = 0x59095;   /* literal constant (Ghidra printed it as the address of a data label) */
  param_1[0x3f] = 0x78105;
  param_1[0x41] = 0;
  param_1[0x44] = 0x20490000;
  param_1[0x45] = 0x1181;
  param_1[0x56] = 4;
  param_1[0x60] = 0;
  param_1[0x46] = 0;
  param_1[0x48] = 0;
  param_1[0x4a] = 0;
  param_1[0x4c] = 0;
  param_1[0x58] = 0;
  param_1[0x47] = 0x118d;
  param_1[0x49] = 0x118e;
  param_1[0x4b] = 0x118c;
  param_1[0x4d] = 0x11a9;
  param_1[0x4e] = 0x1b00;
  param_1[0x4f] = 0x11aa;
  param_1[0x51] = 0x11ab;
  param_1[0x53] = 0x11ac;
  param_1[0x55] = 0x10c0;
  param_1[0x57] = 0x10c1;
  param_1[0x59] = 0x10c8;
  param_1[0x5a] = 0x10;
  param_1[0x54] = 0xf;
  param_1[0x42] = 0xdb06d8;
  param_1[0x50] = 0xf;
  param_1[0x5d] = 0x10f4;
  param_1[0x52] = 0xf;
  param_1[0x5f] = 0x10f8;
  param_1[0x43] = 0xc18000;
  param_1[0x5c] = 0xc2040;
  param_1[0x61] = 0x10f9;
  param_1[0x5b] = 0x101d;
  param_1[0x5e] = 0xffff;
  if ((M<UInt32>(param_2 + 0x3c) & 0xf00000) == 0) {
    param_1[0x62] = (M<UInt16>(param_2 + 0x1e) & 0x1fff) << 0xd;
  }
  else {
    param_1[0x62] =
         (UInt32)M<UInt16>(param_2 + 0x1c) / (M<UInt32>(param_2 + 0x3c) >> 0x14 & 0xf) & 0x1fff |
         (M<UInt16>(param_2 + 0x1e) & 0x1fff) << 0xd;
  }
  if ((M<UInt32>(param_2 + 0x3c) & 0xf00000) == 0) {
    uVar4 = 0;
  }
  else {
    uVar4 = ((UInt32)M<UInt16>(param_2 + 0x1c) / (M<UInt32>(param_2 + 0x3c) >> 0x14 & 0xf)) *
            0x60000;
  }
  uVar2 = M<UInt16>(param_2 + 0x1e);
  param_1[0x65] = 0xc0033500;
  param_1[99] = 0x1087;
  param_1[100] = (UInt32)uVar2 * 6 & 0xffff | uVar4;
  param_1[0x66] = 0x10031;
  if ((M<UInt32>(param_2 + 0x3c) & 0xf00000) == 0) {
    param_1[0x67] = 0;
  }
  else {
    param_1[0x67] =
         (UInt32)(float)((double)CONCAT44d(0x43300000,
                                         (SInt32)((UInt32)M<UInt16>(param_2 + 0x1c) /
                                              (M<UInt32>(param_2 + 0x3c) >> 0x14 & 0xf)) >> 1 ^
                                         0x80000000) - DOUBLE_0004c3a8);
  }
  dVar3 = DOUBLE_0004c3a8;
  uVar2 = M<UInt16>(param_2 + 0x1e);
  uVar10 = 0;
  param_1[0x69] = 0;
  param_1[0x6a] = 0x13c6;
  param_1[0x6b] = 3;
  param_1[0x68] = (UInt32)(float)((double)CONCAT44d(0x43300000,uVar2 >> 1 ^ 0x80000000) - dVar3);
  if ((param_2[0x34] != 0x0) &&
     ((2 < M<UInt16>(param_2 + 0x16) ||
      (uVar10 = 4, 2 < (M<UInt32>(param_2 + 0x3c) >> 0x14 & 0xf))))) {
    uVar10 = 0x1c;
  }
  param_1[0x6c] = 0x13c7;
  param_1[0x6d] = uVar10;
  param_1[0x6e] = 0x1393;
  param_1[0x6f] = 10;
  param_1[0x70] = 0x5c8;
  param_1[0x71] = 0x20000;
  return (UInt32 *)(param_1 + 0x72);
}
