/* NOTE 2026-09-19: 1 function body formerly in this file has been replaced by mechanical ports from the shipped kext's decompile (Sources/*_Port.cpp; marked
   "(re-ported mechanically: ...)" below). The analysis prose in this file describes the earlier hand-written bodies and is kept as history; see README.md,
   "How the code was produced". */
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

/* (re-ported mechanically: see store_reg_Port.cpp) */
