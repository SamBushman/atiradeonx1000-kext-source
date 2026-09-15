/*
 * ATIRadeonX1000_TrackRegsWrittenByPM4.cpp
 *
 * RESOLVED (issue #39): `track_regs_written_by_pm4`'s real body, real
 * addr 0x1b180. Declared (with a real-mangled-name `asm` alias) in
 * `Sources/ATIR500GLContext_RestoreState.cpp`, the only real caller;
 * body lives in its own file since it's a plain C-linkage free function,
 * not a class method, and is dense enough to deserve its own writeup.
 *
 * Real signature: `track_regs_written_by_pm4(tracked_register_set
 * *state, unsigned long *rangeStart, unsigned long *rangeEnd)` - walks a
 * real PM4 packet stream, one dword at a time, from `rangeStart` up to
 * (not including) `rangeEnd`, decoding each packet's real 2-bit type
 * field (`header >> 30`) exactly per the standard R5xx PM4 packet
 * format this project already relies on elsewhere:
 *
 * - Type 1 (paired register write, `header>>30==1`): two real 11-bit
 *   register indices packed into the SAME header dword (`header&0x7ff`
 *   and `(header>>11)&0x7ff`), each followed by its own one-dword value
 *   - a real, previously-undocumented PM4 packet shape this project
 *     hadn't transcribed before (every other PM4 consumer in this
 *     project only handles type 0/2/3). Both register/value pairs are
 *     forwarded to `store_reg` (real name, real addr 0x1abe0 - a local/
 *     non-exported symbol, own body RESOLVED, issue #47).
 * - Type 0 (sequential register write, `header>>30==0`): a real base
 *   register index (`header&0x1fff`) and a real dword count
 *   (`(header>>16)&0x3fff`, `0xffffffff`/all-ones meaning "empty/skip",
 *   transcribed exactly as decompiled - the real code checks the full
 *   32-bit sentinel value, not just the 14-bit count field, an
 *   established real PM4 convention). Real bit 15 of the header
 *   (`header&0x8000`) selects between two shapes that this project's
 *   raw decompile treats identically except for whether the register
 *   index increments per written dword ("sequential", bit clear) or
 *   stays fixed ("same register repeatedly", bit set) - both call
 *   `store_reg` once per dword in the real count+1 range.
 * - Type 2 (nop/filler, `header>>30==2`): consumes the header dword
 *   only, no payload - matches this project's existing PM4 type-2
 *   handling elsewhere.
 * - Type 3 (indirect/other, `header>>30==3`): real byte length
 *   `(((header>>16)&0x3fff)<<2) + 8` (a real 14-bit dword count at
 *   header bits `[29:16]`, converted to bytes; the `+8` accounts for the
 *   two header dwords already consumed by every real PM4 packet -
 *   transcribed as the real decompile computes it in one combined
 *   `(header>>0xe)&0xfffc` shift+mask), skipped in full
 *   without inspection - this function does not decode type-3 packet
 *   bodies, matching this project's existing "not every PM4 packet
 *   needs register tracking" convention seen elsewhere.
 *
 * Confidence: CONFIRMED for control flow and every real offset/shift -
 * `rangeStart`/`rangeEnd` are real `unsigned long*` (4-byte-stride PM4
 * dword pointers, the natural real scaling for this type, not a case of
 * this project's own `int*`-scaling trap), and the one place the real
 * code needs a genuine BYTE offset (the type-3 skip) casts through
 * `(int)` explicitly in the real decompile, removing any ambiguity.
 * `store_reg`'s own body is now RESOLVED too (issue #47) - its real role
 * ("write one register/value pair into a `tracked_register_set`") is
 * confirmed by that decompile, not just inferred from this call site.
 * No C++ compiler was available in
 * the sandboxed environment this was written in (same standing
 * limitation as every other file in this project).
 */

#include "../Headers/ATIRadeonX1000Types.h"

struct tracked_register_set;
extern "C" void store_reg(tracked_register_set *state, UInt32 regIndex, UInt32 value) asm("__Z9store_regP20tracked_register_setmm"); /* real name/addr (0x1abe0, local symbol) - RESOLVED, issue #47, see Sources/ATIRadeonX1000_StoreReg.cpp */

extern "C" void track_regs_written_by_pm4(tracked_register_set *state, UInt32 *rangeStart, UInt32 *rangeEnd) asm("__Z25track_regs_written_by_pm4P20tracked_register_setPmS1_");

extern "C" void track_regs_written_by_pm4(tracked_register_set *state, UInt32 *rangeStart, UInt32 *rangeEnd) {
    while (rangeStart < rangeEnd) {
        UInt32 header = *rangeStart;
        UInt32 type = header >> 30;

        if (type == 1) {
            store_reg(state, header & 0x7ff, rangeStart[1]);
            store_reg(state, (header >> 11) & 0x7ff, rangeStart[2]);
            rangeStart += 3;
        } else if (type == 0) {
            UInt32 baseReg = header & 0x1fff;
            UInt32 count = (header >> 16) & 0x3fff;
            rangeStart += 1;
            if (header & 0x8000) {
                /* real: same register index repeated for every dword in the range */
                if (count != 0xffffffff) {
                    for (UInt32 n = 0; n != count + 1; n++) {
                        store_reg(state, baseReg, *rangeStart);
                        rangeStart += 1;
                    }
                }
            } else {
                /* real: register index increments once per written dword */
                if (count != 0xffffffff) {
                    for (UInt32 n = 0; n != count + 1; n++) {
                        store_reg(state, baseReg, *rangeStart);
                        rangeStart += 1;
                        baseReg += 1;
                    }
                }
            }
        } else if (type == 2) {
            rangeStart += 1;
        } else { /* type == 3 */
            rangeStart = reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(rangeStart) + ((header >> 14) & 0xfffc) + 8);
        }
    }
}
