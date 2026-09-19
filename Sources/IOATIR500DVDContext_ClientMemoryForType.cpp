/*
 * IOATIR500DVDContext_ClientMemoryForType.cpp
 *
 * RESOLVED (ledger pass): IOATIR500DVDContext::clientMemoryForType (real addr 0xf0c0, vtable +0x580), transcribed
 * from the shipped kext; every alloc_surfaces argument list was checked against the disassembly.
 *
 *   type 0: retain and hand out the accelerator's shared descriptor (accelerator+0xac).
 *   type 2: retain and hand out the context-buffer descriptor (this+0xb4), re-initialise its header.
 *   type 3: retain and hand out the accelerator's shared descriptor (accelerator+0xb0).
 *   type 1: the DVD "flush the current command buffer and hand the client a fresh one" path. Same skeleton as the
 *           2D and GL versions (revalidate the bound surface with alloc_surfaces retried up to 1000 times, submit
 *           the previous context's buffer if a different context last submitted, run process_command_buffer,
 *           submit through accelerator vtable +0x560, update the surface's stamps and the live-surface ring, swap
 *           in the next command buffer from the accelerator's 0x1c-byte-entry ring), plus DVD-specific work:
 *           every bound texture is added to and removed from the command stream around the parse, and the fresh
 *           command buffer is re-allocated at the accelerator's size hint (+0x5c8) when its size differs.
 *
 * Accelerator slots: +0x54c wait for stamp, +0x554 stamp passed?, +0x560 submit a VendorCommandDescriptor.
 * Surface slots: +0x5b4 update_ref_stamps, +0x5c0 build_swap. Own slots: +0x5b0 submit_context_buffer,
 * +0x5b4 process_command_buffer, +0x5b8 discard_command_buffer.
 */

#include "../Headers/IOATIR500DVDContext.h"
#include "../Headers/ATIRadeonX1000.h"
#include "../Headers/IOATIR500Surface.h"

extern "C" void DVDCmft_lock(void *) asm("_IOLockLock");
extern "C" void DVDCmft_unlock(void *) asm("_IOLockUnlock");
extern "C" void DVDCmft_sleep(void *lock, void *event, UInt32 interruptible) asm("_IOLockSleep");
extern "C" void DVDCmft_thread_block(UInt32 continuation) asm("_thread_block");
extern "C" void DVDCmft_IOSleep(UInt32 ms) asm("_IOSleep");

