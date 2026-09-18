/*
 * IOATIR500DVDContext_ExternalMethods.cpp
 *
 * RESOLVED (issue #59 / #42): real bodies for the DVD context's base external-method table members
 * that only need already-reconstructed pieces (real addrs in parentheses):
 *   get_config (0xe980)  get_status (0xe9b0)  get_surface_size (0xe9e0)  finish (0xea30)
 *   unlock_memory (0xff20)  write_buffer (0xffe0)  declare_image (0x103e0)  delete_image (0x104f0)
 *   create_shared (0xee60)
 * Still on #59 for this class: lock_all_buffers (needs IOATIR500Surface::alloc_surfaces) and the
 * start/stop/clientClose/remove_surface/setCompatibleSurfaceMode family.
 *
 * Field offsets: this+0x78 task, +0x7c stamp tag, +0x84 shared allocator, +0x88 surface-flags bitmask,
 * +0x8c accelerator, +0xf8 bound surface (NULL until set_surface binds one). accelerator+0x80 =
 * hardware up, +0x840 = command lock.
 *
 * REAL VENDOR BUG, reproduced faithfully: write_buffer reads `boundSurface + 0xb70 + ...` BEFORE it
 * checks boundSurface for NULL. On a fresh DVD connection (no set_surface yet) that is a kernel NULL
 * dereference: it panics the stock driver exactly like set_macrovision does (issue #43). The load is
 * done through a volatile pointer so the compiler cannot delete the later null check on the grounds
 * that the earlier dereference already proved non-null.
 *
 * Confidence: CONFIRMED for control flow and offsets - complete decompiles.
 */

#include "../Headers/IOATIR500DVDContext.h"
#include "../Headers/ATIRadeonX1000.h"
#include "../Headers/IOATIR500Surface.h"
#include "../Headers/IOATIR500Shared.h"

extern "C" void DVDBase_lock(void *) asm("_IOLockLock");
extern "C" void DVDBase_unlock(void *) asm("_IOLockUnlock");
extern "C" void DVDBase_IOSleep(UInt32) asm("_IOSleep");
extern "C" void *DVDBase_withAddress(UInt32 address, UInt32 length, UInt32 direction, void *task) asm("__ZN18IOMemoryDescriptor11withAddressEjm11IODirectionP4task");
extern "C" int kernelPageSize asm("_page_size"); /* kernel page_size (0x1000); see ATIRadeonX1000Types.h notes on the "_ASICSupportsAGP" label */

