/*
 * IOATIR500Surface_Methods.cpp
 *
 * RESOLVED (ledger pass): IOATIR500Surface members that had no body in the rebuild, transcribed from the shipped
 * kext (real addrs in parentheses):
 *   free (0x10a50)  clientClose (0x10ac0)  add_2d_context_to_list (0x10ba0)  set_access (0x11100)
 *   sleep_blocked (0x11840)  alloc_surfaces (0x12470)  alloc_buffer_backing_store (0x12900)
 *   move_buffer_from_backing_store (0x131b0)  alloc_surface_keep (0x13210)  alloc_surface (0x13360)
 *   stop (0x134b0)  setupFullScreen (0x13900)  remove_2d_context_from_list (0x13e30)  surface_req_bits (0x13f50)
 *   buffer_map_offset (0x14010)  clientMemoryForType (0x141b0)
 *
 * Field offsets: this+0x7c stamp, +0x88/+0x8c/+0x90 GL / 2D / DVD context list heads (each context links to the
 * next through its own +0x84), +0x9c/+0xa0 accelerator surface-list links, +0xa8 first of 23 buffer records
 * (stride 0x78), +0xb70 per-format record pointers, +0xbd0/+0xbd1 read/write lock state bytes, +0xbf6 blocking
 * flag, +0xbf7 "has backing store" flag, +0xbf8 pending-allocation mask, +0xc00 access handle, +0xc04 per-surface
 * lock, +0xc14 full-screen panel (0xffff = none), +0xc18 combined context mode bits, +0xc28.. per-panel swap
 * buffers (stride 0x94), +0xd50 accelerator, +0xd58 "started" flag, +0xd60/+0xd64 per-id region records.
 *
 * `alloc_surfaces(mask, retry)` is `alloc_surfaces_pageq(mask, 0, retry)`: the raw decompile shows the wrong
 * argument shuffle (Ghidra thought the first parameter was `this`); the disassembly (`or r6,r5,r5; li r5,0; bl`)
 * is unambiguous.
 */

#include "../Headers/IOATIR500Surface.h"
#include "../Headers/IOATIR500GLContext.h"
#include "../Headers/IOATIR5002DContext.h"
#include "../Headers/IOATIR500DVDContext.h"
#include "../Headers/ATIRadeonX1000.h"

extern "C" void SurfM_IOLockFree(void *lock) asm("_IOLockFree");
extern "C" void SurfM_IOFree(void *ptr, UInt32 size) asm("_IOFreeAligned"); /* stub 0x13884 resolves to IOFreeAligned, not IOFree */
extern "C" void SurfM_IOLockLock(void *lock) asm("_IOLockLock");
extern "C" void SurfM_IOLockUnlock(void *lock) asm("_IOLockUnlock");
extern "C" void SurfM_IOLockSleep(void *lock, void *event, UInt32 interruptible) asm("_IOLockSleep");
extern "C" void *SurfM_inTaskWithOptions(void *task, UInt32 options, UInt32 capacity, unsigned int alignment) asm("__ZN24IOBufferMemoryDescriptor17inTaskWithOptionsEP4taskmjj");
extern "C" int kernelPageSize asm("_page_size");

namespace {
inline UInt32 &U32At(void *base, int offset) { return *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt16 &U16At(void *base, int offset) { return *reinterpret_cast<UInt16 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt8  &U8At(void *base, int offset)  { return *(reinterpret_cast<UInt8 *>(base) + offset); }
typedef void (*ReleaseFn)(void *);
typedef void (*RetainFn)(void *);
inline void ReleaseObj(void *obj) {
    void **vtable = *reinterpret_cast<void ***>(obj);
    reinterpret_cast<ReleaseFn>(vtable[0x18 / 4])(obj);
}
} // namespace

void IOATIR500Surface::free() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    if (U32At(self, 0xc04) != 0) {
        SurfM_IOLockFree(reinterpret_cast<void *>(U32At(self, 0xc04)));
    }
    OSObject::free();
}

IOReturn IOATIR500Surface::clientClose() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    if (U32At(self, 0xd58) != 0) {
        IOService *provider = *reinterpret_cast<IOService **>(self + 0xd50);
        this->stop(provider);
        this->detach(provider);
    }
    return 0;
}

