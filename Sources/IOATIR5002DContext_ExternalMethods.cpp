/*
 * IOATIR5002DContext_ExternalMethods.cpp
 *
 * RESOLVED (issue #59 / #42): real bodies for the self-contained members of the 2D context's
 * external-method table (real addrs in parentheses), transcribed from the shipped kext's own
 * decompile:
 *   get_config (0xbd90)  finish (0xbdc0)  scale_surface (0xcb90)  declare_image (0xd020)
 *   create_image (0xd130)  delete_image (0xd450)  wait_image (0xd5c0)  create_shared (0xbc90)
 *   set_surface_paging_options (0xc2c0)  set_surface_vsync_options (0xc2d0)
 *
 * The remaining members of the table (set_surface, get_surface_info, swap_surface, lock_memory, unlock_memory,
 * create_transfer, set_macrovision) are in IOATIR5002DContext_Surface.cpp; the table itself is in
 * IOATIR5002DContext_MethodTables.cpp.
 *
 * Field offsets used: this+0x7c (current stamp tag), +0x88 (shared allocator), +0x94 (accelerator),
 * +0x100 (bound surface), +0x114 (last bound texture); accelerator+0x80 (hardware up), +0x840
 * (command lock), +0x98/+0x9c (config words), +0x75c/+0x7a0/+0x7a4 (wait-time accumulators).
 * The lock is IOLockLock/IOLockUnlock (kxld binds them to mutex_lock/mutex_unlock_rwcmb).
 *
 * Confidence: CONFIRMED for control flow and every offset - short, complete decompiles.
 */

#include "../Headers/IOATIR5002DContext.h"
#include "../Headers/ATIRadeonX1000.h"
#include "../Headers/IOATIR500Surface.h"
#include "../Headers/IOATIR500Shared.h"

extern "C" void Ctx2D_lock(void *) asm("_IOLockLock");
extern "C" void Ctx2D_unlock(void *) asm("_IOLockUnlock");

namespace {
inline UInt32 &U32At(void *base, int offset) { return *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt8  &U8At(void *base, int offset)  { return *(reinterpret_cast<UInt8 *>(base) + offset); }
typedef SInt32 (*WaitFn)(void *, UInt32);
inline SInt32 CallAccelWait(void *accel, int slotOffset, UInt32 tag) {
    void **vtable = *reinterpret_cast<void ***>(accel);
    return (*reinterpret_cast<WaitFn *>(vtable + (slotOffset / 4)))(accel, tag);
}
} // namespace

IOReturn IOATIR5002DContext::get_config(UInt32 *out0, UInt32 *out1) {
    *out0 = U32At(accelerator, 0x98);
    *out1 = U32At(accelerator, 0x9c);
    return 0;
}

/* finish(mode): 0 = wait on this context's own stamp (same slot GL finish uses, +0x55c); 1 / 2 = wait on
 * the accelerator's own pending stamp (-1) via slot +0x55c / +0x558; anything else = BadArgument. */
IOReturn IOATIR5002DContext::finish(UInt32 mode) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    void *accel = accelerator;
    if (mode == 0) {
        SInt32 delta = CallAccelWait(accel, 0x55c, U32At(self, 0x7c));
        if (delta == -1) {
            return 0xe00002d6;
        }
        U32At(accelerator, 0x7a4) += delta;
        return 0;
    }
    if (mode != 1 && mode != 2) {
        return 0xe00002c2;
    }
    SInt32 delta = CallAccelWait(accel, mode == 1 ? 0x55c : 0x558, U32At(accel, 0x50) - 1);
    if (delta == -1) {
        return 0xe00002d6;
    }
    U32At(accelerator, 0x7a0) += delta;
    return 0;
}

IOReturn IOATIR5002DContext::scale_surface(UInt32 flags, UInt32 xScale, UInt32 yScale) {
    Ctx2D_lock(*reinterpret_cast<void **>(reinterpret_cast<UInt8 *>(accelerator) + 0x840));
    IOReturn result;
    if (boundSurface == nullptr || (flags & 1) == 0) {
        result = 0xe00002c7;
    } else {
        /* real: 12-byte IOAccelSurfaceScaling built on the stack: {0,0,x,y,x,y} halfwords */
        UInt16 scaling[6] = {0, 0, static_cast<UInt16>(xScale), static_cast<UInt16>(yScale),
                             static_cast<UInt16>(xScale), static_cast<UInt16>(yScale)};
        result = boundSurface->set_scaling(((flags >> 2) & 1) | (flags & 2), reinterpret_cast<IOAccelSurfaceScaling *>(scaling));
    }
    Ctx2D_unlock(*reinterpret_cast<void **>(reinterpret_cast<UInt8 *>(accelerator) + 0x840));
    return result;
}

/* create_shared: allocate and init this context's IOATIR500Shared, and wire it to the accelerator (+0xc)
 * and the owning task (+8). Real: `init()` is the vtable +0x48 call (IOATIR500Shared::init). */
bool IOATIR5002DContext::create_shared() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    IOATIR500Shared *shared = new IOATIR500Shared();
    sharedAllocator = shared;
    if (shared == nullptr) {
        return false;
    }
    if (!shared->init()) {
        shared->release();
        sharedAllocator = nullptr;
        return false;
    }
    U32At(shared, 0xc) = U32At(self, 0x94);
    U32At(shared, 0x8) = U32At(self, 0x78);
    return true;
}

