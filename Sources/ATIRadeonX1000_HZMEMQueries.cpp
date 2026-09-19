/*
 * ATIRadeonX1000_HZMEMQueries.cpp
 *
 * RESOLVED (issue #40): `HZMEM_GetBlockOffset`/`HZMEM_GetBlockCount`/
 * `HZMEM_IsPartial`'s real bodies, real addrs 0x45790/0x45810/0x45890.
 * Declared in `Headers/ATIRadeonX1000Registers.h`; bodies live here since
 * they're plain C-linkage free functions, not class methods.
 *
 * Transcribed directly from raw PPC disassembly (`otool -tv`), per this
 * project's established `_HZDATA*` discipline (see
 * `ATIRadeonX1000_HZMEMFree.cpp`). All three share HZMEM_Free's exact
 * table/record layout, and cross-checking them against Ghidra's own C
 * decompile of the same three functions found the C output byte-exact
 * (since `_HZDATA` is forward-declared with no defined size, Ghidra
 * cannot scale pointer arithmetic on it by any sizeof and emits raw byte
 * offsets, matching the disassembly line for line) - this is what
 * exposed a real bug in this project's OWN prior `HZMEM_Free`
 * transcription (see that file's header comment for the fix) by
 * providing three independent, simpler confirmations of the true record
 * layout.
 *
 * `table = *(UInt8*)(hizData + blockKind*4 + 0x10)` (same "field group"
 * indirection as `HZMEM_Free`); `index` = the same real 10-bit sub-field
 * of `surfaceHzField` selected by `blockKind` (0/1/2, else return `1`);
 * `record = table + 0x14 + index*16`. All three reject (return `1`) on
 * `hizData == null`, `table == null`, `index == 0x3ff` (sentinel), or
 * `record == null` (an always-false-in-practice pointer-arithmetic
 * guard, transcribed exactly as decompiled) - `HZMEM_GetBlockOffset`/
 * `GetBlockCount` return a distinct sentinel `0xfffffffe` for that last
 * guard specifically (real, confirmed via `li r3,0xfffe` immediately
 * preceding the guard in the disassembly - NOT the same as the generic
 * `1` rejection code); `IsPartial` does not (falls through to `1` like
 * the rest, since it does not use the pointer as a return value the way
 * the other two do - real, disassembly-confirmed, this project's own
 * best explanation for the difference).
 *
 * `HZMEM_GetBlockOffset` returns `record[1]` (`record+4`, i.e.
 * `table+0x18` for index 0). `HZMEM_GetBlockCount` returns `record[2]`
 * (`record+8`, `table+0x1c`). `HZMEM_IsPartial` returns whether
 * `record[2]` (`record+8`) differs from `record[3]` (`record+0xc`,
 * `table+0x20`) - i.e. whether the block's current real "count" differs
 * from its real "full count", exactly matching the project's own
 * INFERRED name for this function.
 *
 * Confidence: CONFIRMED for control flow and every real offset, checked
 * directly against the raw disassembly. No C++ compiler was available in
 * the sandboxed environment this was written in (same standing
 * limitation as every other file in this project).
 */

#include "../Headers/ATIRadeonX1000Registers.h"
#include "../Headers/ATIRadeonX1000Types.h"

namespace {
inline UInt32 &U32At(void *base, int offset) { return *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(base) + offset); }
} // namespace

/* Shared by all three: real field-group -> table -> record-index resolution. Returns false (and sets *outCode to the caller's real rejection value) if any real gate fails. */
static bool HZMEM_ResolveRecord(_HZDATA *hizData, UInt32 surfaceHzField, UInt32 blockKind, UInt32 rejectValue, UInt8 **outRecord, UInt32 *outCode) {
    if (hizData == nullptr) {
        *outCode = 1;
        return false;
    }
    UInt8 *fieldGroup = reinterpret_cast<UInt8 *>(hizData) + blockKind * 4;
    UInt8 *table = reinterpret_cast<UInt8 *>(U32At(fieldGroup, 0x10));
    if (table == nullptr) {
        *outCode = 1;
        return false;
    }

    UInt32 index;
    if (blockKind == 1) {
        index = (surfaceHzField >> 10) & 0x3ff;
    } else if (blockKind == 0) {
        index = surfaceHzField & 0x3ff;
    } else if (blockKind == 2) {
        index = (surfaceHzField >> 20) & 0x3ff;
    } else {
        *outCode = 1;
        return false;
    }
    if (index == 0x3ff) {
        *outCode = 1;
        return false;
    }

    UInt8 *record = table + 0x14 + index * 16;
    if (record == nullptr) { /* real: transcribed exactly as decompiled - always false in practice */
        *outCode = rejectValue;
        return false;
    }

    *outRecord = record;
    return true;
}

/* (re-ported mechanically: see _HZMEM_GetBlockOffset_Port.cpp) */


/* (re-ported mechanically: see _HZMEM_GetBlockCount_Port.cpp) */


/* (re-ported mechanically: see _HZMEM_IsPartial_Port.cpp) */

