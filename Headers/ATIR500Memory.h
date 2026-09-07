/*
 * ATIR500Memory.h
 *
 * RESOLVED (issue #25): every real method this class exposes is now
 * decompiled and transcribed - see the `Sources/ATIR500Memory_*.cpp`
 * files this header declares. Originally found (issue #23) only as
 * `ATIRadeonX1000::tmpAllocVRAM`/`tmpDeallocVRAM`'s own real delegate
 * object (`accelerator+0x93c`), and independently as
 * `IOATIR500Surface::dealloc_surface`/`ATIR500Surface::alloc_surface_buffer`/
 * `ATIRadeonX1000::allocate_texture`/`deallocate_texture`'s own real
 * delegate (a SEPARATE instance, `accelerator+0x7c`) - a real,
 * substantial free-list VRAM/GART memory-pool allocator. Real own
 * vtable exists (`__ZTV13ATIR500Memory`, `0x49078`).
 *
 * REAL FIELD LAYOUT (CONFIRMED from every real method's own body):
 *
 *   this+0x08  UInt32 *poolHeadSlot;
 *       A pointer INTO the pool's own backing chunk memory, set once by
 *       `init`/`init_pool` to `chunkBase+4`. That slot in turn holds the
 *       real address of the pool's sentinel/first real boundary node -
 *       every real search (`alloc`/`dealloc`/`reserve`/`total_free`)
 *       reaches the real node list via TWO real levels of indirection:
 *       `*poolHeadSlot` gives the sentinel node's address, and the
 *       sentinel's own real `next` field (word 0) gives the first real
 *       node representing actual pool memory.
 *
 *   this+0x0C  BoundaryNode *spareNodeStack;
 *       A real singly-linked (via word 0) LIFO stack of unused, ready-
 *       to-use `BoundaryNode` records, threaded through the SAME 0x10-
 *       byte record layout described below. Popped whenever `alloc`
 *       needs to insert a new boundary node to represent a leftover
 *       free remainder after carving out an allocation; pushed back
 *       whenever a boundary node's own region collapses to nothing
 *       (an exact-size allocation/dealloc that consumes a whole node).
 *       Refilled via `add_to_stack` when empty.
 *
 *   this+0x10  ChunkHeader *chunkList;
 *       Head of a real singly-linked list (via word 0) of raw 0x204-
 *       byte memory chunks backing this pool - both the pool's own
 *       bootstrap chunk (from `init_pool`) and every later refill chunk
 *       (from `add_to_stack`) thread onto this list, walked and freed
 *       by `free()`.
 *
 * REAL BoundaryNode LAYOUT (CONFIRMED, 0x10/16 bytes, a real address-
 * ordered doubly-linked list implementing classic boundary-tag free-
 * list bookkeeping - each node marks the START of a region; the region
 * spans from this node's own `offset` to the NEXT node's `offset`):
 *
 *   +0x0  BoundaryNode *next;   // next node in address order (also the
 *                               // spare-stack's own thread field when
 *                               // the record is sitting on spareNodeStack)
 *   +0x4  BoundaryNode *prev;   // previous node in address order
 *   +0x8  UInt32 offset;        // real byte offset within the pool that
 *                               // this node marks the start of
 *   +0xC  SInt32  freeFlag;      // negative (top bit set, real constant
 *                               // 0x80000000) - the region starting at
 *                               // this node is FREE; zero - allocated/
 *                               // plain boundary
 *
 * Every real caller-owned `GLKMemoryElement` (still an opaque forward-
 * declared type - never itself decompiled, only ever touched via real
 * output/bookkeeping fields at its own start) receives, on a successful
 * `alloc`/`reserve`:
 *
 *   elem+0x0   BoundaryNode *node;      // real back-pointer bookkeeping
 *   elem+0x4   BoundaryNode *nodePrev;  // the allocator itself writes/
 *                                       // reads these two on dealloc -
 *                                       // NOT caller-owned data
 *   elem+0x8   UInt32 offset;           // real allocated byte offset
 *   elem+0xC   UInt32 alignMask;        // real (alignment-1) & 0xffff, or
 *                                       // 0 for `reserve` (no alignment
 *                                       // search)
 *
 * and `dealloc` reads back `elem+0x8` as the block's own real offset to
 * free.
 */

#ifndef ATIR500MEMORY_H
#define ATIR500MEMORY_H

#include "ATIRadeonX1000Types.h"

struct GLKMemoryElement;

class ATIR500Memory {
public:
    /*
     * Two real constructor bodies exist (real addrs `0x18c00`/`0x18ce0`),
     * nearly identical - each calls a real, distinct pair of unidentified
     * external-looking helpers (`FUN_00018c60`/`FUN_00018c50` vs
     * `FUN_00018d40`/`FUN_00018d30`) before stamping the real vtable
     * pointer, matching the same real "metaclass association" idiom this
     * project's already-transcribed constructors use elsewhere (e.g.
     * `IOATIR500Shared`'s own ctor) - almost certainly the GCC PPC ABI's
     * real complete-object vs base-object constructor pair for the same
     * logical constructor, not two genuinely different overloads. Real
     * own object size CONFIRMED 0x28 bytes (allocation-site cross-check,
     * issue #23).
     */
    ATIR500Memory();

