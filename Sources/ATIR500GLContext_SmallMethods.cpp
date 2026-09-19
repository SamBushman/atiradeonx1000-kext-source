/*
 * ATIR500GLContext_SmallMethods.cpp
 *
 * RESOLVED (ledger pass): the ATIR500GLContext (GL subclass) members that had no body in the rebuild:
 *   set_texture_flags (0x26fd0, vtable +0x5c0)   clientMemoryForType (0x27000, +0x580)
 *   setCompatibleSurfaceMode (0x270a0, +0x5ac)   update_surface (0x27fd0, +0x5a8)
 * Field offsets: this+0xc8 accelerator, +0x290 bound surface, +0x35c and +0x3aa / +0xac: surface-mode fields.
 */

#include "../Headers/ATIR500GLContext.h"
#include "../Headers/ATIRadeonX1000.h"
#include "../Headers/IOATIR500Surface.h"

namespace {
inline UInt32 &U32At(void *base, int offset) { return *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt16 &U16At(void *base, int offset) { return *reinterpret_cast<UInt16 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt8  &U8At(void *base, int offset)  { return *(reinterpret_cast<UInt8 *>(base) + offset); }
typedef void (*RetainFn)(void *);
} // namespace

/* Real: for a plain texture (kind byte +0x20 == 0) that belongs to a surface (+0x50), copy bits 0-2 of the
 * surface's first buffer record byte +0x38, shifted left 2, into the texture record's flag byte +0x15. */
void ATIR500GLContext::set_texture_flags(VendorTextureBuffer *texture) {
    UInt8 *tex = reinterpret_cast<UInt8 *>(texture);
    if (U8At(tex, 0x20) != 0) {
        return;
    }
    UInt8 *surface = reinterpret_cast<UInt8 *>(U32At(tex, 0x50));
    if (surface == nullptr) {
        return;
    }
    UInt8 *bufRec = reinterpret_cast<UInt8 *>(U32At(surface, 0xb70));
    U8At(reinterpret_cast<void *>(U32At(tex, 0x14)), 0x15) = static_cast<UInt8>((U8At(bufRec, 0x38) & 7) << 2);
}

/* Real: type 0 hands out (and retains) the accelerator's shared 0x1000-byte client-memory descriptor; every other
 * type defers to the base class. */
IOReturn ATIR500GLContext::clientMemoryForType(UInt32 type, UInt32 *options, IOMemoryDescriptor **memory) {
    if (type != 0) {
        return IOATIR500GLContext::clientMemoryForType(type, options, memory);
    }
    UInt8 *accel = *reinterpret_cast<UInt8 **>(reinterpret_cast<UInt8 *>(this) + 0xc8);
    void *desc = *reinterpret_cast<void **>(accel + 0x8d8);
    if (desc == nullptr) {
        return 0xe00002be;
    }
    void **vtable = *reinterpret_cast<void ***>(desc);
    (*reinterpret_cast<RetainFn *>(vtable + (0x14 / 4)))(desc);
    *options = 0x1000;
    *memory = reinterpret_cast<IOMemoryDescriptor *>(desc);
    return 0;
}

/* Real: the base class's own check first; if the modes are not already compatible, try to merge the per-context
 * bits (0x30000 = stereo/quad bits, 0x700000 / 0xc0000 = multisample fields) into *modeBits, failing (false) if
 * two different non-zero values collide. */
bool ATIR500GLContext::setCompatibleSurfaceMode(SInt32 *modeBits, eIOGLContextModeBits modeEnum, SInt32 flagsIn) {
    UInt32 mode = static_cast<UInt32>(modeEnum);
    UInt32 flags = static_cast<UInt32>(flagsIn);
    if (IOATIR500GLContext::setCompatibleSurfaceMode(modeBits, modeEnum, flagsIn)) {
        return true;
    }
    UInt32 cur = static_cast<UInt32>(*modeBits);
    UInt32 merged = cur & 0xffff7fc0u;
    if ((flags & 0x40) == 0) {
        merged = (mode & 0x30000u) | (cur & 0xfffc7fc0u);
    } else {
        UInt32 want = mode & 0x30000u;
        if ((cur & 0x30000u) != want) {
            if ((cur & 0x30000u) != 0 && want != 0) {
                return false;
            }
            merged |= want;
        }
    }
    if ((flags & 0x200) == 0) {
        merged = (mode & 0x7c0000u) | (merged & 0xff83ffffu);
    } else {
        UInt32 want = mode & 0x700000u;
        if ((merged & 0x700000u) != want) {
            if ((merged & 0x700000u) != 0 && want != 0) {
                return false;
            }
            merged |= want;
        }
        want = mode & 0xc0000u;
        if ((merged & 0xc0000u) != want) {
            if ((merged & 0xc0000u) != 0 && want != 0) {
                return false;
            }
            merged |= want;
        }
    }
    if ((merged & 0xfffcffffu) == (mode & 0xfffcc03fu)) {
        *modeBits = static_cast<SInt32>(merged | (cur & 0x803fu) | (mode & 0x30000u));
        return true;
    }
    return true;
}

/* Real: recompute the two effective-mode halfwords (this+0x3aa / this+0xac) from this context's mode word
 * (+0x35c) and the bound surface's mode bits, rebuild the scissor, then invalidate and clear the accelerator's
 * "last hardware context" marker. */
void ATIR500GLContext::update_surface() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *surface = reinterpret_cast<UInt8 *>(U32At(self, 0x290));
    if (surface != nullptr) {
        SInt32 mode = static_cast<SInt32>(U32At(self, 0x35c));
        UInt32 surfBits = U32At(surface, 0xbe8);
        bool compatible = (mode == 1) || (mode == 0 && (surfBits & 0x400) == 0);
        if ((surfBits & 0x7c0000) == 0 || !compatible) {
            U16At(self, 0x3aa) = static_cast<UInt16>(mode);
            U16At(self, 0xac) = static_cast<UInt16>(mode);
        } else {
            U16At(self, 0x3aa) = 9;
            U16At(self, 0xac) = 9;
        }
        build_scissor();
    }
    invalidate();
    U32At(*reinterpret_cast<void **>(self + 0xc8), 0x78) = 0;
}
