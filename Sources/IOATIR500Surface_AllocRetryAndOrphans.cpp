/*
 * IOATIR500Surface_AllocRetryAndOrphans.cpp
 *
 * RESOLVED (issue #1, get-it-linking pass): real bodies for
 * `alloc_surfaces_retry`, `attach_buffer_backing_store`,
 * `free_buffer_backing_orphans` (IOATIR500Surface), and
 * `addOrphanTexture` (IOATIR500Accelerator) - found via Ghidra
 * decompile at each function's own real, substantial address (every
 * other match is a trivial self-recursive stub/thunk artifact).
 *
 * Confidence: CONFIRMED for control flow and every real struct offset.
 * `+0x570` is already independently named elsewhere in this project
 * (allocVendorTextureBuffer). The two real "brief unlock, yield twice,
 * relock" helper calls in `alloc_surfaces_retry`'s own retry loop
 * (real addresses, each taking a single literal argument) are not
 * independently identified - pinned by address per this project's own
 * established convention for a genuinely unidentified local helper.
 */

#include "../Headers/IOATIR500Surface.h"
#include "../Headers/IOATIR500Accelerator.h"
#include "../Headers/ATIRadeonX1000.h"
#include "../Headers/ATIRadeonX1000Types.h"

namespace {
inline UInt32 &U32At(void *base, int offset) { return *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt16 &U16At(void *base, int offset) { return *reinterpret_cast<UInt16 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt8  &U8At(void *base, int offset)  { return *(reinterpret_cast<UInt8 *>(base) + offset); }
} // namespace

extern "C" void GLSurfaceRetry_mutex_lock(void *) asm("_IOLockLock");
extern "C" void GLSurfaceRetry_mutex_unlock(void *) asm("_IOLockUnlock");
/* RESOLVED (issue #58 follow-up): FUN_000149f4 = thread_block (0x32eec),
 * FUN_000149e4 = IOSleep (0x2b255c) - a yield then a 1 ms sleep, live kxld read. */
extern "C" void GLSurfaceRetry_thread_block(UInt32 continuation) asm("_thread_block");
extern "C" void GLSurfaceRetry_IOSleep(UInt32 milliseconds) asm("_IOSleep");

/*
 * alloc_surfaces_retry - CONFIRMED, transcribed faithfully. Real body:
 * an up-to-0x3e9-iteration retry loop. `lockType==0` (write) requires
 * the accelerator's own +0x80 "ready" flag; `lockType==1`/`2` (the two
 * real per-lock-type slots, +0xbd0/+0xbd1) instead short-circuit
 * success immediately if that slot is already non-zero. Otherwise
 * tries `alloc_surfaces_pageq` against the caller's own format mask;
 * a real "would need eviction" result (2) fails outright, a real
 * "nothing to do" result (0) succeeds outright, and any other result
 * retries after a brief unlock/yield/relock. After 0x3e9 failed
 * retries, falls back to a real last-resort attempt against just this
 * surface's own persistent bits (+0xc1c & 3).
 */
IOReturn IOATIR500Surface::alloc_surfaces_retry(UInt32 formatMask, eLockType lockTypeE) {
    UInt32 lockType = static_cast<UInt32>(lockTypeE);
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 isWrite = static_cast<UInt8>((lockType == 0) << 1);
    UInt8 isType2 = static_cast<UInt8>((lockType == 2) << 1);
    UInt8 isType1 = static_cast<UInt8>((lockType == 1) << 1);
    SInt32 retries = 0x3e9;

    for (;;) {
        if ((isWrite >> 1 & 1) != 0) {
            if (U8At(*reinterpret_cast<void **>(self + 0xd50), 0x80) == 0) {
                return static_cast<IOReturn>(0xe00002be);
            }
        } else {
            UInt8 slot;
            if ((isType1 >> 1 & 1) != 0) {
                slot = U8At(self, 0xbd0);
            } else if ((isType2 >> 1 & 1) != 0) {
                slot = U8At(self, 0xbd1);
            } else {
                goto checkEmptyMask;
            }
            if (slot != 0) {
                return static_cast<IOReturn>(0xe00002cc);
            }
        }
    checkEmptyMask:
        if ((U32At(self, 0xbf8) & 0x20000000) != 0) {
            return static_cast<IOReturn>(0xe00002cc);
        }
        if ((U32At(self, 0xbf8) & formatMask) == 0) {
            return 0;
        }
        if ((isWrite >> 1 & 1) == 0 && U8At(*reinterpret_cast<void **>(self + 0xd50), 0x80) == 0) {
            return static_cast<IOReturn>(0xe00002be);
        }
        {
            SInt32 pageqResult = alloc_surfaces_pageq(formatMask, 0, false);
            if (pageqResult == 0) {
                return 0;
            }
            if (pageqResult == 2) {
                return static_cast<IOReturn>(0xe00002cc);
            }
        }
        retries -= 1;
        if (retries == 0) {
            SInt32 lastResort = alloc_surfaces_pageq(U32At(self, 0xc1c) & 3, 0, false);
            return (lastResort == 0) ? static_cast<IOReturn>(0) : static_cast<IOReturn>(0xe00002cc);
        }
        {
            UInt8 *accel = *reinterpret_cast<UInt8 **>(self + 0xd50);
            GLSurfaceRetry_mutex_unlock(*reinterpret_cast<void **>(accel + 0x840));
            GLSurfaceRetry_thread_block(0);
            GLSurfaceRetry_IOSleep(1);
            accel = *reinterpret_cast<UInt8 **>(self + 0xd50);
            GLSurfaceRetry_mutex_lock(*reinterpret_cast<void **>(accel + 0x840));
        }
    }
}

/*
 * attach_buffer_backing_store - CONFIRMED, transcribed faithfully.
 * Real body: allocates a real fixed-size (0xc0-byte) tracking record
 * via the accelerator's own `allocVendorTextureBuffer` (+0x570,
 * already named elsewhere in this project), zero-initializes a real
 * ~0x30-byte sub-record embedded at its own +0x14, wires the caller's
 * real memory descriptor and alignment/pitch fields in, and - if this
 * surface has a real "notify on attach" flag (+0xbf7) and the target
 * buffer already has its own live descriptor - issues one more real
 * "set cache mode" vtable call (+0xdc, mode 2, the same real shape
 * already established for `connect_buffer_backing_store`).
 */
UInt32 IOATIR500Surface::attach_buffer_backing_store(ATIR500SurfaceBuffer *buffer, IOMemoryDescriptor *memory,
                                                      UInt32 param3, UInt32 alignedPitch) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *buf = reinterpret_cast<UInt8 *>(buffer);
    ATIRadeonX1000 *accel = *reinterpret_cast<ATIRadeonX1000 **>(self + 0xd50);
    VendorTextureBuffer *rec = accel->allocVendorTextureBuffer(0xc0);
    UInt32 result = 0;
    if (rec != nullptr) {
        UInt8 *recBytes = reinterpret_cast<UInt8 *>(rec);
        U32At(buf, 0x24) = reinterpret_cast<UInt32>(recBytes);
        U32At(recBytes, 0x80) = 0;
        U32At(recBytes, 0x14) = reinterpret_cast<UInt32>(recBytes + 0x80);
        UInt8 *sub = recBytes + 0x80;
        U32At(sub, 0) = 0;
        U32At(sub, 4) = 0;
        U32At(sub, 8) = 0;
        U16At(sub, 0x1c) = 0;
        U16At(sub, 0x1e) = 0;
        U16At(sub, 0x20) = 0;
        U16At(sub, 0x22) = 0;
        U16At(sub, 0x24) = 0;
        U16At(sub, 0x26) = 0;
        U16At(sub, 0x28) = 0;
        U16At(sub, 0x2a) = 0;
        U16At(sub, 0x2c) = 0;
        U16At(sub, 0x2e) = 0;
        U16At(sub, 0x30) = 0;
        U16At(sub, 0x32) = 0;
        U8At(sub, 0x14) = 1;
        U8At(sub, 0x15) = 0;
        U8At(sub, 0x16) = 5;
        U8At(sub, 0x34) = 0;
        U8At(sub, 0x35) = 0;
        U8At(sub, 0x17) = 0;
        U16At(sub, 0x36) = 0;
        *reinterpret_cast<IOMemoryDescriptor **>(recBytes + 8) = memory;
        U8At(recBytes, 0x20) = 5;
        *reinterpret_cast<SInt16 *>(recBytes + 0x50) = static_cast<SInt16>(param3);
        *reinterpret_cast<SInt16 *>(recBytes + 0x52) = static_cast<SInt16>(alignedPitch);
        U8At(recBytes, 0x58) = 1;
        U32At(recBytes, 0x54) = U32At(self, 0x7c);

        void *innerDesc = nullptr;
        if (U8At(self, 0xbf7) != 0 && U32At(buf, 0x24) != 0) {
            innerDesc = *reinterpret_cast<void **>(reinterpret_cast<UInt8 *>(*reinterpret_cast<void **>(buf + 0x24)) + 8);
        }
        if (innerDesc != nullptr) {
            typedef void (*Fn0xdc)(void *, UInt32, UInt32);
            (*reinterpret_cast<Fn0xdc *>(*reinterpret_cast<void ***>(innerDesc) + (0xdc / 4)))(innerDesc, 2, 0);
        }
        result = 1;
    }
    return result;
}

/*
 * free_buffer_backing_orphans - CONFIRMED, simple: releases the
 * pending-eviction slot's (+0xd8c) own inner memory-mapping handle if
 * set, then deletes the backing itself via `delete_buffer_backing`
 * and clears the slot.
 */
void IOATIR500Surface::free_buffer_backing_orphans() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *pending = *reinterpret_cast<UInt8 **>(self + 0xd8c);
    void *inner = *reinterpret_cast<void **>(pending + 0x10);
    if (inner != nullptr) {
        typedef void (*ReleaseFn)(void *);
        (*reinterpret_cast<ReleaseFn *>(*reinterpret_cast<void ***>(inner) + (0x18 / 4)))(inner);
        U32At(*reinterpret_cast<void **>(self + 0xd8c), 0x10) = 0;
        pending = *reinterpret_cast<UInt8 **>(self + 0xd8c);
    }
    delete_buffer_backing(reinterpret_cast<IOTextureBuffer *>(pending));
    U32At(self, 0xd8c) = 0;
}

