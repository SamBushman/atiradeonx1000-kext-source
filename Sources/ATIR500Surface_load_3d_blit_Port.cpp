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
UInt32 *ATIR500Surface::load_3d_blit(UInt32*dest, ATIR500SurfaceBuffer *buffer) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *bufferBytes = reinterpret_cast<UInt8 *>(buffer);

  bool bVar1;
  UInt16 uVar2;
  double dVar3;
  UInt32 uVar4;
  SInt32 iVar5;
  SInt32 accelerator;
  UInt32 uVar7;
  SInt32 iVar8;
  UInt32 uVar9;
  UInt32 uVar10;
  UInt32 uVar11;
  
  uVar4 = M<UInt32>(bufferBytes + 0x3c) >> 0x14 & 0xf;
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
  dest[7] = uVar10;
  *dest = 0x1393;
  dest[1] = 10;
  dest[2] = 0x13c6;
  dest[3] = 3;
  dest[4] = 0x5c8;
  dest[8] = 0x11004;
  dest[5] = 0x20000;
  dest[6] = 0x10fa;
  dest[9] = M<UInt32>((UInt8 *)kLoad3dMspos0Table +
                         (M<UInt32>(bufferBytes + 0x3c) >> 0x12 & 0x3c));
  uVar4 = M<UInt32>(bufferBytes + 0x3c);
  dest[0xb] = 0x1008;
  dest[0xc] = uVar11;
  dest[0xe] = 0;
  dest[0xd] = 0x1383;
  dest[0xf] = 0x1006;
  dest[10] = M<UInt32>((UInt8 *)kLoad3dMspos1Table +
                          (uVar4 >> 0x12 & 0x3c));
  uVar10 = M<UInt32>(M<SInt32>(self + kIOATIR500Surface_accelerator) + 0xb74);
  dest[0x11] = 0x13c7;
  dest[0x12] = 0xc;
  dest[0x14] = 0;
  dest[0x13] = 0x10e9;
  dest[0x10] = uVar10;
  dest[0x15] = 0x13c4;
  dest[0x16] = -((UInt8)bufferBytes[0x3a] ^ 0x10) >> 0x1e & 2;
  dest[0x17] = 0x113c8;
  dest[0x18] = M<UInt32>(bufferBytes + 8);
  uVar4 = M<UInt32>(bufferBytes + 0x3c);
  bVar1 = (uVar4 & 0xf00000) != 0;
  if (bVar1) {
    uVar7 = (UInt32)M<UInt16>(bufferBytes + 0x14) / (uVar4 >> 0x14 & 0xf);
  }
  else {
    uVar7 = 0;
  }
  uVar9 = 0x20 / M<UInt16>(bufferBytes + 0x16);
  if (uVar7 < uVar9) {
    uVar7 = uVar9;
  }
  dest[0x19] =
       ((UInt8)bufferBytes[0x38] & 6) << 0x10 |
       ((UInt8)bufferBytes[0x38] & 1) << 0x10 | ((UInt8)bufferBytes[0x39] & 3) << 0x13 | uVar7 & 0x3ffc;
  accelerator = M<SInt32>(self + kIOATIR500Surface_accelerator);
  iVar8 = M<SInt32>(accelerator + kIOATIR500Accelerator_numPipes);
  if (bVar1) {
    uVar4 = (UInt32)M<UInt16>(bufferBytes + 0x14) / (uVar4 >> 0x14 & 0xf);
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
  dest[0x1a] = 0x13cd;
  dest[0x1b] = uVar10;
  uVar10 = HZMEM_GetBlockOffset((_HZDATA *)((UInt8 *)(accelerator + kIOATIR500Accelerator_hzmem)),M<UInt32>(bufferBytes + 0x28),0);
  dest[0x1c] = 0x13cc;
  dest[0x1d] = uVar10;
  dest[0x1e] = 0x13ca;
  dest[0x1f] = M<UInt32>(bufferBytes + 0x2c);
  dest[0x21] = 0;
  dest[0x23] = 0;
  dest[0x25] = 0;
  dest[0x27] = 0;
  dest[0x20] = 0x1041;
  dest[0x22] = 0x1180;
  dest[0x2d] = 0;
  dest[0x2f] = 0;
  dest[0x31] = 0;
  dest[0x3d] = 0;
  dest[0x40] = 0;
  dest[0x24] = 0x13c0;
  dest[0x26] = 0x13c1;
  dest[0x28] = 0x850;
  dest[0x29] = 0x102;
  dest[0x2a] = 0x887;
  dest[0x2e] = 0x10ae;
  dest[0x2c] = 0x82c;
  dest[0x32] = 0x824;
  dest[0x30] = 0x1002;
  dest[0x33] = 1;
  dest[0x34] = 0x825;
  dest[0x36] = 0x82d;
  dest[0x38] = 0x854;
  dest[0x39] = 0x26000001;
  dest[0x3a] = 0x878;
  dest[0x35] = 4;
  dest[0x37] = 3;
  dest[0x3c] = 0x1094;
  dest[0x2b] = 0x1c000;
  dest[0x3b] = 0xfb24fb08;
  dest[0x3e] = 0x59095;   /* literal constant (Ghidra printed it as the address of a data label) */
  dest[0x3f] = 0x78105;
  dest[0x41] = 0;
  dest[0x44] = 0x20490000;
  dest[0x45] = 0x1181;
  dest[0x56] = 4;
  dest[0x60] = 0;
  dest[0x46] = 0;
  dest[0x48] = 0;
  dest[0x4a] = 0;
  dest[0x4c] = 0;
  dest[0x58] = 0;
  dest[0x47] = 0x118d;
  dest[0x49] = 0x118e;
  dest[0x4b] = 0x118c;
  dest[0x4d] = 0x11a9;
  dest[0x4e] = 0x1b00;
  dest[0x4f] = 0x11aa;
  dest[0x51] = 0x11ab;
  dest[0x53] = 0x11ac;
  dest[0x55] = 0x10c0;
  dest[0x57] = 0x10c1;
  dest[0x59] = 0x10c8;
  dest[0x5a] = 0x10;
  dest[0x54] = 0xf;
  dest[0x42] = 0xdb06d8;
  dest[0x50] = 0xf;
  dest[0x5d] = 0x10f4;
  dest[0x52] = 0xf;
  dest[0x5f] = 0x10f8;
  dest[0x43] = 0xc18000;
  dest[0x5c] = 0xc2040;
  dest[0x61] = 0x10f9;
  dest[0x5b] = 0x101d;
  dest[0x5e] = 0xffff;
  if ((M<UInt32>(bufferBytes + 0x3c) & 0xf00000) == 0) {
    dest[0x62] = (M<UInt16>(bufferBytes + 0x1e) & 0x1fff) << 0xd;
  }
  else {
    dest[0x62] =
         (UInt32)M<UInt16>(bufferBytes + 0x1c) / (M<UInt32>(bufferBytes + 0x3c) >> 0x14 & 0xf) & 0x1fff |
         (M<UInt16>(bufferBytes + 0x1e) & 0x1fff) << 0xd;
  }
  if ((M<UInt32>(bufferBytes + 0x3c) & 0xf00000) == 0) {
    uVar4 = 0;
  }
  else {
    uVar4 = ((UInt32)M<UInt16>(bufferBytes + 0x1c) / (M<UInt32>(bufferBytes + 0x3c) >> 0x14 & 0xf)) *
            0x60000;
  }
  uVar2 = M<UInt16>(bufferBytes + 0x1e);
  dest[0x65] = 0xc0033500;
  dest[99] = 0x1087;
  dest[100] = (UInt32)uVar2 * 6 & 0xffff | uVar4;
  dest[0x66] = 0x10031;
  if ((M<UInt32>(bufferBytes + 0x3c) & 0xf00000) == 0) {
    dest[0x67] = 0;
  }
  else {
    dest[0x67] =
         FBITS((float)((double)CONCAT44d(0x43300000,
                                         (SInt32)((UInt32)M<UInt16>(bufferBytes + 0x1c) /
                                              (M<UInt32>(bufferBytes + 0x3c) >> 0x14 & 0xf)) >> 1 ^
                                         0x80000000) - DOUBLE_0004c3a8));
  }
  dVar3 = DOUBLE_0004c3a8;
  uVar2 = M<UInt16>(bufferBytes + 0x1e);
  uVar10 = 0;
  dest[0x69] = 0;
  dest[0x6a] = 0x13c6;
  dest[0x6b] = 3;
  dest[0x68] = FBITS((float)((double)CONCAT44d(0x43300000,uVar2 >> 1 ^ 0x80000000) - dVar3));
  if ((bufferBytes[0x34] != 0x0) &&
     ((2 < M<UInt16>(bufferBytes + 0x16) ||
      (uVar10 = 4, 2 < (M<UInt32>(bufferBytes + 0x3c) >> 0x14 & 0xf))))) {
    uVar10 = 0x1c;
  }
  dest[0x6c] = 0x13c7;
  dest[0x6d] = uVar10;
  dest[0x6e] = 0x1393;
  dest[0x6f] = 10;
  dest[0x70] = 0x5c8;
  dest[0x71] = 0x20000;
  return (UInt32 *)(dest + 0x72);
}
