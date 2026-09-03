/*
 * ATIR500DVDContext_ProcessCommandBuffer.cpp
 *
 * PARTIALLY RESOLVED (issue #7): the DVD context's own embedded
 * command-buffer opcode language. Real dispatch mechanism confirmed
 * (top-byte opcode over a `this+0xa4+0x1c`-based record stream,
 * self-consuming low-24-bit distance fields) and EIGHT real opcode
 * groups - texture bind, texture unbind, the opcode 0x2 return-code
 * setter, the opcode 0x5/0x6 texture-sampler-state pair, opcodes
 * 0xa/0xb/0xd's own per-mip YUV/tiling setup, and the opcode 0x4
 * explicit-flush - fully transcribed from complete real decompiles
 * (kext offsets within ATIR500DVDContext::process_command_buffer,
 * 0x357c0). Together these cover 41 real opcodes with genuine handlers
 * (bind: 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e-0x25, 0x26-0x2a, 0x2d;
 * unbind: 0x2b, 0x2c, 0x2e-0x30, 0x32-0x34, 0x36-0x3c; plus 0x02, 0x04,
 * 0x05, 0x06, 0x0a, 0x0b, 0x0d), plus four more (0x07, 0x08, 0x09,
 * 0x0c) confirmed to be trivial abort paths with NO real handler at
 * all - re-reading the raw decompile's brace structure precisely (not
 * just its surface `goto` targets) showed 0xc in particular was
 * wrongly assumed part of the "0xa/0xb/0xc/0xd cluster" by this
 * project's own earlier skeleton-mapping pass; corrected here.
 *
 * CORRECTION to this project's own earlier opcode-range accounting:
 * DVD has NO real opcode 0x11 at all (an earlier pass's "remaining
 * opcodes" list wrongly included it, apparently carried over by
 * mistake from the UNRELATED opcode 0x11 this project already
 * resolved on the 2D context - a real, different opcode language).
 * Grepping the complete raw decompile for every real `uVar17 ==/!=
 * 0x??000000` comparison confirms DVD's own opcode 0x12 is the
 * smallest value in that neighborhood actually dispatched on.
 *
 * Real, high-value finding this pass: opcode 0x12's own real body
 * spans roughly 750+ lines of raw decompile (loop-based, multiple
 * fixed-size local arrays, dense per-plane geometry math) - comparable
 * in scale to GL's own opcode 0x2d, which this project's history
 * explicitly flagged as "the single largest remaining gap" in the
 * entire GL reconstruction (CORRECTED, issue #12 item 4: that content
 * was known as "opcode 0x31" at the time this comment was written, but
 * has since been found to really be opcode 0x2d - the REAL, separate
 * GL opcode 0x31 is much smaller, ~180 lines, and is now fully
 * transcribed - see ATIR500GLContext_ProcessCommandBuffer.cpp's
 * handle_depth_buffer_resolve). NOT attempted this pass; a correct
 * transcription needs its own dedicated pass, not a continuation of
 * this session's per-opcode cadence.
 *
 * The remaining ~18 real opcodes (0x12 [very large, see above], 0x14-
 * 0x18, 0x31, 0x35, 0x3d-0x3f, 0x42-0x44, 0x46-0x47) were NOT
 * transcribed this pass. Continuing reliably needs a more rigorous
 * method than this pass's manual brace-reading of the raw decompile -
 * that method already produced two real opcode-boundary mistakes this
 * session (0x1d wrongly modeled as separate from the bind family in an
 * earlier commit, and 0x11 wrongly carried into this file's own
 * "remaining" list) that needed correcting after the fact. A future
 * pass should cross-check routing against the real compiled branch
 * instructions (raw disassembly), not decompiled C brace nesting
 * alone, before trusting an opcode boundary. `process_command_buffer`
 * itself is therefore NOT yet declared/assembled as one function -
 * these handlers exist as free functions a future completed dispatcher
 * will call, matching how GL's own opcode-by-opcode effort progressed.
 *
 * Confidence: CONFIRMED for control flow and every field offset/call
 * touched in the two transcribed handlers - complete real decompiles,
 * not summarized. `FUN_0003911c` (a real refcount-style helper - every
 * call site gates `delete_texture` on it returning exactly 1, "this was
 * the last reference") and `FUN_0003913c` (the same real "ensure
 * GART-mapped" idiom as GL's FUN_0002a864/2D's FUN_000334cc) are called
 * opaquely. `FUN_000390dc` is called with a literal `0xffff0001` first
 * argument - the exact same bit pattern as the real atomic
 * packed-counter update this project independently verified via raw
 * PPC disassembly in GL's own get_texture (issue #5); a striking match,
 * but NOT independently re-verified against DVD's own disassembly this
 * pass, so called opaquely rather than assumed identical.
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
 */
static void handle_texture_bind(ATIR500DVDContext *ctx, UInt32 opcode, UInt32 *record,
                                 UInt32 &recordCount, UInt32 &byteOffset) {
    UInt8 *self = reinterpret_cast<UInt8 *>(ctx);
    UInt8 *accel = reinterpret_cast<UInt8 *>(ctx->accelerator);
    UInt8 *shared = reinterpret_cast<UInt8 *>(ctx->sharedAllocator);

    UInt32 idx = record[1];
    if (idx >= U32At(shared, 0x14)) return; /* real: falls through to the shared "no match" skip path */
    UInt8 *transferBuf = *reinterpret_cast<UInt8 **>(reinterpret_cast<UInt8 *>(U32At(shared, 0x10)) + idx * 4);
    if (transferBuf == nullptr) return;

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
 * the surface-field/height-delta precondition) - the caller should
 * treat this exactly like a real bounds-check failure elsewhere in
 * this file (reset to the shared trivial-abort path).
 */
static bool handle_opcode_0a(ATIR500DVDContext *ctx, UInt32 *record) {
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

    UInt32 local_64 = 0; /* real: uninitialized read in the raw decompile - see header note */
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
 * tiling-word computation (including the same honestly-flagged
 * uninitialized-`local_58`-read anomaly - see handle_opcode_0a's
 * header note; the same pattern recurring here independently
 * reinforces that this is a real driver/compiler artifact, not a
 * one-off transcription mistake).
 *
 * Real, notable finding: opcode 0xc (numerically adjacent, and
 * originally assumed part of this "0xa/0xb/0xc/0xd cluster" by this
 * project's own earlier skeleton-mapping pass) turns out to have NO
 * real handler at all - re-reading the raw decompile's brace structure
 * precisely shows 0xc falls straight through to the same trivial-abort
 * path as a genuinely-unrecognized opcode value. Corrected here rather
 * than left as a stale assumption.
 */
static void handle_opcode_0b(ATIR500DVDContext *ctx, UInt32 *record) {
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

    UInt32 local_58 = 0; /* real: uninitialized read in the raw decompile - see handle_opcode_0a's header note */
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
