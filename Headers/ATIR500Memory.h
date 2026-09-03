/*
 * ATIR500Memory.h
 *
 * A real class this project has not reconstructed - found this pass
 * (issue #23) only as `ATIRadeonX1000::tmpAllocVRAM`/`tmpDeallocVRAM`'s
 * own real delegate object (`this+0x93c`), and independently as
 * `IOATIR500Surface::dealloc_surface`/`ATIR500Surface::alloc_surface_buffer`/
 * `ATIRadeonX1000::allocate_texture`/`deallocate_texture`'s own real
 * delegate (a SEPARATE instance, `accelerator+0x7c`) - a real, substantial
 * free-list VRAM/GART memory-pool allocator. Real own vtable exists
 * (`__ZTV13ATIR500Memory`, `0x49078`) with at least a dozen real methods
 * this project has only decompiled two of (`alloc`'s 5-parameter
 * overload, `dealloc`) - `init`/`init_pool` (two overloads)/`free`/
 * `add_to_stack`/`reserve`/`alloc`'s 3-parameter overload/`total_free`
 * all real, confirmed to exist, not investigated. Left as a minimal
 * shell rather than inventing an interface this project hasn't actually
 * decompiled - see GAPS.md.
 */

#ifndef ATIR500MEMORY_H
#define ATIR500MEMORY_H

struct GLKMemoryElement;

class ATIR500Memory {
public:
    /*
     * alloc - CONFIRMED real name/signature (real mangled symbol
     * __ZN13ATIR500Memory5allocEP16GLKMemoryElementmmmm, kext offset
     * 0x195f0 - the real 5-parameter overload; a real 3-parameter
     * overload also exists, real addr 0x19430, not decompiled this
     * pass). Real body: a genuine free-list allocator with real
     * node-splitting/merging logic over a doubly-linked list of blocks,
     * returning a real boolean success/failure (not a pointer) - fills
     * in real fields on the caller-owned `GLKMemoryElement` on success.
     */
    UInt32 alloc(GLKMemoryElement *elem, UInt32 size, UInt32 alignment, UInt32 rangeStart, UInt32 rangeSize);

    /*
     * dealloc - CONFIRMED real name/signature (real mangled symbol
     * __ZN13ATIR500Memory7deallocEP16GLKMemoryElement, kext offset
     * 0x197d0). Real body: the inverse free-list operation (merges the
     * freed block back into its neighbors), also returns a real boolean
     * success/failure - never checked at any of this project's own real
     * call sites so far.
     */
    UInt32 dealloc(GLKMemoryElement *elem);
};

#endif /* ATIR500MEMORY_H */
