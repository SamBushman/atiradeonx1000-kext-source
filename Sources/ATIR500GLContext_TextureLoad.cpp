/* NOTE 2026-09-19: 5 function bodies formerly in this file have been replaced by mechanical ports from the shipped kext's decompile (Sources/*_Port.cpp; marked
   "(re-ported mechanically: ...)" below). The analysis prose in this file describes the earlier hand-written bodies and is kept as history; see README.md,
   "How the code was produced". */
/*
 * ATIR500GLContext_TextureLoad.cpp
 *
 * FULLY RESOLVED (issue #5): all six of this project's remaining
 * declared-but-bodyless internal helpers - get_texture,
 * alloc_and_load_texture, compact_current_textures, submit_context_buffer,
 * convertIOGLBufferToBufIdx (a real free function, see
 * ATIR500GLContext.h), and finally load_texture itself - are now fully
 * decompiled and transcribed (real kext offsets 0x2b5f0, 0x2a3d0, 0x29dd0,
 * 0x2a8b0, 0x26ce0, and 0x29480 respectively). load_texture was the one
 * deliberately deferred across an earlier pass (large/dense, ~380 lines)
 * - see its own header comment below for the full real structure.
 *
 * Confidence: CONFIRMED for control flow and every field offset/call
 * touched - transcribed directly from complete real decompiles, not
 * summarized. Several sub-calls originally reached through raw
 * vtable-offset casts (accelerator vtable +0x524/+0x528/+0x54c,
 * IOATIR500Surface vtable +0x5c4/+0x5cc/+0x5d0) are now RESOLVED (issues
 * #18/#19) to real named methods - see ATIRadeonX1000.h/ATIR500Surface.h.
 * Two more used only by load_texture at +0x14c/+0xd0/+0x18 on a real
 * "memory-descriptor-shaped" object (see
 * ATIR500GLContext_DiscardBuffer.cpp's matching cross-reference) - real
 * class identity RESOLVED, issues #20/#24: this is the texture's own
 * `memoryDescriptor` field (`tex+8`, `ATIRadeonX1000Types.h`), already
 * independently CONFIRMED elsewhere in this project to be Apple's own
 * external `IOMemoryDescriptor` (retain/release at +0x14/+0x18) - +0x14c/
 * +0xd0 are real (unnamed) `IOMemoryDescriptor` methods this project has
 * not further identified, but the RECEIVER's own class is no longer in
 * question.
 * get_texture's atomic decrement loop was verified against raw PPC
 * disassembly (lwarx/stwcx.), not just Ghidra's decompile, since the
 * decompiler couldn't fully resolve it into clean C on its own.
 * load_texture's own deepest per-tile register-burst math (particularly
 * its "linear" tiling path's per-level hwShiftA/hwShiftB recurrence and
 * its LOD-bias computation's own `pAVar22`-shaped struct) is transcribed
 * faithfully but, like write_kernel_context_buffer_regs and
 * restore_state_destroyed_by_pageoff elsewhere in this project, dense
 * enough to warrant an independent spot-check before being fully trusted
 * bit-for-bit - see load_texture's own header comment for specifics.
 */

#include "../Headers/ATIR500GLContext.h"
#include "../Headers/IOATIR500Surface.h"
#include "../Headers/ATIRadeonX1000.h"
#include "../Headers/ATIRadeonX1000Types.h"
#include "../Headers/ATIRadeonX1000PPCIntrinsics.h"
#include <libkern/OSAtomic.h>