    /*
     * init - CONFIRMED real body, real addr 0x18d50. Calls this class's
     * own real vtable slot `+0x48` first (the real gate every one of
     * this class's real entry points shares - same real vtable-indirect
     * call convention as `IOATIR500Shared::init`, issue #24) - if that
     * succeeds, walks and frees the real `chunkList` (this+0x10) via the
     * real per-chunk free helper (`FUN_00018de8`, own body not
     * decompiled this pass, same "opaque kernel free wrapper" role as
     * issue #15's own alloc/free pair), leaving the pool's OWN top-level
     * bookkeeping fields otherwise untouched. Real return: bool
     * success/failure, mirroring the vtable call's own.
     *
     * NOTE: this is a genuinely odd real body for a method named
     * `init` - it FREES the chunk list rather than allocating one. Real
     * behavior only makes sense as a "reset/reinit" path: whatever the
     * real `+0x48` vtable call does first (own body unresolved, matches
     * `IOATIR500Shared::init`'s equivalent kxld-patched external call,
     * issue #20/#24's own precedent) apparently re-establishes the pool
     * state that this function then walks and tears back down. No real
     * call site for this specific method exists anywhere else in this
     * project's own reconstruction (only `init_pool`'s two overloads are
     * ever actually called, from `ATIRadeonX1000::allocate_texture`-
     * family code per issue #23) - left exactly as decompiled rather
     * than reinterpreted, since no real caller context is available to
     * confirm a better story.
     */
    bool init();

    /*
     * init_pool - CONFIRMED real bodies, two real overloads:
     *   - (UInt32 poolSize) - real addr 0x18e00. Bootstraps a single
     *     real region spanning the whole pool, offset range
     *     [0, poolSize).
     *   - (UInt32 regionOffset, UInt32 regionSize, UInt32 poolSize) -
     *     real addr 0x18f60. Same bootstrap, but real logic conditional
     *     on `regionSize != 0` splits the pool into TWO initial regions:
     *     a reserved lower boundary node describing
     *     [0, regionOffset+regionSize) and only carves the actual usable
     *     free region starting past it - used by real callers that need
     *     to reserve a real fixed low range of the pool up front (the
     *     third parameter, `poolSize`, is stored into the region's own
     *     real per-node data as the pool's total real extent).
     * Both real bodies: call this class's own real vtable `+0x48` gate
     * first (same as `init`, above); on success, allocate the pool's
     * first real 0x204-byte chunk via the real opaque kernel allocator
     * (`FUN_00018f44`/`FUN_00019108`, own bodies not decompiled - same
     * role as issue #15's own alloc/free pair) if `chunkList` is still
     * empty; then hand-carve the chunk's own memory into the real
     * `poolHeadSlot`/sentinel/first-region `BoundaryNode` triple and a
     * real run of additional free `BoundaryNode` records threaded onto
     * `spareNodeStack`, terminated by a real zero sentinel at the
     * chunk's own end. The exact per-record byte layout this carving
     * loop walks is INFERRED at the level of "0x10-byte BoundaryNode
     * records, threaded via word 0" (consistent with every other real
     * method's own usage of the same records) but the loop's own raw
     * index arithmetic (`iVar2+0x44` vs `piVar7+0xc`, etc. - the two
     * overloads carve a different real number of initial records to
     * make room for the second overload's extra reserved region) was
     * left as literal raw-offset arithmetic rather than force a named
     * per-field breakdown of every single carve step, to avoid asserting
     * more confidence than a single decompile pass actually earned - see
     * each function's own body below for the literal real arithmetic.
     */
    bool init_pool(UInt32 poolSize);
    bool init_pool(UInt32 regionOffset, UInt32 regionSize, UInt32 poolSize);

    /*
     * free - CONFIRMED real body, real addr 0x19120. Walks and frees the
     * real `chunkList` (this+0x10) via the same real opaque per-chunk
     * free helper `init()` uses (`FUN_00019198`, own body not decompiled,
     * issue #15-style opaque allocator wrapper), then calls this object's
     * own real vtable `+0x4c` slot (own target/role unresolved - a real
     * "free self"/teardown-continuation call, own body not investigated
     * this pass) as its final real action.
     */
    void free();

    /*
     * add_to_stack - CONFIRMED real body, real addr 0x191b0. Allocates
     * one more real 0x204-byte chunk (`FUN_00019260`, same opaque
     * allocator role as `init_pool`'s own chunk allocator), links it
     * onto `chunkList`, and hand-carves its memory into a real run of
     * additional `BoundaryNode`-sized records threaded onto
     * `spareNodeStack` (real loop count 0x1f=31 plus the first record
     * set up outside the loop), terminated by a real zero sentinel at
     * the chunk's own end - the real refill path every `alloc`/`reserve`
     * call falls back to when `spareNodeStack` is empty. Real return:
     * bool success/failure (false only if the chunk allocation itself
     * fails).
     */
    bool add_to_stack();

