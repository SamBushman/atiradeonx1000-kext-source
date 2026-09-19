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

/* FUN_00004ea8 / FUN_00004f04: RESOLVED (issue #58 follow-up) - kxld-patched stubs whose
 * live targets are IOMalloc (0x2b1b50) and IOFree (0x2b1b94), exact nm matches. */
extern "C" void *VendorTexBuf_IOMalloc(UInt32 size) asm("_IOMalloc");
extern "C" void VendorTexBuf_IOFree(void *ptr, UInt32 size) asm("_IOFree");

/* (re-ported mechanically: see IOATIR500Accelerator_allocVendorTextureBuffer_Port.cpp) */


/* (re-ported mechanically: see IOATIR500Accelerator_releaseVendorTextureBuffer_Port.cpp) */


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
/* (re-ported mechanically: see IOATIR500Accelerator_removeTransferFromGART_Port.cpp) */


/*
 * ATIRadeonX1000's own copies - CONFIRMED (see file header note above):
 * real, plain explicit-base-qualified forwards, not genuine overrides.
 */
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


/*
 * alloc_surface_buffer - RESOLVED (issue #1, get-it-linking pass), real
 * addr 0x4590. A real, genuine placeholder: unconditionally returns 0
 * (not overridden by the subclass - identical address on both vtables,
 * matching this project's own already-established header comment).
 */
/* (re-ported mechanically: see IOATIR500Accelerator_alloc_surface_buffer_Port.cpp) */