/*
 * get_texture - CONFIRMED, fully transcribed (real kext offset 0x2b5f0).
 * Real, previously-guessed-at behavior now confirmed: on a real "needs
 * reload" flag (texture's mip record + 0x14, a byte), submits a real
 * backward-indexed PM4 header + `record` payload via
 * ATIRadeonX1000::submit_buffer, then calls alloc_and_load_texture and,
 * if the accelerator is mid-pageoff (accel+0xb90 != 0), calls
 * restore_state_destroyed_by_pageoff. Otherwise (or after), if
 * this+0xd0 is still unset, calls map_transfer_to_GART.
 *
 * Real, notable finding: an ATOMIC decrement-by-0xffff (PPC lwarx/
 * stwcx. retry loop, not a plain load-modify-store - Ghidra's own
 * decompile couldn't resolve this into clean C, represented via
 * pseudo-registers instead) on a 32-bit word at the mip record's own
 * +0x10 field, unconditional (runs whether or not the reload branch
 * above ran). -0xffff = -0x10000+1, i.e. this simultaneously decrements
 * a count packed in the high 16 bits and increments one in the low 16
 * bits - real evidence of a packed dual-counter field, exact meaning of
 * either half UNKNOWN.
 *
 * Finally, if the texture has a nonzero value at +0x48, splices it out
 * of whatever real doubly-linked list it's currently on and re-inserts
 * it at the head of a real list embedded in the accelerator object
 * (head pointer at accelerator+0x600, an embedded sentinel node at
 * accelerator+0x5dc) - a real, previously-undocumented accelerator-
 * level structure (plausibly the orphan-texture list
 * IOATIR500Accelerator::addOrphanTexture already references
 * conceptually; not confirmed to be the same list this pass).
 */
/* (re-ported mechanically: see ATIR500GLContext_get_texture_Port.cpp) */


/*
 * A small real helper this function's four near-identical branches all
 * call before splicing a buffer into the accelerator's transfer-buffer
 * list (accelerator+0x6d0 head / +0x69c sentinel - the SAME real
 * circular-doubly-linked-list shape get_texture uses on the texture
 * list at +0x600/+0x5dc, just a different instance for transfer
 * buffers). Real address 0x2a864. RESOLVED, issue #15 (live
 * kxld-resolved memory read on real G5/Tiger hardware, cross-referenced
 * against the running kernel's own symbol table): the real target is
 * `IOGetTime(mach_timespec_t *)`, NOT a GART-mapping helper as this
 * project's earlier call-site-pattern inference guessed (a real
 * correction) - it stamps the current time into the node's own `+0x2c`
 * field, consistent with a per-node timestamp for transfer-list
 * aging/LRU. Same real target as 2D's FUN_000334cc and DVD's
 * FUN_0003913c below.
 */
extern "C" void FUN_0002a864(void *timestampField) asm("_IOGetTime");
/* Same real target, second distinct decompiled call site (real address
 * 0x29da8) - see load_texture's own use below. Declared here at file
 * scope rather than locally inside that function: gcc-4.0.1 (FIXED,
 * issue #1, first build attempt) does not accept an asm-label rename on
 * a local `extern` declaration inside a function body - only at file
 * scope, matching FUN_0002a864 immediately above. */
extern "C" void FUN_00029da8(void *timestampField) asm("_IOGetTime");

/*
 * Two more real accelerator vtable calls alloc_and_load_texture makes -
 * RESOLVED, issue #19/#23: `ATIRadeonX1000::allocate_texture`/
 * `::deallocate_texture` (see ATIRadeonX1000.h and
 * Sources/ATIRadeonX1000_TextureVRAM.cpp for the real bodies). Called
 * directly through the typed `accelerator` member below rather than the
 * raw vtable-offset casts this project previously used here.
 * `deallocate_texture`'s real signature CORRECTED, issue #23: takes a
 * real `VendorTextureBuffer*` parameter - the two real call sites below
 * were passing none at all, fixed to pass the real texture in scope at
 * each site.
 */

