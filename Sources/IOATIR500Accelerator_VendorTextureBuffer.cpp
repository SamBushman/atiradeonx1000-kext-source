/*
 * IOATIR500Accelerator_VendorTextureBuffer.cpp
 *
 * RESOLVED (issue #1, get-it-linking pass): real bodies for
 * `IOATIR500Accelerator::allocVendorTextureBuffer`,
 * `releaseVendorTextureBuffer`, and `removeTransferFromGART` - a real,
 * important correction along the way: this project's own header
 * comments had characterized `ATIRadeonX1000`'s own copies of these
 * three methods as "real subclass override, different address",
 * implying genuinely distinct override bodies. A live decompile of
 * those subclass addresses (0x1a560/0x1a590/0x1a530) instead shows
 * each is a plain, literal tail-call through a real static function
 * pointer (`PTR_allocVendorTextureBuffer_00046ee0` etc.) - and reading
 * those pointers' own real, statically-bound values (confirmed by
 * direct memory read, not guessed) shows they point EXACTLY at these
 * three base-class bodies (0x4dc0/0x4ec0/0x34f0). The subclass "does
 * NOT actually override" these three at all - it's a real, compiled
 * `ATIRadeonX1000::method() { return IOATIR500Accelerator::method(); }`
 * explicit-base-qualified forward, which gcc compiled as a direct
 * tail-call stub through a lazy-pointer rather than going back through
 * the vtable.
 *
 * Confidence: CONFIRMED for control flow and every real struct offset.
 * `allocVendorTextureBuffer`'s own real decompile never shows an
 * explicit return statement (r3 is never overwritten after the initial
 * allocation) - the same real Ghidra return-value-dropped artifact this
 * project already documents elsewhere (e.g. `alloc_overlay`) -
 * transcribed here with the allocated record as the real, explicit
 * return value, matching this class's own already-established real
 * return type. `removeTransferFromGART`'s own real `+0x5a4` vtable
 * call is not independently named elsewhere in this project.
 */

#include "../Headers/IOATIR500Accelerator.h"
#include "../Headers/ATIRadeonX1000.h"
#include "../Headers/ATIRadeonX1000Types.h"

namespace {
inline UInt32 &U32At(void *base, int offset) { return *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt16 &U16At(void *base, int offset) { return *reinterpret_cast<UInt16 *>(reinterpret_cast<UInt8 *>(base) + offset); }
} // namespace

extern "C" void *FUN_00004ea8(UInt32 size); /* real, address-pinned local allocator - own identity NOT independently confirmed (a generic fixed/caller-sized allocator, not specific to VendorTextureBuffer despite this class's own naming) */
extern "C" void FUN_00004f04(void *record, UInt32 size); /* real, address-pinned local deallocator, the real inverse of FUN_00004ea8 above */

VendorTextureBuffer *IOATIR500Accelerator::allocVendorTextureBuffer(UInt32 size) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt32 *rec = reinterpret_cast<UInt32 *>(FUN_00004ea8(size));
    U32At(self, 0x808) += size;
    U16At(rec, 0xc) = 4; /* real: `*(undefined2*)(puVar1+3) = 4` - puVar1+3 elements = byte 0xc */
    rec[0] = 0; rec[1] = 0; rec[2] = 0;
    U16At(rec, 0xe) = 0;
    rec[4] = 0; rec[5] = 0; rec[6] = 0; rec[7] = 0;
    U16At(rec, 0x22) = 0;
    rec[0xb] = 0; rec[0xc] = 0;
    rec[0xf] = 0; rec[0x10] = 0; rec[0x11] = 0; rec[0x12] = 0; rec[0x13] = 0;
    rec[0x14] = 0; rec[0x15] = 0; rec[0x16] = 0;
    rec[0x18] = 0; rec[0x19] = 0;
    U16At(rec, 0x1c * 4) = 0;
    U16At(rec, 0x72) = 0;
    rec[9] = reinterpret_cast<UInt32>(rec);
    rec[10] = reinterpret_cast<UInt32>(rec);
    rec[0xd] = reinterpret_cast<UInt32>(rec);
    rec[0xe] = reinterpret_cast<UInt32>(rec);
    rec[0x1b] = 0xffffffff;
    rec[0x1a] = 0;
    rec[0x1d] = 0;
    U16At(rec, 0x1e * 4) = 0;
    U16At(rec, 0x7a) = 0;
    rec[0x1f] = 0;
    return reinterpret_cast<VendorTextureBuffer *>(rec);
}

void IOATIR500Accelerator::releaseVendorTextureBuffer(VendorTextureBuffer *buffer, UInt32 size) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    FUN_00004f04(buffer, size);
    U32At(self, 0x808) -= size;
}

/*
 * removeTransferFromGART - CONFIRMED. Real body: if the buffer's own
 * "kind" tag (+0xc) is 4 (a real GART-mapped transfer buffer), unlinks
 * it from whatever real doubly-linked list it's currently on
 * (+0x34/+0x38 prev/next, the same shape `allocVendorTextureBuffer`'s
 * own self-linked-empty-list initialization above already
 * establishes), then always calls this accelerator's own real +0x5a4
 * vtable slot (own identity not independently confirmed elsewhere)
 * with the buffer's own +8/+4 fields, and clears the buffer's own +4
 * field.
 */
void IOATIR500Accelerator::removeTransferFromGART(VendorTransferBuffer *buffer) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *buf = reinterpret_cast<UInt8 *>(buffer);
    if (buf == nullptr) {
        return;
    }
    if (*reinterpret_cast<SInt16 *>(buf + 0xc) == 4) {
        UInt8 *prev = *reinterpret_cast<UInt8 **>(buf + 0x34);
        UInt8 *next = *reinterpret_cast<UInt8 **>(buf + 0x38);
        U32At(prev, 0x38) = reinterpret_cast<UInt32>(next);
        *reinterpret_cast<UInt8 **>(buf + 0x38) = buf;
        U32At(next, 0x34) = reinterpret_cast<UInt32>(prev);
        *reinterpret_cast<UInt8 **>(buf + 0x34) = buf;
    }
    typedef void (*Fn0x5a4)(void *, UInt32, UInt32);
    (*reinterpret_cast<Fn0x5a4 *>(*reinterpret_cast<void ***>(self) + (0x5a4 / 4)))(self, U32At(buf, 8), U32At(buf, 4));
    U32At(buf, 4) = 0;
}

/*
 * ATIRadeonX1000's own copies - CONFIRMED (see file header note above):
 * real, plain explicit-base-qualified forwards, not genuine overrides.
 */
VendorTextureBuffer *ATIRadeonX1000::allocVendorTextureBuffer(UInt32 size) {
    return IOATIR500Accelerator::allocVendorTextureBuffer(size);
}

void ATIRadeonX1000::releaseVendorTextureBuffer(VendorTextureBuffer *buffer, UInt32 size) {
    IOATIR500Accelerator::releaseVendorTextureBuffer(buffer, size);
}

void ATIRadeonX1000::removeTransferFromGART(VendorTransferBuffer *buffer) {
    IOATIR500Accelerator::removeTransferFromGART(buffer);
}
