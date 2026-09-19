/*
 * ATIR500GLContext_build_surface_from_texture_Port.cpp
 *
 * ATIR500GLContext::build_surface_from_texture (real addr 0x28200, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x28200 */
void ATIR500GLContext::build_surface_from_texture(VendorTextureBuffer *real_param_1, ATIR500SurfaceBuffer *real_param_2, UInt16 param_3, UInt16 param_4, UInt8 param_5, UInt32 param_6, UInt16 param_7) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *param_1 = reinterpret_cast<UInt8 *>(real_param_1);
    UInt8 *param_2 = reinterpret_cast<UInt8 *>(real_param_2);

  UInt8 bVar1;
  UInt8 AVar2;
  UInt32 uVar3;
  SInt32 iVar4;
  UInt32 uVar5;
  UInt32 uVar6;
  UInt16 uVar7;
  SInt32 iVar8;
  UInt32 in_register_00000020;
  UInt32 uVar9;
  UInt32 uVar10;
  
  param_2[0x3c] = 0x0;
  param_2[0x37] = 0xff;
  param_2[0x3b] = 0x6;
  M<UInt32>(param_2 + 0x44) = 0;
  M<UInt32>(param_2) = 0;
  M<UInt32>(param_2 + 4) = 0;
  M<UInt32>(param_2 + 8) = 0;
  M<UInt32>(param_2 + 0xc) = 0;
  M<UInt32>(param_2 + 0x10) = 0;
  M<UInt16>(param_2 + 0x14) = 0;
  M<UInt16>(param_2 + 0x16) = 0;
  M<UInt32>(param_2 + 0x24) = 0;
  M<UInt32>(param_2 + 0x28) = 0xffffffff;
  M<UInt32>(param_2 + 0x2c) = 0;
  M<UInt32>(param_2 + 0x30) = 0;
  M<UInt16>(param_2 + 0x1c) = param_3;
  M<UInt16>(param_2 + 0x1e) = param_4;
  M<UInt16>(param_2 + 0x18) = 0;
  param_2[0x34] = 0x0;
  param_2[0x35] = 0x0;
  param_2[0x36] = 0x0;
  param_2[0x38] = 0x0;
  param_2[0x39] = 0x0;
  M<UInt16>(param_2 + 0x22) = 1;
  M<UInt16>(param_2 + 0x20) = 1;
  M<UInt32>(param_2 + 0x40) = 0;
  M<UInt32>(param_2 + 0x3c) = M<UInt32>(param_2 + 0x3c) & 0xff0007ff | 0x111000;
  if (param_1[0x20] == 0x6) {
    iVar4 = this->GetTextureOffset((VendorTextureBuffer *)(param_1),true);
    M<UInt32>(param_2 + 8) = iVar4 + param_6;
  }
  else {
    M<UInt32>(param_2 + 8) = param_6 + M<SInt32>(param_1 + 0x48);
  }
  uVar3 = M<UInt32>(param_1 + 0x4c);
  uVar5 = M<UInt32>(param_1 + 0x40);
  uVar9 = M<UInt32>(param_1 + 0x44);
  M<UInt16>(param_2 + 0x18) = param_7;
  param_2[0x3a] = param_5;
  M<UInt32>(param_2 + 0xc) = uVar3;
  M<UInt32>(param_2) = uVar5;
  M<UInt32>(param_2 + 4) = uVar9;
  iVar4 = ((UInt32)param_5) * 0x1c;
  bVar1 = M<UInt8>(M<SInt32>(param_1 + 0x14) + 0x15) >> 2;
  AVar2 = (bVar1 & 7);
  param_2[0x38] = AVar2;
  if ((UInt8)AVar2 < 2) {
    uVar10 = FormatTableLookup_0x0004d2dc(iVar4);
    iVar8 = 1;
  }
  else {
    uVar10 = FormatTableLookup_0x0004d2dc(iVar4);
    iVar8 = 1 << (uVar10 >> 8 & 3);
  }
  if (((UInt32)M<UInt16>(param_2 + 0x18) < (UInt32)((0x20 >> (uVar10 >> 8 & 3)) << 3)) ||
     ((UInt32)M<UInt16>(param_2 + 0x1e) < (UInt32)(iVar8 << 3))) {
    param_2[0x38] = (bVar1 & 6);
    uVar10 = FormatTableLookup_0x0004d2dc(iVar4);
  }
  uVar6 = 1 << (uVar10 >> 0xc & 7);
  uVar10 = uVar6 & 0xffff;
  uVar7 = (UInt16)uVar6;
  M<UInt16>(param_2 + 0x16) = uVar7;
  if (uVar10 == 0) {
    M<UInt16>(param_2 + 0x14) = uVar7;
  }
  else {
    M<SInt16>(param_2 + 0x14) = (SInt16)(M<UInt16>(param_2 + 0x18) / uVar10);
  }
  M<UInt32>(param_2 + 0x28) = M<UInt32>(param_1 + 0x6c);
  param_2[0x34] = SUB21(M<UInt16>(param_1 + 0x7a),0);
  param_2[0x35] = SUB21((UInt16)M<UInt16>(param_1 + 0x7a) >> 8,0);
  return;
}
