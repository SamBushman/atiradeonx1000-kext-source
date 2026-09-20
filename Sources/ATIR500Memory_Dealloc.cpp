/* NOTE 2026-09-19: 1 function body formerly in this file has been replaced by mechanical ports from the shipped kext's decompile (Sources/*_Port.cpp; marked
   "(re-ported mechanically: ...)" below). The analysis prose in this file describes the earlier hand-written bodies and is kept as history; see README.md,
   "How the code was produced". */
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

/* (re-ported mechanically: see ATIR500Memory_dealloc_Port.cpp) */

