/*
 * IOATIR500Accelerator_OneDataBuffer.cpp
 *
 * RESOLVED: `IOATIR500Accelerator::allocOneDataBuffer`/`freeOneDataBuffer`'s
 * real bodies (real addrs 0x6960/0x32d0). See
 * `Headers/IOATIR500Accelerator.h`'s own declaration comment for a real,
 * honestly-flagged open question about the exact identity of the
 * `+0x570`/`+0x574`/`+0x5ac`/`+0x56c` vtable calls below - transcribed
 * via raw vtable-offset casts rather than the candidate names pending
 * that resolution.
 *
 * `allocOneDataBuffer`: allocates a real `0xc0`-byte `VendorTextureBuffer`-
 * shaped object via `+0x570`, stamps its own `poolSizeClass` (`+0x50`)
 * and `mip` pointer (`+0x14`, pointed at the object's own embedded
 * `+0x80` record) and `typeTag` (`+0x20` = `8`, a real data-buffer type
 * this project hasn't seen elsewhere). If `forWrite` is false, or a real
 * `allocate_texture` call (`+0x528`, RESOLVED elsewhere) fails, falls
 * back to `allocDataBufferBacking`; on failure there too, releases via
 * `+0x574` and returns null. If `forWrite` succeeded, splices the buffer
 * into a real per-accelerator list (`this+0x600`, sentinel `this+0x5dc`)
 * when its own `transferBufferFlag` (`+0x48`) is set, then calls a real
 * `waitForTimeStamp`-shaped method (`+0x54c`, RESOLVED elsewhere) with
 * `this+0x50 - 1`. Either way, increments a real per-accelerator counter
 * (`+0x750`).
 *
 * `freeOneDataBuffer`: the real inverse - unsplices from the same list
 * (via `+0x524`, `deallocate_texture`'s own real slot, called here with
 * NO visible arguments in the raw decompile - the same real "calling-
 * convention artifact" this project documents elsewhere) when
 * `transferBufferFlag` is set, releases a real GART-mapping handle
 * (`+0x10`, vtable `+0x18` - `OSObject::release()`) if present, and - if
 * the buffer has a real `memoryDescriptor` (`+8`) - calls
 * `waitForTimeStamp` (`+0x54c`) on its own `+0x5c` field then a real,
 * previously-unknown vtable slot `+0x5ac` on the buffer itself before
 * releasing the descriptor (vtable `+0x18` again). Finally releases the
 * whole object via `+0x574` and decrements the same `+0x750` counter.
 *
 * Confidence: CONFIRMED for control flow and every real offset except
 * the `+0x570`/`+0x574`/`+0x5ac`/`+0x56c` identity question flagged in
 * the header. No C++ compiler was available in the sandboxed environment
 * this was written in (same standing limitation as every other file in
 * this project).
 */

#include "../Headers/IOATIR500Accelerator.h"
#include "../Headers/ATIRadeonX1000Types.h"

namespace {
inline UInt32 &U32At(void *base, int offset) { return *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt8  &U8At(void *base, int offset)  { return *(reinterpret_cast<UInt8 *>(base) + offset); }
} // namespace

VendorTextureBuffer *IOATIR500Accelerator::allocOneDataBuffer(UInt32 sizeClass, bool forWrite) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    void **vtable = *reinterpret_cast<void ***>(self);

    typedef VendorTextureBuffer *(*Fn0x570)(void *, UInt32);
    VendorTextureBuffer *buf = (*reinterpret_cast<Fn0x570 *>(vtable + (0x570 / 4)))(self, 0xc0);
    if (buf == nullptr) {
        return nullptr;
    }
    UInt8 *bufBytes = reinterpret_cast<UInt8 *>(buf);
    buf->poolSizeClass = sizeClass;
    *reinterpret_cast<UInt8 **>(bufBytes + 0x14) = bufBytes + 0x80;
    U8At(bufBytes, 0x20) = 8;

    bool allocatedForWrite = forWrite && allocate_texture(buf) != 0;
    if (!allocatedForWrite) {
        if (!allocDataBufferBacking(buf)) {
            typedef void (*Fn0x574)(void *, VendorTextureBuffer *, UInt32);
            (*reinterpret_cast<Fn0x574 *>(vtable + (0x574 / 4)))(self, buf, 0xc0);
            return nullptr;
        }
    } else {
        if (buf->transferBufferFlag != 0) {
            VendorTextureBuffer *prev = reinterpret_cast<VendorTextureBuffer *>(buf->surfaceOrFormatInfo);
            *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(prev) + 0x28) = U32At(bufBytes, 0x28);
            VendorTextureBuffer *next = reinterpret_cast<VendorTextureBuffer *>(buf->listNext);
            buf->surfaceOrFormatInfo = self + 0x5dc; /* real: sentinel-shaped, matches this project's other circular-list sentinels */
            *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(next) + 0x24) = reinterpret_cast<UInt32>(prev);
            buf->listNext = *reinterpret_cast<void **>(self + 0x600);
            *reinterpret_cast<VendorTextureBuffer **>(self + 0x600) = buf;
            *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(*reinterpret_cast<void **>(self + 0x600)) + 0x28) = reinterpret_cast<UInt32>(buf);
        }
        waitForTimeStamp(U32At(self, 0x50) - 1);
    }
    U32At(self, 0x750) += 1;
    return buf;
}

void IOATIR500Accelerator::freeOneDataBuffer(VendorTextureBuffer *buffer) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    void **vtable = *reinterpret_cast<void ***>(self);
    UInt8 *buf = reinterpret_cast<UInt8 *>(buffer);

    if (buffer->transferBufferFlag != 0) {
        deallocate_texture(buffer); /* real: +0x524, called with no visible args in the raw decompile - same calling-convention artifact documented elsewhere */
        VendorTextureBuffer *prev = reinterpret_cast<VendorTextureBuffer *>(buffer->surfaceOrFormatInfo);
        VendorTextureBuffer *next = reinterpret_cast<VendorTextureBuffer *>(buffer->listNext);
        *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(prev) + 0x28) = reinterpret_cast<UInt32>(next);
        buffer->listNext = buffer;
        *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(next) + 0x24) = reinterpret_cast<UInt32>(prev);
        buffer->surfaceOrFormatInfo = buffer;
    }

    if (buffer->gartMapping != nullptr) {
        typedef void (*ReleaseFn)(void *);
        (*reinterpret_cast<ReleaseFn *>(*reinterpret_cast<void ***>(buffer->gartMapping) + (0x18 / 4)))(buffer->gartMapping);
        buffer->gartMapping = nullptr;
    }

    void *memDesc = buffer->memoryDescriptor;
    if (memDesc != nullptr) {
        if (buffer->field_0x04 != 0) { /* real: `*(int*)(param_1+4)` - already-known "has real backing" gate */
            waitForTimeStamp(U32At(buf, 0x5c));
            typedef void (*Fn0x5ac)(void *, VendorTextureBuffer *);
            (*reinterpret_cast<Fn0x5ac *>(vtable + (0x5ac / 4)))(self, buffer);
            memDesc = buffer->memoryDescriptor;
        }
        typedef void (*ReleaseFn)(void *);
        (*reinterpret_cast<ReleaseFn *>(*reinterpret_cast<void ***>(memDesc) + (0x18 / 4)))(memDesc);
    }

    typedef void (*Fn0x574)(void *, VendorTextureBuffer *, UInt32);
    (*reinterpret_cast<Fn0x574 *>(vtable + (0x574 / 4)))(self, buffer, 0xc0);
    U32At(self, 0x750) -= 1;
}