void IOATIR500Surface::add_2d_context_to_list(IOATIR5002DContext *context) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    U32At(context, 0x84) = U32At(self, 0x8c);
    U32At(self, 0x8c) = reinterpret_cast<UInt32>(context);
    U32At(self, 0xc18) |= U32At(context, 0x8c);
}

void IOATIR500Surface::remove_2d_context_from_list(IOATIR5002DContext *context) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *node = reinterpret_cast<UInt8 *>(U32At(self, 0x8c));
    if (node == reinterpret_cast<UInt8 *>(context)) {
        U32At(self, 0x8c) = U32At(context, 0x84);
    } else {
        UInt8 *prev;
        do {
            prev = node;
            node = reinterpret_cast<UInt8 *>(U32At(prev, 0x84));
            if (node == nullptr) {
                break;
            }
        } while (reinterpret_cast<UInt8 *>(context) != node);
        U32At(prev, 0x84) = U32At(context, 0x84);
    }
    U32At(context, 0x84) = 0;
    reset_req_bits();
}

void IOATIR500Surface::set_access() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    U32At(self, 0xc00) = U32At(reinterpret_cast<void *>(U32At(self, 0xd50)), 0xdc);
}

void IOATIR500Surface::sleep_blocked() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    void *lock = reinterpret_cast<void *>(U32At(self, 0xc04));
    SurfM_IOLockLock(lock);
    while (U8At(self, 0xbf6) != 0) {
        SurfM_IOLockSleep(lock, this, 0);
    }
    SurfM_IOLockUnlock(lock);
}

UInt32 IOATIR500Surface::alloc_surfaces(UInt32 mask, bool retry) {
    return alloc_surfaces_pageq(mask, 0, retry);
}

UInt32 IOATIR500Surface::surface_req_bits() {
    return 0;
}

bool IOATIR500Surface::buffer_map_offset(ATIR500SurfaceBuffer *buffer, UInt32 a, UInt32 b, SInt32 *w, SInt32 *h, SInt32 *bytes) {
    (void)a; (void)b;
    UInt8 *rec = reinterpret_cast<UInt8 *>(buffer);
    UInt16 pitchWords = U16At(rec, 0x14);
    UInt16 bytesPerPixel = U16At(rec, 0x16);
    UInt16 height = U16At(rec, 0x1e);
    if (w != nullptr) {
        *w = U16At(rec, 0x1c);
    }
    if (h != nullptr) {
        *h = height;
    }
    if (bytes != nullptr) {
        *bytes = static_cast<SInt32>(static_cast<UInt32>(bytesPerPixel) * static_cast<UInt32>(pitchWords));
    }
    return true;
}

bool IOATIR500Surface::alloc_buffer_backing_store(ATIR500SurfaceBuffer *buffer) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *rec = reinterpret_cast<UInt8 *>(buffer);
    UInt32 page = static_cast<UInt32>(kernelPageSize);
    UInt32 size = (page + U32At(rec, 0x10) - 1u) & static_cast<UInt32>(-kernelPageSize);
    void *desc = SurfM_inTaskWithOptions(reinterpret_cast<void *>(U32At(reinterpret_cast<void *>(U32At(self, 0xd50)), 0x220)), 0x10063, size, 0);
    if (desc != nullptr) {
        U8At(self, 0xbf7) = 1;
        attach_buffer_backing_store(buffer, reinterpret_cast<IOMemoryDescriptor *>(desc), 0, U16At(rec, 0x18));
        UInt8 *backing = reinterpret_cast<UInt8 *>(U32At(rec, 0x24));
        U8At(backing, 0x59) = 0;
        U32At(backing, 0x54) = U32At(self, 0x7c) - 1;
    } else {
        UInt32 index = static_cast<UInt32>((static_cast<SInt32>(reinterpret_cast<UInt32>(rec)) -
                                            static_cast<SInt32>(reinterpret_cast<UInt32>(self + 0xa8))) >> 3) *
                       static_cast<UInt32>(-0x11111111);
        dealloc_surface(index);
    }
    return desc != nullptr;
}

