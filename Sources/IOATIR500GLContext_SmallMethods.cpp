/*
 * IOATIR500GLContext_SmallMethods.cpp
 *
 * RESOLVED (ledger pass): the IOATIR500GLContext (GL base class) members that had no body in the rebuild, all
 * transcribed from the shipped kext's decompile:
 *   clientClose (0x7130, vtable +0x568)                 remove_surface (0x79c0)
 *   setCompatibleSurfaceMode (0x7b70, vtable +0x5ac)    set_texture_flags (0x7e60, +0x5c0): empty
 *   add_vendor_surface_required_bits (0x83b0, +0x5bc): empty
 * Field offsets: this+0xc8 accelerator, this+0x290 bound surface, this+0x294 "started" flag.
 */

#include "../Headers/IOATIR500GLContext.h"
#include "../Headers/ATIRadeonX1000.h"

namespace {
inline UInt32 &U32At(void *base, int offset) { return *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(base) + offset); }
} // namespace

/* Real: if the started flag is set, stop() then detach() from the accelerator (vtable +0x34c / +0x3a8). */
IOReturn IOATIR500GLContext::clientClose() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    if (U32At(self, 0x294) != 0) {
        IOService *provider = *reinterpret_cast<IOService **>(self + 0xc8);
        this->stop(provider);
        this->detach(provider);
    }
    return 0;
}

void IOATIR500GLContext::remove_surface() {
    U32At(this, 0x290) = 0;
}

/* Real: true iff the surface's current mode bits, ignoring the per-context bits, equal the requested mode. */
bool IOATIR500GLContext::setCompatibleSurfaceMode(SInt32 *modeBits, eIOGLContextModeBits mode, SInt32 flags) {
    (void)flags;
    return (static_cast<UInt32>(*modeBits) & 0xffff7fc0u) == (static_cast<UInt32>(mode) & 0xffffc03fu);
}

void IOATIR500GLContext::set_texture_flags(VendorTextureBuffer *texture) {
    (void)texture;
}

void IOATIR500GLContext::add_vendor_surface_required_bits(eIOGLContextModeBits mode) {
    (void)mode;
}
