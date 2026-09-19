/*
 * ATIR500GLContext_restore_state_destroyed_by_pageoff_Port.cpp
 *
 * ATIR500GLContext::restore_state_destroyed_by_pageoff (real addr 0x2af10, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



struct tracked_register_set;
extern "C" void track_regs_written_by_pm4(tracked_register_set *state, UInt32 *rangeStart, UInt32 *rangeEnd) asm("__Z25track_regs_written_by_pm4P20tracked_register_setPmS1_");

/* real addr 0x2af10 */
void ATIR500GLContext::restore_state_destroyed_by_pageoff(register_tracking_state *real_param_1) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *param_1 = reinterpret_cast<UInt8 *>(real_param_1);

  UInt32 uVar1;
  UInt32 uVar2;
  UInt32 *puVar3;
  SInt32 iVar4;
  UInt32 uVar5;
  UInt32 *puVar6;
  UInt32 uVar7;
  UInt32 uVar8;
  SInt32 *piVar9;
  SInt32 iVar10;
  r500_3d_blit_state_packet_struct *prVar11;
  
  M<UInt32>(M<SInt32>(self + 200) + 0xb90) = 0;
  track_regs_written_by_pm4
            ((tracked_register_set *)param_1,M<UInt32 *>(param_1 + 0x134),
             M<UInt32 *>(param_1 + 0x138));
  M<UInt32>(param_1 + 0x134) = M<UInt32>(param_1 + 0x138);
  track_regs_written_by_pm4
            ((tracked_register_set *)param_1,M<UInt32 *>(param_1 + 0x13c),
             M<UInt32 *>(param_1 + 0x140));
  M<UInt32>(param_1 + 0x13c) = M<UInt32>(param_1 + 0x140);
  VCALL(M<SInt32>(self), 0x5a4)(self);
  piVar9 = M<SInt32 *>(self + 200);
  uVar1 = M<SInt32>(self + 0x28c) + 1U & 0xf;
  M<UInt32>(self + 0x28c) = uVar1;
  iVar10 = piVar9[0x1e0];
  iVar4 = VCALL(*piVar9, 0x54c)(piVar9,M<UInt32>(self + uVar1 * 0x18 + 0x11c));
  piVar9[0x1e0] = iVar10 + iVar4;
  puVar3 = M<UInt32 *>(self + 0x108);
  puVar6 = M<UInt32 *>(self + uVar1 * 0x18 + 0x120);
  uVar8 = puVar3[1];
  uVar7 = puVar3[2];
  uVar5 = puVar3[3];
  *puVar6 = *puVar3;
  puVar6[1] = uVar8;
  puVar6[2] = uVar7;
  puVar6[3] = uVar5;
  uVar8 = puVar3[4];
  uVar7 = puVar3[5];
  uVar5 = puVar3[6];
  puVar6[7] = puVar3[7];
  puVar6[4] = uVar8;
  puVar6[5] = uVar7;
  puVar6[6] = uVar5;
  iVar4 = M<SInt32>(self + uVar1 * 0x18 + 0x120);
  prVar11 = (r500_3d_blit_state_packet_struct *)(iVar4 + 0x20);
  M<UInt32>(iVar4 + 0x20) = 0x1393;
  M<UInt32>(iVar4 + 0x28) = 0x13c6;
  M<UInt32>(iVar4 + 0x24) = 10;
  M<UInt32>(iVar4 + 0x34) = 0x8000;
  M<UInt32>(iVar4 + 0x30) = 0x5c8;
  M<UInt32>(iVar4 + 0x2c) = 3;
  M<UInt32>(iVar4 + 0x38) = 0x10ea;
  uVar5 = M<UInt32>(param_1);
  M<UInt32>(iVar4 + 0x40) = 0x10fa;
  M<UInt32>(iVar4 + 0x3c) = uVar5;
  uVar5 = M<UInt32>(param_1 + 4);
  M<UInt32>(iVar4 + 0x48) = 0xc0001000;
  M<UInt32>(iVar4 + 0x44) = uVar5;
  M<UInt32>(iVar4 + 0x50) = 0x11004;
  M<UInt32>(iVar4 + 0x54) = M<UInt32>(param_1 + 0xc);
  uVar5 = M<UInt32>(param_1 + 0x10);
  M<UInt32>(iVar4 + 0x5c) = 0x1008;
  M<UInt32>(iVar4 + 0x58) = uVar5;
  uVar5 = M<UInt32>(param_1 + 0x14);
  M<UInt32>(iVar4 + 100) = 0x10e9;
  M<UInt32>(iVar4 + 0x60) = uVar5;
  uVar5 = M<UInt32>(param_1 + 0x18);
  M<UInt32>(iVar4 + 0x6c) = 0x13c7;
  M<UInt32>(iVar4 + 0x68) = uVar5;
  uVar5 = M<UInt32>(param_1 + 0x1c);
  M<UInt32>(iVar4 + 0x74) = 0x13c1;
  M<UInt32>(iVar4 + 0x70) = uVar5;
  uVar5 = M<UInt32>(param_1 + 0x20);
  M<UInt32>(iVar4 + 0x7c) = 0x850;
  M<UInt32>(iVar4 + 0x78) = uVar5;
  uVar5 = M<UInt32>(param_1 + 0x24);
  M<UInt32>(iVar4 + 0x84) = 0x887;
  M<UInt32>(iVar4 + 0x80) = uVar5;
  uVar5 = M<UInt32>(param_1 + 0x28);
  M<UInt32>(iVar4 + 0x30c) = 0x82c;
  M<UInt32>(iVar4 + 0x88) = uVar5;
  uVar5 = M<UInt32>(param_1 + 0x2c);
  M<UInt32>(iVar4 + 0x8c) = 0x10ae;
  M<UInt32>(iVar4 + 0x310) = uVar5;
  uVar5 = M<UInt32>(param_1 + 0x30);
  M<UInt32>(iVar4 + 0x94) = 0x1394;
  M<UInt32>(iVar4 + 0x90) = uVar5;
  uVar5 = M<UInt32>(param_1 + 0x34);
  M<UInt32>(iVar4 + 0x9c) = 0x1380;
  M<UInt32>(iVar4 + 0xa0) = 0;
  M<UInt32>(iVar4 + 0x98) = uVar5;
  M<UInt32>(iVar4 + 0xa4) = 0x1002;
  uVar5 = M<UInt32>(param_1 + 0x3c);
  M<UInt32>(iVar4 + 0xac) = 0x824;
  M<UInt32>(iVar4 + 0xa8) = uVar5;
  uVar5 = M<UInt32>(param_1 + 0x40);
  M<UInt32>(iVar4 + 0xb4) = 0x825;
  M<UInt32>(iVar4 + 0xb0) = uVar5;
  uVar5 = M<UInt32>(param_1 + 0x44);
  M<UInt32>(iVar4 + 0xbc) = 0x82d;
  M<UInt32>(iVar4 + 0xb8) = uVar5;
  uVar5 = M<UInt32>(param_1 + 0x48);
  M<UInt32>(iVar4 + 0xc4) = 0x854;
  M<UInt32>(iVar4 + 0xc0) = uVar5;
  uVar5 = M<UInt32>(param_1 + 0x4c);
  M<UInt32>(iVar4 + 0xcc) = 0x878;
  M<UInt32>(iVar4 + 200) = uVar5;
  uVar5 = M<UInt32>(param_1 + 0x50);
  M<UInt32>(iVar4 + 0xd4) = 0x13c0;
  M<UInt32>(iVar4 + 0xd0) = uVar5;
  uVar5 = M<UInt32>(param_1 + 0x54);
  M<UInt32>(iVar4 + 0xdc) = 0x12f0;
  M<UInt32>(iVar4 + 0xd8) = uVar5;
  uVar5 = M<UInt32>(param_1 + 0x58);
  M<UInt32>(iVar4 + 0xe4) = 0x12f5;
  M<UInt32>(iVar4 + 0xe0) = uVar5;
  uVar5 = M<UInt32>(param_1 + 0x5c);
  M<UInt32>(iVar4 + 0xec) = 0x10a2;
  M<UInt32>(iVar4 + 0xe8) = uVar5;
  uVar5 = M<UInt32>(param_1 + 0x60);
  M<UInt32>(iVar4 + 0xf4) = 0x1381;
  M<UInt32>(iVar4 + 0xf0) = uVar5;
  uVar5 = M<UInt32>(param_1 + 100);
  M<UInt32>(iVar4 + 0xfc) = 0x109e;
  M<UInt32>(iVar4 + 0xf8) = uVar5;
  M<UInt32>(iVar4 + 0x100) = M<UInt32>(param_1 + 0x68);
  M<UInt32>(iVar4 + 0x104) = 0x1096;
  uVar5 = M<UInt32>(param_1 + 0x6c);
  M<UInt32>(iVar4 + 0x10c) = 0x1041;
  M<UInt32>(iVar4 + 0x108) = uVar5;
  uVar5 = M<UInt32>(param_1 + 0x70);
  M<UInt32>(iVar4 + 0x114) = 0x1046;
  M<UInt32>(iVar4 + 0x110) = uVar5;
  uVar5 = M<UInt32>(param_1 + 0x74);
  M<UInt32>(iVar4 + 0x124) = 0x1095;
  M<UInt32>(iVar4 + 0x11c) = 0x1094;
  M<UInt32>(iVar4 + 0x120) = 0;
  M<UInt32>(iVar4 + 0x118) = uVar5;
  uVar5 = M<UInt32>(param_1 + 0x104);
  M<UInt32>(iVar4 + 300) = 0x1095;
  M<UInt32>(iVar4 + 0x128) = uVar5;
  uVar5 = M<UInt32>(param_1 + 0x108);
  M<UInt32>(iVar4 + 0x134) = 0x1095;
  M<UInt32>(iVar4 + 0x130) = uVar5;
  uVar5 = M<UInt32>(param_1 + 0x10c);
  M<UInt32>(iVar4 + 0x13c) = 0x1095;
  M<UInt32>(iVar4 + 0x138) = uVar5;
  uVar5 = M<UInt32>(param_1 + 0x110);
  M<UInt32>(iVar4 + 0x144) = 0x1095;
  M<UInt32>(iVar4 + 0x140) = uVar5;
  uVar5 = M<UInt32>(param_1 + 0x114);
  M<UInt32>(iVar4 + 0x14c) = 0x1095;
  M<UInt32>(iVar4 + 0x148) = uVar5;
  uVar5 = M<UInt32>(param_1 + 0x118);
  M<UInt32>(iVar4 + 0x154) = 0x1095;
  M<UInt32>(iVar4 + 0x150) = uVar5;
  uVar5 = M<UInt32>(param_1 + 0x11c);
  M<UInt32>(iVar4 + 0x15c) = 0x1095;
  M<UInt32>(iVar4 + 0x158) = uVar5;
  M<UInt32>(iVar4 + 0x160) = M<UInt32>(param_1 + 0x120);
  M<UInt32>(iVar4 + 0x164) = 0x1095;
  uVar5 = M<UInt32>(param_1 + 0x124);
  M<UInt32>(iVar4 + 0x16c) = 0x1095;
  M<UInt32>(iVar4 + 0x168) = uVar5;
  uVar5 = M<UInt32>(param_1 + 0x128);
  M<UInt32>(iVar4 + 0x174) = 0x1095;
  M<UInt32>(iVar4 + 0x170) = uVar5;
  uVar5 = M<UInt32>(param_1 + 300);
  M<UInt32>(iVar4 + 0x17c) = 0x1095;
  M<UInt32>(iVar4 + 0x178) = uVar5;
  uVar5 = M<UInt32>(param_1 + 0x130);
  M<UInt32>(iVar4 + 0x184) = 0xc0221000;
  M<UInt32>(iVar4 + 0x214) = 0x1180;
  M<UInt32>(iVar4 + 0x180) = uVar5;
  uVar5 = M<UInt32>(param_1 + 0x88);
  M<UInt32>(iVar4 + 0x21c) = 0x1189;
  M<UInt32>(iVar4 + 0x218) = uVar5;
  uVar5 = M<UInt32>(param_1 + 0x8c);
  M<UInt32>(iVar4 + 0x224) = 0x1181;
  M<UInt32>(iVar4 + 0x220) = uVar5;
  uVar5 = M<UInt32>(param_1 + 0x90);
  M<UInt32>(iVar4 + 0x22c) = 0x118d;
  M<UInt32>(iVar4 + 0x228) = uVar5;
  uVar5 = M<UInt32>(param_1 + 0x94);
  M<UInt32>(iVar4 + 0x234) = 0x118e;
  M<UInt32>(iVar4 + 0x230) = uVar5;
  uVar5 = M<UInt32>(param_1 + 0x98);
  M<UInt32>(iVar4 + 0x23c) = 0x118c;
  M<UInt32>(iVar4 + 0x238) = uVar5;
  uVar5 = M<UInt32>(param_1 + 0x9c);
  M<UInt32>(iVar4 + 0x244) = 0x11a9;
  M<UInt32>(iVar4 + 0x240) = uVar5;
  M<UInt32>(iVar4 + 0x248) = M<UInt32>(param_1 + 0x78);
  M<UInt32>(iVar4 + 0x24c) = 0x11aa;
  uVar5 = M<UInt32>(param_1 + 0x7c);
  M<UInt32>(iVar4 + 0x254) = 0x11ab;
  M<UInt32>(iVar4 + 0x250) = uVar5;
  uVar5 = M<UInt32>(param_1 + 0x80);
  M<UInt32>(iVar4 + 0x25c) = 0x11ac;
  M<UInt32>(iVar4 + 600) = uVar5;
  uVar5 = M<UInt32>(param_1 + 0x84);
  M<UInt32>(iVar4 + 0x264) = 0x10c0;
  M<UInt32>(iVar4 + 0x260) = uVar5;
  uVar5 = M<UInt32>(param_1 + 0xa0);
  M<UInt32>(iVar4 + 0x26c) = 0x10c1;
  M<UInt32>(iVar4 + 0x268) = uVar5;
  uVar5 = M<UInt32>(param_1 + 0xa4);
  M<UInt32>(iVar4 + 0x274) = 0x10c8;
  M<UInt32>(iVar4 + 0x270) = uVar5;
  uVar5 = M<UInt32>(param_1 + 0xa8);
  M<UInt32>(iVar4 + 0x27c) = 0x101d;
  M<UInt32>(iVar4 + 0x278) = uVar5;
  uVar5 = M<UInt32>(param_1 + 0xac);
  M<UInt32>(iVar4 + 0x284) = 0x138a;
  M<UInt32>(iVar4 + 0x28c) = 0x138e;
  M<UInt32>(iVar4 + 0x2a0) = 0;
  M<UInt32>(iVar4 + 0x294) = 0x1040;
  M<UInt32>(iVar4 + 0x288) = 0;
  M<UInt32>(iVar4 + 0x2a4) = 0x1100;
  M<UInt32>(iVar4 + 0x290) = 0;
  M<UInt32>(iVar4 + 0x280) = uVar5;
  M<UInt32>(iVar4 + 0x298) = 0;
  M<UInt32>(iVar4 + 0x29c) = 0x1150;
  uVar5 = M<UInt32>(param_1 + 0xc0);
  M<UInt32>(iVar4 + 0x2ac) = 0x1110;
  M<UInt32>(iVar4 + 0x2a8) = uVar5;
  M<UInt32>(iVar4 + 0x2b0) = M<UInt32>(param_1 + 0xc4);
  M<UInt32>(iVar4 + 0x2b4) = 0x1120;
  uVar5 = M<UInt32>(param_1 + 200);
  M<UInt32>(iVar4 + 700) = 0x1130;
  M<UInt32>(iVar4 + 0x2b8) = uVar5;
  uVar5 = M<UInt32>(param_1 + 0xcc);
  M<UInt32>(iVar4 + 0x2c4) = 0x1140;
  M<UInt32>(iVar4 + 0x2c0) = uVar5;
  uVar5 = M<UInt32>(param_1 + 0xd0);
  M<UInt32>(iVar4 + 0x2cc) = 0x10f4;
  M<UInt32>(iVar4 + 0x2d0) = 0xaaaa;
  M<UInt32>(iVar4 + 0x2d4) = 0x1383;
  M<UInt32>(iVar4 + 0x2c8) = uVar5;
  uVar5 = M<UInt32>(param_1 + 0xd8);
  M<UInt32>(iVar4 + 0x2dc) = 0x1386;
  M<UInt32>(iVar4 + 0x2d8) = uVar5;
  uVar5 = M<UInt32>(param_1 + 0xdc);
  M<UInt8 *>(iVar4 + 0x2e4) = (UInt8 *)0x110f8;   /* PM4 header word literal (Ghidra labels it as a data address) */
  M<UInt32>(iVar4 + 0x2e0) = uVar5;
  M<UInt32>(iVar4 + 0x2e8) = M<UInt32>(param_1 + 0xe0);
  uVar5 = M<UInt32>(param_1 + 0xe4);
  M<UInt32>(iVar4 + 0x2f0) = 0x1087;
  M<UInt32>(iVar4 + 0x2ec) = uVar5;
  uVar5 = M<UInt32>(param_1 + 0xe8);
  M<UInt32>(iVar4 + 0x2f8) = 0x31080;
  M<UInt32>(iVar4 + 0x2f4) = uVar5;
  M<UInt32>(iVar4 + 0x2fc) = M<UInt32>(param_1 + 0xec);
  M<UInt32>(iVar4 + 0x300) = M<UInt32>(param_1 + 0xf0);
  M<UInt32>(iVar4 + 0x304) = M<UInt32>(param_1 + 0xf4);
  M<UInt32>(iVar4 + 0x308) = M<UInt32>(param_1 + 0xf8);
  M<UInt32>(iVar4 + 0x314) = 0x13c4;
  M<UInt32>(iVar4 + 0x31c) = 0x113c8;
  M<UInt32>(iVar4 + 0x328) = 0x13cd;
  M<UInt32>(iVar4 + 0x330) = 0x13cc;
  M<UInt32>(iVar4 + 0x338) = 0x13ca;
  this->write_r500_3d_blit_state_packet((r500_3d_blit_state_packet_struct *)(prVar11));
  this->write_r500_zdecompress_restore_add_on_packet((r500_zdecompress_restore_add_on_packet_struct *)(iVar4 + 0x314));
  uVar2 = (iVar4 + 0x340) - (SInt32)prVar11 >> 2;
  if ((uVar2 & 1) != 0) {
    M<UInt32>(iVar4 + 0x340) = 0x80000000;
    uVar2 = (iVar4 + 0x344) - (SInt32)prVar11 >> 2;
  }
  M<UInt32>(M<SInt32>(self + uVar1 * 0x18 + 0x120) + 0x14) = uVar2;
  if (M<SInt32>(self + uVar1 * 0x18 + 0x110) == 0) {
    ((IOATIR500GLContext *)((UInt8 *)self))->map_transfer_to_GART((VendorTransferBuffer *)((UInt8 *)(self + uVar1 * 0x18 + 0x10c)));
  }
  M<SInt32>(M<SInt32>(self + 200) + 0x704) =
       M<SInt32>(M<SInt32>(self + uVar1 * 0x18 + 0x120) + 0x14) * 4 +
       M<SInt32>(M<SInt32>(self + 200) + 0x704);
  uVar5 = ((ATIRadeonX1000 *)(M<UInt8 *>(self + 200)))->submit_buffer((UInt32 *)(M<SInt32>(self + uVar1 * 0x18 + 0x120) + 0x20),
                     M<SInt32>(self + uVar1 * 0x18 + 0x110) + 0x20,
                     M<UInt32>(M<SInt32>(self + uVar1 * 0x18 + 0x120) + 0x14));
  M<UInt32>(self + uVar1 * 0x18 + 0x11c) = uVar5;
  M<UInt32>(self + 0x7c) = uVar5;
  return;
}
