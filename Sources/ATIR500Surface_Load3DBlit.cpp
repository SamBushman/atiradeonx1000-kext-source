/* NOTE 2026-09-19: 1 function body formerly in this file has been replaced by mechanical ports from the shipped kext's decompile (Sources/*_Port.cpp; marked
   "(re-ported mechanically: ...)" below). The analysis prose in this file describes the earlier hand-written bodies and is kept as history; see README.md,
   "How the code was produced". */
/*
 * ATIR500Surface_Load3DBlit.cpp
 *
 * RESOLVED (issue #47): `ATIR500Surface::load_3d_blit`'s real body, real
 * addr 0x3d4c0. Only real caller is `decompress_and_flush_depth_buffer`
 * (issue #38, `Sources/ATIR500Surface_DecompressAndFlushDepthBuffer.cpp`)
 * when the scratch buffer's real `+0x34` byte is nonzero - emits a real,
 * dense sequence of PM4 register-index/value pairs (a "3D blit state"
 * setup, matching this project's own already-resolved GLOBAL template
 * `g_r500_3d_blit_state_packet`, issue #14,
 * `Sources/ATIRadeonX1000_DataTables.cpp` - the two share several
 * leading literal dwords exactly, e.g. `0x1393`/`10`/`0x13c6`/`3`/
 * `0x5c8`/`0x20000`, a real independent cross-check that this
 * transcription's constant writes are correct - but are otherwise
 * DIFFERENT real functions: `load_3d_blit` computes most of its own
 * fields live from the passed-in `ATIR500SurfaceBuffer`, the global
 * template does not) into `dest`, and returns `dest + 0x72` (dwords)
 * always - the caller's own `(end - record) >> 2` dword-count
 * conversion already established this real return shape.
 *
 * Real register NAMES in the comments below come from this project's
 * own `ATIRadeonX1000Registers.h` (`regIndex * 4` = real MMIO byte
 * offset) wherever already established; a bare hex literal means no
 * name is established yet. Two real per-format-degree lookup tables
 * this function reads are real, CONFIRMED-distinct local statics (real
 * mangled names `...load_3d_blitEPmP20ATIR500SurfaceBufferE11mspos0Table`/
 * `mspos1Table`/`12samplesTable`, kext addresses 0x4c2d8/0x4c2bc/0x4c2f4
 * respectively) - NOT the same symbol as the already-resolved GLOBAL
 * `_samplesTable` (`SamplesTableLookup`, kext address 0x4c268, issue
 * #14) despite the identical short name; real content read directly out
 * of the kext binary via Ghidra, same as that global table.
 *
 * `ATIR500SurfaceBuffer`'s own `+0x2c` field (`hzBlockExtra`) was
 * previously unnamed padding - `load_3d_blit` is the first real reader
 * found this pass, promoting it to a named (if still role-INFERRED)
 * field (`Headers/ATIRadeonX1000Types.h`).
 *
 * Two places translate a genuinely tricky real C idiom into equivalent,
 * clearer C++ rather than a literal transcription (both verified
 * mathematically equivalent to the real decompile, not simplified
 * approximations):
 * - The real "magic-bias" int-to-float conversions (`param_1[0x67]`/
 *   `[0x68]`) use this project's own already-established
 *   `BiasedIntToFloat` helper (`Sources/ATIR500GLContext_FSAAResolveBlit.cpp`
 *   and others) with `kBias = 4503601774854144.0`, the same real
 *   sign-flip variant used throughout this project.
 * - `rec[0x16]`'s real expression (`-(formatTableIndex ^ 0x10) >> 0x1e &
 *   2`) is a real "is formatTableIndex exactly 0x10?" test in disguise
 *   (arithmetic-shift sign-extension of a small negative int) -
 *   rewritten as the equivalent `(formatTableIndex != 0x10) ? 2 : 0`.
 * - The real short-circuit `&&`/`||` expression computing `rec[0x6d]`
 *   (real side-effecting comma operator inside the `||`) is rewritten as
 *   the equivalent explicit nested-if form for readability; the real
 *   surviving-side-effect case (`zbBandwidthEligible` set, `bytesPerRow
 *   <= 2`, tiling degree `<= 2` -> value stays `4`) is preserved exactly.
 *
 * Confidence: CONFIRMED for control flow and every real (index, value)
 * pair against the raw Ghidra decompile - this function's sheer size
 * made a full independent raw-disassembly re-check impractical this
 * pass (unlike some of this project's smaller dense functions), so
 * treat individual literal values as CONFIRMED-from-decompile rather
 * than CONFIRMED-from-raw-disassembly. Real per-field HARDWARE meaning
 * beyond "this is the value written to this named/unnamed register" is
 * UNKNOWN except where already independently established elsewhere in
 * this project. The real literal pointer constant at `rec[0x3e]`
 * (`&DAT_00059095`) is transcribed as a raw address, matching this
 * project's own established precedent for an un-named literal pointer
 * constant (`ATIR500GLContext_RestoreState.cpp`'s own `&DAT_000110f8`
 * note) - this project's sandboxed Ghidra environment could not read
 * live bytes at that address to say more. No C++ compiler was available
 * in the sandboxed environment this was written in (same standing
 * limitation as every other file in this project).
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
const double kBias = 4503601774854144.0;

/* Real local static, kext addr 0x4c2f4 - see file header comment for why
   this is NOT the same symbol as the already-resolved global _samplesTable. */
const UInt32 kSamplesTable[16] = {
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000002, 0x00000000, 0x00000003, 0x00005b00,
    0x00008650, 0x0000c4f0, 0x0000f040, 0x00014130,
    0x00018910, 0x00019a50, 0x0001b3f0, 0x000273f0,
};

/* Real local static, kext addr 0x4c2d8. */
const UInt32 kMspos0Table[16] = {
    0x66666666, 0x66666666, 0x33393993, 0x66666666,
    0x11a4417a, 0x66666666, 0x11951153, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000002,
    0x00000000, 0x00000003, 0x00005b00, 0x00008650,
};

/* Real local static, kext addr 0x4c2bc. */
const UInt32 kMspos1Table[16] = {
    0x06666666, 0x06666666, 0x03393939, 0x06666666,
    0x01171717, 0x06666666, 0x017b37b9, 0x66666666,
    0x66666666, 0x33393993, 0x66666666, 0x11a4417a,
    0x66666666, 0x11951153, 0x00000000, 0x00000000,
};

} // namespace

/* (re-ported mechanically: see ATIR500Surface_load_3d_blit_Port.cpp) */

