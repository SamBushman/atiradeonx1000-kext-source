/*
 * ATIR500Memory_Pool.cpp
 *
 * RESOLVED (issue #25): `ATIR500Memory::init_pool` (both real overloads,
 * addrs `0x18e00`/`0x18f60`), `add_to_stack` (real addr `0x191b0`), and
 * `total_free` (real addr `0x19910`).
 *
 * All three chunk-carving functions (`init_pool` x2, `add_to_stack`)
 * gate on this class's own real vtable slot `+0x48` where applicable
 * (see `ATIR500Memory_Lifecycle.cpp`'s own header comment for that
 * slot's role) and allocate raw `0x204`-byte chunks via a real opaque
 * kernel allocator wrapper - THREE distinct real call addresses
 * (`FUN_00018f44`/`FUN_00019108`/`FUN_00019260`), not the same function
 * reused, matching this project's own issue #15 category of opaque
 * allocator wrappers.
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

extern "C" void *FUN_00018f44(UInt32 size, UInt32 align); /* real opaque kernel allocator, init_pool(1-param)'s own */
extern "C" void *FUN_00019108(UInt32 size, UInt32 align); /* real opaque kernel allocator, init_pool(3-param)'s own (distinct real address) */
extern "C" void *FUN_00019260(UInt32 size, UInt32 align); /* real opaque kernel allocator, add_to_stack's own (distinct real address) */

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

bool ATIR500Memory::init_pool(UInt32 poolSize) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

    typedef bool (*Fn0x48)(void *);
    void **vtable = *reinterpret_cast<void ***>(self);
    if (!reinterpret_cast<Fn0x48>(vtable[0x48 / 4])(this)) {
        return false;
    }

    UInt8 *chunk = *reinterpret_cast<UInt8 **>(self + 0x10);
    *reinterpret_cast<UInt32 *>(self + 0xc) = 0;
    *reinterpret_cast<UInt32 *>(self + 8) = 0;

    if (chunk == 0) {
        chunk = reinterpret_cast<UInt8 *>(FUN_00018f44(0x204, 0x20));
        *reinterpret_cast<UInt8 **>(self + 0x10) = chunk;
        if (chunk != 0) {
            U32At(chunk, 0) = 0;
        }
        chunk = *reinterpret_cast<UInt8 **>(self + 0x10);
        if (chunk == 0) {
            return false;
        }
    }

    /*
     * Real bootstrap: sentinel node at chunk+4 (fields at +4/+8/+0xc/
     * +0x10 relative to the CHUNK, i.e. next/prev/offset/freeFlag at
     * chunk+4/8/0xc/0x10), first real region node at chunk+0x14
     * (fields at +0x14/0x18/0x1c/0x20), end-boundary node at chunk+0x24
     * (fields at +0x24/0x28/0x2c/0x30) - see the literal writes below;
     * transcribed exactly as decompiled rather than re-derived, since
     * this project's own re-check of the exact node/field correspondence
     * here was inconclusive - see this file's own header comment).
     */
    UInt8 *spareHead = chunk + 0x44;
    *reinterpret_cast<UInt8 **>(self + 8) = chunk + 4;
    U32At(chunk, 0xc) = 0;
    U32At(chunk, 8) = 0;
    U32At(chunk, 0x1c) = 0;
    U32At(chunk, 0x18) = reinterpret_cast<UInt32>(chunk + 4);
    U32At(chunk, 0x2c) = 0;
    U32At(chunk, 0x28) = reinterpret_cast<UInt32>(chunk + 0x14);
    U32At(chunk, 0x3c) = poolSize;
    U32At(chunk, 0x38) = reinterpret_cast<UInt32>(chunk + 0x24);
    U32At(chunk, 4) = reinterpret_cast<UInt32>(chunk + 0x14);
    U32At(chunk, 0x14) = reinterpret_cast<UInt32>(chunk + 0x24);
    U32At(chunk, 0x24) = reinterpret_cast<UInt32>(chunk + 0x34);
    U32At(chunk, 0x34) = 0;
    U32At(chunk, 0x10) = 0x80000000;
    U32At(chunk, 0x20) = 0;
    U32At(chunk, 0x30) = 0x80000000;
    U32At(chunk, 0x40) = 0;
    *reinterpret_cast<UInt8 **>(self + 0xc) = spareHead;
    U32At(chunk, 0x48) = 0;
    U32At(chunk, 0x4c) = 0;
    U32At(chunk, 0x50) = 0;

    if (chunk + 500 != spareHead) {
        UInt8 *p = chunk + 0x5c;
        int count = 0x1b;
        do {
            U32At(p, 0) = 0;
            U32At(p, 4) = 0;
            U32At(p, -4) = 0;
            U32At(spareHead, 0) = reinterpret_cast<UInt32>(spareHead + 0x10);
            p += 0x10;
            count--;
            spareHead += 0x10;
        } while (count != 0);
    }

    U32At(chunk, 500) = 0;
    return true;
}

