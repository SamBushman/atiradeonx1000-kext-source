/*
 * IOATIR500Shared_Free.cpp
 *
 * RESOLVED (issue #58 follow-up): real bodies for `IOATIR500Shared::free`
 * (real addr 0x184d0) and `free_handles` (real addr 0x16b30) - the two
 * teardown functions that had never been transcribed. They became necessary
 * when IOATIR500Shared was corrected to derive from OSObject (see
 * Headers/IOATIR500Shared.h): without them the inherited `OSObject::free()`
 * would leak the texture list, client-shared chunks and handle table.
 *
 * `free` real body, in order:
 *   1. Walks the texture list at `this+0x24` (next = `+0x3c`, kind byte =
 *      `+0x20`). Kind-4 entries (own AGP-mapped companions, deleted together
 *      with the texture that owns them) are skipped; every other entry has its
 *      record's refcount field (`rec+0x10`, `rec = tex+0x14`) reset to its
 *      initial value (`rec+0x12`) and is passed to `delete_texture`. The next
 *      pointer is chosen BEFORE the delete, skipping any run of kind-4 entries.
 *   2. Deletes whatever is still at the list head the same way until empty.
 *   3. If this is the accelerator's currently cached shared object
 *      (`accel+0x6c`), clears that cache pair (`+0x6c`/`+0x70`); then calls
 *      `freeOrphanTexture(true)` on the accelerator (`this+0xc`).
 *   4. Walks the client-shared chunk list at `this+0x20` (real node layout:
 *      word0 = next, words 1..3 = three objects, released via vtable `+0x18` =
 *      `OSObject::release() const`), frees each 0x1c-byte node (`IOFree`) and
 *      subtracts 0x1c from the accelerator's byte-accounting field (`+0x808`).
 *   5. `free_handles()`, then `OSObject::free()` (raw decompile:
 *      `(*pcRam0000004c)(this)`, an indirect call through the OSObject vtable
 *      symbol - Mach-O relocation at 0x18698 targets `__ZTV8OSObject`).
 *
 * `free_handles` real body: frees the combined handle-array + bitmap buffer
 * (`this+0x10`, size `capacity*4 + capacity/8`, capacity at `this+0x14`) and
 * subtracts that size from the accelerator's byte-accounting field (`+0x808`),
 * the exact inverse of `alloc_handles`' accounting.
 *
 * The two helper stubs (`FUN_000186d4`, `FUN_00016ba0`) both resolve, by the
 * kext's Mach-O relocation table, to `IOFree`.
 *
 * Confidence: CONFIRMED for control flow and every real offset/literal - real,
 * complete, standalone decompiles.
 */

#include "../Headers/IOATIR500Shared.h"
#include "../Headers/IOATIR500Accelerator.h"

extern "C" void IOATIR500Shared_IOFree(void *ptr, UInt32 size) asm("_IOFree");

namespace {
inline UInt32 &U32At(void *base, int offset) { return *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt16 &U16At(void *base, int offset) { return *reinterpret_cast<UInt16 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt8  &U8At(void *base, int offset)  { return *(reinterpret_cast<UInt8 *>(base) + offset); }
typedef void (*ReleaseFn)(void *);
inline void ReleaseObj(void *obj) {
    void **vtable = *reinterpret_cast<void ***>(obj);
    reinterpret_cast<ReleaseFn>(vtable[0x18 / 4])(obj);
}
/* real: reset the record's refcount to its initial value, then delete the texture */
inline void ResetRefcount(UInt8 *tex) {
    UInt8 *rec = reinterpret_cast<UInt8 *>(U32At(tex, 0x14));
    U32At(rec, 0x10) = static_cast<UInt32>(U16At(rec, 0x12));
}
} // namespace

/* (re-ported mechanically: see IOATIR500Shared_free_Port.cpp) */


/* (re-ported mechanically: see IOATIR500Shared_free_handles_Port.cpp) */

