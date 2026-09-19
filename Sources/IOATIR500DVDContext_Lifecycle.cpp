/*
 * IOATIR500DVDContext_Lifecycle.cpp
 *
 * RESOLVED (ledger pass): the lifecycle members of IOATIR500DVDContext (the DVD/video user-client base class) that
 * had no body in the rebuild, transcribed from the shipped kext (real addrs in parentheses):
 *   start (0xec60, vtable +0x348)   stop (0xe3a0, +0x34c)   clientClose (0xe6d0, +0x568)
 *   setCompatibleSurfaceMode (0xe970, +0x5ac): returns 1   init_command_buffer_header (0xe780)
 *   remove_surface (0xe810)   lock_all_buffers (0xfd00, table selector 4)
 *
 * Field offsets (this): +0x7c stamp, +0x80 next context in the accelerator's DVD list, +0x84 shared allocator,
 * +0x88 required-bits word, +0x8c accelerator, +0x90..+0xa8 the live VendorCommandBuffer (+0x98 = its descriptor),
 * +0xb4 context-buffer descriptor, +0xc0 context-buffer header, +0xc4.. two 0x18-byte transfer-buffer slots,
 * +0xf4 current slot, +0xf8 bound surface, +0xfc "started" flag, +0x100 method table, +0x104..+0x148 eighteen
 * texture pointers (bound-texture slots, reference-counted through OSDecrementAtomic/OSAddAtomic at texture+0x14+0x10).
 * Accelerator: +0x60 head of the live GL-context list, +0x68 head of the live DVD-context list, +0x73c open-DVD
 * count, +0x5c8 command-buffer size hint, +0x78 last submitting context, vtable +0x530 setup3D(), +0x538 teardown3D().
 */

#include "../Headers/IOATIR500DVDContext.h"
#include "../Headers/ATIRadeonX1000.h"
#include "../Headers/IOATIR500Surface.h"
#include "../Headers/IOATIR500Shared.h"

extern const VendorExternalMethod kDVDBaseMethods[10];

extern "C" void DVDLife_lock(void *) asm("_IOLockLock");
extern "C" void DVDLife_unlock(void *) asm("_IOLockUnlock");
extern "C" void DVDLife_thread_block(UInt32 continuation) asm("_thread_block");
extern "C" void DVDLife_IOSleep(UInt32 ms) asm("_IOSleep");
extern "C" SInt32 DVDLife_OSDecrementAtomic(volatile SInt32 *address) asm("_OSDecrementAtomic");

/* the 128-byte output of lock_all_buffers: thirteen {address, pitch} pairs (the table declares 256 bytes; only
 * the first 0x68 are ever written) */
struct sIODVDContextLockBufferData {
    UInt32 buffer[13][2];
    UInt8  _unwritten[256 - 13 * 8];
};

namespace {
inline UInt32 &U32At(void *base, int offset) { return *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt16 &U16At(void *base, int offset) { return *reinterpret_cast<UInt16 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt8  &U8At(void *base, int offset)  { return *(reinterpret_cast<UInt8 *>(base) + offset); }
typedef void (*AccelTeardownFn)(void *);
} // namespace

bool IOATIR500DVDContext::start(IOService *provider) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    if (!IOUserClient::start(provider)) {
        return false;
    }
    U32At(self, 0xc0) = 0;
    accelerator = reinterpret_cast<ATIRadeonX1000 *>(provider);
    U32At(self, 0xfc) = 0;
    U32At(self, 0x7c) = 0;
    U32At(self, 0xf8) = 0;
    U32At(self, 0x84) = 0;
    U32At(self, 0x90) = 0;
    U32At(self, 0x94) = 0;
    U32At(self, 0x98) = 0;
    U16At(self, 0x9e) = 0;
    U32At(self, 0xa0) = 0;
    U32At(self, 0xa4) = 0;
    U32At(self, 0xa8) = 0;
    U32At(self, 0xf4) = 0;
    U32At(self, 0xac) = 0;
    U32At(self, 0xb0) = 0;
    U32At(self, 0xb4) = 0;
    U16At(self, 0xba) = 0;
    U16At(self, 0xb8) = 0;
    U32At(self, 0xbc) = 0;
    U16At(self, 0x9c) = 1;
    for (int i = 0; i < 2; ++i) {
        UInt8 *slot = self + i * 0x18;
        U32At(slot, 0xc4) = 0;
        U32At(slot, 0xc8) = 0;
        U32At(slot, 0xcc) = 0;
        U16At(slot, 0xd2) = 0;
        U16At(slot, 0xd0) = 0;
        U32At(slot, 0xd4) = 0;
        U32At(slot, 0xd8) = 0;
    }
    U32At(self, 0x88) = 0x20000402;
    for (int i = 0; i < 0x12; ++i) {
        U32At(self, 0x104 + i * 4) = 0;
    }

    UInt8 *accel = reinterpret_cast<UInt8 *>(U32At(self, 0x8c));
    if (U32At(accel, 0x68) == 0 && U32At(accel, 0x60) == 0) {
        if (accelerator->setup3D() == 0) {
            IOATIR500DVDContext::stop(provider);
            return false;
        }
        accel = reinterpret_cast<UInt8 *>(U32At(self, 0x8c));
    }
    U32At(self, 0x80) = U32At(accel, 0x68);
    U32At(accel, 0x68) = reinterpret_cast<UInt32>(this);
    U32At(reinterpret_cast<void *>(U32At(self, 0x8c)), 0x73c) += 1;
    if (accelerator->getVRAMDescriptors() &&
        accelerator->allocCommandBuffer(reinterpret_cast<VendorCommandBuffer *>(self + 0x90), 0x80000) &&
        allocAllContextBuffers(0x1000)) {
        U32At(self, 0xfc) = 1;
        U32At(self, 0x100) = reinterpret_cast<UInt32>(kDVDBaseMethods);
        return true;
    }
    IOATIR500DVDContext::stop(provider);
    return false;
}

void IOATIR500DVDContext::stop(IOService *provider) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    U32At(self, 0xfc) = 0;

