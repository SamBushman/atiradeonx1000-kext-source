/*
 * ATIRadeonX1000_StoreReg.cpp
 *
 * RESOLVED (issue #47): `store_reg`'s real body, real addr 0x1abe0 (a
 * local, non-exported symbol - lowercase `t` in `nm`). Only real caller
 * is `track_regs_written_by_pm4` (issue #39,
 * `Sources/ATIRadeonX1000_TrackRegsWrittenByPM4.cpp`), once per decoded
 * PM4 register/value pair.
 *
 * Real body: a big real binary-search if/else chain over `regIndex`
 * (the real PM4 register index, same units as this project's own
 * `ATIRadeonX1000Registers.h` register table - `regIndex * 4` gives the
 * real MMIO byte offset used there), each leaf writing `value` into one
 * fixed real byte offset of the opaque `tracked_register_set`. CONFIRMED
 * these are genuine flat BYTE offsets (not scaled by any assumed
 * pointee size) via raw PPC disassembly of the GL body's own literal
 * `stw rValue,N(rState)` at every leaf checked. Transcribed here as a
 * real `switch`, behaviorally identical to the real if-chain (a regIndex
 * with no matching case is a real silent no-op, matching the real
 * decompile's fall-through-to-nothing default). Real register NAMES in
 * the comments below are looked up from `ATIRadeonX1000Registers.h`
 * where this project already has one at that MMIO byte offset; a bare
 * hex offset means no name is established yet.
 *
 * One real regIndex (0x1095, `GA_US_VECTOR_DATA`) has a genuinely denser
 * real body instead of a plain single-field write: it accumulates
 * `value` into a small real per-state array (up to 2 real 6-dword
 * "vector" entries starting at `state+0x104`), gated and indexed by a
 * real packed field at `state+0xfc` (the SAME real byte offset
 * `GA_US_VECTOR_INDEX`, regIndex 0x1094, plain-writes elsewhere) - low 9
 * bits a real index/generation counter, bit `0x10000` a real "disabled,
 * ignore every 0x1095 write" gate. Real per-dword sub-position tracked
 * separately at `state+0x100`, reset to 0 and the outer counter advanced
 * by 1 (wrapping the low 9 bits) every 6th dword. Transcribed exactly as
 * decompiled; this project hasn't independently confirmed what real
 * hardware feature ("vector"/uniform constant upload, most likely) this
 * indexed-write protocol implements beyond what's visible here.
 *
 * Confidence: CONFIRMED for every real (regIndex -> offset) mapping and
 * the 0x1095 accumulator's own real control flow (re-checked leaf by
 * leaf against the raw decompile). Real per-field SEMANTIC role beyond
 * "this project's own established register name, if any" is INFERRED
 * only where noted. No C++ compiler was available in the sandboxed
 * environment this was written in (same standing limitation as every
 * other file in this project).
 */

#include "../Headers/ATIRadeonX1000Types.h"

struct tracked_register_set;

extern "C" void store_reg(tracked_register_set *state, UInt32 regIndex, UInt32 value) asm("__Z9store_regP20tracked_register_setmm");

namespace {
inline UInt32 &U32At(tracked_register_set *state, int offset) {
    return *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(state) + offset);
}
} // namespace

