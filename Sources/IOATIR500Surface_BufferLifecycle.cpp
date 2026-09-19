/*
 * IOATIR500Surface_BufferLifecycle.cpp
 *
 * RESOLVED (issue #1, get-it-linking pass): real bodies for
 * `alloc_surfaces_keep`, `connect_buffer_backing_store`, and
 * `copy_buffer_from_backing_store` - three real IOATIR500Surface
 * base-class methods, found via Ghidra decompile at each function's
 * own real, substantial address (every other match is a trivial
 * self-recursive stub/thunk artifact, not real content).
 *
 * Confidence: CONFIRMED for control flow and every real struct offset.
 * Two real vtable slots on this class's own vtable (+0x5f8 in
 * alloc_surfaces_keep, +0x5f0/+0x5ec in copy_buffer_from_backing_store)
 * are not independently named elsewhere in this project - called via
 * this project's established raw vtable-cast idiom.
 */

#include "../Headers/IOATIR500Surface.h"
#include "../Headers/ATIRadeonX1000Types.h"
#include <IOKit/IOMemoryDescriptor.h>

namespace {
inline UInt32 &U32At(void *base, int offset) { return *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt16 &U16At(void *base, int offset) { return *reinterpret_cast<UInt16 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt8  &U8At(void *base, int offset)  { return *(reinterpret_cast<UInt8 *>(base) + offset); }
} // namespace

/*
 * alloc_surfaces_keep - CONFIRMED. Real body: for each of the 23 real
 * per-format records (0..0x16) whose bit is set in BOTH the caller's
 * own `formatMask` and this surface's own real "empty" bitmask
 * (+0xbf8), calls this surface's own +0x5f8 vtable slot (real identity
 * not independently confirmed elsewhere in this project) - real
 * result 0 for any single format immediately fails the whole call
 * (real early-return `2`, "some format's allocation attempt failed")
 * once every bit has been tried.
 */
UInt32 IOATIR500Surface::alloc_surfaces_keep(IOATIR500Surface *excludeSurface, VendorTextureBuffer **excludeList,
                                              SInt32 param3, UInt32 formatMask) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    typedef UInt32 (*Fn0x5f8)(void *, IOATIR500Surface *, VendorTextureBuffer **, SInt32, UInt32);
    UInt32 idx = 0;
    UInt32 allOk = 1;
    UInt32 emptyMask = U32At(self, 0xbf8);
    for (;;) {
        if ((formatMask & emptyMask & (1u << (idx & 0x3f))) != 0) {
            UInt32 ok = (*reinterpret_cast<Fn0x5f8 *>(*reinterpret_cast<void ***>(self) + (0x5f8 / 4)))(
                self, excludeSurface, excludeList, param3, idx);
            allOk &= ok;
        }
        bool atEnd = (idx == 0x16);
        idx += 1;
        if (atEnd) break;
        if (allOk == 0) {
            return 2;
        }
    }
    if (allOk == 0) {
        return 2;
    }
    return 0;
}

/*
 * connect_buffer_backing_store - CONFIRMED. Real body: computes a
 * real page-aligned CPU-visible backing size (real per-buffer height
 * times a caller-supplied row multiplier, plus a real per-surface
 * override at +0xd4c if nonzero), allocates it via a real, not yet
 * independently named local helper (address-pinned, own body not
 * decompiled this pass), sets a real cache mode (+0xdc vtable call,
 * mode 2) on success, and attaches it via `attach_buffer_backing_store`.
 * The real decompile reads a global named `_ASICSupportsAGP` for every
 * one of this function's own alignment/rounding computations
 * (`-X & expr`, `X-1 & expr` - the standard power-of-two round-up/down
 * idiom) - Ghidra's own emitted warning ("Globals starting with '_'
 * overlap smaller symbols at the same address") confirms this is a
 * real symbol-table collision, not the same small integer flag this
 * project already uses that name for elsewhere. The value being
 * rounded to is a real page size, matching this project's own
 * established `0x1000` constant used for the identical purpose
 * throughout (e.g. every `resolve`-shaped vtable call elsewhere in
 * this file set) - modeled as the literal `0x1000` here instead.
 */
/* FUN_000128ec: RESOLVED (issue #58 follow-up) - live kxld target 0x2d617c,
 * IOMemoryDescriptor::withAddress(unsigned long, unsigned long, IODirection,
 * task*). Parameters below renamed from the earlier guesses to the real ones. */
extern "C" void *FUN_000128ec(UInt32 address, UInt32 length, UInt32 direction, void *task) asm("__ZN18IOMemoryDescriptor11withAddressEjm11IODirectionP4task");

bool IOATIR500Surface::connect_buffer_backing_store(ATIR500SurfaceBuffer *buffer, unsigned int options, UInt32 rowMultiplier) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *buf = reinterpret_cast<UInt8 *>(buffer);
    const UInt32 kPageSize = 0x1000;