    /*
     * alloc - CONFIRMED real bodies, two real overloads (real mangled
     * symbols `__ZN13ATIR500Memory5allocEP16GLKMemoryElementmm` (3-param,
     * real addr 0x19430) and `__ZN13ATIR500Memory5allocEP16GLKMemoryElementmmmm`
     * (5-param, real addr 0x195f0)). Both are a real free-list allocator
     * walking the address-ordered `BoundaryNode` list for the first real
     * FREE region (`freeFlag < 0`) large enough to hold `size` once its
     * own start offset is rounded up to `alignment` - real node-
     * splitting logic on a partial match (pops a spare node from
     * `spareNodeStack` to represent the leftover free remainder, or
     * pushes a now-empty node back onto it on an exact match), matching
     * `dealloc`'s own inverse merge logic below. The 5-param overload
     * additionally real-bounds the search to the caller-given
     * `[rangeStart, rangeStart+rangeSize)` window (real check: candidate
     * end must not exceed `rangeStart+rangeSize`, real early-return
     * failure otherwise) - the 3-param overload has no such bound and
     * searches the whole real pool; this is the real overload
     * `ATIRadeonX1000::tmpAllocVRAM` (`Headers/ATIRadeonX1000.h`) calls
     * through. Both real bodies call `add_to_stack` first if
     * `spareNodeStack` is empty, failing outright if that also fails.
     * Real return: bool success/failure (not a pointer) - fills in the
     * real `elem+0x8`/`elem+0xC` output fields (see header comment
     * above) only on success.
     */
    UInt32 alloc(GLKMemoryElement *elem, UInt32 size, UInt32 alignment);
    UInt32 alloc(GLKMemoryElement *elem, UInt32 size, UInt32 alignment, UInt32 rangeStart, UInt32 rangeSize);

    /*
     * reserve - CONFIRMED real body, real addr 0x19270. A real variant of
     * `alloc` that reserves a CALLER-SPECIFIED offset range
     * (`[offset, offset+size)`, no alignment search - real `elem+0xC`
     * output field always zeroed) rather than searching for a fitting
     * free region - real logic walks the address-ordered list to find
     * the real free node whose own region actually contains the
     * requested range, then applies the exact same real node-
     * splitting/merging logic `alloc` uses to carve it out. Real return:
     * bool success/failure. No real caller of this method exists
     * anywhere else in this project's own reconstruction so far - likely
     * used by a real caller this pass never reached (candidate: a real
     * fixed/pre-mapped VRAM reservation done once at accelerator start,
     * matching this class's own two real known instances' very different
     * roles - the "main" GART pool almost certainly reserves some real
     * fixed low range this way before general `alloc` calls begin).
     */
    UInt32 reserve(GLKMemoryElement *elem, UInt32 offset, UInt32 size);

    /*
     * dealloc - CONFIRMED real name/signature (real mangled symbol
     * __ZN13ATIR500Memory7deallocEP16GLKMemoryElement, kext offset
     * 0x197d0). Real body: reads the block's own real offset back from
     * `elem+0x8`, clears the real `elem+0x0`/`elem+0x4`/`elem+0x8`/
     * `elem+0xC` bookkeeping words the corresponding `alloc`/`reserve`
     * call wrote (this project's own read of the real decompile:
     * `elem+0x0`/`elem+0x4` are real per-element node-back-pointer
     * bookkeeping the allocator itself maintains, NOT caller-owned data -
     * added to the `GLKMemoryElement` field notes above, previously
     * undocumented), then merges the freed node back into the real
     * doubly-linked list depending on which of its real neighbors (via
     * the freed node's own prev/next) are ALSO already free: merges with
     * both, merges with just one on either side, or (no free neighbor)
     * simply flips the node's own real `freeFlag` on in place. A node
     * consumed entirely by a merge is pushed back onto `spareNodeStack`,
     * mirroring `alloc`'s own reverse operation. Real return: bool
     * success/failure (false only if `spareNodeStack` was empty AND
     * `add_to_stack` also failed - a real defensive gate this function
     * shares with `alloc`, even though a dealloc merge does not always
     * need a spare node) - never checked at any of this project's own
     * real call sites so far.
     */
    UInt32 dealloc(GLKMemoryElement *elem);

    /*
     * total_free - CONFIRMED real body, real addr 0x19910. Walks the
     * real address-ordered `BoundaryNode` list once, summing
     * `(next->offset - node->offset)` for every real node whose own
     * `freeFlag` is set - i.e. the real total free byte count across the
     * whole pool. Real return: signed int (matches every other real
     * size/offset field in this class).
     */
    int total_free();
};

#endif /* ATIR500MEMORY_H */
