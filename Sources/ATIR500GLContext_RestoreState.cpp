/*
 * ATIR500GLContext_RestoreState.cpp
 *
 * restore_state_destroyed_by_pageoff - THE CAPSTONE FUNCTION of this
 * entire reconstruction project. CONFIRMED, fully transcribed from a
 * complete real decompile (real kext offset 0x2af10) - not summarized,
 * not reconstructed from notes, a genuine byte-offset-for-byte-offset
 * transcription of every real register-tracking-state field this
 * function serializes back out as real PM4-header-shaped writes into a
 * per-instance ring-buffer-slot-relative packet buffer.
 *
 * This transcription preserves the real decompile's own literal byte
 * offsets into both `register_tracking_state` (the source) and the
 * destination packet buffer, rather than translating through named
 * struct members - the real field-to-register mapping here is dense
 * enough, and important enough to get exactly right, that a literal,
 * checkable transcription beats a "clean" abstraction that might
 * silently transpose two adjacent fields. Cross-referencing these exact
 * offsets against Headers/ATIRadeonX1000Types.h's register_tracking_state
 * comments (which were derived from an earlier, less precise summary) is
 * flagged as a real, concrete follow-up in GAPS.md - several field
 * offsets here refine or supersede that earlier summary.
 *
 * Real, notable re-confirmations from this exact trace:
 * - `0x1393`/count `10` as a burst header - the SAME literal pair
 *   independently confirmed in write_kernel_context_buffer_regs, the DVD
 *   command language, and the GA plugin's AllocateSurface (now a 4th
 *   independent sighting).
 * - `SC_CLIP_RULE = 0xaaaa` - a 7th independent confirmation.
 * - Real evidence that not every embedded "(index, value)" pair is real
 *   MMIO: index `0x1383` (byte `0x4e0c`) and `0x1386` (byte `0x4e18`) both
 *   reappear here exactly as ATIRadeonX1000Registers.h already documents
 *   (RB3D_COLOR_CHANNEL_MASK/RB3D_ROPCNTL, real aliased register indices).
 *
 * HONEST CAVEAT: this is ~120 real (index, value) pairs transcribed by
 * hand from a linear decompile where the real source reads its local
 * `uVar5` variable one statement ahead of where it's consumed (a real
 * compiler-scheduling artifact, not this project's choice) - a genuine
 * transposition risk. One transposition (destination offsets 0x8c/0x310)
 * was caught and fixed during this same pass; others may remain. Anyone
 * relying on a *specific* register value here for a real hardware test
 * should re-check that one pair against the raw decompile
 * (kext offset 0x2af10) before trusting it, rather than assuming the
 * whole block is error-free just because most of it is.
 */

#include "../Headers/ATIR500GLContext.h"
#include "../Headers/ATIRadeonX1000.h"

/*
 * track_regs_written_by_pm4 / tracked_register_set - CONFIRMED real
 * names (the mangled decompile signature names both), called twice at
 * the top of restore_state_destroyed_by_pageoff on two real (start, end)
 * pointer pairs read from register_tracking_state itself (+0x134/+0x138
 * and +0x13c/+0x140) - real role UNKNOWN beyond "track a range of
 * registers written via PM4," not independently decompiled this pass.
 */
struct tracked_register_set;
extern "C" void track_regs_written_by_pm4(tracked_register_set *state, UInt32 *rangeStart, UInt32 *rangeEnd);

