/* NOTE 2026-09-19: 1 function body formerly in this file has been replaced by mechanical ports from the shipped kext's decompile (Sources/*_Port.cpp; marked
   "(re-ported mechanically: ...)" below). The analysis prose in this file describes the earlier hand-written bodies and is kept as history; see README.md,
   "How the code was produced". */
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
 * RESOLVED, issue #12 item 6 - systematic spot-check complete. Every one
 * of the ~120 (index, value) pairs below was individually re-verified,
 * pair by pair, against a fresh Ghidra headless re-decompile of this exact
 * function (kext offset 0x2af10) - not sampled, all of them. One
 * transposition (destination offsets 0x8c/0x310) was already caught and
 * fixed in an earlier pass and is CONFIRMED still correct (not re-broken).
 * No further transposition errors were found in the (index, value) table
 * itself - all ~120 pairs check out exactly against the raw decompile.
 *
 * One real, separate, CONFIRMED bug WAS found and fixed this pass, outside
 * the (index, value) table: the ring-buffer-slot bookkeeping's completion-
 * stamp accumulator was reading/writing `accel + 0x1e0` when the real
 * value is `accel + 0x780` (the raw decompile indexes it as `piVar9[0x1e0]`
 * on a real `int *`-typed local - a DWORD index, `0x1e0 * 4 = 0x780` bytes,
 * not a raw byte offset as this project's earlier transcription treated
 * it). Independently cross-confirmed against
 * `ATIR500GLContext_TextureLoad.cpp`'s `compact_current_textures`, which
 * calls the exact same real `ATIRadeonX1000::waitForTimeStamp`
 * (RESOLVED, issue #19) against `accel+0x780` - that file's own header comment already named this
 * function/field pairing, meaning the two files disagreed with each other
 * before this fix. See that accumulator's own comment below for the full
 * writeup. The rest of the function's scaffolding (the header-block copy,
 * the dword-count/pad computation, the `map_transfer_to_GART`/
 * `submit_buffer` tail) was also individually re-checked against the raw
 * decompile this pass and found to already match exactly.
 *
 * Original honest caveat, now addressed by the above: this is ~120 real
 * (index, value) pairs transcribed by hand from a linear decompile where
 * the real source reads its local `uVar5` variable one statement ahead of
 * where it's consumed (a real compiler-scheduling artifact, not this
 * project's choice) - a genuine transposition risk in principle, now
 * checked in full rather than spot-sampled.
 */

#include "../Headers/ATIR500GLContext.h"
#include "../Headers/ATIRadeonX1000.h"

/*
 * track_regs_written_by_pm4 / tracked_register_set - CONFIRMED real
 * names (the mangled decompile signature names both), called twice at
 * the top of restore_state_destroyed_by_pageoff on two real (start, end)
 * pointer pairs read from register_tracking_state itself (+0x134/+0x138
 * and +0x13c/+0x140). Own body RESOLVED, issue #39 - see
 * Sources/ATIRadeonX1000_TrackRegsWrittenByPM4.cpp (real addr 0x1b180).
 * LINKAGE FIXED there too: the real symbol is mangled
 * (`__Z25track_regs_written_by_pm4P20tracked_register_setPmS1_`), pinned
 * via `asm(...)` per this project's established convention.
 */
struct tracked_register_set;
extern "C" void track_regs_written_by_pm4(tracked_register_set *state, UInt32 *rangeStart, UInt32 *rangeEnd) asm("__Z25track_regs_written_by_pm4P20tracked_register_setPmS1_");

/* (re-ported mechanically: see ATIR500GLContext_restore_state_destroyed_by_pageoff_Port.cpp) */