/*
 * addOrphanTexture - CONFIRMED, transcribed faithfully. Real body:
 * splices the buffer onto the accelerator's own real doubly-linked
 * orphan-texture list (head at +0x660, each node's own +0x24/+0x28
 * prev/next links, the list's own sentinel node embedded at
 * accelerator+0x63c), and if the accelerator's own "orphan sweep
 * scheduled" flag (+0x82) is clear, schedules one via a real
 * `IOService::setTimeoutMS`-shaped vtable call (+300/0x12c on the
 * accelerator's own +0xb8 provider object) with a real 100ms delay,
 * setting the flag so it isn't scheduled again until the sweep runs.
 */
void IOATIR500Accelerator::addOrphanTexture(IOTextureBuffer *buffer) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *buf = reinterpret_cast<UInt8 *>(buffer);
    UInt8 *prev = *reinterpret_cast<UInt8 **>(buf + 0x24);
    UInt8 *next = *reinterpret_cast<UInt8 **>(buf + 0x28);
    U32At(prev, 0x28) = reinterpret_cast<UInt32>(next);
    *reinterpret_cast<UInt8 **>(buf + 0x28) = self + 0x63c;
    U32At(next, 0x24) = reinterpret_cast<UInt32>(prev);
    U32At(buf, 0x24) = U32At(self, 0x660);
    *reinterpret_cast<UInt8 **>(self + 0x660) = buf;
    U32At(*reinterpret_cast<void **>(buf + 0x24), 0x28) = reinterpret_cast<UInt32>(buf);

    if (U8At(self, 0x82) == 0) {
        typedef void (*Fn0x12c)(void *, UInt32);
        void *provider = *reinterpret_cast<void **>(self + 0xb8);
        (*reinterpret_cast<Fn0x12c *>(*reinterpret_cast<void ***>(provider) + (300 / 4)))(provider, 100);
        U8At(self, 0x82) = 1;
    }
}
