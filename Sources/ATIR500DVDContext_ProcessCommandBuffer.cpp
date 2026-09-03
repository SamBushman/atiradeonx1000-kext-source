/*
 * ATIR500DVDContext_ProcessCommandBuffer.cpp
 *
 * PARTIALLY RESOLVED (issue #7): the DVD context's own embedded
 * command-buffer opcode language. Real dispatch mechanism confirmed
 * (top-byte opcode over a `this+0xa4+0x1c`-based record stream,
 * self-consuming low-24-bit distance fields), and `process_command_buffer`
 * itself is NOW ASSEMBLED AND WIRED (this pass) - previously the
 * transcribed handlers existed only as free functions with no real
 * dispatcher calling them.
 *
 * METHODOLOGY CHANGE this pass, directly acting on the "future pass
 * should cross-check routing against real compiled branch instructions"
 * note this file previously carried: every opcode boundary below was
 * verified by DIRECT PPC BRANCH-INSTRUCTION TRACING of the raw
 * disassembly (`lis`/`cmpw`/`beq`/`bne`/`b` sequences from a fresh
 * headless disassembly dump), not decompiled-C brace nesting - this
 * exact function had already produced two real mistakes from the
 * brace-nesting approach in an earlier pass (see below), and a third,
 * new one was caught mid-pass this time before being trusted (an
 * ambiguous C-decompile region around opcodes 0x14/0x15 that direct
 * disassembly resolved cleanly - real target addresses now on record
 * in the dispatcher's own comments for every opcode, transcribed or
 * not, so a future pass never has to re-derive them).
 *
 * Real opcode groups now transcribed (48 real opcodes with genuine
 * handlers): texture bind (0x19-0x1d, 0x1e-0x25, 0x26-0x2a); texture
 * unbind (0x2b/0x2c, 0x2d, 0x2e-0x30, 0x31, 0x32-0x34, 0x35, 0x36-0x3c);
 * the opcode 0x2 return-code setter; the opcode 0x4 explicit-flush; the
 * opcode 0x5/0x6 texture-sampler-state pair; opcodes 0xa/0xb/0xd's own
 * per-mip YUV/tiling setup; opcode 0x13's texture-fetch setup (found
 * this pass - previously not even catalogued as a gap, since an earlier
 * pass's opcode inventory skipped it entirely); opcodes 0x3e/0x3f/0x42/
 * 0x43+0x44 (a single real shared handler - see below)/0x46/0x47; and,
 * in a later continuation of this same pass, opcodes 0x14/0x16 (dense
 * real multi-plane YUV/tiling bursts, 3 and 5 real output values
 * respectively, across a 6-way and 12-way branch), 0x18 (a real
 * two-transfer-buffer fetch setup), 0x15 (the one opcode in this whole
 * cluster that does NOT index a per-`record[N]` mip array - it reads a
 * real FIXED sub-record embedded in `boundSurface` at `+0x7b0`,
 * transcribed via direct PPC instruction decoding since no matching
 * decompiled-C region for it was found in the raw decompile output this
 * project has on hand), and - in a STILL LATER continuation - opcode
 * 0x3d, the densest opcode transcribed this whole pass (a real
 * self-consuming record producing TWO separate 5-plane PM4 bursts
 * across a 4-way branch with 9 tracked output values; see that
 * function's own header comment for a real, verified 32-bit-overflow
 * pointer-arithmetic subtlety this project caught and worked around
 * rather than reproducing via undefined behavior). Plus four more
 * (0x07/0x08/0x09/0x0c) confirmed to be real HARD-ABORT paths (the
 * walk's whole running position resets to 0, not a plain single-opcode
 * skip - see the dispatcher's own
 * `abortToZero` handling) with no other real handler.
 *
 * Two more real logic bugs caught and fixed in THIS PASS'S OWN draft
 * before committing (not stale earlier-pass bugs like the ones below):
 * an early draft of `handle_opcode_16` used `rowSize` instead of the
 * real `blendedBase` in two of its twelve branches' `outE` formula -
 * caught by re-checking every branch individually against the raw
 * decompile rather than trusting the first pass through such a dense
 * function; and an early draft of `handle_opcode_3d` computed its first
 * PM4 burst's destination pointer as `record + record[5]` using C++
 * pointer arithmetic directly on the record's own already-self-consumed
 * (zeroed to `0x80000000`) `record[5]` field - real, verified (via
 * direct disassembly of the exact `lwz`/`rlwinm`/`add` sequence) to
 * numerically equal `record` itself once real 32-bit address-arithmetic
 * overflow is accounted for, but NOT safe to express that way in C++,
 * since pointer arithmetic that overflows the array's bounds is
 * undefined behavior rather than the well-defined modular arithmetic
 * the real machine code performs - rewritten to assign `record` to that
 * pointer directly instead, with the real derivation documented in that
 * function's own header comment rather than silently "simplified away."
 *
 * THREE REAL CORRECTIONS to this project's own earlier opcode
 * accounting, all found via the disassembly tracing above:
 * 1. Opcode 0x2d is really part of the UNBIND family (target
 *    `LAB_00037880`), NOT bind (`LAB_00037620`) as an earlier pass's
 *    prose wrongly listed - never actually wired into committed code
 *    before now (no dispatcher existed), so this was caught before
 *    becoming a live bug, not fixed after the fact.
 * 2. Opcode 0x35 is ALSO a real unbind opcode - previously not
 *    catalogued in either the bind or unbind list at all.
 * 3. Opcode 0x31 was already correctly known to be a real unbind opcode
 *    (listed in an earlier pass's "remaining opcodes" note), but had
 *    never actually been wired to `handle_texture_unbind` in any
 *    dispatcher - fixed here, simply by including it (no new decompile
 *    work needed, it reuses the already-transcribed handler).
 *
 * TWO REAL LOGIC BUGS caught and fixed this pass in the ALREADY-
 * COMMITTED handlers, found while working out the dispatcher's own
 * shared state:
 * 1. `handle_texture_bind`'s bounds/null-lookup failure real target is
 *    the HARD-ABORT path (`LAB_00039030`), not a plain single-opcode
 *    skip as originally modeled (a bare `return;`) - now returns `bool`
 *    like `handle_opcode_0a`/`0b`, matching the real dispatcher
 *    semantics exactly. See that function's own header note.
 * 2. `local_64`/`local_58` (used by opcodes 0xa/0xb respectively, and
 *    now also `local_60`/`local_5c` for opcode 0x46) are real
 *    FUNCTION-SCOPE `process_command_buffer` variables - zero-
 *    initialized ONCE before the dispatch loop starts, not fresh
 *    per-call locals. Their own self-referential update
 *    (`local_X = (new bits) | (local_X & mask)`) means they genuinely
 *    persist, masked, across every real call to their opcode within one
 *    `process_command_buffer` invocation - a command buffer containing
 *    the same opcode more than once would have later occurrences see
 *    bits left behind by earlier ones. An earlier pass modeled each as
 *    a fresh `UInt32 local_X = 0;` local to its own handler function
 *    every call, losing this real persistence - now threaded through as
 *    real shared dispatcher state instead. See handle_opcode_0a's own
 *    header note for the full explanation.
 *
 * Real, notable structural finding: opcodes 0x43 and 0x44 are, per a
 * direct byte-for-byte disassembly comparison, REAL, IDENTICAL setup
 * code (0x44 reaches the exact same real merge point 0x43's own natural
 * fall-through does, via an explicit `goto`) - a genuine driver/
 * compiler artifact, transcribed here as one shared handler,
 * `handle_opcode_43_44`, rather than two separately-derived copies.
 *
 * CORRECTION to this project's own earlier opcode-range accounting:
 * DVD has NO real opcode 0x11 at all (an earlier pass's "remaining
 * opcodes" list wrongly included it, apparently carried over by
 * mistake from the UNRELATED opcode 0x11 this project already
 * resolved on the 2D context - a real, different opcode language).
 *
 * STILL OPEN, real disassembly-verified target addresses on record for
 * a future pass (see the dispatcher's own explicit not-yet-transcribed
 * `case` block for the full list - down to TWO opcodes from the original
 * seven, after this pass's later continuations): opcode 0x12 (~750 real
 * lines, comparable in scale to GL's own single-largest gap, opcode
 * 0x2d - CORRECTED, issue #12 item 4: that GL content was misattributed
 * to "opcode 0x31" when this note was first written; the real GL opcode
 * 0x31 is much smaller and is now fully transcribed - see
 * ATIR500GLContext_ProcessCommandBuffer.cpp's handle_depth_buffer_resolve);
 * and 0x17 (its opening instructions closely mirror opcode 0x16's own
 * real shape - likely a similarly-dense multi-plane burst, not
 * independently confirmed - own body not yet located in the raw
 * decompile). This is a genuinely large remaining undertaking for 0x12
 * specifically, same scope note this file has carried since it was first
 * opened - not
 * a small residual item.
 *
 * Confidence: CONFIRMED for control flow and every field offset/call in
 * every transcribed handler - complete real decompiles, cross-checked
 * against raw disassembly wherever the C decompile's own brace
 * structure was ambiguous (which, this pass found, was more often than
 * this file's earlier passes assumed - see the methodology note above).
 * `FUN_0003911c` (a real refcount-style helper - every call site gates
 * `delete_texture` on it returning exactly 1, "this was the last
 * reference") and `FUN_0003913c` (the same real "ensure GART-mapped"
 * idiom as GL's FUN_0002a864/2D's FUN_000334cc) are called opaquely.
 * `FUN_000390dc` is called with a literal `0xffff0001` first argument -
 * the exact same bit pattern as the real atomic packed-counter update
 * this project independently verified via raw PPC disassembly in GL's
 * own get_texture (issue #5); a striking match, but NOT independently
 * re-verified against DVD's own disassembly this pass, so called
 * opaquely rather than assumed identical. The four new small per-call-
 * site lock/alloc/free helpers this pass's opcode 0x13/0x3e/0x43+0x44
 * transcriptions reuse (`FUN_0003913c`, already known) are likewise
 * opaque, matching this project's established treatment of such helpers.
 */

#include "../Headers/ATIR500DVDContext.h"
#include "../Headers/IOATIR500Shared.h"
#include "../Headers/ATIRadeonX1000.h"
#include "../Headers/ATIRadeonX1000Types.h"

