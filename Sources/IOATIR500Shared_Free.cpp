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

void IOATIR500Shared::free() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

    UInt8 *tex = reinterpret_cast<UInt8 *>(U32At(self, 0x24));
    UInt32 head = 0;
    if (tex != nullptr) {
        do {
            UInt8 *next;
            if (U8At(tex, 0x20) == 4) {
                next = reinterpret_cast<UInt8 *>(U32At(tex, 0x3c));
            } else {
                next = reinterpret_cast<UInt8 *>(U32At(tex, 0x3c));
                if (next != nullptr) {
                    UInt8 kind = U8At(next, 0x20);
                    while (kind == 4 && (next = reinterpret_cast<UInt8 *>(U32At(next, 0x3c)), next != nullptr)) {
                        kind = U8At(next, 0x20);
                    }
                }
                ResetRefcount(tex);
                delete_texture(reinterpret_cast<VendorTextureBuffer *>(tex));
            }
            tex = next;
        } while (tex != nullptr);
        head = U32At(self, 0x24);
    }
    while (head != 0) {
        ResetRefcount(reinterpret_cast<UInt8 *>(head));
        delete_texture(reinterpret_cast<VendorTextureBuffer *>(U32At(self, 0x24)));
        head = U32At(self, 0x24);
    }

    UInt8 *accel = reinterpret_cast<UInt8 *>(U32At(self, 0xc));
    if (this == reinterpret_cast<IOATIR500Shared *>(U32At(accel, 0x6c))) {
        U32At(accel, 0x6c) = 0;
        U32At(reinterpret_cast<void *>(U32At(self, 0xc)), 0x70) = 0;
        accel = reinterpret_cast<UInt8 *>(U32At(self, 0xc));
    }
    reinterpret_cast<IOATIR500Accelerator *>(accel)->freeOrphanTexture(true);

    UInt32 *node = reinterpret_cast<UInt32 *>(U32At(self, 0x20));
    while (node != nullptr) {
        UInt32 *next = reinterpret_cast<UInt32 *>(node[0]);
        ReleaseObj(reinterpret_cast<void *>(node[3]));
        ReleaseObj(reinterpret_cast<void *>(node[2]));
        ReleaseObj(reinterpret_cast<void *>(node[1]));
        IOATIR500Shared_IOFree(node, 0x1c);
        UInt8 *owner = reinterpret_cast<UInt8 *>(U32At(self, 0xc));
        node = next;
        if (owner != nullptr) {
            U32At(owner, 0x808) -= 0x1c;
        }
    }

    free_handles();
    OSObject::free();
}

void IOATIR500Shared::free_handles() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

    UInt32 capacity = U32At(self, 0x14);
    UInt32 totalSize = capacity * 4 + (capacity >> 3);
    IOATIR500Shared_IOFree(reinterpret_cast<void *>(U32At(self, 0x10)), totalSize);
    UInt8 *owner = reinterpret_cast<UInt8 *>(U32At(self, 0xc));
    if (owner != nullptr) {
        U32At(owner, 0x808) = U32At(owner, 0x808) - totalSize;
    }
}
