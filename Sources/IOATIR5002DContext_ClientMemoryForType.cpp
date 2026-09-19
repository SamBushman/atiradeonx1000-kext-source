/*
 * IOATIR5002DContext_ClientMemoryForType.cpp
 *
 * RESOLVED (ledger pass): IOATIR5002DContext::clientMemoryForType (real addr 0xd6f0, vtable +0x580), transcribed
 * from the shipped kext; the retry loops and every alloc_surfaces argument were checked against the disassembly.
 *
 *   type 1: retain and hand out the context-buffer descriptor (this+0xbc), re-initialise its header.
 *   type 2: retain and hand out the accelerator's shared descriptor (accelerator+0xac).
 *   type 0: the 2D "flush the current command buffer and hand the client a fresh one" path. Waits for the display,
 *           re-validates the bound surface (alloc_surfaces retried up to 1000 times with thread_block(0) +
 *           IOSleep(1) between attempts), submits the previous context's buffer if a different context last
 *           submitted, runs process_command_buffer over the client's buffer, submits it through accelerator
 *           vtable +0x560, updates the surface's stamps/refcounts and the accelerator's live-surface ring, swaps
 *           in the next command buffer from the accelerator's 0x1c-byte-entry ring (allocating more on demand)
 *           and schedules the deferred flush notification before returning the fresh command-buffer descriptor.
 *
 * Accelerator vtable slots used here (IOATIR500Accelerator, all pure in the base): +0x54c wait for stamp,
 * +0x554 stamp passed?, +0x558 wait for stamp, +0x560 submit a VendorCommandDescriptor, returning its stamp.
 * Surface vtable slots: +0x5b4 update_ref_stamps, +0x5b8 increment_refcounts, +0x5bc decrement_refcounts,
 * +0x5c0 build_swap, +0x5d4 submit_swap_buffer(index, 0).
 */

#include "../Headers/IOATIR5002DContext.h"
#include "../Headers/ATIRadeonX1000.h"
#include "../Headers/IOATIR500Surface.h"

extern "C" void Ctx2DM_lock(void *) asm("_IOLockLock");
extern "C" void Ctx2DM_unlock(void *) asm("_IOLockUnlock");
extern "C" void Ctx2DM_sleep(void *lock, void *event, UInt32 interruptible) asm("_IOLockSleep");
extern "C" void Ctx2DM_thread_block(UInt32 continuation) asm("_thread_block");
extern "C" void Ctx2DM_IOSleep(UInt32 ms) asm("_IOSleep");

