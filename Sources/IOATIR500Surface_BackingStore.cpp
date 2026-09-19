/*
 * IOATIR500Surface_BackingStore.cpp
 *
 * RESOLVED (issue #1, get-it-linking pass): real bodies for
 * `dealloc_surface`, `free_buffer_backing_store`,
 * `delete_buffer_backing`, and `move_buffer_to_backing_store` - four
 * real IOATIR500Surface base-class methods managing a per-format
 * record's own VRAM allocation and its optional CPU-visible backing
 * store, found via Ghidra decompile at each function's own real,
 * substantial address (every other match is a trivial self-recursive
 * stub/thunk artifact, not real content).
 *
 * Confidence: CONFIRMED for control flow and every real struct offset.
 */

#include "../Headers/IOATIR500Surface.h"
#include "../Headers/IOATIR500Accelerator.h"
#include "../Headers/ATIR500Memory.h"
#include "../Headers/ATIRadeonX1000Types.h"

namespace {
inline UInt32 &U32At(void *base, int offset) { return *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt8  &U8At(void *base, int offset)  { return *(reinterpret_cast<UInt8 *>(base) + offset); }
} // namespace

/*
 * dealloc_surface - CONFIRMED. Real body: if the record at
 * `this+surfaceIndex*0x78+0xb0` has a real allocation, and this index
 * is one of the two "primary" formats (real bitmask `3` - indices
 * 0/1), marks every real attached-buffer-list entry (+0xbcc head,
 * +0x54 next, same real list `reset_req_bits` already established) as
 * dirty via its own +0x14 record's own +0x14 byte, then frees the real
 * VRAM allocation through the accelerator's own `ATIR500Memory`
 * allocator (+0x7c). Always marks the format's own "empty" bit in
 * +0xbf8 before returning success.
 */
/* (re-ported mechanically: see IOATIR500Surface_dealloc_surface_Port.cpp) */


/*
 * free_buffer_backing_store - CONFIRMED. Real body: if the buffer's
 * own CPU-visible backing handle (+0x24, `IOTextureBuffer*`) is set
 * and not already marked released (its own +0x59 flag byte), either
 * deletes it immediately (no real real pending-eviction record at
 * +0x10, or this surface's own +0xd8c "one pending eviction" slot is
 * already occupied) or defers it into that single-slot cache instead.
 */
UInt32 IOATIR500Surface::free_buffer_backing_store(ATIR500SurfaceBuffer *buffer) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *buf = reinterpret_cast<UInt8 *>(buffer);
    UInt8 *backing = *reinterpret_cast<UInt8 **>(buf + 0x24);
    if (U8At(backing, 0x59) == 0) {
        if (U32At(backing, 0x10) == 0 || U32At(self, 0xd8c) != 0) {
            delete_buffer_backing(reinterpret_cast<IOTextureBuffer *>(backing));
        } else {
            U32At(self, 0xd8c) = reinterpret_cast<UInt32>(backing);
        }
        U32At(buf, 0x24) = 0;
    }
    return 1;
}

/*
 * delete_buffer_backing - CONFIRMED. Real body: if the backing
 * handle's own reference count field (+4) is nonzero, asks the
 * accelerator (its own +0x554 vtable call, identity not independently
 * confirmed elsewhere) whether the handle's own memory descriptor
 * (+0x14's own +8 field) is still live; if not, hands it off to the
 * accelerator's real orphan-texture list instead of freeing it
 * outright (unless its own +0x20 flag says otherwise, in which case
 * it's relinked into this surface's own doubly-linked backing list).
 * If it WAS still live (or the refcount was already zero), releases
 * the real memory descriptor and calls the accelerator's own real
 * `releaseVendorTextureBuffer` (+0x574, already named elsewhere in
 * this project) to give the raw VendorTextureBuffer storage back.
 */
/* (re-ported mechanically: see IOATIR500Surface_delete_buffer_backing_Port.cpp) */


/*
 * move_buffer_to_backing_store - CONFIRMED, simple: copies the
 * buffer's live contents into its own CPU-visible backing store
 * (`copy_buffer_to_backing_store`, already established elsewhere in
 * this project), then real-deallocates the VRAM record via
 * `dealloc_surface`, real-indexed by this buffer's own position within
 * the fixed +0xa8-based per-format record array (a real pointer-
 * difference-divided-by-stride computation - the raw decompile
 * expresses the `/0x78` as a compiler-generated reciprocal-multiply
 * constant; represented here as a plain division, semantically
 * identical and far more legible).
 */
bool IOATIR500Surface::move_buffer_to_backing_store(ATIR500SurfaceBuffer *buffer) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    bool result = copy_buffer_to_backing_store(buffer);
    UInt32 index = static_cast<UInt32>((reinterpret_cast<UInt8 *>(buffer) - (self + 0xa8)) / 0x78);
    dealloc_surface(index);
    return result;
}
