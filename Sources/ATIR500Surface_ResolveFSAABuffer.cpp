/* NOTE 2026-09-19: 1 function body formerly in this file has been replaced by mechanical ports from the shipped kext's decompile (Sources/*_Port.cpp; marked
   "(re-ported mechanically: ...)" below). The analysis prose in this file describes the earlier hand-written bodies and is kept as history; see README.md,
   "How the code was produced". */
/*
 * ATIR500Surface_ResolveFSAABuffer.cpp
 *
 * RESOLVED (issue #13 item 2): `ATIR500Surface::resolve_fsaa_buffer`, the
 * one function this project had left genuinely opaque since the opcode
 * 0x31/0x2d misattribution investigation used it only as a targeted
 * negative-identity check (kext offset `0x43e60`, confirmed by symbol
 * name already present in the binary's own symbol table - not a guess).
 * Full decompile obtained fresh this pass and transcribed completely.
 *
 * CORRECTED (issue #17 investigation): decompiling the sibling function
 * `back_resolve_fsaa_buffer` (`ATIR500Surface_BackResolveFSAABuffer.cpp`)
 * turned up two real transcription bugs in THIS file's original pass,
 * both now fixed:
 *   1. The top-level Block A/B selector flag is real `*(uint*)(this+0xbe8)`
 *      - a field on the SURFACE OBJECT ITSELF (already independently
 *      confirmed elsewhere as a real Surface mode/state-bits field -
 *      `IOATIR500Surface_LockShape.cpp`, `ATIR500GLContext_RegisterState.cpp`,
 *      `ATIR500GLContext_ProcessCommandBuffer.cpp` all read/write the same
 *      `this+0xbe8`/`self+0xbe8`/`boundSurface+0xbe8` offset) - NOT
 *      `accelerator+0xbe8` as this file originally had it. `accel` and
 *      `this` are different pointers; the original code silently read the
 *      wrong object at this one site only (every other `accel`-based read
 *      in this file is correct, cross-checked and unaffected).
 *   2. The two `paramBlock[0x9a]`/`paramBlock[0xa0]` base-address
 *      computations read a real distinct struct field at `+0x20`
 *      (`basePitch`, `ATIRadeonX1000Types.h`), not `bytesPerRow` (`+0x16`)
 *      as originally transcribed - `back_resolve_fsaa_buffer` reads the
 *      exact same `+0x20` offset in the same base-address-computation role
 *      for both its own surface sources, which is what surfaced the
 *      mismatch on a fresh re-read of this file's own raw decompile.
 * Every other line in this file was re-checked against the original raw
 * decompile during this correction pass and found accurate.
 *
 * Real signature, matching this project's existing declaration exactly
 * (`Headers/IOATIR500Surface.h`): called from opcode 0x30's handler
 * (`handle_fsaa_resolve_setup`, `ATIR500GLContext_ProcessCommandBuffer.cpp`)
 * with the caller's own live command-buffer record pointer passed
 * directly as `paramBlock` - this function writes straight into the
 * caller's own record stream and returns a pointer indicating how far it
 * consumed, exactly the same "explicit next pointer, not a natural
 * distance" convention already established for opcode 0x2d's own handler
 * (`local_d0` - see issue #13 item 1). The caller compares the returned
 * pointer against its own natural-distance target and pads the gap if
 * short, confirming this reading of the convention.
 *
 * Real top-level structure: a single flag-bit test
 * (`this+0xbe8 & 0x700000`) selects between two ENTIRELY DIFFERENT real
 * resolve strategies, not two minor variations of the same one:
 *
 *   - Block A (flag clear): a real per-plane MSAA-sample-position/pitch
 *     burst plus real floating-point NDC viewport math (the same
 *     "magic-bias" int-to-float trick already established in
 *     `ATIR500GLContext_FSAAResolveBlit.cpp`/DVD's opcode 0x3d) - the
 *     textured-quad-blit-shaped resolve path.
 *   - Block B (flag set): a real HyperZ-block-driven resolve using
 *     `HZMEM_GetBlockOffset`/`HZMEM_GetBlockCount` and a completely
 *     different real PM4 burst shape (`0x1395`/`0x1399`/`0x13a0`-`0x13a2`/
 *     `0x1385`/`0x1380`), never touching the floating-point path at all.
 *
 * Both blocks are real, independently transcribed from the same
 * complete decompile - not derived from each other or from
 * `FSAAResolveBlit.cpp`'s own similar-looking (but NOT identical) content;
 * that file is a different class (`ATIR500GLContext`, opcode 0x2d) with
 * its own distinct field offsets. The resemblance (same magic-bias float
 * trick, same cascading-format-table-bit-patch idiom already seen at
 * three other real sites this project has found) is real convergent
 * evidence of a shared driver-wide idiom, not code sharing between these
 * two specific functions.
 *
 * Real struct finding this pass: `iVar18`/`iVar19` in the raw decompile
 * are real `ATIR500SurfaceBuffer*` pointers (this project's own
 * already-declared struct, `ATIRadeonX1000Types.h`) - confirmed by a
 * field-by-field match against every already-CONFIRMED field in that
 * struct (`+0x08` base, `+0x14`/`+0x16` width/pitch, `+0x1c`/`+0x1e`
 * height pair, `+0x28` HZMEM block field (`hzBlockField`, RENAMED from a
 * real naming/scope error - see that field's own declaration comment),
 * `+0x38`/`+0x39`/`+0x3a` tiling/format
 * bytes, `+0x40..` mip offsets). This function also reads three real
 * fields the struct didn't have names for yet - `+0x30`, `+0x36`, and
 * `+0x3c` - all three now added to the struct's own declaration with
 * this function cited as the source. `this+0xb70` (indexed by the
 * caller's own format-code argument) and `this+0xb94` (a single, always-
 * read pointer) are the real base addresses these `ATIR500SurfaceBuffer*`
 * pointers come from - both newly declared on `IOATIR500Surface` by this
 * pass, previously undocumented anywhere in this project.
 *
 * TRANSCRIPTION METHOD, matching `FSAAResolveBlit.cpp`'s own stated
 * approach for the same reason: flat decompile-derived variable names
 * (`uVar12`, `uVar15`, etc.) are kept close to the original rather than
 * renamed into "cleaner" semantic names wherever a value is reassigned
 * for an unrelated purpose partway through (e.g. `uVar15` is reused for
 * at least four structurally different real quantities across this one
 * function) - renaming these is exactly the kind of "cleanup" that has
 * caused real transcription mistakes elsewhere in this project.
 * `ATIR500SurfaceBuffer*`-typed field access is used in place of raw
 * `U32At`/`U16At` offset arithmetic where the struct now names the field,
 * for readability - this is a safe substitution, not a reinterpretation,
 * since the struct's own offsets were independently confirmed against
 * this exact function's own field reads (see above).
 *
 * The real "magic-bias" int-to-float constant here (`4503601774854144.0`)
 * is a LITERAL double value in the raw decompile output - Ghidra resolved
 * it directly, unlike `FSAAResolveBlit.cpp`'s own still-unresolved
 * `DOUBLE_0004c3a8`/`0x3b0` externs for the equivalent constant in that
 * function. Used directly here rather than left as an unresolved extern.
 *
 * `FUN_00044868` (the real `0x2f4`-byte blit-state-packet template copy,
 * called once at the very top before either block runs) - RESOLVED,
 * issue #15: real target `memmove`, the same real copy
 * `FSAAResolveBlit.cpp`/`RestoreState.cpp` already document
 * (`g_r500_3d_blit_state_packet`, `ATIRadeonX1000Types.h`) - not
 * re-modeled as a direct `memmove` call here since the template's own
 * real per-field content was never extracted from the binary either
 * place.
 *
 * `&_samplesTable` (real binary data, indexed via a real byte offset
 * `(tilingDegreeBits >> 0x12) & 0x3c` - a real up-to-16-entry `UInt32`
 * table; the `0x3c` mask is mathematically the same real 4-byte-stride
 * indexing every other format table in this project uses, just written
 * as a direct byte-offset mask instead of an explicit `<<2` scale -
 * confirmed equivalent: `x & 0x3c == (x & 0xf) << 2`) is declared as a
 * new `extern "C"` accessor (`SamplesTableLookup`, taking the same real
 * byte-offset convention as `FormatTableLookup_0x0004d2e0/e4`,
 * `ATIRadeonX1000Registers.h`) - raw table content not extracted from
 * the binary this pass, same standing caveat as those tables.
 *
 * `this+0xbe8` (the real block-A/block-B selector flag) and the
 * `ATIRadeonX1000`-relative offsets this function reads
 * (`accelerator+0xb74`/`+0xb98`/`+0x78`/`+0x870`) are accessed via raw
 * `U32At`/`U8At` rather than newly-declared named fields - consistent
 * with this project's established practice of leaving single-use,
 * not-independently-corroborated accelerator offsets as raw offsets
 * rather than promoting every one to a named struct member (see e.g.
 * `ATIR500GLContext_FSAAResolveBlit.cpp`'s own `self+0x290`-style
 * offsets). `accelerator+0x870` is the same real `_HZDATA*` base
 * `HZMEM_GetBlockOffset`/`GetBlockCount` already use elsewhere in this
 * project (`ATIRadeonX1000Registers.h`).
 *
 * Confidence: CONFIRMED for every literal constant and the complete
 * control flow - this is a real, standalone function (not embedded in
 * one of this project's giant multi-opcode dispatch functions), so its
 * own decompile carries none of the brace-nesting-unreliability risk
 * this project has repeatedly documented for `process_command_buffer`.
 * No C++ compiler was available in the sandboxed environment this was
 * written in (same standing limitation as every other file in this
 * project) - checked by careful, repeated manual re-reading against the
 * raw decompile instead.
 */

#include "../Headers/ATIR500Surface.h"
#include "../Headers/ATIRadeonX1000Types.h"
#include "../Headers/ATIRadeonX1000Registers.h"

namespace {

inline float BiasedIntToFloat(UInt32 raw, double bias) {
    union { double d; struct { UInt32 hi, lo; } parts; } u;
    u.parts.hi = 0x43300000;
    u.parts.lo = raw;
    return static_cast<float>(u.d - bias);
}

inline UInt32 &U32At(void *base, int offset) { return *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt16 &U16At(void *base, int offset) { return *reinterpret_cast<UInt16 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt8  &U8At(void *base, int offset)  { return *(reinterpret_cast<UInt8 *>(base) + offset); }

const double kBias = 4503601774854144.0;

} // namespace

/* (re-ported mechanically: see ATIR500Surface_resolve_fsaa_buffer_Port.cpp) */