extern "C" void store_reg(tracked_register_set *state, UInt32 regIndex, UInt32 value) {
    switch (regIndex) {
    case 0x10ea: U32At(state, 0x00) = value; return; /* SC_EDGERULE */
    case 0x10fa: U32At(state, 0x04) = value; return; /* SC_SCREENDOOR */
    case 0x1006: U32At(state, 0x08) = value; return;
    case 0x1004: U32At(state, 0x0c) = value; return; /* GB_MSPOS0 */
    case 0x1008: U32At(state, 0x14) = value; return; /* GB_AA_CONFIG */
    case 0x10e9: U32At(state, 0x18) = value; return; /* SC_HYPERZ_EN */
    case 0x13c7: U32At(state, 0x1c) = value; return; /* ZB_BW_CNTL */
    case 0x13c1: U32At(state, 0x20) = value; return; /* ZB_ZSTENCILCNTL */
    case 0x850:  U32At(state, 0x24) = value; return; /* VAP_CNTL_STATUS */
    case 0x887:  U32At(state, 0x28) = value; return; /* VAP_CLIP_CNTL */
    case 0x82c:  U32At(state, 0x2c) = value; return; /* VAP_VTE_CNTL */
    case 0x10ae: U32At(state, 0x30) = value; return; /* SU_CULL_MODE */
    case 0x1394: U32At(state, 0x34) = value; return; /* RB3D_DITHER_CTL */
    case 0x1380: U32At(state, 0x38) = value; return; /* RB3D_CCTL */
    case 0x1002: U32At(state, 0x3c) = value; return; /* GB_ENABLE */
    case 0x824:  U32At(state, 0x40) = value; return; /* VAP_OUT_VTX_FMT_0 */
    case 0x825:  U32At(state, 0x44) = value; return; /* VAP_OUT_VTX_FMT_1 */
    case 0x82d:  U32At(state, 0x48) = value; return; /* VAP_VTX_SIZE */
    case 0x854:  U32At(state, 0x4c) = value; return; /* VAP_PROG_STREAM_CNTL_0 */
    case 0x878:  U32At(state, 0x50) = value; return; /* VAP_PROG_STREAM_CNTL_EXT_0 */
    case 0x13c0: U32At(state, 0x54) = value; return; /* ZB_CNTL */
    case 0x12f0: U32At(state, 0x58) = value; return;
    case 0x12f5: U32At(state, 0x5c) = value; return;
    case 0x10a2: U32At(state, 0x60) = value; return; /* GA_POLY_MODE */
    case 0x109e: U32At(state, 0x68) = value; return; /* GA_COLOR_CONTROL */
    case 0x1096: U32At(state, 0x6c) = value; return; /* GA_COLOR_CONTROL_PS3 */
    case 0x1041: U32At(state, 0x70) = value; return; /* TX_ENABLE */
    case 0x1046: U32At(state, 0x74) = value; return; /* GB_PS3_ENABLE */
    case 0x11a9: U32At(state, 0x78) = value; return; /* US_OUT_FMT_0 */
    case 0x11aa: U32At(state, 0x7c) = value; return; /* US_OUT_FMT_1 */
    case 0x11ab: U32At(state, 0x80) = value; return; /* US_OUT_FMT_2 */
    case 0x11ac: U32At(state, 0x84) = value; return; /* US_OUT_FMT_3 */
    case 0x1189: U32At(state, 0x8c) = value; return; /* US_FC_CTRL */
    case 0x1180: U32At(state, 0x88) = value; return; /* US_CONFIG */
    case 0x1181: U32At(state, 0x90) = value; return; /* US_PIXSIZE */
    case 0x118d: U32At(state, 0x94) = value; return; /* US_CODE_RANGE */
    case 0x118e: U32At(state, 0x98) = value; return; /* US_CODE_OFFSET */
    case 0x118c: U32At(state, 0x9c) = value; return; /* US_CODE_ADDR */
    case 0x10c0: U32At(state, 0xa0) = value; return; /* RS_COUNT */
    case 0x10c1: U32At(state, 0xa4) = value; return; /* RS_INST_COUNT */
    case 0x10c8: U32At(state, 0xa8) = value; return; /* RS_INST_0 */
    case 0x101d: U32At(state, 0xac) = value; return; /* RS_IP_0 */
    case 0x138a: U32At(state, 0xb0) = value; return; /* RB3D_COLOROFFSET0 */
    case 0x138e: U32At(state, 0xb4) = value; return; /* RB3D_COLORPITCH0 */
    case 0x1150: U32At(state, 0xbc) = value; return;
    case 0x1040: U32At(state, 0xb8) = value; return; /* TX_INVALTAGS */
    case 0x1100: U32At(state, 0xc0) = value; return;
    case 0x1110: U32At(state, 0xc4) = value; return;
    case 0x1120: U32At(state, 0xc8) = value; return;
    case 0x1130: U32At(state, 0xcc) = value; return;
    case 0x1140: U32At(state, 0xd0) = value; return;
    case 0x10f4: U32At(state, 0xd4) = value; return; /* SC_CLIP_RULE */
    case 0x1383: U32At(state, 0xd8) = value; return; /* RB3D_COLOR_CHANNEL_MASK */
    case 0x1386: U32At(state, 0xdc) = value; return; /* RB3D_ROPCNTL */
    case 0x10f8: U32At(state, 0xe0) = value; return;
    case 0x10f9: U32At(state, 0xe4) = value; return;
    case 0x1080: U32At(state, 0xec) = value; return; /* GA_POINT_S0 */
    case 0x1087: U32At(state, 0xe8) = value; return; /* GA_POINT_SIZE */
    case 0x1082: U32At(state, 0xf4) = value; return; /* GA_POINT_S1 */
    case 0x1083: U32At(state, 0xf8) = value; return; /* GA_POINT_T1 */
    case 0x1381: U32At(state, 0x64) = value; return; /* RB3D_BLENDCNTL */
    case 0x1094: /* GA_US_VECTOR_INDEX */
        U32At(state, 0xfc) = value;
        U32At(state, 0x100) = 0;
        return;
    case 0x1095: { /* GA_US_VECTOR_DATA - real accumulator, see header comment */
        UInt32 indexAndFlags = U32At(state, 0xfc);
        if ((indexAndFlags & 0x10000) != 0) {
            return;
        }
        UInt32 subIndex = indexAndFlags & 0x1ff;
        SInt32 pos = static_cast<SInt32>(U32At(state, 0x100));
        if (subIndex < 2) {
            U32At(state, (subIndex * 6 + pos) * 4 + 0x104) = value;
        }
        pos = pos + 1;
        U32At(state, 0x100) = static_cast<UInt32>(pos);
        if (pos < 6) {
            return;
        }
        U32At(state, 0x100) = 0;
        U32At(state, 0xfc) = (indexAndFlags & 0xfffffe00) | ((subIndex + 1) & 0x1ff);
        return;
    }
    default:
        return;
    }
}