IOReturn IOATIR5002DContext::declare_image(UInt32 param1, unsigned int formatOrSize, UInt32 sizeInBytes, unsigned int *outHandle) {
    (void)param1;
    if (sizeInBytes == 0 || formatOrSize == 0) {
        return 0xe00002c2;
    }
    void *lock = *reinterpret_cast<void **>(reinterpret_cast<UInt8 *>(accelerator) + 0x840);
    Ctx2D_lock(lock);
    if (sharedAllocator == nullptr && !create_shared()) {
        Ctx2D_unlock(lock);
        return 0xe00002be;
    }
    void *texture = sharedAllocator->new_agp_texture(formatOrSize, sizeInBytes, outHandle);
    Ctx2D_unlock(lock);
    return texture == nullptr ? 0xe00002bd : 0;
}

IOReturn IOATIR5002DContext::create_image(UInt32 param1, UInt32 param2, unsigned int *outLow, unsigned int *outHigh) {
    if (param1 == 0) {
        return 0xe00002c2;
    }
    void *lock = *reinterpret_cast<void **>(reinterpret_cast<UInt8 *>(accelerator) + 0x840);
    Ctx2D_lock(lock);
    if (sharedAllocator == nullptr && !create_shared()) {
        Ctx2D_unlock(lock);
        return 0xe00002be;
    }
    void *texture = sharedAllocator->new_texture(param1, param2, 0, 0, outLow, outHigh);
    Ctx2D_unlock(lock);
    return texture == nullptr ? 0xe00002bd : 0;
}

IOReturn IOATIR5002DContext::delete_image(UInt32 textureID) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    void *lock = *reinterpret_cast<void **>(reinterpret_cast<UInt8 *>(accelerator) + 0x840);
    Ctx2D_lock(lock);
    IOATIR500Shared *shared = sharedAllocator;
    IOReturn result;
    if (shared == nullptr) {
        result = 0xe00002be;
    } else {
        UInt8 *sharedBytes = reinterpret_cast<UInt8 *>(shared);
        UInt8 *tex = nullptr;
        if (textureID < U32At(sharedBytes, 0x14)) {
            tex = reinterpret_cast<UInt8 **>(U32At(sharedBytes, 0x10))[textureID];
        }
        if (tex == nullptr) {
            result = 0xe00002c2;
        } else {
            if (reinterpret_cast<UInt8 *>(U32At(self, 0x114)) == tex) {
                U32At(self, 0x114) = 0;
            }
            if (boundSurface != nullptr) {
                ATIR500SurfaceBuffer *buf = reinterpret_cast<ATIR500SurfaceBuffer *>(U32At(boundSurface, 0xb70)); /* surfaceBuffersByFormat[0] */
                UInt8 *backing = reinterpret_cast<UInt8 *>(U32At(buf, 0x24));
                if (backing != nullptr && U32At(backing, 8) == U32At(tex, 8)) {
                    U8At(backing, 0x59) = 0;
                    boundSurface->free_buffer_backing_store(buf);
                    shared = sharedAllocator;
                }
            }
            result = shared->delete_texture(reinterpret_cast<VendorTextureBuffer *>(tex));
        }
    }
    Ctx2D_unlock(lock);
    return result;
}

IOReturn IOATIR5002DContext::wait_image(UInt32 textureID) {
    void *lock = *reinterpret_cast<void **>(reinterpret_cast<UInt8 *>(accelerator) + 0x840);
    Ctx2D_lock(lock);
    IOATIR500Shared *shared = sharedAllocator;
    if (shared == nullptr) {
        Ctx2D_unlock(lock);
        return 0xe00002be;
    }
    UInt8 *sharedBytes = reinterpret_cast<UInt8 *>(shared);
    UInt8 *tex = nullptr;
    if (textureID < U32At(sharedBytes, 0x14)) {
        tex = reinterpret_cast<UInt8 **>(U32At(sharedBytes, 0x10))[textureID];
    }
    if (tex == nullptr) {
        Ctx2D_unlock(lock);
        return 0xe00002c2;
    }
    Ctx2D_unlock(lock);
    /* real: wait on the texture record's own stamp (record+8) via accelerator slot +0x550 */
    SInt32 delta = CallAccelWait(accelerator, 0x550, U32At(reinterpret_cast<void *>(U32At(tex, 0x14)), 8));
    if (delta == -1) {
        return 0xe00002d6;
    }
    U32At(accelerator, 0x75c) += delta;
    return 0;
}

/* set_surface_paging_options / set_surface_vsync_options: deliberate stubs in the shipped driver */
IOReturn IOATIR5002DContext::set_surface_paging_options(IOSurfacePagingControlInfoStruct *inStruct, IOSurfacePagingControlInfoStruct *outStruct, UInt32 structSize, UInt32 *outTag) {
    (void)inStruct; (void)outStruct; (void)structSize; (void)outTag;
    return 0xe00002c7; /* kIOReturnUnsupported */
}

IOReturn IOATIR5002DContext::set_surface_vsync_options(IOSurfaceVsyncControlInfoStruct *inStruct, IOSurfaceVsyncControlInfoStruct *outStruct, UInt32 structSize, UInt32 *outTag) {
    (void)inStruct; (void)outStruct; (void)structSize; (void)outTag;
    return 0xe00002c7; /* kIOReturnUnsupported */
}
