/*
 * IOATIR500Surface_LockShape.cpp
 *
 * RESOLVED (issue #8, fully closed): the lock/unlock family's real
 * internal shape, PLUS (in a later pass) the shape/ID-assignment family -
 * every one of Surface's 19 real external methods now has real
 * decompiled content behind it. The lock/unlock six are thin,
 * fully-transcribed forwards into two shared internal helpers,
 * `surface_lock_options`/`surface_unlock_options` (declared in
 * IOATIR500Surface.h, bodies NOT independently decompiled this pass),
 * plus the two genuinely internal (non-external-method) helpers
 * `surface_write_lock_int`/`surface_write_unlock_int`. The shape/ID
 * family - `set_id_mode`, `set_shape_backing`, `set_shape_backing_length`,
 * and the shared `set_shape_backing_length_ext` they tail-call - is much
 * denser; see each function's own header comment below for its full
 * writeup, including two real transcription bugs this project caught and
 * fixed on its own re-review (a swapped parameter pair in
 * `set_shape_backing_length_ext`, and a dword-index-vs-byte-offset
 * scaling bug matching the exact class already found and fixed in issue
 * #12 item 6).
 *
 * Confidence: CONFIRMED for every function transcribed here - real,
 * complete decompiles (or, for the two thin shape-backing forwards whose
 * arguments Ghidra's own no-analysis decompile couldn't recover, the raw
 * PPC disassembly directly), not summarized.
 */

#include "../Headers/IOATIR500Surface.h"
#include "../Headers/ATIRadeonX1000.h"
#include "../Headers/ATIRadeonX1000Types.h"

/* (re-ported mechanically: see IOATIR500Surface_surface_write_unlock_Port.cpp) */


/* (re-ported mechanically: see IOATIR500Surface_surface_write_unlock_options_Port.cpp) */


/* (re-ported mechanically: see IOATIR500Surface_surface_write_lock_Port.cpp) */


/* (re-ported mechanically: see IOATIR500Surface_surface_write_lock_options_Port.cpp) */



IOReturn IOATIR500Surface::surface_read_lock_options(UInt32 lockOptions, IOAccelSurfaceData *data, UInt32 size) {
    return surface_lock_options(static_cast<eLockType>(1), lockOptions, data, size);
}


/*
 * set_scale - CONFIRMED, fully transcribed (real kext offset 0x159f0).
 * REAL SIGNATURE CORRECTION: takes a real `IOAccelSurfaceScaling*`
 * (this project had guessed raw `UInt32 xScale, UInt32 yScale` instead
 * - a real structural error, not just a naming gap). Real body: only
 * accepts `param3 == 0 || param3 == 0x2c` (an INFERRED "real struct
 * size" gate - 0x2c matches a plausible real IOAccelSurfaceScaling
 * size on this 32-bit target, not independently confirmed against
 * Apple's own header this pass); on a gate pass, takes the accelerator
 * lock (this+0xd50's own +0x840, the same real lock field
 * ATIRadeonX1000.h documents as `commandLock`), calls the already-
 * declared `set_scaling`, and releases the lock.
 */
/*
 * Real, locally-generated lock/unlock helper pair set_scale calls
 * around set_scaling (real addresses 0x15aa4/0x15a84, immediately
 * after set_scale's own body) - the same "FUN_xxxx(lockPtr)" pattern
 * this project already documents for ATIR500GLContext::start's
 * FUN_000286dc/ec and discard_command_buffer's own lock pair: each
 * real caller gets its own small lock/unlock function taking the real
 * commandLock pointer (this+0xd50's own +0x840 here) as sole argument,
 * rather than one shared helper. RESOLVED, issue #15 (live kxld-resolved
 * memory read on real G5/Tiger hardware, cross-referenced against the
 * running kernel's own symbol table - see
 * `Headers/ATIRadeonX1000Registers.h`): both are real external XNU
 * kernel primitives, `mutex_lock`/`mutex_unlock_rwcmb`, aliased below via
 * their real symbol names.
 */
