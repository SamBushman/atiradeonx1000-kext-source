/*
 * ATIR500GLContext_build_scissor_Port.cpp
 *
 * ATIR500GLContext::build_scissor (real addr 0x27ee0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x27ee0 */
void ATIR500GLContext::build_scissor() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  SInt32 iVar1;
  UInt32 uVar2;
  SInt32 iVar3;
  UInt8 *pAVar4;
  UInt32 uVar5;
  
  if (M<SInt32>(self + 0x3bc) == 0) {
    uVar5 = M<UInt32>(self + 0x29c);
    pAVar4 = *(UInt8 **)
              ((UInt32)M<UInt16>(self + 0xac) * 4 + M<SInt32>(self + 0x290) + 0xb70);
  }
  else {
    uVar5 = 0;
    pAVar4 = self + (UInt32)M<UInt16>(self + 0x3b2) * 0x78 + 0x3c0;
  }
  if (((M<UInt32>(pAVar4 + 0x3c) & 0xf00000) == 0) ||
     (iVar1 = (SInt32)((UInt32)M<UInt16>(pAVar4 + 0x1c) / (M<UInt32>(pAVar4 + 0x3c) >> 0x14 & 0xf)) >>
              (uVar5 & 0x3f), iVar1 == 0)) {
    iVar1 = 1;
  }
  uVar2 = (SInt32)(UInt32)M<UInt16>(pAVar4 + 0x1e) >> (uVar5 & 0x3f);
  uVar5 = 1;
  if (uVar2 != 0) {
    uVar5 = uVar2;
  }
  uVar2 = FormatTableLookup_0x0004d2dc((UInt32)(UInt8)pAVar4[0x3a] * 0x1c) >> 3 & 0x1f;
  if ((uVar2 < 3) || ((iVar3 = 1, 4 < uVar2 && (iVar3 = 2, uVar2 != 6)))) {
    iVar3 = 0;
  }
  M<UInt32>(self + 0x358) =
       iVar1 << ((FormatTableLookup_0x0004d2dc((UInt32)(UInt8)pAVar4[0x3a] * 0x1c) >> 0xc & 7) - iVar3 &
                0x3f) & 0x3fffU | (uVar5 & 0x3fff) << 0x10;
  return;
}
