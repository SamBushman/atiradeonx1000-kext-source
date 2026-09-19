/*
 * ATIR500GLContext_WriteVertexArrayOffset_Port.cpp
 *
 * ATIR500GLContext::WriteVertexArrayOffset (real addr 0x27470, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x27470 */
UInt32 ATIR500GLContext::WriteVertexArrayOffset(UInt32*param_1, UInt32 param_2) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  bool bVar1;
  UInt32 uVar2;
  SInt32 iVar3;
  UInt32 uVar4;
  SInt32 iVar5;
  UInt8 *pAVar6;
  UInt8 *pAVar7;
  SInt32 iVar8;
  SInt32 iVar9;
  SInt32 iVar10;
  UInt8 bVar11;
  
  iVar5 = 1;
  uVar4 = 0x832;
  pAVar7 = self + 4;
  iVar10 = param_2 * 4 + 4;
  bVar11 = (M<SInt32>(self + 0x364) == 0) << 1;
  pAVar6 = self;
  iVar9 = param_2 * 4 + 8;
  do {
    if ((bool)(bVar11 >> 1 & 1)) {
      iVar3 = 0x10;
      iVar8 = 0x10;
    }
    else {
      iVar3 = iVar5 + 0xf;
      iVar8 = iVar5 + 0x10;
    }
    param_1[param_2] = uVar4 | 0x10000;
    uVar2 = this->GetVertexArrayOffset((VendorTextureBuffer *)(M<UInt8 *>(self + iVar3 * 4 + 0x2a4)),
                       M<UInt32>(pAVar6 + 0x368));
    M<UInt32>((SInt32)param_1 + iVar10) = uVar2;
    param_2 = param_2 + 3;
    iVar10 = iVar10 + 0xc;
    uVar2 = this->GetVertexArrayOffset((VendorTextureBuffer *)(M<UInt8 *>(self + iVar8 * 4 + 0x2a4)),
                       M<UInt32>(pAVar7 + 0x368));
    M<UInt32>((SInt32)param_1 + iVar9) = uVar2;
    bVar1 = iVar5 != 0xf;
    pAVar7 = pAVar7 + 8;
    pAVar6 = pAVar6 + 8;
    uVar4 = uVar4 + 3;
    iVar5 = iVar5 + 2;
    iVar9 = iVar9 + 0xc;
  } while (bVar1);
  return 0x18;
}