inline UInt32 &U32At(void *base, int offset) { return *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt16 &U16At(void *base, int offset) { return *reinterpret_cast<UInt16 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt8  &U8At(void *base, int offset)  { return *(reinterpret_cast<UInt8 *>(base) + offset); }

extern "C" UInt32 FUN_0003911c(void *refcountFieldAddr);
extern "C" void   FUN_0003913c(void *transferBufferPlus0x2c);
extern "C" void   FUN_000390dc(UInt32 magicConstant, void *counterFieldAddr);

/*
 * handle_texture_bind - RESOLVED (issue #7), fully transcribed. Covers
 * opcodes 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e-0x25, 0x26-0x2a, 0x2d - a real
 * "bind texture unit N" family, N derived directly from the opcode
 * value (`(opcode + 0xe7) mod 0x100`, i.e. `opcode - 0x19`) indexing a
 * per-unit slot array at `this+0x104`.
 *
 * Real behavior: looks up a transfer buffer by index in
 * `sharedAllocator`'s own table (bounds-checked against its `+0x14`
 * count), unbinds whatever texture currently occupies the target unit
 * slot (real refcount-gated `delete_texture`, same shape as
 * handle_texture_unbind below), binds the new one via
 * `add_texture_to_stream`, and - if the transfer buffer's own mip
 * record is flagged dirty - flushes any pending write batch, ensures
 * it's GART-mapped, and splices it into the SAME two real accelerator-
 * level lists (`+0x6d0`/`+0x69c` and, later, `+0x600`/`+0x5dc`) this
 * project already reconstructed for GL and 2D this session (issue #5).
 * Always calls the real `FUN_000390dc(0xffff0001, ...)` counter update
 * on the bound texture's mip record (see file header note) and writes
 * a plain sentinel pair before falling through to the shared generic
 * advance.
 *
 * `opcode` MUST be the already-masked top-byte value (real `uVar17`,
 * e.g. exactly `0x19000000`), not the raw record dword with its real
 * distance bits still in the low 24 - for THIS handler's `>> 0x18`
 * shift the two are mathematically equivalent (the shift discards all
 * 24 low bits regardless), but callers must still pass the masked
 * value for consistency with handle_texture_unbind below, where the
 * distinction is NOT equivalent.
 *
 * CORRECTED, issue #7 continuation: returns `bool` now - real
 * disassembly-verified tracing (not brace-inferred) shows the real
 * `LAB_00037620` block's own bounds/null-lookup failure goes straight to
 * the real HARD-ABORT path (`LAB_00039030` - both the running record
 * count AND the whole walk's distance get reset to 0), NOT a plain
 * single-opcode skip as this project's earlier pass wrongly modeled it
 * (a bare `return;`, treated by the (not-yet-existent) caller as "use
 * the natural distance"). Caller must reset both its own record-count
 * accumulator and distance to 0 when this returns `false`, matching
 * handle_opcode_0a/0b's own established `bool`-return convention above.
 */
static bool handle_texture_bind(ATIR500DVDContext *ctx, UInt32 opcode, UInt32 *record,
                                 UInt32 &recordCount, UInt32 &byteOffset) {
    UInt8 *self = reinterpret_cast<UInt8 *>(ctx);
    UInt8 *accel = reinterpret_cast<UInt8 *>(ctx->accelerator);
    UInt8 *shared = reinterpret_cast<UInt8 *>(ctx->sharedAllocator);

    UInt32 idx = record[1];
    if (idx >= U32At(shared, 0x14)) return false; /* real: falls to the shared HARD-ABORT path, not a plain skip */
    UInt8 *transferBuf = *reinterpret_cast<UInt8 **>(reinterpret_cast<UInt8 *>(U32At(shared, 0x10)) + idx * 4);
    if (transferBuf == nullptr) return false;

    UInt32 unitSlot = ((opcode + 0xe7000000u) >> 0x18) * 4;
    UInt8 *slotAddr = self + unitSlot + 0x104;
    UInt8 *oldTex = *reinterpret_cast<UInt8 **>(slotAddr);
    if (oldTex != nullptr) {
        ctx->remove_texture_from_stream(reinterpret_cast<VendorTextureBuffer *>(oldTex));
        UInt32 refCheck = FUN_0003911c(reinterpret_cast<UInt8 *>(U32At(oldTex, 0x14)) + 0x10);
        if (refCheck == 1) {
            ctx->sharedAllocator->delete_texture(reinterpret_cast<VendorTextureBuffer *>(oldTex));
        }
        *reinterpret_cast<UInt32 *>(slotAddr) = 0;
    }

    ctx->add_texture_to_stream(reinterpret_cast<VendorTextureBuffer *>(transferBuf));

    if (U8At(reinterpret_cast<void *>(U32At(transferBuf, 0x14)), 0x14) != 0) {
        if (recordCount != 0) {
            UInt32 savedCount = recordCount; /* real: uVar10 = local_6c, saved BEFORE reset - the real submit_buffer call below uses this saved value, not the (by-then-zeroed) live counter */
            UInt32 flushDwords = recordCount * 4;
            recordCount = 0;
            UInt32 bufBase = (byteOffset & 0xfffffffcu) + U32At(self, 0xa4);
            U32At(accel, 0x708) += flushDwords;
            UInt32 bufEnd = byteOffset + U32At(self, 0x94);
            byteOffset += flushDwords;
            U32At(self, 0xa0) = ctx->accelerator->submit_buffer(
                reinterpret_cast<UInt32 *>(bufBase + 0x20), bufEnd + 0x20, savedCount);
        }
        if (U32At(transferBuf, 4) != 0 ||
            (ctx->map_transfer_to_GART(reinterpret_cast<VendorTransferBuffer *>(transferBuf)),
             U32At(transferBuf, 4) != 0)) {
            FUN_0003913c(transferBuf + 0x2c);
            void *prevNode = reinterpret_cast<void *>(U32At(transferBuf, 0x34));
            void *nextNode = reinterpret_cast<void *>(U32At(transferBuf, 0x38));
            U32At(prevNode, 0x38) = reinterpret_cast<UInt32>(nextNode);
            U32At(nextNode, 0x34) = reinterpret_cast<UInt32>(prevNode);
            U32At(transferBuf, 0x34) = U32At(accel, 0x6d0);
            U32At(transferBuf, 0x38) = reinterpret_cast<UInt32>(accel + 0x69c);
            U32At(accel, 0x6d0) = reinterpret_cast<UInt32>(transferBuf);
            void *newPrev = reinterpret_cast<void *>(U32At(transferBuf, 0x34));
            U32At(newPrev, 0x38) = reinterpret_cast<UInt32>(transferBuf);
        }
        U8At(reinterpret_cast<void *>(U32At(transferBuf, 0x14)), 0x14) = 0;
        if (U32At(self, 0x94) == 0) {
            ctx->map_transfer_to_GART(reinterpret_cast<VendorTransferBuffer *>(self + 0x90));
        }
    }

    FUN_000390dc(0xffff0001u, reinterpret_cast<UInt8 *>(U32At(transferBuf, 0x14)) + 0x10);

    if (U32At(transferBuf, 0x48) != 0) {
        void *prevNode = reinterpret_cast<void *>(U32At(transferBuf, 0x24));
        void *nextNode = reinterpret_cast<void *>(U32At(transferBuf, 0x28));
        U32At(prevNode, 0x28) = reinterpret_cast<UInt32>(nextNode);
        U32At(nextNode, 0x24) = reinterpret_cast<UInt32>(prevNode);
        U32At(transferBuf, 0x24) = U32At(accel, 0x600);
        U32At(transferBuf, 0x28) = reinterpret_cast<UInt32>(accel + 0x5dc);
        U32At(accel, 0x600) = reinterpret_cast<UInt32>(transferBuf);
        void *newPrev = reinterpret_cast<void *>(U32At(transferBuf, 0x24));
        U32At(newPrev, 0x28) = reinterpret_cast<UInt32>(transferBuf);
    }

    *record = 0x80000000u;
    record[1] = 0x80000000u;
    *reinterpret_cast<UInt32 *>(slotAddr) = reinterpret_cast<UInt32>(transferBuf);
    return true;
}

/*
 * handle_texture_unbind - RESOLVED (issue #7), fully transcribed. Covers
 * opcodes 0x2b, 0x2c, 0x2e-0x30, 0x32-0x34, 0x36-0x3c - the mirror-image
 * "unbind texture unit N" family. Real slot-index formula differs from
 * bind's (`(opcode + 0xd5) >> 22` rather than `>> 24, *4` - the shift by
 * 22 instead of 24 already produces an implicitly-times-4 result).
 * Real behavior is just the same refcount-gated cleanup bind uses when
 * displacing an old texture - no new binding, no reload/GART-map/splice
 * dance.
 *
 * `opcode` MUST be the already-masked top-byte value here (real
 * `uVar17`) - UNLIKE handle_texture_bind's `>> 0x18` shift, this
 * handler's `>> 0x16` shift does NOT fully discard the record's real
 * low-24-bit distance field (bits 22-23 survive into the result), so
 * passing the raw unmasked record dword here would be a real bug
 * whenever a record's real distance value is >= 0x400000.
 */
static void handle_texture_unbind(ATIR500DVDContext *ctx, UInt32 opcode, UInt32 *record) {
    UInt8 *self = reinterpret_cast<UInt8 *>(ctx);
    UInt32 unitSlot = (opcode + 0xd5000000u) >> 0x16;
    UInt8 *slotAddr = self + unitSlot + 0x104;
    UInt8 *oldTex = *reinterpret_cast<UInt8 **>(slotAddr);
    if (oldTex != nullptr) {
        ctx->remove_texture_from_stream(reinterpret_cast<VendorTextureBuffer *>(oldTex));
        UInt32 refCheck = FUN_0003911c(reinterpret_cast<UInt8 *>(U32At(oldTex, 0x14)) + 0x10);
        if (refCheck == 1) {
            ctx->sharedAllocator->delete_texture(reinterpret_cast<VendorTextureBuffer *>(oldTex));
        }
        *reinterpret_cast<UInt32 *>(slotAddr) = 0;
    }
    *record = 0x80000000u;
}

/*
 * handle_opcode_02 - RESOLVED (issue #7), fully transcribed. The
 * function's own overall return value (`local_68` in the raw decompile,
 * returned verbatim at the shared tail) is set to 3 here - a DIFFERENT
 * value from GL's and 2D's own opcode 0x2, which both set their
 * equivalent return value to 1. Real, deliberate per-class difference,
 * not a transcription error. Natural distance applies (no override).
 */
static void handle_opcode_02(UInt32 &result) {
    result = 3;
}

/*
 * handle_texture_sampler_state - RESOLVED (issue #7), fully
 * transcribed. Covers opcodes 0x5 and 0x6 - a real texture-sampler-
 * state PM4 record pair sharing an identical header/tail template with
 * opcode 0xd's own transfer-buffer setup (`0x1393`/10/`0x5c8`/
 * `0x20000`/`0xc0069a00`/`0x52f036da`, and a `0xd0b`/5/`0x5c8`/
 * `0x10000` tail) - confirming that template is a general "sampler
 * state" shape reused across at least two real, distinct source kinds
 * (bound-surface mip records here, transfer buffers for opcode 0xd).
 *
 * Real per-mip lookup: `boundSurface + record[1]*0x78`. `record[2]==0`
 * selects the plain luma-plane base offset; nonzero selects the real
 * YUV 4:2:0 combined-plane formula (`height*pitch*3 >> 1 + base`) - the
 * same real chroma formula this project already found documented in
 * this file's own earlier skeleton-mapping pass. Opcode 0x6
 * additionally adds the plain luma-plane size unconditionally on top
 * (real evidence it targets the position PAST the luma plane, versus
 * opcode 0x5's own plain "plane base" role).
 */
static void handle_texture_sampler_state(ATIR500DVDContext *ctx, UInt32 opcode, UInt32 *record) {
    UInt8 *self = reinterpret_cast<UInt8 *>(ctx);
    UInt8 *surf = reinterpret_cast<UInt8 *>(ctx->boundSurface);
    UInt8 *mip = surf + record[1] * 0x78;
    UInt8 embeddedByte = U8At(record, 0xf);
    SInt32 heightDelta = static_cast<SInt16>(U16At(surf, 0x9a)) - static_cast<SInt16>(U16At(surf, 0x94));

    UInt32 pitch = U16At(mip, 0x570);
    UInt32 base;
    if (opcode == 0x05000000u) {
        base = (record[2] == 0) ? U32At(mip, 0x560)
                                 : static_cast<UInt32>((heightDelta * static_cast<SInt32>(pitch) * 3) >> 1) + U32At(mip, 0x560);
    } else {
        UInt32 lumaSize = static_cast<UInt32>(heightDelta) * pitch;
        base = lumaSize + U32At(mip, 0x560);
        if (record[2] != 0) {
            base += static_cast<UInt32>((heightDelta * static_cast<SInt32>(pitch) * 3) >> 1);
        }
    }

    UInt8 tileFlag = U8At(mip, 0x590);
    UInt32 bigTileBit = (tileFlag < 2) ? 0 : 0x80000000u;

    record[0] = 0x1393;
    record[1] = 10;
    record[2] = 0x5c8;
    record[3] = 0x20000;
    record[4] = 0xc0069a00;
    record[5] = 0x52f036da;
    record[6] = bigTileBit | (base >> 10) | ((pitch & 0x3fc0u) << 16) | ((tileFlag & 1) << 0x1e);
    record[7] = U32At(self, 0x158);
    record[8] = (static_cast<UInt32>(U16At(mip, 0x576)) << 16) | U16At(mip, 0x574);
    record[9] = embeddedByte | (embeddedByte << 24) | (embeddedByte << 16) | (embeddedByte << 8);

    record[10] = 0; /* real: unconditional for both opcodes */
    UInt32 dims;
    if (opcode == 0x05000000u) {
        dims = static_cast<UInt32>(heightDelta) | ((pitch & 0xfffcu) << 14);
    } else {
        dims = ((pitch & 0xfffcu) << 14) | (static_cast<UInt32>(heightDelta) >> 1);
    }

    record[0xb] = dims;
    record[0xc] = 0xd0b;
    record[0xd] = 5;
    record[0xe] = 0x5c8;
    record[0xf] = 0x10000;
}

/*
 * handle_opcode_0d - RESOLVED (issue #7), fully transcribed. A third
 * real real sighting of the shared "sampler state" header template
 * (`0x1393`/10/`0x5c8`/`0x20000`/`0xc0069a00`/`0x52f036da`) and a
 * shared tail (`0xd0b`/5/`0x5c8`/`0x10000`, real label `LAB_00038f80`,
 * ALSO reached from a real, separate branch of the texture-bind family
 * this project already transcribed - not independently re-derived
 * here, just reused as the same literal 4-dword write).
 *
 * Real per-source branch on `record[2]`: zero selects a transfer
 * buffer from the SAME per-unit slot array (`this+0x104`) the bind/
 * unbind families index (ensuring GART-mapped and splicing into the
 * `+0x6d0`/`+0x69c` list exactly as they do); nonzero selects a fixed
 * record embedded in `boundSurface` itself (`boundSurface+0x828`).
 * Real per-context constant fields `this+0x158`/`this+0x15c` (new this
 * pass) feed record[7]/[8] - the same `this+0x158` opcodes 0x5/0x6
 * also reference, now confirmed used identically here.
 */
static void handle_opcode_0d(ATIR500DVDContext *ctx, UInt32 *record) {
    UInt8 *self = reinterpret_cast<UInt8 *>(ctx);
    UInt8 *accel = reinterpret_cast<UInt8 *>(ctx->accelerator);

    UInt32 paramA = record[3];
    UInt32 paramB = record[4];
    UInt32 paramC = record[5];
    bool isTransferBuffer = (record[2] == 0);

    UInt32 sixthDword;
    UInt8 *surfaceRecord = nullptr; /* real: iVar23, only meaningfully set (and used) in the boundSurface branch below - the transfer-buffer branch sets it to 0 in the real decompile but never dereferences it */

    if (isTransferBuffer) {
        UInt8 *transferBuf = *reinterpret_cast<UInt8 **>(self + record[1] * 4 + 0x104);

        if (U32At(transferBuf, 4) != 0 ||
            (ctx->map_transfer_to_GART(reinterpret_cast<VendorTransferBuffer *>(transferBuf)),
             U32At(transferBuf, 4) != 0)) {
            FUN_0003913c(transferBuf + 0x2c);
            void *prevNode = reinterpret_cast<void *>(U32At(transferBuf, 0x34));
            void *nextNode = reinterpret_cast<void *>(U32At(transferBuf, 0x38));
            U32At(prevNode, 0x38) = reinterpret_cast<UInt32>(nextNode);
            U32At(nextNode, 0x34) = reinterpret_cast<UInt32>(prevNode);
            U32At(transferBuf, 0x34) = U32At(accel, 0x6d0);
            U32At(transferBuf, 0x38) = reinterpret_cast<UInt32>(accel + 0x69c);
            U32At(accel, 0x6d0) = reinterpret_cast<UInt32>(transferBuf);
            void *newPrev = reinterpret_cast<void *>(U32At(transferBuf, 0x34));
            U32At(newPrev, 0x38) = reinterpret_cast<UInt32>(transferBuf);
        }

        sixthDword = 0;
        U8At(reinterpret_cast<void *>(U32At(transferBuf, 0x14)), 0x14) = 0;
        if (U32At(transferBuf, 4) != 0) {
            sixthDword = (U32At(transferBuf, 4) + U32At(transferBuf, 0x50) + U32At(accel, 0x8a4)) >> 10;
        }
        sixthDword |= (paramC & 0xff0u) << 0x12;
    } else {
        UInt8 *surf = reinterpret_cast<UInt8 *>(ctx->boundSurface);
        surfaceRecord = surf + 0x828;
        sixthDword = (U32At(surf, 0x830) >> 10) | (static_cast<UInt32>(U16At(surf, 0x840) & 0x3fc0u) << 16);
    }

    record[0] = 0x1393;
    record[1] = 10;
    record[2] = 0x5c8;
    record[3] = 0x20000;
    record[4] = 0xc0069a00;
    record[5] = 0x52f036da;
    record[6] = sixthDword;
    record[7] = U32At(self, 0x158);
    record[8] = U32At(self, 0x15c);
    record[9] = 0;
    record[10] = 0;
    if (isTransferBuffer) {
        record[0xb] = paramB | (paramA << 16);
    } else {
        record[0xb] = U32At(surfaceRecord, 0x1c);
    }

    /* real: shared tail at LAB_00038f80 */
    record[0xc] = 0xd0b;
    record[0xd] = 5;
    record[0xe] = 0x5c8;
    record[0xf] = 0x10000;
}

/*
 * handle_opcode_0a - RESOLVED (issue #7), fully transcribed - the
 * densest real opcode in this cluster and the highest-value target for
 * the H.264 project goal. Real per-mip Y/UV plane pitch+offset setup,
 * gated on a real "engine ready" flag (`accelerator+0x8bc`, word-index
 * 0x22f in the raw decompile) and a real vtable call at
 * `accelerator+0x5ec`. On success, writes a real second, independent
 * sighting of the YUV 4:2:0 combined-plane formula
 * (`height*pitch*3 >> 1`) - this time applied to the Y-plane base
 * itself under one real embedded flag combination, not just the
 * chroma-plane offset opcodes 0x5/0x6/0xd already exercised it for -
 * and a real UV-plane offset computed as luma-plane-size (+ the same
 * chroma term again, under a second independent flag) added to the
 * Y base. Finishes with the same real format-table-driven tiling word
 * (`FormatTableLookup_0x0004d2e0`/`_0x0004d2dc`) GL's own
 * `build_scissor`/`write_kernel_context_buffer_regs` already use.
 *
 * Real, honestly-flagged anomaly: the raw decompile's own `local_64`
 * is read (`... & 0xfe00c001`) before ever being assigned within this
 * function - a genuine read of an uninitialized stack local in the
 * real compiled driver (or a Ghidra stack-slot-reuse artifact this
 * project can't distinguish from static analysis alone). Modeled as 0
 * here rather than silently guessing a "real" preserved-bits value -
 * flagged, not fabricated. The identical pattern recurs in
 * handle_opcode_0b below.
 *
 * Returns `false` on the real failure path (engine-not-ready gate, or
 * the surface-field/height-delta precondition) - the real disassembly
 * (address-verified, not brace-inferred) confirms this maps to the
 * dispatcher's real HARD-ABORT path (both the running record-count AND
 * the whole walk's own position get reset to 0 - LAB_00039030 - not a
 * plain single-opcode skip), for both this failure mode and the
 * engine-not-ready gate above.
 *
 * CORRECTED, issue #7 continuation: `local_64` is a real FUNCTION-SCOPE
 * variable in `process_command_buffer` itself - declared and
 * zero-initialized ONCE, before the dispatch loop even starts, NOT a
 * fresh per-call local. Its own self-referential update
 * (`local_64 = (new bits) | (local_64 & 0xfe00c001)`) means it
 * genuinely PERSISTS, masked, across every call to this opcode within
 * one `process_command_buffer` invocation (a command buffer containing
 * opcode 0xa more than once would have later occurrences see bits left
 * behind by earlier ones). An earlier pass wrongly modeled this as a
 * fresh `UInt32 local_64 = 0;` local to this function every call -
 * caught and fixed this pass by threading it as real shared dispatcher
 * state instead. The "uninitialized read" honesty note below still
 * applies to its FIRST real use ever within a given
 * `process_command_buffer` call (where it genuinely is 0, by the real
 * function-entry initialization) - it was never about this call
 * boundary.
 */
static bool handle_opcode_0a(ATIR500DVDContext *ctx, UInt32 *record, UInt32 &local_64) {
    UInt8 *self = reinterpret_cast<UInt8 *>(ctx);
    UInt8 *accel = reinterpret_cast<UInt8 *>(ctx->accelerator);

    if (U32At(accel, 0x8bc) == 0) return false;

    typedef void (*EngineKickFn)(void *, UInt32);
    (*reinterpret_cast<EngineKickFn *>(*reinterpret_cast<void ***>(accel) + (0x5ec / 4)))(accel, U32At(self, 0x154));

    UInt8 *surf = reinterpret_cast<UInt8 *>(ctx->boundSurface);
    U32At(surf, 0xd90) = record[1];

    SInt32 heightDelta = static_cast<SInt16>(U16At(surf, 0x9a)) - static_cast<SInt16>(U16At(surf, 0x94));
    if (U16At(surf, 0x98) == U16At(surf, 0x96) || heightDelta == 0) return false;

    UInt8 *mip = surf + record[1] * 0x78;

    UInt32 yBase, yPitch;
    if ((record[3] & 2) == 0) {
        yPitch = U16At(mip, 0x570);
        if (record[2] == 0) {
            yBase = U32At(mip, 0x560);
        } else {
            yBase = static_cast<UInt32>((heightDelta * static_cast<SInt32>(yPitch) * 3) >> 1) + U32At(mip, 0x560);
        }
    } else {
        yBase = U32At(surf, 0x998);
        yPitch = U16At(mip, 0x570);
    }

    UInt32 uvBase;
    if ((record[3] & 4) == 0) {
        if (record[2] == 0) {
            uvBase = static_cast<UInt32>(heightDelta) * yPitch + U32At(mip, 0x560);
        } else {
            uvBase = static_cast<UInt32>(heightDelta) * yPitch +
                     static_cast<UInt32>((heightDelta * static_cast<SInt32>(yPitch) * 3) >> 1) + U32At(mip, 0x560);
        }
    } else {
        uvBase = static_cast<UInt32>(heightDelta) * yPitch + U32At(surf, 0x998);
    }

    UInt8 tileByte = U8At(mip, 0x590);
    UInt32 tileBit1 = (tileByte & 1u) << 2;
    UInt32 tileBit2 = (tileByte & 6u) << 2;

    record[0] = 0x1140;
    record[1] = yPitch - 1;
    record[2] = 0x1150;
    record[3] = (yBase & 0xffffffe0u) | tileBit1 | tileBit2;
    record[4] = 0x1141;
    record[5] = (yPitch >> 1) - 1;
    record[6] = 0x1151;
    record[7] = tileBit2 | tileBit1 | (uvBase & 0xffffffe0u);
    record[8] = 0x1393;
    record[9] = 10;
    record[0xa] = 0x138a;
    record[0xb] = U32At(surf, 0x128) & 0xffffffe0u;
    record[0xc] = 0x138e;

    UInt32 formatIdx = static_cast<UInt32>(U8At(surf, 0x15a)) * 0x1c;
    UInt32 div1 = 0;
    if ((U32At(surf, 0x15c) & 0xf00000u) != 0) {
        div1 = U16At(surf, 0x134) / ((U32At(surf, 0x15c) >> 0x14) & 0xfu);
    }
    UInt32 div2 = 0x20u / U16At(surf, 0x136);
    UInt32 divFinal = (div2 <= div1) ? div1 : div2;

    /* real: `local_64` is shared dispatcher state, passed by reference -
     * see header note. Genuinely 0 the first time any opcode-0xa record
     * in this buffer reaches here (real function-entry init), masked-
     * persists across any later ones. */
    local_64 = ((FormatTableLookup_0x0004d2e0(formatIdx) >> 1) & 0x1e00000u) |
               ((FormatTableLookup_0x0004d2dc(formatIdx) & 0xc00u) << 9) |
               (static_cast<UInt32>(U8At(surf, 0x158) & 6u) << 16) |
               (static_cast<UInt32>(U8At(surf, 0x158) & 1u) << 16) |
               (divFinal & 0x3ffeu) | (local_64 & 0xfe00c001u);
    record[0xd] = local_64;

    return true;
}

/*
 * handle_opcode_0b - RESOLVED (issue #7), fully transcribed. A single-
 * plane cousin of opcode 0xa above (no Y/UV split, one base+pitch),
 * with a real per-source branch mirroring opcode 0xd's own transfer-
 * buffer-vs-boundSurface split, and the exact same real format-table
 * tiling-word computation (including the same real shared-dispatcher-
 * state pattern as `local_64` above - `local_58` here, see
 * handle_opcode_0a's own header note for the full correction; the same
 * pattern recurring here independently reinforces that this is a real
 * driver behavior, not a one-off).
 *
 * Real, notable finding: opcode 0xc (numerically adjacent, and
 * originally assumed part of this "0xa/0xb/0xc/0xd cluster" by this
 * project's own earlier skeleton-mapping pass) turns out to have NO
 * real handler at all - a fresh disassembly-level check (address-
 * verified, not brace-inferred) confirms it unconditionally hits the
 * real HARD-ABORT path (LAB_00039030) - CORRECTED from this project's
 * earlier characterization as a "trivial pass-through" (that phrasing
 * was ambiguous and this pass pins down the exact real target, not just
 * "some no-op path").
 */
static void handle_opcode_0b(ATIR500DVDContext *ctx, UInt32 *record, UInt32 &local_58) {
    UInt8 *self = reinterpret_cast<UInt8 *>(ctx);
    UInt8 *accel = reinterpret_cast<UInt8 *>(ctx->accelerator);

    UInt8 *sourceRecord;
    UInt32 shiftedBase;

    if (record[2] == 0) {
        UInt8 *transferBuf = *reinterpret_cast<UInt8 **>(self + record[1] * 4 + 0x104);

        if (U32At(transferBuf, 4) != 0 ||
            (ctx->map_transfer_to_GART(reinterpret_cast<VendorTransferBuffer *>(transferBuf)),
             U32At(transferBuf, 4) != 0)) {
            FUN_0003913c(transferBuf + 0x2c);
            void *prevNode = reinterpret_cast<void *>(U32At(transferBuf, 0x34));
            void *nextNode = reinterpret_cast<void *>(U32At(transferBuf, 0x38));
            U32At(prevNode, 0x38) = reinterpret_cast<UInt32>(nextNode);
            U32At(nextNode, 0x34) = reinterpret_cast<UInt32>(prevNode);
            U32At(transferBuf, 0x34) = U32At(accel, 0x6d0);
            U32At(transferBuf, 0x38) = reinterpret_cast<UInt32>(accel + 0x69c);
            U32At(accel, 0x6d0) = reinterpret_cast<UInt32>(transferBuf);
            void *newPrev = reinterpret_cast<void *>(U32At(transferBuf, 0x34));
            U32At(newPrev, 0x38) = reinterpret_cast<UInt32>(transferBuf);
        }

        U8At(reinterpret_cast<void *>(U32At(transferBuf, 0x14)), 0x14) = 0;
        if (U32At(transferBuf, 4) == 0) {
            sourceRecord = reinterpret_cast<UInt8 *>(ctx->boundSurface);
            shiftedBase = 0;
        } else {
            sourceRecord = reinterpret_cast<UInt8 *>(ctx->boundSurface);
            shiftedBase = (U32At(transferBuf, 4) + U32At(transferBuf, 0x50) + U32At(accel, 0x8a4)) >> 5;
        }
    } else {
        sourceRecord = reinterpret_cast<UInt8 *>(ctx->boundSurface);
        shiftedBase = U32At(sourceRecord, 0x830) >> 5;
    }

    record[0] = 0x1150;
    record[1] = shiftedBase << 5;
    record[2] = 0x1393;
    record[3] = 10;
    record[4] = 0x138a;
    record[5] = U32At(sourceRecord, 0x128) & 0xffffffe0u;
    record[6] = 0x138e;

    UInt32 formatIdx = static_cast<UInt32>(U8At(sourceRecord, 0x15a)) * 0x1c;
    UInt32 div1 = 0;
    if ((U32At(sourceRecord, 0x15c) & 0xf00000u) != 0) {
        div1 = U16At(sourceRecord, 0x134) / ((U32At(sourceRecord, 0x15c) >> 0x14) & 0xfu);
    }
    UInt32 div2 = 0x20u / U16At(sourceRecord, 0x136);
    UInt32 divFinal = (div2 <= div1) ? div1 : div2;

    /* real: `local_58` is shared dispatcher state, passed by reference -
     * see handle_opcode_0a's header note for the full correction. */
    local_58 = ((FormatTableLookup_0x0004d2e0(formatIdx) >> 1) & 0x1e00000u) |
               ((FormatTableLookup_0x0004d2dc(formatIdx) & 0xc00u) << 9) |
               (static_cast<UInt32>(U8At(sourceRecord, 0x158) & 6u) << 16) |
               (static_cast<UInt32>(U8At(sourceRecord, 0x158) & 1u) << 16) |
               (divFinal & 0x3ffeu) | (local_58 & 0xfe00c001u);
    record[7] = local_58;
}

/*
 * handle_opcode_04 - RESOLVED (issue #7), fully transcribed. A real
 * explicit-flush opcode - same real shape as GL's own opcode 0x2b -
 * flushes any pending write batch (the same real save-before-reset
 * pattern as handle_texture_bind's own flush path) and writes a plain
 * sentinel. No real per-opcode payload beyond the flush itself.
 */
/*
 * handle_opcode_13 - RESOLVED (issue #7), fully transcribed. Real target
 * address (0x38884) confirmed via DIRECT PPC BRANCH-INSTRUCTION TRACING
 * of the raw disassembly (`lis r0,0x1300; cmpw ...; beq cr7,0x00038884`),
 * not decompiled-C brace nesting - this exact function is where an
 * earlier pass's brace-nesting-only method produced two real mistakes
 * (see this file's own header note), so this pass verified every
 * opcode's real target address against the raw compiled branch tree
 * before trusting any opcode boundary, per that note's own
 * recommendation. Real per-mip texture-fetch/tiling setup for
 * `boundSurface`, ending with a real pair of "magic bias" integer-to-
 * float conversions (the same general int->float trick this project's
 * GL side already documents as its own `BiasedIntToFloat` helper, though
 * using a DIFFERENT real bias constant here - `4503601774854144.0`
 * (2^52 + 2^31), not the already-named `DOUBLE_0004c3a8` (a plain 2^52) -
 * so declared as its own local literal rather than reusing that extern).
 * Real per-mip YUV height-delta term (`boundSurface's own +0x9a - +0x94`)
 * matches the SAME chroma-plane-adjacent computation already confirmed
 * on opcodes 0x5/0x6/0xa/0xb/0xd. Ends with the real natural
 * distance-based advance (no override) - confirmed via the raw
 * disassembly's own unconditional `b 0x0003903c` (the shared loop tail),
 * immediately followed in memory by opcode 0x18's own real body,
 * confirming there is no gap/hidden opcode between the two.
 */
static void handle_opcode_13(ATIR500DVDContext *ctx, UInt32 *record) {
    UInt8 *surf = reinterpret_cast<UInt8 *>(ctx->boundSurface);
    UInt8 *mip = surf + record[1] * 0x78;

    UInt32 base = U32At(mip, 0x560);
    UInt32 pitch = U16At(mip, 0x570);
    SInt32 heightDelta = static_cast<SInt16>(U16At(surf, 0x9a)) - static_cast<SInt16>(U16At(surf, 0x94));

    record[0] = 0x1087;
    record[1] = ((U16At(mip, 0x576) & 0x3fffu) << 2) | (pitch << 0x11);
    record[2] = 0x1150;
    record[3] = base & 0xffffffe0u;
    record[4] = 0x1393;
    record[5] = 10;
    record[6] = 0x138a;
    record[7] = (base + static_cast<UInt32>((heightDelta * static_cast<SInt32>(pitch) * 3) >> 1)) & 0xffffffe0u;
    record[8] = 0x138e;
    record[9] = ((pitch >> 2) & 0x3ffeu) | ((U8At(mip, 0x590) & 1u) << 0x10) |
                ((U8At(mip, 0x590) & 6u) << 0x10) | ((U8At(mip, 0x591) & 3u) << 0x13) | 0xc00000u;

    /* real "magic bias" int->float conversions - see header note on the
     * bias constant. */
    const double kBias13 = 4503601774854144.0;
    union { double d; struct { UInt32 hi, lo; } parts; } u;

    u.parts.hi = 0x43300000;
    u.parts.lo = (pitch >> 2) ^ 0x80000000u;
    record[0x61] = static_cast<UInt32>(static_cast<float>((u.d - kBias13) * 0.5));

    u.parts.hi = 0x43300000;
    u.parts.lo = (static_cast<UInt32>(U16At(mip, 0x576)) >> 1) ^ 0x80000000u;
    record[0x62] = static_cast<UInt32>(static_cast<float>((u.d - kBias13) * 0.5));
}

/*
 * handle_opcode_3f / handle_opcode_42 - RESOLVED (issue #7), fully
 * transcribed. Real target addresses (0x38330 / 0x3841c respectively)
 * confirmed via direct PPC branch-instruction tracing, same discipline
 * as opcode 0x13 above. Both are real single/paired-plane texture-fetch
 * setups for `boundSurface`'s indexed mip record, reusing the same real
 * YUV 4:2:0 chroma-offset formula already confirmed on opcodes
 * 0x5/0x6/0xa/0xb/0xd/0x13/0x14ish - opcode 0x42 is the real two-register
 * (Y+UV) cousin of 0x3f's single-register form, otherwise structurally
 * identical.
 */
static void handle_opcode_3f(ATIR500DVDContext *ctx, UInt32 *record) {
    UInt8 *surf = reinterpret_cast<UInt8 *>(ctx->boundSurface);
    UInt8 *mip = surf + record[1] * 0x78;

    UInt32 pitch = U16At(mip, 0x570);
    UInt32 base;
    if (record[2] == 0) {
        base = U32At(mip, 0x560);
    } else {
        SInt32 heightDelta = static_cast<SInt16>(U16At(surf, 0x9a)) - static_cast<SInt16>(U16At(surf, 0x94));
        base = static_cast<UInt32>((heightDelta * static_cast<SInt32>(pitch) * 3) >> 1) + U32At(mip, 0x560);
    }

    record[0] = 0x1150;
    record[1] = (base & 0xffffffe0u) | ((U8At(mip, 0x590) & 1u) << 2) | ((U8At(mip, 0x590) & 6u) << 2);
    record[2] = 0x1393;
    record[3] = 10;
    record[4] = 0x138a;
    record[5] = U32At(surf, 0x998) & 0xffffffe0u;
    record[6] = 0x138e;
    record[7] = ((pitch >> 2) & 0x3ffeu) | ((U8At(surf, 0x9c9) & 3u) << 0x13) | 0xc00000u;
}

static void handle_opcode_42(ATIR500DVDContext *ctx, UInt32 *record) {
    UInt8 *surf = reinterpret_cast<UInt8 *>(ctx->boundSurface);
    UInt8 *mip = surf + record[1] * 0x78;
    SInt32 heightDelta = static_cast<SInt16>(U16At(surf, 0x9a)) - static_cast<SInt16>(U16At(surf, 0x94));

    UInt32 pitch = U16At(mip, 0x570);
    UInt32 lumaSize = static_cast<UInt32>(heightDelta) * pitch;
    UInt32 base;
    if (record[2] == 0) {
        base = lumaSize + U32At(mip, 0x560);
    } else {
        base = lumaSize + static_cast<UInt32>((heightDelta * static_cast<SInt32>(pitch) * 3) >> 1) + U32At(mip, 0x560);
    }
    UInt32 basePacked = (base & 0xffffffe0u) | ((U8At(mip, 0x590) & 1u) << 2) | ((U8At(mip, 0x590) & 6u) << 2);

    record[0] = 0x1150;
    record[1] = basePacked;
    record[2] = 0x1151;
    record[3] = basePacked;
    record[4] = 0x1393;
    record[5] = 10;
    record[6] = 0x138a;
    record[7] = (lumaSize + U32At(surf, 0x998)) & 0xffffffe0u;
    record[8] = 0x138e;
    record[9] = ((pitch >> 2) & 0x3ffeu) | ((U8At(surf, 0x9c9) & 3u) << 0x13) | 0xc00000u;
}

/*
 * handle_opcode_3e - RESOLVED (issue #7), fully transcribed. Real
 * target address 0x37ee8, confirmed via direct branch-instruction
 * tracing. A real three-plane (Y, UV, and a third "UV plus quarter-row"
 * variant) transfer-buffer-fetch setup, reusing the exact same real
 * GART-map-and-splice-into-+0x6d0/+0x69c-list pattern already fully
 * confirmed on the bind family and opcodes 0x0d/0x12/0x43/0x44 above.
 */
static void handle_opcode_3e(ATIR500DVDContext *ctx, UInt32 *record) {
    UInt8 *self = reinterpret_cast<UInt8 *>(ctx);
    UInt8 *accel = reinterpret_cast<UInt8 *>(ctx->accelerator);
    UInt8 *surf = reinterpret_cast<UInt8 *>(ctx->boundSurface);

    UInt32 pad = record[3];
    UInt8 *transferBuf = *reinterpret_cast<UInt8 **>(self + record[2] * 4 + 0x104);
    UInt8 *mip = surf + record[1] * 0x78;

    if (U32At(transferBuf, 4) != 0 ||
        (ctx->map_transfer_to_GART(reinterpret_cast<VendorTransferBuffer *>(transferBuf)),
         U32At(transferBuf, 4) != 0)) {
        FUN_0003913c(transferBuf + 0x2c);
        void *prevNode = reinterpret_cast<void *>(U32At(transferBuf, 0x34));
        void *nextNode = reinterpret_cast<void *>(U32At(transferBuf, 0x38));
        U32At(prevNode, 0x38) = reinterpret_cast<UInt32>(nextNode);
        U32At(nextNode, 0x34) = reinterpret_cast<UInt32>(prevNode);
        U32At(transferBuf, 0x34) = U32At(accel, 0x6d0);
        U32At(transferBuf, 0x38) = reinterpret_cast<UInt32>(accel + 0x69c);
        U32At(accel, 0x6d0) = reinterpret_cast<UInt32>(transferBuf);
        void *newPrev = reinterpret_cast<void *>(U32At(transferBuf, 0x34));
        U32At(newPrev, 0x38) = reinterpret_cast<UInt32>(transferBuf);
    }

    UInt32 shiftedBase = 0;
    U8At(reinterpret_cast<void *>(U32At(transferBuf, 0x14)), 0x14) = 0;
    if (U32At(transferBuf, 4) != 0) {
        shiftedBase = (U32At(transferBuf, 4) + U32At(transferBuf, 0x50) + U32At(accel, 0x8a4)) >> 5;
    }

    UInt32 base0 = U32At(mip, 0x560);
    SInt32 heightDelta = static_cast<SInt16>(U16At(surf, 0x9a)) - static_cast<SInt16>(U16At(surf, 0x94));
    UInt32 rowDelta = static_cast<UInt32>(heightDelta) * U16At(mip, 0x570);
    UInt32 base1 = base0 + rowDelta;

    UInt32 tileBit1 = (U8At(mip, 0x590) & 1u) << 2;
    UInt32 tileBit2 = (U8At(mip, 0x590) & 6u) << 2;

    record[0] = 0x1150;
    record[1] = (base0 & 0xffffffe0u) | tileBit1 | tileBit2;
    record[2] = 0x1151;
    record[3] = tileBit2 | tileBit1 | (base1 & 0xffffffe0u);
    record[4] = 0x1152;
    record[5] = tileBit2 | tileBit1 | ((base1 + (rowDelta >> 2)) & 0xffffffe0u);
    record[6] = 0x1393;
    record[7] = 10;
    record[8] = 0x138a;
    record[9] = shiftedBase << 5;
    record[10] = 0x138e;
    record[0xb] = ((pad >> 2) & 0x3ffeu) | 0xd00000u;
}

/*
 * handle_opcode_43_44 - RESOLVED (issue #7), fully transcribed. Real
 * target addresses 0x38094 (0x43) and 0x38130 (0x44) - CONFIRMED, via
 * direct disassembly comparison, to be REAL, BYTE-FOR-BYTE IDENTICAL
 * setup code (0x44 reaches the exact same real `joined_r0x000381c4`
 * merge point as 0x43's own natural fall-through, via an explicit
 * `goto`) - a genuine real driver/compiler artifact, not a transcription
 * shortcut. Real per-mip Y/UV transfer-buffer fetch setup, real
 * per-flag-bit branch on `record[4]` selecting between the mip's own
 * plain base and `boundSurface`'s own alternate `+0x998` base for each
 * of the two planes independently - the same "alternate mode" shape
 * already confirmed on the GL side's own analogous fields.
 */
static void handle_opcode_43_44(ATIR500DVDContext *ctx, UInt32 *record) {
    UInt8 *self = reinterpret_cast<UInt8 *>(ctx);
    UInt8 *accel = reinterpret_cast<UInt8 *>(ctx->accelerator);
    UInt8 *surf = reinterpret_cast<UInt8 *>(ctx->boundSurface);
    UInt8 *mip = surf + record[1] * 0x78;
    UInt8 *transferBuf = *reinterpret_cast<UInt8 **>(self + record[2] * 4 + 0x104);

    UInt32 flags = record[4];
    SInt32 heightDelta = static_cast<SInt16>(U16At(surf, 0x9a)) - static_cast<SInt16>(U16At(surf, 0x94));
    bool hasPad = record[3] != 0;

    UInt32 base, pitch;
    if ((flags & 2u) == 0) {
        pitch = U16At(mip, 0x570);
        base = hasPad ? (static_cast<UInt32>((heightDelta * static_cast<SInt32>(pitch) * 3) >> 1) + U32At(mip, 0x560))
                       : U32At(mip, 0x560);
    } else {
        base = U32At(surf, 0x998);
        pitch = U16At(mip, 0x570);
    }

    UInt32 uvBase;
    if ((flags & 4u) == 0) {
        uvBase = static_cast<UInt32>(heightDelta) * pitch + U32At(mip, 0x560);
        if (hasPad) {
            uvBase += static_cast<UInt32>((heightDelta * static_cast<SInt32>(pitch) * 3) >> 1);
        }
    } else {
        uvBase = static_cast<UInt32>(heightDelta) * pitch + U32At(surf, 0x998);
    }

    if (U32At(transferBuf, 4) != 0 ||
        (ctx->map_transfer_to_GART(reinterpret_cast<VendorTransferBuffer *>(transferBuf)),
         U32At(transferBuf, 4) != 0)) {
        FUN_0003913c(transferBuf + 0x2c);
        void *prevNode = reinterpret_cast<void *>(U32At(transferBuf, 0x34));
        void *nextNode = reinterpret_cast<void *>(U32At(transferBuf, 0x38));
        U32At(prevNode, 0x38) = reinterpret_cast<UInt32>(nextNode);
        U32At(nextNode, 0x34) = reinterpret_cast<UInt32>(prevNode);
        U32At(transferBuf, 0x34) = U32At(accel, 0x6d0);
        U32At(transferBuf, 0x38) = reinterpret_cast<UInt32>(accel + 0x69c);
        U32At(accel, 0x6d0) = reinterpret_cast<UInt32>(transferBuf);
        void *newPrev = reinterpret_cast<void *>(U32At(transferBuf, 0x34));
        U32At(newPrev, 0x38) = reinterpret_cast<UInt32>(transferBuf);
    }

    UInt32 shiftedBase = 0;
    U8At(reinterpret_cast<void *>(U32At(transferBuf, 0x14)), 0x14) = 0;
    if (U32At(transferBuf, 4) != 0) {
        shiftedBase = (U32At(transferBuf, 4) + U32At(transferBuf, 0x50) + U32At(accel, 0x8a4)) >> 5;
    }

    UInt32 tileBit1 = (U8At(mip, 0x590) & 1u) << 2;
    UInt32 tileBit2 = (U8At(mip, 0x590) & 6u) << 2;

    record[0] = 0x1150;
    record[1] = (base & 0xffffffe0u) | tileBit1 | tileBit2;
    record[2] = 0x1151;
    record[3] = tileBit2 | tileBit1 | (uvBase & 0xffffffe0u);
    record[4] = 0x1393;
    record[5] = 10;
    record[6] = 0x138a;
    record[7] = shiftedBase << 5;
}

/*
 * handle_opcode_46 - RESOLVED (issue #7), fully transcribed. Real target
 * address 0x38538. A real two-plane (Y/UV) fixed-surface tiling/format
 * register burst directly off `boundSurface`'s own embedded plane
 * descriptors (`+0x120`/`+0x128`/`+0x134`/`+0x136`/`+0x158`/`+0x15a`/
 * `+0x15c` for the Y-ish plane; `+0x920`/`+0x92c`/`+0x92e`/`+0x930`/
 * `+0x950`/`+0x952`/`+0x954` for the second, structurally-identical
 * plane) - no transfer-buffer/mip-array indirection at all, unlike every
 * other opcode in this cluster.
 *
 * CORRECTED, issue #7 continuation: `local_60`/`local_5c` are real
 * FUNCTION-SCOPE `process_command_buffer` variables (zero-initialized
 * once, before the dispatch loop), threaded here by reference - the
 * exact same real cross-call-persistence correction already applied to
 * `local_64`/`local_58` in handle_opcode_0a/0b above (see that function's
 * header note for the full explanation).
 */
static void handle_opcode_46(ATIR500DVDContext *ctx, UInt32 *record, UInt32 &local_60, UInt32 &local_5c) {
    UInt8 *surf = reinterpret_cast<UInt8 *>(ctx->boundSurface);

    UInt32 strideDiv0 = U16At(surf, 0x136);
    record[0] = 0x1140;
    record[1] = (strideDiv0 == 0) ? 0 : (U16At(surf, 0x138) / strideDiv0 - 1);
    record[2] = 0x1150;
    UInt32 tileBit0a = U8At(surf, 0x158) & 1u;
    UInt32 base0 = U32At(surf, 0x128) & 0xffffffe0u;
    UInt32 tileBit0b = static_cast<UInt32>(U8At(surf, 0x158) >> 1);
    record[3] = base0 | (tileBit0a << 2) | ((tileBit0b & 3u) << 3);
    record[4] = 0x1141;

    UInt32 strideDiv1 = U16At(surf, 0x92e);
    record[5] = (strideDiv1 == 0) ? 0 : (U16At(surf, 0x930) / strideDiv1 - 1);
    record[6] = 0x1151;
    UInt32 tileBit1a = U8At(surf, 0x950) & 1u;
    UInt32 base1 = U32At(surf, 0x920) & 0xffffffe0u;
    UInt32 tileBit1b = static_cast<UInt32>(U8At(surf, 0x950) >> 1);
    record[7] = base1 | (tileBit1a << 2) | ((tileBit1b & 3u) << 3);
    record[8] = 0x1393;
    record[9] = 10;
    record[0xa] = 0x138a;
    record[0xb] = base0;
    record[0xc] = 0x138e;

    UInt32 formatIdx0 = static_cast<UInt32>(U8At(surf, 0x15a)) * 0x1c;
    UInt32 div0a = 0;
    if ((U32At(surf, 0x15c) & 0xf00000u) != 0) {
        div0a = U16At(surf, 0x134) / ((U32At(surf, 0x15c) >> 0x14) & 0xfu);
    }
    UInt32 div0b = 0x20u / strideDiv0;
    UInt32 divFinal0 = (div0b <= div0a) ? div0a : div0b;
    local_60 = ((FormatTableLookup_0x0004d2e0(formatIdx0) >> 1) & 0x1e00000u) |
               ((FormatTableLookup_0x0004d2dc(formatIdx0) & 0xc00u) << 9) |
               ((tileBit0b & 3u) << 0x11) | (tileBit0a << 0x10) |
               (divFinal0 & 0x3ffeu) | (local_60 & 0xfe00c001u);
    record[0xd] = local_60;
    record[0xe] = 0x138b;
    record[0xf] = base1;
    record[0x10] = 0x138f;

    UInt32 formatIdx1 = static_cast<UInt32>(U8At(surf, 0x952)) * 0x1c;
    UInt32 div1a = 0;
    if ((U32At(surf, 0x954) & 0xf00000u) != 0) {
        div1a = U16At(surf, 0x92c) / ((U32At(surf, 0x954) >> 0x14) & 0xfu);
    }
    UInt32 div1b = 0x20u / strideDiv1;
    UInt32 divFinal1 = (div1b <= div1a) ? div1a : div1b;
    local_5c = ((FormatTableLookup_0x0004d2e0(formatIdx1) >> 1) & 0x1e00000u) |
               ((FormatTableLookup_0x0004d2dc(formatIdx1) & 0xc00u) << 9) |
               ((tileBit1b & 3u) << 0x11) | (tileBit1a << 0x10) |
               (divFinal1 & 0x3ffeu) | (local_5c & 0xfe00c001u);
    record[0x11] = local_5c;
}

/*
 * handle_opcode_47 - RESOLVED (issue #7), fully transcribed. Real target
 * address 0x38764. A real two-plane-index texture-fetch setup indexed
 * directly off `record[1]`/`record[2]` (clamped to a real, unexplained
 * `[10, 22]` valid range, defaulting to 1 when the raw value is 0 -
 * outside that range is a real HARD ABORT, `LAB_00039030`, not a plain
 * skip), reusing the exact same real shared tail (`LAB_00038870`:
 * `record[9] = ... | (tail & 3) << 0x13 | 0xc00000`) opcode 0x14 also
 * falls into - inlined here directly since 0x14 itself is not yet
 * transcribed (see this file's own header note on remaining opcodes).
 * `sets abortHard` on the real hard-abort path instead of returning, to
 * match the dispatcher's own real LAB_00039030 semantics exactly.
 */
static void handle_opcode_47(ATIR500DVDContext *ctx, UInt32 *record, bool &abortHard) {
    UInt8 *surf = reinterpret_cast<UInt8 *>(ctx->boundSurface);

    UInt32 idxB = record[1];
    if (idxB == 0) {
        idxB = 1;
    } else if (idxB - 10 > 0xcu) {
        abortHard = true;
        return;
    }
    UInt32 idxA = record[2];
    if (idxA == 0) {
        idxA = 1;
    } else if (idxA - 10 > 0xcu) {
        abortHard = true;
        return;
    }

    UInt8 *planeA = surf + idxA * 0x78;
    UInt8 *planeB = surf + idxB * 0x78;

    record[0] = 0x1140;
    record[1] = (U16At(planeB, 0xc0) >> 2) - 1;
    record[2] = 0x1150;
    record[3] = (U32At(planeB, 0xb0) & 0xffffffe0u) | ((U8At(planeB, 0xe0) & 1u) << 2) | ((U8At(planeB, 0xe0) & 6u) << 2);
    record[4] = 0x1393;
    record[5] = 10;
    record[6] = 0x138a;
    record[7] = U32At(planeA, 0xb0) & 0xffffffe0u;
    record[8] = 0x138e;

    UInt8 tail = U8At(planeA, 0xe1);
    UInt32 packed = ((U16At(planeA, 0xc0) >> 2) & 0x3ffeu) | ((U8At(planeA, 0xe0) & 1u) << 0x10) | ((U8At(planeA, 0xe0) & 6u) << 0x10);
    record[9] = packed | ((tail & 3u) << 0x13) | 0xc00000u; /* real: shared LAB_00038870 tail */
}

static void handle_opcode_04(ATIR500DVDContext *ctx, UInt32 *record, UInt32 &recordCount, UInt32 &byteOffset) {
    UInt8 *self = reinterpret_cast<UInt8 *>(ctx);
    UInt8 *accel = reinterpret_cast<UInt8 *>(ctx->accelerator);

    if (recordCount != 0) {
        UInt32 savedCount = recordCount; /* real: uVar10, saved at the top of the dispatch loop before any opcode runs */
        UInt32 flushDwords = recordCount * 4;
        recordCount = 0;
        UInt32 bufBase = (byteOffset & 0xfffffffcu) + U32At(self, 0xa4);
        U32At(accel, 0x708) += flushDwords;
        UInt32 bufEnd = byteOffset + U32At(self, 0x94);
        byteOffset += flushDwords;
        U32At(self, 0xa0) = ctx->accelerator->submit_buffer(
            reinterpret_cast<UInt32 *>(bufBase + 0x20), bufEnd + 0x20, savedCount);
    }
    *record = 0x80000000u;
}

/*
 * handle_opcode_18 - RESOLVED (issue #7), fully transcribed. Real target
 * address 0x38a0c, confirmed via direct branch-instruction tracing. A
 * real two-transfer-buffer fetch setup (`record[1]`/`record[2]`
 * independently indexed, each through the SAME real GART-map-and-splice
 * pattern already confirmed throughout this cluster), finishing with a
 * real format-ratio computation directly off `boundSurface`'s own
 * `+0x83e`/`+0x840` fields (a real divide-by-zero guard, unlike most of
 * this cluster's format-table-driven tail).
 */
/*
 * handle_opcode_15 - RESOLVED (issue #7), fully transcribed. Real target
 * address 0x378e0, confirmed via direct branch-instruction tracing.
 * Unlike every other opcode in this cluster, this one does NOT index a
 * per-`record[N]` mip array at all - it reads a real FIXED sub-record
 * embedded directly in `boundSurface` at `+0x7b0` (own fields at +8
 * "base", +0x18 "pitch", +0x38 "tile flag", +0x1c/+0x1e a dimension
 * pair) - the SAME real `+0x7b0`-relative fields (`+0x7b8`/`+0x7c8`/
 * `+0x7e8`) opcode 0x3d also references (still not yet transcribed, see
 * this file's own header note), confirming this is a real, distinct,
 * non-indexed "plane descriptor" on the surface object, reused by
 * multiple real opcodes. Real HARD ABORT if that record's own `base`
 * field is zero (`LAB_00039030` directly, not a plain skip). Ends via
 * the SAME real shared "sampler state" header/tail template
 * (`LAB_00038f80`) opcodes 0x05/0x06/0x0d already established, including
 * the same real `bigTileBit`/`combined` and `dims` formulas confirmed
 * on opcode 0x05's own body - transcribed here via direct PPC
 * instruction decoding (the raw disassembly's own `rlwinm` mask/shift
 * pairs were cross-checked against the ALREADY-CONFIRMED equivalent C
 * expressions from `handle_texture_sampler_state` rather than derived
 * from scratch, since no matching decompiled-C region for this specific
 * opcode's real body was found in the raw decompile output this project
 * has on hand - a real gap in Ghidra's own C rendering for this
 * particular address range, not something this project chose to skip).
 */
/*
 * handle_opcode_3d - RESOLVED (issue #7), fully transcribed. Real target
 * address 0x364c0, confirmed via direct branch-instruction tracing. The
 * densest opcode transcribed this pass: a real self-consuming record
 * (its own leading 7 dwords, `record[0..6]`, get overwritten to
 * `0x80000000` before any output is written - the same real "consume my
 * own header" idiom this project already documents elsewhere) followed
 * by TWO separate real 5-plane `0x1150`-`0x1154` PM4 bursts, written to
 * TWO explicitly-computed destinations WITHIN the record buffer itself
 * (`record + record[5]` for the first, `record + record[6]` for the
 * second - real explicit relative addressing, not simply the next
 * sequential slot), each burst gated by the SAME real 4-way branch
 * (`record[4] != 1` combined with `record[3] == 0`) across TWO real
 * source records - `mipA` (`boundSurface + record[1]*0x78`) and `mipB`
 * (`boundSurface + record[2]*0x78`) - plus a real THIRD, non-indexed
 * source: `boundSurface`'s own fixed `+0x7b0` sub-record (the SAME real
 * "plane descriptor" opcode 0x15 above already established, at the same
 * real `+0x7b8`/`+0x7c8` fields, plus two more of its own fields here,
 * `+0x7e8`/`+0x7e9`, not touched by opcode 0x15).
 *
 * Real, notable structural detail: the second burst's own 4-way branch
 * REUSES several real intermediate values the first burst's matching
 * branch already computed (`planeBase`, `planePitch`, `pitchB`, `baseB`)
 * rather than re-deriving them - real evidence the two bursts' branches,
 * while textually separate real `if` chains in the decompile, are a
 * single real continuous computation per real branch taken, not two
 * independent ones. Transcribed accordingly: each of the four real
 * branches below computes both bursts' output values together, in the
 * real decompile's own exact assignment order (several outputs feed
 * later ones within the same branch - order is load-bearing here).
 *
 * Confidence: CONFIRMED structure and every real offset/constant from a
 * complete real decompile. Given the real density (9 distinct tracked
 * output values across two bursts and four branches), transcribed with
 * literal per-branch scoping rather than cross-branch simplification -
 * worth an independent spot-check before trusting any single bit
 * position, same caveat already given to this pass's other densest
 * functions (e.g. handle_opcode_16 above, where exactly this kind of
 * check caught a real transcription bug before it was committed).
 */
static void handle_opcode_3d(ATIR500DVDContext *ctx, UInt32 *record) {
    UInt8 *surf = reinterpret_cast<UInt8 *>(ctx->boundSurface);
    UInt32 selB = record[3];  /* real: uVar35 */
    UInt32 selA = record[4];  /* real: uVar30 - NOT record[4]'s later reuse as an opcode; a real per-record selector */
    UInt8 *mipA = surf + record[1] * 0x78;
    UInt8 *mipB = surf + record[2] * 0x78;
    UInt32 burst2Off = record[6];

    SInt32 heightDelta = static_cast<SInt16>(U16At(surf, 0x9a)) - static_cast<SInt16>(U16At(surf, 0x94));
    UInt32 pitchA = U16At(mipA, 0x570);
    UInt32 pitchAw = pitchA;
    UInt32 baseA = U32At(mipA, 0x560);
    UInt32 rowSizeA = static_cast<UInt32>(heightDelta) * pitchAw;
    UInt32 blendedA = baseA + ((rowSizeA * 3) >> 1);

    /* real: self-consume this record's own leading 7 dwords */
    for (int i = 0; i < 7; i++) record[i] = 0x80000000u;

    UInt32 planePitch = U16At(surf, 0x7c8);          /* real: uVar33, the SAME +0x7b0-relative "pitch" field opcode 0x15 uses */
    /*
     * real: `puVar23 = puVar37 + puVar37[5];` in the raw decompile - but
     * VERIFIED via direct disassembly that the real machine code loads
     * `record[5]`'s value HERE, AFTER the self-consuming zero-out above
     * already overwrote it to exactly `0x80000000`, not before (unlike
     * `record[6]`/`burst2Off`, captured safely into a stack slot BEFORE
     * the zero-out - real, deliberate asymmetry, not a transcription
     * inconsistency). Real C-style pointer arithmetic scales that value
     * by `sizeof(UInt32)` (4) before adding it to `record` - and
     * `0x80000000 * 4`, computed in real 32-bit address arithmetic,
     * overflows exactly back to 0 (confirmed via the raw disassembly's
     * own `rlwinm r2,r2,0x2,...` scale-by-4 immediately followed by
     * `add r7,r30,r2`). So `burst1` is real, always, exactly `record`
     * itself - written directly here rather than as `record +
     * record[5]`, which would rely on the SAME 32-bit overflow
     * wraparound C++ does not guarantee (unlike the real machine code's
     * plain modular address arithmetic) - mathematically identical
     * result, without relying on undefined pointer-overflow behavior.
     */
    UInt32 *burst1 = record;
    UInt32 tailPacked2Src = planePitch >> 1;           /* real: uVar14 before its own later reuse */

    UInt32 out1E = baseA;      /* real: uVar8 default */
    UInt32 out1G = blendedA;   /* real: uVar18 default */
    UInt32 out1_altG = blendedA; /* real: uVar16 default (a SEPARATE default slot from out1G, despite sharing the same initial value) */

    UInt32 out1A, out1B, out1C, out1D;   /* burst 1: uVar38/uVar26/uVar10/uVar27 */
    UInt32 out2A, out2B, out2C, out2D, out2E, out2G, out2I; /* burst 2: uVar18/uVar29/uVar30/uVar31/uVar28/uVar16/uVar32 */
    UInt32 planeBase, pitchB, baseB; /* real: uVar29/uVar36/uVar31 - shared across both bursts' branches */

    if (selA != 1) {
        if (selB == 0) {
            planeBase = U32At(surf, 0x7b8);
            baseB = U32At(mipB, 0x560);
            out1_altG = pitchAw + blendedA;
            out1C = baseA + pitchAw;
            pitchB = U16At(mipB, 0x570);
            out1B = planeBase + planePitch;
            out1A = planeBase;
            out1D = baseB;

            out2G = rowSizeA + blendedA;
            out2I = pitchAw + out2G;
            out2A = planePitch * static_cast<UInt32>(heightDelta) + planeBase;
            out2E = baseA + rowSizeA;
            out2D = static_cast<UInt32>(heightDelta) * pitchB + baseB;
            out2B = planePitch + out2A;
            out2C = pitchAw + out2E;
        } else {
            pitchB = U16At(mipB, 0x570);
            planeBase = U32At(surf, 0x7b8);
            baseB = U32At(mipB, 0x560);
            out1C = baseA; /* real: `uVar10 = uVar28;` - explicit self-assign-shaped, still a real distinct write */
            out1A = planeBase + planePitch;
            out1B = planeBase;
            out1G = pitchAw + blendedA;
            out1E = baseA + pitchAw;
            out1D = pitchB + baseB;

            out2I = rowSizeA + blendedA;
            out2C = baseA + rowSizeA;
            out2B = static_cast<UInt32>(heightDelta) * planePitch + planeBase;
            out2G = pitchAw + out2I;
            out2E = pitchAw + out2C;
            out2A = planePitch + out2B;
            out2D = pitchB + static_cast<UInt32>(heightDelta) * pitchB + baseB;
        }
    } else if (selB == 0) {
        pitchB = U16At(mipB, 0x570);
        baseB = U32At(mipB, 0x560);
        planeBase = U32At(surf, 0x7b8);
        out1C = baseB;
        out1A = planeBase + planePitch;
        out1B = planeBase;
        out1G = pitchAw + blendedA;
        out1E = baseA + pitchAw;
        out1D = baseB + pitchB;

        out2I = rowSizeA + blendedA;
        out2G = pitchAw + out2I;
        out2B = planePitch * static_cast<UInt32>(heightDelta) + planeBase;
        out2C = static_cast<UInt32>(heightDelta) * pitchB + baseB;
        out2A = planePitch + out2B;
        out2E = pitchAw + baseA + rowSizeA;
        out2D = pitchB + out2C;
    } else {
        pitchB = U16At(mipB, 0x570);
        baseB = U32At(mipB, 0x560);
        planeBase = U32At(surf, 0x7b8);
        out1C = baseB + pitchB;
        out1A = planeBase;
        out1B = planeBase + planePitch;
        out1D = baseB;
        out1_altG = pitchAw + blendedA;

        out2G = rowSizeA + blendedA;
        out2I = pitchAw + out2G;
        out2A = planePitch * static_cast<UInt32>(heightDelta) + planeBase;
        out2E = baseA + rowSizeA;
        out2D = static_cast<UInt32>(heightDelta) * pitchB + baseB;
        out2B = planePitch + out2A;
        out2C = pitchB + out2D;
    }

    UInt32 tileA0 = U8At(mipA, 0x590) & 1u;
    UInt32 tileA1 = static_cast<UInt32>(U8At(mipA, 0x590) >> 1);
    UInt32 tileAHi = (tileA1 & 3u) << 3;
    UInt32 tileALo = tileA0 << 2;
    UInt32 tileB0 = (U8At(mipB, 0x590) & 1u) << 2;
    UInt32 tileB1 = (U8At(mipB, 0x590) & 6u) << 2;

    UInt32 tailPacked1 = ((pitchA >> 1) & 0x3ffeu) | (tileA0 << 0x10) | ((tileA1 & 3u) << 0x11) |
                          ((U8At(mipA, 0x591) & 3u) << 0x13) | 0xc00000u;
    UInt32 tailPacked2 = (tailPacked2Src & 0x3ffeu) | ((U8At(surf, 0x7e8) & 1u) << 0x10) |
                          ((U8At(surf, 0x7e8) & 6u) << 0x10) | ((U8At(surf, 0x7e9) & 3u) << 0x13) | 0xc00000u;

    burst1[0] = 0x1150;
    burst1[1] = (out1A & 0xffffffe0u) | tileALo | tileAHi;
    burst1[2] = 0x1151;
    burst1[3] = tileAHi | tileALo | (out1B & 0xffffffe0u);
    burst1[4] = 0x1152;
    burst1[5] = tileAHi | tileALo | (out1C & 0xffffffe0u);
    burst1[6] = 0x1153;
    burst1[7] = (out1D & 0xffffffe0u) | tileB0 | tileB1;
    burst1[8] = 0x1154;
    burst1[9] = tileB1 | tileB0 | (out1E & 0xffffffe0u);
    burst1[10] = 0x1393;
    burst1[0xb] = 10;
    burst1[0xc] = 0x138e;
    burst1[0xd] = tailPacked1;
    burst1[0xe] = 0x138a;
    burst1[0xf] = out1G & 0xffffffe0u;
    burst1[0x10] = 0x138f;
    burst1[0x11] = tailPacked1;
    burst1[0x12] = 0x138b;
    burst1[0x13] = out1_altG & 0xffffffe0u;
    burst1[0x14] = 0x1390;
    burst1[0x15] = tailPacked2;
    burst1[0x16] = 0x138c;
    burst1[0x17] = out1A & 0xffffffe0u;

    UInt32 *burst2 = record + burst2Off;
    burst2[0] = 0x1150;
    burst2[1] = tileAHi | tileALo | (out2A & 0xffffffe0u);
    burst2[2] = 0x1151;
    burst2[3] = tileAHi | tileALo | (out2B & 0xffffffe0u);
    burst2[4] = 0x1152;
    burst2[5] = tileAHi | tileALo | (out2C & 0xffffffe0u);
    burst2[6] = 0x1153;
    burst2[7] = tileB1 | tileB0 | (out2D & 0xffffffe0u);
    burst2[8] = 0x1154;
    burst2[9] = tileB1 | tileB0 | (out2E & 0xffffffe0u);
    burst2[10] = 0x1393;
    burst2[0xb] = 10;
    burst2[0xc] = 0x138e;
    burst2[0xd] = tailPacked1;
    burst2[0xe] = 0x138a;
    burst2[0xf] = out2G & 0xffffffe0u;
    burst2[0x10] = 0x138f;
    burst2[0x11] = tailPacked1;
    burst2[0x12] = 0x138b;
    burst2[0x13] = out2I & 0xffffffe0u;
    burst2[0x14] = 0x1390;
    burst2[0x15] = tailPacked2;
    burst2[0x16] = 0x138c;
    burst2[0x17] = out2A & 0xffffffe0u;
}

static void handle_opcode_15(ATIR500DVDContext *ctx, UInt32 *record, bool &abortHard) {
    UInt8 *self = reinterpret_cast<UInt8 *>(ctx);
    UInt8 *surf = reinterpret_cast<UInt8 *>(ctx->boundSurface);
    UInt32 origRecord1 = record[1];
    UInt8 *planeRec = surf + 0x7b0;

    UInt32 base = U32At(planeRec, 8);
    if (base == 0) {
        abortHard = true;
        return;
    }
    UInt8 tileFlag = U8At(planeRec, 0x38);
    UInt32 pitch = U16At(planeRec, 0x18);

    UInt32 bigTileBit = (tileFlag < 2) ? 0 : 0x80000000u;
    UInt32 combined = (base >> 10) | ((pitch & 0x3fc0u) << 16) | ((tileFlag & 1u) << 0x1e);

    record[0] = 0x1393;
    record[1] = 10;
    record[2] = 0x5c8;
    record[3] = 0x20000;
    record[4] = 0xc0069a00;
    record[5] = 0x52f036da;
    record[6] = bigTileBit | combined;
    record[7] = U32At(self, 0x158);
    record[8] = (static_cast<UInt32>(U16At(planeRec, 0x1e)) << 16) | U16At(planeRec, 0x1c);
    record[9] = origRecord1;
    record[0xa] = 0;
    record[0xb] = U16At(planeRec, 0x1e) | ((pitch & 0xfffcu) << 14);

    /* real: shared LAB_00038f80 tail */
    record[0xc] = 0xd0b;
    record[0xd] = 5;
    record[0xe] = 0x5c8;
    record[0xf] = 0x10000;
}

static void handle_opcode_18(ATIR500DVDContext *ctx, UInt32 *record) {
    UInt8 *self = reinterpret_cast<UInt8 *>(ctx);
    UInt8 *accel = reinterpret_cast<UInt8 *>(ctx->accelerator);
    UInt8 *surf = reinterpret_cast<UInt8 *>(ctx->boundSurface);

    UInt8 *bufA = *reinterpret_cast<UInt8 **>(self + record[1] * 4 + 0x104);
    if (U32At(bufA, 4) != 0 ||
        (ctx->map_transfer_to_GART(reinterpret_cast<VendorTransferBuffer *>(bufA)),
         U32At(bufA, 4) != 0)) {
        FUN_0003913c(bufA + 0x2c);
        void *prevNode = reinterpret_cast<void *>(U32At(bufA, 0x34));
        void *nextNode = reinterpret_cast<void *>(U32At(bufA, 0x38));
        U32At(prevNode, 0x38) = reinterpret_cast<UInt32>(nextNode);
        U32At(nextNode, 0x34) = reinterpret_cast<UInt32>(prevNode);
        U32At(bufA, 0x34) = U32At(accel, 0x6d0);
        U32At(bufA, 0x38) = reinterpret_cast<UInt32>(accel + 0x69c);
        U32At(accel, 0x6d0) = reinterpret_cast<UInt32>(bufA);
        void *newPrev = reinterpret_cast<void *>(U32At(bufA, 0x34));
        U32At(newPrev, 0x38) = reinterpret_cast<UInt32>(bufA);
    }
    UInt32 shiftedA = 0;
    U8At(reinterpret_cast<void *>(U32At(bufA, 0x14)), 0x14) = 0;
    if (U32At(bufA, 4) != 0) {
        shiftedA = (U32At(bufA, 4) + U32At(bufA, 0x50) + U32At(accel, 0x8a4)) >> 5;
    }

    UInt8 *bufB = *reinterpret_cast<UInt8 **>(self + record[2] * 4 + 0x104);
    if (U32At(bufB, 4) != 0 ||
        (ctx->map_transfer_to_GART(reinterpret_cast<VendorTransferBuffer *>(bufB)),
         U32At(bufB, 4) != 0)) {
        FUN_0003913c(bufB + 0x2c);
        void *prevNode = reinterpret_cast<void *>(U32At(bufB, 0x34));
        void *nextNode = reinterpret_cast<void *>(U32At(bufB, 0x38));
        U32At(prevNode, 0x38) = reinterpret_cast<UInt32>(nextNode);
        U32At(nextNode, 0x34) = reinterpret_cast<UInt32>(prevNode);
        U32At(bufB, 0x34) = U32At(accel, 0x6d0);
        U32At(bufB, 0x38) = reinterpret_cast<UInt32>(accel + 0x69c);
        U32At(accel, 0x6d0) = reinterpret_cast<UInt32>(bufB);
        void *newPrev = reinterpret_cast<void *>(U32At(bufB, 0x34));
        U32At(newPrev, 0x38) = reinterpret_cast<UInt32>(bufB);
    }
    UInt32 sumB = 0;
    U8At(reinterpret_cast<void *>(U32At(bufB, 0x14)), 0x14) = 0;
    if (U32At(bufB, 4) != 0) {
        sumB = U32At(bufB, 4) + U32At(bufB, 0x50) + U32At(accel, 0x8a4);
    }

    record[0] = 0x1150;
    record[1] = shiftedA << 5;
    record[2] = 0x1151;
    record[3] = (sumB + record[3] * 0x80) & 0xffffffe0u;
    record[4] = 0x1393;
    record[5] = 10;
    record[6] = 0x138a;
    record[7] = U32At(surf, 0x830) & 0xffffffe0u;
    record[8] = 0x138e;
    UInt16 divisor = U16At(surf, 0x83e);
    if (divisor == 0) {
        record[9] = 0x1400000u;
    } else {
        record[9] = (((U16At(surf, 0x840) / divisor) >> 1) & 0x3ffeu) | 0x1400000u;
    }
}

/*
 * handle_opcode_16 - RESOLVED (issue #7), fully transcribed. Real target
 * address 0x36e08, confirmed via direct branch-instruction tracing. The
 * densest opcode transcribed this pass: a real 12-way branch
 * (`record[5] != 1` selecting between two source-record conventions,
 * each further split on `record[1]` being 2/3/other, each further split
 * on `record[4]`/altFlag) producing FIVE real output values from TWO
 * independent real per-mip records - `mipB` (`boundSurface + record[2]*0x78`,
 * always the source for tile bits on outputs A/C and the shared tail)
 * and `mipAlt` (`boundSurface + record[3]*0x78` when `record[5] != 1`,
 * else numerically identical to `mipB` - the SAME real "alternate source
 * record" convention already confirmed on opcode 0x14 above, except
 * HERE both branches genuinely read it, unlike 0x14 where one branch's
 * read of it was real but unused). Reuses the same real YUV 4:2:0
 * chroma formula and 4-plus-1-plane PM4 burst shape (`0x1150`/`1151`/
 * `1152`/`1153` plus a fifth plain value) as the rest of this cluster.
 *
 * Confidence: CONFIRMED structure and every real offset/constant from a
 * complete real decompile. Given the real density (5 interdependent
 * outputs across 12 real branches), transcribed with per-branch local
 * scoping and literal-order preservation rather than cross-branch
 * simplification, to keep this checkable line-by-line against the raw
 * decompile - worth an independent spot-check before trusting any single
 * bit position, same caveat this project already gives its other
 * densest functions.
 */
static void handle_opcode_16(ATIR500DVDContext *ctx, UInt32 *record) {
    UInt8 *surf = reinterpret_cast<UInt8 *>(ctx->boundSurface);
    UInt32 mode = record[1];
    UInt32 altFlag = record[4];
    UInt8 *mipB = surf + record[2] * 0x78;
    UInt8 *mipAlt = (record[5] != 1) ? (surf + record[3] * 0x78) : mipB;

    UInt32 pitch = U16At(mipB, 0x570);
    UInt32 pitchW = pitch;
    UInt32 base0 = U32At(mipB, 0x560);
    SInt32 heightDelta = static_cast<SInt16>(U16At(surf, 0x9a)) - static_cast<SInt16>(U16At(surf, 0x94));
    UInt32 rowSize = static_cast<UInt32>(heightDelta) * pitchW;
    UInt32 blendedBase = base0 + ((rowSize * 3) >> 1);

    UInt32 packedLow, outA, outB, outC, outD, outE;

    if (record[5] != 1) {
        if (mode == 2) {
            packedLow = pitch >> 2;
            if (altFlag == 0) {
                UInt32 tmp = base0 + rowSize;
                outE = pitchW + rowSize + blendedBase;
                outA = tmp + (pitch >> 1);
                outC = tmp + ((pitchW * 3) >> 1);
                outD = static_cast<UInt32>(heightDelta) * U16At(mipAlt, 0x570) + U32At(mipAlt, 0x560);
                outB = U16At(mipAlt, 0x570) + outD;
            } else {
                UInt32 pitchAlt = U16At(mipAlt, 0x570);
                outA = base0 + rowSize;
                outE = rowSize + blendedBase + (pitch >> 1);
                outC = pitchW + outA;
                UInt32 altBlend = static_cast<UInt32>(heightDelta) * pitchAlt + U32At(mipAlt, 0x560);
                outD = altBlend + ((pitchAlt * 3) >> 1);
                outB = altBlend + (pitchAlt >> 1);
            }
        } else if (mode == 3) {
            packedLow = pitch >> 2;
            UInt32 fifthTerm = (rowSize * 5) >> 2;
            if (altFlag == 0) {
                UInt32 tmp = base0 + fifthTerm;
                outE = pitchW + blendedBase + fifthTerm;
                outC = tmp + ((pitchW * 3) >> 1);
                outA = tmp + (pitch >> 1);
                outD = (static_cast<UInt32>(heightDelta) * U16At(mipAlt, 0x570) * 5 >> 2) + U32At(mipAlt, 0x560);
                outB = U16At(mipAlt, 0x570) + outD;
            } else {
                UInt32 pitchAlt = U16At(mipAlt, 0x570);
                UInt32 fifthTermA = fifthTerm;
                outA = base0 + fifthTermA;
                outE = fifthTermA + blendedBase + (pitch >> 1);
                outC = pitchW + outA;
                UInt32 altBlend = (static_cast<UInt32>(heightDelta) * pitchAlt * 5 >> 2) + U32At(mipAlt, 0x560);
                outD = altBlend + ((pitchAlt * 3) >> 1);
                outB = altBlend + (pitchAlt >> 1);
            }
        } else {
            packedLow = (pitch >> 1) & 0x7ffeu;
            if (altFlag == 0) {
                outD = U32At(mipAlt, 0x560);
                outE = blendedBase + pitchW * 2;
                outC = base0 + pitchW * 3;
                outA = base0 + pitchW;
                outB = outD + U16At(mipAlt, 0x570) * 2;
            } else {
                outE = pitchW + blendedBase;
                outC = base0 + pitchW * 2;
                outB = U32At(mipAlt, 0x560) + U16At(mipAlt, 0x570);
                outD = U32At(mipAlt, 0x560) + U16At(mipAlt, 0x570) * 3;
            }
        }
    } else if (mode == 2) {
        packedLow = pitch >> 2;
        if (altFlag == 0) {
            outC = U16At(mipAlt, 0x570);
            outE = rowSize + blendedBase + (pitch >> 1);
            outA = static_cast<UInt32>(heightDelta) * outC + U32At(mipAlt, 0x560);
            outB = outA + (U16At(mipAlt, 0x570) >> 1);
            outD = outA + ((outC * 3) >> 1);
            outC = outC + outA; /* real: `uVar14` reused a THIRD time here for the final outC */
        } else {
            outB = U16At(mipAlt, 0x570);
            outE = pitchW + rowSize + blendedBase;
            outD = static_cast<UInt32>(heightDelta) * outB + U32At(mipAlt, 0x560);
            outA = outD + (U16At(mipAlt, 0x570) >> 1);
            outC = outD + ((outB * 3) >> 1);
            outB = outB + outD;
        }
    } else if (mode == 3) {
        packedLow = pitch >> 2;
        UInt32 fifthTerm = (rowSize * 5) >> 2;
        if (altFlag == 0) {
            outC = U16At(mipAlt, 0x570);
            outE = blendedBase + fifthTerm + (pitch >> 1);
            outA = (static_cast<UInt32>(heightDelta) * outC * 5 >> 2) + U32At(mipAlt, 0x560);
            outB = outA + (U16At(mipAlt, 0x570) >> 1);
            outD = outA + ((outC * 3) >> 1);
            outC = outC + outA;
        } else {
            outB = U16At(mipAlt, 0x570);
            outE = pitchW + blendedBase + fifthTerm;
            outD = (static_cast<UInt32>(heightDelta) * outB * 5 >> 2) + U32At(mipAlt, 0x560);
            outA = outD + (U16At(mipAlt, 0x570) >> 1);
            outC = outD + ((outB * 3) >> 1);
            outB = outB + outD;
        }
    } else {
        packedLow = (pitch >> 1) & 0x7ffeu;
        if (altFlag == 0) {
            outD = U16At(mipAlt, 0x570);
            outA = U32At(mipAlt, 0x560);
            outE = pitchW + blendedBase;
            outB = outA + outD;
            outC = outA + outD * 2;
            outD = outA + outD * 3;
        } else {
            outC = U16At(mipAlt, 0x570);
            outD = U32At(mipAlt, 0x560);
            outE = blendedBase + pitchW * 2;
            outA = outD + outC;
            outB = outD + outC * 2;
            outC = outD + outC * 3;
        }
    }

    record[0] = 0x1150;
    UInt32 tileB0 = U8At(mipB, 0x590) & 1u;
    UInt32 tileB1 = static_cast<UInt32>(U8At(mipB, 0x590) >> 1);
    UInt32 tileBHi = (tileB1 & 3u) << 3;
    UInt32 tileBLo = tileB0 << 2;
    record[1] = (outA & 0xffffffe0u) | tileBLo | tileBHi;
    record[2] = 0x1151;
    UInt32 tileAltLo = (U8At(mipAlt, 0x590) & 1u) << 2;
    UInt32 tileAltHi = (U8At(mipAlt, 0x590) & 6u) << 2;
    record[3] = (outB & 0xffffffe0u) | tileAltLo | tileAltHi;
    record[4] = 0x1152;
    record[5] = tileBHi | tileBLo | (outC & 0xffffffe0u);
    record[6] = 0x1153;
    record[7] = tileAltHi | tileAltLo | (outD & 0xffffffe0u);
    record[8] = 0x1393;
    record[9] = 10;
    record[0xa] = 0x138a;
    record[0xb] = outE & 0xffffffe0u;
    record[0xc] = 0x138e;
    UInt8 tail = U8At(mipB, 0x591);
    record[0xd] = (packedLow & 0x3ffeu) | (tileB0 << 0x10) | ((tileB1 & 3u) << 0x11) | ((tail & 3u) << 0x13) | 0xc00000u;
}

/*
 * handle_opcode_14 - RESOLVED (issue #7), fully transcribed. Real target
 * address 0x36a14, confirmed via direct branch-instruction tracing
 * (this was the exact opcode boundary whose C-decompile brace nesting
 * this project's earlier pass found genuinely ambiguous - resolved this
 * time by tracing the real disassembly instead, per this file's own
 * methodology note).
 *
 * Real structure: a dense real 6-way branch (`record[5] != 1` selecting
 * between two structurally-parallel families of formulas, each further
 * split on `record[1]` being 2, 3, or anything else) computing three
 * real output values (Y-plane-ish `outA`, a second `outB`, and a third
 * `outC`) from `boundSurface`'s own real per-mip fields, reusing the
 * same real YUV 4:2:0 chroma formula (`heightDelta * pitch * 3 >> 1`)
 * already confirmed throughout this cluster. The `record[5] != 1`
 * branch's own real per-source-record indirection (`iVar20` in the raw
 * decompile, overridden to a SECOND mip record - indexed by `record[3]`
 * rather than `record[2]` - only in this branch) is transcribed as a
 * real, apparently-dead computation (the override is computed but never
 * actually read anywhere in that specific branch, confirmed by reading
 * every reference to it) - kept for fidelity rather than silently
 * dropped, since this project cannot rule out a real reason for it this
 * pass. The OTHER branch (`record[5] == 1`) genuinely DOES use that
 * indirection, but since it's never overridden in that branch (the
 * override only fires on `record[5] != 1`), it's always numerically
 * identical to the primary mip record - simplified here to reuse this
 * function's own `pitch`/`base0`/`rowSize`/`blendedBase` locals directly
 * rather than re-deriving them from a second, provably-identical
 * pointer (verified equivalent, not assumed).
 *
 * Ends via the same real shared tail (`LAB_00038870`) opcode 0x47 above
 * also reaches.
 */
static void handle_opcode_14(ATIR500DVDContext *ctx, UInt32 *record) {
    UInt8 *surf = reinterpret_cast<UInt8 *>(ctx->boundSurface);
    UInt32 mode = record[1];
    UInt32 altFlag = record[4];
    UInt8 *mipB = surf + record[2] * 0x78;

    UInt32 pitch = U16At(mipB, 0x570);
    UInt32 pitchAsUInt = pitch;
    UInt32 base0 = U32At(mipB, 0x560);
    SInt32 heightDelta = static_cast<SInt16>(U16At(surf, 0x9a)) - static_cast<SInt16>(U16At(surf, 0x94));
    UInt32 rowSize = static_cast<UInt32>(heightDelta) * pitchAsUInt;
    UInt32 blendedBase = base0 + ((rowSize * 3) >> 1);

    UInt32 packedLow, outA, outB, outC;

    if (record[5] != 1) {
        /* real: `iVar20` override to a second mip record computed here
         * but never read in this branch - see header note. */
        (void)(surf + record[3] * 0x78);

        if (mode == 2) {
            packedLow = pitch >> 2;
            if (altFlag == 0) {
                UInt32 tmp = base0 + rowSize;
                outB = pitchAsUInt + rowSize + blendedBase;
                outA = tmp + (pitch >> 1);
                outC = tmp + ((pitchAsUInt * 3) >> 1);
            } else {
                outA = base0 + rowSize;
                outC = pitchAsUInt + outA;
                outB = rowSize + blendedBase + (pitch >> 1);
            }
        } else if (mode == 3) {
            packedLow = pitch >> 2;
            UInt32 fifthTerm = (rowSize * 5) >> 2;
            if (altFlag == 0) {
                UInt32 tmp = base0 + fifthTerm;
                outB = pitchAsUInt + blendedBase + fifthTerm;
                outC = tmp + ((pitchAsUInt * 3) >> 1);
                outA = tmp + (pitch >> 1);
            } else {
                outA = base0 + fifthTerm;
                outB = blendedBase + fifthTerm + (pitch >> 1);
                outC = pitchAsUInt + outA;
            }
        } else {
            packedLow = (pitch >> 1) & 0x7ffeu;
            if (altFlag == 0) {
                outB = blendedBase + pitchAsUInt * 2;
                outC = base0 + pitchAsUInt * 3;
                outA = base0 + pitchAsUInt;
            } else {
                outB = pitchAsUInt + blendedBase;
                outC = base0 + pitchAsUInt * 2;
                outA = base0; /* real: NOT reassigned on this specific sub-branch */
            }
        }
    } else if (mode == 2) {
        packedLow = pitch >> 2;
        if (altFlag == 0) {
            outB = rowSize + blendedBase + (pitch >> 1);
            outA = rowSize + base0;
            outC = pitch + outA;
        } else {
            UInt32 tmp = rowSize + base0;
            outB = pitchAsUInt + rowSize + blendedBase;
            outC = tmp + ((pitch * 3) >> 1);
            outA = tmp + (pitch >> 1);
        }
    } else if (mode == 3) {
        packedLow = pitch >> 2;
        UInt32 fifthTerm = (rowSize * 5) >> 2;
        if (altFlag == 0) {
            outB = blendedBase + fifthTerm + (pitch >> 1);
            outA = fifthTerm + base0;
            outC = pitch + outA;
        } else {
            UInt32 tmp = fifthTerm + base0;
            outB = pitchAsUInt + blendedBase + fifthTerm;
            outC = tmp + ((pitch * 3) >> 1);
            outA = tmp + (pitch >> 1);
        }
    } else {
        packedLow = (pitch >> 1) & 0x7ffeu;
        if (altFlag == 0) {
            outA = base0;
            outB = pitchAsUInt + blendedBase;
            outC = outA + pitch * 2;
        } else {
            outB = blendedBase + pitchAsUInt * 2;
            outA = base0 + pitch;
            outC = base0 + pitch * 3;
        }
    }

    record[0] = 0x1150;
    UInt32 tileBit0 = U8At(mipB, 0x590) & 1u;
    UInt32 tileBit1 = static_cast<UInt32>(U8At(mipB, 0x590) >> 1);
    UInt32 tileBitsHi = (tileBit1 & 3u) << 3;
    UInt32 tileBitsLo = tileBit0 << 2;
    record[1] = (outA & 0xffffffe0u) | tileBitsLo | tileBitsHi;
    record[2] = 0x1151;
    record[3] = tileBitsHi | tileBitsLo | (outC & 0xffffffe0u);
    record[4] = 0x1393;
    record[5] = 10;
    record[6] = 0x138a;
    record[7] = outB & 0xffffffe0u;
    record[8] = 0x138e;
    UInt8 tail = U8At(mipB, 0x591);
    UInt32 packed = (packedLow & 0x3ffeu) | (tileBit0 << 0x10) | ((tileBit1 & 3u) << 0x11);
    record[9] = packed | ((tail & 3u) << 0x13) | 0xc00000u; /* real: shared LAB_00038870 tail */
}

/*
 * process_command_buffer - RESOLVED (issue #7) for every opcode this
 * pass has transcribed; STILL PARTIAL overall - see the explicit
 * fallthrough case below for exactly which seven opcodes remain (real,
 * disassembly-verified addresses given there, ready for a future pass -
 * finding those addresses reliably, after this exact function burned
 * two earlier brace-nesting-only attempts, was itself a real deliverable
 * this pass).
 *
 * Real skeleton: a `this+0xa4`-based (`commandBufferBase`) record
 * stream, top-byte opcode dispatch, self-consuming low-24-bit distance
 * fields - same mechanism as GL/2D. Real shared per-buffer state,
 * matching the raw decompile's own function-scope locals exactly (NOT
 * per-opcode-call locals - see handle_opcode_0a's header note for why
 * this distinction is load-bearing): `result` (real `local_68`,
 * accumulated return value), `byteOffset` (real `local_70`),
 * `recordCount` (real `local_6c`, initial sentinel `0xffffffff` -
 * confirmed the same real convention 2D's own dispatcher already uses),
 * and `local_64`/`local_60`/`local_5c`/`local_58` (real per-opcode
 * cross-call-persistent scratch words, each read by exactly one real
 * opcode - 0xa/0x46/0x46/0xb respectively).
 */
IOReturn ATIR500DVDContext::process_command_buffer(VendorCommandDescriptor *descriptor) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

    UInt32 result = 0;                 /* real: local_68 */
    UInt32 byteOffset = 0;             /* real: local_70 */
    UInt32 recordCount = 0xffffffffu;  /* real: local_6c */
    UInt32 local_64 = 0, local_60 = 0, local_5c = 0, local_58 = 0; /* real: shared cross-opcode scratch - see handle_opcode_0a's header note */
    UInt32 *record = reinterpret_cast<UInt32 *>(U32At(self, 0xa4) + 0x1c);

    do {
        UInt32 raw = *record;
        UInt32 opcode = raw & 0xff000000u;
        UInt32 distance = raw & 0xffffffu; /* real default consumption - overridden per opcode below (none of the resolved opcodes below actually override it - every one uses the natural distance - but this matches 2D's own established template) */
        bool abortToZero = false;          /* real: LAB_00039030 (recordCount=0, distance=0) */

        switch (opcode) {
        case 0x02000000u:
            handle_opcode_02(result);
            break;

        case 0x04000000u:
            handle_opcode_04(this, record, recordCount, byteOffset);
            break;

        case 0x05000000u:
        case 0x06000000u:
            handle_texture_sampler_state(this, opcode, record);
            break;

        /* Real HARD-ABORT opcodes - address-verified (not brace-inferred):
         * 0x07/0x08/0x09 unconditionally, 0x0c unconditionally too
         * (numerically adjacent to the 0xa/0xb/0xd cluster, but confirmed
         * to share NO code with it - see handle_opcode_0b's header note). */
        case 0x07000000u:
        case 0x08000000u:
        case 0x09000000u:
        case 0x0c000000u:
            abortToZero = true;
            break;

        case 0x0a000000u:
            if (!handle_opcode_0a(this, record, local_64)) abortToZero = true;
            break;

        case 0x0b000000u:
            handle_opcode_0b(this, record, local_58);
            break;

        case 0x0d000000u:
            handle_opcode_0d(this, record);
            break;

        case 0x13000000u:
            handle_opcode_13(this, record);
            break;

        case 0x14000000u:
            handle_opcode_14(this, record);
            break;

        case 0x15000000u:
            handle_opcode_15(this, record, abortToZero);
            break;

        case 0x16000000u:
            handle_opcode_16(this, record);
            break;

        case 0x18000000u:
            handle_opcode_18(this, record);
            break;

        /* Real "bind texture unit N" family - opcodes 0x19-0x1d, 0x1e-0x25, 0x26-0x2a. */
        case 0x19000000u: case 0x1a000000u: case 0x1b000000u: case 0x1c000000u: case 0x1d000000u:
        case 0x1e000000u: case 0x1f000000u: case 0x20000000u: case 0x21000000u: case 0x22000000u:
        case 0x23000000u: case 0x24000000u: case 0x25000000u:
        case 0x26000000u: case 0x27000000u: case 0x28000000u: case 0x29000000u: case 0x2a000000u:
            if (!handle_texture_bind(this, opcode, record, recordCount, byteOffset)) abortToZero = true;
            break;

        /* Real "unbind texture unit N" family - opcodes 0x2b/0x2c, 0x2d,
         * 0x2e-0x30, 0x31, 0x32-0x34, 0x35, 0x36-0x3c. `0x2d` and `0x35`
         * are CORRECTIONS to this project's own earlier accounting; 0x31
         * was already known to be real but had never actually been wired
         * to a handler (it was listed as "remaining" purely because no
         * dispatcher existed yet) - see file header note for the real
         * disassembly evidence for all three. */
        case 0x2b000000u: case 0x2c000000u:
        case 0x2d000000u:
        case 0x2e000000u: case 0x2f000000u: case 0x30000000u: case 0x31000000u:
        case 0x32000000u: case 0x33000000u: case 0x34000000u:
        case 0x35000000u:
        case 0x36000000u: case 0x37000000u: case 0x38000000u: case 0x39000000u:
        case 0x3a000000u: case 0x3b000000u: case 0x3c000000u:
            handle_texture_unbind(this, opcode, record);
            break;

        case 0x3e000000u:
            handle_opcode_3e(this, record);
            break;

        case 0x3f000000u:
            handle_opcode_3f(this, record);
            break;

        case 0x42000000u:
            handle_opcode_42(this, record);
            break;

        case 0x43000000u:
        case 0x44000000u:
            handle_opcode_43_44(this, record);
            break;

        case 0x46000000u:
            handle_opcode_46(this, record, local_60, local_5c);
            break;

        case 0x47000000u:
            handle_opcode_47(this, record, abortToZero);
            break;

        case 0x3d000000u:
            handle_opcode_3d(this, record);
            break;

        case 0x12000000u:
        case 0x17000000u:
            /* NOT YET TRANSCRIBED (issue #7 remains open for these two -
             * down from seven earlier this same pass; 0x14/0x15/0x16/0x18/
             * 0x3d are now done, see their own handlers above). Real,
             * disassembly-verified target addresses, ready for a future
             * pass: 0x12 -> 0x35c04 (~750 lines, the single largest
             * remaining gap in this whole function, comparable in scale
             * to GL's own largest opcode); 0x17 -> 0x372b4 (its opening
             * instructions are near-identical to opcode 0x16's own real
             * shape above - likely a similarly-dense multi-plane burst,
             * not independently confirmed - see this file's own header
             * note). Both have REAL, DISTINCT behavior on real hardware -
             * this fallthrough to the natural-distance default is a
             * KNOWN GAP, not a confirmed real no-op. Do not trust this
             * dispatcher for these two opcode values. */
            break;

        default:
            /* Real: an unrecognized opcode value is a plain pass-through
             * (LAB_00039028) - just consumes the record's own natural
             * distance, no other effect. */
            break;
        }

        if (abortToZero) {
            recordCount = 0;
            distance = 0;
        }

        record += distance;
        recordCount += distance;
        if (distance == 0) {
            if ((recordCount & 1) != 0) {
                *record = 0x80000000u;
                record += 1;
                recordCount += 1;
            }
            descriptor->pendingBufferStart = reinterpret_cast<void *>((byteOffset & 0xfffffffcu) + U32At(self, 0xa4) + 0x20);
            descriptor->pendingBufferOffset = byteOffset + U32At(self, 0x94) + 0x20;
            descriptor->pendingDwordCount = recordCount;
            descriptor->finalRecordCursor = record;
            return static_cast<IOReturn>(result);
        }
    } while (true);
}
