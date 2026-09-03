/*
 * ATIRadeonX1000_TextureVRAM.cpp
 *
 * RESOLVED (issue #23): `ATIRadeonX1000::allocate_texture`/
 * `deallocate_texture`'s real bodies (real vtable slots `+0x528`/`+0x524`,
 * names/addresses RESOLVED issue #19). Both dispatch on a texture's own
 * real type-discriminant byte (`texture+0x20`, the same real discriminant
 * this project has already partially catalogued - see
 * `Sources/IOATIR500GLContext_TextureStream.cpp`'s own header comment).
 *
 * `allocate_texture` - real "try preferred VRAM placement strategy, fall
 * back to another" pattern for real discriminant values 3/7 (and, for
 * every OTHER value except 8, falls into the SAME real allocation path
 * with a zero requested size - transcribed exactly as found, an
 * apparent real "always attempt a (possibly zero-size) allocation
 * unless this is a type-8 texture" design). Real strategy selection:
 * checks a real "is AGP available" signal by calling through the SAME
 * still-unidentified real object this project's issue #20/#24 already
 * flagged (`texture+8`, real `+0x14c`/`+0xd0`/`+0x18` call chain,
 * `_ASICSupportsAGP` - the same real global TextureLoad.cpp/
 * DiscardBuffer.cpp already reference) - if AGP is unavailable or the
 * accelerator's own VRAM budget (`this+0x84c`) already equals its cap
 * (`this+0x9c`), allocates from a real "overflow" region instead
 * (`this+0xd0`-gated choice of two different real `ATIR500Memory::alloc`
 * range arguments). Delegates the real allocation itself to the SAME
 * `ATIR500Memory` class this project found in issue #23's own earlier
 * pass (`Headers/ATIR500Memory.h`), via the accelerator's own "main" GART
 * pool (`this+0x7c`).
 *
 * `deallocate_texture` - real per-discriminant cleanup (type 3/7: a real
 * mip-array dirty-bit scan this project hasn't fully named every field
 * of, then a real vtable call at `+0x52c` on `this` with a
 * "release/evict everything" shaped `(param_1, -1, -1)` argument
 * pattern, own target not investigated; type 8: either a direct real
 * release call on a per-texture handle object at `texture+0x10`
 * (`+0x18` slot - the same real ABI-fixed-looking release pattern this
 * project has seen on several DIFFERENT real classes, not claimed to be
 * the same object as issue #20/#24's own mystery object), or delegates
 * to the already-known `IOATIR500Accelerator::pageOffDataBuffer`),
 * followed by a real shared tail every discriminant value reaches: two
 * `HZMEM_Free` calls (already-known function) gated on real per-texture
 * HyperZ-block-assignment fields, then unconditionally releases the
 * real backing VRAM via `ATIR500Memory::dealloc` on the same "main" GART
 * pool.
 *
 * Confidence: CONFIRMED for control flow and every field offset/literal
 * constant touched - two real, complete decompiles, not summarized.
 * Several field roles (the mip-array scan's own exact semantics,
 * `texture+0x50`/`+0x6c`/`+0x70`/`+0x72`/`+0x74`/`+0x78`/`+0x7a`) are
 * transcribed as raw offsets rather than promoted to named struct
 * fields, since neither this pass nor any earlier one has independently
 * corroborated their real roles beyond what's visible in these two
 * functions alone - consistent with this project's established practice
 * elsewhere. No C++ compiler was available in the sandboxed environment
 * this was written in (same standing limitation as every other file in
 * this project) - checked by careful, repeated manual re-reading against
 * each raw decompile instead.
 */

#include "../Headers/ATIRadeonX1000.h"
#include "../Headers/ATIR500Memory.h"
#include "../Headers/ATIRadeonX1000Registers.h"

extern "C" int _ASICSupportsAGP; /* real global, already referenced elsewhere in this project (ATIR500GLContext_TextureLoad.cpp) */

