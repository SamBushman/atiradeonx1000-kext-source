/*
 * ATIRadeonX1000_HZMEMAlloc.cpp
 *
 * RESOLVED (issue #40): `HZMEM_Alloc`'s real body, real addr 0x45350.
 * Declared in `Headers/ATIRadeonX1000Registers.h`; body lives here since
 * it's a plain C-linkage free function, not a class method.
 *
 * REAL SIGNATURE CORRECTED this pass: this project's prior INFERRED
 * parameter names (`existingBlockOrSentinel`, `chainFlag`) were wrong.
 * The real 2nd parameter is `surfaceHzField` - the SAME rolling packed
 * bitfield value `HZMEM_Free`/`GetBlockOffset`/`GetBlockCount`/
 * `IsPartial` all take, confirmed by this function's own real final
 * packing step, which reads the OTHER (non-`blockKind`) bitfields
 * straight out of it and writes the newly allocated index into the one
 * `blockKind` selects - exactly mirroring those siblings' own bit
 * layout (`[9:0]`/`[19:10]`/`[29:20]` for `blockKind` 0/1/2). The real
 * 3rd parameter is `blockKind` itself (0/1/2, else rejected - same real
 * role as every sibling function), not a boolean "chain" flag. Real
 * call-site shapes (`ATIR500GLContext_ProcessCommandBuffer.cpp`'s
 * opcode 0x41 body): a first call with `blockKind=0` and
 * `surfaceHzField=0xffffffff` (all-bits-set - a real "nothing allocated
 * yet" sentinel for a value whose bits are all consumed by real
 * sub-fields), producing a real updated `surfaceHzField` that a second
 * call then passes back in with `blockKind=1` to allocate the sibling
 * block while preserving the first allocation's own bits.
 *
 * Table/record layout CONFIRMED identical to `HZMEM_Free`/
 * `HZMEM_GetBlockOffset`/`GetBlockCount`/`IsPartial` (`table = *(hizData
 * + blockKind*4 + 0x10)`; `record = table + 0x14 + index*16`) - the
 * opening table lookup and every `_HZDATA*`/`table`-pointer-arithmetic
 * expression below was independently checked against raw PPC
 * disassembly (`otool -tv`) and found byte-exact to Ghidra's own C
 * decompile, same as every sibling function. The interior bitmap-scan
 * and "extend an existing chain" fallback logic (this function's own
 * real allocation strategy - not shared with any sibling) was traced
 * against the raw disassembly for structure and register roles (see
 * git history / session notes for the full instruction-by-instruction
 * cross-check) but not re-verified instruction-by-instruction to the
 * same exhaustive standard as the four simpler siblings, given its
 * size (~150 real instructions) - flagged INFERRED-with-strong-basis
 * below, not blindly trusted from Ghidra's C output alone.
 *
 * Two real "table" fields not seen in any sibling function, both newly
 * found this pass: `table[2]` (`+8`) - a real total-byte-capacity limit
 * for the bitmap sub-allocator (checked as `tableUnitSize*(pos+
 * neededSlots) <= table[2]` before committing an "extend existing
 * chain" allocation). `hizData+4`/`hizData+8` (NOT table-relative - real
 * global per-`_HZDATA` tile-granularity units) - `tileDim`/`size` are
 * real, disassembly-confirmed to be validated as exact multiples of
 * these (a nonzero remainder rejects the whole call), matching the same
 * pattern as `HZMEM_Free`'s already-known unit-scaling of raw byte
 * ranges. Real division-by-zero if either unit is genuinely `0` -
 * transcribed exactly as decompiled/disassembled (this project's own
 * standing "no invented safety the real code doesn't have" rule), not
 * expected to occur in practice.
 *
 * Real algorithm: computes a real "needed slot count" from
 * `tileDim`/`size` (converted to a unit count, then rounded up to a
 * whole multiple of the table's own `unitSize`, `table[1]`). If the
 * table's own refcount (`table[0x10]`) is under `0x100` (a real, fixed
 * 256-group cap), scans up to 256 real `record` slots (16-byte stride,
 * same array `HZMEM_Free`/`Get*` index into) for one with a clear
 * `valid` flag (`record[0]==0`); if found and the table's own real
 * bitmap-length field (`table[0]`) is nonzero, scans a real per-byte
 * bitmap (`table[0xc]`, one byte per allocatable unit) for the first
 * run of `neededSlots` consecutive `0` (free) bytes, marks them `1`
 * (occupied) on success. If no free group slot exists, the group-scan
 * exhausts, or the bitmap scan finds no run, falls back to a real
 * "extend an existing chain" path: re-derives `table`/the bitmap,
 * checks whether the bitmap's own last byte is free, and - if so - how
 * many more free bytes precede it (walking backward, capped at
 * `neededSlots`), extending that existing free run in place rather than
 * starting a fresh search; either way, on success, records the real
 * byte offset (`record[1]`), the real total requested size
 * (`record[3]`, `neededSlots*unitSize`) and the real newly-added-this-
 * call size (`record[2]`, `extendedCount*unitSize` - this is what
 * `HZMEM_GetBlockCount` returns, distinct from `record[3]` which
 * `HZMEM_IsPartial` compares it against), sets `record[0]=1`, and
 * increments the table's own refcount. On any failure, the found index
 * used for the final bit-packing is the real sentinel `0xffffffff`
 * (masked down to 10 bits like every real success value, so a failure
 * is indistinguishable from a genuine index of `0x3ff` at the bit level
 * - transcribed exactly as decompiled, this project's own standing rule
 * against inventing distinctions the real code doesn't make).
 *
 * Confidence: CONFIRMED for the table/record lookup and every
 * `_HZDATA*`-typed offset (disassembly-checked). INFERRED-with-strong-
 * basis for the interior bitmap-scan/chain-extension algorithm (Ghidra
 * C decompile plus a structural, not byte-by-byte-exhaustive,
 * disassembly cross-check). No C++ compiler was available in the
 * sandboxed environment this was written in (same standing limitation
 * as every other file in this project).
 */