/*
 * alloc_and_load_texture - RESOLVED (issue #5), fully transcribed (real
 * kext offset 0x2a3d0). REAL RETURN TYPE CORRECTED to `void` (was
 * declared `IOReturn`) - see ATIR500GLContext.h.
 *
 * An 8-way dispatch on the texture's own type-discriminant byte
 * (`texture+0x20` - the same real discriminant
 * Sources/IOATIR500GLContext_TextureStream.cpp's header already
 * documents at least six values for; this function is real evidence
 * for values 0/1/2/3/6/7/8 specifically). Real per-type behavior:
 *   - 0 (surface-backed): resolves/caches the real IOATIR500Surface via
 *     find_surface_for_id if not already cached, checks two real bitmask
 *     gates, and on a real mask hit calls IOATIR500Surface::
 *     alloc_surfaces_keep then compact_current_textures.
 *   - 1 (chained/aliased reference): real, direct RECURSION - calls
 *     itself on the real linked texture at +0x50 (confirms this
 *     project's earlier characterization of type 1 as "recursive").
 *   - 2, 6, 8: near-identical real "timestamp, then splice into the
 *     accelerator's transfer-buffer list" bodies (via the real
 *     FUN_0002a864/`IOGetTime` helper above, RESOLVED issue #15).
 *   - 3, 7: real "free VRAM for this texture, then compact" paths -
 *     type 7 additionally handles a real "already pending eviction" bit
 *     (texture's mip-record byte, bit 1) before retrying.
 *   - default: no-op.
 * Falls through to `load_texture` (this issue's other resolved
 * function) whenever the type-specific path doesn't return early.
 */
/* (re-ported mechanically: see ATIR500GLContext_alloc_and_load_texture_Port.cpp) */


/*
 * Three more real IOATIR500Surface vtable calls compact_current_textures
 * makes - RESOLVED, issue #18: dealloc_surface/invalidate/
 * alloc_surface_buffer (see Headers/IOATIR500Surface.h). Called directly
 * via ordinary virtual dispatch below rather than the raw vtable-offset
 * casts this project previously used here.
 */

/*
 * A real, shared eviction-scan sub-routine compact_current_textures
 * inlines twice for two different surfaces (once per already-bound slot
 * being evicted, once for the newly-requested texture's own surface).
 * Real body: walks a real 0x17-entry (23) `ATIR500SurfaceBuffer`-sized
 * (0x78 stride) array at `surface+0xa8`, and for each entry whose real
 * gating condition holds (a mix of `surface+0xc14 == 0xffff`, an index
 * range check, `entry+8 != 0`, and a `surface+0xbd0` high-word/pointer-
 * identity check), either moves it to backing store or calls the real
 * `dealloc_surface` method with a "reason" code - then, after the whole
 * scan, calls the real `invalidate` method once (both RESOLVED, issue
 * #18). Extracted here as a named helper purely for this
 * reconstruction's own readability - the real binary has it inlined at
 * both real call sites, not factored out.
 */
static void evictSurfaceBuffers(IOATIR500Surface *surface, UInt32 reasonCode) {
    UInt8 *surf = reinterpret_cast<UInt8 *>(surface);
    UInt8 *entry = surf + 0xa8;
    for (UInt32 i = 0; i <= 0x16; i++, entry += 0x78) {
        bool indexGate = (*reinterpret_cast<SInt32 *>(surf + 0xc14) == 0xffff) ||
                          (i > 1 && (i - 4) > 1);
        bool entryLive = *reinterpret_cast<UInt32 *>(entry + 8) != 0;
        bool identityGate = (*reinterpret_cast<UInt32 *>(surf + 0xbd0) & 0xffff0000u) == 0 ||
                             (reinterpret_cast<void *>(entry) != *reinterpret_cast<void **>(surf + 0xb70));
        if (indexGate && entryLive && identityGate) {
            if (*reinterpret_cast<UInt32 *>(surf + 0xd48) == 0) {
                surface->move_buffer_to_backing_store(reinterpret_cast<ATIR500SurfaceBuffer *>(entry));
            } else {
                surface->dealloc_surface(reasonCode);
            }
        }
    }
    surface->invalidate();
}

