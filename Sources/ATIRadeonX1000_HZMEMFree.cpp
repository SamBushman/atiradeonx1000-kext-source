/*
 * ATIRadeonX1000_HZMEMFree.cpp
 *
 * RESOLVED (issue #28): `HZMEM_Free`'s real body, real addr 0x45680.
 * Declared in `Headers/ATIRadeonX1000Registers.h`; body lives here since
 * it's a plain C-linkage free function, not a class method.
 *
 * Transcribed directly from raw PPC disassembly (`otool -tv`), NOT from
 * Ghidra's own C-level decompile of this function - `_HZDATA` is an
 * intentionally opaque, never-defined struct (see
 * `ATIRadeonX1000Registers.h`'s own note), so Ghidra's C output performs
 * pointer arithmetic on `_HZDATA *` using an assumed (and unverifiable)
 * sizeof; the raw instructions have no such ambiguity. This caught a
 * real mistake in an earlier draft of this file that trusted Ghidra's C
 * output at face value and misattributed several table-level fields as
 * per-record fields - see git history for that draft; this is the
 * corrected version, re-verified line-by-line against the real
 * disassembly.
 *
 * Real signature: `HZMEM_Free(_HZDATA *hizData, unsigned long
 * surfaceHzField, unsigned long blockKind)`. `blockKind` (0/1/2, else
 * rejected) selects a real 10-bit sub-field out of `surfaceHzField`
 * (bits `[9:0]`/`[19:10]`/`[29:20]` respectively) as a real record
 * index. `hizData + blockKind*4` is a real "field group" base; its own
 * `+0x10` field is a real per-blockKind tracking table pointer
 * (`table`). The record index selects a real 16-byte record within that
 * table, `table + index*16` (`slot`).
 *
 * Real bounds/no-op checks (each returns `1`, this project's established
 * "rejected/no-op" code for this function family): `hizData == null`,
 * `table == null`, `index == 0x3ff` (sentinel), `slot + 0x14 == null`
 * (transcribed exactly as the real code checks it, an always-false-in-
 * practice pointer-arithmetic guard), `table`'s own real "unit size"
 * field (`table[1]`) nonzero but the resulting `[start,end)` range (real
 * per-record raw fields `slot[1]`/`slot[2]`, each divided by
 * `table[1]`) exceeds `table`'s own real bound field (`table[0]`), or
 * `table`'s own real base-pointer field (`table[3]`) is null.
 *
 * Otherwise: if `start < end`, zeroes the real byte range
 * `[table[3]+start, table[3]+end)` in place; clears the record's own
 * word 0 (`slot[0] = 0`); decrements a real refcount at `table[4]`
 * (`table`'s own `+0x10` byte field); returns `0` (success).
 *
 * Confidence: CONFIRMED for control flow and every real offset - checked
 * directly against the raw disassembly, not just Ghidra's C decompile.
 * No C++ compiler was available in the sandboxed environment this was
 * written in (same standing limitation as every other file in this
 * project).
 */

#include "../Headers/ATIRadeonX1000Registers.h"
#include "../Headers/ATIRadeonX1000Types.h"

namespace {
inline UInt32 &U32At(void *base, int offset) { return *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(base) + offset); }
} // namespace

UInt32 HZMEM_Free(_HZDATA *hizData, UInt32 surfaceHzField, UInt32 blockKind) {
    if (hizData == nullptr) {
        return 1;
    }
    UInt8 *fieldGroup = reinterpret_cast<UInt8 *>(hizData) + blockKind * 4;
    UInt8 *table = reinterpret_cast<UInt8 *>(U32At(fieldGroup, 0x10));
    if (table == nullptr) {
        return 1;
    }

    UInt32 index;
    if (blockKind == 1) {
        index = (surfaceHzField >> 10) & 0x3ff;
    } else if (blockKind == 0) {
        index = surfaceHzField & 0x3ff;
    } else if (blockKind == 2) {
        index = (surfaceHzField >> 20) & 0x3ff;
    } else {
        return 1;
    }
    if (index == 0x3ff) {
        return 1;
    }

    UInt8 *slot = table + index * 16;
    if (slot + 0x14 == nullptr) { /* real: transcribed exactly as decompiled - always false in practice */
        return 1;
    }

    UInt32 tableUnitSize = U32At(table, 4);
    UInt32 start, end;
    if (tableUnitSize == 0) {
        start = 0;
        end = 0;
    } else {
        start = U32At(slot, 4) / tableUnitSize;
        end = start + U32At(slot, 8) / tableUnitSize;
        if (U32At(table, 0) < end) {
            return 1;
        }
    }

    UInt32 tableBase = U32At(table, 0xc);
    if (tableBase == 0) {
        return 1;
    }

    if (start < end) {
        UInt8 *p = reinterpret_cast<UInt8 *>(tableBase + start);
        for (UInt32 n = end - start; n != 0; n--) {
            *p++ = 0;
        }
    }
    U32At(slot, 0) = 0;
    U32At(table, 0x10) -= 1;
    return 0;
}
