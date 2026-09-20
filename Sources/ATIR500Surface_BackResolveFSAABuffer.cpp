/* NOTE 2026-09-19: 1 function body formerly in this file has been replaced by mechanical ports from the shipped kext's decompile (Sources/*_Port.cpp; marked
   "(re-ported mechanically: ...)" below). The analysis prose in this file describes the earlier hand-written bodies and is kept as history; see README.md,
   "How the code was produced". */
/*
 * ATIR500Surface_BackResolveFSAABuffer.cpp
 *
 * RESOLVED (issue #17): `ATIR500Surface::back_resolve_fsaa_buffer`, a real
 * function found incidentally while locating `resolve_fsaa_buffer`'s own
 * address for issue #13 (kext offset `0x44880`, size 1260 bytes,
 * immediately after `resolve_fsaa_buffer`'s own body) - flagged there but
 * never itself investigated until now. Full decompile obtained fresh this
 * pass and transcribed completely.
 *
 * Real signature: `back_resolve_fsaa_buffer(this, param_1, param_2,
 * param_3)`. `param_1` is real but genuinely UNUSED - never read anywhere
 * in the function body, confirmed by a full read of the raw decompile, not
 * an oversight in this transcription. `param_2` indexes
 * `surfaceBuffersByFormat` (same real per-format-code array
 * `resolve_fsaa_buffer` uses), matching that function's own `formatCode`
 * parameter. `param_3` is the same real "caller's own live command-buffer
 * record pointer, written into directly, explicit next-pointer returned"
 * convention `resolve_fsaa_buffer` and opcode 0x2d's handler both already
 * established.
 *
 * REAL CALLER: none found. A Ghidra reference sweep for every real
 * cross-reference TO this function's address found exactly one hit, typed
 * "Entry Point (EXTERNAL)" with no containing function - i.e. this
 * function is reachable only via an external/vtable-style reference
 * Ghidra's static analysis can't resolve to a real call site, not from any
 * of this project's already-transcribed command-buffer opcode handlers.
 * Consistent with the issue's own "if any exist" hedge on this point.
 *
 * REAL STRUCTURAL RELATIONSHIP TO `resolve_fsaa_buffer` (issue #13) - NOT
 * simply that function run backwards. Real differences, all confirmed
 * directly against the raw decompile:
 *
 *   1. The two real `ATIR500SurfaceBuffer*` sources are the SAME PAIR
 *      `resolve_fsaa_buffer` uses (`fixedSurfaceBuffer`, this+0xb94; and
 *      `surfaceBuffersByFormat[formatCode]`, this+0xb70) but with their
 *      ROLES SWAPPED: here `fixedSurfaceBuffer` feeds the
 *      `[0x9a]`/`[0x9c]`/`[0x8a]`/`[0xb3]` slot group (`resolve_fsaa_buffer`
 *      Block A's `surfA`/indexed-by-format role), and
 *      `surfaceBuffersByFormat[formatCode]` feeds the
 *      `[0xa0]`/`[0xa6]`/`[0xa8]`/`[0xaa]` group (`resolve_fsaa_buffer`
 *      Block A's `surfB`/fixed role) - consistent with this being a real
 *      inverse/companion operation, exactly as the function's own real
 *      name (already present in the kext's symbol table) suggests.
 *   2. `resolve_fsaa_buffer`'s real top-level `this+0xbe8`
 *      HyperZ-vs-float-blit strategy split does NOT exist here. Both
 *      surface-descriptor slot groups are computed UNCONDITIONALLY, every
 *      call, with none of `resolve_fsaa_buffer` Block B's real HyperZ-block
 *      machinery (`HZMEM_GetBlockOffset`/`GetBlockCount`, the `0x1395`/
 *      `0x1399`/`0x13a0`-`0x13a2`/`0x1385`/`0x1380` burst shape) anywhere
 *      in this function. `this+0xbe8`'s flag survives only as a single
 *      extra register write (`paramBlock[0xf] = 0xc0001000`) gating on the
 *      SAME real bit test, nothing more.
 *   3. Only 2 real arguments feed the floating-point tail (`param_2`'s
 *      indexed surface, via `fixedSurfaceBuffer`/`surfaceBuffersByFormat`
 *      already read above) - there is no equivalent of
 *      `resolve_fsaa_buffer`'s real `param5`-`param8` viewport-rectangle
 *      arguments; the float tail here computes a single per-axis
 *      half-extent from `fixedSurfaceBuffer`'s own `heightOrRows`/`extra1e`
 *      fields alone, not a caller-supplied rectangle.
 *   4. That same float tail branches on `fixedSurfaceBuffer->tilingDegreeBits`
 *      (a real PER-SURFACE tiling check, distinct from the top-level
 *      `this+0xbe8` accelerator-mode-style flag) to pick between a plain
 *      unsigned int-to-float conversion (no `^0x80000000` sign-flip, no
 *      tiling-degree divide) and a tiling-degree-divided, sign-flipped
 *      conversion matching `resolve_fsaa_buffer`'s own idiom - two
 *      genuinely different real formulas, not a stylistic variation.
 *
 * REAL BUG FOUND AND FIXED IN `resolve_fsaa_buffer` (issue #13) BY THIS
 * INVESTIGATION - see `ATIR500Surface_ResolveFSAABuffer.cpp`'s own header
 * comment for the full account. Cross-checking this function's real
 * `+0x20` field read and real `this+0xbe8` top-level flag read against
 * that file's already-committed transcription surfaced two real
 * misattributions there (a `bytesPerRow` field aliased onto a distinct
 * real `+0x20` field now named `basePitch`, and an `accelerator+0xbe8`
 * read that should have been `this+0xbe8`) - both now corrected in that
 * file, independently re-verified against the FULL raw decompile this
 * pass turned up no further discrepancies.
 *
 * The real "plain, no sign-flip" magic-bias int-to-float conversion this
 * function uses in one branch of its float tail is the SAME real
 * `DOUBLE_0004c3b0` (2^52, `0x4330000000000000`) constant already
 * CONFIRMED and named in `ATIRadeonX1000Registers.h` (issue #14) - not a
 * new discovery, just the first CALLER this project has found for that
 * specific variant (every other real magic-bias use this project has
 * transcribed so far uses the sign-flipped `DOUBLE_0004c3a8` variant).
 *
 * `FUN_00044d74` (the real `0x2f4`-byte blit-state-packet template copy,
 * called once at the very top, same role as `resolve_fsaa_buffer`'s own
 * `FUN_00044868`) is a SEPARATE real lazy-binding stub instance - RESOLVED,
 * issue #15 (live kxld-resolved memory read on real G5/Tiger hardware):
 * confirmed the SAME real external target as `FUN_00044868`, `_memmove`,
 * just this call site's own distinct per-reference stub symbol - see
 * `ATIRadeonX1000Registers.h`.
 *
 * TRANSCRIPTION METHOD: same as `ATIR500Surface_ResolveFSAABuffer.cpp`
 * (flat decompile-derived naming kept close to the original rather than
 * renamed into "cleaner" semantic names; `ATIR500SurfaceBuffer*`-typed
 * field access used in place of raw offset arithmetic wherever the struct
 * already names the field, as a safe non-reinterpreting substitution).
 *
 * Confidence: CONFIRMED for every literal constant and the complete
 * control flow - a real, standalone function (not embedded in one of this
 * project's giant multi-opcode dispatch functions), so its own decompile
 * carries none of the brace-nesting-unreliability risk documented
 * elsewhere in this project for `process_command_buffer`. No C++ compiler
 * was available in the sandboxed environment this was written in (same
 * standing limitation as every other file in this project) - checked by
 * careful, repeated manual re-reading against the raw decompile instead.
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

const double kBias = 4503601774854144.0;      /* DOUBLE_0004c3a8: sign-flipped variant */
const double kPlainBias = 4503599627370496.0; /* DOUBLE_0004c3b0: plain/unsigned variant */

} // namespace

/* (re-ported mechanically: see ATIR500Surface_back_resolve_fsaa_buffer_Port.cpp) */