/*
 * compact_current_textures - RESOLVED (issue #5), fully transcribed
 * (real kext offset 0x29dd0). REAL RETURN TYPE CORRECTED to a real
 * value (was declared `void`) - see ATIR500GLContext.h.
 *
 * Real structure: a 42-entry (0x2a) scan over the texture-slot array at
 * this+0x2a4 (the SAME array IOATIR500GLContext::start zero-initializes
 * - see issue #10's Sources/IOATIR500GLContext_Start.cpp), evicting
 * every currently-bound texture's surface buffers (via the shared
 * evictSurfaceBuffers helper above) and unlinking each from a real
 * doubly-linked list at its mip-record's own +0x24/+0x28 fields. If the
 * requested texture (`texture`) wasn't itself found in that scan, it
 * gets the same eviction-and-unlink treatment on its own. Then calls
 * `invalidate()` (RESOLVED issue #12.1), advances a real 4-bit rotating
 * ring-buffer-slot index (this+0x28c), and re-walks the SAME 42-entry
 * array a second time to rebuild and resubmit a real vertex/texture
 * offset table via WriteTextureOffset/WriteVertexArrayOffset/
 * ATIRadeonX1000::submit_buffer - reloading each surviving texture from
 * its own backing store (or calling `load_texture`) along the way.
 * Finally ensures the originally-requested texture's own surface is
 * reloaded before returning success/failure.
 */
/* (re-ported mechanically: see ATIR500GLContext_compact_current_textures_Port.cpp) */


/*
 * submit_context_buffer - RESOLVED (issue #5), fully transcribed (real
 * kext offset 0x2a8b0). Real structure: first walks the SAME 42-entry
 * texture-slot array (this+0x2a4) as compact_current_textures, reloading
 * (alloc_and_load_texture + invalidate()) any texture whose mip record
 * is flagged dirty, then re-links any texture with a nonzero +0x48 into
 * the accelerator's texture list (accelerator+0x600/+0x5dc - the same
 * real list get_texture uses).
 *
 * Then checks the dirty bit `invalidate()` sets (this+0x108's own +0x1c,
 * bit 0) - RESOLVED cross-reference confirming exactly what that bit is
 * for: if clear, just reuses the current ring-buffer slot's existing
 * buffer pointer; if set, this is the real "flush" path - advances the
 * 4-bit rotating ring-buffer slot (same pattern as
 * compact_current_textures), copies an 8-dword header plus a real
 * variable-length payload out of the pending-writes queue object at
 * this+0x108 into the new ring slot's buffer, calls
 * write_kernel_context_buffer_regs to append the live register state,
 * walks the FIRST 16 (not all 42) texture slots writing their offsets,
 * appends a real trailing PM4 header (`0x1040`/`0`) plus alignment
 * padding, records the real dword count on the ring slot's own buffer
 * object, then clears the dirty bit.
 *
 * Either way, ensures the ring slot is GART-mapped and submits it via
 * ATIRadeonX1000::submit_buffer, recording the result both on the ring
 * slot (+0x11c) and on this+0x7c (a field this project has not
 * independently named).
 */
/* (re-ported mechanically: see ATIR500GLContext_submit_context_buffer_Port.cpp) */


