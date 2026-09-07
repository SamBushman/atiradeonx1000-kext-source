/*
 * ATIR500Memory_Dealloc.cpp
 *
 * RESOLVED (issue #25): `ATIR500Memory::dealloc`'s real body, real addr
 * `0x197d0`. Decompiled by issue #23's own pass but never actually
 * committed to source until now.
 *
 * Real, previously-undocumented finding: `GLKMemoryElement` itself
 * doubles as a real `BoundaryNode`-shaped record while a block is
 * allocated - `alloc`/`reserve` (`ATIR500Memory_Alloc.cpp`) write real
 * neighbor `BoundaryNode` pointers into `elem+0x0`/`elem+0x4` (matching
 * a node's own `next`/`prev` fields at the exact same offsets), and this
 * function reads them back to splice the freed block's own neighbors
 * back together. This is why `elem+0xC` (the alignment-mask field) is
 * always safe to double as an implicit "not free" flag at alloc time -
 * every real alignment mask value (`(alignment-1) & 0xffff`) is small
 * enough to never set the real `0x80000000` free-flag bit a genuine
 * `BoundaryNode`'s own flag word uses.
 *
 * Real merge logic: reads back the freed block's own offset
 * (`elem+0x8`) and its two real neighbor nodes (`elem+0x4`=prev,
 * `elem+0x0`=next), clears all four of `elem`'s own bookkeeping words,
 * then handles four real cases depending on which neighbor(s) are
 * already free: both free (merge all three regions into the prev node,
 * return the next node to `spareNodeStack`), only prev free (extend it
 * rightward by simply relinking past the freed gap), only next free
 * (extend it leftward by moving its own `offset` back to the freed
 * block's start), or neither free (pop a spare node from
 * `spareNodeStack` to represent the newly-freed region on its own).
 *
 * Confidence: CONFIRMED for control flow and every field offset - a
 * real, complete, standalone decompile, cross-checked against `alloc`'s
 * own inverse operations (`ATIR500Memory_Alloc.cpp`) - the neither-free
 * case here is the exact mirror of `alloc`'s own middle-split case, and
 * matches it field-for-field.
 */

#include "../Headers/ATIR500Memory.h"

UInt32 ATIR500Memory::dealloc(GLKMemoryElement *elem) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *e = reinterpret_cast<UInt8 *>(elem);

    UInt32 offset = *reinterpret_cast<UInt32 *>(e + 8);

    if (*reinterpret_cast<UInt32 *>(self + 0xc) == 0 && !add_to_stack()) {
        return 0;
    }

    UInt32 *prevNode = *reinterpret_cast<UInt32 **>(e + 4);
    UInt32 *nextNode = *reinterpret_cast<UInt32 **>(e);

    *reinterpret_cast<UInt32 *>(e + 0xc) = 0;
    *reinterpret_cast<UInt32 *>(e + 4) = 0;
    *reinterpret_cast<UInt32 *>(e) = 0;
    *reinterpret_cast<UInt32 *>(e + 8) = 0;

    if ((static_cast<SInt32>(prevNode[3]) & static_cast<SInt32>(nextNode[3])) < 0) {
        /* Both neighbors free: merge all three regions into `prevNode`, return `nextNode`
         * to spareNodeStack. */
        UInt32 *nextNext = reinterpret_cast<UInt32 *>(nextNode[0]);
        prevNode[0] = reinterpret_cast<UInt32>(nextNext);
        nextNext[1] = reinterpret_cast<UInt32>(prevNode);
        UInt32 spareOld = *reinterpret_cast<UInt32 *>(self + 0xc);
        nextNode[3] = 0;
        nextNode[1] = 0;
        nextNode[2] = 0;
        nextNode[0] = spareOld;
        *reinterpret_cast<UInt32 **>(self + 0xc) = nextNode;
    } else if (static_cast<SInt32>(prevNode[3]) < 0) {
        /* Only prevNode free: extend it rightward by relinking past the freed gap. */
        nextNode[1] = reinterpret_cast<UInt32>(prevNode);
        *prevNode = reinterpret_cast<UInt32>(nextNode);
    } else if (static_cast<SInt32>(nextNode[3]) < 0) {
        /* Only nextNode free: extend it leftward to the freed block's own start offset. */
        nextNode[2] = offset;
        nextNode[1] = reinterpret_cast<UInt32>(prevNode);
        *prevNode = reinterpret_cast<UInt32>(nextNode);
    } else {
        /* Neither neighbor free: pop a spare node to represent the newly-freed region. */
        UInt32 *spare = *reinterpret_cast<UInt32 **>(self + 0xc);
        *reinterpret_cast<UInt32 *>(self + 0xc) = spare[0];
        *prevNode = reinterpret_cast<UInt32>(spare);
        nextNode[1] = reinterpret_cast<UInt32>(spare);
        spare[3] = 0x80000000;
        spare[2] = offset;
        spare[0] = reinterpret_cast<UInt32>(nextNode);
        spare[1] = reinterpret_cast<UInt32>(prevNode);
    }
    return 1;
}
