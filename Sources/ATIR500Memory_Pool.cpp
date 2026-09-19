/*
 * ATIR500Memory_Pool.cpp
 *
 * RESOLVED (issue #25): `ATIR500Memory::init_pool` (both real overloads,
 * addrs `0x18e00`/`0x18f60`), `add_to_stack` (real addr `0x191b0`), and
 * `total_free` (real addr `0x19910`).
 *
 * Both `init_pool` overloads first call this object's own virtual `init()`
 * (slot +0x48 of its vtable; see `ATIR500Memory_Lifecycle.cpp`) and allocate raw `0x204`-byte chunks via a real kernel
 * allocator wrapper - THREE distinct per-call-site stub addresses
 * (`FUN_00018f44`/`FUN_00019108`/`FUN_00019260`), all RESOLVED, issue
 * #27, to the same real target, `IOMallocAligned`.
 *
 * The two `init_pool` overloads carve their first chunk into this
 * class's real sentinel/first-region `BoundaryNode` bootstrap (see
 * `Headers/ATIR500Memory.h`'s own field-layout comment) plus a run of
 * additional spare `BoundaryNode` records threaded onto
 * `spareNodeStack`. Transcribed here as LITERAL raw index/offset
 * arithmetic rather than forced into fully-named struct field writes -
 * the exact real bootstrap topology (how the sentinel, first region
 * node(s), and the larger real record the 3-param overload's own
 * region-node builds - real indices up to word 15/`+0x3c` - relate to
 * the plain 4-word `BoundaryNode` the runtime methods use) was NOT
 * fully resolved this pass; see inline comments at each point of real
 * uncertainty. `add_to_stack`'s own carving loop (a uniform run of
 * plain spare records, no special first-node bootstrap) is fully
 * resolved with the same confidence as the runtime methods.
 *
 * `total_free` reuses the exact same real "reach the first search node"
 * expression (`self+8` field, two more real levels of indirection) that
 * `alloc`/`dealloc`/`reserve` all independently use - see
 * `ATIR500Memory_Alloc.cpp`'s own copy of the `FirstSearchNode` helper
 * for the full account of what those three real dereferences mean.
 *
 * Confidence: CONFIRMED for control flow and every literal constant in
 * all four functions - real, complete, standalone decompiles. Field
 * MEANING beyond the plain `next`/`prev`/`offset`/`freeFlag` model is
 * INFERRED/UNKNOWN exactly where flagged inline, per this project's own
 * confidence tiers (see `README.md`).
 */

#include "../Headers/ATIR500Memory.h"

extern "C" void *FUN_00018f44(UInt32 size, UInt32 align) asm("_IOMallocAligned"); /* init_pool(1-param)'s own stub instance */
extern "C" void *FUN_00019108(UInt32 size, UInt32 align) asm("_IOMallocAligned"); /* init_pool(3-param)'s own stub instance */
extern "C" void *FUN_00019260(UInt32 size, UInt32 align) asm("_IOMallocAligned"); /* add_to_stack's own stub instance */

namespace {
inline UInt32 &U32At(void *base, int offset) { return *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(base) + offset); }

/*
 * Real, consistently-used expression every search-based method in this
 * class shares (`alloc` x2, `reserve`, `total_free`): reads the real
 * `self+8` field (sentinel node address), then follows the sentinel's
 * own real `next` field to reach the first real node the search should
 * examine. See `ATIR500Memory_Alloc.cpp` for the full derivation.
 */
inline UInt32 *FirstSearchNode(UInt8 *self) {
    UInt32 *sentinel = *reinterpret_cast<UInt32 **>(self + 8);
    return *reinterpret_cast<UInt32 **>(sentinel);
}
} // namespace

/* (re-ported mechanically: see ATIR500Memory_init_pool_Port.cpp) */


/* (re-ported mechanically: see ATIR500Memory_init_pool_Port.cpp) */


/* (re-ported mechanically: see ATIR500Memory_add_to_stack_Port.cpp) */


int ATIR500Memory::total_free() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt32 *cur = FirstSearchNode(self);
    int total = 0;

    for (;;) {
        UInt32 *node = cur;
        UInt32 *next = reinterpret_cast<UInt32 *>(cur[0]);
        if (next == 0) {
            break;
        }
        if (static_cast<SInt32>(node[3]) < 0) {
            total += static_cast<SInt32>(next[2] - node[2]);
        }
        cur = next;
    }
    return total;
}