    /* unlink from the accelerator's list of live DVD contexts (head at accelerator+0x68) */
    UInt8 *accel = reinterpret_cast<UInt8 *>(U32At(self, 0x8c));
    UInt8 *head = reinterpret_cast<UInt8 *>(U32At(accel, 0x68));
    if (self == head) {
        U32At(accel, 0x68) = U32At(self, 0x80);
        accel = reinterpret_cast<UInt8 *>(U32At(self, 0x8c));
        if (U32At(accel, 0x68) == 0 && U32At(accel, 0x60) == 0) {
            AccelTeardownFn teardown3D = *reinterpret_cast<AccelTeardownFn *>(*reinterpret_cast<UInt8 **>(accel) + 0x538);
            teardown3D(accel);
            accel = reinterpret_cast<UInt8 *>(U32At(self, 0x8c));
        }
    } else {
        UInt8 *prev;
        do {
            prev = head;
            head = reinterpret_cast<UInt8 *>(U32At(prev, 0x80));
            if (head == nullptr) {
                break;
            }
        } while (self != head);
        U32At(prev, 0x80) = U32At(self, 0x80);
    }
    U32At(accel, 0x73c) -= 1;
    U32At(reinterpret_cast<void *>(U32At(self, 0x8c)), 0x5c8) = 0x20000;

    /* drop every live GL and DVD context's client mapping of this context's command-buffer descriptor */
    if (U32At(self, 0x98) != 0) {
        accel = reinterpret_cast<UInt8 *>(U32At(self, 0x8c));
        UInt8 *ctx = reinterpret_cast<UInt8 *>(U32At(accel, 0x60));
        bool anyLists = true;
        if (ctx == nullptr) {
            anyLists = U32At(accel, 0x68) != 0;
        } else {
            for (;;) {
                if (U32At(accel, 0x5c8) < U32At(ctx, 0xb0)) {
                    U32At(accel, 0x5c8) = U32At(ctx, 0xb0);
                }
                IOMemoryMap *map = reinterpret_cast<IOATIR500DVDContext *>(ctx)->removeMappingForDescriptor(
                    reinterpret_cast<IOMemoryDescriptor *>(U32At(self, 0x98)));
                if (map != nullptr) {
                    map->release();
                }
                ctx = reinterpret_cast<UInt8 *>(U32At(ctx, 0x80));
                if (ctx == nullptr) {
                    break;
                }
                accel = reinterpret_cast<UInt8 *>(U32At(self, 0x8c));
            }
            accel = reinterpret_cast<UInt8 *>(U32At(self, 0x8c));
        }
        if (anyLists) {
            ctx = reinterpret_cast<UInt8 *>(U32At(accel, 0x68));
            if (ctx != nullptr) {
                for (;;) {
                    if (U32At(accel, 0x5c8) < 0x80000) {
                        U32At(accel, 0x5c8) = 0x80000;
                    }
                    IOMemoryMap *map = reinterpret_cast<IOATIR500DVDContext *>(ctx)->removeMappingForDescriptor(
                        reinterpret_cast<IOMemoryDescriptor *>(U32At(self, 0x98)));
                    if (map != nullptr) {
                        map->release();
                    }
                    ctx = reinterpret_cast<UInt8 *>(U32At(ctx, 0x80));
                    if (ctx == nullptr) {
                        break;
                    }
                    accel = reinterpret_cast<UInt8 *>(U32At(self, 0x8c));
                }
            }
        }
    }

