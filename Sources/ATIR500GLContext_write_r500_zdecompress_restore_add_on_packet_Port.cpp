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
void ATIR500GLContext::write_r500_zdecompress_restore_add_on_packet(r500_zdecompress_restore_add_on_packet_struct *packet) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *packetBytes = reinterpret_cast<UInt8 *>(packet);

  SInt32 iVar1;
  UInt32 uVar2;
  UInt32 uVar3;
  SInt32 iVar4;
  UInt32 uVar5;
  UInt8 *depthBuffer;
  
  depthBuffer = self + kATIR500GLContext_textureDepthBuffer;
  if (M<SInt32>(self + kATIR500GLContext_renderToTexture) == 0) {
    depthBuffer = *(UInt8 **)
              ((UInt32)M<UInt16>(self + kIOATIR500GLContext_depthBufferIndex) * 4 + M<SInt32>(self + kIOATIR500GLContext_boundSurface) + 0xb70);
  }
  uVar5 = 0;
  M<UInt32>(packetBytes + 4) = -((UInt8)depthBuffer[0x3a] ^ 0x10) >> 0x1e & 2;
  M<UInt32>(packetBytes + 0xc) = M<UInt32>(depthBuffer + 8);
  if ((M<UInt32>(depthBuffer + 0x3c) & 0xf00000) != 0) {
    uVar5 = (UInt32)M<UInt16>(depthBuffer + 0x14) / (M<UInt32>(depthBuffer + 0x3c) >> 0x14 & 0xf);
  }
  uVar2 = 0x20 / M<UInt16>(depthBuffer + 0x16);
  if (0x20 / M<UInt16>(depthBuffer + 0x16) <= uVar5) {
    uVar2 = uVar5;
  }
  uVar5 = 0;
  M<UInt32>(packetBytes + 0x10) =
       ((UInt8)depthBuffer[0x38] & 6) << 0x10 |
       ((UInt8)depthBuffer[0x38] & 1) << 0x10 | ((UInt8)depthBuffer[0x39] & 3) << 0x13 | uVar2 & 0x3ffc;
  if ((M<UInt32>(depthBuffer + 0x3c) & 0xf00000) != 0) {
    uVar5 = (UInt32)M<UInt16>(depthBuffer + 0x14) / (M<UInt32>(depthBuffer + 0x3c) >> 0x14 & 0xf);
  }
  uVar2 = 0x20 / M<UInt16>(depthBuffer + 0x16);
  if (0x20 / M<UInt16>(depthBuffer + 0x16) <= uVar5) {
    uVar2 = uVar5;
  }
  iVar1 = 0x20;
  if (M<SInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0xb98) != 4) {
    iVar1 = M<SInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0xb98) << 4;
    iVar4 = 0;
    if (iVar1 == 0) goto LAB_0002888c;
  }
  iVar4 = iVar1 * ((SInt32)(uVar2 + iVar1 + -1) / iVar1);
LAB_0002888c:
  M<SInt32>(packetBytes + 0x18) = iVar4;
  uVar3 = HZMEM_GetBlockOffset
                    ((_HZDATA *)((UInt8 *)(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x870)),M<UInt32>(depthBuffer + 0x28),0);
  M<UInt32>(packetBytes + 0x20) = uVar3;
  M<UInt32>(packetBytes + 0x28) = M<UInt32>(depthBuffer + 0x2c);
  return;
}
