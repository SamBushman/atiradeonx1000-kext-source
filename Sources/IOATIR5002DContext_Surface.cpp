/*
 * IOATIR5002DContext_Surface.cpp
 *
 * RESOLVED (ledger pass): the surface/memory members of the 2D external-method table that had no body in the
 * rebuild, transcribed from the shipped kext (real addrs in parentheses):
 *   set_surface (0xc570)  get_surface_info (0xc850)  swap_surface (0xc960)  lock_memory (0xcc80)
 *   unlock_memory (0xcf30)  create_transfer (0xd260)  set_macrovision (0xc2e0)
 *
 * The retry loops (up to 1000 attempts of alloc_surfaces(1, false), then one alloc_surfaces(1, true), with
 * `thread_block(0); IOSleep(1)` between attempts) were checked against the disassembly: the stock decompile drops
 * the third argument of IOATIR500Surface::alloc_surfaces(mask, retry).
 *
 * Bound surface fields used: +0x7c stamp, +0xa4 pending-count, +0xa8 buffer record, +0xb70 buffer pointer,
 * +0xbd2 lock count (u16), +0xbe8 mode bits, +0xbf4 has-memory flag, +0xbf8/+0xc1c state / required bits,
 * +0xbfc state, +0xc00 backing IOMemoryDescriptor. Accelerator: +0x80 active flag, +0x840 command lock,
 * +0xcc/+0xd0 display count / mask, +0xd4+i*0x20 per-display framebuffer.
 */

#include "../Headers/IOATIR5002DContext.h"
#include "../Headers/ATIRadeonX1000.h"
#include "../Headers/IOATIR500Surface.h"
#include "../Headers/IOATIR500Shared.h"

extern "C" void Ctx2DS_lock(void *) asm("_IOLockLock");
extern "C" void Ctx2DS_unlock(void *) asm("_IOLockUnlock");
extern "C" void Ctx2DS_sleep(void *lock, void *event, UInt32 interruptible) asm("_IOLockSleep");
extern "C" void Ctx2DS_thread_block(UInt32 continuation) asm("_thread_block");
extern "C" void Ctx2DS_IOSleep(UInt32 ms) asm("_IOSleep");
extern "C" void *Ctx2DS_safeMetaCast(void *obj, void *metaClass) asm("__ZN15OSMetaClassBase12safeMetaCastEPKS_PK11OSMetaClass");
/* Site 0xc334 is a `lis/lwz` VALUE load of IONDRVFramebuffer::metaClass (Ghidra mislabels it `_ASICSupportsAGP`). */
extern "C" void *Ctx2DS_IONDRVFramebuffer_metaClass asm("__ZN17IONDRVFramebuffer9metaClassE");

