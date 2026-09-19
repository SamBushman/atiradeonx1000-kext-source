/*
 * ATIR500GLContext_write_r500_zdecompress_restore_add_on_packet_Port.cpp
 *
 * ATIR500GLContext::write_r500_zdecompress_restore_add_on_packet (real addr 0x28780, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x28780 */
void ATIR500GLContext::write_r500_zdecompress_restore_add_on_packet(r500_zdecompress_restore_add_on_packet_struct *real_param_1) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *param_1 = reinterpret_cast<UInt8 *>(real_param_1);

  SInt32 iVar1;
  UInt32 uVar2;
  UInt32 uVar3;
  SInt32 iVar4;
  UInt32 uVar5;
  UInt8 *pAVar6;
  
  pAVar6 = self + 0x5a0;
  if (M<SInt32>(self + 0x3bc) == 0) {
    pAVar6 = *(UInt8 **)
              ((UInt32)M<UInt16>(self + 0xae) * 4 + M<SInt32>(self + 0x290) + 0xb70);
  }
  uVar5 = 0;
  M<UInt32>(param_1 + 4) = -((UInt8)pAVar6[0x3a] ^ 0x10) >> 0x1e & 2;
  M<UInt32>(param_1 + 0xc) = M<UInt32>(pAVar6 + 8);
  if ((M<UInt32>(pAVar6 + 0x3c) & 0xf00000) != 0) {
    uVar5 = (UInt32)M<UInt16>(pAVar6 + 0x14) / (M<UInt32>(pAVar6 + 0x3c) >> 0x14 & 0xf);
  }
  uVar2 = 0x20 / M<UInt16>(pAVar6 + 0x16);
  if (0x20 / M<UInt16>(pAVar6 + 0x16) <= uVar5) {
    uVar2 = uVar5;
  }
  uVar5 = 0;
  M<UInt32>(param_1 + 0x10) =
       ((UInt8)pAVar6[0x38] & 6) << 0x10 |
       ((UInt8)pAVar6[0x38] & 1) << 0x10 | ((UInt8)pAVar6[0x39] & 3) << 0x13 | uVar2 & 0x3ffc;
  if ((M<UInt32>(pAVar6 + 0x3c) & 0xf00000) != 0) {
    uVar5 = (UInt32)M<UInt16>(pAVar6 + 0x14) / (M<UInt32>(pAVar6 + 0x3c) >> 0x14 & 0xf);
  }
  uVar2 = 0x20 / M<UInt16>(pAVar6 + 0x16);
  if (0x20 / M<UInt16>(pAVar6 + 0x16) <= uVar5) {
    uVar2 = uVar5;
  }
  iVar1 = 0x20;
  if (M<SInt32>(M<SInt32>(self + 200) + 0xb98) != 4) {
    iVar1 = M<SInt32>(M<SInt32>(self + 200) + 0xb98) << 4;
    iVar4 = 0;
    if (iVar1 == 0) goto LAB_0002888c;
  }
  iVar4 = iVar1 * ((SInt32)(uVar2 + iVar1 + -1) / iVar1);
LAB_0002888c:
  M<SInt32>(param_1 + 0x18) = iVar4;
  uVar3 = HZMEM_GetBlockOffset
                    ((_HZDATA *)((UInt8 *)(M<SInt32>(self + 200) + 0x870)),M<UInt32>(pAVar6 + 0x28),0);
  M<UInt32>(param_1 + 0x20) = uVar3;
  M<UInt32>(param_1 + 0x28) = M<UInt32>(pAVar6 + 0x2c);
  return;
}
