/* NOTE 2026-09-19: 3 function bodies formerly in this file have been replaced by mechanical ports from the shipped kext's decompile (Sources/*_Port.cpp; marked
   "(re-ported mechanically: ...)" below). The analysis prose in this file describes the earlier hand-written bodies and is kept as history; see README.md,
   "How the code was produced". */
/*
 * ATIR500Memory_Alloc.cpp
 *
 * RESOLVED (issue #25): `ATIR500Memory::alloc`'s real 3-parameter
 * overload (real addr `0x19430`, NOT decompiled by the earlier issue
 * #23 pass that found this class) and `reserve` (real addr `0x19270`,
 * also new this pass). The 5-parameter `alloc` overload was already
 * decompiled by issue #23's own pass (real addr `0x195f0`) but never
 * actually committed to source - transcribed here for the first time.
 *
 * All three share the exact same real "reach the first search node"
 * expression: read the real `self+8` field (a pointer to this pool's
 * own real sentinel `BoundaryNode`, see `Headers/ATIR500Memory.h`), then
 * follow the sentinel's own real `next` field to reach the first real
 * node the search should examine (`FirstSearchNode`, below) - three real
 * levels of pointer indirection in the raw decompile
 * (`*(T**)**(undefined4**)(this+8)`), all three CONFIRMED consistent
 * across every one of this class's own search-based methods, including
 * `total_free` (`ATIR500Memory_Pool.cpp`).
 *
 * All three implement the same real free-list search/split logic: walk
 * the address-ordered `BoundaryNode` list for the first real FREE
 * region (`freeFlag < 0`) that can hold the request, then either reuse
 * an existing node (exact-size match, collapses the boundary and
 * returns it to `spareNodeStack`) or pop a spare node from
 * `spareNodeStack` to represent the leftover free remainder - failing
 * outright (after first trying `add_to_stack` once) if `spareNodeStack`
 * is empty and a split is needed. `reserve` differs only in NOT
 * searching for a fitting size/alignment - it walks for the specific
 * free region that already CONTAINS the caller's given
 * `[offset, offset+size)` range.
 *
 * Confidence: CONFIRMED for control flow and every field offset/literal
 * constant in all three functions - real, complete, standalone
 * decompiles, cross-checked against each other (all three share
 * near-identical split/merge logic, which agrees byte-for-byte across
 * the two `alloc` overloads).
 */

#include "../Headers/ATIR500Memory.h"

namespace {
/*
 * Real, consistently-used expression every search-based method in this
 * class shares: reads the real `self+8` field (sentinel node address),
 * then follows the sentinel's own real `next` field to reach the first
 * real node the search should examine.
 */
inline UInt32 *FirstSearchNode(UInt8 *self) {
    UInt32 *sentinel = *reinterpret_cast<UInt32 **>(self + 8);
    return *reinterpret_cast<UInt32 **>(sentinel);
}
} // namespace

/* (re-ported mechanically: see ATIR500Memory_alloc_Port.cpp) */


/* (re-ported mechanically: see ATIR500Memory_alloc_Port.cpp) */


/* (re-ported mechanically: see ATIR500Memory_reserve_Port.cpp) */