namespace {
inline UInt32 &U32At(void *base, int offset) { return *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt16 &U16At(void *base, int offset) { return *reinterpret_cast<UInt16 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt8  &U8At(void *base, int offset)  { return *(reinterpret_cast<UInt8 *>(base) + offset); }
typedef void *(*MapFn)(void *, void *task, UInt32 address, UInt32 options, UInt32 offset, UInt32 length);
typedef UInt32 (*GetVAFn)(void *);
typedef IOReturn (*SetAttrFn)(void *, UInt32, UInt32 *);
} // namespace

#define ACCEL_LOCK() (*reinterpret_cast<void **>(reinterpret_cast<UInt8 *>(accelerator) + 0x840))

IOReturn IOATIR5002DContext::set_surface(UInt32 surfaceID, eIOContextModeBits modeBits, void *info, UInt32 *infoSize) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt32 mode = static_cast<UInt32>(modeBits);
    Ctx2DS_lock(ACCEL_LOCK());
    IOReturn result;
    UInt8 *accel;
    if ((mode & 0x800) == 0) {
        if (boundSurface != nullptr) {
            boundSurface->remove_2d_context_from_list(this);
            boundSurface->prune_buffers();
            boundSurface = nullptr;
        }
        accel = reinterpret_cast<UInt8 *>(accelerator);
        if (surfaceID < U32At(accel, 0xcc)) {
            result = 0;
            if (((1u << (surfaceID & 0x3f)) & U32At(accel, 0xd0)) == 0) {
                U32At(self, 0x110) = 0;
            } else {
                U32At(self, 0x110) = surfaceID;
            }
        } else {
            U32At(self, 0x110) = 0;
            result = 0xe00002c2;
        }
        U32At(self, 0x8c) = 0x20000000;
    } else {
        IOATIR500Surface *surface;
        bool noSurface;
        if (surfaceID == 0) {
            result = 0;
            surface = nullptr;
            noSurface = true;
        } else {
            surface = reinterpret_cast<IOATIR500Surface *>(accelerator->find_surface_for_id(surfaceID));
            noSurface = surface == nullptr;
            result = noSurface ? 0xe00002c2 : 0;
        }
        if (boundSurface != nullptr) {
            boundSurface->remove_2d_context_from_list(this);
            if (surface != boundSurface) {
                boundSurface->prune_buffers();
            }
        }
        if (noSurface) {
            accel = reinterpret_cast<UInt8 *>(accelerator);
            U32At(self, 0x100) = reinterpret_cast<UInt32>(surface);
            U32At(self, 0x110) = reinterpret_cast<UInt32>(surface);
        } else {
            UInt32 oldBits = U32At(surface, 0xbe8);
            U32At(self, 0x110) = 0xffff;
            if (surface != boundSurface) {
                surface->reset_req_bits();
            }
            U32At(surface, 0xbe8) = (oldBits & 0x803f) | (mode & 0xffff803f);
            U32At(self, 0x8c) = 0x20000001;
            if (((mode >> 10) & 1) != 0) {
                U32At(self, 0x8c) = 0x20000003;
            }
            if ((mode & 0x4000) != 0) {
                U32At(self, 0x8c) |= 0x7ffc00;
            }
            surface->add_2d_context_to_list(this);
            boundSurface = surface;
            surface->prune_buffers();
            accel = reinterpret_cast<UInt8 *>(accelerator);
        }
    }
    if (self == reinterpret_cast<UInt8 *>(U32At(accel, 0x78))) {
        U32At(accel, 0x78) = 0;
    }
    U8At(self, 0x92) = 0;
    invalidate();
    if (result == 0) {
        result = set_destination(info, infoSize);
    }
    Ctx2DS_unlock(ACCEL_LOCK());
    return result;
}

IOReturn IOATIR5002DContext::get_surface_info(UInt32 surfaceID, eIOContextModeBits modeBits, void *info, UInt32 *infoSize) {
    UInt32 mode = static_cast<UInt32>(modeBits);
    Ctx2DS_lock(ACCEL_LOCK());
    IOATIR500Surface *surface = nullptr;
    IOReturn result;
    if ((mode & 0x800) == 0) {
        if (U32At(accelerator, 0xcc) <= surfaceID) {
            result = 0xe00002c2;
            goto out;
        }
    } else {
        surface = reinterpret_cast<IOATIR500Surface *>(accelerator->find_surface_for_id(surfaceID));
        if (surface == nullptr) {
            result = 0xe00002f0;
            goto out;
        }
    }
    result = get_buffer_info(surface, surfaceID, info, infoSize);
out:
    Ctx2DS_unlock(ACCEL_LOCK());
    return result;
}

IOReturn IOATIR5002DContext::swap_surface(UInt32 lockType, UInt32 *outTag) {
    (void)lockType;
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt32 tries = 0;
    IOReturn result;
    IOATIR500Surface *surface;
    for (;;) {
        Ctx2DS_lock(ACCEL_LOCK());
        surface = boundSurface;
        if (surface == nullptr) {
            goto fail;
        }
        if (U32At(surface, 0xa4) > 0xff) {
            UInt8 *accel = reinterpret_cast<UInt8 *>(accelerator);
            if (U8At(accel, 0x80) == 0) {
                do {
                    Ctx2DS_sleep(reinterpret_cast<void *>(U32At(accel, 0x840)), accel, 0);
                } while (U8At(accel, 0x80) == 0);
                surface = boundSurface;
                if (surface == nullptr) {
                    goto fail;
                }
            }
        }
        if (U8At(accelerator, 0x80) == 0) {
            goto fail;
        }
        if ((((U32At(self, 0x8c) | U32At(surface, 0xc1c)) & 0x20000001) & U32At(surface, 0xbf8)) == 0) {
            break;
        }
        if ((U32At(surface, 0xbf8) & 0x20000000) != 0) {
            goto fail;
        }
        {
            UInt32 r = surface->alloc_surfaces(1, false);
            if (r == 0) {
                surface = boundSurface;
                break;
            }
            if (r == 2) {
                goto fail;
            }
        }
        if (tries == 1000) {
            if (boundSurface->alloc_surfaces(1, true) == 0) {
                surface = boundSurface;
                break;
            }
            *outTag = 0;
            result = 0xe00002be;
            goto out;
        }
        ++tries;
        Ctx2DS_unlock(ACCEL_LOCK());
        Ctx2DS_thread_block(0);
        Ctx2DS_IOSleep(1);
    }
    if ((U32At(surface, 0xbfc) & 2) == 0) {
        surface->flush_surface(0xffffffff, 0);
        surface = boundSurface;
    }
    result = 0;
    *outTag = U32At(surface, 0xbfc);
    goto out;
fail:
    result = 0xe00002be;
    *outTag = 0;
out:
    Ctx2DS_unlock(ACCEL_LOCK());
    return result;
}

IOReturn IOATIR5002DContext::lock_memory(UInt32 lockType, unsigned int *outAddress, UInt32 *outSize) {
    (void)lockType;
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt32 tries = 0;
    UInt32 range[9];
    IOATIR500Surface *surface;
    IOReturn result;
    for (;;) {
        Ctx2DS_lock(ACCEL_LOCK());
        surface = boundSurface;
        if (surface == nullptr) {
            goto noSurface;
        }
        if ((((U32At(self, 0x8c) | U32At(surface, 0xc1c)) & 0x20000001) & U32At(surface, 0xbf8)) == 0) {
            break;
        }
        if ((U32At(surface, 0xbf8) & 0x20000000) != 0) {
            goto noSurface;
        }
        {
            UInt32 r = surface->alloc_surfaces(1, false);
            if (r == 0) {
                surface = boundSurface;
                break;
            }
            if (r == 2) {
                goto noSurface;
            }
        }
        if (tries == 1000) {
            if (boundSurface->alloc_surfaces(1, true) == 0) {
                surface = boundSurface;
                break;
            }
            goto noSurface;
        }
        ++tries;
        Ctx2DS_unlock(ACCEL_LOCK());
        Ctx2DS_thread_block(0);
        Ctx2DS_IOSleep(1);
    }
    if (U8At(surface, 0xbf4) == 0) {
        if (U32At(self, 0x118) != 0) {
            reinterpret_cast<OSObject *>(U32At(self, 0x118))->release();
            U32At(self, 0x11c) = 0;
            U32At(self, 0x118) = 0;
        }
        goto noSurface;
    }
    {
        bool needMap = false;
        if (U32At(self, 0x118) == 0) {
            needMap = true;
        } else if (U32At(self, 0x104) != U32At(surface, 0xc00)) {
            reinterpret_cast<OSObject *>(U32At(self, 0x118))->release();
            surface = boundSurface;
            U32At(self, 0x118) = 0;
            needMap = true;
        }
        if (needMap) {
            void *descriptor = reinterpret_cast<void *>(U32At(surface, 0xc00));
            U32At(self, 0x104) = reinterpret_cast<UInt32>(descriptor);
            /* real: IOMemoryDescriptor vtable +0x14c map(task = this+0x78, address 0, options kIOMapAnywhere, 0, 0) */
            void *map = (*reinterpret_cast<MapFn *>(*reinterpret_cast<UInt8 **>(descriptor) + 0x14c))(
                descriptor, reinterpret_cast<void *>(U32At(self, 0x78)), 0, 1, 0, 0);
            U32At(self, 0x118) = reinterpret_cast<UInt32>(map);
            if (map == nullptr) {
                U32At(self, 0x11c) = 0;
                result = 0xe00002c8;
                *outAddress = 0xdeadbeef;
                goto out;
            }
            /* real: IOMemoryMap vtable +0xd0 getVirtualAddress() */
            U32At(self, 0x11c) = (*reinterpret_cast<GetVAFn *>(*reinterpret_cast<UInt8 **>(map) + 0xd0))(map);
            surface = boundSurface;
        }
    }
    result = 0;
    surface->surface_write_lock_int(0, range, outSize);
    U16At(boundSurface, 0xbd2) = U16At(boundSurface, 0xbd2) + 1;
    *outAddress = U32At(self, 0x11c) + range[0];
    goto out;
noSurface:
    result = 0xe00002cc;
    *outAddress = 0xdeadbeef;
out:
    Ctx2DS_unlock(ACCEL_LOCK());
    return result;
}

IOReturn IOATIR5002DContext::unlock_memory(UInt32 lockType, UInt32 *outTag) {
    IOReturn result;
    Ctx2DS_lock(ACCEL_LOCK());
    if (boundSurface == nullptr) {
        result = 0xe00002c2;
    } else {
        result = 0;
        boundSurface->surface_write_unlock_int(0);
        U16At(boundSurface, 0xbd2) = U16At(boundSurface, 0xbd2) - 1;
    }
    Ctx2DS_unlock(ACCEL_LOCK());
    if (result == 0 && static_cast<SInt32>(lockType) < 0) {
        return swap_surface(lockType, outTag);
    }
    *outTag = 0;
    return result;
}

IOReturn IOATIR5002DContext::create_transfer(UInt32 param1, UInt32 sizeInBytes, unsigned int *outHandle, unsigned int *outAddress) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    if (sizeInBytes == 0) {
        return 0xe00002c2;
    }
    Ctx2DS_lock(ACCEL_LOCK());
    if (sharedAllocator == nullptr) {
        if (!create_shared()) {
            Ctx2DS_unlock(ACCEL_LOCK());
            return 0xe00002be;
        }
    }
    UInt8 *texture = reinterpret_cast<UInt8 *>(sharedAllocator->new_agp_texture(0, sizeInBytes, outAddress));
    if (texture == nullptr) {
        Ctx2DS_unlock(ACCEL_LOCK());
        return 0xe00002bd;
    }
    *outHandle = U32At(texture, 0x58);
    U8At(self, 0x92) = 0;
    if (boundSurface != nullptr && ((param1 ^ U32At(boundSurface, 0xbe8)) & 0xf) == 0) {
        UInt8 *buffer = reinterpret_cast<UInt8 *>(U32At(boundSurface, 0xb70));
        if (U32At(buffer, 0x24) != 0) {
            U8At(reinterpret_cast<void *>(U32At(buffer, 0x24)), 0x59) = 0;
            boundSurface->free_buffer_backing_store(reinterpret_cast<ATIR500SurfaceBuffer *>(buffer));
        }
        IOMemoryDescriptor *memory = reinterpret_cast<IOMemoryDescriptor *>(U32At(texture, 8));
        memory->retain();
        boundSurface->attach_buffer_backing_store(reinterpret_cast<ATIR500SurfaceBuffer *>(buffer), memory, 0,
                                                  (static_cast<UInt32>(U16At(buffer, 0x1c)) * U16At(buffer, 0x16) + 0x7f) & 0xffffff80);
        U8At(reinterpret_cast<void *>(U32At(buffer, 0x24)), 0x59) = 1;
        U8At(self, 0x92) = 1;
    }
    Ctx2DS_unlock(ACCEL_LOCK());
    return 0;
}