namespace {
inline UInt32 &U32At(void *base, int offset) { return *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt16 &U16At(void *base, int offset) { return *reinterpret_cast<UInt16 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt8  &U8At(void *base, int offset)  { return *(reinterpret_cast<UInt8 *>(base) + offset); }
typedef SInt32 (*StampFn)(void *, UInt32);
typedef UInt32 (*SubmitFn)(void *, VendorCommandDescriptor *);
typedef void (*NotifyFn)(void *, UInt32);
inline void *AccelSlot(void *accel, int off) { return *reinterpret_cast<void **>(*reinterpret_cast<UInt8 **>(accel) + off); }
} // namespace

#define ACCEL() reinterpret_cast<UInt8 *>(accelerator)
#define ACCEL_LOCK() (*reinterpret_cast<void **>(ACCEL() + 0x840))

IOReturn IOATIR5002DContext::clientMemoryForType(UInt32 type, UInt32 *options, IOMemoryDescriptor **memory) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

    if (type == 1) {
        Ctx2DM_lock(ACCEL_LOCK());
        reinterpret_cast<OSObject *>(U32At(self, 0xbc))->retain();
        *options = 0;
        *memory = reinterpret_cast<IOMemoryDescriptor *>(U32At(self, 0xbc));
        init_context_buffer_header(reinterpret_cast<VendorContextBufferHeader *>(U32At(self, 200)), 0x1000);
        Ctx2DM_unlock(ACCEL_LOCK());
        return 0;
    }
    if (type != 0) {
        if (type != 2) {
            return 0xe00002c2;
        }
        if (U32At(ACCEL(), 0xac) == 0) {
            return 0xe00002be;
        }
        reinterpret_cast<OSObject *>(U32At(ACCEL(), 0xac))->retain();
        *options = 0;
        *memory = reinterpret_cast<IOMemoryDescriptor *>(U32At(ACCEL(), 0xac));
        return 0;
    }

    UInt32 tries = 0;
    UInt32 flags = 0;
    IOATIR500Surface *surface;
    VendorCommandDescriptor desc;
    UInt8 *accel;

    for (;;) {
        for (;;) {
            Ctx2DM_lock(ACCEL_LOCK());
            surface = boundSurface;
            if (surface == nullptr || U32At(surface, 0xa4) < 0x100) {
                accel = ACCEL();
            } else {
                accel = ACCEL();
                if (U8At(accel, 0x80) == 0) {
                    do {
                        Ctx2DM_sleep(reinterpret_cast<void *>(U32At(accel, 0x840)), accel, 0);
                    } while (U8At(accel, 0x80) == 0);
                    accel = ACCEL();
                    surface = boundSurface;
                }
            }
            if (U8At(accel, 0x80) == 0) {
                tries = 0x3e9;
                flags = 0;
                goto settled;
            }
            if (surface == nullptr) {
                flags = 0;
                goto settled;
            }
            if (U8At(surface, 0xbf6) == 0) {
                break;
            }
            surface->retain();
            Ctx2DM_unlock(ACCEL_LOCK());
            surface->sleep_blocked();
            surface->release();
        }

        flags = U32At(surface, 0xbfc);
        if ((U32At(surface, 0xbec) & 0xffffff) != 0) {
            flags |= 2;
        }
        if (U8At(surface, 0xbd0) == 0 || tries == 999) {
            UInt32 bits = U32At(surface, 0xbf8);
            UInt32 want = U32At(self, 0x8c) | U32At(surface, 0xc1c);
            if ((want & bits) == 0) {
                goto revalidated;
            }
            if ((bits & 0x20000000) != 0) {
                tries = 0x3e9;
                goto revalidated;
            }
            UInt32 mask = want & 0x7fffff;
            if ((bits & mask) != 0) {
                UInt32 r = surface->alloc_surfaces(mask, false);
                if (r != 0) {
                    if (r != 2) {
                        goto retry;
                    }
                    surface = boundSurface;
                    tries = 0x3e9;
                    goto settled;
                }
                surface = boundSurface;
                if ((U32At(surface, 0xbf8) & U32At(surface, 0xc1c) & 0x10000000) == 0) {
                    goto revalidated;
                }
            }
            surface->build_swap();
            U32At(boundSurface, 0xbf8) &= 0xefffffff;
            surface = boundSurface;
            goto settled;
        }
    retry:
        if (tries == 1000) {
            surface = boundSurface;
            break;
        }
        ++tries;
        Ctx2DM_unlock(ACCEL_LOCK());
        Ctx2DM_thread_block(0);
        Ctx2DM_IOSleep(1);
    }

settled:
    if (surface == nullptr) {
        if (U32At(self, 0x110) == 0xffff) {
            goto finish;
        }
    }
revalidated:
    if (tries > 999) {
        if (tries > 1000) {
            goto finish;
        }
        if (surface->alloc_surfaces((U32At(self, 0x8c) | U32At(surface, 0xc1c)) & 0x7fffff, true) != 0) {
            goto finish;
        }
        surface = boundSurface;
        if ((U32At(surface, 0xbf8) & U32At(surface, 0xc1c) & 0x10000000) != 0) {
            surface->build_swap();
            U32At(boundSurface, 0xbf8) &= 0xefffffff;
        }
    }

    if (self != reinterpret_cast<UInt8 *>(U32At(ACCEL(), 0x78))) {
        submit_context_buffer();
        U32At(ACCEL(), 0x744) += 1;
        U32At(ACCEL(), 0x78) = reinterpret_cast<UInt32>(this);
    }
    surface = boundSurface;
    if (surface != nullptr) {
        surface->increment_refcounts(U32At(self, 0x8c));
    }
    if (U32At(self, 0x9c) == 0) {
        map_transfer_to_GART(reinterpret_cast<VendorTransferBuffer *>(self + 0x98));
    }
    {
        IOReturn processed = process_command_buffer(&desc);
        if (U32At(self, 0x114) != 0) {
            U32At(reinterpret_cast<void *>(U32At(reinterpret_cast<void *>(U32At(self, 0x114)), 0x14)), 8) = U32At(ACCEL(), 0x50);
        }
        UInt32 stamp;
        if (desc.pendingDwordCount == 0) {
            stamp = U32At(ACCEL(), 0x50) - 1;
        } else {
            U32At(ACCEL(), 0x700) += desc.pendingDwordCount * 4;
            stamp = (*reinterpret_cast<SubmitFn *>(*reinterpret_cast<UInt8 **>(ACCEL()) + 0x560))(ACCEL(), &desc);
        }
        U32At(self, 0x7c) = stamp;
        U32At(self, 0xa8) = stamp;

        surface = boundSurface;
        if (surface == nullptr) {
            goto recordStamp;
        }
        surface->decrement_refcounts(U32At(self, 0x8c));
        surface = boundSurface;
        if (surface == nullptr) {
            goto recordStamp;
        }
        U32At(surface, 0x7c) = surface->update_ref_stamps(U32At(self, 0x7c), U32At(self, 0x8c));
        if (U8At(self, 0x92) != 0) {
            U32At(reinterpret_cast<void *>(U32At(reinterpret_cast<void *>(U32At(boundSurface, 0xb70)), 0x24)), 0x54) = U32At(boundSurface, 0x7c);
        }
        {
            /* move the surface to the head of the accelerator's circular live-surface list (prev +0x9c, next +0xa0) */
            UInt8 *s = reinterpret_cast<UInt8 *>(boundSurface);
            if (s != reinterpret_cast<UInt8 *>(U32At(ACCEL(), 0x5c))) {
                U32At(reinterpret_cast<void *>(U32At(s, 0x9c)), 0xa0) = U32At(s, 0xa0);
                U32At(reinterpret_cast<void *>(U32At(s, 0xa0)), 0x9c) = U32At(s, 0x9c);
                UInt8 *listHead = reinterpret_cast<UInt8 *>(U32At(ACCEL(), 0x5c));
                U32At(s, 0x9c) = reinterpret_cast<UInt32>(listHead);
                UInt8 *next = reinterpret_cast<UInt8 *>(U32At(listHead, 0xa0));
                U32At(s, 0xa0) = reinterpret_cast<UInt32>(next);
                U32At(listHead, 0xa0) = reinterpret_cast<UInt32>(s);
                U32At(next, 0x9c) = reinterpret_cast<UInt32>(s);
                U32At(ACCEL(), 0x5c) = reinterpret_cast<UInt32>(s);
            }
        }
        if (processed != 0 && (flags & 2) == 0) {
            UInt8 *s = reinterpret_cast<UInt8 *>(boundSurface);
            UInt32 oldStamp = U32At(s, 0x84);
            U32At(s, 0x84) = U32At(s, 0x80);
            accel = ACCEL();
            for (UInt32 i = 0, off = 0; i < U32At(accel, 0xcc); ++i, off += 0x94) {
                if (U8At(boundSurface, off + 0xcac) != 0) {
                    boundSurface->submit_swap_buffer(i, 0);
                    U32At(ACCEL(), 0x74c) += 1;
                    accel = ACCEL();
                }
            }
            UInt32 waited = U32At(accel, 0x794);
            SInt32 r = (*reinterpret_cast<StampFn *>(*reinterpret_cast<UInt8 **>(accel) + 0x558))(accel, oldStamp);
            U32At(accel, 0x794) = waited + r;
        }
        goto ring;
    recordStamp:
        U32At(ACCEL(), U32At(self, 0x110) * 0x20 + 0xec) = U32At(self, 0x7c);
    }

ring:
    {
        accel = ACCEL();
        UInt8 *entry = accel + U16At(accel, 0x5c4) * 0x1c + 0x404;
        if ((*reinterpret_cast<StampFn *>(*reinterpret_cast<UInt8 **>(accel) + 0x554))(accel, U32At(entry, 0x10)) == 0) {
            accel = ACCEL();
            bool waitForIt = true;
            if (U16At(accel, 0x5c6) < 8) {
                if (accelerator->allocMoreCommandBuffers(1, 0x1000)) {
                    accel = ACCEL();
                    entry = accel + U16At(accel, 0x5c4) * 0x1c + 0x404;
                    waitForIt = false;
                } else {
                    accel = ACCEL();
                }
            }
            if (waitForIt) {
                UInt32 waited = U32At(accel, 0x76c);
                SInt32 r = (*reinterpret_cast<StampFn *>(*reinterpret_cast<UInt8 **>(accel) + 0x54c))(accel, U32At(entry, 0x10));
                U32At(accel, 0x76c) = waited + r;
                accel = ACCEL();
            }
        } else {
            accel = ACCEL();
        }
        U16At(accel, 0x5c4) = (U16At(accel, 0x5c4) + 1) & (U16At(accel, 0x5c6) - 1);

        /* exchange this context's live command buffer (this+0x98 .. +0xb0, seven words) with the ring entry */
        for (int i = 0; i < 7; ++i) {
            UInt32 mine = U32At(self, 0x98 + i * 4);
            U32At(self, 0x98 + i * 4) = U32At(entry, i * 4);
            U32At(entry, i * 4) = mine;
        }

        accel = ACCEL();
        if (U8At(accel, 0x88) == 0) {
            void *scheduler = reinterpret_cast<void *>(U32At(accel, 0xc0));
            (*reinterpret_cast<NotifyFn *>(*reinterpret_cast<UInt8 **>(scheduler) + 0x12c))(scheduler, U32At(accel, 0x8c));
            U8At(ACCEL(), 0x88) = 1;
        } else {
            U8At(accel, 0x89) = 1;
        }
    }

finish:
    reinterpret_cast<OSObject *>(U32At(self, 0xa0))->retain();
    *options = 0;
    *memory = reinterpret_cast<IOMemoryDescriptor *>(U32At(self, 0xa0));
    init_command_buffer_header(reinterpret_cast<VendorCommandBufferHeader *>(U32At(self, 0xac)), U32At(self, 0xb0), flags);
    Ctx2DM_unlock(ACCEL_LOCK());
    return 0;
}