#include "../Headers/ATIRadeonX1000Registers.h"
#include "../Headers/ATIRadeonX1000Types.h"

namespace {
inline UInt32 &U32At(void *base, int offset) { return *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(base) + offset); }
} // namespace

UInt32 HZMEM_Alloc(_HZDATA *hizData, UInt32 surfaceHzField, UInt32 blockKind, UInt32 tileDim, UInt32 size) {
    if (hizData == nullptr) {
        return 0xffffffff;
    }
    UInt8 *fieldGroup = reinterpret_cast<UInt8 *>(hizData) + blockKind * 4;
    UInt8 *table = reinterpret_cast<UInt8 *>(U32At(fieldGroup, 0x10));
    if (table == nullptr) {
        return 0xffffffff;
    }
    if (blockKind > 2) {
        return 0xffffffff;
    }

    UInt32 unit1 = U32At(hizData, 4);
    if (tileDim != (tileDim / unit1) * unit1) { /* real: divides by unit1 unconditionally, exactly as disassembled */
        return 0xffffffff;
    }
    UInt32 unit2 = U32At(hizData, 8);
    if (size != (size / unit2) * unit2) {
        return 0xffffffff;
    }

    UInt32 area = (unit1 == 0 || unit2 == 0) ? 0 : (tileDim / unit1) * (size / unit2);

    UInt32 tableUnitSize = U32At(table, 4);
    UInt32 byteCapacityLimit = U32At(table, 8);
    UInt32 remainder = area - (area / tableUnitSize) * tableUnitSize;
    if (remainder != 0) {
        area = tableUnitSize + (area - remainder);
    }
    UInt32 neededSlots = (tableUnitSize == 0) ? 0 : (area / tableUnitSize);

    bool found = false;
    bool attemptFallback = false;
    UInt32 foundGroupIndex = 0;
    UInt32 startPos = 0;
    UInt32 extendedCount = neededSlots;

    if (U32At(table, 0x10) < 0x100) {
        UInt8 *scan = table + 0x14;
        UInt32 groupIndex = 0;
        UInt32 remainingGroups = 0x100;
        UInt32 freeGroupIndex = 0xffffffff;
        do {
            if (U32At(scan, 0) == 0) {
                freeGroupIndex = groupIndex;
                break;
            }
            groupIndex++;
            scan += 16;
            remainingGroups--;
        } while (remainingGroups != 0);

        if (freeGroupIndex != 0xffffffff) {
            foundGroupIndex = freeGroupIndex;
            UInt32 recordCountBound = U32At(table, 0);
            extendedCount = neededSlots;
            if (recordCountBound == 0) {
                attemptFallback = true;
            } else {
                UInt8 *bitmap = reinterpret_cast<UInt8 *>(U32At(table, 0xc));
                UInt32 run = 0;
                SInt32 runStart = -1;
                UInt32 pos = 0;
                bool ranOut = true;
                for (;;) {
                    run++;
                    if (bitmap[pos] == 1) {
                        runStart = static_cast<SInt32>(pos) + 1;
                        run = 0;
                    }
                    if (run == neededSlots) {
                        ranOut = false;
                        break;
                    }
                    pos++;
                    recordCountBound--;
                    if (recordCountBound == 0) {
                        break; /* real: bitmap scan exhausted -> falls through to the chain fallback below */
                    }
                }
                if (!ranOut) {
                    if (neededSlots != 0) {
                        UInt8 *p = bitmap + runStart;
                        for (UInt32 n = neededSlots; n != 0; n--) {
                            *p++ = 1;
                        }
                    }
                    /* real: `if (runStart != -1)` guard here is always true in practice
                       (runStart only ever increases from its -1 init) - this project's
                       own established convention for transcribing dead-in-practice
                       guards exactly as decompiled, without inventing a reachable else. */
                    startPos = tableUnitSize * static_cast<UInt32>(runStart);
                    found = true;
                } else {
                    attemptFallback = true;
                }
            }
        }
        /* else: no free group slot among all 256 -> real hard fail, no fallback attempt */
    }
    /* else: table[0x10] (refcount) >= 0x100 -> real hard fail, no fallback attempt */

    if (attemptFallback) {
        UInt8 *table2 = reinterpret_cast<UInt8 *>(U32At(fieldGroup, 0x10));
        UInt8 *bitmap2 = (table2 != nullptr) ? reinterpret_cast<UInt8 *>(U32At(table2, 0xc)) : nullptr;
        SInt32 bound = (table2 != nullptr) ? static_cast<SInt32>(U32At(table2, 0)) : 0;

        if (table2 == nullptr || bitmap2 == nullptr || bound < 1) {
            startPos = 0;
            found = true; /* real: allocates at position 0 unconditionally in this case */
        } else {
            SInt32 last = bound - 1;
            if (bitmap2[last] != 0) {
                found = false;
            } else {
                SInt32 secondLast = bound - 2;
                if (secondLast < 0 || bitmap2[secondLast] == 1) {
                    extendedCount = 1;
                } else {
                    extendedCount = 2;
                    if (neededSlots > 2) {
                        UInt8 *p = bitmap2 + secondLast;
                        SInt32 left = last;
                        while (extendedCount != neededSlots) {
                            last--;
                            left--;
                            if (left == 0 || p[-1] == 1) {
                                break;
                            }
                            extendedCount++;
                            p--;
                        }
                    }
                }
                if (last != -1 && tableUnitSize * (static_cast<UInt32>(last) + neededSlots) <= byteCapacityLimit) {
                    if (last < bound) {
                        UInt32 fillCount = static_cast<UInt32>(bound - last);
                        UInt8 *p = bitmap2 + last;
                        for (; fillCount != 0; fillCount--) {
                            *p++ = 1;
                        }
                    }
                    startPos = tableUnitSize * static_cast<UInt32>(last);
                    found = true;
                } else {
                    found = false;
                }
            }
        }
    }

    UInt32 resultIndex;
    if (found) {
        U32At(table, 0x14 + foundGroupIndex * 16 + 4)  = startPos;
        U32At(table, 0x14 + foundGroupIndex * 16 + 0xc) = neededSlots * tableUnitSize;
        U32At(table, 0x14 + foundGroupIndex * 16 + 8)  = tableUnitSize * extendedCount;
        U32At(table, 0x14 + foundGroupIndex * 16 + 0)  = 1;
        U32At(reinterpret_cast<UInt8 *>(U32At(fieldGroup, 0x10)), 0x10) += 1;
        resultIndex = foundGroupIndex;
    } else {
        resultIndex = 0xffffffff;
    }

    if (blockKind == 1) {
        return (surfaceHzField & 0x3ff) | ((resultIndex & 0x3ff) << 10) | (surfaceHzField & 0x3ff00000);
    }
    if (blockKind != 0) {
        if (blockKind != 2) {
            return 0xffffffff;
        }
        return (surfaceHzField & 0xfffff) | ((resultIndex & 0x3ff) << 20);
    }
    return (resultIndex & 0x3ff) | (surfaceHzField & 0xffc00) | (surfaceHzField & 0x3ff00000);
}