extern "C" void FUN_00015aa4(void *lockPtr) asm("_IOLockLock");
extern "C" void FUN_00015a84(void *lockPtr) asm("_IOLockUnlock");


IOReturn IOATIR500Surface::set_scale(UInt32 flags, IOAccelSurfaceScaling *scaling, UInt32 param3) {
    if (param3 != 0 && param3 != 0x2c) {
        return 0xe00002c2; /* real: kIOReturnBadArgument-family literal, same constant used elsewhere in this project */
    }

    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *accel = *reinterpret_cast<UInt8 **>(self + 0xd50);
    bool passedScaling = (param3 != 0); /* real: `bVar2` gate, INFERRED role from the real decompile's own inverted-bit encoding */

    FUN_00015aa4(*reinterpret_cast<void **>(accel + 0x840));
    IOReturn result = set_scaling(flags, passedScaling ? scaling : nullptr);
    FUN_00015a84(*reinterpret_cast<void **>(accel + 0x840));
    return result;
}


/*
 * surface_write_lock_int / surface_write_unlock_int - CONFIRMED, fully
 * transcribed (real kext offsets 0x114a0/0x11540). Real per-buffer
 * lock/unlock around a mip/buffer record at this+bufferIndex*4+0xb70
 * (the SAME real per-mip array shape ATIR500GLContext::build_scissor
 * and friends index via a texture's own +0xb70 field - here indexed
 * directly off the surface object itself). Real vtable calls at
 * +0x5fc (lock) / +0x600 (unlock) are RESOLVED (issue #18):
 * `prepare_vram`/`complete_vram` (Headers/IOATIR500Surface.h) -
 * surface_write_lock_int additionally does real completion-counter
 * bookkeeping via `ATIRadeonX1000::sleepForTimeStamp` (RESOLVED, issue
 * #19) on this+0xd50 (mirrors the same real "stamp delta" pattern
 * ATIR500GLContext::compact_current_textures/submit_context_buffer use
 * on their own accelerator pointer, at the same waitForTimeStamp/
 * sleepForTimeStamp family - see Sources/ATIR500GLContext_TextureLoad.cpp).
 */

/* (re-ported mechanically: see IOATIR500Surface_surface_write_lock_int_Port.cpp) */


/* (re-ported mechanically: see IOATIR500Surface_surface_write_unlock_int_Port.cpp) */