void ATIR500GLContext::restore_state_destroyed_by_pageoff(register_tracking_state *param1) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *p1 = reinterpret_cast<UInt8 *>(param1);
    UInt8 *accel = reinterpret_cast<UInt8 *>(accelerator);

    *reinterpret_cast<UInt32 *>(accel + 0xb90) = 0;

    track_regs_written_by_pm4(reinterpret_cast<tracked_register_set *>(param1),
                               *reinterpret_cast<UInt32 **>(p1 + 0x134),
                               *reinterpret_cast<UInt32 **>(p1 + 0x138));
    *reinterpret_cast<UInt32 *>(p1 + 0x134) = *reinterpret_cast<UInt32 *>(p1 + 0x138);
    track_regs_written_by_pm4(reinterpret_cast<tracked_register_set *>(param1),
                               *reinterpret_cast<UInt32 **>(p1 + 0x13c),
                               *reinterpret_cast<UInt32 **>(p1 + 0x140));
    *reinterpret_cast<UInt32 *>(p1 + 0x13c) = *reinterpret_cast<UInt32 *>(p1 + 0x140);

    /* real vtable call, offset 0x5a4 - UNKNOWN real virtual method name,
     * same unresolved slot as opcode 0x2f's trailing call
     * (Sources/ATIR500GLContext_ProcessCommandBuffer.cpp) */
    // (**(code**)(*(int*)this + 0x5a4))(this);

    /* real per-context ring-buffer-slot bookkeeping - advances a 4-bit
     * rotating slot index (this+0x28c, mod 16) and accumulates a real
     * completion-stamp delta via a vtable call at accel+0x54c (the same
     * offset already confirmed elsewhere as a fence/stamp-accumulator
     * call). */
    UInt32 slot = (*reinterpret_cast<UInt32 *>(self + 0x28c) + 1) & 0xf;
    *reinterpret_cast<UInt32 *>(self + 0x28c) = slot;
    UInt8 *slotRecord = self + slot * 0x18;
    UInt32 accelAccum = *reinterpret_cast<UInt32 *>(accel + 0x1e0);
    typedef UInt32 (*VTableCall0x54c)(void *, UInt32);
    UInt32 delta = (reinterpret_cast<VTableCall0x54c>(*reinterpret_cast<UInt32 **>(accel))[0x54c / 4])(
        accel, *reinterpret_cast<UInt32 *>(slotRecord + 0x11c));
    *reinterpret_cast<UInt32 *>(accel + 0x1e0) = accelAccum + delta;

    /* real 8-dword header block copy from this+0x108 into the new slot's
     * own header area (this+slot*0x18+0x120) */
    UInt32 *srcHeader = reinterpret_cast<UInt32 *>(*reinterpret_cast<UInt32 *>(self + 0x108));
    UInt32 *dstHeader = reinterpret_cast<UInt32 *>(*reinterpret_cast<UInt32 *>(slotRecord + 0x120));
    for (int i = 0; i < 8; ++i) dstHeader[i] = srcHeader[i];

    UInt8 *pkt = reinterpret_cast<UInt8 *>(dstHeader) + 0x20; /* prVar11 in the real decompile */
    auto W = [&](int offset, UInt32 value) {
        *reinterpret_cast<UInt32 *>(pkt - 0x20 + offset) = value;
    };
    auto Src = [&](int offset) -> UInt32 { return *reinterpret_cast<UInt32 *>(p1 + offset); };

    /* ---- The real, dense register-tracking-state serialization ----
     * Left-hand side is the destination packet offset (relative to
     * `dstHeader`, matching the real decompile's `iVar4 + N` exactly);
     * right-hand side is either a real literal header/count constant or
     * a direct read from register_tracking_state at the exact real
     * offset the decompile uses. */
    W(0x20, 0x1393); W(0x24, 10); W(0x28, 0x13c6); W(0x2c, 3);
    W(0x30, 0x5c8);  W(0x34, 0x8000); W(0x38, 0x10ea);
    W(0x3c, Src(0x00)); W(0x40, 0x10fa);
    W(0x44, Src(0x04)); W(0x48, 0xc0001000);
    W(0x50, 0x11004); W(0x54, Src(0x0c));
    W(0x58, Src(0x10)); W(0x5c, 0x1008);
    W(0x60, Src(0x14)); W(0x64, 0x10e9);
    W(0x68, Src(0x18)); W(0x6c, 0x13c7);
    W(0x70, Src(0x1c)); W(0x74, 0x13c1);
    W(0x78, Src(0x20)); W(0x7c, 0x850);
    W(0x80, Src(0x24)); W(0x84, 0x887);
    W(0x30c, 0x82c); W(0x88, Src(0x28));
    W(0x8c, 0x10ae); W(0x310, Src(0x2c));
    W(0x90, Src(0x30)); W(0x94, 0x1394);
    W(0x98, Src(0x34)); W(0x9c, 0x1380);
    W(0xa0, 0); W(0xa4, 0x1002);
    W(0xa8, Src(0x3c)); W(0xac, 0x824);
    W(0xb0, Src(0x40)); W(0xb4, 0x825);
    W(0xb8, Src(0x44)); W(0xbc, 0x82d);
    W(0xc0, Src(0x48)); W(0xc4, 0x854);
    W(200, Src(0x4c)); W(0xcc, 0x878);
    W(0xd0, Src(0x50)); W(0xd4, 0x13c0);
    W(0xd8, Src(0x54)); W(0xdc, 0x12f0);
    W(0xe0, Src(0x58)); W(0xe4, 0x12f5);
    W(0xe8, Src(0x5c)); W(0xec, 0x10a2);
    W(0xf0, Src(0x60)); W(0xf4, 0x1381);
    W(0xf8, Src(0x64)); W(0xfc, 0x109e);
    W(0x100, Src(0x68)); W(0x104, 0x1096);
    W(0x108, Src(0x6c)); W(0x10c, 0x1041);
    W(0x110, Src(0x70)); W(0x114, 0x1046);
    W(0x118, Src(0x74)); W(0x11c, 0x1094); W(0x120, 0); W(0x124, 0x1095);
    W(0x128, Src(0x104)); W(300, 0x1095);
    W(0x130, Src(0x108)); W(0x134, 0x1095);
    W(0x138, Src(0x10c)); W(0x13c, 0x1095);
    W(0x140, Src(0x110)); W(0x144, 0x1095);
    W(0x148, Src(0x114)); W(0x14c, 0x1095);
    W(0x150, Src(0x118)); W(0x154, 0x1095);
    W(0x158, Src(0x11c)); W(0x15c, 0x1095);
    W(0x160, Src(0x120)); W(0x164, 0x1095);
    W(0x168, Src(0x124)); W(0x16c, 0x1095);
    W(0x170, Src(0x128)); W(0x174, 0x1095);
    W(0x178, Src(300)); W(0x17c, 0x1095);
    W(0x180, Src(0x130)); W(0x184, 0xc0221000); W(0x214, 0x1180);
    W(0x218, Src(0x88)); W(0x21c, 0x1189);
    W(0x220, Src(0x8c)); W(0x224, 0x1181);
    W(0x228, Src(0x90)); W(0x22c, 0x118d);
    W(0x230, Src(0x94)); W(0x234, 0x118e);
    W(0x238, Src(0x98)); W(0x23c, 0x118c);
    W(0x240, Src(0x9c)); W(0x244, 0x11a9);
    W(0x248, Src(0x78)); W(0x24c, 0x11aa);
    W(0x250, Src(0x7c)); W(0x254, 0x11ab);
    W(600, Src(0x80)); W(0x25c, 0x11ac);
    W(0x260, Src(0x84)); W(0x264, 0x10c0);
    W(0x268, Src(0xa0)); W(0x26c, 0x10c1);
    W(0x270, Src(0xa4)); W(0x274, 0x10c8);
    W(0x278, Src(0xa8)); W(0x27c, 0x101d);
    W(0x280, Src(0xac)); W(0x284, 0x138a);
    W(0x288, 0); W(0x28c, 0x138e);
    W(0x290, 0); W(0x294, 0x1040);
    W(0x298, 0); W(0x29c, 0x1150);
    W(0x2a0, 0); W(0x2a4, 0x1100);
    W(0x2a8, Src(0xc0)); W(0x2ac, 0x1110);
    W(0x2b0, Src(0xc4)); W(0x2b4, 0x1120);
    W(0x2b8, Src(200)); W(700, 0x1130);
    W(0x2c0, Src(0xcc)); W(0x2c4, 0x1140);
    W(0x2c8, Src(0xd0)); W(0x2cc, 0x10f4);
    W(0x2d0, SC_CLIP_RULE_VALUE_0xAAAA); /* CONFIRMED literal, 7th independent sighting across this project */
    W(0x2d4, 0x1383); /* RB3D_COLOR_CHANNEL_MASK-aliased index, see ATIRadeonX1000Registers.h */
    W(0x2d8, Src(0xd8)); W(0x2dc, 0x1386); /* RB3D_ROPCNTL-aliased index */
    W(0x2e0, Src(0xdc));
    /* real: `*(undefined**)(iVar4+0x2e4) = &DAT_000110f8;` - a real
     * literal pointer constant this project never independently named. */
    W(0x2e8, Src(0xe0));
    W(0x2ec, Src(0xe4)); W(0x2f0, 0x1087);
    W(0x2f4, Src(0xe8)); W(0x2f8, 0x31080);
    W(0x2fc, Src(0xec));
    W(0x300, Src(0xf0));
    W(0x304, Src(0xf4));
    W(0x308, Src(0xf8));
    W(0x314, 0x13c4);
    W(0x31c, 0x113c8);
    W(0x328, 0x13cd);
    W(0x330, 0x13cc);
    W(0x338, 0x13ca);

    write_r500_3d_blit_state_packet(reinterpret_cast<r500_3d_blit_state_packet_struct *>(pkt));
    write_r500_zdecompress_restore_add_on_packet(
        reinterpret_cast<r500_zdecompress_restore_add_on_packet_struct *>(reinterpret_cast<UInt8 *>(dstHeader) + 0x314));

    UInt32 dwordCount = (reinterpret_cast<UInt8 *>(dstHeader) + 0x340 - pkt) >> 2;
    if ((dwordCount & 1) != 0) {
        *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(dstHeader) + 0x340) = 0x80000000; /* real Type-2 filler pad for odd dword count */
        dwordCount = (reinterpret_cast<UInt8 *>(dstHeader) + 0x344 - pkt) >> 2;
    }
    *reinterpret_cast<UInt32 *>(*reinterpret_cast<UInt32 *>(slotRecord + 0x120) + 0x14) = dwordCount;

    if (*reinterpret_cast<UInt32 *>(slotRecord + 0x110) == 0) {
        map_transfer_to_GART(reinterpret_cast<VendorTransferBuffer *>(slotRecord + 0x10c));
    }

    *reinterpret_cast<UInt32 *>(accel + 0x704) =
        *reinterpret_cast<UInt32 *>(*reinterpret_cast<UInt32 *>(slotRecord + 0x120) + 0x14) * 4 +
        *reinterpret_cast<UInt32 *>(accel + 0x704);

    UInt32 newTag = accelerator->submit_buffer(
        reinterpret_cast<UInt32 *>(*reinterpret_cast<UInt32 *>(slotRecord + 0x120) + 0x20),
        *reinterpret_cast<UInt32 *>(slotRecord + 0x110) + 0x20,
        *reinterpret_cast<UInt32 *>(*reinterpret_cast<UInt32 *>(slotRecord + 0x120) + 0x14));
    *reinterpret_cast<UInt32 *>(slotRecord + 0x11c) = newTag;
    *reinterpret_cast<UInt32 *>(self + 0x7c) = newTag;
}
