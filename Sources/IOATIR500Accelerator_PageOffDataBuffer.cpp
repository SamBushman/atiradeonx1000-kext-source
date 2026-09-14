/*
 * IOATIR500Accelerator_PageOffDataBuffer.cpp
 *
 * RESOLVED (issue #28): `IOATIR500Accelerator::pageOffDataBuffer`'s real
 * body, real addr 0x3140.
 *
 * Real behavior: tries `allocDataBufferBacking(buffer)` first.
 *
 * On FAILURE (0): calls `deallocate_texture(buffer)` (virtual dispatch -
 * RESOLVED, issue #28 addendum, see `Headers/IOATIR500Accelerator.h`),
 * then unlinks `buffer` from whatever real doubly-linked list it
 * currently sits in via its own `surfaceOrFormatInfo`/`listNext`
 * (`+0x24`/`+0x28`) fields, and sets both back to point at itself - the
 * real "detached, empty single-node list" idiom this project has not
 * previously named but is a real, recognizable C doubly-linked-list
 * pattern.
 *
 * On SUCCESS (nonzero): a real "temporarily redirect the GART mapping,
 * copy hardware descriptor data, restore it" sequence -
 *   1. If `buffer->gartMapping` (`+0x10`) is non-null, calls its own
 *      real, unidentified vtable slot `+0xf0` with args `(0, 0x400, 0)` -
 *      an Apple `IOMemoryMap`-family method this project does not
 *      reverse-engineer further (out of scope, same category as other
 *      external Apple vtable calls elsewhere in this project).
 *   2. The same real `+0x14c`/`+0xd0` "prepare mapping, then get real
 *      hardware-info pointer" vtable chain `load_texture` already
 *      establishes, called on `buffer->memoryDescriptor` (`+0x08`) with
 *      a different real flags value (`0x401` vs. `load_texture`'s own
 *      `accelerator+0x82c | 1`).
 *   3. If `buffer->poolSizeClass >> 2` (`+0x50`) is nonzero, copies that
 *      many dwords from `*(this+0xe4) + buffer->transferBufferFlag`
 *      (`+0x48`) into the real hardware-info pointer from step 2 - a
 *      real, previously-unknown use of `transferBufferFlag` as a byte
 *      offset rather than a pure boolean gate (this project's own prior
 *      documentation of that field as just a gate stands for its OTHER
 *      call sites; this is additional real evidence of a richer role).
 *      `this+0xe4` (accelerator-owned) is a real, not-yet-named pointer
 *      field - role UNKNOWN beyond this one use.
 *   4. Releases the real hardware-info object from step 2 (vtable
 *      `+0x18` - the same real `OSObject::release()` pattern issue #20
 *      resolved).
 *   5. Re-issues the same `+0xf0` call from step 1 on `gartMapping`, this
 *      time with args `(buffer->memoryDescriptor, 0x400, 0)` - restoring
 *      whatever step 1 temporarily redirected.
 *
 * Confidence: CONFIRMED for control flow and every real offset - a real,
 * complete, standalone decompile. The exact real semantics of the
 * `+0xf0` Apple vtable calls and the `this+0xe4` field are UNKNOWN
 * beyond what's described above. No C++ compiler was available in the
 * sandboxed environment this was written in (same standing limitation as
 * every other file in this project) - checked by careful, repeated
 * manual re-reading against the raw decompile instead.
 */

#include "../Headers/IOATIR500Accelerator.h"
#include "../Headers/ATIRadeonX1000Types.h"

extern "C" int _ASICSupportsAGP;

void IOATIR500Accelerator::pageOffDataBuffer(VendorTextureBuffer *buffer) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

    if (!allocDataBufferBacking(buffer)) {
        deallocate_texture(buffer);

        /* real: unconditional, no null checks in the raw decompile - this
         * is a real circular doubly-linked list (an unlinked node points
         * to itself, never to null), consistent with every other such
         * list in this project. */
        VendorTextureBuffer *prev = reinterpret_cast<VendorTextureBuffer *>(buffer->surfaceOrFormatInfo);
        VendorTextureBuffer *next = reinterpret_cast<VendorTextureBuffer *>(buffer->listNext);
        prev->listNext = next;
        buffer->listNext = buffer;
        next->surfaceOrFormatInfo = prev;
        buffer->surfaceOrFormatInfo = buffer;
        return;
    }

    typedef void (*Fn0xf0)(void *, UInt32, UInt32, UInt32);
    void *gartMapping = buffer->gartMapping;
    if (gartMapping != nullptr) {
        (*reinterpret_cast<Fn0xf0 *>(*reinterpret_cast<void ***>(gartMapping) + (0xf0 / 4)))(gartMapping, 0, 0x400, 0);
    }

    typedef void *(*PrepareMappingFn)(void *, int, int, UInt32, int, int);
    void *memoryDescriptor = buffer->memoryDescriptor;
    void *memHandle = (*reinterpret_cast<PrepareMappingFn *>(
        *reinterpret_cast<void ***>(memoryDescriptor) + (0x14c / 4)))(
        memoryDescriptor, _ASICSupportsAGP, 0, 0x401, 0, 0);
    if (memHandle != nullptr) {
        typedef UInt32 *(*GetHwInfoFn)(void *);
        UInt32 *hwInfo = (*reinterpret_cast<GetHwInfoFn *>(*reinterpret_cast<void ***>(memHandle) + (0xd0 / 4)))(memHandle);
        UInt8 *hwInfoBytes = reinterpret_cast<UInt8 *>(hwInfo);

        if ((buffer->poolSizeClass >> 2) != 0) {
            UInt8 *src = *reinterpret_cast<UInt8 **>(self + 0xe4) + buffer->transferBufferFlag;
            UInt32 count = buffer->poolSizeClass >> 2;
            for (UInt32 i = 0; i < count; i++) {
                *reinterpret_cast<UInt32 *>(hwInfoBytes + i * 4) = *reinterpret_cast<UInt32 *>(src + i * 4);
            }
        }

        typedef void (*ReleaseFn)(void *);
        (*reinterpret_cast<ReleaseFn *>(*reinterpret_cast<void ***>(memHandle) + (0x18 / 4)))(memHandle);
    }

    if (gartMapping != nullptr) {
        (*reinterpret_cast<Fn0xf0 *>(*reinterpret_cast<void ***>(gartMapping) + (0xf0 / 4)))(gartMapping, reinterpret_cast<UInt32>(memoryDescriptor), 0x400, 0);
    }
}