UInt32 IOATIR500Surface::move_buffer_from_backing_store(ATIR500SurfaceBuffer *buffer) {
    copy_buffer_from_backing_store(buffer);
    free_buffer_backing_store(buffer);
    return 1;
}

/* Shared tail of alloc_surface / alloc_surface_keep: clear bit `index` of the pending-allocation mask. */
static inline void ClearPendingBit(UInt8 *self, UInt32 index) {
    U32At(self, 0xbf8) &= ~(1u << (index & 0x1f));
}

bool IOATIR500Surface::alloc_surface_keep(IOATIR500Surface *other, VendorTextureBuffer **texture, SInt32 param3, UInt32 index) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    ATIR500SurfaceBuffer *rec = reinterpret_cast<ATIR500SurfaceBuffer *>(self + index * 0x78 + 0xa8);
    if (U32At(self, index * 0x78 + 0xb8) == 0 || U32At(self, index * 0x78 + 0xb0) != 0) {
        if (U32At(self, index * 0x78 + 0xcc) != 0) {
            free_buffer_backing_store(rec);
        }
    } else {
        UInt32 ok = alloc_surface_buffer(rec);
        if (ok == 0) {
            ok = reinterpret_cast<ATIRadeonX1000 *>(U32At(self, 0xd50))->freeToAllocSurfaceVRAM(this, other, texture, param3, rec);
            if (ok == 0) {
                return false;
            }
        }
        if (((3u >> (index & 0x3f)) & 1) != 0) {
            U32At(self, 0xbf8) |= 0x10000000;
        }
        if (U32At(self, index * 0x78 + 0xcc) != 0) {
            move_buffer_from_backing_store(rec);
        }
    }
    ClearPendingBit(self, index);
    return true;
}

bool IOATIR500Surface::alloc_surface(UInt32 index, bool moveFromBacking) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    ATIR500SurfaceBuffer *rec = reinterpret_cast<ATIR500SurfaceBuffer *>(self + index * 0x78 + 0xa8);
    if (U32At(self, index * 0x78 + 0xb8) == 0 || U32At(self, index * 0x78 + 0xb0) != 0) {
        if (U32At(self, index * 0x78 + 0xcc) != 0) {
            free_buffer_backing_store(rec);
        }
    } else {
        UInt32 ok = alloc_surface_buffer(rec);
        if (ok == 0) {
            ok = reinterpret_cast<ATIRadeonX1000 *>(U32At(self, 0xd50))->freeToAllocSurfaceVRAM(this, nullptr, nullptr, 0, rec);
            if (ok == 0) {
                return false;
            }
        }
        if (((3u >> (index & 0x3f)) & 1) != 0) {
            U32At(self, 0xbf8) |= 0x10000000;
        }
        if (U32At(self, index * 0x78 + 0xcc) != 0) {
            if (moveFromBacking) {
                move_buffer_from_backing_store(rec);
            } else {
                free_buffer_backing_store(rec);
            }
        }
    }
    ClearPendingBit(self, index);
    return true;
}

void IOATIR500Surface::setupFullScreen() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    if (is_flip_allowed() != 0) {
        UInt32 panel = U32At(self, 0xc14);
        UInt8 *accel = reinterpret_cast<UInt8 *>(U32At(self, 0xd50));
        if (((1u << (panel & 0x3f)) & U32At(accel, 0xd0)) != 0) {
            U16At(self, panel * 0x94 + 0xcae) = static_cast<UInt16>((U16At(self, panel * 0x94 + 0xcae) + 1u) & 3);
            /* real: virtual slot +0x5e0 = submit_flip_buffer(panel, NULL context, 0) */
            submit_flip_buffer(U32At(self, 0xc14), nullptr, 0);
            U32At(reinterpret_cast<void *>(U32At(self, 0xd50)), 0x74c) += 1;
        }
    }
}