    UInt32 remainder = (kPageSize - 1) & options;
    UInt32 size = (~(kPageSize - 1)) & (kPageSize + U16At(buf, 0x1e) * rowMultiplier + remainder - 1);
    if (U32At(self, 0xd4c) != 0) {
        size = U32At(self, 0xd4c);
    }
    IOMemoryDescriptor *descriptor = reinterpret_cast<IOMemoryDescriptor *>(
        FUN_000128ec(options & ~(kPageSize - 1), size, 0x10003, *reinterpret_cast<void **>(self + 0x78)));
    if (descriptor != nullptr) {
        typedef void (*Fn0xdc)(void *, UInt32, UInt32);
        (*reinterpret_cast<Fn0xdc *>(*reinterpret_cast<void ***>(descriptor) + (0xdc / 4)))(descriptor, 2, 0);
        attach_buffer_backing_store(buffer, descriptor, remainder, rowMultiplier);
        U8At(*reinterpret_cast<void **>(buf + 0x24), 0x59) = 1;
    }
    return descriptor != nullptr;
}

/*
 * copy_buffer_from_backing_store - CONFIRMED. Real body: only actually
 * copies anything if the buffer's own backing record's own +0x54
 * "generation" tag matches this surface's own current one (+0x7c);
 * when it does, accumulates the copy's own real byte count into the
 * accelerator's own +0x724 field, then for every real (row, column)
 * tile pair (dimensions at the buffer's own +0x20/+0x22 fields) calls
 * this surface's own +0x5f0 "resolve tile address" vtable slot
 * followed by its own +0x5ec "blit" vtable slot (both real, not
 * independently named elsewhere in this project), stamping the
 * buffer's own backing record with the current generation afterward.
 * Also refreshes every other per-format record's own matching
 * generation tag. Finally, under a real specific combination of this
 * surface's own state flags (+0xc09/+0xbd0/+0xc08/+0xbf7), issues one
 * more real vtable call (the buffer's own memory descriptor, +0xdc,
 * mode 3) - the same real "set cache mode" shape
 * `connect_buffer_backing_store` above already establishes, mode 3
 * instead of 2.
 */
UInt32 IOATIR500Surface::copy_buffer_from_backing_store(ATIR500SurfaceBuffer *buffer) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *buf = reinterpret_cast<UInt8 *>(buffer);

    if (U32At(*reinterpret_cast<void **>(buf + 0x24), 0x54) == U32At(self, 0x7c)) {
        void *accel = *reinterpret_cast<void **>(self + 0xd50);
        U32At(accel, 0x724) += U32At(buf, 0x10);

        UInt32 cols = U16At(buf, 0x20);
        UInt32 currentTag = U32At(self, 0x7c);
        UInt32 mipLevel = U32At(*reinterpret_cast<void **>(self + 0xd50), 0x50);
        if (cols != 0) {
            UInt16 rows = U16At(buf, 0x22);
            UInt32 col = 0;
            do {
                if (rows != 0) {
                    UInt32 row = 0;
                    do {
                        UInt32 tileAddr = 0;
                        UInt32 tileInfo[6] = {};
                        typedef void (*Fn0x5f0)(void *, ATIR500SurfaceBuffer *, UInt32, UInt32, UInt32 *, UInt32 *, UInt32);
                        (*reinterpret_cast<Fn0x5f0 *>(*reinterpret_cast<void ***>(self) + (0x5f0 / 4)))(
                            self, buffer, col, row, &tileAddr, tileInfo, 0);
                        UInt32 nextRow = row + 1;
                        typedef void (*Fn0x5ec)(void *, UInt32, UInt32, UInt32, UInt32, UInt32, UInt32, ATIR500SurfaceBuffer *, UInt32, UInt32, UInt32, UInt32, UInt32);
                        (*reinterpret_cast<Fn0x5ec *>(*reinterpret_cast<void ***>(self) + (0x5ec / 4)))(
                            self, 0, 0, tileAddr, tileInfo[0], col, row, buffer, mipLevel - 1, 0, 0, 0, 1);
                        U32At(*reinterpret_cast<void **>(buf + 0x24), 8) = currentTag;
                        rows = U16At(buf, 0x22);
                        row = nextRow;
                        if (row >= rows) break;
                    } while (true);
                    cols = U16At(buf, 0x20);
                }
                col += 1;
            } while (col < cols);
        }

        UInt8 *rec = self + 0xcc;
        for (SInt32 i = 0x17; i != 0; --i) {
            void *recPtr = *reinterpret_cast<void **>(rec);
            rec += 0x78;
            if (recPtr != nullptr && currentTag == U32At(recPtr, 0x54)) {
                U32At(recPtr, 0x54) = U32At(self, 0x7c);
            }
        }
    }

    if (U8At(self, 0xc09) == 0 && (U32At(self, 0xbd0) & 0xffff0000) == 0 && U8At(self, 0xc08) == 0 &&
        U8At(self, 0xbf7) != 0 && U32At(buf, 0x24) != 0) {
        void *backing = *reinterpret_cast<void **>(buf + 0x24);
        void *desc = *reinterpret_cast<void **>(reinterpret_cast<UInt8 *>(backing) + 8);
        if (desc != nullptr) {
            typedef void (*Fn0xdc)(void *, UInt32, UInt32);
            (*reinterpret_cast<Fn0xdc *>(*reinterpret_cast<void ***>(desc) + (0xdc / 4)))(desc, 3, 0);
        }
    }
    return 1;
}