bool ATIR500Memory::init_pool(UInt32 regionOffset, UInt32 regionSize, UInt32 poolSize) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

    typedef bool (*Fn0x48)(void *);
    void **vtable = *reinterpret_cast<void ***>(self);
    if (!reinterpret_cast<Fn0x48>(vtable[0x48 / 4])(this)) {
        return false;
    }

    UInt8 *chunk = *reinterpret_cast<UInt8 **>(self + 0x10);
    *reinterpret_cast<UInt32 *>(self + 0xc) = 0;
    *reinterpret_cast<UInt32 *>(self + 8) = 0;

    if (chunk == 0) {
        chunk = reinterpret_cast<UInt8 *>(FUN_00019108(0x204, 0x20));
        *reinterpret_cast<UInt8 **>(self + 0x10) = chunk;
        if (chunk != 0) {
            U32At(chunk, 0) = 0;
        }
        chunk = *reinterpret_cast<UInt8 **>(self + 0x10);
        if (chunk == 0) {
            return false;
        }
    }

    UInt32 *node = reinterpret_cast<UInt32 *>(chunk + 0x24);
    *reinterpret_cast<UInt8 **>(self + 8) = chunk + 4;
    UInt32 *chunkEnd = reinterpret_cast<UInt32 *>(chunk + 500);
    U32At(chunk, 0xc) = 0;
    U32At(chunk, 8) = 0;
    U32At(chunk, 0x10) = 0x80000000;
    U32At(chunk, 0x18) = reinterpret_cast<UInt32>(chunk + 4);
    U32At(chunk, 4) = reinterpret_cast<UInt32>(chunk + 0x14);
    U32At(chunk, 0x1c) = 0;
    U32At(chunk, 0x20) = 0;
    *reinterpret_cast<UInt32 **>(chunk + 0x14) = node;

    if (regionSize != 0) {
        node = reinterpret_cast<UInt32 *>(chunk + 0x34);
        U32At(chunk, 0x28) = reinterpret_cast<UInt32>(chunk + 0x14);
        U32At(chunk, 0x2c) = 0;
        U32At(chunk, 0x30) = 0x80000000;
        *reinterpret_cast<UInt32 **>(chunk + 0x24) = node;
    }

    /*
     * From here, `node` (raw decompile: `piVar7`) is walked as a real
     * WORD-indexed array exactly as Ghidra's own decompile expressed it
     * - real indices up to word 15 (`node[0xf]`), i.e. a real record
     * LARGER than the plain 4-word BoundaryNode this class's runtime
     * methods (alloc/dealloc/reserve/total_free) use. Real meaning of
     * words 4-9/0xd-0xf beyond the first four (matching the runtime's
     * own next/prev/offset/freeFlag model) is UNKNOWN/INFERRED - word 10
     * visibly stores `poolSize` verbatim, suggesting real one-time
     * bootstrap scaffolding for a real consumer this pass never located
     * (no other already-transcribed method in this class reads these
     * extra words again). Left as literal raw index arithmetic rather
     * than force a guessed name onto each one.
     */
    UInt32 *spareHead = node + 0xc;
    node[2] = regionOffset;
    node[1] = reinterpret_cast<UInt32>(node - 4);
    node[3] = 0;
    node[8] = 0;
    node[5] = reinterpret_cast<UInt32>(node);
    node[0] = reinterpret_cast<UInt32>(node + 4);
    node[9] = reinterpret_cast<UInt32>(node + 4);
    node[4] = reinterpret_cast<UInt32>(node + 8);
    node[6] = regionOffset + regionSize;
    node[7] = 0x80000000;
    node[10] = poolSize;
    node[0xb] = 0;
    *reinterpret_cast<UInt32 **>(self + 0xc) = spareHead;
    node[0xd] = 0;
    node[0xe] = 0;
    node[0xf] = 0;

    if (chunkEnd != spareHead) {
        UInt32 *p = node + 0x12;
        do {
            UInt32 *next = spareHead + 4;
            *p = 0;
            p[1] = 0;
            p[-1] = 0;
            *spareHead = reinterpret_cast<UInt32>(next);
            p += 4;
            spareHead = next;
        } while (chunkEnd != next);
    }

    *chunkEnd = 0;
    return true;
}

bool ATIR500Memory::add_to_stack() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

    UInt32 *chunk = reinterpret_cast<UInt32 *>(FUN_00019260(0x204, 0x20));
    if (chunk == 0) {
        return false;
    }

    UInt32 *node = chunk + 1;
    chunk[0] = *reinterpret_cast<UInt32 *>(self + 0x10);
    *reinterpret_cast<UInt32 **>(self + 0xc) = node;
    *reinterpret_cast<UInt32 **>(self + 0x10) = chunk;
    node[1] = 0;
    node[2] = 0;
    node[3] = 0;

    if (node != chunk + 0x7d) {
        UInt32 *p = chunk + 7;
        int count = 0x1f;
        do {
            *p = 0;
            p[1] = 0;
            p[-1] = 0;
            *node = reinterpret_cast<UInt32>(node + 4);
            p += 4;
            count--;
            node += 4;
        } while (count != 0);
    }

    chunk[0x7d] = 0;
    return true;
}

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
