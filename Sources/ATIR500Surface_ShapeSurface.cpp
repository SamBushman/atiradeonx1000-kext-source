/* NOTE 2026-09-19: 1 function body formerly in this file has been replaced by mechanical ports from the shipped kext's decompile (Sources/*_Port.cpp; marked
   "(re-ported mechanically: ...)" below). The analysis prose in this file describes the earlier hand-written bodies and is kept as history; see README.md,
   "How the code was produced". */
/*
 * ATIR500Surface_ShapeSurface.cpp
 *
 * RESOLVED (issue #22): `ATIR500Surface::shape_surface`'s real body -
 * subclass-only, real addr `0x3c130`. The single largest function this
 * project has ever decompiled (~650 lines of raw decompile) - the last
 * remaining item from this issue's own original 12-slot enumeration.
 *
 * Real purpose: recomputes and (re)allocates the per-format-code
 * `ATIR500SurfaceBuffer` records this surface owns, whenever the
 * surface's own top-level format/mode bits (`this+0xbe8`) or dimensions
 * (`this+0xbd4`/`this+0xbd6`) change - the real "surface was reshaped,
 * make every dependent buffer record agree with the new shape" pass.
 * Every one of this class's own per-slot buffer records lives at
 * `this + slotIndex*0x78 + 0xa8`, cast as `ATIR500SurfaceBuffer*`
 * (matching `alloc_surface_buffer`'s own already-established addressing
 * - issue #22 - and `dealloc_surface`'s own per-index teardown,
 * `ATIR500Surface_VRAM.cpp`) - EXCEPT slot 9, which lives at the fixed
 * offset `this+0x4e0` instead of following the `*0x78` stride (this
 * function special-cases index 9 accordingly throughout).
 *
 * Real structure, four consecutive passes over different slot groups:
 *
 *   1. HyperZ depth/stencil slots (6/7/8) - gated on `this+0xc18`'s own
 *      `0x1c0` bits. Picks a real depth/stencil format-table index
 *      (`0x29` or `0x10`, `DAT_0004d2dc`-driven) and per-slot compression
 *      sample-count multipliers, computes each slot's real byte size,
 *      and reshapes (tears down + calls the real `dealloc_surface(idx)`
 *      teardown, `+0x5cc` on this class's own vtable - CONFIRMED here to
 *      be `dealloc_surface`, resolving the "unidentified `+0x5cc` slot"
 *      an earlier pass on this same issue flagged as unknown) whichever
 *      slots actually changed size.
 *   2. Slot 9 (the fixed color/depth buffer at `this+0x4e0`) - gated on
 *      `this+0xc18 & 0x200`. Same real reshape pattern, using the MAIN
 *      window format (`window_mode_to_ati_format`) instead of the
 *      depth/stencil-specific lookup above.
 *   3. The general color-format slots (a real, mode-dependent index set:
 *      `{0,1,5,4,2,3}` in the normal case, or just `{0,1}` when a real
 *      custom-window-rect mode is active, `this+0x90 != 0`) - computes a
 *      real mip-pyramid byte-size accumulator (14 real per-level partial
 *      sums, `local_90`) via either a trivial swap-buffer-record copy, a
 *      simple pitch*height product, or (the real tiled/`0x70000000` bit
 *      set case) an actual per-mip-level tile-alignment loop - and
 *      reshapes each slot the same way as passes 1/2.
 *   4. Real deinterlace/subpicture-plane slots (10-22, `this+0xc18`'s
 *      own `0x7ffc00` bits, only reached when `this+0x90 != 0`) -
 *      geometry driven by the real custom window rect
 *      (`this+0x94`/`0x96`/`0x98`/`0x9a`) rather than the surface's own
 *      width/height, with three real per-plane-type special config
 *      writes (indices `0x10`/`0x11`/`0x12`) whose own semantics are
 *      UNKNOWN beyond "written when that specific plane is reshaped".
 *
 * Finally, a real overlay-handle allocate-once-if-needed
 * (`alloc_overlay`) and a real per-framebuffer content-sanity check
 * (`getFramebufferIndex`, `this+0xd60`-based array) gate a real
 * `setup_overlay()` call.
 *
 * Two real, previously-undocumented `ATIR500SurfaceBuffer` fields found
 * and named this pass (now in `Headers/ATIRadeonX1000Types.h`):
 * `backingStoreHandle` (+0x24, the real "does this slot already have an
 * allocated backing" gate every reshape site checks before calling
 * `free_buffer_backing_store`) and `formatSubShift` (+0x3b, a real
 * per-format sub-field written alongside `formatTableIndex`, never read
 * back anywhere this project has decompiled so far). The real vtable
 * slot `+0x5cc` is now CONFIRMED `dealloc_surface` (already declared,
 * `Headers/IOATIR500Surface.h`) rather than a separate unidentified
 * "notify resize" method, as an earlier progress pass on this issue had
 * it - resolved by simply cross-checking the slot number against this
 * project's own already-committed vtable-slot table instead of treating
 * it as new.
 *
 * Real gaps left explicitly flagged, not resolved this pass (per this
 * project's own confidence tiers - narrowed as far as static analysis
 * from THIS function alone allows, not guessed):
 *   - `window_mode_to_ati_format` (RESOLVED separately, issue #35),
 *     `getFramebufferIndex`/`alloc_overlay`/`setup_overlay` (RESOLVED,
 *     issue #48 - see `Sources/ATIR500Surface_Overlay2.cpp`, which also
 *     confirms `setup_overlay()` really is a genuine zero-argument
 *     no-op, not a decompiler artifact hiding an implicit argument),
 *     `copy_buffer_to_backing_store` - real names (Ghidra's own resolved
 *     symbols, not `FUN_` addresses); `copy_buffer_to_backing_store`
 *     alone remains undecompiled as of this writing.
 *   - The real per-framebuffer array at `this+0xd60` (`this+0xd50`'s
 *     accelerator field sits immediately before it) and the real record
 *     it points to (`+0x0`/`+0x10`/`+0x12` sanity-checked before
 *     `setup_overlay()`) - real shape/roles UNKNOWN, transcribed as
 *     literal raw offsets. (The middle offset is real raw `piVar11 + 4`
 *     on a real Ghidra-typed `int*` local, i.e. already word-scaled to
 *     byte offset `+0x10`, NOT `+4` - this project's own known `int*`-
 *     scaling trap; the transcription itself already gets this right
 *     via `fbRec + 4` on an equally `SInt32*`-typed local, this comment
 *     just corrects its own prose to match.)
 *   - The real compiled-in constant table `C_146` (copied via a
 *     `0x38`-byte memcpy-style helper, `FUN_0003cf24` - RESOLVED, issue
 *     #27: real target `memmove`, the same real target as this
 *     project's `FUN_000314c4`/`FUN_00044868` blit-template-copy family,
 *     issue #15) - real content/field meaning UNKNOWN, used opaquely as
 *     "the default 14-entry mip-offset table" per its own real call-site
 *     role.
 *   - The apparent real field-reuse tension between this function's own
 *     `this+0x94`/`0x96`/`0x98`/`0x9a` reads (used here as if they were
 *     two opposite rect corners, `w-x`/`y-h`) and
 *     `ATIR500Surface::dvd_setup_overlay`'s own real writes to the SAME
 *     four offsets (`ATIR500Surface_Overlay.cpp`, x/h/y/w individually)
 *     - both are real, independently decompiled, but this project did
 *     NOT reconcile whether they're genuinely the same logical rect
 *     under two different real access patterns or two coincidentally
 *     co-located records; transcribed literally, flagged rather than
 *     guessed.
 *
 * Confidence: CONFIRMED for control flow and every field offset/literal
 * constant that maps onto an already-established real field
 * (`accelerator`, `gateBits`/`this+0xc18`, `formatBits`/`this+0xbe8`,
 * `this+0xc14`, `this+0xbd4`/`0xbd6`, `this+0xdac`, `ATIR500SurfaceBuffer`'s
 * own named fields, `FormatTableLookup_0x0004d2dc`) - all independently
 * cross-checked against their own already-committed real usage
 * elsewhere in this project before being reused here, per this
 * project's own "cross-check a fresh decompile against committed code"
 * discipline. Real per-mip tile-alignment arithmetic (pass 3's tiled
 * branch) and the three real per-plane-type special config writes
 * (pass 4) are transcribed as literal raw arithmetic/offsets - real
 * behavior, INFERRED-level confidence on exact semantic naming. No C++
 * compiler was available in the sandboxed environment this was written
 * in (same standing limitation as every other file in this project) -
 * checked by careful, repeated manual re-reading against the raw
 * decompile instead.
 *
 * Real, previously-unnoted finding confirmed via that re-reading: pass
 * 3's own `swizzleMode` selector is the SAME Ghidra-tracked
 * variable/register as the earlier per-panel `overlayFormatSel` pick -
 * the real swizzle-mode-computing code sits ONLY inside pass 3's own
 * tiled branch (confirmed from this function's own brace structure),
 * so the two untiled branches genuinely reshape their slots using
 * whatever `overlayFormatSel` value the earlier, logically-unrelated
 * panel-format selection happened to leave behind - a real cross-
 * purpose field reuse, not a transcription simplification.
 *
 * Several real self-caught bugs were found and fixed during this
 * function's own line-by-line re-verification before commit (this
 * project's own standard discipline, not a one-off): every one of this
 * class's per-slot records is addressed as `this+slotIndex*0x78+0xa8`
 * throughout passes 1-3, but pass 4 walks a SEPARATE real pointer
 * (`pAVar15`, starting at `this` itself, not `this+10*0x78+0xa8`) -
 * an initial draft of pass 4 wrongly reused pass 1-3's own `+0xNN`
 * literal offsets verbatim against pass 4's differently-based record
 * pointer, corrupting every single field pass 4 touches; corrected by
 * re-deriving each real offset via `pAVar15 = rec - 0x558`. A second,
 * separate round of the same mistake affected several of pass 1/3's OWN
 * secondary fields (`+0xb8`/`+0xc0`/`+0xe4`/`+0xca`/`200`/`+0xe8`) that
 * were transcribed as literal `rec+<raw literal>` without first
 * subtracting the record's own `+0xa8` base, double-counting it.
 *
 * INDEPENDENT SECOND REVIEW (issue #22 - separate session, re-derived the
 * decompile fresh from Ghidra rather than trusting the file/dump above)
 * found and fixed four further real, narrow bugs the first pass missed,
 * confirmed line-by-line against the raw decompile:
 *   - Pass 1's `packedCfg`/`tilingDegreeBits` write had `sx`/`sy` SWAPPED
 *     relative to the real raw operands (`(uVar28 & 0xf) << 0xc | iVar9
 *     << 0x10` is `sy << 0xc | sx << 0x10`, and the sibling `0x700000`
 *     branch is `iVar9 << 0x14` = `sx`, not `sy`) - caught by cross-
 *     checking against Pass 2's OWN analogous `packedCfg9` computation
 *     (`(local_58 & 0xf) << 0xc | iVar23 << 0x10` /
 *     `iVar23 << 0x14`, i.e. `sampleCountY`/`sampleCountX` in that
 *     order), which this second pass confirmed was ALREADY correct and
 *     used as the cross-check baseline.
 *   - Pass 1's `heightOrRows` write used the CACHED pre-call `baseW`
 *     instead of a fresh `this+0xbd4` re-read; the raw decompile shows
 *     this specific field write (unlike every other field in the same
 *     block) is a literal fresh dereference AFTER the `free_buffer_
 *     backing_store`/`dealloc_surface` calls, matching the sibling
 *     `extra1e` write's own already-correct fresh `this+0xbd6` read one
 *     line below it - the file already got the `extra1e` half of this
 *     pair right, just not the `heightOrRows` half.
 *   - Pass 3's tiled-mip branch computed `rowByteBase` (the row-pitch
 *     value later stored at `rec+0x18` and divided into `buf->width` for
 *     every general color slot) WITHOUT the real 0x100-boundary
 *     round-up the raw decompile applies immediately after the initial
 *     `mainBlockShift * w` product (`if ((uVar8 & 0xff) != 0) uVar24 =
 *     (uVar8 & 0xffffff00) + 0x100;`) - the first draft's own comment
 *     ("uVar24 = uVar8's initial value") only quoted the ASSIGNMENT,
 *     missing the very next line that immediately overwrites it.
 *   - The `overlayFormatSel` selector's `this+0xbd6 < 0x10` height check
 *     had its two branches (0 vs 1) SWAPPED, traced to a misread of the
 *     raw decompile's `(AVar12 = 1, height < 0x10) || ...` comma-operator
 *     `goto`: the `AVar12 = 1` side effect fires whenever the right `||`
 *     operand is evaluated at all, but gets unconditionally overwritten
 *     back to 0 by the `goto` target whenever `height < 0x10` is ALSO
 *     true - so real net behavior is 0 for `height < 0x10`, 1 only when
 *     `height >= 0x10` (falls through with the side-effect value intact)
 *     - the exact opposite of the swapped first draft.
 * Also corrected: a header-comment-only inaccuracy (not a code bug) that
 * described the per-framebuffer sanity-check record's middle field as
 * real raw offset `+0x4`; it is real raw `piVar11 + 4` on a Ghidra `int*`
 * local, i.e. already word-scaled to byte offset `+0x10` - this project's
 * own known `int*`-scaling trap - and the CODE already had this right
 * (`fbRec + 4` on an equally `SInt32*`-typed local); only the prose was
 * wrong. No other discrepancies found in a full line-by-line offset/
 * cast/loop-bound/branch re-derivation covering every pass.
 */

