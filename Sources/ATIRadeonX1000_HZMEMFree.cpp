/* NOTE 2026-09-19: 1 function body formerly in this file has been replaced by mechanical ports from the shipped kext's decompile (Sources/*_Port.cpp; marked
   "(re-ported mechanically: ...)" below). The analysis prose in this file describes the earlier hand-written bodies and is kept as history; see README.md,
   "How the code was produced". */
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
 * SECOND FIX this pass (issue #40 sweep): re-tracing this same raw
 * disassembly instruction-by-instruction while decompiling this
 * function's siblings (`HZMEM_GetBlockOffset`/`GetBlockCount`/
 * `IsPartial`) found this file's OWN prior "corrected" version was
 * itself still wrong in two spots - the real `table` header is 0x14
 * bytes (`table[0]`=bound, `table[1]`=unitSize, `table[3]`=tableBase,
 * `table[4]`=refcount, matching the prior version), but the per-index
 * RECORD array does not start at `table + index*16` - it starts at
 * `table + 0x14 + index*16` (`record`). The two real fields this
 * function reads for `start`/`end` are `record[1]`/`record[2]` (byte
 * offsets `record+4`/`record+8`, i.e. ABSOLUTE `table+0x18`/`table+0x1c`
 * for index 0) - previously mistranscribed as `slot[1]`/`slot[2]` at
 * `table+4`/`table+8` (colliding with the table's OWN header fields).
 * And the final "clear" write on success targets `record[0]`
 * (`record+0`, i.e. `table+0x14` for index 0) - previously
 * mistranscribed as `slot[0]` (`table+0`, the table's own bound field -
 * would have corrupted the table header on every real free!). Real
 * per-index record layout (16-byte stride, CONFIRMED CROSS-REFERENCE:
 * these same three fields are exactly what
 * `HZMEM_GetBlockOffset`/`GetBlockCount`/`IsPartial` read, at the same
 * real offsets from the same real `record` base - see
 * `ATIRadeonX1000_HZMEMQueries.cpp`): `record[0]` = valid/occupied flag
 * (`HZMEM_Alloc` sets it to `1`, this function clears it to `0` on
 * free), `record[1]` (`+4`) = real "offset" field (also
 * `HZMEM_GetBlockOffset`'s return value), `record[2]` (`+8`) = real
 * "count" field (also `HZMEM_GetBlockCount`'s return value), `record[3]`
 * (`+0xc`) = a second real "count" field (`HZMEM_IsPartial` compares
 * `record[2]` against this one).
 *
 * Real signature: `HZMEM_Free(_HZDATA *hizData, unsigned long
 * surfaceHzField, unsigned long blockKind)`. `blockKind` (0/1/2, else
 * rejected) selects a real 10-bit sub-field out of `surfaceHzField`
 * (bits `[9:0]`/`[19:10]`/`[29:20]` respectively) as a real record
 * index. `hizData + blockKind*4` is a real "field group" base; its own
 * `+0x10` field is a real per-blockKind tracking table pointer
 * (`table`).
 *
 * Real bounds/no-op checks (each returns `1`, this project's established
 * "rejected/no-op" code for this function family): `hizData == null`,
 * `table == null`, `index == 0x3ff` (sentinel), `record + 0 == null`
 * (transcribed exactly as the real code checks it - an always-false-in-
 * practice pointer-arithmetic guard, computed as `record` itself since
 * the header's own `+0x14` offset has already been folded in), `table`'s
 * own real "unit size" field (`table[1]`) nonzero but the resulting
 * `[start,end)` range (real per-record raw fields `record[1]`/
 * `record[2]`, each divided by `table[1]`) exceeds `table`'s own real
 * bound field (`table[0]`), or `table`'s own real base-pointer field
 * (`table[3]`) is null.
 *
 * Otherwise: if `start < end`, zeroes the real byte range
 * `[table[3]+start, table[3]+end)` in place; clears the record's own
 * flag word (`record[0] = 0`); decrements a real refcount at `table[4]`
 * (`table`'s own `+0x10` byte field); returns `0` (success).
 *
 * Confidence: CONFIRMED for control flow and every real offset - checked
 * directly against the raw disassembly, not just Ghidra's C decompile,
 * TWICE now (issue #28 and this pass). No C++ compiler was available in
 * the sandboxed environment this was written in (same standing
 * limitation as every other file in this project).
 */

#include "../Headers/ATIRadeonX1000Registers.h"
#include "../Headers/ATIRadeonX1000Types.h"

namespace {
inline UInt32 &U32At(void *base, int offset) { return *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(base) + offset); }
} // namespace

/* (re-ported mechanically: see _HZMEM_Free_Port.cpp) */