/* Real: with the display up and at least one display, casts each display entry to IONDRVFramebuffer and calls its
 * vtable +0x70c as (obj, 0x92, &enable); succeeds (0) if any display accepted it, else kIOReturnNoDevice-family. */
IOReturn IOATIR5002DContext::set_macrovision(UInt32 enable) {
    UInt8 *accel = reinterpret_cast<UInt8 *>(accelerator);
    Ctx2DS_lock(ACCEL_LOCK());
    IOReturn result;
    if (U8At(accel, 0x80) == 0 || U32At(accel, 0xcc) == 0) {
        result = 0xe00002c0;
    } else {
        result = 0xe00002c0;
        UInt32 index = 0;
        do {
            void *display = Ctx2DS_safeMetaCast(reinterpret_cast<void *>(U32At(accel, index * 0x20 + 0xd4)),
                                                Ctx2DS_IONDRVFramebuffer_metaClass);
            if (display != nullptr) {
                SetAttrFn setAttribute = *reinterpret_cast<SetAttrFn *>(*reinterpret_cast<UInt8 **>(display) + 0x70c);
                if (setAttribute(display, 0x92, &enable) == 0) {
                    result = 0;
                }
            }
            accel = reinterpret_cast<UInt8 *>(accelerator);
            ++index;
        } while (index < U32At(accel, 0xcc));
    }
    Ctx2DS_unlock(reinterpret_cast<void *>(U32At(accel, 0x840)));
    return result;
}
