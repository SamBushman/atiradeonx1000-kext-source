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

UInt32 *ATIR500Surface::load_3d_blit(UInt32 *dest, ATIR500SurfaceBuffer *scratch) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *accel = *reinterpret_cast<UInt8 **>(self + 0xd50);
    UInt32 *rec = dest;

    UInt32 tilingDeg = (scratch->tilingDegreeBits >> 0x14) & 0xf;
    UInt32 sampleMaskWord;   /* real uVar10 */
    UInt32 sampleEnableWord; /* real uVar11 */
    if (tilingDeg < 2) {
        sampleEnableWord = 0;
        sampleMaskWord = 0xffffff;
    } else {
        UInt32 bits = (1u << tilingDeg) - 1;
        sampleEnableWord = (kSamplesTable[tilingDeg] << 1) | 1;
        sampleMaskWord = bits | (bits * 0x40000) | (bits * 0x1000) | (bits * 0x40);
    }

    rec[7] = sampleMaskWord;
    rec[0] = 0x1393;
    rec[1] = 10;
    rec[2] = 0x13c6;
    rec[3] = 3;
    rec[4] = 0x5c8;
    rec[8] = 0x11004;
    rec[5] = 0x20000;
    rec[6] = 0x10fa; /* SC_SCREENDOOR */
    rec[9] = kMspos0Table[((scratch->tilingDegreeBits >> 0x12) & 0x3c) / 4];
    rec[0xb] = 0x1008; /* GB_AA_CONFIG */
    rec[0xc] = sampleEnableWord;
    rec[0xe] = 0;
    rec[0xd] = 0x1383; /* RB3D_COLOR_CHANNEL_MASK */
    rec[0xf] = 0x1006;
    rec[10] = kMspos1Table[((scratch->tilingDegreeBits >> 0x12) & 0x3c) / 4];
    rec[0x11] = 0x13c7; /* ZB_BW_CNTL */
    rec[0x12] = 0xc;
    rec[0x14] = 0;
    rec[0x13] = 0x10e9; /* SC_HYPERZ_EN */
    rec[0x10] = *reinterpret_cast<UInt32 *>(accel + 0xb74); /* real accelerator-relative constant this project never independently named - same field ResolveFSAABuffer.cpp/RegisterState.cpp already read raw */
    rec[0x15] = 0x13c4;
    rec[0x16] = (scratch->formatTableIndex != 0x10) ? 2 : 0; /* real: -(formatTableIndex^0x10)>>0x1e & 2, an "!= 0x10" test in disguise - see file header comment */
    rec[0x17] = 0x113c8;
    rec[0x18] = scratch->gpuBaseAddress;

    bool hasTiling = (scratch->tilingDegreeBits & 0xf00000) != 0;
    UInt32 blockDivisor = (scratch->tilingDegreeBits >> 0x14) & 0xf;
    UInt32 widthOverDiv = hasTiling ? (static_cast<UInt32>(scratch->width) / blockDivisor) : 0;
    UInt32 minBlockCount = 0x20 / scratch->bytesPerRow;
    UInt32 blockCount = (widthOverDiv < minBlockCount) ? minBlockCount : widthOverDiv;
    rec[0x19] = (static_cast<UInt32>(scratch->tilingConfigByte0 & 6) << 0x10) |
                (static_cast<UInt32>(scratch->tilingConfigByte0 & 1) << 0x10) |
                (static_cast<UInt32>(scratch->tilingConfigByte1 & 3) << 0x13) |
                (blockCount & 0x3ffc);

    UInt32 hzDivisor = *reinterpret_cast<UInt32 *>(accel + 0xb98); /* real accelerator-relative constant this project never independently named (same field ResolveFSAABuffer.cpp/AllocSurfaceBuffer.cpp already read raw) */
    UInt32 widthOverDiv2 = hasTiling ? (static_cast<UInt32>(scratch->width) / blockDivisor) : 0;
    UInt32 minBlockCount2 = minBlockCount;
    if (minBlockCount2 <= widthOverDiv2) {
        minBlockCount2 = widthOverDiv2;
    }
    UInt32 pitchAlignedVal;
    if (hzDivisor == 4) {
        pitchAlignedVal = 0x20 * static_cast<UInt32>((static_cast<SInt32>(minBlockCount2 + 0x20 - 1)) / 0x20);
    } else {
        UInt32 stride = hzDivisor << 4;
        if (stride == 0) {
            pitchAlignedVal = 0;
        } else {
            pitchAlignedVal = stride * static_cast<UInt32>((static_cast<SInt32>(minBlockCount2 + stride - 1)) / static_cast<SInt32>(stride));
        }
    }
    rec[0x1a] = 0x13cd;
    rec[0x1b] = pitchAlignedVal;

    UInt32 hzBlockOffset = HZMEM_GetBlockOffset(reinterpret_cast<_HZDATA *>(accel + 0x870), scratch->hzBlockField, 0);
    rec[0x1c] = 0x13cc;
    rec[0x1d] = hzBlockOffset;
    rec[0x1e] = 0x13ca;
    rec[0x1f] = scratch->hzBlockExtra;

    rec[0x21] = 0;
    rec[0x23] = 0;
    rec[0x25] = 0;
    rec[0x27] = 0;
    rec[0x20] = 0x1041; /* TX_ENABLE */
    rec[0x22] = 0x1180; /* US_CONFIG */
    rec[0x2d] = 0;
    rec[0x2f] = 0;
    rec[0x31] = 0;
    rec[0x3d] = 0;
    rec[0x40] = 0;
    rec[0x24] = 0x13c0; /* ZB_CNTL */
    rec[0x26] = 0x13c1; /* ZB_ZSTENCILCNTL */
    rec[0x28] = 0x850;  /* VAP_CNTL_STATUS */
    rec[0x29] = 0x102;
    rec[0x2a] = 0x887;  /* VAP_CLIP_CNTL */
    rec[0x2e] = 0x10ae; /* SU_CULL_MODE */
    rec[0x2c] = 0x82c;  /* VAP_VTE_CNTL */
    rec[0x32] = 0x824;  /* VAP_OUT_VTX_FMT_0 */
    rec[0x30] = 0x1002; /* GB_ENABLE */
    rec[0x33] = 1;
    rec[0x34] = 0x825;  /* VAP_OUT_VTX_FMT_1 */
    rec[0x36] = 0x82d;  /* VAP_VTX_SIZE */
    rec[0x38] = 0x854;  /* VAP_PROG_STREAM_CNTL_0 */
    rec[0x39] = 0x26000001;
    rec[0x3a] = 0x878;  /* VAP_PROG_STREAM_CNTL_EXT_0 */
    rec[0x35] = 4;
    rec[0x37] = 3;
    rec[0x3c] = 0x1094; /* GA_US_VECTOR_INDEX */
    rec[0x2b] = 0x1c000;
    rec[0x3b] = 0xfb24fb08;
    rec[0x3e] = 0x00059095; /* real literal pointer constant this project never independently named - see file header comment */
    rec[0x3f] = 0x78105;
    rec[0x41] = 0;
    rec[0x44] = 0x20490000;
    rec[0x45] = 0x1181; /* US_PIXSIZE */
    rec[0x56] = 4;
    rec[0x60] = 0;
    rec[0x46] = 0;
    rec[0x48] = 0;
    rec[0x4a] = 0;
    rec[0x4c] = 0;
    rec[0x58] = 0;
    rec[0x47] = 0x118d; /* US_CODE_RANGE */
    rec[0x49] = 0x118e; /* US_CODE_OFFSET */
    rec[0x4b] = 0x118c; /* US_CODE_ADDR */
    rec[0x4d] = 0x11a9; /* US_OUT_FMT_0 */
    rec[0x4e] = 0x1b00;
    rec[0x4f] = 0x11aa; /* US_OUT_FMT_1 */
    rec[0x51] = 0x11ab; /* US_OUT_FMT_2 */
    rec[0x53] = 0x11ac; /* US_OUT_FMT_3 */
    rec[0x55] = 0x10c0; /* RS_COUNT */
    rec[0x57] = 0x10c1; /* RS_INST_COUNT */
    rec[0x59] = 0x10c8; /* RS_INST_0 */
    rec[0x5a] = 0x10;
    rec[0x54] = 0xf;
    rec[0x42] = 0xdb06d8;
    rec[0x50] = 0xf;
    rec[0x5d] = 0x10f4; /* SC_CLIP_RULE */
    rec[0x52] = 0xf;
    rec[0x5f] = 0x10f8;
    rec[0x43] = 0xc18000;
    rec[0x5c] = 0xc2040;
    rec[0x61] = 0x10f9;
    rec[0x5b] = 0x101d; /* RS_IP_0 */
    rec[0x5e] = 0xffff;

    /* real: these three (rec[0x62], stride60000/rec[100], rec[0x67]) use
       heightOrRows (+0x1c), NOT width (+0x14) - distinct from rec[0x19]'s
       and pitchAlignedVal's own width-based divisions above; re-verified
       directly against the raw decompile before writing this. */
    if (!hasTiling) {
        rec[0x62] = (static_cast<UInt32>(scratch->extra1e) & 0x1fff) << 0xd;
    } else {
        rec[0x62] = ((static_cast<UInt32>(scratch->heightOrRows) / blockDivisor) & 0x1fff) |
                    ((static_cast<UInt32>(scratch->extra1e) & 0x1fff) << 0xd);
    }

    UInt32 stride60000 = hasTiling ? (static_cast<UInt32>(scratch->heightOrRows) / blockDivisor) * 0x60000 : 0;
    rec[0x65] = 0xc0033500;
    rec[99] = 0x1087; /* GA_POINT_SIZE */
    rec[100] = ((static_cast<UInt32>(scratch->extra1e) * 6) & 0xffff) | stride60000;
    rec[0x66] = 0x10031;
    if (!hasTiling) {
        rec[0x67] = 0;
    } else {
        UInt32 quotient = static_cast<UInt32>(scratch->heightOrRows) / blockDivisor;
        UInt32 raw = (static_cast<UInt32>(static_cast<SInt32>(quotient) >> 1)) ^ 0x80000000u;
        rec[0x67] = static_cast<UInt32>(BiasedIntToFloat(raw, kBias));
    }

    rec[0x69] = 0;
    rec[0x6a] = 0x13c6;
    rec[0x6b] = 3;
    {
        UInt32 raw = (static_cast<UInt32>(scratch->extra1e) >> 1) ^ 0x80000000u;
        rec[0x68] = static_cast<UInt32>(BiasedIntToFloat(raw, kBias));
    }

    /* real short-circuit &&/|| with a side-effecting comma operator -
       rewritten as an equivalent explicit nested-if, see file header
       comment for the verified-equivalent derivation. */
    UInt32 zbExtra = 0;
    if (scratch->zbBandwidthEligible != 0) {
        if (scratch->bytesPerRow > 2) {
            zbExtra = 0x1c;
        } else {
            zbExtra = 4;
            if (blockDivisor > 2) {
                zbExtra = 0x1c;
            }
        }
    }
    rec[0x6c] = 0x13c7; /* ZB_BW_CNTL */
    rec[0x6d] = zbExtra;
    rec[0x6e] = 0x1393;
    rec[0x6f] = 10;
    rec[0x70] = 0x5c8;
    rec[0x71] = 0x20000;

    return rec + 0x72;
}