namespace {
inline UInt32 &U32At(void *base, int offset) { return *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt16 &U16At(void *base, int offset) { return *reinterpret_cast<UInt16 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt8  &U8At(void *base, int offset)  { return *(reinterpret_cast<UInt8 *>(base) + offset); }
} // namespace

/*
 * set_id_mode - RESOLVED (issue #8), fully transcribed (real kext offset
 * 0x142b0). Real signature CONFIRMED via direct disassembly of the
 * function's own prologue (this=r3, mode=r4, modeBits=r5 - matches the
 * already-declared 2-parameter header signature exactly; Ghidra's own
 * no-analysis decompile mislabeled the second parameter "param_3" for
 * unrelated internal reasons - a real 3-name/2-register mismatch this
 * project caught and corrected rather than trusting blindly).
 *
 * Real structure: assigns this surface a real "ID slot" (an index into a
 * real, accelerator-owned, id*0x20-strided pointer table at
 * accelerator+0xe8, bounded by accelerator+0xcc) with an associated real
 * "kind" byte (a small hardcoded 4-bit-selector -> kind-code table,
 * cross-checked against a real per-ID kind array at
 * accelerator+id*0x78+0x142), tracks the assignment on both this surface
 * (+0xa4/+0xbe8/+0xc14/+0xc1c) and the accelerator's own table, allocates
 * or reuses a small (0xc-byte) per-ID tracking record (the accelerator's
 * own +0x804 byte-accounting field is adjusted alongside), copies two
 * real per-ID halfword fields (accelerator+id*0x78+0x148/+0x14a) into
 * both that record and a pair of this-surface fields (+0xbd4/+0xbd8 and
 * +0xbd6/+0xbda respectively - each written twice, to what look like a
 * "current" and "requested" copy of the same value), calls a real vtable
 * method at this-object's own +0x5dc (role INFERRED: "commit ID
 * assignment," given it gates a real "assignment succeeded" flag write on
 * success), then real backing-store allocation bookkeeping
 * (prune_buffers, a size/handle selection from this+0xb8/+0x130 gated on
 * this+0xc1c's own low bits, and - if nonzero - a real accelerator
 * vtable+0x540/+0x544 allocate/commit pair using a 4-dword local struct -
 * the SAME real vtable pair `set_shape_backing_length_ext` below
 * independently uses for the same purpose). Runs the whole thing under
 * the accelerator's real commandLock (this+0xd50's own +0x840, the SAME
 * lock `set_scale` already uses - see this file's earlier comment), via
 * ANOTHER real per-call-site lock/unlock trampoline pair
 * (FUN_00014850/FUN_000147f0, same established pattern as
 * FUN_00015aa4/FUN_00015a84 for `set_scale` - RESOLVED, issue #15:
 * `mutex_lock`/`mutex_unlock_rwcmb`, same real pair).
 *
 * Two more real helper calls, RESOLVED issue #15: FUN_00014820(size,
 * align) is the real kernel allocator `IOMallocAligned`, called with
 * literal args `(0xc, 0x20)` - and FUN_00014810(ptr, size) is its
 * matching real deallocator `IOFreeAligned`, called on the OLD record
 * before it's replaced.
 *
 * Real, honestly-flagged ambiguity: `this+0xa4` is written from a value
 * (`idOrComplement` below, real decompile's `uVar7`) that holds TWO
 * DIFFERENT real values depending on which path assigns the ID - the raw
 * `mode` value (fast path, `modeBits & 0x20` set) or its bitwise
 * complement `~mode` (validated slow path). Transcribed exactly as
 * found; the real semantic difference between "mode" and "~mode" in this
 * one field is UNKNOWN beyond what's visible here.
 *
 * Real, verified restructuring (not a behavior change): the raw decompile
 * reaches its shared unlock/return tail via several `goto`s into what are
 * really just 2-3 converging branches each - this transcription uses
 * plain structured if/else instead (an `IOReturn result` initialized to
 * the real default-error value, only overridden on the real success/
 * specific-error paths), verified by hand to produce the identical
 * control flow, matching this project's established practice for real
 * goto-shaped code proven equivalent to structured code (see e.g. opcode
 * 0x2f's real body elsewhere in this project).
 *
 * Confidence: CONFIRMED for the overall control flow and every real
 * offset/constant (all read directly from a fresh complete decompile,
 * cross-checked against the real disassembly for the parameter-count
 * question above). RESOLVED, issue #15: the four helper calls below are
 * real external XNU kernel primitives (`mutex_lock`/`mutex_unlock_rwcmb`/
 * `IOMallocAligned`/`IOFreeAligned`), identified via a live kxld-resolved
 * memory read on real G5/Tiger hardware, cross-referenced against the
 * running kernel's own symbol table - see
 * `Headers/ATIRadeonX1000Registers.h`.
 */
extern "C" void FUN_00014850(void *lockPtr) asm("_IOLockLock");
extern "C" void FUN_000147f0(void *lockPtr) asm("_IOLockUnlock");
extern "C" void *FUN_00014820(UInt32 size, UInt32 align) asm("_IOMallocAligned");
extern "C" void FUN_00014810(void *ptr, UInt32 size) asm("_IOFreeAligned");

/* (re-ported mechanically: see IOATIR500Surface_set_id_mode_Port.cpp) */


/*
 * set_shape_backing_length_ext - RESOLVED (issue #8), fully transcribed
 * (real kext offset 0x152d0). Real 7-parameter signature CONFIRMED via
 * the real mangled symbol AND cross-checked by tracing the raw PPC
 * registers through all three real callers (`set_shape_backing`/
 * `set_shape_backing_length`/`set_shape`, all reached via real
 * branch-island trampolines at 0x15948/0x15984/0x159d4 - Ghidra's own
 * no-analysis decompile numbers these params "param_2".."param_8"
 * (skipping "param_1" for the implicit `this`), which line up 1:1 with
 * this class's real registers r4..r10 - confirmed, not assumed.
 *
 * Real 2nd parameter (named `id` here, Ghidra's `param_3`) is CONFIRMED
 * to be the SAME real "surface ID slot" concept `set_id_mode` assigns -
 * bounds-checked against the identical `accelerator+0xcc` count, and
 * used to index the identical `id*8+0xd60/+0xd64` per-ID tracking-record
 * array, `id*0x94+0xcac` per-ID flag array, and `id*0x78+...` per-ID
 * descriptor array that function also touches.
 *
 * Real structure, in order:
 *  1. Real validation: `id` must be within `accelerator+0xcc`'s bound,
 *     and `region`'s own dimension field (a real 32-bit value at
 *     `region+8` - see the honest note on this field below) must have
 *     both halves non-negative, else `kIOReturnBadArgument`-family
 *     `0xe00002bc`.
 *  2. Real struct-size validation/default: the real `param6` (structSize)
 *     argument must either be 0 (in which case it's computed from
 *     `region[0]` - a real "rect count" field - as `count*8 + 0xc`) or
 *     already equal that computed value, else rejected. If both of
 *     `region`'s dimension halves (see below) are zero, this also resets
 *     `param4`/`param5` to 0 and force-sets both halves to 1 (a real
 *     "degenerate region becomes a real 1x1" normalization).
 *  3. Real accelerator commandLock acquire (this+0xd50's own +0x840,
 *     same lock every other function in this file uses) via ANOTHER
 *     real per-call-site lock trampoline (FUN_000158e0, matching the
 *     already-established FUN_00014850-style pattern - RESOLVED, issue
 *     #15: `mutex_lock`). If `shapeBits & 0x80` is set, real spin-wait on
 *     `accelerator+0x80` (a byte flag) via a real 3-arg wait primitive
 *     (FUN_000158d0(lockPtr, accelerator, 0) - RESOLVED, issue #15:
 *     `IOLockSleep`, confirming the prior guess exactly) until that
 *     flag goes nonzero.
 *  4. Real busy-gate check (this+0xbd0, the SAME field set_id_mode also
 *     gates on) and a real requirement that this+0xbe8's own bit 0x20
 *     (the SAME "mode bits" field set_id_mode writes, and the SAME bit
 *     set_id_mode's own fast-assignment path tests) is already set -
 *     rejects otherwise.
 *  5. Real per-ID record reallocation IF the existing record
 *     (`id*8+0xd60/+0xd64`) is too small or its size "class" (byte-
 *     rounded) differs from the real requested `structSize` - same real
 *     alloc/free helper SHAPE as set_id_mode's own (different real
 *     addresses here: FUN_000158c0 allocates, FUN_000158b0 frees), with
 *     the SAME real accelerator+0x804 byte-accounting field adjusted.
 *  6. Real per-rect copy: `region[0]` (a real rect count) entries copied
 *     from `region` into the per-ID record's own trailing array (the
 *     record's first 3 dwords are a real header - count/dim1/dim2 -
 *     copied from `region[0..2]`; the per-rect array starts at record+0xc,
 *     8-byte stride, reading from `region`'s OWN embedded per-rect data
 *     at real offsets `region+12`/`region+16` relative to each entry's
 *     advancing base). Transcribed byte-for-byte from the real decompile;
 *     the real per-rect field meanings are UNKNOWN beyond that (this
 *     project has not reconstructed Apple's own real `IOAccelDeviceRegion`
 *     layout - see this header's own top-level note - and this loop's
 *     exact addressing is dense enough that a byte-for-byte transcription
 *     was preferred over a semantic reinterpretation that might silently
 *     get a field wrong).
 *  7. A real "is this a trivial 1-rect no-scale case" flag computed from
 *     a real accelerator+0xd0 bitmask (tested against bit `id`) and, for
 *     a single-rect region, whether a SEPARATE real dimension pair at
 *     `region+16`/`region+18` (both real 16-bit fields, distinct from the
 *     packed 32-bit field at `region+8` - see honest note below) is
 *     zero - stored into the SAME `this+id*0x94+0xcac` per-ID flag byte
 *     `set_id_mode` also writes.
 *  8. Real bookkeeping into several per-surface fields (+0xbd4/+0xbd6/
 *     +0xbd8/+0xbda/+0xbdc/+0xbde/+0xbe0/+0xbe2/+0xbe4/+0xbe6/+0xbec/
 *     +0xbfc) tracking "current" vs "requested" dimension pairs, gated
 *     on real flags this project has not further named beyond their raw
 *     offsets.
 *  9. Real vtable calls at this-object's own +0x5c8 (role INFERRED:
 *     "invalidate," gated on a real "shape actually changed" condition,
 *     paired with a real call to the already-declared `update_contexts`)
 *     and +0x5b0 (role INFERRED: "commit/validate new dimensions,"
 *     called with the two just-set "current" dimension shorts as its
 *     real arguments) - failure (+0x5b0 returns 0) rejects with
 *     `0xe00002be` and sets a real "pending" bit (+0xbf8 |= 0x20000000).
 * 10. On success, real backing-store (re)allocation: if this ISN'T the
 *     "trivial" case from step 7, the SAME real accelerator vtable+0x540/
 *     +0x544 allocate/commit pair `set_id_mode` independently uses,
 *     sized from `*(this+0xb70)+0x10` (this surface's own PRIMARY
 *     `ATIR500SurfaceBuffer*`, i.e. mip/buffer-slot 0 - the SAME real
 *     per-mip-array field `+0xb70` this project already knows from the
 *     GL-context side, here read as a single pointer with no index).
 *     Then, unless `param4`(structSize-flag) was reset to the real
 *     sentinel `0xffffffff` in step 2's normalization, releases any
 *     existing real `IOTextureBuffer` at that buffer's own +0x24 (via
 *     the already-declared `delete_buffer_backing`) and, unless the
 *     real `param3`(count-ish)/`param4` pair is degenerate, calls the
 *     already-declared `connect_buffer_backing_store` to establish a new
 *     one - on success, stamps a real "generation" value (this+0x7c,
 *     optionally -1 if `shapeBits & 0x20`) into that buffer's own +0x24
 *     object's +0x54 field.
 * 11. Real shared tail (runs on EVERY path, including the early
 *     rejections from steps 1/2/4/5): writes two more per-surface byte
 *     flags (+0xbef from `shapeBits` bit 3; +0xbed from `shapeBits` bit 4
 *     OR this+0xbee being nonzero), then - unless `shapeBits & 1` is set -
 *     accumulates a real completion-stamp via
 *     `ATIRadeonX1000::sleepForTimeStamp` (RESOLVED, issue #19; the SAME
 *     real method `surface_write_lock_int` already calls, here with a DIFFERENT real
 *     argument, `this+0x80`, and a DIFFERENT real accumulator field,
 *     `accelerator+0x7c0` - a FOURTH distinct completion-stamp
 *     accumulator this project has now found, alongside the
 *     already-known +0x704/+0x780/+0x7bc). **CAUGHT AND FIXED this
 *     pass, same class of bug as issue #12 item 6**: the raw decompile
 *     indexes this accumulator via a real `int*`-typed local
 *     (`piVar12[0x1f0]`) - a DWORD index, i.e. real byte offset
 *     `0x1f0*4 = 0x7c0`, not `0x1f0` - caught before it became a second
 *     instance of that exact scaling mistake. Sets a real +0xbf2 byte
 *     flag either way. Finally releases the commandLock via ANOTHER real
 *     per-call-site trampoline (FUN_00015870) and returns the real
 *     accumulated status code.
 *
 * Honest note on `region`'s real internal layout: this project has NOT
 * reconstructed Apple's own real `IOAccelDeviceRegion` struct (see this
 * header's top-level note - it's a real, forward-declared-only Apple
 * type). The raw decompile reads `region+8` as BOTH a 16-bit value
 * (bounds-checked for a non-negative HIGH half in step 1, via a
 * big-endian-significant `short` read at that exact address) AND as a
 * full 32-bit value (copied wholesale for a real "did the size change"
 * comparison and into the per-ID record's header) - consistent with
 * `region+8` being a real PACKED 32-bit field (two 16-bit halves), not a
 * struct field naming error on this project's part. Separately,
 * `region+16`/`region+18` are consistently read as plain 16-bit fields
 * everywhere they're touched - a real, distinct dimension pair. Neither
 * pairing is asserted as a confirmed Apple field name; both are
 * transcribed via raw byte offsets on `region` (kept as `UInt8 *`)
 * rather than a guessed struct layout, per this project's standing
 * policy for genuinely unreconstructed Apple types.
 *
 * Confidence: CONFIRMED for the overall structure, every real offset,
 * and the parameter-mapping cross-check above. The per-rect copy loop
 * (step 6) and the dense multi-field bookkeeping in steps 8/10 are
 * transcribed literally from the raw decompile's own pointer arithmetic
 * rather than reinterpreted into named fields, consistent with this
 * project's practice for genuinely dense, semantically-uncertain
 * real code (see e.g. Sources/ATIR500GLContext_FSAAResolveBlit.cpp's
 * own methodology note). INDEPENDENT SPOT-CHECK COMPLETE: re-decompiled
 * fresh from Ghidra and compared line-by-line against this committed
 * transcription, including every `int*`-scaled pointer expression
 * (`piVar12[3]`/`piVar12+4`/`piVar12+2`/`param_6[2]`, etc.) - zero
 * discrepancies found. This function's transcription is CONFIRMED
 * byte-accurate, not just structurally plausible.
 */
/* RESOLVED, issue #15 (live kxld-resolved memory read on real G5/Tiger
 * hardware, cross-referenced against the running kernel's own symbol
 * table - see `Headers/ATIRadeonX1000Registers.h`): all five below are
 * real external XNU kernel primitives. FUN_000158d0's real target is
 * `IOLockSleep`, confirming the "plausibly a real IOLockSleep-shaped
 * call" guess above exactly. */
extern "C" void FUN_000158e0(void *lockPtr) asm("_IOLockLock");
extern "C" void FUN_000158d0(void *lockPtr, void *accel, UInt32 zero) asm("_IOLockSleep");
extern "C" void *FUN_000158c0(UInt32 size, UInt32 align) asm("_IOMallocAligned");
extern "C" void FUN_000158b0(void *ptr, UInt32 size) asm("_IOFreeAligned");
extern "C" void FUN_00015870(void *lockPtr) asm("_IOLockUnlock");

/* (re-ported mechanically: see IOATIR500Surface_set_shape_backing_length_ext_Port.cpp) */


/*
 * set_shape_backing_length / set_shape_backing - RESOLVED (issue #8),
 * both real, thin forwards into `set_shape_backing_length_ext` above
 * (real kext offsets 0x158f0/0x15960, each reaching the real body via
 * its own real branch-island trampoline - see that function's own header
 * comment). Ghidra's own no-analysis decompile of both collapsed to a
 * bare, argument-less tail call (`set_shape_backing_length_ext();`),
 * unable to recover the real argument setup without full analysis - so
 * this transcription is instead sourced directly from the raw PPC
 * disassembly's own register moves at each function, cross-checked
 * against the real PPC32 SysV/Darwin integer-argument-register
 * convention (r3=this, r4..r10=args 1-7), not trusted to a decompile.
 *
 * set_shape_backing_length additionally has a real, CONFIRMED validation
 * gate no earlier note of this project had recorded: unless its own
 * `param4` (the pass-through for set_shape_backing_length_ext's `param4`,
 * "structSize" - real 0xffffffff sentinel means "unset") equals
 * `0xffffffff`, it real-multiplies `param4` by a real 16-bit field at
 * `region+0xa` and rejects with `0xe00002bc` if the caller's own `param5`
 * is smaller than that product - a real "is the caller's buffer big
 * enough" check this function performs BEFORE ever reaching
 * `set_shape_backing_length_ext`, on top of the real size/region
 * validation that function does internally. On success (or when
 * `param4==0xffffffff`, which skips this check entirely), forwards to
 * `set_shape_backing_length_ext` with `param5` set to a real literal `0`
 * and the real `region`/`param5`(caller's) values passed through -
 * confirmed via the raw register moves (`or r8,r9,r9` moves the real
 * `region` argument from r9 into r8; `or r10,r8,r8` saves the real
 * caller's `param5` from r8 into r10, BEFORE r8 is overwritten with
 * `region` - real evidence this project's transcription order below
 * matters and was checked, not assumed).
 */
/*
 * set_shape_backing_length / set_shape_backing - RESOLVED (issue #8),
 * both real, thin forwards into `set_shape_backing_length_ext` above
 * (real kext offsets 0x158f0/0x15960, each reaching the real body via
 * its own real branch-island trampoline - see that function's own header
 * comment). Ghidra's own no-analysis decompile of both collapsed to a
 * bare, argument-less tail call (`set_shape_backing_length_ext();`),
 * unable to recover the real argument setup without full analysis - so
 * this transcription is instead sourced directly from the raw PPC
 * disassembly's own register moves at each function, cross-checked
 * against the real PPC32 SysV/Darwin integer-argument-register
 * convention (r3=this, r4..r10=args 1-7), not trusted to a decompile.
 *
 * set_shape_backing_length additionally has a real, CONFIRMED validation
 * gate no earlier note of this project had recorded: unless its own
 * `param4` (the pass-through for set_shape_backing_length_ext's `param4`,
 * "structSize" - real 0xffffffff sentinel means "unset") equals
 * `0xffffffff`, it real-multiplies `param4` by a real 16-bit field at
 * `region+0xa` and rejects with `0xe00002bc` if the caller's own `param5`
 * is smaller than that product - a real "is the caller's buffer big
 * enough" check this function performs BEFORE ever reaching
 * `set_shape_backing_length_ext`, on top of the real size/region
 * validation that function does internally. On success (or when
 * `param4==0xffffffff`, which skips this check entirely), forwards to
 * `set_shape_backing_length_ext` with `param5` set to a real literal `0`
 * and the real `region`/`param5`(caller's) values passed through -
 * confirmed via the raw register moves (`or r8,r9,r9` moves the real
 * `region` argument from r9 into r8; `or r10,r8,r8` saves the real
 * caller's `param5` from r8 into r10, BEFORE r8 is overwritten with
 * `region` - real evidence this project's transcription order below
 * matters and was checked, not assumed).
 */
IOReturn IOATIR500Surface::set_shape_backing_length(eIOAccelSurfaceShapeBits shapeBits, UInt32 param2, unsigned int param3,
                                                      UInt32 param4, UInt32 param5,
                                                      IOAccelDeviceRegion *region) {
    if (param4 != 0xffffffffu) {
        UInt16 dim = *reinterpret_cast<UInt16 *>(reinterpret_cast<UInt8 *>(region) + 0xa);
        if (param5 < param4 * static_cast<UInt32>(dim)) {
            return 0xe00002bc;
        }
    }
    return set_shape_backing_length_ext(shapeBits, param2, param3, param4, region, 0, param5);
}



void IOATIR500Surface::set_shape_backing(eIOAccelSurfaceShapeBits shapeBits, UInt32 param2, unsigned int param3, UInt32 param4,
                                          IOAccelDeviceRegion *region, UInt32 param6) {
    /* real: discards set_shape_backing_length_ext's own return value -
     * matches this function's real `void` return type (confirmed via the
     * raw disassembly: r3 is never touched again after the call before
     * `blr`, i.e. nothing reads it - not this project's own choice to
     * ignore it). */
    set_shape_backing_length_ext(shapeBits, param2, param3, param4, region, param6, 0);
}