    if (U32At(self, 0xb4) != 0) {
        freeAllContextBuffers();
    }
    if (U32At(self, 0x98) != 0) {
        accelerator->freeCommandBuffer(reinterpret_cast<VendorCommandBuffer *>(self + 0x90));
    }
    accel = reinterpret_cast<UInt8 *>(U32At(self, 0x8c));
    if (self == reinterpret_cast<UInt8 *>(U32At(accel, 0x78))) {
        U32At(accel, 0x78) = 0;
    }
    if (boundSurface != nullptr) {
        reinterpret_cast<IOATIR500Surface *>(boundSurface)->remove_dvd_context(this);
        reinterpret_cast<IOATIR500Surface *>(boundSurface)->prune_buffers();
        boundSurface = nullptr;
    }
    if (U32At(self, 0x84) != 0) {
        for (int i = 0; i < 0x12; ++i) {
            UInt8 *texture = reinterpret_cast<UInt8 *>(U32At(self, 0x104 + i * 4));
            if (texture != nullptr) {
                if (DVDLife_OSDecrementAtomic(reinterpret_cast<volatile SInt32 *>(U32At(texture, 0x14) + 0x10)) == 1) {
                    sharedAllocator->delete_texture(reinterpret_cast<VendorTextureBuffer *>(texture));
                }
                U32At(self, 0x104 + i * 4) = 0;
            }
        }
        reinterpret_cast<OSObject *>(U32At(self, 0x84))->release();
        U32At(self, 0x84) = 0;
    }
    IOUserClient::stop(provider);
}

/* Real: only if the started flag is set, stop() then detach() from the accelerator (vtable +0x34c / +0x3a8). */
IOReturn IOATIR500DVDContext::clientClose() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    if (U32At(self, 0xfc) != 0) {
        IOService *provider = reinterpret_cast<IOService *>(U32At(self, 0x8c));
        this->stop(provider);
        this->detach(provider);
    }
    return 0;
}

void IOATIR500DVDContext::init_command_buffer_header(VendorCommandBufferHeader *header, UInt32 size, UInt32 flags) {
    UInt8 *h = reinterpret_cast<UInt8 *>(header);
    for (int i = 0; i < 8; ++i) {
        U32At(h, i * 4) = 0;
    }
    U32At(h, 0x14) = flags;
    U32At(h, 0x20) = 0x1000000;
    U32At(h, 0x10) = (size - 0x20) >> 2;
    U32At(h, 0x1c) = 1;
    U32At(h, 0x18) = U32At(this, 0x7c);
}

void IOATIR500DVDContext::remove_surface() {
    U32At(this, 0xf8) = 0;
}

bool IOATIR500DVDContext::setCompatibleSurfaceMode(SInt32 *modeBits, eIODVDContextModeBits requested) {
    (void)modeBits;
    (void)requested;
    return true;
}

/* Real: up to 1000 attempts of alloc_surfaces(mask, false) (thread_block(0) + IOSleep(1) between them) then one
 * alloc_surfaces(mask, true), with mask = this+0x88 & 0x207ffc00; on success copies the {address, pitch} pair of
 * bound-surface buffers 10..22 out and bumps the surface's lock count (u16 at +0xbd2). On every failure path the
 * thirteen pairs are zeroed and kIOReturnNoMemory-family 0xe00002cc is returned. */
IOReturn IOATIR500DVDContext::lock_all_buffers(UInt32 param1, sIODVDContextLockBufferData *out) {
    (void)param1;
    UInt32 tries = 0;
    IOATIR500Surface *surface;
    IOReturn result;
    for (;;) {
        DVDLife_lock(*reinterpret_cast<void **>(reinterpret_cast<UInt8 *>(accelerator) + 0x840));
        surface = reinterpret_cast<IOATIR500Surface *>(boundSurface);
        if (surface == nullptr) {
            goto failed;
        }
        {
            UInt32 mask = U32At(this, 0x88) & 0x207ffc00;
            if ((U32At(surface, 0xbf8) & mask) == 0) {
                break;
            }
            if ((U32At(surface, 0xbf8) & 0x20000000) != 0) {
                goto failed;
            }
            UInt32 r = surface->alloc_surfaces(mask, false);
            if (r == 0) {
                surface = reinterpret_cast<IOATIR500Surface *>(boundSurface);
                break;
            }
            if (r == 2) {
                goto failed;
            }
            if (tries == 1000) {
                if (reinterpret_cast<IOATIR500Surface *>(boundSurface)->alloc_surfaces(mask, true) == 0) {
                    surface = reinterpret_cast<IOATIR500Surface *>(boundSurface);
                    break;
                }
                goto failed;
            }
        }
        ++tries;
        DVDLife_unlock(*reinterpret_cast<void **>(reinterpret_cast<UInt8 *>(accelerator) + 0x840));
        DVDLife_thread_block(0);
        DVDLife_IOSleep(1);
    }
    for (int i = 0; i < 13; ++i) {
        UInt8 *buffer = reinterpret_cast<UInt8 *>(U32At(surface, 0xb70 + (10 + i) * 4));
        out->buffer[i][0] = U32At(buffer, 8);
        out->buffer[i][1] = U16At(buffer, 0x18);
        surface = reinterpret_cast<IOATIR500Surface *>(boundSurface);
    }
    result = 0;
    U16At(boundSurface, 0xbd2) = U16At(boundSurface, 0xbd2) + 1;
    goto out;
failed:
    for (int i = 0; i < 13; ++i) {
        out->buffer[i][1] = 0;
        out->buffer[i][0] = 0;
    }
    result = 0xe00002cc;
out:
    DVDLife_unlock(*reinterpret_cast<void **>(reinterpret_cast<UInt8 *>(accelerator) + 0x840));
    return result;
}