namespace {
inline UInt32 &U32At(void *base, int offset) { return *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt16 &U16At(void *base, int offset) { return *reinterpret_cast<UInt16 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt8  &U8At(void *base, int offset)  { return *(reinterpret_cast<UInt8 *>(base) + offset); }
typedef void (*BlitTileFn)(void *, UInt32, UInt32, UInt32, UInt32, UInt32, UInt32, void *, UInt32, UInt32, UInt32, UInt32, UInt32);
typedef SInt32 (*Fn0x55c)(void *, UInt32);
typedef void (*Fn0x5ac)(void *, void *);
typedef void (*ReleaseFn)(void *);
struct DVDWriteXfer { UInt32 word0; UInt32 needsRelease; void *memDesc; UInt16 kind; UInt16 pad; };
} // namespace

IOReturn IOATIR500DVDContext::get_config(UInt32 *out0, UInt32 *out1) {
    *out0 = U32At(accelerator, 0x98);
    *out1 = U32At(accelerator, 0x9c);
    return 0;
}

IOReturn IOATIR500DVDContext::get_status(UInt32 *out0) {
    UInt32 status = 1;
    if (boundSurface == nullptr || (U32At(boundSurface, 0xbf8) & 0x20000000u) != 0) {
        status = 0;
    }
    *out0 = status;
    return 0;
}

IOReturn IOATIR500DVDContext::get_surface_size(SInt32 *outW, SInt32 *outH) {
    if (boundSurface == nullptr) {
        return 0xe00002bc;
    }
    UInt8 *buf = reinterpret_cast<UInt8 *>(U32At(boundSurface, 0xb70));
    *outW = U16At(buf, 0x1c);
    buf = reinterpret_cast<UInt8 *>(U32At(boundSurface, 0xb70));
    *outH = U16At(buf, 0x1e);
    return 0;
}

IOReturn IOATIR500DVDContext::finish() {
    void *accel = accelerator;
    void **vtable = *reinterpret_cast<void ***>(accel);
    SInt32 delta = (*reinterpret_cast<Fn0x55c *>(vtable + (0x55c / 4)))(accel, U32At(this, 0x7c));
    if (delta == -1) {
        return 0xe00002d6;
    }
    U32At(accelerator, 0x7ac) += delta;
    return 0;
}

IOReturn IOATIR500DVDContext::unlock_memory(UInt32 lockType, UInt32 *outTag) {
    (void)lockType;
    void *lock = *reinterpret_cast<void **>(reinterpret_cast<UInt8 *>(accelerator) + 0x840);
    DVDBase_lock(lock);
    IOReturn result;
    if (boundSurface == nullptr) {
        result = 0xe00002c2;
    } else {
        result = 0;
        U16At(boundSurface, 0xbd2) -= 1;
    }
    DVDBase_unlock(lock);
    *outTag = 0; /* real: both branches of the decompile store 0 */
    return result;
}

/* create_shared: see IOATIR5002DContext::create_shared - same body, this class's own offsets (+0x84, +0x8c) */
bool IOATIR500DVDContext::create_shared() {
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
    U32At(shared, 0xc) = U32At(this, 0x8c);
    U32At(shared, 0x8) = U32At(this, 0x78);
    return true;
}

IOReturn IOATIR500DVDContext::declare_image(UInt32 param1, UInt32 formatOrSize, UInt32 sizeInBytes, UInt32 *outHandle) {
    (void)param1;
    if (sizeInBytes == 0 || formatOrSize == 0) {
        return 0xe00002c2;
    }
    void *lock = *reinterpret_cast<void **>(reinterpret_cast<UInt8 *>(accelerator) + 0x840);
    DVDBase_lock(lock);
    if (sharedAllocator == nullptr && !create_shared()) {
        DVDBase_unlock(lock);
        return 0xe00002be;
    }
    void *texture = sharedAllocator->new_agp_texture(formatOrSize, sizeInBytes, outHandle);
    DVDBase_unlock(lock);
    return texture == nullptr ? 0xe00002bd : 0;
}

IOReturn IOATIR500DVDContext::delete_image(UInt32 textureID) {
    void *lock = *reinterpret_cast<void **>(reinterpret_cast<UInt8 *>(accelerator) + 0x840);
    DVDBase_lock(lock);
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
        result = (tex == nullptr) ? static_cast<IOReturn>(0xe00002c2)
                                  : shared->delete_texture(reinterpret_cast<VendorTextureBuffer *>(tex));
    }
    DVDBase_unlock(lock);
    return result;
}

/* write_buffer(data, byteCount): the DVD context's clipped framebuffer WRITE-back into a caller-supplied
 * userspace range - the same shape as GL read_buffer / Surface surface_read, keyed off bound-surface
 * buffer index 0xf or 0x10. data layout: {x,y,w,h, kindFlag, destBase, stride}. */
IOReturn IOATIR500DVDContext::write_buffer(UInt32 *dataWords, UInt32 byteCount) {
    (void)byteCount;
    UInt8 *data = reinterpret_cast<UInt8 *>(dataWords);
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *accel = reinterpret_cast<UInt8 *>(accelerator);

    SInt32 x = static_cast<SInt32>(U32At(data, 0x00));
    SInt32 y = static_cast<SInt32>(U32At(data, 0x04));
    SInt32 w = static_cast<SInt32>(U32At(data, 0x08));
    SInt32 h = static_cast<SInt32>(U32At(data, 0x0c));
    UInt32 destBase = U32At(data, 0x14);
    UInt32 bufferOffset = (0x10 - (U32At(data, 0x10) == 0 ? 1u : 0u)) * 4;

    void *commandLock = *reinterpret_cast<void **>(accel + 0x840);
    DVDBase_lock(commandLock);

    UInt8 *surface = reinterpret_cast<UInt8 *>(boundSurface);
    /* FAITHFUL VENDOR BUG (see header): dereferences surface+0xb70+off before the NULL check below. */
    UInt8 *bufRec = reinterpret_cast<UInt8 *>(*reinterpret_cast<volatile UInt32 *>(surface + bufferOffset + 0xb70));
    UInt32 mask = 0x40000000;
    UInt32 slotIdx = static_cast<UInt32>((static_cast<SInt32>(reinterpret_cast<UInt32>(bufRec)) -
                                          static_cast<SInt32>(reinterpret_cast<UInt32>(surface + 0xa8))) >> 3) *
                     static_cast<UInt32>(-0x11111111);
    if (slotIdx < 0x17) {
        mask = (1u << (slotIdx & 0x3f)) & U32At(self, 0x88);
    }
    if (surface == nullptr || mask == 0) {
        DVDBase_unlock(commandLock);
        return 0xe00002cc;
    }

    bool skipGate = false;
    if ((mask & U32At(surface, 0xbf8)) != 0) {
        UInt8 *backing = reinterpret_cast<UInt8 *>(U32At(bufRec, 0x24));
        if (backing == nullptr) {
            DVDBase_unlock(commandLock);
            return 0;
        }
        if (U8At(accel, 0x80) != 0 && U8At(backing, 0x58) == 0) {
            IOReturn allocResult = boundSurface->alloc_surfaces_retry(mask, 0);
            if (allocResult != 0) {
                DVDBase_unlock(commandLock);
                return 0xe00002cc;
            }
            bufRec = reinterpret_cast<UInt8 *>(U32At(boundSurface, bufferOffset + 0xb70));
            skipGate = true;
        }
    }
    if (!skipGate) {
        if ((U32At(surface, 0xbf8) & 0x20000000u) != 0 || U32At(bufRec, 0x10) == 0) {
            DVDBase_unlock(commandLock);
            return 0xe00002cc;
        }
    }

    SInt32 xEnd = x + w;
    SInt32 yEnd = y + h;
    SInt32 bufW = U16At(bufRec, 0x1c);
    SInt32 bufH = U16At(bufRec, 0x1e);
    if (!(xEnd > 0 && yEnd > 0 && x < bufW && y < bufH)) {
        DVDBase_unlock(commandLock);
        return 0;
    }

    SInt32 destStride = static_cast<SInt32>(U32At(data, 0x18));
    SInt32 byteOffset = 0;
    if (x < 0) { byteOffset = -(static_cast<SInt32>(U16At(bufRec, 0x16)) * x); x = 0; w = xEnd; }
    if (y < 0) { byteOffset -= destStride * y; y = 0; h = yEnd; }
    if (bufW < xEnd) { w = bufW - x; }
    if (bufH < yEnd) { h = bufH - y; }

    UInt32 addr = destBase + byteOffset;
    UInt32 addrLow = addr & (static_cast<UInt32>(kernelPageSize) - 1);
    UInt32 alignedAddr = addr & static_cast<UInt32>(-kernelPageSize);
    UInt32 length = static_cast<UInt32>(-kernelPageSize) &
                    ((static_cast<UInt32>(kernelPageSize) + destStride * (h - 1) +
                      static_cast<UInt32>(U16At(bufRec, 0x16)) * w + addrLow) - 1);

    DVDWriteXfer xfer = {0, 0, nullptr, 3, 0};
    void *memDesc = DVDBase_withAddress(alignedAddr, length, 0, reinterpret_cast<void *>(U32At(self, 0x78)));
    xfer.memDesc = memDesc;
    IOReturn result;
    if (memDesc == nullptr) {
        result = 0xe00002be;
    } else {
        UInt32 stampBefore = U32At(surface, 0x7c);
        void **surfVtable = *reinterpret_cast<void ***>(surface);
        (*reinterpret_cast<BlitTileFn *>(surfVtable + (0x5ec / 4)))(
            surface, static_cast<UInt32>(x), static_cast<UInt32>(y), static_cast<UInt32>(w), static_cast<UInt32>(h),
            0, 0, bufRec, U32At(accel, 0x50) - 1, reinterpret_cast<UInt32>(&xfer),
            addrLow, static_cast<UInt32>(destStride), 0);

        UInt8 *slotBase = surface + 0xa0;
        for (int i = 0x17; i != 0; i--) {
            UInt8 *slotBuf = *reinterpret_cast<UInt8 **>(slotBase + 0x2c);
            slotBase += 0x78;
            if (slotBuf != nullptr && stampBefore == U32At(slotBuf, 0x54)) {
                U32At(slotBuf, 0x54) = U32At(surface, 0x7c);
            }
        }
        if (xfer.needsRelease != 0) {
            DVDBase_unlock(commandLock);
            void **accelVtable = *reinterpret_cast<void ***>(accel);
            SInt32 prev = *reinterpret_cast<SInt32 *>(accel + 0x7b0);
            SInt32 delta = (*reinterpret_cast<Fn0x55c *>(accelVtable + (0x55c / 4)))(accel, U32At(surface, 0x7c));
            *reinterpret_cast<SInt32 *>(accel + 0x7b0) = prev + delta;
            DVDBase_lock(commandLock);
            (*reinterpret_cast<Fn0x5ac *>(accelVtable + (0x5ac / 4)))(accel, &xfer);
        }
        result = 0;
        (*reinterpret_cast<ReleaseFn *>(*reinterpret_cast<void ***>(memDesc) + (0x18 / 4)))(memDesc);
    }
    DVDBase_unlock(commandLock);
    return result;
}