#include "../Headers/ATIR500Surface.h"
#include "../Headers/ATIRadeonX1000.h"
#include "../Headers/ATIRadeonX1000Registers.h"

namespace {
inline UInt32 &U32At(void *base, int offset) { return *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt16 &U16At(void *base, int offset) { return *reinterpret_cast<UInt16 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline SInt16 &S16At(void *base, int offset) { return *reinterpret_cast<SInt16 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt8  &U8At(void *base, int offset)  { return *(reinterpret_cast<UInt8 *>(base) + offset); }

/* Real per-mip/per-plane pitch rounding this function applies repeatedly:
 * round `value` up to the next multiple of `align` (align is always a
 * real power of two, 0x20 or 0x100, in every real call site). */
inline UInt32 RoundUpPitch(UInt32 value, UInt32 align) {
    if ((value & (align - 1)) != 0) {
        value = (value & ~(align - 1)) + align;
    }
    return value;
}

/* Real per-mip height rounding, always to a 0x20 boundary, but real
 * arithmetic on a SIGNED short in the raw decompile (matters for the
 * rare real negative-height case) - transcribed with the exact same
 * signed rounding-toward-zero shift the raw decompile performs, not
 * simplified to unsigned rounding. Real base value is SIGN-extended
 * (`(uint)*(short*)...` in the raw decompile sign-extends short->int
 * before the uint reinterpret - NOT a zero-extend of the 16-bit
 * pattern), which only matters for this same real negative-height
 * edge case. */
inline UInt32 RoundUpHeight32(SInt16 heightVal) {
    UInt32 h = static_cast<UInt32>(static_cast<SInt32>(heightVal));
    if ((h & 0x1f) != 0) {
        SInt32 hSigned = static_cast<SInt32>(h);
        SInt16 shiftSum = static_cast<SInt16>((hSigned >> 5) + ((hSigned < 0) ? 1 : 0));
        SInt16 adjusted = static_cast<SInt16>(heightVal + static_cast<SInt16>(shiftSum * -0x20));
        h = (h - static_cast<UInt32>(static_cast<SInt32>(adjusted))) + 0x20;
    }
    return h;
}
} // namespace

/* RESOLVED, issue #35 - real body (a simple format-code switch) now
 * decompiled, see Sources/ATIRadeonX1000_WindowModeToATIFormat.cpp.
 * RESOLVED linkage: real symbol is C++-mangled
 * (`__Z25window_mode_to_ati_formatm`), a plain `extern "C"` declaration
 * with no `asm()` alias would never have linked against it - fixed. */
extern "C" UInt32 window_mode_to_ati_format(UInt32 windowModeBits) asm("__Z25window_mode_to_ati_formatm");
/* getFramebufferIndex/alloc_overlay/setup_overlay - RESOLVED, now real
 * member declarations on Headers/ATIR500Surface.h - see that header's
 * own comment for the real linkage bug this replaced. */
/* RESOLVED, issue #27: real target memmove, same real target as issue #15's FUN_000314c4/FUN_00044868 */
extern "C" void   FUN_0003cf24(void *dest, const void *constTable, UInt32 byteCount) asm("_memmove");
/* shape_surface()::C.146 - real addr 0x4c284 in __const, 0x38 bytes. Extracted from the binary (issue #58
 * follow-up): all 14 words are zero (and no relocations overlap the range), i.e. the compiler's
 * copy of an all-zero initialiser for the local `localMipOffsets[14]`. */
extern const UInt32 kShapeSurfaceDefaultMipTable[14] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

/* FIXED (issue #1, first build attempt): this function previously wrote
 * raw byte offsets as `this[N] = static_cast<ATIR500Surface>(...)`. Since
 * `this` is `ATIR500Surface *`, `this[N]` is pointer arithmetic SCALED by
 * `sizeof(ATIR500Surface)` and treats the target as a WHOLE object of
 * that type, not a single byte at byte-offset N - a real, silently-wrong
 * transcription (not merely a build error the old sandbox couldn't
 * catch: on this exact class the confusion is total, since `sizeof
 * (ATIR500Surface)` isn't even 1). Converted to this file's own existing
 * `U8At(self, N)` byte-accessor helper, matching every other raw-offset
 * access in this file. */
/* (re-ported mechanically: see ATIR500Surface_shape_surface_Port.cpp) */

