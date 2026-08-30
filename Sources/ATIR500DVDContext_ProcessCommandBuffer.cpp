/*
 * ATIR500DVDContext_ProcessCommandBuffer.cpp
 *
 * PARTIALLY RESOLVED (issue #7): the DVD context's own embedded
 * command-buffer opcode language. Real dispatch mechanism confirmed
 * (top-byte opcode over a `this+0xa4+0x1c`-based record stream,
 * self-consuming low-24-bit distance fields) and two real opcode
 * families - texture bind and texture unbind - fully transcribed from
 * complete real decompiles (kext offsets within
 * ATIR500DVDContext::process_command_buffer, 0x357c0). These two
 * families alone cover 33 of the real ~55 opcodes (bind: 0x19, 0x1a,
 * 0x1b, 0x1c, 0x1d, 0x1e-0x25, 0x26-0x2a, 0x2d; unbind: 0x2b, 0x2c, 0x2e-0x30,
 * 0x32-0x34, 0x36-0x3c).
 *
 * The remaining ~21 opcodes (0x02, 0x04-0x0d, 0x11-0x18, 0x31,
 * 0x35, 0x3d-0x3f, 0x42-0x44, 0x46-0x47) are dense per-mip YUV/tiling
 * math comparable in density to GL's own richest opcodes (real
 * floating-point double arithmetic, multiple format-table lookups per
 * opcode) - NOT transcribed this pass. `process_command_buffer` itself
 * is therefore NOT yet declared/assembled as one function - these two
 * handlers exist as free functions a future completed dispatcher will
 * call, matching how GL's own opcode-by-opcode effort progressed.
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
