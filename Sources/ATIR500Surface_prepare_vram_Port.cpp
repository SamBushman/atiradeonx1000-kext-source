/*
 * ATIR500Surface_prepare_vram_Port.cpp
 *
 * ATIR500Surface::prepare_vram (real addr 0x3dc50, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x3dc50 */
UInt32 ATIR500Surface::prepare_vram(ATIR500SurfaceBuffer *real_param_1) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *param_1 = reinterpret_cast<UInt8 *>(real_param_1);

  UInt8 AVar1;
  UInt32 uVar2;
  SInt32 iVar3;
  SInt32 *piVar4;
  UInt32 uVar5;
  SInt32 iVar6;
  UInt32 uVar7;
  SInt32 iVar8;
  UInt32 uVar9;
  SInt32 iVar10;
  UInt8 *this_00;
  UInt32 *puVar11;
  
  AVar1 = param_1[0x3c];
  param_1[0x3c] = ((char)AVar1 + 1U);
  if (1 < (UInt8)((char)AVar1 + 1U)) {
    return 1;
  }
  iVar8 = M<SInt32>(self + 0xd50);
  if (M<UInt8>(iVar8 + 0x990) == 0) {
LAB_0003dcc0:
    param_1[0x3c] = 0x0;
    return 0;
  }
  uVar9 = M<UInt32>(iVar8 + 0x890);
  uVar7 = 0;
  if ((uVar9 & 1) == 0) {
    uVar7 = 0;
  }
  else {
    do {
      uVar2 = uVar7 + 1;
      uVar7 = uVar2 & 0xff;
      if (uVar7 == M<UInt8>(iVar8 + 0x990)) goto LAB_0003dcc0;
    } while ((uVar9 & 1 << (uVar2 & 0x3f)) != 0);
  }
  M<UInt32>(iVar8 + 0x890) = 1 << (uVar7 & 0x3f) | uVar9;
  param_1[0x37] = SUB41m(uVar7,0);
  piVar4 = M<SInt32 *>(self + 0xd50);
  if (M<char>(piVar4 + 0x20) == '\0') {
    return 1;
  }
  iVar6 = piVar4[0x8e];
  iVar8 = uVar7 * 4;
  iVar10 = M<SInt32>(param_1 + 8);
  puVar11 = (UInt32 *)(iVar6 + 0x120);
  if ((M<UInt32>(param_1 + 0x3c) >> 0x14 & 0xf) < 2) {
    switch(param_1[0x38]) {
    default:
      goto switchD_0003dd5c_caseD_0;
    case 0x1:
      iVar3 = 1;
      break;
    case 0x2:
      iVar3 = 2;
      break;
    case 0x3:
      iVar3 = 3;
      break;
    case 0x4:
      iVar3 = 6;
      break;
    case 0x5:
      iVar3 = 7;
    }
    uVar7 = iVar3 << 0x10;
    uVar9 = (UInt32)(M<UInt16>(param_1 + 0x18) >> 3);
  }
  else {
switchD_0003dd5c_caseD_0:
    uVar9 = 0;
    uVar7 = 0;
  }
  AVar1 = param_1[0x39];
  VCALL(*piVar4, 0x54c)(piVar4,piVar4[0x8d]);
  *puVar11 = iVar8 + 0x2c1;
  M<SInt32>(iVar6 + 0x124) = iVar10;
  M<SInt32>(iVar6 + 0x128) = iVar8 + 0x2c2;
  M<SInt32>(iVar6 + 300) = iVar10 + M<SInt32>(param_1 + 0x10) + -1;
  M<SInt32>(iVar6 + 0x130) = iVar8 + 0x2c3;
  M<UInt32>(iVar6 + 0x134) = uVar7 | uVar9 | ((UInt8)AVar1 & 3) << 0x14 | ((UInt8)AVar1 & 3) << 0x16;
  if ((M<UInt32>(param_1 + 0x3c) & 0x800) == 0) {
    M<UInt32>(iVar6 + 0x138) = 0xd0b;
    M<UInt32>(iVar6 + 0x13c) = 5;
    M<UInt32>(iVar6 + 0x140) = 0x1393;
    M<UInt32>(iVar6 + 0x144) = 10;
    iVar6 = 10;
    iVar8 = 0x28;
    iVar10 = 0xb;
    uVar7 = 0xc;
  }
  else {
    iVar6 = this->decompress_and_flush_depth_buffer((ATIR500SurfaceBuffer *)(param_1),6,(UInt32 *)(puVar11));
    iVar8 = iVar6 << 2;
    iVar10 = iVar6 + 1;
    uVar7 = iVar6 + 2;
  }
  M<UInt32>((SInt32)puVar11 + iVar8) = 0x5c8;
  puVar11[iVar10] = 0x70000;
  uVar9 = uVar7;
  if ((uVar7 & 7) != 0) {
    uVar9 = iVar6 + 3;
    puVar11[uVar7] = 0x80000000;
  }
  this_00 = M<UInt8 *>(self + 0xd50);
  uVar5 = ((ATIRadeonX1000 *)(this_00))->submit_buffer((UInt32 *)(puVar11), M<SInt32>(this_00 + 0x228) + 0x120, uVar9);
  M<UInt32>(this_00 + 0x234) = uVar5;
  piVar4 = M<SInt32 *>(self + 0xd50);
  VCALL(*piVar4, 0x54c)(piVar4,piVar4[0x8d]);
  return 1;
}