namespace {
inline UInt32 &U32At(void *base, int offset) { return *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt16 &U16At(void *base, int offset) { return *reinterpret_cast<UInt16 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt8  &U8At(void *base, int offset)  { return *(reinterpret_cast<UInt8 *>(base) + offset); }
typedef SInt32 (*StampFn)(void *, UInt32);
typedef UInt32 (*SubmitFn)(void *, VendorCommandDescriptor *);
} // namespace

#define ACCEL() reinterpret_cast<UInt8 *>(accelerator)
#define ACCEL_LOCK() (*reinterpret_cast<void **>(ACCEL() + 0x840))

IOReturn IOATIR500DVDContext::clientMemoryForType(UInt32 type, UInt32 *options, IOMemoryDescriptor **memory) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

    if (type != 1) {
        if (type == 0) {
            if (U32At(ACCEL(), 0xac) != 0) {
                reinterpret_cast<OSObject *>(U32At(ACCEL(), 0xac))->retain();
                *options = 0;
                *memory = reinterpret_cast<IOMemoryDescriptor *>(U32At(ACCEL(), 0xac));
                return 0;
            }
        } else {
            if (type == 2) {
                DVDCmft_lock(ACCEL_LOCK());
                reinterpret_cast<OSObject *>(U32At(self, 0xb4))->retain();
                *options = 0;
                *memory = reinterpret_cast<IOMemoryDescriptor *>(U32At(self, 0xb4));
                init_context_buffer_header(reinterpret_cast<VendorContextBufferHeader *>(U32At(self, 0xc0)), 0x1000);
                DVDCmft_unlock(ACCEL_LOCK());
                return 0;
            }
            if (type != 3) {
                return 0xe00002c2;
            }
            if (U32At(ACCEL(), 0xb0) != 0) {
                reinterpret_cast<OSObject *>(U32At(ACCEL(), 0xb0))->retain();
                *options = 0;
                *memory = reinterpret_cast<IOMemoryDescriptor *>(U32At(ACCEL(), 0xb0));
                return 0;
            }
        }
        return 0xe00002be;
    }

    UInt32 tries = 0;
    UInt32 flags = 0;
    IOATIR500Surface *surface;
    VendorCommandDescriptor desc;
    UInt8 *accel;

    for (;;) {
        DVDCmft_lock(ACCEL_LOCK());
        surface = reinterpret_cast<IOATIR500Surface *>(boundSurface);
        if (surface == nullptr) {
            goto noSurface;
        }
        if (U32At(surface, 0xa4) < 0x100) {
            accel = ACCEL();
        } else {
            accel = ACCEL();
            if (U8At(accel, 0x80) == 0) {
                do {
                    DVDCmft_sleep(reinterpret_cast<void *>(U32At(accel, 0x840)), accel, 0);
                } while (U8At(accel, 0x80) == 0);
                surface = reinterpret_cast<IOATIR500Surface *>(boundSurface);
                if (surface == nullptr) {
                    goto noSurface;
                }
            }
        }
        if (U8At(accel, 0x80) == 0) {
            goto noSurface;
        }
        if (U8At(surface, 0xbf6) != 0) {
            surface->retain();
            DVDCmft_unlock(ACCEL_LOCK());
            surface->sleep_blocked();
            surface->release();
            continue;
        }
        flags = U32At(surface, 0xbfc) | 2;
        if (U8At(surface, 0xbd0) == 0 || tries == 999) {
            UInt32 bits = U32At(surface, 0xbf8);
            UInt32 want = U32At(self, 0x88) | U32At(surface, 0xc1c);
            if ((want & bits) != 0) {
                if ((bits & 0x20000000) != 0) {
                    goto discard;
                }
                UInt32 mask = want & 0x7fffff;
                if ((bits & mask) != 0) {
                    UInt32 r = surface->alloc_surfaces(mask, false);
                    if (r != 0) {
                        if (r != 2) {
                            goto retry;
                        }
                        goto discard;
                    }
                    surface = reinterpret_cast<IOATIR500Surface *>(boundSurface);
                    if ((U32At(surface, 0xbf8) & U32At(surface, 0xc1c) & 0x10000000) == 0) {
                        goto evaluated;
                    }
                }
                surface->build_swap();
                U32At(boundSurface, 0xbf8) &= 0xefffffff;
            }
        evaluated:
            if (tries < 1000) {
                goto proceed;
            }
            if (tries < 0x3e9) {
                goto lastChance;
            }
            goto discard;
        }
    retry:
        if (tries == 1000) {
        lastChance:
            if (reinterpret_cast<IOATIR500Surface *>(boundSurface)->alloc_surfaces((U32At(self, 0x88) | U32At(boundSurface, 0xc1c)) & 0x7fffff, true) == 0) {
                if ((U32At(boundSurface, 0xbf8) & U32At(boundSurface, 0xc1c) & 0x10000000) != 0) {
                    reinterpret_cast<IOATIR500Surface *>(boundSurface)->build_swap();
                    U32At(boundSurface, 0xbf8) &= 0xefffffff;
                }
                goto proceed;
            }
            goto discard;
        }
        ++tries;
        DVDCmft_unlock(ACCEL_LOCK());
        DVDCmft_thread_block(0);
        DVDCmft_IOSleep(1);
    }

proceed:
    for (int i = 0; i < 0x12; ++i) {
        if (U32At(self, 0x104 + i * 4) != 0) {
            add_texture_to_stream(reinterpret_cast<VendorTextureBuffer *>(U32At(self, 0x104 + i * 4)));
        }
    }
    if (self != reinterpret_cast<UInt8 *>(U32At(ACCEL(), 0x78))) {
        submit_context_buffer();
        U32At(ACCEL(), 0x748) += 1;
        U32At(ACCEL(), 0x78) = reinterpret_cast<UInt32>(this);
    }
    if (U32At(self, 0x94) == 0) {
        map_transfer_to_GART(reinterpret_cast<VendorTransferBuffer *>(self + 0x90));
    }
    process_command_buffer(&desc);
    for (int i = 0; i < 0x12; ++i) {
        if (U32At(self, 0x104 + i * 4) != 0) {
            remove_texture_from_stream(reinterpret_cast<VendorTextureBuffer *>(U32At(self, 0x104 + i * 4)));
        }
    }
    {
        UInt32 stamp;
        if (desc.pendingDwordCount == 0) {
            stamp = U32At(ACCEL(), 0x50) - 1;
        } else {
            U32At(ACCEL(), 0x708) += desc.pendingDwordCount * 4;
            stamp = (*reinterpret_cast<SubmitFn *>(*reinterpret_cast<UInt8 **>(ACCEL()) + 0x560))(ACCEL(), &desc);
        }
        surface = reinterpret_cast<IOATIR500Surface *>(boundSurface);
        UInt32 refStamp = surface->update_ref_stamps(stamp, U32At(self, 0x88));
        U32At(surface, 0x7c) = refStamp;
        U32At(self, 0x7c) = refStamp;
        U32At(self, 0xa0) = refStamp;
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
    {
        accel = ACCEL();
        UInt8 *entry = accel + U16At(accel, 0x400) * 0x1c + 0x240;
        if (U32At(accel, 0x5c8) < 0x80000) {
            U32At(accel, 0x5c8) = 0x80000;
            accel = ACCEL();
        }
        if ((*reinterpret_cast<StampFn *>(*reinterpret_cast<UInt8 **>(accel) + 0x554))(accel, U32At(entry, 0x10)) == 0) {
            accel = ACCEL();
            bool waitForIt = true;
            if (U16At(accel, 0x402) < 0x10) {
                if (accelerator->allocMoreCommandBuffers(0, 0x80000)) {
                    accel = ACCEL();
                    entry = accel + U16At(accel, 0x400) * 0x1c + 0x240;
                    waitForIt = false;
                } else {
                    accel = ACCEL();
                }
            }
            if (waitForIt) {
                UInt32 waited = U32At(accel, 0x774);
                SInt32 r = (*reinterpret_cast<StampFn *>(*reinterpret_cast<UInt8 **>(accel) + 0x54c))(accel, U32At(entry, 0x10));
                U32At(accel, 0x774) = waited + r;
                accel = ACCEL();
            }
        } else {
            accel = ACCEL();
        }
        U16At(accel, 0x400) = (U16At(accel, 0x400) + 1) & (U16At(accel, 0x402) - 1);

        /* exchange this context's live command buffer (this+0x90 .. +0xa8, seven words) with the ring entry */
        for (int i = 0; i < 7; ++i) {
            UInt32 mine = U32At(self, 0x90 + i * 4);
            U32At(self, 0x90 + i * 4) = U32At(entry, i * 4);
            U32At(entry, i * 4) = mine;
        }

        accel = ACCEL();
        if (U32At(self, 0xa8) != U32At(accel, 0x5c8)) {
            UInt32 fresh[7] = { 0, 0, 0, 0x10000, 0, 0, 0 };
            if (accelerator->allocCommandBuffer(reinterpret_cast<VendorCommandBuffer *>(fresh), U32At(accel, 0x5c8))) {
                accelerator->freeCommandBuffer(reinterpret_cast<VendorCommandBuffer *>(self + 0x90));
                for (int i = 0; i < 7; ++i) {
                    U32At(self, 0x90 + i * 4) = fresh[i];
                }
            }
        }
    }
    goto handOut;

noSurface:
    flags = 0;
discard:
    discard_command_buffer();
    U32At(ACCEL(), 0x78) = 0;
handOut:
    reinterpret_cast<OSObject *>(U32At(self, 0x98))->retain();
    *options = 0;
    *memory = reinterpret_cast<IOMemoryDescriptor *>(U32At(self, 0x98));
    init_command_buffer_header(reinterpret_cast<VendorCommandBufferHeader *>(U32At(self, 0xa4)), U32At(self, 0xa8), flags);
    DVDCmft_unlock(ACCEL_LOCK());
    return 0;
}
