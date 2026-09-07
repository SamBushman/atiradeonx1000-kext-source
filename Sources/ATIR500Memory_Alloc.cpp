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

UInt32 ATIR500Memory::alloc(GLKMemoryElement *elem, UInt32 size, UInt32 alignment) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *e = reinterpret_cast<UInt8 *>(elem);

    UInt32 alignMask = (alignment != 0) ? (alignment - 1) : 0;

    if ((*reinterpret_cast<UInt32 *>(self + 0xc) == 0 && !add_to_stack()) ||
        FirstSearchNode(self) == 0) {
        return 0;
    }

    UInt32 *cur = FirstSearchNode(self);
    UInt32 *node;
    UInt32 alignedStart;
    UInt32 end;
    for (;;) {
        node = cur;
        while (static_cast<SInt32>(node[3]) >= 0) {
            cur = reinterpret_cast<UInt32 *>(node[0]);
            if (cur == 0) {
                return 0;
            }
            node = cur;
        }
        cur = reinterpret_cast<UInt32 *>(node[0]);
        alignedStart = (alignMask + node[2]) & ~alignMask;
        end = size + alignedStart;
        if (end <= cur[2]) {
            break;
        }
    }

    *reinterpret_cast<UInt32 *>(e + 8) = alignedStart;
    *reinterpret_cast<UInt32 *>(e + 0xc) = alignMask & 0xffff;
    UInt32 *nodePrev = reinterpret_cast<UInt32 *>(node[1]);

    if (node[2] == alignedStart) {
        if (end == cur[2]) {
            /* Exact match on both ends: the whole free node is consumed - unlink it and
             * return it to spareNodeStack. */
            *reinterpret_cast<UInt32 **>(e) = cur;
            *reinterpret_cast<UInt32 **>(e + 4) = nodePrev;
            *nodePrev = reinterpret_cast<UInt32>(elem);
            cur[1] = reinterpret_cast<UInt32>(elem);
            UInt32 spareOld = *reinterpret_cast<UInt32 *>(self + 0xc);
            node[3] = 0;
            node[1] = 0;
            node[2] = 0;
            node[0] = spareOld;
            *reinterpret_cast<UInt32 **>(self + 0xc) = node;
        } else {
            /* Allocation exactly fills the START of the free region: shrink the node in
             * place to describe the (smaller) remaining free tail. */
            *reinterpret_cast<UInt32 **>(e) = node;
            *reinterpret_cast<UInt32 **>(e + 4) = nodePrev;
            node[2] = end;
            *nodePrev = reinterpret_cast<UInt32>(elem);
            node[1] = reinterpret_cast<UInt32>(elem);
        }
    } else if (cur[2] == end) {
        /* Allocation exactly fills the END of the free region: the free region's own
         * start node stays free (now shorter); insert `elem` as the new boundary at the
         * allocation's own end, coinciding with the existing next node. */
        *reinterpret_cast<UInt32 **>(e) = cur;
        *reinterpret_cast<UInt32 **>(e + 4) = node;
        *node = reinterpret_cast<UInt32>(elem);
        cur[1] = reinterpret_cast<UInt32>(elem);
    } else {
        /* Allocation falls strictly inside the free region: pop a spare node to
         * represent the leftover free tail after the allocation. */
        UInt32 *spare = *reinterpret_cast<UInt32 **>(self + 0xc);
        *reinterpret_cast<UInt32 *>(self + 0xc) = spare[0];
        spare[0] = reinterpret_cast<UInt32>(cur);
        cur[1] = reinterpret_cast<UInt32>(spare);
        *reinterpret_cast<UInt32 **>(e) = spare;
        spare[1] = reinterpret_cast<UInt32>(elem);
        spare[3] = 0x80000000;
        spare[2] = end;
        *node = reinterpret_cast<UInt32>(elem);
        *reinterpret_cast<UInt32 **>(e + 4) = node;
    }
    return 1;
}