/*
 * load_texture - RESOLVED (issue #5), fully transcribed (real kext offset
 * 0x29480). This is the deferred function - see this file's own header
 * and GAPS.md for why it was split from its now-resolved siblings.
 *
 * Real structure, in order:
 *
 * 1. Dirty-mip scan: for each of the texture's `faceCount` faces (mip[0x34],
 *    a byte - almost certainly cubemap face count, 1 or 6 in practice) and
 *    each mip level in [baseLevel, baseLevel+levelCount-1] (mip[0x17],
 *    mip[0x35]), tests bit `level` of `(dirtyBits & ~loadedBits)` where
 *    dirtyBits/loadedBits are per-face UInt16 fields at `mip + face*2 +
 *    0x1c` / `mip + face*2 + 0x28` respectively - CONFIRMED CROSS-REFERENCE:
 *    the `+0x28` array (up to 6 UInt16 entries, one per face) is the exact
 *    same memory `alloc_and_load_texture`/`compact_current_textures` clear
 *    to zero via their six explicit `mip[0x28]..mip[0x32] = 0` writes during
 *    eviction. If no face/level combination is dirty-and-unloaded, returns
 *    immediately (nothing to do).
 *
 * 2. GART-mapping prep: calls a real vtable method at offset 0x14c on the
 *    texture's `memoryDescriptor` field (VendorTextureBuffer+0x08, per
 *    ATIRadeonX1000Types.h) - the SAME real vtable slot
 *    Sources/ATIR500GLContext_DiscardBuffer.cpp's header already flags as
 *    "a real vtable method... to (re)establish a real backing mapping" on
 *    opcode 0x3b's cleanup path (issue #12 item 3) - this is a second,
 *    independent real call site for that same slot, with concrete argument
 *    values, though still not independently named (opaque call, matching
 *    this project's no-shortcuts standard). Returns null on failure (early
 *    return). The resulting handle's own vtable+0xd0 (no extra args) then
 *    returns `hwInfo`, a heavily-indexed per-mip/tile hardware-tiling
 *    descriptor this function reads extensively - CONFIRMED this handle is
 *    released via vtable+0x18 right before returning (matches the
 *    `gartMapping`/`memoryDescriptor` struct comment's established
 *    "released via vtable+0x18" pattern).
 *
 * 3. Per-texture-type dispatch (type 3 / type 7 / anything else) computing
 *    `payloadByteLen` and an initial `tileXBase` value - types 3 and 7 both
 *    real-splice a transfer buffer into the accelerator's transfer-buffer
 *    list (accelerator+0x6d0/+0x69c, the SAME list alloc_and_load_texture's
 *    `spliceIntoTransferList` uses) via a SEPARATE small helper at real
 *    address 0x29da8 - RESOLVED, issue #15: `IOGetTime` (own per-call-site
 *    stub instance of the same real target as `FUN_0002a864` above).
 *
 * 4. Real completion-stamp accumulation via ATIRadeonX1000::waitForTimeStamp
 *    (RESOLVED, issue #19; accelerator+0x744 += stamp(mip+0xc)) - the SAME real call
 *    `compact_current_textures`/`restore_state_destroyed_by_pageoff` make
 *    against a different accumulator field (+0x780); this one is specific
 *    to texture loads. `record` (the PM4 burst output buffer) is then
 *    computed as `hwInfo + 0xa00` bytes - CONFIRMED CROSS-REFERENCE: this
 *    exact `+0xa00` constant reappears in both of this function's own
 *    `submit_buffer` calls at the tail (`tex+4 (GART address) + 0xa00`),
 *    confirming `hwInfo` is the kernel-mapped view of the same GART
 *    allocation the texture's own +4 field addresses.
 *
 * 5. A real two-way branch on `hwInfo[8]`'s sign bit (real offset 0x20,
 *    tested as `< 0`) - real evidence of two genuinely different tiling
 *    code paths (informally "macro-tiled" vs "linear" below, not real
 *    driver terminology, chosen for readability):
 *
 *    - Path A (hwInfo[8] < 0): walks all faces/levels again, building a
 *      3-field-per-tile register burst (an "enable" marker plus X/Y base
 *      addresses, or a "disabled" marker if the level is out of the
 *      dirty-and-unloaded set), reading a per-tile record at `hwInfo +
 *      tileIndex*0x20` (tileIndex = face*13+level) with fields at +0x40
 *      (UInt16, output DWORD slot), +0x42 (UInt16, repeat count), +0x44/
 *      +0x48 (SInt32 X/Y base), +0x4c/+0x50 (SInt32 X/Y stride). Marks
 *      each face's levels loaded (`loadedBits |= dirtyBits`) as it goes.
 *      Finishes with a real LOD-bias register computation read from a
 *      SEPARATE per-context "current surface buffer entry" pointer
 *      (`pAVar22` in the raw decompile) whose own real field layout
 *      (+0x08/+0x14/+0x16/+0x20/+0x38/+0x3c, plus a 2-entry SInt32 array at
 *      +0x40) is UNKNOWN beyond what this one computation implies -
 *      genuinely reached via two different real source expressions
 *      depending on `this+0x3bc`, both eventually indexing the same
 *      `surface+idx*4+0xb70`-shaped array `compact_current_textures`
 *      already uses for `ATIR500SurfaceBuffer` lookups (plausible, not
 *      confirmed, that `pAVar22` IS an `ATIR500SurfaceBuffer*`).
 *
 *    - Path B (hwInfo[8] >= 0): offsets `record` forward by `hwInfo[1]`
 *      dwords (a real "header size" - the matching `submit_buffer` call
 *      below re-adds the same offset when computing the GART address, a
 *      direct confirmation), writes one fixed dword (`record[0xb] =
 *      accelerator+0xb74`), then runs a real small state machine on
 *      `mip[0x15]`'s upper bits and `hwInfo[0x1a]` (a byte) to pick one of
 *      three `(tileMode, tileParam)` pairs - transcribed as clean
 *      structured code below; the raw decompile's own label soup
 *      (LAB_00029a5c/LAB_00029a64/LAB_00029a94) was verified by hand to
 *      collapse to exactly this if/else-if/else with no behavior change.
 *      Then a face/level double loop writes a real 5-field-per-repeat
 *      register burst per tile (fields at relative dword offsets +1/+3/+5/
 *      +9 within a 0x1d-dword stride, packing hwInfo[0x1b] and evolving
 *      per-level shift values `hwShiftA`/`hwShiftB` whose own recurrence -
 *      each level's value is `max(a fixed floor, half of the previous
 *      level's value)` - is transcribed exactly as decompiled but NOT
 *      independently re-verified against raw disassembly. Sets
 *      accelerator+0xb90 = 1 at the end - CONFIRMED CROSS-REFERENCE: this
 *      is the exact same "mid-pageoff" flag `get_texture` checks before
 *      calling `restore_state_destroyed_by_pageoff`, and that
 *      `submit_context_buffer` clears at its own start - Path B is the
 *      real producer of that flag.
 *
 * 6. Shared tail: pads `record` to an even dword count (writing a
 *    `0x80000000` terminator if needed), accumulates
 *    accelerator+0x704/+0x71c (byte-count and payload-length accumulators,
 *    the same +0x704 field `compact_current_textures`/
 *    `submit_context_buffer` also accumulate), submits via
 *    `ATIRadeonX1000::submit_buffer` (base GART address differs by
 *    `hwInfo[1]*4` between the two tiling paths, matching the Path-B-only
 *    forward offset applied to `record` above), stores the result on
 *    `mip+0xc` (the same field the completion-stamp call above reads), and
 *    for type 7 propagates that same value into a second, real but
 *    UNKNOWN-precision field reached through the type's own inner transfer
 *    buffer (two pointer indirections deep - arithmetic transcribed
 *    faithfully, exact struct identity not independently confirmed).
 *    Finally releases the GART-mapping handle from step 2 via vtable+0x18.
 *
 * Confidence: CONFIRMED for the overall structure, every real offset and
 * cross-referenced field, and both submit_buffer call sites.
 * INDEPENDENT SPOT-CHECK COMPLETE: re-decompiled fresh from Ghidra and
 * compared line-by-line against this committed transcription, including
 * Path A's LOD-bias formula (a real operator-precedence trap - the raw
 * `>> 10 |` chain only parses correctly if `>>` binds every preceding
 * `+`/`*` term together before the `|`s apply, exactly as this
 * transcription's explicit parenthesization already had it) and Path B's
 * per-level `hwShiftA`/`hwShiftB` recurrence (a real two-step reassignment
 * where the SAME raw variable is read at an intermediate value before its
 * own final reassignment - also already correct here). ONE REAL BUG FOUND
 * AND FIXED: Path B's per-tile output-slot offset was `tile + 0x18`,
 * should be `tile + 0x58` (`*(ushort*)(hwInfo + tileIndex*8 + 0x16)` on an
 * `int*`-typed local - real byte offset `tileIndex*0x20 + 0x58`, not
 * `+0x18` - a real instance of this project's own documented
 * `int*`-scaling trap that slipped through the original transcription).
 * Real per-tile struct field names beyond what's cross-referenced above
 * are UNKNOWN; kept as raw byte offsets rather than invented names, per
 * this project's standard.
 */
/* (re-ported mechanically: see ATIR500GLContext_load_texture_Port.cpp) */