IOReturn IOATIR500Surface::clientMemoryForType(UInt32 type, UInt32 *options, IOMemoryDescriptor **memory) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *accel = reinterpret_cast<UInt8 *>(U32At(self, 0xd50));
    void *lock = *reinterpret_cast<void **>(accel + 0x840);
    SurfM_IOLockLock(lock);
    if (type < U32At(accel, 0xcc)) {
        void *desc = reinterpret_cast<void *>(U32At(self, type * 0x94 + 0xc28));
        void **vtable = *reinterpret_cast<void ***>(desc);
        (*reinterpret_cast<RetainFn *>(vtable + (0x14 / 4)))(desc);
        *options = 0;
        *memory = reinterpret_cast<IOMemoryDescriptor *>(desc);
        init_swap_buffer_header(reinterpret_cast<VendorSwapBufferHeader *>(U32At(self, type * 0x94 + 0xc34)), U32At(self, type * 0x94 + 0xcb0));
        SurfM_IOLockUnlock(lock);
        return 0;
    }
    SurfM_IOLockUnlock(lock);
    return 0xe00002c2;
}

void IOATIR500Surface::stop(IOService *provider) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    U32At(self, 0xd58) = 0;

    UInt8 *prev = reinterpret_cast<UInt8 *>(U32At(self, 0x9c));
    UInt8 *accel = reinterpret_cast<UInt8 *>(U32At(self, 0xd50));
    U32At(prev, 0xa0) = U32At(self, 0xa0);
    U32At(reinterpret_cast<void *>(U32At(self, 0xa0)), 0x9c) = reinterpret_cast<UInt32>(prev);
    if (reinterpret_cast<UInt8 *>(this) == reinterpret_cast<UInt8 *>(U32At(accel, 0x5c))) {
        if (reinterpret_cast<UInt8 *>(this) == reinterpret_cast<UInt8 *>(U32At(self, 0x9c))) {
            U32At(accel, 0x5c) = 0;
        } else {
            U32At(accel, 0x5c) = U32At(self, 0x9c);
        }
        accel = reinterpret_cast<UInt8 *>(U32At(self, 0xd50));
    }
    U32At(accel, 0x730) -= 1;
    if (U32At(self, 0xd48) != 0) {
        UInt32 count = U32At(reinterpret_cast<void *>(U32At(self, 0xd50)), 0x21c);
        if (count != 0) {
            U32At(reinterpret_cast<void *>(U32At(self, 0xd50)), 0x21c) = count - 1;
        }
    }

    /* release the orphaned-texture chain (next pointer at texture+0x54) */
    UInt8 *orphan = reinterpret_cast<UInt8 *>(U32At(self, 0xbcc));
    while (orphan != nullptr) {
        U32At(orphan, 0x50) = 0;
        U8At(reinterpret_cast<void *>(U32At(orphan, 0x14)), 0x14) = 1;
        U32At(self, 0xbcc) = U32At(orphan, 0x54);
        U32At(orphan, 0x54) = 0;
        orphan = reinterpret_cast<UInt8 *>(U32At(self, 0xbcc));
    }

    /* give back the full-screen panel this surface owns, if any */
    if (U32At(self, 0xc14) != 0xffff) {
        UInt8 *acc = reinterpret_cast<UInt8 *>(U32At(self, 0xd50));
        if (reinterpret_cast<UInt8 *>(this) == reinterpret_cast<UInt8 *>(U32At(acc, U32At(self, 0xc14) * 0x20 + 0xe8))) {
            resetFullScreen();
            U32At(reinterpret_cast<void *>(U32At(self, 0xd50)), U32At(self, 0xc14) * 0x20 + 0xe8) = 0;
            U32At(self, 0xc14) = 0xffff;
        }
    }

    UInt8 lockState = U8At(self, 0xbd0);
    if (lockState != 0) {
        if (lockState == 3) {
            UInt8 *bufRec = reinterpret_cast<UInt8 *>(U32At(self, 0xb70));
            if (U32At(self, 0xd8c) == 0) {
                UInt8 *backing = reinterpret_cast<UInt8 *>(U32At(bufRec, 0x24));
                if (backing != nullptr && U32At(backing, 0x10) != 0) {
                    ReleaseObj(reinterpret_cast<void *>(U32At(backing, 0x10)));
                    U32At(reinterpret_cast<void *>(U32At(bufRec, 0x24)), 0x10) = 0;
                }
            } else {
                free_buffer_backing_orphans();
            }
        } else if (lockState == 1) {
            complete_vram(reinterpret_cast<ATIR500SurfaceBuffer *>(U32At(self, 0xb70)));
        }
        U8At(self, 0xbd0) = 0;
    }

    if (U32At(self, 0xd84) != 0) {
        ReleaseObj(reinterpret_cast<void *>(U32At(self, 0xd84)));
        U32At(self, 0xd84) = 0;
    }
    if (U32At(self, 0xd88) != 0) {
        ReleaseObj(reinterpret_cast<void *>(U32At(self, 0xd88)));
        U32At(self, 0xd88) = 0;
    }

    /* detach every context still bound to this surface */
    IOATIR500GLContext *gl = reinterpret_cast<IOATIR500GLContext *>(U32At(self, 0x88));
    while (gl != nullptr) {
        gl->remove_surface();
        IOATIR500GLContext *next = reinterpret_cast<IOATIR500GLContext *>(U32At(gl, 0x84));
        U32At(gl, 0x84) = 0;
        gl = next;
    }
    IOATIR5002DContext *ctx2d = reinterpret_cast<IOATIR5002DContext *>(U32At(self, 0x8c));
    while (ctx2d != nullptr) {
        ctx2d->remove_surface();
        IOATIR5002DContext *next = reinterpret_cast<IOATIR5002DContext *>(U32At(ctx2d, 0x84));
        U32At(ctx2d, 0x84) = 0;
        ctx2d = next;
    }
    if (U32At(self, 0x90) != 0) {
        reinterpret_cast<IOATIR500DVDContext *>(U32At(self, 0x90))->remove_surface();
    }

    for (UInt32 i = 0; i <= 0x16; i++) {
        dealloc_surface(i);
        UInt8 *rec = self + i * 0x78;
        if (U32At(rec, 0xcc) != 0) {
            delete_buffer_backing(reinterpret_cast<IOTextureBuffer *>(U32At(rec, 0xcc)));
            U32At(rec, 0xcc) = 0;
        }
    }

    UInt8 *acc = reinterpret_cast<UInt8 *>(U32At(self, 0xd50));
    if (U32At(acc, 0xcc) != 0) {
        for (UInt32 idx = 0; idx < U32At(reinterpret_cast<void *>(U32At(self, 0xd50)), 0xcc); idx++) {
            if (U32At(self, idx * 0x94 + 0xc28) != 0) {
                freeAllSwapBuffers(idx);
            }
            if (U32At(self, idx * 8 + 0xd60) != 0) {
                SurfM_IOFree(reinterpret_cast<void *>(U32At(self, idx * 8 + 0xd60)), U32At(self, idx * 8 + 0xd64));
                UInt8 *owner = reinterpret_cast<UInt8 *>(U32At(self, 0xd50));
                if (owner != nullptr) {
                    U32At(owner, 0x804) = U32At(owner, 0x804) - U32At(self, idx * 8 + 0xd64);
                }
                U32At(self, idx * 8 + 0xd64) = 0;
                U32At(self, idx * 8 + 0xd60) = 0;
            }
        }
    }
    if (U32At(self, 0xd8c) != 0) {
        free_buffer_backing_orphans();
    }
    IOUserClient::stop(provider);
}