UInt32 ATIR500Memory::alloc(GLKMemoryElement *elem, UInt32 size, UInt32 alignment, UInt32 rangeStart, UInt32 rangeSize) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *e = reinterpret_cast<UInt8 *>(elem);

    if (*reinterpret_cast<UInt32 *>(self + 0xc) == 0 && !add_to_stack()) {
        return 0;
    }

    UInt32 alignMask = (alignment != 0) ? (alignment - 1) : 0;
    UInt32 *cur = FirstSearchNode(self);

    /*
     * NOTE on loop shape: the raw decompile nests two `while` loops whose
     * combined condition does "advance one node, stop if it isn't free"
     * (the inner loop) inside an outer `cur != 0` guard. Collapsing both
     * into a single `while (cur != 0)` here is behaviorally identical -
     * every path (allocated node, free-but-too-small node) falls through
     * to re-check `cur != 0` either way - and, unlike a naive direct
     * transliteration of the inner loop alone, it can never dereference
     * a null `node` once the list's own real terminal boundary node
     * (always non-free by construction) is reached.
     */
    while (cur != 0) {
        UInt32 *node = cur;
        cur = reinterpret_cast<UInt32 *>(node[0]);
        if (static_cast<SInt32>(node[3]) >= 0) {
            continue;
        }

        UInt32 candidateStart = (rangeStart <= node[2]) ? ((alignMask + node[2]) & ~alignMask) : rangeStart;
        UInt32 end = size + candidateStart;
        if (end > cur[2]) {
            continue;
        }

        if (rangeStart + rangeSize < end) {
            return 0;
        }

        *reinterpret_cast<UInt32 *>(e + 8) = candidateStart;
        UInt32 *nodePrev = reinterpret_cast<UInt32 *>(node[1]);
        *reinterpret_cast<UInt32 *>(e + 0xc) = alignMask & 0xffff;

        if (candidateStart == node[2]) {
            if (end != cur[2]) {
                *reinterpret_cast<UInt32 **>(e) = node;
                *reinterpret_cast<UInt32 **>(e + 4) = nodePrev;
                node[2] = end;
                *nodePrev = reinterpret_cast<UInt32>(elem);
                node[1] = reinterpret_cast<UInt32>(elem);
                return 1;
            }
            *reinterpret_cast<UInt32 **>(e) = cur;
            *reinterpret_cast<UInt32 **>(e + 4) = nodePrev;
            *nodePrev = reinterpret_cast<UInt32>(elem);
            cur[1] = reinterpret_cast<UInt32>(elem);
            UInt32 spareOld = *reinterpret_cast<UInt32 *>(self + 0xc);
            node[3] = 0;
            node[1] = 0;
            node[2] = 0;
            node[0] = spareOld;
            *reinterpret_cast<UInt32 **>(self + 0xc) = node;
            return 1;
        }
        if (cur[2] == end) {
            *reinterpret_cast<UInt32 **>(e) = cur;
            *reinterpret_cast<UInt32 **>(e + 4) = node;
            *node = reinterpret_cast<UInt32>(elem);
            cur[1] = reinterpret_cast<UInt32>(elem);
            return 1;
        }
        UInt32 *spare = *reinterpret_cast<UInt32 **>(self + 0xc);
        *reinterpret_cast<UInt32 *>(self + 0xc) = spare[0];
        *spare = reinterpret_cast<UInt32>(cur);
        cur[1] = reinterpret_cast<UInt32>(spare);
        *reinterpret_cast<UInt32 **>(e) = spare;
        spare[1] = reinterpret_cast<UInt32>(elem);
        spare[3] = 0x80000000;
        spare[2] = end;
        *node = reinterpret_cast<UInt32>(elem); /* real: *puVar8 = param_1 (node's own next slot) */
        *reinterpret_cast<UInt32 **>(e + 4) = node;
        return 1;
    }
    return 0;
}

UInt32 ATIR500Memory::reserve(GLKMemoryElement *elem, UInt32 offset, UInt32 size) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *e = reinterpret_cast<UInt8 *>(elem);

    if (*reinterpret_cast<UInt32 *>(self + 0xc) == 0 && !add_to_stack()) {
        return 0;
    }

    UInt32 end = offset + size;
    UInt32 *cur = FirstSearchNode(self);

    while (cur != 0) {
        UInt32 *node = cur;
        cur = reinterpret_cast<UInt32 *>(node[0]);
        if (static_cast<SInt32>(node[3]) >= 0) {
            continue;
        }
        if (offset < node[2]) {
            continue;
        }
        if (end > cur[2]) {
            continue;
        }

        *reinterpret_cast<UInt32 *>(e + 8) = offset;
        UInt32 *nodePrev = reinterpret_cast<UInt32 *>(node[1]);
        *reinterpret_cast<UInt32 *>(e + 0xc) = 0;

        if (offset != node[2]) {
            if (cur[2] == end) {
                *reinterpret_cast<UInt32 **>(e) = cur;
                *reinterpret_cast<UInt32 **>(e + 4) = node;
                *node = reinterpret_cast<UInt32>(elem);
                cur[1] = reinterpret_cast<UInt32>(elem);
                return 1;
            }
            UInt32 *spare = *reinterpret_cast<UInt32 **>(self + 0xc);
            *reinterpret_cast<UInt32 *>(self + 0xc) = spare[0];
            *spare = reinterpret_cast<UInt32>(cur);
            cur[1] = reinterpret_cast<UInt32>(spare);
            *reinterpret_cast<UInt32 **>(e) = spare;
            spare[1] = reinterpret_cast<UInt32>(elem);
            spare[3] = 0x80000000;
            spare[2] = end;
            *node = reinterpret_cast<UInt32>(elem); /* real: *piVar5 = param_1 */
            *reinterpret_cast<UInt32 **>(e + 4) = node;
            return 1;
        }
        if (end == cur[2]) {
            *reinterpret_cast<UInt32 **>(e) = cur;
            *reinterpret_cast<UInt32 **>(e + 4) = nodePrev;
            *nodePrev = reinterpret_cast<UInt32>(elem);
            cur[1] = reinterpret_cast<UInt32>(elem);
            UInt32 spareOld = *reinterpret_cast<UInt32 *>(self + 0xc);
            node[3] = 0;
            node[1] = 0;
            node[2] = 0;
            node[0] = spareOld;
            *reinterpret_cast<UInt32 **>(self + 0xc) = node;
            return 1;
        }
        *reinterpret_cast<UInt32 **>(e) = node;
        *reinterpret_cast<UInt32 **>(e + 4) = nodePrev;
        node[2] = end;
        *nodePrev = reinterpret_cast<UInt32>(elem);
        node[1] = reinterpret_cast<UInt32>(elem);
        return 1;
    }
    return 0;
}