namespace {
inline UInt32 &U32At(void *base, int offset) { return *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt16 &U16At(void *base, int offset) { return *reinterpret_cast<UInt16 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt8  &U8At(void *base, int offset)  { return *(reinterpret_cast<UInt8 *>(base) + offset); }
} // namespace

IOReturn ATIRadeonX1000::allocate_texture(VendorTextureBuffer *texture) {
    UInt8 *tex = reinterpret_cast<UInt8 *>(texture);
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt32 discriminant = U32At(tex, 0x20);
    UInt32 requestedSize;

    if (discriminant != 3 && discriminant != 7) {
        if (discriminant == 8) {
            return 0; /* real: type 8 never allocates VRAM here */
        }
        requestedSize = 0;
    } else {
        requestedSize = U32At(tex, 0x50);
    }

    ATIR500Memory *pool = *reinterpret_cast<ATIR500Memory **>(self + 0x7c);
    UInt32 used = U32At(self, 0x84c);
    /* real: set only when arriving at the fallback allocation below via the "overflow alloc
     * itself failed" path (real goto LAB_0001a980) - that path always uses the (0, used)
     * variant regardless of this+0xd0, skipping the check every OTHER path into the fallback
     * performs. Transcribed with this flag rather than restructuring, to avoid silently
     * merging two real, distinct control-flow paths into one. */
    bool skipD0Check = false;

    if (used != U32At(self, 0x9c)) {
        /* real: AGP-overflow-first path, gated on a real check through the still-unidentified
         * object at texture+8 (issue #20/#24's own tracked mystery) */
        typedef void *(*PrepareMappingFn)(void *, int, int, UInt32, int, int);
        void *memoryDescriptor = *reinterpret_cast<void **>(tex + 8);
        void *piVar2 = (*reinterpret_cast<PrepareMappingFn *>(*reinterpret_cast<void ***>(memoryDescriptor) + (0x14c / 4)))(
            memoryDescriptor, _ASICSupportsAGP, 0, 1, 0, 0);
        if (piVar2 != nullptr) {
            typedef UInt32 *(*GetHwInfoFn)(void *);
            UInt32 *hwInfo = (*reinterpret_cast<GetHwInfoFn *>(*reinterpret_cast<void ***>(piVar2) + (0xd0 / 4)))(piVar2);
            UInt32 flags = U32At(hwInfo, 0x20);
            typedef void (*ReleaseFn)(void *);
            (*reinterpret_cast<ReleaseFn *>(*reinterpret_cast<void ***>(piVar2) + (0x18 / 4)))(piVar2);
            used = U32At(self, 0x84c);
            if (((flags ^ 0x40000000u) >> 0x1e & 1) == 0) {
                UInt32 overflowResult = pool->alloc(reinterpret_cast<GLKMemoryElement *>(tex + 0x40), requestedSize, 0x1000,
                                                     used, U32At(self, 0x9c) - used);
                if (overflowResult != 0) {
                    return 1; /* real: falls straight through to success, skipping the fallback entirely */
                }
                used = U32At(self, 0x84c);
                skipD0Check = true;
            }
        } else {
            used = U32At(self, 0x84c);
        }
    }

    UInt32 fallbackResult;
    if (skipD0Check || U32At(self, 0xd0) != 0) {
        fallbackResult = pool->alloc(reinterpret_cast<GLKMemoryElement *>(tex + 0x40), requestedSize, 0x1000, 0, used);
    } else {
        fallbackResult = pool->alloc(reinterpret_cast<GLKMemoryElement *>(tex + 0x40), requestedSize, 0x1000, 0x10000, used - 0x10000);
    }
    if (fallbackResult == 0) return 0;
    return 1;
}

void ATIRadeonX1000::deallocate_texture(VendorTextureBuffer *texture) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *tex = reinterpret_cast<UInt8 *>(texture);
    UInt32 discriminant = U32At(tex, 0x20);

    if (discriminant == 3 || discriminant == 7) {
        UInt8 *rec = reinterpret_cast<UInt8 *>(U32At(tex, 0x14));
        UInt32 mipCount = U8At(rec, 0x34);
        if (mipCount != 0) {
            /* real: scans up to mipCount real mip-adjacent records looking for a "dirty" one
             * (a & ~b != 0). If it finds one - or the gate below never triggers the scan at
             * all - real vtable+0x52c eviction call runs. If the scan completes all mipCount
             * entries and NONE are dirty, the real code SKIPS the eviction call entirely and
             * jumps straight to the shared HZMEM_Free tail (real goto LAB_0001a700) - a real,
             * meaningful branch, not dead code. */
            bool allClean = false;
            if ((U16At(rec, 0x28) & ~U16At(rec, 0x1c)) == 0) {
                UInt32 scanned = 0;
                UInt32 remaining = mipCount;
                UInt8 *cursor = rec;
                do {
                    scanned++;
                    remaining--;
                    if (remaining == 0) {
                        allClean = (mipCount == scanned);
                        break;
                    }
                    UInt16 a = U16At(cursor, 0x2a);
                    UInt16 b = U16At(cursor, 0x1e);
                    cursor += 2;
                    if ((a & static_cast<UInt16>(~b)) != 0) break;
                } while (true);
            }
            if (!allClean) {
                typedef void (*EvictFn)(void *, void *, UInt32, UInt32);
                UInt32 *vtable = *reinterpret_cast<UInt32 **>(self);
                (*reinterpret_cast<EvictFn *>(vtable + (0x52c / 4)))(self, texture, 0xffffffffu, 0xffffffffu);
            } else {
                goto sharedTail; /* real goto LAB_0001a700 */
            }
        }
    } else if (discriminant == 8) {
        if (U32At(tex, 0x54) == 0) {
            void *handle = *reinterpret_cast<void **>(tex + 0x10);
            if (handle != nullptr) {
                typedef void (*ReleaseFn)(void *);
                (*reinterpret_cast<ReleaseFn *>(*reinterpret_cast<void ***>(handle) + (0x18 / 4)))(handle);
                *reinterpret_cast<UInt32 *>(tex + 0x10) = 0;
            }
        } else {
            pageOffDataBuffer(texture);
        }
    }

sharedTail:
    UInt32 hzBlock = U32At(tex, 0x6c);
    if (hzBlock != 0xffffffffu) {
        if ((hzBlock & 0x3ff) != 0x3ff) {
            HZMEM_Free(reinterpret_cast<_HZDATA *>(self + 0x870), hzBlock, 0);
            hzBlock = U32At(tex, 0x6c);
        }
        if ((hzBlock & 0xffc00) != 0xffc00) {
            HZMEM_Free(reinterpret_cast<_HZDATA *>(self + 0x870), hzBlock, 1);
        }
        U16At(tex, 0x72) = 0;
        U16At(tex, 0x7a) = 0;
        U32At(tex, 0x6c) = 0xffffffffu;
        U16At(tex, 0x70) = 0;
        U32At(tex, 0x74) = 0;
        U16At(tex, 0x78) = 0;
    }

    ATIR500Memory *pool = *reinterpret_cast<ATIR500Memory **>(self + 0x7c);
    pool->dealloc(reinterpret_cast<GLKMemoryElement *>(tex + 0x40));
}
